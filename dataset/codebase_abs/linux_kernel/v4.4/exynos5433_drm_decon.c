static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 )
{
V_5 = ( V_5 & V_4 ) | ( F_2 ( V_2 -> V_6 + V_3 ) & ~ V_4 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return - V_11 ;
if ( F_6 ( V_12 , & V_2 -> V_10 ) ) {
V_5 = V_13 ;
if ( V_2 -> V_14 == V_15 )
V_5 |= V_16 ;
else
V_5 |= V_17 ;
F_3 ( V_5 , V_2 -> V_6 + V_18 ) ;
}
return 0 ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_3 ( 0 , V_2 -> V_6 + V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_5 = ( V_2 -> V_14 != V_19 )
? V_20 | V_21 |
V_22 | V_23
: V_20 | V_21 |
V_24 | V_25 ;
F_3 ( V_5 , V_2 -> V_6 + V_26 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_27 * V_28 = & V_8 -> V_29 . V_30 ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
if ( V_2 -> V_14 == V_19 ) {
V_28 -> V_31 = V_28 -> V_32 + 10 ;
V_28 -> V_33 = V_28 -> V_34 - 92 ;
V_28 -> V_35 = V_28 -> V_36 + 1 ;
V_28 -> V_37 = V_28 -> V_35 + 1 ;
}
F_1 ( V_2 , V_38 , V_39 , 0 ) ;
V_5 = V_40 | V_41 ;
F_3 ( V_5 , V_2 -> V_6 + V_42 ) ;
V_5 = V_43 ;
if ( V_2 -> V_14 == V_15 )
V_5 |= V_44 ;
else
V_5 |= V_45 ;
F_3 ( V_5 , V_2 -> V_6 + V_46 ) ;
V_5 = F_11 ( V_28 -> V_47 - 1 ) |
F_12 ( V_28 -> V_48 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_49 ) ;
if ( V_2 -> V_14 != V_15 ) {
V_5 = F_13 (
V_28 -> V_50 - V_28 -> V_37 - 1 ) |
F_14 (
V_28 -> V_35 - V_28 -> V_36 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_51 ) ;
V_5 = F_15 (
V_28 -> V_37 - V_28 -> V_35 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_52 ) ;
V_5 = F_16 (
V_28 -> V_34 - V_28 -> V_33 - 1 ) |
F_17 (
V_28 -> V_31 - V_28 -> V_32 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_53 ) ;
V_5 = F_18 (
V_28 -> V_33 - V_28 -> V_31 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_54 ) ;
}
F_9 ( V_2 ) ;
F_1 ( V_2 , V_38 , V_39 | V_55 , ~ 0 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_56 ,
struct V_57 * V_58 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_2 -> V_6 + F_20 ( V_56 ) ) ;
V_5 &= ~ V_59 ;
switch ( V_58 -> V_60 ) {
case V_61 :
V_5 |= V_62 ;
V_5 |= V_63 ;
V_5 |= V_64 ;
break;
case V_65 :
V_5 |= V_66 ;
V_5 |= V_63 ;
V_5 |= V_64 ;
break;
case V_67 :
V_5 |= V_68 ;
V_5 |= V_69 ;
V_5 |= V_64 ;
break;
case V_70 :
V_5 |= V_71 ;
V_5 |= V_69 | V_72 | V_73 ;
V_5 |= V_64 ;
break;
default:
F_21 ( L_1 ) ;
return;
}
F_22 ( L_2 , V_58 -> V_74 ) ;
if ( V_58 -> V_75 < V_76 ) {
V_5 &= ~ V_77 ;
V_5 |= V_78 ;
}
F_3 ( V_5 , V_2 -> V_6 + F_20 ( V_56 ) ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_56 ,
bool V_79 )
{
F_1 ( V_2 , V_80 , F_24 ( V_56 ) ,
V_79 ? ~ 0 : 0 ) ;
}
static void F_25 ( struct V_7 * V_8 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_23 ( V_2 , V_82 -> V_83 , true ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_84 * V_85 = V_82 -> V_29 . V_85 ;
unsigned int V_56 = V_82 -> V_83 ;
unsigned int V_86 = V_85 -> V_58 -> V_74 >> 3 ;
unsigned int V_87 = V_85 -> V_58 -> V_88 [ 0 ] ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
V_5 = F_27 ( V_82 -> V_89 ) | F_28 ( V_82 -> V_90 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_29 ( V_56 ) ) ;
V_5 = F_27 ( V_82 -> V_89 + V_82 -> V_91 - 1 ) |
F_28 ( V_82 -> V_90 + V_82 -> V_92 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_30 ( V_56 ) ) ;
V_5 = F_31 ( 0x0 ) | F_32 ( 0x0 ) |
F_33 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_34 ( V_56 ) ) ;
V_5 = F_31 ( 0x0 ) | F_32 ( 0x0 ) |
F_33 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_35 ( V_56 ) ) ;
F_3 ( V_82 -> V_93 [ 0 ] , V_2 -> V_6 + F_36 ( V_56 ) ) ;
V_5 = V_82 -> V_93 [ 0 ] + V_87 * V_82 -> V_92 ;
F_3 ( V_5 , V_2 -> V_6 + F_37 ( V_56 ) ) ;
if ( V_2 -> V_14 != V_19 )
V_5 = F_38 ( V_87 - V_82 -> V_91 * V_86 , 27 , 14 )
| F_38 ( V_82 -> V_91 * V_86 , 13 , 0 ) ;
else
V_5 = F_38 ( V_87 - V_82 -> V_91 * V_86 , 29 , 15 )
| F_38 ( V_82 -> V_91 * V_86 , 14 , 0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_39 ( V_56 ) ) ;
F_19 ( V_2 , V_56 , V_85 -> V_58 ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_94 , ~ 0 ) ;
F_1 ( V_2 , V_95 , V_96 , ~ 0 ) ;
}
static void F_40 ( struct V_7 * V_8 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_56 = V_82 -> V_83 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_23 ( V_2 , V_56 , true ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_94 , 0 ) ;
F_23 ( V_2 , V_56 , false ) ;
F_1 ( V_2 , V_95 , V_96 , ~ 0 ) ;
}
static void F_41 ( struct V_7 * V_8 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_23 ( V_2 , V_82 -> V_83 , false ) ;
if ( V_2 -> V_14 == V_15 )
F_42 ( V_97 , & V_2 -> V_10 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned int V_98 ;
F_3 ( 0 , V_2 -> V_6 + V_38 ) ;
for ( V_98 = 2000 ; V_98 ; -- V_98 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_38 ) & V_99 )
break;
F_44 ( 10 ) ;
}
F_45 ( V_98 == 0 , L_3 ) ;
F_3 ( V_100 , V_2 -> V_6 + V_38 ) ;
for ( V_98 = 2000 ; V_98 ; -- V_98 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_38 ) & V_100 )
break;
F_44 ( 10 ) ;
}
F_45 ( V_98 == 0 , L_4 ) ;
if ( V_2 -> V_14 != V_19 )
return;
F_3 ( V_101 | V_102 , V_2 -> V_6 + V_38 ) ;
F_1 ( V_2 , V_42 ,
V_40 | V_41 , ~ 0 ) ;
F_3 ( V_103 , V_2 -> V_6 + V_104 ) ;
F_3 ( V_105 | V_106 | V_107 ,
V_2 -> V_6 + V_108 ) ;
F_9 ( V_2 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_109 ;
int V_110 ;
if ( ! F_8 ( V_9 , & V_2 -> V_10 ) )
return;
F_47 ( V_2 -> V_111 ) ;
for ( V_110 = 0 ; V_110 < F_48 ( V_112 ) ; V_110 ++ ) {
V_109 = F_49 ( V_2 -> V_113 [ V_110 ] ) ;
if ( V_109 < 0 )
goto V_114;
}
F_42 ( V_115 , & V_2 -> V_10 ) ;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_4 ( V_2 -> V_8 ) ;
F_10 ( V_2 -> V_8 ) ;
return;
V_114:
while ( -- V_110 >= 0 )
F_50 ( V_2 -> V_113 [ V_110 ] ) ;
F_42 ( V_9 , & V_2 -> V_10 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_110 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_110 = V_2 -> V_116 ; V_110 < V_117 ; V_110 ++ )
F_40 ( V_8 , & V_2 -> V_118 [ V_110 ] ) ;
F_43 ( V_2 ) ;
for ( V_110 = 0 ; V_110 < F_48 ( V_112 ) ; V_110 ++ )
F_50 ( V_2 -> V_113 [ V_110 ] ) ;
F_52 ( V_115 , & V_2 -> V_10 ) ;
F_53 ( V_2 -> V_111 ) ;
F_42 ( V_9 , & V_2 -> V_10 ) ;
}
void F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_5 ( V_115 , & V_2 -> V_10 ) )
return;
if ( F_8 ( V_97 , & V_2 -> V_10 ) )
F_1 ( V_2 , V_26 , V_119 , ~ 0 ) ;
F_55 ( & V_2 -> V_8 -> V_29 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_56 , V_110 , V_109 ;
F_22 ( L_5 , __FILE__ ) ;
for ( V_110 = 0 ; V_110 < F_48 ( V_112 ) ; V_110 ++ ) {
V_109 = F_49 ( V_2 -> V_113 [ V_110 ] ) ;
if ( V_109 < 0 )
goto V_114;
}
for ( V_56 = 0 ; V_56 < V_117 ; V_56 ++ ) {
F_23 ( V_2 , V_56 , true ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_94 , 0 ) ;
F_23 ( V_2 , V_56 , false ) ;
F_1 ( V_2 , V_95 , V_96 , ~ 0 ) ;
}
F_57 ( 50 ) ;
V_114:
while ( -- V_110 >= 0 )
F_50 ( V_2 -> V_113 [ V_110 ] ) ;
}
static int F_58 ( struct V_120 * V_111 , struct V_120 * V_121 , void * V_122 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
struct V_123 * V_124 = V_122 ;
struct V_125 * V_126 = V_124 -> V_127 ;
struct V_81 * V_128 ;
enum V_129 V_14 ;
enum V_130 type ;
unsigned int V_56 ;
int V_109 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_131 = V_126 -> V_131 ++ ;
for ( V_56 = V_2 -> V_116 ; V_56 < V_117 ; V_56 ++ ) {
int V_132 = ( V_56 == V_2 -> V_116 ) ? 0 : V_56 ;
type = F_60 ( V_132 , V_133 ) ;
V_109 = F_61 ( V_124 , & V_2 -> V_118 [ V_56 ] ,
1 << V_2 -> V_131 , type , V_134 ,
F_48 ( V_134 ) , V_56 ) ;
if ( V_109 )
return V_109 ;
}
V_128 = & V_2 -> V_118 [ V_2 -> V_116 ] ;
V_14 = ( V_2 -> V_14 == V_19 ) ? V_135
: V_136 ;
V_2 -> V_8 = F_62 ( V_124 , & V_128 -> V_29 ,
V_2 -> V_131 , V_14 ,
& V_137 , V_2 ) ;
if ( F_63 ( V_2 -> V_8 ) ) {
V_109 = F_64 ( V_2 -> V_8 ) ;
goto V_114;
}
F_56 ( V_2 -> V_8 ) ;
V_109 = F_65 ( V_124 , V_111 ) ;
if ( V_109 )
goto V_114;
return V_109 ;
V_114:
V_126 -> V_131 -- ;
return V_109 ;
}
static void F_66 ( struct V_120 * V_111 , struct V_120 * V_121 , void * V_122 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
F_51 ( V_2 -> V_8 ) ;
F_67 ( V_2 -> V_124 , V_2 -> V_111 ) ;
}
static T_2 F_68 ( int V_138 , void * V_139 )
{
struct V_1 * V_2 = V_139 ;
T_1 V_5 ;
int V_56 ;
if ( ! F_5 ( V_115 , & V_2 -> V_10 ) )
goto V_140;
V_5 = F_2 ( V_2 -> V_6 + V_141 ) ;
V_5 &= V_142 | V_143 ;
if ( V_5 ) {
for ( V_56 = V_2 -> V_116 ; V_56 < V_117 ; V_56 ++ ) {
struct V_81 * V_82 = & V_2 -> V_118 [ V_56 ] ;
if ( ! V_82 -> V_144 )
continue;
F_69 ( V_2 -> V_8 , V_82 ) ;
}
F_3 ( V_5 , V_2 -> V_6 + V_141 ) ;
}
V_140:
return V_145 ;
}
static int F_70 ( struct V_146 * V_147 )
{
const struct V_148 * V_149 ;
struct V_120 * V_111 = & V_147 -> V_111 ;
struct V_1 * V_2 ;
struct V_150 * V_151 ;
int V_109 ;
int V_110 ;
V_2 = F_71 ( V_111 , sizeof( * V_2 ) , V_152 ) ;
if ( ! V_2 )
return - V_153 ;
F_72 ( V_9 , & V_2 -> V_10 ) ;
V_2 -> V_111 = V_111 ;
V_149 = F_73 ( V_154 , & V_147 -> V_111 ) ;
V_2 -> V_14 = (enum V_155 ) V_149 -> V_122 ;
if ( V_2 -> V_14 == V_19 )
V_2 -> V_116 = 1 ;
else if ( F_74 ( V_111 -> V_156 , L_6 ) )
V_2 -> V_14 = V_15 ;
for ( V_110 = 0 ; V_110 < F_48 ( V_112 ) ; V_110 ++ ) {
struct V_157 * V_157 ;
V_157 = F_75 ( V_2 -> V_111 , V_112 [ V_110 ] ) ;
if ( F_63 ( V_157 ) )
return F_64 ( V_157 ) ;
V_2 -> V_113 [ V_110 ] = V_157 ;
}
V_151 = F_76 ( V_147 , V_158 , 0 ) ;
if ( ! V_151 ) {
F_77 ( V_111 , L_7 ) ;
return - V_159 ;
}
V_2 -> V_6 = F_78 ( V_111 , V_151 ) ;
if ( F_63 ( V_2 -> V_6 ) ) {
F_77 ( V_111 , L_8 ) ;
return F_64 ( V_2 -> V_6 ) ;
}
V_151 = F_79 ( V_147 , V_160 ,
( V_2 -> V_14 == V_15 ) ? L_9 : L_10 ) ;
if ( ! V_151 ) {
F_77 ( V_111 , L_11 ) ;
return - V_159 ;
}
V_109 = F_80 ( V_111 , V_151 -> V_161 , F_68 , 0 ,
L_12 , V_2 ) ;
if ( V_109 < 0 ) {
F_77 ( V_111 , L_13 ) ;
return V_109 ;
}
F_81 ( V_147 , V_2 ) ;
F_82 ( V_111 ) ;
V_109 = F_83 ( V_111 , & V_162 ) ;
if ( V_109 )
goto V_163;
return 0 ;
V_163:
F_84 ( V_111 ) ;
return V_109 ;
}
static int F_85 ( struct V_146 * V_147 )
{
F_84 ( & V_147 -> V_111 ) ;
F_86 ( & V_147 -> V_111 , & V_162 ) ;
return 0 ;
}
