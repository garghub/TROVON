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
if ( V_2 -> V_23 ++ < 20 ) {
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
if ( V_2 -> V_29 ++ < 20 ) {
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
V_2 -> V_40 = true ;
while ( V_2 -> V_41 ) {
struct V_42 * V_43 = V_2 -> V_41 ;
if ( ! V_39 && V_43 -> V_44 == V_2 -> V_45 )
break;
V_2 -> V_41 = V_43 -> V_46 ;
V_43 -> V_46 = NULL ;
F_20 ( V_2 , V_43 ) ;
}
if ( V_2 -> V_41 ) {
F_5 ( V_2 , V_47 , true ) ;
++ V_2 -> V_45 ;
}
V_2 -> V_40 = false ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_11 & F_22 ( V_48 ) ) ) {
V_2 -> V_49 = F_23 (
V_2 -> V_50 . V_51 ,
struct V_52 , V_53 ) ;
V_2 -> V_54 = F_23 (
V_2 -> V_55 . V_51 ,
struct V_56 , V_57 ) ;
F_5 ( V_2 , V_48 , true ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_52 * V_58 , * V_59 ;
struct V_56 * V_60 , * V_61 ;
if ( V_2 -> V_18 < V_19 ) {
V_2 -> V_49 = NULL ;
V_2 -> V_54 = NULL ;
}
F_25 (itd, n, &ehci->cached_itd_list, itd_list) {
F_26 ( & V_58 -> V_53 ) ;
F_27 ( V_2 -> V_62 , V_58 , V_58 -> V_63 ) ;
if ( V_58 == V_2 -> V_49 )
break;
}
F_25 (sitd, sn, &ehci->cached_sitd_list, sitd_list) {
F_26 ( & V_60 -> V_57 ) ;
F_27 ( V_2 -> V_64 , V_60 , V_60 -> V_65 ) ;
if ( V_60 == V_2 -> V_54 )
break;
}
if ( ! F_28 ( & V_2 -> V_50 ) ||
! F_28 ( & V_2 -> V_55 ) )
F_21 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 != V_19 )
return;
if ( V_2 -> V_66 ) {
T_1 V_67 , V_22 ;
V_67 = F_3 ( V_2 , & V_2 -> V_5 -> V_4 ) ;
V_22 = F_3 ( V_2 , & V_2 -> V_5 -> V_22 ) ;
if ( ( V_22 & V_68 ) || ! ( V_67 & V_69 ) ) {
F_30 ( V_2 -> V_70 . V_71 ) ;
F_2 ( V_2 , V_68 , & V_2 -> V_5 -> V_22 ) ;
}
F_31 ( V_2 , L_4 ,
V_22 , V_67 ) ;
F_18 ( V_2 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 != V_19 ||
( V_2 -> V_11 &
F_22 ( V_72 ) ) )
return;
if ( V_2 -> V_73 > 0 || ( V_2 -> V_74 &&
V_2 -> V_25 + V_2 -> V_75 > 0 ) )
F_5 ( V_2 , V_72 , true ) ;
}
static enum V_76 F_33 ( struct V_13 * V_77 )
{
struct V_1 * V_2 = F_34 ( V_77 , struct V_1 , V_13 ) ;
T_2 V_78 ;
unsigned long V_79 ;
unsigned long V_80 ;
unsigned V_81 ;
F_35 ( & V_2 -> V_82 , V_80 ) ;
V_79 = V_2 -> V_11 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_83 ;
V_78 = F_7 () ;
F_36 (e, &events, EHCI_HRTIMER_NUM_EVENTS) {
if ( V_78 . V_84 >= V_2 -> V_9 [ V_81 ] . V_84 )
V_85 [ V_81 ] ( V_2 ) ;
else
F_5 ( V_2 , V_81 , false ) ;
}
F_37 ( & V_2 -> V_82 , V_80 ) ;
return V_86 ;
}
