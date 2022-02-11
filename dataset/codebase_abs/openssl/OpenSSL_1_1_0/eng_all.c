void F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , NULL ) ;
}
void F_4 ( void )
{
static int V_2 = 0 ;
if ( ! V_2 ) {
F_3 ( V_3 , NULL ) ;
F_5 () ;
}
V_2 = 1 ;
}
