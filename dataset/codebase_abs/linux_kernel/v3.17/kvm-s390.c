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
int F_14 ( struct V_15 * V_15 , long V_16 )
{
int V_17 ;
switch ( V_16 ) {
case V_18 :
case V_19 :
case V_20 :
#ifdef F_15
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
static void F_16 ( struct V_15 * V_15 ,
struct V_41 * V_42 )
{
T_1 V_43 , V_44 ;
unsigned long V_45 ;
struct V_46 * V_46 = V_15 -> V_47 . V_46 ;
F_17 ( & V_46 -> V_48 -> V_49 ) ;
V_44 = V_42 -> V_50 + V_42 -> V_51 ;
for ( V_43 = V_42 -> V_50 ; V_43 <= V_44 ; V_43 ++ ) {
V_45 = F_18 ( V_42 , V_43 ) ;
if ( F_19 ( V_45 , V_46 ) )
F_20 ( V_15 , V_43 ) ;
}
F_21 ( & V_46 -> V_48 -> V_49 ) ;
}
int F_22 ( struct V_15 * V_15 ,
struct V_52 * log )
{
int V_17 ;
unsigned long V_53 ;
struct V_41 * V_42 ;
int V_54 = 0 ;
F_23 ( & V_15 -> V_55 ) ;
V_17 = - V_14 ;
if ( log -> V_56 >= V_38 )
goto V_57;
V_42 = F_24 ( V_15 -> V_58 , log -> V_56 ) ;
V_17 = - V_59 ;
if ( ! V_42 -> V_60 )
goto V_57;
F_16 ( V_15 , V_42 ) ;
V_17 = F_25 ( V_15 , log , & V_54 ) ;
if ( V_17 )
goto V_57;
if ( V_54 ) {
V_53 = F_26 ( V_42 ) ;
memset ( V_42 -> V_60 , 0 , V_53 ) ;
}
V_17 = 0 ;
V_57:
F_27 ( & V_15 -> V_55 ) ;
return V_17 ;
}
static int F_28 ( struct V_15 * V_15 , struct V_61 * V_62 )
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
static int F_29 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
int V_67 ;
unsigned int V_68 ;
switch ( V_66 -> V_66 ) {
case V_69 :
V_67 = - V_70 ;
F_23 ( & V_15 -> V_71 ) ;
if ( F_30 ( & V_15 -> V_72 ) == 0 ) {
V_15 -> V_47 . V_73 = 1 ;
V_67 = 0 ;
}
F_27 ( & V_15 -> V_71 ) ;
break;
case V_74 :
F_23 ( & V_15 -> V_71 ) ;
V_68 = F_31 ( & V_15 -> V_75 ) ;
F_32 ( V_15 -> V_47 . V_46 -> V_48 , 0 , V_76 , false ) ;
F_33 ( & V_15 -> V_75 , V_68 ) ;
F_27 ( & V_15 -> V_71 ) ;
V_67 = 0 ;
break;
default:
V_67 = - V_77 ;
break;
}
return V_67 ;
}
static int F_34 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
int V_67 ;
switch ( V_66 -> V_78 ) {
case V_79 :
V_67 = F_29 ( V_15 , V_66 ) ;
break;
default:
V_67 = - V_77 ;
break;
}
return V_67 ;
}
static int F_35 ( struct V_15 * V_15 , struct V_65 * V_66 )
{
return - V_77 ;
}
static int F_36 ( struct V_15 * V_15 , struct V_65 * V_66 )
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
long F_37 ( struct V_9 * V_10 ,
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
if ( F_38 ( & V_84 , V_81 , sizeof( V_84 ) ) )
break;
V_17 = F_39 ( V_15 , & V_84 ) ;
break;
}
case V_86 : {
struct V_61 V_62 ;
V_17 = - V_85 ;
if ( F_38 ( & V_62 , V_81 , sizeof( V_62 ) ) )
break;
V_17 = F_28 ( V_15 , & V_62 ) ;
break;
}
case V_87 : {
struct V_88 V_89 ;
V_17 = - V_14 ;
if ( V_15 -> V_47 . V_64 ) {
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
F_40 ( V_15 , & V_89 , 0 , 0 ) ;
V_17 = 0 ;
}
break;
}
case V_90 : {
V_17 = - V_85 ;
if ( F_38 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_34 ( V_15 , & V_66 ) ;
break;
}
case V_91 : {
V_17 = - V_85 ;
if ( F_38 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_35 ( V_15 , & V_66 ) ;
break;
}
case V_92 : {
V_17 = - V_85 ;
if ( F_38 ( & V_66 , ( void T_2 * ) V_12 , sizeof( V_66 ) ) )
break;
V_17 = F_36 ( V_15 , & V_66 ) ;
break;
}
default:
V_17 = - V_93 ;
}
return V_17 ;
}
int F_41 ( struct V_15 * V_15 , unsigned long type )
{
int V_94 ;
char V_95 [ 16 ] ;
static unsigned long V_96 ;
V_94 = - V_14 ;
#ifdef F_15
if ( type & ~ V_97 )
goto V_98;
if ( ( type & V_97 ) && ( ! F_42 ( V_99 ) ) )
goto V_98;
#else
if ( type )
goto V_98;
#endif
V_94 = F_13 () ;
if ( V_94 )
goto V_98;
V_94 = - V_100 ;
V_15 -> V_47 . V_101 = (struct V_102 * ) F_43 ( V_103 ) ;
if ( ! V_15 -> V_47 . V_101 )
goto V_98;
F_44 ( & V_104 ) ;
V_96 = ( V_96 + 16 ) & 0x7f0 ;
V_15 -> V_47 . V_101 = (struct V_102 * ) ( ( char * ) V_15 -> V_47 . V_101 + V_96 ) ;
F_45 ( & V_104 ) ;
sprintf ( V_95 , L_1 , V_105 -> V_106 ) ;
V_15 -> V_47 . V_107 = F_46 ( V_95 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_15 -> V_47 . V_107 )
goto V_108;
F_47 ( & V_15 -> V_47 . V_109 . V_71 ) ;
F_48 ( & V_15 -> V_47 . V_109 . V_110 ) ;
F_49 ( & V_15 -> V_47 . V_111 ) ;
F_50 ( V_15 -> V_47 . V_107 , & V_112 ) ;
F_51 ( V_15 , 3 , L_2 , L_3 ) ;
if ( type & V_97 ) {
V_15 -> V_47 . V_46 = NULL ;
} else {
V_15 -> V_47 . V_46 = F_52 ( V_105 -> V_48 ) ;
if ( ! V_15 -> V_47 . V_46 )
goto V_113;
V_15 -> V_47 . V_46 -> V_114 = V_15 ;
V_15 -> V_47 . V_46 -> V_115 = 0 ;
}
V_15 -> V_47 . V_116 = 0 ;
V_15 -> V_47 . V_64 = 0 ;
F_47 ( & V_15 -> V_47 . V_117 ) ;
return 0 ;
V_113:
F_53 ( V_15 -> V_47 . V_107 ) ;
V_108:
F_54 ( ( unsigned long ) ( V_15 -> V_47 . V_101 ) ) ;
V_98:
return V_94 ;
}
void F_55 ( struct V_118 * V_119 )
{
F_56 ( V_119 , 3 , L_2 , L_4 ) ;
F_57 ( V_119 -> V_120 ) ;
F_58 ( V_119 ) ;
F_59 ( V_119 ) ;
if ( ! F_60 ( V_119 -> V_15 ) ) {
F_61 ( 63 - V_119 -> V_120 ,
( unsigned long * ) & V_119 -> V_15 -> V_47 . V_101 -> V_121 ) ;
if ( V_119 -> V_15 -> V_47 . V_101 -> V_122 [ V_119 -> V_120 ] . V_123 ==
( V_124 ) V_119 -> V_47 . V_125 )
V_119 -> V_15 -> V_47 . V_101 -> V_122 [ V_119 -> V_120 ] . V_123 = 0 ;
}
F_62 () ;
if ( F_60 ( V_119 -> V_15 ) )
F_63 ( V_119 -> V_47 . V_46 ) ;
if ( F_64 ( V_119 -> V_15 ) )
F_65 ( V_119 ) ;
F_54 ( ( unsigned long ) ( V_119 -> V_47 . V_125 ) ) ;
F_66 ( V_119 ) ;
F_67 ( V_126 , V_119 ) ;
}
static void F_68 ( struct V_15 * V_15 )
{
unsigned int V_127 ;
struct V_118 * V_119 ;
F_69 (i, vcpu, kvm)
F_55 ( V_119 ) ;
F_23 ( & V_15 -> V_71 ) ;
for ( V_127 = 0 ; V_127 < F_30 ( & V_15 -> V_72 ) ; V_127 ++ )
V_15 -> V_128 [ V_127 ] = NULL ;
F_70 ( & V_15 -> V_72 , 0 ) ;
F_27 ( & V_15 -> V_71 ) ;
}
void F_71 ( struct V_15 * V_15 )
{
}
void F_72 ( struct V_15 * V_15 )
{
F_68 ( V_15 ) ;
F_54 ( ( unsigned long ) ( V_15 -> V_47 . V_101 ) ) ;
F_53 ( V_15 -> V_47 . V_107 ) ;
if ( ! F_60 ( V_15 ) )
F_63 ( V_15 -> V_47 . V_46 ) ;
F_73 ( V_15 ) ;
F_74 ( V_15 ) ;
}
int F_75 ( struct V_118 * V_119 )
{
V_119 -> V_47 . V_129 = V_130 ;
F_59 ( V_119 ) ;
if ( F_60 ( V_119 -> V_15 ) ) {
V_119 -> V_47 . V_46 = F_52 ( V_105 -> V_48 ) ;
if ( ! V_119 -> V_47 . V_46 )
return - V_100 ;
V_119 -> V_47 . V_46 -> V_114 = V_119 -> V_15 ;
return 0 ;
}
V_119 -> V_47 . V_46 = V_119 -> V_15 -> V_47 . V_46 ;
V_119 -> V_131 -> V_132 = V_133 |
V_134 |
V_135 |
V_136 ;
return 0 ;
}
void F_76 ( struct V_118 * V_119 )
{
}
void F_77 ( struct V_118 * V_119 , int V_122 )
{
F_78 ( & V_119 -> V_47 . V_137 . V_138 ) ;
F_79 ( V_119 -> V_47 . V_137 . V_139 ) ;
F_80 ( V_119 -> V_47 . V_140 ) ;
F_81 ( & V_119 -> V_47 . V_141 . V_138 ) ;
F_82 ( V_119 -> V_47 . V_141 . V_139 ) ;
F_83 ( V_119 -> V_131 -> V_142 . V_143 . V_144 ) ;
F_84 ( V_119 -> V_47 . V_46 ) ;
F_85 ( V_145 , & V_119 -> V_47 . V_125 -> V_146 ) ;
}
void F_86 ( struct V_118 * V_119 )
{
F_87 ( V_145 , & V_119 -> V_47 . V_125 -> V_146 ) ;
F_88 ( V_119 -> V_47 . V_46 ) ;
F_78 ( & V_119 -> V_47 . V_141 . V_138 ) ;
F_79 ( V_119 -> V_47 . V_141 . V_139 ) ;
F_80 ( V_119 -> V_131 -> V_142 . V_143 . V_144 ) ;
F_81 ( & V_119 -> V_47 . V_137 . V_138 ) ;
F_82 ( V_119 -> V_47 . V_137 . V_139 ) ;
F_83 ( V_119 -> V_47 . V_140 ) ;
}
static void F_89 ( struct V_118 * V_119 )
{
V_119 -> V_47 . V_125 -> V_147 . V_148 = 0UL ;
V_119 -> V_47 . V_125 -> V_147 . V_149 = 0UL ;
F_90 ( V_119 , 0 ) ;
V_119 -> V_47 . V_125 -> V_150 = 0UL ;
V_119 -> V_47 . V_125 -> V_151 = 0UL ;
V_119 -> V_47 . V_125 -> V_152 = 0 ;
memset ( V_119 -> V_47 . V_125 -> V_153 , 0 , 16 * sizeof( V_124 ) ) ;
V_119 -> V_47 . V_125 -> V_153 [ 0 ] = 0xE0UL ;
V_119 -> V_47 . V_125 -> V_153 [ 14 ] = 0xC2000000UL ;
V_119 -> V_47 . V_141 . V_138 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_119 -> V_47 . V_125 -> V_154 = 1 ;
V_119 -> V_47 . V_125 -> V_155 = 0 ;
V_119 -> V_47 . V_129 = V_130 ;
F_59 ( V_119 ) ;
if ( ! F_91 ( V_119 -> V_15 ) )
F_92 ( V_119 ) ;
F_58 ( V_119 ) ;
}
int F_93 ( struct V_118 * V_119 )
{
return 0 ;
}
void F_65 ( struct V_118 * V_119 )
{
F_54 ( V_119 -> V_47 . V_125 -> V_156 ) ;
V_119 -> V_47 . V_125 -> V_156 = 0 ;
}
int F_94 ( struct V_118 * V_119 )
{
V_119 -> V_47 . V_125 -> V_156 = F_43 ( V_103 ) ;
if ( ! V_119 -> V_47 . V_125 -> V_156 )
return - V_100 ;
V_119 -> V_47 . V_125 -> V_157 |= 0x80 ;
V_119 -> V_47 . V_125 -> V_157 &= ~ 0x08 ;
return 0 ;
}
int F_95 ( struct V_118 * V_119 )
{
int V_94 = 0 ;
F_70 ( & V_119 -> V_47 . V_125 -> V_146 , V_158 |
V_159 |
V_160 |
V_161 ) ;
V_119 -> V_47 . V_125 -> V_162 = 6 ;
if ( F_1 ( 50 ) && F_1 ( 73 ) )
V_119 -> V_47 . V_125 -> V_162 |= 0x10 ;
V_119 -> V_47 . V_125 -> V_157 = 8 ;
V_119 -> V_47 . V_125 -> V_163 = 0xD1002000U ;
if ( F_96 () )
V_119 -> V_47 . V_125 -> V_163 |= 1 ;
V_119 -> V_47 . V_125 -> V_164 = ( int ) ( long ) V_2 ;
V_119 -> V_47 . V_125 -> V_165 |= V_166 | V_167 | V_168 |
V_169 ;
if ( F_64 ( V_119 -> V_15 ) ) {
V_94 = F_94 ( V_119 ) ;
if ( V_94 )
return V_94 ;
}
F_97 ( & V_119 -> V_47 . V_170 , V_171 , V_172 ) ;
V_119 -> V_47 . V_170 . V_173 = V_174 ;
F_98 ( & V_119 -> V_47 . V_175 ) ;
V_119 -> V_47 . V_175 . V_176 = 0xff ;
return V_94 ;
}
struct V_118 * F_99 ( struct V_15 * V_15 ,
unsigned int V_177 )
{
struct V_118 * V_119 ;
struct V_178 * V_178 ;
int V_94 = - V_14 ;
if ( V_177 >= V_36 )
goto V_57;
V_94 = - V_100 ;
V_119 = F_100 ( V_126 , V_103 ) ;
if ( ! V_119 )
goto V_57;
V_178 = (struct V_178 * ) F_43 ( V_103 ) ;
if ( ! V_178 )
goto V_179;
V_119 -> V_47 . V_125 = & V_178 -> V_125 ;
V_119 -> V_47 . V_125 -> V_180 = ( unsigned long ) & V_178 -> V_181 ;
V_119 -> V_47 . V_125 -> V_182 = V_177 ;
if ( ! F_60 ( V_15 ) ) {
if ( ! V_15 -> V_47 . V_101 ) {
F_101 ( 1 ) ;
goto V_179;
}
if ( ! V_15 -> V_47 . V_101 -> V_122 [ V_177 ] . V_123 )
V_15 -> V_47 . V_101 -> V_122 [ V_177 ] . V_123 =
( V_124 ) V_119 -> V_47 . V_125 ;
V_119 -> V_47 . V_125 -> V_183 =
( V_184 ) ( ( ( V_124 ) V_15 -> V_47 . V_101 ) >> 32 ) ;
V_119 -> V_47 . V_125 -> V_185 = ( V_184 ) ( V_124 ) V_15 -> V_47 . V_101 ;
F_102 ( 63 - V_177 , ( unsigned long * ) & V_15 -> V_47 . V_101 -> V_121 ) ;
}
F_47 ( & V_119 -> V_47 . V_186 . V_71 ) ;
F_48 ( & V_119 -> V_47 . V_186 . V_110 ) ;
V_119 -> V_47 . V_186 . V_109 = & V_15 -> V_47 . V_109 ;
V_119 -> V_47 . V_186 . V_187 = & V_119 -> V_187 ;
V_119 -> V_47 . V_186 . V_146 = & V_119 -> V_47 . V_125 -> V_146 ;
V_94 = F_103 ( V_119 , V_15 , V_177 ) ;
if ( V_94 )
goto V_188;
F_51 ( V_15 , 3 , L_5 , V_177 , V_119 ,
V_119 -> V_47 . V_125 ) ;
F_104 ( V_177 , V_119 , V_119 -> V_47 . V_125 ) ;
return V_119 ;
V_188:
F_54 ( ( unsigned long ) ( V_119 -> V_47 . V_125 ) ) ;
V_179:
F_67 ( V_126 , V_119 ) ;
V_57:
return F_105 ( V_94 ) ;
}
int F_106 ( struct V_118 * V_119 )
{
return F_107 ( V_119 ) ;
}
void F_108 ( struct V_118 * V_119 )
{
F_85 ( V_189 , & V_119 -> V_47 . V_125 -> V_190 ) ;
}
void F_109 ( struct V_118 * V_119 )
{
F_87 ( V_189 , & V_119 -> V_47 . V_125 -> V_190 ) ;
}
void F_110 ( struct V_118 * V_119 )
{
F_85 ( V_191 , & V_119 -> V_47 . V_125 -> V_146 ) ;
while ( V_119 -> V_47 . V_125 -> V_192 & V_193 )
F_111 () ;
}
void F_112 ( struct V_118 * V_119 )
{
F_108 ( V_119 ) ;
F_110 ( V_119 ) ;
}
static void V_6 ( struct V_46 * V_46 , unsigned long V_45 )
{
int V_127 ;
struct V_15 * V_15 = V_46 -> V_114 ;
struct V_118 * V_119 ;
F_69 (i, vcpu, kvm) {
if ( F_113 ( V_119 ) == ( V_45 & ~ 0x1000UL ) ) {
F_56 ( V_119 , 2 , L_6 , V_45 ) ;
F_114 ( V_194 , V_119 ) ;
F_112 ( V_119 ) ;
}
}
}
int F_115 ( struct V_118 * V_119 )
{
F_116 () ;
return 0 ;
}
static int F_117 ( struct V_118 * V_119 ,
struct V_195 * V_196 )
{
int V_17 = - V_14 ;
switch ( V_196 -> V_177 ) {
case V_197 :
V_17 = F_118 ( V_119 -> V_47 . V_125 -> V_152 ,
( V_198 T_2 * ) V_196 -> V_149 ) ;
break;
case V_199 :
V_17 = F_118 ( V_119 -> V_47 . V_125 -> V_200 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_202 :
V_17 = F_118 ( V_119 -> V_47 . V_125 -> V_150 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_203 :
V_17 = F_118 ( V_119 -> V_47 . V_125 -> V_151 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_204 :
V_17 = F_118 ( V_119 -> V_47 . V_129 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_205 :
V_17 = F_118 ( V_119 -> V_47 . V_206 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_207 :
V_17 = F_118 ( V_119 -> V_47 . V_208 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_209 :
V_17 = F_118 ( V_119 -> V_47 . V_125 -> V_155 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_210 :
V_17 = F_118 ( V_119 -> V_47 . V_125 -> V_154 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_119 ( struct V_118 * V_119 ,
struct V_195 * V_196 )
{
int V_17 = - V_14 ;
switch ( V_196 -> V_177 ) {
case V_197 :
V_17 = F_120 ( V_119 -> V_47 . V_125 -> V_152 ,
( V_198 T_2 * ) V_196 -> V_149 ) ;
break;
case V_199 :
V_17 = F_120 ( V_119 -> V_47 . V_125 -> V_200 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_202 :
V_17 = F_120 ( V_119 -> V_47 . V_125 -> V_150 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_203 :
V_17 = F_120 ( V_119 -> V_47 . V_125 -> V_151 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_204 :
V_17 = F_120 ( V_119 -> V_47 . V_129 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_205 :
V_17 = F_120 ( V_119 -> V_47 . V_206 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_207 :
V_17 = F_120 ( V_119 -> V_47 . V_208 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_209 :
V_17 = F_120 ( V_119 -> V_47 . V_125 -> V_155 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
case V_210 :
V_17 = F_120 ( V_119 -> V_47 . V_125 -> V_154 ,
( V_201 T_2 * ) V_196 -> V_149 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_121 ( struct V_118 * V_119 )
{
F_89 ( V_119 ) ;
return 0 ;
}
int F_122 ( struct V_118 * V_119 , struct V_211 * V_143 )
{
memcpy ( & V_119 -> V_131 -> V_142 . V_143 . V_212 , & V_143 -> V_212 , sizeof( V_143 -> V_212 ) ) ;
return 0 ;
}
int F_123 ( struct V_118 * V_119 , struct V_211 * V_143 )
{
memcpy ( & V_143 -> V_212 , & V_119 -> V_131 -> V_142 . V_143 . V_212 , sizeof( V_143 -> V_212 ) ) ;
return 0 ;
}
int F_124 ( struct V_118 * V_119 ,
struct V_213 * V_214 )
{
memcpy ( & V_119 -> V_131 -> V_142 . V_143 . V_144 , & V_214 -> V_144 , sizeof( V_214 -> V_144 ) ) ;
memcpy ( & V_119 -> V_47 . V_125 -> V_153 , & V_214 -> V_215 , sizeof( V_214 -> V_215 ) ) ;
F_83 ( V_119 -> V_131 -> V_142 . V_143 . V_144 ) ;
return 0 ;
}
int F_125 ( struct V_118 * V_119 ,
struct V_213 * V_214 )
{
memcpy ( & V_214 -> V_144 , & V_119 -> V_131 -> V_142 . V_143 . V_144 , sizeof( V_214 -> V_144 ) ) ;
memcpy ( & V_214 -> V_215 , & V_119 -> V_47 . V_125 -> V_153 , sizeof( V_214 -> V_215 ) ) ;
return 0 ;
}
int F_126 ( struct V_118 * V_119 , struct V_216 * V_217 )
{
if ( F_127 ( V_217 -> V_138 ) )
return - V_14 ;
memcpy ( & V_119 -> V_47 . V_141 . V_139 , & V_217 -> V_139 , sizeof( V_217 -> V_139 ) ) ;
V_119 -> V_47 . V_141 . V_138 = V_217 -> V_138 ;
F_81 ( & V_119 -> V_47 . V_141 . V_138 ) ;
F_82 ( V_119 -> V_47 . V_141 . V_139 ) ;
return 0 ;
}
int F_128 ( struct V_118 * V_119 , struct V_216 * V_217 )
{
memcpy ( & V_217 -> V_139 , & V_119 -> V_47 . V_141 . V_139 , sizeof( V_217 -> V_139 ) ) ;
V_217 -> V_138 = V_119 -> V_47 . V_141 . V_138 ;
return 0 ;
}
static int F_129 ( struct V_118 * V_119 , T_3 V_218 )
{
int V_94 = 0 ;
if ( ! F_130 ( V_119 ) )
V_94 = - V_70 ;
else {
V_119 -> V_131 -> V_219 = V_218 . V_148 ;
V_119 -> V_131 -> V_220 = V_218 . V_149 ;
}
return V_94 ;
}
int F_131 ( struct V_118 * V_119 ,
struct V_221 * V_222 )
{
return - V_14 ;
}
int F_132 ( struct V_118 * V_119 ,
struct V_223 * V_224 )
{
int V_94 = 0 ;
V_119 -> V_225 = 0 ;
F_133 ( V_119 ) ;
if ( V_224 -> V_226 & ~ V_227 )
return - V_14 ;
if ( V_224 -> V_226 & V_228 ) {
V_119 -> V_225 = V_224 -> V_226 ;
F_85 ( V_229 , & V_119 -> V_47 . V_125 -> V_146 ) ;
if ( V_224 -> V_226 & V_230 )
V_94 = F_134 ( V_119 , V_224 ) ;
} else {
F_87 ( V_229 , & V_119 -> V_47 . V_125 -> V_146 ) ;
V_119 -> V_47 . V_231 . V_232 = 0 ;
}
if ( V_94 ) {
V_119 -> V_225 = 0 ;
F_133 ( V_119 ) ;
F_87 ( V_229 , & V_119 -> V_47 . V_125 -> V_146 ) ;
}
return V_94 ;
}
int F_135 ( struct V_118 * V_119 ,
struct V_233 * V_234 )
{
return F_130 ( V_119 ) ? V_235 :
V_236 ;
}
int F_136 ( struct V_118 * V_119 ,
struct V_233 * V_234 )
{
int V_94 = 0 ;
V_119 -> V_15 -> V_47 . V_237 = 1 ;
switch ( V_234 -> V_234 ) {
case V_235 :
F_92 ( V_119 ) ;
break;
case V_236 :
F_137 ( V_119 ) ;
break;
case V_238 :
case V_239 :
default:
V_94 = - V_77 ;
}
return V_94 ;
}
bool F_64 ( struct V_15 * V_15 )
{
if ( ! V_240 )
return false ;
if ( ! V_241 )
return false ;
if ( ! V_15 -> V_47 . V_73 )
return false ;
return true ;
}
static bool F_138 ( struct V_118 * V_119 )
{
return F_30 ( & V_119 -> V_47 . V_125 -> V_146 ) & V_242 ;
}
static int F_139 ( struct V_118 * V_119 )
{
V_243:
F_109 ( V_119 ) ;
if ( F_140 ( V_194 , V_119 ) ) {
int V_94 ;
V_94 = F_141 ( V_119 -> V_47 . V_46 ,
F_113 ( V_119 ) ,
V_244 * 2 ) ;
if ( V_94 )
return V_94 ;
goto V_243;
}
if ( F_140 ( V_245 , V_119 ) ) {
if ( ! F_138 ( V_119 ) ) {
F_142 ( V_119 -> V_120 , 1 ) ;
F_85 ( V_242 ,
& V_119 -> V_47 . V_125 -> V_146 ) ;
}
goto V_243;
}
if ( F_140 ( V_246 , V_119 ) ) {
if ( F_138 ( V_119 ) ) {
F_142 ( V_119 -> V_120 , 0 ) ;
F_87 ( V_242 ,
& V_119 -> V_47 . V_125 -> V_146 ) ;
}
goto V_243;
}
F_61 ( V_247 , & V_119 -> V_248 ) ;
return 0 ;
}
long F_143 ( struct V_118 * V_119 , T_4 V_249 , int V_250 )
{
struct V_251 * V_48 = V_105 -> V_48 ;
T_5 V_252 ;
long V_94 ;
V_252 = F_144 ( V_249 , V_119 -> V_47 . V_46 ) ;
if ( F_145 ( V_252 ) )
return ( long ) V_252 ;
F_17 ( & V_48 -> V_49 ) ;
V_94 = F_146 ( V_105 , V_48 , V_252 , 1 , V_250 , 0 , NULL , NULL ) ;
F_21 ( & V_48 -> V_49 ) ;
return V_94 < 0 ? V_94 : 0 ;
}
static void F_147 ( struct V_118 * V_119 , bool V_253 ,
unsigned long V_254 )
{
struct V_83 V_255 ;
V_255 . V_256 = V_254 ;
if ( V_253 ) {
V_255 . type = V_257 ;
F_101 ( F_148 ( V_119 , & V_255 ) ) ;
} else {
V_255 . type = V_258 ;
F_101 ( F_39 ( V_119 -> V_15 , & V_255 ) ) ;
}
}
void F_149 ( struct V_118 * V_119 ,
struct V_259 * V_260 )
{
F_150 ( V_119 , V_260 -> V_47 . V_129 ) ;
F_147 ( V_119 , true , V_260 -> V_47 . V_129 ) ;
}
void F_151 ( struct V_118 * V_119 ,
struct V_259 * V_260 )
{
F_152 ( V_119 , V_260 -> V_47 . V_129 ) ;
F_147 ( V_119 , false , V_260 -> V_47 . V_129 ) ;
}
void F_153 ( struct V_118 * V_119 ,
struct V_259 * V_260 )
{
}
bool F_154 ( struct V_118 * V_119 )
{
return true ;
}
static int F_155 ( struct V_118 * V_119 )
{
T_5 V_252 ;
struct V_261 V_47 ;
int V_94 ;
if ( V_119 -> V_47 . V_129 == V_130 )
return 0 ;
if ( ( V_119 -> V_47 . V_125 -> V_147 . V_148 & V_119 -> V_47 . V_208 ) !=
V_119 -> V_47 . V_206 )
return 0 ;
if ( F_156 ( V_119 ) )
return 0 ;
if ( F_107 ( V_119 ) )
return 0 ;
if ( ! ( V_119 -> V_47 . V_125 -> V_153 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_119 -> V_47 . V_46 -> V_115 )
return 0 ;
V_252 = F_157 ( V_119 -> V_15 , F_158 ( V_105 -> V_262 . V_263 ) ) ;
V_252 += V_105 -> V_262 . V_263 & ~ V_264 ;
if ( F_159 ( V_119 , V_119 -> V_47 . V_129 , & V_47 . V_129 , 8 ) )
return 0 ;
V_94 = F_160 ( V_119 , V_105 -> V_262 . V_263 , V_252 , & V_47 ) ;
return V_94 ;
}
static int F_161 ( struct V_118 * V_119 )
{
int V_94 , V_146 ;
F_162 ( V_119 ) ;
memcpy ( & V_119 -> V_47 . V_125 -> V_265 , & V_119 -> V_131 -> V_142 . V_143 . V_212 [ 14 ] , 16 ) ;
if ( F_163 () )
F_164 () ;
if ( F_165 ( V_266 ) )
F_166 () ;
if ( ! F_60 ( V_119 -> V_15 ) )
F_167 ( V_119 ) ;
V_94 = F_139 ( V_119 ) ;
if ( V_94 )
return V_94 ;
if ( F_168 ( V_119 ) ) {
F_169 ( V_119 ) ;
F_170 ( V_119 ) ;
}
V_119 -> V_47 . V_125 -> V_267 = 0 ;
V_146 = F_30 ( & V_119 -> V_47 . V_125 -> V_146 ) ;
F_56 ( V_119 , 6 , L_7 , V_146 ) ;
F_171 ( V_119 , V_146 ) ;
return 0 ;
}
static int F_172 ( struct V_118 * V_119 , int V_268 )
{
int V_94 = - 1 ;
F_56 ( V_119 , 6 , L_8 ,
V_119 -> V_47 . V_125 -> V_267 ) ;
F_173 ( V_119 , V_119 -> V_47 . V_125 -> V_267 ) ;
if ( F_168 ( V_119 ) )
F_174 ( V_119 ) ;
if ( V_268 >= 0 ) {
V_94 = 0 ;
} else if ( F_60 ( V_119 -> V_15 ) ) {
V_119 -> V_131 -> V_268 = V_269 ;
V_119 -> V_131 -> V_270 . V_271 =
V_105 -> V_262 . V_263 ;
V_119 -> V_131 -> V_270 . V_272 = 0x10 ;
V_94 = - V_273 ;
} else if ( V_105 -> V_262 . V_274 ) {
F_175 ( V_119 ) ;
V_105 -> V_262 . V_274 = 0 ;
if ( F_155 ( V_119 ) ) {
V_94 = 0 ;
} else {
T_4 V_249 = V_105 -> V_262 . V_263 ;
V_94 = F_143 ( V_119 , V_249 , 1 ) ;
}
}
if ( V_94 == - 1 ) {
F_56 ( V_119 , 3 , L_2 , L_9 ) ;
F_176 ( V_119 ) ;
V_94 = F_177 ( V_119 , V_275 ) ;
}
memcpy ( & V_119 -> V_131 -> V_142 . V_143 . V_212 [ 14 ] , & V_119 -> V_47 . V_125 -> V_265 , 16 ) ;
if ( V_94 == 0 ) {
if ( F_60 ( V_119 -> V_15 ) )
V_94 = V_119 -> V_47 . V_125 -> V_267 ? - V_276 : 0 ;
else
V_94 = F_178 ( V_119 ) ;
}
return V_94 ;
}
static int F_179 ( struct V_118 * V_119 )
{
int V_94 , V_268 ;
V_119 -> V_277 = F_31 ( & V_119 -> V_15 -> V_75 ) ;
do {
V_94 = F_161 ( V_119 ) ;
if ( V_94 )
break;
F_33 ( & V_119 -> V_15 -> V_75 , V_119 -> V_277 ) ;
F_180 () ;
F_181 () ;
F_182 () ;
V_268 = F_183 ( V_119 -> V_47 . V_125 ,
V_119 -> V_131 -> V_142 . V_143 . V_212 ) ;
F_184 () ;
V_119 -> V_277 = F_31 ( & V_119 -> V_15 -> V_75 ) ;
V_94 = F_172 ( V_119 , V_268 ) ;
} while ( ! F_185 ( V_105 ) && ! F_186 ( V_119 ) && ! V_94 );
F_33 ( & V_119 -> V_15 -> V_75 , V_119 -> V_277 ) ;
return V_94 ;
}
int F_187 ( struct V_118 * V_119 , struct V_278 * V_278 )
{
int V_94 ;
T_6 V_279 ;
if ( F_186 ( V_119 ) ) {
F_188 ( V_119 ) ;
return 0 ;
}
if ( V_119 -> V_280 )
F_189 ( V_281 , & V_119 -> V_282 , & V_279 ) ;
if ( ! F_91 ( V_119 -> V_15 ) ) {
F_137 ( V_119 ) ;
} else if ( F_130 ( V_119 ) ) {
F_190 ( L_10 ,
V_119 -> V_120 ) ;
return - V_14 ;
}
V_119 -> V_47 . V_125 -> V_147 . V_148 = V_278 -> V_219 ;
V_119 -> V_47 . V_125 -> V_147 . V_149 = V_278 -> V_220 ;
if ( V_278 -> V_283 & V_133 ) {
V_278 -> V_283 &= ~ V_133 ;
F_90 ( V_119 , V_278 -> V_142 . V_143 . V_284 ) ;
}
if ( V_278 -> V_283 & V_136 ) {
V_278 -> V_283 &= ~ V_136 ;
memcpy ( & V_119 -> V_47 . V_125 -> V_153 , & V_278 -> V_142 . V_143 . V_215 , 128 ) ;
F_90 ( V_119 , V_278 -> V_142 . V_143 . V_284 ) ;
}
F_191 () ;
V_94 = F_179 ( V_119 ) ;
if ( F_185 ( V_105 ) && ! V_94 ) {
V_278 -> V_268 = V_285 ;
V_94 = - V_286 ;
}
if ( F_186 ( V_119 ) && ! V_94 ) {
F_188 ( V_119 ) ;
V_94 = 0 ;
}
if ( V_94 == - V_276 ) {
V_278 -> V_268 = V_287 ;
V_278 -> V_288 . V_267 = V_119 -> V_47 . V_125 -> V_267 ;
V_278 -> V_288 . V_289 = V_119 -> V_47 . V_125 -> V_289 ;
V_278 -> V_288 . V_290 = V_119 -> V_47 . V_125 -> V_290 ;
V_94 = 0 ;
}
if ( V_94 == - V_273 ) {
V_94 = 0 ;
}
V_278 -> V_219 = V_119 -> V_47 . V_125 -> V_147 . V_148 ;
V_278 -> V_220 = V_119 -> V_47 . V_125 -> V_147 . V_149 ;
V_278 -> V_142 . V_143 . V_284 = F_113 ( V_119 ) ;
memcpy ( & V_278 -> V_142 . V_143 . V_215 , & V_119 -> V_47 . V_125 -> V_153 , 128 ) ;
if ( V_119 -> V_280 )
F_189 ( V_281 , & V_279 , NULL ) ;
V_119 -> V_291 . V_292 ++ ;
return V_94 ;
}
int F_192 ( struct V_118 * V_119 , unsigned long V_249 )
{
unsigned char V_293 = 1 ;
unsigned int V_294 ;
V_201 V_295 ;
int V_94 ;
if ( V_249 == V_296 ) {
if ( F_193 ( V_119 , 163 , & V_293 , 1 ) )
return - V_85 ;
V_249 = V_297 ;
} else if ( V_249 == V_298 ) {
if ( F_194 ( V_119 , 163 , & V_293 , 1 ) )
return - V_85 ;
V_249 = F_195 ( V_119 , V_297 ) ;
}
V_94 = F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_300 ) ,
V_119 -> V_47 . V_141 . V_139 , 128 ) ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_301 ) ,
V_119 -> V_131 -> V_142 . V_143 . V_212 , 128 ) ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_218 ) ,
& V_119 -> V_47 . V_125 -> V_147 , 16 ) ;
V_294 = F_113 ( V_119 ) ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_302 ) ,
& V_294 , 4 ) ;
V_94 |= F_193 ( V_119 ,
V_249 + F_196 ( struct V_299 , V_303 ) ,
& V_119 -> V_47 . V_141 . V_138 , 4 ) ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_304 ) ,
& V_119 -> V_47 . V_125 -> V_152 , 4 ) ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_305 ) ,
& V_119 -> V_47 . V_125 -> V_150 , 8 ) ;
V_295 = V_119 -> V_47 . V_125 -> V_151 >> 8 ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_306 ) ,
& V_295 , 8 ) ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_307 ) ,
& V_119 -> V_131 -> V_142 . V_143 . V_144 , 64 ) ;
V_94 |= F_193 ( V_119 , V_249 + F_196 ( struct V_299 , V_308 ) ,
& V_119 -> V_47 . V_125 -> V_153 , 128 ) ;
return V_94 ? - V_85 : 0 ;
}
int F_197 ( struct V_118 * V_119 , unsigned long V_149 )
{
F_78 ( & V_119 -> V_47 . V_141 . V_138 ) ;
F_79 ( V_119 -> V_47 . V_141 . V_139 ) ;
F_80 ( V_119 -> V_131 -> V_142 . V_143 . V_144 ) ;
return F_192 ( V_119 , V_149 ) ;
}
static void F_198 ( struct V_118 * V_119 )
{
F_140 ( V_245 , V_119 ) ;
F_114 ( V_246 , V_119 ) ;
F_112 ( V_119 ) ;
}
static void F_199 ( struct V_15 * V_15 )
{
unsigned int V_127 ;
struct V_118 * V_119 ;
F_69 (i, vcpu, kvm) {
F_198 ( V_119 ) ;
}
}
static void F_200 ( struct V_118 * V_119 )
{
F_140 ( V_246 , V_119 ) ;
F_114 ( V_245 , V_119 ) ;
F_112 ( V_119 ) ;
}
void F_137 ( struct V_118 * V_119 )
{
int V_127 , V_72 , V_309 = 0 ;
if ( ! F_130 ( V_119 ) )
return;
F_201 ( V_119 -> V_120 , 1 ) ;
F_44 ( & V_119 -> V_15 -> V_47 . V_117 ) ;
V_72 = F_30 ( & V_119 -> V_15 -> V_72 ) ;
for ( V_127 = 0 ; V_127 < V_72 ; V_127 ++ ) {
if ( ! F_130 ( V_119 -> V_15 -> V_128 [ V_127 ] ) )
V_309 ++ ;
}
if ( V_309 == 0 ) {
F_200 ( V_119 ) ;
} else if ( V_309 == 1 ) {
F_199 ( V_119 -> V_15 ) ;
}
F_87 ( V_160 , & V_119 -> V_47 . V_125 -> V_146 ) ;
V_119 -> V_47 . V_125 -> V_310 = 0xffff ;
F_45 ( & V_119 -> V_15 -> V_47 . V_117 ) ;
return;
}
void F_92 ( struct V_118 * V_119 )
{
int V_127 , V_72 , V_309 = 0 ;
struct V_118 * V_311 = NULL ;
if ( F_130 ( V_119 ) )
return;
F_201 ( V_119 -> V_120 , 0 ) ;
F_44 ( & V_119 -> V_15 -> V_47 . V_117 ) ;
V_72 = F_30 ( & V_119 -> V_15 -> V_72 ) ;
F_44 ( & V_119 -> V_47 . V_186 . V_71 ) ;
F_85 ( V_160 , & V_119 -> V_47 . V_125 -> V_146 ) ;
V_119 -> V_47 . V_186 . V_312 &=
~ ( V_313 | V_314 ) ;
F_45 ( & V_119 -> V_47 . V_186 . V_71 ) ;
F_198 ( V_119 ) ;
for ( V_127 = 0 ; V_127 < V_72 ; V_127 ++ ) {
if ( ! F_130 ( V_119 -> V_15 -> V_128 [ V_127 ] ) ) {
V_309 ++ ;
V_311 = V_119 -> V_15 -> V_128 [ V_127 ] ;
}
}
if ( V_309 == 1 ) {
F_200 ( V_311 ) ;
}
F_45 ( & V_119 -> V_15 -> V_47 . V_117 ) ;
return;
}
static int F_202 ( struct V_118 * V_119 ,
struct V_61 * V_62 )
{
int V_17 ;
if ( V_62 -> V_63 )
return - V_14 ;
switch ( V_62 -> V_62 ) {
case V_26 :
if ( ! V_119 -> V_15 -> V_47 . V_116 ) {
V_119 -> V_15 -> V_47 . V_116 = 1 ;
F_203 ( V_119 -> V_15 ) ;
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
struct V_118 * V_119 = V_10 -> V_80 ;
void T_2 * V_81 = ( void T_2 * ) V_12 ;
int V_68 ;
long V_17 ;
switch ( V_11 ) {
case V_82 : {
struct V_83 V_84 ;
V_17 = - V_85 ;
if ( F_38 ( & V_84 , V_81 , sizeof( V_84 ) ) )
break;
V_17 = F_148 ( V_119 , & V_84 ) ;
break;
}
case V_315 :
V_68 = F_31 ( & V_119 -> V_15 -> V_75 ) ;
V_17 = F_197 ( V_119 , V_12 ) ;
F_33 ( & V_119 -> V_15 -> V_75 , V_68 ) ;
break;
case V_316 : {
T_3 V_218 ;
V_17 = - V_85 ;
if ( F_38 ( & V_218 , V_81 , sizeof( V_218 ) ) )
break;
V_17 = F_129 ( V_119 , V_218 ) ;
break;
}
case V_317 :
V_17 = F_121 ( V_119 ) ;
break;
case V_318 :
case V_319 : {
struct V_195 V_196 ;
V_17 = - V_85 ;
if ( F_38 ( & V_196 , V_81 , sizeof( V_196 ) ) )
break;
if ( V_11 == V_318 )
V_17 = F_119 ( V_119 , & V_196 ) ;
else
V_17 = F_117 ( V_119 , & V_196 ) ;
break;
}
#ifdef F_15
case V_320 : {
struct V_321 V_322 ;
if ( F_38 ( & V_322 , V_81 , sizeof( V_322 ) ) ) {
V_17 = - V_85 ;
break;
}
if ( ! F_60 ( V_119 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_205 ( V_119 -> V_47 . V_46 , V_322 . V_323 ,
V_322 . V_324 , V_322 . V_325 ) ;
break;
}
case V_326 : {
struct V_321 V_322 ;
if ( F_38 ( & V_322 , V_81 , sizeof( V_322 ) ) ) {
V_17 = - V_85 ;
break;
}
if ( ! F_60 ( V_119 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_206 ( V_119 -> V_47 . V_46 , V_322 . V_324 ,
V_322 . V_325 ) ;
break;
}
#endif
case V_327 : {
V_17 = F_144 ( V_12 , V_119 -> V_47 . V_46 ) ;
if ( ! F_145 ( V_17 ) )
V_17 = 0 ;
break;
}
case V_86 :
{
struct V_61 V_62 ;
V_17 = - V_85 ;
if ( F_38 ( & V_62 , V_81 , sizeof( V_62 ) ) )
break;
V_17 = F_202 ( V_119 , & V_62 ) ;
break;
}
default:
V_17 = - V_93 ;
}
return V_17 ;
}
int F_207 ( struct V_118 * V_119 , struct V_328 * V_329 )
{
#ifdef F_15
if ( ( V_329 -> V_330 == V_331 )
&& ( F_60 ( V_119 -> V_15 ) ) ) {
V_329 -> V_332 = F_208 ( V_119 -> V_47 . V_125 ) ;
F_209 ( V_329 -> V_332 ) ;
return 0 ;
}
#endif
return V_333 ;
}
void F_210 ( struct V_15 * V_15 , struct V_41 * free ,
struct V_41 * V_334 )
{
}
int F_211 ( struct V_15 * V_15 , struct V_41 * V_56 ,
unsigned long V_51 )
{
return 0 ;
}
void F_212 ( struct V_15 * V_15 )
{
}
int F_213 ( struct V_15 * V_15 ,
struct V_41 * V_42 ,
struct V_335 * V_336 ,
enum V_337 V_338 )
{
if ( V_336 -> V_339 & 0xffffful )
return - V_14 ;
if ( V_336 -> V_340 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_214 ( struct V_15 * V_15 ,
struct V_335 * V_336 ,
const struct V_41 * V_341 ,
enum V_337 V_338 )
{
int V_94 ;
if ( V_341 -> V_339 == V_336 -> V_339 &&
V_341 -> V_50 * V_244 == V_336 -> V_342 &&
V_341 -> V_51 * V_244 == V_336 -> V_340 )
return;
V_94 = F_205 ( V_15 -> V_47 . V_46 , V_336 -> V_339 ,
V_336 -> V_342 , V_336 -> V_340 ) ;
if ( V_94 )
F_215 ( V_343 L_11 ) ;
return;
}
void F_216 ( struct V_15 * V_15 )
{
}
void F_217 ( struct V_15 * V_15 ,
struct V_41 * V_56 )
{
}
static int T_7 F_218 ( void )
{
int V_67 ;
V_67 = F_219 ( NULL , sizeof( struct V_118 ) , 0 , V_344 ) ;
if ( V_67 )
return V_67 ;
V_2 = ( unsigned long * ) F_43 ( V_103 | V_345 ) ;
if ( ! V_2 ) {
F_220 () ;
return - V_100 ;
}
memcpy ( V_2 , V_346 . V_347 , 16 ) ;
V_2 [ 0 ] &= 0xff82fff3f4fc2000UL ;
V_2 [ 1 ] &= 0x005c000000000000UL ;
return 0 ;
}
static void T_8 F_221 ( void )
{
F_54 ( ( unsigned long ) V_2 ) ;
F_220 () ;
}
