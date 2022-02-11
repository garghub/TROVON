static inline const struct V_1 * F_1 (
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
static bool F_29 ( void T_1 * V_49 , unsigned int V_43 , bool * V_57 )
{
* V_57 = ( F_27 ( V_49 + V_58 ) >> V_43 ) & 0x1 ;
return ( F_27 ( V_49 + V_59 ) >> V_43 ) & 0x1 ;
}
static void F_30 ( void T_1 * V_49 , unsigned int V_50 ,
bool V_60 , bool V_57 )
{
F_25 ( V_50 , V_49 + ( V_57 ? V_61 : V_62 ) ) ;
F_25 ( V_50 , V_49 + ( V_60 ? V_63 : V_64 ) ) ;
}
static unsigned F_31 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_27 ( V_49 + V_65 ) >> V_43 ) & 0x1 ;
}
static void F_32 ( void T_1 * V_49 , unsigned V_50 , bool V_53 )
{
F_25 ( V_50 , V_49 + ( V_53 ? V_66 : V_67 ) ) ;
}
static void F_33 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_68 ) ;
}
static void F_34 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_69 ) ;
}
static void F_35 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_70 ) & ~ V_50 ,
V_49 + V_70 ) ;
F_25 ( F_27 ( V_49 + V_71 ) & ~ V_50 ,
V_49 + V_71 ) ;
}
static void F_36 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_70 ) | V_50 ,
V_49 + V_70 ) ;
F_25 ( F_27 ( V_49 + V_71 ) & ~ V_50 ,
V_49 + V_71 ) ;
}
static void F_37 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_70 ) & ~ V_50 , V_49 + V_70 ) ;
F_25 ( F_27 ( V_49 + V_71 ) | V_50 , V_49 + V_71 ) ;
}
static void F_38 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_70 ) | V_50 , V_49 + V_70 ) ;
F_25 ( F_27 ( V_49 + V_71 ) | V_50 , V_49 + V_71 ) ;
}
static enum V_72 F_39 ( void T_1 * V_49 , unsigned V_50 )
{
unsigned V_73 ;
if ( F_27 ( V_49 + V_74 ) & V_50 )
return V_75 ;
V_73 = ! ! ( F_27 ( V_49 + V_70 ) & V_50 ) ;
V_73 |= ( ! ! ( F_27 ( V_49 + V_71 ) & V_50 ) << 1 ) ;
return V_73 + 1 ;
}
static enum V_72 F_40 ( void T_1 * V_49 , unsigned V_50 )
{
unsigned V_73 ;
if ( F_27 ( V_49 + V_74 ) & V_50 )
return V_75 ;
V_73 = F_27 ( V_49 + V_76 ) & V_50 ;
return V_73 + 1 ;
}
static bool F_41 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_27 ( V_49 + V_77 ) >> V_43 ) & 0x1 ;
}
static void F_42 ( void T_1 * V_49 , unsigned V_50 , bool V_60 )
{
F_25 ( V_50 , V_49 + ( V_60 ? V_78 : V_79 ) ) ;
}
static bool F_43 ( void T_1 * V_49 , unsigned V_43 )
{
if ( ( F_27 ( V_49 + V_77 ) >> V_43 ) & 0x1 )
return ! ( ( F_27 ( V_49 + V_80 ) >> V_43 ) & 0x1 ) ;
return false ;
}
static void F_44 ( void T_1 * V_49 , unsigned V_50 , bool V_60 )
{
if ( V_60 )
F_25 ( V_50 , V_49 + V_81 ) ;
F_42 ( V_49 , V_50 , V_60 ) ;
}
static bool F_45 ( void T_1 * V_49 , unsigned V_43 , T_2 * div )
{
* div = F_27 ( V_49 + V_82 ) ;
return ( ( F_27 ( V_49 + V_77 ) >> V_43 ) & 0x1 ) &&
( ( F_27 ( V_49 + V_80 ) >> V_43 ) & 0x1 ) ;
}
static void F_46 ( void T_1 * V_49 , unsigned V_50 ,
bool V_60 , T_2 div )
{
if ( V_60 ) {
F_25 ( V_50 , V_49 + V_83 ) ;
F_25 ( div & V_84 , V_49 + V_82 ) ;
F_25 ( V_50 , V_49 + V_78 ) ;
} else
F_25 ( V_50 , V_49 + V_81 ) ;
}
static bool F_47 ( void T_1 * V_49 , unsigned V_43 )
{
return ! ( ( F_27 ( V_49 + V_85 ) >> V_43 ) & 0x1 ) ;
}
static void F_48 ( void T_1 * V_49 , unsigned V_50 , bool V_60 )
{
if ( V_60 )
F_25 ( V_50 , V_49 + V_56 ) ;
F_25 ( V_50 , V_49 + ( V_60 ? V_86 : V_54 ) ) ;
}
static void F_49 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( F_27 ( V_49 + V_87 ) | V_50 , V_49 + V_87 ) ;
}
static bool F_50 ( void T_1 * V_49 , unsigned V_43 )
{
return ( F_27 ( V_49 + V_87 ) >> V_43 ) & 0x1 ;
}
static inline T_2 F_51 ( void T_1 * V_88 , unsigned V_43 )
{
unsigned V_89 = F_27 ( V_88 ) ;
V_89 = V_89 >> F_21 ( V_43 ) ;
return V_89 & V_90 ;
}
static unsigned F_52 ( void T_1 * V_49 ,
unsigned V_43 )
{
unsigned V_89 = F_51 ( V_49 +
F_22 ( V_43 ) , V_43 ) ;
if ( ! V_89 )
V_89 = V_91 ;
return V_89 ;
}
static unsigned F_53 ( void T_1 * V_49 ,
unsigned V_43 )
{
unsigned V_89 = F_51 ( V_49 +
F_23 ( V_43 ) , V_43 ) ;
V_89 = V_92 - V_89 ;
return V_89 ;
}
static void F_54 ( void T_1 * V_88 , unsigned V_43 , T_2 V_93 )
{
unsigned V_89 = F_27 ( V_88 ) ;
unsigned V_94 = F_21 ( V_43 ) ;
V_89 &= ~ ( V_90 << V_94 ) ;
V_89 |= V_93 << V_94 ;
F_25 ( V_89 , V_88 ) ;
}
static void F_55 ( void T_1 * V_49 , unsigned V_43 ,
T_2 V_95 )
{
if ( ! V_95 )
return;
F_54 ( V_49 + F_22 ( V_43 ) , V_43 , V_95 ) ;
}
static void F_56 ( void T_1 * V_49 , unsigned V_43 ,
T_2 V_95 )
{
if ( ! V_95 )
return;
V_95 = V_92 - V_95 ;
F_54 ( V_49 + F_23 ( V_43 ) , V_43 ,
V_95 ) ;
}
static void F_57 ( const struct V_96 * V_9 , const struct V_97 * V_43 )
{
if ( V_43 -> V_31 ) {
F_2 ( V_9 , L_5 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_31 - 1 + 'A' , V_43 -> V_38 ) ;
} else {
F_2 ( V_9 , L_6 ,
V_43 -> V_40 + 'A' , V_43 -> V_43 , V_43 -> V_38 ) ;
}
}
static int F_58 ( struct V_2 * V_3 , const char * V_4 ,
int V_98 , const struct V_97 * V_43 )
{
int V_31 ;
if ( V_43 -> V_40 >= V_99 ) {
F_11 ( V_3 -> V_9 , L_7 ,
V_4 , V_98 , V_43 -> V_40 , V_99 ) ;
return - V_15 ;
}
if ( ! V_41 [ V_43 -> V_40 ] ) {
F_11 ( V_3 -> V_9 , L_8 ,
V_4 , V_98 , V_43 -> V_40 ) ;
return - V_100 ;
}
if ( V_43 -> V_43 >= V_44 ) {
F_11 ( V_3 -> V_9 , L_9 ,
V_4 , V_98 , V_43 -> V_43 , V_44 ) ;
return - V_15 ;
}
if ( ! V_43 -> V_31 )
return 0 ;
V_31 = V_43 -> V_31 - 1 ;
if ( V_31 >= V_3 -> V_101 ) {
F_11 ( V_3 -> V_9 , L_10 ,
V_4 , V_98 , V_31 , V_3 -> V_101 ) ;
return - V_15 ;
}
if ( ! ( V_3 -> V_102 [ V_43 -> V_40 * V_3 -> V_101 + V_31 ] & 1 << V_43 -> V_43 ) ) {
F_11 ( V_3 -> V_9 , L_11 ,
V_4 , V_98 , V_31 , V_43 -> V_40 + 'A' , V_43 -> V_43 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_59 ( void T_1 * V_49 , unsigned V_50 )
{
F_25 ( V_50 , V_49 + V_103 ) ;
}
static void F_60 ( void T_1 * V_49 , unsigned V_50 , bool V_104 )
{
F_25 ( V_50 , V_49 + V_105 ) ;
F_25 ( V_50 , V_49 + ( V_104 ? V_64 : V_63 ) ) ;
}
static int F_61 ( struct V_12 * V_13 , unsigned V_14 ,
unsigned V_33 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
const struct V_97 * V_37 = V_3 -> V_8 [ V_33 ] . V_37 ;
const struct V_97 * V_43 ;
T_3 V_10 = V_3 -> V_8 [ V_33 ] . V_10 ;
int V_6 , V_106 ;
unsigned V_50 ;
void T_1 * V_49 ;
F_2 ( V_3 -> V_9 , L_12 ,
V_3 -> V_107 [ V_14 ] . V_4 , V_3 -> V_8 [ V_33 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
V_106 = F_58 ( V_3 , V_3 -> V_8 [ V_33 ] . V_4 , V_6 , V_43 ) ;
if ( V_106 )
return V_106 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ ) {
V_43 = & V_37 [ V_6 ] ;
F_57 ( V_3 -> V_9 , V_43 ) ;
V_49 = F_18 ( V_3 , V_43 -> V_40 ) ;
if ( ! V_49 )
continue;
V_50 = F_20 ( V_43 -> V_43 ) ;
F_24 ( V_49 , V_50 ) ;
switch ( V_43 -> V_31 ) {
case V_75 :
F_60 ( V_49 , V_50 , 1 ) ;
break;
case V_108 :
V_3 -> V_109 -> V_110 ( V_49 , V_50 ) ;
break;
case V_111 :
V_3 -> V_109 -> V_112 ( V_49 , V_50 ) ;
break;
case V_113 :
if ( ! V_3 -> V_109 -> V_114 )
return - V_15 ;
V_3 -> V_109 -> V_114 ( V_49 , V_50 ) ;
break;
case V_115 :
if ( ! V_3 -> V_109 -> V_116 )
return - V_15 ;
V_3 -> V_109 -> V_116 ( V_49 , V_50 ) ;
break;
}
if ( V_43 -> V_31 )
F_59 ( V_49 , V_50 ) ;
}
return 0 ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_117 ;
}
static const char * F_63 ( struct V_12 * V_13 ,
unsigned V_14 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_107 [ V_14 ] . V_4 ;
}
static int F_64 ( struct V_12 * V_13 , unsigned V_14 ,
const char * const * * V_8 ,
unsigned * const V_118 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_8 = V_3 -> V_107 [ V_14 ] . V_8 ;
* V_118 = V_3 -> V_107 [ V_14 ] . V_7 ;
return 0 ;
}
static int F_65 ( struct V_12 * V_13 ,
struct V_119 * V_120 ,
unsigned V_18 )
{
struct V_2 * V_121 = F_4 ( V_13 ) ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
unsigned V_50 ;
if ( ! V_120 ) {
F_11 ( V_121 -> V_9 , L_13 ) ;
return - V_15 ;
}
if ( ! V_120 -> V_126 ) {
F_11 ( V_121 -> V_9 , L_14 ) ;
return - V_15 ;
}
V_125 = V_120 -> V_126 ;
V_123 = F_66 ( V_125 ) ;
F_2 ( V_121 -> V_9 , L_15 , V_18 ) ;
V_50 = 1 << ( V_18 - V_125 -> V_127 ) ;
F_2 ( V_121 -> V_9 , L_16 ,
V_18 , 'A' + V_120 -> V_128 , V_18 - V_125 -> V_127 , V_50 ) ;
F_25 ( V_50 , V_123 -> V_42 + V_105 ) ;
return 0 ;
}
static void F_67 ( struct V_12 * V_13 ,
struct V_119 * V_120 ,
unsigned V_18 )
{
struct V_2 * V_121 = F_4 ( V_13 ) ;
F_2 ( V_121 -> V_9 , L_17 , V_18 ) ;
}
static int F_68 ( struct V_12 * V_13 ,
unsigned V_129 , unsigned long * V_130 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
void T_1 * V_49 ;
unsigned V_43 ;
int div ;
bool V_131 ;
* V_130 = 0 ;
F_2 ( V_3 -> V_9 , L_18 , V_132 , __LINE__ , V_129 ) ;
V_49 = F_18 ( V_3 , F_19 ( V_129 ) ) ;
if ( ! V_49 )
return - V_15 ;
V_43 = V_129 % V_44 ;
if ( F_31 ( V_49 , V_43 ) )
* V_130 |= V_133 ;
if ( F_26 ( V_49 , V_43 ) )
* V_130 |= V_134 ;
if ( V_3 -> V_109 -> V_135 && V_3 -> V_109 -> V_135 ( V_49 , V_43 ) )
* V_130 |= V_136 ;
if ( V_3 -> V_109 -> V_137 && V_3 -> V_109 -> V_137 ( V_49 , V_43 , & div ) )
* V_130 |= V_138 | ( div << V_139 ) ;
if ( V_3 -> V_109 -> V_140 && V_3 -> V_109 -> V_140 ( V_49 , V_43 ) )
* V_130 |= V_141 ;
if ( V_3 -> V_109 -> V_142 && V_3 -> V_109 -> V_142 ( V_49 , V_43 ) )
* V_130 |= V_143 ;
if ( V_3 -> V_109 -> V_144 )
* V_130 |= ( V_3 -> V_109 -> V_144 ( V_49 , V_43 )
<< V_145 ) ;
if ( F_29 ( V_49 , V_43 , & V_131 ) )
* V_130 |= V_146 | ( V_131 << V_147 ) ;
return 0 ;
}
static int F_69 ( struct V_12 * V_13 ,
unsigned V_129 , unsigned long * V_35 ,
unsigned V_39 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
unsigned V_50 ;
void T_1 * V_49 ;
int V_6 ;
unsigned long V_130 ;
unsigned V_43 ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ ) {
V_130 = V_35 [ V_6 ] ;
F_2 ( V_3 -> V_9 ,
L_19 ,
V_132 , __LINE__ , V_129 , V_130 ) ;
V_49 = F_18 ( V_3 , F_19 ( V_129 ) ) ;
if ( ! V_49 )
return - V_15 ;
V_43 = V_129 % V_44 ;
V_50 = F_20 ( V_43 ) ;
if ( V_130 & V_134 && V_130 & V_141 )
return - V_15 ;
F_30 ( V_49 , V_50 , V_130 & V_146 ,
( V_130 & V_148 ) >> V_147 ) ;
F_28 ( V_49 , V_50 , V_130 & V_134 ) ;
F_32 ( V_49 , V_50 , V_130 & V_133 ) ;
if ( V_3 -> V_109 -> V_149 )
V_3 -> V_109 -> V_149 ( V_49 , V_50 , V_130 & V_136 ) ;
if ( V_3 -> V_109 -> V_150 )
V_3 -> V_109 -> V_150 ( V_49 , V_50 , V_130 & V_138 ,
( V_130 & V_151 ) >> V_139 ) ;
if ( V_3 -> V_109 -> V_152 )
V_3 -> V_109 -> V_152 ( V_49 , V_50 , V_130 & V_141 ) ;
if ( V_3 -> V_109 -> V_153 && V_130 & V_143 )
V_3 -> V_109 -> V_153 ( V_49 , V_50 ) ;
if ( V_3 -> V_109 -> V_154 )
V_3 -> V_109 -> V_154 ( V_49 , V_43 ,
( V_130 & V_155 )
>> V_145 ) ;
}
return 0 ;
}
static void F_70 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_129 )
{
unsigned long V_130 ;
int V_57 , V_156 = 0 ;
F_68 ( V_13 , V_129 , & V_130 ) ;
F_71 ( V_133 ) ;
F_71 ( V_134 ) ;
F_71 ( V_141 ) ;
F_71 ( V_143 ) ;
F_71 ( V_136 ) ;
F_72 ( V_155 , V_91 ) ;
F_72 ( V_155 , V_157 ) ;
F_72 ( V_155 , V_92 ) ;
F_71 ( V_138 ) ;
if ( V_130 & V_138 ) {
V_57 = V_130 >> V_139 ;
F_8 ( V_17 , L_20 , V_57 ) ;
}
return;
}
static void F_73 ( struct V_12 * V_13 ,
struct V_16 * V_17 , unsigned V_33 )
{
}
static void F_74 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
struct V_19 * V_158 ;
F_75 (np, child) {
if ( F_76 ( V_158 , V_159 ) ) {
if ( F_77 ( V_158 ) )
V_3 -> V_160 ++ ;
} else {
V_3 -> V_117 ++ ;
V_3 -> V_7 += F_78 ( V_158 ) ;
}
}
}
static int F_79 ( struct V_2 * V_3 ,
struct V_19 * V_20 )
{
int V_106 = 0 ;
int V_161 ;
const T_4 * V_162 ;
V_162 = F_80 ( V_20 , L_21 , & V_161 ) ;
if ( ! V_162 ) {
F_11 ( V_3 -> V_9 , L_22 , V_161 ) ;
return - V_15 ;
}
V_161 /= sizeof( * V_162 ) ;
if ( ! V_161 || V_161 % V_99 ) {
F_11 ( V_3 -> V_9 , L_23 , V_99 ) ;
return - V_15 ;
}
V_3 -> V_101 = V_161 / V_99 ;
V_3 -> V_102 = F_12 ( V_3 -> V_9 , sizeof( T_2 ) * V_161 , V_27 ) ;
if ( ! V_3 -> V_102 ) {
F_11 ( V_3 -> V_9 , L_24 ) ;
return - V_28 ;
}
V_106 = F_81 ( V_20 , L_21 ,
V_3 -> V_102 , V_161 ) ;
if ( V_106 )
F_11 ( V_3 -> V_9 , L_22 , V_161 ) ;
return V_106 ;
}
static int F_82 ( struct V_19 * V_20 ,
struct V_1 * V_5 ,
struct V_2 * V_3 , T_2 V_98 )
{
struct V_97 * V_43 ;
int V_161 ;
const T_4 * V_162 ;
int V_6 , V_163 ;
F_2 ( V_3 -> V_9 , L_25 , V_98 , V_20 -> V_4 ) ;
V_5 -> V_4 = V_20 -> V_4 ;
V_162 = F_80 ( V_20 , L_26 , & V_161 ) ;
V_161 /= sizeof( * V_162 ) ;
if ( ! V_161 || V_161 % 4 ) {
F_11 ( V_3 -> V_9 , L_27 ) ;
return - V_15 ;
}
V_5 -> V_10 = V_161 / 4 ;
V_43 = V_5 -> V_37 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( struct V_97 ) ,
V_27 ) ;
V_5 -> V_11 = F_12 ( V_3 -> V_9 , V_5 -> V_10 * sizeof( unsigned int ) ,
V_27 ) ;
if ( ! V_5 -> V_37 || ! V_5 -> V_11 )
return - V_28 ;
for ( V_6 = 0 , V_163 = 0 ; V_6 < V_161 ; V_6 += 4 , V_163 ++ ) {
V_43 -> V_40 = F_83 ( * V_162 ++ ) ;
V_43 -> V_43 = F_83 ( * V_162 ++ ) ;
V_5 -> V_11 [ V_163 ] = V_43 -> V_40 * V_44 + V_43 -> V_43 ;
V_43 -> V_31 = F_83 ( * V_162 ++ ) ;
V_43 -> V_38 = F_83 ( * V_162 ++ ) ;
F_57 ( V_3 -> V_9 , V_43 ) ;
V_43 ++ ;
}
return 0 ;
}
static int F_84 ( struct V_19 * V_20 ,
struct V_2 * V_3 , T_2 V_98 )
{
struct V_19 * V_158 ;
struct V_164 * V_165 ;
struct V_1 * V_5 ;
int V_106 ;
static T_2 V_166 ;
T_2 V_6 = 0 ;
F_2 ( V_3 -> V_9 , L_28 , V_98 , V_20 -> V_4 ) ;
V_165 = & V_3 -> V_107 [ V_98 ] ;
V_165 -> V_4 = V_20 -> V_4 ;
V_165 -> V_7 = F_78 ( V_20 ) ;
if ( V_165 -> V_7 == 0 ) {
F_11 ( V_3 -> V_9 , L_29 ) ;
return - V_15 ;
}
V_165 -> V_8 = F_12 ( V_3 -> V_9 ,
V_165 -> V_7 * sizeof( char * ) , V_27 ) ;
if ( ! V_165 -> V_8 )
return - V_28 ;
F_75 (np, child) {
V_165 -> V_8 [ V_6 ] = V_158 -> V_4 ;
V_5 = & V_3 -> V_8 [ V_166 ++ ] ;
V_106 = F_82 ( V_158 , V_5 , V_3 , V_6 ++ ) ;
if ( V_106 ) {
F_15 ( V_158 ) ;
return V_106 ;
}
}
return 0 ;
}
static int F_85 ( struct V_167 * V_168 ,
struct V_2 * V_3 )
{
int V_106 = 0 ;
int V_6 , V_163 ;
T_3 * V_89 ;
struct V_19 * V_20 = V_168 -> V_9 . V_169 ;
struct V_19 * V_158 ;
if ( ! V_20 )
return - V_170 ;
V_3 -> V_9 = & V_168 -> V_9 ;
V_3 -> V_109 = (struct V_171 * )
F_86 ( V_172 , & V_168 -> V_9 ) -> V_30 ;
F_74 ( V_3 , V_20 ) ;
if ( V_99 < 1 ) {
F_11 ( & V_168 -> V_9 , L_30 ) ;
return - V_15 ;
}
V_106 = F_79 ( V_3 , V_20 ) ;
if ( V_106 )
return V_106 ;
F_2 ( & V_168 -> V_9 , L_31 , V_3 -> V_101 ) ;
F_2 ( & V_168 -> V_9 , L_32 ) ;
V_89 = V_3 -> V_102 ;
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ ) {
for ( V_163 = 0 ; V_163 < V_3 -> V_101 ; V_163 ++ , V_89 ++ ) {
F_2 ( & V_168 -> V_9 , L_33 , V_6 , V_163 , V_89 [ 0 ] ) ;
}
}
F_2 ( & V_168 -> V_9 , L_34 , V_3 -> V_117 ) ;
F_2 ( & V_168 -> V_9 , L_35 , V_3 -> V_7 ) ;
V_3 -> V_107 = F_12 ( & V_168 -> V_9 , V_3 -> V_117 * sizeof( struct V_164 ) ,
V_27 ) ;
if ( ! V_3 -> V_107 )
return - V_28 ;
V_3 -> V_8 = F_12 ( & V_168 -> V_9 , V_3 -> V_7 * sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_3 -> V_8 )
return - V_28 ;
F_2 ( & V_168 -> V_9 , L_36 , V_99 ) ;
F_2 ( & V_168 -> V_9 , L_34 , V_3 -> V_117 ) ;
F_2 ( & V_168 -> V_9 , L_35 , V_3 -> V_7 ) ;
V_6 = 0 ;
F_75 (np, child) {
if ( F_76 ( V_158 , V_159 ) )
continue;
V_106 = F_84 ( V_158 , V_3 , V_6 ++ ) ;
if ( V_106 ) {
F_11 ( & V_168 -> V_9 , L_37 ) ;
F_15 ( V_158 ) ;
return V_106 ;
}
}
return 0 ;
}
static int F_87 ( struct V_167 * V_168 )
{
struct V_2 * V_3 ;
struct V_173 * V_174 ;
int V_106 , V_6 , V_163 , V_175 , V_176 = 0 ;
V_3 = F_12 ( & V_168 -> V_9 , sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_106 = F_85 ( V_168 , V_3 ) ;
if ( V_106 )
return V_106 ;
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ )
if ( V_41 [ V_6 ] )
V_176 ++ ;
if ( V_176 < V_3 -> V_160 ) {
F_88 ( & V_168 -> V_9 ,
L_38 ,
V_176 , V_3 -> V_160 ) ;
F_14 ( & V_168 -> V_9 , V_3 ) ;
return - V_177 ;
}
V_178 . V_4 = F_9 ( & V_168 -> V_9 ) ;
V_178 . V_10 = V_99 * V_44 ;
V_178 . V_11 = V_174 =
F_12 ( & V_168 -> V_9 , sizeof( * V_174 ) * V_178 . V_10 , V_27 ) ;
if ( ! V_178 . V_11 )
return - V_28 ;
for ( V_6 = 0 , V_175 = 0 ; V_6 < V_99 ; V_6 ++ ) {
for ( V_163 = 0 ; V_163 < V_44 ; V_163 ++ , V_175 ++ ) {
V_174 -> V_179 = V_175 ;
V_174 -> V_4 = F_89 ( V_27 , L_39 , V_6 + 'A' , V_163 ) ;
V_174 ++ ;
}
}
F_90 ( V_168 , V_3 ) ;
V_3 -> V_180 = F_91 ( & V_168 -> V_9 , & V_178 ,
V_3 ) ;
if ( F_92 ( V_3 -> V_180 ) ) {
F_11 ( & V_168 -> V_9 , L_40 ) ;
return F_93 ( V_3 -> V_180 ) ;
}
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ )
if ( V_41 [ V_6 ] )
F_94 ( V_3 -> V_180 , & V_41 [ V_6 ] -> V_120 ) ;
F_95 ( & V_168 -> V_9 , L_41 ) ;
return 0 ;
}
static int F_96 ( struct V_124 * V_125 , unsigned V_18 )
{
struct V_122 * V_181 = F_66 ( V_125 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
T_2 V_182 ;
V_182 = F_27 ( V_49 + V_59 ) ;
return ! ( V_182 & V_50 ) ;
}
static int F_97 ( struct V_124 * V_125 , unsigned V_18 )
{
struct V_122 * V_181 = F_66 ( V_125 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + V_64 ) ;
return 0 ;
}
static int F_98 ( struct V_124 * V_125 , unsigned V_18 )
{
struct V_122 * V_181 = F_66 ( V_125 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
T_2 V_183 ;
V_183 = F_27 ( V_49 + V_184 ) ;
return ( V_183 & V_50 ) != 0 ;
}
static void F_99 ( struct V_124 * V_125 , unsigned V_18 ,
int V_57 )
{
struct V_122 * V_181 = F_66 ( V_125 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + ( V_57 ? V_61 : V_62 ) ) ;
}
static void F_100 ( struct V_124 * V_125 ,
unsigned long * V_50 , unsigned long * V_185 )
{
struct V_122 * V_181 = F_66 ( V_125 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
#define F_101 ( V_185 ) (((bits) == 32) ? ~0U : (BIT(bits) - 1))
T_3 V_186 = ( * V_50 & * V_185 ) & F_101 ( V_125 -> V_187 ) ;
T_3 V_188 = ( * V_50 & ~ ( * V_185 ) ) & F_101 ( V_125 -> V_187 ) ;
F_25 ( V_186 , V_49 + V_61 ) ;
F_25 ( V_188 , V_49 + V_62 ) ;
}
static int F_102 ( struct V_124 * V_125 , unsigned V_18 ,
int V_57 )
{
struct V_122 * V_181 = F_66 ( V_125 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_18 ;
F_25 ( V_50 , V_49 + ( V_57 ? V_61 : V_62 ) ) ;
F_25 ( V_50 , V_49 + V_63 ) ;
return 0 ;
}
static void F_103 ( struct V_16 * V_17 , struct V_124 * V_125 )
{
enum V_72 V_189 ;
int V_6 ;
struct V_122 * V_181 = F_66 ( V_125 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
for ( V_6 = 0 ; V_6 < V_125 -> V_187 ; V_6 ++ ) {
unsigned V_50 = F_20 ( V_6 ) ;
const char * V_190 ;
V_190 = F_104 ( V_125 , V_6 ) ;
if ( ! V_190 )
continue;
V_189 = V_181 -> V_109 -> V_191 ( V_49 , V_50 ) ;
F_8 ( V_17 , L_42 ,
V_190 , V_125 -> V_192 , V_6 ) ;
if ( V_189 == V_75 ) {
F_8 ( V_17 , L_43 ) ;
F_8 ( V_17 , L_44 ,
F_27 ( V_49 + V_59 ) & V_50 ?
L_45 : L_46 ) ;
F_8 ( V_17 , L_47 ,
F_27 ( V_49 + V_184 ) & V_50 ?
L_48 : L_49 ) ;
} else {
F_8 ( V_17 , L_50 ,
V_189 + 'A' - 1 ) ;
}
}
}
static void F_105 ( struct V_193 * V_194 )
{
struct V_122 * V_181 = F_106 ( V_194 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_194 -> V_195 ;
if ( V_49 )
F_25 ( V_50 , V_49 + V_51 ) ;
}
static void F_107 ( struct V_193 * V_194 )
{
struct V_122 * V_181 = F_106 ( V_194 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_194 -> V_195 ;
if ( V_49 )
F_25 ( V_50 , V_49 + V_196 ) ;
}
static int F_108 ( struct V_193 * V_194 , unsigned type )
{
switch ( type ) {
case V_197 :
case V_198 :
return 0 ;
default:
return - V_15 ;
}
}
static int F_109 ( struct V_193 * V_194 , unsigned type )
{
struct V_122 * V_181 = F_106 ( V_194 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned V_50 = 1 << V_194 -> V_195 ;
switch ( type ) {
case V_199 :
F_110 ( V_194 , V_200 ) ;
F_25 ( V_50 , V_49 + V_201 ) ;
F_25 ( V_50 , V_49 + V_202 ) ;
break;
case V_203 :
F_110 ( V_194 , V_200 ) ;
F_25 ( V_50 , V_49 + V_201 ) ;
F_25 ( V_50 , V_49 + V_204 ) ;
break;
case V_205 :
F_110 ( V_194 , V_206 ) ;
F_25 ( V_50 , V_49 + V_207 ) ;
F_25 ( V_50 , V_49 + V_204 ) ;
break;
case V_208 :
F_110 ( V_194 , V_206 ) ;
F_25 ( V_50 , V_49 + V_207 ) ;
F_25 ( V_50 , V_49 + V_202 ) ;
break;
case V_198 :
F_110 ( V_194 , V_200 ) ;
F_25 ( V_50 , V_49 + V_209 ) ;
return 0 ;
case V_197 :
default:
F_111 ( L_51 , F_112 ( V_194 -> V_210 ) ) ;
return - V_15 ;
}
F_25 ( V_50 , V_49 + V_211 ) ;
return 0 ;
}
static void F_113 ( struct V_193 * V_194 )
{
}
static int F_114 ( struct V_193 * V_194 , unsigned V_212 )
{
struct V_122 * V_181 = F_106 ( V_194 ) ;
unsigned V_40 = V_181 -> V_213 ;
unsigned V_50 = 1 << V_194 -> V_195 ;
if ( F_115 ( V_40 >= V_214 ) )
return - V_15 ;
if ( V_212 )
V_215 [ V_40 ] |= V_50 ;
else
V_215 [ V_40 ] &= ~ V_50 ;
F_116 ( V_181 -> V_216 , V_212 ) ;
return 0 ;
}
void F_117 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ ) {
void T_1 * V_49 ;
if ( ! V_41 [ V_6 ] )
continue;
V_49 = V_41 [ V_6 ] -> V_42 ;
V_217 [ V_6 ] = F_27 ( V_49 + V_218 ) ;
F_25 ( V_217 [ V_6 ] , V_49 + V_51 ) ;
F_25 ( V_215 [ V_6 ] , V_49 + V_196 ) ;
if ( ! V_215 [ V_6 ] )
F_118 ( V_41 [ V_6 ] -> clock ) ;
else
F_119 ( V_219 L_52 ,
'A' + V_6 , V_215 [ V_6 ] ) ;
}
}
void F_120 ( void )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_99 ; V_6 ++ ) {
void T_1 * V_49 ;
if ( ! V_41 [ V_6 ] )
continue;
V_49 = V_41 [ V_6 ] -> V_42 ;
if ( ! V_215 [ V_6 ] )
F_121 ( V_41 [ V_6 ] -> clock ) ;
F_25 ( V_215 [ V_6 ] , V_49 + V_51 ) ;
F_25 ( V_217 [ V_6 ] , V_49 + V_196 ) ;
}
}
static void F_122 ( struct V_220 * V_221 )
{
struct V_222 * V_125 = F_123 ( V_221 ) ;
struct V_124 * V_124 = F_124 ( V_221 ) ;
struct V_122 * V_181 = F_66 ( V_124 ) ;
void T_1 * V_49 = V_181 -> V_42 ;
unsigned long V_223 ;
int V_224 ;
F_125 ( V_125 , V_221 ) ;
for (; ; ) {
V_223 = F_27 ( V_49 + V_225 ) & F_27 ( V_49 + V_218 ) ;
if ( ! V_223 ) {
if ( ! V_181 -> V_226 )
break;
V_181 = V_181 -> V_226 ;
V_49 = V_181 -> V_42 ;
V_124 = & V_181 -> V_125 ;
continue;
}
F_126 (n, &isr, BITS_PER_LONG) {
F_127 ( F_128 (
V_124 -> V_227 , V_224 ) ) ;
}
}
F_129 ( V_125 , V_221 ) ;
}
static int F_130 ( struct V_167 * V_168 ,
struct V_122 * V_181 )
{
struct V_124 * V_228 = NULL ;
struct V_122 * V_229 = NULL ;
struct V_193 * V_194 = F_131 ( V_181 -> V_216 ) ;
int V_106 , V_6 ;
V_181 -> V_230 = F_132 ( V_194 ) ;
V_231 . V_232 = V_181 -> V_109 -> V_233 ;
F_25 ( ~ 0 , V_181 -> V_42 + V_51 ) ;
V_106 = F_133 ( & V_181 -> V_125 ,
& V_231 ,
0 ,
V_234 ,
V_197 ) ;
if ( V_106 ) {
F_11 ( & V_168 -> V_9 , L_53 ,
V_181 -> V_213 ) ;
return V_106 ;
}
V_228 = F_134 ( V_181 -> V_216 ) ;
if ( ! V_228 ) {
F_135 ( & V_181 -> V_125 ,
& V_231 ,
V_181 -> V_216 ,
F_122 ) ;
return 0 ;
}
V_229 = F_66 ( V_228 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
if ( V_229 -> V_226 ) {
V_229 = V_229 -> V_226 ;
} else {
V_229 -> V_226 = V_181 ;
return 0 ;
}
}
return - V_15 ;
}
static int F_136 ( struct V_167 * V_168 )
{
struct V_19 * V_20 = V_168 -> V_9 . V_169 ;
struct V_235 * V_236 ;
struct V_122 * V_123 = NULL ;
struct V_124 * V_125 ;
struct V_119 * V_120 ;
int V_106 = 0 ;
int V_210 , V_6 ;
int V_237 = F_137 ( V_20 , L_54 ) ;
T_3 V_187 ;
char * * V_238 ;
F_138 ( V_237 >= F_139 ( V_41 ) ) ;
if ( V_41 [ V_237 ] ) {
V_106 = - V_239 ;
goto V_240;
}
V_210 = F_140 ( V_168 , 0 ) ;
if ( V_210 < 0 ) {
V_106 = V_210 ;
goto V_240;
}
V_123 = F_12 ( & V_168 -> V_9 , sizeof( * V_123 ) , V_27 ) ;
if ( ! V_123 ) {
V_106 = - V_28 ;
goto V_240;
}
V_236 = F_141 ( V_168 , V_241 , 0 ) ;
V_123 -> V_42 = F_142 ( & V_168 -> V_9 , V_236 ) ;
if ( F_92 ( V_123 -> V_42 ) ) {
V_106 = F_93 ( V_123 -> V_42 ) ;
goto V_240;
}
V_123 -> V_109 = (struct V_171 * )
F_86 ( V_242 , & V_168 -> V_9 ) -> V_30 ;
V_123 -> V_216 = V_210 ;
V_123 -> V_213 = V_237 ;
V_123 -> clock = F_143 ( & V_168 -> V_9 , NULL ) ;
if ( F_92 ( V_123 -> clock ) ) {
F_11 ( & V_168 -> V_9 , L_55 ) ;
V_106 = F_93 ( V_123 -> clock ) ;
goto V_240;
}
V_106 = F_121 ( V_123 -> clock ) ;
if ( V_106 ) {
F_11 ( & V_168 -> V_9 , L_56 ) ;
goto V_243;
}
V_123 -> V_125 = V_244 ;
V_125 = & V_123 -> V_125 ;
V_125 -> V_169 = V_20 ;
V_125 -> V_192 = F_9 ( & V_168 -> V_9 ) ;
V_125 -> V_25 = & V_168 -> V_9 ;
V_125 -> V_245 = V_246 ;
V_125 -> V_127 = V_237 * V_44 ;
if ( ! F_144 ( V_20 , L_57 , & V_187 ) ) {
if ( V_187 >= V_44 )
F_145 ( L_58 ,
V_237 , V_44 , V_44 ) ;
else
V_125 -> V_187 = V_187 ;
}
V_238 = F_12 ( & V_168 -> V_9 , sizeof( char * ) * V_125 -> V_187 ,
V_27 ) ;
if ( ! V_238 ) {
V_106 = - V_28 ;
goto V_243;
}
for ( V_6 = 0 ; V_6 < V_125 -> V_187 ; V_6 ++ )
V_238 [ V_6 ] = F_89 ( V_27 , L_39 , V_237 + 'A' , V_6 ) ;
V_125 -> V_238 = ( const char * const * ) V_238 ;
V_120 = & V_123 -> V_120 ;
V_120 -> V_4 = V_125 -> V_192 ;
V_120 -> V_128 = V_237 ;
V_120 -> V_247 = V_120 -> V_127 = V_120 -> V_128 * V_44 ;
V_120 -> V_10 = V_125 -> V_187 ;
V_120 -> V_126 = V_125 ;
V_106 = F_146 ( V_125 , V_123 ) ;
if ( V_106 )
goto V_248;
V_41 [ V_237 ] = V_123 ;
V_99 = F_147 ( V_99 , V_237 + 1 ) ;
V_106 = F_130 ( V_168 , V_123 ) ;
if ( V_106 )
goto V_249;
F_95 ( & V_168 -> V_9 , L_59 , V_123 -> V_42 ) ;
return 0 ;
V_249:
F_148 ( V_125 ) ;
V_248:
V_243:
F_118 ( V_123 -> clock ) ;
V_240:
F_11 ( & V_168 -> V_9 , L_60 , V_106 , V_237 ) ;
return V_106 ;
}
static int T_5 F_149 ( void )
{
return F_150 ( V_250 , F_139 ( V_250 ) ) ;
}
