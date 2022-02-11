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
F_13 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_15 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_18 ) {
if ( V_2 -> V_19 -> V_20 ( V_2 , 0 ) ) {
F_16 ( V_2 ) ;
return - V_21 ;
}
V_4 -> V_22 = F_17 ( V_4 -> V_18 ) ;
}
F_16 ( V_2 ) ;
return 0 ;
}
int F_18 ( struct V_23 * V_1 , int V_24 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned char V_25 ;
int V_26 ;
F_15 ( V_2 ) ;
V_26 = - V_27 ;
if ( V_1 -> V_28 != V_29 || V_1 -> type != V_8 )
goto V_30;
V_25 = V_2 -> V_9 ;
if ( ! ( ( 1 << V_25 ) & ( V_31 | V_32 ) ) )
goto V_30;
if ( V_25 != V_33 ) {
V_26 = F_19 ( V_2 , V_24 ) ;
if ( V_26 )
goto V_30;
}
V_2 -> V_34 = V_24 ;
V_26 = 0 ;
V_30:
F_16 ( V_2 ) ;
return V_26 ;
}
void F_20 ( void )
{
T_1 V_35 ;
do {
F_21 ( & V_35 , sizeof( V_35 ) ) ;
} while ( V_35 == 0 );
F_22 ( & V_36 , 0 , V_35 ) ;
}
static inline int F_23 ( struct V_37 * V_37 , int V_38 )
{
int V_39 ;
const struct V_40 * V_41 ;
if ( F_24 ( V_37 , & V_42 ) )
return 1 ;
V_39 = V_38 & ( V_43 - 1 ) ;
V_41 = F_25 ( V_44 [ V_39 ] ) ;
if ( V_41 == NULL )
return 1 ;
return V_41 -> V_45 ;
}
static int F_26 ( struct V_37 * V_37 , struct V_23 * V_1 , int V_38 ,
int V_46 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_3 * V_4 ;
struct V_49 * V_50 ;
unsigned char V_51 ;
char V_52 ;
int V_53 = 0 ;
int V_26 ;
if ( F_27 ( ! V_36 ) )
if ( V_1 -> type != V_54 && V_1 -> type != V_55 )
F_20 () ;
V_1 -> V_28 = V_29 ;
V_56:
V_26 = - V_57 ;
F_28 () ;
F_29 (answer, &inetsw[sock->type], list) {
V_26 = 0 ;
if ( V_38 == V_48 -> V_38 ) {
if ( V_38 != V_58 )
break;
} else {
if ( V_58 == V_38 ) {
V_38 = V_48 -> V_38 ;
break;
}
if ( V_58 == V_48 -> V_38 )
break;
}
V_26 = - V_59 ;
}
if ( F_27 ( V_26 ) ) {
if ( V_53 < 2 ) {
F_30 () ;
if ( ++ V_53 == 1 )
F_31 ( L_3 ,
V_60 , V_38 , V_1 -> type ) ;
else
F_31 ( L_4 ,
V_60 , V_38 ) ;
goto V_56;
} else
goto V_61;
}
V_26 = - V_62 ;
if ( V_1 -> type == V_54 && ! V_46 && ! F_32 ( V_63 ) )
goto V_61;
V_26 = - V_64 ;
if ( ! F_23 ( V_37 , V_38 ) )
goto V_61;
V_1 -> V_65 = V_48 -> V_65 ;
V_50 = V_48 -> V_66 ;
V_52 = V_48 -> V_67 ;
V_51 = V_48 -> V_68 ;
F_30 () ;
F_7 ( V_50 -> V_69 == NULL ) ;
V_26 = - V_70 ;
V_2 = F_33 ( V_37 , V_60 , V_71 , V_50 ) ;
if ( V_2 == NULL )
goto V_30;
V_26 = 0 ;
V_2 -> V_72 = V_52 ;
if ( V_73 & V_51 )
V_2 -> V_74 = 1 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_75 = ( V_76 & V_51 ) != 0 ;
V_4 -> V_77 = 0 ;
if ( V_54 == V_1 -> type ) {
V_4 -> V_18 = V_38 ;
if ( V_78 == V_38 )
V_4 -> V_79 = 1 ;
}
if ( V_80 . V_81 )
V_4 -> V_82 = V_83 ;
else
V_4 -> V_82 = V_84 ;
V_4 -> V_85 = 0 ;
F_34 ( V_1 , V_2 ) ;
V_2 -> V_86 = F_1 ;
V_2 -> V_87 = V_38 ;
V_2 -> V_88 = V_2 -> V_19 -> V_89 ;
V_4 -> V_90 = - 1 ;
V_4 -> V_91 = 1 ;
V_4 -> V_92 = 1 ;
V_4 -> V_93 = 1 ;
V_4 -> V_94 = 0 ;
V_4 -> V_95 = NULL ;
F_35 ( V_2 ) ;
if ( V_4 -> V_18 ) {
V_4 -> V_22 = F_17 ( V_4 -> V_18 ) ;
V_2 -> V_19 -> V_39 ( V_2 ) ;
}
if ( V_2 -> V_19 -> V_96 ) {
V_26 = V_2 -> V_19 -> V_96 ( V_2 ) ;
if ( V_26 )
F_36 ( V_2 ) ;
}
V_30:
return V_26 ;
V_61:
F_30 () ;
goto V_30;
}
int F_37 ( struct V_23 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_97 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
V_97 = 0 ;
if ( F_6 ( V_2 , V_98 ) &&
! ( V_99 -> V_68 & V_100 ) )
V_97 = V_2 -> V_101 ;
V_1 -> V_2 = NULL ;
V_2 -> V_19 -> V_102 ( V_2 , V_97 ) ;
}
return 0 ;
}
int F_40 ( struct V_23 * V_1 , struct V_103 * V_104 , int V_105 )
{
struct V_106 * V_107 = (struct V_106 * ) V_104 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_108 ;
int V_109 ;
int V_26 ;
if ( V_2 -> V_19 -> V_110 ) {
V_26 = V_2 -> V_19 -> V_110 ( V_2 , V_104 , V_105 ) ;
goto V_30;
}
V_26 = - V_27 ;
if ( V_105 < sizeof( struct V_106 ) )
goto V_30;
if ( V_107 -> V_111 != V_112 ) {
V_26 = - V_64 ;
if ( V_107 -> V_111 != V_113 ||
V_107 -> V_114 . V_115 != F_41 ( V_116 ) )
goto V_30;
}
V_109 = F_42 ( F_43 ( V_2 ) , V_107 -> V_114 . V_115 ) ;
V_26 = - V_117 ;
if ( ! V_118 &&
! ( V_4 -> V_119 || V_4 -> V_120 ) &&
V_107 -> V_114 . V_115 != F_41 ( V_116 ) &&
V_109 != V_121 &&
V_109 != V_122 &&
V_109 != V_123 )
goto V_30;
V_108 = F_44 ( V_107 -> V_124 ) ;
V_26 = - V_125 ;
if ( V_108 && V_108 < V_126 && ! F_32 ( V_127 ) )
goto V_30;
F_15 ( V_2 ) ;
V_26 = - V_27 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_18 )
goto V_128;
V_4 -> V_129 = V_4 -> V_130 = V_107 -> V_114 . V_115 ;
if ( V_109 == V_122 || V_109 == V_123 )
V_4 -> V_130 = 0 ;
if ( V_2 -> V_19 -> V_20 ( V_2 , V_108 ) ) {
V_4 -> V_130 = V_4 -> V_129 = 0 ;
V_26 = - V_131 ;
goto V_128;
}
if ( V_4 -> V_129 )
V_2 -> V_132 |= V_133 ;
if ( V_108 )
V_2 -> V_132 |= V_134 ;
V_4 -> V_22 = F_17 ( V_4 -> V_18 ) ;
V_4 -> V_135 = 0 ;
V_4 -> V_136 = 0 ;
F_45 ( V_2 ) ;
V_26 = 0 ;
V_128:
F_16 ( V_2 ) ;
V_30:
return V_26 ;
}
int F_46 ( struct V_23 * V_1 , struct V_103 * V_104 ,
int V_105 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_105 < sizeof( V_104 -> V_137 ) )
return - V_27 ;
if ( V_104 -> V_137 == V_113 )
return V_2 -> V_19 -> V_138 ( V_2 , V_68 ) ;
if ( ! F_2 ( V_2 ) -> V_18 && F_14 ( V_2 ) )
return - V_21 ;
return V_2 -> V_19 -> V_139 ( V_2 , (struct V_103 * ) V_104 , V_105 ) ;
}
static long F_47 ( struct V_1 * V_2 , long V_140 )
{
F_48 ( V_141 ) ;
F_49 ( F_50 ( V_2 ) , & V_141 , V_142 ) ;
while ( ( 1 << V_2 -> V_9 ) & ( V_143 | V_144 ) ) {
F_16 ( V_2 ) ;
V_140 = F_51 ( V_140 ) ;
F_15 ( V_2 ) ;
if ( F_52 ( V_99 ) || ! V_140 )
break;
F_49 ( F_50 ( V_2 ) , & V_141 , V_142 ) ;
}
F_53 ( F_50 ( V_2 ) , & V_141 ) ;
return V_140 ;
}
int F_54 ( struct V_23 * V_1 , struct V_103 * V_104 ,
int V_105 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 ;
long V_140 ;
if ( V_105 < sizeof( V_104 -> V_137 ) )
return - V_27 ;
F_15 ( V_2 ) ;
if ( V_104 -> V_137 == V_113 ) {
V_26 = V_2 -> V_19 -> V_138 ( V_2 , V_68 ) ;
V_1 -> V_28 = V_26 ? V_145 : V_29 ;
goto V_30;
}
switch ( V_1 -> V_28 ) {
default:
V_26 = - V_27 ;
goto V_30;
case V_146 :
V_26 = - V_147 ;
goto V_30;
case V_148 :
V_26 = - V_149 ;
break;
case V_29 :
V_26 = - V_147 ;
if ( V_2 -> V_9 != V_10 )
goto V_30;
V_26 = V_2 -> V_19 -> V_139 ( V_2 , V_104 , V_105 ) ;
if ( V_26 < 0 )
goto V_30;
V_1 -> V_28 = V_148 ;
V_26 = - V_150 ;
break;
}
V_140 = F_55 ( V_2 , V_68 & V_151 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_143 | V_144 ) ) {
if ( ! V_140 || ! F_47 ( V_2 , V_140 ) )
goto V_30;
V_26 = F_56 ( V_140 ) ;
if ( F_52 ( V_99 ) )
goto V_30;
}
if ( V_2 -> V_9 == V_10 )
goto V_152;
V_1 -> V_28 = V_146 ;
V_26 = 0 ;
V_30:
F_16 ( V_2 ) ;
return V_26 ;
V_152:
V_26 = V_152 ( V_2 ) ? : - V_153 ;
V_1 -> V_28 = V_29 ;
if ( V_2 -> V_19 -> V_138 ( V_2 , V_68 ) )
V_1 -> V_28 = V_145 ;
goto V_30;
}
int F_57 ( struct V_23 * V_1 , struct V_23 * V_154 , int V_68 )
{
struct V_1 * V_155 = V_1 -> V_2 ;
int V_26 = - V_27 ;
struct V_1 * V_156 = V_155 -> V_19 -> V_157 ( V_155 , V_68 , & V_26 ) ;
if ( ! V_156 )
goto V_158;
F_15 ( V_156 ) ;
F_58 ( V_156 ) ;
F_7 ( ! ( ( 1 << V_156 -> V_9 ) &
( V_159 | V_160 | V_31 ) ) ) ;
F_59 ( V_156 , V_154 ) ;
V_154 -> V_28 = V_146 ;
V_26 = 0 ;
F_16 ( V_156 ) ;
V_158:
return V_26 ;
}
int F_60 ( struct V_23 * V_1 , struct V_103 * V_104 ,
int * V_161 , int V_162 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_61 ( struct V_106 * , sin , V_104 ) ;
sin -> V_111 = V_112 ;
if ( V_162 ) {
if ( ! V_4 -> V_136 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_31 | V_143 ) ) &&
V_162 == 1 ) )
return - V_163 ;
sin -> V_124 = V_4 -> V_136 ;
sin -> V_114 . V_115 = V_4 -> V_135 ;
} else {
T_2 V_107 = V_4 -> V_129 ;
if ( ! V_107 )
V_107 = V_4 -> V_130 ;
sin -> V_124 = V_4 -> V_22 ;
sin -> V_114 . V_115 = V_107 ;
}
memset ( sin -> V_164 , 0 , sizeof( sin -> V_164 ) ) ;
* V_161 = sizeof( * sin ) ;
return 0 ;
}
int F_62 ( struct V_165 * V_166 , struct V_23 * V_1 , struct V_167 * V_168 ,
T_3 V_169 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_58 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_18 && ! V_2 -> V_19 -> V_170 &&
F_14 ( V_2 ) )
return - V_21 ;
return V_2 -> V_19 -> V_171 ( V_166 , V_2 , V_168 , V_169 ) ;
}
T_4 F_63 ( struct V_23 * V_1 , struct V_172 * V_172 , int V_173 ,
T_3 V_169 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_58 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_18 && ! V_2 -> V_19 -> V_170 &&
F_14 ( V_2 ) )
return - V_21 ;
if ( V_2 -> V_19 -> V_174 )
return V_2 -> V_19 -> V_174 ( V_2 , V_172 , V_173 , V_169 , V_68 ) ;
return F_64 ( V_1 , V_172 , V_173 , V_169 , V_68 ) ;
}
int F_65 ( struct V_165 * V_166 , struct V_23 * V_1 , struct V_167 * V_168 ,
T_3 V_169 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_105 = 0 ;
int V_26 ;
F_58 ( V_2 ) ;
V_26 = V_2 -> V_19 -> V_175 ( V_166 , V_2 , V_168 , V_169 , V_68 & V_176 ,
V_68 & ~ V_176 , & V_105 ) ;
if ( V_26 >= 0 )
V_168 -> V_177 = V_105 ;
return V_26 ;
}
int F_66 ( struct V_23 * V_1 , int V_178 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 = 0 ;
V_178 ++ ;
if ( ( V_178 & ~ V_179 ) || ! V_178 )
return - V_27 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_28 == V_148 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_143 | V_144 | V_31 ) )
V_1 -> V_28 = V_145 ;
else
V_1 -> V_28 = V_146 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_26 = - V_163 ;
default:
V_2 -> V_180 |= V_178 ;
if ( V_2 -> V_19 -> V_181 )
V_2 -> V_19 -> V_181 ( V_2 , V_178 ) ;
break;
case V_33 :
if ( ! ( V_178 & V_182 ) )
break;
case V_183 :
V_26 = V_2 -> V_19 -> V_138 ( V_2 , V_151 ) ;
V_1 -> V_28 = V_26 ? V_145 : V_29 ;
break;
}
V_2 -> V_184 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_26 ;
}
int F_67 ( struct V_23 * V_1 , unsigned int V_185 , unsigned long V_186 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 = 0 ;
struct V_37 * V_37 = F_43 ( V_2 ) ;
switch ( V_185 ) {
case V_187 :
V_26 = F_68 ( V_2 , (struct V_188 V_189 * ) V_186 ) ;
break;
case V_190 :
V_26 = F_69 ( V_2 , (struct V_191 V_189 * ) V_186 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
V_26 = F_70 ( V_37 , V_185 , ( void V_189 * ) V_186 ) ;
break;
case V_195 :
case V_196 :
case V_197 :
V_26 = F_71 ( V_37 , V_185 , ( void V_189 * ) V_186 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
V_26 = F_72 ( V_37 , V_185 , ( void V_189 * ) V_186 ) ;
break;
default:
if ( V_2 -> V_19 -> V_209 )
V_26 = V_2 -> V_19 -> V_209 ( V_2 , V_185 , V_186 ) ;
else
V_26 = - V_210 ;
break;
}
return V_26 ;
}
int F_73 ( struct V_23 * V_1 , unsigned int V_185 , unsigned long V_186 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 = - V_210 ;
if ( V_2 -> V_19 -> V_211 )
V_26 = V_2 -> V_19 -> V_211 ( V_2 , V_185 , V_186 ) ;
return V_26 ;
}
void F_74 ( struct V_47 * V_212 )
{
struct V_213 * V_214 ;
struct V_47 * V_48 ;
int V_38 = V_212 -> V_38 ;
struct V_213 * V_215 ;
F_75 ( & V_216 ) ;
if ( V_212 -> type >= V_217 )
goto V_218;
V_48 = NULL ;
V_215 = & V_219 [ V_212 -> type ] ;
F_76 (lh, &inetsw[p->type]) {
V_48 = F_77 ( V_214 , struct V_47 , V_220 ) ;
if ( V_221 & V_48 -> V_68 ) {
if ( V_38 == V_48 -> V_38 )
break;
V_215 = V_214 ;
}
V_48 = NULL ;
}
if ( V_48 )
goto V_222;
F_78 ( & V_212 -> V_220 , V_215 ) ;
V_30:
F_79 ( & V_216 ) ;
return;
V_222:
F_80 ( V_223 L_5 ,
V_38 ) ;
goto V_30;
V_218:
F_80 ( V_223
L_6 ,
V_212 -> type ) ;
goto V_30;
}
void F_81 ( struct V_47 * V_212 )
{
if ( V_221 & V_212 -> V_68 ) {
F_80 ( V_223
L_7 ,
V_212 -> V_38 ) ;
} else {
F_75 ( & V_216 ) ;
F_82 ( & V_212 -> V_220 ) ;
F_79 ( & V_216 ) ;
F_83 () ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_224 = V_4 -> V_130 ;
T_2 V_225 = V_4 -> V_135 ;
struct V_226 * V_227 ;
struct V_228 * V_229 ;
T_2 V_230 ;
struct V_231 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_85 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_232 . V_233 )
V_225 = V_16 -> V_232 . V_234 ;
V_227 = & V_4 -> V_235 . V_236 . V_237 . V_238 ;
V_229 = F_86 ( V_227 , V_225 , 0 , F_87 ( V_2 ) ,
V_2 -> V_239 , V_2 -> V_87 ,
V_4 -> V_22 , V_4 -> V_136 , V_2 , false ) ;
if ( F_88 ( V_229 ) )
return F_89 ( V_229 ) ;
F_90 ( V_2 , & V_229 -> V_240 ) ;
V_230 = V_227 -> V_241 ;
if ( V_230 == V_224 )
return 0 ;
if ( V_242 > 1 ) {
F_80 ( V_243 L_8 ,
V_244 , & V_224 , & V_230 ) ;
}
V_4 -> V_130 = V_4 -> V_129 = V_230 ;
F_91 ( V_2 ) ;
return 0 ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_228 * V_229 = (struct V_228 * ) F_93 ( V_2 , 0 ) ;
T_2 V_225 ;
struct V_231 * V_16 ;
struct V_226 * V_227 ;
int V_26 ;
if ( V_229 )
return 0 ;
F_28 () ;
V_16 = F_25 ( V_4 -> V_16 ) ;
V_225 = V_4 -> V_135 ;
if ( V_16 && V_16 -> V_232 . V_233 )
V_225 = V_16 -> V_232 . V_234 ;
F_30 () ;
V_227 = & V_4 -> V_235 . V_236 . V_237 . V_238 ;
V_229 = F_94 ( F_43 ( V_2 ) , V_227 , V_2 , V_225 , V_4 -> V_130 ,
V_4 -> V_136 , V_4 -> V_22 ,
V_2 -> V_87 , F_87 ( V_2 ) ,
V_2 -> V_239 ) ;
if ( ! F_88 ( V_229 ) ) {
V_26 = 0 ;
F_90 ( V_2 , & V_229 -> V_240 ) ;
} else {
V_26 = F_89 ( V_229 ) ;
V_2 -> V_245 = 0 ;
if ( ! V_242 ||
V_2 -> V_9 != V_183 ||
( V_2 -> V_132 & V_133 ) ||
( V_26 = F_84 ( V_2 ) ) != 0 )
V_2 -> V_246 = - V_26 ;
}
return V_26 ;
}
static int F_95 ( struct V_247 * V_248 )
{
const struct V_249 * V_250 ;
const struct V_40 * V_65 ;
int V_49 ;
int V_251 ;
int V_26 = - V_27 ;
if ( F_27 ( ! F_96 ( V_248 , sizeof( * V_250 ) ) ) )
goto V_30;
V_250 = F_97 ( V_248 ) ;
V_251 = V_250 -> V_251 * 4 ;
if ( V_251 < sizeof( * V_250 ) )
goto V_30;
if ( F_27 ( ! F_96 ( V_248 , V_251 ) ) )
goto V_30;
F_98 ( V_248 , V_251 ) ;
F_99 ( V_248 ) ;
V_250 = F_97 ( V_248 ) ;
V_49 = V_250 -> V_38 & ( V_43 - 1 ) ;
V_26 = - V_59 ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( F_100 ( V_65 && V_65 -> V_252 ) )
V_26 = V_65 -> V_252 ( V_248 ) ;
F_30 () ;
V_30:
return V_26 ;
}
static struct V_247 * F_101 ( struct V_247 * V_248 , T_1 V_253 )
{
struct V_247 * V_254 = F_102 ( - V_27 ) ;
struct V_249 * V_250 ;
const struct V_40 * V_65 ;
int V_49 ;
int V_251 ;
int V_255 ;
unsigned int V_173 = 0 ;
if ( ! ( V_253 & V_256 ) )
V_253 &= ~ V_257 ;
if ( F_27 ( F_103 ( V_248 ) -> V_258 &
~ ( V_259 |
V_260 |
V_261 |
V_262 |
0 ) ) )
goto V_30;
if ( F_27 ( ! F_96 ( V_248 , sizeof( * V_250 ) ) ) )
goto V_30;
V_250 = F_97 ( V_248 ) ;
V_251 = V_250 -> V_251 * 4 ;
if ( V_251 < sizeof( * V_250 ) )
goto V_30;
if ( F_27 ( ! F_96 ( V_248 , V_251 ) ) )
goto V_30;
F_98 ( V_248 , V_251 ) ;
F_99 ( V_248 ) ;
V_250 = F_97 ( V_248 ) ;
V_255 = F_44 ( V_250 -> V_255 ) ;
V_49 = V_250 -> V_38 & ( V_43 - 1 ) ;
V_254 = F_102 ( - V_59 ) ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( F_100 ( V_65 && V_65 -> V_263 ) )
V_254 = V_65 -> V_263 ( V_248 , V_253 ) ;
F_30 () ;
if ( ! V_254 || F_88 ( V_254 ) )
goto V_30;
V_248 = V_254 ;
do {
V_250 = F_97 ( V_248 ) ;
if ( V_49 == V_264 ) {
V_250 -> V_255 = F_17 ( V_255 ) ;
V_250 -> V_265 = F_17 ( V_173 >> 3 ) ;
if ( V_248 -> V_266 != NULL )
V_250 -> V_265 |= F_17 ( V_267 ) ;
V_173 += ( V_248 -> V_268 - V_248 -> V_269 - V_250 -> V_251 * 4 ) ;
} else
V_250 -> V_255 = F_17 ( V_255 ++ ) ;
V_250 -> V_270 = F_17 ( V_248 -> V_268 - V_248 -> V_269 ) ;
V_250 -> V_271 = 0 ;
V_250 -> V_271 = F_104 ( F_105 ( V_248 ) , V_250 -> V_251 ) ;
} while ( ( V_248 = V_248 -> V_266 ) );
V_30:
return V_254 ;
}
static struct V_247 * * F_106 ( struct V_247 * * V_272 ,
struct V_247 * V_248 )
{
const struct V_40 * V_65 ;
struct V_247 * * V_273 = NULL ;
struct V_247 * V_212 ;
const struct V_249 * V_250 ;
unsigned int V_274 ;
unsigned int V_275 ;
unsigned int V_255 ;
int V_276 = 1 ;
int V_49 ;
V_275 = F_107 ( V_248 ) ;
V_274 = V_275 + sizeof( * V_250 ) ;
V_250 = F_108 ( V_248 , V_275 ) ;
if ( F_109 ( V_248 , V_274 ) ) {
V_250 = F_110 ( V_248 , V_274 , V_275 ) ;
if ( F_27 ( ! V_250 ) )
goto V_30;
}
V_49 = V_250 -> V_38 & ( V_43 - 1 ) ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( ! V_65 || ! V_65 -> V_277 )
goto V_278;
if ( * ( V_279 * ) V_250 != 0x45 )
goto V_278;
if ( F_27 ( F_104 ( ( V_279 * ) V_250 , V_250 -> V_251 ) ) )
goto V_278;
V_255 = F_111 ( * ( T_2 * ) & V_250 -> V_255 ) ;
V_276 = ( V_280 ) ( ( F_111 ( * ( T_2 * ) V_250 ) ^ F_112 ( V_248 ) ) | ( V_255 ^ V_281 ) ) ;
V_255 >>= 16 ;
for ( V_212 = * V_272 ; V_212 ; V_212 = V_212 -> V_266 ) {
struct V_249 * V_282 ;
if ( ! F_113 ( V_212 ) -> V_283 )
continue;
V_282 = F_97 ( V_212 ) ;
if ( ( V_250 -> V_38 ^ V_282 -> V_38 ) |
( V_250 -> V_284 ^ V_282 -> V_284 ) |
( ( V_285 T_1 ) V_250 -> V_241 ^ ( V_285 T_1 ) V_282 -> V_241 ) |
( ( V_285 T_1 ) V_250 -> V_225 ^ ( V_285 T_1 ) V_282 -> V_225 ) ) {
F_113 ( V_212 ) -> V_283 = 0 ;
continue;
}
F_113 ( V_212 ) -> V_276 |=
( V_250 -> V_286 ^ V_282 -> V_286 ) |
( ( V_280 ) ( F_44 ( V_282 -> V_255 ) + F_113 ( V_212 ) -> V_287 ) ^ V_255 ) ;
F_113 ( V_212 ) -> V_276 |= V_276 ;
}
F_113 ( V_248 ) -> V_276 |= V_276 ;
F_114 ( V_248 , sizeof( * V_250 ) ) ;
F_115 ( V_248 , F_107 ( V_248 ) ) ;
V_273 = V_65 -> V_277 ( V_272 , V_248 ) ;
V_278:
F_30 () ;
V_30:
F_113 ( V_248 ) -> V_276 |= V_276 ;
return V_273 ;
}
static int F_116 ( struct V_247 * V_248 )
{
const struct V_40 * V_65 ;
struct V_249 * V_250 = F_97 ( V_248 ) ;
int V_49 = V_250 -> V_38 & ( V_43 - 1 ) ;
int V_26 = - V_288 ;
T_5 V_289 = F_17 ( V_248 -> V_268 - F_117 ( V_248 ) ) ;
F_118 ( & V_250 -> V_271 , V_250 -> V_270 , V_289 ) ;
V_250 -> V_270 = V_289 ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( F_7 ( ! V_65 || ! V_65 -> V_290 ) )
goto V_278;
V_26 = V_65 -> V_290 ( V_248 ) ;
V_278:
F_30 () ;
return V_26 ;
}
int F_119 ( struct V_1 * * V_2 , unsigned short V_291 ,
unsigned short type , unsigned char V_38 ,
struct V_37 * V_37 )
{
struct V_23 * V_1 ;
int V_292 = F_120 ( V_291 , type , V_38 , & V_1 ) ;
if ( V_292 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_293 = V_294 ;
( * V_2 ) -> V_19 -> V_295 ( * V_2 ) ;
F_121 ( * V_2 , V_37 ) ;
}
return V_292 ;
}
unsigned long F_122 ( void T_6 * V_296 [] , int V_297 )
{
unsigned long V_298 = 0 ;
int V_299 , V_300 ;
F_123 (i) {
for ( V_300 = 0 ; V_300 < V_301 ; V_300 ++ )
V_298 += * ( ( ( unsigned long * ) F_124 ( V_296 [ V_300 ] , V_299 ) ) + V_297 ) ;
}
return V_298 ;
}
T_7 F_125 ( void T_6 * V_296 [] , int V_297 , T_3 V_302 )
{
T_7 V_298 = 0 ;
int V_303 ;
F_123 (cpu) {
void * V_304 ;
struct V_305 * V_306 ;
T_7 V_307 ;
unsigned int V_308 ;
V_304 = F_124 ( V_296 [ 0 ] , V_303 ) ;
V_306 = (struct V_305 * ) ( V_304 + V_302 ) ;
do {
V_308 = F_126 ( V_306 ) ;
V_307 = * ( ( ( T_7 * ) V_304 ) + V_297 ) ;
} while ( F_127 ( V_306 , V_308 ) );
V_298 += V_307 ;
}
return V_298 ;
}
int F_128 ( void T_6 * V_309 [ 2 ] , T_3 V_310 , T_3 V_311 )
{
F_129 ( V_309 == NULL ) ;
V_309 [ 0 ] = F_130 ( V_310 , V_311 ) ;
if ( ! V_309 [ 0 ] )
return - V_312 ;
#if V_301 == 2
V_309 [ 1 ] = F_130 ( V_310 , V_311 ) ;
if ( ! V_309 [ 1 ] ) {
F_131 ( V_309 [ 0 ] ) ;
V_309 [ 0 ] = NULL ;
return - V_312 ;
}
#endif
return 0 ;
}
void F_132 ( void T_6 * V_309 [ V_301 ] )
{
int V_299 ;
F_129 ( V_309 == NULL ) ;
for ( V_299 = 0 ; V_299 < V_301 ; V_299 ++ ) {
F_131 ( V_309 [ V_299 ] ) ;
V_309 [ V_299 ] = NULL ;
}
}
static T_8 int F_133 ( struct V_37 * V_37 )
{
if ( F_128 ( ( void T_6 * * ) V_37 -> V_296 . V_313 ,
sizeof( struct V_314 ) ,
F_134 ( struct V_314 ) ) < 0 )
goto V_315;
if ( F_128 ( ( void T_6 * * ) V_37 -> V_296 . V_316 ,
sizeof( struct V_317 ) ,
F_134 ( struct V_317 ) ) < 0 )
goto V_318;
if ( F_128 ( ( void T_6 * * ) V_37 -> V_296 . V_319 ,
sizeof( struct V_320 ) ,
F_134 ( struct V_320 ) ) < 0 )
goto V_321;
if ( F_128 ( ( void T_6 * * ) V_37 -> V_296 . V_322 ,
sizeof( struct V_323 ) ,
F_134 ( struct V_323 ) ) < 0 )
goto V_324;
if ( F_128 ( ( void T_6 * * ) V_37 -> V_296 . V_325 ,
sizeof( struct V_323 ) ,
F_134 ( struct V_323 ) ) < 0 )
goto V_326;
if ( F_128 ( ( void T_6 * * ) V_37 -> V_296 . V_327 ,
sizeof( struct V_328 ) ,
F_134 ( struct V_328 ) ) < 0 )
goto V_329;
if ( F_128 ( ( void T_6 * * ) V_37 -> V_296 . V_330 ,
sizeof( struct V_331 ) ,
F_134 ( struct V_331 ) ) < 0 )
goto V_332;
F_135 ( V_37 ) ;
return 0 ;
V_332:
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_327 ) ;
V_329:
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_325 ) ;
V_326:
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_322 ) ;
V_324:
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_319 ) ;
V_321:
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_316 ) ;
V_318:
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_313 ) ;
V_315:
return - V_312 ;
}
static T_9 void F_136 ( struct V_37 * V_37 )
{
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_330 ) ;
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_327 ) ;
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_325 ) ;
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_322 ) ;
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_319 ) ;
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_316 ) ;
F_132 ( ( void T_6 * * ) V_37 -> V_296 . V_313 ) ;
}
static int T_10 F_137 ( void )
{
return F_138 ( & V_333 ) ;
}
static int T_10 F_139 ( void )
{
struct V_247 * V_334 ;
struct V_47 * V_335 ;
struct V_213 * V_336 ;
int V_292 = - V_27 ;
F_140 ( sizeof( struct V_337 ) > sizeof( V_334 -> V_338 ) ) ;
V_339 = F_141 ( 65536 / 8 , V_71 ) ;
if ( ! V_339 )
goto V_30;
V_292 = F_142 ( & V_340 , 1 ) ;
if ( V_292 )
goto V_341;
V_292 = F_142 ( & V_342 , 1 ) ;
if ( V_292 )
goto V_343;
V_292 = F_142 ( & V_344 , 1 ) ;
if ( V_292 )
goto V_345;
V_292 = F_142 ( & V_346 , 1 ) ;
if ( V_292 )
goto V_347;
( void ) F_143 ( & V_348 ) ;
#ifdef F_144
F_145 () ;
#endif
if ( F_146 ( & V_349 , V_350 ) < 0 )
F_80 ( V_351 L_9 ) ;
if ( F_146 ( & V_352 , V_264 ) < 0 )
F_80 ( V_351 L_10 ) ;
if ( F_146 ( & V_353 , V_354 ) < 0 )
F_80 ( V_351 L_11 ) ;
#ifdef F_147
if ( F_146 ( & V_355 , V_356 ) < 0 )
F_80 ( V_351 L_12 ) ;
#endif
for ( V_336 = & V_219 [ 0 ] ; V_336 < & V_219 [ V_217 ] ; ++ V_336 )
F_148 ( V_336 ) ;
for ( V_335 = V_357 ; V_335 < & V_357 [ V_358 ] ; ++ V_335 )
F_74 ( V_335 ) ;
F_149 () ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
F_154 () ;
F_155 () ;
if ( F_156 () < 0 )
F_157 ( L_13 ) ;
#if F_158 ( V_359 )
if ( F_159 () )
F_80 ( V_351 L_14 ) ;
#endif
if ( F_137 () )
F_80 ( V_351 L_15 ) ;
F_160 () ;
F_161 () ;
F_162 ( & V_360 ) ;
V_292 = 0 ;
V_30:
return V_292 ;
V_347:
F_163 ( & V_344 ) ;
V_345:
F_163 ( & V_342 ) ;
V_343:
F_163 ( & V_340 ) ;
V_341:
F_9 ( V_339 ) ;
goto V_30;
}
static int T_10 F_160 ( void )
{
int V_292 = 0 ;
if ( F_164 () )
goto V_361;
if ( F_165 () )
goto V_362;
if ( F_166 () )
goto V_363;
if ( F_167 () )
goto V_364;
if ( F_168 () )
goto V_365;
V_30:
return V_292 ;
V_365:
F_169 () ;
V_364:
F_170 () ;
V_363:
F_171 () ;
V_362:
F_172 () ;
V_361:
V_292 = - V_312 ;
goto V_30;
}
static int T_10 F_160 ( void )
{
return 0 ;
}
