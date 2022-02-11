static void F_1 ( void * V_1 )
__acquires( &tve->lock
static void F_2 ( void * V_1 )
__releases( &tve->lock
static void F_3 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
int V_5 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( ! V_3 -> V_7 ) {
V_3 -> V_7 = 1 ;
F_5 ( V_3 -> V_8 ) ;
V_5 = F_6 ( V_3 -> V_9 , V_10 ,
V_11 | V_12 ,
V_11 | V_12 ) ;
}
F_7 ( V_3 -> V_9 , V_13 , 0xffffffff ) ;
if ( V_3 -> V_14 == V_15 )
F_7 ( V_3 -> V_9 , V_16 , 0 ) ;
else
F_7 ( V_3 -> V_9 , V_16 ,
V_17 |
V_18 |
V_19 ) ;
F_8 ( & V_3 -> V_6 , V_4 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
int V_5 ;
F_4 ( & V_3 -> V_6 , V_4 ) ;
if ( V_3 -> V_7 ) {
V_3 -> V_7 = 0 ;
V_5 = F_6 ( V_3 -> V_9 , V_10 ,
V_11 | V_12 , 0 ) ;
F_10 ( V_3 -> V_8 ) ;
}
F_8 ( & V_3 -> V_6 , V_4 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
return - V_20 ;
}
static int F_12 ( struct V_2 * V_3 )
{
unsigned int V_21 ;
unsigned int V_22 ;
int V_5 ;
V_5 = F_6 ( V_3 -> V_9 , V_23 ,
V_24 , 0x0a ) ;
V_5 = F_6 ( V_3 -> V_9 , V_25 ,
V_24 , 0x0a ) ;
V_5 = F_6 ( V_3 -> V_9 , V_26 ,
V_24 , 0x0a ) ;
V_21 = V_27 | V_28 ;
V_22 = V_29 | V_30 ;
V_21 |= V_31 | V_32 ;
V_22 |= V_33 | 0 ;
V_21 |= V_34 | V_35 ;
V_22 |= V_36 | V_35 ;
V_5 = F_6 ( V_3 -> V_9 , V_10 , V_21 , V_22 ) ;
if ( V_5 < 0 ) {
F_13 ( V_3 -> V_37 , L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_6 ( V_3 -> V_9 , V_38 ,
V_39 , 1 ) ;
return 0 ;
}
static enum V_40 F_14 (
struct V_41 * V_42 , bool V_43 )
{
return V_44 ;
}
static void F_15 ( struct V_41 * V_42 )
{
}
static int F_16 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = F_17 ( V_42 ) ;
struct V_45 * V_45 ;
int V_5 = 0 ;
if ( ! V_3 -> V_46 )
return 0 ;
V_45 = F_18 ( V_42 , V_3 -> V_46 ) ;
if ( V_45 ) {
F_19 ( V_42 , V_45 ) ;
V_5 = F_20 ( V_42 , V_45 ) ;
F_21 ( V_45 ) ;
}
return V_5 ;
}
static int F_22 ( struct V_41 * V_42 ,
struct V_47 * V_14 )
{
struct V_2 * V_3 = F_17 ( V_42 ) ;
unsigned long V_48 ;
V_48 = F_23 ( V_3 -> V_8 , 2000UL * V_14 -> clock ) / 2000 ;
if ( V_48 == V_14 -> clock )
return V_49 ;
V_48 = F_23 ( V_3 -> V_8 , 1000UL * V_14 -> clock ) / 1000 ;
if ( V_48 == V_14 -> clock )
return V_49 ;
F_24 ( V_3 -> V_37 , L_2 ,
V_14 -> V_50 , V_14 -> V_51 ) ;
return V_52 ;
}
static struct V_53 * F_25 (
struct V_41 * V_42 )
{
struct V_2 * V_3 = F_17 ( V_42 ) ;
return & V_3 -> V_54 ;
}
static void F_26 ( struct V_53 * V_54 , int V_14 )
{
struct V_2 * V_3 = F_27 ( V_54 ) ;
int V_5 ;
V_5 = F_6 ( V_3 -> V_9 , V_10 ,
V_34 , V_55 ) ;
if ( V_5 < 0 )
F_13 ( V_3 -> V_37 , L_3 , V_5 ) ;
}
static bool F_28 ( struct V_53 * V_54 ,
const struct V_47 * V_14 ,
struct V_47 * V_56 )
{
return true ;
}
static void F_29 ( struct V_53 * V_54 )
{
struct V_2 * V_3 = F_27 ( V_54 ) ;
F_9 ( V_3 ) ;
switch ( V_3 -> V_14 ) {
case V_15 :
F_30 ( V_54 -> V_57 ,
V_58 , V_59 ,
V_3 -> V_60 , V_3 -> V_61 ) ;
break;
case V_62 :
F_31 ( V_54 -> V_57 , V_63 ,
V_64 ) ;
break;
}
}
static void F_32 ( struct V_53 * V_54 ,
struct V_47 * V_14 ,
struct V_47 * V_56 )
{
struct V_2 * V_3 = F_27 ( V_54 ) ;
unsigned long V_65 ;
unsigned long V_48 ;
int div = 1 ;
int V_5 ;
V_48 = 2000UL * V_14 -> clock ;
F_33 ( V_3 -> V_8 , V_48 ) ;
V_65 = F_34 ( V_3 -> V_8 ) ;
if ( V_65 >= V_48 )
div = 2 ;
F_33 ( V_3 -> V_66 , V_65 / div ) ;
V_5 = F_35 ( V_3 -> V_67 , V_3 -> V_66 ) ;
if ( V_5 < 0 ) {
F_13 ( V_3 -> V_37 , L_4 ,
V_5 ) ;
}
if ( V_3 -> V_14 == V_15 )
F_12 ( V_3 ) ;
else
F_11 ( V_3 ) ;
}
static void F_36 ( struct V_53 * V_54 )
{
struct V_2 * V_3 = F_27 ( V_54 ) ;
F_3 ( V_3 ) ;
}
static void F_37 ( struct V_53 * V_54 )
{
struct V_2 * V_3 = F_27 ( V_54 ) ;
F_9 ( V_3 ) ;
}
static void F_38 ( struct V_53 * V_54 )
{
}
static T_1 F_39 ( int V_68 , void * V_69 )
{
struct V_2 * V_3 = V_69 ;
unsigned int V_22 ;
F_40 ( V_3 -> V_9 , V_13 , & V_22 ) ;
F_7 ( V_3 -> V_9 , V_13 , 0xffffffff ) ;
return V_70 ;
}
static unsigned long F_41 ( struct V_71 * V_72 ,
unsigned long V_73 )
{
struct V_2 * V_3 = F_42 ( V_72 , struct V_2 , V_74 ) ;
unsigned int V_22 ;
int V_5 ;
V_5 = F_40 ( V_3 -> V_9 , V_10 , & V_22 ) ;
if ( V_5 < 0 )
return 0 ;
switch ( V_22 & V_75 ) {
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
static long F_43 ( struct V_71 * V_72 , unsigned long V_48 ,
unsigned long * V_79 )
{
unsigned long div ;
div = * V_79 / V_48 ;
if ( div >= 4 )
return * V_79 / 4 ;
else if ( div >= 2 )
return * V_79 / 2 ;
else
return * V_79 ;
}
static int F_44 ( struct V_71 * V_72 , unsigned long V_48 ,
unsigned long V_73 )
{
struct V_2 * V_3 = F_42 ( V_72 , struct V_2 , V_74 ) ;
unsigned long div ;
T_2 V_22 ;
int V_5 ;
div = V_73 / V_48 ;
if ( div >= 4 )
V_22 = V_76 ;
else if ( div >= 2 )
V_22 = V_77 ;
else
V_22 = V_78 ;
V_5 = F_6 ( V_3 -> V_9 , V_10 ,
V_75 , V_22 ) ;
if ( V_5 < 0 ) {
F_13 ( V_3 -> V_37 , L_5 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , void T_3 * V_80 )
{
const char * V_81 [ 1 ] ;
struct V_82 V_83 = {
. V_84 = L_6 ,
. V_85 = & V_86 ,
. V_87 = 1 ,
. V_4 = 0 ,
} ;
V_81 [ 0 ] = F_46 ( V_3 -> V_8 ) ;
V_83 . V_88 = ( const char * * ) & V_81 ;
V_3 -> V_74 . V_83 = & V_83 ;
V_3 -> V_66 = F_47 ( V_3 -> V_37 , & V_3 -> V_74 ) ;
if ( F_48 ( V_3 -> V_66 ) ) {
F_13 ( V_3 -> V_37 , L_7 ,
F_49 ( V_3 -> V_66 ) ) ;
return F_49 ( V_3 -> V_66 ) ;
}
return 0 ;
}
static int F_50 ( struct V_2 * V_3 )
{
int V_5 ;
V_3 -> V_42 . V_89 = & V_90 ;
V_3 -> V_54 . V_89 = & V_91 ;
V_3 -> V_54 . V_92 = V_93 ;
V_3 -> V_42 . V_94 = V_95 ;
F_51 ( & V_3 -> V_54 , & V_96 ) ;
V_5 = F_52 ( & V_3 -> V_54 , & V_3 -> V_97 ,
V_98 ) ;
if ( V_5 ) {
F_13 ( V_3 -> V_37 , L_8 , V_5 ) ;
return V_5 ;
}
F_53 ( & V_3 -> V_42 ,
& V_99 ) ;
V_5 = F_54 ( & V_3 -> V_42 ,
& V_3 -> V_100 , V_98 ) ;
if ( V_5 ) {
F_55 ( V_3 -> V_97 ) ;
F_13 ( V_3 -> V_37 , L_9 , V_5 ) ;
return V_5 ;
}
F_56 ( & V_3 -> V_42 , & V_3 -> V_54 ) ;
return 0 ;
}
static bool F_57 ( struct V_101 * V_37 , unsigned int V_102 )
{
return ( V_102 % 4 == 0 ) && ( V_102 <= 0xdc ) ;
}
const int F_58 ( struct V_103 * V_104 )
{
const char * V_105 ;
int V_5 , V_106 ;
V_5 = F_59 ( V_104 , L_10 , & V_105 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_106 = 0 ; V_106 < F_60 ( V_107 ) ; V_106 ++ )
if ( ! strcasecmp ( V_105 , V_107 [ V_106 ] ) )
return V_106 ;
return - V_108 ;
}
static int F_61 ( struct V_109 * V_110 )
{
struct V_103 * V_104 = V_110 -> V_37 . V_111 ;
struct V_103 * V_112 ;
struct V_2 * V_3 ;
struct V_113 * V_114 ;
void T_3 * V_80 ;
unsigned int V_22 ;
int V_68 ;
int V_5 ;
V_3 = F_62 ( & V_110 -> V_37 , sizeof( * V_3 ) , V_115 ) ;
if ( ! V_3 )
return - V_116 ;
V_3 -> V_37 = & V_110 -> V_37 ;
F_63 ( & V_3 -> V_117 ) ;
F_63 ( & V_3 -> V_6 ) ;
V_112 = F_64 ( V_104 , L_11 , 0 ) ;
if ( V_112 ) {
V_3 -> V_46 = F_65 ( V_112 ) ;
F_66 ( V_112 ) ;
}
V_3 -> V_14 = F_58 ( V_104 ) ;
if ( V_3 -> V_14 != V_15 ) {
F_13 ( & V_110 -> V_37 , L_12 ) ;
return - V_108 ;
}
if ( V_3 -> V_14 == V_15 ) {
V_5 = F_67 ( V_104 , L_13 ,
& V_3 -> V_60 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_110 -> V_37 , L_14 ) ;
return V_5 ;
}
V_5 |= F_67 ( V_104 , L_15 ,
& V_3 -> V_61 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_110 -> V_37 , L_14 ) ;
return V_5 ;
}
}
V_114 = F_68 ( V_110 , V_118 , 0 ) ;
V_80 = F_69 ( & V_110 -> V_37 , V_114 ) ;
if ( F_48 ( V_80 ) )
return F_49 ( V_80 ) ;
V_119 . V_120 = V_3 ;
V_3 -> V_9 = F_70 ( & V_110 -> V_37 , L_16 , V_80 ,
& V_119 ) ;
if ( F_48 ( V_3 -> V_9 ) ) {
F_13 ( & V_110 -> V_37 , L_17 ,
F_49 ( V_3 -> V_9 ) ) ;
return F_49 ( V_3 -> V_9 ) ;
}
V_68 = F_71 ( V_110 , 0 ) ;
if ( V_68 < 0 ) {
F_13 ( & V_110 -> V_37 , L_18 ) ;
return V_68 ;
}
V_5 = F_72 ( & V_110 -> V_37 , V_68 , NULL ,
F_39 , V_121 ,
L_19 , V_3 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_110 -> V_37 , L_20 , V_5 ) ;
return V_5 ;
}
V_3 -> V_122 = F_73 ( & V_110 -> V_37 , L_21 ) ;
if ( ! F_48 ( V_3 -> V_122 ) ) {
F_74 ( V_3 -> V_122 , 2750000 , 2750000 ) ;
V_5 = F_75 ( V_3 -> V_122 ) ;
if ( V_5 )
return V_5 ;
}
V_3 -> V_8 = F_76 ( & V_110 -> V_37 , L_16 ) ;
if ( F_48 ( V_3 -> V_8 ) ) {
F_13 ( & V_110 -> V_37 , L_22 ,
F_49 ( V_3 -> V_8 ) ) ;
return F_49 ( V_3 -> V_8 ) ;
}
V_3 -> V_67 = F_76 ( & V_110 -> V_37 , L_23 ) ;
if ( F_48 ( V_3 -> V_67 ) ) {
F_13 ( & V_110 -> V_37 , L_24 ,
F_49 ( V_3 -> V_67 ) ) ;
return F_49 ( V_3 -> V_67 ) ;
}
V_5 = F_45 ( V_3 , V_80 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_40 ( V_3 -> V_9 , V_10 , & V_22 ) ;
if ( V_5 < 0 ) {
F_13 ( & V_110 -> V_37 , L_25 , V_5 ) ;
return V_5 ;
}
if ( V_22 != 0x00100000 ) {
F_13 ( & V_110 -> V_37 , L_26 ) ;
return - V_123 ;
} ;
V_5 = F_7 ( V_3 -> V_9 , V_124 , 0 ) ;
V_5 = F_50 ( V_3 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_77 ( V_3 -> V_97 , V_104 ) ;
F_78 ( V_110 , V_3 ) ;
return 0 ;
}
static int F_79 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = F_80 ( V_110 ) ;
struct V_41 * V_42 = & V_3 -> V_42 ;
struct V_53 * V_54 = & V_3 -> V_54 ;
F_81 ( V_42 , V_54 ) ;
F_82 ( V_3 -> V_100 ) ;
F_55 ( V_3 -> V_97 ) ;
if ( ! F_48 ( V_3 -> V_122 ) )
F_83 ( V_3 -> V_122 ) ;
return 0 ;
}
