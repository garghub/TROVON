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
static int F_16 ( struct V_17 * V_9 , struct V_36 * V_37 )
{
enum V_38 V_39 = V_39 ;
int V_19 , V_40 ;
F_17 ( V_9 , V_39 ) ;
V_19 = F_18 ( V_9 , V_39 ) ;
if ( V_19 )
goto V_41;
V_37 -> V_42 =
F_19 ( V_9 , V_43 ,
F_20 ( V_43 ) )
? - 1 : 1 ;
V_19 = F_18 ( V_9 , V_39 ) ;
V_41:
V_40 = F_21 ( V_9 , V_39 , V_19 == 0 ) ;
return V_19 ? V_19 : V_40 ;
}
static enum V_38 F_22 ( enum V_38 V_44 )
{
return V_45 ;
}
static int F_23 ( T_5 * V_46 )
{
enum {
V_47 = ( V_48 | V_49 |
V_50 | V_51 |
V_52 ) ,
V_53 = ( V_47 |
V_54 << V_55 ) ,
};
if ( ( * V_46 & V_53 ) == V_53 ) {
* V_46 &= ~ V_53 ;
return V_56 ;
}
if ( ( * V_46 & V_47 ) == V_47 ) {
* V_46 &= ~ V_47 ;
return V_45 ;
}
return - V_57 ;
}
static int F_18 ( struct V_17 * V_9 , enum V_38 V_58 )
{
int V_19 ;
V_19 = F_24 ( V_9 ) ;
if ( V_19 )
return V_19 ;
if ( V_58 == V_56 )
return F_25 ( V_9 ) ;
else
return F_26 ( V_9 ) ;
}
static int F_27 ( struct V_17 * V_9 )
{
T_5 V_59 = 0 ;
int V_19 ;
V_19 = F_28 ( V_9 , V_9 -> V_12 -> V_60 , NULL , & V_59 ) ;
V_9 -> V_61 =
( V_59 & ( 1 << V_62 ) ) ?
3072 : 6144 ;
return V_19 ;
}
static void F_29 ( struct V_17 * V_9 )
{
F_30 ( V_9 , V_63 / 2 ) ;
}
static int F_31 ( struct V_17 * V_9 )
{
struct V_64 * V_65 ;
bool V_66 = false ;
T_6 V_67 ;
int V_19 ;
V_65 = F_32 ( sizeof( struct V_64 ) , V_68 ) ;
if ( ! V_65 )
return - V_69 ;
V_9 -> V_65 = V_65 ;
if ( F_33 ( V_9 ) != 0 ) {
F_34 ( V_9 , V_31 , V_9 -> V_12 ,
L_2 ) ;
V_19 = - V_70 ;
goto V_71;
}
F_35 ( V_9 , & V_67 , V_72 ) ;
V_9 -> V_12 -> V_73 = F_36 ( V_67 , V_74 ) - 1 ;
F_37 ( V_9 ) ;
V_19 = F_24 ( V_9 ) ;
if ( V_19 )
goto V_71;
V_19 = F_38 ( V_9 , true , & V_66 ) ;
if ( V_19 ) {
F_34 ( V_9 , V_31 , V_9 -> V_12 ,
L_3 ) ;
goto V_75;
}
if ( V_66 )
F_34 ( V_9 , V_31 , V_9 -> V_12 ,
L_4 ) ;
V_19 = F_18 ( V_9 , V_45 ) ;
if ( V_19 ) {
F_34 ( V_9 , V_31 , V_9 -> V_12 , L_5 ) ;
goto V_76;
}
F_39 ( V_9 ) ;
V_19 = F_10 ( V_9 , & V_9 -> V_77 , sizeof( T_6 ) ) ;
if ( V_19 )
goto V_78;
F_40 ( V_9 -> V_77 . V_35 & 0x0f ) ;
F_11 ( V_9 , V_31 , V_9 -> V_12 ,
L_6 ,
( unsigned long long ) V_9 -> V_77 . V_35 ,
V_9 -> V_77 . V_15 ,
( unsigned long long ) F_12 ( V_9 -> V_77 . V_15 ) ) ;
V_19 = F_27 ( V_9 ) ;
if ( V_19 == - V_57 ) {
F_34 ( V_9 , V_31 , V_9 -> V_12 ,
L_7 ) ;
V_9 -> V_79 = V_80 ;
V_9 -> V_25 . V_13 = V_81 ;
} else if ( V_19 ) {
goto V_82;
}
V_19 = F_41 ( V_9 ) ;
if ( V_19 )
goto V_82;
F_42 ( V_9 ) ;
F_43 ( V_9 ) ;
return 0 ;
V_82:
F_15 ( V_9 , & V_9 -> V_77 ) ;
V_78:
V_76:
F_38 ( V_9 , false , NULL ) ;
V_75:
V_71:
F_44 ( V_9 -> V_65 ) ;
return V_19 ;
}
static int F_45 ( struct V_17 * V_9 )
{
T_6 V_83 ;
int V_19 ;
V_19 = F_24 ( V_9 ) ;
if ( V_19 )
return V_19 ;
F_35 ( V_9 , & V_83 , V_84 ) ;
F_46 ( V_83 , V_85 , 1 ) ;
F_47 ( V_9 , & V_83 , V_84 ) ;
F_35 ( V_9 , & V_83 , V_86 ) ;
F_46 ( V_83 , V_87 , 0 ) ;
F_46 ( V_83 , V_88 , 1 ) ;
F_47 ( V_9 , & V_83 , V_86 ) ;
F_35 ( V_9 , & V_83 , V_89 ) ;
F_46 ( V_83 , V_90 , 0 ) ;
F_46 ( V_83 , V_91 , 1 ) ;
F_46 ( V_83 , V_92 , 1 ) ;
F_46 ( V_83 , V_93 , 1 ) ;
F_46 ( V_83 , V_94 , 1 ) ;
F_47 ( V_9 , & V_83 , V_89 ) ;
memcpy ( & V_83 , V_9 -> V_95 , sizeof( V_83 ) ) ;
F_47 ( V_9 , & V_83 , V_96 ) ;
F_48 ( sizeof( V_9 -> V_95 ) <
2 * sizeof( V_83 ) + V_97 / 8 ||
V_98 != 0 ) ;
memcpy ( & V_83 , V_9 -> V_95 , sizeof( V_83 ) ) ;
F_47 ( V_9 , & V_83 , V_99 ) ;
memcpy ( & V_83 , V_9 -> V_95 + sizeof( V_83 ) , sizeof( V_83 ) ) ;
F_47 ( V_9 , & V_83 , V_100 ) ;
F_49 ( V_83 , V_101 , 1 ,
V_102 , 1 ) ;
memcpy ( & V_83 , V_9 -> V_95 + 2 * sizeof( V_83 ) ,
V_97 / 8 ) ;
F_47 ( V_9 , & V_83 , V_103 ) ;
V_19 = F_50 ( V_9 , true , false , 0 ) ;
if ( V_19 )
return V_19 ;
F_51 ( V_83 , V_104 , 0 ) ;
F_47 ( V_9 , & V_83 , V_105 ) ;
F_51 ( V_83 , V_106 , 1 ) ;
F_47 ( V_9 , & V_83 , V_107 ) ;
F_52 ( V_9 ) ;
return 0 ;
}
static void F_53 ( struct V_17 * V_9 )
{
F_54 ( V_9 ) ;
F_15 ( V_9 , & V_9 -> V_77 ) ;
F_18 ( V_9 , V_45 ) ;
F_38 ( V_9 , false , NULL ) ;
F_44 ( V_9 -> V_65 ) ;
V_9 -> V_65 = NULL ;
}
static int F_55 ( struct V_17 * V_9 )
{
T_7 * V_108 ;
struct V_109 * V_110 ;
T_7 V_111 , V_112 ;
V_110 = & V_9 -> V_110 ;
V_108 = V_9 -> V_32 . V_15 ;
V_112 = V_108 [ V_113 ] ;
if ( V_112 == V_114 )
return 0 ;
F_56 () ;
#define F_57 ( T_8 , T_9 ) \
mac_stats->M = le64_to_cpu(dma_stats[MC_CMD_MAC_ ## D])
F_57 ( V_115 , V_116 ) ;
F_57 ( V_117 , V_118 ) ;
F_58 ( & V_110 -> V_119 ,
V_110 -> V_115 - V_110 -> V_117 ) ;
F_57 ( V_120 , V_121 ) ;
F_57 ( V_122 , V_123 ) ;
F_57 ( V_124 , V_125 ) ;
F_57 ( V_126 , V_127 ) ;
F_57 ( V_128 , V_129 ) ;
F_57 ( V_130 , V_131 ) ;
F_57 ( V_132 , V_133 ) ;
F_57 ( V_134 , V_135 ) ;
F_57 ( V_136 , V_137 ) ;
F_57 ( V_138 , V_139 ) ;
F_57 ( V_140 , V_141 ) ;
F_57 ( V_142 , V_143 ) ;
F_57 ( V_144 , V_145 ) ;
F_57 ( V_146 , V_147 ) ;
F_57 ( V_148 , V_149 ) ;
F_57 ( V_150 , V_151 ) ;
V_110 -> V_152 = 0 ;
F_57 ( V_153 , V_154 ) ;
F_57 ( V_155 , V_156 ) ;
F_57 ( V_157 , V_158 ) ;
F_57 ( V_159 , V_160 ) ;
F_57 ( V_161 , V_162 ) ;
V_110 -> V_152 = ( V_110 -> V_153 +
V_110 -> V_155 +
V_110 -> V_157 +
V_110 -> V_161 ) ;
F_57 ( V_163 , V_164 ) ;
F_57 ( V_165 , V_166 ) ;
F_57 ( V_167 , V_168 ) ;
F_57 ( V_169 , V_170 ) ;
F_57 ( V_171 , V_172 ) ;
F_57 ( V_173 , V_174 ) ;
F_58 ( & V_110 -> V_175 ,
V_110 -> V_171 - V_110 -> V_173 ) ;
F_57 ( V_176 , V_177 ) ;
F_57 ( V_178 , V_179 ) ;
F_57 ( V_180 , V_181 ) ;
F_57 ( V_182 , V_183 ) ;
F_57 ( V_184 , V_185 ) ;
F_57 ( V_186 , V_187 ) ;
F_57 ( V_188 , V_189 ) ;
F_57 ( V_190 , V_191 ) ;
F_57 ( V_192 , V_193 ) ;
F_57 ( V_194 , V_195 ) ;
F_57 ( V_196 , V_197 ) ;
F_57 ( V_198 , V_199 ) ;
F_57 ( V_200 , V_201 ) ;
F_57 ( V_202 , V_203 ) ;
F_57 ( V_204 , V_205 ) ;
F_57 ( V_206 , V_207 ) ;
F_57 ( V_208 , V_209 ) ;
V_110 -> V_210 = 0 ;
V_110 -> V_211 = 0 ;
V_110 -> V_212 = 0 ;
F_57 ( V_213 , V_214 ) ;
F_57 ( V_215 , V_216 ) ;
V_110 -> V_217 = 0 ;
F_57 ( V_218 , V_219 ) ;
F_57 ( V_220 , V_221 ) ;
F_57 ( V_222 , V_223 ) ;
F_57 ( V_224 , V_225 ) ;
F_57 ( V_226 , V_227 ) ;
V_110 -> V_228 = 0 ;
V_9 -> V_229 =
F_59 ( V_108 [ V_230 ] ) ;
#undef F_57
F_56 () ;
V_111 = V_108 [ V_231 ] ;
if ( V_112 != V_111 )
return - V_232 ;
return 0 ;
}
static void F_60 ( struct V_17 * V_9 )
{
int V_233 ;
for ( V_233 = 0 ; V_233 < 100 ; ++ V_233 ) {
if ( F_55 ( V_9 ) == 0 )
return;
F_61 ( 100 ) ;
}
}
static void F_62 ( struct V_17 * V_9 )
{
T_7 * V_108 = V_9 -> V_32 . V_15 ;
V_108 [ V_113 ] = V_114 ;
F_13 ( V_9 , V_9 -> V_32 . V_35 ,
V_33 * sizeof( V_34 ) , 1 , 0 ) ;
}
static void F_63 ( struct V_17 * V_9 )
{
F_13 ( V_9 , V_9 -> V_32 . V_35 , 0 , 0 , 0 ) ;
}
static void F_64 ( struct V_17 * V_9 , struct V_234 * V_235 )
{
struct V_64 * V_65 = V_9 -> V_65 ;
V_235 -> V_236 = V_237 ;
if ( V_65 -> V_238 != - 1 )
V_235 -> V_239 = V_237 ;
else
V_235 -> V_239 = 0 ;
memset ( & V_235 -> V_240 , 0 , sizeof( V_235 -> V_240 ) ) ;
}
static int F_65 ( struct V_17 * V_9 , T_5 type )
{
struct V_64 * V_65 = V_9 -> V_65 ;
int V_19 ;
if ( type & ~ V_237 )
return - V_57 ;
if ( type & V_237 ) {
if ( V_65 -> V_238 != - 1 )
F_66 ( V_9 ,
V_65 -> V_238 ) ;
V_19 = F_67 ( V_9 , V_9 -> V_12 -> V_241 ,
& V_65 -> V_238 ) ;
if ( V_19 )
goto V_242;
F_68 ( V_9 -> V_243 , true ) ;
} else {
V_19 = F_69 ( V_9 ) ;
V_65 -> V_238 = - 1 ;
F_68 ( V_9 -> V_243 , false ) ;
if ( V_19 )
goto V_242;
}
return 0 ;
V_242:
F_34 ( V_9 , V_244 , V_9 -> V_12 , L_8 ,
V_245 , type , V_19 ) ;
return V_19 ;
}
static void F_39 ( struct V_17 * V_9 )
{
struct V_64 * V_65 = V_9 -> V_65 ;
int V_19 ;
V_19 = F_70 ( V_9 , & V_65 -> V_238 ) ;
if ( V_19 != 0 ) {
F_69 ( V_9 ) ;
V_65 -> V_238 = - 1 ;
} else if ( V_65 -> V_238 != - 1 ) {
F_68 ( V_9 -> V_243 , true ) ;
}
}
