// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <fastrtps/transport/TransportInterface.h>
#include <fastrtps/transport/UDPTransportInterface.h>
#include <fastrtps/rtps/messages/CDRMessage.h>
#include <utility>
#include <cstring>
#include <algorithm>
#include <fastrtps/log/Log.h>
#include <fastrtps/utils/Semaphore.h>
#include <fastrtps/rtps/network/ReceiverResource.h>
#include <fastrtps/rtps/network/SenderResource.h>
#include <fastrtps/rtps/messages/MessageReceiver.h>

using namespace std;
using namespace asio;

namespace eprosima{
namespace fastrtps{
namespace rtps {

UDPTransportDescriptor::UDPTransportDescriptor()
    : TransportDescriptorInterface(s_maximumMessageSize)
    , m_output_udp_socket(0)
{
}

UDPTransportDescriptor::UDPTransportDescriptor(const UDPTransportDescriptor& t)
    : TransportDescriptorInterface(t)
    , m_output_udp_socket(t.m_output_udp_socket)
{
}

UDPTransportInterface::UDPTransportInterface()
{
}

UDPTransportInterface::~UDPTransportInterface()
{
}

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima
