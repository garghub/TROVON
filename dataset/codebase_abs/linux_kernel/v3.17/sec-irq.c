int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int type = V_2 -> V_4 ;
const struct V_5 * V_6 ;
if ( ! V_2 -> V_7 ) {
F_2 ( V_2 -> V_8 ,
L_1 ) ;
V_2 -> V_9 = 0 ;
return 0 ;
}
switch ( type ) {
case V_10 :
V_6 = & V_11 ;
break;
case V_12 :
V_6 = & V_13 ;
break;
case V_14 :
V_6 = & V_15 ;
break;
case V_16 :
V_6 = & V_17 ;
break;
case V_18 :
V_6 = & V_19 ;
break;
default:
F_3 ( V_2 -> V_8 , L_2 ,
V_2 -> V_4 ) ;
return - V_20 ;
}
V_3 = F_4 ( V_2 -> V_21 , V_2 -> V_7 ,
V_22 | V_23 ,
V_2 -> V_9 , V_6 ,
& V_2 -> V_24 ) ;
if ( V_3 != 0 ) {
F_3 ( V_2 -> V_8 , L_3 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_7 , V_2 -> V_24 ) ;
}
