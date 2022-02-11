static void F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 -> V_2 ) ;
V_2 |= V_1 -> V_3 ;
F_3 ( V_2 , V_1 -> V_2 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 -> V_2 ) ;
V_2 &= ~ V_1 -> V_3 ;
F_3 ( V_2 , V_1 -> V_2 ) ;
}
void T_2 F_5 ( void )
{
F_6 ( F_7 ( V_4 ) ) ;
}
