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
F_10 () ;
}
static int F_11 ( int V_6 )
{
if ( ! F_12 ( V_2 ) )
return - V_7 ;
return ! F_13 ( V_2 + 2 * V_6 + 1 ) ;
}
static int F_14 ( int V_6 )
{
if ( ! F_12 ( V_2 ) )
return - V_7 ;
return F_13 ( V_2 + 2 * V_6 + 0 ) ;
}
static T_1 void F_15 ( void )
{
struct V_8 * V_9 ;
F_2 ( 1 , L_6 ) ;
F_5 ( 1 ) ;
V_10 [ 2 ] . V_11 = F_6 ( 1 ) ;
V_9 = F_16 ( & V_12 . V_13 , L_7 ) ;
if ( F_17 ( V_9 ) )
F_18 ( L_8 , V_14 ) ;
else
F_19 ( V_9 ) ;
F_20 ( V_15 ,
F_8 ( V_15 ) ) ;
F_3 () ;
F_21 ( & V_16 ) ;
F_2 ( 2 , L_9 ) ;
F_22 ( 2 , V_17 ) ;
F_23 ( 1000 , 8 ) ;
F_24 ( 0 , & V_18 ) ;
F_24 ( 1 , & V_18 ) ;
F_25 ( & V_19 , & V_20 ) ;
F_26 ( F_27 ( 0 ) , V_21 ,
F_8 ( V_21 ) ) ;
F_28 ( V_22 | V_23 , & V_24 ) ;
}
