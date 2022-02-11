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
static int F_14 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_42 * V_42 ;
int V_10 = 0 ;
if ( ! V_9 -> V_43 )
return 0 ;
V_42 = F_15 ( V_4 , V_9 -> V_43 ) ;
if ( V_42 ) {
F_16 ( V_4 , V_42 ) ;
V_10 = F_17 ( V_4 , V_42 ) ;
F_18 ( V_42 ) ;
}
return V_10 ;
}
static int F_19 ( struct V_2 * V_4 ,
struct V_44 * V_17 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
unsigned long V_45 ;
V_45 = F_20 ( V_9 -> V_12 , 2000UL * V_17 -> clock ) / 2000 ;
if ( V_45 == V_17 -> clock )
return V_46 ;
V_45 = F_20 ( V_9 -> V_12 , 1000UL * V_17 -> clock ) / 1000 ;
if ( V_45 == V_17 -> clock )
return V_46 ;
F_21 ( V_9 -> V_47 , L_1 ,
V_17 -> V_48 , V_17 -> V_49 ) ;
return V_50 ;
}
static struct V_5 * F_22 (
struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
return & V_9 -> V_7 ;
}
static void F_23 ( struct V_5 * V_7 ,
struct V_44 * V_51 ,
struct V_44 * V_17 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
unsigned long V_52 ;
unsigned long V_45 ;
int div = 1 ;
int V_10 ;
V_45 = 2000UL * V_17 -> clock ;
F_24 ( V_9 -> V_12 , V_45 ) ;
V_52 = F_25 ( V_9 -> V_12 ) ;
if ( V_52 >= V_45 )
div = 2 ;
F_24 ( V_9 -> V_53 , V_52 / div ) ;
V_10 = F_26 ( V_9 -> V_54 , V_9 -> V_53 ) ;
if ( V_10 < 0 ) {
F_27 ( V_9 -> V_47 , L_2 ,
V_10 ) ;
}
F_8 ( V_9 -> V_13 , V_14 ,
V_55 , V_55 ) ;
if ( V_9 -> V_17 == V_18 )
V_10 = F_13 ( V_9 ) ;
else
V_10 = F_12 ( V_9 ) ;
if ( V_10 )
F_27 ( V_9 -> V_47 , L_3 , V_10 ) ;
}
static void F_28 ( struct V_5 * V_7 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
F_6 ( V_9 ) ;
}
static void F_29 ( struct V_5 * V_7 )
{
struct V_1 * V_9 = F_3 ( V_7 ) ;
F_10 ( V_9 ) ;
}
static int F_30 ( struct V_5 * V_7 ,
struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_60 = F_31 ( V_57 ) ;
struct V_1 * V_9 = F_3 ( V_7 ) ;
V_60 -> V_61 = V_62 ;
V_60 -> V_63 = V_9 -> V_63 ;
V_60 -> V_64 = V_9 -> V_64 ;
return 0 ;
}
static T_1 F_32 ( int V_65 , void * V_66 )
{
struct V_1 * V_9 = V_66 ;
unsigned int V_25 ;
F_33 ( V_9 -> V_13 , V_16 , & V_25 ) ;
F_9 ( V_9 -> V_13 , V_16 , 0xffffffff ) ;
return V_67 ;
}
static unsigned long F_34 ( struct V_68 * V_69 ,
unsigned long V_70 )
{
struct V_1 * V_9 = F_2 ( V_69 , struct V_1 , V_71 ) ;
unsigned int V_25 ;
int V_10 ;
V_10 = F_33 ( V_9 -> V_13 , V_14 , & V_25 ) ;
if ( V_10 < 0 )
return 0 ;
switch ( V_25 & V_72 ) {
case V_73 :
return V_70 / 4 ;
case V_74 :
return V_70 / 2 ;
case V_75 :
default:
return V_70 ;
}
return 0 ;
}
static long F_35 ( struct V_68 * V_69 , unsigned long V_45 ,
unsigned long * V_76 )
{
unsigned long div ;
div = * V_76 / V_45 ;
if ( div >= 4 )
return * V_76 / 4 ;
else if ( div >= 2 )
return * V_76 / 2 ;
return * V_76 ;
}
static int F_36 ( struct V_68 * V_69 , unsigned long V_45 ,
unsigned long V_70 )
{
struct V_1 * V_9 = F_2 ( V_69 , struct V_1 , V_71 ) ;
unsigned long div ;
T_2 V_25 ;
int V_10 ;
div = V_70 / V_45 ;
if ( div >= 4 )
V_25 = V_73 ;
else if ( div >= 2 )
V_25 = V_74 ;
else
V_25 = V_75 ;
V_10 = F_8 ( V_9 -> V_13 , V_14 ,
V_72 , V_25 ) ;
if ( V_10 < 0 ) {
F_27 ( V_9 -> V_47 , L_4 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_9 , void T_3 * V_77 )
{
const char * V_78 [ 1 ] ;
struct V_79 V_80 = {
. V_81 = L_5 ,
. V_82 = & V_83 ,
. V_84 = 1 ,
. V_85 = 0 ,
} ;
V_78 [ 0 ] = F_38 ( V_9 -> V_12 ) ;
V_80 . V_86 = ( const char * * ) & V_78 ;
V_9 -> V_71 . V_80 = & V_80 ;
V_9 -> V_53 = F_39 ( V_9 -> V_47 , & V_9 -> V_71 ) ;
if ( F_40 ( V_9 -> V_53 ) ) {
F_27 ( V_9 -> V_47 , L_6 ,
F_41 ( V_9 -> V_53 ) ) ;
return F_41 ( V_9 -> V_53 ) ;
}
return 0 ;
}
static int F_42 ( struct V_87 * V_88 , struct V_1 * V_9 )
{
int V_89 ;
int V_10 ;
V_89 = V_9 -> V_17 == V_18 ?
V_90 : V_91 ;
V_10 = F_43 ( V_88 , & V_9 -> V_7 , V_9 -> V_47 -> V_92 ) ;
if ( V_10 )
return V_10 ;
F_44 ( & V_9 -> V_7 , & V_93 ) ;
F_45 ( V_88 , & V_9 -> V_7 , & V_94 ,
V_89 , NULL ) ;
F_46 ( & V_9 -> V_4 ,
& V_95 ) ;
F_47 ( V_88 , & V_9 -> V_4 , & V_96 ,
V_97 ) ;
F_48 ( & V_9 -> V_4 , & V_9 -> V_7 ) ;
return 0 ;
}
static bool F_49 ( struct V_98 * V_47 , unsigned int V_99 )
{
return ( V_99 % 4 == 0 ) && ( V_99 <= 0xdc ) ;
}
static const int F_50 ( struct V_100 * V_101 )
{
const char * V_102 ;
int V_10 , V_103 ;
V_10 = F_51 ( V_101 , L_7 , & V_102 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_103 = 0 ; V_103 < F_52 ( V_104 ) ; V_103 ++ )
if ( ! strcasecmp ( V_102 , V_104 [ V_103 ] ) )
return V_103 ;
return - V_105 ;
}
static int F_53 ( struct V_98 * V_47 , struct V_98 * V_106 , void * V_66 )
{
struct V_107 * V_108 = F_54 ( V_47 ) ;
struct V_87 * V_88 = V_66 ;
struct V_100 * V_101 = V_47 -> V_92 ;
struct V_100 * V_109 ;
struct V_1 * V_9 ;
struct V_110 * V_111 ;
void T_3 * V_77 ;
unsigned int V_25 ;
int V_65 ;
int V_10 ;
V_9 = F_55 ( V_47 , sizeof( * V_9 ) , V_112 ) ;
if ( ! V_9 )
return - V_113 ;
V_9 -> V_47 = V_47 ;
F_56 ( & V_9 -> V_114 ) ;
V_109 = F_57 ( V_101 , L_8 , 0 ) ;
if ( V_109 ) {
V_9 -> V_43 = F_58 ( V_109 ) ;
F_59 ( V_109 ) ;
}
V_9 -> V_17 = F_50 ( V_101 ) ;
if ( V_9 -> V_17 != V_18 ) {
F_27 ( V_47 , L_9 ) ;
return - V_105 ;
}
if ( V_9 -> V_17 == V_18 ) {
V_10 = F_60 ( V_101 , L_10 ,
& V_9 -> V_63 ) ;
if ( V_10 < 0 ) {
F_27 ( V_47 , L_11 ) ;
return V_10 ;
}
V_10 = F_60 ( V_101 , L_12 ,
& V_9 -> V_64 ) ;
if ( V_10 < 0 ) {
F_27 ( V_47 , L_13 ) ;
return V_10 ;
}
}
V_111 = F_61 ( V_108 , V_115 , 0 ) ;
V_77 = F_62 ( V_47 , V_111 ) ;
if ( F_40 ( V_77 ) )
return F_41 ( V_77 ) ;
V_116 . V_117 = V_9 ;
V_9 -> V_13 = F_63 ( V_47 , L_14 , V_77 ,
& V_116 ) ;
if ( F_40 ( V_9 -> V_13 ) ) {
F_27 ( V_47 , L_15 ,
F_41 ( V_9 -> V_13 ) ) ;
return F_41 ( V_9 -> V_13 ) ;
}
V_65 = F_64 ( V_108 , 0 ) ;
if ( V_65 < 0 ) {
F_27 ( V_47 , L_16 ) ;
return V_65 ;
}
V_10 = F_65 ( V_47 , V_65 , NULL ,
F_32 , V_118 ,
L_17 , V_9 ) ;
if ( V_10 < 0 ) {
F_27 ( V_47 , L_18 , V_10 ) ;
return V_10 ;
}
V_9 -> V_119 = F_66 ( V_47 , L_19 ) ;
if ( ! F_40 ( V_9 -> V_119 ) ) {
V_10 = F_67 ( V_9 -> V_119 , 2750000 , 2750000 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_68 ( V_9 -> V_119 ) ;
if ( V_10 )
return V_10 ;
}
V_9 -> V_12 = F_69 ( V_47 , L_14 ) ;
if ( F_40 ( V_9 -> V_12 ) ) {
F_27 ( V_47 , L_20 ,
F_41 ( V_9 -> V_12 ) ) ;
return F_41 ( V_9 -> V_12 ) ;
}
V_9 -> V_54 = F_69 ( V_47 , L_21 ) ;
if ( F_40 ( V_9 -> V_54 ) ) {
F_27 ( V_47 , L_22 ,
F_41 ( V_9 -> V_54 ) ) ;
return F_41 ( V_9 -> V_54 ) ;
}
V_10 = F_37 ( V_9 , V_77 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_33 ( V_9 -> V_13 , V_14 , & V_25 ) ;
if ( V_10 < 0 ) {
F_27 ( V_47 , L_23 ,
V_10 ) ;
return V_10 ;
}
if ( V_25 != 0x00100000 ) {
F_27 ( V_47 , L_24 ) ;
return - V_120 ;
}
V_10 = F_9 ( V_9 -> V_13 , V_121 , 0 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_42 ( V_88 , V_9 ) ;
if ( V_10 )
return V_10 ;
F_70 ( V_47 , V_9 ) ;
return 0 ;
}
static void F_71 ( struct V_98 * V_47 , struct V_98 * V_106 ,
void * V_66 )
{
struct V_1 * V_9 = F_72 ( V_47 ) ;
if ( ! F_40 ( V_9 -> V_119 ) )
F_73 ( V_9 -> V_119 ) ;
}
static int F_74 ( struct V_107 * V_108 )
{
return F_75 ( & V_108 -> V_47 , & V_122 ) ;
}
static int F_76 ( struct V_107 * V_108 )
{
F_77 ( & V_108 -> V_47 , & V_122 ) ;
return 0 ;
}
