int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 =
(struct V_8 * ) V_3 ;
switch ( V_9 -> V_9 ) {
case V_10 :
V_9 -> V_11 = F_3 ( V_7 ) ;
break;
case V_12 :
V_9 -> V_11 = F_4 ( V_7 ) ;
break;
case V_13 :
V_9 -> V_11 = F_5 ( V_7 ) ? 1 : 0 ;
break;
case V_14 :
V_9 -> V_11 = V_7 -> V_15 ;
break;
case V_16 :
V_9 -> V_11 = V_7 -> V_17 ;
break;
case V_18 :
V_9 -> V_11 = V_7 -> V_19 . V_17 ;
break;
case V_20 :
V_9 -> V_11 = V_7 -> V_21 ;
break;
default:
F_6 ( L_1 ,
V_9 -> V_9 ) ;
return - V_22 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_23 * V_24 = & V_7 -> V_19 ;
struct V_25 * V_26 =
(struct V_25 * ) V_3 ;
T_1 T_2 * V_27 = ( T_1 T_2 * )
( unsigned long ) V_26 -> V_28 ;
if ( F_8 ( V_24 -> V_29 == NULL ) )
return - V_22 ;
if ( V_26 -> V_30 < V_24 -> V_31 ) {
V_26 -> V_32 = V_26 -> V_30 ;
V_26 -> V_33 = 1 ;
} else {
V_26 -> V_32 = V_24 -> V_31 ;
V_26 -> V_33 = 0 ;
}
return F_9 ( V_27 , V_24 -> V_29 , V_26 -> V_32 ) ;
}
