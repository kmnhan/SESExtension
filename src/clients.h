#pragma once
#include <zmq.hpp>
#include <string>
#include <iostream>

namespace slit_client
{
    std::string info()
    {
        //  Prepare our context and socket
        zmq::context_t context(1);
        zmq::socket_t socket(context, zmq::socket_type::req);

        // std::cout << "Connecting to slit server..." << std::endl;
        socket.connect("tcp://localhost:5557");

        zmq::message_t req(1);
        zmq::message_t result;
        memcpy(req.data(), "1", 1);

        // request
        socket.send(req, zmq::send_flags::none);
        socket.recv(result, zmq::recv_flags::none);

        return result.to_string();

        // zmq::message_t req1(1);
        // memcpy(req1.data(), "0", 1);
        // zmq::message_t req2(1);
        // memcpy(req2.data(), "1", 1);
        // zmq::message_t req3(1);
        // memcpy(req3.data(), "2", 1);

        // zmq::message_t slit_number;
        // zmq::message_t slit_width;
        // zmq::message_t slit_aperture;

        // // request 1
        // socket.send(req1, zmq::send_flags::none);
        // socket.recv(slit_number, zmq::recv_flags::none);

        // // request 2
        // socket.send(req2, zmq::send_flags::none);
        // socket.recv(slit_width, zmq::recv_flags::none);

        // // request 3
        // socket.send(req3, zmq::send_flags::none);
        // socket.recv(slit_aperture, zmq::recv_flags::none);

        // std::string slit_attrs = "";
        // slit_attrs += "Analyzer Slit Number=" + slit_number.to_string() + "\n";
        // slit_attrs += "Analyzer Slit Width=" + slit_width.to_string() + "\n";
        // slit_attrs += "Analyzer Slit Aperture=" + slit_aperture.to_string() + "\n";

        // return slit_attrs;
    }
}

namespace cryo_client
{
    std::string info()
    {
        //  Prepare our context and socket
        zmq::context_t context(1);
        zmq::socket_t socket(context, zmq::socket_type::req);

        socket.connect("tcp://localhost:5558");

        zmq::message_t req(1);
        zmq::message_t result;
        memcpy(req.data(), "1", 1);

        // request
        socket.send(req, zmq::send_flags::none);
        socket.recv(result, zmq::recv_flags::none);

        return result.to_string();
    }
}

namespace mg15_client
{
    std::string info()
    {
        //  Prepare our context and socket
        zmq::context_t context(1);
        zmq::socket_t socket(context, zmq::socket_type::req);

        socket.connect("tcp://localhost:5559");

        zmq::message_t req(1);
        zmq::message_t result;
        memcpy(req.data(), "1", 1);

        // request
        socket.send(req, zmq::send_flags::none);
        socket.recv(result, zmq::recv_flags::none);

        return result.to_string();
    }
}