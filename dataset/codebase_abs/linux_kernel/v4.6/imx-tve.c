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
static void F_25 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
F_7 ( V_3 ) ;
switch ( V_3 -> V_12 ) {
case V_13 :
F_26 ( V_52 , V_54 ,
V_3 -> V_55 , V_3 -> V_56 ) ;
break;
case V_57 :
F_27 ( V_52 , V_58 ) ;
break;
}
}
static void F_28 ( struct V_51 * V_52 ,
struct V_44 * V_59 ,
struct V_44 * V_12 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
unsigned long V_60 ;
unsigned long V_45 ;
int div = 1 ;
int V_4 ;
V_45 = 2000UL * V_12 -> clock ;
F_29 ( V_3 -> V_6 , V_45 ) ;
V_60 = F_30 ( V_3 -> V_6 ) ;
if ( V_60 >= V_45 )
div = 2 ;
F_29 ( V_3 -> V_61 , V_60 / div ) ;
V_4 = F_31 ( V_3 -> V_62 , V_3 -> V_61 ) ;
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
static void F_32 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
F_3 ( V_3 ) ;
}
static void F_33 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = F_23 ( V_52 ) ;
F_7 ( V_3 ) ;
}
static T_1 F_34 ( int V_63 , void * V_64 )
{
struct V_2 * V_3 = V_64 ;
unsigned int V_20 ;
F_35 ( V_3 -> V_7 , V_11 , & V_20 ) ;
F_6 ( V_3 -> V_7 , V_11 , 0xffffffff ) ;
return V_65 ;
}
static unsigned long F_36 ( struct V_66 * V_67 ,
unsigned long V_68 )
{
struct V_2 * V_3 = F_37 ( V_67 , struct V_2 , V_69 ) ;
unsigned int V_20 ;
int V_4 ;
V_4 = F_35 ( V_3 -> V_7 , V_8 , & V_20 ) ;
if ( V_4 < 0 )
return 0 ;
switch ( V_20 & V_70 ) {
case V_71 :
return V_68 / 4 ;
case V_72 :
return V_68 / 2 ;
case V_73 :
default:
return V_68 ;
}
return 0 ;
}
static long F_38 ( struct V_66 * V_67 , unsigned long V_45 ,
unsigned long * V_74 )
{
unsigned long div ;
div = * V_74 / V_45 ;
if ( div >= 4 )
return * V_74 / 4 ;
else if ( div >= 2 )
return * V_74 / 2 ;
return * V_74 ;
}
static int F_39 ( struct V_66 * V_67 , unsigned long V_45 ,
unsigned long V_68 )
{
struct V_2 * V_3 = F_37 ( V_67 , struct V_2 , V_69 ) ;
unsigned long div ;
T_2 V_20 ;
int V_4 ;
div = V_68 / V_45 ;
if ( div >= 4 )
V_20 = V_71 ;
else if ( div >= 2 )
V_20 = V_72 ;
else
V_20 = V_73 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 ,
V_70 , V_20 ) ;
if ( V_4 < 0 ) {
F_24 ( V_3 -> V_47 , L_5 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , void T_3 * V_75 )
{
const char * V_76 [ 1 ] ;
struct V_77 V_78 = {
. V_79 = L_6 ,
. V_80 = & V_81 ,
. V_82 = 1 ,
. V_83 = 0 ,
} ;
V_76 [ 0 ] = F_41 ( V_3 -> V_6 ) ;
V_78 . V_84 = ( const char * * ) & V_76 ;
V_3 -> V_69 . V_78 = & V_78 ;
V_3 -> V_61 = F_42 ( V_3 -> V_47 , & V_3 -> V_69 ) ;
if ( F_43 ( V_3 -> V_61 ) ) {
F_24 ( V_3 -> V_47 , L_7 ,
F_44 ( V_3 -> V_61 ) ) ;
return F_44 ( V_3 -> V_61 ) ;
}
return 0 ;
}
static int F_45 ( struct V_85 * V_86 , struct V_2 * V_3 )
{
int V_87 ;
int V_4 ;
V_87 = V_3 -> V_12 == V_13 ?
V_88 : V_89 ;
V_4 = F_46 ( V_86 , & V_3 -> V_52 ,
V_3 -> V_47 -> V_90 ) ;
if ( V_4 )
return V_4 ;
F_47 ( & V_3 -> V_52 , & V_91 ) ;
F_48 ( V_86 , & V_3 -> V_52 , & V_92 ,
V_87 , NULL ) ;
F_49 ( & V_3 -> V_39 ,
& V_93 ) ;
F_50 ( V_86 , & V_3 -> V_39 , & V_94 ,
V_95 ) ;
F_51 ( & V_3 -> V_39 , & V_3 -> V_52 ) ;
return 0 ;
}
static bool F_52 ( struct V_96 * V_47 , unsigned int V_97 )
{
return ( V_97 % 4 == 0 ) && ( V_97 <= 0xdc ) ;
}
static const int F_53 ( struct V_98 * V_99 )
{
const char * V_100 ;
int V_4 , V_101 ;
V_4 = F_54 ( V_99 , L_8 , & V_100 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_101 = 0 ; V_101 < F_55 ( V_102 ) ; V_101 ++ )
if ( ! strcasecmp ( V_100 , V_102 [ V_101 ] ) )
return V_101 ;
return - V_103 ;
}
static int F_56 ( struct V_96 * V_47 , struct V_96 * V_104 , void * V_64 )
{
struct V_105 * V_106 = F_57 ( V_47 ) ;
struct V_85 * V_86 = V_64 ;
struct V_98 * V_99 = V_47 -> V_90 ;
struct V_98 * V_107 ;
struct V_2 * V_3 ;
struct V_108 * V_109 ;
void T_3 * V_75 ;
unsigned int V_20 ;
int V_63 ;
int V_4 ;
V_3 = F_58 ( V_47 , sizeof( * V_3 ) , V_110 ) ;
if ( ! V_3 )
return - V_111 ;
V_3 -> V_47 = V_47 ;
F_59 ( & V_3 -> V_112 ) ;
V_107 = F_60 ( V_99 , L_9 , 0 ) ;
if ( V_107 ) {
V_3 -> V_43 = F_61 ( V_107 ) ;
F_62 ( V_107 ) ;
}
V_3 -> V_12 = F_53 ( V_99 ) ;
if ( V_3 -> V_12 != V_13 ) {
F_24 ( V_47 , L_10 ) ;
return - V_103 ;
}
if ( V_3 -> V_12 == V_13 ) {
V_4 = F_63 ( V_99 , L_11 ,
& V_3 -> V_55 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_12 ) ;
return V_4 ;
}
V_4 |= F_63 ( V_99 , L_13 ,
& V_3 -> V_56 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_12 ) ;
return V_4 ;
}
}
V_109 = F_64 ( V_106 , V_113 , 0 ) ;
V_75 = F_65 ( V_47 , V_109 ) ;
if ( F_43 ( V_75 ) )
return F_44 ( V_75 ) ;
V_114 . V_115 = V_3 ;
V_3 -> V_7 = F_66 ( V_47 , L_14 , V_75 ,
& V_114 ) ;
if ( F_43 ( V_3 -> V_7 ) ) {
F_24 ( V_47 , L_15 ,
F_44 ( V_3 -> V_7 ) ) ;
return F_44 ( V_3 -> V_7 ) ;
}
V_63 = F_67 ( V_106 , 0 ) ;
if ( V_63 < 0 ) {
F_24 ( V_47 , L_16 ) ;
return V_63 ;
}
V_4 = F_68 ( V_47 , V_63 , NULL ,
F_34 , V_116 ,
L_17 , V_3 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_18 , V_4 ) ;
return V_4 ;
}
V_3 -> V_117 = F_69 ( V_47 , L_19 ) ;
if ( ! F_43 ( V_3 -> V_117 ) ) {
F_70 ( V_3 -> V_117 , 2750000 , 2750000 ) ;
V_4 = F_71 ( V_3 -> V_117 ) ;
if ( V_4 )
return V_4 ;
}
V_3 -> V_6 = F_72 ( V_47 , L_14 ) ;
if ( F_43 ( V_3 -> V_6 ) ) {
F_24 ( V_47 , L_20 ,
F_44 ( V_3 -> V_6 ) ) ;
return F_44 ( V_3 -> V_6 ) ;
}
V_3 -> V_62 = F_72 ( V_47 , L_21 ) ;
if ( F_43 ( V_3 -> V_62 ) ) {
F_24 ( V_47 , L_22 ,
F_44 ( V_3 -> V_62 ) ) ;
return F_44 ( V_3 -> V_62 ) ;
}
V_4 = F_40 ( V_3 , V_75 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_35 ( V_3 -> V_7 , V_8 , & V_20 ) ;
if ( V_4 < 0 ) {
F_24 ( V_47 , L_23 ,
V_4 ) ;
return V_4 ;
}
if ( V_20 != 0x00100000 ) {
F_24 ( V_47 , L_24 ) ;
return - V_118 ;
}
V_4 = F_6 ( V_3 -> V_7 , V_119 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_45 ( V_86 , V_3 ) ;
if ( V_4 )
return V_4 ;
F_73 ( V_47 , V_3 ) ;
return 0 ;
}
static void F_74 ( struct V_96 * V_47 , struct V_96 * V_104 ,
void * V_64 )
{
struct V_2 * V_3 = F_75 ( V_47 ) ;
V_3 -> V_39 . V_120 -> V_121 ( & V_3 -> V_39 ) ;
V_3 -> V_52 . V_120 -> V_121 ( & V_3 -> V_52 ) ;
if ( ! F_43 ( V_3 -> V_117 ) )
F_76 ( V_3 -> V_117 ) ;
}
static int F_77 ( struct V_105 * V_106 )
{
return F_78 ( & V_106 -> V_47 , & V_122 ) ;
}
static int F_79 ( struct V_105 * V_106 )
{
F_80 ( & V_106 -> V_47 , & V_122 ) ;
return 0 ;
}
