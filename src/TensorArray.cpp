#include "TensorArray.h"



/* Default constructor*/
TensorArray::TensorArray() : current_size(0){
    array = std::vector<VertexTensor>();
}

TensorArray::TensorArray(int len) : current_size(0){
    array = std::vector<VertexTensor>(len);
}



void TensorArray::AddTensor(VertexTensor* tensor){
    if (current_size >= array.size()){
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




TensorArray TensorArray::GetProjection(float disp_z, float proj_z){
    TensorArray new_array = TensorArray(current_size);

    for (uint16_t i = 0; i < current_size; i++){
        VertexTensor new_tensor = VertexTensor();

        new_tensor.z = array[i].z + disp_z;
        new_tensor.x = array[i].x * new_tensor.z / proj_z;
        new_tensor.y = array[i].y * new_tensor.z / proj_z;
        new_tensor.norm_x = array[i].norm_x;
        new_tensor.norm_y = array[i].norm_y;
        new_tensor.norm_z = array[i].norm_z;
    }

    return new_array;
}