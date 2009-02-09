/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/commands/ConsumerInfo.h>
#include <activemq/state/CommandVisitor.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for ConsumerInfo
 *
 *
 *  NOTE!: This file is auto generated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ConsumerInfo::ConsumerInfo() {

    this->browser = false;
    this->prefetchSize = 0;
    this->maximumPendingMessageLimit = 0;
    this->dispatchAsync = false;
    this->selector = "";
    this->subscriptionName = "";
    this->noLocal = false;
    this->exclusive = false;
    this->retroactive = false;
    this->priority = 0;
    this->networkSubscription = false;
    this->optimizedAcknowledge = false;
    this->noRangeAcks = false;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerInfo::~ConsumerInfo() {

}

////////////////////////////////////////////////////////////////////////////////
ConsumerInfo* ConsumerInfo::cloneDataStructure() const {
    std::auto_ptr<ConsumerInfo> consumerInfo( new ConsumerInfo() );

    // Copy the data from the base class or classes
    consumerInfo->copyDataStructure( this );

    return consumerInfo.release();
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::copyDataStructure( const DataStructure* src ) {

    // Protect against invalid self assignment.
    if( this == src ) {
        return;
    }

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const ConsumerInfo* srcPtr = dynamic_cast<const ConsumerInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "ConsumerInfo::copyDataStructure - src is NULL or invalid" );
    }
    this->setConsumerId( srcPtr->getConsumerId() );
    this->setBrowser( srcPtr->isBrowser() );
    this->setDestination( srcPtr->getDestination() );
    this->setPrefetchSize( srcPtr->getPrefetchSize() );
    this->setMaximumPendingMessageLimit( srcPtr->getMaximumPendingMessageLimit() );
    this->setDispatchAsync( srcPtr->isDispatchAsync() );
    this->setSelector( srcPtr->getSelector() );
    this->setSubscriptionName( srcPtr->getSubscriptionName() );
    this->setNoLocal( srcPtr->isNoLocal() );
    this->setExclusive( srcPtr->isExclusive() );
    this->setRetroactive( srcPtr->isRetroactive() );
    this->setPriority( srcPtr->getPriority() );
    this->setBrokerPath( srcPtr->getBrokerPath() );
    this->setAdditionalPredicate( srcPtr->getAdditionalPredicate() );
    this->setNetworkSubscription( srcPtr->isNetworkSubscription() );
    this->setOptimizedAcknowledge( srcPtr->isOptimizedAcknowledge() );
    this->setNoRangeAcks( srcPtr->isNoRangeAcks() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ConsumerInfo::getDataStructureType() const {
    return ConsumerInfo::ID_CONSUMERINFO;
}

////////////////////////////////////////////////////////////////////////////////
std::string ConsumerInfo::toString() const {

    ostringstream stream;

    stream << "Begin Class = ConsumerInfo" << std::endl;
    stream << " Value of ConsumerInfo::ID_CONSUMERINFO = 5" << std::endl;
    stream << " Value of ConsumerId is Below:" << std::endl;
    if( this->getConsumerId() != NULL ) {
        stream << this->getConsumerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Browser = " << this->isBrowser() << std::endl;
    stream << " Value of Destination is Below:" << std::endl;
    if( this->getDestination() != NULL ) {
        stream << this->getDestination()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of PrefetchSize = " << this->getPrefetchSize() << std::endl;
    stream << " Value of MaximumPendingMessageLimit = " << this->getMaximumPendingMessageLimit() << std::endl;
    stream << " Value of DispatchAsync = " << this->isDispatchAsync() << std::endl;
    stream << " Value of Selector = " << this->getSelector() << std::endl;
    stream << " Value of SubscriptionName = " << this->getSubscriptionName() << std::endl;
    stream << " Value of NoLocal = " << this->isNoLocal() << std::endl;
    stream << " Value of Exclusive = " << this->isExclusive() << std::endl;
    stream << " Value of Retroactive = " << this->isRetroactive() << std::endl;
    stream << " Value of Priority = " << (int)this->getPriority() << std::endl;
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        stream << " Value of BrokerPath[" << ibrokerPath << "] is Below:" << std::endl;
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            stream << this->getBrokerPath()[ibrokerPath]->toString() << std::endl;
        } else {
            stream << "   Object is NULL" << std::endl;
        }
    }
    stream << " Value of AdditionalPredicate is Below:" << std::endl;
    if( this->getAdditionalPredicate() != NULL ) {
        stream << this->getAdditionalPredicate()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of NetworkSubscription = " << this->isNetworkSubscription() << std::endl;
    stream << " Value of OptimizedAcknowledge = " << this->isOptimizedAcknowledge() << std::endl;
    stream << " Value of NoRangeAcks = " << this->isNoRangeAcks() << std::endl;
    stream << BaseCommand::toString();
    stream << "End Class = ConsumerInfo" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::equals( const DataStructure* value ) const {

    if( this == value ) {
        return true;
    }

    const ConsumerInfo* valuePtr = dynamic_cast<const ConsumerInfo*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }

    if( this->getConsumerId() != NULL ) {
        if( !this->getConsumerId()->equals( valuePtr->getConsumerId().get() ) ) {
            return false;
        }
    } else if( valuePtr->getConsumerId() != NULL ) {
        return false;
    }
    if( this->isBrowser() != valuePtr->isBrowser() ) {
        return false;
    }
    if( this->getDestination() != NULL ) {
        if( !this->getDestination()->equals( valuePtr->getDestination().get() ) ) {
            return false;
        }
    } else if( valuePtr->getDestination() != NULL ) {
        return false;
    }
    if( this->getPrefetchSize() != valuePtr->getPrefetchSize() ) {
        return false;
    }
    if( this->getMaximumPendingMessageLimit() != valuePtr->getMaximumPendingMessageLimit() ) {
        return false;
    }
    if( this->isDispatchAsync() != valuePtr->isDispatchAsync() ) {
        return false;
    }
    if( this->getSelector() != valuePtr->getSelector() ) {
        return false;
    }
    if( this->getSubscriptionName() != valuePtr->getSubscriptionName() ) {
        return false;
    }
    if( this->isNoLocal() != valuePtr->isNoLocal() ) {
        return false;
    }
    if( this->isExclusive() != valuePtr->isExclusive() ) {
        return false;
    }
    if( this->isRetroactive() != valuePtr->isRetroactive() ) {
        return false;
    }
    if( this->getPriority() != valuePtr->getPriority() ) {
        return false;
    }
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            if( !this->getBrokerPath()[ibrokerPath]->equals( valuePtr->getBrokerPath()[ibrokerPath].get() ) ) {
                return false;
            }
        } else if( valuePtr->getBrokerPath()[ibrokerPath] != NULL ) {
            return false;
        }
    }
    if( this->getAdditionalPredicate() != NULL ) {
        if( !this->getAdditionalPredicate()->equals( valuePtr->getAdditionalPredicate().get() ) ) {
            return false;
        }
    } else if( valuePtr->getAdditionalPredicate() != NULL ) {
        return false;
    }
    if( this->isNetworkSubscription() != valuePtr->isNetworkSubscription() ) {
        return false;
    }
    if( this->isOptimizedAcknowledge() != valuePtr->isOptimizedAcknowledge() ) {
        return false;
    }
    if( this->isNoRangeAcks() != valuePtr->isNoRangeAcks() ) {
        return false;
    }
    if( !BaseCommand::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
decaf::lang::Pointer<commands::Command> ConsumerInfo::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processConsumerInfo( this );
}

////////////////////////////////////////////////////////////////////////////////
const decaf::lang::Pointer<ConsumerId>& ConsumerInfo::getConsumerId() const {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
decaf::lang::Pointer<ConsumerId>& ConsumerInfo::getConsumerId() {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setConsumerId( const decaf::lang::Pointer<ConsumerId>& consumerId ) {
    this->consumerId = consumerId;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isBrowser() const {
    return browser;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setBrowser( bool browser ) {
    this->browser = browser;
}

////////////////////////////////////////////////////////////////////////////////
const decaf::lang::Pointer<ActiveMQDestination>& ConsumerInfo::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
decaf::lang::Pointer<ActiveMQDestination>& ConsumerInfo::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setDestination( const decaf::lang::Pointer<ActiveMQDestination>& destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
int ConsumerInfo::getPrefetchSize() const {
    return prefetchSize;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setPrefetchSize( int prefetchSize ) {
    this->prefetchSize = prefetchSize;
}

////////////////////////////////////////////////////////////////////////////////
int ConsumerInfo::getMaximumPendingMessageLimit() const {
    return maximumPendingMessageLimit;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setMaximumPendingMessageLimit( int maximumPendingMessageLimit ) {
    this->maximumPendingMessageLimit = maximumPendingMessageLimit;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isDispatchAsync() const {
    return dispatchAsync;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setDispatchAsync( bool dispatchAsync ) {
    this->dispatchAsync = dispatchAsync;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ConsumerInfo::getSelector() const {
    return selector;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ConsumerInfo::getSelector() {
    return selector;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setSelector( const std::string& selector ) {
    this->selector = selector;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ConsumerInfo::getSubscriptionName() const {
    return subscriptionName;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ConsumerInfo::getSubscriptionName() {
    return subscriptionName;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setSubscriptionName( const std::string& subscriptionName ) {
    this->subscriptionName = subscriptionName;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isNoLocal() const {
    return noLocal;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setNoLocal( bool noLocal ) {
    this->noLocal = noLocal;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isExclusive() const {
    return exclusive;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setExclusive( bool exclusive ) {
    this->exclusive = exclusive;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isRetroactive() const {
    return retroactive;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setRetroactive( bool retroactive ) {
    this->retroactive = retroactive;
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ConsumerInfo::getPriority() const {
    return priority;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setPriority( unsigned char priority ) {
    this->priority = priority;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector< decaf::lang::Pointer<BrokerId> >& ConsumerInfo::getBrokerPath() const {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
std::vector< decaf::lang::Pointer<BrokerId> >& ConsumerInfo::getBrokerPath() {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setBrokerPath( const std::vector< decaf::lang::Pointer<BrokerId> >& brokerPath ) {
    this->brokerPath = brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
const decaf::lang::Pointer<BooleanExpression>& ConsumerInfo::getAdditionalPredicate() const {
    return additionalPredicate;
}

////////////////////////////////////////////////////////////////////////////////
decaf::lang::Pointer<BooleanExpression>& ConsumerInfo::getAdditionalPredicate() {
    return additionalPredicate;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setAdditionalPredicate( const decaf::lang::Pointer<BooleanExpression>& additionalPredicate ) {
    this->additionalPredicate = additionalPredicate;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isNetworkSubscription() const {
    return networkSubscription;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setNetworkSubscription( bool networkSubscription ) {
    this->networkSubscription = networkSubscription;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isOptimizedAcknowledge() const {
    return optimizedAcknowledge;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setOptimizedAcknowledge( bool optimizedAcknowledge ) {
    this->optimizedAcknowledge = optimizedAcknowledge;
}

////////////////////////////////////////////////////////////////////////////////
bool ConsumerInfo::isNoRangeAcks() const {
    return noRangeAcks;
}

////////////////////////////////////////////////////////////////////////////////
void ConsumerInfo::setNoRangeAcks( bool noRangeAcks ) {
    this->noRangeAcks = noRangeAcks;
}

