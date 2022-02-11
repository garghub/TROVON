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
T_1 void F_4 ( const char * V_5 , ... )
{
char V_6 [ 512 ] ;
int V_2 ;
T_2 V_7 ;
va_start ( V_7 , V_5 ) ;
V_2 = F_5 ( V_6 , sizeof( V_6 ) , V_5 , V_7 ) ;
F_1 ( V_6 , V_2 ) ;
va_end ( V_7 ) ;
}
static int T_3 F_6 ( char * V_6 )
{
F_7 ( & V_8 ) ;
return 0 ;
}
