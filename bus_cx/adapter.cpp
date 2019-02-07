#include "adapter.h"

void Adapter::write( unsigned addr, unsigned  data )
{
 if (addr==1024)
    x.write(data);
  else if (addr==1025)
    y.write(data);
  else if (addr==1026)
    cout<<"Write Forbidden to 1026"<<endl;
  else
    cout<<"Unknown Address"<<endl;
}

void Adapter::read( unsigned addr, unsigned  &data )
{
  if (addr==1024)
    data=x.read();
  else if (addr==1025)
    data=y.read();
  else if (addr==1026)
    data=s.read();
  else
    cout<<"Unknown Address"<<endl;
}
