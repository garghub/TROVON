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
unsigned long V_22 ;
F_5 ( V_22 ) ;
V_23 = ( V_23 & ~ V_6 ) | V_7 ;
F_6 ( V_22 ) ;
F_7 ( V_5 -> V_24 , V_8 , V_9 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == 0 )
V_23 &= ~ ( V_14 | V_15 ) ;
F_9 ( V_2 ) ;
}
int F_10 ( struct V_25 * V_26 )
{
int V_10 = - V_27 ;
if ( F_11 () ) {
F_12 ( V_26 , V_12 | V_13 | V_20 | V_21 , 0 , 0 ) ;
F_7 ( V_26 , V_12 | V_13 | V_20 | V_21 , 0 ) ;
F_13 ( V_26 , V_12 | V_13 | V_20 | V_21 , 0 ) ;
F_14 ( & V_28 ) ;
V_10 = F_15 ( V_26 , & V_28 ,
V_29 ) ;
}
return V_10 ;
}
