// Copyright 2020 Robert Carneiro, Derek Meer, Matthew Tabak, Eric Lujan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#ifndef _HANDSHAKE_SERVER
#define _HANDSHAKE_SERVER

#include "../Backend/Database/GList.h"
#include "../Backend/Networking/main.h"
#include "../Backend/Networking/service.h"
#include "../Backend/Networking/socket.h"

class Handshake_Server : public GNet::Service
{
public:
	shmea::GList execute(class GNet::Instance* cInstance, const shmea::GList& data)
	{
		// Log the client into the server
		shmea::GList retList;
		if (data.size() < 1)
			return retList;

		// Check the characters in the name
		std::string clientName = data.getString(0);
		if (GNet::Instance::validName(clientName))
			cInstance->setName(clientName);

		// generate a new key for the sockets
		if (cInstance->getIP() != GNet::Sockets::LOCALHOST)
		{
			int64_t newKey = GNet::Instance::generateKey();

			// tell the client the good news
			shmea::GList wData;
			wData.addString("Handshake_Client");
			wData.addString(cInstance->getName());
			wData.addLong(newKey);
			GNet::Sockets::writeConnection(cInstance, cInstance->sockfd, wData, GNet::ACK_TYPE);

			// Set the new instance key
			cInstance->setKey(newKey);
		}

		return retList;
	}

	std::string getName() const
	{
		return "Handshake_Server";
	}

	GNet::Service* MakeService() const
	{
		return new Handshake_Server();
	}
};

#endif
