void F_1 ( void )
{
switch ( V_1 ) {
case V_2 :
V_3 = V_4 + 0x3f8 ;
break;
case V_5 :
case V_6 :
V_3 = V_4 + 0x2f8 ;
break;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
default:
V_3 = V_11 + 0x3f8 ;
break;
}
V_12 =
( unsigned long ) F_2 ( V_3 , 8 ) ;
}
