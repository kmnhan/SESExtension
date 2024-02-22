#pragma once
#include <zmq.hpp>
#include <string>
#include <iostream>

namespace attrs_client
{
    std::string info()
    {
        zmq::context_t context(1);

        zmq::socket_t socket(context, zmq::socket_type::sub);

        socket.connect("tcp://localhost:5556");

        socket.set(zmq::sockopt::subscribe, "");

        zmq::message_t result;
        socket.recv(result, zmq::recv_flags::none);

        return result.to_string();
    }
}