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
F_8 ( L_2 , NULL , L_3 , NULL ) ;
}
static int F_9 ( struct V_8 * V_9 , int V_10 , int V_11 ,
int V_12 )
{
F_3 ( V_13 , V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 , int V_10 )
{
return F_11 ( V_14 ) ;
}
static void T_1 F_12 ( void )
{
int V_15 ;
V_15 = F_13 ( V_13 , L_4 ) ;
if ( V_15 < 0 )
return;
F_14 ( V_13 , 0 ) ;
V_15 = F_13 ( V_14 , L_5 ) ;
if ( V_15 < 0 ) {
F_15 ( V_13 ) ;
return;
}
F_16 ( V_14 ) ;
V_16 [ 1 ] = & V_17 ;
F_17 ( V_16 , V_18 ) ;
}
static inline void F_12 ( void )
{
}
static void T_1 F_18 ( void )
{
F_19 ( ( F_20 ( 0xfffb5008 ) & ~ 2 ) , 0xfffb5008 ) ;
F_19 ( ( F_20 ( 0xfffb5004 ) & ~ 2 ) , 0xfffb5004 ) ;
F_21 ( V_19 , F_22 ( V_19 ) ) ;
V_20 [ 1 ] . V_21 = F_23 ( 15 ) ;
F_24 ( V_20 ,
F_22 ( V_20 ) ) ;
F_25 () ;
F_26 ( 1 , 100 , NULL , 0 ) ;
F_7 () ;
F_5 () ;
F_27 ( & V_22 ) ;
F_12 () ;
}
