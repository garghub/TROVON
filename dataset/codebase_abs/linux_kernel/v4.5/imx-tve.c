static void F_1 ( void * V_1 )
__acquires( &tve->lock
static void F_2 ( void * V_1 )
__releases( &tve->lock
static void F_3 ( struct V_2 * V_3 )
{
int V_4 ;
if ( ! V_3 -> V_5 ) {
V_3 -> V_5 = true ;
F_4 ( V_3 -> V_6 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_8 ,
V_9 | V_10 ,
V_9 | V_10 ) ;
}
F_6 ( V_3 -> V_7 , V_11 , 0xffffffff ) ;
if ( V_3 -> V_12 == V_13 )
F_6 ( V_3 -> V_7 , V_14 , 0 ) ;
else
F_6 ( V_3 -> V_7 , V_14 ,
V_15 |
V_16 |
V_17 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
int V_4 ;
if ( V_3 -> V_5 ) {
V_3 -> V_5 = false ;
V_4 = F_5 ( V_3 -> V_7 , V_8 ,
V_9 | V_10 , 0 ) ;
F_8 ( V_3 -> V_6 ) ;
}
}
static int F_9 ( struct V_2 * V_3 )
{
return - V_18 ;
}
static int F_10 ( struct V_2 * V_3 )
{
unsigned int V_19 ;
unsigned int V_20 ;
int V_4 ;
V_4 = F_5 ( V_3 -> V_7 , V_21 ,
V_22 , 0x0a ) ;
if ( V_4 )
return V_4 ;
V_4 = F_5 ( V_3 -> V_7 , V_23 ,
V_22 , 0x0a ) ;
if ( V_4 )
return V_4 ;
V_4 = F_5 ( V_3 -> V_7 , V_24 ,
V_22 , 0x0a ) ;
if ( V_4 )
return V_4 ;
V_19 = V_25 | V_26 ;
V_20 = V_27 | V_28 ;
V_19 |= V_29 | V_30 ;
V_20 |= V_31 | 0 ;
V_19 |= V_32 | V_33 ;
V_20 |= V_34 | V_33 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_19 , V_20 ) ;
if ( V_4 )
return V_4 ;
return F_5 ( V_3 -> V_7 , V_35 ,
V_36 , 1 ) ;
}
static enum V_37 F_11 (
struct V_38 * V_39 , bool V_40 )
{
return V_41 ;
}
static int F_12 ( struct V_38 * V_39 )
{
struct V_2 * V_3 = F_13 ( V_39 ) ;
struct V_42 * V_42 ;
int V_4 = 0 ;
if ( ! V_3 -> V_43 )
return 0 ;
V_42 = F_14 ( V_39 , V_3 -> V_43 ) ;
if ( V_42 ) {
F_15 ( V_39 , V_42 ) ;
V_4 = F_16 ( V_39 , V_42 ) ;
F_17 ( V_42 ) ;
}
return V_4 ;
}
static int F_18 ( struct V_38 * V_39 ,
struct V_44 * V_12 )
{
struct V_2 * V_3 = F_13 ( V_39 ) ;
unsigned long V_45 ;
V_45 = F_19 ( V_3 -> V_6 , 2000UL * V_12 -> clock ) / 2000 ;
if ( V_45 == V_12 -> clock )
return V_46 ;
V_45 = F_19 ( V_3 -> V_6 , 1000UL * V_12 -> clock ) / 1000 ;
if ( V_45 == V_12 -> clock )
return V_46 ;
F_20 ( V_3 -> V_47 , L_1 ,
V_12 -> V_48 , V_12 -> V_49 ) ;
return V_50 ;
}
static struct V_51 * F_21 (
struct V_38 * V_39 )
{
struct V_2 * V_3 = F_13 ( V_39 ) ;
return & V_3 -> V_52 ;
}
static void F_22 ( struct V_51 * V_52 , int V_12 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
int V_4 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 ,
V_32 , V_53 ) ;
if ( V_4 < 0 )
F_24 ( V_3 -> V_47 , L_2 , V_4 ) ;
}
static bool F_25 ( struct V_51 * V_52 ,
const struct V_44 * V_12 ,
struct V_44 * V_54 )
{
return true ;
}
static void F_26 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
F_7 ( V_3 ) ;
switch ( V_3 -> V_12 ) {
case V_13 :
F_27 ( V_52 , V_55 ,
V_3 -> V_56 , V_3 -> V_57 ) ;
break;
case V_58 :
F_28 ( V_52 , V_59 ) ;
break;
}
}
static void F_29 ( struct V_51 * V_52 ,
struct V_44 * V_60 ,
struct V_44 * V_12 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
unsigned long V_61 ;
unsigned long V_45 ;
int div = 1 ;
int V_4 ;
V_45 = 2000UL * V_12 -> clock ;
F_30 ( V_3 -> V_6 , V_45 ) ;
V_61 = F_31 ( V_3 -> V_6 ) ;
if ( V_61 >= V_45 )
div = 2 ;
F_30 ( V_3 -> V_62 , V_61 / div ) ;
V_4 = F_32 ( V_3 -> V_63 , V_3 -> V_62 ) ;
if ( V_4 < 0 ) {
F_24 ( V_3 -> V_47 , L_3 ,
V_4 ) ;
}
if ( V_3 -> V_12 == V_13 )
V_4 = F_10 ( V_3 ) ;
else
V_4 = F_9 ( V_3 ) ;
if ( V_4 )
F_24 ( V_3 -> V_47 , L_4 , V_4 ) ;
}
static void F_33 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
F_3 ( V_3 ) ;
}
static void F_34 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
F_7 ( V_3 ) ;
}
static T_1 F_35 ( int V_64 , void * V_65 )
{
struct V_2 * V_3 = V_65 ;
unsigned int V_20 ;
F_36 ( V_3 -> V_7 , V_11 , & V_20 ) ;
F_6 ( V_3 -> V_7 , V_11 , 0xffffffff ) ;
return V_66 ;
}
static unsigned long F_37 ( struct V_67 * V_68 ,
unsigned long V_69 )
{
struct V_2 * V_3 = F_38 ( V_68 , struct V_2 , V_70 ) ;
unsigned int V_20 ;
int V_4 ;
V_4 = F_36 ( V_3 -> V_7 , V_8 , & V_20 ) ;
if ( V_4 < 0 )
return 0 ;
switch ( V_20 & V_71 ) {
case V_72 :
return V_69 / 4 ;
case V_73 :
return V_69 / 2 ;
case V_74 :
default:
return V_69 ;
}
return 0 ;
}
static long F_39 ( struct V_67 * V_68 , unsigned long V_45 ,
unsigned long * V_75 )
{
unsigned long div ;
div = * V_75 / V_45 ;
if ( div >= 4 )
return * V_75 / 4 ;
else if ( div >= 2 )
return * V_75 / 2 ;
return * V_75 ;
}
static int F_40 ( struct V_67 * V_68 , unsigned long V_45 ,
unsigned long V_69 )
{
struct V_2 * V_3 = F_38 ( V_68 , struct V_2 , V_70 ) ;
unsigned long div ;
T_2 V_20 ;
int V_4 ;
div = V_69 / V_45 ;
if ( div >= 4 )
V_20 = V_72 ;
else if ( div >= 2 )
V_20 = V_73 ;
else
V_20 = V_74 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 ,
V_71 , V_20 ) ;
if ( V_4 < 0 ) {
F_24 ( V_3 -> V_47 , L_5 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , void T_3 * V_76 )
{
const char * V_77 [ 1 ] ;
struct V_78 V_79 = {
. V_80 = L_6 ,
. V_81 = & V_82 ,
. V_83 = 1 ,
. V_84 = 0 ,
} ;
V_77 [ 0 ] = F_42 ( V_3 -> V_6 ) ;
V_79 . V_85 = ( const char * * ) & V_77 ;
V_3 -> V_70 . V_79 = & V_79 ;
V_3 -> V_62 = F_43 ( V_3 -> V_47 , & V_3 -> V_70 ) ;
if ( F_44 ( V_3 -> V_62 ) ) {
F_24 ( V_3 -> V_47 , L_7 ,
F_45 ( V_3 -> V_62 ) ) ;
return F_45 ( V_3 -> V_62 ) ;
}
return 0 ;
}
static int F_46 ( struct V_86 * V_87 , struct V_2 * V_3 )
{
int V_88 ;
int V_4 ;
V_88 = V_3 -> V_12 == V_13 ?
V_89 : V_90 ;
V_4 = F_47 ( V_87 , & V_3 -> V_52 ,
V_3 -> V_47 -> V_91 ) ;
if ( V_4 )
return V_4 ;
F_48 ( & V_3 -> V_52 , & V_92 ) ;
F_49 ( V_87 , & V_3 -> V_52 , & V_93 ,
V_88 , NULL ) ;
F_50 ( & V_3 -> V_39 ,
& V_94 ) ;
F_51 ( V_87 , & V_3 -> V_39 , & V_95 ,
V_96 ) ;
F_52 ( & V_3 -> V_39 , & V_3 -> V_52 ) ;
return 0 ;
}
static bool F_53 ( struct V_97 * V_47 , unsigned int V_98 )
{
return ( V_98 % 4 == 0 ) && ( V_98 <= 0xdc ) ;
}
static const int F_54 ( struct V_99 * V_100 )
{
const char * V_101 ;
int V_4 , V_102 ;
V_4 = F_55 ( V_100 , L_8 , & V_101 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_102 = 0 ; V_102 < F_56 ( V_103 ) ; V_102 ++ )
if ( ! strcasecmp ( V_101 , V_103 [ V_102 ] ) )
return V_102 ;
return - V_104 ;
}
static int F_57 ( struct V_97 * V_47 , struct V_97 * V_105 , void * V_65 )
{
struct V_106 * V_107 = F_58 ( V_47 ) ;
struct V_86 * V_87 = V_65 ;
struct V_99 * V_100 = V_47 -> V_91 ;
struct V_99 * V_108 ;
struct V_2 * V_3 ;
struct V_109 * V_110 ;
void T_3 * V_76 ;
unsigned int V_20 ;
int V_64 ;
int V_4 ;
V_3 = F_59 ( V_47 , sizeof( * V_3 ) , V_111 ) ;
if ( ! V_3 )
return - V_112 ;
V_3 -> V_47 = V_47 ;
F_60 ( & V_3 -> V_113 ) ;
V_108 = F_61 ( V_100 , L_9 , 0 ) ;
if ( V_108 ) {
V_3 -> V_43 = F_62 ( V_108 ) ;
F_63 ( V_108 ) ;
}
V_3 -> V_12 = F_54 ( V_100 ) ;
if ( V_3 -> V_12 != V_13 ) {
F_24 ( V_47 , L_10 ) ;
return - V_104 ;
}
if ( V_3 -> V_12 == V_13 ) {
V_4 = F_64 ( V_100 , L_11 ,
& V_3 -> V_56 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_12 ) ;
return V_4 ;
}
V_4 |= F_64 ( V_100 , L_13 ,
& V_3 -> V_57 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_12 ) ;
return V_4 ;
}
}
V_110 = F_65 ( V_107 , V_114 , 0 ) ;
V_76 = F_66 ( V_47 , V_110 ) ;
if ( F_44 ( V_76 ) )
return F_45 ( V_76 ) ;
V_115 . V_116 = V_3 ;
V_3 -> V_7 = F_67 ( V_47 , L_14 , V_76 ,
& V_115 ) ;
if ( F_44 ( V_3 -> V_7 ) ) {
F_24 ( V_47 , L_15 ,
F_45 ( V_3 -> V_7 ) ) ;
return F_45 ( V_3 -> V_7 ) ;
}
V_64 = F_68 ( V_107 , 0 ) ;
if ( V_64 < 0 ) {
F_24 ( V_47 , L_16 ) ;
return V_64 ;
}
V_4 = F_69 ( V_47 , V_64 , NULL ,
F_35 , V_117 ,
L_17 , V_3 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_18 , V_4 ) ;
return V_4 ;
}
V_3 -> V_118 = F_70 ( V_47 , L_19 ) ;
if ( ! F_44 ( V_3 -> V_118 ) ) {
F_71 ( V_3 -> V_118 , 2750000 , 2750000 ) ;
V_4 = F_72 ( V_3 -> V_118 ) ;
if ( V_4 )
return V_4 ;
}
V_3 -> V_6 = F_73 ( V_47 , L_14 ) ;
if ( F_44 ( V_3 -> V_6 ) ) {
F_24 ( V_47 , L_20 ,
F_45 ( V_3 -> V_6 ) ) ;
return F_45 ( V_3 -> V_6 ) ;
}
V_3 -> V_63 = F_73 ( V_47 , L_21 ) ;
if ( F_44 ( V_3 -> V_63 ) ) {
F_24 ( V_47 , L_22 ,
F_45 ( V_3 -> V_63 ) ) ;
return F_45 ( V_3 -> V_63 ) ;
}
V_4 = F_41 ( V_3 , V_76 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_36 ( V_3 -> V_7 , V_8 , & V_20 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_23 ,
V_4 ) ;
return V_4 ;
}
if ( V_20 != 0x00100000 ) {
F_24 ( V_47 , L_24 ) ;
return - V_119 ;
}
V_4 = F_6 ( V_3 -> V_7 , V_120 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_46 ( V_87 , V_3 ) ;
if ( V_4 )
return V_4 ;
F_74 ( V_47 , V_3 ) ;
return 0 ;
}
static void F_75 ( struct V_97 * V_47 , struct V_97 * V_105 ,
void * V_65 )
{
struct V_2 * V_3 = F_76 ( V_47 ) ;
V_3 -> V_39 . V_121 -> V_122 ( & V_3 -> V_39 ) ;
V_3 -> V_52 . V_121 -> V_122 ( & V_3 -> V_52 ) ;
if ( ! F_44 ( V_3 -> V_118 ) )
F_77 ( V_3 -> V_118 ) ;
}
static int F_78 ( struct V_106 * V_107 )
{
return F_79 ( & V_107 -> V_47 , & V_123 ) ;
}
static int F_80 ( struct V_106 * V_107 )
{
F_81 ( & V_107 -> V_47 , & V_123 ) ;
return 0 ;
}
