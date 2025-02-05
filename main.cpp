#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "log.h"
#include "VertexTensor.h"



struct Facet {
    float normal[3];
    float vertex1[3];
    float vertex2[3];
    float vertex3[3];
    uint16_t attributeByteCount;
};




int main() {

    Logging Log;
    Log.SetLogLevel(LOG_LEVEL_INFO);


    const char* filename = "heart.stl"; // Replace with your STL file name
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        Log.Error("Could not read file!\n");
        return 1;
    }

    // Skip the 80-byte header
    file.seekg(80, std::ios::beg);

    // Read the number of facets (4 bytes)
    uint32_t numFacets;
    file.read(reinterpret_cast<char*>(&numFacets), sizeof(uint32_t));


    // Read facets
    for (uint32_t i = 0; i < numFacets; ++i) {
        Facet facet;
        VertexTensor VT;

        file.read(reinterpret_cast<char*>(&facet.normal), 3 * sizeof(float));   // Read normal
        file.read(reinterpret_cast<char*>(&facet.vertex1), 3 * sizeof(float));  // Read vertex1
        file.read(reinterpret_cast<char*>(&facet.vertex2), 3 * sizeof(float));  // Read vertex2
        file.read(reinterpret_cast<char*>(&facet.vertex3), 3 * sizeof(float));  // Read vertex3
        file.read(reinterpret_cast<char*>(&facet.attributeByteCount), sizeof(uint16_t));                                           // skip over the attribute byte count

        VT.FromFacet(facet.vertex1, facet.vertex2, facet.vertex3, facet.normal);

        std::cout << "Vertex: (" << VT.x << ", " << VT.y << ", " << VT.z << ")\n";
        std::cout << "Normal: (" << VT.norm_x << ", " << VT.norm_y << ", " << VT.norm_z << ")\n";
    }
    file.close();

    std::cout << "------------------------------------------\n";
    std::cout << "Number of facets: " << numFacets << "\n";
    std::cout << "------------------------------------------\n";

    if (numFacets >= 10000) Log.Warning("Excessive facets will destory your pc, just saying!");

    return 0;
}