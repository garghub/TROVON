static void T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
F_3 ( NULL , V_2 ,
V_3 , NULL ) ;
}
static void T_1 F_4 ( void )
{
int V_4 ;
V_4 = F_5 ( true , true ) ;
if ( V_4 )
F_6 ( L_1 , V_4 ) ;
}
static void T_1 F_7 ( void )
{
int V_4 ;
V_4 = F_8 () ;
if ( V_4 ) {
F_6 ( L_2 , V_4 ) ;
return;
}
V_4 = F_9 () ;
if ( V_4 )
F_6 ( L_3 , V_4 ) ;
}
static void T_1 F_10 ( void )
{
F_11 () ;
}
static void T_1 F_12 ( void )
{
int V_5 ;
F_13 () ;
for ( V_5 = 0 ; V_5 < F_14 ( V_6 ) ; V_5 ++ ) {
if ( F_15 ( V_6 [ V_5 ] . V_7 ) ) {
V_6 [ V_5 ] . F_16 () ;
break;
}
}
}
