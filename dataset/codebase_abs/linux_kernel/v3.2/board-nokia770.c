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
const struct V_5 * V_6 ;
V_6 = F_6 ( V_7 , struct V_5 ) ;
if ( V_6 != NULL ) {
V_8 . V_3 = V_6 -> V_3 ;
V_8 . V_9 = V_6 -> V_9 ;
}
}
static void T_1 F_7 ( void )
{
if ( F_8 ( V_10 , L_2 ) < 0 )
F_2 ( V_11 L_3 ) ;
}
static int F_9 ( void )
{
return ! F_10 ( V_10 ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( L_4 , NULL , L_5 , NULL ) ;
F_13 ( & V_12 ) ;
}
static int F_14 ( struct V_13 * V_14 , int V_15 , int V_16 ,
int V_17 )
{
F_3 ( V_18 , V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , int V_15 )
{
return F_10 ( V_19 ) ;
}
static void T_1 F_16 ( void )
{
int V_20 ;
V_20 = F_8 ( V_18 , L_6 ) ;
if ( V_20 < 0 )
return;
F_17 ( V_18 , 0 ) ;
V_20 = F_8 ( V_19 , L_7 ) ;
if ( V_20 < 0 ) {
F_18 ( V_18 ) ;
return;
}
F_19 ( V_19 ) ;
V_21 [ 1 ] = & V_22 ;
F_20 ( V_21 , V_23 ) ;
}
static inline void F_16 ( void )
{
}
static void T_1 F_21 ( void )
{
F_22 ( ( F_23 ( 0xfffb5008 ) & ~ 2 ) , 0xfffb5008 ) ;
F_22 ( ( F_23 ( 0xfffb5004 ) & ~ 2 ) , 0xfffb5004 ) ;
F_24 ( V_24 , F_25 ( V_24 ) ) ;
F_26 ( V_25 ,
F_25 ( V_25 ) ) ;
F_27 () ;
F_28 ( 1 , 100 , NULL , 0 ) ;
F_11 () ;
F_7 () ;
F_5 () ;
F_29 ( & V_26 ) ;
F_16 () ;
}
