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
#pragma once

#include <string>
#include <utility>

#include <mcrouter/lib/RouteHandleTraverser.h>

#include "mcrouter/lib/carbon/test/gen/CarbonTestMessages.h"

namespace carbon {
namespace test {

template <class Route>
class CarbonTestRouteHandle;

class CarbonTestRouteHandleIf {
 public:
  template <class Route>
  using Impl = CarbonTestRouteHandle<Route>;

  /**
   * Returns a string identifying this route handle instance
   */
  virtual std::string routeName() const = 0;

  virtual ~CarbonTestRouteHandleIf() = default;

  virtual AnotherReply route(const AnotherRequest&) = 0;
  virtual TestReply route(const TestRequest&) = 0;
  virtual TestReplyStringKey route(const TestRequestStringKey&) = 0;
  virtual test2::util::YetAnotherReply route(
      const test2::util::YetAnotherRequest&) = 0;

  virtual void traverse(
      const AnotherRequest&,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>&) const = 0;
  virtual void traverse(
      const TestRequest&,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>&) const = 0;
  virtual void traverse(
      const TestRequestStringKey&,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>&) const = 0;
  virtual void traverse(
      const test2::util::YetAnotherRequest&,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>&) const = 0;
};

template <class Route>
class CarbonTestRouteHandle : public CarbonTestRouteHandleIf {
 public:
  template <class... Args>
  explicit CarbonTestRouteHandle(Args&&... args)
      : route_(std::forward<Args>(args)...) {}
  std::string routeName() const override final {
    return route_.routeName();
  }

  AnotherReply route(const AnotherRequest& request) override final {
    return route_.route(request);
  }
  TestReply route(const TestRequest& request) override final {
    return route_.route(request);
  }
  TestReplyStringKey route(const TestRequestStringKey& request) override final {
    return route_.route(request);
  }
  test2::util::YetAnotherReply route(
      const test2::util::YetAnotherRequest& request) override final {
    return route_.route(request);
  }

  void traverse(
      const AnotherRequest& request,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>& traverser)
      const override final {
    route_.traverse(request, traverser);
  }
  void traverse(
      const TestRequest& request,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>& traverser)
      const override final {
    route_.traverse(request, traverser);
  }
  void traverse(
      const TestRequestStringKey& request,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>& traverser)
      const override final {
    route_.traverse(request, traverser);
  }
  void traverse(
      const test2::util::YetAnotherRequest& request,
      const RouteHandleTraverser<CarbonTestRouteHandleIf>& traverser)
      const override final {
    route_.traverse(request, traverser);
  }

 private:
  Route route_;
};

} // test
} // carbon
