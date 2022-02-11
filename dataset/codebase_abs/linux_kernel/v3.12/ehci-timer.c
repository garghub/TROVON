static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 |= V_3 ;
F_2 ( V_2 , V_2 -> V_4 , & V_2 -> V_5 -> V_4 ) ;
F_3 ( V_2 , & V_2 -> V_5 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 &= ~ V_3 ;
F_2 ( V_2 , V_2 -> V_4 , & V_2 -> V_5 -> V_4 ) ;
F_3 ( V_2 , & V_2 -> V_5 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_6 ,
bool V_7 )
{
T_2 * V_8 = & V_2 -> V_9 [ V_6 ] ;
if ( V_7 )
* V_8 = F_6 ( F_7 () ,
F_8 ( 0 , V_10 [ V_6 ] ) ) ;
V_2 -> V_11 |= ( 1 << V_6 ) ;
if ( V_6 < V_2 -> V_12 ) {
V_2 -> V_12 = V_6 ;
F_9 ( & V_2 -> V_13 , * V_8 ,
V_14 , V_15 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned V_16 , V_17 ;
if ( V_2 -> V_18 != V_19 )
return;
V_17 = ( V_2 -> V_4 & V_20 ) ? V_21 : 0 ;
V_16 = F_3 ( V_2 , & V_2 -> V_5 -> V_22 ) & V_21 ;
if ( V_17 != V_16 ) {
if ( V_2 -> V_23 ++ < 2 ) {
F_5 ( V_2 , V_24 , true ) ;
return;
}
F_11 ( V_2 , L_1 ,
V_17 , V_16 ) ;
}
V_2 -> V_23 = 0 ;
if ( V_17 == 0 ) {
if ( V_2 -> V_25 > 0 )
F_1 ( V_2 , V_20 ) ;
} else {
if ( V_2 -> V_25 == 0 ) {
F_5 ( V_2 , V_26 ,
true ) ;
}
}
}
static void F_12 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_20 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned V_16 , V_17 ;
if ( V_2 -> V_18 != V_19 )
return;
V_17 = ( V_2 -> V_4 & V_27 ) ? V_28 : 0 ;
V_16 = F_3 ( V_2 , & V_2 -> V_5 -> V_22 ) & V_28 ;
if ( V_17 != V_16 ) {
if ( V_2 -> V_29 ++ < 2 ) {
F_5 ( V_2 , V_30 , true ) ;
return;
}
F_11 ( V_2 , L_2 ,
V_17 , V_16 ) ;
}
V_2 -> V_29 = 0 ;
if ( V_17 == 0 ) {
if ( V_2 -> V_31 > 0 )
F_1 ( V_2 , V_27 ) ;
} else {
if ( V_2 -> V_31 == 0 ) {
F_5 ( V_2 , V_32 ,
true ) ;
}
}
}
static void F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_27 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( ! ( F_3 ( V_2 , & V_2 -> V_5 -> V_22 ) & V_33 ) ) {
if ( V_2 -> V_34 ++ < 5 ) {
F_5 ( V_2 , V_35 , true ) ;
return;
}
F_16 ( V_2 , L_3 ) ;
}
V_2 -> V_18 = V_36 ;
F_2 ( V_2 , 0 , & V_2 -> V_5 -> V_37 ) ;
F_2 ( V_2 , 0 , & V_2 -> V_5 -> V_38 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
bool V_39 = ( V_2 -> V_18 < V_19 ) ;
while ( ! F_20 ( & V_2 -> V_40 ) ) {
struct V_41 * V_42 ;
V_42 = F_21 ( & V_2 -> V_40 ,
struct V_41 , V_43 ) ;
if ( ! V_39 && ( V_42 -> V_44 ==
V_2 -> V_45 ) )
break;
F_22 ( & V_42 -> V_43 ) ;
F_23 ( V_2 , V_42 ) ;
}
if ( ! F_20 ( & V_2 -> V_40 ) ) {
F_5 ( V_2 , V_46 , true ) ;
++ V_2 -> V_45 ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
bool V_39 = ( V_2 -> V_18 < V_19 ) ;
V_2 -> V_47 = true ;
while ( ! F_20 ( & V_2 -> V_48 ) ) {
struct V_41 * V_42 ;
V_42 = F_21 ( & V_2 -> V_48 , struct V_41 ,
V_43 ) ;
if ( ! V_39 && V_42 -> V_44 == V_2 -> V_49 )
break;
F_22 ( & V_42 -> V_43 ) ;
F_25 ( V_2 , V_42 ) ;
}
if ( ! F_20 ( & V_2 -> V_48 ) ) {
F_5 ( V_2 , V_50 , true ) ;
++ V_2 -> V_49 ;
}
V_2 -> V_47 = false ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_11 & F_27 ( V_51 ) ) ) {
V_2 -> V_52 = F_28 (
V_2 -> V_53 . V_54 ,
struct V_55 , V_56 ) ;
V_2 -> V_57 = F_28 (
V_2 -> V_58 . V_54 ,
struct V_59 , V_60 ) ;
F_5 ( V_2 , V_51 , true ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_55 * V_61 , * V_62 ;
struct V_59 * V_63 , * V_64 ;
if ( V_2 -> V_18 < V_19 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_57 = NULL ;
}
F_30 (itd, n, &ehci->cached_itd_list, itd_list) {
F_31 ( & V_61 -> V_56 ) ;
F_32 ( V_2 -> V_65 , V_61 , V_61 -> V_66 ) ;
if ( V_61 == V_2 -> V_52 )
break;
}
F_30 (sitd, sn, &ehci->cached_sitd_list, sitd_list) {
F_31 ( & V_63 -> V_60 ) ;
F_32 ( V_2 -> V_67 , V_63 , V_63 -> V_68 ) ;
if ( V_63 == V_2 -> V_57 )
break;
}
if ( ! F_20 ( & V_2 -> V_53 ) ||
! F_20 ( & V_2 -> V_58 ) )
F_26 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_69 , V_22 ;
if ( ! V_2 -> V_70 || V_2 -> V_18 != V_19 )
return;
V_69 = F_3 ( V_2 , & V_2 -> V_5 -> V_4 ) ;
V_22 = F_3 ( V_2 , & V_2 -> V_5 -> V_22 ) ;
if ( ( V_22 & V_71 ) || ! ( V_69 & V_72 ) ) {
F_34 ( V_2 -> V_73 . V_74 ) ;
F_2 ( V_2 , V_71 , & V_2 -> V_5 -> V_22 ) ;
}
F_11 ( V_2 , L_4 , V_22 , V_69 ) ;
F_18 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 != V_19 ||
( V_2 -> V_11 &
F_27 ( V_75 ) ) )
return;
if ( V_2 -> V_76 > 0 || ( V_2 -> V_77 &&
V_2 -> V_25 + V_2 -> V_78 > 0 ) )
F_5 ( V_2 , V_75 , true ) ;
}
static enum V_79 F_36 ( struct V_13 * V_80 )
{
struct V_1 * V_2 = F_37 ( V_80 , struct V_1 , V_13 ) ;
T_2 V_81 ;
unsigned long V_82 ;
unsigned long V_83 ;
unsigned V_84 ;
F_38 ( & V_2 -> V_85 , V_83 ) ;
V_82 = V_2 -> V_11 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_86 ;
V_81 = F_7 () ;
F_39 (e, &events, EHCI_HRTIMER_NUM_EVENTS) {
if ( V_81 . V_87 >= V_2 -> V_9 [ V_84 ] . V_87 )
V_88 [ V_84 ] ( V_2 ) ;
else
F_5 ( V_2 , V_84 , false ) ;
}
F_40 ( & V_2 -> V_85 , V_83 ) ;
return V_89 ;
}
