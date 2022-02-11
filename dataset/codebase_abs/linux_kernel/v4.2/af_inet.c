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
if ( ! V_43 -> V_76 . V_117 &&
! ( V_4 -> V_118 || V_4 -> V_119 ) &&
V_105 -> V_113 . V_114 != F_38 ( V_115 ) &&
V_107 != V_120 &&
V_107 != V_121 &&
V_107 != V_122 )
goto V_31;
V_106 = F_40 ( V_105 -> V_123 ) ;
V_27 = - V_124 ;
if ( V_106 && V_106 < V_125 &&
! F_29 ( V_43 -> V_60 , V_126 ) )
goto V_31;
F_15 ( V_2 ) ;
V_27 = - V_28 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_19 )
goto V_127;
V_4 -> V_128 = V_4 -> V_129 = V_105 -> V_113 . V_114 ;
if ( V_107 == V_121 || V_107 == V_122 )
V_4 -> V_129 = 0 ;
if ( ( V_106 || ! V_4 -> V_130 ) &&
V_2 -> V_20 -> V_21 ( V_2 , V_106 ) ) {
V_4 -> V_129 = V_4 -> V_128 = 0 ;
V_27 = - V_131 ;
goto V_127;
}
if ( V_4 -> V_128 )
V_2 -> V_132 |= V_133 ;
if ( V_106 )
V_2 -> V_132 |= V_134 ;
V_4 -> V_23 = F_17 ( V_4 -> V_19 ) ;
V_4 -> V_135 = 0 ;
V_4 -> V_136 = 0 ;
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
if ( V_103 < sizeof( V_102 -> V_137 ) )
return - V_28 ;
if ( V_102 -> V_137 == V_112 )
return V_2 -> V_20 -> V_138 ( V_2 , V_64 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_139 ( V_2 , V_102 , V_103 ) ;
}
static long F_43 ( struct V_1 * V_2 , long V_140 , int V_141 )
{
F_44 ( V_142 ) ;
F_45 ( F_46 ( V_2 ) , & V_142 , V_143 ) ;
V_2 -> V_144 += V_141 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_145 | V_146 ) ) {
F_16 ( V_2 ) ;
V_140 = F_47 ( V_140 ) ;
F_15 ( V_2 ) ;
if ( F_48 ( V_97 ) || ! V_140 )
break;
F_45 ( F_46 ( V_2 ) , & V_142 , V_143 ) ;
}
F_49 ( F_46 ( V_2 ) , & V_142 ) ;
V_2 -> V_144 -= V_141 ;
return V_140 ;
}
int F_50 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 ;
long V_140 ;
if ( V_103 < sizeof( V_102 -> V_137 ) )
return - V_28 ;
if ( V_102 -> V_137 == V_112 ) {
V_27 = V_2 -> V_20 -> V_138 ( V_2 , V_64 ) ;
V_1 -> V_29 = V_27 ? V_147 : V_30 ;
goto V_31;
}
switch ( V_1 -> V_29 ) {
default:
V_27 = - V_28 ;
goto V_31;
case V_148 :
V_27 = - V_149 ;
goto V_31;
case V_150 :
V_27 = - V_151 ;
break;
case V_30 :
V_27 = - V_149 ;
if ( V_2 -> V_9 != V_10 )
goto V_31;
V_27 = V_2 -> V_20 -> V_139 ( V_2 , V_102 , V_103 ) ;
if ( V_27 < 0 )
goto V_31;
V_1 -> V_29 = V_150 ;
V_27 = - V_152 ;
break;
}
V_140 = F_51 ( V_2 , V_64 & V_153 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_145 | V_146 ) ) {
int V_141 = ( V_2 -> V_83 == V_154 ) &&
F_52 ( V_2 ) -> V_155 &&
F_52 ( V_2 ) -> V_155 -> V_156 ? 1 : 0 ;
if ( ! V_140 || ! F_43 ( V_2 , V_140 , V_141 ) )
goto V_31;
V_27 = F_53 ( V_140 ) ;
if ( F_48 ( V_97 ) )
goto V_31;
}
if ( V_2 -> V_9 == V_10 )
goto V_157;
V_1 -> V_29 = V_148 ;
V_27 = 0 ;
V_31:
return V_27 ;
V_157:
V_27 = V_157 ( V_2 ) ? : - V_158 ;
V_1 -> V_29 = V_30 ;
if ( V_2 -> V_20 -> V_138 ( V_2 , V_64 ) )
V_1 -> V_29 = V_147 ;
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
int F_55 ( struct V_24 * V_1 , struct V_24 * V_159 , int V_64 )
{
struct V_1 * V_160 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_161 = V_160 -> V_20 -> V_162 ( V_160 , V_64 , & V_27 ) ;
if ( ! V_161 )
goto V_163;
F_15 ( V_161 ) ;
F_56 ( V_161 ) ;
F_7 ( ! ( ( 1 << V_161 -> V_9 ) &
( V_164 | V_146 |
V_165 | V_32 ) ) ) ;
F_57 ( V_161 , V_159 ) ;
V_159 -> V_29 = V_148 ;
V_27 = 0 ;
F_16 ( V_161 ) ;
V_163:
return V_27 ;
}
int F_58 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int * V_166 , int V_167 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_59 ( struct V_104 * , sin , V_102 ) ;
sin -> V_109 = V_110 ;
if ( V_167 ) {
if ( ! V_4 -> V_136 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_32 | V_145 ) ) &&
V_167 == 1 ) )
return - V_168 ;
sin -> V_123 = V_4 -> V_136 ;
sin -> V_113 . V_114 = V_4 -> V_135 ;
} else {
T_1 V_105 = V_4 -> V_128 ;
if ( ! V_105 )
V_105 = V_4 -> V_129 ;
sin -> V_123 = V_4 -> V_23 ;
sin -> V_113 . V_114 = V_105 ;
}
memset ( sin -> V_169 , 0 , sizeof( sin -> V_169 ) ) ;
* V_166 = sizeof( * sin ) ;
return 0 ;
}
int F_60 ( struct V_24 * V_1 , struct V_170 * V_171 , T_2 V_172 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_56 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_173 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_174 ( V_2 , V_171 , V_172 ) ;
}
T_3 F_61 ( struct V_24 * V_1 , struct V_175 * V_175 , int V_176 ,
T_2 V_172 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_56 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_173 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_177 )
return V_2 -> V_20 -> V_177 ( V_2 , V_175 , V_176 , V_172 , V_64 ) ;
return F_62 ( V_1 , V_175 , V_176 , V_172 , V_64 ) ;
}
int F_63 ( struct V_24 * V_1 , struct V_170 * V_171 , T_2 V_172 ,
int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_103 = 0 ;
int V_27 ;
F_56 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_178 ( V_2 , V_171 , V_172 , V_64 & V_179 ,
V_64 & ~ V_179 , & V_103 ) ;
if ( V_27 >= 0 )
V_171 -> V_180 = V_103 ;
return V_27 ;
}
int F_64 ( struct V_24 * V_1 , int V_181 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_181 ++ ;
if ( ( V_181 & ~ V_182 ) || ! V_181 )
return - V_28 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_29 == V_150 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_145 | V_146 | V_32 ) )
V_1 -> V_29 = V_147 ;
else
V_1 -> V_29 = V_148 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_27 = - V_168 ;
default:
V_2 -> V_183 |= V_181 ;
if ( V_2 -> V_20 -> V_184 )
V_2 -> V_20 -> V_184 ( V_2 , V_181 ) ;
break;
case V_34 :
if ( ! ( V_181 & V_185 ) )
break;
case V_186 :
V_27 = V_2 -> V_20 -> V_138 ( V_2 , V_153 ) ;
V_1 -> V_29 = V_27 ? V_147 : V_30 ;
break;
}
V_2 -> V_187 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_65 ( struct V_24 * V_1 , unsigned int V_188 , unsigned long V_189 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_43 * V_43 = F_37 ( V_2 ) ;
switch ( V_188 ) {
case V_190 :
V_27 = F_66 ( V_2 , (struct V_191 V_192 * ) V_189 ) ;
break;
case V_193 :
V_27 = F_67 ( V_2 , (struct V_194 V_192 * ) V_189 ) ;
break;
case V_195 :
case V_196 :
case V_197 :
V_27 = F_68 ( V_43 , V_188 , ( void V_192 * ) V_189 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
V_27 = F_69 ( V_43 , V_188 , ( void V_192 * ) V_189 ) ;
break;
case V_201 :
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
V_27 = F_70 ( V_43 , V_188 , ( void V_192 * ) V_189 ) ;
break;
default:
if ( V_2 -> V_20 -> V_212 )
V_27 = V_2 -> V_20 -> V_212 ( V_2 , V_188 , V_189 ) ;
else
V_27 = - V_213 ;
break;
}
return V_27 ;
}
static int F_71 ( struct V_24 * V_1 , unsigned int V_188 , unsigned long V_189 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_213 ;
if ( V_2 -> V_20 -> V_214 )
V_27 = V_2 -> V_20 -> V_214 ( V_2 , V_188 , V_189 ) ;
return V_27 ;
}
void F_72 ( struct V_46 * V_215 )
{
struct V_216 * V_217 ;
struct V_46 * V_47 ;
int V_44 = V_215 -> V_44 ;
struct V_216 * V_218 ;
F_73 ( & V_219 ) ;
if ( V_215 -> type >= V_220 )
goto V_221;
V_47 = NULL ;
V_218 = & V_222 [ V_215 -> type ] ;
F_74 (lh, &inetsw[p->type]) {
V_47 = F_75 ( V_217 , struct V_46 , V_223 ) ;
if ( V_224 & V_47 -> V_64 ) {
if ( V_44 == V_47 -> V_44 )
break;
V_218 = V_217 ;
}
V_47 = NULL ;
}
if ( V_47 )
goto V_225;
F_76 ( & V_215 -> V_223 , V_218 ) ;
V_31:
F_77 ( & V_219 ) ;
return;
V_225:
F_5 ( L_5 , V_44 ) ;
goto V_31;
V_221:
F_5 ( L_6 ,
V_215 -> type ) ;
goto V_31;
}
void F_78 ( struct V_46 * V_215 )
{
if ( V_224 & V_215 -> V_64 ) {
F_5 ( L_7 ,
V_215 -> V_44 ) ;
} else {
F_73 ( & V_219 ) ;
F_79 ( & V_215 -> V_223 ) ;
F_77 ( & V_219 ) ;
F_80 () ;
}
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_226 = V_4 -> V_129 ;
T_1 V_227 = V_4 -> V_135 ;
struct V_228 * V_229 ;
struct V_230 * V_231 ;
T_1 V_232 ;
struct V_233 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_82 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_234 . V_235 )
V_227 = V_16 -> V_234 . V_236 ;
V_229 = & V_4 -> V_237 . V_238 . V_239 . V_240 ;
V_231 = F_83 ( V_229 , V_227 , 0 , F_84 ( V_2 ) ,
V_2 -> V_241 , V_2 -> V_83 ,
V_4 -> V_23 , V_4 -> V_136 , V_2 ) ;
if ( F_85 ( V_231 ) )
return F_86 ( V_231 ) ;
F_87 ( V_2 , & V_231 -> V_242 ) ;
V_232 = V_229 -> V_243 ;
if ( V_232 == V_226 )
return 0 ;
if ( V_244 > 1 ) {
F_88 ( L_8 ,
V_245 , & V_226 , & V_232 ) ;
}
V_4 -> V_129 = V_4 -> V_128 = V_232 ;
F_89 ( V_2 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_230 * V_231 = (struct V_230 * ) F_91 ( V_2 , 0 ) ;
T_1 V_227 ;
struct V_233 * V_16 ;
struct V_228 * V_229 ;
int V_27 ;
if ( V_231 )
return 0 ;
F_24 () ;
V_16 = F_92 ( V_4 -> V_16 ) ;
V_227 = V_4 -> V_135 ;
if ( V_16 && V_16 -> V_234 . V_235 )
V_227 = V_16 -> V_234 . V_236 ;
F_27 () ;
V_229 = & V_4 -> V_237 . V_238 . V_239 . V_240 ;
V_231 = F_93 ( F_37 ( V_2 ) , V_229 , V_2 , V_227 , V_4 -> V_129 ,
V_4 -> V_136 , V_4 -> V_23 ,
V_2 -> V_83 , F_84 ( V_2 ) ,
V_2 -> V_241 ) ;
if ( ! F_85 ( V_231 ) ) {
V_27 = 0 ;
F_87 ( V_2 , & V_231 -> V_242 ) ;
} else {
V_27 = F_86 ( V_231 ) ;
V_2 -> V_246 = 0 ;
if ( ! V_244 ||
V_2 -> V_9 != V_186 ||
( V_2 -> V_132 & V_133 ) ||
( V_27 = F_81 ( V_2 ) ) != 0 )
V_2 -> V_247 = - V_27 ;
}
return V_27 ;
}
static struct V_248 * F_94 ( struct V_248 * V_249 ,
T_4 V_250 )
{
struct V_248 * V_251 = F_95 ( - V_28 ) ;
const struct V_252 * V_62 ;
unsigned int V_176 = 0 ;
bool V_253 , V_254 ;
struct V_255 * V_256 ;
int V_48 ;
int V_257 ;
int V_258 ;
int V_259 ;
if ( F_26 ( F_96 ( V_249 ) -> V_260 &
~ ( V_261 |
V_262 |
V_263 |
V_264 |
V_265 |
V_266 |
V_267 |
V_268 |
V_269 |
V_270 |
V_271 |
V_272 |
0 ) ) )
goto V_31;
F_97 ( V_249 ) ;
V_257 = F_98 ( V_249 ) - F_99 ( V_249 ) ;
if ( F_26 ( ! F_100 ( V_249 , sizeof( * V_256 ) ) ) )
goto V_31;
V_256 = F_101 ( V_249 ) ;
V_258 = V_256 -> V_258 * 4 ;
if ( V_258 < sizeof( * V_256 ) )
goto V_31;
V_259 = F_40 ( V_256 -> V_259 ) ;
V_48 = V_256 -> V_44 ;
if ( F_26 ( ! F_100 ( V_249 , V_258 ) ) )
goto V_31;
F_102 ( V_249 , V_258 ) ;
V_254 = F_103 ( V_249 ) -> V_273 > 0 ;
if ( V_254 )
V_250 &= V_249 -> V_274 -> V_275 ;
F_103 ( V_249 ) -> V_273 += V_258 ;
F_104 ( V_249 ) ;
V_251 = F_95 ( - V_55 ) ;
if ( V_249 -> V_276 &&
F_96 ( V_249 ) -> V_260 & ( V_268 | V_267 ) )
V_253 = V_48 == V_277 && V_254 ;
else
V_253 = V_48 == V_277 && ! V_249 -> V_276 ;
V_62 = F_92 ( V_278 [ V_48 ] ) ;
if ( F_105 ( V_62 && V_62 -> V_279 . V_280 ) )
V_251 = V_62 -> V_279 . V_280 ( V_249 , V_250 ) ;
if ( F_106 ( V_251 ) )
goto V_31;
V_249 = V_251 ;
do {
V_256 = (struct V_255 * ) ( F_99 ( V_249 ) + V_257 ) ;
if ( V_253 ) {
V_256 -> V_259 = F_17 ( V_259 ) ;
V_256 -> V_281 = F_17 ( V_176 >> 3 ) ;
if ( V_249 -> V_282 )
V_256 -> V_281 |= F_17 ( V_283 ) ;
V_176 += V_249 -> V_284 - V_257 - V_258 ;
} else {
V_256 -> V_259 = F_17 ( V_259 ++ ) ;
}
V_256 -> V_285 = F_17 ( V_249 -> V_284 - V_257 ) ;
F_107 ( V_256 ) ;
if ( V_254 )
F_108 ( V_249 ) ;
V_249 -> V_286 = ( V_287 * ) V_256 - V_249 -> V_288 ;
} while ( ( V_249 = V_249 -> V_282 ) );
V_31:
return V_251 ;
}
static struct V_248 * * F_109 ( struct V_248 * * V_288 ,
struct V_248 * V_249 )
{
const struct V_252 * V_62 ;
struct V_248 * * V_289 = NULL ;
struct V_248 * V_215 ;
const struct V_255 * V_256 ;
unsigned int V_290 ;
unsigned int V_291 ;
unsigned int V_259 ;
int V_292 = 1 ;
int V_48 ;
V_291 = F_110 ( V_249 ) ;
V_290 = V_291 + sizeof( * V_256 ) ;
V_256 = F_111 ( V_249 , V_291 ) ;
if ( F_112 ( V_249 , V_290 ) ) {
V_256 = F_113 ( V_249 , V_290 , V_291 ) ;
if ( F_26 ( ! V_256 ) )
goto V_31;
}
V_48 = V_256 -> V_44 ;
F_24 () ;
V_62 = F_92 ( V_278 [ V_48 ] ) ;
if ( ! V_62 || ! V_62 -> V_279 . V_293 )
goto V_294;
if ( * ( V_287 * ) V_256 != 0x45 )
goto V_294;
if ( F_26 ( F_114 ( ( V_287 * ) V_256 , 5 ) ) )
goto V_294;
V_259 = F_115 ( * ( T_1 * ) & V_256 -> V_259 ) ;
V_292 = ( V_295 ) ( ( F_115 ( * ( T_1 * ) V_256 ) ^ F_116 ( V_249 ) ) | ( V_259 & ~ V_296 ) ) ;
V_259 >>= 16 ;
for ( V_215 = * V_288 ; V_215 ; V_215 = V_215 -> V_282 ) {
struct V_255 * V_297 ;
if ( ! F_117 ( V_215 ) -> V_298 )
continue;
V_297 = (struct V_255 * ) ( V_215 -> V_156 + V_291 ) ;
if ( ( V_256 -> V_44 ^ V_297 -> V_44 ) |
( ( V_299 V_300 ) V_256 -> V_243 ^ ( V_299 V_300 ) V_297 -> V_243 ) |
( ( V_299 V_300 ) V_256 -> V_227 ^ ( V_299 V_300 ) V_297 -> V_227 ) ) {
F_117 ( V_215 ) -> V_298 = 0 ;
continue;
}
F_117 ( V_215 ) -> V_292 |=
( V_256 -> V_301 ^ V_297 -> V_301 ) |
( V_256 -> V_302 ^ V_297 -> V_302 ) |
( ( V_256 -> V_281 ^ V_297 -> V_281 ) & F_17 ( V_296 ) ) ;
F_117 ( V_215 ) -> V_303 =
( ( V_295 ) ( F_40 ( V_297 -> V_259 ) + F_117 ( V_215 ) -> V_304 ) ^ V_259 ) ;
F_117 ( V_215 ) -> V_292 |= V_292 ;
}
F_117 ( V_249 ) -> V_292 |= V_292 ;
F_118 ( V_249 , V_291 ) ;
F_119 ( V_249 , sizeof( * V_256 ) ) ;
F_120 ( V_249 , F_110 ( V_249 ) ) ;
V_289 = V_62 -> V_279 . V_293 ( V_288 , V_249 ) ;
V_294:
F_27 () ;
V_31:
F_117 ( V_249 ) -> V_292 |= V_292 ;
return V_289 ;
}
int F_121 ( struct V_1 * V_2 , struct V_170 * V_171 , int V_284 , int * V_103 )
{
if ( V_2 -> V_305 == V_110 )
return F_122 ( V_2 , V_171 , V_284 , V_103 ) ;
#if F_123 ( V_306 )
if ( V_2 -> V_305 == V_307 )
return V_308 . V_309 ( V_2 , V_171 , V_284 , V_103 ) ;
#endif
return - V_28 ;
}
static int F_124 ( struct V_248 * V_249 , int V_257 )
{
T_5 V_310 = F_17 ( V_249 -> V_284 - V_257 ) ;
struct V_255 * V_256 = (struct V_255 * ) ( V_249 -> V_156 + V_257 ) ;
const struct V_252 * V_62 ;
int V_48 = V_256 -> V_44 ;
int V_27 = - V_311 ;
if ( V_249 -> V_276 )
F_125 ( V_249 , V_257 ) ;
F_126 ( & V_256 -> V_312 , V_256 -> V_285 , V_310 ) ;
V_256 -> V_285 = V_310 ;
F_24 () ;
V_62 = F_92 ( V_278 [ V_48 ] ) ;
if ( F_7 ( ! V_62 || ! V_62 -> V_279 . V_313 ) )
goto V_294;
V_27 = V_62 -> V_279 . V_313 ( V_249 , V_257 + sizeof( * V_256 ) ) ;
V_294:
F_27 () ;
return V_27 ;
}
int F_127 ( struct V_1 * * V_2 , unsigned short V_314 ,
unsigned short type , unsigned char V_44 ,
struct V_43 * V_43 )
{
struct V_24 * V_1 ;
int V_315 = F_128 ( V_43 , V_314 , type , V_44 , & V_1 ) ;
if ( V_315 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_316 = V_317 ;
( * V_2 ) -> V_20 -> V_318 ( * V_2 ) ;
}
return V_315 ;
}
unsigned long F_129 ( void T_6 * V_319 , int V_320 )
{
unsigned long V_321 = 0 ;
int V_322 ;
F_130 (i)
V_321 += * ( ( ( unsigned long * ) F_131 ( V_319 , V_322 ) ) + V_320 ) ;
return V_321 ;
}
T_7 F_132 ( void T_6 * V_319 , int V_320 , T_2 V_323 )
{
T_7 V_321 = 0 ;
int V_324 ;
F_130 (cpu) {
void * V_325 ;
struct V_326 * V_327 ;
T_7 V_328 ;
unsigned int V_329 ;
V_325 = F_131 ( V_319 , V_324 ) ;
V_327 = (struct V_326 * ) ( V_325 + V_323 ) ;
do {
V_329 = F_133 ( V_327 ) ;
V_328 = * ( ( ( T_7 * ) V_325 ) + V_320 ) ;
} while ( F_134 ( V_327 , V_329 ) );
V_321 += V_328 ;
}
return V_321 ;
}
static T_8 int F_135 ( struct V_43 * V_43 )
{
int V_322 ;
V_43 -> V_319 . V_330 = F_136 ( struct V_331 ) ;
if ( ! V_43 -> V_319 . V_330 )
goto V_332;
V_43 -> V_319 . V_333 = F_136 ( struct V_334 ) ;
if ( ! V_43 -> V_319 . V_333 )
goto V_335;
F_130 (i) {
struct V_334 * V_336 ;
V_336 = F_131 ( V_43 -> V_319 . V_333 , V_322 ) ;
F_137 ( & V_336 -> V_327 ) ;
}
V_43 -> V_319 . V_337 = F_136 ( struct V_338 ) ;
if ( ! V_43 -> V_319 . V_337 )
goto V_339;
V_43 -> V_319 . V_340 = F_136 ( struct V_341 ) ;
if ( ! V_43 -> V_319 . V_340 )
goto V_342;
V_43 -> V_319 . V_343 = F_136 ( struct V_341 ) ;
if ( ! V_43 -> V_319 . V_343 )
goto V_344;
V_43 -> V_319 . V_345 = F_136 ( struct V_346 ) ;
if ( ! V_43 -> V_319 . V_345 )
goto V_347;
V_43 -> V_319 . V_348 = F_138 ( sizeof( struct V_349 ) ,
V_67 ) ;
if ( ! V_43 -> V_319 . V_348 )
goto V_350;
F_139 ( V_43 ) ;
return 0 ;
V_350:
F_140 ( V_43 -> V_319 . V_345 ) ;
V_347:
F_140 ( V_43 -> V_319 . V_343 ) ;
V_344:
F_140 ( V_43 -> V_319 . V_340 ) ;
V_342:
F_140 ( V_43 -> V_319 . V_337 ) ;
V_339:
F_140 ( V_43 -> V_319 . V_333 ) ;
V_335:
F_140 ( V_43 -> V_319 . V_330 ) ;
V_332:
return - V_351 ;
}
static T_9 void F_141 ( struct V_43 * V_43 )
{
F_9 ( V_43 -> V_319 . V_348 ) ;
F_140 ( V_43 -> V_319 . V_345 ) ;
F_140 ( V_43 -> V_319 . V_343 ) ;
F_140 ( V_43 -> V_319 . V_340 ) ;
F_140 ( V_43 -> V_319 . V_337 ) ;
F_140 ( V_43 -> V_319 . V_333 ) ;
F_140 ( V_43 -> V_319 . V_330 ) ;
}
static int T_10 F_142 ( void )
{
return F_143 ( & V_352 ) ;
}
static T_8 int F_144 ( struct V_43 * V_43 )
{
F_145 ( & V_43 -> V_76 . V_353 . V_354 ) ;
V_43 -> V_76 . V_353 . V_355 [ 0 ] = 32768 ;
V_43 -> V_76 . V_353 . V_355 [ 1 ] = 60999 ;
F_145 ( & V_43 -> V_76 . V_356 . V_354 ) ;
V_43 -> V_76 . V_356 . V_355 [ 0 ] = F_146 ( & V_357 , 1 ) ;
V_43 -> V_76 . V_356 . V_355 [ 1 ] = F_146 ( & V_357 , 0 ) ;
return 0 ;
}
static T_9 void F_147 ( struct V_43 * V_43 )
{
}
static int T_10 F_148 ( void )
{
return F_143 ( & V_358 ) ;
}
static int T_10 F_149 ( void )
{
if ( F_150 () < 0 )
F_151 ( L_9 , V_245 ) ;
if ( F_152 () < 0 )
F_151 ( L_10 , V_245 ) ;
F_153 ( & V_359 ) ;
F_154 ( & V_360 , V_361 ) ;
return 0 ;
}
static int T_10 F_155 ( void )
{
struct V_46 * V_362 ;
struct V_216 * V_363 ;
int V_315 = - V_28 ;
F_156 ( sizeof( struct V_364 ) ) ;
V_315 = F_157 ( & V_365 , 1 ) ;
if ( V_315 )
goto V_31;
V_315 = F_157 ( & V_366 , 1 ) ;
if ( V_315 )
goto V_367;
V_315 = F_157 ( & V_368 , 1 ) ;
if ( V_315 )
goto V_369;
V_315 = F_157 ( & V_370 , 1 ) ;
if ( V_315 )
goto V_371;
( void ) F_158 ( & V_372 ) ;
#ifdef F_159
F_160 () ;
#endif
if ( F_161 ( & V_373 , V_374 ) < 0 )
F_151 ( L_11 , V_245 ) ;
if ( F_161 ( & V_375 , V_277 ) < 0 )
F_151 ( L_12 , V_245 ) ;
if ( F_161 ( & V_376 , V_154 ) < 0 )
F_151 ( L_13 , V_245 ) ;
#ifdef F_162
if ( F_161 ( & V_377 , V_378 ) < 0 )
F_151 ( L_14 , V_245 ) ;
#endif
for ( V_363 = & V_222 [ 0 ] ; V_363 < & V_222 [ V_220 ] ; ++ V_363 )
F_163 ( V_363 ) ;
for ( V_362 = V_379 ; V_362 < & V_379 [ V_380 ] ; ++ V_362 )
F_72 ( V_362 ) ;
F_164 () ;
F_165 () ;
F_166 () ;
F_167 () ;
F_168 () ;
F_169 () ;
F_170 () ;
if ( F_171 () < 0 )
F_172 ( L_15 ) ;
#if F_173 ( V_381 )
if ( F_174 () )
F_151 ( L_16 , V_245 ) ;
#endif
if ( F_148 () )
F_151 ( L_17 , V_245 ) ;
if ( F_142 () )
F_151 ( L_18 , V_245 ) ;
F_175 () ;
F_176 () ;
F_177 ( & V_382 ) ;
V_315 = 0 ;
V_31:
return V_315 ;
V_371:
F_178 ( & V_368 ) ;
V_369:
F_178 ( & V_366 ) ;
V_367:
F_178 ( & V_365 ) ;
goto V_31;
}
static int T_10 F_175 ( void )
{
int V_315 = 0 ;
if ( F_179 () )
goto V_383;
if ( F_180 () )
goto V_384;
if ( F_181 () )
goto V_385;
if ( F_182 () )
goto V_386;
if ( F_183 () )
goto V_387;
V_31:
return V_315 ;
V_387:
F_184 () ;
V_386:
F_185 () ;
V_385:
F_186 () ;
V_384:
F_187 () ;
V_383:
V_315 = - V_351 ;
goto V_31;
}
static int T_10 F_175 ( void )
{
return 0 ;
}
