static int inline F_1 ( void )
{
return F_2 () || ( V_1 & V_2 ) ;
}
static void T_1 F_3 ( void )
{
F_4 ( 18432000 ) ;
}
static void T_1 F_5 ( void )
{
if ( F_1 () )
V_3 . V_4 = V_5 ;
F_6 ( & V_3 ) ;
}
static void T_1 F_7 ( void )
{
V_6 . V_7 = F_8 () ;
if ( V_6 . V_7 )
V_8 . V_9 |= V_10 ;
else
V_8 . V_9 |= V_11 ;
F_9 ( 0 , 3 , & V_8 ) ;
F_10 ( & V_6 ) ;
}
static void T_1 F_11 ( void )
{
#if F_12 ( V_12 ) || F_12 ( V_13 )
if ( F_1 () ) {
V_14 . V_15 [ 0 ] . V_16 = 4 ;
V_14 . V_15 [ 0 ] . V_17 = V_18 ;
V_14 . V_15 [ 0 ] . V_19 = - 1 ;
}
F_13 ( 0 , & V_14 ) ;
#else
F_14 ( 0 , & V_14 ) ;
#endif
}
static void T_1 F_15 ( void )
{
if ( F_1 () ) {
V_20 [ 0 ] . V_21 = V_22 ;
V_20 [ 1 ] . V_21 = V_23 ;
}
F_16 ( V_20 , F_17 ( V_20 ) ) ;
}
static void T_1 F_18 ( void )
{
F_19 ( V_24 , 1 ) ;
F_20 ( V_24 , 1 ) ;
F_19 ( V_25 , 1 ) ;
F_20 ( V_25 , 1 ) ;
F_21 ( & V_26 ) ;
}
static void T_1 F_18 ( void ) {}
static void T_1 F_22 ( void )
{
F_21 ( & V_27 ) ;
}
static void T_1 F_22 ( void ) {}
static void T_1 F_23 ( void )
{
F_24 ( 0 , 0 , 0 ) ;
F_24 ( V_28 , 1 , V_29 | V_30
| V_31 | V_32 | V_33
| V_34 ) ;
F_24 ( V_35 , 2 , V_29 | V_30 ) ;
F_25 () ;
F_26 ( & V_36 ) ;
F_27 ( & V_37 ) ;
F_28 ( V_38 , F_17 ( V_38 ) ) ;
F_7 () ;
F_5 () ;
F_22 () ;
F_11 () ;
F_29 ( V_39 , F_17 ( V_39 ) ) ;
F_15 () ;
F_18 () ;
F_30 ( & V_40 ) ;
F_31 ( V_41 , 0 ) ;
F_32 ( V_42 , V_43 ) ;
}
