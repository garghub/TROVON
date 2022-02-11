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
if ( ( V_35 & V_36 ) &&
( V_35 & V_37 ) &&
! F_19 ( V_2 ) -> V_38 . V_39 . V_40 ) {
F_20 ( V_2 , V_25 ) ;
F_21 ( true ) ;
}
V_27 = F_22 ( V_2 , V_25 ) ;
if ( V_27 )
goto V_31;
}
V_2 -> V_41 = V_25 ;
V_27 = 0 ;
V_31:
F_16 ( V_2 ) ;
return V_27 ;
}
static int F_23 ( struct V_42 * V_42 , struct V_24 * V_1 , int V_43 ,
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
F_24 () ;
F_25 (answer, &inetsw[sock->type], list) {
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
if ( F_26 ( V_27 ) ) {
if ( V_50 < 2 ) {
F_27 () ;
if ( ++ V_50 == 1 )
F_28 ( L_3 ,
V_56 , V_43 , V_1 -> type ) ;
else
F_28 ( L_4 ,
V_56 , V_43 ) ;
goto V_52;
} else
goto V_57;
}
V_27 = - V_58 ;
if ( V_1 -> type == V_59 && ! V_44 &&
! F_29 ( V_42 -> V_60 , V_61 ) )
goto V_57;
V_1 -> V_62 = V_46 -> V_62 ;
V_48 = V_46 -> V_63 ;
V_49 = V_46 -> V_64 ;
F_27 () ;
F_7 ( ! V_48 -> V_65 ) ;
V_27 = - V_66 ;
V_2 = F_30 ( V_42 , V_56 , V_67 , V_48 , V_44 ) ;
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
F_31 ( V_1 , V_2 ) ;
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
F_32 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_27 = V_2 -> V_20 -> V_93 ( V_2 ) ;
if ( V_27 ) {
F_33 ( V_2 ) ;
goto V_31;
}
}
if ( V_2 -> V_20 -> V_94 ) {
V_27 = V_2 -> V_20 -> V_94 ( V_2 ) ;
if ( V_27 ) {
F_33 ( V_2 ) ;
goto V_31;
}
}
if ( ! V_44 ) {
V_27 = F_34 ( V_2 ) ;
if ( V_27 ) {
F_33 ( V_2 ) ;
goto V_31;
}
}
V_31:
return V_27 ;
V_57:
F_27 () ;
goto V_31;
}
int F_35 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_95 ;
F_36 ( V_2 ) ;
V_95 = 0 ;
if ( F_6 ( V_2 , V_96 ) &&
! ( V_97 -> V_64 & V_98 ) )
V_95 = V_2 -> V_99 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_100 ( V_2 , V_95 ) ;
}
return 0 ;
}
int F_37 ( struct V_24 * V_1 , struct V_101 * V_102 , int V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_42 = F_38 ( V_2 ) ;
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
V_105 -> V_115 . V_116 != F_39 ( V_117 ) )
goto V_31;
}
V_108 = F_40 ( V_42 , V_2 -> V_118 ) ? : V_108 ;
V_107 = F_41 ( V_42 , V_105 -> V_115 . V_116 , V_108 ) ;
V_27 = - V_119 ;
if ( ! V_42 -> V_76 . V_120 &&
! ( V_4 -> V_121 || V_4 -> V_122 ) &&
V_105 -> V_115 . V_116 != F_39 ( V_117 ) &&
V_107 != V_123 &&
V_107 != V_124 &&
V_107 != V_125 )
goto V_31;
V_106 = F_42 ( V_105 -> V_126 ) ;
V_27 = - V_127 ;
if ( V_106 && V_106 < V_128 &&
! F_29 ( V_42 -> V_60 , V_129 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_130;
V_4 -> V_131 = V_4 -> V_132 = V_105 -> V_115 . V_116 ;
if ( V_107 == V_124 || V_107 == V_125 )
V_4 -> V_132 = 0 ;
if ( ( V_106 || ! V_4 -> V_133 ) &&
V_2 -> V_20 -> V_21 ( V_2 , V_106 ) ) {
V_4 -> V_132 = V_4 -> V_131 = 0 ;
V_27 = - V_134 ;
goto V_130;
}
if ( V_4 -> V_131 )
V_2 -> V_135 |= V_136 ;
if ( V_106 )
V_2 -> V_135 |= V_137 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_138 = 0 ;
V_4 -> V_139 = 0 ;
F_43 ( V_2 ) ;
V_27 = 0 ;
V_130:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_44 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_103 < sizeof( V_102 -> V_140 ) )
return - V_28 ;
if ( V_102 -> V_140 == V_114 )
return V_2 -> V_20 -> V_141 ( V_2 , V_64 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_142 ( V_2 , V_102 , V_103 ) ;
}
static long F_45 ( struct V_1 * V_2 , long V_143 , int V_144 )
{
F_46 ( V_145 , V_146 ) ;
F_47 ( F_48 ( V_2 ) , & V_145 ) ;
V_2 -> V_147 += V_144 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_148 | V_149 ) ) {
F_16 ( V_2 ) ;
V_143 = F_49 ( & V_145 , V_150 , V_143 ) ;
F_15 ( V_2 ) ;
if ( F_50 ( V_97 ) || ! V_143 )
break;
}
F_51 ( F_48 ( V_2 ) , & V_145 ) ;
V_2 -> V_147 -= V_144 ;
return V_143 ;
}
int F_52 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_143 ;
if ( V_103 < sizeof( V_102 -> V_140 ) )
return - V_28 ;
if ( V_102 -> V_140 == V_114 ) {
V_27 = V_2 -> V_20 -> V_141 ( V_2 , V_64 ) ;
V_1 -> V_29 = V_27 ? V_151 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_152 :
V_27 = - V_153 ;
goto V_31;
case V_154 :
V_27 = - V_155 ;
break;
case V_30 :
V_27 = - V_153 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_142 ( V_2 , V_102 , V_103 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_154 ;
V_27 = - V_156 ;
break;
}
V_143 = F_53 ( V_2 , V_64 & V_157 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_148 | V_149 ) ) {
int V_144 = ( V_2 -> V_83 == V_158 ) &&
F_54 ( V_2 ) -> V_159 &&
F_54 ( V_2 ) -> V_159 -> V_160 ? 1 : 0 ;
if ( ! V_143 || ! F_45 ( V_2 , V_143 , V_144 ) )
goto V_31;
V_27 = F_55 ( V_143 ) ;
if ( F_50 ( V_97 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_161;
V_1 -> V_29 = V_152 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_161:
V_27 = V_161 ( V_2 ) ? : - V_162 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_141 ( V_2 , V_64 ) )
V_1 -> V_29 = V_151 ;
goto V_31;
}
int F_56 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_52 ( V_1 , V_102 , V_103 , V_64 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_57 ( struct V_24 * V_1 , struct V_24 * V_163 , int V_64 )
{
struct V_1 * V_164 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_165 = V_164 -> V_20 -> V_166 ( V_164 , V_64 , & V_27 ) ;
if ( ! V_165 )
goto V_167;
F_15 ( V_165 ) ;
F_58 ( V_165 ) ;
F_7 ( ! ( ( 1 << V_165 -> V_9 ) &
( V_168 | V_149 |
V_169 | V_32 ) ) ) ;
F_59 ( V_165 , V_163 ) ;
V_163 -> V_29 = V_152 ;
V_27 = 0 ;
F_16 ( V_165 ) ;
V_167:
return V_27 ;
}
int F_60 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int * V_170 , int V_171 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_61 ( struct V_104 * , sin , V_102 ) ;
sin -> V_111 = V_112 ;
if ( V_171 ) {
if ( ! V_4 -> V_139 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_148 ) ) &&
V_171 == 1 ) )
return - V_172 ;
sin -> V_126 = V_4 -> V_139 ;
sin -> V_115 . V_116 = V_4 -> V_138 ;
} else {
T_2 V_105 = V_4 -> V_131 ;
if ( ! V_105 )
V_105 = V_4 -> V_132 ;
sin -> V_126 = V_4 -> V_23 ;
sin -> V_115 . V_116 = V_105 ;
}
memset ( sin -> V_173 , 0 , sizeof( sin -> V_173 ) ) ;
* V_170 = sizeof( * sin ) ;
return 0 ;
}
int F_62 ( struct V_24 * V_1 , struct V_174 * V_175 , T_3 V_176 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_58 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_177 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_178 ( V_2 , V_175 , V_176 ) ;
}
T_4 F_63 ( struct V_24 * V_1 , struct V_179 * V_179 , int V_180 ,
T_3 V_176 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_58 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_177 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_181 )
return V_2 -> V_20 -> V_181 ( V_2 , V_179 , V_180 , V_176 , V_64 ) ;
return F_64 ( V_1 , V_179 , V_180 , V_176 , V_64 ) ;
}
int F_65 ( struct V_24 * V_1 , struct V_174 * V_175 , T_3 V_176 ,
int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_103 = 0 ;
int V_27 ;
F_58 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_182 ( V_2 , V_175 , V_176 , V_64 & V_183 ,
V_64 & ~ V_183 , & V_103 ) ;
if ( V_27 >= 0 )
V_175 -> V_184 = V_103 ;
return V_27 ;
}
int F_66 ( struct V_24 * V_1 , int V_185 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_185 ++ ;
if ( ( V_185 & ~ V_186 ) || ! V_185 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_154 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_148 | V_149 | V_32 ) )
V_1 -> V_29 = V_151 ;
else
V_1 -> V_29 = V_152 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_172 ;
default:
V_2 -> V_187 |= V_185 ;
if ( V_2 -> V_20 -> V_188 )
V_2 -> V_20 -> V_188 ( V_2 , V_185 ) ;
break;
case V_34 :
if ( ! ( V_185 & V_189 ) )
break;
case V_190 :
V_27 = V_2 -> V_20 -> V_141 ( V_2 , V_157 ) ;
V_1 -> V_29 = V_27 ? V_151 : V_30 ;
break;
}
V_2 -> V_191 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_67 ( struct V_24 * V_1 , unsigned int V_192 , unsigned long V_193 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_42 * V_42 = F_38 ( V_2 ) ;
switch ( V_192 ) {
case V_194 :
V_27 = F_68 ( V_2 , (struct V_195 V_196 * ) V_193 ) ;
break;
case V_197 :
V_27 = F_69 ( V_2 , (struct V_198 V_196 * ) V_193 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
V_27 = F_70 ( V_42 , V_192 , ( void V_196 * ) V_193 ) ;
break;
case V_202 :
case V_203 :
case V_204 :
V_27 = F_71 ( V_42 , V_192 , ( void V_196 * ) V_193 ) ;
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
V_27 = F_72 ( V_42 , V_192 , ( void V_196 * ) V_193 ) ;
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
static int F_73 ( struct V_24 * V_1 , unsigned int V_192 , unsigned long V_193 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_217 ;
if ( V_2 -> V_20 -> V_218 )
V_27 = V_2 -> V_20 -> V_218 ( V_2 , V_192 , V_193 ) ;
return V_27 ;
}
void F_74 ( struct V_45 * V_219 )
{
struct V_220 * V_221 ;
struct V_45 * V_46 ;
int V_43 = V_219 -> V_43 ;
struct V_220 * V_222 ;
F_75 ( & V_223 ) ;
if ( V_219 -> type >= V_224 )
goto V_225;
V_222 = & V_226 [ V_219 -> type ] ;
F_76 (lh, &inetsw[p->type]) {
V_46 = F_77 ( V_221 , struct V_45 , V_227 ) ;
if ( ( V_228 & V_46 -> V_64 ) == 0 )
break;
if ( V_43 == V_46 -> V_43 )
goto V_229;
V_222 = V_221 ;
}
F_78 ( & V_219 -> V_227 , V_222 ) ;
V_31:
F_79 ( & V_223 ) ;
return;
V_229:
F_5 ( L_5 , V_43 ) ;
goto V_31;
V_225:
F_5 ( L_6 ,
V_219 -> type ) ;
goto V_31;
}
void F_80 ( struct V_45 * V_219 )
{
if ( V_228 & V_219 -> V_64 ) {
F_5 ( L_7 ,
V_219 -> V_43 ) ;
} else {
F_75 ( & V_223 ) ;
F_81 ( & V_219 -> V_227 ) ;
F_79 ( & V_223 ) ;
F_82 () ;
}
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_230 = V_4 -> V_132 ;
T_2 V_231 = V_4 -> V_138 ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
T_2 V_236 ;
struct V_237 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_84 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_238 . V_239 )
V_231 = V_16 -> V_238 . V_240 ;
V_233 = & V_4 -> V_241 . V_242 . V_243 . V_244 ;
V_235 = F_85 ( V_233 , V_231 , 0 , F_86 ( V_2 ) ,
V_2 -> V_118 , V_2 -> V_83 ,
V_4 -> V_23 , V_4 -> V_139 , V_2 ) ;
if ( F_87 ( V_235 ) )
return F_88 ( V_235 ) ;
F_89 ( V_2 , & V_235 -> V_245 ) ;
V_236 = V_233 -> V_246 ;
if ( V_236 == V_230 )
return 0 ;
if ( F_38 ( V_2 ) -> V_76 . V_247 > 1 ) {
F_90 ( L_8 ,
V_248 , & V_230 , & V_236 ) ;
}
V_4 -> V_132 = V_4 -> V_131 = V_236 ;
return F_91 ( V_2 ) ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_234 * V_235 = (struct V_234 * ) F_93 ( V_2 , 0 ) ;
T_2 V_231 ;
struct V_237 * V_16 ;
struct V_232 * V_233 ;
int V_27 ;
if ( V_235 )
return 0 ;
F_24 () ;
V_16 = F_94 ( V_4 -> V_16 ) ;
V_231 = V_4 -> V_138 ;
if ( V_16 && V_16 -> V_238 . V_239 )
V_231 = V_16 -> V_238 . V_240 ;
F_27 () ;
V_233 = & V_4 -> V_241 . V_242 . V_243 . V_244 ;
V_235 = F_95 ( F_38 ( V_2 ) , V_233 , V_2 , V_231 , V_4 -> V_132 ,
V_4 -> V_139 , V_4 -> V_23 ,
V_2 -> V_83 , F_86 ( V_2 ) ,
V_2 -> V_118 ) ;
if ( ! F_87 ( V_235 ) ) {
V_27 = 0 ;
F_89 ( V_2 , & V_235 -> V_245 ) ;
} else {
V_27 = F_88 ( V_235 ) ;
V_2 -> V_249 = 0 ;
if ( ! F_38 ( V_2 ) -> V_76 . V_247 ||
V_2 -> V_9 != V_190 ||
( V_2 -> V_135 & V_136 ) ||
( V_27 = F_83 ( V_2 ) ) != 0 )
V_2 -> V_250 = - V_27 ;
}
return V_27 ;
}
struct V_251 * F_96 ( struct V_251 * V_252 ,
T_5 V_253 )
{
bool V_254 = false , V_255 = false , V_256 , V_257 ;
struct V_251 * V_258 = F_97 ( - V_28 ) ;
const struct V_259 * V_62 ;
unsigned int V_180 = 0 ;
struct V_260 * V_261 ;
int V_47 , V_262 ;
int V_263 ;
int V_264 ;
int V_265 ;
F_98 ( V_252 ) ;
V_263 = F_99 ( V_252 ) - F_100 ( V_252 ) ;
if ( F_26 ( ! F_101 ( V_252 , sizeof( * V_261 ) ) ) )
goto V_31;
V_261 = F_102 ( V_252 ) ;
V_264 = V_261 -> V_264 * 4 ;
if ( V_264 < sizeof( * V_261 ) )
goto V_31;
V_265 = F_42 ( V_261 -> V_265 ) ;
V_47 = V_261 -> V_43 ;
if ( F_26 ( ! F_101 ( V_252 , V_264 ) ) )
goto V_31;
F_103 ( V_252 , V_264 ) ;
V_257 = F_104 ( V_252 ) -> V_266 > 0 ;
if ( V_257 )
V_253 &= V_252 -> V_267 -> V_268 ;
F_104 ( V_252 ) -> V_266 += V_264 ;
F_105 ( V_252 ) ;
V_258 = F_97 ( - V_55 ) ;
if ( ! V_252 -> V_269 || V_257 ) {
V_254 = ! ! ( F_106 ( V_252 ) -> V_270 & V_271 ) ;
V_255 = ! ! ( F_106 ( V_252 ) -> V_270 & V_272 ) ;
if ( V_255 && ! ( F_102 ( V_252 ) -> V_273 & F_17 ( V_274 ) ) )
goto V_31;
}
V_62 = F_94 ( V_275 [ V_47 ] ) ;
if ( F_107 ( V_62 && V_62 -> V_276 . V_277 ) )
V_258 = V_62 -> V_276 . V_277 ( V_252 , V_253 ) ;
if ( F_108 ( V_258 ) )
goto V_31;
V_256 = ! ! ( F_106 ( V_258 ) -> V_270 & V_278 ) ;
V_252 = V_258 ;
do {
V_261 = (struct V_260 * ) ( F_100 ( V_252 ) + V_263 ) ;
if ( V_254 ) {
V_261 -> V_273 = F_17 ( V_180 >> 3 ) ;
if ( V_252 -> V_279 )
V_261 -> V_273 |= F_17 ( V_280 ) ;
V_180 += V_252 -> V_281 - V_263 - V_264 ;
V_262 = V_252 -> V_281 - V_263 ;
} else if ( F_109 ( V_252 ) ) {
if ( ! V_255 ) {
V_261 -> V_265 = F_17 ( V_265 ) ;
V_265 += F_106 ( V_252 ) -> V_282 ;
}
if ( V_256 )
V_262 = F_106 ( V_252 ) -> V_283 +
F_104 ( V_252 ) -> V_284 +
V_252 -> V_285 - ( unsigned char * ) V_261 ;
else
V_262 = V_252 -> V_281 - V_263 ;
} else {
if ( ! V_255 )
V_261 -> V_265 = F_17 ( V_265 ++ ) ;
V_262 = V_252 -> V_281 - V_263 ;
}
V_261 -> V_262 = F_17 ( V_262 ) ;
F_110 ( V_261 ) ;
if ( V_257 )
F_111 ( V_252 ) ;
V_252 -> V_286 = ( V_287 * ) V_261 - V_252 -> V_285 ;
} while ( ( V_252 = V_252 -> V_279 ) );
V_31:
return V_258 ;
}
struct V_251 * * F_112 ( struct V_251 * * V_285 , struct V_251 * V_252 )
{
const struct V_259 * V_62 ;
struct V_251 * * V_288 = NULL ;
struct V_251 * V_219 ;
const struct V_260 * V_261 ;
unsigned int V_289 ;
unsigned int V_290 ;
unsigned int V_265 ;
int V_291 = 1 ;
int V_47 ;
V_290 = F_113 ( V_252 ) ;
V_289 = V_290 + sizeof( * V_261 ) ;
V_261 = F_114 ( V_252 , V_290 ) ;
if ( F_115 ( V_252 , V_289 ) ) {
V_261 = F_116 ( V_252 , V_289 , V_290 ) ;
if ( F_26 ( ! V_261 ) )
goto V_31;
}
V_47 = V_261 -> V_43 ;
F_24 () ;
V_62 = F_94 ( V_275 [ V_47 ] ) ;
if ( ! V_62 || ! V_62 -> V_276 . V_292 )
goto V_293;
if ( * ( V_287 * ) V_261 != 0x45 )
goto V_293;
if ( F_26 ( F_117 ( ( V_287 * ) V_261 , 5 ) ) )
goto V_293;
V_265 = F_118 ( * ( T_2 * ) & V_261 -> V_265 ) ;
V_291 = ( V_294 ) ( ( F_118 ( * ( T_2 * ) V_261 ) ^ F_119 ( V_252 ) ) | ( V_265 & ~ V_274 ) ) ;
V_265 >>= 16 ;
for ( V_219 = * V_285 ; V_219 ; V_219 = V_219 -> V_279 ) {
struct V_260 * V_295 ;
V_294 V_296 ;
if ( ! F_120 ( V_219 ) -> V_297 )
continue;
V_295 = (struct V_260 * ) ( V_219 -> V_160 + V_290 ) ;
if ( ( V_261 -> V_43 ^ V_295 -> V_43 ) |
( ( V_298 T_1 ) V_261 -> V_246 ^ ( V_298 T_1 ) V_295 -> V_246 ) |
( ( V_298 T_1 ) V_261 -> V_231 ^ ( V_298 T_1 ) V_295 -> V_231 ) ) {
F_120 ( V_219 ) -> V_297 = 0 ;
continue;
}
F_120 ( V_219 ) -> V_291 |=
( V_261 -> V_299 ^ V_295 -> V_299 ) |
( V_261 -> V_300 ^ V_295 -> V_300 ) |
( ( V_261 -> V_273 ^ V_295 -> V_273 ) & F_17 ( V_274 ) ) ;
F_120 ( V_219 ) -> V_291 |= V_291 ;
V_296 = ( V_294 ) ( V_265 - F_42 ( V_295 -> V_265 ) ) ;
if ( ! F_120 ( V_219 ) -> V_301 ||
! ( V_261 -> V_273 & F_17 ( V_274 ) ) ) {
V_296 ^= F_120 ( V_219 ) -> V_302 ;
V_296 = V_296 ? 0xFFFF : 0 ;
}
if ( F_120 ( V_252 ) -> V_301 )
F_120 ( V_219 ) -> V_296 = V_296 ;
else
F_120 ( V_219 ) -> V_296 |= V_296 ;
}
F_120 ( V_252 ) -> V_301 = ! ! ( V_261 -> V_273 & F_17 ( V_274 ) ) ;
F_120 ( V_252 ) -> V_291 |= V_291 ;
F_121 ( V_252 , V_290 ) ;
F_122 ( V_252 , sizeof( * V_261 ) ) ;
F_123 ( V_252 , F_113 ( V_252 ) ) ;
V_288 = F_124 ( V_62 -> V_276 . V_292 , V_285 , V_252 ) ;
V_293:
F_27 () ;
V_31:
F_120 ( V_252 ) -> V_291 |= V_291 ;
return V_288 ;
}
static struct V_251 * * F_125 ( struct V_251 * * V_285 ,
struct V_251 * V_252 )
{
if ( F_120 ( V_252 ) -> V_303 ) {
F_120 ( V_252 ) -> V_291 = 1 ;
return NULL ;
}
F_120 ( V_252 ) -> V_303 = 1 ;
return F_112 ( V_285 , V_252 ) ;
}
T_2 F_126 ( void )
{
T_1 V_304 ;
T_1 V_305 ;
struct V_306 V_307 ;
F_127 ( & V_307 ) ;
( void ) F_128 ( V_307 . V_308 , V_309 , & V_304 ) ;
V_305 = V_304 * V_310 ;
V_305 += ( T_1 ) V_307 . V_311 / V_312 ;
return F_39 ( V_305 ) ;
}
int F_129 ( struct V_1 * V_2 , struct V_174 * V_175 , int V_281 , int * V_103 )
{
if ( V_2 -> V_313 == V_112 )
return F_130 ( V_2 , V_175 , V_281 , V_103 ) ;
#if F_131 ( V_314 )
if ( V_2 -> V_313 == V_315 )
return V_316 . V_317 ( V_2 , V_175 , V_281 , V_103 ) ;
#endif
return - V_28 ;
}
int F_132 ( struct V_251 * V_252 , int V_263 )
{
T_6 V_318 = F_17 ( V_252 -> V_281 - V_263 ) ;
struct V_260 * V_261 = (struct V_260 * ) ( V_252 -> V_160 + V_263 ) ;
const struct V_259 * V_62 ;
int V_47 = V_261 -> V_43 ;
int V_27 = - V_319 ;
if ( V_252 -> V_269 )
F_133 ( V_252 , V_263 ) ;
F_134 ( & V_261 -> V_320 , V_261 -> V_262 , V_318 ) ;
V_261 -> V_262 = V_318 ;
F_24 () ;
V_62 = F_94 ( V_275 [ V_47 ] ) ;
if ( F_7 ( ! V_62 || ! V_62 -> V_276 . V_321 ) )
goto V_293;
V_27 = V_62 -> V_276 . V_321 ( V_252 , V_263 + sizeof( * V_261 ) ) ;
V_293:
F_27 () ;
return V_27 ;
}
static int F_135 ( struct V_251 * V_252 , int V_263 )
{
V_252 -> V_269 = 1 ;
F_106 ( V_252 ) -> V_270 |= V_322 ;
return F_132 ( V_252 , V_263 ) ;
}
int F_136 ( struct V_1 * * V_2 , unsigned short V_323 ,
unsigned short type , unsigned char V_43 ,
struct V_42 * V_42 )
{
struct V_24 * V_1 ;
int V_324 = F_137 ( V_42 , V_323 , type , V_43 , & V_1 ) ;
if ( V_324 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_325 = V_326 ;
( * V_2 ) -> V_20 -> V_327 ( * V_2 ) ;
}
return V_324 ;
}
T_7 F_138 ( void T_8 * V_328 , int V_329 , int V_330 )
{
return * ( ( ( unsigned long * ) F_139 ( V_328 , V_329 ) ) + V_330 ) ;
}
unsigned long F_140 ( void T_8 * V_328 , int V_330 )
{
unsigned long V_331 = 0 ;
int V_332 ;
F_141 (i)
V_331 += F_138 ( V_328 , V_332 , V_330 ) ;
return V_331 ;
}
T_7 F_142 ( void T_8 * V_328 , int V_329 , int V_330 ,
T_3 V_333 )
{
void * V_334 ;
struct V_335 * V_336 ;
T_7 V_337 ;
unsigned int V_338 ;
V_334 = F_139 ( V_328 , V_329 ) ;
V_336 = (struct V_335 * ) ( V_334 + V_333 ) ;
do {
V_338 = F_143 ( V_336 ) ;
V_337 = * ( ( ( T_7 * ) V_334 ) + V_330 ) ;
} while ( F_144 ( V_336 , V_338 ) );
return V_337 ;
}
T_7 F_145 ( void T_8 * V_328 , int V_330 , T_3 V_333 )
{
T_7 V_331 = 0 ;
int V_329 ;
F_141 (cpu) {
V_331 += F_142 ( V_328 , V_329 , V_330 , V_333 ) ;
}
return V_331 ;
}
static T_9 int F_146 ( struct V_42 * V_42 )
{
int V_332 ;
V_42 -> V_328 . V_339 = F_147 ( struct V_340 ) ;
if ( ! V_42 -> V_328 . V_339 )
goto V_341;
V_42 -> V_328 . V_342 = F_147 ( struct V_343 ) ;
if ( ! V_42 -> V_328 . V_342 )
goto V_344;
F_141 (i) {
struct V_343 * V_345 ;
V_345 = F_139 ( V_42 -> V_328 . V_342 , V_332 ) ;
F_148 ( & V_345 -> V_336 ) ;
}
V_42 -> V_328 . V_346 = F_147 ( struct V_347 ) ;
if ( ! V_42 -> V_328 . V_346 )
goto V_348;
V_42 -> V_328 . V_349 = F_147 ( struct V_350 ) ;
if ( ! V_42 -> V_328 . V_349 )
goto V_351;
V_42 -> V_328 . V_352 = F_147 ( struct V_350 ) ;
if ( ! V_42 -> V_328 . V_352 )
goto V_353;
V_42 -> V_328 . V_354 = F_147 ( struct V_355 ) ;
if ( ! V_42 -> V_328 . V_354 )
goto V_356;
V_42 -> V_328 . V_357 = F_149 ( sizeof( struct V_358 ) ,
V_67 ) ;
if ( ! V_42 -> V_328 . V_357 )
goto V_359;
F_150 ( V_42 ) ;
return 0 ;
V_359:
F_151 ( V_42 -> V_328 . V_354 ) ;
V_356:
F_151 ( V_42 -> V_328 . V_352 ) ;
V_353:
F_151 ( V_42 -> V_328 . V_349 ) ;
V_351:
F_151 ( V_42 -> V_328 . V_346 ) ;
V_348:
F_151 ( V_42 -> V_328 . V_342 ) ;
V_344:
F_151 ( V_42 -> V_328 . V_339 ) ;
V_341:
return - V_360 ;
}
static T_10 void F_152 ( struct V_42 * V_42 )
{
F_9 ( V_42 -> V_328 . V_357 ) ;
F_151 ( V_42 -> V_328 . V_354 ) ;
F_151 ( V_42 -> V_328 . V_352 ) ;
F_151 ( V_42 -> V_328 . V_349 ) ;
F_151 ( V_42 -> V_328 . V_346 ) ;
F_151 ( V_42 -> V_328 . V_342 ) ;
F_151 ( V_42 -> V_328 . V_339 ) ;
}
static int T_11 F_153 ( void )
{
return F_154 ( & V_361 ) ;
}
static T_9 int F_155 ( struct V_42 * V_42 )
{
F_156 ( & V_42 -> V_76 . V_362 . V_363 ) ;
V_42 -> V_76 . V_362 . V_364 [ 0 ] = 32768 ;
V_42 -> V_76 . V_362 . V_364 [ 1 ] = 60999 ;
F_156 ( & V_42 -> V_76 . V_365 . V_363 ) ;
V_42 -> V_76 . V_365 . V_364 [ 0 ] = F_157 ( & V_366 , 1 ) ;
V_42 -> V_76 . V_365 . V_364 [ 1 ] = F_157 ( & V_366 , 0 ) ;
V_42 -> V_76 . V_367 = V_368 ;
V_42 -> V_76 . V_247 = 0 ;
V_42 -> V_76 . V_369 = 1 ;
return 0 ;
}
static T_10 void F_158 ( struct V_42 * V_42 )
{
}
static int T_11 F_159 ( void )
{
return F_154 ( & V_370 ) ;
}
static int T_11 F_160 ( void )
{
if ( F_161 () < 0 )
F_162 ( L_9 , V_248 ) ;
if ( F_163 () < 0 )
F_162 ( L_10 , V_248 ) ;
F_164 ( & V_371 ) ;
F_165 ( & V_372 , V_373 ) ;
return 0 ;
}
static int T_11 F_166 ( void )
{
struct V_45 * V_374 ;
struct V_220 * V_375 ;
int V_324 = - V_28 ;
F_167 ( sizeof( struct V_376 ) ) ;
V_324 = F_168 ( & V_377 , 1 ) ;
if ( V_324 )
goto V_31;
V_324 = F_168 ( & V_378 , 1 ) ;
if ( V_324 )
goto V_379;
V_324 = F_168 ( & V_380 , 1 ) ;
if ( V_324 )
goto V_381;
V_324 = F_168 ( & V_382 , 1 ) ;
if ( V_324 )
goto V_383;
( void ) F_169 ( & V_384 ) ;
#ifdef F_170
F_171 () ;
#endif
if ( F_172 ( & V_385 , V_386 ) < 0 )
F_162 ( L_11 , V_248 ) ;
if ( F_172 ( & V_387 , V_388 ) < 0 )
F_162 ( L_12 , V_248 ) ;
if ( F_172 ( & V_389 , V_158 ) < 0 )
F_162 ( L_13 , V_248 ) ;
#ifdef F_173
if ( F_172 ( & V_390 , V_391 ) < 0 )
F_162 ( L_14 , V_248 ) ;
#endif
for ( V_375 = & V_226 [ 0 ] ; V_375 < & V_226 [ V_224 ] ; ++ V_375 )
F_174 ( V_375 ) ;
for ( V_374 = V_392 ; V_374 < & V_392 [ V_393 ] ; ++ V_374 )
F_74 ( V_374 ) ;
F_175 () ;
F_176 () ;
F_177 () ;
F_178 () ;
F_179 () ;
F_180 () ;
F_181 () ;
if ( F_182 () < 0 )
F_183 ( L_15 ) ;
#if F_184 ( V_394 )
if ( F_185 () )
F_162 ( L_16 , V_248 ) ;
#endif
if ( F_159 () )
F_162 ( L_17 , V_248 ) ;
if ( F_153 () )
F_162 ( L_18 , V_248 ) ;
F_186 () ;
F_187 () ;
F_188 ( & V_395 ) ;
F_189 () ;
V_324 = 0 ;
V_31:
return V_324 ;
V_383:
F_190 ( & V_380 ) ;
V_381:
F_190 ( & V_378 ) ;
V_379:
F_190 ( & V_377 ) ;
goto V_31;
}
static int T_11 F_186 ( void )
{
int V_324 = 0 ;
if ( F_191 () )
goto V_396;
if ( F_192 () )
goto V_397;
if ( F_193 () )
goto V_398;
if ( F_194 () )
goto V_399;
if ( F_195 () )
goto V_400;
V_31:
return V_324 ;
V_400:
F_196 () ;
V_399:
F_197 () ;
V_398:
F_198 () ;
V_397:
F_199 () ;
V_396:
V_324 = - V_360 ;
goto V_31;
}
static int T_11 F_186 ( void )
{
return 0 ;
}
