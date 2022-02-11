T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
union V_3 V_4 ;
union V_3 V_5 ;
T_2 V_6 ;
if ( V_2 == 0 )
return V_1 ;
V_5 . V_7 = V_1 ;
V_6 = ( sizeof( V_8 ) * V_9 ) - V_2 ;
if ( V_6 <= 0 ) {
V_4 . V_10 . V_11 = V_5 . V_10 . V_11 >> ( sizeof( V_8 ) * V_9 - 1 ) ;
V_4 . V_10 . V_12 = V_5 . V_10 . V_11 >> - V_6 ;
} else {
T_3 V_13 = ( T_3 ) V_5 . V_10 . V_11 << V_6 ;
V_4 . V_10 . V_11 = V_5 . V_10 . V_11 >> V_2 ;
V_4 . V_10 . V_12 = ( ( T_3 ) V_5 . V_10 . V_12 >> V_2 ) | V_13 ;
}
return V_4 . V_7 ;
}
