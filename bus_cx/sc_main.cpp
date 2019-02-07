#include "master.h"
#include "ram.h"
#include "bus_cx.h"
#include "adapter.h"
#include "adder.h"
#include "masternew.h"

int sc_main(int argc, char *argv[])
{
  Master master1("master1", 0, 17, 0);
  Ram    ram1("ram1", 0, 16);

  Master master2("master2", 20, 31, 1);
  Ram    ram2("ram2", 16,16);

  MasterNew master3("master3",64,79,2);
  Ram   ram3("ram3",64,16);

  Adder add("add");

  Bus_cx bus("bus",10,SC_NS);

  Adapter adapt("adapt");

  master1.initiator_port(bus.bus_export);
  master2.initiator_port(bus.bus_export);
  master3.initiator_port(bus.bus_export);

  bus.bus_port(ram1.target_export);
  bus.bus_port(ram2.target_export);
  bus.bus_port(ram3.target_export);
  bus.bus_port(adapt.Adapter_export);
  
  sc_signal<int> chx,chy,chs;
  add.s(chs);
  add.x(chx);
  add.y(chy);

  adapt.s(chs);
  adapt.x(chx);
  adapt.y(chy);

  sc_start();
  return 0;
}
