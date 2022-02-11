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
return V_41 ;
}
static int F_26 ( T_5 * V_47 )
{
enum {
V_48 = ( V_49 | V_50 |
V_51 | V_52 |
V_53 ) ,
V_54 = ( V_48 |
V_55 << V_56 ) ,
};
if ( ( * V_47 & V_54 ) == V_54 ) {
* V_47 &= ~ V_54 ;
return V_57 ;
}
if ( ( * V_47 & V_48 ) == V_48 ) {
* V_47 &= ~ V_48 ;
return V_41 ;
}
return - V_58 ;
}
static int F_21 ( struct V_17 * V_9 , enum V_39 V_59 )
{
int V_19 ;
V_19 = F_27 ( V_9 ) ;
if ( V_19 )
return V_19 ;
if ( V_59 == V_57 )
return F_28 ( V_9 ) ;
else
return F_29 ( V_9 ) ;
}
static int F_30 ( struct V_17 * V_9 )
{
T_5 V_60 = 0 ;
int V_19 ;
V_19 = F_31 ( V_9 , V_9 -> V_12 -> V_61 , NULL , & V_60 ) ;
V_9 -> V_62 =
( V_60 & ( 1 << V_63 ) ) ?
3072 : 6144 ;
return V_19 ;
}
static void F_32 ( struct V_17 * V_9 )
{
F_33 ( V_9 , V_64 / 2 ) ;
}
static int F_34 ( struct V_17 * V_9 )
{
struct V_65 * V_66 ;
bool V_67 = false ;
T_6 V_68 ;
int V_19 ;
V_66 = F_35 ( sizeof( struct V_65 ) , V_69 ) ;
if ( ! V_66 )
return - V_70 ;
V_9 -> V_66 = V_66 ;
if ( F_36 ( V_9 ) != 0 ) {
F_37 ( V_9 , V_31 , V_9 -> V_12 ,
L_2 ) ;
V_19 = - V_71 ;
goto V_72;
}
F_38 ( V_9 , & V_68 , V_73 ) ;
V_9 -> V_12 -> V_74 = F_39 ( V_68 , V_75 ) - 1 ;
F_40 ( V_9 ) ;
V_19 = F_27 ( V_9 ) ;
if ( V_19 )
goto V_72;
V_19 = F_41 ( V_9 , true , & V_67 ) ;
if ( V_19 ) {
F_37 ( V_9 , V_31 , V_9 -> V_12 ,
L_3 ) ;
goto V_76;
}
if ( V_67 )
F_37 ( V_9 , V_31 , V_9 -> V_12 ,
L_4 ) ;
V_19 = F_21 ( V_9 , V_41 ) ;
if ( V_19 ) {
F_37 ( V_9 , V_31 , V_9 -> V_12 , L_5 ) ;
goto V_77;
}
F_42 ( V_9 ) ;
V_19 = F_10 ( V_9 , & V_9 -> V_78 , sizeof( T_6 ) ) ;
if ( V_19 )
goto V_79;
F_43 ( V_9 -> V_78 . V_35 & 0x0f ) ;
F_11 ( V_9 , V_31 , V_9 -> V_12 ,
L_6 ,
( unsigned long long ) V_9 -> V_78 . V_35 ,
V_9 -> V_78 . V_15 ,
( unsigned long long ) F_12 ( V_9 -> V_78 . V_15 ) ) ;
V_19 = F_30 ( V_9 ) ;
if ( V_19 == - V_58 ) {
F_37 ( V_9 , V_31 , V_9 -> V_12 ,
L_7 ) ;
V_9 -> V_80 = V_81 ;
V_9 -> V_25 . V_13 = V_82 ;
} else if ( V_19 ) {
goto V_83;
}
V_19 = F_44 ( V_9 ) ;
if ( V_19 )
goto V_83;
F_45 ( V_9 ) ;
F_46 ( V_9 ) ;
return 0 ;
V_83:
F_15 ( V_9 , & V_9 -> V_78 ) ;
V_79:
V_77:
F_41 ( V_9 , false , NULL ) ;
V_76:
V_72:
F_47 ( V_9 -> V_66 ) ;
return V_19 ;
}
static int F_48 ( struct V_17 * V_9 )
{
T_6 V_84 ;
int V_19 ;
V_19 = F_27 ( V_9 ) ;
if ( V_19 )
return V_19 ;
F_38 ( V_9 , & V_84 , V_85 ) ;
F_49 ( V_84 , V_86 , 1 ) ;
F_50 ( V_9 , & V_84 , V_85 ) ;
F_38 ( V_9 , & V_84 , V_87 ) ;
F_49 ( V_84 , V_88 , 0 ) ;
F_49 ( V_84 , V_89 , 1 ) ;
F_50 ( V_9 , & V_84 , V_87 ) ;
F_38 ( V_9 , & V_84 , V_90 ) ;
F_49 ( V_84 , V_91 , 0 ) ;
F_49 ( V_84 , V_92 , 1 ) ;
F_49 ( V_84 , V_93 , 1 ) ;
F_49 ( V_84 , V_94 , 1 ) ;
F_49 ( V_84 , V_95 , 1 ) ;
F_50 ( V_9 , & V_84 , V_90 ) ;
memcpy ( & V_84 , V_9 -> V_96 , sizeof( V_84 ) ) ;
F_50 ( V_9 , & V_84 , V_97 ) ;
F_51 ( sizeof( V_9 -> V_96 ) <
2 * sizeof( V_84 ) + V_98 / 8 ||
V_99 != 0 ) ;
memcpy ( & V_84 , V_9 -> V_96 , sizeof( V_84 ) ) ;
F_50 ( V_9 , & V_84 , V_100 ) ;
memcpy ( & V_84 , V_9 -> V_96 + sizeof( V_84 ) , sizeof( V_84 ) ) ;
F_50 ( V_9 , & V_84 , V_101 ) ;
F_52 ( V_84 , V_102 , 1 ,
V_103 , 1 ) ;
memcpy ( & V_84 , V_9 -> V_96 + 2 * sizeof( V_84 ) ,
V_98 / 8 ) ;
F_50 ( V_9 , & V_84 , V_104 ) ;
V_19 = F_53 ( V_9 , true , false , 0 ) ;
if ( V_19 )
return V_19 ;
F_54 ( V_84 , V_105 , 0 ) ;
F_50 ( V_9 , & V_84 , V_106 ) ;
F_54 ( V_84 , V_107 , 1 ) ;
F_50 ( V_9 , & V_84 , V_108 ) ;
F_55 ( V_9 ) ;
return 0 ;
}
static void F_56 ( struct V_17 * V_9 )
{
F_57 ( V_9 ) ;
F_15 ( V_9 , & V_9 -> V_78 ) ;
F_21 ( V_9 , V_41 ) ;
F_41 ( V_9 , false , NULL ) ;
F_47 ( V_9 -> V_66 ) ;
V_9 -> V_66 = NULL ;
}
static int F_58 ( struct V_17 * V_9 )
{
T_7 * V_109 ;
struct V_110 * V_111 ;
T_7 V_112 , V_113 ;
V_111 = & V_9 -> V_111 ;
V_109 = V_9 -> V_32 . V_15 ;
V_113 = V_109 [ V_114 ] ;
if ( V_113 == V_115 )
return 0 ;
F_59 () ;
#define F_60 ( T_8 , T_9 ) \
mac_stats->M = le64_to_cpu(dma_stats[MC_CMD_MAC_ ## D])
F_60 ( V_116 , V_117 ) ;
F_60 ( V_118 , V_119 ) ;
F_61 ( & V_111 -> V_120 ,
V_111 -> V_116 - V_111 -> V_118 ) ;
F_60 ( V_121 , V_122 ) ;
F_60 ( V_123 , V_124 ) ;
F_60 ( V_125 , V_126 ) ;
F_60 ( V_127 , V_128 ) ;
F_60 ( V_129 , V_130 ) ;
F_60 ( V_131 , V_132 ) ;
F_60 ( V_133 , V_134 ) ;
F_60 ( V_135 , V_136 ) ;
F_60 ( V_137 , V_138 ) ;
F_60 ( V_139 , V_140 ) ;
F_60 ( V_141 , V_142 ) ;
F_60 ( V_143 , V_144 ) ;
F_60 ( V_145 , V_146 ) ;
F_60 ( V_147 , V_148 ) ;
F_60 ( V_149 , V_150 ) ;
F_60 ( V_151 , V_152 ) ;
V_111 -> V_153 = 0 ;
F_60 ( V_154 , V_155 ) ;
F_60 ( V_156 , V_157 ) ;
F_60 ( V_158 , V_159 ) ;
F_60 ( V_160 , V_161 ) ;
F_60 ( V_162 , V_163 ) ;
V_111 -> V_153 = ( V_111 -> V_154 +
V_111 -> V_156 +
V_111 -> V_158 +
V_111 -> V_162 ) ;
F_60 ( V_164 , V_165 ) ;
F_60 ( V_166 , V_167 ) ;
F_60 ( V_168 , V_169 ) ;
F_60 ( V_170 , V_171 ) ;
F_60 ( V_172 , V_173 ) ;
F_60 ( V_174 , V_175 ) ;
F_61 ( & V_111 -> V_176 ,
V_111 -> V_172 - V_111 -> V_174 ) ;
F_60 ( V_177 , V_178 ) ;
F_60 ( V_179 , V_180 ) ;
F_60 ( V_181 , V_182 ) ;
F_60 ( V_183 , V_184 ) ;
F_60 ( V_185 , V_186 ) ;
F_60 ( V_187 , V_188 ) ;
F_60 ( V_189 , V_190 ) ;
F_60 ( V_191 , V_192 ) ;
F_60 ( V_193 , V_194 ) ;
F_60 ( V_195 , V_196 ) ;
F_60 ( V_197 , V_198 ) ;
F_60 ( V_199 , V_200 ) ;
F_60 ( V_201 , V_202 ) ;
F_60 ( V_203 , V_204 ) ;
F_60 ( V_205 , V_206 ) ;
F_60 ( V_207 , V_208 ) ;
F_60 ( V_209 , V_210 ) ;
V_111 -> V_211 = 0 ;
V_111 -> V_212 = 0 ;
V_111 -> V_213 = 0 ;
F_60 ( V_214 , V_215 ) ;
F_60 ( V_216 , V_217 ) ;
V_111 -> V_218 = 0 ;
F_60 ( V_219 , V_220 ) ;
F_60 ( V_221 , V_222 ) ;
F_60 ( V_223 , V_224 ) ;
F_60 ( V_225 , V_226 ) ;
F_60 ( V_227 , V_228 ) ;
V_111 -> V_229 = 0 ;
V_9 -> V_230 =
F_62 ( V_109 [ V_231 ] ) ;
#undef F_60
F_59 () ;
V_112 = V_109 [ V_232 ] ;
if ( V_113 != V_112 )
return - V_233 ;
return 0 ;
}
static void F_63 ( struct V_17 * V_9 )
{
int V_234 ;
for ( V_234 = 0 ; V_234 < 100 ; ++ V_234 ) {
if ( F_58 ( V_9 ) == 0 )
return;
F_64 ( 100 ) ;
}
}
static void F_65 ( struct V_17 * V_9 )
{
T_7 * V_109 = V_9 -> V_32 . V_15 ;
V_109 [ V_114 ] = V_115 ;
F_13 ( V_9 , V_9 -> V_32 . V_35 ,
V_33 * sizeof( V_34 ) , 1 , 0 ) ;
}
static void F_66 ( struct V_17 * V_9 )
{
F_13 ( V_9 , V_9 -> V_32 . V_35 , 0 , 0 , 0 ) ;
}
static void F_67 ( struct V_17 * V_9 , struct V_235 * V_236 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
V_236 -> V_237 = V_238 ;
if ( V_66 -> V_239 != - 1 )
V_236 -> V_240 = V_238 ;
else
V_236 -> V_240 = 0 ;
memset ( & V_236 -> V_241 , 0 , sizeof( V_236 -> V_241 ) ) ;
}
static int F_68 ( struct V_17 * V_9 , T_5 type )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_19 ;
if ( type & ~ V_238 )
return - V_58 ;
if ( type & V_238 ) {
if ( V_66 -> V_239 != - 1 )
F_69 ( V_9 ,
V_66 -> V_239 ) ;
V_19 = F_70 ( V_9 , V_9 -> V_12 -> V_242 ,
& V_66 -> V_239 ) ;
if ( V_19 )
goto V_243;
F_71 ( V_9 -> V_244 , true ) ;
} else {
V_19 = F_72 ( V_9 ) ;
V_66 -> V_239 = - 1 ;
F_71 ( V_9 -> V_244 , false ) ;
if ( V_19 )
goto V_243;
}
return 0 ;
V_243:
F_37 ( V_9 , V_245 , V_9 -> V_12 , L_8 ,
V_246 , type , V_19 ) ;
return V_19 ;
}
static void F_42 ( struct V_17 * V_9 )
{
struct V_65 * V_66 = V_9 -> V_66 ;
int V_19 ;
V_19 = F_73 ( V_9 , & V_66 -> V_239 ) ;
if ( V_19 != 0 ) {
F_72 ( V_9 ) ;
V_66 -> V_239 = - 1 ;
} else if ( V_66 -> V_239 != - 1 ) {
F_71 ( V_9 -> V_244 , true ) ;
}
}
