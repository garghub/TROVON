static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != - 1 ) {
F_2 ( V_4 L_1 ) ;
F_3 ( V_2 -> V_3 , 0 ) ;
F_4 ( 120 ) ;
}
}
static void T_1 F_5 ( void )
{
V_5 . V_3 = 13 ;
V_5 . V_6 = 16 ;
F_6 ( & V_7 ) ;
}
static void T_1 F_7 ( void )
{
if ( F_8 ( V_8 , L_2 ) < 0 )
F_2 ( V_9 L_3 ) ;
}
static int F_9 ( void )
{
return ! F_10 ( V_8 ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( L_4 , NULL , L_5 , NULL ) ;
}
static int F_13 ( struct V_10 * V_11 , int V_12 , int V_13 ,
int V_14 )
{
F_3 ( V_15 , V_13 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 , int V_12 )
{
return F_10 ( V_16 ) ;
}
static void T_1 F_15 ( void )
{
int V_17 ;
V_17 = F_8 ( V_15 , L_6 ) ;
if ( V_17 < 0 )
return;
F_16 ( V_15 , 0 ) ;
V_17 = F_8 ( V_16 , L_7 ) ;
if ( V_17 < 0 ) {
F_17 ( V_15 ) ;
return;
}
F_18 ( V_16 ) ;
V_18 [ 1 ] = & V_19 ;
F_19 ( V_18 , V_20 ) ;
}
static inline void F_15 ( void )
{
}
static void T_1 F_20 ( void )
{
F_21 ( ( F_22 ( 0xfffb5008 ) & ~ 2 ) , 0xfffb5008 ) ;
F_21 ( ( F_22 ( 0xfffb5004 ) & ~ 2 ) , 0xfffb5004 ) ;
F_23 ( V_21 , F_24 ( V_21 ) ) ;
V_22 [ 1 ] . V_23 = F_25 ( 15 ) ;
F_26 ( V_22 ,
F_24 ( V_22 ) ) ;
F_27 () ;
F_28 ( 1 , 100 , NULL , 0 ) ;
F_11 () ;
F_7 () ;
F_5 () ;
F_29 ( & V_24 ) ;
F_15 () ;
}
