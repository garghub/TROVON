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
V_4 -> V_96 = 0 ;
F_35 ( V_2 ) ;
if ( V_4 -> V_18 ) {
V_4 -> V_22 = F_17 ( V_4 -> V_18 ) ;
V_2 -> V_19 -> V_39 ( V_2 ) ;
}
if ( V_2 -> V_19 -> V_97 ) {
V_26 = V_2 -> V_19 -> V_97 ( V_2 ) ;
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
long V_98 ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
V_98 = 0 ;
if ( F_6 ( V_2 , V_99 ) &&
! ( V_100 -> V_68 & V_101 ) )
V_98 = V_2 -> V_102 ;
V_1 -> V_2 = NULL ;
V_2 -> V_19 -> V_103 ( V_2 , V_98 ) ;
}
return 0 ;
}
int F_40 ( struct V_23 * V_1 , struct V_104 * V_105 , int V_106 )
{
struct V_107 * V_108 = (struct V_107 * ) V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_109 ;
int V_110 ;
int V_26 ;
if ( V_2 -> V_19 -> V_111 ) {
V_26 = V_2 -> V_19 -> V_111 ( V_2 , V_105 , V_106 ) ;
goto V_30;
}
V_26 = - V_27 ;
if ( V_106 < sizeof( struct V_107 ) )
goto V_30;
if ( V_108 -> V_112 != V_113 ) {
V_26 = - V_64 ;
if ( V_108 -> V_112 != V_114 ||
V_108 -> V_115 . V_116 != F_41 ( V_117 ) )
goto V_30;
}
V_110 = F_42 ( F_43 ( V_2 ) , V_108 -> V_115 . V_116 ) ;
V_26 = - V_118 ;
if ( ! V_119 &&
! ( V_4 -> V_120 || V_4 -> V_121 ) &&
V_108 -> V_115 . V_116 != F_41 ( V_117 ) &&
V_110 != V_122 &&
V_110 != V_123 &&
V_110 != V_124 )
goto V_30;
V_109 = F_44 ( V_108 -> V_125 ) ;
V_26 = - V_126 ;
if ( V_109 && V_109 < V_127 && ! F_32 ( V_128 ) )
goto V_30;
F_15 ( V_2 ) ;
V_26 = - V_27 ;
if ( V_2 -> V_9 != V_10 || V_4 -> V_18 )
goto V_129;
V_4 -> V_130 = V_4 -> V_131 = V_108 -> V_115 . V_116 ;
if ( V_110 == V_123 || V_110 == V_124 )
V_4 -> V_131 = 0 ;
if ( V_2 -> V_19 -> V_20 ( V_2 , V_109 ) ) {
V_4 -> V_131 = V_4 -> V_130 = 0 ;
V_26 = - V_132 ;
goto V_129;
}
if ( V_4 -> V_130 )
V_2 -> V_133 |= V_134 ;
if ( V_109 )
V_2 -> V_133 |= V_135 ;
V_4 -> V_22 = F_17 ( V_4 -> V_18 ) ;
V_4 -> V_136 = 0 ;
V_4 -> V_137 = 0 ;
F_45 ( V_2 ) ;
V_26 = 0 ;
V_129:
F_16 ( V_2 ) ;
V_30:
return V_26 ;
}
int F_46 ( struct V_23 * V_1 , struct V_104 * V_105 ,
int V_106 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_106 < sizeof( V_105 -> V_138 ) )
return - V_27 ;
if ( V_105 -> V_138 == V_114 )
return V_2 -> V_19 -> V_139 ( V_2 , V_68 ) ;
if ( ! F_2 ( V_2 ) -> V_18 && F_14 ( V_2 ) )
return - V_21 ;
return V_2 -> V_19 -> V_140 ( V_2 , (struct V_104 * ) V_105 , V_106 ) ;
}
static long F_47 ( struct V_1 * V_2 , long V_141 )
{
F_48 ( V_142 ) ;
F_49 ( F_50 ( V_2 ) , & V_142 , V_143 ) ;
while ( ( 1 << V_2 -> V_9 ) & ( V_144 | V_145 ) ) {
F_16 ( V_2 ) ;
V_141 = F_51 ( V_141 ) ;
F_15 ( V_2 ) ;
if ( F_52 ( V_100 ) || ! V_141 )
break;
F_49 ( F_50 ( V_2 ) , & V_142 , V_143 ) ;
}
F_53 ( F_50 ( V_2 ) , & V_142 ) ;
return V_141 ;
}
int F_54 ( struct V_23 * V_1 , struct V_104 * V_105 ,
int V_106 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 ;
long V_141 ;
if ( V_106 < sizeof( V_105 -> V_138 ) )
return - V_27 ;
F_15 ( V_2 ) ;
if ( V_105 -> V_138 == V_114 ) {
V_26 = V_2 -> V_19 -> V_139 ( V_2 , V_68 ) ;
V_1 -> V_28 = V_26 ? V_146 : V_29 ;
goto V_30;
}
switch ( V_1 -> V_28 ) {
default:
V_26 = - V_27 ;
goto V_30;
case V_147 :
V_26 = - V_148 ;
goto V_30;
case V_149 :
V_26 = - V_150 ;
break;
case V_29 :
V_26 = - V_148 ;
if ( V_2 -> V_9 != V_10 )
goto V_30;
V_26 = V_2 -> V_19 -> V_140 ( V_2 , V_105 , V_106 ) ;
if ( V_26 < 0 )
goto V_30;
V_1 -> V_28 = V_149 ;
V_26 = - V_151 ;
break;
}
V_141 = F_55 ( V_2 , V_68 & V_152 ) ;
if ( ( 1 << V_2 -> V_9 ) & ( V_144 | V_145 ) ) {
if ( ! V_141 || ! F_47 ( V_2 , V_141 ) )
goto V_30;
V_26 = F_56 ( V_141 ) ;
if ( F_52 ( V_100 ) )
goto V_30;
}
if ( V_2 -> V_9 == V_10 )
goto V_153;
V_1 -> V_28 = V_147 ;
V_26 = 0 ;
V_30:
F_16 ( V_2 ) ;
return V_26 ;
V_153:
V_26 = V_153 ( V_2 ) ? : - V_154 ;
V_1 -> V_28 = V_29 ;
if ( V_2 -> V_19 -> V_139 ( V_2 , V_68 ) )
V_1 -> V_28 = V_146 ;
goto V_30;
}
int F_57 ( struct V_23 * V_1 , struct V_23 * V_155 , int V_68 )
{
struct V_1 * V_156 = V_1 -> V_2 ;
int V_26 = - V_27 ;
struct V_1 * V_157 = V_156 -> V_19 -> V_158 ( V_156 , V_68 , & V_26 ) ;
if ( ! V_157 )
goto V_159;
F_15 ( V_157 ) ;
F_58 ( V_157 ) ;
F_7 ( ! ( ( 1 << V_157 -> V_9 ) &
( V_160 | V_161 | V_31 ) ) ) ;
F_59 ( V_157 , V_155 ) ;
V_155 -> V_28 = V_147 ;
V_26 = 0 ;
F_16 ( V_157 ) ;
V_159:
return V_26 ;
}
int F_60 ( struct V_23 * V_1 , struct V_104 * V_105 ,
int * V_162 , int V_163 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_61 ( struct V_107 * , sin , V_105 ) ;
sin -> V_112 = V_113 ;
if ( V_163 ) {
if ( ! V_4 -> V_137 ||
( ( ( 1 << V_2 -> V_9 ) & ( V_31 | V_144 ) ) &&
V_163 == 1 ) )
return - V_164 ;
sin -> V_125 = V_4 -> V_137 ;
sin -> V_115 . V_116 = V_4 -> V_136 ;
} else {
T_2 V_108 = V_4 -> V_130 ;
if ( ! V_108 )
V_108 = V_4 -> V_131 ;
sin -> V_125 = V_4 -> V_22 ;
sin -> V_115 . V_116 = V_108 ;
}
memset ( sin -> V_165 , 0 , sizeof( sin -> V_165 ) ) ;
* V_162 = sizeof( * sin ) ;
return 0 ;
}
int F_62 ( struct V_166 * V_167 , struct V_23 * V_1 , struct V_168 * V_169 ,
T_3 V_170 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_58 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_18 && ! V_2 -> V_19 -> V_171 &&
F_14 ( V_2 ) )
return - V_21 ;
return V_2 -> V_19 -> V_172 ( V_167 , V_2 , V_169 , V_170 ) ;
}
T_4 F_63 ( struct V_23 * V_1 , struct V_173 * V_173 , int V_174 ,
T_3 V_170 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_58 ( V_2 ) ;
if ( ! F_2 ( V_2 ) -> V_18 && ! V_2 -> V_19 -> V_171 &&
F_14 ( V_2 ) )
return - V_21 ;
if ( V_2 -> V_19 -> V_175 )
return V_2 -> V_19 -> V_175 ( V_2 , V_173 , V_174 , V_170 , V_68 ) ;
return F_64 ( V_1 , V_173 , V_174 , V_170 , V_68 ) ;
}
int F_65 ( struct V_166 * V_167 , struct V_23 * V_1 , struct V_168 * V_169 ,
T_3 V_170 , int V_68 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_106 = 0 ;
int V_26 ;
F_58 ( V_2 ) ;
V_26 = V_2 -> V_19 -> V_176 ( V_167 , V_2 , V_169 , V_170 , V_68 & V_177 ,
V_68 & ~ V_177 , & V_106 ) ;
if ( V_26 >= 0 )
V_169 -> V_178 = V_106 ;
return V_26 ;
}
int F_66 ( struct V_23 * V_1 , int V_179 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 = 0 ;
V_179 ++ ;
if ( ( V_179 & ~ V_180 ) || ! V_179 )
return - V_27 ;
F_15 ( V_2 ) ;
if ( V_1 -> V_28 == V_149 ) {
if ( ( 1 << V_2 -> V_9 ) &
( V_144 | V_145 | V_31 ) )
V_1 -> V_28 = V_146 ;
else
V_1 -> V_28 = V_147 ;
}
switch ( V_2 -> V_9 ) {
case V_10 :
V_26 = - V_164 ;
default:
V_2 -> V_181 |= V_179 ;
if ( V_2 -> V_19 -> V_182 )
V_2 -> V_19 -> V_182 ( V_2 , V_179 ) ;
break;
case V_33 :
if ( ! ( V_179 & V_183 ) )
break;
case V_184 :
V_26 = V_2 -> V_19 -> V_139 ( V_2 , V_152 ) ;
V_1 -> V_28 = V_26 ? V_146 : V_29 ;
break;
}
V_2 -> V_185 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_26 ;
}
int F_67 ( struct V_23 * V_1 , unsigned int V_186 , unsigned long V_187 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 = 0 ;
struct V_37 * V_37 = F_43 ( V_2 ) ;
switch ( V_186 ) {
case V_188 :
V_26 = F_68 ( V_2 , (struct V_189 V_190 * ) V_187 ) ;
break;
case V_191 :
V_26 = F_69 ( V_2 , (struct V_192 V_190 * ) V_187 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
V_26 = F_70 ( V_37 , V_186 , ( void V_190 * ) V_187 ) ;
break;
case V_196 :
case V_197 :
case V_198 :
V_26 = F_71 ( V_37 , V_186 , ( void V_190 * ) V_187 ) ;
break;
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
case V_209 :
V_26 = F_72 ( V_37 , V_186 , ( void V_190 * ) V_187 ) ;
break;
default:
if ( V_2 -> V_19 -> V_210 )
V_26 = V_2 -> V_19 -> V_210 ( V_2 , V_186 , V_187 ) ;
else
V_26 = - V_211 ;
break;
}
return V_26 ;
}
static int F_73 ( struct V_23 * V_1 , unsigned int V_186 , unsigned long V_187 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_26 = - V_211 ;
if ( V_2 -> V_19 -> V_212 )
V_26 = V_2 -> V_19 -> V_212 ( V_2 , V_186 , V_187 ) ;
return V_26 ;
}
void F_74 ( struct V_47 * V_213 )
{
struct V_214 * V_215 ;
struct V_47 * V_48 ;
int V_38 = V_213 -> V_38 ;
struct V_214 * V_216 ;
F_75 ( & V_217 ) ;
if ( V_213 -> type >= V_218 )
goto V_219;
V_48 = NULL ;
V_216 = & V_220 [ V_213 -> type ] ;
F_76 (lh, &inetsw[p->type]) {
V_48 = F_77 ( V_215 , struct V_47 , V_221 ) ;
if ( V_222 & V_48 -> V_68 ) {
if ( V_38 == V_48 -> V_38 )
break;
V_216 = V_215 ;
}
V_48 = NULL ;
}
if ( V_48 )
goto V_223;
F_78 ( & V_213 -> V_221 , V_216 ) ;
V_30:
F_79 ( & V_217 ) ;
return;
V_223:
F_5 ( L_5 , V_38 ) ;
goto V_30;
V_219:
F_5 ( L_6 ,
V_213 -> type ) ;
goto V_30;
}
void F_80 ( struct V_47 * V_213 )
{
if ( V_222 & V_213 -> V_68 ) {
F_5 ( L_7 ,
V_213 -> V_38 ) ;
} else {
F_75 ( & V_217 ) ;
F_81 ( & V_213 -> V_221 ) ;
F_79 ( & V_217 ) ;
F_82 () ;
}
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_224 = V_4 -> V_131 ;
T_2 V_225 = V_4 -> V_136 ;
struct V_226 * V_227 ;
struct V_228 * V_229 ;
T_2 V_230 ;
struct V_231 * V_16 ;
V_16 = F_10 ( V_4 -> V_16 ,
F_84 ( V_2 ) ) ;
if ( V_16 && V_16 -> V_232 . V_233 )
V_225 = V_16 -> V_232 . V_234 ;
V_227 = & V_4 -> V_235 . V_236 . V_237 . V_238 ;
V_229 = F_85 ( V_227 , V_225 , 0 , F_86 ( V_2 ) ,
V_2 -> V_239 , V_2 -> V_87 ,
V_4 -> V_22 , V_4 -> V_137 , V_2 , false ) ;
if ( F_87 ( V_229 ) )
return F_88 ( V_229 ) ;
F_89 ( V_2 , & V_229 -> V_240 ) ;
V_230 = V_227 -> V_241 ;
if ( V_230 == V_224 )
return 0 ;
if ( V_242 > 1 ) {
F_90 ( L_8 ,
V_243 , & V_224 , & V_230 ) ;
}
V_4 -> V_131 = V_4 -> V_130 = V_230 ;
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
V_225 = V_4 -> V_136 ;
if ( V_16 && V_16 -> V_232 . V_233 )
V_225 = V_16 -> V_232 . V_234 ;
F_30 () ;
V_227 = & V_4 -> V_235 . V_236 . V_237 . V_238 ;
V_229 = F_94 ( F_43 ( V_2 ) , V_227 , V_2 , V_225 , V_4 -> V_131 ,
V_4 -> V_137 , V_4 -> V_22 ,
V_2 -> V_87 , F_86 ( V_2 ) ,
V_2 -> V_239 ) ;
if ( ! F_87 ( V_229 ) ) {
V_26 = 0 ;
F_89 ( V_2 , & V_229 -> V_240 ) ;
} else {
V_26 = F_88 ( V_229 ) ;
V_2 -> V_244 = 0 ;
if ( ! V_242 ||
V_2 -> V_9 != V_184 ||
( V_2 -> V_133 & V_134 ) ||
( V_26 = F_83 ( V_2 ) ) != 0 )
V_2 -> V_245 = - V_26 ;
}
return V_26 ;
}
static int F_95 ( struct V_246 * V_247 )
{
const struct V_248 * V_249 ;
const struct V_40 * V_65 ;
int V_49 ;
int V_250 ;
int V_26 = - V_27 ;
if ( F_27 ( ! F_96 ( V_247 , sizeof( * V_249 ) ) ) )
goto V_30;
V_249 = F_97 ( V_247 ) ;
V_250 = V_249 -> V_250 * 4 ;
if ( V_250 < sizeof( * V_249 ) )
goto V_30;
if ( F_27 ( ! F_96 ( V_247 , V_250 ) ) )
goto V_30;
F_98 ( V_247 , V_250 ) ;
F_99 ( V_247 ) ;
V_249 = F_97 ( V_247 ) ;
V_49 = V_249 -> V_38 & ( V_43 - 1 ) ;
V_26 = - V_59 ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( F_100 ( V_65 && V_65 -> V_251 ) )
V_26 = V_65 -> V_251 ( V_247 ) ;
F_30 () ;
V_30:
return V_26 ;
}
static struct V_246 * F_101 ( struct V_246 * V_247 ,
T_5 V_252 )
{
struct V_246 * V_253 = F_102 ( - V_27 ) ;
struct V_248 * V_249 ;
const struct V_40 * V_65 ;
int V_49 ;
int V_250 ;
int V_254 ;
unsigned int V_174 = 0 ;
if ( ! ( V_252 & V_255 ) )
V_252 &= ~ V_256 ;
if ( F_27 ( F_103 ( V_247 ) -> V_257 &
~ ( V_258 |
V_259 |
V_260 |
V_261 |
0 ) ) )
goto V_30;
if ( F_27 ( ! F_96 ( V_247 , sizeof( * V_249 ) ) ) )
goto V_30;
V_249 = F_97 ( V_247 ) ;
V_250 = V_249 -> V_250 * 4 ;
if ( V_250 < sizeof( * V_249 ) )
goto V_30;
if ( F_27 ( ! F_96 ( V_247 , V_250 ) ) )
goto V_30;
F_98 ( V_247 , V_250 ) ;
F_99 ( V_247 ) ;
V_249 = F_97 ( V_247 ) ;
V_254 = F_44 ( V_249 -> V_254 ) ;
V_49 = V_249 -> V_38 & ( V_43 - 1 ) ;
V_253 = F_102 ( - V_59 ) ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( F_100 ( V_65 && V_65 -> V_262 ) )
V_253 = V_65 -> V_262 ( V_247 , V_252 ) ;
F_30 () ;
if ( ! V_253 || F_87 ( V_253 ) )
goto V_30;
V_247 = V_253 ;
do {
V_249 = F_97 ( V_247 ) ;
if ( V_49 == V_263 ) {
V_249 -> V_254 = F_17 ( V_254 ) ;
V_249 -> V_264 = F_17 ( V_174 >> 3 ) ;
if ( V_247 -> V_265 != NULL )
V_249 -> V_264 |= F_17 ( V_266 ) ;
V_174 += ( V_247 -> V_267 - V_247 -> V_268 - V_249 -> V_250 * 4 ) ;
} else
V_249 -> V_254 = F_17 ( V_254 ++ ) ;
V_249 -> V_269 = F_17 ( V_247 -> V_267 - V_247 -> V_268 ) ;
V_249 -> V_270 = 0 ;
V_249 -> V_270 = F_104 ( F_105 ( V_247 ) , V_249 -> V_250 ) ;
} while ( ( V_247 = V_247 -> V_265 ) );
V_30:
return V_253 ;
}
static struct V_246 * * F_106 ( struct V_246 * * V_271 ,
struct V_246 * V_247 )
{
const struct V_40 * V_65 ;
struct V_246 * * V_272 = NULL ;
struct V_246 * V_213 ;
const struct V_248 * V_249 ;
unsigned int V_273 ;
unsigned int V_274 ;
unsigned int V_254 ;
int V_275 = 1 ;
int V_49 ;
V_274 = F_107 ( V_247 ) ;
V_273 = V_274 + sizeof( * V_249 ) ;
V_249 = F_108 ( V_247 , V_274 ) ;
if ( F_109 ( V_247 , V_273 ) ) {
V_249 = F_110 ( V_247 , V_273 , V_274 ) ;
if ( F_27 ( ! V_249 ) )
goto V_30;
}
V_49 = V_249 -> V_38 & ( V_43 - 1 ) ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( ! V_65 || ! V_65 -> V_276 )
goto V_277;
if ( * ( V_278 * ) V_249 != 0x45 )
goto V_277;
if ( F_27 ( F_104 ( ( V_278 * ) V_249 , V_249 -> V_250 ) ) )
goto V_277;
V_254 = F_111 ( * ( T_2 * ) & V_249 -> V_254 ) ;
V_275 = ( V_279 ) ( ( F_111 ( * ( T_2 * ) V_249 ) ^ F_112 ( V_247 ) ) | ( V_254 ^ V_280 ) ) ;
V_254 >>= 16 ;
for ( V_213 = * V_271 ; V_213 ; V_213 = V_213 -> V_265 ) {
struct V_248 * V_281 ;
if ( ! F_113 ( V_213 ) -> V_282 )
continue;
V_281 = F_97 ( V_213 ) ;
if ( ( V_249 -> V_38 ^ V_281 -> V_38 ) |
( V_249 -> V_283 ^ V_281 -> V_283 ) |
( ( V_284 T_1 ) V_249 -> V_241 ^ ( V_284 T_1 ) V_281 -> V_241 ) |
( ( V_284 T_1 ) V_249 -> V_225 ^ ( V_284 T_1 ) V_281 -> V_225 ) ) {
F_113 ( V_213 ) -> V_282 = 0 ;
continue;
}
F_113 ( V_213 ) -> V_275 |=
( V_249 -> V_285 ^ V_281 -> V_285 ) |
( ( V_279 ) ( F_44 ( V_281 -> V_254 ) + F_113 ( V_213 ) -> V_286 ) ^ V_254 ) ;
F_113 ( V_213 ) -> V_275 |= V_275 ;
}
F_113 ( V_247 ) -> V_275 |= V_275 ;
F_114 ( V_247 , sizeof( * V_249 ) ) ;
F_115 ( V_247 , F_107 ( V_247 ) ) ;
V_272 = V_65 -> V_276 ( V_271 , V_247 ) ;
V_277:
F_30 () ;
V_30:
F_113 ( V_247 ) -> V_275 |= V_275 ;
return V_272 ;
}
static int F_116 ( struct V_246 * V_247 )
{
const struct V_40 * V_65 ;
struct V_248 * V_249 = F_97 ( V_247 ) ;
int V_49 = V_249 -> V_38 & ( V_43 - 1 ) ;
int V_26 = - V_287 ;
T_6 V_288 = F_17 ( V_247 -> V_267 - F_117 ( V_247 ) ) ;
F_118 ( & V_249 -> V_270 , V_249 -> V_269 , V_288 ) ;
V_249 -> V_269 = V_288 ;
F_28 () ;
V_65 = F_25 ( V_44 [ V_49 ] ) ;
if ( F_7 ( ! V_65 || ! V_65 -> V_289 ) )
goto V_277;
V_26 = V_65 -> V_289 ( V_247 ) ;
V_277:
F_30 () ;
return V_26 ;
}
int F_119 ( struct V_1 * * V_2 , unsigned short V_290 ,
unsigned short type , unsigned char V_38 ,
struct V_37 * V_37 )
{
struct V_23 * V_1 ;
int V_291 = F_120 ( V_290 , type , V_38 , & V_1 ) ;
if ( V_291 == 0 ) {
* V_2 = V_1 -> V_2 ;
( * V_2 ) -> V_292 = V_293 ;
( * V_2 ) -> V_19 -> V_294 ( * V_2 ) ;
F_121 ( * V_2 , V_37 ) ;
}
return V_291 ;
}
unsigned long F_122 ( void T_7 * V_295 [] , int V_296 )
{
unsigned long V_297 = 0 ;
int V_298 , V_299 ;
F_123 (i) {
for ( V_299 = 0 ; V_299 < V_300 ; V_299 ++ )
V_297 += * ( ( ( unsigned long * ) F_124 ( V_295 [ V_299 ] , V_298 ) ) + V_296 ) ;
}
return V_297 ;
}
T_8 F_125 ( void T_7 * V_295 [] , int V_296 , T_3 V_301 )
{
T_8 V_297 = 0 ;
int V_302 ;
F_123 (cpu) {
void * V_303 ;
struct V_304 * V_305 ;
T_8 V_306 ;
unsigned int V_307 ;
V_303 = F_124 ( V_295 [ 0 ] , V_302 ) ;
V_305 = (struct V_304 * ) ( V_303 + V_301 ) ;
do {
V_307 = F_126 ( V_305 ) ;
V_306 = * ( ( ( T_8 * ) V_303 ) + V_296 ) ;
} while ( F_127 ( V_305 , V_307 ) );
V_297 += V_306 ;
}
return V_297 ;
}
int F_128 ( void T_7 * V_308 [ 2 ] , T_3 V_309 , T_3 V_310 )
{
F_129 ( V_308 == NULL ) ;
V_308 [ 0 ] = F_130 ( V_309 , V_310 ) ;
if ( ! V_308 [ 0 ] )
return - V_311 ;
#if V_300 == 2
V_308 [ 1 ] = F_130 ( V_309 , V_310 ) ;
if ( ! V_308 [ 1 ] ) {
F_131 ( V_308 [ 0 ] ) ;
V_308 [ 0 ] = NULL ;
return - V_311 ;
}
#endif
return 0 ;
}
void F_132 ( void T_7 * V_308 [ V_300 ] )
{
int V_298 ;
F_129 ( V_308 == NULL ) ;
for ( V_298 = 0 ; V_298 < V_300 ; V_298 ++ ) {
F_131 ( V_308 [ V_298 ] ) ;
V_308 [ V_298 ] = NULL ;
}
}
static T_9 int F_133 ( struct V_37 * V_37 )
{
if ( F_128 ( ( void T_7 * * ) V_37 -> V_295 . V_312 ,
sizeof( struct V_313 ) ,
F_134 ( struct V_313 ) ) < 0 )
goto V_314;
if ( F_128 ( ( void T_7 * * ) V_37 -> V_295 . V_315 ,
sizeof( struct V_316 ) ,
F_134 ( struct V_316 ) ) < 0 )
goto V_317;
if ( F_128 ( ( void T_7 * * ) V_37 -> V_295 . V_318 ,
sizeof( struct V_319 ) ,
F_134 ( struct V_319 ) ) < 0 )
goto V_320;
if ( F_128 ( ( void T_7 * * ) V_37 -> V_295 . V_321 ,
sizeof( struct V_322 ) ,
F_134 ( struct V_322 ) ) < 0 )
goto V_323;
if ( F_128 ( ( void T_7 * * ) V_37 -> V_295 . V_324 ,
sizeof( struct V_322 ) ,
F_134 ( struct V_322 ) ) < 0 )
goto V_325;
if ( F_128 ( ( void T_7 * * ) V_37 -> V_295 . V_326 ,
sizeof( struct V_327 ) ,
F_134 ( struct V_327 ) ) < 0 )
goto V_328;
V_37 -> V_295 . V_329 = F_135 ( sizeof( struct V_330 ) ,
V_71 ) ;
if ( ! V_37 -> V_295 . V_329 )
goto V_331;
F_136 ( V_37 ) ;
return 0 ;
V_331:
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_326 ) ;
V_328:
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_324 ) ;
V_325:
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_321 ) ;
V_323:
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_318 ) ;
V_320:
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_315 ) ;
V_317:
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_312 ) ;
V_314:
return - V_311 ;
}
static T_10 void F_137 ( struct V_37 * V_37 )
{
F_9 ( V_37 -> V_295 . V_329 ) ;
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_326 ) ;
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_324 ) ;
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_321 ) ;
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_318 ) ;
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_315 ) ;
F_132 ( ( void T_7 * * ) V_37 -> V_295 . V_312 ) ;
}
static int T_11 F_138 ( void )
{
return F_139 ( & V_332 ) ;
}
static int T_11 F_140 ( void )
{
struct V_246 * V_333 ;
struct V_47 * V_334 ;
struct V_214 * V_335 ;
int V_291 = - V_27 ;
F_141 ( sizeof( struct V_336 ) > sizeof( V_333 -> V_337 ) ) ;
V_338 = F_135 ( 65536 / 8 , V_71 ) ;
if ( ! V_338 )
goto V_30;
V_291 = F_142 ( & V_339 , 1 ) ;
if ( V_291 )
goto V_340;
V_291 = F_142 ( & V_341 , 1 ) ;
if ( V_291 )
goto V_342;
V_291 = F_142 ( & V_343 , 1 ) ;
if ( V_291 )
goto V_344;
V_291 = F_142 ( & V_345 , 1 ) ;
if ( V_291 )
goto V_346;
( void ) F_143 ( & V_347 ) ;
#ifdef F_144
F_145 () ;
#endif
V_339 . V_348 = V_42 . V_349 . V_350 ;
if ( F_146 ( & V_351 , V_352 ) < 0 )
F_147 ( L_9 , V_243 ) ;
if ( F_146 ( & V_353 , V_263 ) < 0 )
F_147 ( L_10 , V_243 ) ;
if ( F_146 ( & V_354 , V_355 ) < 0 )
F_147 ( L_11 , V_243 ) ;
#ifdef F_148
if ( F_146 ( & V_356 , V_357 ) < 0 )
F_147 ( L_12 , V_243 ) ;
#endif
for ( V_335 = & V_220 [ 0 ] ; V_335 < & V_220 [ V_218 ] ; ++ V_335 )
F_149 ( V_335 ) ;
for ( V_334 = V_358 ; V_334 < & V_358 [ V_359 ] ; ++ V_334 )
F_74 ( V_334 ) ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
F_154 () ;
F_155 () ;
F_156 () ;
if ( F_157 () < 0 )
F_158 ( L_13 ) ;
#if F_159 ( V_360 )
if ( F_160 () )
F_147 ( L_14 , V_243 ) ;
#endif
if ( F_138 () )
F_147 ( L_15 , V_243 ) ;
F_161 () ;
F_162 () ;
F_163 ( & V_361 ) ;
V_291 = 0 ;
V_30:
return V_291 ;
V_346:
F_164 ( & V_343 ) ;
V_344:
F_164 ( & V_341 ) ;
V_342:
F_164 ( & V_339 ) ;
V_340:
F_9 ( V_338 ) ;
goto V_30;
}
static int T_11 F_161 ( void )
{
int V_291 = 0 ;
if ( F_165 () )
goto V_362;
if ( F_166 () )
goto V_363;
if ( F_167 () )
goto V_364;
if ( F_168 () )
goto V_365;
if ( F_169 () )
goto V_366;
V_30:
return V_291 ;
V_366:
F_170 () ;
V_365:
F_171 () ;
V_364:
F_172 () ;
V_363:
F_173 () ;
V_362:
V_291 = - V_311 ;
goto V_30;
}
static int T_11 F_161 ( void )
{
return 0 ;
}
