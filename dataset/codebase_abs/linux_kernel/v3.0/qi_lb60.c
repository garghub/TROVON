static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_6 = ! F_2 ( V_5 ) ;
F_3 ( V_7 , V_6 ) ;
F_3 ( V_8 , V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_10 -> V_14 ;
struct V_15 * V_16 = & V_12 -> V_16 ;
int V_17 ;
F_5 ( V_16 , L_1 ) ;
F_5 ( V_16 , L_2 ) ;
V_17 = F_6 ( V_14 , V_18 ) ;
if ( V_17 < 0 ) {
F_7 ( V_12 -> V_19 , L_3 , V_17 ) ;
return V_17 ;
}
return 0 ;
}
static int T_1 F_8 ( void )
{
int V_17 ;
V_20 = F_9 ( L_4 , - 1 ) ;
if ( ! V_20 )
return - V_21 ;
V_17 = F_10 ( V_22 , F_11 ( V_22 ) ) ;
if ( V_17 ) {
F_12 ( L_5 , V_17 ) ;
goto V_23;
}
F_13 ( V_20 , & V_24 ) ;
V_17 = F_14 ( V_20 ) ;
if ( V_17 ) {
F_12 ( L_6 , V_17 ) ;
goto V_25;
}
return 0 ;
V_25:
F_13 ( V_20 , NULL ) ;
F_15 ( V_22 , F_11 ( V_22 ) ) ;
V_23:
F_16 ( V_20 ) ;
return V_17 ;
}
static void T_2 F_17 ( void )
{
F_18 ( V_20 ) ;
F_15 ( V_22 , F_11 ( V_22 ) ) ;
}
