#include "masternew.h"

void MasterNew::action()
{
  unsigned data,data2,data3;
  wait(2000,SC_NS);
  unsigned addr2=0;
  unsigned addr3=0;
  for( unsigned addr = 0; addr <= 15; addr++ )
  {    
    addr2=addr+16;
    addr3=addr+64;
    initiator_port->read(addr, data);
    cout << name() << " read(" << addr << ", " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);
    initiator_port->read(addr2, data2);
    cout << name() << " read(" << addr2 << ", " << data2 << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);

    initiator_port->write(1024, data);
    wait(1, SC_NS);
    initiator_port->write(1025, data2);
    wait(1, SC_NS);
    initiator_port->read(1026, data3);
    wait(1, SC_NS);
    initiator_port->write(addr3, data3);
    wait(1, SC_NS);
    cout << name() << " write(" << addr3 << ", " << data3 << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);
  }
  wait();
}
