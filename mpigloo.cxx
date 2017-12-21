#include <cassert>
#include <iostream>

#include "gloo/mpi/context.h"
#include "gloo/transport/tcp/device.h"
#include "gloo/allreduce_ring.h"

int main(int argc, char** argv) {
  // We'll use the TCP transport in this example
  auto dev = gloo::transport::tcp::CreateDevice("localhost");

  // Create Gloo context and delegate management of MPI_Init/MPI_Finalize
  auto context = gloo::mpi::Context::createManaged();
  context->connectFullMesh(dev);

  // Create and run simple allreduce
  int rank = context->rank;
  int local_val = 1;
  std::cout << "rank before allreduce: " << local_val << std::endl;
  gloo::AllreduceRing<int> allreduce(context, {&local_val}, 1);
  allreduce.run();
  std::cout << "Result: " << local_val << std::endl;

  return 0;
}
