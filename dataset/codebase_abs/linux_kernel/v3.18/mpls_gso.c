static struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( - V_5 ) ;
T_1 V_6 ;
T_2 V_7 ;
if ( F_3 ( F_4 ( V_2 ) -> V_8 &
~ ( V_9 |
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 |
V_17 ) ) )
goto V_18;
V_7 = V_2 -> V_19 ;
V_2 -> V_19 = V_2 -> V_20 ;
F_5 ( V_2 , V_2 -> V_21 ) ;
V_6 = V_2 -> V_22 -> V_6 & V_3 ;
V_4 = F_6 ( V_2 , V_6 ) ;
V_2 -> V_19 = V_7 ;
F_7 ( V_2 , V_2 -> V_23 - F_8 ( V_2 ) ) ;
V_18:
return V_4 ;
}
static int T_3 F_9 ( void )
{
F_10 ( L_1 ) ;
F_11 ( & V_24 ) ;
F_11 ( & V_25 ) ;
return 0 ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_24 ) ;
F_13 ( & V_25 ) ;
}
