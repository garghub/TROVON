T_1 F_1 ( T_1 V_1 , const T_2 * V_2 , T_3 V_3 )
{
T_1 V_4 = V_1 & 0xffff ;
T_1 V_5 = ( V_1 >> 16 ) & 0xffff ;
T_3 V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
V_4 = ( V_4 + V_2 [ V_6 ] ) % V_7 ;
V_5 = ( V_5 + V_4 ) % V_7 ;
}
return ( V_5 << 16 ) + V_4 ;
}
T_1 F_2 ( const T_2 * V_2 , T_3 V_3 )
{
return F_1 ( 1 , V_2 , V_3 ) ;
}
T_1 F_3 ( const char * V_2 )
{
return F_1 ( 1 , ( const T_2 * ) V_2 , strlen ( V_2 ) ) ;
}
