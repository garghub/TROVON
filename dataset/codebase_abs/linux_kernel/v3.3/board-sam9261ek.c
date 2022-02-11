static void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( 0 , 0 , 0 ) ;
F_5 ( 0 ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( 0 , 2 , & V_3 ) ;
F_8 ( V_4 , 0 ) ;
F_9 ( V_5 , 0 ) ;
F_10 ( & V_6 ) ;
}
static void T_1 F_6 ( void ) {}
static void T_1 F_11 ( void )
{
V_7 . V_8 = F_12 () ;
if ( V_7 . V_8 )
V_9 . V_10 |= V_11 ;
else
V_9 . V_10 |= V_12 ;
F_7 ( 0 , 3 , & V_9 ) ;
F_13 ( & V_7 ) ;
}
static int F_14 ( void )
{
return ! F_15 ( V_13 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_13 , 1 ) ;
F_9 ( V_14 , 1 ) ;
}
static void T_1 F_16 ( void ) {}
static void T_1 F_18 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_17 * V_19 ;
V_18 = F_19 ( NULL , L_1 ) ;
V_19 = F_19 ( NULL , L_2 ) ;
F_17 ( V_20 , 0 ) ;
F_20 ( V_18 , V_19 ) ;
F_21 ( V_19 ) ;
V_16 -> V_21 = V_18 ;
}
static void T_1 F_18 ( struct V_15 * V_16 ) {}
static void F_22 ( int V_22 )
{
if ( V_22 ) {
F_23 ( V_23 , 0 ) ;
F_23 ( V_24 , 0 ) ;
} else {
F_23 ( V_23 , 1 ) ;
F_23 ( V_24 , 1 ) ;
}
}
static void F_24 ( int V_22 )
{
if ( V_22 )
F_23 ( V_25 , 0 ) ;
else
F_23 ( V_25 , 1 ) ;
}
static void T_1 F_25 ( void )
{
F_9 ( V_26 , 1 ) ;
F_26 ( V_26 , 1 ) ;
F_9 ( V_27 , 1 ) ;
F_26 ( V_27 , 1 ) ;
F_9 ( V_28 , 1 ) ;
F_26 ( V_28 , 1 ) ;
F_9 ( V_29 , 1 ) ;
F_26 ( V_29 , 1 ) ;
F_10 ( & V_30 ) ;
}
static void T_1 F_25 ( void ) {}
static void T_1 F_27 ( void )
{
F_28 () ;
F_29 ( & V_31 ) ;
F_30 ( & V_32 ) ;
F_31 ( NULL , 0 ) ;
F_11 () ;
F_6 () ;
#if F_32 ( V_33 ) || F_32 ( V_34 )
F_33 ( V_35 , F_34 ( V_35 ) ) ;
F_16 () ;
F_18 ( & V_36 ) ;
F_35 ( V_37 , V_38 ) ;
#else
F_36 ( 0 , & V_39 ) ;
#endif
F_37 ( & V_40 ) ;
F_25 () ;
F_38 ( V_41 , F_34 ( V_41 ) ) ;
}
