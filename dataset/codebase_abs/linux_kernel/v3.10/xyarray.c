struct V_1 * F_1 ( int V_2 , int V_3 , T_1 V_4 )
{
T_1 V_5 = V_3 * V_4 ;
struct V_1 * V_6 = F_2 ( sizeof( * V_6 ) + V_2 * V_5 ) ;
if ( V_6 != NULL ) {
V_6 -> V_4 = V_4 ;
V_6 -> V_5 = V_5 ;
}
return V_6 ;
}
void F_3 ( struct V_1 * V_6 )
{
free ( V_6 ) ;
}
