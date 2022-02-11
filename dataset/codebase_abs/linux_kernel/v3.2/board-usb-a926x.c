static void T_1 F_1 ( void )
{
F_2 ( 12000000 ) ;
F_3 ( 0 , 0 , 0 ) ;
F_4 ( 0 ) ;
}
static void T_1 F_5 ( void )
{
if ( F_6 () || F_7 () )
V_1 . V_2 = V_3 ;
F_8 ( & V_1 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
T_2 (* F_10)( int , void * ) , void * V_6 )
{
F_11 ( V_7 , 0 ) ;
return F_12 ( F_13 ( V_7 ) , F_10 ,
V_8 | V_9 ,
L_1 , V_6 ) ;
}
static void F_14 ( struct V_4 * V_5 , void * V_6 )
{
F_15 ( F_13 ( V_7 ) , V_6 ) ;
}
static void T_1 F_16 ( void )
{
if ( F_17 () )
F_18 ( V_10 , F_19 ( V_10 ) ) ;
else if ( F_7 () )
F_18 ( V_11 , F_19 ( V_11 ) ) ;
}
static void T_1 F_20 ( void )
{
if ( F_6 () || F_7 () )
V_12 . V_13 = V_14 ;
F_21 ( & V_12 ) ;
}
static void T_1 F_22 ( void )
{
if ( F_6 () || F_7 () ) {
V_15 . V_16 = V_17 ;
V_15 . V_18 = V_19 ;
}
if ( F_7 () )
F_23 ( 3 , & V_20 ) ;
else
F_23 ( 3 , & V_21 ) ;
F_24 ( & V_15 ) ;
}
static void T_1 F_25 ( void )
{
F_26 ( V_22 , 1 ) ;
F_27 ( V_22 , 1 ) ;
F_28 ( & V_23 ) ;
}
static void T_1 F_25 ( void ) {}
static void T_1 F_29 ( void )
{
if ( F_6 () || F_7 () )
V_24 [ 0 ] . V_25 = 0 ;
F_30 ( V_24 , F_19 ( V_24 ) ) ;
}
static void T_1 F_31 ( void )
{
F_32 () ;
F_33 ( & V_26 ) ;
F_5 () ;
F_16 () ;
F_20 () ;
F_22 () ;
F_25 () ;
F_29 () ;
if ( F_7 () ) {
F_34 ( V_27 , F_19 ( V_27 ) ) ;
} else {
F_34 ( NULL , 0 ) ;
F_35 ( V_28 , F_36 ( 10 )
| V_29
| V_30 ) ;
}
}
