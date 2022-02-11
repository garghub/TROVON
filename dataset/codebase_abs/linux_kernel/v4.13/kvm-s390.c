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
T_3 V_222 ;
if ( F_79 ( & V_222 , ( void V_174 * ) V_169 -> V_175 ,
sizeof( V_222 ) ) )
return - V_176 ;
if ( V_222 != 0 )
return - V_91 ;
F_48 ( V_7 , 3 , L_23 , V_222 ) ;
return 0 ;
}
static int F_80 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
V_173 V_223 ;
if ( F_79 ( & V_223 , ( void V_174 * ) V_169 -> V_175 , sizeof( V_223 ) ) )
return - V_176 ;
F_81 ( V_7 , V_223 ) ;
F_48 ( V_7 , 3 , L_24 , V_223 ) ;
return 0 ;
}
static int F_82 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
if ( V_169 -> V_156 )
return - V_91 ;
switch ( V_169 -> V_169 ) {
case V_224 :
V_170 = F_78 ( V_7 , V_169 ) ;
break;
case V_225 :
V_170 = F_80 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_83 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
T_3 V_222 = 0 ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_222 ,
sizeof( V_222 ) ) )
return - V_176 ;
F_48 ( V_7 , 3 , L_25 , V_222 ) ;
return 0 ;
}
static int F_84 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
V_173 V_223 ;
V_223 = F_85 ( V_7 ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_223 , sizeof( V_223 ) ) )
return - V_176 ;
F_48 ( V_7 , 3 , L_26 , V_223 ) ;
return 0 ;
}
static int F_86 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
if ( V_169 -> V_156 )
return - V_91 ;
switch ( V_169 -> V_169 ) {
case V_224 :
V_170 = F_83 ( V_7 , V_169 ) ;
break;
case V_225 :
V_170 = F_84 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_87 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_226 * V_227 ;
T_4 V_228 , V_229 ;
int V_170 = 0 ;
F_40 ( & V_7 -> V_159 ) ;
if ( V_7 -> V_160 ) {
V_170 = - V_161 ;
goto V_150;
}
V_227 = F_67 ( sizeof( * V_227 ) , V_209 ) ;
if ( ! V_227 ) {
V_170 = - V_82 ;
goto V_150;
}
if ( ! F_79 ( V_227 , ( void V_174 * ) V_169 -> V_175 ,
sizeof( * V_227 ) ) ) {
V_7 -> V_12 . V_162 . V_230 = V_227 -> V_230 ;
V_228 = V_60 . V_231 >> 16 & 0xfff ;
V_229 = V_60 . V_231 & 0xfff ;
if ( V_228 && V_227 -> V_231 ) {
if ( V_227 -> V_231 > V_229 )
V_7 -> V_12 . V_162 . V_231 = V_229 ;
else if ( V_227 -> V_231 < V_228 )
V_7 -> V_12 . V_162 . V_231 = V_228 ;
else
V_7 -> V_12 . V_162 . V_231 = V_227 -> V_231 ;
}
memcpy ( V_7 -> V_12 . V_162 . V_164 , V_227 -> V_164 ,
V_232 ) ;
F_48 ( V_7 , 3 , L_27 ,
V_7 -> V_12 . V_162 . V_231 ,
V_7 -> V_12 . V_162 . V_230 ) ;
F_48 ( V_7 , 3 , L_28 ,
V_7 -> V_12 . V_162 . V_164 [ 0 ] ,
V_7 -> V_12 . V_162 . V_164 [ 1 ] ,
V_7 -> V_12 . V_162 . V_164 [ 2 ] ) ;
} else
V_170 = - V_176 ;
F_70 ( V_227 ) ;
V_150:
F_44 ( & V_7 -> V_159 ) ;
return V_170 ;
}
static int F_88 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
struct V_233 V_234 ;
int V_170 = - V_161 ;
if ( F_79 ( & V_234 , ( void V_174 * ) V_169 -> V_175 , sizeof( V_234 ) ) )
return - V_176 ;
if ( ! F_89 ( ( unsigned long * ) V_234 . V_235 ,
V_27 ,
V_236 ) )
return - V_91 ;
F_40 ( & V_7 -> V_159 ) ;
if ( ! F_50 ( & V_7 -> V_165 ) ) {
F_90 ( V_7 -> V_12 . V_237 , ( unsigned long * ) V_234 . V_235 ,
V_236 ) ;
V_170 = 0 ;
}
F_44 ( & V_7 -> V_159 ) ;
return V_170 ;
}
static int F_91 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
return - V_177 ;
}
static int F_92 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 = - V_177 ;
switch ( V_169 -> V_169 ) {
case V_238 :
V_170 = F_87 ( V_7 , V_169 ) ;
break;
case V_239 :
V_170 = F_88 ( V_7 , V_169 ) ;
break;
case V_240 :
V_170 = F_91 ( V_7 , V_169 ) ;
break;
}
return V_170 ;
}
static int F_93 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_226 * V_227 ;
int V_170 = 0 ;
V_227 = F_67 ( sizeof( * V_227 ) , V_209 ) ;
if ( ! V_227 ) {
V_170 = - V_82 ;
goto V_150;
}
V_227 -> V_230 = V_7 -> V_12 . V_162 . V_230 ;
V_227 -> V_231 = V_7 -> V_12 . V_162 . V_231 ;
memcpy ( & V_227 -> V_164 , V_7 -> V_12 . V_162 . V_164 ,
V_232 ) ;
F_48 ( V_7 , 3 , L_29 ,
V_7 -> V_12 . V_162 . V_231 ,
V_7 -> V_12 . V_162 . V_230 ) ;
F_48 ( V_7 , 3 , L_30 ,
V_7 -> V_12 . V_162 . V_164 [ 0 ] ,
V_7 -> V_12 . V_162 . V_164 [ 1 ] ,
V_7 -> V_12 . V_162 . V_164 [ 2 ] ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , V_227 , sizeof( * V_227 ) ) )
V_170 = - V_176 ;
F_70 ( V_227 ) ;
V_150:
return V_170 ;
}
static int F_94 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
struct V_241 * V_242 ;
int V_170 = 0 ;
V_242 = F_67 ( sizeof( * V_242 ) , V_209 ) ;
if ( ! V_242 ) {
V_170 = - V_82 ;
goto V_150;
}
F_95 ( (struct V_230 * ) & V_242 -> V_230 ) ;
V_242 -> V_231 = V_60 . V_231 ;
memcpy ( & V_242 -> V_163 , V_7 -> V_12 . V_162 . V_163 ,
V_232 ) ;
memcpy ( ( unsigned long * ) & V_242 -> V_164 , V_243 . V_244 ,
sizeof( V_243 . V_244 ) ) ;
F_48 ( V_7 , 3 , L_31 ,
V_7 -> V_12 . V_162 . V_231 ,
V_7 -> V_12 . V_162 . V_230 ) ;
F_48 ( V_7 , 3 , L_32 ,
V_242 -> V_163 [ 0 ] ,
V_242 -> V_163 [ 1 ] ,
V_242 -> V_163 [ 2 ] ) ;
F_48 ( V_7 , 3 , L_33 ,
V_242 -> V_164 [ 0 ] ,
V_242 -> V_164 [ 1 ] ,
V_242 -> V_164 [ 2 ] ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , V_242 , sizeof( * V_242 ) ) )
V_170 = - V_176 ;
F_70 ( V_242 ) ;
V_150:
return V_170 ;
}
static int F_96 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
struct V_233 V_234 ;
F_90 ( ( unsigned long * ) V_234 . V_235 , V_7 -> V_12 . V_237 ,
V_236 ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_234 , sizeof( V_234 ) ) )
return - V_176 ;
return 0 ;
}
static int F_97 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
struct V_233 V_234 ;
F_90 ( ( unsigned long * ) V_234 . V_235 ,
V_27 ,
V_236 ) ;
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_234 , sizeof( V_234 ) ) )
return - V_176 ;
return 0 ;
}
static int F_98 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
return - V_177 ;
}
static int F_99 ( struct V_7 * V_7 ,
struct V_168 * V_169 )
{
if ( F_77 ( ( void V_174 * ) V_169 -> V_175 , & V_30 ,
sizeof( struct V_245 ) ) )
return - V_176 ;
return 0 ;
}
static int F_100 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 = - V_177 ;
switch ( V_169 -> V_169 ) {
case V_238 :
V_170 = F_93 ( V_7 , V_169 ) ;
break;
case V_246 :
V_170 = F_94 ( V_7 , V_169 ) ;
break;
case V_239 :
V_170 = F_96 ( V_7 , V_169 ) ;
break;
case V_247 :
V_170 = F_97 ( V_7 , V_169 ) ;
break;
case V_240 :
V_170 = F_98 ( V_7 , V_169 ) ;
break;
case V_248 :
V_170 = F_99 ( V_7 , V_169 ) ;
break;
}
return V_170 ;
}
static int F_101 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
switch ( V_169 -> V_249 ) {
case V_250 :
V_170 = F_53 ( V_7 , V_169 ) ;
break;
case V_251 :
V_170 = F_82 ( V_7 , V_169 ) ;
break;
case V_252 :
V_170 = F_92 ( V_7 , V_169 ) ;
break;
case V_253 :
V_170 = F_60 ( V_7 , V_169 ) ;
break;
case V_254 :
V_170 = F_75 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_102 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
switch ( V_169 -> V_249 ) {
case V_250 :
V_170 = F_51 ( V_7 , V_169 ) ;
break;
case V_251 :
V_170 = F_86 ( V_7 , V_169 ) ;
break;
case V_252 :
V_170 = F_100 ( V_7 , V_169 ) ;
break;
case V_254 :
V_170 = F_76 ( V_7 , V_169 ) ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static int F_103 ( struct V_7 * V_7 , struct V_168 * V_169 )
{
int V_170 ;
switch ( V_169 -> V_249 ) {
case V_250 :
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
case V_251 :
switch ( V_169 -> V_169 ) {
case V_225 :
case V_224 :
V_170 = 0 ;
break;
default:
V_170 = - V_177 ;
break;
}
break;
case V_252 :
switch ( V_169 -> V_169 ) {
case V_238 :
case V_246 :
case V_239 :
case V_247 :
case V_248 :
V_170 = 0 ;
break;
case V_240 :
default:
V_170 = - V_177 ;
break;
}
break;
case V_253 :
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
case V_254 :
V_170 = 0 ;
break;
default:
V_170 = - V_177 ;
break;
}
return V_170 ;
}
static long F_104 ( struct V_7 * V_7 , struct V_255 * args )
{
T_5 * V_256 ;
T_6 V_257 ;
int V_258 , V_10 , V_93 = 0 ;
if ( args -> V_156 != 0 )
return - V_91 ;
if ( ! F_105 ( V_142 -> V_141 ) )
return V_259 ;
if ( args -> V_260 < 1 || args -> V_260 > V_261 )
return - V_91 ;
V_256 = F_106 ( args -> V_260 , sizeof( T_5 ) , V_209 ) ;
if ( ! V_256 )
return - V_82 ;
F_107 ( & V_142 -> V_141 -> V_262 ) ;
V_258 = F_54 ( & V_7 -> V_183 ) ;
for ( V_10 = 0 ; V_10 < args -> V_260 ; V_10 ++ ) {
V_257 = F_108 ( V_7 , args -> V_263 + V_10 ) ;
if ( F_109 ( V_257 ) ) {
V_93 = - V_176 ;
break;
}
V_93 = F_110 ( V_142 -> V_141 , V_257 , & V_256 [ V_10 ] ) ;
if ( V_93 )
break;
}
F_56 ( & V_7 -> V_183 , V_258 ) ;
F_111 ( & V_142 -> V_141 -> V_262 ) ;
if ( ! V_93 ) {
V_93 = F_77 ( ( T_5 V_174 * ) args -> V_264 , V_256 ,
sizeof( T_5 ) * args -> V_260 ) ;
if ( V_93 )
V_93 = - V_176 ;
}
F_112 ( V_256 ) ;
return V_93 ;
}
static long F_113 ( struct V_7 * V_7 , struct V_255 * args )
{
T_5 * V_256 ;
T_6 V_257 ;
int V_258 , V_10 , V_93 = 0 ;
if ( args -> V_156 != 0 )
return - V_91 ;
if ( args -> V_260 < 1 || args -> V_260 > V_261 )
return - V_91 ;
V_256 = F_106 ( args -> V_260 , sizeof( T_5 ) , V_209 ) ;
if ( ! V_256 )
return - V_82 ;
V_93 = F_79 ( V_256 , ( T_5 V_174 * ) args -> V_264 ,
sizeof( T_5 ) * args -> V_260 ) ;
if ( V_93 ) {
V_93 = - V_176 ;
goto V_150;
}
V_93 = F_114 () ;
if ( V_93 )
goto V_150;
F_107 ( & V_142 -> V_141 -> V_262 ) ;
V_258 = F_54 ( & V_7 -> V_183 ) ;
for ( V_10 = 0 ; V_10 < args -> V_260 ; V_10 ++ ) {
V_257 = F_108 ( V_7 , args -> V_263 + V_10 ) ;
if ( F_109 ( V_257 ) ) {
V_93 = - V_176 ;
break;
}
if ( V_256 [ V_10 ] & 0x01 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_115 ( V_142 -> V_141 , V_257 , V_256 [ V_10 ] , 0 ) ;
if ( V_93 )
break;
}
F_56 ( & V_7 -> V_183 , V_258 ) ;
F_111 ( & V_142 -> V_141 -> V_262 ) ;
V_150:
F_112 ( V_256 ) ;
return V_93 ;
}
static int F_116 ( struct V_7 * V_7 ,
struct V_265 * args )
{
struct V_202 * V_266 = V_7 -> V_12 . V_207 ;
unsigned long V_267 , V_257 , V_268 , V_10 , V_269 , V_270 ;
int V_258 , V_271 , V_93 = 0 , V_272 ;
T_3 * V_217 ;
V_270 = args -> V_263 ;
V_10 = V_269 = V_268 = 0 ;
if ( F_117 ( ! V_7 -> V_12 . V_181 ) )
return - V_177 ;
if ( args -> V_156 & ~ V_273 )
return - V_91 ;
V_271 = ! ! ( args -> V_156 & V_273 ) ;
if ( ! V_271 && ! V_266 )
return - V_91 ;
V_267 = F_118 ( args -> V_260 , V_274 ) ;
if ( ! V_267 || ! V_7 -> V_141 -> V_275 . V_181 ) {
memset ( args , 0 , sizeof( * args ) ) ;
return 0 ;
}
if ( ! V_271 ) {
if ( ! F_119 ( & V_266 -> V_214 ) ) {
memset ( args , 0 , sizeof( * args ) ) ;
return 0 ;
}
V_270 = F_120 ( V_266 -> V_212 , V_266 -> V_213 ,
args -> V_263 ) ;
if ( V_270 >= V_266 -> V_213 )
V_270 = F_120 ( V_266 -> V_212 , V_266 -> V_213 , 0 ) ;
if ( V_270 >= V_266 -> V_213 ) {
memset ( args , 0 , sizeof( * args ) ) ;
return 0 ;
}
V_269 = F_120 ( V_266 -> V_212 , V_266 -> V_213 , V_270 + 1 ) ;
}
V_217 = F_69 ( V_267 ) ;
if ( ! V_217 )
return - V_82 ;
args -> V_263 = V_270 ;
F_107 ( & V_7 -> V_141 -> V_262 ) ;
V_258 = F_54 ( & V_7 -> V_183 ) ;
while ( V_10 < V_267 ) {
V_257 = F_108 ( V_7 , V_270 ) ;
if ( F_109 ( V_257 ) ) {
V_93 = - V_176 ;
break;
}
if ( ! V_271 && F_121 ( V_270 , V_266 -> V_212 ) )
F_122 ( & V_266 -> V_214 ) ;
V_93 = F_123 ( V_7 -> V_141 , V_257 , & V_268 ) ;
if ( V_93 < 0 )
V_268 = 0 ;
V_217 [ V_10 ++ ] = ( V_268 >> 24 ) & 0x3 ;
if ( ! V_271 ) {
if ( V_269 > V_270 + V_276 )
break;
if ( V_270 == V_269 )
V_269 = F_120 ( V_266 -> V_212 ,
V_266 -> V_213 , V_270 + 1 ) ;
if ( ( V_269 >= V_266 -> V_213 ) ||
( V_269 >= args -> V_263 + V_267 ) )
break;
}
V_270 ++ ;
}
F_56 ( & V_7 -> V_183 , V_258 ) ;
F_111 ( & V_7 -> V_141 -> V_262 ) ;
args -> V_260 = V_10 ;
args -> V_277 = V_266 ? F_119 ( & V_266 -> V_214 ) : 0 ;
V_272 = F_77 ( ( void V_174 * ) args -> V_278 , V_217 , args -> V_260 ) ;
if ( V_272 )
V_93 = - V_176 ;
F_74 ( V_217 ) ;
return V_93 ;
}
static int F_124 ( struct V_7 * V_7 ,
const struct V_265 * args )
{
unsigned long V_257 , V_279 , V_268 , V_10 ;
T_5 * V_280 ;
int V_258 , V_93 = 0 ;
V_279 = args -> V_279 ;
if ( ! V_7 -> V_12 . V_181 )
return - V_177 ;
if ( args -> V_156 != 0 )
return - V_91 ;
if ( args -> V_260 > V_274 )
return - V_91 ;
if ( args -> V_260 == 0 )
return 0 ;
V_280 = F_69 ( sizeof( * V_280 ) * args -> V_260 ) ;
if ( ! V_280 )
return - V_82 ;
V_93 = F_79 ( V_280 , ( void V_174 * ) args -> V_278 , args -> V_260 ) ;
if ( V_93 ) {
V_93 = - V_176 ;
goto V_150;
}
F_107 ( & V_7 -> V_141 -> V_262 ) ;
V_258 = F_54 ( & V_7 -> V_183 ) ;
for ( V_10 = 0 ; V_10 < args -> V_260 ; V_10 ++ ) {
V_257 = F_108 ( V_7 , args -> V_263 + V_10 ) ;
if ( F_109 ( V_257 ) ) {
V_93 = - V_176 ;
break;
}
V_268 = V_280 [ V_10 ] ;
V_268 = V_268 << 24 ;
V_279 &= V_281 ;
F_125 ( V_7 -> V_141 , V_257 , V_279 , V_268 ) ;
}
F_56 ( & V_7 -> V_183 , V_258 ) ;
F_111 ( & V_7 -> V_141 -> V_262 ) ;
if ( ! V_7 -> V_141 -> V_275 . V_181 ) {
F_126 ( & V_7 -> V_141 -> V_262 ) ;
V_7 -> V_141 -> V_275 . V_181 = 1 ;
F_127 ( & V_7 -> V_141 -> V_262 ) ;
}
V_150:
F_74 ( V_280 ) ;
return V_93 ;
}
long F_128 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_7 * V_7 = V_87 -> V_282 ;
void V_174 * V_283 = ( void V_174 * ) V_89 ;
struct V_168 V_169 ;
int V_93 ;
switch ( V_88 ) {
case V_284 : {
struct V_285 V_286 ;
V_93 = - V_176 ;
if ( F_79 ( & V_286 , V_283 , sizeof( V_286 ) ) )
break;
V_93 = F_129 ( V_7 , & V_286 ) ;
break;
}
case V_287 : {
struct V_154 V_155 ;
V_93 = - V_176 ;
if ( F_79 ( & V_155 , V_283 , sizeof( V_155 ) ) )
break;
V_93 = F_47 ( V_7 , & V_155 ) ;
break;
}
case V_288 : {
struct V_289 V_290 ;
V_93 = - V_91 ;
if ( V_7 -> V_12 . V_157 ) {
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
V_93 = F_130 ( V_7 , & V_290 , 0 , 0 ) ;
}
break;
}
case V_291 : {
V_93 = - V_176 ;
if ( F_79 ( & V_169 , ( void V_174 * ) V_89 , sizeof( V_169 ) ) )
break;
V_93 = F_101 ( V_7 , & V_169 ) ;
break;
}
case V_292 : {
V_93 = - V_176 ;
if ( F_79 ( & V_169 , ( void V_174 * ) V_89 , sizeof( V_169 ) ) )
break;
V_93 = F_102 ( V_7 , & V_169 ) ;
break;
}
case V_293 : {
V_93 = - V_176 ;
if ( F_79 ( & V_169 , ( void V_174 * ) V_89 , sizeof( V_169 ) ) )
break;
V_93 = F_103 ( V_7 , & V_169 ) ;
break;
}
case V_294 : {
struct V_255 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_283 ,
sizeof( struct V_255 ) ) )
break;
V_93 = F_104 ( V_7 , & args ) ;
break;
}
case V_295 : {
struct V_255 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_283 ,
sizeof( struct V_255 ) ) )
break;
V_93 = F_113 ( V_7 , & args ) ;
break;
}
case V_296 : {
struct V_265 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_283 , sizeof( args ) ) )
break;
V_93 = F_116 ( V_7 , & args ) ;
if ( ! V_93 ) {
V_93 = F_77 ( V_283 , & args , sizeof( args ) ) ;
if ( V_93 )
V_93 = - V_176 ;
}
break;
}
case V_297 : {
struct V_265 args ;
V_93 = - V_176 ;
if ( F_79 ( & args , V_283 , sizeof( args ) ) )
break;
V_93 = F_124 ( V_7 , & args ) ;
break;
}
default:
V_93 = - V_298 ;
}
return V_93 ;
}
static int F_131 ( T_3 * V_299 )
{
T_7 V_300 = 0x04000000UL ;
T_7 V_29 = 0 ;
memset ( V_299 , 0 , 128 ) ;
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
static int F_132 ( void )
{
T_3 V_299 [ 128 ] ;
int V_29 ;
if ( F_18 ( 12 ) ) {
V_29 = F_131 ( V_299 ) ;
if ( V_29 )
F_133 ( L_34 , V_29 ) ;
else
return V_299 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_134 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_191 . V_301 = ( V_302 ) ( unsigned long ) V_7 -> V_12 . V_191 . V_192 ;
if ( F_132 () )
V_7 -> V_12 . V_191 . V_301 |= V_303 ;
else
V_7 -> V_12 . V_191 . V_301 |= V_304 ;
}
static V_173 F_135 ( void )
{
struct V_230 V_230 ;
F_95 ( & V_230 ) ;
V_230 . V_305 = 0xff ;
return * ( ( V_173 * ) & V_230 ) ;
}
static void F_136 ( struct V_7 * V_7 )
{
if ( ! F_61 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_191 . V_192 = & V_7 -> V_12 . V_306 -> V_192 ;
F_134 ( V_7 ) ;
V_7 -> V_12 . V_191 . V_194 = 1 ;
V_7 -> V_12 . V_191 . V_197 = 1 ;
F_62 ( V_7 -> V_12 . V_191 . V_192 -> V_193 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_193 ) ) ;
F_62 ( V_7 -> V_12 . V_191 . V_192 -> V_196 ,
sizeof( V_7 -> V_12 . V_191 . V_192 -> V_196 ) ) ;
}
static void F_137 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_307 )
F_138 ( V_7 -> V_12 . V_308 , sizeof( struct V_309 ) ) ;
else
F_139 ( ( unsigned long ) ( V_7 -> V_12 . V_308 ) ) ;
V_7 -> V_12 . V_308 = NULL ;
}
int F_140 ( struct V_7 * V_7 , unsigned long type )
{
T_8 V_310 = V_209 ;
int V_10 , V_311 ;
char V_312 [ 16 ] ;
static unsigned long V_313 ;
V_311 = - V_91 ;
#ifdef F_30
if ( type & ~ V_314 )
goto V_315;
if ( ( type & V_314 ) && ( ! F_141 ( V_316 ) ) )
goto V_315;
#else
if ( type )
goto V_315;
#endif
V_311 = F_28 () ;
if ( V_311 )
goto V_315;
V_311 = - V_82 ;
F_142 ( & V_7 -> V_12 . V_317 , 5 * V_318 , 500 ) ;
V_7 -> V_12 . V_307 = 0 ;
if ( ! V_60 . V_62 )
V_310 |= V_319 ;
F_143 ( & V_7 -> V_12 . V_320 ) ;
V_7 -> V_12 . V_308 = (struct V_321 * ) F_144 ( V_310 ) ;
if ( ! V_7 -> V_12 . V_308 )
goto V_315;
F_145 ( & V_322 ) ;
V_313 += 16 ;
if ( V_313 + sizeof( struct V_321 ) > V_323 )
V_313 = 0 ;
V_7 -> V_12 . V_308 = (struct V_321 * )
( ( char * ) V_7 -> V_12 . V_308 + V_313 ) ;
F_146 ( & V_322 ) ;
sprintf ( V_312 , L_35 , V_142 -> V_324 ) ;
V_7 -> V_12 . V_325 = F_22 ( V_312 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_325 )
goto V_315;
V_7 -> V_12 . V_306 =
(struct V_306 * ) F_144 ( V_209 | V_319 ) ;
if ( ! V_7 -> V_12 . V_306 )
goto V_315;
memcpy ( V_7 -> V_12 . V_162 . V_163 , V_243 . V_244 ,
sizeof( V_243 . V_244 ) ) ;
for ( V_10 = 0 ; V_10 < V_326 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_162 . V_163 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_162 . V_163 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_162 . V_164 = V_7 -> V_12 . V_306 -> V_164 ;
memcpy ( V_7 -> V_12 . V_162 . V_164 , V_7 -> V_12 . V_162 . V_163 ,
V_232 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_163 , 74 ) ;
F_49 ( V_7 -> V_12 . V_162 . V_164 , 74 ) ;
V_7 -> V_12 . V_162 . V_230 = F_135 () ;
V_7 -> V_12 . V_162 . V_231 = V_60 . V_231 & 0x0fff ;
F_136 ( V_7 ) ;
F_147 ( & V_7 -> V_12 . V_327 . V_328 ) ;
V_7 -> V_12 . V_327 . V_329 = 0 ;
V_7 -> V_12 . V_327 . V_330 = 0 ;
F_148 ( & V_7 -> V_12 . V_327 . V_159 ) ;
for ( V_10 = 0 ; V_10 < V_331 ; V_10 ++ )
F_149 ( & V_7 -> V_12 . V_327 . V_332 [ V_10 ] ) ;
F_150 ( & V_7 -> V_12 . V_333 ) ;
F_147 ( & V_7 -> V_12 . V_334 ) ;
F_23 ( V_7 -> V_12 . V_325 , & V_83 ) ;
F_48 ( V_7 , 3 , L_36 , type ) ;
if ( type & V_314 ) {
V_7 -> V_12 . V_138 = NULL ;
V_7 -> V_12 . V_172 = V_185 ;
} else {
if ( V_60 . V_335 == V_336 )
V_7 -> V_12 . V_172 = V_337 ;
else
V_7 -> V_12 . V_172 = F_151 (unsigned long, TASK_SIZE_MAX,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_138 = F_58 ( V_142 -> V_141 , V_7 -> V_12 . V_172 - 1 ) ;
if ( ! V_7 -> V_12 . V_138 )
goto V_315;
V_7 -> V_12 . V_138 -> V_188 = V_7 ;
V_7 -> V_12 . V_138 -> V_338 = 0 ;
}
V_7 -> V_12 . V_339 = 0 ;
V_7 -> V_12 . V_157 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_148 ( & V_7 -> V_12 . V_340 ) ;
F_152 ( V_7 ) ;
F_153 ( 3 , L_37 , V_7 , V_142 -> V_324 ) ;
return 0 ;
V_315:
F_139 ( ( unsigned long ) V_7 -> V_12 . V_306 ) ;
F_24 ( V_7 -> V_12 . V_325 ) ;
F_137 ( V_7 ) ;
F_153 ( 3 , L_38 , V_311 ) ;
return V_311 ;
}
bool F_154 ( void )
{
return false ;
}
int F_155 ( struct V_8 * V_9 )
{
return 0 ;
}
void F_156 ( struct V_8 * V_9 )
{
F_157 ( V_9 , 3 , L_3 , L_39 ) ;
F_158 ( V_9 -> V_341 ) ;
F_159 ( V_9 ) ;
F_160 ( V_9 ) ;
if ( ! F_39 ( V_9 -> V_7 ) )
F_161 ( V_9 ) ;
if ( F_39 ( V_9 -> V_7 ) )
F_59 ( V_9 -> V_12 . V_138 ) ;
if ( V_9 -> V_7 -> V_12 . V_181 )
F_162 ( V_9 ) ;
F_139 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_163 ( V_9 ) ;
F_164 ( V_342 , V_9 ) ;
}
static void F_165 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_156 ( V_9 ) ;
F_40 ( & V_7 -> V_159 ) ;
for ( V_10 = 0 ; V_10 < F_50 ( & V_7 -> V_165 ) ; V_10 ++ )
V_7 -> V_343 [ V_10 ] = NULL ;
F_166 ( & V_7 -> V_165 , 0 ) ;
F_44 ( & V_7 -> V_159 ) ;
}
void F_167 ( struct V_7 * V_7 )
{
F_165 ( V_7 ) ;
F_137 ( V_7 ) ;
F_24 ( V_7 -> V_12 . V_325 ) ;
F_139 ( ( unsigned long ) V_7 -> V_12 . V_306 ) ;
if ( ! F_39 ( V_7 ) )
F_59 ( V_7 -> V_12 . V_138 ) ;
F_168 ( V_7 ) ;
F_169 ( V_7 ) ;
F_170 ( V_7 ) ;
if ( V_7 -> V_12 . V_207 ) {
F_74 ( V_7 -> V_12 . V_207 -> V_212 ) ;
F_70 ( V_7 -> V_12 . V_207 ) ;
}
F_153 ( 3 , L_40 , V_7 ) ;
}
static int F_171 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_138 = F_58 ( V_142 -> V_141 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_138 )
return - V_82 ;
V_9 -> V_12 . V_138 -> V_188 = V_9 -> V_7 ;
return 0 ;
}
static void F_161 ( struct V_8 * V_9 )
{
if ( ! F_31 () )
return;
F_172 ( & V_9 -> V_7 -> V_12 . V_320 ) ;
if ( V_9 -> V_7 -> V_12 . V_307 ) {
struct V_309 * V_308 = V_9 -> V_7 -> V_12 . V_308 ;
F_173 ( V_9 -> V_341 , ( unsigned long * ) V_308 -> V_344 ) ;
V_308 -> V_345 [ V_9 -> V_341 ] . V_346 = 0 ;
} else {
struct V_321 * V_308 = V_9 -> V_7 -> V_12 . V_308 ;
F_173 ( V_9 -> V_341 , ( unsigned long * ) & V_308 -> V_344 ) ;
V_308 -> V_345 [ V_9 -> V_341 ] . V_346 = 0 ;
}
F_174 ( & V_9 -> V_7 -> V_12 . V_320 ) ;
}
static void F_175 ( struct V_8 * V_9 )
{
if ( ! F_31 () ) {
struct V_321 * V_308 = V_9 -> V_7 -> V_12 . V_308 ;
V_9 -> V_12 . V_14 -> V_347 = ( V_302 ) ( ( ( V_348 ) V_308 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_349 = ( V_302 ) ( V_348 ) V_308 ;
}
F_172 ( & V_9 -> V_7 -> V_12 . V_320 ) ;
if ( V_9 -> V_7 -> V_12 . V_307 ) {
struct V_309 * V_308 = V_9 -> V_7 -> V_12 . V_308 ;
V_308 -> V_345 [ V_9 -> V_341 ] . V_346 = ( V_348 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_347 = ( V_302 ) ( ( ( V_348 ) V_308 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_349 = ( V_302 ) ( V_348 ) V_308 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_350 |= V_351 ;
F_15 ( V_9 -> V_341 , ( unsigned long * ) V_308 -> V_344 ) ;
} else {
struct V_321 * V_308 = V_9 -> V_7 -> V_12 . V_308 ;
V_308 -> V_345 [ V_9 -> V_341 ] . V_346 = ( V_348 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_347 = ( V_302 ) ( ( ( V_348 ) V_308 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_349 = ( V_302 ) ( V_348 ) V_308 ;
F_15 ( V_9 -> V_341 , ( unsigned long * ) & V_308 -> V_344 ) ;
}
F_174 ( & V_9 -> V_7 -> V_12 . V_320 ) ;
}
static inline void F_176 ( struct V_352 * V_353 , struct V_354 * V_266 )
{
V_353 -> V_346 = V_266 -> V_346 ;
V_353 -> V_355 . V_356 = V_266 -> V_355 . V_356 ;
V_353 -> V_355 . V_357 = V_266 -> V_355 . V_357 ;
}
static void F_177 ( struct V_309 * V_353 , struct V_321 * V_266 )
{
int V_10 ;
V_353 -> V_358 = V_266 -> V_358 ;
V_353 -> V_344 [ 0 ] = V_266 -> V_344 ;
for ( V_10 = 0 ; V_10 < V_122 ; V_10 ++ )
F_176 ( & V_353 -> V_345 [ V_10 ] , & V_266 -> V_345 [ V_10 ] ) ;
}
static int F_178 ( struct V_7 * V_7 )
{
struct V_321 * V_359 = V_7 -> V_12 . V_308 ;
struct V_309 * V_360 ;
struct V_8 * V_9 ;
unsigned int V_361 ;
T_7 V_349 , V_347 ;
V_360 = F_179 ( sizeof( * V_360 ) , V_209 | V_362 ) ;
if ( ! V_360 )
return - V_82 ;
V_347 = ( T_7 ) ( ( V_173 ) ( V_360 ) >> 32 ) ;
V_349 = ( T_7 ) ( V_173 ) ( V_360 ) & ~ 0x3fU ;
F_180 ( V_7 ) ;
F_181 ( & V_7 -> V_12 . V_320 ) ;
F_177 ( V_360 , V_359 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_347 = V_347 ;
V_9 -> V_12 . V_14 -> V_349 = V_349 ;
V_9 -> V_12 . V_14 -> V_350 |= V_351 ;
}
V_7 -> V_12 . V_308 = V_360 ;
V_7 -> V_12 . V_307 = 1 ;
F_182 ( & V_7 -> V_12 . V_320 ) ;
F_183 ( V_7 ) ;
F_139 ( ( unsigned long ) V_359 ) ;
F_48 ( V_7 , 2 , L_41 ,
V_359 , V_7 -> V_12 . V_308 ) ;
return 0 ;
}
static int F_184 ( struct V_7 * V_7 , unsigned int V_363 )
{
int V_311 ;
if ( ! F_31 () ) {
if ( V_363 < V_123 )
return true ;
return false ;
}
if ( V_363 < V_122 )
return true ;
if ( ! V_60 . V_124 || ! V_60 . V_62 )
return false ;
F_40 ( & V_7 -> V_159 ) ;
V_311 = V_7 -> V_12 . V_307 ? 0 : F_178 ( V_7 ) ;
F_44 ( & V_7 -> V_159 ) ;
return V_311 == 0 && V_363 < V_125 ;
}
int F_185 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_364 = V_365 ;
F_160 ( V_9 ) ;
V_9 -> V_366 -> V_367 = V_368 |
V_369 |
V_370 |
V_371 |
V_372 |
V_373 ;
F_186 ( V_9 , 0 ) ;
if ( F_61 ( V_9 -> V_7 , 64 ) )
V_9 -> V_366 -> V_367 |= V_374 ;
if ( F_61 ( V_9 -> V_7 , 133 ) )
V_9 -> V_366 -> V_367 |= V_375 ;
if ( V_130 )
V_9 -> V_366 -> V_367 |= V_376 ;
else
V_9 -> V_366 -> V_367 |= V_377 ;
if ( F_39 ( V_9 -> V_7 ) )
return F_171 ( V_9 ) ;
return 0 ;
}
static void F_187 ( struct V_8 * V_9 )
{
F_188 ( V_9 -> V_12 . V_16 != 0 ) ;
F_189 ( & V_9 -> V_12 . V_378 ) ;
V_9 -> V_12 . V_16 = F_190 () ;
F_191 ( & V_9 -> V_12 . V_378 ) ;
}
static void F_192 ( struct V_8 * V_9 )
{
F_188 ( V_9 -> V_12 . V_16 == 0 ) ;
F_189 ( & V_9 -> V_12 . V_378 ) ;
V_9 -> V_12 . V_14 -> V_379 -= F_190 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_191 ( & V_9 -> V_12 . V_378 ) ;
}
static void F_193 ( struct V_8 * V_9 )
{
F_188 ( V_9 -> V_12 . V_15 ) ;
V_9 -> V_12 . V_15 = true ;
F_187 ( V_9 ) ;
}
static void F_194 ( struct V_8 * V_9 )
{
F_188 ( ! V_9 -> V_12 . V_15 ) ;
F_192 ( V_9 ) ;
V_9 -> V_12 . V_15 = false ;
}
static void F_195 ( struct V_8 * V_9 )
{
F_196 () ;
F_193 ( V_9 ) ;
F_197 () ;
}
static void F_198 ( struct V_8 * V_9 )
{
F_196 () ;
F_194 ( V_9 ) ;
F_197 () ;
}
void F_199 ( struct V_8 * V_9 , V_348 V_379 )
{
F_196 () ;
F_189 ( & V_9 -> V_12 . V_378 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_190 () ;
V_9 -> V_12 . V_14 -> V_379 = V_379 ;
F_191 ( & V_9 -> V_12 . V_378 ) ;
F_197 () ;
}
V_348 F_200 ( struct V_8 * V_9 )
{
unsigned int V_380 ;
V_348 V_381 ;
if ( F_117 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_379 ;
F_196 () ;
do {
V_380 = F_201 ( & V_9 -> V_12 . V_378 ) ;
F_188 ( ( V_380 & 1 ) && F_202 () == V_9 -> V_345 ) ;
V_381 = V_9 -> V_12 . V_14 -> V_379 ;
if ( F_203 ( V_9 -> V_12 . V_16 ) )
V_381 -= F_190 () - V_9 -> V_12 . V_16 ;
} while ( F_204 ( & V_9 -> V_12 . V_378 , V_380 & ~ 1 ) );
F_197 () ;
return V_381 ;
}
void F_205 ( struct V_8 * V_9 , int V_345 )
{
F_206 ( V_9 -> V_12 . V_382 ) ;
F_207 ( V_383 , & V_9 -> V_12 . V_14 -> V_384 ) ;
if ( V_9 -> V_12 . V_15 && ! F_208 ( V_9 ) )
F_187 ( V_9 ) ;
V_9 -> V_345 = V_345 ;
}
void F_209 ( struct V_8 * V_9 )
{
V_9 -> V_345 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_208 ( V_9 ) )
F_192 ( V_9 ) ;
F_210 ( V_383 , & V_9 -> V_12 . V_14 -> V_384 ) ;
V_9 -> V_12 . V_382 = F_211 () ;
F_212 ( V_9 -> V_12 . V_382 ) ;
}
static void F_213 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_385 . V_279 = 0UL ;
V_9 -> V_12 . V_14 -> V_385 . V_175 = 0UL ;
F_186 ( V_9 , 0 ) ;
F_199 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_386 = 0UL ;
V_9 -> V_12 . V_14 -> V_387 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_388 , 0 , 16 * sizeof( V_348 ) ) ;
V_9 -> V_12 . V_14 -> V_388 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_388 [ 14 ] = 0xC2000000UL ;
F_214 () ;
V_142 -> V_389 . V_390 . V_391 = 0 ;
V_9 -> V_12 . V_14 -> V_392 = 1 ;
V_9 -> V_12 . V_14 -> V_393 = 0 ;
V_9 -> V_12 . V_364 = V_365 ;
F_160 ( V_9 ) ;
if ( ! F_215 ( V_9 -> V_7 ) )
F_216 ( V_9 ) ;
F_159 ( V_9 ) ;
}
void F_217 ( struct V_8 * V_9 )
{
F_40 ( & V_9 -> V_7 -> V_159 ) ;
F_196 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_197 () ;
F_44 ( & V_9 -> V_7 -> V_159 ) ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_138 = V_9 -> V_7 -> V_12 . V_138 ;
F_175 ( V_9 ) ;
}
if ( F_61 ( V_9 -> V_7 , 74 ) || V_9 -> V_7 -> V_12 . V_167 )
V_9 -> V_12 . V_14 -> V_394 |= V_395 ;
V_9 -> V_12 . V_382 = V_9 -> V_12 . V_138 ;
}
static void F_63 ( struct V_8 * V_9 )
{
if ( ! F_61 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_396 &= ~ ( V_397 | V_398 ) ;
if ( V_9 -> V_7 -> V_12 . V_191 . V_194 )
V_9 -> V_12 . V_14 -> V_396 |= V_397 ;
if ( V_9 -> V_7 -> V_12 . V_191 . V_197 )
V_9 -> V_12 . V_14 -> V_396 |= V_398 ;
V_9 -> V_12 . V_14 -> V_301 = V_9 -> V_7 -> V_12 . V_191 . V_301 ;
}
void F_162 ( struct V_8 * V_9 )
{
F_139 ( V_9 -> V_12 . V_14 -> V_399 ) ;
V_9 -> V_12 . V_14 -> V_399 = 0 ;
}
int F_218 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_399 = F_144 ( V_209 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_399 )
return - V_82 ;
V_9 -> V_12 . V_14 -> V_350 &= ~ V_400 ;
return 0 ;
}
static void F_219 ( struct V_8 * V_9 )
{
struct V_401 * V_162 = & V_9 -> V_7 -> V_12 . V_162 ;
V_9 -> V_12 . V_14 -> V_231 = V_162 -> V_231 ;
if ( F_61 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_402 = ( T_7 ) ( V_173 ) V_162 -> V_164 ;
}
int F_220 ( struct V_8 * V_9 )
{
int V_311 = 0 ;
F_166 ( & V_9 -> V_12 . V_14 -> V_384 , V_403 |
V_404 |
V_405 ) ;
if ( F_61 ( V_9 -> V_7 , 78 ) )
F_207 ( V_406 , & V_9 -> V_12 . V_14 -> V_384 ) ;
else if ( F_61 ( V_9 -> V_7 , 8 ) )
F_207 ( V_407 , & V_9 -> V_12 . V_14 -> V_384 ) ;
F_219 ( V_9 ) ;
if ( V_58 )
V_9 -> V_12 . V_14 -> V_408 |= V_409 ;
if ( F_61 ( V_9 -> V_7 , 9 ) )
V_9 -> V_12 . V_14 -> V_408 |= V_410 ;
if ( F_61 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_408 |= V_411 ;
if ( F_61 ( V_9 -> V_7 , 8 ) && V_60 . V_412 )
V_9 -> V_12 . V_14 -> V_350 |= V_400 ;
if ( F_61 ( V_9 -> V_7 , 130 ) )
V_9 -> V_12 . V_14 -> V_350 |= V_413 ;
V_9 -> V_12 . V_14 -> V_414 = V_415 | V_416 ;
if ( V_60 . V_74 )
V_9 -> V_12 . V_14 -> V_414 |= V_417 ;
if ( V_60 . V_72 )
V_9 -> V_12 . V_14 -> V_414 |= V_418 ;
if ( V_60 . V_66 )
V_9 -> V_12 . V_14 -> V_414 |= V_419 ;
if ( V_60 . V_420 )
V_9 -> V_12 . V_14 -> V_414 |= V_421 ;
if ( F_61 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_414 |= V_422 ;
V_9 -> V_12 . V_14 -> V_423 |= V_424 ;
}
V_9 -> V_12 . V_14 -> V_425 = ( ( unsigned long ) & V_9 -> V_366 -> V_266 . V_426 . V_427 )
| V_428 ;
V_9 -> V_12 . V_14 -> V_429 = ( unsigned long ) & V_9 -> V_366 -> V_266 . V_426 . V_430 ;
if ( V_60 . V_78 )
F_207 ( V_431 , & V_9 -> V_12 . V_14 -> V_384 ) ;
else
V_9 -> V_12 . V_14 -> V_394 |= V_432 | V_433 | V_434 ;
if ( V_9 -> V_7 -> V_12 . V_181 ) {
V_311 = F_218 ( V_9 ) ;
if ( V_311 )
return V_311 ;
}
F_221 ( & V_9 -> V_12 . V_435 , V_436 , V_437 ) ;
V_9 -> V_12 . V_435 . V_438 = V_439 ;
F_63 ( V_9 ) ;
return V_311 ;
}
struct V_8 * F_222 ( struct V_7 * V_7 ,
unsigned int V_363 )
{
struct V_8 * V_9 ;
struct V_440 * V_440 ;
int V_311 = - V_91 ;
if ( ! F_39 ( V_7 ) && ! F_184 ( V_7 , V_363 ) )
goto V_150;
V_311 = - V_82 ;
V_9 = F_223 ( V_342 , V_209 ) ;
if ( ! V_9 )
goto V_150;
F_2 ( sizeof( struct V_440 ) != 4096 ) ;
V_440 = (struct V_440 * ) F_144 ( V_209 ) ;
if ( ! V_440 )
goto V_441;
V_9 -> V_12 . V_14 = & V_440 -> V_14 ;
V_9 -> V_12 . V_14 -> V_442 = ( unsigned long ) & V_440 -> V_443 ;
V_9 -> V_12 . V_14 -> V_444 = 0 ;
V_9 -> V_12 . V_14 -> V_445 = V_60 . V_335 ;
V_9 -> V_12 . V_14 -> V_446 = V_363 ;
F_148 ( & V_9 -> V_12 . V_447 . V_159 ) ;
V_9 -> V_12 . V_447 . V_327 = & V_7 -> V_12 . V_327 ;
V_9 -> V_12 . V_447 . V_448 = & V_9 -> V_448 ;
V_9 -> V_12 . V_447 . V_384 = & V_9 -> V_12 . V_14 -> V_384 ;
F_224 ( & V_9 -> V_12 . V_378 ) ;
V_311 = F_225 ( V_9 , V_7 , V_363 ) ;
if ( V_311 )
goto V_449;
F_48 ( V_7 , 3 , L_42 , V_363 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_226 ( V_363 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_449:
F_139 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_441:
F_164 ( V_342 , V_9 ) ;
V_150:
return F_227 ( V_311 ) ;
}
int F_228 ( struct V_8 * V_9 )
{
return F_229 ( V_9 , 0 ) ;
}
void F_230 ( struct V_8 * V_9 )
{
F_207 ( V_450 , & V_9 -> V_12 . V_14 -> V_451 ) ;
F_64 ( V_9 ) ;
}
void F_231 ( struct V_8 * V_9 )
{
F_210 ( V_450 , & V_9 -> V_12 . V_14 -> V_451 ) ;
}
static void F_232 ( struct V_8 * V_9 )
{
F_207 ( V_452 , & V_9 -> V_12 . V_14 -> V_451 ) ;
F_64 ( V_9 ) ;
}
static void F_233 ( struct V_8 * V_9 )
{
F_210 ( V_452 , & V_9 -> V_12 . V_14 -> V_451 ) ;
}
void F_64 ( struct V_8 * V_9 )
{
F_207 ( V_453 , & V_9 -> V_12 . V_14 -> V_384 ) ;
while ( V_9 -> V_12 . V_14 -> V_454 & V_455 )
F_234 () ;
}
void F_46 ( int V_200 , struct V_8 * V_9 )
{
F_235 ( V_200 , V_9 ) ;
F_232 ( V_9 ) ;
}
static void V_21 ( struct V_138 * V_138 , unsigned long V_456 ,
unsigned long V_457 )
{
struct V_7 * V_7 = V_138 -> V_188 ;
struct V_8 * V_9 ;
unsigned long V_458 ;
int V_10 ;
if ( F_236 ( V_138 ) )
return;
if ( V_456 >= 1UL << 31 )
return;
F_7 (i, vcpu, kvm) {
V_458 = F_237 ( V_9 ) ;
if ( V_458 <= V_457 && V_456 <= V_458 + 2 * V_323 - 1 ) {
F_157 ( V_9 , 2 , L_43 ,
V_456 , V_457 ) ;
F_46 ( V_459 , V_9 ) ;
}
}
}
int F_238 ( struct V_8 * V_9 )
{
F_239 () ;
return 0 ;
}
static int F_240 ( struct V_8 * V_9 ,
struct V_460 * V_461 )
{
int V_93 = - V_91 ;
switch ( V_461 -> V_363 ) {
case V_462 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_387 ,
( T_7 V_174 * ) V_461 -> V_175 ) ;
break;
case V_463 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_464 :
V_93 = F_52 ( F_200 ( V_9 ) ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_465 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_386 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_466 :
V_93 = F_52 ( V_9 -> V_12 . V_364 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_467 :
V_93 = F_52 ( V_9 -> V_12 . V_468 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_469 :
V_93 = F_52 ( V_9 -> V_12 . V_470 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_471 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_393 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_472 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_392 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
default:
break;
}
return V_93 ;
}
static int F_241 ( struct V_8 * V_9 ,
struct V_460 * V_461 )
{
int V_93 = - V_91 ;
V_348 V_5 ;
switch ( V_461 -> V_363 ) {
case V_462 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_387 ,
( T_7 V_174 * ) V_461 -> V_175 ) ;
break;
case V_463 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_464 :
V_93 = F_57 ( V_5 , ( V_173 V_174 * ) V_461 -> V_175 ) ;
if ( ! V_93 )
F_199 ( V_9 , V_5 ) ;
break;
case V_465 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_386 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_466 :
V_93 = F_57 ( V_9 -> V_12 . V_364 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
if ( V_9 -> V_12 . V_364 == V_365 )
F_160 ( V_9 ) ;
break;
case V_467 :
V_93 = F_57 ( V_9 -> V_12 . V_468 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_469 :
V_93 = F_57 ( V_9 -> V_12 . V_470 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_471 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_393 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
case V_472 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_392 ,
( V_173 V_174 * ) V_461 -> V_175 ) ;
break;
default:
break;
}
return V_93 ;
}
static int F_242 ( struct V_8 * V_9 )
{
F_213 ( V_9 ) ;
return 0 ;
}
int F_243 ( struct V_8 * V_9 , struct V_473 * V_426 )
{
memcpy ( & V_9 -> V_366 -> V_266 . V_426 . V_474 , & V_426 -> V_474 , sizeof( V_426 -> V_474 ) ) ;
return 0 ;
}
int F_244 ( struct V_8 * V_9 , struct V_473 * V_426 )
{
memcpy ( & V_426 -> V_474 , & V_9 -> V_366 -> V_266 . V_426 . V_474 , sizeof( V_426 -> V_474 ) ) ;
return 0 ;
}
int F_245 ( struct V_8 * V_9 ,
struct V_475 * V_476 )
{
memcpy ( & V_9 -> V_366 -> V_266 . V_426 . V_477 , & V_476 -> V_477 , sizeof( V_476 -> V_477 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_388 , & V_476 -> V_478 , sizeof( V_476 -> V_478 ) ) ;
return 0 ;
}
int F_246 ( struct V_8 * V_9 ,
struct V_475 * V_476 )
{
memcpy ( & V_476 -> V_477 , & V_9 -> V_366 -> V_266 . V_426 . V_477 , sizeof( V_476 -> V_477 ) ) ;
memcpy ( & V_476 -> V_478 , & V_9 -> V_12 . V_14 -> V_388 , sizeof( V_476 -> V_478 ) ) ;
return 0 ;
}
int F_247 ( struct V_8 * V_9 , struct V_479 * V_390 )
{
if ( F_248 ( V_390 -> V_391 ) )
return - V_91 ;
V_9 -> V_366 -> V_266 . V_426 . V_391 = V_390 -> V_391 ;
if ( V_130 )
F_249 ( ( V_480 * ) V_9 -> V_366 -> V_266 . V_426 . V_481 ,
( V_482 * ) V_390 -> V_483 ) ;
else
memcpy ( V_9 -> V_366 -> V_266 . V_426 . V_483 , & V_390 -> V_483 , sizeof( V_390 -> V_483 ) ) ;
return 0 ;
}
int F_250 ( struct V_8 * V_9 , struct V_479 * V_390 )
{
F_214 () ;
if ( V_130 )
F_251 ( ( V_482 * ) V_390 -> V_483 ,
( V_480 * ) V_9 -> V_366 -> V_266 . V_426 . V_481 ) ;
else
memcpy ( V_390 -> V_483 , V_9 -> V_366 -> V_266 . V_426 . V_483 , sizeof( V_390 -> V_483 ) ) ;
V_390 -> V_391 = V_9 -> V_366 -> V_266 . V_426 . V_391 ;
return 0 ;
}
static int F_252 ( struct V_8 * V_9 , T_9 V_484 )
{
int V_311 = 0 ;
if ( ! F_253 ( V_9 ) )
V_311 = - V_161 ;
else {
V_9 -> V_366 -> V_485 = V_484 . V_279 ;
V_9 -> V_366 -> V_486 = V_484 . V_175 ;
}
return V_311 ;
}
int F_254 ( struct V_8 * V_9 ,
struct V_487 * V_488 )
{
return - V_91 ;
}
int F_255 ( struct V_8 * V_9 ,
struct V_489 * V_490 )
{
int V_311 = 0 ;
V_9 -> V_491 = 0 ;
F_256 ( V_9 ) ;
if ( V_490 -> V_492 & ~ V_493 )
return - V_91 ;
if ( ! V_60 . V_68 )
return - V_91 ;
if ( V_490 -> V_492 & V_494 ) {
V_9 -> V_491 = V_490 -> V_492 ;
F_207 ( V_495 , & V_9 -> V_12 . V_14 -> V_384 ) ;
if ( V_490 -> V_492 & V_496 )
V_311 = F_257 ( V_9 , V_490 ) ;
} else {
F_210 ( V_495 , & V_9 -> V_12 . V_14 -> V_384 ) ;
V_9 -> V_12 . V_497 . V_498 = 0 ;
}
if ( V_311 ) {
V_9 -> V_491 = 0 ;
F_256 ( V_9 ) ;
F_210 ( V_495 , & V_9 -> V_12 . V_14 -> V_384 ) ;
}
return V_311 ;
}
int F_258 ( struct V_8 * V_9 ,
struct V_499 * V_500 )
{
return F_253 ( V_9 ) ? V_501 :
V_502 ;
}
int F_259 ( struct V_8 * V_9 ,
struct V_499 * V_500 )
{
int V_311 = 0 ;
V_9 -> V_7 -> V_12 . V_503 = 1 ;
switch ( V_500 -> V_500 ) {
case V_501 :
F_216 ( V_9 ) ;
break;
case V_502 :
F_260 ( V_9 ) ;
break;
case V_504 :
case V_505 :
default:
V_311 = - V_177 ;
}
return V_311 ;
}
static bool F_261 ( struct V_8 * V_9 )
{
return F_50 ( & V_9 -> V_12 . V_14 -> V_384 ) & V_506 ;
}
static int F_262 ( struct V_8 * V_9 )
{
V_507:
F_233 ( V_9 ) ;
if ( ! F_263 ( V_9 ) )
return 0 ;
if ( F_264 ( V_459 , V_9 ) ) {
int V_311 ;
V_311 = F_265 ( V_9 -> V_12 . V_138 ,
F_237 ( V_9 ) ,
V_323 * 2 , V_508 ) ;
if ( V_311 ) {
F_235 ( V_459 , V_9 ) ;
return V_311 ;
}
goto V_507;
}
if ( F_264 ( V_509 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_510 = 0xffff ;
goto V_507;
}
if ( F_264 ( V_511 , V_9 ) ) {
if ( ! F_261 ( V_9 ) ) {
F_266 ( V_9 -> V_341 , 1 ) ;
F_207 ( V_506 ,
& V_9 -> V_12 . V_14 -> V_384 ) ;
}
goto V_507;
}
if ( F_264 ( V_512 , V_9 ) ) {
if ( F_261 ( V_9 ) ) {
F_266 ( V_9 -> V_341 , 0 ) ;
F_210 ( V_506 ,
& V_9 -> V_12 . V_14 -> V_384 ) ;
}
goto V_507;
}
if ( F_264 ( V_153 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_394 |= V_395 ;
goto V_507;
}
if ( F_264 ( V_215 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_350 &= ~ V_513 ;
goto V_507;
}
if ( F_264 ( V_216 , V_9 ) ) {
if ( ( V_9 -> V_7 -> V_12 . V_181 ) &&
( V_9 -> V_7 -> V_141 -> V_275 . V_181 ) )
V_9 -> V_12 . V_14 -> V_350 |= V_513 ;
goto V_507;
}
F_267 ( V_514 , V_9 ) ;
return 0 ;
}
void F_81 ( struct V_7 * V_7 , V_173 V_515 )
{
struct V_8 * V_9 ;
int V_10 ;
F_40 ( & V_7 -> V_159 ) ;
F_196 () ;
V_7 -> V_12 . V_13 = V_515 - F_268 () ;
F_180 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_183 ( V_7 ) ;
F_197 () ;
F_44 ( & V_7 -> V_159 ) ;
}
long F_269 ( struct V_8 * V_9 , T_10 V_516 , int V_517 )
{
return F_270 ( V_9 -> V_12 . V_138 , V_516 ,
V_517 ? V_518 : 0 ) ;
}
static void F_271 ( struct V_8 * V_9 , bool V_519 ,
unsigned long V_520 )
{
struct V_285 V_521 ;
struct V_522 V_523 ;
if ( V_519 ) {
V_523 . V_524 . V_92 . V_525 = V_520 ;
V_523 . type = V_526 ;
F_188 ( F_272 ( V_9 , & V_523 ) ) ;
} else {
V_521 . type = V_527 ;
V_521 . V_528 = V_520 ;
F_188 ( F_129 ( V_9 -> V_7 , & V_521 ) ) ;
}
}
void F_273 ( struct V_8 * V_9 ,
struct V_529 * V_530 )
{
F_274 ( V_9 , V_530 -> V_12 . V_364 ) ;
F_271 ( V_9 , true , V_530 -> V_12 . V_364 ) ;
}
void F_275 ( struct V_8 * V_9 ,
struct V_529 * V_530 )
{
F_276 ( V_9 , V_530 -> V_12 . V_364 ) ;
F_271 ( V_9 , false , V_530 -> V_12 . V_364 ) ;
}
void F_277 ( struct V_8 * V_9 ,
struct V_529 * V_530 )
{
}
bool F_278 ( struct V_8 * V_9 )
{
return true ;
}
static int F_279 ( struct V_8 * V_9 )
{
T_11 V_257 ;
struct V_531 V_12 ;
int V_311 ;
if ( V_9 -> V_12 . V_364 == V_365 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_385 . V_279 & V_9 -> V_12 . V_470 ) !=
V_9 -> V_12 . V_468 )
return 0 ;
if ( F_280 ( V_9 ) )
return 0 ;
if ( F_229 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_388 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_138 -> V_338 )
return 0 ;
V_257 = F_108 ( V_9 -> V_7 , F_281 ( V_142 -> V_389 . V_532 ) ) ;
V_257 += V_142 -> V_389 . V_532 & ~ V_533 ;
if ( F_282 ( V_9 , V_9 -> V_12 . V_364 , & V_12 . V_364 , 8 ) )
return 0 ;
V_311 = F_283 ( V_9 , V_142 -> V_389 . V_532 , V_257 , & V_12 ) ;
return V_311 ;
}
static int F_284 ( struct V_8 * V_9 )
{
int V_311 , V_384 ;
F_285 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_534 = V_9 -> V_366 -> V_266 . V_426 . V_474 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_535 = V_9 -> V_366 -> V_266 . V_426 . V_474 [ 15 ] ;
if ( F_286 () )
F_287 () ;
if ( F_288 ( V_536 ) )
F_289 () ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_311 = F_290 ( V_9 ) ;
if ( V_311 )
return V_311 ;
}
V_311 = F_262 ( V_9 ) ;
if ( V_311 )
return V_311 ;
if ( F_291 ( V_9 ) ) {
F_292 ( V_9 ) ;
F_293 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_537 = 0 ;
V_384 = F_50 ( & V_9 -> V_12 . V_14 -> V_384 ) ;
F_157 ( V_9 , 6 , L_44 , V_384 ) ;
F_294 ( V_9 , V_384 ) ;
return 0 ;
}
static int F_295 ( struct V_8 * V_9 )
{
struct V_538 V_539 = {
. V_540 = V_541 ,
} ;
T_3 V_542 , V_543 ;
int V_311 ;
F_157 ( V_9 , 3 , L_3 , L_45 ) ;
F_296 ( V_9 ) ;
V_311 = F_297 ( V_9 , V_9 -> V_12 . V_14 -> V_385 . V_175 , & V_542 , 1 ) ;
V_543 = F_298 ( V_542 ) ;
if ( V_311 < 0 ) {
return V_311 ;
} else if ( V_311 ) {
V_539 = V_9 -> V_12 . V_544 ;
V_543 = 4 ;
}
V_539 . V_156 = V_543 | V_545 ;
F_299 ( V_9 , V_543 ) ;
return F_300 ( V_9 , & V_539 ) ;
}
static int F_301 ( struct V_8 * V_9 , int V_546 )
{
struct V_547 * V_548 ;
struct V_440 * V_440 ;
F_157 ( V_9 , 6 , L_46 ,
V_9 -> V_12 . V_14 -> V_537 ) ;
F_302 ( V_9 , V_9 -> V_12 . V_14 -> V_537 ) ;
if ( F_291 ( V_9 ) )
F_303 ( V_9 ) ;
V_9 -> V_366 -> V_266 . V_426 . V_474 [ 14 ] = V_9 -> V_12 . V_14 -> V_534 ;
V_9 -> V_366 -> V_266 . V_426 . V_474 [ 15 ] = V_9 -> V_12 . V_14 -> V_535 ;
if ( V_546 == - V_549 ) {
F_157 ( V_9 , 3 , L_3 , L_47 ) ;
V_440 = F_304 ( V_9 -> V_12 . V_14 ,
struct V_440 , V_14 ) ;
V_548 = & V_440 -> V_548 ;
F_305 ( V_9 , V_548 ) ;
return 0 ;
}
if ( V_9 -> V_12 . V_14 -> V_537 > 0 ) {
int V_311 = F_306 ( V_9 ) ;
if ( V_311 != - V_550 )
return V_311 ;
V_9 -> V_366 -> V_546 = V_551 ;
V_9 -> V_366 -> V_552 . V_537 = V_9 -> V_12 . V_14 -> V_537 ;
V_9 -> V_366 -> V_552 . V_553 = V_9 -> V_12 . V_14 -> V_553 ;
V_9 -> V_366 -> V_552 . V_554 = V_9 -> V_12 . V_14 -> V_554 ;
return - V_555 ;
} else if ( V_546 != - V_176 ) {
V_9 -> V_556 . V_557 ++ ;
return 0 ;
} else if ( F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_366 -> V_546 = V_558 ;
V_9 -> V_366 -> V_559 . V_560 =
V_142 -> V_389 . V_532 ;
V_9 -> V_366 -> V_559 . V_561 = 0x10 ;
return - V_555 ;
} else if ( V_142 -> V_389 . V_562 ) {
F_307 ( V_9 ) ;
V_142 -> V_389 . V_562 = 0 ;
if ( F_279 ( V_9 ) )
return 0 ;
return F_269 ( V_9 , V_142 -> V_389 . V_532 , 1 ) ;
}
return F_295 ( V_9 ) ;
}
static int F_308 ( struct V_8 * V_9 )
{
int V_311 , V_546 ;
V_9 -> V_258 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
do {
V_311 = F_284 ( V_9 ) ;
if ( V_311 )
break;
F_56 ( & V_9 -> V_7 -> V_183 , V_9 -> V_258 ) ;
F_309 () ;
F_310 () ;
F_194 ( V_9 ) ;
F_311 () ;
V_546 = F_312 ( V_9 -> V_12 . V_14 ,
V_9 -> V_366 -> V_266 . V_426 . V_474 ) ;
F_309 () ;
F_193 ( V_9 ) ;
F_313 () ;
F_311 () ;
V_9 -> V_258 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
V_311 = F_301 ( V_9 , V_546 ) ;
} while ( ! F_314 ( V_142 ) && ! F_315 ( V_9 ) && ! V_311 );
F_56 ( & V_9 -> V_7 -> V_183 , V_9 -> V_258 ) ;
return V_311 ;
}
static void F_316 ( struct V_8 * V_9 , struct V_563 * V_563 )
{
struct V_564 * V_430 ;
struct V_565 * V_566 ;
V_430 = (struct V_564 * ) & V_563 -> V_266 . V_426 . V_430 ;
V_566 = (struct V_565 * ) & V_563 -> V_266 . V_426 . V_566 ;
V_9 -> V_12 . V_14 -> V_385 . V_279 = V_563 -> V_485 ;
V_9 -> V_12 . V_14 -> V_385 . V_175 = V_563 -> V_486 ;
if ( V_563 -> V_567 & V_368 )
F_186 ( V_9 , V_563 -> V_266 . V_426 . V_458 ) ;
if ( V_563 -> V_567 & V_371 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_388 , & V_563 -> V_266 . V_426 . V_478 , 128 ) ;
F_235 ( V_509 , V_9 ) ;
}
if ( V_563 -> V_567 & V_372 ) {
F_199 ( V_9 , V_563 -> V_266 . V_426 . V_379 ) ;
V_9 -> V_12 . V_14 -> V_386 = V_563 -> V_266 . V_426 . V_386 ;
V_9 -> V_12 . V_14 -> V_387 = V_563 -> V_266 . V_426 . V_387 ;
V_9 -> V_12 . V_14 -> V_393 = V_563 -> V_266 . V_426 . V_393 ;
V_9 -> V_12 . V_14 -> V_392 = V_563 -> V_266 . V_426 . V_392 ;
}
if ( V_563 -> V_567 & V_373 ) {
V_9 -> V_12 . V_364 = V_563 -> V_266 . V_426 . V_568 ;
V_9 -> V_12 . V_470 = V_563 -> V_266 . V_426 . V_569 ;
V_9 -> V_12 . V_468 = V_563 -> V_266 . V_426 . V_570 ;
if ( V_9 -> V_12 . V_364 == V_365 )
F_160 ( V_9 ) ;
}
if ( ( V_563 -> V_567 & V_374 ) &&
F_61 ( V_9 -> V_7 , 64 ) &&
V_430 -> V_571 &&
! ( V_9 -> V_12 . V_14 -> V_396 & V_572 ) ) {
F_157 ( V_9 , 3 , L_3 , L_48 ) ;
V_9 -> V_12 . V_14 -> V_396 |= V_572 ;
}
if ( ( V_563 -> V_567 & V_375 ) &&
F_61 ( V_9 -> V_7 , 133 ) &&
V_566 -> V_573 &&
! V_9 -> V_12 . V_574 ) {
F_157 ( V_9 , 3 , L_3 , L_49 ) ;
V_9 -> V_12 . V_14 -> V_408 |= V_575 ;
V_9 -> V_12 . V_14 -> V_423 |= V_424 ;
V_9 -> V_12 . V_574 = 1 ;
}
F_317 ( V_9 -> V_12 . V_576 ) ;
F_318 ( V_9 -> V_366 -> V_266 . V_426 . V_477 ) ;
F_214 () ;
V_9 -> V_12 . V_577 . V_391 = V_142 -> V_389 . V_390 . V_391 ;
V_9 -> V_12 . V_577 . V_426 = V_142 -> V_389 . V_390 . V_426 ;
if ( V_130 )
V_142 -> V_389 . V_390 . V_426 = V_9 -> V_366 -> V_266 . V_426 . V_481 ;
else
V_142 -> V_389 . V_390 . V_426 = V_9 -> V_366 -> V_266 . V_426 . V_483 ;
V_142 -> V_389 . V_390 . V_391 = V_9 -> V_366 -> V_266 . V_426 . V_391 ;
if ( F_248 ( V_142 -> V_389 . V_390 . V_391 ) )
V_142 -> V_389 . V_390 . V_391 = 0 ;
if ( V_578 ) {
F_196 () ;
F_319 ( 2 , 4 ) ;
if ( V_142 -> V_389 . V_565 ) {
V_9 -> V_12 . V_579 = V_142 -> V_389 . V_565 ;
F_320 ( V_9 -> V_12 . V_579 ) ;
}
if ( V_9 -> V_12 . V_574 ) {
V_142 -> V_389 . V_565 = (struct V_565 * )
& V_9 -> V_366 -> V_266 . V_426 . V_566 ;
F_321 ( V_142 -> V_389 . V_565 ) ;
}
F_197 () ;
}
V_563 -> V_567 = 0 ;
}
static void F_322 ( struct V_8 * V_9 , struct V_563 * V_563 )
{
V_563 -> V_485 = V_9 -> V_12 . V_14 -> V_385 . V_279 ;
V_563 -> V_486 = V_9 -> V_12 . V_14 -> V_385 . V_175 ;
V_563 -> V_266 . V_426 . V_458 = F_237 ( V_9 ) ;
memcpy ( & V_563 -> V_266 . V_426 . V_478 , & V_9 -> V_12 . V_14 -> V_388 , 128 ) ;
V_563 -> V_266 . V_426 . V_379 = F_200 ( V_9 ) ;
V_563 -> V_266 . V_426 . V_386 = V_9 -> V_12 . V_14 -> V_386 ;
V_563 -> V_266 . V_426 . V_387 = V_9 -> V_12 . V_14 -> V_387 ;
V_563 -> V_266 . V_426 . V_393 = V_9 -> V_12 . V_14 -> V_393 ;
V_563 -> V_266 . V_426 . V_392 = V_9 -> V_12 . V_14 -> V_392 ;
V_563 -> V_266 . V_426 . V_568 = V_9 -> V_12 . V_364 ;
V_563 -> V_266 . V_426 . V_569 = V_9 -> V_12 . V_470 ;
V_563 -> V_266 . V_426 . V_570 = V_9 -> V_12 . V_468 ;
F_317 ( V_9 -> V_366 -> V_266 . V_426 . V_477 ) ;
F_318 ( V_9 -> V_12 . V_576 ) ;
F_214 () ;
V_9 -> V_366 -> V_266 . V_426 . V_391 = V_142 -> V_389 . V_390 . V_391 ;
V_142 -> V_389 . V_390 . V_391 = V_9 -> V_12 . V_577 . V_391 ;
V_142 -> V_389 . V_390 . V_426 = V_9 -> V_12 . V_577 . V_426 ;
if ( V_578 ) {
F_319 ( 2 , 4 ) ;
if ( V_9 -> V_12 . V_574 )
F_320 ( V_142 -> V_389 . V_565 ) ;
F_196 () ;
V_142 -> V_389 . V_565 = V_9 -> V_12 . V_579 ;
F_321 ( V_9 -> V_12 . V_579 ) ;
F_197 () ;
if ( ! V_9 -> V_12 . V_579 )
F_323 ( 2 , 4 ) ;
V_9 -> V_12 . V_579 = NULL ;
}
}
int F_324 ( struct V_8 * V_9 , struct V_563 * V_563 )
{
int V_311 ;
T_12 V_580 ;
if ( V_563 -> V_581 )
return - V_549 ;
if ( F_315 ( V_9 ) ) {
F_325 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_582 )
F_326 ( V_583 , & V_9 -> V_584 , & V_580 ) ;
if ( ! F_215 ( V_9 -> V_7 ) ) {
F_260 ( V_9 ) ;
} else if ( F_253 ( V_9 ) ) {
F_327 ( L_50 ,
V_9 -> V_341 ) ;
return - V_91 ;
}
F_316 ( V_9 , V_563 ) ;
F_195 ( V_9 ) ;
F_328 () ;
V_311 = F_308 ( V_9 ) ;
if ( F_314 ( V_142 ) && ! V_311 ) {
V_563 -> V_546 = V_585 ;
V_311 = - V_549 ;
}
if ( F_315 ( V_9 ) && ! V_311 ) {
F_325 ( V_9 ) ;
V_311 = 0 ;
}
if ( V_311 == - V_555 ) {
V_311 = 0 ;
}
F_198 ( V_9 ) ;
F_322 ( V_9 , V_563 ) ;
if ( V_9 -> V_582 )
F_326 ( V_583 , & V_580 , NULL ) ;
V_9 -> V_556 . V_586 ++ ;
return V_311 ;
}
int F_329 ( struct V_8 * V_9 , unsigned long V_516 )
{
unsigned char V_587 = 1 ;
V_482 V_483 [ V_588 ] ;
unsigned int V_589 ;
V_173 V_590 , V_379 ;
int V_311 ;
V_589 = F_237 ( V_9 ) ;
if ( V_516 == V_591 ) {
if ( F_330 ( V_9 , 163 , & V_587 , 1 ) )
return - V_176 ;
V_516 = 0 ;
} else if ( V_516 == V_592 ) {
if ( F_331 ( V_9 , 163 , & V_587 , 1 ) )
return - V_176 ;
V_516 = V_589 ;
} else
V_516 -= V_593 ;
if ( V_130 ) {
F_251 ( V_483 , ( V_480 * ) V_9 -> V_366 -> V_266 . V_426 . V_481 ) ;
V_311 = F_330 ( V_9 , V_516 + V_593 ,
V_483 , 128 ) ;
} else {
V_311 = F_330 ( V_9 , V_516 + V_593 ,
V_9 -> V_366 -> V_266 . V_426 . V_483 , 128 ) ;
}
V_311 |= F_330 ( V_9 , V_516 + V_594 ,
V_9 -> V_366 -> V_266 . V_426 . V_474 , 128 ) ;
V_311 |= F_330 ( V_9 , V_516 + V_595 ,
& V_9 -> V_12 . V_14 -> V_385 , 16 ) ;
V_311 |= F_330 ( V_9 , V_516 + V_596 ,
& V_589 , 4 ) ;
V_311 |= F_330 ( V_9 , V_516 + V_597 ,
& V_9 -> V_366 -> V_266 . V_426 . V_391 , 4 ) ;
V_311 |= F_330 ( V_9 , V_516 + V_598 ,
& V_9 -> V_12 . V_14 -> V_387 , 4 ) ;
V_379 = F_200 ( V_9 ) ;
V_311 |= F_330 ( V_9 , V_516 + V_599 ,
& V_379 , 8 ) ;
V_590 = V_9 -> V_12 . V_14 -> V_386 >> 8 ;
V_311 |= F_330 ( V_9 , V_516 + V_600 ,
& V_590 , 8 ) ;
V_311 |= F_330 ( V_9 , V_516 + V_601 ,
& V_9 -> V_366 -> V_266 . V_426 . V_477 , 64 ) ;
V_311 |= F_330 ( V_9 , V_516 + V_602 ,
& V_9 -> V_12 . V_14 -> V_388 , 128 ) ;
return V_311 ? - V_176 : 0 ;
}
int F_332 ( struct V_8 * V_9 , unsigned long V_175 )
{
F_214 () ;
V_9 -> V_366 -> V_266 . V_426 . V_391 = V_142 -> V_389 . V_390 . V_391 ;
F_317 ( V_9 -> V_366 -> V_266 . V_426 . V_477 ) ;
return F_329 ( V_9 , V_175 ) ;
}
static void F_333 ( struct V_8 * V_9 )
{
F_264 ( V_511 , V_9 ) ;
F_46 ( V_512 , V_9 ) ;
}
static void F_334 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_333 ( V_9 ) ;
}
}
static void F_335 ( struct V_8 * V_9 )
{
if ( ! V_60 . V_76 )
return;
F_264 ( V_512 , V_9 ) ;
F_46 ( V_511 , V_9 ) ;
}
void F_260 ( struct V_8 * V_9 )
{
int V_10 , V_165 , V_603 = 0 ;
if ( ! F_253 ( V_9 ) )
return;
F_336 ( V_9 -> V_341 , 1 ) ;
F_145 ( & V_9 -> V_7 -> V_12 . V_340 ) ;
V_165 = F_50 ( & V_9 -> V_7 -> V_165 ) ;
for ( V_10 = 0 ; V_10 < V_165 ; V_10 ++ ) {
if ( ! F_253 ( V_9 -> V_7 -> V_343 [ V_10 ] ) )
V_603 ++ ;
}
if ( V_603 == 0 ) {
F_335 ( V_9 ) ;
} else if ( V_603 == 1 ) {
F_334 ( V_9 -> V_7 ) ;
}
F_210 ( V_405 , & V_9 -> V_12 . V_14 -> V_384 ) ;
F_235 ( V_509 , V_9 ) ;
F_146 ( & V_9 -> V_7 -> V_12 . V_340 ) ;
return;
}
void F_216 ( struct V_8 * V_9 )
{
int V_10 , V_165 , V_603 = 0 ;
struct V_8 * V_604 = NULL ;
if ( F_253 ( V_9 ) )
return;
F_336 ( V_9 -> V_341 , 0 ) ;
F_145 ( & V_9 -> V_7 -> V_12 . V_340 ) ;
V_165 = F_50 ( & V_9 -> V_7 -> V_165 ) ;
F_337 ( V_9 ) ;
F_207 ( V_405 , & V_9 -> V_12 . V_14 -> V_384 ) ;
F_333 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_165 ; V_10 ++ ) {
if ( ! F_253 ( V_9 -> V_7 -> V_343 [ V_10 ] ) ) {
V_603 ++ ;
V_604 = V_9 -> V_7 -> V_343 [ V_10 ] ;
}
}
if ( V_603 == 1 ) {
F_335 ( V_604 ) ;
}
F_146 ( & V_9 -> V_7 -> V_12 . V_340 ) ;
return;
}
static int F_338 ( struct V_8 * V_9 ,
struct V_154 * V_155 )
{
int V_93 ;
if ( V_155 -> V_156 )
return - V_91 ;
switch ( V_155 -> V_155 ) {
case V_102 :
if ( ! V_9 -> V_7 -> V_12 . V_339 ) {
V_9 -> V_7 -> V_12 . V_339 = 1 ;
F_48 ( V_9 -> V_7 , 3 , L_3 , L_51 ) ;
F_339 ( V_9 -> V_7 ) ;
}
V_93 = 0 ;
break;
default:
V_93 = - V_91 ;
break;
}
return V_93 ;
}
static long F_340 ( struct V_8 * V_9 ,
struct V_605 * V_606 )
{
void V_174 * V_607 = ( void V_174 * ) V_606 -> V_608 ;
void * V_609 = NULL ;
int V_93 , V_258 ;
const V_173 V_610 = V_611
| V_612 ;
if ( V_606 -> V_156 & ~ V_610 )
return - V_91 ;
if ( V_606 -> V_613 > V_119 )
return - V_186 ;
if ( ! ( V_606 -> V_156 & V_612 ) ) {
V_609 = F_69 ( V_606 -> V_613 ) ;
if ( ! V_609 )
return - V_82 ;
}
V_258 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
switch ( V_606 -> V_614 ) {
case V_615 :
if ( V_606 -> V_156 & V_612 ) {
V_93 = F_341 ( V_9 , V_606 -> V_616 , V_606 -> V_617 ,
V_606 -> V_613 , V_618 ) ;
break;
}
V_93 = F_342 ( V_9 , V_606 -> V_616 , V_606 -> V_617 , V_609 , V_606 -> V_613 ) ;
if ( V_93 == 0 ) {
if ( F_77 ( V_607 , V_609 , V_606 -> V_613 ) )
V_93 = - V_176 ;
}
break;
case V_619 :
if ( V_606 -> V_156 & V_612 ) {
V_93 = F_341 ( V_9 , V_606 -> V_616 , V_606 -> V_617 ,
V_606 -> V_613 , V_620 ) ;
break;
}
if ( F_79 ( V_609 , V_607 , V_606 -> V_613 ) ) {
V_93 = - V_176 ;
break;
}
V_93 = F_343 ( V_9 , V_606 -> V_616 , V_606 -> V_617 , V_609 , V_606 -> V_613 ) ;
break;
default:
V_93 = - V_91 ;
}
F_56 ( & V_9 -> V_7 -> V_183 , V_258 ) ;
if ( V_93 > 0 && ( V_606 -> V_156 & V_611 ) != 0 )
F_300 ( V_9 , & V_9 -> V_12 . V_544 ) ;
F_74 ( V_609 ) ;
return V_93 ;
}
long F_344 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_8 * V_9 = V_87 -> V_282 ;
void V_174 * V_283 = ( void V_174 * ) V_89 ;
int V_178 ;
long V_93 ;
switch ( V_88 ) {
case V_621 : {
struct V_522 V_622 ;
V_93 = - V_176 ;
if ( F_79 ( & V_622 , V_283 , sizeof( V_622 ) ) )
break;
V_93 = F_272 ( V_9 , & V_622 ) ;
break;
}
case V_284 : {
struct V_285 V_286 ;
struct V_522 V_622 ;
V_93 = - V_176 ;
if ( F_79 ( & V_286 , V_283 , sizeof( V_286 ) ) )
break;
if ( F_345 ( & V_286 , & V_622 ) )
return - V_91 ;
V_93 = F_272 ( V_9 , & V_622 ) ;
break;
}
case V_623 :
V_178 = F_54 ( & V_9 -> V_7 -> V_183 ) ;
V_93 = F_332 ( V_9 , V_89 ) ;
F_56 ( & V_9 -> V_7 -> V_183 , V_178 ) ;
break;
case V_624 : {
T_9 V_484 ;
V_93 = - V_176 ;
if ( F_79 ( & V_484 , V_283 , sizeof( V_484 ) ) )
break;
V_93 = F_252 ( V_9 , V_484 ) ;
break;
}
case V_625 :
V_93 = F_242 ( V_9 ) ;
break;
case V_626 :
case V_627 : {
struct V_460 V_461 ;
V_93 = - V_176 ;
if ( F_79 ( & V_461 , V_283 , sizeof( V_461 ) ) )
break;
if ( V_88 == V_626 )
V_93 = F_241 ( V_9 , & V_461 ) ;
else
V_93 = F_240 ( V_9 , & V_461 ) ;
break;
}
#ifdef F_30
case V_628 : {
struct V_629 V_630 ;
if ( F_79 ( & V_630 , V_283 , sizeof( V_630 ) ) ) {
V_93 = - V_176 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_93 = - V_91 ;
break;
}
V_93 = F_346 ( V_9 -> V_12 . V_138 , V_630 . V_631 ,
V_630 . V_632 , V_630 . V_633 ) ;
break;
}
case V_634 : {
struct V_629 V_630 ;
if ( F_79 ( & V_630 , V_283 , sizeof( V_630 ) ) ) {
V_93 = - V_176 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_93 = - V_91 ;
break;
}
V_93 = F_347 ( V_9 -> V_12 . V_138 , V_630 . V_632 ,
V_630 . V_633 ) ;
break;
}
#endif
case V_635 : {
V_93 = F_270 ( V_9 -> V_12 . V_138 , V_89 , 0 ) ;
break;
}
case V_287 :
{
struct V_154 V_155 ;
V_93 = - V_176 ;
if ( F_79 ( & V_155 , V_283 , sizeof( V_155 ) ) )
break;
V_93 = F_338 ( V_9 , & V_155 ) ;
break;
}
case V_636 : {
struct V_605 V_637 ;
if ( F_79 ( & V_637 , V_283 , sizeof( V_637 ) ) == 0 )
V_93 = F_340 ( V_9 , & V_637 ) ;
else
V_93 = - V_176 ;
break;
}
case V_638 : {
struct V_639 V_640 ;
V_93 = - V_176 ;
if ( F_79 ( & V_640 , V_283 , sizeof( V_640 ) ) )
break;
if ( V_640 . V_641 > V_642 ||
V_640 . V_641 == 0 ||
V_640 . V_641 % sizeof( struct V_522 ) > 0 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_348 ( V_9 ,
( void V_174 * ) V_640 . V_608 ,
V_640 . V_641 ) ;
break;
}
case V_643 : {
struct V_639 V_640 ;
V_93 = - V_176 ;
if ( F_79 ( & V_640 , V_283 , sizeof( V_640 ) ) )
break;
if ( V_640 . V_641 == 0 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_349 ( V_9 ,
( V_644 V_174 * ) V_640 . V_608 ,
V_640 . V_641 ) ;
break;
}
default:
V_93 = - V_298 ;
}
return V_93 ;
}
int F_350 ( struct V_8 * V_9 , struct V_645 * V_646 )
{
#ifdef F_30
if ( ( V_646 -> V_647 == V_648 )
&& ( F_39 ( V_9 -> V_7 ) ) ) {
V_646 -> V_649 = F_351 ( V_9 -> V_12 . V_14 ) ;
F_352 ( V_646 -> V_649 ) ;
return 0 ;
}
#endif
return V_650 ;
}
int F_353 ( struct V_7 * V_7 , struct V_133 * V_149 ,
unsigned long V_140 )
{
return 0 ;
}
int F_354 ( struct V_7 * V_7 ,
struct V_133 * V_134 ,
const struct V_651 * V_652 ,
enum V_653 V_654 )
{
if ( V_652 -> V_655 & 0xffffful )
return - V_91 ;
if ( V_652 -> V_656 & 0xffffful )
return - V_91 ;
if ( V_652 -> V_657 + V_652 -> V_656 > V_7 -> V_12 . V_172 )
return - V_91 ;
return 0 ;
}
void F_355 ( struct V_7 * V_7 ,
const struct V_651 * V_652 ,
const struct V_133 * V_658 ,
const struct V_133 * V_187 ,
enum V_653 V_654 )
{
int V_311 ;
if ( V_658 -> V_655 == V_652 -> V_655 &&
V_658 -> V_139 * V_323 == V_652 -> V_657 &&
V_658 -> V_140 * V_323 == V_652 -> V_656 )
return;
V_311 = F_346 ( V_7 -> V_12 . V_138 , V_652 -> V_655 ,
V_652 -> V_657 , V_652 -> V_656 ) ;
if ( V_311 )
F_356 ( L_52 ) ;
return;
}
static inline unsigned long F_357 ( int V_10 )
{
unsigned int V_659 = ( V_60 . V_660 << V_10 * 2 ) >> 30 ;
return 0x0000ffffffffffffUL >> ( V_659 << 4 ) ;
}
void F_358 ( struct V_8 * V_9 )
{
V_9 -> V_661 = false ;
}
static int T_13 F_359 ( void )
{
int V_10 ;
if ( ! V_60 . V_61 ) {
F_360 ( L_53 ) ;
return - V_662 ;
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_1 [ V_10 ] |=
V_243 . V_244 [ V_10 ] & F_357 ( V_10 ) ;
return F_361 ( NULL , sizeof( struct V_8 ) , 0 , V_663 ) ;
}
static void T_14 F_362 ( void )
{
F_363 () ;
}
