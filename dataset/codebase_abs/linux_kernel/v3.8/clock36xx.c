int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
T_1 V_6 , V_7 , V_8 ;
int V_9 ;
V_9 = F_2 ( V_2 ) ;
V_5 = F_3 ( F_4 ( V_2 -> V_2 ) ) ;
V_4 = F_5 ( V_5 ) ;
if ( ! V_9 ) {
V_8 = F_6 ( V_4 -> V_10 ) ;
V_7 = F_7 ( V_4 -> V_11 ) ;
V_6 = V_7 ;
V_6 ^= ( 1 << V_8 ) ;
F_8 ( V_6 , V_4 -> V_11 ) ;
F_8 ( V_7 , V_4 -> V_11 ) ;
}
return V_9 ;
}
