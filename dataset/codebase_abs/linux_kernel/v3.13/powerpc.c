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
int V_7 = 1 ;
F_4 ( ! F_5 () ) ;
while ( true ) {
if ( F_6 () ) {
F_7 () ;
F_8 () ;
F_9 () ;
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
F_7 () ;
F_13 ( V_6 ) ;
V_7 = F_14 ( V_6 ) ;
F_9 () ;
if ( V_7 > 0 )
continue;
break;
}
if ( F_15 ( V_6 ) ) {
continue;
}
#ifdef F_16
F_17 () ;
if ( F_18 () ) {
F_7 () ;
F_9 () ;
F_19 () ;
continue;
}
#endif
F_20 () ;
break;
}
return V_7 ;
}
int F_21 ( struct V_1 * V_6 )
{
int V_16 = F_22 ( V_6 , 11 ) ;
int V_7 ;
unsigned long T_1 V_17 = F_22 ( V_6 , 3 ) ;
unsigned long T_1 V_18 = F_22 ( V_6 , 4 ) ;
unsigned long T_1 V_19 = F_22 ( V_6 , 5 ) ;
unsigned long T_1 V_20 = F_22 ( V_6 , 6 ) ;
unsigned long V_21 = 0 ;
if ( ! ( V_6 -> V_3 . V_22 -> V_23 & V_24 ) ) {
V_17 &= 0xffffffff ;
V_18 &= 0xffffffff ;
V_19 &= 0xffffffff ;
V_20 &= 0xffffffff ;
}
switch ( V_16 ) {
case F_23 ( V_25 ) :
{
V_6 -> V_3 . V_26 = V_17 ;
V_6 -> V_3 . V_27 = V_18 ;
V_21 = V_28 | V_29 ;
V_7 = V_30 ;
break;
}
case F_23 ( V_31 ) :
V_7 = V_30 ;
#if F_24 ( V_32 ) || F_24 ( V_33 )
V_21 |= ( 1 << V_34 ) ;
#endif
break;
case F_25 ( V_35 ) :
V_7 = V_30 ;
F_26 ( V_6 ) ;
F_27 ( V_36 , & V_6 -> V_5 ) ;
break;
default:
V_7 = V_37 ;
break;
}
F_28 ( V_6 , 4 , V_21 ) ;
return V_7 ;
}
int F_29 ( struct V_1 * V_6 )
{
int V_7 = false ;
if ( ! V_6 -> V_3 . V_38 )
goto V_39;
if ( ( V_6 -> V_3 . V_40 != V_41 ) && V_6 -> V_3 . V_42 )
goto V_39;
if ( ! V_6 -> V_3 . V_42 && F_30 ( V_6 -> V_43 ) )
goto V_39;
#ifdef F_31
if ( ! F_32 ( V_44 ) )
goto V_39;
#endif
V_7 = true ;
V_39:
V_6 -> V_3 . V_45 = V_7 ;
return V_7 ? 0 : - V_46 ;
}
int F_33 ( struct V_47 * V_10 , struct V_1 * V_6 )
{
enum V_48 V_49 ;
int V_7 ;
V_49 = F_34 ( V_10 , V_6 ) ;
switch ( V_49 ) {
case V_50 :
V_7 = V_51 ;
break;
case V_52 :
V_10 -> V_11 = V_53 ;
V_7 = V_54 ;
break;
case V_55 :
F_35 ( V_56 L_1 , V_57 ,
F_36 ( V_6 ) ) ;
V_7 = V_58 ;
break;
default:
F_37 ( 1 ) ;
V_7 = V_59 ;
}
return V_7 ;
}
int F_38 ( void * V_60 )
{
return 0 ;
}
void F_39 ( void * V_60 )
{
}
int F_40 ( void )
{
return 0 ;
}
void F_41 ( void )
{
}
void F_42 ( void * V_61 )
{
* ( int * ) V_61 = F_43 () ;
}
int F_44 ( struct V_43 * V_43 , unsigned long type )
{
struct V_62 * V_63 = NULL ;
if ( type == 0 ) {
if ( V_64 )
V_63 = V_64 ;
else
V_63 = V_65 ;
if ( ! V_63 )
goto V_66;
} else if ( type == V_67 ) {
if ( ! V_64 )
goto V_66;
V_63 = V_64 ;
} else if ( type == V_68 ) {
if ( ! V_65 )
goto V_66;
V_63 = V_65 ;
} else
goto V_66;
if ( V_63 -> V_69 && ! F_45 ( V_63 -> V_69 ) )
return - V_70 ;
V_43 -> V_3 . V_63 = V_63 ;
return F_46 ( V_43 ) ;
V_66:
return - V_46 ;
}
void F_47 ( struct V_43 * V_43 )
{
unsigned int V_71 ;
struct V_1 * V_6 ;
F_48 (i, vcpu, kvm)
F_49 ( V_6 ) ;
F_50 ( & V_43 -> V_72 ) ;
for ( V_71 = 0 ; V_71 < F_51 ( & V_43 -> V_73 ) ; V_71 ++ )
V_43 -> V_74 [ V_71 ] = NULL ;
F_52 ( & V_43 -> V_73 , 0 ) ;
F_53 ( V_43 ) ;
F_54 ( & V_43 -> V_72 ) ;
F_55 ( V_43 -> V_3 . V_63 -> V_69 ) ;
}
void F_56 ( struct V_43 * V_43 )
{
}
int F_57 ( long V_75 )
{
int V_7 ;
int V_76 = V_64 ? 1 : 0 ;
switch ( V_75 ) {
#ifdef F_58
case V_77 :
case V_78 :
case V_79 :
#else
case V_80 :
case V_81 :
case V_82 :
#endif
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_7 = 1 ;
break;
case V_89 :
case V_90 :
case V_91 :
#if F_24 ( V_33 ) || F_24 ( V_92 )
case V_93 :
#endif
V_7 = ! V_76 ;
break;
#ifdef F_59
case V_94 :
V_7 = V_95 ;
break;
#endif
#ifdef F_60
case V_96 :
V_7 = 1 ;
break;
#endif
#ifdef F_61
case V_97 :
case V_98 :
case V_99 :
#ifdef F_62
case V_100 :
#endif
V_7 = 1 ;
break;
#endif
#ifdef F_63
case V_101 :
if ( V_76 )
V_7 = V_102 ;
else
V_7 = 0 ;
break;
case V_103 :
V_7 = V_76 ;
if ( V_7 && F_32 ( V_104 ) )
V_7 = 2 ;
break;
#endif
case V_105 :
#ifdef F_63
if ( V_76 )
V_7 = F_32 ( V_106 ) ? 1 : 0 ;
else
V_7 = 0 ;
#elif F_24 ( V_107 )
V_7 = 1 ;
#else
V_7 = 0 ;
#endif
break;
#ifdef F_63
case V_108 :
V_7 = V_76 ;
break;
#endif
case V_109 :
if ( V_76 )
V_7 = F_64 () ;
else
V_7 = F_65 () ;
break;
case V_110 :
V_7 = V_111 ;
break;
#ifdef F_61
case V_112 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_66 ( struct V_113 * V_114 ,
unsigned int V_115 , unsigned long V_116 )
{
return - V_46 ;
}
void F_67 ( struct V_43 * V_43 , struct V_117 * free ,
struct V_117 * V_118 )
{
F_68 ( V_43 , free , V_118 ) ;
}
int F_69 ( struct V_43 * V_43 , struct V_117 * V_119 ,
unsigned long V_120 )
{
return F_70 ( V_43 , V_119 , V_120 ) ;
}
void F_71 ( struct V_43 * V_43 )
{
}
int F_72 ( struct V_43 * V_43 ,
struct V_117 * V_121 ,
struct V_122 * V_123 ,
enum V_124 V_125 )
{
return F_73 ( V_43 , V_121 , V_123 ) ;
}
void F_74 ( struct V_43 * V_43 ,
struct V_122 * V_123 ,
const struct V_117 * V_126 ,
enum V_124 V_125 )
{
F_75 ( V_43 , V_123 , V_126 ) ;
}
void F_76 ( struct V_43 * V_43 )
{
}
void F_77 ( struct V_43 * V_43 ,
struct V_117 * V_119 )
{
F_78 ( V_43 , V_119 ) ;
}
struct V_1 * F_79 ( struct V_43 * V_43 , unsigned int V_127 )
{
struct V_1 * V_6 ;
V_6 = F_80 ( V_43 , V_127 ) ;
if ( ! F_81 ( V_6 ) ) {
V_6 -> V_3 . V_128 = & V_6 -> V_129 ;
F_82 ( V_6 , V_127 ) ;
}
return V_6 ;
}
int F_83 ( struct V_1 * V_6 )
{
return 0 ;
}
void F_49 ( struct V_1 * V_6 )
{
F_84 ( & V_6 -> V_3 . V_130 ) ;
F_85 ( & V_6 -> V_3 . V_131 ) ;
F_86 ( V_6 ) ;
switch ( V_6 -> V_3 . V_132 ) {
case V_133 :
F_87 ( V_6 -> V_3 . V_134 , V_6 ) ;
break;
case V_135 :
F_88 ( V_6 ) ;
break;
}
F_89 ( V_6 ) ;
}
void F_90 ( struct V_1 * V_6 )
{
F_49 ( V_6 ) ;
}
int F_91 ( struct V_1 * V_6 )
{
return F_92 ( V_6 ) ;
}
enum V_136 F_93 ( struct V_137 * V_138 )
{
struct V_1 * V_6 ;
V_6 = F_94 ( V_138 , struct V_1 , V_3 . V_130 ) ;
F_95 ( & V_6 -> V_3 . V_131 ) ;
return V_139 ;
}
int F_96 ( struct V_1 * V_6 )
{
int V_140 ;
F_97 ( & V_6 -> V_3 . V_130 , V_141 , V_142 ) ;
F_98 ( & V_6 -> V_3 . V_131 , V_143 , ( V_144 ) V_6 ) ;
V_6 -> V_3 . V_130 . V_145 = F_93 ;
V_6 -> V_3 . V_146 = ~ ( V_147 ) 0 ;
#ifdef F_99
F_100 ( & V_6 -> V_3 . V_148 ) ;
#endif
V_140 = F_101 ( V_6 ) ;
return V_140 ;
}
void F_102 ( struct V_1 * V_6 )
{
F_103 ( V_6 ) ;
F_104 ( V_6 ) ;
}
void F_105 ( struct V_1 * V_6 , int V_149 )
{
#ifdef F_58
F_106 ( V_150 , V_6 -> V_3 . V_151 ) ;
#endif
F_107 ( V_6 , V_149 ) ;
}
void F_108 ( struct V_1 * V_6 )
{
F_109 ( V_6 ) ;
#ifdef F_58
V_6 -> V_3 . V_151 = F_110 ( V_150 ) ;
#endif
}
static void F_111 ( struct V_1 * V_6 ,
struct V_47 * V_10 )
{
F_28 ( V_6 , V_6 -> V_3 . V_152 , V_10 -> V_153 . V_154 ) ;
}
static void F_112 ( struct V_1 * V_6 ,
struct V_47 * V_10 )
{
V_147 V_155 ( V_156 ) ;
if ( V_10 -> V_157 . V_158 > sizeof( V_156 ) ) {
F_35 ( V_159 L_2 , V_10 -> V_157 . V_158 ) ;
return;
}
if ( V_6 -> V_3 . V_160 ) {
switch ( V_10 -> V_157 . V_158 ) {
case 8 : V_156 = * ( V_147 * ) V_10 -> V_157 . V_154 ; break;
case 4 : V_156 = * ( V_161 * ) V_10 -> V_157 . V_154 ; break;
case 2 : V_156 = * ( V_162 * ) V_10 -> V_157 . V_154 ; break;
case 1 : V_156 = * ( V_163 * ) V_10 -> V_157 . V_154 ; break;
}
} else {
switch ( V_10 -> V_157 . V_158 ) {
case 4 : V_156 = F_113 ( ( V_161 * ) V_10 -> V_157 . V_154 ) ; break;
case 2 : V_156 = F_114 ( ( V_162 * ) V_10 -> V_157 . V_154 ) ; break;
case 1 : V_156 = * ( V_163 * ) V_10 -> V_157 . V_154 ; break;
}
}
if ( V_6 -> V_3 . V_164 ) {
switch ( V_10 -> V_157 . V_158 ) {
#ifdef F_16
case 4 :
V_156 = ( V_165 ) ( V_166 ) V_156 ;
break;
#endif
case 2 :
V_156 = ( V_165 ) ( V_167 ) V_156 ;
break;
case 1 :
V_156 = ( V_165 ) ( V_168 ) V_156 ;
break;
}
}
F_28 ( V_6 , V_6 -> V_3 . V_152 , V_156 ) ;
switch ( V_6 -> V_3 . V_152 & V_169 ) {
case V_170 :
F_28 ( V_6 , V_6 -> V_3 . V_152 , V_156 ) ;
break;
case V_171 :
V_6 -> V_3 . V_172 [ V_6 -> V_3 . V_152 & V_173 ] = V_156 ;
break;
#ifdef V_32
case V_174 :
V_6 -> V_3 . V_175 [ V_6 -> V_3 . V_152 & V_173 ] = V_156 ;
break;
case V_176 :
V_6 -> V_3 . V_172 [ V_6 -> V_3 . V_152 & V_173 ] = V_156 ;
V_6 -> V_3 . V_175 [ V_6 -> V_3 . V_152 & V_173 ] = V_156 ;
break;
#endif
default:
F_115 () ;
}
}
int F_116 ( struct V_47 * V_10 , struct V_1 * V_6 ,
unsigned int V_177 , unsigned int V_178 , int V_179 )
{
int V_180 , V_140 ;
if ( V_178 > sizeof( V_10 -> V_157 . V_154 ) ) {
F_35 ( V_159 L_3 , V_57 ,
V_10 -> V_157 . V_158 ) ;
}
V_10 -> V_157 . V_181 = V_6 -> V_3 . V_182 ;
V_10 -> V_157 . V_158 = V_178 ;
V_10 -> V_157 . V_183 = 0 ;
V_6 -> V_3 . V_152 = V_177 ;
V_6 -> V_3 . V_160 = V_179 ;
V_6 -> V_184 = 1 ;
V_6 -> V_185 = 0 ;
V_6 -> V_3 . V_164 = 0 ;
V_180 = F_117 ( & V_6 -> V_43 -> V_186 ) ;
V_140 = F_118 ( V_6 -> V_43 , V_187 , V_10 -> V_157 . V_181 ,
V_178 , & V_10 -> V_157 . V_154 ) ;
F_119 ( & V_6 -> V_43 -> V_186 , V_180 ) ;
if ( ! V_140 ) {
F_112 ( V_6 , V_10 ) ;
V_6 -> V_184 = 0 ;
return V_50 ;
}
return V_52 ;
}
int F_120 ( struct V_47 * V_10 , struct V_1 * V_6 ,
unsigned int V_177 , unsigned int V_178 , int V_179 )
{
int V_7 ;
V_6 -> V_3 . V_164 = 1 ;
V_7 = F_116 ( V_10 , V_6 , V_177 , V_178 , V_179 ) ;
return V_7 ;
}
int F_121 ( struct V_47 * V_10 , struct V_1 * V_6 ,
V_147 V_188 , unsigned int V_178 , int V_179 )
{
void * V_154 = V_10 -> V_157 . V_154 ;
int V_180 , V_140 ;
if ( V_178 > sizeof( V_10 -> V_157 . V_154 ) ) {
F_35 ( V_159 L_3 , V_57 ,
V_10 -> V_157 . V_158 ) ;
}
V_10 -> V_157 . V_181 = V_6 -> V_3 . V_182 ;
V_10 -> V_157 . V_158 = V_178 ;
V_10 -> V_157 . V_183 = 1 ;
V_6 -> V_184 = 1 ;
V_6 -> V_185 = 1 ;
if ( V_179 ) {
switch ( V_178 ) {
case 8 : * ( V_147 * ) V_154 = V_188 ; break;
case 4 : * ( V_161 * ) V_154 = V_188 ; break;
case 2 : * ( V_162 * ) V_154 = V_188 ; break;
case 1 : * ( V_163 * ) V_154 = V_188 ; break;
}
} else {
switch ( V_178 ) {
case 4 : F_122 ( V_154 , V_188 ) ; break;
case 2 : F_123 ( V_154 , V_188 ) ; break;
case 1 : * ( V_163 * ) V_154 = V_188 ; break;
}
}
V_180 = F_117 ( & V_6 -> V_43 -> V_186 ) ;
V_140 = F_124 ( V_6 -> V_43 , V_187 , V_10 -> V_157 . V_181 ,
V_178 , & V_10 -> V_157 . V_154 ) ;
F_119 ( & V_6 -> V_43 -> V_186 , V_180 ) ;
if ( ! V_140 ) {
V_6 -> V_184 = 0 ;
return V_50 ;
}
return V_52 ;
}
int F_125 ( struct V_1 * V_6 , struct V_47 * V_10 )
{
int V_7 ;
T_2 V_189 ;
if ( V_6 -> V_190 )
F_126 ( V_191 , & V_6 -> V_192 , & V_189 ) ;
if ( V_6 -> V_184 ) {
if ( ! V_6 -> V_185 )
F_112 ( V_6 , V_10 ) ;
V_6 -> V_184 = 0 ;
} else if ( V_6 -> V_3 . V_193 ) {
if ( ! V_6 -> V_3 . V_194 )
F_111 ( V_6 , V_10 ) ;
V_6 -> V_3 . V_193 = 0 ;
} else if ( V_6 -> V_3 . V_195 ) {
V_147 * V_196 = V_10 -> V_197 . V_196 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < 32 ; V_71 ++ )
F_28 ( V_6 , V_71 , V_196 [ V_71 ] ) ;
V_6 -> V_3 . V_195 = 0 ;
} else if ( V_6 -> V_3 . V_198 ) {
int V_71 ;
F_28 ( V_6 , 3 , V_10 -> V_199 . V_140 ) ;
for ( V_71 = 0 ; V_71 < 9 ; ++ V_71 )
F_28 ( V_6 , 4 + V_71 , V_10 -> V_199 . args [ V_71 ] ) ;
V_6 -> V_3 . V_198 = 0 ;
#ifdef F_58
} else if ( V_6 -> V_3 . V_200 ) {
F_127 ( V_6 , V_10 -> V_201 . V_201 ) ;
V_6 -> V_3 . V_200 = 0 ;
#endif
}
V_7 = F_128 ( V_10 , V_6 ) ;
if ( V_6 -> V_190 )
F_126 ( V_191 , & V_189 , NULL ) ;
return V_7 ;
}
int F_129 ( struct V_1 * V_6 , struct V_202 * V_203 )
{
if ( V_203 -> V_203 == V_204 ) {
F_130 ( V_6 ) ;
return 0 ;
}
F_131 ( V_6 , V_203 ) ;
F_132 ( V_6 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_6 ,
struct V_205 * V_206 )
{
int V_7 ;
if ( V_206 -> V_207 )
return - V_46 ;
switch ( V_206 -> V_206 ) {
case V_90 :
V_7 = 0 ;
V_6 -> V_3 . V_208 = true ;
break;
case V_82 :
V_7 = 0 ;
V_6 -> V_3 . V_42 = true ;
break;
case V_79 :
V_7 = 0 ;
if ( V_206 -> args [ 0 ] )
V_6 -> V_3 . V_209 |= V_210 ;
else
V_6 -> V_3 . V_209 &= ~ V_210 ;
break;
#ifdef F_58
case V_78 :
V_7 = 0 ;
V_6 -> V_3 . V_211 = true ;
break;
#endif
#if F_24 ( V_33 ) || F_24 ( V_92 )
case V_93 : {
struct V_212 V_213 ;
void T_3 * V_214 = ( void T_3 * ) ( V_215 ) V_206 -> args [ 0 ] ;
V_7 = - V_216 ;
if ( F_134 ( & V_213 , V_214 , sizeof( V_213 ) ) )
break;
V_7 = F_135 ( V_6 , & V_213 ) ;
break;
}
#endif
#ifdef F_60
case V_96 : {
struct V_217 V_218 ;
struct V_219 * V_220 ;
V_7 = - V_221 ;
V_218 = F_136 ( V_206 -> args [ 0 ] ) ;
if ( ! V_218 . V_113 )
break;
V_7 = - V_222 ;
V_220 = F_137 ( V_218 . V_113 ) ;
if ( V_220 )
V_7 = F_138 ( V_220 , V_6 , V_206 -> args [ 1 ] ) ;
F_139 ( V_218 ) ;
break;
}
#endif
#ifdef F_62
case V_100 : {
struct V_217 V_218 ;
struct V_219 * V_220 ;
V_7 = - V_221 ;
V_218 = F_136 ( V_206 -> args [ 0 ] ) ;
if ( ! V_218 . V_113 )
break;
V_7 = - V_222 ;
V_220 = F_137 ( V_218 . V_113 ) ;
if ( V_220 )
V_7 = F_140 ( V_220 , V_6 , V_206 -> args [ 1 ] ) ;
F_139 ( V_218 ) ;
break;
}
#endif
default:
V_7 = - V_46 ;
break;
}
if ( ! V_7 )
V_7 = F_29 ( V_6 ) ;
return V_7 ;
}
int F_141 ( struct V_1 * V_6 ,
struct V_223 * V_224 )
{
return - V_46 ;
}
int F_142 ( struct V_1 * V_6 ,
struct V_223 * V_224 )
{
return - V_46 ;
}
long F_143 ( struct V_113 * V_114 ,
unsigned int V_115 , unsigned long V_116 )
{
struct V_1 * V_6 = V_114 -> V_225 ;
void T_3 * V_226 = ( void T_3 * ) V_116 ;
long V_7 ;
switch ( V_115 ) {
case V_227 : {
struct V_202 V_203 ;
V_7 = - V_216 ;
if ( F_134 ( & V_203 , V_226 , sizeof( V_203 ) ) )
goto V_39;
V_7 = F_129 ( V_6 , & V_203 ) ;
goto V_39;
}
case V_228 :
{
struct V_205 V_206 ;
V_7 = - V_216 ;
if ( F_134 ( & V_206 , V_226 , sizeof( V_206 ) ) )
goto V_39;
V_7 = F_133 ( V_6 , & V_206 ) ;
break;
}
case V_229 :
case V_230 :
{
struct V_231 V_232 ;
V_7 = - V_216 ;
if ( F_134 ( & V_232 , V_226 , sizeof( V_232 ) ) )
goto V_39;
if ( V_115 == V_229 )
V_7 = F_144 ( V_6 , & V_232 ) ;
else
V_7 = F_145 ( V_6 , & V_232 ) ;
break;
}
#if F_24 ( V_33 ) || F_24 ( V_92 )
case V_233 : {
struct V_234 V_235 ;
V_7 = - V_216 ;
if ( F_134 ( & V_235 , V_226 , sizeof( V_235 ) ) )
goto V_39;
V_7 = F_146 ( V_6 , & V_235 ) ;
break;
}
#endif
default:
V_7 = - V_46 ;
}
V_39:
return V_7 ;
}
int F_147 ( struct V_1 * V_6 , struct V_236 * V_237 )
{
return V_238 ;
}
static int F_148 ( struct V_239 * V_240 )
{
V_161 V_241 = 0x60000000 ;
#ifdef F_31
V_161 V_242 = 0x44000022 ;
V_240 -> V_243 [ 0 ] = V_242 ;
V_240 -> V_243 [ 1 ] = V_241 ;
V_240 -> V_243 [ 2 ] = V_241 ;
V_240 -> V_243 [ 3 ] = V_241 ;
#else
V_161 V_244 = 0x3c000000 ;
V_161 V_245 = 0x60000000 ;
V_161 V_246 = 0x44000002 ;
V_161 V_247 = 0xffff ;
V_240 -> V_243 [ 0 ] = V_244 | ( ( V_248 >> 16 ) & V_247 ) ;
V_240 -> V_243 [ 1 ] = V_245 | ( V_248 & V_247 ) ;
V_240 -> V_243 [ 2 ] = V_246 ;
V_240 -> V_243 [ 3 ] = V_241 ;
#endif
V_240 -> V_207 = V_249 ;
return 0 ;
}
int F_149 ( struct V_43 * V_43 , struct V_250 * V_251 ,
bool V_252 )
{
if ( ! F_150 ( V_43 ) )
return - V_253 ;
V_251 -> V_254 = F_151 ( V_43 , V_255 ,
V_251 -> V_203 , V_251 -> V_256 ,
V_252 ) ;
return 0 ;
}
long F_152 ( struct V_113 * V_114 ,
unsigned int V_115 , unsigned long V_116 )
{
struct V_43 * V_43 T_1 = V_114 -> V_225 ;
void T_3 * V_226 = ( void T_3 * ) V_116 ;
long V_7 ;
switch ( V_115 ) {
case V_257 : {
struct V_239 V_240 ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_7 = F_148 ( & V_240 ) ;
if ( F_153 ( V_226 , & V_240 , sizeof( V_240 ) ) ) {
V_7 = - V_216 ;
goto V_39;
}
break;
}
#ifdef F_61
case V_258 : {
struct V_259 V_260 ;
V_7 = - V_216 ;
if ( F_134 ( & V_260 , V_226 , sizeof( V_260 ) ) )
goto V_39;
V_7 = F_154 ( V_43 , & V_260 ) ;
goto V_39;
}
case V_261 : {
struct V_262 V_263 ;
struct V_43 * V_43 = V_114 -> V_225 ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_7 = V_43 -> V_3 . V_63 -> V_264 ( V_43 , & V_263 ) ;
if ( V_7 >= 0 && F_153 ( V_226 , & V_263 , sizeof( V_263 ) ) )
V_7 = - V_216 ;
break;
}
case V_265 : {
struct V_43 * V_43 = V_114 -> V_225 ;
V_7 = F_155 ( V_43 , V_226 ) ;
break;
}
default: {
struct V_43 * V_43 = V_114 -> V_225 ;
V_7 = V_43 -> V_3 . V_63 -> V_266 ( V_114 , V_115 , V_116 ) ;
}
#else
default:
V_7 = - V_267 ;
#endif
}
V_39:
return V_7 ;
}
long F_156 ( void )
{
long V_268 ;
do {
V_268 = F_157 ( V_269 , V_270 ) ;
if ( V_268 >= V_271 ) {
F_158 ( L_4 , V_57 ) ;
return - V_272 ;
}
} while ( F_159 ( V_268 , V_269 ) );
return V_268 ;
}
void F_160 ( long V_268 )
{
F_161 ( V_268 , V_269 ) ;
}
void F_162 ( long V_268 )
{
F_27 ( V_268 , V_269 ) ;
}
void F_163 ( unsigned long V_273 )
{
V_271 = F_164 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_269 , 0 , sizeof( V_269 ) ) ;
}
int F_165 ( void * V_274 )
{
return 0 ;
}
void F_166 ( void )
{
}
