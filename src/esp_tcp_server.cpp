#include "esp_tcp_server.h"

TcpServer::TcpServer(uint16_t port)
     : TcpServer(IP_ANY_TYPE, port)
{
}

TcpServer::TcpServer(const IPAddress &address, uint16_t port)
     : WiFiServer(address, port)
{
}

TcpServer::TcpServer(uint16_t port, route_map_t &&route_map)
     : TcpServer(IP_ANY_TYPE, port, std::move(route_map))
{
}

TcpServer::TcpServer(const IPAddress &address, uint16 port, route_map_t &&route_map)
     : WiFiServer(address, port), _route_map(std::move(route_map))
{
}

