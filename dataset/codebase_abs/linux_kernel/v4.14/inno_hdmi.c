static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 ) * 0x04 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_3 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + ( V_3 ) * 0x04 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_3 ,
T_3 V_6 , T_3 V_5 )
{
T_1 V_7 = F_1 ( V_2 , V_3 ) & ~ V_6 ;
V_7 |= V_5 & V_6 ;
F_3 ( V_2 , V_3 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = ( V_2 -> V_9 >> 2 ) / V_10 ;
F_3 ( V_2 , V_11 , V_8 & 0xFF ) ;
F_3 ( V_2 , V_12 , ( V_8 >> 8 ) & 0xFF ) ;
F_3 ( V_2 , V_13 , 0 ) ;
F_3 ( V_2 , V_14 , V_15 ) ;
}
static void F_7 ( struct V_1 * V_2 , bool V_16 )
{
if ( V_16 )
F_5 ( V_2 , V_17 , V_18 , V_19 ) ;
else
F_5 ( V_2 , V_17 , V_18 , V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_21 )
{
switch ( V_21 ) {
case V_22 :
F_7 ( V_2 , false ) ;
F_3 ( V_2 , V_23 , 0x6f ) ;
F_3 ( V_2 , V_24 , 0xbb ) ;
F_3 ( V_2 , V_25 , 0x15 ) ;
F_3 ( V_2 , V_25 , 0x14 ) ;
F_3 ( V_2 , V_25 , 0x10 ) ;
F_3 ( V_2 , V_26 , 0x0f ) ;
F_3 ( V_2 , V_27 , 0x00 ) ;
F_3 ( V_2 , V_27 , 0x01 ) ;
F_7 ( V_2 , true ) ;
break;
case V_28 :
F_7 ( V_2 , false ) ;
F_3 ( V_2 , V_24 , 0x00 ) ;
F_3 ( V_2 , V_23 , 0x00 ) ;
F_3 ( V_2 , V_26 , 0x00 ) ;
F_3 ( V_2 , V_25 , 0x15 ) ;
break;
default:
F_9 ( V_2 -> V_29 , L_1 , V_21 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
T_3 V_5 ;
T_3 V_6 ;
F_5 ( V_2 , V_17 , V_30 , V_31 ) ;
F_11 ( 100 ) ;
F_5 ( V_2 , V_17 , V_32 , V_33 ) ;
F_11 ( 100 ) ;
V_6 = V_34 | V_35 | V_18 | V_36 ;
V_5 = V_37 | V_38 | V_19 | V_39 ;
F_5 ( V_2 , V_17 , V_6 , V_5 ) ;
F_8 ( V_2 , V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_40 ,
union V_41 * V_42 , T_3 V_43 ,
T_3 V_44 , T_3 V_45 , T_3 V_16 )
{
if ( V_44 )
F_5 ( V_2 , V_46 , V_44 , V_45 ) ;
F_3 ( V_2 , V_47 , V_43 ) ;
if ( V_40 >= 0 ) {
T_1 V_48 [ V_49 ] ;
T_4 V_50 , V_51 ;
V_50 = F_13 ( V_42 , V_48 ,
sizeof( V_48 ) ) ;
if ( V_50 < 0 )
return V_50 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
F_3 ( V_2 , V_52 + V_51 ,
V_48 [ V_51 ] ) ;
if ( V_44 )
F_5 ( V_2 , V_46 , V_44 , V_16 ) ;
}
return V_40 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_53 * V_21 )
{
union V_41 V_42 ;
int V_50 ;
V_50 = F_15 ( & V_42 . V_54 . V_2 ,
V_21 ) ;
return F_12 ( V_2 , V_50 , & V_42 , V_55 ,
V_56 , F_16 ( 0 ) , F_16 ( 1 ) ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_53 * V_21 )
{
union V_41 V_42 ;
int V_50 ;
V_50 = F_18 ( & V_42 . V_57 , V_21 , false ) ;
if ( V_2 -> V_58 . V_59 == V_60 )
V_42 . V_57 . V_61 = V_60 ;
else if ( V_2 -> V_58 . V_59 == V_62 )
V_42 . V_57 . V_61 = V_62 ;
else
V_42 . V_57 . V_61 = V_63 ;
return F_12 ( V_2 , V_50 , & V_42 , V_64 , 0 , 0 , 0 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = & V_2 -> V_58 ;
int V_67 = 0 ;
int V_68 = 0 ;
int V_69 = 0 ;
int V_70 = 0 ;
int V_71 ;
int V_51 ;
F_3 ( V_2 , V_72 , V_73 |
F_20 ( V_74 ) ) ;
V_71 = F_21 ( V_75 ) |
F_22 ( 0 ) |
F_23 ( 0 ) ;
F_3 ( V_2 , V_76 , V_71 ) ;
if ( V_66 -> V_77 == V_66 -> V_59 ) {
if ( ( V_66 -> V_77 == V_63 ) ||
( V_66 -> V_77 >= V_60 ) ) {
V_71 = V_78 | F_24 ( 1 ) ;
F_3 ( V_2 , V_79 , V_71 ) ;
F_5 ( V_2 , V_80 ,
V_81 | V_82 ,
F_25 ( V_83 ) |
F_26 ( V_84 ) ) ;
return 0 ;
}
}
if ( V_66 -> V_85 == V_86 ) {
if ( ( V_66 -> V_77 == V_63 ) &&
( V_66 -> V_59 == V_60 ) ) {
V_69 = V_87 ;
V_70 = V_83 ;
V_67 = V_84 ;
V_68 = V_88 ;
} else if ( ( V_66 -> V_77 == V_60 ) &&
( V_66 -> V_59 == V_63 ) ) {
V_69 = V_89 ;
V_70 = V_90 ;
V_67 = V_84 ;
V_68 = V_91 ;
}
} else {
if ( ( V_66 -> V_77 == V_63 ) &&
( V_66 -> V_59 == V_60 ) ) {
V_69 = V_92 ;
V_70 = V_83 ;
V_67 = V_84 ;
V_68 = V_88 ;
} else if ( ( V_66 -> V_77 == V_60 ) &&
( V_66 -> V_59 == V_63 ) ) {
V_69 = V_93 ;
V_70 = V_90 ;
V_67 = V_84 ;
V_68 = V_91 ;
}
}
for ( V_51 = 0 ; V_51 < 24 ; V_51 ++ )
F_3 ( V_2 , V_94 + V_51 ,
V_95 [ V_69 ] [ V_51 ] ) ;
V_71 = V_78 | V_68 | F_24 ( 1 ) ;
F_3 ( V_2 , V_79 , V_71 ) ;
F_5 ( V_2 , V_80 , V_81 |
V_82 , F_25 ( V_70 ) |
F_26 ( V_67 ) ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_53 * V_21 )
{
int V_71 ;
V_71 = F_28 ( 1 ) ;
V_71 |= V_21 -> V_96 & V_97 ?
F_29 ( 1 ) : F_29 ( 0 ) ;
V_71 |= V_21 -> V_96 & V_98 ?
F_30 ( 1 ) : F_30 ( 0 ) ;
V_71 |= V_21 -> V_96 & V_99 ?
F_31 ( 1 ) : F_31 ( 0 ) ;
F_3 ( V_2 , V_100 , V_71 ) ;
V_71 = V_21 -> V_101 ;
F_3 ( V_2 , V_102 , V_71 & 0xFF ) ;
F_3 ( V_2 , V_103 , ( V_71 >> 8 ) & 0xFF ) ;
V_71 = V_21 -> V_101 - V_21 -> V_104 ;
F_3 ( V_2 , V_105 , V_71 & 0xFF ) ;
F_3 ( V_2 , V_106 , ( V_71 >> 8 ) & 0xFF ) ;
V_71 = V_21 -> V_107 - V_21 -> V_104 ;
F_3 ( V_2 , V_108 , V_71 & 0xFF ) ;
F_3 ( V_2 , V_109 , ( V_71 >> 8 ) & 0xFF ) ;
V_71 = V_21 -> V_110 - V_21 -> V_107 ;
F_3 ( V_2 , V_111 , V_71 & 0xFF ) ;
F_3 ( V_2 , V_112 , ( V_71 >> 8 ) & 0xFF ) ;
V_71 = V_21 -> V_113 ;
F_3 ( V_2 , V_114 , V_71 & 0xFF ) ;
F_3 ( V_2 , V_115 , ( V_71 >> 8 ) & 0xFF ) ;
V_71 = V_21 -> V_113 - V_21 -> V_116 ;
F_3 ( V_2 , V_117 , V_71 & 0xFF ) ;
V_71 = V_21 -> V_118 - V_21 -> V_116 ;
F_3 ( V_2 , V_119 , V_71 & 0xFF ) ;
V_71 = V_21 -> V_120 - V_21 -> V_118 ;
F_3 ( V_2 , V_121 , V_71 & 0xFF ) ;
F_3 ( V_2 , V_122 , 0x1e ) ;
F_3 ( V_2 , V_123 , 0x2c ) ;
F_3 ( V_2 , V_124 , 0x01 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_53 * V_21 )
{
V_2 -> V_58 . V_125 = F_33 ( V_21 ) ;
V_2 -> V_58 . V_77 = V_63 ;
V_2 -> V_58 . V_59 = V_63 ;
if ( ( V_2 -> V_58 . V_125 == 6 ) || ( V_2 -> V_58 . V_125 == 7 ) ||
( V_2 -> V_58 . V_125 == 21 ) || ( V_2 -> V_58 . V_125 == 22 ) ||
( V_2 -> V_58 . V_125 == 2 ) || ( V_2 -> V_58 . V_125 == 3 ) ||
( V_2 -> V_58 . V_125 == 17 ) || ( V_2 -> V_58 . V_125 == 18 ) )
V_2 -> V_58 . V_85 = V_86 ;
else
V_2 -> V_58 . V_85 = V_126 ;
F_5 ( V_2 , V_127 , V_128 | V_129 ,
F_34 ( 1 ) | F_35 ( 1 ) ) ;
F_3 ( V_2 , V_130 ,
F_36 ( V_2 -> V_58 . V_131 ) ) ;
F_27 ( V_2 , V_21 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_58 . V_131 ) {
F_17 ( V_2 , V_21 ) ;
F_14 ( V_2 , V_21 ) ;
}
V_2 -> V_9 = V_21 -> clock * 1000 ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_127 , V_128 | V_129 ,
F_34 ( 0 ) | F_35 ( 0 ) ) ;
return 0 ;
}
static void F_37 ( struct V_132 * V_133 ,
struct V_53 * V_21 ,
struct V_53 * V_134 )
{
struct V_1 * V_2 = F_38 ( V_133 ) ;
F_32 ( V_2 , V_134 ) ;
memcpy ( & V_2 -> V_135 , V_134 , sizeof( V_2 -> V_135 ) ) ;
}
static void F_39 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_38 ( V_133 ) ;
F_8 ( V_2 , V_22 ) ;
}
static void F_40 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_38 ( V_133 ) ;
F_8 ( V_2 , V_28 ) ;
}
static bool F_41 ( struct V_132 * V_133 ,
const struct V_53 * V_21 ,
struct V_53 * V_134 )
{
return true ;
}
static int
F_42 ( struct V_132 * V_133 ,
struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 = F_43 ( V_137 ) ;
V_141 -> V_142 = V_143 ;
V_141 -> V_144 = V_145 ;
return 0 ;
}
static enum V_146
F_44 ( struct V_147 * V_148 , bool V_149 )
{
struct V_1 * V_2 = F_38 ( V_148 ) ;
return ( F_1 ( V_2 , V_150 ) & V_151 ) ?
V_152 : V_153 ;
}
static int F_45 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_38 ( V_148 ) ;
struct V_154 * V_154 ;
int V_155 = 0 ;
if ( ! V_2 -> V_156 )
return 0 ;
V_154 = F_46 ( V_148 , V_2 -> V_156 ) ;
if ( V_154 ) {
V_2 -> V_58 . V_131 = F_47 ( V_154 ) ;
V_2 -> V_58 . V_157 = F_48 ( V_154 ) ;
F_49 ( V_148 , V_154 ) ;
V_155 = F_50 ( V_148 , V_154 ) ;
F_51 ( V_154 ) ;
}
return V_155 ;
}
static enum V_158
F_52 ( struct V_147 * V_148 ,
struct V_53 * V_21 )
{
return V_159 ;
}
static int
F_53 ( struct V_147 * V_148 ,
T_5 V_160 , T_5 V_161 )
{
return F_54 ( V_148 , 1920 , 1080 ) ;
}
static void F_55 ( struct V_147 * V_148 )
{
F_56 ( V_148 ) ;
F_57 ( V_148 ) ;
}
static int F_58 ( struct V_162 * V_163 , struct V_1 * V_2 )
{
struct V_132 * V_133 = & V_2 -> V_133 ;
struct V_164 * V_29 = V_2 -> V_29 ;
V_133 -> V_165 = F_59 ( V_163 , V_29 -> V_166 ) ;
if ( V_133 -> V_165 == 0 )
return - V_167 ;
F_60 ( V_133 , & V_168 ) ;
F_61 ( V_163 , V_133 , & V_169 ,
V_170 , NULL ) ;
V_2 -> V_148 . V_171 = V_172 ;
F_62 ( & V_2 -> V_148 ,
& V_173 ) ;
F_63 ( V_163 , & V_2 -> V_148 , & V_174 ,
V_145 ) ;
F_64 ( & V_2 -> V_148 , V_133 ) ;
return 0 ;
}
static T_6 F_65 ( struct V_1 * V_2 )
{
struct V_175 * V_176 = V_2 -> V_176 ;
T_1 V_177 ;
V_177 = F_1 ( V_2 , V_14 ) ;
if ( ! ( V_177 & V_15 ) )
return V_178 ;
F_3 ( V_2 , V_14 , V_15 ) ;
F_66 ( & V_176 -> V_179 ) ;
return V_180 ;
}
static T_6 F_67 ( int V_181 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
T_6 V_155 = V_178 ;
T_1 V_183 ;
if ( V_2 -> V_176 )
V_155 = F_65 ( V_2 ) ;
V_183 = F_1 ( V_2 , V_150 ) ;
if ( V_183 & V_184 ) {
F_5 ( V_2 , V_150 , V_184 , V_184 ) ;
V_155 = V_185 ;
}
return V_155 ;
}
static T_6 F_68 ( int V_181 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
F_69 ( V_2 -> V_148 . V_29 ) ;
return V_180 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_186 * V_187 )
{
int V_188 = V_187 -> V_189 ;
T_1 * V_190 = V_187 -> V_190 ;
int V_155 ;
V_155 = F_71 ( & V_2 -> V_176 -> V_179 , V_191 / 10 ) ;
if ( ! V_155 )
return - V_192 ;
while ( V_188 -- )
* V_190 ++ = F_1 ( V_2 , V_193 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_186 * V_187 )
{
if ( ( V_187 -> V_189 != 1 ) ||
( ( V_187 -> V_194 != V_195 ) && ( V_187 -> V_194 != V_196 ) ) )
return - V_197 ;
F_73 ( & V_2 -> V_176 -> V_179 ) ;
if ( V_187 -> V_194 == V_196 )
V_2 -> V_176 -> V_198 = V_187 -> V_190 [ 0 ] ;
if ( V_187 -> V_194 == V_195 )
V_2 -> V_176 -> V_199 = V_187 -> V_190 [ 0 ] ;
F_3 ( V_2 , V_200 , 0x00 ) ;
F_3 ( V_2 , V_201 , V_2 -> V_176 -> V_199 ) ;
F_3 ( V_2 , V_202 , V_2 -> V_176 -> V_198 ) ;
return 0 ;
}
static int F_74 ( struct V_203 * V_204 ,
struct V_186 * V_187 , int V_205 )
{
struct V_1 * V_2 = F_75 ( V_204 ) ;
struct V_175 * V_176 = V_2 -> V_176 ;
int V_51 , V_155 = 0 ;
F_76 ( & V_176 -> V_206 ) ;
F_3 ( V_2 , V_13 , V_15 ) ;
F_3 ( V_2 , V_14 , V_15 ) ;
for ( V_51 = 0 ; V_51 < V_205 ; V_51 ++ ) {
F_77 ( V_2 -> V_29 , L_2 ,
V_51 + 1 , V_205 , V_187 [ V_51 ] . V_189 , V_187 [ V_51 ] . V_96 ) ;
if ( V_187 [ V_51 ] . V_96 & V_207 )
V_155 = F_70 ( V_2 , & V_187 [ V_51 ] ) ;
else
V_155 = F_72 ( V_2 , & V_187 [ V_51 ] ) ;
if ( V_155 < 0 )
break;
}
if ( ! V_155 )
V_155 = V_205 ;
F_3 ( V_2 , V_13 , 0 ) ;
F_78 ( & V_176 -> V_206 ) ;
return V_155 ;
}
static T_3 F_79 ( struct V_203 * V_208 )
{
return V_209 | V_210 ;
}
static struct V_203 * F_80 ( struct V_1 * V_2 )
{
struct V_203 * V_204 ;
struct V_175 * V_176 ;
int V_155 ;
V_176 = F_81 ( V_2 -> V_29 , sizeof( * V_176 ) , V_211 ) ;
if ( ! V_176 )
return F_82 ( - V_212 ) ;
F_83 ( & V_176 -> V_206 ) ;
F_84 ( & V_176 -> V_179 ) ;
V_204 = & V_176 -> V_204 ;
V_204 -> V_213 = V_214 ;
V_204 -> V_215 = V_216 ;
V_204 -> V_29 . V_217 = V_2 -> V_29 ;
V_204 -> V_29 . V_166 = V_2 -> V_29 -> V_166 ;
V_204 -> V_218 = & V_219 ;
F_85 ( V_204 -> V_220 , L_3 , sizeof( V_204 -> V_220 ) ) ;
F_86 ( V_204 , V_2 ) ;
V_155 = F_87 ( V_204 ) ;
if ( V_155 ) {
F_88 ( V_2 -> V_29 , L_4 , V_204 -> V_220 ) ;
F_89 ( V_2 -> V_29 , V_176 ) ;
return F_82 ( V_155 ) ;
}
V_2 -> V_176 = V_176 ;
F_90 ( V_2 -> V_29 , L_5 , V_204 -> V_220 ) ;
return V_204 ;
}
static int F_91 ( struct V_164 * V_29 , struct V_164 * V_221 ,
void * V_66 )
{
struct V_222 * V_223 = F_92 ( V_29 ) ;
struct V_162 * V_163 = V_66 ;
struct V_1 * V_2 ;
struct V_224 * V_225 ;
int V_181 ;
int V_155 ;
V_2 = F_81 ( V_29 , sizeof( * V_2 ) , V_211 ) ;
if ( ! V_2 )
return - V_212 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_226 = V_163 ;
V_225 = F_93 ( V_223 , V_227 , 0 ) ;
if ( ! V_225 )
return - V_228 ;
V_2 -> V_4 = F_94 ( V_29 , V_225 ) ;
if ( F_95 ( V_2 -> V_4 ) )
return F_96 ( V_2 -> V_4 ) ;
V_2 -> V_229 = F_97 ( V_2 -> V_29 , L_6 ) ;
if ( F_95 ( V_2 -> V_229 ) ) {
F_9 ( V_2 -> V_29 , L_7 ) ;
return F_96 ( V_2 -> V_229 ) ;
}
V_155 = F_98 ( V_2 -> V_229 ) ;
if ( V_155 ) {
F_9 ( V_2 -> V_29 , L_8 , V_155 ) ;
return V_155 ;
}
V_181 = F_99 ( V_223 , 0 ) ;
if ( V_181 < 0 )
return V_181 ;
F_10 ( V_2 ) ;
V_2 -> V_156 = F_80 ( V_2 ) ;
if ( F_95 ( V_2 -> V_156 ) ) {
V_155 = F_96 ( V_2 -> V_156 ) ;
V_2 -> V_156 = NULL ;
return V_155 ;
}
V_2 -> V_9 = F_100 ( V_2 -> V_229 ) ;
F_6 ( V_2 ) ;
V_155 = F_58 ( V_163 , V_2 ) ;
if ( V_155 )
return V_155 ;
F_101 ( V_29 , V_2 ) ;
F_5 ( V_2 , V_150 , V_230 , F_102 ( 1 ) ) ;
V_155 = F_103 ( V_29 , V_181 , F_67 ,
F_68 , V_231 ,
F_104 ( V_29 ) , V_2 ) ;
return V_155 ;
}
static void F_105 ( struct V_164 * V_29 , struct V_164 * V_221 ,
void * V_66 )
{
struct V_1 * V_2 = F_106 ( V_29 ) ;
V_2 -> V_148 . V_232 -> V_233 ( & V_2 -> V_148 ) ;
V_2 -> V_133 . V_232 -> V_233 ( & V_2 -> V_133 ) ;
F_107 ( V_2 -> V_229 ) ;
F_108 ( V_2 -> V_156 ) ;
}
static int F_109 ( struct V_222 * V_223 )
{
return F_110 ( & V_223 -> V_29 , & V_234 ) ;
}
static int F_111 ( struct V_222 * V_223 )
{
F_112 ( & V_223 -> V_29 , & V_234 ) ;
return 0 ;
}
