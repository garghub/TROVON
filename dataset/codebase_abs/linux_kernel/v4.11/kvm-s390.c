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
if ( V_56 )
F_14 ( V_57 ) ;
if ( ! V_58 . V_59 || ! V_56 || ! V_58 . V_60 ||
! F_18 ( 3 ) || ! V_61 )
return;
F_14 ( V_62 ) ;
if ( V_58 . V_60 )
F_14 ( V_63 ) ;
if ( V_58 . V_64 )
F_14 ( V_65 ) ;
if ( V_58 . V_66 )
F_14 ( V_67 ) ;
if ( V_58 . V_68 )
F_14 ( V_69 ) ;
if ( V_58 . V_70 )
F_14 ( V_71 ) ;
if ( V_58 . V_72 )
F_14 ( V_73 ) ;
if ( V_58 . V_74 )
F_14 ( V_75 ) ;
}
int F_21 ( void * V_76 )
{
V_77 = F_22 ( L_2 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_77 )
return - V_78 ;
if ( F_23 ( V_77 , & V_79 ) ) {
F_24 ( V_77 ) ;
return - V_78 ;
}
F_17 () ;
return F_25 ( & V_80 , V_81 ) ;
}
void F_26 ( void )
{
F_24 ( V_77 ) ;
}
long F_27 ( struct V_82 * V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
if ( V_84 == V_86 )
return F_28 () ;
return - V_87 ;
}
int F_29 ( struct V_7 * V_7 , long V_88 )
{
int V_89 ;
switch ( V_88 ) {
case V_90 :
case V_91 :
case V_92 :
#ifdef F_30
case V_93 :
#endif
case V_94 :
case V_95 :
case V_96 :
case V_97 :
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
V_89 = 1 ;
break;
case V_112 :
V_89 = V_113 ;
break;
case V_114 :
case V_115 :
V_89 = V_116 ;
if ( ! F_31 () )
V_89 = V_117 ;
else if ( V_58 . V_118 && V_58 . V_60 )
V_89 = V_119 ;
break;
case V_120 :
V_89 = V_121 ;
break;
case V_122 :
V_89 = V_56 ;
break;
case V_123 :
V_89 = V_124 ;
break;
case V_125 :
V_89 = F_18 ( 64 ) ;
break;
default:
V_89 = 0 ;
}
return V_89 ;
}
static void F_32 ( struct V_7 * V_7 ,
struct V_126 * V_127 )
{
T_2 V_128 , V_129 ;
unsigned long V_130 ;
struct V_131 * V_131 = V_7 -> V_12 . V_131 ;
V_129 = V_127 -> V_132 + V_127 -> V_133 ;
for ( V_128 = V_127 -> V_132 ; V_128 <= V_129 ; V_128 ++ ) {
V_130 = F_33 ( V_127 , V_128 ) ;
if ( F_34 ( V_131 -> V_134 , V_130 ) )
F_35 ( V_7 , V_128 ) ;
if ( F_36 ( V_135 ) )
return;
F_37 () ;
}
}
int F_38 ( struct V_7 * V_7 ,
struct V_136 * log )
{
int V_89 ;
unsigned long V_137 ;
struct V_138 * V_139 ;
struct V_126 * V_127 ;
int V_140 = 0 ;
if ( F_39 ( V_7 ) )
return - V_87 ;
F_40 ( & V_7 -> V_141 ) ;
V_89 = - V_87 ;
if ( log -> V_142 >= V_121 )
goto V_143;
V_139 = V_138 ( V_7 ) ;
V_127 = F_41 ( V_139 , log -> V_142 ) ;
V_89 = - V_144 ;
if ( ! V_127 -> V_145 )
goto V_143;
F_32 ( V_7 , V_127 ) ;
V_89 = F_42 ( V_7 , log , & V_140 ) ;
if ( V_89 )
goto V_143;
if ( V_140 ) {
V_137 = F_43 ( V_127 ) ;
memset ( V_127 -> V_145 , 0 , V_137 ) ;
}
V_89 = 0 ;
V_143:
F_44 ( & V_7 -> V_141 ) ;
return V_89 ;
}
static void F_45 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_46 ( V_146 , V_9 ) ;
}
}
static int F_47 ( struct V_7 * V_7 , struct V_147 * V_148 )
{
int V_89 ;
if ( V_148 -> V_149 )
return - V_87 ;
switch ( V_148 -> V_148 ) {
case V_102 :
F_48 ( V_7 , 3 , L_3 , L_4 ) ;
V_7 -> V_12 . V_150 = 1 ;
V_89 = 0 ;
break;
case V_107 :
F_48 ( V_7 , 3 , L_3 , L_5 ) ;
V_7 -> V_12 . V_151 = 1 ;
V_89 = 0 ;
break;
case V_123 :
F_40 ( & V_7 -> V_152 ) ;
if ( V_7 -> V_153 ) {
V_89 = - V_154 ;
} else if ( V_124 ) {
F_49 ( V_7 -> V_12 . V_155 . V_156 , 129 ) ;
F_49 ( V_7 -> V_12 . V_155 . V_157 , 129 ) ;
if ( F_18 ( 134 ) ) {
F_49 ( V_7 -> V_12 . V_155 . V_156 , 134 ) ;
F_49 ( V_7 -> V_12 . V_155 . V_157 , 134 ) ;
}
if ( F_18 ( 135 ) ) {
F_49 ( V_7 -> V_12 . V_155 . V_156 , 135 ) ;
F_49 ( V_7 -> V_12 . V_155 . V_157 , 135 ) ;
}
V_89 = 0 ;
} else
V_89 = - V_87 ;
F_44 ( & V_7 -> V_152 ) ;
F_48 ( V_7 , 3 , L_6 ,
V_89 ? L_7 : L_8 ) ;
break;
case V_125 :
V_89 = - V_87 ;
F_40 ( & V_7 -> V_152 ) ;
if ( V_7 -> V_153 ) {
V_89 = - V_154 ;
} else if ( F_18 ( 64 ) ) {
F_49 ( V_7 -> V_12 . V_155 . V_156 , 64 ) ;
F_49 ( V_7 -> V_12 . V_155 . V_157 , 64 ) ;
V_89 = 0 ;
}
F_44 ( & V_7 -> V_152 ) ;
F_48 ( V_7 , 3 , L_9 ,
V_89 ? L_7 : L_8 ) ;
break;
case V_108 :
F_48 ( V_7 , 3 , L_3 , L_10 ) ;
V_7 -> V_12 . V_158 = 1 ;
V_89 = 0 ;
break;
case V_111 :
F_48 ( V_7 , 3 , L_3 , L_11 ) ;
V_7 -> V_12 . V_159 = 1 ;
F_45 ( V_7 ) ;
V_89 = 0 ;
break;
default:
V_89 = - V_87 ;
break;
}
return V_89 ;
}
static int F_50 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 ;
switch ( V_161 -> V_161 ) {
case V_163 :
V_162 = 0 ;
F_48 ( V_7 , 3 , L_12 ,
V_7 -> V_12 . V_164 ) ;
if ( F_51 ( V_7 -> V_12 . V_164 , ( V_165 V_166 * ) V_161 -> V_167 ) )
V_162 = - V_168 ;
break;
default:
V_162 = - V_169 ;
break;
}
return V_162 ;
}
static int F_52 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 ;
unsigned int V_170 ;
switch ( V_161 -> V_161 ) {
case V_171 :
V_162 = - V_169 ;
if ( ! V_58 . V_172 )
break;
V_162 = - V_154 ;
F_48 ( V_7 , 3 , L_3 , L_13 ) ;
F_40 ( & V_7 -> V_152 ) ;
if ( ! V_7 -> V_153 ) {
V_7 -> V_12 . V_173 = 1 ;
V_162 = 0 ;
}
F_44 ( & V_7 -> V_152 ) ;
break;
case V_174 :
V_162 = - V_169 ;
if ( ! V_58 . V_172 )
break;
V_162 = - V_87 ;
if ( ! V_7 -> V_12 . V_173 )
break;
F_48 ( V_7 , 3 , L_3 , L_14 ) ;
F_40 ( & V_7 -> V_152 ) ;
V_170 = F_53 ( & V_7 -> V_175 ) ;
F_54 ( V_7 -> V_12 . V_131 -> V_134 ) ;
F_55 ( & V_7 -> V_175 , V_170 ) ;
F_44 ( & V_7 -> V_152 ) ;
V_162 = 0 ;
break;
case V_163 : {
unsigned long V_176 ;
if ( F_39 ( V_7 ) )
return - V_87 ;
if ( F_56 ( V_176 , ( V_165 V_166 * ) V_161 -> V_167 ) )
return - V_168 ;
if ( V_7 -> V_12 . V_164 != V_177 &&
V_176 > V_7 -> V_12 . V_164 )
return - V_178 ;
if ( ! V_176 )
return - V_87 ;
if ( V_176 != V_177 )
V_176 -= 1 ;
V_162 = - V_154 ;
F_40 ( & V_7 -> V_152 ) ;
if ( ! V_7 -> V_153 ) {
struct V_131 * V_179 = F_57 ( V_135 -> V_134 , V_176 ) ;
if ( ! V_179 ) {
V_162 = - V_78 ;
} else {
F_58 ( V_7 -> V_12 . V_131 ) ;
V_179 -> V_180 = V_7 ;
V_7 -> V_12 . V_131 = V_179 ;
V_162 = 0 ;
}
}
F_44 ( & V_7 -> V_152 ) ;
F_48 ( V_7 , 3 , L_15 , V_176 ) ;
F_48 ( V_7 , 3 , L_16 ,
( void * ) V_7 -> V_12 . V_131 -> V_181 ) ;
break;
}
default:
V_162 = - V_169 ;
break;
}
return V_162 ;
}
static int F_59 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_60 ( V_7 , 76 ) )
return - V_87 ;
F_40 ( & V_7 -> V_152 ) ;
switch ( V_161 -> V_161 ) {
case V_182 :
F_61 (
V_7 -> V_12 . V_183 . V_184 -> V_185 ,
sizeof( V_7 -> V_12 . V_183 . V_184 -> V_185 ) ) ;
V_7 -> V_12 . V_183 . V_186 = 1 ;
F_48 ( V_7 , 3 , L_3 , L_17 ) ;
break;
case V_187 :
F_61 (
V_7 -> V_12 . V_183 . V_184 -> V_188 ,
sizeof( V_7 -> V_12 . V_183 . V_184 -> V_188 ) ) ;
V_7 -> V_12 . V_183 . V_189 = 1 ;
F_48 ( V_7 , 3 , L_3 , L_18 ) ;
break;
case V_190 :
V_7 -> V_12 . V_183 . V_186 = 0 ;
memset ( V_7 -> V_12 . V_183 . V_184 -> V_185 , 0 ,
sizeof( V_7 -> V_12 . V_183 . V_184 -> V_185 ) ) ;
F_48 ( V_7 , 3 , L_3 , L_19 ) ;
break;
case V_191 :
V_7 -> V_12 . V_183 . V_189 = 0 ;
memset ( V_7 -> V_12 . V_183 . V_184 -> V_188 , 0 ,
sizeof( V_7 -> V_12 . V_183 . V_184 -> V_188 ) ) ;
F_48 ( V_7 , 3 , L_3 , L_20 ) ;
break;
default:
F_44 ( & V_7 -> V_152 ) ;
return - V_169 ;
}
F_7 (i, vcpu, kvm) {
F_62 ( V_9 ) ;
F_63 ( V_9 ) ;
}
F_44 ( & V_7 -> V_152 ) ;
return 0 ;
}
static int F_64 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
T_3 V_192 ;
if ( F_65 ( & V_192 , ( void V_166 * ) V_161 -> V_167 ,
sizeof( V_192 ) ) )
return - V_168 ;
if ( V_192 != 0 )
return - V_87 ;
F_48 ( V_7 , 3 , L_21 , V_192 ) ;
return 0 ;
}
static int F_66 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
V_165 V_193 ;
if ( F_65 ( & V_193 , ( void V_166 * ) V_161 -> V_167 , sizeof( V_193 ) ) )
return - V_168 ;
F_67 ( V_7 , V_193 ) ;
F_48 ( V_7 , 3 , L_22 , V_193 ) ;
return 0 ;
}
static int F_68 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 ;
if ( V_161 -> V_149 )
return - V_87 ;
switch ( V_161 -> V_161 ) {
case V_194 :
V_162 = F_64 ( V_7 , V_161 ) ;
break;
case V_195 :
V_162 = F_66 ( V_7 , V_161 ) ;
break;
default:
V_162 = - V_169 ;
break;
}
return V_162 ;
}
static int F_69 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
T_3 V_192 = 0 ;
if ( F_70 ( ( void V_166 * ) V_161 -> V_167 , & V_192 ,
sizeof( V_192 ) ) )
return - V_168 ;
F_48 ( V_7 , 3 , L_23 , V_192 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
V_165 V_193 ;
V_193 = F_72 ( V_7 ) ;
if ( F_70 ( ( void V_166 * ) V_161 -> V_167 , & V_193 , sizeof( V_193 ) ) )
return - V_168 ;
F_48 ( V_7 , 3 , L_24 , V_193 ) ;
return 0 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 ;
if ( V_161 -> V_149 )
return - V_87 ;
switch ( V_161 -> V_161 ) {
case V_194 :
V_162 = F_69 ( V_7 , V_161 ) ;
break;
case V_195 :
V_162 = F_71 ( V_7 , V_161 ) ;
break;
default:
V_162 = - V_169 ;
break;
}
return V_162 ;
}
static int F_74 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
struct V_196 * V_197 ;
T_4 V_198 , V_199 ;
int V_162 = 0 ;
F_40 ( & V_7 -> V_152 ) ;
if ( V_7 -> V_153 ) {
V_162 = - V_154 ;
goto V_143;
}
V_197 = F_75 ( sizeof( * V_197 ) , V_200 ) ;
if ( ! V_197 ) {
V_162 = - V_78 ;
goto V_143;
}
if ( ! F_65 ( V_197 , ( void V_166 * ) V_161 -> V_167 ,
sizeof( * V_197 ) ) ) {
V_7 -> V_12 . V_155 . V_201 = V_197 -> V_201 ;
V_198 = V_58 . V_202 >> 16 & 0xfff ;
V_199 = V_58 . V_202 & 0xfff ;
if ( V_198 && V_197 -> V_202 ) {
if ( V_197 -> V_202 > V_199 )
V_7 -> V_12 . V_155 . V_202 = V_199 ;
else if ( V_197 -> V_202 < V_198 )
V_7 -> V_12 . V_155 . V_202 = V_198 ;
else
V_7 -> V_12 . V_155 . V_202 = V_197 -> V_202 ;
}
memcpy ( V_7 -> V_12 . V_155 . V_157 , V_197 -> V_157 ,
V_203 ) ;
F_48 ( V_7 , 3 , L_25 ,
V_7 -> V_12 . V_155 . V_202 ,
V_7 -> V_12 . V_155 . V_201 ) ;
F_48 ( V_7 , 3 , L_26 ,
V_7 -> V_12 . V_155 . V_157 [ 0 ] ,
V_7 -> V_12 . V_155 . V_157 [ 1 ] ,
V_7 -> V_12 . V_155 . V_157 [ 2 ] ) ;
} else
V_162 = - V_168 ;
F_76 ( V_197 ) ;
V_143:
F_44 ( & V_7 -> V_152 ) ;
return V_162 ;
}
static int F_77 ( struct V_7 * V_7 ,
struct V_160 * V_161 )
{
struct V_204 V_205 ;
int V_162 = - V_154 ;
if ( F_65 ( & V_205 , ( void V_166 * ) V_161 -> V_167 , sizeof( V_205 ) ) )
return - V_168 ;
if ( ! F_78 ( ( unsigned long * ) V_205 . V_206 ,
V_27 ,
V_207 ) )
return - V_87 ;
F_40 ( & V_7 -> V_152 ) ;
if ( ! F_79 ( & V_7 -> V_208 ) ) {
F_80 ( V_7 -> V_12 . V_209 , ( unsigned long * ) V_205 . V_206 ,
V_207 ) ;
V_162 = 0 ;
}
F_44 ( & V_7 -> V_152 ) ;
return V_162 ;
}
static int F_81 ( struct V_7 * V_7 ,
struct V_160 * V_161 )
{
return - V_169 ;
}
static int F_82 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 = - V_169 ;
switch ( V_161 -> V_161 ) {
case V_210 :
V_162 = F_74 ( V_7 , V_161 ) ;
break;
case V_211 :
V_162 = F_77 ( V_7 , V_161 ) ;
break;
case V_212 :
V_162 = F_81 ( V_7 , V_161 ) ;
break;
}
return V_162 ;
}
static int F_83 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
struct V_196 * V_197 ;
int V_162 = 0 ;
V_197 = F_75 ( sizeof( * V_197 ) , V_200 ) ;
if ( ! V_197 ) {
V_162 = - V_78 ;
goto V_143;
}
V_197 -> V_201 = V_7 -> V_12 . V_155 . V_201 ;
V_197 -> V_202 = V_7 -> V_12 . V_155 . V_202 ;
memcpy ( & V_197 -> V_157 , V_7 -> V_12 . V_155 . V_157 ,
V_203 ) ;
F_48 ( V_7 , 3 , L_27 ,
V_7 -> V_12 . V_155 . V_202 ,
V_7 -> V_12 . V_155 . V_201 ) ;
F_48 ( V_7 , 3 , L_28 ,
V_7 -> V_12 . V_155 . V_157 [ 0 ] ,
V_7 -> V_12 . V_155 . V_157 [ 1 ] ,
V_7 -> V_12 . V_155 . V_157 [ 2 ] ) ;
if ( F_70 ( ( void V_166 * ) V_161 -> V_167 , V_197 , sizeof( * V_197 ) ) )
V_162 = - V_168 ;
F_76 ( V_197 ) ;
V_143:
return V_162 ;
}
static int F_84 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
struct V_213 * V_214 ;
int V_162 = 0 ;
V_214 = F_75 ( sizeof( * V_214 ) , V_200 ) ;
if ( ! V_214 ) {
V_162 = - V_78 ;
goto V_143;
}
F_85 ( (struct V_201 * ) & V_214 -> V_201 ) ;
V_214 -> V_202 = V_58 . V_202 ;
memcpy ( & V_214 -> V_156 , V_7 -> V_12 . V_155 . V_156 ,
V_203 ) ;
memcpy ( ( unsigned long * ) & V_214 -> V_157 , V_215 . V_216 ,
sizeof( V_215 . V_216 ) ) ;
F_48 ( V_7 , 3 , L_29 ,
V_7 -> V_12 . V_155 . V_202 ,
V_7 -> V_12 . V_155 . V_201 ) ;
F_48 ( V_7 , 3 , L_30 ,
V_214 -> V_156 [ 0 ] ,
V_214 -> V_156 [ 1 ] ,
V_214 -> V_156 [ 2 ] ) ;
F_48 ( V_7 , 3 , L_31 ,
V_214 -> V_157 [ 0 ] ,
V_214 -> V_157 [ 1 ] ,
V_214 -> V_157 [ 2 ] ) ;
if ( F_70 ( ( void V_166 * ) V_161 -> V_167 , V_214 , sizeof( * V_214 ) ) )
V_162 = - V_168 ;
F_76 ( V_214 ) ;
V_143:
return V_162 ;
}
static int F_86 ( struct V_7 * V_7 ,
struct V_160 * V_161 )
{
struct V_204 V_205 ;
F_80 ( ( unsigned long * ) V_205 . V_206 , V_7 -> V_12 . V_209 ,
V_207 ) ;
if ( F_70 ( ( void V_166 * ) V_161 -> V_167 , & V_205 , sizeof( V_205 ) ) )
return - V_168 ;
return 0 ;
}
static int F_87 ( struct V_7 * V_7 ,
struct V_160 * V_161 )
{
struct V_204 V_205 ;
F_80 ( ( unsigned long * ) V_205 . V_206 ,
V_27 ,
V_207 ) ;
if ( F_70 ( ( void V_166 * ) V_161 -> V_167 , & V_205 , sizeof( V_205 ) ) )
return - V_168 ;
return 0 ;
}
static int F_88 ( struct V_7 * V_7 ,
struct V_160 * V_161 )
{
return - V_169 ;
}
static int F_89 ( struct V_7 * V_7 ,
struct V_160 * V_161 )
{
if ( F_70 ( ( void V_166 * ) V_161 -> V_167 , & V_30 ,
sizeof( struct V_217 ) ) )
return - V_168 ;
return 0 ;
}
static int F_90 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 = - V_169 ;
switch ( V_161 -> V_161 ) {
case V_210 :
V_162 = F_83 ( V_7 , V_161 ) ;
break;
case V_218 :
V_162 = F_84 ( V_7 , V_161 ) ;
break;
case V_211 :
V_162 = F_86 ( V_7 , V_161 ) ;
break;
case V_219 :
V_162 = F_87 ( V_7 , V_161 ) ;
break;
case V_212 :
V_162 = F_88 ( V_7 , V_161 ) ;
break;
case V_220 :
V_162 = F_89 ( V_7 , V_161 ) ;
break;
}
return V_162 ;
}
static int F_91 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 ;
switch ( V_161 -> V_221 ) {
case V_222 :
V_162 = F_52 ( V_7 , V_161 ) ;
break;
case V_223 :
V_162 = F_68 ( V_7 , V_161 ) ;
break;
case V_224 :
V_162 = F_82 ( V_7 , V_161 ) ;
break;
case V_225 :
V_162 = F_59 ( V_7 , V_161 ) ;
break;
default:
V_162 = - V_169 ;
break;
}
return V_162 ;
}
static int F_92 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 ;
switch ( V_161 -> V_221 ) {
case V_222 :
V_162 = F_50 ( V_7 , V_161 ) ;
break;
case V_223 :
V_162 = F_73 ( V_7 , V_161 ) ;
break;
case V_224 :
V_162 = F_90 ( V_7 , V_161 ) ;
break;
default:
V_162 = - V_169 ;
break;
}
return V_162 ;
}
static int F_93 ( struct V_7 * V_7 , struct V_160 * V_161 )
{
int V_162 ;
switch ( V_161 -> V_221 ) {
case V_222 :
switch ( V_161 -> V_161 ) {
case V_171 :
case V_174 :
V_162 = V_58 . V_172 ? 0 : - V_169 ;
break;
case V_163 :
V_162 = 0 ;
break;
default:
V_162 = - V_169 ;
break;
}
break;
case V_223 :
switch ( V_161 -> V_161 ) {
case V_195 :
case V_194 :
V_162 = 0 ;
break;
default:
V_162 = - V_169 ;
break;
}
break;
case V_224 :
switch ( V_161 -> V_161 ) {
case V_210 :
case V_218 :
case V_211 :
case V_219 :
case V_220 :
V_162 = 0 ;
break;
case V_212 :
default:
V_162 = - V_169 ;
break;
}
break;
case V_225 :
switch ( V_161 -> V_161 ) {
case V_182 :
case V_187 :
case V_190 :
case V_191 :
V_162 = 0 ;
break;
default:
V_162 = - V_169 ;
break;
}
break;
default:
V_162 = - V_169 ;
break;
}
return V_162 ;
}
static long F_94 ( struct V_7 * V_7 , struct V_226 * args )
{
T_5 * V_227 ;
T_6 V_228 ;
int V_10 , V_89 = 0 ;
if ( args -> V_149 != 0 )
return - V_87 ;
if ( ! F_95 ( V_135 -> V_134 ) )
return V_229 ;
if ( args -> V_230 < 1 || args -> V_230 > V_231 )
return - V_87 ;
V_227 = F_96 ( args -> V_230 , sizeof( T_5 ) ,
V_200 | V_232 ) ;
if ( ! V_227 )
V_227 = F_97 ( sizeof( T_5 ) * args -> V_230 ) ;
if ( ! V_227 )
return - V_78 ;
F_98 ( & V_135 -> V_134 -> V_233 ) ;
for ( V_10 = 0 ; V_10 < args -> V_230 ; V_10 ++ ) {
V_228 = F_99 ( V_7 , args -> V_234 + V_10 ) ;
if ( F_100 ( V_228 ) ) {
V_89 = - V_168 ;
break;
}
V_89 = F_101 ( V_135 -> V_134 , V_228 , & V_227 [ V_10 ] ) ;
if ( V_89 )
break;
}
F_102 ( & V_135 -> V_134 -> V_233 ) ;
if ( ! V_89 ) {
V_89 = F_70 ( ( T_5 V_166 * ) args -> V_235 , V_227 ,
sizeof( T_5 ) * args -> V_230 ) ;
if ( V_89 )
V_89 = - V_168 ;
}
F_103 ( V_227 ) ;
return V_89 ;
}
static long F_104 ( struct V_7 * V_7 , struct V_226 * args )
{
T_5 * V_227 ;
T_6 V_228 ;
int V_10 , V_89 = 0 ;
if ( args -> V_149 != 0 )
return - V_87 ;
if ( args -> V_230 < 1 || args -> V_230 > V_231 )
return - V_87 ;
V_227 = F_96 ( args -> V_230 , sizeof( T_5 ) ,
V_200 | V_232 ) ;
if ( ! V_227 )
V_227 = F_97 ( sizeof( T_5 ) * args -> V_230 ) ;
if ( ! V_227 )
return - V_78 ;
V_89 = F_65 ( V_227 , ( T_5 V_166 * ) args -> V_235 ,
sizeof( T_5 ) * args -> V_230 ) ;
if ( V_89 ) {
V_89 = - V_168 ;
goto V_143;
}
V_89 = F_105 () ;
if ( V_89 )
goto V_143;
F_98 ( & V_135 -> V_134 -> V_233 ) ;
for ( V_10 = 0 ; V_10 < args -> V_230 ; V_10 ++ ) {
V_228 = F_99 ( V_7 , args -> V_234 + V_10 ) ;
if ( F_100 ( V_228 ) ) {
V_89 = - V_168 ;
break;
}
if ( V_227 [ V_10 ] & 0x01 ) {
V_89 = - V_87 ;
break;
}
V_89 = F_106 ( V_135 -> V_134 , V_228 , V_227 [ V_10 ] , 0 ) ;
if ( V_89 )
break;
}
F_102 ( & V_135 -> V_134 -> V_233 ) ;
V_143:
F_103 ( V_227 ) ;
return V_89 ;
}
long F_107 ( struct V_82 * V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_7 * V_7 = V_83 -> V_236 ;
void V_166 * V_237 = ( void V_166 * ) V_85 ;
struct V_160 V_161 ;
int V_89 ;
switch ( V_84 ) {
case V_238 : {
struct V_239 V_240 ;
V_89 = - V_168 ;
if ( F_65 ( & V_240 , V_237 , sizeof( V_240 ) ) )
break;
V_89 = F_108 ( V_7 , & V_240 ) ;
break;
}
case V_241 : {
struct V_147 V_148 ;
V_89 = - V_168 ;
if ( F_65 ( & V_148 , V_237 , sizeof( V_148 ) ) )
break;
V_89 = F_47 ( V_7 , & V_148 ) ;
break;
}
case V_242 : {
struct V_243 V_244 ;
V_89 = - V_87 ;
if ( V_7 -> V_12 . V_150 ) {
memset ( & V_244 , 0 , sizeof( V_244 ) ) ;
V_89 = F_109 ( V_7 , & V_244 , 0 , 0 ) ;
}
break;
}
case V_245 : {
V_89 = - V_168 ;
if ( F_65 ( & V_161 , ( void V_166 * ) V_85 , sizeof( V_161 ) ) )
break;
V_89 = F_91 ( V_7 , & V_161 ) ;
break;
}
case V_246 : {
V_89 = - V_168 ;
if ( F_65 ( & V_161 , ( void V_166 * ) V_85 , sizeof( V_161 ) ) )
break;
V_89 = F_92 ( V_7 , & V_161 ) ;
break;
}
case V_247 : {
V_89 = - V_168 ;
if ( F_65 ( & V_161 , ( void V_166 * ) V_85 , sizeof( V_161 ) ) )
break;
V_89 = F_93 ( V_7 , & V_161 ) ;
break;
}
case V_248 : {
struct V_226 args ;
V_89 = - V_168 ;
if ( F_65 ( & args , V_237 ,
sizeof( struct V_226 ) ) )
break;
V_89 = F_94 ( V_7 , & args ) ;
break;
}
case V_249 : {
struct V_226 args ;
V_89 = - V_168 ;
if ( F_65 ( & args , V_237 ,
sizeof( struct V_226 ) ) )
break;
V_89 = F_104 ( V_7 , & args ) ;
break;
}
default:
V_89 = - V_250 ;
}
return V_89 ;
}
static int F_110 ( T_3 * V_251 )
{
T_7 V_252 = 0x04000000UL ;
T_7 V_29 = 0 ;
memset ( V_251 , 0 , 128 ) ;
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
static int F_111 ( void )
{
T_3 V_251 [ 128 ] ;
int V_29 ;
if ( F_18 ( 12 ) ) {
V_29 = F_110 ( V_251 ) ;
if ( V_29 )
F_112 ( L_32 , V_29 ) ;
else
return V_251 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_113 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_183 . V_253 = ( V_254 ) ( unsigned long ) V_7 -> V_12 . V_183 . V_184 ;
if ( F_111 () )
V_7 -> V_12 . V_183 . V_253 |= V_255 ;
else
V_7 -> V_12 . V_183 . V_253 |= V_256 ;
}
static V_165 F_114 ( void )
{
struct V_201 V_201 ;
F_85 ( & V_201 ) ;
V_201 . V_257 = 0xff ;
return * ( ( V_165 * ) & V_201 ) ;
}
static void F_115 ( struct V_7 * V_7 )
{
if ( ! F_60 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_183 . V_184 = & V_7 -> V_12 . V_258 -> V_184 ;
F_113 ( V_7 ) ;
V_7 -> V_12 . V_183 . V_186 = 1 ;
V_7 -> V_12 . V_183 . V_189 = 1 ;
F_61 ( V_7 -> V_12 . V_183 . V_184 -> V_185 ,
sizeof( V_7 -> V_12 . V_183 . V_184 -> V_185 ) ) ;
F_61 ( V_7 -> V_12 . V_183 . V_184 -> V_188 ,
sizeof( V_7 -> V_12 . V_183 . V_184 -> V_188 ) ) ;
}
static void F_116 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_259 )
F_117 ( V_7 -> V_12 . V_260 , sizeof( struct V_261 ) ) ;
else
F_118 ( ( unsigned long ) ( V_7 -> V_12 . V_260 ) ) ;
V_7 -> V_12 . V_260 = NULL ;
}
int F_119 ( struct V_7 * V_7 , unsigned long type )
{
T_8 V_262 = V_200 ;
int V_10 , V_263 ;
char V_264 [ 16 ] ;
static unsigned long V_265 ;
V_263 = - V_87 ;
#ifdef F_30
if ( type & ~ V_266 )
goto V_267;
if ( ( type & V_266 ) && ( ! F_120 ( V_268 ) ) )
goto V_267;
#else
if ( type )
goto V_267;
#endif
V_263 = F_28 () ;
if ( V_263 )
goto V_267;
V_263 = - V_78 ;
F_121 ( & V_7 -> V_12 . V_269 , 5 * V_270 , 500 ) ;
V_7 -> V_12 . V_259 = 0 ;
if ( ! V_58 . V_60 )
V_262 |= V_271 ;
F_122 ( & V_7 -> V_12 . V_272 ) ;
V_7 -> V_12 . V_260 = (struct V_273 * ) F_123 ( V_262 ) ;
if ( ! V_7 -> V_12 . V_260 )
goto V_267;
F_124 ( & V_274 ) ;
V_265 += 16 ;
if ( V_265 + sizeof( struct V_273 ) > V_275 )
V_265 = 0 ;
V_7 -> V_12 . V_260 = (struct V_273 * )
( ( char * ) V_7 -> V_12 . V_260 + V_265 ) ;
F_125 ( & V_274 ) ;
sprintf ( V_264 , L_33 , V_135 -> V_276 ) ;
V_7 -> V_12 . V_277 = F_22 ( V_264 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_277 )
goto V_267;
V_7 -> V_12 . V_258 =
(struct V_258 * ) F_123 ( V_200 | V_271 ) ;
if ( ! V_7 -> V_12 . V_258 )
goto V_267;
memcpy ( V_7 -> V_12 . V_155 . V_156 , V_215 . V_216 ,
sizeof( V_215 . V_216 ) ) ;
for ( V_10 = 0 ; V_10 < V_278 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_155 . V_156 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_155 . V_156 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_155 . V_157 = V_7 -> V_12 . V_258 -> V_157 ;
memcpy ( V_7 -> V_12 . V_155 . V_157 , V_7 -> V_12 . V_155 . V_156 ,
V_203 ) ;
F_49 ( V_7 -> V_12 . V_155 . V_156 , 74 ) ;
F_49 ( V_7 -> V_12 . V_155 . V_157 , 74 ) ;
V_7 -> V_12 . V_155 . V_201 = F_114 () ;
V_7 -> V_12 . V_155 . V_202 = V_58 . V_202 & 0x0fff ;
F_115 ( V_7 ) ;
F_126 ( & V_7 -> V_12 . V_279 . V_152 ) ;
for ( V_10 = 0 ; V_10 < V_280 ; V_10 ++ )
F_127 ( & V_7 -> V_12 . V_279 . V_281 [ V_10 ] ) ;
F_128 ( & V_7 -> V_12 . V_282 ) ;
F_129 ( & V_7 -> V_12 . V_283 ) ;
F_23 ( V_7 -> V_12 . V_277 , & V_79 ) ;
F_48 ( V_7 , 3 , L_34 , type ) ;
if ( type & V_266 ) {
V_7 -> V_12 . V_131 = NULL ;
V_7 -> V_12 . V_164 = V_177 ;
} else {
if ( V_58 . V_284 == V_285 )
V_7 -> V_12 . V_164 = V_286 ;
else
V_7 -> V_12 . V_164 = F_130 (unsigned long, TASK_MAX_SIZE,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_131 = F_57 ( V_135 -> V_134 , V_7 -> V_12 . V_164 - 1 ) ;
if ( ! V_7 -> V_12 . V_131 )
goto V_267;
V_7 -> V_12 . V_131 -> V_180 = V_7 ;
V_7 -> V_12 . V_131 -> V_287 = 0 ;
}
V_7 -> V_12 . V_288 = 0 ;
V_7 -> V_12 . V_150 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_126 ( & V_7 -> V_12 . V_289 ) ;
F_131 ( V_7 ) ;
F_132 ( 3 , L_35 , V_7 , V_135 -> V_276 ) ;
return 0 ;
V_267:
F_118 ( ( unsigned long ) V_7 -> V_12 . V_258 ) ;
F_24 ( V_7 -> V_12 . V_277 ) ;
F_116 ( V_7 ) ;
F_132 ( 3 , L_36 , V_263 ) ;
return V_263 ;
}
bool F_133 ( void )
{
return false ;
}
int F_134 ( struct V_8 * V_9 )
{
return 0 ;
}
void F_135 ( struct V_8 * V_9 )
{
F_136 ( V_9 , 3 , L_3 , L_37 ) ;
F_137 ( V_9 -> V_290 ) ;
F_138 ( V_9 ) ;
F_139 ( V_9 ) ;
if ( ! F_39 ( V_9 -> V_7 ) )
F_140 ( V_9 ) ;
if ( F_39 ( V_9 -> V_7 ) )
F_58 ( V_9 -> V_12 . V_131 ) ;
if ( V_9 -> V_7 -> V_12 . V_173 )
F_141 ( V_9 ) ;
F_118 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_142 ( V_9 ) ;
F_143 ( V_291 , V_9 ) ;
}
static void F_144 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_135 ( V_9 ) ;
F_40 ( & V_7 -> V_152 ) ;
for ( V_10 = 0 ; V_10 < F_79 ( & V_7 -> V_208 ) ; V_10 ++ )
V_7 -> V_292 [ V_10 ] = NULL ;
F_145 ( & V_7 -> V_208 , 0 ) ;
F_44 ( & V_7 -> V_152 ) ;
}
void F_146 ( struct V_7 * V_7 )
{
F_144 ( V_7 ) ;
F_116 ( V_7 ) ;
F_24 ( V_7 -> V_12 . V_277 ) ;
F_118 ( ( unsigned long ) V_7 -> V_12 . V_258 ) ;
if ( ! F_39 ( V_7 ) )
F_58 ( V_7 -> V_12 . V_131 ) ;
F_147 ( V_7 ) ;
F_148 ( V_7 ) ;
F_149 ( V_7 ) ;
F_132 ( 3 , L_38 , V_7 ) ;
}
static int F_150 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_131 = F_57 ( V_135 -> V_134 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_131 )
return - V_78 ;
V_9 -> V_12 . V_131 -> V_180 = V_9 -> V_7 ;
return 0 ;
}
static void F_140 ( struct V_8 * V_9 )
{
if ( ! F_31 () )
return;
F_151 ( & V_9 -> V_7 -> V_12 . V_272 ) ;
if ( V_9 -> V_7 -> V_12 . V_259 ) {
struct V_261 * V_260 = V_9 -> V_7 -> V_12 . V_260 ;
F_152 ( V_9 -> V_290 , ( unsigned long * ) V_260 -> V_293 ) ;
V_260 -> V_294 [ V_9 -> V_290 ] . V_295 = 0 ;
} else {
struct V_273 * V_260 = V_9 -> V_7 -> V_12 . V_260 ;
F_152 ( V_9 -> V_290 , ( unsigned long * ) & V_260 -> V_293 ) ;
V_260 -> V_294 [ V_9 -> V_290 ] . V_295 = 0 ;
}
F_153 ( & V_9 -> V_7 -> V_12 . V_272 ) ;
}
static void F_154 ( struct V_8 * V_9 )
{
if ( ! F_31 () ) {
struct V_273 * V_260 = V_9 -> V_7 -> V_12 . V_260 ;
V_9 -> V_12 . V_14 -> V_296 = ( V_254 ) ( ( ( V_297 ) V_260 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_298 = ( V_254 ) ( V_297 ) V_260 ;
}
F_151 ( & V_9 -> V_7 -> V_12 . V_272 ) ;
if ( V_9 -> V_7 -> V_12 . V_259 ) {
struct V_261 * V_260 = V_9 -> V_7 -> V_12 . V_260 ;
V_260 -> V_294 [ V_9 -> V_290 ] . V_295 = ( V_297 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_296 = ( V_254 ) ( ( ( V_297 ) V_260 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_298 = ( V_254 ) ( V_297 ) V_260 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_299 |= 0x04U ;
F_15 ( V_9 -> V_290 , ( unsigned long * ) V_260 -> V_293 ) ;
} else {
struct V_273 * V_260 = V_9 -> V_7 -> V_12 . V_260 ;
V_260 -> V_294 [ V_9 -> V_290 ] . V_295 = ( V_297 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_296 = ( V_254 ) ( ( ( V_297 ) V_260 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_298 = ( V_254 ) ( V_297 ) V_260 ;
F_15 ( V_9 -> V_290 , ( unsigned long * ) & V_260 -> V_293 ) ;
}
F_153 ( & V_9 -> V_7 -> V_12 . V_272 ) ;
}
static inline void F_155 ( struct V_300 * V_301 , struct V_302 * V_303 )
{
V_301 -> V_295 = V_303 -> V_295 ;
V_301 -> V_304 . V_305 = V_303 -> V_304 . V_305 ;
V_301 -> V_304 . V_306 = V_303 -> V_304 . V_306 ;
}
static void F_156 ( struct V_261 * V_301 , struct V_273 * V_303 )
{
int V_10 ;
V_301 -> V_307 = V_303 -> V_307 ;
V_301 -> V_293 [ 0 ] = V_303 -> V_293 ;
for ( V_10 = 0 ; V_10 < V_116 ; V_10 ++ )
F_155 ( & V_301 -> V_294 [ V_10 ] , & V_303 -> V_294 [ V_10 ] ) ;
}
static int F_157 ( struct V_7 * V_7 )
{
struct V_273 * V_308 = V_7 -> V_12 . V_260 ;
struct V_261 * V_309 ;
struct V_8 * V_9 ;
unsigned int V_310 ;
T_7 V_298 , V_296 ;
V_309 = F_158 ( sizeof( * V_309 ) , V_200 | V_311 ) ;
if ( ! V_309 )
return - V_78 ;
V_296 = ( T_7 ) ( ( V_165 ) ( V_309 ) >> 32 ) ;
V_298 = ( T_7 ) ( V_165 ) ( V_309 ) & ~ 0x3fU ;
F_159 ( V_7 ) ;
F_160 ( & V_7 -> V_12 . V_272 ) ;
F_156 ( V_309 , V_308 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_296 = V_296 ;
V_9 -> V_12 . V_14 -> V_298 = V_298 ;
V_9 -> V_12 . V_14 -> V_299 |= 0x04U ;
}
V_7 -> V_12 . V_260 = V_309 ;
V_7 -> V_12 . V_259 = 1 ;
F_161 ( & V_7 -> V_12 . V_272 ) ;
F_162 ( V_7 ) ;
F_118 ( ( unsigned long ) V_308 ) ;
F_48 ( V_7 , 2 , L_39 ,
V_308 , V_7 -> V_12 . V_260 ) ;
return 0 ;
}
static int F_163 ( struct V_7 * V_7 , unsigned int V_312 )
{
int V_263 ;
if ( ! F_31 () ) {
if ( V_312 < V_117 )
return true ;
return false ;
}
if ( V_312 < V_116 )
return true ;
if ( ! V_58 . V_118 || ! V_58 . V_60 )
return false ;
F_40 ( & V_7 -> V_152 ) ;
V_263 = V_7 -> V_12 . V_259 ? 0 : F_157 ( V_7 ) ;
F_44 ( & V_7 -> V_152 ) ;
return V_263 == 0 && V_312 < V_119 ;
}
int F_164 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_313 = V_314 ;
F_139 ( V_9 ) ;
V_9 -> V_315 -> V_316 = V_317 |
V_318 |
V_319 |
V_320 |
V_321 |
V_322 ;
F_165 ( V_9 , 0 ) ;
if ( F_60 ( V_9 -> V_7 , 64 ) )
V_9 -> V_315 -> V_316 |= V_323 ;
if ( V_124 )
V_9 -> V_315 -> V_316 |= V_324 ;
else
V_9 -> V_315 -> V_316 |= V_325 ;
if ( F_39 ( V_9 -> V_7 ) )
return F_150 ( V_9 ) ;
return 0 ;
}
static void F_166 ( struct V_8 * V_9 )
{
F_167 ( V_9 -> V_12 . V_16 != 0 ) ;
F_168 ( & V_9 -> V_12 . V_326 ) ;
V_9 -> V_12 . V_16 = F_169 () ;
F_170 ( & V_9 -> V_12 . V_326 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_167 ( V_9 -> V_12 . V_16 == 0 ) ;
F_168 ( & V_9 -> V_12 . V_326 ) ;
V_9 -> V_12 . V_14 -> V_327 -= F_169 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_170 ( & V_9 -> V_12 . V_326 ) ;
}
static void F_172 ( struct V_8 * V_9 )
{
F_167 ( V_9 -> V_12 . V_15 ) ;
V_9 -> V_12 . V_15 = true ;
F_166 ( V_9 ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
F_167 ( ! V_9 -> V_12 . V_15 ) ;
F_171 ( V_9 ) ;
V_9 -> V_12 . V_15 = false ;
}
static void F_174 ( struct V_8 * V_9 )
{
F_175 () ;
F_172 ( V_9 ) ;
F_176 () ;
}
static void F_177 ( struct V_8 * V_9 )
{
F_175 () ;
F_173 ( V_9 ) ;
F_176 () ;
}
void F_178 ( struct V_8 * V_9 , V_297 V_327 )
{
F_175 () ;
F_168 ( & V_9 -> V_12 . V_326 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_169 () ;
V_9 -> V_12 . V_14 -> V_327 = V_327 ;
F_170 ( & V_9 -> V_12 . V_326 ) ;
F_176 () ;
}
V_297 F_179 ( struct V_8 * V_9 )
{
unsigned int V_328 ;
V_297 V_329 ;
if ( F_180 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_327 ;
F_175 () ;
do {
V_328 = F_181 ( & V_9 -> V_12 . V_326 ) ;
F_167 ( ( V_328 & 1 ) && F_182 () == V_9 -> V_294 ) ;
V_329 = V_9 -> V_12 . V_14 -> V_327 ;
if ( F_183 ( V_9 -> V_12 . V_16 ) )
V_329 -= F_169 () - V_9 -> V_12 . V_16 ;
} while ( F_184 ( & V_9 -> V_12 . V_326 , V_328 & ~ 1 ) );
F_176 () ;
return V_329 ;
}
void F_185 ( struct V_8 * V_9 , int V_294 )
{
F_186 ( V_9 -> V_12 . V_330 ) ;
F_187 ( V_331 , & V_9 -> V_12 . V_14 -> V_332 ) ;
if ( V_9 -> V_12 . V_15 && ! F_188 ( V_9 ) )
F_166 ( V_9 ) ;
V_9 -> V_294 = V_294 ;
}
void F_189 ( struct V_8 * V_9 )
{
V_9 -> V_294 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_188 ( V_9 ) )
F_171 ( V_9 ) ;
F_190 ( V_331 , & V_9 -> V_12 . V_14 -> V_332 ) ;
V_9 -> V_12 . V_330 = F_191 () ;
F_192 ( V_9 -> V_12 . V_330 ) ;
}
static void F_193 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_333 . V_334 = 0UL ;
V_9 -> V_12 . V_14 -> V_333 . V_167 = 0UL ;
F_165 ( V_9 , 0 ) ;
F_178 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_335 = 0UL ;
V_9 -> V_12 . V_14 -> V_336 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_337 , 0 , 16 * sizeof( V_297 ) ) ;
V_9 -> V_12 . V_14 -> V_337 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_337 [ 14 ] = 0xC2000000UL ;
F_194 () ;
V_135 -> V_338 . V_339 . V_340 = 0 ;
V_9 -> V_12 . V_14 -> V_341 = 1 ;
V_9 -> V_12 . V_14 -> V_342 = 0 ;
V_9 -> V_12 . V_313 = V_314 ;
F_139 ( V_9 ) ;
if ( ! F_195 ( V_9 -> V_7 ) )
F_196 ( V_9 ) ;
F_138 ( V_9 ) ;
}
void F_197 ( struct V_8 * V_9 )
{
F_40 ( & V_9 -> V_7 -> V_152 ) ;
F_175 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_176 () ;
F_44 ( & V_9 -> V_7 -> V_152 ) ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_131 = V_9 -> V_7 -> V_12 . V_131 ;
F_154 ( V_9 ) ;
}
if ( F_60 ( V_9 -> V_7 , 74 ) || V_9 -> V_7 -> V_12 . V_159 )
V_9 -> V_12 . V_14 -> V_343 |= V_344 ;
V_9 -> V_12 . V_330 = V_9 -> V_12 . V_131 ;
}
static void F_62 ( struct V_8 * V_9 )
{
if ( ! F_60 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_345 &= ~ ( V_346 | V_347 ) ;
if ( V_9 -> V_7 -> V_12 . V_183 . V_186 )
V_9 -> V_12 . V_14 -> V_345 |= V_346 ;
if ( V_9 -> V_7 -> V_12 . V_183 . V_189 )
V_9 -> V_12 . V_14 -> V_345 |= V_347 ;
V_9 -> V_12 . V_14 -> V_253 = V_9 -> V_7 -> V_12 . V_183 . V_253 ;
}
void F_141 ( struct V_8 * V_9 )
{
F_118 ( V_9 -> V_12 . V_14 -> V_348 ) ;
V_9 -> V_12 . V_14 -> V_348 = 0 ;
}
int F_198 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_348 = F_123 ( V_200 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_348 )
return - V_78 ;
V_9 -> V_12 . V_14 -> V_299 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_299 &= ~ 0x08 ;
return 0 ;
}
static void F_199 ( struct V_8 * V_9 )
{
struct V_349 * V_155 = & V_9 -> V_7 -> V_12 . V_155 ;
V_9 -> V_12 . V_14 -> V_202 = V_155 -> V_202 ;
if ( F_60 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_350 = ( T_7 ) ( V_165 ) V_155 -> V_157 ;
}
int F_200 ( struct V_8 * V_9 )
{
int V_263 = 0 ;
F_145 ( & V_9 -> V_12 . V_14 -> V_332 , V_351 |
V_352 |
V_353 ) ;
if ( F_60 ( V_9 -> V_7 , 78 ) )
F_187 ( V_354 , & V_9 -> V_12 . V_14 -> V_332 ) ;
else if ( F_60 ( V_9 -> V_7 , 8 ) )
F_187 ( V_355 , & V_9 -> V_12 . V_14 -> V_332 ) ;
F_199 ( V_9 ) ;
if ( V_56 )
V_9 -> V_12 . V_14 -> V_356 |= 0x02 ;
if ( F_60 ( V_9 -> V_7 , 9 ) )
V_9 -> V_12 . V_14 -> V_356 |= 0x04 ;
if ( F_60 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_356 |= 0x10 ;
if ( F_60 ( V_9 -> V_7 , 8 ) && V_58 . V_357 )
V_9 -> V_12 . V_14 -> V_299 |= 0x08 ;
if ( F_60 ( V_9 -> V_7 , 130 ) )
V_9 -> V_12 . V_14 -> V_299 |= 0x20 ;
V_9 -> V_12 . V_14 -> V_358 = 0x1002000U ;
if ( V_58 . V_72 )
V_9 -> V_12 . V_14 -> V_358 |= 0x80000000U ;
if ( V_58 . V_70 )
V_9 -> V_12 . V_14 -> V_358 |= 0x40000000U ;
if ( V_58 . V_64 )
V_9 -> V_12 . V_14 -> V_358 |= 1 ;
if ( V_58 . V_359 )
V_9 -> V_12 . V_14 -> V_358 |= 0x10000000U ;
if ( F_60 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_358 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_360 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_361 = ( unsigned long ) & V_9 -> V_315 -> V_303 . V_362 . V_363 ;
V_9 -> V_12 . V_14 -> V_343 |= V_364 | V_365 | V_366 ;
if ( V_9 -> V_7 -> V_12 . V_173 ) {
V_263 = F_198 ( V_9 ) ;
if ( V_263 )
return V_263 ;
}
F_201 ( & V_9 -> V_12 . V_367 , V_368 , V_369 ) ;
V_9 -> V_12 . V_367 . V_370 = V_371 ;
F_62 ( V_9 ) ;
return V_263 ;
}
struct V_8 * F_202 ( struct V_7 * V_7 ,
unsigned int V_312 )
{
struct V_8 * V_9 ;
struct V_372 * V_372 ;
int V_263 = - V_87 ;
if ( ! F_39 ( V_7 ) && ! F_163 ( V_7 , V_312 ) )
goto V_143;
V_263 = - V_78 ;
V_9 = F_203 ( V_291 , V_200 ) ;
if ( ! V_9 )
goto V_143;
V_372 = (struct V_372 * ) F_123 ( V_200 ) ;
if ( ! V_372 )
goto V_373;
V_9 -> V_12 . V_14 = & V_372 -> V_14 ;
V_9 -> V_12 . V_14 -> V_374 = ( unsigned long ) & V_372 -> V_375 ;
V_9 -> V_12 . V_14 -> V_376 = 0 ;
V_9 -> V_12 . V_14 -> V_377 = V_58 . V_284 ;
V_9 -> V_12 . V_14 -> V_378 = V_312 ;
F_126 ( & V_9 -> V_12 . V_379 . V_152 ) ;
V_9 -> V_12 . V_379 . V_279 = & V_7 -> V_12 . V_279 ;
V_9 -> V_12 . V_379 . V_380 = & V_9 -> V_380 ;
V_9 -> V_12 . V_379 . V_332 = & V_9 -> V_12 . V_14 -> V_332 ;
F_204 ( & V_9 -> V_12 . V_326 ) ;
V_263 = F_205 ( V_9 , V_7 , V_312 ) ;
if ( V_263 )
goto V_381;
F_48 ( V_7 , 3 , L_40 , V_312 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_206 ( V_312 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_381:
F_118 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_373:
F_143 ( V_291 , V_9 ) ;
V_143:
return F_207 ( V_263 ) ;
}
int F_208 ( struct V_8 * V_9 )
{
return F_209 ( V_9 , 0 ) ;
}
void F_210 ( struct V_8 * V_9 )
{
F_187 ( V_382 , & V_9 -> V_12 . V_14 -> V_383 ) ;
F_63 ( V_9 ) ;
}
void F_211 ( struct V_8 * V_9 )
{
F_190 ( V_382 , & V_9 -> V_12 . V_14 -> V_383 ) ;
}
static void F_212 ( struct V_8 * V_9 )
{
F_187 ( V_384 , & V_9 -> V_12 . V_14 -> V_383 ) ;
F_63 ( V_9 ) ;
}
static void F_213 ( struct V_8 * V_9 )
{
F_190 ( V_384 , & V_9 -> V_12 . V_14 -> V_383 ) ;
}
void F_63 ( struct V_8 * V_9 )
{
F_187 ( V_385 , & V_9 -> V_12 . V_14 -> V_332 ) ;
while ( V_9 -> V_12 . V_14 -> V_386 & V_387 )
F_214 () ;
}
void F_46 ( int V_388 , struct V_8 * V_9 )
{
F_215 ( V_388 , V_9 ) ;
F_212 ( V_9 ) ;
}
static void V_21 ( struct V_131 * V_131 , unsigned long V_389 ,
unsigned long V_390 )
{
struct V_7 * V_7 = V_131 -> V_180 ;
struct V_8 * V_9 ;
unsigned long V_391 ;
int V_10 ;
if ( F_216 ( V_131 ) )
return;
if ( V_389 >= 1UL << 31 )
return;
F_7 (i, vcpu, kvm) {
V_391 = F_217 ( V_9 ) ;
if ( V_391 <= V_390 && V_389 <= V_391 + 2 * V_275 - 1 ) {
F_136 ( V_9 , 2 , L_41 ,
V_389 , V_390 ) ;
F_46 ( V_392 , V_9 ) ;
}
}
}
int F_218 ( struct V_8 * V_9 )
{
F_219 () ;
return 0 ;
}
static int F_220 ( struct V_8 * V_9 ,
struct V_393 * V_394 )
{
int V_89 = - V_87 ;
switch ( V_394 -> V_312 ) {
case V_395 :
V_89 = F_51 ( V_9 -> V_12 . V_14 -> V_336 ,
( T_7 V_166 * ) V_394 -> V_167 ) ;
break;
case V_396 :
V_89 = F_51 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_397 :
V_89 = F_51 ( F_179 ( V_9 ) ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_398 :
V_89 = F_51 ( V_9 -> V_12 . V_14 -> V_335 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_399 :
V_89 = F_51 ( V_9 -> V_12 . V_313 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_400 :
V_89 = F_51 ( V_9 -> V_12 . V_401 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_402 :
V_89 = F_51 ( V_9 -> V_12 . V_403 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_404 :
V_89 = F_51 ( V_9 -> V_12 . V_14 -> V_342 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_405 :
V_89 = F_51 ( V_9 -> V_12 . V_14 -> V_341 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
default:
break;
}
return V_89 ;
}
static int F_221 ( struct V_8 * V_9 ,
struct V_393 * V_394 )
{
int V_89 = - V_87 ;
V_297 V_5 ;
switch ( V_394 -> V_312 ) {
case V_395 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_336 ,
( T_7 V_166 * ) V_394 -> V_167 ) ;
break;
case V_396 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_397 :
V_89 = F_56 ( V_5 , ( V_165 V_166 * ) V_394 -> V_167 ) ;
if ( ! V_89 )
F_178 ( V_9 , V_5 ) ;
break;
case V_398 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_335 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_399 :
V_89 = F_56 ( V_9 -> V_12 . V_313 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
if ( V_9 -> V_12 . V_313 == V_314 )
F_139 ( V_9 ) ;
break;
case V_400 :
V_89 = F_56 ( V_9 -> V_12 . V_401 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_402 :
V_89 = F_56 ( V_9 -> V_12 . V_403 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_404 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_342 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
case V_405 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_341 ,
( V_165 V_166 * ) V_394 -> V_167 ) ;
break;
default:
break;
}
return V_89 ;
}
static int F_222 ( struct V_8 * V_9 )
{
F_193 ( V_9 ) ;
return 0 ;
}
int F_223 ( struct V_8 * V_9 , struct V_406 * V_362 )
{
memcpy ( & V_9 -> V_315 -> V_303 . V_362 . V_407 , & V_362 -> V_407 , sizeof( V_362 -> V_407 ) ) ;
return 0 ;
}
int F_224 ( struct V_8 * V_9 , struct V_406 * V_362 )
{
memcpy ( & V_362 -> V_407 , & V_9 -> V_315 -> V_303 . V_362 . V_407 , sizeof( V_362 -> V_407 ) ) ;
return 0 ;
}
int F_225 ( struct V_8 * V_9 ,
struct V_408 * V_409 )
{
memcpy ( & V_9 -> V_315 -> V_303 . V_362 . V_410 , & V_409 -> V_410 , sizeof( V_409 -> V_410 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_337 , & V_409 -> V_411 , sizeof( V_409 -> V_411 ) ) ;
return 0 ;
}
int F_226 ( struct V_8 * V_9 ,
struct V_408 * V_409 )
{
memcpy ( & V_409 -> V_410 , & V_9 -> V_315 -> V_303 . V_362 . V_410 , sizeof( V_409 -> V_410 ) ) ;
memcpy ( & V_409 -> V_411 , & V_9 -> V_12 . V_14 -> V_337 , sizeof( V_409 -> V_411 ) ) ;
return 0 ;
}
int F_227 ( struct V_8 * V_9 , struct V_412 * V_339 )
{
if ( F_228 ( V_339 -> V_340 ) )
return - V_87 ;
V_9 -> V_315 -> V_303 . V_362 . V_340 = V_339 -> V_340 ;
if ( V_124 )
F_229 ( ( V_413 * ) V_9 -> V_315 -> V_303 . V_362 . V_414 ,
( V_415 * ) V_339 -> V_416 ) ;
else
memcpy ( V_9 -> V_315 -> V_303 . V_362 . V_416 , & V_339 -> V_416 , sizeof( V_339 -> V_416 ) ) ;
return 0 ;
}
int F_230 ( struct V_8 * V_9 , struct V_412 * V_339 )
{
F_194 () ;
if ( V_124 )
F_231 ( ( V_415 * ) V_339 -> V_416 ,
( V_413 * ) V_9 -> V_315 -> V_303 . V_362 . V_414 ) ;
else
memcpy ( V_339 -> V_416 , V_9 -> V_315 -> V_303 . V_362 . V_416 , sizeof( V_339 -> V_416 ) ) ;
V_339 -> V_340 = V_9 -> V_315 -> V_303 . V_362 . V_340 ;
return 0 ;
}
static int F_232 ( struct V_8 * V_9 , T_9 V_417 )
{
int V_263 = 0 ;
if ( ! F_233 ( V_9 ) )
V_263 = - V_154 ;
else {
V_9 -> V_315 -> V_418 = V_417 . V_334 ;
V_9 -> V_315 -> V_419 = V_417 . V_167 ;
}
return V_263 ;
}
int F_234 ( struct V_8 * V_9 ,
struct V_420 * V_421 )
{
return - V_87 ;
}
int F_235 ( struct V_8 * V_9 ,
struct V_422 * V_423 )
{
int V_263 = 0 ;
V_9 -> V_424 = 0 ;
F_236 ( V_9 ) ;
if ( V_423 -> V_425 & ~ V_426 )
return - V_87 ;
if ( ! V_58 . V_66 )
return - V_87 ;
if ( V_423 -> V_425 & V_427 ) {
V_9 -> V_424 = V_423 -> V_425 ;
F_187 ( V_428 , & V_9 -> V_12 . V_14 -> V_332 ) ;
if ( V_423 -> V_425 & V_429 )
V_263 = F_237 ( V_9 , V_423 ) ;
} else {
F_190 ( V_428 , & V_9 -> V_12 . V_14 -> V_332 ) ;
V_9 -> V_12 . V_430 . V_431 = 0 ;
}
if ( V_263 ) {
V_9 -> V_424 = 0 ;
F_236 ( V_9 ) ;
F_190 ( V_428 , & V_9 -> V_12 . V_14 -> V_332 ) ;
}
return V_263 ;
}
int F_238 ( struct V_8 * V_9 ,
struct V_432 * V_433 )
{
return F_233 ( V_9 ) ? V_434 :
V_435 ;
}
int F_239 ( struct V_8 * V_9 ,
struct V_432 * V_433 )
{
int V_263 = 0 ;
V_9 -> V_7 -> V_12 . V_436 = 1 ;
switch ( V_433 -> V_433 ) {
case V_434 :
F_196 ( V_9 ) ;
break;
case V_435 :
F_240 ( V_9 ) ;
break;
case V_437 :
case V_438 :
default:
V_263 = - V_169 ;
}
return V_263 ;
}
static bool F_241 ( struct V_8 * V_9 )
{
return F_79 ( & V_9 -> V_12 . V_14 -> V_332 ) & V_439 ;
}
static int F_242 ( struct V_8 * V_9 )
{
V_440:
F_213 ( V_9 ) ;
if ( ! V_9 -> V_441 )
return 0 ;
if ( F_243 ( V_392 , V_9 ) ) {
int V_263 ;
V_263 = F_244 ( V_9 -> V_12 . V_131 ,
F_217 ( V_9 ) ,
V_275 * 2 , V_442 ) ;
if ( V_263 ) {
F_215 ( V_392 , V_9 ) ;
return V_263 ;
}
goto V_440;
}
if ( F_243 ( V_443 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_444 = 0xffff ;
goto V_440;
}
if ( F_243 ( V_445 , V_9 ) ) {
if ( ! F_241 ( V_9 ) ) {
F_245 ( V_9 -> V_290 , 1 ) ;
F_187 ( V_439 ,
& V_9 -> V_12 . V_14 -> V_332 ) ;
}
goto V_440;
}
if ( F_243 ( V_446 , V_9 ) ) {
if ( F_241 ( V_9 ) ) {
F_245 ( V_9 -> V_290 , 0 ) ;
F_190 ( V_439 ,
& V_9 -> V_12 . V_14 -> V_332 ) ;
}
goto V_440;
}
if ( F_243 ( V_146 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_343 |= V_344 ;
goto V_440;
}
F_246 ( V_447 , & V_9 -> V_441 ) ;
return 0 ;
}
void F_67 ( struct V_7 * V_7 , V_165 V_448 )
{
struct V_8 * V_9 ;
int V_10 ;
F_40 ( & V_7 -> V_152 ) ;
F_175 () ;
V_7 -> V_12 . V_13 = V_448 - F_247 () ;
F_159 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_162 ( V_7 ) ;
F_176 () ;
F_44 ( & V_7 -> V_152 ) ;
}
long F_248 ( struct V_8 * V_9 , T_10 V_449 , int V_450 )
{
return F_249 ( V_9 -> V_12 . V_131 , V_449 ,
V_450 ? V_451 : 0 ) ;
}
static void F_250 ( struct V_8 * V_9 , bool V_452 ,
unsigned long V_453 )
{
struct V_239 V_454 ;
struct V_455 V_456 ;
if ( V_452 ) {
V_456 . V_457 . V_88 . V_458 = V_453 ;
V_456 . type = V_459 ;
F_167 ( F_251 ( V_9 , & V_456 ) ) ;
} else {
V_454 . type = V_460 ;
V_454 . V_461 = V_453 ;
F_167 ( F_108 ( V_9 -> V_7 , & V_454 ) ) ;
}
}
void F_252 ( struct V_8 * V_9 ,
struct V_462 * V_463 )
{
F_253 ( V_9 , V_463 -> V_12 . V_313 ) ;
F_250 ( V_9 , true , V_463 -> V_12 . V_313 ) ;
}
void F_254 ( struct V_8 * V_9 ,
struct V_462 * V_463 )
{
F_255 ( V_9 , V_463 -> V_12 . V_313 ) ;
F_250 ( V_9 , false , V_463 -> V_12 . V_313 ) ;
}
void F_256 ( struct V_8 * V_9 ,
struct V_462 * V_463 )
{
}
bool F_257 ( struct V_8 * V_9 )
{
return true ;
}
static int F_258 ( struct V_8 * V_9 )
{
T_11 V_228 ;
struct V_464 V_12 ;
int V_263 ;
if ( V_9 -> V_12 . V_313 == V_314 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_333 . V_334 & V_9 -> V_12 . V_403 ) !=
V_9 -> V_12 . V_401 )
return 0 ;
if ( F_259 ( V_9 ) )
return 0 ;
if ( F_209 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_337 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_131 -> V_287 )
return 0 ;
V_228 = F_99 ( V_9 -> V_7 , F_260 ( V_135 -> V_338 . V_465 ) ) ;
V_228 += V_135 -> V_338 . V_465 & ~ V_466 ;
if ( F_261 ( V_9 , V_9 -> V_12 . V_313 , & V_12 . V_313 , 8 ) )
return 0 ;
V_263 = F_262 ( V_9 , V_135 -> V_338 . V_465 , V_228 , & V_12 ) ;
return V_263 ;
}
static int F_263 ( struct V_8 * V_9 )
{
int V_263 , V_332 ;
F_264 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_467 = V_9 -> V_315 -> V_303 . V_362 . V_407 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_468 = V_9 -> V_315 -> V_303 . V_362 . V_407 [ 15 ] ;
if ( F_265 () )
F_266 () ;
if ( F_267 ( V_469 ) )
F_268 () ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_263 = F_269 ( V_9 ) ;
if ( V_263 )
return V_263 ;
}
V_263 = F_242 ( V_9 ) ;
if ( V_263 )
return V_263 ;
if ( F_270 ( V_9 ) ) {
F_271 ( V_9 ) ;
F_272 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_470 = 0 ;
V_332 = F_79 ( & V_9 -> V_12 . V_14 -> V_332 ) ;
F_136 ( V_9 , 6 , L_42 , V_332 ) ;
F_273 ( V_9 , V_332 ) ;
return 0 ;
}
static int F_274 ( struct V_8 * V_9 )
{
struct V_471 V_472 = {
. V_473 = V_474 ,
} ;
T_3 V_475 , V_476 ;
int V_263 ;
F_136 ( V_9 , 3 , L_3 , L_43 ) ;
F_275 ( V_9 ) ;
V_263 = F_276 ( V_9 , V_9 -> V_12 . V_14 -> V_333 . V_167 , & V_475 , 1 ) ;
V_476 = F_277 ( V_475 ) ;
if ( V_263 < 0 ) {
return V_263 ;
} else if ( V_263 ) {
V_472 = V_9 -> V_12 . V_477 ;
V_476 = 4 ;
}
V_472 . V_149 = V_476 | V_478 ;
F_278 ( V_9 , V_476 ) ;
return F_279 ( V_9 , & V_472 ) ;
}
static int F_280 ( struct V_8 * V_9 , int V_479 )
{
F_136 ( V_9 , 6 , L_44 ,
V_9 -> V_12 . V_14 -> V_470 ) ;
F_281 ( V_9 , V_9 -> V_12 . V_14 -> V_470 ) ;
if ( F_270 ( V_9 ) )
F_282 ( V_9 ) ;
V_9 -> V_315 -> V_303 . V_362 . V_407 [ 14 ] = V_9 -> V_12 . V_14 -> V_467 ;
V_9 -> V_315 -> V_303 . V_362 . V_407 [ 15 ] = V_9 -> V_12 . V_14 -> V_468 ;
if ( V_9 -> V_12 . V_14 -> V_470 > 0 ) {
int V_263 = F_283 ( V_9 ) ;
if ( V_263 != - V_480 )
return V_263 ;
V_9 -> V_315 -> V_479 = V_481 ;
V_9 -> V_315 -> V_482 . V_470 = V_9 -> V_12 . V_14 -> V_470 ;
V_9 -> V_315 -> V_482 . V_483 = V_9 -> V_12 . V_14 -> V_483 ;
V_9 -> V_315 -> V_482 . V_484 = V_9 -> V_12 . V_14 -> V_484 ;
return - V_485 ;
} else if ( V_479 != - V_168 ) {
V_9 -> V_486 . V_487 ++ ;
return 0 ;
} else if ( F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_315 -> V_479 = V_488 ;
V_9 -> V_315 -> V_489 . V_490 =
V_135 -> V_338 . V_465 ;
V_9 -> V_315 -> V_489 . V_491 = 0x10 ;
return - V_485 ;
} else if ( V_135 -> V_338 . V_492 ) {
F_284 ( V_9 ) ;
V_135 -> V_338 . V_492 = 0 ;
if ( F_258 ( V_9 ) )
return 0 ;
return F_248 ( V_9 , V_135 -> V_338 . V_465 , 1 ) ;
}
return F_274 ( V_9 ) ;
}
static int F_285 ( struct V_8 * V_9 )
{
int V_263 , V_479 ;
V_9 -> V_493 = F_53 ( & V_9 -> V_7 -> V_175 ) ;
do {
V_263 = F_263 ( V_9 ) ;
if ( V_263 )
break;
F_55 ( & V_9 -> V_7 -> V_175 , V_9 -> V_493 ) ;
F_286 () ;
F_287 () ;
F_173 ( V_9 ) ;
F_288 () ;
V_479 = F_289 ( V_9 -> V_12 . V_14 ,
V_9 -> V_315 -> V_303 . V_362 . V_407 ) ;
F_286 () ;
F_172 ( V_9 ) ;
F_290 () ;
F_288 () ;
V_9 -> V_493 = F_53 ( & V_9 -> V_7 -> V_175 ) ;
V_263 = F_280 ( V_9 , V_479 ) ;
} while ( ! F_291 ( V_135 ) && ! F_292 ( V_9 ) && ! V_263 );
F_55 ( & V_9 -> V_7 -> V_175 , V_9 -> V_493 ) ;
return V_263 ;
}
static void F_293 ( struct V_8 * V_9 , struct V_494 * V_494 )
{
V_9 -> V_12 . V_14 -> V_333 . V_334 = V_494 -> V_418 ;
V_9 -> V_12 . V_14 -> V_333 . V_167 = V_494 -> V_419 ;
if ( V_494 -> V_495 & V_317 )
F_165 ( V_9 , V_494 -> V_303 . V_362 . V_391 ) ;
if ( V_494 -> V_495 & V_320 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_337 , & V_494 -> V_303 . V_362 . V_411 , 128 ) ;
F_215 ( V_443 , V_9 ) ;
}
if ( V_494 -> V_495 & V_321 ) {
F_178 ( V_9 , V_494 -> V_303 . V_362 . V_327 ) ;
V_9 -> V_12 . V_14 -> V_335 = V_494 -> V_303 . V_362 . V_335 ;
V_9 -> V_12 . V_14 -> V_336 = V_494 -> V_303 . V_362 . V_336 ;
V_9 -> V_12 . V_14 -> V_342 = V_494 -> V_303 . V_362 . V_342 ;
V_9 -> V_12 . V_14 -> V_341 = V_494 -> V_303 . V_362 . V_341 ;
}
if ( V_494 -> V_495 & V_322 ) {
V_9 -> V_12 . V_313 = V_494 -> V_303 . V_362 . V_496 ;
V_9 -> V_12 . V_403 = V_494 -> V_303 . V_362 . V_497 ;
V_9 -> V_12 . V_401 = V_494 -> V_303 . V_362 . V_498 ;
if ( V_9 -> V_12 . V_313 == V_314 )
F_139 ( V_9 ) ;
}
if ( ( V_494 -> V_495 & V_323 ) &&
F_60 ( V_9 -> V_7 , 64 ) ) {
struct V_499 * V_363 =
(struct V_499 * ) & V_494 -> V_303 . V_362 . V_363 ;
if ( V_363 -> V_500 )
V_9 -> V_12 . V_14 -> V_345 |= 0x01 ;
}
F_294 ( V_9 -> V_12 . V_501 ) ;
F_295 ( V_9 -> V_315 -> V_303 . V_362 . V_410 ) ;
F_194 () ;
V_9 -> V_12 . V_502 . V_340 = V_135 -> V_338 . V_339 . V_340 ;
V_9 -> V_12 . V_502 . V_362 = V_135 -> V_338 . V_339 . V_362 ;
if ( V_124 )
V_135 -> V_338 . V_339 . V_362 = V_9 -> V_315 -> V_303 . V_362 . V_414 ;
else
V_135 -> V_338 . V_339 . V_362 = V_9 -> V_315 -> V_303 . V_362 . V_416 ;
V_135 -> V_338 . V_339 . V_340 = V_9 -> V_315 -> V_303 . V_362 . V_340 ;
if ( F_228 ( V_135 -> V_338 . V_339 . V_340 ) )
V_135 -> V_338 . V_339 . V_340 = 0 ;
V_494 -> V_495 = 0 ;
}
static void F_296 ( struct V_8 * V_9 , struct V_494 * V_494 )
{
V_494 -> V_418 = V_9 -> V_12 . V_14 -> V_333 . V_334 ;
V_494 -> V_419 = V_9 -> V_12 . V_14 -> V_333 . V_167 ;
V_494 -> V_303 . V_362 . V_391 = F_217 ( V_9 ) ;
memcpy ( & V_494 -> V_303 . V_362 . V_411 , & V_9 -> V_12 . V_14 -> V_337 , 128 ) ;
V_494 -> V_303 . V_362 . V_327 = F_179 ( V_9 ) ;
V_494 -> V_303 . V_362 . V_335 = V_9 -> V_12 . V_14 -> V_335 ;
V_494 -> V_303 . V_362 . V_336 = V_9 -> V_12 . V_14 -> V_336 ;
V_494 -> V_303 . V_362 . V_342 = V_9 -> V_12 . V_14 -> V_342 ;
V_494 -> V_303 . V_362 . V_341 = V_9 -> V_12 . V_14 -> V_341 ;
V_494 -> V_303 . V_362 . V_496 = V_9 -> V_12 . V_313 ;
V_494 -> V_303 . V_362 . V_497 = V_9 -> V_12 . V_403 ;
V_494 -> V_303 . V_362 . V_498 = V_9 -> V_12 . V_401 ;
F_294 ( V_9 -> V_315 -> V_303 . V_362 . V_410 ) ;
F_295 ( V_9 -> V_12 . V_501 ) ;
F_194 () ;
V_9 -> V_315 -> V_303 . V_362 . V_340 = V_135 -> V_338 . V_339 . V_340 ;
V_135 -> V_338 . V_339 . V_340 = V_9 -> V_12 . V_502 . V_340 ;
V_135 -> V_338 . V_339 . V_362 = V_9 -> V_12 . V_502 . V_362 ;
}
int F_297 ( struct V_8 * V_9 , struct V_494 * V_494 )
{
int V_263 ;
T_12 V_503 ;
if ( V_494 -> V_504 )
return - V_505 ;
if ( F_292 ( V_9 ) ) {
F_298 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_506 )
F_299 ( V_507 , & V_9 -> V_508 , & V_503 ) ;
if ( ! F_195 ( V_9 -> V_7 ) ) {
F_240 ( V_9 ) ;
} else if ( F_233 ( V_9 ) ) {
F_300 ( L_45 ,
V_9 -> V_290 ) ;
return - V_87 ;
}
F_293 ( V_9 , V_494 ) ;
F_174 ( V_9 ) ;
F_301 () ;
V_263 = F_285 ( V_9 ) ;
if ( F_291 ( V_135 ) && ! V_263 ) {
V_494 -> V_479 = V_509 ;
V_263 = - V_505 ;
}
if ( F_292 ( V_9 ) && ! V_263 ) {
F_298 ( V_9 ) ;
V_263 = 0 ;
}
if ( V_263 == - V_485 ) {
V_263 = 0 ;
}
F_177 ( V_9 ) ;
F_296 ( V_9 , V_494 ) ;
if ( V_9 -> V_506 )
F_299 ( V_507 , & V_503 , NULL ) ;
V_9 -> V_486 . V_510 ++ ;
return V_263 ;
}
int F_302 ( struct V_8 * V_9 , unsigned long V_449 )
{
unsigned char V_511 = 1 ;
V_415 V_416 [ V_512 ] ;
unsigned int V_513 ;
V_165 V_514 , V_327 ;
int V_263 ;
V_513 = F_217 ( V_9 ) ;
if ( V_449 == V_515 ) {
if ( F_303 ( V_9 , 163 , & V_511 , 1 ) )
return - V_168 ;
V_449 = 0 ;
} else if ( V_449 == V_516 ) {
if ( F_304 ( V_9 , 163 , & V_511 , 1 ) )
return - V_168 ;
V_449 = V_513 ;
} else
V_449 -= V_517 ;
if ( V_124 ) {
F_231 ( V_416 , ( V_413 * ) V_9 -> V_315 -> V_303 . V_362 . V_414 ) ;
V_263 = F_303 ( V_9 , V_449 + V_517 ,
V_416 , 128 ) ;
} else {
V_263 = F_303 ( V_9 , V_449 + V_517 ,
V_9 -> V_315 -> V_303 . V_362 . V_416 , 128 ) ;
}
V_263 |= F_303 ( V_9 , V_449 + V_518 ,
V_9 -> V_315 -> V_303 . V_362 . V_407 , 128 ) ;
V_263 |= F_303 ( V_9 , V_449 + V_519 ,
& V_9 -> V_12 . V_14 -> V_333 , 16 ) ;
V_263 |= F_303 ( V_9 , V_449 + V_520 ,
& V_513 , 4 ) ;
V_263 |= F_303 ( V_9 , V_449 + V_521 ,
& V_9 -> V_315 -> V_303 . V_362 . V_340 , 4 ) ;
V_263 |= F_303 ( V_9 , V_449 + V_522 ,
& V_9 -> V_12 . V_14 -> V_336 , 4 ) ;
V_327 = F_179 ( V_9 ) ;
V_263 |= F_303 ( V_9 , V_449 + V_523 ,
& V_327 , 8 ) ;
V_514 = V_9 -> V_12 . V_14 -> V_335 >> 8 ;
V_263 |= F_303 ( V_9 , V_449 + V_524 ,
& V_514 , 8 ) ;
V_263 |= F_303 ( V_9 , V_449 + V_525 ,
& V_9 -> V_315 -> V_303 . V_362 . V_410 , 64 ) ;
V_263 |= F_303 ( V_9 , V_449 + V_526 ,
& V_9 -> V_12 . V_14 -> V_337 , 128 ) ;
return V_263 ? - V_168 : 0 ;
}
int F_305 ( struct V_8 * V_9 , unsigned long V_167 )
{
F_194 () ;
V_9 -> V_315 -> V_303 . V_362 . V_340 = V_135 -> V_338 . V_339 . V_340 ;
F_294 ( V_9 -> V_315 -> V_303 . V_362 . V_410 ) ;
return F_302 ( V_9 , V_167 ) ;
}
static void F_306 ( struct V_8 * V_9 )
{
F_243 ( V_445 , V_9 ) ;
F_46 ( V_446 , V_9 ) ;
}
static void F_307 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_306 ( V_9 ) ;
}
}
static void F_308 ( struct V_8 * V_9 )
{
if ( ! V_58 . V_74 )
return;
F_243 ( V_446 , V_9 ) ;
F_46 ( V_445 , V_9 ) ;
}
void F_240 ( struct V_8 * V_9 )
{
int V_10 , V_208 , V_527 = 0 ;
if ( ! F_233 ( V_9 ) )
return;
F_309 ( V_9 -> V_290 , 1 ) ;
F_124 ( & V_9 -> V_7 -> V_12 . V_289 ) ;
V_208 = F_79 ( & V_9 -> V_7 -> V_208 ) ;
for ( V_10 = 0 ; V_10 < V_208 ; V_10 ++ ) {
if ( ! F_233 ( V_9 -> V_7 -> V_292 [ V_10 ] ) )
V_527 ++ ;
}
if ( V_527 == 0 ) {
F_308 ( V_9 ) ;
} else if ( V_527 == 1 ) {
F_307 ( V_9 -> V_7 ) ;
}
F_190 ( V_353 , & V_9 -> V_12 . V_14 -> V_332 ) ;
F_215 ( V_443 , V_9 ) ;
F_125 ( & V_9 -> V_7 -> V_12 . V_289 ) ;
return;
}
void F_196 ( struct V_8 * V_9 )
{
int V_10 , V_208 , V_527 = 0 ;
struct V_8 * V_528 = NULL ;
if ( F_233 ( V_9 ) )
return;
F_309 ( V_9 -> V_290 , 0 ) ;
F_124 ( & V_9 -> V_7 -> V_12 . V_289 ) ;
V_208 = F_79 ( & V_9 -> V_7 -> V_208 ) ;
F_310 ( V_9 ) ;
F_187 ( V_353 , & V_9 -> V_12 . V_14 -> V_332 ) ;
F_306 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_208 ; V_10 ++ ) {
if ( ! F_233 ( V_9 -> V_7 -> V_292 [ V_10 ] ) ) {
V_527 ++ ;
V_528 = V_9 -> V_7 -> V_292 [ V_10 ] ;
}
}
if ( V_527 == 1 ) {
F_308 ( V_528 ) ;
}
F_125 ( & V_9 -> V_7 -> V_12 . V_289 ) ;
return;
}
static int F_311 ( struct V_8 * V_9 ,
struct V_147 * V_148 )
{
int V_89 ;
if ( V_148 -> V_149 )
return - V_87 ;
switch ( V_148 -> V_148 ) {
case V_98 :
if ( ! V_9 -> V_7 -> V_12 . V_288 ) {
V_9 -> V_7 -> V_12 . V_288 = 1 ;
F_48 ( V_9 -> V_7 , 3 , L_3 , L_46 ) ;
F_312 ( V_9 -> V_7 ) ;
}
V_89 = 0 ;
break;
default:
V_89 = - V_87 ;
break;
}
return V_89 ;
}
static long F_313 ( struct V_8 * V_9 ,
struct V_529 * V_530 )
{
void V_166 * V_531 = ( void V_166 * ) V_530 -> V_532 ;
void * V_533 = NULL ;
int V_89 , V_493 ;
const V_165 V_534 = V_535
| V_536 ;
if ( V_530 -> V_149 & ~ V_534 )
return - V_87 ;
if ( V_530 -> V_537 > V_113 )
return - V_178 ;
if ( ! ( V_530 -> V_149 & V_536 ) ) {
V_533 = F_97 ( V_530 -> V_537 ) ;
if ( ! V_533 )
return - V_78 ;
}
V_493 = F_53 ( & V_9 -> V_7 -> V_175 ) ;
switch ( V_530 -> V_538 ) {
case V_539 :
if ( V_530 -> V_149 & V_536 ) {
V_89 = F_314 ( V_9 , V_530 -> V_540 , V_530 -> V_541 ,
V_530 -> V_537 , V_542 ) ;
break;
}
V_89 = F_315 ( V_9 , V_530 -> V_540 , V_530 -> V_541 , V_533 , V_530 -> V_537 ) ;
if ( V_89 == 0 ) {
if ( F_70 ( V_531 , V_533 , V_530 -> V_537 ) )
V_89 = - V_168 ;
}
break;
case V_543 :
if ( V_530 -> V_149 & V_536 ) {
V_89 = F_314 ( V_9 , V_530 -> V_540 , V_530 -> V_541 ,
V_530 -> V_537 , V_544 ) ;
break;
}
if ( F_65 ( V_533 , V_531 , V_530 -> V_537 ) ) {
V_89 = - V_168 ;
break;
}
V_89 = F_316 ( V_9 , V_530 -> V_540 , V_530 -> V_541 , V_533 , V_530 -> V_537 ) ;
break;
default:
V_89 = - V_87 ;
}
F_55 ( & V_9 -> V_7 -> V_175 , V_493 ) ;
if ( V_89 > 0 && ( V_530 -> V_149 & V_535 ) != 0 )
F_279 ( V_9 , & V_9 -> V_12 . V_477 ) ;
F_317 ( V_533 ) ;
return V_89 ;
}
long F_318 ( struct V_82 * V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_8 * V_9 = V_83 -> V_236 ;
void V_166 * V_237 = ( void V_166 * ) V_85 ;
int V_170 ;
long V_89 ;
switch ( V_84 ) {
case V_545 : {
struct V_455 V_546 ;
V_89 = - V_168 ;
if ( F_65 ( & V_546 , V_237 , sizeof( V_546 ) ) )
break;
V_89 = F_251 ( V_9 , & V_546 ) ;
break;
}
case V_238 : {
struct V_239 V_240 ;
struct V_455 V_546 ;
V_89 = - V_168 ;
if ( F_65 ( & V_240 , V_237 , sizeof( V_240 ) ) )
break;
if ( F_319 ( & V_240 , & V_546 ) )
return - V_87 ;
V_89 = F_251 ( V_9 , & V_546 ) ;
break;
}
case V_547 :
V_170 = F_53 ( & V_9 -> V_7 -> V_175 ) ;
V_89 = F_305 ( V_9 , V_85 ) ;
F_55 ( & V_9 -> V_7 -> V_175 , V_170 ) ;
break;
case V_548 : {
T_9 V_417 ;
V_89 = - V_168 ;
if ( F_65 ( & V_417 , V_237 , sizeof( V_417 ) ) )
break;
V_89 = F_232 ( V_9 , V_417 ) ;
break;
}
case V_549 :
V_89 = F_222 ( V_9 ) ;
break;
case V_550 :
case V_551 : {
struct V_393 V_394 ;
V_89 = - V_168 ;
if ( F_65 ( & V_394 , V_237 , sizeof( V_394 ) ) )
break;
if ( V_84 == V_550 )
V_89 = F_221 ( V_9 , & V_394 ) ;
else
V_89 = F_220 ( V_9 , & V_394 ) ;
break;
}
#ifdef F_30
case V_552 : {
struct V_553 V_554 ;
if ( F_65 ( & V_554 , V_237 , sizeof( V_554 ) ) ) {
V_89 = - V_168 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_89 = - V_87 ;
break;
}
V_89 = F_320 ( V_9 -> V_12 . V_131 , V_554 . V_555 ,
V_554 . V_556 , V_554 . V_557 ) ;
break;
}
case V_558 : {
struct V_553 V_554 ;
if ( F_65 ( & V_554 , V_237 , sizeof( V_554 ) ) ) {
V_89 = - V_168 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_89 = - V_87 ;
break;
}
V_89 = F_321 ( V_9 -> V_12 . V_131 , V_554 . V_556 ,
V_554 . V_557 ) ;
break;
}
#endif
case V_559 : {
V_89 = F_249 ( V_9 -> V_12 . V_131 , V_85 , 0 ) ;
break;
}
case V_241 :
{
struct V_147 V_148 ;
V_89 = - V_168 ;
if ( F_65 ( & V_148 , V_237 , sizeof( V_148 ) ) )
break;
V_89 = F_311 ( V_9 , & V_148 ) ;
break;
}
case V_560 : {
struct V_529 V_561 ;
if ( F_65 ( & V_561 , V_237 , sizeof( V_561 ) ) == 0 )
V_89 = F_313 ( V_9 , & V_561 ) ;
else
V_89 = - V_168 ;
break;
}
case V_562 : {
struct V_563 V_564 ;
V_89 = - V_168 ;
if ( F_65 ( & V_564 , V_237 , sizeof( V_564 ) ) )
break;
if ( V_564 . V_565 > V_566 ||
V_564 . V_565 == 0 ||
V_564 . V_565 % sizeof( struct V_455 ) > 0 ) {
V_89 = - V_87 ;
break;
}
V_89 = F_322 ( V_9 ,
( void V_166 * ) V_564 . V_532 ,
V_564 . V_565 ) ;
break;
}
case V_567 : {
struct V_563 V_564 ;
V_89 = - V_168 ;
if ( F_65 ( & V_564 , V_237 , sizeof( V_564 ) ) )
break;
if ( V_564 . V_565 == 0 ) {
V_89 = - V_87 ;
break;
}
V_89 = F_323 ( V_9 ,
( V_568 V_166 * ) V_564 . V_532 ,
V_564 . V_565 ) ;
break;
}
default:
V_89 = - V_250 ;
}
return V_89 ;
}
int F_324 ( struct V_8 * V_9 , struct V_569 * V_570 )
{
#ifdef F_30
if ( ( V_570 -> V_571 == V_572 )
&& ( F_39 ( V_9 -> V_7 ) ) ) {
V_570 -> V_573 = F_325 ( V_9 -> V_12 . V_14 ) ;
F_326 ( V_570 -> V_573 ) ;
return 0 ;
}
#endif
return V_574 ;
}
int F_327 ( struct V_7 * V_7 , struct V_126 * V_142 ,
unsigned long V_133 )
{
return 0 ;
}
int F_328 ( struct V_7 * V_7 ,
struct V_126 * V_127 ,
const struct V_575 * V_576 ,
enum V_577 V_578 )
{
if ( V_576 -> V_579 & 0xffffful )
return - V_87 ;
if ( V_576 -> V_580 & 0xffffful )
return - V_87 ;
if ( V_576 -> V_581 + V_576 -> V_580 > V_7 -> V_12 . V_164 )
return - V_87 ;
return 0 ;
}
void F_329 ( struct V_7 * V_7 ,
const struct V_575 * V_576 ,
const struct V_126 * V_582 ,
const struct V_126 * V_179 ,
enum V_577 V_578 )
{
int V_263 ;
if ( V_582 -> V_579 == V_576 -> V_579 &&
V_582 -> V_132 * V_275 == V_576 -> V_581 &&
V_582 -> V_133 * V_275 == V_576 -> V_580 )
return;
V_263 = F_320 ( V_7 -> V_12 . V_131 , V_576 -> V_579 ,
V_576 -> V_581 , V_576 -> V_580 ) ;
if ( V_263 )
F_330 ( L_47 ) ;
return;
}
static inline unsigned long F_331 ( int V_10 )
{
unsigned int V_583 = ( V_58 . V_584 << V_10 * 2 ) >> 30 ;
return 0x0000ffffffffffffUL >> ( V_583 << 4 ) ;
}
void F_332 ( struct V_8 * V_9 )
{
V_9 -> V_585 = false ;
}
static int T_13 F_333 ( void )
{
int V_10 ;
if ( ! V_58 . V_59 ) {
F_334 ( L_48 ) ;
return - V_586 ;
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_1 [ V_10 ] |=
V_215 . V_216 [ V_10 ] & F_331 ( V_10 ) ;
return F_335 ( NULL , sizeof( struct V_8 ) , 0 , V_587 ) ;
}
static void T_14 F_336 ( void )
{
F_337 () ;
}
