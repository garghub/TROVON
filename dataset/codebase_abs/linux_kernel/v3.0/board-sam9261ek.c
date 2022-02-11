static void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( 0 , 0 , 0 ) ;
F_5 ( 0 ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( NULL ) ;
}
static void T_1 F_8 ( void )
{
F_9 ( 2 , & V_3 ) ;
F_10 ( V_4 , 0 ) ;
F_11 ( V_5 , 0 ) ;
F_12 ( & V_6 ) ;
}
static void T_1 F_8 ( void ) {}
static struct V_7 * T_1 F_13 ( int V_8 , int * V_9 )
{
* V_9 = F_14 ( V_10 ) ;
return V_10 ;
}
static void T_1 F_15 ( void )
{
V_11 . V_12 = F_16 () ;
if ( V_11 . V_12 )
V_13 . V_14 |= V_15 ;
else
V_13 . V_14 |= V_16 ;
F_9 ( 3 , & V_13 ) ;
F_17 ( & V_11 ) ;
}
static int F_18 ( void )
{
return ! F_19 ( V_17 ) ;
}
static void T_1 F_20 ( void )
{
F_21 ( V_17 , 1 ) ;
F_11 ( V_18 , 1 ) ;
}
static void T_1 F_20 ( void ) {}
static void T_1 F_22 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_21 * V_23 ;
V_22 = F_23 ( NULL , L_1 ) ;
V_23 = F_23 ( NULL , L_2 ) ;
F_21 ( V_24 , 0 ) ;
F_24 ( V_22 , V_23 ) ;
F_25 ( V_23 ) ;
V_20 -> V_25 = V_22 ;
}
static void T_1 F_22 ( struct V_19 * V_20 ) {}
static void F_26 ( int V_26 )
{
if ( V_26 ) {
F_27 ( V_27 , 0 ) ;
F_27 ( V_28 , 0 ) ;
} else {
F_27 ( V_27 , 1 ) ;
F_27 ( V_28 , 1 ) ;
}
}
static void F_28 ( int V_26 )
{
if ( V_26 )
F_27 ( V_29 , 0 ) ;
else
F_27 ( V_29 , 1 ) ;
}
static void T_1 F_29 ( void )
{
F_11 ( V_30 , 1 ) ;
F_30 ( V_30 , 1 ) ;
F_11 ( V_31 , 1 ) ;
F_30 ( V_31 , 1 ) ;
F_11 ( V_32 , 1 ) ;
F_30 ( V_32 , 1 ) ;
F_11 ( V_33 , 1 ) ;
F_30 ( V_33 , 1 ) ;
F_12 ( & V_34 ) ;
}
static void T_1 F_29 ( void ) {}
static void T_1 F_31 ( void )
{
F_32 () ;
F_33 ( & V_35 ) ;
F_34 ( & V_36 ) ;
F_35 ( NULL , 0 ) ;
F_15 () ;
F_8 () ;
#if F_36 ( V_37 ) || F_36 ( V_38 )
F_37 ( V_39 , F_14 ( V_39 ) ) ;
F_20 () ;
F_22 ( & V_40 ) ;
F_38 ( V_41 , V_42 ) ;
#else
F_39 ( 0 , & V_43 ) ;
#endif
F_40 ( & V_44 ) ;
F_29 () ;
F_41 ( V_45 , F_14 ( V_45 ) ) ;
}
