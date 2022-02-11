int F_1 ( unsigned long long V_1 , unsigned long long V_2 )
{
union V_3 V_4 = { . V_5 = V_1 } ;
union V_3 V_6 = { . V_5 = V_2 } ;
if ( V_4 . V_7 . V_8 < V_6 . V_7 . V_8 )
return 0 ;
else if ( V_4 . V_7 . V_8 > V_6 . V_7 . V_8 )
return 2 ;
if ( V_4 . V_7 . V_9 < V_6 . V_7 . V_9 )
return 0 ;
else if ( V_4 . V_7 . V_9 > V_6 . V_7 . V_9 )
return 2 ;
return 1 ;
}
