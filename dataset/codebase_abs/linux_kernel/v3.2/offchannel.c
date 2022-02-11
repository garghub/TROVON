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
bool V_3 )
{
struct V_1 * V_2 ;
F_12 ( & V_5 -> V_25 ) ;
F_13 (sdata, &local->interfaces, list) {
if ( ! F_14 ( V_2 ) )
continue;
if ( V_2 -> V_26 . type == V_35 &&
V_2 -> V_8 . V_9 . V_36 )
F_1 ( V_2 , V_3 ) ;
}
F_18 ( & V_5 -> V_25 ) ;
}
void F_20 ( struct V_4 * V_5 ,
bool V_37 ,
bool V_38 )
{
struct V_1 * V_2 ;
F_12 ( & V_5 -> V_25 ) ;
F_13 (sdata, &local->interfaces, list) {
if ( ! F_14 ( V_2 ) )
continue;
if ( V_38 &&
V_2 -> V_26 . type == V_35 ) {
if ( V_2 -> V_8 . V_9 . V_36 )
F_6 ( V_2 ) ;
}
if ( V_2 -> V_26 . type != V_27 ) {
F_21 ( V_28 , & V_2 -> V_29 ) ;
F_22 ( V_2 -> V_34 ) ;
}
if ( V_37 &&
( V_2 -> V_26 . type == V_30 ||
V_2 -> V_26 . type == V_31 ||
V_2 -> V_26 . type == V_32 ) )
F_16 (
V_2 , V_33 ) ;
}
F_18 ( & V_5 -> V_25 ) ;
}
static void F_23 ( struct V_39 * V_40 )
{
struct V_4 * V_5 =
F_24 ( V_40 , struct V_4 , V_41 ) ;
struct V_1 * V_2 ;
F_12 ( & V_5 -> V_42 ) ;
if ( ! V_5 -> V_43 ) {
F_18 ( & V_5 -> V_42 ) ;
return;
}
F_25 ( V_5 ) ;
if ( V_5 -> V_44 ) {
V_2 = F_26 ( V_5 -> V_45 ) ;
F_27 ( V_2 , V_5 -> V_44 ) ;
V_5 -> V_44 = NULL ;
} else {
F_28 ( V_5 -> V_45 ,
V_5 -> V_46 ,
V_5 -> V_43 ,
V_5 -> V_47 ,
V_5 -> V_48 ,
V_49 ) ;
}
F_18 ( & V_5 -> V_42 ) ;
}
void F_29 ( struct V_50 * V_15 )
{
struct V_4 * V_5 = F_30 ( V_15 ) ;
F_31 ( V_5 ) ;
F_32 ( V_15 , & V_5 -> V_41 ) ;
}
static void F_33 ( struct V_39 * V_40 )
{
struct V_4 * V_5 =
F_24 ( V_40 , struct V_4 , V_51 ) ;
F_12 ( & V_5 -> V_42 ) ;
if ( ! V_5 -> V_43 ) {
F_18 ( & V_5 -> V_42 ) ;
return;
}
if ( ! V_5 -> V_52 )
F_34 ( V_5 -> V_45 ,
V_5 -> V_46 ,
V_5 -> V_43 ,
V_5 -> V_47 ,
V_49 ) ;
V_5 -> V_43 = NULL ;
V_5 -> V_46 = 0 ;
F_25 ( V_5 ) ;
F_18 ( & V_5 -> V_42 ) ;
}
void F_35 ( struct V_50 * V_15 )
{
struct V_4 * V_5 = F_30 ( V_15 ) ;
F_36 ( V_5 ) ;
F_32 ( V_15 , & V_5 -> V_51 ) ;
}
void F_37 ( struct V_4 * V_5 )
{
F_38 ( & V_5 -> V_41 , F_23 ) ;
F_38 ( & V_5 -> V_51 , F_33 ) ;
}
