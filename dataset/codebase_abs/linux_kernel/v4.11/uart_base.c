void F_1 ( void )
{
switch ( V_1 ) {
case V_2 :
V_3 [ 0 ] = V_4 + 0x1e0 ;
break;
case V_5 :
V_3 [ 0 ] = V_6 + 0x3f8 ;
break;
case V_7 :
case V_8 :
V_3 [ 0 ] = V_6 + 0x2f8 ;
break;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
default:
V_3 [ 0 ] = V_13 + 0x3f8 ;
break;
}
V_14 [ 0 ] =
( unsigned long ) F_2 ( V_3 [ 0 ] , 8 ) ;
}
