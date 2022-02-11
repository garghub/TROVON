static void T_1 F_1 ( void )
{
F_2 ( NULL , V_1 ,
V_2 , NULL ) ;
}
static void T_1 F_3 ( void )
{
#ifdef F_4
int V_3 ;
V_3 = F_5 ( true , true ) ;
if ( V_3 )
F_6 ( L_1 , V_3 ) ;
#endif
}
static void T_1 F_7 ( void )
{
#ifdef F_4
int V_3 ;
V_3 = F_8 () ;
if ( V_3 )
F_6 ( L_2 , V_3 ) ;
#endif
}
static void T_1 F_9 ( void )
{
F_10 () ;
}
static void T_1 F_11 ( void )
{
int V_4 ;
F_12 () ;
for ( V_4 = 0 ; V_4 < F_13 ( V_5 ) ; V_4 ++ ) {
if ( F_14 ( V_5 [ V_4 ] . V_6 ) ) {
V_5 [ V_4 ] . F_15 () ;
break;
}
}
}
