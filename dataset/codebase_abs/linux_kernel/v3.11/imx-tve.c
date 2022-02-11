static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( & V_3 -> V_4 ) ;
}
static void F_3 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_4 ( & V_3 -> V_4 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
unsigned long V_5 ;
int V_6 ;
F_6 ( & V_3 -> V_7 , V_5 ) ;
if ( ! V_3 -> V_8 ) {
V_3 -> V_8 = 1 ;
F_7 ( V_3 -> V_9 ) ;
V_6 = F_8 ( V_3 -> V_10 , V_11 ,
V_12 | V_13 ,
V_12 | V_13 ) ;
}
F_9 ( V_3 -> V_10 , V_14 , 0xffffffff ) ;
if ( V_3 -> V_15 == V_16 )
F_9 ( V_3 -> V_10 , V_17 , 0 ) ;
else
F_9 ( V_3 -> V_10 , V_17 ,
V_18 | V_19 | V_20 ) ;
F_10 ( & V_3 -> V_7 , V_5 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
unsigned long V_5 ;
int V_6 ;
F_6 ( & V_3 -> V_7 , V_5 ) ;
if ( V_3 -> V_8 ) {
V_3 -> V_8 = 0 ;
V_6 = F_8 ( V_3 -> V_10 , V_11 ,
V_12 | V_13 , 0 ) ;
F_12 ( V_3 -> V_9 ) ;
}
F_10 ( & V_3 -> V_7 , V_5 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
return - V_21 ;
}
static int F_14 ( struct V_2 * V_3 )
{
unsigned int V_22 ;
unsigned int V_23 ;
int V_6 ;
V_6 = F_8 ( V_3 -> V_10 , V_24 ,
V_25 , 0x0a ) ;
V_6 = F_8 ( V_3 -> V_10 , V_26 ,
V_25 , 0x0a ) ;
V_6 = F_8 ( V_3 -> V_10 , V_27 ,
V_25 , 0x0a ) ;
V_22 = V_28 | V_29 ;
V_23 = V_30 | V_31 ;
V_22 |= V_32 | V_33 ;
V_23 |= V_34 | 0 ;
V_22 |= V_35 | V_36 ;
V_23 |= V_37 | V_36 ;
V_6 = F_8 ( V_3 -> V_10 , V_11 , V_22 , V_23 ) ;
if ( V_6 < 0 ) {
F_15 ( V_3 -> V_38 , L_1 , V_6 ) ;
return V_6 ;
}
V_6 = F_8 ( V_3 -> V_10 , V_39 ,
V_40 , 1 ) ;
return 0 ;
}
static enum V_41 F_16 (
struct V_42 * V_43 , bool V_44 )
{
return V_45 ;
}
static void F_17 ( struct V_42 * V_43 )
{
}
static int F_18 ( struct V_42 * V_43 )
{
struct V_2 * V_3 = F_19 ( V_43 ) ;
struct V_46 * V_46 ;
int V_6 = 0 ;
if ( ! V_3 -> V_47 )
return 0 ;
V_46 = F_20 ( V_43 , V_3 -> V_47 ) ;
if ( V_46 ) {
F_21 ( V_43 , V_46 ) ;
V_6 = F_22 ( V_43 , V_46 ) ;
F_23 ( V_46 ) ;
}
return V_6 ;
}
static int F_24 ( struct V_42 * V_43 ,
struct V_48 * V_15 )
{
struct V_2 * V_3 = F_19 ( V_43 ) ;
unsigned long V_49 ;
V_49 = F_25 ( V_3 -> V_9 , 2000UL * V_15 -> clock ) / 2000 ;
if ( V_49 == V_15 -> clock )
return V_50 ;
V_49 = F_25 ( V_3 -> V_9 , 1000UL * V_15 -> clock ) / 1000 ;
if ( V_49 == V_15 -> clock )
return V_50 ;
F_26 ( V_3 -> V_38 , L_2 ,
V_15 -> V_51 , V_15 -> V_52 ) ;
return V_53 ;
}
static struct V_54 * F_27 (
struct V_42 * V_43 )
{
struct V_2 * V_3 = F_19 ( V_43 ) ;
return & V_3 -> V_55 ;
}
static void F_28 ( struct V_54 * V_55 , int V_15 )
{
struct V_2 * V_3 = F_29 ( V_55 ) ;
int V_6 ;
V_6 = F_8 ( V_3 -> V_10 , V_11 ,
V_35 , V_56 ) ;
if ( V_6 < 0 )
F_15 ( V_3 -> V_38 , L_3 , V_6 ) ;
}
static bool F_30 ( struct V_54 * V_55 ,
const struct V_48 * V_15 ,
struct V_48 * V_57 )
{
return true ;
}
static void F_31 ( struct V_54 * V_55 )
{
struct V_2 * V_3 = F_29 ( V_55 ) ;
F_11 ( V_3 ) ;
switch ( V_3 -> V_15 ) {
case V_16 :
F_32 ( V_55 -> V_58 ,
V_59 , V_60 ,
V_3 -> V_61 , V_3 -> V_62 ) ;
break;
case V_63 :
F_33 ( V_55 -> V_58 , V_64 ,
V_65 ) ;
break;
}
}
static void F_34 ( struct V_54 * V_55 ,
struct V_48 * V_15 ,
struct V_48 * V_57 )
{
struct V_2 * V_3 = F_29 ( V_55 ) ;
unsigned long V_66 ;
unsigned long V_49 ;
int div = 1 ;
int V_6 ;
V_49 = 2000UL * V_15 -> clock ;
F_35 ( V_3 -> V_9 , V_49 ) ;
V_66 = F_36 ( V_3 -> V_9 ) ;
if ( V_66 >= V_49 )
div = 2 ;
F_35 ( V_3 -> V_67 , V_66 / div ) ;
V_6 = F_37 ( V_3 -> V_68 , V_3 -> V_67 ) ;
if ( V_6 < 0 ) {
F_15 ( V_3 -> V_38 , L_4 ,
V_6 ) ;
}
if ( V_3 -> V_15 == V_16 )
F_14 ( V_3 ) ;
else
F_13 ( V_3 ) ;
}
static void F_38 ( struct V_54 * V_55 )
{
struct V_2 * V_3 = F_29 ( V_55 ) ;
F_5 ( V_3 ) ;
}
static void F_39 ( struct V_54 * V_55 )
{
struct V_2 * V_3 = F_29 ( V_55 ) ;
F_11 ( V_3 ) ;
}
static void F_40 ( struct V_54 * V_55 )
{
}
static T_1 F_41 ( int V_69 , void * V_70 )
{
struct V_2 * V_3 = V_70 ;
unsigned int V_23 ;
F_42 ( V_3 -> V_10 , V_14 , & V_23 ) ;
F_9 ( V_3 -> V_10 , V_14 , 0xffffffff ) ;
return V_71 ;
}
static unsigned long F_43 ( struct V_72 * V_73 ,
unsigned long V_74 )
{
struct V_2 * V_3 = F_44 ( V_73 , struct V_2 , V_75 ) ;
unsigned int V_23 ;
int V_6 ;
V_6 = F_42 ( V_3 -> V_10 , V_11 , & V_23 ) ;
if ( V_6 < 0 )
return 0 ;
switch ( V_23 & V_76 ) {
case V_77 :
return V_74 / 4 ;
case V_78 :
return V_74 / 2 ;
case V_79 :
default:
return V_74 ;
}
return 0 ;
}
static long F_45 ( struct V_72 * V_73 , unsigned long V_49 ,
unsigned long * V_80 )
{
unsigned long div ;
div = * V_80 / V_49 ;
if ( div >= 4 )
return * V_80 / 4 ;
else if ( div >= 2 )
return * V_80 / 2 ;
else
return * V_80 ;
}
static int F_46 ( struct V_72 * V_73 , unsigned long V_49 ,
unsigned long V_74 )
{
struct V_2 * V_3 = F_44 ( V_73 , struct V_2 , V_75 ) ;
unsigned long div ;
T_2 V_23 ;
int V_6 ;
div = V_74 / V_49 ;
if ( div >= 4 )
V_23 = V_77 ;
else if ( div >= 2 )
V_23 = V_78 ;
else
V_23 = V_79 ;
V_6 = F_8 ( V_3 -> V_10 , V_11 , V_76 , V_23 ) ;
if ( V_6 < 0 ) {
F_15 ( V_3 -> V_38 , L_5 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , void T_3 * V_81 )
{
const char * V_82 [ 1 ] ;
struct V_83 V_84 = {
. V_85 = L_6 ,
. V_86 = & V_87 ,
. V_88 = 1 ,
. V_5 = 0 ,
} ;
V_82 [ 0 ] = F_48 ( V_3 -> V_9 ) ;
V_84 . V_89 = ( const char * * ) & V_82 ;
V_3 -> V_75 . V_84 = & V_84 ;
V_3 -> V_67 = F_49 ( V_3 -> V_38 , & V_3 -> V_75 ) ;
if ( F_50 ( V_3 -> V_67 ) ) {
F_15 ( V_3 -> V_38 , L_7 ,
F_51 ( V_3 -> V_67 ) ) ;
return F_51 ( V_3 -> V_67 ) ;
}
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_6 ;
V_3 -> V_43 . V_90 = & V_91 ;
V_3 -> V_55 . V_90 = & V_92 ;
V_3 -> V_55 . V_93 = V_94 ;
V_3 -> V_43 . V_95 = V_96 ;
F_53 ( & V_3 -> V_55 , & V_97 ) ;
V_6 = F_54 ( & V_3 -> V_55 , & V_3 -> V_98 ,
V_99 ) ;
if ( V_6 ) {
F_15 ( V_3 -> V_38 , L_8 , V_6 ) ;
return V_6 ;
}
F_55 ( & V_3 -> V_43 ,
& V_100 ) ;
V_6 = F_56 ( & V_3 -> V_43 ,
& V_3 -> V_101 , V_99 ) ;
if ( V_6 ) {
F_57 ( V_3 -> V_98 ) ;
F_15 ( V_3 -> V_38 , L_9 , V_6 ) ;
return V_6 ;
}
F_58 ( & V_3 -> V_43 , & V_3 -> V_55 ) ;
return 0 ;
}
static bool F_59 ( struct V_102 * V_38 , unsigned int V_103 )
{
return ( V_103 % 4 == 0 ) && ( V_103 <= 0xdc ) ;
}
const int F_60 ( struct V_104 * V_105 )
{
const char * V_106 ;
int V_6 , V_107 ;
V_6 = F_61 ( V_105 , L_10 , & V_106 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_107 = 0 ; V_107 < F_62 ( V_108 ) ; V_107 ++ )
if ( ! strcasecmp ( V_106 , V_108 [ V_107 ] ) )
return V_107 ;
return - V_109 ;
}
static int F_63 ( struct V_110 * V_111 )
{
struct V_104 * V_105 = V_111 -> V_38 . V_112 ;
struct V_104 * V_113 ;
struct V_2 * V_3 ;
struct V_114 * V_115 ;
void T_3 * V_81 ;
unsigned int V_23 ;
int V_69 ;
int V_6 ;
V_3 = F_64 ( & V_111 -> V_38 , sizeof( * V_3 ) , V_116 ) ;
if ( ! V_3 )
return - V_117 ;
V_3 -> V_38 = & V_111 -> V_38 ;
F_65 ( & V_3 -> V_4 ) ;
F_65 ( & V_3 -> V_7 ) ;
V_113 = F_66 ( V_105 , L_11 , 0 ) ;
if ( V_113 ) {
V_3 -> V_47 = F_67 ( V_113 ) ;
F_68 ( V_113 ) ;
}
V_3 -> V_15 = F_60 ( V_105 ) ;
if ( V_3 -> V_15 != V_16 ) {
F_15 ( & V_111 -> V_38 , L_12 ) ;
return - V_109 ;
}
if ( V_3 -> V_15 == V_16 ) {
V_6 = F_69 ( V_105 , L_13 , & V_3 -> V_61 ) ;
if ( V_6 < 0 ) {
F_15 ( & V_111 -> V_38 , L_14 ) ;
return V_6 ;
}
V_6 |= F_69 ( V_105 , L_15 , & V_3 -> V_62 ) ;
if ( V_6 < 0 ) {
F_15 ( & V_111 -> V_38 , L_14 ) ;
return V_6 ;
}
}
V_115 = F_70 ( V_111 , V_118 , 0 ) ;
if ( ! V_115 ) {
F_15 ( & V_111 -> V_38 , L_16 ) ;
return - V_119 ;
}
V_81 = F_71 ( & V_111 -> V_38 , V_115 ) ;
if ( F_50 ( V_81 ) )
return F_51 ( V_81 ) ;
V_120 . V_121 = V_3 ;
V_3 -> V_10 = F_72 ( & V_111 -> V_38 , L_17 , V_81 ,
& V_120 ) ;
if ( F_50 ( V_3 -> V_10 ) ) {
F_15 ( & V_111 -> V_38 , L_18 ,
F_51 ( V_3 -> V_10 ) ) ;
return F_51 ( V_3 -> V_10 ) ;
}
V_69 = F_73 ( V_111 , 0 ) ;
if ( V_69 < 0 ) {
F_15 ( & V_111 -> V_38 , L_19 ) ;
return V_69 ;
}
V_6 = F_74 ( & V_111 -> V_38 , V_69 , NULL ,
F_41 , V_122 ,
L_20 , V_3 ) ;
if ( V_6 < 0 ) {
F_15 ( & V_111 -> V_38 , L_21 , V_6 ) ;
return V_6 ;
}
V_3 -> V_123 = F_75 ( & V_111 -> V_38 , L_22 ) ;
if ( ! F_50 ( V_3 -> V_123 ) ) {
F_76 ( V_3 -> V_123 , 2750000 , 2750000 ) ;
V_6 = F_77 ( V_3 -> V_123 ) ;
if ( V_6 )
return V_6 ;
}
V_3 -> V_9 = F_78 ( & V_111 -> V_38 , L_17 ) ;
if ( F_50 ( V_3 -> V_9 ) ) {
F_15 ( & V_111 -> V_38 , L_23 ,
F_51 ( V_3 -> V_9 ) ) ;
return F_51 ( V_3 -> V_9 ) ;
}
V_3 -> V_68 = F_78 ( & V_111 -> V_38 , L_24 ) ;
if ( F_50 ( V_3 -> V_68 ) ) {
F_15 ( & V_111 -> V_38 , L_25 ,
F_51 ( V_3 -> V_68 ) ) ;
return F_51 ( V_3 -> V_68 ) ;
}
V_6 = F_47 ( V_3 , V_81 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_42 ( V_3 -> V_10 , V_11 , & V_23 ) ;
if ( V_6 < 0 ) {
F_15 ( & V_111 -> V_38 , L_26 , V_6 ) ;
return V_6 ;
}
if ( V_23 != 0x00100000 ) {
F_15 ( & V_111 -> V_38 , L_27 ) ;
return - V_124 ;
} ;
V_6 = F_9 ( V_3 -> V_10 , V_125 , 0 ) ;
V_6 = F_52 ( V_3 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_79 ( V_3 -> V_98 , V_105 ) ;
F_80 ( V_111 , V_3 ) ;
return 0 ;
}
static int F_81 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = F_82 ( V_111 ) ;
struct V_42 * V_43 = & V_3 -> V_43 ;
struct V_54 * V_55 = & V_3 -> V_55 ;
F_83 ( V_43 , V_55 ) ;
F_84 ( V_3 -> V_101 ) ;
F_57 ( V_3 -> V_98 ) ;
if ( ! F_50 ( V_3 -> V_123 ) )
F_85 ( V_3 -> V_123 ) ;
return 0 ;
}
