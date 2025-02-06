#ifndef TENSOR_ARRAY
#define TENSOR_ARRAY
#include <cstdint>
#include "VertexTensor.h"
#include "log.h"

class TensorArray{
private:
    VertexTensor* array;
    uint32_t max_size;
    uint32_t current_size;
public:
    TensorArray(uint32_t len);
    void AddTensor(VertexTensor* tensor);
    VertexTensor GetTensor(uint32_t index);
    void RotateArray(float angle_x, float angle_y, float angle_z);

    /* TensorArray GetProjection(void) */
    /* generates new tensor array with new x and y, (z, norms unchanged) */

};

#endif