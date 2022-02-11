static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 , V_11 ;
int V_12 ;
V_10 = F_2 ( V_6 -> V_13 ) ;
if ( V_10 == V_14 )
V_11 = 38400000 ;
else if ( V_10 == V_15 )
V_11 = 32768 ;
else
return - V_16 ;
V_12 = F_3 ( V_9 , V_10 , V_11 ,
V_17 ) ;
if ( V_12 ) {
F_4 ( V_18 L_1 ) ;
return V_12 ;
}
return V_12 ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_19 * V_13 = V_6 -> V_13 ;
int V_12 , V_20 ;
V_20 = F_6 ( V_13 , V_21 ) ;
F_7 ( V_6 , F_8 ( V_20 ) ,
F_9 ( V_20 ) ) ;
V_12 = F_10 ( V_13 , L_2 ,
V_22 , & V_23 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_11 ( & V_23 , F_12 ( V_24 ) ,
V_24 ) ;
if ( F_13 () )
F_14 ( V_13 , & V_23 , V_22 ) ;
else
F_15 ( & V_23 , V_22 , V_22 ) ;
return V_12 ;
}
static int T_1 F_16 ( void )
{
int V_12 ;
if ( ! F_13 () )
return - V_25 ;
F_4 ( V_26 L_3 ) ;
V_27 = F_17 ( L_4 , - 1 ) ;
if ( ! V_27 ) {
F_4 ( V_18 L_5 ) ;
return - V_28 ;
}
F_18 ( V_27 , & V_29 ) ;
V_12 = F_19 ( V_27 ) ;
if ( V_12 )
goto V_30;
return 0 ;
V_30:
F_4 ( V_18 L_6 ) ;
F_20 ( V_27 ) ;
return V_12 ;
}
static void T_2 F_21 ( void )
{
F_22 ( V_27 ) ;
}
