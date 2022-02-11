static void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
const struct V_6 * V_7 =
& V_5 [ V_4 ] ;
if ( V_4 <= V_7 -> V_8 )
return V_2 -> V_9 -> V_10 + V_7 -> V_11 + V_3 ;
}
return NULL ;
}
static unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
void T_1 * V_12 = F_1 ( V_2 , V_3 ) ;
T_2 V_13 = F_4 ( V_12 ) & V_14 ;
switch ( V_13 ) {
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
case V_19 :
default:
return V_20 ;
}
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_21 )
{
void T_1 * V_12 = F_1 ( V_2 , V_3 ) ;
T_2 V_13 = F_4 ( V_12 ) & ~ V_14 ;
switch ( V_21 ) {
case V_16 :
V_13 |= V_15 ;
break;
case V_18 :
V_13 |= V_17 ;
break;
}
F_6 ( V_13 , V_12 ) ;
}
