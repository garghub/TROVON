static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 = ( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static void F_11 ( struct V_10 * V_2 , T_5 V_11 , int V_12 )
{
unsigned long V_13 ;
F_12 ( & V_14 -> V_15 , V_13 ) ;
F_13 ( V_12 , V_16 ) ;
F_13 ( V_11 , V_17 ) ;
F_14 ( & V_14 -> V_15 , V_13 ) ;
}
static T_5 F_15 ( struct V_10 * V_2 , int V_12 )
{
unsigned long V_13 ;
T_5 V_18 ;
F_12 ( & V_14 -> V_15 , V_13 ) ;
F_13 ( V_12 , V_16 ) ;
V_18 = F_16 ( V_17 ) ;
F_14 ( & V_14 -> V_15 , V_13 ) ;
return V_18 ;
}
static void F_17 ( struct V_10 * V_2 , T_5 V_11 ,
int V_12 )
{
unsigned V_19 ;
switch ( V_12 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
case V_26 :
V_19 = V_27 ;
break;
case V_28 :
V_19 = V_29 ;
break;
case V_30 :
V_19 = V_31 ;
break;
case V_32 :
V_19 = V_33 ;
break;
case V_34 :
V_19 = V_35 ;
break;
case V_36 :
F_18 ( V_11 , V_37 ) ;
return;
break;
case V_38 :
F_18 ( V_11 , V_39 ) ;
return;
break;
case V_40 :
V_19 = V_41 ;
break;
case V_42 :
V_19 = V_43 ;
break;
case V_44 :
V_19 = V_45 ;
break;
case V_46 :
V_19 = V_47 ;
break;
case V_48 :
V_19 = V_49 ;
break;
case V_50 :
V_19 = V_51 ;
break;
case V_52 :
V_19 = V_53 ;
break;
case V_54 :
V_19 = V_55 ;
break;
case V_56 :
V_19 = V_57 ;
break;
case V_58 :
V_19 = V_59 ;
break;
case V_60 :
V_19 = V_61 ;
break;
case V_62 :
V_19 = V_63 ;
break;
case V_64 :
V_19 = V_65 ;
break;
case V_66 :
V_19 = V_67 ;
break;
case V_68 :
V_19 = V_69 ;
break;
case V_70 :
F_19
( L_1 ,
V_71 , V_12 ) ;
return;
break;
case F_20 ( 0 ) :
V_19 = V_72 ;
break;
case F_20 ( 1 ) :
V_19 = V_73 ;
break;
case F_21 ( 0 ) :
V_19 = V_74 ;
break;
case F_21 ( 1 ) :
V_19 = V_75 ;
break;
case F_22 ( 0 ) :
V_19 = V_76 ;
break;
case F_22 ( 1 ) :
V_19 = V_77 ;
break;
case F_23 ( 0 ) :
V_19 = V_78 ;
break;
case F_23 ( 1 ) :
V_19 = V_79 ;
break;
case V_80 :
V_19 = V_81 ;
break;
case V_82 :
V_19 = V_83 ;
break;
case V_84 :
V_19 = V_85 ;
break;
case V_86 :
V_19 = V_87 ;
break;
case V_88 :
V_19 = V_89 ;
break;
case V_90 :
V_19 = V_91 ;
break;
case V_92 :
V_19 = V_93 ;
break;
case V_94 :
V_19 = V_95 ;
break;
case V_96 :
V_19 = V_97 ;
break;
case V_98 :
V_19 = V_99 ;
break;
default:
F_19 ( L_2 ,
V_71 , V_12 ) ;
F_24 () ;
return;
break;
}
F_13 ( V_11 , V_19 ) ;
}
static T_5 F_25 ( struct V_10 * V_2 , int V_12 )
{
unsigned V_19 ;
switch ( V_12 ) {
case V_100 :
V_19 = V_101 ;
break;
case V_102 :
V_19 = V_103 ;
break;
case V_104 :
V_19 = V_105 ;
break;
case V_106 :
return F_26 ( V_107 ) ;
break;
case V_108 :
V_19 = V_109 ;
break;
case V_110 :
V_19 = V_111 ;
break;
case V_112 :
V_19 = V_113 ;
break;
default:
F_19 ( L_2 ,
V_71 , V_12 ) ;
F_24 () ;
return 0 ;
break;
}
return F_16 ( V_19 ) ;
}
static void F_27 ( struct V_10 * V_2 , T_6 V_11 ,
int V_12 )
{
unsigned V_19 ;
switch ( V_12 ) {
case V_114 :
V_19 = V_115 ;
break;
case V_116 :
V_19 = V_117 ;
break;
case V_118 :
V_19 = V_119 ;
break;
case V_120 :
V_19 = V_121 ;
break;
case V_122 :
V_19 = V_123 ;
break;
case F_28 ( 0 ) :
V_19 = V_124 ;
break;
case F_28 ( 1 ) :
V_19 = V_125 ;
break;
case F_29 ( 0 ) :
V_19 = V_126 ;
break;
case F_29 ( 1 ) :
V_19 = V_127 ;
break;
default:
F_19 ( L_2 ,
V_71 , V_12 ) ;
F_24 () ;
return;
break;
}
F_18 ( V_11 , V_19 ) ;
}
static T_6 F_30 ( struct V_10 * V_2 , int V_12 )
{
unsigned V_19 ;
switch ( V_12 ) {
case F_31 ( 0 ) :
V_19 = V_128 ;
break;
case F_31 ( 1 ) :
V_19 = V_129 ;
break;
case F_32 ( 0 ) :
V_19 = V_130 ;
break;
case F_32 ( 1 ) :
V_19 = V_131 ;
break;
default:
F_19 ( L_2 ,
V_71 , V_12 ) ;
F_24 () ;
return 0 ;
break;
}
return F_33 ( V_19 ) ;
}
static void F_34 ( struct V_10 * V_2 )
{
static const int V_132 = 0x400 ;
static const unsigned V_133 = 10 ;
static const int V_134 = 0x4 ;
static const int V_135 = 0x4 ;
unsigned V_136 ;
unsigned V_137 ;
unsigned V_138 ;
int V_139 ;
V_136 = F_35 ( V_14 -> V_140 -> V_141 + V_142 ) ;
V_137 = F_35 ( V_14 -> V_140 -> V_141 + V_143 ) ;
V_138 = F_35 ( V_14 -> V_140 -> V_141 + V_144 ) ;
F_36 ( 0x0 , V_14 -> V_140 -> V_141 + V_142 ) ;
F_36 ( ( ( 0x80 | V_133 ) | V_14 -> V_140 -> V_145 ) ,
V_14 -> V_140 -> V_141 + V_143 ) ;
F_36 ( 0x1 | V_138 ,
V_14 -> V_140 -> V_141 + V_144 ) ;
F_36 ( 0xf , V_14 -> V_140 -> V_141 + 0x30 ) ;
F_37 ( V_135 > sizeof( V_14 -> V_146 ) ) ;
for ( V_139 = 0 ; V_139 < V_135 ; ++ V_139 ) {
char * V_147 = ( char * ) & V_14 -> V_146 + V_139 ;
* V_147 = F_26 ( V_134 + V_139 ) ;
}
V_14 -> V_146 = F_38 ( V_14 -> V_146 ) ;
for ( V_139 = 0 ; V_139 < V_148 ; ++ V_139 ) {
V_14 -> V_149 [ V_139 ] = F_26 ( V_132 + V_139 ) ;
}
F_36 ( V_137 , V_14 -> V_140 -> V_141 + V_143 ) ;
F_36 ( V_136 , V_14 -> V_140 -> V_141 + V_142 ) ;
F_36 ( V_138 , V_14 -> V_140 -> V_141 + V_144 ) ;
F_36 ( 0x0 , V_14 -> V_140 -> V_141 + 0x30 ) ;
}
static void F_39 ( struct V_10 * V_2 )
{
V_14 -> V_150 ( V_2 , 0 , V_88 ) ;
F_40 ( 0x00 , V_151 ) ;
F_40 ( 0x80 , V_152 ) ;
F_40 ( 0x00 , V_153 ) ;
F_18 ( V_154 . V_155 / 2 , V_156 ) ;
V_14 -> V_157 = 0 ;
F_13 ( V_14 -> V_158 | V_159 ,
V_160 ) ;
F_13 ( V_14 -> V_158 , V_160 ) ;
}
static int F_41 ( struct V_10 * V_2 )
{
F_42 ( V_2 ) ;
if ( V_2 -> V_161 ) {
F_43 ( V_2 -> V_161 , V_2 ) ;
}
if ( V_2 -> V_162 ) {
F_44 ( V_14 -> V_163 ) ;
F_44 ( V_14 -> V_164 ) ;
F_44 ( V_14 -> V_165 ) ;
F_44 ( V_14 -> V_166 [ 0 ] ) ;
F_44 ( V_14 -> V_166 [ 1 ] ) ;
if ( V_14 -> V_140 )
F_45 ( V_14 -> V_140 ) ;
}
return 0 ;
}
static int F_46 ( struct V_10 * V_2 , struct V_167 * V_168 )
{
int V_18 ;
F_19 ( L_3 , V_2 -> V_169 ) ;
V_18 = F_47 ( V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_48 ( V_2 , V_168 -> V_170 [ 0 ] , V_168 -> V_170 [ 1 ] ) ;
if ( V_18 < 0 )
return V_18 ;
F_19 ( L_4 , V_154 . V_9 ) ;
V_2 -> V_171 = V_154 . V_9 ;
if ( V_154 . V_172 & V_173 ) {
V_14 -> V_150 = & F_17 ;
V_14 -> V_174 = & F_25 ;
V_14 -> V_175 = & F_27 ;
V_14 -> V_176 = & F_30 ;
} else {
V_14 -> V_150 = & F_11 ;
V_14 -> V_174 = & F_15 ;
V_14 -> V_175 = & V_177 ;
V_14 -> V_176 = & V_178 ;
}
V_18 = F_49 ( V_14 -> V_140 ) ;
if ( V_18 < 0 ) {
F_19 ( L_5 ) ;
return V_18 ;
}
F_50 ( V_2 , & V_14 -> V_140 -> V_179 -> V_2 ) ;
V_14 -> V_163 = F_51 ( V_14 -> V_140 ) ;
if ( V_14 -> V_163 == NULL )
return - V_180 ;
V_14 -> V_164 = F_51 ( V_14 -> V_140 ) ;
if ( V_14 -> V_164 == NULL )
return - V_180 ;
V_14 -> V_165 = F_51 ( V_14 -> V_140 ) ;
if ( V_14 -> V_165 == NULL )
return - V_180 ;
V_14 -> V_166 [ 0 ] = F_51 ( V_14 -> V_140 ) ;
if ( V_14 -> V_166 [ 0 ] == NULL )
return - V_180 ;
V_14 -> V_166 [ 1 ] = F_51 ( V_14 -> V_140 ) ;
if ( V_14 -> V_166 [ 1 ] == NULL )
return - V_180 ;
if ( V_154 . V_172 & V_173 )
F_34 ( V_2 ) ;
if ( V_154 . V_172 == V_181 )
F_39 ( V_2 ) ;
V_2 -> V_161 = F_52 ( V_14 -> V_140 ) ;
if ( V_2 -> V_161 == 0 ) {
F_19 ( L_6 ) ;
} else {
F_19 ( L_7 , V_2 -> V_161 ) ;
V_18 = F_53 ( V_2 -> V_161 , V_182 , V_183 ,
V_184 , V_2 ) ;
if ( V_18 < 0 ) {
F_19 ( L_8 ) ;
V_2 -> V_161 = 0 ;
}
}
V_18 = F_54 ( V_2 , V_168 ) ;
if ( V_18 < 0 )
return V_18 ;
V_2 -> V_185 [ V_186 ] . V_187 = & V_188 ;
V_2 -> V_185 [ V_189 ] . V_187 = & V_190 ;
V_2 -> V_185 [ F_55 ( 0 ) ] . V_187 = & V_191 ;
V_2 -> V_185 [ F_55 ( 1 ) ] . V_187 = & V_192 ;
V_2 -> V_185 [ V_193 ] . V_187 = & V_194 ;
return V_18 ;
}
static int F_48 ( struct V_10 * V_2 , int V_195 , int V_196 )
{
struct V_197 * V_140 ;
int V_139 ;
for ( V_140 = V_198 ; V_140 ; V_140 = V_140 -> V_199 ) {
if ( V_140 -> V_200 )
continue;
if ( V_195 || V_196 ) {
if ( V_195 != V_140 -> V_179 -> V_195 -> V_201 ||
V_196 != F_56 ( V_140 -> V_179 -> V_202 ) )
continue;
}
for ( V_139 = 0 ; V_139 < V_203 ; V_139 ++ ) {
if ( F_57 ( V_140 ) == V_204 [ V_139 ] . V_205 ) {
V_2 -> V_206 = V_204 + V_139 ;
V_14 -> V_140 = V_140 ;
return 0 ;
}
}
}
F_19 ( L_9 ) ;
F_58 () ;
return - V_207 ;
}
static int V_188 ( struct V_10 * V_2 ,
struct V_208 * V_209 , unsigned long V_210 )
{
int V_18 ;
V_18 = F_59 ( V_14 -> V_163 , V_209 -> V_211 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int V_190 ( struct V_10 * V_2 ,
struct V_208 * V_209 , unsigned long V_210 )
{
int V_18 ;
V_18 = F_59 ( V_14 -> V_164 , V_209 -> V_211 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int V_191 ( struct V_10 * V_2 ,
struct V_208 * V_209 ,
unsigned long V_210 )
{
int V_18 ;
V_18 = F_59 ( V_14 -> V_166 [ 0 ] , V_209 -> V_211 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int V_192 ( struct V_10 * V_2 ,
struct V_208 * V_209 ,
unsigned long V_210 )
{
int V_18 ;
V_18 = F_59 ( V_14 -> V_166 [ 1 ] , V_209 -> V_211 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int V_194 ( struct V_10 * V_2 ,
struct V_208 * V_209 , unsigned long V_210 )
{
int V_18 ;
V_18 = F_59 ( V_14 -> V_165 , V_209 -> V_211 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
