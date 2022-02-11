static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
F_3 ( ~ 0 , V_2 ) ;
F_3 ( 0x7 , V_3 ) ;
F_4 () ;
F_3 ( V_1 , V_2 ) ;
}
static int F_5 ( T_2 V_4 )
{
switch ( V_4 ) {
case V_5 :
F_1 () ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_6 ( T_2 V_4 )
{
return V_4 == V_5 ;
}
int T_3 F_7 ( void )
{
V_3 = F_8 ( V_7 , 4 ) ;
V_2 = F_8 ( V_8 , 4 ) ;
F_9 ( & V_9 ) ;
return 0 ;
}
