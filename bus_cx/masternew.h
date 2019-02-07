#ifndef _MASTERNEW_H_
#define _MASTERNEW_H_

#include "bus_if.h"

SC_MODULE( MasterNew )
{
  sc_port<bus_if,1> initiator_port;
  void action();
  unsigned start, end, id;
  SC_HAS_PROCESS(MasterNew);
  MasterNew( sc_module_name mn, unsigned start_addr, unsigned end_addr, unsigned id = 0 )
  : sc_module( mn )
  {
    cout << "# newMaster #" << endl;
    SC_THREAD(action);
    this->id = id;
    start = start_addr;
    end = end_addr;
  }
};

#endif
