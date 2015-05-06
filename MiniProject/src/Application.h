#ifndef APPLICATION_H
#define APPLICATION_H

enum {
  AM_APPLICATION = 6
};

 
 typedef nx_struct ApplicationMsg {
  nx_uint16_t nodeid;
  nx_uint16_t size;
  nx_uint16_t test;
  nx_uint16_t test1;
  nx_uint16_t test2;
  nx_uint16_t test3;
  nx_uint16_t test4;
} ApplicationMsg;
#endif /* APPLICATION_H */