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
static void T_1 F_5 ( void )
{
F_6 ( NULL ) ;
}
static void T_1 F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_11 * V_13 ;
V_12 = F_8 ( NULL , L_1 ) ;
V_13 = F_8 ( NULL , L_2 ) ;
F_9 ( V_14 , 0 ) ;
F_10 ( V_12 , V_13 ) ;
F_11 ( V_13 ) ;
V_10 -> V_15 = V_12 ;
}
static void T_1 F_7 ( struct V_9 * V_10 ) {}
static struct V_16 * T_1 F_12 ( int V_17 , int * V_18 )
{
* V_18 = F_13 ( V_19 ) ;
return V_19 ;
}
static void T_1 F_14 ( void )
{
V_20 . V_21 = F_15 () ;
if ( V_20 . V_21 )
V_22 . V_23 |= V_24 ;
else
V_22 . V_23 |= V_25 ;
F_16 ( 3 , & V_22 ) ;
F_17 ( & V_20 ) ;
}
static void T_1 F_18 ( void )
{
F_19 ( V_26 , 1 ) ;
F_20 ( V_26 , 1 ) ;
F_19 ( V_27 , 1 ) ;
F_20 ( V_27 , 1 ) ;
F_21 ( & V_28 ) ;
}
static void T_1 F_18 ( void ) {}
static void T_1 F_22 ( void )
{
F_23 () ;
F_24 ( & V_29 ) ;
F_25 ( & V_30 ) ;
F_26 ( V_31 , F_13 ( V_31 ) ) ;
F_14 () ;
F_27 ( & V_32 ) ;
F_28 ( 0 , & V_33 ) ;
F_29 ( V_34 , F_13 ( V_34 ) ) ;
F_7 ( & V_35 ) ;
F_30 ( V_36 , V_37 ) ;
F_31 ( V_38 , F_13 ( V_38 ) ) ;
F_18 () ;
}
