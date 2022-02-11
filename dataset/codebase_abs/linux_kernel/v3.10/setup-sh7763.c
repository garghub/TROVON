static int T_1 F_1 ( void )
{
return F_2 ( V_1 ,
F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
F_5 ( V_2 ,
F_3 ( V_2 ) ) ;
}
void T_1 F_6 ( void )
{
F_7 ( 0xff000000 , V_3 ) ;
F_7 ( 0xc0000000 , V_4 ) ;
F_7 ( 0xfffefffe , V_5 ) ;
F_8 ( & V_6 ) ;
}
void T_1 F_9 ( int V_7 )
{
switch ( V_7 ) {
case V_8 :
F_7 ( F_10 ( V_9 ) | 0x00c00000 , V_9 ) ;
F_8 ( & V_10 ) ;
break;
case V_11 :
F_7 ( 0x40000000 , V_12 ) ;
F_7 ( 0x0000fffe , V_13 ) ;
break;
case V_14 :
F_7 ( 0x80000000 , V_12 ) ;
F_7 ( 0xfffe0000 , V_13 ) ;
break;
case V_15 :
F_7 ( 0x40000000 , V_12 ) ;
F_8 ( & V_16 ) ;
break;
case V_17 :
F_7 ( 0x80000000 , V_12 ) ;
F_8 ( & V_18 ) ;
break;
default:
F_11 () ;
}
}
