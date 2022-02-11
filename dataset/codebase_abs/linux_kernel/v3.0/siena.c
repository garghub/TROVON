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
static void F_4 ( struct V_11 * V_9 )
{
F_5 ( ! F_6 ( & V_9 -> V_12 ) ) ;
F_7 ( V_9 , V_13 ,
V_9 -> V_14 . V_15 , sizeof( V_9 -> V_14 ) ,
NULL , 0 , NULL ) ;
}
static int F_8 ( struct V_16 * V_17 ,
int V_18 , int V_19 , T_2 V_20 , T_2 V_21 )
{
struct V_11 * V_9 = F_9 ( V_17 ) ;
T_3 V_22 ;
int V_23 ;
V_23 = F_10 ( V_9 , V_9 -> V_24 , V_18 , V_19 ,
V_20 , V_21 , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 != V_25 )
return - V_26 ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 ,
int V_18 , int V_19 , T_2 V_20 )
{
struct V_11 * V_9 = F_9 ( V_17 ) ;
T_4 V_21 ;
T_3 V_22 ;
int V_23 ;
V_23 = F_12 ( V_9 , V_9 -> V_24 , V_18 , V_19 ,
V_20 , & V_21 , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 != V_25 )
return - V_26 ;
return ( int ) V_21 ;
}
static int F_13 ( struct V_11 * V_9 )
{
int V_23 ;
V_9 -> V_27 = & V_28 ;
V_9 -> V_29 . V_30 = V_31 | V_32 ;
V_9 -> V_29 . V_33 = F_11 ;
V_9 -> V_29 . V_34 = F_8 ;
V_23 = V_9 -> V_27 -> V_35 ( V_9 ) ;
if ( V_23 != 0 )
return V_23 ;
V_23 = F_14 ( V_9 , & V_9 -> V_36 ,
V_37 * sizeof( V_38 ) ) ;
if ( V_23 )
return V_23 ;
F_15 ( V_9 , V_35 , V_9 -> V_17 ,
L_1 ,
( V_38 ) V_9 -> V_36 . V_39 ,
V_9 -> V_36 . V_20 ,
( V_38 ) F_16 ( V_9 -> V_36 . V_20 ) ) ;
F_17 ( V_9 , V_9 -> V_36 . V_39 , 0 , 0 , 1 ) ;
return 0 ;
}
static void F_18 ( struct V_11 * V_9 )
{
V_9 -> V_27 -> remove ( V_9 ) ;
F_19 ( V_9 , & V_9 -> V_36 ) ;
}
static int F_20 ( struct V_11 * V_9 )
{
return F_21 ( V_9 , V_40 ,
F_22 ( V_40 ) ) ;
}
static int F_23 ( struct V_11 * V_9 , enum V_41 V_42 )
{
int V_23 ;
V_23 = F_24 ( V_9 ) ;
if ( V_23 )
return V_23 ;
if ( V_42 == V_43 )
return F_25 ( V_9 ) ;
else
return F_26 ( V_9 ) ;
}
static int F_27 ( struct V_11 * V_9 )
{
return F_28 ( V_9 , V_9 -> V_17 -> V_44 , NULL ) ;
}
static int F_29 ( struct V_11 * V_9 )
{
struct V_45 * V_46 ;
bool V_47 = 0 ;
T_5 V_48 ;
int V_23 ;
V_46 = F_30 ( sizeof( struct V_45 ) , V_49 ) ;
if ( ! V_46 )
return - V_50 ;
V_9 -> V_46 = V_46 ;
if ( F_31 ( V_9 ) != 0 ) {
F_32 ( V_9 , V_35 , V_9 -> V_17 ,
L_2 ) ;
V_23 = - V_51 ;
goto V_52;
}
F_33 ( V_9 , & V_48 , V_53 ) ;
V_9 -> V_17 -> V_54 = F_34 ( V_48 , V_55 ) - 1 ;
V_46 -> V_56 = F_35 ( V_9 -> V_57 +
V_58 ,
V_59 *
V_60 ) ;
if ( ! V_46 -> V_56 ) {
F_32 ( V_9 , V_35 , V_9 -> V_17 ,
L_3 ,
( unsigned long long ) V_9 -> V_57 +
V_58 ,
V_59 * V_60 ) ;
V_23 = - V_50 ;
goto V_52;
}
F_36 ( V_9 ) ;
V_23 = F_24 ( V_9 ) ;
if ( V_23 )
goto V_61;
V_23 = F_37 ( V_9 , true , & V_47 ) ;
if ( V_23 ) {
F_32 ( V_9 , V_35 , V_9 -> V_17 ,
L_4 ) ;
goto V_61;
}
if ( V_47 )
F_32 ( V_9 , V_35 , V_9 -> V_17 ,
L_5 ) ;
V_23 = F_23 ( V_9 , V_62 ) ;
if ( V_23 ) {
F_32 ( V_9 , V_35 , V_9 -> V_17 , L_6 ) ;
goto V_63;
}
F_38 ( V_9 ) ;
V_23 = F_14 ( V_9 , & V_9 -> V_64 , sizeof( T_5 ) ) ;
if ( V_23 )
goto V_65;
F_39 ( V_9 -> V_64 . V_39 & 0x0f ) ;
F_15 ( V_9 , V_35 , V_9 -> V_17 ,
L_7 ,
( unsigned long long ) V_9 -> V_64 . V_39 ,
V_9 -> V_64 . V_20 ,
( unsigned long long ) F_16 ( V_9 -> V_64 . V_20 ) ) ;
V_23 = F_27 ( V_9 ) ;
if ( V_23 == - V_66 ) {
F_32 ( V_9 , V_35 , V_9 -> V_17 ,
L_8 ) ;
V_9 -> V_67 = V_68 ;
V_9 -> V_29 . V_18 = V_69 ;
} else if ( V_23 ) {
goto V_70;
}
return 0 ;
V_70:
F_19 ( V_9 , & V_9 -> V_64 ) ;
V_65:
V_63:
F_37 ( V_9 , false , NULL ) ;
V_61:
F_40 ( V_46 -> V_56 ) ;
V_52:
F_41 ( V_9 -> V_46 ) ;
return V_23 ;
}
static int F_42 ( struct V_11 * V_9 )
{
T_5 V_71 ;
int V_23 ;
V_23 = F_24 ( V_9 ) ;
if ( V_23 )
return V_23 ;
F_33 ( V_9 , & V_71 , V_72 ) ;
F_43 ( V_71 , V_73 , 1 ) ;
F_44 ( V_9 , & V_71 , V_72 ) ;
F_33 ( V_9 , & V_71 , V_74 ) ;
F_43 ( V_71 , V_75 , 0 ) ;
F_43 ( V_71 , V_76 , 1 ) ;
F_44 ( V_9 , & V_71 , V_74 ) ;
F_33 ( V_9 , & V_71 , V_77 ) ;
F_43 ( V_71 , V_78 , 0 ) ;
F_43 ( V_71 , V_79 , 1 ) ;
F_43 ( V_71 , V_80 , 1 ) ;
F_43 ( V_71 , V_81 , 1 ) ;
F_43 ( V_71 , V_82 , 1 ) ;
F_44 ( V_9 , & V_71 , V_77 ) ;
memcpy ( & V_71 , V_9 -> V_83 , sizeof( V_71 ) ) ;
F_44 ( V_9 , & V_71 , V_84 ) ;
F_45 ( sizeof( V_9 -> V_83 ) <
2 * sizeof( V_71 ) + V_85 / 8 ||
V_86 != 0 ) ;
memcpy ( & V_71 , V_9 -> V_83 , sizeof( V_71 ) ) ;
F_44 ( V_9 , & V_71 , V_87 ) ;
memcpy ( & V_71 , V_9 -> V_83 + sizeof( V_71 ) , sizeof( V_71 ) ) ;
F_44 ( V_9 , & V_71 , V_88 ) ;
F_46 ( V_71 , V_89 , 1 ,
V_90 , 1 ) ;
memcpy ( & V_71 , V_9 -> V_83 + 2 * sizeof( V_71 ) ,
V_85 / 8 ) ;
F_44 ( V_9 , & V_71 , V_91 ) ;
V_23 = F_47 ( V_9 , true , false , 0 ) ;
if ( V_23 )
return V_23 ;
F_48 ( V_71 , V_92 , 0 ) ;
F_44 ( V_9 , & V_71 , V_93 ) ;
F_48 ( V_71 , V_94 , 1 ) ;
F_44 ( V_9 , & V_71 , V_95 ) ;
F_49 ( V_9 ) ;
return 0 ;
}
static void F_50 ( struct V_11 * V_9 )
{
struct V_45 * V_46 = V_9 -> V_46 ;
F_19 ( V_9 , & V_9 -> V_64 ) ;
F_23 ( V_9 , V_62 ) ;
if ( F_51 ( V_9 ) )
F_37 ( V_9 , false , NULL ) ;
F_40 ( V_46 -> V_56 ) ;
F_41 ( V_46 ) ;
V_9 -> V_46 = NULL ;
}
static int F_52 ( struct V_11 * V_9 )
{
V_38 * V_96 ;
struct V_97 * V_98 ;
V_38 V_99 ;
V_38 V_100 ;
V_98 = & V_9 -> V_98 ;
V_96 = ( V_38 * ) V_9 -> V_36 . V_20 ;
V_100 = V_96 [ V_101 ] ;
if ( V_100 == V_102 )
return 0 ;
F_53 () ;
#define F_54 ( T_6 , T_7 ) \
mac_stats->M = dma_stats[MC_CMD_MAC_ ## D]
F_54 ( V_103 , V_104 ) ;
F_54 ( V_105 , V_106 ) ;
V_98 -> V_107 = ( V_98 -> V_103 -
V_98 -> V_105 ) ;
F_54 ( V_108 , V_109 ) ;
F_54 ( V_110 , V_111 ) ;
F_54 ( V_112 , V_113 ) ;
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
V_98 -> V_140 = 0 ;
F_54 ( V_141 , V_142 ) ;
F_54 ( V_143 , V_144 ) ;
F_54 ( V_145 , V_146 ) ;
F_54 ( V_147 , V_148 ) ;
F_54 ( V_149 , V_150 ) ;
V_98 -> V_140 = ( V_98 -> V_141 +
V_98 -> V_143 +
V_98 -> V_145 +
V_98 -> V_149 ) ;
F_54 ( V_151 , V_152 ) ;
F_54 ( V_153 , V_154 ) ;
F_54 ( V_155 , V_156 ) ;
F_54 ( V_157 , V_158 ) ;
F_54 ( V_159 , V_160 ) ;
F_54 ( V_161 , V_162 ) ;
V_98 -> V_163 = ( V_98 -> V_159 -
V_98 -> V_161 ) ;
F_54 ( V_164 , V_165 ) ;
F_54 ( V_166 , V_167 ) ;
F_54 ( V_168 , V_169 ) ;
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
V_98 -> V_198 = 0 ;
V_98 -> V_199 = 0 ;
V_98 -> V_200 = 0 ;
F_54 ( V_201 , V_202 ) ;
F_54 ( V_203 , V_204 ) ;
V_98 -> V_205 = 0 ;
F_54 ( V_206 , V_207 ) ;
F_54 ( V_208 , V_209 ) ;
F_54 ( V_210 , V_211 ) ;
F_54 ( V_212 , V_213 ) ;
F_54 ( V_214 , V_215 ) ;
V_98 -> V_216 = 0 ;
V_9 -> V_217 = V_96 [ V_218 ] ;
#undef F_54
F_53 () ;
V_99 = V_96 [ V_219 ] ;
if ( V_100 != V_99 )
return - V_220 ;
return 0 ;
}
static void F_55 ( struct V_11 * V_9 )
{
int V_221 ;
for ( V_221 = 0 ; V_221 < 100 ; ++ V_221 ) {
if ( F_52 ( V_9 ) == 0 )
return;
F_56 ( 100 ) ;
}
}
static void F_57 ( struct V_11 * V_9 )
{
V_38 * V_96 = ( V_38 * ) V_9 -> V_36 . V_20 ;
V_96 [ V_101 ] = V_102 ;
F_17 ( V_9 , V_9 -> V_36 . V_39 ,
V_37 * sizeof( V_38 ) , 1 , 0 ) ;
}
static void F_58 ( struct V_11 * V_9 )
{
F_17 ( V_9 , V_9 -> V_36 . V_39 , 0 , 0 , 0 ) ;
}
static void F_59 ( struct V_11 * V_9 , struct V_222 * V_223 )
{
struct V_45 * V_46 = V_9 -> V_46 ;
V_223 -> V_224 = V_225 ;
if ( V_46 -> V_226 != - 1 )
V_223 -> V_227 = V_225 ;
else
V_223 -> V_227 = 0 ;
memset ( & V_223 -> V_228 , 0 , sizeof( V_223 -> V_228 ) ) ;
}
static int F_60 ( struct V_11 * V_9 , T_8 type )
{
struct V_45 * V_46 = V_9 -> V_46 ;
int V_23 ;
if ( type & ~ V_225 )
return - V_66 ;
if ( type & V_225 ) {
if ( V_46 -> V_226 != - 1 )
F_61 ( V_9 ,
V_46 -> V_226 ) ;
V_23 = F_62 ( V_9 , V_9 -> V_17 -> V_229 ,
& V_46 -> V_226 ) ;
if ( V_23 )
goto V_230;
F_63 ( V_9 -> V_231 , true ) ;
} else {
V_23 = F_64 ( V_9 ) ;
V_46 -> V_226 = - 1 ;
F_63 ( V_9 -> V_231 , false ) ;
if ( V_23 )
goto V_230;
}
return 0 ;
V_230:
F_32 ( V_9 , V_232 , V_9 -> V_17 , L_9 ,
V_233 , type , V_23 ) ;
return V_23 ;
}
static void F_38 ( struct V_11 * V_9 )
{
struct V_45 * V_46 = V_9 -> V_46 ;
int V_23 ;
V_23 = F_65 ( V_9 , & V_46 -> V_226 ) ;
if ( V_23 != 0 ) {
F_64 ( V_9 ) ;
V_46 -> V_226 = - 1 ;
} else if ( V_46 -> V_226 != - 1 ) {
F_63 ( V_9 -> V_231 , true ) ;
}
}
