static int inline F_1 ( void )
{
return F_2 () || ( V_1 & V_2 ) ;
}
static void T_1 F_3 ( void )
{
F_4 ( 18432000 ) ;
F_5 ( 0 , 0 , 0 ) ;
F_5 ( V_3 , 1 , V_4 | V_5
| V_6 | V_7 | V_8
| V_9 ) ;
F_5 ( V_10 , 2 , V_4 | V_5 ) ;
F_6 ( 0 ) ;
}
static void T_1 F_7 ( void )
{
if ( F_1 () )
V_11 . V_12 = V_13 ;
F_8 ( & V_11 ) ;
}
static void T_1 F_9 ( void )
{
V_14 . V_15 = F_10 () ;
if ( V_14 . V_15 )
V_16 . V_17 |= V_18 ;
else
V_16 . V_17 |= V_19 ;
F_11 ( 3 , & V_16 ) ;
F_12 ( & V_14 ) ;
}
static void T_1 F_13 ( void )
{
#if F_14 ( V_20 ) || F_14 ( V_21 )
if ( F_1 () ) {
V_22 . V_23 [ 0 ] . V_24 = 4 ;
V_22 . V_23 [ 0 ] . V_25 = V_26 ;
}
F_15 ( 0 , & V_22 ) ;
#else
F_16 ( 0 , & V_22 ) ;
#endif
}
static void T_1 F_17 ( void )
{
if ( F_1 () ) {
V_27 [ 0 ] . V_28 = V_29 ;
V_27 [ 1 ] . V_28 = V_30 ;
}
F_18 ( V_27 , F_19 ( V_27 ) ) ;
}
static void T_1 F_20 ( void )
{
F_21 ( V_31 , 1 ) ;
F_22 ( V_31 , 1 ) ;
F_21 ( V_32 , 1 ) ;
F_22 ( V_32 , 1 ) ;
F_23 ( & V_33 ) ;
}
static void T_1 F_20 ( void ) {}
static void T_1 F_24 ( void )
{
F_23 ( & V_34 ) ;
}
static void T_1 F_24 ( void ) {}
static void T_1 F_25 ( void )
{
F_26 () ;
F_27 ( & V_35 ) ;
F_28 ( & V_36 ) ;
F_29 ( V_37 , F_19 ( V_37 ) ) ;
F_9 () ;
F_7 () ;
F_24 () ;
F_13 () ;
F_30 ( V_38 , F_19 ( V_38 ) ) ;
F_17 () ;
F_20 () ;
F_31 ( V_39 , 0 ) ;
F_32 ( V_40 , V_41 ) ;
}
