static int T_1 F_1 ( void )
{
return F_2 ( V_1 ,
F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
if ( F_5 () ) {
V_2 . V_3 &= ~ V_4 ;
V_5 . V_3 &= ~ V_4 ;
}
F_6 ( V_6 ,
F_3 ( V_6 ) ) ;
}
void T_1 F_7 ( void )
{
F_8 ( 0xff000000 , V_7 ) ;
F_8 ( 0xc0000000 , V_8 ) ;
F_8 ( 0xfffefffe , V_9 ) ;
F_8 ( F_9 ( V_10 ) & ~ 0x00c00000 , V_10 ) ;
F_8 ( F_9 ( V_10 ) | 0x00200000 , V_10 ) ;
F_10 ( & V_11 ) ;
}
void T_1 F_11 ( int V_12 )
{
switch ( V_12 ) {
case V_13 :
F_8 ( F_9 ( V_10 ) | 0x00c00000 , V_10 ) ;
F_10 ( & V_14 ) ;
break;
case V_15 :
F_8 ( 0x40000000 , V_16 ) ;
F_8 ( 0x0000fffe , V_17 ) ;
break;
case V_18 :
F_8 ( 0x80000000 , V_16 ) ;
F_8 ( 0xfffe0000 , V_17 ) ;
break;
case V_19 :
F_8 ( 0x40000000 , V_16 ) ;
F_10 ( & V_20 ) ;
break;
case V_21 :
F_8 ( 0x80000000 , V_16 ) ;
F_10 ( & V_22 ) ;
break;
default:
F_12 () ;
}
}
