static int F_1 ( T_1 V_1 )
{
T_2 V_2 ;
switch ( V_1 ) {
case V_3 :
V_2 = F_2 ( F_3 ( V_4 ) ) ;
V_2 &= 0xFFFFFFFC ;
F_4 ( V_2 , F_3 ( V_4 ) ) ;
F_5 () ;
break;
default:
return - V_5 ;
}
return 0 ;
}
static int T_3 F_6 ( void )
{
if ( ! F_7 () )
return 0 ;
F_8 ( & V_6 ) ;
return 0 ;
}
