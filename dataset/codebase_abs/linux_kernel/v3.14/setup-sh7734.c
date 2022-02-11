void T_1 F_1 ( void )
{
F_2 ( V_1 ,
F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
F_5 ( 0xF0000000 , V_2 ) ;
F_5 ( 0x80000000 , V_3 ) ;
F_5 ( F_6 ( V_4 ) & ~ 0x00800000 , V_4 ) ;
F_5 ( F_6 ( V_4 ) | 0x00200000 , V_4 ) ;
F_7 ( & V_5 ) ;
}
void T_1 F_8 ( int V_6 )
{
switch ( V_6 ) {
case V_7 :
F_5 ( F_6 ( V_4 ) | 0x00800000 , V_4 ) ;
F_7 ( & V_8 ) ;
break;
case V_9 :
F_5 ( 0x80000000 , V_10 ) ;
F_5 ( 0xf0000000 , V_11 ) ;
break;
case V_12 :
F_5 ( 0x80000000 , V_11 ) ;
F_7 ( & V_13 ) ;
break;
default:
F_9 () ;
}
}
