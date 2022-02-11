int F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 , ( void * ) V_2 ) ;
}
int F_3 ( void )
{
return 0 ;
}
int F_4 ( void )
{
V_3 . V_4 = V_5 ;
F_5 ( & V_3 ) ;
return 0 ;
}
void F_6 ( void )
{
F_7 ( & V_3 ) ;
}
int F_8 ( void * V_6 )
{
return F_9 ( & V_7 , V_8 ) ;
}
long F_10 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
if ( V_11 == V_13 )
return F_11 () ;
return - V_14 ;
}
int F_12 ( struct V_15 * V_15 , long V_16 )
{
int V_17 ;
switch ( V_16 ) {
case V_18 :
case V_19 :
case V_20 :
#ifdef F_13
case V_21 :
#endif
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_17 = 1 ;
break;
case V_34 :
case V_35 :
V_17 = V_36 ;
break;
case V_37 :
V_17 = V_38 ;
break;
case V_39 :
V_17 = V_40 ;
break;
default:
V_17 = 0 ;
}
return V_17 ;
}
static void F_14 ( struct V_15 * V_15 ,
struct V_41 * V_42 )
{
T_1 V_43 , V_44 ;
unsigned long V_45 ;
struct V_46 * V_46 = V_15 -> V_47 . V_46 ;
F_15 ( & V_46 -> V_48 -> V_49 ) ;
V_44 = V_42 -> V_50 + V_42 -> V_51 ;
for ( V_43 = V_42 -> V_50 ; V_43 <= V_44 ; V_43 ++ ) {
V_45 = F_16 ( V_42 , V_43 ) ;
if ( F_17 ( V_45 , V_46 ) )
F_18 ( V_15 , V_43 ) ;
}
F_19 ( & V_46 -> V_48 -> V_49 ) ;
}
int F_20 ( struct V_15 * V_15 ,
struct V_52 * log )
{
int V_17 ;
unsigned long V_53 ;
struct V_41 * V_42 ;
int V_54 = 0 ;
F_21 ( & V_15 -> V_55 ) ;
V_17 = - V_14 ;
if ( log -> V_56 >= V_38 )
goto V_57;
V_42 = F_22 ( V_15 -> V_58 , log -> V_56 ) ;
V_17 = - V_59 ;
if ( ! V_42 -> V_60 )
goto V_57;
F_14 ( V_15 , V_42 ) ;
V_17 = F_23 ( V_15 , log , & V_54 ) ;
if ( V_17 )
goto V_57;
if ( V_54 ) {
V_53 = F_24 ( V_42 ) ;
memset ( V_42 -> V_60 , 0 , V_53 ) ;
}
V_17 = 0 ;
V_57:
F_25 ( & V_15 -> V_55 ) ;
return V_17 ;
}
static int F_26 ( struct V_15 * V_15 , struct V_61 * V_62 )
{
int V_17 ;
if ( V_62 -> V_63 )
return - V_14 ;
switch ( V_62 -> V_62 ) {
case V_31 :
V_15 -> V_47 . V_64 = 1 ;
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
static int F_27 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
int V_67 ;
unsigned int V_68 ;
switch ( V_66 -> V_66 ) {
case V_69 :
V_67 = - V_70 ;
F_21 ( & V_15 -> V_71 ) ;
if ( F_28 ( & V_15 -> V_72 ) == 0 ) {
V_15 -> V_47 . V_73 = 1 ;
V_67 = 0 ;
}
F_25 ( & V_15 -> V_71 ) ;
break;
case V_74 :
F_21 ( & V_15 -> V_71 ) ;
V_68 = F_29 ( & V_15 -> V_75 ) ;
F_30 ( V_15 -> V_47 . V_46 -> V_48 ) ;
F_31 ( & V_15 -> V_75 , V_68 ) ;
F_25 ( & V_15 -> V_71 ) ;
V_67 = 0 ;
break;
default:
V_67 = - V_76 ;
break;
}
return V_67 ;
}
static int F_32 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
int V_67 ;
switch ( V_66 -> V_77 ) {
case V_78 :
V_67 = F_27 ( V_15 , V_66 ) ;
break;
default:
V_67 = - V_76 ;
break;
}
return V_67 ;
}
static int F_33 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
return - V_76 ;
}
static int F_34 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
int V_67 ;
switch ( V_66 -> V_77 ) {
case V_78 :
switch ( V_66 -> V_66 ) {
case V_69 :
case V_74 :
V_67 = 0 ;
break;
default:
V_67 = - V_76 ;
break;
}
break;
default:
V_67 = - V_76 ;
break;
}
return V_67 ;
}
long F_35 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_15 * V_15 = V_10 -> V_79 ;
void T_2 * V_80 = ( void T_2 * ) V_12 ;
struct V_65 V_66 ;
int V_17 ;
switch ( V_11 ) {
case V_81 : {
struct V_82 V_83 ;
V_17 = - V_84 ;
if ( F_36 ( & V_83 , V_80 , sizeof( V_83 ) ) )
break;
V_17 = F_37 ( V_15 , & V_83 ) ;
break;
}
case V_85 : {
struct V_61 V_62 ;
V_17 = - V_84 ;
if ( F_36 ( & V_62 , V_80 , sizeof( V_62 ) ) )
break;
V_17 = F_26 ( V_15 , & V_62 ) ;
break;
}
case V_86 : {
struct V_87 V_88 ;
V_17 = - V_14 ;
if ( V_15 -> V_47 . V_64 ) {
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
F_38 ( V_15 , & V_88 , 0 , 0 ) ;
V_17 = 0 ;
}
break;
}
case V_89 : {
V_17 = - V_84 ;
if ( F_36 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_32 ( V_15 , & V_66 ) ;
break;
}
case V_90 : {
V_17 = - V_84 ;
if ( F_36 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_33 ( V_15 , & V_66 ) ;
break;
}
case V_91 : {
V_17 = - V_84 ;
if ( F_36 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_34 ( V_15 , & V_66 ) ;
break;
}
default:
V_17 = - V_92 ;
}
return V_17 ;
}
static int F_39 ( struct V_15 * V_15 )
{
if ( ! F_1 ( 76 ) )
return 0 ;
V_15 -> V_47 . V_93 . V_94 = F_40 ( sizeof( * V_15 -> V_47 . V_93 . V_94 ) ,
V_95 | V_96 ) ;
if ( ! V_15 -> V_47 . V_93 . V_94 )
return - V_97 ;
V_15 -> V_47 . V_93 . V_98 = ( V_99 ) ( unsigned long ) V_15 -> V_47 . V_93 . V_94 |
V_100 ;
return 0 ;
}
int F_41 ( struct V_15 * V_15 , unsigned long type )
{
int V_101 ;
char V_102 [ 16 ] ;
static unsigned long V_103 ;
V_101 = - V_14 ;
#ifdef F_13
if ( type & ~ V_104 )
goto V_105;
if ( ( type & V_104 ) && ( ! F_42 ( V_106 ) ) )
goto V_105;
#else
if ( type )
goto V_105;
#endif
V_101 = F_11 () ;
if ( V_101 )
goto V_105;
V_101 = - V_97 ;
V_15 -> V_47 . V_107 = (struct V_108 * ) F_43 ( V_95 ) ;
if ( ! V_15 -> V_47 . V_107 )
goto V_105;
F_44 ( & V_109 ) ;
V_103 = ( V_103 + 16 ) & 0x7f0 ;
V_15 -> V_47 . V_107 = (struct V_108 * ) ( ( char * ) V_15 -> V_47 . V_107 + V_103 ) ;
F_45 ( & V_109 ) ;
sprintf ( V_102 , L_1 , V_110 -> V_111 ) ;
V_15 -> V_47 . V_112 = F_46 ( V_102 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_15 -> V_47 . V_112 )
goto V_113;
if ( F_39 ( V_15 ) < 0 )
goto V_114;
F_47 ( & V_15 -> V_47 . V_115 . V_71 ) ;
F_48 ( & V_15 -> V_47 . V_115 . V_116 ) ;
F_49 ( & V_15 -> V_47 . V_117 ) ;
F_50 ( & V_15 -> V_47 . V_118 ) ;
F_51 ( V_15 -> V_47 . V_112 , & V_119 ) ;
F_52 ( V_15 , 3 , L_2 , L_3 ) ;
if ( type & V_104 ) {
V_15 -> V_47 . V_46 = NULL ;
} else {
V_15 -> V_47 . V_46 = F_53 ( V_110 -> V_48 , ( 1UL << 44 ) - 1 ) ;
if ( ! V_15 -> V_47 . V_46 )
goto V_120;
V_15 -> V_47 . V_46 -> V_121 = V_15 ;
V_15 -> V_47 . V_46 -> V_122 = 0 ;
}
V_15 -> V_47 . V_123 = 0 ;
V_15 -> V_47 . V_64 = 0 ;
F_47 ( & V_15 -> V_47 . V_124 ) ;
return 0 ;
V_120:
F_54 ( V_15 -> V_47 . V_93 . V_94 ) ;
V_114:
F_55 ( V_15 -> V_47 . V_112 ) ;
V_113:
F_56 ( ( unsigned long ) ( V_15 -> V_47 . V_107 ) ) ;
V_105:
return V_101 ;
}
void F_57 ( struct V_125 * V_126 )
{
F_58 ( V_126 , 3 , L_2 , L_4 ) ;
F_59 ( V_126 -> V_127 ) ;
F_60 ( V_126 ) ;
F_61 ( V_126 ) ;
if ( ! F_62 ( V_126 -> V_15 ) ) {
F_63 ( 63 - V_126 -> V_127 ,
( unsigned long * ) & V_126 -> V_15 -> V_47 . V_107 -> V_128 ) ;
if ( V_126 -> V_15 -> V_47 . V_107 -> V_129 [ V_126 -> V_127 ] . V_130 ==
( V_131 ) V_126 -> V_47 . V_132 )
V_126 -> V_15 -> V_47 . V_107 -> V_129 [ V_126 -> V_127 ] . V_130 = 0 ;
}
F_64 () ;
if ( F_62 ( V_126 -> V_15 ) )
F_65 ( V_126 -> V_47 . V_46 ) ;
if ( F_66 ( V_126 -> V_15 ) )
F_67 ( V_126 ) ;
F_56 ( ( unsigned long ) ( V_126 -> V_47 . V_132 ) ) ;
F_68 ( V_126 ) ;
F_69 ( V_133 , V_126 ) ;
}
static void F_70 ( struct V_15 * V_15 )
{
unsigned int V_134 ;
struct V_125 * V_126 ;
F_71 (i, vcpu, kvm)
F_57 ( V_126 ) ;
F_21 ( & V_15 -> V_71 ) ;
for ( V_134 = 0 ; V_134 < F_28 ( & V_15 -> V_72 ) ; V_134 ++ )
V_15 -> V_135 [ V_134 ] = NULL ;
F_72 ( & V_15 -> V_72 , 0 ) ;
F_25 ( & V_15 -> V_71 ) ;
}
void F_73 ( struct V_15 * V_15 )
{
F_70 ( V_15 ) ;
F_56 ( ( unsigned long ) ( V_15 -> V_47 . V_107 ) ) ;
F_55 ( V_15 -> V_47 . V_112 ) ;
F_54 ( V_15 -> V_47 . V_93 . V_94 ) ;
if ( ! F_62 ( V_15 ) )
F_65 ( V_15 -> V_47 . V_46 ) ;
F_74 ( V_15 ) ;
F_75 ( V_15 ) ;
}
int F_76 ( struct V_125 * V_126 )
{
V_126 -> V_47 . V_136 = V_137 ;
F_61 ( V_126 ) ;
if ( F_62 ( V_126 -> V_15 ) ) {
V_126 -> V_47 . V_46 = F_53 ( V_110 -> V_48 , - 1UL ) ;
if ( ! V_126 -> V_47 . V_46 )
return - V_97 ;
V_126 -> V_47 . V_46 -> V_121 = V_126 -> V_15 ;
return 0 ;
}
V_126 -> V_47 . V_46 = V_126 -> V_15 -> V_47 . V_46 ;
V_126 -> V_138 -> V_139 = V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 ;
return 0 ;
}
void F_77 ( struct V_125 * V_126 , int V_129 )
{
F_78 ( & V_126 -> V_47 . V_146 . V_147 ) ;
F_79 ( V_126 -> V_47 . V_146 . V_148 ) ;
F_80 ( V_126 -> V_47 . V_149 ) ;
F_81 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_82 ( V_126 -> V_47 . V_150 . V_148 ) ;
F_83 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
F_84 ( V_126 -> V_47 . V_46 ) ;
F_85 ( V_154 , & V_126 -> V_47 . V_132 -> V_155 ) ;
}
void F_86 ( struct V_125 * V_126 )
{
F_87 ( V_154 , & V_126 -> V_47 . V_132 -> V_155 ) ;
F_88 ( V_126 -> V_47 . V_46 ) ;
F_78 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_79 ( V_126 -> V_47 . V_150 . V_148 ) ;
F_80 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
F_81 ( & V_126 -> V_47 . V_146 . V_147 ) ;
F_82 ( V_126 -> V_47 . V_146 . V_148 ) ;
F_83 ( V_126 -> V_47 . V_149 ) ;
}
static void F_89 ( struct V_125 * V_126 )
{
V_126 -> V_47 . V_132 -> V_156 . V_157 = 0UL ;
V_126 -> V_47 . V_132 -> V_156 . V_158 = 0UL ;
F_90 ( V_126 , 0 ) ;
V_126 -> V_47 . V_132 -> V_159 = 0UL ;
V_126 -> V_47 . V_132 -> V_160 = 0UL ;
V_126 -> V_47 . V_132 -> V_161 = 0 ;
memset ( V_126 -> V_47 . V_132 -> V_162 , 0 , 16 * sizeof( V_131 ) ) ;
V_126 -> V_47 . V_132 -> V_162 [ 0 ] = 0xE0UL ;
V_126 -> V_47 . V_132 -> V_162 [ 14 ] = 0xC2000000UL ;
V_126 -> V_47 . V_150 . V_147 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_126 -> V_47 . V_132 -> V_163 = 1 ;
V_126 -> V_47 . V_132 -> V_164 = 0 ;
V_126 -> V_47 . V_136 = V_137 ;
F_61 ( V_126 ) ;
if ( ! F_91 ( V_126 -> V_15 ) )
F_92 ( V_126 ) ;
F_60 ( V_126 ) ;
}
int F_93 ( struct V_125 * V_126 )
{
return 0 ;
}
static void F_94 ( struct V_125 * V_126 )
{
if ( ! F_1 ( 76 ) )
return;
V_126 -> V_47 . V_132 -> V_98 = V_126 -> V_15 -> V_47 . V_93 . V_98 ;
}
void F_67 ( struct V_125 * V_126 )
{
F_56 ( V_126 -> V_47 . V_132 -> V_165 ) ;
V_126 -> V_47 . V_132 -> V_165 = 0 ;
}
int F_95 ( struct V_125 * V_126 )
{
V_126 -> V_47 . V_132 -> V_165 = F_43 ( V_95 ) ;
if ( ! V_126 -> V_47 . V_132 -> V_165 )
return - V_97 ;
V_126 -> V_47 . V_132 -> V_166 |= 0x80 ;
V_126 -> V_47 . V_132 -> V_166 &= ~ 0x08 ;
return 0 ;
}
int F_96 ( struct V_125 * V_126 )
{
int V_101 = 0 ;
F_72 ( & V_126 -> V_47 . V_132 -> V_155 , V_167 |
V_168 |
V_169 |
V_170 ) ;
V_126 -> V_47 . V_132 -> V_171 = 6 ;
if ( F_1 ( 50 ) && F_1 ( 73 ) )
V_126 -> V_47 . V_132 -> V_171 |= 0x10 ;
V_126 -> V_47 . V_132 -> V_166 = 8 ;
V_126 -> V_47 . V_132 -> V_172 = 0xD1002000U ;
if ( F_97 () )
V_126 -> V_47 . V_132 -> V_172 |= 1 ;
V_126 -> V_47 . V_132 -> V_173 = ( int ) ( long ) V_2 ;
V_126 -> V_47 . V_132 -> V_174 |= V_175 | V_176 | V_177 |
V_178 ;
if ( F_66 ( V_126 -> V_15 ) ) {
V_101 = F_95 ( V_126 ) ;
if ( V_101 )
return V_101 ;
}
F_98 ( & V_126 -> V_47 . V_179 , V_180 , V_181 ) ;
V_126 -> V_47 . V_179 . V_182 = V_183 ;
F_99 ( & V_126 -> V_47 . V_184 ) ;
V_126 -> V_47 . V_184 . V_185 = 0xff ;
F_94 ( V_126 ) ;
return V_101 ;
}
struct V_125 * F_100 ( struct V_15 * V_15 ,
unsigned int V_186 )
{
struct V_125 * V_126 ;
struct V_187 * V_187 ;
int V_101 = - V_14 ;
if ( V_186 >= V_36 )
goto V_57;
V_101 = - V_97 ;
V_126 = F_101 ( V_133 , V_95 ) ;
if ( ! V_126 )
goto V_57;
V_187 = (struct V_187 * ) F_43 ( V_95 ) ;
if ( ! V_187 )
goto V_188;
V_126 -> V_47 . V_132 = & V_187 -> V_132 ;
V_126 -> V_47 . V_132 -> V_189 = ( unsigned long ) & V_187 -> V_190 ;
V_126 -> V_47 . V_132 -> V_191 = V_186 ;
if ( ! F_62 ( V_15 ) ) {
if ( ! V_15 -> V_47 . V_107 ) {
F_102 ( 1 ) ;
goto V_188;
}
if ( ! V_15 -> V_47 . V_107 -> V_129 [ V_186 ] . V_130 )
V_15 -> V_47 . V_107 -> V_129 [ V_186 ] . V_130 =
( V_131 ) V_126 -> V_47 . V_132 ;
V_126 -> V_47 . V_132 -> V_192 =
( V_99 ) ( ( ( V_131 ) V_15 -> V_47 . V_107 ) >> 32 ) ;
V_126 -> V_47 . V_132 -> V_193 = ( V_99 ) ( V_131 ) V_15 -> V_47 . V_107 ;
F_103 ( 63 - V_186 , ( unsigned long * ) & V_15 -> V_47 . V_107 -> V_128 ) ;
}
F_47 ( & V_126 -> V_47 . V_194 . V_71 ) ;
V_126 -> V_47 . V_194 . V_115 = & V_15 -> V_47 . V_115 ;
V_126 -> V_47 . V_194 . V_195 = & V_126 -> V_195 ;
V_126 -> V_47 . V_194 . V_155 = & V_126 -> V_47 . V_132 -> V_155 ;
V_101 = F_104 ( V_126 , V_15 , V_186 ) ;
if ( V_101 )
goto V_196;
F_52 ( V_15 , 3 , L_5 , V_186 , V_126 ,
V_126 -> V_47 . V_132 ) ;
F_105 ( V_186 , V_126 , V_126 -> V_47 . V_132 ) ;
return V_126 ;
V_196:
F_56 ( ( unsigned long ) ( V_126 -> V_47 . V_132 ) ) ;
V_188:
F_69 ( V_133 , V_126 ) ;
V_57:
return F_106 ( V_101 ) ;
}
int F_107 ( struct V_125 * V_126 )
{
return F_108 ( V_126 ) ;
}
void F_109 ( struct V_125 * V_126 )
{
F_85 ( V_197 , & V_126 -> V_47 . V_132 -> V_198 ) ;
}
void F_110 ( struct V_125 * V_126 )
{
F_87 ( V_197 , & V_126 -> V_47 . V_132 -> V_198 ) ;
}
void F_111 ( struct V_125 * V_126 )
{
F_85 ( V_199 , & V_126 -> V_47 . V_132 -> V_155 ) ;
while ( V_126 -> V_47 . V_132 -> V_200 & V_201 )
F_112 () ;
}
void F_113 ( struct V_125 * V_126 )
{
F_109 ( V_126 ) ;
F_111 ( V_126 ) ;
}
static void V_5 ( struct V_46 * V_46 , unsigned long V_45 )
{
int V_134 ;
struct V_15 * V_15 = V_46 -> V_121 ;
struct V_125 * V_126 ;
F_71 (i, vcpu, kvm) {
if ( F_114 ( V_126 ) == ( V_45 & ~ 0x1000UL ) ) {
F_58 ( V_126 , 2 , L_6 , V_45 ) ;
F_115 ( V_202 , V_126 ) ;
F_113 ( V_126 ) ;
}
}
}
int F_116 ( struct V_125 * V_126 )
{
F_117 () ;
return 0 ;
}
static int F_118 ( struct V_125 * V_126 ,
struct V_203 * V_204 )
{
int V_17 = - V_14 ;
switch ( V_204 -> V_186 ) {
case V_205 :
V_17 = F_119 ( V_126 -> V_47 . V_132 -> V_161 ,
( V_206 T_2 * ) V_204 -> V_158 ) ;
break;
case V_207 :
V_17 = F_119 ( V_126 -> V_47 . V_132 -> V_208 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_210 :
V_17 = F_119 ( V_126 -> V_47 . V_132 -> V_159 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_211 :
V_17 = F_119 ( V_126 -> V_47 . V_132 -> V_160 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_212 :
V_17 = F_119 ( V_126 -> V_47 . V_136 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_213 :
V_17 = F_119 ( V_126 -> V_47 . V_214 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_215 :
V_17 = F_119 ( V_126 -> V_47 . V_216 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_217 :
V_17 = F_119 ( V_126 -> V_47 . V_132 -> V_164 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_218 :
V_17 = F_119 ( V_126 -> V_47 . V_132 -> V_163 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_120 ( struct V_125 * V_126 ,
struct V_203 * V_204 )
{
int V_17 = - V_14 ;
switch ( V_204 -> V_186 ) {
case V_205 :
V_17 = F_121 ( V_126 -> V_47 . V_132 -> V_161 ,
( V_206 T_2 * ) V_204 -> V_158 ) ;
break;
case V_207 :
V_17 = F_121 ( V_126 -> V_47 . V_132 -> V_208 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_210 :
V_17 = F_121 ( V_126 -> V_47 . V_132 -> V_159 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_211 :
V_17 = F_121 ( V_126 -> V_47 . V_132 -> V_160 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_212 :
V_17 = F_121 ( V_126 -> V_47 . V_136 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_213 :
V_17 = F_121 ( V_126 -> V_47 . V_214 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_215 :
V_17 = F_121 ( V_126 -> V_47 . V_216 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_217 :
V_17 = F_121 ( V_126 -> V_47 . V_132 -> V_164 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_218 :
V_17 = F_121 ( V_126 -> V_47 . V_132 -> V_163 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_122 ( struct V_125 * V_126 )
{
F_89 ( V_126 ) ;
return 0 ;
}
int F_123 ( struct V_125 * V_126 , struct V_219 * V_152 )
{
memcpy ( & V_126 -> V_138 -> V_151 . V_152 . V_220 , & V_152 -> V_220 , sizeof( V_152 -> V_220 ) ) ;
return 0 ;
}
int F_124 ( struct V_125 * V_126 , struct V_219 * V_152 )
{
memcpy ( & V_152 -> V_220 , & V_126 -> V_138 -> V_151 . V_152 . V_220 , sizeof( V_152 -> V_220 ) ) ;
return 0 ;
}
int F_125 ( struct V_125 * V_126 ,
struct V_221 * V_222 )
{
memcpy ( & V_126 -> V_138 -> V_151 . V_152 . V_153 , & V_222 -> V_153 , sizeof( V_222 -> V_153 ) ) ;
memcpy ( & V_126 -> V_47 . V_132 -> V_162 , & V_222 -> V_223 , sizeof( V_222 -> V_223 ) ) ;
F_83 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
return 0 ;
}
int F_126 ( struct V_125 * V_126 ,
struct V_221 * V_222 )
{
memcpy ( & V_222 -> V_153 , & V_126 -> V_138 -> V_151 . V_152 . V_153 , sizeof( V_222 -> V_153 ) ) ;
memcpy ( & V_222 -> V_223 , & V_126 -> V_47 . V_132 -> V_162 , sizeof( V_222 -> V_223 ) ) ;
return 0 ;
}
int F_127 ( struct V_125 * V_126 , struct V_224 * V_225 )
{
if ( F_128 ( V_225 -> V_147 ) )
return - V_14 ;
memcpy ( & V_126 -> V_47 . V_150 . V_148 , & V_225 -> V_148 , sizeof( V_225 -> V_148 ) ) ;
V_126 -> V_47 . V_150 . V_147 = V_225 -> V_147 ;
F_81 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_82 ( V_126 -> V_47 . V_150 . V_148 ) ;
return 0 ;
}
int F_129 ( struct V_125 * V_126 , struct V_224 * V_225 )
{
memcpy ( & V_225 -> V_148 , & V_126 -> V_47 . V_150 . V_148 , sizeof( V_225 -> V_148 ) ) ;
V_225 -> V_147 = V_126 -> V_47 . V_150 . V_147 ;
return 0 ;
}
static int F_130 ( struct V_125 * V_126 , T_3 V_226 )
{
int V_101 = 0 ;
if ( ! F_131 ( V_126 ) )
V_101 = - V_70 ;
else {
V_126 -> V_138 -> V_227 = V_226 . V_157 ;
V_126 -> V_138 -> V_228 = V_226 . V_158 ;
}
return V_101 ;
}
int F_132 ( struct V_125 * V_126 ,
struct V_229 * V_230 )
{
return - V_14 ;
}
int F_133 ( struct V_125 * V_126 ,
struct V_231 * V_232 )
{
int V_101 = 0 ;
V_126 -> V_233 = 0 ;
F_134 ( V_126 ) ;
if ( V_232 -> V_234 & ~ V_235 )
return - V_14 ;
if ( V_232 -> V_234 & V_236 ) {
V_126 -> V_233 = V_232 -> V_234 ;
F_85 ( V_237 , & V_126 -> V_47 . V_132 -> V_155 ) ;
if ( V_232 -> V_234 & V_238 )
V_101 = F_135 ( V_126 , V_232 ) ;
} else {
F_87 ( V_237 , & V_126 -> V_47 . V_132 -> V_155 ) ;
V_126 -> V_47 . V_239 . V_240 = 0 ;
}
if ( V_101 ) {
V_126 -> V_233 = 0 ;
F_134 ( V_126 ) ;
F_87 ( V_237 , & V_126 -> V_47 . V_132 -> V_155 ) ;
}
return V_101 ;
}
int F_136 ( struct V_125 * V_126 ,
struct V_241 * V_242 )
{
return F_131 ( V_126 ) ? V_243 :
V_244 ;
}
int F_137 ( struct V_125 * V_126 ,
struct V_241 * V_242 )
{
int V_101 = 0 ;
V_126 -> V_15 -> V_47 . V_245 = 1 ;
switch ( V_242 -> V_242 ) {
case V_243 :
F_92 ( V_126 ) ;
break;
case V_244 :
F_138 ( V_126 ) ;
break;
case V_246 :
case V_247 :
default:
V_101 = - V_76 ;
}
return V_101 ;
}
bool F_66 ( struct V_15 * V_15 )
{
if ( ! V_248 )
return false ;
if ( ! V_249 )
return false ;
if ( ! V_15 -> V_47 . V_73 )
return false ;
return true ;
}
static bool F_139 ( struct V_125 * V_126 )
{
return F_28 ( & V_126 -> V_47 . V_132 -> V_155 ) & V_250 ;
}
static int F_140 ( struct V_125 * V_126 )
{
V_251:
F_110 ( V_126 ) ;
if ( F_141 ( V_202 , V_126 ) ) {
int V_101 ;
V_101 = F_142 ( V_126 -> V_47 . V_46 ,
F_114 ( V_126 ) ,
V_252 * 2 ) ;
if ( V_101 )
return V_101 ;
goto V_251;
}
if ( F_141 ( V_253 , V_126 ) ) {
V_126 -> V_47 . V_132 -> V_254 = 0xffff ;
goto V_251;
}
if ( F_141 ( V_255 , V_126 ) ) {
if ( ! F_139 ( V_126 ) ) {
F_143 ( V_126 -> V_127 , 1 ) ;
F_85 ( V_250 ,
& V_126 -> V_47 . V_132 -> V_155 ) ;
}
goto V_251;
}
if ( F_141 ( V_256 , V_126 ) ) {
if ( F_139 ( V_126 ) ) {
F_143 ( V_126 -> V_127 , 0 ) ;
F_87 ( V_250 ,
& V_126 -> V_47 . V_132 -> V_155 ) ;
}
goto V_251;
}
F_63 ( V_257 , & V_126 -> V_258 ) ;
return 0 ;
}
long F_144 ( struct V_125 * V_126 , T_4 V_259 , int V_260 )
{
return F_145 ( V_126 -> V_47 . V_46 , V_259 ,
V_260 ? V_261 : 0 ) ;
}
static void F_146 ( struct V_125 * V_126 , bool V_262 ,
unsigned long V_263 )
{
struct V_82 V_264 ;
struct V_265 V_266 ;
if ( V_262 ) {
V_266 . V_267 . V_16 . V_268 = V_263 ;
V_266 . type = V_269 ;
F_102 ( F_147 ( V_126 , & V_266 ) ) ;
} else {
V_264 . type = V_270 ;
V_264 . V_271 = V_263 ;
F_102 ( F_37 ( V_126 -> V_15 , & V_264 ) ) ;
}
}
void F_148 ( struct V_125 * V_126 ,
struct V_272 * V_273 )
{
F_149 ( V_126 , V_273 -> V_47 . V_136 ) ;
F_146 ( V_126 , true , V_273 -> V_47 . V_136 ) ;
}
void F_150 ( struct V_125 * V_126 ,
struct V_272 * V_273 )
{
F_151 ( V_126 , V_273 -> V_47 . V_136 ) ;
F_146 ( V_126 , false , V_273 -> V_47 . V_136 ) ;
}
void F_152 ( struct V_125 * V_126 ,
struct V_272 * V_273 )
{
}
bool F_153 ( struct V_125 * V_126 )
{
return true ;
}
static int F_154 ( struct V_125 * V_126 )
{
T_5 V_274 ;
struct V_275 V_47 ;
int V_101 ;
if ( V_126 -> V_47 . V_136 == V_137 )
return 0 ;
if ( ( V_126 -> V_47 . V_132 -> V_156 . V_157 & V_126 -> V_47 . V_216 ) !=
V_126 -> V_47 . V_214 )
return 0 ;
if ( F_155 ( V_126 ) )
return 0 ;
if ( F_108 ( V_126 ) )
return 0 ;
if ( ! ( V_126 -> V_47 . V_132 -> V_162 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_126 -> V_47 . V_46 -> V_122 )
return 0 ;
V_274 = F_156 ( V_126 -> V_15 , F_157 ( V_110 -> V_276 . V_277 ) ) ;
V_274 += V_110 -> V_276 . V_277 & ~ V_278 ;
if ( F_158 ( V_126 , V_126 -> V_47 . V_136 , & V_47 . V_136 , 8 ) )
return 0 ;
V_101 = F_159 ( V_126 , V_110 -> V_276 . V_277 , V_274 , & V_47 ) ;
return V_101 ;
}
static int F_160 ( struct V_125 * V_126 )
{
int V_101 , V_155 ;
F_161 ( V_126 ) ;
memcpy ( & V_126 -> V_47 . V_132 -> V_279 , & V_126 -> V_138 -> V_151 . V_152 . V_220 [ 14 ] , 16 ) ;
if ( F_162 () )
F_163 () ;
if ( F_164 ( V_280 ) )
F_165 () ;
if ( ! F_62 ( V_126 -> V_15 ) ) {
V_101 = F_166 ( V_126 ) ;
if ( V_101 )
return V_101 ;
}
V_101 = F_140 ( V_126 ) ;
if ( V_101 )
return V_101 ;
if ( F_167 ( V_126 ) ) {
F_168 ( V_126 ) ;
F_169 ( V_126 ) ;
}
V_126 -> V_47 . V_132 -> V_281 = 0 ;
V_155 = F_28 ( & V_126 -> V_47 . V_132 -> V_155 ) ;
F_58 ( V_126 , 6 , L_7 , V_155 ) ;
F_170 ( V_126 , V_155 ) ;
return 0 ;
}
static int F_171 ( struct V_125 * V_126 , int V_282 )
{
int V_101 = - 1 ;
F_58 ( V_126 , 6 , L_8 ,
V_126 -> V_47 . V_132 -> V_281 ) ;
F_172 ( V_126 , V_126 -> V_47 . V_132 -> V_281 ) ;
if ( F_167 ( V_126 ) )
F_173 ( V_126 ) ;
if ( V_282 >= 0 ) {
V_101 = 0 ;
} else if ( F_62 ( V_126 -> V_15 ) ) {
V_126 -> V_138 -> V_282 = V_283 ;
V_126 -> V_138 -> V_284 . V_285 =
V_110 -> V_276 . V_277 ;
V_126 -> V_138 -> V_284 . V_286 = 0x10 ;
V_101 = - V_287 ;
} else if ( V_110 -> V_276 . V_288 ) {
F_174 ( V_126 ) ;
V_110 -> V_276 . V_288 = 0 ;
if ( F_154 ( V_126 ) ) {
V_101 = 0 ;
} else {
T_4 V_259 = V_110 -> V_276 . V_277 ;
V_101 = F_144 ( V_126 , V_259 , 1 ) ;
}
}
if ( V_101 == - 1 ) {
F_58 ( V_126 , 3 , L_2 , L_9 ) ;
F_175 ( V_126 ) ;
V_101 = F_176 ( V_126 , V_289 ) ;
}
memcpy ( & V_126 -> V_138 -> V_151 . V_152 . V_220 [ 14 ] , & V_126 -> V_47 . V_132 -> V_279 , 16 ) ;
if ( V_101 == 0 ) {
if ( F_62 ( V_126 -> V_15 ) )
V_101 = V_126 -> V_47 . V_132 -> V_281 ? - V_290 : 0 ;
else
V_101 = F_177 ( V_126 ) ;
}
return V_101 ;
}
static int F_178 ( struct V_125 * V_126 )
{
int V_101 , V_282 ;
V_126 -> V_291 = F_29 ( & V_126 -> V_15 -> V_75 ) ;
do {
V_101 = F_160 ( V_126 ) ;
if ( V_101 )
break;
F_31 ( & V_126 -> V_15 -> V_75 , V_126 -> V_291 ) ;
F_179 () ;
F_180 () ;
F_181 () ;
V_282 = F_182 ( V_126 -> V_47 . V_132 ,
V_126 -> V_138 -> V_151 . V_152 . V_220 ) ;
F_183 () ;
V_126 -> V_291 = F_29 ( & V_126 -> V_15 -> V_75 ) ;
V_101 = F_171 ( V_126 , V_282 ) ;
} while ( ! F_184 ( V_110 ) && ! F_185 ( V_126 ) && ! V_101 );
F_31 ( & V_126 -> V_15 -> V_75 , V_126 -> V_291 ) ;
return V_101 ;
}
static void F_186 ( struct V_125 * V_126 , struct V_292 * V_292 )
{
V_126 -> V_47 . V_132 -> V_156 . V_157 = V_292 -> V_227 ;
V_126 -> V_47 . V_132 -> V_156 . V_158 = V_292 -> V_228 ;
if ( V_292 -> V_293 & V_140 )
F_90 ( V_126 , V_292 -> V_151 . V_152 . V_294 ) ;
if ( V_292 -> V_293 & V_143 ) {
memcpy ( & V_126 -> V_47 . V_132 -> V_162 , & V_292 -> V_151 . V_152 . V_223 , 128 ) ;
F_115 ( V_253 , V_126 ) ;
}
if ( V_292 -> V_293 & V_144 ) {
V_126 -> V_47 . V_132 -> V_159 = V_292 -> V_151 . V_152 . V_159 ;
V_126 -> V_47 . V_132 -> V_160 = V_292 -> V_151 . V_152 . V_160 ;
V_126 -> V_47 . V_132 -> V_161 = V_292 -> V_151 . V_152 . V_161 ;
V_126 -> V_47 . V_132 -> V_164 = V_292 -> V_151 . V_152 . V_164 ;
V_126 -> V_47 . V_132 -> V_163 = V_292 -> V_151 . V_152 . V_163 ;
}
if ( V_292 -> V_293 & V_145 ) {
V_126 -> V_47 . V_136 = V_292 -> V_151 . V_152 . V_295 ;
V_126 -> V_47 . V_216 = V_292 -> V_151 . V_152 . V_296 ;
V_126 -> V_47 . V_214 = V_292 -> V_151 . V_152 . V_297 ;
}
V_292 -> V_293 = 0 ;
}
static void F_187 ( struct V_125 * V_126 , struct V_292 * V_292 )
{
V_292 -> V_227 = V_126 -> V_47 . V_132 -> V_156 . V_157 ;
V_292 -> V_228 = V_126 -> V_47 . V_132 -> V_156 . V_158 ;
V_292 -> V_151 . V_152 . V_294 = F_114 ( V_126 ) ;
memcpy ( & V_292 -> V_151 . V_152 . V_223 , & V_126 -> V_47 . V_132 -> V_162 , 128 ) ;
V_292 -> V_151 . V_152 . V_159 = V_126 -> V_47 . V_132 -> V_159 ;
V_292 -> V_151 . V_152 . V_160 = V_126 -> V_47 . V_132 -> V_160 ;
V_292 -> V_151 . V_152 . V_161 = V_126 -> V_47 . V_132 -> V_161 ;
V_292 -> V_151 . V_152 . V_164 = V_126 -> V_47 . V_132 -> V_164 ;
V_292 -> V_151 . V_152 . V_163 = V_126 -> V_47 . V_132 -> V_163 ;
V_292 -> V_151 . V_152 . V_295 = V_126 -> V_47 . V_136 ;
V_292 -> V_151 . V_152 . V_296 = V_126 -> V_47 . V_216 ;
V_292 -> V_151 . V_152 . V_297 = V_126 -> V_47 . V_214 ;
}
int F_188 ( struct V_125 * V_126 , struct V_292 * V_292 )
{
int V_101 ;
T_6 V_298 ;
if ( F_185 ( V_126 ) ) {
F_189 ( V_126 ) ;
return 0 ;
}
if ( V_126 -> V_299 )
F_190 ( V_300 , & V_126 -> V_301 , & V_298 ) ;
if ( ! F_91 ( V_126 -> V_15 ) ) {
F_138 ( V_126 ) ;
} else if ( F_131 ( V_126 ) ) {
F_191 ( L_10 ,
V_126 -> V_127 ) ;
return - V_14 ;
}
F_186 ( V_126 , V_292 ) ;
F_192 () ;
V_101 = F_178 ( V_126 ) ;
if ( F_184 ( V_110 ) && ! V_101 ) {
V_292 -> V_282 = V_302 ;
V_101 = - V_303 ;
}
if ( F_185 ( V_126 ) && ! V_101 ) {
F_189 ( V_126 ) ;
V_101 = 0 ;
}
if ( V_101 == - V_290 ) {
V_292 -> V_282 = V_304 ;
V_292 -> V_305 . V_281 = V_126 -> V_47 . V_132 -> V_281 ;
V_292 -> V_305 . V_306 = V_126 -> V_47 . V_132 -> V_306 ;
V_292 -> V_305 . V_307 = V_126 -> V_47 . V_132 -> V_307 ;
V_101 = 0 ;
}
if ( V_101 == - V_287 ) {
V_101 = 0 ;
}
F_187 ( V_126 , V_292 ) ;
if ( V_126 -> V_299 )
F_190 ( V_300 , & V_298 , NULL ) ;
V_126 -> V_308 . V_309 ++ ;
return V_101 ;
}
int F_193 ( struct V_125 * V_126 , unsigned long V_259 )
{
unsigned char V_310 = 1 ;
unsigned int V_311 ;
V_209 V_312 ;
int V_101 ;
if ( V_259 == V_313 ) {
if ( F_194 ( V_126 , 163 , & V_310 , 1 ) )
return - V_84 ;
V_259 = V_314 ;
} else if ( V_259 == V_315 ) {
if ( F_195 ( V_126 , 163 , & V_310 , 1 ) )
return - V_84 ;
V_259 = F_196 ( V_126 , V_314 ) ;
}
V_101 = F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_317 ) ,
V_126 -> V_47 . V_150 . V_148 , 128 ) ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_318 ) ,
V_126 -> V_138 -> V_151 . V_152 . V_220 , 128 ) ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_226 ) ,
& V_126 -> V_47 . V_132 -> V_156 , 16 ) ;
V_311 = F_114 ( V_126 ) ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_319 ) ,
& V_311 , 4 ) ;
V_101 |= F_194 ( V_126 ,
V_259 + F_197 ( struct V_316 , V_320 ) ,
& V_126 -> V_47 . V_150 . V_147 , 4 ) ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_321 ) ,
& V_126 -> V_47 . V_132 -> V_161 , 4 ) ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_322 ) ,
& V_126 -> V_47 . V_132 -> V_159 , 8 ) ;
V_312 = V_126 -> V_47 . V_132 -> V_160 >> 8 ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_323 ) ,
& V_312 , 8 ) ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_324 ) ,
& V_126 -> V_138 -> V_151 . V_152 . V_153 , 64 ) ;
V_101 |= F_194 ( V_126 , V_259 + F_197 ( struct V_316 , V_325 ) ,
& V_126 -> V_47 . V_132 -> V_162 , 128 ) ;
return V_101 ? - V_84 : 0 ;
}
int F_198 ( struct V_125 * V_126 , unsigned long V_158 )
{
F_78 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_79 ( V_126 -> V_47 . V_150 . V_148 ) ;
F_80 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
return F_193 ( V_126 , V_158 ) ;
}
static void F_199 ( struct V_125 * V_126 )
{
F_141 ( V_255 , V_126 ) ;
F_115 ( V_256 , V_126 ) ;
F_113 ( V_126 ) ;
}
static void F_200 ( struct V_15 * V_15 )
{
unsigned int V_134 ;
struct V_125 * V_126 ;
F_71 (i, vcpu, kvm) {
F_199 ( V_126 ) ;
}
}
static void F_201 ( struct V_125 * V_126 )
{
F_141 ( V_256 , V_126 ) ;
F_115 ( V_255 , V_126 ) ;
F_113 ( V_126 ) ;
}
void F_138 ( struct V_125 * V_126 )
{
int V_134 , V_72 , V_326 = 0 ;
if ( ! F_131 ( V_126 ) )
return;
F_202 ( V_126 -> V_127 , 1 ) ;
F_44 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
V_72 = F_28 ( & V_126 -> V_15 -> V_72 ) ;
for ( V_134 = 0 ; V_134 < V_72 ; V_134 ++ ) {
if ( ! F_131 ( V_126 -> V_15 -> V_135 [ V_134 ] ) )
V_326 ++ ;
}
if ( V_326 == 0 ) {
F_201 ( V_126 ) ;
} else if ( V_326 == 1 ) {
F_200 ( V_126 -> V_15 ) ;
}
F_87 ( V_169 , & V_126 -> V_47 . V_132 -> V_155 ) ;
F_115 ( V_253 , V_126 ) ;
F_45 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
return;
}
void F_92 ( struct V_125 * V_126 )
{
int V_134 , V_72 , V_326 = 0 ;
struct V_125 * V_327 = NULL ;
if ( F_131 ( V_126 ) )
return;
F_202 ( V_126 -> V_127 , 0 ) ;
F_44 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
V_72 = F_28 ( & V_126 -> V_15 -> V_72 ) ;
F_44 ( & V_126 -> V_47 . V_194 . V_71 ) ;
F_85 ( V_169 , & V_126 -> V_47 . V_132 -> V_155 ) ;
V_126 -> V_47 . V_194 . V_328 &=
~ ( V_329 | V_330 ) ;
F_45 ( & V_126 -> V_47 . V_194 . V_71 ) ;
F_199 ( V_126 ) ;
for ( V_134 = 0 ; V_134 < V_72 ; V_134 ++ ) {
if ( ! F_131 ( V_126 -> V_15 -> V_135 [ V_134 ] ) ) {
V_326 ++ ;
V_327 = V_126 -> V_15 -> V_135 [ V_134 ] ;
}
}
if ( V_326 == 1 ) {
F_201 ( V_327 ) ;
}
F_45 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
return;
}
static int F_203 ( struct V_125 * V_126 ,
struct V_61 * V_62 )
{
int V_17 ;
if ( V_62 -> V_63 )
return - V_14 ;
switch ( V_62 -> V_62 ) {
case V_26 :
if ( ! V_126 -> V_15 -> V_47 . V_123 ) {
V_126 -> V_15 -> V_47 . V_123 = 1 ;
F_204 ( V_126 -> V_15 ) ;
}
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
long F_205 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_125 * V_126 = V_10 -> V_79 ;
void T_2 * V_80 = ( void T_2 * ) V_12 ;
int V_68 ;
long V_17 ;
switch ( V_11 ) {
case V_81 : {
struct V_82 V_83 ;
struct V_265 V_331 ;
V_17 = - V_84 ;
if ( F_36 ( & V_83 , V_80 , sizeof( V_83 ) ) )
break;
if ( F_206 ( & V_83 , & V_331 ) )
return - V_14 ;
V_17 = F_147 ( V_126 , & V_331 ) ;
break;
}
case V_332 :
V_68 = F_29 ( & V_126 -> V_15 -> V_75 ) ;
V_17 = F_198 ( V_126 , V_12 ) ;
F_31 ( & V_126 -> V_15 -> V_75 , V_68 ) ;
break;
case V_333 : {
T_3 V_226 ;
V_17 = - V_84 ;
if ( F_36 ( & V_226 , V_80 , sizeof( V_226 ) ) )
break;
V_17 = F_130 ( V_126 , V_226 ) ;
break;
}
case V_334 :
V_17 = F_122 ( V_126 ) ;
break;
case V_335 :
case V_336 : {
struct V_203 V_204 ;
V_17 = - V_84 ;
if ( F_36 ( & V_204 , V_80 , sizeof( V_204 ) ) )
break;
if ( V_11 == V_335 )
V_17 = F_120 ( V_126 , & V_204 ) ;
else
V_17 = F_118 ( V_126 , & V_204 ) ;
break;
}
#ifdef F_13
case V_337 : {
struct V_338 V_339 ;
if ( F_36 ( & V_339 , V_80 , sizeof( V_339 ) ) ) {
V_17 = - V_84 ;
break;
}
if ( ! F_62 ( V_126 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_207 ( V_126 -> V_47 . V_46 , V_339 . V_340 ,
V_339 . V_341 , V_339 . V_342 ) ;
break;
}
case V_343 : {
struct V_338 V_339 ;
if ( F_36 ( & V_339 , V_80 , sizeof( V_339 ) ) ) {
V_17 = - V_84 ;
break;
}
if ( ! F_62 ( V_126 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_208 ( V_126 -> V_47 . V_46 , V_339 . V_341 ,
V_339 . V_342 ) ;
break;
}
#endif
case V_344 : {
V_17 = F_145 ( V_126 -> V_47 . V_46 , V_12 , 0 ) ;
break;
}
case V_85 :
{
struct V_61 V_62 ;
V_17 = - V_84 ;
if ( F_36 ( & V_62 , V_80 , sizeof( V_62 ) ) )
break;
V_17 = F_203 ( V_126 , & V_62 ) ;
break;
}
default:
V_17 = - V_92 ;
}
return V_17 ;
}
int F_209 ( struct V_125 * V_126 , struct V_345 * V_346 )
{
#ifdef F_13
if ( ( V_346 -> V_347 == V_348 )
&& ( F_62 ( V_126 -> V_15 ) ) ) {
V_346 -> V_349 = F_210 ( V_126 -> V_47 . V_132 ) ;
F_211 ( V_346 -> V_349 ) ;
return 0 ;
}
#endif
return V_350 ;
}
int F_212 ( struct V_15 * V_15 , struct V_41 * V_56 ,
unsigned long V_51 )
{
return 0 ;
}
int F_213 ( struct V_15 * V_15 ,
struct V_41 * V_42 ,
struct V_351 * V_352 ,
enum V_353 V_354 )
{
if ( V_352 -> V_355 & 0xffffful )
return - V_14 ;
if ( V_352 -> V_356 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_214 ( struct V_15 * V_15 ,
struct V_351 * V_352 ,
const struct V_41 * V_357 ,
enum V_353 V_354 )
{
int V_101 ;
if ( V_357 -> V_355 == V_352 -> V_355 &&
V_357 -> V_50 * V_252 == V_352 -> V_358 &&
V_357 -> V_51 * V_252 == V_352 -> V_356 )
return;
V_101 = F_207 ( V_15 -> V_47 . V_46 , V_352 -> V_355 ,
V_352 -> V_358 , V_352 -> V_356 ) ;
if ( V_101 )
F_215 ( V_359 L_11 ) ;
return;
}
static int T_7 F_216 ( void )
{
int V_67 ;
V_67 = F_217 ( NULL , sizeof( struct V_125 ) , 0 , V_360 ) ;
if ( V_67 )
return V_67 ;
V_2 = ( unsigned long * ) F_43 ( V_95 | V_96 ) ;
if ( ! V_2 ) {
F_218 () ;
return - V_97 ;
}
memcpy ( V_2 , V_361 . V_362 , 16 ) ;
V_2 [ 0 ] &= 0xff82fffbf47c2000UL ;
V_2 [ 1 ] &= 0x005c000000000000UL ;
return 0 ;
}
static void T_8 F_219 ( void )
{
F_56 ( ( unsigned long ) V_2 ) ;
F_218 () ;
}
