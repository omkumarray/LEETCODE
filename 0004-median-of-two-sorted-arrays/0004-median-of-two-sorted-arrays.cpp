class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {

        int n1=nums1.size();  
        int n2=nums2.size();
        int n=n1+n2;  
      
        if(n2==0)
            return n1%2?nums1[n1/2]:(nums1[n1/2-1]+nums1[n1/2])/2.0;
        if(n1==0)
             return n2%2?nums2[n2/2]:(nums2[n2/2-1]+nums2[n2/2])/2.0;
        
        nums1.resize(n);
     
        int i=0;
        int j=0;

        while(i<n1)  
        {
            if(nums1[i]>nums2[0])
            {
                swap(nums1[i],nums2[0]); 
                rearrangeArray(nums2);  
            }
            i++;
        } 
        while(j<nums2.size())
            nums1[i++]=nums2[j++];

    return n%2?nums1[n/2]:(nums1[n/2-1]+nums1[n/2])/2.0;
    }
    
    void rearrangeArray(vector<int>&nums2)
    {
        for(int i=1;i<nums2.size()&&nums2[i]<nums2[i-1];i++)
            swap(nums2[i],nums2[i-1]);
    }
};