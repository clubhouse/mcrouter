/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 */

namespace carbon {
namespace test {

inline void TestRequest::serialize(carbon::CarbonProtocolWriter& writer) const {
  writer.writeStructBegin();
  writer.writeField(-1 /* field id */, asBase());
  writer.writeField(1 /* field id */, key());
  writer.writeField(2 /* field id */, testEnum());
  writer.writeField(3 /* field id */, testBool());
  writer.writeField(4 /* field id */, testChar());
  writer.writeField(5 /* field id */, testInt8());
  writer.writeField(6 /* field id */, testInt16());
  writer.writeField(7 /* field id */, testInt32());
  writer.writeField(8 /* field id */, testInt64());
  writer.writeField(9 /* field id */, testUInt8());
  writer.writeField(10 /* field id */, testUInt16());
  writer.writeField(11 /* field id */, testUInt32());
  writer.writeField(12 /* field id */, testUInt64());
  writer.writeField(13 /* field id */, testFloat());
  writer.writeField(14 /* field id */, testDouble());
  writer.writeField(15 /* field id */, testShortString());
  writer.writeField(16 /* field id */, testLongString());
  writer.writeField(17 /* field id */, testIobuf());
  writer.writeField(18 /* field id */, testStruct());
  writer.writeField(19 /* field id */, testList());
  writer.writeField(20 /* field id */, testOptionalString());
  writer.writeField(21 /* field id */, testOptionalIobuf());
  writer.writeField(22 /* field id */, testEnumVec());
  writer.writeStructEnd();
  writer.writeStop();
}

inline void TestRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        _carbon_simplestruct_.deserialize(reader);
        break;
      }
      case 1: {
        reader.readRawInto(key());
        break;
      }
      case 2: {
        reader.readRawInto(testEnum());
        break;
      }
      case 3: {
        reader.readRawInto(testBool(), fieldType);
        break;
      }
      case 4: {
        reader.readRawInto(testChar());
        break;
      }
      case 5: {
        reader.readRawInto(testInt8());
        break;
      }
      case 6: {
        reader.readRawInto(testInt16());
        break;
      }
      case 7: {
        reader.readRawInto(testInt32());
        break;
      }
      case 8: {
        reader.readRawInto(testInt64());
        break;
      }
      case 9: {
        reader.readRawInto(testUInt8());
        break;
      }
      case 10: {
        reader.readRawInto(testUInt16());
        break;
      }
      case 11: {
        reader.readRawInto(testUInt32());
        break;
      }
      case 12: {
        reader.readRawInto(testUInt64());
        break;
      }
      case 13: {
        reader.readRawInto(testFloat());
        break;
      }
      case 14: {
        reader.readRawInto(testDouble());
        break;
      }
      case 15: {
        reader.readRawInto(testShortString());
        break;
      }
      case 16: {
        reader.readRawInto(testLongString());
        break;
      }
      case 17: {
        reader.readRawInto(testIobuf());
        break;
      }
      case 18: {
        testStruct().deserialize(reader);
        break;
      }
      case 19: {
        reader.readRawInto(testList());
        break;
      }
      case 20: {
        reader.readRawInto(testOptionalString());
        break;
      }
      case 21: {
        reader.readRawInto(testOptionalIobuf());
        break;
      }
      case 22: {
        reader.readRawInto(testEnumVec());
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

template <class V>
void TestRequest::visitFields(V&& v) {
  if (v.enterMixin(1, "Base", _carbon_simplestruct_)) {
    _carbon_simplestruct_.visitFields(std::forward<V>(v));
  }
  if (!v.leaveMixin()) {
    return;
  }
  if (!v.visitField(1, "key", key_)) {
    return;
  }
  if (!v.visitField(2, "testEnum", testEnum_)) {
    return;
  }
  if (!v.visitField(3, "testBool", testBool_)) {
    return;
  }
  if (!v.visitField(4, "testChar", testChar_)) {
    return;
  }
  if (!v.visitField(5, "testInt8", testInt8_)) {
    return;
  }
  if (!v.visitField(6, "testInt16", testInt16_)) {
    return;
  }
  if (!v.visitField(7, "testInt32", testInt32_)) {
    return;
  }
  if (!v.visitField(8, "testInt64", testInt64_)) {
    return;
  }
  if (!v.visitField(9, "testUInt8", testUInt8_)) {
    return;
  }
  if (!v.visitField(10, "testUInt16", testUInt16_)) {
    return;
  }
  if (!v.visitField(11, "testUInt32", testUInt32_)) {
    return;
  }
  if (!v.visitField(12, "testUInt64", testUInt64_)) {
    return;
  }
  if (!v.visitField(13, "testFloat", testFloat_)) {
    return;
  }
  if (!v.visitField(14, "testDouble", testDouble_)) {
    return;
  }
  if (!v.visitField(15, "testShortString", testShortString_)) {
    return;
  }
  if (!v.visitField(16, "testLongString", testLongString_)) {
    return;
  }
  if (!v.visitField(17, "testIobuf", testIobuf_)) {
    return;
  }
  if (!v.visitField(18, "testStruct", testStruct_)) {
    return;
  }
  if (!v.visitField(19, "testList", testList_)) {
    return;
  }
  if (!v.visitField(20, "testOptionalString", testOptionalString_)) {
    return;
  }
  if (!v.visitField(21, "testOptionalIobuf", testOptionalIobuf_)) {
    return;
  }
  if (!v.visitField(22, "testEnumVec", testEnumVec_)) {
    return;
  }
}

template <class V>
void TestRequest::visitFields(V&& v) const {
  if (v.enterMixin(1, "Base", _carbon_simplestruct_)) {
    _carbon_simplestruct_.visitFields(std::forward<V>(v));
  }
  if (!v.leaveMixin()) {
    return;
  }
  if (!v.visitField(1, "key", key_)) {
    return;
  }
  if (!v.visitField(2, "testEnum", testEnum_)) {
    return;
  }
  if (!v.visitField(3, "testBool", testBool_)) {
    return;
  }
  if (!v.visitField(4, "testChar", testChar_)) {
    return;
  }
  if (!v.visitField(5, "testInt8", testInt8_)) {
    return;
  }
  if (!v.visitField(6, "testInt16", testInt16_)) {
    return;
  }
  if (!v.visitField(7, "testInt32", testInt32_)) {
    return;
  }
  if (!v.visitField(8, "testInt64", testInt64_)) {
    return;
  }
  if (!v.visitField(9, "testUInt8", testUInt8_)) {
    return;
  }
  if (!v.visitField(10, "testUInt16", testUInt16_)) {
    return;
  }
  if (!v.visitField(11, "testUInt32", testUInt32_)) {
    return;
  }
  if (!v.visitField(12, "testUInt64", testUInt64_)) {
    return;
  }
  if (!v.visitField(13, "testFloat", testFloat_)) {
    return;
  }
  if (!v.visitField(14, "testDouble", testDouble_)) {
    return;
  }
  if (!v.visitField(15, "testShortString", testShortString_)) {
    return;
  }
  if (!v.visitField(16, "testLongString", testLongString_)) {
    return;
  }
  if (!v.visitField(17, "testIobuf", testIobuf_)) {
    return;
  }
  if (!v.visitField(18, "testStruct", testStruct_)) {
    return;
  }
  if (!v.visitField(19, "testList", testList_)) {
    return;
  }
  if (!v.visitField(20, "testOptionalString", testOptionalString_)) {
    return;
  }
  if (!v.visitField(21, "testOptionalIobuf", testOptionalIobuf_)) {
    return;
  }
  if (!v.visitField(22, "testEnumVec", testEnumVec_)) {
    return;
  }
}

inline void TestReply::serialize(carbon::CarbonProtocolWriter& writer) const {
  writer.writeStructBegin();
  writer.writeField(1 /* field id */, result());
  writer.writeStructEnd();
  writer.writeStop();
}

inline void TestReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readRawInto(result());
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

template <class V>
void TestReply::visitFields(V&& v) {
  if (!v.visitField(1, "result", result_)) {
    return;
  }
}

template <class V>
void TestReply::visitFields(V&& v) const {
  if (!v.visitField(1, "result", result_)) {
    return;
  }
}

inline void TestRequestStringKey::serialize(
    carbon::CarbonProtocolWriter& writer) const {
  writer.writeStructBegin();
  writer.writeField(1 /* field id */, key());
  writer.writeStructEnd();
  writer.writeStop();
}

inline void TestRequestStringKey::deserialize(
    carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readRawInto(key());
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

template <class V>
void TestRequestStringKey::visitFields(V&& v) {
  if (!v.visitField(1, "key", key_)) {
    return;
  }
}

template <class V>
void TestRequestStringKey::visitFields(V&& v) const {
  if (!v.visitField(1, "key", key_)) {
    return;
  }
}

inline void TestReplyStringKey::serialize(
    carbon::CarbonProtocolWriter& writer) const {
  writer.writeStructBegin();
  writer.writeField(1 /* field id */, result());
  writer.writeStructEnd();
  writer.writeStop();
}

inline void TestReplyStringKey::deserialize(
    carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readRawInto(result());
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

template <class V>
void TestReplyStringKey::visitFields(V&& v) {
  if (!v.visitField(1, "result", result_)) {
    return;
  }
}

template <class V>
void TestReplyStringKey::visitFields(V&& v) const {
  if (!v.visitField(1, "result", result_)) {
    return;
  }
}

} // test
} // carbon
