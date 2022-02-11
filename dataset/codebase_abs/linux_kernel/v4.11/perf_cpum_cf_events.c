const struct V_1 * * F_1 ( void )
{
struct V_2 * * V_3 , * * V_4 ;
struct V_5 V_6 ;
F_2 ( & V_6 ) ;
switch ( V_6 . V_7 ) {
case 0x2097 :
case 0x2098 :
V_4 = V_8 ;
break;
case 0x2817 :
case 0x2818 :
V_4 = V_9 ;
break;
case 0x2827 :
case 0x2828 :
V_4 = V_10 ;
break;
default:
V_4 = NULL ;
break;
}
if ( ! V_4 )
goto V_11;
V_3 = F_3 ( V_12 , V_4 ) ;
if ( V_3 )
V_13 . V_14 = V_3 ;
V_11:
return V_15 ;
}
