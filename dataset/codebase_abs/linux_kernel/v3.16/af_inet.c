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
int V_51 = 0 ;
int V_27 ;
V_1 -> V_29 = V_30 ;
V_52:
V_27 = - V_53 ;
F_23 () ;
F_24 (answer, &inetsw[sock->type], list) {
V_27 = 0 ;
if ( V_44 == V_47 -> V_44 ) {
if ( V_44 != V_54 )
break;
} else {
if ( V_54 == V_44 ) {
V_44 = V_47 -> V_44 ;
break;
}
if ( V_54 == V_47 -> V_44 )
break;
}
V_27 = - V_55 ;
}
if ( F_25 ( V_27 ) ) {
if ( V_51 < 2 ) {
F_26 () ;
if ( ++ V_51 == 1 )
F_27 ( L_3 ,
V_56 , V_44 , V_1 -> type ) ;
else
F_27 ( L_4 ,
V_56 , V_44 ) ;
goto V_52;
} else
goto V_57;
}
V_27 = - V_58 ;
if ( V_1 -> type == V_59 && ! V_45 &&
! F_28 ( V_43 -> V_60 , V_61 ) )
goto V_57;
V_1 -> V_62 = V_47 -> V_62 ;
V_49 = V_47 -> V_63 ;
V_50 = V_47 -> V_64 ;
F_26 () ;
F_7 ( V_49 -> V_65 == NULL ) ;
V_27 = - V_66 ;
V_2 = F_29 ( V_43 , V_56 , V_67 , V_49 ) ;
if ( V_2 == NULL )
goto V_31;
V_27 = 0 ;
if ( V_68 & V_50 )
V_2 -> V_69 = V_70 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_71 = ( V_72 & V_50 ) != 0 ;
V_4 -> V_73 = 0 ;
if ( V_59 == V_1 -> type ) {
V_4 -> V_19 = V_44 ;
if ( V_74 == V_44 )
V_4 -> V_75 = 1 ;
}
if ( V_43 -> V_76 . V_77 )
V_4 -> V_78 = V_79 ;
else
V_4 -> V_78 = V_80 ;
V_4 -> V_81 = 0 ;
F_30 ( V_1 , V_2 ) ;
V_2 -> V_82 = F_1 ;
V_2 -> V_83 = V_44 ;
V_2 -> V_84 = V_2 -> V_20 -> V_85 ;
V_4 -> V_86 = - 1 ;
V_4 -> V_87 = 1 ;
V_4 -> V_88 = 1 ;
V_4 -> V_89 = 1 ;
V_4 -> V_90 = 0 ;
V_4 -> V_91 = NULL ;
V_4 -> V_92 = 0 ;
F_31 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_2 -> V_20 -> V_93 ( V_2 ) ;
}
if ( V_2 -> V_20 -> V_94 ) {
V_27 = V_2 -> V_20 -> V_94 ( V_2 ) ;
if ( V_27 )
F_32 ( V_2 ) ;
}
V_31:
return V_27 ;
V_57:
F_26 () ;
goto V_31;
}
int F_33 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_95 ;
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
V_95 = 0 ;
if ( F_6 ( V_2 , V_96 ) &&
! ( V_97 -> V_64 & V_98 ) )
V_95 = V_2 -> V_99 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_100 ( V_2 , V_95 ) ;
}
return 0 ;
}
int F_36 ( struct V_24 * V_1 , struct V_101 * V_102 , int V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_43 = F_37 ( V_2 ) ;
unsigned short V_106 ;
int V_107 ;
int V_27 ;
if ( V_2 -> V_20 -> V_108 ) {
V_27 = V_2 -> V_20 -> V_108 ( V_2 , V_102 , V_103 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_103 < sizeof( struct V_104 ) )
goto V_31;
if ( V_105 -> V_109 != V_110 ) {
V_27 = - V_111 ;
if ( V_105 -> V_109 != V_112 ||
V_105 -> V_113 . V_114 != F_38 ( V_115 ) )
goto V_31;
}
V_107 = F_39 ( V_43 , V_105 -> V_113 . V_114 ) ;
V_27 = - V_116 ;
if ( ! V_117 &&
! ( V_4 -> V_118 || V_4 -> V_119 ) &&
V_105 -> V_113 . V_114 != F_38 ( V_115 ) &&
V_107 != V_120 &&
V_107 != V_121 &&
V_107 != V_122 )
goto V_31;
V_106 = F_40 ( V_105 -> V_123 ) ;
V_27 = - V_124 ;
if ( V_106 && V_106 < V_125 &&
! F_28 ( V_43 -> V_60 , V_126 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_127;
V_4 -> V_128 = V_4 -> V_129 = V_105 -> V_113 . V_114 ;
if ( V_107 == V_121 || V_107 == V_122 )
V_4 -> V_129 = 0 ;
if ( V_2 -> V_20 -> V_21 ( V_2 , V_106 ) ) {
V_4 -> V_129 = V_4 -> V_128 = 0 ;
V_27 = - V_130 ;
goto V_127;
}
if ( V_4 -> V_128 )
V_2 -> V_131 |= V_132 ;
if ( V_106 )
V_2 -> V_131 |= V_133 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_134 = 0 ;
V_4 -> V_135 = 0 ;
F_41 ( V_2 ) ;
V_27 = 0 ;
V_127:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_42 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_103 < sizeof( V_102 -> V_136 ) )
return - V_28 ;
if ( V_102 -> V_136 == V_112 )
return V_2 -> V_20 -> V_137 ( V_2 , V_64 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_138 ( V_2 , V_102 , V_103 ) ;
}
static long F_43 ( struct V_1 * V_2 , long V_139 , int V_140 )
{
F_44 ( V_141 ) ;
F_45 ( F_46 ( V_2 ) , & V_141 , V_142 ) ;
V_2 -> V_143 += V_140 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_144 | V_145 ) ) {
F_16 ( V_2 ) ;
V_139 = F_47 ( V_139 ) ;
F_15 ( V_2 ) ;
if ( F_48 ( V_97 ) || ! V_139 )
break;
F_45 ( F_46 ( V_2 ) , & V_141 , V_142 ) ;
}
F_49 ( F_46 ( V_2 ) , & V_141 ) ;
V_2 -> V_143 -= V_140 ;
return V_139 ;
}
int F_50 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_139 ;
if ( V_103 < sizeof( V_102 -> V_136 ) )
return - V_28 ;
if ( V_102 -> V_136 == V_112 ) {
V_27 = V_2 -> V_20 -> V_137 ( V_2 , V_64 ) ;
V_1 -> V_29 = V_27 ? V_146 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_147 :
V_27 = - V_148 ;
goto V_31;
case V_149 :
V_27 = - V_150 ;
break;
case V_30 :
V_27 = - V_148 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_138 ( V_2 , V_102 , V_103 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_149 ;
V_27 = - V_151 ;
break;
}
V_139 = F_51 ( V_2 , V_64 & V_152 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_144 | V_145 ) ) {
int V_140 = ( V_2 -> V_83 == V_153 ) &&
F_52 ( V_2 ) -> V_154 &&
F_52 ( V_2 ) -> V_154 -> V_155 ? 1 : 0 ;
if ( ! V_139 || ! F_43 ( V_2 , V_139 , V_140 ) )
goto V_31;
V_27 = F_53 ( V_139 ) ;
if ( F_48 ( V_97 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_156;
V_1 -> V_29 = V_147 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_156:
V_27 = V_156 ( V_2 ) ? : - V_157 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_137 ( V_2 , V_64 ) )
V_1 -> V_29 = V_146 ;
goto V_31;
}
int F_54 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_50 ( V_1 , V_102 , V_103 , V_64 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_55 ( struct V_24 * V_1 , struct V_24 * V_158 , int V_64 )
{
struct V_1 * V_159 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_160 = V_159 -> V_20 -> V_161 ( V_159 , V_64 , & V_27 ) ;
if ( ! V_160 )
goto V_162;
F_15 ( V_160 ) ;
F_56 ( V_160 ) ;
F_7 ( ! ( ( 1 << V_160 -> V_9 ) &
( V_163 | V_145 |
V_164 | V_32 ) ) ) ;
F_57 ( V_160 , V_158 ) ;
V_158 -> V_29 = V_147 ;
V_27 = 0 ;
F_16 ( V_160 ) ;
V_162:
return V_27 ;
}
int F_58 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int * V_165 , int V_166 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_59 ( struct V_104 * , sin , V_102 ) ;
sin -> V_109 = V_110 ;
if ( V_166 ) {
if ( ! V_4 -> V_135 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_144 ) ) &&
V_166 == 1 ) )
return - V_167 ;
sin -> V_123 = V_4 -> V_135 ;
sin -> V_113 . V_114 = V_4 -> V_134 ;
} else {
T_1 V_105 = V_4 -> V_128 ;
if ( ! V_105 )
V_105 = V_4 -> V_129 ;
sin -> V_123 = V_4 -> V_23 ;
sin -> V_113 . V_114 = V_105 ;
}
memset ( sin -> V_168 , 0 , sizeof( sin -> V_168 ) ) ;
* V_165 = sizeof( * sin ) ;
return 0 ;
}
int F_60 ( struct V_169 * V_170 , struct V_24 * V_1 , struct V_171 * V_172 ,
T_2 V_173 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_56 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_174 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_175 ( V_170 , V_2 , V_172 , V_173 ) ;
}
T_3 F_61 ( struct V_24 * V_1 , struct V_176 * V_176 , int V_177 ,
T_2 V_173 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_56 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_174 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_178 )
return V_2 -> V_20 -> V_178 ( V_2 , V_176 , V_177 , V_173 , V_64 ) ;
return F_62 ( V_1 , V_176 , V_177 , V_173 , V_64 ) ;
}
int F_63 ( struct V_169 * V_170 , struct V_24 * V_1 , struct V_171 * V_172 ,
T_2 V_173 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_103 = 0 ;
int V_27 ;
F_56 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_179 ( V_170 , V_2 , V_172 , V_173 , V_64 & V_180 ,
V_64 & ~ V_180 , & V_103 ) ;
if ( V_27 >= 0 )
V_172 -> V_181 = V_103 ;
return V_27 ;
}
int F_64 ( struct V_24 * V_1 , int V_182 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_182 ++ ;
if ( ( V_182 & ~ V_183 ) || ! V_182 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_149 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_144 | V_145 | V_32 ) )
V_1 -> V_29 = V_146 ;
else
V_1 -> V_29 = V_147 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_167 ;
default:
V_2 -> V_184 |= V_182 ;
if ( V_2 -> V_20 -> V_185 )
V_2 -> V_20 -> V_185 ( V_2 , V_182 ) ;
break;
case V_34 :
if ( ! ( V_182 & V_186 ) )
break;
case V_187 :
V_27 = V_2 -> V_20 -> V_137 ( V_2 , V_152 ) ;
V_1 -> V_29 = V_27 ? V_146 : V_30 ;
break;
}
V_2 -> V_188 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_65 ( struct V_24 * V_1 , unsigned int V_189 , unsigned long V_190 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_43 * V_43 = F_37 ( V_2 ) ;
switch ( V_189 ) {
case V_191 :
V_27 = F_66 ( V_2 , (struct V_192 V_193 * ) V_190 ) ;
break;
case V_194 :
V_27 = F_67 ( V_2 , (struct V_195 V_193 * ) V_190 ) ;
break;
case V_196 :
case V_197 :
case V_198 :
V_27 = F_68 ( V_43 , V_189 , ( void V_193 * ) V_190 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
V_27 = F_69 ( V_43 , V_189 , ( void V_193 * ) V_190 ) ;
break;
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
V_27 = F_70 ( V_43 , V_189 , ( void V_193 * ) V_190 ) ;
break;
default:
if ( V_2 -> V_20 -> V_213 )
V_27 = V_2 -> V_20 -> V_213 ( V_2 , V_189 , V_190 ) ;
else
V_27 = - V_214 ;
break;
}
return V_27 ;
}
static int F_71 ( struct V_24 * V_1 , unsigned int V_189 , unsigned long V_190 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_214 ;
if ( V_2 -> V_20 -> V_215 )
V_27 = V_2 -> V_20 -> V_215 ( V_2 , V_189 , V_190 ) ;
return V_27 ;
}
void F_72 ( struct V_46 * V_216 )
{
struct V_217 * V_218 ;
struct V_46 * V_47 ;
int V_44 = V_216 -> V_44 ;
struct V_217 * V_219 ;
F_73 ( & V_220 ) ;
if ( V_216 -> type >= V_221 )
goto V_222;
V_47 = NULL ;
V_219 = & V_223 [ V_216 -> type ] ;
F_74 (lh, &inetsw[p->type]) {
V_47 = F_75 ( V_218 , struct V_46 , V_224 ) ;
if ( V_225 & V_47 -> V_64 ) {
if ( V_44 == V_47 -> V_44 )
break;
V_219 = V_218 ;
}
V_47 = NULL ;
}
if ( V_47 )
goto V_226;
F_76 ( & V_216 -> V_224 , V_219 ) ;
V_31:
F_77 ( & V_220 ) ;
return;
V_226:
F_5 ( L_5 , V_44 ) ;
goto V_31;
V_222:
F_5 ( L_6 ,
V_216 -> type ) ;
goto V_31;
}
void F_78 ( struct V_46 * V_216 )
{
if ( V_225 & V_216 -> V_64 ) {
F_5 ( L_7 ,
V_216 -> V_44 ) ;
} else {
F_73 ( & V_220 ) ;
F_79 ( & V_216 -> V_224 ) ;
F_77 ( & V_220 ) ;
F_80 () ;
}
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_227 = V_4 -> V_129 ;
T_1 V_228 = V_4 -> V_134 ;
struct V_229 * V_230 ;
struct V_231 * V_232 ;
T_1 V_233 ;
struct V_234 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_82 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_235 . V_236 )
V_228 = V_16 -> V_235 . V_237 ;
V_230 = & V_4 -> V_238 . V_239 . V_240 . V_241 ;
V_232 = F_83 ( V_230 , V_228 , 0 , F_84 ( V_2 ) ,
V_2 -> V_242 , V_2 -> V_83 ,
V_4 -> V_23 , V_4 -> V_135 , V_2 ) ;
if ( F_85 ( V_232 ) )
return F_86 ( V_232 ) ;
F_87 ( V_2 , & V_232 -> V_243 ) ;
V_233 = V_230 -> V_244 ;
if ( V_233 == V_227 )
return 0 ;
if ( V_245 > 1 ) {
F_88 ( L_8 ,
V_246 , & V_227 , & V_233 ) ;
}
V_4 -> V_129 = V_4 -> V_128 = V_233 ;
F_89 ( V_2 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_231 * V_232 = (struct V_231 * ) F_91 ( V_2 , 0 ) ;
T_1 V_228 ;
struct V_234 * V_16 ;
struct V_229 * V_230 ;
int V_27 ;
if ( V_232 )
return 0 ;
F_23 () ;
V_16 = F_92 ( V_4 -> V_16 ) ;
V_228 = V_4 -> V_134 ;
if ( V_16 && V_16 -> V_235 . V_236 )
V_228 = V_16 -> V_235 . V_237 ;
F_26 () ;
V_230 = & V_4 -> V_238 . V_239 . V_240 . V_241 ;
V_232 = F_93 ( F_37 ( V_2 ) , V_230 , V_2 , V_228 , V_4 -> V_129 ,
V_4 -> V_135 , V_4 -> V_23 ,
V_2 -> V_83 , F_84 ( V_2 ) ,
V_2 -> V_242 ) ;
if ( ! F_85 ( V_232 ) ) {
V_27 = 0 ;
F_87 ( V_2 , & V_232 -> V_243 ) ;
} else {
V_27 = F_86 ( V_232 ) ;
V_2 -> V_247 = 0 ;
if ( ! V_245 ||
V_2 -> V_9 != V_187 ||
( V_2 -> V_131 & V_132 ) ||
( V_27 = F_81 ( V_2 ) ) != 0 )
V_2 -> V_248 = - V_27 ;
}
return V_27 ;
}
static int F_94 ( struct V_249 * V_250 )
{
const struct V_251 * V_62 ;
const struct V_252 * V_253 ;
int V_48 ;
int V_254 ;
int V_27 = - V_28 ;
if ( F_25 ( ! F_95 ( V_250 , sizeof( * V_253 ) ) ) )
goto V_31;
V_253 = F_96 ( V_250 ) ;
V_254 = V_253 -> V_254 * 4 ;
if ( V_254 < sizeof( * V_253 ) )
goto V_31;
V_48 = V_253 -> V_44 ;
if ( F_25 ( ! F_95 ( V_250 , V_254 ) ) )
goto V_31;
F_97 ( V_250 , V_254 ) ;
F_98 ( V_250 ) ;
V_27 = - V_55 ;
V_62 = F_92 ( V_255 [ V_48 ] ) ;
if ( F_99 ( V_62 && V_62 -> V_256 . V_257 ) )
V_27 = V_62 -> V_256 . V_257 ( V_250 ) ;
V_31:
return V_27 ;
}
static struct V_249 * F_100 ( struct V_249 * V_250 ,
T_4 V_258 )
{
struct V_249 * V_259 = F_101 ( - V_28 ) ;
const struct V_251 * V_62 ;
unsigned int V_177 = 0 ;
bool V_260 , V_261 ;
struct V_252 * V_253 ;
int V_48 ;
int V_262 ;
int V_254 ;
int V_263 ;
if ( F_25 ( F_102 ( V_250 ) -> V_264 &
~ ( V_265 |
V_266 |
V_267 |
V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
V_275 |
V_276 |
0 ) ) )
goto V_31;
F_103 ( V_250 ) ;
V_262 = F_104 ( V_250 ) - F_105 ( V_250 ) ;
if ( F_25 ( ! F_95 ( V_250 , sizeof( * V_253 ) ) ) )
goto V_31;
V_253 = F_96 ( V_250 ) ;
V_254 = V_253 -> V_254 * 4 ;
if ( V_254 < sizeof( * V_253 ) )
goto V_31;
V_263 = F_40 ( V_253 -> V_263 ) ;
V_48 = V_253 -> V_44 ;
if ( F_25 ( ! F_95 ( V_250 , V_254 ) ) )
goto V_31;
F_97 ( V_250 , V_254 ) ;
V_261 = F_106 ( V_250 ) -> V_277 > 0 ;
if ( V_261 )
V_258 = V_250 -> V_278 -> V_279 & F_107 ( V_250 ) ;
F_106 ( V_250 ) -> V_277 += V_254 ;
F_98 ( V_250 ) ;
V_259 = F_101 ( - V_55 ) ;
if ( V_250 -> V_280 &&
F_102 ( V_250 ) -> V_264 & ( V_272 | V_271 ) )
V_260 = V_48 == V_281 && V_261 ;
else
V_260 = V_48 == V_281 && ! V_250 -> V_280 ;
V_62 = F_92 ( V_255 [ V_48 ] ) ;
if ( F_99 ( V_62 && V_62 -> V_256 . V_282 ) )
V_259 = V_62 -> V_256 . V_282 ( V_250 , V_258 ) ;
if ( F_108 ( V_259 ) )
goto V_31;
V_250 = V_259 ;
do {
V_253 = (struct V_252 * ) ( F_105 ( V_250 ) + V_262 ) ;
if ( V_260 ) {
V_253 -> V_263 = F_17 ( V_263 ) ;
V_253 -> V_283 = F_17 ( V_177 >> 3 ) ;
if ( V_250 -> V_284 != NULL )
V_253 -> V_283 |= F_17 ( V_285 ) ;
V_177 += V_250 -> V_286 - V_262 - V_254 ;
} else {
V_253 -> V_263 = F_17 ( V_263 ++ ) ;
}
V_253 -> V_287 = F_17 ( V_250 -> V_286 - V_262 ) ;
F_109 ( V_253 ) ;
if ( V_261 )
F_110 ( V_250 ) ;
V_250 -> V_288 = ( V_289 * ) V_253 - V_250 -> V_290 ;
} while ( ( V_250 = V_250 -> V_284 ) );
V_31:
return V_259 ;
}
static struct V_249 * * F_111 ( struct V_249 * * V_290 ,
struct V_249 * V_250 )
{
const struct V_251 * V_62 ;
struct V_249 * * V_291 = NULL ;
struct V_249 * V_216 ;
const struct V_252 * V_253 ;
unsigned int V_292 ;
unsigned int V_293 ;
unsigned int V_263 ;
int V_294 = 1 ;
int V_48 ;
V_293 = F_112 ( V_250 ) ;
V_292 = V_293 + sizeof( * V_253 ) ;
V_253 = F_113 ( V_250 , V_293 ) ;
if ( F_114 ( V_250 , V_292 ) ) {
V_253 = F_115 ( V_250 , V_292 , V_293 ) ;
if ( F_25 ( ! V_253 ) )
goto V_31;
}
V_48 = V_253 -> V_44 ;
F_23 () ;
V_62 = F_92 ( V_255 [ V_48 ] ) ;
if ( ! V_62 || ! V_62 -> V_256 . V_295 )
goto V_296;
if ( * ( V_289 * ) V_253 != 0x45 )
goto V_296;
if ( F_25 ( F_116 ( ( V_289 * ) V_253 , 5 ) ) )
goto V_296;
V_263 = F_117 ( * ( T_1 * ) & V_253 -> V_263 ) ;
V_294 = ( V_297 ) ( ( F_117 ( * ( T_1 * ) V_253 ) ^ F_118 ( V_250 ) ) | ( V_263 & ~ V_298 ) ) ;
V_263 >>= 16 ;
for ( V_216 = * V_290 ; V_216 ; V_216 = V_216 -> V_284 ) {
struct V_252 * V_299 ;
if ( ! F_119 ( V_216 ) -> V_300 )
continue;
V_299 = (struct V_252 * ) ( V_216 -> V_155 + V_293 ) ;
if ( ( V_253 -> V_44 ^ V_299 -> V_44 ) |
( ( V_301 V_302 ) V_253 -> V_244 ^ ( V_301 V_302 ) V_299 -> V_244 ) |
( ( V_301 V_302 ) V_253 -> V_228 ^ ( V_301 V_302 ) V_299 -> V_228 ) ) {
F_119 ( V_216 ) -> V_300 = 0 ;
continue;
}
F_119 ( V_216 ) -> V_294 |=
( V_253 -> V_303 ^ V_299 -> V_303 ) |
( V_253 -> V_304 ^ V_299 -> V_304 ) |
( ( V_253 -> V_283 ^ V_299 -> V_283 ) & F_17 ( V_298 ) ) ;
F_119 ( V_216 ) -> V_305 =
( ( V_297 ) ( F_40 ( V_299 -> V_263 ) + F_119 ( V_216 ) -> V_306 ) ^ V_263 ) ;
F_119 ( V_216 ) -> V_294 |= V_294 ;
}
F_119 ( V_250 ) -> V_294 |= V_294 ;
F_120 ( V_250 , V_293 ) ;
F_121 ( V_250 , sizeof( * V_253 ) ) ;
F_122 ( V_250 , F_112 ( V_250 ) ) ;
V_291 = V_62 -> V_256 . V_295 ( V_290 , V_250 ) ;
V_296:
F_26 () ;
V_31:
F_119 ( V_250 ) -> V_294 |= V_294 ;
return V_291 ;
}
static int F_123 ( struct V_249 * V_250 , int V_262 )
{
T_5 V_307 = F_17 ( V_250 -> V_286 - V_262 ) ;
struct V_252 * V_253 = (struct V_252 * ) ( V_250 -> V_155 + V_262 ) ;
const struct V_251 * V_62 ;
int V_48 = V_253 -> V_44 ;
int V_27 = - V_308 ;
if ( V_250 -> V_280 )
F_124 ( V_250 , V_262 ) ;
F_125 ( & V_253 -> V_309 , V_253 -> V_287 , V_307 ) ;
V_253 -> V_287 = V_307 ;
F_23 () ;
V_62 = F_92 ( V_255 [ V_48 ] ) ;
if ( F_7 ( ! V_62 || ! V_62 -> V_256 . V_310 ) )
goto V_296;
V_27 = V_62 -> V_256 . V_310 ( V_250 , V_262 + sizeof( * V_253 ) ) ;
V_296:
F_26 () ;
return V_27 ;
}
int F_126 ( struct V_1 * * V_2 , unsigned short V_311 ,
unsigned short type , unsigned char V_44 ,
struct V_43 * V_43 )
{
struct V_24 * V_1 ;
int V_312 = F_127 ( V_311 , type , V_44 , & V_1 ) ;
if ( V_312 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_313 = V_314 ;
( * V_2 ) -> V_20 -> V_315 ( * V_2 ) ;
F_128 ( * V_2 , V_43 ) ;
}
return V_312 ;
}
unsigned long F_129 ( void T_6 * V_316 , int V_317 )
{
unsigned long V_318 = 0 ;
int V_319 ;
F_130 (i)
V_318 += * ( ( ( unsigned long * ) F_131 ( V_316 , V_319 ) ) + V_317 ) ;
return V_318 ;
}
T_7 F_132 ( void T_6 * V_316 , int V_317 , T_2 V_320 )
{
T_7 V_318 = 0 ;
int V_321 ;
F_130 (cpu) {
void * V_322 ;
struct V_323 * V_324 ;
T_7 V_325 ;
unsigned int V_326 ;
V_322 = F_131 ( V_316 , V_321 ) ;
V_324 = (struct V_323 * ) ( V_322 + V_320 ) ;
do {
V_326 = F_133 ( V_324 ) ;
V_325 = * ( ( ( T_7 * ) V_322 ) + V_317 ) ;
} while ( F_134 ( V_324 , V_326 ) );
V_318 += V_325 ;
}
return V_318 ;
}
static T_8 int F_135 ( struct V_43 * V_43 )
{
int V_319 ;
V_43 -> V_316 . V_327 = F_136 ( struct V_328 ) ;
if ( ! V_43 -> V_316 . V_327 )
goto V_329;
V_43 -> V_316 . V_330 = F_136 ( struct V_331 ) ;
if ( ! V_43 -> V_316 . V_330 )
goto V_332;
F_130 (i) {
struct V_331 * V_333 ;
V_333 = F_131 ( V_43 -> V_316 . V_330 , V_319 ) ;
F_137 ( & V_333 -> V_324 ) ;
}
V_43 -> V_316 . V_334 = F_136 ( struct V_335 ) ;
if ( ! V_43 -> V_316 . V_334 )
goto V_336;
V_43 -> V_316 . V_337 = F_136 ( struct V_338 ) ;
if ( ! V_43 -> V_316 . V_337 )
goto V_339;
V_43 -> V_316 . V_340 = F_136 ( struct V_338 ) ;
if ( ! V_43 -> V_316 . V_340 )
goto V_341;
V_43 -> V_316 . V_342 = F_136 ( struct V_343 ) ;
if ( ! V_43 -> V_316 . V_342 )
goto V_344;
V_43 -> V_316 . V_345 = F_138 ( sizeof( struct V_346 ) ,
V_67 ) ;
if ( ! V_43 -> V_316 . V_345 )
goto V_347;
F_139 ( V_43 ) ;
return 0 ;
V_347:
F_140 ( V_43 -> V_316 . V_342 ) ;
V_344:
F_140 ( V_43 -> V_316 . V_340 ) ;
V_341:
F_140 ( V_43 -> V_316 . V_337 ) ;
V_339:
F_140 ( V_43 -> V_316 . V_334 ) ;
V_336:
F_140 ( V_43 -> V_316 . V_330 ) ;
V_332:
F_140 ( V_43 -> V_316 . V_327 ) ;
V_329:
return - V_348 ;
}
static T_9 void F_141 ( struct V_43 * V_43 )
{
F_9 ( V_43 -> V_316 . V_345 ) ;
F_140 ( V_43 -> V_316 . V_342 ) ;
F_140 ( V_43 -> V_316 . V_340 ) ;
F_140 ( V_43 -> V_316 . V_337 ) ;
F_140 ( V_43 -> V_316 . V_334 ) ;
F_140 ( V_43 -> V_316 . V_330 ) ;
F_140 ( V_43 -> V_316 . V_327 ) ;
}
static int T_10 F_142 ( void )
{
return F_143 ( & V_349 ) ;
}
static T_8 int F_144 ( struct V_43 * V_43 )
{
F_145 ( & V_43 -> V_76 . V_350 . V_351 ) ;
V_43 -> V_76 . V_350 . V_352 [ 0 ] = 32768 ;
V_43 -> V_76 . V_350 . V_352 [ 1 ] = 61000 ;
F_145 ( & V_43 -> V_76 . V_353 . V_351 ) ;
V_43 -> V_76 . V_353 . V_352 [ 0 ] = F_146 ( & V_354 , 1 ) ;
V_43 -> V_76 . V_353 . V_352 [ 1 ] = F_146 ( & V_354 , 0 ) ;
return 0 ;
}
static T_9 void F_147 ( struct V_43 * V_43 )
{
}
static int T_10 F_148 ( void )
{
return F_143 ( & V_355 ) ;
}
static int T_10 F_149 ( void )
{
if ( F_150 () < 0 )
F_151 ( L_9 , V_246 ) ;
if ( F_152 () < 0 )
F_151 ( L_10 , V_246 ) ;
F_153 ( & V_356 ) ;
F_154 ( & V_357 , V_358 ) ;
return 0 ;
}
static int T_10 F_155 ( void )
{
struct V_46 * V_359 ;
struct V_217 * V_360 ;
int V_312 = - V_28 ;
F_156 ( sizeof( struct V_361 ) > F_157 ( struct V_249 , V_362 ) ) ;
V_312 = F_158 ( & V_363 , 1 ) ;
if ( V_312 )
goto V_31;
V_312 = F_158 ( & V_364 , 1 ) ;
if ( V_312 )
goto V_365;
V_312 = F_158 ( & V_366 , 1 ) ;
if ( V_312 )
goto V_367;
V_312 = F_158 ( & V_368 , 1 ) ;
if ( V_312 )
goto V_369;
( void ) F_159 ( & V_370 ) ;
#ifdef F_160
F_161 () ;
#endif
if ( F_162 ( & V_371 , V_372 ) < 0 )
F_151 ( L_11 , V_246 ) ;
if ( F_162 ( & V_373 , V_281 ) < 0 )
F_151 ( L_12 , V_246 ) ;
if ( F_162 ( & V_374 , V_153 ) < 0 )
F_151 ( L_13 , V_246 ) ;
#ifdef F_163
if ( F_162 ( & V_375 , V_376 ) < 0 )
F_151 ( L_14 , V_246 ) ;
#endif
for ( V_360 = & V_223 [ 0 ] ; V_360 < & V_223 [ V_221 ] ; ++ V_360 )
F_164 ( V_360 ) ;
for ( V_359 = V_377 ; V_359 < & V_377 [ V_378 ] ; ++ V_359 )
F_72 ( V_359 ) ;
F_165 () ;
F_166 () ;
F_167 () ;
F_168 () ;
F_169 () ;
F_170 () ;
F_171 () ;
if ( F_172 () < 0 )
F_173 ( L_15 ) ;
#if F_174 ( V_379 )
if ( F_175 () )
F_151 ( L_16 , V_246 ) ;
#endif
if ( F_148 () )
F_151 ( L_17 , V_246 ) ;
if ( F_142 () )
F_151 ( L_18 , V_246 ) ;
F_176 () ;
F_177 () ;
F_178 ( & V_380 ) ;
V_312 = 0 ;
V_31:
return V_312 ;
V_369:
F_179 ( & V_366 ) ;
V_367:
F_179 ( & V_364 ) ;
V_365:
F_179 ( & V_363 ) ;
goto V_31;
}
static int T_10 F_176 ( void )
{
int V_312 = 0 ;
if ( F_180 () )
goto V_381;
if ( F_181 () )
goto V_382;
if ( F_182 () )
goto V_383;
if ( F_183 () )
goto V_384;
if ( F_184 () )
goto V_385;
V_31:
return V_312 ;
V_385:
F_185 () ;
V_384:
F_186 () ;
V_383:
F_187 () ;
V_382:
F_188 () ;
V_381:
V_312 = - V_348 ;
goto V_31;
}
static int T_10 F_176 ( void )
{
return 0 ;
}
