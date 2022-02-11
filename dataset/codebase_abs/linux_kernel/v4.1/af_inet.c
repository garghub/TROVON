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
F_7 ( ! V_49 -> V_65 ) ;
V_27 = - V_66 ;
V_2 = F_29 ( V_43 , V_56 , V_67 , V_49 ) ;
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
V_95 = 0 ;
if ( F_6 ( V_2 , V_96 ) &&
! ( V_97 -> V_64 & V_98 ) )
V_95 = V_2 -> V_99 ;
V_1 -> V_2 = NULL ;
V_2 -> V_20 -> V_100 ( V_2 , V_95 ) ;
}
return 0 ;
}
int F_35 ( struct V_24 * V_1 , struct V_101 * V_102 , int V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_43 * V_43 = F_36 ( V_2 ) ;
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
V_105 -> V_113 . V_114 != F_37 ( V_115 ) )
goto V_31;
}
V_107 = F_38 ( V_43 , V_105 -> V_113 . V_114 ) ;
V_27 = - V_116 ;
if ( ! V_43 -> V_76 . V_117 &&
! ( V_4 -> V_118 || V_4 -> V_119 ) &&
V_105 -> V_113 . V_114 != F_37 ( V_115 ) &&
V_107 != V_120 &&
V_107 != V_121 &&
V_107 != V_122 )
goto V_31;
V_106 = F_39 ( V_105 -> V_123 ) ;
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
F_40 ( V_2 ) ;
V_27 = 0 ;
V_127:
F_16 ( V_2 ) ;
V_31:
return V_27 ;
}
int F_41 ( struct V_24 * V_1 , struct V_101 * V_102 ,
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
static long F_42 ( struct V_1 * V_2 , long V_139 , int V_140 )
{
F_43 ( V_141 ) ;
F_44 ( F_45 ( V_2 ) , & V_141 , V_142 ) ;
V_2 -> V_143 += V_140 ;
while ( ( 1 << V_2 -> V_9 ) & ( V_144 | V_145 ) ) {
F_16 ( V_2 ) ;
V_139 = F_46 ( V_139 ) ;
F_15 ( V_2 ) ;
if ( F_47 ( V_97 ) || ! V_139 )
break;
F_44 ( F_45 ( V_2 ) , & V_141 , V_142 ) ;
}
F_48 ( F_45 ( V_2 ) , & V_141 ) ;
V_2 -> V_143 -= V_140 ;
return V_139 ;
}
int F_49 ( struct V_24 * V_1 , struct V_101 * V_102 ,
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
V_139 = F_50 ( V_2 , V_64 & V_152 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_144 | V_145 ) ) {
int V_140 = ( V_2 -> V_83 == V_153 ) &&
F_51 ( V_2 ) -> V_154 &&
F_51 ( V_2 ) -> V_154 -> V_155 ? 1 : 0 ;
if ( ! V_139 || ! F_42 ( V_2 , V_139 , V_140 ) )
goto V_31;
V_27 = F_52 ( V_139 ) ;
if ( F_47 ( V_97 ) )
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
int F_53 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int V_103 , int V_64 )
{
int V_27 ;
F_15 ( V_1 -> V_2 ) ;
V_27 = F_49 ( V_1 , V_102 , V_103 , V_64 ) ;
F_16 ( V_1 -> V_2 ) ;
return V_27 ;
}
int F_54 ( struct V_24 * V_1 , struct V_24 * V_158 , int V_64 )
{
struct V_1 * V_159 = V_1 -> V_2 ;
int V_27 = - V_28 ;
struct V_1 * V_160 = V_159 -> V_20 -> V_161 ( V_159 , V_64 , & V_27 ) ;
if ( ! V_160 )
goto V_162;
F_15 ( V_160 ) ;
F_55 ( V_160 ) ;
F_7 ( ! ( ( 1 << V_160 -> V_9 ) &
( V_163 | V_145 |
V_164 | V_32 ) ) ) ;
F_56 ( V_160 , V_158 ) ;
V_158 -> V_29 = V_147 ;
V_27 = 0 ;
F_16 ( V_160 ) ;
V_162:
return V_27 ;
}
int F_57 ( struct V_24 * V_1 , struct V_101 * V_102 ,
int * V_165 , int V_166 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_58 ( struct V_104 * , sin , V_102 ) ;
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
int F_59 ( struct V_24 * V_1 , struct V_169 * V_170 , T_2 V_171 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_55 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_172 &&
F_14 ( V_2 ) )
return - V_22 ;
return V_2 -> V_20 -> V_173 ( V_2 , V_170 , V_171 ) ;
}
T_3 F_60 ( struct V_24 * V_1 , struct V_174 * V_174 , int V_175 ,
T_2 V_171 , int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_55 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_19 && ! V_2 -> V_20 -> V_172 &&
F_14 ( V_2 ) )
return - V_22 ;
if ( V_2 -> V_20 -> V_176 )
return V_2 -> V_20 -> V_176 ( V_2 , V_174 , V_175 , V_171 , V_64 ) ;
return F_61 ( V_1 , V_174 , V_175 , V_171 , V_64 ) ;
}
int F_62 ( struct V_24 * V_1 , struct V_169 * V_170 , T_2 V_171 ,
int V_64 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_103 = 0 ;
int V_27 ;
F_55 ( V_2 ) ;
V_27 = V_2 -> V_20 -> V_177 ( V_2 , V_170 , V_171 , V_64 & V_178 ,
V_64 & ~ V_178 , & V_103 ) ;
if ( V_27 >= 0 )
V_170 -> V_179 = V_103 ;
return V_27 ;
}
int F_63 ( struct V_24 * V_1 , int V_180 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
V_180 ++ ;
if ( ( V_180 & ~ V_181 ) || ! V_180 )
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
V_2 -> V_182 |= V_180 ;
if ( V_2 -> V_20 -> V_183 )
V_2 -> V_20 -> V_183 ( V_2 , V_180 ) ;
break;
case V_34 :
if ( ! ( V_180 & V_184 ) )
break;
case V_185 :
V_27 = V_2 -> V_20 -> V_137 ( V_2 , V_152 ) ;
V_1 -> V_29 = V_27 ? V_146 : V_30 ;
break;
}
V_2 -> V_186 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_27 ;
}
int F_64 ( struct V_24 * V_1 , unsigned int V_187 , unsigned long V_188 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = 0 ;
struct V_43 * V_43 = F_36 ( V_2 ) ;
switch ( V_187 ) {
case V_189 :
V_27 = F_65 ( V_2 , (struct V_190 V_191 * ) V_188 ) ;
break;
case V_192 :
V_27 = F_66 ( V_2 , (struct V_193 V_191 * ) V_188 ) ;
break;
case V_194 :
case V_195 :
case V_196 :
V_27 = F_67 ( V_43 , V_187 , ( void V_191 * ) V_188 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
V_27 = F_68 ( V_43 , V_187 , ( void V_191 * ) V_188 ) ;
break;
case V_200 :
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
V_27 = F_69 ( V_43 , V_187 , ( void V_191 * ) V_188 ) ;
break;
default:
if ( V_2 -> V_20 -> V_211 )
V_27 = V_2 -> V_20 -> V_211 ( V_2 , V_187 , V_188 ) ;
else
V_27 = - V_212 ;
break;
}
return V_27 ;
}
static int F_70 ( struct V_24 * V_1 , unsigned int V_187 , unsigned long V_188 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_27 = - V_212 ;
if ( V_2 -> V_20 -> V_213 )
V_27 = V_2 -> V_20 -> V_213 ( V_2 , V_187 , V_188 ) ;
return V_27 ;
}
void F_71 ( struct V_46 * V_214 )
{
struct V_215 * V_216 ;
struct V_46 * V_47 ;
int V_44 = V_214 -> V_44 ;
struct V_215 * V_217 ;
F_72 ( & V_218 ) ;
if ( V_214 -> type >= V_219 )
goto V_220;
V_47 = NULL ;
V_217 = & V_221 [ V_214 -> type ] ;
F_73 (lh, &inetsw[p->type]) {
V_47 = F_74 ( V_216 , struct V_46 , V_222 ) ;
if ( V_223 & V_47 -> V_64 ) {
if ( V_44 == V_47 -> V_44 )
break;
V_217 = V_216 ;
}
V_47 = NULL ;
}
if ( V_47 )
goto V_224;
F_75 ( & V_214 -> V_222 , V_217 ) ;
V_31:
F_76 ( & V_218 ) ;
return;
V_224:
F_5 ( L_5 , V_44 ) ;
goto V_31;
V_220:
F_5 ( L_6 ,
V_214 -> type ) ;
goto V_31;
}
void F_77 ( struct V_46 * V_214 )
{
if ( V_223 & V_214 -> V_64 ) {
F_5 ( L_7 ,
V_214 -> V_44 ) ;
} else {
F_72 ( & V_218 ) ;
F_78 ( & V_214 -> V_222 ) ;
F_76 ( & V_218 ) ;
F_79 () ;
}
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_225 = V_4 -> V_129 ;
T_1 V_226 = V_4 -> V_134 ;
struct V_227 * V_228 ;
struct V_229 * V_230 ;
T_1 V_231 ;
struct V_232 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_81 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_233 . V_234 )
V_226 = V_16 -> V_233 . V_235 ;
V_228 = & V_4 -> V_236 . V_237 . V_238 . V_239 ;
V_230 = F_82 ( V_228 , V_226 , 0 , F_83 ( V_2 ) ,
V_2 -> V_240 , V_2 -> V_83 ,
V_4 -> V_23 , V_4 -> V_135 , V_2 ) ;
if ( F_84 ( V_230 ) )
return F_85 ( V_230 ) ;
F_86 ( V_2 , & V_230 -> V_241 ) ;
V_231 = V_228 -> V_242 ;
if ( V_231 == V_225 )
return 0 ;
if ( V_243 > 1 ) {
F_87 ( L_8 ,
V_244 , & V_225 , & V_231 ) ;
}
V_4 -> V_129 = V_4 -> V_128 = V_231 ;
F_88 ( V_2 ) ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_229 * V_230 = (struct V_229 * ) F_90 ( V_2 , 0 ) ;
T_1 V_226 ;
struct V_232 * V_16 ;
struct V_227 * V_228 ;
int V_27 ;
if ( V_230 )
return 0 ;
F_23 () ;
V_16 = F_91 ( V_4 -> V_16 ) ;
V_226 = V_4 -> V_134 ;
if ( V_16 && V_16 -> V_233 . V_234 )
V_226 = V_16 -> V_233 . V_235 ;
F_26 () ;
V_228 = & V_4 -> V_236 . V_237 . V_238 . V_239 ;
V_230 = F_92 ( F_36 ( V_2 ) , V_228 , V_2 , V_226 , V_4 -> V_129 ,
V_4 -> V_135 , V_4 -> V_23 ,
V_2 -> V_83 , F_83 ( V_2 ) ,
V_2 -> V_240 ) ;
if ( ! F_84 ( V_230 ) ) {
V_27 = 0 ;
F_86 ( V_2 , & V_230 -> V_241 ) ;
} else {
V_27 = F_85 ( V_230 ) ;
V_2 -> V_245 = 0 ;
if ( ! V_243 ||
V_2 -> V_9 != V_185 ||
( V_2 -> V_131 & V_132 ) ||
( V_27 = F_80 ( V_2 ) ) != 0 )
V_2 -> V_246 = - V_27 ;
}
return V_27 ;
}
static struct V_247 * F_93 ( struct V_247 * V_248 ,
T_4 V_249 )
{
struct V_247 * V_250 = F_94 ( - V_28 ) ;
const struct V_251 * V_62 ;
unsigned int V_175 = 0 ;
bool V_252 , V_253 ;
struct V_254 * V_255 ;
int V_48 ;
int V_256 ;
int V_257 ;
int V_258 ;
if ( F_25 ( F_95 ( V_248 ) -> V_259 &
~ ( V_260 |
V_261 |
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
0 ) ) )
goto V_31;
F_96 ( V_248 ) ;
V_256 = F_97 ( V_248 ) - F_98 ( V_248 ) ;
if ( F_25 ( ! F_99 ( V_248 , sizeof( * V_255 ) ) ) )
goto V_31;
V_255 = F_100 ( V_248 ) ;
V_257 = V_255 -> V_257 * 4 ;
if ( V_257 < sizeof( * V_255 ) )
goto V_31;
V_258 = F_39 ( V_255 -> V_258 ) ;
V_48 = V_255 -> V_44 ;
if ( F_25 ( ! F_99 ( V_248 , V_257 ) ) )
goto V_31;
F_101 ( V_248 , V_257 ) ;
V_253 = F_102 ( V_248 ) -> V_272 > 0 ;
if ( V_253 )
V_249 &= V_248 -> V_273 -> V_274 ;
F_102 ( V_248 ) -> V_272 += V_257 ;
F_103 ( V_248 ) ;
V_250 = F_94 ( - V_55 ) ;
if ( V_248 -> V_275 &&
F_95 ( V_248 ) -> V_259 & ( V_267 | V_266 ) )
V_252 = V_48 == V_276 && V_253 ;
else
V_252 = V_48 == V_276 && ! V_248 -> V_275 ;
V_62 = F_91 ( V_277 [ V_48 ] ) ;
if ( F_104 ( V_62 && V_62 -> V_278 . V_279 ) )
V_250 = V_62 -> V_278 . V_279 ( V_248 , V_249 ) ;
if ( F_105 ( V_250 ) )
goto V_31;
V_248 = V_250 ;
do {
V_255 = (struct V_254 * ) ( F_98 ( V_248 ) + V_256 ) ;
if ( V_252 ) {
V_255 -> V_258 = F_17 ( V_258 ) ;
V_255 -> V_280 = F_17 ( V_175 >> 3 ) ;
if ( V_248 -> V_281 )
V_255 -> V_280 |= F_17 ( V_282 ) ;
V_175 += V_248 -> V_283 - V_256 - V_257 ;
} else {
V_255 -> V_258 = F_17 ( V_258 ++ ) ;
}
V_255 -> V_284 = F_17 ( V_248 -> V_283 - V_256 ) ;
F_106 ( V_255 ) ;
if ( V_253 )
F_107 ( V_248 ) ;
V_248 -> V_285 = ( V_286 * ) V_255 - V_248 -> V_287 ;
} while ( ( V_248 = V_248 -> V_281 ) );
V_31:
return V_250 ;
}
static struct V_247 * * F_108 ( struct V_247 * * V_287 ,
struct V_247 * V_248 )
{
const struct V_251 * V_62 ;
struct V_247 * * V_288 = NULL ;
struct V_247 * V_214 ;
const struct V_254 * V_255 ;
unsigned int V_289 ;
unsigned int V_290 ;
unsigned int V_258 ;
int V_291 = 1 ;
int V_48 ;
V_290 = F_109 ( V_248 ) ;
V_289 = V_290 + sizeof( * V_255 ) ;
V_255 = F_110 ( V_248 , V_290 ) ;
if ( F_111 ( V_248 , V_289 ) ) {
V_255 = F_112 ( V_248 , V_289 , V_290 ) ;
if ( F_25 ( ! V_255 ) )
goto V_31;
}
V_48 = V_255 -> V_44 ;
F_23 () ;
V_62 = F_91 ( V_277 [ V_48 ] ) ;
if ( ! V_62 || ! V_62 -> V_278 . V_292 )
goto V_293;
if ( * ( V_286 * ) V_255 != 0x45 )
goto V_293;
if ( F_25 ( F_113 ( ( V_286 * ) V_255 , 5 ) ) )
goto V_293;
V_258 = F_114 ( * ( T_1 * ) & V_255 -> V_258 ) ;
V_291 = ( V_294 ) ( ( F_114 ( * ( T_1 * ) V_255 ) ^ F_115 ( V_248 ) ) | ( V_258 & ~ V_295 ) ) ;
V_258 >>= 16 ;
for ( V_214 = * V_287 ; V_214 ; V_214 = V_214 -> V_281 ) {
struct V_254 * V_296 ;
if ( ! F_116 ( V_214 ) -> V_297 )
continue;
V_296 = (struct V_254 * ) ( V_214 -> V_155 + V_290 ) ;
if ( ( V_255 -> V_44 ^ V_296 -> V_44 ) |
( ( V_298 V_299 ) V_255 -> V_242 ^ ( V_298 V_299 ) V_296 -> V_242 ) |
( ( V_298 V_299 ) V_255 -> V_226 ^ ( V_298 V_299 ) V_296 -> V_226 ) ) {
F_116 ( V_214 ) -> V_297 = 0 ;
continue;
}
F_116 ( V_214 ) -> V_291 |=
( V_255 -> V_300 ^ V_296 -> V_300 ) |
( V_255 -> V_301 ^ V_296 -> V_301 ) |
( ( V_255 -> V_280 ^ V_296 -> V_280 ) & F_17 ( V_295 ) ) ;
F_116 ( V_214 ) -> V_302 =
( ( V_294 ) ( F_39 ( V_296 -> V_258 ) + F_116 ( V_214 ) -> V_303 ) ^ V_258 ) ;
F_116 ( V_214 ) -> V_291 |= V_291 ;
}
F_116 ( V_248 ) -> V_291 |= V_291 ;
F_117 ( V_248 , V_290 ) ;
F_118 ( V_248 , sizeof( * V_255 ) ) ;
F_119 ( V_248 , F_109 ( V_248 ) ) ;
V_288 = V_62 -> V_278 . V_292 ( V_287 , V_248 ) ;
V_293:
F_26 () ;
V_31:
F_116 ( V_248 ) -> V_291 |= V_291 ;
return V_288 ;
}
int F_120 ( struct V_1 * V_2 , struct V_169 * V_170 , int V_283 , int * V_103 )
{
if ( V_2 -> V_304 == V_110 )
return F_121 ( V_2 , V_170 , V_283 , V_103 ) ;
#if F_122 ( V_305 )
if ( V_2 -> V_304 == V_306 )
return V_307 . V_308 ( V_2 , V_170 , V_283 , V_103 ) ;
#endif
return - V_28 ;
}
static int F_123 ( struct V_247 * V_248 , int V_256 )
{
T_5 V_309 = F_17 ( V_248 -> V_283 - V_256 ) ;
struct V_254 * V_255 = (struct V_254 * ) ( V_248 -> V_155 + V_256 ) ;
const struct V_251 * V_62 ;
int V_48 = V_255 -> V_44 ;
int V_27 = - V_310 ;
if ( V_248 -> V_275 )
F_124 ( V_248 , V_256 ) ;
F_125 ( & V_255 -> V_311 , V_255 -> V_284 , V_309 ) ;
V_255 -> V_284 = V_309 ;
F_23 () ;
V_62 = F_91 ( V_277 [ V_48 ] ) ;
if ( F_7 ( ! V_62 || ! V_62 -> V_278 . V_312 ) )
goto V_293;
V_27 = V_62 -> V_278 . V_312 ( V_248 , V_256 + sizeof( * V_255 ) ) ;
V_293:
F_26 () ;
return V_27 ;
}
int F_126 ( struct V_1 * * V_2 , unsigned short V_313 ,
unsigned short type , unsigned char V_44 ,
struct V_43 * V_43 )
{
struct V_24 * V_1 ;
int V_314 = F_127 ( V_313 , type , V_44 , & V_1 ) ;
if ( V_314 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_315 = V_316 ;
( * V_2 ) -> V_20 -> V_317 ( * V_2 ) ;
F_128 ( * V_2 , V_43 ) ;
}
return V_314 ;
}
unsigned long F_129 ( void T_6 * V_318 , int V_319 )
{
unsigned long V_320 = 0 ;
int V_321 ;
F_130 (i)
V_320 += * ( ( ( unsigned long * ) F_131 ( V_318 , V_321 ) ) + V_319 ) ;
return V_320 ;
}
T_7 F_132 ( void T_6 * V_318 , int V_319 , T_2 V_322 )
{
T_7 V_320 = 0 ;
int V_323 ;
F_130 (cpu) {
void * V_324 ;
struct V_325 * V_326 ;
T_7 V_327 ;
unsigned int V_328 ;
V_324 = F_131 ( V_318 , V_323 ) ;
V_326 = (struct V_325 * ) ( V_324 + V_322 ) ;
do {
V_328 = F_133 ( V_326 ) ;
V_327 = * ( ( ( T_7 * ) V_324 ) + V_319 ) ;
} while ( F_134 ( V_326 , V_328 ) );
V_320 += V_327 ;
}
return V_320 ;
}
static T_8 int F_135 ( struct V_43 * V_43 )
{
int V_321 ;
V_43 -> V_318 . V_329 = F_136 ( struct V_330 ) ;
if ( ! V_43 -> V_318 . V_329 )
goto V_331;
V_43 -> V_318 . V_332 = F_136 ( struct V_333 ) ;
if ( ! V_43 -> V_318 . V_332 )
goto V_334;
F_130 (i) {
struct V_333 * V_335 ;
V_335 = F_131 ( V_43 -> V_318 . V_332 , V_321 ) ;
F_137 ( & V_335 -> V_326 ) ;
}
V_43 -> V_318 . V_336 = F_136 ( struct V_337 ) ;
if ( ! V_43 -> V_318 . V_336 )
goto V_338;
V_43 -> V_318 . V_339 = F_136 ( struct V_340 ) ;
if ( ! V_43 -> V_318 . V_339 )
goto V_341;
V_43 -> V_318 . V_342 = F_136 ( struct V_340 ) ;
if ( ! V_43 -> V_318 . V_342 )
goto V_343;
V_43 -> V_318 . V_344 = F_136 ( struct V_345 ) ;
if ( ! V_43 -> V_318 . V_344 )
goto V_346;
V_43 -> V_318 . V_347 = F_138 ( sizeof( struct V_348 ) ,
V_67 ) ;
if ( ! V_43 -> V_318 . V_347 )
goto V_349;
F_139 ( V_43 ) ;
return 0 ;
V_349:
F_140 ( V_43 -> V_318 . V_344 ) ;
V_346:
F_140 ( V_43 -> V_318 . V_342 ) ;
V_343:
F_140 ( V_43 -> V_318 . V_339 ) ;
V_341:
F_140 ( V_43 -> V_318 . V_336 ) ;
V_338:
F_140 ( V_43 -> V_318 . V_332 ) ;
V_334:
F_140 ( V_43 -> V_318 . V_329 ) ;
V_331:
return - V_350 ;
}
static T_9 void F_141 ( struct V_43 * V_43 )
{
F_9 ( V_43 -> V_318 . V_347 ) ;
F_140 ( V_43 -> V_318 . V_344 ) ;
F_140 ( V_43 -> V_318 . V_342 ) ;
F_140 ( V_43 -> V_318 . V_339 ) ;
F_140 ( V_43 -> V_318 . V_336 ) ;
F_140 ( V_43 -> V_318 . V_332 ) ;
F_140 ( V_43 -> V_318 . V_329 ) ;
}
static int T_10 F_142 ( void )
{
return F_143 ( & V_351 ) ;
}
static T_8 int F_144 ( struct V_43 * V_43 )
{
F_145 ( & V_43 -> V_76 . V_352 . V_353 ) ;
V_43 -> V_76 . V_352 . V_354 [ 0 ] = 32768 ;
V_43 -> V_76 . V_352 . V_354 [ 1 ] = 61000 ;
F_145 ( & V_43 -> V_76 . V_355 . V_353 ) ;
V_43 -> V_76 . V_355 . V_354 [ 0 ] = F_146 ( & V_356 , 1 ) ;
V_43 -> V_76 . V_355 . V_354 [ 1 ] = F_146 ( & V_356 , 0 ) ;
return 0 ;
}
static T_9 void F_147 ( struct V_43 * V_43 )
{
}
static int T_10 F_148 ( void )
{
return F_143 ( & V_357 ) ;
}
static int T_10 F_149 ( void )
{
if ( F_150 () < 0 )
F_151 ( L_9 , V_244 ) ;
if ( F_152 () < 0 )
F_151 ( L_10 , V_244 ) ;
F_153 ( & V_358 ) ;
F_154 ( & V_359 , V_360 ) ;
return 0 ;
}
static int T_10 F_155 ( void )
{
struct V_46 * V_361 ;
struct V_215 * V_362 ;
int V_314 = - V_28 ;
F_156 ( sizeof( struct V_363 ) ) ;
V_314 = F_157 ( & V_364 , 1 ) ;
if ( V_314 )
goto V_31;
V_314 = F_157 ( & V_365 , 1 ) ;
if ( V_314 )
goto V_366;
V_314 = F_157 ( & V_367 , 1 ) ;
if ( V_314 )
goto V_368;
V_314 = F_157 ( & V_369 , 1 ) ;
if ( V_314 )
goto V_370;
( void ) F_158 ( & V_371 ) ;
#ifdef F_159
F_160 () ;
#endif
if ( F_161 ( & V_372 , V_373 ) < 0 )
F_151 ( L_11 , V_244 ) ;
if ( F_161 ( & V_374 , V_276 ) < 0 )
F_151 ( L_12 , V_244 ) ;
if ( F_161 ( & V_375 , V_153 ) < 0 )
F_151 ( L_13 , V_244 ) ;
#ifdef F_162
if ( F_161 ( & V_376 , V_377 ) < 0 )
F_151 ( L_14 , V_244 ) ;
#endif
for ( V_362 = & V_221 [ 0 ] ; V_362 < & V_221 [ V_219 ] ; ++ V_362 )
F_163 ( V_362 ) ;
for ( V_361 = V_378 ; V_361 < & V_378 [ V_379 ] ; ++ V_361 )
F_71 ( V_361 ) ;
F_164 () ;
F_165 () ;
F_166 () ;
F_167 () ;
F_168 () ;
F_169 () ;
F_170 () ;
if ( F_171 () < 0 )
F_172 ( L_15 ) ;
#if F_173 ( V_380 )
if ( F_174 () )
F_151 ( L_16 , V_244 ) ;
#endif
if ( F_148 () )
F_151 ( L_17 , V_244 ) ;
if ( F_142 () )
F_151 ( L_18 , V_244 ) ;
F_175 () ;
F_176 () ;
F_177 ( & V_381 ) ;
V_314 = 0 ;
V_31:
return V_314 ;
V_370:
F_178 ( & V_367 ) ;
V_368:
F_178 ( & V_365 ) ;
V_366:
F_178 ( & V_364 ) ;
goto V_31;
}
static int T_10 F_175 ( void )
{
int V_314 = 0 ;
if ( F_179 () )
goto V_382;
if ( F_180 () )
goto V_383;
if ( F_181 () )
goto V_384;
if ( F_182 () )
goto V_385;
if ( F_183 () )
goto V_386;
V_31:
return V_314 ;
V_386:
F_184 () ;
V_385:
F_185 () ;
V_384:
F_186 () ;
V_383:
F_187 () ;
V_382:
V_314 = - V_350 ;
goto V_31;
}
static int T_10 F_175 ( void )
{
return 0 ;
}
