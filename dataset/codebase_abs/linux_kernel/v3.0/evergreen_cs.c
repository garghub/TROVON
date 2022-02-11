static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_2 -> V_4 [ V_3 ] = NULL ;
V_2 -> V_5 [ V_3 ] = NULL ;
V_2 -> V_6 [ V_3 ] = 0 ;
V_2 -> V_7 [ V_3 ] = 0 ;
}
for ( V_3 = 0 ; V_3 < 12 ; V_3 ++ ) {
V_2 -> V_8 [ V_3 ] = 0 ;
V_2 -> V_9 [ V_3 ] = NULL ;
V_2 -> V_10 [ V_3 ] = 0xFFFFFFFF ;
V_2 -> V_11 [ V_3 ] = 0 ;
V_2 -> V_12 [ V_3 ] = 0 ;
V_2 -> V_13 [ V_3 ] = 0 ;
V_2 -> V_14 [ V_3 ] = 0 ;
V_2 -> V_15 [ V_3 ] = 0 ;
V_2 -> V_16 [ V_3 ] = 0 ;
V_2 -> V_17 [ V_3 ] = 0 ;
V_2 -> V_15 [ V_3 ] = 0 ;
}
V_2 -> V_18 = 0xFFFFFFFF ;
V_2 -> V_19 = 0xFFFFFFFF ;
V_2 -> V_20 = 0xFFFFC000 ;
V_2 -> V_21 = 0xFFFFFFFF ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0xFFFFFFFF ;
V_2 -> V_24 = 0xFFFFFFFF ;
V_2 -> V_25 = 0xFFFFFFFF ;
V_2 -> V_26 = 0xFFFFFFFF ;
V_2 -> V_27 = 0xFFFFFFFF ;
V_2 -> V_28 = NULL ;
V_2 -> V_29 = NULL ;
V_2 -> V_30 = 0xFFFFFFFF ;
V_2 -> V_31 = 0xFFFFFFFF ;
V_2 -> V_32 = 0xFFFFFFFF ;
V_2 -> V_33 = 0xFFFFFFFF ;
V_2 -> V_34 = NULL ;
V_2 -> V_35 = NULL ;
}
static inline int F_2 ( struct V_36 * V_37 , int V_3 )
{
return 0 ;
}
static int F_3 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
if ( V_2 -> V_38 || V_2 -> V_39 ) {
F_4 ( V_37 -> V_40 , L_1 ) ;
return - V_41 ;
}
return 0 ;
}
int F_5 ( struct V_36 * V_37 ,
struct V_42 * V_43 ,
unsigned V_44 )
{
struct V_45 * V_46 = & V_37 -> V_47 [ V_37 -> V_48 ] ;
T_1 V_49 ;
if ( V_44 >= V_46 -> V_50 ) {
F_6 ( L_2 ,
V_44 , V_46 -> V_50 ) ;
return - V_41 ;
}
V_49 = F_7 ( V_37 , V_44 ) ;
V_43 -> V_44 = V_44 ;
V_43 -> type = F_8 ( V_49 ) ;
V_43 -> V_51 = F_9 ( V_49 ) ;
V_43 -> V_52 = 0 ;
switch ( V_43 -> type ) {
case V_53 :
V_43 -> V_54 = F_10 ( V_49 ) ;
break;
case V_55 :
V_43 -> V_56 = F_11 ( V_49 ) ;
break;
case V_57 :
V_43 -> V_51 = - 1 ;
break;
default:
F_6 ( L_3 , V_43 -> type , V_44 ) ;
return - V_41 ;
}
if ( ( V_43 -> V_51 + 1 + V_43 -> V_44 ) >= V_46 -> V_50 ) {
F_6 ( L_4 ,
V_43 -> V_44 , V_43 -> type , V_43 -> V_51 , V_46 -> V_50 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_12 ( struct V_36 * V_37 ,
struct V_58 * * V_59 )
{
struct V_45 * V_60 ;
struct V_42 V_61 ;
unsigned V_44 ;
int V_62 ;
if ( V_37 -> V_63 == - 1 ) {
F_6 ( L_5 ) ;
return - V_41 ;
}
* V_59 = NULL ;
V_60 = & V_37 -> V_47 [ V_37 -> V_63 ] ;
V_62 = F_5 ( V_37 , & V_61 , V_37 -> V_44 ) ;
if ( V_62 ) {
return V_62 ;
}
V_37 -> V_44 += V_61 . V_51 + 2 ;
if ( V_61 . type != V_55 || V_61 . V_56 != V_64 ) {
F_6 ( L_6 ,
V_61 . V_44 ) ;
return - V_41 ;
}
V_44 = F_7 ( V_37 , V_61 . V_44 + 1 ) ;
if ( V_44 >= V_60 -> V_50 ) {
F_6 ( L_7 ,
V_44 , V_60 -> V_50 ) ;
return - V_41 ;
}
* V_59 = V_37 -> V_65 [ ( V_44 / 4 ) ] ;
return 0 ;
}
static inline int F_13 ( struct V_36 * V_37 )
{
struct V_42 V_61 ;
int V_62 ;
V_62 = F_5 ( V_37 , & V_61 , V_37 -> V_44 ) ;
if ( V_62 ) {
return 0 ;
}
if ( V_61 . type != V_55 || V_61 . V_56 != V_64 ) {
return 0 ;
}
return 1 ;
}
static int F_14 ( struct V_36 * V_37 )
{
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_70 ;
struct V_42 V_61 , V_71 ;
int V_72 ;
int V_62 ;
T_1 V_49 , V_73 , V_54 , V_74 ;
volatile T_1 * V_75 ;
V_75 = V_37 -> V_75 -> V_76 ;
V_62 = F_5 ( V_37 , & V_71 , V_37 -> V_44 ) ;
if ( V_62 )
return V_62 ;
if ( V_71 . type != V_55 ||
V_71 . V_56 != V_77 ) {
F_6 ( L_8 ) ;
return - V_41 ;
}
V_74 = F_7 ( V_37 , V_71 . V_44 + 1 ) ;
if ( V_74 & 0x10 ) {
F_6 ( L_9 ) ;
return - V_41 ;
}
if ( ( V_74 & 0x7 ) != 0x3 ) {
F_6 ( L_10 ) ;
return - V_41 ;
}
if ( ( F_7 ( V_37 , V_71 . V_44 + 2 ) << 2 ) != V_78 ) {
F_6 ( L_11 ) ;
return - V_41 ;
}
if ( F_7 ( V_37 , V_71 . V_44 + 5 ) != V_79 ) {
F_6 ( L_12 ) ;
return - V_41 ;
}
V_62 = F_5 ( V_37 , & V_61 , V_37 -> V_44 + V_71 . V_51 + 2 ) ;
if ( V_62 )
return V_62 ;
V_73 = V_37 -> V_44 - 2 ;
V_37 -> V_44 += V_71 . V_51 + 2 ;
V_37 -> V_44 += V_61 . V_51 + 2 ;
V_49 = F_7 ( V_37 , V_73 ) ;
V_72 = F_7 ( V_37 , V_73 + 2 + 7 + 1 ) ;
V_54 = F_10 ( V_49 ) ;
V_67 = F_15 ( V_37 -> V_80 -> V_81 , V_72 , V_82 ) ;
if ( ! V_67 ) {
F_6 ( L_13 , V_72 ) ;
return - V_41 ;
}
V_69 = F_16 ( V_67 ) ;
V_70 = F_17 ( V_69 ) ;
V_72 = V_70 -> V_72 ;
if ( ! V_69 -> V_83 ) {
V_75 [ V_73 + 2 ] = F_18 ( 0 ) ;
V_75 [ V_73 + 3 ] = F_18 ( 0 ) ;
V_75 [ V_73 + 4 ] = F_18 ( 0 ) ;
V_75 [ V_73 + 5 ] = F_18 ( 0 ) ;
V_75 [ V_73 + 6 ] = F_18 ( 0 ) ;
V_75 [ V_73 + 7 ] = F_18 ( 0 ) ;
V_75 [ V_73 + 8 ] = F_18 ( 0 ) ;
} else {
switch ( V_54 ) {
case V_84 :
V_49 &= ~ V_85 ;
V_49 |= ( V_84 + V_70 -> V_86 ) >> 2 ;
V_75 [ V_73 ] = V_49 ;
V_75 [ V_73 + 4 ] = ( V_78 + V_70 -> V_86 ) >> 2 ;
break;
default:
F_6 ( L_14 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_19 ( struct V_36 * V_37 ,
struct V_42 * V_43 ,
unsigned V_44 , unsigned V_54 )
{
int V_62 ;
switch ( V_54 ) {
case V_84 :
V_62 = F_14 ( V_37 ) ;
if ( V_62 ) {
F_6 ( L_15 ,
V_44 , V_54 ) ;
return V_62 ;
}
break;
default:
F_20 ( V_87 L_16 ,
V_54 , V_44 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_21 ( struct V_36 * V_37 ,
struct V_42 * V_43 )
{
unsigned V_54 , V_3 ;
unsigned V_44 ;
int V_62 ;
V_44 = V_43 -> V_44 + 1 ;
V_54 = V_43 -> V_54 ;
for ( V_3 = 0 ; V_3 <= V_43 -> V_51 ; V_3 ++ , V_44 ++ , V_54 += 4 ) {
V_62 = F_19 ( V_37 , V_43 , V_44 , V_54 ) ;
if ( V_62 ) {
return V_62 ;
}
}
return 0 ;
}
static inline int F_22 ( struct V_36 * V_37 , T_2 V_54 , T_2 V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_2 ;
struct V_58 * V_88 ;
T_2 V_89 ;
T_2 V_90 , V_3 , V_91 , * V_75 ;
int V_62 ;
if ( V_37 -> V_80 -> V_92 >= V_93 )
V_89 = F_23 ( V_94 ) ;
else
V_89 = F_23 ( V_95 ) ;
V_3 = ( V_54 >> 7 ) ;
if ( V_3 > V_89 ) {
F_4 ( V_37 -> V_40 , L_17 , V_54 , V_44 ) ;
return - V_41 ;
}
V_90 = 1 << ( ( V_54 >> 2 ) & 31 ) ;
if ( V_37 -> V_80 -> V_92 >= V_93 ) {
if ( ! ( V_94 [ V_3 ] & V_90 ) )
return 0 ;
} else {
if ( ! ( V_95 [ V_3 ] & V_90 ) )
return 0 ;
}
V_75 = V_37 -> V_75 -> V_76 ;
switch ( V_54 ) {
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
break;
case V_130 :
V_2 -> V_23 = F_7 ( V_37 , V_44 ) ;
break;
case V_131 :
if ( V_37 -> V_80 -> V_92 < V_93 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
break;
case V_132 :
if ( V_37 -> V_80 -> V_92 < V_93 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
break;
case V_133 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_2 -> V_24 = F_7 ( V_37 , V_44 ) ;
V_75 [ V_44 ] &= ~ F_24 ( 0xf ) ;
V_2 -> V_24 &= ~ F_24 ( 0xf ) ;
if ( V_88 -> V_128 . V_134 & V_135 ) {
V_75 [ V_44 ] |= F_24 ( V_136 ) ;
V_2 -> V_24 |= F_24 ( V_136 ) ;
} else {
V_75 [ V_44 ] |= F_24 ( V_137 ) ;
V_2 -> V_24 |= F_24 ( V_137 ) ;
}
break;
case V_138 :
V_2 -> V_30 = F_7 ( V_37 , V_44 ) ;
break;
case V_139 :
V_2 -> V_20 = F_7 ( V_37 , V_44 ) ;
break;
case V_140 :
V_2 -> V_21 = F_7 ( V_37 , V_44 ) ;
V_2 -> V_22 = V_44 ;
break;
case V_141 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_2 -> V_26 = F_7 ( V_37 , V_44 ) ;
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_28 = V_88 -> V_142 ;
break;
case V_143 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_2 -> V_27 = F_7 ( V_37 , V_44 ) ;
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_29 = V_88 -> V_142 ;
break;
case V_144 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_2 -> V_32 = F_7 ( V_37 , V_44 ) ;
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_34 = V_88 -> V_142 ;
break;
case V_145 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_2 -> V_33 = F_7 ( V_37 , V_44 ) ;
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_35 = V_88 -> V_142 ;
break;
case V_146 :
V_2 -> V_38 = F_7 ( V_37 , V_44 ) ;
break;
case V_147 :
V_2 -> V_39 = F_7 ( V_37 , V_44 ) ;
break;
case V_148 :
V_2 -> V_18 = F_7 ( V_37 , V_44 ) ;
break;
case V_149 :
V_2 -> V_19 = F_7 ( V_37 , V_44 ) ;
break;
case V_150 :
if ( V_37 -> V_80 -> V_92 >= V_93 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_91 = F_7 ( V_37 , V_44 ) & V_151 ;
V_2 -> V_152 = 1 << V_91 ;
break;
case V_153 :
if ( V_37 -> V_80 -> V_92 < V_93 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_91 = F_7 ( V_37 , V_44 ) & V_154 ;
V_2 -> V_152 = 1 << V_91 ;
break;
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
V_91 = ( V_54 - V_155 ) / 0x3c ;
V_2 -> V_12 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
break;
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_91 = ( ( V_54 - V_163 ) / 0x1c ) + 8 ;
V_2 -> V_12 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_91 = ( V_54 - V_167 ) / 0x3c ;
V_2 -> V_11 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
if ( V_88 -> V_128 . V_134 & V_135 ) {
V_75 [ V_44 ] |= F_25 ( V_136 ) ;
V_2 -> V_11 [ V_91 ] |= F_25 ( V_136 ) ;
} else if ( V_88 -> V_128 . V_134 & V_175 ) {
V_75 [ V_44 ] |= F_25 ( V_137 ) ;
V_2 -> V_11 [ V_91 ] |= F_25 ( V_137 ) ;
}
break;
case V_176 :
case V_177 :
case V_178 :
case V_179 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_91 = ( ( V_54 - V_176 ) / 0x1c ) + 8 ;
V_2 -> V_11 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
if ( V_88 -> V_128 . V_134 & V_135 ) {
V_75 [ V_44 ] |= F_25 ( V_136 ) ;
V_2 -> V_11 [ V_91 ] |= F_25 ( V_136 ) ;
} else if ( V_88 -> V_128 . V_134 & V_175 ) {
V_75 [ V_44 ] |= F_25 ( V_137 ) ;
V_2 -> V_11 [ V_91 ] |= F_25 ( V_137 ) ;
}
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
V_91 = ( V_54 - V_180 ) / 0x3c ;
V_2 -> V_16 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_2 -> V_13 [ V_91 ] = V_44 ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
V_91 = ( ( V_54 - V_188 ) / 0x1c ) + 8 ;
V_2 -> V_16 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_2 -> V_13 [ V_91 ] = V_44 ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
V_91 = ( V_54 - V_192 ) / 0x3c ;
V_2 -> V_17 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_2 -> V_14 [ V_91 ] = V_44 ;
break;
case V_200 :
case V_201 :
case V_202 :
case V_203 :
V_91 = ( ( V_54 - V_200 ) / 0x1c ) + 8 ;
V_2 -> V_17 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_2 -> V_14 [ V_91 ] = V_44 ;
break;
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
V_91 = ( V_54 - V_216 ) / 0x3c ;
V_2 -> V_15 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_2 -> V_224 [ V_91 ] = V_44 ;
break;
case V_225 :
case V_226 :
case V_227 :
case V_228 :
V_91 = ( ( V_54 - V_225 ) / 0x1c ) + 8 ;
V_2 -> V_15 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_2 -> V_224 [ V_91 ] = V_44 ;
break;
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
V_91 = ( V_54 - V_229 ) / 0x3c ;
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_26 ( V_37 -> V_40 , L_20 , V_54 ) ;
return - V_41 ;
}
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_4 [ V_91 ] = V_88 -> V_142 ;
break;
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
V_91 = ( V_54 - V_237 ) / 0x3c ;
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_26 ( V_37 -> V_40 , L_20 , V_54 ) ;
return - V_41 ;
}
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_5 [ V_91 ] = V_88 -> V_142 ;
break;
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
V_91 = ( V_54 - V_245 ) / 0x3c ;
V_2 -> V_7 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
break;
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
V_91 = ( V_54 - V_253 ) / 0x3c ;
V_2 -> V_6 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
break;
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_91 = ( V_54 - V_261 ) / 0x3c ;
V_2 -> V_10 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_8 [ V_91 ] = V_75 [ V_44 ] ;
V_2 -> V_9 [ V_91 ] = V_88 -> V_142 ;
break;
case V_269 :
case V_270 :
case V_271 :
case V_272 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_91 = ( ( V_54 - V_269 ) / 0x1c ) + 8 ;
V_2 -> V_10 [ V_91 ] = F_7 ( V_37 , V_44 ) ;
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_2 -> V_8 [ V_91 ] = V_75 [ V_44 ] ;
V_2 -> V_9 [ V_91 ] = V_88 -> V_142 ;
break;
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_18
L_19 , V_54 ) ;
return - V_41 ;
}
V_75 [ V_44 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
break;
default:
F_4 ( V_37 -> V_40 , L_17 , V_54 , V_44 ) ;
return - V_41 ;
}
return 0 ;
}
static inline int F_27 ( struct V_36 * V_37 , T_2 V_44 ,
struct V_375 * V_376 ,
struct V_375 * V_377 )
{
return 0 ;
}
static int F_28 ( struct V_36 * V_37 ,
struct V_42 * V_43 )
{
struct V_58 * V_88 ;
struct V_1 * V_2 ;
volatile T_2 * V_75 ;
unsigned V_44 ;
unsigned V_3 ;
unsigned V_378 , V_379 , V_54 ;
int V_62 ;
T_2 V_380 ;
V_2 = (struct V_1 * ) V_37 -> V_2 ;
V_75 = V_37 -> V_75 -> V_76 ;
V_44 = V_43 -> V_44 + 1 ;
V_380 = F_7 ( V_37 , V_44 ) ;
switch ( V_43 -> V_56 ) {
case V_381 :
{
int V_382 ;
int V_91 ;
if ( V_43 -> V_51 != 1 ) {
F_6 ( L_21 ) ;
return - V_41 ;
}
V_91 = F_7 ( V_37 , V_44 + 1 ) ;
V_382 = ( V_91 >> 16 ) & 0x7 ;
if ( V_382 == 0 )
return 0 ;
if ( V_382 > 2 ) {
F_6 ( L_22 , V_382 ) ;
return - V_41 ;
}
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_21 ) ;
return - V_41 ;
}
V_75 [ V_44 + 0 ] = V_380 + ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 1 ] = V_91 + ( F_29 ( V_88 -> V_128 . V_129 ) & 0xff ) ;
}
break;
case V_383 :
if ( V_43 -> V_51 != 1 ) {
F_6 ( L_23 ) ;
return - V_41 ;
}
break;
case V_384 :
case V_385 :
case V_386 :
if ( V_43 -> V_51 ) {
F_6 ( L_24 ) ;
return - V_41 ;
}
break;
case V_387 :
if ( V_37 -> V_80 -> V_92 < V_93 ) {
F_6 ( L_25 ) ;
return - V_41 ;
}
if ( V_43 -> V_51 ) {
F_6 ( L_24 ) ;
return - V_41 ;
}
break;
case V_388 :
if ( V_43 -> V_51 != 1 ) {
F_6 ( L_26 ) ;
return - V_41 ;
}
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_26 ) ;
return - V_41 ;
}
V_75 [ V_44 + 0 ] = V_380 + ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 1 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_27 , V_389 , __LINE__ ) ;
return V_62 ;
}
break;
case V_390 :
if ( V_43 -> V_51 != 3 ) {
F_6 ( L_28 ) ;
return - V_41 ;
}
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_28 ) ;
return - V_41 ;
}
V_75 [ V_44 + 0 ] = V_380 + ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 1 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_27 , V_389 , __LINE__ ) ;
return V_62 ;
}
break;
case V_391 :
if ( V_43 -> V_51 != 4 ) {
F_6 ( L_29 ) ;
return - V_41 ;
}
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_29 ) ;
return - V_41 ;
}
V_75 [ V_44 + 1 ] = V_380 + ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 2 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_27 , V_389 , __LINE__ ) ;
return V_62 ;
}
break;
case V_392 :
if ( V_43 -> V_51 != 1 ) {
F_6 ( L_30 ) ;
return - V_41 ;
}
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_31 , V_389 , __LINE__ , V_44 ) ;
return V_62 ;
}
break;
case V_393 :
if ( V_43 -> V_51 != 2 ) {
F_6 ( L_32 ) ;
return - V_41 ;
}
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_31 , V_389 , __LINE__ , V_44 ) ;
return V_62 ;
}
break;
case V_394 :
if ( V_43 -> V_51 < 2 ) {
F_6 ( L_33 ) ;
return - V_41 ;
}
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_27 , V_389 , __LINE__ ) ;
return V_62 ;
}
break;
case V_395 :
if ( V_43 -> V_51 != 2 ) {
F_6 ( L_34 ) ;
return - V_41 ;
}
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_27 , V_389 , __LINE__ ) ;
return V_62 ;
}
break;
case V_396 :
if ( V_43 -> V_51 != 3 ) {
F_6 ( L_35 ) ;
return - V_41 ;
}
V_62 = F_3 ( V_37 ) ;
if ( V_62 ) {
F_4 ( V_37 -> V_40 , L_27 , V_389 , __LINE__ ) ;
return V_62 ;
}
break;
case V_77 :
if ( V_43 -> V_51 != 5 ) {
F_6 ( L_36 ) ;
return - V_41 ;
}
if ( V_380 & 0x10 ) {
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_36 ) ;
return - V_41 ;
}
V_75 [ V_44 + 1 ] += ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 2 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
}
break;
case V_397 :
if ( V_43 -> V_51 != 3 ) {
F_6 ( L_37 ) ;
return - V_41 ;
}
if ( F_7 ( V_37 , V_44 + 1 ) != 0xffffffff ||
F_7 ( V_37 , V_44 + 2 ) != 0 ) {
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_37 ) ;
return - V_41 ;
}
V_75 [ V_44 + 2 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
}
break;
case V_398 :
if ( V_43 -> V_51 != 2 && V_43 -> V_51 != 0 ) {
F_6 ( L_38 ) ;
return - V_41 ;
}
if ( V_43 -> V_51 ) {
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_38 ) ;
return - V_41 ;
}
V_75 [ V_44 + 1 ] += ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 2 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
}
break;
case V_399 :
if ( V_43 -> V_51 != 4 ) {
F_6 ( L_39 ) ;
return - V_41 ;
}
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_39 ) ;
return - V_41 ;
}
V_75 [ V_44 + 1 ] += ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 2 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
break;
case V_400 :
if ( V_43 -> V_51 != 3 ) {
F_6 ( L_40 ) ;
return - V_41 ;
}
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_40 ) ;
return - V_41 ;
}
V_75 [ V_44 + 1 ] += ( T_2 ) ( V_88 -> V_128 . V_129 & 0xffffffff ) ;
V_75 [ V_44 + 2 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
break;
case V_401 :
V_378 = ( V_380 << 2 ) + V_402 ;
V_379 = 4 * V_43 -> V_51 + V_378 - 4 ;
if ( ( V_378 < V_402 ) ||
( V_378 >= V_403 ) ||
( V_379 >= V_403 ) ) {
F_6 ( L_41 ) ;
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < V_43 -> V_51 ; V_3 ++ ) {
V_54 = V_378 + ( 4 * V_3 ) ;
V_62 = F_22 ( V_37 , V_54 , V_44 + 1 + V_3 ) ;
if ( V_62 )
return V_62 ;
}
break;
case V_404 :
V_378 = ( V_380 << 2 ) + V_405 ;
V_379 = 4 * V_43 -> V_51 + V_378 - 4 ;
if ( ( V_378 < V_405 ) ||
( V_378 >= V_406 ) ||
( V_379 >= V_406 ) ) {
F_6 ( L_42 ) ;
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < V_43 -> V_51 ; V_3 ++ ) {
V_54 = V_378 + ( 4 * V_3 ) ;
V_62 = F_22 ( V_37 , V_54 , V_44 + 1 + V_3 ) ;
if ( V_62 )
return V_62 ;
}
break;
case V_407 :
if ( V_43 -> V_51 % 8 ) {
F_6 ( L_43 ) ;
return - V_41 ;
}
V_378 = ( V_380 << 2 ) + V_408 ;
V_379 = 4 * V_43 -> V_51 + V_378 - 4 ;
if ( ( V_378 < V_408 ) ||
( V_378 >= V_409 ) ||
( V_379 >= V_409 ) ) {
F_6 ( L_43 ) ;
return - V_41 ;
}
for ( V_3 = 0 ; V_3 < ( V_43 -> V_51 / 8 ) ; V_3 ++ ) {
struct V_375 * V_376 , * V_377 ;
T_2 V_410 , V_411 ;
switch ( F_30 ( F_7 ( V_37 , V_44 + 1 + ( V_3 * 8 ) + 7 ) ) ) {
case V_412 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_44 ) ;
return - V_41 ;
}
V_75 [ V_44 + 1 + ( V_3 * 8 ) + 2 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
if ( V_88 -> V_128 . V_134 & V_135 )
V_75 [ V_44 + 1 + ( V_3 * 8 ) + 1 ] |= F_31 ( V_136 ) ;
else if ( V_88 -> V_128 . V_134 & V_175 )
V_75 [ V_44 + 1 + ( V_3 * 8 ) + 1 ] |= F_31 ( V_137 ) ;
V_376 = V_88 -> V_142 ;
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_44 ) ;
return - V_41 ;
}
V_75 [ V_44 + 1 + ( V_3 * 8 ) + 3 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 >> 8 ) & 0xffffffff ) ;
V_377 = V_88 -> V_142 ;
V_62 = F_27 ( V_37 , V_44 + 1 + ( V_3 * 8 ) ,
V_376 , V_377 ) ;
if ( V_62 )
return V_62 ;
break;
case V_413 :
V_62 = F_12 ( V_37 , & V_88 ) ;
if ( V_62 ) {
F_6 ( L_45 ) ;
return - V_41 ;
}
V_411 = F_7 ( V_37 , V_44 + 1 + ( V_3 * 8 ) + 0 ) ;
V_410 = F_7 ( V_37 , V_44 + 1 + ( V_3 * 8 ) + 1 ) ;
if ( V_37 -> V_80 && ( V_410 + V_411 ) > F_32 ( V_88 -> V_142 ) ) {
F_4 ( V_37 -> V_40 , L_46 ) ;
V_75 [ V_44 + 1 + ( V_3 * 8 ) + 1 ] = F_32 ( V_88 -> V_142 ) ;
}
V_75 [ V_44 + 1 + ( V_3 * 8 ) + 0 ] += ( T_2 ) ( ( V_88 -> V_128 . V_129 ) & 0xffffffff ) ;
V_75 [ V_44 + 1 + ( V_3 * 8 ) + 2 ] += F_29 ( V_88 -> V_128 . V_129 ) & 0xff ;
break;
case V_414 :
case V_415 :
default:
F_6 ( L_43 ) ;
return - V_41 ;
}
}
break;
case V_416 :
break;
case V_417 :
V_378 = ( V_380 << 2 ) + V_418 ;
V_379 = 4 * V_43 -> V_51 + V_378 - 4 ;
if ( ( V_378 < V_418 ) ||
( V_378 >= V_419 ) ||
( V_379 >= V_419 ) ) {
F_6 ( L_47 ) ;
return - V_41 ;
}
break;
case V_420 :
V_378 = ( V_380 << 2 ) + V_421 ;
V_379 = 4 * V_43 -> V_51 + V_378 - 4 ;
if ( ( V_378 < V_421 ) ||
( V_378 >= V_422 ) ||
( V_379 >= V_422 ) ) {
F_6 ( L_48 ) ;
return - V_41 ;
}
break;
case V_423 :
V_378 = ( V_380 << 2 ) + V_424 ;
V_379 = 4 * V_43 -> V_51 + V_378 - 4 ;
if ( ( V_378 < V_424 ) ||
( V_378 >= V_425 ) ||
( V_379 >= V_425 ) ) {
F_6 ( L_49 ) ;
return - V_41 ;
}
break;
case V_426 :
if ( V_43 -> V_51 % 3 ) {
F_6 ( L_50 ) ;
return - V_41 ;
}
V_378 = ( V_380 << 2 ) + V_427 ;
V_379 = 4 * V_43 -> V_51 + V_378 - 4 ;
if ( ( V_378 < V_427 ) ||
( V_378 >= V_428 ) ||
( V_379 >= V_428 ) ) {
F_6 ( L_50 ) ;
return - V_41 ;
}
break;
case V_64 :
break;
default:
F_6 ( L_51 , V_43 -> V_56 ) ;
return - V_41 ;
}
return 0 ;
}
int F_33 ( struct V_36 * V_37 )
{
struct V_42 V_43 ;
struct V_1 * V_2 ;
int V_62 ;
if ( V_37 -> V_2 == NULL ) {
V_2 = F_34 ( sizeof( * V_2 ) , V_429 ) ;
if ( V_2 == NULL )
return - V_430 ;
F_1 ( V_2 ) ;
V_2 -> V_431 = V_37 -> V_80 -> V_432 . V_433 . V_434 ;
V_2 -> V_435 = V_37 -> V_80 -> V_432 . V_433 . V_436 ;
V_2 -> V_437 = V_37 -> V_80 -> V_432 . V_433 . V_438 ;
V_37 -> V_2 = V_2 ;
}
do {
V_62 = F_5 ( V_37 , & V_43 , V_37 -> V_44 ) ;
if ( V_62 ) {
F_35 ( V_37 -> V_2 ) ;
V_37 -> V_2 = NULL ;
return V_62 ;
}
V_37 -> V_44 += V_43 . V_51 + 2 ;
switch ( V_43 . type ) {
case V_53 :
V_62 = F_21 ( V_37 , & V_43 ) ;
break;
case V_57 :
break;
case V_55 :
V_62 = F_28 ( V_37 , & V_43 ) ;
break;
default:
F_6 ( L_52 , V_43 . type ) ;
F_35 ( V_37 -> V_2 ) ;
V_37 -> V_2 = NULL ;
return - V_41 ;
}
if ( V_62 ) {
F_35 ( V_37 -> V_2 ) ;
V_37 -> V_2 = NULL ;
return V_62 ;
}
} while ( V_37 -> V_44 < V_37 -> V_47 [ V_37 -> V_48 ] . V_50 );
#if 0
for (r = 0; r < p->ib->length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib->ptr[r]);
mdelay(1);
}
#endif
F_35 ( V_37 -> V_2 ) ;
V_37 -> V_2 = NULL ;
return 0 ;
}
