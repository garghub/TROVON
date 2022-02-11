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
V_11 = 1 ;
break;
#endif
#ifdef F_8
case V_76 :
V_11 = V_77 ;
break;
case V_78 :
V_11 = 1 ;
if ( F_10 ( V_79 ) )
V_11 = 2 ;
break;
case V_80 :
V_11 = F_10 ( V_81 ) ? 1 : 0 ;
break;
#endif
case V_82 :
#ifdef F_8
V_11 = F_36 () ;
#else
V_11 = F_37 () ;
#endif
break;
case V_83 :
V_11 = V_84 ;
break;
#ifdef F_35
case V_85 :
V_11 = 1 ;
break;
#endif
default:
V_11 = 0 ;
break;
}
return V_11 ;
}
long F_38 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
return - V_37 ;
}
void F_39 ( struct V_90 * free ,
struct V_90 * V_91 )
{
}
int F_40 ( struct V_90 * V_92 , unsigned long V_93 )
{
return 0 ;
}
int F_41 ( struct V_54 * V_54 ,
struct V_90 * V_94 ,
struct V_90 V_95 ,
struct V_96 * V_97 ,
int V_98 )
{
return F_42 ( V_54 , V_97 ) ;
}
void F_43 ( struct V_54 * V_54 ,
struct V_96 * V_97 ,
struct V_90 V_95 ,
int V_98 )
{
F_44 ( V_54 , V_97 ) ;
}
void F_45 ( struct V_54 * V_54 )
{
}
struct V_1 * F_46 ( struct V_54 * V_54 , unsigned int V_99 )
{
struct V_1 * V_9 ;
V_9 = F_47 ( V_54 , V_99 ) ;
if ( ! F_48 ( V_9 ) ) {
V_9 -> V_3 . V_100 = & V_9 -> V_101 ;
F_49 ( V_9 , V_99 ) ;
}
return V_9 ;
}
void F_26 ( struct V_1 * V_9 )
{
F_50 ( & V_9 -> V_3 . V_102 ) ;
F_51 ( & V_9 -> V_3 . V_103 ) ;
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
enum V_104 F_57 ( struct V_105 * V_106 )
{
struct V_1 * V_9 ;
V_9 = F_58 ( V_106 , struct V_1 , V_3 . V_102 ) ;
F_59 ( & V_9 -> V_3 . V_103 ) ;
return V_107 ;
}
int F_60 ( struct V_1 * V_9 )
{
F_61 ( & V_9 -> V_3 . V_102 , V_108 , V_109 ) ;
F_62 ( & V_9 -> V_3 . V_103 , V_110 , ( V_111 ) V_9 ) ;
V_9 -> V_3 . V_102 . V_112 = F_57 ;
V_9 -> V_3 . V_113 = ~ ( V_114 ) 0 ;
#ifdef F_63
F_64 ( & V_9 -> V_3 . V_115 ) ;
#endif
return 0 ;
}
void F_65 ( struct V_1 * V_9 )
{
F_66 ( V_9 ) ;
}
void F_67 ( struct V_1 * V_9 , int V_116 )
{
#ifdef F_34
F_68 ( V_117 , V_9 -> V_3 . V_118 ) ;
#endif
F_69 ( V_9 , V_116 ) ;
V_9 -> V_116 = F_70 () ;
}
void F_71 ( struct V_1 * V_9 )
{
F_72 ( V_9 ) ;
#ifdef F_34
V_9 -> V_3 . V_118 = F_73 ( V_117 ) ;
#endif
V_9 -> V_116 = - 1 ;
}
int F_74 ( struct V_1 * V_9 ,
struct V_119 * V_120 )
{
return - V_37 ;
}
static void F_75 ( struct V_1 * V_9 ,
struct V_38 * V_39 )
{
F_6 ( V_9 , V_9 -> V_3 . V_121 , V_39 -> V_122 . V_123 ) ;
}
static void F_76 ( struct V_1 * V_9 ,
struct V_38 * V_39 )
{
V_114 V_124 ( V_125 ) ;
if ( V_39 -> V_126 . V_127 > sizeof( V_125 ) ) {
F_13 ( V_128 L_2 , V_39 -> V_126 . V_127 ) ;
return;
}
if ( V_9 -> V_3 . V_129 ) {
switch ( V_39 -> V_126 . V_127 ) {
case 8 : V_125 = * ( V_114 * ) V_39 -> V_126 . V_123 ; break;
case 4 : V_125 = * ( V_130 * ) V_39 -> V_126 . V_123 ; break;
case 2 : V_125 = * ( V_131 * ) V_39 -> V_126 . V_123 ; break;
case 1 : V_125 = * ( V_132 * ) V_39 -> V_126 . V_123 ; break;
}
} else {
switch ( V_39 -> V_126 . V_127 ) {
case 4 : V_125 = F_77 ( ( V_130 * ) V_39 -> V_126 . V_123 ) ; break;
case 2 : V_125 = F_78 ( ( V_131 * ) V_39 -> V_126 . V_123 ) ; break;
case 1 : V_125 = * ( V_132 * ) V_39 -> V_126 . V_123 ; break;
}
}
if ( V_9 -> V_3 . V_133 ) {
switch ( V_39 -> V_126 . V_127 ) {
#ifdef F_79
case 4 :
V_125 = ( V_134 ) ( V_135 ) V_125 ;
break;
#endif
case 2 :
V_125 = ( V_134 ) ( V_136 ) V_125 ;
break;
case 1 :
V_125 = ( V_134 ) ( V_137 ) V_125 ;
break;
}
}
F_6 ( V_9 , V_9 -> V_3 . V_121 , V_125 ) ;
switch ( V_9 -> V_3 . V_121 & V_138 ) {
case V_139 :
F_6 ( V_9 , V_9 -> V_3 . V_121 , V_125 ) ;
break;
case V_140 :
V_9 -> V_3 . V_141 [ V_9 -> V_3 . V_121 & V_142 ] = V_125 ;
break;
#ifdef V_26
case V_143 :
V_9 -> V_3 . V_144 [ V_9 -> V_3 . V_121 & V_142 ] = V_125 ;
break;
case V_145 :
V_9 -> V_3 . V_141 [ V_9 -> V_3 . V_121 & V_142 ] = V_125 ;
V_9 -> V_3 . V_144 [ V_9 -> V_3 . V_121 & V_142 ] = V_125 ;
break;
#endif
default:
F_15 () ;
}
}
int F_80 ( struct V_38 * V_39 , struct V_1 * V_9 ,
unsigned int V_146 , unsigned int V_147 , int V_148 )
{
if ( V_147 > sizeof( V_39 -> V_126 . V_123 ) ) {
F_13 ( V_128 L_3 , V_50 ,
V_39 -> V_126 . V_127 ) ;
}
V_39 -> V_126 . V_149 = V_9 -> V_3 . V_150 ;
V_39 -> V_126 . V_127 = V_147 ;
V_39 -> V_126 . V_151 = 0 ;
V_9 -> V_3 . V_121 = V_146 ;
V_9 -> V_3 . V_129 = V_148 ;
V_9 -> V_152 = 1 ;
V_9 -> V_153 = 0 ;
V_9 -> V_3 . V_133 = 0 ;
return V_44 ;
}
int F_81 ( struct V_38 * V_39 , struct V_1 * V_9 ,
unsigned int V_146 , unsigned int V_147 , int V_148 )
{
int V_11 ;
V_11 = F_80 ( V_39 , V_9 , V_146 , V_147 , V_148 ) ;
V_9 -> V_3 . V_133 = 1 ;
return V_11 ;
}
int F_82 ( struct V_38 * V_39 , struct V_1 * V_9 ,
V_114 V_154 , unsigned int V_147 , int V_148 )
{
void * V_123 = V_39 -> V_126 . V_123 ;
if ( V_147 > sizeof( V_39 -> V_126 . V_123 ) ) {
F_13 ( V_128 L_3 , V_50 ,
V_39 -> V_126 . V_127 ) ;
}
V_39 -> V_126 . V_149 = V_9 -> V_3 . V_150 ;
V_39 -> V_126 . V_127 = V_147 ;
V_39 -> V_126 . V_151 = 1 ;
V_9 -> V_152 = 1 ;
V_9 -> V_153 = 1 ;
if ( V_148 ) {
switch ( V_147 ) {
case 8 : * ( V_114 * ) V_123 = V_154 ; break;
case 4 : * ( V_130 * ) V_123 = V_154 ; break;
case 2 : * ( V_131 * ) V_123 = V_154 ; break;
case 1 : * ( V_132 * ) V_123 = V_154 ; break;
}
} else {
switch ( V_147 ) {
case 4 : F_83 ( V_123 , V_154 ) ; break;
case 2 : F_84 ( V_123 , V_154 ) ; break;
case 1 : * ( V_132 * ) V_123 = V_154 ; break;
}
}
return V_44 ;
}
int F_85 ( struct V_1 * V_9 , struct V_38 * V_39 )
{
int V_11 ;
T_2 V_155 ;
if ( V_9 -> V_156 )
F_86 ( V_157 , & V_9 -> V_158 , & V_155 ) ;
if ( V_9 -> V_152 ) {
if ( ! V_9 -> V_153 )
F_76 ( V_9 , V_39 ) ;
V_9 -> V_152 = 0 ;
} else if ( V_9 -> V_3 . V_159 ) {
if ( ! V_9 -> V_3 . V_160 )
F_75 ( V_9 , V_39 ) ;
V_9 -> V_3 . V_159 = 0 ;
} else if ( V_9 -> V_3 . V_161 ) {
V_114 * V_162 = V_39 -> V_163 . V_162 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < 32 ; V_55 ++ )
F_6 ( V_9 , V_55 , V_162 [ V_55 ] ) ;
V_9 -> V_3 . V_161 = 0 ;
} else if ( V_9 -> V_3 . V_164 ) {
int V_55 ;
F_6 ( V_9 , 3 , V_39 -> V_165 . V_166 ) ;
for ( V_55 = 0 ; V_55 < 9 ; ++ V_55 )
F_6 ( V_9 , 4 + V_55 , V_39 -> V_165 . args [ V_55 ] ) ;
V_9 -> V_3 . V_164 = 0 ;
}
V_11 = F_87 ( V_39 , V_9 ) ;
if ( V_9 -> V_156 )
F_86 ( V_157 , & V_155 , NULL ) ;
return V_11 ;
}
int F_88 ( struct V_1 * V_9 , struct V_167 * V_168 )
{
if ( V_168 -> V_168 == V_169 ) {
F_89 ( V_9 , V_168 ) ;
return 0 ;
}
F_90 ( V_9 , V_168 ) ;
F_91 ( V_9 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_9 ,
struct V_170 * V_171 )
{
int V_11 ;
if ( V_171 -> V_172 )
return - V_37 ;
switch ( V_171 -> V_171 ) {
case V_69 :
V_11 = 0 ;
V_9 -> V_3 . V_173 = true ;
break;
case V_63 :
V_11 = 0 ;
V_9 -> V_3 . V_34 = true ;
break;
#if F_5 ( V_27 ) || F_5 ( V_71 )
case V_72 : {
struct V_174 V_175 ;
void T_3 * V_176 = ( void T_3 * ) ( V_177 ) V_171 -> args [ 0 ] ;
V_11 = - V_178 ;
if ( F_93 ( & V_175 , V_176 , sizeof( V_175 ) ) )
break;
V_11 = F_94 ( V_9 , & V_175 ) ;
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
struct V_179 * V_180 )
{
return - V_37 ;
}
int F_96 ( struct V_1 * V_9 ,
struct V_179 * V_180 )
{
return - V_37 ;
}
long F_97 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_1 * V_9 = V_87 -> V_181 ;
void T_3 * V_182 = ( void T_3 * ) V_89 ;
long V_11 ;
switch ( V_88 ) {
case V_183 : {
struct V_167 V_168 ;
V_11 = - V_178 ;
if ( F_93 ( & V_168 , V_182 , sizeof( V_168 ) ) )
goto V_31;
V_11 = F_88 ( V_9 , & V_168 ) ;
goto V_31;
}
case V_184 :
{
struct V_170 V_171 ;
V_11 = - V_178 ;
if ( F_93 ( & V_171 , V_182 , sizeof( V_171 ) ) )
goto V_31;
V_11 = F_92 ( V_9 , & V_171 ) ;
break;
}
case V_185 :
case V_186 :
{
struct V_187 V_188 ;
V_11 = - V_178 ;
if ( F_93 ( & V_188 , V_182 , sizeof( V_188 ) ) )
goto V_31;
if ( V_88 == V_185 )
V_11 = F_98 ( V_9 , & V_188 ) ;
else
V_11 = F_99 ( V_9 , & V_188 ) ;
break;
}
#if F_5 ( V_27 ) || F_5 ( V_71 )
case V_189 : {
struct V_190 V_191 ;
V_11 = - V_178 ;
if ( F_93 ( & V_191 , V_182 , sizeof( V_191 ) ) )
goto V_31;
V_11 = F_100 ( V_9 , & V_191 ) ;
break;
}
#endif
default:
V_11 = - V_37 ;
}
V_31:
return V_11 ;
}
int F_101 ( struct V_1 * V_9 , struct V_192 * V_193 )
{
return V_194 ;
}
static int F_102 ( struct V_195 * V_196 )
{
V_130 V_197 = 0x3c000000 ;
V_130 V_198 = 0x60000000 ;
V_130 V_199 = 0x60000000 ;
V_130 V_200 = 0x44000002 ;
V_130 V_201 = 0xffff ;
V_196 -> V_202 [ 0 ] = V_197 | ( ( V_203 >> 16 ) & V_201 ) ;
V_196 -> V_202 [ 1 ] = V_198 | ( V_203 & V_201 ) ;
V_196 -> V_202 [ 2 ] = V_200 ;
V_196 -> V_202 [ 3 ] = V_199 ;
return 0 ;
}
long F_103 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
void T_3 * V_182 = ( void T_3 * ) V_89 ;
long V_11 ;
switch ( V_88 ) {
case V_204 : {
struct V_195 V_196 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_11 = F_102 ( & V_196 ) ;
if ( F_104 ( V_182 , & V_196 , sizeof( V_196 ) ) ) {
V_11 = - V_178 ;
goto V_31;
}
break;
}
#ifdef F_35
case V_205 : {
struct V_206 V_207 ;
struct V_54 * V_54 = V_87 -> V_181 ;
V_11 = - V_178 ;
if ( F_93 ( & V_207 , V_182 , sizeof( V_207 ) ) )
goto V_31;
V_11 = F_105 ( V_54 , & V_207 ) ;
goto V_31;
}
#endif
#ifdef F_8
case V_208 : {
struct V_54 * V_54 = V_87 -> V_181 ;
struct V_209 V_210 ;
V_11 = F_106 ( V_54 , & V_210 ) ;
if ( V_11 >= 0 && F_104 ( V_182 , & V_210 , sizeof( V_210 ) ) )
V_11 = - V_178 ;
break;
}
#endif
#ifdef F_35
case V_211 : {
struct V_54 * V_54 = V_87 -> V_181 ;
struct V_212 V_213 ;
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
V_11 = F_107 ( V_54 , & V_213 ) ;
if ( V_11 >= 0 && F_104 ( V_182 , & V_213 , sizeof( V_213 ) ) )
V_11 = - V_178 ;
break;
}
#endif
default:
V_11 = - V_214 ;
}
V_31:
return V_11 ;
}
long F_108 ( void )
{
long V_215 ;
do {
V_215 = F_109 ( V_216 , V_217 ) ;
if ( V_215 >= V_218 ) {
F_110 ( L_4 , V_50 ) ;
return - V_219 ;
}
} while ( F_111 ( V_215 , V_216 ) );
return V_215 ;
}
void F_112 ( long V_215 )
{
F_113 ( V_215 , V_216 ) ;
}
void F_114 ( long V_215 )
{
F_115 ( V_215 , V_216 ) ;
}
void F_116 ( unsigned long V_220 )
{
V_218 = F_117 (unsigned long, KVMPPC_NR_LPIDS, nr_lpids_param) ;
memset ( V_216 , 0 , sizeof( V_216 ) ) ;
}
int F_118 ( void * V_221 )
{
return 0 ;
}
void F_119 ( void )
{
}
