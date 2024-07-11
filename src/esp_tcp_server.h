#ifndef ESP_TCP_SERVER_H_
#define ESP_TCP_SERVER_H_
#include <ESP8266WiFi.h>
#include <unordered_map>
#include "hashable_string.h"

class TcpServer : public WiFiServer{
     using callback_t = void(*);
     using route_map_t = std::unordered_map<hashable_string, callback_t, hashable_string_hash>;

     public:
          TcpServer(uint16_t port);
          TcpServer(const IPAddress &address, uint16_t port);
          
          TcpServer(uint16_t port, route_map_t &&route_map);

          TcpServer(const IPAddress &address, uint16 port, route_map_t &&route_map);

          void add_routes(route_map_t &&routes);

          void remove_routes(std::initializer_list<hashable_string> route_names);

     private:
          route_map_t _route_map;
};

 
#endif


