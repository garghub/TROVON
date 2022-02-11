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
static int F_16 ( struct V_17 * V_9 )
{
return F_17 ( V_9 , V_36 ,
F_18 ( V_36 ) ) ;
}
static enum V_37 F_19 ( enum V_37 V_38 )
{
return V_39 ;
}
static int F_20 ( T_5 * V_40 )
{
enum {
V_41 = ( V_42 | V_43 |
V_44 | V_45 |
V_46 ) ,
V_47 = ( V_41 |
V_48 << V_49 ) ,
};
if ( ( * V_40 & V_47 ) == V_47 ) {
* V_40 &= ~ V_47 ;
return V_50 ;
}
if ( ( * V_40 & V_41 ) == V_41 ) {
* V_40 &= ~ V_41 ;
return V_39 ;
}
return - V_51 ;
}
static int F_21 ( struct V_17 * V_9 , enum V_37 V_52 )
{
int V_19 ;
V_19 = F_22 ( V_9 ) ;
if ( V_19 )
return V_19 ;
if ( V_52 == V_50 )
return F_23 ( V_9 ) ;
else
return F_24 ( V_9 ) ;
}
static int F_25 ( struct V_17 * V_9 )
{
T_5 V_53 = 0 ;
int V_19 ;
V_19 = F_26 ( V_9 , V_9 -> V_12 -> V_54 , NULL , & V_53 ) ;
V_9 -> V_55 =
( V_53 & ( 1 << V_56 ) ) ?
3072 : 6144 ;
return V_19 ;
}
static void F_27 ( struct V_17 * V_9 )
{
F_28 ( V_9 , V_57 / 2 ) ;
}
static int F_29 ( struct V_17 * V_9 )
{
struct V_58 * V_59 ;
bool V_60 = false ;
T_6 V_61 ;
int V_19 ;
V_59 = F_30 ( sizeof( struct V_58 ) , V_62 ) ;
if ( ! V_59 )
return - V_63 ;
V_9 -> V_59 = V_59 ;
if ( F_31 ( V_9 ) != 0 ) {
F_32 ( V_9 , V_31 , V_9 -> V_12 ,
L_2 ) ;
V_19 = - V_64 ;
goto V_65;
}
F_33 ( V_9 , & V_61 , V_66 ) ;
V_9 -> V_12 -> V_67 = F_34 ( V_61 , V_68 ) - 1 ;
F_35 ( V_9 ) ;
V_19 = F_22 ( V_9 ) ;
if ( V_19 )
goto V_65;
V_19 = F_36 ( V_9 , true , & V_60 ) ;
if ( V_19 ) {
F_32 ( V_9 , V_31 , V_9 -> V_12 ,
L_3 ) ;
goto V_69;
}
if ( V_60 )
F_32 ( V_9 , V_31 , V_9 -> V_12 ,
L_4 ) ;
V_19 = F_21 ( V_9 , V_39 ) ;
if ( V_19 ) {
F_32 ( V_9 , V_31 , V_9 -> V_12 , L_5 ) ;
goto V_70;
}
F_37 ( V_9 ) ;
V_19 = F_10 ( V_9 , & V_9 -> V_71 , sizeof( T_6 ) ) ;
if ( V_19 )
goto V_72;
F_38 ( V_9 -> V_71 . V_35 & 0x0f ) ;
F_11 ( V_9 , V_31 , V_9 -> V_12 ,
L_6 ,
( unsigned long long ) V_9 -> V_71 . V_35 ,
V_9 -> V_71 . V_15 ,
( unsigned long long ) F_12 ( V_9 -> V_71 . V_15 ) ) ;
V_19 = F_25 ( V_9 ) ;
if ( V_19 == - V_51 ) {
F_32 ( V_9 , V_31 , V_9 -> V_12 ,
L_7 ) ;
V_9 -> V_73 = V_74 ;
V_9 -> V_25 . V_13 = V_75 ;
} else if ( V_19 ) {
goto V_76;
}
V_19 = F_39 ( V_9 ) ;
if ( V_19 )
goto V_76;
F_40 ( V_9 ) ;
return 0 ;
V_76:
F_15 ( V_9 , & V_9 -> V_71 ) ;
V_72:
V_70:
F_36 ( V_9 , false , NULL ) ;
V_69:
V_65:
F_41 ( V_9 -> V_59 ) ;
return V_19 ;
}
static int F_42 ( struct V_17 * V_9 )
{
T_6 V_77 ;
int V_19 ;
V_19 = F_22 ( V_9 ) ;
if ( V_19 )
return V_19 ;
F_33 ( V_9 , & V_77 , V_78 ) ;
F_43 ( V_77 , V_79 , 1 ) ;
F_44 ( V_9 , & V_77 , V_78 ) ;
F_33 ( V_9 , & V_77 , V_80 ) ;
F_43 ( V_77 , V_81 , 0 ) ;
F_43 ( V_77 , V_82 , 1 ) ;
F_44 ( V_9 , & V_77 , V_80 ) ;
F_33 ( V_9 , & V_77 , V_83 ) ;
F_43 ( V_77 , V_84 , 0 ) ;
F_43 ( V_77 , V_85 , 1 ) ;
F_43 ( V_77 , V_86 , 1 ) ;
F_43 ( V_77 , V_87 , 1 ) ;
F_43 ( V_77 , V_88 , 1 ) ;
F_44 ( V_9 , & V_77 , V_83 ) ;
memcpy ( & V_77 , V_9 -> V_89 , sizeof( V_77 ) ) ;
F_44 ( V_9 , & V_77 , V_90 ) ;
F_45 ( sizeof( V_9 -> V_89 ) <
2 * sizeof( V_77 ) + V_91 / 8 ||
V_92 != 0 ) ;
memcpy ( & V_77 , V_9 -> V_89 , sizeof( V_77 ) ) ;
F_44 ( V_9 , & V_77 , V_93 ) ;
memcpy ( & V_77 , V_9 -> V_89 + sizeof( V_77 ) , sizeof( V_77 ) ) ;
F_44 ( V_9 , & V_77 , V_94 ) ;
F_46 ( V_77 , V_95 , 1 ,
V_96 , 1 ) ;
memcpy ( & V_77 , V_9 -> V_89 + 2 * sizeof( V_77 ) ,
V_91 / 8 ) ;
F_44 ( V_9 , & V_77 , V_97 ) ;
V_19 = F_47 ( V_9 , true , false , 0 ) ;
if ( V_19 )
return V_19 ;
F_48 ( V_77 , V_98 , 0 ) ;
F_44 ( V_9 , & V_77 , V_99 ) ;
F_48 ( V_77 , V_100 , 1 ) ;
F_44 ( V_9 , & V_77 , V_101 ) ;
F_49 ( V_9 ) ;
return 0 ;
}
static void F_50 ( struct V_17 * V_9 )
{
F_51 ( V_9 ) ;
F_15 ( V_9 , & V_9 -> V_71 ) ;
F_21 ( V_9 , V_39 ) ;
F_36 ( V_9 , false , NULL ) ;
F_41 ( V_9 -> V_59 ) ;
V_9 -> V_59 = NULL ;
}
static int F_52 ( struct V_17 * V_9 )
{
T_7 * V_102 ;
struct V_103 * V_104 ;
T_7 V_105 , V_106 ;
V_104 = & V_9 -> V_104 ;
V_102 = V_9 -> V_32 . V_15 ;
V_106 = V_102 [ V_107 ] ;
if ( V_106 == V_108 )
return 0 ;
F_53 () ;
#define F_54 ( T_8 , T_9 ) \
mac_stats->M = le64_to_cpu(dma_stats[MC_CMD_MAC_ ## D])
F_54 ( V_109 , V_110 ) ;
F_54 ( V_111 , V_112 ) ;
V_104 -> V_113 = ( V_104 -> V_109 -
V_104 -> V_111 ) ;
F_54 ( V_114 , V_115 ) ;
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
V_104 -> V_146 = 0 ;
F_54 ( V_147 , V_148 ) ;
F_54 ( V_149 , V_150 ) ;
F_54 ( V_151 , V_152 ) ;
F_54 ( V_153 , V_154 ) ;
F_54 ( V_155 , V_156 ) ;
V_104 -> V_146 = ( V_104 -> V_147 +
V_104 -> V_149 +
V_104 -> V_151 +
V_104 -> V_155 ) ;
F_54 ( V_157 , V_158 ) ;
F_54 ( V_159 , V_160 ) ;
F_54 ( V_161 , V_162 ) ;
F_54 ( V_163 , V_164 ) ;
F_54 ( V_165 , V_166 ) ;
F_54 ( V_167 , V_168 ) ;
V_104 -> V_169 = ( V_104 -> V_165 -
V_104 -> V_167 ) ;
F_54 ( V_170 , V_171 ) ;
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
V_104 -> V_204 = 0 ;
V_104 -> V_205 = 0 ;
V_104 -> V_206 = 0 ;
F_54 ( V_207 , V_208 ) ;
F_54 ( V_209 , V_210 ) ;
V_104 -> V_211 = 0 ;
F_54 ( V_212 , V_213 ) ;
F_54 ( V_214 , V_215 ) ;
F_54 ( V_216 , V_217 ) ;
F_54 ( V_218 , V_219 ) ;
F_54 ( V_220 , V_221 ) ;
V_104 -> V_222 = 0 ;
V_9 -> V_223 =
F_55 ( V_102 [ V_224 ] ) ;
#undef F_54
F_53 () ;
V_105 = V_102 [ V_225 ] ;
if ( V_106 != V_105 )
return - V_226 ;
return 0 ;
}
static void F_56 ( struct V_17 * V_9 )
{
int V_227 ;
for ( V_227 = 0 ; V_227 < 100 ; ++ V_227 ) {
if ( F_52 ( V_9 ) == 0 )
return;
F_57 ( 100 ) ;
}
}
static void F_58 ( struct V_17 * V_9 )
{
T_7 * V_102 = V_9 -> V_32 . V_15 ;
V_102 [ V_107 ] = V_108 ;
F_13 ( V_9 , V_9 -> V_32 . V_35 ,
V_33 * sizeof( V_34 ) , 1 , 0 ) ;
}
static void F_59 ( struct V_17 * V_9 )
{
F_13 ( V_9 , V_9 -> V_32 . V_35 , 0 , 0 , 0 ) ;
}
static void F_60 ( struct V_17 * V_9 , struct V_228 * V_229 )
{
struct V_58 * V_59 = V_9 -> V_59 ;
V_229 -> V_230 = V_231 ;
if ( V_59 -> V_232 != - 1 )
V_229 -> V_233 = V_231 ;
else
V_229 -> V_233 = 0 ;
memset ( & V_229 -> V_234 , 0 , sizeof( V_229 -> V_234 ) ) ;
}
static int F_61 ( struct V_17 * V_9 , T_5 type )
{
struct V_58 * V_59 = V_9 -> V_59 ;
int V_19 ;
if ( type & ~ V_231 )
return - V_51 ;
if ( type & V_231 ) {
if ( V_59 -> V_232 != - 1 )
F_62 ( V_9 ,
V_59 -> V_232 ) ;
V_19 = F_63 ( V_9 , V_9 -> V_12 -> V_235 ,
& V_59 -> V_232 ) ;
if ( V_19 )
goto V_236;
F_64 ( V_9 -> V_237 , true ) ;
} else {
V_19 = F_65 ( V_9 ) ;
V_59 -> V_232 = - 1 ;
F_64 ( V_9 -> V_237 , false ) ;
if ( V_19 )
goto V_236;
}
return 0 ;
V_236:
F_32 ( V_9 , V_238 , V_9 -> V_12 , L_8 ,
V_239 , type , V_19 ) ;
return V_19 ;
}
static void F_37 ( struct V_17 * V_9 )
{
struct V_58 * V_59 = V_9 -> V_59 ;
int V_19 ;
V_19 = F_66 ( V_9 , & V_59 -> V_232 ) ;
if ( V_19 != 0 ) {
F_65 ( V_9 ) ;
V_59 -> V_232 = - 1 ;
} else if ( V_59 -> V_232 != - 1 ) {
F_64 ( V_9 -> V_237 , true ) ;
}
}
