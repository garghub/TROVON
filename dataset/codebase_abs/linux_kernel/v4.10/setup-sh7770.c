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
F_7 ( F_8 ( V_6 ) & ~ 0x00c00000 , V_6 ) ;
F_7 ( F_8 ( V_6 ) | 0x00200000 , V_6 ) ;
F_9 ( & V_7 ) ;
}
void T_1 F_10 ( int V_8 )
{
switch ( V_8 ) {
case V_9 :
F_7 ( F_8 ( V_6 ) | 0x00c00000 , V_6 ) ;
F_9 ( & V_10 ) ;
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
F_9 ( & V_16 ) ;
break;
case V_17 :
F_7 ( 0x80000000 , V_12 ) ;
F_9 ( & V_18 ) ;
break;
default:
F_11 () ;
}
}
