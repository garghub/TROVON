static void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( 0 , 0 , 0 ) ;
F_5 ( 0 ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( 2 , & V_3 ) ;
F_8 ( V_4 , 0 ) ;
F_9 ( V_5 , 0 ) ;
F_10 ( & V_6 ) ;
}
static void T_1 F_6 ( void ) {}
static struct V_7 * T_1 F_11 ( int V_8 , int * V_9 )
{
* V_9 = F_12 ( V_10 ) ;
return V_10 ;
}
static void T_1 F_13 ( void )
{
V_11 . V_12 = F_14 () ;
if ( V_11 . V_12 )
V_13 . V_14 |= V_15 ;
else
V_13 . V_14 |= V_16 ;
F_7 ( 3 , & V_13 ) ;
F_15 ( & V_11 ) ;
}
static int F_16 ( void )
{
return ! F_17 ( V_17 ) ;
}
static void T_1 F_18 ( void )
{
F_19 ( V_17 , 1 ) ;
F_9 ( V_18 , 1 ) ;
}
static void T_1 F_18 ( void ) {}
static void T_1 F_20 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_21 * V_23 ;
V_22 = F_21 ( NULL , L_1 ) ;
V_23 = F_21 ( NULL , L_2 ) ;
F_19 ( V_24 , 0 ) ;
F_22 ( V_22 , V_23 ) ;
F_23 ( V_23 ) ;
V_20 -> V_25 = V_22 ;
}
static void T_1 F_20 ( struct V_19 * V_20 ) {}
static void F_24 ( int V_26 )
{
if ( V_26 ) {
F_25 ( V_27 , 0 ) ;
F_25 ( V_28 , 0 ) ;
} else {
F_25 ( V_27 , 1 ) ;
F_25 ( V_28 , 1 ) ;
}
}
static void F_26 ( int V_26 )
{
if ( V_26 )
F_25 ( V_29 , 0 ) ;
else
F_25 ( V_29 , 1 ) ;
}
static void T_1 F_27 ( void )
{
F_9 ( V_30 , 1 ) ;
F_28 ( V_30 , 1 ) ;
F_9 ( V_31 , 1 ) ;
F_28 ( V_31 , 1 ) ;
F_9 ( V_32 , 1 ) ;
F_28 ( V_32 , 1 ) ;
F_9 ( V_33 , 1 ) ;
F_28 ( V_33 , 1 ) ;
F_10 ( & V_34 ) ;
}
static void T_1 F_27 ( void ) {}
static void T_1 F_29 ( void )
{
F_30 () ;
F_31 ( & V_35 ) ;
F_32 ( & V_36 ) ;
F_33 ( NULL , 0 ) ;
F_13 () ;
F_6 () ;
#if F_34 ( V_37 ) || F_34 ( V_38 )
F_35 ( V_39 , F_12 ( V_39 ) ) ;
F_18 () ;
F_20 ( & V_40 ) ;
F_36 ( V_41 , V_42 ) ;
#else
F_37 ( 0 , & V_43 ) ;
#endif
F_38 ( & V_44 ) ;
F_27 () ;
F_39 ( V_45 , F_12 ( V_45 ) ) ;
}
