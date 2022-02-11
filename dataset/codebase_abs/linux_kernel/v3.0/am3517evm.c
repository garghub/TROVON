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
V_11 = F_4 ( V_9 , 0 ,
V_16 , V_17 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_3 ) ;
return V_11 ;
}
V_11 = F_4 ( V_10 , V_18 , 0 ,
V_17 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_4 ) ;
return V_11 ;
}
F_4 ( V_10 , V_19 , 0 ,
V_17 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_5 ) ;
return V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
F_6 ( V_23 , V_24 ,
F_7 ( V_24 ) ) ;
F_8 ( V_23 , V_25 , F_7 ( V_25 ) ) ;
F_9 ( V_23 , L_6 ) ;
F_9 ( V_23 , L_7 ) ;
F_9 ( V_23 , L_8 ) ;
F_10 ( V_23 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
int V_11 ;
if ( ! F_12 () )
return - V_26 ;
F_13 ( L_9 ) ;
V_27 = F_14 ( L_10 , - 1 ) ;
if ( ! V_27 ) {
F_3 ( V_15 L_11 ) ;
return - V_28 ;
}
F_15 ( V_27 , & V_29 ) ;
V_11 = F_16 ( V_27 ) ;
if ( V_11 )
goto V_30;
return 0 ;
V_30:
F_3 ( V_15 L_12 ) ;
F_17 ( V_27 ) ;
return V_11 ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_27 ) ;
}
