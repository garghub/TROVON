static int T_1 F_1 ( void )
{
if ( F_2 () ) {
V_1 [ 0 ] . V_2 = V_3 ;
V_1 [ 0 ] . V_4 = V_3 + 0xff ;
V_1 [ 1 ] . V_2 =
F_3 ( V_5 ) ;
V_1 [ 1 ] . V_4 =
F_3 ( V_5 ) ;
F_4 ( & V_6 ) ;
}
return 0 ;
}
static T_2 F_5 ( struct V_7 * V_8 , unsigned int V_9 )
{
int V_10 = 0 ;
struct V_11 * V_12 ;
V_12 = F_6 ( V_8 , struct V_11 , V_13 ) ;
if ( V_9 == 0 ) {
if ( ! V_14 )
return 0 ;
F_7 ( V_12 -> V_15 , & V_14 ) ;
if ( ! V_14 ) {
V_10 = F_8 ( V_16 ) ;
if ( V_10 )
F_9 ( L_1
L_2 , V_12 -> V_15 , V_10 ) ;
}
return 0 ;
}
if ( ! V_14 ) {
V_10 = F_10 ( V_16 , 2900 ) ;
if ( V_10 )
F_9 ( L_3 ,
V_12 -> V_15 , V_10 ) ;
V_10 = F_11 ( V_16 ) ;
if ( V_10 )
F_9 ( L_4 ,
V_12 -> V_15 , V_10 ) ;
}
F_12 ( V_12 -> V_15 , & V_14 ) ;
return 0 ;
}
static void T_1 F_13 ( void )
{
V_16 = F_14 ( NULL , L_5 ) ;
if ( F_15 ( V_16 ) ) {
F_9 ( L_6 ,
F_16 ( V_16 ) ) ;
return;
}
F_17 ( 1 , & V_17 , 0 , 0 ) ;
}
static void T_1 F_18 ( void )
{
F_19 () ;
}
static void T_1 F_20 ( void )
{
F_21 () ;
F_22 () ;
}
static void T_1 F_23 ( void )
{
V_18 . V_13 . V_19 = & V_20 ;
V_21 . V_13 . V_22 = & V_18 . V_13 ;
V_23 . V_13 . V_22 = & V_18 . V_13 ;
F_24 ( V_24 , F_25 ( V_24 ) ) ;
F_13 () ;
}
static void T_1 F_26 ( void )
{
F_27 () ;
}
