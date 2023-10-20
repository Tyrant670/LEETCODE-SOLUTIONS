/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> ans;
    int i=0;

public:
    void func(vector<NestedInteger> &nestedList){
        for(int i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger()){
                ans.push_back(nestedList[i].getInteger());
            }
            else{
                func(nestedList[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        func(nestedList);
    }
    
    int next() {
        int val=-1;
        if(i<ans.size()){
            val=ans[i];
            i++;
        }
        return val;
    }
    
    bool hasNext() {
        if(i<ans.size()) return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */