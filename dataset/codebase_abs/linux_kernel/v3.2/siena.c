static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_4 > ( 1 << V_5 ) ) ;
if ( V_2 -> V_6 )
F_3 ( V_3 ,
V_7 ,
V_8 ,
V_9 ,
V_2 -> V_6 - 1 ) ;
else
F_3 ( V_3 ,
V_7 ,
V_10 ,
V_9 , 0 ) ;
F_4 ( V_2 -> V_11 , & V_3 , V_12 ,
V_2 -> V_2 ) ;
}
static void F_5 ( struct V_13 * V_11 )
{
F_6 ( ! F_7 ( & V_11 -> V_14 ) ) ;
F_8 ( V_11 , V_15 ,
V_11 -> V_16 . V_17 , sizeof( V_11 -> V_16 ) ,
NULL , 0 , NULL ) ;
}
static int F_9 ( struct V_18 * V_19 ,
int V_20 , int V_21 , T_2 V_22 , T_2 V_23 )
{
struct V_13 * V_11 = F_10 ( V_19 ) ;
T_3 V_24 ;
int V_25 ;
V_25 = F_11 ( V_11 , V_11 -> V_26 , V_20 , V_21 ,
V_22 , V_23 , & V_24 ) ;
if ( V_25 )
return V_25 ;
if ( V_24 != V_27 )
return - V_28 ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 ,
int V_20 , int V_21 , T_2 V_22 )
{
struct V_13 * V_11 = F_10 ( V_19 ) ;
T_4 V_23 ;
T_3 V_24 ;
int V_25 ;
V_25 = F_13 ( V_11 , V_11 -> V_26 , V_20 , V_21 ,
V_22 , & V_23 , & V_24 ) ;
if ( V_25 )
return V_25 ;
if ( V_24 != V_27 )
return - V_28 ;
return ( int ) V_23 ;
}
static int F_14 ( struct V_13 * V_11 )
{
int V_25 ;
V_11 -> V_29 = & V_30 ;
V_11 -> V_31 . V_32 = V_33 | V_34 ;
V_11 -> V_31 . V_35 = F_12 ;
V_11 -> V_31 . V_36 = F_9 ;
V_25 = V_11 -> V_29 -> V_37 ( V_11 ) ;
if ( V_25 != 0 )
return V_25 ;
V_25 = F_15 ( V_11 , & V_11 -> V_38 ,
V_39 * sizeof( V_40 ) ) ;
if ( V_25 )
return V_25 ;
F_16 ( V_11 , V_37 , V_11 -> V_19 ,
L_1 ,
( V_40 ) V_11 -> V_38 . V_41 ,
V_11 -> V_38 . V_22 ,
( V_40 ) F_17 ( V_11 -> V_38 . V_22 ) ) ;
F_18 ( V_11 , V_11 -> V_38 . V_41 , 0 , 0 , 1 ) ;
return 0 ;
}
static void F_19 ( struct V_13 * V_11 )
{
V_11 -> V_29 -> remove ( V_11 ) ;
F_20 ( V_11 , & V_11 -> V_38 ) ;
}
static int F_21 ( struct V_13 * V_11 )
{
return F_22 ( V_11 , V_42 ,
F_23 ( V_42 ) ) ;
}
static enum V_43 F_24 ( enum V_43 V_44 )
{
return V_45 ;
}
static int F_25 ( T_5 * V_46 )
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
static int F_26 ( struct V_13 * V_11 , enum V_43 V_58 )
{
int V_25 ;
V_25 = F_27 ( V_11 ) ;
if ( V_25 )
return V_25 ;
if ( V_58 == V_56 )
return F_28 ( V_11 ) ;
else
return F_29 ( V_11 ) ;
}
static int F_30 ( struct V_13 * V_11 )
{
return F_31 ( V_11 , V_11 -> V_19 -> V_59 , NULL ) ;
}
static int F_32 ( struct V_13 * V_11 )
{
struct V_60 * V_61 ;
bool V_62 = 0 ;
T_6 V_63 ;
int V_25 ;
V_61 = F_33 ( sizeof( struct V_60 ) , V_64 ) ;
if ( ! V_61 )
return - V_65 ;
V_11 -> V_61 = V_61 ;
if ( F_34 ( V_11 ) != 0 ) {
F_35 ( V_11 , V_37 , V_11 -> V_19 ,
L_2 ) ;
V_25 = - V_66 ;
goto V_67;
}
F_36 ( V_11 , & V_63 , V_68 ) ;
V_11 -> V_19 -> V_69 = F_37 ( V_63 , V_70 ) - 1 ;
F_38 ( V_11 ) ;
V_25 = F_27 ( V_11 ) ;
if ( V_25 )
goto V_67;
V_25 = F_39 ( V_11 , true , & V_62 ) ;
if ( V_25 ) {
F_35 ( V_11 , V_37 , V_11 -> V_19 ,
L_3 ) ;
goto V_71;
}
if ( V_62 )
F_35 ( V_11 , V_37 , V_11 -> V_19 ,
L_4 ) ;
V_25 = F_26 ( V_11 , V_45 ) ;
if ( V_25 ) {
F_35 ( V_11 , V_37 , V_11 -> V_19 , L_5 ) ;
goto V_72;
}
F_40 ( V_11 ) ;
V_25 = F_15 ( V_11 , & V_11 -> V_73 , sizeof( T_6 ) ) ;
if ( V_25 )
goto V_74;
F_41 ( V_11 -> V_73 . V_41 & 0x0f ) ;
F_16 ( V_11 , V_37 , V_11 -> V_19 ,
L_6 ,
( unsigned long long ) V_11 -> V_73 . V_41 ,
V_11 -> V_73 . V_22 ,
( unsigned long long ) F_17 ( V_11 -> V_73 . V_22 ) ) ;
V_25 = F_30 ( V_11 ) ;
if ( V_25 == - V_57 ) {
F_35 ( V_11 , V_37 , V_11 -> V_19 ,
L_7 ) ;
V_11 -> V_75 = V_76 ;
V_11 -> V_31 . V_20 = V_77 ;
} else if ( V_25 ) {
goto V_78;
}
return 0 ;
V_78:
F_20 ( V_11 , & V_11 -> V_73 ) ;
V_74:
V_72:
F_39 ( V_11 , false , NULL ) ;
V_71:
V_67:
F_42 ( V_11 -> V_61 ) ;
return V_25 ;
}
static int F_43 ( struct V_13 * V_11 )
{
T_6 V_79 ;
int V_25 ;
V_25 = F_27 ( V_11 ) ;
if ( V_25 )
return V_25 ;
F_36 ( V_11 , & V_79 , V_80 ) ;
F_44 ( V_79 , V_81 , 1 ) ;
F_45 ( V_11 , & V_79 , V_80 ) ;
F_36 ( V_11 , & V_79 , V_82 ) ;
F_44 ( V_79 , V_83 , 0 ) ;
F_44 ( V_79 , V_84 , 1 ) ;
F_45 ( V_11 , & V_79 , V_82 ) ;
F_36 ( V_11 , & V_79 , V_85 ) ;
F_44 ( V_79 , V_86 , 0 ) ;
F_44 ( V_79 , V_87 , 1 ) ;
F_44 ( V_79 , V_88 , 1 ) ;
F_44 ( V_79 , V_89 , 1 ) ;
F_44 ( V_79 , V_90 , 1 ) ;
F_45 ( V_11 , & V_79 , V_85 ) ;
memcpy ( & V_79 , V_11 -> V_91 , sizeof( V_79 ) ) ;
F_45 ( V_11 , & V_79 , V_92 ) ;
F_2 ( sizeof( V_11 -> V_91 ) <
2 * sizeof( V_79 ) + V_93 / 8 ||
V_94 != 0 ) ;
memcpy ( & V_79 , V_11 -> V_91 , sizeof( V_79 ) ) ;
F_45 ( V_11 , & V_79 , V_95 ) ;
memcpy ( & V_79 , V_11 -> V_91 + sizeof( V_79 ) , sizeof( V_79 ) ) ;
F_45 ( V_11 , & V_79 , V_96 ) ;
F_46 ( V_79 , V_97 , 1 ,
V_98 , 1 ) ;
memcpy ( & V_79 , V_11 -> V_91 + 2 * sizeof( V_79 ) ,
V_93 / 8 ) ;
F_45 ( V_11 , & V_79 , V_99 ) ;
V_25 = F_47 ( V_11 , true , false , 0 ) ;
if ( V_25 )
return V_25 ;
F_48 ( V_79 , V_100 , 0 ) ;
F_45 ( V_11 , & V_79 , V_101 ) ;
F_48 ( V_79 , V_102 , 1 ) ;
F_45 ( V_11 , & V_79 , V_103 ) ;
F_49 ( V_11 ) ;
return 0 ;
}
static void F_50 ( struct V_13 * V_11 )
{
F_20 ( V_11 , & V_11 -> V_73 ) ;
F_26 ( V_11 , V_45 ) ;
if ( F_51 ( V_11 ) )
F_39 ( V_11 , false , NULL ) ;
F_42 ( V_11 -> V_61 ) ;
V_11 -> V_61 = NULL ;
}
static int F_52 ( struct V_13 * V_11 )
{
T_7 * V_104 ;
struct V_105 * V_106 ;
T_7 V_107 , V_108 ;
V_106 = & V_11 -> V_106 ;
V_104 = V_11 -> V_38 . V_22 ;
V_108 = V_104 [ V_109 ] ;
if ( V_108 == V_110 )
return 0 ;
F_53 () ;
#define F_54 ( T_8 , T_9 ) \
mac_stats->M = le64_to_cpu(dma_stats[MC_CMD_MAC_ ## D])
F_54 ( V_111 , V_112 ) ;
F_54 ( V_113 , V_114 ) ;
V_106 -> V_115 = ( V_106 -> V_111 -
V_106 -> V_113 ) ;
F_54 ( V_116 , V_117 ) ;
F_54 ( V_118 , V_119 ) ;
F_54 ( V_120 , V_121 ) ;
F_54 ( V_122 , V_123 ) ;
F_54 ( V_124 , V_125 ) ;
F_54 ( V_126 , V_127 ) ;
F_54 ( V_128 , V_129 ) ;
F_54 ( V_130 , V_131 ) ;
F_54 ( V_132 , V_133 ) ;
F_54 ( V_134 , V_135 ) ;
F_54 ( V_136 , V_137 ) ;
F_54 ( V_138 , V_139 ) ;
F_54 ( V_140 , V_141 ) ;
F_54 ( V_142 , V_143 ) ;
F_54 ( V_144 , V_145 ) ;
F_54 ( V_146 , V_147 ) ;
V_106 -> V_148 = 0 ;
F_54 ( V_149 , V_150 ) ;
F_54 ( V_151 , V_152 ) ;
F_54 ( V_153 , V_154 ) ;
F_54 ( V_155 , V_156 ) ;
F_54 ( V_157 , V_158 ) ;
V_106 -> V_148 = ( V_106 -> V_149 +
V_106 -> V_151 +
V_106 -> V_153 +
V_106 -> V_157 ) ;
F_54 ( V_159 , V_160 ) ;
F_54 ( V_161 , V_162 ) ;
F_54 ( V_163 , V_164 ) ;
F_54 ( V_165 , V_166 ) ;
F_54 ( V_167 , V_168 ) ;
F_54 ( V_169 , V_170 ) ;
V_106 -> V_171 = ( V_106 -> V_167 -
V_106 -> V_169 ) ;
F_54 ( V_172 , V_173 ) ;
F_54 ( V_174 , V_175 ) ;
F_54 ( V_176 , V_177 ) ;
F_54 ( V_178 , V_179 ) ;
F_54 ( V_180 , V_181 ) ;
F_54 ( V_182 , V_183 ) ;
F_54 ( V_184 , V_185 ) ;
F_54 ( V_186 , V_187 ) ;
F_54 ( V_188 , V_189 ) ;
F_54 ( V_190 , V_191 ) ;
F_54 ( V_192 , V_193 ) ;
F_54 ( V_194 , V_195 ) ;
F_54 ( V_196 , V_197 ) ;
F_54 ( V_198 , V_199 ) ;
F_54 ( V_200 , V_201 ) ;
F_54 ( V_202 , V_203 ) ;
F_54 ( V_204 , V_205 ) ;
V_106 -> V_206 = 0 ;
V_106 -> V_207 = 0 ;
V_106 -> V_208 = 0 ;
F_54 ( V_209 , V_210 ) ;
F_54 ( V_211 , V_212 ) ;
V_106 -> V_213 = 0 ;
F_54 ( V_214 , V_215 ) ;
F_54 ( V_216 , V_217 ) ;
F_54 ( V_218 , V_219 ) ;
F_54 ( V_220 , V_221 ) ;
F_54 ( V_222 , V_223 ) ;
V_106 -> V_224 = 0 ;
V_11 -> V_225 =
F_55 ( V_104 [ V_226 ] ) ;
#undef F_54
F_53 () ;
V_107 = V_104 [ V_227 ] ;
if ( V_108 != V_107 )
return - V_228 ;
return 0 ;
}
static void F_56 ( struct V_13 * V_11 )
{
int V_229 ;
for ( V_229 = 0 ; V_229 < 100 ; ++ V_229 ) {
if ( F_52 ( V_11 ) == 0 )
return;
F_57 ( 100 ) ;
}
}
static void F_58 ( struct V_13 * V_11 )
{
T_7 * V_104 = V_11 -> V_38 . V_22 ;
V_104 [ V_109 ] = V_110 ;
F_18 ( V_11 , V_11 -> V_38 . V_41 ,
V_39 * sizeof( V_40 ) , 1 , 0 ) ;
}
static void F_59 ( struct V_13 * V_11 )
{
F_18 ( V_11 , V_11 -> V_38 . V_41 , 0 , 0 , 0 ) ;
}
static void F_60 ( struct V_13 * V_11 , struct V_230 * V_231 )
{
struct V_60 * V_61 = V_11 -> V_61 ;
V_231 -> V_232 = V_233 ;
if ( V_61 -> V_234 != - 1 )
V_231 -> V_235 = V_233 ;
else
V_231 -> V_235 = 0 ;
memset ( & V_231 -> V_236 , 0 , sizeof( V_231 -> V_236 ) ) ;
}
static int F_61 ( struct V_13 * V_11 , T_5 type )
{
struct V_60 * V_61 = V_11 -> V_61 ;
int V_25 ;
if ( type & ~ V_233 )
return - V_57 ;
if ( type & V_233 ) {
if ( V_61 -> V_234 != - 1 )
F_62 ( V_11 ,
V_61 -> V_234 ) ;
V_25 = F_63 ( V_11 , V_11 -> V_19 -> V_237 ,
& V_61 -> V_234 ) ;
if ( V_25 )
goto V_238;
F_64 ( V_11 -> V_239 , true ) ;
} else {
V_25 = F_65 ( V_11 ) ;
V_61 -> V_234 = - 1 ;
F_64 ( V_11 -> V_239 , false ) ;
if ( V_25 )
goto V_238;
}
return 0 ;
V_238:
F_35 ( V_11 , V_240 , V_11 -> V_19 , L_8 ,
V_241 , type , V_25 ) ;
return V_25 ;
}
static void F_40 ( struct V_13 * V_11 )
{
struct V_60 * V_61 = V_11 -> V_61 ;
int V_25 ;
V_25 = F_66 ( V_11 , & V_61 -> V_234 ) ;
if ( V_25 != 0 ) {
F_65 ( V_11 ) ;
V_61 -> V_234 = - 1 ;
} else if ( V_61 -> V_234 != - 1 ) {
F_64 ( V_11 -> V_239 , true ) ;
}
}
