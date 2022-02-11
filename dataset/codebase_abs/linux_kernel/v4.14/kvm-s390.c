unsigned long F_1 ( void )
{
F_2 ( F_3 ( V_1 ) > V_2 ) ;
return F_3 ( V_1 ) ;
}
int F_4 ( void )
{
return 0 ;
}
static int F_5 ( struct V_3 * V_4 , unsigned long V_5 ,
void * V_6 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
unsigned long long * V_11 = V_6 ;
F_6 (kvm, &vm_list, vm_list) {
V_7 -> V_12 . V_13 -= * V_11 ;
F_7 (i, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_13 -= * V_11 ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 += * V_11 ;
if ( V_9 -> V_12 . V_17 )
V_9 -> V_12 . V_17 -> V_13 -= * V_11 ;
}
}
return V_18 ;
}
int F_8 ( void )
{
V_19 . V_20 = V_21 ;
F_9 ( & V_19 ) ;
V_22 . V_20 = V_23 ;
F_9 ( & V_22 ) ;
F_10 ( & V_24 ,
& V_25 ) ;
return 0 ;
}
void F_11 ( void )
{
F_12 ( & V_19 ) ;
F_12 ( & V_22 ) ;
F_13 ( & V_24 ,
& V_25 ) ;
}
static void F_14 ( unsigned long V_26 )
{
F_15 ( V_26 , V_27 ) ;
}
static inline int F_16 ( unsigned char V_26 )
{
register unsigned long T_1 V_28 ( L_1 ) = ( unsigned long ) V_26 | 0x100 ;
int V_29 ;
asm volatile(
" plo 0,0,0,0(0)\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc)
: "d" (r0)
: "cc");
return V_29 == 0 ;
}
static void F_17 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 256 ; ++ V_10 ) {
if ( F_16 ( V_10 ) )
V_30 . V_31 [ V_10 >> 3 ] |= 0x80 >> ( V_10 & 7 ) ;
}
if ( F_18 ( 28 ) )
F_19 ( V_30 . F_19 ,
sizeof( V_30 . F_19 ) ,
V_32 ) ;
if ( F_18 ( 17 ) ) {
F_20 ( V_33 , ( V_34 * )
V_30 . V_35 ) ;
F_20 ( V_36 , ( V_34 * )
V_30 . V_37 ) ;
F_20 ( V_38 , ( V_34 * )
V_30 . V_39 ) ;
F_20 ( V_40 , ( V_34 * )
V_30 . V_41 ) ;
F_20 ( V_42 , ( V_34 * )
V_30 . V_43 ) ;
}
if ( F_18 ( 76 ) )
F_20 ( V_44 , ( V_34 * )
V_30 . V_45 ) ;
if ( F_18 ( 77 ) ) {
F_20 ( V_46 , ( V_34 * )
V_30 . V_47 ) ;
F_20 ( V_48 , ( V_34 * )
V_30 . V_49 ) ;
F_20 ( V_50 , ( V_34 * )
V_30 . V_51 ) ;
F_20 ( V_52 , ( V_34 * )
V_30 . V_53 ) ;
}
if ( F_18 ( 57 ) )
F_20 ( V_54 , ( V_34 * )
V_30 . V_55 ) ;
if ( F_18 ( 146 ) )
F_20 ( V_56 , ( V_34 * )
V_30 . V_57 ) ;
if ( V_58 )
F_14 ( V_59 ) ;
if ( ! V_60 . V_61 || ! V_58 || ! V_60 . V_62 ||
! F_18 ( 3 ) || ! V_63 )
return;
F_14 ( V_64 ) ;
if ( V_60 . V_62 )
F_14 ( V_65 ) ;
if ( V_60 . V_66 )
F_14 ( V_67 ) ;
if ( V_60 . V_68 )
F_14 ( V_69 ) ;
if ( V_60 . V_70 )
F_14 ( V_71 ) ;
if ( V_60 . V_72 )
F_14 ( V_73 ) ;
if ( V_60 . V_74 )
F_14 ( V_75 ) ;
if ( V_60 . V_76 )
F_14 ( V_77 ) ;
if ( V_60 . V_78 )
F_14 ( V_79 ) ;
}
int F_21 ( void * V_80 )
{
V_81 = F_22 ( L_2 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_81 )
return - V_82 ;
if ( F_23 ( V_81 , & V_83 ) ) {
F_24 ( V_81 ) ;
return - V_82 ;
}
F_17 () ;
return F_25 ( & V_84 , V_85 ) ;
}
void F_26 ( void )
{
F_24 ( V_81 ) ;
}
long F_27 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
if ( V_88 == V_90 )
return F_28 () ;
return - V_91 ;
}
int F_29 ( struct V_7 * V_7 , long V_92 )
{
int V_93 ;
switch ( V_92 ) {
case V_94 :
case V_95 :
case V_96 :
#ifdef F_30
case V_97 :
#endif
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_93 = 1 ;
break;
case V_118 :
V_93 = V_119 ;
break;
case V_120 :
case V_121 :
V_93 = V_122 ;
if ( ! F_31 () )
V_93 = V_123 ;
else if ( V_60 . V_124 && V_60 . V_62 )
V_93 = V_125 ;
break;
case V_126 :
V_93 = V_127 ;
break;
case V_128 :
V_93 = V_58 ;
break;
case V_129 :
V_93 = V_130 ;
break;
case V_131 :
V_93 = F_18 ( 64 ) ;
break;
case V_132 :
V_93 = F_18 ( 133 ) ;
break;
default:
V_93 = 0 ;
}
return V_93 ;
}
static void F_32 ( struct V_7 * V_7 ,
struct V_133 * V_134 )
{
T_2 V_135 , V_136 ;
unsigned long V_137 ;
struct V_138 * V_138 = V_7 -> V_12 . V_138 ;
V_136 = V_134 -> V_139 + V_134 -> V_140 ;
for ( V_135 = V_134 -> V_139 ; V_135 <= V_136 ; V_135 ++ ) {
V_137 = F_33 ( V_134 , V_135 ) ;
if ( F_34 ( V_138 -> V_141 , V_137 ) )
F_35 ( V_7 , V_135 ) ;
if ( F_36 ( V_142 ) )
return;
F_37 () ;
}
}
int F_38 ( struct V_7 * V_7 ,
struct V_143 * log )
{
int V_93 ;
unsigned long V_144 ;
struct V_145 * V_146 ;
struct V_133 * V_134 ;
int V_147 = 0 ;
if ( F_39 ( V_7 ) )
return - V_91 ;
F_40 ( & V_7 -> V_148 ) ;
V_93 = - V_91 ;
if ( log -> V_149 >= V_127 )
goto V_150;
V_146 = V_145 ( V_7 ) ;
V_134 = F_41 ( V_146 , log -> V_149 ) ;
V_93 = - V_151 ;
if ( ! V_134 -> V_152 )
goto V_150;
F_32 ( V_7 , V_134 ) ;
V_93 = F_42 ( V_7 , log , & V_147 ) ;
if ( V_93 )
goto V_150;
if ( V_147 ) {
V_144 = F_43 ( V_134 ) ;
memset ( V_134 -> V_152 , 0 , V_144 ) ;
}
V_93 = 0 ;
V_150:
F_44 ( & V_7 -> V_148 ) ;
return V_93 ;
}
static void F_45 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_46 ( V_153 , V_9 ) ;
}
}
static int F_47 ( struct V_7 * V_7 , struct V_154 * V_155 )
{
int V_93 ;
if ( V_155 -> V_156 )
return - V_91 ;
switch ( V_155 -> V_155 ) {
case V_106 :
F_48 ( V_7 , 3 , L_3 , L_4 ) ;
V_7 -> V_12 . V_157 = 1 ;
V_93 = 0 ;
break;
case V_111 :
F_48 ( V_7 , 3 , L_3 , L_5 ) ;
V_7 -> V_12 . V_158 = 1 ;
V_93 = 0 ;
break;
case V_129 :
F_40 ( & V_7 -> V_159 ) ;
if ( V_7 -> V_160 ) {
V_93 = - V_161 ;
} else if ( V_130 ) {
F_49 ( V_7 -> V_12 . V_162 . V_163 , 129 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 129 ) ;
if ( F_18 ( 134 ) ) {
F_49 ( V_7 -> V_12 . V_162 . V_163 , 134 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 134 ) ;
}
if ( F_18 ( 135 ) ) {
F_49 ( V_7 -> V_12 . V_162 . V_163 , 135 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 135 ) ;
}
V_93 = 0 ;
} else
V_93 = - V_91 ;
F_44 ( & V_7 -> V_159 ) ;
F_48 ( V_7 , 3 , L_6 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_131 :
V_93 = - V_91 ;
F_40 ( & V_7 -> V_159 ) ;
if ( V_7 -> V_160 ) {
V_93 = - V_161 ;
} else if ( F_18 ( 64 ) ) {
F_49 ( V_7 -> V_12 . V_162 . V_163 , 64 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 64 ) ;
V_93 = 0 ;
}
F_44 ( & V_7 -> V_159 ) ;
F_48 ( V_7 , 3 , L_9 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_117 :
F_40 ( & V_7 -> V_159 ) ;
if ( V_7 -> V_160 ) {
V_93 = - V_161 ;
} else {
F_49 ( V_7 -> V_12 . V_162 . V_163 , 72 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 72 ) ;
V_93 = 0 ;
}
F_44 ( & V_7 -> V_159 ) ;
F_48 ( V_7 , 3 , L_10 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_132 :
V_93 = - V_91 ;
F_40 ( & V_7 -> V_159 ) ;
if ( F_50 ( & V_7 -> V_165 ) ) {
V_93 = - V_161 ;
} else if ( F_18 ( 133 ) ) {
F_49 ( V_7 -> V_12 . V_162 . V_163 , 133 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 133 ) ;
V_93 = 0 ;
}
F_44 ( & V_7 -> V_159 ) ;
F_48 ( V_7 , 3 , L_11 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_112 :
F_48 ( V_7 , 3 , L_3 , L_12 ) ;
V_7 -> V_12 . V_166 = 1 ;
V_93 = 0 ;
break;
case V_115 :
F_48 ( V_7 , 3 , L_3 , L_13 ) ;
V_7 -> V_12 . V_167 = 1 ;
F_45 ( V_7 ) ;
V_93 = 0 ;
break;
default:
V_93 = - V_91 ;
break;
}
return V_93 ;
}
static int F_51 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
switch ( V_169 -> V_169 ) {
case V_171 :
V_170 = 0 ;
F_48 ( V_7 , 3 , L_14 ,
V_7 -> V_12 . V_172 ) ;
if ( F_52 ( V_7 -> V_12 . V_172 , ( V_173 V_174 * ) V_169 -> V_175 ) )
V_170 = - V_176 ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_53 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
unsigned int V_178 ;
switch ( V_169 -> V_169 ) {
case V_179 :
V_170 = - V_177 ;
if ( ! V_60 . V_180 )
break;
V_170 = - V_161 ;
F_48 ( V_7 , 3 , L_3 , L_15 ) ;
F_40 ( & V_7 -> V_159 ) ;
if ( ! V_7 -> V_160 ) {
V_7 -> V_12 . V_181 = 1 ;
V_170 = 0 ;
}
F_44 ( & V_7 -> V_159 ) ;
break;
case V_182 :
V_170 = - V_177 ;
if ( ! V_60 . V_180 )
break;
V_170 = - V_91 ;
if ( ! V_7 -> V_12 . V_181 )
break;
F_48 ( V_7 , 3 , L_3 , L_16 ) ;
F_40 ( & V_7 -> V_159 ) ;
V_178 = F_54 ( & V_7 -> V_183 ) ;
F_55 ( V_7 -> V_12 . V_138 -> V_141 ) ;
F_56 ( & V_7 -> V_183 , V_178 ) ;
F_44 ( & V_7 -> V_159 ) ;
V_170 = 0 ;
break;
case V_171 : {
unsigned long V_184 ;
if ( F_39 ( V_7 ) )
return - V_91 ;
if ( F_57 ( V_184 , ( V_173 V_174 * ) V_169 -> V_175 ) )
return - V_176 ;
if ( V_7 -> V_12 . V_172 != V_185 &&
V_184 > V_7 -> V_12 . V_172 )
return - V_186 ;
if ( ! V_184 )
return - V_91 ;
if ( V_184 != V_185 )
V_184 -= 1 ;
V_170 = - V_161 ;
F_40 ( & V_7 -> V_159 ) ;
if ( ! V_7 -> V_160 ) {
struct V_138 * V_187 = F_58 ( V_142 -> V_141 , V_184 ) ;
if ( ! V_187 ) {
V_170 = - V_82 ;
} else {
F_59 ( V_7 -> V_12 . V_138 ) ;
V_187 -> V_188 = V_7 ;
V_7 -> V_12 . V_138 = V_187 ;
V_170 = 0 ;
}
}
F_44 ( & V_7 -> V_159 ) ;
F_48 ( V_7 , 3 , L_17 , V_184 ) ;
F_48 ( V_7 , 3 , L_18 ,
( void * ) V_7 -> V_12 . V_138 -> V_189 ) ;
break;
}
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_60 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_61 ( V_7 , 76 ) )
return - V_91 ;
F_40 ( & V_7 -> V_159 ) ;
switch ( V_169 -> V_169 ) {
case V_190 :
F_62 (
V_7 -> V_12 . V_191 . V_192 -> V_193 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_193 ) ) ;
V_7 -> V_12 . V_191 . V_194 = 1 ;
F_48 ( V_7 , 3 , L_3 , L_19 ) ;
break;
case V_195 :
F_62 (
V_7 -> V_12 . V_191 . V_192 -> V_196 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_196 ) ) ;
V_7 -> V_12 . V_191 . V_197 = 1 ;
F_48 ( V_7 , 3 , L_3 , L_20 ) ;
break;
case V_198 :
V_7 -> V_12 . V_191 . V_194 = 0 ;
memset ( V_7 -> V_12 . V_191 . V_192 -> V_193 , 0 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_193 ) ) ;
F_48 ( V_7 , 3 , L_3 , L_21 ) ;
break;
case V_199 :
V_7 -> V_12 . V_191 . V_197 = 0 ;
memset ( V_7 -> V_12 . V_191 . V_192 -> V_196 , 0 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_196 ) ) ;
F_48 ( V_7 , 3 , L_3 , L_22 ) ;
break;
default:
F_44 ( & V_7 -> V_159 ) ;
return - V_177 ;
}
F_7 (i, vcpu, kvm) {
F_63 ( V_9 ) ;
F_64 ( V_9 ) ;
}
F_44 ( & V_7 -> V_159 ) ;
return 0 ;
}
static void F_65 ( struct V_7 * V_7 , int V_200 )
{
int V_201 ;
struct V_8 * V_9 ;
F_7 (cx, vcpu, kvm)
F_46 ( V_200 , V_9 ) ;
}
static int F_66 ( struct V_7 * V_7 )
{
struct V_202 * V_203 ;
struct V_133 * V_204 ;
struct V_145 * V_146 ;
unsigned long V_205 ;
int V_206 ;
if ( V_7 -> V_12 . V_207 )
return 0 ;
V_146 = V_145 ( V_7 ) ;
if ( ! V_146 || ! V_146 -> V_208 )
return - V_91 ;
V_203 = F_67 ( sizeof( * V_203 ) , V_209 ) ;
if ( ! V_203 )
return - V_82 ;
V_7 -> V_12 . V_207 = V_203 ;
if ( V_7 -> V_12 . V_181 ) {
V_204 = V_146 -> V_210 + V_146 -> V_208 - 1 ;
V_205 = F_68 ( V_204 -> V_139 + V_204 -> V_140 , V_211 ) ;
V_203 -> V_212 = F_69 ( V_205 / 8 ) ;
if ( ! V_203 -> V_212 ) {
F_70 ( V_203 ) ;
V_7 -> V_12 . V_207 = NULL ;
return - V_82 ;
}
V_203 -> V_213 = V_205 ;
F_71 ( & V_203 -> V_214 , V_205 ) ;
for ( V_206 = 0 ; V_206 < V_146 -> V_208 ; V_206 ++ ) {
V_204 = V_146 -> V_210 + V_206 ;
F_72 ( V_203 -> V_212 , V_204 -> V_139 , V_204 -> V_140 ) ;
}
F_65 ( V_7 , V_215 ) ;
}
return 0 ;
}
static int F_73 ( struct V_7 * V_7 )
{
struct V_202 * V_203 ;
if ( ! V_7 -> V_12 . V_207 )
return 0 ;
V_203 = V_7 -> V_12 . V_207 ;
V_7 -> V_12 . V_207 = NULL ;
if ( V_7 -> V_12 . V_181 ) {
F_65 ( V_7 , V_216 ) ;
F_74 ( V_203 -> V_212 ) ;
}
F_70 ( V_203 ) ;
return 0 ;
}
static int F_75 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
int V_178 , V_217 = - V_177 ;
F_40 ( & V_7 -> V_159 ) ;
switch ( V_169 -> V_169 ) {
case V_218 :
V_178 = F_54 ( & V_7 -> V_183 ) ;
V_217 = F_66 ( V_7 ) ;
F_56 ( & V_7 -> V_183 , V_178 ) ;
break;
case V_219 :
V_217 = F_73 ( V_7 ) ;
break;
default:
break;
}
F_44 ( & V_7 -> V_159 ) ;
return V_217 ;
}
static int F_76 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
V_173 V_220 = ( V_7 -> V_12 . V_207 != NULL ) ;
if ( V_169 -> V_169 != V_221 )
return - V_177 ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_220 , sizeof( V_220 ) ) )
return - V_176 ;
return 0 ;
}
static int F_78 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_222 V_223 ;
if ( F_79 ( & V_223 , ( void V_174 * ) V_169 -> V_175 , sizeof( V_223 ) ) )
return - V_176 ;
if ( F_61 ( V_7 , 139 ) )
F_80 ( V_7 , & V_223 ) ;
else if ( V_223 . V_224 == 0 )
F_81 ( V_7 , V_223 . V_225 ) ;
else
return - V_91 ;
F_48 ( V_7 , 3 , L_23 ,
V_223 . V_224 , V_223 . V_225 ) ;
return 0 ;
}
static int F_82 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
T_3 V_226 ;
if ( F_79 ( & V_226 , ( void V_174 * ) V_169 -> V_175 ,
sizeof( V_226 ) ) )
return - V_176 ;
if ( V_226 != 0 )
return - V_91 ;
F_48 ( V_7 , 3 , L_24 , V_226 ) ;
return 0 ;
}
static int F_83 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
V_173 V_223 ;
if ( F_79 ( & V_223 , ( void V_174 * ) V_169 -> V_175 , sizeof( V_223 ) ) )
return - V_176 ;
F_81 ( V_7 , V_223 ) ;
F_48 ( V_7 , 3 , L_25 , V_223 ) ;
return 0 ;
}
static int F_84 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
if ( V_169 -> V_156 )
return - V_91 ;
switch ( V_169 -> V_169 ) {
case V_227 :
V_170 = F_78 ( V_7 , V_169 ) ;
break;
case V_228 :
V_170 = F_82 ( V_7 , V_169 ) ;
break;
case V_229 :
V_170 = F_83 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static void F_85 ( struct V_7 * V_7 ,
struct V_222 * V_223 )
{
struct V_230 V_231 ;
F_86 () ;
F_87 ( ( char * ) & V_231 ) ;
V_223 -> V_225 = V_231 . V_225 + V_7 -> V_12 . V_13 ;
V_223 -> V_224 = V_231 . V_224 + V_7 -> V_12 . V_232 ;
if ( V_223 -> V_225 < V_231 . V_225 )
V_223 -> V_224 += 1 ;
F_88 () ;
}
static int F_89 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_222 V_223 ;
memset ( & V_223 , 0 , sizeof( V_223 ) ) ;
if ( F_61 ( V_7 , 139 ) )
F_85 ( V_7 , & V_223 ) ;
else
V_223 . V_225 = F_90 ( V_7 ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_223 , sizeof( V_223 ) ) )
return - V_176 ;
F_48 ( V_7 , 3 , L_26 ,
V_223 . V_224 , V_223 . V_225 ) ;
return 0 ;
}
static int F_91 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
T_3 V_226 = 0 ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_226 ,
sizeof( V_226 ) ) )
return - V_176 ;
F_48 ( V_7 , 3 , L_27 , V_226 ) ;
return 0 ;
}
static int F_92 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
V_173 V_223 ;
V_223 = F_90 ( V_7 ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_223 , sizeof( V_223 ) ) )
return - V_176 ;
F_48 ( V_7 , 3 , L_28 , V_223 ) ;
return 0 ;
}
static int F_93 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
if ( V_169 -> V_156 )
return - V_91 ;
switch ( V_169 -> V_169 ) {
case V_227 :
V_170 = F_89 ( V_7 , V_169 ) ;
break;
case V_228 :
V_170 = F_91 ( V_7 , V_169 ) ;
break;
case V_229 :
V_170 = F_92 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_94 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_233 * V_234 ;
T_4 V_235 , V_236 ;
int V_170 = 0 ;
F_40 ( & V_7 -> V_159 ) ;
if ( V_7 -> V_160 ) {
V_170 = - V_161 ;
goto V_150;
}
V_234 = F_67 ( sizeof( * V_234 ) , V_209 ) ;
if ( ! V_234 ) {
V_170 = - V_82 ;
goto V_150;
}
if ( ! F_79 ( V_234 , ( void V_174 * ) V_169 -> V_175 ,
sizeof( * V_234 ) ) ) {
V_7 -> V_12 . V_162 . V_237 = V_234 -> V_237 ;
V_235 = V_60 . V_238 >> 16 & 0xfff ;
V_236 = V_60 . V_238 & 0xfff ;
if ( V_235 && V_234 -> V_238 ) {
if ( V_234 -> V_238 > V_236 )
V_7 -> V_12 . V_162 . V_238 = V_236 ;
else if ( V_234 -> V_238 < V_235 )
V_7 -> V_12 . V_162 . V_238 = V_235 ;
else
V_7 -> V_12 . V_162 . V_238 = V_234 -> V_238 ;
}
memcpy ( V_7 -> V_12 . V_162 . V_164 , V_234 -> V_164 ,
V_239 ) ;
F_48 ( V_7 , 3 , L_29 ,
V_7 -> V_12 . V_162 . V_238 ,
V_7 -> V_12 . V_162 . V_237 ) ;
F_48 ( V_7 , 3 , L_30 ,
V_7 -> V_12 . V_162 . V_164 [ 0 ] ,
V_7 -> V_12 . V_162 . V_164 [ 1 ] ,
V_7 -> V_12 . V_162 . V_164 [ 2 ] ) ;
} else
V_170 = - V_176 ;
F_70 ( V_234 ) ;
V_150:
F_44 ( & V_7 -> V_159 ) ;
return V_170 ;
}
static int F_95 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
struct V_240 V_241 ;
int V_170 = - V_161 ;
if ( F_79 ( & V_241 , ( void V_174 * ) V_169 -> V_175 , sizeof( V_241 ) ) )
return - V_176 ;
if ( ! F_96 ( ( unsigned long * ) V_241 . V_242 ,
V_27 ,
V_243 ) )
return - V_91 ;
F_40 ( & V_7 -> V_159 ) ;
if ( ! F_50 ( & V_7 -> V_165 ) ) {
F_97 ( V_7 -> V_12 . V_244 , ( unsigned long * ) V_241 . V_242 ,
V_243 ) ;
V_170 = 0 ;
}
F_44 ( & V_7 -> V_159 ) ;
return V_170 ;
}
static int F_98 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
return - V_177 ;
}
static int F_99 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 = - V_177 ;
switch ( V_169 -> V_169 ) {
case V_245 :
V_170 = F_94 ( V_7 , V_169 ) ;
break;
case V_246 :
V_170 = F_95 ( V_7 , V_169 ) ;
break;
case V_247 :
V_170 = F_98 ( V_7 , V_169 ) ;
break;
}
return V_170 ;
}
static int F_100 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_233 * V_234 ;
int V_170 = 0 ;
V_234 = F_67 ( sizeof( * V_234 ) , V_209 ) ;
if ( ! V_234 ) {
V_170 = - V_82 ;
goto V_150;
}
V_234 -> V_237 = V_7 -> V_12 . V_162 . V_237 ;
V_234 -> V_238 = V_7 -> V_12 . V_162 . V_238 ;
memcpy ( & V_234 -> V_164 , V_7 -> V_12 . V_162 . V_164 ,
V_239 ) ;
F_48 ( V_7 , 3 , L_31 ,
V_7 -> V_12 . V_162 . V_238 ,
V_7 -> V_12 . V_162 . V_237 ) ;
F_48 ( V_7 , 3 , L_32 ,
V_7 -> V_12 . V_162 . V_164 [ 0 ] ,
V_7 -> V_12 . V_162 . V_164 [ 1 ] ,
V_7 -> V_12 . V_162 . V_164 [ 2 ] ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , V_234 , sizeof( * V_234 ) ) )
V_170 = - V_176 ;
F_70 ( V_234 ) ;
V_150:
return V_170 ;
}
static int F_101 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_248 * V_249 ;
int V_170 = 0 ;
V_249 = F_67 ( sizeof( * V_249 ) , V_209 ) ;
if ( ! V_249 ) {
V_170 = - V_82 ;
goto V_150;
}
F_102 ( (struct V_237 * ) & V_249 -> V_237 ) ;
V_249 -> V_238 = V_60 . V_238 ;
memcpy ( & V_249 -> V_163 , V_7 -> V_12 . V_162 . V_163 ,
V_239 ) ;
memcpy ( ( unsigned long * ) & V_249 -> V_164 , V_250 . V_251 ,
sizeof( V_250 . V_251 ) ) ;
F_48 ( V_7 , 3 , L_33 ,
V_7 -> V_12 . V_162 . V_238 ,
V_7 -> V_12 . V_162 . V_237 ) ;
F_48 ( V_7 , 3 , L_34 ,
V_249 -> V_163 [ 0 ] ,
V_249 -> V_163 [ 1 ] ,
V_249 -> V_163 [ 2 ] ) ;
F_48 ( V_7 , 3 , L_35 ,
V_249 -> V_164 [ 0 ] ,
V_249 -> V_164 [ 1 ] ,
V_249 -> V_164 [ 2 ] ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , V_249 , sizeof( * V_249 ) ) )
V_170 = - V_176 ;
F_70 ( V_249 ) ;
V_150:
return V_170 ;
}
static int F_103 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
struct V_240 V_241 ;
F_97 ( ( unsigned long * ) V_241 . V_242 , V_7 -> V_12 . V_244 ,
V_243 ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_241 , sizeof( V_241 ) ) )
return - V_176 ;
return 0 ;
}
static int F_104 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
struct V_240 V_241 ;
F_97 ( ( unsigned long * ) V_241 . V_242 ,
V_27 ,
V_243 ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_241 , sizeof( V_241 ) ) )
return - V_176 ;
return 0 ;
}
static int F_105 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
return - V_177 ;
}
static int F_106 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_30 ,
sizeof( struct V_252 ) ) )
return - V_176 ;
return 0 ;
}
static int F_107 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 = - V_177 ;
switch ( V_169 -> V_169 ) {
case V_245 :
V_170 = F_100 ( V_7 , V_169 ) ;
break;
case V_253 :
V_170 = F_101 ( V_7 , V_169 ) ;
break;
case V_246 :
V_170 = F_103 ( V_7 , V_169 ) ;
break;
case V_254 :
V_170 = F_104 ( V_7 , V_169 ) ;
break;
case V_247 :
V_170 = F_105 ( V_7 , V_169 ) ;
break;
case V_255 :
V_170 = F_106 ( V_7 , V_169 ) ;
break;
}
return V_170 ;
}
static int F_108 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
switch ( V_169 -> V_256 ) {
case V_257 :
V_170 = F_53 ( V_7 , V_169 ) ;
break;
case V_258 :
V_170 = F_84 ( V_7 , V_169 ) ;
break;
case V_259 :
V_170 = F_99 ( V_7 , V_169 ) ;
break;
case V_260 :
V_170 = F_60 ( V_7 , V_169 ) ;
break;
case V_261 :
V_170 = F_75 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_109 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
switch ( V_169 -> V_256 ) {
case V_257 :
V_170 = F_51 ( V_7 , V_169 ) ;
break;
case V_258 :
V_170 = F_93 ( V_7 , V_169 ) ;
break;
case V_259 :
V_170 = F_107 ( V_7 , V_169 ) ;
break;
case V_261 :
V_170 = F_76 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_110 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
switch ( V_169 -> V_256 ) {
case V_257 :
switch ( V_169 -> V_169 ) {
case V_179 :
case V_182 :
V_170 = V_60 . V_180 ? 0 : - V_177 ;
break;
case V_171 :
V_170 = 0 ;
break;
default:
V_170 = - V_177 ;
break;
}
break;
case V_258 :
switch ( V_169 -> V_169 ) {
case V_229 :
case V_228 :
V_170 = 0 ;
break;
default:
V_170 = - V_177 ;
break;
}
break;
case V_259 :
switch ( V_169 -> V_169 ) {
case V_245 :
case V_253 :
case V_246 :
case V_254 :
case V_255 :
V_170 = 0 ;
break;
case V_247 :
default:
V_170 = - V_177 ;
break;
}
break;
case V_260 :
switch ( V_169 -> V_169 ) {
case V_190 :
case V_195 :
case V_198 :
case V_199 :
V_170 = 0 ;
break;
default:
V_170 = - V_177 ;
break;
}
break;
case V_261 :
V_170 = 0 ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static long F_111 ( struct V_7 * V_7 , struct V_262 * args )
{
T_5 * V_263 ;
T_6 V_264 ;
int V_265 , V_10 , V_93 = 0 ;
if ( args -> V_156 != 0 )
return - V_91 ;
if ( ! F_112 ( V_142 -> V_141 ) )
return V_266 ;
if ( args -> V_267 < 1 || args -> V_267 > V_268 )
return - V_91 ;
V_263 = F_113 ( args -> V_267 , sizeof( T_5 ) , V_209 ) ;
if ( ! V_263 )
return - V_82 ;
F_114 ( & V_142 -> V_141 -> V_269 ) ;
V_265 = F_54 ( & V_7 -> V_183 ) ;
for ( V_10 = 0 ; V_10 < args -> V_267 ; V_10 ++ ) {
V_264 = F_115 ( V_7 , args -> V_270 + V_10 ) ;
if ( F_116 ( V_264 ) ) {
V_93 = - V_176 ;
break;
}
V_93 = F_117 ( V_142 -> V_141 , V_264 , & V_263 [ V_10 ] ) ;
if ( V_93 )
break;
}
F_56 ( & V_7 -> V_183 , V_265 ) ;
F_118 ( & V_142 -> V_141 -> V_269 ) ;
if ( ! V_93 ) {
V_93 = F_77 ( ( T_5 V_174 * ) args -> V_271 , V_263 ,
sizeof( T_5 ) * args -> V_267 ) ;
if ( V_93 )
V_93 = - V_176 ;
}
F_119 ( V_263 ) ;
return V_93 ;
}
static long F_120 ( struct V_7 * V_7 , struct V_262 * args )
{
T_5 * V_263 ;
T_6 V_264 ;
int V_265 , V_10 , V_93 = 0 ;
if ( args -> V_156 != 0 )
return - V_91 ;
if ( args -> V_267 < 1 || args -> V_267 > V_268 )
return - V_91 ;
V_263 = F_113 ( args -> V_267 , sizeof( T_5 ) , V_209 ) ;
if ( ! V_263 )
return - V_82 ;
V_93 = F_79 ( V_263 , ( T_5 V_174 * ) args -> V_271 ,
sizeof( T_5 ) * args -> V_267 ) ;
if ( V_93 ) {
V_93 = - V_176 ;
goto V_150;
}
V_93 = F_121 () ;
if ( V_93 )
goto V_150;
F_114 ( & V_142 -> V_141 -> V_269 ) ;
V_265 = F_54 ( & V_7 -> V_183 ) ;
for ( V_10 = 0 ; V_10 < args -> V_267 ; V_10 ++ ) {
V_264 = F_115 ( V_7 , args -> V_270 + V_10 ) ;
if ( F_116 ( V_264 ) ) {
V_93 = - V_176 ;
break;
}
if ( V_263 [ V_10 ] & 0x01 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_122 ( V_142 -> V_141 , V_264 , V_263 [ V_10 ] , 0 ) ;
if ( V_93 )
break;
}
F_56 ( & V_7 -> V_183 , V_265 ) ;
F_118 ( & V_142 -> V_141 -> V_269 ) ;
V_150:
F_119 ( V_263 ) ;
return V_93 ;
}
static int F_123 ( struct V_7 * V_7 ,
struct V_272 * args )
{
struct V_202 * V_273 = V_7 -> V_12 . V_207 ;
unsigned long V_274 , V_264 , V_275 , V_10 , V_276 , V_277 ;
int V_265 , V_278 , V_93 = 0 , V_279 ;
T_3 * V_217 ;
V_277 = args -> V_270 ;
V_10 = V_276 = V_275 = 0 ;
if ( F_124 ( ! V_7 -> V_12 . V_181 ) )
return - V_177 ;
if ( args -> V_156 & ~ V_280 )
return - V_91 ;
V_278 = ! ! ( args -> V_156 & V_280 ) ;
if ( ! V_278 && ! V_273 )
return - V_91 ;
V_274 = F_125 ( args -> V_267 , V_281 ) ;
if ( ! V_274 || ! V_7 -> V_141 -> V_282 . V_181 ) {
memset ( args , 0 , sizeof( * args ) ) ;
return 0 ;
}
if ( ! V_278 ) {
if ( ! F_126 ( & V_273 -> V_214 ) ) {
memset ( args , 0 , sizeof( * args ) ) ;
return 0 ;
}
V_277 = F_127 ( V_273 -> V_212 , V_273 -> V_213 ,
args -> V_270 ) ;
if ( V_277 >= V_273 -> V_213 )
V_277 = F_127 ( V_273 -> V_212 , V_273 -> V_213 , 0 ) ;
if ( V_277 >= V_273 -> V_213 ) {
memset ( args , 0 , sizeof( * args ) ) ;
return 0 ;
}
V_276 = F_127 ( V_273 -> V_212 , V_273 -> V_213 , V_277 + 1 ) ;
}
V_217 = F_69 ( V_274 ) ;
if ( ! V_217 )
return - V_82 ;
args -> V_270 = V_277 ;
F_114 ( & V_7 -> V_141 -> V_269 ) ;
V_265 = F_54 ( & V_7 -> V_183 ) ;
while ( V_10 < V_274 ) {
V_264 = F_115 ( V_7 , V_277 ) ;
if ( F_116 ( V_264 ) ) {
V_93 = - V_176 ;
break;
}
if ( ! V_278 && F_128 ( V_277 , V_273 -> V_212 ) )
F_129 ( & V_273 -> V_214 ) ;
V_93 = F_130 ( V_7 -> V_141 , V_264 , & V_275 ) ;
if ( V_93 < 0 )
V_275 = 0 ;
V_217 [ V_10 ++ ] = ( V_275 >> 24 ) & 0x43 ;
if ( ! V_278 ) {
if ( V_276 > V_277 + V_283 )
break;
if ( V_277 == V_276 )
V_276 = F_127 ( V_273 -> V_212 ,
V_273 -> V_213 , V_277 + 1 ) ;
if ( ( V_276 >= V_273 -> V_213 ) ||
( V_276 >= args -> V_270 + V_274 ) )
break;
}
V_277 ++ ;
}
F_56 ( & V_7 -> V_183 , V_265 ) ;
F_118 ( & V_7 -> V_141 -> V_269 ) ;
args -> V_267 = V_10 ;
args -> V_284 = V_273 ? F_126 ( & V_273 -> V_214 ) : 0 ;
V_279 = F_77 ( ( void V_174 * ) args -> V_285 , V_217 , args -> V_267 ) ;
if ( V_279 )
V_93 = - V_176 ;
F_74 ( V_217 ) ;
return V_93 ;
}
static int F_131 ( struct V_7 * V_7 ,
const struct V_272 * args )
{
unsigned long V_264 , V_286 , V_275 , V_10 ;
T_5 * V_287 ;
int V_265 , V_93 = 0 ;
V_286 = args -> V_286 ;
if ( ! V_7 -> V_12 . V_181 )
return - V_177 ;
if ( args -> V_156 != 0 )
return - V_91 ;
if ( args -> V_267 > V_281 )
return - V_91 ;
if ( args -> V_267 == 0 )
return 0 ;
V_287 = F_69 ( sizeof( * V_287 ) * args -> V_267 ) ;
if ( ! V_287 )
return - V_82 ;
V_93 = F_79 ( V_287 , ( void V_174 * ) args -> V_285 , args -> V_267 ) ;
if ( V_93 ) {
V_93 = - V_176 ;
goto V_150;
}
F_114 ( & V_7 -> V_141 -> V_269 ) ;
V_265 = F_54 ( & V_7 -> V_183 ) ;
for ( V_10 = 0 ; V_10 < args -> V_267 ; V_10 ++ ) {
V_264 = F_115 ( V_7 , args -> V_270 + V_10 ) ;
if ( F_116 ( V_264 ) ) {
V_93 = - V_176 ;
break;
}
V_275 = V_287 [ V_10 ] ;
V_275 = V_275 << 24 ;
V_286 &= V_288 | V_289 ;
F_132 ( V_7 -> V_141 , V_264 , V_286 , V_275 ) ;
}
F_56 ( & V_7 -> V_183 , V_265 ) ;
F_118 ( & V_7 -> V_141 -> V_269 ) ;
if ( ! V_7 -> V_141 -> V_282 . V_181 ) {
F_133 ( & V_7 -> V_141 -> V_269 ) ;
V_7 -> V_141 -> V_282 . V_181 = 1 ;
F_134 ( & V_7 -> V_141 -> V_269 ) ;
}
V_150:
F_74 ( V_287 ) ;
return V_93 ;
}
long F_135 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_7 * V_7 = V_87 -> V_290 ;
void V_174 * V_291 = ( void V_174 * ) V_89 ;
struct V_168 V_169 ;
int V_93 ;
switch ( V_88 ) {
case V_292 : {
struct V_293 V_294 ;
V_93 = - V_176 ;
if ( F_79 ( & V_294 , V_291 , sizeof( V_294 ) ) )
break;
V_93 = F_136 ( V_7 , & V_294 ) ;
break;
}
case V_295 : {
struct V_154 V_155 ;
V_93 = - V_176 ;
if ( F_79 ( & V_155 , V_291 , sizeof( V_155 ) ) )
break;
V_93 = F_47 ( V_7 , & V_155 ) ;
break;
}
case V_296 : {
struct V_297 V_298 ;
V_93 = - V_91 ;
if ( V_7 -> V_12 . V_157 ) {
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
V_93 = F_137 ( V_7 , & V_298 , 0 , 0 ) ;
}
break;
}
case V_299 : {
V_93 = - V_176 ;
if ( F_79 ( & V_169 , ( void V_174 * ) V_89 , sizeof( V_169 ) ) )
break;
V_93 = F_108 ( V_7 , & V_169 ) ;
break;
}
case V_300 : {
V_93 = - V_176 ;
if ( F_79 ( & V_169 , ( void V_174 * ) V_89 , sizeof( V_169 ) ) )
break;
V_93 = F_109 ( V_7 , & V_169 ) ;
break;
}
case V_301 : {
V_93 = - V_176 ;
if ( F_79 ( & V_169 , ( void V_174 * ) V_89 , sizeof( V_169 ) ) )
break;
V_93 = F_110 ( V_7 , & V_169 ) ;
break;
}
case V_302 : {
struct V_262 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_291 ,
sizeof( struct V_262 ) ) )
break;
V_93 = F_111 ( V_7 , & args ) ;
break;
}
case V_303 : {
struct V_262 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_291 ,
sizeof( struct V_262 ) ) )
break;
V_93 = F_120 ( V_7 , & args ) ;
break;
}
case V_304 : {
struct V_272 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_291 , sizeof( args ) ) )
break;
V_93 = F_123 ( V_7 , & args ) ;
if ( ! V_93 ) {
V_93 = F_77 ( V_291 , & args , sizeof( args ) ) ;
if ( V_93 )
V_93 = - V_176 ;
}
break;
}
case V_305 : {
struct V_272 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_291 , sizeof( args ) ) )
break;
V_93 = F_131 ( V_7 , & args ) ;
break;
}
default:
V_93 = - V_306 ;
}
return V_93 ;
}
static int F_138 ( T_3 * V_307 )
{
T_7 V_308 = 0x04000000UL ;
T_7 V_29 = 0 ;
memset ( V_307 , 0 , 128 ) ;
asm volatile(
"lgr 0,%1\n"
"lgr 2,%2\n"
".long 0xb2af0000\n"
"0: ipm %0\n"
"srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+r" (cc)
: "r" (fcn_code), "r" (config)
: "cc", "0", "2", "memory"
);
return V_29 ;
}
static int F_139 ( void )
{
T_3 V_307 [ 128 ] ;
int V_29 ;
if ( F_18 ( 12 ) ) {
V_29 = F_138 ( V_307 ) ;
if ( V_29 )
F_140 ( L_36 , V_29 ) ;
else
return V_307 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_141 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_191 . V_309 = ( V_310 ) ( unsigned long ) V_7 -> V_12 . V_191 . V_192 ;
if ( F_139 () )
V_7 -> V_12 . V_191 . V_309 |= V_311 ;
else
V_7 -> V_12 . V_191 . V_309 |= V_312 ;
}
static V_173 F_142 ( void )
{
struct V_237 V_237 ;
F_102 ( & V_237 ) ;
V_237 . V_313 = 0xff ;
return * ( ( V_173 * ) & V_237 ) ;
}
static void F_143 ( struct V_7 * V_7 )
{
if ( ! F_61 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_191 . V_192 = & V_7 -> V_12 . V_314 -> V_192 ;
F_141 ( V_7 ) ;
V_7 -> V_12 . V_191 . V_194 = 1 ;
V_7 -> V_12 . V_191 . V_197 = 1 ;
F_62 ( V_7 -> V_12 . V_191 . V_192 -> V_193 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_193 ) ) ;
F_62 ( V_7 -> V_12 . V_191 . V_192 -> V_196 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_196 ) ) ;
}
static void F_144 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_315 )
F_145 ( V_7 -> V_12 . V_316 , sizeof( struct V_317 ) ) ;
else
F_146 ( ( unsigned long ) ( V_7 -> V_12 . V_316 ) ) ;
V_7 -> V_12 . V_316 = NULL ;
}
int F_147 ( struct V_7 * V_7 , unsigned long type )
{
T_8 V_318 = V_209 ;
int V_10 , V_319 ;
char V_320 [ 16 ] ;
static unsigned long V_321 ;
V_319 = - V_91 ;
#ifdef F_30
if ( type & ~ V_322 )
goto V_323;
if ( ( type & V_322 ) && ( ! F_148 ( V_324 ) ) )
goto V_323;
#else
if ( type )
goto V_323;
#endif
V_319 = F_28 () ;
if ( V_319 )
goto V_323;
V_319 = - V_82 ;
F_149 ( & V_7 -> V_12 . V_325 , 5 * V_326 , 500 ) ;
V_7 -> V_12 . V_315 = 0 ;
if ( ! V_60 . V_62 )
V_318 |= V_327 ;
F_150 ( & V_7 -> V_12 . V_328 ) ;
V_7 -> V_12 . V_316 = (struct V_329 * ) F_151 ( V_318 ) ;
if ( ! V_7 -> V_12 . V_316 )
goto V_323;
F_152 ( & V_330 ) ;
V_321 += 16 ;
if ( V_321 + sizeof( struct V_329 ) > V_331 )
V_321 = 0 ;
V_7 -> V_12 . V_316 = (struct V_329 * )
( ( char * ) V_7 -> V_12 . V_316 + V_321 ) ;
F_153 ( & V_330 ) ;
sprintf ( V_320 , L_37 , V_142 -> V_332 ) ;
V_7 -> V_12 . V_333 = F_22 ( V_320 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_333 )
goto V_323;
V_7 -> V_12 . V_314 =
(struct V_314 * ) F_151 ( V_209 | V_327 ) ;
if ( ! V_7 -> V_12 . V_314 )
goto V_323;
memcpy ( V_7 -> V_12 . V_162 . V_163 , V_250 . V_251 ,
sizeof( V_250 . V_251 ) ) ;
for ( V_10 = 0 ; V_10 < V_334 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_162 . V_163 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_162 . V_163 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_162 . V_164 = V_7 -> V_12 . V_314 -> V_164 ;
memcpy ( V_7 -> V_12 . V_162 . V_164 , V_7 -> V_12 . V_162 . V_163 ,
V_239 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_163 , 138 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 138 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_163 , 74 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 74 ) ;
if ( V_335 ) {
F_49 ( V_7 -> V_12 . V_162 . V_163 , 147 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 147 ) ;
}
V_7 -> V_12 . V_162 . V_237 = F_142 () ;
V_7 -> V_12 . V_162 . V_238 = V_60 . V_238 & 0x0fff ;
F_143 ( V_7 ) ;
F_154 ( & V_7 -> V_12 . V_336 . V_337 ) ;
V_7 -> V_12 . V_336 . V_338 = 0 ;
V_7 -> V_12 . V_336 . V_339 = 0 ;
F_155 ( & V_7 -> V_12 . V_336 . V_159 ) ;
for ( V_10 = 0 ; V_10 < V_340 ; V_10 ++ )
F_156 ( & V_7 -> V_12 . V_336 . V_341 [ V_10 ] ) ;
F_157 ( & V_7 -> V_12 . V_342 ) ;
F_154 ( & V_7 -> V_12 . V_343 ) ;
F_23 ( V_7 -> V_12 . V_333 , & V_83 ) ;
F_48 ( V_7 , 3 , L_38 , type ) ;
if ( type & V_322 ) {
V_7 -> V_12 . V_138 = NULL ;
V_7 -> V_12 . V_172 = V_185 ;
} else {
if ( V_60 . V_344 == V_345 )
V_7 -> V_12 . V_172 = V_346 ;
else
V_7 -> V_12 . V_172 = F_158 (unsigned long, TASK_SIZE_MAX,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_138 = F_58 ( V_142 -> V_141 , V_7 -> V_12 . V_172 - 1 ) ;
if ( ! V_7 -> V_12 . V_138 )
goto V_323;
V_7 -> V_12 . V_138 -> V_188 = V_7 ;
V_7 -> V_12 . V_138 -> V_347 = 0 ;
}
V_7 -> V_12 . V_348 = 0 ;
V_7 -> V_12 . V_157 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_155 ( & V_7 -> V_12 . V_349 ) ;
F_159 ( V_7 ) ;
F_160 ( 3 , L_39 , V_7 , V_142 -> V_332 ) ;
return 0 ;
V_323:
F_146 ( ( unsigned long ) V_7 -> V_12 . V_314 ) ;
F_24 ( V_7 -> V_12 . V_333 ) ;
F_144 ( V_7 ) ;
F_160 ( 3 , L_40 , V_319 ) ;
return V_319 ;
}
bool F_161 ( void )
{
return false ;
}
int F_162 ( struct V_8 * V_9 )
{
return 0 ;
}
void F_163 ( struct V_8 * V_9 )
{
F_164 ( V_9 , 3 , L_3 , L_41 ) ;
F_165 ( V_9 -> V_350 ) ;
F_166 ( V_9 ) ;
F_167 ( V_9 ) ;
if ( ! F_39 ( V_9 -> V_7 ) )
F_168 ( V_9 ) ;
if ( F_39 ( V_9 -> V_7 ) )
F_59 ( V_9 -> V_12 . V_138 ) ;
if ( V_9 -> V_7 -> V_12 . V_181 )
F_169 ( V_9 ) ;
F_146 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_170 ( V_9 ) ;
F_171 ( V_351 , V_9 ) ;
}
static void F_172 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_163 ( V_9 ) ;
F_40 ( & V_7 -> V_159 ) ;
for ( V_10 = 0 ; V_10 < F_50 ( & V_7 -> V_165 ) ; V_10 ++ )
V_7 -> V_352 [ V_10 ] = NULL ;
F_173 ( & V_7 -> V_165 , 0 ) ;
F_44 ( & V_7 -> V_159 ) ;
}
void F_174 ( struct V_7 * V_7 )
{
F_172 ( V_7 ) ;
F_144 ( V_7 ) ;
F_24 ( V_7 -> V_12 . V_333 ) ;
F_146 ( ( unsigned long ) V_7 -> V_12 . V_314 ) ;
if ( ! F_39 ( V_7 ) )
F_59 ( V_7 -> V_12 . V_138 ) ;
F_175 ( V_7 ) ;
F_176 ( V_7 ) ;
F_177 ( V_7 ) ;
if ( V_7 -> V_12 . V_207 ) {
F_74 ( V_7 -> V_12 . V_207 -> V_212 ) ;
F_70 ( V_7 -> V_12 . V_207 ) ;
}
F_160 ( 3 , L_42 , V_7 ) ;
}
static int F_178 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_138 = F_58 ( V_142 -> V_141 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_138 )
return - V_82 ;
V_9 -> V_12 . V_138 -> V_188 = V_9 -> V_7 ;
return 0 ;
}
static void F_168 ( struct V_8 * V_9 )
{
if ( ! F_31 () )
return;
F_179 ( & V_9 -> V_7 -> V_12 . V_328 ) ;
if ( V_9 -> V_7 -> V_12 . V_315 ) {
struct V_317 * V_316 = V_9 -> V_7 -> V_12 . V_316 ;
F_180 ( V_9 -> V_350 , ( unsigned long * ) V_316 -> V_353 ) ;
V_316 -> V_354 [ V_9 -> V_350 ] . V_355 = 0 ;
} else {
struct V_329 * V_316 = V_9 -> V_7 -> V_12 . V_316 ;
F_180 ( V_9 -> V_350 , ( unsigned long * ) & V_316 -> V_353 ) ;
V_316 -> V_354 [ V_9 -> V_350 ] . V_355 = 0 ;
}
F_181 ( & V_9 -> V_7 -> V_12 . V_328 ) ;
}
static void F_182 ( struct V_8 * V_9 )
{
if ( ! F_31 () ) {
struct V_329 * V_316 = V_9 -> V_7 -> V_12 . V_316 ;
V_9 -> V_12 . V_14 -> V_356 = ( V_310 ) ( ( ( V_357 ) V_316 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_358 = ( V_310 ) ( V_357 ) V_316 ;
}
F_179 ( & V_9 -> V_7 -> V_12 . V_328 ) ;
if ( V_9 -> V_7 -> V_12 . V_315 ) {
struct V_317 * V_316 = V_9 -> V_7 -> V_12 . V_316 ;
V_316 -> V_354 [ V_9 -> V_350 ] . V_355 = ( V_357 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_356 = ( V_310 ) ( ( ( V_357 ) V_316 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_358 = ( V_310 ) ( V_357 ) V_316 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_359 |= V_360 ;
F_15 ( V_9 -> V_350 , ( unsigned long * ) V_316 -> V_353 ) ;
} else {
struct V_329 * V_316 = V_9 -> V_7 -> V_12 . V_316 ;
V_316 -> V_354 [ V_9 -> V_350 ] . V_355 = ( V_357 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_356 = ( V_310 ) ( ( ( V_357 ) V_316 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_358 = ( V_310 ) ( V_357 ) V_316 ;
F_15 ( V_9 -> V_350 , ( unsigned long * ) & V_316 -> V_353 ) ;
}
F_181 ( & V_9 -> V_7 -> V_12 . V_328 ) ;
}
static inline void F_183 ( struct V_361 * V_362 , struct V_363 * V_273 )
{
V_362 -> V_355 = V_273 -> V_355 ;
V_362 -> V_364 . V_365 = V_273 -> V_364 . V_365 ;
V_362 -> V_364 . V_366 = V_273 -> V_364 . V_366 ;
}
static void F_184 ( struct V_317 * V_362 , struct V_329 * V_273 )
{
int V_10 ;
V_362 -> V_367 = V_273 -> V_367 ;
V_362 -> V_353 [ 0 ] = V_273 -> V_353 ;
for ( V_10 = 0 ; V_10 < V_122 ; V_10 ++ )
F_183 ( & V_362 -> V_354 [ V_10 ] , & V_273 -> V_354 [ V_10 ] ) ;
}
static int F_185 ( struct V_7 * V_7 )
{
struct V_329 * V_368 = V_7 -> V_12 . V_316 ;
struct V_317 * V_369 ;
struct V_8 * V_9 ;
unsigned int V_370 ;
T_7 V_358 , V_356 ;
V_369 = F_186 ( sizeof( * V_369 ) , V_209 | V_371 ) ;
if ( ! V_369 )
return - V_82 ;
V_356 = ( T_7 ) ( ( V_173 ) ( V_369 ) >> 32 ) ;
V_358 = ( T_7 ) ( V_173 ) ( V_369 ) & ~ 0x3fU ;
F_187 ( V_7 ) ;
F_188 ( & V_7 -> V_12 . V_328 ) ;
F_184 ( V_369 , V_368 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_356 = V_356 ;
V_9 -> V_12 . V_14 -> V_358 = V_358 ;
V_9 -> V_12 . V_14 -> V_359 |= V_360 ;
}
V_7 -> V_12 . V_316 = V_369 ;
V_7 -> V_12 . V_315 = 1 ;
F_189 ( & V_7 -> V_12 . V_328 ) ;
F_190 ( V_7 ) ;
F_146 ( ( unsigned long ) V_368 ) ;
F_48 ( V_7 , 2 , L_43 ,
V_368 , V_7 -> V_12 . V_316 ) ;
return 0 ;
}
static int F_191 ( struct V_7 * V_7 , unsigned int V_372 )
{
int V_319 ;
if ( ! F_31 () ) {
if ( V_372 < V_123 )
return true ;
return false ;
}
if ( V_372 < V_122 )
return true ;
if ( ! V_60 . V_124 || ! V_60 . V_62 )
return false ;
F_40 ( & V_7 -> V_159 ) ;
V_319 = V_7 -> V_12 . V_315 ? 0 : F_185 ( V_7 ) ;
F_44 ( & V_7 -> V_159 ) ;
return V_319 == 0 && V_372 < V_125 ;
}
int F_192 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_373 = V_374 ;
F_167 ( V_9 ) ;
V_9 -> V_375 -> V_376 = V_377 |
V_378 |
V_379 |
V_380 |
V_381 |
V_382 ;
F_193 ( V_9 , 0 ) ;
if ( F_61 ( V_9 -> V_7 , 64 ) )
V_9 -> V_375 -> V_376 |= V_383 ;
if ( F_61 ( V_9 -> V_7 , 133 ) )
V_9 -> V_375 -> V_376 |= V_384 ;
if ( V_130 )
V_9 -> V_375 -> V_376 |= V_385 ;
else
V_9 -> V_375 -> V_376 |= V_386 ;
if ( F_39 ( V_9 -> V_7 ) )
return F_178 ( V_9 ) ;
return 0 ;
}
static void F_194 ( struct V_8 * V_9 )
{
F_195 ( V_9 -> V_12 . V_16 != 0 ) ;
F_196 ( & V_9 -> V_12 . V_387 ) ;
V_9 -> V_12 . V_16 = F_197 () ;
F_198 ( & V_9 -> V_12 . V_387 ) ;
}
static void F_199 ( struct V_8 * V_9 )
{
F_195 ( V_9 -> V_12 . V_16 == 0 ) ;
F_196 ( & V_9 -> V_12 . V_387 ) ;
V_9 -> V_12 . V_14 -> V_388 -= F_197 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_198 ( & V_9 -> V_12 . V_387 ) ;
}
static void F_200 ( struct V_8 * V_9 )
{
F_195 ( V_9 -> V_12 . V_15 ) ;
V_9 -> V_12 . V_15 = true ;
F_194 ( V_9 ) ;
}
static void F_201 ( struct V_8 * V_9 )
{
F_195 ( ! V_9 -> V_12 . V_15 ) ;
F_199 ( V_9 ) ;
V_9 -> V_12 . V_15 = false ;
}
static void F_202 ( struct V_8 * V_9 )
{
F_86 () ;
F_200 ( V_9 ) ;
F_88 () ;
}
static void F_203 ( struct V_8 * V_9 )
{
F_86 () ;
F_201 ( V_9 ) ;
F_88 () ;
}
void F_204 ( struct V_8 * V_9 , V_357 V_388 )
{
F_86 () ;
F_196 ( & V_9 -> V_12 . V_387 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_197 () ;
V_9 -> V_12 . V_14 -> V_388 = V_388 ;
F_198 ( & V_9 -> V_12 . V_387 ) ;
F_88 () ;
}
V_357 F_205 ( struct V_8 * V_9 )
{
unsigned int V_389 ;
V_357 V_390 ;
if ( F_124 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_388 ;
F_86 () ;
do {
V_389 = F_206 ( & V_9 -> V_12 . V_387 ) ;
F_195 ( ( V_389 & 1 ) && F_207 () == V_9 -> V_354 ) ;
V_390 = V_9 -> V_12 . V_14 -> V_388 ;
if ( F_208 ( V_9 -> V_12 . V_16 ) )
V_390 -= F_197 () - V_9 -> V_12 . V_16 ;
} while ( F_209 ( & V_9 -> V_12 . V_387 , V_389 & ~ 1 ) );
F_88 () ;
return V_390 ;
}
void F_210 ( struct V_8 * V_9 , int V_354 )
{
F_211 ( V_9 -> V_12 . V_391 ) ;
F_212 ( V_392 , & V_9 -> V_12 . V_14 -> V_393 ) ;
if ( V_9 -> V_12 . V_15 && ! F_213 ( V_9 ) )
F_194 ( V_9 ) ;
V_9 -> V_354 = V_354 ;
}
void F_214 ( struct V_8 * V_9 )
{
V_9 -> V_354 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_213 ( V_9 ) )
F_199 ( V_9 ) ;
F_215 ( V_392 , & V_9 -> V_12 . V_14 -> V_393 ) ;
V_9 -> V_12 . V_391 = F_216 () ;
F_217 ( V_9 -> V_12 . V_391 ) ;
}
static void F_218 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_394 . V_286 = 0UL ;
V_9 -> V_12 . V_14 -> V_394 . V_175 = 0UL ;
F_193 ( V_9 , 0 ) ;
F_204 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_395 = 0UL ;
V_9 -> V_12 . V_14 -> V_396 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_397 , 0 , 16 * sizeof( V_357 ) ) ;
V_9 -> V_12 . V_14 -> V_397 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_397 [ 14 ] = 0xC2000000UL ;
F_219 () ;
V_142 -> V_398 . V_399 . V_400 = 0 ;
V_9 -> V_12 . V_14 -> V_401 = 1 ;
V_9 -> V_12 . V_14 -> V_402 = 0 ;
V_9 -> V_12 . V_373 = V_374 ;
F_167 ( V_9 ) ;
if ( ! F_220 ( V_9 -> V_7 ) )
F_221 ( V_9 ) ;
F_166 ( V_9 ) ;
}
void F_222 ( struct V_8 * V_9 )
{
F_40 ( & V_9 -> V_7 -> V_159 ) ;
F_86 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_88 () ;
F_44 ( & V_9 -> V_7 -> V_159 ) ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_138 = V_9 -> V_7 -> V_12 . V_138 ;
F_182 ( V_9 ) ;
}
if ( F_61 ( V_9 -> V_7 , 74 ) || V_9 -> V_7 -> V_12 . V_167 )
V_9 -> V_12 . V_14 -> V_403 |= V_404 ;
V_9 -> V_12 . V_391 = V_9 -> V_12 . V_138 ;
}
static void F_63 ( struct V_8 * V_9 )
{
if ( ! F_61 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_405 &= ~ ( V_406 | V_407 ) ;
if ( V_9 -> V_7 -> V_12 . V_191 . V_194 )
V_9 -> V_12 . V_14 -> V_405 |= V_406 ;
if ( V_9 -> V_7 -> V_12 . V_191 . V_197 )
V_9 -> V_12 . V_14 -> V_405 |= V_407 ;
V_9 -> V_12 . V_14 -> V_309 = V_9 -> V_7 -> V_12 . V_191 . V_309 ;
}
void F_169 ( struct V_8 * V_9 )
{
F_146 ( V_9 -> V_12 . V_14 -> V_408 ) ;
V_9 -> V_12 . V_14 -> V_408 = 0 ;
}
int F_223 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_408 = F_151 ( V_209 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_408 )
return - V_82 ;
V_9 -> V_12 . V_14 -> V_359 &= ~ V_409 ;
return 0 ;
}
static void F_224 ( struct V_8 * V_9 )
{
struct V_410 * V_162 = & V_9 -> V_7 -> V_12 . V_162 ;
V_9 -> V_12 . V_14 -> V_238 = V_162 -> V_238 ;
if ( F_61 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_411 = ( T_7 ) ( V_173 ) V_162 -> V_164 ;
}
int F_225 ( struct V_8 * V_9 )
{
int V_319 = 0 ;
F_173 ( & V_9 -> V_12 . V_14 -> V_393 , V_412 |
V_413 |
V_414 ) ;
if ( F_61 ( V_9 -> V_7 , 78 ) )
F_212 ( V_415 , & V_9 -> V_12 . V_14 -> V_393 ) ;
else if ( F_61 ( V_9 -> V_7 , 8 ) )
F_212 ( V_416 , & V_9 -> V_12 . V_14 -> V_393 ) ;
F_224 ( V_9 ) ;
if ( V_58 )
V_9 -> V_12 . V_14 -> V_417 |= V_418 ;
if ( F_61 ( V_9 -> V_7 , 9 ) )
V_9 -> V_12 . V_14 -> V_417 |= V_419 ;
if ( F_61 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_417 |= V_420 ;
if ( F_61 ( V_9 -> V_7 , 8 ) && V_60 . V_421 )
V_9 -> V_12 . V_14 -> V_359 |= V_409 ;
if ( F_61 ( V_9 -> V_7 , 130 ) )
V_9 -> V_12 . V_14 -> V_359 |= V_422 ;
V_9 -> V_12 . V_14 -> V_423 = V_424 | V_425 ;
if ( V_60 . V_74 )
V_9 -> V_12 . V_14 -> V_423 |= V_426 ;
if ( V_60 . V_72 )
V_9 -> V_12 . V_14 -> V_423 |= V_427 ;
if ( V_60 . V_66 )
V_9 -> V_12 . V_14 -> V_423 |= V_428 ;
if ( V_60 . V_429 )
V_9 -> V_12 . V_14 -> V_423 |= V_430 ;
if ( F_61 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_423 |= V_431 ;
V_9 -> V_12 . V_14 -> V_432 |= V_433 ;
}
if ( F_61 ( V_9 -> V_7 , 139 ) )
V_9 -> V_12 . V_14 -> V_432 |= V_434 ;
V_9 -> V_12 . V_14 -> V_435 = ( ( unsigned long ) & V_9 -> V_375 -> V_273 . V_436 . V_437 )
| V_438 ;
V_9 -> V_12 . V_14 -> V_439 = ( unsigned long ) & V_9 -> V_375 -> V_273 . V_436 . V_440 ;
if ( V_60 . V_78 )
F_212 ( V_441 , & V_9 -> V_12 . V_14 -> V_393 ) ;
else
V_9 -> V_12 . V_14 -> V_403 |= V_442 | V_443 | V_444 ;
if ( V_9 -> V_7 -> V_12 . V_181 ) {
V_319 = F_223 ( V_9 ) ;
if ( V_319 )
return V_319 ;
}
F_226 ( & V_9 -> V_12 . V_445 , V_446 , V_447 ) ;
V_9 -> V_12 . V_445 . V_448 = V_449 ;
F_63 ( V_9 ) ;
return V_319 ;
}
struct V_8 * F_227 ( struct V_7 * V_7 ,
unsigned int V_372 )
{
struct V_8 * V_9 ;
struct V_450 * V_450 ;
int V_319 = - V_91 ;
if ( ! F_39 ( V_7 ) && ! F_191 ( V_7 , V_372 ) )
goto V_150;
V_319 = - V_82 ;
V_9 = F_228 ( V_351 , V_209 ) ;
if ( ! V_9 )
goto V_150;
F_2 ( sizeof( struct V_450 ) != 4096 ) ;
V_450 = (struct V_450 * ) F_151 ( V_209 ) ;
if ( ! V_450 )
goto V_451;
V_9 -> V_12 . V_14 = & V_450 -> V_14 ;
V_9 -> V_12 . V_14 -> V_452 = ( unsigned long ) & V_450 -> V_453 ;
V_9 -> V_12 . V_14 -> V_454 = 0 ;
V_9 -> V_12 . V_14 -> V_455 = V_60 . V_344 ;
V_9 -> V_12 . V_14 -> V_456 = V_372 ;
F_155 ( & V_9 -> V_12 . V_457 . V_159 ) ;
V_9 -> V_12 . V_457 . V_336 = & V_7 -> V_12 . V_336 ;
V_9 -> V_12 . V_457 . V_458 = & V_9 -> V_458 ;
V_9 -> V_12 . V_457 . V_393 = & V_9 -> V_12 . V_14 -> V_393 ;
F_229 ( & V_9 -> V_12 . V_387 ) ;
V_319 = F_230 ( V_9 , V_7 , V_372 ) ;
if ( V_319 )
goto V_459;
F_48 ( V_7 , 3 , L_44 , V_372 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_231 ( V_372 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_459:
F_146 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_451:
F_171 ( V_351 , V_9 ) ;
V_150:
return F_232 ( V_319 ) ;
}
int F_233 ( struct V_8 * V_9 )
{
return F_234 ( V_9 , 0 ) ;
}
bool F_235 ( struct V_8 * V_9 )
{
return ! ( V_9 -> V_12 . V_14 -> V_394 . V_286 & V_460 ) ;
}
void F_236 ( struct V_8 * V_9 )
{
F_212 ( V_461 , & V_9 -> V_12 . V_14 -> V_462 ) ;
F_64 ( V_9 ) ;
}
void F_237 ( struct V_8 * V_9 )
{
F_215 ( V_461 , & V_9 -> V_12 . V_14 -> V_462 ) ;
}
static void F_238 ( struct V_8 * V_9 )
{
F_212 ( V_463 , & V_9 -> V_12 . V_14 -> V_462 ) ;
F_64 ( V_9 ) ;
}
static void F_239 ( struct V_8 * V_9 )
{
F_215 ( V_463 , & V_9 -> V_12 . V_14 -> V_462 ) ;
}
void F_64 ( struct V_8 * V_9 )
{
F_212 ( V_464 , & V_9 -> V_12 . V_14 -> V_393 ) ;
while ( V_9 -> V_12 . V_14 -> V_465 & V_466 )
F_240 () ;
}
void F_46 ( int V_200 , struct V_8 * V_9 )
{
F_241 ( V_200 , V_9 ) ;
F_238 ( V_9 ) ;
}
static void V_21 ( struct V_138 * V_138 , unsigned long V_467 ,
unsigned long V_468 )
{
struct V_7 * V_7 = V_138 -> V_188 ;
struct V_8 * V_9 ;
unsigned long V_469 ;
int V_10 ;
if ( F_242 ( V_138 ) )
return;
if ( V_467 >= 1UL << 31 )
return;
F_7 (i, vcpu, kvm) {
V_469 = F_243 ( V_9 ) ;
if ( V_469 <= V_468 && V_467 <= V_469 + 2 * V_331 - 1 ) {
F_164 ( V_9 , 2 , L_45 ,
V_467 , V_468 ) ;
F_46 ( V_470 , V_9 ) ;
}
}
}
int F_244 ( struct V_8 * V_9 )
{
F_245 () ;
return 0 ;
}
static int F_246 ( struct V_8 * V_9 ,
struct V_471 * V_472 )
{
int V_93 = - V_91 ;
switch ( V_472 -> V_372 ) {
case V_473 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_396 ,
( T_7 V_174 * ) V_472 -> V_175 ) ;
break;
case V_474 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_475 :
V_93 = F_52 ( F_205 ( V_9 ) ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_476 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_395 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_477 :
V_93 = F_52 ( V_9 -> V_12 . V_373 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_478 :
V_93 = F_52 ( V_9 -> V_12 . V_479 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_480 :
V_93 = F_52 ( V_9 -> V_12 . V_481 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_482 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_402 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_483 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_401 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
default:
break;
}
return V_93 ;
}
static int F_247 ( struct V_8 * V_9 ,
struct V_471 * V_472 )
{
int V_93 = - V_91 ;
V_357 V_5 ;
switch ( V_472 -> V_372 ) {
case V_473 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_396 ,
( T_7 V_174 * ) V_472 -> V_175 ) ;
break;
case V_474 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_475 :
V_93 = F_57 ( V_5 , ( V_173 V_174 * ) V_472 -> V_175 ) ;
if ( ! V_93 )
F_204 ( V_9 , V_5 ) ;
break;
case V_476 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_395 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_477 :
V_93 = F_57 ( V_9 -> V_12 . V_373 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
if ( V_9 -> V_12 . V_373 == V_374 )
F_167 ( V_9 ) ;
break;
case V_478 :
V_93 = F_57 ( V_9 -> V_12 . V_479 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_480 :
V_93 = F_57 ( V_9 -> V_12 . V_481 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_482 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_402 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
case V_483 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_401 ,
( V_173 V_174 * ) V_472 -> V_175 ) ;
break;
default:
break;
}
return V_93 ;
}
static int F_248 ( struct V_8 * V_9 )
{
F_218 ( V_9 ) ;
return 0 ;
}
int F_249 ( struct V_8 * V_9 , struct V_484 * V_436 )
{
memcpy ( & V_9 -> V_375 -> V_273 . V_436 . V_485 , & V_436 -> V_485 , sizeof( V_436 -> V_485 ) ) ;
return 0 ;
}
int F_250 ( struct V_8 * V_9 , struct V_484 * V_436 )
{
memcpy ( & V_436 -> V_485 , & V_9 -> V_375 -> V_273 . V_436 . V_485 , sizeof( V_436 -> V_485 ) ) ;
return 0 ;
}
int F_251 ( struct V_8 * V_9 ,
struct V_486 * V_487 )
{
memcpy ( & V_9 -> V_375 -> V_273 . V_436 . V_488 , & V_487 -> V_488 , sizeof( V_487 -> V_488 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_397 , & V_487 -> V_489 , sizeof( V_487 -> V_489 ) ) ;
return 0 ;
}
int F_252 ( struct V_8 * V_9 ,
struct V_486 * V_487 )
{
memcpy ( & V_487 -> V_488 , & V_9 -> V_375 -> V_273 . V_436 . V_488 , sizeof( V_487 -> V_488 ) ) ;
memcpy ( & V_487 -> V_489 , & V_9 -> V_12 . V_14 -> V_397 , sizeof( V_487 -> V_489 ) ) ;
return 0 ;
}
int F_253 ( struct V_8 * V_9 , struct V_490 * V_399 )
{
if ( F_254 ( V_399 -> V_400 ) )
return - V_91 ;
V_9 -> V_375 -> V_273 . V_436 . V_400 = V_399 -> V_400 ;
if ( V_130 )
F_255 ( ( V_491 * ) V_9 -> V_375 -> V_273 . V_436 . V_492 ,
( V_493 * ) V_399 -> V_494 ) ;
else
memcpy ( V_9 -> V_375 -> V_273 . V_436 . V_494 , & V_399 -> V_494 , sizeof( V_399 -> V_494 ) ) ;
return 0 ;
}
int F_256 ( struct V_8 * V_9 , struct V_490 * V_399 )
{
F_219 () ;
if ( V_130 )
F_257 ( ( V_493 * ) V_399 -> V_494 ,
( V_491 * ) V_9 -> V_375 -> V_273 . V_436 . V_492 ) ;
else
memcpy ( V_399 -> V_494 , V_9 -> V_375 -> V_273 . V_436 . V_494 , sizeof( V_399 -> V_494 ) ) ;
V_399 -> V_400 = V_9 -> V_375 -> V_273 . V_436 . V_400 ;
return 0 ;
}
static int F_258 ( struct V_8 * V_9 , T_9 V_495 )
{
int V_319 = 0 ;
if ( ! F_259 ( V_9 ) )
V_319 = - V_161 ;
else {
V_9 -> V_375 -> V_496 = V_495 . V_286 ;
V_9 -> V_375 -> V_497 = V_495 . V_175 ;
}
return V_319 ;
}
int F_260 ( struct V_8 * V_9 ,
struct V_498 * V_499 )
{
return - V_91 ;
}
int F_261 ( struct V_8 * V_9 ,
struct V_500 * V_501 )
{
int V_319 = 0 ;
V_9 -> V_502 = 0 ;
F_262 ( V_9 ) ;
if ( V_501 -> V_503 & ~ V_504 )
return - V_91 ;
if ( ! V_60 . V_68 )
return - V_91 ;
if ( V_501 -> V_503 & V_505 ) {
V_9 -> V_502 = V_501 -> V_503 ;
F_212 ( V_506 , & V_9 -> V_12 . V_14 -> V_393 ) ;
if ( V_501 -> V_503 & V_507 )
V_319 = F_263 ( V_9 , V_501 ) ;
} else {
F_215 ( V_506 , & V_9 -> V_12 . V_14 -> V_393 ) ;
V_9 -> V_12 . V_508 . V_509 = 0 ;
}
if ( V_319 ) {
V_9 -> V_502 = 0 ;
F_262 ( V_9 ) ;
F_215 ( V_506 , & V_9 -> V_12 . V_14 -> V_393 ) ;
}
return V_319 ;
}
int F_264 ( struct V_8 * V_9 ,
struct V_510 * V_511 )
{
return F_259 ( V_9 ) ? V_512 :
V_513 ;
}
int F_265 ( struct V_8 * V_9 ,
struct V_510 * V_511 )
{
int V_319 = 0 ;
V_9 -> V_7 -> V_12 . V_514 = 1 ;
switch ( V_511 -> V_511 ) {
case V_512 :
F_221 ( V_9 ) ;
break;
case V_513 :
F_266 ( V_9 ) ;
break;
case V_515 :
case V_516 :
default:
V_319 = - V_177 ;
}
return V_319 ;
}
static bool F_267 ( struct V_8 * V_9 )
{
return F_50 ( & V_9 -> V_12 . V_14 -> V_393 ) & V_517 ;
}
static int F_268 ( struct V_8 * V_9 )
{
V_518:
F_239 ( V_9 ) ;
if ( ! F_269 ( V_9 ) )
return 0 ;
if ( F_270 ( V_470 , V_9 ) ) {
int V_319 ;
V_319 = F_271 ( V_9 -> V_12 . V_138 ,
F_243 ( V_9 ) ,
V_331 * 2 , V_519 ) ;
if ( V_319 ) {
F_241 ( V_470 , V_9 ) ;
return V_319 ;
}
goto V_518;
}
if ( F_270 ( V_520 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_521 = 0xffff ;
goto V_518;
}
if ( F_270 ( V_522 , V_9 ) ) {
if ( ! F_267 ( V_9 ) ) {
F_272 ( V_9 -> V_350 , 1 ) ;
F_212 ( V_517 ,
& V_9 -> V_12 . V_14 -> V_393 ) ;
}
goto V_518;
}
if ( F_270 ( V_523 , V_9 ) ) {
if ( F_267 ( V_9 ) ) {
F_272 ( V_9 -> V_350 , 0 ) ;
F_215 ( V_517 ,
& V_9 -> V_12 . V_14 -> V_393 ) ;
}
goto V_518;
}
if ( F_270 ( V_153 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_403 |= V_404 ;
goto V_518;
}
if ( F_270 ( V_215 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_359 &= ~ V_524 ;
goto V_518;
}
if ( F_270 ( V_216 , V_9 ) ) {
if ( ( V_9 -> V_7 -> V_12 . V_181 ) &&
( V_9 -> V_7 -> V_141 -> V_282 . V_181 ) )
V_9 -> V_12 . V_14 -> V_359 |= V_524 ;
goto V_518;
}
F_273 ( V_525 , V_9 ) ;
return 0 ;
}
void F_80 ( struct V_7 * V_7 ,
const struct V_222 * V_223 )
{
struct V_8 * V_9 ;
struct V_230 V_231 ;
int V_10 ;
F_40 ( & V_7 -> V_159 ) ;
F_86 () ;
F_87 ( ( char * ) & V_231 ) ;
V_7 -> V_12 . V_13 = V_223 -> V_225 - V_231 . V_225 ;
V_7 -> V_12 . V_232 = V_223 -> V_224 - V_231 . V_224 ;
if ( V_7 -> V_12 . V_13 > V_223 -> V_225 )
V_7 -> V_12 . V_232 -= 1 ;
F_187 ( V_7 ) ;
F_7 (i, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
V_9 -> V_12 . V_14 -> V_232 = V_7 -> V_12 . V_232 ;
}
F_190 ( V_7 ) ;
F_88 () ;
F_44 ( & V_7 -> V_159 ) ;
}
void F_81 ( struct V_7 * V_7 , V_173 V_225 )
{
struct V_8 * V_9 ;
int V_10 ;
F_40 ( & V_7 -> V_159 ) ;
F_86 () ;
V_7 -> V_12 . V_13 = V_225 - F_274 () ;
F_187 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_190 ( V_7 ) ;
F_88 () ;
F_44 ( & V_7 -> V_159 ) ;
}
long F_275 ( struct V_8 * V_9 , T_10 V_526 , int V_527 )
{
return F_276 ( V_9 -> V_12 . V_138 , V_526 ,
V_527 ? V_528 : 0 ) ;
}
static void F_277 ( struct V_8 * V_9 , bool V_529 ,
unsigned long V_530 )
{
struct V_293 V_531 ;
struct V_532 V_533 ;
if ( V_529 ) {
V_533 . V_534 . V_92 . V_535 = V_530 ;
V_533 . type = V_536 ;
F_195 ( F_278 ( V_9 , & V_533 ) ) ;
} else {
V_531 . type = V_537 ;
V_531 . V_538 = V_530 ;
F_195 ( F_136 ( V_9 -> V_7 , & V_531 ) ) ;
}
}
void F_279 ( struct V_8 * V_9 ,
struct V_539 * V_540 )
{
F_280 ( V_9 , V_540 -> V_12 . V_373 ) ;
F_277 ( V_9 , true , V_540 -> V_12 . V_373 ) ;
}
void F_281 ( struct V_8 * V_9 ,
struct V_539 * V_540 )
{
F_282 ( V_9 , V_540 -> V_12 . V_373 ) ;
F_277 ( V_9 , false , V_540 -> V_12 . V_373 ) ;
}
void F_283 ( struct V_8 * V_9 ,
struct V_539 * V_540 )
{
}
bool F_284 ( struct V_8 * V_9 )
{
return true ;
}
static int F_285 ( struct V_8 * V_9 )
{
T_11 V_264 ;
struct V_541 V_12 ;
int V_319 ;
if ( V_9 -> V_12 . V_373 == V_374 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_394 . V_286 & V_9 -> V_12 . V_481 ) !=
V_9 -> V_12 . V_479 )
return 0 ;
if ( F_286 ( V_9 ) )
return 0 ;
if ( F_234 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_397 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_138 -> V_347 )
return 0 ;
V_264 = F_115 ( V_9 -> V_7 , F_287 ( V_142 -> V_398 . V_542 ) ) ;
V_264 += V_142 -> V_398 . V_542 & ~ V_543 ;
if ( F_288 ( V_9 , V_9 -> V_12 . V_373 , & V_12 . V_373 , 8 ) )
return 0 ;
V_319 = F_289 ( V_9 , V_142 -> V_398 . V_542 , V_264 , & V_12 ) ;
return V_319 ;
}
static int F_290 ( struct V_8 * V_9 )
{
int V_319 , V_393 ;
F_291 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_544 = V_9 -> V_375 -> V_273 . V_436 . V_485 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_545 = V_9 -> V_375 -> V_273 . V_436 . V_485 [ 15 ] ;
if ( F_292 () )
F_293 () ;
if ( F_294 ( V_546 ) )
F_295 () ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_319 = F_296 ( V_9 ) ;
if ( V_319 )
return V_319 ;
}
V_319 = F_268 ( V_9 ) ;
if ( V_319 )
return V_319 ;
if ( F_297 ( V_9 ) ) {
F_298 ( V_9 ) ;
F_299 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_547 = 0 ;
V_393 = F_50 ( & V_9 -> V_12 . V_14 -> V_393 ) ;
F_164 ( V_9 , 6 , L_46 , V_393 ) ;
F_300 ( V_9 , V_393 ) ;
return 0 ;
}
static int F_301 ( struct V_8 * V_9 )
{
struct V_548 V_549 = {
. V_550 = V_551 ,
} ;
T_3 V_552 , V_553 ;
int V_319 ;
F_164 ( V_9 , 3 , L_3 , L_47 ) ;
F_302 ( V_9 ) ;
V_319 = F_303 ( V_9 , V_9 -> V_12 . V_14 -> V_394 . V_175 , & V_552 , 1 ) ;
V_553 = F_304 ( V_552 ) ;
if ( V_319 < 0 ) {
return V_319 ;
} else if ( V_319 ) {
V_549 = V_9 -> V_12 . V_554 ;
V_553 = 4 ;
}
V_549 . V_156 = V_553 | V_555 ;
F_305 ( V_9 , V_553 ) ;
return F_306 ( V_9 , & V_549 ) ;
}
static int F_307 ( struct V_8 * V_9 , int V_556 )
{
struct V_557 * V_558 ;
struct V_450 * V_450 ;
F_164 ( V_9 , 6 , L_48 ,
V_9 -> V_12 . V_14 -> V_547 ) ;
F_308 ( V_9 , V_9 -> V_12 . V_14 -> V_547 ) ;
if ( F_297 ( V_9 ) )
F_309 ( V_9 ) ;
V_9 -> V_375 -> V_273 . V_436 . V_485 [ 14 ] = V_9 -> V_12 . V_14 -> V_544 ;
V_9 -> V_375 -> V_273 . V_436 . V_485 [ 15 ] = V_9 -> V_12 . V_14 -> V_545 ;
if ( V_556 == - V_559 ) {
F_164 ( V_9 , 3 , L_3 , L_49 ) ;
V_450 = F_310 ( V_9 -> V_12 . V_14 ,
struct V_450 , V_14 ) ;
V_558 = & V_450 -> V_558 ;
F_311 ( V_9 , V_558 ) ;
return 0 ;
}
if ( V_9 -> V_12 . V_14 -> V_547 > 0 ) {
int V_319 = F_312 ( V_9 ) ;
if ( V_319 != - V_560 )
return V_319 ;
V_9 -> V_375 -> V_556 = V_561 ;
V_9 -> V_375 -> V_562 . V_547 = V_9 -> V_12 . V_14 -> V_547 ;
V_9 -> V_375 -> V_562 . V_563 = V_9 -> V_12 . V_14 -> V_563 ;
V_9 -> V_375 -> V_562 . V_564 = V_9 -> V_12 . V_14 -> V_564 ;
return - V_565 ;
} else if ( V_556 != - V_176 ) {
V_9 -> V_566 . V_567 ++ ;
return 0 ;
} else if ( F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_375 -> V_556 = V_568 ;
V_9 -> V_375 -> V_569 . V_570 =
V_142 -> V_398 . V_542 ;
V_9 -> V_375 -> V_569 . V_571 = 0x10 ;
return - V_565 ;
} else if ( V_142 -> V_398 . V_572 ) {
F_313 ( V_9 ) ;
V_142 -> V_398 . V_572 = 0 ;
if ( F_285 ( V_9 ) )
return 0 ;
return F_275 ( V_9 , V_142 -> V_398 . V_542 , 1 ) ;
}
return F_301 ( V_9 ) ;
}
static int F_314 ( struct V_8 * V_9 )
{
int V_319 , V_556 ;
V_9 -> V_265 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
do {
V_319 = F_290 ( V_9 ) ;
if ( V_319 )
break;
F_56 ( & V_9 -> V_7 -> V_183 , V_9 -> V_265 ) ;
F_315 () ;
F_316 () ;
F_201 ( V_9 ) ;
F_317 () ;
V_556 = F_318 ( V_9 -> V_12 . V_14 ,
V_9 -> V_375 -> V_273 . V_436 . V_485 ) ;
F_315 () ;
F_200 ( V_9 ) ;
F_319 () ;
F_317 () ;
V_9 -> V_265 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
V_319 = F_307 ( V_9 , V_556 ) ;
} while ( ! F_320 ( V_142 ) && ! F_321 ( V_9 ) && ! V_319 );
F_56 ( & V_9 -> V_7 -> V_183 , V_9 -> V_265 ) ;
return V_319 ;
}
static void F_322 ( struct V_8 * V_9 , struct V_573 * V_573 )
{
struct V_574 * V_440 ;
struct V_575 * V_576 ;
V_440 = (struct V_574 * ) & V_573 -> V_273 . V_436 . V_440 ;
V_576 = (struct V_575 * ) & V_573 -> V_273 . V_436 . V_576 ;
V_9 -> V_12 . V_14 -> V_394 . V_286 = V_573 -> V_496 ;
V_9 -> V_12 . V_14 -> V_394 . V_175 = V_573 -> V_497 ;
if ( V_573 -> V_577 & V_377 )
F_193 ( V_9 , V_573 -> V_273 . V_436 . V_469 ) ;
if ( V_573 -> V_577 & V_380 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_397 , & V_573 -> V_273 . V_436 . V_489 , 128 ) ;
F_241 ( V_520 , V_9 ) ;
}
if ( V_573 -> V_577 & V_381 ) {
F_204 ( V_9 , V_573 -> V_273 . V_436 . V_388 ) ;
V_9 -> V_12 . V_14 -> V_395 = V_573 -> V_273 . V_436 . V_395 ;
V_9 -> V_12 . V_14 -> V_396 = V_573 -> V_273 . V_436 . V_396 ;
V_9 -> V_12 . V_14 -> V_402 = V_573 -> V_273 . V_436 . V_402 ;
V_9 -> V_12 . V_14 -> V_401 = V_573 -> V_273 . V_436 . V_401 ;
}
if ( V_573 -> V_577 & V_382 ) {
V_9 -> V_12 . V_373 = V_573 -> V_273 . V_436 . V_578 ;
V_9 -> V_12 . V_481 = V_573 -> V_273 . V_436 . V_579 ;
V_9 -> V_12 . V_479 = V_573 -> V_273 . V_436 . V_580 ;
if ( V_9 -> V_12 . V_373 == V_374 )
F_167 ( V_9 ) ;
}
if ( ( V_573 -> V_577 & V_383 ) &&
F_61 ( V_9 -> V_7 , 64 ) &&
V_440 -> V_581 &&
! ( V_9 -> V_12 . V_14 -> V_405 & V_582 ) ) {
F_164 ( V_9 , 3 , L_3 , L_50 ) ;
V_9 -> V_12 . V_14 -> V_405 |= V_582 ;
}
if ( ( V_573 -> V_577 & V_384 ) &&
F_61 ( V_9 -> V_7 , 133 ) &&
V_576 -> V_583 &&
! V_9 -> V_12 . V_584 ) {
F_164 ( V_9 , 3 , L_3 , L_51 ) ;
V_9 -> V_12 . V_14 -> V_417 |= V_585 ;
V_9 -> V_12 . V_14 -> V_432 |= V_433 ;
V_9 -> V_12 . V_584 = 1 ;
}
F_323 ( V_9 -> V_12 . V_586 ) ;
F_324 ( V_9 -> V_375 -> V_273 . V_436 . V_488 ) ;
F_219 () ;
V_9 -> V_12 . V_587 . V_400 = V_142 -> V_398 . V_399 . V_400 ;
V_9 -> V_12 . V_587 . V_436 = V_142 -> V_398 . V_399 . V_436 ;
if ( V_130 )
V_142 -> V_398 . V_399 . V_436 = V_9 -> V_375 -> V_273 . V_436 . V_492 ;
else
V_142 -> V_398 . V_399 . V_436 = V_9 -> V_375 -> V_273 . V_436 . V_494 ;
V_142 -> V_398 . V_399 . V_400 = V_9 -> V_375 -> V_273 . V_436 . V_400 ;
if ( F_254 ( V_142 -> V_398 . V_399 . V_400 ) )
V_142 -> V_398 . V_399 . V_400 = 0 ;
if ( V_588 ) {
F_86 () ;
F_325 ( 2 , 4 ) ;
if ( V_142 -> V_398 . V_575 ) {
V_9 -> V_12 . V_589 = V_142 -> V_398 . V_575 ;
F_326 ( V_9 -> V_12 . V_589 ) ;
}
if ( V_9 -> V_12 . V_584 ) {
V_142 -> V_398 . V_575 = (struct V_575 * )
& V_9 -> V_375 -> V_273 . V_436 . V_576 ;
F_327 ( V_142 -> V_398 . V_575 ) ;
}
F_88 () ;
}
V_573 -> V_577 = 0 ;
}
static void F_328 ( struct V_8 * V_9 , struct V_573 * V_573 )
{
V_573 -> V_496 = V_9 -> V_12 . V_14 -> V_394 . V_286 ;
V_573 -> V_497 = V_9 -> V_12 . V_14 -> V_394 . V_175 ;
V_573 -> V_273 . V_436 . V_469 = F_243 ( V_9 ) ;
memcpy ( & V_573 -> V_273 . V_436 . V_489 , & V_9 -> V_12 . V_14 -> V_397 , 128 ) ;
V_573 -> V_273 . V_436 . V_388 = F_205 ( V_9 ) ;
V_573 -> V_273 . V_436 . V_395 = V_9 -> V_12 . V_14 -> V_395 ;
V_573 -> V_273 . V_436 . V_396 = V_9 -> V_12 . V_14 -> V_396 ;
V_573 -> V_273 . V_436 . V_402 = V_9 -> V_12 . V_14 -> V_402 ;
V_573 -> V_273 . V_436 . V_401 = V_9 -> V_12 . V_14 -> V_401 ;
V_573 -> V_273 . V_436 . V_578 = V_9 -> V_12 . V_373 ;
V_573 -> V_273 . V_436 . V_579 = V_9 -> V_12 . V_481 ;
V_573 -> V_273 . V_436 . V_580 = V_9 -> V_12 . V_479 ;
F_323 ( V_9 -> V_375 -> V_273 . V_436 . V_488 ) ;
F_324 ( V_9 -> V_12 . V_586 ) ;
F_219 () ;
V_9 -> V_375 -> V_273 . V_436 . V_400 = V_142 -> V_398 . V_399 . V_400 ;
V_142 -> V_398 . V_399 . V_400 = V_9 -> V_12 . V_587 . V_400 ;
V_142 -> V_398 . V_399 . V_436 = V_9 -> V_12 . V_587 . V_436 ;
if ( V_588 ) {
F_325 ( 2 , 4 ) ;
if ( V_9 -> V_12 . V_584 )
F_326 ( V_142 -> V_398 . V_575 ) ;
F_86 () ;
V_142 -> V_398 . V_575 = V_9 -> V_12 . V_589 ;
F_327 ( V_9 -> V_12 . V_589 ) ;
F_88 () ;
if ( ! V_9 -> V_12 . V_589 )
F_329 ( 2 , 4 ) ;
V_9 -> V_12 . V_589 = NULL ;
}
}
int F_330 ( struct V_8 * V_9 , struct V_573 * V_573 )
{
int V_319 ;
T_12 V_590 ;
if ( V_573 -> V_591 )
return - V_559 ;
if ( F_321 ( V_9 ) ) {
F_331 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_592 )
F_332 ( V_593 , & V_9 -> V_594 , & V_590 ) ;
if ( ! F_220 ( V_9 -> V_7 ) ) {
F_266 ( V_9 ) ;
} else if ( F_259 ( V_9 ) ) {
F_333 ( L_52 ,
V_9 -> V_350 ) ;
return - V_91 ;
}
F_322 ( V_9 , V_573 ) ;
F_202 ( V_9 ) ;
F_334 () ;
V_319 = F_314 ( V_9 ) ;
if ( F_320 ( V_142 ) && ! V_319 ) {
V_573 -> V_556 = V_595 ;
V_319 = - V_559 ;
}
if ( F_321 ( V_9 ) && ! V_319 ) {
F_331 ( V_9 ) ;
V_319 = 0 ;
}
if ( V_319 == - V_565 ) {
V_319 = 0 ;
}
F_203 ( V_9 ) ;
F_328 ( V_9 , V_573 ) ;
if ( V_9 -> V_592 )
F_332 ( V_593 , & V_590 , NULL ) ;
V_9 -> V_566 . V_596 ++ ;
return V_319 ;
}
int F_335 ( struct V_8 * V_9 , unsigned long V_526 )
{
unsigned char V_597 = 1 ;
V_493 V_494 [ V_598 ] ;
unsigned int V_599 ;
V_173 V_600 , V_388 ;
int V_319 ;
V_599 = F_243 ( V_9 ) ;
if ( V_526 == V_601 ) {
if ( F_336 ( V_9 , 163 , & V_597 , 1 ) )
return - V_176 ;
V_526 = 0 ;
} else if ( V_526 == V_602 ) {
if ( F_337 ( V_9 , 163 , & V_597 , 1 ) )
return - V_176 ;
V_526 = V_599 ;
} else
V_526 -= V_603 ;
if ( V_130 ) {
F_257 ( V_494 , ( V_491 * ) V_9 -> V_375 -> V_273 . V_436 . V_492 ) ;
V_319 = F_336 ( V_9 , V_526 + V_603 ,
V_494 , 128 ) ;
} else {
V_319 = F_336 ( V_9 , V_526 + V_603 ,
V_9 -> V_375 -> V_273 . V_436 . V_494 , 128 ) ;
}
V_319 |= F_336 ( V_9 , V_526 + V_604 ,
V_9 -> V_375 -> V_273 . V_436 . V_485 , 128 ) ;
V_319 |= F_336 ( V_9 , V_526 + V_605 ,
& V_9 -> V_12 . V_14 -> V_394 , 16 ) ;
V_319 |= F_336 ( V_9 , V_526 + V_606 ,
& V_599 , 4 ) ;
V_319 |= F_336 ( V_9 , V_526 + V_607 ,
& V_9 -> V_375 -> V_273 . V_436 . V_400 , 4 ) ;
V_319 |= F_336 ( V_9 , V_526 + V_608 ,
& V_9 -> V_12 . V_14 -> V_396 , 4 ) ;
V_388 = F_205 ( V_9 ) ;
V_319 |= F_336 ( V_9 , V_526 + V_609 ,
& V_388 , 8 ) ;
V_600 = V_9 -> V_12 . V_14 -> V_395 >> 8 ;
V_319 |= F_336 ( V_9 , V_526 + V_610 ,
& V_600 , 8 ) ;
V_319 |= F_336 ( V_9 , V_526 + V_611 ,
& V_9 -> V_375 -> V_273 . V_436 . V_488 , 64 ) ;
V_319 |= F_336 ( V_9 , V_526 + V_612 ,
& V_9 -> V_12 . V_14 -> V_397 , 128 ) ;
return V_319 ? - V_176 : 0 ;
}
int F_338 ( struct V_8 * V_9 , unsigned long V_175 )
{
F_219 () ;
V_9 -> V_375 -> V_273 . V_436 . V_400 = V_142 -> V_398 . V_399 . V_400 ;
F_323 ( V_9 -> V_375 -> V_273 . V_436 . V_488 ) ;
return F_335 ( V_9 , V_175 ) ;
}
static void F_339 ( struct V_8 * V_9 )
{
F_270 ( V_522 , V_9 ) ;
F_46 ( V_523 , V_9 ) ;
}
static void F_340 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_339 ( V_9 ) ;
}
}
static void F_341 ( struct V_8 * V_9 )
{
if ( ! V_60 . V_76 )
return;
F_270 ( V_523 , V_9 ) ;
F_46 ( V_522 , V_9 ) ;
}
void F_266 ( struct V_8 * V_9 )
{
int V_10 , V_165 , V_613 = 0 ;
if ( ! F_259 ( V_9 ) )
return;
F_342 ( V_9 -> V_350 , 1 ) ;
F_152 ( & V_9 -> V_7 -> V_12 . V_349 ) ;
V_165 = F_50 ( & V_9 -> V_7 -> V_165 ) ;
for ( V_10 = 0 ; V_10 < V_165 ; V_10 ++ ) {
if ( ! F_259 ( V_9 -> V_7 -> V_352 [ V_10 ] ) )
V_613 ++ ;
}
if ( V_613 == 0 ) {
F_341 ( V_9 ) ;
} else if ( V_613 == 1 ) {
F_340 ( V_9 -> V_7 ) ;
}
F_215 ( V_414 , & V_9 -> V_12 . V_14 -> V_393 ) ;
F_241 ( V_520 , V_9 ) ;
F_153 ( & V_9 -> V_7 -> V_12 . V_349 ) ;
return;
}
void F_221 ( struct V_8 * V_9 )
{
int V_10 , V_165 , V_613 = 0 ;
struct V_8 * V_614 = NULL ;
if ( F_259 ( V_9 ) )
return;
F_342 ( V_9 -> V_350 , 0 ) ;
F_152 ( & V_9 -> V_7 -> V_12 . V_349 ) ;
V_165 = F_50 ( & V_9 -> V_7 -> V_165 ) ;
F_343 ( V_9 ) ;
F_212 ( V_414 , & V_9 -> V_12 . V_14 -> V_393 ) ;
F_339 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_165 ; V_10 ++ ) {
if ( ! F_259 ( V_9 -> V_7 -> V_352 [ V_10 ] ) ) {
V_613 ++ ;
V_614 = V_9 -> V_7 -> V_352 [ V_10 ] ;
}
}
if ( V_613 == 1 ) {
F_341 ( V_614 ) ;
}
F_153 ( & V_9 -> V_7 -> V_12 . V_349 ) ;
return;
}
static int F_344 ( struct V_8 * V_9 ,
struct V_154 * V_155 )
{
int V_93 ;
if ( V_155 -> V_156 )
return - V_91 ;
switch ( V_155 -> V_155 ) {
case V_102 :
if ( ! V_9 -> V_7 -> V_12 . V_348 ) {
V_9 -> V_7 -> V_12 . V_348 = 1 ;
F_48 ( V_9 -> V_7 , 3 , L_3 , L_53 ) ;
F_345 ( V_9 -> V_7 ) ;
}
V_93 = 0 ;
break;
default:
V_93 = - V_91 ;
break;
}
return V_93 ;
}
static long F_346 ( struct V_8 * V_9 ,
struct V_615 * V_616 )
{
void V_174 * V_617 = ( void V_174 * ) V_616 -> V_618 ;
void * V_619 = NULL ;
int V_93 , V_265 ;
const V_173 V_620 = V_621
| V_622 ;
if ( V_616 -> V_156 & ~ V_620 )
return - V_91 ;
if ( V_616 -> V_623 > V_119 )
return - V_186 ;
if ( ! ( V_616 -> V_156 & V_622 ) ) {
V_619 = F_69 ( V_616 -> V_623 ) ;
if ( ! V_619 )
return - V_82 ;
}
V_265 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
switch ( V_616 -> V_624 ) {
case V_625 :
if ( V_616 -> V_156 & V_622 ) {
V_93 = F_347 ( V_9 , V_616 -> V_626 , V_616 -> V_627 ,
V_616 -> V_623 , V_628 ) ;
break;
}
V_93 = F_348 ( V_9 , V_616 -> V_626 , V_616 -> V_627 , V_619 , V_616 -> V_623 ) ;
if ( V_93 == 0 ) {
if ( F_77 ( V_617 , V_619 , V_616 -> V_623 ) )
V_93 = - V_176 ;
}
break;
case V_629 :
if ( V_616 -> V_156 & V_622 ) {
V_93 = F_347 ( V_9 , V_616 -> V_626 , V_616 -> V_627 ,
V_616 -> V_623 , V_630 ) ;
break;
}
if ( F_79 ( V_619 , V_617 , V_616 -> V_623 ) ) {
V_93 = - V_176 ;
break;
}
V_93 = F_349 ( V_9 , V_616 -> V_626 , V_616 -> V_627 , V_619 , V_616 -> V_623 ) ;
break;
default:
V_93 = - V_91 ;
}
F_56 ( & V_9 -> V_7 -> V_183 , V_265 ) ;
if ( V_93 > 0 && ( V_616 -> V_156 & V_621 ) != 0 )
F_306 ( V_9 , & V_9 -> V_12 . V_554 ) ;
F_74 ( V_619 ) ;
return V_93 ;
}
long F_350 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_8 * V_9 = V_87 -> V_290 ;
void V_174 * V_291 = ( void V_174 * ) V_89 ;
int V_178 ;
long V_93 ;
switch ( V_88 ) {
case V_631 : {
struct V_532 V_632 ;
V_93 = - V_176 ;
if ( F_79 ( & V_632 , V_291 , sizeof( V_632 ) ) )
break;
V_93 = F_278 ( V_9 , & V_632 ) ;
break;
}
case V_292 : {
struct V_293 V_294 ;
struct V_532 V_632 ;
V_93 = - V_176 ;
if ( F_79 ( & V_294 , V_291 , sizeof( V_294 ) ) )
break;
if ( F_351 ( & V_294 , & V_632 ) )
return - V_91 ;
V_93 = F_278 ( V_9 , & V_632 ) ;
break;
}
case V_633 :
V_178 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
V_93 = F_338 ( V_9 , V_89 ) ;
F_56 ( & V_9 -> V_7 -> V_183 , V_178 ) ;
break;
case V_634 : {
T_9 V_495 ;
V_93 = - V_176 ;
if ( F_79 ( & V_495 , V_291 , sizeof( V_495 ) ) )
break;
V_93 = F_258 ( V_9 , V_495 ) ;
break;
}
case V_635 :
V_93 = F_248 ( V_9 ) ;
break;
case V_636 :
case V_637 : {
struct V_471 V_472 ;
V_93 = - V_176 ;
if ( F_79 ( & V_472 , V_291 , sizeof( V_472 ) ) )
break;
if ( V_88 == V_636 )
V_93 = F_247 ( V_9 , & V_472 ) ;
else
V_93 = F_246 ( V_9 , & V_472 ) ;
break;
}
#ifdef F_30
case V_638 : {
struct V_639 V_640 ;
if ( F_79 ( & V_640 , V_291 , sizeof( V_640 ) ) ) {
V_93 = - V_176 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_93 = - V_91 ;
break;
}
V_93 = F_352 ( V_9 -> V_12 . V_138 , V_640 . V_641 ,
V_640 . V_642 , V_640 . V_643 ) ;
break;
}
case V_644 : {
struct V_639 V_640 ;
if ( F_79 ( & V_640 , V_291 , sizeof( V_640 ) ) ) {
V_93 = - V_176 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_93 = - V_91 ;
break;
}
V_93 = F_353 ( V_9 -> V_12 . V_138 , V_640 . V_642 ,
V_640 . V_643 ) ;
break;
}
#endif
case V_645 : {
V_93 = F_276 ( V_9 -> V_12 . V_138 , V_89 , 0 ) ;
break;
}
case V_295 :
{
struct V_154 V_155 ;
V_93 = - V_176 ;
if ( F_79 ( & V_155 , V_291 , sizeof( V_155 ) ) )
break;
V_93 = F_344 ( V_9 , & V_155 ) ;
break;
}
case V_646 : {
struct V_615 V_647 ;
if ( F_79 ( & V_647 , V_291 , sizeof( V_647 ) ) == 0 )
V_93 = F_346 ( V_9 , & V_647 ) ;
else
V_93 = - V_176 ;
break;
}
case V_648 : {
struct V_649 V_650 ;
V_93 = - V_176 ;
if ( F_79 ( & V_650 , V_291 , sizeof( V_650 ) ) )
break;
if ( V_650 . V_651 > V_652 ||
V_650 . V_651 == 0 ||
V_650 . V_651 % sizeof( struct V_532 ) > 0 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_354 ( V_9 ,
( void V_174 * ) V_650 . V_618 ,
V_650 . V_651 ) ;
break;
}
case V_653 : {
struct V_649 V_650 ;
V_93 = - V_176 ;
if ( F_79 ( & V_650 , V_291 , sizeof( V_650 ) ) )
break;
if ( V_650 . V_651 == 0 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_355 ( V_9 ,
( V_654 V_174 * ) V_650 . V_618 ,
V_650 . V_651 ) ;
break;
}
default:
V_93 = - V_306 ;
}
return V_93 ;
}
int F_356 ( struct V_8 * V_9 , struct V_655 * V_656 )
{
#ifdef F_30
if ( ( V_656 -> V_657 == V_658 )
&& ( F_39 ( V_9 -> V_7 ) ) ) {
V_656 -> V_659 = F_357 ( V_9 -> V_12 . V_14 ) ;
F_358 ( V_656 -> V_659 ) ;
return 0 ;
}
#endif
return V_660 ;
}
int F_359 ( struct V_7 * V_7 , struct V_133 * V_149 ,
unsigned long V_140 )
{
return 0 ;
}
int F_360 ( struct V_7 * V_7 ,
struct V_133 * V_134 ,
const struct V_661 * V_662 ,
enum V_663 V_664 )
{
if ( V_662 -> V_665 & 0xffffful )
return - V_91 ;
if ( V_662 -> V_666 & 0xffffful )
return - V_91 ;
if ( V_662 -> V_667 + V_662 -> V_666 > V_7 -> V_12 . V_172 )
return - V_91 ;
return 0 ;
}
void F_361 ( struct V_7 * V_7 ,
const struct V_661 * V_662 ,
const struct V_133 * V_668 ,
const struct V_133 * V_187 ,
enum V_663 V_664 )
{
int V_319 ;
if ( V_668 -> V_665 == V_662 -> V_665 &&
V_668 -> V_139 * V_331 == V_662 -> V_667 &&
V_668 -> V_140 * V_331 == V_662 -> V_666 )
return;
V_319 = F_352 ( V_7 -> V_12 . V_138 , V_662 -> V_665 ,
V_662 -> V_667 , V_662 -> V_666 ) ;
if ( V_319 )
F_362 ( L_54 ) ;
return;
}
static inline unsigned long F_363 ( int V_10 )
{
unsigned int V_669 = ( V_60 . V_670 << V_10 * 2 ) >> 30 ;
return 0x0000ffffffffffffUL >> ( V_669 << 4 ) ;
}
void F_364 ( struct V_8 * V_9 )
{
V_9 -> V_671 = false ;
}
static int T_13 F_365 ( void )
{
int V_10 ;
if ( ! V_60 . V_61 ) {
F_366 ( L_55 ) ;
return - V_672 ;
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_1 [ V_10 ] |=
V_250 . V_251 [ V_10 ] & F_363 ( V_10 ) ;
return F_367 ( NULL , sizeof( struct V_8 ) , 0 , V_673 ) ;
}
static void T_14 F_368 ( void )
{
F_369 () ;
}
