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
static int F_22 ( struct V_43 * V_43 , struct V_24 * V_1 , int V_44 ,
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
V_1 -> V_29 = V_30 ;
V_53:
V_27 = - V_54 ;
F_23 () ;
F_24 (answer, &inetsw[sock->type], list) {
V_27 = 0 ;
if ( V_44 == V_47 -> V_44 ) {
if ( V_44 != V_55 )
break;
} else {
if ( V_55 == V_44 ) {
V_44 = V_47 -> V_44 ;
break;
}
if ( V_55 == V_47 -> V_44 )
break;
}
V_27 = - V_56 ;
}
if ( F_25 ( V_27 ) ) {
if ( V_52 < 2 ) {
F_26 () ;
if ( ++ V_52 == 1 )
F_27 ( L_3 ,
V_57 , V_44 , V_1 -> type ) ;
else
F_27 ( L_4 ,
V_57 , V_44 ) ;
goto V_53;
} else
goto V_58;
}
V_27 = - V_59 ;
if ( V_1 -> type == V_60 && ! V_45 &&
! F_28 ( V_43 -> V_61 , V_62 ) )
goto V_58;
V_1 -> V_63 = V_47 -> V_63 ;
V_49 = V_47 -> V_64 ;
V_51 = V_47 -> V_65 ;
V_50 = V_47 -> V_66 ;
F_26 () ;
F_7 ( V_49 -> V_67 == NULL ) ;
V_27 = - V_68 ;
V_2 = F_29 ( V_43 , V_57 , V_69 , V_49 ) ;
if ( V_2 == NULL )
goto V_31;
V_27 = 0 ;
V_2 -> V_70 = V_51 ;
if ( V_71 & V_50 )
V_2 -> V_72 = V_73 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_74 = ( V_75 & V_50 ) != 0 ;
V_4 -> V_76 = 0 ;
if ( V_60 == V_1 -> type ) {
V_4 -> V_19 = V_44 ;
if ( V_77 == V_44 )
V_4 -> V_78 = 1 ;
}
if ( V_43 -> V_79 . V_80 )
V_4 -> V_81 = V_82 ;
else
V_4 -> V_81 = V_83 ;
V_4 -> V_84 = 0 ;
F_30 ( V_1 , V_2 ) ;
V_2 -> V_85 = F_1 ;
V_2 -> V_86 = V_44 ;
V_2 -> V_87 = V_2 -> V_20 -> V_88 ;
V_4 -> V_89 = - 1 ;
V_4 -> V_90 = 1 ;
V_4 -> V_91 = 1 ;
V_4 -> V_92 = 1 ;
V_4 -> V_93 = 0 ;
V_4 -> V_94 = NULL ;
V_4 -> V_95 = 0 ;
F_31 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_2 -> V_20 -> V_96 ( V_2 ) ;
}
if ( V_2 -> V_20 -> V_97 ) {
V_27 = V_2 -> V_20 -> V_97 ( V_2 ) ;
if ( V_27 )
F_32 ( V_2 ) ;
}
V_31:
return V_27 ;
V_58:
F_26 () ;
goto V_31;
}
int F_33 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_98 ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
V_98 = 0 ;
if ( F_6 ( V_2 , V_99 ) &&
! ( V_100 -> V_66 & V_101 ) )
V_98 = V_2 -> V_102 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_103 ( V_2 , V_98 ) ;
}
return 0 ;
}
int F_36 ( struct V_24 * V_1 , struct V_104 * V_105 , int V_106 )
{
struct V_107 * V_108 = (struct V_107 * ) V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_43 = F_37 ( V_2 ) ;
unsigned short V_109 ;
int V_110 ;
int V_27 ;
if ( V_2 -> V_20 -> V_111 ) {
V_27 = V_2 -> V_20 -> V_111 ( V_2 , V_105 , V_106 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_106 < sizeof( struct V_107 ) )
goto V_31;
if ( V_108 -> V_112 != V_113 ) {
V_27 = - V_114 ;
if ( V_108 -> V_112 != V_115 ||
V_108 -> V_116 . V_117 != F_38 ( V_118 ) )
goto V_31;
}
V_110 = F_39 ( V_43 , V_108 -> V_116 . V_117 ) ;
V_27 = - V_119 ;
if ( ! V_120 &&
! ( V_4 -> V_121 || V_4 -> V_122 ) &&
V_108 -> V_116 . V_117 != F_38 ( V_118 ) &&
V_110 != V_123 &&
V_110 != V_124 &&
V_110 != V_125 )
goto V_31;
V_109 = F_40 ( V_108 -> V_126 ) ;
V_27 = - V_127 ;
if ( V_109 && V_109 < V_128 &&
! F_28 ( V_43 -> V_61 , V_129 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_130;
V_4 -> V_131 = V_4 -> V_132 = V_108 -> V_116 . V_117 ;
if ( V_110 == V_124 || V_110 == V_125 )
V_4 -> V_132 = 0 ;
if ( V_2 -> V_20 -> V_21 ( V_2 , V_109 ) ) {
V_4 -> V_132 = V_4 -> V_131 = 0 ;
V_27 = - V_133 ;
goto V_130;
}
if ( V_4 -> V_131 )
V_2 -> V_134 |= V_135 ;
if ( V_109 )
V_2 -> V_134 |= V_136 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_137 = 0 ;
V_4 -> V_138 = 0 ;
F_41 ( V_2 ) ;
V_27 = 0 ;
V_130:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_42 ( struct V_24 * V_1 , struct V_104 * V_105 ,
int V_106 , int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_106 < sizeof( V_105 -> V_139 ) )
return - V_28 ;
if ( V_105 -> V_139 == V_115 )
return V_2 -> V_20 -> V_140 ( V_2 , V_66 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_141 ( V_2 , V_105 , V_106 ) ;
}
static long F_43 ( struct V_1 * V_2 , long V_142 , int V_143 )
{
F_44 ( V_144 ) ;
F_45 ( F_46 ( V_2 ) , & V_144 , V_145 ) ;
V_2 -> V_146 += V_143 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_147 | V_148 ) ) {
F_16 ( V_2 ) ;
V_142 = F_47 ( V_142 ) ;
F_15 ( V_2 ) ;
if ( F_48 ( V_100 ) || ! V_142 )
break;
F_45 ( F_46 ( V_2 ) , & V_144 , V_145 ) ;
}
F_49 ( F_46 ( V_2 ) , & V_144 ) ;
V_2 -> V_146 -= V_143 ;
return V_142 ;
}
int F_50 ( struct V_24 * V_1 , struct V_104 * V_105 ,
int V_106 , int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_142 ;
if ( V_106 < sizeof( V_105 -> V_139 ) )
return - V_28 ;
if ( V_105 -> V_139 == V_115 ) {
V_27 = V_2 -> V_20 -> V_140 ( V_2 , V_66 ) ;
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
V_27 = V_2 -> V_20 -> V_141 ( V_2 , V_105 , V_106 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_152 ;
V_27 = - V_154 ;
break;
}
V_142 = F_51 ( V_2 , V_66 & V_155 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_147 | V_148 ) ) {
int V_143 = ( V_2 -> V_86 == V_156 ) &&
F_52 ( V_2 ) -> V_157 &&
F_52 ( V_2 ) -> V_157 -> V_158 ? 1 : 0 ;
if ( ! V_142 || ! F_43 ( V_2 , V_142 , V_143 ) )
goto V_31;
V_27 = F_53 ( V_142 ) ;
if ( F_48 ( V_100 ) )
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
if ( V_2 -> V_20 -> V_140 ( V_2 , V_66 ) )
V_1 -> V_29 = V_149 ;
goto V_31;
}
int F_54 ( struct V_24 * V_1 , struct V_104 * V_105 ,
int V_106 , int V_66 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_50 ( V_1 , V_105 , V_106 , V_66 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_55 ( struct V_24 * V_1 , struct V_24 * V_161 , int V_66 )
{
struct V_1 * V_162 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_163 = V_162 -> V_20 -> V_164 ( V_162 , V_66 , & V_27 ) ;
if ( ! V_163 )
goto V_165;
F_15 ( V_163 ) ;
F_56 ( V_163 ) ;
F_7 ( ! ( ( 1 << V_163 -> V_9 ) &
( V_166 | V_148 |
V_167 | V_32 ) ) ) ;
F_57 ( V_163 , V_161 ) ;
V_161 -> V_29 = V_150 ;
V_27 = 0 ;
F_16 ( V_163 ) ;
V_165:
return V_27 ;
}
int F_58 ( struct V_24 * V_1 , struct V_104 * V_105 ,
int * V_168 , int V_169 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_59 ( struct V_107 * , sin , V_105 ) ;
sin -> V_112 = V_113 ;
if ( V_169 ) {
if ( ! V_4 -> V_138 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_147 ) ) &&
V_169 == 1 ) )
return - V_170 ;
sin -> V_126 = V_4 -> V_138 ;
sin -> V_116 . V_117 = V_4 -> V_137 ;
} else {
T_1 V_108 = V_4 -> V_131 ;
if ( ! V_108 )
V_108 = V_4 -> V_132 ;
sin -> V_126 = V_4 -> V_23 ;
sin -> V_116 . V_117 = V_108 ;
}
memset ( sin -> V_171 , 0 , sizeof( sin -> V_171 ) ) ;
* V_168 = sizeof( * sin ) ;
return 0 ;
}
int F_60 ( struct V_172 * V_173 , struct V_24 * V_1 , struct V_174 * V_175 ,
T_2 V_176 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_56 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_177 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_178 ( V_173 , V_2 , V_175 , V_176 ) ;
}
T_3 F_61 ( struct V_24 * V_1 , struct V_179 * V_179 , int V_180 ,
T_2 V_176 , int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_56 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_177 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_181 )
return V_2 -> V_20 -> V_181 ( V_2 , V_179 , V_180 , V_176 , V_66 ) ;
return F_62 ( V_1 , V_179 , V_180 , V_176 , V_66 ) ;
}
int F_63 ( struct V_172 * V_173 , struct V_24 * V_1 , struct V_174 * V_175 ,
T_2 V_176 , int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_106 = 0 ;
int V_27 ;
F_56 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_182 ( V_173 , V_2 , V_175 , V_176 , V_66 & V_183 ,
V_66 & ~ V_183 , & V_106 ) ;
if ( V_27 >= 0 )
V_175 -> V_184 = V_106 ;
return V_27 ;
}
int F_64 ( struct V_24 * V_1 , int V_185 )
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
int F_65 ( struct V_24 * V_1 , unsigned int V_192 , unsigned long V_193 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_43 * V_43 = F_37 ( V_2 ) ;
switch ( V_192 ) {
case V_194 :
V_27 = F_66 ( V_2 , (struct V_195 V_196 * ) V_193 ) ;
break;
case V_197 :
V_27 = F_67 ( V_2 , (struct V_198 V_196 * ) V_193 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
V_27 = F_68 ( V_43 , V_192 , ( void V_196 * ) V_193 ) ;
break;
case V_202 :
case V_203 :
case V_204 :
V_27 = F_69 ( V_43 , V_192 , ( void V_196 * ) V_193 ) ;
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
V_27 = F_70 ( V_43 , V_192 , ( void V_196 * ) V_193 ) ;
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
static int F_71 ( struct V_24 * V_1 , unsigned int V_192 , unsigned long V_193 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_217 ;
if ( V_2 -> V_20 -> V_218 )
V_27 = V_2 -> V_20 -> V_218 ( V_2 , V_192 , V_193 ) ;
return V_27 ;
}
void F_72 ( struct V_46 * V_219 )
{
struct V_220 * V_221 ;
struct V_46 * V_47 ;
int V_44 = V_219 -> V_44 ;
struct V_220 * V_222 ;
F_73 ( & V_223 ) ;
if ( V_219 -> type >= V_224 )
goto V_225;
V_47 = NULL ;
V_222 = & V_226 [ V_219 -> type ] ;
F_74 (lh, &inetsw[p->type]) {
V_47 = F_75 ( V_221 , struct V_46 , V_227 ) ;
if ( V_228 & V_47 -> V_66 ) {
if ( V_44 == V_47 -> V_44 )
break;
V_222 = V_221 ;
}
V_47 = NULL ;
}
if ( V_47 )
goto V_229;
F_76 ( & V_219 -> V_227 , V_222 ) ;
V_31:
F_77 ( & V_223 ) ;
return;
V_229:
F_5 ( L_5 , V_44 ) ;
goto V_31;
V_225:
F_5 ( L_6 ,
V_219 -> type ) ;
goto V_31;
}
void F_78 ( struct V_46 * V_219 )
{
if ( V_228 & V_219 -> V_66 ) {
F_5 ( L_7 ,
V_219 -> V_44 ) ;
} else {
F_73 ( & V_223 ) ;
F_79 ( & V_219 -> V_227 ) ;
F_77 ( & V_223 ) ;
F_80 () ;
}
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_230 = V_4 -> V_132 ;
T_1 V_231 = V_4 -> V_137 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
T_1 V_236 ;
struct V_237 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_82 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_238 . V_239 )
V_231 = V_16 -> V_238 . V_240 ;
V_233 = & V_4 -> V_241 . V_242 . V_243 . V_244 ;
V_235 = F_83 ( V_233 , V_231 , 0 , F_84 ( V_2 ) ,
V_2 -> V_245 , V_2 -> V_86 ,
V_4 -> V_23 , V_4 -> V_138 , V_2 ) ;
if ( F_85 ( V_235 ) )
return F_86 ( V_235 ) ;
F_87 ( V_2 , & V_235 -> V_246 ) ;
V_236 = V_233 -> V_247 ;
if ( V_236 == V_230 )
return 0 ;
if ( V_248 > 1 ) {
F_88 ( L_8 ,
V_249 , & V_230 , & V_236 ) ;
}
V_4 -> V_132 = V_4 -> V_131 = V_236 ;
F_89 ( V_2 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_234 * V_235 = (struct V_234 * ) F_91 ( V_2 , 0 ) ;
T_1 V_231 ;
struct V_237 * V_16 ;
struct V_232 * V_233 ;
int V_27 ;
if ( V_235 )
return 0 ;
F_23 () ;
V_16 = F_92 ( V_4 -> V_16 ) ;
V_231 = V_4 -> V_137 ;
if ( V_16 && V_16 -> V_238 . V_239 )
V_231 = V_16 -> V_238 . V_240 ;
F_26 () ;
V_233 = & V_4 -> V_241 . V_242 . V_243 . V_244 ;
V_235 = F_93 ( F_37 ( V_2 ) , V_233 , V_2 , V_231 , V_4 -> V_132 ,
V_4 -> V_138 , V_4 -> V_23 ,
V_2 -> V_86 , F_84 ( V_2 ) ,
V_2 -> V_245 ) ;
if ( ! F_85 ( V_235 ) ) {
V_27 = 0 ;
F_87 ( V_2 , & V_235 -> V_246 ) ;
} else {
V_27 = F_86 ( V_235 ) ;
V_2 -> V_250 = 0 ;
if ( ! V_248 ||
V_2 -> V_9 != V_190 ||
( V_2 -> V_134 & V_135 ) ||
( V_27 = F_81 ( V_2 ) ) != 0 )
V_2 -> V_251 = - V_27 ;
}
return V_27 ;
}
static int F_94 ( struct V_252 * V_253 )
{
const struct V_254 * V_63 ;
const struct V_255 * V_256 ;
int V_48 ;
int V_257 ;
int V_27 = - V_28 ;
if ( F_25 ( ! F_95 ( V_253 , sizeof( * V_256 ) ) ) )
goto V_31;
V_256 = F_96 ( V_253 ) ;
V_257 = V_256 -> V_257 * 4 ;
if ( V_257 < sizeof( * V_256 ) )
goto V_31;
V_48 = V_256 -> V_44 ;
if ( F_25 ( ! F_95 ( V_253 , V_257 ) ) )
goto V_31;
F_97 ( V_253 , V_257 ) ;
F_98 ( V_253 ) ;
V_27 = - V_56 ;
V_63 = F_92 ( V_258 [ V_48 ] ) ;
if ( F_99 ( V_63 && V_63 -> V_259 . V_260 ) )
V_27 = V_63 -> V_259 . V_260 ( V_253 ) ;
V_31:
return V_27 ;
}
static struct V_252 * F_100 ( struct V_252 * V_253 ,
T_4 V_261 )
{
struct V_252 * V_262 = F_101 ( - V_28 ) ;
const struct V_254 * V_63 ;
unsigned int V_180 = 0 ;
bool V_263 , V_264 ;
struct V_255 * V_256 ;
int V_48 ;
int V_265 ;
int V_257 ;
int V_266 ;
if ( F_25 ( F_102 ( V_253 ) -> V_267 &
~ ( V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
V_275 |
V_276 |
V_277 |
0 ) ) )
goto V_31;
F_103 ( V_253 ) ;
V_265 = F_104 ( V_253 ) - F_105 ( V_253 ) ;
if ( F_25 ( ! F_95 ( V_253 , sizeof( * V_256 ) ) ) )
goto V_31;
V_256 = F_96 ( V_253 ) ;
V_257 = V_256 -> V_257 * 4 ;
if ( V_257 < sizeof( * V_256 ) )
goto V_31;
V_266 = F_40 ( V_256 -> V_266 ) ;
V_48 = V_256 -> V_44 ;
if ( F_25 ( ! F_95 ( V_253 , V_257 ) ) )
goto V_31;
F_97 ( V_253 , V_257 ) ;
V_264 = F_106 ( V_253 ) -> V_278 > 0 ;
if ( V_264 )
V_261 = V_253 -> V_279 -> V_280 & F_107 ( V_253 ) ;
F_106 ( V_253 ) -> V_278 += V_257 ;
F_98 ( V_253 ) ;
V_262 = F_101 ( - V_56 ) ;
if ( V_253 -> V_281 &&
F_102 ( V_253 ) -> V_267 & ( V_274 | V_273 ) )
V_263 = V_48 == V_282 && V_264 ;
else
V_263 = V_48 == V_282 && ! V_253 -> V_281 ;
V_63 = F_92 ( V_258 [ V_48 ] ) ;
if ( F_99 ( V_63 && V_63 -> V_259 . V_283 ) )
V_262 = V_63 -> V_259 . V_283 ( V_253 , V_261 ) ;
if ( F_108 ( V_262 ) )
goto V_31;
V_253 = V_262 ;
do {
V_256 = (struct V_255 * ) ( F_105 ( V_253 ) + V_265 ) ;
if ( V_263 ) {
V_256 -> V_266 = F_17 ( V_266 ) ;
V_256 -> V_284 = F_17 ( V_180 >> 3 ) ;
if ( V_253 -> V_285 != NULL )
V_256 -> V_284 |= F_17 ( V_286 ) ;
V_180 += V_253 -> V_287 - V_265 - V_257 ;
} else {
V_256 -> V_266 = F_17 ( V_266 ++ ) ;
}
V_256 -> V_288 = F_17 ( V_253 -> V_287 - V_265 ) ;
F_109 ( V_256 ) ;
if ( V_264 )
F_110 ( V_253 ) ;
V_253 -> V_289 = ( V_290 * ) V_256 - V_253 -> V_291 ;
} while ( ( V_253 = V_253 -> V_285 ) );
V_31:
return V_262 ;
}
static struct V_252 * * F_111 ( struct V_252 * * V_291 ,
struct V_252 * V_253 )
{
const struct V_254 * V_63 ;
struct V_252 * * V_292 = NULL ;
struct V_252 * V_219 ;
const struct V_255 * V_256 ;
unsigned int V_293 ;
unsigned int V_294 ;
unsigned int V_266 ;
int V_295 = 1 ;
int V_48 ;
V_294 = F_112 ( V_253 ) ;
V_293 = V_294 + sizeof( * V_256 ) ;
V_256 = F_113 ( V_253 , V_294 ) ;
if ( F_114 ( V_253 , V_293 ) ) {
V_256 = F_115 ( V_253 , V_293 , V_294 ) ;
if ( F_25 ( ! V_256 ) )
goto V_31;
}
V_48 = V_256 -> V_44 ;
F_23 () ;
V_63 = F_92 ( V_258 [ V_48 ] ) ;
if ( ! V_63 || ! V_63 -> V_259 . V_296 )
goto V_297;
if ( * ( V_290 * ) V_256 != 0x45 )
goto V_297;
if ( F_25 ( F_116 ( ( V_290 * ) V_256 , 5 ) ) )
goto V_297;
V_266 = F_117 ( * ( T_1 * ) & V_256 -> V_266 ) ;
V_295 = ( V_298 ) ( ( F_117 ( * ( T_1 * ) V_256 ) ^ F_118 ( V_253 ) ) | ( V_266 & ~ V_299 ) ) ;
V_266 >>= 16 ;
for ( V_219 = * V_291 ; V_219 ; V_219 = V_219 -> V_285 ) {
struct V_255 * V_300 ;
if ( ! F_119 ( V_219 ) -> V_301 )
continue;
V_300 = (struct V_255 * ) ( V_219 -> V_158 + V_294 ) ;
if ( ( V_256 -> V_44 ^ V_300 -> V_44 ) |
( ( V_302 V_303 ) V_256 -> V_247 ^ ( V_302 V_303 ) V_300 -> V_247 ) |
( ( V_302 V_303 ) V_256 -> V_231 ^ ( V_302 V_303 ) V_300 -> V_231 ) ) {
F_119 ( V_219 ) -> V_301 = 0 ;
continue;
}
F_119 ( V_219 ) -> V_295 |=
( V_256 -> V_304 ^ V_300 -> V_304 ) |
( V_256 -> V_305 ^ V_300 -> V_305 ) |
( ( V_256 -> V_284 ^ V_300 -> V_284 ) & F_17 ( V_299 ) ) ;
F_119 ( V_219 ) -> V_306 =
( ( V_298 ) ( F_40 ( V_300 -> V_266 ) + F_119 ( V_219 ) -> V_307 ) ^ V_266 ) ;
F_119 ( V_219 ) -> V_295 |= V_295 ;
}
F_119 ( V_253 ) -> V_295 |= V_295 ;
F_120 ( V_253 , V_294 ) ;
F_121 ( V_253 , sizeof( * V_256 ) ) ;
F_122 ( V_253 , F_112 ( V_253 ) ) ;
V_292 = V_63 -> V_259 . V_296 ( V_291 , V_253 ) ;
V_297:
F_26 () ;
V_31:
F_119 ( V_253 ) -> V_295 |= V_295 ;
return V_292 ;
}
static int F_123 ( struct V_252 * V_253 , int V_265 )
{
T_5 V_308 = F_17 ( V_253 -> V_287 - V_265 ) ;
struct V_255 * V_256 = (struct V_255 * ) ( V_253 -> V_158 + V_265 ) ;
const struct V_254 * V_63 ;
int V_48 = V_256 -> V_44 ;
int V_27 = - V_309 ;
F_124 ( & V_256 -> V_310 , V_256 -> V_288 , V_308 ) ;
V_256 -> V_288 = V_308 ;
F_23 () ;
V_63 = F_92 ( V_258 [ V_48 ] ) ;
if ( F_7 ( ! V_63 || ! V_63 -> V_259 . V_311 ) )
goto V_297;
V_27 = V_63 -> V_259 . V_311 ( V_253 , V_265 + sizeof( * V_256 ) ) ;
V_297:
F_26 () ;
return V_27 ;
}
int F_125 ( struct V_1 * * V_2 , unsigned short V_312 ,
unsigned short type , unsigned char V_44 ,
struct V_43 * V_43 )
{
struct V_24 * V_1 ;
int V_313 = F_126 ( V_312 , type , V_44 , & V_1 ) ;
if ( V_313 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_314 = V_315 ;
( * V_2 ) -> V_20 -> V_316 ( * V_2 ) ;
F_127 ( * V_2 , V_43 ) ;
}
return V_313 ;
}
unsigned long F_128 ( void T_6 * V_317 [] , int V_318 )
{
unsigned long V_319 = 0 ;
int V_320 , V_321 ;
F_129 (i) {
for ( V_321 = 0 ; V_321 < V_322 ; V_321 ++ )
V_319 += * ( ( ( unsigned long * ) F_130 ( V_317 [ V_321 ] , V_320 ) ) + V_318 ) ;
}
return V_319 ;
}
T_7 F_131 ( void T_6 * V_317 [] , int V_318 , T_2 V_323 )
{
T_7 V_319 = 0 ;
int V_324 ;
F_129 (cpu) {
void * V_325 ;
struct V_326 * V_327 ;
T_7 V_328 ;
unsigned int V_329 ;
V_325 = F_130 ( V_317 [ 0 ] , V_324 ) ;
V_327 = (struct V_326 * ) ( V_325 + V_323 ) ;
do {
V_329 = F_132 ( V_327 ) ;
V_328 = * ( ( ( T_7 * ) V_325 ) + V_318 ) ;
} while ( F_133 ( V_327 , V_329 ) );
V_319 += V_328 ;
}
return V_319 ;
}
int F_134 ( void T_6 * V_330 [ 2 ] , T_2 V_331 , T_2 V_332 )
{
F_135 ( V_330 == NULL ) ;
V_330 [ 0 ] = F_136 ( V_331 , V_332 ) ;
if ( ! V_330 [ 0 ] )
return - V_333 ;
#if V_322 == 2
V_330 [ 1 ] = F_136 ( V_331 , V_332 ) ;
if ( ! V_330 [ 1 ] ) {
F_137 ( V_330 [ 0 ] ) ;
V_330 [ 0 ] = NULL ;
return - V_333 ;
}
#endif
return 0 ;
}
static T_8 int F_138 ( struct V_43 * V_43 )
{
int V_320 ;
if ( F_134 ( ( void T_6 * * ) V_43 -> V_317 . V_334 ,
sizeof( struct V_335 ) ,
F_139 ( struct V_335 ) ) < 0 )
goto V_336;
if ( F_134 ( ( void T_6 * * ) V_43 -> V_317 . V_337 ,
sizeof( struct V_338 ) ,
F_139 ( struct V_338 ) ) < 0 )
goto V_339;
F_129 (i) {
struct V_338 * V_340 ;
V_340 = F_130 ( V_43 -> V_317 . V_337 [ 0 ] , V_320 ) ;
F_140 ( & V_340 -> V_327 ) ;
#if V_322 == 2
V_340 = F_130 ( V_43 -> V_317 . V_337 [ 1 ] , V_320 ) ;
F_140 ( & V_340 -> V_327 ) ;
#endif
}
if ( F_134 ( ( void T_6 * * ) V_43 -> V_317 . V_341 ,
sizeof( struct V_342 ) ,
F_139 ( struct V_342 ) ) < 0 )
goto V_343;
if ( F_134 ( ( void T_6 * * ) V_43 -> V_317 . V_344 ,
sizeof( struct V_345 ) ,
F_139 ( struct V_345 ) ) < 0 )
goto V_346;
if ( F_134 ( ( void T_6 * * ) V_43 -> V_317 . V_347 ,
sizeof( struct V_345 ) ,
F_139 ( struct V_345 ) ) < 0 )
goto V_348;
if ( F_134 ( ( void T_6 * * ) V_43 -> V_317 . V_349 ,
sizeof( struct V_350 ) ,
F_139 ( struct V_350 ) ) < 0 )
goto V_351;
V_43 -> V_317 . V_352 = F_141 ( sizeof( struct V_353 ) ,
V_69 ) ;
if ( ! V_43 -> V_317 . V_352 )
goto V_354;
F_142 ( V_43 ) ;
return 0 ;
V_354:
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_349 ) ;
V_351:
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_347 ) ;
V_348:
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_344 ) ;
V_346:
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_341 ) ;
V_343:
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_337 ) ;
V_339:
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_334 ) ;
V_336:
return - V_333 ;
}
static T_9 void F_144 ( struct V_43 * V_43 )
{
F_9 ( V_43 -> V_317 . V_352 ) ;
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_349 ) ;
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_347 ) ;
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_344 ) ;
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_341 ) ;
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_337 ) ;
F_143 ( ( void T_6 * * ) V_43 -> V_317 . V_334 ) ;
}
static int T_10 F_145 ( void )
{
return F_146 ( & V_355 ) ;
}
static int T_10 F_147 ( void )
{
if ( F_148 () < 0 )
F_149 ( L_9 , V_249 ) ;
if ( F_150 () < 0 )
F_149 ( L_10 , V_249 ) ;
F_151 ( & V_356 ) ;
F_152 ( & V_357 , V_358 ) ;
return 0 ;
}
static int T_10 F_153 ( void )
{
struct V_46 * V_359 ;
struct V_220 * V_360 ;
int V_313 = - V_28 ;
F_154 ( sizeof( struct V_361 ) > F_155 ( struct V_252 , V_362 ) ) ;
V_363 = F_141 ( 65536 / 8 , V_69 ) ;
if ( ! V_363 )
goto V_31;
V_313 = F_156 ( & V_364 , 1 ) ;
if ( V_313 )
goto V_365;
V_313 = F_156 ( & V_366 , 1 ) ;
if ( V_313 )
goto V_367;
V_313 = F_156 ( & V_368 , 1 ) ;
if ( V_313 )
goto V_369;
V_313 = F_156 ( & V_370 , 1 ) ;
if ( V_313 )
goto V_371;
( void ) F_157 ( & V_372 ) ;
#ifdef F_158
F_159 () ;
#endif
if ( F_160 ( & V_373 , V_374 ) < 0 )
F_149 ( L_11 , V_249 ) ;
if ( F_160 ( & V_375 , V_282 ) < 0 )
F_149 ( L_12 , V_249 ) ;
if ( F_160 ( & V_376 , V_156 ) < 0 )
F_149 ( L_13 , V_249 ) ;
#ifdef F_161
if ( F_160 ( & V_377 , V_378 ) < 0 )
F_149 ( L_14 , V_249 ) ;
#endif
for ( V_360 = & V_226 [ 0 ] ; V_360 < & V_226 [ V_224 ] ; ++ V_360 )
F_162 ( V_360 ) ;
for ( V_359 = V_379 ; V_359 < & V_379 [ V_380 ] ; ++ V_359 )
F_72 ( V_359 ) ;
F_163 () ;
F_164 () ;
F_165 () ;
F_166 () ;
F_167 () ;
F_168 () ;
F_169 () ;
if ( F_170 () < 0 )
F_171 ( L_15 ) ;
#if F_172 ( V_381 )
if ( F_173 () )
F_149 ( L_16 , V_249 ) ;
#endif
if ( F_145 () )
F_149 ( L_17 , V_249 ) ;
F_174 () ;
F_175 () ;
F_176 ( & V_382 ) ;
V_313 = 0 ;
V_31:
return V_313 ;
V_371:
F_177 ( & V_368 ) ;
V_369:
F_177 ( & V_366 ) ;
V_367:
F_177 ( & V_364 ) ;
V_365:
F_9 ( V_363 ) ;
goto V_31;
}
static int T_10 F_174 ( void )
{
int V_313 = 0 ;
if ( F_178 () )
goto V_383;
if ( F_179 () )
goto V_384;
if ( F_180 () )
goto V_385;
if ( F_181 () )
goto V_386;
if ( F_182 () )
goto V_387;
V_31:
return V_313 ;
V_387:
F_183 () ;
V_386:
F_184 () ;
V_385:
F_185 () ;
V_384:
F_186 () ;
V_383:
V_313 = - V_333 ;
goto V_31;
}
static int T_10 F_174 ( void )
{
return 0 ;
}
