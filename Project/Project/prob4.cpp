class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1<N2) return findMedianSortedArrays(nums2,nums1);
        
        int h = 0;
        int t = 2*N2;
        while(h<=t)
        {
            int mid2 = (h+t)/2;
            int mid1 = N1+N2-mid2;
            double L1 = (mid1 == 0)?INT_MIN :nums1[(mid1-1)/2];
            double R1 = (mid1 == 2*N1)? INT_MAX:nums1[(mid1)/2];
            double L2 = (mid2 == 0)?INT_MIN :nums2[(mid2-1)/2];
            double R2 = (mid2 == 2*N2)? INT_MAX:nums2[(mid2)/2];    
            
            if (L1>R2) h = mid2+1;
            else if (L2>R1) t = mid2-1;
            else return (max(L1,L2)+min(R1,R2))/2;
        }
    }
};

