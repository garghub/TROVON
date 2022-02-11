const char *
F_1 ( void * V_1 , T_1 V_2 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
T_3 * V_4 ;
const T_4 * V_5 = NULL ;
V_4 = F_2 ( V_3 -> V_6 ) ;
if ( V_2 < V_4 -> V_7 )
V_5 = & F_3 ( V_4 -> V_8 , T_4 , V_2 ) ;
F_4 ( V_4 ) ;
if ( V_5 ) {
if ( V_5 -> V_9 )
return V_5 -> V_9 ;
else if ( V_5 -> V_10 )
return V_5 -> V_10 ;
}
return L_1 ;
}
void
F_5 ( T_2 * V_3 )
{
memset ( V_3 , 0 , sizeof( T_2 ) ) ;
V_3 -> V_11 = V_12 ;
}
