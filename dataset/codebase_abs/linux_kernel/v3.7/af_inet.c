void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_7 == V_8 && V_2 -> V_9 != V_10 ) {
F_5 ( L_1 ,
V_2 -> V_9 , V_2 ) ;
return;
}
if ( ! F_6 ( V_2 , V_11 ) ) {
F_5 ( L_2 , V_2 ) ;
return;
}
F_7 ( F_8 ( & V_2 -> V_12 ) ) ;
F_7 ( F_8 ( & V_2 -> V_13 ) ) ;
F_7 ( V_2 -> V_14 ) ;
F_7 ( V_2 -> V_15 ) ;
F_9 ( F_10 ( V_4 -> V_16 , 1 ) ) ;
F_11 ( F_12 ( V_2 -> V_17 , 1 ) ) ;
F_11 ( V_2 -> V_18 ) ;
F_13 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_15 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_19 ) {
if ( V_2 -> V_20 -> V_21 ( V_2 , 0 ) ) {
F_16 ( V_2 ) ;
return - V_22 ;
}
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
int F_18 ( struct V_24 * V_1 , int V_25 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned char V_26 ;
int V_27 ;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_1 -> V_29 != V_30 || V_1 -> type != V_8 )
goto V_31;
V_26 = V_2 -> V_9 ;
if ( ! ( ( 1 << V_26 ) & ( V_32 | V_33 ) ) )
goto V_31;
if ( V_26 != V_34 ) {
if ( ( V_35 & V_36 ) != 0 &&
F_19 ( V_2 ) -> V_37 . V_38 == NULL ) {
if ( ( V_35 & V_39 ) != 0 )
V_27 = F_20 ( V_2 , V_25 ) ;
else if ( ( V_35 &
V_40 ) != 0 )
V_27 = F_20 ( V_2 ,
( ( V_41 ) V_35 ) >> 16 ) ;
else
V_27 = 0 ;
if ( V_27 )
goto V_31;
}
V_27 = F_21 ( V_2 , V_25 ) ;
if ( V_27 )
goto V_31;
}
V_2 -> V_42 = V_25 ;
V_27 = 0 ;
V_31:
F_16 ( V_2 ) ;
return V_27 ;
}
void F_22 ( void )
{
T_1 V_43 ;
do {
F_23 ( & V_43 , sizeof( V_43 ) ) ;
} while ( V_43 == 0 );
F_24 ( & V_44 , 0 , V_43 ) ;
}
static inline int F_25 ( struct V_45 * V_45 , T_2 V_46 )
{
const struct V_47 * V_48 ;
if ( F_26 ( V_45 , & V_49 ) )
return 1 ;
V_48 = F_27 ( V_50 [ V_46 ] ) ;
if ( V_48 == NULL ) {
return 1 ;
}
return V_48 -> V_51 ;
}
static int F_28 ( struct V_45 * V_45 , struct V_24 * V_1 , int V_46 ,
int V_52 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_3 * V_4 ;
struct V_55 * V_56 ;
unsigned char V_57 ;
char V_58 ;
int V_59 = 0 ;
int V_27 ;
if ( F_29 ( ! V_44 ) )
if ( V_1 -> type != V_60 && V_1 -> type != V_61 )
F_22 () ;
V_1 -> V_29 = V_30 ;
V_62:
V_27 = - V_63 ;
F_30 () ;
F_31 (answer, &inetsw[sock->type], list) {
V_27 = 0 ;
if ( V_46 == V_54 -> V_46 ) {
if ( V_46 != V_64 )
break;
} else {
if ( V_64 == V_46 ) {
V_46 = V_54 -> V_46 ;
break;
}
if ( V_64 == V_54 -> V_46 )
break;
}
V_27 = - V_65 ;
}
if ( F_29 ( V_27 ) ) {
if ( V_59 < 2 ) {
F_32 () ;
if ( ++ V_59 == 1 )
F_33 ( L_3 ,
V_66 , V_46 , V_1 -> type ) ;
else
F_33 ( L_4 ,
V_66 , V_46 ) ;
goto V_62;
} else
goto V_67;
}
V_27 = - V_68 ;
if ( V_1 -> type == V_60 && ! V_52 && ! F_34 ( V_69 ) )
goto V_67;
V_27 = - V_70 ;
if ( ! F_25 ( V_45 , V_46 ) )
goto V_67;
V_1 -> V_71 = V_54 -> V_71 ;
V_56 = V_54 -> V_72 ;
V_58 = V_54 -> V_73 ;
V_57 = V_54 -> V_74 ;
F_32 () ;
F_7 ( V_56 -> V_75 == NULL ) ;
V_27 = - V_76 ;
V_2 = F_35 ( V_45 , V_66 , V_77 , V_56 ) ;
if ( V_2 == NULL )
goto V_31;
V_27 = 0 ;
V_2 -> V_78 = V_58 ;
if ( V_79 & V_57 )
V_2 -> V_80 = V_81 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_82 = ( V_83 & V_57 ) != 0 ;
V_4 -> V_84 = 0 ;
if ( V_60 == V_1 -> type ) {
V_4 -> V_19 = V_46 ;
if ( V_85 == V_46 )
V_4 -> V_86 = 1 ;
}
if ( V_87 . V_88 )
V_4 -> V_89 = V_90 ;
else
V_4 -> V_89 = V_91 ;
V_4 -> V_92 = 0 ;
F_36 ( V_1 , V_2 ) ;
V_2 -> V_93 = F_1 ;
V_2 -> V_94 = V_46 ;
V_2 -> V_95 = V_2 -> V_20 -> V_96 ;
V_4 -> V_97 = - 1 ;
V_4 -> V_98 = 1 ;
V_4 -> V_99 = 1 ;
V_4 -> V_100 = 1 ;
V_4 -> V_101 = 0 ;
V_4 -> V_102 = NULL ;
V_4 -> V_103 = 0 ;
F_37 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_2 -> V_20 -> V_104 ( V_2 ) ;
}
if ( V_2 -> V_20 -> V_105 ) {
V_27 = V_2 -> V_20 -> V_105 ( V_2 ) ;
if ( V_27 )
F_38 ( V_2 ) ;
}
V_31:
return V_27 ;
V_67:
F_32 () ;
goto V_31;
}
int F_39 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_106 ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
V_106 = 0 ;
if ( F_6 ( V_2 , V_107 ) &&
! ( V_108 -> V_74 & V_109 ) )
V_106 = V_2 -> V_110 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_111 ( V_2 , V_106 ) ;
}
return 0 ;
}
int F_42 ( struct V_24 * V_1 , struct V_112 * V_113 , int V_114 )
{
struct V_115 * V_116 = (struct V_115 * ) V_113 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_117 ;
int V_118 ;
int V_27 ;
if ( V_2 -> V_20 -> V_119 ) {
V_27 = V_2 -> V_20 -> V_119 ( V_2 , V_113 , V_114 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_114 < sizeof( struct V_115 ) )
goto V_31;
if ( V_116 -> V_120 != V_121 ) {
V_27 = - V_70 ;
if ( V_116 -> V_120 != V_122 ||
V_116 -> V_123 . V_124 != F_43 ( V_125 ) )
goto V_31;
}
V_118 = F_44 ( F_45 ( V_2 ) , V_116 -> V_123 . V_124 ) ;
V_27 = - V_126 ;
if ( ! V_127 &&
! ( V_4 -> V_128 || V_4 -> V_129 ) &&
V_116 -> V_123 . V_124 != F_43 ( V_125 ) &&
V_118 != V_130 &&
V_118 != V_131 &&
V_118 != V_132 )
goto V_31;
V_117 = F_46 ( V_116 -> V_133 ) ;
V_27 = - V_134 ;
if ( V_117 && V_117 < V_135 && ! F_34 ( V_136 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_137;
V_4 -> V_138 = V_4 -> V_139 = V_116 -> V_123 . V_124 ;
if ( V_118 == V_131 || V_118 == V_132 )
V_4 -> V_139 = 0 ;
if ( V_2 -> V_20 -> V_21 ( V_2 , V_117 ) ) {
V_4 -> V_139 = V_4 -> V_138 = 0 ;
V_27 = - V_140 ;
goto V_137;
}
if ( V_4 -> V_138 )
V_2 -> V_141 |= V_142 ;
if ( V_117 )
V_2 -> V_141 |= V_143 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_144 = 0 ;
V_4 -> V_145 = 0 ;
F_47 ( V_2 ) ;
V_27 = 0 ;
V_137:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_48 ( struct V_24 * V_1 , struct V_112 * V_113 ,
int V_114 , int V_74 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_114 < sizeof( V_113 -> V_146 ) )
return - V_28 ;
if ( V_113 -> V_146 == V_122 )
return V_2 -> V_20 -> V_147 ( V_2 , V_74 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_148 ( V_2 , V_113 , V_114 ) ;
}
static long F_49 ( struct V_1 * V_2 , long V_149 , int V_150 )
{
F_50 ( V_151 ) ;
F_51 ( F_52 ( V_2 ) , & V_151 , V_152 ) ;
V_2 -> V_153 += V_150 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_154 | V_155 ) ) {
F_16 ( V_2 ) ;
V_149 = F_53 ( V_149 ) ;
F_15 ( V_2 ) ;
if ( F_54 ( V_108 ) || ! V_149 )
break;
F_51 ( F_52 ( V_2 ) , & V_151 , V_152 ) ;
}
F_55 ( F_52 ( V_2 ) , & V_151 ) ;
V_2 -> V_153 -= V_150 ;
return V_149 ;
}
int F_56 ( struct V_24 * V_1 , struct V_112 * V_113 ,
int V_114 , int V_74 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_149 ;
if ( V_114 < sizeof( V_113 -> V_146 ) )
return - V_28 ;
if ( V_113 -> V_146 == V_122 ) {
V_27 = V_2 -> V_20 -> V_147 ( V_2 , V_74 ) ;
V_1 -> V_29 = V_27 ? V_156 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_157 :
V_27 = - V_158 ;
goto V_31;
case V_159 :
V_27 = - V_160 ;
break;
case V_30 :
V_27 = - V_158 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_148 ( V_2 , V_113 , V_114 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_159 ;
V_27 = - V_161 ;
break;
}
V_149 = F_57 ( V_2 , V_74 & V_162 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_154 | V_155 ) ) {
int V_150 = ( V_2 -> V_94 == V_163 ) &&
F_58 ( V_2 ) -> V_164 &&
F_58 ( V_2 ) -> V_164 -> V_165 ? 1 : 0 ;
if ( ! V_149 || ! F_49 ( V_2 , V_149 , V_150 ) )
goto V_31;
V_27 = F_59 ( V_149 ) ;
if ( F_54 ( V_108 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_166;
V_1 -> V_29 = V_157 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_166:
V_27 = V_166 ( V_2 ) ? : - V_167 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_147 ( V_2 , V_74 ) )
V_1 -> V_29 = V_156 ;
goto V_31;
}
int F_60 ( struct V_24 * V_1 , struct V_112 * V_113 ,
int V_114 , int V_74 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_56 ( V_1 , V_113 , V_114 , V_74 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_61 ( struct V_24 * V_1 , struct V_24 * V_168 , int V_74 )
{
struct V_1 * V_169 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_170 = V_169 -> V_20 -> V_171 ( V_169 , V_74 , & V_27 ) ;
if ( ! V_170 )
goto V_172;
F_15 ( V_170 ) ;
F_62 ( V_170 ) ;
F_7 ( ! ( ( 1 << V_170 -> V_9 ) &
( V_173 | V_155 |
V_174 | V_32 ) ) ) ;
F_63 ( V_170 , V_168 ) ;
V_168 -> V_29 = V_157 ;
V_27 = 0 ;
F_16 ( V_170 ) ;
V_172:
return V_27 ;
}
int F_64 ( struct V_24 * V_1 , struct V_112 * V_113 ,
int * V_175 , int V_176 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_65 ( struct V_115 * , sin , V_113 ) ;
sin -> V_120 = V_121 ;
if ( V_176 ) {
if ( ! V_4 -> V_145 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_154 ) ) &&
V_176 == 1 ) )
return - V_177 ;
sin -> V_133 = V_4 -> V_145 ;
sin -> V_123 . V_124 = V_4 -> V_144 ;
} else {
T_3 V_116 = V_4 -> V_138 ;
if ( ! V_116 )
V_116 = V_4 -> V_139 ;
sin -> V_133 = V_4 -> V_23 ;
sin -> V_123 . V_124 = V_116 ;
}
memset ( sin -> V_178 , 0 , sizeof( sin -> V_178 ) ) ;
* V_175 = sizeof( * sin ) ;
return 0 ;
}
int F_66 ( struct V_179 * V_180 , struct V_24 * V_1 , struct V_181 * V_182 ,
T_4 V_183 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_62 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_184 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_185 ( V_180 , V_2 , V_182 , V_183 ) ;
}
T_5 F_67 ( struct V_24 * V_1 , struct V_186 * V_186 , int V_187 ,
T_4 V_183 , int V_74 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_62 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_184 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_188 )
return V_2 -> V_20 -> V_188 ( V_2 , V_186 , V_187 , V_183 , V_74 ) ;
return F_68 ( V_1 , V_186 , V_187 , V_183 , V_74 ) ;
}
int F_69 ( struct V_179 * V_180 , struct V_24 * V_1 , struct V_181 * V_182 ,
T_4 V_183 , int V_74 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_114 = 0 ;
int V_27 ;
F_62 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_189 ( V_180 , V_2 , V_182 , V_183 , V_74 & V_190 ,
V_74 & ~ V_190 , & V_114 ) ;
if ( V_27 >= 0 )
V_182 -> V_191 = V_114 ;
return V_27 ;
}
int F_70 ( struct V_24 * V_1 , int V_192 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_192 ++ ;
if ( ( V_192 & ~ V_193 ) || ! V_192 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_159 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_154 | V_155 | V_32 ) )
V_1 -> V_29 = V_156 ;
else
V_1 -> V_29 = V_157 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_177 ;
default:
V_2 -> V_194 |= V_192 ;
if ( V_2 -> V_20 -> V_195 )
V_2 -> V_20 -> V_195 ( V_2 , V_192 ) ;
break;
case V_34 :
if ( ! ( V_192 & V_196 ) )
break;
case V_197 :
V_27 = V_2 -> V_20 -> V_147 ( V_2 , V_162 ) ;
V_1 -> V_29 = V_27 ? V_156 : V_30 ;
break;
}
V_2 -> V_198 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_71 ( struct V_24 * V_1 , unsigned int V_199 , unsigned long V_200 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_45 * V_45 = F_45 ( V_2 ) ;
switch ( V_199 ) {
case V_201 :
V_27 = F_72 ( V_2 , (struct V_202 V_203 * ) V_200 ) ;
break;
case V_204 :
V_27 = F_73 ( V_2 , (struct V_205 V_203 * ) V_200 ) ;
break;
case V_206 :
case V_207 :
case V_208 :
V_27 = F_74 ( V_45 , V_199 , ( void V_203 * ) V_200 ) ;
break;
case V_209 :
case V_210 :
case V_211 :
V_27 = F_75 ( V_45 , V_199 , ( void V_203 * ) V_200 ) ;
break;
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
V_27 = F_76 ( V_45 , V_199 , ( void V_203 * ) V_200 ) ;
break;
default:
if ( V_2 -> V_20 -> V_223 )
V_27 = V_2 -> V_20 -> V_223 ( V_2 , V_199 , V_200 ) ;
else
V_27 = - V_224 ;
break;
}
return V_27 ;
}
static int F_77 ( struct V_24 * V_1 , unsigned int V_199 , unsigned long V_200 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_224 ;
if ( V_2 -> V_20 -> V_225 )
V_27 = V_2 -> V_20 -> V_225 ( V_2 , V_199 , V_200 ) ;
return V_27 ;
}
void F_78 ( struct V_53 * V_226 )
{
struct V_227 * V_228 ;
struct V_53 * V_54 ;
int V_46 = V_226 -> V_46 ;
struct V_227 * V_229 ;
F_79 ( & V_230 ) ;
if ( V_226 -> type >= V_231 )
goto V_232;
V_54 = NULL ;
V_229 = & V_233 [ V_226 -> type ] ;
F_80 (lh, &inetsw[p->type]) {
V_54 = F_81 ( V_228 , struct V_53 , V_234 ) ;
if ( V_235 & V_54 -> V_74 ) {
if ( V_46 == V_54 -> V_46 )
break;
V_229 = V_228 ;
}
V_54 = NULL ;
}
if ( V_54 )
goto V_236;
F_82 ( & V_226 -> V_234 , V_229 ) ;
V_31:
F_83 ( & V_230 ) ;
return;
V_236:
F_5 ( L_5 , V_46 ) ;
goto V_31;
V_232:
F_5 ( L_6 ,
V_226 -> type ) ;
goto V_31;
}
void F_84 ( struct V_53 * V_226 )
{
if ( V_235 & V_226 -> V_74 ) {
F_5 ( L_7 ,
V_226 -> V_46 ) ;
} else {
F_79 ( & V_230 ) ;
F_85 ( & V_226 -> V_234 ) ;
F_83 ( & V_230 ) ;
F_86 () ;
}
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_237 = V_4 -> V_139 ;
T_3 V_238 = V_4 -> V_144 ;
struct V_239 * V_240 ;
struct V_241 * V_242 ;
T_3 V_243 ;
struct V_244 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_88 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_245 . V_246 )
V_238 = V_16 -> V_245 . V_247 ;
V_240 = & V_4 -> V_248 . V_249 . V_250 . V_251 ;
V_242 = F_89 ( V_240 , V_238 , 0 , F_90 ( V_2 ) ,
V_2 -> V_252 , V_2 -> V_94 ,
V_4 -> V_23 , V_4 -> V_145 , V_2 , false ) ;
if ( F_91 ( V_242 ) )
return F_92 ( V_242 ) ;
F_93 ( V_2 , & V_242 -> V_253 ) ;
V_243 = V_240 -> V_254 ;
if ( V_243 == V_237 )
return 0 ;
if ( V_255 > 1 ) {
F_94 ( L_8 ,
V_256 , & V_237 , & V_243 ) ;
}
V_4 -> V_139 = V_4 -> V_138 = V_243 ;
F_95 ( V_2 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_241 * V_242 = (struct V_241 * ) F_97 ( V_2 , 0 ) ;
T_3 V_238 ;
struct V_244 * V_16 ;
struct V_239 * V_240 ;
int V_27 ;
if ( V_242 )
return 0 ;
F_30 () ;
V_16 = F_27 ( V_4 -> V_16 ) ;
V_238 = V_4 -> V_144 ;
if ( V_16 && V_16 -> V_245 . V_246 )
V_238 = V_16 -> V_245 . V_247 ;
F_32 () ;
V_240 = & V_4 -> V_248 . V_249 . V_250 . V_251 ;
V_242 = F_98 ( F_45 ( V_2 ) , V_240 , V_2 , V_238 , V_4 -> V_139 ,
V_4 -> V_145 , V_4 -> V_23 ,
V_2 -> V_94 , F_90 ( V_2 ) ,
V_2 -> V_252 ) ;
if ( ! F_91 ( V_242 ) ) {
V_27 = 0 ;
F_93 ( V_2 , & V_242 -> V_253 ) ;
} else {
V_27 = F_92 ( V_242 ) ;
V_2 -> V_257 = 0 ;
if ( ! V_255 ||
V_2 -> V_9 != V_197 ||
( V_2 -> V_141 & V_142 ) ||
( V_27 = F_87 ( V_2 ) ) != 0 )
V_2 -> V_258 = - V_27 ;
}
return V_27 ;
}
static int F_99 ( struct V_259 * V_260 )
{
const struct V_47 * V_71 ;
const struct V_261 * V_262 ;
int V_55 ;
int V_263 ;
int V_27 = - V_28 ;
if ( F_29 ( ! F_100 ( V_260 , sizeof( * V_262 ) ) ) )
goto V_31;
V_262 = F_101 ( V_260 ) ;
V_263 = V_262 -> V_263 * 4 ;
if ( V_263 < sizeof( * V_262 ) )
goto V_31;
if ( F_29 ( ! F_100 ( V_260 , V_263 ) ) )
goto V_31;
F_102 ( V_260 , V_263 ) ;
F_103 ( V_260 ) ;
V_262 = F_101 ( V_260 ) ;
V_55 = V_262 -> V_46 ;
V_27 = - V_65 ;
F_30 () ;
V_71 = F_27 ( V_50 [ V_55 ] ) ;
if ( F_104 ( V_71 && V_71 -> V_264 ) )
V_27 = V_71 -> V_264 ( V_260 ) ;
F_32 () ;
V_31:
return V_27 ;
}
static struct V_259 * F_105 ( struct V_259 * V_260 ,
T_6 V_265 )
{
struct V_259 * V_266 = F_106 ( - V_28 ) ;
const struct V_47 * V_71 ;
struct V_261 * V_262 ;
int V_55 ;
int V_263 ;
int V_267 ;
unsigned int V_187 = 0 ;
if ( ! ( V_265 & V_268 ) )
V_265 &= ~ V_269 ;
if ( F_29 ( F_107 ( V_260 ) -> V_270 &
~ ( V_271 |
V_272 |
V_273 |
V_274 |
0 ) ) )
goto V_31;
if ( F_29 ( ! F_100 ( V_260 , sizeof( * V_262 ) ) ) )
goto V_31;
V_262 = F_101 ( V_260 ) ;
V_263 = V_262 -> V_263 * 4 ;
if ( V_263 < sizeof( * V_262 ) )
goto V_31;
if ( F_29 ( ! F_100 ( V_260 , V_263 ) ) )
goto V_31;
F_102 ( V_260 , V_263 ) ;
F_103 ( V_260 ) ;
V_262 = F_101 ( V_260 ) ;
V_267 = F_46 ( V_262 -> V_267 ) ;
V_55 = V_262 -> V_46 ;
V_266 = F_106 ( - V_65 ) ;
F_30 () ;
V_71 = F_27 ( V_50 [ V_55 ] ) ;
if ( F_104 ( V_71 && V_71 -> V_275 ) )
V_266 = V_71 -> V_275 ( V_260 , V_265 ) ;
F_32 () ;
if ( ! V_266 || F_91 ( V_266 ) )
goto V_31;
V_260 = V_266 ;
do {
V_262 = F_101 ( V_260 ) ;
if ( V_55 == V_276 ) {
V_262 -> V_267 = F_17 ( V_267 ) ;
V_262 -> V_277 = F_17 ( V_187 >> 3 ) ;
if ( V_260 -> V_278 != NULL )
V_262 -> V_277 |= F_17 ( V_279 ) ;
V_187 += ( V_260 -> V_280 - V_260 -> V_281 - V_262 -> V_263 * 4 ) ;
} else
V_262 -> V_267 = F_17 ( V_267 ++ ) ;
V_262 -> V_282 = F_17 ( V_260 -> V_280 - V_260 -> V_281 ) ;
V_262 -> V_283 = 0 ;
V_262 -> V_283 = F_108 ( F_109 ( V_260 ) , V_262 -> V_263 ) ;
} while ( ( V_260 = V_260 -> V_278 ) );
V_31:
return V_266 ;
}
static struct V_259 * * F_110 ( struct V_259 * * V_284 ,
struct V_259 * V_260 )
{
const struct V_47 * V_71 ;
struct V_259 * * V_285 = NULL ;
struct V_259 * V_226 ;
const struct V_261 * V_262 ;
unsigned int V_286 ;
unsigned int V_287 ;
unsigned int V_267 ;
int V_288 = 1 ;
int V_55 ;
V_287 = F_111 ( V_260 ) ;
V_286 = V_287 + sizeof( * V_262 ) ;
V_262 = F_112 ( V_260 , V_287 ) ;
if ( F_113 ( V_260 , V_286 ) ) {
V_262 = F_114 ( V_260 , V_286 , V_287 ) ;
if ( F_29 ( ! V_262 ) )
goto V_31;
}
V_55 = V_262 -> V_46 ;
F_30 () ;
V_71 = F_27 ( V_50 [ V_55 ] ) ;
if ( ! V_71 || ! V_71 -> V_289 )
goto V_290;
if ( * ( V_291 * ) V_262 != 0x45 )
goto V_290;
if ( F_29 ( F_108 ( ( V_291 * ) V_262 , 5 ) ) )
goto V_290;
V_267 = F_115 ( * ( T_3 * ) & V_262 -> V_267 ) ;
V_288 = ( V_292 ) ( ( F_115 ( * ( T_3 * ) V_262 ) ^ F_116 ( V_260 ) ) | ( V_267 ^ V_293 ) ) ;
V_267 >>= 16 ;
for ( V_226 = * V_284 ; V_226 ; V_226 = V_226 -> V_278 ) {
struct V_261 * V_294 ;
if ( ! F_117 ( V_226 ) -> V_295 )
continue;
V_294 = F_101 ( V_226 ) ;
if ( ( V_262 -> V_46 ^ V_294 -> V_46 ) |
( ( V_296 T_1 ) V_262 -> V_254 ^ ( V_296 T_1 ) V_294 -> V_254 ) |
( ( V_296 T_1 ) V_262 -> V_238 ^ ( V_296 T_1 ) V_294 -> V_238 ) ) {
F_117 ( V_226 ) -> V_295 = 0 ;
continue;
}
F_117 ( V_226 ) -> V_288 |=
( V_262 -> V_297 ^ V_294 -> V_297 ) |
( V_262 -> V_298 ^ V_294 -> V_298 ) |
( ( V_292 ) ( F_46 ( V_294 -> V_267 ) + F_117 ( V_226 ) -> V_299 ) ^ V_267 ) ;
F_117 ( V_226 ) -> V_288 |= V_288 ;
}
F_117 ( V_260 ) -> V_288 |= V_288 ;
F_118 ( V_260 , sizeof( * V_262 ) ) ;
F_119 ( V_260 , F_111 ( V_260 ) ) ;
V_285 = V_71 -> V_289 ( V_284 , V_260 ) ;
V_290:
F_32 () ;
V_31:
F_117 ( V_260 ) -> V_288 |= V_288 ;
return V_285 ;
}
static int F_120 ( struct V_259 * V_260 )
{
T_7 V_300 = F_17 ( V_260 -> V_280 - F_121 ( V_260 ) ) ;
struct V_261 * V_262 = F_101 ( V_260 ) ;
const struct V_47 * V_71 ;
int V_55 = V_262 -> V_46 ;
int V_27 = - V_301 ;
F_122 ( & V_262 -> V_283 , V_262 -> V_282 , V_300 ) ;
V_262 -> V_282 = V_300 ;
F_30 () ;
V_71 = F_27 ( V_50 [ V_55 ] ) ;
if ( F_7 ( ! V_71 || ! V_71 -> V_302 ) )
goto V_290;
V_27 = V_71 -> V_302 ( V_260 ) ;
V_290:
F_32 () ;
return V_27 ;
}
int F_123 ( struct V_1 * * V_2 , unsigned short V_303 ,
unsigned short type , unsigned char V_46 ,
struct V_45 * V_45 )
{
struct V_24 * V_1 ;
int V_304 = F_124 ( V_303 , type , V_46 , & V_1 ) ;
if ( V_304 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_305 = V_306 ;
( * V_2 ) -> V_20 -> V_307 ( * V_2 ) ;
F_125 ( * V_2 , V_45 ) ;
}
return V_304 ;
}
unsigned long F_126 ( void T_8 * V_308 [] , int V_309 )
{
unsigned long V_310 = 0 ;
int V_311 , V_312 ;
F_127 (i) {
for ( V_312 = 0 ; V_312 < V_313 ; V_312 ++ )
V_310 += * ( ( ( unsigned long * ) F_128 ( V_308 [ V_312 ] , V_311 ) ) + V_309 ) ;
}
return V_310 ;
}
T_9 F_129 ( void T_8 * V_308 [] , int V_309 , T_4 V_314 )
{
T_9 V_310 = 0 ;
int V_315 ;
F_127 (cpu) {
void * V_316 ;
struct V_317 * V_318 ;
T_9 V_319 ;
unsigned int V_320 ;
V_316 = F_128 ( V_308 [ 0 ] , V_315 ) ;
V_318 = (struct V_317 * ) ( V_316 + V_314 ) ;
do {
V_320 = F_130 ( V_318 ) ;
V_319 = * ( ( ( T_9 * ) V_316 ) + V_309 ) ;
} while ( F_131 ( V_318 , V_320 ) );
V_310 += V_319 ;
}
return V_310 ;
}
int F_132 ( void T_8 * V_321 [ 2 ] , T_4 V_322 , T_4 V_323 )
{
F_133 ( V_321 == NULL ) ;
V_321 [ 0 ] = F_134 ( V_322 , V_323 ) ;
if ( ! V_321 [ 0 ] )
return - V_324 ;
#if V_313 == 2
V_321 [ 1 ] = F_134 ( V_322 , V_323 ) ;
if ( ! V_321 [ 1 ] ) {
F_135 ( V_321 [ 0 ] ) ;
V_321 [ 0 ] = NULL ;
return - V_324 ;
}
#endif
return 0 ;
}
void F_136 ( void T_8 * V_321 [ V_313 ] )
{
int V_311 ;
F_133 ( V_321 == NULL ) ;
for ( V_311 = 0 ; V_311 < V_313 ; V_311 ++ ) {
F_135 ( V_321 [ V_311 ] ) ;
V_321 [ V_311 ] = NULL ;
}
}
static T_10 int F_137 ( struct V_45 * V_45 )
{
if ( F_132 ( ( void T_8 * * ) V_45 -> V_308 . V_325 ,
sizeof( struct V_326 ) ,
F_138 ( struct V_326 ) ) < 0 )
goto V_327;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_308 . V_328 ,
sizeof( struct V_329 ) ,
F_138 ( struct V_329 ) ) < 0 )
goto V_330;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_308 . V_331 ,
sizeof( struct V_332 ) ,
F_138 ( struct V_332 ) ) < 0 )
goto V_333;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_308 . V_334 ,
sizeof( struct V_335 ) ,
F_138 ( struct V_335 ) ) < 0 )
goto V_336;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_308 . V_337 ,
sizeof( struct V_335 ) ,
F_138 ( struct V_335 ) ) < 0 )
goto V_338;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_308 . V_339 ,
sizeof( struct V_340 ) ,
F_138 ( struct V_340 ) ) < 0 )
goto V_341;
V_45 -> V_308 . V_342 = F_139 ( sizeof( struct V_343 ) ,
V_77 ) ;
if ( ! V_45 -> V_308 . V_342 )
goto V_344;
F_140 ( V_45 ) ;
return 0 ;
V_344:
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_339 ) ;
V_341:
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_337 ) ;
V_338:
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_334 ) ;
V_336:
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_331 ) ;
V_333:
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_328 ) ;
V_330:
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_325 ) ;
V_327:
return - V_324 ;
}
static T_11 void F_141 ( struct V_45 * V_45 )
{
F_9 ( V_45 -> V_308 . V_342 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_339 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_337 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_334 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_331 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_328 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_308 . V_325 ) ;
}
static int T_12 F_142 ( void )
{
return F_143 ( & V_345 ) ;
}
static int T_12 F_144 ( void )
{
struct V_259 * V_346 ;
struct V_53 * V_347 ;
struct V_227 * V_348 ;
int V_304 = - V_28 ;
F_145 ( sizeof( struct V_349 ) > sizeof( V_346 -> V_350 ) ) ;
V_351 = F_139 ( 65536 / 8 , V_77 ) ;
if ( ! V_351 )
goto V_31;
V_304 = F_146 ( & V_352 , 1 ) ;
if ( V_304 )
goto V_353;
V_304 = F_146 ( & V_354 , 1 ) ;
if ( V_304 )
goto V_355;
V_304 = F_146 ( & V_356 , 1 ) ;
if ( V_304 )
goto V_357;
V_304 = F_146 ( & V_358 , 1 ) ;
if ( V_304 )
goto V_359;
( void ) F_147 ( & V_360 ) ;
#ifdef F_148
F_149 () ;
#endif
V_352 . V_361 = V_49 . V_362 . V_363 ;
if ( F_150 ( & V_364 , V_365 ) < 0 )
F_151 ( L_9 , V_256 ) ;
if ( F_150 ( & V_366 , V_276 ) < 0 )
F_151 ( L_10 , V_256 ) ;
if ( F_150 ( & V_367 , V_163 ) < 0 )
F_151 ( L_11 , V_256 ) ;
#ifdef F_152
if ( F_150 ( & V_368 , V_369 ) < 0 )
F_151 ( L_12 , V_256 ) ;
#endif
for ( V_348 = & V_233 [ 0 ] ; V_348 < & V_233 [ V_231 ] ; ++ V_348 )
F_153 ( V_348 ) ;
for ( V_347 = V_370 ; V_347 < & V_370 [ V_371 ] ; ++ V_347 )
F_78 ( V_347 ) ;
F_154 () ;
F_155 () ;
F_156 () ;
F_157 () ;
F_158 () ;
F_159 () ;
F_160 () ;
if ( F_161 () < 0 )
F_162 ( L_13 ) ;
#if F_163 ( V_372 )
if ( F_164 () )
F_151 ( L_14 , V_256 ) ;
#endif
if ( F_142 () )
F_151 ( L_15 , V_256 ) ;
F_165 () ;
F_166 () ;
F_167 ( & V_373 ) ;
V_304 = 0 ;
V_31:
return V_304 ;
V_359:
F_168 ( & V_356 ) ;
V_357:
F_168 ( & V_354 ) ;
V_355:
F_168 ( & V_352 ) ;
V_353:
F_9 ( V_351 ) ;
goto V_31;
}
static int T_12 F_165 ( void )
{
int V_304 = 0 ;
if ( F_169 () )
goto V_374;
if ( F_170 () )
goto V_375;
if ( F_171 () )
goto V_376;
if ( F_172 () )
goto V_377;
if ( F_173 () )
goto V_378;
V_31:
return V_304 ;
V_378:
F_174 () ;
V_377:
F_175 () ;
V_376:
F_176 () ;
V_375:
F_177 () ;
V_374:
V_304 = - V_324 ;
goto V_31;
}
static int T_12 F_165 ( void )
{
return 0 ;
}
