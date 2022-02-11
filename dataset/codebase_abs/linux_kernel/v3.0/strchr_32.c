char * strchr ( const char * V_1 , int V_2 )
{
int V_3 , V_4 ;
const T_1 V_5 = ( T_1 ) V_1 ;
const T_2 * V_6 = ( const T_2 * ) ( V_5 & - 4 ) ;
const T_2 V_7 = 0x01010101 * ( V_8 ) V_2 ;
const T_2 V_9 = ( 1 << ( V_5 << 3 ) ) - 1 ;
T_2 V_10 = ( * V_6 | V_9 ) ^ ( V_7 & F_1 ( V_9 , 1 ) ) ;
T_2 V_11 , V_12 ;
while ( 1 ) {
V_11 = F_2 ( V_10 , 0 ) ;
V_12 = F_2 ( V_10 , V_7 ) ;
if ( F_3 ( V_11 | V_12 , 0 ) )
break;
V_10 = * ++ V_6 ;
}
V_3 = F_4 ( V_11 ) ;
V_4 = F_4 ( V_12 ) ;
return ( V_4 <= V_3 ) ? ( ( char * ) V_6 ) + ( V_4 >> 3 ) : NULL ;
}
