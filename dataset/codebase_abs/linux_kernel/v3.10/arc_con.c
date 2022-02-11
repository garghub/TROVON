static void F_1 ( struct V_1 * V_2 , const char * V_3 ,
unsigned V_4 )
{
while ( V_4 -- ) {
if ( * V_3 == '\n' )
F_2 ( '\r' ) ;
F_2 ( * V_3 ++ ) ;
}
}
static int F_3 ( struct V_1 * V_2 , char * V_5 )
{
return ! ( V_6 & V_7 ) ;
}
static int T_1 F_4 ( void )
{
F_5 ( & V_8 ) ;
return 0 ;
}
