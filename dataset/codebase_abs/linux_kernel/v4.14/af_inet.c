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
F_7 ( F_9 ( & V_2 -> V_13 ) ) ;
F_7 ( V_2 -> V_14 ) ;
F_7 ( V_2 -> V_15 ) ;
F_10 ( F_11 ( V_4 -> V_16 , 1 ) ) ;
F_12 ( F_13 ( V_2 -> V_17 , 1 ) ) ;
F_12 ( V_2 -> V_18 ) ;
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_16 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_19 ) {
if ( V_2 -> V_20 -> V_21 ( V_2 , 0 ) ) {
F_17 ( V_2 ) ;
return - V_22 ;
}
V_4 -> V_23 = F_18 ( V_4 -> V_19 ) ;
}
F_17 ( V_2 ) ;
return 0 ;
}
int F_19 ( struct V_24 * V_1 , int V_25 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned char V_26 ;
int V_27 ;
F_16 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_1 -> V_29 != V_30 || V_1 -> type != V_8 )
goto V_31;
V_26 = V_2 -> V_9 ;
if ( ! ( ( 1 << V_26 ) & ( V_32 | V_33 ) ) )
goto V_31;
if ( V_26 != V_34 ) {
if ( ( V_35 & V_36 ) &&
( V_35 & V_37 ) &&
! F_20 ( V_2 ) -> V_38 . V_39 . V_40 ) {
F_21 ( V_2 , V_25 ) ;
F_22 ( true ) ;
}
V_27 = F_23 ( V_2 , V_25 ) ;
if ( V_27 )
goto V_31;
}
V_2 -> V_41 = V_25 ;
V_27 = 0 ;
V_31:
F_17 ( V_2 ) ;
return V_27 ;
}
static int F_24 ( struct V_42 * V_42 , struct V_24 * V_1 , int V_43 ,
int V_44 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
struct V_3 * V_4 ;
struct V_47 * V_48 ;
unsigned char V_49 ;
int V_50 = 0 ;
int V_27 ;
if ( V_43 < 0 || V_43 >= V_51 )
return - V_28 ;
V_1 -> V_29 = V_30 ;
V_52:
V_27 = - V_53 ;
F_25 () ;
F_26 (answer, &inetsw[sock->type], list) {
V_27 = 0 ;
if ( V_43 == V_46 -> V_43 ) {
if ( V_43 != V_54 )
break;
} else {
if ( V_54 == V_43 ) {
V_43 = V_46 -> V_43 ;
break;
}
if ( V_54 == V_46 -> V_43 )
break;
}
V_27 = - V_55 ;
}
if ( F_27 ( V_27 ) ) {
if ( V_50 < 2 ) {
F_28 () ;
if ( ++ V_50 == 1 )
F_29 ( L_3 ,
V_56 , V_43 , V_1 -> type ) ;
else
F_29 ( L_4 ,
V_56 , V_43 ) ;
goto V_52;
} else
goto V_57;
}
V_27 = - V_58 ;
if ( V_1 -> type == V_59 && ! V_44 &&
! F_30 ( V_42 -> V_60 , V_61 ) )
goto V_57;
V_1 -> V_62 = V_46 -> V_62 ;
V_48 = V_46 -> V_63 ;
V_49 = V_46 -> V_64 ;
F_28 () ;
F_7 ( ! V_48 -> V_65 ) ;
V_27 = - V_66 ;
V_2 = F_31 ( V_42 , V_56 , V_67 , V_48 , V_44 ) ;
if ( ! V_2 )
goto V_31;
V_27 = 0 ;
if ( V_68 & V_49 )
V_2 -> V_69 = V_70 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_71 = ( V_72 & V_49 ) != 0 ;
V_4 -> V_73 = 0 ;
if ( V_59 == V_1 -> type ) {
V_4 -> V_19 = V_43 ;
if ( V_74 == V_43 )
V_4 -> V_75 = 1 ;
}
if ( V_42 -> V_76 . V_77 )
V_4 -> V_78 = V_79 ;
else
V_4 -> V_78 = V_80 ;
V_4 -> V_81 = 0 ;
F_32 ( V_1 , V_2 ) ;
V_2 -> V_82 = F_1 ;
V_2 -> V_83 = V_43 ;
V_2 -> V_84 = V_2 -> V_20 -> V_85 ;
V_4 -> V_86 = - 1 ;
V_4 -> V_87 = 1 ;
V_4 -> V_88 = 1 ;
V_4 -> V_89 = 1 ;
V_4 -> V_90 = 0 ;
V_4 -> V_91 = NULL ;
V_4 -> V_92 = 0 ;
F_33 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_18 ( V_4 -> V_19 ) ;
V_27 = V_2 -> V_20 -> V_93 ( V_2 ) ;
if ( V_27 ) {
F_34 ( V_2 ) ;
goto V_31;
}
}
if ( V_2 -> V_20 -> V_94 ) {
V_27 = V_2 -> V_20 -> V_94 ( V_2 ) ;
if ( V_27 ) {
F_34 ( V_2 ) ;
goto V_31;
}
}
if ( ! V_44 ) {
V_27 = F_35 ( V_2 ) ;
if ( V_27 ) {
F_34 ( V_2 ) ;
goto V_31;
}
}
V_31:
return V_27 ;
V_57:
F_28 () ;
goto V_31;
}
int F_36 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_95 ;
F_37 ( V_2 ) ;
V_95 = 0 ;
if ( F_6 ( V_2 , V_96 ) &&
! ( V_97 -> V_64 & V_98 ) )
V_95 = V_2 -> V_99 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_100 ( V_2 , V_95 ) ;
}
return 0 ;
}
int F_38 ( struct V_24 * V_1 , struct V_101 * V_102 , int V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_42 = F_39 ( V_2 ) ;
unsigned short V_106 ;
int V_107 ;
T_1 V_108 = V_109 ;
int V_27 ;
if ( V_2 -> V_20 -> V_110 ) {
V_27 = V_2 -> V_20 -> V_110 ( V_2 , V_102 , V_103 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_103 < sizeof( struct V_104 ) )
goto V_31;
if ( V_105 -> V_111 != V_112 ) {
V_27 = - V_113 ;
if ( V_105 -> V_111 != V_114 ||
V_105 -> V_115 . V_116 != F_40 ( V_117 ) )
goto V_31;
}
V_108 = F_41 ( V_42 , V_2 -> V_118 ) ? : V_108 ;
V_107 = F_42 ( V_42 , V_105 -> V_115 . V_116 , V_108 ) ;
V_27 = - V_119 ;
if ( ! V_42 -> V_76 . V_120 &&
! ( V_4 -> V_121 || V_4 -> V_122 ) &&
V_105 -> V_115 . V_116 != F_40 ( V_117 ) &&
V_107 != V_123 &&
V_107 != V_124 &&
V_107 != V_125 )
goto V_31;
V_106 = F_43 ( V_105 -> V_126 ) ;
V_27 = - V_127 ;
if ( V_106 && V_106 < F_44 ( V_42 ) &&
! F_30 ( V_42 -> V_60 , V_128 ) )
goto V_31;
F_16 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_129;
V_4 -> V_130 = V_4 -> V_131 = V_105 -> V_115 . V_116 ;
if ( V_107 == V_124 || V_107 == V_125 )
V_4 -> V_131 = 0 ;
if ( ( V_106 || ! V_4 -> V_132 ) &&
V_2 -> V_20 -> V_21 ( V_2 , V_106 ) ) {
V_4 -> V_131 = V_4 -> V_130 = 0 ;
V_27 = - V_133 ;
goto V_129;
}
if ( V_4 -> V_130 )
V_2 -> V_134 |= V_135 ;
if ( V_106 )
V_2 -> V_134 |= V_136 ;
V_4 -> V_23 = F_18 ( V_4 -> V_19 ) ;
V_4 -> V_137 = 0 ;
V_4 -> V_138 = 0 ;
F_45 ( V_2 ) ;
V_27 = 0 ;
V_129:
F_17 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_46 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_103 < sizeof( V_102 -> V_139 ) )
return - V_28 ;
if ( V_102 -> V_139 == V_114 )
return V_2 -> V_20 -> V_140 ( V_2 , V_64 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_15 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_141 ( V_2 , V_102 , V_103 ) ;
}
static long F_47 ( struct V_1 * V_2 , long V_142 , int V_143 )
{
F_48 ( V_144 , V_145 ) ;
F_49 ( F_50 ( V_2 ) , & V_144 ) ;
V_2 -> V_146 += V_143 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_147 | V_148 ) ) {
F_17 ( V_2 ) ;
V_142 = F_51 ( & V_144 , V_149 , V_142 ) ;
F_16 ( V_2 ) ;
if ( F_52 ( V_97 ) || ! V_142 )
break;
}
F_53 ( F_50 ( V_2 ) , & V_144 ) ;
V_2 -> V_146 -= V_143 ;
return V_142 ;
}
int F_54 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 , int V_150 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_142 ;
if ( V_102 ) {
if ( V_103 < sizeof( V_102 -> V_139 ) )
return - V_28 ;
if ( V_102 -> V_139 == V_114 ) {
V_27 = V_2 -> V_20 -> V_140 ( V_2 , V_64 ) ;
V_1 -> V_29 = V_27 ? V_151 : V_30 ;
goto V_31;
}
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_152 :
V_27 = - V_153 ;
goto V_31;
case V_154 :
if ( F_2 ( V_2 ) -> V_155 )
V_27 = V_150 ? - V_156 : - V_153 ;
else
V_27 = - V_157 ;
break;
case V_30 :
V_27 = - V_153 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_141 ( V_2 , V_102 , V_103 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_154 ;
if ( ! V_27 && F_2 ( V_2 ) -> V_155 )
goto V_31;
V_27 = - V_156 ;
break;
}
V_142 = F_55 ( V_2 , V_64 & V_158 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_147 | V_148 ) ) {
int V_143 = ( V_2 -> V_83 == V_159 ) &&
F_56 ( V_2 ) -> V_160 &&
F_56 ( V_2 ) -> V_160 -> V_161 ? 1 : 0 ;
if ( ! V_142 || ! F_47 ( V_2 , V_142 , V_143 ) )
goto V_31;
V_27 = F_57 ( V_142 ) ;
if ( F_52 ( V_97 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_162;
V_1 -> V_29 = V_152 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_162:
V_27 = V_162 ( V_2 ) ? : - V_163 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_140 ( V_2 , V_64 ) )
V_1 -> V_29 = V_151 ;
goto V_31;
}
int F_58 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
int V_27 ;
F_16 ( V_1 -> V_2 ) ;
V_27 = F_54 ( V_1 , V_102 , V_103 , V_64 , 0 ) ;
F_17 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_59 ( struct V_24 * V_1 , struct V_24 * V_164 , int V_64 ,
bool V_44 )
{
struct V_1 * V_165 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_166 = V_165 -> V_20 -> V_167 ( V_165 , V_64 , & V_27 , V_44 ) ;
if ( ! V_166 )
goto V_168;
F_16 ( V_166 ) ;
F_60 ( V_166 ) ;
F_7 ( ! ( ( 1 << V_166 -> V_9 ) &
( V_169 | V_148 |
V_170 | V_32 ) ) ) ;
F_61 ( V_166 , V_164 ) ;
V_164 -> V_29 = V_152 ;
V_27 = 0 ;
F_17 ( V_166 ) ;
V_168:
return V_27 ;
}
int F_62 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int * V_171 , int V_172 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_63 ( struct V_104 * , sin , V_102 ) ;
sin -> V_111 = V_112 ;
if ( V_172 ) {
if ( ! V_4 -> V_138 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_147 ) ) &&
V_172 == 1 ) )
return - V_173 ;
sin -> V_126 = V_4 -> V_138 ;
sin -> V_115 . V_116 = V_4 -> V_137 ;
} else {
T_2 V_105 = V_4 -> V_130 ;
if ( ! V_105 )
V_105 = V_4 -> V_131 ;
sin -> V_126 = V_4 -> V_23 ;
sin -> V_115 . V_116 = V_105 ;
}
memset ( sin -> V_174 , 0 , sizeof( sin -> V_174 ) ) ;
* V_171 = sizeof( * sin ) ;
return 0 ;
}
int F_64 ( struct V_24 * V_1 , struct V_175 * V_176 , T_3 V_177 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_60 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_178 &&
F_15 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_179 ( V_2 , V_176 , V_177 ) ;
}
T_4 F_65 ( struct V_24 * V_1 , struct V_180 * V_180 , int V_181 ,
T_3 V_177 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_60 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_178 &&
F_15 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_182 )
return V_2 -> V_20 -> V_182 ( V_2 , V_180 , V_181 , V_177 , V_64 ) ;
return F_66 ( V_1 , V_180 , V_181 , V_177 , V_64 ) ;
}
int F_67 ( struct V_24 * V_1 , struct V_175 * V_176 , T_3 V_177 ,
int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_103 = 0 ;
int V_27 ;
F_60 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_183 ( V_2 , V_176 , V_177 , V_64 & V_184 ,
V_64 & ~ V_184 , & V_103 ) ;
if ( V_27 >= 0 )
V_176 -> V_185 = V_103 ;
return V_27 ;
}
int F_68 ( struct V_24 * V_1 , int V_186 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_186 ++ ;
if ( ( V_186 & ~ V_187 ) || ! V_186 )
return - V_28 ;
F_16 ( V_2 ) ;
if ( V_1 -> V_29 == V_154 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_147 | V_148 | V_32 ) )
V_1 -> V_29 = V_151 ;
else
V_1 -> V_29 = V_152 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_173 ;
default:
V_2 -> V_188 |= V_186 ;
if ( V_2 -> V_20 -> V_189 )
V_2 -> V_20 -> V_189 ( V_2 , V_186 ) ;
break;
case V_34 :
if ( ! ( V_186 & V_190 ) )
break;
case V_191 :
V_27 = V_2 -> V_20 -> V_140 ( V_2 , V_158 ) ;
V_1 -> V_29 = V_27 ? V_151 : V_30 ;
break;
}
V_2 -> V_192 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_27 ;
}
int F_69 ( struct V_24 * V_1 , unsigned int V_193 , unsigned long V_194 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_42 * V_42 = F_39 ( V_2 ) ;
switch ( V_193 ) {
case V_195 :
V_27 = F_70 ( V_2 , (struct V_196 V_197 * ) V_194 ) ;
break;
case V_198 :
V_27 = F_71 ( V_2 , (struct V_199 V_197 * ) V_194 ) ;
break;
case V_200 :
case V_201 :
case V_202 :
V_27 = F_72 ( V_42 , V_193 , ( void V_197 * ) V_194 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
V_27 = F_73 ( V_42 , V_193 , ( void V_197 * ) V_194 ) ;
break;
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
case V_216 :
V_27 = F_74 ( V_42 , V_193 , ( void V_197 * ) V_194 ) ;
break;
default:
if ( V_2 -> V_20 -> V_217 )
V_27 = V_2 -> V_20 -> V_217 ( V_2 , V_193 , V_194 ) ;
else
V_27 = - V_218 ;
break;
}
return V_27 ;
}
static int F_75 ( struct V_24 * V_1 , unsigned int V_193 , unsigned long V_194 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_218 ;
if ( V_2 -> V_20 -> V_219 )
V_27 = V_2 -> V_20 -> V_219 ( V_2 , V_193 , V_194 ) ;
return V_27 ;
}
void F_76 ( struct V_45 * V_220 )
{
struct V_221 * V_222 ;
struct V_45 * V_46 ;
int V_43 = V_220 -> V_43 ;
struct V_221 * V_223 ;
F_77 ( & V_224 ) ;
if ( V_220 -> type >= V_225 )
goto V_226;
V_223 = & V_227 [ V_220 -> type ] ;
F_78 (lh, &inetsw[p->type]) {
V_46 = F_79 ( V_222 , struct V_45 , V_228 ) ;
if ( ( V_229 & V_46 -> V_64 ) == 0 )
break;
if ( V_43 == V_46 -> V_43 )
goto V_230;
V_223 = V_222 ;
}
F_80 ( & V_220 -> V_228 , V_223 ) ;
V_31:
F_81 ( & V_224 ) ;
return;
V_230:
F_5 ( L_5 , V_43 ) ;
goto V_31;
V_226:
F_5 ( L_6 ,
V_220 -> type ) ;
goto V_31;
}
void F_82 ( struct V_45 * V_220 )
{
if ( V_229 & V_220 -> V_64 ) {
F_5 ( L_7 ,
V_220 -> V_43 ) ;
} else {
F_77 ( & V_224 ) ;
F_83 ( & V_220 -> V_228 ) ;
F_81 ( & V_224 ) ;
F_84 () ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_231 = V_4 -> V_131 ;
T_2 V_232 = V_4 -> V_137 ;
struct V_233 * V_234 ;
struct V_235 * V_236 ;
T_2 V_237 ;
struct V_238 * V_16 ;
V_16 = F_11 ( V_4 -> V_16 ,
F_86 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_239 . V_240 )
V_232 = V_16 -> V_239 . V_241 ;
V_234 = & V_4 -> V_242 . V_243 . V_244 . V_245 ;
V_236 = F_87 ( V_234 , V_232 , 0 , F_88 ( V_2 ) ,
V_2 -> V_118 , V_2 -> V_83 ,
V_4 -> V_23 , V_4 -> V_138 , V_2 ) ;
if ( F_89 ( V_236 ) )
return F_90 ( V_236 ) ;
F_91 ( V_2 , & V_236 -> V_246 ) ;
V_237 = V_234 -> V_247 ;
if ( V_237 == V_231 )
return 0 ;
if ( F_39 ( V_2 ) -> V_76 . V_248 > 1 ) {
F_92 ( L_8 ,
V_249 , & V_231 , & V_237 ) ;
}
V_4 -> V_131 = V_4 -> V_130 = V_237 ;
return F_93 ( V_2 ) ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_235 * V_236 = (struct V_235 * ) F_95 ( V_2 , 0 ) ;
T_2 V_232 ;
struct V_238 * V_16 ;
struct V_233 * V_234 ;
int V_27 ;
if ( V_236 )
return 0 ;
F_25 () ;
V_16 = F_96 ( V_4 -> V_16 ) ;
V_232 = V_4 -> V_137 ;
if ( V_16 && V_16 -> V_239 . V_240 )
V_232 = V_16 -> V_239 . V_241 ;
F_28 () ;
V_234 = & V_4 -> V_242 . V_243 . V_244 . V_245 ;
V_236 = F_97 ( F_39 ( V_2 ) , V_234 , V_2 , V_232 , V_4 -> V_131 ,
V_4 -> V_138 , V_4 -> V_23 ,
V_2 -> V_83 , F_88 ( V_2 ) ,
V_2 -> V_118 ) ;
if ( ! F_89 ( V_236 ) ) {
V_27 = 0 ;
F_91 ( V_2 , & V_236 -> V_246 ) ;
} else {
V_27 = F_90 ( V_236 ) ;
V_2 -> V_250 = 0 ;
if ( ! F_39 ( V_2 ) -> V_76 . V_248 ||
V_2 -> V_9 != V_191 ||
( V_2 -> V_134 & V_135 ) ||
( V_27 = F_85 ( V_2 ) ) != 0 )
V_2 -> V_251 = - V_27 ;
}
return V_27 ;
}
struct V_252 * F_98 ( struct V_252 * V_253 ,
T_5 V_254 )
{
bool V_255 = false , V_256 , V_257 ;
struct V_252 * V_258 = F_99 ( - V_28 ) ;
const struct V_259 * V_62 ;
struct V_260 * V_261 ;
int V_47 , V_262 ;
int V_263 ;
int V_264 ;
int V_265 ;
F_100 ( V_253 ) ;
V_263 = F_101 ( V_253 ) - F_102 ( V_253 ) ;
if ( F_27 ( ! F_103 ( V_253 , sizeof( * V_261 ) ) ) )
goto V_31;
V_261 = F_104 ( V_253 ) ;
V_264 = V_261 -> V_264 * 4 ;
if ( V_264 < sizeof( * V_261 ) )
goto V_31;
V_265 = F_43 ( V_261 -> V_265 ) ;
V_47 = V_261 -> V_43 ;
if ( F_27 ( ! F_103 ( V_253 , V_264 ) ) )
goto V_31;
F_105 ( V_253 , V_264 ) ;
V_257 = F_106 ( V_253 ) -> V_266 > 0 ;
if ( V_257 )
V_254 &= V_253 -> V_267 -> V_268 ;
F_106 ( V_253 ) -> V_266 += V_264 ;
F_107 ( V_253 ) ;
V_258 = F_99 ( - V_55 ) ;
if ( ! V_253 -> V_269 || V_257 ) {
V_255 = ! ! ( F_108 ( V_253 ) -> V_270 & V_271 ) ;
if ( V_255 && ! ( F_104 ( V_253 ) -> V_272 & F_18 ( V_273 ) ) )
goto V_31;
}
V_62 = F_96 ( V_274 [ V_47 ] ) ;
if ( F_109 ( V_62 && V_62 -> V_275 . V_276 ) )
V_258 = V_62 -> V_275 . V_276 ( V_253 , V_254 ) ;
if ( F_110 ( V_258 ) )
goto V_31;
V_256 = ! ! ( F_108 ( V_258 ) -> V_270 & V_277 ) ;
V_253 = V_258 ;
do {
V_261 = (struct V_260 * ) ( F_102 ( V_253 ) + V_263 ) ;
if ( F_111 ( V_253 ) ) {
if ( ! V_255 ) {
V_261 -> V_265 = F_18 ( V_265 ) ;
V_265 += F_108 ( V_253 ) -> V_278 ;
}
if ( V_256 )
V_262 = F_108 ( V_253 ) -> V_279 +
F_106 ( V_253 ) -> V_280 +
V_253 -> V_281 - ( unsigned char * ) V_261 ;
else
V_262 = V_253 -> V_282 - V_263 ;
} else {
if ( ! V_255 )
V_261 -> V_265 = F_18 ( V_265 ++ ) ;
V_262 = V_253 -> V_282 - V_263 ;
}
V_261 -> V_262 = F_18 ( V_262 ) ;
F_112 ( V_261 ) ;
if ( V_257 )
F_113 ( V_253 ) ;
V_253 -> V_283 = ( V_284 * ) V_261 - V_253 -> V_281 ;
} while ( ( V_253 = V_253 -> V_285 ) );
V_31:
return V_258 ;
}
struct V_252 * * F_114 ( struct V_252 * * V_281 , struct V_252 * V_253 )
{
const struct V_259 * V_62 ;
struct V_252 * * V_286 = NULL ;
struct V_252 * V_220 ;
const struct V_260 * V_261 ;
unsigned int V_287 ;
unsigned int V_288 ;
unsigned int V_265 ;
int V_289 = 1 ;
int V_47 ;
V_288 = F_115 ( V_253 ) ;
V_287 = V_288 + sizeof( * V_261 ) ;
V_261 = F_116 ( V_253 , V_288 ) ;
if ( F_117 ( V_253 , V_287 ) ) {
V_261 = F_118 ( V_253 , V_287 , V_288 ) ;
if ( F_27 ( ! V_261 ) )
goto V_31;
}
V_47 = V_261 -> V_43 ;
F_25 () ;
V_62 = F_96 ( V_274 [ V_47 ] ) ;
if ( ! V_62 || ! V_62 -> V_275 . V_290 )
goto V_291;
if ( * ( V_284 * ) V_261 != 0x45 )
goto V_291;
if ( F_119 ( V_261 ) )
goto V_291;
if ( F_27 ( F_120 ( ( V_284 * ) V_261 , 5 ) ) )
goto V_291;
V_265 = F_121 ( * ( T_2 * ) & V_261 -> V_265 ) ;
V_289 = ( V_292 ) ( ( F_121 ( * ( T_2 * ) V_261 ) ^ F_122 ( V_253 ) ) | ( V_265 & ~ V_273 ) ) ;
V_265 >>= 16 ;
for ( V_220 = * V_281 ; V_220 ; V_220 = V_220 -> V_285 ) {
struct V_260 * V_293 ;
V_292 V_294 ;
if ( ! F_123 ( V_220 ) -> V_295 )
continue;
V_293 = (struct V_260 * ) ( V_220 -> V_161 + V_288 ) ;
if ( ( V_261 -> V_43 ^ V_293 -> V_43 ) |
( ( V_296 T_1 ) V_261 -> V_247 ^ ( V_296 T_1 ) V_293 -> V_247 ) |
( ( V_296 T_1 ) V_261 -> V_232 ^ ( V_296 T_1 ) V_293 -> V_232 ) ) {
F_123 ( V_220 ) -> V_295 = 0 ;
continue;
}
F_123 ( V_220 ) -> V_289 |=
( V_261 -> V_297 ^ V_293 -> V_297 ) |
( V_261 -> V_298 ^ V_293 -> V_298 ) |
( ( V_261 -> V_272 ^ V_293 -> V_272 ) & F_18 ( V_273 ) ) ;
F_123 ( V_220 ) -> V_289 |= V_289 ;
V_294 = ( V_292 ) ( V_265 - F_43 ( V_293 -> V_265 ) ) ;
if ( ! F_123 ( V_220 ) -> V_299 ||
! ( V_261 -> V_272 & F_18 ( V_273 ) ) ) {
V_294 ^= F_123 ( V_220 ) -> V_300 ;
V_294 = V_294 ? 0xFFFF : 0 ;
}
if ( F_123 ( V_253 ) -> V_299 )
F_123 ( V_220 ) -> V_294 = V_294 ;
else
F_123 ( V_220 ) -> V_294 |= V_294 ;
}
F_123 ( V_253 ) -> V_299 = ! ! ( V_261 -> V_272 & F_18 ( V_273 ) ) ;
F_123 ( V_253 ) -> V_289 |= V_289 ;
F_124 ( V_253 , V_288 ) ;
F_125 ( V_253 , sizeof( * V_261 ) ) ;
F_126 ( V_253 , F_115 ( V_253 ) ) ;
V_286 = F_127 ( V_62 -> V_275 . V_290 , V_281 , V_253 ) ;
V_291:
F_28 () ;
V_31:
F_128 ( V_253 , V_286 , V_289 ) ;
return V_286 ;
}
static struct V_252 * * F_129 ( struct V_252 * * V_281 ,
struct V_252 * V_253 )
{
if ( F_123 ( V_253 ) -> V_301 ) {
F_123 ( V_253 ) -> V_289 = 1 ;
return NULL ;
}
F_123 ( V_253 ) -> V_301 = 1 ;
return F_114 ( V_281 , V_253 ) ;
}
T_2 F_130 ( void )
{
T_1 V_302 ;
T_1 V_303 ;
struct V_304 V_305 ;
F_131 ( & V_305 ) ;
( void ) F_132 ( V_305 . V_306 , V_307 , & V_302 ) ;
V_303 = V_302 * V_308 ;
V_303 += ( T_1 ) V_305 . V_309 / V_310 ;
return F_40 ( V_303 ) ;
}
int F_133 ( struct V_1 * V_2 , struct V_175 * V_176 , int V_282 , int * V_103 )
{
if ( V_2 -> V_311 == V_112 )
return F_134 ( V_2 , V_176 , V_282 , V_103 ) ;
#if F_135 ( V_312 )
if ( V_2 -> V_311 == V_313 )
return V_314 . V_315 ( V_2 , V_176 , V_282 , V_103 ) ;
#endif
return - V_28 ;
}
int F_136 ( struct V_252 * V_253 , int V_263 )
{
T_6 V_316 = F_18 ( V_253 -> V_282 - V_263 ) ;
struct V_260 * V_261 = (struct V_260 * ) ( V_253 -> V_161 + V_263 ) ;
const struct V_259 * V_62 ;
int V_47 = V_261 -> V_43 ;
int V_27 = - V_317 ;
if ( V_253 -> V_269 ) {
F_137 ( V_253 , F_138 ( V_318 ) ) ;
F_139 ( V_253 , V_263 ) ;
}
F_140 ( & V_261 -> V_319 , V_261 -> V_262 , V_316 ) ;
V_261 -> V_262 = V_316 ;
F_25 () ;
V_62 = F_96 ( V_274 [ V_47 ] ) ;
if ( F_7 ( ! V_62 || ! V_62 -> V_275 . V_320 ) )
goto V_291;
V_27 = V_62 -> V_275 . V_320 ( V_253 , V_263 + sizeof( * V_261 ) ) ;
V_291:
F_28 () ;
return V_27 ;
}
static int F_141 ( struct V_252 * V_253 , int V_263 )
{
V_253 -> V_269 = 1 ;
F_108 ( V_253 ) -> V_270 |= V_321 ;
return F_136 ( V_253 , V_263 ) ;
}
int F_142 ( struct V_1 * * V_2 , unsigned short V_322 ,
unsigned short type , unsigned char V_43 ,
struct V_42 * V_42 )
{
struct V_24 * V_1 ;
int V_323 = F_143 ( V_42 , V_322 , type , V_43 , & V_1 ) ;
if ( V_323 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_324 = V_325 ;
( * V_2 ) -> V_20 -> V_326 ( * V_2 ) ;
}
return V_323 ;
}
T_7 F_144 ( void T_8 * V_327 , int V_328 , int V_329 )
{
return * ( ( ( unsigned long * ) F_145 ( V_327 , V_328 ) ) + V_329 ) ;
}
unsigned long F_146 ( void T_8 * V_327 , int V_329 )
{
unsigned long V_330 = 0 ;
int V_331 ;
F_147 (i)
V_330 += F_144 ( V_327 , V_331 , V_329 ) ;
return V_330 ;
}
T_7 F_148 ( void T_8 * V_327 , int V_328 , int V_329 ,
T_3 V_332 )
{
void * V_333 ;
struct V_334 * V_335 ;
T_7 V_336 ;
unsigned int V_337 ;
V_333 = F_145 ( V_327 , V_328 ) ;
V_335 = (struct V_334 * ) ( V_333 + V_332 ) ;
do {
V_337 = F_149 ( V_335 ) ;
V_336 = * ( ( ( T_7 * ) V_333 ) + V_329 ) ;
} while ( F_150 ( V_335 , V_337 ) );
return V_336 ;
}
T_7 F_151 ( void T_8 * V_327 , int V_329 , T_3 V_332 )
{
T_7 V_330 = 0 ;
int V_328 ;
F_147 (cpu) {
V_330 += F_148 ( V_327 , V_328 , V_329 , V_332 ) ;
}
return V_330 ;
}
static T_9 int F_152 ( struct V_42 * V_42 )
{
int V_331 ;
V_42 -> V_327 . V_338 = F_153 ( struct V_339 ) ;
if ( ! V_42 -> V_327 . V_338 )
goto V_340;
V_42 -> V_327 . V_341 = F_153 ( struct V_342 ) ;
if ( ! V_42 -> V_327 . V_341 )
goto V_343;
F_147 (i) {
struct V_342 * V_344 ;
V_344 = F_145 ( V_42 -> V_327 . V_341 , V_331 ) ;
F_154 ( & V_344 -> V_335 ) ;
}
V_42 -> V_327 . V_345 = F_153 ( struct V_346 ) ;
if ( ! V_42 -> V_327 . V_345 )
goto V_347;
V_42 -> V_327 . V_348 = F_153 ( struct V_349 ) ;
if ( ! V_42 -> V_327 . V_348 )
goto V_350;
V_42 -> V_327 . V_351 = F_153 ( struct V_349 ) ;
if ( ! V_42 -> V_327 . V_351 )
goto V_352;
V_42 -> V_327 . V_353 = F_153 ( struct V_354 ) ;
if ( ! V_42 -> V_327 . V_353 )
goto V_355;
V_42 -> V_327 . V_356 = F_155 ( sizeof( struct V_357 ) ,
V_67 ) ;
if ( ! V_42 -> V_327 . V_356 )
goto V_358;
F_156 ( V_42 ) ;
return 0 ;
V_358:
F_157 ( V_42 -> V_327 . V_353 ) ;
V_355:
F_157 ( V_42 -> V_327 . V_351 ) ;
V_352:
F_157 ( V_42 -> V_327 . V_348 ) ;
V_350:
F_157 ( V_42 -> V_327 . V_345 ) ;
V_347:
F_157 ( V_42 -> V_327 . V_341 ) ;
V_343:
F_157 ( V_42 -> V_327 . V_338 ) ;
V_340:
return - V_359 ;
}
static T_10 void F_158 ( struct V_42 * V_42 )
{
F_10 ( V_42 -> V_327 . V_356 ) ;
F_157 ( V_42 -> V_327 . V_353 ) ;
F_157 ( V_42 -> V_327 . V_351 ) ;
F_157 ( V_42 -> V_327 . V_348 ) ;
F_157 ( V_42 -> V_327 . V_345 ) ;
F_157 ( V_42 -> V_327 . V_341 ) ;
F_157 ( V_42 -> V_327 . V_338 ) ;
}
static int T_11 F_159 ( void )
{
return F_160 ( & V_360 ) ;
}
static T_9 int F_161 ( struct V_42 * V_42 )
{
F_162 ( & V_42 -> V_76 . V_361 . V_362 ) ;
V_42 -> V_76 . V_361 . V_363 [ 0 ] = 32768 ;
V_42 -> V_76 . V_361 . V_363 [ 1 ] = 60999 ;
F_162 ( & V_42 -> V_76 . V_364 . V_362 ) ;
V_42 -> V_76 . V_364 . V_363 [ 0 ] = F_163 ( & V_365 , 1 ) ;
V_42 -> V_76 . V_364 . V_363 [ 1 ] = F_163 ( & V_365 , 0 ) ;
V_42 -> V_76 . V_366 = V_367 ;
V_42 -> V_76 . V_248 = 0 ;
V_42 -> V_76 . V_368 = 1 ;
V_42 -> V_76 . V_369 = 1 ;
V_42 -> V_76 . V_370 = 1 ;
#ifdef F_164
V_42 -> V_76 . V_371 = V_372 ;
#endif
V_42 -> V_76 . V_373 = 20 ;
V_42 -> V_76 . V_374 = 10 ;
V_42 -> V_76 . V_375 = 1 ;
V_42 -> V_76 . V_376 = 2 ;
return 0 ;
}
static T_10 void F_165 ( struct V_42 * V_42 )
{
}
static int T_11 F_166 ( void )
{
return F_160 ( & V_377 ) ;
}
static int T_11 F_167 ( void )
{
return F_168 ( & V_378 , V_379 ) ;
}
static int T_11 F_169 ( void )
{
if ( F_170 () < 0 )
F_171 ( L_9 , V_249 ) ;
if ( F_172 () < 0 )
F_171 ( L_10 , V_249 ) ;
if ( F_167 () < 0 )
F_171 ( L_11 , V_249 ) ;
F_173 ( & V_380 ) ;
return 0 ;
}
static int T_11 F_174 ( void )
{
struct V_45 * V_381 ;
struct V_221 * V_382 ;
int V_323 = - V_28 ;
F_175 ( sizeof( struct V_383 ) ) ;
V_323 = F_176 ( & V_384 , 1 ) ;
if ( V_323 )
goto V_31;
V_323 = F_176 ( & V_385 , 1 ) ;
if ( V_323 )
goto V_386;
V_323 = F_176 ( & V_387 , 1 ) ;
if ( V_323 )
goto V_388;
V_323 = F_176 ( & V_389 , 1 ) ;
if ( V_323 )
goto V_390;
( void ) F_177 ( & V_391 ) ;
#ifdef F_164
F_178 () ;
#endif
if ( F_179 ( & V_392 , V_393 ) < 0 )
F_171 ( L_12 , V_249 ) ;
if ( F_179 ( & V_394 , V_395 ) < 0 )
F_171 ( L_13 , V_249 ) ;
if ( F_179 ( & V_396 , V_159 ) < 0 )
F_171 ( L_14 , V_249 ) ;
#ifdef F_180
if ( F_179 ( & V_397 , V_398 ) < 0 )
F_171 ( L_15 , V_249 ) ;
#endif
for ( V_382 = & V_227 [ 0 ] ; V_382 < & V_227 [ V_225 ] ; ++ V_382 )
F_181 ( V_382 ) ;
for ( V_381 = V_399 ; V_381 < & V_399 [ V_400 ] ; ++ V_381 )
F_76 ( V_381 ) ;
F_182 () ;
F_183 () ;
F_184 () ;
F_185 () ;
F_186 () ;
F_187 () ;
if ( F_188 () < 0 )
F_189 ( L_16 ) ;
#if F_190 ( V_401 )
if ( F_191 () )
F_171 ( L_17 , V_249 ) ;
#endif
if ( F_166 () )
F_171 ( L_18 , V_249 ) ;
if ( F_159 () )
F_171 ( L_19 , V_249 ) ;
F_192 () ;
F_193 () ;
F_194 ( & V_402 ) ;
F_195 () ;
V_323 = 0 ;
V_31:
return V_323 ;
V_390:
F_196 ( & V_387 ) ;
V_388:
F_196 ( & V_385 ) ;
V_386:
F_196 ( & V_384 ) ;
goto V_31;
}
static int T_11 F_192 ( void )
{
int V_323 = 0 ;
if ( F_197 () )
goto V_403;
if ( F_198 () )
goto V_404;
if ( F_199 () )
goto V_405;
if ( F_200 () )
goto V_406;
if ( F_201 () )
goto V_407;
V_31:
return V_323 ;
V_407:
F_202 () ;
V_406:
F_203 () ;
V_405:
F_204 () ;
V_404:
F_205 () ;
V_403:
V_323 = - V_359 ;
goto V_31;
}
static int T_11 F_192 ( void )
{
return 0 ;
}
