unsigned long * F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
unsigned long * V_4 = ( unsigned long * ) & V_2 -> V_5 . V_6 . V_7 . V_8 ;
unsigned long V_9 = * F_2 ( V_2 ) & V_10 ;
switch ( V_9 ) {
case V_11 ... V_12 :
V_9 &= ~ V_13 ;
break;
case V_14 :
V_9 = 4 ;
break;
case V_15 :
V_9 = 5 ;
break;
case V_16 :
V_9 = 0 ;
break;
default:
F_3 () ;
}
return V_4 + V_17 [ V_9 ] [ V_3 ] ;
}
unsigned long * F_4 ( const struct V_1 * V_2 )
{
unsigned long V_9 = * F_2 ( V_2 ) & V_10 ;
switch ( V_9 ) {
case V_12 :
V_9 = V_18 ;
break;
case V_14 :
V_9 = V_19 ;
break;
case V_15 :
V_9 = V_20 ;
break;
case V_21 :
V_9 = V_22 ;
break;
case V_23 :
V_9 = V_24 ;
break;
default:
F_3 () ;
}
return ( unsigned long * ) & F_5 ( V_2 ) -> V_25 [ V_9 ] ;
}
