static void F_1 ( const char * V_1 , unsigned V_2 )
{
while ( V_2 -- > 0 ) {
if ( * V_1 == '\n' )
F_2 ( '\r' ) ;
F_2 ( * V_1 ) ;
V_1 ++ ;
}
}
static void F_3 ( struct V_3 * V_4 , const char * V_1 , unsigned V_2 )
{
F_1 ( V_1 , V_2 ) ;
}
static int T_1 F_4 ( char * V_5 )
{
V_6 = & V_7 ;
F_5 ( & V_7 ) ;
return 0 ;
}
