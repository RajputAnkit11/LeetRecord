class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        /*
        
        //DeQue Solution
        //Pair<int,int> contains (nums[i],index)
        deque<pair<int,int>> dq;  //We will store elements in the deque only inside our current window
        vector<int> ans;
        
        for(int i=0;i<nums.size();++i)
        {
            if(!dq.empty() and dq.front().second<=(i-k))    //Remove front element if it goes out of window size
                dq.pop_front();
            while(!dq.empty() and dq.back().first<nums[i])  //Maintain elements in DSC order
                dq.pop_back();
            dq.push_back(make_pair(nums[i],i));     //Push current NODE
            if(i>=(k-1))
                ans.push_back(dq.front().first);    //Include maximum of cuurrent window
        }
        return ans;
        
        */
        
        ////Max_Heap Solution
        //Pair<int,int> contains (nums[i],index)
        priority_queue<pair<int,int>> heap; //Max_Heap to find maximum in a sliding window
        vector<int> ans;    //Stores all maximum values for all sliding windows
        
        for(int i=0;i<nums.size();++i)
        {
            while(!heap.empty() and heap.top().second<=(i-k))  //Pop the root (max_element),if it is out of sliding window
                heap.pop();
            heap.push(make_pair(nums[i],i));    //Push current element (along with its index) into the heap
            if(i>=k-1)      //Store max in the window if we have a valid window (based on size K)
                ans.push_back(heap.top().first);       
        }
        return ans;
    }
};
​
​
​
