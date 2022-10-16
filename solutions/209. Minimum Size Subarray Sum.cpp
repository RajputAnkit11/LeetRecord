                cout<<sum<<endl;
                if(sum>=target){
                    break;
                }
                f1 = false;
            }
            cout<<"here\n";
            while(l<r){
                if(f1 == false) break;
                f2 = true;
                sum -= nums[l];
                cout<<"sum 2 = "<<sum<<endl;
                l++;
                if(sum<target){
                    ans = min(ans,r-l+1);
                    cout<<"ans "<<ans<<endl;
                    break;
                }
                else{
                    continue;
                }
            }
            
            if(!f1 and !f2){
                break;
            }
        }
        
        return ans==INT_MAX? 0 : ans;
    }
};
