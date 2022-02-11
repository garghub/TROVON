char * strchr ( const char * V_1 , int V_2 )
{
int V_3 , V_4 ;
const T_1 V_5 = ( T_1 ) V_1 ;
const T_2 * V_6 = ( const T_2 * ) ( V_5 & - 8 ) ;
const T_2 V_7 = F_1 ( V_2 ) ;
const T_2 V_8 = F_2 ( V_5 ) ;
T_2 V_9 = ( * V_6 | V_8 ) ^ ( V_7 & F_3 ( V_8 , 1 ) ) ;
T_2 V_10 , V_11 ;
while ( 1 ) {
V_10 = F_4 ( V_9 , 0 ) ;
V_11 = F_5 ( V_9 , V_7 ) ;
if ( F_6 ( ( V_10 | V_11 ) != 0 , 0 ) )
break;
V_9 = * ++ V_6 ;
}
V_3 = F_7 ( V_10 ) ;
V_4 = F_7 ( V_11 ) ;
return ( V_4 <= V_3 ) ? ( ( char * ) V_6 ) + ( V_4 >> 3 ) : NULL ;
}
