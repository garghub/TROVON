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
if ( ! V_92 || free -> V_3 . V_93 != V_92 -> V_3 . V_93 ) {
F_40 ( free -> V_3 . V_93 ) ;
free -> V_3 . V_93 = NULL ;
}
}
int F_41 ( struct V_91 * V_94 , unsigned long V_95 )
{
V_94 -> V_3 . V_93 = F_42 ( V_95 * sizeof( * V_94 -> V_3 . V_93 ) ) ;
if ( ! V_94 -> V_3 . V_93 )
return - V_96 ;
return 0 ;
}
int F_43 ( struct V_54 * V_54 ,
struct V_91 * V_97 ,
struct V_91 V_98 ,
struct V_99 * V_100 ,
int V_101 )
{
return F_44 ( V_54 , V_100 ) ;
}
void F_45 ( struct V_54 * V_54 ,
struct V_99 * V_100 ,
struct V_91 V_98 ,
int V_101 )
{
F_46 ( V_54 , V_100 ) ;
}
void F_47 ( struct V_54 * V_54 )
{
}
void F_48 ( struct V_54 * V_54 ,
struct V_91 * V_94 )
{
}
struct V_1 * F_49 ( struct V_54 * V_54 , unsigned int V_102 )
{
struct V_1 * V_9 ;
V_9 = F_50 ( V_54 , V_102 ) ;
if ( ! F_51 ( V_9 ) ) {
V_9 -> V_3 . V_103 = & V_9 -> V_104 ;
F_52 ( V_9 , V_102 ) ;
}
return V_9 ;
}
void F_26 ( struct V_1 * V_9 )
{
F_53 ( & V_9 -> V_3 . V_105 ) ;
F_54 ( & V_9 -> V_3 . V_106 ) ;
F_55 ( V_9 ) ;
F_56 ( V_9 ) ;
}
void F_57 ( struct V_1 * V_9 )
{
F_26 ( V_9 ) ;
}
int F_58 ( struct V_1 * V_9 )
{
return F_59 ( V_9 ) ;
}
enum V_107 F_60 ( struct V_108 * V_109 )
{
struct V_1 * V_9 ;
V_9 = F_61 ( V_109 , struct V_1 , V_3 . V_105 ) ;
F_62 ( & V_9 -> V_3 . V_106 ) ;
return V_110 ;
}
int F_63 ( struct V_1 * V_9 )
{
F_64 ( & V_9 -> V_3 . V_105 , V_111 , V_112 ) ;
F_65 ( & V_9 -> V_3 . V_106 , V_113 , ( V_114 ) V_9 ) ;
V_9 -> V_3 . V_105 . V_115 = F_60 ;
V_9 -> V_3 . V_116 = ~ ( V_117 ) 0 ;
#ifdef F_66
F_67 ( & V_9 -> V_3 . V_118 ) ;
#endif
return 0 ;
}
void F_68 ( struct V_1 * V_9 )
{
F_69 ( V_9 ) ;
}
void F_70 ( struct V_1 * V_9 , int V_119 )
{
#ifdef F_34
F_71 ( V_120 , V_9 -> V_3 . V_121 ) ;
#endif
F_72 ( V_9 , V_119 ) ;
V_9 -> V_119 = F_73 () ;
}
void F_74 ( struct V_1 * V_9 )
{
F_75 ( V_9 ) ;
#ifdef F_34
V_9 -> V_3 . V_121 = F_76 ( V_120 ) ;
#endif
V_9 -> V_119 = - 1 ;
}
int F_77 ( struct V_1 * V_9 ,
struct V_122 * V_123 )
{
return - V_37 ;
}
static void F_78 ( struct V_1 * V_9 ,
struct V_38 * V_39 )
{
F_6 ( V_9 , V_9 -> V_3 . V_124 , V_39 -> V_125 . V_126 ) ;
}
static void F_79 ( struct V_1 * V_9 ,
struct V_38 * V_39 )
{
V_117 V_127 ( V_128 ) ;
if ( V_39 -> V_129 . V_130 > sizeof( V_128 ) ) {
F_13 ( V_131 L_2 , V_39 -> V_129 . V_130 ) ;
return;
}
if ( V_9 -> V_3 . V_132 ) {
switch ( V_39 -> V_129 . V_130 ) {
case 8 : V_128 = * ( V_117 * ) V_39 -> V_129 . V_126 ; break;
case 4 : V_128 = * ( V_133 * ) V_39 -> V_129 . V_126 ; break;
case 2 : V_128 = * ( V_134 * ) V_39 -> V_129 . V_126 ; break;
case 1 : V_128 = * ( V_135 * ) V_39 -> V_129 . V_126 ; break;
}
} else {
switch ( V_39 -> V_129 . V_130 ) {
case 4 : V_128 = F_80 ( ( V_133 * ) V_39 -> V_129 . V_126 ) ; break;
case 2 : V_128 = F_81 ( ( V_134 * ) V_39 -> V_129 . V_126 ) ; break;
case 1 : V_128 = * ( V_135 * ) V_39 -> V_129 . V_126 ; break;
}
}
if ( V_9 -> V_3 . V_136 ) {
switch ( V_39 -> V_129 . V_130 ) {
#ifdef F_82
case 4 :
V_128 = ( V_137 ) ( V_138 ) V_128 ;
break;
#endif
case 2 :
V_128 = ( V_137 ) ( V_139 ) V_128 ;
break;
case 1 :
V_128 = ( V_137 ) ( V_140 ) V_128 ;
break;
}
}
F_6 ( V_9 , V_9 -> V_3 . V_124 , V_128 ) ;
switch ( V_9 -> V_3 . V_124 & V_141 ) {
case V_142 :
F_6 ( V_9 , V_9 -> V_3 . V_124 , V_128 ) ;
break;
case V_143 :
V_9 -> V_3 . V_144 [ V_9 -> V_3 . V_124 & V_145 ] = V_128 ;
break;
#ifdef V_26
case V_146 :
V_9 -> V_3 . V_147 [ V_9 -> V_3 . V_124 & V_145 ] = V_128 ;
break;
case V_148 :
V_9 -> V_3 . V_144 [ V_9 -> V_3 . V_124 & V_145 ] = V_128 ;
V_9 -> V_3 . V_147 [ V_9 -> V_3 . V_124 & V_145 ] = V_128 ;
break;
#endif
default:
F_15 () ;
}
}
int F_83 ( struct V_38 * V_39 , struct V_1 * V_9 ,
unsigned int V_149 , unsigned int V_150 , int V_151 )
{
if ( V_150 > sizeof( V_39 -> V_129 . V_126 ) ) {
F_13 ( V_131 L_3 , V_50 ,
V_39 -> V_129 . V_130 ) ;
}
V_39 -> V_129 . V_152 = V_9 -> V_3 . V_153 ;
V_39 -> V_129 . V_130 = V_150 ;
V_39 -> V_129 . V_154 = 0 ;
V_9 -> V_3 . V_124 = V_149 ;
V_9 -> V_3 . V_132 = V_151 ;
V_9 -> V_155 = 1 ;
V_9 -> V_156 = 0 ;
V_9 -> V_3 . V_136 = 0 ;
return V_44 ;
}
int F_84 ( struct V_38 * V_39 , struct V_1 * V_9 ,
unsigned int V_149 , unsigned int V_150 , int V_151 )
{
int V_11 ;
V_11 = F_83 ( V_39 , V_9 , V_149 , V_150 , V_151 ) ;
V_9 -> V_3 . V_136 = 1 ;
return V_11 ;
}
int F_85 ( struct V_38 * V_39 , struct V_1 * V_9 ,
V_117 V_157 , unsigned int V_150 , int V_151 )
{
void * V_126 = V_39 -> V_129 . V_126 ;
if ( V_150 > sizeof( V_39 -> V_129 . V_126 ) ) {
F_13 ( V_131 L_3 , V_50 ,
V_39 -> V_129 . V_130 ) ;
}
V_39 -> V_129 . V_152 = V_9 -> V_3 . V_153 ;
V_39 -> V_129 . V_130 = V_150 ;
V_39 -> V_129 . V_154 = 1 ;
V_9 -> V_155 = 1 ;
V_9 -> V_156 = 1 ;
if ( V_151 ) {
switch ( V_150 ) {
case 8 : * ( V_117 * ) V_126 = V_157 ; break;
case 4 : * ( V_133 * ) V_126 = V_157 ; break;
case 2 : * ( V_134 * ) V_126 = V_157 ; break;
case 1 : * ( V_135 * ) V_126 = V_157 ; break;
}
} else {
switch ( V_150 ) {
case 4 : F_86 ( V_126 , V_157 ) ; break;
case 2 : F_87 ( V_126 , V_157 ) ; break;
case 1 : * ( V_135 * ) V_126 = V_157 ; break;
}
}
return V_44 ;
}
int F_88 ( struct V_1 * V_9 , struct V_38 * V_39 )
{
int V_11 ;
T_2 V_158 ;
if ( V_9 -> V_159 )
F_89 ( V_160 , & V_9 -> V_161 , & V_158 ) ;
if ( V_9 -> V_155 ) {
if ( ! V_9 -> V_156 )
F_79 ( V_9 , V_39 ) ;
V_9 -> V_155 = 0 ;
} else if ( V_9 -> V_3 . V_162 ) {
if ( ! V_9 -> V_3 . V_163 )
F_78 ( V_9 , V_39 ) ;
V_9 -> V_3 . V_162 = 0 ;
} else if ( V_9 -> V_3 . V_164 ) {
V_117 * V_165 = V_39 -> V_166 . V_165 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < 32 ; V_55 ++ )
F_6 ( V_9 , V_55 , V_165 [ V_55 ] ) ;
V_9 -> V_3 . V_164 = 0 ;
} else if ( V_9 -> V_3 . V_167 ) {
int V_55 ;
F_6 ( V_9 , 3 , V_39 -> V_168 . V_169 ) ;
for ( V_55 = 0 ; V_55 < 9 ; ++ V_55 )
F_6 ( V_9 , 4 + V_55 , V_39 -> V_168 . args [ V_55 ] ) ;
V_9 -> V_3 . V_167 = 0 ;
}
V_11 = F_90 ( V_39 , V_9 ) ;
if ( V_9 -> V_159 )
F_89 ( V_160 , & V_158 , NULL ) ;
return V_11 ;
}
int F_91 ( struct V_1 * V_9 , struct V_170 * V_171 )
{
if ( V_171 -> V_171 == V_172 ) {
F_92 ( V_9 , V_171 ) ;
return 0 ;
}
F_93 ( V_9 , V_171 ) ;
F_94 ( V_9 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_9 ,
struct V_173 * V_174 )
{
int V_11 ;
if ( V_174 -> V_175 )
return - V_37 ;
switch ( V_174 -> V_174 ) {
case V_69 :
V_11 = 0 ;
V_9 -> V_3 . V_176 = true ;
break;
case V_63 :
V_11 = 0 ;
V_9 -> V_3 . V_34 = true ;
break;
#if F_5 ( V_27 ) || F_5 ( V_71 )
case V_72 : {
struct V_177 V_178 ;
void T_3 * V_179 = ( void T_3 * ) ( V_180 ) V_174 -> args [ 0 ] ;
V_11 = - V_181 ;
if ( F_96 ( & V_178 , V_179 , sizeof( V_178 ) ) )
break;
V_11 = F_97 ( V_9 , & V_178 ) ;
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
int F_98 ( struct V_1 * V_9 ,
struct V_182 * V_183 )
{
return - V_37 ;
}
int F_99 ( struct V_1 * V_9 ,
struct V_182 * V_183 )
{
return - V_37 ;
}
long F_100 ( struct V_87 * V_88 ,
unsigned int V_89 , unsigned long V_90 )
{
struct V_1 * V_9 = V_88 -> V_184 ;
void T_3 * V_185 = ( void T_3 * ) V_90 ;
long V_11 ;
switch ( V_89 ) {
case V_186 : {
struct V_170 V_171 ;
V_11 = - V_181 ;
if ( F_96 ( & V_171 , V_185 , sizeof( V_171 ) ) )
goto V_31;
V_11 = F_91 ( V_9 , & V_171 ) ;
goto V_31;
}
case V_187 :
{
struct V_173 V_174 ;
V_11 = - V_181 ;
if ( F_96 ( & V_174 , V_185 , sizeof( V_174 ) ) )
goto V_31;
V_11 = F_95 ( V_9 , & V_174 ) ;
break;
}
case V_188 :
case V_189 :
{
struct V_190 V_191 ;
V_11 = - V_181 ;
if ( F_96 ( & V_191 , V_185 , sizeof( V_191 ) ) )
goto V_31;
if ( V_89 == V_188 )
V_11 = F_101 ( V_9 , & V_191 ) ;
else
V_11 = F_102 ( V_9 , & V_191 ) ;
break;
}
#if F_5 ( V_27 ) || F_5 ( V_71 )
case V_192 : {
struct V_193 V_194 ;
V_11 = - V_181 ;
if ( F_96 ( & V_194 , V_185 , sizeof( V_194 ) ) )
goto V_31;
V_11 = F_103 ( V_9 , & V_194 ) ;
break;
}
#endif
default:
V_11 = - V_37 ;
}
V_31:
return V_11 ;
}
int F_104 ( struct V_1 * V_9 , struct V_195 * V_196 )
{
return V_197 ;
}
static int F_105 ( struct V_198 * V_199 )
{
V_133 V_200 = 0x3c000000 ;
V_133 V_201 = 0x60000000 ;
V_133 V_202 = 0x60000000 ;
V_133 V_203 = 0x44000002 ;
V_133 V_204 = 0xffff ;
V_199 -> V_205 [ 0 ] = V_200 | ( ( V_206 >> 16 ) & V_204 ) ;
V_199 -> V_205 [ 1 ] = V_201 | ( V_206 & V_204 ) ;
V_199 -> V_205 [ 2 ] = V_203 ;
V_199 -> V_205 [ 3 ] = V_202 ;
return 0 ;
}
long F_106 ( struct V_87 * V_88 ,
unsigned int V_89 , unsigned long V_90 )
{
void T_3 * V_185 = ( void T_3 * ) V_90 ;
long V_11 ;
switch ( V_89 ) {
case V_207 : {
struct V_198 V_199 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_11 = F_105 ( & V_199 ) ;
if ( F_107 ( V_185 , & V_199 , sizeof( V_199 ) ) ) {
V_11 = - V_181 ;
goto V_31;
}
break;
}
#ifdef F_35
case V_208 : {
struct V_209 V_210 ;
struct V_54 * V_54 = V_88 -> V_184 ;
V_11 = - V_181 ;
if ( F_96 ( & V_210 , V_185 , sizeof( V_210 ) ) )
goto V_31;
V_11 = F_108 ( V_54 , & V_210 ) ;
goto V_31;
}
#endif
#ifdef F_8
case V_211 : {
struct V_54 * V_54 = V_88 -> V_184 ;
struct V_212 V_213 ;
V_11 = F_109 ( V_54 , & V_213 ) ;
if ( V_11 >= 0 && F_107 ( V_185 , & V_213 , sizeof( V_213 ) ) )
V_11 = - V_181 ;
break;
}
case V_214 : {
struct V_54 * V_54 = V_88 -> V_184 ;
V_133 V_215 ;
V_11 = - V_181 ;
if ( F_110 ( V_215 , ( V_133 T_3 * ) V_185 ) )
break;
V_11 = F_111 ( V_54 , & V_215 ) ;
if ( V_11 )
break;
V_11 = - V_181 ;
if ( F_112 ( V_215 , ( V_133 T_3 * ) V_185 ) )
break;
V_11 = 0 ;
break;
}
#endif
#ifdef F_35
case V_216 : {
struct V_54 * V_54 = V_88 -> V_184 ;
struct V_217 V_218 ;
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
V_11 = F_113 ( V_54 , & V_218 ) ;
if ( V_11 >= 0 && F_107 ( V_185 , & V_218 , sizeof( V_218 ) ) )
V_11 = - V_181 ;
break;
}
#endif
default:
V_11 = - V_219 ;
}
V_31:
return V_11 ;
}
long F_114 ( void )
{
long V_220 ;
do {
V_220 = F_115 ( V_221 , V_222 ) ;
if ( V_220 >= V_223 ) {
F_116 ( L_4 , V_50 ) ;
return - V_96 ;
}
} while ( F_117 ( V_220 , V_221 ) );
return V_220 ;
}
void F_118 ( long V_220 )
{
F_119 ( V_220 , V_221 ) ;
}
void F_120 ( long V_220 )
{
F_121 ( V_220 , V_221 ) ;
}
void F_122 ( unsigned long V_224 )
{
V_223 = F_123 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_221 , 0 , sizeof( V_221 ) ) ;
}
int F_124 ( void * V_225 )
{
return 0 ;
}
void F_125 ( void )
{
}
