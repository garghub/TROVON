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
int V_29 = 3 ;
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
V_89 = 1 ;
break;
case V_111 :
V_89 = V_112 ;
break;
case V_113 :
case V_114 :
V_89 = V_115 ;
if ( ! F_31 () )
V_89 = V_116 ;
else if ( V_58 . V_117 && V_58 . V_60 )
V_89 = V_118 ;
break;
case V_119 :
V_89 = V_120 ;
break;
case V_121 :
V_89 = V_56 ;
break;
case V_122 :
V_89 = V_123 ;
break;
case V_124 :
V_89 = F_18 ( 64 ) ;
break;
default:
V_89 = 0 ;
}
return V_89 ;
}
static void F_32 ( struct V_7 * V_7 ,
struct V_125 * V_126 )
{
T_2 V_127 , V_128 ;
unsigned long V_129 ;
struct V_130 * V_130 = V_7 -> V_12 . V_130 ;
V_128 = V_126 -> V_131 + V_126 -> V_132 ;
for ( V_127 = V_126 -> V_131 ; V_127 <= V_128 ; V_127 ++ ) {
V_129 = F_33 ( V_126 , V_127 ) ;
if ( F_34 ( V_130 -> V_133 , V_129 ) )
F_35 ( V_7 , V_127 ) ;
if ( F_36 ( V_134 ) )
return;
F_37 () ;
}
}
int F_38 ( struct V_7 * V_7 ,
struct V_135 * log )
{
int V_89 ;
unsigned long V_136 ;
struct V_137 * V_138 ;
struct V_125 * V_126 ;
int V_139 = 0 ;
F_39 ( & V_7 -> V_140 ) ;
V_89 = - V_87 ;
if ( log -> V_141 >= V_120 )
goto V_142;
V_138 = V_137 ( V_7 ) ;
V_126 = F_40 ( V_138 , log -> V_141 ) ;
V_89 = - V_143 ;
if ( ! V_126 -> V_144 )
goto V_142;
F_32 ( V_7 , V_126 ) ;
V_89 = F_41 ( V_7 , log , & V_139 ) ;
if ( V_89 )
goto V_142;
if ( V_139 ) {
V_136 = F_42 ( V_126 ) ;
memset ( V_126 -> V_144 , 0 , V_136 ) ;
}
V_89 = 0 ;
V_142:
F_43 ( & V_7 -> V_140 ) ;
return V_89 ;
}
static void F_44 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_45 ( V_145 , V_9 ) ;
}
}
static int F_46 ( struct V_7 * V_7 , struct V_146 * V_147 )
{
int V_89 ;
if ( V_147 -> V_148 )
return - V_87 ;
switch ( V_147 -> V_147 ) {
case V_102 :
F_47 ( V_7 , 3 , L_3 , L_4 ) ;
V_7 -> V_12 . V_149 = 1 ;
V_89 = 0 ;
break;
case V_106 :
F_47 ( V_7 , 3 , L_3 , L_5 ) ;
V_7 -> V_12 . V_150 = 1 ;
V_89 = 0 ;
break;
case V_122 :
F_39 ( & V_7 -> V_151 ) ;
if ( V_7 -> V_152 ) {
V_89 = - V_153 ;
} else if ( V_123 ) {
F_48 ( V_7 -> V_12 . V_154 . V_155 , 129 ) ;
F_48 ( V_7 -> V_12 . V_154 . V_156 , 129 ) ;
V_89 = 0 ;
} else
V_89 = - V_87 ;
F_43 ( & V_7 -> V_151 ) ;
F_47 ( V_7 , 3 , L_6 ,
V_89 ? L_7 : L_8 ) ;
break;
case V_124 :
V_89 = - V_87 ;
F_39 ( & V_7 -> V_151 ) ;
if ( V_7 -> V_152 ) {
V_89 = - V_153 ;
} else if ( F_18 ( 64 ) ) {
F_48 ( V_7 -> V_12 . V_154 . V_155 , 64 ) ;
F_48 ( V_7 -> V_12 . V_154 . V_156 , 64 ) ;
V_89 = 0 ;
}
F_43 ( & V_7 -> V_151 ) ;
F_47 ( V_7 , 3 , L_9 ,
V_89 ? L_7 : L_8 ) ;
break;
case V_107 :
F_47 ( V_7 , 3 , L_3 , L_10 ) ;
V_7 -> V_12 . V_157 = 1 ;
V_89 = 0 ;
break;
case V_110 :
F_47 ( V_7 , 3 , L_3 , L_11 ) ;
V_7 -> V_12 . V_158 = 1 ;
F_44 ( V_7 ) ;
V_89 = 0 ;
break;
default:
V_89 = - V_87 ;
break;
}
return V_89 ;
}
static int F_49 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 ;
switch ( V_160 -> V_160 ) {
case V_162 :
V_161 = 0 ;
F_47 ( V_7 , 3 , L_12 ,
V_7 -> V_12 . V_163 ) ;
if ( F_50 ( V_7 -> V_12 . V_163 , ( V_164 V_165 * ) V_160 -> V_166 ) )
V_161 = - V_167 ;
break;
default:
V_161 = - V_168 ;
break;
}
return V_161 ;
}
static int F_51 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 ;
unsigned int V_169 ;
switch ( V_160 -> V_160 ) {
case V_170 :
V_161 = - V_168 ;
if ( ! V_58 . V_171 )
break;
V_161 = - V_153 ;
F_47 ( V_7 , 3 , L_3 , L_13 ) ;
F_39 ( & V_7 -> V_151 ) ;
if ( ! V_7 -> V_152 ) {
V_7 -> V_12 . V_172 = 1 ;
V_161 = 0 ;
}
F_43 ( & V_7 -> V_151 ) ;
break;
case V_173 :
V_161 = - V_168 ;
if ( ! V_58 . V_171 )
break;
V_161 = - V_87 ;
if ( ! V_7 -> V_12 . V_172 )
break;
F_47 ( V_7 , 3 , L_3 , L_14 ) ;
F_39 ( & V_7 -> V_151 ) ;
V_169 = F_52 ( & V_7 -> V_174 ) ;
F_53 ( V_7 -> V_12 . V_130 -> V_133 ) ;
F_54 ( & V_7 -> V_174 , V_169 ) ;
F_43 ( & V_7 -> V_151 ) ;
V_161 = 0 ;
break;
case V_162 : {
unsigned long V_175 ;
if ( F_55 ( V_7 ) )
return - V_87 ;
if ( F_56 ( V_175 , ( V_164 V_165 * ) V_160 -> V_166 ) )
return - V_167 ;
if ( V_7 -> V_12 . V_163 != V_176 &&
V_175 > V_7 -> V_12 . V_163 )
return - V_177 ;
if ( ! V_175 )
return - V_87 ;
if ( V_175 != V_176 )
V_175 -= 1 ;
V_161 = - V_153 ;
F_39 ( & V_7 -> V_151 ) ;
if ( ! V_7 -> V_152 ) {
struct V_130 * V_178 = F_57 ( V_134 -> V_133 , V_175 ) ;
if ( ! V_178 ) {
V_161 = - V_78 ;
} else {
F_58 ( V_7 -> V_12 . V_130 ) ;
V_178 -> V_179 = V_7 ;
V_7 -> V_12 . V_130 = V_178 ;
V_161 = 0 ;
}
}
F_43 ( & V_7 -> V_151 ) ;
F_47 ( V_7 , 3 , L_15 , V_175 ) ;
F_47 ( V_7 , 3 , L_16 ,
( void * ) V_7 -> V_12 . V_130 -> V_180 ) ;
break;
}
default:
V_161 = - V_168 ;
break;
}
return V_161 ;
}
static int F_59 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_60 ( V_7 , 76 ) )
return - V_87 ;
F_39 ( & V_7 -> V_151 ) ;
switch ( V_160 -> V_160 ) {
case V_181 :
F_61 (
V_7 -> V_12 . V_182 . V_183 -> V_184 ,
sizeof( V_7 -> V_12 . V_182 . V_183 -> V_184 ) ) ;
V_7 -> V_12 . V_182 . V_185 = 1 ;
F_47 ( V_7 , 3 , L_3 , L_17 ) ;
break;
case V_186 :
F_61 (
V_7 -> V_12 . V_182 . V_183 -> V_187 ,
sizeof( V_7 -> V_12 . V_182 . V_183 -> V_187 ) ) ;
V_7 -> V_12 . V_182 . V_188 = 1 ;
F_47 ( V_7 , 3 , L_3 , L_18 ) ;
break;
case V_189 :
V_7 -> V_12 . V_182 . V_185 = 0 ;
memset ( V_7 -> V_12 . V_182 . V_183 -> V_184 , 0 ,
sizeof( V_7 -> V_12 . V_182 . V_183 -> V_184 ) ) ;
F_47 ( V_7 , 3 , L_3 , L_19 ) ;
break;
case V_190 :
V_7 -> V_12 . V_182 . V_188 = 0 ;
memset ( V_7 -> V_12 . V_182 . V_183 -> V_187 , 0 ,
sizeof( V_7 -> V_12 . V_182 . V_183 -> V_187 ) ) ;
F_47 ( V_7 , 3 , L_3 , L_20 ) ;
break;
default:
F_43 ( & V_7 -> V_151 ) ;
return - V_168 ;
}
F_7 (i, vcpu, kvm) {
F_62 ( V_9 ) ;
F_63 ( V_9 ) ;
}
F_43 ( & V_7 -> V_151 ) ;
return 0 ;
}
static int F_64 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
T_3 V_191 ;
if ( F_65 ( & V_191 , ( void V_165 * ) V_160 -> V_166 ,
sizeof( V_191 ) ) )
return - V_167 ;
if ( V_191 != 0 )
return - V_87 ;
F_47 ( V_7 , 3 , L_21 , V_191 ) ;
return 0 ;
}
static int F_66 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
V_164 V_192 ;
if ( F_65 ( & V_192 , ( void V_165 * ) V_160 -> V_166 , sizeof( V_192 ) ) )
return - V_167 ;
F_67 ( V_7 , V_192 ) ;
F_47 ( V_7 , 3 , L_22 , V_192 ) ;
return 0 ;
}
static int F_68 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 ;
if ( V_160 -> V_148 )
return - V_87 ;
switch ( V_160 -> V_160 ) {
case V_193 :
V_161 = F_64 ( V_7 , V_160 ) ;
break;
case V_194 :
V_161 = F_66 ( V_7 , V_160 ) ;
break;
default:
V_161 = - V_168 ;
break;
}
return V_161 ;
}
static int F_69 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
T_3 V_191 = 0 ;
if ( F_70 ( ( void V_165 * ) V_160 -> V_166 , & V_191 ,
sizeof( V_191 ) ) )
return - V_167 ;
F_47 ( V_7 , 3 , L_23 , V_191 ) ;
return 0 ;
}
static int F_71 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
V_164 V_192 ;
V_192 = F_72 ( V_7 ) ;
if ( F_70 ( ( void V_165 * ) V_160 -> V_166 , & V_192 , sizeof( V_192 ) ) )
return - V_167 ;
F_47 ( V_7 , 3 , L_24 , V_192 ) ;
return 0 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 ;
if ( V_160 -> V_148 )
return - V_87 ;
switch ( V_160 -> V_160 ) {
case V_193 :
V_161 = F_69 ( V_7 , V_160 ) ;
break;
case V_194 :
V_161 = F_71 ( V_7 , V_160 ) ;
break;
default:
V_161 = - V_168 ;
break;
}
return V_161 ;
}
static int F_74 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
struct V_195 * V_196 ;
T_4 V_197 , V_198 ;
int V_161 = 0 ;
F_39 ( & V_7 -> V_151 ) ;
if ( V_7 -> V_152 ) {
V_161 = - V_153 ;
goto V_142;
}
V_196 = F_75 ( sizeof( * V_196 ) , V_199 ) ;
if ( ! V_196 ) {
V_161 = - V_78 ;
goto V_142;
}
if ( ! F_65 ( V_196 , ( void V_165 * ) V_160 -> V_166 ,
sizeof( * V_196 ) ) ) {
V_7 -> V_12 . V_154 . V_200 = V_196 -> V_200 ;
V_197 = V_58 . V_201 >> 16 & 0xfff ;
V_198 = V_58 . V_201 & 0xfff ;
if ( V_197 && V_196 -> V_201 ) {
if ( V_196 -> V_201 > V_198 )
V_7 -> V_12 . V_154 . V_201 = V_198 ;
else if ( V_196 -> V_201 < V_197 )
V_7 -> V_12 . V_154 . V_201 = V_197 ;
else
V_7 -> V_12 . V_154 . V_201 = V_196 -> V_201 ;
}
memcpy ( V_7 -> V_12 . V_154 . V_156 , V_196 -> V_156 ,
V_202 ) ;
} else
V_161 = - V_167 ;
F_76 ( V_196 ) ;
V_142:
F_43 ( & V_7 -> V_151 ) ;
return V_161 ;
}
static int F_77 ( struct V_7 * V_7 ,
struct V_159 * V_160 )
{
struct V_203 V_204 ;
int V_161 = - V_153 ;
if ( F_65 ( & V_204 , ( void V_165 * ) V_160 -> V_166 , sizeof( V_204 ) ) )
return - V_167 ;
if ( ! F_78 ( ( unsigned long * ) V_204 . V_205 ,
V_27 ,
V_206 ) )
return - V_87 ;
F_39 ( & V_7 -> V_151 ) ;
if ( ! F_79 ( & V_7 -> V_207 ) ) {
F_80 ( V_7 -> V_12 . V_208 , ( unsigned long * ) V_204 . V_205 ,
V_206 ) ;
V_161 = 0 ;
}
F_43 ( & V_7 -> V_151 ) ;
return V_161 ;
}
static int F_81 ( struct V_7 * V_7 ,
struct V_159 * V_160 )
{
return - V_168 ;
}
static int F_82 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 = - V_168 ;
switch ( V_160 -> V_160 ) {
case V_209 :
V_161 = F_74 ( V_7 , V_160 ) ;
break;
case V_210 :
V_161 = F_77 ( V_7 , V_160 ) ;
break;
case V_211 :
V_161 = F_81 ( V_7 , V_160 ) ;
break;
}
return V_161 ;
}
static int F_83 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
struct V_195 * V_196 ;
int V_161 = 0 ;
V_196 = F_75 ( sizeof( * V_196 ) , V_199 ) ;
if ( ! V_196 ) {
V_161 = - V_78 ;
goto V_142;
}
V_196 -> V_200 = V_7 -> V_12 . V_154 . V_200 ;
V_196 -> V_201 = V_7 -> V_12 . V_154 . V_201 ;
memcpy ( & V_196 -> V_156 , V_7 -> V_12 . V_154 . V_156 ,
V_202 ) ;
if ( F_70 ( ( void V_165 * ) V_160 -> V_166 , V_196 , sizeof( * V_196 ) ) )
V_161 = - V_167 ;
F_76 ( V_196 ) ;
V_142:
return V_161 ;
}
static int F_84 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
struct V_212 * V_213 ;
int V_161 = 0 ;
V_213 = F_75 ( sizeof( * V_213 ) , V_199 ) ;
if ( ! V_213 ) {
V_161 = - V_78 ;
goto V_142;
}
F_85 ( (struct V_200 * ) & V_213 -> V_200 ) ;
V_213 -> V_201 = V_58 . V_201 ;
memcpy ( & V_213 -> V_155 , V_7 -> V_12 . V_154 . V_155 ,
V_202 ) ;
memcpy ( ( unsigned long * ) & V_213 -> V_156 , V_214 . V_215 ,
sizeof( V_214 . V_215 ) ) ;
if ( F_70 ( ( void V_165 * ) V_160 -> V_166 , V_213 , sizeof( * V_213 ) ) )
V_161 = - V_167 ;
F_76 ( V_213 ) ;
V_142:
return V_161 ;
}
static int F_86 ( struct V_7 * V_7 ,
struct V_159 * V_160 )
{
struct V_203 V_204 ;
F_80 ( ( unsigned long * ) V_204 . V_205 , V_7 -> V_12 . V_208 ,
V_206 ) ;
if ( F_70 ( ( void V_165 * ) V_160 -> V_166 , & V_204 , sizeof( V_204 ) ) )
return - V_167 ;
return 0 ;
}
static int F_87 ( struct V_7 * V_7 ,
struct V_159 * V_160 )
{
struct V_203 V_204 ;
F_80 ( ( unsigned long * ) V_204 . V_205 ,
V_27 ,
V_206 ) ;
if ( F_70 ( ( void V_165 * ) V_160 -> V_166 , & V_204 , sizeof( V_204 ) ) )
return - V_167 ;
return 0 ;
}
static int F_88 ( struct V_7 * V_7 ,
struct V_159 * V_160 )
{
return - V_168 ;
}
static int F_89 ( struct V_7 * V_7 ,
struct V_159 * V_160 )
{
if ( F_70 ( ( void V_165 * ) V_160 -> V_166 , & V_30 ,
sizeof( struct V_216 ) ) )
return - V_167 ;
return 0 ;
}
static int F_90 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 = - V_168 ;
switch ( V_160 -> V_160 ) {
case V_209 :
V_161 = F_83 ( V_7 , V_160 ) ;
break;
case V_217 :
V_161 = F_84 ( V_7 , V_160 ) ;
break;
case V_210 :
V_161 = F_86 ( V_7 , V_160 ) ;
break;
case V_218 :
V_161 = F_87 ( V_7 , V_160 ) ;
break;
case V_211 :
V_161 = F_88 ( V_7 , V_160 ) ;
break;
case V_219 :
V_161 = F_89 ( V_7 , V_160 ) ;
break;
}
return V_161 ;
}
static int F_91 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 ;
switch ( V_160 -> V_220 ) {
case V_221 :
V_161 = F_51 ( V_7 , V_160 ) ;
break;
case V_222 :
V_161 = F_68 ( V_7 , V_160 ) ;
break;
case V_223 :
V_161 = F_82 ( V_7 , V_160 ) ;
break;
case V_224 :
V_161 = F_59 ( V_7 , V_160 ) ;
break;
default:
V_161 = - V_168 ;
break;
}
return V_161 ;
}
static int F_92 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 ;
switch ( V_160 -> V_220 ) {
case V_221 :
V_161 = F_49 ( V_7 , V_160 ) ;
break;
case V_222 :
V_161 = F_73 ( V_7 , V_160 ) ;
break;
case V_223 :
V_161 = F_90 ( V_7 , V_160 ) ;
break;
default:
V_161 = - V_168 ;
break;
}
return V_161 ;
}
static int F_93 ( struct V_7 * V_7 , struct V_159 * V_160 )
{
int V_161 ;
switch ( V_160 -> V_220 ) {
case V_221 :
switch ( V_160 -> V_160 ) {
case V_170 :
case V_173 :
V_161 = V_58 . V_171 ? 0 : - V_168 ;
break;
case V_162 :
V_161 = 0 ;
break;
default:
V_161 = - V_168 ;
break;
}
break;
case V_222 :
switch ( V_160 -> V_160 ) {
case V_194 :
case V_193 :
V_161 = 0 ;
break;
default:
V_161 = - V_168 ;
break;
}
break;
case V_223 :
switch ( V_160 -> V_160 ) {
case V_209 :
case V_217 :
case V_210 :
case V_218 :
case V_219 :
V_161 = 0 ;
break;
case V_211 :
default:
V_161 = - V_168 ;
break;
}
break;
case V_224 :
switch ( V_160 -> V_160 ) {
case V_181 :
case V_186 :
case V_189 :
case V_190 :
V_161 = 0 ;
break;
default:
V_161 = - V_168 ;
break;
}
break;
default:
V_161 = - V_168 ;
break;
}
return V_161 ;
}
static long F_94 ( struct V_7 * V_7 , struct V_225 * args )
{
T_5 * V_226 ;
T_6 V_227 ;
int V_10 , V_89 = 0 ;
if ( args -> V_148 != 0 )
return - V_87 ;
if ( ! F_95 ( V_134 -> V_133 ) )
return V_228 ;
if ( args -> V_229 < 1 || args -> V_229 > V_230 )
return - V_87 ;
V_226 = F_96 ( args -> V_229 , sizeof( T_5 ) ,
V_199 | V_231 ) ;
if ( ! V_226 )
V_226 = F_97 ( sizeof( T_5 ) * args -> V_229 ) ;
if ( ! V_226 )
return - V_78 ;
F_98 ( & V_134 -> V_133 -> V_232 ) ;
for ( V_10 = 0 ; V_10 < args -> V_229 ; V_10 ++ ) {
V_227 = F_99 ( V_7 , args -> V_233 + V_10 ) ;
if ( F_100 ( V_227 ) ) {
V_89 = - V_167 ;
break;
}
V_89 = F_101 ( V_134 -> V_133 , V_227 , & V_226 [ V_10 ] ) ;
if ( V_89 )
break;
}
F_102 ( & V_134 -> V_133 -> V_232 ) ;
if ( ! V_89 ) {
V_89 = F_70 ( ( T_5 V_165 * ) args -> V_234 , V_226 ,
sizeof( T_5 ) * args -> V_229 ) ;
if ( V_89 )
V_89 = - V_167 ;
}
F_103 ( V_226 ) ;
return V_89 ;
}
static long F_104 ( struct V_7 * V_7 , struct V_225 * args )
{
T_5 * V_226 ;
T_6 V_227 ;
int V_10 , V_89 = 0 ;
if ( args -> V_148 != 0 )
return - V_87 ;
if ( args -> V_229 < 1 || args -> V_229 > V_230 )
return - V_87 ;
V_226 = F_96 ( args -> V_229 , sizeof( T_5 ) ,
V_199 | V_231 ) ;
if ( ! V_226 )
V_226 = F_97 ( sizeof( T_5 ) * args -> V_229 ) ;
if ( ! V_226 )
return - V_78 ;
V_89 = F_65 ( V_226 , ( T_5 V_165 * ) args -> V_234 ,
sizeof( T_5 ) * args -> V_229 ) ;
if ( V_89 ) {
V_89 = - V_167 ;
goto V_142;
}
V_89 = F_105 () ;
if ( V_89 )
goto V_142;
F_98 ( & V_134 -> V_133 -> V_232 ) ;
for ( V_10 = 0 ; V_10 < args -> V_229 ; V_10 ++ ) {
V_227 = F_99 ( V_7 , args -> V_233 + V_10 ) ;
if ( F_100 ( V_227 ) ) {
V_89 = - V_167 ;
break;
}
if ( V_226 [ V_10 ] & 0x01 ) {
V_89 = - V_87 ;
break;
}
V_89 = F_106 ( V_134 -> V_133 , V_227 , V_226 [ V_10 ] , 0 ) ;
if ( V_89 )
break;
}
F_102 ( & V_134 -> V_133 -> V_232 ) ;
V_142:
F_103 ( V_226 ) ;
return V_89 ;
}
long F_107 ( struct V_82 * V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_7 * V_7 = V_83 -> V_235 ;
void V_165 * V_236 = ( void V_165 * ) V_85 ;
struct V_159 V_160 ;
int V_89 ;
switch ( V_84 ) {
case V_237 : {
struct V_238 V_239 ;
V_89 = - V_167 ;
if ( F_65 ( & V_239 , V_236 , sizeof( V_239 ) ) )
break;
V_89 = F_108 ( V_7 , & V_239 ) ;
break;
}
case V_240 : {
struct V_146 V_147 ;
V_89 = - V_167 ;
if ( F_65 ( & V_147 , V_236 , sizeof( V_147 ) ) )
break;
V_89 = F_46 ( V_7 , & V_147 ) ;
break;
}
case V_241 : {
struct V_242 V_243 ;
V_89 = - V_87 ;
if ( V_7 -> V_12 . V_149 ) {
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_89 = F_109 ( V_7 , & V_243 , 0 , 0 ) ;
}
break;
}
case V_244 : {
V_89 = - V_167 ;
if ( F_65 ( & V_160 , ( void V_165 * ) V_85 , sizeof( V_160 ) ) )
break;
V_89 = F_91 ( V_7 , & V_160 ) ;
break;
}
case V_245 : {
V_89 = - V_167 ;
if ( F_65 ( & V_160 , ( void V_165 * ) V_85 , sizeof( V_160 ) ) )
break;
V_89 = F_92 ( V_7 , & V_160 ) ;
break;
}
case V_246 : {
V_89 = - V_167 ;
if ( F_65 ( & V_160 , ( void V_165 * ) V_85 , sizeof( V_160 ) ) )
break;
V_89 = F_93 ( V_7 , & V_160 ) ;
break;
}
case V_247 : {
struct V_225 args ;
V_89 = - V_167 ;
if ( F_65 ( & args , V_236 ,
sizeof( struct V_225 ) ) )
break;
V_89 = F_94 ( V_7 , & args ) ;
break;
}
case V_248 : {
struct V_225 args ;
V_89 = - V_167 ;
if ( F_65 ( & args , V_236 ,
sizeof( struct V_225 ) ) )
break;
V_89 = F_104 ( V_7 , & args ) ;
break;
}
default:
V_89 = - V_249 ;
}
return V_89 ;
}
static int F_110 ( T_3 * V_250 )
{
T_7 V_251 = 0x04000000UL ;
T_7 V_29 = 0 ;
memset ( V_250 , 0 , 128 ) ;
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
T_3 V_250 [ 128 ] ;
int V_29 ;
if ( F_18 ( 12 ) ) {
V_29 = F_110 ( V_250 ) ;
if ( V_29 )
F_112 ( L_25 , V_29 ) ;
else
return V_250 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_113 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_182 . V_252 = ( V_253 ) ( unsigned long ) V_7 -> V_12 . V_182 . V_183 ;
if ( F_111 () )
V_7 -> V_12 . V_182 . V_252 |= V_254 ;
else
V_7 -> V_12 . V_182 . V_252 |= V_255 ;
}
static V_164 F_114 ( void )
{
struct V_200 V_200 ;
F_85 ( & V_200 ) ;
V_200 . V_256 = 0xff ;
return * ( ( V_164 * ) & V_200 ) ;
}
static void F_115 ( struct V_7 * V_7 )
{
if ( ! F_60 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_182 . V_183 = & V_7 -> V_12 . V_257 -> V_183 ;
F_113 ( V_7 ) ;
V_7 -> V_12 . V_182 . V_185 = 1 ;
V_7 -> V_12 . V_182 . V_188 = 1 ;
F_61 ( V_7 -> V_12 . V_182 . V_183 -> V_184 ,
sizeof( V_7 -> V_12 . V_182 . V_183 -> V_184 ) ) ;
F_61 ( V_7 -> V_12 . V_182 . V_183 -> V_187 ,
sizeof( V_7 -> V_12 . V_182 . V_183 -> V_187 ) ) ;
}
static void F_116 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_258 )
F_117 ( V_7 -> V_12 . V_259 , sizeof( struct V_260 ) ) ;
else
F_118 ( ( unsigned long ) ( V_7 -> V_12 . V_259 ) ) ;
V_7 -> V_12 . V_259 = NULL ;
}
int F_119 ( struct V_7 * V_7 , unsigned long type )
{
T_8 V_261 = V_199 ;
int V_10 , V_262 ;
char V_263 [ 16 ] ;
static unsigned long V_264 ;
V_262 = - V_87 ;
#ifdef F_30
if ( type & ~ V_265 )
goto V_266;
if ( ( type & V_265 ) && ( ! F_120 ( V_267 ) ) )
goto V_266;
#else
if ( type )
goto V_266;
#endif
V_262 = F_28 () ;
if ( V_262 )
goto V_266;
V_262 = - V_78 ;
F_121 ( & V_7 -> V_12 . V_268 , 5 * V_269 , 500 ) ;
V_7 -> V_12 . V_258 = 0 ;
if ( ! V_58 . V_60 )
V_261 |= V_270 ;
F_122 ( & V_7 -> V_12 . V_271 ) ;
V_7 -> V_12 . V_259 = (struct V_272 * ) F_123 ( V_261 ) ;
if ( ! V_7 -> V_12 . V_259 )
goto V_266;
F_124 ( & V_273 ) ;
V_264 += 16 ;
if ( V_264 + sizeof( struct V_272 ) > V_274 )
V_264 = 0 ;
V_7 -> V_12 . V_259 = (struct V_272 * )
( ( char * ) V_7 -> V_12 . V_259 + V_264 ) ;
F_125 ( & V_273 ) ;
sprintf ( V_263 , L_26 , V_134 -> V_275 ) ;
V_7 -> V_12 . V_276 = F_22 ( V_263 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_276 )
goto V_266;
V_7 -> V_12 . V_257 =
(struct V_257 * ) F_123 ( V_199 | V_270 ) ;
if ( ! V_7 -> V_12 . V_257 )
goto V_266;
memcpy ( V_7 -> V_12 . V_154 . V_155 , V_214 . V_215 ,
sizeof( V_214 . V_215 ) ) ;
for ( V_10 = 0 ; V_10 < V_277 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_154 . V_155 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_154 . V_155 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_154 . V_156 = V_7 -> V_12 . V_257 -> V_156 ;
memcpy ( V_7 -> V_12 . V_154 . V_156 , V_7 -> V_12 . V_154 . V_155 ,
V_202 ) ;
F_48 ( V_7 -> V_12 . V_154 . V_155 , 74 ) ;
F_48 ( V_7 -> V_12 . V_154 . V_156 , 74 ) ;
V_7 -> V_12 . V_154 . V_200 = F_114 () ;
V_7 -> V_12 . V_154 . V_201 = V_58 . V_201 & 0x0fff ;
F_115 ( V_7 ) ;
F_126 ( & V_7 -> V_12 . V_278 . V_151 ) ;
for ( V_10 = 0 ; V_10 < V_279 ; V_10 ++ )
F_127 ( & V_7 -> V_12 . V_278 . V_280 [ V_10 ] ) ;
F_128 ( & V_7 -> V_12 . V_281 ) ;
F_129 ( & V_7 -> V_12 . V_282 ) ;
F_23 ( V_7 -> V_12 . V_276 , & V_79 ) ;
F_47 ( V_7 , 3 , L_27 , type ) ;
if ( type & V_265 ) {
V_7 -> V_12 . V_130 = NULL ;
V_7 -> V_12 . V_163 = V_176 ;
} else {
if ( V_58 . V_283 == V_284 )
V_7 -> V_12 . V_163 = V_285 ;
else
V_7 -> V_12 . V_163 = F_130 (unsigned long, TASK_MAX_SIZE,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_130 = F_57 ( V_134 -> V_133 , V_7 -> V_12 . V_163 - 1 ) ;
if ( ! V_7 -> V_12 . V_130 )
goto V_266;
V_7 -> V_12 . V_130 -> V_179 = V_7 ;
V_7 -> V_12 . V_130 -> V_286 = 0 ;
}
V_7 -> V_12 . V_287 = 0 ;
V_7 -> V_12 . V_149 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_126 ( & V_7 -> V_12 . V_288 ) ;
F_131 ( V_7 ) ;
F_132 ( 3 , L_28 , V_7 , V_134 -> V_275 ) ;
return 0 ;
V_266:
F_118 ( ( unsigned long ) V_7 -> V_12 . V_257 ) ;
F_24 ( V_7 -> V_12 . V_276 ) ;
F_116 ( V_7 ) ;
F_132 ( 3 , L_29 , V_262 ) ;
return V_262 ;
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
F_136 ( V_9 , 3 , L_3 , L_30 ) ;
F_137 ( V_9 -> V_289 ) ;
F_138 ( V_9 ) ;
F_139 ( V_9 ) ;
if ( ! F_55 ( V_9 -> V_7 ) )
F_140 ( V_9 ) ;
if ( F_55 ( V_9 -> V_7 ) )
F_58 ( V_9 -> V_12 . V_130 ) ;
if ( V_9 -> V_7 -> V_12 . V_172 )
F_141 ( V_9 ) ;
F_118 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_142 ( V_9 ) ;
F_143 ( V_290 , V_9 ) ;
}
static void F_144 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_135 ( V_9 ) ;
F_39 ( & V_7 -> V_151 ) ;
for ( V_10 = 0 ; V_10 < F_79 ( & V_7 -> V_207 ) ; V_10 ++ )
V_7 -> V_291 [ V_10 ] = NULL ;
F_145 ( & V_7 -> V_207 , 0 ) ;
F_43 ( & V_7 -> V_151 ) ;
}
void F_146 ( struct V_7 * V_7 )
{
F_144 ( V_7 ) ;
F_116 ( V_7 ) ;
F_24 ( V_7 -> V_12 . V_276 ) ;
F_118 ( ( unsigned long ) V_7 -> V_12 . V_257 ) ;
if ( ! F_55 ( V_7 ) )
F_58 ( V_7 -> V_12 . V_130 ) ;
F_147 ( V_7 ) ;
F_148 ( V_7 ) ;
F_149 ( V_7 ) ;
F_132 ( 3 , L_31 , V_7 ) ;
}
static int F_150 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_130 = F_57 ( V_134 -> V_133 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_130 )
return - V_78 ;
V_9 -> V_12 . V_130 -> V_179 = V_9 -> V_7 ;
return 0 ;
}
static void F_140 ( struct V_8 * V_9 )
{
if ( ! F_31 () )
return;
F_151 ( & V_9 -> V_7 -> V_12 . V_271 ) ;
if ( V_9 -> V_7 -> V_12 . V_258 ) {
struct V_260 * V_259 = V_9 -> V_7 -> V_12 . V_259 ;
F_152 ( V_9 -> V_289 , ( unsigned long * ) V_259 -> V_292 ) ;
V_259 -> V_293 [ V_9 -> V_289 ] . V_294 = 0 ;
} else {
struct V_272 * V_259 = V_9 -> V_7 -> V_12 . V_259 ;
F_152 ( V_9 -> V_289 , ( unsigned long * ) & V_259 -> V_292 ) ;
V_259 -> V_293 [ V_9 -> V_289 ] . V_294 = 0 ;
}
F_153 ( & V_9 -> V_7 -> V_12 . V_271 ) ;
}
static void F_154 ( struct V_8 * V_9 )
{
if ( ! F_31 () ) {
struct V_272 * V_259 = V_9 -> V_7 -> V_12 . V_259 ;
V_9 -> V_12 . V_14 -> V_295 = ( V_253 ) ( ( ( V_296 ) V_259 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_297 = ( V_253 ) ( V_296 ) V_259 ;
}
F_151 ( & V_9 -> V_7 -> V_12 . V_271 ) ;
if ( V_9 -> V_7 -> V_12 . V_258 ) {
struct V_260 * V_259 = V_9 -> V_7 -> V_12 . V_259 ;
V_259 -> V_293 [ V_9 -> V_289 ] . V_294 = ( V_296 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_295 = ( V_253 ) ( ( ( V_296 ) V_259 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_297 = ( V_253 ) ( V_296 ) V_259 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_298 |= 0x04U ;
F_15 ( V_9 -> V_289 , ( unsigned long * ) V_259 -> V_292 ) ;
} else {
struct V_272 * V_259 = V_9 -> V_7 -> V_12 . V_259 ;
V_259 -> V_293 [ V_9 -> V_289 ] . V_294 = ( V_296 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_295 = ( V_253 ) ( ( ( V_296 ) V_259 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_297 = ( V_253 ) ( V_296 ) V_259 ;
F_15 ( V_9 -> V_289 , ( unsigned long * ) & V_259 -> V_292 ) ;
}
F_153 ( & V_9 -> V_7 -> V_12 . V_271 ) ;
}
static inline void F_155 ( struct V_299 * V_300 , struct V_301 * V_302 )
{
V_300 -> V_294 = V_302 -> V_294 ;
V_300 -> V_303 . V_304 = V_302 -> V_303 . V_304 ;
V_300 -> V_303 . V_305 = V_302 -> V_303 . V_305 ;
}
static void F_156 ( struct V_260 * V_300 , struct V_272 * V_302 )
{
int V_10 ;
V_300 -> V_306 = V_302 -> V_306 ;
V_300 -> V_292 [ 0 ] = V_302 -> V_292 ;
for ( V_10 = 0 ; V_10 < V_115 ; V_10 ++ )
F_155 ( & V_300 -> V_293 [ V_10 ] , & V_302 -> V_293 [ V_10 ] ) ;
}
static int F_157 ( struct V_7 * V_7 )
{
struct V_272 * V_307 = V_7 -> V_12 . V_259 ;
struct V_260 * V_308 ;
struct V_8 * V_9 ;
unsigned int V_309 ;
T_7 V_297 , V_295 ;
V_308 = F_158 ( sizeof( * V_308 ) , V_199 | V_310 ) ;
if ( ! V_308 )
return - V_78 ;
V_295 = ( T_7 ) ( ( V_164 ) ( V_308 ) >> 32 ) ;
V_297 = ( T_7 ) ( V_164 ) ( V_308 ) & ~ 0x3fU ;
F_159 ( V_7 ) ;
F_160 ( & V_7 -> V_12 . V_271 ) ;
F_156 ( V_308 , V_307 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_295 = V_295 ;
V_9 -> V_12 . V_14 -> V_297 = V_297 ;
V_9 -> V_12 . V_14 -> V_298 |= 0x04U ;
}
V_7 -> V_12 . V_259 = V_308 ;
V_7 -> V_12 . V_258 = 1 ;
F_161 ( & V_7 -> V_12 . V_271 ) ;
F_162 ( V_7 ) ;
F_118 ( ( unsigned long ) V_307 ) ;
F_47 ( V_7 , 2 , L_32 ,
V_307 , V_7 -> V_12 . V_259 ) ;
return 0 ;
}
static int F_163 ( struct V_7 * V_7 , unsigned int V_311 )
{
int V_262 ;
if ( ! F_31 () ) {
if ( V_311 < V_116 )
return true ;
return false ;
}
if ( V_311 < V_115 )
return true ;
if ( ! V_58 . V_117 || ! V_58 . V_60 )
return false ;
F_39 ( & V_7 -> V_151 ) ;
V_262 = V_7 -> V_12 . V_258 ? 0 : F_157 ( V_7 ) ;
F_43 ( & V_7 -> V_151 ) ;
return V_262 == 0 && V_311 < V_118 ;
}
int F_164 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_312 = V_313 ;
F_139 ( V_9 ) ;
V_9 -> V_314 -> V_315 = V_316 |
V_317 |
V_318 |
V_319 |
V_320 |
V_321 ;
F_165 ( V_9 , 0 ) ;
if ( F_60 ( V_9 -> V_7 , 64 ) )
V_9 -> V_314 -> V_315 |= V_322 ;
if ( V_123 )
V_9 -> V_314 -> V_315 |= V_323 ;
else
V_9 -> V_314 -> V_315 |= V_324 ;
if ( F_55 ( V_9 -> V_7 ) )
return F_150 ( V_9 ) ;
return 0 ;
}
static void F_166 ( struct V_8 * V_9 )
{
F_167 ( V_9 -> V_12 . V_16 != 0 ) ;
F_168 ( & V_9 -> V_12 . V_325 ) ;
V_9 -> V_12 . V_16 = F_169 () ;
F_170 ( & V_9 -> V_12 . V_325 ) ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_167 ( V_9 -> V_12 . V_16 == 0 ) ;
F_168 ( & V_9 -> V_12 . V_325 ) ;
V_9 -> V_12 . V_14 -> V_326 -= F_169 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_170 ( & V_9 -> V_12 . V_325 ) ;
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
void F_178 ( struct V_8 * V_9 , V_296 V_326 )
{
F_175 () ;
F_168 ( & V_9 -> V_12 . V_325 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_169 () ;
V_9 -> V_12 . V_14 -> V_326 = V_326 ;
F_170 ( & V_9 -> V_12 . V_325 ) ;
F_176 () ;
}
V_296 F_179 ( struct V_8 * V_9 )
{
unsigned int V_327 ;
V_296 V_328 ;
if ( F_180 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_326 ;
F_175 () ;
do {
V_327 = F_181 ( & V_9 -> V_12 . V_325 ) ;
F_167 ( ( V_327 & 1 ) && F_182 () == V_9 -> V_293 ) ;
V_328 = V_9 -> V_12 . V_14 -> V_326 ;
if ( F_183 ( V_9 -> V_12 . V_16 ) )
V_328 -= F_169 () - V_9 -> V_12 . V_16 ;
} while ( F_184 ( & V_9 -> V_12 . V_325 , V_327 & ~ 1 ) );
F_176 () ;
return V_328 ;
}
void F_185 ( struct V_8 * V_9 , int V_293 )
{
F_186 ( V_9 -> V_12 . V_329 ) ;
F_187 ( V_330 , & V_9 -> V_12 . V_14 -> V_331 ) ;
if ( V_9 -> V_12 . V_15 && ! F_188 ( V_9 ) )
F_166 ( V_9 ) ;
V_9 -> V_293 = V_293 ;
}
void F_189 ( struct V_8 * V_9 )
{
V_9 -> V_293 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_188 ( V_9 ) )
F_171 ( V_9 ) ;
F_190 ( V_330 , & V_9 -> V_12 . V_14 -> V_331 ) ;
V_9 -> V_12 . V_329 = F_191 () ;
F_192 ( V_9 -> V_12 . V_329 ) ;
}
static void F_193 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_332 . V_333 = 0UL ;
V_9 -> V_12 . V_14 -> V_332 . V_166 = 0UL ;
F_165 ( V_9 , 0 ) ;
F_178 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_334 = 0UL ;
V_9 -> V_12 . V_14 -> V_335 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_336 , 0 , 16 * sizeof( V_296 ) ) ;
V_9 -> V_12 . V_14 -> V_336 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_336 [ 14 ] = 0xC2000000UL ;
F_194 () ;
V_134 -> V_337 . V_338 . V_339 = 0 ;
V_9 -> V_12 . V_14 -> V_340 = 1 ;
V_9 -> V_12 . V_14 -> V_341 = 0 ;
V_9 -> V_12 . V_312 = V_313 ;
F_139 ( V_9 ) ;
if ( ! F_195 ( V_9 -> V_7 ) )
F_196 ( V_9 ) ;
F_138 ( V_9 ) ;
}
void F_197 ( struct V_8 * V_9 )
{
F_39 ( & V_9 -> V_7 -> V_151 ) ;
F_175 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_176 () ;
F_43 ( & V_9 -> V_7 -> V_151 ) ;
if ( ! F_55 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_130 = V_9 -> V_7 -> V_12 . V_130 ;
F_154 ( V_9 ) ;
}
if ( F_60 ( V_9 -> V_7 , 74 ) || V_9 -> V_7 -> V_12 . V_158 )
V_9 -> V_12 . V_14 -> V_342 |= V_343 ;
V_9 -> V_12 . V_329 = V_9 -> V_12 . V_130 ;
}
static void F_62 ( struct V_8 * V_9 )
{
if ( ! F_60 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_344 &= ~ ( V_345 | V_346 ) ;
if ( V_9 -> V_7 -> V_12 . V_182 . V_185 )
V_9 -> V_12 . V_14 -> V_344 |= V_345 ;
if ( V_9 -> V_7 -> V_12 . V_182 . V_188 )
V_9 -> V_12 . V_14 -> V_344 |= V_346 ;
V_9 -> V_12 . V_14 -> V_252 = V_9 -> V_7 -> V_12 . V_182 . V_252 ;
}
void F_141 ( struct V_8 * V_9 )
{
F_118 ( V_9 -> V_12 . V_14 -> V_347 ) ;
V_9 -> V_12 . V_14 -> V_347 = 0 ;
}
int F_198 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_347 = F_123 ( V_199 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_347 )
return - V_78 ;
V_9 -> V_12 . V_14 -> V_298 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_298 &= ~ 0x08 ;
return 0 ;
}
static void F_199 ( struct V_8 * V_9 )
{
struct V_348 * V_154 = & V_9 -> V_7 -> V_12 . V_154 ;
V_9 -> V_12 . V_14 -> V_201 = V_154 -> V_201 ;
if ( F_60 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_349 = ( T_7 ) ( V_164 ) V_154 -> V_156 ;
}
int F_200 ( struct V_8 * V_9 )
{
int V_262 = 0 ;
F_145 ( & V_9 -> V_12 . V_14 -> V_331 , V_350 |
V_351 |
V_352 ) ;
if ( F_60 ( V_9 -> V_7 , 78 ) )
F_187 ( V_353 , & V_9 -> V_12 . V_14 -> V_331 ) ;
else if ( F_60 ( V_9 -> V_7 , 8 ) )
F_187 ( V_354 , & V_9 -> V_12 . V_14 -> V_331 ) ;
F_199 ( V_9 ) ;
if ( V_56 )
V_9 -> V_12 . V_14 -> V_355 |= 0x02 ;
if ( F_60 ( V_9 -> V_7 , 9 ) )
V_9 -> V_12 . V_14 -> V_355 |= 0x04 ;
if ( F_60 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_355 |= 0x10 ;
if ( F_60 ( V_9 -> V_7 , 8 ) && V_58 . V_356 )
V_9 -> V_12 . V_14 -> V_298 |= 0x08 ;
V_9 -> V_12 . V_14 -> V_357 = 0x1002000U ;
if ( V_58 . V_72 )
V_9 -> V_12 . V_14 -> V_357 |= 0x80000000U ;
if ( V_58 . V_70 )
V_9 -> V_12 . V_14 -> V_357 |= 0x40000000U ;
if ( V_58 . V_64 )
V_9 -> V_12 . V_14 -> V_357 |= 1 ;
if ( V_58 . V_358 )
V_9 -> V_12 . V_14 -> V_357 |= 0x10000000U ;
if ( F_60 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_357 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_359 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_360 = ( unsigned long ) & V_9 -> V_314 -> V_302 . V_361 . V_362 ;
V_9 -> V_12 . V_14 -> V_342 |= V_363 | V_364 | V_365 ;
if ( V_9 -> V_7 -> V_12 . V_172 ) {
V_262 = F_198 ( V_9 ) ;
if ( V_262 )
return V_262 ;
}
F_201 ( & V_9 -> V_12 . V_366 , V_367 , V_368 ) ;
V_9 -> V_12 . V_366 . V_369 = V_370 ;
F_62 ( V_9 ) ;
return V_262 ;
}
struct V_8 * F_202 ( struct V_7 * V_7 ,
unsigned int V_311 )
{
struct V_8 * V_9 ;
struct V_371 * V_371 ;
int V_262 = - V_87 ;
if ( ! F_55 ( V_7 ) && ! F_163 ( V_7 , V_311 ) )
goto V_142;
V_262 = - V_78 ;
V_9 = F_203 ( V_290 , V_199 ) ;
if ( ! V_9 )
goto V_142;
V_371 = (struct V_371 * ) F_123 ( V_199 ) ;
if ( ! V_371 )
goto V_372;
V_9 -> V_12 . V_14 = & V_371 -> V_14 ;
V_9 -> V_12 . V_14 -> V_373 = ( unsigned long ) & V_371 -> V_374 ;
V_9 -> V_12 . V_14 -> V_375 = 0 ;
V_9 -> V_12 . V_14 -> V_376 = V_58 . V_283 ;
V_9 -> V_12 . V_14 -> V_377 = V_311 ;
F_126 ( & V_9 -> V_12 . V_378 . V_151 ) ;
V_9 -> V_12 . V_378 . V_278 = & V_7 -> V_12 . V_278 ;
V_9 -> V_12 . V_378 . V_379 = & V_9 -> V_379 ;
V_9 -> V_12 . V_378 . V_331 = & V_9 -> V_12 . V_14 -> V_331 ;
F_204 ( & V_9 -> V_12 . V_325 ) ;
V_262 = F_205 ( V_9 , V_7 , V_311 ) ;
if ( V_262 )
goto V_380;
F_47 ( V_7 , 3 , L_33 , V_311 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_206 ( V_311 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_380:
F_118 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_372:
F_143 ( V_290 , V_9 ) ;
V_142:
return F_207 ( V_262 ) ;
}
int F_208 ( struct V_8 * V_9 )
{
return F_209 ( V_9 , 0 ) ;
}
void F_210 ( struct V_8 * V_9 )
{
F_187 ( V_381 , & V_9 -> V_12 . V_14 -> V_382 ) ;
F_63 ( V_9 ) ;
}
void F_211 ( struct V_8 * V_9 )
{
F_190 ( V_381 , & V_9 -> V_12 . V_14 -> V_382 ) ;
}
static void F_212 ( struct V_8 * V_9 )
{
F_187 ( V_383 , & V_9 -> V_12 . V_14 -> V_382 ) ;
F_63 ( V_9 ) ;
}
static void F_213 ( struct V_8 * V_9 )
{
F_190 ( V_383 , & V_9 -> V_12 . V_14 -> V_382 ) ;
}
void F_63 ( struct V_8 * V_9 )
{
F_187 ( V_384 , & V_9 -> V_12 . V_14 -> V_331 ) ;
while ( V_9 -> V_12 . V_14 -> V_385 & V_386 )
F_214 () ;
}
void F_45 ( int V_387 , struct V_8 * V_9 )
{
F_215 ( V_387 , V_9 ) ;
F_212 ( V_9 ) ;
}
static void V_21 ( struct V_130 * V_130 , unsigned long V_388 ,
unsigned long V_389 )
{
struct V_7 * V_7 = V_130 -> V_179 ;
struct V_8 * V_9 ;
unsigned long V_390 ;
int V_10 ;
if ( F_216 ( V_130 ) )
return;
if ( V_388 >= 1UL << 31 )
return;
F_7 (i, vcpu, kvm) {
V_390 = F_217 ( V_9 ) ;
if ( V_390 <= V_389 && V_388 <= V_390 + 2 * V_274 - 1 ) {
F_136 ( V_9 , 2 , L_34 ,
V_388 , V_389 ) ;
F_45 ( V_391 , V_9 ) ;
}
}
}
int F_218 ( struct V_8 * V_9 )
{
F_219 () ;
return 0 ;
}
static int F_220 ( struct V_8 * V_9 ,
struct V_392 * V_393 )
{
int V_89 = - V_87 ;
switch ( V_393 -> V_311 ) {
case V_394 :
V_89 = F_50 ( V_9 -> V_12 . V_14 -> V_335 ,
( T_7 V_165 * ) V_393 -> V_166 ) ;
break;
case V_395 :
V_89 = F_50 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_396 :
V_89 = F_50 ( F_179 ( V_9 ) ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_397 :
V_89 = F_50 ( V_9 -> V_12 . V_14 -> V_334 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_398 :
V_89 = F_50 ( V_9 -> V_12 . V_312 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_399 :
V_89 = F_50 ( V_9 -> V_12 . V_400 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_401 :
V_89 = F_50 ( V_9 -> V_12 . V_402 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_403 :
V_89 = F_50 ( V_9 -> V_12 . V_14 -> V_341 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_404 :
V_89 = F_50 ( V_9 -> V_12 . V_14 -> V_340 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
default:
break;
}
return V_89 ;
}
static int F_221 ( struct V_8 * V_9 ,
struct V_392 * V_393 )
{
int V_89 = - V_87 ;
V_296 V_5 ;
switch ( V_393 -> V_311 ) {
case V_394 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_335 ,
( T_7 V_165 * ) V_393 -> V_166 ) ;
break;
case V_395 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_396 :
V_89 = F_56 ( V_5 , ( V_164 V_165 * ) V_393 -> V_166 ) ;
if ( ! V_89 )
F_178 ( V_9 , V_5 ) ;
break;
case V_397 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_334 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_398 :
V_89 = F_56 ( V_9 -> V_12 . V_312 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
if ( V_9 -> V_12 . V_312 == V_313 )
F_139 ( V_9 ) ;
break;
case V_399 :
V_89 = F_56 ( V_9 -> V_12 . V_400 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_401 :
V_89 = F_56 ( V_9 -> V_12 . V_402 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_403 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_341 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
break;
case V_404 :
V_89 = F_56 ( V_9 -> V_12 . V_14 -> V_340 ,
( V_164 V_165 * ) V_393 -> V_166 ) ;
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
int F_223 ( struct V_8 * V_9 , struct V_405 * V_361 )
{
memcpy ( & V_9 -> V_314 -> V_302 . V_361 . V_406 , & V_361 -> V_406 , sizeof( V_361 -> V_406 ) ) ;
return 0 ;
}
int F_224 ( struct V_8 * V_9 , struct V_405 * V_361 )
{
memcpy ( & V_361 -> V_406 , & V_9 -> V_314 -> V_302 . V_361 . V_406 , sizeof( V_361 -> V_406 ) ) ;
return 0 ;
}
int F_225 ( struct V_8 * V_9 ,
struct V_407 * V_408 )
{
memcpy ( & V_9 -> V_314 -> V_302 . V_361 . V_409 , & V_408 -> V_409 , sizeof( V_408 -> V_409 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_336 , & V_408 -> V_410 , sizeof( V_408 -> V_410 ) ) ;
return 0 ;
}
int F_226 ( struct V_8 * V_9 ,
struct V_407 * V_408 )
{
memcpy ( & V_408 -> V_409 , & V_9 -> V_314 -> V_302 . V_361 . V_409 , sizeof( V_408 -> V_409 ) ) ;
memcpy ( & V_408 -> V_410 , & V_9 -> V_12 . V_14 -> V_336 , sizeof( V_408 -> V_410 ) ) ;
return 0 ;
}
int F_227 ( struct V_8 * V_9 , struct V_411 * V_338 )
{
if ( F_228 ( V_338 -> V_339 ) )
return - V_87 ;
V_9 -> V_314 -> V_302 . V_361 . V_339 = V_338 -> V_339 ;
if ( V_123 )
F_229 ( ( V_412 * ) V_9 -> V_314 -> V_302 . V_361 . V_413 ,
( V_414 * ) V_338 -> V_415 ) ;
else
memcpy ( V_9 -> V_314 -> V_302 . V_361 . V_415 , & V_338 -> V_415 , sizeof( V_338 -> V_415 ) ) ;
return 0 ;
}
int F_230 ( struct V_8 * V_9 , struct V_411 * V_338 )
{
F_194 () ;
if ( V_123 )
F_231 ( ( V_414 * ) V_338 -> V_415 ,
( V_412 * ) V_9 -> V_314 -> V_302 . V_361 . V_413 ) ;
else
memcpy ( V_338 -> V_415 , V_9 -> V_314 -> V_302 . V_361 . V_415 , sizeof( V_338 -> V_415 ) ) ;
V_338 -> V_339 = V_9 -> V_314 -> V_302 . V_361 . V_339 ;
return 0 ;
}
static int F_232 ( struct V_8 * V_9 , T_9 V_416 )
{
int V_262 = 0 ;
if ( ! F_233 ( V_9 ) )
V_262 = - V_153 ;
else {
V_9 -> V_314 -> V_417 = V_416 . V_333 ;
V_9 -> V_314 -> V_418 = V_416 . V_166 ;
}
return V_262 ;
}
int F_234 ( struct V_8 * V_9 ,
struct V_419 * V_420 )
{
return - V_87 ;
}
int F_235 ( struct V_8 * V_9 ,
struct V_421 * V_422 )
{
int V_262 = 0 ;
V_9 -> V_423 = 0 ;
F_236 ( V_9 ) ;
if ( V_422 -> V_424 & ~ V_425 )
return - V_87 ;
if ( ! V_58 . V_66 )
return - V_87 ;
if ( V_422 -> V_424 & V_426 ) {
V_9 -> V_423 = V_422 -> V_424 ;
F_187 ( V_427 , & V_9 -> V_12 . V_14 -> V_331 ) ;
if ( V_422 -> V_424 & V_428 )
V_262 = F_237 ( V_9 , V_422 ) ;
} else {
F_190 ( V_427 , & V_9 -> V_12 . V_14 -> V_331 ) ;
V_9 -> V_12 . V_429 . V_430 = 0 ;
}
if ( V_262 ) {
V_9 -> V_423 = 0 ;
F_236 ( V_9 ) ;
F_190 ( V_427 , & V_9 -> V_12 . V_14 -> V_331 ) ;
}
return V_262 ;
}
int F_238 ( struct V_8 * V_9 ,
struct V_431 * V_432 )
{
return F_233 ( V_9 ) ? V_433 :
V_434 ;
}
int F_239 ( struct V_8 * V_9 ,
struct V_431 * V_432 )
{
int V_262 = 0 ;
V_9 -> V_7 -> V_12 . V_435 = 1 ;
switch ( V_432 -> V_432 ) {
case V_433 :
F_196 ( V_9 ) ;
break;
case V_434 :
F_240 ( V_9 ) ;
break;
case V_436 :
case V_437 :
default:
V_262 = - V_168 ;
}
return V_262 ;
}
static bool F_241 ( struct V_8 * V_9 )
{
return F_79 ( & V_9 -> V_12 . V_14 -> V_331 ) & V_438 ;
}
static int F_242 ( struct V_8 * V_9 )
{
V_439:
F_213 ( V_9 ) ;
if ( ! V_9 -> V_440 )
return 0 ;
if ( F_243 ( V_391 , V_9 ) ) {
int V_262 ;
V_262 = F_244 ( V_9 -> V_12 . V_130 ,
F_217 ( V_9 ) ,
V_274 * 2 , V_441 ) ;
if ( V_262 ) {
F_215 ( V_391 , V_9 ) ;
return V_262 ;
}
goto V_439;
}
if ( F_243 ( V_442 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_443 = 0xffff ;
goto V_439;
}
if ( F_243 ( V_444 , V_9 ) ) {
if ( ! F_241 ( V_9 ) ) {
F_245 ( V_9 -> V_289 , 1 ) ;
F_187 ( V_438 ,
& V_9 -> V_12 . V_14 -> V_331 ) ;
}
goto V_439;
}
if ( F_243 ( V_445 , V_9 ) ) {
if ( F_241 ( V_9 ) ) {
F_245 ( V_9 -> V_289 , 0 ) ;
F_190 ( V_438 ,
& V_9 -> V_12 . V_14 -> V_331 ) ;
}
goto V_439;
}
if ( F_243 ( V_145 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_342 |= V_343 ;
goto V_439;
}
F_246 ( V_446 , & V_9 -> V_440 ) ;
return 0 ;
}
void F_67 ( struct V_7 * V_7 , V_164 V_447 )
{
struct V_8 * V_9 ;
int V_10 ;
F_39 ( & V_7 -> V_151 ) ;
F_175 () ;
V_7 -> V_12 . V_13 = V_447 - F_247 () ;
F_159 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_162 ( V_7 ) ;
F_176 () ;
F_43 ( & V_7 -> V_151 ) ;
}
long F_248 ( struct V_8 * V_9 , T_10 V_448 , int V_449 )
{
return F_249 ( V_9 -> V_12 . V_130 , V_448 ,
V_449 ? V_450 : 0 ) ;
}
static void F_250 ( struct V_8 * V_9 , bool V_451 ,
unsigned long V_452 )
{
struct V_238 V_453 ;
struct V_454 V_455 ;
if ( V_451 ) {
V_455 . V_456 . V_88 . V_457 = V_452 ;
V_455 . type = V_458 ;
F_167 ( F_251 ( V_9 , & V_455 ) ) ;
} else {
V_453 . type = V_459 ;
V_453 . V_460 = V_452 ;
F_167 ( F_108 ( V_9 -> V_7 , & V_453 ) ) ;
}
}
void F_252 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
F_253 ( V_9 , V_462 -> V_12 . V_312 ) ;
F_250 ( V_9 , true , V_462 -> V_12 . V_312 ) ;
}
void F_254 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
F_255 ( V_9 , V_462 -> V_12 . V_312 ) ;
F_250 ( V_9 , false , V_462 -> V_12 . V_312 ) ;
}
void F_256 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
}
bool F_257 ( struct V_8 * V_9 )
{
return true ;
}
static int F_258 ( struct V_8 * V_9 )
{
T_11 V_227 ;
struct V_463 V_12 ;
int V_262 ;
if ( V_9 -> V_12 . V_312 == V_313 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_332 . V_333 & V_9 -> V_12 . V_402 ) !=
V_9 -> V_12 . V_400 )
return 0 ;
if ( F_259 ( V_9 ) )
return 0 ;
if ( F_209 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_336 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_130 -> V_286 )
return 0 ;
V_227 = F_99 ( V_9 -> V_7 , F_260 ( V_134 -> V_337 . V_464 ) ) ;
V_227 += V_134 -> V_337 . V_464 & ~ V_465 ;
if ( F_261 ( V_9 , V_9 -> V_12 . V_312 , & V_12 . V_312 , 8 ) )
return 0 ;
V_262 = F_262 ( V_9 , V_134 -> V_337 . V_464 , V_227 , & V_12 ) ;
return V_262 ;
}
static int F_263 ( struct V_8 * V_9 )
{
int V_262 , V_331 ;
F_264 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_466 = V_9 -> V_314 -> V_302 . V_361 . V_406 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_467 = V_9 -> V_314 -> V_302 . V_361 . V_406 [ 15 ] ;
if ( F_265 () )
F_266 () ;
if ( F_267 ( V_468 ) )
F_268 () ;
if ( ! F_55 ( V_9 -> V_7 ) ) {
V_262 = F_269 ( V_9 ) ;
if ( V_262 )
return V_262 ;
}
V_262 = F_242 ( V_9 ) ;
if ( V_262 )
return V_262 ;
if ( F_270 ( V_9 ) ) {
F_271 ( V_9 ) ;
F_272 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_469 = 0 ;
V_331 = F_79 ( & V_9 -> V_12 . V_14 -> V_331 ) ;
F_136 ( V_9 , 6 , L_35 , V_331 ) ;
F_273 ( V_9 , V_331 ) ;
return 0 ;
}
static int F_274 ( struct V_8 * V_9 )
{
struct V_470 V_471 = {
. V_472 = V_473 ,
} ;
T_3 V_474 , V_475 ;
int V_262 ;
F_136 ( V_9 , 3 , L_3 , L_36 ) ;
F_275 ( V_9 ) ;
V_262 = F_276 ( V_9 , & V_474 , 1 ) ;
V_475 = F_277 ( V_474 ) ;
if ( V_262 < 0 ) {
return V_262 ;
} else if ( V_262 ) {
V_471 = V_9 -> V_12 . V_476 ;
V_475 = 4 ;
}
V_471 . V_148 = V_475 | V_477 ;
F_278 ( V_9 , V_475 ) ;
return F_279 ( V_9 , & V_471 ) ;
}
static int F_280 ( struct V_8 * V_9 , int V_478 )
{
F_136 ( V_9 , 6 , L_37 ,
V_9 -> V_12 . V_14 -> V_469 ) ;
F_281 ( V_9 , V_9 -> V_12 . V_14 -> V_469 ) ;
if ( F_270 ( V_9 ) )
F_282 ( V_9 ) ;
V_9 -> V_314 -> V_302 . V_361 . V_406 [ 14 ] = V_9 -> V_12 . V_14 -> V_466 ;
V_9 -> V_314 -> V_302 . V_361 . V_406 [ 15 ] = V_9 -> V_12 . V_14 -> V_467 ;
if ( V_9 -> V_12 . V_14 -> V_469 > 0 ) {
int V_262 = F_283 ( V_9 ) ;
if ( V_262 != - V_479 )
return V_262 ;
V_9 -> V_314 -> V_478 = V_480 ;
V_9 -> V_314 -> V_481 . V_469 = V_9 -> V_12 . V_14 -> V_469 ;
V_9 -> V_314 -> V_481 . V_482 = V_9 -> V_12 . V_14 -> V_482 ;
V_9 -> V_314 -> V_481 . V_483 = V_9 -> V_12 . V_14 -> V_483 ;
return - V_484 ;
} else if ( V_478 != - V_167 ) {
V_9 -> V_485 . V_486 ++ ;
return 0 ;
} else if ( F_55 ( V_9 -> V_7 ) ) {
V_9 -> V_314 -> V_478 = V_487 ;
V_9 -> V_314 -> V_488 . V_489 =
V_134 -> V_337 . V_464 ;
V_9 -> V_314 -> V_488 . V_490 = 0x10 ;
return - V_484 ;
} else if ( V_134 -> V_337 . V_491 ) {
F_284 ( V_9 ) ;
V_134 -> V_337 . V_491 = 0 ;
if ( F_258 ( V_9 ) )
return 0 ;
return F_248 ( V_9 , V_134 -> V_337 . V_464 , 1 ) ;
}
return F_274 ( V_9 ) ;
}
static int F_285 ( struct V_8 * V_9 )
{
int V_262 , V_478 ;
V_9 -> V_492 = F_52 ( & V_9 -> V_7 -> V_174 ) ;
do {
V_262 = F_263 ( V_9 ) ;
if ( V_262 )
break;
F_54 ( & V_9 -> V_7 -> V_174 , V_9 -> V_492 ) ;
F_286 () ;
F_287 () ;
F_173 ( V_9 ) ;
F_288 () ;
V_478 = F_289 ( V_9 -> V_12 . V_14 ,
V_9 -> V_314 -> V_302 . V_361 . V_406 ) ;
F_286 () ;
F_172 ( V_9 ) ;
F_290 () ;
F_288 () ;
V_9 -> V_492 = F_52 ( & V_9 -> V_7 -> V_174 ) ;
V_262 = F_280 ( V_9 , V_478 ) ;
} while ( ! F_291 ( V_134 ) && ! F_292 ( V_9 ) && ! V_262 );
F_54 ( & V_9 -> V_7 -> V_174 , V_9 -> V_492 ) ;
return V_262 ;
}
static void F_293 ( struct V_8 * V_9 , struct V_493 * V_493 )
{
V_9 -> V_12 . V_14 -> V_332 . V_333 = V_493 -> V_417 ;
V_9 -> V_12 . V_14 -> V_332 . V_166 = V_493 -> V_418 ;
if ( V_493 -> V_494 & V_316 )
F_165 ( V_9 , V_493 -> V_302 . V_361 . V_390 ) ;
if ( V_493 -> V_494 & V_319 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_336 , & V_493 -> V_302 . V_361 . V_410 , 128 ) ;
F_215 ( V_442 , V_9 ) ;
}
if ( V_493 -> V_494 & V_320 ) {
F_178 ( V_9 , V_493 -> V_302 . V_361 . V_326 ) ;
V_9 -> V_12 . V_14 -> V_334 = V_493 -> V_302 . V_361 . V_334 ;
V_9 -> V_12 . V_14 -> V_335 = V_493 -> V_302 . V_361 . V_335 ;
V_9 -> V_12 . V_14 -> V_341 = V_493 -> V_302 . V_361 . V_341 ;
V_9 -> V_12 . V_14 -> V_340 = V_493 -> V_302 . V_361 . V_340 ;
}
if ( V_493 -> V_494 & V_321 ) {
V_9 -> V_12 . V_312 = V_493 -> V_302 . V_361 . V_495 ;
V_9 -> V_12 . V_402 = V_493 -> V_302 . V_361 . V_496 ;
V_9 -> V_12 . V_400 = V_493 -> V_302 . V_361 . V_497 ;
if ( V_9 -> V_12 . V_312 == V_313 )
F_139 ( V_9 ) ;
}
if ( ( V_493 -> V_494 & V_322 ) &&
F_60 ( V_9 -> V_7 , 64 ) ) {
struct V_498 * V_362 =
(struct V_498 * ) & V_493 -> V_302 . V_361 . V_362 ;
if ( V_362 -> V_499 )
V_9 -> V_12 . V_14 -> V_344 |= 0x01 ;
}
F_294 ( V_9 -> V_12 . V_500 ) ;
F_295 ( V_9 -> V_314 -> V_302 . V_361 . V_409 ) ;
F_194 () ;
V_9 -> V_12 . V_501 . V_339 = V_134 -> V_337 . V_338 . V_339 ;
V_9 -> V_12 . V_501 . V_361 = V_134 -> V_337 . V_338 . V_361 ;
if ( V_123 )
V_134 -> V_337 . V_338 . V_361 = V_9 -> V_314 -> V_302 . V_361 . V_413 ;
else
V_134 -> V_337 . V_338 . V_361 = V_9 -> V_314 -> V_302 . V_361 . V_415 ;
V_134 -> V_337 . V_338 . V_339 = V_9 -> V_314 -> V_302 . V_361 . V_339 ;
if ( F_228 ( V_134 -> V_337 . V_338 . V_339 ) )
V_134 -> V_337 . V_338 . V_339 = 0 ;
V_493 -> V_494 = 0 ;
}
static void F_296 ( struct V_8 * V_9 , struct V_493 * V_493 )
{
V_493 -> V_417 = V_9 -> V_12 . V_14 -> V_332 . V_333 ;
V_493 -> V_418 = V_9 -> V_12 . V_14 -> V_332 . V_166 ;
V_493 -> V_302 . V_361 . V_390 = F_217 ( V_9 ) ;
memcpy ( & V_493 -> V_302 . V_361 . V_410 , & V_9 -> V_12 . V_14 -> V_336 , 128 ) ;
V_493 -> V_302 . V_361 . V_326 = F_179 ( V_9 ) ;
V_493 -> V_302 . V_361 . V_334 = V_9 -> V_12 . V_14 -> V_334 ;
V_493 -> V_302 . V_361 . V_335 = V_9 -> V_12 . V_14 -> V_335 ;
V_493 -> V_302 . V_361 . V_341 = V_9 -> V_12 . V_14 -> V_341 ;
V_493 -> V_302 . V_361 . V_340 = V_9 -> V_12 . V_14 -> V_340 ;
V_493 -> V_302 . V_361 . V_495 = V_9 -> V_12 . V_312 ;
V_493 -> V_302 . V_361 . V_496 = V_9 -> V_12 . V_402 ;
V_493 -> V_302 . V_361 . V_497 = V_9 -> V_12 . V_400 ;
F_294 ( V_9 -> V_314 -> V_302 . V_361 . V_409 ) ;
F_295 ( V_9 -> V_12 . V_500 ) ;
F_194 () ;
V_9 -> V_314 -> V_302 . V_361 . V_339 = V_134 -> V_337 . V_338 . V_339 ;
V_134 -> V_337 . V_338 . V_339 = V_9 -> V_12 . V_501 . V_339 ;
V_134 -> V_337 . V_338 . V_361 = V_9 -> V_12 . V_501 . V_361 ;
}
int F_297 ( struct V_8 * V_9 , struct V_493 * V_493 )
{
int V_262 ;
T_12 V_502 ;
if ( F_292 ( V_9 ) ) {
F_298 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_503 )
F_299 ( V_504 , & V_9 -> V_505 , & V_502 ) ;
if ( ! F_195 ( V_9 -> V_7 ) ) {
F_240 ( V_9 ) ;
} else if ( F_233 ( V_9 ) ) {
F_300 ( L_38 ,
V_9 -> V_289 ) ;
return - V_87 ;
}
F_293 ( V_9 , V_493 ) ;
F_174 ( V_9 ) ;
F_301 () ;
V_262 = F_285 ( V_9 ) ;
if ( F_291 ( V_134 ) && ! V_262 ) {
V_493 -> V_478 = V_506 ;
V_262 = - V_507 ;
}
if ( F_292 ( V_9 ) && ! V_262 ) {
F_298 ( V_9 ) ;
V_262 = 0 ;
}
if ( V_262 == - V_484 ) {
V_262 = 0 ;
}
F_177 ( V_9 ) ;
F_296 ( V_9 , V_493 ) ;
if ( V_9 -> V_503 )
F_299 ( V_504 , & V_502 , NULL ) ;
V_9 -> V_485 . V_508 ++ ;
return V_262 ;
}
int F_302 ( struct V_8 * V_9 , unsigned long V_448 )
{
unsigned char V_509 = 1 ;
V_414 V_415 [ V_510 ] ;
unsigned int V_511 ;
V_164 V_512 , V_326 ;
int V_262 ;
V_511 = F_217 ( V_9 ) ;
if ( V_448 == V_513 ) {
if ( F_303 ( V_9 , 163 , & V_509 , 1 ) )
return - V_167 ;
V_448 = 0 ;
} else if ( V_448 == V_514 ) {
if ( F_304 ( V_9 , 163 , & V_509 , 1 ) )
return - V_167 ;
V_448 = V_511 ;
} else
V_448 -= V_515 ;
if ( V_123 ) {
F_231 ( V_415 , ( V_412 * ) V_9 -> V_314 -> V_302 . V_361 . V_413 ) ;
V_262 = F_303 ( V_9 , V_448 + V_515 ,
V_415 , 128 ) ;
} else {
V_262 = F_303 ( V_9 , V_448 + V_515 ,
V_9 -> V_314 -> V_302 . V_361 . V_415 , 128 ) ;
}
V_262 |= F_303 ( V_9 , V_448 + V_516 ,
V_9 -> V_314 -> V_302 . V_361 . V_406 , 128 ) ;
V_262 |= F_303 ( V_9 , V_448 + V_517 ,
& V_9 -> V_12 . V_14 -> V_332 , 16 ) ;
V_262 |= F_303 ( V_9 , V_448 + V_518 ,
& V_511 , 4 ) ;
V_262 |= F_303 ( V_9 , V_448 + V_519 ,
& V_9 -> V_314 -> V_302 . V_361 . V_339 , 4 ) ;
V_262 |= F_303 ( V_9 , V_448 + V_520 ,
& V_9 -> V_12 . V_14 -> V_335 , 4 ) ;
V_326 = F_179 ( V_9 ) ;
V_262 |= F_303 ( V_9 , V_448 + V_521 ,
& V_326 , 8 ) ;
V_512 = V_9 -> V_12 . V_14 -> V_334 >> 8 ;
V_262 |= F_303 ( V_9 , V_448 + V_522 ,
& V_512 , 8 ) ;
V_262 |= F_303 ( V_9 , V_448 + V_523 ,
& V_9 -> V_314 -> V_302 . V_361 . V_409 , 64 ) ;
V_262 |= F_303 ( V_9 , V_448 + V_524 ,
& V_9 -> V_12 . V_14 -> V_336 , 128 ) ;
return V_262 ? - V_167 : 0 ;
}
int F_305 ( struct V_8 * V_9 , unsigned long V_166 )
{
F_194 () ;
V_9 -> V_314 -> V_302 . V_361 . V_339 = V_134 -> V_337 . V_338 . V_339 ;
F_294 ( V_9 -> V_314 -> V_302 . V_361 . V_409 ) ;
return F_302 ( V_9 , V_166 ) ;
}
static void F_306 ( struct V_8 * V_9 )
{
F_243 ( V_444 , V_9 ) ;
F_45 ( V_445 , V_9 ) ;
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
F_243 ( V_445 , V_9 ) ;
F_45 ( V_444 , V_9 ) ;
}
void F_240 ( struct V_8 * V_9 )
{
int V_10 , V_207 , V_525 = 0 ;
if ( ! F_233 ( V_9 ) )
return;
F_309 ( V_9 -> V_289 , 1 ) ;
F_124 ( & V_9 -> V_7 -> V_12 . V_288 ) ;
V_207 = F_79 ( & V_9 -> V_7 -> V_207 ) ;
for ( V_10 = 0 ; V_10 < V_207 ; V_10 ++ ) {
if ( ! F_233 ( V_9 -> V_7 -> V_291 [ V_10 ] ) )
V_525 ++ ;
}
if ( V_525 == 0 ) {
F_308 ( V_9 ) ;
} else if ( V_525 == 1 ) {
F_307 ( V_9 -> V_7 ) ;
}
F_190 ( V_352 , & V_9 -> V_12 . V_14 -> V_331 ) ;
F_215 ( V_442 , V_9 ) ;
F_125 ( & V_9 -> V_7 -> V_12 . V_288 ) ;
return;
}
void F_196 ( struct V_8 * V_9 )
{
int V_10 , V_207 , V_525 = 0 ;
struct V_8 * V_526 = NULL ;
if ( F_233 ( V_9 ) )
return;
F_309 ( V_9 -> V_289 , 0 ) ;
F_124 ( & V_9 -> V_7 -> V_12 . V_288 ) ;
V_207 = F_79 ( & V_9 -> V_7 -> V_207 ) ;
F_310 ( V_9 ) ;
F_187 ( V_352 , & V_9 -> V_12 . V_14 -> V_331 ) ;
F_306 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_207 ; V_10 ++ ) {
if ( ! F_233 ( V_9 -> V_7 -> V_291 [ V_10 ] ) ) {
V_525 ++ ;
V_526 = V_9 -> V_7 -> V_291 [ V_10 ] ;
}
}
if ( V_525 == 1 ) {
F_308 ( V_526 ) ;
}
F_125 ( & V_9 -> V_7 -> V_12 . V_288 ) ;
return;
}
static int F_311 ( struct V_8 * V_9 ,
struct V_146 * V_147 )
{
int V_89 ;
if ( V_147 -> V_148 )
return - V_87 ;
switch ( V_147 -> V_147 ) {
case V_98 :
if ( ! V_9 -> V_7 -> V_12 . V_287 ) {
V_9 -> V_7 -> V_12 . V_287 = 1 ;
F_47 ( V_9 -> V_7 , 3 , L_3 , L_39 ) ;
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
struct V_527 * V_528 )
{
void V_165 * V_529 = ( void V_165 * ) V_528 -> V_530 ;
void * V_531 = NULL ;
int V_89 , V_492 ;
const V_164 V_532 = V_533
| V_534 ;
if ( V_528 -> V_148 & ~ V_532 )
return - V_87 ;
if ( V_528 -> V_535 > V_112 )
return - V_177 ;
if ( ! ( V_528 -> V_148 & V_534 ) ) {
V_531 = F_97 ( V_528 -> V_535 ) ;
if ( ! V_531 )
return - V_78 ;
}
V_492 = F_52 ( & V_9 -> V_7 -> V_174 ) ;
switch ( V_528 -> V_536 ) {
case V_537 :
if ( V_528 -> V_148 & V_534 ) {
V_89 = F_314 ( V_9 , V_528 -> V_538 , V_528 -> V_539 ,
V_528 -> V_535 , V_540 ) ;
break;
}
V_89 = F_315 ( V_9 , V_528 -> V_538 , V_528 -> V_539 , V_531 , V_528 -> V_535 ) ;
if ( V_89 == 0 ) {
if ( F_70 ( V_529 , V_531 , V_528 -> V_535 ) )
V_89 = - V_167 ;
}
break;
case V_541 :
if ( V_528 -> V_148 & V_534 ) {
V_89 = F_314 ( V_9 , V_528 -> V_538 , V_528 -> V_539 ,
V_528 -> V_535 , V_542 ) ;
break;
}
if ( F_65 ( V_531 , V_529 , V_528 -> V_535 ) ) {
V_89 = - V_167 ;
break;
}
V_89 = F_316 ( V_9 , V_528 -> V_538 , V_528 -> V_539 , V_531 , V_528 -> V_535 ) ;
break;
default:
V_89 = - V_87 ;
}
F_54 ( & V_9 -> V_7 -> V_174 , V_492 ) ;
if ( V_89 > 0 && ( V_528 -> V_148 & V_533 ) != 0 )
F_279 ( V_9 , & V_9 -> V_12 . V_476 ) ;
F_317 ( V_531 ) ;
return V_89 ;
}
long F_318 ( struct V_82 * V_83 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_8 * V_9 = V_83 -> V_235 ;
void V_165 * V_236 = ( void V_165 * ) V_85 ;
int V_169 ;
long V_89 ;
switch ( V_84 ) {
case V_543 : {
struct V_454 V_544 ;
V_89 = - V_167 ;
if ( F_65 ( & V_544 , V_236 , sizeof( V_544 ) ) )
break;
V_89 = F_251 ( V_9 , & V_544 ) ;
break;
}
case V_237 : {
struct V_238 V_239 ;
struct V_454 V_544 ;
V_89 = - V_167 ;
if ( F_65 ( & V_239 , V_236 , sizeof( V_239 ) ) )
break;
if ( F_319 ( & V_239 , & V_544 ) )
return - V_87 ;
V_89 = F_251 ( V_9 , & V_544 ) ;
break;
}
case V_545 :
V_169 = F_52 ( & V_9 -> V_7 -> V_174 ) ;
V_89 = F_305 ( V_9 , V_85 ) ;
F_54 ( & V_9 -> V_7 -> V_174 , V_169 ) ;
break;
case V_546 : {
T_9 V_416 ;
V_89 = - V_167 ;
if ( F_65 ( & V_416 , V_236 , sizeof( V_416 ) ) )
break;
V_89 = F_232 ( V_9 , V_416 ) ;
break;
}
case V_547 :
V_89 = F_222 ( V_9 ) ;
break;
case V_548 :
case V_549 : {
struct V_392 V_393 ;
V_89 = - V_167 ;
if ( F_65 ( & V_393 , V_236 , sizeof( V_393 ) ) )
break;
if ( V_84 == V_548 )
V_89 = F_221 ( V_9 , & V_393 ) ;
else
V_89 = F_220 ( V_9 , & V_393 ) ;
break;
}
#ifdef F_30
case V_550 : {
struct V_551 V_552 ;
if ( F_65 ( & V_552 , V_236 , sizeof( V_552 ) ) ) {
V_89 = - V_167 ;
break;
}
if ( ! F_55 ( V_9 -> V_7 ) ) {
V_89 = - V_87 ;
break;
}
V_89 = F_320 ( V_9 -> V_12 . V_130 , V_552 . V_553 ,
V_552 . V_554 , V_552 . V_555 ) ;
break;
}
case V_556 : {
struct V_551 V_552 ;
if ( F_65 ( & V_552 , V_236 , sizeof( V_552 ) ) ) {
V_89 = - V_167 ;
break;
}
if ( ! F_55 ( V_9 -> V_7 ) ) {
V_89 = - V_87 ;
break;
}
V_89 = F_321 ( V_9 -> V_12 . V_130 , V_552 . V_554 ,
V_552 . V_555 ) ;
break;
}
#endif
case V_557 : {
V_89 = F_249 ( V_9 -> V_12 . V_130 , V_85 , 0 ) ;
break;
}
case V_240 :
{
struct V_146 V_147 ;
V_89 = - V_167 ;
if ( F_65 ( & V_147 , V_236 , sizeof( V_147 ) ) )
break;
V_89 = F_311 ( V_9 , & V_147 ) ;
break;
}
case V_558 : {
struct V_527 V_559 ;
if ( F_65 ( & V_559 , V_236 , sizeof( V_559 ) ) == 0 )
V_89 = F_313 ( V_9 , & V_559 ) ;
else
V_89 = - V_167 ;
break;
}
case V_560 : {
struct V_561 V_562 ;
V_89 = - V_167 ;
if ( F_65 ( & V_562 , V_236 , sizeof( V_562 ) ) )
break;
if ( V_562 . V_563 > V_564 ||
V_562 . V_563 == 0 ||
V_562 . V_563 % sizeof( struct V_454 ) > 0 ) {
V_89 = - V_87 ;
break;
}
V_89 = F_322 ( V_9 ,
( void V_165 * ) V_562 . V_530 ,
V_562 . V_563 ) ;
break;
}
case V_565 : {
struct V_561 V_562 ;
V_89 = - V_167 ;
if ( F_65 ( & V_562 , V_236 , sizeof( V_562 ) ) )
break;
if ( V_562 . V_563 == 0 ) {
V_89 = - V_87 ;
break;
}
V_89 = F_323 ( V_9 ,
( V_566 V_165 * ) V_562 . V_530 ,
V_562 . V_563 ) ;
break;
}
default:
V_89 = - V_249 ;
}
return V_89 ;
}
int F_324 ( struct V_8 * V_9 , struct V_567 * V_568 )
{
#ifdef F_30
if ( ( V_568 -> V_569 == V_570 )
&& ( F_55 ( V_9 -> V_7 ) ) ) {
V_568 -> V_571 = F_325 ( V_9 -> V_12 . V_14 ) ;
F_326 ( V_568 -> V_571 ) ;
return 0 ;
}
#endif
return V_572 ;
}
int F_327 ( struct V_7 * V_7 , struct V_125 * V_141 ,
unsigned long V_132 )
{
return 0 ;
}
int F_328 ( struct V_7 * V_7 ,
struct V_125 * V_126 ,
const struct V_573 * V_574 ,
enum V_575 V_576 )
{
if ( V_574 -> V_577 & 0xffffful )
return - V_87 ;
if ( V_574 -> V_578 & 0xffffful )
return - V_87 ;
if ( V_574 -> V_579 + V_574 -> V_578 > V_7 -> V_12 . V_163 )
return - V_87 ;
return 0 ;
}
void F_329 ( struct V_7 * V_7 ,
const struct V_573 * V_574 ,
const struct V_125 * V_580 ,
const struct V_125 * V_178 ,
enum V_575 V_576 )
{
int V_262 ;
if ( V_580 -> V_577 == V_574 -> V_577 &&
V_580 -> V_131 * V_274 == V_574 -> V_579 &&
V_580 -> V_132 * V_274 == V_574 -> V_578 )
return;
V_262 = F_320 ( V_7 -> V_12 . V_130 , V_574 -> V_577 ,
V_574 -> V_579 , V_574 -> V_578 ) ;
if ( V_262 )
F_330 ( L_40 ) ;
return;
}
static inline unsigned long F_331 ( int V_10 )
{
unsigned int V_581 = ( V_58 . V_582 << V_10 * 2 ) >> 30 ;
return 0x0000ffffffffffffUL >> ( V_581 << 4 ) ;
}
void F_332 ( struct V_8 * V_9 )
{
V_9 -> V_583 = false ;
}
static int T_13 F_333 ( void )
{
int V_10 ;
if ( ! V_58 . V_59 ) {
F_334 ( L_41 ) ;
return - V_584 ;
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_1 [ V_10 ] |=
V_214 . V_215 [ V_10 ] & F_331 ( V_10 ) ;
return F_335 ( NULL , sizeof( struct V_8 ) , 0 , V_585 ) ;
}
static void T_14 F_336 ( void )
{
F_337 () ;
}
