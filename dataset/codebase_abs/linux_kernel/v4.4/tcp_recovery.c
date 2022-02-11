int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
T_1 V_7 , V_8 = V_4 -> V_9 ;
if ( F_3 ( V_2 ) -> V_10 < V_11 || ! V_4 -> V_12 . V_13 )
return 0 ;
V_4 -> V_12 . V_13 = 0 ;
V_7 = 1000 ;
if ( V_4 -> V_12 . V_14 && F_4 ( V_4 ) != ~ 0U )
V_7 = F_5 ( F_4 ( V_4 ) >> 2 , V_7 ) ;
F_6 (skb, sk) {
struct V_15 * V_16 = F_7 ( V_6 ) ;
if ( V_6 == F_8 ( V_2 ) )
break;
if ( ! F_9 ( V_16 -> V_17 , V_4 -> V_18 ) ||
V_16 -> V_19 & V_20 )
continue;
if ( F_10 ( & V_4 -> V_12 . V_21 , & V_6 -> V_22 ) ) {
if ( F_11 ( & V_4 -> V_12 . V_21 ,
& V_6 -> V_22 ) <= V_7 )
continue;
F_12 ( V_4 , V_6 ) ;
if ( V_16 -> V_19 & V_23 ) {
V_16 -> V_19 &= ~ V_23 ;
V_4 -> V_9 -= F_13 ( V_6 ) ;
F_14 ( F_15 ( V_2 ) ,
V_24 ) ;
}
} else if ( ! ( V_16 -> V_19 & V_25 ) ) {
break;
}
}
return V_8 - V_4 -> V_9 ;
}
void F_16 ( struct V_3 * V_4 ,
const struct V_22 * V_26 , T_2 V_19 )
{
if ( V_4 -> V_12 . V_21 . V_27 &&
! F_10 ( V_26 , & V_4 -> V_12 . V_21 ) )
return;
if ( V_19 & V_25 ) {
struct V_22 V_28 ;
F_17 ( & V_28 ) ;
if ( F_11 ( & V_28 , V_26 ) < F_4 ( V_4 ) )
return;
}
V_4 -> V_12 . V_21 = * V_26 ;
V_4 -> V_12 . V_13 = 1 ;
}
