static void T_1 F_1 ( void )
{
int V_1 ;
V_1 = 0x4 ;
F_2 ( V_2 L_1 ,
V_1 ) ;
switch ( V_1 ) {
case 0x4 :
V_3 . V_4 = & V_5 ;
break;
case 0x6 :
V_3 . V_4 = & V_6 ;
break;
default:
F_2 ( V_2 L_2 ,
V_1 ) ;
V_3 . V_4 = & V_5 ;
}
}
static void T_1 F_3 ( void )
{
F_4 ( NULL ) ;
F_5 ( NULL ) ;
F_6 ( NULL ) ;
F_1 () ;
F_7 ( V_7 , F_8 ( V_7 ) ) ;
}
