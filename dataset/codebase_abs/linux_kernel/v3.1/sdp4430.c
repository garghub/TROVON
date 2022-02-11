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
struct V_20 * V_21 = & V_13 -> V_21 ;
int V_12 ;
V_12 = F_6 ( V_21 , V_22 ,
F_7 ( V_22 ) ) ;
if ( V_12 )
return V_12 ;
F_8 ( V_21 , V_23 , F_7 ( V_23 ) ) ;
F_9 ( V_21 , L_2 ) ;
F_9 ( V_21 , L_3 ) ;
F_9 ( V_21 , L_4 ) ;
F_9 ( V_21 , L_5 ) ;
F_9 ( V_21 , L_6 ) ;
F_9 ( V_21 , L_7 ) ;
V_12 = F_10 ( V_21 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_11 ( V_13 , L_8 ,
V_24 , & V_25 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_12 ( & V_25 , F_7 ( V_26 ) ,
V_26 ) ;
if ( F_13 () )
F_14 ( V_13 , & V_25 , V_24 ) ;
else
F_15 ( & V_25 , V_24 , V_24 ) ;
return V_12 ;
}
static int T_1 F_16 ( void )
{
int V_12 ;
if ( ! F_13 () )
return - V_27 ;
F_4 ( V_28 L_9 ) ;
V_29 = F_17 ( L_10 , - 1 ) ;
if ( ! V_29 ) {
F_4 ( V_18 L_11 ) ;
return - V_30 ;
}
F_18 ( V_29 , & V_31 ) ;
V_12 = F_19 ( V_29 ) ;
if ( V_12 )
goto V_32;
return 0 ;
V_32:
F_4 ( V_18 L_12 ) ;
F_20 ( V_29 ) ;
return V_12 ;
}
static void T_2 F_21 ( void )
{
F_22 ( V_29 ) ;
}
