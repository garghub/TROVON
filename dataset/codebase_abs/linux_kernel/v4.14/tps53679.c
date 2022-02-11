static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , 0 , V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 = V_6 & F_3 ( 4 , 0 ) ;
switch ( V_5 ) {
case V_8 :
case V_9 :
V_4 -> V_10 = V_11 ;
break;
case V_12 :
case V_13 :
case V_14 :
V_4 -> V_10 = V_15 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
return F_5 ( V_2 , V_18 , & V_19 ) ;
}
