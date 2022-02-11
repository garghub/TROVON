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
T_1 V_21 = F_10 ( 0 ) ;
struct V_1 * V_2 ;
unsigned long V_6 ;
F_11 () ;
F_12 (ctx, &cancel_list, clist) {
if ( ! V_2 -> V_22 )
continue;
F_3 ( & V_2 -> V_7 . V_8 , V_6 ) ;
if ( V_2 -> V_21 != V_21 ) {
V_2 -> V_21 = V_23 ;
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
F_15 ( & V_24 ) ;
F_16 ( & V_2 -> V_25 ) ;
F_17 ( & V_24 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_24 ) ;
F_14 ( V_2 ) ;
F_17 ( & V_2 -> V_24 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 || V_2 -> V_21 != V_23 )
return false ;
V_2 -> V_21 = F_10 ( 0 ) ;
return true ;
}
static void F_20 ( struct V_1 * V_2 , int V_6 )
{
F_15 ( & V_2 -> V_24 ) ;
if ( ( V_2 -> V_3 == V_26 ||
V_2 -> V_3 == V_4 ) &&
( V_6 & V_27 ) && ( V_6 & V_28 ) ) {
if ( ! V_2 -> V_22 ) {
V_2 -> V_22 = true ;
F_15 ( & V_24 ) ;
F_21 ( & V_2 -> V_25 , & V_29 ) ;
F_17 ( & V_24 ) ;
}
} else {
F_14 ( V_2 ) ;
}
F_17 ( & V_2 -> V_24 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_30 ;
if ( F_1 ( V_2 ) )
V_30 = F_23 ( & V_2 -> V_14 . V_18 ) ;
else
V_30 = F_24 ( & V_2 -> V_14 . V_15 ) ;
return V_30 < 0 ? 0 : V_30 ;
}
static int F_25 ( struct V_1 * V_2 , int V_6 ,
const struct V_31 * V_32 )
{
enum V_33 V_34 ;
T_1 V_35 ;
int V_3 = V_2 -> V_3 ;
V_34 = ( V_6 & V_27 ) ?
V_36 : V_37 ;
V_35 = F_26 ( V_32 -> V_38 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_39 = F_26 ( V_32 -> V_40 ) ;
if ( F_1 ( V_2 ) ) {
F_27 ( & V_2 -> V_14 . V_18 ,
V_2 -> V_3 == V_4 ?
V_41 : V_42 ,
F_8 ) ;
} else {
F_28 ( & V_2 -> V_14 . V_15 , V_3 , V_34 ) ;
F_29 ( & V_2 -> V_14 . V_15 , V_35 ) ;
V_2 -> V_14 . V_15 . V_43 = F_6 ;
}
if ( V_35 != 0 ) {
if ( F_1 ( V_2 ) ) {
if ( V_6 & V_27 )
F_30 ( & V_2 -> V_14 . V_18 , V_35 ) ;
else
F_31 ( & V_2 -> V_14 . V_18 , V_35 ) ;
} else {
F_32 ( & V_2 -> V_14 . V_15 , V_35 , V_34 ) ;
}
if ( F_19 ( V_2 ) )
return - V_44 ;
}
V_2 -> V_45 = V_6 & V_46 ;
return 0 ;
}
static int F_33 ( struct V_47 * V_47 , struct V_48 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
F_18 ( V_2 ) ;
if ( F_1 ( V_2 ) )
F_34 ( & V_2 -> V_14 . V_18 ) ;
else
F_35 ( & V_2 -> V_14 . V_15 ) ;
F_36 ( V_2 , V_50 ) ;
return 0 ;
}
static unsigned int F_37 ( struct V_48 * V_48 , T_2 * V_51 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
unsigned int V_52 = 0 ;
unsigned long V_6 ;
F_38 ( V_48 , & V_2 -> V_7 , V_51 ) ;
F_3 ( & V_2 -> V_7 . V_8 , V_6 ) ;
if ( V_2 -> V_10 )
V_52 |= V_53 ;
F_5 ( & V_2 -> V_7 . V_8 , V_6 ) ;
return V_52 ;
}
static T_3 F_39 ( struct V_48 * V_48 , char T_4 * V_54 , T_5 V_55 ,
T_6 * V_56 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
T_3 V_57 ;
T_7 V_10 = 0 ;
if ( V_55 < sizeof( V_10 ) )
return - V_58 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( V_48 -> V_59 & V_60 )
V_57 = - V_61 ;
else
V_57 = F_41 ( V_2 -> V_7 , V_2 -> V_10 ) ;
if ( F_19 ( V_2 ) ) {
V_2 -> V_10 = 0 ;
V_2 -> V_9 = 0 ;
V_57 = - V_44 ;
}
if ( V_2 -> V_10 ) {
V_10 = V_2 -> V_10 ;
if ( V_2 -> V_9 && V_2 -> V_39 ) {
if ( F_1 ( V_2 ) ) {
V_10 += F_42 (
& V_2 -> V_14 . V_18 , V_2 -> V_39 ) - 1 ;
F_43 ( & V_2 -> V_14 . V_18 ) ;
} else {
V_10 += F_44 ( & V_2 -> V_14 . V_15 ,
V_2 -> V_39 ) - 1 ;
V_11 ( & V_2 -> V_14 . V_15 ) ;
}
}
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
}
F_45 ( & V_2 -> V_7 . V_8 ) ;
if ( V_10 )
V_57 = F_46 ( V_10 , ( T_7 T_4 * ) V_54 ) ? - V_62 : sizeof( V_10 ) ;
return V_57 ;
}
static void F_47 ( struct V_63 * V_64 , struct V_48 * V_48 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
struct V_65 V_14 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
V_14 . V_38 = F_48 ( F_22 ( V_2 ) ) ;
V_14 . V_40 = F_48 ( V_2 -> V_39 ) ;
F_45 ( & V_2 -> V_7 . V_8 ) ;
F_49 ( V_64 ,
L_1
L_2
L_3
L_4
L_5 ,
V_2 -> V_3 ,
( unsigned long long ) V_2 -> V_10 ,
V_2 -> V_45 ,
( unsigned long long ) V_14 . V_38 . V_66 ,
( unsigned long long ) V_14 . V_38 . V_67 ,
( unsigned long long ) V_14 . V_40 . V_66 ,
( unsigned long long ) V_14 . V_40 . V_67 ) ;
}
static long F_50 ( struct V_48 * V_48 , unsigned int V_68 , unsigned long V_69 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
int V_70 = 0 ;
switch ( V_68 ) {
case V_71 : {
T_7 V_10 ;
if ( F_51 ( & V_10 , ( T_7 T_4 * ) V_69 , sizeof( V_10 ) ) )
return - V_62 ;
if ( ! V_10 )
return - V_58 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( ! F_19 ( V_2 ) ) {
V_2 -> V_10 = V_10 ;
F_4 ( & V_2 -> V_7 ) ;
} else
V_70 = - V_44 ;
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
if ( ! V_75 . V_48 )
return - V_76 ;
if ( V_75 . V_48 -> V_77 != & V_78 ) {
F_54 ( V_75 ) ;
return - V_58 ;
}
* V_74 = V_75 ;
return 0 ;
}
static int F_55 ( int V_79 , int V_6 ,
const struct V_31 * V_80 ,
struct V_31 * V_81 )
{
struct V_73 V_75 ;
struct V_1 * V_2 ;
int V_70 ;
if ( ( V_6 & ~ V_46 ) ||
! F_56 ( V_80 ) )
return - V_58 ;
V_70 = F_52 ( V_79 , & V_75 ) ;
if ( V_70 )
return V_70 ;
V_2 = V_75 . V_48 -> V_49 ;
if ( F_1 ( V_2 ) && ! F_57 ( V_82 ) ) {
F_54 ( V_75 ) ;
return - V_83 ;
}
F_20 ( V_2 , V_6 ) ;
for (; ; ) {
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_58 ( & V_2 -> V_14 . V_18 ) >= 0 )
break;
} else {
if ( F_59 ( & V_2 -> V_14 . V_15 ) >= 0 )
break;
}
F_45 ( & V_2 -> V_7 . V_8 ) ;
F_60 () ;
}
if ( V_2 -> V_9 && V_2 -> V_39 ) {
if ( F_1 ( V_2 ) )
F_42 ( & V_2 -> V_14 . V_18 , V_2 -> V_39 ) ;
else
F_44 ( & V_2 -> V_14 . V_15 , V_2 -> V_39 ) ;
}
V_81 -> V_38 = F_61 ( F_22 ( V_2 ) ) ;
V_81 -> V_40 = F_61 ( V_2 -> V_39 ) ;
V_70 = F_25 ( V_2 , V_6 , V_80 ) ;
F_45 ( & V_2 -> V_7 . V_8 ) ;
F_54 ( V_75 ) ;
return V_70 ;
}
static int F_62 ( int V_79 , struct V_31 * V_14 )
{
struct V_73 V_75 ;
struct V_1 * V_2 ;
int V_70 = F_52 ( V_79 , & V_75 ) ;
if ( V_70 )
return V_70 ;
V_2 = V_75 . V_48 -> V_49 ;
F_40 ( & V_2 -> V_7 . V_8 ) ;
if ( V_2 -> V_9 && V_2 -> V_39 ) {
V_2 -> V_9 = 0 ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_10 +=
F_42 (
& V_2 -> V_14 . V_18 , V_2 -> V_39 ) - 1 ;
F_43 ( & V_2 -> V_14 . V_18 ) ;
} else {
V_2 -> V_10 +=
F_44 ( & V_2 -> V_14 . V_15 , V_2 -> V_39 )
- 1 ;
V_11 ( & V_2 -> V_14 . V_15 ) ;
}
}
V_14 -> V_38 = F_61 ( F_22 ( V_2 ) ) ;
V_14 -> V_40 = F_61 ( V_2 -> V_39 ) ;
F_45 ( & V_2 -> V_7 . V_8 ) ;
F_54 ( V_75 ) ;
return 0 ;
}
