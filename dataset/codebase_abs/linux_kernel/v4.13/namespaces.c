struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
T_1 V_4 = ( ( V_3 ? V_3 -> V_5 : V_6 ) *
sizeof( struct V_7 ) ) ;
V_1 = F_2 ( sizeof( struct V_1 ) + V_4 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_8 = - 1 ;
if ( V_3 )
memcpy ( V_1 -> V_9 , V_3 -> V_9 , V_4 ) ;
return V_1 ;
}
void F_3 ( struct V_1 * V_1 )
{
free ( V_1 ) ;
}
