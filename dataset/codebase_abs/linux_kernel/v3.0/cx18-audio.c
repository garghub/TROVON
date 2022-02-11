int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
T_1 V_5 , V_6 ;
int V_7 ;
if ( F_2 ( V_8 , & V_2 -> V_9 ) )
V_4 = & V_2 -> V_10 -> V_11 ;
else
V_4 = & V_2 -> V_10 -> V_12 [ V_2 -> V_13 ] ;
F_3 ( V_2 -> V_14 , V_15 , V_16 ,
( T_1 ) V_4 -> V_17 , 0 , 0 ) ;
V_7 = F_4 ( V_2 , V_2 -> V_10 -> V_18 ,
V_15 , V_16 , V_4 -> V_13 , 0 , 0 ) ;
if ( V_7 )
return V_7 ;
V_5 = F_5 ( V_2 , V_19 ) ;
V_6 = V_5 & ~ V_20 ;
switch ( V_4 -> V_13 ) {
case V_21 :
V_6 |= V_22 ;
break;
case V_23 :
V_6 |= V_24 ;
break;
default:
V_6 |= V_25 ;
break;
}
if ( V_6 == V_5 ) {
V_5 &= ~ V_20 ;
switch ( V_4 -> V_13 ) {
case V_21 :
V_5 |= V_25 ;
break;
case V_23 :
V_5 |= V_25 ;
break;
default:
V_5 |= V_22 ;
break;
}
F_6 ( V_2 , V_5 | 0xb00 , V_19 ,
V_5 , V_20 ) ;
}
F_6 ( V_2 , V_6 | 0xb00 , V_19 ,
V_6 , V_20 ) ;
return 0 ;
}
