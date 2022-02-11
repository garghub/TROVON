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
! F_19 ( V_2 ) -> V_37 . V_38 ) {
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
F_21 ( true ) ;
}
V_27 = F_22 ( V_2 , V_25 ) ;
if ( V_27 )
goto V_31;
}
V_2 -> V_42 = V_25 ;
V_27 = 0 ;
V_31:
F_16 ( V_2 ) ;
return V_27 ;
}
static int F_23 ( struct V_43 * V_43 , struct V_24 * V_1 , int V_44 ,
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
F_24 () ;
F_25 (answer, &inetsw[sock->type], list) {
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
if ( F_26 ( V_27 ) ) {
if ( V_51 < 2 ) {
F_27 () ;
if ( ++ V_51 == 1 )
F_28 ( L_3 ,
V_56 , V_44 , V_1 -> type ) ;
else
F_28 ( L_4 ,
V_56 , V_44 ) ;
goto V_52;
} else
goto V_57;
}
V_27 = - V_58 ;
if ( V_1 -> type == V_59 && ! V_45 &&
! F_29 ( V_43 -> V_60 , V_61 ) )
goto V_57;
V_1 -> V_62 = V_47 -> V_62 ;
V_49 = V_47 -> V_63 ;
V_50 = V_47 -> V_64 ;
F_27 () ;
F_7 ( ! V_49 -> V_65 ) ;
V_27 = - V_66 ;
V_2 = F_30 ( V_43 , V_56 , V_67 , V_49 , V_45 ) ;
if ( ! V_2 )
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
F_31 ( V_1 , V_2 ) ;
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
F_32 ( V_2 ) ;
if ( V_4 -> V_19 ) {
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_2 -> V_20 -> V_93 ( V_2 ) ;
}
if ( V_2 -> V_20 -> V_94 ) {
V_27 = V_2 -> V_20 -> V_94 ( V_2 ) ;
if ( V_27 )
F_33 ( V_2 ) ;
}
V_31:
return V_27 ;
V_57:
F_27 () ;
goto V_31;
}
int F_34 ( struct V_24 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 ) {
long V_95 ;
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
V_105 -> V_115 . V_116 != F_38 ( V_117 ) )
goto V_31;
}
V_108 = F_39 ( V_43 , V_2 -> V_118 ) ? : V_108 ;
V_107 = F_40 ( V_43 , V_105 -> V_115 . V_116 , V_108 ) ;
V_27 = - V_119 ;
if ( ! V_43 -> V_76 . V_120 &&
! ( V_4 -> V_121 || V_4 -> V_122 ) &&
V_105 -> V_115 . V_116 != F_38 ( V_117 ) &&
V_107 != V_123 &&
V_107 != V_124 &&
V_107 != V_125 )
goto V_31;
V_106 = F_41 ( V_105 -> V_126 ) ;
V_27 = - V_127 ;
if ( V_106 && V_106 < V_128 &&
! F_29 ( V_43 -> V_60 , V_129 ) )
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
F_42 ( V_2 ) ;
V_27 = 0 ;
V_130:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_43 ( struct V_24 * V_1 , struct V_101 * V_102 ,
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
static long F_44 ( struct V_1 * V_2 , long V_143 , int V_144 )
{
F_45 ( V_145 ) ;
F_46 ( F_47 ( V_2 ) , & V_145 , V_146 ) ;
V_2 -> V_147 += V_144 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_148 | V_149 ) ) {
F_16 ( V_2 ) ;
V_143 = F_48 ( V_143 ) ;
F_15 ( V_2 ) ;
if ( F_49 ( V_97 ) || ! V_143 )
break;
F_46 ( F_47 ( V_2 ) , & V_145 , V_146 ) ;
}
F_50 ( F_47 ( V_2 ) , & V_145 ) ;
V_2 -> V_147 -= V_144 ;
return V_143 ;
}
int F_51 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_143 ;
if ( V_103 < sizeof( V_102 -> V_140 ) )
return - V_28 ;
if ( V_102 -> V_140 == V_114 ) {
V_27 = V_2 -> V_20 -> V_141 ( V_2 , V_64 ) ;
V_1 -> V_29 = V_27 ? V_150 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_151 :
V_27 = - V_152 ;
goto V_31;
case V_153 :
V_27 = - V_154 ;
break;
case V_30 :
V_27 = - V_152 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_142 ( V_2 , V_102 , V_103 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_153 ;
V_27 = - V_155 ;
break;
}
V_143 = F_52 ( V_2 , V_64 & V_156 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_148 | V_149 ) ) {
int V_144 = ( V_2 -> V_83 == V_157 ) &&
F_53 ( V_2 ) -> V_158 &&
F_53 ( V_2 ) -> V_158 -> V_159 ? 1 : 0 ;
if ( ! V_143 || ! F_44 ( V_2 , V_143 , V_144 ) )
goto V_31;
V_27 = F_54 ( V_143 ) ;
if ( F_49 ( V_97 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_160;
V_1 -> V_29 = V_151 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_160:
V_27 = V_160 ( V_2 ) ? : - V_161 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_141 ( V_2 , V_64 ) )
V_1 -> V_29 = V_150 ;
goto V_31;
}
int F_55 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_51 ( V_1 , V_102 , V_103 , V_64 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_56 ( struct V_24 * V_1 , struct V_24 * V_162 , int V_64 )
{
struct V_1 * V_163 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_164 = V_163 -> V_20 -> V_165 ( V_163 , V_64 , & V_27 ) ;
if ( ! V_164 )
goto V_166;
F_15 ( V_164 ) ;
F_57 ( V_164 ) ;
F_7 ( ! ( ( 1 << V_164 -> V_9 ) &
( V_167 | V_149 |
V_168 | V_32 ) ) ) ;
F_58 ( V_164 , V_162 ) ;
V_162 -> V_29 = V_151 ;
V_27 = 0 ;
F_16 ( V_164 ) ;
V_166:
return V_27 ;
}
int F_59 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int * V_169 , int V_170 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_60 ( struct V_104 * , sin , V_102 ) ;
sin -> V_111 = V_112 ;
if ( V_170 ) {
if ( ! V_4 -> V_139 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_148 ) ) &&
V_170 == 1 ) )
return - V_171 ;
sin -> V_126 = V_4 -> V_139 ;
sin -> V_115 . V_116 = V_4 -> V_138 ;
} else {
T_2 V_105 = V_4 -> V_131 ;
if ( ! V_105 )
V_105 = V_4 -> V_132 ;
sin -> V_126 = V_4 -> V_23 ;
sin -> V_115 . V_116 = V_105 ;
}
memset ( sin -> V_172 , 0 , sizeof( sin -> V_172 ) ) ;
* V_169 = sizeof( * sin ) ;
return 0 ;
}
int F_61 ( struct V_24 * V_1 , struct V_173 * V_174 , T_3 V_175 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_57 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_176 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_177 ( V_2 , V_174 , V_175 ) ;
}
T_4 F_62 ( struct V_24 * V_1 , struct V_178 * V_178 , int V_179 ,
T_3 V_175 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_57 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_176 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_180 )
return V_2 -> V_20 -> V_180 ( V_2 , V_178 , V_179 , V_175 , V_64 ) ;
return F_63 ( V_1 , V_178 , V_179 , V_175 , V_64 ) ;
}
int F_64 ( struct V_24 * V_1 , struct V_173 * V_174 , T_3 V_175 ,
int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_103 = 0 ;
int V_27 ;
F_57 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_181 ( V_2 , V_174 , V_175 , V_64 & V_182 ,
V_64 & ~ V_182 , & V_103 ) ;
if ( V_27 >= 0 )
V_174 -> V_183 = V_103 ;
return V_27 ;
}
int F_65 ( struct V_24 * V_1 , int V_184 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_184 ++ ;
if ( ( V_184 & ~ V_185 ) || ! V_184 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_153 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_148 | V_149 | V_32 ) )
V_1 -> V_29 = V_150 ;
else
V_1 -> V_29 = V_151 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_171 ;
default:
V_2 -> V_186 |= V_184 ;
if ( V_2 -> V_20 -> V_187 )
V_2 -> V_20 -> V_187 ( V_2 , V_184 ) ;
break;
case V_34 :
if ( ! ( V_184 & V_188 ) )
break;
case V_189 :
V_27 = V_2 -> V_20 -> V_141 ( V_2 , V_156 ) ;
V_1 -> V_29 = V_27 ? V_150 : V_30 ;
break;
}
V_2 -> V_190 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_66 ( struct V_24 * V_1 , unsigned int V_191 , unsigned long V_192 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_43 * V_43 = F_37 ( V_2 ) ;
switch ( V_191 ) {
case V_193 :
V_27 = F_67 ( V_2 , (struct V_194 V_195 * ) V_192 ) ;
break;
case V_196 :
V_27 = F_68 ( V_2 , (struct V_197 V_195 * ) V_192 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
V_27 = F_69 ( V_43 , V_191 , ( void V_195 * ) V_192 ) ;
break;
case V_201 :
case V_202 :
case V_203 :
V_27 = F_70 ( V_43 , V_191 , ( void V_195 * ) V_192 ) ;
break;
case V_204 :
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
V_27 = F_71 ( V_43 , V_191 , ( void V_195 * ) V_192 ) ;
break;
default:
if ( V_2 -> V_20 -> V_215 )
V_27 = V_2 -> V_20 -> V_215 ( V_2 , V_191 , V_192 ) ;
else
V_27 = - V_216 ;
break;
}
return V_27 ;
}
static int F_72 ( struct V_24 * V_1 , unsigned int V_191 , unsigned long V_192 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_216 ;
if ( V_2 -> V_20 -> V_217 )
V_27 = V_2 -> V_20 -> V_217 ( V_2 , V_191 , V_192 ) ;
return V_27 ;
}
void F_73 ( struct V_46 * V_218 )
{
struct V_219 * V_220 ;
struct V_46 * V_47 ;
int V_44 = V_218 -> V_44 ;
struct V_219 * V_221 ;
F_74 ( & V_222 ) ;
if ( V_218 -> type >= V_223 )
goto V_224;
V_47 = NULL ;
V_221 = & V_225 [ V_218 -> type ] ;
F_75 (lh, &inetsw[p->type]) {
V_47 = F_76 ( V_220 , struct V_46 , V_226 ) ;
if ( V_227 & V_47 -> V_64 ) {
if ( V_44 == V_47 -> V_44 )
break;
V_221 = V_220 ;
}
V_47 = NULL ;
}
if ( V_47 )
goto V_228;
F_77 ( & V_218 -> V_226 , V_221 ) ;
V_31:
F_78 ( & V_222 ) ;
return;
V_228:
F_5 ( L_5 , V_44 ) ;
goto V_31;
V_224:
F_5 ( L_6 ,
V_218 -> type ) ;
goto V_31;
}
void F_79 ( struct V_46 * V_218 )
{
if ( V_227 & V_218 -> V_64 ) {
F_5 ( L_7 ,
V_218 -> V_44 ) ;
} else {
F_74 ( & V_222 ) ;
F_80 ( & V_218 -> V_226 ) ;
F_78 ( & V_222 ) ;
F_81 () ;
}
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_229 = V_4 -> V_132 ;
T_2 V_230 = V_4 -> V_138 ;
struct V_231 * V_232 ;
struct V_233 * V_234 ;
T_2 V_235 ;
struct V_236 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_83 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_237 . V_238 )
V_230 = V_16 -> V_237 . V_239 ;
V_232 = & V_4 -> V_240 . V_241 . V_242 . V_243 ;
V_234 = F_84 ( V_232 , V_230 , 0 , F_85 ( V_2 ) ,
V_2 -> V_118 , V_2 -> V_83 ,
V_4 -> V_23 , V_4 -> V_139 , V_2 ) ;
if ( F_86 ( V_234 ) )
return F_87 ( V_234 ) ;
F_88 ( V_2 , & V_234 -> V_244 ) ;
V_235 = V_232 -> V_245 ;
if ( V_235 == V_229 )
return 0 ;
if ( V_246 > 1 ) {
F_89 ( L_8 ,
V_247 , & V_229 , & V_235 ) ;
}
V_4 -> V_132 = V_4 -> V_131 = V_235 ;
F_90 ( V_2 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_233 * V_234 = (struct V_233 * ) F_92 ( V_2 , 0 ) ;
T_2 V_230 ;
struct V_236 * V_16 ;
struct V_231 * V_232 ;
int V_27 ;
if ( V_234 )
return 0 ;
F_24 () ;
V_16 = F_93 ( V_4 -> V_16 ) ;
V_230 = V_4 -> V_138 ;
if ( V_16 && V_16 -> V_237 . V_238 )
V_230 = V_16 -> V_237 . V_239 ;
F_27 () ;
V_232 = & V_4 -> V_240 . V_241 . V_242 . V_243 ;
V_234 = F_94 ( F_37 ( V_2 ) , V_232 , V_2 , V_230 , V_4 -> V_132 ,
V_4 -> V_139 , V_4 -> V_23 ,
V_2 -> V_83 , F_85 ( V_2 ) ,
V_2 -> V_118 ) ;
if ( ! F_86 ( V_234 ) ) {
V_27 = 0 ;
F_88 ( V_2 , & V_234 -> V_244 ) ;
} else {
V_27 = F_87 ( V_234 ) ;
V_2 -> V_248 = 0 ;
if ( ! V_246 ||
V_2 -> V_9 != V_189 ||
( V_2 -> V_135 & V_136 ) ||
( V_27 = F_82 ( V_2 ) ) != 0 )
V_2 -> V_249 = - V_27 ;
}
return V_27 ;
}
static struct V_250 * F_95 ( struct V_250 * V_251 ,
T_5 V_252 )
{
struct V_250 * V_253 = F_96 ( - V_28 ) ;
const struct V_254 * V_62 ;
unsigned int V_179 = 0 ;
bool V_255 , V_256 ;
struct V_257 * V_258 ;
int V_48 ;
int V_259 ;
int V_260 ;
int V_261 ;
if ( F_26 ( F_97 ( V_251 ) -> V_262 &
~ ( V_263 |
V_264 |
V_265 |
V_266 |
V_267 |
V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
V_273 |
V_274 |
0 ) ) )
goto V_31;
F_98 ( V_251 ) ;
V_259 = F_99 ( V_251 ) - F_100 ( V_251 ) ;
if ( F_26 ( ! F_101 ( V_251 , sizeof( * V_258 ) ) ) )
goto V_31;
V_258 = F_102 ( V_251 ) ;
V_260 = V_258 -> V_260 * 4 ;
if ( V_260 < sizeof( * V_258 ) )
goto V_31;
V_261 = F_41 ( V_258 -> V_261 ) ;
V_48 = V_258 -> V_44 ;
if ( F_26 ( ! F_101 ( V_251 , V_260 ) ) )
goto V_31;
F_103 ( V_251 , V_260 ) ;
V_256 = F_104 ( V_251 ) -> V_275 > 0 ;
if ( V_256 )
V_252 &= V_251 -> V_276 -> V_277 ;
F_104 ( V_251 ) -> V_275 += V_260 ;
F_105 ( V_251 ) ;
V_253 = F_96 ( - V_55 ) ;
if ( V_251 -> V_278 &&
F_97 ( V_251 ) -> V_262 & ( V_270 | V_269 ) )
V_255 = V_48 == V_279 && V_256 ;
else
V_255 = V_48 == V_279 && ! V_251 -> V_278 ;
V_62 = F_93 ( V_280 [ V_48 ] ) ;
if ( F_106 ( V_62 && V_62 -> V_281 . V_282 ) )
V_253 = V_62 -> V_281 . V_282 ( V_251 , V_252 ) ;
if ( F_107 ( V_253 ) )
goto V_31;
V_251 = V_253 ;
do {
V_258 = (struct V_257 * ) ( F_100 ( V_251 ) + V_259 ) ;
if ( V_255 ) {
V_258 -> V_261 = F_17 ( V_261 ) ;
V_258 -> V_283 = F_17 ( V_179 >> 3 ) ;
if ( V_251 -> V_284 )
V_258 -> V_283 |= F_17 ( V_285 ) ;
V_179 += V_251 -> V_286 - V_259 - V_260 ;
} else {
V_258 -> V_261 = F_17 ( V_261 ++ ) ;
}
V_258 -> V_287 = F_17 ( V_251 -> V_286 - V_259 ) ;
F_108 ( V_258 ) ;
if ( V_256 )
F_109 ( V_251 ) ;
V_251 -> V_288 = ( V_289 * ) V_258 - V_251 -> V_290 ;
} while ( ( V_251 = V_251 -> V_284 ) );
V_31:
return V_253 ;
}
static struct V_250 * * F_110 ( struct V_250 * * V_290 ,
struct V_250 * V_251 )
{
const struct V_254 * V_62 ;
struct V_250 * * V_291 = NULL ;
struct V_250 * V_218 ;
const struct V_257 * V_258 ;
unsigned int V_292 ;
unsigned int V_293 ;
unsigned int V_261 ;
int V_294 = 1 ;
int V_48 ;
V_293 = F_111 ( V_251 ) ;
V_292 = V_293 + sizeof( * V_258 ) ;
V_258 = F_112 ( V_251 , V_293 ) ;
if ( F_113 ( V_251 , V_292 ) ) {
V_258 = F_114 ( V_251 , V_292 , V_293 ) ;
if ( F_26 ( ! V_258 ) )
goto V_31;
}
V_48 = V_258 -> V_44 ;
F_24 () ;
V_62 = F_93 ( V_280 [ V_48 ] ) ;
if ( ! V_62 || ! V_62 -> V_281 . V_295 )
goto V_296;
if ( * ( V_289 * ) V_258 != 0x45 )
goto V_296;
if ( F_26 ( F_115 ( ( V_289 * ) V_258 , 5 ) ) )
goto V_296;
V_261 = F_116 ( * ( T_2 * ) & V_258 -> V_261 ) ;
V_294 = ( V_297 ) ( ( F_116 ( * ( T_2 * ) V_258 ) ^ F_117 ( V_251 ) ) | ( V_261 & ~ V_298 ) ) ;
V_261 >>= 16 ;
for ( V_218 = * V_290 ; V_218 ; V_218 = V_218 -> V_284 ) {
struct V_257 * V_299 ;
if ( ! F_118 ( V_218 ) -> V_300 )
continue;
V_299 = (struct V_257 * ) ( V_218 -> V_159 + V_293 ) ;
if ( ( V_258 -> V_44 ^ V_299 -> V_44 ) |
( ( V_301 T_1 ) V_258 -> V_245 ^ ( V_301 T_1 ) V_299 -> V_245 ) |
( ( V_301 T_1 ) V_258 -> V_230 ^ ( V_301 T_1 ) V_299 -> V_230 ) ) {
F_118 ( V_218 ) -> V_300 = 0 ;
continue;
}
F_118 ( V_218 ) -> V_294 |=
( V_258 -> V_302 ^ V_299 -> V_302 ) |
( V_258 -> V_303 ^ V_299 -> V_303 ) |
( ( V_258 -> V_283 ^ V_299 -> V_283 ) & F_17 ( V_298 ) ) ;
F_118 ( V_218 ) -> V_304 =
( ( V_297 ) ( F_41 ( V_299 -> V_261 ) + F_118 ( V_218 ) -> V_305 ) ^ V_261 ) ;
F_118 ( V_218 ) -> V_294 |= V_294 ;
}
F_118 ( V_251 ) -> V_294 |= V_294 ;
F_119 ( V_251 , V_293 ) ;
F_120 ( V_251 , sizeof( * V_258 ) ) ;
F_121 ( V_251 , F_111 ( V_251 ) ) ;
V_291 = V_62 -> V_281 . V_295 ( V_290 , V_251 ) ;
V_296:
F_27 () ;
V_31:
F_118 ( V_251 ) -> V_294 |= V_294 ;
return V_291 ;
}
int F_122 ( struct V_1 * V_2 , struct V_173 * V_174 , int V_286 , int * V_103 )
{
if ( V_2 -> V_306 == V_112 )
return F_123 ( V_2 , V_174 , V_286 , V_103 ) ;
#if F_124 ( V_307 )
if ( V_2 -> V_306 == V_308 )
return V_309 . V_310 ( V_2 , V_174 , V_286 , V_103 ) ;
#endif
return - V_28 ;
}
static int F_125 ( struct V_250 * V_251 , int V_259 )
{
T_6 V_311 = F_17 ( V_251 -> V_286 - V_259 ) ;
struct V_257 * V_258 = (struct V_257 * ) ( V_251 -> V_159 + V_259 ) ;
const struct V_254 * V_62 ;
int V_48 = V_258 -> V_44 ;
int V_27 = - V_312 ;
if ( V_251 -> V_278 )
F_126 ( V_251 , V_259 ) ;
F_127 ( & V_258 -> V_313 , V_258 -> V_287 , V_311 ) ;
V_258 -> V_287 = V_311 ;
F_24 () ;
V_62 = F_93 ( V_280 [ V_48 ] ) ;
if ( F_7 ( ! V_62 || ! V_62 -> V_281 . V_314 ) )
goto V_296;
V_27 = V_62 -> V_281 . V_314 ( V_251 , V_259 + sizeof( * V_258 ) ) ;
V_296:
F_27 () ;
return V_27 ;
}
int F_128 ( struct V_1 * * V_2 , unsigned short V_315 ,
unsigned short type , unsigned char V_44 ,
struct V_43 * V_43 )
{
struct V_24 * V_1 ;
int V_316 = F_129 ( V_43 , V_315 , type , V_44 , & V_1 ) ;
if ( V_316 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_317 = V_318 ;
( * V_2 ) -> V_20 -> V_319 ( * V_2 ) ;
}
return V_316 ;
}
T_7 F_130 ( void T_8 * V_320 , int V_321 , int V_322 )
{
return * ( ( ( unsigned long * ) F_131 ( V_320 , V_321 ) ) + V_322 ) ;
}
unsigned long F_132 ( void T_8 * V_320 , int V_322 )
{
unsigned long V_323 = 0 ;
int V_324 ;
F_133 (i)
V_323 += F_130 ( V_320 , V_324 , V_322 ) ;
return V_323 ;
}
T_7 F_134 ( void T_8 * V_320 , int V_321 , int V_322 ,
T_3 V_325 )
{
void * V_326 ;
struct V_327 * V_328 ;
T_7 V_329 ;
unsigned int V_330 ;
V_326 = F_131 ( V_320 , V_321 ) ;
V_328 = (struct V_327 * ) ( V_326 + V_325 ) ;
do {
V_330 = F_135 ( V_328 ) ;
V_329 = * ( ( ( T_7 * ) V_326 ) + V_322 ) ;
} while ( F_136 ( V_328 , V_330 ) );
return V_329 ;
}
T_7 F_137 ( void T_8 * V_320 , int V_322 , T_3 V_325 )
{
T_7 V_323 = 0 ;
int V_321 ;
F_133 (cpu) {
V_323 += F_134 ( V_320 , V_321 , V_322 , V_325 ) ;
}
return V_323 ;
}
static T_9 int F_138 ( struct V_43 * V_43 )
{
int V_324 ;
V_43 -> V_320 . V_331 = F_139 ( struct V_332 ) ;
if ( ! V_43 -> V_320 . V_331 )
goto V_333;
V_43 -> V_320 . V_334 = F_139 ( struct V_335 ) ;
if ( ! V_43 -> V_320 . V_334 )
goto V_336;
F_133 (i) {
struct V_335 * V_337 ;
V_337 = F_131 ( V_43 -> V_320 . V_334 , V_324 ) ;
F_140 ( & V_337 -> V_328 ) ;
}
V_43 -> V_320 . V_338 = F_139 ( struct V_339 ) ;
if ( ! V_43 -> V_320 . V_338 )
goto V_340;
V_43 -> V_320 . V_341 = F_139 ( struct V_342 ) ;
if ( ! V_43 -> V_320 . V_341 )
goto V_343;
V_43 -> V_320 . V_344 = F_139 ( struct V_342 ) ;
if ( ! V_43 -> V_320 . V_344 )
goto V_345;
V_43 -> V_320 . V_346 = F_139 ( struct V_347 ) ;
if ( ! V_43 -> V_320 . V_346 )
goto V_348;
V_43 -> V_320 . V_349 = F_141 ( sizeof( struct V_350 ) ,
V_67 ) ;
if ( ! V_43 -> V_320 . V_349 )
goto V_351;
F_142 ( V_43 ) ;
return 0 ;
V_351:
F_143 ( V_43 -> V_320 . V_346 ) ;
V_348:
F_143 ( V_43 -> V_320 . V_344 ) ;
V_345:
F_143 ( V_43 -> V_320 . V_341 ) ;
V_343:
F_143 ( V_43 -> V_320 . V_338 ) ;
V_340:
F_143 ( V_43 -> V_320 . V_334 ) ;
V_336:
F_143 ( V_43 -> V_320 . V_331 ) ;
V_333:
return - V_352 ;
}
static T_10 void F_144 ( struct V_43 * V_43 )
{
F_9 ( V_43 -> V_320 . V_349 ) ;
F_143 ( V_43 -> V_320 . V_346 ) ;
F_143 ( V_43 -> V_320 . V_344 ) ;
F_143 ( V_43 -> V_320 . V_341 ) ;
F_143 ( V_43 -> V_320 . V_338 ) ;
F_143 ( V_43 -> V_320 . V_334 ) ;
F_143 ( V_43 -> V_320 . V_331 ) ;
}
static int T_11 F_145 ( void )
{
return F_146 ( & V_353 ) ;
}
static T_9 int F_147 ( struct V_43 * V_43 )
{
F_148 ( & V_43 -> V_76 . V_354 . V_355 ) ;
V_43 -> V_76 . V_354 . V_356 [ 0 ] = 32768 ;
V_43 -> V_76 . V_354 . V_356 [ 1 ] = 60999 ;
F_148 ( & V_43 -> V_76 . V_357 . V_355 ) ;
V_43 -> V_76 . V_357 . V_356 [ 0 ] = F_149 ( & V_358 , 1 ) ;
V_43 -> V_76 . V_357 . V_356 [ 1 ] = F_149 ( & V_358 , 0 ) ;
return 0 ;
}
static T_10 void F_150 ( struct V_43 * V_43 )
{
}
static int T_11 F_151 ( void )
{
return F_146 ( & V_359 ) ;
}
static int T_11 F_152 ( void )
{
if ( F_153 () < 0 )
F_154 ( L_9 , V_247 ) ;
if ( F_155 () < 0 )
F_154 ( L_10 , V_247 ) ;
F_156 ( & V_360 ) ;
F_157 ( & V_361 , V_362 ) ;
return 0 ;
}
static int T_11 F_158 ( void )
{
struct V_46 * V_363 ;
struct V_219 * V_364 ;
int V_316 = - V_28 ;
F_159 ( sizeof( struct V_365 ) ) ;
V_316 = F_160 ( & V_366 , 1 ) ;
if ( V_316 )
goto V_31;
V_316 = F_160 ( & V_367 , 1 ) ;
if ( V_316 )
goto V_368;
V_316 = F_160 ( & V_369 , 1 ) ;
if ( V_316 )
goto V_370;
V_316 = F_160 ( & V_371 , 1 ) ;
if ( V_316 )
goto V_372;
( void ) F_161 ( & V_373 ) ;
#ifdef F_162
F_163 () ;
#endif
if ( F_164 ( & V_374 , V_375 ) < 0 )
F_154 ( L_11 , V_247 ) ;
if ( F_164 ( & V_376 , V_279 ) < 0 )
F_154 ( L_12 , V_247 ) ;
if ( F_164 ( & V_377 , V_157 ) < 0 )
F_154 ( L_13 , V_247 ) ;
#ifdef F_165
if ( F_164 ( & V_378 , V_379 ) < 0 )
F_154 ( L_14 , V_247 ) ;
#endif
for ( V_364 = & V_225 [ 0 ] ; V_364 < & V_225 [ V_223 ] ; ++ V_364 )
F_166 ( V_364 ) ;
for ( V_363 = V_380 ; V_363 < & V_380 [ V_381 ] ; ++ V_363 )
F_73 ( V_363 ) ;
F_167 () ;
F_168 () ;
F_169 () ;
F_170 () ;
F_171 () ;
F_172 () ;
F_173 () ;
if ( F_174 () < 0 )
F_175 ( L_15 ) ;
#if F_176 ( V_382 )
if ( F_177 () )
F_154 ( L_16 , V_247 ) ;
#endif
if ( F_151 () )
F_154 ( L_17 , V_247 ) ;
if ( F_145 () )
F_154 ( L_18 , V_247 ) ;
F_178 () ;
F_179 () ;
F_180 ( & V_383 ) ;
F_181 () ;
V_316 = 0 ;
V_31:
return V_316 ;
V_372:
F_182 ( & V_369 ) ;
V_370:
F_182 ( & V_367 ) ;
V_368:
F_182 ( & V_366 ) ;
goto V_31;
}
static int T_11 F_178 ( void )
{
int V_316 = 0 ;
if ( F_183 () )
goto V_384;
if ( F_184 () )
goto V_385;
if ( F_185 () )
goto V_386;
if ( F_186 () )
goto V_387;
if ( F_187 () )
goto V_388;
V_31:
return V_316 ;
V_388:
F_188 () ;
V_387:
F_189 () ;
V_386:
F_190 () ;
V_385:
F_191 () ;
V_384:
V_316 = - V_352 ;
goto V_31;
}
static int T_11 F_178 ( void )
{
return 0 ;
}
