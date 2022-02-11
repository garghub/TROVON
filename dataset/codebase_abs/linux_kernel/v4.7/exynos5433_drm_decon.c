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
if ( V_2 -> V_14 & V_15 )
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
T_1 V_5 = ! ( V_2 -> V_14 & V_19 )
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
if ( V_2 -> V_14 & V_31 ) {
V_28 -> V_32 = V_28 -> V_33 + 10 ;
V_28 -> V_34 = V_28 -> V_35 - 92 ;
V_28 -> V_36 = V_28 -> V_37 + 1 ;
V_28 -> V_38 = V_28 -> V_36 + 1 ;
}
F_1 ( V_2 , V_39 , V_40 , 0 ) ;
V_5 = V_41 | V_42 ;
F_3 ( V_5 , V_2 -> V_6 + V_43 ) ;
if ( V_2 -> V_14 & ( V_15 | V_19 ) )
F_9 ( V_2 ) ;
V_5 = V_44 ;
if ( V_2 -> V_14 & V_15 ) {
V_5 |= V_45 ;
} else {
V_5 |= V_46 ;
}
F_3 ( V_5 , V_2 -> V_6 + V_47 ) ;
V_5 = F_11 ( V_28 -> V_48 - 1 ) |
F_12 ( V_28 -> V_49 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_50 ) ;
if ( ! ( V_2 -> V_14 & V_15 ) ) {
V_5 = F_13 (
V_28 -> V_51 - V_28 -> V_38 - 1 ) |
F_14 (
V_28 -> V_36 - V_28 -> V_37 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_52 ) ;
V_5 = F_15 (
V_28 -> V_38 - V_28 -> V_36 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_53 ) ;
V_5 = F_16 (
V_28 -> V_35 - V_28 -> V_34 - 1 ) |
F_17 (
V_28 -> V_32 - V_28 -> V_33 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_54 ) ;
V_5 = F_18 (
V_28 -> V_34 - V_28 -> V_32 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_55 ) ;
}
F_1 ( V_2 , V_39 , V_40 | V_56 , ~ 0 ) ;
F_1 ( V_2 , V_57 , V_58 , ~ 0 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_59 ,
struct V_60 * V_61 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_2 -> V_6 + F_20 ( V_59 ) ) ;
V_5 &= ~ V_62 ;
switch ( V_61 -> V_63 ) {
case V_64 :
V_5 |= V_65 ;
V_5 |= V_66 ;
V_5 |= V_67 ;
break;
case V_68 :
V_5 |= V_69 ;
V_5 |= V_66 ;
V_5 |= V_67 ;
break;
case V_70 :
V_5 |= V_71 ;
V_5 |= V_72 ;
V_5 |= V_67 ;
break;
case V_73 :
V_5 |= V_74 ;
V_5 |= V_72 | V_75 | V_76 ;
V_5 |= V_67 ;
break;
default:
F_21 ( L_1 ) ;
return;
}
F_22 ( L_2 , V_61 -> V_77 ) ;
if ( V_61 -> V_78 < V_79 ) {
V_5 &= ~ V_80 ;
V_5 |= V_81 ;
}
F_3 ( V_5 , V_2 -> V_6 + F_20 ( V_59 ) ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_59 ,
bool V_82 )
{
F_1 ( V_2 , V_83 , F_24 ( V_59 ) ,
V_82 ? ~ 0 : 0 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_84 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_84 = V_2 -> V_85 ; V_84 < V_86 ; V_84 ++ )
F_23 ( V_2 , V_84 , true ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_87 * V_88 )
{
struct V_89 * V_90 =
F_27 ( V_88 -> V_29 . V_90 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_60 * V_61 = V_90 -> V_29 . V_61 ;
unsigned int V_59 = V_88 -> V_91 ;
unsigned int V_92 = V_61 -> V_77 >> 3 ;
unsigned int V_93 = V_61 -> V_94 [ 0 ] ;
T_2 V_95 = F_28 ( V_61 , 0 ) ;
T_1 V_5 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
V_5 = F_29 ( V_90 -> V_8 . V_96 ) | F_30 ( V_90 -> V_8 . V_97 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_31 ( V_59 ) ) ;
V_5 = F_29 ( V_90 -> V_8 . V_96 + V_90 -> V_8 . V_98 - 1 ) |
F_30 ( V_90 -> V_8 . V_97 + V_90 -> V_8 . V_99 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_32 ( V_59 ) ) ;
V_5 = F_33 ( 0x0 ) | F_34 ( 0x0 ) |
F_35 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_36 ( V_59 ) ) ;
V_5 = F_33 ( 0x0 ) | F_34 ( 0x0 ) |
F_35 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_37 ( V_59 ) ) ;
F_3 ( V_95 , V_2 -> V_6 + F_38 ( V_59 ) ) ;
V_5 = V_95 + V_93 * V_90 -> V_100 . V_99 ;
F_3 ( V_5 , V_2 -> V_6 + F_39 ( V_59 ) ) ;
if ( ! ( V_2 -> V_14 & V_31 ) )
V_5 = F_40 ( V_93 - V_90 -> V_8 . V_98 * V_92 , 27 , 14 )
| F_40 ( V_90 -> V_8 . V_98 * V_92 , 13 , 0 ) ;
else
V_5 = F_40 ( V_93 - V_90 -> V_8 . V_98 * V_92 , 29 , 15 )
| F_40 ( V_90 -> V_8 . V_98 * V_92 , 14 , 0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_41 ( V_59 ) ) ;
F_19 ( V_2 , V_59 , V_61 ) ;
F_1 ( V_2 , F_20 ( V_59 ) , V_101 , ~ 0 ) ;
}
static void F_42 ( struct V_7 * V_8 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_59 = V_88 -> V_91 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
F_1 ( V_2 , F_20 ( V_59 ) , V_101 , 0 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_84 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_84 = V_2 -> V_85 ; V_84 < V_86 ; V_84 ++ )
F_23 ( V_2 , V_84 , false ) ;
F_1 ( V_2 , V_57 , V_58 , ~ 0 ) ;
if ( V_2 -> V_14 & V_15 )
F_44 ( V_102 , & V_2 -> V_10 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_103 ;
F_3 ( 0 , V_2 -> V_6 + V_39 ) ;
for ( V_103 = 2000 ; V_103 ; -- V_103 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_39 ) & V_104 )
break;
F_46 ( 10 ) ;
}
F_47 ( V_103 == 0 , L_3 ) ;
F_3 ( V_105 , V_2 -> V_6 + V_39 ) ;
for ( V_103 = 2000 ; V_103 ; -- V_103 ) {
if ( ~ F_2 ( V_2 -> V_6 + V_39 ) & V_105 )
break;
F_46 ( 10 ) ;
}
F_47 ( V_103 == 0 , L_4 ) ;
if ( ! ( V_2 -> V_14 & V_31 ) )
return;
F_3 ( V_106 | V_107 , V_2 -> V_6 + V_39 ) ;
F_1 ( V_2 , V_43 ,
V_41 | V_42 , ~ 0 ) ;
F_3 ( V_108 , V_2 -> V_6 + V_109 ) ;
F_3 ( V_110 | V_111 | V_112 ,
V_2 -> V_6 + V_113 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_8 ( V_9 , & V_2 -> V_10 ) )
return;
F_49 ( V_2 -> V_114 ) ;
F_50 ( V_8 , true ) ;
F_44 ( V_115 , & V_2 -> V_10 ) ;
F_45 ( V_2 ) ;
if ( F_8 ( V_12 , & V_2 -> V_10 ) )
F_4 ( V_2 -> V_8 ) ;
F_10 ( V_2 -> V_8 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_84 ;
if ( F_5 ( V_9 , & V_2 -> V_10 ) )
return;
for ( V_84 = V_2 -> V_85 ; V_84 < V_86 ; V_84 ++ )
F_42 ( V_8 , & V_2 -> V_116 [ V_84 ] ) ;
F_45 ( V_2 ) ;
F_52 ( V_115 , & V_2 -> V_10 ) ;
F_50 ( V_8 , false ) ;
F_53 ( V_2 -> V_114 ) ;
F_44 ( V_9 , & V_2 -> V_10 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_5 ( V_115 , & V_2 -> V_10 ) ||
( V_2 -> V_14 & V_19 ) )
return;
if ( F_8 ( V_102 , & V_2 -> V_10 ) )
F_1 ( V_2 , V_26 , V_117 , ~ 0 ) ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_59 , V_84 , V_118 ;
F_22 ( L_5 , __FILE__ ) ;
for ( V_84 = 0 ; V_84 < F_56 ( V_119 ) ; V_84 ++ ) {
V_118 = F_57 ( V_2 -> V_120 [ V_84 ] ) ;
if ( V_118 < 0 )
goto V_121;
}
for ( V_59 = 0 ; V_59 < V_86 ; V_59 ++ ) {
F_23 ( V_2 , V_59 , true ) ;
F_1 ( V_2 , F_20 ( V_59 ) , V_101 , 0 ) ;
F_23 ( V_2 , V_59 , false ) ;
}
F_1 ( V_2 , V_57 , V_58 , ~ 0 ) ;
F_58 ( 50 ) ;
V_121:
while ( -- V_84 >= 0 )
F_59 ( V_2 -> V_120 [ V_84 ] ) ;
}
static int F_60 ( struct V_122 * V_114 , struct V_122 * V_123 , void * V_124 )
{
struct V_1 * V_2 = F_61 ( V_114 ) ;
struct V_125 * V_126 = V_124 ;
struct V_127 * V_128 = V_126 -> V_129 ;
struct V_87 * V_130 ;
enum V_131 V_14 ;
unsigned int V_59 ;
int V_118 ;
V_2 -> V_126 = V_126 ;
V_2 -> V_132 = V_128 -> V_132 ++ ;
for ( V_59 = V_2 -> V_85 ; V_59 < V_86 ; V_59 ++ ) {
int V_133 = ( V_59 == V_2 -> V_85 ) ? 0 : V_59 ;
V_2 -> V_134 [ V_59 ] . V_135 = V_136 ;
V_2 -> V_134 [ V_59 ] . V_137 = F_56 ( V_136 ) ;
V_2 -> V_134 [ V_59 ] . V_138 = V_59 ;
V_2 -> V_134 [ V_59 ] . type = V_139 [ V_133 ] ;
V_118 = F_62 ( V_126 , & V_2 -> V_116 [ V_59 ] , V_59 ,
1 << V_2 -> V_132 , & V_2 -> V_134 [ V_59 ] ) ;
if ( V_118 )
return V_118 ;
}
V_130 = & V_2 -> V_116 [ V_2 -> V_85 ] ;
V_14 = ( V_2 -> V_14 & V_31 ) ? V_140
: V_141 ;
V_2 -> V_8 = F_63 ( V_126 , & V_130 -> V_29 ,
V_2 -> V_132 , V_14 ,
& V_142 , V_2 ) ;
if ( F_64 ( V_2 -> V_8 ) ) {
V_118 = F_65 ( V_2 -> V_8 ) ;
goto V_121;
}
F_55 ( V_2 -> V_8 ) ;
V_118 = F_66 ( V_126 , V_114 ) ;
if ( V_118 )
goto V_121;
return V_118 ;
V_121:
V_128 -> V_132 -- ;
return V_118 ;
}
static void F_67 ( struct V_122 * V_114 , struct V_122 * V_123 , void * V_124 )
{
struct V_1 * V_2 = F_61 ( V_114 ) ;
F_51 ( V_2 -> V_8 ) ;
F_68 ( V_2 -> V_126 , V_2 -> V_114 ) ;
}
static T_3 F_69 ( int V_143 , void * V_144 )
{
struct V_1 * V_2 = V_144 ;
T_1 V_5 ;
int V_59 ;
if ( ! F_5 ( V_115 , & V_2 -> V_10 ) )
goto V_145;
V_5 = F_2 ( V_2 -> V_6 + V_146 ) ;
V_5 &= V_147 | V_148 ;
if ( V_5 ) {
for ( V_59 = V_2 -> V_85 ; V_59 < V_86 ; V_59 ++ ) {
struct V_87 * V_88 = & V_2 -> V_116 [ V_59 ] ;
if ( ! V_88 -> V_149 )
continue;
F_70 ( V_2 -> V_8 , V_88 ) ;
}
F_3 ( V_5 , V_2 -> V_6 + V_146 ) ;
F_71 ( & V_2 -> V_8 -> V_29 ) ;
}
V_145:
return V_150 ;
}
static int F_72 ( struct V_122 * V_114 )
{
struct V_1 * V_2 = F_61 ( V_114 ) ;
int V_84 = F_56 ( V_119 ) ;
while ( -- V_84 >= 0 )
F_59 ( V_2 -> V_120 [ V_84 ] ) ;
return 0 ;
}
static int F_73 ( struct V_122 * V_114 )
{
struct V_1 * V_2 = F_61 ( V_114 ) ;
int V_84 , V_118 ;
for ( V_84 = 0 ; V_84 < F_56 ( V_119 ) ; V_84 ++ ) {
V_118 = F_57 ( V_2 -> V_120 [ V_84 ] ) ;
if ( V_118 < 0 )
goto V_121;
}
return 0 ;
V_121:
while ( -- V_84 >= 0 )
F_59 ( V_2 -> V_120 [ V_84 ] ) ;
return V_118 ;
}
static int F_74 ( struct V_151 * V_152 )
{
struct V_122 * V_114 = & V_152 -> V_114 ;
struct V_1 * V_2 ;
struct V_153 * V_154 ;
int V_118 ;
int V_84 ;
V_2 = F_75 ( V_114 , sizeof( * V_2 ) , V_155 ) ;
if ( ! V_2 )
return - V_156 ;
F_76 ( V_9 , & V_2 -> V_10 ) ;
V_2 -> V_114 = V_114 ;
V_2 -> V_14 = ( unsigned long ) F_77 ( V_114 ) ;
if ( V_2 -> V_14 & V_31 ) {
V_2 -> V_85 = 1 ;
} else if ( F_78 ( V_114 -> V_157 , L_6 ) ) {
V_2 -> V_14 |= V_15 ;
}
for ( V_84 = 0 ; V_84 < F_56 ( V_119 ) ; V_84 ++ ) {
struct V_158 * V_158 ;
V_158 = F_79 ( V_2 -> V_114 , V_119 [ V_84 ] ) ;
if ( F_64 ( V_158 ) )
return F_65 ( V_158 ) ;
V_2 -> V_120 [ V_84 ] = V_158 ;
}
V_154 = F_80 ( V_152 , V_159 , 0 ) ;
if ( ! V_154 ) {
F_81 ( V_114 , L_7 ) ;
return - V_160 ;
}
V_2 -> V_6 = F_82 ( V_114 , V_154 ) ;
if ( F_64 ( V_2 -> V_6 ) ) {
F_81 ( V_114 , L_8 ) ;
return F_65 ( V_2 -> V_6 ) ;
}
V_154 = F_83 ( V_152 , V_161 ,
( V_2 -> V_14 & V_15 ) ? L_9 : L_10 ) ;
if ( ! V_154 ) {
F_81 ( V_114 , L_11 ) ;
return - V_160 ;
}
V_118 = F_84 ( V_114 , V_154 -> V_162 , F_69 , 0 ,
L_12 , V_2 ) ;
if ( V_118 < 0 ) {
F_81 ( V_114 , L_13 ) ;
return V_118 ;
}
F_85 ( V_152 , V_2 ) ;
F_86 ( V_114 ) ;
V_118 = F_87 ( V_114 , & V_163 ) ;
if ( V_118 )
goto V_164;
return 0 ;
V_164:
F_88 ( V_114 ) ;
return V_118 ;
}
static int F_89 ( struct V_151 * V_152 )
{
F_88 ( & V_152 -> V_114 ) ;
F_90 ( & V_152 -> V_114 , & V_163 ) ;
return 0 ;
}
