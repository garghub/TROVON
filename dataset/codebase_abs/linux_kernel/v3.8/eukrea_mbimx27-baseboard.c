static void F_1 ( int V_1 )
{
if ( V_1 )
F_2 ( V_2 | 5 , 1 ) ;
else
F_2 ( V_2 | 5 , 0 ) ;
}
static void F_3 ( struct V_3 * V_4 ,
unsigned int V_5 )
{
if ( V_5 )
F_2 ( V_6 | 25 , 1 ) ;
else
F_2 ( V_6 | 25 , 0 ) ;
}
static void T_1 F_4 ( void )
{
if ( F_5 ( V_7 , L_1 ) < 0 ) {
F_6 ( V_8 L_2 ) ;
return;
}
F_7 ( V_7 ) ;
}
static int F_8 ( void )
{
return ! F_9 ( V_7 ) ;
}
void T_2 F_10 ( void )
{
F_11 ( V_9 ,
F_12 ( V_9 ) , L_3 ) ;
F_13 ( & V_10 ) ;
F_14 ( & V_10 ) ;
#if ! F_15 ( V_11 )
F_16 ( & V_10 ) ;
#endif
F_17 ( & V_12 ) ;
F_18 ( 0 , & V_13 ) ;
F_19 ( 0 , V_14 ,
F_12 ( V_14 ) ) ;
F_20 ( 0 , & V_15 ) ;
#if F_15 ( V_16 ) \
|| F_15 ( V_17 )
F_21 ( V_18 | 25 | V_19 | V_20 ) ;
F_4 () ;
#endif
F_21 ( V_18 | 28 | V_19 | V_21 ) ;
F_22 ( & V_22 ) ;
V_23 [ 0 ] . V_24 = F_23 ( F_24 ( 4 , 25 ) ) ;
F_25 ( V_23 ,
F_12 ( V_23 ) ) ;
F_21 ( V_25 | 16 | V_19 | V_21 ) ;
F_21 ( V_25 | 19 | V_19 | V_21 ) ;
F_21 ( V_2 | 5 | V_19 | V_21 ) ;
F_5 ( V_2 | 5 , L_4 ) ;
F_26 ( & V_26 ) ;
F_21 ( V_6 | 25 | V_19 | V_21 ) ;
F_5 ( V_6 | 25 , L_5 ) ;
F_26 ( & V_27 ) ;
F_27 ( & V_28 ) ;
F_28 ( - 1 , & V_29 ) ;
F_29 ( L_6 , 0 , NULL , 0 , NULL , 0 ) ;
}
