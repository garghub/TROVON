int F_1 ( union V_1 V_2 )
{
V_3 ;
V_4 ;
switch( V_5 ) {
case V_6 :
return 0x01 ;
case V_7 :
return 0x02 ;
case V_8 :
return 0x04 << ( V_9 ? 0 : 4 ) ;
case V_10 :
return 0x08 << ( V_9 ? 0 : 4 ) ;
case V_11 :
return 0x10 << ( V_9 ? 0 : 4 ) ;
case V_12 :
return 0x20 << ( V_9 ? 0 : 4 ) ;
default:
F_2 ( L_1 , V_5 ) ;
return 0 ;
}
}
