static void T_1 F_1 ( void )
{
F_2 ( 18432000 ) ;
F_3 ( 0 , 0 , 0 ) ;
F_3 ( V_1 , 1 , V_2 | V_3
| V_4 | V_5 | V_6
| V_7 ) ;
F_3 ( V_8 , 2 , V_2 | V_3 ) ;
F_4 ( 0 ) ;
}
static void T_1 F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_11 * V_13 ;
V_12 = F_6 ( NULL , L_1 ) ;
V_13 = F_6 ( NULL , L_2 ) ;
F_7 ( V_14 , 0 ) ;
F_8 ( V_12 , V_13 ) ;
F_9 ( V_13 ) ;
V_10 -> V_15 = V_12 ;
}
static void T_1 F_5 ( struct V_9 * V_10 ) {}
static struct V_16 * T_1 F_10 ( int V_17 , int * V_18 )
{
* V_18 = F_11 ( V_19 ) ;
return V_19 ;
}
static void T_1 F_12 ( void )
{
V_20 . V_21 = F_13 () ;
if ( V_20 . V_21 )
V_22 . V_23 |= V_24 ;
else
V_22 . V_23 |= V_25 ;
F_14 ( 3 , & V_22 ) ;
F_15 ( & V_20 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_26 , 1 ) ;
F_18 ( V_26 , 1 ) ;
F_17 ( V_27 , 1 ) ;
F_18 ( V_27 , 1 ) ;
F_19 ( & V_28 ) ;
}
static void T_1 F_16 ( void ) {}
static void T_1 F_20 ( void )
{
F_21 () ;
F_22 ( & V_29 ) ;
F_23 ( & V_30 ) ;
F_24 ( V_31 , F_11 ( V_31 ) ) ;
F_12 () ;
F_25 ( & V_32 ) ;
F_26 ( 0 , & V_33 ) ;
F_27 ( V_34 , F_11 ( V_34 ) ) ;
F_5 ( & V_35 ) ;
F_28 ( V_36 , V_37 ) ;
F_29 ( V_38 , F_11 ( V_38 ) ) ;
F_16 () ;
}
