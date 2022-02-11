static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 & V_2 )
return V_3 ;
else if ( V_1 & V_4 )
return V_5 ;
else
return V_6 ;
}
static T_1 F_2 ( T_1 V_7 )
{
switch ( V_7 ) {
case 2 :
return V_8 ;
case 4 :
return V_9 ;
case 8 :
default:
return V_10 ;
case 16 :
return V_11 ;
}
}
static T_1 F_3 ( T_1 V_12 )
{
switch ( V_12 ) {
case 1 :
default:
return V_13 ;
case 2 :
return V_14 ;
case 4 :
return V_15 ;
}
}
static void F_4 ( struct V_16 * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_17 -> V_19 [ V_18 ] = NULL ;
V_17 -> V_20 [ V_18 ] = NULL ;
V_17 -> V_21 [ V_18 ] = 0 ;
V_17 -> V_22 [ V_18 ] = 0 ;
}
for ( V_18 = 0 ; V_18 < 12 ; V_18 ++ ) {
V_17 -> V_23 [ V_18 ] = 0 ;
V_17 -> V_24 [ V_18 ] = NULL ;
V_17 -> V_25 [ V_18 ] = 0xFFFFFFFF ;
V_17 -> V_26 [ V_18 ] = 0 ;
V_17 -> V_27 [ V_18 ] = 0 ;
V_17 -> V_28 [ V_18 ] = 0 ;
V_17 -> V_29 [ V_18 ] = 0 ;
V_17 -> V_30 [ V_18 ] = 0 ;
V_17 -> V_31 [ V_18 ] = 0 ;
V_17 -> V_32 [ V_18 ] = 0 ;
V_17 -> V_30 [ V_18 ] = 0 ;
}
V_17 -> V_33 = 0xFFFFFFFF ;
V_17 -> V_34 = 0xFFFFFFFF ;
V_17 -> V_35 = 0xFFFFC000 ;
V_17 -> V_36 = 0xFFFFFFFF ;
V_17 -> V_37 = 0 ;
V_17 -> V_38 = 0xFFFFFFFF ;
V_17 -> V_39 = 0xFFFFFFFF ;
V_17 -> V_40 = 0xFFFFFFFF ;
V_17 -> V_41 = 0xFFFFFFFF ;
V_17 -> V_42 = 0xFFFFFFFF ;
V_17 -> V_43 = NULL ;
V_17 -> V_44 = NULL ;
V_17 -> V_45 = 0xFFFFFFFF ;
V_17 -> V_46 = 0xFFFFFFFF ;
V_17 -> V_47 = 0xFFFFFFFF ;
V_17 -> V_48 = 0xFFFFFFFF ;
V_17 -> V_49 = NULL ;
V_17 -> V_50 = NULL ;
}
static int F_5 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = V_52 -> V_17 ;
if ( V_17 -> V_53 || V_17 -> V_54 ) {
F_6 ( V_52 -> V_55 , L_1 ) ;
return - V_56 ;
}
return 0 ;
}
int F_7 ( struct V_51 * V_52 ,
struct V_57 * V_58 ,
unsigned V_59 )
{
struct V_60 * V_61 = & V_52 -> V_62 [ V_52 -> V_63 ] ;
T_2 V_64 ;
if ( V_59 >= V_61 -> V_65 ) {
F_8 ( L_2 ,
V_59 , V_61 -> V_65 ) ;
return - V_56 ;
}
V_64 = F_9 ( V_52 , V_59 ) ;
V_58 -> V_59 = V_59 ;
V_58 -> type = F_10 ( V_64 ) ;
V_58 -> V_66 = F_11 ( V_64 ) ;
V_58 -> V_67 = 0 ;
switch ( V_58 -> type ) {
case V_68 :
V_58 -> V_69 = F_12 ( V_64 ) ;
break;
case V_70 :
V_58 -> V_71 = F_13 ( V_64 ) ;
break;
case V_72 :
V_58 -> V_66 = - 1 ;
break;
default:
F_8 ( L_3 , V_58 -> type , V_59 ) ;
return - V_56 ;
}
if ( ( V_58 -> V_66 + 1 + V_58 -> V_59 ) >= V_61 -> V_65 ) {
F_8 ( L_4 ,
V_58 -> V_59 , V_58 -> type , V_58 -> V_66 , V_61 -> V_65 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_14 ( struct V_51 * V_52 ,
struct V_73 * * V_74 )
{
struct V_60 * V_75 ;
struct V_57 V_76 ;
unsigned V_59 ;
int V_77 ;
if ( V_52 -> V_78 == - 1 ) {
F_8 ( L_5 ) ;
return - V_56 ;
}
* V_74 = NULL ;
V_75 = & V_52 -> V_62 [ V_52 -> V_78 ] ;
V_77 = F_7 ( V_52 , & V_76 , V_52 -> V_59 ) ;
if ( V_77 ) {
return V_77 ;
}
V_52 -> V_59 += V_76 . V_66 + 2 ;
if ( V_76 . type != V_70 || V_76 . V_71 != V_79 ) {
F_8 ( L_6 ,
V_76 . V_59 ) ;
return - V_56 ;
}
V_59 = F_9 ( V_52 , V_76 . V_59 + 1 ) ;
if ( V_59 >= V_75 -> V_65 ) {
F_8 ( L_7 ,
V_59 , V_75 -> V_65 ) ;
return - V_56 ;
}
* V_74 = V_52 -> V_80 [ ( V_59 / 4 ) ] ;
return 0 ;
}
static int F_15 ( struct V_51 * V_52 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_85 ;
struct V_57 V_76 , V_86 ;
int V_87 ;
int V_77 ;
T_2 V_64 , V_88 , V_69 , V_89 ;
volatile T_2 * V_90 ;
V_90 = V_52 -> V_90 -> V_91 ;
V_77 = F_7 ( V_52 , & V_86 , V_52 -> V_59 ) ;
if ( V_77 )
return V_77 ;
if ( V_86 . type != V_70 ||
V_86 . V_71 != V_92 ) {
F_8 ( L_8 ) ;
return - V_56 ;
}
V_89 = F_9 ( V_52 , V_86 . V_59 + 1 ) ;
if ( V_89 & 0x10 ) {
F_8 ( L_9 ) ;
return - V_56 ;
}
if ( ( V_89 & 0x7 ) != 0x3 ) {
F_8 ( L_10 ) ;
return - V_56 ;
}
if ( ( F_9 ( V_52 , V_86 . V_59 + 2 ) << 2 ) != V_93 ) {
F_8 ( L_11 ) ;
return - V_56 ;
}
if ( F_9 ( V_52 , V_86 . V_59 + 5 ) != V_94 ) {
F_8 ( L_12 ) ;
return - V_56 ;
}
V_77 = F_7 ( V_52 , & V_76 , V_52 -> V_59 + V_86 . V_66 + 2 ) ;
if ( V_77 )
return V_77 ;
V_88 = V_52 -> V_59 - 2 ;
V_52 -> V_59 += V_86 . V_66 + 2 ;
V_52 -> V_59 += V_76 . V_66 + 2 ;
V_64 = F_9 ( V_52 , V_88 ) ;
V_87 = F_9 ( V_52 , V_88 + 2 + 7 + 1 ) ;
V_69 = F_12 ( V_64 ) ;
V_82 = F_16 ( V_52 -> V_95 -> V_96 , V_87 , V_97 ) ;
if ( ! V_82 ) {
F_8 ( L_13 , V_87 ) ;
return - V_56 ;
}
V_84 = F_17 ( V_82 ) ;
V_85 = F_18 ( V_84 ) ;
V_87 = V_85 -> V_87 ;
if ( ! V_84 -> V_98 ) {
V_90 [ V_88 + 2 ] = F_19 ( 0 ) ;
V_90 [ V_88 + 3 ] = F_19 ( 0 ) ;
V_90 [ V_88 + 4 ] = F_19 ( 0 ) ;
V_90 [ V_88 + 5 ] = F_19 ( 0 ) ;
V_90 [ V_88 + 6 ] = F_19 ( 0 ) ;
V_90 [ V_88 + 7 ] = F_19 ( 0 ) ;
V_90 [ V_88 + 8 ] = F_19 ( 0 ) ;
} else {
switch ( V_69 ) {
case V_99 :
V_64 &= ~ V_100 ;
V_64 |= ( V_99 + V_85 -> V_101 ) >> 2 ;
V_90 [ V_88 ] = V_64 ;
V_90 [ V_88 + 4 ] = ( V_93 + V_85 -> V_101 ) >> 2 ;
break;
default:
F_8 ( L_14 ) ;
return - V_56 ;
}
}
return 0 ;
}
static int F_20 ( struct V_51 * V_52 ,
struct V_57 * V_58 ,
unsigned V_59 , unsigned V_69 )
{
int V_77 ;
switch ( V_69 ) {
case V_99 :
V_77 = F_15 ( V_52 ) ;
if ( V_77 ) {
F_8 ( L_15 ,
V_59 , V_69 ) ;
return V_77 ;
}
break;
default:
F_21 ( V_102 L_16 ,
V_69 , V_59 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_22 ( struct V_51 * V_52 ,
struct V_57 * V_58 )
{
unsigned V_69 , V_18 ;
unsigned V_59 ;
int V_77 ;
V_59 = V_58 -> V_59 + 1 ;
V_69 = V_58 -> V_69 ;
for ( V_18 = 0 ; V_18 <= V_58 -> V_66 ; V_18 ++ , V_59 ++ , V_69 += 4 ) {
V_77 = F_20 ( V_52 , V_58 , V_59 , V_69 ) ;
if ( V_77 ) {
return V_77 ;
}
}
return 0 ;
}
static int F_23 ( struct V_51 * V_52 , T_1 V_69 , T_1 V_59 )
{
struct V_16 * V_17 = (struct V_16 * ) V_52 -> V_17 ;
struct V_73 * V_103 ;
T_1 V_104 ;
T_1 V_105 , V_18 , V_106 , * V_90 ;
int V_77 ;
if ( V_52 -> V_95 -> V_107 >= V_108 )
V_104 = F_24 ( V_109 ) ;
else
V_104 = F_24 ( V_110 ) ;
V_18 = ( V_69 >> 7 ) ;
if ( V_18 >= V_104 ) {
F_6 ( V_52 -> V_55 , L_17 , V_69 , V_59 ) ;
return - V_56 ;
}
V_105 = 1 << ( ( V_69 >> 2 ) & 31 ) ;
if ( V_52 -> V_95 -> V_107 >= V_108 ) {
if ( ! ( V_109 [ V_18 ] & V_105 ) )
return 0 ;
} else {
if ( ! ( V_110 [ V_18 ] & V_105 ) )
return 0 ;
}
V_90 = V_52 -> V_90 -> V_91 ;
switch ( V_69 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
break;
case V_145 :
V_17 -> V_38 = F_9 ( V_52 , V_59 ) ;
break;
case V_146 :
if ( V_52 -> V_95 -> V_107 < V_108 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
break;
case V_147 :
if ( V_52 -> V_95 -> V_107 < V_108 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
break;
case V_148 :
V_17 -> V_39 = F_9 ( V_52 , V_59 ) ;
if ( ! V_52 -> V_149 ) {
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] &= ~ F_25 ( 0xf ) ;
V_17 -> V_39 &= ~ F_25 ( 0xf ) ;
V_90 [ V_59 ] |= F_25 ( F_1 ( V_103 -> V_143 . V_1 ) ) ;
V_17 -> V_39 |= F_25 ( F_1 ( V_103 -> V_143 . V_1 ) ) ;
if ( V_103 -> V_143 . V_1 & V_2 ) {
V_90 [ V_59 ] |= F_26 ( F_2 ( V_17 -> V_7 ) ) ;
V_90 [ V_59 ] |= F_27 ( F_3 ( V_17 -> V_12 ) ) ;
}
}
break;
case V_150 :
V_17 -> V_45 = F_9 ( V_52 , V_59 ) ;
break;
case V_151 :
V_17 -> V_35 = F_9 ( V_52 , V_59 ) ;
break;
case V_152 :
V_17 -> V_36 = F_9 ( V_52 , V_59 ) ;
V_17 -> V_37 = V_59 ;
break;
case V_153 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_17 -> V_41 = F_9 ( V_52 , V_59 ) ;
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_43 = V_103 -> V_154 ;
break;
case V_155 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_17 -> V_42 = F_9 ( V_52 , V_59 ) ;
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_44 = V_103 -> V_154 ;
break;
case V_156 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_17 -> V_47 = F_9 ( V_52 , V_59 ) ;
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_49 = V_103 -> V_154 ;
break;
case V_157 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_17 -> V_48 = F_9 ( V_52 , V_59 ) ;
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_50 = V_103 -> V_154 ;
break;
case V_158 :
V_17 -> V_53 = F_9 ( V_52 , V_59 ) ;
break;
case V_159 :
V_17 -> V_54 = F_9 ( V_52 , V_59 ) ;
break;
case V_160 :
V_17 -> V_33 = F_9 ( V_52 , V_59 ) ;
break;
case V_161 :
V_17 -> V_34 = F_9 ( V_52 , V_59 ) ;
break;
case V_162 :
if ( V_52 -> V_95 -> V_107 >= V_108 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_106 = F_9 ( V_52 , V_59 ) & V_163 ;
V_17 -> V_164 = 1 << V_106 ;
break;
case V_165 :
if ( V_52 -> V_95 -> V_107 < V_108 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_106 = F_9 ( V_52 , V_59 ) & V_166 ;
V_17 -> V_164 = 1 << V_106 ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_106 = ( V_69 - V_167 ) / 0x3c ;
V_17 -> V_27 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
break;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
V_106 = ( ( V_69 - V_175 ) / 0x1c ) + 8 ;
V_17 -> V_27 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
V_106 = ( V_69 - V_179 ) / 0x3c ;
V_17 -> V_26 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
if ( ! V_52 -> V_149 ) {
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] |= F_28 ( F_1 ( V_103 -> V_143 . V_1 ) ) ;
V_17 -> V_26 [ V_106 ] |= F_28 ( F_1 ( V_103 -> V_143 . V_1 ) ) ;
}
break;
case V_187 :
case V_188 :
case V_189 :
case V_190 :
V_106 = ( ( V_69 - V_187 ) / 0x1c ) + 8 ;
V_17 -> V_26 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
if ( ! V_52 -> V_149 ) {
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] |= F_28 ( F_1 ( V_103 -> V_143 . V_1 ) ) ;
V_17 -> V_26 [ V_106 ] |= F_28 ( F_1 ( V_103 -> V_143 . V_1 ) ) ;
}
break;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
V_106 = ( V_69 - V_191 ) / 0x3c ;
V_17 -> V_31 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_17 -> V_28 [ V_106 ] = V_59 ;
break;
case V_199 :
case V_200 :
case V_201 :
case V_202 :
V_106 = ( ( V_69 - V_199 ) / 0x1c ) + 8 ;
V_17 -> V_31 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_17 -> V_28 [ V_106 ] = V_59 ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
V_106 = ( V_69 - V_203 ) / 0x3c ;
V_17 -> V_32 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_17 -> V_29 [ V_106 ] = V_59 ;
break;
case V_211 :
case V_212 :
case V_213 :
case V_214 :
V_106 = ( ( V_69 - V_211 ) / 0x1c ) + 8 ;
V_17 -> V_32 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_17 -> V_29 [ V_106 ] = V_59 ;
break;
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
if ( V_103 -> V_143 . V_1 & V_2 ) {
V_90 [ V_59 ] |= F_29 ( F_2 ( V_17 -> V_7 ) ) ;
V_90 [ V_59 ] |= F_30 ( F_3 ( V_17 -> V_12 ) ) ;
}
break;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
V_106 = ( V_69 - V_227 ) / 0x3c ;
V_17 -> V_30 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_17 -> V_235 [ V_106 ] = V_59 ;
break;
case V_236 :
case V_237 :
case V_238 :
case V_239 :
V_106 = ( ( V_69 - V_236 ) / 0x1c ) + 8 ;
V_17 -> V_30 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_17 -> V_235 [ V_106 ] = V_59 ;
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
V_106 = ( V_69 - V_240 ) / 0x3c ;
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_31 ( V_52 -> V_55 , L_20 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_19 [ V_106 ] = V_103 -> V_154 ;
break;
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_106 = ( V_69 - V_248 ) / 0x3c ;
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_31 ( V_52 -> V_55 , L_20 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_20 [ V_106 ] = V_103 -> V_154 ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
V_106 = ( V_69 - V_256 ) / 0x3c ;
V_17 -> V_22 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
break;
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
V_106 = ( V_69 - V_264 ) / 0x3c ;
V_17 -> V_21 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_106 = ( V_69 - V_272 ) / 0x3c ;
V_17 -> V_25 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_23 [ V_106 ] = V_90 [ V_59 ] ;
V_17 -> V_24 [ V_106 ] = V_103 -> V_154 ;
break;
case V_280 :
case V_281 :
case V_282 :
case V_283 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_106 = ( ( V_69 - V_280 ) / 0x1c ) + 8 ;
V_17 -> V_25 [ V_106 ] = F_9 ( V_52 , V_59 ) ;
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_17 -> V_23 [ V_106 ] = V_90 [ V_59 ] ;
V_17 -> V_24 [ V_106 ] = V_103 -> V_154 ;
break;
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
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
break;
case V_385 :
if ( V_52 -> V_95 -> V_107 >= V_108 ) {
F_6 ( V_52 -> V_55 , L_21
L_19 , V_69 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_21
L_19 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
break;
case V_386 :
if ( V_52 -> V_95 -> V_107 < V_108 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_18
L_19 , V_69 ) ;
return - V_56 ;
}
V_90 [ V_59 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
break;
default:
F_6 ( V_52 -> V_55 , L_17 , V_69 , V_59 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_32 ( struct V_51 * V_52 , T_1 V_59 ,
struct V_387 * V_388 ,
struct V_387 * V_389 )
{
return 0 ;
}
static int F_33 ( struct V_51 * V_52 ,
struct V_57 * V_58 )
{
struct V_73 * V_103 ;
struct V_16 * V_17 ;
volatile T_1 * V_90 ;
unsigned V_59 ;
unsigned V_18 ;
unsigned V_390 , V_391 , V_69 ;
int V_77 ;
T_1 V_392 ;
V_17 = (struct V_16 * ) V_52 -> V_17 ;
V_90 = V_52 -> V_90 -> V_91 ;
V_59 = V_58 -> V_59 + 1 ;
V_392 = F_9 ( V_52 , V_59 ) ;
switch ( V_58 -> V_71 ) {
case V_393 :
{
int V_394 ;
int V_106 ;
if ( V_58 -> V_66 != 1 ) {
F_8 ( L_22 ) ;
return - V_56 ;
}
V_106 = F_9 ( V_52 , V_59 + 1 ) ;
V_394 = ( V_106 >> 16 ) & 0x7 ;
if ( V_394 == 0 )
return 0 ;
if ( V_394 > 2 ) {
F_8 ( L_23 , V_394 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_22 ) ;
return - V_56 ;
}
V_90 [ V_59 + 0 ] = V_392 + ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 1 ] = V_106 + ( F_34 ( V_103 -> V_143 . V_144 ) & 0xff ) ;
}
break;
case V_395 :
if ( V_58 -> V_66 != 1 ) {
F_8 ( L_24 ) ;
return - V_56 ;
}
break;
case V_396 :
case V_397 :
case V_398 :
if ( V_58 -> V_66 ) {
F_8 ( L_25 ) ;
return - V_56 ;
}
break;
case V_399 :
if ( V_52 -> V_95 -> V_107 < V_108 ) {
F_8 ( L_26 ) ;
return - V_56 ;
}
if ( V_58 -> V_66 ) {
F_8 ( L_25 ) ;
return - V_56 ;
}
break;
case V_400 :
if ( V_58 -> V_66 != 1 ) {
F_8 ( L_27 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_27 ) ;
return - V_56 ;
}
V_90 [ V_59 + 0 ] = V_392 + ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 1 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_28 , V_401 , __LINE__ ) ;
return V_77 ;
}
break;
case V_402 :
if ( V_58 -> V_66 != 3 ) {
F_8 ( L_29 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_29 ) ;
return - V_56 ;
}
V_90 [ V_59 + 0 ] = V_392 + ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 1 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_28 , V_401 , __LINE__ ) ;
return V_77 ;
}
break;
case V_403 :
if ( V_58 -> V_66 != 4 ) {
F_8 ( L_30 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_30 ) ;
return - V_56 ;
}
V_90 [ V_59 + 1 ] = V_392 + ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 2 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_28 , V_401 , __LINE__ ) ;
return V_77 ;
}
break;
case V_404 :
if ( V_58 -> V_66 != 1 ) {
F_8 ( L_31 ) ;
return - V_56 ;
}
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_32 , V_401 , __LINE__ , V_59 ) ;
return V_77 ;
}
break;
case V_405 :
if ( V_58 -> V_66 != 2 ) {
F_8 ( L_33 ) ;
return - V_56 ;
}
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_32 , V_401 , __LINE__ , V_59 ) ;
return V_77 ;
}
break;
case V_406 :
if ( V_58 -> V_66 < 2 ) {
F_8 ( L_34 ) ;
return - V_56 ;
}
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_28 , V_401 , __LINE__ ) ;
return V_77 ;
}
break;
case V_407 :
if ( V_58 -> V_66 != 2 ) {
F_8 ( L_35 ) ;
return - V_56 ;
}
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_28 , V_401 , __LINE__ ) ;
return V_77 ;
}
break;
case V_408 :
if ( V_58 -> V_66 != 3 ) {
F_8 ( L_36 ) ;
return - V_56 ;
}
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_28 , V_401 , __LINE__ ) ;
return V_77 ;
}
break;
case V_409 :
if ( V_58 -> V_66 != 3 ) {
F_8 ( L_37 ) ;
return - V_56 ;
}
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_32 , V_401 , __LINE__ , V_59 ) ;
return V_77 ;
}
break;
case V_410 :
if ( V_58 -> V_66 != 1 ) {
F_8 ( L_38 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_38 ) ;
return - V_56 ;
}
V_90 [ V_59 + 0 ] = V_392 + ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_77 = F_5 ( V_52 ) ;
if ( V_77 ) {
F_6 ( V_52 -> V_55 , L_28 , V_401 , __LINE__ ) ;
return V_77 ;
}
break;
case V_92 :
if ( V_58 -> V_66 != 5 ) {
F_8 ( L_39 ) ;
return - V_56 ;
}
if ( V_392 & 0x10 ) {
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_39 ) ;
return - V_56 ;
}
V_90 [ V_59 + 1 ] += ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 2 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
}
break;
case V_411 :
if ( V_58 -> V_66 != 3 ) {
F_8 ( L_40 ) ;
return - V_56 ;
}
if ( F_9 ( V_52 , V_59 + 1 ) != 0xffffffff ||
F_9 ( V_52 , V_59 + 2 ) != 0 ) {
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_40 ) ;
return - V_56 ;
}
V_90 [ V_59 + 2 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
}
break;
case V_412 :
if ( V_58 -> V_66 != 2 && V_58 -> V_66 != 0 ) {
F_8 ( L_41 ) ;
return - V_56 ;
}
if ( V_58 -> V_66 ) {
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_41 ) ;
return - V_56 ;
}
V_90 [ V_59 + 1 ] += ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 2 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
}
break;
case V_413 :
if ( V_58 -> V_66 != 4 ) {
F_8 ( L_42 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_42 ) ;
return - V_56 ;
}
V_90 [ V_59 + 1 ] += ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 2 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
break;
case V_414 :
if ( V_58 -> V_66 != 3 ) {
F_8 ( L_43 ) ;
return - V_56 ;
}
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_43 ) ;
return - V_56 ;
}
V_90 [ V_59 + 1 ] += ( T_1 ) ( V_103 -> V_143 . V_144 & 0xffffffff ) ;
V_90 [ V_59 + 2 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
break;
case V_415 :
V_390 = ( V_392 << 2 ) + V_416 ;
V_391 = 4 * V_58 -> V_66 + V_390 - 4 ;
if ( ( V_390 < V_416 ) ||
( V_390 >= V_417 ) ||
( V_391 >= V_417 ) ) {
F_8 ( L_44 ) ;
return - V_56 ;
}
for ( V_18 = 0 ; V_18 < V_58 -> V_66 ; V_18 ++ ) {
V_69 = V_390 + ( 4 * V_18 ) ;
V_77 = F_23 ( V_52 , V_69 , V_59 + 1 + V_18 ) ;
if ( V_77 )
return V_77 ;
}
break;
case V_418 :
V_390 = ( V_392 << 2 ) + V_419 ;
V_391 = 4 * V_58 -> V_66 + V_390 - 4 ;
if ( ( V_390 < V_419 ) ||
( V_390 >= V_420 ) ||
( V_391 >= V_420 ) ) {
F_8 ( L_45 ) ;
return - V_56 ;
}
for ( V_18 = 0 ; V_18 < V_58 -> V_66 ; V_18 ++ ) {
V_69 = V_390 + ( 4 * V_18 ) ;
V_77 = F_23 ( V_52 , V_69 , V_59 + 1 + V_18 ) ;
if ( V_77 )
return V_77 ;
}
break;
case V_421 :
if ( V_58 -> V_66 % 8 ) {
F_8 ( L_46 ) ;
return - V_56 ;
}
V_390 = ( V_392 << 2 ) + V_422 ;
V_391 = 4 * V_58 -> V_66 + V_390 - 4 ;
if ( ( V_390 < V_422 ) ||
( V_390 >= V_423 ) ||
( V_391 >= V_423 ) ) {
F_8 ( L_46 ) ;
return - V_56 ;
}
for ( V_18 = 0 ; V_18 < ( V_58 -> V_66 / 8 ) ; V_18 ++ ) {
struct V_387 * V_388 , * V_389 ;
T_1 V_424 , V_425 ;
switch ( F_35 ( F_9 ( V_52 , V_59 + 1 + ( V_18 * 8 ) + 7 ) ) ) {
case V_426 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_47 ) ;
return - V_56 ;
}
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 2 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
if ( ! V_52 -> V_149 ) {
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 1 ] |=
F_36 ( F_1 ( V_103 -> V_143 . V_1 ) ) ;
if ( V_103 -> V_143 . V_1 & V_2 ) {
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 6 ] |=
F_37 ( F_3 ( V_17 -> V_12 ) ) ;
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 7 ] |=
F_38 ( F_2 ( V_17 -> V_7 ) ) ;
}
}
V_388 = V_103 -> V_154 ;
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_47 ) ;
return - V_56 ;
}
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 3 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 >> 8 ) & 0xffffffff ) ;
V_389 = V_103 -> V_154 ;
V_77 = F_32 ( V_52 , V_59 + 1 + ( V_18 * 8 ) ,
V_388 , V_389 ) ;
if ( V_77 )
return V_77 ;
break;
case V_427 :
V_77 = F_14 ( V_52 , & V_103 ) ;
if ( V_77 ) {
F_8 ( L_48 ) ;
return - V_56 ;
}
V_425 = F_9 ( V_52 , V_59 + 1 + ( V_18 * 8 ) + 0 ) ;
V_424 = F_9 ( V_52 , V_59 + 1 + ( V_18 * 8 ) + 1 ) ;
if ( V_52 -> V_95 && ( V_424 + V_425 ) > F_39 ( V_103 -> V_154 ) ) {
F_6 ( V_52 -> V_55 , L_49 ) ;
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 1 ] = F_39 ( V_103 -> V_154 ) ;
}
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 0 ] += ( T_1 ) ( ( V_103 -> V_143 . V_144 ) & 0xffffffff ) ;
V_90 [ V_59 + 1 + ( V_18 * 8 ) + 2 ] += F_34 ( V_103 -> V_143 . V_144 ) & 0xff ;
break;
case V_428 :
case V_429 :
default:
F_8 ( L_46 ) ;
return - V_56 ;
}
}
break;
case V_430 :
break;
case V_431 :
V_390 = ( V_392 << 2 ) + V_432 ;
V_391 = 4 * V_58 -> V_66 + V_390 - 4 ;
if ( ( V_390 < V_432 ) ||
( V_390 >= V_433 ) ||
( V_391 >= V_433 ) ) {
F_8 ( L_50 ) ;
return - V_56 ;
}
break;
case V_434 :
V_390 = ( V_392 << 2 ) + V_435 ;
V_391 = 4 * V_58 -> V_66 + V_390 - 4 ;
if ( ( V_390 < V_435 ) ||
( V_390 >= V_436 ) ||
( V_391 >= V_436 ) ) {
F_8 ( L_51 ) ;
return - V_56 ;
}
break;
case V_437 :
V_390 = ( V_392 << 2 ) + V_438 ;
V_391 = 4 * V_58 -> V_66 + V_390 - 4 ;
if ( ( V_390 < V_438 ) ||
( V_390 >= V_439 ) ||
( V_391 >= V_439 ) ) {
F_8 ( L_52 ) ;
return - V_56 ;
}
break;
case V_440 :
if ( V_58 -> V_66 % 3 ) {
F_8 ( L_53 ) ;
return - V_56 ;
}
V_390 = ( V_392 << 2 ) + V_441 ;
V_391 = 4 * V_58 -> V_66 + V_390 - 4 ;
if ( ( V_390 < V_441 ) ||
( V_390 >= V_442 ) ||
( V_391 >= V_442 ) ) {
F_8 ( L_53 ) ;
return - V_56 ;
}
break;
case V_79 :
break;
default:
F_8 ( L_54 , V_58 -> V_71 ) ;
return - V_56 ;
}
return 0 ;
}
int F_40 ( struct V_51 * V_52 )
{
struct V_57 V_58 ;
struct V_16 * V_17 ;
T_1 V_106 ;
int V_77 ;
if ( V_52 -> V_17 == NULL ) {
V_17 = F_41 ( sizeof( * V_17 ) , V_443 ) ;
if ( V_17 == NULL )
return - V_444 ;
F_4 ( V_17 ) ;
if ( V_52 -> V_95 -> V_107 >= V_108 )
V_106 = V_52 -> V_95 -> V_445 . V_446 . V_447 ;
else
V_106 = V_52 -> V_95 -> V_445 . V_448 . V_447 ;
switch ( V_106 & 0xf ) {
case 0 :
V_17 -> V_449 = 1 ;
break;
case 1 :
default:
V_17 -> V_449 = 2 ;
break;
case 2 :
V_17 -> V_449 = 4 ;
break;
case 3 :
V_17 -> V_449 = 8 ;
break;
}
switch ( ( V_106 & 0xf0 ) >> 4 ) {
case 0 :
V_17 -> V_7 = 4 ;
break;
case 1 :
default:
V_17 -> V_7 = 8 ;
break;
case 2 :
V_17 -> V_7 = 16 ;
break;
}
switch ( ( V_106 & 0xf00 ) >> 8 ) {
case 0 :
V_17 -> V_450 = 256 ;
break;
case 1 :
default:
V_17 -> V_450 = 512 ;
break;
}
switch ( ( V_106 & 0xf000 ) >> 12 ) {
case 0 :
V_17 -> V_12 = 1 ;
break;
case 1 :
default:
V_17 -> V_12 = 2 ;
break;
case 2 :
V_17 -> V_12 = 4 ;
break;
}
V_52 -> V_17 = V_17 ;
}
do {
V_77 = F_7 ( V_52 , & V_58 , V_52 -> V_59 ) ;
if ( V_77 ) {
F_42 ( V_52 -> V_17 ) ;
V_52 -> V_17 = NULL ;
return V_77 ;
}
V_52 -> V_59 += V_58 . V_66 + 2 ;
switch ( V_58 . type ) {
case V_68 :
V_77 = F_22 ( V_52 , & V_58 ) ;
break;
case V_72 :
break;
case V_70 :
V_77 = F_33 ( V_52 , & V_58 ) ;
break;
default:
F_8 ( L_55 , V_58 . type ) ;
F_42 ( V_52 -> V_17 ) ;
V_52 -> V_17 = NULL ;
return - V_56 ;
}
if ( V_77 ) {
F_42 ( V_52 -> V_17 ) ;
V_52 -> V_17 = NULL ;
return V_77 ;
}
} while ( V_52 -> V_59 < V_52 -> V_62 [ V_52 -> V_63 ] . V_65 );
#if 0
for (r = 0; r < p->ib->length_dw; r++) {
printk(KERN_INFO "%05d 0x%08X\n", r, p->ib->ptr[r]);
mdelay(1);
}
#endif
F_42 ( V_52 -> V_17 ) ;
V_52 -> V_17 = NULL ;
return 0 ;
}
