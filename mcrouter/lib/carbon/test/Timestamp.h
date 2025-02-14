/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <thrift/lib/cpp2/Thrift.h>
#include <limits>
#include "mcrouter/lib/carbon/CommonSerializationTraits.h"

namespace carbon {
namespace test {

// A transaction timestamp generated by a Clock.
class Timestamp {
 public:
  FBTHRIFT_CPP_DEFINE_MEMBER_INDIRECTION_FN(value());

  Timestamp() = default;
  explicit Timestamp(uint64_t val) noexcept : v_(val) {}

  uint64_t value() const {
    return v_;
  }
  uint64_t& value() {
    return v_;
  }

  bool operator==(Timestamp that) const {
    return v_ == that.v_;
  }
  bool operator<(Timestamp that) const {
    return v_ < that.v_;
  }

  uint64_t toUint64() const;
  static Timestamp fromUint64(uint64_t value);
  int64_t toInt64() const;
  static Timestamp fromInt64(int64_t value);

 private:
  uint64_t v_{0};
};

struct TimestampAdapter {
  static Timestamp fromThrift(const int64_t& v) {
    return Timestamp::fromInt64(v);
  }

  static int64_t toThrift(const Timestamp& v) {
    return v.toInt64();
  }
};

template <typename T1, typename T2>
struct DummyPairAdapter {
  static std::pair<T1, T2> fromThrift(const folly::IOBuf& /*buffer*/) {
    return {};
  }

  static folly::IOBuf toThrift(const std::pair<T1, T2>& /*value*/) {
    return {};
  }
};
} // namespace test
} // namespace carbon

namespace carbon {
template <>
struct SerializationTraits<carbon::test::Timestamp> {
  static constexpr carbon::FieldType kWireType = carbon::FieldType::Int64;

  template <class Reader>
  static carbon::test::Timestamp read(Reader&& reader) {
    return carbon::test::Timestamp::fromUint64(
        reader.template readRaw<uint64_t>());
  }

  template <class Writer>
  static void write(const carbon::test::Timestamp& value, Writer&& writer) {
    writer.writeRaw(value.toUint64());
  }

  static bool isEmpty(const carbon::test::Timestamp& /*value*/) {
    return false;
  }
};

template <typename T1, typename T2>
struct SerializationTraits<std::pair<T1, T2>> {
  static constexpr carbon::FieldType kWireType =
      SerializationTraits<std::pair<T1, T2>>::kWireType;

  template <class Reader>
  static std::pair<T1, T2> read(Reader&& /*reader*/) {
    return {};
  }

  template <class Writer>
  static void write(const std::pair<T1, T2>& /*value*/, Writer&& /*writer*/) {}

  static bool isEmpty(const std::pair<T1, T2>& /*value*/) {
    return false;
  }
};
} // namespace carbon
