#ifndef APPLICATION_H
#define APPLICATION_H

enum {
  AM_APPLICATION = 6
};

 
 typedef nx_struct ApplicationMsg {
  nx_uint16_t nodeid;
  nx_uint16_t size;
  nx_uint16_t test;
} ApplicationMsg;
#endif /* APPLICATION_H */