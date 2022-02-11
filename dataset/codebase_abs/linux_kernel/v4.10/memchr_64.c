void * memchr ( const void * V_1 , int V_2 , T_1 V_3 )
{
const T_2 * V_4 ;
const T_2 * V_5 ;
const char * V_6 ;
T_3 V_7 ;
T_2 V_8 , V_9 , V_10 , V_11 ;
char * V_12 ;
if ( F_1 ( V_3 == 0 , 0 ) ) {
return NULL ;
}
V_7 = ( T_3 ) V_1 ;
V_5 = ( const T_2 * ) ( V_7 & - 8 ) ;
V_8 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 ) ;
V_10 = ( * V_5 | V_9 ) ^ ( V_8 & V_9 ) ;
V_6 = ( const char * ) V_1 + V_3 - 1 ;
V_4 = ( const T_2 * ) ( ( T_3 ) V_6 & - 8 ) ;
while ( ( V_11 = F_4 ( V_10 , V_8 ) ) == 0 ) {
if ( F_1 ( V_5 == V_4 , 0 ) ) {
return NULL ;
}
V_10 = * ++ V_5 ;
}
V_12 = ( ( char * ) V_5 ) + ( F_5 ( V_11 ) >> 3 ) ;
return ( V_12 <= V_6 ) ? V_12 : NULL ;
}
