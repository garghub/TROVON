T_1 F_1 ( T_2 V_1 , const T_1 * * V_2 )
{
switch ( V_1 ) {
case V_3 :
* V_2 = V_4 ;
return F_2 ( V_4 ) ;
default:
F_3 ( L_1 , V_1 ) ;
* V_2 = NULL ;
return 0 ;
}
}
static T_1 F_4 ( T_1 V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ )
if ( V_7 [ V_6 ] . V_5 == V_5 )
return V_7 [ V_6 ] . V_8 ;
F_3 ( L_2 ,
V_5 ) ;
return V_9 ;
}
static void F_5 ( void T_3 * V_10 , T_1 V_11 , T_1 V_12 )
{
T_1 V_13 , V_14 ;
V_13 = V_11 % 32 ;
V_14 = V_11 / 32 ;
F_6 ( V_10 + F_7 ( V_14 ) , V_13 ,
F_8 ( 1 ) , ! ! V_12 ) ;
}
static T_1 F_9 ( void T_3 * V_10 , T_1 V_11 )
{
T_1 V_15 , V_13 , V_14 ;
V_13 = V_11 % 32 ;
V_14 = V_11 / 32 ;
V_15 = F_10 ( V_10 + F_7 ( V_14 ) ) ;
return ! ! ( F_11 ( V_13 ) & V_15 ) ;
}
static void F_12 ( struct V_16 * V_17 )
{
void T_3 * V_10 = V_17 -> V_10 ;
F_6 ( V_10 + V_18 , V_19 ,
V_20 , V_21 ) ;
F_13 ( 0 , V_10 + V_22 ) ;
F_13 ( 0 , V_10 + V_23 ) ;
F_13 ( 0 , V_10 + F_14 ( V_24 ) ) ;
F_13 ( F_8 ( 32 ) , V_10 + F_15 ( 0 ) ) ;
F_13 ( F_8 ( 32 ) , V_10 + F_15 ( 1 ) ) ;
F_13 ( F_8 ( 32 ) , V_10 + F_7 ( 0 ) ) ;
F_13 ( F_8 ( 32 ) , V_10 + F_7 ( 1 ) ) ;
F_6 ( V_10 + V_25 , V_26 ,
V_27 , V_28 ) ;
}
static void F_16 ( struct V_16 * V_17 ,
struct V_29 * V_30 ,
struct V_29 * V_31 )
{
T_1 V_32 = V_30 -> clock * 1000 ;
int V_33 ;
V_33 = F_17 ( V_17 -> V_34 , V_32 ) ;
if ( V_33 )
F_3 ( L_3 , V_32 , V_33 ) ;
V_31 -> clock = F_18 ( V_17 -> V_34 ) / 1000 ;
}
static void F_19 ( struct V_35 * V_36 ,
struct V_29 * V_30 ,
struct V_29 * V_31 )
{
struct V_16 * V_17 = V_36 -> V_17 ;
void T_3 * V_10 = V_17 -> V_10 ;
T_1 V_37 = V_30 -> V_38 ;
T_1 V_39 = V_30 -> V_40 ;
T_1 V_41 , V_42 , V_43 , V_44 , V_45 , V_46 ;
T_1 V_47 ;
V_47 = ( V_30 -> V_48 & V_49 ) ? V_50 : 0 ;
V_47 |= ( V_30 -> V_48 & V_51 ) ? V_52 : 0 ;
V_41 = V_30 -> V_53 - V_30 -> V_38 ;
V_42 = V_30 -> V_54 - V_30 -> V_55 ;
V_43 = V_30 -> V_55 - V_30 -> V_53 ;
V_44 = V_30 -> V_56 - V_30 -> V_40 ;
V_45 = V_30 -> V_57 - V_30 -> V_58 ;
V_46 = V_30 -> V_58 - V_30 -> V_56 ;
if ( V_46 > 15 ) {
F_20 ( L_4 ) ;
V_46 = 15 ;
}
F_13 ( ( V_42 << V_59 ) | V_41 , V_10 + V_60 ) ;
F_13 ( V_43 - 1 , V_10 + V_61 ) ;
F_13 ( ( V_45 << V_62 ) | V_44 , V_10 + V_63 ) ;
F_13 ( V_46 - 1 , V_10 + V_64 ) ;
F_13 ( ( ( V_39 - 1 ) << V_65 ) | ( V_37 - 1 ) ,
V_10 + V_66 ) ;
F_13 ( V_47 , V_10 + V_67 ) ;
F_13 ( ( ( V_37 - 1 ) << V_68 ) | ( V_39 - 1 ) ,
V_10 + F_21 ( V_24 ) ) ;
F_13 ( V_69 , V_10 + F_22 ( V_70 ) ) ;
F_13 ( V_37 * V_39 - 1 , V_10 + F_23 ( V_70 ) ) ;
F_5 ( V_10 , V_71 + V_70 , 0 ) ;
F_16 ( V_17 , V_30 , V_31 ) ;
F_20 ( L_5 , V_37 , V_39 ) ;
}
static int F_24 ( struct V_16 * V_17 )
{
int V_33 ;
V_33 = F_25 ( V_17 -> V_72 ) ;
if ( V_33 ) {
F_3 ( L_6 , V_33 ) ;
return V_33 ;
}
V_33 = F_26 ( V_17 -> V_73 ) ;
if ( V_33 ) {
F_3 ( L_7 ) ;
return V_33 ;
}
V_33 = F_25 ( V_17 -> V_74 ) ;
if ( V_33 ) {
F_3 ( L_8 , V_33 ) ;
return V_33 ;
}
F_12 ( V_17 ) ;
V_17 -> V_75 = true ;
return 0 ;
}
static void F_27 ( struct V_16 * V_17 )
{
void T_3 * V_10 = V_17 -> V_10 ;
F_13 ( V_76 , V_10 + V_77 ) ;
F_13 ( V_78 , V_10 + V_79 ) ;
F_28 ( V_17 -> V_74 ) ;
F_29 ( V_17 -> V_73 ) ;
F_28 ( V_17 -> V_72 ) ;
V_17 -> V_75 = false ;
}
static void F_30 ( struct V_35 * V_36 )
{
struct V_16 * V_17 = V_36 -> V_17 ;
struct V_80 * V_81 = V_17 -> V_82 ;
F_31 ( V_81 , V_83 ,
V_84 , V_85 ) ;
F_31 ( V_81 , V_86 ,
V_87 , V_87 ) ;
F_31 ( V_81 , V_88 ,
V_84 , V_85 ) ;
F_31 ( V_81 , V_89 ,
V_87 , V_87 ) ;
}
static int F_32 ( struct V_90 * V_91 , unsigned int V_92 )
{
struct V_93 * V_94 = V_91 -> V_95 ;
struct V_35 * V_36 = F_33 ( V_94 -> V_96 [ V_92 ] ) ;
struct V_16 * V_17 = V_36 -> V_17 ;
void T_3 * V_10 = V_17 -> V_10 ;
if ( ! V_17 -> V_75 )
( void ) F_24 ( V_17 ) ;
F_6 ( V_10 + V_97 , V_98 ,
F_8 ( 1 ) , 1 ) ;
return 0 ;
}
static void F_34 ( struct V_90 * V_91 , unsigned int V_92 )
{
struct V_93 * V_94 = V_91 -> V_95 ;
struct V_35 * V_36 = F_33 ( V_94 -> V_96 [ V_92 ] ) ;
struct V_16 * V_17 = V_36 -> V_17 ;
void T_3 * V_10 = V_17 -> V_10 ;
if ( ! V_17 -> V_75 ) {
F_3 ( L_9 ) ;
return;
}
F_6 ( V_10 + V_97 , V_98 ,
F_8 ( 1 ) , 0 ) ;
}
static T_4 F_35 ( int V_99 , void * V_100 )
{
struct V_35 * V_36 = V_100 ;
struct V_16 * V_17 = V_36 -> V_17 ;
struct V_101 * V_96 = & V_36 -> V_10 ;
void T_3 * V_10 = V_17 -> V_10 ;
T_1 V_102 ;
V_102 = F_10 ( V_10 + V_103 ) ;
F_36 ( L_10 , V_102 ) ;
if ( V_102 & F_11 ( V_98 ) ) {
F_6 ( V_10 + V_104 , V_98 ,
F_8 ( 1 ) , 1 ) ;
F_37 ( V_96 ) ;
}
return V_105 ;
}
static void F_38 ( struct V_35 * V_36 )
{
struct V_16 * V_17 = V_36 -> V_17 ;
void T_3 * V_10 = V_17 -> V_10 ;
T_1 V_106 = V_36 -> V_107 ;
F_13 ( V_21 , V_10 + F_14 ( V_24 ) ) ;
F_5 ( V_10 , V_108 + V_24 , 0 ) ;
F_13 ( V_109 , V_10 + V_110 ) ;
F_13 ( V_21 , V_10 + V_111 ) ;
F_13 ( V_112 , V_10 + V_113 ) ;
F_13 ( ( V_106 << V_114 ) | V_115 | V_116 ,
V_10 + V_77 ) ;
F_13 ( V_117 , V_10 + V_79 ) ;
}
static void F_39 ( void T_3 * V_10 , T_1 V_1 )
{
T_1 V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
T_1 V_12 ;
V_118 = F_40 ( V_1 ) ;
V_119 = F_41 ( V_1 ) ;
V_120 = F_42 ( V_1 ) ;
V_121 = F_43 ( V_1 ) ;
V_122 = F_44 ( V_1 ) ;
V_123 = F_45 ( V_1 ) ;
V_12 = F_9 ( V_10 , V_124 + V_1 ) ;
F_20 ( L_11 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + V_118 ) ;
F_20 ( L_12 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + V_119 ) ;
F_20 ( L_13 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + V_120 ) ;
F_20 ( L_14 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + V_121 ) ;
F_20 ( L_15 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + V_122 ) ;
F_20 ( L_16 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + V_123 ) ;
F_20 ( L_17 , V_1 + 1 , V_12 ) ;
}
static void F_46 ( void T_3 * V_10 , T_1 V_1 )
{
T_1 V_12 ;
V_12 = F_9 ( V_10 , V_125 + V_1 ) ;
F_20 ( L_18 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + F_47 ( V_1 ) ) ;
F_20 ( L_19 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + F_48 ( V_1 ) ) ;
F_20 ( L_20 , V_1 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + F_49 ( V_1 ) ) ;
F_20 ( L_21 , V_1 + 1 , V_12 ) ;
}
static void F_50 ( void T_3 * V_10 , T_1 V_1 )
{
T_2 V_126 = 0 ;
T_1 V_12 ;
V_12 = F_10 ( V_10 + F_51 ( V_126 ) ) ;
F_20 ( L_22 , V_126 , V_12 ) ;
V_12 = F_10 ( V_10 + F_52 ( V_126 ) ) ;
F_20 ( L_23 , V_126 , V_12 ) ;
V_12 = F_10 ( V_10 + F_53 ( V_126 ) ) ;
F_20 ( L_24 , V_126 , V_12 ) ;
}
static void F_54 ( void T_3 * V_10 , T_1 V_127 )
{
T_1 V_12 ;
V_12 = F_9 ( V_10 , V_108 + V_127 ) ;
F_20 ( L_25 , V_127 + 1 , V_12 ) ;
F_13 ( V_21 , V_10 + F_14 ( V_127 ) ) ;
F_20 ( L_26 , V_127 + 1 , V_12 ) ;
V_12 = F_10 ( V_10 + V_23 ) ;
F_20 ( L_27 , V_12 ) ;
}
static void F_55 ( void T_3 * V_10 )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_128 ; V_6 ++ ) {
F_39 ( V_10 , V_6 ) ;
F_46 ( V_10 , V_6 ) ;
F_50 ( V_10 , V_6 ) ;
}
F_54 ( V_10 , V_24 ) ;
}
static void F_55 ( void T_3 * V_10 ) { }
static void F_56 ( struct V_101 * V_96 )
{
struct V_35 * V_36 = F_33 ( V_96 ) ;
struct V_16 * V_17 = V_36 -> V_17 ;
int V_33 ;
if ( V_36 -> V_129 )
return;
if ( ! V_17 -> V_75 ) {
V_33 = F_24 ( V_17 ) ;
if ( V_33 )
return;
}
F_30 ( V_36 ) ;
F_38 ( V_36 ) ;
F_55 ( V_17 -> V_10 ) ;
F_57 ( V_96 ) ;
V_36 -> V_129 = true ;
}
static void F_58 ( struct V_101 * V_96 )
{
struct V_35 * V_36 = F_33 ( V_96 ) ;
struct V_16 * V_17 = V_36 -> V_17 ;
if ( ! V_36 -> V_129 )
return;
F_59 ( V_96 ) ;
F_27 ( V_17 ) ;
V_36 -> V_129 = false ;
}
static void F_60 ( struct V_101 * V_96 )
{
struct V_35 * V_36 = F_33 ( V_96 ) ;
struct V_16 * V_17 = V_36 -> V_17 ;
struct V_29 * V_30 = & V_96 -> V_130 -> V_30 ;
struct V_29 * V_31 = & V_96 -> V_130 -> V_131 ;
if ( ! V_17 -> V_75 )
( void ) F_24 ( V_17 ) ;
F_19 ( V_36 , V_30 , V_31 ) ;
}
static void F_61 ( struct V_101 * V_96 ,
struct V_132 * V_133 )
{
struct V_35 * V_36 = F_33 ( V_96 ) ;
struct V_16 * V_17 = V_36 -> V_17 ;
if ( ! V_17 -> V_75 )
( void ) F_24 ( V_17 ) ;
}
static void F_62 ( struct V_101 * V_96 ,
struct V_132 * V_133 )
{
struct V_35 * V_36 = F_33 ( V_96 ) ;
struct V_16 * V_17 = V_36 -> V_17 ;
struct V_134 * V_135 = V_96 -> V_130 -> V_135 ;
void T_3 * V_10 = V_17 -> V_10 ;
if ( V_36 -> V_129 ) {
F_55 ( V_10 ) ;
F_13 ( V_21 , V_10 + V_111 ) ;
}
if ( V_135 ) {
V_96 -> V_130 -> V_135 = NULL ;
F_63 ( & V_96 -> V_91 -> V_136 ) ;
if ( F_64 ( V_96 ) == 0 )
F_65 ( V_96 , V_135 ) ;
else
F_66 ( V_96 , V_135 ) ;
F_67 ( & V_96 -> V_91 -> V_136 ) ;
}
}
static int F_68 ( struct V_90 * V_91 , struct V_101 * V_96 ,
struct V_137 * V_138 )
{
struct V_93 * V_94 = V_91 -> V_95 ;
struct V_139 * V_140 ;
int V_33 ;
V_140 = F_69 ( V_91 -> V_91 -> V_141 , L_28 ) ;
if ( ! V_140 ) {
F_3 ( L_29 ,
V_91 -> V_91 -> V_141 -> V_142 ) ;
return - V_143 ;
}
F_70 ( V_140 ) ;
V_96 -> V_140 = V_140 ;
V_33 = F_71 ( V_91 , V_96 , V_138 , NULL ,
& V_144 , NULL ) ;
if ( V_33 ) {
F_3 ( L_30 ) ;
return V_33 ;
}
F_72 ( V_96 , & V_145 ) ;
V_94 -> V_96 [ F_73 ( V_96 ) ] = V_96 ;
return 0 ;
}
static void F_74 ( void T_3 * V_10 , struct V_146 * V_147 ,
T_1 V_1 , T_1 V_148 , T_1 V_149 , T_1 V_150 )
{
struct V_151 * V_152 = F_75 ( V_147 , 0 ) ;
char * V_153 ;
T_1 V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
T_1 V_154 = V_147 -> V_155 [ 0 ] ;
T_1 V_156 = ( T_1 ) V_152 -> V_157 + V_148 * V_154 ;
F_20 ( L_31 ,
V_1 + 1 , V_148 , V_149 , V_154 , ( T_1 ) V_152 -> V_157 ) ;
V_153 = F_76 ( V_147 -> V_5 ) ;
F_20 ( L_32 ,
V_156 , V_147 -> V_37 , V_147 -> V_39 , V_150 , V_153 ) ;
F_77 ( V_153 ) ;
V_118 = F_40 ( V_1 ) ;
V_119 = F_41 ( V_1 ) ;
V_120 = F_42 ( V_1 ) ;
V_121 = F_43 ( V_1 ) ;
V_122 = F_44 ( V_1 ) ;
V_123 = F_45 ( V_1 ) ;
F_13 ( ( V_150 << 16 ) & 0x1f0000 , V_10 + V_118 ) ;
F_13 ( V_156 , V_10 + V_119 ) ;
F_13 ( ( V_149 << 16 ) | V_154 , V_10 + V_120 ) ;
F_13 ( V_154 , V_10 + V_121 ) ;
F_13 ( V_149 * V_154 , V_10 + V_122 ) ;
F_13 ( V_21 , V_10 + V_123 ) ;
F_5 ( V_10 , V_124 + V_1 , 0 ) ;
}
static void F_78 ( void T_3 * V_10 , T_1 V_1 )
{
T_1 V_123 ;
V_123 = F_45 ( V_1 ) ;
F_13 ( 0 , V_10 + V_123 ) ;
F_5 ( V_10 , V_124 + V_1 , 1 ) ;
}
static void F_79 ( void T_3 * V_10 , T_1 V_1 , T_1 V_158 , T_1 V_159 ,
T_1 V_160 , T_1 V_149 )
{
T_1 V_161 ;
T_1 V_162 ;
T_1 V_163 ;
if ( V_158 == V_160 ) {
V_161 = 1 ;
V_162 = 0 ;
V_163 = 0 ;
} else {
V_161 = 0 ;
V_162 = V_159 ;
V_163 = V_158 - ( V_159 + V_160 ) - 1 ;
}
F_20 ( L_33 ,
V_1 + 1 , V_162 , V_163 ) ;
F_13 ( V_161 , V_10 + F_47 ( V_1 ) ) ;
F_13 ( ( V_158 - 1 ) << 16 | ( V_149 - 1 ) , V_10 + F_48 ( V_1 ) ) ;
F_13 ( V_162 << 16 | V_163 , V_10 + F_49 ( V_1 ) ) ;
F_5 ( V_10 , V_125 + V_1 , 0 ) ;
}
static void F_80 ( void T_3 * V_10 , T_1 V_1 )
{
F_13 ( 1 , V_10 + F_47 ( V_1 ) ) ;
F_5 ( V_10 , V_125 + V_1 , 1 ) ;
}
static bool F_81 ( int V_164 )
{
switch ( V_164 ) {
case V_165 :
case V_166 :
case V_167 :
case V_168 :
return true ;
default:
return false ;
}
}
static void F_82 ( T_1 V_150 , T_2 V_169 , T_2 * V_170 ,
T_2 * V_171 , T_2 * V_172 )
{
bool V_173 = F_81 ( V_150 ) ;
if ( V_173 && V_169 < 255 )
* V_170 = V_174 ;
else if ( V_173 )
* V_170 = V_175 ;
else
* V_170 = V_176 ;
* V_171 = V_177 ;
* V_172 = V_178 ;
}
static void F_83 ( void T_3 * V_10 , T_2 V_1 ,
T_1 V_179 , T_1 y0 ,
T_1 V_160 , T_1 V_149 , T_1 V_150 )
{
T_2 V_126 = 0 ;
T_2 V_169 = 255 ;
T_1 V_180 = V_179 + V_160 - 1 ;
T_1 y1 = y0 + V_149 - 1 ;
T_1 V_12 ;
T_2 V_171 ;
T_2 V_172 ;
T_2 V_170 ;
F_82 ( V_150 , V_169 , & V_170 , & V_171 ,
& V_172 ) ;
F_13 ( V_179 << 16 | y0 , V_10 + F_51 ( V_126 ) ) ;
F_13 ( V_180 << 16 | y1 , V_10 + F_52 ( V_126 ) ) ;
V_12 = ( V_1 + 1 ) << V_181 | F_11 ( V_182 ) |
V_171 << V_183 |
V_172 << V_184 |
V_169 << V_185 |
V_170 << V_186 ;
F_13 ( V_12 , V_10 + F_53 ( V_126 ) ) ;
F_6 ( V_10 + V_23 , F_84 ( V_126 ) ,
V_187 , F_85 ( V_24 ) ) ;
}
static void F_86 ( void T_3 * V_10 , T_1 V_1 )
{
T_2 V_126 = 0 ;
F_6 ( V_10 + F_53 ( V_126 ) , V_182 ,
F_8 ( 1 ) , 0 ) ;
F_6 ( V_10 + V_23 , F_84 ( V_126 ) ,
V_187 , 0 ) ;
}
static void F_87 ( struct V_188 * V_189 ,
struct V_146 * V_147 , int V_190 ,
int V_191 , unsigned int V_192 ,
unsigned int V_193 , T_1 V_194 ,
T_1 V_195 , T_1 V_196 , T_1 V_197 )
{
struct V_16 * V_17 = V_189 -> V_17 ;
void T_3 * V_10 = V_17 -> V_10 ;
T_1 V_150 = F_4 ( V_147 -> V_5 ) ;
T_1 V_1 = V_189 -> V_1 ;
T_1 V_160 ;
T_1 V_149 ;
F_20 ( L_34 ,
V_1 + 1 , V_194 , V_195 , V_196 , V_197 ,
V_190 , V_191 , V_192 , V_193 ) ;
V_160 = V_196 ;
V_149 = V_197 ;
F_74 ( V_10 , V_147 , V_1 , V_195 , V_149 , V_150 ) ;
F_79 ( V_10 , V_1 , V_147 -> V_37 , V_194 , V_160 , V_149 ) ;
F_83 ( V_10 , V_1 , V_190 , V_191 , V_160 , V_149 , V_150 ) ;
}
static void F_88 ( struct V_188 * V_189 )
{
struct V_16 * V_17 = V_189 -> V_17 ;
void T_3 * V_10 = V_17 -> V_10 ;
T_1 V_1 = V_189 -> V_1 ;
F_20 ( L_35 , V_1 + 1 ) ;
F_78 ( V_10 , V_1 ) ;
F_80 ( V_10 , V_1 ) ;
F_86 ( V_10 , V_1 ) ;
}
static int F_89 ( struct V_137 * V_138 ,
struct V_198 * V_130 )
{
struct V_146 * V_147 = V_130 -> V_147 ;
struct V_101 * V_96 = V_130 -> V_96 ;
struct V_132 * V_199 ;
T_1 V_194 = V_130 -> V_194 >> 16 ;
T_1 V_195 = V_130 -> V_195 >> 16 ;
T_1 V_196 = V_130 -> V_196 >> 16 ;
T_1 V_197 = V_130 -> V_197 >> 16 ;
int V_190 = V_130 -> V_190 ;
int V_191 = V_130 -> V_191 ;
T_1 V_192 = V_130 -> V_192 ;
T_1 V_193 = V_130 -> V_193 ;
T_1 V_150 ;
if ( ! V_96 || ! V_147 )
return 0 ;
V_150 = F_4 ( V_147 -> V_5 ) ;
if ( V_150 == V_9 )
return - V_143 ;
V_199 = F_90 ( V_130 -> V_130 , V_96 ) ;
if ( F_91 ( V_199 ) )
return F_92 ( V_199 ) ;
if ( V_196 != V_192 || V_197 != V_193 ) {
F_3 ( L_36 ) ;
return - V_143 ;
}
if ( V_194 + V_196 > V_147 -> V_37 ||
V_195 + V_197 > V_147 -> V_39 )
return - V_143 ;
if ( V_190 < 0 || V_191 < 0 )
return - V_143 ;
if ( V_190 + V_192 > V_199 -> V_131 . V_38 ||
V_191 + V_193 > V_199 -> V_131 . V_40 )
return - V_143 ;
return 0 ;
}
static void F_93 ( struct V_137 * V_138 ,
struct V_198 * V_133 )
{
struct V_198 * V_130 = V_138 -> V_130 ;
struct V_188 * V_189 = F_94 ( V_138 ) ;
F_87 ( V_189 , V_130 -> V_147 , V_130 -> V_190 , V_130 -> V_191 ,
V_130 -> V_192 , V_130 -> V_193 ,
V_130 -> V_194 >> 16 , V_130 -> V_195 >> 16 ,
V_130 -> V_196 >> 16 , V_130 -> V_197 >> 16 ) ;
}
static void F_95 ( struct V_137 * V_138 ,
struct V_198 * V_133 )
{
struct V_188 * V_189 = F_94 ( V_138 ) ;
F_88 ( V_189 ) ;
}
static int F_96 ( struct V_90 * V_91 , struct V_188 * V_189 ,
enum V_200 type )
{
const T_1 * V_201 ;
T_1 V_202 ;
int V_33 = 0 ;
V_202 = F_1 ( V_189 -> V_1 , & V_201 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_97 ( V_91 , & V_189 -> V_10 , 1 , & V_203 ,
V_201 , V_202 , type , NULL ) ;
if ( V_33 ) {
F_3 ( L_37 , V_189 -> V_1 ) ;
return V_33 ;
}
F_98 ( & V_189 -> V_10 , & V_204 ) ;
return 0 ;
}
static int F_99 ( struct V_205 * V_206 , struct V_16 * V_17 )
{
struct V_207 * V_208 ;
struct V_209 * V_91 = & V_206 -> V_91 ;
struct V_139 * V_210 = V_206 -> V_91 . V_141 ;
V_208 = F_100 ( V_206 , V_211 , 0 ) ;
V_17 -> V_10 = F_101 ( V_91 , V_208 ) ;
if ( F_91 ( V_17 -> V_10 ) ) {
F_3 ( L_38 ) ;
return F_92 ( V_17 -> V_10 ) ;
}
V_17 -> V_73 = F_102 ( V_91 , NULL ) ;
if ( F_91 ( V_17 -> V_73 ) )
return F_92 ( V_17 -> V_73 ) ;
V_17 -> V_82 =
F_103 ( V_210 , L_39 ) ;
if ( F_91 ( V_17 -> V_82 ) ) {
F_3 ( L_40 ) ;
return F_92 ( V_17 -> V_82 ) ;
}
V_17 -> V_99 = F_104 ( V_206 , 0 ) ;
if ( V_17 -> V_99 < 0 ) {
F_3 ( L_41 ) ;
return - V_212 ;
}
V_17 -> V_74 = F_105 ( V_91 , L_42 ) ;
if ( F_91 ( V_17 -> V_74 ) ) {
F_3 ( L_43 ) ;
return F_92 ( V_17 -> V_74 ) ;
}
V_17 -> V_72 = F_105 ( V_91 , L_44 ) ;
if ( F_91 ( V_17 -> V_72 ) ) {
F_3 ( L_45 ) ;
return F_92 ( V_17 -> V_72 ) ;
}
V_17 -> V_34 = F_105 ( V_91 , L_46 ) ;
if ( F_91 ( V_17 -> V_34 ) ) {
F_3 ( L_47 ) ;
return F_92 ( V_17 -> V_34 ) ;
}
return 0 ;
}
static int F_106 ( struct V_90 * V_91 )
{
struct V_205 * V_206 = V_91 -> V_213 ;
struct V_214 * V_215 ;
struct V_16 * V_17 ;
struct V_35 * V_36 ;
struct V_188 * V_189 ;
enum V_200 type ;
int V_33 ;
int V_6 ;
V_215 = F_107 ( V_91 -> V_91 , sizeof( * V_215 ) , V_216 ) ;
if ( ! V_215 ) {
F_3 ( L_48 ) ;
return - V_217 ;
}
F_108 ( V_206 , V_215 ) ;
V_17 = & V_215 -> V_17 ;
V_36 = & V_215 -> V_36 ;
V_36 -> V_17 = V_17 ;
V_36 -> V_107 = V_218 ;
V_33 = F_99 ( V_206 , V_17 ) ;
if ( V_33 )
return V_33 ;
for ( V_6 = 0 ; V_6 < V_128 ; V_6 ++ ) {
V_189 = & V_215 -> V_189 [ V_6 ] ;
V_189 -> V_1 = V_6 ;
V_189 -> V_17 = V_17 ;
type = V_6 == V_219 ? V_220 :
V_221 ;
V_33 = F_96 ( V_91 , V_189 , type ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_68 ( V_91 , & V_36 -> V_10 , & V_215 -> V_189 [ V_219 ] . V_10 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_109 ( V_91 -> V_91 , V_17 -> V_99 , F_35 ,
V_222 , V_91 -> V_223 -> V_224 , V_36 ) ;
if ( V_33 )
return V_33 ;
V_91 -> V_223 -> V_225 = V_226 ;
V_91 -> V_223 -> V_227 = F_32 ;
V_91 -> V_223 -> V_228 = F_34 ;
return 0 ;
}
static void F_110 ( struct V_90 * V_91 )
{
struct V_205 * V_206 = V_91 -> V_213 ;
struct V_214 * V_215 = F_111 ( V_206 ) ;
struct V_101 * V_96 = & V_215 -> V_36 . V_10 ;
F_112 ( V_96 ) ;
}
