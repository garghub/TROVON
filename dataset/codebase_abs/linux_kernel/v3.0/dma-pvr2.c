static T_1 F_1 ( int V_1 , void * V_2 )
{
if ( F_2 ( V_3 ) ) {
F_3 ( V_4 L_1
L_2 , V_3 ) ;
F_4 ( V_3 ) ;
}
if ( V_5 ++ < 10 )
F_5 ( L_3 ,
V_1 - V_6 ) ;
V_7 = 1 ;
return V_8 ;
}
static int F_6 ( struct V_9 * V_10 )
{
if ( F_7 ( V_11 ) != 0 )
return - V_12 ;
F_8 ( 0 , V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
return V_7 == 0 ;
}
static int F_10 ( struct V_9 * V_10 )
{
if ( V_10 -> V_14 || ! V_10 -> V_15 )
return - V_16 ;
V_7 = 0 ;
F_8 ( V_10 -> V_15 , V_17 ) ;
F_8 ( V_10 -> V_5 , V_18 ) ;
F_8 ( V_10 -> V_19 & V_20 , V_11 ) ;
return 0 ;
}
static int T_2 F_11 ( void )
{
F_12 ( V_6 , & V_21 ) ;
F_13 ( V_3 , L_4 ) ;
return F_14 ( & V_22 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( V_3 ) ;
F_17 ( V_6 , 0 ) ;
F_18 ( & V_22 ) ;
}
