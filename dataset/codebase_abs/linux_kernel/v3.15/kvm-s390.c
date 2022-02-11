static inline int F_1 ( unsigned long V_1 )
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
V_16 = 1 ;
break;
case V_30 :
case V_31 :
V_16 = V_32 ;
break;
case V_33 :
V_16 = V_34 ;
break;
case V_35 :
V_16 = V_36 ;
break;
default:
V_16 = 0 ;
}
return V_16 ;
}
int F_16 ( struct V_37 * V_37 ,
struct V_38 * log )
{
return 0 ;
}
static int F_17 ( struct V_37 * V_37 , struct V_39 * V_40 )
{
int V_16 ;
if ( V_40 -> V_41 )
return - V_14 ;
switch ( V_40 -> V_40 ) {
case V_42 :
V_37 -> V_43 . V_44 = 1 ;
V_16 = 0 ;
break;
default:
V_16 = - V_14 ;
break;
}
return V_16 ;
}
long F_18 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_37 * V_37 = V_10 -> V_45 ;
void T_1 * V_46 = ( void T_1 * ) V_12 ;
int V_16 ;
switch ( V_11 ) {
case V_47 : {
struct V_48 V_49 ;
V_16 = - V_50 ;
if ( F_19 ( & V_49 , V_46 , sizeof( V_49 ) ) )
break;
V_16 = F_20 ( V_37 , & V_49 ) ;
break;
}
case V_51 : {
struct V_39 V_40 ;
V_16 = - V_50 ;
if ( F_19 ( & V_40 , V_46 , sizeof( V_40 ) ) )
break;
V_16 = F_17 ( V_37 , & V_40 ) ;
break;
}
case V_52 : {
struct V_53 V_54 ;
V_16 = - V_14 ;
if ( V_37 -> V_43 . V_44 ) {
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_21 ( V_37 , & V_54 , 0 , 0 ) ;
V_16 = 0 ;
}
break;
}
default:
V_16 = - V_55 ;
}
return V_16 ;
}
int F_22 ( struct V_37 * V_37 , unsigned long type )
{
int V_56 ;
char V_57 [ 16 ] ;
static unsigned long V_58 ;
V_56 = - V_14 ;
#ifdef F_15
if ( type & ~ V_59 )
goto V_60;
if ( ( type & V_59 ) && ( ! F_23 ( V_61 ) ) )
goto V_60;
#else
if ( type )
goto V_60;
#endif
V_56 = F_13 () ;
if ( V_56 )
goto V_60;
V_56 = - V_62 ;
V_37 -> V_43 . V_63 = (struct V_64 * ) F_24 ( V_65 ) ;
if ( ! V_37 -> V_43 . V_63 )
goto V_60;
F_25 ( & V_66 ) ;
V_58 = ( V_58 + 16 ) & 0x7f0 ;
V_37 -> V_43 . V_63 = (struct V_64 * ) ( ( char * ) V_37 -> V_43 . V_63 + V_58 ) ;
F_26 ( & V_66 ) ;
sprintf ( V_57 , L_1 , V_67 -> V_68 ) ;
V_37 -> V_43 . V_69 = F_27 ( V_57 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_37 -> V_43 . V_69 )
goto V_70;
F_28 ( & V_37 -> V_43 . V_71 . V_72 ) ;
F_29 ( & V_37 -> V_43 . V_71 . V_73 ) ;
F_30 ( V_37 -> V_43 . V_69 , & V_74 ) ;
F_31 ( V_37 , 3 , L_2 , L_3 ) ;
if ( type & V_59 ) {
V_37 -> V_43 . V_75 = NULL ;
} else {
V_37 -> V_43 . V_75 = F_32 ( V_67 -> V_76 ) ;
if ( ! V_37 -> V_43 . V_75 )
goto V_77;
V_37 -> V_43 . V_75 -> V_78 = V_37 ;
V_37 -> V_43 . V_75 -> V_79 = 0 ;
}
V_37 -> V_43 . V_80 = 0 ;
V_37 -> V_43 . V_44 = 0 ;
return 0 ;
V_77:
F_33 ( V_37 -> V_43 . V_69 ) ;
V_70:
F_34 ( ( unsigned long ) ( V_37 -> V_43 . V_63 ) ) ;
V_60:
return V_56 ;
}
void F_35 ( struct V_81 * V_82 )
{
F_36 ( V_82 , 3 , L_2 , L_4 ) ;
F_37 ( V_82 -> V_83 ) ;
F_38 ( V_82 ) ;
if ( ! F_39 ( V_82 -> V_37 ) ) {
F_40 ( 63 - V_82 -> V_83 ,
( unsigned long * ) & V_82 -> V_37 -> V_43 . V_63 -> V_84 ) ;
if ( V_82 -> V_37 -> V_43 . V_63 -> V_85 [ V_82 -> V_83 ] . V_86 ==
( V_87 ) V_82 -> V_43 . V_88 )
V_82 -> V_37 -> V_43 . V_63 -> V_85 [ V_82 -> V_83 ] . V_86 = 0 ;
}
F_41 () ;
if ( F_39 ( V_82 -> V_37 ) )
F_42 ( V_82 -> V_43 . V_75 ) ;
if ( V_82 -> V_43 . V_88 -> V_89 )
F_43 ( F_44 (
V_82 -> V_43 . V_88 -> V_89 >> V_90 ) ) ;
F_34 ( ( unsigned long ) ( V_82 -> V_43 . V_88 ) ) ;
F_45 ( V_82 ) ;
F_46 ( V_91 , V_82 ) ;
}
static void F_47 ( struct V_37 * V_37 )
{
unsigned int V_92 ;
struct V_81 * V_82 ;
F_48 (i, vcpu, kvm)
F_35 ( V_82 ) ;
F_49 ( & V_37 -> V_72 ) ;
for ( V_92 = 0 ; V_92 < F_50 ( & V_37 -> V_93 ) ; V_92 ++ )
V_37 -> V_94 [ V_92 ] = NULL ;
F_51 ( & V_37 -> V_93 , 0 ) ;
F_52 ( & V_37 -> V_72 ) ;
}
void F_53 ( struct V_37 * V_37 )
{
}
void F_54 ( struct V_37 * V_37 )
{
F_47 ( V_37 ) ;
F_34 ( ( unsigned long ) ( V_37 -> V_43 . V_63 ) ) ;
F_33 ( V_37 -> V_43 . V_69 ) ;
if ( ! F_39 ( V_37 ) )
F_42 ( V_37 -> V_43 . V_75 ) ;
F_55 ( V_37 ) ;
}
int F_56 ( struct V_81 * V_82 )
{
V_82 -> V_43 . V_95 = V_96 ;
F_38 ( V_82 ) ;
if ( F_39 ( V_82 -> V_37 ) ) {
V_82 -> V_43 . V_75 = F_32 ( V_67 -> V_76 ) ;
if ( ! V_82 -> V_43 . V_75 )
return - V_62 ;
V_82 -> V_43 . V_75 -> V_78 = V_82 -> V_37 ;
return 0 ;
}
V_82 -> V_43 . V_75 = V_82 -> V_37 -> V_43 . V_75 ;
V_82 -> V_97 -> V_98 = V_99 |
V_100 |
V_101 |
V_102 ;
return 0 ;
}
void F_57 ( struct V_81 * V_82 )
{
}
void F_58 ( struct V_81 * V_82 , int V_85 )
{
F_59 ( & V_82 -> V_43 . V_103 . V_104 ) ;
F_60 ( V_82 -> V_43 . V_103 . V_105 ) ;
F_61 ( V_82 -> V_43 . V_106 ) ;
F_62 ( & V_82 -> V_43 . V_107 . V_104 ) ;
F_63 ( V_82 -> V_43 . V_107 . V_105 ) ;
F_64 ( V_82 -> V_97 -> V_108 . V_109 . V_110 ) ;
F_65 ( V_82 -> V_43 . V_75 ) ;
F_66 ( V_111 , & V_82 -> V_43 . V_88 -> V_112 ) ;
}
void F_67 ( struct V_81 * V_82 )
{
F_68 ( V_111 , & V_82 -> V_43 . V_88 -> V_112 ) ;
F_69 ( V_82 -> V_43 . V_75 ) ;
F_59 ( & V_82 -> V_43 . V_107 . V_104 ) ;
F_60 ( V_82 -> V_43 . V_107 . V_105 ) ;
F_61 ( V_82 -> V_97 -> V_108 . V_109 . V_110 ) ;
F_62 ( & V_82 -> V_43 . V_103 . V_104 ) ;
F_63 ( V_82 -> V_43 . V_103 . V_105 ) ;
F_64 ( V_82 -> V_43 . V_106 ) ;
}
static void F_70 ( struct V_81 * V_82 )
{
V_82 -> V_43 . V_88 -> V_113 . V_114 = 0UL ;
V_82 -> V_43 . V_88 -> V_113 . V_115 = 0UL ;
F_71 ( V_82 , 0 ) ;
V_82 -> V_43 . V_88 -> V_116 = 0UL ;
V_82 -> V_43 . V_88 -> V_117 = 0UL ;
V_82 -> V_43 . V_88 -> V_118 = 0 ;
memset ( V_82 -> V_43 . V_88 -> V_119 , 0 , 16 * sizeof( V_87 ) ) ;
V_82 -> V_43 . V_88 -> V_119 [ 0 ] = 0xE0UL ;
V_82 -> V_43 . V_88 -> V_119 [ 14 ] = 0xC2000000UL ;
V_82 -> V_43 . V_107 . V_104 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_82 -> V_43 . V_88 -> V_120 = 1 ;
V_82 -> V_43 . V_88 -> V_121 = 0 ;
V_82 -> V_43 . V_95 = V_96 ;
F_38 ( V_82 ) ;
F_66 ( V_122 , & V_82 -> V_43 . V_88 -> V_112 ) ;
F_72 ( V_82 ) ;
}
int F_73 ( struct V_81 * V_82 )
{
return 0 ;
}
int F_74 ( struct V_81 * V_82 )
{
struct V_123 * V_124 ;
F_51 ( & V_82 -> V_43 . V_88 -> V_112 , V_125 |
V_126 |
V_122 |
V_127 ) ;
V_82 -> V_43 . V_88 -> V_128 = 6 ;
if ( F_1 ( 50 ) && F_1 ( 73 ) )
V_82 -> V_43 . V_88 -> V_128 |= 0x10 ;
V_82 -> V_43 . V_88 -> V_129 = 8 ;
V_82 -> V_43 . V_88 -> V_130 = 0xC1002001U ;
V_82 -> V_43 . V_88 -> V_131 = ( int ) ( long ) V_2 ;
if ( F_75 () ) {
V_124 = F_76 ( V_65 | V_132 ) ;
if ( V_124 ) {
V_82 -> V_43 . V_88 -> V_129 |= 0x80 ;
V_82 -> V_43 . V_88 -> V_129 &= ~ 0x08 ;
V_82 -> V_43 . V_88 -> V_89 = F_77 ( V_124 ) ;
}
}
F_78 ( & V_82 -> V_43 . V_133 , V_134 , V_135 ) ;
F_79 ( & V_82 -> V_43 . V_136 , V_137 ,
( unsigned long ) V_82 ) ;
V_82 -> V_43 . V_133 . V_138 = V_139 ;
F_80 ( & V_82 -> V_43 . V_140 ) ;
V_82 -> V_43 . V_140 . V_141 = 0xff ;
return 0 ;
}
struct V_81 * F_81 ( struct V_37 * V_37 ,
unsigned int V_142 )
{
struct V_81 * V_82 ;
struct V_143 * V_143 ;
int V_56 = - V_14 ;
if ( V_142 >= V_32 )
goto V_144;
V_56 = - V_62 ;
V_82 = F_82 ( V_91 , V_65 ) ;
if ( ! V_82 )
goto V_144;
V_143 = (struct V_143 * ) F_24 ( V_65 ) ;
if ( ! V_143 )
goto V_145;
V_82 -> V_43 . V_88 = & V_143 -> V_88 ;
V_82 -> V_43 . V_88 -> V_146 = ( unsigned long ) & V_143 -> V_147 ;
V_82 -> V_43 . V_88 -> V_148 = V_142 ;
if ( ! F_39 ( V_37 ) ) {
if ( ! V_37 -> V_43 . V_63 ) {
F_83 ( 1 ) ;
goto V_145;
}
if ( ! V_37 -> V_43 . V_63 -> V_85 [ V_142 ] . V_86 )
V_37 -> V_43 . V_63 -> V_85 [ V_142 ] . V_86 =
( V_87 ) V_82 -> V_43 . V_88 ;
V_82 -> V_43 . V_88 -> V_149 =
( V_150 ) ( ( ( V_87 ) V_37 -> V_43 . V_63 ) >> 32 ) ;
V_82 -> V_43 . V_88 -> V_151 = ( V_150 ) ( V_87 ) V_37 -> V_43 . V_63 ;
F_84 ( 63 - V_142 , ( unsigned long * ) & V_37 -> V_43 . V_63 -> V_84 ) ;
}
F_28 ( & V_82 -> V_43 . V_152 . V_72 ) ;
F_29 ( & V_82 -> V_43 . V_152 . V_73 ) ;
V_82 -> V_43 . V_152 . V_71 = & V_37 -> V_43 . V_71 ;
V_82 -> V_43 . V_152 . V_153 = & V_82 -> V_153 ;
V_82 -> V_43 . V_152 . V_112 = & V_82 -> V_43 . V_88 -> V_112 ;
V_56 = F_85 ( V_82 , V_37 , V_142 ) ;
if ( V_56 )
goto V_154;
F_31 ( V_37 , 3 , L_5 , V_142 , V_82 ,
V_82 -> V_43 . V_88 ) ;
F_86 ( V_142 , V_82 , V_82 -> V_43 . V_88 ) ;
return V_82 ;
V_154:
F_34 ( ( unsigned long ) ( V_82 -> V_43 . V_88 ) ) ;
V_145:
F_46 ( V_91 , V_82 ) ;
V_144:
return F_87 ( V_56 ) ;
}
int F_88 ( struct V_81 * V_82 )
{
return F_89 ( V_82 ) ;
}
void F_90 ( struct V_81 * V_82 )
{
F_66 ( V_155 , & V_82 -> V_43 . V_88 -> V_156 ) ;
}
void F_91 ( struct V_81 * V_82 )
{
F_68 ( V_155 , & V_82 -> V_43 . V_88 -> V_156 ) ;
}
void F_92 ( struct V_81 * V_82 )
{
F_66 ( V_157 , & V_82 -> V_43 . V_88 -> V_112 ) ;
while ( V_82 -> V_43 . V_88 -> V_158 & V_159 )
F_93 () ;
}
void F_94 ( struct V_81 * V_82 )
{
F_90 ( V_82 ) ;
F_92 ( V_82 ) ;
}
static void V_6 ( struct V_75 * V_75 , unsigned long V_160 )
{
int V_92 ;
struct V_37 * V_37 = V_75 -> V_78 ;
struct V_81 * V_82 ;
F_48 (i, vcpu, kvm) {
if ( V_82 -> V_43 . V_88 -> V_161 == ( V_160 & ~ 0x1000UL ) ) {
F_36 ( V_82 , 2 , L_6 , V_160 ) ;
F_95 ( V_162 , V_82 ) ;
F_94 ( V_82 ) ;
}
}
}
int F_96 ( struct V_81 * V_82 )
{
F_97 () ;
return 0 ;
}
static int F_98 ( struct V_81 * V_82 ,
struct V_163 * V_164 )
{
int V_16 = - V_14 ;
switch ( V_164 -> V_142 ) {
case V_165 :
V_16 = F_99 ( V_82 -> V_43 . V_88 -> V_118 ,
( V_166 T_1 * ) V_164 -> V_115 ) ;
break;
case V_167 :
V_16 = F_99 ( V_82 -> V_43 . V_88 -> V_168 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_170 :
V_16 = F_99 ( V_82 -> V_43 . V_88 -> V_116 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_171 :
V_16 = F_99 ( V_82 -> V_43 . V_88 -> V_117 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_172 :
V_16 = F_99 ( V_82 -> V_43 . V_95 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_173 :
V_16 = F_99 ( V_82 -> V_43 . V_174 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_175 :
V_16 = F_99 ( V_82 -> V_43 . V_176 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_177 :
V_16 = F_99 ( V_82 -> V_43 . V_88 -> V_121 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_178 :
V_16 = F_99 ( V_82 -> V_43 . V_88 -> V_120 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_100 ( struct V_81 * V_82 ,
struct V_163 * V_164 )
{
int V_16 = - V_14 ;
switch ( V_164 -> V_142 ) {
case V_165 :
V_16 = F_101 ( V_82 -> V_43 . V_88 -> V_118 ,
( V_166 T_1 * ) V_164 -> V_115 ) ;
break;
case V_167 :
V_16 = F_101 ( V_82 -> V_43 . V_88 -> V_168 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_170 :
V_16 = F_101 ( V_82 -> V_43 . V_88 -> V_116 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_171 :
V_16 = F_101 ( V_82 -> V_43 . V_88 -> V_117 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_172 :
V_16 = F_101 ( V_82 -> V_43 . V_95 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_173 :
V_16 = F_101 ( V_82 -> V_43 . V_174 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_175 :
V_16 = F_101 ( V_82 -> V_43 . V_176 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_177 :
V_16 = F_101 ( V_82 -> V_43 . V_88 -> V_121 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
case V_178 :
V_16 = F_101 ( V_82 -> V_43 . V_88 -> V_120 ,
( V_169 T_1 * ) V_164 -> V_115 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_102 ( struct V_81 * V_82 )
{
F_70 ( V_82 ) ;
return 0 ;
}
int F_103 ( struct V_81 * V_82 , struct V_179 * V_109 )
{
memcpy ( & V_82 -> V_97 -> V_108 . V_109 . V_180 , & V_109 -> V_180 , sizeof( V_109 -> V_180 ) ) ;
return 0 ;
}
int F_104 ( struct V_81 * V_82 , struct V_179 * V_109 )
{
memcpy ( & V_109 -> V_180 , & V_82 -> V_97 -> V_108 . V_109 . V_180 , sizeof( V_109 -> V_180 ) ) ;
return 0 ;
}
int F_105 ( struct V_81 * V_82 ,
struct V_181 * V_182 )
{
memcpy ( & V_82 -> V_97 -> V_108 . V_109 . V_110 , & V_182 -> V_110 , sizeof( V_182 -> V_110 ) ) ;
memcpy ( & V_82 -> V_43 . V_88 -> V_119 , & V_182 -> V_183 , sizeof( V_182 -> V_183 ) ) ;
F_64 ( V_82 -> V_97 -> V_108 . V_109 . V_110 ) ;
return 0 ;
}
int F_106 ( struct V_81 * V_82 ,
struct V_181 * V_182 )
{
memcpy ( & V_182 -> V_110 , & V_82 -> V_97 -> V_108 . V_109 . V_110 , sizeof( V_182 -> V_110 ) ) ;
memcpy ( & V_182 -> V_183 , & V_82 -> V_43 . V_88 -> V_119 , sizeof( V_182 -> V_183 ) ) ;
return 0 ;
}
int F_107 ( struct V_81 * V_82 , struct V_184 * V_185 )
{
if ( F_108 ( V_185 -> V_104 ) )
return - V_14 ;
memcpy ( & V_82 -> V_43 . V_107 . V_105 , & V_185 -> V_105 , sizeof( V_185 -> V_105 ) ) ;
V_82 -> V_43 . V_107 . V_104 = V_185 -> V_104 ;
F_62 ( & V_82 -> V_43 . V_107 . V_104 ) ;
F_63 ( V_82 -> V_43 . V_107 . V_105 ) ;
return 0 ;
}
int F_109 ( struct V_81 * V_82 , struct V_184 * V_185 )
{
memcpy ( & V_185 -> V_105 , & V_82 -> V_43 . V_107 . V_105 , sizeof( V_185 -> V_105 ) ) ;
V_185 -> V_104 = V_82 -> V_43 . V_107 . V_104 ;
return 0 ;
}
static int F_110 ( struct V_81 * V_82 , T_2 V_186 )
{
int V_56 = 0 ;
if ( ! ( F_50 ( & V_82 -> V_43 . V_88 -> V_112 ) & V_122 ) )
V_56 = - V_187 ;
else {
V_82 -> V_97 -> V_188 = V_186 . V_114 ;
V_82 -> V_97 -> V_189 = V_186 . V_115 ;
}
return V_56 ;
}
int F_111 ( struct V_81 * V_82 ,
struct V_190 * V_191 )
{
return - V_14 ;
}
int F_112 ( struct V_81 * V_82 ,
struct V_192 * V_193 )
{
return - V_14 ;
}
int F_113 ( struct V_81 * V_82 ,
struct V_194 * V_195 )
{
return - V_14 ;
}
int F_114 ( struct V_81 * V_82 ,
struct V_194 * V_195 )
{
return - V_14 ;
}
static int F_115 ( struct V_81 * V_82 )
{
while ( F_116 ( V_162 , V_82 ) ) {
int V_56 ;
V_56 = F_117 ( V_82 -> V_43 . V_75 ,
V_82 -> V_43 . V_88 -> V_161 ,
V_196 * 2 ) ;
if ( V_56 )
return V_56 ;
F_91 ( V_82 ) ;
}
return 0 ;
}
static long F_118 ( struct V_81 * V_82 )
{
long V_56 ;
T_3 V_197 = F_119 ( V_67 -> V_198 . V_199 , V_82 -> V_43 . V_75 ) ;
struct V_200 * V_76 = V_67 -> V_76 ;
F_120 ( & V_76 -> V_201 ) ;
V_56 = F_121 ( V_67 , V_76 , V_197 , 1 , 1 , 0 , NULL , NULL ) ;
F_122 ( & V_76 -> V_201 ) ;
return V_56 ;
}
static void F_123 ( struct V_81 * V_82 , bool V_202 ,
unsigned long V_203 )
{
struct V_48 V_204 ;
V_204 . V_205 = V_203 ;
if ( V_202 ) {
V_204 . type = V_206 ;
F_83 ( F_124 ( V_82 , & V_204 ) ) ;
} else {
V_204 . type = V_207 ;
F_83 ( F_20 ( V_82 -> V_37 , & V_204 ) ) ;
}
}
void F_125 ( struct V_81 * V_82 ,
struct V_208 * V_209 )
{
F_126 ( V_82 , V_209 -> V_43 . V_95 ) ;
F_123 ( V_82 , true , V_209 -> V_43 . V_95 ) ;
}
void F_127 ( struct V_81 * V_82 ,
struct V_208 * V_209 )
{
F_128 ( V_82 , V_209 -> V_43 . V_95 ) ;
F_123 ( V_82 , false , V_209 -> V_43 . V_95 ) ;
}
void F_129 ( struct V_81 * V_82 ,
struct V_208 * V_209 )
{
}
bool F_130 ( struct V_81 * V_82 )
{
return true ;
}
static int F_131 ( struct V_81 * V_82 )
{
T_3 V_210 ;
struct V_211 V_43 ;
int V_56 ;
if ( V_82 -> V_43 . V_95 == V_96 )
return 0 ;
if ( ( V_82 -> V_43 . V_88 -> V_113 . V_114 & V_82 -> V_43 . V_176 ) !=
V_82 -> V_43 . V_174 )
return 0 ;
if ( F_132 ( V_82 ) )
return 0 ;
if ( F_89 ( V_82 ) )
return 0 ;
if ( ! ( V_82 -> V_43 . V_88 -> V_119 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_82 -> V_43 . V_75 -> V_79 )
return 0 ;
V_210 = F_119 ( V_67 -> V_198 . V_199 , V_82 -> V_43 . V_75 ) ;
if ( F_133 ( V_82 , & V_43 . V_95 , V_82 -> V_43 . V_95 , 8 ) )
return 0 ;
V_56 = F_134 ( V_82 , V_67 -> V_198 . V_199 , V_210 , & V_43 ) ;
return V_56 ;
}
static int F_135 ( struct V_81 * V_82 )
{
int V_56 , V_112 ;
F_136 ( V_82 ) ;
memcpy ( & V_82 -> V_43 . V_88 -> V_212 , & V_82 -> V_97 -> V_108 . V_109 . V_180 [ 14 ] , 16 ) ;
if ( F_137 () )
F_138 () ;
if ( F_139 ( V_213 ) )
F_140 () ;
if ( ! F_39 ( V_82 -> V_37 ) )
F_141 ( V_82 ) ;
V_56 = F_115 ( V_82 ) ;
if ( V_56 )
return V_56 ;
V_82 -> V_43 . V_88 -> V_214 = 0 ;
V_112 = F_50 ( & V_82 -> V_43 . V_88 -> V_112 ) ;
F_36 ( V_82 , 6 , L_7 , V_112 ) ;
F_142 ( V_82 , V_112 ) ;
return 0 ;
}
static int F_143 ( struct V_81 * V_82 , int V_215 )
{
int V_56 = - 1 ;
F_36 ( V_82 , 6 , L_8 ,
V_82 -> V_43 . V_88 -> V_214 ) ;
F_144 ( V_82 , V_82 -> V_43 . V_88 -> V_214 ) ;
if ( V_215 >= 0 ) {
V_56 = 0 ;
} else if ( F_39 ( V_82 -> V_37 ) ) {
V_82 -> V_97 -> V_215 = V_216 ;
V_82 -> V_97 -> V_217 . V_218 =
V_67 -> V_198 . V_199 ;
V_82 -> V_97 -> V_217 . V_219 = 0x10 ;
V_56 = - V_220 ;
} else if ( V_67 -> V_198 . V_221 ) {
F_145 ( V_82 ) ;
V_67 -> V_198 . V_221 = 0 ;
if ( F_131 ( V_82 ) ||
( F_118 ( V_82 ) >= 0 ) )
V_56 = 0 ;
}
if ( V_56 == - 1 ) {
F_36 ( V_82 , 3 , L_2 , L_9 ) ;
F_146 ( V_82 ) ;
V_56 = F_147 ( V_82 , V_222 ) ;
}
memcpy ( & V_82 -> V_97 -> V_108 . V_109 . V_180 [ 14 ] , & V_82 -> V_43 . V_88 -> V_212 , 16 ) ;
if ( V_56 == 0 ) {
if ( F_39 ( V_82 -> V_37 ) )
V_56 = V_82 -> V_43 . V_88 -> V_214 ? - V_223 : 0 ;
else
V_56 = F_148 ( V_82 ) ;
}
return V_56 ;
}
bool F_75 ( void )
{
if ( ! V_224 )
return false ;
if ( ! V_225 )
return false ;
return true ;
}
static int F_149 ( struct V_81 * V_82 )
{
int V_56 , V_215 ;
V_82 -> V_226 = F_150 ( & V_82 -> V_37 -> V_227 ) ;
do {
V_56 = F_135 ( V_82 ) ;
if ( V_56 )
break;
F_151 ( & V_82 -> V_37 -> V_227 , V_82 -> V_226 ) ;
F_152 () ;
F_153 () ;
F_154 () ;
V_215 = F_155 ( V_82 -> V_43 . V_88 ,
V_82 -> V_97 -> V_108 . V_109 . V_180 ) ;
F_156 () ;
V_82 -> V_226 = F_150 ( & V_82 -> V_37 -> V_227 ) ;
V_56 = F_143 ( V_82 , V_215 ) ;
} while ( ! F_157 ( V_67 ) && ! V_56 );
F_151 ( & V_82 -> V_37 -> V_227 , V_82 -> V_226 ) ;
return V_56 ;
}
int F_158 ( struct V_81 * V_82 , struct V_228 * V_228 )
{
int V_56 ;
T_4 V_229 ;
if ( V_82 -> V_230 )
F_159 ( V_231 , & V_82 -> V_232 , & V_229 ) ;
F_68 ( V_122 , & V_82 -> V_43 . V_88 -> V_112 ) ;
switch ( V_228 -> V_215 ) {
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_216 :
case V_237 :
break;
default:
F_97 () ;
}
V_82 -> V_43 . V_88 -> V_113 . V_114 = V_228 -> V_188 ;
V_82 -> V_43 . V_88 -> V_113 . V_115 = V_228 -> V_189 ;
if ( V_228 -> V_238 & V_99 ) {
V_228 -> V_238 &= ~ V_99 ;
F_71 ( V_82 , V_228 -> V_108 . V_109 . V_161 ) ;
}
if ( V_228 -> V_238 & V_102 ) {
V_228 -> V_238 &= ~ V_102 ;
memcpy ( & V_82 -> V_43 . V_88 -> V_119 , & V_228 -> V_108 . V_109 . V_183 , 128 ) ;
F_71 ( V_82 , V_228 -> V_108 . V_109 . V_161 ) ;
}
F_160 () ;
V_56 = F_149 ( V_82 ) ;
if ( F_157 ( V_67 ) && ! V_56 ) {
V_228 -> V_215 = V_235 ;
V_56 = - V_239 ;
}
if ( V_56 == - V_223 ) {
V_228 -> V_215 = V_233 ;
V_228 -> V_240 . V_214 = V_82 -> V_43 . V_88 -> V_214 ;
V_228 -> V_240 . V_241 = V_82 -> V_43 . V_88 -> V_241 ;
V_228 -> V_240 . V_242 = V_82 -> V_43 . V_88 -> V_242 ;
V_56 = 0 ;
}
if ( V_56 == - V_220 ) {
V_56 = 0 ;
}
V_228 -> V_188 = V_82 -> V_43 . V_88 -> V_113 . V_114 ;
V_228 -> V_189 = V_82 -> V_43 . V_88 -> V_113 . V_115 ;
V_228 -> V_108 . V_109 . V_161 = V_82 -> V_43 . V_88 -> V_161 ;
memcpy ( & V_228 -> V_108 . V_109 . V_183 , & V_82 -> V_43 . V_88 -> V_119 , 128 ) ;
if ( V_82 -> V_230 )
F_159 ( V_231 , & V_229 , NULL ) ;
V_82 -> V_243 . V_244 ++ ;
return V_56 ;
}
static int F_161 ( struct V_81 * V_82 , V_169 V_245 , void * V_246 ,
unsigned long V_247 , int V_161 )
{
if ( V_161 )
return F_162 ( V_82 , V_245 , V_246 , V_247 ) ;
else
return F_163 ( V_82 , V_245 , V_246 , V_247 ) ;
}
int F_164 ( struct V_81 * V_82 , unsigned long V_115 )
{
unsigned char V_248 = 1 ;
int V_161 ;
V_169 V_249 ;
if ( V_115 == V_250 ) {
if ( F_163 ( V_82 , 163ul , & V_248 , 1 ) )
return - V_50 ;
V_115 = V_251 ;
V_161 = 0 ;
} else if ( V_115 == V_252 ) {
if ( F_162 ( V_82 , 163ul , & V_248 , 1 ) )
return - V_50 ;
V_115 = V_251 ;
V_161 = 1 ;
} else
V_161 = 0 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_254 ) ,
V_82 -> V_43 . V_107 . V_105 , 128 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_255 ) ,
V_82 -> V_97 -> V_108 . V_109 . V_180 , 128 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_186 ) ,
& V_82 -> V_43 . V_88 -> V_113 , 16 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_256 ) ,
& V_82 -> V_43 . V_88 -> V_161 , 4 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 ,
V_115 + F_165 ( struct V_253 , V_257 ) ,
& V_82 -> V_43 . V_107 . V_104 , 4 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_258 ) ,
& V_82 -> V_43 . V_88 -> V_118 , 4 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_259 ) ,
& V_82 -> V_43 . V_88 -> V_116 , 8 , V_161 ) )
return - V_50 ;
V_249 = V_82 -> V_43 . V_88 -> V_117 >> 8 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_260 ) ,
& V_249 , 8 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 , V_115 + F_165 ( struct V_253 , V_261 ) ,
& V_82 -> V_97 -> V_108 . V_109 . V_110 , 64 , V_161 ) )
return - V_50 ;
if ( F_161 ( V_82 ,
V_115 + F_165 ( struct V_253 , V_262 ) ,
& V_82 -> V_43 . V_88 -> V_119 , 128 , V_161 ) )
return - V_50 ;
return 0 ;
}
int F_166 ( struct V_81 * V_82 , unsigned long V_115 )
{
F_59 ( & V_82 -> V_43 . V_107 . V_104 ) ;
F_60 ( V_82 -> V_43 . V_107 . V_105 ) ;
F_61 ( V_82 -> V_97 -> V_108 . V_109 . V_110 ) ;
return F_164 ( V_82 , V_115 ) ;
}
static int F_167 ( struct V_81 * V_82 ,
struct V_39 * V_40 )
{
int V_16 ;
if ( V_40 -> V_41 )
return - V_14 ;
switch ( V_40 -> V_40 ) {
case V_25 :
if ( ! V_82 -> V_37 -> V_43 . V_80 ) {
V_82 -> V_37 -> V_43 . V_80 = 1 ;
F_168 ( V_82 -> V_37 ) ;
}
V_16 = 0 ;
break;
default:
V_16 = - V_14 ;
break;
}
return V_16 ;
}
long F_169 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_81 * V_82 = V_10 -> V_45 ;
void T_1 * V_46 = ( void T_1 * ) V_12 ;
int V_263 ;
long V_16 ;
switch ( V_11 ) {
case V_47 : {
struct V_48 V_49 ;
V_16 = - V_50 ;
if ( F_19 ( & V_49 , V_46 , sizeof( V_49 ) ) )
break;
V_16 = F_124 ( V_82 , & V_49 ) ;
break;
}
case V_264 :
V_263 = F_150 ( & V_82 -> V_37 -> V_227 ) ;
V_16 = F_166 ( V_82 , V_12 ) ;
F_151 ( & V_82 -> V_37 -> V_227 , V_263 ) ;
break;
case V_265 : {
T_2 V_186 ;
V_16 = - V_50 ;
if ( F_19 ( & V_186 , V_46 , sizeof( V_186 ) ) )
break;
V_16 = F_110 ( V_82 , V_186 ) ;
break;
}
case V_266 :
V_16 = F_102 ( V_82 ) ;
break;
case V_267 :
case V_268 : {
struct V_163 V_164 ;
V_16 = - V_50 ;
if ( F_19 ( & V_164 , V_46 , sizeof( V_164 ) ) )
break;
if ( V_11 == V_267 )
V_16 = F_100 ( V_82 , & V_164 ) ;
else
V_16 = F_98 ( V_82 , & V_164 ) ;
break;
}
#ifdef F_15
case V_269 : {
struct V_270 V_271 ;
if ( F_19 ( & V_271 , V_46 , sizeof( V_271 ) ) ) {
V_16 = - V_50 ;
break;
}
if ( ! F_39 ( V_82 -> V_37 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_170 ( V_82 -> V_43 . V_75 , V_271 . V_272 ,
V_271 . V_273 , V_271 . V_274 ) ;
break;
}
case V_275 : {
struct V_270 V_271 ;
if ( F_19 ( & V_271 , V_46 , sizeof( V_271 ) ) ) {
V_16 = - V_50 ;
break;
}
if ( ! F_39 ( V_82 -> V_37 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_171 ( V_82 -> V_43 . V_75 , V_271 . V_273 ,
V_271 . V_274 ) ;
break;
}
#endif
case V_276 : {
V_16 = F_119 ( V_12 , V_82 -> V_43 . V_75 ) ;
if ( ! F_172 ( V_16 ) )
V_16 = 0 ;
break;
}
case V_51 :
{
struct V_39 V_40 ;
V_16 = - V_50 ;
if ( F_19 ( & V_40 , V_46 , sizeof( V_40 ) ) )
break;
V_16 = F_167 ( V_82 , & V_40 ) ;
break;
}
default:
V_16 = - V_55 ;
}
return V_16 ;
}
int F_173 ( struct V_81 * V_82 , struct V_277 * V_278 )
{
#ifdef F_15
if ( ( V_278 -> V_279 == V_280 )
&& ( F_39 ( V_82 -> V_37 ) ) ) {
V_278 -> V_123 = F_174 ( V_82 -> V_43 . V_88 ) ;
F_175 ( V_278 -> V_123 ) ;
return 0 ;
}
#endif
return V_281 ;
}
void F_176 ( struct V_37 * V_37 , struct V_282 * free ,
struct V_282 * V_283 )
{
}
int F_177 ( struct V_37 * V_37 , struct V_282 * V_284 ,
unsigned long V_285 )
{
return 0 ;
}
void F_178 ( struct V_37 * V_37 )
{
}
int F_179 ( struct V_37 * V_37 ,
struct V_282 * V_286 ,
struct V_287 * V_288 ,
enum V_289 V_290 )
{
if ( V_288 -> V_291 & 0xffffful )
return - V_14 ;
if ( V_288 -> V_292 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_180 ( struct V_37 * V_37 ,
struct V_287 * V_288 ,
const struct V_282 * V_293 ,
enum V_289 V_290 )
{
int V_56 ;
if ( V_293 -> V_291 == V_288 -> V_291 &&
V_293 -> V_294 * V_196 == V_288 -> V_295 &&
V_293 -> V_285 * V_196 == V_288 -> V_292 )
return;
V_56 = F_170 ( V_37 -> V_43 . V_75 , V_288 -> V_291 ,
V_288 -> V_295 , V_288 -> V_292 ) ;
if ( V_56 )
F_181 ( V_296 L_10 ) ;
return;
}
void F_182 ( struct V_37 * V_37 )
{
}
void F_183 ( struct V_37 * V_37 ,
struct V_282 * V_284 )
{
}
static int T_5 F_184 ( void )
{
int V_297 ;
V_297 = F_185 ( NULL , sizeof( struct V_81 ) , 0 , V_298 ) ;
if ( V_297 )
return V_297 ;
V_2 = ( unsigned long * ) F_24 ( V_65 | V_299 ) ;
if ( ! V_2 ) {
F_186 () ;
return - V_62 ;
}
memcpy ( V_2 , V_300 . V_301 , 16 ) ;
V_2 [ 0 ] &= 0xff82fff3f4fc2000UL ;
V_2 [ 1 ] &= 0x005c000000000000UL ;
return 0 ;
}
static void T_6 F_187 ( void )
{
F_34 ( ( unsigned long ) V_2 ) ;
F_186 () ;
}
