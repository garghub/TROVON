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
F_38 () ;
}
return V_7 ;
}
int F_39 ( void * V_58 )
{
return 0 ;
}
void F_40 ( void * V_58 )
{
}
int F_41 ( void )
{
return 0 ;
}
void F_42 ( void )
{
}
void F_43 ( void * V_59 )
{
* ( int * ) V_59 = F_44 () ;
}
int F_45 ( struct V_60 * V_60 , unsigned long type )
{
if ( type )
return - V_45 ;
return F_46 ( V_60 ) ;
}
void F_47 ( struct V_60 * V_60 )
{
unsigned int V_61 ;
struct V_1 * V_6 ;
F_48 (i, vcpu, kvm)
F_49 ( V_6 ) ;
F_50 ( & V_60 -> V_62 ) ;
for ( V_61 = 0 ; V_61 < F_51 ( & V_60 -> V_63 ) ; V_61 ++ )
V_60 -> V_64 [ V_61 ] = NULL ;
F_52 ( & V_60 -> V_63 , 0 ) ;
F_53 ( V_60 ) ;
F_54 ( & V_60 -> V_62 ) ;
}
void F_55 ( struct V_60 * V_60 )
{
}
int F_56 ( long V_65 )
{
int V_7 ;
switch ( V_65 ) {
#ifdef F_57
case V_66 :
case V_67 :
#else
case V_68 :
case V_69 :
case V_70 :
#endif
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_7 = 1 ;
break;
#ifndef F_31
case V_76 :
case V_77 :
case V_78 :
#if F_25 ( V_33 ) || F_25 ( V_79 )
case V_80 :
#endif
V_7 = 1 ;
break;
case V_81 :
V_7 = V_82 ;
break;
#endif
#ifdef F_58
case V_83 :
case V_84 :
V_7 = 1 ;
break;
#endif
#ifdef F_31
case V_85 :
V_7 = V_86 ;
break;
case V_87 :
V_7 = 1 ;
if ( F_33 ( V_88 ) )
V_7 = 2 ;
break;
#endif
case V_89 :
#ifdef F_31
V_7 = F_33 ( V_90 ) ? 1 : 0 ;
#elif F_25 ( V_91 )
V_7 = 1 ;
#else
V_7 = 0 ;
break;
#endif
#ifdef F_31
case V_92 :
V_7 = 1 ;
break;
#endif
break;
case V_93 :
#ifdef F_31
V_7 = F_59 () ;
#else
V_7 = F_60 () ;
#endif
break;
case V_94 :
V_7 = V_95 ;
break;
#ifdef F_58
case V_96 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_61 ( struct V_97 * V_98 ,
unsigned int V_99 , unsigned long V_100 )
{
return - V_45 ;
}
void F_62 ( struct V_101 * free ,
struct V_101 * V_102 )
{
F_63 ( free , V_102 ) ;
}
int F_64 ( struct V_101 * V_103 , unsigned long V_104 )
{
return F_65 ( V_103 , V_104 ) ;
}
int F_66 ( struct V_60 * V_60 ,
struct V_101 * V_105 ,
struct V_101 V_106 ,
struct V_107 * V_108 ,
int V_109 )
{
return F_67 ( V_60 , V_105 , V_108 ) ;
}
void F_68 ( struct V_60 * V_60 ,
struct V_107 * V_108 ,
struct V_101 V_106 ,
int V_109 )
{
F_69 ( V_60 , V_108 , V_106 ) ;
}
void F_70 ( struct V_60 * V_60 )
{
}
void F_71 ( struct V_60 * V_60 ,
struct V_101 * V_103 )
{
F_72 ( V_60 , V_103 ) ;
}
struct V_1 * F_73 ( struct V_60 * V_60 , unsigned int V_110 )
{
struct V_1 * V_6 ;
V_6 = F_74 ( V_60 , V_110 ) ;
if ( ! F_75 ( V_6 ) ) {
V_6 -> V_3 . V_111 = & V_6 -> V_112 ;
F_76 ( V_6 , V_110 ) ;
}
return V_6 ;
}
int F_77 ( struct V_1 * V_6 )
{
return 0 ;
}
void F_49 ( struct V_1 * V_6 )
{
F_78 ( & V_6 -> V_3 . V_113 ) ;
F_79 ( & V_6 -> V_3 . V_114 ) ;
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
enum V_115 F_85 ( struct V_116 * V_117 )
{
struct V_1 * V_6 ;
V_6 = F_86 ( V_117 , struct V_1 , V_3 . V_113 ) ;
F_87 ( & V_6 -> V_3 . V_114 ) ;
return V_118 ;
}
int F_88 ( struct V_1 * V_6 )
{
int V_119 ;
F_89 ( & V_6 -> V_3 . V_113 , V_120 , V_121 ) ;
F_90 ( & V_6 -> V_3 . V_114 , V_122 , ( V_123 ) V_6 ) ;
V_6 -> V_3 . V_113 . V_124 = F_85 ;
V_6 -> V_3 . V_125 = ~ ( V_126 ) 0 ;
#ifdef F_91
F_92 ( & V_6 -> V_3 . V_127 ) ;
#endif
V_119 = F_93 ( V_6 ) ;
return V_119 ;
}
void F_94 ( struct V_1 * V_6 )
{
F_95 ( V_6 ) ;
F_96 ( V_6 ) ;
}
void F_97 ( struct V_1 * V_6 , int V_128 )
{
#ifdef F_57
F_98 ( V_129 , V_6 -> V_3 . V_130 ) ;
#endif
F_99 ( V_6 , V_128 ) ;
}
void F_100 ( struct V_1 * V_6 )
{
F_101 ( V_6 ) ;
#ifdef F_57
V_6 -> V_3 . V_130 = F_102 ( V_129 ) ;
#endif
}
int F_103 ( struct V_1 * V_6 ,
struct V_131 * V_132 )
{
return - V_45 ;
}
static void F_104 ( struct V_1 * V_6 ,
struct V_46 * V_10 )
{
F_29 ( V_6 , V_6 -> V_3 . V_133 , V_10 -> V_134 . V_135 ) ;
}
static void F_105 ( struct V_1 * V_6 ,
struct V_46 * V_10 )
{
V_126 V_136 ( V_137 ) ;
if ( V_10 -> V_138 . V_139 > sizeof( V_137 ) ) {
F_36 ( V_140 L_2 , V_10 -> V_138 . V_139 ) ;
return;
}
if ( V_6 -> V_3 . V_141 ) {
switch ( V_10 -> V_138 . V_139 ) {
case 8 : V_137 = * ( V_126 * ) V_10 -> V_138 . V_135 ; break;
case 4 : V_137 = * ( V_142 * ) V_10 -> V_138 . V_135 ; break;
case 2 : V_137 = * ( V_143 * ) V_10 -> V_138 . V_135 ; break;
case 1 : V_137 = * ( V_144 * ) V_10 -> V_138 . V_135 ; break;
}
} else {
switch ( V_10 -> V_138 . V_139 ) {
case 4 : V_137 = F_106 ( ( V_142 * ) V_10 -> V_138 . V_135 ) ; break;
case 2 : V_137 = F_107 ( ( V_143 * ) V_10 -> V_138 . V_135 ) ; break;
case 1 : V_137 = * ( V_144 * ) V_10 -> V_138 . V_135 ; break;
}
}
if ( V_6 -> V_3 . V_145 ) {
switch ( V_10 -> V_138 . V_139 ) {
#ifdef F_16
case 4 :
V_137 = ( V_146 ) ( V_147 ) V_137 ;
break;
#endif
case 2 :
V_137 = ( V_146 ) ( V_148 ) V_137 ;
break;
case 1 :
V_137 = ( V_146 ) ( V_149 ) V_137 ;
break;
}
}
F_29 ( V_6 , V_6 -> V_3 . V_133 , V_137 ) ;
switch ( V_6 -> V_3 . V_133 & V_150 ) {
case V_151 :
F_29 ( V_6 , V_6 -> V_3 . V_133 , V_137 ) ;
break;
case V_152 :
V_6 -> V_3 . V_153 [ V_6 -> V_3 . V_133 & V_154 ] = V_137 ;
break;
#ifdef V_32
case V_155 :
V_6 -> V_3 . V_156 [ V_6 -> V_3 . V_133 & V_154 ] = V_137 ;
break;
case V_157 :
V_6 -> V_3 . V_153 [ V_6 -> V_3 . V_133 & V_154 ] = V_137 ;
V_6 -> V_3 . V_156 [ V_6 -> V_3 . V_133 & V_154 ] = V_137 ;
break;
#endif
default:
F_38 () ;
}
}
int F_108 ( struct V_46 * V_10 , struct V_1 * V_6 ,
unsigned int V_158 , unsigned int V_159 , int V_160 )
{
if ( V_159 > sizeof( V_10 -> V_138 . V_135 ) ) {
F_36 ( V_140 L_3 , V_56 ,
V_10 -> V_138 . V_139 ) ;
}
V_10 -> V_138 . V_161 = V_6 -> V_3 . V_162 ;
V_10 -> V_138 . V_139 = V_159 ;
V_10 -> V_138 . V_163 = 0 ;
V_6 -> V_3 . V_133 = V_158 ;
V_6 -> V_3 . V_141 = V_160 ;
V_6 -> V_164 = 1 ;
V_6 -> V_165 = 0 ;
V_6 -> V_3 . V_145 = 0 ;
if ( ! F_109 ( V_6 -> V_60 , V_166 , V_10 -> V_138 . V_161 ,
V_159 , & V_10 -> V_138 . V_135 ) ) {
F_105 ( V_6 , V_10 ) ;
V_6 -> V_164 = 0 ;
return V_49 ;
}
return V_51 ;
}
int F_110 ( struct V_46 * V_10 , struct V_1 * V_6 ,
unsigned int V_158 , unsigned int V_159 , int V_160 )
{
int V_7 ;
V_6 -> V_3 . V_145 = 1 ;
V_7 = F_108 ( V_10 , V_6 , V_158 , V_159 , V_160 ) ;
return V_7 ;
}
int F_111 ( struct V_46 * V_10 , struct V_1 * V_6 ,
V_126 V_167 , unsigned int V_159 , int V_160 )
{
void * V_135 = V_10 -> V_138 . V_135 ;
if ( V_159 > sizeof( V_10 -> V_138 . V_135 ) ) {
F_36 ( V_140 L_3 , V_56 ,
V_10 -> V_138 . V_139 ) ;
}
V_10 -> V_138 . V_161 = V_6 -> V_3 . V_162 ;
V_10 -> V_138 . V_139 = V_159 ;
V_10 -> V_138 . V_163 = 1 ;
V_6 -> V_164 = 1 ;
V_6 -> V_165 = 1 ;
if ( V_160 ) {
switch ( V_159 ) {
case 8 : * ( V_126 * ) V_135 = V_167 ; break;
case 4 : * ( V_142 * ) V_135 = V_167 ; break;
case 2 : * ( V_143 * ) V_135 = V_167 ; break;
case 1 : * ( V_144 * ) V_135 = V_167 ; break;
}
} else {
switch ( V_159 ) {
case 4 : F_112 ( V_135 , V_167 ) ; break;
case 2 : F_113 ( V_135 , V_167 ) ; break;
case 1 : * ( V_144 * ) V_135 = V_167 ; break;
}
}
if ( ! F_114 ( V_6 -> V_60 , V_166 , V_10 -> V_138 . V_161 ,
V_159 , & V_10 -> V_138 . V_135 ) ) {
F_105 ( V_6 , V_10 ) ;
V_6 -> V_164 = 0 ;
return V_49 ;
}
return V_51 ;
}
int F_115 ( struct V_1 * V_6 , struct V_46 * V_10 )
{
int V_7 ;
T_2 V_168 ;
if ( V_6 -> V_169 )
F_116 ( V_170 , & V_6 -> V_171 , & V_168 ) ;
if ( V_6 -> V_164 ) {
if ( ! V_6 -> V_165 )
F_105 ( V_6 , V_10 ) ;
V_6 -> V_164 = 0 ;
} else if ( V_6 -> V_3 . V_172 ) {
if ( ! V_6 -> V_3 . V_173 )
F_104 ( V_6 , V_10 ) ;
V_6 -> V_3 . V_172 = 0 ;
} else if ( V_6 -> V_3 . V_174 ) {
V_126 * V_175 = V_10 -> V_176 . V_175 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < 32 ; V_61 ++ )
F_29 ( V_6 , V_61 , V_175 [ V_61 ] ) ;
V_6 -> V_3 . V_174 = 0 ;
} else if ( V_6 -> V_3 . V_177 ) {
int V_61 ;
F_29 ( V_6 , 3 , V_10 -> V_178 . V_119 ) ;
for ( V_61 = 0 ; V_61 < 9 ; ++ V_61 )
F_29 ( V_6 , 4 + V_61 , V_10 -> V_178 . args [ V_61 ] ) ;
V_6 -> V_3 . V_177 = 0 ;
}
V_7 = F_117 ( V_10 , V_6 ) ;
if ( V_6 -> V_169 )
F_116 ( V_170 , & V_168 , NULL ) ;
return V_7 ;
}
int F_118 ( struct V_1 * V_6 , struct V_179 * V_180 )
{
if ( V_180 -> V_180 == V_181 ) {
F_119 ( V_6 , V_180 ) ;
return 0 ;
}
F_120 ( V_6 , V_180 ) ;
F_121 ( V_6 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_6 ,
struct V_182 * V_183 )
{
int V_7 ;
if ( V_183 -> V_184 )
return - V_45 ;
switch ( V_183 -> V_183 ) {
case V_77 :
V_7 = 0 ;
V_6 -> V_3 . V_185 = true ;
break;
case V_70 :
V_7 = 0 ;
V_6 -> V_3 . V_42 = true ;
break;
#ifdef F_57
case V_67 :
V_7 = 0 ;
V_6 -> V_3 . V_186 = true ;
break;
#endif
#if F_25 ( V_33 ) || F_25 ( V_79 )
case V_80 : {
struct V_187 V_188 ;
void T_3 * V_189 = ( void T_3 * ) ( V_190 ) V_183 -> args [ 0 ] ;
V_7 = - V_191 ;
if ( F_123 ( & V_188 , V_189 , sizeof( V_188 ) ) )
break;
V_7 = F_124 ( V_6 , & V_188 ) ;
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
int F_125 ( struct V_1 * V_6 ,
struct V_192 * V_193 )
{
return - V_45 ;
}
int F_126 ( struct V_1 * V_6 ,
struct V_192 * V_193 )
{
return - V_45 ;
}
long F_127 ( struct V_97 * V_98 ,
unsigned int V_99 , unsigned long V_100 )
{
struct V_1 * V_6 = V_98 -> V_194 ;
void T_3 * V_195 = ( void T_3 * ) V_100 ;
long V_7 ;
switch ( V_99 ) {
case V_196 : {
struct V_179 V_180 ;
V_7 = - V_191 ;
if ( F_123 ( & V_180 , V_195 , sizeof( V_180 ) ) )
goto V_39;
V_7 = F_118 ( V_6 , & V_180 ) ;
goto V_39;
}
case V_197 :
{
struct V_182 V_183 ;
V_7 = - V_191 ;
if ( F_123 ( & V_183 , V_195 , sizeof( V_183 ) ) )
goto V_39;
V_7 = F_122 ( V_6 , & V_183 ) ;
break;
}
case V_198 :
case V_199 :
{
struct V_200 V_201 ;
V_7 = - V_191 ;
if ( F_123 ( & V_201 , V_195 , sizeof( V_201 ) ) )
goto V_39;
if ( V_99 == V_198 )
V_7 = F_128 ( V_6 , & V_201 ) ;
else
V_7 = F_129 ( V_6 , & V_201 ) ;
break;
}
#if F_25 ( V_33 ) || F_25 ( V_79 )
case V_202 : {
struct V_203 V_204 ;
V_7 = - V_191 ;
if ( F_123 ( & V_204 , V_195 , sizeof( V_204 ) ) )
goto V_39;
V_7 = F_130 ( V_6 , & V_204 ) ;
break;
}
#endif
default:
V_7 = - V_45 ;
}
V_39:
return V_7 ;
}
int F_131 ( struct V_1 * V_6 , struct V_205 * V_206 )
{
return V_207 ;
}
static int F_132 ( struct V_208 * V_209 )
{
V_142 V_210 = 0x60000000 ;
#ifdef F_32
V_142 V_211 = 0x44000022 ;
V_209 -> V_212 [ 0 ] = V_211 ;
V_209 -> V_212 [ 1 ] = V_210 ;
V_209 -> V_212 [ 2 ] = V_210 ;
V_209 -> V_212 [ 3 ] = V_210 ;
#else
V_142 V_213 = 0x3c000000 ;
V_142 V_214 = 0x60000000 ;
V_142 V_215 = 0x44000002 ;
V_142 V_216 = 0xffff ;
V_209 -> V_212 [ 0 ] = V_213 | ( ( V_217 >> 16 ) & V_216 ) ;
V_209 -> V_212 [ 1 ] = V_214 | ( V_217 & V_216 ) ;
V_209 -> V_212 [ 2 ] = V_215 ;
V_209 -> V_212 [ 3 ] = V_210 ;
#endif
V_209 -> V_184 = V_218 ;
return 0 ;
}
long F_133 ( struct V_97 * V_98 ,
unsigned int V_99 , unsigned long V_100 )
{
void T_3 * V_195 = ( void T_3 * ) V_100 ;
long V_7 ;
switch ( V_99 ) {
case V_219 : {
struct V_208 V_209 ;
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_7 = F_132 ( & V_209 ) ;
if ( F_134 ( V_195 , & V_209 , sizeof( V_209 ) ) ) {
V_7 = - V_191 ;
goto V_39;
}
break;
}
#ifdef F_58
case V_220 : {
struct V_221 V_222 ;
struct V_60 * V_60 = V_98 -> V_194 ;
V_7 = - V_191 ;
if ( F_123 ( & V_222 , V_195 , sizeof( V_222 ) ) )
goto V_39;
V_7 = F_135 ( V_60 , & V_222 ) ;
goto V_39;
}
#endif
#ifdef F_31
case V_223 : {
struct V_60 * V_60 = V_98 -> V_194 ;
struct V_224 V_225 ;
V_7 = F_136 ( V_60 , & V_225 ) ;
if ( V_7 >= 0 && F_134 ( V_195 , & V_225 , sizeof( V_225 ) ) )
V_7 = - V_191 ;
break;
}
case V_226 : {
struct V_60 * V_60 = V_98 -> V_194 ;
V_142 V_227 ;
V_7 = - V_191 ;
if ( F_137 ( V_227 , ( V_142 T_3 * ) V_195 ) )
break;
V_7 = F_138 ( V_60 , & V_227 ) ;
if ( V_7 )
break;
V_7 = - V_191 ;
if ( F_139 ( V_227 , ( V_142 T_3 * ) V_195 ) )
break;
V_7 = 0 ;
break;
}
case V_228 : {
struct V_60 * V_60 = V_98 -> V_194 ;
struct V_229 V_230 ;
V_7 = - V_191 ;
if ( F_123 ( & V_230 , V_195 , sizeof( V_230 ) ) )
break;
V_7 = F_140 ( V_60 , & V_230 ) ;
break;
}
#endif
#ifdef F_58
case V_231 : {
struct V_60 * V_60 = V_98 -> V_194 ;
struct V_232 V_233 ;
memset ( & V_233 , 0 , sizeof( V_233 ) ) ;
V_7 = F_141 ( V_60 , & V_233 ) ;
if ( V_7 >= 0 && F_134 ( V_195 , & V_233 , sizeof( V_233 ) ) )
V_7 = - V_191 ;
break;
}
#endif
default:
V_7 = - V_234 ;
}
V_39:
return V_7 ;
}
long F_142 ( void )
{
long V_235 ;
do {
V_235 = F_143 ( V_236 , V_237 ) ;
if ( V_235 >= V_238 ) {
F_144 ( L_4 , V_56 ) ;
return - V_239 ;
}
} while ( F_145 ( V_235 , V_236 ) );
return V_235 ;
}
void F_146 ( long V_235 )
{
F_147 ( V_235 , V_236 ) ;
}
void F_148 ( long V_235 )
{
F_28 ( V_235 , V_236 ) ;
}
void F_149 ( unsigned long V_240 )
{
V_238 = F_150 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
}
int F_151 ( void * V_241 )
{
return 0 ;
}
void F_152 ( void )
{
}
