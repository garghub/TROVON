const struct V_1 * * F_1 ( void )
{
struct V_2 * * V_3 , * * V_4 ;
struct V_2 * V_5 [] = { NULL } ;
struct V_6 V_7 ;
F_2 ( & V_7 ) ;
switch ( V_7 . V_8 ) {
case 0x2097 :
case 0x2098 :
V_4 = V_9 ;
break;
case 0x2817 :
case 0x2818 :
V_4 = V_10 ;
break;
case 0x2827 :
case 0x2828 :
V_4 = V_11 ;
break;
case 0x2964 :
case 0x2965 :
V_4 = V_12 ;
break;
default:
V_4 = V_5 ;
break;
}
V_3 = F_3 ( V_13 , V_4 ) ;
if ( V_3 )
V_14 . V_15 = V_3 ;
return V_16 ;
}
