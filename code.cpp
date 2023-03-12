#include<iostream>
using namespace std;
 

int main()
{
    int n,swap,count,count_2;
    count = 0;
    cin>>n;
    int A[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>A[i];
    }
    
       //Sorting the array

    for(int i = 0 ; i<(n-1) ; i++)
    {
        for (int j = i + 1 ;j<n ; j++)
        {
            if(A[i] > A[j])
            {
                 swap = A[i];
                 A[i] = A[j];
                 A[j] = swap;
            }
        }
    }
    
   //counting number of distinct element by using count variable
    count = 1;
    for (int i = 0 ;i<(n-1) ; i++)
    {
        if(A[i] != A[i+1])
        {
            count++;
        }
    }
 
    //making new array which has non repeated elements

   int A_new[count];
    count_2 = 0;
    for(int i = 0 ;i<(n-1) ; i++)
    {
        A_new[0] = A[0] ;
        if(A[i] != A[i+1])
        {
            count_2++;
            A_new[count_2] = A[(i+1)];
        }
    }
 
    //indicies at which distinct elements occur
 
    int index_distint[count]; int k = 0;
    for(int i = 0   ; i<n ; i++)
    {
        if (A[i] == A_new[k])
        {
             index_distint[k] = i;
             k++;
        }
    }
    
    //main programme starts from here

     //calculation of mean
     
      float n_1 = (float) n;
     float mean = 0.0; float sum = 0;
     for(int i = 0 ;i<n ; i++)
     {
        sum  = sum + A[i];
     }
     mean =  sum/n_1;
     cout<<"Mean of the given array is : "<<mean<<endl;
     
     // calculation of median
 
     float median = 0.0;
     if(n%2 != 0)
     {
         median = (float) A[(n-1)/2];
     }
     else
     {
         float extra = (float) (A[(n/2 - 1)] + A[(n/2)] );
         median =  extra/2.0;
     }
     cout<<"Median of the given array is : "<<median<<endl;
      
     // calculation of mode
 
     // finding frequency of all elements
    
     int mode[count] ={0};int freq=0;
     for(int i = 0 ; i<count; i++)
     {
         for(int j = 0 ; j<n ; j++)
         {
             if(A[j] == A_new[i])
             {
                 mode[i]++;
             }
         }
     }

  
     
      //calculating the max freq
 
      int max_mode = mode[0];
      for(int i = 1 ;i<count ;i++)
      {
          if(max_mode<mode[i])
          {
              max_mode = mode[i];
          }
      }

     int max_freq_no_of=0;
     for(int i = 0 ;i<count ;i++)
     {
         if(mode[i] == max_mode)
         {
             max_freq_no_of++;
         }
     }

     //calculation indexes at which max freq occurs
    
     int max_freq_index[max_freq_no_of];int pseudo = 0;
     for(int i = 0 ; i<count ; i++)
     {
         if(mode[i] == max_mode)
         {
             max_freq_index[pseudo] = i ;
             pseudo++;
         }
         
     }
     
     //Printing Mode
 
    cout<<"Modes of the given array are : "<<A_new[max_freq_index[0]];
    for(int i = 1 ;i<max_freq_no_of;i++)
    {
        cout<<", ";
        cout<<A_new[max_freq_index[i]];
    }
    

    return 0;
}
