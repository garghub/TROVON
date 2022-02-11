static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_4 ) ;
if ( F_4 ( V_4 ) -> V_7 & V_8 ) {
F_4 ( V_4 ) -> V_7 &= ~ V_8 ;
V_6 -> V_9 -= F_5 ( V_4 ) ;
F_6 ( F_7 ( V_2 ) , V_10 ,
F_5 ( V_4 ) ) ;
}
}
static bool F_8 ( T_1 V_11 , T_1 V_12 , T_2 V_13 , T_2 V_14 )
{
return V_11 > V_12 || ( V_11 == V_12 && F_9 ( V_13 , V_14 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_2 V_16 ;
* V_15 = 0 ;
V_16 = 1000 ;
if ( ( V_6 -> V_17 . V_18 || ! V_6 -> V_19 ) && F_11 ( V_6 ) != ~ 0U )
V_16 = F_12 ( F_11 ( V_6 ) >> 2 , V_16 ) ;
F_13 (skb, sk) {
struct V_20 * V_21 = F_4 ( V_4 ) ;
if ( V_4 == F_14 ( V_2 ) )
break;
if ( ! F_9 ( V_21 -> V_22 , V_6 -> V_23 ) ||
V_21 -> V_7 & V_24 )
continue;
if ( F_8 ( V_6 -> V_17 . V_25 , V_4 -> V_26 ,
V_6 -> V_17 . V_22 , V_21 -> V_22 ) ) {
T_2 V_27 = F_15 ( V_6 -> V_28 ,
V_4 -> V_26 ) ;
T_3 V_29 = V_6 -> V_17 . V_30 + V_16 - V_27 ;
if ( V_29 < 0 ) {
F_1 ( V_2 , V_4 ) ;
continue;
}
if ( ( V_21 -> V_7 & V_31 ) &&
! ( V_21 -> V_7 & V_8 ) )
continue;
* V_15 = F_16 ( T_2 , * V_15 , 1 + V_29 ) ;
} else if ( ! ( V_21 -> V_7 & V_32 ) ) {
break;
}
}
}
void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_33 ;
if ( ! V_6 -> V_17 . V_34 )
return;
V_6 -> V_17 . V_34 = 0 ;
F_10 ( V_2 , & V_33 ) ;
if ( V_33 ) {
V_33 = F_18 ( V_33 + V_35 ) ;
F_19 ( V_2 , V_36 ,
V_33 , F_20 ( V_2 ) -> V_37 ) ;
}
}
void F_21 ( struct V_5 * V_6 , T_4 V_7 , T_2 V_22 ,
T_1 V_38 )
{
T_2 V_30 ;
if ( V_6 -> V_17 . V_25 &&
! F_8 ( V_38 , V_6 -> V_17 . V_25 ,
V_22 , V_6 -> V_17 . V_22 ) )
return;
V_30 = F_15 ( V_6 -> V_28 , V_38 ) ;
if ( V_7 & V_32 ) {
if ( V_30 < F_11 ( V_6 ) )
return;
}
V_6 -> V_17 . V_30 = V_30 ;
V_6 -> V_17 . V_25 = V_38 ;
V_6 -> V_17 . V_22 = V_22 ;
V_6 -> V_17 . V_34 = 1 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_33 , V_39 ;
V_39 = F_23 ( V_6 ) ;
F_10 ( V_2 , & V_33 ) ;
if ( V_39 != F_23 ( V_6 ) ) {
if ( F_20 ( V_2 ) -> V_40 != V_41 ) {
F_24 ( V_2 , false ) ;
if ( ! F_20 ( V_2 ) -> V_42 -> V_43 )
F_25 ( V_2 , 1 , 0 ) ;
}
F_26 ( V_2 ) ;
}
if ( F_20 ( V_2 ) -> V_44 != V_45 )
F_27 ( V_2 ) ;
}
