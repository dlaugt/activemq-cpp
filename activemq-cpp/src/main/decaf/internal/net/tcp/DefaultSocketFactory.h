/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DEFAULTSOCKETFACTORY_H_
#define DEFAULTSOCKETFACTORY_H_

#include <decaf/util/Config.h>

#include <decaf/net/SocketFactory.h>

namespace decaf {
namespace internal {
namespace net {
namespace tcp {

    /**
     * SocketFactory implementation that is used to create TCP style Sockets.
     *
     * @since 1.0
     */
    class DECAF_API DefaultSocketFactory : public decaf::net::SocketFactory {
    public:

        DefaultSocketFactory();

        virtual ~DefaultSocketFactory();

        /**
         * {@inheritDoc}
         */
        virtual decaf::net::Socket* createSocket()
            throw( decaf::io::IOException );

        /**
         * {@inheritDoc}
         */
        virtual decaf::net::Socket* createSocket( const std::string& name, int port )
            throw( decaf::io::IOException, decaf::net::UnknownHostException );

    };

}}}}

#endif /* DEFAULTSOCKETFACTORY_H_ */