int F_1 ( void )
{
V_1 = F_2 ( V_2 , 1 ) ;
if ( V_1 < 0 )
return 1 ;
V_3 = F_3 ( V_2 ) ;
return 0 ;
}
void F_4 ( void )
{
if ( V_1 >= 0 ) {
F_2 ( V_1 , 0 ) ;
F_3 ( V_3 ) ;
}
}
