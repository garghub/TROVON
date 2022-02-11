enum V_1 F_1 ( void )
{
enum V_1 V_2 = V_3 ;
V_2 = F_2 ( V_4 ) ;
if ( V_2 == V_3 )
V_2 = F_2 ( V_5 ) ;
if ( V_2 == V_3 )
V_2 = F_2 ( V_6 ) ;
if ( V_2 != V_3 )
F_3 () ;
return V_2 ;
}
void F_3 ( void )
{
F_4 ( V_6 ) ;
F_4 ( V_5 ) ;
F_4 ( V_4 ) ;
}
