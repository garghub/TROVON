struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( struct V_1 ) , V_4 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_2 = ( V_5 ) V_2 ;
V_3 -> V_6 = F_3 ( V_2 ) ;
if ( ! V_3 -> V_6 ) {
F_4 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
void F_5 ( struct V_1 * V_3 )
{
if ( V_3 ) {
F_6 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
F_4 ( V_3 ) ;
}
}
