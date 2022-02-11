static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
int V_5 ;
V_6 [ 0 ] . V_7 = V_3 + 0 ;
F_2 ( V_6 ) ;
V_8 . V_2 = V_6 [ 0 ] . V_2 ;
V_9 . V_2 = V_6 [ 0 ] . V_2 ;
V_10 . V_2 = V_6 [ 1 ] . V_2 ;
V_5 = F_3 ( V_11 , V_12 ,
L_1 ) ;
if ( V_5 )
F_4 ( L_2 ,
V_11 ) ;
return V_5 ;
}
static void F_5 ( int V_13 )
{
F_6 ( V_14 , V_13 ) ;
}
static int T_1 F_7 ( void )
{
if ( F_8 () ) {
V_15 . V_16 = 3 ;
V_15 . V_17 = 1 ;
V_15 . V_18 = F_5 ;
}
F_9 ( 1 , 2400 , L_3 , V_19 , & V_20 ) ;
F_10 ( 2 , 400 , NULL , 0 ) ;
F_10 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void F_11 ( void )
{
F_12 ( L_4 ,
V_21 | V_22 ) ;
}
void T_1 F_13 ( void )
{
if ( F_14 ( & V_23 ) )
F_4 ( L_5 ) ;
F_7 () ;
F_15 ( & V_24 ) ;
F_16 ( NULL ) ;
F_11 () ;
F_17 () ;
}
