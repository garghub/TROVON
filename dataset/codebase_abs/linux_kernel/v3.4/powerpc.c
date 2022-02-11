int F_1 ( struct V_1 * V_2 )
{
return ! ( V_2 -> V_3 . V_4 -> V_5 & V_6 ) ||
! ! ( V_2 -> V_3 . V_7 ) ||
V_2 -> V_8 ;
}
int F_2 ( struct V_1 * V_9 )
{
int V_10 = F_3 ( V_9 , 11 ) ;
int V_11 ;
unsigned long T_1 V_12 = F_3 ( V_9 , 3 ) ;
unsigned long T_1 V_13 = F_3 ( V_9 , 4 ) ;
unsigned long T_1 V_14 = F_3 ( V_9 , 5 ) ;
unsigned long T_1 V_15 = F_3 ( V_9 , 6 ) ;
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
#if F_4 ( V_26 ) || F_4 ( V_27 )
V_16 |= ( 1 << V_28 ) ;
#endif
break;
default:
V_11 = V_29 ;
break;
}
F_5 ( V_9 , 4 , V_16 ) ;
return V_11 ;
}
int F_6 ( struct V_1 * V_9 )
{
int V_11 = false ;
if ( ! V_9 -> V_3 . V_30 )
goto V_31;
if ( ( V_9 -> V_3 . V_32 != V_33 ) && V_9 -> V_3 . V_34 )
goto V_31;
#ifdef F_7
if ( ! V_9 -> V_3 . V_34 )
goto V_31;
#endif
V_11 = true ;
V_31:
V_9 -> V_3 . V_35 = V_11 ;
return V_11 ? 0 : - V_36 ;
}
int F_8 ( struct V_37 * V_38 , struct V_1 * V_9 )
{
enum V_39 V_40 ;
int V_11 ;
V_40 = F_9 ( V_38 , V_9 ) ;
switch ( V_40 ) {
case V_41 :
V_11 = V_42 ;
break;
case V_43 :
V_38 -> V_44 = V_45 ;
V_11 = V_46 ;
break;
case V_47 :
F_10 ( V_48 L_1 , V_49 ,
F_11 ( V_9 ) ) ;
V_11 = V_50 ;
break;
default:
F_12 () ;
}
return V_11 ;
}
int F_13 ( void * V_51 )
{
return 0 ;
}
void F_14 ( void * V_51 )
{
}
int F_15 ( void )
{
return 0 ;
}
void F_16 ( void )
{
}
void F_17 ( void * V_52 )
{
* ( int * ) V_52 = F_18 () ;
}
int F_19 ( struct V_53 * V_53 , unsigned long type )
{
if ( type )
return - V_36 ;
return F_20 ( V_53 ) ;
}
void F_21 ( struct V_53 * V_53 )
{
unsigned int V_54 ;
struct V_1 * V_9 ;
F_22 (i, vcpu, kvm)
F_23 ( V_9 ) ;
F_24 ( & V_53 -> V_55 ) ;
for ( V_54 = 0 ; V_54 < F_25 ( & V_53 -> V_56 ) ; V_54 ++ )
V_53 -> V_57 [ V_54 ] = NULL ;
F_26 ( & V_53 -> V_56 , 0 ) ;
F_27 ( V_53 ) ;
F_28 ( & V_53 -> V_55 ) ;
}
void F_29 ( struct V_53 * V_53 )
{
}
int F_30 ( long V_58 )
{
int V_11 ;
switch ( V_58 ) {
#ifdef F_31
case V_59 :
#else
case V_60 :
case V_61 :
case V_62 :
#endif
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_11 = 1 ;
break;
#ifndef F_7
case V_67 :
case V_68 :
case V_69 :
#ifdef V_27
case V_70 :
#endif
V_11 = 1 ;
break;
case V_71 :
V_11 = V_72 ;
break;
#endif
#ifdef F_7
case V_73 :
V_11 = 1 ;
break;
case V_74 :
V_11 = V_75 ;
break;
case V_76 :
V_11 = 1 ;
if ( F_32 ( V_77 ) )
V_11 = 2 ;
break;
case V_78 :
V_11 = F_32 ( V_79 ) ? 1 : 0 ;
break;
#endif
case V_80 :
#ifdef F_7
V_11 = F_33 () ;
#else
V_11 = F_34 () ;
#endif
break;
case V_81 :
V_11 = V_82 ;
break;
default:
V_11 = 0 ;
break;
}
return V_11 ;
}
long F_35 ( struct V_83 * V_84 ,
unsigned int V_85 , unsigned long V_86 )
{
return - V_36 ;
}
void F_36 ( struct V_87 * free ,
struct V_87 * V_88 )
{
}
int F_37 ( struct V_87 * V_89 , unsigned long V_90 )
{
return 0 ;
}
int F_38 ( struct V_53 * V_53 ,
struct V_87 * V_91 ,
struct V_87 V_92 ,
struct V_93 * V_94 ,
int V_95 )
{
return F_39 ( V_53 , V_94 ) ;
}
void F_40 ( struct V_53 * V_53 ,
struct V_93 * V_94 ,
struct V_87 V_92 ,
int V_95 )
{
F_41 ( V_53 , V_94 ) ;
}
void F_42 ( struct V_53 * V_53 )
{
}
struct V_1 * F_43 ( struct V_53 * V_53 , unsigned int V_96 )
{
struct V_1 * V_9 ;
V_9 = F_44 ( V_53 , V_96 ) ;
if ( ! F_45 ( V_9 ) ) {
V_9 -> V_3 . V_97 = & V_9 -> V_98 ;
F_46 ( V_9 , V_96 ) ;
}
return V_9 ;
}
void F_23 ( struct V_1 * V_9 )
{
F_47 ( & V_9 -> V_3 . V_99 ) ;
F_48 ( & V_9 -> V_3 . V_100 ) ;
F_49 ( V_9 ) ;
F_50 ( V_9 ) ;
}
void F_51 ( struct V_1 * V_9 )
{
F_23 ( V_9 ) ;
}
int F_52 ( struct V_1 * V_9 )
{
return F_53 ( V_9 ) ;
}
enum V_101 F_54 ( struct V_102 * V_103 )
{
struct V_1 * V_9 ;
V_9 = F_55 ( V_103 , struct V_1 , V_3 . V_99 ) ;
F_56 ( & V_9 -> V_3 . V_100 ) ;
return V_104 ;
}
int F_57 ( struct V_1 * V_9 )
{
F_58 ( & V_9 -> V_3 . V_99 , V_105 , V_106 ) ;
F_59 ( & V_9 -> V_3 . V_100 , V_107 , ( V_108 ) V_9 ) ;
V_9 -> V_3 . V_99 . V_109 = F_54 ;
V_9 -> V_3 . V_110 = ~ ( V_111 ) 0 ;
#ifdef F_60
F_61 ( & V_9 -> V_3 . V_112 ) ;
#endif
return 0 ;
}
void F_62 ( struct V_1 * V_9 )
{
F_63 ( V_9 ) ;
}
void F_64 ( struct V_1 * V_9 , int V_113 )
{
#ifdef F_31
F_65 ( V_114 , V_9 -> V_3 . V_115 ) ;
#endif
F_66 ( V_9 , V_113 ) ;
V_9 -> V_113 = F_67 () ;
}
void F_68 ( struct V_1 * V_9 )
{
F_69 ( V_9 ) ;
#ifdef F_31
V_9 -> V_3 . V_115 = F_70 ( V_114 ) ;
#endif
V_9 -> V_113 = - 1 ;
}
int F_71 ( struct V_1 * V_9 ,
struct V_116 * V_117 )
{
return - V_36 ;
}
static void F_72 ( struct V_1 * V_9 ,
struct V_37 * V_38 )
{
F_5 ( V_9 , V_9 -> V_3 . V_118 , V_38 -> V_119 . V_120 ) ;
}
static void F_73 ( struct V_1 * V_9 ,
struct V_37 * V_38 )
{
V_111 V_121 ( V_122 ) ;
if ( V_38 -> V_123 . V_124 > sizeof( V_122 ) ) {
F_10 ( V_125 L_2 , V_38 -> V_123 . V_124 ) ;
return;
}
if ( V_9 -> V_3 . V_126 ) {
switch ( V_38 -> V_123 . V_124 ) {
case 8 : V_122 = * ( V_111 * ) V_38 -> V_123 . V_120 ; break;
case 4 : V_122 = * ( V_127 * ) V_38 -> V_123 . V_120 ; break;
case 2 : V_122 = * ( V_128 * ) V_38 -> V_123 . V_120 ; break;
case 1 : V_122 = * ( V_129 * ) V_38 -> V_123 . V_120 ; break;
}
} else {
switch ( V_38 -> V_123 . V_124 ) {
case 4 : V_122 = F_74 ( ( V_127 * ) V_38 -> V_123 . V_120 ) ; break;
case 2 : V_122 = F_75 ( ( V_128 * ) V_38 -> V_123 . V_120 ) ; break;
case 1 : V_122 = * ( V_129 * ) V_38 -> V_123 . V_120 ; break;
}
}
if ( V_9 -> V_3 . V_130 ) {
switch ( V_38 -> V_123 . V_124 ) {
#ifdef F_76
case 4 :
V_122 = ( V_131 ) ( V_132 ) V_122 ;
break;
#endif
case 2 :
V_122 = ( V_131 ) ( V_133 ) V_122 ;
break;
case 1 :
V_122 = ( V_131 ) ( V_134 ) V_122 ;
break;
}
}
F_5 ( V_9 , V_9 -> V_3 . V_118 , V_122 ) ;
switch ( V_9 -> V_3 . V_118 & V_135 ) {
case V_136 :
F_5 ( V_9 , V_9 -> V_3 . V_118 , V_122 ) ;
break;
case V_137 :
V_9 -> V_3 . V_138 [ V_9 -> V_3 . V_118 & V_139 ] = V_122 ;
break;
#ifdef V_26
case V_140 :
V_9 -> V_3 . V_141 [ V_9 -> V_3 . V_118 & V_139 ] = V_122 ;
break;
case V_142 :
V_9 -> V_3 . V_138 [ V_9 -> V_3 . V_118 & V_139 ] = V_122 ;
V_9 -> V_3 . V_141 [ V_9 -> V_3 . V_118 & V_139 ] = V_122 ;
break;
#endif
default:
F_12 () ;
}
}
int F_77 ( struct V_37 * V_38 , struct V_1 * V_9 ,
unsigned int V_143 , unsigned int V_144 , int V_145 )
{
if ( V_144 > sizeof( V_38 -> V_123 . V_120 ) ) {
F_10 ( V_125 L_3 , V_49 ,
V_38 -> V_123 . V_124 ) ;
}
V_38 -> V_123 . V_146 = V_9 -> V_3 . V_147 ;
V_38 -> V_123 . V_124 = V_144 ;
V_38 -> V_123 . V_148 = 0 ;
V_9 -> V_3 . V_118 = V_143 ;
V_9 -> V_3 . V_126 = V_145 ;
V_9 -> V_149 = 1 ;
V_9 -> V_150 = 0 ;
V_9 -> V_3 . V_130 = 0 ;
return V_43 ;
}
int F_78 ( struct V_37 * V_38 , struct V_1 * V_9 ,
unsigned int V_143 , unsigned int V_144 , int V_145 )
{
int V_11 ;
V_11 = F_77 ( V_38 , V_9 , V_143 , V_144 , V_145 ) ;
V_9 -> V_3 . V_130 = 1 ;
return V_11 ;
}
int F_79 ( struct V_37 * V_38 , struct V_1 * V_9 ,
V_111 V_151 , unsigned int V_144 , int V_145 )
{
void * V_120 = V_38 -> V_123 . V_120 ;
if ( V_144 > sizeof( V_38 -> V_123 . V_120 ) ) {
F_10 ( V_125 L_3 , V_49 ,
V_38 -> V_123 . V_124 ) ;
}
V_38 -> V_123 . V_146 = V_9 -> V_3 . V_147 ;
V_38 -> V_123 . V_124 = V_144 ;
V_38 -> V_123 . V_148 = 1 ;
V_9 -> V_149 = 1 ;
V_9 -> V_150 = 1 ;
if ( V_145 ) {
switch ( V_144 ) {
case 8 : * ( V_111 * ) V_120 = V_151 ; break;
case 4 : * ( V_127 * ) V_120 = V_151 ; break;
case 2 : * ( V_128 * ) V_120 = V_151 ; break;
case 1 : * ( V_129 * ) V_120 = V_151 ; break;
}
} else {
switch ( V_144 ) {
case 4 : F_80 ( V_120 , V_151 ) ; break;
case 2 : F_81 ( V_120 , V_151 ) ; break;
case 1 : * ( V_129 * ) V_120 = V_151 ; break;
}
}
return V_43 ;
}
int F_82 ( struct V_1 * V_9 , struct V_37 * V_38 )
{
int V_11 ;
T_2 V_152 ;
if ( V_9 -> V_153 )
F_83 ( V_154 , & V_9 -> V_155 , & V_152 ) ;
if ( V_9 -> V_149 ) {
if ( ! V_9 -> V_150 )
F_73 ( V_9 , V_38 ) ;
V_9 -> V_149 = 0 ;
} else if ( V_9 -> V_3 . V_156 ) {
if ( ! V_9 -> V_3 . V_157 )
F_72 ( V_9 , V_38 ) ;
V_9 -> V_3 . V_156 = 0 ;
} else if ( V_9 -> V_3 . V_158 ) {
V_111 * V_159 = V_38 -> V_160 . V_159 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 32 ; V_54 ++ )
F_5 ( V_9 , V_54 , V_159 [ V_54 ] ) ;
V_9 -> V_3 . V_158 = 0 ;
} else if ( V_9 -> V_3 . V_161 ) {
int V_54 ;
F_5 ( V_9 , 3 , V_38 -> V_162 . V_163 ) ;
for ( V_54 = 0 ; V_54 < 9 ; ++ V_54 )
F_5 ( V_9 , 4 + V_54 , V_38 -> V_162 . args [ V_54 ] ) ;
V_9 -> V_3 . V_161 = 0 ;
}
V_11 = F_84 ( V_38 , V_9 ) ;
if ( V_9 -> V_153 )
F_83 ( V_154 , & V_152 , NULL ) ;
return V_11 ;
}
void F_85 ( struct V_1 * V_9 )
{
int V_164 ;
int V_113 = V_9 -> V_113 ;
V_164 = F_86 () ;
if ( F_87 ( V_9 -> V_3 . V_97 ) ) {
F_88 ( V_9 -> V_3 . V_97 ) ;
V_9 -> V_165 . V_166 ++ ;
} else if ( V_113 != V_164 && V_113 != - 1 ) {
F_89 ( V_9 -> V_113 ) ;
}
F_90 () ;
}
int F_91 ( struct V_1 * V_9 , struct V_167 * V_168 )
{
if ( V_168 -> V_168 == V_169 ) {
F_92 ( V_9 , V_168 ) ;
return 0 ;
}
F_93 ( V_9 , V_168 ) ;
F_85 ( V_9 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_9 ,
struct V_170 * V_171 )
{
int V_11 ;
if ( V_171 -> V_172 )
return - V_36 ;
switch ( V_171 -> V_171 ) {
case V_68 :
V_11 = 0 ;
V_9 -> V_3 . V_173 = true ;
break;
case V_62 :
V_11 = 0 ;
V_9 -> V_3 . V_34 = true ;
break;
#ifdef V_27
case V_70 : {
struct V_174 V_175 ;
void T_3 * V_176 = ( void T_3 * ) ( V_177 ) V_171 -> args [ 0 ] ;
V_11 = - V_178 ;
if ( F_95 ( & V_175 , V_176 , sizeof( V_175 ) ) )
break;
V_11 = F_96 ( V_9 , & V_175 ) ;
break;
}
#endif
default:
V_11 = - V_36 ;
break;
}
if ( ! V_11 )
V_11 = F_6 ( V_9 ) ;
return V_11 ;
}
int F_97 ( struct V_1 * V_9 ,
struct V_179 * V_180 )
{
return - V_36 ;
}
int F_98 ( struct V_1 * V_9 ,
struct V_179 * V_180 )
{
return - V_36 ;
}
long F_99 ( struct V_83 * V_84 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_1 * V_9 = V_84 -> V_181 ;
void T_3 * V_182 = ( void T_3 * ) V_86 ;
long V_11 ;
switch ( V_85 ) {
case V_183 : {
struct V_167 V_168 ;
V_11 = - V_178 ;
if ( F_95 ( & V_168 , V_182 , sizeof( V_168 ) ) )
goto V_31;
V_11 = F_91 ( V_9 , & V_168 ) ;
goto V_31;
}
case V_184 :
{
struct V_170 V_171 ;
V_11 = - V_178 ;
if ( F_95 ( & V_171 , V_182 , sizeof( V_171 ) ) )
goto V_31;
V_11 = F_94 ( V_9 , & V_171 ) ;
break;
}
case V_185 :
case V_186 :
{
struct V_187 V_188 ;
V_11 = - V_178 ;
if ( F_95 ( & V_188 , V_182 , sizeof( V_188 ) ) )
goto V_31;
if ( V_85 == V_185 )
V_11 = F_100 ( V_9 , & V_188 ) ;
else
V_11 = F_101 ( V_9 , & V_188 ) ;
break;
}
#ifdef V_27
case V_189 : {
struct V_190 V_191 ;
V_11 = - V_178 ;
if ( F_95 ( & V_191 , V_182 , sizeof( V_191 ) ) )
goto V_31;
V_11 = F_102 ( V_9 , & V_191 ) ;
break;
}
#endif
default:
V_11 = - V_36 ;
}
V_31:
return V_11 ;
}
int F_103 ( struct V_1 * V_9 , struct V_192 * V_193 )
{
return V_194 ;
}
static int F_104 ( struct V_195 * V_196 )
{
V_127 V_197 = 0x3c000000 ;
V_127 V_198 = 0x60000000 ;
V_127 V_199 = 0x60000000 ;
V_127 V_200 = 0x44000002 ;
V_127 V_201 = 0xffff ;
V_196 -> V_202 [ 0 ] = V_197 | ( ( V_203 >> 16 ) & V_201 ) ;
V_196 -> V_202 [ 1 ] = V_198 | ( V_203 & V_201 ) ;
V_196 -> V_202 [ 2 ] = V_200 ;
V_196 -> V_202 [ 3 ] = V_199 ;
return 0 ;
}
long F_105 ( struct V_83 * V_84 ,
unsigned int V_85 , unsigned long V_86 )
{
void T_3 * V_182 = ( void T_3 * ) V_86 ;
long V_11 ;
switch ( V_85 ) {
case V_204 : {
struct V_195 V_196 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_11 = F_104 ( & V_196 ) ;
if ( F_106 ( V_182 , & V_196 , sizeof( V_196 ) ) ) {
V_11 = - V_178 ;
goto V_31;
}
break;
}
#ifdef F_7
case V_205 : {
struct V_206 V_207 ;
struct V_53 * V_53 = V_84 -> V_181 ;
V_11 = - V_178 ;
if ( F_95 ( & V_207 , V_182 , sizeof( V_207 ) ) )
goto V_31;
V_11 = F_107 ( V_53 , & V_207 ) ;
goto V_31;
}
case V_208 : {
struct V_53 * V_53 = V_84 -> V_181 ;
struct V_209 V_210 ;
V_11 = F_108 ( V_53 , & V_210 ) ;
if ( V_11 >= 0 && F_106 ( V_182 , & V_210 , sizeof( V_210 ) ) )
V_11 = - V_178 ;
break;
}
#endif
default:
V_11 = - V_211 ;
}
V_31:
return V_11 ;
}
int F_109 ( void * V_212 )
{
return 0 ;
}
void F_110 ( void )
{
}
