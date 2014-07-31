#ifndef THPP_TENSORITERATOR_H_
#error This file may only be included from thpp/TensorIterator.h
#endif

#include "folly/Malloc.h"

namespace thpp {

template <class T>
TensorIterator<T>::TensorIterator(const Tensor<T> toIterate) : data(src.data()), index(0),
                                  currentDim(src->ndims()-1){ 
  src = &toIterate;
  dimensions = static_cast<long>(folly::checkedMalloc( src->ndims() * sizeof(long)));
}

template <class T>
bool TensorIterator<T>::notdone() {return index < src->numel(); }

template <class T>
T* TensorIterator<T>::next(){
  ++index;
  while (currentDim  >=0){
   if (++dimensions[currentDim] >= src->size(currentDim)){
    data -= src->size(currentDim)*src->stride(currentDim);
    diimensions[currentDim--] = -1;
    continue;
   }
   data += src->stride(j);
   if(currentDim != src->ndims())
    currentDim++;
   else 
    return data;
  }
}
 
}
