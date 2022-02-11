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
F_2 ( & V_7 -> V_8 ) ;
V_6 = & V_7 -> V_9 ;
F_3 (this, tmp, head) {
T_2 * V_39 = F_4 ( V_4 , T_2 , V_11 ) ;
F_5 ( V_7 , V_39 ) ;
}
F_6 ( & V_7 -> V_8 ) ;
}
static int F_21 ( struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
F_22 ( & V_2 -> V_17 ) ;
F_20 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_23 ( struct V_21 * V_12 , struct V_40 * V_41 , int V_42 )
{
if ( V_42 != V_43 && V_42 != V_44 &&
! F_24 ( V_45 ) )
return - V_46 ;
switch ( V_42 ) {
case V_47 :
return F_25 ( V_12 , V_41 -> V_48 ) ;
case V_49 :
return F_26 ( V_12 , V_41 -> V_48 ) ;
case V_44 :
return F_27 ( V_12 , V_41 -> V_48 ) ;
case V_50 :
return F_28 ( V_12 , V_41 -> V_48 ) ;
case V_43 :
return F_29 ( V_12 , V_41 -> V_48 ) ;
case V_51 :
return F_30 ( V_12 , V_41 -> V_48 ) ;
default:
return - V_52 ;
}
}
static T_2 * F_31 ( T_4 * V_7 )
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
static T_5 F_32 ( struct V_56 * V_57 , struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
T_2 * V_10 ;
F_33 ( & V_2 -> V_7 . V_8 ) ;
V_10 = F_31 ( & V_2 -> V_7 ) ;
if ( V_10 ) {
struct V_21 * V_58 = V_10 -> V_12 ;
V_57 -> V_12 = V_58 ;
V_57 -> V_59 = 1 ;
V_10 -> V_15 += V_57 -> V_60 ;
F_34 ( V_57 ) ;
V_12 -> V_61 . V_62 ++ ;
} else {
V_12 -> V_61 . V_63 ++ ;
F_35 ( V_57 ) ;
}
F_36 ( & V_2 -> V_7 . V_8 ) ;
return V_64 ;
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
T_2 * V_65 = NULL ;
V_65 = F_37 ( V_7 , V_10 -> V_12 ) ;
if ( V_65 )
F_5 ( V_7 , V_65 ) ;
F_41 ( & V_10 -> V_11 , & V_7 -> V_9 ) ;
V_7 -> V_37 ++ ;
V_10 -> V_12 -> V_13 |= V_38 ;
return 0 ;
}
return - V_66 ;
}
static int F_25 ( struct V_21 * V_24 , T_6 T_7 * V_67 )
{
struct V_21 * V_58 ;
T_6 V_68 ;
if ( F_42 ( & V_68 , V_67 , sizeof ( T_6 ) ) )
return - V_69 ;
V_58 = F_43 ( & V_70 , V_68 . V_71 ) ;
if ( V_58 ) {
if ( ( V_24 -> V_13 & V_14 ) == V_14 ) {
if ( ! F_44 ( V_58 ) &&
! F_45 ( V_58 ) ) {
T_2 * V_39 = F_46 ( sizeof( * V_39 ) , V_72 ) ;
T_1 * V_2 = F_9 ( V_24 ) ;
int V_73 ;
if ( ! V_39 ) {
F_18 ( V_58 ) ;
return - V_74 ;
}
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_12 = V_58 ;
V_39 -> V_59 = V_68 . V_59 ;
V_39 -> V_75 = V_68 . V_59 ;
V_39 -> V_16 = V_68 . V_59 / 8 ;
F_2 ( & V_2 -> V_7 . V_8 ) ;
V_73 = F_40 ( & V_2 -> V_7 , V_39 ) ;
if ( V_73 ) {
F_18 ( V_58 ) ;
F_19 ( V_39 ) ;
}
F_6 ( & V_2 -> V_7 . V_8 ) ;
return V_73 ;
}
}
F_18 ( V_58 ) ;
}
return - V_76 ;
}
static int F_26 ( struct V_21 * V_24 , T_6 T_7 * V_67 )
{
T_1 * V_2 = F_9 ( V_24 ) ;
struct V_21 * V_58 ;
T_6 V_68 ;
int V_73 ;
if ( F_42 ( & V_68 , V_67 , sizeof ( T_6 ) ) )
return - V_69 ;
V_58 = F_43 ( & V_70 , V_68 . V_71 ) ;
V_73 = - V_76 ;
if ( V_58 ) {
F_2 ( & V_2 -> V_7 . V_8 ) ;
if ( F_45 ( V_58 ) ) {
T_2 * V_10 = F_37 ( & V_2 -> V_7 ,
V_58 ) ;
if ( V_10 ) {
F_5 ( & V_2 -> V_7 , V_10 ) ;
V_73 = 0 ;
}
}
F_18 ( V_58 ) ;
F_6 ( & V_2 -> V_7 . V_8 ) ;
}
return V_73 ;
}
static int F_27 ( struct V_21 * V_12 , T_8 T_7 * V_77 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
T_2 * V_10 ;
struct V_21 * V_58 ;
T_8 V_78 ;
int V_73 ;
if ( F_42 ( & V_78 , V_77 , sizeof ( T_8 ) ) )
return - V_69 ;
V_58 = F_43 ( & V_70 , V_78 . V_71 ) ;
if ( ! V_58 )
return - V_79 ;
V_73 = - V_76 ;
F_2 ( & V_2 -> V_7 . V_8 ) ;
if ( F_45 ( V_58 ) ) {
V_10 = F_37 ( & V_2 -> V_7 , V_58 ) ;
if ( V_10 ) {
V_78 . V_59 = V_10 -> V_59 ;
V_73 = 0 ;
}
}
F_6 ( & V_2 -> V_7 . V_8 ) ;
F_18 ( V_58 ) ;
if ( ! V_73 && F_47 ( V_77 , & V_78 , sizeof ( T_8 ) ) )
V_73 = - V_69 ;
return V_73 ;
}
static int F_28 ( struct V_21 * V_12 , T_8 T_7 * V_77 )
{
T_2 * V_10 ;
T_1 * V_2 ;
struct V_21 * V_58 ;
T_8 V_78 ;
int V_73 ;
if ( F_42 ( & V_78 , V_77 , sizeof ( T_8 ) ) )
return - V_69 ;
V_58 = F_43 ( & V_70 , V_78 . V_71 ) ;
if ( ! V_58 )
return - V_79 ;
V_73 = - V_76 ;
V_2 = F_9 ( V_12 ) ;
F_2 ( & V_2 -> V_7 . V_8 ) ;
if ( F_45 ( V_58 ) ) {
V_10 = F_37 ( & V_2 -> V_7 , V_58 ) ;
if ( V_10 ) {
V_10 -> V_59 = V_78 . V_59 ;
V_10 -> V_75 = V_78 . V_59 ;
V_10 -> V_16 = V_78 . V_59 / 8 ;
V_73 = 0 ;
}
}
F_6 ( & V_2 -> V_7 . V_8 ) ;
F_18 ( V_58 ) ;
return V_73 ;
}
static int F_29 ( struct V_21 * V_12 , T_9 T_7 * V_80 )
{
T_1 * V_2 ;
T_9 V_81 ;
memset ( & V_81 , 0 , sizeof( T_9 ) ) ;
if ( F_44 ( V_12 ) ) {
V_2 = F_9 ( V_12 ) ;
V_81 . V_35 = V_2 -> V_35 ;
V_81 . V_34 = V_2 -> V_34 ;
if ( F_47 ( V_80 , & V_81 , sizeof ( T_9 ) ) )
return - V_69 ;
return 0 ;
}
return - V_76 ;
}
static int F_30 ( struct V_21 * V_12 , T_9 T_7 * V_80 )
{
T_1 * V_2 ;
T_9 V_81 ;
if ( F_42 ( & V_81 , V_80 , sizeof ( T_9 ) ) )
return - V_69 ;
if ( F_44 ( V_12 ) ) {
V_2 = F_9 ( V_12 ) ;
V_2 -> V_35 = V_81 . V_35 ;
V_2 -> V_34 = V_81 . V_34 ;
return 0 ;
}
return - V_76 ;
}
static int T_3 F_48 ( void )
{
int V_82 ;
F_49 ( L_2 , V_83 ) ;
V_84 = F_50 ( sizeof( T_1 ) , L_3 , F_8 ) ;
if ( ! V_84 )
return - V_74 ;
V_82 = F_51 ( V_84 ) ;
if ( V_82 )
F_52 ( V_84 ) ;
return V_82 ;
}
static void T_10 F_53 ( void )
{
F_54 ( V_84 ) ;
F_52 ( V_84 ) ;
}
