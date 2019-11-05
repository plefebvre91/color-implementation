#include <iostream>
#include <chrono>

#include "image.hpp"

#define NB_ITERATION 50
#define IMG_SIZE (1024*1024)

int main(int argc, char** argv)
{

  image image(IMG_SIZE);
  unsigned long now[NB_ITERATION], after[NB_ITERATION], mean;

  for(int i=0; i<NB_ITERATION; i++){
    
  now[i] = std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::system_clock::now().time_since_epoch()).count();
 
  image.to_greyscale();
  
  after[i] = std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::system_clock::now().time_since_epoch()).count();
  }

  mean = 0;
  for(int i=0; i<NB_ITERATION; i++){
    mean += after[i] - now[i];
  }

  mean /= NB_ITERATION;

  std::cout << mean << " ms\n";
    
  return 0; 
}


