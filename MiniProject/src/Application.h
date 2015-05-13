#ifndef APPLICATION_H
#define APPLICATION_H

enum {
  AM_APPLICATION = 6
};

 typedef nx_struct ApplicationMsg112 {
  nx_uint64_t nodeid;
  nx_uint64_t rssi;
  nx_uint64_t a2;
  nx_uint64_t a3;
  nx_uint64_t a4;
  nx_uint64_t a5;
  nx_uint64_t a6;
  nx_uint64_t a7;
  nx_uint64_t a8;
  nx_uint64_t a9;
  nx_uint64_t a10;
  nx_uint64_t a11;
  nx_uint64_t a12;
  nx_uint64_t a13;
} ApplicationMsg112;


 typedef nx_struct ApplicationMsg56 {
  nx_uint64_t nodeid;
  nx_uint64_t rssi;
  nx_uint64_t a2;
  nx_uint64_t a3;
  nx_uint64_t a4;
  nx_uint64_t a5;
  nx_uint64_t a6;
} ApplicationMsg56;

 typedef nx_struct ApplicationMsg24 {
  nx_uint64_t nodeid;
  nx_uint64_t rssi;
  nx_uint64_t a2;
} ApplicationMsg24;

 typedef nx_struct ApplicationMsg8 {
  nx_uint64_t nodeid;
} ApplicationMsg8;
#endif /* APPLICATION_H */