static void F_1 ( unsigned long V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
struct V_3 * V_4 , * V_5 , * V_6 ;
F_2 ( & V_2 -> V_7 . V_8 ) ;
V_6 = & V_2 -> V_7 . V_9 ;
F_3 (this, tmp, head) {
T_2 * V_10 = F_4 ( V_4 , T_2 , V_11 ) ;
if ( ( V_10 -> V_12 -> V_13 & V_14 ) == V_14 ) {
V_10 -> V_15 -= V_10 -> V_16 ;
if ( V_10 -> V_15 < 0 )
V_10 -> V_15 = 0 ;
} else {
F_5 ( & V_2 -> V_7 , V_10 ) ;
}
}
F_6 ( & V_2 -> V_7 . V_8 ) ;
V_2 -> V_17 . V_18 = V_19 + V_20 ;
F_7 ( & V_2 -> V_17 ) ;
}
static void T_3 F_8 ( struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
F_10 ( & V_2 -> V_17 ) ;
V_2 -> V_17 . V_22 = ( unsigned long ) V_2 ;
V_2 -> V_17 . V_18 = V_19 + V_20 ;
V_2 -> V_17 . V_23 = F_1 ;
F_11 ( & V_2 -> V_7 . V_8 ) ;
F_12 ( & V_2 -> V_7 . V_9 ) ;
V_2 -> V_7 . V_24 = V_12 ;
V_12 -> V_25 = & V_26 ;
V_12 -> V_27 = V_28 ;
V_12 -> V_13 = V_29 ;
V_12 -> type = V_30 ;
V_12 -> V_31 = 5 ;
V_12 -> V_32 &= ~ V_33 ;
}
static int F_13 ( struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
F_14 ( V_12 ,
L_1 ) ;
F_15 ( ! F_16 ( & V_2 -> V_7 . V_9 ) ) ;
V_2 -> V_34 = 1 ;
V_2 -> V_35 = V_36 ;
F_7 ( & V_2 -> V_17 ) ;
return 0 ;
}
static void F_5 ( T_4 * V_7 , T_2 * V_10 )
{
F_17 ( & V_10 -> V_11 ) ;
V_7 -> V_37 -- ;
V_10 -> V_12 -> V_13 &= ~ V_38 ;
F_18 ( V_10 -> V_12 ) ;
F_19 ( V_10 ) ;
}
static void F_20 ( T_4 * V_7 )
{
struct V_3 * V_6 , * V_5 , * V_4 ;
F_21 ( & V_7 -> V_8 ) ;
V_6 = & V_7 -> V_9 ;
F_3 (this, tmp, head) {
T_2 * V_39 = F_4 ( V_4 , T_2 , V_11 ) ;
F_5 ( V_7 , V_39 ) ;
}
F_22 ( & V_7 -> V_8 ) ;
}
static int F_23 ( struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
F_24 ( & V_2 -> V_17 ) ;
F_20 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_12 , struct V_40 * V_41 , int V_42 )
{
if ( V_42 != V_43 && V_42 != V_44 &&
! F_26 ( V_45 ) )
return - V_46 ;
switch ( V_42 ) {
case V_47 :
return F_27 ( V_12 , V_41 -> V_48 ) ;
case V_49 :
return F_28 ( V_12 , V_41 -> V_48 ) ;
case V_44 :
return F_29 ( V_12 , V_41 -> V_48 ) ;
case V_50 :
return F_30 ( V_12 , V_41 -> V_48 ) ;
case V_43 :
return F_31 ( V_12 , V_41 -> V_48 ) ;
case V_51 :
return F_32 ( V_12 , V_41 -> V_48 ) ;
default:
return - V_52 ;
}
}
static T_2 * F_33 ( T_4 * V_7 )
{
unsigned long V_53 = ~ 0UL ;
struct V_3 * V_4 , * V_5 , * V_6 ;
T_2 * V_54 ;
V_54 = NULL ;
V_6 = & V_7 -> V_9 ;
F_3 (this, tmp, head) {
T_2 * V_10 = F_4 ( V_4 , T_2 , V_11 ) ;
unsigned long V_55 , V_15 , V_16 ;
V_15 = V_10 -> V_15 ;
V_16 = V_10 -> V_16 ;
if ( ( V_10 -> V_12 -> V_13 & V_14 ) == V_14 ) {
V_55 = ( ~ 0UL - ( ~ 0UL / 2 ) ) -
( V_16 ) + V_15 * 8 ;
if ( V_55 < V_53 ) {
V_53 = V_55 ;
V_54 = V_10 ;
}
} else {
F_5 ( V_7 , V_10 ) ;
}
}
return V_54 ;
}
static T_5 F_34 ( struct V_56 * V_57 , struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
T_2 * V_10 ;
F_2 ( & V_2 -> V_7 . V_8 ) ;
V_10 = F_33 ( & V_2 -> V_7 ) ;
if ( V_10 ) {
struct V_21 * V_58 = V_10 -> V_12 ;
V_57 -> V_12 = V_58 ;
V_57 -> V_59 = V_60 ;
V_10 -> V_15 += V_57 -> V_61 ;
F_35 ( V_57 ) ;
V_12 -> V_62 . V_63 ++ ;
} else {
V_12 -> V_62 . V_64 ++ ;
F_36 ( V_57 ) ;
}
F_6 ( & V_2 -> V_7 . V_8 ) ;
return V_65 ;
}
static T_2 * F_37 ( T_4 * V_7 , struct V_21 * V_12 )
{
struct V_3 * V_4 , * V_6 ;
V_6 = & V_7 -> V_9 ;
F_38 (this, head) {
T_2 * V_10 = F_4 ( V_4 , T_2 , V_11 ) ;
if ( V_10 -> V_12 == V_12 )
return V_10 ;
}
return NULL ;
}
static inline int F_39 ( T_4 * V_7 )
{
T_1 * V_2 = F_9 ( V_7 -> V_24 ) ;
if ( V_7 -> V_37 >= V_2 -> V_35 )
return 1 ;
return 0 ;
}
static int F_40 ( T_4 * V_7 , T_2 * V_10 )
{
if ( ! F_39 ( V_7 ) ) {
T_2 * V_66 = NULL ;
V_66 = F_37 ( V_7 , V_10 -> V_12 ) ;
if ( V_66 )
F_5 ( V_7 , V_66 ) ;
F_41 ( & V_10 -> V_11 , & V_7 -> V_9 ) ;
V_7 -> V_37 ++ ;
V_10 -> V_12 -> V_13 |= V_38 ;
return 0 ;
}
return - V_67 ;
}
static int F_27 ( struct V_21 * V_24 , T_6 T_7 * V_68 )
{
struct V_21 * V_58 ;
T_6 V_69 ;
if ( F_42 ( & V_69 , V_68 , sizeof ( T_6 ) ) )
return - V_70 ;
V_58 = F_43 ( & V_71 , V_69 . V_72 ) ;
if ( V_58 ) {
if ( ( V_24 -> V_13 & V_14 ) == V_14 ) {
if ( ! F_44 ( V_58 ) &&
! F_45 ( V_58 ) ) {
T_2 * V_39 = F_46 ( sizeof( * V_39 ) , V_73 ) ;
T_1 * V_2 = F_9 ( V_24 ) ;
int V_74 ;
if ( ! V_39 ) {
F_18 ( V_58 ) ;
return - V_75 ;
}
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_12 = V_58 ;
V_39 -> V_59 = V_69 . V_59 ;
V_39 -> V_76 = V_69 . V_59 ;
V_39 -> V_16 = V_69 . V_59 / 8 ;
F_21 ( & V_2 -> V_7 . V_8 ) ;
V_74 = F_40 ( & V_2 -> V_7 , V_39 ) ;
if ( V_74 ) {
F_18 ( V_58 ) ;
F_19 ( V_39 ) ;
}
F_22 ( & V_2 -> V_7 . V_8 ) ;
return V_74 ;
}
}
F_18 ( V_58 ) ;
}
return - V_77 ;
}
static int F_28 ( struct V_21 * V_24 , T_6 T_7 * V_68 )
{
T_1 * V_2 = F_9 ( V_24 ) ;
struct V_21 * V_58 ;
T_6 V_69 ;
int V_74 ;
if ( F_42 ( & V_69 , V_68 , sizeof ( T_6 ) ) )
return - V_70 ;
V_58 = F_43 ( & V_71 , V_69 . V_72 ) ;
V_74 = - V_77 ;
if ( V_58 ) {
F_21 ( & V_2 -> V_7 . V_8 ) ;
if ( F_45 ( V_58 ) ) {
T_2 * V_10 = F_37 ( & V_2 -> V_7 ,
V_58 ) ;
if ( V_10 ) {
F_5 ( & V_2 -> V_7 , V_10 ) ;
V_74 = 0 ;
}
}
F_18 ( V_58 ) ;
F_22 ( & V_2 -> V_7 . V_8 ) ;
}
return V_74 ;
}
static int F_29 ( struct V_21 * V_12 , T_8 T_7 * V_78 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
T_2 * V_10 ;
struct V_21 * V_58 ;
T_8 V_79 ;
int V_74 ;
if ( F_42 ( & V_79 , V_78 , sizeof ( T_8 ) ) )
return - V_70 ;
V_58 = F_43 ( & V_71 , V_79 . V_72 ) ;
if ( ! V_58 )
return - V_80 ;
V_74 = - V_77 ;
F_21 ( & V_2 -> V_7 . V_8 ) ;
if ( F_45 ( V_58 ) ) {
V_10 = F_37 ( & V_2 -> V_7 , V_58 ) ;
if ( V_10 ) {
V_79 . V_59 = V_10 -> V_59 ;
V_74 = 0 ;
}
}
F_22 ( & V_2 -> V_7 . V_8 ) ;
F_18 ( V_58 ) ;
if ( ! V_74 && F_47 ( V_78 , & V_79 , sizeof ( T_8 ) ) )
V_74 = - V_70 ;
return V_74 ;
}
static int F_30 ( struct V_21 * V_12 , T_8 T_7 * V_78 )
{
T_2 * V_10 ;
T_1 * V_2 ;
struct V_21 * V_58 ;
T_8 V_79 ;
int V_74 ;
if ( F_42 ( & V_79 , V_78 , sizeof ( T_8 ) ) )
return - V_70 ;
V_58 = F_43 ( & V_71 , V_79 . V_72 ) ;
if ( ! V_58 )
return - V_80 ;
V_74 = - V_77 ;
V_2 = F_9 ( V_12 ) ;
F_21 ( & V_2 -> V_7 . V_8 ) ;
if ( F_45 ( V_58 ) ) {
V_10 = F_37 ( & V_2 -> V_7 , V_58 ) ;
if ( V_10 ) {
V_10 -> V_59 = V_79 . V_59 ;
V_10 -> V_76 = V_79 . V_59 ;
V_10 -> V_16 = V_79 . V_59 / 8 ;
V_74 = 0 ;
}
}
F_22 ( & V_2 -> V_7 . V_8 ) ;
F_18 ( V_58 ) ;
return V_74 ;
}
static int F_31 ( struct V_21 * V_12 , T_9 T_7 * V_81 )
{
T_1 * V_2 ;
T_9 V_82 ;
memset ( & V_82 , 0 , sizeof( T_9 ) ) ;
if ( F_44 ( V_12 ) ) {
V_2 = F_9 ( V_12 ) ;
V_82 . V_35 = V_2 -> V_35 ;
V_82 . V_34 = V_2 -> V_34 ;
if ( F_47 ( V_81 , & V_82 , sizeof ( T_9 ) ) )
return - V_70 ;
return 0 ;
}
return - V_77 ;
}
static int F_32 ( struct V_21 * V_12 , T_9 T_7 * V_81 )
{
T_1 * V_2 ;
T_9 V_82 ;
if ( F_42 ( & V_82 , V_81 , sizeof ( T_9 ) ) )
return - V_70 ;
if ( F_44 ( V_12 ) ) {
V_2 = F_9 ( V_12 ) ;
V_2 -> V_35 = V_82 . V_35 ;
V_2 -> V_34 = V_82 . V_34 ;
return 0 ;
}
return - V_77 ;
}
static int T_3 F_48 ( void )
{
int V_83 ;
F_49 ( L_2 , V_84 ) ;
V_85 = F_50 ( sizeof( T_1 ) , L_3 , F_8 ) ;
if ( ! V_85 )
return - V_75 ;
V_83 = F_51 ( V_85 ) ;
if ( V_83 )
F_52 ( V_85 ) ;
return V_83 ;
}
static void T_10 F_53 ( void )
{
F_54 ( V_85 ) ;
F_52 ( V_85 ) ;
}
