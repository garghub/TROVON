static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
unsigned long V_2 = F_4 () ;
int V_3 = 0 ;
for ( V_3 = 0 ; V_3 < F_5 ( V_4 ) ; V_3 ++ ) {
if ( F_6 ( V_2 , V_4 [ V_3 ] ) ) {
F_7 ( V_5 ) ;
return 1 ;
}
}
return 0 ;
}
