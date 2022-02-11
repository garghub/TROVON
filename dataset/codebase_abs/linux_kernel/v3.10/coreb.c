static long
F_1 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
int V_4 = 0 ;
switch ( V_2 ) {
case V_5 :
F_2 ( F_3 () & ~ 0x0020 ) ;
break;
case V_6 :
F_2 ( F_3 () | 0x0020 ) ;
F_4 ( F_5 () | 0x0080 ) ;
break;
case V_7 :
F_4 ( F_5 () | 0x0080 ) ;
break;
default:
V_4 = - V_8 ;
break;
}
F_6 () ;
return V_4 ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_9 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_9 ) ;
}
