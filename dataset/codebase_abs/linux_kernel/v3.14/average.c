void F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 )
{
F_2 ( ! F_3 ( V_4 ) || ! F_3 ( V_3 ) ) ;
V_2 -> V_4 = F_4 ( V_4 ) ;
V_2 -> V_3 = F_4 ( V_3 ) ;
V_2 -> V_5 = 0 ;
}
struct V_1 * F_5 ( struct V_1 * V_2 , unsigned long V_6 )
{
unsigned long V_5 = F_6 ( V_2 -> V_5 ) ;
F_6 ( V_2 -> V_5 ) = V_5 ?
( ( ( V_5 << V_2 -> V_4 ) - V_5 ) +
( V_6 << V_2 -> V_3 ) ) >> V_2 -> V_4 :
( V_6 << V_2 -> V_3 ) ;
return V_2 ;
}
