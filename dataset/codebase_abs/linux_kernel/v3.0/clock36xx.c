static int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 , V_3 , V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 ) ;
if ( ! V_5 ) {
V_4 = F_3 ( V_1 -> V_6 -> V_7 ) ;
V_3 = F_4 ( V_1 -> V_6 -> V_8 ) ;
V_2 = V_3 ;
V_2 ^= ( 1 << V_4 ) ;
F_5 ( V_2 , V_1 -> V_6 -> V_8 ) ;
F_5 ( V_3 , V_1 -> V_6 -> V_8 ) ;
}
return V_5 ;
}
