static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
int V_5 ;
V_6 [ 0 ] . V_7 = V_3 + 0 ;
F_2 ( V_6 ) ;
V_5 = F_3 ( V_8 , V_9 ,
L_1 ) ;
if ( V_5 )
F_4 ( L_2 ,
V_8 ) ;
return V_5 ;
}
static void F_5 ( int V_10 )
{
F_6 ( V_11 , V_10 ) ;
}
static int T_1 F_7 ( void )
{
F_8 ( & V_12 ,
V_13 | V_14 |
V_15 | V_16 ,
V_17 | V_18 ) ;
if ( F_9 () ) {
struct V_19 * V_20 ;
V_20 = V_12 . V_21 -> V_22 ;
V_20 -> V_23 = 3 ;
V_20 -> V_24 = 1 ;
V_20 -> V_25 = F_5 ;
}
F_10 ( 1 , 2400 , L_3 , V_26 , & V_12 ) ;
F_11 ( 2 , 400 , NULL , 0 ) ;
F_11 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void F_12 ( void )
{
F_13 ( L_4 ,
V_27 | V_28 ) ;
}
void T_1 F_14 ( void )
{
if ( F_15 ( & V_29 ) )
F_4 ( L_5 ) ;
F_7 () ;
F_16 ( & V_30 ) ;
F_17 ( NULL ) ;
F_12 () ;
F_18 () ;
}
