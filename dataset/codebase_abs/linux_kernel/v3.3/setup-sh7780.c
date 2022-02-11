static int T_1 F_1 ( void )
{
return F_2 ( V_1 ,
F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
if ( F_5 () ) {
V_2 . V_3 &= ~ V_4 ;
V_2 . V_5 = V_6 ;
V_7 . V_3 &= ~ V_4 ;
V_7 . V_5 = V_6 ;
}
F_6 ( V_8 ,
F_3 ( V_8 ) ) ;
}
void T_1 F_7 ( void )
{
F_8 ( 0xff000000 , V_9 ) ;
F_8 ( 0xc0000000 , V_10 ) ;
F_8 ( 0xfffefffe , V_11 ) ;
F_8 ( F_9 ( V_12 ) & ~ 0x00c00000 , V_12 ) ;
F_8 ( F_9 ( V_12 ) | 0x00200000 , V_12 ) ;
F_10 ( & V_13 ) ;
}
void T_1 F_11 ( int V_14 )
{
switch ( V_14 ) {
case V_15 :
F_8 ( F_9 ( V_12 ) | 0x00c00000 , V_12 ) ;
F_10 ( & V_16 ) ;
break;
case V_17 :
F_8 ( 0x40000000 , V_18 ) ;
F_8 ( 0x0000fffe , V_19 ) ;
break;
case V_20 :
F_8 ( 0x80000000 , V_18 ) ;
F_8 ( 0xfffe0000 , V_19 ) ;
break;
case V_21 :
F_8 ( 0x40000000 , V_18 ) ;
F_10 ( & V_22 ) ;
break;
case V_23 :
F_8 ( 0x80000000 , V_18 ) ;
F_10 ( & V_24 ) ;
break;
default:
F_12 () ;
}
}
