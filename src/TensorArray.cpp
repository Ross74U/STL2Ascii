#include "TensorArray.h"



TensorArray::TensorArray(uint32_t len) : max_size(len), current_size(0){
    array = new VertexTensor[len];
}



void TensorArray::AddTensor(VertexTensor* tensor){
    if (current_size >= max_size){
        return;
    }

    array[current_size] = *tensor;
    current_size ++;
}




VertexTensor TensorArray::GetTensor(uint32_t index){
    VertexTensor tensor = array[index];
    return tensor;
}



void TensorArray::RotateArray(float angle_x, float angle_y, float angle_z){
    if (angle_x != 0){
        for (uint32_t i = 0; i<current_size; i++){
            array[i].RotateX(angle_x);
        }
    }
    if (angle_y != 0){
        for (uint32_t i = 0; i<current_size; i++){
            array[i].RotateY(angle_y);
        }
    }
    if (angle_z != 0){
        for (uint32_t i = 0; i<current_size; i++){
            array[i].RotateZ(angle_z);
        }
    }
}