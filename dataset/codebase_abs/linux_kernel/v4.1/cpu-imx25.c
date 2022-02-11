static int F_1 ( void )
{
T_1 V_1 ;
void T_2 * V_2 ;
struct V_3 * V_4 ;
V_4 = F_2 ( NULL , NULL , L_1 ) ;
V_2 = F_3 ( V_4 , 0 ) ;
F_4 ( ! V_2 ) ;
V_1 = F_5 ( V_2 + V_5 ) ;
F_6 ( V_2 ) ;
switch ( V_1 ) {
case 0x00 :
return V_6 ;
case 0x01 :
return V_7 ;
default:
return V_8 ;
}
}
int F_7 ( void )
{
if ( V_9 == - 1 )
V_9 = F_1 () ;
return V_9 ;
}
