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
if ( F_1 () ) {
V_12 . V_13 [ 0 ] . V_14 = 4 ;
V_12 . V_13 [ 0 ] . V_15 = V_16 ;
V_12 . V_13 [ 0 ] . V_17 = - 1 ;
}
F_12 ( 0 , & V_12 ) ;
}
static void T_1 F_13 ( void )
{
if ( F_1 () ) {
V_18 [ 0 ] . V_19 = V_20 ;
V_18 [ 1 ] . V_19 = V_21 ;
}
F_14 ( V_18 , F_15 ( V_18 ) ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_22 , 1 ) ;
F_18 ( V_22 , 1 ) ;
F_17 ( V_23 , 1 ) ;
F_18 ( V_23 , 1 ) ;
F_19 ( & V_24 ) ;
}
static void T_1 F_16 ( void ) {}
static void T_1 F_20 ( void )
{
F_19 ( & V_25 ) ;
}
static void T_1 F_20 ( void ) {}
static void T_1 F_21 ( void )
{
F_22 ( 0 , 0 , 0 ) ;
F_22 ( V_26 , 1 , V_27 | V_28
| V_29 | V_30 | V_31
| V_32 ) ;
F_22 ( V_33 , 2 , V_27 | V_28 ) ;
F_23 () ;
F_24 ( & V_34 ) ;
F_25 ( & V_35 ) ;
F_26 ( V_36 , F_15 ( V_36 ) ) ;
F_7 () ;
F_5 () ;
F_20 () ;
F_11 () ;
F_27 ( V_37 , F_15 ( V_37 ) ) ;
F_13 () ;
F_16 () ;
F_28 ( & V_38 ) ;
F_29 ( V_39 , 0 ) ;
F_30 ( V_40 , V_41 ) ;
}
