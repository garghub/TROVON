void F_1 ( const char * V_1 )
{
F_2 ( V_1 ) ;
}
struct V_2 * F_3 ( const char * V_1 )
{
struct V_2 * V_3 = F_4 ( V_1 ) ;
if ( V_3 == NULL ) {
F_1 ( V_1 ) ;
V_3 = F_4 ( V_1 ) ;
}
return V_3 ;
}
