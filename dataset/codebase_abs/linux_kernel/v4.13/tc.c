int F_1 ( T_1 * V_1 , void T_2 * V_2 )
{
return F_2 ( * V_1 , ( T_1 * ) V_2 ) ;
}
int T_3 F_3 ( struct V_3 * V_4 )
{
if ( ! V_5 )
return - V_6 ;
memcpy ( & V_4 -> V_7 , F_4 () , sizeof( V_4 -> V_7 ) ) ;
V_4 -> V_8 = F_5 ( ( long ) F_6 ( 0 ) ) ;
switch ( V_9 ) {
case V_10 :
V_4 -> V_11 = 7 ;
break;
case V_12 :
case V_13 :
V_4 -> V_14 = 0x20000000 ;
V_4 -> V_15 = 0x20000000 ;
case V_16 :
V_4 -> V_11 = 3 ;
break;
case V_17 :
V_4 -> V_11 = 2 ;
default:
break;
}
return 0 ;
}
void T_3 F_7 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case 0 :
V_19 -> V_21 = V_22 [ V_23 ] ;
break;
case 1 :
V_19 -> V_21 = V_22 [ V_24 ] ;
break;
case 2 :
V_19 -> V_21 = V_22 [ V_25 ] ;
break;
case 5 :
V_19 -> V_21 = V_22 [ V_26 ] ;
break;
case 6 :
V_19 -> V_21 = V_22 [ V_27 ] ;
break;
default:
V_19 -> V_21 = - 1 ;
break;
}
}
