static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( V_3 ) {
case V_5 :
case V_6 :
return 0 ;
default:
V_4 = F_2 ( V_2 -> V_7 + V_3 ) ;
}
return V_4 ;
}
static T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_4 ;
switch ( V_3 ) {
case V_8 :
V_4 = F_4 ( V_2 -> V_7 + V_3 ) ;
V_4 &= ~ V_9 ;
break;
default:
V_4 = F_4 ( V_2 -> V_7 + V_3 ) ;
}
return V_4 ;
}
