void F_1 ( const char * V_1 , const char * V_2 ,
T_1 V_3 , T_2 V_4 ) {
T_3 * V_5 ;
V_5 = ( T_3 * ) F_2 ( sizeof( T_3 ) ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
V_6 = F_3 ( V_6 , V_5 ) ;
}
struct V_7 * F_4 ( const char * V_8 )
{
T_4 * V_9 = V_6 ;
T_3 * V_10 ;
while ( V_9 != NULL ) {
V_10 = ( T_3 * ) V_9 -> V_11 ;
if ( ! strcmp ( V_10 -> V_1 , V_8 ) )
return V_10 ;
V_9 = F_5 ( V_9 ) ;
}
return NULL ;
}
