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
V_27 = F_19 ( V_2 , V_25 ) ;
if ( V_27 )
goto V_31;
}
V_2 -> V_35 = V_25 ;
V_27 = 0 ;
V_31:
F_16 ( V_2 ) ;
return V_27 ;
}
void F_20 ( void )
{
T_1 V_36 ;
do {
F_21 ( & V_36 , sizeof( V_36 ) ) ;
} while ( V_36 == 0 );
F_22 ( & V_37 , 0 , V_36 ) ;
}
static inline int F_23 ( struct V_38 * V_38 , T_2 V_39 )
{
const struct V_40 * V_41 ;
if ( F_24 ( V_38 , & V_42 ) )
return 1 ;
V_41 = F_25 ( V_43 [ V_39 ] ) ;
if ( V_41 == NULL ) {
return 1 ;
}
return V_41 -> V_44 ;
}
static int F_26 ( struct V_38 * V_38 , struct V_24 * V_1 , int V_39 ,
int V_45 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
struct V_3 * V_4 ;
struct V_48 * V_49 ;
unsigned char V_50 ;
char V_51 ;
int V_52 = 0 ;
int V_27 ;
if ( F_27 ( ! V_37 ) )
if ( V_1 -> type != V_53 && V_1 -> type != V_54 )
F_20 () ;
V_1 -> V_29 = V_30 ;
V_55:
V_27 = - V_56 ;
F_28 () ;
F_29 (answer, &inetsw[sock->type], list) {
V_27 = 0 ;
if ( V_39 == V_47 -> V_39 ) {
if ( V_39 != V_57 )
break;
} else {
if ( V_57 == V_39 ) {
V_39 = V_47 -> V_39 ;
break;
}
if ( V_57 == V_47 -> V_39 )
break;
}
V_27 = - V_58 ;
}
if ( F_27 ( V_27 ) ) {
if ( V_52 < 2 ) {
F_30 () ;
if ( ++ V_52 == 1 )
F_31 ( L_3 ,
V_59 , V_39 , V_1 -> type ) ;
else
F_31 ( L_4 ,
V_59 , V_39 ) ;
goto V_55;
} else
goto V_60;
}
V_27 = - V_61 ;
if ( V_1 -> type == V_53 && ! V_45 && ! F_32 ( V_62 ) )
goto V_60;
V_27 = - V_63 ;
if ( ! F_23 ( V_38 , V_39 ) )
goto V_60;
V_1 -> V_64 = V_47 -> V_64 ;
V_49 = V_47 -> V_65 ;
V_51 = V_47 -> V_66 ;
V_50 = V_47 -> V_67 ;
F_30 () ;
F_7 ( V_49 -> V_68 == NULL ) ;
V_27 = - V_69 ;
V_2 = F_33 ( V_38 , V_59 , V_70 , V_49 ) ;
if ( V_2 == NULL )
goto V_31;
V_27 = 0 ;
V_2 -> V_71 = V_51 ;
if ( V_72 & V_50 )
V_2 -> V_73 = V_74 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_75 = ( V_76 & V_50 ) != 0 ;
V_4 -> V_77 = 0 ;
if ( V_53 == V_1 -> type ) {
V_4 -> V_19 = V_39 ;
if ( V_78 == V_39 )
V_4 -> V_79 = 1 ;
}
if ( V_80 . V_81 )
V_4 -> V_82 = V_83 ;
else
V_4 -> V_82 = V_84 ;
V_4 -> V_85 = 0 ;
F_34 ( V_1 , V_2 ) ;
V_2 -> V_86 = F_1 ;
V_2 -> V_87 = V_39 ;
V_2 -> V_88 = V_2 -> V_20 -> V_89 ;
V_4 -> V_90 = - 1 ;
V_4 -> V_91 = 1 ;
V_4 -> V_92 = 1 ;
V_4 -> V_93 = 1 ;
V_4 -> V_94 = 0 ;
V_4 -> V_95 = NULL ;
V_4 -> V_96 = 0 ;
F_35 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_2 -> V_20 -> V_97 ( V_2 ) ;
}
if ( V_2 -> V_20 -> V_98 ) {
V_27 = V_2 -> V_20 -> V_98 ( V_2 ) ;
if ( V_27 )
F_36 ( V_2 ) ;
}
V_31:
return V_27 ;
V_60:
F_30 () ;
goto V_31;
}
int F_37 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_99 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
V_99 = 0 ;
if ( F_6 ( V_2 , V_100 ) &&
! ( V_101 -> V_67 & V_102 ) )
V_99 = V_2 -> V_103 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_104 ( V_2 , V_99 ) ;
}
return 0 ;
}
int F_40 ( struct V_24 * V_1 , struct V_105 * V_106 , int V_107 )
{
struct V_108 * V_109 = (struct V_108 * ) V_106 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_110 ;
int V_111 ;
int V_27 ;
if ( V_2 -> V_20 -> V_112 ) {
V_27 = V_2 -> V_20 -> V_112 ( V_2 , V_106 , V_107 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_107 < sizeof( struct V_108 ) )
goto V_31;
if ( V_109 -> V_113 != V_114 ) {
V_27 = - V_63 ;
if ( V_109 -> V_113 != V_115 ||
V_109 -> V_116 . V_117 != F_41 ( V_118 ) )
goto V_31;
}
V_111 = F_42 ( F_43 ( V_2 ) , V_109 -> V_116 . V_117 ) ;
V_27 = - V_119 ;
if ( ! V_120 &&
! ( V_4 -> V_121 || V_4 -> V_122 ) &&
V_109 -> V_116 . V_117 != F_41 ( V_118 ) &&
V_111 != V_123 &&
V_111 != V_124 &&
V_111 != V_125 )
goto V_31;
V_110 = F_44 ( V_109 -> V_126 ) ;
V_27 = - V_127 ;
if ( V_110 && V_110 < V_128 && ! F_32 ( V_129 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_130;
V_4 -> V_131 = V_4 -> V_132 = V_109 -> V_116 . V_117 ;
if ( V_111 == V_124 || V_111 == V_125 )
V_4 -> V_132 = 0 ;
if ( V_2 -> V_20 -> V_21 ( V_2 , V_110 ) ) {
V_4 -> V_132 = V_4 -> V_131 = 0 ;
V_27 = - V_133 ;
goto V_130;
}
if ( V_4 -> V_131 )
V_2 -> V_134 |= V_135 ;
if ( V_110 )
V_2 -> V_134 |= V_136 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_137 = 0 ;
V_4 -> V_138 = 0 ;
F_45 ( V_2 ) ;
V_27 = 0 ;
V_130:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_46 ( struct V_24 * V_1 , struct V_105 * V_106 ,
int V_107 , int V_67 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_107 < sizeof( V_106 -> V_139 ) )
return - V_28 ;
if ( V_106 -> V_139 == V_115 )
return V_2 -> V_20 -> V_140 ( V_2 , V_67 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_141 ( V_2 , V_106 , V_107 ) ;
}
static long F_47 ( struct V_1 * V_2 , long V_142 , int V_143 )
{
F_48 ( V_144 ) ;
F_49 ( F_50 ( V_2 ) , & V_144 , V_145 ) ;
V_2 -> V_146 += V_143 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_147 | V_148 ) ) {
F_16 ( V_2 ) ;
V_142 = F_51 ( V_142 ) ;
F_15 ( V_2 ) ;
if ( F_52 ( V_101 ) || ! V_142 )
break;
F_49 ( F_50 ( V_2 ) , & V_144 , V_145 ) ;
}
F_53 ( F_50 ( V_2 ) , & V_144 ) ;
V_2 -> V_146 -= V_143 ;
return V_142 ;
}
int F_54 ( struct V_24 * V_1 , struct V_105 * V_106 ,
int V_107 , int V_67 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_142 ;
if ( V_107 < sizeof( V_106 -> V_139 ) )
return - V_28 ;
if ( V_106 -> V_139 == V_115 ) {
V_27 = V_2 -> V_20 -> V_140 ( V_2 , V_67 ) ;
V_1 -> V_29 = V_27 ? V_149 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_150 :
V_27 = - V_151 ;
goto V_31;
case V_152 :
V_27 = - V_153 ;
break;
case V_30 :
V_27 = - V_151 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_141 ( V_2 , V_106 , V_107 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_152 ;
V_27 = - V_154 ;
break;
}
V_142 = F_55 ( V_2 , V_67 & V_155 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_147 | V_148 ) ) {
int V_143 = ( V_2 -> V_87 == V_156 ) &&
F_56 ( V_2 ) -> V_157 &&
F_56 ( V_2 ) -> V_157 -> V_158 ? 1 : 0 ;
if ( ! V_142 || ! F_47 ( V_2 , V_142 , V_143 ) )
goto V_31;
V_27 = F_57 ( V_142 ) ;
if ( F_52 ( V_101 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_159;
V_1 -> V_29 = V_150 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_159:
V_27 = V_159 ( V_2 ) ? : - V_160 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_140 ( V_2 , V_67 ) )
V_1 -> V_29 = V_149 ;
goto V_31;
}
int F_58 ( struct V_24 * V_1 , struct V_105 * V_106 ,
int V_107 , int V_67 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_54 ( V_1 , V_106 , V_107 , V_67 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_59 ( struct V_24 * V_1 , struct V_24 * V_161 , int V_67 )
{
struct V_1 * V_162 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_163 = V_162 -> V_20 -> V_164 ( V_162 , V_67 , & V_27 ) ;
if ( ! V_163 )
goto V_165;
F_15 ( V_163 ) ;
F_60 ( V_163 ) ;
F_7 ( ! ( ( 1 << V_163 -> V_9 ) &
( V_166 | V_167 | V_32 ) ) ) ;
F_61 ( V_163 , V_161 ) ;
V_161 -> V_29 = V_150 ;
V_27 = 0 ;
F_16 ( V_163 ) ;
V_165:
return V_27 ;
}
int F_62 ( struct V_24 * V_1 , struct V_105 * V_106 ,
int * V_168 , int V_169 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_63 ( struct V_108 * , sin , V_106 ) ;
sin -> V_113 = V_114 ;
if ( V_169 ) {
if ( ! V_4 -> V_138 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_147 ) ) &&
V_169 == 1 ) )
return - V_170 ;
sin -> V_126 = V_4 -> V_138 ;
sin -> V_116 . V_117 = V_4 -> V_137 ;
} else {
T_3 V_109 = V_4 -> V_131 ;
if ( ! V_109 )
V_109 = V_4 -> V_132 ;
sin -> V_126 = V_4 -> V_23 ;
sin -> V_116 . V_117 = V_109 ;
}
memset ( sin -> V_171 , 0 , sizeof( sin -> V_171 ) ) ;
* V_168 = sizeof( * sin ) ;
return 0 ;
}
int F_64 ( struct V_172 * V_173 , struct V_24 * V_1 , struct V_174 * V_175 ,
T_4 V_176 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_60 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_177 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_178 ( V_173 , V_2 , V_175 , V_176 ) ;
}
T_5 F_65 ( struct V_24 * V_1 , struct V_179 * V_179 , int V_180 ,
T_4 V_176 , int V_67 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_60 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_177 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_181 )
return V_2 -> V_20 -> V_181 ( V_2 , V_179 , V_180 , V_176 , V_67 ) ;
return F_66 ( V_1 , V_179 , V_180 , V_176 , V_67 ) ;
}
int F_67 ( struct V_172 * V_173 , struct V_24 * V_1 , struct V_174 * V_175 ,
T_4 V_176 , int V_67 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_107 = 0 ;
int V_27 ;
F_60 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_182 ( V_173 , V_2 , V_175 , V_176 , V_67 & V_183 ,
V_67 & ~ V_183 , & V_107 ) ;
if ( V_27 >= 0 )
V_175 -> V_184 = V_107 ;
return V_27 ;
}
int F_68 ( struct V_24 * V_1 , int V_185 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_185 ++ ;
if ( ( V_185 & ~ V_186 ) || ! V_185 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_152 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_147 | V_148 | V_32 ) )
V_1 -> V_29 = V_149 ;
else
V_1 -> V_29 = V_150 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_170 ;
default:
V_2 -> V_187 |= V_185 ;
if ( V_2 -> V_20 -> V_188 )
V_2 -> V_20 -> V_188 ( V_2 , V_185 ) ;
break;
case V_34 :
if ( ! ( V_185 & V_189 ) )
break;
case V_190 :
V_27 = V_2 -> V_20 -> V_140 ( V_2 , V_155 ) ;
V_1 -> V_29 = V_27 ? V_149 : V_30 ;
break;
}
V_2 -> V_191 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_69 ( struct V_24 * V_1 , unsigned int V_192 , unsigned long V_193 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_38 * V_38 = F_43 ( V_2 ) ;
switch ( V_192 ) {
case V_194 :
V_27 = F_70 ( V_2 , (struct V_195 V_196 * ) V_193 ) ;
break;
case V_197 :
V_27 = F_71 ( V_2 , (struct V_198 V_196 * ) V_193 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
V_27 = F_72 ( V_38 , V_192 , ( void V_196 * ) V_193 ) ;
break;
case V_202 :
case V_203 :
case V_204 :
V_27 = F_73 ( V_38 , V_192 , ( void V_196 * ) V_193 ) ;
break;
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
V_27 = F_74 ( V_38 , V_192 , ( void V_196 * ) V_193 ) ;
break;
default:
if ( V_2 -> V_20 -> V_216 )
V_27 = V_2 -> V_20 -> V_216 ( V_2 , V_192 , V_193 ) ;
else
V_27 = - V_217 ;
break;
}
return V_27 ;
}
static int F_75 ( struct V_24 * V_1 , unsigned int V_192 , unsigned long V_193 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_217 ;
if ( V_2 -> V_20 -> V_218 )
V_27 = V_2 -> V_20 -> V_218 ( V_2 , V_192 , V_193 ) ;
return V_27 ;
}
void F_76 ( struct V_46 * V_219 )
{
struct V_220 * V_221 ;
struct V_46 * V_47 ;
int V_39 = V_219 -> V_39 ;
struct V_220 * V_222 ;
F_77 ( & V_223 ) ;
if ( V_219 -> type >= V_224 )
goto V_225;
V_47 = NULL ;
V_222 = & V_226 [ V_219 -> type ] ;
F_78 (lh, &inetsw[p->type]) {
V_47 = F_79 ( V_221 , struct V_46 , V_227 ) ;
if ( V_228 & V_47 -> V_67 ) {
if ( V_39 == V_47 -> V_39 )
break;
V_222 = V_221 ;
}
V_47 = NULL ;
}
if ( V_47 )
goto V_229;
F_80 ( & V_219 -> V_227 , V_222 ) ;
V_31:
F_81 ( & V_223 ) ;
return;
V_229:
F_5 ( L_5 , V_39 ) ;
goto V_31;
V_225:
F_5 ( L_6 ,
V_219 -> type ) ;
goto V_31;
}
void F_82 ( struct V_46 * V_219 )
{
if ( V_228 & V_219 -> V_67 ) {
F_5 ( L_7 ,
V_219 -> V_39 ) ;
} else {
F_77 ( & V_223 ) ;
F_83 ( & V_219 -> V_227 ) ;
F_81 ( & V_223 ) ;
F_84 () ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_230 = V_4 -> V_132 ;
T_3 V_231 = V_4 -> V_137 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
T_3 V_236 ;
struct V_237 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_86 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_238 . V_239 )
V_231 = V_16 -> V_238 . V_240 ;
V_233 = & V_4 -> V_241 . V_242 . V_243 . V_244 ;
V_235 = F_87 ( V_233 , V_231 , 0 , F_88 ( V_2 ) ,
V_2 -> V_245 , V_2 -> V_87 ,
V_4 -> V_23 , V_4 -> V_138 , V_2 , false ) ;
if ( F_89 ( V_235 ) )
return F_90 ( V_235 ) ;
F_91 ( V_2 , & V_235 -> V_246 ) ;
V_236 = V_233 -> V_247 ;
if ( V_236 == V_230 )
return 0 ;
if ( V_248 > 1 ) {
F_92 ( L_8 ,
V_249 , & V_230 , & V_236 ) ;
}
V_4 -> V_132 = V_4 -> V_131 = V_236 ;
F_93 ( V_2 ) ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_234 * V_235 = (struct V_234 * ) F_95 ( V_2 , 0 ) ;
T_3 V_231 ;
struct V_237 * V_16 ;
struct V_232 * V_233 ;
int V_27 ;
if ( V_235 )
return 0 ;
F_28 () ;
V_16 = F_25 ( V_4 -> V_16 ) ;
V_231 = V_4 -> V_137 ;
if ( V_16 && V_16 -> V_238 . V_239 )
V_231 = V_16 -> V_238 . V_240 ;
F_30 () ;
V_233 = & V_4 -> V_241 . V_242 . V_243 . V_244 ;
V_235 = F_96 ( F_43 ( V_2 ) , V_233 , V_2 , V_231 , V_4 -> V_132 ,
V_4 -> V_138 , V_4 -> V_23 ,
V_2 -> V_87 , F_88 ( V_2 ) ,
V_2 -> V_245 ) ;
if ( ! F_89 ( V_235 ) ) {
V_27 = 0 ;
F_91 ( V_2 , & V_235 -> V_246 ) ;
} else {
V_27 = F_90 ( V_235 ) ;
V_2 -> V_250 = 0 ;
if ( ! V_248 ||
V_2 -> V_9 != V_190 ||
( V_2 -> V_134 & V_135 ) ||
( V_27 = F_85 ( V_2 ) ) != 0 )
V_2 -> V_251 = - V_27 ;
}
return V_27 ;
}
static int F_97 ( struct V_252 * V_253 )
{
const struct V_40 * V_64 ;
const struct V_254 * V_255 ;
int V_48 ;
int V_256 ;
int V_27 = - V_28 ;
if ( F_27 ( ! F_98 ( V_253 , sizeof( * V_255 ) ) ) )
goto V_31;
V_255 = F_99 ( V_253 ) ;
V_256 = V_255 -> V_256 * 4 ;
if ( V_256 < sizeof( * V_255 ) )
goto V_31;
if ( F_27 ( ! F_98 ( V_253 , V_256 ) ) )
goto V_31;
F_100 ( V_253 , V_256 ) ;
F_101 ( V_253 ) ;
V_255 = F_99 ( V_253 ) ;
V_48 = V_255 -> V_39 ;
V_27 = - V_58 ;
F_28 () ;
V_64 = F_25 ( V_43 [ V_48 ] ) ;
if ( F_102 ( V_64 && V_64 -> V_257 ) )
V_27 = V_64 -> V_257 ( V_253 ) ;
F_30 () ;
V_31:
return V_27 ;
}
static struct V_252 * F_103 ( struct V_252 * V_253 ,
T_6 V_258 )
{
struct V_252 * V_259 = F_104 ( - V_28 ) ;
const struct V_40 * V_64 ;
struct V_254 * V_255 ;
int V_48 ;
int V_256 ;
int V_260 ;
unsigned int V_180 = 0 ;
if ( ! ( V_258 & V_261 ) )
V_258 &= ~ V_262 ;
if ( F_27 ( F_105 ( V_253 ) -> V_263 &
~ ( V_264 |
V_265 |
V_266 |
V_267 |
0 ) ) )
goto V_31;
if ( F_27 ( ! F_98 ( V_253 , sizeof( * V_255 ) ) ) )
goto V_31;
V_255 = F_99 ( V_253 ) ;
V_256 = V_255 -> V_256 * 4 ;
if ( V_256 < sizeof( * V_255 ) )
goto V_31;
if ( F_27 ( ! F_98 ( V_253 , V_256 ) ) )
goto V_31;
F_100 ( V_253 , V_256 ) ;
F_101 ( V_253 ) ;
V_255 = F_99 ( V_253 ) ;
V_260 = F_44 ( V_255 -> V_260 ) ;
V_48 = V_255 -> V_39 ;
V_259 = F_104 ( - V_58 ) ;
F_28 () ;
V_64 = F_25 ( V_43 [ V_48 ] ) ;
if ( F_102 ( V_64 && V_64 -> V_268 ) )
V_259 = V_64 -> V_268 ( V_253 , V_258 ) ;
F_30 () ;
if ( ! V_259 || F_89 ( V_259 ) )
goto V_31;
V_253 = V_259 ;
do {
V_255 = F_99 ( V_253 ) ;
if ( V_48 == V_269 ) {
V_255 -> V_260 = F_17 ( V_260 ) ;
V_255 -> V_270 = F_17 ( V_180 >> 3 ) ;
if ( V_253 -> V_271 != NULL )
V_255 -> V_270 |= F_17 ( V_272 ) ;
V_180 += ( V_253 -> V_273 - V_253 -> V_274 - V_255 -> V_256 * 4 ) ;
} else
V_255 -> V_260 = F_17 ( V_260 ++ ) ;
V_255 -> V_275 = F_17 ( V_253 -> V_273 - V_253 -> V_274 ) ;
V_255 -> V_276 = 0 ;
V_255 -> V_276 = F_106 ( F_107 ( V_253 ) , V_255 -> V_256 ) ;
} while ( ( V_253 = V_253 -> V_271 ) );
V_31:
return V_259 ;
}
static struct V_252 * * F_108 ( struct V_252 * * V_277 ,
struct V_252 * V_253 )
{
const struct V_40 * V_64 ;
struct V_252 * * V_278 = NULL ;
struct V_252 * V_219 ;
const struct V_254 * V_255 ;
unsigned int V_279 ;
unsigned int V_280 ;
unsigned int V_260 ;
int V_281 = 1 ;
int V_48 ;
V_280 = F_109 ( V_253 ) ;
V_279 = V_280 + sizeof( * V_255 ) ;
V_255 = F_110 ( V_253 , V_280 ) ;
if ( F_111 ( V_253 , V_279 ) ) {
V_255 = F_112 ( V_253 , V_279 , V_280 ) ;
if ( F_27 ( ! V_255 ) )
goto V_31;
}
V_48 = V_255 -> V_39 ;
F_28 () ;
V_64 = F_25 ( V_43 [ V_48 ] ) ;
if ( ! V_64 || ! V_64 -> V_282 )
goto V_283;
if ( * ( V_284 * ) V_255 != 0x45 )
goto V_283;
if ( F_27 ( F_106 ( ( V_284 * ) V_255 , V_255 -> V_256 ) ) )
goto V_283;
V_260 = F_113 ( * ( T_3 * ) & V_255 -> V_260 ) ;
V_281 = ( V_285 ) ( ( F_113 ( * ( T_3 * ) V_255 ) ^ F_114 ( V_253 ) ) | ( V_260 ^ V_286 ) ) ;
V_260 >>= 16 ;
for ( V_219 = * V_277 ; V_219 ; V_219 = V_219 -> V_271 ) {
struct V_254 * V_287 ;
if ( ! F_115 ( V_219 ) -> V_288 )
continue;
V_287 = F_99 ( V_219 ) ;
if ( ( V_255 -> V_39 ^ V_287 -> V_39 ) |
( V_255 -> V_289 ^ V_287 -> V_289 ) |
( ( V_290 T_1 ) V_255 -> V_247 ^ ( V_290 T_1 ) V_287 -> V_247 ) |
( ( V_290 T_1 ) V_255 -> V_231 ^ ( V_290 T_1 ) V_287 -> V_231 ) ) {
F_115 ( V_219 ) -> V_288 = 0 ;
continue;
}
F_115 ( V_219 ) -> V_281 |=
( V_255 -> V_291 ^ V_287 -> V_291 ) |
( ( V_285 ) ( F_44 ( V_287 -> V_260 ) + F_115 ( V_219 ) -> V_292 ) ^ V_260 ) ;
F_115 ( V_219 ) -> V_281 |= V_281 ;
}
F_115 ( V_253 ) -> V_281 |= V_281 ;
F_116 ( V_253 , sizeof( * V_255 ) ) ;
F_117 ( V_253 , F_109 ( V_253 ) ) ;
V_278 = V_64 -> V_282 ( V_277 , V_253 ) ;
V_283:
F_30 () ;
V_31:
F_115 ( V_253 ) -> V_281 |= V_281 ;
return V_278 ;
}
static int F_118 ( struct V_252 * V_253 )
{
T_7 V_293 = F_17 ( V_253 -> V_273 - F_119 ( V_253 ) ) ;
struct V_254 * V_255 = F_99 ( V_253 ) ;
const struct V_40 * V_64 ;
int V_48 = V_255 -> V_39 ;
int V_27 = - V_294 ;
F_120 ( & V_255 -> V_276 , V_255 -> V_275 , V_293 ) ;
V_255 -> V_275 = V_293 ;
F_28 () ;
V_64 = F_25 ( V_43 [ V_48 ] ) ;
if ( F_7 ( ! V_64 || ! V_64 -> V_295 ) )
goto V_283;
V_27 = V_64 -> V_295 ( V_253 ) ;
V_283:
F_30 () ;
return V_27 ;
}
int F_121 ( struct V_1 * * V_2 , unsigned short V_296 ,
unsigned short type , unsigned char V_39 ,
struct V_38 * V_38 )
{
struct V_24 * V_1 ;
int V_297 = F_122 ( V_296 , type , V_39 , & V_1 ) ;
if ( V_297 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_298 = V_299 ;
( * V_2 ) -> V_20 -> V_300 ( * V_2 ) ;
F_123 ( * V_2 , V_38 ) ;
}
return V_297 ;
}
unsigned long F_124 ( void T_8 * V_301 [] , int V_302 )
{
unsigned long V_303 = 0 ;
int V_304 , V_305 ;
F_125 (i) {
for ( V_305 = 0 ; V_305 < V_306 ; V_305 ++ )
V_303 += * ( ( ( unsigned long * ) F_126 ( V_301 [ V_305 ] , V_304 ) ) + V_302 ) ;
}
return V_303 ;
}
T_9 F_127 ( void T_8 * V_301 [] , int V_302 , T_4 V_307 )
{
T_9 V_303 = 0 ;
int V_308 ;
F_125 (cpu) {
void * V_309 ;
struct V_310 * V_311 ;
T_9 V_312 ;
unsigned int V_313 ;
V_309 = F_126 ( V_301 [ 0 ] , V_308 ) ;
V_311 = (struct V_310 * ) ( V_309 + V_307 ) ;
do {
V_313 = F_128 ( V_311 ) ;
V_312 = * ( ( ( T_9 * ) V_309 ) + V_302 ) ;
} while ( F_129 ( V_311 , V_313 ) );
V_303 += V_312 ;
}
return V_303 ;
}
int F_130 ( void T_8 * V_314 [ 2 ] , T_4 V_315 , T_4 V_316 )
{
F_131 ( V_314 == NULL ) ;
V_314 [ 0 ] = F_132 ( V_315 , V_316 ) ;
if ( ! V_314 [ 0 ] )
return - V_317 ;
#if V_306 == 2
V_314 [ 1 ] = F_132 ( V_315 , V_316 ) ;
if ( ! V_314 [ 1 ] ) {
F_133 ( V_314 [ 0 ] ) ;
V_314 [ 0 ] = NULL ;
return - V_317 ;
}
#endif
return 0 ;
}
void F_134 ( void T_8 * V_314 [ V_306 ] )
{
int V_304 ;
F_131 ( V_314 == NULL ) ;
for ( V_304 = 0 ; V_304 < V_306 ; V_304 ++ ) {
F_133 ( V_314 [ V_304 ] ) ;
V_314 [ V_304 ] = NULL ;
}
}
static T_10 int F_135 ( struct V_38 * V_38 )
{
if ( F_130 ( ( void T_8 * * ) V_38 -> V_301 . V_318 ,
sizeof( struct V_319 ) ,
F_136 ( struct V_319 ) ) < 0 )
goto V_320;
if ( F_130 ( ( void T_8 * * ) V_38 -> V_301 . V_321 ,
sizeof( struct V_322 ) ,
F_136 ( struct V_322 ) ) < 0 )
goto V_323;
if ( F_130 ( ( void T_8 * * ) V_38 -> V_301 . V_324 ,
sizeof( struct V_325 ) ,
F_136 ( struct V_325 ) ) < 0 )
goto V_326;
if ( F_130 ( ( void T_8 * * ) V_38 -> V_301 . V_327 ,
sizeof( struct V_328 ) ,
F_136 ( struct V_328 ) ) < 0 )
goto V_329;
if ( F_130 ( ( void T_8 * * ) V_38 -> V_301 . V_330 ,
sizeof( struct V_328 ) ,
F_136 ( struct V_328 ) ) < 0 )
goto V_331;
if ( F_130 ( ( void T_8 * * ) V_38 -> V_301 . V_332 ,
sizeof( struct V_333 ) ,
F_136 ( struct V_333 ) ) < 0 )
goto V_334;
V_38 -> V_301 . V_335 = F_137 ( sizeof( struct V_336 ) ,
V_70 ) ;
if ( ! V_38 -> V_301 . V_335 )
goto V_337;
F_138 ( V_38 ) ;
return 0 ;
V_337:
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_332 ) ;
V_334:
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_330 ) ;
V_331:
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_327 ) ;
V_329:
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_324 ) ;
V_326:
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_321 ) ;
V_323:
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_318 ) ;
V_320:
return - V_317 ;
}
static T_11 void F_139 ( struct V_38 * V_38 )
{
F_9 ( V_38 -> V_301 . V_335 ) ;
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_332 ) ;
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_330 ) ;
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_327 ) ;
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_324 ) ;
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_321 ) ;
F_134 ( ( void T_8 * * ) V_38 -> V_301 . V_318 ) ;
}
static int T_12 F_140 ( void )
{
return F_141 ( & V_338 ) ;
}
static int T_12 F_142 ( void )
{
struct V_252 * V_339 ;
struct V_46 * V_340 ;
struct V_220 * V_341 ;
int V_297 = - V_28 ;
F_143 ( sizeof( struct V_342 ) > sizeof( V_339 -> V_343 ) ) ;
V_344 = F_137 ( 65536 / 8 , V_70 ) ;
if ( ! V_344 )
goto V_31;
V_297 = F_144 ( & V_345 , 1 ) ;
if ( V_297 )
goto V_346;
V_297 = F_144 ( & V_347 , 1 ) ;
if ( V_297 )
goto V_348;
V_297 = F_144 ( & V_349 , 1 ) ;
if ( V_297 )
goto V_350;
V_297 = F_144 ( & V_351 , 1 ) ;
if ( V_297 )
goto V_352;
( void ) F_145 ( & V_353 ) ;
#ifdef F_146
F_147 () ;
#endif
V_345 . V_354 = V_42 . V_355 . V_356 ;
if ( F_148 ( & V_357 , V_358 ) < 0 )
F_149 ( L_9 , V_249 ) ;
if ( F_148 ( & V_359 , V_269 ) < 0 )
F_149 ( L_10 , V_249 ) ;
if ( F_148 ( & V_360 , V_156 ) < 0 )
F_149 ( L_11 , V_249 ) ;
#ifdef F_150
if ( F_148 ( & V_361 , V_362 ) < 0 )
F_149 ( L_12 , V_249 ) ;
#endif
for ( V_341 = & V_226 [ 0 ] ; V_341 < & V_226 [ V_224 ] ; ++ V_341 )
F_151 ( V_341 ) ;
for ( V_340 = V_363 ; V_340 < & V_363 [ V_364 ] ; ++ V_340 )
F_76 ( V_340 ) ;
F_152 () ;
F_153 () ;
F_154 () ;
F_155 () ;
F_156 () ;
F_157 () ;
F_158 () ;
if ( F_159 () < 0 )
F_160 ( L_13 ) ;
#if F_161 ( V_365 )
if ( F_162 () )
F_149 ( L_14 , V_249 ) ;
#endif
if ( F_140 () )
F_149 ( L_15 , V_249 ) ;
F_163 () ;
F_164 () ;
F_165 ( & V_366 ) ;
V_297 = 0 ;
V_31:
return V_297 ;
V_352:
F_166 ( & V_349 ) ;
V_350:
F_166 ( & V_347 ) ;
V_348:
F_166 ( & V_345 ) ;
V_346:
F_9 ( V_344 ) ;
goto V_31;
}
static int T_12 F_163 ( void )
{
int V_297 = 0 ;
if ( F_167 () )
goto V_367;
if ( F_168 () )
goto V_368;
if ( F_169 () )
goto V_369;
if ( F_170 () )
goto V_370;
if ( F_171 () )
goto V_371;
V_31:
return V_297 ;
V_371:
F_172 () ;
V_370:
F_173 () ;
V_369:
F_174 () ;
V_368:
F_175 () ;
V_367:
V_297 = - V_317 ;
goto V_31;
}
static int T_12 F_163 ( void )
{
return 0 ;
}
