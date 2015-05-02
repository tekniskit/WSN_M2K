#ifndef APPLICATION_H
#define APPLICATION_H

enum {
  AM_APPLICATION = 6
};

 
 typedef nx_struct ApplicationMsg {
  nx_uint16_t nodeid;
} ApplicationMsg;
#endif /* APPLICATION_H */