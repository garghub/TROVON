int F_1 ( void * V_1 )
{
return 0 ;
}
void F_2 ( void * V_1 )
{
}
int F_3 ( void )
{
V_2 . V_3 = V_4 ;
F_4 ( & V_2 ) ;
return 0 ;
}
void F_5 ( void )
{
F_6 ( & V_2 ) ;
}
void F_7 ( void * V_5 )
{
}
int F_8 ( void * V_6 )
{
return 0 ;
}
void F_9 ( void )
{
}
long F_10 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned long V_10 )
{
if ( V_9 == V_11 )
return F_11 () ;
return - V_12 ;
}
int F_12 ( long V_13 )
{
int V_14 ;
switch ( V_13 ) {
case V_15 :
case V_16 :
case V_17 :
#ifdef F_13
case V_18 :
#endif
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_14 = 1 ;
break;
case V_24 :
case V_25 :
V_14 = V_26 ;
break;
case V_27 :
V_14 = V_28 ;
break;
case V_29 :
V_14 = V_30 ;
break;
default:
V_14 = 0 ;
}
return V_14 ;
}
int F_14 ( struct V_31 * V_31 ,
struct V_32 * log )
{
return 0 ;
}
long F_15 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned long V_10 )
{
struct V_31 * V_31 = V_8 -> V_33 ;
void T_1 * V_34 = ( void T_1 * ) V_10 ;
int V_14 ;
switch ( V_9 ) {
case V_35 : {
struct V_36 V_37 ;
V_14 = - V_38 ;
if ( F_16 ( & V_37 , V_34 , sizeof( V_37 ) ) )
break;
V_14 = F_17 ( V_31 , & V_37 ) ;
break;
}
default:
V_14 = - V_39 ;
}
return V_14 ;
}
int F_18 ( struct V_31 * V_31 , unsigned long type )
{
int V_40 ;
char V_41 [ 16 ] ;
V_40 = - V_12 ;
#ifdef F_13
if ( type & ~ V_42 )
goto V_43;
if ( ( type & V_42 ) && ( ! F_19 ( V_44 ) ) )
goto V_43;
#else
if ( type )
goto V_43;
#endif
V_40 = F_11 () ;
if ( V_40 )
goto V_43;
V_40 = - V_45 ;
V_31 -> V_46 . V_47 = (struct V_48 * ) F_20 ( V_49 ) ;
if ( ! V_31 -> V_46 . V_47 )
goto V_43;
sprintf ( V_41 , L_1 , V_50 -> V_51 ) ;
V_31 -> V_46 . V_52 = F_21 ( V_41 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_31 -> V_46 . V_52 )
goto V_53;
F_22 ( & V_31 -> V_46 . V_54 . V_55 ) ;
F_23 ( & V_31 -> V_46 . V_54 . V_56 ) ;
F_24 ( V_31 -> V_46 . V_52 , & V_57 ) ;
F_25 ( V_31 , 3 , L_2 , L_3 ) ;
if ( type & V_42 ) {
V_31 -> V_46 . V_58 = NULL ;
} else {
V_31 -> V_46 . V_58 = F_26 ( V_50 -> V_59 ) ;
if ( ! V_31 -> V_46 . V_58 )
goto V_60;
V_31 -> V_46 . V_58 -> V_61 = V_31 ;
}
V_31 -> V_46 . V_62 = 0 ;
return 0 ;
V_60:
F_27 ( V_31 -> V_46 . V_52 ) ;
V_53:
F_28 ( ( unsigned long ) ( V_31 -> V_46 . V_47 ) ) ;
V_43:
return V_40 ;
}
void F_29 ( struct V_63 * V_64 )
{
F_30 ( V_64 , 3 , L_2 , L_4 ) ;
F_31 ( V_64 -> V_65 ) ;
if ( ! F_32 ( V_64 -> V_31 ) ) {
F_33 ( 63 - V_64 -> V_65 ,
( unsigned long * ) & V_64 -> V_31 -> V_46 . V_47 -> V_66 ) ;
if ( V_64 -> V_31 -> V_46 . V_47 -> V_67 [ V_64 -> V_65 ] . V_68 ==
( V_69 ) V_64 -> V_46 . V_70 )
V_64 -> V_31 -> V_46 . V_47 -> V_67 [ V_64 -> V_65 ] . V_68 = 0 ;
}
F_34 () ;
if ( F_32 ( V_64 -> V_31 ) )
F_35 ( V_64 -> V_46 . V_58 ) ;
F_28 ( ( unsigned long ) ( V_64 -> V_46 . V_70 ) ) ;
F_36 ( V_64 ) ;
F_37 ( V_71 , V_64 ) ;
}
static void F_38 ( struct V_31 * V_31 )
{
unsigned int V_72 ;
struct V_63 * V_64 ;
F_39 (i, vcpu, kvm)
F_29 ( V_64 ) ;
F_40 ( & V_31 -> V_55 ) ;
for ( V_72 = 0 ; V_72 < F_41 ( & V_31 -> V_73 ) ; V_72 ++ )
V_31 -> V_74 [ V_72 ] = NULL ;
F_42 ( & V_31 -> V_73 , 0 ) ;
F_43 ( & V_31 -> V_55 ) ;
}
void F_44 ( struct V_31 * V_31 )
{
}
void F_45 ( struct V_31 * V_31 )
{
F_38 ( V_31 ) ;
F_28 ( ( unsigned long ) ( V_31 -> V_46 . V_47 ) ) ;
F_27 ( V_31 -> V_46 . V_52 ) ;
if ( ! F_32 ( V_31 ) )
F_35 ( V_31 -> V_46 . V_58 ) ;
}
int F_46 ( struct V_63 * V_64 )
{
if ( F_32 ( V_64 -> V_31 ) ) {
V_64 -> V_46 . V_58 = F_26 ( V_50 -> V_59 ) ;
if ( ! V_64 -> V_46 . V_58 )
return - V_45 ;
V_64 -> V_46 . V_58 -> V_61 = V_64 -> V_31 ;
return 0 ;
}
V_64 -> V_46 . V_58 = V_64 -> V_31 -> V_46 . V_58 ;
V_64 -> V_75 -> V_76 = V_77 |
V_78 |
V_79 |
V_80 ;
return 0 ;
}
void F_47 ( struct V_63 * V_64 )
{
}
void F_48 ( struct V_63 * V_64 , int V_67 )
{
F_49 ( & V_64 -> V_46 . V_81 ) ;
F_50 ( V_64 -> V_46 . V_82 ) ;
V_64 -> V_46 . V_83 . V_84 &= V_85 ;
F_51 ( & V_64 -> V_46 . V_83 ) ;
F_52 ( V_64 -> V_75 -> V_86 . V_87 . V_88 ) ;
F_53 ( V_64 -> V_46 . V_58 ) ;
F_54 ( V_89 , & V_64 -> V_46 . V_70 -> V_90 ) ;
}
void F_55 ( struct V_63 * V_64 )
{
F_56 ( V_89 , & V_64 -> V_46 . V_70 -> V_90 ) ;
F_57 ( V_64 -> V_46 . V_58 ) ;
F_49 ( & V_64 -> V_46 . V_83 ) ;
F_50 ( V_64 -> V_75 -> V_86 . V_87 . V_88 ) ;
F_51 ( & V_64 -> V_46 . V_81 ) ;
F_52 ( V_64 -> V_46 . V_82 ) ;
}
static void F_58 ( struct V_63 * V_64 )
{
V_64 -> V_46 . V_70 -> V_91 . V_92 = 0UL ;
V_64 -> V_46 . V_70 -> V_91 . V_93 = 0UL ;
F_59 ( V_64 , 0 ) ;
V_64 -> V_46 . V_70 -> V_94 = 0UL ;
V_64 -> V_46 . V_70 -> V_95 = 0UL ;
V_64 -> V_46 . V_70 -> V_96 = 0 ;
memset ( V_64 -> V_46 . V_70 -> V_97 , 0 , 16 * sizeof( V_69 ) ) ;
V_64 -> V_46 . V_70 -> V_97 [ 0 ] = 0xE0UL ;
V_64 -> V_46 . V_70 -> V_97 [ 14 ] = 0xC2000000UL ;
V_64 -> V_46 . V_83 . V_84 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_64 -> V_46 . V_70 -> V_98 = 1 ;
F_54 ( V_99 , & V_64 -> V_46 . V_70 -> V_90 ) ;
}
int F_60 ( struct V_63 * V_64 )
{
return 0 ;
}
int F_61 ( struct V_63 * V_64 )
{
F_42 ( & V_64 -> V_46 . V_70 -> V_90 , V_100 |
V_101 |
V_99 |
V_102 ) ;
V_64 -> V_46 . V_70 -> V_103 = 6 ;
V_64 -> V_46 . V_70 -> V_104 = 8 ;
V_64 -> V_46 . V_70 -> V_105 = 0xC1002001U ;
V_64 -> V_46 . V_70 -> V_106 = ( int ) ( long ) V_107 ;
F_62 ( & V_64 -> V_46 . V_108 , V_109 , V_110 ) ;
F_63 ( & V_64 -> V_46 . V_111 , V_112 ,
( unsigned long ) V_64 ) ;
V_64 -> V_46 . V_108 . V_113 = V_114 ;
F_64 ( & V_64 -> V_46 . V_115 ) ;
V_64 -> V_46 . V_115 . V_116 = 0xff ;
return 0 ;
}
struct V_63 * F_65 ( struct V_31 * V_31 ,
unsigned int V_117 )
{
struct V_63 * V_64 ;
int V_40 = - V_12 ;
if ( V_117 >= V_26 )
goto V_118;
V_40 = - V_45 ;
V_64 = F_66 ( V_71 , V_49 ) ;
if ( ! V_64 )
goto V_118;
V_64 -> V_46 . V_70 = (struct V_119 * )
F_20 ( V_49 ) ;
if ( ! V_64 -> V_46 . V_70 )
goto V_120;
V_64 -> V_46 . V_70 -> V_121 = V_117 ;
if ( ! F_32 ( V_31 ) ) {
if ( ! V_31 -> V_46 . V_47 ) {
F_67 ( 1 ) ;
goto V_120;
}
if ( ! V_31 -> V_46 . V_47 -> V_67 [ V_117 ] . V_68 )
V_31 -> V_46 . V_47 -> V_67 [ V_117 ] . V_68 =
( V_69 ) V_64 -> V_46 . V_70 ;
V_64 -> V_46 . V_70 -> V_122 =
( V_123 ) ( ( ( V_69 ) V_31 -> V_46 . V_47 ) >> 32 ) ;
V_64 -> V_46 . V_70 -> V_124 = ( V_123 ) ( V_69 ) V_31 -> V_46 . V_47 ;
F_68 ( 63 - V_117 , ( unsigned long * ) & V_31 -> V_46 . V_47 -> V_66 ) ;
}
F_22 ( & V_64 -> V_46 . V_125 . V_55 ) ;
F_23 ( & V_64 -> V_46 . V_125 . V_56 ) ;
V_64 -> V_46 . V_125 . V_54 = & V_31 -> V_46 . V_54 ;
F_69 ( & V_31 -> V_46 . V_54 . V_55 ) ;
V_31 -> V_46 . V_54 . V_125 [ V_117 ] = & V_64 -> V_46 . V_125 ;
V_64 -> V_46 . V_125 . V_126 = & V_64 -> V_126 ;
V_64 -> V_46 . V_125 . V_90 = & V_64 -> V_46 . V_70 -> V_90 ;
F_70 ( & V_31 -> V_46 . V_54 . V_55 ) ;
V_40 = F_71 ( V_64 , V_31 , V_117 ) ;
if ( V_40 )
goto V_127;
F_25 ( V_31 , 3 , L_5 , V_117 , V_64 ,
V_64 -> V_46 . V_70 ) ;
F_72 ( V_117 , V_64 , V_64 -> V_46 . V_70 ) ;
return V_64 ;
V_127:
F_28 ( ( unsigned long ) ( V_64 -> V_46 . V_70 ) ) ;
V_120:
F_37 ( V_71 , V_64 ) ;
V_118:
return F_73 ( V_40 ) ;
}
int F_74 ( struct V_63 * V_64 )
{
F_75 () ;
return 0 ;
}
void F_76 ( struct V_63 * V_64 )
{
F_54 ( V_128 , & V_64 -> V_46 . V_70 -> V_129 ) ;
}
void F_77 ( struct V_63 * V_64 )
{
F_56 ( V_128 , & V_64 -> V_46 . V_70 -> V_129 ) ;
}
void F_78 ( struct V_63 * V_64 )
{
F_54 ( V_130 , & V_64 -> V_46 . V_70 -> V_90 ) ;
while ( V_64 -> V_46 . V_70 -> V_131 & V_132 )
F_79 () ;
}
void F_80 ( struct V_63 * V_64 )
{
F_76 ( V_64 ) ;
F_78 ( V_64 ) ;
}
static void V_4 ( struct V_58 * V_58 , unsigned long V_133 )
{
int V_72 ;
struct V_31 * V_31 = V_58 -> V_61 ;
struct V_63 * V_64 ;
F_39 (i, vcpu, kvm) {
if ( V_64 -> V_46 . V_70 -> V_134 == ( V_133 & ~ 0x1000UL ) ) {
F_30 ( V_64 , 2 , L_6 , V_133 ) ;
F_81 ( V_135 , V_64 ) ;
F_80 ( V_64 ) ;
}
}
}
int F_82 ( struct V_63 * V_64 )
{
F_75 () ;
return 0 ;
}
static int F_83 ( struct V_63 * V_64 ,
struct V_136 * V_137 )
{
int V_14 = - V_12 ;
switch ( V_137 -> V_117 ) {
case V_138 :
V_14 = F_84 ( V_64 -> V_46 . V_70 -> V_96 ,
( V_139 T_1 * ) V_137 -> V_93 ) ;
break;
case V_140 :
V_14 = F_84 ( V_64 -> V_46 . V_70 -> V_141 ,
( V_142 T_1 * ) V_137 -> V_93 ) ;
break;
case V_143 :
V_14 = F_84 ( V_64 -> V_46 . V_70 -> V_94 ,
( V_142 T_1 * ) V_137 -> V_93 ) ;
break;
case V_144 :
V_14 = F_84 ( V_64 -> V_46 . V_70 -> V_95 ,
( V_142 T_1 * ) V_137 -> V_93 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_85 ( struct V_63 * V_64 ,
struct V_136 * V_137 )
{
int V_14 = - V_12 ;
switch ( V_137 -> V_117 ) {
case V_138 :
V_14 = F_86 ( V_64 -> V_46 . V_70 -> V_96 ,
( V_139 T_1 * ) V_137 -> V_93 ) ;
break;
case V_140 :
V_14 = F_86 ( V_64 -> V_46 . V_70 -> V_141 ,
( V_142 T_1 * ) V_137 -> V_93 ) ;
break;
case V_143 :
V_14 = F_86 ( V_64 -> V_46 . V_70 -> V_94 ,
( V_142 T_1 * ) V_137 -> V_93 ) ;
break;
case V_144 :
V_14 = F_86 ( V_64 -> V_46 . V_70 -> V_95 ,
( V_142 T_1 * ) V_137 -> V_93 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_87 ( struct V_63 * V_64 )
{
F_58 ( V_64 ) ;
return 0 ;
}
int F_88 ( struct V_63 * V_64 , struct V_145 * V_87 )
{
memcpy ( & V_64 -> V_75 -> V_86 . V_87 . V_146 , & V_87 -> V_146 , sizeof( V_87 -> V_146 ) ) ;
return 0 ;
}
int F_89 ( struct V_63 * V_64 , struct V_145 * V_87 )
{
memcpy ( & V_87 -> V_146 , & V_64 -> V_75 -> V_86 . V_87 . V_146 , sizeof( V_87 -> V_146 ) ) ;
return 0 ;
}
int F_90 ( struct V_63 * V_64 ,
struct V_147 * V_148 )
{
memcpy ( & V_64 -> V_75 -> V_86 . V_87 . V_88 , & V_148 -> V_88 , sizeof( V_148 -> V_88 ) ) ;
memcpy ( & V_64 -> V_46 . V_70 -> V_97 , & V_148 -> V_149 , sizeof( V_148 -> V_149 ) ) ;
F_52 ( V_64 -> V_75 -> V_86 . V_87 . V_88 ) ;
return 0 ;
}
int F_91 ( struct V_63 * V_64 ,
struct V_147 * V_148 )
{
memcpy ( & V_148 -> V_88 , & V_64 -> V_75 -> V_86 . V_87 . V_88 , sizeof( V_148 -> V_88 ) ) ;
memcpy ( & V_148 -> V_149 , & V_64 -> V_46 . V_70 -> V_97 , sizeof( V_148 -> V_149 ) ) ;
return 0 ;
}
int F_92 ( struct V_63 * V_64 , struct V_150 * V_151 )
{
memcpy ( & V_64 -> V_46 . V_83 . V_152 , & V_151 -> V_152 , sizeof( V_151 -> V_152 ) ) ;
V_64 -> V_46 . V_83 . V_84 = V_151 -> V_84 & V_85 ;
F_51 ( & V_64 -> V_46 . V_83 ) ;
return 0 ;
}
int F_93 ( struct V_63 * V_64 , struct V_150 * V_151 )
{
memcpy ( & V_151 -> V_152 , & V_64 -> V_46 . V_83 . V_152 , sizeof( V_151 -> V_152 ) ) ;
V_151 -> V_84 = V_64 -> V_46 . V_83 . V_84 ;
return 0 ;
}
static int F_94 ( struct V_63 * V_64 , T_2 V_153 )
{
int V_40 = 0 ;
if ( ! ( F_41 ( & V_64 -> V_46 . V_70 -> V_90 ) & V_99 ) )
V_40 = - V_154 ;
else {
V_64 -> V_75 -> V_155 = V_153 . V_92 ;
V_64 -> V_75 -> V_156 = V_153 . V_93 ;
}
return V_40 ;
}
int F_95 ( struct V_63 * V_64 ,
struct V_157 * V_158 )
{
return - V_12 ;
}
int F_96 ( struct V_63 * V_64 ,
struct V_159 * V_160 )
{
return - V_12 ;
}
int F_97 ( struct V_63 * V_64 ,
struct V_161 * V_162 )
{
return - V_12 ;
}
int F_98 ( struct V_63 * V_64 ,
struct V_161 * V_162 )
{
return - V_12 ;
}
static int F_99 ( struct V_63 * V_64 )
{
while ( F_100 ( V_135 , V_64 ) ) {
int V_40 ;
V_40 = F_101 ( V_64 -> V_46 . V_58 ,
V_64 -> V_46 . V_70 -> V_134 ,
V_163 * 2 ) ;
if ( V_40 )
return V_40 ;
F_77 ( V_64 ) ;
}
return 0 ;
}
static int F_102 ( struct V_63 * V_64 )
{
int V_40 ;
memcpy ( & V_64 -> V_46 . V_70 -> V_164 , & V_64 -> V_75 -> V_86 . V_87 . V_146 [ 14 ] , 16 ) ;
if ( F_103 () )
F_104 () ;
if ( F_105 ( V_165 ) )
F_106 () ;
if ( ! F_32 ( V_64 -> V_31 ) )
F_107 ( V_64 ) ;
V_40 = F_99 ( V_64 ) ;
if ( V_40 )
return V_40 ;
V_64 -> V_46 . V_70 -> V_166 = 0 ;
F_30 ( V_64 , 6 , L_7 ,
F_41 ( & V_64 -> V_46 . V_70 -> V_90 ) ) ;
F_108 ( V_64 ,
F_41 ( & V_64 -> V_46 . V_70 -> V_90 ) ) ;
F_109 () ;
F_110 () ;
F_111 () ;
V_40 = F_112 ( V_64 -> V_46 . V_70 , V_64 -> V_75 -> V_86 . V_87 . V_146 ) ;
F_113 () ;
F_30 ( V_64 , 6 , L_8 ,
V_64 -> V_46 . V_70 -> V_166 ) ;
F_114 ( V_64 , V_64 -> V_46 . V_70 -> V_166 ) ;
if ( V_40 > 0 )
V_40 = 0 ;
if ( V_40 < 0 ) {
if ( F_32 ( V_64 -> V_31 ) ) {
V_40 = V_167 ;
} else {
F_30 ( V_64 , 3 , L_2 , L_9 ) ;
F_115 ( V_64 ) ;
V_40 = F_116 ( V_64 , V_168 ) ;
}
}
memcpy ( & V_64 -> V_75 -> V_86 . V_87 . V_146 [ 14 ] , & V_64 -> V_46 . V_70 -> V_164 , 16 ) ;
return V_40 ;
}
int F_117 ( struct V_63 * V_64 , struct V_169 * V_169 )
{
int V_40 ;
T_3 V_170 ;
V_171:
if ( V_64 -> V_172 )
F_118 ( V_173 , & V_64 -> V_174 , & V_170 ) ;
F_56 ( V_99 , & V_64 -> V_46 . V_70 -> V_90 ) ;
F_119 ( V_64 -> V_31 -> V_46 . V_54 . V_125 [ V_64 -> V_65 ] == NULL ) ;
switch ( V_169 -> V_175 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
break;
default:
F_75 () ;
}
V_64 -> V_46 . V_70 -> V_91 . V_92 = V_169 -> V_155 ;
V_64 -> V_46 . V_70 -> V_91 . V_93 = V_169 -> V_156 ;
if ( V_169 -> V_182 & V_77 ) {
V_169 -> V_182 &= ~ V_77 ;
F_59 ( V_64 , V_169 -> V_86 . V_87 . V_134 ) ;
}
if ( V_169 -> V_182 & V_80 ) {
V_169 -> V_182 &= ~ V_80 ;
memcpy ( & V_64 -> V_46 . V_70 -> V_97 , & V_169 -> V_86 . V_87 . V_149 , 128 ) ;
F_59 ( V_64 , V_169 -> V_86 . V_87 . V_134 ) ;
}
F_120 () ;
do {
V_40 = F_102 ( V_64 ) ;
if ( V_40 )
break;
if ( F_32 ( V_64 -> V_31 ) )
V_40 = - V_183 ;
else
V_40 = F_121 ( V_64 ) ;
} while ( ! F_122 ( V_50 ) && ! V_40 );
if ( V_40 == V_184 )
goto V_171;
if ( F_122 ( V_50 ) && ! V_40 ) {
V_169 -> V_175 = V_178 ;
V_40 = - V_185 ;
}
#ifdef F_13
if ( V_40 == V_167 ) {
V_169 -> V_175 = V_180 ;
V_169 -> V_186 . V_187 =
V_50 -> V_188 . V_189 ;
V_169 -> V_186 . V_190 = 0x10 ;
V_40 = 0 ;
}
#endif
if ( V_40 == - V_183 ) {
V_169 -> V_175 = V_176 ;
V_169 -> V_191 . V_166 = V_64 -> V_46 . V_70 -> V_166 ;
V_169 -> V_191 . V_192 = V_64 -> V_46 . V_70 -> V_192 ;
V_169 -> V_191 . V_193 = V_64 -> V_46 . V_70 -> V_193 ;
V_40 = 0 ;
}
if ( V_40 == - V_194 ) {
V_40 = 0 ;
}
V_169 -> V_155 = V_64 -> V_46 . V_70 -> V_91 . V_92 ;
V_169 -> V_156 = V_64 -> V_46 . V_70 -> V_91 . V_93 ;
V_169 -> V_86 . V_87 . V_134 = V_64 -> V_46 . V_70 -> V_134 ;
memcpy ( & V_169 -> V_86 . V_87 . V_149 , & V_64 -> V_46 . V_70 -> V_97 , 128 ) ;
if ( V_64 -> V_172 )
F_118 ( V_173 , & V_170 , NULL ) ;
V_64 -> V_195 . V_196 ++ ;
return V_40 ;
}
static int F_123 ( struct V_63 * V_64 , V_142 V_197 , void * V_198 ,
unsigned long V_199 , int V_134 )
{
if ( V_134 )
return F_124 ( V_64 , V_197 , V_198 , V_199 ) ;
else
return F_125 ( V_64 , V_197 , V_198 , V_199 ) ;
}
int F_126 ( struct V_63 * V_64 , unsigned long V_93 )
{
unsigned char V_200 = 1 ;
int V_134 ;
if ( V_93 == V_201 ) {
if ( F_125 ( V_64 , 163ul , & V_200 , 1 ) )
return - V_38 ;
V_93 = V_202 ;
V_134 = 0 ;
} else if ( V_93 == V_203 ) {
if ( F_124 ( V_64 , 163ul , & V_200 , 1 ) )
return - V_38 ;
V_93 = V_202 ;
V_134 = 1 ;
} else
V_134 = 0 ;
F_49 ( & V_64 -> V_46 . V_83 ) ;
F_50 ( V_64 -> V_75 -> V_86 . V_87 . V_88 ) ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_205 ) ,
V_64 -> V_46 . V_83 . V_152 , 128 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_206 ) ,
V_64 -> V_75 -> V_86 . V_87 . V_146 , 128 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_153 ) ,
& V_64 -> V_46 . V_70 -> V_91 , 16 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_207 ) ,
& V_64 -> V_46 . V_70 -> V_134 , 4 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 ,
V_93 + F_127 ( struct V_204 , V_208 ) ,
& V_64 -> V_46 . V_83 . V_84 , 4 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_209 ) ,
& V_64 -> V_46 . V_70 -> V_96 , 4 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_210 ) ,
& V_64 -> V_46 . V_70 -> V_94 , 8 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_211 ) ,
& V_64 -> V_46 . V_70 -> V_95 , 8 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 , V_93 + F_127 ( struct V_204 , V_212 ) ,
& V_64 -> V_75 -> V_86 . V_87 . V_88 , 64 , V_134 ) )
return - V_38 ;
if ( F_123 ( V_64 ,
V_93 + F_127 ( struct V_204 , V_213 ) ,
& V_64 -> V_46 . V_70 -> V_97 , 128 , V_134 ) )
return - V_38 ;
return 0 ;
}
static int F_128 ( struct V_63 * V_64 ,
struct V_214 * V_215 )
{
int V_14 ;
if ( V_215 -> V_216 )
return - V_12 ;
switch ( V_215 -> V_215 ) {
case V_22 :
if ( ! V_64 -> V_31 -> V_46 . V_62 ) {
V_64 -> V_31 -> V_46 . V_62 = 1 ;
F_129 ( V_64 -> V_31 ) ;
}
V_14 = 0 ;
break;
default:
V_14 = - V_12 ;
break;
}
return V_14 ;
}
long F_130 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned long V_10 )
{
struct V_63 * V_64 = V_8 -> V_33 ;
void T_1 * V_34 = ( void T_1 * ) V_10 ;
long V_14 ;
switch ( V_9 ) {
case V_35 : {
struct V_36 V_37 ;
V_14 = - V_38 ;
if ( F_16 ( & V_37 , V_34 , sizeof( V_37 ) ) )
break;
V_14 = F_131 ( V_64 , & V_37 ) ;
break;
}
case V_217 :
V_14 = F_126 ( V_64 , V_10 ) ;
break;
case V_218 : {
T_2 V_153 ;
V_14 = - V_38 ;
if ( F_16 ( & V_153 , V_34 , sizeof( V_153 ) ) )
break;
V_14 = F_94 ( V_64 , V_153 ) ;
break;
}
case V_219 :
V_14 = F_87 ( V_64 ) ;
break;
case V_220 :
case V_221 : {
struct V_136 V_137 ;
V_14 = - V_38 ;
if ( F_16 ( & V_137 , V_34 , sizeof( V_137 ) ) )
break;
if ( V_9 == V_220 )
V_14 = F_85 ( V_64 , & V_137 ) ;
else
V_14 = F_83 ( V_64 , & V_137 ) ;
break;
}
#ifdef F_13
case V_222 : {
struct V_223 V_224 ;
if ( F_16 ( & V_224 , V_34 , sizeof( V_224 ) ) ) {
V_14 = - V_38 ;
break;
}
if ( ! F_32 ( V_64 -> V_31 ) ) {
V_14 = - V_12 ;
break;
}
V_14 = F_132 ( V_64 -> V_46 . V_58 , V_224 . V_225 ,
V_224 . V_226 , V_224 . V_227 ) ;
break;
}
case V_228 : {
struct V_223 V_224 ;
if ( F_16 ( & V_224 , V_34 , sizeof( V_224 ) ) ) {
V_14 = - V_38 ;
break;
}
if ( ! F_32 ( V_64 -> V_31 ) ) {
V_14 = - V_12 ;
break;
}
V_14 = F_133 ( V_64 -> V_46 . V_58 , V_224 . V_226 ,
V_224 . V_227 ) ;
break;
}
#endif
case V_229 : {
V_14 = F_134 ( V_10 , V_64 -> V_46 . V_58 ) ;
if ( ! F_135 ( V_14 ) )
V_14 = 0 ;
break;
}
case V_230 :
{
struct V_214 V_215 ;
V_14 = - V_38 ;
if ( F_16 ( & V_215 , V_34 , sizeof( V_215 ) ) )
break;
V_14 = F_128 ( V_64 , & V_215 ) ;
break;
}
default:
V_14 = - V_39 ;
}
return V_14 ;
}
int F_136 ( struct V_63 * V_64 , struct V_231 * V_232 )
{
#ifdef F_13
if ( ( V_232 -> V_233 == V_234 )
&& ( F_32 ( V_64 -> V_31 ) ) ) {
V_232 -> V_235 = F_137 ( V_64 -> V_46 . V_70 ) ;
F_138 ( V_232 -> V_235 ) ;
return 0 ;
}
#endif
return V_236 ;
}
void F_139 ( struct V_237 * free ,
struct V_237 * V_238 )
{
}
int F_140 ( struct V_237 * V_239 , unsigned long V_240 )
{
return 0 ;
}
int F_141 ( struct V_31 * V_31 ,
struct V_237 * V_241 ,
struct V_242 * V_243 ,
enum V_244 V_245 )
{
if ( V_243 -> V_246 & 0xffffful )
return - V_12 ;
if ( V_243 -> V_247 & 0xffffful )
return - V_12 ;
return 0 ;
}
void F_142 ( struct V_31 * V_31 ,
struct V_242 * V_243 ,
const struct V_237 * V_248 ,
enum V_244 V_245 )
{
int V_40 ;
if ( V_248 -> V_246 == V_243 -> V_246 &&
V_248 -> V_249 * V_163 == V_243 -> V_250 &&
V_248 -> V_240 * V_163 == V_243 -> V_247 )
return;
V_40 = F_132 ( V_31 -> V_46 . V_58 , V_243 -> V_246 ,
V_243 -> V_250 , V_243 -> V_247 ) ;
if ( V_40 )
F_143 ( V_251 L_10 ) ;
return;
}
void F_144 ( struct V_31 * V_31 )
{
}
void F_145 ( struct V_31 * V_31 ,
struct V_237 * V_239 )
{
}
static int T_4 F_146 ( void )
{
int V_252 ;
V_252 = F_147 ( NULL , sizeof( struct V_63 ) , 0 , V_253 ) ;
if ( V_252 )
return V_252 ;
V_107 = ( unsigned long long * ) F_20 ( V_49 | V_254 ) ;
if ( ! V_107 ) {
F_148 () ;
return - V_45 ;
}
memcpy ( V_107 , V_255 . V_256 , 16 ) ;
V_107 [ 0 ] &= 0xff82fff3f47c0000ULL ;
V_107 [ 1 ] &= 0x001c000000000000ULL ;
return 0 ;
}
static void T_5 F_149 ( void )
{
F_28 ( ( unsigned long ) V_107 ) ;
F_148 () ;
}
