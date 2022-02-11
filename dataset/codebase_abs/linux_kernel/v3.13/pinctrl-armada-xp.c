static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
const struct V_6 * V_7 =
F_2 ( V_8 , & V_2 -> V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_4 -> V_11 = ( unsigned ) V_7 -> V_12 & 0xff ;
switch ( V_4 -> V_11 ) {
case V_13 :
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = F_3 ( V_15 ) ;
V_4 -> V_17 = V_18 ;
V_4 -> V_19 = V_15 [ 0 ] . V_20 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = F_3 ( V_22 ) ;
break;
case V_24 :
V_4 -> V_14 = V_25 ;
V_4 -> V_16 = F_3 ( V_25 ) ;
V_4 -> V_17 = V_18 ;
V_4 -> V_19 = V_25 [ 0 ] . V_20 ;
V_4 -> V_21 = V_26 ;
V_4 -> V_23 = F_3 ( V_26 ) ;
break;
case V_27 :
V_4 -> V_14 = V_28 ;
V_4 -> V_16 = F_3 ( V_28 ) ;
V_4 -> V_17 = V_18 ;
V_4 -> V_19 = V_28 [ 0 ] . V_20 ;
V_4 -> V_21 = V_29 ;
V_4 -> V_23 = F_3 ( V_29 ) ;
break;
}
V_2 -> V_9 . V_30 = V_4 ;
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 ) ;
}
