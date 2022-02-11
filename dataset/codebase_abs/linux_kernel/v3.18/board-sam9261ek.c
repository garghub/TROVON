static void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
}
static void T_1 F_3 ( void )
{
struct V_1 * V_2 = & V_3 [ 2 ] ;
F_4 ( 0 , 2 , & V_4 ) ;
F_5 ( V_5 , 0 ) ;
F_6 ( V_6 , 0 ) ;
V_2 -> V_7 = V_2 -> V_8 = F_7 ( V_6 ) ;
F_8 ( & V_9 ) ;
}
static void T_1 F_3 ( void ) {}
static void T_1 F_9 ( void )
{
V_10 . V_11 = F_10 () ;
if ( V_10 . V_11 )
V_12 . V_13 |= V_14 ;
else
V_12 . V_13 |= V_15 ;
F_4 ( 0 , 3 , & V_12 ) ;
F_11 ( & V_10 ) ;
}
static int F_12 ( void )
{
return ! F_13 ( V_16 ) ;
}
static void T_1 F_14 ( void )
{
F_15 ( V_16 , 1 ) ;
F_6 ( V_17 , 1 ) ;
}
static void T_1 F_14 ( void ) {}
static void T_1 F_16 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_20 * V_22 ;
V_21 = F_17 ( NULL , L_1 ) ;
V_22 = F_17 ( NULL , L_2 ) ;
F_15 ( V_23 , 0 ) ;
F_18 ( V_21 , V_22 ) ;
F_19 ( V_22 ) ;
V_19 -> V_24 = V_21 ;
}
static void T_1 F_16 ( struct V_18 * V_19 ) {}
static void F_20 ( struct V_25 * V_26 , int V_27 )
{
if ( V_27 ) {
F_21 ( V_28 , 0 ) ;
F_21 ( V_29 , 0 ) ;
} else {
F_21 ( V_28 , 1 ) ;
F_21 ( V_29 , 1 ) ;
}
}
static void F_22 ( struct V_25 * V_26 , int V_27 )
{
if ( V_27 )
F_21 ( V_30 , 0 ) ;
else
F_21 ( V_30 , 1 ) ;
}
static void T_1 F_23 ( void )
{
F_6 ( V_31 , 1 ) ;
F_24 ( V_31 , 1 ) ;
F_6 ( V_32 , 1 ) ;
F_24 ( V_32 , 1 ) ;
F_6 ( V_33 , 1 ) ;
F_24 ( V_33 , 1 ) ;
F_6 ( V_34 , 1 ) ;
F_24 ( V_34 , 1 ) ;
F_8 ( & V_35 ) ;
}
static void T_1 F_23 ( void ) {}
static void T_1 F_25 ( void )
{
F_26 () ;
F_27 ( 0 , 0 , 0 ) ;
F_28 () ;
if ( F_29 () )
V_36 . V_37 = V_38 ;
F_30 ( & V_39 ) ;
F_31 ( & V_40 ) ;
F_32 ( NULL , 0 ) ;
F_9 () ;
F_3 () ;
#if F_33 ( V_41 ) || F_33 ( V_42 )
F_34 ( V_43 , F_35 ( V_43 ) ) ;
F_14 () ;
F_16 ( & V_44 ) ;
F_36 ( V_45 , V_46 ) ;
#else
F_37 ( 0 , & V_47 ) ;
#endif
F_38 ( & V_36 ) ;
F_23 () ;
F_39 ( V_48 , F_35 ( V_48 ) ) ;
}
