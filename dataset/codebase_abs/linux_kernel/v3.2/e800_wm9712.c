static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_6 )
F_2 ( V_7 , 1 ) ;
else if ( V_5 & V_8 )
F_2 ( V_7 , 0 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_6 )
F_2 ( V_9 , 0 ) ;
else if ( V_5 & V_8 )
F_2 ( V_9 , 1 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
F_5 ( V_15 , V_16 ,
F_6 ( V_16 ) ) ;
F_7 ( V_15 , V_17 , F_6 ( V_17 ) ) ;
return 0 ;
}
static int T_1 F_8 ( void )
{
int V_18 ;
if ( ! F_9 () )
return - V_19 ;
V_18 = F_10 ( V_9 , L_1 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_10 ( V_7 , L_2 ) ;
if ( V_18 )
goto V_20;
V_18 = F_11 ( V_9 , 1 ) ;
if ( V_18 )
goto V_21;
V_18 = F_11 ( V_7 , 1 ) ;
if ( V_18 )
goto V_21;
V_22 = F_12 ( L_3 , - 1 ) ;
if ( ! V_22 )
return - V_23 ;
F_13 ( V_22 , & V_24 ) ;
V_18 = F_14 ( V_22 ) ;
if ( ! V_18 )
return 0 ;
F_15 ( V_22 ) ;
V_21:
F_16 ( V_7 ) ;
V_20:
F_16 ( V_9 ) ;
return V_18 ;
}
static void T_2 F_17 ( void )
{
F_18 ( V_22 ) ;
F_16 ( V_7 ) ;
F_16 ( V_9 ) ;
}
