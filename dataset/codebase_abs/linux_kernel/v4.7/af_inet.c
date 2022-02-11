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
! F_19 ( V_2 ) -> V_37 . V_38 . V_39 ) {
if ( ( V_35 & V_40 ) != 0 )
F_20 ( V_2 , V_25 ) ;
else if ( ( V_35 &
V_41 ) != 0 )
F_20 ( V_2 ,
( ( V_42 ) V_35 ) >> 16 ) ;
F_21 ( true ) ;
}
V_27 = F_22 ( V_2 , V_25 ) ;
if ( V_27 )
goto V_31;
}
V_2 -> V_43 = V_25 ;
V_27 = 0 ;
V_31:
F_16 ( V_2 ) ;
return V_27 ;
}
static int F_23 ( struct V_44 * V_44 , struct V_24 * V_1 , int V_45 ,
int V_46 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_3 * V_4 ;
struct V_49 * V_50 ;
unsigned char V_51 ;
int V_52 = 0 ;
int V_27 ;
if ( V_45 < 0 || V_45 >= V_53 )
return - V_28 ;
V_1 -> V_29 = V_30 ;
V_54:
V_27 = - V_55 ;
F_24 () ;
F_25 (answer, &inetsw[sock->type], list) {
V_27 = 0 ;
if ( V_45 == V_48 -> V_45 ) {
if ( V_45 != V_56 )
break;
} else {
if ( V_56 == V_45 ) {
V_45 = V_48 -> V_45 ;
break;
}
if ( V_56 == V_48 -> V_45 )
break;
}
V_27 = - V_57 ;
}
if ( F_26 ( V_27 ) ) {
if ( V_52 < 2 ) {
F_27 () ;
if ( ++ V_52 == 1 )
F_28 ( L_3 ,
V_58 , V_45 , V_1 -> type ) ;
else
F_28 ( L_4 ,
V_58 , V_45 ) ;
goto V_54;
} else
goto V_59;
}
V_27 = - V_60 ;
if ( V_1 -> type == V_61 && ! V_46 &&
! F_29 ( V_44 -> V_62 , V_63 ) )
goto V_59;
V_1 -> V_64 = V_48 -> V_64 ;
V_50 = V_48 -> V_65 ;
V_51 = V_48 -> V_66 ;
F_27 () ;
F_7 ( ! V_50 -> V_67 ) ;
V_27 = - V_68 ;
V_2 = F_30 ( V_44 , V_58 , V_69 , V_50 , V_46 ) ;
if ( ! V_2 )
goto V_31;
V_27 = 0 ;
if ( V_70 & V_51 )
V_2 -> V_71 = V_72 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_73 = ( V_74 & V_51 ) != 0 ;
V_4 -> V_75 = 0 ;
if ( V_61 == V_1 -> type ) {
V_4 -> V_19 = V_45 ;
if ( V_76 == V_45 )
V_4 -> V_77 = 1 ;
}
if ( V_44 -> V_78 . V_79 )
V_4 -> V_80 = V_81 ;
else
V_4 -> V_80 = V_82 ;
V_4 -> V_83 = 0 ;
F_31 ( V_1 , V_2 ) ;
V_2 -> V_84 = F_1 ;
V_2 -> V_85 = V_45 ;
V_2 -> V_86 = V_2 -> V_20 -> V_87 ;
V_4 -> V_88 = - 1 ;
V_4 -> V_89 = 1 ;
V_4 -> V_90 = 1 ;
V_4 -> V_91 = 1 ;
V_4 -> V_92 = 0 ;
V_4 -> V_93 = NULL ;
V_4 -> V_94 = 0 ;
F_32 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_27 = V_2 -> V_20 -> V_95 ( V_2 ) ;
if ( V_27 ) {
F_33 ( V_2 ) ;
goto V_31;
}
}
if ( V_2 -> V_20 -> V_96 ) {
V_27 = V_2 -> V_20 -> V_96 ( V_2 ) ;
if ( V_27 )
F_33 ( V_2 ) ;
}
V_31:
return V_27 ;
V_59:
F_27 () ;
goto V_31;
}
int F_34 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_97 ;
F_35 ( V_2 ) ;
V_97 = 0 ;
if ( F_6 ( V_2 , V_98 ) &&
! ( V_99 -> V_66 & V_100 ) )
V_97 = V_2 -> V_101 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_102 ( V_2 , V_97 ) ;
}
return 0 ;
}
int F_36 ( struct V_24 * V_1 , struct V_103 * V_104 , int V_105 )
{
struct V_106 * V_107 = (struct V_106 * ) V_104 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_44 * V_44 = F_37 ( V_2 ) ;
unsigned short V_108 ;
int V_109 ;
T_1 V_110 = V_111 ;
int V_27 ;
if ( V_2 -> V_20 -> V_112 ) {
V_27 = V_2 -> V_20 -> V_112 ( V_2 , V_104 , V_105 ) ;
goto V_31;
}
V_27 = - V_28 ;
if ( V_105 < sizeof( struct V_106 ) )
goto V_31;
if ( V_107 -> V_113 != V_114 ) {
V_27 = - V_115 ;
if ( V_107 -> V_113 != V_116 ||
V_107 -> V_117 . V_118 != F_38 ( V_119 ) )
goto V_31;
}
V_110 = F_39 ( V_44 , V_2 -> V_120 ) ? : V_110 ;
V_109 = F_40 ( V_44 , V_107 -> V_117 . V_118 , V_110 ) ;
V_27 = - V_121 ;
if ( ! V_44 -> V_78 . V_122 &&
! ( V_4 -> V_123 || V_4 -> V_124 ) &&
V_107 -> V_117 . V_118 != F_38 ( V_119 ) &&
V_109 != V_125 &&
V_109 != V_126 &&
V_109 != V_127 )
goto V_31;
V_108 = F_41 ( V_107 -> V_128 ) ;
V_27 = - V_129 ;
if ( V_108 && V_108 < V_130 &&
! F_29 ( V_44 -> V_62 , V_131 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_132;
V_4 -> V_133 = V_4 -> V_134 = V_107 -> V_117 . V_118 ;
if ( V_109 == V_126 || V_109 == V_127 )
V_4 -> V_134 = 0 ;
if ( ( V_108 || ! V_4 -> V_135 ) &&
V_2 -> V_20 -> V_21 ( V_2 , V_108 ) ) {
V_4 -> V_134 = V_4 -> V_133 = 0 ;
V_27 = - V_136 ;
goto V_132;
}
if ( V_4 -> V_133 )
V_2 -> V_137 |= V_138 ;
if ( V_108 )
V_2 -> V_137 |= V_139 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_140 = 0 ;
V_4 -> V_141 = 0 ;
F_42 ( V_2 ) ;
V_27 = 0 ;
V_132:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_43 ( struct V_24 * V_1 , struct V_103 * V_104 ,
int V_105 , int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_105 < sizeof( V_104 -> V_142 ) )
return - V_28 ;
if ( V_104 -> V_142 == V_116 )
return V_2 -> V_20 -> V_143 ( V_2 , V_66 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_144 ( V_2 , V_104 , V_105 ) ;
}
static long F_44 ( struct V_1 * V_2 , long V_145 , int V_146 )
{
F_45 ( V_147 ) ;
F_46 ( F_47 ( V_2 ) , & V_147 , V_148 ) ;
V_2 -> V_149 += V_146 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_150 | V_151 ) ) {
F_16 ( V_2 ) ;
V_145 = F_48 ( V_145 ) ;
F_15 ( V_2 ) ;
if ( F_49 ( V_99 ) || ! V_145 )
break;
F_46 ( F_47 ( V_2 ) , & V_147 , V_148 ) ;
}
F_50 ( F_47 ( V_2 ) , & V_147 ) ;
V_2 -> V_149 -= V_146 ;
return V_145 ;
}
int F_51 ( struct V_24 * V_1 , struct V_103 * V_104 ,
int V_105 , int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_145 ;
if ( V_105 < sizeof( V_104 -> V_142 ) )
return - V_28 ;
if ( V_104 -> V_142 == V_116 ) {
V_27 = V_2 -> V_20 -> V_143 ( V_2 , V_66 ) ;
V_1 -> V_29 = V_27 ? V_152 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_153 :
V_27 = - V_154 ;
goto V_31;
case V_155 :
V_27 = - V_156 ;
break;
case V_30 :
V_27 = - V_154 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_144 ( V_2 , V_104 , V_105 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_155 ;
V_27 = - V_157 ;
break;
}
V_145 = F_52 ( V_2 , V_66 & V_158 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_150 | V_151 ) ) {
int V_146 = ( V_2 -> V_85 == V_159 ) &&
F_53 ( V_2 ) -> V_160 &&
F_53 ( V_2 ) -> V_160 -> V_161 ? 1 : 0 ;
if ( ! V_145 || ! F_44 ( V_2 , V_145 , V_146 ) )
goto V_31;
V_27 = F_54 ( V_145 ) ;
if ( F_49 ( V_99 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_162;
V_1 -> V_29 = V_153 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_162:
V_27 = V_162 ( V_2 ) ? : - V_163 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_143 ( V_2 , V_66 ) )
V_1 -> V_29 = V_152 ;
goto V_31;
}
int F_55 ( struct V_24 * V_1 , struct V_103 * V_104 ,
int V_105 , int V_66 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_51 ( V_1 , V_104 , V_105 , V_66 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_56 ( struct V_24 * V_1 , struct V_24 * V_164 , int V_66 )
{
struct V_1 * V_165 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_166 = V_165 -> V_20 -> V_167 ( V_165 , V_66 , & V_27 ) ;
if ( ! V_166 )
goto V_168;
F_15 ( V_166 ) ;
F_57 ( V_166 ) ;
F_7 ( ! ( ( 1 << V_166 -> V_9 ) &
( V_169 | V_151 |
V_170 | V_32 ) ) ) ;
F_58 ( V_166 , V_164 ) ;
V_164 -> V_29 = V_153 ;
V_27 = 0 ;
F_16 ( V_166 ) ;
V_168:
return V_27 ;
}
int F_59 ( struct V_24 * V_1 , struct V_103 * V_104 ,
int * V_171 , int V_172 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_60 ( struct V_106 * , sin , V_104 ) ;
sin -> V_113 = V_114 ;
if ( V_172 ) {
if ( ! V_4 -> V_141 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_150 ) ) &&
V_172 == 1 ) )
return - V_173 ;
sin -> V_128 = V_4 -> V_141 ;
sin -> V_117 . V_118 = V_4 -> V_140 ;
} else {
T_2 V_107 = V_4 -> V_133 ;
if ( ! V_107 )
V_107 = V_4 -> V_134 ;
sin -> V_128 = V_4 -> V_23 ;
sin -> V_117 . V_118 = V_107 ;
}
memset ( sin -> V_174 , 0 , sizeof( sin -> V_174 ) ) ;
* V_171 = sizeof( * sin ) ;
return 0 ;
}
int F_61 ( struct V_24 * V_1 , struct V_175 * V_176 , T_3 V_177 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_57 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_178 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_179 ( V_2 , V_176 , V_177 ) ;
}
T_4 F_62 ( struct V_24 * V_1 , struct V_180 * V_180 , int V_181 ,
T_3 V_177 , int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_57 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_178 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_182 )
return V_2 -> V_20 -> V_182 ( V_2 , V_180 , V_181 , V_177 , V_66 ) ;
return F_63 ( V_1 , V_180 , V_181 , V_177 , V_66 ) ;
}
int F_64 ( struct V_24 * V_1 , struct V_175 * V_176 , T_3 V_177 ,
int V_66 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_105 = 0 ;
int V_27 ;
F_57 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_183 ( V_2 , V_176 , V_177 , V_66 & V_184 ,
V_66 & ~ V_184 , & V_105 ) ;
if ( V_27 >= 0 )
V_176 -> V_185 = V_105 ;
return V_27 ;
}
int F_65 ( struct V_24 * V_1 , int V_186 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_186 ++ ;
if ( ( V_186 & ~ V_187 ) || ! V_186 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_155 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_150 | V_151 | V_32 ) )
V_1 -> V_29 = V_152 ;
else
V_1 -> V_29 = V_153 ;
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
V_27 = V_2 -> V_20 -> V_143 ( V_2 , V_158 ) ;
V_1 -> V_29 = V_27 ? V_152 : V_30 ;
break;
}
V_2 -> V_192 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_66 ( struct V_24 * V_1 , unsigned int V_193 , unsigned long V_194 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_44 * V_44 = F_37 ( V_2 ) ;
switch ( V_193 ) {
case V_195 :
V_27 = F_67 ( V_2 , (struct V_196 V_197 * ) V_194 ) ;
break;
case V_198 :
V_27 = F_68 ( V_2 , (struct V_199 V_197 * ) V_194 ) ;
break;
case V_200 :
case V_201 :
case V_202 :
V_27 = F_69 ( V_44 , V_193 , ( void V_197 * ) V_194 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
V_27 = F_70 ( V_44 , V_193 , ( void V_197 * ) V_194 ) ;
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
V_27 = F_71 ( V_44 , V_193 , ( void V_197 * ) V_194 ) ;
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
static int F_72 ( struct V_24 * V_1 , unsigned int V_193 , unsigned long V_194 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_218 ;
if ( V_2 -> V_20 -> V_219 )
V_27 = V_2 -> V_20 -> V_219 ( V_2 , V_193 , V_194 ) ;
return V_27 ;
}
void F_73 ( struct V_47 * V_220 )
{
struct V_221 * V_222 ;
struct V_47 * V_48 ;
int V_45 = V_220 -> V_45 ;
struct V_221 * V_223 ;
F_74 ( & V_224 ) ;
if ( V_220 -> type >= V_225 )
goto V_226;
V_223 = & V_227 [ V_220 -> type ] ;
F_75 (lh, &inetsw[p->type]) {
V_48 = F_76 ( V_222 , struct V_47 , V_228 ) ;
if ( ( V_229 & V_48 -> V_66 ) == 0 )
break;
if ( V_45 == V_48 -> V_45 )
goto V_230;
V_223 = V_222 ;
}
F_77 ( & V_220 -> V_228 , V_223 ) ;
V_31:
F_78 ( & V_224 ) ;
return;
V_230:
F_5 ( L_5 , V_45 ) ;
goto V_31;
V_226:
F_5 ( L_6 ,
V_220 -> type ) ;
goto V_31;
}
void F_79 ( struct V_47 * V_220 )
{
if ( V_229 & V_220 -> V_66 ) {
F_5 ( L_7 ,
V_220 -> V_45 ) ;
} else {
F_74 ( & V_224 ) ;
F_80 ( & V_220 -> V_228 ) ;
F_78 ( & V_224 ) ;
F_81 () ;
}
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_231 = V_4 -> V_134 ;
T_2 V_232 = V_4 -> V_140 ;
struct V_233 * V_234 ;
struct V_235 * V_236 ;
T_2 V_237 ;
struct V_238 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_83 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_239 . V_240 )
V_232 = V_16 -> V_239 . V_241 ;
V_234 = & V_4 -> V_242 . V_243 . V_244 . V_245 ;
V_236 = F_84 ( V_234 , V_232 , 0 , F_85 ( V_2 ) ,
V_2 -> V_120 , V_2 -> V_85 ,
V_4 -> V_23 , V_4 -> V_141 , V_2 ) ;
if ( F_86 ( V_236 ) )
return F_87 ( V_236 ) ;
F_88 ( V_2 , & V_236 -> V_246 ) ;
V_237 = V_234 -> V_247 ;
if ( V_237 == V_231 )
return 0 ;
if ( F_37 ( V_2 ) -> V_78 . V_248 > 1 ) {
F_89 ( L_8 ,
V_249 , & V_231 , & V_237 ) ;
}
V_4 -> V_134 = V_4 -> V_133 = V_237 ;
return F_90 ( V_2 ) ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_235 * V_236 = (struct V_235 * ) F_92 ( V_2 , 0 ) ;
T_2 V_232 ;
struct V_238 * V_16 ;
struct V_233 * V_234 ;
int V_27 ;
if ( V_236 )
return 0 ;
F_24 () ;
V_16 = F_93 ( V_4 -> V_16 ) ;
V_232 = V_4 -> V_140 ;
if ( V_16 && V_16 -> V_239 . V_240 )
V_232 = V_16 -> V_239 . V_241 ;
F_27 () ;
V_234 = & V_4 -> V_242 . V_243 . V_244 . V_245 ;
V_236 = F_94 ( F_37 ( V_2 ) , V_234 , V_2 , V_232 , V_4 -> V_134 ,
V_4 -> V_141 , V_4 -> V_23 ,
V_2 -> V_85 , F_85 ( V_2 ) ,
V_2 -> V_120 ) ;
if ( ! F_86 ( V_236 ) ) {
V_27 = 0 ;
F_88 ( V_2 , & V_236 -> V_246 ) ;
} else {
V_27 = F_87 ( V_236 ) ;
V_2 -> V_250 = 0 ;
if ( ! F_37 ( V_2 ) -> V_78 . V_248 ||
V_2 -> V_9 != V_191 ||
( V_2 -> V_137 & V_138 ) ||
( V_27 = F_82 ( V_2 ) ) != 0 )
V_2 -> V_251 = - V_27 ;
}
return V_27 ;
}
struct V_252 * F_95 ( struct V_252 * V_253 ,
T_5 V_254 )
{
bool V_255 = false , V_256 = false , V_257 ;
struct V_252 * V_258 = F_96 ( - V_28 ) ;
const struct V_259 * V_64 ;
unsigned int V_181 = 0 ;
struct V_260 * V_261 ;
int V_49 , V_262 ;
int V_263 ;
int V_264 ;
int V_265 ;
F_97 ( V_253 ) ;
V_263 = F_98 ( V_253 ) - F_99 ( V_253 ) ;
if ( F_26 ( ! F_100 ( V_253 , sizeof( * V_261 ) ) ) )
goto V_31;
V_261 = F_101 ( V_253 ) ;
V_264 = V_261 -> V_264 * 4 ;
if ( V_264 < sizeof( * V_261 ) )
goto V_31;
V_265 = F_41 ( V_261 -> V_265 ) ;
V_49 = V_261 -> V_45 ;
if ( F_26 ( ! F_100 ( V_253 , V_264 ) ) )
goto V_31;
F_102 ( V_253 , V_264 ) ;
V_257 = F_103 ( V_253 ) -> V_266 > 0 ;
if ( V_257 )
V_254 &= V_253 -> V_267 -> V_268 ;
F_103 ( V_253 ) -> V_266 += V_264 ;
F_104 ( V_253 ) ;
V_258 = F_96 ( - V_57 ) ;
if ( ! V_253 -> V_269 || V_257 ) {
V_255 = ! ! ( F_105 ( V_253 ) -> V_270 & V_271 ) ;
V_256 = ! ! ( F_105 ( V_253 ) -> V_270 & V_272 ) ;
if ( V_256 && ! ( V_261 -> V_273 & F_17 ( V_274 ) ) )
goto V_31;
}
V_64 = F_93 ( V_275 [ V_49 ] ) ;
if ( F_106 ( V_64 && V_64 -> V_276 . V_277 ) )
V_258 = V_64 -> V_276 . V_277 ( V_253 , V_254 ) ;
if ( F_107 ( V_258 ) )
goto V_31;
V_253 = V_258 ;
do {
V_261 = (struct V_260 * ) ( F_99 ( V_253 ) + V_263 ) ;
if ( V_255 ) {
V_261 -> V_273 = F_17 ( V_181 >> 3 ) ;
if ( V_253 -> V_278 )
V_261 -> V_273 |= F_17 ( V_279 ) ;
V_181 += V_253 -> V_280 - V_263 - V_264 ;
V_262 = V_253 -> V_280 - V_263 ;
} else if ( F_108 ( V_253 ) ) {
if ( ! V_256 ) {
V_261 -> V_265 = F_17 ( V_265 ) ;
V_265 += F_105 ( V_253 ) -> V_281 ;
}
V_262 = F_105 ( V_253 ) -> V_282 +
F_103 ( V_253 ) -> V_283 +
V_253 -> V_284 - ( unsigned char * ) V_261 ;
} else {
if ( ! V_256 )
V_261 -> V_265 = F_17 ( V_265 ++ ) ;
V_262 = V_253 -> V_280 - V_263 ;
}
V_261 -> V_262 = F_17 ( V_262 ) ;
F_109 ( V_261 ) ;
if ( V_257 )
F_110 ( V_253 ) ;
V_253 -> V_285 = ( V_286 * ) V_261 - V_253 -> V_284 ;
} while ( ( V_253 = V_253 -> V_278 ) );
V_31:
return V_258 ;
}
struct V_252 * * F_111 ( struct V_252 * * V_284 , struct V_252 * V_253 )
{
const struct V_259 * V_64 ;
struct V_252 * * V_287 = NULL ;
struct V_252 * V_220 ;
const struct V_260 * V_261 ;
unsigned int V_288 ;
unsigned int V_289 ;
unsigned int V_265 ;
int V_290 = 1 ;
int V_49 ;
V_289 = F_112 ( V_253 ) ;
V_288 = V_289 + sizeof( * V_261 ) ;
V_261 = F_113 ( V_253 , V_289 ) ;
if ( F_114 ( V_253 , V_288 ) ) {
V_261 = F_115 ( V_253 , V_288 , V_289 ) ;
if ( F_26 ( ! V_261 ) )
goto V_31;
}
V_49 = V_261 -> V_45 ;
F_24 () ;
V_64 = F_93 ( V_275 [ V_49 ] ) ;
if ( ! V_64 || ! V_64 -> V_276 . V_291 )
goto V_292;
if ( * ( V_286 * ) V_261 != 0x45 )
goto V_292;
if ( F_26 ( F_116 ( ( V_286 * ) V_261 , 5 ) ) )
goto V_292;
V_265 = F_117 ( * ( T_2 * ) & V_261 -> V_265 ) ;
V_290 = ( V_293 ) ( ( F_117 ( * ( T_2 * ) V_261 ) ^ F_118 ( V_253 ) ) | ( V_265 & ~ V_274 ) ) ;
V_265 >>= 16 ;
for ( V_220 = * V_284 ; V_220 ; V_220 = V_220 -> V_278 ) {
struct V_260 * V_294 ;
V_293 V_295 ;
if ( ! F_119 ( V_220 ) -> V_296 )
continue;
V_294 = (struct V_260 * ) ( V_220 -> V_161 + V_289 ) ;
if ( ( V_261 -> V_45 ^ V_294 -> V_45 ) |
( ( V_297 T_1 ) V_261 -> V_247 ^ ( V_297 T_1 ) V_294 -> V_247 ) |
( ( V_297 T_1 ) V_261 -> V_232 ^ ( V_297 T_1 ) V_294 -> V_232 ) ) {
F_119 ( V_220 ) -> V_296 = 0 ;
continue;
}
F_119 ( V_220 ) -> V_290 |=
( V_261 -> V_298 ^ V_294 -> V_298 ) |
( V_261 -> V_299 ^ V_294 -> V_299 ) |
( ( V_261 -> V_273 ^ V_294 -> V_273 ) & F_17 ( V_274 ) ) ;
F_119 ( V_220 ) -> V_290 |= V_290 ;
V_295 = ( V_293 ) ( V_265 - F_41 ( V_294 -> V_265 ) ) ;
if ( ! F_119 ( V_220 ) -> V_300 ||
! ( V_261 -> V_273 & F_17 ( V_274 ) ) ) {
V_295 ^= F_119 ( V_220 ) -> V_301 ;
V_295 = V_295 ? 0xFFFF : 0 ;
}
if ( F_119 ( V_253 ) -> V_300 )
F_119 ( V_220 ) -> V_295 = V_295 ;
else
F_119 ( V_220 ) -> V_295 |= V_295 ;
}
F_119 ( V_253 ) -> V_300 = ! ! ( V_261 -> V_273 & F_17 ( V_274 ) ) ;
F_119 ( V_253 ) -> V_290 |= V_290 ;
F_120 ( V_253 , V_289 ) ;
F_121 ( V_253 , sizeof( * V_261 ) ) ;
F_122 ( V_253 , F_112 ( V_253 ) ) ;
V_287 = V_64 -> V_276 . V_291 ( V_284 , V_253 ) ;
V_292:
F_27 () ;
V_31:
F_119 ( V_253 ) -> V_290 |= V_290 ;
return V_287 ;
}
static struct V_252 * * F_123 ( struct V_252 * * V_284 ,
struct V_252 * V_253 )
{
if ( F_119 ( V_253 ) -> V_302 ) {
F_119 ( V_253 ) -> V_290 = 1 ;
return NULL ;
}
F_119 ( V_253 ) -> V_302 = 1 ;
return F_111 ( V_284 , V_253 ) ;
}
T_2 F_124 ( void )
{
T_1 V_303 ;
T_1 V_304 ;
struct V_305 V_306 ;
F_125 ( & V_306 ) ;
( void ) F_126 ( V_306 . V_307 , V_308 , & V_303 ) ;
V_304 = V_303 * V_309 ;
V_304 += ( T_1 ) V_306 . V_310 / V_311 ;
return F_38 ( V_304 ) ;
}
int F_127 ( struct V_1 * V_2 , struct V_175 * V_176 , int V_280 , int * V_105 )
{
if ( V_2 -> V_312 == V_114 )
return F_128 ( V_2 , V_176 , V_280 , V_105 ) ;
#if F_129 ( V_313 )
if ( V_2 -> V_312 == V_314 )
return V_315 . V_316 ( V_2 , V_176 , V_280 , V_105 ) ;
#endif
return - V_28 ;
}
int F_130 ( struct V_252 * V_253 , int V_263 )
{
T_6 V_317 = F_17 ( V_253 -> V_280 - V_263 ) ;
struct V_260 * V_261 = (struct V_260 * ) ( V_253 -> V_161 + V_263 ) ;
const struct V_259 * V_64 ;
int V_49 = V_261 -> V_45 ;
int V_27 = - V_318 ;
if ( V_253 -> V_269 )
F_131 ( V_253 , V_263 ) ;
F_132 ( & V_261 -> V_319 , V_261 -> V_262 , V_317 ) ;
V_261 -> V_262 = V_317 ;
F_24 () ;
V_64 = F_93 ( V_275 [ V_49 ] ) ;
if ( F_7 ( ! V_64 || ! V_64 -> V_276 . V_320 ) )
goto V_292;
V_27 = V_64 -> V_276 . V_320 ( V_253 , V_263 + sizeof( * V_261 ) ) ;
V_292:
F_27 () ;
return V_27 ;
}
static int F_133 ( struct V_252 * V_253 , int V_263 )
{
V_253 -> V_269 = 1 ;
F_105 ( V_253 ) -> V_270 |= V_321 ;
return F_130 ( V_253 , V_263 ) ;
}
int F_134 ( struct V_1 * * V_2 , unsigned short V_322 ,
unsigned short type , unsigned char V_45 ,
struct V_44 * V_44 )
{
struct V_24 * V_1 ;
int V_323 = F_135 ( V_44 , V_322 , type , V_45 , & V_1 ) ;
if ( V_323 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_324 = V_325 ;
( * V_2 ) -> V_20 -> V_326 ( * V_2 ) ;
}
return V_323 ;
}
T_7 F_136 ( void T_8 * V_327 , int V_328 , int V_329 )
{
return * ( ( ( unsigned long * ) F_137 ( V_327 , V_328 ) ) + V_329 ) ;
}
unsigned long F_138 ( void T_8 * V_327 , int V_329 )
{
unsigned long V_330 = 0 ;
int V_331 ;
F_139 (i)
V_330 += F_136 ( V_327 , V_331 , V_329 ) ;
return V_330 ;
}
T_7 F_140 ( void T_8 * V_327 , int V_328 , int V_329 ,
T_3 V_332 )
{
void * V_333 ;
struct V_334 * V_335 ;
T_7 V_336 ;
unsigned int V_337 ;
V_333 = F_137 ( V_327 , V_328 ) ;
V_335 = (struct V_334 * ) ( V_333 + V_332 ) ;
do {
V_337 = F_141 ( V_335 ) ;
V_336 = * ( ( ( T_7 * ) V_333 ) + V_329 ) ;
} while ( F_142 ( V_335 , V_337 ) );
return V_336 ;
}
T_7 F_143 ( void T_8 * V_327 , int V_329 , T_3 V_332 )
{
T_7 V_330 = 0 ;
int V_328 ;
F_139 (cpu) {
V_330 += F_140 ( V_327 , V_328 , V_329 , V_332 ) ;
}
return V_330 ;
}
static T_9 int F_144 ( struct V_44 * V_44 )
{
int V_331 ;
V_44 -> V_327 . V_338 = F_145 ( struct V_339 ) ;
if ( ! V_44 -> V_327 . V_338 )
goto V_340;
V_44 -> V_327 . V_341 = F_145 ( struct V_342 ) ;
if ( ! V_44 -> V_327 . V_341 )
goto V_343;
F_139 (i) {
struct V_342 * V_344 ;
V_344 = F_137 ( V_44 -> V_327 . V_341 , V_331 ) ;
F_146 ( & V_344 -> V_335 ) ;
}
V_44 -> V_327 . V_345 = F_145 ( struct V_346 ) ;
if ( ! V_44 -> V_327 . V_345 )
goto V_347;
V_44 -> V_327 . V_348 = F_145 ( struct V_349 ) ;
if ( ! V_44 -> V_327 . V_348 )
goto V_350;
V_44 -> V_327 . V_351 = F_145 ( struct V_349 ) ;
if ( ! V_44 -> V_327 . V_351 )
goto V_352;
V_44 -> V_327 . V_353 = F_145 ( struct V_354 ) ;
if ( ! V_44 -> V_327 . V_353 )
goto V_355;
V_44 -> V_327 . V_356 = F_147 ( sizeof( struct V_357 ) ,
V_69 ) ;
if ( ! V_44 -> V_327 . V_356 )
goto V_358;
F_148 ( V_44 ) ;
return 0 ;
V_358:
F_149 ( V_44 -> V_327 . V_353 ) ;
V_355:
F_149 ( V_44 -> V_327 . V_351 ) ;
V_352:
F_149 ( V_44 -> V_327 . V_348 ) ;
V_350:
F_149 ( V_44 -> V_327 . V_345 ) ;
V_347:
F_149 ( V_44 -> V_327 . V_341 ) ;
V_343:
F_149 ( V_44 -> V_327 . V_338 ) ;
V_340:
return - V_359 ;
}
static T_10 void F_150 ( struct V_44 * V_44 )
{
F_9 ( V_44 -> V_327 . V_356 ) ;
F_149 ( V_44 -> V_327 . V_353 ) ;
F_149 ( V_44 -> V_327 . V_351 ) ;
F_149 ( V_44 -> V_327 . V_348 ) ;
F_149 ( V_44 -> V_327 . V_345 ) ;
F_149 ( V_44 -> V_327 . V_341 ) ;
F_149 ( V_44 -> V_327 . V_338 ) ;
}
static int T_11 F_151 ( void )
{
return F_152 ( & V_360 ) ;
}
static T_9 int F_153 ( struct V_44 * V_44 )
{
F_154 ( & V_44 -> V_78 . V_361 . V_362 ) ;
V_44 -> V_78 . V_361 . V_363 [ 0 ] = 32768 ;
V_44 -> V_78 . V_361 . V_363 [ 1 ] = 60999 ;
F_154 ( & V_44 -> V_78 . V_364 . V_362 ) ;
V_44 -> V_78 . V_364 . V_363 [ 0 ] = F_155 ( & V_365 , 1 ) ;
V_44 -> V_78 . V_364 . V_363 [ 1 ] = F_155 ( & V_365 , 0 ) ;
V_44 -> V_78 . V_366 = V_367 ;
V_44 -> V_78 . V_248 = 0 ;
V_44 -> V_78 . V_368 = 1 ;
return 0 ;
}
static T_10 void F_156 ( struct V_44 * V_44 )
{
}
static int T_11 F_157 ( void )
{
return F_152 ( & V_369 ) ;
}
static int T_11 F_158 ( void )
{
if ( F_159 () < 0 )
F_160 ( L_9 , V_249 ) ;
if ( F_161 () < 0 )
F_160 ( L_10 , V_249 ) ;
F_162 ( & V_370 ) ;
F_163 ( & V_371 , V_372 ) ;
return 0 ;
}
static int T_11 F_164 ( void )
{
struct V_47 * V_373 ;
struct V_221 * V_374 ;
int V_323 = - V_28 ;
F_165 ( sizeof( struct V_375 ) ) ;
V_323 = F_166 ( & V_376 , 1 ) ;
if ( V_323 )
goto V_31;
V_323 = F_166 ( & V_377 , 1 ) ;
if ( V_323 )
goto V_378;
V_323 = F_166 ( & V_379 , 1 ) ;
if ( V_323 )
goto V_380;
V_323 = F_166 ( & V_381 , 1 ) ;
if ( V_323 )
goto V_382;
( void ) F_167 ( & V_383 ) ;
#ifdef F_168
F_169 () ;
#endif
if ( F_170 ( & V_384 , V_385 ) < 0 )
F_160 ( L_11 , V_249 ) ;
if ( F_170 ( & V_386 , V_387 ) < 0 )
F_160 ( L_12 , V_249 ) ;
if ( F_170 ( & V_388 , V_159 ) < 0 )
F_160 ( L_13 , V_249 ) ;
#ifdef F_171
if ( F_170 ( & V_389 , V_390 ) < 0 )
F_160 ( L_14 , V_249 ) ;
#endif
for ( V_374 = & V_227 [ 0 ] ; V_374 < & V_227 [ V_225 ] ; ++ V_374 )
F_172 ( V_374 ) ;
for ( V_373 = V_391 ; V_373 < & V_391 [ V_392 ] ; ++ V_373 )
F_73 ( V_373 ) ;
F_173 () ;
F_174 () ;
F_175 () ;
F_176 () ;
F_177 () ;
F_178 () ;
F_179 () ;
if ( F_180 () < 0 )
F_181 ( L_15 ) ;
#if F_182 ( V_393 )
if ( F_183 () )
F_160 ( L_16 , V_249 ) ;
#endif
if ( F_157 () )
F_160 ( L_17 , V_249 ) ;
if ( F_151 () )
F_160 ( L_18 , V_249 ) ;
F_184 () ;
F_185 () ;
F_186 ( & V_394 ) ;
F_187 () ;
V_323 = 0 ;
V_31:
return V_323 ;
V_382:
F_188 ( & V_379 ) ;
V_380:
F_188 ( & V_377 ) ;
V_378:
F_188 ( & V_376 ) ;
goto V_31;
}
static int T_11 F_184 ( void )
{
int V_323 = 0 ;
if ( F_189 () )
goto V_395;
if ( F_190 () )
goto V_396;
if ( F_191 () )
goto V_397;
if ( F_192 () )
goto V_398;
if ( F_193 () )
goto V_399;
V_31:
return V_323 ;
V_399:
F_194 () ;
V_398:
F_195 () ;
V_397:
F_196 () ;
V_396:
F_197 () ;
V_395:
V_323 = - V_359 ;
goto V_31;
}
static int T_11 F_184 ( void )
{
return 0 ;
}
