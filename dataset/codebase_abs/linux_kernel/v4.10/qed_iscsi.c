static int
F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
struct V_5 * V_6 ,
void * V_7 , T_1 V_8 )
{
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 V_20 ;
int V_21 = 0 ;
T_2 V_22 ;
T_3 V_23 ;
T_4 V_24 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_25 = F_2 ( V_2 ) ;
V_20 . V_26 = V_2 -> V_27 . V_26 ;
V_20 . V_4 = V_4 ;
V_20 . V_28 = V_6 ;
V_21 = F_3 ( V_2 , & V_18 ,
V_29 ,
V_30 , & V_20 ) ;
if ( V_21 )
return V_21 ;
V_10 = & V_18 -> V_31 . V_32 ;
V_16 = & V_10 -> V_33 ;
V_14 = & V_2 -> V_34 . V_35 ;
V_12 = & V_16 -> V_36 ;
F_4 ( V_16 -> V_37 . V_38 ,
V_39 , V_40 ) ;
V_16 -> V_37 . V_41 = V_29 ;
V_23 = V_14 -> V_42 ;
V_16 -> V_42 = F_5 ( V_23 ) ;
V_16 -> V_43 = V_14 -> V_43 ;
V_16 -> V_44 = V_14 -> V_44 ;
V_16 -> V_45 = V_14 -> V_45 ;
V_16 -> V_46 . V_47 = V_14 -> V_47 ;
V_23 = V_14 -> V_48 ;
V_16 -> V_46 . V_48 = F_5 ( V_23 ) ;
V_16 -> V_49 . V_38 = V_14 -> V_49 ;
F_6 ( V_12 -> V_50 ,
V_14 -> V_50 ) ;
V_23 = V_14 -> V_51 ;
V_12 -> V_51 = F_5 ( V_23 ) ;
V_23 = V_14 -> V_52 ;
V_12 -> V_52 = F_5 ( V_23 ) ;
V_12 -> V_53 = V_14 -> V_53 ;
V_22 = ( T_4 ) V_2 -> V_27 . V_54 [ V_55 ] ;
V_12 -> V_56 = ( T_4 ) V_22 ;
V_12 -> V_57 = V_14 -> V_58 ;
V_12 -> V_59 = V_14 -> V_60 ;
for ( V_24 = 0 ; V_24 < V_14 -> V_53 ; V_24 ++ ) {
V_23 = V_2 -> V_61 [ V_24 ] -> V_62 ;
V_12 -> V_63 [ V_24 ] = F_5 ( V_23 ) ;
}
V_12 -> V_64 = F_7 ( V_2 -> V_65 ) ;
F_6 ( V_12 -> V_66 [ V_67 ] ,
V_14 -> V_68 [ V_67 ] ) ;
V_12 -> V_69 [ V_67 ] =
V_14 -> V_69 [ V_67 ] ;
V_23 = V_14 -> V_70 [ V_67 ] ;
V_12 -> V_70 [ V_67 ] = F_5 ( V_23 ) ;
V_23 = V_14 -> V_71 [ V_67 ] ;
V_12 -> V_71 [ V_67 ] = F_5 ( V_23 ) ;
F_6 ( V_12 -> V_66 [ V_72 ] ,
V_14 -> V_68 [ V_72 ] ) ;
V_12 -> V_69 [ V_72 ] =
V_14 -> V_69 [ V_72 ] ;
V_23 = V_14 -> V_70 [ V_72 ] ;
V_12 -> V_70 [ V_72 ] = F_5 ( V_23 ) ;
V_23 = V_14 -> V_71 [ V_72 ] ;
V_12 -> V_71 [ V_72 ] = F_5 ( V_23 ) ;
V_23 = V_14 -> V_73 ;
V_12 -> V_73 = F_5 ( V_23 ) ;
if ( V_14 -> V_74 ) {
F_4 ( V_12 -> V_75 ,
V_76 , 1 ) ;
if ( V_12 -> V_69 [ V_72 ] )
F_4 ( V_12 -> V_75 ,
V_77 , 1 ) ;
F_4 ( V_12 -> V_75 ,
V_78 , 1 ) ;
} else {
F_4 ( V_12 -> V_75 ,
V_76 , 1 ) ;
}
V_10 -> V_79 . V_80 = F_8 ( V_14 -> V_80 ) ;
V_23 = V_14 -> V_81 ;
V_10 -> V_79 . V_81 = F_5 ( V_23 ) ;
V_10 -> V_79 . V_82 = V_14 -> V_83 ;
V_2 -> V_84 -> V_7 = V_7 ;
V_2 -> V_84 -> V_85 = V_8 ;
return F_9 ( V_2 , V_18 , NULL ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
enum V_3 V_4 ,
struct V_5 * V_6 )
{
struct V_88 * V_10 = NULL ;
struct V_89 * V_90 = NULL ;
struct V_91 * V_92 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 V_20 ;
union V_93 V_94 ;
T_3 V_95 = 0 , V_96 = 0 ;
T_5 V_97 ;
T_5 V_98 ;
T_5 V_99 ;
int V_21 = 0 ;
T_2 V_22 ;
T_3 V_100 ;
T_4 V_24 ;
T_3 * V_101 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_25 = V_87 -> V_102 ;
V_20 . V_26 = V_2 -> V_27 . V_26 ;
V_20 . V_4 = V_4 ;
V_20 . V_28 = V_6 ;
V_21 = F_3 ( V_2 , & V_18 ,
V_103 ,
V_30 , & V_20 ) ;
if ( V_21 )
return V_21 ;
V_10 = & V_18 -> V_31 . V_104 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_95 = F_11 ( V_2 , V_30 , & V_94 ) ;
V_87 -> V_105 = F_5 ( V_95 ) ;
V_10 -> V_106 . V_105 = F_5 ( V_95 ) ;
V_94 . V_106 . V_107 = 1 ;
V_96 = F_11 ( V_2 , V_30 , & V_94 ) ;
V_87 -> V_108 = F_5 ( V_96 ) ;
V_10 -> V_106 . V_108 = F_5 ( V_96 ) ;
V_10 -> V_37 . V_41 = V_103 ;
F_4 ( V_10 -> V_37 . V_38 , V_39 ,
V_87 -> V_109 ) ;
V_10 -> V_110 = F_5 ( V_87 -> V_110 ) ;
V_10 -> V_111 = F_8 ( V_87 -> V_102 ) ;
F_6 ( V_10 -> V_106 . V_112 , V_87 -> V_112 ) ;
V_97 = F_12 ( & V_87 -> V_113 ) ;
F_6 ( V_10 -> V_106 . V_97 , V_97 ) ;
V_98 = F_12 ( & V_87 -> V_114 ) ;
F_6 ( V_10 -> V_106 . V_98 , V_98 ) ;
V_99 = F_12 ( & V_87 -> V_115 ) ;
F_6 ( V_10 -> V_106 . V_99 , V_99 ) ;
V_10 -> V_106 . V_116 = F_8 ( V_87 -> V_116 ) ;
V_10 -> V_106 . V_38 = V_87 -> V_117 ;
V_10 -> V_106 . V_118 = V_87 -> V_118 ;
V_10 -> V_106 . V_119 = F_8 ( V_87 -> V_119 ) ;
if ( ! F_13 ( V_10 -> V_106 . V_38 ,
V_120 ) ) {
V_92 = & V_10 -> V_121 ;
V_101 = ( T_3 * ) V_87 -> V_122 ;
V_92 -> V_123 = F_14 ( F_15 ( V_101 ) ) ;
V_92 -> V_124 = F_14 ( F_15 ( V_101 + 1 ) ) ;
V_92 -> V_125 = F_14 ( F_15 ( V_101 + 2 ) ) ;
V_101 = ( T_3 * ) V_87 -> V_126 ;
V_92 -> V_127 = F_14 ( F_15 ( V_101 ) ) ;
V_92 -> V_128 = F_14 ( F_15 ( V_101 + 1 ) ) ;
V_92 -> V_129 = F_14 ( F_15 ( V_101 + 2 ) ) ;
V_92 -> V_130 = F_5 ( V_87 -> V_130 ) ;
V_92 -> V_38 = V_87 -> V_131 ;
V_92 -> V_132 = V_87 -> V_132 ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
V_22 = V_87 -> V_133 [ V_24 ] ;
V_92 -> V_133 [ V_24 ] = F_8 ( V_22 ) ;
V_22 = V_87 -> V_134 [ V_24 ] ;
V_92 -> V_134 [ V_24 ] = F_8 ( V_22 ) ;
}
V_92 -> V_135 = V_87 -> V_135 ;
V_92 -> V_136 = V_87 -> V_136 ;
V_92 -> V_137 = F_8 ( V_87 -> V_137 ) ;
V_92 -> V_138 = F_8 ( V_87 -> V_138 ) ;
V_92 -> V_139 = F_8 ( V_87 -> V_139 ) ;
V_92 -> V_140 = F_8 ( V_87 -> V_140 ) ;
V_92 -> V_141 = F_8 ( V_87 -> V_141 ) ;
V_92 -> V_142 = F_8 ( V_87 -> V_142 ) ;
V_92 -> V_143 = F_8 ( V_87 -> V_143 ) ;
V_92 -> V_144 = F_8 ( V_87 -> V_144 ) ;
V_92 -> V_145 = F_8 ( V_87 -> V_145 ) ;
V_92 -> V_146 = F_5 ( V_87 -> V_146 ) ;
V_92 -> V_147 = F_5 ( V_87 -> V_147 ) ;
V_92 -> V_148 = F_8 ( V_87 -> V_148 ) ;
V_92 -> V_149 = F_8 ( V_87 -> V_149 ) ;
V_92 -> V_150 = F_8 ( V_87 -> V_150 ) ;
V_92 -> V_151 = F_8 ( V_87 -> V_151 ) ;
V_22 = V_87 -> V_152 ;
V_92 -> V_152 = F_8 ( V_22 ) ;
V_22 = V_87 -> V_153 ;
V_92 -> V_153 = F_8 ( V_22 ) ;
V_92 -> V_154 = V_87 -> V_154 ;
V_92 -> V_155 = V_87 -> V_155 ;
V_92 -> V_156 = V_87 -> V_156 ;
V_92 -> V_157 = V_87 -> V_157 ;
V_92 -> V_158 = F_8 ( V_87 -> V_158 ) ;
V_92 -> V_159 = F_8 ( V_87 -> V_159 ) ;
V_92 -> V_160 = F_8 ( V_87 -> V_160 ) ;
V_92 -> V_161 = F_8 ( V_87 -> V_161 ) ;
V_22 = V_87 -> V_162 ;
V_92 -> V_162 = F_8 ( V_22 ) ;
V_92 -> V_163 = V_87 -> V_163 ;
V_92 -> V_164 = V_87 -> V_164 ;
V_92 -> V_165 = F_5 ( V_87 -> V_165 ) ;
V_92 -> V_166 = F_5 ( V_87 -> V_166 ) ;
V_92 -> V_167 = F_5 ( V_87 -> V_167 ) ;
V_92 -> V_168 = V_87 -> V_168 ;
V_92 -> V_169 = V_87 -> V_169 ;
V_22 = V_87 -> V_170 ;
V_92 -> V_170 = F_8 ( V_22 ) ;
V_100 = V_87 -> V_171 ;
V_92 -> V_171 = F_5 ( V_100 ) ;
V_92 -> V_172 = V_87 -> V_172 ;
V_92 -> V_173 = V_87 -> V_173 ;
} else {
V_90 =
& ( (struct V_174 * ) V_10 ) -> V_121 ;
V_101 = ( T_3 * ) V_87 -> V_122 ;
V_90 -> V_123 = F_14 ( F_15 ( V_101 ) ) ;
V_90 -> V_124 = F_14 ( F_15 ( V_101 + 1 ) ) ;
V_90 -> V_125 = F_14 ( F_15 ( V_101 + 2 ) ) ;
V_101 = ( T_3 * ) V_87 -> V_126 ;
V_90 -> V_127 = F_14 ( F_15 ( V_101 ) ) ;
V_90 -> V_128 = F_14 ( F_15 ( V_101 + 1 ) ) ;
V_90 -> V_129 = F_14 ( F_15 ( V_101 + 2 ) ) ;
V_90 -> V_130 = F_5 ( V_87 -> V_130 ) ;
V_90 -> V_38 = V_87 -> V_131 ;
V_90 -> V_132 = V_87 -> V_132 ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
V_22 = V_87 -> V_133 [ V_24 ] ;
V_90 -> V_133 [ V_24 ] = F_8 ( V_22 ) ;
V_22 = V_87 -> V_134 [ V_24 ] ;
V_90 -> V_134 [ V_24 ] = F_8 ( V_22 ) ;
}
V_90 -> V_158 = F_8 ( V_87 -> V_158 ) ;
V_90 -> V_163 = V_87 -> V_163 ;
V_90 -> V_164 = V_87 -> V_164 ;
V_90 -> V_165 = F_5 ( V_87 -> V_165 ) ;
V_90 -> V_166 = F_5 ( V_87 -> V_166 ) ;
V_90 -> V_167 = F_5 ( V_87 -> V_167 ) ;
V_90 -> V_169 = V_87 -> V_169 ;
V_90 -> V_173 = V_87 -> V_173 ;
V_100 = V_87 -> V_175 ;
V_90 -> V_175 = F_5 ( V_100 ) ;
V_90 -> V_176 = F_16 ( V_87 -> V_177 ) ;
V_90 -> V_178 = F_17 ( V_87 -> V_177 ) ;
}
return F_9 ( V_2 , V_18 , NULL ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
enum V_3 V_4 ,
struct V_5 * V_6 )
{
struct V_179 * V_10 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 V_20 ;
int V_21 = - V_180 ;
T_2 V_22 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_25 = V_87 -> V_102 ;
V_20 . V_26 = V_2 -> V_27 . V_26 ;
V_20 . V_4 = V_4 ;
V_20 . V_28 = V_6 ;
V_21 = F_3 ( V_2 , & V_18 ,
V_181 ,
V_30 , & V_20 ) ;
if ( V_21 )
return V_21 ;
V_10 = & V_18 -> V_31 . V_182 ;
V_10 -> V_37 . V_41 = V_181 ;
F_4 ( V_10 -> V_37 . V_38 ,
V_39 , V_87 -> V_109 ) ;
V_10 -> V_110 = F_5 ( V_87 -> V_110 ) ;
V_10 -> V_111 = F_8 ( V_87 -> V_102 ) ;
V_10 -> V_38 = V_87 -> V_183 ;
V_10 -> V_184 = F_8 ( V_87 -> V_184 ) ;
V_22 = V_87 -> V_185 ;
V_10 -> V_185 = F_8 ( V_22 ) ;
V_22 = V_87 -> V_186 ;
V_10 -> V_186 = F_8 ( V_22 ) ;
V_22 = V_87 -> V_187 ;
V_10 -> V_187 = F_8 ( V_22 ) ;
V_10 -> V_188 = F_8 ( V_87 -> V_188 ) ;
return F_9 ( V_2 , V_18 , NULL ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
enum V_3 V_4 ,
struct V_5 * V_6 )
{
struct V_189 * V_10 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 V_20 ;
int V_21 = - V_180 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_25 = V_87 -> V_102 ;
V_20 . V_26 = V_2 -> V_27 . V_26 ;
V_20 . V_4 = V_4 ;
V_20 . V_28 = V_6 ;
V_21 = F_3 ( V_2 , & V_18 ,
V_190 ,
V_30 , & V_20 ) ;
if ( V_21 )
return V_21 ;
V_10 = & V_18 -> V_31 . V_191 ;
V_10 -> V_37 . V_41 = V_190 ;
F_4 ( V_10 -> V_37 . V_38 ,
V_39 , V_87 -> V_109 ) ;
V_10 -> V_110 = F_5 ( V_87 -> V_110 ) ;
V_10 -> V_111 = F_8 ( V_87 -> V_102 ) ;
V_10 -> V_192 = V_87 -> V_193 ;
F_6 ( V_10 -> V_194 ,
V_87 -> V_195 ) ;
F_6 ( V_10 -> V_196 , V_87 -> V_197 ) ;
return F_9 ( V_2 , V_18 , NULL ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
enum V_3 V_4 ,
struct V_5 * V_6 )
{
struct V_198 * V_10 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 V_20 ;
int V_21 = - V_180 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_25 = V_87 -> V_102 ;
V_20 . V_26 = V_2 -> V_27 . V_26 ;
V_20 . V_4 = V_4 ;
V_20 . V_28 = V_6 ;
V_21 = F_3 ( V_2 , & V_18 ,
V_199 ,
V_30 , & V_20 ) ;
if ( V_21 )
return V_21 ;
V_10 = & V_18 -> V_31 . V_200 ;
V_10 -> V_41 = V_199 ;
F_4 ( V_10 -> V_38 ,
V_39 , V_87 -> V_109 ) ;
return F_9 ( V_2 , V_18 , NULL ) ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
struct V_5 * V_6 )
{
struct V_201 * V_10 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_19 V_20 ;
int V_21 = 0 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_25 = F_2 ( V_2 ) ;
V_20 . V_26 = V_2 -> V_27 . V_26 ;
V_20 . V_4 = V_4 ;
V_20 . V_28 = V_6 ;
V_21 = F_3 ( V_2 , & V_18 ,
V_202 ,
V_30 , & V_20 ) ;
if ( V_21 )
return V_21 ;
V_10 = & V_18 -> V_31 . V_203 ;
V_10 -> V_37 . V_41 = V_202 ;
return F_9 ( V_2 , V_18 , NULL ) ;
}
static void T_6 * F_22 ( struct V_1 * V_2 , T_2 V_25 )
{
return ( T_4 T_6 * ) V_2 -> V_204 +
F_23 ( V_25 , V_205 ) ;
}
static void T_6 * F_24 ( struct V_1 * V_2 ,
T_4 V_206 )
{
T_4 V_207 = F_7 ( V_2 -> V_65 ) ;
return ( T_4 T_6 * ) V_2 -> V_208 + V_209 +
F_25 ( V_207 ,
V_206 ) ;
}
static void T_6 * F_26 ( struct V_1 * V_2 ,
T_4 V_206 )
{
T_4 V_207 = F_7 ( V_2 -> V_65 ) ;
return ( T_4 T_6 * ) V_2 -> V_208 + V_210 +
F_27 ( V_207 ,
V_206 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
if ( ! V_87 -> V_211 )
goto V_212;
memset ( V_87 -> V_211 , 0 ,
sizeof( * V_87 -> V_211 ) ) ;
if ( ! V_87 -> V_213 )
goto V_212;
memset ( V_87 -> V_213 , 0 ,
sizeof( * V_87 -> V_213 ) ) ;
if ( ! V_87 -> V_113 . V_214 )
goto V_212;
F_29 ( & V_87 -> V_113 ) ;
if ( ! V_87 -> V_115 . V_214 )
goto V_212;
F_29 ( & V_87 -> V_115 ) ;
if ( ! V_87 -> V_114 . V_214 )
goto V_212;
F_29 ( & V_87 -> V_114 ) ;
return 0 ;
V_212:
return - V_215 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_86 * * V_216 )
{
T_3 V_217 = 0 , V_218 = 0 , V_219 = 0 ;
struct V_220 * V_221 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_222 * V_92 = NULL ;
struct V_86 * V_87 = NULL ;
int V_21 = 0 ;
F_31 ( & V_2 -> V_84 -> V_223 ) ;
if ( ! F_32 ( & V_2 -> V_84 -> V_224 ) )
V_87 = F_33 ( & V_2 -> V_84 -> V_224 ,
struct V_86 , V_225 ) ;
if ( V_87 ) {
F_34 ( & V_87 -> V_225 ) ;
F_35 ( & V_2 -> V_84 -> V_223 ) ;
* V_216 = V_87 ;
return 0 ;
}
F_35 ( & V_2 -> V_84 -> V_223 ) ;
V_14 = & V_2 -> V_34 . V_35 ;
V_87 = F_36 ( sizeof( * V_87 ) , V_226 ) ;
if ( ! V_87 )
return - V_215 ;
V_221 = F_37 ( & V_2 -> V_227 -> V_228 -> V_229 ,
sizeof( * V_221 ) ,
& V_87 -> V_197 ,
V_226 ) ;
if ( ! V_221 )
goto V_230;
V_87 -> V_211 = V_221 ;
V_92 = F_37 ( & V_2 -> V_227 -> V_228 -> V_229 ,
sizeof( * V_92 ) ,
& V_87 -> V_195 ,
V_226 ) ;
if ( ! V_92 )
goto V_231;
V_87 -> V_213 = V_92 ;
V_219 = V_14 -> V_44 *
V_232 / 0x80 ;
V_21 = F_38 ( V_2 -> V_227 ,
V_233 ,
V_234 ,
V_235 ,
V_219 , 0x80 , & V_87 -> V_113 ) ;
if ( V_21 )
goto V_236;
V_217 = V_14 -> V_45 *
V_232 / sizeof( struct V_237 ) ;
V_21 = F_38 ( V_2 -> V_227 ,
V_233 ,
V_234 ,
V_235 ,
V_217 ,
sizeof( struct V_237 ) , & V_87 -> V_115 ) ;
if ( V_21 )
goto V_238;
V_218 = V_217 ;
V_21 = F_38 ( V_2 -> V_227 ,
V_233 ,
V_234 ,
V_235 ,
V_218 ,
sizeof( struct V_239 ) , & V_87 -> V_114 ) ;
if ( V_21 )
goto V_212;
V_87 -> V_240 = true ;
* V_216 = V_87 ;
return 0 ;
V_212:
F_39 ( V_2 -> V_227 , & V_87 -> V_115 ) ;
V_238:
F_39 ( V_2 -> V_227 , & V_87 -> V_113 ) ;
V_236:
F_40 ( & V_2 -> V_227 -> V_228 -> V_229 ,
sizeof( struct V_222 ) ,
V_87 -> V_213 ,
V_87 -> V_195 ) ;
V_231:
F_40 ( & V_2 -> V_227 -> V_228 -> V_229 ,
sizeof( struct V_220 ) ,
V_87 -> V_211 ,
V_87 -> V_197 ) ;
V_230:
F_41 ( V_87 ) ;
return - V_215 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_86 * V_241 ,
struct V_86 * * V_216 )
{
struct V_86 * V_87 = NULL ;
int V_21 = 0 ;
T_2 V_102 ;
F_31 ( & V_2 -> V_84 -> V_223 ) ;
V_21 = F_43 ( V_2 , V_30 , & V_102 ) ;
F_35 ( & V_2 -> V_84 -> V_223 ) ;
if ( V_21 )
return V_21 ;
if ( V_241 )
V_87 = V_241 ;
else
V_21 = F_30 ( V_2 , & V_87 ) ;
if ( ! V_21 )
V_21 = F_28 ( V_2 , V_87 ) ;
if ( V_21 ) {
F_31 ( & V_2 -> V_84 -> V_223 ) ;
F_44 ( V_2 , V_102 ) ;
F_35 ( & V_2 -> V_84 -> V_223 ) ;
return V_21 ;
}
V_87 -> V_102 = V_102 ;
V_87 -> V_110 = ( T_3 ) V_102 ;
V_87 -> V_111 = ( V_2 -> V_27 . V_26 << 16 ) | V_102 ;
* V_216 = V_87 ;
return V_21 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
F_31 ( & V_2 -> V_84 -> V_223 ) ;
F_46 ( & V_87 -> V_225 , & V_2 -> V_84 -> V_224 ) ;
F_44 ( V_2 , V_87 -> V_102 ) ;
F_35 ( & V_2 -> V_84 -> V_223 ) ;
}
struct V_242 * F_47 ( struct V_1 * V_2 )
{
struct V_242 * V_84 ;
V_84 = F_36 ( sizeof( * V_84 ) , V_226 ) ;
if ( ! V_84 )
return NULL ;
F_48 ( & V_84 -> V_224 ) ;
return V_84 ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_242 * V_84 )
{
F_50 ( & V_84 -> V_223 ) ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_242 * V_84 )
{
F_41 ( V_84 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 )
{
struct V_247 V_248 ;
T_2 V_249 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_249 = V_250 +
F_53 ( V_2 -> V_251 ) ;
F_54 ( V_2 , V_244 , & V_248 , V_249 , sizeof( V_248 ) ) ;
V_246 -> V_252 =
F_55 ( V_248 . V_252 ) ;
V_246 -> V_253 =
F_55 ( V_248 . V_253 ) ;
V_246 -> V_254 =
F_56 ( V_248 . V_254 ) ;
V_246 -> V_255 =
F_56 ( V_248 . V_255 ) ;
V_246 -> V_256 =
F_56 ( V_248 . V_256 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 )
{
struct V_257 V_258 ;
T_2 V_259 ;
memset ( & V_258 , 0 , sizeof( V_258 ) ) ;
V_259 = V_260 +
F_58 ( V_2 -> V_251 ) ;
F_54 ( V_2 , V_244 , & V_258 , V_259 , sizeof( V_258 ) ) ;
V_246 -> V_261 =
F_55 ( V_258 . V_261 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 )
{
struct V_262 V_263 ;
T_2 V_264 ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_264 = V_265 +
F_60 ( V_2 -> V_251 ) ;
F_54 ( V_2 , V_244 , & V_263 , V_264 , sizeof( V_263 ) ) ;
V_246 -> V_266 =
F_55 ( V_263 . V_266 ) ;
V_246 -> V_267 =
F_55 ( V_263 . V_267 ) ;
V_246 -> V_268 =
F_55 ( V_263 . V_268 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 )
{
struct V_269 V_270 ;
T_2 V_271 ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
V_271 = V_272 +
F_62 ( V_2 -> V_251 ) ;
F_54 ( V_2 , V_244 , & V_270 , V_271 , sizeof( V_270 ) ) ;
V_246 -> V_273 =
F_55 ( V_270 . V_273 ) ;
V_246 -> V_274 =
F_55 ( V_270 . V_274 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 )
{
struct V_275 V_276 ;
T_2 V_277 ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_277 = V_278 +
F_64 ( V_2 -> V_251 ) ;
F_54 ( V_2 , V_244 , & V_276 , V_277 , sizeof( V_276 ) ) ;
V_246 -> V_279 =
F_55 ( V_276 . V_279 ) ;
V_246 -> V_280 =
F_55 ( V_276 . V_280 ) ;
V_246 -> V_281 =
F_55 ( V_276 . V_281 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
struct V_245 * V_246 )
{
struct V_282 V_283 ;
T_2 V_284 ;
memset ( & V_283 , 0 , sizeof( V_283 ) ) ;
V_284 = V_285 +
F_66 ( V_2 -> V_251 ) ;
F_54 ( V_2 , V_244 , & V_283 , V_284 , sizeof( V_283 ) ) ;
V_246 -> V_286 =
F_55 ( V_283 . V_286 ) ;
V_246 -> V_287 =
F_55 ( V_283 . V_287 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_245 * V_288 )
{
struct V_243 * V_244 ;
memset ( V_288 , 0 , sizeof( * V_288 ) ) ;
V_244 = F_68 ( V_2 ) ;
if ( ! V_244 ) {
F_69 ( V_2 , L_1 ) ;
return - V_289 ;
}
F_52 ( V_2 , V_244 , V_288 ) ;
F_57 ( V_2 , V_244 , V_288 ) ;
F_59 ( V_2 , V_244 , V_288 ) ;
F_61 ( V_2 , V_244 , V_288 ) ;
F_63 ( V_2 , V_244 , V_288 ) ;
F_65 ( V_2 , V_244 , V_288 ) ;
F_70 ( V_2 , V_244 ) ;
return 0 ;
}
static int F_71 ( struct V_290 * V_227 ,
struct V_291 * V_292 )
{
struct V_1 * V_293 = F_72 ( V_227 ) ;
int V_21 ;
memset ( V_292 , 0 , sizeof( * V_292 ) ) ;
V_21 = F_73 ( V_227 , & V_292 -> V_294 ) ;
V_292 -> V_295 =
F_24 ( V_293 , V_67 ) ;
V_292 -> V_296 =
F_26 ( V_293 , V_67 ) ;
return V_21 ;
}
static void F_74 ( struct V_290 * V_227 ,
struct V_297 * V_298 , void * V_299 )
{
V_227 -> V_300 . V_106 = V_298 ;
V_227 -> V_301 = V_299 ;
}
static struct V_302 * F_75 ( struct V_290 * V_227 ,
T_2 V_303 )
{
struct V_302 * V_304 = NULL ;
if ( ! ( V_227 -> V_38 & V_305 ) )
return NULL ;
F_76 (cdev->connections, hash_con, node, handle) {
if ( V_304 -> V_306 -> V_102 == V_303 )
break;
}
if ( ! V_304 || ( V_304 -> V_306 -> V_102 != V_303 ) )
return NULL ;
return V_304 ;
}
static int F_77 ( struct V_290 * V_227 )
{
int V_21 ;
if ( ! ( V_227 -> V_38 & V_305 ) ) {
F_78 ( V_227 , L_2 ) ;
return 0 ;
}
if ( ! F_79 ( V_227 -> V_307 ) ) {
F_78 ( V_227 ,
L_3 ) ;
return - V_180 ;
}
V_21 = F_21 ( F_72 ( V_227 ) ,
V_308 , NULL ) ;
V_227 -> V_38 &= ~ V_305 ;
return V_21 ;
}
static int F_80 ( struct V_290 * V_227 ,
struct V_309 * V_310 ,
void * V_7 ,
T_1 V_8 )
{
int V_21 ;
struct V_311 * V_312 ;
if ( V_227 -> V_38 & V_305 ) {
F_78 ( V_227 , L_4 ) ;
return 0 ;
}
V_21 = F_1 ( F_72 ( V_227 ) ,
V_308 , NULL , V_7 ,
V_8 ) ;
if ( V_21 ) {
F_78 ( V_227 , L_5 ) ;
return V_21 ;
}
V_227 -> V_38 |= V_305 ;
F_81 ( V_227 -> V_307 ) ;
if ( ! V_310 )
return 0 ;
V_312 = F_36 ( sizeof( * V_312 ) , V_226 ) ;
if ( ! V_312 ) {
F_77 ( V_227 ) ;
return - V_215 ;
}
V_21 = F_82 ( F_72 ( V_227 ) ,
V_312 ) ;
if ( V_21 ) {
F_78 ( V_227 , L_6 ) ;
F_77 ( V_227 ) ;
F_41 ( V_312 ) ;
return V_21 ;
}
V_310 -> V_313 = V_312 -> V_314 ;
V_310 -> V_315 = V_312 -> V_315 ;
memcpy ( V_310 -> V_316 , V_312 -> V_316 ,
V_317 * sizeof( T_4 * ) ) ;
F_41 ( V_312 ) ;
return 0 ;
}
static int F_83 ( struct V_290 * V_227 ,
T_2 * V_303 ,
T_2 * V_111 , void T_6 * * V_318 )
{
struct V_302 * V_304 ;
int V_21 ;
V_304 = F_36 ( sizeof( * V_304 ) , V_319 ) ;
if ( ! V_304 )
return - V_215 ;
V_21 = F_42 ( F_72 ( V_227 ) , NULL ,
& V_304 -> V_306 ) ;
if ( V_21 ) {
F_78 ( V_227 , L_7 ) ;
F_41 ( V_304 ) ;
return V_21 ;
}
* V_303 = V_304 -> V_306 -> V_102 ;
* V_111 = V_304 -> V_306 -> V_111 ;
F_84 ( V_227 -> V_307 , & V_304 -> V_320 , * V_303 ) ;
if ( V_318 )
* V_318 = F_22 ( F_72 ( V_227 ) ,
* V_303 ) ;
return 0 ;
}
static int F_85 ( struct V_290 * V_227 , T_2 V_303 )
{
struct V_302 * V_304 ;
V_304 = F_75 ( V_227 , V_303 ) ;
if ( ! V_304 ) {
F_78 ( V_227 , L_8 ,
V_303 ) ;
return - V_180 ;
}
F_86 ( & V_304 -> V_320 ) ;
F_45 ( F_72 ( V_227 ) , V_304 -> V_306 ) ;
F_41 ( V_304 ) ;
return 0 ;
}
static int F_87 ( struct V_290 * V_227 ,
T_2 V_303 ,
struct V_321 * V_322 )
{
struct V_302 * V_304 ;
struct V_86 * V_306 ;
V_304 = F_75 ( V_227 , V_303 ) ;
if ( ! V_304 ) {
F_78 ( V_227 , L_8 ,
V_303 ) ;
return - V_180 ;
}
V_306 = V_304 -> V_306 ;
F_88 ( V_306 -> V_122 , V_322 -> V_323 . V_324 ) ;
F_88 ( V_306 -> V_126 , V_322 -> V_325 . V_324 ) ;
memcpy ( V_306 -> V_134 , V_322 -> V_323 . V_326 , sizeof( V_306 -> V_134 ) ) ;
memcpy ( V_306 -> V_133 , V_322 -> V_325 . V_326 , sizeof( V_306 -> V_133 ) ) ;
V_306 -> V_166 = V_322 -> V_323 . V_327 ;
V_306 -> V_165 = V_322 -> V_325 . V_327 ;
V_306 -> V_109 = V_322 -> V_109 ;
V_306 -> V_112 = V_322 -> V_112 ;
V_306 -> V_116 = V_322 -> V_116 ;
V_306 -> V_130 = V_322 -> V_130 ;
V_306 -> V_131 = V_322 -> V_131 ;
V_306 -> V_132 = V_322 -> V_132 ;
V_306 -> V_118 = V_322 -> V_118 ;
V_306 -> V_135 = V_322 -> V_135 ;
V_306 -> V_136 = V_322 -> V_136 ;
V_306 -> V_137 = V_322 -> V_137 ;
V_306 -> V_138 = V_322 -> V_138 ;
V_306 -> V_139 = V_322 -> V_139 ;
V_306 -> V_140 = V_322 -> V_140 ;
V_306 -> V_141 = V_322 -> V_141 ;
V_306 -> V_142 = V_322 -> V_142 ;
V_306 -> V_143 = V_322 -> V_143 ;
V_306 -> V_144 = V_322 -> V_144 ;
V_306 -> V_145 = V_322 -> V_145 ;
V_306 -> V_146 = V_322 -> V_146 ;
V_306 -> V_147 = V_322 -> V_147 ;
V_306 -> V_148 = V_322 -> V_148 ;
V_306 -> V_149 = V_322 -> V_149 ;
V_306 -> V_150 = V_322 -> V_150 ;
V_306 -> V_151 = V_322 -> V_151 ;
V_306 -> V_152 = V_322 -> V_152 ;
V_306 -> V_153 = V_322 -> V_153 ;
V_306 -> V_154 = V_322 -> V_154 ;
V_306 -> V_155 = V_322 -> V_155 ;
V_306 -> V_156 = V_322 -> V_156 ;
V_306 -> V_157 = V_322 -> V_157 ;
V_306 -> V_158 = V_322 -> V_158 ;
V_306 -> V_159 = V_322 -> V_159 ;
V_306 -> V_160 = V_322 -> V_160 ;
V_306 -> V_161 = V_322 -> V_161 ;
V_306 -> V_162 = V_322 -> V_162 ;
V_306 -> V_163 = V_322 -> V_163 ;
V_306 -> V_164 = V_322 -> V_164 ;
V_306 -> V_165 = V_322 -> V_165 ;
V_306 -> V_166 = V_322 -> V_166 ;
V_306 -> V_167 = V_322 -> V_167 ;
V_306 -> V_168 = V_322 -> V_168 ;
V_306 -> V_169 = V_322 -> V_169 ;
V_306 -> V_170 = V_322 -> V_170 ;
V_306 -> V_171 = V_322 -> V_171 ;
V_306 -> V_172 = V_322 -> V_172 ;
V_306 -> V_117 = 0x1 ;
return F_10 ( F_72 ( V_227 ) , V_306 ,
V_308 , NULL ) ;
}
static int F_89 ( struct V_290 * V_227 ,
T_2 V_303 ,
struct V_328 * V_322 )
{
struct V_302 * V_304 ;
struct V_86 * V_306 ;
V_304 = F_75 ( V_227 , V_303 ) ;
if ( ! V_304 ) {
F_78 ( V_227 , L_8 ,
V_303 ) ;
return - V_180 ;
}
V_306 = V_304 -> V_306 ;
V_306 -> V_183 = V_322 -> V_183 ;
V_306 -> V_184 = V_322 -> V_184 ;
V_306 -> V_185 = V_322 -> V_185 ;
V_306 -> V_186 = V_322 -> V_186 ;
V_306 -> V_187 = V_322 -> V_187 ;
V_306 -> V_188 = V_322 -> V_188 ;
return F_18 ( F_72 ( V_227 ) , V_306 ,
V_308 , NULL ) ;
}
static int F_90 ( struct V_290 * V_227 , T_2 V_303 )
{
struct V_302 * V_304 ;
V_304 = F_75 ( V_227 , V_303 ) ;
if ( ! V_304 ) {
F_78 ( V_227 , L_8 ,
V_303 ) ;
return - V_180 ;
}
return F_20 ( F_72 ( V_227 ) ,
V_304 -> V_306 ,
V_308 , NULL ) ;
}
static int F_91 ( struct V_290 * V_227 ,
T_2 V_303 , T_4 V_329 )
{
struct V_302 * V_304 ;
V_304 = F_75 ( V_227 , V_303 ) ;
if ( ! V_304 ) {
F_78 ( V_227 , L_8 ,
V_303 ) ;
return - V_180 ;
}
V_304 -> V_306 -> V_193 = V_329 ;
return F_19 ( F_72 ( V_227 ) ,
V_304 -> V_306 ,
V_308 , NULL ) ;
}
static int V_245 ( struct V_290 * V_227 , struct V_245 * V_288 )
{
return F_67 ( F_72 ( V_227 ) , V_288 ) ;
}
const struct V_330 * F_92 ( void )
{
return & V_331 ;
}
void F_93 ( void )
{
}
