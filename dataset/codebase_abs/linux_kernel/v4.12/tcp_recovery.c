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
static bool F_8 ( const struct V_11 * V_12 ,
const struct V_11 * V_13 ,
T_1 V_14 , T_1 V_15 )
{
return F_9 ( V_12 , V_13 ) ||
( V_12 -> V_16 == V_13 -> V_16 && F_10 ( V_14 , V_15 ) ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_18 ;
* V_17 = 0 ;
V_18 = 1000 ;
if ( ( V_6 -> V_19 . V_20 || ! V_6 -> V_21 ) && F_12 ( V_6 ) != ~ 0U )
V_18 = F_13 ( F_12 ( V_6 ) >> 2 , V_18 ) ;
F_14 (skb, sk) {
struct V_22 * V_23 = F_4 ( V_4 ) ;
if ( V_4 == F_15 ( V_2 ) )
break;
if ( ! F_10 ( V_23 -> V_24 , V_6 -> V_25 ) ||
V_23 -> V_7 & V_26 )
continue;
if ( F_8 ( & V_6 -> V_19 . V_27 , & V_4 -> V_11 ,
V_6 -> V_19 . V_24 , V_23 -> V_24 ) ) {
T_1 V_28 = F_16 ( & V_6 -> V_29 ,
& V_4 -> V_11 ) ;
T_2 V_30 = V_6 -> V_19 . V_31 + V_18 - V_28 ;
if ( V_30 < 0 ) {
F_1 ( V_2 , V_4 ) ;
continue;
}
if ( ( V_23 -> V_7 & V_32 ) &&
! ( V_23 -> V_7 & V_8 ) )
continue;
* V_17 = F_17 ( T_1 , * V_17 , 1 + V_30 ) ;
} else if ( ! ( V_23 -> V_7 & V_33 ) ) {
break;
}
}
}
void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_34 ;
if ( ! V_6 -> V_19 . V_35 )
return;
V_6 -> V_19 . V_35 = 0 ;
F_11 ( V_2 , & V_34 ) ;
if ( V_34 ) {
V_34 = F_19 ( V_34 + V_36 ) ;
F_20 ( V_2 , V_37 ,
V_34 , F_21 ( V_2 ) -> V_38 ) ;
}
}
void F_22 ( struct V_5 * V_6 , T_3 V_7 , T_1 V_24 ,
const struct V_11 * V_39 )
{
T_1 V_31 ;
if ( V_6 -> V_19 . V_27 . V_16 &&
! F_8 ( V_39 , & V_6 -> V_19 . V_27 ,
V_24 , V_6 -> V_19 . V_24 ) )
return;
V_31 = F_16 ( & V_6 -> V_29 , V_39 ) ;
if ( V_7 & V_33 ) {
if ( V_31 < F_12 ( V_6 ) )
return;
}
V_6 -> V_19 . V_31 = V_31 ;
V_6 -> V_19 . V_27 = * V_39 ;
V_6 -> V_19 . V_24 = V_24 ;
V_6 -> V_19 . V_35 = 1 ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_34 , V_40 ;
V_40 = F_24 ( V_6 ) ;
F_25 ( & V_6 -> V_29 ) ;
F_11 ( V_2 , & V_34 ) ;
if ( V_40 != F_24 ( V_6 ) ) {
if ( F_21 ( V_2 ) -> V_41 != V_42 ) {
F_26 ( V_2 , false ) ;
if ( ! F_21 ( V_2 ) -> V_43 -> V_44 )
F_27 ( V_2 , 1 , 0 ) ;
}
F_28 ( V_2 ) ;
}
if ( F_21 ( V_2 ) -> V_45 != V_46 )
F_29 ( V_2 ) ;
}
