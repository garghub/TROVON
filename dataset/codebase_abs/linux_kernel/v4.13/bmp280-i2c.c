static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
const struct V_6 * V_6 ;
switch ( V_4 -> V_7 ) {
case V_8 :
V_6 = & V_9 ;
break;
case V_10 :
case V_11 :
V_6 = & V_12 ;
break;
default:
return - V_13 ;
}
V_5 = F_2 ( V_2 , V_6 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( & V_2 -> V_14 , L_1 ) ;
return F_5 ( V_5 ) ;
}
return F_6 ( & V_2 -> V_14 ,
V_5 ,
V_4 -> V_7 ,
V_4 -> V_15 ,
V_2 -> V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_14 ) ;
}
