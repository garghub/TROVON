static void T_1 F_1 ( void )
{
F_2 ( 12000000 ) ;
}
static void T_1 F_3 ( void )
{
if ( F_4 () || F_5 () )
V_1 . V_2 = V_3 ;
F_6 ( & V_1 ) ;
}
static int F_7 ( struct V_4 * V_5 ,
T_2 (* F_8)( int , void * ) , void * V_6 )
{
F_9 ( V_7 , 0 ) ;
return F_10 ( F_11 ( V_7 ) , F_8 ,
V_8 | V_9 ,
L_1 , V_6 ) ;
}
static void F_12 ( struct V_4 * V_5 , void * V_6 )
{
F_13 ( F_11 ( V_7 ) , V_6 ) ;
}
static void T_1 F_14 ( void )
{
if ( F_15 () )
F_16 ( V_10 , F_17 ( V_10 ) ) ;
else if ( F_5 () )
F_16 ( V_11 , F_17 ( V_11 ) ) ;
}
static void T_1 F_18 ( void )
{
if ( F_4 () || F_5 () )
V_12 . V_13 = V_14 ;
F_19 ( & V_12 ) ;
}
static void T_1 F_20 ( void )
{
if ( F_4 () || F_5 () ) {
V_15 . V_16 = V_17 ;
V_15 . V_18 = V_19 ;
}
if ( F_5 () )
F_21 ( 0 , 3 , & V_20 ) ;
else
F_21 ( 0 , 3 , & V_21 ) ;
F_22 ( & V_15 ) ;
}
static void T_1 F_23 ( void )
{
F_24 ( V_22 , 1 ) ;
F_25 ( V_22 , 1 ) ;
F_26 ( & V_23 ) ;
}
static void T_1 F_23 ( void ) {}
static void T_1 F_27 ( void )
{
if ( F_4 () || F_5 () )
V_24 [ 0 ] . V_25 = 0 ;
F_28 ( V_24 , F_17 ( V_24 ) ) ;
}
static void T_1 F_29 ( void )
{
F_30 ( 0 , 0 , 0 ) ;
F_31 () ;
F_32 ( & V_26 ) ;
F_3 () ;
F_14 () ;
F_18 () ;
F_20 () ;
F_23 () ;
F_27 () ;
if ( F_5 () ) {
F_33 ( V_27 , F_17 ( V_27 ) ) ;
} else {
F_33 ( NULL , 0 ) ;
F_34 ( V_28 , F_35 ( 10 )
| V_29
| V_30 ) ;
}
}
