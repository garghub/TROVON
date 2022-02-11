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
F_30 ( V_15 -> V_47 . V_46 -> V_48 , 0 , V_76 , false ) ;
F_31 ( & V_15 -> V_75 , V_68 ) ;
F_25 ( & V_15 -> V_71 ) ;
V_67 = 0 ;
break;
default:
V_67 = - V_77 ;
break;
}
return V_67 ;
}
static int F_32 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
int V_67 ;
switch ( V_66 -> V_78 ) {
case V_79 :
V_67 = F_27 ( V_15 , V_66 ) ;
break;
default:
V_67 = - V_77 ;
break;
}
return V_67 ;
}
static int F_33 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
return - V_77 ;
}
static int F_34 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
int V_67 ;
switch ( V_66 -> V_78 ) {
case V_79 :
switch ( V_66 -> V_66 ) {
case V_69 :
case V_74 :
V_67 = 0 ;
break;
default:
V_67 = - V_77 ;
break;
}
break;
default:
V_67 = - V_77 ;
break;
}
return V_67 ;
}
long F_35 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_15 * V_15 = V_10 -> V_80 ;
void T_2 * V_81 = ( void T_2 * ) V_12 ;
struct V_65 V_66 ;
int V_17 ;
switch ( V_11 ) {
case V_82 : {
struct V_83 V_84 ;
V_17 = - V_85 ;
if ( F_36 ( & V_84 , V_81 , sizeof( V_84 ) ) )
break;
V_17 = F_37 ( V_15 , & V_84 ) ;
break;
}
case V_86 : {
struct V_61 V_62 ;
V_17 = - V_85 ;
if ( F_36 ( & V_62 , V_81 , sizeof( V_62 ) ) )
break;
V_17 = F_26 ( V_15 , & V_62 ) ;
break;
}
case V_87 : {
struct V_88 V_89 ;
V_17 = - V_14 ;
if ( V_15 -> V_47 . V_64 ) {
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
F_38 ( V_15 , & V_89 , 0 , 0 ) ;
V_17 = 0 ;
}
break;
}
case V_90 : {
V_17 = - V_85 ;
if ( F_36 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_32 ( V_15 , & V_66 ) ;
break;
}
case V_91 : {
V_17 = - V_85 ;
if ( F_36 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_33 ( V_15 , & V_66 ) ;
break;
}
case V_92 : {
V_17 = - V_85 ;
if ( F_36 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_34 ( V_15 , & V_66 ) ;
break;
}
default:
V_17 = - V_93 ;
}
return V_17 ;
}
static int F_39 ( struct V_15 * V_15 )
{
if ( ! F_1 ( 76 ) )
return 0 ;
V_15 -> V_47 . V_94 . V_95 = F_40 ( sizeof( * V_15 -> V_47 . V_94 . V_95 ) ,
V_96 | V_97 ) ;
if ( ! V_15 -> V_47 . V_94 . V_95 )
return - V_98 ;
V_15 -> V_47 . V_94 . V_99 = ( V_100 ) ( unsigned long ) V_15 -> V_47 . V_94 . V_95 |
V_101 ;
return 0 ;
}
int F_41 ( struct V_15 * V_15 , unsigned long type )
{
int V_102 ;
char V_103 [ 16 ] ;
static unsigned long V_104 ;
V_102 = - V_14 ;
#ifdef F_13
if ( type & ~ V_105 )
goto V_106;
if ( ( type & V_105 ) && ( ! F_42 ( V_107 ) ) )
goto V_106;
#else
if ( type )
goto V_106;
#endif
V_102 = F_11 () ;
if ( V_102 )
goto V_106;
V_102 = - V_98 ;
V_15 -> V_47 . V_108 = (struct V_109 * ) F_43 ( V_96 ) ;
if ( ! V_15 -> V_47 . V_108 )
goto V_106;
F_44 ( & V_110 ) ;
V_104 = ( V_104 + 16 ) & 0x7f0 ;
V_15 -> V_47 . V_108 = (struct V_109 * ) ( ( char * ) V_15 -> V_47 . V_108 + V_104 ) ;
F_45 ( & V_110 ) ;
sprintf ( V_103 , L_1 , V_111 -> V_112 ) ;
V_15 -> V_47 . V_113 = F_46 ( V_103 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_15 -> V_47 . V_113 )
goto V_114;
if ( F_39 ( V_15 ) < 0 )
goto V_115;
F_47 ( & V_15 -> V_47 . V_116 . V_71 ) ;
F_48 ( & V_15 -> V_47 . V_116 . V_117 ) ;
F_49 ( & V_15 -> V_47 . V_118 ) ;
F_50 ( V_15 -> V_47 . V_113 , & V_119 ) ;
F_51 ( V_15 , 3 , L_2 , L_3 ) ;
if ( type & V_105 ) {
V_15 -> V_47 . V_46 = NULL ;
} else {
V_15 -> V_47 . V_46 = F_52 ( V_111 -> V_48 , ( 1UL << 44 ) - 1 ) ;
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
F_53 ( V_15 -> V_47 . V_94 . V_95 ) ;
V_115:
F_54 ( V_15 -> V_47 . V_113 ) ;
V_114:
F_55 ( ( unsigned long ) ( V_15 -> V_47 . V_108 ) ) ;
V_106:
return V_102 ;
}
void F_56 ( struct V_125 * V_126 )
{
F_57 ( V_126 , 3 , L_2 , L_4 ) ;
F_58 ( V_126 -> V_127 ) ;
F_59 ( V_126 ) ;
F_60 ( V_126 ) ;
if ( ! F_61 ( V_126 -> V_15 ) ) {
F_62 ( 63 - V_126 -> V_127 ,
( unsigned long * ) & V_126 -> V_15 -> V_47 . V_108 -> V_128 ) ;
if ( V_126 -> V_15 -> V_47 . V_108 -> V_129 [ V_126 -> V_127 ] . V_130 ==
( V_131 ) V_126 -> V_47 . V_132 )
V_126 -> V_15 -> V_47 . V_108 -> V_129 [ V_126 -> V_127 ] . V_130 = 0 ;
}
F_63 () ;
if ( F_61 ( V_126 -> V_15 ) )
F_64 ( V_126 -> V_47 . V_46 ) ;
if ( F_65 ( V_126 -> V_15 ) )
F_66 ( V_126 ) ;
F_55 ( ( unsigned long ) ( V_126 -> V_47 . V_132 ) ) ;
F_67 ( V_126 ) ;
F_68 ( V_133 , V_126 ) ;
}
static void F_69 ( struct V_15 * V_15 )
{
unsigned int V_134 ;
struct V_125 * V_126 ;
F_70 (i, vcpu, kvm)
F_56 ( V_126 ) ;
F_21 ( & V_15 -> V_71 ) ;
for ( V_134 = 0 ; V_134 < F_28 ( & V_15 -> V_72 ) ; V_134 ++ )
V_15 -> V_135 [ V_134 ] = NULL ;
F_71 ( & V_15 -> V_72 , 0 ) ;
F_25 ( & V_15 -> V_71 ) ;
}
void F_72 ( struct V_15 * V_15 )
{
F_69 ( V_15 ) ;
F_55 ( ( unsigned long ) ( V_15 -> V_47 . V_108 ) ) ;
F_54 ( V_15 -> V_47 . V_113 ) ;
F_53 ( V_15 -> V_47 . V_94 . V_95 ) ;
if ( ! F_61 ( V_15 ) )
F_64 ( V_15 -> V_47 . V_46 ) ;
F_73 ( V_15 ) ;
F_74 ( V_15 ) ;
}
int F_75 ( struct V_125 * V_126 )
{
V_126 -> V_47 . V_136 = V_137 ;
F_60 ( V_126 ) ;
if ( F_61 ( V_126 -> V_15 ) ) {
V_126 -> V_47 . V_46 = F_52 ( V_111 -> V_48 , - 1UL ) ;
if ( ! V_126 -> V_47 . V_46 )
return - V_98 ;
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
void F_76 ( struct V_125 * V_126 , int V_129 )
{
F_77 ( & V_126 -> V_47 . V_146 . V_147 ) ;
F_78 ( V_126 -> V_47 . V_146 . V_148 ) ;
F_79 ( V_126 -> V_47 . V_149 ) ;
F_80 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_81 ( V_126 -> V_47 . V_150 . V_148 ) ;
F_82 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
F_83 ( V_126 -> V_47 . V_46 ) ;
F_84 ( V_154 , & V_126 -> V_47 . V_132 -> V_155 ) ;
}
void F_85 ( struct V_125 * V_126 )
{
F_86 ( V_154 , & V_126 -> V_47 . V_132 -> V_155 ) ;
F_87 ( V_126 -> V_47 . V_46 ) ;
F_77 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_78 ( V_126 -> V_47 . V_150 . V_148 ) ;
F_79 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
F_80 ( & V_126 -> V_47 . V_146 . V_147 ) ;
F_81 ( V_126 -> V_47 . V_146 . V_148 ) ;
F_82 ( V_126 -> V_47 . V_149 ) ;
}
static void F_88 ( struct V_125 * V_126 )
{
V_126 -> V_47 . V_132 -> V_156 . V_157 = 0UL ;
V_126 -> V_47 . V_132 -> V_156 . V_158 = 0UL ;
F_89 ( V_126 , 0 ) ;
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
F_60 ( V_126 ) ;
if ( ! F_90 ( V_126 -> V_15 ) )
F_91 ( V_126 ) ;
F_59 ( V_126 ) ;
}
int F_92 ( struct V_125 * V_126 )
{
return 0 ;
}
static void F_93 ( struct V_125 * V_126 )
{
if ( ! F_1 ( 76 ) )
return;
V_126 -> V_47 . V_132 -> V_99 = V_126 -> V_15 -> V_47 . V_94 . V_99 ;
}
void F_66 ( struct V_125 * V_126 )
{
F_55 ( V_126 -> V_47 . V_132 -> V_165 ) ;
V_126 -> V_47 . V_132 -> V_165 = 0 ;
}
int F_94 ( struct V_125 * V_126 )
{
V_126 -> V_47 . V_132 -> V_165 = F_43 ( V_96 ) ;
if ( ! V_126 -> V_47 . V_132 -> V_165 )
return - V_98 ;
V_126 -> V_47 . V_132 -> V_166 |= 0x80 ;
V_126 -> V_47 . V_132 -> V_166 &= ~ 0x08 ;
return 0 ;
}
int F_95 ( struct V_125 * V_126 )
{
int V_102 = 0 ;
F_71 ( & V_126 -> V_47 . V_132 -> V_155 , V_167 |
V_168 |
V_169 |
V_170 ) ;
V_126 -> V_47 . V_132 -> V_171 = 6 ;
if ( F_1 ( 50 ) && F_1 ( 73 ) )
V_126 -> V_47 . V_132 -> V_171 |= 0x10 ;
V_126 -> V_47 . V_132 -> V_166 = 8 ;
V_126 -> V_47 . V_132 -> V_172 = 0xD1002000U ;
if ( F_96 () )
V_126 -> V_47 . V_132 -> V_172 |= 1 ;
V_126 -> V_47 . V_132 -> V_173 = ( int ) ( long ) V_2 ;
V_126 -> V_47 . V_132 -> V_174 |= V_175 | V_176 | V_177 |
V_178 ;
if ( F_65 ( V_126 -> V_15 ) ) {
V_102 = F_94 ( V_126 ) ;
if ( V_102 )
return V_102 ;
}
F_97 ( & V_126 -> V_47 . V_179 , V_180 , V_181 ) ;
V_126 -> V_47 . V_179 . V_182 = V_183 ;
F_98 ( & V_126 -> V_47 . V_184 ) ;
V_126 -> V_47 . V_184 . V_185 = 0xff ;
F_93 ( V_126 ) ;
return V_102 ;
}
struct V_125 * F_99 ( struct V_15 * V_15 ,
unsigned int V_186 )
{
struct V_125 * V_126 ;
struct V_187 * V_187 ;
int V_102 = - V_14 ;
if ( V_186 >= V_36 )
goto V_57;
V_102 = - V_98 ;
V_126 = F_100 ( V_133 , V_96 ) ;
if ( ! V_126 )
goto V_57;
V_187 = (struct V_187 * ) F_43 ( V_96 ) ;
if ( ! V_187 )
goto V_188;
V_126 -> V_47 . V_132 = & V_187 -> V_132 ;
V_126 -> V_47 . V_132 -> V_189 = ( unsigned long ) & V_187 -> V_190 ;
V_126 -> V_47 . V_132 -> V_191 = V_186 ;
if ( ! F_61 ( V_15 ) ) {
if ( ! V_15 -> V_47 . V_108 ) {
F_101 ( 1 ) ;
goto V_188;
}
if ( ! V_15 -> V_47 . V_108 -> V_129 [ V_186 ] . V_130 )
V_15 -> V_47 . V_108 -> V_129 [ V_186 ] . V_130 =
( V_131 ) V_126 -> V_47 . V_132 ;
V_126 -> V_47 . V_132 -> V_192 =
( V_100 ) ( ( ( V_131 ) V_15 -> V_47 . V_108 ) >> 32 ) ;
V_126 -> V_47 . V_132 -> V_193 = ( V_100 ) ( V_131 ) V_15 -> V_47 . V_108 ;
F_102 ( 63 - V_186 , ( unsigned long * ) & V_15 -> V_47 . V_108 -> V_128 ) ;
}
F_47 ( & V_126 -> V_47 . V_194 . V_71 ) ;
F_48 ( & V_126 -> V_47 . V_194 . V_117 ) ;
V_126 -> V_47 . V_194 . V_116 = & V_15 -> V_47 . V_116 ;
V_126 -> V_47 . V_194 . V_195 = & V_126 -> V_195 ;
V_126 -> V_47 . V_194 . V_155 = & V_126 -> V_47 . V_132 -> V_155 ;
V_102 = F_103 ( V_126 , V_15 , V_186 ) ;
if ( V_102 )
goto V_196;
F_51 ( V_15 , 3 , L_5 , V_186 , V_126 ,
V_126 -> V_47 . V_132 ) ;
F_104 ( V_186 , V_126 , V_126 -> V_47 . V_132 ) ;
return V_126 ;
V_196:
F_55 ( ( unsigned long ) ( V_126 -> V_47 . V_132 ) ) ;
V_188:
F_68 ( V_133 , V_126 ) ;
V_57:
return F_105 ( V_102 ) ;
}
int F_106 ( struct V_125 * V_126 )
{
return F_107 ( V_126 ) ;
}
void F_108 ( struct V_125 * V_126 )
{
F_84 ( V_197 , & V_126 -> V_47 . V_132 -> V_198 ) ;
}
void F_109 ( struct V_125 * V_126 )
{
F_86 ( V_197 , & V_126 -> V_47 . V_132 -> V_198 ) ;
}
void F_110 ( struct V_125 * V_126 )
{
F_84 ( V_199 , & V_126 -> V_47 . V_132 -> V_155 ) ;
while ( V_126 -> V_47 . V_132 -> V_200 & V_201 )
F_111 () ;
}
void F_112 ( struct V_125 * V_126 )
{
F_108 ( V_126 ) ;
F_110 ( V_126 ) ;
}
static void V_5 ( struct V_46 * V_46 , unsigned long V_45 )
{
int V_134 ;
struct V_15 * V_15 = V_46 -> V_121 ;
struct V_125 * V_126 ;
F_70 (i, vcpu, kvm) {
if ( F_113 ( V_126 ) == ( V_45 & ~ 0x1000UL ) ) {
F_57 ( V_126 , 2 , L_6 , V_45 ) ;
F_114 ( V_202 , V_126 ) ;
F_112 ( V_126 ) ;
}
}
}
int F_115 ( struct V_125 * V_126 )
{
F_116 () ;
return 0 ;
}
static int F_117 ( struct V_125 * V_126 ,
struct V_203 * V_204 )
{
int V_17 = - V_14 ;
switch ( V_204 -> V_186 ) {
case V_205 :
V_17 = F_118 ( V_126 -> V_47 . V_132 -> V_161 ,
( V_206 T_2 * ) V_204 -> V_158 ) ;
break;
case V_207 :
V_17 = F_118 ( V_126 -> V_47 . V_132 -> V_208 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_210 :
V_17 = F_118 ( V_126 -> V_47 . V_132 -> V_159 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_211 :
V_17 = F_118 ( V_126 -> V_47 . V_132 -> V_160 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_212 :
V_17 = F_118 ( V_126 -> V_47 . V_136 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_213 :
V_17 = F_118 ( V_126 -> V_47 . V_214 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_215 :
V_17 = F_118 ( V_126 -> V_47 . V_216 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_217 :
V_17 = F_118 ( V_126 -> V_47 . V_132 -> V_164 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_218 :
V_17 = F_118 ( V_126 -> V_47 . V_132 -> V_163 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_119 ( struct V_125 * V_126 ,
struct V_203 * V_204 )
{
int V_17 = - V_14 ;
switch ( V_204 -> V_186 ) {
case V_205 :
V_17 = F_120 ( V_126 -> V_47 . V_132 -> V_161 ,
( V_206 T_2 * ) V_204 -> V_158 ) ;
break;
case V_207 :
V_17 = F_120 ( V_126 -> V_47 . V_132 -> V_208 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_210 :
V_17 = F_120 ( V_126 -> V_47 . V_132 -> V_159 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_211 :
V_17 = F_120 ( V_126 -> V_47 . V_132 -> V_160 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_212 :
V_17 = F_120 ( V_126 -> V_47 . V_136 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_213 :
V_17 = F_120 ( V_126 -> V_47 . V_214 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_215 :
V_17 = F_120 ( V_126 -> V_47 . V_216 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_217 :
V_17 = F_120 ( V_126 -> V_47 . V_132 -> V_164 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
case V_218 :
V_17 = F_120 ( V_126 -> V_47 . V_132 -> V_163 ,
( V_209 T_2 * ) V_204 -> V_158 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_121 ( struct V_125 * V_126 )
{
F_88 ( V_126 ) ;
return 0 ;
}
int F_122 ( struct V_125 * V_126 , struct V_219 * V_152 )
{
memcpy ( & V_126 -> V_138 -> V_151 . V_152 . V_220 , & V_152 -> V_220 , sizeof( V_152 -> V_220 ) ) ;
return 0 ;
}
int F_123 ( struct V_125 * V_126 , struct V_219 * V_152 )
{
memcpy ( & V_152 -> V_220 , & V_126 -> V_138 -> V_151 . V_152 . V_220 , sizeof( V_152 -> V_220 ) ) ;
return 0 ;
}
int F_124 ( struct V_125 * V_126 ,
struct V_221 * V_222 )
{
memcpy ( & V_126 -> V_138 -> V_151 . V_152 . V_153 , & V_222 -> V_153 , sizeof( V_222 -> V_153 ) ) ;
memcpy ( & V_126 -> V_47 . V_132 -> V_162 , & V_222 -> V_223 , sizeof( V_222 -> V_223 ) ) ;
F_82 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
return 0 ;
}
int F_125 ( struct V_125 * V_126 ,
struct V_221 * V_222 )
{
memcpy ( & V_222 -> V_153 , & V_126 -> V_138 -> V_151 . V_152 . V_153 , sizeof( V_222 -> V_153 ) ) ;
memcpy ( & V_222 -> V_223 , & V_126 -> V_47 . V_132 -> V_162 , sizeof( V_222 -> V_223 ) ) ;
return 0 ;
}
int F_126 ( struct V_125 * V_126 , struct V_224 * V_225 )
{
if ( F_127 ( V_225 -> V_147 ) )
return - V_14 ;
memcpy ( & V_126 -> V_47 . V_150 . V_148 , & V_225 -> V_148 , sizeof( V_225 -> V_148 ) ) ;
V_126 -> V_47 . V_150 . V_147 = V_225 -> V_147 ;
F_80 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_81 ( V_126 -> V_47 . V_150 . V_148 ) ;
return 0 ;
}
int F_128 ( struct V_125 * V_126 , struct V_224 * V_225 )
{
memcpy ( & V_225 -> V_148 , & V_126 -> V_47 . V_150 . V_148 , sizeof( V_225 -> V_148 ) ) ;
V_225 -> V_147 = V_126 -> V_47 . V_150 . V_147 ;
return 0 ;
}
static int F_129 ( struct V_125 * V_126 , T_3 V_226 )
{
int V_102 = 0 ;
if ( ! F_130 ( V_126 ) )
V_102 = - V_70 ;
else {
V_126 -> V_138 -> V_227 = V_226 . V_157 ;
V_126 -> V_138 -> V_228 = V_226 . V_158 ;
}
return V_102 ;
}
int F_131 ( struct V_125 * V_126 ,
struct V_229 * V_230 )
{
return - V_14 ;
}
int F_132 ( struct V_125 * V_126 ,
struct V_231 * V_232 )
{
int V_102 = 0 ;
V_126 -> V_233 = 0 ;
F_133 ( V_126 ) ;
if ( V_232 -> V_234 & ~ V_235 )
return - V_14 ;
if ( V_232 -> V_234 & V_236 ) {
V_126 -> V_233 = V_232 -> V_234 ;
F_84 ( V_237 , & V_126 -> V_47 . V_132 -> V_155 ) ;
if ( V_232 -> V_234 & V_238 )
V_102 = F_134 ( V_126 , V_232 ) ;
} else {
F_86 ( V_237 , & V_126 -> V_47 . V_132 -> V_155 ) ;
V_126 -> V_47 . V_239 . V_240 = 0 ;
}
if ( V_102 ) {
V_126 -> V_233 = 0 ;
F_133 ( V_126 ) ;
F_86 ( V_237 , & V_126 -> V_47 . V_132 -> V_155 ) ;
}
return V_102 ;
}
int F_135 ( struct V_125 * V_126 ,
struct V_241 * V_242 )
{
return F_130 ( V_126 ) ? V_243 :
V_244 ;
}
int F_136 ( struct V_125 * V_126 ,
struct V_241 * V_242 )
{
int V_102 = 0 ;
V_126 -> V_15 -> V_47 . V_245 = 1 ;
switch ( V_242 -> V_242 ) {
case V_243 :
F_91 ( V_126 ) ;
break;
case V_244 :
F_137 ( V_126 ) ;
break;
case V_246 :
case V_247 :
default:
V_102 = - V_77 ;
}
return V_102 ;
}
bool F_65 ( struct V_15 * V_15 )
{
if ( ! V_248 )
return false ;
if ( ! V_249 )
return false ;
if ( ! V_15 -> V_47 . V_73 )
return false ;
return true ;
}
static bool F_138 ( struct V_125 * V_126 )
{
return F_28 ( & V_126 -> V_47 . V_132 -> V_155 ) & V_250 ;
}
static int F_139 ( struct V_125 * V_126 )
{
V_251:
F_109 ( V_126 ) ;
if ( F_140 ( V_202 , V_126 ) ) {
int V_102 ;
V_102 = F_141 ( V_126 -> V_47 . V_46 ,
F_113 ( V_126 ) ,
V_252 * 2 ) ;
if ( V_102 )
return V_102 ;
goto V_251;
}
if ( F_140 ( V_253 , V_126 ) ) {
V_126 -> V_47 . V_132 -> V_254 = 0xffff ;
goto V_251;
}
if ( F_140 ( V_255 , V_126 ) ) {
if ( ! F_138 ( V_126 ) ) {
F_142 ( V_126 -> V_127 , 1 ) ;
F_84 ( V_250 ,
& V_126 -> V_47 . V_132 -> V_155 ) ;
}
goto V_251;
}
if ( F_140 ( V_256 , V_126 ) ) {
if ( F_138 ( V_126 ) ) {
F_142 ( V_126 -> V_127 , 0 ) ;
F_86 ( V_250 ,
& V_126 -> V_47 . V_132 -> V_155 ) ;
}
goto V_251;
}
F_62 ( V_257 , & V_126 -> V_258 ) ;
return 0 ;
}
long F_143 ( struct V_125 * V_126 , T_4 V_259 , int V_260 )
{
return F_144 ( V_126 -> V_47 . V_46 , V_259 ,
V_260 ? V_261 : 0 ) ;
}
static void F_145 ( struct V_125 * V_126 , bool V_262 ,
unsigned long V_263 )
{
struct V_83 V_264 ;
V_264 . V_265 = V_263 ;
if ( V_262 ) {
V_264 . type = V_266 ;
F_101 ( F_146 ( V_126 , & V_264 ) ) ;
} else {
V_264 . type = V_267 ;
F_101 ( F_37 ( V_126 -> V_15 , & V_264 ) ) ;
}
}
void F_147 ( struct V_125 * V_126 ,
struct V_268 * V_269 )
{
F_148 ( V_126 , V_269 -> V_47 . V_136 ) ;
F_145 ( V_126 , true , V_269 -> V_47 . V_136 ) ;
}
void F_149 ( struct V_125 * V_126 ,
struct V_268 * V_269 )
{
F_150 ( V_126 , V_269 -> V_47 . V_136 ) ;
F_145 ( V_126 , false , V_269 -> V_47 . V_136 ) ;
}
void F_151 ( struct V_125 * V_126 ,
struct V_268 * V_269 )
{
}
bool F_152 ( struct V_125 * V_126 )
{
return true ;
}
static int F_153 ( struct V_125 * V_126 )
{
T_5 V_270 ;
struct V_271 V_47 ;
int V_102 ;
if ( V_126 -> V_47 . V_136 == V_137 )
return 0 ;
if ( ( V_126 -> V_47 . V_132 -> V_156 . V_157 & V_126 -> V_47 . V_216 ) !=
V_126 -> V_47 . V_214 )
return 0 ;
if ( F_154 ( V_126 ) )
return 0 ;
if ( F_107 ( V_126 ) )
return 0 ;
if ( ! ( V_126 -> V_47 . V_132 -> V_162 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_126 -> V_47 . V_46 -> V_122 )
return 0 ;
V_270 = F_155 ( V_126 -> V_15 , F_156 ( V_111 -> V_272 . V_273 ) ) ;
V_270 += V_111 -> V_272 . V_273 & ~ V_274 ;
if ( F_157 ( V_126 , V_126 -> V_47 . V_136 , & V_47 . V_136 , 8 ) )
return 0 ;
V_102 = F_158 ( V_126 , V_111 -> V_272 . V_273 , V_270 , & V_47 ) ;
return V_102 ;
}
static int F_159 ( struct V_125 * V_126 )
{
int V_102 , V_155 ;
F_160 ( V_126 ) ;
memcpy ( & V_126 -> V_47 . V_132 -> V_275 , & V_126 -> V_138 -> V_151 . V_152 . V_220 [ 14 ] , 16 ) ;
if ( F_161 () )
F_162 () ;
if ( F_163 ( V_276 ) )
F_164 () ;
if ( ! F_61 ( V_126 -> V_15 ) ) {
V_102 = F_165 ( V_126 ) ;
if ( V_102 )
return V_102 ;
}
V_102 = F_139 ( V_126 ) ;
if ( V_102 )
return V_102 ;
if ( F_166 ( V_126 ) ) {
F_167 ( V_126 ) ;
F_168 ( V_126 ) ;
}
V_126 -> V_47 . V_132 -> V_277 = 0 ;
V_155 = F_28 ( & V_126 -> V_47 . V_132 -> V_155 ) ;
F_57 ( V_126 , 6 , L_7 , V_155 ) ;
F_169 ( V_126 , V_155 ) ;
return 0 ;
}
static int F_170 ( struct V_125 * V_126 , int V_278 )
{
int V_102 = - 1 ;
F_57 ( V_126 , 6 , L_8 ,
V_126 -> V_47 . V_132 -> V_277 ) ;
F_171 ( V_126 , V_126 -> V_47 . V_132 -> V_277 ) ;
if ( F_166 ( V_126 ) )
F_172 ( V_126 ) ;
if ( V_278 >= 0 ) {
V_102 = 0 ;
} else if ( F_61 ( V_126 -> V_15 ) ) {
V_126 -> V_138 -> V_278 = V_279 ;
V_126 -> V_138 -> V_280 . V_281 =
V_111 -> V_272 . V_273 ;
V_126 -> V_138 -> V_280 . V_282 = 0x10 ;
V_102 = - V_283 ;
} else if ( V_111 -> V_272 . V_284 ) {
F_173 ( V_126 ) ;
V_111 -> V_272 . V_284 = 0 ;
if ( F_153 ( V_126 ) ) {
V_102 = 0 ;
} else {
T_4 V_259 = V_111 -> V_272 . V_273 ;
V_102 = F_143 ( V_126 , V_259 , 1 ) ;
}
}
if ( V_102 == - 1 ) {
F_57 ( V_126 , 3 , L_2 , L_9 ) ;
F_174 ( V_126 ) ;
V_102 = F_175 ( V_126 , V_285 ) ;
}
memcpy ( & V_126 -> V_138 -> V_151 . V_152 . V_220 [ 14 ] , & V_126 -> V_47 . V_132 -> V_275 , 16 ) ;
if ( V_102 == 0 ) {
if ( F_61 ( V_126 -> V_15 ) )
V_102 = V_126 -> V_47 . V_132 -> V_277 ? - V_286 : 0 ;
else
V_102 = F_176 ( V_126 ) ;
}
return V_102 ;
}
static int F_177 ( struct V_125 * V_126 )
{
int V_102 , V_278 ;
V_126 -> V_287 = F_29 ( & V_126 -> V_15 -> V_75 ) ;
do {
V_102 = F_159 ( V_126 ) ;
if ( V_102 )
break;
F_31 ( & V_126 -> V_15 -> V_75 , V_126 -> V_287 ) ;
F_178 () ;
F_179 () ;
F_180 () ;
V_278 = F_181 ( V_126 -> V_47 . V_132 ,
V_126 -> V_138 -> V_151 . V_152 . V_220 ) ;
F_182 () ;
V_126 -> V_287 = F_29 ( & V_126 -> V_15 -> V_75 ) ;
V_102 = F_170 ( V_126 , V_278 ) ;
} while ( ! F_183 ( V_111 ) && ! F_184 ( V_126 ) && ! V_102 );
F_31 ( & V_126 -> V_15 -> V_75 , V_126 -> V_287 ) ;
return V_102 ;
}
static void F_185 ( struct V_125 * V_126 , struct V_288 * V_288 )
{
V_126 -> V_47 . V_132 -> V_156 . V_157 = V_288 -> V_227 ;
V_126 -> V_47 . V_132 -> V_156 . V_158 = V_288 -> V_228 ;
if ( V_288 -> V_289 & V_140 )
F_89 ( V_126 , V_288 -> V_151 . V_152 . V_290 ) ;
if ( V_288 -> V_289 & V_143 ) {
memcpy ( & V_126 -> V_47 . V_132 -> V_162 , & V_288 -> V_151 . V_152 . V_223 , 128 ) ;
F_114 ( V_253 , V_126 ) ;
}
if ( V_288 -> V_289 & V_144 ) {
V_126 -> V_47 . V_132 -> V_159 = V_288 -> V_151 . V_152 . V_159 ;
V_126 -> V_47 . V_132 -> V_160 = V_288 -> V_151 . V_152 . V_160 ;
V_126 -> V_47 . V_132 -> V_161 = V_288 -> V_151 . V_152 . V_161 ;
V_126 -> V_47 . V_132 -> V_164 = V_288 -> V_151 . V_152 . V_164 ;
V_126 -> V_47 . V_132 -> V_163 = V_288 -> V_151 . V_152 . V_163 ;
}
if ( V_288 -> V_289 & V_145 ) {
V_126 -> V_47 . V_136 = V_288 -> V_151 . V_152 . V_291 ;
V_126 -> V_47 . V_216 = V_288 -> V_151 . V_152 . V_292 ;
V_126 -> V_47 . V_214 = V_288 -> V_151 . V_152 . V_293 ;
}
V_288 -> V_289 = 0 ;
}
static void F_186 ( struct V_125 * V_126 , struct V_288 * V_288 )
{
V_288 -> V_227 = V_126 -> V_47 . V_132 -> V_156 . V_157 ;
V_288 -> V_228 = V_126 -> V_47 . V_132 -> V_156 . V_158 ;
V_288 -> V_151 . V_152 . V_290 = F_113 ( V_126 ) ;
memcpy ( & V_288 -> V_151 . V_152 . V_223 , & V_126 -> V_47 . V_132 -> V_162 , 128 ) ;
V_288 -> V_151 . V_152 . V_159 = V_126 -> V_47 . V_132 -> V_159 ;
V_288 -> V_151 . V_152 . V_160 = V_126 -> V_47 . V_132 -> V_160 ;
V_288 -> V_151 . V_152 . V_161 = V_126 -> V_47 . V_132 -> V_161 ;
V_288 -> V_151 . V_152 . V_164 = V_126 -> V_47 . V_132 -> V_164 ;
V_288 -> V_151 . V_152 . V_163 = V_126 -> V_47 . V_132 -> V_163 ;
V_288 -> V_151 . V_152 . V_291 = V_126 -> V_47 . V_136 ;
V_288 -> V_151 . V_152 . V_292 = V_126 -> V_47 . V_216 ;
V_288 -> V_151 . V_152 . V_293 = V_126 -> V_47 . V_214 ;
}
int F_187 ( struct V_125 * V_126 , struct V_288 * V_288 )
{
int V_102 ;
T_6 V_294 ;
if ( F_184 ( V_126 ) ) {
F_188 ( V_126 ) ;
return 0 ;
}
if ( V_126 -> V_295 )
F_189 ( V_296 , & V_126 -> V_297 , & V_294 ) ;
if ( ! F_90 ( V_126 -> V_15 ) ) {
F_137 ( V_126 ) ;
} else if ( F_130 ( V_126 ) ) {
F_190 ( L_10 ,
V_126 -> V_127 ) ;
return - V_14 ;
}
F_185 ( V_126 , V_288 ) ;
F_191 () ;
V_102 = F_177 ( V_126 ) ;
if ( F_183 ( V_111 ) && ! V_102 ) {
V_288 -> V_278 = V_298 ;
V_102 = - V_299 ;
}
if ( F_184 ( V_126 ) && ! V_102 ) {
F_188 ( V_126 ) ;
V_102 = 0 ;
}
if ( V_102 == - V_286 ) {
V_288 -> V_278 = V_300 ;
V_288 -> V_301 . V_277 = V_126 -> V_47 . V_132 -> V_277 ;
V_288 -> V_301 . V_302 = V_126 -> V_47 . V_132 -> V_302 ;
V_288 -> V_301 . V_303 = V_126 -> V_47 . V_132 -> V_303 ;
V_102 = 0 ;
}
if ( V_102 == - V_283 ) {
V_102 = 0 ;
}
F_186 ( V_126 , V_288 ) ;
if ( V_126 -> V_295 )
F_189 ( V_296 , & V_294 , NULL ) ;
V_126 -> V_304 . V_305 ++ ;
return V_102 ;
}
int F_192 ( struct V_125 * V_126 , unsigned long V_259 )
{
unsigned char V_306 = 1 ;
unsigned int V_307 ;
V_209 V_308 ;
int V_102 ;
if ( V_259 == V_309 ) {
if ( F_193 ( V_126 , 163 , & V_306 , 1 ) )
return - V_85 ;
V_259 = V_310 ;
} else if ( V_259 == V_311 ) {
if ( F_194 ( V_126 , 163 , & V_306 , 1 ) )
return - V_85 ;
V_259 = F_195 ( V_126 , V_310 ) ;
}
V_102 = F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_313 ) ,
V_126 -> V_47 . V_150 . V_148 , 128 ) ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_314 ) ,
V_126 -> V_138 -> V_151 . V_152 . V_220 , 128 ) ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_226 ) ,
& V_126 -> V_47 . V_132 -> V_156 , 16 ) ;
V_307 = F_113 ( V_126 ) ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_315 ) ,
& V_307 , 4 ) ;
V_102 |= F_193 ( V_126 ,
V_259 + F_196 ( struct V_312 , V_316 ) ,
& V_126 -> V_47 . V_150 . V_147 , 4 ) ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_317 ) ,
& V_126 -> V_47 . V_132 -> V_161 , 4 ) ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_318 ) ,
& V_126 -> V_47 . V_132 -> V_159 , 8 ) ;
V_308 = V_126 -> V_47 . V_132 -> V_160 >> 8 ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_319 ) ,
& V_308 , 8 ) ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_320 ) ,
& V_126 -> V_138 -> V_151 . V_152 . V_153 , 64 ) ;
V_102 |= F_193 ( V_126 , V_259 + F_196 ( struct V_312 , V_321 ) ,
& V_126 -> V_47 . V_132 -> V_162 , 128 ) ;
return V_102 ? - V_85 : 0 ;
}
int F_197 ( struct V_125 * V_126 , unsigned long V_158 )
{
F_77 ( & V_126 -> V_47 . V_150 . V_147 ) ;
F_78 ( V_126 -> V_47 . V_150 . V_148 ) ;
F_79 ( V_126 -> V_138 -> V_151 . V_152 . V_153 ) ;
return F_192 ( V_126 , V_158 ) ;
}
static void F_198 ( struct V_125 * V_126 )
{
F_140 ( V_255 , V_126 ) ;
F_114 ( V_256 , V_126 ) ;
F_112 ( V_126 ) ;
}
static void F_199 ( struct V_15 * V_15 )
{
unsigned int V_134 ;
struct V_125 * V_126 ;
F_70 (i, vcpu, kvm) {
F_198 ( V_126 ) ;
}
}
static void F_200 ( struct V_125 * V_126 )
{
F_140 ( V_256 , V_126 ) ;
F_114 ( V_255 , V_126 ) ;
F_112 ( V_126 ) ;
}
void F_137 ( struct V_125 * V_126 )
{
int V_134 , V_72 , V_322 = 0 ;
if ( ! F_130 ( V_126 ) )
return;
F_201 ( V_126 -> V_127 , 1 ) ;
F_44 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
V_72 = F_28 ( & V_126 -> V_15 -> V_72 ) ;
for ( V_134 = 0 ; V_134 < V_72 ; V_134 ++ ) {
if ( ! F_130 ( V_126 -> V_15 -> V_135 [ V_134 ] ) )
V_322 ++ ;
}
if ( V_322 == 0 ) {
F_200 ( V_126 ) ;
} else if ( V_322 == 1 ) {
F_199 ( V_126 -> V_15 ) ;
}
F_86 ( V_169 , & V_126 -> V_47 . V_132 -> V_155 ) ;
F_114 ( V_253 , V_126 ) ;
F_45 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
return;
}
void F_91 ( struct V_125 * V_126 )
{
int V_134 , V_72 , V_322 = 0 ;
struct V_125 * V_323 = NULL ;
if ( F_130 ( V_126 ) )
return;
F_201 ( V_126 -> V_127 , 0 ) ;
F_44 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
V_72 = F_28 ( & V_126 -> V_15 -> V_72 ) ;
F_44 ( & V_126 -> V_47 . V_194 . V_71 ) ;
F_84 ( V_169 , & V_126 -> V_47 . V_132 -> V_155 ) ;
V_126 -> V_47 . V_194 . V_324 &=
~ ( V_325 | V_326 ) ;
F_45 ( & V_126 -> V_47 . V_194 . V_71 ) ;
F_198 ( V_126 ) ;
for ( V_134 = 0 ; V_134 < V_72 ; V_134 ++ ) {
if ( ! F_130 ( V_126 -> V_15 -> V_135 [ V_134 ] ) ) {
V_322 ++ ;
V_323 = V_126 -> V_15 -> V_135 [ V_134 ] ;
}
}
if ( V_322 == 1 ) {
F_200 ( V_323 ) ;
}
F_45 ( & V_126 -> V_15 -> V_47 . V_124 ) ;
return;
}
static int F_202 ( struct V_125 * V_126 ,
struct V_61 * V_62 )
{
int V_17 ;
if ( V_62 -> V_63 )
return - V_14 ;
switch ( V_62 -> V_62 ) {
case V_26 :
if ( ! V_126 -> V_15 -> V_47 . V_123 ) {
V_126 -> V_15 -> V_47 . V_123 = 1 ;
F_203 ( V_126 -> V_15 ) ;
}
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
long F_204 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_125 * V_126 = V_10 -> V_80 ;
void T_2 * V_81 = ( void T_2 * ) V_12 ;
int V_68 ;
long V_17 ;
switch ( V_11 ) {
case V_82 : {
struct V_83 V_84 ;
V_17 = - V_85 ;
if ( F_36 ( & V_84 , V_81 , sizeof( V_84 ) ) )
break;
V_17 = F_146 ( V_126 , & V_84 ) ;
break;
}
case V_327 :
V_68 = F_29 ( & V_126 -> V_15 -> V_75 ) ;
V_17 = F_197 ( V_126 , V_12 ) ;
F_31 ( & V_126 -> V_15 -> V_75 , V_68 ) ;
break;
case V_328 : {
T_3 V_226 ;
V_17 = - V_85 ;
if ( F_36 ( & V_226 , V_81 , sizeof( V_226 ) ) )
break;
V_17 = F_129 ( V_126 , V_226 ) ;
break;
}
case V_329 :
V_17 = F_121 ( V_126 ) ;
break;
case V_330 :
case V_331 : {
struct V_203 V_204 ;
V_17 = - V_85 ;
if ( F_36 ( & V_204 , V_81 , sizeof( V_204 ) ) )
break;
if ( V_11 == V_330 )
V_17 = F_119 ( V_126 , & V_204 ) ;
else
V_17 = F_117 ( V_126 , & V_204 ) ;
break;
}
#ifdef F_13
case V_332 : {
struct V_333 V_334 ;
if ( F_36 ( & V_334 , V_81 , sizeof( V_334 ) ) ) {
V_17 = - V_85 ;
break;
}
if ( ! F_61 ( V_126 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_205 ( V_126 -> V_47 . V_46 , V_334 . V_335 ,
V_334 . V_336 , V_334 . V_337 ) ;
break;
}
case V_338 : {
struct V_333 V_334 ;
if ( F_36 ( & V_334 , V_81 , sizeof( V_334 ) ) ) {
V_17 = - V_85 ;
break;
}
if ( ! F_61 ( V_126 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_206 ( V_126 -> V_47 . V_46 , V_334 . V_336 ,
V_334 . V_337 ) ;
break;
}
#endif
case V_339 : {
V_17 = F_144 ( V_126 -> V_47 . V_46 , V_12 , 0 ) ;
break;
}
case V_86 :
{
struct V_61 V_62 ;
V_17 = - V_85 ;
if ( F_36 ( & V_62 , V_81 , sizeof( V_62 ) ) )
break;
V_17 = F_202 ( V_126 , & V_62 ) ;
break;
}
default:
V_17 = - V_93 ;
}
return V_17 ;
}
int F_207 ( struct V_125 * V_126 , struct V_340 * V_341 )
{
#ifdef F_13
if ( ( V_341 -> V_342 == V_343 )
&& ( F_61 ( V_126 -> V_15 ) ) ) {
V_341 -> V_344 = F_208 ( V_126 -> V_47 . V_132 ) ;
F_209 ( V_341 -> V_344 ) ;
return 0 ;
}
#endif
return V_345 ;
}
int F_210 ( struct V_15 * V_15 , struct V_41 * V_56 ,
unsigned long V_51 )
{
return 0 ;
}
int F_211 ( struct V_15 * V_15 ,
struct V_41 * V_42 ,
struct V_346 * V_347 ,
enum V_348 V_349 )
{
if ( V_347 -> V_350 & 0xffffful )
return - V_14 ;
if ( V_347 -> V_351 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_212 ( struct V_15 * V_15 ,
struct V_346 * V_347 ,
const struct V_41 * V_352 ,
enum V_348 V_349 )
{
int V_102 ;
if ( V_352 -> V_350 == V_347 -> V_350 &&
V_352 -> V_50 * V_252 == V_347 -> V_353 &&
V_352 -> V_51 * V_252 == V_347 -> V_351 )
return;
V_102 = F_205 ( V_15 -> V_47 . V_46 , V_347 -> V_350 ,
V_347 -> V_353 , V_347 -> V_351 ) ;
if ( V_102 )
F_213 ( V_354 L_11 ) ;
return;
}
static int T_7 F_214 ( void )
{
int V_67 ;
V_67 = F_215 ( NULL , sizeof( struct V_125 ) , 0 , V_355 ) ;
if ( V_67 )
return V_67 ;
V_2 = ( unsigned long * ) F_43 ( V_96 | V_97 ) ;
if ( ! V_2 ) {
F_216 () ;
return - V_98 ;
}
memcpy ( V_2 , V_356 . V_357 , 16 ) ;
V_2 [ 0 ] &= 0xff82fffbf47c2000UL ;
V_2 [ 1 ] &= 0x005c000000000000UL ;
return 0 ;
}
static void T_8 F_217 ( void )
{
F_55 ( ( unsigned long ) V_2 ) ;
F_216 () ;
}
