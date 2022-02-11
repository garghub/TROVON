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
V_93 = 1 ;
break;
case V_117 :
V_93 = V_118 ;
break;
case V_119 :
case V_120 :
V_93 = V_121 ;
if ( ! F_31 () )
V_93 = V_122 ;
else if ( V_60 . V_123 && V_60 . V_62 )
V_93 = V_124 ;
break;
case V_125 :
V_93 = V_126 ;
break;
case V_127 :
V_93 = V_58 ;
break;
case V_128 :
V_93 = V_129 ;
break;
case V_130 :
V_93 = F_18 ( 64 ) ;
break;
case V_131 :
V_93 = F_18 ( 133 ) ;
break;
default:
V_93 = 0 ;
}
return V_93 ;
}
static void F_32 ( struct V_7 * V_7 ,
struct V_132 * V_133 )
{
T_2 V_134 , V_135 ;
unsigned long V_136 ;
struct V_137 * V_137 = V_7 -> V_12 . V_137 ;
V_135 = V_133 -> V_138 + V_133 -> V_139 ;
for ( V_134 = V_133 -> V_138 ; V_134 <= V_135 ; V_134 ++ ) {
V_136 = F_33 ( V_133 , V_134 ) ;
if ( F_34 ( V_137 -> V_140 , V_136 ) )
F_35 ( V_7 , V_134 ) ;
if ( F_36 ( V_141 ) )
return;
F_37 () ;
}
}
int F_38 ( struct V_7 * V_7 ,
struct V_142 * log )
{
int V_93 ;
unsigned long V_143 ;
struct V_144 * V_145 ;
struct V_132 * V_133 ;
int V_146 = 0 ;
if ( F_39 ( V_7 ) )
return - V_91 ;
F_40 ( & V_7 -> V_147 ) ;
V_93 = - V_91 ;
if ( log -> V_148 >= V_126 )
goto V_149;
V_145 = V_144 ( V_7 ) ;
V_133 = F_41 ( V_145 , log -> V_148 ) ;
V_93 = - V_150 ;
if ( ! V_133 -> V_151 )
goto V_149;
F_32 ( V_7 , V_133 ) ;
V_93 = F_42 ( V_7 , log , & V_146 ) ;
if ( V_93 )
goto V_149;
if ( V_146 ) {
V_143 = F_43 ( V_133 ) ;
memset ( V_133 -> V_151 , 0 , V_143 ) ;
}
V_93 = 0 ;
V_149:
F_44 ( & V_7 -> V_147 ) ;
return V_93 ;
}
static void F_45 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_46 ( V_152 , V_9 ) ;
}
}
static int F_47 ( struct V_7 * V_7 , struct V_153 * V_154 )
{
int V_93 ;
if ( V_154 -> V_155 )
return - V_91 ;
switch ( V_154 -> V_154 ) {
case V_106 :
F_48 ( V_7 , 3 , L_3 , L_4 ) ;
V_7 -> V_12 . V_156 = 1 ;
V_93 = 0 ;
break;
case V_111 :
F_48 ( V_7 , 3 , L_3 , L_5 ) ;
V_7 -> V_12 . V_157 = 1 ;
V_93 = 0 ;
break;
case V_128 :
F_40 ( & V_7 -> V_158 ) ;
if ( V_7 -> V_159 ) {
V_93 = - V_160 ;
} else if ( V_129 ) {
F_49 ( V_7 -> V_12 . V_161 . V_162 , 129 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_163 , 129 ) ;
if ( F_18 ( 134 ) ) {
F_49 ( V_7 -> V_12 . V_161 . V_162 , 134 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_163 , 134 ) ;
}
if ( F_18 ( 135 ) ) {
F_49 ( V_7 -> V_12 . V_161 . V_162 , 135 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_163 , 135 ) ;
}
V_93 = 0 ;
} else
V_93 = - V_91 ;
F_44 ( & V_7 -> V_158 ) ;
F_48 ( V_7 , 3 , L_6 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_130 :
V_93 = - V_91 ;
F_40 ( & V_7 -> V_158 ) ;
if ( V_7 -> V_159 ) {
V_93 = - V_160 ;
} else if ( F_18 ( 64 ) ) {
F_49 ( V_7 -> V_12 . V_161 . V_162 , 64 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_163 , 64 ) ;
V_93 = 0 ;
}
F_44 ( & V_7 -> V_158 ) ;
F_48 ( V_7 , 3 , L_9 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_116 :
F_40 ( & V_7 -> V_158 ) ;
if ( V_7 -> V_159 ) {
V_93 = - V_160 ;
} else {
F_49 ( V_7 -> V_12 . V_161 . V_162 , 72 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_163 , 72 ) ;
V_93 = 0 ;
}
F_44 ( & V_7 -> V_158 ) ;
F_48 ( V_7 , 3 , L_10 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_131 :
V_93 = - V_91 ;
F_40 ( & V_7 -> V_158 ) ;
if ( F_50 ( & V_7 -> V_164 ) ) {
V_93 = - V_160 ;
} else if ( F_18 ( 133 ) ) {
F_49 ( V_7 -> V_12 . V_161 . V_162 , 133 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_163 , 133 ) ;
V_93 = 0 ;
}
F_44 ( & V_7 -> V_158 ) ;
F_48 ( V_7 , 3 , L_11 ,
V_93 ? L_7 : L_8 ) ;
break;
case V_112 :
F_48 ( V_7 , 3 , L_3 , L_12 ) ;
V_7 -> V_12 . V_165 = 1 ;
V_93 = 0 ;
break;
case V_115 :
F_48 ( V_7 , 3 , L_3 , L_13 ) ;
V_7 -> V_12 . V_166 = 1 ;
F_45 ( V_7 ) ;
V_93 = 0 ;
break;
default:
V_93 = - V_91 ;
break;
}
return V_93 ;
}
static int F_51 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 ;
switch ( V_168 -> V_168 ) {
case V_170 :
V_169 = 0 ;
F_48 ( V_7 , 3 , L_14 ,
V_7 -> V_12 . V_171 ) ;
if ( F_52 ( V_7 -> V_12 . V_171 , ( V_172 V_173 * ) V_168 -> V_174 ) )
V_169 = - V_175 ;
break;
default:
V_169 = - V_176 ;
break;
}
return V_169 ;
}
static int F_53 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 ;
unsigned int V_177 ;
switch ( V_168 -> V_168 ) {
case V_178 :
V_169 = - V_176 ;
if ( ! V_60 . V_179 )
break;
V_169 = - V_160 ;
F_48 ( V_7 , 3 , L_3 , L_15 ) ;
F_40 ( & V_7 -> V_158 ) ;
if ( ! V_7 -> V_159 ) {
V_7 -> V_12 . V_180 = 1 ;
V_169 = 0 ;
}
F_44 ( & V_7 -> V_158 ) ;
break;
case V_181 :
V_169 = - V_176 ;
if ( ! V_60 . V_179 )
break;
V_169 = - V_91 ;
if ( ! V_7 -> V_12 . V_180 )
break;
F_48 ( V_7 , 3 , L_3 , L_16 ) ;
F_40 ( & V_7 -> V_158 ) ;
V_177 = F_54 ( & V_7 -> V_182 ) ;
F_55 ( V_7 -> V_12 . V_137 -> V_140 ) ;
F_56 ( & V_7 -> V_182 , V_177 ) ;
F_44 ( & V_7 -> V_158 ) ;
V_169 = 0 ;
break;
case V_170 : {
unsigned long V_183 ;
if ( F_39 ( V_7 ) )
return - V_91 ;
if ( F_57 ( V_183 , ( V_172 V_173 * ) V_168 -> V_174 ) )
return - V_175 ;
if ( V_7 -> V_12 . V_171 != V_184 &&
V_183 > V_7 -> V_12 . V_171 )
return - V_185 ;
if ( ! V_183 )
return - V_91 ;
if ( V_183 != V_184 )
V_183 -= 1 ;
V_169 = - V_160 ;
F_40 ( & V_7 -> V_158 ) ;
if ( ! V_7 -> V_159 ) {
struct V_137 * V_186 = F_58 ( V_141 -> V_140 , V_183 ) ;
if ( ! V_186 ) {
V_169 = - V_82 ;
} else {
F_59 ( V_7 -> V_12 . V_137 ) ;
V_186 -> V_187 = V_7 ;
V_7 -> V_12 . V_137 = V_186 ;
V_169 = 0 ;
}
}
F_44 ( & V_7 -> V_158 ) ;
F_48 ( V_7 , 3 , L_17 , V_183 ) ;
F_48 ( V_7 , 3 , L_18 ,
( void * ) V_7 -> V_12 . V_137 -> V_188 ) ;
break;
}
default:
V_169 = - V_176 ;
break;
}
return V_169 ;
}
static int F_60 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_61 ( V_7 , 76 ) )
return - V_91 ;
F_40 ( & V_7 -> V_158 ) ;
switch ( V_168 -> V_168 ) {
case V_189 :
F_62 (
V_7 -> V_12 . V_190 . V_191 -> V_192 ,
sizeof( V_7 -> V_12 . V_190 . V_191 -> V_192 ) ) ;
V_7 -> V_12 . V_190 . V_193 = 1 ;
F_48 ( V_7 , 3 , L_3 , L_19 ) ;
break;
case V_194 :
F_62 (
V_7 -> V_12 . V_190 . V_191 -> V_195 ,
sizeof( V_7 -> V_12 . V_190 . V_191 -> V_195 ) ) ;
V_7 -> V_12 . V_190 . V_196 = 1 ;
F_48 ( V_7 , 3 , L_3 , L_20 ) ;
break;
case V_197 :
V_7 -> V_12 . V_190 . V_193 = 0 ;
memset ( V_7 -> V_12 . V_190 . V_191 -> V_192 , 0 ,
sizeof( V_7 -> V_12 . V_190 . V_191 -> V_192 ) ) ;
F_48 ( V_7 , 3 , L_3 , L_21 ) ;
break;
case V_198 :
V_7 -> V_12 . V_190 . V_196 = 0 ;
memset ( V_7 -> V_12 . V_190 . V_191 -> V_195 , 0 ,
sizeof( V_7 -> V_12 . V_190 . V_191 -> V_195 ) ) ;
F_48 ( V_7 , 3 , L_3 , L_22 ) ;
break;
default:
F_44 ( & V_7 -> V_158 ) ;
return - V_176 ;
}
F_7 (i, vcpu, kvm) {
F_63 ( V_9 ) ;
F_64 ( V_9 ) ;
}
F_44 ( & V_7 -> V_158 ) ;
return 0 ;
}
static int F_65 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
T_3 V_199 ;
if ( F_66 ( & V_199 , ( void V_173 * ) V_168 -> V_174 ,
sizeof( V_199 ) ) )
return - V_175 ;
if ( V_199 != 0 )
return - V_91 ;
F_48 ( V_7 , 3 , L_23 , V_199 ) ;
return 0 ;
}
static int F_67 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
V_172 V_200 ;
if ( F_66 ( & V_200 , ( void V_173 * ) V_168 -> V_174 , sizeof( V_200 ) ) )
return - V_175 ;
F_68 ( V_7 , V_200 ) ;
F_48 ( V_7 , 3 , L_24 , V_200 ) ;
return 0 ;
}
static int F_69 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 ;
if ( V_168 -> V_155 )
return - V_91 ;
switch ( V_168 -> V_168 ) {
case V_201 :
V_169 = F_65 ( V_7 , V_168 ) ;
break;
case V_202 :
V_169 = F_67 ( V_7 , V_168 ) ;
break;
default:
V_169 = - V_176 ;
break;
}
return V_169 ;
}
static int F_70 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
T_3 V_199 = 0 ;
if ( F_71 ( ( void V_173 * ) V_168 -> V_174 , & V_199 ,
sizeof( V_199 ) ) )
return - V_175 ;
F_48 ( V_7 , 3 , L_25 , V_199 ) ;
return 0 ;
}
static int F_72 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
V_172 V_200 ;
V_200 = F_73 ( V_7 ) ;
if ( F_71 ( ( void V_173 * ) V_168 -> V_174 , & V_200 , sizeof( V_200 ) ) )
return - V_175 ;
F_48 ( V_7 , 3 , L_26 , V_200 ) ;
return 0 ;
}
static int F_74 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 ;
if ( V_168 -> V_155 )
return - V_91 ;
switch ( V_168 -> V_168 ) {
case V_201 :
V_169 = F_70 ( V_7 , V_168 ) ;
break;
case V_202 :
V_169 = F_72 ( V_7 , V_168 ) ;
break;
default:
V_169 = - V_176 ;
break;
}
return V_169 ;
}
static int F_75 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
struct V_203 * V_204 ;
T_4 V_205 , V_206 ;
int V_169 = 0 ;
F_40 ( & V_7 -> V_158 ) ;
if ( V_7 -> V_159 ) {
V_169 = - V_160 ;
goto V_149;
}
V_204 = F_76 ( sizeof( * V_204 ) , V_207 ) ;
if ( ! V_204 ) {
V_169 = - V_82 ;
goto V_149;
}
if ( ! F_66 ( V_204 , ( void V_173 * ) V_168 -> V_174 ,
sizeof( * V_204 ) ) ) {
V_7 -> V_12 . V_161 . V_208 = V_204 -> V_208 ;
V_205 = V_60 . V_209 >> 16 & 0xfff ;
V_206 = V_60 . V_209 & 0xfff ;
if ( V_205 && V_204 -> V_209 ) {
if ( V_204 -> V_209 > V_206 )
V_7 -> V_12 . V_161 . V_209 = V_206 ;
else if ( V_204 -> V_209 < V_205 )
V_7 -> V_12 . V_161 . V_209 = V_205 ;
else
V_7 -> V_12 . V_161 . V_209 = V_204 -> V_209 ;
}
memcpy ( V_7 -> V_12 . V_161 . V_163 , V_204 -> V_163 ,
V_210 ) ;
F_48 ( V_7 , 3 , L_27 ,
V_7 -> V_12 . V_161 . V_209 ,
V_7 -> V_12 . V_161 . V_208 ) ;
F_48 ( V_7 , 3 , L_28 ,
V_7 -> V_12 . V_161 . V_163 [ 0 ] ,
V_7 -> V_12 . V_161 . V_163 [ 1 ] ,
V_7 -> V_12 . V_161 . V_163 [ 2 ] ) ;
} else
V_169 = - V_175 ;
F_77 ( V_204 ) ;
V_149:
F_44 ( & V_7 -> V_158 ) ;
return V_169 ;
}
static int F_78 ( struct V_7 * V_7 ,
struct V_167 * V_168 )
{
struct V_211 V_212 ;
int V_169 = - V_160 ;
if ( F_66 ( & V_212 , ( void V_173 * ) V_168 -> V_174 , sizeof( V_212 ) ) )
return - V_175 ;
if ( ! F_79 ( ( unsigned long * ) V_212 . V_213 ,
V_27 ,
V_214 ) )
return - V_91 ;
F_40 ( & V_7 -> V_158 ) ;
if ( ! F_50 ( & V_7 -> V_164 ) ) {
F_80 ( V_7 -> V_12 . V_215 , ( unsigned long * ) V_212 . V_213 ,
V_214 ) ;
V_169 = 0 ;
}
F_44 ( & V_7 -> V_158 ) ;
return V_169 ;
}
static int F_81 ( struct V_7 * V_7 ,
struct V_167 * V_168 )
{
return - V_176 ;
}
static int F_82 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 = - V_176 ;
switch ( V_168 -> V_168 ) {
case V_216 :
V_169 = F_75 ( V_7 , V_168 ) ;
break;
case V_217 :
V_169 = F_78 ( V_7 , V_168 ) ;
break;
case V_218 :
V_169 = F_81 ( V_7 , V_168 ) ;
break;
}
return V_169 ;
}
static int F_83 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
struct V_203 * V_204 ;
int V_169 = 0 ;
V_204 = F_76 ( sizeof( * V_204 ) , V_207 ) ;
if ( ! V_204 ) {
V_169 = - V_82 ;
goto V_149;
}
V_204 -> V_208 = V_7 -> V_12 . V_161 . V_208 ;
V_204 -> V_209 = V_7 -> V_12 . V_161 . V_209 ;
memcpy ( & V_204 -> V_163 , V_7 -> V_12 . V_161 . V_163 ,
V_210 ) ;
F_48 ( V_7 , 3 , L_29 ,
V_7 -> V_12 . V_161 . V_209 ,
V_7 -> V_12 . V_161 . V_208 ) ;
F_48 ( V_7 , 3 , L_30 ,
V_7 -> V_12 . V_161 . V_163 [ 0 ] ,
V_7 -> V_12 . V_161 . V_163 [ 1 ] ,
V_7 -> V_12 . V_161 . V_163 [ 2 ] ) ;
if ( F_71 ( ( void V_173 * ) V_168 -> V_174 , V_204 , sizeof( * V_204 ) ) )
V_169 = - V_175 ;
F_77 ( V_204 ) ;
V_149:
return V_169 ;
}
static int F_84 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
struct V_219 * V_220 ;
int V_169 = 0 ;
V_220 = F_76 ( sizeof( * V_220 ) , V_207 ) ;
if ( ! V_220 ) {
V_169 = - V_82 ;
goto V_149;
}
F_85 ( (struct V_208 * ) & V_220 -> V_208 ) ;
V_220 -> V_209 = V_60 . V_209 ;
memcpy ( & V_220 -> V_162 , V_7 -> V_12 . V_161 . V_162 ,
V_210 ) ;
memcpy ( ( unsigned long * ) & V_220 -> V_163 , V_221 . V_222 ,
sizeof( V_221 . V_222 ) ) ;
F_48 ( V_7 , 3 , L_31 ,
V_7 -> V_12 . V_161 . V_209 ,
V_7 -> V_12 . V_161 . V_208 ) ;
F_48 ( V_7 , 3 , L_32 ,
V_220 -> V_162 [ 0 ] ,
V_220 -> V_162 [ 1 ] ,
V_220 -> V_162 [ 2 ] ) ;
F_48 ( V_7 , 3 , L_33 ,
V_220 -> V_163 [ 0 ] ,
V_220 -> V_163 [ 1 ] ,
V_220 -> V_163 [ 2 ] ) ;
if ( F_71 ( ( void V_173 * ) V_168 -> V_174 , V_220 , sizeof( * V_220 ) ) )
V_169 = - V_175 ;
F_77 ( V_220 ) ;
V_149:
return V_169 ;
}
static int F_86 ( struct V_7 * V_7 ,
struct V_167 * V_168 )
{
struct V_211 V_212 ;
F_80 ( ( unsigned long * ) V_212 . V_213 , V_7 -> V_12 . V_215 ,
V_214 ) ;
if ( F_71 ( ( void V_173 * ) V_168 -> V_174 , & V_212 , sizeof( V_212 ) ) )
return - V_175 ;
return 0 ;
}
static int F_87 ( struct V_7 * V_7 ,
struct V_167 * V_168 )
{
struct V_211 V_212 ;
F_80 ( ( unsigned long * ) V_212 . V_213 ,
V_27 ,
V_214 ) ;
if ( F_71 ( ( void V_173 * ) V_168 -> V_174 , & V_212 , sizeof( V_212 ) ) )
return - V_175 ;
return 0 ;
}
static int F_88 ( struct V_7 * V_7 ,
struct V_167 * V_168 )
{
return - V_176 ;
}
static int F_89 ( struct V_7 * V_7 ,
struct V_167 * V_168 )
{
if ( F_71 ( ( void V_173 * ) V_168 -> V_174 , & V_30 ,
sizeof( struct V_223 ) ) )
return - V_175 ;
return 0 ;
}
static int F_90 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 = - V_176 ;
switch ( V_168 -> V_168 ) {
case V_216 :
V_169 = F_83 ( V_7 , V_168 ) ;
break;
case V_224 :
V_169 = F_84 ( V_7 , V_168 ) ;
break;
case V_217 :
V_169 = F_86 ( V_7 , V_168 ) ;
break;
case V_225 :
V_169 = F_87 ( V_7 , V_168 ) ;
break;
case V_218 :
V_169 = F_88 ( V_7 , V_168 ) ;
break;
case V_226 :
V_169 = F_89 ( V_7 , V_168 ) ;
break;
}
return V_169 ;
}
static int F_91 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 ;
switch ( V_168 -> V_227 ) {
case V_228 :
V_169 = F_53 ( V_7 , V_168 ) ;
break;
case V_229 :
V_169 = F_69 ( V_7 , V_168 ) ;
break;
case V_230 :
V_169 = F_82 ( V_7 , V_168 ) ;
break;
case V_231 :
V_169 = F_60 ( V_7 , V_168 ) ;
break;
default:
V_169 = - V_176 ;
break;
}
return V_169 ;
}
static int F_92 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 ;
switch ( V_168 -> V_227 ) {
case V_228 :
V_169 = F_51 ( V_7 , V_168 ) ;
break;
case V_229 :
V_169 = F_74 ( V_7 , V_168 ) ;
break;
case V_230 :
V_169 = F_90 ( V_7 , V_168 ) ;
break;
default:
V_169 = - V_176 ;
break;
}
return V_169 ;
}
static int F_93 ( struct V_7 * V_7 , struct V_167 * V_168 )
{
int V_169 ;
switch ( V_168 -> V_227 ) {
case V_228 :
switch ( V_168 -> V_168 ) {
case V_178 :
case V_181 :
V_169 = V_60 . V_179 ? 0 : - V_176 ;
break;
case V_170 :
V_169 = 0 ;
break;
default:
V_169 = - V_176 ;
break;
}
break;
case V_229 :
switch ( V_168 -> V_168 ) {
case V_202 :
case V_201 :
V_169 = 0 ;
break;
default:
V_169 = - V_176 ;
break;
}
break;
case V_230 :
switch ( V_168 -> V_168 ) {
case V_216 :
case V_224 :
case V_217 :
case V_225 :
case V_226 :
V_169 = 0 ;
break;
case V_218 :
default:
V_169 = - V_176 ;
break;
}
break;
case V_231 :
switch ( V_168 -> V_168 ) {
case V_189 :
case V_194 :
case V_197 :
case V_198 :
V_169 = 0 ;
break;
default:
V_169 = - V_176 ;
break;
}
break;
default:
V_169 = - V_176 ;
break;
}
return V_169 ;
}
static long F_94 ( struct V_7 * V_7 , struct V_232 * args )
{
T_5 * V_233 ;
T_6 V_234 ;
int V_10 , V_93 = 0 ;
if ( args -> V_155 != 0 )
return - V_91 ;
if ( ! F_95 ( V_141 -> V_140 ) )
return V_235 ;
if ( args -> V_236 < 1 || args -> V_236 > V_237 )
return - V_91 ;
V_233 = F_96 ( args -> V_236 , sizeof( T_5 ) , V_207 ) ;
if ( ! V_233 )
return - V_82 ;
F_97 ( & V_141 -> V_140 -> V_238 ) ;
for ( V_10 = 0 ; V_10 < args -> V_236 ; V_10 ++ ) {
V_234 = F_98 ( V_7 , args -> V_239 + V_10 ) ;
if ( F_99 ( V_234 ) ) {
V_93 = - V_175 ;
break;
}
V_93 = F_100 ( V_141 -> V_140 , V_234 , & V_233 [ V_10 ] ) ;
if ( V_93 )
break;
}
F_101 ( & V_141 -> V_140 -> V_238 ) ;
if ( ! V_93 ) {
V_93 = F_71 ( ( T_5 V_173 * ) args -> V_240 , V_233 ,
sizeof( T_5 ) * args -> V_236 ) ;
if ( V_93 )
V_93 = - V_175 ;
}
F_102 ( V_233 ) ;
return V_93 ;
}
static long F_103 ( struct V_7 * V_7 , struct V_232 * args )
{
T_5 * V_233 ;
T_6 V_234 ;
int V_10 , V_93 = 0 ;
if ( args -> V_155 != 0 )
return - V_91 ;
if ( args -> V_236 < 1 || args -> V_236 > V_237 )
return - V_91 ;
V_233 = F_96 ( args -> V_236 , sizeof( T_5 ) , V_207 ) ;
if ( ! V_233 )
return - V_82 ;
V_93 = F_66 ( V_233 , ( T_5 V_173 * ) args -> V_240 ,
sizeof( T_5 ) * args -> V_236 ) ;
if ( V_93 ) {
V_93 = - V_175 ;
goto V_149;
}
V_93 = F_104 () ;
if ( V_93 )
goto V_149;
F_97 ( & V_141 -> V_140 -> V_238 ) ;
for ( V_10 = 0 ; V_10 < args -> V_236 ; V_10 ++ ) {
V_234 = F_98 ( V_7 , args -> V_239 + V_10 ) ;
if ( F_99 ( V_234 ) ) {
V_93 = - V_175 ;
break;
}
if ( V_233 [ V_10 ] & 0x01 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_105 ( V_141 -> V_140 , V_234 , V_233 [ V_10 ] , 0 ) ;
if ( V_93 )
break;
}
F_101 ( & V_141 -> V_140 -> V_238 ) ;
V_149:
F_102 ( V_233 ) ;
return V_93 ;
}
long F_106 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_7 * V_7 = V_87 -> V_241 ;
void V_173 * V_242 = ( void V_173 * ) V_89 ;
struct V_167 V_168 ;
int V_93 ;
switch ( V_88 ) {
case V_243 : {
struct V_244 V_245 ;
V_93 = - V_175 ;
if ( F_66 ( & V_245 , V_242 , sizeof( V_245 ) ) )
break;
V_93 = F_107 ( V_7 , & V_245 ) ;
break;
}
case V_246 : {
struct V_153 V_154 ;
V_93 = - V_175 ;
if ( F_66 ( & V_154 , V_242 , sizeof( V_154 ) ) )
break;
V_93 = F_47 ( V_7 , & V_154 ) ;
break;
}
case V_247 : {
struct V_248 V_249 ;
V_93 = - V_91 ;
if ( V_7 -> V_12 . V_156 ) {
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
V_93 = F_108 ( V_7 , & V_249 , 0 , 0 ) ;
}
break;
}
case V_250 : {
V_93 = - V_175 ;
if ( F_66 ( & V_168 , ( void V_173 * ) V_89 , sizeof( V_168 ) ) )
break;
V_93 = F_91 ( V_7 , & V_168 ) ;
break;
}
case V_251 : {
V_93 = - V_175 ;
if ( F_66 ( & V_168 , ( void V_173 * ) V_89 , sizeof( V_168 ) ) )
break;
V_93 = F_92 ( V_7 , & V_168 ) ;
break;
}
case V_252 : {
V_93 = - V_175 ;
if ( F_66 ( & V_168 , ( void V_173 * ) V_89 , sizeof( V_168 ) ) )
break;
V_93 = F_93 ( V_7 , & V_168 ) ;
break;
}
case V_253 : {
struct V_232 args ;
V_93 = - V_175 ;
if ( F_66 ( & args , V_242 ,
sizeof( struct V_232 ) ) )
break;
V_93 = F_94 ( V_7 , & args ) ;
break;
}
case V_254 : {
struct V_232 args ;
V_93 = - V_175 ;
if ( F_66 ( & args , V_242 ,
sizeof( struct V_232 ) ) )
break;
V_93 = F_103 ( V_7 , & args ) ;
break;
}
default:
V_93 = - V_255 ;
}
return V_93 ;
}
static int F_109 ( T_3 * V_256 )
{
T_7 V_257 = 0x04000000UL ;
T_7 V_29 = 0 ;
memset ( V_256 , 0 , 128 ) ;
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
static int F_110 ( void )
{
T_3 V_256 [ 128 ] ;
int V_29 ;
if ( F_18 ( 12 ) ) {
V_29 = F_109 ( V_256 ) ;
if ( V_29 )
F_111 ( L_34 , V_29 ) ;
else
return V_256 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_112 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_190 . V_258 = ( V_259 ) ( unsigned long ) V_7 -> V_12 . V_190 . V_191 ;
if ( F_110 () )
V_7 -> V_12 . V_190 . V_258 |= V_260 ;
else
V_7 -> V_12 . V_190 . V_258 |= V_261 ;
}
static V_172 F_113 ( void )
{
struct V_208 V_208 ;
F_85 ( & V_208 ) ;
V_208 . V_262 = 0xff ;
return * ( ( V_172 * ) & V_208 ) ;
}
static void F_114 ( struct V_7 * V_7 )
{
if ( ! F_61 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_190 . V_191 = & V_7 -> V_12 . V_263 -> V_191 ;
F_112 ( V_7 ) ;
V_7 -> V_12 . V_190 . V_193 = 1 ;
V_7 -> V_12 . V_190 . V_196 = 1 ;
F_62 ( V_7 -> V_12 . V_190 . V_191 -> V_192 ,
sizeof( V_7 -> V_12 . V_190 . V_191 -> V_192 ) ) ;
F_62 ( V_7 -> V_12 . V_190 . V_191 -> V_195 ,
sizeof( V_7 -> V_12 . V_190 . V_191 -> V_195 ) ) ;
}
static void F_115 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_264 )
F_116 ( V_7 -> V_12 . V_265 , sizeof( struct V_266 ) ) ;
else
F_117 ( ( unsigned long ) ( V_7 -> V_12 . V_265 ) ) ;
V_7 -> V_12 . V_265 = NULL ;
}
int F_118 ( struct V_7 * V_7 , unsigned long type )
{
T_8 V_267 = V_207 ;
int V_10 , V_268 ;
char V_269 [ 16 ] ;
static unsigned long V_270 ;
V_268 = - V_91 ;
#ifdef F_30
if ( type & ~ V_271 )
goto V_272;
if ( ( type & V_271 ) && ( ! F_119 ( V_273 ) ) )
goto V_272;
#else
if ( type )
goto V_272;
#endif
V_268 = F_28 () ;
if ( V_268 )
goto V_272;
V_268 = - V_82 ;
F_120 ( & V_7 -> V_12 . V_274 , 5 * V_275 , 500 ) ;
V_7 -> V_12 . V_264 = 0 ;
if ( ! V_60 . V_62 )
V_267 |= V_276 ;
F_121 ( & V_7 -> V_12 . V_277 ) ;
V_7 -> V_12 . V_265 = (struct V_278 * ) F_122 ( V_267 ) ;
if ( ! V_7 -> V_12 . V_265 )
goto V_272;
F_123 ( & V_279 ) ;
V_270 += 16 ;
if ( V_270 + sizeof( struct V_278 ) > V_280 )
V_270 = 0 ;
V_7 -> V_12 . V_265 = (struct V_278 * )
( ( char * ) V_7 -> V_12 . V_265 + V_270 ) ;
F_124 ( & V_279 ) ;
sprintf ( V_269 , L_35 , V_141 -> V_281 ) ;
V_7 -> V_12 . V_282 = F_22 ( V_269 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_282 )
goto V_272;
V_7 -> V_12 . V_263 =
(struct V_263 * ) F_122 ( V_207 | V_276 ) ;
if ( ! V_7 -> V_12 . V_263 )
goto V_272;
memcpy ( V_7 -> V_12 . V_161 . V_162 , V_221 . V_222 ,
sizeof( V_221 . V_222 ) ) ;
for ( V_10 = 0 ; V_10 < V_283 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_161 . V_162 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_161 . V_162 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_161 . V_163 = V_7 -> V_12 . V_263 -> V_163 ;
memcpy ( V_7 -> V_12 . V_161 . V_163 , V_7 -> V_12 . V_161 . V_162 ,
V_210 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_162 , 74 ) ;
F_49 ( V_7 -> V_12 . V_161 . V_163 , 74 ) ;
V_7 -> V_12 . V_161 . V_208 = F_113 () ;
V_7 -> V_12 . V_161 . V_209 = V_60 . V_209 & 0x0fff ;
F_114 ( V_7 ) ;
F_125 ( & V_7 -> V_12 . V_284 . V_285 ) ;
V_7 -> V_12 . V_284 . V_286 = 0 ;
V_7 -> V_12 . V_284 . V_287 = 0 ;
F_126 ( & V_7 -> V_12 . V_284 . V_158 ) ;
for ( V_10 = 0 ; V_10 < V_288 ; V_10 ++ )
F_127 ( & V_7 -> V_12 . V_284 . V_289 [ V_10 ] ) ;
F_128 ( & V_7 -> V_12 . V_290 ) ;
F_125 ( & V_7 -> V_12 . V_291 ) ;
F_23 ( V_7 -> V_12 . V_282 , & V_83 ) ;
F_48 ( V_7 , 3 , L_36 , type ) ;
if ( type & V_271 ) {
V_7 -> V_12 . V_137 = NULL ;
V_7 -> V_12 . V_171 = V_184 ;
} else {
if ( V_60 . V_292 == V_293 )
V_7 -> V_12 . V_171 = V_294 ;
else
V_7 -> V_12 . V_171 = F_129 (unsigned long, TASK_SIZE_MAX,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_137 = F_58 ( V_141 -> V_140 , V_7 -> V_12 . V_171 - 1 ) ;
if ( ! V_7 -> V_12 . V_137 )
goto V_272;
V_7 -> V_12 . V_137 -> V_187 = V_7 ;
V_7 -> V_12 . V_137 -> V_295 = 0 ;
}
V_7 -> V_12 . V_296 = 0 ;
V_7 -> V_12 . V_156 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_126 ( & V_7 -> V_12 . V_297 ) ;
F_130 ( V_7 ) ;
F_131 ( 3 , L_37 , V_7 , V_141 -> V_281 ) ;
return 0 ;
V_272:
F_117 ( ( unsigned long ) V_7 -> V_12 . V_263 ) ;
F_24 ( V_7 -> V_12 . V_282 ) ;
F_115 ( V_7 ) ;
F_131 ( 3 , L_38 , V_268 ) ;
return V_268 ;
}
bool F_132 ( void )
{
return false ;
}
int F_133 ( struct V_8 * V_9 )
{
return 0 ;
}
void F_134 ( struct V_8 * V_9 )
{
F_135 ( V_9 , 3 , L_3 , L_39 ) ;
F_136 ( V_9 -> V_298 ) ;
F_137 ( V_9 ) ;
F_138 ( V_9 ) ;
if ( ! F_39 ( V_9 -> V_7 ) )
F_139 ( V_9 ) ;
if ( F_39 ( V_9 -> V_7 ) )
F_59 ( V_9 -> V_12 . V_137 ) ;
if ( V_9 -> V_7 -> V_12 . V_180 )
F_140 ( V_9 ) ;
F_117 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_141 ( V_9 ) ;
F_142 ( V_299 , V_9 ) ;
}
static void F_143 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_134 ( V_9 ) ;
F_40 ( & V_7 -> V_158 ) ;
for ( V_10 = 0 ; V_10 < F_50 ( & V_7 -> V_164 ) ; V_10 ++ )
V_7 -> V_300 [ V_10 ] = NULL ;
F_144 ( & V_7 -> V_164 , 0 ) ;
F_44 ( & V_7 -> V_158 ) ;
}
void F_145 ( struct V_7 * V_7 )
{
F_143 ( V_7 ) ;
F_115 ( V_7 ) ;
F_24 ( V_7 -> V_12 . V_282 ) ;
F_117 ( ( unsigned long ) V_7 -> V_12 . V_263 ) ;
if ( ! F_39 ( V_7 ) )
F_59 ( V_7 -> V_12 . V_137 ) ;
F_146 ( V_7 ) ;
F_147 ( V_7 ) ;
F_148 ( V_7 ) ;
F_131 ( 3 , L_40 , V_7 ) ;
}
static int F_149 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_137 = F_58 ( V_141 -> V_140 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_137 )
return - V_82 ;
V_9 -> V_12 . V_137 -> V_187 = V_9 -> V_7 ;
return 0 ;
}
static void F_139 ( struct V_8 * V_9 )
{
if ( ! F_31 () )
return;
F_150 ( & V_9 -> V_7 -> V_12 . V_277 ) ;
if ( V_9 -> V_7 -> V_12 . V_264 ) {
struct V_266 * V_265 = V_9 -> V_7 -> V_12 . V_265 ;
F_151 ( V_9 -> V_298 , ( unsigned long * ) V_265 -> V_301 ) ;
V_265 -> V_302 [ V_9 -> V_298 ] . V_303 = 0 ;
} else {
struct V_278 * V_265 = V_9 -> V_7 -> V_12 . V_265 ;
F_151 ( V_9 -> V_298 , ( unsigned long * ) & V_265 -> V_301 ) ;
V_265 -> V_302 [ V_9 -> V_298 ] . V_303 = 0 ;
}
F_152 ( & V_9 -> V_7 -> V_12 . V_277 ) ;
}
static void F_153 ( struct V_8 * V_9 )
{
if ( ! F_31 () ) {
struct V_278 * V_265 = V_9 -> V_7 -> V_12 . V_265 ;
V_9 -> V_12 . V_14 -> V_304 = ( V_259 ) ( ( ( V_305 ) V_265 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_306 = ( V_259 ) ( V_305 ) V_265 ;
}
F_150 ( & V_9 -> V_7 -> V_12 . V_277 ) ;
if ( V_9 -> V_7 -> V_12 . V_264 ) {
struct V_266 * V_265 = V_9 -> V_7 -> V_12 . V_265 ;
V_265 -> V_302 [ V_9 -> V_298 ] . V_303 = ( V_305 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_304 = ( V_259 ) ( ( ( V_305 ) V_265 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_306 = ( V_259 ) ( V_305 ) V_265 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_307 |= V_308 ;
F_15 ( V_9 -> V_298 , ( unsigned long * ) V_265 -> V_301 ) ;
} else {
struct V_278 * V_265 = V_9 -> V_7 -> V_12 . V_265 ;
V_265 -> V_302 [ V_9 -> V_298 ] . V_303 = ( V_305 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_304 = ( V_259 ) ( ( ( V_305 ) V_265 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_306 = ( V_259 ) ( V_305 ) V_265 ;
F_15 ( V_9 -> V_298 , ( unsigned long * ) & V_265 -> V_301 ) ;
}
F_152 ( & V_9 -> V_7 -> V_12 . V_277 ) ;
}
static inline void F_154 ( struct V_309 * V_310 , struct V_311 * V_312 )
{
V_310 -> V_303 = V_312 -> V_303 ;
V_310 -> V_313 . V_314 = V_312 -> V_313 . V_314 ;
V_310 -> V_313 . V_315 = V_312 -> V_313 . V_315 ;
}
static void F_155 ( struct V_266 * V_310 , struct V_278 * V_312 )
{
int V_10 ;
V_310 -> V_316 = V_312 -> V_316 ;
V_310 -> V_301 [ 0 ] = V_312 -> V_301 ;
for ( V_10 = 0 ; V_10 < V_121 ; V_10 ++ )
F_154 ( & V_310 -> V_302 [ V_10 ] , & V_312 -> V_302 [ V_10 ] ) ;
}
static int F_156 ( struct V_7 * V_7 )
{
struct V_278 * V_317 = V_7 -> V_12 . V_265 ;
struct V_266 * V_318 ;
struct V_8 * V_9 ;
unsigned int V_319 ;
T_7 V_306 , V_304 ;
V_318 = F_157 ( sizeof( * V_318 ) , V_207 | V_320 ) ;
if ( ! V_318 )
return - V_82 ;
V_304 = ( T_7 ) ( ( V_172 ) ( V_318 ) >> 32 ) ;
V_306 = ( T_7 ) ( V_172 ) ( V_318 ) & ~ 0x3fU ;
F_158 ( V_7 ) ;
F_159 ( & V_7 -> V_12 . V_277 ) ;
F_155 ( V_318 , V_317 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_304 = V_304 ;
V_9 -> V_12 . V_14 -> V_306 = V_306 ;
V_9 -> V_12 . V_14 -> V_307 |= V_308 ;
}
V_7 -> V_12 . V_265 = V_318 ;
V_7 -> V_12 . V_264 = 1 ;
F_160 ( & V_7 -> V_12 . V_277 ) ;
F_161 ( V_7 ) ;
F_117 ( ( unsigned long ) V_317 ) ;
F_48 ( V_7 , 2 , L_41 ,
V_317 , V_7 -> V_12 . V_265 ) ;
return 0 ;
}
static int F_162 ( struct V_7 * V_7 , unsigned int V_321 )
{
int V_268 ;
if ( ! F_31 () ) {
if ( V_321 < V_122 )
return true ;
return false ;
}
if ( V_321 < V_121 )
return true ;
if ( ! V_60 . V_123 || ! V_60 . V_62 )
return false ;
F_40 ( & V_7 -> V_158 ) ;
V_268 = V_7 -> V_12 . V_264 ? 0 : F_156 ( V_7 ) ;
F_44 ( & V_7 -> V_158 ) ;
return V_268 == 0 && V_321 < V_124 ;
}
int F_163 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_322 = V_323 ;
F_138 ( V_9 ) ;
V_9 -> V_324 -> V_325 = V_326 |
V_327 |
V_328 |
V_329 |
V_330 |
V_331 ;
F_164 ( V_9 , 0 ) ;
if ( F_61 ( V_9 -> V_7 , 64 ) )
V_9 -> V_324 -> V_325 |= V_332 ;
if ( F_61 ( V_9 -> V_7 , 133 ) )
V_9 -> V_324 -> V_325 |= V_333 ;
if ( V_129 )
V_9 -> V_324 -> V_325 |= V_334 ;
else
V_9 -> V_324 -> V_325 |= V_335 ;
if ( F_39 ( V_9 -> V_7 ) )
return F_149 ( V_9 ) ;
return 0 ;
}
static void F_165 ( struct V_8 * V_9 )
{
F_166 ( V_9 -> V_12 . V_16 != 0 ) ;
F_167 ( & V_9 -> V_12 . V_336 ) ;
V_9 -> V_12 . V_16 = F_168 () ;
F_169 ( & V_9 -> V_12 . V_336 ) ;
}
static void F_170 ( struct V_8 * V_9 )
{
F_166 ( V_9 -> V_12 . V_16 == 0 ) ;
F_167 ( & V_9 -> V_12 . V_336 ) ;
V_9 -> V_12 . V_14 -> V_337 -= F_168 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_169 ( & V_9 -> V_12 . V_336 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_166 ( V_9 -> V_12 . V_15 ) ;
V_9 -> V_12 . V_15 = true ;
F_165 ( V_9 ) ;
}
static void F_172 ( struct V_8 * V_9 )
{
F_166 ( ! V_9 -> V_12 . V_15 ) ;
F_170 ( V_9 ) ;
V_9 -> V_12 . V_15 = false ;
}
static void F_173 ( struct V_8 * V_9 )
{
F_174 () ;
F_171 ( V_9 ) ;
F_175 () ;
}
static void F_176 ( struct V_8 * V_9 )
{
F_174 () ;
F_172 ( V_9 ) ;
F_175 () ;
}
void F_177 ( struct V_8 * V_9 , V_305 V_337 )
{
F_174 () ;
F_167 ( & V_9 -> V_12 . V_336 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_168 () ;
V_9 -> V_12 . V_14 -> V_337 = V_337 ;
F_169 ( & V_9 -> V_12 . V_336 ) ;
F_175 () ;
}
V_305 F_178 ( struct V_8 * V_9 )
{
unsigned int V_338 ;
V_305 V_339 ;
if ( F_179 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_337 ;
F_174 () ;
do {
V_338 = F_180 ( & V_9 -> V_12 . V_336 ) ;
F_166 ( ( V_338 & 1 ) && F_181 () == V_9 -> V_302 ) ;
V_339 = V_9 -> V_12 . V_14 -> V_337 ;
if ( F_182 ( V_9 -> V_12 . V_16 ) )
V_339 -= F_168 () - V_9 -> V_12 . V_16 ;
} while ( F_183 ( & V_9 -> V_12 . V_336 , V_338 & ~ 1 ) );
F_175 () ;
return V_339 ;
}
void F_184 ( struct V_8 * V_9 , int V_302 )
{
F_185 ( V_9 -> V_12 . V_340 ) ;
F_186 ( V_341 , & V_9 -> V_12 . V_14 -> V_342 ) ;
if ( V_9 -> V_12 . V_15 && ! F_187 ( V_9 ) )
F_165 ( V_9 ) ;
V_9 -> V_302 = V_302 ;
}
void F_188 ( struct V_8 * V_9 )
{
V_9 -> V_302 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_187 ( V_9 ) )
F_170 ( V_9 ) ;
F_189 ( V_341 , & V_9 -> V_12 . V_14 -> V_342 ) ;
V_9 -> V_12 . V_340 = F_190 () ;
F_191 ( V_9 -> V_12 . V_340 ) ;
}
static void F_192 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_343 . V_344 = 0UL ;
V_9 -> V_12 . V_14 -> V_343 . V_174 = 0UL ;
F_164 ( V_9 , 0 ) ;
F_177 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_345 = 0UL ;
V_9 -> V_12 . V_14 -> V_346 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_347 , 0 , 16 * sizeof( V_305 ) ) ;
V_9 -> V_12 . V_14 -> V_347 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_347 [ 14 ] = 0xC2000000UL ;
F_193 () ;
V_141 -> V_348 . V_349 . V_350 = 0 ;
V_9 -> V_12 . V_14 -> V_351 = 1 ;
V_9 -> V_12 . V_14 -> V_352 = 0 ;
V_9 -> V_12 . V_322 = V_323 ;
F_138 ( V_9 ) ;
if ( ! F_194 ( V_9 -> V_7 ) )
F_195 ( V_9 ) ;
F_137 ( V_9 ) ;
}
void F_196 ( struct V_8 * V_9 )
{
F_40 ( & V_9 -> V_7 -> V_158 ) ;
F_174 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_175 () ;
F_44 ( & V_9 -> V_7 -> V_158 ) ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_137 = V_9 -> V_7 -> V_12 . V_137 ;
F_153 ( V_9 ) ;
}
if ( F_61 ( V_9 -> V_7 , 74 ) || V_9 -> V_7 -> V_12 . V_166 )
V_9 -> V_12 . V_14 -> V_353 |= V_354 ;
V_9 -> V_12 . V_340 = V_9 -> V_12 . V_137 ;
}
static void F_63 ( struct V_8 * V_9 )
{
if ( ! F_61 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_355 &= ~ ( V_356 | V_357 ) ;
if ( V_9 -> V_7 -> V_12 . V_190 . V_193 )
V_9 -> V_12 . V_14 -> V_355 |= V_356 ;
if ( V_9 -> V_7 -> V_12 . V_190 . V_196 )
V_9 -> V_12 . V_14 -> V_355 |= V_357 ;
V_9 -> V_12 . V_14 -> V_258 = V_9 -> V_7 -> V_12 . V_190 . V_258 ;
}
void F_140 ( struct V_8 * V_9 )
{
F_117 ( V_9 -> V_12 . V_14 -> V_358 ) ;
V_9 -> V_12 . V_14 -> V_358 = 0 ;
}
int F_197 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_358 = F_122 ( V_207 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_358 )
return - V_82 ;
V_9 -> V_12 . V_14 -> V_307 |= V_359 ;
V_9 -> V_12 . V_14 -> V_307 &= ~ V_360 ;
return 0 ;
}
static void F_198 ( struct V_8 * V_9 )
{
struct V_361 * V_161 = & V_9 -> V_7 -> V_12 . V_161 ;
V_9 -> V_12 . V_14 -> V_209 = V_161 -> V_209 ;
if ( F_61 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_362 = ( T_7 ) ( V_172 ) V_161 -> V_163 ;
}
int F_199 ( struct V_8 * V_9 )
{
int V_268 = 0 ;
F_144 ( & V_9 -> V_12 . V_14 -> V_342 , V_363 |
V_364 |
V_365 ) ;
if ( F_61 ( V_9 -> V_7 , 78 ) )
F_186 ( V_366 , & V_9 -> V_12 . V_14 -> V_342 ) ;
else if ( F_61 ( V_9 -> V_7 , 8 ) )
F_186 ( V_367 , & V_9 -> V_12 . V_14 -> V_342 ) ;
F_198 ( V_9 ) ;
if ( V_58 )
V_9 -> V_12 . V_14 -> V_368 |= V_369 ;
if ( F_61 ( V_9 -> V_7 , 9 ) )
V_9 -> V_12 . V_14 -> V_368 |= V_370 ;
if ( F_61 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_368 |= V_371 ;
if ( F_61 ( V_9 -> V_7 , 8 ) && V_60 . V_372 )
V_9 -> V_12 . V_14 -> V_307 |= V_360 ;
if ( F_61 ( V_9 -> V_7 , 130 ) )
V_9 -> V_12 . V_14 -> V_307 |= V_373 ;
V_9 -> V_12 . V_14 -> V_374 = V_375 | V_376 ;
if ( V_60 . V_74 )
V_9 -> V_12 . V_14 -> V_374 |= V_377 ;
if ( V_60 . V_72 )
V_9 -> V_12 . V_14 -> V_374 |= V_378 ;
if ( V_60 . V_66 )
V_9 -> V_12 . V_14 -> V_374 |= V_379 ;
if ( V_60 . V_380 )
V_9 -> V_12 . V_14 -> V_374 |= V_381 ;
if ( F_61 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_374 |= V_382 ;
V_9 -> V_12 . V_14 -> V_383 |= V_384 ;
}
V_9 -> V_12 . V_14 -> V_385 = ( ( unsigned long ) & V_9 -> V_324 -> V_312 . V_386 . V_387 )
| V_388 ;
V_9 -> V_12 . V_14 -> V_389 = ( unsigned long ) & V_9 -> V_324 -> V_312 . V_386 . V_390 ;
if ( V_60 . V_78 )
F_186 ( V_391 , & V_9 -> V_12 . V_14 -> V_342 ) ;
else
V_9 -> V_12 . V_14 -> V_353 |= V_392 | V_393 | V_394 ;
if ( V_9 -> V_7 -> V_12 . V_180 ) {
V_268 = F_197 ( V_9 ) ;
if ( V_268 )
return V_268 ;
}
F_200 ( & V_9 -> V_12 . V_395 , V_396 , V_397 ) ;
V_9 -> V_12 . V_395 . V_398 = V_399 ;
F_63 ( V_9 ) ;
return V_268 ;
}
struct V_8 * F_201 ( struct V_7 * V_7 ,
unsigned int V_321 )
{
struct V_8 * V_9 ;
struct V_400 * V_400 ;
int V_268 = - V_91 ;
if ( ! F_39 ( V_7 ) && ! F_162 ( V_7 , V_321 ) )
goto V_149;
V_268 = - V_82 ;
V_9 = F_202 ( V_299 , V_207 ) ;
if ( ! V_9 )
goto V_149;
V_400 = (struct V_400 * ) F_122 ( V_207 ) ;
if ( ! V_400 )
goto V_401;
V_9 -> V_12 . V_14 = & V_400 -> V_14 ;
V_9 -> V_12 . V_14 -> V_402 = ( unsigned long ) & V_400 -> V_403 ;
V_9 -> V_12 . V_14 -> V_404 = 0 ;
V_9 -> V_12 . V_14 -> V_405 = V_60 . V_292 ;
V_9 -> V_12 . V_14 -> V_406 = V_321 ;
F_126 ( & V_9 -> V_12 . V_407 . V_158 ) ;
V_9 -> V_12 . V_407 . V_284 = & V_7 -> V_12 . V_284 ;
V_9 -> V_12 . V_407 . V_408 = & V_9 -> V_408 ;
V_9 -> V_12 . V_407 . V_342 = & V_9 -> V_12 . V_14 -> V_342 ;
F_203 ( & V_9 -> V_12 . V_336 ) ;
V_268 = F_204 ( V_9 , V_7 , V_321 ) ;
if ( V_268 )
goto V_409;
F_48 ( V_7 , 3 , L_42 , V_321 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_205 ( V_321 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_409:
F_117 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_401:
F_142 ( V_299 , V_9 ) ;
V_149:
return F_206 ( V_268 ) ;
}
int F_207 ( struct V_8 * V_9 )
{
return F_208 ( V_9 , 0 ) ;
}
void F_209 ( struct V_8 * V_9 )
{
F_186 ( V_410 , & V_9 -> V_12 . V_14 -> V_411 ) ;
F_64 ( V_9 ) ;
}
void F_210 ( struct V_8 * V_9 )
{
F_189 ( V_410 , & V_9 -> V_12 . V_14 -> V_411 ) ;
}
static void F_211 ( struct V_8 * V_9 )
{
F_186 ( V_412 , & V_9 -> V_12 . V_14 -> V_411 ) ;
F_64 ( V_9 ) ;
}
static void F_212 ( struct V_8 * V_9 )
{
F_189 ( V_412 , & V_9 -> V_12 . V_14 -> V_411 ) ;
}
void F_64 ( struct V_8 * V_9 )
{
F_186 ( V_413 , & V_9 -> V_12 . V_14 -> V_342 ) ;
while ( V_9 -> V_12 . V_14 -> V_414 & V_415 )
F_213 () ;
}
void F_46 ( int V_416 , struct V_8 * V_9 )
{
F_214 ( V_416 , V_9 ) ;
F_211 ( V_9 ) ;
}
static void V_21 ( struct V_137 * V_137 , unsigned long V_417 ,
unsigned long V_418 )
{
struct V_7 * V_7 = V_137 -> V_187 ;
struct V_8 * V_9 ;
unsigned long V_419 ;
int V_10 ;
if ( F_215 ( V_137 ) )
return;
if ( V_417 >= 1UL << 31 )
return;
F_7 (i, vcpu, kvm) {
V_419 = F_216 ( V_9 ) ;
if ( V_419 <= V_418 && V_417 <= V_419 + 2 * V_280 - 1 ) {
F_135 ( V_9 , 2 , L_43 ,
V_417 , V_418 ) ;
F_46 ( V_420 , V_9 ) ;
}
}
}
int F_217 ( struct V_8 * V_9 )
{
F_218 () ;
return 0 ;
}
static int F_219 ( struct V_8 * V_9 ,
struct V_421 * V_422 )
{
int V_93 = - V_91 ;
switch ( V_422 -> V_321 ) {
case V_423 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_346 ,
( T_7 V_173 * ) V_422 -> V_174 ) ;
break;
case V_424 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_425 :
V_93 = F_52 ( F_178 ( V_9 ) ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_426 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_345 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_427 :
V_93 = F_52 ( V_9 -> V_12 . V_322 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_428 :
V_93 = F_52 ( V_9 -> V_12 . V_429 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_430 :
V_93 = F_52 ( V_9 -> V_12 . V_431 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_432 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_352 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_433 :
V_93 = F_52 ( V_9 -> V_12 . V_14 -> V_351 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
default:
break;
}
return V_93 ;
}
static int F_220 ( struct V_8 * V_9 ,
struct V_421 * V_422 )
{
int V_93 = - V_91 ;
V_305 V_5 ;
switch ( V_422 -> V_321 ) {
case V_423 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_346 ,
( T_7 V_173 * ) V_422 -> V_174 ) ;
break;
case V_424 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_425 :
V_93 = F_57 ( V_5 , ( V_172 V_173 * ) V_422 -> V_174 ) ;
if ( ! V_93 )
F_177 ( V_9 , V_5 ) ;
break;
case V_426 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_345 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_427 :
V_93 = F_57 ( V_9 -> V_12 . V_322 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
if ( V_9 -> V_12 . V_322 == V_323 )
F_138 ( V_9 ) ;
break;
case V_428 :
V_93 = F_57 ( V_9 -> V_12 . V_429 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_430 :
V_93 = F_57 ( V_9 -> V_12 . V_431 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_432 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_352 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
case V_433 :
V_93 = F_57 ( V_9 -> V_12 . V_14 -> V_351 ,
( V_172 V_173 * ) V_422 -> V_174 ) ;
break;
default:
break;
}
return V_93 ;
}
static int F_221 ( struct V_8 * V_9 )
{
F_192 ( V_9 ) ;
return 0 ;
}
int F_222 ( struct V_8 * V_9 , struct V_434 * V_386 )
{
memcpy ( & V_9 -> V_324 -> V_312 . V_386 . V_435 , & V_386 -> V_435 , sizeof( V_386 -> V_435 ) ) ;
return 0 ;
}
int F_223 ( struct V_8 * V_9 , struct V_434 * V_386 )
{
memcpy ( & V_386 -> V_435 , & V_9 -> V_324 -> V_312 . V_386 . V_435 , sizeof( V_386 -> V_435 ) ) ;
return 0 ;
}
int F_224 ( struct V_8 * V_9 ,
struct V_436 * V_437 )
{
memcpy ( & V_9 -> V_324 -> V_312 . V_386 . V_438 , & V_437 -> V_438 , sizeof( V_437 -> V_438 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_347 , & V_437 -> V_439 , sizeof( V_437 -> V_439 ) ) ;
return 0 ;
}
int F_225 ( struct V_8 * V_9 ,
struct V_436 * V_437 )
{
memcpy ( & V_437 -> V_438 , & V_9 -> V_324 -> V_312 . V_386 . V_438 , sizeof( V_437 -> V_438 ) ) ;
memcpy ( & V_437 -> V_439 , & V_9 -> V_12 . V_14 -> V_347 , sizeof( V_437 -> V_439 ) ) ;
return 0 ;
}
int F_226 ( struct V_8 * V_9 , struct V_440 * V_349 )
{
if ( F_227 ( V_349 -> V_350 ) )
return - V_91 ;
V_9 -> V_324 -> V_312 . V_386 . V_350 = V_349 -> V_350 ;
if ( V_129 )
F_228 ( ( V_441 * ) V_9 -> V_324 -> V_312 . V_386 . V_442 ,
( V_443 * ) V_349 -> V_444 ) ;
else
memcpy ( V_9 -> V_324 -> V_312 . V_386 . V_444 , & V_349 -> V_444 , sizeof( V_349 -> V_444 ) ) ;
return 0 ;
}
int F_229 ( struct V_8 * V_9 , struct V_440 * V_349 )
{
F_193 () ;
if ( V_129 )
F_230 ( ( V_443 * ) V_349 -> V_444 ,
( V_441 * ) V_9 -> V_324 -> V_312 . V_386 . V_442 ) ;
else
memcpy ( V_349 -> V_444 , V_9 -> V_324 -> V_312 . V_386 . V_444 , sizeof( V_349 -> V_444 ) ) ;
V_349 -> V_350 = V_9 -> V_324 -> V_312 . V_386 . V_350 ;
return 0 ;
}
static int F_231 ( struct V_8 * V_9 , T_9 V_445 )
{
int V_268 = 0 ;
if ( ! F_232 ( V_9 ) )
V_268 = - V_160 ;
else {
V_9 -> V_324 -> V_446 = V_445 . V_344 ;
V_9 -> V_324 -> V_447 = V_445 . V_174 ;
}
return V_268 ;
}
int F_233 ( struct V_8 * V_9 ,
struct V_448 * V_449 )
{
return - V_91 ;
}
int F_234 ( struct V_8 * V_9 ,
struct V_450 * V_451 )
{
int V_268 = 0 ;
V_9 -> V_452 = 0 ;
F_235 ( V_9 ) ;
if ( V_451 -> V_453 & ~ V_454 )
return - V_91 ;
if ( ! V_60 . V_68 )
return - V_91 ;
if ( V_451 -> V_453 & V_455 ) {
V_9 -> V_452 = V_451 -> V_453 ;
F_186 ( V_456 , & V_9 -> V_12 . V_14 -> V_342 ) ;
if ( V_451 -> V_453 & V_457 )
V_268 = F_236 ( V_9 , V_451 ) ;
} else {
F_189 ( V_456 , & V_9 -> V_12 . V_14 -> V_342 ) ;
V_9 -> V_12 . V_458 . V_459 = 0 ;
}
if ( V_268 ) {
V_9 -> V_452 = 0 ;
F_235 ( V_9 ) ;
F_189 ( V_456 , & V_9 -> V_12 . V_14 -> V_342 ) ;
}
return V_268 ;
}
int F_237 ( struct V_8 * V_9 ,
struct V_460 * V_461 )
{
return F_232 ( V_9 ) ? V_462 :
V_463 ;
}
int F_238 ( struct V_8 * V_9 ,
struct V_460 * V_461 )
{
int V_268 = 0 ;
V_9 -> V_7 -> V_12 . V_464 = 1 ;
switch ( V_461 -> V_461 ) {
case V_462 :
F_195 ( V_9 ) ;
break;
case V_463 :
F_239 ( V_9 ) ;
break;
case V_465 :
case V_466 :
default:
V_268 = - V_176 ;
}
return V_268 ;
}
static bool F_240 ( struct V_8 * V_9 )
{
return F_50 ( & V_9 -> V_12 . V_14 -> V_342 ) & V_467 ;
}
static int F_241 ( struct V_8 * V_9 )
{
V_468:
F_212 ( V_9 ) ;
if ( ! V_9 -> V_469 )
return 0 ;
if ( F_242 ( V_420 , V_9 ) ) {
int V_268 ;
V_268 = F_243 ( V_9 -> V_12 . V_137 ,
F_216 ( V_9 ) ,
V_280 * 2 , V_470 ) ;
if ( V_268 ) {
F_214 ( V_420 , V_9 ) ;
return V_268 ;
}
goto V_468;
}
if ( F_242 ( V_471 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_472 = 0xffff ;
goto V_468;
}
if ( F_242 ( V_473 , V_9 ) ) {
if ( ! F_240 ( V_9 ) ) {
F_244 ( V_9 -> V_298 , 1 ) ;
F_186 ( V_467 ,
& V_9 -> V_12 . V_14 -> V_342 ) ;
}
goto V_468;
}
if ( F_242 ( V_474 , V_9 ) ) {
if ( F_240 ( V_9 ) ) {
F_244 ( V_9 -> V_298 , 0 ) ;
F_189 ( V_467 ,
& V_9 -> V_12 . V_14 -> V_342 ) ;
}
goto V_468;
}
if ( F_242 ( V_152 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_353 |= V_354 ;
goto V_468;
}
F_245 ( V_475 , V_9 ) ;
return 0 ;
}
void F_68 ( struct V_7 * V_7 , V_172 V_476 )
{
struct V_8 * V_9 ;
int V_10 ;
F_40 ( & V_7 -> V_158 ) ;
F_174 () ;
V_7 -> V_12 . V_13 = V_476 - F_246 () ;
F_158 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_161 ( V_7 ) ;
F_175 () ;
F_44 ( & V_7 -> V_158 ) ;
}
long F_247 ( struct V_8 * V_9 , T_10 V_477 , int V_478 )
{
return F_248 ( V_9 -> V_12 . V_137 , V_477 ,
V_478 ? V_479 : 0 ) ;
}
static void F_249 ( struct V_8 * V_9 , bool V_480 ,
unsigned long V_481 )
{
struct V_244 V_482 ;
struct V_483 V_484 ;
if ( V_480 ) {
V_484 . V_485 . V_92 . V_486 = V_481 ;
V_484 . type = V_487 ;
F_166 ( F_250 ( V_9 , & V_484 ) ) ;
} else {
V_482 . type = V_488 ;
V_482 . V_489 = V_481 ;
F_166 ( F_107 ( V_9 -> V_7 , & V_482 ) ) ;
}
}
void F_251 ( struct V_8 * V_9 ,
struct V_490 * V_491 )
{
F_252 ( V_9 , V_491 -> V_12 . V_322 ) ;
F_249 ( V_9 , true , V_491 -> V_12 . V_322 ) ;
}
void F_253 ( struct V_8 * V_9 ,
struct V_490 * V_491 )
{
F_254 ( V_9 , V_491 -> V_12 . V_322 ) ;
F_249 ( V_9 , false , V_491 -> V_12 . V_322 ) ;
}
void F_255 ( struct V_8 * V_9 ,
struct V_490 * V_491 )
{
}
bool F_256 ( struct V_8 * V_9 )
{
return true ;
}
static int F_257 ( struct V_8 * V_9 )
{
T_11 V_234 ;
struct V_492 V_12 ;
int V_268 ;
if ( V_9 -> V_12 . V_322 == V_323 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_343 . V_344 & V_9 -> V_12 . V_431 ) !=
V_9 -> V_12 . V_429 )
return 0 ;
if ( F_258 ( V_9 ) )
return 0 ;
if ( F_208 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_347 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_137 -> V_295 )
return 0 ;
V_234 = F_98 ( V_9 -> V_7 , F_259 ( V_141 -> V_348 . V_493 ) ) ;
V_234 += V_141 -> V_348 . V_493 & ~ V_494 ;
if ( F_260 ( V_9 , V_9 -> V_12 . V_322 , & V_12 . V_322 , 8 ) )
return 0 ;
V_268 = F_261 ( V_9 , V_141 -> V_348 . V_493 , V_234 , & V_12 ) ;
return V_268 ;
}
static int F_262 ( struct V_8 * V_9 )
{
int V_268 , V_342 ;
F_263 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_495 = V_9 -> V_324 -> V_312 . V_386 . V_435 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_496 = V_9 -> V_324 -> V_312 . V_386 . V_435 [ 15 ] ;
if ( F_264 () )
F_265 () ;
if ( F_266 ( V_497 ) )
F_267 () ;
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_268 = F_268 ( V_9 ) ;
if ( V_268 )
return V_268 ;
}
V_268 = F_241 ( V_9 ) ;
if ( V_268 )
return V_268 ;
if ( F_269 ( V_9 ) ) {
F_270 ( V_9 ) ;
F_271 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_498 = 0 ;
V_342 = F_50 ( & V_9 -> V_12 . V_14 -> V_342 ) ;
F_135 ( V_9 , 6 , L_44 , V_342 ) ;
F_272 ( V_9 , V_342 ) ;
return 0 ;
}
static int F_273 ( struct V_8 * V_9 )
{
struct V_499 V_500 = {
. V_501 = V_502 ,
} ;
T_3 V_503 , V_504 ;
int V_268 ;
F_135 ( V_9 , 3 , L_3 , L_45 ) ;
F_274 ( V_9 ) ;
V_268 = F_275 ( V_9 , V_9 -> V_12 . V_14 -> V_343 . V_174 , & V_503 , 1 ) ;
V_504 = F_276 ( V_503 ) ;
if ( V_268 < 0 ) {
return V_268 ;
} else if ( V_268 ) {
V_500 = V_9 -> V_12 . V_505 ;
V_504 = 4 ;
}
V_500 . V_155 = V_504 | V_506 ;
F_277 ( V_9 , V_504 ) ;
return F_278 ( V_9 , & V_500 ) ;
}
static int F_279 ( struct V_8 * V_9 , int V_507 )
{
F_135 ( V_9 , 6 , L_46 ,
V_9 -> V_12 . V_14 -> V_498 ) ;
F_280 ( V_9 , V_9 -> V_12 . V_14 -> V_498 ) ;
if ( F_269 ( V_9 ) )
F_281 ( V_9 ) ;
V_9 -> V_324 -> V_312 . V_386 . V_435 [ 14 ] = V_9 -> V_12 . V_14 -> V_495 ;
V_9 -> V_324 -> V_312 . V_386 . V_435 [ 15 ] = V_9 -> V_12 . V_14 -> V_496 ;
if ( V_9 -> V_12 . V_14 -> V_498 > 0 ) {
int V_268 = F_282 ( V_9 ) ;
if ( V_268 != - V_508 )
return V_268 ;
V_9 -> V_324 -> V_507 = V_509 ;
V_9 -> V_324 -> V_510 . V_498 = V_9 -> V_12 . V_14 -> V_498 ;
V_9 -> V_324 -> V_510 . V_511 = V_9 -> V_12 . V_14 -> V_511 ;
V_9 -> V_324 -> V_510 . V_512 = V_9 -> V_12 . V_14 -> V_512 ;
return - V_513 ;
} else if ( V_507 != - V_175 ) {
V_9 -> V_514 . V_515 ++ ;
return 0 ;
} else if ( F_39 ( V_9 -> V_7 ) ) {
V_9 -> V_324 -> V_507 = V_516 ;
V_9 -> V_324 -> V_517 . V_518 =
V_141 -> V_348 . V_493 ;
V_9 -> V_324 -> V_517 . V_519 = 0x10 ;
return - V_513 ;
} else if ( V_141 -> V_348 . V_520 ) {
F_283 ( V_9 ) ;
V_141 -> V_348 . V_520 = 0 ;
if ( F_257 ( V_9 ) )
return 0 ;
return F_247 ( V_9 , V_141 -> V_348 . V_493 , 1 ) ;
}
return F_273 ( V_9 ) ;
}
static int F_284 ( struct V_8 * V_9 )
{
int V_268 , V_507 ;
V_9 -> V_521 = F_54 ( & V_9 -> V_7 -> V_182 ) ;
do {
V_268 = F_262 ( V_9 ) ;
if ( V_268 )
break;
F_56 ( & V_9 -> V_7 -> V_182 , V_9 -> V_521 ) ;
F_285 () ;
F_286 () ;
F_172 ( V_9 ) ;
F_287 () ;
V_507 = F_288 ( V_9 -> V_12 . V_14 ,
V_9 -> V_324 -> V_312 . V_386 . V_435 ) ;
F_285 () ;
F_171 ( V_9 ) ;
F_289 () ;
F_287 () ;
V_9 -> V_521 = F_54 ( & V_9 -> V_7 -> V_182 ) ;
V_268 = F_279 ( V_9 , V_507 ) ;
} while ( ! F_290 ( V_141 ) && ! F_291 ( V_9 ) && ! V_268 );
F_56 ( & V_9 -> V_7 -> V_182 , V_9 -> V_521 ) ;
return V_268 ;
}
static void F_292 ( struct V_8 * V_9 , struct V_522 * V_522 )
{
struct V_523 * V_390 ;
struct V_524 * V_525 ;
V_390 = (struct V_523 * ) & V_522 -> V_312 . V_386 . V_390 ;
V_525 = (struct V_524 * ) & V_522 -> V_312 . V_386 . V_525 ;
V_9 -> V_12 . V_14 -> V_343 . V_344 = V_522 -> V_446 ;
V_9 -> V_12 . V_14 -> V_343 . V_174 = V_522 -> V_447 ;
if ( V_522 -> V_526 & V_326 )
F_164 ( V_9 , V_522 -> V_312 . V_386 . V_419 ) ;
if ( V_522 -> V_526 & V_329 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_347 , & V_522 -> V_312 . V_386 . V_439 , 128 ) ;
F_214 ( V_471 , V_9 ) ;
}
if ( V_522 -> V_526 & V_330 ) {
F_177 ( V_9 , V_522 -> V_312 . V_386 . V_337 ) ;
V_9 -> V_12 . V_14 -> V_345 = V_522 -> V_312 . V_386 . V_345 ;
V_9 -> V_12 . V_14 -> V_346 = V_522 -> V_312 . V_386 . V_346 ;
V_9 -> V_12 . V_14 -> V_352 = V_522 -> V_312 . V_386 . V_352 ;
V_9 -> V_12 . V_14 -> V_351 = V_522 -> V_312 . V_386 . V_351 ;
}
if ( V_522 -> V_526 & V_331 ) {
V_9 -> V_12 . V_322 = V_522 -> V_312 . V_386 . V_527 ;
V_9 -> V_12 . V_431 = V_522 -> V_312 . V_386 . V_528 ;
V_9 -> V_12 . V_429 = V_522 -> V_312 . V_386 . V_529 ;
if ( V_9 -> V_12 . V_322 == V_323 )
F_138 ( V_9 ) ;
}
if ( ( V_522 -> V_526 & V_332 ) &&
F_61 ( V_9 -> V_7 , 64 ) &&
V_390 -> V_530 &&
! ( V_9 -> V_12 . V_14 -> V_355 & V_531 ) ) {
F_135 ( V_9 , 3 , L_3 , L_47 ) ;
V_9 -> V_12 . V_14 -> V_355 |= V_531 ;
}
if ( ( V_522 -> V_526 & V_333 ) &&
F_61 ( V_9 -> V_7 , 133 ) &&
V_525 -> V_532 &&
! V_9 -> V_12 . V_533 ) {
F_135 ( V_9 , 3 , L_3 , L_48 ) ;
V_9 -> V_12 . V_14 -> V_368 |= V_534 ;
V_9 -> V_12 . V_14 -> V_383 |= V_384 ;
V_9 -> V_12 . V_533 = 1 ;
}
F_293 ( V_9 -> V_12 . V_535 ) ;
F_294 ( V_9 -> V_324 -> V_312 . V_386 . V_438 ) ;
F_193 () ;
V_9 -> V_12 . V_536 . V_350 = V_141 -> V_348 . V_349 . V_350 ;
V_9 -> V_12 . V_536 . V_386 = V_141 -> V_348 . V_349 . V_386 ;
if ( V_129 )
V_141 -> V_348 . V_349 . V_386 = V_9 -> V_324 -> V_312 . V_386 . V_442 ;
else
V_141 -> V_348 . V_349 . V_386 = V_9 -> V_324 -> V_312 . V_386 . V_444 ;
V_141 -> V_348 . V_349 . V_350 = V_9 -> V_324 -> V_312 . V_386 . V_350 ;
if ( F_227 ( V_141 -> V_348 . V_349 . V_350 ) )
V_141 -> V_348 . V_349 . V_350 = 0 ;
if ( V_537 ) {
F_174 () ;
F_295 ( 2 , 4 ) ;
if ( V_141 -> V_348 . V_524 ) {
V_9 -> V_12 . V_538 = V_141 -> V_348 . V_524 ;
F_296 ( V_9 -> V_12 . V_538 ) ;
}
if ( V_9 -> V_12 . V_533 ) {
V_141 -> V_348 . V_524 = (struct V_524 * )
& V_9 -> V_324 -> V_312 . V_386 . V_525 ;
F_297 ( V_141 -> V_348 . V_524 ) ;
}
F_175 () ;
}
V_522 -> V_526 = 0 ;
}
static void F_298 ( struct V_8 * V_9 , struct V_522 * V_522 )
{
V_522 -> V_446 = V_9 -> V_12 . V_14 -> V_343 . V_344 ;
V_522 -> V_447 = V_9 -> V_12 . V_14 -> V_343 . V_174 ;
V_522 -> V_312 . V_386 . V_419 = F_216 ( V_9 ) ;
memcpy ( & V_522 -> V_312 . V_386 . V_439 , & V_9 -> V_12 . V_14 -> V_347 , 128 ) ;
V_522 -> V_312 . V_386 . V_337 = F_178 ( V_9 ) ;
V_522 -> V_312 . V_386 . V_345 = V_9 -> V_12 . V_14 -> V_345 ;
V_522 -> V_312 . V_386 . V_346 = V_9 -> V_12 . V_14 -> V_346 ;
V_522 -> V_312 . V_386 . V_352 = V_9 -> V_12 . V_14 -> V_352 ;
V_522 -> V_312 . V_386 . V_351 = V_9 -> V_12 . V_14 -> V_351 ;
V_522 -> V_312 . V_386 . V_527 = V_9 -> V_12 . V_322 ;
V_522 -> V_312 . V_386 . V_528 = V_9 -> V_12 . V_431 ;
V_522 -> V_312 . V_386 . V_529 = V_9 -> V_12 . V_429 ;
F_293 ( V_9 -> V_324 -> V_312 . V_386 . V_438 ) ;
F_294 ( V_9 -> V_12 . V_535 ) ;
F_193 () ;
V_9 -> V_324 -> V_312 . V_386 . V_350 = V_141 -> V_348 . V_349 . V_350 ;
V_141 -> V_348 . V_349 . V_350 = V_9 -> V_12 . V_536 . V_350 ;
V_141 -> V_348 . V_349 . V_386 = V_9 -> V_12 . V_536 . V_386 ;
if ( V_537 ) {
F_295 ( 2 , 4 ) ;
if ( V_9 -> V_12 . V_533 )
F_296 ( V_141 -> V_348 . V_524 ) ;
F_174 () ;
V_141 -> V_348 . V_524 = V_9 -> V_12 . V_538 ;
F_297 ( V_9 -> V_12 . V_538 ) ;
F_175 () ;
if ( ! V_9 -> V_12 . V_538 )
F_299 ( 2 , 4 ) ;
V_9 -> V_12 . V_538 = NULL ;
}
}
int F_300 ( struct V_8 * V_9 , struct V_522 * V_522 )
{
int V_268 ;
T_12 V_539 ;
if ( V_522 -> V_540 )
return - V_541 ;
if ( F_291 ( V_9 ) ) {
F_301 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_542 )
F_302 ( V_543 , & V_9 -> V_544 , & V_539 ) ;
if ( ! F_194 ( V_9 -> V_7 ) ) {
F_239 ( V_9 ) ;
} else if ( F_232 ( V_9 ) ) {
F_303 ( L_49 ,
V_9 -> V_298 ) ;
return - V_91 ;
}
F_292 ( V_9 , V_522 ) ;
F_173 ( V_9 ) ;
F_304 () ;
V_268 = F_284 ( V_9 ) ;
if ( F_290 ( V_141 ) && ! V_268 ) {
V_522 -> V_507 = V_545 ;
V_268 = - V_541 ;
}
if ( F_291 ( V_9 ) && ! V_268 ) {
F_301 ( V_9 ) ;
V_268 = 0 ;
}
if ( V_268 == - V_513 ) {
V_268 = 0 ;
}
F_176 ( V_9 ) ;
F_298 ( V_9 , V_522 ) ;
if ( V_9 -> V_542 )
F_302 ( V_543 , & V_539 , NULL ) ;
V_9 -> V_514 . V_546 ++ ;
return V_268 ;
}
int F_305 ( struct V_8 * V_9 , unsigned long V_477 )
{
unsigned char V_547 = 1 ;
V_443 V_444 [ V_548 ] ;
unsigned int V_549 ;
V_172 V_550 , V_337 ;
int V_268 ;
V_549 = F_216 ( V_9 ) ;
if ( V_477 == V_551 ) {
if ( F_306 ( V_9 , 163 , & V_547 , 1 ) )
return - V_175 ;
V_477 = 0 ;
} else if ( V_477 == V_552 ) {
if ( F_307 ( V_9 , 163 , & V_547 , 1 ) )
return - V_175 ;
V_477 = V_549 ;
} else
V_477 -= V_553 ;
if ( V_129 ) {
F_230 ( V_444 , ( V_441 * ) V_9 -> V_324 -> V_312 . V_386 . V_442 ) ;
V_268 = F_306 ( V_9 , V_477 + V_553 ,
V_444 , 128 ) ;
} else {
V_268 = F_306 ( V_9 , V_477 + V_553 ,
V_9 -> V_324 -> V_312 . V_386 . V_444 , 128 ) ;
}
V_268 |= F_306 ( V_9 , V_477 + V_554 ,
V_9 -> V_324 -> V_312 . V_386 . V_435 , 128 ) ;
V_268 |= F_306 ( V_9 , V_477 + V_555 ,
& V_9 -> V_12 . V_14 -> V_343 , 16 ) ;
V_268 |= F_306 ( V_9 , V_477 + V_556 ,
& V_549 , 4 ) ;
V_268 |= F_306 ( V_9 , V_477 + V_557 ,
& V_9 -> V_324 -> V_312 . V_386 . V_350 , 4 ) ;
V_268 |= F_306 ( V_9 , V_477 + V_558 ,
& V_9 -> V_12 . V_14 -> V_346 , 4 ) ;
V_337 = F_178 ( V_9 ) ;
V_268 |= F_306 ( V_9 , V_477 + V_559 ,
& V_337 , 8 ) ;
V_550 = V_9 -> V_12 . V_14 -> V_345 >> 8 ;
V_268 |= F_306 ( V_9 , V_477 + V_560 ,
& V_550 , 8 ) ;
V_268 |= F_306 ( V_9 , V_477 + V_561 ,
& V_9 -> V_324 -> V_312 . V_386 . V_438 , 64 ) ;
V_268 |= F_306 ( V_9 , V_477 + V_562 ,
& V_9 -> V_12 . V_14 -> V_347 , 128 ) ;
return V_268 ? - V_175 : 0 ;
}
int F_308 ( struct V_8 * V_9 , unsigned long V_174 )
{
F_193 () ;
V_9 -> V_324 -> V_312 . V_386 . V_350 = V_141 -> V_348 . V_349 . V_350 ;
F_293 ( V_9 -> V_324 -> V_312 . V_386 . V_438 ) ;
return F_305 ( V_9 , V_174 ) ;
}
static void F_309 ( struct V_8 * V_9 )
{
F_242 ( V_473 , V_9 ) ;
F_46 ( V_474 , V_9 ) ;
}
static void F_310 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_309 ( V_9 ) ;
}
}
static void F_311 ( struct V_8 * V_9 )
{
if ( ! V_60 . V_76 )
return;
F_242 ( V_474 , V_9 ) ;
F_46 ( V_473 , V_9 ) ;
}
void F_239 ( struct V_8 * V_9 )
{
int V_10 , V_164 , V_563 = 0 ;
if ( ! F_232 ( V_9 ) )
return;
F_312 ( V_9 -> V_298 , 1 ) ;
F_123 ( & V_9 -> V_7 -> V_12 . V_297 ) ;
V_164 = F_50 ( & V_9 -> V_7 -> V_164 ) ;
for ( V_10 = 0 ; V_10 < V_164 ; V_10 ++ ) {
if ( ! F_232 ( V_9 -> V_7 -> V_300 [ V_10 ] ) )
V_563 ++ ;
}
if ( V_563 == 0 ) {
F_311 ( V_9 ) ;
} else if ( V_563 == 1 ) {
F_310 ( V_9 -> V_7 ) ;
}
F_189 ( V_365 , & V_9 -> V_12 . V_14 -> V_342 ) ;
F_214 ( V_471 , V_9 ) ;
F_124 ( & V_9 -> V_7 -> V_12 . V_297 ) ;
return;
}
void F_195 ( struct V_8 * V_9 )
{
int V_10 , V_164 , V_563 = 0 ;
struct V_8 * V_564 = NULL ;
if ( F_232 ( V_9 ) )
return;
F_312 ( V_9 -> V_298 , 0 ) ;
F_123 ( & V_9 -> V_7 -> V_12 . V_297 ) ;
V_164 = F_50 ( & V_9 -> V_7 -> V_164 ) ;
F_313 ( V_9 ) ;
F_186 ( V_365 , & V_9 -> V_12 . V_14 -> V_342 ) ;
F_309 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_164 ; V_10 ++ ) {
if ( ! F_232 ( V_9 -> V_7 -> V_300 [ V_10 ] ) ) {
V_563 ++ ;
V_564 = V_9 -> V_7 -> V_300 [ V_10 ] ;
}
}
if ( V_563 == 1 ) {
F_311 ( V_564 ) ;
}
F_124 ( & V_9 -> V_7 -> V_12 . V_297 ) ;
return;
}
static int F_314 ( struct V_8 * V_9 ,
struct V_153 * V_154 )
{
int V_93 ;
if ( V_154 -> V_155 )
return - V_91 ;
switch ( V_154 -> V_154 ) {
case V_102 :
if ( ! V_9 -> V_7 -> V_12 . V_296 ) {
V_9 -> V_7 -> V_12 . V_296 = 1 ;
F_48 ( V_9 -> V_7 , 3 , L_3 , L_50 ) ;
F_315 ( V_9 -> V_7 ) ;
}
V_93 = 0 ;
break;
default:
V_93 = - V_91 ;
break;
}
return V_93 ;
}
static long F_316 ( struct V_8 * V_9 ,
struct V_565 * V_566 )
{
void V_173 * V_567 = ( void V_173 * ) V_566 -> V_568 ;
void * V_569 = NULL ;
int V_93 , V_521 ;
const V_172 V_570 = V_571
| V_572 ;
if ( V_566 -> V_155 & ~ V_570 )
return - V_91 ;
if ( V_566 -> V_573 > V_118 )
return - V_185 ;
if ( ! ( V_566 -> V_155 & V_572 ) ) {
V_569 = F_317 ( V_566 -> V_573 ) ;
if ( ! V_569 )
return - V_82 ;
}
V_521 = F_54 ( & V_9 -> V_7 -> V_182 ) ;
switch ( V_566 -> V_574 ) {
case V_575 :
if ( V_566 -> V_155 & V_572 ) {
V_93 = F_318 ( V_9 , V_566 -> V_576 , V_566 -> V_577 ,
V_566 -> V_573 , V_578 ) ;
break;
}
V_93 = F_319 ( V_9 , V_566 -> V_576 , V_566 -> V_577 , V_569 , V_566 -> V_573 ) ;
if ( V_93 == 0 ) {
if ( F_71 ( V_567 , V_569 , V_566 -> V_573 ) )
V_93 = - V_175 ;
}
break;
case V_579 :
if ( V_566 -> V_155 & V_572 ) {
V_93 = F_318 ( V_9 , V_566 -> V_576 , V_566 -> V_577 ,
V_566 -> V_573 , V_580 ) ;
break;
}
if ( F_66 ( V_569 , V_567 , V_566 -> V_573 ) ) {
V_93 = - V_175 ;
break;
}
V_93 = F_320 ( V_9 , V_566 -> V_576 , V_566 -> V_577 , V_569 , V_566 -> V_573 ) ;
break;
default:
V_93 = - V_91 ;
}
F_56 ( & V_9 -> V_7 -> V_182 , V_521 ) ;
if ( V_93 > 0 && ( V_566 -> V_155 & V_571 ) != 0 )
F_278 ( V_9 , & V_9 -> V_12 . V_505 ) ;
F_321 ( V_569 ) ;
return V_93 ;
}
long F_322 ( struct V_86 * V_87 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_8 * V_9 = V_87 -> V_241 ;
void V_173 * V_242 = ( void V_173 * ) V_89 ;
int V_177 ;
long V_93 ;
switch ( V_88 ) {
case V_581 : {
struct V_483 V_582 ;
V_93 = - V_175 ;
if ( F_66 ( & V_582 , V_242 , sizeof( V_582 ) ) )
break;
V_93 = F_250 ( V_9 , & V_582 ) ;
break;
}
case V_243 : {
struct V_244 V_245 ;
struct V_483 V_582 ;
V_93 = - V_175 ;
if ( F_66 ( & V_245 , V_242 , sizeof( V_245 ) ) )
break;
if ( F_323 ( & V_245 , & V_582 ) )
return - V_91 ;
V_93 = F_250 ( V_9 , & V_582 ) ;
break;
}
case V_583 :
V_177 = F_54 ( & V_9 -> V_7 -> V_182 ) ;
V_93 = F_308 ( V_9 , V_89 ) ;
F_56 ( & V_9 -> V_7 -> V_182 , V_177 ) ;
break;
case V_584 : {
T_9 V_445 ;
V_93 = - V_175 ;
if ( F_66 ( & V_445 , V_242 , sizeof( V_445 ) ) )
break;
V_93 = F_231 ( V_9 , V_445 ) ;
break;
}
case V_585 :
V_93 = F_221 ( V_9 ) ;
break;
case V_586 :
case V_587 : {
struct V_421 V_422 ;
V_93 = - V_175 ;
if ( F_66 ( & V_422 , V_242 , sizeof( V_422 ) ) )
break;
if ( V_88 == V_586 )
V_93 = F_220 ( V_9 , & V_422 ) ;
else
V_93 = F_219 ( V_9 , & V_422 ) ;
break;
}
#ifdef F_30
case V_588 : {
struct V_589 V_590 ;
if ( F_66 ( & V_590 , V_242 , sizeof( V_590 ) ) ) {
V_93 = - V_175 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_93 = - V_91 ;
break;
}
V_93 = F_324 ( V_9 -> V_12 . V_137 , V_590 . V_591 ,
V_590 . V_592 , V_590 . V_593 ) ;
break;
}
case V_594 : {
struct V_589 V_590 ;
if ( F_66 ( & V_590 , V_242 , sizeof( V_590 ) ) ) {
V_93 = - V_175 ;
break;
}
if ( ! F_39 ( V_9 -> V_7 ) ) {
V_93 = - V_91 ;
break;
}
V_93 = F_325 ( V_9 -> V_12 . V_137 , V_590 . V_592 ,
V_590 . V_593 ) ;
break;
}
#endif
case V_595 : {
V_93 = F_248 ( V_9 -> V_12 . V_137 , V_89 , 0 ) ;
break;
}
case V_246 :
{
struct V_153 V_154 ;
V_93 = - V_175 ;
if ( F_66 ( & V_154 , V_242 , sizeof( V_154 ) ) )
break;
V_93 = F_314 ( V_9 , & V_154 ) ;
break;
}
case V_596 : {
struct V_565 V_597 ;
if ( F_66 ( & V_597 , V_242 , sizeof( V_597 ) ) == 0 )
V_93 = F_316 ( V_9 , & V_597 ) ;
else
V_93 = - V_175 ;
break;
}
case V_598 : {
struct V_599 V_600 ;
V_93 = - V_175 ;
if ( F_66 ( & V_600 , V_242 , sizeof( V_600 ) ) )
break;
if ( V_600 . V_601 > V_602 ||
V_600 . V_601 == 0 ||
V_600 . V_601 % sizeof( struct V_483 ) > 0 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_326 ( V_9 ,
( void V_173 * ) V_600 . V_568 ,
V_600 . V_601 ) ;
break;
}
case V_603 : {
struct V_599 V_600 ;
V_93 = - V_175 ;
if ( F_66 ( & V_600 , V_242 , sizeof( V_600 ) ) )
break;
if ( V_600 . V_601 == 0 ) {
V_93 = - V_91 ;
break;
}
V_93 = F_327 ( V_9 ,
( V_604 V_173 * ) V_600 . V_568 ,
V_600 . V_601 ) ;
break;
}
default:
V_93 = - V_255 ;
}
return V_93 ;
}
int F_328 ( struct V_8 * V_9 , struct V_605 * V_606 )
{
#ifdef F_30
if ( ( V_606 -> V_607 == V_608 )
&& ( F_39 ( V_9 -> V_7 ) ) ) {
V_606 -> V_609 = F_329 ( V_9 -> V_12 . V_14 ) ;
F_330 ( V_606 -> V_609 ) ;
return 0 ;
}
#endif
return V_610 ;
}
int F_331 ( struct V_7 * V_7 , struct V_132 * V_148 ,
unsigned long V_139 )
{
return 0 ;
}
int F_332 ( struct V_7 * V_7 ,
struct V_132 * V_133 ,
const struct V_611 * V_612 ,
enum V_613 V_614 )
{
if ( V_612 -> V_615 & 0xffffful )
return - V_91 ;
if ( V_612 -> V_616 & 0xffffful )
return - V_91 ;
if ( V_612 -> V_617 + V_612 -> V_616 > V_7 -> V_12 . V_171 )
return - V_91 ;
return 0 ;
}
void F_333 ( struct V_7 * V_7 ,
const struct V_611 * V_612 ,
const struct V_132 * V_618 ,
const struct V_132 * V_186 ,
enum V_613 V_614 )
{
int V_268 ;
if ( V_618 -> V_615 == V_612 -> V_615 &&
V_618 -> V_138 * V_280 == V_612 -> V_617 &&
V_618 -> V_139 * V_280 == V_612 -> V_616 )
return;
V_268 = F_324 ( V_7 -> V_12 . V_137 , V_612 -> V_615 ,
V_612 -> V_617 , V_612 -> V_616 ) ;
if ( V_268 )
F_334 ( L_51 ) ;
return;
}
static inline unsigned long F_335 ( int V_10 )
{
unsigned int V_619 = ( V_60 . V_620 << V_10 * 2 ) >> 30 ;
return 0x0000ffffffffffffUL >> ( V_619 << 4 ) ;
}
void F_336 ( struct V_8 * V_9 )
{
V_9 -> V_621 = false ;
}
static int T_13 F_337 ( void )
{
int V_10 ;
if ( ! V_60 . V_61 ) {
F_338 ( L_52 ) ;
return - V_622 ;
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_1 [ V_10 ] |=
V_221 . V_222 [ V_10 ] & F_335 ( V_10 ) ;
return F_339 ( NULL , sizeof( struct V_8 ) , 0 , V_623 ) ;
}
static void T_14 F_340 ( void )
{
F_341 () ;
}
