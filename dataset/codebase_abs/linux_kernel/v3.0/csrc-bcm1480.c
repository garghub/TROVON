static T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) F_2 ( F_3 ( V_3 ) ) ;
}
void T_2 F_4 ( void )
{
struct V_1 * V_2 = & V_4 ;
unsigned int V_5 ;
unsigned long V_6 ;
V_5 = F_5 ( F_2 ( F_3 ( V_7 ) ) ) ;
V_6 = ( ( V_5 >> 1 ) * 50000000 ) + ( ( V_5 & 1 ) * 25000000 ) ;
F_6 ( V_2 , V_6 ) ;
}
