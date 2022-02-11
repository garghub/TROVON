static int
F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 , V_7 ;
int V_8 ;
F_3 ( V_9 L_1 , V_10 ,
V_2 -> V_11 , V_3 -> V_12 , V_3 -> V_13 ) ;
switch ( V_2 -> V_11 ) {
case 0 :
V_6 = V_14 | V_15 ;
switch ( V_3 -> V_12 ) {
default:
case 0 :
V_7 = 0 ;
break;
case 33 :
V_7 = V_14 | V_15 ;
break;
case 50 :
V_7 = V_14 ;
break;
}
break;
case 1 :
V_6 = V_16 ;
switch ( V_3 -> V_12 ) {
default:
case 0 :
V_7 = 0 ;
break;
case 33 :
V_7 = V_16 ;
break;
case 50 :
V_7 = V_16 ;
break;
}
break;
default:
return - 1 ;
}
if ( V_3 -> V_13 != V_3 -> V_12 && V_3 -> V_13 != 0 ) {
F_3 ( V_17 L_2 ,
V_10 , V_3 -> V_13 ) ;
return - V_18 ;
}
V_8 = F_4 ( V_2 , V_3 ) ;
if ( V_8 == 0 )
F_5 ( V_5 -> V_19 , V_6 , V_7 ) ;
return V_8 ;
}
int T_2 F_6 ( struct V_20 * V_19 )
{
int V_8 = - V_21 ;
if ( F_7 () ) {
unsigned int V_22 = V_23 | V_24 | V_25 | V_26 ;
V_27 |= 0x00000002 ;
F_8 ( V_19 , V_22 , 0 , 0 ) ;
F_5 ( V_19 , V_22 , 0 ) ;
F_9 ( V_19 , V_22 , 0 ) ;
F_10 ( & V_28 ) ;
V_8 = F_11 ( V_19 , & V_28 ,
V_29 ) ;
}
return V_8 ;
}
