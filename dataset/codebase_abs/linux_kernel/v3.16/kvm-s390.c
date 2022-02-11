int F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 , ( void * ) V_2 ) ;
}
int F_3 ( void * V_3 )
{
return 0 ;
}
void F_4 ( void * V_3 )
{
}
int F_5 ( void )
{
V_4 . V_5 = V_6 ;
F_6 ( & V_4 ) ;
return 0 ;
}
void F_7 ( void )
{
F_8 ( & V_4 ) ;
}
void F_9 ( void * V_7 )
{
}
int F_10 ( void * V_8 )
{
return 0 ;
}
void F_11 ( void )
{
}
long F_12 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
if ( V_11 == V_13 )
return F_13 () ;
return - V_14 ;
}
int F_14 ( long V_15 )
{
int V_16 ;
switch ( V_15 ) {
case V_17 :
case V_18 :
case V_19 :
#ifdef F_15
case V_20 :
#endif
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_16 = 1 ;
break;
case V_31 :
case V_32 :
V_16 = V_33 ;
break;
case V_34 :
V_16 = V_35 ;
break;
case V_36 :
V_16 = V_37 ;
break;
default:
V_16 = 0 ;
}
return V_16 ;
}
static void F_16 ( struct V_38 * V_38 ,
struct V_39 * V_40 )
{
T_1 V_41 , V_42 ;
unsigned long V_43 ;
struct V_44 * V_44 = V_38 -> V_45 . V_44 ;
F_17 ( & V_44 -> V_46 -> V_47 ) ;
V_42 = V_40 -> V_48 + V_40 -> V_49 ;
for ( V_41 = V_40 -> V_48 ; V_41 <= V_42 ; V_41 ++ ) {
V_43 = F_18 ( V_40 , V_41 ) ;
if ( F_19 ( V_43 , V_44 ) )
F_20 ( V_38 , V_41 ) ;
}
F_21 ( & V_44 -> V_46 -> V_47 ) ;
}
int F_22 ( struct V_38 * V_38 ,
struct V_50 * log )
{
int V_16 ;
unsigned long V_51 ;
struct V_39 * V_40 ;
int V_52 = 0 ;
F_23 ( & V_38 -> V_53 ) ;
V_16 = - V_14 ;
if ( log -> V_54 >= V_35 )
goto V_55;
V_40 = F_24 ( V_38 -> V_56 , log -> V_54 ) ;
V_16 = - V_57 ;
if ( ! V_40 -> V_58 )
goto V_55;
F_16 ( V_38 , V_40 ) ;
V_16 = F_25 ( V_38 , log , & V_52 ) ;
if ( V_16 )
goto V_55;
if ( V_52 ) {
V_51 = F_26 ( V_40 ) ;
memset ( V_40 -> V_58 , 0 , V_51 ) ;
}
V_16 = 0 ;
V_55:
F_27 ( & V_38 -> V_53 ) ;
return V_16 ;
}
static int F_28 ( struct V_38 * V_38 , struct V_59 * V_60 )
{
int V_16 ;
if ( V_60 -> V_61 )
return - V_14 ;
switch ( V_60 -> V_60 ) {
case V_62 :
V_38 -> V_45 . V_63 = 1 ;
V_16 = 0 ;
break;
default:
V_16 = - V_14 ;
break;
}
return V_16 ;
}
static int F_29 ( struct V_38 * V_38 , struct V_64 * V_65 )
{
int V_66 ;
unsigned int V_67 ;
switch ( V_65 -> V_65 ) {
case V_68 :
V_66 = - V_69 ;
F_23 ( & V_38 -> V_70 ) ;
if ( F_30 ( & V_38 -> V_71 ) == 0 ) {
V_38 -> V_45 . V_72 = 1 ;
V_66 = 0 ;
}
F_27 ( & V_38 -> V_70 ) ;
break;
case V_73 :
F_23 ( & V_38 -> V_70 ) ;
V_67 = F_31 ( & V_38 -> V_74 ) ;
F_32 ( V_38 -> V_45 . V_44 -> V_46 , 0 , V_75 , false ) ;
F_33 ( & V_38 -> V_74 , V_67 ) ;
F_27 ( & V_38 -> V_70 ) ;
V_66 = 0 ;
break;
default:
V_66 = - V_76 ;
break;
}
return V_66 ;
}
static int F_34 ( struct V_38 * V_38 , struct V_64 * V_65 )
{
int V_66 ;
switch ( V_65 -> V_77 ) {
case V_78 :
V_66 = F_29 ( V_38 , V_65 ) ;
break;
default:
V_66 = - V_76 ;
break;
}
return V_66 ;
}
static int F_35 ( struct V_38 * V_38 , struct V_64 * V_65 )
{
return - V_76 ;
}
static int F_36 ( struct V_38 * V_38 , struct V_64 * V_65 )
{
int V_66 ;
switch ( V_65 -> V_77 ) {
case V_78 :
switch ( V_65 -> V_65 ) {
case V_68 :
case V_73 :
V_66 = 0 ;
break;
default:
V_66 = - V_76 ;
break;
}
break;
default:
V_66 = - V_76 ;
break;
}
return V_66 ;
}
long F_37 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_38 * V_38 = V_10 -> V_79 ;
void T_2 * V_80 = ( void T_2 * ) V_12 ;
struct V_64 V_65 ;
int V_16 ;
switch ( V_11 ) {
case V_81 : {
struct V_82 V_83 ;
V_16 = - V_84 ;
if ( F_38 ( & V_83 , V_80 , sizeof( V_83 ) ) )
break;
V_16 = F_39 ( V_38 , & V_83 ) ;
break;
}
case V_85 : {
struct V_59 V_60 ;
V_16 = - V_84 ;
if ( F_38 ( & V_60 , V_80 , sizeof( V_60 ) ) )
break;
V_16 = F_28 ( V_38 , & V_60 ) ;
break;
}
case V_86 : {
struct V_87 V_88 ;
V_16 = - V_14 ;
if ( V_38 -> V_45 . V_63 ) {
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
F_40 ( V_38 , & V_88 , 0 , 0 ) ;
V_16 = 0 ;
}
break;
}
case V_89 : {
V_16 = - V_84 ;
if ( F_38 ( & V_65 , ( void T_2 * ) V_12 , sizeof( V_65 ) ) )
break;
V_16 = F_34 ( V_38 , & V_65 ) ;
break;
}
case V_90 : {
V_16 = - V_84 ;
if ( F_38 ( & V_65 , ( void T_2 * ) V_12 , sizeof( V_65 ) ) )
break;
V_16 = F_35 ( V_38 , & V_65 ) ;
break;
}
case V_91 : {
V_16 = - V_84 ;
if ( F_38 ( & V_65 , ( void T_2 * ) V_12 , sizeof( V_65 ) ) )
break;
V_16 = F_36 ( V_38 , & V_65 ) ;
break;
}
default:
V_16 = - V_92 ;
}
return V_16 ;
}
int F_41 ( struct V_38 * V_38 , unsigned long type )
{
int V_93 ;
char V_94 [ 16 ] ;
static unsigned long V_95 ;
V_93 = - V_14 ;
#ifdef F_15
if ( type & ~ V_96 )
goto V_97;
if ( ( type & V_96 ) && ( ! F_42 ( V_98 ) ) )
goto V_97;
#else
if ( type )
goto V_97;
#endif
V_93 = F_13 () ;
if ( V_93 )
goto V_97;
V_93 = - V_99 ;
V_38 -> V_45 . V_100 = (struct V_101 * ) F_43 ( V_102 ) ;
if ( ! V_38 -> V_45 . V_100 )
goto V_97;
F_44 ( & V_103 ) ;
V_95 = ( V_95 + 16 ) & 0x7f0 ;
V_38 -> V_45 . V_100 = (struct V_101 * ) ( ( char * ) V_38 -> V_45 . V_100 + V_95 ) ;
F_45 ( & V_103 ) ;
sprintf ( V_94 , L_1 , V_104 -> V_105 ) ;
V_38 -> V_45 . V_106 = F_46 ( V_94 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_38 -> V_45 . V_106 )
goto V_107;
F_47 ( & V_38 -> V_45 . V_108 . V_70 ) ;
F_48 ( & V_38 -> V_45 . V_108 . V_109 ) ;
F_49 ( & V_38 -> V_45 . V_110 ) ;
F_50 ( V_38 -> V_45 . V_106 , & V_111 ) ;
F_51 ( V_38 , 3 , L_2 , L_3 ) ;
if ( type & V_96 ) {
V_38 -> V_45 . V_44 = NULL ;
} else {
V_38 -> V_45 . V_44 = F_52 ( V_104 -> V_46 ) ;
if ( ! V_38 -> V_45 . V_44 )
goto V_112;
V_38 -> V_45 . V_44 -> V_113 = V_38 ;
V_38 -> V_45 . V_44 -> V_114 = 0 ;
}
V_38 -> V_45 . V_115 = 0 ;
V_38 -> V_45 . V_63 = 0 ;
F_47 ( & V_38 -> V_45 . V_116 ) ;
return 0 ;
V_112:
F_53 ( V_38 -> V_45 . V_106 ) ;
V_107:
F_54 ( ( unsigned long ) ( V_38 -> V_45 . V_100 ) ) ;
V_97:
return V_93 ;
}
void F_55 ( struct V_117 * V_118 )
{
F_56 ( V_118 , 3 , L_2 , L_4 ) ;
F_57 ( V_118 -> V_119 ) ;
F_58 ( V_118 ) ;
F_59 ( V_118 ) ;
if ( ! F_60 ( V_118 -> V_38 ) ) {
F_61 ( 63 - V_118 -> V_119 ,
( unsigned long * ) & V_118 -> V_38 -> V_45 . V_100 -> V_120 ) ;
if ( V_118 -> V_38 -> V_45 . V_100 -> V_121 [ V_118 -> V_119 ] . V_122 ==
( V_123 ) V_118 -> V_45 . V_124 )
V_118 -> V_38 -> V_45 . V_100 -> V_121 [ V_118 -> V_119 ] . V_122 = 0 ;
}
F_62 () ;
if ( F_60 ( V_118 -> V_38 ) )
F_63 ( V_118 -> V_45 . V_44 ) ;
if ( F_64 ( V_118 -> V_38 ) )
F_65 ( V_118 ) ;
F_54 ( ( unsigned long ) ( V_118 -> V_45 . V_124 ) ) ;
F_66 ( V_118 ) ;
F_67 ( V_125 , V_118 ) ;
}
static void F_68 ( struct V_38 * V_38 )
{
unsigned int V_126 ;
struct V_117 * V_118 ;
F_69 (i, vcpu, kvm)
F_55 ( V_118 ) ;
F_23 ( & V_38 -> V_70 ) ;
for ( V_126 = 0 ; V_126 < F_30 ( & V_38 -> V_71 ) ; V_126 ++ )
V_38 -> V_127 [ V_126 ] = NULL ;
F_70 ( & V_38 -> V_71 , 0 ) ;
F_27 ( & V_38 -> V_70 ) ;
}
void F_71 ( struct V_38 * V_38 )
{
}
void F_72 ( struct V_38 * V_38 )
{
F_68 ( V_38 ) ;
F_54 ( ( unsigned long ) ( V_38 -> V_45 . V_100 ) ) ;
F_53 ( V_38 -> V_45 . V_106 ) ;
if ( ! F_60 ( V_38 ) )
F_63 ( V_38 -> V_45 . V_44 ) ;
F_73 ( V_38 ) ;
F_74 ( V_38 ) ;
}
int F_75 ( struct V_117 * V_118 )
{
V_118 -> V_45 . V_128 = V_129 ;
F_59 ( V_118 ) ;
if ( F_60 ( V_118 -> V_38 ) ) {
V_118 -> V_45 . V_44 = F_52 ( V_104 -> V_46 ) ;
if ( ! V_118 -> V_45 . V_44 )
return - V_99 ;
V_118 -> V_45 . V_44 -> V_113 = V_118 -> V_38 ;
return 0 ;
}
V_118 -> V_45 . V_44 = V_118 -> V_38 -> V_45 . V_44 ;
V_118 -> V_130 -> V_131 = V_132 |
V_133 |
V_134 |
V_135 ;
return 0 ;
}
void F_76 ( struct V_117 * V_118 )
{
}
void F_77 ( struct V_117 * V_118 , int V_121 )
{
F_78 ( & V_118 -> V_45 . V_136 . V_137 ) ;
F_79 ( V_118 -> V_45 . V_136 . V_138 ) ;
F_80 ( V_118 -> V_45 . V_139 ) ;
F_81 ( & V_118 -> V_45 . V_140 . V_137 ) ;
F_82 ( V_118 -> V_45 . V_140 . V_138 ) ;
F_83 ( V_118 -> V_130 -> V_141 . V_142 . V_143 ) ;
F_84 ( V_118 -> V_45 . V_44 ) ;
F_85 ( V_144 , & V_118 -> V_45 . V_124 -> V_145 ) ;
}
void F_86 ( struct V_117 * V_118 )
{
F_87 ( V_144 , & V_118 -> V_45 . V_124 -> V_145 ) ;
F_88 ( V_118 -> V_45 . V_44 ) ;
F_78 ( & V_118 -> V_45 . V_140 . V_137 ) ;
F_79 ( V_118 -> V_45 . V_140 . V_138 ) ;
F_80 ( V_118 -> V_130 -> V_141 . V_142 . V_143 ) ;
F_81 ( & V_118 -> V_45 . V_136 . V_137 ) ;
F_82 ( V_118 -> V_45 . V_136 . V_138 ) ;
F_83 ( V_118 -> V_45 . V_139 ) ;
}
static void F_89 ( struct V_117 * V_118 )
{
V_118 -> V_45 . V_124 -> V_146 . V_147 = 0UL ;
V_118 -> V_45 . V_124 -> V_146 . V_148 = 0UL ;
F_90 ( V_118 , 0 ) ;
V_118 -> V_45 . V_124 -> V_149 = 0UL ;
V_118 -> V_45 . V_124 -> V_150 = 0UL ;
V_118 -> V_45 . V_124 -> V_151 = 0 ;
memset ( V_118 -> V_45 . V_124 -> V_152 , 0 , 16 * sizeof( V_123 ) ) ;
V_118 -> V_45 . V_124 -> V_152 [ 0 ] = 0xE0UL ;
V_118 -> V_45 . V_124 -> V_152 [ 14 ] = 0xC2000000UL ;
V_118 -> V_45 . V_140 . V_137 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_118 -> V_45 . V_124 -> V_153 = 1 ;
V_118 -> V_45 . V_124 -> V_154 = 0 ;
V_118 -> V_45 . V_128 = V_129 ;
F_59 ( V_118 ) ;
F_91 ( V_118 ) ;
F_58 ( V_118 ) ;
}
int F_92 ( struct V_117 * V_118 )
{
return 0 ;
}
void F_65 ( struct V_117 * V_118 )
{
F_54 ( V_118 -> V_45 . V_124 -> V_155 ) ;
V_118 -> V_45 . V_124 -> V_155 = 0 ;
}
int F_93 ( struct V_117 * V_118 )
{
V_118 -> V_45 . V_124 -> V_155 = F_43 ( V_102 ) ;
if ( ! V_118 -> V_45 . V_124 -> V_155 )
return - V_99 ;
V_118 -> V_45 . V_124 -> V_156 |= 0x80 ;
V_118 -> V_45 . V_124 -> V_156 &= ~ 0x08 ;
return 0 ;
}
int F_94 ( struct V_117 * V_118 )
{
int V_93 = 0 ;
F_70 ( & V_118 -> V_45 . V_124 -> V_145 , V_157 |
V_158 |
V_159 |
V_160 ) ;
V_118 -> V_45 . V_124 -> V_161 = 6 ;
if ( F_1 ( 50 ) && F_1 ( 73 ) )
V_118 -> V_45 . V_124 -> V_161 |= 0x10 ;
V_118 -> V_45 . V_124 -> V_156 = 8 ;
V_118 -> V_45 . V_124 -> V_162 = 0xD1002000U ;
if ( F_95 () )
V_118 -> V_45 . V_124 -> V_162 |= 1 ;
V_118 -> V_45 . V_124 -> V_163 = ( int ) ( long ) V_2 ;
V_118 -> V_45 . V_124 -> V_164 |= V_165 | V_166 | V_167 |
V_168 ;
if ( F_64 ( V_118 -> V_38 ) ) {
V_93 = F_93 ( V_118 ) ;
if ( V_93 )
return V_93 ;
}
F_96 ( & V_118 -> V_45 . V_169 , V_170 , V_171 ) ;
F_97 ( & V_118 -> V_45 . V_172 , V_173 ,
( unsigned long ) V_118 ) ;
V_118 -> V_45 . V_169 . V_174 = V_175 ;
F_98 ( & V_118 -> V_45 . V_176 ) ;
V_118 -> V_45 . V_176 . V_177 = 0xff ;
return V_93 ;
}
struct V_117 * F_99 ( struct V_38 * V_38 ,
unsigned int V_178 )
{
struct V_117 * V_118 ;
struct V_179 * V_179 ;
int V_93 = - V_14 ;
if ( V_178 >= V_33 )
goto V_55;
V_93 = - V_99 ;
V_118 = F_100 ( V_125 , V_102 ) ;
if ( ! V_118 )
goto V_55;
V_179 = (struct V_179 * ) F_43 ( V_102 ) ;
if ( ! V_179 )
goto V_180;
V_118 -> V_45 . V_124 = & V_179 -> V_124 ;
V_118 -> V_45 . V_124 -> V_181 = ( unsigned long ) & V_179 -> V_182 ;
V_118 -> V_45 . V_124 -> V_183 = V_178 ;
if ( ! F_60 ( V_38 ) ) {
if ( ! V_38 -> V_45 . V_100 ) {
F_101 ( 1 ) ;
goto V_180;
}
if ( ! V_38 -> V_45 . V_100 -> V_121 [ V_178 ] . V_122 )
V_38 -> V_45 . V_100 -> V_121 [ V_178 ] . V_122 =
( V_123 ) V_118 -> V_45 . V_124 ;
V_118 -> V_45 . V_124 -> V_184 =
( V_185 ) ( ( ( V_123 ) V_38 -> V_45 . V_100 ) >> 32 ) ;
V_118 -> V_45 . V_124 -> V_186 = ( V_185 ) ( V_123 ) V_38 -> V_45 . V_100 ;
F_102 ( 63 - V_178 , ( unsigned long * ) & V_38 -> V_45 . V_100 -> V_120 ) ;
}
F_47 ( & V_118 -> V_45 . V_187 . V_70 ) ;
F_48 ( & V_118 -> V_45 . V_187 . V_109 ) ;
V_118 -> V_45 . V_187 . V_108 = & V_38 -> V_45 . V_108 ;
V_118 -> V_45 . V_187 . V_188 = & V_118 -> V_188 ;
V_118 -> V_45 . V_187 . V_145 = & V_118 -> V_45 . V_124 -> V_145 ;
V_93 = F_103 ( V_118 , V_38 , V_178 ) ;
if ( V_93 )
goto V_189;
F_51 ( V_38 , 3 , L_5 , V_178 , V_118 ,
V_118 -> V_45 . V_124 ) ;
F_104 ( V_178 , V_118 , V_118 -> V_45 . V_124 ) ;
return V_118 ;
V_189:
F_54 ( ( unsigned long ) ( V_118 -> V_45 . V_124 ) ) ;
V_180:
F_67 ( V_125 , V_118 ) ;
V_55:
return F_105 ( V_93 ) ;
}
int F_106 ( struct V_117 * V_118 )
{
return F_107 ( V_118 ) ;
}
void F_108 ( struct V_117 * V_118 )
{
F_85 ( V_190 , & V_118 -> V_45 . V_124 -> V_191 ) ;
}
void F_109 ( struct V_117 * V_118 )
{
F_87 ( V_190 , & V_118 -> V_45 . V_124 -> V_191 ) ;
}
void F_110 ( struct V_117 * V_118 )
{
F_85 ( V_192 , & V_118 -> V_45 . V_124 -> V_145 ) ;
while ( V_118 -> V_45 . V_124 -> V_193 & V_194 )
F_111 () ;
}
void F_112 ( struct V_117 * V_118 )
{
F_108 ( V_118 ) ;
F_110 ( V_118 ) ;
}
static void V_6 ( struct V_44 * V_44 , unsigned long V_43 )
{
int V_126 ;
struct V_38 * V_38 = V_44 -> V_113 ;
struct V_117 * V_118 ;
F_69 (i, vcpu, kvm) {
if ( F_113 ( V_118 ) == ( V_43 & ~ 0x1000UL ) ) {
F_56 ( V_118 , 2 , L_6 , V_43 ) ;
F_114 ( V_195 , V_118 ) ;
F_112 ( V_118 ) ;
}
}
}
int F_115 ( struct V_117 * V_118 )
{
F_116 () ;
return 0 ;
}
static int F_117 ( struct V_117 * V_118 ,
struct V_196 * V_197 )
{
int V_16 = - V_14 ;
switch ( V_197 -> V_178 ) {
case V_198 :
V_16 = F_118 ( V_118 -> V_45 . V_124 -> V_151 ,
( V_199 T_2 * ) V_197 -> V_148 ) ;
break;
case V_200 :
V_16 = F_118 ( V_118 -> V_45 . V_124 -> V_201 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_203 :
V_16 = F_118 ( V_118 -> V_45 . V_124 -> V_149 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_204 :
V_16 = F_118 ( V_118 -> V_45 . V_124 -> V_150 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_205 :
V_16 = F_118 ( V_118 -> V_45 . V_128 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_206 :
V_16 = F_118 ( V_118 -> V_45 . V_207 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_208 :
V_16 = F_118 ( V_118 -> V_45 . V_209 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_210 :
V_16 = F_118 ( V_118 -> V_45 . V_124 -> V_154 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_211 :
V_16 = F_118 ( V_118 -> V_45 . V_124 -> V_153 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_119 ( struct V_117 * V_118 ,
struct V_196 * V_197 )
{
int V_16 = - V_14 ;
switch ( V_197 -> V_178 ) {
case V_198 :
V_16 = F_120 ( V_118 -> V_45 . V_124 -> V_151 ,
( V_199 T_2 * ) V_197 -> V_148 ) ;
break;
case V_200 :
V_16 = F_120 ( V_118 -> V_45 . V_124 -> V_201 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_203 :
V_16 = F_120 ( V_118 -> V_45 . V_124 -> V_149 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_204 :
V_16 = F_120 ( V_118 -> V_45 . V_124 -> V_150 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_205 :
V_16 = F_120 ( V_118 -> V_45 . V_128 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_206 :
V_16 = F_120 ( V_118 -> V_45 . V_207 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_208 :
V_16 = F_120 ( V_118 -> V_45 . V_209 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_210 :
V_16 = F_120 ( V_118 -> V_45 . V_124 -> V_154 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
case V_211 :
V_16 = F_120 ( V_118 -> V_45 . V_124 -> V_153 ,
( V_202 T_2 * ) V_197 -> V_148 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_121 ( struct V_117 * V_118 )
{
F_89 ( V_118 ) ;
return 0 ;
}
int F_122 ( struct V_117 * V_118 , struct V_212 * V_142 )
{
memcpy ( & V_118 -> V_130 -> V_141 . V_142 . V_213 , & V_142 -> V_213 , sizeof( V_142 -> V_213 ) ) ;
return 0 ;
}
int F_123 ( struct V_117 * V_118 , struct V_212 * V_142 )
{
memcpy ( & V_142 -> V_213 , & V_118 -> V_130 -> V_141 . V_142 . V_213 , sizeof( V_142 -> V_213 ) ) ;
return 0 ;
}
int F_124 ( struct V_117 * V_118 ,
struct V_214 * V_215 )
{
memcpy ( & V_118 -> V_130 -> V_141 . V_142 . V_143 , & V_215 -> V_143 , sizeof( V_215 -> V_143 ) ) ;
memcpy ( & V_118 -> V_45 . V_124 -> V_152 , & V_215 -> V_216 , sizeof( V_215 -> V_216 ) ) ;
F_83 ( V_118 -> V_130 -> V_141 . V_142 . V_143 ) ;
return 0 ;
}
int F_125 ( struct V_117 * V_118 ,
struct V_214 * V_215 )
{
memcpy ( & V_215 -> V_143 , & V_118 -> V_130 -> V_141 . V_142 . V_143 , sizeof( V_215 -> V_143 ) ) ;
memcpy ( & V_215 -> V_216 , & V_118 -> V_45 . V_124 -> V_152 , sizeof( V_215 -> V_216 ) ) ;
return 0 ;
}
int F_126 ( struct V_117 * V_118 , struct V_217 * V_218 )
{
if ( F_127 ( V_218 -> V_137 ) )
return - V_14 ;
memcpy ( & V_118 -> V_45 . V_140 . V_138 , & V_218 -> V_138 , sizeof( V_218 -> V_138 ) ) ;
V_118 -> V_45 . V_140 . V_137 = V_218 -> V_137 ;
F_81 ( & V_118 -> V_45 . V_140 . V_137 ) ;
F_82 ( V_118 -> V_45 . V_140 . V_138 ) ;
return 0 ;
}
int F_128 ( struct V_117 * V_118 , struct V_217 * V_218 )
{
memcpy ( & V_218 -> V_138 , & V_118 -> V_45 . V_140 . V_138 , sizeof( V_218 -> V_138 ) ) ;
V_218 -> V_137 = V_118 -> V_45 . V_140 . V_137 ;
return 0 ;
}
static int F_129 ( struct V_117 * V_118 , T_3 V_219 )
{
int V_93 = 0 ;
if ( ! ( F_30 ( & V_118 -> V_45 . V_124 -> V_145 ) & V_159 ) )
V_93 = - V_69 ;
else {
V_118 -> V_130 -> V_220 = V_219 . V_147 ;
V_118 -> V_130 -> V_221 = V_219 . V_148 ;
}
return V_93 ;
}
int F_130 ( struct V_117 * V_118 ,
struct V_222 * V_223 )
{
return - V_14 ;
}
int F_131 ( struct V_117 * V_118 ,
struct V_224 * V_225 )
{
int V_93 = 0 ;
V_118 -> V_226 = 0 ;
F_132 ( V_118 ) ;
if ( V_225 -> V_227 & ~ V_228 )
return - V_14 ;
if ( V_225 -> V_227 & V_229 ) {
V_118 -> V_226 = V_225 -> V_227 ;
F_85 ( V_230 , & V_118 -> V_45 . V_124 -> V_145 ) ;
if ( V_225 -> V_227 & V_231 )
V_93 = F_133 ( V_118 , V_225 ) ;
} else {
F_87 ( V_230 , & V_118 -> V_45 . V_124 -> V_145 ) ;
V_118 -> V_45 . V_232 . V_233 = 0 ;
}
if ( V_93 ) {
V_118 -> V_226 = 0 ;
F_132 ( V_118 ) ;
F_87 ( V_230 , & V_118 -> V_45 . V_124 -> V_145 ) ;
}
return V_93 ;
}
int F_134 ( struct V_117 * V_118 ,
struct V_234 * V_235 )
{
return - V_14 ;
}
int F_135 ( struct V_117 * V_118 ,
struct V_234 * V_235 )
{
return - V_14 ;
}
bool F_64 ( struct V_38 * V_38 )
{
if ( ! V_236 )
return false ;
if ( ! V_237 )
return false ;
if ( ! V_38 -> V_45 . V_72 )
return false ;
return true ;
}
static bool F_136 ( struct V_117 * V_118 )
{
return F_30 ( & V_118 -> V_45 . V_124 -> V_145 ) & V_238 ;
}
static int F_137 ( struct V_117 * V_118 )
{
V_239:
F_109 ( V_118 ) ;
if ( F_138 ( V_195 , V_118 ) ) {
int V_93 ;
V_93 = F_139 ( V_118 -> V_45 . V_44 ,
F_113 ( V_118 ) ,
V_240 * 2 ) ;
if ( V_93 )
return V_93 ;
goto V_239;
}
if ( F_138 ( V_241 , V_118 ) ) {
if ( ! F_136 ( V_118 ) ) {
F_140 ( V_118 -> V_119 , 1 ) ;
F_85 ( V_238 ,
& V_118 -> V_45 . V_124 -> V_145 ) ;
}
goto V_239;
}
if ( F_138 ( V_242 , V_118 ) ) {
if ( F_136 ( V_118 ) ) {
F_140 ( V_118 -> V_119 , 0 ) ;
F_87 ( V_238 ,
& V_118 -> V_45 . V_124 -> V_145 ) ;
}
goto V_239;
}
return 0 ;
}
long F_141 ( struct V_117 * V_118 , T_4 V_243 , int V_244 )
{
struct V_245 * V_46 = V_104 -> V_46 ;
T_5 V_246 ;
long V_93 ;
V_246 = F_142 ( V_243 , V_118 -> V_45 . V_44 ) ;
if ( F_143 ( V_246 ) )
return ( long ) V_246 ;
F_17 ( & V_46 -> V_47 ) ;
V_93 = F_144 ( V_104 , V_46 , V_246 , 1 , V_244 , 0 , NULL , NULL ) ;
F_21 ( & V_46 -> V_47 ) ;
return V_93 < 0 ? V_93 : 0 ;
}
static void F_145 ( struct V_117 * V_118 , bool V_247 ,
unsigned long V_248 )
{
struct V_82 V_249 ;
V_249 . V_250 = V_248 ;
if ( V_247 ) {
V_249 . type = V_251 ;
F_101 ( F_146 ( V_118 , & V_249 ) ) ;
} else {
V_249 . type = V_252 ;
F_101 ( F_39 ( V_118 -> V_38 , & V_249 ) ) ;
}
}
void F_147 ( struct V_117 * V_118 ,
struct V_253 * V_254 )
{
F_148 ( V_118 , V_254 -> V_45 . V_128 ) ;
F_145 ( V_118 , true , V_254 -> V_45 . V_128 ) ;
}
void F_149 ( struct V_117 * V_118 ,
struct V_253 * V_254 )
{
F_150 ( V_118 , V_254 -> V_45 . V_128 ) ;
F_145 ( V_118 , false , V_254 -> V_45 . V_128 ) ;
}
void F_151 ( struct V_117 * V_118 ,
struct V_253 * V_254 )
{
}
bool F_152 ( struct V_117 * V_118 )
{
return true ;
}
static int F_153 ( struct V_117 * V_118 )
{
T_5 V_246 ;
struct V_255 V_45 ;
int V_93 ;
if ( V_118 -> V_45 . V_128 == V_129 )
return 0 ;
if ( ( V_118 -> V_45 . V_124 -> V_146 . V_147 & V_118 -> V_45 . V_209 ) !=
V_118 -> V_45 . V_207 )
return 0 ;
if ( F_154 ( V_118 ) )
return 0 ;
if ( F_107 ( V_118 ) )
return 0 ;
if ( ! ( V_118 -> V_45 . V_124 -> V_152 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_118 -> V_45 . V_44 -> V_114 )
return 0 ;
V_246 = F_155 ( V_118 -> V_38 , F_156 ( V_104 -> V_256 . V_257 ) ) ;
V_246 += V_104 -> V_256 . V_257 & ~ V_258 ;
if ( F_157 ( V_118 , V_118 -> V_45 . V_128 , & V_45 . V_128 , 8 ) )
return 0 ;
V_93 = F_158 ( V_118 , V_104 -> V_256 . V_257 , V_246 , & V_45 ) ;
return V_93 ;
}
static int F_159 ( struct V_117 * V_118 )
{
int V_93 , V_145 ;
F_160 ( V_118 ) ;
memcpy ( & V_118 -> V_45 . V_124 -> V_259 , & V_118 -> V_130 -> V_141 . V_142 . V_213 [ 14 ] , 16 ) ;
if ( F_161 () )
F_162 () ;
if ( F_163 ( V_260 ) )
F_164 () ;
if ( ! F_60 ( V_118 -> V_38 ) )
F_165 ( V_118 ) ;
V_93 = F_137 ( V_118 ) ;
if ( V_93 )
return V_93 ;
if ( F_166 ( V_118 ) ) {
F_167 ( V_118 ) ;
F_168 ( V_118 ) ;
}
V_118 -> V_45 . V_124 -> V_261 = 0 ;
V_145 = F_30 ( & V_118 -> V_45 . V_124 -> V_145 ) ;
F_56 ( V_118 , 6 , L_7 , V_145 ) ;
F_169 ( V_118 , V_145 ) ;
return 0 ;
}
static int F_170 ( struct V_117 * V_118 , int V_262 )
{
int V_93 = - 1 ;
F_56 ( V_118 , 6 , L_8 ,
V_118 -> V_45 . V_124 -> V_261 ) ;
F_171 ( V_118 , V_118 -> V_45 . V_124 -> V_261 ) ;
if ( F_166 ( V_118 ) )
F_172 ( V_118 ) ;
if ( V_262 >= 0 ) {
V_93 = 0 ;
} else if ( F_60 ( V_118 -> V_38 ) ) {
V_118 -> V_130 -> V_262 = V_263 ;
V_118 -> V_130 -> V_264 . V_265 =
V_104 -> V_256 . V_257 ;
V_118 -> V_130 -> V_264 . V_266 = 0x10 ;
V_93 = - V_267 ;
} else if ( V_104 -> V_256 . V_268 ) {
F_173 ( V_118 ) ;
V_104 -> V_256 . V_268 = 0 ;
if ( F_153 ( V_118 ) ) {
V_93 = 0 ;
} else {
T_4 V_243 = V_104 -> V_256 . V_257 ;
V_93 = F_141 ( V_118 , V_243 , 1 ) ;
}
}
if ( V_93 == - 1 ) {
F_56 ( V_118 , 3 , L_2 , L_9 ) ;
F_174 ( V_118 ) ;
V_93 = F_175 ( V_118 , V_269 ) ;
}
memcpy ( & V_118 -> V_130 -> V_141 . V_142 . V_213 [ 14 ] , & V_118 -> V_45 . V_124 -> V_259 , 16 ) ;
if ( V_93 == 0 ) {
if ( F_60 ( V_118 -> V_38 ) )
V_93 = V_118 -> V_45 . V_124 -> V_261 ? - V_270 : 0 ;
else
V_93 = F_176 ( V_118 ) ;
}
return V_93 ;
}
static int F_177 ( struct V_117 * V_118 )
{
int V_93 , V_262 ;
V_118 -> V_271 = F_31 ( & V_118 -> V_38 -> V_74 ) ;
do {
V_93 = F_159 ( V_118 ) ;
if ( V_93 )
break;
F_33 ( & V_118 -> V_38 -> V_74 , V_118 -> V_271 ) ;
F_178 () ;
F_179 () ;
F_180 () ;
V_262 = F_181 ( V_118 -> V_45 . V_124 ,
V_118 -> V_130 -> V_141 . V_142 . V_213 ) ;
F_182 () ;
V_118 -> V_271 = F_31 ( & V_118 -> V_38 -> V_74 ) ;
V_93 = F_170 ( V_118 , V_262 ) ;
} while ( ! F_183 ( V_104 ) && ! F_184 ( V_118 ) && ! V_93 );
F_33 ( & V_118 -> V_38 -> V_74 , V_118 -> V_271 ) ;
return V_93 ;
}
int F_185 ( struct V_117 * V_118 , struct V_272 * V_272 )
{
int V_93 ;
T_6 V_273 ;
if ( F_184 ( V_118 ) ) {
F_186 ( V_118 ) ;
return 0 ;
}
if ( V_118 -> V_274 )
F_187 ( V_275 , & V_118 -> V_276 , & V_273 ) ;
F_188 ( V_118 ) ;
switch ( V_272 -> V_262 ) {
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_263 :
case V_281 :
case V_282 :
break;
default:
F_116 () ;
}
V_118 -> V_45 . V_124 -> V_146 . V_147 = V_272 -> V_220 ;
V_118 -> V_45 . V_124 -> V_146 . V_148 = V_272 -> V_221 ;
if ( V_272 -> V_283 & V_132 ) {
V_272 -> V_283 &= ~ V_132 ;
F_90 ( V_118 , V_272 -> V_141 . V_142 . V_284 ) ;
}
if ( V_272 -> V_283 & V_135 ) {
V_272 -> V_283 &= ~ V_135 ;
memcpy ( & V_118 -> V_45 . V_124 -> V_152 , & V_272 -> V_141 . V_142 . V_216 , 128 ) ;
F_90 ( V_118 , V_272 -> V_141 . V_142 . V_284 ) ;
}
F_189 () ;
V_93 = F_177 ( V_118 ) ;
if ( F_183 ( V_104 ) && ! V_93 ) {
V_272 -> V_262 = V_279 ;
V_93 = - V_285 ;
}
if ( F_184 ( V_118 ) && ! V_93 ) {
F_186 ( V_118 ) ;
V_93 = 0 ;
}
if ( V_93 == - V_270 ) {
V_272 -> V_262 = V_277 ;
V_272 -> V_286 . V_261 = V_118 -> V_45 . V_124 -> V_261 ;
V_272 -> V_286 . V_287 = V_118 -> V_45 . V_124 -> V_287 ;
V_272 -> V_286 . V_288 = V_118 -> V_45 . V_124 -> V_288 ;
V_93 = 0 ;
}
if ( V_93 == - V_267 ) {
V_93 = 0 ;
}
V_272 -> V_220 = V_118 -> V_45 . V_124 -> V_146 . V_147 ;
V_272 -> V_221 = V_118 -> V_45 . V_124 -> V_146 . V_148 ;
V_272 -> V_141 . V_142 . V_284 = F_113 ( V_118 ) ;
memcpy ( & V_272 -> V_141 . V_142 . V_216 , & V_118 -> V_45 . V_124 -> V_152 , 128 ) ;
if ( V_118 -> V_274 )
F_187 ( V_275 , & V_273 , NULL ) ;
V_118 -> V_289 . V_290 ++ ;
return V_93 ;
}
int F_190 ( struct V_117 * V_118 , unsigned long V_243 )
{
unsigned char V_291 = 1 ;
unsigned int V_292 ;
V_202 V_293 ;
int V_93 ;
if ( V_243 == V_294 ) {
if ( F_191 ( V_118 , 163 , & V_291 , 1 ) )
return - V_84 ;
V_243 = V_295 ;
} else if ( V_243 == V_296 ) {
if ( F_192 ( V_118 , 163 , & V_291 , 1 ) )
return - V_84 ;
V_243 = F_193 ( V_118 , V_295 ) ;
}
V_93 = F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_298 ) ,
V_118 -> V_45 . V_140 . V_138 , 128 ) ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_299 ) ,
V_118 -> V_130 -> V_141 . V_142 . V_213 , 128 ) ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_219 ) ,
& V_118 -> V_45 . V_124 -> V_146 , 16 ) ;
V_292 = F_113 ( V_118 ) ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_300 ) ,
& V_292 , 4 ) ;
V_93 |= F_191 ( V_118 ,
V_243 + F_194 ( struct V_297 , V_301 ) ,
& V_118 -> V_45 . V_140 . V_137 , 4 ) ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_302 ) ,
& V_118 -> V_45 . V_124 -> V_151 , 4 ) ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_303 ) ,
& V_118 -> V_45 . V_124 -> V_149 , 8 ) ;
V_293 = V_118 -> V_45 . V_124 -> V_150 >> 8 ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_304 ) ,
& V_293 , 8 ) ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_305 ) ,
& V_118 -> V_130 -> V_141 . V_142 . V_143 , 64 ) ;
V_93 |= F_191 ( V_118 , V_243 + F_194 ( struct V_297 , V_306 ) ,
& V_118 -> V_45 . V_124 -> V_152 , 128 ) ;
return V_93 ? - V_84 : 0 ;
}
int F_195 ( struct V_117 * V_118 , unsigned long V_148 )
{
F_78 ( & V_118 -> V_45 . V_140 . V_137 ) ;
F_79 ( V_118 -> V_45 . V_140 . V_138 ) ;
F_80 ( V_118 -> V_130 -> V_141 . V_142 . V_143 ) ;
return F_190 ( V_118 , V_148 ) ;
}
static inline int F_196 ( struct V_117 * V_118 )
{
return F_30 ( & ( V_118 ) -> V_45 . V_124 -> V_145 ) & V_159 ;
}
static void F_197 ( struct V_117 * V_118 )
{
F_138 ( V_241 , V_118 ) ;
F_114 ( V_242 , V_118 ) ;
F_112 ( V_118 ) ;
}
static void F_198 ( struct V_38 * V_38 )
{
unsigned int V_126 ;
struct V_117 * V_118 ;
F_69 (i, vcpu, kvm) {
F_197 ( V_118 ) ;
}
}
static void F_199 ( struct V_117 * V_118 )
{
F_138 ( V_242 , V_118 ) ;
F_114 ( V_241 , V_118 ) ;
F_112 ( V_118 ) ;
}
void F_188 ( struct V_117 * V_118 )
{
int V_126 , V_71 , V_307 = 0 ;
if ( ! F_196 ( V_118 ) )
return;
F_200 ( V_118 -> V_119 , 1 ) ;
F_201 ( & V_118 -> V_38 -> V_45 . V_116 ) ;
V_71 = F_30 ( & V_118 -> V_38 -> V_71 ) ;
for ( V_126 = 0 ; V_126 < V_71 ; V_126 ++ ) {
if ( ! F_196 ( V_118 -> V_38 -> V_127 [ V_126 ] ) )
V_307 ++ ;
}
if ( V_307 == 0 ) {
F_199 ( V_118 ) ;
} else if ( V_307 == 1 ) {
F_198 ( V_118 -> V_38 ) ;
}
F_87 ( V_159 , & V_118 -> V_45 . V_124 -> V_145 ) ;
V_118 -> V_45 . V_124 -> V_308 = 0xffff ;
F_202 ( & V_118 -> V_38 -> V_45 . V_116 ) ;
return;
}
void F_91 ( struct V_117 * V_118 )
{
int V_126 , V_71 , V_307 = 0 ;
struct V_117 * V_309 = NULL ;
if ( F_196 ( V_118 ) )
return;
F_200 ( V_118 -> V_119 , 0 ) ;
F_201 ( & V_118 -> V_38 -> V_45 . V_116 ) ;
V_71 = F_30 ( & V_118 -> V_38 -> V_71 ) ;
F_85 ( V_159 , & V_118 -> V_45 . V_124 -> V_145 ) ;
F_197 ( V_118 ) ;
for ( V_126 = 0 ; V_126 < V_71 ; V_126 ++ ) {
if ( ! F_196 ( V_118 -> V_38 -> V_127 [ V_126 ] ) ) {
V_307 ++ ;
V_309 = V_118 -> V_38 -> V_127 [ V_126 ] ;
}
}
if ( V_307 == 1 ) {
F_199 ( V_309 ) ;
}
F_202 ( & V_118 -> V_38 -> V_45 . V_116 ) ;
return;
}
static int F_203 ( struct V_117 * V_118 ,
struct V_59 * V_60 )
{
int V_16 ;
if ( V_60 -> V_61 )
return - V_14 ;
switch ( V_60 -> V_60 ) {
case V_25 :
if ( ! V_118 -> V_38 -> V_45 . V_115 ) {
V_118 -> V_38 -> V_45 . V_115 = 1 ;
F_204 ( V_118 -> V_38 ) ;
}
V_16 = 0 ;
break;
default:
V_16 = - V_14 ;
break;
}
return V_16 ;
}
long F_205 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_117 * V_118 = V_10 -> V_79 ;
void T_2 * V_80 = ( void T_2 * ) V_12 ;
int V_67 ;
long V_16 ;
switch ( V_11 ) {
case V_81 : {
struct V_82 V_83 ;
V_16 = - V_84 ;
if ( F_38 ( & V_83 , V_80 , sizeof( V_83 ) ) )
break;
V_16 = F_146 ( V_118 , & V_83 ) ;
break;
}
case V_310 :
V_67 = F_31 ( & V_118 -> V_38 -> V_74 ) ;
V_16 = F_195 ( V_118 , V_12 ) ;
F_33 ( & V_118 -> V_38 -> V_74 , V_67 ) ;
break;
case V_311 : {
T_3 V_219 ;
V_16 = - V_84 ;
if ( F_38 ( & V_219 , V_80 , sizeof( V_219 ) ) )
break;
V_16 = F_129 ( V_118 , V_219 ) ;
break;
}
case V_312 :
V_16 = F_121 ( V_118 ) ;
break;
case V_313 :
case V_314 : {
struct V_196 V_197 ;
V_16 = - V_84 ;
if ( F_38 ( & V_197 , V_80 , sizeof( V_197 ) ) )
break;
if ( V_11 == V_313 )
V_16 = F_119 ( V_118 , & V_197 ) ;
else
V_16 = F_117 ( V_118 , & V_197 ) ;
break;
}
#ifdef F_15
case V_315 : {
struct V_316 V_317 ;
if ( F_38 ( & V_317 , V_80 , sizeof( V_317 ) ) ) {
V_16 = - V_84 ;
break;
}
if ( ! F_60 ( V_118 -> V_38 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_206 ( V_118 -> V_45 . V_44 , V_317 . V_318 ,
V_317 . V_319 , V_317 . V_320 ) ;
break;
}
case V_321 : {
struct V_316 V_317 ;
if ( F_38 ( & V_317 , V_80 , sizeof( V_317 ) ) ) {
V_16 = - V_84 ;
break;
}
if ( ! F_60 ( V_118 -> V_38 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_207 ( V_118 -> V_45 . V_44 , V_317 . V_319 ,
V_317 . V_320 ) ;
break;
}
#endif
case V_322 : {
V_16 = F_142 ( V_12 , V_118 -> V_45 . V_44 ) ;
if ( ! F_143 ( V_16 ) )
V_16 = 0 ;
break;
}
case V_85 :
{
struct V_59 V_60 ;
V_16 = - V_84 ;
if ( F_38 ( & V_60 , V_80 , sizeof( V_60 ) ) )
break;
V_16 = F_203 ( V_118 , & V_60 ) ;
break;
}
default:
V_16 = - V_92 ;
}
return V_16 ;
}
int F_208 ( struct V_117 * V_118 , struct V_323 * V_324 )
{
#ifdef F_15
if ( ( V_324 -> V_325 == V_326 )
&& ( F_60 ( V_118 -> V_38 ) ) ) {
V_324 -> V_327 = F_209 ( V_118 -> V_45 . V_124 ) ;
F_210 ( V_324 -> V_327 ) ;
return 0 ;
}
#endif
return V_328 ;
}
void F_211 ( struct V_38 * V_38 , struct V_39 * free ,
struct V_39 * V_329 )
{
}
int F_212 ( struct V_38 * V_38 , struct V_39 * V_54 ,
unsigned long V_49 )
{
return 0 ;
}
void F_213 ( struct V_38 * V_38 )
{
}
int F_214 ( struct V_38 * V_38 ,
struct V_39 * V_40 ,
struct V_330 * V_331 ,
enum V_332 V_333 )
{
if ( V_331 -> V_334 & 0xffffful )
return - V_14 ;
if ( V_331 -> V_335 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_215 ( struct V_38 * V_38 ,
struct V_330 * V_331 ,
const struct V_39 * V_336 ,
enum V_332 V_333 )
{
int V_93 ;
if ( V_336 -> V_334 == V_331 -> V_334 &&
V_336 -> V_48 * V_240 == V_331 -> V_337 &&
V_336 -> V_49 * V_240 == V_331 -> V_335 )
return;
V_93 = F_206 ( V_38 -> V_45 . V_44 , V_331 -> V_334 ,
V_331 -> V_337 , V_331 -> V_335 ) ;
if ( V_93 )
F_216 ( V_338 L_10 ) ;
return;
}
void F_217 ( struct V_38 * V_38 )
{
}
void F_218 ( struct V_38 * V_38 ,
struct V_39 * V_54 )
{
}
static int T_7 F_219 ( void )
{
int V_66 ;
V_66 = F_220 ( NULL , sizeof( struct V_117 ) , 0 , V_339 ) ;
if ( V_66 )
return V_66 ;
V_2 = ( unsigned long * ) F_43 ( V_102 | V_340 ) ;
if ( ! V_2 ) {
F_221 () ;
return - V_99 ;
}
memcpy ( V_2 , V_341 . V_342 , 16 ) ;
V_2 [ 0 ] &= 0xff82fff3f4fc2000UL ;
V_2 [ 1 ] &= 0x005c000000000000UL ;
return 0 ;
}
static void T_8 F_222 ( void )
{
F_54 ( ( unsigned long ) V_2 ) ;
F_221 () ;
}
