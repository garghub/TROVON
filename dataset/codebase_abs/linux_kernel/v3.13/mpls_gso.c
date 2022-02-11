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
V_16 ) ) )
goto V_17;
V_7 = V_2 -> V_18 ;
V_2 -> V_18 = V_2 -> V_19 ;
F_5 ( V_2 , V_2 -> V_20 ) ;
V_6 = V_2 -> V_21 -> V_6 & F_6 ( V_2 ) ;
V_4 = F_7 ( V_2 , V_6 ) ;
V_2 -> V_18 = V_7 ;
F_5 ( V_2 , V_2 -> V_22 - F_8 ( V_2 ) ) ;
V_17:
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_3 F_10 ( void )
{
F_11 ( L_1 ) ;
F_12 ( & V_23 ) ;
F_12 ( & V_24 ) ;
return 0 ;
}
static void T_4 F_13 ( void )
{
F_14 ( & V_23 ) ;
F_14 ( & V_24 ) ;
}
