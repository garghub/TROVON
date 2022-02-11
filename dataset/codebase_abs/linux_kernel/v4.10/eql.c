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
F_13 ( V_12 ) ;
}
static int F_14 ( struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
F_15 ( V_12 ,
L_1 ) ;
F_16 ( ! F_17 ( & V_2 -> V_7 . V_9 ) ) ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = V_34 ;
F_7 ( & V_2 -> V_17 ) ;
return 0 ;
}
static void F_5 ( T_4 * V_7 , T_2 * V_10 )
{
F_18 ( & V_10 -> V_11 ) ;
V_7 -> V_35 -- ;
V_10 -> V_12 -> V_13 &= ~ V_36 ;
F_19 ( V_10 -> V_12 ) ;
F_20 ( V_10 ) ;
}
static void F_21 ( T_4 * V_7 )
{
struct V_3 * V_6 , * V_5 , * V_4 ;
F_22 ( & V_7 -> V_8 ) ;
V_6 = & V_7 -> V_9 ;
F_3 (this, tmp, head) {
T_2 * V_37 = F_4 ( V_4 , T_2 , V_11 ) ;
F_5 ( V_7 , V_37 ) ;
}
F_23 ( & V_7 -> V_8 ) ;
}
static int F_24 ( struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
F_25 ( & V_2 -> V_17 ) ;
F_21 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_26 ( struct V_21 * V_12 , struct V_38 * V_39 , int V_40 )
{
if ( V_40 != V_41 && V_40 != V_42 &&
! F_27 ( V_43 ) )
return - V_44 ;
switch ( V_40 ) {
case V_45 :
return F_28 ( V_12 , V_39 -> V_46 ) ;
case V_47 :
return F_29 ( V_12 , V_39 -> V_46 ) ;
case V_42 :
return F_30 ( V_12 , V_39 -> V_46 ) ;
case V_48 :
return F_31 ( V_12 , V_39 -> V_46 ) ;
case V_41 :
return F_32 ( V_12 , V_39 -> V_46 ) ;
case V_49 :
return F_33 ( V_12 , V_39 -> V_46 ) ;
default:
return - V_50 ;
}
}
static T_2 * F_34 ( T_4 * V_7 )
{
unsigned long V_51 = ~ 0UL ;
struct V_3 * V_4 , * V_5 , * V_6 ;
T_2 * V_52 ;
V_52 = NULL ;
V_6 = & V_7 -> V_9 ;
F_3 (this, tmp, head) {
T_2 * V_10 = F_4 ( V_4 , T_2 , V_11 ) ;
unsigned long V_53 , V_15 , V_16 ;
V_15 = V_10 -> V_15 ;
V_16 = V_10 -> V_16 ;
if ( ( V_10 -> V_12 -> V_13 & V_14 ) == V_14 ) {
V_53 = ( ~ 0UL - ( ~ 0UL / 2 ) ) -
( V_16 ) + V_15 * 8 ;
if ( V_53 < V_51 ) {
V_51 = V_53 ;
V_52 = V_10 ;
}
} else {
F_5 ( V_7 , V_10 ) ;
}
}
return V_52 ;
}
static T_5 F_35 ( struct V_54 * V_55 , struct V_21 * V_12 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
T_2 * V_10 ;
F_2 ( & V_2 -> V_7 . V_8 ) ;
V_10 = F_34 ( & V_2 -> V_7 ) ;
if ( V_10 ) {
struct V_21 * V_56 = V_10 -> V_12 ;
V_55 -> V_12 = V_56 ;
V_55 -> V_57 = V_58 ;
V_10 -> V_15 += V_55 -> V_59 ;
F_36 ( V_55 ) ;
V_12 -> V_60 . V_61 ++ ;
} else {
V_12 -> V_60 . V_62 ++ ;
F_37 ( V_55 ) ;
}
F_6 ( & V_2 -> V_7 . V_8 ) ;
return V_63 ;
}
static T_2 * F_38 ( T_4 * V_7 , struct V_21 * V_12 )
{
struct V_3 * V_4 , * V_6 ;
V_6 = & V_7 -> V_9 ;
F_39 (this, head) {
T_2 * V_10 = F_4 ( V_4 , T_2 , V_11 ) ;
if ( V_10 -> V_12 == V_12 )
return V_10 ;
}
return NULL ;
}
static inline int F_40 ( T_4 * V_7 )
{
T_1 * V_2 = F_9 ( V_7 -> V_24 ) ;
if ( V_7 -> V_35 >= V_2 -> V_33 )
return 1 ;
return 0 ;
}
static int F_41 ( T_4 * V_7 , T_2 * V_10 )
{
if ( ! F_40 ( V_7 ) ) {
T_2 * V_64 = NULL ;
V_64 = F_38 ( V_7 , V_10 -> V_12 ) ;
if ( V_64 )
F_5 ( V_7 , V_64 ) ;
F_42 ( V_10 -> V_12 ) ;
F_43 ( & V_10 -> V_11 , & V_7 -> V_9 ) ;
V_7 -> V_35 ++ ;
V_10 -> V_12 -> V_13 |= V_36 ;
return 0 ;
}
return - V_65 ;
}
static int F_28 ( struct V_21 * V_24 , T_6 T_7 * V_66 )
{
struct V_21 * V_56 ;
T_6 V_67 ;
if ( F_44 ( & V_67 , V_66 , sizeof ( T_6 ) ) )
return - V_68 ;
V_56 = F_45 ( & V_69 , V_67 . V_70 ) ;
if ( ! V_56 )
return - V_71 ;
if ( ( V_24 -> V_13 & V_14 ) == V_14 ) {
if ( ! F_46 ( V_56 ) && ! F_47 ( V_56 ) ) {
T_2 * V_37 = F_48 ( sizeof( * V_37 ) , V_72 ) ;
T_1 * V_2 = F_9 ( V_24 ) ;
int V_73 ;
if ( ! V_37 )
return - V_74 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_12 = V_56 ;
V_37 -> V_57 = V_67 . V_57 ;
V_37 -> V_75 = V_67 . V_57 ;
V_37 -> V_16 = V_67 . V_57 / 8 ;
F_22 ( & V_2 -> V_7 . V_8 ) ;
V_73 = F_41 ( & V_2 -> V_7 , V_37 ) ;
if ( V_73 )
F_20 ( V_37 ) ;
F_23 ( & V_2 -> V_7 . V_8 ) ;
return V_73 ;
}
}
return - V_76 ;
}
static int F_29 ( struct V_21 * V_24 , T_6 T_7 * V_66 )
{
T_1 * V_2 = F_9 ( V_24 ) ;
struct V_21 * V_56 ;
T_6 V_67 ;
int V_73 ;
if ( F_44 ( & V_67 , V_66 , sizeof ( T_6 ) ) )
return - V_68 ;
V_56 = F_45 ( & V_69 , V_67 . V_70 ) ;
if ( ! V_56 )
return - V_71 ;
V_73 = - V_76 ;
F_22 ( & V_2 -> V_7 . V_8 ) ;
if ( F_47 ( V_56 ) ) {
T_2 * V_10 = F_38 ( & V_2 -> V_7 , V_56 ) ;
if ( V_10 ) {
F_5 ( & V_2 -> V_7 , V_10 ) ;
V_73 = 0 ;
}
}
F_23 ( & V_2 -> V_7 . V_8 ) ;
return V_73 ;
}
static int F_30 ( struct V_21 * V_12 , T_8 T_7 * V_77 )
{
T_1 * V_2 = F_9 ( V_12 ) ;
T_2 * V_10 ;
struct V_21 * V_56 ;
T_8 V_78 ;
int V_73 ;
if ( F_44 ( & V_78 , V_77 , sizeof ( T_8 ) ) )
return - V_68 ;
V_56 = F_45 ( & V_69 , V_78 . V_70 ) ;
if ( ! V_56 )
return - V_71 ;
V_73 = - V_76 ;
F_22 ( & V_2 -> V_7 . V_8 ) ;
if ( F_47 ( V_56 ) ) {
V_10 = F_38 ( & V_2 -> V_7 , V_56 ) ;
if ( V_10 ) {
V_78 . V_57 = V_10 -> V_57 ;
V_73 = 0 ;
}
}
F_23 ( & V_2 -> V_7 . V_8 ) ;
if ( ! V_73 && F_49 ( V_77 , & V_78 , sizeof ( T_8 ) ) )
V_73 = - V_68 ;
return V_73 ;
}
static int F_31 ( struct V_21 * V_12 , T_8 T_7 * V_77 )
{
T_2 * V_10 ;
T_1 * V_2 ;
struct V_21 * V_56 ;
T_8 V_78 ;
int V_73 ;
if ( F_44 ( & V_78 , V_77 , sizeof ( T_8 ) ) )
return - V_68 ;
V_56 = F_45 ( & V_69 , V_78 . V_70 ) ;
if ( ! V_56 )
return - V_71 ;
V_73 = - V_76 ;
V_2 = F_9 ( V_12 ) ;
F_22 ( & V_2 -> V_7 . V_8 ) ;
if ( F_47 ( V_56 ) ) {
V_10 = F_38 ( & V_2 -> V_7 , V_56 ) ;
if ( V_10 ) {
V_10 -> V_57 = V_78 . V_57 ;
V_10 -> V_75 = V_78 . V_57 ;
V_10 -> V_16 = V_78 . V_57 / 8 ;
V_73 = 0 ;
}
}
F_23 ( & V_2 -> V_7 . V_8 ) ;
return V_73 ;
}
static int F_32 ( struct V_21 * V_12 , T_9 T_7 * V_79 )
{
T_1 * V_2 ;
T_9 V_80 ;
memset ( & V_80 , 0 , sizeof( T_9 ) ) ;
if ( F_46 ( V_12 ) ) {
V_2 = F_9 ( V_12 ) ;
V_80 . V_33 = V_2 -> V_33 ;
V_80 . V_32 = V_2 -> V_32 ;
if ( F_49 ( V_79 , & V_80 , sizeof ( T_9 ) ) )
return - V_68 ;
return 0 ;
}
return - V_76 ;
}
static int F_33 ( struct V_21 * V_12 , T_9 T_7 * V_79 )
{
T_1 * V_2 ;
T_9 V_80 ;
if ( F_44 ( & V_80 , V_79 , sizeof ( T_9 ) ) )
return - V_68 ;
if ( F_46 ( V_12 ) ) {
V_2 = F_9 ( V_12 ) ;
V_2 -> V_33 = V_80 . V_33 ;
V_2 -> V_32 = V_80 . V_32 ;
return 0 ;
}
return - V_76 ;
}
static int T_3 F_50 ( void )
{
int V_81 ;
F_51 ( L_2 , V_82 ) ;
V_83 = F_52 ( sizeof( T_1 ) , L_3 , V_84 ,
F_8 ) ;
if ( ! V_83 )
return - V_74 ;
V_81 = F_53 ( V_83 ) ;
if ( V_81 )
F_54 ( V_83 ) ;
return V_81 ;
}
static void T_10 F_55 ( void )
{
F_56 ( V_83 ) ;
F_54 ( V_83 ) ;
}
