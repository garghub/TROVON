T_1 T_2 F_1 ( unsigned long long V_1 , unsigned long long V_2 )
{
const T_3 V_3 = { . V_4 = V_1 } ;
const T_3 V_5 = { . V_4 = V_2 } ;
if ( ( unsigned int ) V_3 . V_6 . V_7 < ( unsigned int ) V_5 . V_6 . V_7 )
return 0 ;
else if ( ( unsigned int ) V_3 . V_6 . V_7 > ( unsigned int ) V_5 . V_6 . V_7 )
return 2 ;
if ( ( unsigned int ) V_3 . V_6 . V_8 < ( unsigned int ) V_5 . V_6 . V_8 )
return 0 ;
else if ( ( unsigned int ) V_3 . V_6 . V_8 > ( unsigned int ) V_5 . V_6 . V_8 )
return 2 ;
return 1 ;
}
