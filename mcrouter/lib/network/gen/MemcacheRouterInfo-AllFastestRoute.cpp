/*
 *  Copyright (c) 2017-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#include "MemcacheRouterInfo.h"

#include <mcrouter/routes/AllFastestRouteFactory.h>

namespace facebook {
namespace memcache {
namespace mcrouter {

template facebook::memcache::MemcacheRouterInfo::RouteHandlePtr
makeAllFastestRoute<facebook::memcache::MemcacheRouterInfo>(
    RouteHandleFactory<facebook::memcache::MemcacheRouterInfo::RouteHandleIf>& factory,
    const folly::dynamic& json);

} // namespace mcrouter
} // namespace memcache
} // namespace facebook
