//
//  Hello World client in C++
//  Connects REQ socket to tcp://localhost:5555
//  Sends "Hello" to server, expects "World" back
//
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <windows.h>

int main ()
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, zmq::socket_type::req);

    std::cout << "Connecting to slit server..." << std::endl;
    socket.connect ("tcp://localhost:5559");
    Sleep(1000);
    // //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 30; request_nbr++) {
    //     zmq::message_t request (5);
    //     memcpy (request.data (), "Hello", 5);
    //     std::cout << "Sending Hello " << request_nbr << "..." << std::endl;
    //     socket.send (request, zmq::send_flags::none);

    //     //  Get the reply.
    //     zmq::message_t reply;
    //     socket.recv (reply, zmq::recv_flags::none);
    //     std::cout << "Received World " << request_nbr << std::endl;

    // return 0;


        zmq::message_t req(1);
        zmq::message_t result;
        memcpy(req.data(), "1", 1);

        // request
        socket.send(req, zmq::send_flags::none);
        socket.recv(result, zmq::recv_flags::none);

   
        std::cout << result.to_string() << std::endl;
        Sleep(1000);
    }
    Sleep(2000);
    return 0;
}