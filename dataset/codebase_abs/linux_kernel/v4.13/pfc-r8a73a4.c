static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
void T_1 * V_4 ;
V_4 = V_2 -> V_5 -> V_6 + V_7 [ V_3 >> 5 ] + V_3 ;
switch ( F_2 ( V_4 ) & V_8 ) {
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
case V_13 :
default:
return V_14 ;
}
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_15 )
{
void T_1 * V_4 ;
T_2 V_16 ;
V_4 = V_2 -> V_5 -> V_6 + V_7 [ V_3 >> 5 ] + V_3 ;
V_16 = F_2 ( V_4 ) & ~ V_8 ;
switch ( V_15 ) {
case V_10 :
V_16 |= V_9 ;
break;
case V_12 :
V_16 |= V_11 ;
break;
}
F_4 ( V_16 , V_4 ) ;
}
