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
* V_8 = F_6 ( F_7 () , V_10 [ V_6 ] ) ;
V_2 -> V_11 |= ( 1 << V_6 ) ;
if ( V_6 < V_2 -> V_12 ) {
V_2 -> V_12 = V_6 ;
F_8 ( & V_2 -> V_13 , * V_8 ,
V_14 , V_15 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
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
F_10 ( V_2 , L_1 ,
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
static void F_11 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 )
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
F_10 ( V_2 , L_2 ,
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
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( ! ( F_3 ( V_2 , & V_2 -> V_5 -> V_22 ) & V_33 ) ) {
if ( V_2 -> V_34 ++ < 5 ) {
F_5 ( V_2 , V_35 , true ) ;
return;
}
F_15 ( V_2 , L_3 ) ;
}
V_2 -> V_18 = V_36 ;
F_2 ( V_2 , 0 , & V_2 -> V_5 -> V_37 ) ;
F_2 ( V_2 , 0 , & V_2 -> V_5 -> V_38 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
bool V_39 = ( V_2 -> V_18 < V_19 ) ;
while ( ! F_19 ( & V_2 -> V_40 ) ) {
struct V_41 * V_42 ;
V_42 = F_20 ( & V_2 -> V_40 ,
struct V_41 , V_43 ) ;
if ( ! V_39 && ( V_42 -> V_44 ==
V_2 -> V_45 ) )
break;
F_21 ( & V_42 -> V_43 ) ;
V_42 -> V_46 |= V_47 ;
F_22 ( V_2 , V_42 ) ;
}
if ( ! F_19 ( & V_2 -> V_40 ) ) {
F_5 ( V_2 , V_48 , true ) ;
++ V_2 -> V_45 ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
bool V_39 = ( V_2 -> V_18 < V_19 ) ;
V_2 -> V_49 = true ;
while ( ! F_19 ( & V_2 -> V_50 ) ) {
struct V_41 * V_42 ;
V_42 = F_20 ( & V_2 -> V_50 , struct V_41 ,
V_43 ) ;
if ( ! V_39 && V_42 -> V_44 == V_2 -> V_51 )
break;
F_21 ( & V_42 -> V_43 ) ;
F_24 ( V_2 , V_42 ) ;
}
if ( ! F_19 ( & V_2 -> V_50 ) ) {
F_5 ( V_2 , V_52 , true ) ;
++ V_2 -> V_51 ;
}
V_2 -> V_49 = false ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_11 & F_26 ( V_53 ) ) ) {
V_2 -> V_54 = F_27 (
V_2 -> V_55 . V_56 ,
struct V_57 , V_58 ) ;
V_2 -> V_59 = F_27 (
V_2 -> V_60 . V_56 ,
struct V_61 , V_62 ) ;
F_5 ( V_2 , V_53 , true ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_57 * V_63 , * V_64 ;
struct V_61 * V_65 , * V_66 ;
if ( V_2 -> V_18 < V_19 ) {
V_2 -> V_54 = NULL ;
V_2 -> V_59 = NULL ;
}
F_29 (itd, n, &ehci->cached_itd_list, itd_list) {
F_30 ( & V_63 -> V_58 ) ;
F_31 ( V_2 -> V_67 , V_63 , V_63 -> V_68 ) ;
if ( V_63 == V_2 -> V_54 )
break;
}
F_29 (sitd, sn, &ehci->cached_sitd_list, sitd_list) {
F_30 ( & V_65 -> V_62 ) ;
F_31 ( V_2 -> V_69 , V_65 , V_65 -> V_70 ) ;
if ( V_65 == V_2 -> V_59 )
break;
}
if ( ! F_19 ( & V_2 -> V_55 ) ||
! F_19 ( & V_2 -> V_60 ) )
F_25 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_71 , V_22 ;
if ( ! V_2 -> V_72 || V_2 -> V_18 != V_19 )
return;
V_71 = F_3 ( V_2 , & V_2 -> V_5 -> V_4 ) ;
V_22 = F_3 ( V_2 , & V_2 -> V_5 -> V_22 ) ;
if ( ( V_22 & V_73 ) || ! ( V_71 & V_74 ) ) {
F_33 ( V_2 -> V_75 . V_76 ) ;
F_2 ( V_2 , V_73 , & V_2 -> V_5 -> V_22 ) ;
}
F_10 ( V_2 , L_4 , V_22 , V_71 ) ;
F_34 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 != V_19 ||
( V_2 -> V_11 &
F_26 ( V_77 ) ) )
return;
if ( V_2 -> V_78 > 0 || ( V_2 -> V_79 &&
V_2 -> V_25 + V_2 -> V_80 > 0 ) )
F_5 ( V_2 , V_77 , true ) ;
}
static enum V_81 F_36 ( struct V_13 * V_82 )
{
struct V_1 * V_2 = F_37 ( V_82 , struct V_1 , V_13 ) ;
T_2 V_83 ;
unsigned long V_84 ;
unsigned long V_85 ;
unsigned V_86 ;
F_38 ( & V_2 -> V_87 , V_85 ) ;
V_84 = V_2 -> V_11 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = V_88 ;
V_83 = F_7 () ;
F_39 (e, &events, EHCI_HRTIMER_NUM_EVENTS) {
if ( V_83 >= V_2 -> V_9 [ V_86 ] )
V_89 [ V_86 ] ( V_2 ) ;
else
F_5 ( V_2 , V_86 , false ) ;
}
F_40 ( & V_2 -> V_87 , V_85 ) ;
return V_90 ;
}
