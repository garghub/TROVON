int F_1 ( unsigned int V_1 , unsigned int type )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
int V_6 ;
V_6 = - V_7 ;
V_3 = F_2 ( V_1 ) ;
if ( V_3 && V_3 -> V_8 ) {
V_5 = V_3 -> V_8 ;
if ( V_5 -> V_9 ) {
struct V_10 * V_11 = F_3 ( V_1 ) ;
V_6 = V_5 -> V_9 ( F_4 ( V_11 ) , type ) ;
}
}
return V_6 ;
}
