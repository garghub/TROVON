T_1
F_1 ( void * V_1 , T_2 * V_2 , T_3 * T_4 V_3 ,
const void * V_4 )
{
T_5 * V_5 = ( T_5 * ) V_1 ;
const T_6 * V_6 = ( const T_6 * ) V_4 ;
T_7 * V_7 ;
if ( V_6 ) {
V_7 = ( T_7 * ) F_2 ( sizeof( T_7 ) ) ;
V_7 -> V_8 = V_2 -> V_9 ;
V_7 -> V_10 = V_6 -> V_10 ;
V_7 -> V_11 = V_6 -> V_11 ;
V_7 -> V_12 = F_3 ( F_4 ( V_6 -> V_12 ) ) ;
V_7 -> V_13 = V_6 -> V_13 ;
V_7 -> V_14 = V_6 -> V_14 ;
F_5 ( V_5 , V_7 ) ;
return TRUE ;
} else {
return FALSE ;
}
}
