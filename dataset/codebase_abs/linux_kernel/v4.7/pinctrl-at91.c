static const inline struct V_1 * F_1 (
const struct V_2 * V_3 ,
const char * V_4 )
{
const struct V_1 * V_5 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( strcmp ( V_3 -> V_8 [ V_6 ] . V_4 , V_4 ) )
continue;
V_5 = & V_3 -> V_8 [ V_6 ] ;
F_2 ( V_3 -> V_9 , L_1 , V_4 , V_5 -> V_10 , V_5 -> V_11 [ 0 ] ) ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_7 ;
}
static const char * F_5 ( struct V_12 * V_13 ,
unsigned V_14 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_8 [ V_14 ] . V_4 ;
}
static int F_6 ( struct V_12 * V_13 , unsigned V_14 ,
const unsigned * * V_11 ,
unsigned * V_10 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
if ( V_14 >= V_3 -> V_7 )
return - V_15 ;
* V_11 = V_3 -> V_8 [ V_14 ] . V_11 ;
* V_10 = V_3 -> V_8 [ V_14 ] . V_10 ;
return 0 ;
}
static void F_7 ( struct V_12 * V_13 , struct V_16 * V_17 ,
unsigned V_18 )
{
F_8 ( V_17 , L_2 , F_9 ( V_13 -> V_9 ) ) ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_19 * V_20 ,
struct V_21 * * V_22 , unsigned * V_23 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_1 * V_5 ;
struct V_21 * V_24 ;
struct V_19 * V_25 ;
int V_26 = 1 ;
int V_6 ;
V_5 = F_1 ( V_3 , V_20 -> V_4 ) ;
if ( ! V_5 ) {
F_11 ( V_3 -> V_9 , L_3 ,
V_20 -> V_4 ) ;
return - V_15 ;
}
V_26 += V_5 -> V_10 ;
V_24 = F_12 ( V_13 -> V_9 , sizeof( * V_24 ) * V_26 , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
* V_22 = V_24 ;
* V_23 = V_26 ;
V_25 = F_13 ( V_20 ) ;
if ( ! V_25 ) {
F_14 ( V_13 -> V_9 , V_24 ) ;
return - V_15 ;
}
V_24 [ 0 ] . type = V_29 ;
V_24 [ 0 ] . V_30 . V_31 . V_32 = V_25 -> V_4 ;
V_24 [ 0 ] . V_30 . V_31 . V_33 = V_20 -> V_4 ;
F_15 ( V_25 ) ;
V_24 ++ ;
for ( V_6 = 0 ; V_6 < V_5 -> V_10 ; V_6 ++ ) {
V_24 [ V_6 ] . type = V_34 ;
V_24 [ V_6 ] . V_30 . V_35 . V_36 =
F_16 ( V_13 , V_5 -> V_11 [ V_6 ] ) ;
V_24 [ V_6 ] . V_30 . V_35 . V_35 = & V_5 -> V_37 [ V_6 ] . V_38 ;
V_24 [ V_6 ] . V_30 . V_35 . V_39 = 1 ;
}
F_2 ( V_13 -> V_9 , L_4 ,
( * V_22 ) -> V_30 . V_31 . V_32 , ( * V_22 ) -> V_30 . V_31 . V_33 , V_26 ) ;
return 0 ;
}
static void F_17 ( struct V_12 * V_13 ,
struct V_21 * V_22 , unsigned V_23 )
{
}
static void T_1 * F_18 ( struct V_2 * V_3 ,
unsigned int V_40 )
{
if ( ! V_41 [ V_40 ] )
return NULL ;
return V_41 [ V_40 ] -> V_42 ;
}
static inline int F_19 ( unsigned V_43 )
{
return V_43 /= V_44 ;
}
static unsigned F_20 ( unsigned int V_43 )
{
return 1 << V_43 ;
}
static unsigned F_21 ( unsigned int V_43 )
{
return 2 * ( ( V_43 >= V_44 / 2 )
? V_43 - V_44 / 2 : V_43 ) ;
}
static unsigned F_22 ( unsigned int V_43 )
{
return ( V_43 >= V_44 / 2 )
? V_45 : V_46 ;
}
static unsigned F_23 ( unsigned int V_43 )
{
return ( V_43 >= V_44 / 2 )
? V_47 : V_48 ;
}
static void F_24 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_51 ) ;
}
static unsigned F_26 ( void T_1 * V_49 , unsigned V_43 )
{
return ! ( ( F_27 ( V_49 + V_52 ) >> V_43 ) & 0x1 ) ;
}
static void F_28 ( void T_1 * V_49 , unsigned V_50 , bool V_53 )
{
if ( V_53 )
F_25 ( V_50 , V_49 + V_54 ) ;
F_25 ( V_50 , V_49 + ( V_53 ? V_55 : V_56 ) ) ;
}
static unsigned F_29 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_27 ( V_49 + V_57 ) >> V_43 ) & 0x1 ;
}
static void F_30 ( void T_1 * V_49 , unsigned V_50 , bool V_53 )
{
F_25 ( V_50 , V_49 + ( V_53 ? V_58 : V_59 ) ) ;
}
static void F_31 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_60 ) ;
}
static void F_32 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_61 ) ;
}
static void F_33 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) & ~ V_50 ,
V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) & ~ V_50 ,
V_49 + V_63 ) ;
}
static void F_34 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) | V_50 ,
V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) & ~ V_50 ,
V_49 + V_63 ) ;
}
static void F_35 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) & ~ V_50 , V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) | V_50 , V_49 + V_63 ) ;
}
static void F_36 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_62 ) | V_50 , V_49 + V_62 ) ;
F_25 ( F_27 ( V_49 + V_63 ) | V_50 , V_49 + V_63 ) ;
}
static enum V_64 F_37 ( void T_1 * V_49 , unsigned V_50 )
{
unsigned V_65 ;
if ( F_27 ( V_49 + V_66 ) & V_50 )
return V_67 ;
V_65 = ! ! ( F_27 ( V_49 + V_62 ) & V_50 ) ;
V_65 |= ( ! ! ( F_27 ( V_49 + V_63 ) & V_50 ) << 1 ) ;
return V_65 + 1 ;
}
static enum V_64 F_38 ( void T_1 * V_49 , unsigned V_50 )
{
unsigned V_65 ;
if ( F_27 ( V_49 + V_66 ) & V_50 )
return V_67 ;
V_65 = F_27 ( V_49 + V_68 ) & V_50 ;
return V_65 + 1 ;
}
static bool F_39 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_27 ( V_49 + V_69 ) >> V_43 ) & 0x1 ;
}
static void F_40 ( void T_1 * V_49 , unsigned V_50 , bool V_70 )
{
F_25 ( V_50 , V_49 + ( V_70 ? V_71 : V_72 ) ) ;
}
static bool F_41 ( void T_1 * V_49 , unsigned V_43 )
{
if ( ( F_27 ( V_49 + V_69 ) >> V_43 ) & 0x1 )
return ! ( ( F_27 ( V_49 + V_73 ) >> V_43 ) & 0x1 ) ;
return false ;
}
static void F_42 ( void T_1 * V_49 , unsigned V_50 , bool V_70 )
{
if ( V_70 )
F_25 ( V_50 , V_49 + V_74 ) ;
F_40 ( V_49 , V_50 , V_70 ) ;
}
static bool F_43 ( void T_1 * V_49 , unsigned V_43 , T_2 * div )
{
* div = F_27 ( V_49 + V_75 ) ;
return ( ( F_27 ( V_49 + V_69 ) >> V_43 ) & 0x1 ) &&
( ( F_27 ( V_49 + V_73 ) >> V_43 ) & 0x1 ) ;
}
static void F_44 ( void T_1 * V_49 , unsigned V_50 ,
bool V_70 , T_2 div )
{
if ( V_70 ) {
F_25 ( V_50 , V_49 + V_76 ) ;
F_25 ( div & V_77 , V_49 + V_75 ) ;
F_25 ( V_50 , V_49 + V_71 ) ;
} else
F_25 ( V_50 , V_49 + V_74 ) ;
}
static bool F_45 ( void T_1 * V_49 , unsigned V_43 )
{
return ! ( ( F_27 ( V_49 + V_78 ) >> V_43 ) & 0x1 ) ;
}
static void F_46 ( void T_1 * V_49 , unsigned V_50 , bool V_70 )
{
if ( V_70 )
F_25 ( V_50 , V_49 + V_56 ) ;
F_25 ( V_50 , V_49 + ( V_70 ? V_79 : V_54 ) ) ;
}
static void F_47 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_80 ) | V_50 , V_49 + V_80 ) ;
}
static bool F_48 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_27 ( V_49 + V_80 ) >> V_43 ) & 0x1 ;
}
static inline T_2 F_49 ( void T_1 * V_81 , unsigned V_43 )
{
unsigned V_82 = F_27 ( V_81 ) ;
V_82 = V_82 >> F_21 ( V_43 ) ;
return V_82 & V_83 ;
}
static unsigned F_50 ( void T_1 * V_49 ,
unsigned V_43 )
{
unsigned V_82 = F_49 ( V_49 +
F_22 ( V_43 ) , V_43 ) ;
if ( ! V_82 )
V_82 = V_84 ;
return V_82 ;
}
static unsigned F_51 ( void T_1 * V_49 ,
unsigned V_43 )
{
unsigned V_82 = F_49 ( V_49 +
F_23 ( V_43 ) , V_43 ) ;
V_82 = V_85 - V_82 ;
return V_82 ;
}
static void F_52 ( void T_1 * V_81 , unsigned V_43 , T_2 V_86 )
{
unsigned V_82 = F_27 ( V_81 ) ;
unsigned V_87 = F_21 ( V_43 ) ;
V_82 &= ~ ( V_83 << V_87 ) ;
V_82 |= V_86 << V_87 ;
F_25 ( V_82 , V_81 ) ;
}
static void F_53 ( void T_1 * V_49 , unsigned V_43 ,
T_2 V_88 )
{
if ( ! V_88 )
return;
F_52 ( V_49 + F_22 ( V_43 ) , V_43 , V_88 ) ;
}
static void F_54 ( void T_1 * V_49 , unsigned V_43 ,
T_2 V_88 )
{
if ( ! V_88 )
return;
V_88 = V_85 - V_88 ;
F_52 ( V_49 + F_23 ( V_43 ) , V_43 ,
V_88 ) ;
}
static void F_55 ( const struct V_89 * V_9 , const struct V_90 * V_43 )
{
if ( V_43 -> V_31 ) {
F_2 ( V_9 , L_5 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_31 - 1 + 'A' , V_43 -> V_38 ) ;
} else {
F_2 ( V_9 , L_6 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_38 ) ;
}
}
static int F_56 ( struct V_2 * V_3 , const char * V_4 ,
int V_91 , const struct V_90 * V_43 )
{
int V_31 ;
if ( V_43 -> V_40 >= V_92 ) {
F_11 ( V_3 -> V_9 , L_7 ,
V_4 , V_91 , V_43 -> V_40 , V_92 ) ;
return - V_15 ;
}
if ( ! V_41 [ V_43 -> V_40 ] ) {
F_11 ( V_3 -> V_9 , L_8 ,
V_4 , V_91 , V_43 -> V_40 ) ;
return - V_93 ;
}
if ( V_43 -> V_43 >= V_44 ) {
F_11 ( V_3 -> V_9 , L_9 ,
V_4 , V_91 , V_43 -> V_43 , V_44 ) ;
return - V_15 ;
}
if ( ! V_43 -> V_31 )
return 0 ;
V_31 = V_43 -> V_31 - 1 ;
if ( V_31 >= V_3 -> V_94 ) {
F_11 ( V_3 -> V_9 , L_10 ,
V_4 , V_91 , V_31 , V_3 -> V_94 ) ;
return - V_15 ;
}
if ( ! ( V_3 -> V_95 [ V_43 -> V_40 * V_3 -> V_94 + V_31 ] & 1 << V_43 -> V_43 ) ) {
F_11 ( V_3 -> V_9 , L_11 ,
V_4 , V_91 , V_31 , V_43 -> V_40 + 'A' , V_43 -> V_43 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_57 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_96 ) ;
}
static void F_58 ( void T_1 * V_49 , unsigned V_50 , bool V_97 )
{
F_25 ( V_50 , V_49 + V_98 ) ;
F_25 ( V_50 , V_49 + ( V_97 ? V_99 : V_100 ) ) ;
}
static int F_59 ( struct V_12 * V_13 , unsigned V_14 ,
unsigned V_33 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_90 * V_37 = V_3 -> V_8 [ V_33 ] . V_37 ;
const struct V_90 * V_43 ;
T_3 V_10 = V_3 -> V_8 [ V_33 ] . V_10 ;
int V_6 , V_101 ;
unsigned V_50 ;
void T_1 * V_49 ;
F_2 ( V_3 -> V_9 , L_12 ,
V_3 -> V_102 [ V_14 ] . V_4 , V_3 -> V_8 [ V_33 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
V_101 = F_56 ( V_3 , V_3 -> V_8 [ V_33 ] . V_4 , V_6 , V_43 ) ;
if ( V_101 )
return V_101 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
F_55 ( V_3 -> V_9 , V_43 ) ;
V_49 = F_18 ( V_3 , V_43 -> V_40 ) ;
if ( ! V_49 )
continue;
V_50 = F_20 ( V_43 -> V_43 ) ;
F_24 ( V_49 , V_50 ) ;
switch ( V_43 -> V_31 ) {
case V_67 :
F_58 ( V_49 , V_50 , 1 ) ;
break;
case V_103 :
V_3 -> V_104 -> V_105 ( V_49 , V_50 ) ;
break;
case V_106 :
V_3 -> V_104 -> V_107 ( V_49 , V_50 ) ;
break;
case V_108 :
if ( ! V_3 -> V_104 -> V_109 )
return - V_15 ;
V_3 -> V_104 -> V_109 ( V_49 , V_50 ) ;
break;
case V_110 :
if ( ! V_3 -> V_104 -> V_111 )
return - V_15 ;
V_3 -> V_104 -> V_111 ( V_49 , V_50 ) ;
break;
}
if ( V_43 -> V_31 )
F_57 ( V_49 , V_50 ) ;
}
return 0 ;
}
static int F_60 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_112 ;
}
static const char * F_61 ( struct V_12 * V_13 ,
unsigned V_14 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_102 [ V_14 ] . V_4 ;
}
static int F_62 ( struct V_12 * V_13 , unsigned V_14 ,
const char * const * * V_8 ,
unsigned * const V_113 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_8 = V_3 -> V_102 [ V_14 ] . V_8 ;
* V_113 = V_3 -> V_102 [ V_14 ] . V_7 ;
return 0 ;
}
static int F_63 ( struct V_12 * V_13 ,
struct V_114 * V_115 ,
unsigned V_18 )
{
struct V_2 * V_116 = F_4 ( V_13 ) ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
unsigned V_50 ;
if ( ! V_115 ) {
F_11 ( V_116 -> V_9 , L_13 ) ;
return - V_15 ;
}
if ( ! V_115 -> V_121 ) {
F_11 ( V_116 -> V_9 , L_14 ) ;
return - V_15 ;
}
V_120 = V_115 -> V_121 ;
V_118 = F_64 ( V_120 ) ;
F_2 ( V_116 -> V_9 , L_15 , V_18 ) ;
V_50 = 1 << ( V_18 - V_120 -> V_122 ) ;
F_2 ( V_116 -> V_9 , L_16 ,
V_18 , 'A' + V_115 -> V_123 , V_18 - V_120 -> V_122 , V_50 ) ;
F_25 ( V_50 , V_118 -> V_42 + V_98 ) ;
return 0 ;
}
static void F_65 ( struct V_12 * V_13 ,
struct V_114 * V_115 ,
unsigned V_18 )
{
struct V_2 * V_116 = F_4 ( V_13 ) ;
F_2 ( V_116 -> V_9 , L_17 , V_18 ) ;
}
static int F_66 ( struct V_12 * V_13 ,
unsigned V_124 , unsigned long * V_125 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
void T_1 * V_49 ;
unsigned V_43 ;
int div ;
* V_125 = 0 ;
F_2 ( V_3 -> V_9 , L_18 , V_126 , __LINE__ , V_124 ) ;
V_49 = F_18 ( V_3 , F_19 ( V_124 ) ) ;
if ( ! V_49 )
return - V_15 ;
V_43 = V_124 % V_44 ;
if ( F_29 ( V_49 , V_43 ) )
* V_125 |= V_127 ;
if ( F_26 ( V_49 , V_43 ) )
* V_125 |= V_128 ;
if ( V_3 -> V_104 -> V_129 && V_3 -> V_104 -> V_129 ( V_49 , V_43 ) )
* V_125 |= V_130 ;
if ( V_3 -> V_104 -> V_131 && V_3 -> V_104 -> V_131 ( V_49 , V_43 , & div ) )
* V_125 |= V_132 | ( div << V_133 ) ;
if ( V_3 -> V_104 -> V_134 && V_3 -> V_104 -> V_134 ( V_49 , V_43 ) )
* V_125 |= V_135 ;
if ( V_3 -> V_104 -> V_136 && V_3 -> V_104 -> V_136 ( V_49 , V_43 ) )
* V_125 |= V_137 ;
if ( V_3 -> V_104 -> V_138 )
* V_125 |= ( V_3 -> V_104 -> V_138 ( V_49 , V_43 )
<< V_139 ) ;
return 0 ;
}
static int F_67 ( struct V_12 * V_13 ,
unsigned V_124 , unsigned long * V_35 ,
unsigned V_39 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
unsigned V_50 ;
void T_1 * V_49 ;
int V_6 ;
unsigned long V_125 ;
unsigned V_43 ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ ) {
V_125 = V_35 [ V_6 ] ;
F_2 ( V_3 -> V_9 ,
L_19 ,
V_126 , __LINE__ , V_124 , V_125 ) ;
V_49 = F_18 ( V_3 , F_19 ( V_124 ) ) ;
if ( ! V_49 )
return - V_15 ;
V_43 = V_124 % V_44 ;
V_50 = F_20 ( V_43 ) ;
if ( V_125 & V_128 && V_125 & V_135 )
return - V_15 ;
F_28 ( V_49 , V_50 , V_125 & V_128 ) ;
F_30 ( V_49 , V_50 , V_125 & V_127 ) ;
if ( V_3 -> V_104 -> V_140 )
V_3 -> V_104 -> V_140 ( V_49 , V_50 , V_125 & V_130 ) ;
if ( V_3 -> V_104 -> V_141 )
V_3 -> V_104 -> V_141 ( V_49 , V_50 , V_125 & V_132 ,
( V_125 & V_142 ) >> V_133 ) ;
if ( V_3 -> V_104 -> V_143 )
V_3 -> V_104 -> V_143 ( V_49 , V_50 , V_125 & V_135 ) ;
if ( V_3 -> V_104 -> V_144 && V_125 & V_137 )
V_3 -> V_104 -> V_144 ( V_49 , V_50 ) ;
if ( V_3 -> V_104 -> V_145 )
V_3 -> V_104 -> V_145 ( V_49 , V_43 ,
( V_125 & V_146 )
>> V_139 ) ;
}
return 0 ;
}
static void F_68 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_124 )
{
unsigned long V_125 ;
int V_147 , V_148 = 0 ;
F_66 ( V_13 , V_124 , & V_125 ) ;
F_69 ( V_127 ) ;
F_69 ( V_128 ) ;
F_69 ( V_135 ) ;
F_69 ( V_137 ) ;
F_69 ( V_130 ) ;
F_70 ( V_146 , V_84 ) ;
F_70 ( V_146 , V_149 ) ;
F_70 ( V_146 , V_85 ) ;
F_69 ( V_132 ) ;
if ( V_125 & V_132 ) {
V_147 = V_125 >> V_133 ;
F_8 ( V_17 , L_20 , V_147 ) ;
}
return;
}
static void F_71 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_33 )
{
}
static void F_72 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_19 * V_150 ;
F_73 (np, child) {
if ( F_74 ( V_150 , V_151 ) ) {
if ( F_75 ( V_150 ) )
V_3 -> V_152 ++ ;
} else {
V_3 -> V_112 ++ ;
V_3 -> V_7 += F_76 ( V_150 ) ;
}
}
}
static int F_77 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
int V_101 = 0 ;
int V_153 ;
const T_4 * V_154 ;
V_154 = F_78 ( V_20 , L_21 , & V_153 ) ;
if ( ! V_154 ) {
F_11 ( V_3 -> V_9 , L_22 , V_153 ) ;
return - V_15 ;
}
V_153 /= sizeof( * V_154 ) ;
if ( ! V_153 || V_153 % V_92 ) {
F_11 ( V_3 -> V_9 , L_23 , V_92 ) ;
return - V_15 ;
}
V_3 -> V_94 = V_153 / V_92 ;
V_3 -> V_95 = F_12 ( V_3 -> V_9 , sizeof( T_2 ) * V_153 , V_27 ) ;
if ( ! V_3 -> V_95 ) {
F_11 ( V_3 -> V_9 , L_24 ) ;
return - V_28 ;
}
V_101 = F_79 ( V_20 , L_21 ,
V_3 -> V_95 , V_153 ) ;
if ( V_101 )
F_11 ( V_3 -> V_9 , L_22 , V_153 ) ;
return V_101 ;
}
static int F_80 ( struct V_19 * V_20 ,
struct V_1 * V_5 ,
struct V_2 * V_3 , T_2 V_91 )
{
struct V_90 * V_43 ;
int V_153 ;
const T_4 * V_154 ;
int V_6 , V_155 ;
F_2 ( V_3 -> V_9 , L_25 , V_91 , V_20 -> V_4 ) ;
V_5 -> V_4 = V_20 -> V_4 ;
V_154 = F_78 ( V_20 , L_26 , & V_153 ) ;
V_153 /= sizeof( * V_154 ) ;
if ( ! V_153 || V_153 % 4 ) {
F_11 ( V_3 -> V_9 , L_27 ) ;
return - V_15 ;
}
V_5 -> V_10 = V_153 / 4 ;
V_43 = V_5 -> V_37 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( struct V_90 ) ,
V_27 ) ;
V_5 -> V_11 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( unsigned int ) ,
V_27 ) ;
if ( ! V_5 -> V_37 || ! V_5 -> V_11 )
return - V_28 ;
for ( V_6 = 0 , V_155 = 0 ; V_6 < V_153 ; V_6 += 4 , V_155 ++ ) {
V_43 -> V_40 = F_81 ( * V_154 ++ ) ;
V_43 -> V_43 = F_81 ( * V_154 ++ ) ;
V_5 -> V_11 [ V_155 ] = V_43 -> V_40 * V_44 + V_43 -> V_43 ;
V_43 -> V_31 = F_81 ( * V_154 ++ ) ;
V_43 -> V_38 = F_81 ( * V_154 ++ ) ;
F_55 ( V_3 -> V_9 , V_43 ) ;
V_43 ++ ;
}
return 0 ;
}
static int F_82 ( struct V_19 * V_20 ,
struct V_2 * V_3 , T_2 V_91 )
{
struct V_19 * V_150 ;
struct V_156 * V_157 ;
struct V_1 * V_5 ;
int V_101 ;
static T_2 V_158 ;
T_2 V_6 = 0 ;
F_2 ( V_3 -> V_9 , L_28 , V_91 , V_20 -> V_4 ) ;
V_157 = & V_3 -> V_102 [ V_91 ] ;
V_157 -> V_4 = V_20 -> V_4 ;
V_157 -> V_7 = F_76 ( V_20 ) ;
if ( V_157 -> V_7 == 0 ) {
F_11 ( V_3 -> V_9 , L_29 ) ;
return - V_15 ;
}
V_157 -> V_8 = F_12 ( V_3 -> V_9 ,
V_157 -> V_7 * sizeof( char * ) , V_27 ) ;
if ( ! V_157 -> V_8 )
return - V_28 ;
F_73 (np, child) {
V_157 -> V_8 [ V_6 ] = V_150 -> V_4 ;
V_5 = & V_3 -> V_8 [ V_158 ++ ] ;
V_101 = F_80 ( V_150 , V_5 , V_3 , V_6 ++ ) ;
if ( V_101 ) {
F_15 ( V_150 ) ;
return V_101 ;
}
}
return 0 ;
}
static int F_83 ( struct V_159 * V_160 ,
struct V_2 * V_3 )
{
int V_101 = 0 ;
int V_6 , V_155 ;
T_3 * V_82 ;
struct V_19 * V_20 = V_160 -> V_9 . V_161 ;
struct V_19 * V_150 ;
if ( ! V_20 )
return - V_162 ;
V_3 -> V_9 = & V_160 -> V_9 ;
V_3 -> V_104 = (struct V_163 * )
F_84 ( V_164 , & V_160 -> V_9 ) -> V_30 ;
F_72 ( V_3 , V_20 ) ;
if ( V_92 < 1 ) {
F_11 ( & V_160 -> V_9 , L_30 ) ;
return - V_15 ;
}
V_101 = F_77 ( V_3 , V_20 ) ;
if ( V_101 )
return V_101 ;
F_2 ( & V_160 -> V_9 , L_31 , V_3 -> V_94 ) ;
F_2 ( & V_160 -> V_9 , L_32 ) ;
V_82 = V_3 -> V_95 ;
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ ) {
for ( V_155 = 0 ; V_155 < V_3 -> V_94 ; V_155 ++ , V_82 ++ ) {
F_2 ( & V_160 -> V_9 , L_33 , V_6 , V_155 , V_82 [ 0 ] ) ;
}
}
F_2 ( & V_160 -> V_9 , L_34 , V_3 -> V_112 ) ;
F_2 ( & V_160 -> V_9 , L_35 , V_3 -> V_7 ) ;
V_3 -> V_102 = F_12 ( & V_160 -> V_9 , V_3 -> V_112 * sizeof( struct V_156 ) ,
V_27 ) ;
if ( ! V_3 -> V_102 )
return - V_28 ;
V_3 -> V_8 = F_12 ( & V_160 -> V_9 , V_3 -> V_7 * sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_3 -> V_8 )
return - V_28 ;
F_2 ( & V_160 -> V_9 , L_36 , V_92 ) ;
F_2 ( & V_160 -> V_9 , L_34 , V_3 -> V_112 ) ;
F_2 ( & V_160 -> V_9 , L_35 , V_3 -> V_7 ) ;
V_6 = 0 ;
F_73 (np, child) {
if ( F_74 ( V_150 , V_151 ) )
continue;
V_101 = F_82 ( V_150 , V_3 , V_6 ++ ) ;
if ( V_101 ) {
F_11 ( & V_160 -> V_9 , L_37 ) ;
F_15 ( V_150 ) ;
return V_101 ;
}
}
return 0 ;
}
static int F_85 ( struct V_159 * V_160 )
{
struct V_2 * V_3 ;
struct V_165 * V_166 ;
int V_101 , V_6 , V_155 , V_167 , V_168 = 0 ;
V_3 = F_12 ( & V_160 -> V_9 , sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_101 = F_83 ( V_160 , V_3 ) ;
if ( V_101 )
return V_101 ;
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ )
if ( V_41 [ V_6 ] )
V_168 ++ ;
if ( V_168 < V_3 -> V_152 ) {
F_86 ( & V_160 -> V_9 ,
L_38 ,
V_168 , V_3 -> V_152 ) ;
F_14 ( & V_160 -> V_9 , V_3 ) ;
return - V_169 ;
}
V_170 . V_4 = F_9 ( & V_160 -> V_9 ) ;
V_170 . V_10 = V_92 * V_44 ;
V_170 . V_11 = V_166 =
F_12 ( & V_160 -> V_9 , sizeof( * V_166 ) * V_170 . V_10 , V_27 ) ;
if ( ! V_170 . V_11 )
return - V_28 ;
for ( V_6 = 0 , V_167 = 0 ; V_6 < V_92 ; V_6 ++ ) {
for ( V_155 = 0 ; V_155 < V_44 ; V_155 ++ , V_167 ++ ) {
V_166 -> V_171 = V_167 ;
V_166 -> V_4 = F_87 ( V_27 , L_39 , V_6 + 'A' , V_155 ) ;
V_166 ++ ;
}
}
F_88 ( V_160 , V_3 ) ;
V_3 -> V_172 = F_89 ( & V_160 -> V_9 , & V_170 ,
V_3 ) ;
if ( F_90 ( V_3 -> V_172 ) ) {
F_11 ( & V_160 -> V_9 , L_40 ) ;
return F_91 ( V_3 -> V_172 ) ;
}
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ )
if ( V_41 [ V_6 ] )
F_92 ( V_3 -> V_172 , & V_41 [ V_6 ] -> V_115 ) ;
F_93 ( & V_160 -> V_9 , L_41 ) ;
return 0 ;
}
static int F_94 ( struct V_119 * V_120 , unsigned V_18 )
{
struct V_117 * V_173 = F_64 ( V_120 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
T_2 V_174 ;
V_174 = F_27 ( V_49 + V_175 ) ;
return ! ( V_174 & V_50 ) ;
}
static int F_95 ( struct V_119 * V_120 , unsigned V_18 )
{
struct V_117 * V_173 = F_64 ( V_120 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + V_99 ) ;
return 0 ;
}
static int F_96 ( struct V_119 * V_120 , unsigned V_18 )
{
struct V_117 * V_173 = F_64 ( V_120 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
T_2 V_176 ;
V_176 = F_27 ( V_49 + V_177 ) ;
return ( V_176 & V_50 ) != 0 ;
}
static void F_97 ( struct V_119 * V_120 , unsigned V_18 ,
int V_147 )
{
struct V_117 * V_173 = F_64 ( V_120 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + ( V_147 ? V_178 : V_179 ) ) ;
}
static void F_98 ( struct V_119 * V_120 ,
unsigned long * V_50 , unsigned long * V_180 )
{
struct V_117 * V_173 = F_64 ( V_120 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
#define F_99 ( V_180 ) (((bits) == 32) ? ~0U : (BIT(bits) - 1))
T_3 V_181 = ( * V_50 & * V_180 ) & F_99 ( V_120 -> V_182 ) ;
T_3 V_183 = ( * V_50 & ~ ( * V_180 ) ) & F_99 ( V_120 -> V_182 ) ;
F_25 ( V_181 , V_49 + V_178 ) ;
F_25 ( V_183 , V_49 + V_179 ) ;
}
static int F_100 ( struct V_119 * V_120 , unsigned V_18 ,
int V_147 )
{
struct V_117 * V_173 = F_64 ( V_120 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + ( V_147 ? V_178 : V_179 ) ) ;
F_25 ( V_50 , V_49 + V_100 ) ;
return 0 ;
}
static void F_101 ( struct V_16 * V_17 , struct V_119 * V_120 )
{
enum V_64 V_184 ;
int V_6 ;
struct V_117 * V_173 = F_64 ( V_120 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
for ( V_6 = 0 ; V_6 < V_120 -> V_182 ; V_6 ++ ) {
unsigned V_50 = F_20 ( V_6 ) ;
const char * V_185 ;
V_185 = F_102 ( V_120 , V_6 ) ;
if ( ! V_185 )
continue;
V_184 = V_173 -> V_104 -> V_186 ( V_49 , V_50 ) ;
F_8 ( V_17 , L_42 ,
V_185 , V_120 -> V_187 , V_6 ) ;
if ( V_184 == V_67 ) {
F_8 ( V_17 , L_43 ) ;
F_8 ( V_17 , L_44 ,
F_27 ( V_49 + V_175 ) & V_50 ?
L_45 : L_46 ) ;
F_8 ( V_17 , L_47 ,
F_27 ( V_49 + V_177 ) & V_50 ?
L_48 : L_49 ) ;
} else {
F_8 ( V_17 , L_50 ,
V_184 + 'A' - 1 ) ;
}
}
}
static void F_103 ( struct V_188 * V_189 )
{
struct V_117 * V_173 = F_104 ( V_189 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_189 -> V_190 ;
if ( V_49 )
F_25 ( V_50 , V_49 + V_51 ) ;
}
static void F_105 ( struct V_188 * V_189 )
{
struct V_117 * V_173 = F_104 ( V_189 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_189 -> V_190 ;
if ( V_49 )
F_25 ( V_50 , V_49 + V_191 ) ;
}
static int F_106 ( struct V_188 * V_189 , unsigned type )
{
switch ( type ) {
case V_192 :
case V_193 :
return 0 ;
default:
return - V_15 ;
}
}
static int F_107 ( struct V_188 * V_189 , unsigned type )
{
struct V_117 * V_173 = F_104 ( V_189 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned V_50 = 1 << V_189 -> V_190 ;
switch ( type ) {
case V_194 :
F_108 ( V_189 , V_195 ) ;
F_25 ( V_50 , V_49 + V_196 ) ;
F_25 ( V_50 , V_49 + V_197 ) ;
break;
case V_198 :
F_108 ( V_189 , V_195 ) ;
F_25 ( V_50 , V_49 + V_196 ) ;
F_25 ( V_50 , V_49 + V_199 ) ;
break;
case V_200 :
F_108 ( V_189 , V_201 ) ;
F_25 ( V_50 , V_49 + V_202 ) ;
F_25 ( V_50 , V_49 + V_199 ) ;
break;
case V_203 :
F_108 ( V_189 , V_201 ) ;
F_25 ( V_50 , V_49 + V_202 ) ;
F_25 ( V_50 , V_49 + V_197 ) ;
break;
case V_193 :
F_108 ( V_189 , V_195 ) ;
F_25 ( V_50 , V_49 + V_204 ) ;
return 0 ;
case V_192 :
default:
F_109 ( L_51 , F_110 ( V_189 -> V_205 ) ) ;
return - V_15 ;
}
F_25 ( V_50 , V_49 + V_206 ) ;
return 0 ;
}
static void F_111 ( struct V_188 * V_189 )
{
}
static int F_112 ( struct V_188 * V_189 , unsigned V_207 )
{
struct V_117 * V_173 = F_104 ( V_189 ) ;
unsigned V_40 = V_173 -> V_208 ;
unsigned V_50 = 1 << V_189 -> V_190 ;
if ( F_113 ( V_40 >= V_209 ) )
return - V_15 ;
if ( V_207 )
V_210 [ V_40 ] |= V_50 ;
else
V_210 [ V_40 ] &= ~ V_50 ;
F_114 ( V_173 -> V_211 , V_207 ) ;
return 0 ;
}
void F_115 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ ) {
void T_1 * V_49 ;
if ( ! V_41 [ V_6 ] )
continue;
V_49 = V_41 [ V_6 ] -> V_42 ;
V_212 [ V_6 ] = F_27 ( V_49 + V_213 ) ;
F_25 ( V_212 [ V_6 ] , V_49 + V_51 ) ;
F_25 ( V_210 [ V_6 ] , V_49 + V_191 ) ;
if ( ! V_210 [ V_6 ] )
F_116 ( V_41 [ V_6 ] -> clock ) ;
else
F_117 ( V_214 L_52 ,
'A' + V_6 , V_210 [ V_6 ] ) ;
}
}
void F_118 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_92 ; V_6 ++ ) {
void T_1 * V_49 ;
if ( ! V_41 [ V_6 ] )
continue;
V_49 = V_41 [ V_6 ] -> V_42 ;
if ( ! V_210 [ V_6 ] )
F_119 ( V_41 [ V_6 ] -> clock ) ;
F_25 ( V_210 [ V_6 ] , V_49 + V_51 ) ;
F_25 ( V_212 [ V_6 ] , V_49 + V_191 ) ;
}
}
static void F_120 ( struct V_215 * V_216 )
{
struct V_217 * V_120 = F_121 ( V_216 ) ;
struct V_119 * V_119 = F_122 ( V_216 ) ;
struct V_117 * V_173 = F_64 ( V_119 ) ;
void T_1 * V_49 = V_173 -> V_42 ;
unsigned long V_218 ;
int V_219 ;
F_123 ( V_120 , V_216 ) ;
for (; ; ) {
V_218 = F_27 ( V_49 + V_220 ) & F_27 ( V_49 + V_213 ) ;
if ( ! V_218 ) {
if ( ! V_173 -> V_221 )
break;
V_173 = V_173 -> V_221 ;
V_49 = V_173 -> V_42 ;
V_119 = & V_173 -> V_120 ;
continue;
}
F_124 (n, &isr, BITS_PER_LONG) {
F_125 ( F_126 (
V_119 -> V_222 , V_219 ) ) ;
}
}
F_127 ( V_120 , V_216 ) ;
}
static int F_128 ( struct V_159 * V_160 ,
struct V_117 * V_173 )
{
struct V_119 * V_223 = NULL ;
struct V_117 * V_224 = NULL ;
struct V_188 * V_189 = F_129 ( V_173 -> V_211 ) ;
int V_101 , V_6 ;
V_173 -> V_225 = F_130 ( V_189 ) ;
V_226 . V_227 = V_173 -> V_104 -> V_228 ;
F_25 ( ~ 0 , V_173 -> V_42 + V_51 ) ;
V_101 = F_131 ( & V_173 -> V_120 ,
& V_226 ,
0 ,
V_229 ,
V_193 ) ;
if ( V_101 ) {
F_11 ( & V_160 -> V_9 , L_53 ,
V_173 -> V_208 ) ;
return V_101 ;
}
V_223 = F_132 ( V_173 -> V_211 ) ;
if ( ! V_223 ) {
F_133 ( & V_173 -> V_120 ,
& V_226 ,
V_173 -> V_211 ,
F_120 ) ;
return 0 ;
}
V_224 = F_64 ( V_223 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
if ( V_224 -> V_221 ) {
V_224 = V_224 -> V_221 ;
} else {
V_224 -> V_221 = V_173 ;
return 0 ;
}
}
return - V_15 ;
}
static int F_134 ( struct V_159 * V_160 )
{
struct V_19 * V_20 = V_160 -> V_9 . V_161 ;
struct V_230 * V_231 ;
struct V_117 * V_118 = NULL ;
struct V_119 * V_120 ;
struct V_114 * V_115 ;
int V_101 = 0 ;
int V_205 , V_6 ;
int V_232 = F_135 ( V_20 , L_54 ) ;
T_3 V_182 ;
char * * V_233 ;
F_136 ( V_232 >= F_137 ( V_41 ) ) ;
if ( V_41 [ V_232 ] ) {
V_101 = - V_234 ;
goto V_235;
}
V_205 = F_138 ( V_160 , 0 ) ;
if ( V_205 < 0 ) {
V_101 = V_205 ;
goto V_235;
}
V_118 = F_12 ( & V_160 -> V_9 , sizeof( * V_118 ) , V_27 ) ;
if ( ! V_118 ) {
V_101 = - V_28 ;
goto V_235;
}
V_231 = F_139 ( V_160 , V_236 , 0 ) ;
V_118 -> V_42 = F_140 ( & V_160 -> V_9 , V_231 ) ;
if ( F_90 ( V_118 -> V_42 ) ) {
V_101 = F_91 ( V_118 -> V_42 ) ;
goto V_235;
}
V_118 -> V_104 = (struct V_163 * )
F_84 ( V_237 , & V_160 -> V_9 ) -> V_30 ;
V_118 -> V_211 = V_205 ;
V_118 -> V_208 = V_232 ;
V_118 -> clock = F_141 ( & V_160 -> V_9 , NULL ) ;
if ( F_90 ( V_118 -> clock ) ) {
F_11 ( & V_160 -> V_9 , L_55 ) ;
V_101 = F_91 ( V_118 -> clock ) ;
goto V_235;
}
V_101 = F_119 ( V_118 -> clock ) ;
if ( V_101 ) {
F_11 ( & V_160 -> V_9 , L_56 ) ;
goto V_238;
}
V_118 -> V_120 = V_239 ;
V_120 = & V_118 -> V_120 ;
V_120 -> V_161 = V_20 ;
V_120 -> V_187 = F_9 ( & V_160 -> V_9 ) ;
V_120 -> V_25 = & V_160 -> V_9 ;
V_120 -> V_240 = V_241 ;
V_120 -> V_122 = V_232 * V_44 ;
if ( ! F_142 ( V_20 , L_57 , & V_182 ) ) {
if ( V_182 >= V_44 )
F_143 ( L_58 ,
V_232 , V_44 , V_44 ) ;
else
V_120 -> V_182 = V_182 ;
}
V_233 = F_12 ( & V_160 -> V_9 , sizeof( char * ) * V_120 -> V_182 ,
V_27 ) ;
if ( ! V_233 ) {
V_101 = - V_28 ;
goto V_238;
}
for ( V_6 = 0 ; V_6 < V_120 -> V_182 ; V_6 ++ )
V_233 [ V_6 ] = F_87 ( V_27 , L_39 , V_232 + 'A' , V_6 ) ;
V_120 -> V_233 = ( const char * const * ) V_233 ;
V_115 = & V_118 -> V_115 ;
V_115 -> V_4 = V_120 -> V_187 ;
V_115 -> V_123 = V_232 ;
V_115 -> V_242 = V_115 -> V_122 = V_115 -> V_123 * V_44 ;
V_115 -> V_10 = V_120 -> V_182 ;
V_115 -> V_121 = V_120 ;
V_101 = F_144 ( V_120 , V_118 ) ;
if ( V_101 )
goto V_243;
V_41 [ V_232 ] = V_118 ;
V_92 = F_145 ( V_92 , V_232 + 1 ) ;
V_101 = F_128 ( V_160 , V_118 ) ;
if ( V_101 )
goto V_244;
F_93 ( & V_160 -> V_9 , L_59 , V_118 -> V_42 ) ;
return 0 ;
V_244:
F_146 ( V_120 ) ;
V_243:
V_238:
F_116 ( V_118 -> clock ) ;
V_235:
F_11 ( & V_160 -> V_9 , L_60 , V_101 , V_232 ) ;
return V_101 ;
}
static int T_5 F_147 ( void )
{
return F_148 ( V_245 , F_137 ( V_245 ) ) ;
}
static void T_6 F_149 ( void )
{
F_150 ( V_245 , F_137 ( V_245 ) ) ;
}
