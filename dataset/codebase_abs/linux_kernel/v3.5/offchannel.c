static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
V_5 -> V_10 = false ;
F_2 ( & V_5 -> V_11 ) ;
F_2 ( & V_7 -> V_12 ) ;
F_2 ( & V_7 -> V_13 ) ;
F_3 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_15 . V_16 . V_17 & V_18 ) {
V_5 -> V_10 = true ;
V_5 -> V_15 . V_16 . V_17 &= ~ V_18 ;
F_4 ( V_5 , V_19 ) ;
}
if ( V_3 && ( ! V_5 -> V_10 ||
! ( V_5 -> V_15 . V_17 & V_20 ) ) )
F_5 ( V_5 , V_2 , 1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 -> V_21 )
F_5 ( V_5 , V_2 , 0 ) ;
else if ( V_5 -> V_10 ) {
V_5 -> V_15 . V_16 . V_17 |= V_18 ;
F_4 ( V_5 , V_19 ) ;
} else if ( V_5 -> V_15 . V_16 . V_22 > 0 ) {
F_5 ( V_5 , V_2 , 0 ) ;
F_7 ( & V_5 -> V_11 , V_23 +
F_8 ( V_5 -> V_15 . V_16 . V_22 ) ) ;
}
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
void F_11 ( struct V_4 * V_5 ,
bool V_24 )
{
struct V_1 * V_2 ;
F_12 ( & V_5 -> V_25 ) ;
F_13 (sdata, &local->interfaces, list) {
if ( ! F_14 ( V_2 ) )
continue;
if ( V_2 -> V_26 . type != V_27 )
F_15 ( V_28 , & V_2 -> V_29 ) ;
if ( V_2 -> V_26 . type == V_30 ||
V_2 -> V_26 . type == V_31 ||
V_2 -> V_26 . type == V_32 )
F_16 (
V_2 , V_33 ) ;
if ( V_2 -> V_26 . type != V_27 ) {
F_17 ( V_2 -> V_34 ) ;
if ( V_24 &&
( V_2 -> V_26 . type == V_35 ) &&
V_2 -> V_8 . V_9 . V_36 )
F_1 ( V_2 , true ) ;
}
}
F_18 ( & V_5 -> V_25 ) ;
}
void F_19 ( struct V_4 * V_5 ,
bool V_37 )
{
struct V_1 * V_2 ;
F_12 ( & V_5 -> V_25 ) ;
F_13 (sdata, &local->interfaces, list) {
if ( V_2 -> V_26 . type != V_27 )
F_20 ( V_28 , & V_2 -> V_29 ) ;
if ( ! F_14 ( V_2 ) )
continue;
if ( V_37 &&
V_2 -> V_26 . type == V_35 ) {
if ( V_2 -> V_8 . V_9 . V_36 )
F_6 ( V_2 ) ;
}
if ( V_2 -> V_26 . type != V_27 ) {
F_21 ( V_2 -> V_34 ) ;
}
if ( V_2 -> V_26 . type == V_30 ||
V_2 -> V_26 . type == V_31 ||
V_2 -> V_26 . type == V_32 )
F_16 (
V_2 , V_33 ) ;
}
F_18 ( & V_5 -> V_25 ) ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_4 * V_5 =
F_23 ( V_39 , struct V_4 , V_40 ) ;
struct V_1 * V_2 ;
F_12 ( & V_5 -> V_41 ) ;
if ( ! V_5 -> V_42 ) {
F_18 ( & V_5 -> V_41 ) ;
return;
}
if ( V_5 -> V_43 ) {
V_2 = F_24 ( V_5 -> V_44 ) ;
F_25 ( V_2 , V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
} else {
F_26 ( V_5 -> V_44 ,
V_5 -> V_45 ,
V_5 -> V_42 ,
V_5 -> V_46 ,
V_5 -> V_47 ,
V_48 ) ;
}
F_27 ( V_5 ) ;
F_18 ( & V_5 -> V_41 ) ;
}
void F_28 ( struct V_49 * V_15 )
{
struct V_4 * V_5 = F_29 ( V_15 ) ;
F_30 ( V_5 ) ;
F_31 ( V_15 , & V_5 -> V_40 ) ;
}
static void F_32 ( struct V_38 * V_39 )
{
struct V_4 * V_5 =
F_23 ( V_39 , struct V_4 , V_50 ) ;
F_12 ( & V_5 -> V_41 ) ;
if ( ! V_5 -> V_42 ) {
F_18 ( & V_5 -> V_41 ) ;
return;
}
if ( V_5 -> V_43 ) {
T_1 V_51 ;
V_51 = V_5 -> V_45 ^ 2 ;
F_33 ( V_5 -> V_44 , V_51 ,
V_5 -> V_43 -> V_52 ,
V_5 -> V_43 -> V_53 , false ,
V_48 ) ;
F_34 ( V_5 -> V_43 ) ;
V_5 -> V_43 = NULL ;
V_5 -> V_54 = NULL ;
}
if ( ! V_5 -> V_55 )
F_35 ( V_5 -> V_44 ,
V_5 -> V_45 ,
V_5 -> V_42 ,
V_5 -> V_46 ,
V_48 ) ;
V_5 -> V_42 = NULL ;
V_5 -> V_45 = 0 ;
F_27 ( V_5 ) ;
F_18 ( & V_5 -> V_41 ) ;
}
void F_36 ( struct V_49 * V_15 )
{
struct V_4 * V_5 = F_29 ( V_15 ) ;
F_37 ( V_5 ) ;
F_31 ( V_15 , & V_5 -> V_50 ) ;
}
void F_38 ( struct V_4 * V_5 )
{
F_39 ( & V_5 -> V_40 , F_22 ) ;
F_39 ( & V_5 -> V_50 , F_32 ) ;
}
