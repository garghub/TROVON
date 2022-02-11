static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
static char line [ 1024 ] ;
T_1 V_5 = 0 ;
bool V_6 = false ;
if ( ! F_2 () )
return;
if ( V_7 != NULL )
V_6 = true ;
F_3 () ;
if ( V_6 == true )
return;
printf ( L_1 ) ;
while ( F_4 ( V_2 , true , line , sizeof( line ) , & V_5 ) ) {
line [ V_5 ] = '\0' ;
printf ( L_2 , line ) ;
}
}
int T_2 F_5 ( void )
{
return F_6 ( & V_1 ) ;
}
