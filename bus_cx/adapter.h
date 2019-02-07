// file adder.h
#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "systemc.h"
#include "bus_if.h"

class Adapter: public sc_module,public bus_if
{
public:
    sc_export<bus_if> Adapter_export;
    void write( unsigned addr, unsigned  data );
    void read(  unsigned addr, unsigned &data );
    // ports to connect to other side
    sc_out<int> x;
    sc_out<int> y;
    sc_in<int> s;
    SC_HAS_PROCESS(Adapter);
    Adapter( sc_module_name ada)
  : sc_module(ada)
  {
    cout << " # Adapter # "<<endl;
    Adapter_export.bind(*this);
  }
};

#endif
