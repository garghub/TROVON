static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_2 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 , 26000000 ,
V_16 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_3 ) ;
return V_11 ;
}
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_11 ;
if ( ! F_6 () )
return - V_17 ;
F_3 ( V_18 L_4 ) ;
V_19 = F_7 ( L_5 , - 1 ) ;
if ( ! V_19 ) {
F_3 ( V_15 L_6 ) ;
return - V_20 ;
}
F_8 ( V_19 , & V_21 ) ;
V_11 = F_9 ( V_19 ) ;
if ( V_11 )
goto V_22;
return 0 ;
V_22:
F_3 ( V_15 L_7 ) ;
F_10 ( V_19 ) ;
return V_11 ;
}
static void T_2 F_11 ( void )
{
F_12 ( V_19 ) ;
}
