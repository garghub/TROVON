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
static int F_5 ( struct V_7 * V_8 , bool assert )
{
int V_9 ;
if ( assert ) {
V_9 = F_6 ( V_8 , V_10 ) ;
if ( V_9 )
F_7 ( L_1 ) ;
} else {
V_9 = F_6 ( V_8 , V_11 ) ;
if ( V_9 )
F_7 ( L_2 ) ;
}
return V_9 ;
}
static int F_8 ( struct V_7 * V_12 )
{
int V_9 ;
V_9 = F_6 ( V_12 , V_10 ) ;
if ( V_9 ) {
F_7 ( L_3 ) ;
return V_9 ;
}
F_9 ( 10000 , 12000 ) ;
V_9 = F_6 ( V_12 , V_11 ) ;
if ( V_9 )
F_7 ( L_4 ) ;
return V_9 ;
}
static T_2 F_10 ( struct V_13 * V_14 , unsigned int V_15 )
{
int V_16 = 0 ;
struct V_17 * V_18 ;
V_18 = F_11 ( V_14 , struct V_17 , V_19 ) ;
if ( V_15 == 0 ) {
if ( ! V_20 )
return 0 ;
F_12 ( V_18 -> V_21 , & V_20 ) ;
if ( ! V_20 ) {
V_16 = F_13 ( V_22 ) ;
if ( V_16 )
F_7 ( L_5
L_6 , V_18 -> V_21 , V_16 ) ;
}
return 0 ;
}
if ( ! V_20 ) {
V_16 = F_14 ( V_22 , 2900 ) ;
if ( V_16 )
F_7 ( L_7 ,
V_18 -> V_21 , V_16 ) ;
V_16 = F_15 ( V_22 ) ;
if ( V_16 )
F_7 ( L_8 ,
V_18 -> V_21 , V_16 ) ;
}
F_16 ( V_18 -> V_21 , & V_20 ) ;
return 0 ;
}
static void T_1 F_17 ( void )
{
V_22 = F_18 ( NULL , L_9 ) ;
if ( F_19 ( V_22 ) ) {
F_7 ( L_10 ,
F_20 ( V_22 ) ) ;
return;
}
F_21 ( 1 , & V_23 , 0 , 0 ) ;
}
static void T_1 F_22 ( void )
{
F_23 () ;
}
static void T_1 F_24 ( void )
{
F_25 () ;
F_26 () ;
}
static void T_1 F_27 ( void )
{
V_24 . V_19 . V_25 = & V_26 ;
V_27 . V_19 . V_28 = & V_24 . V_19 ;
V_29 . V_19 . V_28 = & V_24 . V_19 ;
F_28 ( V_30 , F_29 ( V_30 ) ) ;
F_17 () ;
}
static void T_1 F_30 ( void )
{
F_31 () ;
}
