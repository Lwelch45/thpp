#ifndef THPP_TENSORITERATOR_H_
#error This file may only be included from thpp/TensorIterator.h
#endif

#include "folly/Malloc.h"

namespace thpp {

template <class T>
TensorIterator<T>::TensorIterator(Tensor<T>* toIterate) : data(toIterate->data()), index(0),
                                  currentDim(toIterate->ndims()-1){ 
  src = toIterate;
  dimensions = (folly::checkedMalloc( src->ndims() * sizeof(long)));
}

template <class T>
bool TensorIterator<T>::notdone() {return index < src->numel(); }

template <class T>
T* TensorIterator<T>::next(){
  ++index;
  while (currentDim  >=0){
   if (++dimensions[currentDim] >= src->size(currentDim)){
    data -= src->size(currentDim)*src->stride(currentDim);
    dimensions[currentDim--] = -1;
    continue;
   }
   data += src->stride(currentDim);
   if(currentDim != src->ndims())
    currentDim++;
   else 
    return data;
  }
}
 
}
