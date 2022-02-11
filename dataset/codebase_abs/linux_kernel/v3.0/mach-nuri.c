static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_2 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 = F_6 ( 5 ) ;
F_7 ( V_7 , L_1 ) ;
F_8 ( V_7 , V_6 ) ;
F_9 ( V_7 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
int V_10 , V_7 = F_11 ( 3 ) ;
V_10 = F_7 ( V_7 , L_2 ) ;
if ( ! V_10 )
F_8 ( V_7 , 0 ) ;
return V_10 ;
}
static int F_12 ( struct V_8 * V_9 , int V_11 )
{
if ( V_11 < 1 )
V_11 = 0 ;
F_13 ( F_11 ( 3 ) , 1 ) ;
return V_11 ;
}
static void F_14 ( struct V_8 * V_9 )
{
F_9 ( F_11 ( 3 ) ) ;
}
static void T_1 F_15 ( void )
{
int V_7 ;
V_7 = F_16 ( 4 ) ;
F_7 ( V_7 , L_3 ) ;
F_17 ( V_7 , F_18 ( 0xf ) ) ;
F_19 ( V_7 , V_12 ) ;
}
static void T_1 F_20 ( void )
{
struct V_13 * V_14 = & V_15 ;
F_21 ( V_14 ) ;
}
static void T_1 F_22 ( void )
{
F_23 ( NULL , 0 , V_16 ) ;
F_24 ( 24000000 ) ;
F_25 ( V_17 , F_26 ( V_17 ) ) ;
}
static void T_1 F_27 ( void )
{
F_1 () ;
F_15 () ;
F_28 ( 1 , V_18 , F_26 ( V_18 ) ) ;
F_29 ( & V_19 ) ;
F_28 ( 3 , V_20 , F_26 ( V_20 ) ) ;
F_28 ( 5 , V_21 , F_26 ( V_21 ) ) ;
F_20 () ;
V_22 . V_23 = 24000000 ;
F_30 ( V_24 , F_26 ( V_24 ) ) ;
}
