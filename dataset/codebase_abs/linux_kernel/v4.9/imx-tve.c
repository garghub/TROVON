static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static void F_4 ( void * V_8 )
__acquires( &tve->lock
static void F_5 ( void * V_8 )
__releases( &tve->lock
static void F_6 ( struct V_1 * V_9 )
{
int V_10 ;
if ( ! V_9 -> V_11 ) {
V_9 -> V_11 = true ;
F_7 ( V_9 -> V_12 ) ;
V_10 = F_8 ( V_9 -> V_13 , V_14 ,
V_15 , V_15 ) ;
}
F_9 ( V_9 -> V_13 , V_16 , 0xffffffff ) ;
if ( V_9 -> V_17 == V_18 )
F_9 ( V_9 -> V_13 , V_19 , 0 ) ;
else
F_9 ( V_9 -> V_13 , V_19 ,
V_20 |
V_21 |
V_22 ) ;
}
static void F_10 ( struct V_1 * V_9 )
{
int V_10 ;
if ( V_9 -> V_11 ) {
V_9 -> V_11 = false ;
V_10 = F_8 ( V_9 -> V_13 , V_14 ,
V_15 , 0 ) ;
F_11 ( V_9 -> V_12 ) ;
}
}
static int F_12 ( struct V_1 * V_9 )
{
return - V_23 ;
}
static int F_13 ( struct V_1 * V_9 )
{
unsigned int V_24 ;
unsigned int V_25 ;
int V_10 ;
V_10 = F_8 ( V_9 -> V_13 , V_26 ,
V_27 , 0x0a ) ;
if ( V_10 )
return V_10 ;
V_10 = F_8 ( V_9 -> V_13 , V_28 ,
V_27 , 0x0a ) ;
if ( V_10 )
return V_10 ;
V_10 = F_8 ( V_9 -> V_13 , V_29 ,
V_27 , 0x0a ) ;
if ( V_10 )
return V_10 ;
V_24 = V_30 | V_31 ;
V_25 = V_32 | V_33 ;
V_24 |= V_34 | V_35 ;
V_25 |= V_36 | 0 ;
V_24 |= V_37 | V_38 ;
V_25 |= V_39 | V_38 ;
V_10 = F_8 ( V_9 -> V_13 , V_14 , V_24 , V_25 ) ;
if ( V_10 )
return V_10 ;
return F_8 ( V_9 -> V_13 , V_40 ,
V_41 , 1 ) ;
}
static enum V_42 F_14 (
struct V_2 * V_4 , bool V_43 )
{
return V_44 ;
}
static int F_15 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_45 * V_45 ;
int V_10 = 0 ;
if ( ! V_9 -> V_46 )
return 0 ;
V_45 = F_16 ( V_4 , V_9 -> V_46 ) ;
if ( V_45 ) {
F_17 ( V_4 , V_45 ) ;
V_10 = F_18 ( V_4 , V_45 ) ;
F_19 ( V_45 ) ;
}
return V_10 ;
}
static int F_20 ( struct V_2 * V_4 ,
struct V_47 * V_17 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
unsigned long V_48 ;
V_48 = F_21 ( V_9 -> V_12 , 2000UL * V_17 -> clock ) / 2000 ;
if ( V_48 == V_17 -> clock )
return V_49 ;
V_48 = F_21 ( V_9 -> V_12 , 1000UL * V_17 -> clock ) / 1000 ;
if ( V_48 == V_17 -> clock )
return V_49 ;
F_22 ( V_9 -> V_50 , L_1 ,
V_17 -> V_51 , V_17 -> V_52 ) ;
return V_53 ;
}
static struct V_5 * F_23 (
struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
return & V_9 -> V_7 ;
}
static void F_24 ( struct V_5 * V_7 ,
struct V_47 * V_54 ,
struct V_47 * V_17 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
unsigned long V_55 ;
unsigned long V_48 ;
int div = 1 ;
int V_10 ;
V_48 = 2000UL * V_17 -> clock ;
F_25 ( V_9 -> V_12 , V_48 ) ;
V_55 = F_26 ( V_9 -> V_12 ) ;
if ( V_55 >= V_48 )
div = 2 ;
F_25 ( V_9 -> V_56 , V_55 / div ) ;
V_10 = F_27 ( V_9 -> V_57 , V_9 -> V_56 ) ;
if ( V_10 < 0 ) {
F_28 ( V_9 -> V_50 , L_2 ,
V_10 ) ;
}
F_8 ( V_9 -> V_13 , V_14 ,
V_58 , V_58 ) ;
if ( V_9 -> V_17 == V_18 )
V_10 = F_13 ( V_9 ) ;
else
V_10 = F_12 ( V_9 ) ;
if ( V_10 )
F_28 ( V_9 -> V_50 , L_3 , V_10 ) ;
}
static void F_29 ( struct V_5 * V_7 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
F_6 ( V_9 ) ;
}
static void F_30 ( struct V_5 * V_7 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
F_10 ( V_9 ) ;
}
static int F_31 ( struct V_5 * V_7 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_63 = F_32 ( V_60 ) ;
struct V_1 * V_9 = F_3 ( V_7 ) ;
V_63 -> V_64 = V_65 ;
V_63 -> V_66 = V_9 -> V_66 ;
V_63 -> V_67 = V_9 -> V_67 ;
return 0 ;
}
static T_1 F_33 ( int V_68 , void * V_69 )
{
struct V_1 * V_9 = V_69 ;
unsigned int V_25 ;
F_34 ( V_9 -> V_13 , V_16 , & V_25 ) ;
F_9 ( V_9 -> V_13 , V_16 , 0xffffffff ) ;
return V_70 ;
}
static unsigned long F_35 ( struct V_71 * V_72 ,
unsigned long V_73 )
{
struct V_1 * V_9 = F_2 ( V_72 , struct V_1 , V_74 ) ;
unsigned int V_25 ;
int V_10 ;
V_10 = F_34 ( V_9 -> V_13 , V_14 , & V_25 ) ;
if ( V_10 < 0 )
return 0 ;
switch ( V_25 & V_75 ) {
case V_76 :
return V_73 / 4 ;
case V_77 :
return V_73 / 2 ;
case V_78 :
default:
return V_73 ;
}
return 0 ;
}
static long F_36 ( struct V_71 * V_72 , unsigned long V_48 ,
unsigned long * V_79 )
{
unsigned long div ;
div = * V_79 / V_48 ;
if ( div >= 4 )
return * V_79 / 4 ;
else if ( div >= 2 )
return * V_79 / 2 ;
return * V_79 ;
}
static int F_37 ( struct V_71 * V_72 , unsigned long V_48 ,
unsigned long V_73 )
{
struct V_1 * V_9 = F_2 ( V_72 , struct V_1 , V_74 ) ;
unsigned long div ;
T_2 V_25 ;
int V_10 ;
div = V_73 / V_48 ;
if ( div >= 4 )
V_25 = V_76 ;
else if ( div >= 2 )
V_25 = V_77 ;
else
V_25 = V_78 ;
V_10 = F_8 ( V_9 -> V_13 , V_14 ,
V_75 , V_25 ) ;
if ( V_10 < 0 ) {
F_28 ( V_9 -> V_50 , L_4 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_9 , void T_3 * V_80 )
{
const char * V_81 [ 1 ] ;
struct V_82 V_83 = {
. V_84 = L_5 ,
. V_85 = & V_86 ,
. V_87 = 1 ,
. V_88 = 0 ,
} ;
V_81 [ 0 ] = F_39 ( V_9 -> V_12 ) ;
V_83 . V_89 = ( const char * * ) & V_81 ;
V_9 -> V_74 . V_83 = & V_83 ;
V_9 -> V_56 = F_40 ( V_9 -> V_50 , & V_9 -> V_74 ) ;
if ( F_41 ( V_9 -> V_56 ) ) {
F_28 ( V_9 -> V_50 , L_6 ,
F_42 ( V_9 -> V_56 ) ) ;
return F_42 ( V_9 -> V_56 ) ;
}
return 0 ;
}
static int F_43 ( struct V_90 * V_91 , struct V_1 * V_9 )
{
int V_92 ;
int V_10 ;
V_92 = V_9 -> V_17 == V_18 ?
V_93 : V_94 ;
V_10 = F_44 ( V_91 , & V_9 -> V_7 , V_9 -> V_50 -> V_95 ) ;
if ( V_10 )
return V_10 ;
F_45 ( & V_9 -> V_7 , & V_96 ) ;
F_46 ( V_91 , & V_9 -> V_7 , & V_97 ,
V_92 , NULL ) ;
F_47 ( & V_9 -> V_4 ,
& V_98 ) ;
F_48 ( V_91 , & V_9 -> V_4 , & V_99 ,
V_100 ) ;
F_49 ( & V_9 -> V_4 , & V_9 -> V_7 ) ;
return 0 ;
}
static bool F_50 ( struct V_101 * V_50 , unsigned int V_102 )
{
return ( V_102 % 4 == 0 ) && ( V_102 <= 0xdc ) ;
}
static const int F_51 ( struct V_103 * V_104 )
{
const char * V_105 ;
int V_10 , V_106 ;
V_10 = F_52 ( V_104 , L_7 , & V_105 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_106 = 0 ; V_106 < F_53 ( V_107 ) ; V_106 ++ )
if ( ! strcasecmp ( V_105 , V_107 [ V_106 ] ) )
return V_106 ;
return - V_108 ;
}
static int F_54 ( struct V_101 * V_50 , struct V_101 * V_109 , void * V_69 )
{
struct V_110 * V_111 = F_55 ( V_50 ) ;
struct V_90 * V_91 = V_69 ;
struct V_103 * V_104 = V_50 -> V_95 ;
struct V_103 * V_112 ;
struct V_1 * V_9 ;
struct V_113 * V_114 ;
void T_3 * V_80 ;
unsigned int V_25 ;
int V_68 ;
int V_10 ;
V_9 = F_56 ( V_50 , sizeof( * V_9 ) , V_115 ) ;
if ( ! V_9 )
return - V_116 ;
V_9 -> V_50 = V_50 ;
F_57 ( & V_9 -> V_117 ) ;
V_112 = F_58 ( V_104 , L_8 , 0 ) ;
if ( V_112 ) {
V_9 -> V_46 = F_59 ( V_112 ) ;
F_60 ( V_112 ) ;
}
V_9 -> V_17 = F_51 ( V_104 ) ;
if ( V_9 -> V_17 != V_18 ) {
F_28 ( V_50 , L_9 ) ;
return - V_108 ;
}
if ( V_9 -> V_17 == V_18 ) {
V_10 = F_61 ( V_104 , L_10 ,
& V_9 -> V_66 ) ;
if ( V_10 < 0 ) {
F_28 ( V_50 , L_11 ) ;
return V_10 ;
}
V_10 = F_61 ( V_104 , L_12 ,
& V_9 -> V_67 ) ;
if ( V_10 < 0 ) {
F_28 ( V_50 , L_13 ) ;
return V_10 ;
}
}
V_114 = F_62 ( V_111 , V_118 , 0 ) ;
V_80 = F_63 ( V_50 , V_114 ) ;
if ( F_41 ( V_80 ) )
return F_42 ( V_80 ) ;
V_119 . V_120 = V_9 ;
V_9 -> V_13 = F_64 ( V_50 , L_14 , V_80 ,
& V_119 ) ;
if ( F_41 ( V_9 -> V_13 ) ) {
F_28 ( V_50 , L_15 ,
F_42 ( V_9 -> V_13 ) ) ;
return F_42 ( V_9 -> V_13 ) ;
}
V_68 = F_65 ( V_111 , 0 ) ;
if ( V_68 < 0 ) {
F_28 ( V_50 , L_16 ) ;
return V_68 ;
}
V_10 = F_66 ( V_50 , V_68 , NULL ,
F_33 , V_121 ,
L_17 , V_9 ) ;
if ( V_10 < 0 ) {
F_28 ( V_50 , L_18 , V_10 ) ;
return V_10 ;
}
V_9 -> V_122 = F_67 ( V_50 , L_19 ) ;
if ( ! F_41 ( V_9 -> V_122 ) ) {
V_10 = F_68 ( V_9 -> V_122 , 2750000 , 2750000 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_69 ( V_9 -> V_122 ) ;
if ( V_10 )
return V_10 ;
}
V_9 -> V_12 = F_70 ( V_50 , L_14 ) ;
if ( F_41 ( V_9 -> V_12 ) ) {
F_28 ( V_50 , L_20 ,
F_42 ( V_9 -> V_12 ) ) ;
return F_42 ( V_9 -> V_12 ) ;
}
V_9 -> V_57 = F_70 ( V_50 , L_21 ) ;
if ( F_41 ( V_9 -> V_57 ) ) {
F_28 ( V_50 , L_22 ,
F_42 ( V_9 -> V_57 ) ) ;
return F_42 ( V_9 -> V_57 ) ;
}
V_10 = F_38 ( V_9 , V_80 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_34 ( V_9 -> V_13 , V_14 , & V_25 ) ;
if ( V_10 < 0 ) {
F_28 ( V_50 , L_23 ,
V_10 ) ;
return V_10 ;
}
if ( V_25 != 0x00100000 ) {
F_28 ( V_50 , L_24 ) ;
return - V_123 ;
}
V_10 = F_9 ( V_9 -> V_13 , V_124 , 0 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_43 ( V_91 , V_9 ) ;
if ( V_10 )
return V_10 ;
F_71 ( V_50 , V_9 ) ;
return 0 ;
}
static void F_72 ( struct V_101 * V_50 , struct V_101 * V_109 ,
void * V_69 )
{
struct V_1 * V_9 = F_73 ( V_50 ) ;
if ( ! F_41 ( V_9 -> V_122 ) )
F_74 ( V_9 -> V_122 ) ;
}
static int F_75 ( struct V_110 * V_111 )
{
return F_76 ( & V_111 -> V_50 , & V_125 ) ;
}
static int F_77 ( struct V_110 * V_111 )
{
F_78 ( & V_111 -> V_50 , & V_125 ) ;
return 0 ;
}
