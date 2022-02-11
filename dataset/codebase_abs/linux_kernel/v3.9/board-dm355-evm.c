static void F_1 ( unsigned V_1 )
{
F_2 ( V_1 + 0 , L_1 ) ;
F_2 ( V_1 + 1 , L_2 ) ;
F_2 ( V_1 + 2 , L_3 ) ;
F_2 ( V_1 + 3 , L_4 ) ;
V_2 = V_1 ;
}
static void T_1 F_3 ( void )
{
F_4 ( & V_3 ) ;
F_2 ( 5 , L_5 ) ;
F_5 ( 5 ) ;
V_4 [ 0 ] . V_5 = F_6 ( 5 ) ;
F_7 ( 1 , V_4 ,
F_8 ( V_4 ) ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( & V_6 ) ;
F_11 () ;
}
static int F_12 ( int V_7 )
{
if ( ! F_13 ( V_2 ) )
return - V_8 ;
return ! F_14 ( V_2 + 2 * V_7 + 1 ) ;
}
static int F_15 ( int V_7 )
{
if ( ! F_13 ( V_2 ) )
return - V_8 ;
return F_14 ( V_2 + 2 * V_7 + 0 ) ;
}
static T_1 void F_16 ( void )
{
struct V_9 * V_10 ;
F_2 ( 1 , L_6 ) ;
F_5 ( 1 ) ;
V_11 [ 2 ] . V_12 = F_6 ( 1 ) ;
V_10 = F_17 ( & V_13 . V_14 , L_7 ) ;
if ( F_18 ( V_10 ) )
F_19 ( L_8 , V_15 ) ;
else
F_20 ( V_10 ) ;
F_21 ( V_16 ,
F_8 ( V_16 ) ) ;
F_3 () ;
F_22 ( & V_17 ) ;
F_2 ( 2 , L_9 ) ;
F_23 ( 2 , V_18 ) ;
F_24 ( 1000 , 8 ) ;
F_25 ( 0 , & V_19 ) ;
F_25 ( 1 , & V_19 ) ;
F_26 ( F_27 ( 0 ) , V_20 ,
F_8 ( V_20 ) ) ;
F_28 ( V_21 | V_22 , & V_23 ) ;
}
