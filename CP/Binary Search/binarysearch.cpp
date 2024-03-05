ll lo=0, hi=mx;  ///mx=max possible ans
while(lo<hi){
    ll mid=(lo+hi+1)>>1;
    if(condition)  ///valid condition->ans can be greater than or equal mid
        lo=mid;
    else 
        hi=mid-1;  ///ans is less than mid
}
///or
while(lo<hi){
    ll mid=(lo+hi)>>1;
    if(condition)  ///valid condition->ans can be less than or equal mid
        hi=mid;
    else 
        lo=mid+1;  ///ans is greater than mid
}

ll lo=0, hi=mx, esp=maxError;  ///mx=max possible ans
while((hi-lo)>esp){
    ll mid=(lo+hi+esp)/2.0;
    if(condition)  lo=mid;
    else  hi=mid-esp; 
}
 while((hi-lo)>esp){
    ll mid=(lo+hi)/2.0;
    if(condition)  hi=mid;
    else lo=mid+esp;  
}
