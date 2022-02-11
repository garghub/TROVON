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
F_8 ( NULL ) ;
}
static void T_1 F_9 ( void )
{
if ( F_1 () )
V_11 . V_12 = V_13 ;
F_10 ( & V_11 ) ;
}
static struct V_14 * T_1 F_11 ( int V_15 , int * V_16 )
{
* V_16 = F_12 ( V_17 ) ;
return V_17 ;
}
static void T_1 F_13 ( void )
{
V_18 . V_19 = F_14 () ;
if ( V_18 . V_19 )
V_20 . V_21 |= V_22 ;
else
V_20 . V_21 |= V_23 ;
F_15 ( 3 , & V_20 ) ;
F_16 ( & V_18 ) ;
}
static void T_1 F_17 ( void )
{
#if F_18 ( V_24 ) || F_18 ( V_25 )
if ( F_1 () ) {
V_26 . V_27 [ 0 ] . V_28 = 4 ;
V_26 . V_27 [ 0 ] . V_29 = V_30 ;
}
F_19 ( 0 , & V_26 ) ;
#else
F_20 ( 0 , & V_26 ) ;
#endif
}
static void T_1 F_21 ( void )
{
if ( F_1 () ) {
V_31 [ 0 ] . V_32 = V_33 ;
V_31 [ 1 ] . V_32 = V_34 ;
}
F_22 ( V_31 , F_12 ( V_31 ) ) ;
}
static void T_1 F_23 ( void )
{
F_24 ( V_35 , 1 ) ;
F_25 ( V_35 , 1 ) ;
F_24 ( V_36 , 1 ) ;
F_25 ( V_36 , 1 ) ;
F_26 ( & V_37 ) ;
}
static void T_1 F_23 ( void ) {}
static void T_1 F_27 ( void )
{
F_26 ( & V_38 ) ;
}
static void T_1 F_27 ( void ) {}
static void T_1 F_28 ( void )
{
F_29 () ;
F_30 ( & V_39 ) ;
F_31 ( & V_40 ) ;
F_32 ( V_41 , F_12 ( V_41 ) ) ;
F_13 () ;
F_9 () ;
F_27 () ;
F_17 () ;
F_33 ( V_42 , F_12 ( V_42 ) ) ;
F_21 () ;
F_23 () ;
F_34 ( V_43 , 0 ) ;
F_35 ( V_44 , V_45 ) ;
}
