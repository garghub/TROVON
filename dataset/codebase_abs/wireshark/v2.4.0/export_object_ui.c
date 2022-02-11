T_1
F_1 ( const T_2 * V_1 , T_3 * V_2 , T_1 V_3 )
{
int V_4 ;
T_4 V_5 ;
int V_6 ;
T_5 V_7 ;
T_6 * V_8 ;
int V_9 ;
V_4 = F_2 ( V_1 , V_10 | V_11 | V_12 |
V_13 , 0644 ) ;
if( V_4 == - 1 ) {
if ( V_3 )
F_3 ( V_1 , V_14 , TRUE ) ;
return FALSE ;
}
V_8 = V_2 -> V_15 ;
V_5 = V_2 -> V_16 ;
while ( V_5 != 0 ) {
if ( V_5 > 0x40000000 )
V_6 = 0x40000000 ;
else
V_6 = ( int ) V_5 ;
V_7 = F_4 ( V_4 , V_8 , V_6 ) ;
if( V_7 <= 0 ) {
if ( V_7 < 0 )
V_9 = V_14 ;
else
V_9 = V_17 ;
if ( V_3 )
F_5 ( V_1 , V_9 ) ;
F_6 ( V_4 ) ;
return FALSE ;
}
V_5 -= V_7 ;
V_8 += V_7 ;
}
if ( F_6 ( V_4 ) < 0 ) {
if ( V_3 )
F_5 ( V_1 , V_14 ) ;
return FALSE ;
}
return TRUE ;
}
