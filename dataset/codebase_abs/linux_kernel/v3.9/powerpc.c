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
F_20 () ;
#endif
F_21 () ;
break;
}
return V_7 ;
}
int F_22 ( struct V_1 * V_6 )
{
int V_16 = F_23 ( V_6 , 11 ) ;
int V_7 ;
unsigned long T_1 V_17 = F_23 ( V_6 , 3 ) ;
unsigned long T_1 V_18 = F_23 ( V_6 , 4 ) ;
unsigned long T_1 V_19 = F_23 ( V_6 , 5 ) ;
unsigned long T_1 V_20 = F_23 ( V_6 , 6 ) ;
unsigned long V_21 = 0 ;
if ( ! ( V_6 -> V_3 . V_22 -> V_23 & V_24 ) ) {
V_17 &= 0xffffffff ;
V_18 &= 0xffffffff ;
V_19 &= 0xffffffff ;
V_20 &= 0xffffffff ;
}
switch ( V_16 ) {
case F_24 ( V_25 ) :
{
V_6 -> V_3 . V_26 = V_17 ;
V_6 -> V_3 . V_27 = V_18 ;
V_21 = V_28 | V_29 ;
V_7 = V_30 ;
break;
}
case F_24 ( V_31 ) :
V_7 = V_30 ;
#if F_25 ( V_32 ) || F_25 ( V_33 )
V_21 |= ( 1 << V_34 ) ;
#endif
break;
case F_26 ( V_35 ) :
V_7 = V_30 ;
F_27 ( V_6 ) ;
F_28 ( V_36 , & V_6 -> V_5 ) ;
break;
default:
V_7 = V_37 ;
break;
}
F_29 ( V_6 , 4 , V_21 ) ;
return V_7 ;
}
int F_30 ( struct V_1 * V_6 )
{
int V_7 = false ;
if ( ! V_6 -> V_3 . V_38 )
goto V_39;
if ( ( V_6 -> V_3 . V_40 != V_41 ) && V_6 -> V_3 . V_42 )
goto V_39;
#ifdef F_31
if ( ! V_6 -> V_3 . V_42 )
goto V_39;
#endif
#ifdef F_32
if ( ! F_33 ( V_43 ) )
goto V_39;
#endif
V_7 = true ;
V_39:
V_6 -> V_3 . V_44 = V_7 ;
return V_7 ? 0 : - V_45 ;
}
int F_34 ( struct V_46 * V_10 , struct V_1 * V_6 )
{
enum V_47 V_48 ;
int V_7 ;
V_48 = F_35 ( V_10 , V_6 ) ;
switch ( V_48 ) {
case V_49 :
V_7 = V_50 ;
break;
case V_51 :
V_10 -> V_11 = V_52 ;
V_7 = V_53 ;
break;
case V_54 :
F_36 ( V_55 L_1 , V_56 ,
F_37 ( V_6 ) ) ;
V_7 = V_57 ;
break;
default:
F_38 ( 1 ) ;
V_7 = V_58 ;
}
return V_7 ;
}
int F_39 ( void * V_59 )
{
return 0 ;
}
void F_40 ( void * V_59 )
{
}
int F_41 ( void )
{
return 0 ;
}
void F_42 ( void )
{
}
void F_43 ( void * V_60 )
{
* ( int * ) V_60 = F_44 () ;
}
int F_45 ( struct V_61 * V_61 , unsigned long type )
{
if ( type )
return - V_45 ;
return F_46 ( V_61 ) ;
}
void F_47 ( struct V_61 * V_61 )
{
unsigned int V_62 ;
struct V_1 * V_6 ;
F_48 (i, vcpu, kvm)
F_49 ( V_6 ) ;
F_50 ( & V_61 -> V_63 ) ;
for ( V_62 = 0 ; V_62 < F_51 ( & V_61 -> V_64 ) ; V_62 ++ )
V_61 -> V_65 [ V_62 ] = NULL ;
F_52 ( & V_61 -> V_64 , 0 ) ;
F_53 ( V_61 ) ;
F_54 ( & V_61 -> V_63 ) ;
}
void F_55 ( struct V_61 * V_61 )
{
}
int F_56 ( long V_66 )
{
int V_7 ;
switch ( V_66 ) {
#ifdef F_57
case V_67 :
case V_68 :
case V_69 :
#else
case V_70 :
case V_71 :
case V_72 :
#endif
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_7 = 1 ;
break;
#ifndef F_31
case V_78 :
case V_79 :
case V_80 :
#if F_25 ( V_33 ) || F_25 ( V_81 )
case V_82 :
#endif
V_7 = 1 ;
break;
case V_83 :
V_7 = V_84 ;
break;
#endif
#ifdef F_58
case V_85 :
case V_86 :
V_7 = 1 ;
break;
#endif
#ifdef F_31
case V_87 :
V_7 = V_88 ;
break;
case V_89 :
V_7 = 1 ;
if ( F_33 ( V_90 ) )
V_7 = 2 ;
break;
#endif
case V_91 :
#ifdef F_31
V_7 = F_33 ( V_92 ) ? 1 : 0 ;
#elif F_25 ( V_93 )
V_7 = 1 ;
#else
V_7 = 0 ;
break;
#endif
#ifdef F_31
case V_94 :
V_7 = 1 ;
break;
#endif
break;
case V_95 :
#ifdef F_31
V_7 = F_59 () ;
#else
V_7 = F_60 () ;
#endif
break;
case V_96 :
V_7 = V_97 ;
break;
#ifdef F_58
case V_98 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_61 ( struct V_99 * V_100 ,
unsigned int V_101 , unsigned long V_102 )
{
return - V_45 ;
}
void F_62 ( struct V_103 * free ,
struct V_103 * V_104 )
{
F_63 ( free , V_104 ) ;
}
int F_64 ( struct V_103 * V_105 , unsigned long V_106 )
{
return F_65 ( V_105 , V_106 ) ;
}
int F_66 ( struct V_61 * V_61 ,
struct V_103 * V_107 ,
struct V_103 V_108 ,
struct V_109 * V_110 ,
bool V_111 )
{
return F_67 ( V_61 , V_107 , V_110 ) ;
}
void F_68 ( struct V_61 * V_61 ,
struct V_109 * V_110 ,
struct V_103 V_108 ,
bool V_111 )
{
F_69 ( V_61 , V_110 , V_108 ) ;
}
void F_70 ( struct V_61 * V_61 )
{
}
void F_71 ( struct V_61 * V_61 ,
struct V_103 * V_105 )
{
F_72 ( V_61 , V_105 ) ;
}
struct V_1 * F_73 ( struct V_61 * V_61 , unsigned int V_112 )
{
struct V_1 * V_6 ;
V_6 = F_74 ( V_61 , V_112 ) ;
if ( ! F_75 ( V_6 ) ) {
V_6 -> V_3 . V_113 = & V_6 -> V_114 ;
F_76 ( V_6 , V_112 ) ;
}
return V_6 ;
}
int F_77 ( struct V_1 * V_6 )
{
return 0 ;
}
void F_49 ( struct V_1 * V_6 )
{
F_78 ( & V_6 -> V_3 . V_115 ) ;
F_79 ( & V_6 -> V_3 . V_116 ) ;
F_80 ( V_6 ) ;
F_81 ( V_6 ) ;
}
void F_82 ( struct V_1 * V_6 )
{
F_49 ( V_6 ) ;
}
int F_83 ( struct V_1 * V_6 )
{
return F_84 ( V_6 ) ;
}
enum V_117 F_85 ( struct V_118 * V_119 )
{
struct V_1 * V_6 ;
V_6 = F_86 ( V_119 , struct V_1 , V_3 . V_115 ) ;
F_87 ( & V_6 -> V_3 . V_116 ) ;
return V_120 ;
}
int F_88 ( struct V_1 * V_6 )
{
int V_121 ;
F_89 ( & V_6 -> V_3 . V_115 , V_122 , V_123 ) ;
F_90 ( & V_6 -> V_3 . V_116 , V_124 , ( V_125 ) V_6 ) ;
V_6 -> V_3 . V_115 . V_126 = F_85 ;
V_6 -> V_3 . V_127 = ~ ( V_128 ) 0 ;
#ifdef F_91
F_92 ( & V_6 -> V_3 . V_129 ) ;
#endif
V_121 = F_93 ( V_6 ) ;
return V_121 ;
}
void F_94 ( struct V_1 * V_6 )
{
F_95 ( V_6 ) ;
F_96 ( V_6 ) ;
}
void F_97 ( struct V_1 * V_6 , int V_130 )
{
#ifdef F_57
F_98 ( V_131 , V_6 -> V_3 . V_132 ) ;
#endif
F_99 ( V_6 , V_130 ) ;
}
void F_100 ( struct V_1 * V_6 )
{
F_101 ( V_6 ) ;
#ifdef F_57
V_6 -> V_3 . V_132 = F_102 ( V_131 ) ;
#endif
}
int F_103 ( struct V_1 * V_6 ,
struct V_133 * V_134 )
{
return - V_45 ;
}
static void F_104 ( struct V_1 * V_6 ,
struct V_46 * V_10 )
{
F_29 ( V_6 , V_6 -> V_3 . V_135 , V_10 -> V_136 . V_137 ) ;
}
static void F_105 ( struct V_1 * V_6 ,
struct V_46 * V_10 )
{
V_128 V_138 ( V_139 ) ;
if ( V_10 -> V_140 . V_141 > sizeof( V_139 ) ) {
F_36 ( V_142 L_2 , V_10 -> V_140 . V_141 ) ;
return;
}
if ( V_6 -> V_3 . V_143 ) {
switch ( V_10 -> V_140 . V_141 ) {
case 8 : V_139 = * ( V_128 * ) V_10 -> V_140 . V_137 ; break;
case 4 : V_139 = * ( V_144 * ) V_10 -> V_140 . V_137 ; break;
case 2 : V_139 = * ( V_145 * ) V_10 -> V_140 . V_137 ; break;
case 1 : V_139 = * ( V_146 * ) V_10 -> V_140 . V_137 ; break;
}
} else {
switch ( V_10 -> V_140 . V_141 ) {
case 4 : V_139 = F_106 ( ( V_144 * ) V_10 -> V_140 . V_137 ) ; break;
case 2 : V_139 = F_107 ( ( V_145 * ) V_10 -> V_140 . V_137 ) ; break;
case 1 : V_139 = * ( V_146 * ) V_10 -> V_140 . V_137 ; break;
}
}
if ( V_6 -> V_3 . V_147 ) {
switch ( V_10 -> V_140 . V_141 ) {
#ifdef F_16
case 4 :
V_139 = ( V_148 ) ( V_149 ) V_139 ;
break;
#endif
case 2 :
V_139 = ( V_148 ) ( V_150 ) V_139 ;
break;
case 1 :
V_139 = ( V_148 ) ( V_151 ) V_139 ;
break;
}
}
F_29 ( V_6 , V_6 -> V_3 . V_135 , V_139 ) ;
switch ( V_6 -> V_3 . V_135 & V_152 ) {
case V_153 :
F_29 ( V_6 , V_6 -> V_3 . V_135 , V_139 ) ;
break;
case V_154 :
V_6 -> V_3 . V_155 [ V_6 -> V_3 . V_135 & V_156 ] = V_139 ;
break;
#ifdef V_32
case V_157 :
V_6 -> V_3 . V_158 [ V_6 -> V_3 . V_135 & V_156 ] = V_139 ;
break;
case V_159 :
V_6 -> V_3 . V_155 [ V_6 -> V_3 . V_135 & V_156 ] = V_139 ;
V_6 -> V_3 . V_158 [ V_6 -> V_3 . V_135 & V_156 ] = V_139 ;
break;
#endif
default:
F_108 () ;
}
}
int F_109 ( struct V_46 * V_10 , struct V_1 * V_6 ,
unsigned int V_160 , unsigned int V_161 , int V_162 )
{
if ( V_161 > sizeof( V_10 -> V_140 . V_137 ) ) {
F_36 ( V_142 L_3 , V_56 ,
V_10 -> V_140 . V_141 ) ;
}
V_10 -> V_140 . V_163 = V_6 -> V_3 . V_164 ;
V_10 -> V_140 . V_141 = V_161 ;
V_10 -> V_140 . V_165 = 0 ;
V_6 -> V_3 . V_135 = V_160 ;
V_6 -> V_3 . V_143 = V_162 ;
V_6 -> V_166 = 1 ;
V_6 -> V_167 = 0 ;
V_6 -> V_3 . V_147 = 0 ;
if ( ! F_110 ( V_6 -> V_61 , V_168 , V_10 -> V_140 . V_163 ,
V_161 , & V_10 -> V_140 . V_137 ) ) {
F_105 ( V_6 , V_10 ) ;
V_6 -> V_166 = 0 ;
return V_49 ;
}
return V_51 ;
}
int F_111 ( struct V_46 * V_10 , struct V_1 * V_6 ,
unsigned int V_160 , unsigned int V_161 , int V_162 )
{
int V_7 ;
V_6 -> V_3 . V_147 = 1 ;
V_7 = F_109 ( V_10 , V_6 , V_160 , V_161 , V_162 ) ;
return V_7 ;
}
int F_112 ( struct V_46 * V_10 , struct V_1 * V_6 ,
V_128 V_169 , unsigned int V_161 , int V_162 )
{
void * V_137 = V_10 -> V_140 . V_137 ;
if ( V_161 > sizeof( V_10 -> V_140 . V_137 ) ) {
F_36 ( V_142 L_3 , V_56 ,
V_10 -> V_140 . V_141 ) ;
}
V_10 -> V_140 . V_163 = V_6 -> V_3 . V_164 ;
V_10 -> V_140 . V_141 = V_161 ;
V_10 -> V_140 . V_165 = 1 ;
V_6 -> V_166 = 1 ;
V_6 -> V_167 = 1 ;
if ( V_162 ) {
switch ( V_161 ) {
case 8 : * ( V_128 * ) V_137 = V_169 ; break;
case 4 : * ( V_144 * ) V_137 = V_169 ; break;
case 2 : * ( V_145 * ) V_137 = V_169 ; break;
case 1 : * ( V_146 * ) V_137 = V_169 ; break;
}
} else {
switch ( V_161 ) {
case 4 : F_113 ( V_137 , V_169 ) ; break;
case 2 : F_114 ( V_137 , V_169 ) ; break;
case 1 : * ( V_146 * ) V_137 = V_169 ; break;
}
}
if ( ! F_115 ( V_6 -> V_61 , V_168 , V_10 -> V_140 . V_163 ,
V_161 , & V_10 -> V_140 . V_137 ) ) {
F_105 ( V_6 , V_10 ) ;
V_6 -> V_166 = 0 ;
return V_49 ;
}
return V_51 ;
}
int F_116 ( struct V_1 * V_6 , struct V_46 * V_10 )
{
int V_7 ;
T_2 V_170 ;
if ( V_6 -> V_171 )
F_117 ( V_172 , & V_6 -> V_173 , & V_170 ) ;
if ( V_6 -> V_166 ) {
if ( ! V_6 -> V_167 )
F_105 ( V_6 , V_10 ) ;
V_6 -> V_166 = 0 ;
} else if ( V_6 -> V_3 . V_174 ) {
if ( ! V_6 -> V_3 . V_175 )
F_104 ( V_6 , V_10 ) ;
V_6 -> V_3 . V_174 = 0 ;
} else if ( V_6 -> V_3 . V_176 ) {
V_128 * V_177 = V_10 -> V_178 . V_177 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < 32 ; V_62 ++ )
F_29 ( V_6 , V_62 , V_177 [ V_62 ] ) ;
V_6 -> V_3 . V_176 = 0 ;
} else if ( V_6 -> V_3 . V_179 ) {
int V_62 ;
F_29 ( V_6 , 3 , V_10 -> V_180 . V_121 ) ;
for ( V_62 = 0 ; V_62 < 9 ; ++ V_62 )
F_29 ( V_6 , 4 + V_62 , V_10 -> V_180 . args [ V_62 ] ) ;
V_6 -> V_3 . V_179 = 0 ;
#ifdef F_57
} else if ( V_6 -> V_3 . V_181 ) {
F_118 ( V_6 , V_10 -> V_182 . V_182 ) ;
V_6 -> V_3 . V_181 = 0 ;
#endif
}
V_7 = F_119 ( V_10 , V_6 ) ;
if ( V_6 -> V_171 )
F_117 ( V_172 , & V_170 , NULL ) ;
return V_7 ;
}
int F_120 ( struct V_1 * V_6 , struct V_183 * V_184 )
{
if ( V_184 -> V_184 == V_185 ) {
F_121 ( V_6 , V_184 ) ;
return 0 ;
}
F_122 ( V_6 , V_184 ) ;
F_123 ( V_6 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_6 ,
struct V_186 * V_187 )
{
int V_7 ;
if ( V_187 -> V_188 )
return - V_45 ;
switch ( V_187 -> V_187 ) {
case V_79 :
V_7 = 0 ;
V_6 -> V_3 . V_189 = true ;
break;
case V_72 :
V_7 = 0 ;
V_6 -> V_3 . V_42 = true ;
break;
case V_69 :
V_7 = 0 ;
V_6 -> V_3 . V_190 = V_187 -> args [ 0 ] ;
break;
#ifdef F_57
case V_68 :
V_7 = 0 ;
V_6 -> V_3 . V_191 = true ;
break;
#endif
#if F_25 ( V_33 ) || F_25 ( V_81 )
case V_82 : {
struct V_192 V_193 ;
void T_3 * V_194 = ( void T_3 * ) ( V_195 ) V_187 -> args [ 0 ] ;
V_7 = - V_196 ;
if ( F_125 ( & V_193 , V_194 , sizeof( V_193 ) ) )
break;
V_7 = F_126 ( V_6 , & V_193 ) ;
break;
}
#endif
default:
V_7 = - V_45 ;
break;
}
if ( ! V_7 )
V_7 = F_30 ( V_6 ) ;
return V_7 ;
}
int F_127 ( struct V_1 * V_6 ,
struct V_197 * V_198 )
{
return - V_45 ;
}
int F_128 ( struct V_1 * V_6 ,
struct V_197 * V_198 )
{
return - V_45 ;
}
long F_129 ( struct V_99 * V_100 ,
unsigned int V_101 , unsigned long V_102 )
{
struct V_1 * V_6 = V_100 -> V_199 ;
void T_3 * V_200 = ( void T_3 * ) V_102 ;
long V_7 ;
switch ( V_101 ) {
case V_201 : {
struct V_183 V_184 ;
V_7 = - V_196 ;
if ( F_125 ( & V_184 , V_200 , sizeof( V_184 ) ) )
goto V_39;
V_7 = F_120 ( V_6 , & V_184 ) ;
goto V_39;
}
case V_202 :
{
struct V_186 V_187 ;
V_7 = - V_196 ;
if ( F_125 ( & V_187 , V_200 , sizeof( V_187 ) ) )
goto V_39;
V_7 = F_124 ( V_6 , & V_187 ) ;
break;
}
case V_203 :
case V_204 :
{
struct V_205 V_206 ;
V_7 = - V_196 ;
if ( F_125 ( & V_206 , V_200 , sizeof( V_206 ) ) )
goto V_39;
if ( V_101 == V_203 )
V_7 = F_130 ( V_6 , & V_206 ) ;
else
V_7 = F_131 ( V_6 , & V_206 ) ;
break;
}
#if F_25 ( V_33 ) || F_25 ( V_81 )
case V_207 : {
struct V_208 V_209 ;
V_7 = - V_196 ;
if ( F_125 ( & V_209 , V_200 , sizeof( V_209 ) ) )
goto V_39;
V_7 = F_132 ( V_6 , & V_209 ) ;
break;
}
#endif
default:
V_7 = - V_45 ;
}
V_39:
return V_7 ;
}
int F_133 ( struct V_1 * V_6 , struct V_210 * V_211 )
{
return V_212 ;
}
static int F_134 ( struct V_213 * V_214 )
{
V_144 V_215 = 0x60000000 ;
#ifdef F_32
V_144 V_216 = 0x44000022 ;
V_214 -> V_217 [ 0 ] = V_216 ;
V_214 -> V_217 [ 1 ] = V_215 ;
V_214 -> V_217 [ 2 ] = V_215 ;
V_214 -> V_217 [ 3 ] = V_215 ;
#else
V_144 V_218 = 0x3c000000 ;
V_144 V_219 = 0x60000000 ;
V_144 V_220 = 0x44000002 ;
V_144 V_221 = 0xffff ;
V_214 -> V_217 [ 0 ] = V_218 | ( ( V_222 >> 16 ) & V_221 ) ;
V_214 -> V_217 [ 1 ] = V_219 | ( V_222 & V_221 ) ;
V_214 -> V_217 [ 2 ] = V_220 ;
V_214 -> V_217 [ 3 ] = V_215 ;
#endif
V_214 -> V_188 = V_223 ;
return 0 ;
}
long F_135 ( struct V_99 * V_100 ,
unsigned int V_101 , unsigned long V_102 )
{
void T_3 * V_200 = ( void T_3 * ) V_102 ;
long V_7 ;
switch ( V_101 ) {
case V_224 : {
struct V_213 V_214 ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_7 = F_134 ( & V_214 ) ;
if ( F_136 ( V_200 , & V_214 , sizeof( V_214 ) ) ) {
V_7 = - V_196 ;
goto V_39;
}
break;
}
#ifdef F_58
case V_225 : {
struct V_226 V_227 ;
struct V_61 * V_61 = V_100 -> V_199 ;
V_7 = - V_196 ;
if ( F_125 ( & V_227 , V_200 , sizeof( V_227 ) ) )
goto V_39;
V_7 = F_137 ( V_61 , & V_227 ) ;
goto V_39;
}
#endif
#ifdef F_31
case V_228 : {
struct V_61 * V_61 = V_100 -> V_199 ;
struct V_229 V_230 ;
V_7 = F_138 ( V_61 , & V_230 ) ;
if ( V_7 >= 0 && F_136 ( V_200 , & V_230 , sizeof( V_230 ) ) )
V_7 = - V_196 ;
break;
}
case V_231 : {
struct V_61 * V_61 = V_100 -> V_199 ;
V_144 V_232 ;
V_7 = - V_196 ;
if ( F_139 ( V_232 , ( V_144 T_3 * ) V_200 ) )
break;
V_7 = F_140 ( V_61 , & V_232 ) ;
if ( V_7 )
break;
V_7 = - V_196 ;
if ( F_141 ( V_232 , ( V_144 T_3 * ) V_200 ) )
break;
V_7 = 0 ;
break;
}
case V_233 : {
struct V_61 * V_61 = V_100 -> V_199 ;
struct V_234 V_235 ;
V_7 = - V_196 ;
if ( F_125 ( & V_235 , V_200 , sizeof( V_235 ) ) )
break;
V_7 = F_142 ( V_61 , & V_235 ) ;
break;
}
#endif
#ifdef F_58
case V_236 : {
struct V_61 * V_61 = V_100 -> V_199 ;
struct V_237 V_238 ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_7 = F_143 ( V_61 , & V_238 ) ;
if ( V_7 >= 0 && F_136 ( V_200 , & V_238 , sizeof( V_238 ) ) )
V_7 = - V_196 ;
break;
}
#endif
default:
V_7 = - V_239 ;
}
V_39:
return V_7 ;
}
long F_144 ( void )
{
long V_240 ;
do {
V_240 = F_145 ( V_241 , V_242 ) ;
if ( V_240 >= V_243 ) {
F_146 ( L_4 , V_56 ) ;
return - V_244 ;
}
} while ( F_147 ( V_240 , V_241 ) );
return V_240 ;
}
void F_148 ( long V_240 )
{
F_149 ( V_240 , V_241 ) ;
}
void F_150 ( long V_240 )
{
F_28 ( V_240 , V_241 ) ;
}
void F_151 ( unsigned long V_245 )
{
V_243 = F_152 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_241 , 0 , sizeof( V_241 ) ) ;
}
int F_153 ( void * V_246 )
{
return 0 ;
}
void F_154 ( void )
{
}
