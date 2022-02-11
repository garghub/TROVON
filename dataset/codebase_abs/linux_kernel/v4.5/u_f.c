struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 , int V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_3 , V_7 ) ;
if ( V_6 ) {
V_6 -> V_8 = V_4 ? : V_5 ;
V_6 -> V_9 = F_3 ( V_6 -> V_8 , V_7 ) ;
if ( ! V_6 -> V_9 ) {
F_4 ( V_3 , V_6 ) ;
V_6 = NULL ;
}
}
return V_6 ;
}
