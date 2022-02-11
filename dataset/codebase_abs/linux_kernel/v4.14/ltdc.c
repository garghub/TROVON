static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static inline void F_5 ( void T_2 * V_1 , T_1 V_2 , T_1 V_4 )
{
F_3 ( V_1 , V_2 , F_1 ( V_1 , V_2 ) | V_4 ) ;
}
static inline void F_6 ( void T_2 * V_1 , T_1 V_2 , T_1 V_4 )
{
F_3 ( V_1 , V_2 , F_1 ( V_1 , V_2 ) & ~ V_4 ) ;
}
static inline void F_7 ( void T_2 * V_1 , T_1 V_2 , T_1 V_4 ,
T_1 V_3 )
{
F_3 ( V_1 , V_2 , ( F_1 ( V_1 , V_2 ) & ~ V_4 ) | V_3 ) ;
}
static inline struct V_5 * F_8 ( struct V_6 * V_7 )
{
return (struct V_5 * ) V_7 -> V_8 -> V_9 ;
}
static inline struct V_5 * F_9 ( struct V_10 * V_11 )
{
return (struct V_5 * ) V_11 -> V_8 -> V_9 ;
}
static inline struct V_5 * F_10 ( struct V_12 * V_13 )
{
return (struct V_5 * ) V_13 -> V_8 -> V_9 ;
}
static inline enum V_14 F_11 ( T_1 V_15 )
{
enum V_14 V_16 ;
switch ( V_15 ) {
case V_17 :
case V_18 :
V_16 = V_19 ;
break;
case V_20 :
case V_21 :
V_16 = V_22 ;
break;
case V_23 :
V_16 = V_24 ;
break;
case V_25 :
V_16 = V_26 ;
break;
case V_27 :
case V_28 :
V_16 = V_29 ;
break;
case V_30 :
case V_31 :
V_16 = V_32 ;
break;
case V_33 :
V_16 = V_34 ;
break;
default:
V_16 = V_35 ;
break;
}
return V_16 ;
}
static inline T_1 F_12 ( enum V_14 V_16 )
{
switch ( V_16 ) {
case V_19 :
return V_17 ;
case V_22 :
return V_20 ;
case V_24 :
return V_23 ;
case V_26 :
return V_25 ;
case V_29 :
return V_27 ;
case V_32 :
return V_30 ;
case V_34 :
return V_33 ;
case V_36 :
case V_37 :
case V_35 :
default:
return 0 ;
}
}
static T_3 F_13 ( int V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_5 * V_42 = V_41 -> V_9 ;
struct V_6 * V_7 = F_14 ( V_41 , 0 ) ;
if ( V_42 -> V_43 & V_44 )
F_15 ( V_7 ) ;
F_16 ( & V_42 -> V_45 ) ;
if ( V_42 -> V_43 & V_46 )
V_42 -> V_47 |= V_46 ;
if ( V_42 -> V_43 & V_48 )
V_42 -> V_47 |= V_48 ;
F_17 ( & V_42 -> V_45 ) ;
return V_49 ;
}
static T_3 F_18 ( int V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_5 * V_42 = V_41 -> V_9 ;
V_42 -> V_43 = F_1 ( V_42 -> V_50 , V_51 ) ;
F_3 ( V_42 -> V_50 , V_52 , V_42 -> V_43 ) ;
return V_53 ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_54 * V_55 )
{
struct V_5 * V_42 = F_8 ( V_7 ) ;
F_20 ( L_1 ) ;
F_3 ( V_42 -> V_50 , V_56 , V_57 ) ;
F_5 ( V_42 -> V_50 , V_58 , V_59 | V_60 | V_61 ) ;
F_5 ( V_42 -> V_50 , V_62 , V_63 ) ;
F_5 ( V_42 -> V_50 , V_64 , V_65 ) ;
F_21 ( V_7 ) ;
}
static void F_22 ( struct V_6 * V_7 ,
struct V_54 * V_55 )
{
struct V_5 * V_42 = F_8 ( V_7 ) ;
F_20 ( L_1 ) ;
F_23 ( V_7 ) ;
F_6 ( V_42 -> V_50 , V_64 , V_65 ) ;
F_6 ( V_42 -> V_50 , V_58 , V_59 | V_60 | V_61 ) ;
F_5 ( V_42 -> V_50 , V_62 , V_63 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_5 * V_42 = F_8 ( V_7 ) ;
struct V_66 * V_67 = & V_7 -> V_68 -> V_69 ;
struct V_70 V_71 ;
int V_72 = V_67 -> clock * 1000 ;
T_1 V_73 , V_74 , V_75 , V_76 , V_77 , V_78 ;
T_1 V_79 , V_80 ;
T_1 V_3 ;
F_25 ( V_67 , & V_71 ) ;
F_20 ( L_2 , V_7 -> V_1 . V_81 , V_67 -> V_82 ) ;
F_20 ( L_3 , V_71 . V_83 , V_71 . V_84 ) ;
F_20 ( L_4 ,
V_71 . V_85 , V_71 . V_86 , V_71 . V_87 ,
V_71 . V_88 , V_71 . V_89 , V_71 . V_90 ) ;
V_73 = V_71 . V_87 - 1 ;
V_74 = V_71 . V_90 - 1 ;
V_75 = V_73 + V_71 . V_86 ;
V_76 = V_74 + V_71 . V_89 ;
V_77 = V_75 + V_71 . V_83 ;
V_78 = V_76 + V_71 . V_84 ;
V_79 = V_77 + V_71 . V_85 ;
V_80 = V_78 + V_71 . V_88 ;
F_26 ( V_42 -> V_91 ) ;
if ( F_27 ( V_42 -> V_91 , V_72 ) < 0 ) {
F_28 ( L_5 , V_72 ) ;
return;
}
F_29 ( V_42 -> V_91 ) ;
V_3 = 0 ;
if ( V_71 . V_92 & V_93 )
V_3 |= V_94 ;
if ( V_71 . V_92 & V_95 )
V_3 |= V_96 ;
if ( V_71 . V_92 & V_97 )
V_3 |= V_98 ;
if ( V_71 . V_92 & V_99 )
V_3 |= V_100 ;
F_7 ( V_42 -> V_50 , V_64 ,
V_94 | V_96 | V_98 | V_100 , V_3 ) ;
V_3 = ( V_73 << 16 ) | V_74 ;
F_7 ( V_42 -> V_50 , V_101 , V_102 | V_103 , V_3 ) ;
V_3 = ( V_75 << 16 ) | V_76 ;
F_7 ( V_42 -> V_50 , V_104 , V_105 | V_106 , V_3 ) ;
V_3 = ( V_77 << 16 ) | V_78 ;
F_7 ( V_42 -> V_50 , V_107 , V_108 | V_109 , V_3 ) ;
V_3 = ( V_79 << 16 ) | V_80 ;
F_7 ( V_42 -> V_50 , V_110 , V_111 | V_112 , V_3 ) ;
F_3 ( V_42 -> V_50 , V_113 , ( V_78 + 1 ) ) ;
}
static void F_30 ( struct V_6 * V_7 ,
struct V_54 * V_114 )
{
struct V_5 * V_42 = F_8 ( V_7 ) ;
struct V_115 * V_116 = V_7 -> V_68 -> V_116 ;
F_31 ( L_1 ) ;
F_5 ( V_42 -> V_50 , V_62 , V_117 ) ;
if ( V_116 ) {
V_7 -> V_68 -> V_116 = NULL ;
F_32 ( & V_7 -> V_8 -> V_118 ) ;
if ( F_33 ( V_7 ) == 0 )
F_34 ( V_7 , V_116 ) ;
else
F_35 ( V_7 , V_116 ) ;
F_36 ( & V_7 -> V_8 -> V_118 ) ;
}
}
int F_37 ( struct V_40 * V_41 , unsigned int V_119 )
{
struct V_5 * V_42 = V_41 -> V_9 ;
F_20 ( L_1 ) ;
F_5 ( V_42 -> V_50 , V_58 , V_120 ) ;
return 0 ;
}
void F_38 ( struct V_40 * V_41 , unsigned int V_119 )
{
struct V_5 * V_42 = V_41 -> V_9 ;
F_20 ( L_1 ) ;
F_6 ( V_42 -> V_50 , V_58 , V_120 ) ;
}
static int F_39 ( struct V_10 * V_11 ,
struct V_121 * V_68 )
{
struct V_122 * V_123 = V_68 -> V_123 ;
T_1 V_124 , V_125 , V_126 , V_127 ;
F_20 ( L_1 ) ;
if ( ! V_123 )
return 0 ;
V_124 = V_68 -> V_124 >> 16 ;
V_125 = V_68 -> V_125 >> 16 ;
V_126 = V_68 -> V_126 >> 16 ;
V_127 = V_68 -> V_127 >> 16 ;
if ( ( V_126 != V_68 -> V_128 ) || ( V_127 != V_68 -> V_129 ) ) {
F_28 ( L_6 ) ;
return - V_130 ;
}
return 0 ;
}
static void F_40 ( struct V_10 * V_11 ,
struct V_121 * V_131 )
{
struct V_5 * V_42 = F_9 ( V_11 ) ;
struct V_121 * V_68 = V_11 -> V_68 ;
struct V_122 * V_123 = V_68 -> V_123 ;
T_1 V_132 = V_11 -> V_133 * V_134 ;
T_1 V_135 = V_68 -> V_136 ;
T_1 V_137 = V_68 -> V_136 + V_68 -> V_128 - 1 ;
T_1 y0 = V_68 -> V_138 ;
T_1 y1 = V_68 -> V_138 + V_68 -> V_129 - 1 ;
T_1 V_124 , V_125 , V_126 , V_127 ;
T_1 V_3 , V_139 , V_140 , V_141 , V_142 , V_143 , V_144 ;
enum V_14 V_16 ;
if ( ! V_68 -> V_7 || ! V_123 ) {
F_20 ( L_7 ) ;
return;
}
V_124 = V_68 -> V_124 >> 16 ;
V_125 = V_68 -> V_125 >> 16 ;
V_126 = V_68 -> V_126 >> 16 ;
V_127 = V_68 -> V_127 >> 16 ;
F_20 ( L_8 ,
V_11 -> V_1 . V_81 , V_123 -> V_1 . V_81 ,
V_126 , V_127 , V_124 , V_125 ,
V_68 -> V_128 , V_68 -> V_129 ,
V_68 -> V_136 , V_68 -> V_138 ) ;
V_144 = F_1 ( V_42 -> V_50 , V_104 ) ;
V_142 = ( V_144 & V_106 ) >> 16 ;
V_143 = V_144 & V_105 ;
V_3 = ( ( V_137 + 1 + V_142 ) << 16 ) + ( V_135 + 1 + V_142 ) ;
F_7 ( V_42 -> V_50 , V_145 + V_132 ,
V_146 | V_147 , V_3 ) ;
V_3 = ( ( y1 + 1 + V_143 ) << 16 ) + ( y0 + 1 + V_143 ) ;
F_7 ( V_42 -> V_50 , V_148 + V_132 ,
V_149 | V_150 , V_3 ) ;
V_16 = F_11 ( V_123 -> V_151 -> V_151 ) ;
for ( V_3 = 0 ; V_3 < V_152 ; V_3 ++ )
if ( V_42 -> V_153 . V_154 [ V_3 ] == V_16 )
break;
if ( V_3 == V_152 ) {
F_28 ( L_9 ,
( char * ) & V_123 -> V_151 -> V_151 ) ;
V_3 = 0 ;
}
F_7 ( V_42 -> V_50 , V_155 + V_132 , V_156 , V_3 ) ;
V_139 = V_123 -> V_157 [ 0 ] ;
V_140 = F_41 ( V_123 -> V_151 -> V_151 , 0 ) *
( V_137 - V_135 + 1 ) + ( V_42 -> V_153 . V_158 >> 3 ) - 1 ;
V_3 = ( ( V_139 << 16 ) | V_140 ) ;
F_7 ( V_42 -> V_50 , V_159 + V_132 ,
V_160 | V_161 , V_3 ) ;
V_3 = V_162 ;
F_7 ( V_42 -> V_50 , V_163 + V_132 , V_164 , V_3 ) ;
V_3 = V_165 | V_166 ;
F_7 ( V_42 -> V_50 , V_167 + V_132 ,
V_168 | V_169 , V_3 ) ;
V_3 = y1 - y0 + 1 ;
F_7 ( V_42 -> V_50 , V_170 + V_132 , V_171 , V_3 ) ;
V_141 = ( T_1 ) F_42 ( V_123 , V_68 , 0 ) ;
F_20 ( L_10 , V_141 ) ;
F_3 ( V_42 -> V_50 , V_172 + V_132 , V_141 ) ;
V_3 = V_123 -> V_151 -> V_151 == V_33 ? V_173 : 0 ;
V_3 |= V_174 ;
F_7 ( V_42 -> V_50 , V_175 + V_132 ,
V_174 | V_173 , V_3 ) ;
F_16 ( & V_42 -> V_45 ) ;
if ( V_42 -> V_47 & V_46 ) {
F_20 ( L_11 ) ;
V_42 -> V_47 &= ~ V_46 ;
}
if ( V_42 -> V_47 & V_48 ) {
F_20 ( L_12 ) ;
V_42 -> V_47 &= ~ V_48 ;
}
F_17 ( & V_42 -> V_45 ) ;
}
static void F_43 ( struct V_10 * V_11 ,
struct V_121 * V_131 )
{
struct V_5 * V_42 = F_9 ( V_11 ) ;
T_1 V_132 = V_11 -> V_133 * V_134 ;
F_6 ( V_42 -> V_50 , V_175 + V_132 , V_174 ) ;
F_20 ( L_13 ,
V_131 -> V_7 -> V_1 . V_81 , V_11 -> V_1 . V_81 ) ;
}
static struct V_10 * F_44 ( struct V_40 * V_41 ,
enum V_176 type )
{
unsigned long V_177 = V_178 ;
struct V_5 * V_42 = V_41 -> V_9 ;
struct V_179 * V_8 = V_41 -> V_8 ;
struct V_10 * V_11 ;
unsigned int V_180 , V_181 = 0 ;
T_1 V_182 [ V_152 ] ;
T_1 V_15 ;
int V_183 ;
for ( V_180 = 0 ; V_180 < V_152 ; V_180 ++ ) {
V_15 = F_12 ( V_42 -> V_153 . V_154 [ V_180 ] ) ;
if ( ! V_15 )
continue;
V_182 [ V_181 ++ ] = V_15 ;
}
V_11 = F_45 ( V_8 , sizeof( * V_11 ) , V_184 ) ;
if ( ! V_11 )
return 0 ;
V_183 = F_46 ( V_41 , V_11 , V_177 ,
& V_185 , V_182 , V_181 ,
NULL , type , NULL ) ;
if ( V_183 < 0 )
return 0 ;
F_47 ( V_11 , & V_186 ) ;
F_20 ( L_14 , V_11 -> V_1 . V_81 ) ;
return V_11 ;
}
static void F_48 ( struct V_40 * V_41 )
{
struct V_10 * V_11 , * V_187 ;
F_49 (plane, plane_temp,
&ddev->mode_config.plane_list, head)
F_50 ( V_11 ) ;
}
static int F_51 ( struct V_40 * V_41 , struct V_6 * V_7 )
{
struct V_5 * V_42 = V_41 -> V_9 ;
struct V_10 * V_188 , * V_189 ;
unsigned int V_180 ;
int V_183 ;
V_188 = F_44 ( V_41 , V_190 ) ;
if ( ! V_188 ) {
F_28 ( L_15 ) ;
return - V_130 ;
}
V_183 = F_52 ( V_41 , V_7 , V_188 , NULL ,
& V_191 , NULL ) ;
if ( V_183 ) {
F_28 ( L_16 ) ;
goto V_192;
}
F_53 ( V_7 , & V_193 ) ;
F_20 ( L_17 , V_7 -> V_1 . V_81 ) ;
for ( V_180 = 1 ; V_180 < V_42 -> V_153 . V_194 ; V_180 ++ ) {
V_189 = F_44 ( V_41 , V_195 ) ;
if ( ! V_189 ) {
V_183 = - V_196 ;
F_28 ( L_18 , V_180 ) ;
goto V_192;
}
}
return 0 ;
V_192:
F_48 ( V_41 ) ;
return V_183 ;
}
static int F_54 ( struct V_40 * V_41 )
{
struct V_5 * V_42 = V_41 -> V_9 ;
struct V_12 * V_197 ;
int V_183 ;
V_197 = F_45 ( V_41 -> V_8 , sizeof( * V_197 ) , V_184 ) ;
if ( ! V_197 )
return - V_196 ;
V_197 -> V_177 = V_178 ;
V_197 -> V_198 = 0 ;
F_55 ( V_41 , V_197 , & V_199 ,
V_200 , NULL ) ;
V_183 = F_56 ( V_197 , V_42 -> V_201 , NULL ) ;
if ( V_183 ) {
F_57 ( V_197 ) ;
return - V_130 ;
}
F_20 ( L_19 , V_197 -> V_1 . V_81 ) ;
return 0 ;
}
static int F_58 ( struct V_40 * V_41 )
{
struct V_5 * V_42 = V_41 -> V_9 ;
T_1 V_202 , V_203 , V_204 ;
V_203 = F_1 ( V_42 -> V_50 , V_205 ) ;
V_42 -> V_153 . V_194 = F_59 ( int , V_203 , 1 ) ;
V_204 = F_1 ( V_42 -> V_50 , V_206 ) ;
V_202 = ( V_204 & V_207 ) >> 4 ;
V_42 -> V_153 . V_158 = 8 << V_202 ;
V_42 -> V_153 . V_208 = F_1 ( V_42 -> V_50 , V_209 ) ;
switch ( V_42 -> V_153 . V_208 ) {
case V_210 :
case V_211 :
V_42 -> V_153 . V_212 = V_213 ;
V_42 -> V_153 . V_154 = V_214 ;
break;
case V_215 :
V_42 -> V_153 . V_212 = V_216 ;
V_42 -> V_153 . V_154 = V_217 ;
break;
default:
return - V_218 ;
}
return 0 ;
}
int F_60 ( struct V_40 * V_41 )
{
struct V_219 * V_220 = F_61 ( V_41 -> V_8 ) ;
struct V_5 * V_42 = V_41 -> V_9 ;
struct V_179 * V_8 = V_41 -> V_8 ;
struct V_221 * V_222 = V_8 -> V_223 ;
struct V_224 * V_201 ;
struct V_225 * V_226 ;
struct V_6 * V_7 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
int V_38 , V_183 , V_180 ;
F_20 ( L_1 ) ;
V_183 = F_62 ( V_222 , 0 , 0 , & V_226 , & V_201 ) ;
if ( V_183 )
return V_183 ;
V_228 = F_63 ( V_8 , NULL ) ;
F_64 ( & V_42 -> V_45 ) ;
V_42 -> V_91 = F_65 ( V_8 , L_20 ) ;
if ( F_66 ( V_42 -> V_91 ) ) {
F_28 ( L_21 ) ;
return - V_218 ;
}
if ( F_67 ( V_42 -> V_91 ) ) {
F_28 ( L_22 ) ;
return - V_218 ;
}
V_230 = F_68 ( V_220 , V_231 , 0 ) ;
if ( ! V_230 ) {
F_28 ( L_23 ) ;
V_183 = - V_218 ;
goto V_232;
}
V_42 -> V_50 = F_69 ( V_8 , V_230 ) ;
if ( F_66 ( V_42 -> V_50 ) ) {
F_28 ( L_24 ) ;
V_183 = F_70 ( V_42 -> V_50 ) ;
goto V_232;
}
for ( V_180 = 0 ; V_180 < V_233 ; V_180 ++ ) {
V_38 = F_71 ( V_220 , V_180 ) ;
if ( V_38 < 0 )
continue;
V_183 = F_72 ( V_8 , V_38 , F_18 ,
F_13 , V_234 ,
F_73 ( V_8 ) , V_41 ) ;
if ( V_183 ) {
F_28 ( L_25 ) ;
goto V_232;
}
}
if ( ! F_66 ( V_228 ) )
F_74 ( V_228 ) ;
F_6 ( V_42 -> V_50 , V_58 ,
V_120 | V_59 | V_60 | V_61 ) ;
V_183 = F_58 ( V_41 ) ;
if ( V_183 ) {
F_28 ( L_26 ,
V_42 -> V_153 . V_208 ) ;
goto V_232;
}
F_75 ( L_27 , V_42 -> V_153 . V_208 ) ;
if ( V_226 ) {
V_201 = F_76 ( V_226 , V_235 ) ;
if ( F_66 ( V_201 ) ) {
F_28 ( L_28 ) ;
V_183 = F_70 ( V_201 ) ;
goto V_232;
}
V_42 -> V_236 = true ;
}
V_42 -> V_201 = V_201 ;
V_183 = F_54 ( V_41 ) ;
if ( V_183 ) {
F_28 ( L_29 ) ;
goto V_232;
}
V_7 = F_45 ( V_8 , sizeof( * V_7 ) , V_184 ) ;
if ( ! V_7 ) {
F_28 ( L_30 ) ;
V_183 = - V_196 ;
goto V_232;
}
V_183 = F_51 ( V_41 , V_7 ) ;
if ( V_183 ) {
F_28 ( L_31 ) ;
goto V_232;
}
V_183 = F_77 ( V_41 , V_237 ) ;
if ( V_183 ) {
F_28 ( L_32 ) ;
goto V_232;
}
V_41 -> V_238 = 1 ;
return 0 ;
V_232:
if ( V_42 -> V_236 )
F_78 ( V_201 ) ;
F_79 ( V_42 -> V_91 ) ;
return V_183 ;
}
void F_80 ( struct V_40 * V_41 )
{
struct V_5 * V_42 = V_41 -> V_9 ;
F_20 ( L_1 ) ;
if ( V_42 -> V_236 )
F_78 ( V_42 -> V_201 ) ;
F_79 ( V_42 -> V_91 ) ;
}
