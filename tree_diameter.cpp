#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode{
    int distance;
    vector<TreeNode*> childrens;
    TreeNode(int dist): distance(dist){}
};

struct DiameterReturnVal{
    int diameter;
    int distanceToMostDistantLeaf;
};

DiameterReturnVal _find_diameter(TreeNode *root){
    if(root->childrens.size() == 0)
        return {0, root->distance};

    DiameterReturnVal result;
    result.diameter = INT_MIN;
    int max_dist = 0, max_2_dist = 0;
    for(auto child : root->childrens){
        auto res = _find_diameter(child);
        result.diameter = max(result.diameter, res.diameter);
        if(res.distanceToMostDistantLeaf > max_dist){
            max_2_dist = max_dist;
            max_dist = res.distanceToMostDistantLeaf;
        }
        else if(res.distanceToMostDistantLeaf > max_2_dist)
            max_2_dist = res.distanceToMostDistantLeaf;
    }
    result.distanceToMostDistantLeaf = max_dist + root->distance;
    result.diameter = max(result.diameter, max_dist + max_2_dist);
    return result;
}

int find_diameter(TreeNode *root){
    if(root == nullptr)
        return INT_MIN;
    auto result = _find_diameter(root);
    return result.diameter;
}

void test_case_one(){
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(5);
    root1->childrens.push_back(root2);
    root1->childrens.push_back(root3);
    root2->childrens.push_back(root4);
    root2->childrens.push_back(root5);
    auto dia = find_diameter(root1);
    cout << "Diameter of Tree = " << dia << endl;
}

int main(){
    test_case_one();
    return 0;
}
