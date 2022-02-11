static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
switch ( V_2 -> V_4 ) {
case 0 :
V_3 = F_2 ( 0 ) ;
break;
case 1 :
V_3 = F_2 ( 4 ) ;
break;
default:
F_3 ( & V_2 -> V_5 , L_1 ) ;
return - V_6 ;
}
F_4 ( V_3 , 3 ,
F_5 ( 2 ) , V_7 ) ;
return 0 ;
}
void T_1 F_6 ( int V_8 , int V_9 , int V_10 )
{
struct V_11 * V_12 ;
if ( ! V_10 || V_9 < 0
|| V_9 > V_13 ) {
F_7 ( V_14 L_2 , V_15 ) ;
return;
}
switch ( V_8 ) {
case 0 :
V_12 = & V_16 ;
break;
case 1 :
V_12 = & V_17 ;
break;
default:
F_7 ( V_14 L_3 ,
V_15 , V_8 ) ;
return;
}
V_12 -> V_10 = V_10 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_18 = V_19 [ V_9 ] ;
}
