static void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( 0 , 0 , 0 ) ;
F_5 ( 0 ) ;
}
static void T_1 F_6 ( void )
{
struct V_3 * V_4 = & V_5 [ 2 ] ;
F_7 ( 0 , 2 , & V_6 ) ;
F_8 ( V_7 , 0 ) ;
F_9 ( V_8 , 0 ) ;
V_4 -> V_9 = V_4 -> V_10 = F_10 ( V_8 ) ;
F_11 ( & V_11 ) ;
}
static void T_1 F_6 ( void ) {}
static void T_1 F_12 ( void )
{
V_12 . V_13 = F_13 () ;
if ( V_12 . V_13 )
V_14 . V_15 |= V_16 ;
else
V_14 . V_15 |= V_17 ;
F_7 ( 0 , 3 , & V_14 ) ;
F_14 ( & V_12 ) ;
}
static int F_15 ( void )
{
return ! F_16 ( V_18 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( V_18 , 1 ) ;
F_9 ( V_19 , 1 ) ;
}
static void T_1 F_17 ( void ) {}
static void T_1 F_19 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_22 * V_24 ;
V_23 = F_20 ( NULL , L_1 ) ;
V_24 = F_20 ( NULL , L_2 ) ;
F_18 ( V_25 , 0 ) ;
F_21 ( V_23 , V_24 ) ;
F_22 ( V_24 ) ;
V_21 -> V_26 = V_23 ;
}
static void T_1 F_19 ( struct V_20 * V_21 ) {}
static void F_23 ( int V_27 )
{
if ( V_27 ) {
F_24 ( V_28 , 0 ) ;
F_24 ( V_29 , 0 ) ;
} else {
F_24 ( V_28 , 1 ) ;
F_24 ( V_29 , 1 ) ;
}
}
static void F_25 ( int V_27 )
{
if ( V_27 )
F_24 ( V_30 , 0 ) ;
else
F_24 ( V_30 , 1 ) ;
}
static void T_1 F_26 ( void )
{
F_9 ( V_31 , 1 ) ;
F_27 ( V_31 , 1 ) ;
F_9 ( V_32 , 1 ) ;
F_27 ( V_32 , 1 ) ;
F_9 ( V_33 , 1 ) ;
F_27 ( V_33 , 1 ) ;
F_9 ( V_34 , 1 ) ;
F_27 ( V_34 , 1 ) ;
F_11 ( & V_35 ) ;
}
static void T_1 F_26 ( void ) {}
static void T_1 F_28 ( void )
{
F_29 () ;
F_30 ( & V_36 ) ;
F_31 ( & V_37 ) ;
F_32 ( NULL , 0 ) ;
F_12 () ;
F_6 () ;
#if F_33 ( V_38 ) || F_33 ( V_39 )
F_34 ( V_40 , F_35 ( V_40 ) ) ;
F_17 () ;
F_19 ( & V_41 ) ;
F_36 ( V_42 , V_43 ) ;
#else
F_37 ( 0 , & V_44 ) ;
#endif
F_38 ( & V_45 ) ;
F_26 () ;
F_39 ( V_46 , F_35 ( V_46 ) ) ;
}
