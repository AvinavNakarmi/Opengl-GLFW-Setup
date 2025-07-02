#include <vector>
#include "mesh.h";
class QuadTree
{
public:
    std::vector<Mesh*> vec;
    void add();
    void remove();
    void query();
};