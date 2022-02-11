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
V_16 = 1 ;
break;
case V_26 :
case V_27 :
V_16 = V_28 ;
break;
case V_29 :
V_16 = V_30 ;
break;
case V_31 :
V_16 = V_32 ;
break;
default:
V_16 = 0 ;
}
return V_16 ;
}
int F_16 ( struct V_33 * V_33 ,
struct V_34 * log )
{
return 0 ;
}
long F_17 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_33 * V_33 = V_10 -> V_35 ;
void T_1 * V_36 = ( void T_1 * ) V_12 ;
int V_16 ;
switch ( V_11 ) {
case V_37 : {
struct V_38 V_39 ;
V_16 = - V_40 ;
if ( F_18 ( & V_39 , V_36 , sizeof( V_39 ) ) )
break;
V_16 = F_19 ( V_33 , & V_39 ) ;
break;
}
default:
V_16 = - V_41 ;
}
return V_16 ;
}
int F_20 ( struct V_33 * V_33 , unsigned long type )
{
int V_42 ;
char V_43 [ 16 ] ;
V_42 = - V_14 ;
#ifdef F_15
if ( type & ~ V_44 )
goto V_45;
if ( ( type & V_44 ) && ( ! F_21 ( V_46 ) ) )
goto V_45;
#else
if ( type )
goto V_45;
#endif
V_42 = F_13 () ;
if ( V_42 )
goto V_45;
V_42 = - V_47 ;
V_33 -> V_48 . V_49 = (struct V_50 * ) F_22 ( V_51 ) ;
if ( ! V_33 -> V_48 . V_49 )
goto V_45;
sprintf ( V_43 , L_1 , V_52 -> V_53 ) ;
V_33 -> V_48 . V_54 = F_23 ( V_43 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_33 -> V_48 . V_54 )
goto V_55;
F_24 ( & V_33 -> V_48 . V_56 . V_57 ) ;
F_25 ( & V_33 -> V_48 . V_56 . V_58 ) ;
F_26 ( V_33 -> V_48 . V_54 , & V_59 ) ;
F_27 ( V_33 , 3 , L_2 , L_3 ) ;
if ( type & V_44 ) {
V_33 -> V_48 . V_60 = NULL ;
} else {
V_33 -> V_48 . V_60 = F_28 ( V_52 -> V_61 ) ;
if ( ! V_33 -> V_48 . V_60 )
goto V_62;
V_33 -> V_48 . V_60 -> V_63 = V_33 ;
}
V_33 -> V_48 . V_64 = 0 ;
return 0 ;
V_62:
F_29 ( V_33 -> V_48 . V_54 ) ;
V_55:
F_30 ( ( unsigned long ) ( V_33 -> V_48 . V_49 ) ) ;
V_45:
return V_42 ;
}
void F_31 ( struct V_65 * V_66 )
{
F_32 ( V_66 , 3 , L_2 , L_4 ) ;
F_33 ( V_66 -> V_67 ) ;
if ( ! F_34 ( V_66 -> V_33 ) ) {
F_35 ( 63 - V_66 -> V_67 ,
( unsigned long * ) & V_66 -> V_33 -> V_48 . V_49 -> V_68 ) ;
if ( V_66 -> V_33 -> V_48 . V_49 -> V_69 [ V_66 -> V_67 ] . V_70 ==
( V_71 ) V_66 -> V_48 . V_72 )
V_66 -> V_33 -> V_48 . V_49 -> V_69 [ V_66 -> V_67 ] . V_70 = 0 ;
}
F_36 () ;
if ( F_34 ( V_66 -> V_33 ) )
F_37 ( V_66 -> V_48 . V_60 ) ;
F_30 ( ( unsigned long ) ( V_66 -> V_48 . V_72 ) ) ;
F_38 ( V_66 ) ;
F_39 ( V_73 , V_66 ) ;
}
static void F_40 ( struct V_33 * V_33 )
{
unsigned int V_74 ;
struct V_65 * V_66 ;
F_41 (i, vcpu, kvm)
F_31 ( V_66 ) ;
F_42 ( & V_33 -> V_57 ) ;
for ( V_74 = 0 ; V_74 < F_43 ( & V_33 -> V_75 ) ; V_74 ++ )
V_33 -> V_76 [ V_74 ] = NULL ;
F_44 ( & V_33 -> V_75 , 0 ) ;
F_45 ( & V_33 -> V_57 ) ;
}
void F_46 ( struct V_33 * V_33 )
{
}
void F_47 ( struct V_33 * V_33 )
{
F_40 ( V_33 ) ;
F_30 ( ( unsigned long ) ( V_33 -> V_48 . V_49 ) ) ;
F_29 ( V_33 -> V_48 . V_54 ) ;
if ( ! F_34 ( V_33 ) )
F_37 ( V_33 -> V_48 . V_60 ) ;
}
int F_48 ( struct V_65 * V_66 )
{
if ( F_34 ( V_66 -> V_33 ) ) {
V_66 -> V_48 . V_60 = F_28 ( V_52 -> V_61 ) ;
if ( ! V_66 -> V_48 . V_60 )
return - V_47 ;
V_66 -> V_48 . V_60 -> V_63 = V_66 -> V_33 ;
return 0 ;
}
V_66 -> V_48 . V_60 = V_66 -> V_33 -> V_48 . V_60 ;
V_66 -> V_77 -> V_78 = V_79 |
V_80 |
V_81 |
V_82 ;
return 0 ;
}
void F_49 ( struct V_65 * V_66 )
{
}
void F_50 ( struct V_65 * V_66 , int V_69 )
{
F_51 ( & V_66 -> V_48 . V_83 ) ;
F_52 ( V_66 -> V_48 . V_84 ) ;
V_66 -> V_48 . V_85 . V_86 &= V_87 ;
F_53 ( & V_66 -> V_48 . V_85 ) ;
F_54 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
F_55 ( V_66 -> V_48 . V_60 ) ;
F_56 ( V_91 , & V_66 -> V_48 . V_72 -> V_92 ) ;
}
void F_57 ( struct V_65 * V_66 )
{
F_58 ( V_91 , & V_66 -> V_48 . V_72 -> V_92 ) ;
F_59 ( V_66 -> V_48 . V_60 ) ;
F_51 ( & V_66 -> V_48 . V_85 ) ;
F_52 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
F_53 ( & V_66 -> V_48 . V_83 ) ;
F_54 ( V_66 -> V_48 . V_84 ) ;
}
static void F_60 ( struct V_65 * V_66 )
{
V_66 -> V_48 . V_72 -> V_93 . V_94 = 0UL ;
V_66 -> V_48 . V_72 -> V_93 . V_95 = 0UL ;
F_61 ( V_66 , 0 ) ;
V_66 -> V_48 . V_72 -> V_96 = 0UL ;
V_66 -> V_48 . V_72 -> V_97 = 0UL ;
V_66 -> V_48 . V_72 -> V_98 = 0 ;
memset ( V_66 -> V_48 . V_72 -> V_99 , 0 , 16 * sizeof( V_71 ) ) ;
V_66 -> V_48 . V_72 -> V_99 [ 0 ] = 0xE0UL ;
V_66 -> V_48 . V_72 -> V_99 [ 14 ] = 0xC2000000UL ;
V_66 -> V_48 . V_85 . V_86 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_66 -> V_48 . V_72 -> V_100 = 1 ;
F_56 ( V_101 , & V_66 -> V_48 . V_72 -> V_92 ) ;
}
int F_62 ( struct V_65 * V_66 )
{
return 0 ;
}
int F_63 ( struct V_65 * V_66 )
{
F_44 ( & V_66 -> V_48 . V_72 -> V_92 , V_102 |
V_103 |
V_101 |
V_104 ) ;
V_66 -> V_48 . V_72 -> V_105 = 6 ;
V_66 -> V_48 . V_72 -> V_106 = 8 ;
V_66 -> V_48 . V_72 -> V_107 = 0xC1002001U ;
V_66 -> V_48 . V_72 -> V_108 = ( int ) ( long ) V_2 ;
F_64 ( & V_66 -> V_48 . V_109 , V_110 , V_111 ) ;
F_65 ( & V_66 -> V_48 . V_112 , V_113 ,
( unsigned long ) V_66 ) ;
V_66 -> V_48 . V_109 . V_114 = V_115 ;
F_66 ( & V_66 -> V_48 . V_116 ) ;
V_66 -> V_48 . V_116 . V_117 = 0xff ;
return 0 ;
}
struct V_65 * F_67 ( struct V_33 * V_33 ,
unsigned int V_118 )
{
struct V_65 * V_66 ;
int V_42 = - V_14 ;
if ( V_118 >= V_28 )
goto V_119;
V_42 = - V_47 ;
V_66 = F_68 ( V_73 , V_51 ) ;
if ( ! V_66 )
goto V_119;
V_66 -> V_48 . V_72 = (struct V_120 * )
F_22 ( V_51 ) ;
if ( ! V_66 -> V_48 . V_72 )
goto V_121;
V_66 -> V_48 . V_72 -> V_122 = V_118 ;
if ( ! F_34 ( V_33 ) ) {
if ( ! V_33 -> V_48 . V_49 ) {
F_69 ( 1 ) ;
goto V_121;
}
if ( ! V_33 -> V_48 . V_49 -> V_69 [ V_118 ] . V_70 )
V_33 -> V_48 . V_49 -> V_69 [ V_118 ] . V_70 =
( V_71 ) V_66 -> V_48 . V_72 ;
V_66 -> V_48 . V_72 -> V_123 =
( V_124 ) ( ( ( V_71 ) V_33 -> V_48 . V_49 ) >> 32 ) ;
V_66 -> V_48 . V_72 -> V_125 = ( V_124 ) ( V_71 ) V_33 -> V_48 . V_49 ;
F_70 ( 63 - V_118 , ( unsigned long * ) & V_33 -> V_48 . V_49 -> V_68 ) ;
}
F_24 ( & V_66 -> V_48 . V_126 . V_57 ) ;
F_25 ( & V_66 -> V_48 . V_126 . V_58 ) ;
V_66 -> V_48 . V_126 . V_56 = & V_33 -> V_48 . V_56 ;
F_71 ( & V_33 -> V_48 . V_56 . V_57 ) ;
V_33 -> V_48 . V_56 . V_126 [ V_118 ] = & V_66 -> V_48 . V_126 ;
V_66 -> V_48 . V_126 . V_127 = & V_66 -> V_127 ;
V_66 -> V_48 . V_126 . V_92 = & V_66 -> V_48 . V_72 -> V_92 ;
F_72 ( & V_33 -> V_48 . V_56 . V_57 ) ;
V_42 = F_73 ( V_66 , V_33 , V_118 ) ;
if ( V_42 )
goto V_128;
F_27 ( V_33 , 3 , L_5 , V_118 , V_66 ,
V_66 -> V_48 . V_72 ) ;
F_74 ( V_118 , V_66 , V_66 -> V_48 . V_72 ) ;
return V_66 ;
V_128:
F_30 ( ( unsigned long ) ( V_66 -> V_48 . V_72 ) ) ;
V_121:
F_39 ( V_73 , V_66 ) ;
V_119:
return F_75 ( V_42 ) ;
}
int F_76 ( struct V_65 * V_66 )
{
F_77 () ;
return 0 ;
}
void F_78 ( struct V_65 * V_66 )
{
F_56 ( V_129 , & V_66 -> V_48 . V_72 -> V_130 ) ;
}
void F_79 ( struct V_65 * V_66 )
{
F_58 ( V_129 , & V_66 -> V_48 . V_72 -> V_130 ) ;
}
void F_80 ( struct V_65 * V_66 )
{
F_56 ( V_131 , & V_66 -> V_48 . V_72 -> V_92 ) ;
while ( V_66 -> V_48 . V_72 -> V_132 & V_133 )
F_81 () ;
}
void F_82 ( struct V_65 * V_66 )
{
F_78 ( V_66 ) ;
F_80 ( V_66 ) ;
}
static void V_6 ( struct V_60 * V_60 , unsigned long V_134 )
{
int V_74 ;
struct V_33 * V_33 = V_60 -> V_63 ;
struct V_65 * V_66 ;
F_41 (i, vcpu, kvm) {
if ( V_66 -> V_48 . V_72 -> V_135 == ( V_134 & ~ 0x1000UL ) ) {
F_32 ( V_66 , 2 , L_6 , V_134 ) ;
F_83 ( V_136 , V_66 ) ;
F_82 ( V_66 ) ;
}
}
}
int F_84 ( struct V_65 * V_66 )
{
F_77 () ;
return 0 ;
}
static int F_85 ( struct V_65 * V_66 ,
struct V_137 * V_138 )
{
int V_16 = - V_14 ;
switch ( V_138 -> V_118 ) {
case V_139 :
V_16 = F_86 ( V_66 -> V_48 . V_72 -> V_98 ,
( V_140 T_1 * ) V_138 -> V_95 ) ;
break;
case V_141 :
V_16 = F_86 ( V_66 -> V_48 . V_72 -> V_142 ,
( V_143 T_1 * ) V_138 -> V_95 ) ;
break;
case V_144 :
V_16 = F_86 ( V_66 -> V_48 . V_72 -> V_96 ,
( V_143 T_1 * ) V_138 -> V_95 ) ;
break;
case V_145 :
V_16 = F_86 ( V_66 -> V_48 . V_72 -> V_97 ,
( V_143 T_1 * ) V_138 -> V_95 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_87 ( struct V_65 * V_66 ,
struct V_137 * V_138 )
{
int V_16 = - V_14 ;
switch ( V_138 -> V_118 ) {
case V_139 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_98 ,
( V_140 T_1 * ) V_138 -> V_95 ) ;
break;
case V_141 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_142 ,
( V_143 T_1 * ) V_138 -> V_95 ) ;
break;
case V_144 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_96 ,
( V_143 T_1 * ) V_138 -> V_95 ) ;
break;
case V_145 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_97 ,
( V_143 T_1 * ) V_138 -> V_95 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_89 ( struct V_65 * V_66 )
{
F_60 ( V_66 ) ;
return 0 ;
}
int F_90 ( struct V_65 * V_66 , struct V_146 * V_89 )
{
memcpy ( & V_66 -> V_77 -> V_88 . V_89 . V_147 , & V_89 -> V_147 , sizeof( V_89 -> V_147 ) ) ;
return 0 ;
}
int F_91 ( struct V_65 * V_66 , struct V_146 * V_89 )
{
memcpy ( & V_89 -> V_147 , & V_66 -> V_77 -> V_88 . V_89 . V_147 , sizeof( V_89 -> V_147 ) ) ;
return 0 ;
}
int F_92 ( struct V_65 * V_66 ,
struct V_148 * V_149 )
{
memcpy ( & V_66 -> V_77 -> V_88 . V_89 . V_90 , & V_149 -> V_90 , sizeof( V_149 -> V_90 ) ) ;
memcpy ( & V_66 -> V_48 . V_72 -> V_99 , & V_149 -> V_150 , sizeof( V_149 -> V_150 ) ) ;
F_54 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
return 0 ;
}
int F_93 ( struct V_65 * V_66 ,
struct V_148 * V_149 )
{
memcpy ( & V_149 -> V_90 , & V_66 -> V_77 -> V_88 . V_89 . V_90 , sizeof( V_149 -> V_90 ) ) ;
memcpy ( & V_149 -> V_150 , & V_66 -> V_48 . V_72 -> V_99 , sizeof( V_149 -> V_150 ) ) ;
return 0 ;
}
int F_94 ( struct V_65 * V_66 , struct V_151 * V_152 )
{
memcpy ( & V_66 -> V_48 . V_85 . V_153 , & V_152 -> V_153 , sizeof( V_152 -> V_153 ) ) ;
V_66 -> V_48 . V_85 . V_86 = V_152 -> V_86 & V_87 ;
F_53 ( & V_66 -> V_48 . V_85 ) ;
return 0 ;
}
int F_95 ( struct V_65 * V_66 , struct V_151 * V_152 )
{
memcpy ( & V_152 -> V_153 , & V_66 -> V_48 . V_85 . V_153 , sizeof( V_152 -> V_153 ) ) ;
V_152 -> V_86 = V_66 -> V_48 . V_85 . V_86 ;
return 0 ;
}
static int F_96 ( struct V_65 * V_66 , T_2 V_154 )
{
int V_42 = 0 ;
if ( ! ( F_43 ( & V_66 -> V_48 . V_72 -> V_92 ) & V_101 ) )
V_42 = - V_155 ;
else {
V_66 -> V_77 -> V_156 = V_154 . V_94 ;
V_66 -> V_77 -> V_157 = V_154 . V_95 ;
}
return V_42 ;
}
int F_97 ( struct V_65 * V_66 ,
struct V_158 * V_159 )
{
return - V_14 ;
}
int F_98 ( struct V_65 * V_66 ,
struct V_160 * V_161 )
{
return - V_14 ;
}
int F_99 ( struct V_65 * V_66 ,
struct V_162 * V_163 )
{
return - V_14 ;
}
int F_100 ( struct V_65 * V_66 ,
struct V_162 * V_163 )
{
return - V_14 ;
}
static int F_101 ( struct V_65 * V_66 )
{
while ( F_102 ( V_136 , V_66 ) ) {
int V_42 ;
V_42 = F_103 ( V_66 -> V_48 . V_60 ,
V_66 -> V_48 . V_72 -> V_135 ,
V_164 * 2 ) ;
if ( V_42 )
return V_42 ;
F_79 ( V_66 ) ;
}
return 0 ;
}
static int F_104 ( struct V_65 * V_66 )
{
int V_42 ;
memcpy ( & V_66 -> V_48 . V_72 -> V_165 , & V_66 -> V_77 -> V_88 . V_89 . V_147 [ 14 ] , 16 ) ;
if ( F_105 () )
F_106 () ;
if ( F_107 ( V_166 ) )
F_108 () ;
if ( ! F_34 ( V_66 -> V_33 ) )
F_109 ( V_66 ) ;
V_42 = F_101 ( V_66 ) ;
if ( V_42 )
return V_42 ;
V_66 -> V_48 . V_72 -> V_167 = 0 ;
F_32 ( V_66 , 6 , L_7 ,
F_43 ( & V_66 -> V_48 . V_72 -> V_92 ) ) ;
F_110 ( V_66 ,
F_43 ( & V_66 -> V_48 . V_72 -> V_92 ) ) ;
F_111 () ;
F_112 () ;
F_113 () ;
V_42 = F_114 ( V_66 -> V_48 . V_72 , V_66 -> V_77 -> V_88 . V_89 . V_147 ) ;
F_115 () ;
F_32 ( V_66 , 6 , L_8 ,
V_66 -> V_48 . V_72 -> V_167 ) ;
F_116 ( V_66 , V_66 -> V_48 . V_72 -> V_167 ) ;
if ( V_42 > 0 )
V_42 = 0 ;
if ( V_42 < 0 ) {
if ( F_34 ( V_66 -> V_33 ) ) {
V_42 = V_168 ;
} else {
F_32 ( V_66 , 3 , L_2 , L_9 ) ;
F_117 ( V_66 ) ;
V_42 = F_118 ( V_66 , V_169 ) ;
}
}
memcpy ( & V_66 -> V_77 -> V_88 . V_89 . V_147 [ 14 ] , & V_66 -> V_48 . V_72 -> V_165 , 16 ) ;
return V_42 ;
}
int F_119 ( struct V_65 * V_66 , struct V_170 * V_170 )
{
int V_42 ;
T_3 V_171 ;
V_172:
if ( V_66 -> V_173 )
F_120 ( V_174 , & V_66 -> V_175 , & V_171 ) ;
F_58 ( V_101 , & V_66 -> V_48 . V_72 -> V_92 ) ;
F_121 ( V_66 -> V_33 -> V_48 . V_56 . V_126 [ V_66 -> V_67 ] == NULL ) ;
switch ( V_170 -> V_176 ) {
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
break;
default:
F_77 () ;
}
V_66 -> V_48 . V_72 -> V_93 . V_94 = V_170 -> V_156 ;
V_66 -> V_48 . V_72 -> V_93 . V_95 = V_170 -> V_157 ;
if ( V_170 -> V_183 & V_79 ) {
V_170 -> V_183 &= ~ V_79 ;
F_61 ( V_66 , V_170 -> V_88 . V_89 . V_135 ) ;
}
if ( V_170 -> V_183 & V_82 ) {
V_170 -> V_183 &= ~ V_82 ;
memcpy ( & V_66 -> V_48 . V_72 -> V_99 , & V_170 -> V_88 . V_89 . V_150 , 128 ) ;
F_61 ( V_66 , V_170 -> V_88 . V_89 . V_135 ) ;
}
F_122 () ;
do {
V_42 = F_104 ( V_66 ) ;
if ( V_42 )
break;
if ( F_34 ( V_66 -> V_33 ) )
V_42 = - V_184 ;
else
V_42 = F_123 ( V_66 ) ;
} while ( ! F_124 ( V_52 ) && ! V_42 );
if ( V_42 == V_185 )
goto V_172;
if ( F_124 ( V_52 ) && ! V_42 ) {
V_170 -> V_176 = V_179 ;
V_42 = - V_186 ;
}
#ifdef F_15
if ( V_42 == V_168 ) {
V_170 -> V_176 = V_181 ;
V_170 -> V_187 . V_188 =
V_52 -> V_189 . V_190 ;
V_170 -> V_187 . V_191 = 0x10 ;
V_42 = 0 ;
}
#endif
if ( V_42 == - V_184 ) {
V_170 -> V_176 = V_177 ;
V_170 -> V_192 . V_167 = V_66 -> V_48 . V_72 -> V_167 ;
V_170 -> V_192 . V_193 = V_66 -> V_48 . V_72 -> V_193 ;
V_170 -> V_192 . V_194 = V_66 -> V_48 . V_72 -> V_194 ;
V_42 = 0 ;
}
if ( V_42 == - V_195 ) {
V_42 = 0 ;
}
V_170 -> V_156 = V_66 -> V_48 . V_72 -> V_93 . V_94 ;
V_170 -> V_157 = V_66 -> V_48 . V_72 -> V_93 . V_95 ;
V_170 -> V_88 . V_89 . V_135 = V_66 -> V_48 . V_72 -> V_135 ;
memcpy ( & V_170 -> V_88 . V_89 . V_150 , & V_66 -> V_48 . V_72 -> V_99 , 128 ) ;
if ( V_66 -> V_173 )
F_120 ( V_174 , & V_171 , NULL ) ;
V_66 -> V_196 . V_197 ++ ;
return V_42 ;
}
static int F_125 ( struct V_65 * V_66 , V_143 V_198 , void * V_199 ,
unsigned long V_200 , int V_135 )
{
if ( V_135 )
return F_126 ( V_66 , V_198 , V_199 , V_200 ) ;
else
return F_127 ( V_66 , V_198 , V_199 , V_200 ) ;
}
int F_128 ( struct V_65 * V_66 , unsigned long V_95 )
{
unsigned char V_201 = 1 ;
int V_135 ;
if ( V_95 == V_202 ) {
if ( F_127 ( V_66 , 163ul , & V_201 , 1 ) )
return - V_40 ;
V_95 = V_203 ;
V_135 = 0 ;
} else if ( V_95 == V_204 ) {
if ( F_126 ( V_66 , 163ul , & V_201 , 1 ) )
return - V_40 ;
V_95 = V_203 ;
V_135 = 1 ;
} else
V_135 = 0 ;
F_51 ( & V_66 -> V_48 . V_85 ) ;
F_52 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_206 ) ,
V_66 -> V_48 . V_85 . V_153 , 128 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_207 ) ,
V_66 -> V_77 -> V_88 . V_89 . V_147 , 128 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_154 ) ,
& V_66 -> V_48 . V_72 -> V_93 , 16 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_208 ) ,
& V_66 -> V_48 . V_72 -> V_135 , 4 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 ,
V_95 + F_129 ( struct V_205 , V_209 ) ,
& V_66 -> V_48 . V_85 . V_86 , 4 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_210 ) ,
& V_66 -> V_48 . V_72 -> V_98 , 4 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_211 ) ,
& V_66 -> V_48 . V_72 -> V_96 , 8 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_212 ) ,
& V_66 -> V_48 . V_72 -> V_97 , 8 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 , V_95 + F_129 ( struct V_205 , V_213 ) ,
& V_66 -> V_77 -> V_88 . V_89 . V_90 , 64 , V_135 ) )
return - V_40 ;
if ( F_125 ( V_66 ,
V_95 + F_129 ( struct V_205 , V_214 ) ,
& V_66 -> V_48 . V_72 -> V_99 , 128 , V_135 ) )
return - V_40 ;
return 0 ;
}
static int F_130 ( struct V_65 * V_66 ,
struct V_215 * V_216 )
{
int V_16 ;
if ( V_216 -> V_217 )
return - V_14 ;
switch ( V_216 -> V_216 ) {
case V_24 :
if ( ! V_66 -> V_33 -> V_48 . V_64 ) {
V_66 -> V_33 -> V_48 . V_64 = 1 ;
F_131 ( V_66 -> V_33 ) ;
}
V_16 = 0 ;
break;
default:
V_16 = - V_14 ;
break;
}
return V_16 ;
}
long F_132 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_65 * V_66 = V_10 -> V_35 ;
void T_1 * V_36 = ( void T_1 * ) V_12 ;
long V_16 ;
switch ( V_11 ) {
case V_37 : {
struct V_38 V_39 ;
V_16 = - V_40 ;
if ( F_18 ( & V_39 , V_36 , sizeof( V_39 ) ) )
break;
V_16 = F_133 ( V_66 , & V_39 ) ;
break;
}
case V_218 :
V_16 = F_128 ( V_66 , V_12 ) ;
break;
case V_219 : {
T_2 V_154 ;
V_16 = - V_40 ;
if ( F_18 ( & V_154 , V_36 , sizeof( V_154 ) ) )
break;
V_16 = F_96 ( V_66 , V_154 ) ;
break;
}
case V_220 :
V_16 = F_89 ( V_66 ) ;
break;
case V_221 :
case V_222 : {
struct V_137 V_138 ;
V_16 = - V_40 ;
if ( F_18 ( & V_138 , V_36 , sizeof( V_138 ) ) )
break;
if ( V_11 == V_221 )
V_16 = F_87 ( V_66 , & V_138 ) ;
else
V_16 = F_85 ( V_66 , & V_138 ) ;
break;
}
#ifdef F_15
case V_223 : {
struct V_224 V_225 ;
if ( F_18 ( & V_225 , V_36 , sizeof( V_225 ) ) ) {
V_16 = - V_40 ;
break;
}
if ( ! F_34 ( V_66 -> V_33 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_134 ( V_66 -> V_48 . V_60 , V_225 . V_226 ,
V_225 . V_227 , V_225 . V_228 ) ;
break;
}
case V_229 : {
struct V_224 V_225 ;
if ( F_18 ( & V_225 , V_36 , sizeof( V_225 ) ) ) {
V_16 = - V_40 ;
break;
}
if ( ! F_34 ( V_66 -> V_33 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_135 ( V_66 -> V_48 . V_60 , V_225 . V_227 ,
V_225 . V_228 ) ;
break;
}
#endif
case V_230 : {
V_16 = F_136 ( V_12 , V_66 -> V_48 . V_60 ) ;
if ( ! F_137 ( V_16 ) )
V_16 = 0 ;
break;
}
case V_231 :
{
struct V_215 V_216 ;
V_16 = - V_40 ;
if ( F_18 ( & V_216 , V_36 , sizeof( V_216 ) ) )
break;
V_16 = F_130 ( V_66 , & V_216 ) ;
break;
}
default:
V_16 = - V_41 ;
}
return V_16 ;
}
int F_138 ( struct V_65 * V_66 , struct V_232 * V_233 )
{
#ifdef F_15
if ( ( V_233 -> V_234 == V_235 )
&& ( F_34 ( V_66 -> V_33 ) ) ) {
V_233 -> V_236 = F_139 ( V_66 -> V_48 . V_72 ) ;
F_140 ( V_233 -> V_236 ) ;
return 0 ;
}
#endif
return V_237 ;
}
void F_141 ( struct V_238 * free ,
struct V_238 * V_239 )
{
}
int F_142 ( struct V_238 * V_240 , unsigned long V_241 )
{
return 0 ;
}
void F_143 ( struct V_33 * V_33 )
{
}
int F_144 ( struct V_33 * V_33 ,
struct V_238 * V_242 ,
struct V_243 * V_244 ,
enum V_245 V_246 )
{
if ( V_244 -> V_247 & 0xffffful )
return - V_14 ;
if ( V_244 -> V_248 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_145 ( struct V_33 * V_33 ,
struct V_243 * V_244 ,
const struct V_238 * V_249 ,
enum V_245 V_246 )
{
int V_42 ;
if ( V_249 -> V_247 == V_244 -> V_247 &&
V_249 -> V_250 * V_164 == V_244 -> V_251 &&
V_249 -> V_241 * V_164 == V_244 -> V_248 )
return;
V_42 = F_134 ( V_33 -> V_48 . V_60 , V_244 -> V_247 ,
V_244 -> V_251 , V_244 -> V_248 ) ;
if ( V_42 )
F_146 ( V_252 L_10 ) ;
return;
}
void F_147 ( struct V_33 * V_33 )
{
}
void F_148 ( struct V_33 * V_33 ,
struct V_238 * V_240 )
{
}
static int T_4 F_149 ( void )
{
int V_253 ;
V_253 = F_150 ( NULL , sizeof( struct V_65 ) , 0 , V_254 ) ;
if ( V_253 )
return V_253 ;
V_2 = ( unsigned long * ) F_22 ( V_51 | V_255 ) ;
if ( ! V_2 ) {
F_151 () ;
return - V_47 ;
}
memcpy ( V_2 , V_256 . V_257 , 16 ) ;
V_2 [ 0 ] &= 0xff82fff3f47c0000UL ;
V_2 [ 1 ] &= 0x001c000000000000UL ;
return 0 ;
}
static void T_5 F_152 ( void )
{
F_30 ( ( unsigned long ) V_2 ) ;
F_151 () ;
}
