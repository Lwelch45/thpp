//This code borrows heavily from the iterator classes found in eblearn.
// Find here: http://sourceforge.net/p/eblearn/code/HEAD/tree/trunk/core/libidx/include/idxiter.h
#ifndef THPP_TENSORITERATOR_H_
#define THPP_TENSORITERATOR_H_

#include "Tensor.h"
namespace thpp {
//Class to iterate over the contents of a Tensor.
template <class T>
class TensorIterator {
 public:
  ~TensorIterator();
  TensorIterator(Tensor<T>* src);
  bool notdone();
  T* next();
 private:
  T* data;
  int currentDim; // current dimension being looped on.
  long index; // current posiion in the Tensor
  long* dimensions; // working map of the structure of Tensor
  Tensor<T>* src; //pointer to the tensor currently being iterated through

};
}
#include "TensorIterator-inl.h"
#endif
