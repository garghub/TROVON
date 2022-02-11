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
V_4 = F_5 ( V_3 -> V_7 , V_23 ,
V_22 , 0x0a ) ;
V_4 = F_5 ( V_3 -> V_7 , V_24 ,
V_22 , 0x0a ) ;
V_19 = V_25 | V_26 ;
V_20 = V_27 | V_28 ;
V_19 |= V_29 | V_30 ;
V_20 |= V_31 | 0 ;
V_19 |= V_32 | V_33 ;
V_20 |= V_34 | V_33 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_19 , V_20 ) ;
if ( V_4 < 0 ) {
F_11 ( V_3 -> V_35 , L_1 , V_4 ) ;
return V_4 ;
}
V_4 = F_5 ( V_3 -> V_7 , V_36 ,
V_37 , 1 ) ;
return 0 ;
}
static enum V_38 F_12 (
struct V_39 * V_40 , bool V_41 )
{
return V_42 ;
}
static void F_13 ( struct V_39 * V_40 )
{
}
static int F_14 ( struct V_39 * V_40 )
{
struct V_2 * V_3 = F_15 ( V_40 ) ;
struct V_43 * V_43 ;
int V_4 = 0 ;
if ( ! V_3 -> V_44 )
return 0 ;
V_43 = F_16 ( V_40 , V_3 -> V_44 ) ;
if ( V_43 ) {
F_17 ( V_40 , V_43 ) ;
V_4 = F_18 ( V_40 , V_43 ) ;
F_19 ( V_43 ) ;
}
return V_4 ;
}
static int F_20 ( struct V_39 * V_40 ,
struct V_45 * V_12 )
{
struct V_2 * V_3 = F_15 ( V_40 ) ;
unsigned long V_46 ;
V_46 = F_21 ( V_3 -> V_6 , 2000UL * V_12 -> clock ) / 2000 ;
if ( V_46 == V_12 -> clock )
return V_47 ;
V_46 = F_21 ( V_3 -> V_6 , 1000UL * V_12 -> clock ) / 1000 ;
if ( V_46 == V_12 -> clock )
return V_47 ;
F_22 ( V_3 -> V_35 , L_2 ,
V_12 -> V_48 , V_12 -> V_49 ) ;
return V_50 ;
}
static struct V_51 * F_23 (
struct V_39 * V_40 )
{
struct V_2 * V_3 = F_15 ( V_40 ) ;
return & V_3 -> V_52 ;
}
static void F_24 ( struct V_51 * V_52 , int V_12 )
{
struct V_2 * V_3 = F_25 ( V_52 ) ;
int V_4 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 ,
V_32 , V_53 ) ;
if ( V_4 < 0 )
F_11 ( V_3 -> V_35 , L_3 , V_4 ) ;
}
static bool F_26 ( struct V_51 * V_52 ,
const struct V_45 * V_12 ,
struct V_45 * V_54 )
{
return true ;
}
static void F_27 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_25 ( V_52 ) ;
F_7 ( V_3 ) ;
switch ( V_3 -> V_12 ) {
case V_13 :
F_28 ( V_52 -> V_55 ,
V_56 , V_57 ,
V_3 -> V_58 , V_3 -> V_59 ) ;
break;
case V_60 :
F_29 ( V_52 -> V_55 , V_61 ,
V_62 ) ;
break;
}
}
static void F_30 ( struct V_51 * V_52 ,
struct V_45 * V_12 ,
struct V_45 * V_54 )
{
struct V_2 * V_3 = F_25 ( V_52 ) ;
unsigned long V_63 ;
unsigned long V_46 ;
int div = 1 ;
int V_4 ;
V_46 = 2000UL * V_12 -> clock ;
F_31 ( V_3 -> V_6 , V_46 ) ;
V_63 = F_32 ( V_3 -> V_6 ) ;
if ( V_63 >= V_46 )
div = 2 ;
F_31 ( V_3 -> V_64 , V_63 / div ) ;
V_4 = F_33 ( V_3 -> V_65 , V_3 -> V_64 ) ;
if ( V_4 < 0 ) {
F_11 ( V_3 -> V_35 , L_4 ,
V_4 ) ;
}
if ( V_3 -> V_12 == V_13 )
F_10 ( V_3 ) ;
else
F_9 ( V_3 ) ;
}
static void F_34 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_25 ( V_52 ) ;
F_3 ( V_3 ) ;
}
static void F_35 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_25 ( V_52 ) ;
F_7 ( V_3 ) ;
}
static void F_36 ( struct V_51 * V_52 )
{
}
static T_1 F_37 ( int V_66 , void * V_67 )
{
struct V_2 * V_3 = V_67 ;
unsigned int V_20 ;
F_38 ( V_3 -> V_7 , V_11 , & V_20 ) ;
F_6 ( V_3 -> V_7 , V_11 , 0xffffffff ) ;
return V_68 ;
}
static unsigned long F_39 ( struct V_69 * V_70 ,
unsigned long V_71 )
{
struct V_2 * V_3 = F_40 ( V_70 , struct V_2 , V_72 ) ;
unsigned int V_20 ;
int V_4 ;
V_4 = F_38 ( V_3 -> V_7 , V_8 , & V_20 ) ;
if ( V_4 < 0 )
return 0 ;
switch ( V_20 & V_73 ) {
case V_74 :
return V_71 / 4 ;
case V_75 :
return V_71 / 2 ;
case V_76 :
default:
return V_71 ;
}
return 0 ;
}
static long F_41 ( struct V_69 * V_70 , unsigned long V_46 ,
unsigned long * V_77 )
{
unsigned long div ;
div = * V_77 / V_46 ;
if ( div >= 4 )
return * V_77 / 4 ;
else if ( div >= 2 )
return * V_77 / 2 ;
else
return * V_77 ;
}
static int F_42 ( struct V_69 * V_70 , unsigned long V_46 ,
unsigned long V_71 )
{
struct V_2 * V_3 = F_40 ( V_70 , struct V_2 , V_72 ) ;
unsigned long div ;
T_2 V_20 ;
int V_4 ;
div = V_71 / V_46 ;
if ( div >= 4 )
V_20 = V_74 ;
else if ( div >= 2 )
V_20 = V_75 ;
else
V_20 = V_76 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 ,
V_73 , V_20 ) ;
if ( V_4 < 0 ) {
F_11 ( V_3 -> V_35 , L_5 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , void T_3 * V_78 )
{
const char * V_79 [ 1 ] ;
struct V_80 V_81 = {
. V_82 = L_6 ,
. V_83 = & V_84 ,
. V_85 = 1 ,
. V_86 = 0 ,
} ;
V_79 [ 0 ] = F_44 ( V_3 -> V_6 ) ;
V_81 . V_87 = ( const char * * ) & V_79 ;
V_3 -> V_72 . V_81 = & V_81 ;
V_3 -> V_64 = F_45 ( V_3 -> V_35 , & V_3 -> V_72 ) ;
if ( F_46 ( V_3 -> V_64 ) ) {
F_11 ( V_3 -> V_35 , L_7 ,
F_47 ( V_3 -> V_64 ) ) ;
return F_47 ( V_3 -> V_64 ) ;
}
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
int V_4 ;
V_3 -> V_40 . V_88 = & V_89 ;
V_3 -> V_52 . V_88 = & V_90 ;
V_3 -> V_52 . V_91 = V_92 ;
V_3 -> V_40 . V_93 = V_94 ;
F_49 ( & V_3 -> V_52 , & V_95 ) ;
V_4 = F_50 ( & V_3 -> V_52 , & V_3 -> V_96 ,
V_97 ) ;
if ( V_4 ) {
F_11 ( V_3 -> V_35 , L_8 , V_4 ) ;
return V_4 ;
}
F_51 ( & V_3 -> V_40 ,
& V_98 ) ;
V_4 = F_52 ( & V_3 -> V_40 ,
& V_3 -> V_99 , V_97 ) ;
if ( V_4 ) {
F_53 ( V_3 -> V_96 ) ;
F_11 ( V_3 -> V_35 , L_9 , V_4 ) ;
return V_4 ;
}
F_54 ( & V_3 -> V_40 , & V_3 -> V_52 ) ;
return 0 ;
}
static bool F_55 ( struct V_100 * V_35 , unsigned int V_101 )
{
return ( V_101 % 4 == 0 ) && ( V_101 <= 0xdc ) ;
}
const int F_56 ( struct V_102 * V_103 )
{
const char * V_104 ;
int V_4 , V_105 ;
V_4 = F_57 ( V_103 , L_10 , & V_104 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_105 = 0 ; V_105 < F_58 ( V_106 ) ; V_105 ++ )
if ( ! strcasecmp ( V_104 , V_106 [ V_105 ] ) )
return V_105 ;
return - V_107 ;
}
static int F_59 ( struct V_108 * V_109 )
{
struct V_102 * V_103 = V_109 -> V_35 . V_110 ;
struct V_102 * V_111 ;
struct V_2 * V_3 ;
struct V_112 * V_113 ;
void T_3 * V_78 ;
unsigned int V_20 ;
int V_66 ;
int V_4 ;
V_3 = F_60 ( & V_109 -> V_35 , sizeof( * V_3 ) , V_114 ) ;
if ( ! V_3 )
return - V_115 ;
V_3 -> V_35 = & V_109 -> V_35 ;
F_61 ( & V_3 -> V_116 ) ;
V_111 = F_62 ( V_103 , L_11 , 0 ) ;
if ( V_111 ) {
V_3 -> V_44 = F_63 ( V_111 ) ;
F_64 ( V_111 ) ;
}
V_3 -> V_12 = F_56 ( V_103 ) ;
if ( V_3 -> V_12 != V_13 ) {
F_11 ( & V_109 -> V_35 , L_12 ) ;
return - V_107 ;
}
if ( V_3 -> V_12 == V_13 ) {
V_4 = F_65 ( V_103 , L_13 ,
& V_3 -> V_58 ) ;
if ( V_4 < 0 ) {
F_11 ( & V_109 -> V_35 , L_14 ) ;
return V_4 ;
}
V_4 |= F_65 ( V_103 , L_15 ,
& V_3 -> V_59 ) ;
if ( V_4 < 0 ) {
F_11 ( & V_109 -> V_35 , L_14 ) ;
return V_4 ;
}
}
V_113 = F_66 ( V_109 , V_117 , 0 ) ;
V_78 = F_67 ( & V_109 -> V_35 , V_113 ) ;
if ( F_46 ( V_78 ) )
return F_47 ( V_78 ) ;
V_118 . V_119 = V_3 ;
V_3 -> V_7 = F_68 ( & V_109 -> V_35 , L_16 , V_78 ,
& V_118 ) ;
if ( F_46 ( V_3 -> V_7 ) ) {
F_11 ( & V_109 -> V_35 , L_17 ,
F_47 ( V_3 -> V_7 ) ) ;
return F_47 ( V_3 -> V_7 ) ;
}
V_66 = F_69 ( V_109 , 0 ) ;
if ( V_66 < 0 ) {
F_11 ( & V_109 -> V_35 , L_18 ) ;
return V_66 ;
}
V_4 = F_70 ( & V_109 -> V_35 , V_66 , NULL ,
F_37 , V_120 ,
L_19 , V_3 ) ;
if ( V_4 < 0 ) {
F_11 ( & V_109 -> V_35 , L_20 , V_4 ) ;
return V_4 ;
}
V_3 -> V_121 = F_71 ( & V_109 -> V_35 , L_21 ) ;
if ( ! F_46 ( V_3 -> V_121 ) ) {
F_72 ( V_3 -> V_121 , 2750000 , 2750000 ) ;
V_4 = F_73 ( V_3 -> V_121 ) ;
if ( V_4 )
return V_4 ;
}
V_3 -> V_6 = F_74 ( & V_109 -> V_35 , L_16 ) ;
if ( F_46 ( V_3 -> V_6 ) ) {
F_11 ( & V_109 -> V_35 , L_22 ,
F_47 ( V_3 -> V_6 ) ) ;
return F_47 ( V_3 -> V_6 ) ;
}
V_3 -> V_65 = F_74 ( & V_109 -> V_35 , L_23 ) ;
if ( F_46 ( V_3 -> V_65 ) ) {
F_11 ( & V_109 -> V_35 , L_24 ,
F_47 ( V_3 -> V_65 ) ) ;
return F_47 ( V_3 -> V_65 ) ;
}
V_4 = F_43 ( V_3 , V_78 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_38 ( V_3 -> V_7 , V_8 , & V_20 ) ;
if ( V_4 < 0 ) {
F_11 ( & V_109 -> V_35 , L_25 , V_4 ) ;
return V_4 ;
}
if ( V_20 != 0x00100000 ) {
F_11 ( & V_109 -> V_35 , L_26 ) ;
return - V_122 ;
}
V_4 = F_6 ( V_3 -> V_7 , V_123 , 0 ) ;
V_4 = F_48 ( V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_75 ( V_3 -> V_96 , V_103 ) ;
F_76 ( V_109 , V_3 ) ;
return 0 ;
}
static int F_77 ( struct V_108 * V_109 )
{
struct V_2 * V_3 = F_78 ( V_109 ) ;
struct V_39 * V_40 = & V_3 -> V_40 ;
struct V_51 * V_52 = & V_3 -> V_52 ;
F_79 ( V_40 , V_52 ) ;
F_80 ( V_3 -> V_99 ) ;
F_53 ( V_3 -> V_96 ) ;
if ( ! F_46 ( V_3 -> V_121 ) )
F_81 ( V_3 -> V_121 ) ;
return 0 ;
}
