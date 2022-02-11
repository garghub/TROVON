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
V_5 = V_9 ;
if ( V_8 -> V_10 )
V_5 |= V_11 ;
else
V_5 |= V_12 | V_13 ;
F_3 ( V_5 , V_2 -> V_6 + V_14 ) ;
F_5 ( V_2 -> V_15 ) ;
if ( ! ( V_2 -> V_16 & V_17 ) )
F_5 ( V_2 -> V_18 ) ;
return 0 ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! ( V_2 -> V_16 & V_17 ) )
F_7 ( V_2 -> V_18 ) ;
F_7 ( V_2 -> V_15 ) ;
F_3 ( 0 , V_2 -> V_6 + V_14 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , bool V_19 )
{
T_1 V_20 , V_21 , V_22 , V_23 = 2 ;
V_20 = F_2 ( V_2 -> V_6 + V_24 ) ;
do {
V_22 = F_2 ( V_2 -> V_6 + V_25 ) ;
V_21 = V_20 ;
V_20 = F_2 ( V_2 -> V_6 + V_24 ) ;
} while ( V_20 != V_21 && -- V_23 );
if ( ! V_20 )
return 0 ;
switch ( V_22 & ( V_26 | V_27 ) ) {
case V_28 :
if ( ! ( V_2 -> V_8 -> V_10 ) )
-- V_20 ;
break;
case V_29 :
-- V_20 ;
break;
case V_27 :
case V_30 :
if ( V_19 )
-- V_20 ;
break;
default:
break;
}
return V_20 ;
}
static T_1 F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
return F_8 ( V_2 , false ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_8 -> V_10 && ! ( V_2 -> V_16 & V_17 ) )
return;
if ( ! ( V_2 -> V_16 & V_17 ) ) {
F_3 ( V_31 | V_32 |
V_33 | V_34 ,
V_2 -> V_6 + V_35 ) ;
return;
}
F_3 ( V_31 | V_32 | V_36
| V_37 , V_2 -> V_6 + V_35 ) ;
if ( F_11 ( V_2 -> V_38 , V_39 ,
V_40 , ~ 0 ) )
F_12 ( L_1 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_41 * V_42 = & V_8 -> V_43 . V_44 ;
bool V_45 = false ;
T_1 V_5 ;
if ( V_2 -> V_16 & V_46 ) {
V_42 -> V_47 = V_42 -> V_48 + 10 ;
V_42 -> V_49 = V_42 -> V_50 - 92 ;
V_42 -> V_51 = V_42 -> V_52 + 1 ;
V_42 -> V_53 = V_42 -> V_51 + 1 ;
if ( V_42 -> V_54 & V_55 )
V_45 = true ;
}
F_10 ( V_2 ) ;
V_5 = V_56 ;
if ( V_45 )
V_5 |= V_57 ;
if ( V_8 -> V_10 ) {
V_5 |= V_58 ;
} else {
V_5 |= V_59 ;
}
F_3 ( V_5 , V_2 -> V_6 + V_60 ) ;
if ( V_45 )
V_5 = F_14 ( V_42 -> V_61 / 2 - 1 ) |
F_15 ( V_42 -> V_62 - 1 ) ;
else
V_5 = F_14 ( V_42 -> V_61 - 1 ) |
F_15 ( V_42 -> V_62 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_63 ) ;
if ( ! V_8 -> V_10 ) {
int V_64 = V_42 -> V_65 - V_42 -> V_53 ;
int V_66 = V_42 -> V_51 - V_42 -> V_52 ;
if ( V_45 )
V_64 = V_64 / 2 - 1 ;
V_5 = F_16 ( V_64 - 1 ) | F_17 ( V_66 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_67 ) ;
V_5 = F_18 (
V_42 -> V_53 - V_42 -> V_51 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_68 ) ;
V_5 = F_19 (
V_42 -> V_50 - V_42 -> V_49 - 1 ) |
F_20 (
V_42 -> V_47 - V_42 -> V_48 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_69 ) ;
V_5 = F_21 (
V_42 -> V_49 - V_42 -> V_47 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_70 ) ;
}
F_1 ( V_2 , V_71 , V_72 | V_73 , ~ 0 ) ;
F_1 ( V_2 , V_74 , V_75 , ~ 0 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_76 ,
struct V_77 * V_78 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_2 -> V_6 + F_23 ( V_76 ) ) ;
V_5 &= ~ V_79 ;
switch ( V_78 -> V_80 -> V_80 ) {
case V_81 :
V_5 |= V_82 ;
V_5 |= V_83 ;
V_5 |= V_84 ;
break;
case V_85 :
V_5 |= V_86 ;
V_5 |= V_83 ;
V_5 |= V_84 ;
break;
case V_87 :
V_5 |= V_88 ;
V_5 |= V_89 ;
V_5 |= V_84 ;
break;
case V_90 :
default:
V_5 |= V_91 ;
V_5 |= V_89 | V_92 | V_93 ;
V_5 |= V_84 ;
break;
}
F_24 ( L_2 , V_78 -> V_80 -> V_94 [ 0 ] ) ;
if ( V_78 -> V_95 < V_96 ) {
V_5 &= ~ V_97 ;
V_5 |= V_98 ;
}
F_3 ( V_5 , V_2 -> V_6 + F_23 ( V_76 ) ) ;
}
static void F_25 ( struct V_1 * V_2 , bool V_99 )
{
F_1 ( V_2 , V_100 , V_101 ,
V_99 ? ~ 0 : 0 ) ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_25 ( V_2 , true ) ;
}
static void F_27 ( struct V_7 * V_8 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 =
F_28 ( V_103 -> V_43 . V_105 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_77 * V_78 = V_105 -> V_43 . V_78 ;
unsigned int V_76 = V_103 -> V_106 ;
unsigned int V_94 = V_78 -> V_80 -> V_94 [ 0 ] ;
unsigned int V_107 = V_78 -> V_108 [ 0 ] ;
T_2 V_109 = F_29 ( V_78 , 0 ) ;
T_1 V_5 ;
if ( V_8 -> V_43 . V_44 . V_54 & V_55 ) {
V_5 = F_30 ( V_105 -> V_8 . V_110 ) |
F_31 ( V_105 -> V_8 . V_111 / 2 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_32 ( V_76 ) ) ;
V_5 = F_30 ( V_105 -> V_8 . V_110 + V_105 -> V_8 . V_112 - 1 ) |
F_31 ( ( V_105 -> V_8 . V_111 + V_105 -> V_8 . V_113 ) / 2 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_33 ( V_76 ) ) ;
} else {
V_5 = F_30 ( V_105 -> V_8 . V_110 ) | F_31 ( V_105 -> V_8 . V_111 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_32 ( V_76 ) ) ;
V_5 = F_30 ( V_105 -> V_8 . V_110 + V_105 -> V_8 . V_112 - 1 ) |
F_31 ( V_105 -> V_8 . V_111 + V_105 -> V_8 . V_113 - 1 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_33 ( V_76 ) ) ;
}
V_5 = F_34 ( 0x0 ) | F_35 ( 0x0 ) |
F_36 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_37 ( V_76 ) ) ;
V_5 = F_34 ( 0x0 ) | F_35 ( 0x0 ) |
F_36 ( 0x0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_38 ( V_76 ) ) ;
F_3 ( V_109 , V_2 -> V_6 + F_39 ( V_76 ) ) ;
V_5 = V_109 + V_107 * V_105 -> V_114 . V_113 ;
F_3 ( V_5 , V_2 -> V_6 + F_40 ( V_76 ) ) ;
if ( ! ( V_2 -> V_16 & V_46 ) )
V_5 = F_41 ( V_107 - V_105 -> V_8 . V_112 * V_94 , 27 , 14 )
| F_41 ( V_105 -> V_8 . V_112 * V_94 , 13 , 0 ) ;
else
V_5 = F_41 ( V_107 - V_105 -> V_8 . V_112 * V_94 , 29 , 15 )
| F_41 ( V_105 -> V_8 . V_112 * V_94 , 14 , 0 ) ;
F_3 ( V_5 , V_2 -> V_6 + F_42 ( V_76 ) ) ;
F_22 ( V_2 , V_76 , V_78 ) ;
F_1 ( V_2 , F_23 ( V_76 ) , V_115 , ~ 0 ) ;
}
static void F_43 ( struct V_7 * V_8 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_76 = V_103 -> V_106 ;
F_1 ( V_2 , F_23 ( V_76 ) , V_115 , 0 ) ;
}
static void F_44 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_54 ;
F_45 ( & V_2 -> V_116 , V_54 ) ;
F_25 ( V_2 , false ) ;
F_1 ( V_2 , V_74 , V_75 , ~ 0 ) ;
V_2 -> V_117 = F_8 ( V_2 , true ) ;
F_46 ( V_8 ) ;
F_47 ( & V_2 -> V_116 , V_54 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
T_1 V_5 ;
int V_118 ;
F_3 ( 0 , V_2 -> V_6 + V_71 ) ;
F_49 ( V_2 -> V_6 + V_71 , V_5 ,
~ V_5 & V_119 , 12 , 20000 ) ;
F_3 ( V_120 , V_2 -> V_6 + V_71 ) ;
V_118 = F_49 ( V_2 -> V_6 + V_71 , V_5 ,
~ V_5 & V_120 , 12 , 20000 ) ;
F_50 ( V_118 < 0 , L_3 ) ;
F_45 ( & V_2 -> V_116 , V_54 ) ;
V_2 -> V_117 = 0 ;
F_47 ( & V_2 -> V_116 , V_54 ) ;
if ( ! ( V_2 -> V_16 & V_46 ) )
return;
F_3 ( V_121 | V_122 , V_2 -> V_6 + V_71 ) ;
F_1 ( V_2 , V_123 ,
V_124 | V_125 , ~ 0 ) ;
F_3 ( V_126 , V_2 -> V_6 + V_25 ) ;
F_3 ( V_127 | V_128 | V_129 ,
V_2 -> V_6 + V_130 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
F_52 ( V_2 -> V_131 ) ;
F_53 ( V_8 , true ) ;
F_48 ( V_2 ) ;
F_13 ( V_2 -> V_8 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_132 ;
if ( ! ( V_2 -> V_16 & V_17 ) )
F_55 ( V_2 -> V_18 ) ;
F_55 ( V_2 -> V_15 ) ;
for ( V_132 = V_2 -> V_133 ; V_132 < V_134 ; V_132 ++ )
F_43 ( V_8 , & V_2 -> V_135 [ V_132 ] ) ;
F_48 ( V_2 ) ;
F_53 ( V_8 , false ) ;
F_56 ( V_2 -> V_131 ) ;
}
static T_3 F_57 ( int V_15 , void * V_136 )
{
struct V_1 * V_2 = V_136 ;
F_1 ( V_2 , V_35 , V_137 , ~ 0 ) ;
return V_138 ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
int V_76 , V_132 , V_118 ;
F_24 ( L_4 , __FILE__ ) ;
for ( V_132 = 0 ; V_132 < F_59 ( V_139 ) ; V_132 ++ ) {
V_118 = F_60 ( V_2 -> V_140 [ V_132 ] ) ;
if ( V_118 < 0 )
goto V_141;
}
F_25 ( V_2 , true ) ;
for ( V_76 = 0 ; V_76 < V_134 ; V_76 ++ )
F_1 ( V_2 , F_23 ( V_76 ) , V_115 , 0 ) ;
F_25 ( V_2 , false ) ;
F_1 ( V_2 , V_74 , V_75 , ~ 0 ) ;
F_61 ( 50 ) ;
V_141:
while ( -- V_132 >= 0 )
F_62 ( V_2 -> V_140 [ V_132 ] ) ;
}
static enum V_142 F_63 ( struct V_7 * V_8 ,
const struct V_41 * V_44 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
V_2 -> V_15 = V_8 -> V_10 ? V_2 -> V_143 : V_2 -> V_144 ;
if ( V_2 -> V_15 )
return V_145 ;
F_64 ( V_2 -> V_131 , L_5 ,
V_8 -> V_10 ? L_6 : L_7 ) ;
return V_146 ;
}
static int F_65 ( struct V_147 * V_131 , struct V_147 * V_148 , void * V_149 )
{
struct V_1 * V_2 = F_66 ( V_131 ) ;
struct V_150 * V_151 = V_149 ;
struct V_102 * V_152 ;
enum V_153 V_16 ;
unsigned int V_76 ;
int V_118 ;
V_2 -> V_151 = V_151 ;
V_151 -> V_154 = 0xffffffff ;
for ( V_76 = V_2 -> V_133 ; V_76 < V_134 ; V_76 ++ ) {
int V_155 = ( V_76 == V_2 -> V_133 ) ? 0 : V_76 ;
V_2 -> V_156 [ V_76 ] . V_157 = V_158 ;
V_2 -> V_156 [ V_76 ] . V_159 = F_59 ( V_158 ) ;
V_2 -> V_156 [ V_76 ] . V_160 = V_76 ;
V_2 -> V_156 [ V_76 ] . type = V_161 [ V_155 ] ;
V_118 = F_67 ( V_151 , & V_2 -> V_135 [ V_76 ] , V_76 ,
& V_2 -> V_156 [ V_76 ] ) ;
if ( V_118 )
return V_118 ;
}
V_152 = & V_2 -> V_135 [ V_2 -> V_133 ] ;
V_16 = ( V_2 -> V_16 & V_46 ) ? V_162
: V_163 ;
V_2 -> V_8 = F_68 ( V_151 , & V_152 -> V_43 ,
V_16 , & V_164 , V_2 ) ;
if ( F_69 ( V_2 -> V_8 ) )
return F_70 ( V_2 -> V_8 ) ;
F_58 ( V_2 -> V_8 ) ;
return F_71 ( V_151 , V_131 ) ;
}
static void F_72 ( struct V_147 * V_131 , struct V_147 * V_148 , void * V_149 )
{
struct V_1 * V_2 = F_66 ( V_131 ) ;
F_54 ( V_2 -> V_8 ) ;
F_73 ( V_2 -> V_151 , V_2 -> V_131 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_20 ;
F_75 ( & V_2 -> V_116 ) ;
V_20 = F_8 ( V_2 , true ) ;
if ( V_20 != V_2 -> V_117 ) {
if ( ( V_165 ) ( V_20 - V_2 -> V_117 ) > 0 )
F_76 ( & V_2 -> V_8 -> V_43 ) ;
V_2 -> V_117 = V_20 ;
}
F_77 ( & V_2 -> V_116 ) ;
}
static T_3 F_78 ( int V_15 , void * V_136 )
{
struct V_1 * V_2 = V_136 ;
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_6 + V_166 ) ;
V_5 &= V_167 | V_168 ;
if ( V_5 ) {
F_3 ( V_5 , V_2 -> V_6 + V_166 ) ;
if ( V_2 -> V_16 & V_46 ) {
V_5 = F_2 ( V_2 -> V_6 + V_60 ) ;
V_5 &= V_57 | V_169 ;
if ( V_5 ==
( V_57 | V_169 ) )
return V_138 ;
}
F_74 ( V_2 ) ;
}
return V_138 ;
}
static int F_79 ( struct V_147 * V_131 )
{
struct V_1 * V_2 = F_66 ( V_131 ) ;
int V_132 = F_59 ( V_139 ) ;
while ( -- V_132 >= 0 )
F_62 ( V_2 -> V_140 [ V_132 ] ) ;
return 0 ;
}
static int F_80 ( struct V_147 * V_131 )
{
struct V_1 * V_2 = F_66 ( V_131 ) ;
int V_132 , V_118 ;
for ( V_132 = 0 ; V_132 < F_59 ( V_139 ) ; V_132 ++ ) {
V_118 = F_60 ( V_2 -> V_140 [ V_132 ] ) ;
if ( V_118 < 0 )
goto V_141;
}
return 0 ;
V_141:
while ( -- V_132 >= 0 )
F_62 ( V_2 -> V_140 [ V_132 ] ) ;
return V_118 ;
}
static int F_81 ( struct V_1 * V_2 , const char * V_170 ,
T_4 V_171 , unsigned long int V_54 )
{
struct V_172 * V_173 = F_82 ( V_2 -> V_131 ) ;
int V_118 , V_15 = F_83 ( V_173 , V_170 ) ;
if ( V_15 < 0 ) {
switch ( V_15 ) {
case - V_174 :
return V_15 ;
case - V_175 :
case - V_176 :
return 0 ;
default:
F_84 ( V_2 -> V_131 , L_8 , V_170 , V_15 ) ;
return V_15 ;
}
}
F_85 ( V_15 , V_177 ) ;
V_118 = F_86 ( V_2 -> V_131 , V_15 , V_171 , V_54 , L_9 , V_2 ) ;
if ( V_118 < 0 ) {
F_84 ( V_2 -> V_131 , L_10 , V_170 ) ;
return V_118 ;
}
return V_15 ;
}
static int F_87 ( struct V_172 * V_173 )
{
struct V_147 * V_131 = & V_173 -> V_131 ;
struct V_1 * V_2 ;
struct V_178 * V_179 ;
int V_118 ;
int V_132 ;
V_2 = F_88 ( V_131 , sizeof( * V_2 ) , V_180 ) ;
if ( ! V_2 )
return - V_181 ;
V_2 -> V_131 = V_131 ;
V_2 -> V_16 = ( unsigned long ) F_89 ( V_131 ) ;
F_90 ( & V_2 -> V_116 ) ;
if ( V_2 -> V_16 & V_46 )
V_2 -> V_133 = 1 ;
for ( V_132 = 0 ; V_132 < F_59 ( V_139 ) ; V_132 ++ ) {
struct V_182 * V_182 ;
V_182 = F_91 ( V_2 -> V_131 , V_139 [ V_132 ] ) ;
if ( F_69 ( V_182 ) )
return F_70 ( V_182 ) ;
V_2 -> V_140 [ V_132 ] = V_182 ;
}
V_179 = F_92 ( V_173 , V_183 , 0 ) ;
if ( ! V_179 ) {
F_84 ( V_131 , L_11 ) ;
return - V_176 ;
}
V_2 -> V_6 = F_93 ( V_131 , V_179 ) ;
if ( F_69 ( V_2 -> V_6 ) ) {
F_84 ( V_131 , L_12 ) ;
return F_70 ( V_2 -> V_6 ) ;
}
V_118 = F_81 ( V_2 , L_13 , F_78 , 0 ) ;
if ( V_118 < 0 )
return V_118 ;
V_2 -> V_144 = V_118 ;
V_118 = F_81 ( V_2 , L_14 , F_78 , 0 ) ;
if ( V_118 < 0 )
return V_118 ;
V_2 -> V_143 = V_118 ;
V_118 = F_81 ( V_2 , L_15 , F_57 ,
V_184 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_118 ) {
V_2 -> V_18 = V_118 ;
V_2 -> V_16 &= ~ V_17 ;
}
if ( V_2 -> V_16 & V_17 ) {
V_2 -> V_38 = F_94 ( V_131 -> V_185 ,
L_16 ) ;
if ( F_69 ( V_2 -> V_38 ) ) {
F_84 ( V_131 , L_17 ) ;
return F_70 ( V_2 -> V_38 ) ;
}
}
F_95 ( V_173 , V_2 ) ;
F_96 ( V_131 ) ;
V_118 = F_97 ( V_131 , & V_186 ) ;
if ( V_118 )
goto V_187;
return 0 ;
V_187:
F_98 ( V_131 ) ;
return V_118 ;
}
static int F_99 ( struct V_172 * V_173 )
{
F_98 ( & V_173 -> V_131 ) ;
F_100 ( & V_173 -> V_131 , & V_186 ) ;
return 0 ;
}
