int F_1 ( struct V_1 * V_2 )
{
return ! ( V_2 -> V_3 . V_4 -> V_5 & V_6 ) ||
! ! ( V_2 -> V_3 . V_7 ) ||
V_2 -> V_8 ;
}
int F_2 ( struct V_1 * V_9 )
{
return 1 ;
}
int F_3 ( struct V_1 * V_9 )
{
int V_10 = F_4 ( V_9 , 11 ) ;
int V_11 ;
unsigned long T_1 V_12 = F_4 ( V_9 , 3 ) ;
unsigned long T_1 V_13 = F_4 ( V_9 , 4 ) ;
unsigned long T_1 V_14 = F_4 ( V_9 , 5 ) ;
unsigned long T_1 V_15 = F_4 ( V_9 , 6 ) ;
unsigned long V_16 = 0 ;
if ( ! ( V_9 -> V_3 . V_4 -> V_5 & V_17 ) ) {
V_12 &= 0xffffffff ;
V_13 &= 0xffffffff ;
V_14 &= 0xffffffff ;
V_15 &= 0xffffffff ;
}
switch ( V_10 ) {
case V_18 | V_19 :
{
V_9 -> V_3 . V_20 = V_12 ;
V_9 -> V_3 . V_21 = V_13 ;
V_16 = V_22 | V_23 ;
V_11 = V_24 ;
break;
}
case V_18 | V_25 :
V_11 = V_24 ;
#if F_5 ( V_26 ) || F_5 ( V_27 )
V_16 |= ( 1 << V_28 ) ;
#endif
break;
default:
V_11 = V_29 ;
break;
}
F_6 ( V_9 , 4 , V_16 ) ;
return V_11 ;
}
int F_7 ( struct V_1 * V_9 )
{
int V_11 = false ;
if ( ! V_9 -> V_3 . V_30 )
goto V_31;
if ( ( V_9 -> V_3 . V_32 != V_33 ) && V_9 -> V_3 . V_34 )
goto V_31;
#ifdef F_8
if ( ! V_9 -> V_3 . V_34 )
goto V_31;
#endif
#ifdef F_9
if ( ! F_10 ( V_35 ) )
goto V_31;
#endif
V_11 = true ;
V_31:
V_9 -> V_3 . V_36 = V_11 ;
return V_11 ? 0 : - V_37 ;
}
int F_11 ( struct V_38 * V_39 , struct V_1 * V_9 )
{
enum V_40 V_41 ;
int V_11 ;
V_41 = F_12 ( V_39 , V_9 ) ;
switch ( V_41 ) {
case V_42 :
V_11 = V_43 ;
break;
case V_44 :
V_39 -> V_45 = V_46 ;
V_11 = V_47 ;
break;
case V_48 :
F_13 ( V_49 L_1 , V_50 ,
F_14 ( V_9 ) ) ;
V_11 = V_51 ;
break;
default:
F_15 () ;
}
return V_11 ;
}
int F_16 ( void * V_52 )
{
return 0 ;
}
void F_17 ( void * V_52 )
{
}
int F_18 ( void )
{
return 0 ;
}
void F_19 ( void )
{
}
void F_20 ( void * V_53 )
{
* ( int * ) V_53 = F_21 () ;
}
int F_22 ( struct V_54 * V_54 , unsigned long type )
{
if ( type )
return - V_37 ;
return F_23 ( V_54 ) ;
}
void F_24 ( struct V_54 * V_54 )
{
unsigned int V_55 ;
struct V_1 * V_9 ;
F_25 (i, vcpu, kvm)
F_26 ( V_9 ) ;
F_27 ( & V_54 -> V_56 ) ;
for ( V_55 = 0 ; V_55 < F_28 ( & V_54 -> V_57 ) ; V_55 ++ )
V_54 -> V_58 [ V_55 ] = NULL ;
F_29 ( & V_54 -> V_57 , 0 ) ;
F_30 ( V_54 ) ;
F_31 ( & V_54 -> V_56 ) ;
}
void F_32 ( struct V_54 * V_54 )
{
}
int F_33 ( long V_59 )
{
int V_11 ;
switch ( V_59 ) {
#ifdef F_34
case V_60 :
#else
case V_61 :
case V_62 :
case V_63 :
#endif
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_11 = 1 ;
break;
#ifndef F_8
case V_68 :
case V_69 :
case V_70 :
#if F_5 ( V_27 ) || F_5 ( V_71 )
case V_72 :
#endif
V_11 = 1 ;
break;
case V_73 :
V_11 = V_74 ;
break;
#endif
#ifdef F_35
case V_75 :
case V_76 :
V_11 = 1 ;
break;
#endif
#ifdef F_8
case V_77 :
V_11 = V_78 ;
break;
case V_79 :
V_11 = 1 ;
if ( F_10 ( V_80 ) )
V_11 = 2 ;
break;
case V_81 :
V_11 = F_10 ( V_82 ) ? 1 : 0 ;
break;
#endif
case V_83 :
#ifdef F_8
V_11 = F_36 () ;
#else
V_11 = F_37 () ;
#endif
break;
case V_84 :
V_11 = V_85 ;
break;
#ifdef F_35
case V_86 :
V_11 = 1 ;
break;
#endif
default:
V_11 = 0 ;
break;
}
return V_11 ;
}
long F_38 ( struct V_87 * V_88 ,
unsigned int V_89 , unsigned long V_90 )
{
return - V_37 ;
}
void F_39 ( struct V_91 * free ,
struct V_91 * V_92 )
{
}
int F_40 ( struct V_91 * V_93 , unsigned long V_94 )
{
return 0 ;
}
int F_41 ( struct V_54 * V_54 ,
struct V_91 * V_95 ,
struct V_91 V_96 ,
struct V_97 * V_98 ,
int V_99 )
{
return F_42 ( V_54 , V_98 ) ;
}
void F_43 ( struct V_54 * V_54 ,
struct V_97 * V_98 ,
struct V_91 V_96 ,
int V_99 )
{
F_44 ( V_54 , V_98 ) ;
}
void F_45 ( struct V_54 * V_54 )
{
}
struct V_1 * F_46 ( struct V_54 * V_54 , unsigned int V_100 )
{
struct V_1 * V_9 ;
V_9 = F_47 ( V_54 , V_100 ) ;
if ( ! F_48 ( V_9 ) ) {
V_9 -> V_3 . V_101 = & V_9 -> V_102 ;
F_49 ( V_9 , V_100 ) ;
}
return V_9 ;
}
void F_26 ( struct V_1 * V_9 )
{
F_50 ( & V_9 -> V_3 . V_103 ) ;
F_51 ( & V_9 -> V_3 . V_104 ) ;
F_52 ( V_9 ) ;
F_53 ( V_9 ) ;
}
void F_54 ( struct V_1 * V_9 )
{
F_26 ( V_9 ) ;
}
int F_55 ( struct V_1 * V_9 )
{
return F_56 ( V_9 ) ;
}
enum V_105 F_57 ( struct V_106 * V_107 )
{
struct V_1 * V_9 ;
V_9 = F_58 ( V_107 , struct V_1 , V_3 . V_103 ) ;
F_59 ( & V_9 -> V_3 . V_104 ) ;
return V_108 ;
}
int F_60 ( struct V_1 * V_9 )
{
F_61 ( & V_9 -> V_3 . V_103 , V_109 , V_110 ) ;
F_62 ( & V_9 -> V_3 . V_104 , V_111 , ( V_112 ) V_9 ) ;
V_9 -> V_3 . V_103 . V_113 = F_57 ;
V_9 -> V_3 . V_114 = ~ ( V_115 ) 0 ;
#ifdef F_63
F_64 ( & V_9 -> V_3 . V_116 ) ;
#endif
return 0 ;
}
void F_65 ( struct V_1 * V_9 )
{
F_66 ( V_9 ) ;
}
void F_67 ( struct V_1 * V_9 , int V_117 )
{
#ifdef F_34
F_68 ( V_118 , V_9 -> V_3 . V_119 ) ;
#endif
F_69 ( V_9 , V_117 ) ;
V_9 -> V_117 = F_70 () ;
}
void F_71 ( struct V_1 * V_9 )
{
F_72 ( V_9 ) ;
#ifdef F_34
V_9 -> V_3 . V_119 = F_73 ( V_118 ) ;
#endif
V_9 -> V_117 = - 1 ;
}
int F_74 ( struct V_1 * V_9 ,
struct V_120 * V_121 )
{
return - V_37 ;
}
static void F_75 ( struct V_1 * V_9 ,
struct V_38 * V_39 )
{
F_6 ( V_9 , V_9 -> V_3 . V_122 , V_39 -> V_123 . V_124 ) ;
}
static void F_76 ( struct V_1 * V_9 ,
struct V_38 * V_39 )
{
V_115 V_125 ( V_126 ) ;
if ( V_39 -> V_127 . V_128 > sizeof( V_126 ) ) {
F_13 ( V_129 L_2 , V_39 -> V_127 . V_128 ) ;
return;
}
if ( V_9 -> V_3 . V_130 ) {
switch ( V_39 -> V_127 . V_128 ) {
case 8 : V_126 = * ( V_115 * ) V_39 -> V_127 . V_124 ; break;
case 4 : V_126 = * ( V_131 * ) V_39 -> V_127 . V_124 ; break;
case 2 : V_126 = * ( V_132 * ) V_39 -> V_127 . V_124 ; break;
case 1 : V_126 = * ( V_133 * ) V_39 -> V_127 . V_124 ; break;
}
} else {
switch ( V_39 -> V_127 . V_128 ) {
case 4 : V_126 = F_77 ( ( V_131 * ) V_39 -> V_127 . V_124 ) ; break;
case 2 : V_126 = F_78 ( ( V_132 * ) V_39 -> V_127 . V_124 ) ; break;
case 1 : V_126 = * ( V_133 * ) V_39 -> V_127 . V_124 ; break;
}
}
if ( V_9 -> V_3 . V_134 ) {
switch ( V_39 -> V_127 . V_128 ) {
#ifdef F_79
case 4 :
V_126 = ( V_135 ) ( V_136 ) V_126 ;
break;
#endif
case 2 :
V_126 = ( V_135 ) ( V_137 ) V_126 ;
break;
case 1 :
V_126 = ( V_135 ) ( V_138 ) V_126 ;
break;
}
}
F_6 ( V_9 , V_9 -> V_3 . V_122 , V_126 ) ;
switch ( V_9 -> V_3 . V_122 & V_139 ) {
case V_140 :
F_6 ( V_9 , V_9 -> V_3 . V_122 , V_126 ) ;
break;
case V_141 :
V_9 -> V_3 . V_142 [ V_9 -> V_3 . V_122 & V_143 ] = V_126 ;
break;
#ifdef V_26
case V_144 :
V_9 -> V_3 . V_145 [ V_9 -> V_3 . V_122 & V_143 ] = V_126 ;
break;
case V_146 :
V_9 -> V_3 . V_142 [ V_9 -> V_3 . V_122 & V_143 ] = V_126 ;
V_9 -> V_3 . V_145 [ V_9 -> V_3 . V_122 & V_143 ] = V_126 ;
break;
#endif
default:
F_15 () ;
}
}
int F_80 ( struct V_38 * V_39 , struct V_1 * V_9 ,
unsigned int V_147 , unsigned int V_148 , int V_149 )
{
if ( V_148 > sizeof( V_39 -> V_127 . V_124 ) ) {
F_13 ( V_129 L_3 , V_50 ,
V_39 -> V_127 . V_128 ) ;
}
V_39 -> V_127 . V_150 = V_9 -> V_3 . V_151 ;
V_39 -> V_127 . V_128 = V_148 ;
V_39 -> V_127 . V_152 = 0 ;
V_9 -> V_3 . V_122 = V_147 ;
V_9 -> V_3 . V_130 = V_149 ;
V_9 -> V_153 = 1 ;
V_9 -> V_154 = 0 ;
V_9 -> V_3 . V_134 = 0 ;
return V_44 ;
}
int F_81 ( struct V_38 * V_39 , struct V_1 * V_9 ,
unsigned int V_147 , unsigned int V_148 , int V_149 )
{
int V_11 ;
V_11 = F_80 ( V_39 , V_9 , V_147 , V_148 , V_149 ) ;
V_9 -> V_3 . V_134 = 1 ;
return V_11 ;
}
int F_82 ( struct V_38 * V_39 , struct V_1 * V_9 ,
V_115 V_155 , unsigned int V_148 , int V_149 )
{
void * V_124 = V_39 -> V_127 . V_124 ;
if ( V_148 > sizeof( V_39 -> V_127 . V_124 ) ) {
F_13 ( V_129 L_3 , V_50 ,
V_39 -> V_127 . V_128 ) ;
}
V_39 -> V_127 . V_150 = V_9 -> V_3 . V_151 ;
V_39 -> V_127 . V_128 = V_148 ;
V_39 -> V_127 . V_152 = 1 ;
V_9 -> V_153 = 1 ;
V_9 -> V_154 = 1 ;
if ( V_149 ) {
switch ( V_148 ) {
case 8 : * ( V_115 * ) V_124 = V_155 ; break;
case 4 : * ( V_131 * ) V_124 = V_155 ; break;
case 2 : * ( V_132 * ) V_124 = V_155 ; break;
case 1 : * ( V_133 * ) V_124 = V_155 ; break;
}
} else {
switch ( V_148 ) {
case 4 : F_83 ( V_124 , V_155 ) ; break;
case 2 : F_84 ( V_124 , V_155 ) ; break;
case 1 : * ( V_133 * ) V_124 = V_155 ; break;
}
}
return V_44 ;
}
int F_85 ( struct V_1 * V_9 , struct V_38 * V_39 )
{
int V_11 ;
T_2 V_156 ;
if ( V_9 -> V_157 )
F_86 ( V_158 , & V_9 -> V_159 , & V_156 ) ;
if ( V_9 -> V_153 ) {
if ( ! V_9 -> V_154 )
F_76 ( V_9 , V_39 ) ;
V_9 -> V_153 = 0 ;
} else if ( V_9 -> V_3 . V_160 ) {
if ( ! V_9 -> V_3 . V_161 )
F_75 ( V_9 , V_39 ) ;
V_9 -> V_3 . V_160 = 0 ;
} else if ( V_9 -> V_3 . V_162 ) {
V_115 * V_163 = V_39 -> V_164 . V_163 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < 32 ; V_55 ++ )
F_6 ( V_9 , V_55 , V_163 [ V_55 ] ) ;
V_9 -> V_3 . V_162 = 0 ;
} else if ( V_9 -> V_3 . V_165 ) {
int V_55 ;
F_6 ( V_9 , 3 , V_39 -> V_166 . V_167 ) ;
for ( V_55 = 0 ; V_55 < 9 ; ++ V_55 )
F_6 ( V_9 , 4 + V_55 , V_39 -> V_166 . args [ V_55 ] ) ;
V_9 -> V_3 . V_165 = 0 ;
}
V_11 = F_87 ( V_39 , V_9 ) ;
if ( V_9 -> V_157 )
F_86 ( V_158 , & V_156 , NULL ) ;
return V_11 ;
}
int F_88 ( struct V_1 * V_9 , struct V_168 * V_169 )
{
if ( V_169 -> V_169 == V_170 ) {
F_89 ( V_9 , V_169 ) ;
return 0 ;
}
F_90 ( V_9 , V_169 ) ;
F_91 ( V_9 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_9 ,
struct V_171 * V_172 )
{
int V_11 ;
if ( V_172 -> V_173 )
return - V_37 ;
switch ( V_172 -> V_172 ) {
case V_69 :
V_11 = 0 ;
V_9 -> V_3 . V_174 = true ;
break;
case V_63 :
V_11 = 0 ;
V_9 -> V_3 . V_34 = true ;
break;
#if F_5 ( V_27 ) || F_5 ( V_71 )
case V_72 : {
struct V_175 V_176 ;
void T_3 * V_177 = ( void T_3 * ) ( V_178 ) V_172 -> args [ 0 ] ;
V_11 = - V_179 ;
if ( F_93 ( & V_176 , V_177 , sizeof( V_176 ) ) )
break;
V_11 = F_94 ( V_9 , & V_176 ) ;
break;
}
#endif
default:
V_11 = - V_37 ;
break;
}
if ( ! V_11 )
V_11 = F_7 ( V_9 ) ;
return V_11 ;
}
int F_95 ( struct V_1 * V_9 ,
struct V_180 * V_181 )
{
return - V_37 ;
}
int F_96 ( struct V_1 * V_9 ,
struct V_180 * V_181 )
{
return - V_37 ;
}
long F_97 ( struct V_87 * V_88 ,
unsigned int V_89 , unsigned long V_90 )
{
struct V_1 * V_9 = V_88 -> V_182 ;
void T_3 * V_183 = ( void T_3 * ) V_90 ;
long V_11 ;
switch ( V_89 ) {
case V_184 : {
struct V_168 V_169 ;
V_11 = - V_179 ;
if ( F_93 ( & V_169 , V_183 , sizeof( V_169 ) ) )
goto V_31;
V_11 = F_88 ( V_9 , & V_169 ) ;
goto V_31;
}
case V_185 :
{
struct V_171 V_172 ;
V_11 = - V_179 ;
if ( F_93 ( & V_172 , V_183 , sizeof( V_172 ) ) )
goto V_31;
V_11 = F_92 ( V_9 , & V_172 ) ;
break;
}
case V_186 :
case V_187 :
{
struct V_188 V_189 ;
V_11 = - V_179 ;
if ( F_93 ( & V_189 , V_183 , sizeof( V_189 ) ) )
goto V_31;
if ( V_89 == V_186 )
V_11 = F_98 ( V_9 , & V_189 ) ;
else
V_11 = F_99 ( V_9 , & V_189 ) ;
break;
}
#if F_5 ( V_27 ) || F_5 ( V_71 )
case V_190 : {
struct V_191 V_192 ;
V_11 = - V_179 ;
if ( F_93 ( & V_192 , V_183 , sizeof( V_192 ) ) )
goto V_31;
V_11 = F_100 ( V_9 , & V_192 ) ;
break;
}
#endif
default:
V_11 = - V_37 ;
}
V_31:
return V_11 ;
}
int F_101 ( struct V_1 * V_9 , struct V_193 * V_194 )
{
return V_195 ;
}
static int F_102 ( struct V_196 * V_197 )
{
V_131 V_198 = 0x3c000000 ;
V_131 V_199 = 0x60000000 ;
V_131 V_200 = 0x60000000 ;
V_131 V_201 = 0x44000002 ;
V_131 V_202 = 0xffff ;
V_197 -> V_203 [ 0 ] = V_198 | ( ( V_204 >> 16 ) & V_202 ) ;
V_197 -> V_203 [ 1 ] = V_199 | ( V_204 & V_202 ) ;
V_197 -> V_203 [ 2 ] = V_201 ;
V_197 -> V_203 [ 3 ] = V_200 ;
return 0 ;
}
long F_103 ( struct V_87 * V_88 ,
unsigned int V_89 , unsigned long V_90 )
{
void T_3 * V_183 = ( void T_3 * ) V_90 ;
long V_11 ;
switch ( V_89 ) {
case V_205 : {
struct V_196 V_197 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_11 = F_102 ( & V_197 ) ;
if ( F_104 ( V_183 , & V_197 , sizeof( V_197 ) ) ) {
V_11 = - V_179 ;
goto V_31;
}
break;
}
#ifdef F_35
case V_206 : {
struct V_207 V_208 ;
struct V_54 * V_54 = V_88 -> V_182 ;
V_11 = - V_179 ;
if ( F_93 ( & V_208 , V_183 , sizeof( V_208 ) ) )
goto V_31;
V_11 = F_105 ( V_54 , & V_208 ) ;
goto V_31;
}
#endif
#ifdef F_8
case V_209 : {
struct V_54 * V_54 = V_88 -> V_182 ;
struct V_210 V_211 ;
V_11 = F_106 ( V_54 , & V_211 ) ;
if ( V_11 >= 0 && F_104 ( V_183 , & V_211 , sizeof( V_211 ) ) )
V_11 = - V_179 ;
break;
}
case V_212 : {
struct V_54 * V_54 = V_88 -> V_182 ;
V_131 V_213 ;
V_11 = - V_179 ;
if ( F_107 ( V_213 , ( V_131 T_3 * ) V_183 ) )
break;
V_11 = F_108 ( V_54 , & V_213 ) ;
if ( V_11 )
break;
V_11 = - V_179 ;
if ( F_109 ( V_213 , ( V_131 T_3 * ) V_183 ) )
break;
V_11 = 0 ;
break;
}
#endif
#ifdef F_35
case V_214 : {
struct V_54 * V_54 = V_88 -> V_182 ;
struct V_215 V_216 ;
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_11 = F_110 ( V_54 , & V_216 ) ;
if ( V_11 >= 0 && F_104 ( V_183 , & V_216 , sizeof( V_216 ) ) )
V_11 = - V_179 ;
break;
}
#endif
default:
V_11 = - V_217 ;
}
V_31:
return V_11 ;
}
long F_111 ( void )
{
long V_218 ;
do {
V_218 = F_112 ( V_219 , V_220 ) ;
if ( V_218 >= V_221 ) {
F_113 ( L_4 , V_50 ) ;
return - V_222 ;
}
} while ( F_114 ( V_218 , V_219 ) );
return V_218 ;
}
void F_115 ( long V_218 )
{
F_116 ( V_218 , V_219 ) ;
}
void F_117 ( long V_218 )
{
F_118 ( V_218 , V_219 ) ;
}
void F_119 ( unsigned long V_223 )
{
V_221 = F_120 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_219 , 0 , sizeof( V_219 ) ) ;
}
int F_121 ( void * V_224 )
{
return 0 ;
}
void F_122 ( void )
{
}
