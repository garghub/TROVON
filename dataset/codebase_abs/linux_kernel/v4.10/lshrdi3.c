T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
const T_3 V_3 = { . V_4 = V_1 } ;
const T_2 V_5 = ( sizeof ( V_6 ) * V_7 ) - V_2 ;
T_3 V_8 ;
if ( V_2 == 0 )
return V_1 ;
if ( V_5 <= 0 ) {
V_8 . V_9 . V_10 = 0 ;
V_8 . V_9 . V_11 = ( V_12 ) V_3 . V_9 . V_10 >> - V_5 ;
} else {
const V_12 V_13 = ( V_12 ) V_3 . V_9 . V_10 << V_5 ;
V_8 . V_9 . V_10 = ( V_12 ) V_3 . V_9 . V_10 >> V_2 ;
V_8 . V_9 . V_11 = ( ( V_12 ) V_3 . V_9 . V_11 >> V_2 ) | V_13 ;
}
return V_8 . V_4 ;
}
