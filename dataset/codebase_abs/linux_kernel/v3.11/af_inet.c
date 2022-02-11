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
if ( F_24 ( & V_44 , 0 , V_43 ) == 0 ) {
F_23 ( & V_45 , sizeof( V_45 ) ) ;
F_25 () ;
}
}
static int F_26 ( struct V_46 * V_46 , struct V_24 * V_1 , int V_47 ,
int V_48 )
{
struct V_1 * V_2 ;
struct V_49 * V_50 ;
struct V_3 * V_4 ;
struct V_51 * V_52 ;
unsigned char V_53 ;
char V_54 ;
int V_55 = 0 ;
int V_27 ;
if ( F_27 ( ! V_44 ) )
if ( V_1 -> type != V_56 && V_1 -> type != V_57 )
F_22 () ;
V_1 -> V_29 = V_30 ;
V_58:
V_27 = - V_59 ;
F_28 () ;
F_29 (answer, &inetsw[sock->type], list) {
V_27 = 0 ;
if ( V_47 == V_50 -> V_47 ) {
if ( V_47 != V_60 )
break;
} else {
if ( V_60 == V_47 ) {
V_47 = V_50 -> V_47 ;
break;
}
if ( V_60 == V_50 -> V_47 )
break;
}
V_27 = - V_61 ;
}
if ( F_27 ( V_27 ) ) {
if ( V_55 < 2 ) {
F_30 () ;
if ( ++ V_55 == 1 )
F_31 ( L_3 ,
V_62 , V_47 , V_1 -> type ) ;
else
F_31 ( L_4 ,
V_62 , V_47 ) ;
goto V_58;
} else
goto V_63;
}
V_27 = - V_64 ;
if ( V_1 -> type == V_56 && ! V_48 &&
! F_32 ( V_46 -> V_65 , V_66 ) )
goto V_63;
V_1 -> V_67 = V_50 -> V_67 ;
V_52 = V_50 -> V_68 ;
V_54 = V_50 -> V_69 ;
V_53 = V_50 -> V_70 ;
F_30 () ;
F_7 ( V_52 -> V_71 == NULL ) ;
V_27 = - V_72 ;
V_2 = F_33 ( V_46 , V_62 , V_73 , V_52 ) ;
if ( V_2 == NULL )
goto V_31;
V_27 = 0 ;
V_2 -> V_74 = V_54 ;
if ( V_75 & V_53 )
V_2 -> V_76 = V_77 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_78 = ( V_79 & V_53 ) != 0 ;
V_4 -> V_80 = 0 ;
if ( V_56 == V_1 -> type ) {
V_4 -> V_19 = V_47 ;
if ( V_81 == V_47 )
V_4 -> V_82 = 1 ;
}
if ( V_83 . V_84 )
V_4 -> V_85 = V_86 ;
else
V_4 -> V_85 = V_87 ;
V_4 -> V_88 = 0 ;
F_34 ( V_1 , V_2 ) ;
V_2 -> V_89 = F_1 ;
V_2 -> V_90 = V_47 ;
V_2 -> V_91 = V_2 -> V_20 -> V_92 ;
V_4 -> V_93 = - 1 ;
V_4 -> V_94 = 1 ;
V_4 -> V_95 = 1 ;
V_4 -> V_96 = 1 ;
V_4 -> V_97 = 0 ;
V_4 -> V_98 = NULL ;
V_4 -> V_99 = 0 ;
F_35 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_2 -> V_20 -> V_100 ( V_2 ) ;
}
if ( V_2 -> V_20 -> V_101 ) {
V_27 = V_2 -> V_20 -> V_101 ( V_2 ) ;
if ( V_27 )
F_36 ( V_2 ) ;
}
V_31:
return V_27 ;
V_63:
F_30 () ;
goto V_31;
}
int F_37 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_102 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
V_102 = 0 ;
if ( F_6 ( V_2 , V_103 ) &&
! ( V_104 -> V_70 & V_105 ) )
V_102 = V_2 -> V_106 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_107 ( V_2 , V_102 ) ;
}
return 0 ;
}
int F_40 ( struct V_24 * V_1 , struct V_108 * V_109 , int V_110 )
{
struct V_111 * V_112 = (struct V_111 * ) V_109 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_46 * V_46 = F_41 ( V_2 ) ;
unsigned short V_113 ;
int V_114 ;
int V_27 ;
if ( V_2 -> V_20 -> V_115 ) {
V_27 = V_2 -> V_20 -> V_115 ( V_2 , V_109 , V_110 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_110 < sizeof( struct V_111 ) )
goto V_31;
if ( V_112 -> V_116 != V_117 ) {
V_27 = - V_118 ;
if ( V_112 -> V_116 != V_119 ||
V_112 -> V_120 . V_121 != F_42 ( V_122 ) )
goto V_31;
}
V_114 = F_43 ( V_46 , V_112 -> V_120 . V_121 ) ;
V_27 = - V_123 ;
if ( ! V_124 &&
! ( V_4 -> V_125 || V_4 -> V_126 ) &&
V_112 -> V_120 . V_121 != F_42 ( V_122 ) &&
V_114 != V_127 &&
V_114 != V_128 &&
V_114 != V_129 )
goto V_31;
V_113 = F_44 ( V_112 -> V_130 ) ;
V_27 = - V_131 ;
if ( V_113 && V_113 < V_132 &&
! F_32 ( V_46 -> V_65 , V_133 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_134;
V_4 -> V_135 = V_4 -> V_136 = V_112 -> V_120 . V_121 ;
if ( V_114 == V_128 || V_114 == V_129 )
V_4 -> V_136 = 0 ;
if ( V_2 -> V_20 -> V_21 ( V_2 , V_113 ) ) {
V_4 -> V_136 = V_4 -> V_135 = 0 ;
V_27 = - V_137 ;
goto V_134;
}
if ( V_4 -> V_135 )
V_2 -> V_138 |= V_139 ;
if ( V_113 )
V_2 -> V_138 |= V_140 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_141 = 0 ;
V_4 -> V_142 = 0 ;
F_45 ( V_2 ) ;
V_27 = 0 ;
V_134:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_46 ( struct V_24 * V_1 , struct V_108 * V_109 ,
int V_110 , int V_70 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_110 < sizeof( V_109 -> V_143 ) )
return - V_28 ;
if ( V_109 -> V_143 == V_119 )
return V_2 -> V_20 -> V_144 ( V_2 , V_70 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_145 ( V_2 , V_109 , V_110 ) ;
}
static long F_47 ( struct V_1 * V_2 , long V_146 , int V_147 )
{
F_48 ( V_148 ) ;
F_49 ( F_50 ( V_2 ) , & V_148 , V_149 ) ;
V_2 -> V_150 += V_147 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_151 | V_152 ) ) {
F_16 ( V_2 ) ;
V_146 = F_51 ( V_146 ) ;
F_15 ( V_2 ) ;
if ( F_52 ( V_104 ) || ! V_146 )
break;
F_49 ( F_50 ( V_2 ) , & V_148 , V_149 ) ;
}
F_53 ( F_50 ( V_2 ) , & V_148 ) ;
V_2 -> V_150 -= V_147 ;
return V_146 ;
}
int F_54 ( struct V_24 * V_1 , struct V_108 * V_109 ,
int V_110 , int V_70 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_146 ;
if ( V_110 < sizeof( V_109 -> V_143 ) )
return - V_28 ;
if ( V_109 -> V_143 == V_119 ) {
V_27 = V_2 -> V_20 -> V_144 ( V_2 , V_70 ) ;
V_1 -> V_29 = V_27 ? V_153 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_154 :
V_27 = - V_155 ;
goto V_31;
case V_156 :
V_27 = - V_157 ;
break;
case V_30 :
V_27 = - V_155 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_145 ( V_2 , V_109 , V_110 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_156 ;
V_27 = - V_158 ;
break;
}
V_146 = F_55 ( V_2 , V_70 & V_159 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_151 | V_152 ) ) {
int V_147 = ( V_2 -> V_90 == V_160 ) &&
F_56 ( V_2 ) -> V_161 &&
F_56 ( V_2 ) -> V_161 -> V_162 ? 1 : 0 ;
if ( ! V_146 || ! F_47 ( V_2 , V_146 , V_147 ) )
goto V_31;
V_27 = F_57 ( V_146 ) ;
if ( F_52 ( V_104 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_163;
V_1 -> V_29 = V_154 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_163:
V_27 = V_163 ( V_2 ) ? : - V_164 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_144 ( V_2 , V_70 ) )
V_1 -> V_29 = V_153 ;
goto V_31;
}
int F_58 ( struct V_24 * V_1 , struct V_108 * V_109 ,
int V_110 , int V_70 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_54 ( V_1 , V_109 , V_110 , V_70 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_59 ( struct V_24 * V_1 , struct V_24 * V_165 , int V_70 )
{
struct V_1 * V_166 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_167 = V_166 -> V_20 -> V_168 ( V_166 , V_70 , & V_27 ) ;
if ( ! V_167 )
goto V_169;
F_15 ( V_167 ) ;
F_60 ( V_167 ) ;
F_7 ( ! ( ( 1 << V_167 -> V_9 ) &
( V_170 | V_152 |
V_171 | V_32 ) ) ) ;
F_61 ( V_167 , V_165 ) ;
V_165 -> V_29 = V_154 ;
V_27 = 0 ;
F_16 ( V_167 ) ;
V_169:
return V_27 ;
}
int F_62 ( struct V_24 * V_1 , struct V_108 * V_109 ,
int * V_172 , int V_173 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_63 ( struct V_111 * , sin , V_109 ) ;
sin -> V_116 = V_117 ;
if ( V_173 ) {
if ( ! V_4 -> V_142 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_151 ) ) &&
V_173 == 1 ) )
return - V_174 ;
sin -> V_130 = V_4 -> V_142 ;
sin -> V_120 . V_121 = V_4 -> V_141 ;
} else {
T_2 V_112 = V_4 -> V_135 ;
if ( ! V_112 )
V_112 = V_4 -> V_136 ;
sin -> V_130 = V_4 -> V_23 ;
sin -> V_120 . V_121 = V_112 ;
}
memset ( sin -> V_175 , 0 , sizeof( sin -> V_175 ) ) ;
* V_172 = sizeof( * sin ) ;
return 0 ;
}
int F_64 ( struct V_176 * V_177 , struct V_24 * V_1 , struct V_178 * V_179 ,
T_3 V_180 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_60 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_181 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_182 ( V_177 , V_2 , V_179 , V_180 ) ;
}
T_4 F_65 ( struct V_24 * V_1 , struct V_183 * V_183 , int V_184 ,
T_3 V_180 , int V_70 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_60 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_181 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_185 )
return V_2 -> V_20 -> V_185 ( V_2 , V_183 , V_184 , V_180 , V_70 ) ;
return F_66 ( V_1 , V_183 , V_184 , V_180 , V_70 ) ;
}
int F_67 ( struct V_176 * V_177 , struct V_24 * V_1 , struct V_178 * V_179 ,
T_3 V_180 , int V_70 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_110 = 0 ;
int V_27 ;
F_60 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_186 ( V_177 , V_2 , V_179 , V_180 , V_70 & V_187 ,
V_70 & ~ V_187 , & V_110 ) ;
if ( V_27 >= 0 )
V_179 -> V_188 = V_110 ;
return V_27 ;
}
int F_68 ( struct V_24 * V_1 , int V_189 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_189 ++ ;
if ( ( V_189 & ~ V_190 ) || ! V_189 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_156 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_151 | V_152 | V_32 ) )
V_1 -> V_29 = V_153 ;
else
V_1 -> V_29 = V_154 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_174 ;
default:
V_2 -> V_191 |= V_189 ;
if ( V_2 -> V_20 -> V_192 )
V_2 -> V_20 -> V_192 ( V_2 , V_189 ) ;
break;
case V_34 :
if ( ! ( V_189 & V_193 ) )
break;
case V_194 :
V_27 = V_2 -> V_20 -> V_144 ( V_2 , V_159 ) ;
V_1 -> V_29 = V_27 ? V_153 : V_30 ;
break;
}
V_2 -> V_195 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_69 ( struct V_24 * V_1 , unsigned int V_196 , unsigned long V_197 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_46 * V_46 = F_41 ( V_2 ) ;
switch ( V_196 ) {
case V_198 :
V_27 = F_70 ( V_2 , (struct V_199 V_200 * ) V_197 ) ;
break;
case V_201 :
V_27 = F_71 ( V_2 , (struct V_202 V_200 * ) V_197 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
V_27 = F_72 ( V_46 , V_196 , ( void V_200 * ) V_197 ) ;
break;
case V_206 :
case V_207 :
case V_208 :
V_27 = F_73 ( V_46 , V_196 , ( void V_200 * ) V_197 ) ;
break;
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
V_27 = F_74 ( V_46 , V_196 , ( void V_200 * ) V_197 ) ;
break;
default:
if ( V_2 -> V_20 -> V_220 )
V_27 = V_2 -> V_20 -> V_220 ( V_2 , V_196 , V_197 ) ;
else
V_27 = - V_221 ;
break;
}
return V_27 ;
}
static int F_75 ( struct V_24 * V_1 , unsigned int V_196 , unsigned long V_197 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_221 ;
if ( V_2 -> V_20 -> V_222 )
V_27 = V_2 -> V_20 -> V_222 ( V_2 , V_196 , V_197 ) ;
return V_27 ;
}
void F_76 ( struct V_49 * V_223 )
{
struct V_224 * V_225 ;
struct V_49 * V_50 ;
int V_47 = V_223 -> V_47 ;
struct V_224 * V_226 ;
F_77 ( & V_227 ) ;
if ( V_223 -> type >= V_228 )
goto V_229;
V_50 = NULL ;
V_226 = & V_230 [ V_223 -> type ] ;
F_78 (lh, &inetsw[p->type]) {
V_50 = F_79 ( V_225 , struct V_49 , V_231 ) ;
if ( V_232 & V_50 -> V_70 ) {
if ( V_47 == V_50 -> V_47 )
break;
V_226 = V_225 ;
}
V_50 = NULL ;
}
if ( V_50 )
goto V_233;
F_80 ( & V_223 -> V_231 , V_226 ) ;
V_31:
F_81 ( & V_227 ) ;
return;
V_233:
F_5 ( L_5 , V_47 ) ;
goto V_31;
V_229:
F_5 ( L_6 ,
V_223 -> type ) ;
goto V_31;
}
void F_82 ( struct V_49 * V_223 )
{
if ( V_232 & V_223 -> V_70 ) {
F_5 ( L_7 ,
V_223 -> V_47 ) ;
} else {
F_77 ( & V_227 ) ;
F_83 ( & V_223 -> V_231 ) ;
F_81 ( & V_227 ) ;
F_84 () ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_234 = V_4 -> V_136 ;
T_2 V_235 = V_4 -> V_141 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
T_2 V_240 ;
struct V_241 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_86 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_242 . V_243 )
V_235 = V_16 -> V_242 . V_244 ;
V_237 = & V_4 -> V_245 . V_246 . V_247 . V_248 ;
V_239 = F_87 ( V_237 , V_235 , 0 , F_88 ( V_2 ) ,
V_2 -> V_249 , V_2 -> V_90 ,
V_4 -> V_23 , V_4 -> V_142 , V_2 , false ) ;
if ( F_89 ( V_239 ) )
return F_90 ( V_239 ) ;
F_91 ( V_2 , & V_239 -> V_250 ) ;
V_240 = V_237 -> V_251 ;
if ( V_240 == V_234 )
return 0 ;
if ( V_252 > 1 ) {
F_92 ( L_8 ,
V_253 , & V_234 , & V_240 ) ;
}
V_4 -> V_136 = V_4 -> V_135 = V_240 ;
F_93 ( V_2 ) ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_238 * V_239 = (struct V_238 * ) F_95 ( V_2 , 0 ) ;
T_2 V_235 ;
struct V_241 * V_16 ;
struct V_236 * V_237 ;
int V_27 ;
if ( V_239 )
return 0 ;
F_28 () ;
V_16 = F_96 ( V_4 -> V_16 ) ;
V_235 = V_4 -> V_141 ;
if ( V_16 && V_16 -> V_242 . V_243 )
V_235 = V_16 -> V_242 . V_244 ;
F_30 () ;
V_237 = & V_4 -> V_245 . V_246 . V_247 . V_248 ;
V_239 = F_97 ( F_41 ( V_2 ) , V_237 , V_2 , V_235 , V_4 -> V_136 ,
V_4 -> V_142 , V_4 -> V_23 ,
V_2 -> V_90 , F_88 ( V_2 ) ,
V_2 -> V_249 ) ;
if ( ! F_89 ( V_239 ) ) {
V_27 = 0 ;
F_91 ( V_2 , & V_239 -> V_250 ) ;
} else {
V_27 = F_90 ( V_239 ) ;
V_2 -> V_254 = 0 ;
if ( ! V_252 ||
V_2 -> V_9 != V_194 ||
( V_2 -> V_138 & V_139 ) ||
( V_27 = F_85 ( V_2 ) ) != 0 )
V_2 -> V_255 = - V_27 ;
}
return V_27 ;
}
static int F_98 ( struct V_256 * V_257 )
{
const struct V_258 * V_67 ;
const struct V_259 * V_260 ;
int V_51 ;
int V_261 ;
int V_27 = - V_28 ;
if ( F_27 ( ! F_99 ( V_257 , sizeof( * V_260 ) ) ) )
goto V_31;
V_260 = F_100 ( V_257 ) ;
V_261 = V_260 -> V_261 * 4 ;
if ( V_261 < sizeof( * V_260 ) )
goto V_31;
if ( F_27 ( ! F_99 ( V_257 , V_261 ) ) )
goto V_31;
F_101 ( V_257 , V_261 ) ;
F_102 ( V_257 ) ;
V_260 = F_100 ( V_257 ) ;
V_51 = V_260 -> V_47 ;
V_27 = - V_61 ;
F_28 () ;
V_67 = F_96 ( V_262 [ V_51 ] ) ;
if ( F_103 ( V_67 && V_67 -> V_263 . V_264 ) )
V_27 = V_67 -> V_263 . V_264 ( V_257 ) ;
F_30 () ;
V_31:
return V_27 ;
}
static struct V_256 * F_104 ( struct V_256 * V_257 ,
T_5 V_265 )
{
struct V_256 * V_266 = F_105 ( - V_28 ) ;
const struct V_258 * V_67 ;
struct V_259 * V_260 ;
int V_51 ;
int V_261 ;
int V_267 ;
unsigned int V_184 = 0 ;
bool V_268 ;
if ( F_27 ( F_106 ( V_257 ) -> V_269 &
~ ( V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
V_275 |
V_276 |
V_277 |
0 ) ) )
goto V_31;
if ( F_27 ( ! F_99 ( V_257 , sizeof( * V_260 ) ) ) )
goto V_31;
V_260 = F_100 ( V_257 ) ;
V_261 = V_260 -> V_261 * 4 ;
if ( V_261 < sizeof( * V_260 ) )
goto V_31;
if ( F_27 ( ! F_99 ( V_257 , V_261 ) ) )
goto V_31;
V_268 = ! ! V_257 -> V_278 ;
F_101 ( V_257 , V_261 ) ;
F_102 ( V_257 ) ;
V_260 = F_100 ( V_257 ) ;
V_267 = F_44 ( V_260 -> V_267 ) ;
V_51 = V_260 -> V_47 ;
V_266 = F_105 ( - V_61 ) ;
F_28 () ;
V_67 = F_96 ( V_262 [ V_51 ] ) ;
if ( F_103 ( V_67 && V_67 -> V_263 . V_279 ) )
V_266 = V_67 -> V_263 . V_279 ( V_257 , V_265 ) ;
F_30 () ;
if ( F_107 ( V_266 ) )
goto V_31;
V_257 = V_266 ;
do {
V_260 = F_100 ( V_257 ) ;
if ( ! V_268 && V_51 == V_280 ) {
V_260 -> V_267 = F_17 ( V_267 ) ;
V_260 -> V_281 = F_17 ( V_184 >> 3 ) ;
if ( V_257 -> V_282 != NULL )
V_260 -> V_281 |= F_17 ( V_283 ) ;
V_184 += ( V_257 -> V_284 - V_257 -> V_285 - V_260 -> V_261 * 4 ) ;
} else {
V_260 -> V_267 = F_17 ( V_267 ++ ) ;
}
V_260 -> V_286 = F_17 ( V_257 -> V_284 - V_257 -> V_285 ) ;
V_260 -> V_287 = 0 ;
V_260 -> V_287 = F_108 ( F_109 ( V_257 ) , V_260 -> V_261 ) ;
} while ( ( V_257 = V_257 -> V_282 ) );
V_31:
return V_266 ;
}
static struct V_256 * * F_110 ( struct V_256 * * V_288 ,
struct V_256 * V_257 )
{
const struct V_258 * V_67 ;
struct V_256 * * V_289 = NULL ;
struct V_256 * V_223 ;
const struct V_259 * V_260 ;
unsigned int V_290 ;
unsigned int V_291 ;
unsigned int V_267 ;
int V_292 = 1 ;
int V_51 ;
V_291 = F_111 ( V_257 ) ;
V_290 = V_291 + sizeof( * V_260 ) ;
V_260 = F_112 ( V_257 , V_291 ) ;
if ( F_113 ( V_257 , V_290 ) ) {
V_260 = F_114 ( V_257 , V_290 , V_291 ) ;
if ( F_27 ( ! V_260 ) )
goto V_31;
}
V_51 = V_260 -> V_47 ;
F_28 () ;
V_67 = F_96 ( V_262 [ V_51 ] ) ;
if ( ! V_67 || ! V_67 -> V_263 . V_293 )
goto V_294;
if ( * ( V_295 * ) V_260 != 0x45 )
goto V_294;
if ( F_27 ( F_108 ( ( V_295 * ) V_260 , 5 ) ) )
goto V_294;
V_267 = F_115 ( * ( T_2 * ) & V_260 -> V_267 ) ;
V_292 = ( V_296 ) ( ( F_115 ( * ( T_2 * ) V_260 ) ^ F_116 ( V_257 ) ) | ( V_267 & ~ V_297 ) ) ;
V_267 >>= 16 ;
for ( V_223 = * V_288 ; V_223 ; V_223 = V_223 -> V_282 ) {
struct V_259 * V_298 ;
if ( ! F_117 ( V_223 ) -> V_299 )
continue;
V_298 = F_100 ( V_223 ) ;
if ( ( V_260 -> V_47 ^ V_298 -> V_47 ) |
( ( V_300 T_1 ) V_260 -> V_251 ^ ( V_300 T_1 ) V_298 -> V_251 ) |
( ( V_300 T_1 ) V_260 -> V_235 ^ ( V_300 T_1 ) V_298 -> V_235 ) ) {
F_117 ( V_223 ) -> V_299 = 0 ;
continue;
}
F_117 ( V_223 ) -> V_292 |=
( V_260 -> V_301 ^ V_298 -> V_301 ) |
( V_260 -> V_302 ^ V_298 -> V_302 ) |
( V_300 int ) ( ( V_260 -> V_281 ^ V_298 -> V_281 ) & F_17 ( V_297 ) ) |
( ( V_296 ) ( F_44 ( V_298 -> V_267 ) + F_117 ( V_223 ) -> V_303 ) ^ V_267 ) ;
F_117 ( V_223 ) -> V_292 |= V_292 ;
}
F_117 ( V_257 ) -> V_292 |= V_292 ;
F_118 ( V_257 , sizeof( * V_260 ) ) ;
F_119 ( V_257 , F_111 ( V_257 ) ) ;
V_289 = V_67 -> V_263 . V_293 ( V_288 , V_257 ) ;
V_294:
F_30 () ;
V_31:
F_117 ( V_257 ) -> V_292 |= V_292 ;
return V_289 ;
}
static int F_120 ( struct V_256 * V_257 )
{
T_6 V_304 = F_17 ( V_257 -> V_284 - F_121 ( V_257 ) ) ;
struct V_259 * V_260 = F_100 ( V_257 ) ;
const struct V_258 * V_67 ;
int V_51 = V_260 -> V_47 ;
int V_27 = - V_305 ;
F_122 ( & V_260 -> V_287 , V_260 -> V_286 , V_304 ) ;
V_260 -> V_286 = V_304 ;
F_28 () ;
V_67 = F_96 ( V_262 [ V_51 ] ) ;
if ( F_7 ( ! V_67 || ! V_67 -> V_263 . V_306 ) )
goto V_294;
V_27 = V_67 -> V_263 . V_306 ( V_257 ) ;
V_294:
F_30 () ;
return V_27 ;
}
int F_123 ( struct V_1 * * V_2 , unsigned short V_307 ,
unsigned short type , unsigned char V_47 ,
struct V_46 * V_46 )
{
struct V_24 * V_1 ;
int V_308 = F_124 ( V_307 , type , V_47 , & V_1 ) ;
if ( V_308 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_309 = V_310 ;
( * V_2 ) -> V_20 -> V_311 ( * V_2 ) ;
F_125 ( * V_2 , V_46 ) ;
}
return V_308 ;
}
unsigned long F_126 ( void T_7 * V_312 [] , int V_313 )
{
unsigned long V_314 = 0 ;
int V_315 , V_316 ;
F_127 (i) {
for ( V_316 = 0 ; V_316 < V_317 ; V_316 ++ )
V_314 += * ( ( ( unsigned long * ) F_128 ( V_312 [ V_316 ] , V_315 ) ) + V_313 ) ;
}
return V_314 ;
}
T_8 F_129 ( void T_7 * V_312 [] , int V_313 , T_3 V_318 )
{
T_8 V_314 = 0 ;
int V_319 ;
F_127 (cpu) {
void * V_320 ;
struct V_321 * V_322 ;
T_8 V_323 ;
unsigned int V_324 ;
V_320 = F_128 ( V_312 [ 0 ] , V_319 ) ;
V_322 = (struct V_321 * ) ( V_320 + V_318 ) ;
do {
V_324 = F_130 ( V_322 ) ;
V_323 = * ( ( ( T_8 * ) V_320 ) + V_313 ) ;
} while ( F_131 ( V_322 , V_324 ) );
V_314 += V_323 ;
}
return V_314 ;
}
int F_132 ( void T_7 * V_325 [ 2 ] , T_3 V_326 , T_3 V_327 )
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
void F_136 ( void T_7 * V_325 [ V_317 ] )
{
int V_315 ;
F_133 ( V_325 == NULL ) ;
for ( V_315 = 0 ; V_315 < V_317 ; V_315 ++ ) {
F_135 ( V_325 [ V_315 ] ) ;
V_325 [ V_315 ] = NULL ;
}
}
static T_9 int F_137 ( struct V_46 * V_46 )
{
if ( F_132 ( ( void T_7 * * ) V_46 -> V_312 . V_329 ,
sizeof( struct V_330 ) ,
F_138 ( struct V_330 ) ) < 0 )
goto V_331;
if ( F_132 ( ( void T_7 * * ) V_46 -> V_312 . V_332 ,
sizeof( struct V_333 ) ,
F_138 ( struct V_333 ) ) < 0 )
goto V_334;
if ( F_132 ( ( void T_7 * * ) V_46 -> V_312 . V_335 ,
sizeof( struct V_336 ) ,
F_138 ( struct V_336 ) ) < 0 )
goto V_337;
if ( F_132 ( ( void T_7 * * ) V_46 -> V_312 . V_338 ,
sizeof( struct V_339 ) ,
F_138 ( struct V_339 ) ) < 0 )
goto V_340;
if ( F_132 ( ( void T_7 * * ) V_46 -> V_312 . V_341 ,
sizeof( struct V_339 ) ,
F_138 ( struct V_339 ) ) < 0 )
goto V_342;
if ( F_132 ( ( void T_7 * * ) V_46 -> V_312 . V_343 ,
sizeof( struct V_344 ) ,
F_138 ( struct V_344 ) ) < 0 )
goto V_345;
V_46 -> V_312 . V_346 = F_139 ( sizeof( struct V_347 ) ,
V_73 ) ;
if ( ! V_46 -> V_312 . V_346 )
goto V_348;
F_140 ( V_46 ) ;
return 0 ;
V_348:
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_343 ) ;
V_345:
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_341 ) ;
V_342:
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_338 ) ;
V_340:
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_335 ) ;
V_337:
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_332 ) ;
V_334:
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_329 ) ;
V_331:
return - V_328 ;
}
static T_10 void F_141 ( struct V_46 * V_46 )
{
F_9 ( V_46 -> V_312 . V_346 ) ;
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_343 ) ;
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_341 ) ;
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_338 ) ;
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_335 ) ;
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_332 ) ;
F_136 ( ( void T_7 * * ) V_46 -> V_312 . V_329 ) ;
}
static int T_11 F_142 ( void )
{
return F_143 ( & V_349 ) ;
}
static int T_11 F_144 ( void )
{
if ( F_145 () < 0 )
F_146 ( L_9 , V_253 ) ;
if ( F_147 () < 0 )
F_146 ( L_10 , V_253 ) ;
F_148 ( & V_350 ) ;
return 0 ;
}
static int T_11 F_149 ( void )
{
struct V_49 * V_351 ;
struct V_224 * V_352 ;
int V_308 = - V_28 ;
F_150 ( sizeof( struct V_353 ) > F_151 ( struct V_256 , V_354 ) ) ;
V_355 = F_139 ( 65536 / 8 , V_73 ) ;
if ( ! V_355 )
goto V_31;
V_308 = F_152 ( & V_356 , 1 ) ;
if ( V_308 )
goto V_357;
V_308 = F_152 ( & V_358 , 1 ) ;
if ( V_308 )
goto V_359;
V_308 = F_152 ( & V_360 , 1 ) ;
if ( V_308 )
goto V_361;
V_308 = F_152 ( & V_362 , 1 ) ;
if ( V_308 )
goto V_363;
( void ) F_153 ( & V_364 ) ;
#ifdef F_154
F_155 () ;
#endif
V_356 . V_365 = V_366 . V_367 . V_368 ;
if ( F_156 ( & V_369 , V_370 ) < 0 )
F_146 ( L_11 , V_253 ) ;
if ( F_156 ( & V_371 , V_280 ) < 0 )
F_146 ( L_12 , V_253 ) ;
if ( F_156 ( & V_372 , V_160 ) < 0 )
F_146 ( L_13 , V_253 ) ;
#ifdef F_157
if ( F_156 ( & V_373 , V_374 ) < 0 )
F_146 ( L_14 , V_253 ) ;
#endif
for ( V_352 = & V_230 [ 0 ] ; V_352 < & V_230 [ V_228 ] ; ++ V_352 )
F_158 ( V_352 ) ;
for ( V_351 = V_375 ; V_351 < & V_375 [ V_376 ] ; ++ V_351 )
F_76 ( V_351 ) ;
F_159 () ;
F_160 () ;
F_161 () ;
F_162 () ;
F_163 () ;
F_164 () ;
F_165 () ;
if ( F_166 () < 0 )
F_167 ( L_15 ) ;
#if F_168 ( V_377 )
if ( F_169 () )
F_146 ( L_16 , V_253 ) ;
#endif
if ( F_142 () )
F_146 ( L_17 , V_253 ) ;
F_170 () ;
F_171 () ;
F_172 ( & V_378 ) ;
V_308 = 0 ;
V_31:
return V_308 ;
V_363:
F_173 ( & V_360 ) ;
V_361:
F_173 ( & V_358 ) ;
V_359:
F_173 ( & V_356 ) ;
V_357:
F_9 ( V_355 ) ;
goto V_31;
}
static int T_11 F_170 ( void )
{
int V_308 = 0 ;
if ( F_174 () )
goto V_379;
if ( F_175 () )
goto V_380;
if ( F_176 () )
goto V_381;
if ( F_177 () )
goto V_382;
if ( F_178 () )
goto V_383;
V_31:
return V_308 ;
V_383:
F_179 () ;
V_382:
F_180 () ;
V_381:
F_181 () ;
V_380:
F_182 () ;
V_379:
V_308 = - V_328 ;
goto V_31;
}
static int T_11 F_170 ( void )
{
return 0 ;
}
