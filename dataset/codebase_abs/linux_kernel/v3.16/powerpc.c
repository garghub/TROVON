int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 . V_4 ) ||
V_2 -> V_5 ;
}
int F_2 ( struct V_1 * V_6 )
{
return 1 ;
}
int F_3 ( struct V_1 * V_6 )
{
int V_7 ;
F_4 ( F_5 () ) ;
F_6 () ;
while ( true ) {
if ( F_7 () ) {
F_8 () ;
F_9 () ;
F_6 () ;
continue;
}
if ( F_10 ( V_8 ) ) {
F_11 ( V_6 , V_9 ) ;
V_6 -> V_10 -> V_11 = V_12 ;
V_7 = - V_13 ;
break;
}
V_6 -> V_14 = V_15 ;
F_12 () ;
if ( V_6 -> V_5 ) {
F_8 () ;
F_13 ( V_6 ) ;
V_7 = F_14 ( V_6 ) ;
F_6 () ;
if ( V_7 > 0 )
continue;
break;
}
if ( F_15 ( V_6 ) ) {
continue;
}
F_16 () ;
return 1 ;
}
F_8 () ;
return V_7 ;
}
static void F_17 ( struct V_1 * V_6 )
{
struct V_16 * V_17 = V_6 -> V_3 . V_17 ;
int V_18 ;
V_17 -> V_19 = F_18 ( V_17 -> V_19 ) ;
V_17 -> V_20 = F_18 ( V_17 -> V_20 ) ;
V_17 -> V_21 = F_18 ( V_17 -> V_21 ) ;
V_17 -> V_22 = F_18 ( V_17 -> V_22 ) ;
V_17 -> V_23 = F_18 ( V_17 -> V_23 ) ;
V_17 -> V_24 = F_18 ( V_17 -> V_24 ) ;
V_17 -> V_25 = F_18 ( V_17 -> V_25 ) ;
V_17 -> V_26 = F_18 ( V_17 -> V_26 ) ;
V_17 -> V_27 = F_19 ( V_17 -> V_27 ) ;
V_17 -> V_28 = F_19 ( V_17 -> V_28 ) ;
for ( V_18 = 0 ; V_18 < F_20 ( V_17 -> V_29 ) ; V_18 ++ )
V_17 -> V_29 [ V_18 ] = F_19 ( V_17 -> V_29 [ V_18 ] ) ;
}
int F_21 ( struct V_1 * V_6 )
{
int V_30 = F_22 ( V_6 , 11 ) ;
int V_7 ;
unsigned long T_1 V_31 = F_22 ( V_6 , 3 ) ;
unsigned long T_1 V_32 = F_22 ( V_6 , 4 ) ;
unsigned long T_1 V_33 = F_22 ( V_6 , 5 ) ;
unsigned long T_1 V_34 = F_22 ( V_6 , 6 ) ;
unsigned long V_35 = 0 ;
if ( ! ( F_23 ( V_6 ) & V_36 ) ) {
V_31 &= 0xffffffff ;
V_32 &= 0xffffffff ;
V_33 &= 0xffffffff ;
V_34 &= 0xffffffff ;
}
switch ( V_30 ) {
case F_24 ( V_37 ) :
{
#if F_25 ( V_38 ) && F_25 ( V_39 )
int V_40 = true ;
if ( V_6 -> V_3 . V_41 & V_42 )
V_40 = false ;
if ( V_40 != V_6 -> V_3 . V_40 )
F_17 ( V_6 ) ;
V_6 -> V_3 . V_40 = V_40 ;
#endif
if ( ! ( V_32 & V_43 ) ) {
V_6 -> V_3 . V_44 = true ;
F_26 ( V_45 , V_6 ) ;
}
V_6 -> V_3 . V_46 = V_31 & ~ 0xfffULL ;
V_6 -> V_3 . V_47 = V_32 & ~ 0xfffULL ;
V_35 = V_48 | V_49 ;
V_7 = V_50 ;
break;
}
case F_24 ( V_51 ) :
V_7 = V_50 ;
#if F_25 ( V_52 ) || F_25 ( V_53 )
V_35 |= ( 1 << V_54 ) ;
#endif
break;
case F_27 ( V_55 ) :
V_7 = V_50 ;
F_28 ( V_6 ) ;
F_29 ( V_56 , & V_6 -> V_5 ) ;
break;
default:
V_7 = V_57 ;
break;
}
F_30 ( V_6 , 4 , V_35 ) ;
return V_7 ;
}
int F_31 ( struct V_1 * V_6 )
{
int V_7 = false ;
if ( ! V_6 -> V_3 . V_58 )
goto V_59;
if ( ( V_6 -> V_3 . V_60 != V_61 ) && V_6 -> V_3 . V_62 )
goto V_59;
if ( ! V_6 -> V_3 . V_62 && F_32 ( V_6 -> V_63 ) )
goto V_59;
#ifdef F_33
if ( ! F_34 ( V_64 ) )
goto V_59;
#endif
V_7 = true ;
V_59:
V_6 -> V_3 . V_65 = V_7 ;
return V_7 ? 0 : - V_66 ;
}
int F_35 ( struct V_67 * V_10 , struct V_1 * V_6 )
{
enum V_68 V_69 ;
int V_7 ;
V_69 = F_36 ( V_10 , V_6 ) ;
switch ( V_69 ) {
case V_70 :
V_7 = V_71 ;
break;
case V_72 :
V_10 -> V_11 = V_73 ;
V_7 = V_74 ;
break;
case V_75 :
F_37 ( V_76 L_1 , V_77 ,
F_38 ( V_6 ) ) ;
V_7 = V_78 ;
break;
default:
F_4 ( 1 ) ;
V_7 = V_79 ;
}
return V_7 ;
}
int F_39 ( void * V_80 )
{
return 0 ;
}
void F_40 ( void * V_80 )
{
}
int F_41 ( void )
{
return 0 ;
}
void F_42 ( void )
{
}
void F_43 ( void * V_81 )
{
* ( int * ) V_81 = F_44 () ;
}
int F_45 ( struct V_63 * V_63 , unsigned long type )
{
struct V_82 * V_83 = NULL ;
if ( type == 0 ) {
if ( V_84 )
V_83 = V_84 ;
else
V_83 = V_85 ;
if ( ! V_83 )
goto V_86;
} else if ( type == V_87 ) {
if ( ! V_84 )
goto V_86;
V_83 = V_84 ;
} else if ( type == V_88 ) {
if ( ! V_85 )
goto V_86;
V_83 = V_85 ;
} else
goto V_86;
if ( V_83 -> V_89 && ! F_46 ( V_83 -> V_89 ) )
return - V_90 ;
V_63 -> V_3 . V_83 = V_83 ;
return F_47 ( V_63 ) ;
V_86:
return - V_66 ;
}
void F_48 ( struct V_63 * V_63 )
{
unsigned int V_18 ;
struct V_1 * V_6 ;
F_49 (i, vcpu, kvm)
F_50 ( V_6 ) ;
F_51 ( & V_63 -> V_91 ) ;
for ( V_18 = 0 ; V_18 < F_52 ( & V_63 -> V_92 ) ; V_18 ++ )
V_63 -> V_93 [ V_18 ] = NULL ;
F_53 ( & V_63 -> V_92 , 0 ) ;
F_54 ( V_63 ) ;
F_55 ( & V_63 -> V_91 ) ;
F_56 ( V_63 -> V_3 . V_83 -> V_89 ) ;
}
void F_57 ( struct V_63 * V_63 )
{
}
int F_58 ( long V_94 )
{
int V_7 ;
int V_95 = V_84 ? 1 : 0 ;
switch ( V_94 ) {
#ifdef F_59
case V_96 :
case V_97 :
case V_98 :
#else
case V_99 :
case V_100 :
case V_101 :
#endif
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_7 = 1 ;
break;
case V_108 :
case V_109 :
case V_110 :
#if F_25 ( V_53 ) || F_25 ( V_111 )
case V_112 :
#endif
V_7 = ! V_95 ;
break;
#ifdef F_60
case V_113 :
V_7 = V_114 ;
break;
#endif
#ifdef F_61
case V_115 :
V_7 = 1 ;
break;
#endif
#ifdef V_38
case V_116 :
case V_117 :
case V_118 :
case V_119 :
#ifdef F_62
case V_120 :
#endif
V_7 = 1 ;
break;
#endif
#ifdef F_63
case V_121 :
if ( V_95 )
V_7 = V_122 ;
else
V_7 = 0 ;
break;
case V_123 :
V_7 = V_95 ;
if ( V_7 && F_34 ( V_124 ) )
V_7 = 2 ;
break;
#endif
case V_125 :
#ifdef F_63
if ( V_95 )
V_7 = F_34 ( V_126 ) ? 1 : 0 ;
else
V_7 = 0 ;
#elif F_25 ( V_127 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_63
case V_128 :
V_7 = V_95 ;
break;
#endif
case V_129 :
if ( V_95 )
V_7 = F_64 () ;
else
V_7 = F_65 () ;
break;
case V_130 :
V_7 = V_131 ;
break;
#ifdef V_38
case V_132 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_66 ( struct V_133 * V_134 ,
unsigned int V_135 , unsigned long V_136 )
{
return - V_66 ;
}
void F_67 ( struct V_63 * V_63 , struct V_137 * free ,
struct V_137 * V_138 )
{
F_68 ( V_63 , free , V_138 ) ;
}
int F_69 ( struct V_63 * V_63 , struct V_137 * V_139 ,
unsigned long V_140 )
{
return F_70 ( V_63 , V_139 , V_140 ) ;
}
void F_71 ( struct V_63 * V_63 )
{
}
int F_72 ( struct V_63 * V_63 ,
struct V_137 * V_141 ,
struct V_142 * V_143 ,
enum V_144 V_145 )
{
return F_73 ( V_63 , V_141 , V_143 ) ;
}
void F_74 ( struct V_63 * V_63 ,
struct V_142 * V_143 ,
const struct V_137 * V_146 ,
enum V_144 V_145 )
{
F_75 ( V_63 , V_143 , V_146 ) ;
}
void F_76 ( struct V_63 * V_63 )
{
}
void F_77 ( struct V_63 * V_63 ,
struct V_137 * V_139 )
{
F_78 ( V_63 , V_139 ) ;
}
struct V_1 * F_79 ( struct V_63 * V_63 , unsigned int V_147 )
{
struct V_1 * V_6 ;
V_6 = F_80 ( V_63 , V_147 ) ;
if ( ! F_81 ( V_6 ) ) {
V_6 -> V_3 . V_148 = & V_6 -> V_149 ;
F_82 ( V_6 , V_147 ) ;
}
return V_6 ;
}
int F_83 ( struct V_1 * V_6 )
{
return 0 ;
}
void F_50 ( struct V_1 * V_6 )
{
F_84 ( & V_6 -> V_3 . V_150 ) ;
F_85 ( & V_6 -> V_3 . V_151 ) ;
F_86 ( V_6 ) ;
switch ( V_6 -> V_3 . V_152 ) {
case V_153 :
F_87 ( V_6 -> V_3 . V_154 , V_6 ) ;
break;
case V_155 :
F_88 ( V_6 ) ;
break;
}
F_89 ( V_6 ) ;
}
void F_90 ( struct V_1 * V_6 )
{
F_50 ( V_6 ) ;
}
int F_91 ( struct V_1 * V_6 )
{
return F_92 ( V_6 ) ;
}
enum V_156 F_93 ( struct V_157 * V_158 )
{
struct V_1 * V_6 ;
V_6 = F_94 ( V_158 , struct V_1 , V_3 . V_150 ) ;
F_95 ( & V_6 -> V_3 . V_151 ) ;
return V_159 ;
}
int F_96 ( struct V_1 * V_6 )
{
int V_160 ;
F_97 ( & V_6 -> V_3 . V_150 , V_161 , V_162 ) ;
F_98 ( & V_6 -> V_3 . V_151 , V_163 , ( V_164 ) V_6 ) ;
V_6 -> V_3 . V_150 . V_165 = F_93 ;
V_6 -> V_3 . V_166 = ~ ( V_167 ) 0 ;
#ifdef F_99
F_100 ( & V_6 -> V_3 . V_168 ) ;
#endif
V_160 = F_101 ( V_6 ) ;
return V_160 ;
}
void F_102 ( struct V_1 * V_6 )
{
F_103 ( V_6 ) ;
F_104 ( V_6 ) ;
}
void F_105 ( struct V_1 * V_6 , int V_169 )
{
#ifdef F_59
F_106 ( V_170 , V_6 -> V_3 . V_171 ) ;
#endif
F_107 ( V_6 , V_169 ) ;
}
void F_108 ( struct V_1 * V_6 )
{
F_109 ( V_6 ) ;
#ifdef F_59
V_6 -> V_3 . V_171 = F_110 ( V_170 ) ;
#endif
}
static void F_111 ( struct V_1 * V_6 ,
struct V_67 * V_10 )
{
F_30 ( V_6 , V_6 -> V_3 . V_172 , V_10 -> V_173 . V_174 ) ;
}
static void F_112 ( struct V_1 * V_6 ,
struct V_67 * V_10 )
{
V_167 V_175 ( V_176 ) ;
if ( V_10 -> V_177 . V_178 > sizeof( V_176 ) ) {
F_37 ( V_179 L_2 , V_10 -> V_177 . V_178 ) ;
return;
}
if ( V_6 -> V_3 . V_180 ) {
switch ( V_10 -> V_177 . V_178 ) {
case 8 : V_176 = * ( V_167 * ) V_10 -> V_177 . V_174 ; break;
case 4 : V_176 = * ( V_181 * ) V_10 -> V_177 . V_174 ; break;
case 2 : V_176 = * ( V_182 * ) V_10 -> V_177 . V_174 ; break;
case 1 : V_176 = * ( V_183 * ) V_10 -> V_177 . V_174 ; break;
}
} else {
switch ( V_10 -> V_177 . V_178 ) {
case 4 : V_176 = F_113 ( ( V_181 * ) V_10 -> V_177 . V_174 ) ; break;
case 2 : V_176 = F_114 ( ( V_182 * ) V_10 -> V_177 . V_174 ) ; break;
case 1 : V_176 = * ( V_183 * ) V_10 -> V_177 . V_174 ; break;
}
}
if ( V_6 -> V_3 . V_184 ) {
switch ( V_10 -> V_177 . V_178 ) {
#ifdef F_115
case 4 :
V_176 = ( V_185 ) ( V_186 ) V_176 ;
break;
#endif
case 2 :
V_176 = ( V_185 ) ( V_187 ) V_176 ;
break;
case 1 :
V_176 = ( V_185 ) ( V_188 ) V_176 ;
break;
}
}
F_30 ( V_6 , V_6 -> V_3 . V_172 , V_176 ) ;
switch ( V_6 -> V_3 . V_172 & V_189 ) {
case V_190 :
F_30 ( V_6 , V_6 -> V_3 . V_172 , V_176 ) ;
break;
case V_191 :
F_116 ( V_6 , V_6 -> V_3 . V_172 & V_192 ) = V_176 ;
break;
#ifdef V_52
case V_193 :
V_6 -> V_3 . V_194 [ V_6 -> V_3 . V_172 & V_192 ] = V_176 ;
break;
case V_195 :
F_116 ( V_6 , V_6 -> V_3 . V_172 & V_192 ) = V_176 ;
V_6 -> V_3 . V_194 [ V_6 -> V_3 . V_172 & V_192 ] = V_176 ;
break;
#endif
default:
F_117 () ;
}
}
int F_118 ( struct V_67 * V_10 , struct V_1 * V_6 ,
unsigned int V_196 , unsigned int V_197 ,
int V_198 )
{
int V_199 , V_160 ;
int V_200 ;
if ( F_119 ( V_6 ) ) {
V_200 = ! V_198 ;
} else {
V_200 = V_198 ;
}
if ( V_197 > sizeof( V_10 -> V_177 . V_174 ) ) {
F_37 ( V_179 L_3 , V_77 ,
V_10 -> V_177 . V_178 ) ;
}
V_10 -> V_177 . V_201 = V_6 -> V_3 . V_202 ;
V_10 -> V_177 . V_178 = V_197 ;
V_10 -> V_177 . V_203 = 0 ;
V_6 -> V_3 . V_172 = V_196 ;
V_6 -> V_3 . V_180 = V_200 ;
V_6 -> V_204 = 1 ;
V_6 -> V_205 = 0 ;
V_6 -> V_3 . V_184 = 0 ;
V_199 = F_120 ( & V_6 -> V_63 -> V_206 ) ;
V_160 = F_121 ( V_6 -> V_63 , V_207 , V_10 -> V_177 . V_201 ,
V_197 , & V_10 -> V_177 . V_174 ) ;
F_122 ( & V_6 -> V_63 -> V_206 , V_199 ) ;
if ( ! V_160 ) {
F_112 ( V_6 , V_10 ) ;
V_6 -> V_204 = 0 ;
return V_70 ;
}
return V_72 ;
}
int F_123 ( struct V_67 * V_10 , struct V_1 * V_6 ,
unsigned int V_196 , unsigned int V_197 ,
int V_198 )
{
int V_7 ;
V_6 -> V_3 . V_184 = 1 ;
V_7 = F_118 ( V_10 , V_6 , V_196 , V_197 , V_198 ) ;
return V_7 ;
}
int F_124 ( struct V_67 * V_10 , struct V_1 * V_6 ,
V_167 V_208 , unsigned int V_197 , int V_198 )
{
void * V_174 = V_10 -> V_177 . V_174 ;
int V_199 , V_160 ;
int V_200 ;
if ( F_119 ( V_6 ) ) {
V_200 = ! V_198 ;
} else {
V_200 = V_198 ;
}
if ( V_197 > sizeof( V_10 -> V_177 . V_174 ) ) {
F_37 ( V_179 L_3 , V_77 ,
V_10 -> V_177 . V_178 ) ;
}
V_10 -> V_177 . V_201 = V_6 -> V_3 . V_202 ;
V_10 -> V_177 . V_178 = V_197 ;
V_10 -> V_177 . V_203 = 1 ;
V_6 -> V_204 = 1 ;
V_6 -> V_205 = 1 ;
if ( V_200 ) {
switch ( V_197 ) {
case 8 : * ( V_167 * ) V_174 = V_208 ; break;
case 4 : * ( V_181 * ) V_174 = V_208 ; break;
case 2 : * ( V_182 * ) V_174 = V_208 ; break;
case 1 : * ( V_183 * ) V_174 = V_208 ; break;
}
} else {
switch ( V_197 ) {
case 4 : F_125 ( V_174 , V_208 ) ; break;
case 2 : F_126 ( V_174 , V_208 ) ; break;
case 1 : * ( V_183 * ) V_174 = V_208 ; break;
}
}
V_199 = F_120 ( & V_6 -> V_63 -> V_206 ) ;
V_160 = F_127 ( V_6 -> V_63 , V_207 , V_10 -> V_177 . V_201 ,
V_197 , & V_10 -> V_177 . V_174 ) ;
F_122 ( & V_6 -> V_63 -> V_206 , V_199 ) ;
if ( ! V_160 ) {
V_6 -> V_204 = 0 ;
return V_70 ;
}
return V_72 ;
}
int F_128 ( struct V_1 * V_6 , struct V_67 * V_10 )
{
int V_7 ;
T_2 V_209 ;
if ( V_6 -> V_210 )
F_129 ( V_211 , & V_6 -> V_212 , & V_209 ) ;
if ( V_6 -> V_204 ) {
if ( ! V_6 -> V_205 )
F_112 ( V_6 , V_10 ) ;
V_6 -> V_204 = 0 ;
} else if ( V_6 -> V_3 . V_213 ) {
if ( ! V_6 -> V_3 . V_214 )
F_111 ( V_6 , V_10 ) ;
V_6 -> V_3 . V_213 = 0 ;
} else if ( V_6 -> V_3 . V_215 ) {
V_167 * V_216 = V_10 -> V_217 . V_216 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
F_30 ( V_6 , V_18 , V_216 [ V_18 ] ) ;
V_6 -> V_3 . V_215 = 0 ;
} else if ( V_6 -> V_3 . V_218 ) {
int V_18 ;
F_30 ( V_6 , 3 , V_10 -> V_219 . V_160 ) ;
for ( V_18 = 0 ; V_18 < 9 ; ++ V_18 )
F_30 ( V_6 , 4 + V_18 , V_10 -> V_219 . args [ V_18 ] ) ;
V_6 -> V_3 . V_218 = 0 ;
#ifdef F_59
} else if ( V_6 -> V_3 . V_220 ) {
F_130 ( V_6 , V_10 -> V_221 . V_221 ) ;
V_6 -> V_3 . V_220 = 0 ;
#endif
}
V_7 = F_131 ( V_10 , V_6 ) ;
if ( V_6 -> V_210 )
F_129 ( V_211 , & V_209 , NULL ) ;
return V_7 ;
}
int F_132 ( struct V_1 * V_6 , struct V_222 * V_223 )
{
if ( V_223 -> V_223 == V_224 ) {
F_133 ( V_6 ) ;
return 0 ;
}
F_134 ( V_6 , V_223 ) ;
F_135 ( V_6 ) ;
return 0 ;
}
static int F_136 ( struct V_1 * V_6 ,
struct V_225 * V_226 )
{
int V_7 ;
if ( V_226 -> V_227 )
return - V_66 ;
switch ( V_226 -> V_226 ) {
case V_109 :
V_7 = 0 ;
V_6 -> V_3 . V_228 = true ;
break;
case V_101 :
V_7 = 0 ;
V_6 -> V_3 . V_62 = true ;
break;
case V_98 :
V_7 = 0 ;
if ( V_226 -> args [ 0 ] )
V_6 -> V_3 . V_229 |= V_230 ;
else
V_6 -> V_3 . V_229 &= ~ V_230 ;
break;
#ifdef F_59
case V_97 :
V_7 = 0 ;
V_6 -> V_3 . V_231 = true ;
break;
#endif
#if F_25 ( V_53 ) || F_25 ( V_111 )
case V_112 : {
struct V_232 V_233 ;
void T_3 * V_234 = ( void T_3 * ) ( V_235 ) V_226 -> args [ 0 ] ;
V_7 = - V_236 ;
if ( F_137 ( & V_233 , V_234 , sizeof( V_233 ) ) )
break;
V_7 = F_138 ( V_6 , & V_233 ) ;
break;
}
#endif
#ifdef F_61
case V_115 : {
struct V_237 V_238 ;
struct V_239 * V_240 ;
V_7 = - V_241 ;
V_238 = F_139 ( V_226 -> args [ 0 ] ) ;
if ( ! V_238 . V_133 )
break;
V_7 = - V_242 ;
V_240 = F_140 ( V_238 . V_133 ) ;
if ( V_240 )
V_7 = F_141 ( V_240 , V_6 , V_226 -> args [ 1 ] ) ;
F_142 ( V_238 ) ;
break;
}
#endif
#ifdef F_62
case V_120 : {
struct V_237 V_238 ;
struct V_239 * V_240 ;
V_7 = - V_241 ;
V_238 = F_139 ( V_226 -> args [ 0 ] ) ;
if ( ! V_238 . V_133 )
break;
V_7 = - V_242 ;
V_240 = F_140 ( V_238 . V_133 ) ;
if ( V_240 )
V_7 = F_143 ( V_240 , V_6 , V_226 -> args [ 1 ] ) ;
F_142 ( V_238 ) ;
break;
}
#endif
default:
V_7 = - V_66 ;
break;
}
if ( ! V_7 )
V_7 = F_31 ( V_6 ) ;
return V_7 ;
}
int F_144 ( struct V_1 * V_6 ,
struct V_243 * V_244 )
{
return - V_66 ;
}
int F_145 ( struct V_1 * V_6 ,
struct V_243 * V_244 )
{
return - V_66 ;
}
long F_146 ( struct V_133 * V_134 ,
unsigned int V_135 , unsigned long V_136 )
{
struct V_1 * V_6 = V_134 -> V_245 ;
void T_3 * V_246 = ( void T_3 * ) V_136 ;
long V_7 ;
switch ( V_135 ) {
case V_247 : {
struct V_222 V_223 ;
V_7 = - V_236 ;
if ( F_137 ( & V_223 , V_246 , sizeof( V_223 ) ) )
goto V_59;
V_7 = F_132 ( V_6 , & V_223 ) ;
goto V_59;
}
case V_248 :
{
struct V_225 V_226 ;
V_7 = - V_236 ;
if ( F_137 ( & V_226 , V_246 , sizeof( V_226 ) ) )
goto V_59;
V_7 = F_136 ( V_6 , & V_226 ) ;
break;
}
case V_249 :
case V_250 :
{
struct V_251 V_252 ;
V_7 = - V_236 ;
if ( F_137 ( & V_252 , V_246 , sizeof( V_252 ) ) )
goto V_59;
if ( V_135 == V_249 )
V_7 = F_147 ( V_6 , & V_252 ) ;
else
V_7 = F_148 ( V_6 , & V_252 ) ;
break;
}
#if F_25 ( V_53 ) || F_25 ( V_111 )
case V_253 : {
struct V_254 V_255 ;
V_7 = - V_236 ;
if ( F_137 ( & V_255 , V_246 , sizeof( V_255 ) ) )
goto V_59;
V_7 = F_149 ( V_6 , & V_255 ) ;
break;
}
#endif
default:
V_7 = - V_66 ;
}
V_59:
return V_7 ;
}
int F_150 ( struct V_1 * V_6 , struct V_256 * V_257 )
{
return V_258 ;
}
static int F_151 ( struct V_259 * V_260 )
{
V_181 V_261 = 0x60000000 ;
#ifdef F_33
V_181 V_262 = 0x44000022 ;
V_260 -> V_263 [ 0 ] = F_152 ( V_262 ) ;
V_260 -> V_263 [ 1 ] = F_152 ( V_261 ) ;
V_260 -> V_263 [ 2 ] = F_152 ( V_261 ) ;
V_260 -> V_263 [ 3 ] = F_152 ( V_261 ) ;
#else
V_181 V_264 = 0x3c000000 ;
V_181 V_265 = 0x60000000 ;
V_181 V_266 = 0x44000002 ;
V_181 V_267 = 0xffff ;
V_260 -> V_263 [ 0 ] = F_152 ( V_264 | ( ( V_268 >> 16 ) & V_267 ) ) ;
V_260 -> V_263 [ 1 ] = F_152 ( V_265 | ( V_268 & V_267 ) ) ;
V_260 -> V_263 [ 2 ] = F_152 ( V_266 ) ;
V_260 -> V_263 [ 3 ] = F_152 ( V_261 ) ;
#endif
V_260 -> V_227 = V_269 ;
return 0 ;
}
int F_153 ( struct V_63 * V_63 , struct V_270 * V_271 ,
bool V_272 )
{
if ( ! F_154 ( V_63 ) )
return - V_273 ;
V_271 -> V_274 = F_155 ( V_63 , V_275 ,
V_271 -> V_223 , V_271 -> V_276 ,
V_272 ) ;
return 0 ;
}
long F_156 ( struct V_133 * V_134 ,
unsigned int V_135 , unsigned long V_136 )
{
struct V_63 * V_63 T_1 = V_134 -> V_245 ;
void T_3 * V_246 = ( void T_3 * ) V_136 ;
long V_7 ;
switch ( V_135 ) {
case V_277 : {
struct V_259 V_260 ;
memset ( & V_260 , 0 , sizeof( V_260 ) ) ;
V_7 = F_151 ( & V_260 ) ;
if ( F_157 ( V_246 , & V_260 , sizeof( V_260 ) ) ) {
V_7 = - V_236 ;
goto V_59;
}
break;
}
#ifdef V_38
case V_278 : {
struct V_279 V_280 ;
V_7 = - V_236 ;
if ( F_137 ( & V_280 , V_246 , sizeof( V_280 ) ) )
goto V_59;
V_7 = F_158 ( V_63 , & V_280 ) ;
goto V_59;
}
case V_281 : {
struct V_282 V_283 ;
struct V_63 * V_63 = V_134 -> V_245 ;
memset ( & V_283 , 0 , sizeof( V_283 ) ) ;
V_7 = V_63 -> V_3 . V_83 -> V_284 ( V_63 , & V_283 ) ;
if ( V_7 >= 0 && F_157 ( V_246 , & V_283 , sizeof( V_283 ) ) )
V_7 = - V_236 ;
break;
}
case V_285 : {
struct V_63 * V_63 = V_134 -> V_245 ;
V_7 = F_159 ( V_63 , V_246 ) ;
break;
}
default: {
struct V_63 * V_63 = V_134 -> V_245 ;
V_7 = V_63 -> V_3 . V_83 -> V_286 ( V_134 , V_135 , V_136 ) ;
}
#else
default:
V_7 = - V_287 ;
#endif
}
V_59:
return V_7 ;
}
long F_160 ( void )
{
long V_288 ;
do {
V_288 = F_161 ( V_289 , V_290 ) ;
if ( V_288 >= V_291 ) {
F_162 ( L_4 , V_77 ) ;
return - V_292 ;
}
} while ( F_163 ( V_288 , V_289 ) );
return V_288 ;
}
void F_164 ( long V_288 )
{
F_165 ( V_288 , V_289 ) ;
}
void F_166 ( long V_288 )
{
F_29 ( V_288 , V_289 ) ;
}
void F_167 ( unsigned long V_293 )
{
V_291 = F_168 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_289 , 0 , sizeof( V_289 ) ) ;
}
int F_169 ( void * V_294 )
{
return 0 ;
}
void F_170 ( void )
{
}
