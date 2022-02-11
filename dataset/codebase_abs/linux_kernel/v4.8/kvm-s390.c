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
F_20 ( V_33 , V_30 . V_34 ) ;
F_20 ( V_35 , V_30 . V_36 ) ;
F_20 ( V_37 , V_30 . V_38 ) ;
F_20 ( V_39 , V_30 . V_40 ) ;
F_20 ( V_41 , V_30 . V_42 ) ;
}
if ( F_18 ( 76 ) )
F_20 ( V_43 , V_30 . V_44 ) ;
if ( F_18 ( 77 ) ) {
F_20 ( V_45 , V_30 . V_46 ) ;
F_20 ( V_47 , V_30 . V_48 ) ;
F_20 ( V_49 , V_30 . V_50 ) ;
F_20 ( V_51 , V_30 . V_52 ) ;
}
if ( F_18 ( 57 ) )
F_20 ( V_53 , V_30 . V_54 ) ;
if ( V_55 )
F_14 ( V_56 ) ;
if ( ! V_57 . V_58 || ! V_55 || ! V_57 . V_59 ||
! F_18 ( 3 ) || ! V_60 )
return;
F_14 ( V_61 ) ;
if ( V_57 . V_59 )
F_14 ( V_62 ) ;
if ( V_57 . V_63 )
F_14 ( V_64 ) ;
if ( V_57 . V_65 )
F_14 ( V_66 ) ;
if ( V_57 . V_67 )
F_14 ( V_68 ) ;
if ( V_57 . V_69 )
F_14 ( V_70 ) ;
if ( V_57 . V_71 )
F_14 ( V_72 ) ;
if ( V_57 . V_73 )
F_14 ( V_74 ) ;
}
int F_21 ( void * V_75 )
{
V_76 = F_22 ( L_2 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_76 )
return - V_77 ;
if ( F_23 ( V_76 , & V_78 ) ) {
F_24 ( V_76 ) ;
return - V_77 ;
}
F_17 () ;
return F_25 ( & V_79 , V_80 ) ;
}
void F_26 ( void )
{
F_24 ( V_76 ) ;
}
long F_27 ( struct V_81 * V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
if ( V_83 == V_85 )
return F_28 () ;
return - V_86 ;
}
int F_29 ( struct V_7 * V_7 , long V_87 )
{
int V_88 ;
switch ( V_87 ) {
case V_89 :
case V_90 :
case V_91 :
#ifdef F_30
case V_92 :
#endif
case V_93 :
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
V_88 = 1 ;
break;
case V_110 :
V_88 = V_111 ;
break;
case V_112 :
case V_113 :
V_88 = V_114 ;
if ( V_57 . V_115 && V_57 . V_59 )
V_88 = V_116 ;
break;
case V_117 :
V_88 = V_118 ;
break;
case V_119 :
V_88 = V_55 ;
break;
case V_120 :
V_88 = V_121 ;
break;
case V_122 :
V_88 = F_18 ( 64 ) ;
break;
default:
V_88 = 0 ;
}
return V_88 ;
}
static void F_31 ( struct V_7 * V_7 ,
struct V_123 * V_124 )
{
T_2 V_125 , V_126 ;
unsigned long V_127 ;
struct V_128 * V_128 = V_7 -> V_12 . V_128 ;
V_126 = V_124 -> V_129 + V_124 -> V_130 ;
for ( V_125 = V_124 -> V_129 ; V_125 <= V_126 ; V_125 ++ ) {
V_127 = F_32 ( V_124 , V_125 ) ;
if ( F_33 ( V_128 -> V_131 , V_127 ) )
F_34 ( V_7 , V_125 ) ;
if ( F_35 ( V_132 ) )
return;
F_36 () ;
}
}
int F_37 ( struct V_7 * V_7 ,
struct V_133 * log )
{
int V_88 ;
unsigned long V_134 ;
struct V_135 * V_136 ;
struct V_123 * V_124 ;
int V_137 = 0 ;
F_38 ( & V_7 -> V_138 ) ;
V_88 = - V_86 ;
if ( log -> V_139 >= V_118 )
goto V_140;
V_136 = V_135 ( V_7 ) ;
V_124 = F_39 ( V_136 , log -> V_139 ) ;
V_88 = - V_141 ;
if ( ! V_124 -> V_142 )
goto V_140;
F_31 ( V_7 , V_124 ) ;
V_88 = F_40 ( V_7 , log , & V_137 ) ;
if ( V_88 )
goto V_140;
if ( V_137 ) {
V_134 = F_41 ( V_124 ) ;
memset ( V_124 -> V_142 , 0 , V_134 ) ;
}
V_88 = 0 ;
V_140:
F_42 ( & V_7 -> V_138 ) ;
return V_88 ;
}
static void F_43 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_44 ( V_143 , V_9 ) ;
}
}
static int F_45 ( struct V_7 * V_7 , struct V_144 * V_145 )
{
int V_88 ;
if ( V_145 -> V_146 )
return - V_86 ;
switch ( V_145 -> V_145 ) {
case V_101 :
F_46 ( V_7 , 3 , L_3 , L_4 ) ;
V_7 -> V_12 . V_147 = 1 ;
V_88 = 0 ;
break;
case V_105 :
F_46 ( V_7 , 3 , L_3 , L_5 ) ;
V_7 -> V_12 . V_148 = 1 ;
V_88 = 0 ;
break;
case V_120 :
F_38 ( & V_7 -> V_149 ) ;
if ( V_7 -> V_150 ) {
V_88 = - V_151 ;
} else if ( V_121 ) {
F_47 ( V_7 -> V_12 . V_152 . V_153 , 129 ) ;
F_47 ( V_7 -> V_12 . V_152 . V_154 , 129 ) ;
V_88 = 0 ;
} else
V_88 = - V_86 ;
F_42 ( & V_7 -> V_149 ) ;
F_46 ( V_7 , 3 , L_6 ,
V_88 ? L_7 : L_8 ) ;
break;
case V_122 :
V_88 = - V_86 ;
F_38 ( & V_7 -> V_149 ) ;
if ( V_7 -> V_150 ) {
V_88 = - V_151 ;
} else if ( F_18 ( 64 ) ) {
F_47 ( V_7 -> V_12 . V_152 . V_153 , 64 ) ;
F_47 ( V_7 -> V_12 . V_152 . V_154 , 64 ) ;
V_88 = 0 ;
}
F_42 ( & V_7 -> V_149 ) ;
F_46 ( V_7 , 3 , L_9 ,
V_88 ? L_7 : L_8 ) ;
break;
case V_106 :
F_46 ( V_7 , 3 , L_3 , L_10 ) ;
V_7 -> V_12 . V_155 = 1 ;
V_88 = 0 ;
break;
case V_109 :
F_46 ( V_7 , 3 , L_3 , L_11 ) ;
V_7 -> V_12 . V_156 = 1 ;
F_43 ( V_7 ) ;
V_88 = 0 ;
break;
default:
V_88 = - V_86 ;
break;
}
return V_88 ;
}
static int F_48 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 ;
switch ( V_158 -> V_158 ) {
case V_160 :
V_159 = 0 ;
F_46 ( V_7 , 3 , L_12 ,
V_7 -> V_12 . V_161 ) ;
if ( F_49 ( V_7 -> V_12 . V_161 , ( V_162 V_163 * ) V_158 -> V_164 ) )
V_159 = - V_165 ;
break;
default:
V_159 = - V_166 ;
break;
}
return V_159 ;
}
static int F_50 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 ;
unsigned int V_167 ;
switch ( V_158 -> V_158 ) {
case V_168 :
V_159 = - V_166 ;
if ( ! V_57 . V_169 )
break;
V_159 = - V_151 ;
F_46 ( V_7 , 3 , L_3 , L_13 ) ;
F_38 ( & V_7 -> V_149 ) ;
if ( ! V_7 -> V_150 ) {
V_7 -> V_12 . V_170 = 1 ;
V_159 = 0 ;
}
F_42 ( & V_7 -> V_149 ) ;
break;
case V_171 :
V_159 = - V_166 ;
if ( ! V_57 . V_169 )
break;
V_159 = - V_86 ;
if ( ! V_7 -> V_12 . V_170 )
break;
F_46 ( V_7 , 3 , L_3 , L_14 ) ;
F_38 ( & V_7 -> V_149 ) ;
V_167 = F_51 ( & V_7 -> V_172 ) ;
F_52 ( V_7 -> V_12 . V_128 -> V_131 ) ;
F_53 ( & V_7 -> V_172 , V_167 ) ;
F_42 ( & V_7 -> V_149 ) ;
V_159 = 0 ;
break;
case V_160 : {
unsigned long V_173 ;
if ( F_54 ( V_7 ) )
return - V_86 ;
if ( F_55 ( V_173 , ( V_162 V_163 * ) V_158 -> V_164 ) )
return - V_165 ;
if ( V_7 -> V_12 . V_161 != V_174 &&
V_173 > V_7 -> V_12 . V_161 )
return - V_175 ;
if ( ! V_173 )
return - V_86 ;
if ( V_173 != V_174 )
V_173 -= 1 ;
V_159 = - V_151 ;
F_38 ( & V_7 -> V_149 ) ;
if ( ! V_7 -> V_150 ) {
struct V_128 * V_176 = F_56 ( V_132 -> V_131 , V_173 ) ;
if ( ! V_176 ) {
V_159 = - V_77 ;
} else {
F_57 ( V_7 -> V_12 . V_128 ) ;
V_176 -> V_177 = V_7 ;
V_7 -> V_12 . V_128 = V_176 ;
V_159 = 0 ;
}
}
F_42 ( & V_7 -> V_149 ) ;
F_46 ( V_7 , 3 , L_15 , V_173 ) ;
F_46 ( V_7 , 3 , L_16 ,
( void * ) V_7 -> V_12 . V_128 -> V_178 ) ;
break;
}
default:
V_159 = - V_166 ;
break;
}
return V_159 ;
}
static int F_58 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
struct V_8 * V_9 ;
int V_10 ;
if ( ! F_59 ( V_7 , 76 ) )
return - V_86 ;
F_38 ( & V_7 -> V_149 ) ;
switch ( V_158 -> V_158 ) {
case V_179 :
F_60 (
V_7 -> V_12 . V_180 . V_181 -> V_182 ,
sizeof( V_7 -> V_12 . V_180 . V_181 -> V_182 ) ) ;
V_7 -> V_12 . V_180 . V_183 = 1 ;
F_46 ( V_7 , 3 , L_3 , L_17 ) ;
break;
case V_184 :
F_60 (
V_7 -> V_12 . V_180 . V_181 -> V_185 ,
sizeof( V_7 -> V_12 . V_180 . V_181 -> V_185 ) ) ;
V_7 -> V_12 . V_180 . V_186 = 1 ;
F_46 ( V_7 , 3 , L_3 , L_18 ) ;
break;
case V_187 :
V_7 -> V_12 . V_180 . V_183 = 0 ;
memset ( V_7 -> V_12 . V_180 . V_181 -> V_182 , 0 ,
sizeof( V_7 -> V_12 . V_180 . V_181 -> V_182 ) ) ;
F_46 ( V_7 , 3 , L_3 , L_19 ) ;
break;
case V_188 :
V_7 -> V_12 . V_180 . V_186 = 0 ;
memset ( V_7 -> V_12 . V_180 . V_181 -> V_185 , 0 ,
sizeof( V_7 -> V_12 . V_180 . V_181 -> V_185 ) ) ;
F_46 ( V_7 , 3 , L_3 , L_20 ) ;
break;
default:
F_42 ( & V_7 -> V_149 ) ;
return - V_166 ;
}
F_7 (i, vcpu, kvm) {
F_61 ( V_9 ) ;
F_62 ( V_9 ) ;
}
F_42 ( & V_7 -> V_149 ) ;
return 0 ;
}
static int F_63 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
T_3 V_189 ;
if ( F_64 ( & V_189 , ( void V_163 * ) V_158 -> V_164 ,
sizeof( V_189 ) ) )
return - V_165 ;
if ( V_189 != 0 )
return - V_86 ;
F_46 ( V_7 , 3 , L_21 , V_189 ) ;
return 0 ;
}
static int F_65 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
V_162 V_190 ;
if ( F_64 ( & V_190 , ( void V_163 * ) V_158 -> V_164 , sizeof( V_190 ) ) )
return - V_165 ;
F_66 ( V_7 , V_190 ) ;
F_46 ( V_7 , 3 , L_22 , V_190 ) ;
return 0 ;
}
static int F_67 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 ;
if ( V_158 -> V_146 )
return - V_86 ;
switch ( V_158 -> V_158 ) {
case V_191 :
V_159 = F_63 ( V_7 , V_158 ) ;
break;
case V_192 :
V_159 = F_65 ( V_7 , V_158 ) ;
break;
default:
V_159 = - V_166 ;
break;
}
return V_159 ;
}
static int F_68 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
T_3 V_189 = 0 ;
if ( F_69 ( ( void V_163 * ) V_158 -> V_164 , & V_189 ,
sizeof( V_189 ) ) )
return - V_165 ;
F_46 ( V_7 , 3 , L_23 , V_189 ) ;
return 0 ;
}
static int F_70 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
V_162 V_190 ;
V_190 = F_71 ( V_7 ) ;
if ( F_69 ( ( void V_163 * ) V_158 -> V_164 , & V_190 , sizeof( V_190 ) ) )
return - V_165 ;
F_46 ( V_7 , 3 , L_24 , V_190 ) ;
return 0 ;
}
static int F_72 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 ;
if ( V_158 -> V_146 )
return - V_86 ;
switch ( V_158 -> V_158 ) {
case V_191 :
V_159 = F_68 ( V_7 , V_158 ) ;
break;
case V_192 :
V_159 = F_70 ( V_7 , V_158 ) ;
break;
default:
V_159 = - V_166 ;
break;
}
return V_159 ;
}
static int F_73 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
struct V_193 * V_194 ;
T_4 V_195 , V_196 ;
int V_159 = 0 ;
F_38 ( & V_7 -> V_149 ) ;
if ( V_7 -> V_150 ) {
V_159 = - V_151 ;
goto V_140;
}
V_194 = F_74 ( sizeof( * V_194 ) , V_197 ) ;
if ( ! V_194 ) {
V_159 = - V_77 ;
goto V_140;
}
if ( ! F_64 ( V_194 , ( void V_163 * ) V_158 -> V_164 ,
sizeof( * V_194 ) ) ) {
V_7 -> V_12 . V_152 . V_198 = V_194 -> V_198 ;
V_195 = V_57 . V_199 >> 16 & 0xfff ;
V_196 = V_57 . V_199 & 0xfff ;
if ( V_195 && V_194 -> V_199 ) {
if ( V_194 -> V_199 > V_196 )
V_7 -> V_12 . V_152 . V_199 = V_196 ;
else if ( V_194 -> V_199 < V_195 )
V_7 -> V_12 . V_152 . V_199 = V_195 ;
else
V_7 -> V_12 . V_152 . V_199 = V_194 -> V_199 ;
}
memcpy ( V_7 -> V_12 . V_152 . V_154 , V_194 -> V_154 ,
V_200 ) ;
} else
V_159 = - V_165 ;
F_75 ( V_194 ) ;
V_140:
F_42 ( & V_7 -> V_149 ) ;
return V_159 ;
}
static int F_76 ( struct V_7 * V_7 ,
struct V_157 * V_158 )
{
struct V_201 V_202 ;
int V_159 = - V_151 ;
if ( F_64 ( & V_202 , ( void V_163 * ) V_158 -> V_164 , sizeof( V_202 ) ) )
return - V_165 ;
if ( ! F_77 ( ( unsigned long * ) V_202 . V_203 ,
V_27 ,
V_204 ) )
return - V_86 ;
F_38 ( & V_7 -> V_149 ) ;
if ( ! F_78 ( & V_7 -> V_205 ) ) {
F_79 ( V_7 -> V_12 . V_206 , ( unsigned long * ) V_202 . V_203 ,
V_204 ) ;
V_159 = 0 ;
}
F_42 ( & V_7 -> V_149 ) ;
return V_159 ;
}
static int F_80 ( struct V_7 * V_7 ,
struct V_157 * V_158 )
{
return - V_166 ;
}
static int F_81 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 = - V_166 ;
switch ( V_158 -> V_158 ) {
case V_207 :
V_159 = F_73 ( V_7 , V_158 ) ;
break;
case V_208 :
V_159 = F_76 ( V_7 , V_158 ) ;
break;
case V_209 :
V_159 = F_80 ( V_7 , V_158 ) ;
break;
}
return V_159 ;
}
static int F_82 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
struct V_193 * V_194 ;
int V_159 = 0 ;
V_194 = F_74 ( sizeof( * V_194 ) , V_197 ) ;
if ( ! V_194 ) {
V_159 = - V_77 ;
goto V_140;
}
V_194 -> V_198 = V_7 -> V_12 . V_152 . V_198 ;
V_194 -> V_199 = V_7 -> V_12 . V_152 . V_199 ;
memcpy ( & V_194 -> V_154 , V_7 -> V_12 . V_152 . V_154 ,
V_200 ) ;
if ( F_69 ( ( void V_163 * ) V_158 -> V_164 , V_194 , sizeof( * V_194 ) ) )
V_159 = - V_165 ;
F_75 ( V_194 ) ;
V_140:
return V_159 ;
}
static int F_83 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
struct V_210 * V_211 ;
int V_159 = 0 ;
V_211 = F_74 ( sizeof( * V_211 ) , V_197 ) ;
if ( ! V_211 ) {
V_159 = - V_77 ;
goto V_140;
}
F_84 ( (struct V_198 * ) & V_211 -> V_198 ) ;
V_211 -> V_199 = V_57 . V_199 ;
memcpy ( & V_211 -> V_153 , V_7 -> V_12 . V_152 . V_153 ,
V_200 ) ;
memcpy ( ( unsigned long * ) & V_211 -> V_154 , V_212 . V_213 ,
V_200 ) ;
if ( F_69 ( ( void V_163 * ) V_158 -> V_164 , V_211 , sizeof( * V_211 ) ) )
V_159 = - V_165 ;
F_75 ( V_211 ) ;
V_140:
return V_159 ;
}
static int F_85 ( struct V_7 * V_7 ,
struct V_157 * V_158 )
{
struct V_201 V_202 ;
F_79 ( ( unsigned long * ) V_202 . V_203 , V_7 -> V_12 . V_206 ,
V_204 ) ;
if ( F_69 ( ( void V_163 * ) V_158 -> V_164 , & V_202 , sizeof( V_202 ) ) )
return - V_165 ;
return 0 ;
}
static int F_86 ( struct V_7 * V_7 ,
struct V_157 * V_158 )
{
struct V_201 V_202 ;
F_79 ( ( unsigned long * ) V_202 . V_203 ,
V_27 ,
V_204 ) ;
if ( F_69 ( ( void V_163 * ) V_158 -> V_164 , & V_202 , sizeof( V_202 ) ) )
return - V_165 ;
return 0 ;
}
static int F_87 ( struct V_7 * V_7 ,
struct V_157 * V_158 )
{
return - V_166 ;
}
static int F_88 ( struct V_7 * V_7 ,
struct V_157 * V_158 )
{
if ( F_69 ( ( void V_163 * ) V_158 -> V_164 , & V_30 ,
sizeof( struct V_214 ) ) )
return - V_165 ;
return 0 ;
}
static int F_89 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 = - V_166 ;
switch ( V_158 -> V_158 ) {
case V_207 :
V_159 = F_82 ( V_7 , V_158 ) ;
break;
case V_215 :
V_159 = F_83 ( V_7 , V_158 ) ;
break;
case V_208 :
V_159 = F_85 ( V_7 , V_158 ) ;
break;
case V_216 :
V_159 = F_86 ( V_7 , V_158 ) ;
break;
case V_209 :
V_159 = F_87 ( V_7 , V_158 ) ;
break;
case V_217 :
V_159 = F_88 ( V_7 , V_158 ) ;
break;
}
return V_159 ;
}
static int F_90 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 ;
switch ( V_158 -> V_218 ) {
case V_219 :
V_159 = F_50 ( V_7 , V_158 ) ;
break;
case V_220 :
V_159 = F_67 ( V_7 , V_158 ) ;
break;
case V_221 :
V_159 = F_81 ( V_7 , V_158 ) ;
break;
case V_222 :
V_159 = F_58 ( V_7 , V_158 ) ;
break;
default:
V_159 = - V_166 ;
break;
}
return V_159 ;
}
static int F_91 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 ;
switch ( V_158 -> V_218 ) {
case V_219 :
V_159 = F_48 ( V_7 , V_158 ) ;
break;
case V_220 :
V_159 = F_72 ( V_7 , V_158 ) ;
break;
case V_221 :
V_159 = F_89 ( V_7 , V_158 ) ;
break;
default:
V_159 = - V_166 ;
break;
}
return V_159 ;
}
static int F_92 ( struct V_7 * V_7 , struct V_157 * V_158 )
{
int V_159 ;
switch ( V_158 -> V_218 ) {
case V_219 :
switch ( V_158 -> V_158 ) {
case V_168 :
case V_171 :
V_159 = V_57 . V_169 ? 0 : - V_166 ;
break;
case V_160 :
V_159 = 0 ;
break;
default:
V_159 = - V_166 ;
break;
}
break;
case V_220 :
switch ( V_158 -> V_158 ) {
case V_192 :
case V_191 :
V_159 = 0 ;
break;
default:
V_159 = - V_166 ;
break;
}
break;
case V_221 :
switch ( V_158 -> V_158 ) {
case V_207 :
case V_215 :
case V_208 :
case V_216 :
case V_217 :
V_159 = 0 ;
break;
case V_209 :
default:
V_159 = - V_166 ;
break;
}
break;
case V_222 :
switch ( V_158 -> V_158 ) {
case V_179 :
case V_184 :
case V_187 :
case V_188 :
V_159 = 0 ;
break;
default:
V_159 = - V_166 ;
break;
}
break;
default:
V_159 = - V_166 ;
break;
}
return V_159 ;
}
static long F_93 ( struct V_7 * V_7 , struct V_223 * args )
{
T_5 * V_224 ;
T_6 V_225 ;
int V_10 , V_88 = 0 ;
if ( args -> V_146 != 0 )
return - V_86 ;
if ( ! F_94 ( V_132 -> V_131 ) )
return V_226 ;
if ( args -> V_227 < 1 || args -> V_227 > V_228 )
return - V_86 ;
V_224 = F_95 ( args -> V_227 , sizeof( T_5 ) ,
V_197 | V_229 ) ;
if ( ! V_224 )
V_224 = F_96 ( sizeof( T_5 ) * args -> V_227 ) ;
if ( ! V_224 )
return - V_77 ;
F_97 ( & V_132 -> V_131 -> V_230 ) ;
for ( V_10 = 0 ; V_10 < args -> V_227 ; V_10 ++ ) {
V_225 = F_98 ( V_7 , args -> V_231 + V_10 ) ;
if ( F_99 ( V_225 ) ) {
V_88 = - V_165 ;
break;
}
V_88 = F_100 ( V_132 -> V_131 , V_225 , & V_224 [ V_10 ] ) ;
if ( V_88 )
break;
}
F_101 ( & V_132 -> V_131 -> V_230 ) ;
if ( ! V_88 ) {
V_88 = F_69 ( ( T_5 V_163 * ) args -> V_232 , V_224 ,
sizeof( T_5 ) * args -> V_227 ) ;
if ( V_88 )
V_88 = - V_165 ;
}
F_102 ( V_224 ) ;
return V_88 ;
}
static long F_103 ( struct V_7 * V_7 , struct V_223 * args )
{
T_5 * V_224 ;
T_6 V_225 ;
int V_10 , V_88 = 0 ;
if ( args -> V_146 != 0 )
return - V_86 ;
if ( args -> V_227 < 1 || args -> V_227 > V_228 )
return - V_86 ;
V_224 = F_95 ( args -> V_227 , sizeof( T_5 ) ,
V_197 | V_229 ) ;
if ( ! V_224 )
V_224 = F_96 ( sizeof( T_5 ) * args -> V_227 ) ;
if ( ! V_224 )
return - V_77 ;
V_88 = F_64 ( V_224 , ( T_5 V_163 * ) args -> V_232 ,
sizeof( T_5 ) * args -> V_227 ) ;
if ( V_88 ) {
V_88 = - V_165 ;
goto V_140;
}
V_88 = F_104 () ;
if ( V_88 )
goto V_140;
F_97 ( & V_132 -> V_131 -> V_230 ) ;
for ( V_10 = 0 ; V_10 < args -> V_227 ; V_10 ++ ) {
V_225 = F_98 ( V_7 , args -> V_231 + V_10 ) ;
if ( F_99 ( V_225 ) ) {
V_88 = - V_165 ;
break;
}
if ( V_224 [ V_10 ] & 0x01 ) {
V_88 = - V_86 ;
break;
}
V_88 = F_105 ( V_132 -> V_131 , V_225 , V_224 [ V_10 ] , 0 ) ;
if ( V_88 )
break;
}
F_101 ( & V_132 -> V_131 -> V_230 ) ;
V_140:
F_102 ( V_224 ) ;
return V_88 ;
}
long F_106 ( struct V_81 * V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
struct V_7 * V_7 = V_82 -> V_233 ;
void V_163 * V_234 = ( void V_163 * ) V_84 ;
struct V_157 V_158 ;
int V_88 ;
switch ( V_83 ) {
case V_235 : {
struct V_236 V_237 ;
V_88 = - V_165 ;
if ( F_64 ( & V_237 , V_234 , sizeof( V_237 ) ) )
break;
V_88 = F_107 ( V_7 , & V_237 ) ;
break;
}
case V_238 : {
struct V_144 V_145 ;
V_88 = - V_165 ;
if ( F_64 ( & V_145 , V_234 , sizeof( V_145 ) ) )
break;
V_88 = F_45 ( V_7 , & V_145 ) ;
break;
}
case V_239 : {
struct V_240 V_241 ;
V_88 = - V_86 ;
if ( V_7 -> V_12 . V_147 ) {
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_88 = F_108 ( V_7 , & V_241 , 0 , 0 ) ;
}
break;
}
case V_242 : {
V_88 = - V_165 ;
if ( F_64 ( & V_158 , ( void V_163 * ) V_84 , sizeof( V_158 ) ) )
break;
V_88 = F_90 ( V_7 , & V_158 ) ;
break;
}
case V_243 : {
V_88 = - V_165 ;
if ( F_64 ( & V_158 , ( void V_163 * ) V_84 , sizeof( V_158 ) ) )
break;
V_88 = F_91 ( V_7 , & V_158 ) ;
break;
}
case V_244 : {
V_88 = - V_165 ;
if ( F_64 ( & V_158 , ( void V_163 * ) V_84 , sizeof( V_158 ) ) )
break;
V_88 = F_92 ( V_7 , & V_158 ) ;
break;
}
case V_245 : {
struct V_223 args ;
V_88 = - V_165 ;
if ( F_64 ( & args , V_234 ,
sizeof( struct V_223 ) ) )
break;
V_88 = F_93 ( V_7 , & args ) ;
break;
}
case V_246 : {
struct V_223 args ;
V_88 = - V_165 ;
if ( F_64 ( & args , V_234 ,
sizeof( struct V_223 ) ) )
break;
V_88 = F_103 ( V_7 , & args ) ;
break;
}
default:
V_88 = - V_247 ;
}
return V_88 ;
}
static int F_109 ( T_3 * V_248 )
{
T_7 V_249 = 0x04000000UL ;
T_7 V_29 = 0 ;
memset ( V_248 , 0 , 128 ) ;
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
T_3 V_248 [ 128 ] ;
int V_29 ;
if ( F_18 ( 12 ) ) {
V_29 = F_109 ( V_248 ) ;
if ( V_29 )
F_111 ( L_25 , V_29 ) ;
else
return V_248 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_112 ( struct V_7 * V_7 )
{
V_7 -> V_12 . V_180 . V_250 = ( V_251 ) ( unsigned long ) V_7 -> V_12 . V_180 . V_181 ;
if ( F_110 () )
V_7 -> V_12 . V_180 . V_250 |= V_252 ;
else
V_7 -> V_12 . V_180 . V_250 |= V_253 ;
}
static V_162 F_113 ( void )
{
struct V_198 V_198 ;
F_84 ( & V_198 ) ;
V_198 . V_254 = 0xff ;
return * ( ( V_162 * ) & V_198 ) ;
}
static void F_114 ( struct V_7 * V_7 )
{
if ( ! F_59 ( V_7 , 76 ) )
return;
V_7 -> V_12 . V_180 . V_181 = & V_7 -> V_12 . V_255 -> V_181 ;
F_112 ( V_7 ) ;
V_7 -> V_12 . V_180 . V_183 = 1 ;
V_7 -> V_12 . V_180 . V_186 = 1 ;
F_60 ( V_7 -> V_12 . V_180 . V_181 -> V_182 ,
sizeof( V_7 -> V_12 . V_180 . V_181 -> V_182 ) ) ;
F_60 ( V_7 -> V_12 . V_180 . V_181 -> V_185 ,
sizeof( V_7 -> V_12 . V_180 . V_181 -> V_185 ) ) ;
}
static void F_115 ( struct V_7 * V_7 )
{
if ( V_7 -> V_12 . V_256 )
F_116 ( V_7 -> V_12 . V_257 , sizeof( struct V_258 ) ) ;
else
F_117 ( ( unsigned long ) ( V_7 -> V_12 . V_257 ) ) ;
V_7 -> V_12 . V_257 = NULL ;
}
int F_118 ( struct V_7 * V_7 , unsigned long type )
{
T_8 V_259 = V_197 ;
int V_10 , V_260 ;
char V_261 [ 16 ] ;
static unsigned long V_262 ;
V_260 = - V_86 ;
#ifdef F_30
if ( type & ~ V_263 )
goto V_264;
if ( ( type & V_263 ) && ( ! F_119 ( V_265 ) ) )
goto V_264;
#else
if ( type )
goto V_264;
#endif
V_260 = F_28 () ;
if ( V_260 )
goto V_264;
V_260 = - V_77 ;
F_120 ( & V_7 -> V_12 . V_266 , 5 * V_267 , 500 ) ;
V_7 -> V_12 . V_256 = 0 ;
if ( ! V_57 . V_59 )
V_259 |= V_268 ;
F_121 ( & V_7 -> V_12 . V_269 ) ;
V_7 -> V_12 . V_257 = (struct V_270 * ) F_122 ( V_259 ) ;
if ( ! V_7 -> V_12 . V_257 )
goto V_264;
F_123 ( & V_271 ) ;
V_262 += 16 ;
if ( V_262 + sizeof( struct V_270 ) > V_272 )
V_262 = 0 ;
V_7 -> V_12 . V_257 = (struct V_270 * )
( ( char * ) V_7 -> V_12 . V_257 + V_262 ) ;
F_124 ( & V_271 ) ;
sprintf ( V_261 , L_26 , V_132 -> V_273 ) ;
V_7 -> V_12 . V_274 = F_22 ( V_261 , 32 , 1 , 7 * sizeof( long ) ) ;
if ( ! V_7 -> V_12 . V_274 )
goto V_264;
V_7 -> V_12 . V_255 =
(struct V_255 * ) F_122 ( V_197 | V_268 ) ;
if ( ! V_7 -> V_12 . V_255 )
goto V_264;
memcpy ( V_7 -> V_12 . V_152 . V_153 , V_212 . V_213 ,
V_200 ) ;
for ( V_10 = 0 ; V_10 < V_275 ; V_10 ++ ) {
if ( V_10 < F_1 () )
V_7 -> V_12 . V_152 . V_153 [ V_10 ] &= V_1 [ V_10 ] ;
else
V_7 -> V_12 . V_152 . V_153 [ V_10 ] = 0UL ;
}
V_7 -> V_12 . V_152 . V_154 = V_7 -> V_12 . V_255 -> V_154 ;
memcpy ( V_7 -> V_12 . V_152 . V_154 , V_7 -> V_12 . V_152 . V_153 ,
V_200 ) ;
F_47 ( V_7 -> V_12 . V_152 . V_153 , 74 ) ;
F_47 ( V_7 -> V_12 . V_152 . V_154 , 74 ) ;
V_7 -> V_12 . V_152 . V_198 = F_113 () ;
V_7 -> V_12 . V_152 . V_199 = V_57 . V_199 & 0x0fff ;
F_114 ( V_7 ) ;
F_125 ( & V_7 -> V_12 . V_276 . V_149 ) ;
for ( V_10 = 0 ; V_10 < V_277 ; V_10 ++ )
F_126 ( & V_7 -> V_12 . V_276 . V_278 [ V_10 ] ) ;
F_127 ( & V_7 -> V_12 . V_279 ) ;
F_128 ( & V_7 -> V_12 . V_280 ) ;
F_23 ( V_7 -> V_12 . V_274 , & V_78 ) ;
F_46 ( V_7 , 3 , L_27 , type ) ;
if ( type & V_263 ) {
V_7 -> V_12 . V_128 = NULL ;
V_7 -> V_12 . V_161 = V_174 ;
} else {
if ( V_57 . V_281 == V_282 )
V_7 -> V_12 . V_161 = V_283 ;
else
V_7 -> V_12 . V_161 = F_129 (unsigned long, TASK_MAX_SIZE,
sclp.hamax + 1 ) ;
V_7 -> V_12 . V_128 = F_56 ( V_132 -> V_131 , V_7 -> V_12 . V_161 - 1 ) ;
if ( ! V_7 -> V_12 . V_128 )
goto V_264;
V_7 -> V_12 . V_128 -> V_177 = V_7 ;
V_7 -> V_12 . V_128 -> V_284 = 0 ;
}
V_7 -> V_12 . V_285 = 0 ;
V_7 -> V_12 . V_147 = 0 ;
V_7 -> V_12 . V_13 = 0 ;
F_125 ( & V_7 -> V_12 . V_286 ) ;
F_130 ( V_7 ) ;
F_131 ( 3 , L_28 , V_7 , V_132 -> V_273 ) ;
return 0 ;
V_264:
F_117 ( ( unsigned long ) V_7 -> V_12 . V_255 ) ;
F_24 ( V_7 -> V_12 . V_274 ) ;
F_115 ( V_7 ) ;
F_131 ( 3 , L_29 , V_260 ) ;
return V_260 ;
}
void F_132 ( struct V_8 * V_9 )
{
F_133 ( V_9 , 3 , L_3 , L_30 ) ;
F_134 ( V_9 -> V_287 ) ;
F_135 ( V_9 ) ;
F_136 ( V_9 ) ;
if ( ! F_54 ( V_9 -> V_7 ) )
F_137 ( V_9 ) ;
if ( F_54 ( V_9 -> V_7 ) )
F_57 ( V_9 -> V_12 . V_128 ) ;
if ( V_9 -> V_7 -> V_12 . V_170 )
F_138 ( V_9 ) ;
F_117 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
F_139 ( V_9 ) ;
F_140 ( V_288 , V_9 ) ;
}
static void F_141 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm)
F_132 ( V_9 ) ;
F_38 ( & V_7 -> V_149 ) ;
for ( V_10 = 0 ; V_10 < F_78 ( & V_7 -> V_205 ) ; V_10 ++ )
V_7 -> V_289 [ V_10 ] = NULL ;
F_142 ( & V_7 -> V_205 , 0 ) ;
F_42 ( & V_7 -> V_149 ) ;
}
void F_143 ( struct V_7 * V_7 )
{
F_141 ( V_7 ) ;
F_115 ( V_7 ) ;
F_24 ( V_7 -> V_12 . V_274 ) ;
F_117 ( ( unsigned long ) V_7 -> V_12 . V_255 ) ;
if ( ! F_54 ( V_7 ) )
F_57 ( V_7 -> V_12 . V_128 ) ;
F_144 ( V_7 ) ;
F_145 ( V_7 ) ;
F_146 ( V_7 ) ;
F_131 ( 3 , L_31 , V_7 ) ;
}
static int F_147 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_128 = F_56 ( V_132 -> V_131 , - 1UL ) ;
if ( ! V_9 -> V_12 . V_128 )
return - V_77 ;
V_9 -> V_12 . V_128 -> V_177 = V_9 -> V_7 ;
return 0 ;
}
static void F_137 ( struct V_8 * V_9 )
{
F_148 ( & V_9 -> V_7 -> V_12 . V_269 ) ;
if ( V_9 -> V_7 -> V_12 . V_256 ) {
struct V_258 * V_257 = V_9 -> V_7 -> V_12 . V_257 ;
F_149 ( V_9 -> V_287 , ( unsigned long * ) V_257 -> V_290 ) ;
V_257 -> V_291 [ V_9 -> V_287 ] . V_292 = 0 ;
} else {
struct V_270 * V_257 = V_9 -> V_7 -> V_12 . V_257 ;
F_149 ( V_9 -> V_287 , ( unsigned long * ) & V_257 -> V_290 ) ;
V_257 -> V_291 [ V_9 -> V_287 ] . V_292 = 0 ;
}
F_150 ( & V_9 -> V_7 -> V_12 . V_269 ) ;
}
static void F_151 ( struct V_8 * V_9 )
{
F_148 ( & V_9 -> V_7 -> V_12 . V_269 ) ;
if ( V_9 -> V_7 -> V_12 . V_256 ) {
struct V_258 * V_257 = V_9 -> V_7 -> V_12 . V_257 ;
V_257 -> V_291 [ V_9 -> V_287 ] . V_292 = ( V_293 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_294 = ( V_251 ) ( ( ( V_293 ) V_257 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_295 = ( V_251 ) ( V_293 ) V_257 & ~ 0x3fU ;
V_9 -> V_12 . V_14 -> V_296 |= 0x04U ;
F_15 ( V_9 -> V_287 , ( unsigned long * ) V_257 -> V_290 ) ;
} else {
struct V_270 * V_257 = V_9 -> V_7 -> V_12 . V_257 ;
V_257 -> V_291 [ V_9 -> V_287 ] . V_292 = ( V_293 ) V_9 -> V_12 . V_14 ;
V_9 -> V_12 . V_14 -> V_294 = ( V_251 ) ( ( ( V_293 ) V_257 ) >> 32 ) ;
V_9 -> V_12 . V_14 -> V_295 = ( V_251 ) ( V_293 ) V_257 ;
F_15 ( V_9 -> V_287 , ( unsigned long * ) & V_257 -> V_290 ) ;
}
F_150 ( & V_9 -> V_7 -> V_12 . V_269 ) ;
}
static inline void F_152 ( struct V_297 * V_298 , struct V_299 * V_300 )
{
V_298 -> V_292 = V_300 -> V_292 ;
V_298 -> V_301 . V_302 = V_300 -> V_301 . V_302 ;
V_298 -> V_301 . V_303 = V_300 -> V_301 . V_303 ;
}
static void F_153 ( struct V_258 * V_298 , struct V_270 * V_300 )
{
int V_10 ;
V_298 -> V_304 = V_300 -> V_304 ;
V_298 -> V_290 [ 0 ] = V_300 -> V_290 ;
for ( V_10 = 0 ; V_10 < V_114 ; V_10 ++ )
F_152 ( & V_298 -> V_291 [ V_10 ] , & V_300 -> V_291 [ V_10 ] ) ;
}
static int F_154 ( struct V_7 * V_7 )
{
struct V_270 * V_305 = V_7 -> V_12 . V_257 ;
struct V_258 * V_306 ;
struct V_8 * V_9 ;
unsigned int V_307 ;
T_7 V_295 , V_294 ;
V_306 = F_155 ( sizeof( * V_306 ) , V_197 | V_308 ) ;
if ( ! V_306 )
return - V_77 ;
V_294 = ( T_7 ) ( ( V_162 ) ( V_306 ) >> 32 ) ;
V_295 = ( T_7 ) ( V_162 ) ( V_306 ) & ~ 0x3fU ;
F_156 ( V_7 ) ;
F_157 ( & V_7 -> V_12 . V_269 ) ;
F_153 ( V_306 , V_305 ) ;
F_7 (vcpu_idx, vcpu, kvm) {
V_9 -> V_12 . V_14 -> V_294 = V_294 ;
V_9 -> V_12 . V_14 -> V_295 = V_295 ;
V_9 -> V_12 . V_14 -> V_296 |= 0x04U ;
}
V_7 -> V_12 . V_257 = V_306 ;
V_7 -> V_12 . V_256 = 1 ;
F_158 ( & V_7 -> V_12 . V_269 ) ;
F_159 ( V_7 ) ;
F_117 ( ( unsigned long ) V_305 ) ;
F_46 ( V_7 , 2 , L_32 ,
V_305 , V_7 -> V_12 . V_257 ) ;
return 0 ;
}
static int F_160 ( struct V_7 * V_7 , unsigned int V_309 )
{
int V_260 ;
if ( V_309 < V_114 )
return true ;
if ( ! V_57 . V_115 || ! V_57 . V_59 )
return false ;
F_38 ( & V_7 -> V_149 ) ;
V_260 = V_7 -> V_12 . V_256 ? 0 : F_154 ( V_7 ) ;
F_42 ( & V_7 -> V_149 ) ;
return V_260 == 0 && V_309 < V_116 ;
}
int F_161 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_310 = V_311 ;
F_136 ( V_9 ) ;
V_9 -> V_312 -> V_313 = V_314 |
V_315 |
V_316 |
V_317 |
V_318 |
V_319 ;
F_162 ( V_9 , 0 ) ;
if ( F_59 ( V_9 -> V_7 , 64 ) )
V_9 -> V_312 -> V_313 |= V_320 ;
if ( V_121 )
V_9 -> V_312 -> V_313 |= V_321 ;
else
V_9 -> V_312 -> V_313 |= V_322 ;
if ( F_54 ( V_9 -> V_7 ) )
return F_147 ( V_9 ) ;
return 0 ;
}
static void F_163 ( struct V_8 * V_9 )
{
F_164 ( V_9 -> V_12 . V_16 != 0 ) ;
F_165 ( & V_9 -> V_12 . V_323 ) ;
V_9 -> V_12 . V_16 = F_166 () ;
F_167 ( & V_9 -> V_12 . V_323 ) ;
}
static void F_168 ( struct V_8 * V_9 )
{
F_164 ( V_9 -> V_12 . V_16 == 0 ) ;
F_165 ( & V_9 -> V_12 . V_323 ) ;
V_9 -> V_12 . V_14 -> V_324 -= F_166 () - V_9 -> V_12 . V_16 ;
V_9 -> V_12 . V_16 = 0 ;
F_167 ( & V_9 -> V_12 . V_323 ) ;
}
static void F_169 ( struct V_8 * V_9 )
{
F_164 ( V_9 -> V_12 . V_15 ) ;
V_9 -> V_12 . V_15 = true ;
F_163 ( V_9 ) ;
}
static void F_170 ( struct V_8 * V_9 )
{
F_164 ( ! V_9 -> V_12 . V_15 ) ;
F_168 ( V_9 ) ;
V_9 -> V_12 . V_15 = false ;
}
static void F_171 ( struct V_8 * V_9 )
{
F_172 () ;
F_169 ( V_9 ) ;
F_173 () ;
}
static void F_174 ( struct V_8 * V_9 )
{
F_172 () ;
F_170 ( V_9 ) ;
F_173 () ;
}
void F_175 ( struct V_8 * V_9 , V_293 V_324 )
{
F_172 () ;
F_165 ( & V_9 -> V_12 . V_323 ) ;
if ( V_9 -> V_12 . V_15 )
V_9 -> V_12 . V_16 = F_166 () ;
V_9 -> V_12 . V_14 -> V_324 = V_324 ;
F_167 ( & V_9 -> V_12 . V_323 ) ;
F_173 () ;
}
V_293 F_176 ( struct V_8 * V_9 )
{
unsigned int V_325 ;
V_293 V_326 ;
if ( F_177 ( ! V_9 -> V_12 . V_15 ) )
return V_9 -> V_12 . V_14 -> V_324 ;
F_172 () ;
do {
V_325 = F_178 ( & V_9 -> V_12 . V_323 ) ;
F_164 ( ( V_325 & 1 ) && F_179 () == V_9 -> V_291 ) ;
V_326 = V_9 -> V_12 . V_14 -> V_324 ;
if ( F_180 ( V_9 -> V_12 . V_16 ) )
V_326 -= F_166 () - V_9 -> V_12 . V_16 ;
} while ( F_181 ( & V_9 -> V_12 . V_323 , V_325 & ~ 1 ) );
F_173 () ;
return V_326 ;
}
void F_182 ( struct V_8 * V_9 , int V_291 )
{
F_183 () ;
V_9 -> V_12 . V_327 . V_328 = V_132 -> V_329 . V_330 . V_328 ;
V_9 -> V_12 . V_327 . V_331 = V_132 -> V_329 . V_330 . V_331 ;
if ( V_121 )
V_132 -> V_329 . V_330 . V_331 = V_9 -> V_312 -> V_300 . V_331 . V_332 ;
else
V_132 -> V_329 . V_330 . V_331 = V_9 -> V_312 -> V_300 . V_331 . V_333 ;
V_132 -> V_329 . V_330 . V_328 = V_9 -> V_312 -> V_300 . V_331 . V_328 ;
if ( F_184 ( V_132 -> V_329 . V_330 . V_328 ) )
V_132 -> V_329 . V_330 . V_328 = 0 ;
F_185 ( V_9 -> V_12 . V_334 ) ;
F_186 ( V_9 -> V_312 -> V_300 . V_331 . V_335 ) ;
F_187 ( V_9 -> V_12 . V_336 ) ;
F_188 ( V_337 , & V_9 -> V_12 . V_14 -> V_338 ) ;
if ( V_9 -> V_12 . V_15 && ! F_189 ( V_9 ) )
F_163 ( V_9 ) ;
V_9 -> V_291 = V_291 ;
}
void F_190 ( struct V_8 * V_9 )
{
V_9 -> V_291 = - 1 ;
if ( V_9 -> V_12 . V_15 && ! F_189 ( V_9 ) )
F_168 ( V_9 ) ;
F_191 ( V_337 , & V_9 -> V_12 . V_14 -> V_338 ) ;
V_9 -> V_12 . V_336 = F_192 () ;
F_193 ( V_9 -> V_12 . V_336 ) ;
F_183 () ;
V_9 -> V_312 -> V_300 . V_331 . V_328 = V_132 -> V_329 . V_330 . V_328 ;
V_132 -> V_329 . V_330 . V_328 = V_9 -> V_12 . V_327 . V_328 ;
V_132 -> V_329 . V_330 . V_331 = V_9 -> V_12 . V_327 . V_331 ;
F_185 ( V_9 -> V_312 -> V_300 . V_331 . V_335 ) ;
F_186 ( V_9 -> V_12 . V_334 ) ;
}
static void F_194 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_339 . V_340 = 0UL ;
V_9 -> V_12 . V_14 -> V_339 . V_164 = 0UL ;
F_162 ( V_9 , 0 ) ;
F_175 ( V_9 , 0 ) ;
V_9 -> V_12 . V_14 -> V_341 = 0UL ;
V_9 -> V_12 . V_14 -> V_342 = 0 ;
memset ( V_9 -> V_12 . V_14 -> V_343 , 0 , 16 * sizeof( V_293 ) ) ;
V_9 -> V_12 . V_14 -> V_343 [ 0 ] = 0xE0UL ;
V_9 -> V_12 . V_14 -> V_343 [ 14 ] = 0xC2000000UL ;
F_183 () ;
V_132 -> V_329 . V_330 . V_328 = 0 ;
V_9 -> V_12 . V_14 -> V_344 = 1 ;
V_9 -> V_12 . V_14 -> V_345 = 0 ;
V_9 -> V_12 . V_310 = V_311 ;
F_136 ( V_9 ) ;
if ( ! F_195 ( V_9 -> V_7 ) )
F_196 ( V_9 ) ;
F_135 ( V_9 ) ;
}
void F_197 ( struct V_8 * V_9 )
{
F_38 ( & V_9 -> V_7 -> V_149 ) ;
F_172 () ;
V_9 -> V_12 . V_14 -> V_13 = V_9 -> V_7 -> V_12 . V_13 ;
F_173 () ;
F_42 ( & V_9 -> V_7 -> V_149 ) ;
if ( ! F_54 ( V_9 -> V_7 ) ) {
V_9 -> V_12 . V_128 = V_9 -> V_7 -> V_12 . V_128 ;
F_151 ( V_9 ) ;
}
if ( F_59 ( V_9 -> V_7 , 74 ) || V_9 -> V_7 -> V_12 . V_156 )
V_9 -> V_12 . V_14 -> V_346 |= V_347 ;
V_9 -> V_12 . V_336 = V_9 -> V_12 . V_128 ;
}
static void F_61 ( struct V_8 * V_9 )
{
if ( ! F_59 ( V_9 -> V_7 , 76 ) )
return;
V_9 -> V_12 . V_14 -> V_348 &= ~ ( V_349 | V_350 ) ;
if ( V_9 -> V_7 -> V_12 . V_180 . V_183 )
V_9 -> V_12 . V_14 -> V_348 |= V_349 ;
if ( V_9 -> V_7 -> V_12 . V_180 . V_186 )
V_9 -> V_12 . V_14 -> V_348 |= V_350 ;
V_9 -> V_12 . V_14 -> V_250 = V_9 -> V_7 -> V_12 . V_180 . V_250 ;
}
void F_138 ( struct V_8 * V_9 )
{
F_117 ( V_9 -> V_12 . V_14 -> V_351 ) ;
V_9 -> V_12 . V_14 -> V_351 = 0 ;
}
int F_198 ( struct V_8 * V_9 )
{
V_9 -> V_12 . V_14 -> V_351 = F_122 ( V_197 ) ;
if ( ! V_9 -> V_12 . V_14 -> V_351 )
return - V_77 ;
V_9 -> V_12 . V_14 -> V_296 |= 0x80 ;
V_9 -> V_12 . V_14 -> V_296 &= ~ 0x08 ;
return 0 ;
}
static void F_199 ( struct V_8 * V_9 )
{
struct V_352 * V_152 = & V_9 -> V_7 -> V_12 . V_152 ;
V_9 -> V_12 . V_14 -> V_199 = V_152 -> V_199 ;
if ( F_59 ( V_9 -> V_7 , 7 ) )
V_9 -> V_12 . V_14 -> V_353 = ( T_7 ) ( V_162 ) V_152 -> V_154 ;
}
int F_200 ( struct V_8 * V_9 )
{
int V_260 = 0 ;
F_142 ( & V_9 -> V_12 . V_14 -> V_338 , V_354 |
V_355 |
V_356 ) ;
if ( F_59 ( V_9 -> V_7 , 78 ) )
F_188 ( V_357 , & V_9 -> V_12 . V_14 -> V_338 ) ;
else if ( F_59 ( V_9 -> V_7 , 8 ) )
F_188 ( V_358 , & V_9 -> V_12 . V_14 -> V_338 ) ;
F_199 ( V_9 ) ;
if ( V_55 )
V_9 -> V_12 . V_14 -> V_359 |= 0x02 ;
if ( F_59 ( V_9 -> V_7 , 9 ) )
V_9 -> V_12 . V_14 -> V_359 |= 0x04 ;
if ( F_59 ( V_9 -> V_7 , 73 ) )
V_9 -> V_12 . V_14 -> V_359 |= 0x10 ;
if ( F_59 ( V_9 -> V_7 , 8 ) && V_57 . V_360 )
V_9 -> V_12 . V_14 -> V_296 |= 0x08 ;
V_9 -> V_12 . V_14 -> V_361 = 0x1002000U ;
if ( V_57 . V_71 )
V_9 -> V_12 . V_14 -> V_361 |= 0x80000000U ;
if ( V_57 . V_69 )
V_9 -> V_12 . V_14 -> V_361 |= 0x40000000U ;
if ( V_57 . V_63 )
V_9 -> V_12 . V_14 -> V_361 |= 1 ;
if ( V_57 . V_362 )
V_9 -> V_12 . V_14 -> V_361 |= 0x10000000U ;
if ( F_59 ( V_9 -> V_7 , 64 ) )
V_9 -> V_12 . V_14 -> V_348 |= 0x01 ;
if ( F_59 ( V_9 -> V_7 , 129 ) ) {
V_9 -> V_12 . V_14 -> V_361 |= 0x00020000 ;
V_9 -> V_12 . V_14 -> V_363 |= 0x20000000 ;
}
V_9 -> V_12 . V_14 -> V_364 = ( unsigned long ) & V_9 -> V_312 -> V_300 . V_331 . V_365 ;
V_9 -> V_12 . V_14 -> V_346 |= V_366 | V_367 | V_368 ;
if ( V_9 -> V_7 -> V_12 . V_170 ) {
V_260 = F_198 ( V_9 ) ;
if ( V_260 )
return V_260 ;
}
F_201 ( & V_9 -> V_12 . V_369 , V_370 , V_371 ) ;
V_9 -> V_12 . V_369 . V_372 = V_373 ;
F_61 ( V_9 ) ;
return V_260 ;
}
struct V_8 * F_202 ( struct V_7 * V_7 ,
unsigned int V_309 )
{
struct V_8 * V_9 ;
struct V_374 * V_374 ;
int V_260 = - V_86 ;
if ( ! F_54 ( V_7 ) && ! F_160 ( V_7 , V_309 ) )
goto V_140;
V_260 = - V_77 ;
V_9 = F_203 ( V_288 , V_197 ) ;
if ( ! V_9 )
goto V_140;
V_374 = (struct V_374 * ) F_122 ( V_197 ) ;
if ( ! V_374 )
goto V_375;
V_9 -> V_12 . V_14 = & V_374 -> V_14 ;
V_9 -> V_12 . V_14 -> V_376 = ( unsigned long ) & V_374 -> V_377 ;
V_9 -> V_12 . V_14 -> V_378 = 0 ;
V_9 -> V_12 . V_14 -> V_379 = V_57 . V_281 ;
V_9 -> V_12 . V_14 -> V_380 = V_309 ;
F_125 ( & V_9 -> V_12 . V_381 . V_149 ) ;
V_9 -> V_12 . V_381 . V_276 = & V_7 -> V_12 . V_276 ;
V_9 -> V_12 . V_381 . V_382 = & V_9 -> V_382 ;
V_9 -> V_12 . V_381 . V_338 = & V_9 -> V_12 . V_14 -> V_338 ;
F_204 ( & V_9 -> V_12 . V_323 ) ;
V_260 = F_205 ( V_9 , V_7 , V_309 ) ;
if ( V_260 )
goto V_383;
F_46 ( V_7 , 3 , L_33 , V_309 , V_9 ,
V_9 -> V_12 . V_14 ) ;
F_206 ( V_309 , V_9 , V_9 -> V_12 . V_14 ) ;
return V_9 ;
V_383:
F_117 ( ( unsigned long ) ( V_9 -> V_12 . V_14 ) ) ;
V_375:
F_140 ( V_288 , V_9 ) ;
V_140:
return F_207 ( V_260 ) ;
}
int F_208 ( struct V_8 * V_9 )
{
return F_209 ( V_9 , 0 ) ;
}
void F_210 ( struct V_8 * V_9 )
{
F_188 ( V_384 , & V_9 -> V_12 . V_14 -> V_385 ) ;
F_62 ( V_9 ) ;
}
void F_211 ( struct V_8 * V_9 )
{
F_191 ( V_384 , & V_9 -> V_12 . V_14 -> V_385 ) ;
}
static void F_212 ( struct V_8 * V_9 )
{
F_188 ( V_386 , & V_9 -> V_12 . V_14 -> V_385 ) ;
F_62 ( V_9 ) ;
}
static void F_213 ( struct V_8 * V_9 )
{
F_191 ( V_386 , & V_9 -> V_12 . V_14 -> V_385 ) ;
}
void F_62 ( struct V_8 * V_9 )
{
F_188 ( V_387 , & V_9 -> V_12 . V_14 -> V_338 ) ;
while ( V_9 -> V_12 . V_14 -> V_388 & V_389 )
F_214 () ;
}
void F_44 ( int V_390 , struct V_8 * V_9 )
{
F_215 ( V_390 , V_9 ) ;
F_212 ( V_9 ) ;
}
static void V_21 ( struct V_128 * V_128 , unsigned long V_391 ,
unsigned long V_392 )
{
struct V_7 * V_7 = V_128 -> V_177 ;
struct V_8 * V_9 ;
unsigned long V_393 ;
int V_10 ;
if ( F_216 ( V_128 ) )
return;
if ( V_391 >= 1UL << 31 )
return;
F_7 (i, vcpu, kvm) {
V_393 = F_217 ( V_9 ) ;
if ( V_393 <= V_392 && V_391 <= V_393 + 2 * V_272 - 1 ) {
F_133 ( V_9 , 2 , L_34 ,
V_391 , V_392 ) ;
F_44 ( V_394 , V_9 ) ;
}
}
}
int F_218 ( struct V_8 * V_9 )
{
F_219 () ;
return 0 ;
}
static int F_220 ( struct V_8 * V_9 ,
struct V_395 * V_396 )
{
int V_88 = - V_86 ;
switch ( V_396 -> V_309 ) {
case V_397 :
V_88 = F_49 ( V_9 -> V_12 . V_14 -> V_342 ,
( T_7 V_163 * ) V_396 -> V_164 ) ;
break;
case V_398 :
V_88 = F_49 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_399 :
V_88 = F_49 ( F_176 ( V_9 ) ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_400 :
V_88 = F_49 ( V_9 -> V_12 . V_14 -> V_341 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_401 :
V_88 = F_49 ( V_9 -> V_12 . V_310 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_402 :
V_88 = F_49 ( V_9 -> V_12 . V_403 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_404 :
V_88 = F_49 ( V_9 -> V_12 . V_405 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_406 :
V_88 = F_49 ( V_9 -> V_12 . V_14 -> V_345 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_407 :
V_88 = F_49 ( V_9 -> V_12 . V_14 -> V_344 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
default:
break;
}
return V_88 ;
}
static int F_221 ( struct V_8 * V_9 ,
struct V_395 * V_396 )
{
int V_88 = - V_86 ;
V_293 V_5 ;
switch ( V_396 -> V_309 ) {
case V_397 :
V_88 = F_55 ( V_9 -> V_12 . V_14 -> V_342 ,
( T_7 V_163 * ) V_396 -> V_164 ) ;
break;
case V_398 :
V_88 = F_55 ( V_9 -> V_12 . V_14 -> V_13 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_399 :
V_88 = F_55 ( V_5 , ( V_162 V_163 * ) V_396 -> V_164 ) ;
if ( ! V_88 )
F_175 ( V_9 , V_5 ) ;
break;
case V_400 :
V_88 = F_55 ( V_9 -> V_12 . V_14 -> V_341 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_401 :
V_88 = F_55 ( V_9 -> V_12 . V_310 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
if ( V_9 -> V_12 . V_310 == V_311 )
F_136 ( V_9 ) ;
break;
case V_402 :
V_88 = F_55 ( V_9 -> V_12 . V_403 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_404 :
V_88 = F_55 ( V_9 -> V_12 . V_405 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_406 :
V_88 = F_55 ( V_9 -> V_12 . V_14 -> V_345 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
case V_407 :
V_88 = F_55 ( V_9 -> V_12 . V_14 -> V_344 ,
( V_162 V_163 * ) V_396 -> V_164 ) ;
break;
default:
break;
}
return V_88 ;
}
static int F_222 ( struct V_8 * V_9 )
{
F_194 ( V_9 ) ;
return 0 ;
}
int F_223 ( struct V_8 * V_9 , struct V_408 * V_331 )
{
memcpy ( & V_9 -> V_312 -> V_300 . V_331 . V_409 , & V_331 -> V_409 , sizeof( V_331 -> V_409 ) ) ;
return 0 ;
}
int F_224 ( struct V_8 * V_9 , struct V_408 * V_331 )
{
memcpy ( & V_331 -> V_409 , & V_9 -> V_312 -> V_300 . V_331 . V_409 , sizeof( V_331 -> V_409 ) ) ;
return 0 ;
}
int F_225 ( struct V_8 * V_9 ,
struct V_410 * V_411 )
{
memcpy ( & V_9 -> V_312 -> V_300 . V_331 . V_335 , & V_411 -> V_335 , sizeof( V_411 -> V_335 ) ) ;
memcpy ( & V_9 -> V_12 . V_14 -> V_343 , & V_411 -> V_412 , sizeof( V_411 -> V_412 ) ) ;
F_186 ( V_9 -> V_312 -> V_300 . V_331 . V_335 ) ;
return 0 ;
}
int F_226 ( struct V_8 * V_9 ,
struct V_410 * V_411 )
{
memcpy ( & V_411 -> V_335 , & V_9 -> V_312 -> V_300 . V_331 . V_335 , sizeof( V_411 -> V_335 ) ) ;
memcpy ( & V_411 -> V_412 , & V_9 -> V_12 . V_14 -> V_343 , sizeof( V_411 -> V_412 ) ) ;
return 0 ;
}
int F_227 ( struct V_8 * V_9 , struct V_413 * V_330 )
{
F_183 () ;
if ( F_184 ( V_330 -> V_328 ) )
return - V_86 ;
V_132 -> V_329 . V_330 . V_328 = V_330 -> V_328 ;
if ( V_121 )
F_228 ( ( V_414 * ) V_9 -> V_312 -> V_300 . V_331 . V_332 ,
( V_415 * ) V_330 -> V_333 ) ;
else
memcpy ( V_9 -> V_312 -> V_300 . V_331 . V_333 , & V_330 -> V_333 , sizeof( V_330 -> V_333 ) ) ;
return 0 ;
}
int F_229 ( struct V_8 * V_9 , struct V_413 * V_330 )
{
F_183 () ;
if ( V_121 )
F_230 ( ( V_415 * ) V_330 -> V_333 ,
( V_414 * ) V_9 -> V_312 -> V_300 . V_331 . V_332 ) ;
else
memcpy ( V_330 -> V_333 , V_9 -> V_312 -> V_300 . V_331 . V_333 , sizeof( V_330 -> V_333 ) ) ;
V_330 -> V_328 = V_132 -> V_329 . V_330 . V_328 ;
return 0 ;
}
static int F_231 ( struct V_8 * V_9 , T_9 V_416 )
{
int V_260 = 0 ;
if ( ! F_232 ( V_9 ) )
V_260 = - V_151 ;
else {
V_9 -> V_312 -> V_417 = V_416 . V_340 ;
V_9 -> V_312 -> V_418 = V_416 . V_164 ;
}
return V_260 ;
}
int F_233 ( struct V_8 * V_9 ,
struct V_419 * V_420 )
{
return - V_86 ;
}
int F_234 ( struct V_8 * V_9 ,
struct V_421 * V_422 )
{
int V_260 = 0 ;
V_9 -> V_423 = 0 ;
F_235 ( V_9 ) ;
if ( V_422 -> V_424 & ~ V_425 )
return - V_86 ;
if ( ! V_57 . V_65 )
return - V_86 ;
if ( V_422 -> V_424 & V_426 ) {
V_9 -> V_423 = V_422 -> V_424 ;
F_188 ( V_427 , & V_9 -> V_12 . V_14 -> V_338 ) ;
if ( V_422 -> V_424 & V_428 )
V_260 = F_236 ( V_9 , V_422 ) ;
} else {
F_191 ( V_427 , & V_9 -> V_12 . V_14 -> V_338 ) ;
V_9 -> V_12 . V_429 . V_430 = 0 ;
}
if ( V_260 ) {
V_9 -> V_423 = 0 ;
F_235 ( V_9 ) ;
F_191 ( V_427 , & V_9 -> V_12 . V_14 -> V_338 ) ;
}
return V_260 ;
}
int F_237 ( struct V_8 * V_9 ,
struct V_431 * V_432 )
{
return F_232 ( V_9 ) ? V_433 :
V_434 ;
}
int F_238 ( struct V_8 * V_9 ,
struct V_431 * V_432 )
{
int V_260 = 0 ;
V_9 -> V_7 -> V_12 . V_435 = 1 ;
switch ( V_432 -> V_432 ) {
case V_433 :
F_196 ( V_9 ) ;
break;
case V_434 :
F_239 ( V_9 ) ;
break;
case V_436 :
case V_437 :
default:
V_260 = - V_166 ;
}
return V_260 ;
}
static bool F_240 ( struct V_8 * V_9 )
{
return F_78 ( & V_9 -> V_12 . V_14 -> V_338 ) & V_438 ;
}
static int F_241 ( struct V_8 * V_9 )
{
V_439:
F_213 ( V_9 ) ;
if ( ! V_9 -> V_440 )
return 0 ;
if ( F_242 ( V_394 , V_9 ) ) {
int V_260 ;
V_260 = F_243 ( V_9 -> V_12 . V_128 ,
F_217 ( V_9 ) ,
V_272 * 2 , V_441 ) ;
if ( V_260 ) {
F_215 ( V_394 , V_9 ) ;
return V_260 ;
}
goto V_439;
}
if ( F_242 ( V_442 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_443 = 0xffff ;
goto V_439;
}
if ( F_242 ( V_444 , V_9 ) ) {
if ( ! F_240 ( V_9 ) ) {
F_244 ( V_9 -> V_287 , 1 ) ;
F_188 ( V_438 ,
& V_9 -> V_12 . V_14 -> V_338 ) ;
}
goto V_439;
}
if ( F_242 ( V_445 , V_9 ) ) {
if ( F_240 ( V_9 ) ) {
F_244 ( V_9 -> V_287 , 0 ) ;
F_191 ( V_438 ,
& V_9 -> V_12 . V_14 -> V_338 ) ;
}
goto V_439;
}
if ( F_242 ( V_143 , V_9 ) ) {
V_9 -> V_12 . V_14 -> V_346 |= V_347 ;
goto V_439;
}
F_245 ( V_446 , & V_9 -> V_440 ) ;
return 0 ;
}
void F_66 ( struct V_7 * V_7 , V_162 V_447 )
{
struct V_8 * V_9 ;
int V_10 ;
F_38 ( & V_7 -> V_149 ) ;
F_172 () ;
V_7 -> V_12 . V_13 = V_447 - F_246 () ;
F_156 ( V_7 ) ;
F_7 (i, vcpu, kvm)
V_9 -> V_12 . V_14 -> V_13 = V_7 -> V_12 . V_13 ;
F_159 ( V_7 ) ;
F_173 () ;
F_42 ( & V_7 -> V_149 ) ;
}
long F_247 ( struct V_8 * V_9 , T_10 V_448 , int V_449 )
{
return F_248 ( V_9 -> V_12 . V_128 , V_448 ,
V_449 ? V_450 : 0 ) ;
}
static void F_249 ( struct V_8 * V_9 , bool V_451 ,
unsigned long V_452 )
{
struct V_236 V_453 ;
struct V_454 V_455 ;
if ( V_451 ) {
V_455 . V_456 . V_87 . V_457 = V_452 ;
V_455 . type = V_458 ;
F_164 ( F_250 ( V_9 , & V_455 ) ) ;
} else {
V_453 . type = V_459 ;
V_453 . V_460 = V_452 ;
F_164 ( F_107 ( V_9 -> V_7 , & V_453 ) ) ;
}
}
void F_251 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
F_252 ( V_9 , V_462 -> V_12 . V_310 ) ;
F_249 ( V_9 , true , V_462 -> V_12 . V_310 ) ;
}
void F_253 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
F_254 ( V_9 , V_462 -> V_12 . V_310 ) ;
F_249 ( V_9 , false , V_462 -> V_12 . V_310 ) ;
}
void F_255 ( struct V_8 * V_9 ,
struct V_461 * V_462 )
{
}
bool F_256 ( struct V_8 * V_9 )
{
return true ;
}
static int F_257 ( struct V_8 * V_9 )
{
T_11 V_225 ;
struct V_463 V_12 ;
int V_260 ;
if ( V_9 -> V_12 . V_310 == V_311 )
return 0 ;
if ( ( V_9 -> V_12 . V_14 -> V_339 . V_340 & V_9 -> V_12 . V_405 ) !=
V_9 -> V_12 . V_403 )
return 0 ;
if ( F_258 ( V_9 ) )
return 0 ;
if ( F_209 ( V_9 , 0 ) )
return 0 ;
if ( ! ( V_9 -> V_12 . V_14 -> V_343 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_9 -> V_12 . V_128 -> V_284 )
return 0 ;
V_225 = F_98 ( V_9 -> V_7 , F_259 ( V_132 -> V_329 . V_464 ) ) ;
V_225 += V_132 -> V_329 . V_464 & ~ V_465 ;
if ( F_260 ( V_9 , V_9 -> V_12 . V_310 , & V_12 . V_310 , 8 ) )
return 0 ;
V_260 = F_261 ( V_9 , V_132 -> V_329 . V_464 , V_225 , & V_12 ) ;
return V_260 ;
}
static int F_262 ( struct V_8 * V_9 )
{
int V_260 , V_338 ;
F_263 ( V_9 ) ;
V_9 -> V_12 . V_14 -> V_466 = V_9 -> V_312 -> V_300 . V_331 . V_409 [ 14 ] ;
V_9 -> V_12 . V_14 -> V_467 = V_9 -> V_312 -> V_300 . V_331 . V_409 [ 15 ] ;
if ( F_264 () )
F_265 () ;
if ( F_266 ( V_468 ) )
F_267 () ;
if ( ! F_54 ( V_9 -> V_7 ) ) {
V_260 = F_268 ( V_9 ) ;
if ( V_260 )
return V_260 ;
}
V_260 = F_241 ( V_9 ) ;
if ( V_260 )
return V_260 ;
if ( F_269 ( V_9 ) ) {
F_270 ( V_9 ) ;
F_271 ( V_9 ) ;
}
V_9 -> V_12 . V_14 -> V_469 = 0 ;
V_338 = F_78 ( & V_9 -> V_12 . V_14 -> V_338 ) ;
F_133 ( V_9 , 6 , L_35 , V_338 ) ;
F_272 ( V_9 , V_338 ) ;
return 0 ;
}
static int F_273 ( struct V_8 * V_9 )
{
struct V_470 V_471 = {
. V_472 = V_473 ,
} ;
T_3 V_474 , V_475 ;
int V_260 ;
F_133 ( V_9 , 3 , L_3 , L_36 ) ;
F_274 ( V_9 ) ;
V_260 = F_275 ( V_9 , & V_474 , 1 ) ;
V_475 = F_276 ( V_474 ) ;
if ( V_260 < 0 ) {
return V_260 ;
} else if ( V_260 ) {
V_471 = V_9 -> V_12 . V_476 ;
V_475 = 4 ;
}
V_471 . V_146 = V_475 | V_477 ;
F_277 ( V_9 , V_475 ) ;
return F_278 ( V_9 , & V_471 ) ;
}
static int F_279 ( struct V_8 * V_9 , int V_478 )
{
F_133 ( V_9 , 6 , L_37 ,
V_9 -> V_12 . V_14 -> V_469 ) ;
F_280 ( V_9 , V_9 -> V_12 . V_14 -> V_469 ) ;
if ( F_269 ( V_9 ) )
F_281 ( V_9 ) ;
V_9 -> V_312 -> V_300 . V_331 . V_409 [ 14 ] = V_9 -> V_12 . V_14 -> V_466 ;
V_9 -> V_312 -> V_300 . V_331 . V_409 [ 15 ] = V_9 -> V_12 . V_14 -> V_467 ;
if ( V_9 -> V_12 . V_14 -> V_469 > 0 ) {
int V_260 = F_282 ( V_9 ) ;
if ( V_260 != - V_479 )
return V_260 ;
V_9 -> V_312 -> V_478 = V_480 ;
V_9 -> V_312 -> V_481 . V_469 = V_9 -> V_12 . V_14 -> V_469 ;
V_9 -> V_312 -> V_481 . V_482 = V_9 -> V_12 . V_14 -> V_482 ;
V_9 -> V_312 -> V_481 . V_483 = V_9 -> V_12 . V_14 -> V_483 ;
return - V_484 ;
} else if ( V_478 != - V_165 ) {
V_9 -> V_485 . V_486 ++ ;
return 0 ;
} else if ( F_54 ( V_9 -> V_7 ) ) {
V_9 -> V_312 -> V_478 = V_487 ;
V_9 -> V_312 -> V_488 . V_489 =
V_132 -> V_329 . V_464 ;
V_9 -> V_312 -> V_488 . V_490 = 0x10 ;
return - V_484 ;
} else if ( V_132 -> V_329 . V_491 ) {
F_283 ( V_9 ) ;
V_132 -> V_329 . V_491 = 0 ;
if ( F_257 ( V_9 ) )
return 0 ;
return F_247 ( V_9 , V_132 -> V_329 . V_464 , 1 ) ;
}
return F_273 ( V_9 ) ;
}
static int F_284 ( struct V_8 * V_9 )
{
int V_260 , V_478 ;
V_9 -> V_492 = F_51 ( & V_9 -> V_7 -> V_172 ) ;
do {
V_260 = F_262 ( V_9 ) ;
if ( V_260 )
break;
F_53 ( & V_9 -> V_7 -> V_172 , V_9 -> V_492 ) ;
F_285 () ;
F_286 () ;
F_170 ( V_9 ) ;
F_287 () ;
V_478 = F_288 ( V_9 -> V_12 . V_14 ,
V_9 -> V_312 -> V_300 . V_331 . V_409 ) ;
F_285 () ;
F_169 ( V_9 ) ;
F_289 () ;
F_287 () ;
V_9 -> V_492 = F_51 ( & V_9 -> V_7 -> V_172 ) ;
V_260 = F_279 ( V_9 , V_478 ) ;
} while ( ! F_290 ( V_132 ) && ! F_291 ( V_9 ) && ! V_260 );
F_53 ( & V_9 -> V_7 -> V_172 , V_9 -> V_492 ) ;
return V_260 ;
}
static void F_292 ( struct V_8 * V_9 , struct V_493 * V_493 )
{
V_9 -> V_12 . V_14 -> V_339 . V_340 = V_493 -> V_417 ;
V_9 -> V_12 . V_14 -> V_339 . V_164 = V_493 -> V_418 ;
if ( V_493 -> V_494 & V_314 )
F_162 ( V_9 , V_493 -> V_300 . V_331 . V_393 ) ;
if ( V_493 -> V_494 & V_317 ) {
memcpy ( & V_9 -> V_12 . V_14 -> V_343 , & V_493 -> V_300 . V_331 . V_412 , 128 ) ;
F_215 ( V_442 , V_9 ) ;
}
if ( V_493 -> V_494 & V_318 ) {
F_175 ( V_9 , V_493 -> V_300 . V_331 . V_324 ) ;
V_9 -> V_12 . V_14 -> V_341 = V_493 -> V_300 . V_331 . V_341 ;
V_9 -> V_12 . V_14 -> V_342 = V_493 -> V_300 . V_331 . V_342 ;
V_9 -> V_12 . V_14 -> V_345 = V_493 -> V_300 . V_331 . V_345 ;
V_9 -> V_12 . V_14 -> V_344 = V_493 -> V_300 . V_331 . V_344 ;
}
if ( V_493 -> V_494 & V_319 ) {
V_9 -> V_12 . V_310 = V_493 -> V_300 . V_331 . V_495 ;
V_9 -> V_12 . V_405 = V_493 -> V_300 . V_331 . V_496 ;
V_9 -> V_12 . V_403 = V_493 -> V_300 . V_331 . V_497 ;
if ( V_9 -> V_12 . V_310 == V_311 )
F_136 ( V_9 ) ;
}
V_493 -> V_494 = 0 ;
}
static void F_293 ( struct V_8 * V_9 , struct V_493 * V_493 )
{
V_493 -> V_417 = V_9 -> V_12 . V_14 -> V_339 . V_340 ;
V_493 -> V_418 = V_9 -> V_12 . V_14 -> V_339 . V_164 ;
V_493 -> V_300 . V_331 . V_393 = F_217 ( V_9 ) ;
memcpy ( & V_493 -> V_300 . V_331 . V_412 , & V_9 -> V_12 . V_14 -> V_343 , 128 ) ;
V_493 -> V_300 . V_331 . V_324 = F_176 ( V_9 ) ;
V_493 -> V_300 . V_331 . V_341 = V_9 -> V_12 . V_14 -> V_341 ;
V_493 -> V_300 . V_331 . V_342 = V_9 -> V_12 . V_14 -> V_342 ;
V_493 -> V_300 . V_331 . V_345 = V_9 -> V_12 . V_14 -> V_345 ;
V_493 -> V_300 . V_331 . V_344 = V_9 -> V_12 . V_14 -> V_344 ;
V_493 -> V_300 . V_331 . V_495 = V_9 -> V_12 . V_310 ;
V_493 -> V_300 . V_331 . V_496 = V_9 -> V_12 . V_405 ;
V_493 -> V_300 . V_331 . V_497 = V_9 -> V_12 . V_403 ;
}
int F_294 ( struct V_8 * V_9 , struct V_493 * V_493 )
{
int V_260 ;
T_12 V_498 ;
if ( F_291 ( V_9 ) ) {
F_295 ( V_9 ) ;
return 0 ;
}
if ( V_9 -> V_499 )
F_296 ( V_500 , & V_9 -> V_501 , & V_498 ) ;
if ( ! F_195 ( V_9 -> V_7 ) ) {
F_239 ( V_9 ) ;
} else if ( F_232 ( V_9 ) ) {
F_297 ( L_38 ,
V_9 -> V_287 ) ;
return - V_86 ;
}
F_292 ( V_9 , V_493 ) ;
F_171 ( V_9 ) ;
F_298 () ;
V_260 = F_284 ( V_9 ) ;
if ( F_290 ( V_132 ) && ! V_260 ) {
V_493 -> V_478 = V_502 ;
V_260 = - V_503 ;
}
if ( F_291 ( V_9 ) && ! V_260 ) {
F_295 ( V_9 ) ;
V_260 = 0 ;
}
if ( V_260 == - V_484 ) {
V_260 = 0 ;
}
F_174 ( V_9 ) ;
F_293 ( V_9 , V_493 ) ;
if ( V_9 -> V_499 )
F_296 ( V_500 , & V_498 , NULL ) ;
V_9 -> V_485 . V_504 ++ ;
return V_260 ;
}
int F_299 ( struct V_8 * V_9 , unsigned long V_448 )
{
unsigned char V_505 = 1 ;
V_415 V_333 [ V_506 ] ;
unsigned int V_507 ;
V_162 V_508 , V_324 ;
int V_260 ;
V_507 = F_217 ( V_9 ) ;
if ( V_448 == V_509 ) {
if ( F_300 ( V_9 , 163 , & V_505 , 1 ) )
return - V_165 ;
V_448 = 0 ;
} else if ( V_448 == V_510 ) {
if ( F_301 ( V_9 , 163 , & V_505 , 1 ) )
return - V_165 ;
V_448 = V_507 ;
} else
V_448 -= V_511 ;
if ( V_121 ) {
F_230 ( V_333 , ( V_414 * ) V_9 -> V_312 -> V_300 . V_331 . V_332 ) ;
V_260 = F_300 ( V_9 , V_448 + V_511 ,
V_333 , 128 ) ;
} else {
V_260 = F_300 ( V_9 , V_448 + V_511 ,
V_9 -> V_312 -> V_300 . V_331 . V_333 , 128 ) ;
}
V_260 |= F_300 ( V_9 , V_448 + V_512 ,
V_9 -> V_312 -> V_300 . V_331 . V_409 , 128 ) ;
V_260 |= F_300 ( V_9 , V_448 + V_513 ,
& V_9 -> V_12 . V_14 -> V_339 , 16 ) ;
V_260 |= F_300 ( V_9 , V_448 + V_514 ,
& V_507 , 4 ) ;
V_260 |= F_300 ( V_9 , V_448 + V_515 ,
& V_9 -> V_312 -> V_300 . V_331 . V_328 , 4 ) ;
V_260 |= F_300 ( V_9 , V_448 + V_516 ,
& V_9 -> V_12 . V_14 -> V_342 , 4 ) ;
V_324 = F_176 ( V_9 ) ;
V_260 |= F_300 ( V_9 , V_448 + V_517 ,
& V_324 , 8 ) ;
V_508 = V_9 -> V_12 . V_14 -> V_341 >> 8 ;
V_260 |= F_300 ( V_9 , V_448 + V_518 ,
& V_508 , 8 ) ;
V_260 |= F_300 ( V_9 , V_448 + V_519 ,
& V_9 -> V_312 -> V_300 . V_331 . V_335 , 64 ) ;
V_260 |= F_300 ( V_9 , V_448 + V_520 ,
& V_9 -> V_12 . V_14 -> V_343 , 128 ) ;
return V_260 ? - V_165 : 0 ;
}
int F_302 ( struct V_8 * V_9 , unsigned long V_164 )
{
F_183 () ;
V_9 -> V_312 -> V_300 . V_331 . V_328 = V_132 -> V_329 . V_330 . V_328 ;
F_185 ( V_9 -> V_312 -> V_300 . V_331 . V_335 ) ;
return F_299 ( V_9 , V_164 ) ;
}
int F_303 ( struct V_8 * V_9 ,
unsigned long V_448 )
{
if ( ! ( V_448 & ~ 0x3ff ) )
return 0 ;
return F_300 ( V_9 , V_448 & ~ 0x3ff ,
( void * ) & V_9 -> V_312 -> V_300 . V_331 . V_332 , 512 ) ;
}
int F_304 ( struct V_8 * V_9 , unsigned long V_164 )
{
if ( ! F_59 ( V_9 -> V_7 , 129 ) )
return 0 ;
F_183 () ;
return F_303 ( V_9 , V_164 ) ;
}
static void F_305 ( struct V_8 * V_9 )
{
F_242 ( V_444 , V_9 ) ;
F_44 ( V_445 , V_9 ) ;
}
static void F_306 ( struct V_7 * V_7 )
{
unsigned int V_10 ;
struct V_8 * V_9 ;
F_7 (i, vcpu, kvm) {
F_305 ( V_9 ) ;
}
}
static void F_307 ( struct V_8 * V_9 )
{
if ( ! V_57 . V_73 )
return;
F_242 ( V_445 , V_9 ) ;
F_44 ( V_444 , V_9 ) ;
}
void F_239 ( struct V_8 * V_9 )
{
int V_10 , V_205 , V_521 = 0 ;
if ( ! F_232 ( V_9 ) )
return;
F_308 ( V_9 -> V_287 , 1 ) ;
F_123 ( & V_9 -> V_7 -> V_12 . V_286 ) ;
V_205 = F_78 ( & V_9 -> V_7 -> V_205 ) ;
for ( V_10 = 0 ; V_10 < V_205 ; V_10 ++ ) {
if ( ! F_232 ( V_9 -> V_7 -> V_289 [ V_10 ] ) )
V_521 ++ ;
}
if ( V_521 == 0 ) {
F_307 ( V_9 ) ;
} else if ( V_521 == 1 ) {
F_306 ( V_9 -> V_7 ) ;
}
F_191 ( V_356 , & V_9 -> V_12 . V_14 -> V_338 ) ;
F_215 ( V_442 , V_9 ) ;
F_124 ( & V_9 -> V_7 -> V_12 . V_286 ) ;
return;
}
void F_196 ( struct V_8 * V_9 )
{
int V_10 , V_205 , V_521 = 0 ;
struct V_8 * V_522 = NULL ;
if ( F_232 ( V_9 ) )
return;
F_308 ( V_9 -> V_287 , 0 ) ;
F_123 ( & V_9 -> V_7 -> V_12 . V_286 ) ;
V_205 = F_78 ( & V_9 -> V_7 -> V_205 ) ;
F_309 ( V_9 ) ;
F_188 ( V_356 , & V_9 -> V_12 . V_14 -> V_338 ) ;
F_305 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < V_205 ; V_10 ++ ) {
if ( ! F_232 ( V_9 -> V_7 -> V_289 [ V_10 ] ) ) {
V_521 ++ ;
V_522 = V_9 -> V_7 -> V_289 [ V_10 ] ;
}
}
if ( V_521 == 1 ) {
F_307 ( V_522 ) ;
}
F_124 ( & V_9 -> V_7 -> V_12 . V_286 ) ;
return;
}
static int F_310 ( struct V_8 * V_9 ,
struct V_144 * V_145 )
{
int V_88 ;
if ( V_145 -> V_146 )
return - V_86 ;
switch ( V_145 -> V_145 ) {
case V_97 :
if ( ! V_9 -> V_7 -> V_12 . V_285 ) {
V_9 -> V_7 -> V_12 . V_285 = 1 ;
F_46 ( V_9 -> V_7 , 3 , L_3 , L_39 ) ;
F_311 ( V_9 -> V_7 ) ;
}
V_88 = 0 ;
break;
default:
V_88 = - V_86 ;
break;
}
return V_88 ;
}
static long F_312 ( struct V_8 * V_9 ,
struct V_523 * V_524 )
{
void V_163 * V_525 = ( void V_163 * ) V_524 -> V_526 ;
void * V_527 = NULL ;
int V_88 , V_492 ;
const V_162 V_528 = V_529
| V_530 ;
if ( V_524 -> V_146 & ~ V_528 )
return - V_86 ;
if ( V_524 -> V_531 > V_111 )
return - V_175 ;
if ( ! ( V_524 -> V_146 & V_530 ) ) {
V_527 = F_96 ( V_524 -> V_531 ) ;
if ( ! V_527 )
return - V_77 ;
}
V_492 = F_51 ( & V_9 -> V_7 -> V_172 ) ;
switch ( V_524 -> V_532 ) {
case V_533 :
if ( V_524 -> V_146 & V_530 ) {
V_88 = F_313 ( V_9 , V_524 -> V_534 , V_524 -> V_535 ,
V_524 -> V_531 , V_536 ) ;
break;
}
V_88 = F_314 ( V_9 , V_524 -> V_534 , V_524 -> V_535 , V_527 , V_524 -> V_531 ) ;
if ( V_88 == 0 ) {
if ( F_69 ( V_525 , V_527 , V_524 -> V_531 ) )
V_88 = - V_165 ;
}
break;
case V_537 :
if ( V_524 -> V_146 & V_530 ) {
V_88 = F_313 ( V_9 , V_524 -> V_534 , V_524 -> V_535 ,
V_524 -> V_531 , V_538 ) ;
break;
}
if ( F_64 ( V_527 , V_525 , V_524 -> V_531 ) ) {
V_88 = - V_165 ;
break;
}
V_88 = F_315 ( V_9 , V_524 -> V_534 , V_524 -> V_535 , V_527 , V_524 -> V_531 ) ;
break;
default:
V_88 = - V_86 ;
}
F_53 ( & V_9 -> V_7 -> V_172 , V_492 ) ;
if ( V_88 > 0 && ( V_524 -> V_146 & V_529 ) != 0 )
F_278 ( V_9 , & V_9 -> V_12 . V_476 ) ;
F_316 ( V_527 ) ;
return V_88 ;
}
long F_317 ( struct V_81 * V_82 ,
unsigned int V_83 , unsigned long V_84 )
{
struct V_8 * V_9 = V_82 -> V_233 ;
void V_163 * V_234 = ( void V_163 * ) V_84 ;
int V_167 ;
long V_88 ;
switch ( V_83 ) {
case V_539 : {
struct V_454 V_540 ;
V_88 = - V_165 ;
if ( F_64 ( & V_540 , V_234 , sizeof( V_540 ) ) )
break;
V_88 = F_250 ( V_9 , & V_540 ) ;
break;
}
case V_235 : {
struct V_236 V_237 ;
struct V_454 V_540 ;
V_88 = - V_165 ;
if ( F_64 ( & V_237 , V_234 , sizeof( V_237 ) ) )
break;
if ( F_318 ( & V_237 , & V_540 ) )
return - V_86 ;
V_88 = F_250 ( V_9 , & V_540 ) ;
break;
}
case V_541 :
V_167 = F_51 ( & V_9 -> V_7 -> V_172 ) ;
V_88 = F_302 ( V_9 , V_84 ) ;
F_53 ( & V_9 -> V_7 -> V_172 , V_167 ) ;
break;
case V_542 : {
T_9 V_416 ;
V_88 = - V_165 ;
if ( F_64 ( & V_416 , V_234 , sizeof( V_416 ) ) )
break;
V_88 = F_231 ( V_9 , V_416 ) ;
break;
}
case V_543 :
V_88 = F_222 ( V_9 ) ;
break;
case V_544 :
case V_545 : {
struct V_395 V_396 ;
V_88 = - V_165 ;
if ( F_64 ( & V_396 , V_234 , sizeof( V_396 ) ) )
break;
if ( V_83 == V_544 )
V_88 = F_221 ( V_9 , & V_396 ) ;
else
V_88 = F_220 ( V_9 , & V_396 ) ;
break;
}
#ifdef F_30
case V_546 : {
struct V_547 V_548 ;
if ( F_64 ( & V_548 , V_234 , sizeof( V_548 ) ) ) {
V_88 = - V_165 ;
break;
}
if ( ! F_54 ( V_9 -> V_7 ) ) {
V_88 = - V_86 ;
break;
}
V_88 = F_319 ( V_9 -> V_12 . V_128 , V_548 . V_549 ,
V_548 . V_550 , V_548 . V_551 ) ;
break;
}
case V_552 : {
struct V_547 V_548 ;
if ( F_64 ( & V_548 , V_234 , sizeof( V_548 ) ) ) {
V_88 = - V_165 ;
break;
}
if ( ! F_54 ( V_9 -> V_7 ) ) {
V_88 = - V_86 ;
break;
}
V_88 = F_320 ( V_9 -> V_12 . V_128 , V_548 . V_550 ,
V_548 . V_551 ) ;
break;
}
#endif
case V_553 : {
V_88 = F_248 ( V_9 -> V_12 . V_128 , V_84 , 0 ) ;
break;
}
case V_238 :
{
struct V_144 V_145 ;
V_88 = - V_165 ;
if ( F_64 ( & V_145 , V_234 , sizeof( V_145 ) ) )
break;
V_88 = F_310 ( V_9 , & V_145 ) ;
break;
}
case V_554 : {
struct V_523 V_555 ;
if ( F_64 ( & V_555 , V_234 , sizeof( V_555 ) ) == 0 )
V_88 = F_312 ( V_9 , & V_555 ) ;
else
V_88 = - V_165 ;
break;
}
case V_556 : {
struct V_557 V_558 ;
V_88 = - V_165 ;
if ( F_64 ( & V_558 , V_234 , sizeof( V_558 ) ) )
break;
if ( V_558 . V_559 > V_560 ||
V_558 . V_559 == 0 ||
V_558 . V_559 % sizeof( struct V_454 ) > 0 ) {
V_88 = - V_86 ;
break;
}
V_88 = F_321 ( V_9 ,
( void V_163 * ) V_558 . V_526 ,
V_558 . V_559 ) ;
break;
}
case V_561 : {
struct V_557 V_558 ;
V_88 = - V_165 ;
if ( F_64 ( & V_558 , V_234 , sizeof( V_558 ) ) )
break;
if ( V_558 . V_559 == 0 ) {
V_88 = - V_86 ;
break;
}
V_88 = F_322 ( V_9 ,
( V_562 V_163 * ) V_558 . V_526 ,
V_558 . V_559 ) ;
break;
}
default:
V_88 = - V_247 ;
}
return V_88 ;
}
int F_323 ( struct V_8 * V_9 , struct V_563 * V_564 )
{
#ifdef F_30
if ( ( V_564 -> V_565 == V_566 )
&& ( F_54 ( V_9 -> V_7 ) ) ) {
V_564 -> V_567 = F_324 ( V_9 -> V_12 . V_14 ) ;
F_325 ( V_564 -> V_567 ) ;
return 0 ;
}
#endif
return V_568 ;
}
int F_326 ( struct V_7 * V_7 , struct V_123 * V_139 ,
unsigned long V_130 )
{
return 0 ;
}
int F_327 ( struct V_7 * V_7 ,
struct V_123 * V_124 ,
const struct V_569 * V_570 ,
enum V_571 V_572 )
{
if ( V_570 -> V_573 & 0xffffful )
return - V_86 ;
if ( V_570 -> V_574 & 0xffffful )
return - V_86 ;
if ( V_570 -> V_575 + V_570 -> V_574 > V_7 -> V_12 . V_161 )
return - V_86 ;
return 0 ;
}
void F_328 ( struct V_7 * V_7 ,
const struct V_569 * V_570 ,
const struct V_123 * V_576 ,
const struct V_123 * V_176 ,
enum V_571 V_572 )
{
int V_260 ;
if ( V_576 -> V_573 == V_570 -> V_573 &&
V_576 -> V_129 * V_272 == V_570 -> V_575 &&
V_576 -> V_130 * V_272 == V_570 -> V_574 )
return;
V_260 = F_319 ( V_7 -> V_12 . V_128 , V_570 -> V_573 ,
V_570 -> V_575 , V_570 -> V_574 ) ;
if ( V_260 )
F_329 ( L_40 ) ;
return;
}
static inline unsigned long F_330 ( int V_10 )
{
unsigned int V_577 = ( V_57 . V_578 << V_10 * 2 ) >> 30 ;
return 0x0000ffffffffffffUL >> ( V_577 << 4 ) ;
}
void F_331 ( struct V_8 * V_9 )
{
V_9 -> V_579 = false ;
}
static int T_13 F_332 ( void )
{
int V_10 ;
if ( ! V_57 . V_58 ) {
F_333 ( L_41 ) ;
return - V_580 ;
}
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ )
V_1 [ V_10 ] |=
V_212 . V_213 [ V_10 ] & F_330 ( V_10 ) ;
return F_334 ( NULL , sizeof( struct V_8 ) , 0 , V_581 ) ;
}
static void T_14 F_335 ( void )
{
F_336 () ;
}
