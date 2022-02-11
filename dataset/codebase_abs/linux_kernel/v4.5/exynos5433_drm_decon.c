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
if ( ! F_6 ( V_12 , & V_2 -> V_10 ) ) {
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
static void F_25 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_81 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_81 = V_2 -> V_82 ; V_81 < V_83 ; V_81 ++ )
F_23 ( V_2 , V_81 , true ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 =
F_27 ( V_85 -> V_29 . V_87 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_57 * V_58 = V_87 -> V_29 . V_58 ;
unsigned int V_56 = V_85 -> V_88 ;
unsigned int V_89 = V_58 -> V_74 >> 3 ;
unsigned int V_90 = V_58 -> V_91 [ 0 ] ;
T_2 V_92 = F_28 ( V_58 , 0 ) ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
V_5 = F_29 ( V_87 -> V_8 . V_93 ) | F_30 ( V_87 -> V_8 . V_94 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_31 ( V_56 ) ) ;
V_5 = F_29 ( V_87 -> V_8 . V_93 + V_87 -> V_8 . V_95 - 1 ) |
F_30 ( V_87 -> V_8 . V_94 + V_87 -> V_8 . V_96 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_32 ( V_56 ) ) ;
V_5 = F_33 ( 0x0 ) | F_34 ( 0x0 ) |
F_35 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_36 ( V_56 ) ) ;
V_5 = F_33 ( 0x0 ) | F_34 ( 0x0 ) |
F_35 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_37 ( V_56 ) ) ;
F_3 ( V_92 , V_2 -> V_6 + F_38 ( V_56 ) ) ;
V_5 = V_92 + V_90 * V_87 -> V_97 . V_96 ;
F_3 ( V_5 , V_2 -> V_6 + F_39 ( V_56 ) ) ;
if ( V_2 -> V_14 != V_19 )
V_5 = F_40 ( V_90 - V_87 -> V_8 . V_95 * V_89 , 27 , 14 )
| F_40 ( V_87 -> V_8 . V_95 * V_89 , 13 , 0 ) ;
else
V_5 = F_40 ( V_90 - V_87 -> V_8 . V_95 * V_89 , 29 , 15 )
| F_40 ( V_87 -> V_8 . V_95 * V_89 , 14 , 0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_41 ( V_56 ) ) ;
F_19 ( V_2 , V_56 , V_58 ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_98 , ~ 0 ) ;
F_1 ( V_2 , V_99 , V_100 , ~ 0 ) ;
}
static void F_42 ( struct V_7 * V_8 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_56 = V_85 -> V_88 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_23 ( V_2 , V_56 , true ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_98 , 0 ) ;
F_23 ( V_2 , V_56 , false ) ;
F_1 ( V_2 , V_99 , V_100 , ~ 0 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_81 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_81 = V_2 -> V_82 ; V_81 < V_83 ; V_81 ++ )
F_23 ( V_2 , V_81 , false ) ;
if ( V_2 -> V_14 == V_15 )
F_44 ( V_101 , & V_2 -> V_10 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_102 ;
F_3 ( 0 , V_2 -> V_6 + V_38 ) ;
for ( V_102 = 2000 ; V_102 ; -- V_102 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_38 ) & V_103 )
break;
F_46 ( 10 ) ;
}
F_47 ( V_102 == 0 , L_3 ) ;
F_3 ( V_104 , V_2 -> V_6 + V_38 ) ;
for ( V_102 = 2000 ; V_102 ; -- V_102 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_38 ) & V_104 )
break;
F_46 ( 10 ) ;
}
F_47 ( V_102 == 0 , L_4 ) ;
if ( V_2 -> V_14 != V_19 )
return;
F_3 ( V_105 | V_106 , V_2 -> V_6 + V_38 ) ;
F_1 ( V_2 , V_42 ,
V_40 | V_41 , ~ 0 ) ;
F_3 ( V_107 , V_2 -> V_6 + V_108 ) ;
F_3 ( V_109 | V_110 | V_111 ,
V_2 -> V_6 + V_112 ) ;
F_9 ( V_2 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_8 ( V_9 , & V_2 -> V_10 ) )
return;
F_49 ( V_2 -> V_113 ) ;
F_44 ( V_114 , & V_2 -> V_10 ) ;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_4 ( V_2 -> V_8 ) ;
F_10 ( V_2 -> V_8 ) ;
}
static void F_50 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_81 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_81 = V_2 -> V_82 ; V_81 < V_83 ; V_81 ++ )
F_42 ( V_8 , & V_2 -> V_115 [ V_81 ] ) ;
F_45 ( V_2 ) ;
F_51 ( V_114 , & V_2 -> V_10 ) ;
F_52 ( V_2 -> V_113 ) ;
F_44 ( V_9 , & V_2 -> V_10 ) ;
}
void F_53 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_5 ( V_114 , & V_2 -> V_10 ) )
return;
if ( F_8 ( V_101 , & V_2 -> V_10 ) )
F_1 ( V_2 , V_26 , V_116 , ~ 0 ) ;
F_54 ( & V_2 -> V_8 -> V_29 ) ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_56 , V_81 , V_117 ;
F_22 ( L_5 , __FILE__ ) ;
for ( V_81 = 0 ; V_81 < F_56 ( V_118 ) ; V_81 ++ ) {
V_117 = F_57 ( V_2 -> V_119 [ V_81 ] ) ;
if ( V_117 < 0 )
goto V_120;
}
for ( V_56 = 0 ; V_56 < V_83 ; V_56 ++ ) {
F_23 ( V_2 , V_56 , true ) ;
F_1 ( V_2 , F_20 ( V_56 ) , V_98 , 0 ) ;
F_23 ( V_2 , V_56 , false ) ;
F_1 ( V_2 , V_99 , V_100 , ~ 0 ) ;
}
F_58 ( 50 ) ;
V_120:
while ( -- V_81 >= 0 )
F_59 ( V_2 -> V_119 [ V_81 ] ) ;
}
static int F_60 ( struct V_121 * V_113 , struct V_121 * V_122 , void * V_123 )
{
struct V_1 * V_2 = F_61 ( V_113 ) ;
struct V_124 * V_125 = V_123 ;
struct V_126 * V_127 = V_125 -> V_128 ;
struct V_84 * V_129 ;
enum V_130 V_14 ;
unsigned int V_56 ;
int V_117 ;
V_2 -> V_125 = V_125 ;
V_2 -> V_131 = V_127 -> V_131 ++ ;
for ( V_56 = V_2 -> V_82 ; V_56 < V_83 ; V_56 ++ ) {
int V_132 = ( V_56 == V_2 -> V_82 ) ? 0 : V_56 ;
V_2 -> V_133 [ V_56 ] . V_134 = V_135 ;
V_2 -> V_133 [ V_56 ] . V_136 = F_56 ( V_135 ) ;
V_2 -> V_133 [ V_56 ] . V_137 = V_56 ;
V_2 -> V_133 [ V_56 ] . type = V_138 [ V_132 ] ;
V_117 = F_62 ( V_125 , & V_2 -> V_115 [ V_56 ] , V_56 ,
1 << V_2 -> V_131 , & V_2 -> V_133 [ V_56 ] ) ;
if ( V_117 )
return V_117 ;
}
V_129 = & V_2 -> V_115 [ V_2 -> V_82 ] ;
V_14 = ( V_2 -> V_14 == V_19 ) ? V_139
: V_140 ;
V_2 -> V_8 = F_63 ( V_125 , & V_129 -> V_29 ,
V_2 -> V_131 , V_14 ,
& V_141 , V_2 ) ;
if ( F_64 ( V_2 -> V_8 ) ) {
V_117 = F_65 ( V_2 -> V_8 ) ;
goto V_120;
}
F_55 ( V_2 -> V_8 ) ;
V_117 = F_66 ( V_125 , V_113 ) ;
if ( V_117 )
goto V_120;
return V_117 ;
V_120:
V_127 -> V_131 -- ;
return V_117 ;
}
static void F_67 ( struct V_121 * V_113 , struct V_121 * V_122 , void * V_123 )
{
struct V_1 * V_2 = F_61 ( V_113 ) ;
F_50 ( V_2 -> V_8 ) ;
F_68 ( V_2 -> V_125 , V_2 -> V_113 ) ;
}
static T_3 F_69 ( int V_142 , void * V_143 )
{
struct V_1 * V_2 = V_143 ;
T_1 V_5 ;
int V_56 ;
if ( ! F_5 ( V_114 , & V_2 -> V_10 ) )
goto V_144;
V_5 = F_2 ( V_2 -> V_6 + V_145 ) ;
V_5 &= V_146 | V_147 ;
if ( V_5 ) {
for ( V_56 = V_2 -> V_82 ; V_56 < V_83 ; V_56 ++ ) {
struct V_84 * V_85 = & V_2 -> V_115 [ V_56 ] ;
if ( ! V_85 -> V_148 )
continue;
F_70 ( V_2 -> V_8 , V_85 ) ;
}
F_3 ( V_5 , V_2 -> V_6 + V_145 ) ;
}
V_144:
return V_149 ;
}
static int F_71 ( struct V_121 * V_113 )
{
struct V_1 * V_2 = F_61 ( V_113 ) ;
int V_81 = F_56 ( V_118 ) ;
while ( -- V_81 >= 0 )
F_59 ( V_2 -> V_119 [ V_81 ] ) ;
return 0 ;
}
static int F_72 ( struct V_121 * V_113 )
{
struct V_1 * V_2 = F_61 ( V_113 ) ;
int V_81 , V_117 ;
for ( V_81 = 0 ; V_81 < F_56 ( V_118 ) ; V_81 ++ ) {
V_117 = F_57 ( V_2 -> V_119 [ V_81 ] ) ;
if ( V_117 < 0 )
goto V_120;
}
return 0 ;
V_120:
while ( -- V_81 >= 0 )
F_59 ( V_2 -> V_119 [ V_81 ] ) ;
return V_117 ;
}
static int F_73 ( struct V_150 * V_151 )
{
const struct V_152 * V_153 ;
struct V_121 * V_113 = & V_151 -> V_113 ;
struct V_1 * V_2 ;
struct V_154 * V_155 ;
int V_117 ;
int V_81 ;
V_2 = F_74 ( V_113 , sizeof( * V_2 ) , V_156 ) ;
if ( ! V_2 )
return - V_157 ;
F_75 ( V_9 , & V_2 -> V_10 ) ;
V_2 -> V_113 = V_113 ;
V_153 = F_76 ( V_158 , & V_151 -> V_113 ) ;
V_2 -> V_14 = (enum V_159 ) V_153 -> V_123 ;
if ( V_2 -> V_14 == V_19 )
V_2 -> V_82 = 1 ;
else if ( F_77 ( V_113 -> V_160 , L_6 ) )
V_2 -> V_14 = V_15 ;
for ( V_81 = 0 ; V_81 < F_56 ( V_118 ) ; V_81 ++ ) {
struct V_161 * V_161 ;
V_161 = F_78 ( V_2 -> V_113 , V_118 [ V_81 ] ) ;
if ( F_64 ( V_161 ) )
return F_65 ( V_161 ) ;
V_2 -> V_119 [ V_81 ] = V_161 ;
}
V_155 = F_79 ( V_151 , V_162 , 0 ) ;
if ( ! V_155 ) {
F_80 ( V_113 , L_7 ) ;
return - V_163 ;
}
V_2 -> V_6 = F_81 ( V_113 , V_155 ) ;
if ( F_64 ( V_2 -> V_6 ) ) {
F_80 ( V_113 , L_8 ) ;
return F_65 ( V_2 -> V_6 ) ;
}
V_155 = F_82 ( V_151 , V_164 ,
( V_2 -> V_14 == V_15 ) ? L_9 : L_10 ) ;
if ( ! V_155 ) {
F_80 ( V_113 , L_11 ) ;
return - V_163 ;
}
V_117 = F_83 ( V_113 , V_155 -> V_165 , F_69 , 0 ,
L_12 , V_2 ) ;
if ( V_117 < 0 ) {
F_80 ( V_113 , L_13 ) ;
return V_117 ;
}
F_84 ( V_151 , V_2 ) ;
F_85 ( V_113 ) ;
V_117 = F_86 ( V_113 , & V_166 ) ;
if ( V_117 )
goto V_167;
return 0 ;
V_167:
F_87 ( V_113 ) ;
return V_117 ;
}
static int F_88 ( struct V_150 * V_151 )
{
F_87 ( & V_151 -> V_113 ) ;
F_89 ( & V_151 -> V_113 , & V_166 ) ;
return 0 ;
}
