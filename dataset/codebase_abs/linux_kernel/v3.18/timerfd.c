static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ||
V_2 -> V_3 == V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_3 ( & V_2 -> V_7 . V_8 , V_6 ) ;
V_2 -> V_9 = 1 ;
V_2 -> V_10 ++ ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_7 . V_8 , V_6 ) ;
}
static enum V_11 F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_7 ( V_13 , struct V_1 ,
V_14 . V_15 ) ;
F_2 ( V_2 ) ;
return V_16 ;
}
static enum V_17 F_8 ( struct V_18 * V_18 ,
T_1 V_19 )
{
struct V_1 * V_2 = F_7 ( V_18 , struct V_1 ,
V_14 . V_18 ) ;
F_2 ( V_2 ) ;
return V_20 ;
}
void F_9 ( void )
{
T_1 V_21 = F_10 ((ktime_t){ .tv64 = 0 }) ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_11 () ;
F_12 (ctx, &cancel_list, clist) {
if ( ! V_2 -> V_22 )
continue;
F_3 ( & V_2 -> V_7 . V_8 , V_6 ) ;
if ( V_2 -> V_21 . V_23 != V_21 . V_23 ) {
V_2 -> V_21 . V_23 = V_24 ;
V_2 -> V_10 ++ ;
F_4 ( & V_2 -> V_7 ) ;
}
F_5 ( & V_2 -> V_7 . V_8 , V_6 ) ;
}
F_13 () ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
V_2 -> V_22 = false ;
F_15 ( & V_25 ) ;
F_16 ( & V_2 -> V_26 ) ;
F_17 ( & V_25 ) ;
}
}
static bool F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 || V_2 -> V_21 . V_23 != V_24 )
return false ;
V_2 -> V_21 = F_10 ((ktime_t){ .tv64 = 0 }) ;
return true ;
}
static void F_19 ( struct V_1 * V_2 , int V_6 )
{
if ( ( V_2 -> V_3 == V_27 ||
V_2 -> V_3 == V_4 ) &&
( V_6 & V_28 ) && ( V_6 & V_29 ) ) {
if ( ! V_2 -> V_22 ) {
V_2 -> V_22 = true ;
F_15 ( & V_25 ) ;
F_20 ( & V_2 -> V_26 , & V_30 ) ;
F_17 ( & V_25 ) ;
}
} else if ( V_2 -> V_22 ) {
F_14 ( V_2 ) ;
}
}
static T_1 F_21 ( struct V_1 * V_2 )
{
T_1 V_31 ;
if ( F_1 ( V_2 ) )
V_31 = F_22 ( & V_2 -> V_14 . V_18 ) ;
else
V_31 = F_23 ( & V_2 -> V_14 . V_15 ) ;
return V_31 . V_23 < 0 ? F_24 ( 0 , 0 ) : V_31 ;
}
static int F_25 ( struct V_1 * V_2 , int V_6 ,
const struct V_32 * V_33 )
{
enum V_34 V_35 ;
T_1 V_36 ;
int V_3 = V_2 -> V_3 ;
V_35 = ( V_6 & V_28 ) ?
V_37 : V_38 ;
V_36 = F_26 ( V_33 -> V_39 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_40 = F_26 ( V_33 -> V_41 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( & V_2 -> V_14 . V_18 ,
V_2 -> V_3 == V_4 ?
V_42 : V_43 ,
F_8 ) ;
} else {
F_28 ( & V_2 -> V_14 . V_15 , V_3 , V_35 ) ;
F_29 ( & V_2 -> V_14 . V_15 , V_36 ) ;
V_2 -> V_14 . V_15 . V_44 = F_6 ;
}
if ( V_36 . V_23 != 0 ) {
if ( F_1 ( V_2 ) ) {
if ( V_6 & V_28 )
F_30 ( & V_2 -> V_14 . V_18 , V_36 ) ;
else
F_31 ( & V_2 -> V_14 . V_18 , V_36 ) ;
} else {
F_32 ( & V_2 -> V_14 . V_15 , V_36 , V_35 ) ;
}
if ( F_18 ( V_2 ) )
return - V_45 ;
}
V_2 -> V_46 = V_6 & V_47 ;
return 0 ;
}
static int F_33 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_14 ( V_2 ) ;
if ( F_1 ( V_2 ) )
F_34 ( & V_2 -> V_14 . V_18 ) ;
else
F_35 ( & V_2 -> V_14 . V_15 ) ;
F_36 ( V_2 , V_51 ) ;
return 0 ;
}
static unsigned int F_37 ( struct V_49 * V_49 , T_2 * V_52 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
unsigned int V_53 = 0 ;
unsigned long V_6 ;
F_38 ( V_49 , & V_2 -> V_7 , V_52 ) ;
F_3 ( & V_2 -> V_7 . V_8 , V_6 ) ;
if ( V_2 -> V_10 )
V_53 |= V_54 ;
F_5 ( & V_2 -> V_7 . V_8 , V_6 ) ;
return V_53 ;
}
static T_3 F_39 ( struct V_49 * V_49 , char T_4 * V_55 , T_5 V_56 ,
T_6 * V_57 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
T_3 V_58 ;
T_7 V_10 = 0 ;
if ( V_56 < sizeof( V_10 ) )
return - V_59 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( V_49 -> V_60 & V_61 )
V_58 = - V_62 ;
else
V_58 = F_41 ( V_2 -> V_7 , V_2 -> V_10 ) ;
if ( F_18 ( V_2 ) ) {
V_2 -> V_10 = 0 ;
V_2 -> V_9 = 0 ;
V_58 = - V_45 ;
}
if ( V_2 -> V_10 ) {
V_10 = V_2 -> V_10 ;
if ( V_2 -> V_9 && V_2 -> V_40 . V_23 ) {
if ( F_1 ( V_2 ) ) {
V_10 += F_42 (
& V_2 -> V_14 . V_18 , V_2 -> V_40 ) - 1 ;
F_43 ( & V_2 -> V_14 . V_18 ) ;
} else {
V_10 += F_44 ( & V_2 -> V_14 . V_15 ,
V_2 -> V_40 ) - 1 ;
V_11 ( & V_2 -> V_14 . V_15 ) ;
}
}
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
}
F_45 ( & V_2 -> V_7 . V_8 ) ;
if ( V_10 )
V_58 = F_46 ( V_10 , ( T_7 T_4 * ) V_55 ) ? - V_63 : sizeof( V_10 ) ;
return V_58 ;
}
static int F_47 ( struct V_64 * V_65 , struct V_49 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
struct V_32 V_14 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
V_14 . V_39 = F_48 ( F_21 ( V_2 ) ) ;
V_14 . V_41 = F_48 ( V_2 -> V_40 ) ;
F_45 ( & V_2 -> V_7 . V_8 ) ;
return F_49 ( V_65 ,
L_1
L_2
L_3
L_4
L_5 ,
V_2 -> V_3 , ( unsigned long long ) V_2 -> V_10 ,
V_2 -> V_46 ,
( unsigned long long ) V_14 . V_39 . V_66 ,
( unsigned long long ) V_14 . V_39 . V_67 ,
( unsigned long long ) V_14 . V_41 . V_66 ,
( unsigned long long ) V_14 . V_41 . V_67 ) ;
}
static long F_50 ( struct V_49 * V_49 , unsigned int V_68 , unsigned long V_69 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_70 = 0 ;
switch ( V_68 ) {
case V_71 : {
T_7 V_10 ;
if ( F_51 ( & V_10 , ( T_7 T_4 * ) V_69 , sizeof( V_10 ) ) )
return - V_63 ;
if ( ! V_10 )
return - V_59 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( ! F_18 ( V_2 ) ) {
V_2 -> V_10 = V_10 ;
F_4 ( & V_2 -> V_7 ) ;
} else
V_70 = - V_45 ;
F_45 ( & V_2 -> V_7 . V_8 ) ;
break;
}
default:
V_70 = - V_72 ;
break;
}
return V_70 ;
}
static int F_52 ( int V_73 , struct V_73 * V_74 )
{
struct V_73 V_75 = F_53 ( V_73 ) ;
if ( ! V_75 . V_49 )
return - V_76 ;
if ( V_75 . V_49 -> V_77 != & V_78 ) {
F_54 ( V_75 ) ;
return - V_59 ;
}
* V_74 = V_75 ;
return 0 ;
}
static int F_55 ( int V_79 , int V_6 ,
const struct V_32 * V_80 ,
struct V_32 * V_81 )
{
struct V_73 V_75 ;
struct V_1 * V_2 ;
int V_70 ;
if ( ( V_6 & ~ V_47 ) ||
! F_56 ( & V_80 -> V_39 ) ||
! F_56 ( & V_80 -> V_41 ) )
return - V_59 ;
V_70 = F_52 ( V_79 , & V_75 ) ;
if ( V_70 )
return V_70 ;
V_2 = V_75 . V_49 -> V_50 ;
F_19 ( V_2 , V_6 ) ;
for (; ; ) {
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_57 ( & V_2 -> V_14 . V_18 ) >= 0 )
break;
} else {
if ( F_58 ( & V_2 -> V_14 . V_15 ) >= 0 )
break;
}
F_45 ( & V_2 -> V_7 . V_8 ) ;
F_59 () ;
}
if ( V_2 -> V_9 && V_2 -> V_40 . V_23 ) {
if ( F_1 ( V_2 ) )
F_42 ( & V_2 -> V_14 . V_18 , V_2 -> V_40 ) ;
else
F_44 ( & V_2 -> V_14 . V_15 , V_2 -> V_40 ) ;
}
V_81 -> V_39 = F_48 ( F_21 ( V_2 ) ) ;
V_81 -> V_41 = F_48 ( V_2 -> V_40 ) ;
V_70 = F_25 ( V_2 , V_6 , V_80 ) ;
F_45 ( & V_2 -> V_7 . V_8 ) ;
F_54 ( V_75 ) ;
return V_70 ;
}
static int F_60 ( int V_79 , struct V_32 * V_14 )
{
struct V_73 V_75 ;
struct V_1 * V_2 ;
int V_70 = F_52 ( V_79 , & V_75 ) ;
if ( V_70 )
return V_70 ;
V_2 = V_75 . V_49 -> V_50 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( V_2 -> V_9 && V_2 -> V_40 . V_23 ) {
V_2 -> V_9 = 0 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_10 +=
F_42 (
& V_2 -> V_14 . V_18 , V_2 -> V_40 ) - 1 ;
F_43 ( & V_2 -> V_14 . V_18 ) ;
} else {
V_2 -> V_10 +=
F_44 ( & V_2 -> V_14 . V_15 , V_2 -> V_40 )
- 1 ;
V_11 ( & V_2 -> V_14 . V_15 ) ;
}
}
V_14 -> V_39 = F_48 ( F_21 ( V_2 ) ) ;
V_14 -> V_41 = F_48 ( V_2 -> V_40 ) ;
F_45 ( & V_2 -> V_7 . V_8 ) ;
F_54 ( V_75 ) ;
return 0 ;
}
