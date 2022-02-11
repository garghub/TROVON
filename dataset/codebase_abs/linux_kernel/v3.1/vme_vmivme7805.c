static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static int F_3 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
int V_6 ;
T_2 V_7 ;
V_6 = F_4 ( V_3 ) ;
if ( V_6 ) {
F_5 ( & V_3 -> V_8 , L_1 ) ;
goto V_9;
}
V_6 = F_6 ( V_3 , V_10 ) ;
if ( V_6 ) {
F_5 ( & V_3 -> V_8 , L_2 ) ;
goto V_11;
}
V_12 = F_7 ( F_8 ( V_3 , 0 ) , 16 ) ;
if ( ! V_12 ) {
F_5 ( & V_3 -> V_8 , L_3 ) ;
V_6 = - V_13 ;
goto V_14;
}
F_9 ( 0 , V_12 + V_15 ) ;
V_7 = F_10 ( V_12 + V_15 ) & 0x00000FFF ;
V_7 |= V_16 ;
F_9 ( V_7 , V_12 + V_15 ) ;
V_7 = F_10 ( V_12 + V_15 ) & 0x00000FFF ;
V_7 = V_7 | V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 ;
F_9 ( V_7 , V_12 + V_15 ) ;
return 0 ;
V_14:
F_11 ( V_3 ) ;
V_11:
F_12 ( V_3 ) ;
V_9:
return V_6 ;
}
static void F_13 ( struct V_2 * V_3 )
{
F_14 ( V_12 ) ;
F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_1 ) ;
}
