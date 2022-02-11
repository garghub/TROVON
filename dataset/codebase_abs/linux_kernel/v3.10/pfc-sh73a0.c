static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 -> V_6
+ V_7 [ V_3 >> 5 ] + V_3 ;
T_2 V_8 = F_2 ( V_4 ) & V_9 ;
switch ( V_8 ) {
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
case V_14 :
default:
return V_15 ;
}
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_16 )
{
void T_1 * V_4 = V_2 -> V_5 -> V_6
+ V_7 [ V_3 >> 5 ] + V_3 ;
T_2 V_8 = F_2 ( V_4 ) & ~ V_9 ;
switch ( V_16 ) {
case V_11 :
V_8 |= V_10 ;
break;
case V_13 :
V_8 |= V_12 ;
break;
}
F_4 ( V_8 , V_4 ) ;
}
