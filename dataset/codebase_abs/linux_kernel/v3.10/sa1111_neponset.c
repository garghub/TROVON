static int
F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 , V_7 , V_8 , V_9 ;
int V_10 ;
switch ( V_2 -> V_11 ) {
case 0 :
V_8 = V_12 | V_13 ;
V_6 = V_14 | V_15 ;
if ( V_3 -> V_16 == 0 )
V_7 = 0 ;
else if ( V_3 -> V_16 == 120 )
V_7 = V_15 ;
else if ( V_3 -> V_16 == V_3 -> V_17 )
V_7 = V_14 ;
else {
F_3 ( V_18 L_1 ,
V_19 , V_3 -> V_16 ) ;
return - 1 ;
}
break;
case 1 :
V_8 = V_20 | V_21 ;
V_6 = 0 ;
V_7 = 0 ;
if ( V_3 -> V_16 != V_3 -> V_17 && V_3 -> V_16 != 0 ) {
F_3 ( V_18 L_2 ,
V_19 , V_3 -> V_16 ) ;
return - 1 ;
}
break;
default:
return - 1 ;
}
switch ( V_3 -> V_17 ) {
default:
case 0 : V_9 = 0 ; break;
case 33 : V_9 = V_13 | V_20 ; break;
case 50 : V_9 = V_12 | V_21 ; break;
}
V_10 = F_4 ( V_2 , V_3 ) ;
if ( V_10 == 0 ) {
F_5 ( V_6 , V_7 ) ;
F_6 ( V_5 -> V_22 , V_8 , V_9 ) ;
}
return V_10 ;
}
int F_7 ( struct V_23 * V_24 )
{
int V_10 = - V_25 ;
if ( F_8 () ) {
F_9 ( V_24 , V_12 | V_13 | V_20 | V_21 , 0 , 0 ) ;
F_6 ( V_24 , V_12 | V_13 | V_20 | V_21 , 0 ) ;
F_10 ( V_24 , V_12 | V_13 | V_20 | V_21 , 0 ) ;
F_11 ( & V_26 ) ;
V_10 = F_12 ( V_24 , & V_26 ,
V_27 ) ;
}
return V_10 ;
}
