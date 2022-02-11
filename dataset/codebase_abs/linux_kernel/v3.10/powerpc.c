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
case V_78 :
V_7 = 1 ;
break;
#ifndef F_31
case V_79 :
case V_80 :
case V_81 :
#if F_25 ( V_33 ) || F_25 ( V_82 )
case V_83 :
#endif
#ifdef F_58
case V_84 :
#endif
V_7 = 1 ;
break;
case V_85 :
V_7 = V_86 ;
break;
#endif
#ifdef F_59
case V_87 :
case V_88 :
case V_89 :
#ifdef F_60
case V_90 :
#endif
V_7 = 1 ;
break;
#endif
#ifdef F_31
case V_91 :
V_7 = V_92 ;
break;
case V_93 :
V_7 = 1 ;
if ( F_33 ( V_94 ) )
V_7 = 2 ;
break;
#endif
case V_95 :
#ifdef F_31
V_7 = F_33 ( V_96 ) ? 1 : 0 ;
#elif F_25 ( V_97 )
V_7 = 1 ;
#else
V_7 = 0 ;
break;
#endif
#ifdef F_31
case V_98 :
V_7 = 1 ;
break;
#endif
break;
case V_99 :
#ifdef F_31
V_7 = F_61 () ;
#else
V_7 = F_62 () ;
#endif
break;
case V_100 :
V_7 = V_101 ;
break;
#ifdef F_59
case V_102 :
V_7 = 1 ;
break;
#endif
default:
V_7 = 0 ;
break;
}
return V_7 ;
}
long F_63 ( struct V_103 * V_104 ,
unsigned int V_105 , unsigned long V_106 )
{
return - V_45 ;
}
void F_64 ( struct V_107 * free ,
struct V_107 * V_108 )
{
F_65 ( free , V_108 ) ;
}
int F_66 ( struct V_107 * V_109 , unsigned long V_110 )
{
return F_67 ( V_109 , V_110 ) ;
}
int F_68 ( struct V_61 * V_61 ,
struct V_107 * V_111 ,
struct V_112 * V_113 ,
enum V_114 V_115 )
{
return F_69 ( V_61 , V_111 , V_113 ) ;
}
void F_70 ( struct V_61 * V_61 ,
struct V_112 * V_113 ,
const struct V_107 * V_116 ,
enum V_114 V_115 )
{
F_71 ( V_61 , V_113 , V_116 ) ;
}
void F_72 ( struct V_61 * V_61 )
{
}
void F_73 ( struct V_61 * V_61 ,
struct V_107 * V_109 )
{
F_74 ( V_61 , V_109 ) ;
}
struct V_1 * F_75 ( struct V_61 * V_61 , unsigned int V_117 )
{
struct V_1 * V_6 ;
V_6 = F_76 ( V_61 , V_117 ) ;
if ( ! F_77 ( V_6 ) ) {
V_6 -> V_3 . V_118 = & V_6 -> V_119 ;
F_78 ( V_6 , V_117 ) ;
}
return V_6 ;
}
int F_79 ( struct V_1 * V_6 )
{
return 0 ;
}
void F_49 ( struct V_1 * V_6 )
{
F_80 ( & V_6 -> V_3 . V_120 ) ;
F_81 ( & V_6 -> V_3 . V_121 ) ;
F_82 ( V_6 ) ;
switch ( V_6 -> V_3 . V_122 ) {
case V_123 :
F_83 ( V_6 -> V_3 . V_124 , V_6 ) ;
break;
case V_125 :
F_84 ( V_6 ) ;
break;
}
F_85 ( V_6 ) ;
}
void F_86 ( struct V_1 * V_6 )
{
F_49 ( V_6 ) ;
}
int F_87 ( struct V_1 * V_6 )
{
return F_88 ( V_6 ) ;
}
enum V_126 F_89 ( struct V_127 * V_128 )
{
struct V_1 * V_6 ;
V_6 = F_90 ( V_128 , struct V_1 , V_3 . V_120 ) ;
F_91 ( & V_6 -> V_3 . V_121 ) ;
return V_129 ;
}
int F_92 ( struct V_1 * V_6 )
{
int V_130 ;
F_93 ( & V_6 -> V_3 . V_120 , V_131 , V_132 ) ;
F_94 ( & V_6 -> V_3 . V_121 , V_133 , ( V_134 ) V_6 ) ;
V_6 -> V_3 . V_120 . V_135 = F_89 ;
V_6 -> V_3 . V_136 = ~ ( V_137 ) 0 ;
#ifdef F_95
F_96 ( & V_6 -> V_3 . V_138 ) ;
#endif
V_130 = F_97 ( V_6 ) ;
return V_130 ;
}
void F_98 ( struct V_1 * V_6 )
{
F_99 ( V_6 ) ;
F_100 ( V_6 ) ;
}
void F_101 ( struct V_1 * V_6 , int V_139 )
{
#ifdef F_57
F_102 ( V_140 , V_6 -> V_3 . V_141 ) ;
#endif
F_103 ( V_6 , V_139 ) ;
}
void F_104 ( struct V_1 * V_6 )
{
F_105 ( V_6 ) ;
#ifdef F_57
V_6 -> V_3 . V_141 = F_106 ( V_140 ) ;
#endif
}
static void F_107 ( struct V_1 * V_6 ,
struct V_46 * V_10 )
{
F_29 ( V_6 , V_6 -> V_3 . V_142 , V_10 -> V_143 . V_144 ) ;
}
static void F_108 ( struct V_1 * V_6 ,
struct V_46 * V_10 )
{
V_137 V_145 ( V_146 ) ;
if ( V_10 -> V_147 . V_148 > sizeof( V_146 ) ) {
F_36 ( V_149 L_2 , V_10 -> V_147 . V_148 ) ;
return;
}
if ( V_6 -> V_3 . V_150 ) {
switch ( V_10 -> V_147 . V_148 ) {
case 8 : V_146 = * ( V_137 * ) V_10 -> V_147 . V_144 ; break;
case 4 : V_146 = * ( V_151 * ) V_10 -> V_147 . V_144 ; break;
case 2 : V_146 = * ( V_152 * ) V_10 -> V_147 . V_144 ; break;
case 1 : V_146 = * ( V_153 * ) V_10 -> V_147 . V_144 ; break;
}
} else {
switch ( V_10 -> V_147 . V_148 ) {
case 4 : V_146 = F_109 ( ( V_151 * ) V_10 -> V_147 . V_144 ) ; break;
case 2 : V_146 = F_110 ( ( V_152 * ) V_10 -> V_147 . V_144 ) ; break;
case 1 : V_146 = * ( V_153 * ) V_10 -> V_147 . V_144 ; break;
}
}
if ( V_6 -> V_3 . V_154 ) {
switch ( V_10 -> V_147 . V_148 ) {
#ifdef F_16
case 4 :
V_146 = ( V_155 ) ( V_156 ) V_146 ;
break;
#endif
case 2 :
V_146 = ( V_155 ) ( V_157 ) V_146 ;
break;
case 1 :
V_146 = ( V_155 ) ( V_158 ) V_146 ;
break;
}
}
F_29 ( V_6 , V_6 -> V_3 . V_142 , V_146 ) ;
switch ( V_6 -> V_3 . V_142 & V_159 ) {
case V_160 :
F_29 ( V_6 , V_6 -> V_3 . V_142 , V_146 ) ;
break;
case V_161 :
V_6 -> V_3 . V_162 [ V_6 -> V_3 . V_142 & V_163 ] = V_146 ;
break;
#ifdef V_32
case V_164 :
V_6 -> V_3 . V_165 [ V_6 -> V_3 . V_142 & V_163 ] = V_146 ;
break;
case V_166 :
V_6 -> V_3 . V_162 [ V_6 -> V_3 . V_142 & V_163 ] = V_146 ;
V_6 -> V_3 . V_165 [ V_6 -> V_3 . V_142 & V_163 ] = V_146 ;
break;
#endif
default:
F_111 () ;
}
}
int F_112 ( struct V_46 * V_10 , struct V_1 * V_6 ,
unsigned int V_167 , unsigned int V_168 , int V_169 )
{
int V_170 , V_130 ;
if ( V_168 > sizeof( V_10 -> V_147 . V_144 ) ) {
F_36 ( V_149 L_3 , V_56 ,
V_10 -> V_147 . V_148 ) ;
}
V_10 -> V_147 . V_171 = V_6 -> V_3 . V_172 ;
V_10 -> V_147 . V_148 = V_168 ;
V_10 -> V_147 . V_173 = 0 ;
V_6 -> V_3 . V_142 = V_167 ;
V_6 -> V_3 . V_150 = V_169 ;
V_6 -> V_174 = 1 ;
V_6 -> V_175 = 0 ;
V_6 -> V_3 . V_154 = 0 ;
V_170 = F_113 ( & V_6 -> V_61 -> V_176 ) ;
V_130 = F_114 ( V_6 -> V_61 , V_177 , V_10 -> V_147 . V_171 ,
V_168 , & V_10 -> V_147 . V_144 ) ;
F_115 ( & V_6 -> V_61 -> V_176 , V_170 ) ;
if ( ! V_130 ) {
F_108 ( V_6 , V_10 ) ;
V_6 -> V_174 = 0 ;
return V_49 ;
}
return V_51 ;
}
int F_116 ( struct V_46 * V_10 , struct V_1 * V_6 ,
unsigned int V_167 , unsigned int V_168 , int V_169 )
{
int V_7 ;
V_6 -> V_3 . V_154 = 1 ;
V_7 = F_112 ( V_10 , V_6 , V_167 , V_168 , V_169 ) ;
return V_7 ;
}
int F_117 ( struct V_46 * V_10 , struct V_1 * V_6 ,
V_137 V_178 , unsigned int V_168 , int V_169 )
{
void * V_144 = V_10 -> V_147 . V_144 ;
int V_170 , V_130 ;
if ( V_168 > sizeof( V_10 -> V_147 . V_144 ) ) {
F_36 ( V_149 L_3 , V_56 ,
V_10 -> V_147 . V_148 ) ;
}
V_10 -> V_147 . V_171 = V_6 -> V_3 . V_172 ;
V_10 -> V_147 . V_148 = V_168 ;
V_10 -> V_147 . V_173 = 1 ;
V_6 -> V_174 = 1 ;
V_6 -> V_175 = 1 ;
if ( V_169 ) {
switch ( V_168 ) {
case 8 : * ( V_137 * ) V_144 = V_178 ; break;
case 4 : * ( V_151 * ) V_144 = V_178 ; break;
case 2 : * ( V_152 * ) V_144 = V_178 ; break;
case 1 : * ( V_153 * ) V_144 = V_178 ; break;
}
} else {
switch ( V_168 ) {
case 4 : F_118 ( V_144 , V_178 ) ; break;
case 2 : F_119 ( V_144 , V_178 ) ; break;
case 1 : * ( V_153 * ) V_144 = V_178 ; break;
}
}
V_170 = F_113 ( & V_6 -> V_61 -> V_176 ) ;
V_130 = F_120 ( V_6 -> V_61 , V_177 , V_10 -> V_147 . V_171 ,
V_168 , & V_10 -> V_147 . V_144 ) ;
F_115 ( & V_6 -> V_61 -> V_176 , V_170 ) ;
if ( ! V_130 ) {
V_6 -> V_174 = 0 ;
return V_49 ;
}
return V_51 ;
}
int F_121 ( struct V_1 * V_6 , struct V_46 * V_10 )
{
int V_7 ;
T_2 V_179 ;
if ( V_6 -> V_180 )
F_122 ( V_181 , & V_6 -> V_182 , & V_179 ) ;
if ( V_6 -> V_174 ) {
if ( ! V_6 -> V_175 )
F_108 ( V_6 , V_10 ) ;
V_6 -> V_174 = 0 ;
} else if ( V_6 -> V_3 . V_183 ) {
if ( ! V_6 -> V_3 . V_184 )
F_107 ( V_6 , V_10 ) ;
V_6 -> V_3 . V_183 = 0 ;
} else if ( V_6 -> V_3 . V_185 ) {
V_137 * V_186 = V_10 -> V_187 . V_186 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < 32 ; V_62 ++ )
F_29 ( V_6 , V_62 , V_186 [ V_62 ] ) ;
V_6 -> V_3 . V_185 = 0 ;
} else if ( V_6 -> V_3 . V_188 ) {
int V_62 ;
F_29 ( V_6 , 3 , V_10 -> V_189 . V_130 ) ;
for ( V_62 = 0 ; V_62 < 9 ; ++ V_62 )
F_29 ( V_6 , 4 + V_62 , V_10 -> V_189 . args [ V_62 ] ) ;
V_6 -> V_3 . V_188 = 0 ;
#ifdef F_57
} else if ( V_6 -> V_3 . V_190 ) {
F_123 ( V_6 , V_10 -> V_191 . V_191 ) ;
V_6 -> V_3 . V_190 = 0 ;
#endif
}
V_7 = F_124 ( V_10 , V_6 ) ;
if ( V_6 -> V_180 )
F_122 ( V_181 , & V_179 , NULL ) ;
return V_7 ;
}
int F_125 ( struct V_1 * V_6 , struct V_192 * V_193 )
{
if ( V_193 -> V_193 == V_194 ) {
F_126 ( V_6 ) ;
return 0 ;
}
F_127 ( V_6 , V_193 ) ;
F_128 ( V_6 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_6 ,
struct V_195 * V_196 )
{
int V_7 ;
if ( V_196 -> V_197 )
return - V_45 ;
switch ( V_196 -> V_196 ) {
case V_80 :
V_7 = 0 ;
V_6 -> V_3 . V_198 = true ;
break;
case V_72 :
V_7 = 0 ;
V_6 -> V_3 . V_42 = true ;
break;
case V_69 :
V_7 = 0 ;
if ( V_196 -> args [ 0 ] )
V_6 -> V_3 . V_199 |= V_200 ;
else
V_6 -> V_3 . V_199 &= ~ V_200 ;
break;
#ifdef F_57
case V_68 :
V_7 = 0 ;
V_6 -> V_3 . V_201 = true ;
break;
#endif
#if F_25 ( V_33 ) || F_25 ( V_82 )
case V_83 : {
struct V_202 V_203 ;
void T_3 * V_204 = ( void T_3 * ) ( V_205 ) V_196 -> args [ 0 ] ;
V_7 = - V_206 ;
if ( F_130 ( & V_203 , V_204 , sizeof( V_203 ) ) )
break;
V_7 = F_131 ( V_6 , & V_203 ) ;
break;
}
#endif
#ifdef F_58
case V_84 : {
struct V_103 * V_104 ;
struct V_207 * V_208 ;
V_7 = - V_209 ;
V_104 = F_132 ( V_196 -> args [ 0 ] ) ;
if ( ! V_104 )
break;
V_7 = - V_210 ;
V_208 = F_133 ( V_104 ) ;
if ( V_208 )
V_7 = F_134 ( V_208 , V_6 , V_196 -> args [ 1 ] ) ;
F_135 ( V_104 ) ;
break;
}
#endif
#ifdef F_60
case V_90 : {
struct V_103 * V_104 ;
struct V_207 * V_208 ;
V_7 = - V_209 ;
V_104 = F_132 ( V_196 -> args [ 0 ] ) ;
if ( ! V_104 )
break;
V_7 = - V_210 ;
V_208 = F_133 ( V_104 ) ;
if ( V_208 )
V_7 = F_136 ( V_208 , V_6 , V_196 -> args [ 1 ] ) ;
F_135 ( V_104 ) ;
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
int F_137 ( struct V_1 * V_6 ,
struct V_211 * V_212 )
{
return - V_45 ;
}
int F_138 ( struct V_1 * V_6 ,
struct V_211 * V_212 )
{
return - V_45 ;
}
long F_139 ( struct V_103 * V_104 ,
unsigned int V_105 , unsigned long V_106 )
{
struct V_1 * V_6 = V_104 -> V_213 ;
void T_3 * V_214 = ( void T_3 * ) V_106 ;
long V_7 ;
switch ( V_105 ) {
case V_215 : {
struct V_192 V_193 ;
V_7 = - V_206 ;
if ( F_130 ( & V_193 , V_214 , sizeof( V_193 ) ) )
goto V_39;
V_7 = F_125 ( V_6 , & V_193 ) ;
goto V_39;
}
case V_216 :
{
struct V_195 V_196 ;
V_7 = - V_206 ;
if ( F_130 ( & V_196 , V_214 , sizeof( V_196 ) ) )
goto V_39;
V_7 = F_129 ( V_6 , & V_196 ) ;
break;
}
case V_217 :
case V_218 :
{
struct V_219 V_220 ;
V_7 = - V_206 ;
if ( F_130 ( & V_220 , V_214 , sizeof( V_220 ) ) )
goto V_39;
if ( V_105 == V_217 )
V_7 = F_140 ( V_6 , & V_220 ) ;
else
V_7 = F_141 ( V_6 , & V_220 ) ;
break;
}
#if F_25 ( V_33 ) || F_25 ( V_82 )
case V_221 : {
struct V_222 V_223 ;
V_7 = - V_206 ;
if ( F_130 ( & V_223 , V_214 , sizeof( V_223 ) ) )
goto V_39;
V_7 = F_142 ( V_6 , & V_223 ) ;
break;
}
#endif
default:
V_7 = - V_45 ;
}
V_39:
return V_7 ;
}
int F_143 ( struct V_1 * V_6 , struct V_224 * V_225 )
{
return V_226 ;
}
static int F_144 ( struct V_227 * V_228 )
{
V_151 V_229 = 0x60000000 ;
#ifdef F_32
V_151 V_230 = 0x44000022 ;
V_228 -> V_231 [ 0 ] = V_230 ;
V_228 -> V_231 [ 1 ] = V_229 ;
V_228 -> V_231 [ 2 ] = V_229 ;
V_228 -> V_231 [ 3 ] = V_229 ;
#else
V_151 V_232 = 0x3c000000 ;
V_151 V_233 = 0x60000000 ;
V_151 V_234 = 0x44000002 ;
V_151 V_235 = 0xffff ;
V_228 -> V_231 [ 0 ] = V_232 | ( ( V_236 >> 16 ) & V_235 ) ;
V_228 -> V_231 [ 1 ] = V_233 | ( V_236 & V_235 ) ;
V_228 -> V_231 [ 2 ] = V_234 ;
V_228 -> V_231 [ 3 ] = V_229 ;
#endif
V_228 -> V_197 = V_237 ;
return 0 ;
}
int F_145 ( struct V_61 * V_61 , struct V_238 * V_239 ,
bool V_240 )
{
if ( ! F_146 ( V_61 ) )
return - V_241 ;
V_239 -> V_242 = F_147 ( V_61 , V_243 ,
V_239 -> V_193 , V_239 -> V_244 ,
V_240 ) ;
return 0 ;
}
long F_148 ( struct V_103 * V_104 ,
unsigned int V_105 , unsigned long V_106 )
{
struct V_61 * V_61 T_1 = V_104 -> V_213 ;
void T_3 * V_214 = ( void T_3 * ) V_106 ;
long V_7 ;
switch ( V_105 ) {
case V_245 : {
struct V_227 V_228 ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_7 = F_144 ( & V_228 ) ;
if ( F_149 ( V_214 , & V_228 , sizeof( V_228 ) ) ) {
V_7 = - V_206 ;
goto V_39;
}
break;
}
#ifdef F_59
case V_246 : {
struct V_247 V_248 ;
V_7 = - V_206 ;
if ( F_130 ( & V_248 , V_214 , sizeof( V_248 ) ) )
goto V_39;
V_7 = F_150 ( V_61 , & V_248 ) ;
goto V_39;
}
#endif
#ifdef F_31
case V_249 : {
struct V_250 V_251 ;
struct V_61 * V_61 = V_104 -> V_213 ;
V_7 = F_151 ( V_61 , & V_251 ) ;
if ( V_7 >= 0 && F_149 ( V_214 , & V_251 , sizeof( V_251 ) ) )
V_7 = - V_206 ;
break;
}
case V_252 : {
V_151 V_253 ;
V_7 = - V_206 ;
if ( F_152 ( V_253 , ( V_151 T_3 * ) V_214 ) )
break;
V_7 = F_153 ( V_61 , & V_253 ) ;
if ( V_7 )
break;
V_7 = - V_206 ;
if ( F_154 ( V_253 , ( V_151 T_3 * ) V_214 ) )
break;
V_7 = 0 ;
break;
}
case V_254 : {
struct V_255 V_256 ;
V_7 = - V_206 ;
if ( F_130 ( & V_256 , V_214 , sizeof( V_256 ) ) )
break;
V_7 = F_155 ( V_61 , & V_256 ) ;
break;
}
#endif
#ifdef F_59
case V_257 : {
struct V_258 V_259 ;
memset ( & V_259 , 0 , sizeof( V_259 ) ) ;
V_7 = F_156 ( V_61 , & V_259 ) ;
if ( V_7 >= 0 && F_149 ( V_214 , & V_259 , sizeof( V_259 ) ) )
V_7 = - V_206 ;
break;
}
case V_260 : {
struct V_61 * V_61 = V_104 -> V_213 ;
V_7 = F_157 ( V_61 , V_214 ) ;
break;
}
#endif
default:
V_7 = - V_261 ;
}
V_39:
return V_7 ;
}
long F_158 ( void )
{
long V_262 ;
do {
V_262 = F_159 ( V_263 , V_264 ) ;
if ( V_262 >= V_265 ) {
F_160 ( L_4 , V_56 ) ;
return - V_266 ;
}
} while ( F_161 ( V_262 , V_263 ) );
return V_262 ;
}
void F_162 ( long V_262 )
{
F_163 ( V_262 , V_263 ) ;
}
void F_164 ( long V_262 )
{
F_28 ( V_262 , V_263 ) ;
}
void F_165 ( unsigned long V_267 )
{
V_265 = F_166 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_263 , 0 , sizeof( V_263 ) ) ;
}
int F_167 ( void * V_268 )
{
return 0 ;
}
void F_168 ( void )
{
}
