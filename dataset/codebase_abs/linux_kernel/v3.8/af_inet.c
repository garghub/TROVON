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
if ( V_1 -> type == V_60 && ! V_52 &&
! F_34 ( V_45 -> V_69 , V_70 ) )
goto V_67;
V_27 = - V_71 ;
if ( ! F_25 ( V_45 , V_46 ) )
goto V_67;
V_1 -> V_72 = V_54 -> V_72 ;
V_56 = V_54 -> V_73 ;
V_58 = V_54 -> V_74 ;
V_57 = V_54 -> V_75 ;
F_32 () ;
F_7 ( V_56 -> V_76 == NULL ) ;
V_27 = - V_77 ;
V_2 = F_35 ( V_45 , V_66 , V_78 , V_56 ) ;
if ( V_2 == NULL )
goto V_31;
V_27 = 0 ;
V_2 -> V_79 = V_58 ;
if ( V_80 & V_57 )
V_2 -> V_81 = V_82 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_83 = ( V_84 & V_57 ) != 0 ;
V_4 -> V_85 = 0 ;
if ( V_60 == V_1 -> type ) {
V_4 -> V_19 = V_46 ;
if ( V_86 == V_46 )
V_4 -> V_87 = 1 ;
}
if ( V_88 . V_89 )
V_4 -> V_90 = V_91 ;
else
V_4 -> V_90 = V_92 ;
V_4 -> V_93 = 0 ;
F_36 ( V_1 , V_2 ) ;
V_2 -> V_94 = F_1 ;
V_2 -> V_95 = V_46 ;
V_2 -> V_96 = V_2 -> V_20 -> V_97 ;
V_4 -> V_98 = - 1 ;
V_4 -> V_99 = 1 ;
V_4 -> V_100 = 1 ;
V_4 -> V_101 = 1 ;
V_4 -> V_102 = 0 ;
V_4 -> V_103 = NULL ;
V_4 -> V_104 = 0 ;
F_37 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_2 -> V_20 -> V_105 ( V_2 ) ;
}
if ( V_2 -> V_20 -> V_106 ) {
V_27 = V_2 -> V_20 -> V_106 ( V_2 ) ;
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
long V_107 ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
V_107 = 0 ;
if ( F_6 ( V_2 , V_108 ) &&
! ( V_109 -> V_75 & V_110 ) )
V_107 = V_2 -> V_111 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_112 ( V_2 , V_107 ) ;
}
return 0 ;
}
int F_42 ( struct V_24 * V_1 , struct V_113 * V_114 , int V_115 )
{
struct V_116 * V_117 = (struct V_116 * ) V_114 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_45 * V_45 = F_43 ( V_2 ) ;
unsigned short V_118 ;
int V_119 ;
int V_27 ;
if ( V_2 -> V_20 -> V_120 ) {
V_27 = V_2 -> V_20 -> V_120 ( V_2 , V_114 , V_115 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_115 < sizeof( struct V_116 ) )
goto V_31;
if ( V_117 -> V_121 != V_122 ) {
V_27 = - V_71 ;
if ( V_117 -> V_121 != V_123 ||
V_117 -> V_124 . V_125 != F_44 ( V_126 ) )
goto V_31;
}
V_119 = F_45 ( V_45 , V_117 -> V_124 . V_125 ) ;
V_27 = - V_127 ;
if ( ! V_128 &&
! ( V_4 -> V_129 || V_4 -> V_130 ) &&
V_117 -> V_124 . V_125 != F_44 ( V_126 ) &&
V_119 != V_131 &&
V_119 != V_132 &&
V_119 != V_133 )
goto V_31;
V_118 = F_46 ( V_117 -> V_134 ) ;
V_27 = - V_135 ;
if ( V_118 && V_118 < V_136 &&
! F_34 ( V_45 -> V_69 , V_137 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_138;
V_4 -> V_139 = V_4 -> V_140 = V_117 -> V_124 . V_125 ;
if ( V_119 == V_132 || V_119 == V_133 )
V_4 -> V_140 = 0 ;
if ( V_2 -> V_20 -> V_21 ( V_2 , V_118 ) ) {
V_4 -> V_140 = V_4 -> V_139 = 0 ;
V_27 = - V_141 ;
goto V_138;
}
if ( V_4 -> V_139 )
V_2 -> V_142 |= V_143 ;
if ( V_118 )
V_2 -> V_142 |= V_144 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_145 = 0 ;
V_4 -> V_146 = 0 ;
F_47 ( V_2 ) ;
V_27 = 0 ;
V_138:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_48 ( struct V_24 * V_1 , struct V_113 * V_114 ,
int V_115 , int V_75 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_115 < sizeof( V_114 -> V_147 ) )
return - V_28 ;
if ( V_114 -> V_147 == V_123 )
return V_2 -> V_20 -> V_148 ( V_2 , V_75 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_149 ( V_2 , V_114 , V_115 ) ;
}
static long F_49 ( struct V_1 * V_2 , long V_150 , int V_151 )
{
F_50 ( V_152 ) ;
F_51 ( F_52 ( V_2 ) , & V_152 , V_153 ) ;
V_2 -> V_154 += V_151 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_155 | V_156 ) ) {
F_16 ( V_2 ) ;
V_150 = F_53 ( V_150 ) ;
F_15 ( V_2 ) ;
if ( F_54 ( V_109 ) || ! V_150 )
break;
F_51 ( F_52 ( V_2 ) , & V_152 , V_153 ) ;
}
F_55 ( F_52 ( V_2 ) , & V_152 ) ;
V_2 -> V_154 -= V_151 ;
return V_150 ;
}
int F_56 ( struct V_24 * V_1 , struct V_113 * V_114 ,
int V_115 , int V_75 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_150 ;
if ( V_115 < sizeof( V_114 -> V_147 ) )
return - V_28 ;
if ( V_114 -> V_147 == V_123 ) {
V_27 = V_2 -> V_20 -> V_148 ( V_2 , V_75 ) ;
V_1 -> V_29 = V_27 ? V_157 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_158 :
V_27 = - V_159 ;
goto V_31;
case V_160 :
V_27 = - V_161 ;
break;
case V_30 :
V_27 = - V_159 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_149 ( V_2 , V_114 , V_115 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_160 ;
V_27 = - V_162 ;
break;
}
V_150 = F_57 ( V_2 , V_75 & V_163 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_155 | V_156 ) ) {
int V_151 = ( V_2 -> V_95 == V_164 ) &&
F_58 ( V_2 ) -> V_165 &&
F_58 ( V_2 ) -> V_165 -> V_166 ? 1 : 0 ;
if ( ! V_150 || ! F_49 ( V_2 , V_150 , V_151 ) )
goto V_31;
V_27 = F_59 ( V_150 ) ;
if ( F_54 ( V_109 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_167;
V_1 -> V_29 = V_158 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_167:
V_27 = V_167 ( V_2 ) ? : - V_168 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_148 ( V_2 , V_75 ) )
V_1 -> V_29 = V_157 ;
goto V_31;
}
int F_60 ( struct V_24 * V_1 , struct V_113 * V_114 ,
int V_115 , int V_75 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_56 ( V_1 , V_114 , V_115 , V_75 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_61 ( struct V_24 * V_1 , struct V_24 * V_169 , int V_75 )
{
struct V_1 * V_170 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_171 = V_170 -> V_20 -> V_172 ( V_170 , V_75 , & V_27 ) ;
if ( ! V_171 )
goto V_173;
F_15 ( V_171 ) ;
F_62 ( V_171 ) ;
F_7 ( ! ( ( 1 << V_171 -> V_9 ) &
( V_174 | V_156 |
V_175 | V_32 ) ) ) ;
F_63 ( V_171 , V_169 ) ;
V_169 -> V_29 = V_158 ;
V_27 = 0 ;
F_16 ( V_171 ) ;
V_173:
return V_27 ;
}
int F_64 ( struct V_24 * V_1 , struct V_113 * V_114 ,
int * V_176 , int V_177 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_65 ( struct V_116 * , sin , V_114 ) ;
sin -> V_121 = V_122 ;
if ( V_177 ) {
if ( ! V_4 -> V_146 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_155 ) ) &&
V_177 == 1 ) )
return - V_178 ;
sin -> V_134 = V_4 -> V_146 ;
sin -> V_124 . V_125 = V_4 -> V_145 ;
} else {
T_3 V_117 = V_4 -> V_139 ;
if ( ! V_117 )
V_117 = V_4 -> V_140 ;
sin -> V_134 = V_4 -> V_23 ;
sin -> V_124 . V_125 = V_117 ;
}
memset ( sin -> V_179 , 0 , sizeof( sin -> V_179 ) ) ;
* V_176 = sizeof( * sin ) ;
return 0 ;
}
int F_66 ( struct V_180 * V_181 , struct V_24 * V_1 , struct V_182 * V_183 ,
T_4 V_184 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_62 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_185 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_186 ( V_181 , V_2 , V_183 , V_184 ) ;
}
T_5 F_67 ( struct V_24 * V_1 , struct V_187 * V_187 , int V_188 ,
T_4 V_184 , int V_75 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_62 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_185 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_189 )
return V_2 -> V_20 -> V_189 ( V_2 , V_187 , V_188 , V_184 , V_75 ) ;
return F_68 ( V_1 , V_187 , V_188 , V_184 , V_75 ) ;
}
int F_69 ( struct V_180 * V_181 , struct V_24 * V_1 , struct V_182 * V_183 ,
T_4 V_184 , int V_75 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_115 = 0 ;
int V_27 ;
F_62 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_190 ( V_181 , V_2 , V_183 , V_184 , V_75 & V_191 ,
V_75 & ~ V_191 , & V_115 ) ;
if ( V_27 >= 0 )
V_183 -> V_192 = V_115 ;
return V_27 ;
}
int F_70 ( struct V_24 * V_1 , int V_193 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_193 ++ ;
if ( ( V_193 & ~ V_194 ) || ! V_193 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_160 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_155 | V_156 | V_32 ) )
V_1 -> V_29 = V_157 ;
else
V_1 -> V_29 = V_158 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_178 ;
default:
V_2 -> V_195 |= V_193 ;
if ( V_2 -> V_20 -> V_196 )
V_2 -> V_20 -> V_196 ( V_2 , V_193 ) ;
break;
case V_34 :
if ( ! ( V_193 & V_197 ) )
break;
case V_198 :
V_27 = V_2 -> V_20 -> V_148 ( V_2 , V_163 ) ;
V_1 -> V_29 = V_27 ? V_157 : V_30 ;
break;
}
V_2 -> V_199 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_71 ( struct V_24 * V_1 , unsigned int V_200 , unsigned long V_201 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_45 * V_45 = F_43 ( V_2 ) ;
switch ( V_200 ) {
case V_202 :
V_27 = F_72 ( V_2 , (struct V_203 V_204 * ) V_201 ) ;
break;
case V_205 :
V_27 = F_73 ( V_2 , (struct V_206 V_204 * ) V_201 ) ;
break;
case V_207 :
case V_208 :
case V_209 :
V_27 = F_74 ( V_45 , V_200 , ( void V_204 * ) V_201 ) ;
break;
case V_210 :
case V_211 :
case V_212 :
V_27 = F_75 ( V_45 , V_200 , ( void V_204 * ) V_201 ) ;
break;
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
case V_223 :
V_27 = F_76 ( V_45 , V_200 , ( void V_204 * ) V_201 ) ;
break;
default:
if ( V_2 -> V_20 -> V_224 )
V_27 = V_2 -> V_20 -> V_224 ( V_2 , V_200 , V_201 ) ;
else
V_27 = - V_225 ;
break;
}
return V_27 ;
}
static int F_77 ( struct V_24 * V_1 , unsigned int V_200 , unsigned long V_201 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_225 ;
if ( V_2 -> V_20 -> V_226 )
V_27 = V_2 -> V_20 -> V_226 ( V_2 , V_200 , V_201 ) ;
return V_27 ;
}
void F_78 ( struct V_53 * V_227 )
{
struct V_228 * V_229 ;
struct V_53 * V_54 ;
int V_46 = V_227 -> V_46 ;
struct V_228 * V_230 ;
F_79 ( & V_231 ) ;
if ( V_227 -> type >= V_232 )
goto V_233;
V_54 = NULL ;
V_230 = & V_234 [ V_227 -> type ] ;
F_80 (lh, &inetsw[p->type]) {
V_54 = F_81 ( V_229 , struct V_53 , V_235 ) ;
if ( V_236 & V_54 -> V_75 ) {
if ( V_46 == V_54 -> V_46 )
break;
V_230 = V_229 ;
}
V_54 = NULL ;
}
if ( V_54 )
goto V_237;
F_82 ( & V_227 -> V_235 , V_230 ) ;
V_31:
F_83 ( & V_231 ) ;
return;
V_237:
F_5 ( L_5 , V_46 ) ;
goto V_31;
V_233:
F_5 ( L_6 ,
V_227 -> type ) ;
goto V_31;
}
void F_84 ( struct V_53 * V_227 )
{
if ( V_236 & V_227 -> V_75 ) {
F_5 ( L_7 ,
V_227 -> V_46 ) ;
} else {
F_79 ( & V_231 ) ;
F_85 ( & V_227 -> V_235 ) ;
F_83 ( & V_231 ) ;
F_86 () ;
}
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_238 = V_4 -> V_140 ;
T_3 V_239 = V_4 -> V_145 ;
struct V_240 * V_241 ;
struct V_242 * V_243 ;
T_3 V_244 ;
struct V_245 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_88 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_246 . V_247 )
V_239 = V_16 -> V_246 . V_248 ;
V_241 = & V_4 -> V_249 . V_250 . V_251 . V_252 ;
V_243 = F_89 ( V_241 , V_239 , 0 , F_90 ( V_2 ) ,
V_2 -> V_253 , V_2 -> V_95 ,
V_4 -> V_23 , V_4 -> V_146 , V_2 , false ) ;
if ( F_91 ( V_243 ) )
return F_92 ( V_243 ) ;
F_93 ( V_2 , & V_243 -> V_254 ) ;
V_244 = V_241 -> V_255 ;
if ( V_244 == V_238 )
return 0 ;
if ( V_256 > 1 ) {
F_94 ( L_8 ,
V_257 , & V_238 , & V_244 ) ;
}
V_4 -> V_140 = V_4 -> V_139 = V_244 ;
F_95 ( V_2 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_242 * V_243 = (struct V_242 * ) F_97 ( V_2 , 0 ) ;
T_3 V_239 ;
struct V_245 * V_16 ;
struct V_240 * V_241 ;
int V_27 ;
if ( V_243 )
return 0 ;
F_30 () ;
V_16 = F_27 ( V_4 -> V_16 ) ;
V_239 = V_4 -> V_145 ;
if ( V_16 && V_16 -> V_246 . V_247 )
V_239 = V_16 -> V_246 . V_248 ;
F_32 () ;
V_241 = & V_4 -> V_249 . V_250 . V_251 . V_252 ;
V_243 = F_98 ( F_43 ( V_2 ) , V_241 , V_2 , V_239 , V_4 -> V_140 ,
V_4 -> V_146 , V_4 -> V_23 ,
V_2 -> V_95 , F_90 ( V_2 ) ,
V_2 -> V_253 ) ;
if ( ! F_91 ( V_243 ) ) {
V_27 = 0 ;
F_93 ( V_2 , & V_243 -> V_254 ) ;
} else {
V_27 = F_92 ( V_243 ) ;
V_2 -> V_258 = 0 ;
if ( ! V_256 ||
V_2 -> V_9 != V_198 ||
( V_2 -> V_142 & V_143 ) ||
( V_27 = F_87 ( V_2 ) ) != 0 )
V_2 -> V_259 = - V_27 ;
}
return V_27 ;
}
static int F_99 ( struct V_260 * V_261 )
{
const struct V_262 * V_72 ;
const struct V_263 * V_264 ;
int V_55 ;
int V_265 ;
int V_27 = - V_28 ;
if ( F_29 ( ! F_100 ( V_261 , sizeof( * V_264 ) ) ) )
goto V_31;
V_264 = F_101 ( V_261 ) ;
V_265 = V_264 -> V_265 * 4 ;
if ( V_265 < sizeof( * V_264 ) )
goto V_31;
if ( F_29 ( ! F_100 ( V_261 , V_265 ) ) )
goto V_31;
F_102 ( V_261 , V_265 ) ;
F_103 ( V_261 ) ;
V_264 = F_101 ( V_261 ) ;
V_55 = V_264 -> V_46 ;
V_27 = - V_65 ;
F_30 () ;
V_72 = F_27 ( V_266 [ V_55 ] ) ;
if ( F_104 ( V_72 && V_72 -> V_267 . V_268 ) )
V_27 = V_72 -> V_267 . V_268 ( V_261 ) ;
F_32 () ;
V_31:
return V_27 ;
}
static struct V_260 * F_105 ( struct V_260 * V_261 ,
T_6 V_269 )
{
struct V_260 * V_270 = F_106 ( - V_28 ) ;
const struct V_262 * V_72 ;
struct V_263 * V_264 ;
int V_55 ;
int V_265 ;
int V_271 ;
unsigned int V_188 = 0 ;
if ( ! ( V_269 & V_272 ) )
V_269 &= ~ V_273 ;
if ( F_29 ( F_107 ( V_261 ) -> V_274 &
~ ( V_275 |
V_276 |
V_277 |
V_278 |
0 ) ) )
goto V_31;
if ( F_29 ( ! F_100 ( V_261 , sizeof( * V_264 ) ) ) )
goto V_31;
V_264 = F_101 ( V_261 ) ;
V_265 = V_264 -> V_265 * 4 ;
if ( V_265 < sizeof( * V_264 ) )
goto V_31;
if ( F_29 ( ! F_100 ( V_261 , V_265 ) ) )
goto V_31;
F_102 ( V_261 , V_265 ) ;
F_103 ( V_261 ) ;
V_264 = F_101 ( V_261 ) ;
V_271 = F_46 ( V_264 -> V_271 ) ;
V_55 = V_264 -> V_46 ;
V_270 = F_106 ( - V_65 ) ;
F_30 () ;
V_72 = F_27 ( V_266 [ V_55 ] ) ;
if ( F_104 ( V_72 && V_72 -> V_267 . V_279 ) )
V_270 = V_72 -> V_267 . V_279 ( V_261 , V_269 ) ;
F_32 () ;
if ( ! V_270 || F_91 ( V_270 ) )
goto V_31;
V_261 = V_270 ;
do {
V_264 = F_101 ( V_261 ) ;
if ( V_55 == V_280 ) {
V_264 -> V_271 = F_17 ( V_271 ) ;
V_264 -> V_281 = F_17 ( V_188 >> 3 ) ;
if ( V_261 -> V_282 != NULL )
V_264 -> V_281 |= F_17 ( V_283 ) ;
V_188 += ( V_261 -> V_284 - V_261 -> V_285 - V_264 -> V_265 * 4 ) ;
} else
V_264 -> V_271 = F_17 ( V_271 ++ ) ;
V_264 -> V_286 = F_17 ( V_261 -> V_284 - V_261 -> V_285 ) ;
V_264 -> V_287 = 0 ;
V_264 -> V_287 = F_108 ( F_109 ( V_261 ) , V_264 -> V_265 ) ;
} while ( ( V_261 = V_261 -> V_282 ) );
V_31:
return V_270 ;
}
static struct V_260 * * F_110 ( struct V_260 * * V_288 ,
struct V_260 * V_261 )
{
const struct V_262 * V_72 ;
struct V_260 * * V_289 = NULL ;
struct V_260 * V_227 ;
const struct V_263 * V_264 ;
unsigned int V_290 ;
unsigned int V_291 ;
unsigned int V_271 ;
int V_292 = 1 ;
int V_55 ;
V_291 = F_111 ( V_261 ) ;
V_290 = V_291 + sizeof( * V_264 ) ;
V_264 = F_112 ( V_261 , V_291 ) ;
if ( F_113 ( V_261 , V_290 ) ) {
V_264 = F_114 ( V_261 , V_290 , V_291 ) ;
if ( F_29 ( ! V_264 ) )
goto V_31;
}
V_55 = V_264 -> V_46 ;
F_30 () ;
V_72 = F_27 ( V_266 [ V_55 ] ) ;
if ( ! V_72 || ! V_72 -> V_267 . V_293 )
goto V_294;
if ( * ( V_295 * ) V_264 != 0x45 )
goto V_294;
if ( F_29 ( F_108 ( ( V_295 * ) V_264 , 5 ) ) )
goto V_294;
V_271 = F_115 ( * ( T_3 * ) & V_264 -> V_271 ) ;
V_292 = ( V_296 ) ( ( F_115 ( * ( T_3 * ) V_264 ) ^ F_116 ( V_261 ) ) | ( V_271 ^ V_297 ) ) ;
V_271 >>= 16 ;
for ( V_227 = * V_288 ; V_227 ; V_227 = V_227 -> V_282 ) {
struct V_263 * V_298 ;
if ( ! F_117 ( V_227 ) -> V_299 )
continue;
V_298 = F_101 ( V_227 ) ;
if ( ( V_264 -> V_46 ^ V_298 -> V_46 ) |
( ( V_300 T_1 ) V_264 -> V_255 ^ ( V_300 T_1 ) V_298 -> V_255 ) |
( ( V_300 T_1 ) V_264 -> V_239 ^ ( V_300 T_1 ) V_298 -> V_239 ) ) {
F_117 ( V_227 ) -> V_299 = 0 ;
continue;
}
F_117 ( V_227 ) -> V_292 |=
( V_264 -> V_301 ^ V_298 -> V_301 ) |
( V_264 -> V_302 ^ V_298 -> V_302 ) |
( ( V_296 ) ( F_46 ( V_298 -> V_271 ) + F_117 ( V_227 ) -> V_303 ) ^ V_271 ) ;
F_117 ( V_227 ) -> V_292 |= V_292 ;
}
F_117 ( V_261 ) -> V_292 |= V_292 ;
F_118 ( V_261 , sizeof( * V_264 ) ) ;
F_119 ( V_261 , F_111 ( V_261 ) ) ;
V_289 = V_72 -> V_267 . V_293 ( V_288 , V_261 ) ;
V_294:
F_32 () ;
V_31:
F_117 ( V_261 ) -> V_292 |= V_292 ;
return V_289 ;
}
static int F_120 ( struct V_260 * V_261 )
{
T_7 V_304 = F_17 ( V_261 -> V_284 - F_121 ( V_261 ) ) ;
struct V_263 * V_264 = F_101 ( V_261 ) ;
const struct V_262 * V_72 ;
int V_55 = V_264 -> V_46 ;
int V_27 = - V_305 ;
F_122 ( & V_264 -> V_287 , V_264 -> V_286 , V_304 ) ;
V_264 -> V_286 = V_304 ;
F_30 () ;
V_72 = F_27 ( V_266 [ V_55 ] ) ;
if ( F_7 ( ! V_72 || ! V_72 -> V_267 . V_306 ) )
goto V_294;
V_27 = V_72 -> V_267 . V_306 ( V_261 ) ;
V_294:
F_32 () ;
return V_27 ;
}
int F_123 ( struct V_1 * * V_2 , unsigned short V_307 ,
unsigned short type , unsigned char V_46 ,
struct V_45 * V_45 )
{
struct V_24 * V_1 ;
int V_308 = F_124 ( V_307 , type , V_46 , & V_1 ) ;
if ( V_308 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_309 = V_310 ;
( * V_2 ) -> V_20 -> V_311 ( * V_2 ) ;
F_125 ( * V_2 , V_45 ) ;
}
return V_308 ;
}
unsigned long F_126 ( void T_8 * V_312 [] , int V_313 )
{
unsigned long V_314 = 0 ;
int V_315 , V_316 ;
F_127 (i) {
for ( V_316 = 0 ; V_316 < V_317 ; V_316 ++ )
V_314 += * ( ( ( unsigned long * ) F_128 ( V_312 [ V_316 ] , V_315 ) ) + V_313 ) ;
}
return V_314 ;
}
T_9 F_129 ( void T_8 * V_312 [] , int V_313 , T_4 V_318 )
{
T_9 V_314 = 0 ;
int V_319 ;
F_127 (cpu) {
void * V_320 ;
struct V_321 * V_322 ;
T_9 V_323 ;
unsigned int V_324 ;
V_320 = F_128 ( V_312 [ 0 ] , V_319 ) ;
V_322 = (struct V_321 * ) ( V_320 + V_318 ) ;
do {
V_324 = F_130 ( V_322 ) ;
V_323 = * ( ( ( T_9 * ) V_320 ) + V_313 ) ;
} while ( F_131 ( V_322 , V_324 ) );
V_314 += V_323 ;
}
return V_314 ;
}
int F_132 ( void T_8 * V_325 [ 2 ] , T_4 V_326 , T_4 V_327 )
{
F_133 ( V_325 == NULL ) ;
V_325 [ 0 ] = F_134 ( V_326 , V_327 ) ;
if ( ! V_325 [ 0 ] )
return - V_328 ;
#if V_317 == 2
V_325 [ 1 ] = F_134 ( V_326 , V_327 ) ;
if ( ! V_325 [ 1 ] ) {
F_135 ( V_325 [ 0 ] ) ;
V_325 [ 0 ] = NULL ;
return - V_328 ;
}
#endif
return 0 ;
}
void F_136 ( void T_8 * V_325 [ V_317 ] )
{
int V_315 ;
F_133 ( V_325 == NULL ) ;
for ( V_315 = 0 ; V_315 < V_317 ; V_315 ++ ) {
F_135 ( V_325 [ V_315 ] ) ;
V_325 [ V_315 ] = NULL ;
}
}
static T_10 int F_137 ( struct V_45 * V_45 )
{
if ( F_132 ( ( void T_8 * * ) V_45 -> V_312 . V_329 ,
sizeof( struct V_330 ) ,
F_138 ( struct V_330 ) ) < 0 )
goto V_331;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_312 . V_332 ,
sizeof( struct V_333 ) ,
F_138 ( struct V_333 ) ) < 0 )
goto V_334;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_312 . V_335 ,
sizeof( struct V_336 ) ,
F_138 ( struct V_336 ) ) < 0 )
goto V_337;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_312 . V_338 ,
sizeof( struct V_339 ) ,
F_138 ( struct V_339 ) ) < 0 )
goto V_340;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_312 . V_341 ,
sizeof( struct V_339 ) ,
F_138 ( struct V_339 ) ) < 0 )
goto V_342;
if ( F_132 ( ( void T_8 * * ) V_45 -> V_312 . V_343 ,
sizeof( struct V_344 ) ,
F_138 ( struct V_344 ) ) < 0 )
goto V_345;
V_45 -> V_312 . V_346 = F_139 ( sizeof( struct V_347 ) ,
V_78 ) ;
if ( ! V_45 -> V_312 . V_346 )
goto V_348;
F_140 ( V_45 ) ;
return 0 ;
V_348:
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_343 ) ;
V_345:
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_341 ) ;
V_342:
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_338 ) ;
V_340:
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_335 ) ;
V_337:
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_332 ) ;
V_334:
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_329 ) ;
V_331:
return - V_328 ;
}
static T_11 void F_141 ( struct V_45 * V_45 )
{
F_9 ( V_45 -> V_312 . V_346 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_343 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_341 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_338 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_335 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_332 ) ;
F_136 ( ( void T_8 * * ) V_45 -> V_312 . V_329 ) ;
}
static int T_12 F_142 ( void )
{
return F_143 ( & V_349 ) ;
}
static int T_12 F_144 ( void )
{
if ( F_145 ( & V_350 , V_280 ) < 0 )
F_146 ( L_9 , V_257 ) ;
if ( F_145 ( & V_351 , V_164 ) < 0 )
F_146 ( L_10 , V_257 ) ;
F_147 ( & V_352 ) ;
return 0 ;
}
static int T_12 F_148 ( void )
{
struct V_260 * V_353 ;
struct V_53 * V_354 ;
struct V_228 * V_355 ;
int V_308 = - V_28 ;
F_149 ( sizeof( struct V_356 ) > sizeof( V_353 -> V_357 ) ) ;
V_358 = F_139 ( 65536 / 8 , V_78 ) ;
if ( ! V_358 )
goto V_31;
V_308 = F_150 ( & V_359 , 1 ) ;
if ( V_308 )
goto V_360;
V_308 = F_150 ( & V_361 , 1 ) ;
if ( V_308 )
goto V_362;
V_308 = F_150 ( & V_363 , 1 ) ;
if ( V_308 )
goto V_364;
V_308 = F_150 ( & V_365 , 1 ) ;
if ( V_308 )
goto V_366;
( void ) F_151 ( & V_367 ) ;
#ifdef F_152
F_153 () ;
#endif
V_359 . V_368 = V_49 . V_369 . V_370 ;
if ( F_154 ( & V_371 , V_372 ) < 0 )
F_146 ( L_11 , V_257 ) ;
if ( F_154 ( & V_373 , V_280 ) < 0 )
F_146 ( L_12 , V_257 ) ;
if ( F_154 ( & V_374 , V_164 ) < 0 )
F_146 ( L_13 , V_257 ) ;
#ifdef F_155
if ( F_154 ( & V_375 , V_376 ) < 0 )
F_146 ( L_14 , V_257 ) ;
#endif
for ( V_355 = & V_234 [ 0 ] ; V_355 < & V_234 [ V_232 ] ; ++ V_355 )
F_156 ( V_355 ) ;
for ( V_354 = V_377 ; V_354 < & V_377 [ V_378 ] ; ++ V_354 )
F_78 ( V_354 ) ;
F_157 () ;
F_158 () ;
F_159 () ;
F_160 () ;
F_161 () ;
F_162 () ;
F_163 () ;
if ( F_164 () < 0 )
F_165 ( L_15 ) ;
#if F_166 ( V_379 )
if ( F_167 () )
F_146 ( L_16 , V_257 ) ;
#endif
if ( F_142 () )
F_146 ( L_17 , V_257 ) ;
F_168 () ;
F_169 () ;
F_170 ( & V_380 ) ;
V_308 = 0 ;
V_31:
return V_308 ;
V_366:
F_171 ( & V_363 ) ;
V_364:
F_171 ( & V_361 ) ;
V_362:
F_171 ( & V_359 ) ;
V_360:
F_9 ( V_358 ) ;
goto V_31;
}
static int T_12 F_168 ( void )
{
int V_308 = 0 ;
if ( F_172 () )
goto V_381;
if ( F_173 () )
goto V_382;
if ( F_174 () )
goto V_383;
if ( F_175 () )
goto V_384;
if ( F_176 () )
goto V_385;
V_31:
return V_308 ;
V_385:
F_177 () ;
V_384:
F_178 () ;
V_383:
F_179 () ;
V_382:
F_180 () ;
V_381:
V_308 = - V_328 ;
goto V_31;
}
static int T_12 F_168 ( void )
{
return 0 ;
}
