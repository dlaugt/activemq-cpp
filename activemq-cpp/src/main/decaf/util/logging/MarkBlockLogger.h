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
#ifndef _DECAF_UTIL_LOGGING_MARKBLOCKLOGGER_H_
#define _DECAF_UTIL_LOGGING_MARKBLOCKLOGGER_H_

#include <decaf/util/logging/Logger.h>

namespace decaf{
namespace util{
namespace logging{

    /**
     * Defines a class that can be used to mark the entry and exit from
     * scoped blocks.
     * <p>
     * Create an instance of this class at the start of a scoped block,
     * passing it the logger to use and the name of the block.  The block
     * entry and exit will be marked using the scope name, logger to the
     * logger at the MARKBLOCK log level.
     */
    class DECAF_API MarkBlockLogger
    {
    private:

        // Pointer to the Logger to use for Logging
        Logger* logger;

        // Block Name to Log
        std::string blockName;

    public:

        /**
         * Constructor - Marks Block entry
         * @param logger Logger to use
         * @param blockName Block name
         */
        MarkBlockLogger(Logger* logger, const std::string& blockName)
        {
            this->logger = logger;
            this->blockName = blockName;

            logger.mark(blockName + " - Entered");
        }

        virtual ~MarkBlockLogger()
        {
            logger->mark(blockName + " - Exited");
        }

    };

}}}

#endif /*_DECAF_UTIL_LOGGING_MARKBLOCKLOGGER_H_*/
