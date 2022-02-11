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
F_51 ( & V_66 -> V_48 . V_83 . V_84 ) ;
F_52 ( V_66 -> V_48 . V_83 . V_85 ) ;
F_53 ( V_66 -> V_48 . V_86 ) ;
F_54 ( & V_66 -> V_48 . V_87 . V_84 ) ;
F_55 ( V_66 -> V_48 . V_87 . V_85 ) ;
F_56 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
F_57 ( V_66 -> V_48 . V_60 ) ;
F_58 ( V_91 , & V_66 -> V_48 . V_72 -> V_92 ) ;
}
void F_59 ( struct V_65 * V_66 )
{
F_60 ( V_91 , & V_66 -> V_48 . V_72 -> V_92 ) ;
F_61 ( V_66 -> V_48 . V_60 ) ;
F_51 ( & V_66 -> V_48 . V_87 . V_84 ) ;
F_52 ( V_66 -> V_48 . V_87 . V_85 ) ;
F_53 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
F_54 ( & V_66 -> V_48 . V_83 . V_84 ) ;
F_55 ( V_66 -> V_48 . V_83 . V_85 ) ;
F_56 ( V_66 -> V_48 . V_86 ) ;
}
static void F_62 ( struct V_65 * V_66 )
{
V_66 -> V_48 . V_72 -> V_93 . V_94 = 0UL ;
V_66 -> V_48 . V_72 -> V_93 . V_95 = 0UL ;
F_63 ( V_66 , 0 ) ;
V_66 -> V_48 . V_72 -> V_96 = 0UL ;
V_66 -> V_48 . V_72 -> V_97 = 0UL ;
V_66 -> V_48 . V_72 -> V_98 = 0 ;
memset ( V_66 -> V_48 . V_72 -> V_99 , 0 , 16 * sizeof( V_71 ) ) ;
V_66 -> V_48 . V_72 -> V_99 [ 0 ] = 0xE0UL ;
V_66 -> V_48 . V_72 -> V_99 [ 14 ] = 0xC2000000UL ;
V_66 -> V_48 . V_87 . V_84 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_66 -> V_48 . V_72 -> V_100 = 1 ;
F_58 ( V_101 , & V_66 -> V_48 . V_72 -> V_92 ) ;
}
int F_64 ( struct V_65 * V_66 )
{
return 0 ;
}
int F_65 ( struct V_65 * V_66 )
{
F_44 ( & V_66 -> V_48 . V_72 -> V_92 , V_102 |
V_103 |
V_101 |
V_104 ) ;
V_66 -> V_48 . V_72 -> V_105 = 6 ;
if ( F_1 ( 50 ) && F_1 ( 73 ) )
V_66 -> V_48 . V_72 -> V_105 |= 0x10 ;
V_66 -> V_48 . V_72 -> V_106 = 8 ;
V_66 -> V_48 . V_72 -> V_107 = 0xC1002001U ;
V_66 -> V_48 . V_72 -> V_108 = ( int ) ( long ) V_2 ;
F_66 ( & V_66 -> V_48 . V_109 , V_110 , V_111 ) ;
F_67 ( & V_66 -> V_48 . V_112 , V_113 ,
( unsigned long ) V_66 ) ;
V_66 -> V_48 . V_109 . V_114 = V_115 ;
F_68 ( & V_66 -> V_48 . V_116 ) ;
V_66 -> V_48 . V_116 . V_117 = 0xff ;
return 0 ;
}
struct V_65 * F_69 ( struct V_33 * V_33 ,
unsigned int V_118 )
{
struct V_65 * V_66 ;
struct V_119 * V_119 ;
int V_42 = - V_14 ;
if ( V_118 >= V_28 )
goto V_120;
V_42 = - V_47 ;
V_66 = F_70 ( V_73 , V_51 ) ;
if ( ! V_66 )
goto V_120;
V_119 = (struct V_119 * ) F_22 ( V_51 ) ;
if ( ! V_119 )
goto V_121;
V_66 -> V_48 . V_72 = & V_119 -> V_72 ;
V_66 -> V_48 . V_72 -> V_122 = ( unsigned long ) & V_119 -> V_123 ;
V_66 -> V_48 . V_72 -> V_124 = V_118 ;
if ( ! F_34 ( V_33 ) ) {
if ( ! V_33 -> V_48 . V_49 ) {
F_71 ( 1 ) ;
goto V_121;
}
if ( ! V_33 -> V_48 . V_49 -> V_69 [ V_118 ] . V_70 )
V_33 -> V_48 . V_49 -> V_69 [ V_118 ] . V_70 =
( V_71 ) V_66 -> V_48 . V_72 ;
V_66 -> V_48 . V_72 -> V_125 =
( V_126 ) ( ( ( V_71 ) V_33 -> V_48 . V_49 ) >> 32 ) ;
V_66 -> V_48 . V_72 -> V_127 = ( V_126 ) ( V_71 ) V_33 -> V_48 . V_49 ;
F_72 ( 63 - V_118 , ( unsigned long * ) & V_33 -> V_48 . V_49 -> V_68 ) ;
}
F_24 ( & V_66 -> V_48 . V_128 . V_57 ) ;
F_25 ( & V_66 -> V_48 . V_128 . V_58 ) ;
V_66 -> V_48 . V_128 . V_56 = & V_33 -> V_48 . V_56 ;
F_73 ( & V_33 -> V_48 . V_56 . V_57 ) ;
V_33 -> V_48 . V_56 . V_128 [ V_118 ] = & V_66 -> V_48 . V_128 ;
V_66 -> V_48 . V_128 . V_129 = & V_66 -> V_129 ;
V_66 -> V_48 . V_128 . V_92 = & V_66 -> V_48 . V_72 -> V_92 ;
F_74 ( & V_33 -> V_48 . V_56 . V_57 ) ;
V_42 = F_75 ( V_66 , V_33 , V_118 ) ;
if ( V_42 )
goto V_130;
F_27 ( V_33 , 3 , L_5 , V_118 , V_66 ,
V_66 -> V_48 . V_72 ) ;
F_76 ( V_118 , V_66 , V_66 -> V_48 . V_72 ) ;
return V_66 ;
V_130:
F_30 ( ( unsigned long ) ( V_66 -> V_48 . V_72 ) ) ;
V_121:
F_39 ( V_73 , V_66 ) ;
V_120:
return F_77 ( V_42 ) ;
}
int F_78 ( struct V_65 * V_66 )
{
F_79 () ;
return 0 ;
}
void F_80 ( struct V_65 * V_66 )
{
F_58 ( V_131 , & V_66 -> V_48 . V_72 -> V_132 ) ;
}
void F_81 ( struct V_65 * V_66 )
{
F_60 ( V_131 , & V_66 -> V_48 . V_72 -> V_132 ) ;
}
void F_82 ( struct V_65 * V_66 )
{
F_58 ( V_133 , & V_66 -> V_48 . V_72 -> V_92 ) ;
while ( V_66 -> V_48 . V_72 -> V_134 & V_135 )
F_83 () ;
}
void F_84 ( struct V_65 * V_66 )
{
F_80 ( V_66 ) ;
F_82 ( V_66 ) ;
}
static void V_6 ( struct V_60 * V_60 , unsigned long V_136 )
{
int V_74 ;
struct V_33 * V_33 = V_60 -> V_63 ;
struct V_65 * V_66 ;
F_41 (i, vcpu, kvm) {
if ( V_66 -> V_48 . V_72 -> V_137 == ( V_136 & ~ 0x1000UL ) ) {
F_32 ( V_66 , 2 , L_6 , V_136 ) ;
F_85 ( V_138 , V_66 ) ;
F_84 ( V_66 ) ;
}
}
}
int F_86 ( struct V_65 * V_66 )
{
F_79 () ;
return 0 ;
}
static int F_87 ( struct V_65 * V_66 ,
struct V_139 * V_140 )
{
int V_16 = - V_14 ;
switch ( V_140 -> V_118 ) {
case V_141 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_98 ,
( V_142 T_1 * ) V_140 -> V_95 ) ;
break;
case V_143 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_144 ,
( V_145 T_1 * ) V_140 -> V_95 ) ;
break;
case V_146 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_96 ,
( V_145 T_1 * ) V_140 -> V_95 ) ;
break;
case V_147 :
V_16 = F_88 ( V_66 -> V_48 . V_72 -> V_97 ,
( V_145 T_1 * ) V_140 -> V_95 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_89 ( struct V_65 * V_66 ,
struct V_139 * V_140 )
{
int V_16 = - V_14 ;
switch ( V_140 -> V_118 ) {
case V_141 :
V_16 = F_90 ( V_66 -> V_48 . V_72 -> V_98 ,
( V_142 T_1 * ) V_140 -> V_95 ) ;
break;
case V_143 :
V_16 = F_90 ( V_66 -> V_48 . V_72 -> V_144 ,
( V_145 T_1 * ) V_140 -> V_95 ) ;
break;
case V_146 :
V_16 = F_90 ( V_66 -> V_48 . V_72 -> V_96 ,
( V_145 T_1 * ) V_140 -> V_95 ) ;
break;
case V_147 :
V_16 = F_90 ( V_66 -> V_48 . V_72 -> V_97 ,
( V_145 T_1 * ) V_140 -> V_95 ) ;
break;
default:
break;
}
return V_16 ;
}
static int F_91 ( struct V_65 * V_66 )
{
F_62 ( V_66 ) ;
return 0 ;
}
int F_92 ( struct V_65 * V_66 , struct V_148 * V_89 )
{
memcpy ( & V_66 -> V_77 -> V_88 . V_89 . V_149 , & V_89 -> V_149 , sizeof( V_89 -> V_149 ) ) ;
return 0 ;
}
int F_93 ( struct V_65 * V_66 , struct V_148 * V_89 )
{
memcpy ( & V_89 -> V_149 , & V_66 -> V_77 -> V_88 . V_89 . V_149 , sizeof( V_89 -> V_149 ) ) ;
return 0 ;
}
int F_94 ( struct V_65 * V_66 ,
struct V_150 * V_151 )
{
memcpy ( & V_66 -> V_77 -> V_88 . V_89 . V_90 , & V_151 -> V_90 , sizeof( V_151 -> V_90 ) ) ;
memcpy ( & V_66 -> V_48 . V_72 -> V_99 , & V_151 -> V_152 , sizeof( V_151 -> V_152 ) ) ;
F_56 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
return 0 ;
}
int F_95 ( struct V_65 * V_66 ,
struct V_150 * V_151 )
{
memcpy ( & V_151 -> V_90 , & V_66 -> V_77 -> V_88 . V_89 . V_90 , sizeof( V_151 -> V_90 ) ) ;
memcpy ( & V_151 -> V_152 , & V_66 -> V_48 . V_72 -> V_99 , sizeof( V_151 -> V_152 ) ) ;
return 0 ;
}
int F_96 ( struct V_65 * V_66 , struct V_153 * V_154 )
{
if ( F_97 ( V_154 -> V_84 ) )
return - V_14 ;
memcpy ( & V_66 -> V_48 . V_87 . V_85 , & V_154 -> V_85 , sizeof( V_154 -> V_85 ) ) ;
V_66 -> V_48 . V_87 . V_84 = V_154 -> V_84 ;
F_54 ( & V_66 -> V_48 . V_87 . V_84 ) ;
F_55 ( V_66 -> V_48 . V_87 . V_85 ) ;
return 0 ;
}
int F_98 ( struct V_65 * V_66 , struct V_153 * V_154 )
{
memcpy ( & V_154 -> V_85 , & V_66 -> V_48 . V_87 . V_85 , sizeof( V_154 -> V_85 ) ) ;
V_154 -> V_84 = V_66 -> V_48 . V_87 . V_84 ;
return 0 ;
}
static int F_99 ( struct V_65 * V_66 , T_2 V_155 )
{
int V_42 = 0 ;
if ( ! ( F_43 ( & V_66 -> V_48 . V_72 -> V_92 ) & V_101 ) )
V_42 = - V_156 ;
else {
V_66 -> V_77 -> V_157 = V_155 . V_94 ;
V_66 -> V_77 -> V_158 = V_155 . V_95 ;
}
return V_42 ;
}
int F_100 ( struct V_65 * V_66 ,
struct V_159 * V_160 )
{
return - V_14 ;
}
int F_101 ( struct V_65 * V_66 ,
struct V_161 * V_162 )
{
return - V_14 ;
}
int F_102 ( struct V_65 * V_66 ,
struct V_163 * V_164 )
{
return - V_14 ;
}
int F_103 ( struct V_65 * V_66 ,
struct V_163 * V_164 )
{
return - V_14 ;
}
static int F_104 ( struct V_65 * V_66 )
{
while ( F_105 ( V_138 , V_66 ) ) {
int V_42 ;
V_42 = F_106 ( V_66 -> V_48 . V_60 ,
V_66 -> V_48 . V_72 -> V_137 ,
V_165 * 2 ) ;
if ( V_42 )
return V_42 ;
F_81 ( V_66 ) ;
}
return 0 ;
}
static int F_107 ( struct V_65 * V_66 )
{
int V_42 , V_92 ;
memcpy ( & V_66 -> V_48 . V_72 -> V_166 , & V_66 -> V_77 -> V_88 . V_89 . V_149 [ 14 ] , 16 ) ;
if ( F_108 () )
F_109 () ;
if ( F_110 ( V_167 ) )
F_111 () ;
if ( ! F_34 ( V_66 -> V_33 ) )
F_112 ( V_66 ) ;
V_42 = F_104 ( V_66 ) ;
if ( V_42 )
return V_42 ;
V_66 -> V_48 . V_72 -> V_168 = 0 ;
V_92 = F_43 ( & V_66 -> V_48 . V_72 -> V_92 ) ;
F_32 ( V_66 , 6 , L_7 , V_92 ) ;
F_113 ( V_66 , V_92 ) ;
return 0 ;
}
static int F_114 ( struct V_65 * V_66 , int V_169 )
{
int V_42 ;
F_32 ( V_66 , 6 , L_8 ,
V_66 -> V_48 . V_72 -> V_168 ) ;
F_115 ( V_66 , V_66 -> V_48 . V_72 -> V_168 ) ;
if ( V_169 >= 0 ) {
V_42 = 0 ;
} else if ( F_34 ( V_66 -> V_33 ) ) {
V_66 -> V_77 -> V_169 = V_170 ;
V_66 -> V_77 -> V_171 . V_172 =
V_52 -> V_173 . V_174 ;
V_66 -> V_77 -> V_171 . V_175 = 0x10 ;
V_42 = - V_176 ;
} else {
F_32 ( V_66 , 3 , L_2 , L_9 ) ;
F_116 ( V_66 ) ;
V_42 = F_117 ( V_66 , V_177 ) ;
}
memcpy ( & V_66 -> V_77 -> V_88 . V_89 . V_149 [ 14 ] , & V_66 -> V_48 . V_72 -> V_166 , 16 ) ;
if ( V_42 == 0 ) {
if ( F_34 ( V_66 -> V_33 ) )
V_42 = - V_178 ;
else
V_42 = F_118 ( V_66 ) ;
}
return V_42 ;
}
static int F_119 ( struct V_65 * V_66 )
{
int V_42 , V_169 ;
V_66 -> V_179 = F_120 ( & V_66 -> V_33 -> V_180 ) ;
do {
V_42 = F_107 ( V_66 ) ;
if ( V_42 )
break;
F_121 ( & V_66 -> V_33 -> V_180 , V_66 -> V_179 ) ;
F_122 () ;
F_123 () ;
F_124 () ;
V_169 = F_125 ( V_66 -> V_48 . V_72 ,
V_66 -> V_77 -> V_88 . V_89 . V_149 ) ;
F_126 () ;
V_66 -> V_179 = F_120 ( & V_66 -> V_33 -> V_180 ) ;
V_42 = F_114 ( V_66 , V_169 ) ;
} while ( ! F_127 ( V_52 ) && ! V_42 );
F_121 ( & V_66 -> V_33 -> V_180 , V_66 -> V_179 ) ;
return V_42 ;
}
int F_128 ( struct V_65 * V_66 , struct V_181 * V_181 )
{
int V_42 ;
T_3 V_182 ;
if ( V_66 -> V_183 )
F_129 ( V_184 , & V_66 -> V_185 , & V_182 ) ;
F_60 ( V_101 , & V_66 -> V_48 . V_72 -> V_92 ) ;
F_130 ( V_66 -> V_33 -> V_48 . V_56 . V_128 [ V_66 -> V_67 ] == NULL ) ;
switch ( V_181 -> V_169 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_170 :
case V_190 :
break;
default:
F_79 () ;
}
V_66 -> V_48 . V_72 -> V_93 . V_94 = V_181 -> V_157 ;
V_66 -> V_48 . V_72 -> V_93 . V_95 = V_181 -> V_158 ;
if ( V_181 -> V_191 & V_79 ) {
V_181 -> V_191 &= ~ V_79 ;
F_63 ( V_66 , V_181 -> V_88 . V_89 . V_137 ) ;
}
if ( V_181 -> V_191 & V_82 ) {
V_181 -> V_191 &= ~ V_82 ;
memcpy ( & V_66 -> V_48 . V_72 -> V_99 , & V_181 -> V_88 . V_89 . V_152 , 128 ) ;
F_63 ( V_66 , V_181 -> V_88 . V_89 . V_137 ) ;
}
F_131 () ;
V_42 = F_119 ( V_66 ) ;
if ( F_127 ( V_52 ) && ! V_42 ) {
V_181 -> V_169 = V_188 ;
V_42 = - V_192 ;
}
if ( V_42 == - V_178 ) {
V_181 -> V_169 = V_186 ;
V_181 -> V_193 . V_168 = V_66 -> V_48 . V_72 -> V_168 ;
V_181 -> V_193 . V_194 = V_66 -> V_48 . V_72 -> V_194 ;
V_181 -> V_193 . V_195 = V_66 -> V_48 . V_72 -> V_195 ;
V_42 = 0 ;
}
if ( V_42 == - V_176 ) {
V_42 = 0 ;
}
V_181 -> V_157 = V_66 -> V_48 . V_72 -> V_93 . V_94 ;
V_181 -> V_158 = V_66 -> V_48 . V_72 -> V_93 . V_95 ;
V_181 -> V_88 . V_89 . V_137 = V_66 -> V_48 . V_72 -> V_137 ;
memcpy ( & V_181 -> V_88 . V_89 . V_152 , & V_66 -> V_48 . V_72 -> V_99 , 128 ) ;
if ( V_66 -> V_183 )
F_129 ( V_184 , & V_182 , NULL ) ;
V_66 -> V_196 . V_197 ++ ;
return V_42 ;
}
static int F_132 ( struct V_65 * V_66 , V_145 V_198 , void * V_199 ,
unsigned long V_200 , int V_137 )
{
if ( V_137 )
return F_133 ( V_66 , V_198 , V_199 , V_200 ) ;
else
return F_134 ( V_66 , V_198 , V_199 , V_200 ) ;
}
int F_135 ( struct V_65 * V_66 , unsigned long V_95 )
{
unsigned char V_201 = 1 ;
int V_137 ;
V_145 V_202 ;
if ( V_95 == V_203 ) {
if ( F_134 ( V_66 , 163ul , & V_201 , 1 ) )
return - V_40 ;
V_95 = V_204 ;
V_137 = 0 ;
} else if ( V_95 == V_205 ) {
if ( F_133 ( V_66 , 163ul , & V_201 , 1 ) )
return - V_40 ;
V_95 = V_204 ;
V_137 = 1 ;
} else
V_137 = 0 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_207 ) ,
V_66 -> V_48 . V_87 . V_85 , 128 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_208 ) ,
V_66 -> V_77 -> V_88 . V_89 . V_149 , 128 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_155 ) ,
& V_66 -> V_48 . V_72 -> V_93 , 16 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_209 ) ,
& V_66 -> V_48 . V_72 -> V_137 , 4 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 ,
V_95 + F_136 ( struct V_206 , V_210 ) ,
& V_66 -> V_48 . V_87 . V_84 , 4 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_211 ) ,
& V_66 -> V_48 . V_72 -> V_98 , 4 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_212 ) ,
& V_66 -> V_48 . V_72 -> V_96 , 8 , V_137 ) )
return - V_40 ;
V_202 = V_66 -> V_48 . V_72 -> V_97 >> 8 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_213 ) ,
& V_202 , 8 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 , V_95 + F_136 ( struct V_206 , V_214 ) ,
& V_66 -> V_77 -> V_88 . V_89 . V_90 , 64 , V_137 ) )
return - V_40 ;
if ( F_132 ( V_66 ,
V_95 + F_136 ( struct V_206 , V_215 ) ,
& V_66 -> V_48 . V_72 -> V_99 , 128 , V_137 ) )
return - V_40 ;
return 0 ;
}
int F_137 ( struct V_65 * V_66 , unsigned long V_95 )
{
F_51 ( & V_66 -> V_48 . V_87 . V_84 ) ;
F_52 ( V_66 -> V_48 . V_87 . V_85 ) ;
F_53 ( V_66 -> V_77 -> V_88 . V_89 . V_90 ) ;
return F_135 ( V_66 , V_95 ) ;
}
static int F_138 ( struct V_65 * V_66 ,
struct V_216 * V_217 )
{
int V_16 ;
if ( V_217 -> V_218 )
return - V_14 ;
switch ( V_217 -> V_217 ) {
case V_24 :
if ( ! V_66 -> V_33 -> V_48 . V_64 ) {
V_66 -> V_33 -> V_48 . V_64 = 1 ;
F_139 ( V_66 -> V_33 ) ;
}
V_16 = 0 ;
break;
default:
V_16 = - V_14 ;
break;
}
return V_16 ;
}
long F_140 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_65 * V_66 = V_10 -> V_35 ;
void T_1 * V_36 = ( void T_1 * ) V_12 ;
int V_219 ;
long V_16 ;
switch ( V_11 ) {
case V_37 : {
struct V_38 V_39 ;
V_16 = - V_40 ;
if ( F_18 ( & V_39 , V_36 , sizeof( V_39 ) ) )
break;
V_16 = F_141 ( V_66 , & V_39 ) ;
break;
}
case V_220 :
V_219 = F_120 ( & V_66 -> V_33 -> V_180 ) ;
V_16 = F_137 ( V_66 , V_12 ) ;
F_121 ( & V_66 -> V_33 -> V_180 , V_219 ) ;
break;
case V_221 : {
T_2 V_155 ;
V_16 = - V_40 ;
if ( F_18 ( & V_155 , V_36 , sizeof( V_155 ) ) )
break;
V_16 = F_99 ( V_66 , V_155 ) ;
break;
}
case V_222 :
V_16 = F_91 ( V_66 ) ;
break;
case V_223 :
case V_224 : {
struct V_139 V_140 ;
V_16 = - V_40 ;
if ( F_18 ( & V_140 , V_36 , sizeof( V_140 ) ) )
break;
if ( V_11 == V_223 )
V_16 = F_89 ( V_66 , & V_140 ) ;
else
V_16 = F_87 ( V_66 , & V_140 ) ;
break;
}
#ifdef F_15
case V_225 : {
struct V_226 V_227 ;
if ( F_18 ( & V_227 , V_36 , sizeof( V_227 ) ) ) {
V_16 = - V_40 ;
break;
}
if ( ! F_34 ( V_66 -> V_33 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_142 ( V_66 -> V_48 . V_60 , V_227 . V_228 ,
V_227 . V_229 , V_227 . V_230 ) ;
break;
}
case V_231 : {
struct V_226 V_227 ;
if ( F_18 ( & V_227 , V_36 , sizeof( V_227 ) ) ) {
V_16 = - V_40 ;
break;
}
if ( ! F_34 ( V_66 -> V_33 ) ) {
V_16 = - V_14 ;
break;
}
V_16 = F_143 ( V_66 -> V_48 . V_60 , V_227 . V_229 ,
V_227 . V_230 ) ;
break;
}
#endif
case V_232 : {
V_16 = F_144 ( V_12 , V_66 -> V_48 . V_60 ) ;
if ( ! F_145 ( V_16 ) )
V_16 = 0 ;
break;
}
case V_233 :
{
struct V_216 V_217 ;
V_16 = - V_40 ;
if ( F_18 ( & V_217 , V_36 , sizeof( V_217 ) ) )
break;
V_16 = F_138 ( V_66 , & V_217 ) ;
break;
}
default:
V_16 = - V_41 ;
}
return V_16 ;
}
int F_146 ( struct V_65 * V_66 , struct V_234 * V_235 )
{
#ifdef F_15
if ( ( V_235 -> V_236 == V_237 )
&& ( F_34 ( V_66 -> V_33 ) ) ) {
V_235 -> V_238 = F_147 ( V_66 -> V_48 . V_72 ) ;
F_148 ( V_235 -> V_238 ) ;
return 0 ;
}
#endif
return V_239 ;
}
void F_149 ( struct V_33 * V_33 , struct V_240 * free ,
struct V_240 * V_241 )
{
}
int F_150 ( struct V_33 * V_33 , struct V_240 * V_242 ,
unsigned long V_243 )
{
return 0 ;
}
void F_151 ( struct V_33 * V_33 )
{
}
int F_152 ( struct V_33 * V_33 ,
struct V_240 * V_244 ,
struct V_245 * V_246 ,
enum V_247 V_248 )
{
if ( V_246 -> V_249 & 0xffffful )
return - V_14 ;
if ( V_246 -> V_250 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_153 ( struct V_33 * V_33 ,
struct V_245 * V_246 ,
const struct V_240 * V_251 ,
enum V_247 V_248 )
{
int V_42 ;
if ( V_251 -> V_249 == V_246 -> V_249 &&
V_251 -> V_252 * V_165 == V_246 -> V_253 &&
V_251 -> V_243 * V_165 == V_246 -> V_250 )
return;
V_42 = F_142 ( V_33 -> V_48 . V_60 , V_246 -> V_249 ,
V_246 -> V_253 , V_246 -> V_250 ) ;
if ( V_42 )
F_154 ( V_254 L_10 ) ;
return;
}
void F_155 ( struct V_33 * V_33 )
{
}
void F_156 ( struct V_33 * V_33 ,
struct V_240 * V_242 )
{
}
static int T_4 F_157 ( void )
{
int V_255 ;
V_255 = F_158 ( NULL , sizeof( struct V_65 ) , 0 , V_256 ) ;
if ( V_255 )
return V_255 ;
V_2 = ( unsigned long * ) F_22 ( V_51 | V_257 ) ;
if ( ! V_2 ) {
F_159 () ;
return - V_47 ;
}
memcpy ( V_2 , V_258 . V_259 , 16 ) ;
V_2 [ 0 ] &= 0xff82fff3f4fc2000UL ;
V_2 [ 1 ] &= 0x005c000000000000UL ;
return 0 ;
}
static void T_5 F_160 ( void )
{
F_30 ( ( unsigned long ) V_2 ) ;
F_159 () ;
}
