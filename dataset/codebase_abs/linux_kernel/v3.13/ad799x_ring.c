static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_9 ;
T_2 V_10 ;
switch ( V_8 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
V_10 = V_8 -> V_15 |
( * V_6 -> V_16 << V_17 ) ;
break;
case V_18 :
case V_19 :
case V_20 :
V_10 = ( * V_6 -> V_16 << V_17 ) |
V_21 ;
break;
case V_22 :
case V_23 :
V_10 = V_24 | V_21 ;
break;
default:
V_10 = 0 ;
}
V_9 = F_3 ( V_8 -> V_25 ,
V_10 , V_8 -> V_26 , V_8 -> V_27 ) ;
if ( V_9 < 0 )
goto V_28;
F_4 ( V_6 , V_8 -> V_27 ,
F_5 () ) ;
V_28:
F_6 ( V_6 -> V_29 ) ;
return V_30 ;
}
int F_7 ( struct V_5 * V_6 )
{
return F_8 ( V_6 , NULL ,
& F_1 , NULL ) ;
}
void F_9 ( struct V_5 * V_6 )
{
F_10 ( V_6 ) ;
}
