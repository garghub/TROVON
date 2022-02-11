static void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
}
static void T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
V_4 = F_4 ( NULL , L_1 ) ;
V_5 = F_4 ( NULL , L_2 ) ;
F_5 ( V_6 , 0 ) ;
F_6 ( V_4 , V_5 ) ;
F_7 ( V_5 ) ;
V_2 -> V_7 = V_4 ;
}
static void T_1 F_3 ( struct V_1 * V_2 ) {}
static void T_1 F_8 ( void )
{
V_8 . V_9 = F_9 () ;
if ( V_8 . V_9 )
V_10 . V_11 |= V_12 ;
else
V_10 . V_11 |= V_13 ;
F_10 ( 0 , 3 , & V_10 ) ;
F_11 ( & V_8 ) ;
}
static void T_1 F_12 ( void )
{
F_13 ( V_14 , 1 ) ;
F_14 ( V_14 , 1 ) ;
F_13 ( V_15 , 1 ) ;
F_14 ( V_15 , 1 ) ;
F_15 ( & V_16 ) ;
}
static void T_1 F_12 ( void ) {}
static void T_1 F_16 ( void )
{
F_17 () ;
F_18 ( 0 , 0 , 0 ) ;
F_18 ( V_17 , 1 , V_18 | V_19
| V_20 | V_21 | V_22
| V_23 ) ;
F_18 ( V_24 , 2 , V_18 | V_19 ) ;
F_19 () ;
F_20 ( & V_25 ) ;
F_21 ( & V_26 ) ;
F_22 ( V_27 , F_23 ( V_27 ) ) ;
F_8 () ;
F_24 ( & V_28 ) ;
F_25 ( 0 , & V_29 ) ;
F_26 ( V_30 , F_23 ( V_30 ) ) ;
F_3 ( & V_31 ) ;
F_27 ( V_32 , V_33 ) ;
F_28 ( V_34 , F_23 ( V_34 ) ) ;
F_12 () ;
}
