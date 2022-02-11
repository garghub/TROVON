long long F_1 ( long long V_1 , T_1 V_2 )
{
T_2 V_3 , V_4 ;
T_1 V_5 ;
if ( V_2 == 0 )
return V_1 ;
V_3 . V_6 = V_1 ;
V_5 = 32 - V_2 ;
if ( V_5 <= 0 ) {
V_4 . V_7 . V_8 = 0 ;
V_4 . V_7 . V_9 = ( unsigned int ) V_3 . V_7 . V_8 << - V_5 ;
} else {
const unsigned int V_10 = ( unsigned int ) V_3 . V_7 . V_8 >> V_5 ;
V_4 . V_7 . V_8 = ( unsigned int ) V_3 . V_7 . V_8 << V_2 ;
V_4 . V_7 . V_9 = ( ( unsigned int ) V_3 . V_7 . V_9 << V_2 ) | V_10 ;
}
return V_4 . V_6 ;
}
