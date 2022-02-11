static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 )
F_2 ( V_3 ,
V_5 ,
V_6 ,
V_7 ,
V_2 -> V_4 - 1 ) ;
else
F_2 ( V_3 ,
V_5 ,
V_8 ,
V_7 , 0 ) ;
F_3 ( V_2 -> V_9 , & V_3 , V_10 ,
V_2 -> V_2 ) ;
}
static int F_4 ( struct V_11 * V_12 ,
int V_13 , int V_14 , T_2 V_15 , T_2 V_16 )
{
struct V_17 * V_9 = F_5 ( V_12 ) ;
T_3 V_18 ;
int V_19 ;
V_19 = F_6 ( V_9 , V_9 -> V_20 , V_13 , V_14 ,
V_15 , V_16 , & V_18 ) ;
if ( V_19 )
return V_19 ;
if ( V_18 != V_21 )
return - V_22 ;
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
int V_13 , int V_14 , T_2 V_15 )
{
struct V_17 * V_9 = F_5 ( V_12 ) ;
T_4 V_16 ;
T_3 V_18 ;
int V_19 ;
V_19 = F_8 ( V_9 , V_9 -> V_20 , V_13 , V_14 ,
V_15 , & V_16 , & V_18 ) ;
if ( V_19 )
return V_19 ;
if ( V_18 != V_21 )
return - V_22 ;
return ( int ) V_16 ;
}
static int F_9 ( struct V_17 * V_9 )
{
int V_19 ;
V_9 -> V_23 = & V_24 ;
V_9 -> V_25 . V_26 = V_27 | V_28 ;
V_9 -> V_25 . V_29 = F_7 ;
V_9 -> V_25 . V_30 = F_4 ;
V_19 = V_9 -> V_23 -> V_31 ( V_9 ) ;
if ( V_19 != 0 )
return V_19 ;
V_19 = F_10 ( V_9 , & V_9 -> V_32 ,
V_33 * sizeof( V_34 ) ) ;
if ( V_19 )
return V_19 ;
F_11 ( V_9 , V_31 , V_9 -> V_12 ,
L_1 ,
( V_34 ) V_9 -> V_32 . V_35 ,
V_9 -> V_32 . V_15 ,
( V_34 ) F_12 ( V_9 -> V_32 . V_15 ) ) ;
F_13 ( V_9 , V_9 -> V_32 . V_35 , 0 , 0 , 1 ) ;
return 0 ;
}
static void F_14 ( struct V_17 * V_9 )
{
V_9 -> V_23 -> remove ( V_9 ) ;
F_15 ( V_9 , & V_9 -> V_32 ) ;
}
void F_16 ( struct V_17 * V_9 )
{
if ( V_9 -> V_36 ++ == 0 )
F_17 ( V_9 ) ;
}
void F_18 ( struct V_17 * V_9 )
{
if ( -- V_9 -> V_36 == 0 )
F_17 ( V_9 ) ;
}
static int F_19 ( struct V_17 * V_9 , struct V_37 * V_38 )
{
enum V_39 V_40 = V_41 ;
int V_19 , V_42 ;
F_20 ( V_9 , V_40 ) ;
V_19 = F_21 ( V_9 , V_40 ) ;
if ( V_19 )
goto V_43;
V_38 -> V_44 =
F_22 ( V_9 , V_45 ,
F_23 ( V_45 ) )
? - 1 : 1 ;
V_19 = F_21 ( V_9 , V_40 ) ;
V_43:
V_42 = F_24 ( V_9 , V_40 , V_19 == 0 ) ;
return V_19 ? V_19 : V_42 ;
}
static enum V_39 F_25 ( enum V_39 V_46 )
{
return V_47 ;
}
static int F_26 ( T_5 * V_48 )
{
enum {
V_49 = ( V_50 | V_51 |
V_52 | V_53 |
V_54 ) ,
V_55 = ( V_49 |
V_56 << V_57 ) ,
};
if ( ( * V_48 & V_55 ) == V_55 ) {
* V_48 &= ~ V_55 ;
return V_58 ;
}
if ( ( * V_48 & V_49 ) == V_49 ) {
* V_48 &= ~ V_49 ;
return V_41 ;
}
return - V_59 ;
}
static int F_21 ( struct V_17 * V_9 , enum V_39 V_60 )
{
int V_19 ;
V_19 = F_27 ( V_9 ) ;
if ( V_19 )
return V_19 ;
if ( V_60 == V_58 )
return F_28 ( V_9 ) ;
else
return F_29 ( V_9 ) ;
}
static void F_30 ( struct V_17 * V_9 )
{
struct V_61 * V_62 =
F_31 ( F_32 ( V_9 -> V_63 ) ) ;
F_33 ( V_62 ) ;
}
static int F_34 ( struct V_17 * V_9 )
{
T_5 V_64 = 0 ;
int V_19 ;
V_19 = F_35 ( V_9 , V_9 -> V_12 -> V_65 , NULL , & V_64 ) ;
V_9 -> V_66 =
( V_64 & ( 1 << V_67 ) ) ?
3072 : 6144 ;
return V_19 ;
}
static void F_36 ( struct V_17 * V_9 )
{
F_37 ( V_9 , V_68 / 2 ) ;
}
static int F_38 ( struct V_17 * V_9 )
{
struct V_69 * V_70 ;
bool V_71 = false ;
T_6 V_72 ;
int V_19 ;
V_70 = F_39 ( sizeof( struct V_69 ) , V_73 ) ;
if ( ! V_70 )
return - V_74 ;
V_9 -> V_70 = V_70 ;
if ( F_40 ( V_9 ) != 0 ) {
F_41 ( V_9 , V_31 , V_9 -> V_12 ,
L_2 ) ;
V_19 = - V_75 ;
goto V_76;
}
F_42 ( V_9 , & V_72 , V_77 ) ;
V_9 -> V_12 -> V_78 = F_43 ( V_72 , V_79 ) - 1 ;
F_44 ( V_9 ) ;
V_19 = F_27 ( V_9 ) ;
if ( V_19 )
goto V_76;
V_19 = F_45 ( V_9 , true , & V_71 ) ;
if ( V_19 ) {
F_41 ( V_9 , V_31 , V_9 -> V_12 ,
L_3 ) ;
goto V_80;
}
if ( V_71 )
F_41 ( V_9 , V_31 , V_9 -> V_12 ,
L_4 ) ;
V_19 = F_21 ( V_9 , V_41 ) ;
if ( V_19 ) {
F_41 ( V_9 , V_31 , V_9 -> V_12 , L_5 ) ;
goto V_81;
}
F_46 ( V_9 ) ;
V_19 = F_10 ( V_9 , & V_9 -> V_82 , sizeof( T_6 ) ) ;
if ( V_19 )
goto V_83;
F_47 ( V_9 -> V_82 . V_35 & 0x0f ) ;
F_11 ( V_9 , V_31 , V_9 -> V_12 ,
L_6 ,
( unsigned long long ) V_9 -> V_82 . V_35 ,
V_9 -> V_82 . V_15 ,
( unsigned long long ) F_12 ( V_9 -> V_82 . V_15 ) ) ;
V_19 = F_34 ( V_9 ) ;
if ( V_19 == - V_59 ) {
F_41 ( V_9 , V_31 , V_9 -> V_12 ,
L_7 ) ;
V_9 -> V_84 = V_85 ;
V_9 -> V_25 . V_13 = V_86 ;
} else if ( V_19 ) {
goto V_87;
}
V_19 = F_48 ( V_9 ) ;
if ( V_19 )
goto V_87;
F_49 ( V_9 ) ;
F_50 ( V_9 ) ;
return 0 ;
V_87:
F_15 ( V_9 , & V_9 -> V_82 ) ;
V_83:
V_81:
F_45 ( V_9 , false , NULL ) ;
V_80:
V_76:
F_51 ( V_9 -> V_70 ) ;
return V_19 ;
}
static int F_52 ( struct V_17 * V_9 )
{
T_6 V_88 ;
int V_19 ;
V_19 = F_27 ( V_9 ) ;
if ( V_19 )
return V_19 ;
F_42 ( V_9 , & V_88 , V_89 ) ;
F_53 ( V_88 , V_90 , 1 ) ;
F_54 ( V_9 , & V_88 , V_89 ) ;
F_42 ( V_9 , & V_88 , V_91 ) ;
F_53 ( V_88 , V_92 , 0 ) ;
F_53 ( V_88 , V_93 , 1 ) ;
F_54 ( V_9 , & V_88 , V_91 ) ;
F_42 ( V_9 , & V_88 , V_94 ) ;
F_53 ( V_88 , V_95 , 0 ) ;
F_53 ( V_88 , V_96 , 1 ) ;
F_53 ( V_88 , V_97 , 1 ) ;
F_53 ( V_88 , V_98 , 1 ) ;
F_53 ( V_88 , V_99 , 1 ) ;
F_53 ( V_88 , V_100 ,
V_101 >> 5 ) ;
F_54 ( V_9 , & V_88 , V_94 ) ;
memcpy ( & V_88 , V_9 -> V_102 , sizeof( V_88 ) ) ;
F_54 ( V_9 , & V_88 , V_103 ) ;
F_55 ( sizeof( V_9 -> V_102 ) <
2 * sizeof( V_88 ) + V_104 / 8 ||
V_105 != 0 ) ;
memcpy ( & V_88 , V_9 -> V_102 , sizeof( V_88 ) ) ;
F_54 ( V_9 , & V_88 , V_106 ) ;
memcpy ( & V_88 , V_9 -> V_102 + sizeof( V_88 ) , sizeof( V_88 ) ) ;
F_54 ( V_9 , & V_88 , V_107 ) ;
F_56 ( V_88 , V_108 , 1 ,
V_109 , 1 ) ;
memcpy ( & V_88 , V_9 -> V_102 + 2 * sizeof( V_88 ) ,
V_104 / 8 ) ;
F_54 ( V_9 , & V_88 , V_110 ) ;
V_19 = F_57 ( V_9 , true , false , 0 ) ;
if ( V_19 )
return V_19 ;
F_58 ( V_88 , V_111 , 0 ) ;
F_54 ( V_9 , & V_88 , V_112 ) ;
F_58 ( V_88 , V_113 , 1 ) ;
F_54 ( V_9 , & V_88 , V_114 ) ;
F_59 ( V_9 ) ;
return 0 ;
}
static void F_60 ( struct V_17 * V_9 )
{
F_61 ( V_9 ) ;
F_15 ( V_9 , & V_9 -> V_82 ) ;
F_21 ( V_9 , V_41 ) ;
F_45 ( V_9 , false , NULL ) ;
F_51 ( V_9 -> V_70 ) ;
V_9 -> V_70 = NULL ;
}
static int F_62 ( struct V_17 * V_9 )
{
T_7 * V_115 ;
struct V_116 * V_117 ;
T_7 V_118 , V_119 ;
V_117 = & V_9 -> V_117 ;
V_115 = V_9 -> V_32 . V_15 ;
V_119 = V_115 [ V_120 ] ;
if ( V_119 == V_121 )
return 0 ;
F_63 () ;
#define F_64 ( T_8 , T_9 ) \
mac_stats->M = le64_to_cpu(dma_stats[MC_CMD_MAC_ ## D])
F_64 ( V_122 , V_123 ) ;
F_64 ( V_124 , V_125 ) ;
F_65 ( & V_117 -> V_126 ,
V_117 -> V_122 - V_117 -> V_124 ) ;
F_64 ( V_127 , V_128 ) ;
F_64 ( V_129 , V_130 ) ;
F_64 ( V_131 , V_132 ) ;
F_64 ( V_133 , V_134 ) ;
F_64 ( V_135 , V_136 ) ;
F_64 ( V_137 , V_138 ) ;
F_64 ( V_139 , V_140 ) ;
F_64 ( V_141 , V_142 ) ;
F_64 ( V_143 , V_144 ) ;
F_64 ( V_145 , V_146 ) ;
F_64 ( V_147 , V_148 ) ;
F_64 ( V_149 , V_150 ) ;
F_64 ( V_151 , V_152 ) ;
F_64 ( V_153 , V_154 ) ;
F_64 ( V_155 , V_156 ) ;
F_64 ( V_157 , V_158 ) ;
V_117 -> V_159 = 0 ;
F_64 ( V_160 , V_161 ) ;
F_64 ( V_162 , V_163 ) ;
F_64 ( V_164 , V_165 ) ;
F_64 ( V_166 , V_167 ) ;
F_64 ( V_168 , V_169 ) ;
V_117 -> V_159 = ( V_117 -> V_160 +
V_117 -> V_162 +
V_117 -> V_164 +
V_117 -> V_168 ) ;
F_64 ( V_170 , V_171 ) ;
F_64 ( V_172 , V_173 ) ;
F_64 ( V_174 , V_175 ) ;
F_64 ( V_176 , V_177 ) ;
F_64 ( V_178 , V_179 ) ;
F_64 ( V_180 , V_181 ) ;
F_65 ( & V_117 -> V_182 ,
V_117 -> V_178 - V_117 -> V_180 ) ;
F_64 ( V_183 , V_184 ) ;
F_64 ( V_185 , V_186 ) ;
F_64 ( V_187 , V_188 ) ;
F_64 ( V_189 , V_190 ) ;
F_64 ( V_191 , V_192 ) ;
F_64 ( V_193 , V_194 ) ;
F_64 ( V_195 , V_196 ) ;
F_64 ( V_197 , V_198 ) ;
F_64 ( V_199 , V_200 ) ;
F_64 ( V_201 , V_202 ) ;
F_64 ( V_203 , V_204 ) ;
F_64 ( V_205 , V_206 ) ;
F_64 ( V_207 , V_208 ) ;
F_64 ( V_209 , V_210 ) ;
F_64 ( V_211 , V_212 ) ;
F_64 ( V_213 , V_214 ) ;
F_64 ( V_215 , V_216 ) ;
V_117 -> V_217 = 0 ;
V_117 -> V_218 = 0 ;
V_117 -> V_219 = 0 ;
F_64 ( V_220 , V_221 ) ;
F_64 ( V_222 , V_223 ) ;
V_117 -> V_224 = 0 ;
F_64 ( V_225 , V_226 ) ;
F_64 ( V_227 , V_228 ) ;
F_64 ( V_229 , V_230 ) ;
F_64 ( V_231 , V_232 ) ;
F_64 ( V_233 , V_234 ) ;
V_117 -> V_235 = 0 ;
V_9 -> V_236 =
F_66 ( V_115 [ V_237 ] ) ;
#undef F_64
F_63 () ;
V_118 = V_115 [ V_238 ] ;
if ( V_119 != V_118 )
return - V_239 ;
return 0 ;
}
static void F_67 ( struct V_17 * V_9 )
{
int V_240 ;
for ( V_240 = 0 ; V_240 < 100 ; ++ V_240 ) {
if ( F_62 ( V_9 ) == 0 )
return;
F_68 ( 100 ) ;
}
}
static void F_69 ( struct V_17 * V_9 )
{
T_7 * V_115 = V_9 -> V_32 . V_15 ;
V_115 [ V_120 ] = V_121 ;
F_13 ( V_9 , V_9 -> V_32 . V_35 ,
V_33 * sizeof( V_34 ) , 1 , 0 ) ;
}
static void F_70 ( struct V_17 * V_9 )
{
F_13 ( V_9 , V_9 -> V_32 . V_35 , 0 , 0 , 0 ) ;
}
static void F_71 ( struct V_17 * V_9 , struct V_241 * V_242 )
{
struct V_69 * V_70 = V_9 -> V_70 ;
V_242 -> V_243 = V_244 ;
if ( V_70 -> V_245 != - 1 )
V_242 -> V_246 = V_244 ;
else
V_242 -> V_246 = 0 ;
memset ( & V_242 -> V_247 , 0 , sizeof( V_242 -> V_247 ) ) ;
}
static int F_72 ( struct V_17 * V_9 , T_5 type )
{
struct V_69 * V_70 = V_9 -> V_70 ;
int V_19 ;
if ( type & ~ V_244 )
return - V_59 ;
if ( type & V_244 ) {
if ( V_70 -> V_245 != - 1 )
F_73 ( V_9 ,
V_70 -> V_245 ) ;
V_19 = F_74 ( V_9 , V_9 -> V_12 -> V_248 ,
& V_70 -> V_245 ) ;
if ( V_19 )
goto V_249;
F_75 ( V_9 -> V_63 , true ) ;
} else {
V_19 = F_76 ( V_9 ) ;
V_70 -> V_245 = - 1 ;
F_75 ( V_9 -> V_63 , false ) ;
if ( V_19 )
goto V_249;
}
return 0 ;
V_249:
F_41 ( V_9 , V_250 , V_9 -> V_12 , L_8 ,
V_251 , type , V_19 ) ;
return V_19 ;
}
static void F_46 ( struct V_17 * V_9 )
{
struct V_69 * V_70 = V_9 -> V_70 ;
int V_19 ;
V_19 = F_77 ( V_9 , & V_70 -> V_245 ) ;
if ( V_19 != 0 ) {
F_76 ( V_9 ) ;
V_70 -> V_245 = - 1 ;
} else if ( V_70 -> V_245 != - 1 ) {
F_75 ( V_9 -> V_63 , true ) ;
}
}
