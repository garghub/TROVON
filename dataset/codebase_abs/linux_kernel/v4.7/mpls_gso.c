static struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( - V_5 ) ;
T_1 V_6 ;
T_2 V_7 ;
V_7 = V_2 -> V_8 ;
V_2 -> V_8 = V_2 -> V_9 ;
F_3 ( V_2 , V_2 -> V_10 ) ;
V_6 = V_2 -> V_11 -> V_6 & V_3 ;
V_4 = F_4 ( V_2 , V_6 ) ;
V_2 -> V_8 = V_7 ;
F_5 ( V_2 , V_2 -> V_12 - F_6 ( V_2 ) ) ;
return V_4 ;
}
static int T_3 F_7 ( void )
{
F_8 ( L_1 ) ;
F_9 ( & V_13 ) ;
F_9 ( & V_14 ) ;
return 0 ;
}
static void T_4 F_10 ( void )
{
F_11 ( & V_13 ) ;
F_11 ( & V_14 ) ;
}
