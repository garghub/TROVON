static void T_1 F_1 ( void )
{
F_2 ( ( F_3 ( 0xfffb5008 ) & ~ 2 ) , 0xfffb5008 ) ;
F_2 ( ( F_3 ( 0xfffb5004 ) & ~ 2 ) , 0xfffb5004 ) ;
F_4 () ;
F_5 () ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != - 1 ) {
F_7 ( V_4 L_1 ) ;
F_8 ( V_2 -> V_3 , 0 ) ;
F_9 ( 120 ) ;
}
}
static void T_1 F_10 ( void )
{
const struct V_5 * V_6 ;
V_6 = F_11 ( V_7 , struct V_5 ) ;
if ( V_6 != NULL ) {
V_8 . V_3 = V_6 -> V_3 ;
V_8 . V_9 = V_6 -> V_9 ;
}
}
static void T_1 F_12 ( void )
{
if ( F_13 ( V_10 , L_2 ) < 0 )
F_7 ( V_11 L_3 ) ;
}
static int F_14 ( void )
{
return ! F_15 ( V_10 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( L_4 , NULL , L_5 , NULL ) ;
F_18 ( & V_12 ) ;
}
static int F_19 ( struct V_13 * V_14 , int V_15 , int V_16 ,
int V_17 )
{
F_8 ( V_18 , V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 , int V_15 )
{
return F_15 ( V_19 ) ;
}
static void T_1 F_21 ( void )
{
int V_20 ;
V_20 = F_13 ( V_18 , L_6 ) ;
if ( V_20 < 0 )
return;
F_22 ( V_18 , 0 ) ;
V_20 = F_13 ( V_19 , L_7 ) ;
if ( V_20 < 0 ) {
F_23 ( V_18 ) ;
return;
}
F_24 ( V_19 ) ;
V_21 [ 1 ] = & V_22 ;
F_25 ( V_21 , V_23 ) ;
}
static inline void F_21 ( void )
{
}
static void T_1 F_26 ( void )
{
F_27 ( V_24 , F_28 ( V_24 ) ) ;
F_29 ( V_25 ,
F_28 ( V_25 ) ) ;
F_30 () ;
F_31 ( 1 , 100 , NULL , 0 ) ;
F_16 () ;
F_12 () ;
F_10 () ;
F_32 ( & V_26 ) ;
F_21 () ;
}
static void T_1 F_33 ( void )
{
F_34 () ;
}
