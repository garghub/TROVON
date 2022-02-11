static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = 0 ;
struct V_6 * V_7 ;
F_2 (tmp, dev) {
if ( V_7 -> V_4 == V_4 )
return 1 << V_5 ;
V_5 ++ ;
}
return 0 ;
}
T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_9 ;
T_1 V_10 = 0 ;
F_4 (port, ep) {
V_8 = F_5 ( V_9 ) ;
if ( ! V_8 ) {
F_6 ( V_9 ) ;
return 0 ;
}
V_10 |= F_1 ( V_2 , V_8 ) ;
F_6 ( V_8 ) ;
}
return V_10 ;
}
