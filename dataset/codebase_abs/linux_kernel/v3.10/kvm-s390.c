int F_1 ( void * V_1 )
{
return 0 ;
}
void F_2 ( void * V_1 )
{
}
int F_3 ( void )
{
return 0 ;
}
void F_4 ( void )
{
}
void F_5 ( void * V_2 )
{
}
int F_6 ( void * V_3 )
{
return 0 ;
}
void F_7 ( void )
{
}
long F_8 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
if ( V_6 == V_8 )
return F_9 () ;
return - V_9 ;
}
int F_10 ( long V_10 )
{
int V_11 ;
switch ( V_10 ) {
case V_12 :
case V_13 :
case V_14 :
#ifdef F_11
case V_15 :
#endif
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
V_11 = 1 ;
break;
case V_21 :
case V_22 :
V_11 = V_23 ;
break;
case V_24 :
V_11 = V_25 ;
break;
case V_26 :
V_11 = V_27 ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
int F_12 ( struct V_28 * V_28 ,
struct V_29 * log )
{
return 0 ;
}
long F_13 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_28 * V_28 = V_5 -> V_30 ;
void T_1 * V_31 = ( void T_1 * ) V_7 ;
int V_11 ;
switch ( V_6 ) {
case V_32 : {
struct V_33 V_34 ;
V_11 = - V_35 ;
if ( F_14 ( & V_34 , V_31 , sizeof( V_34 ) ) )
break;
V_11 = F_15 ( V_28 , & V_34 ) ;
break;
}
default:
V_11 = - V_36 ;
}
return V_11 ;
}
int F_16 ( struct V_28 * V_28 , unsigned long type )
{
int V_37 ;
char V_38 [ 16 ] ;
V_37 = - V_9 ;
#ifdef F_11
if ( type & ~ V_39 )
goto V_40;
if ( ( type & V_39 ) && ( ! F_17 ( V_41 ) ) )
goto V_40;
#else
if ( type )
goto V_40;
#endif
V_37 = F_9 () ;
if ( V_37 )
goto V_40;
V_37 = - V_42 ;
V_28 -> V_43 . V_44 = (struct V_45 * ) F_18 ( V_46 ) ;
if ( ! V_28 -> V_43 . V_44 )
goto V_40;
sprintf ( V_38 , L_1 , V_47 -> V_48 ) ;
V_28 -> V_43 . V_49 = F_19 ( V_38 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_28 -> V_43 . V_49 )
goto V_50;
F_20 ( & V_28 -> V_43 . V_51 . V_52 ) ;
F_21 ( & V_28 -> V_43 . V_51 . V_53 ) ;
F_22 ( V_28 -> V_43 . V_49 , & V_54 ) ;
F_23 ( V_28 , 3 , L_2 , L_3 ) ;
if ( type & V_39 ) {
V_28 -> V_43 . V_55 = NULL ;
} else {
V_28 -> V_43 . V_55 = F_24 ( V_47 -> V_56 ) ;
if ( ! V_28 -> V_43 . V_55 )
goto V_57;
}
V_28 -> V_43 . V_58 = 0 ;
return 0 ;
V_57:
F_25 ( V_28 -> V_43 . V_49 ) ;
V_50:
F_26 ( ( unsigned long ) ( V_28 -> V_43 . V_44 ) ) ;
V_40:
return V_37 ;
}
void F_27 ( struct V_59 * V_60 )
{
F_28 ( V_60 , 3 , L_2 , L_4 ) ;
F_29 ( V_60 -> V_61 ) ;
if ( ! F_30 ( V_60 -> V_28 ) ) {
F_31 ( 63 - V_60 -> V_61 ,
( unsigned long * ) & V_60 -> V_28 -> V_43 . V_44 -> V_62 ) ;
if ( V_60 -> V_28 -> V_43 . V_44 -> V_63 [ V_60 -> V_61 ] . V_64 ==
( V_65 ) V_60 -> V_43 . V_66 )
V_60 -> V_28 -> V_43 . V_44 -> V_63 [ V_60 -> V_61 ] . V_64 = 0 ;
}
F_32 () ;
if ( F_30 ( V_60 -> V_28 ) )
F_33 ( V_60 -> V_43 . V_55 ) ;
F_26 ( ( unsigned long ) ( V_60 -> V_43 . V_66 ) ) ;
F_34 ( V_60 ) ;
F_35 ( V_60 ) ;
}
static void F_36 ( struct V_28 * V_28 )
{
unsigned int V_67 ;
struct V_59 * V_60 ;
F_37 (i, vcpu, kvm)
F_27 ( V_60 ) ;
F_38 ( & V_28 -> V_52 ) ;
for ( V_67 = 0 ; V_67 < F_39 ( & V_28 -> V_68 ) ; V_67 ++ )
V_28 -> V_69 [ V_67 ] = NULL ;
F_40 ( & V_28 -> V_68 , 0 ) ;
F_41 ( & V_28 -> V_52 ) ;
}
void F_42 ( struct V_28 * V_28 )
{
}
void F_43 ( struct V_28 * V_28 )
{
F_36 ( V_28 ) ;
F_26 ( ( unsigned long ) ( V_28 -> V_43 . V_44 ) ) ;
F_25 ( V_28 -> V_43 . V_49 ) ;
if ( ! F_30 ( V_28 ) )
F_33 ( V_28 -> V_43 . V_55 ) ;
}
int F_44 ( struct V_59 * V_60 )
{
if ( F_30 ( V_60 -> V_28 ) ) {
V_60 -> V_43 . V_55 = F_24 ( V_47 -> V_56 ) ;
if ( ! V_60 -> V_43 . V_55 )
return - V_42 ;
return 0 ;
}
V_60 -> V_43 . V_55 = V_60 -> V_28 -> V_43 . V_55 ;
V_60 -> V_70 -> V_71 = V_72 |
V_73 |
V_74 |
V_75 ;
return 0 ;
}
void F_45 ( struct V_59 * V_60 )
{
}
void F_46 ( struct V_59 * V_60 , int V_63 )
{
F_47 ( & V_60 -> V_43 . V_76 ) ;
F_48 ( V_60 -> V_43 . V_77 ) ;
V_60 -> V_43 . V_78 . V_79 &= V_80 ;
F_49 ( & V_60 -> V_43 . V_78 ) ;
F_50 ( V_60 -> V_70 -> V_81 . V_82 . V_83 ) ;
F_51 ( V_60 -> V_43 . V_55 ) ;
F_52 ( V_84 , & V_60 -> V_43 . V_66 -> V_85 ) ;
}
void F_53 ( struct V_59 * V_60 )
{
F_54 ( V_84 , & V_60 -> V_43 . V_66 -> V_85 ) ;
F_55 ( V_60 -> V_43 . V_55 ) ;
F_47 ( & V_60 -> V_43 . V_78 ) ;
F_48 ( V_60 -> V_70 -> V_81 . V_82 . V_83 ) ;
F_49 ( & V_60 -> V_43 . V_76 ) ;
F_50 ( V_60 -> V_43 . V_77 ) ;
}
static void F_56 ( struct V_59 * V_60 )
{
V_60 -> V_43 . V_66 -> V_86 . V_87 = 0UL ;
V_60 -> V_43 . V_66 -> V_86 . V_88 = 0UL ;
F_57 ( V_60 , 0 ) ;
V_60 -> V_43 . V_66 -> V_89 = 0UL ;
V_60 -> V_43 . V_66 -> V_90 = 0UL ;
V_60 -> V_43 . V_66 -> V_91 = 0 ;
memset ( V_60 -> V_43 . V_66 -> V_92 , 0 , 16 * sizeof( V_65 ) ) ;
V_60 -> V_43 . V_66 -> V_92 [ 0 ] = 0xE0UL ;
V_60 -> V_43 . V_66 -> V_92 [ 14 ] = 0xC2000000UL ;
V_60 -> V_43 . V_78 . V_79 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_60 -> V_43 . V_66 -> V_93 = 1 ;
F_52 ( V_94 , & V_60 -> V_43 . V_66 -> V_85 ) ;
}
int F_58 ( struct V_59 * V_60 )
{
return 0 ;
}
int F_59 ( struct V_59 * V_60 )
{
F_40 ( & V_60 -> V_43 . V_66 -> V_85 , V_95 |
V_96 |
V_94 ) ;
V_60 -> V_43 . V_66 -> V_97 = 6 ;
V_60 -> V_43 . V_66 -> V_98 = 0xC1002001U ;
V_60 -> V_43 . V_66 -> V_99 = ( int ) ( long ) V_100 ;
F_60 ( & V_60 -> V_43 . V_101 , V_102 , V_103 ) ;
F_61 ( & V_60 -> V_43 . V_104 , V_105 ,
( unsigned long ) V_60 ) ;
V_60 -> V_43 . V_101 . V_106 = V_107 ;
F_62 ( & V_60 -> V_43 . V_108 ) ;
V_60 -> V_43 . V_108 . V_109 = 0xff ;
return 0 ;
}
struct V_59 * F_63 ( struct V_28 * V_28 ,
unsigned int V_110 )
{
struct V_59 * V_60 ;
int V_37 = - V_9 ;
if ( V_110 >= V_23 )
goto V_111;
V_37 = - V_42 ;
V_60 = F_64 ( sizeof( struct V_59 ) , V_46 ) ;
if ( ! V_60 )
goto V_111;
V_60 -> V_43 . V_66 = (struct V_112 * )
F_18 ( V_46 ) ;
if ( ! V_60 -> V_43 . V_66 )
goto V_113;
V_60 -> V_43 . V_66 -> V_114 = V_110 ;
if ( ! F_30 ( V_28 ) ) {
if ( ! V_28 -> V_43 . V_44 ) {
F_65 ( 1 ) ;
goto V_113;
}
if ( ! V_28 -> V_43 . V_44 -> V_63 [ V_110 ] . V_64 )
V_28 -> V_43 . V_44 -> V_63 [ V_110 ] . V_64 =
( V_65 ) V_60 -> V_43 . V_66 ;
V_60 -> V_43 . V_66 -> V_115 =
( V_116 ) ( ( ( V_65 ) V_28 -> V_43 . V_44 ) >> 32 ) ;
V_60 -> V_43 . V_66 -> V_117 = ( V_116 ) ( V_65 ) V_28 -> V_43 . V_44 ;
F_66 ( 63 - V_110 , ( unsigned long * ) & V_28 -> V_43 . V_44 -> V_62 ) ;
}
F_20 ( & V_60 -> V_43 . V_118 . V_52 ) ;
F_21 ( & V_60 -> V_43 . V_118 . V_53 ) ;
V_60 -> V_43 . V_118 . V_51 = & V_28 -> V_43 . V_51 ;
F_67 ( & V_28 -> V_43 . V_51 . V_52 ) ;
V_28 -> V_43 . V_51 . V_118 [ V_110 ] = & V_60 -> V_43 . V_118 ;
F_68 ( & V_60 -> V_43 . V_118 . V_119 ) ;
V_60 -> V_43 . V_118 . V_85 = & V_60 -> V_43 . V_66 -> V_85 ;
F_69 ( & V_28 -> V_43 . V_51 . V_52 ) ;
V_37 = F_70 ( V_60 , V_28 , V_110 ) ;
if ( V_37 )
goto V_120;
F_23 ( V_28 , 3 , L_5 , V_110 , V_60 ,
V_60 -> V_43 . V_66 ) ;
F_71 ( V_110 , V_60 , V_60 -> V_43 . V_66 ) ;
return V_60 ;
V_120:
F_26 ( ( unsigned long ) ( V_60 -> V_43 . V_66 ) ) ;
V_113:
F_35 ( V_60 ) ;
V_111:
return F_72 ( V_37 ) ;
}
int F_73 ( struct V_59 * V_60 )
{
F_74 () ;
return 0 ;
}
int F_75 ( struct V_59 * V_60 )
{
F_74 () ;
return 0 ;
}
static int F_76 ( struct V_59 * V_60 ,
struct V_121 * V_122 )
{
int V_11 = - V_9 ;
switch ( V_122 -> V_110 ) {
case V_123 :
V_11 = F_77 ( V_60 -> V_43 . V_66 -> V_91 ,
( V_124 T_1 * ) V_122 -> V_88 ) ;
break;
case V_125 :
V_11 = F_77 ( V_60 -> V_43 . V_66 -> V_126 ,
( V_127 T_1 * ) V_122 -> V_88 ) ;
break;
case V_128 :
V_11 = F_77 ( V_60 -> V_43 . V_66 -> V_89 ,
( V_127 T_1 * ) V_122 -> V_88 ) ;
break;
case V_129 :
V_11 = F_77 ( V_60 -> V_43 . V_66 -> V_90 ,
( V_127 T_1 * ) V_122 -> V_88 ) ;
break;
default:
break;
}
return V_11 ;
}
static int F_78 ( struct V_59 * V_60 ,
struct V_121 * V_122 )
{
int V_11 = - V_9 ;
switch ( V_122 -> V_110 ) {
case V_123 :
V_11 = F_79 ( V_60 -> V_43 . V_66 -> V_91 ,
( V_124 T_1 * ) V_122 -> V_88 ) ;
break;
case V_125 :
V_11 = F_79 ( V_60 -> V_43 . V_66 -> V_126 ,
( V_127 T_1 * ) V_122 -> V_88 ) ;
break;
case V_128 :
V_11 = F_79 ( V_60 -> V_43 . V_66 -> V_89 ,
( V_127 T_1 * ) V_122 -> V_88 ) ;
break;
case V_129 :
V_11 = F_79 ( V_60 -> V_43 . V_66 -> V_90 ,
( V_127 T_1 * ) V_122 -> V_88 ) ;
break;
default:
break;
}
return V_11 ;
}
static int F_80 ( struct V_59 * V_60 )
{
F_56 ( V_60 ) ;
return 0 ;
}
int F_81 ( struct V_59 * V_60 , struct V_130 * V_82 )
{
memcpy ( & V_60 -> V_70 -> V_81 . V_82 . V_131 , & V_82 -> V_131 , sizeof( V_82 -> V_131 ) ) ;
return 0 ;
}
int F_82 ( struct V_59 * V_60 , struct V_130 * V_82 )
{
memcpy ( & V_82 -> V_131 , & V_60 -> V_70 -> V_81 . V_82 . V_131 , sizeof( V_82 -> V_131 ) ) ;
return 0 ;
}
int F_83 ( struct V_59 * V_60 ,
struct V_132 * V_133 )
{
memcpy ( & V_60 -> V_70 -> V_81 . V_82 . V_83 , & V_133 -> V_83 , sizeof( V_133 -> V_83 ) ) ;
memcpy ( & V_60 -> V_43 . V_66 -> V_92 , & V_133 -> V_134 , sizeof( V_133 -> V_134 ) ) ;
F_50 ( V_60 -> V_70 -> V_81 . V_82 . V_83 ) ;
return 0 ;
}
int F_84 ( struct V_59 * V_60 ,
struct V_132 * V_133 )
{
memcpy ( & V_133 -> V_83 , & V_60 -> V_70 -> V_81 . V_82 . V_83 , sizeof( V_133 -> V_83 ) ) ;
memcpy ( & V_133 -> V_134 , & V_60 -> V_43 . V_66 -> V_92 , sizeof( V_133 -> V_134 ) ) ;
return 0 ;
}
int F_85 ( struct V_59 * V_60 , struct V_135 * V_136 )
{
memcpy ( & V_60 -> V_43 . V_78 . V_137 , & V_136 -> V_137 , sizeof( V_136 -> V_137 ) ) ;
V_60 -> V_43 . V_78 . V_79 = V_136 -> V_79 & V_80 ;
F_49 ( & V_60 -> V_43 . V_78 ) ;
return 0 ;
}
int F_86 ( struct V_59 * V_60 , struct V_135 * V_136 )
{
memcpy ( & V_136 -> V_137 , & V_60 -> V_43 . V_78 . V_137 , sizeof( V_136 -> V_137 ) ) ;
V_136 -> V_79 = V_60 -> V_43 . V_78 . V_79 ;
return 0 ;
}
static int F_87 ( struct V_59 * V_60 , T_2 V_138 )
{
int V_37 = 0 ;
if ( ! ( F_39 ( & V_60 -> V_43 . V_66 -> V_85 ) & V_94 ) )
V_37 = - V_139 ;
else {
V_60 -> V_70 -> V_140 = V_138 . V_87 ;
V_60 -> V_70 -> V_141 = V_138 . V_88 ;
}
return V_37 ;
}
int F_88 ( struct V_59 * V_60 ,
struct V_142 * V_143 )
{
return - V_9 ;
}
int F_89 ( struct V_59 * V_60 ,
struct V_144 * V_145 )
{
return - V_9 ;
}
int F_90 ( struct V_59 * V_60 ,
struct V_146 * V_147 )
{
return - V_9 ;
}
int F_91 ( struct V_59 * V_60 ,
struct V_146 * V_147 )
{
return - V_9 ;
}
static int F_92 ( struct V_59 * V_60 )
{
int V_37 ;
memcpy ( & V_60 -> V_43 . V_66 -> V_148 , & V_60 -> V_70 -> V_81 . V_82 . V_131 [ 14 ] , 16 ) ;
if ( F_93 () )
F_94 () ;
if ( F_95 ( V_149 ) )
F_96 () ;
if ( ! F_30 ( V_60 -> V_28 ) )
F_97 ( V_60 ) ;
V_60 -> V_43 . V_66 -> V_150 = 0 ;
F_98 () ;
F_99 () ;
F_100 () ;
F_28 ( V_60 , 6 , L_6 ,
F_39 ( & V_60 -> V_43 . V_66 -> V_85 ) ) ;
F_101 ( V_60 ,
F_39 ( & V_60 -> V_43 . V_66 -> V_85 ) ) ;
V_37 = F_102 ( V_60 -> V_43 . V_66 , V_60 -> V_70 -> V_81 . V_82 . V_131 ) ;
if ( V_37 ) {
if ( F_30 ( V_60 -> V_28 ) ) {
V_37 = V_151 ;
} else {
F_28 ( V_60 , 3 , L_2 , L_7 ) ;
F_103 ( V_60 ) ;
V_37 = F_104 ( V_60 , V_152 ) ;
}
}
F_28 ( V_60 , 6 , L_8 ,
V_60 -> V_43 . V_66 -> V_150 ) ;
F_105 ( V_60 , V_60 -> V_43 . V_66 -> V_150 ) ;
F_106 () ;
memcpy ( & V_60 -> V_70 -> V_81 . V_82 . V_131 [ 14 ] , & V_60 -> V_43 . V_66 -> V_148 , 16 ) ;
return V_37 ;
}
int F_107 ( struct V_59 * V_60 , struct V_153 * V_153 )
{
int V_37 ;
T_3 V_154 ;
V_155:
if ( V_60 -> V_156 )
F_108 ( V_157 , & V_60 -> V_158 , & V_154 ) ;
F_54 ( V_94 , & V_60 -> V_43 . V_66 -> V_85 ) ;
F_109 ( V_60 -> V_28 -> V_43 . V_51 . V_118 [ V_60 -> V_61 ] == NULL ) ;
switch ( V_153 -> V_159 ) {
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
break;
default:
F_74 () ;
}
V_60 -> V_43 . V_66 -> V_86 . V_87 = V_153 -> V_140 ;
V_60 -> V_43 . V_66 -> V_86 . V_88 = V_153 -> V_141 ;
if ( V_153 -> V_166 & V_72 ) {
V_153 -> V_166 &= ~ V_72 ;
F_57 ( V_60 , V_153 -> V_81 . V_82 . V_167 ) ;
}
if ( V_153 -> V_166 & V_75 ) {
V_153 -> V_166 &= ~ V_75 ;
memcpy ( & V_60 -> V_43 . V_66 -> V_92 , & V_153 -> V_81 . V_82 . V_134 , 128 ) ;
F_57 ( V_60 , V_153 -> V_81 . V_82 . V_167 ) ;
}
F_110 () ;
do {
V_37 = F_92 ( V_60 ) ;
if ( V_37 )
break;
if ( F_30 ( V_60 -> V_28 ) )
V_37 = - V_168 ;
else
V_37 = F_111 ( V_60 ) ;
} while ( ! F_112 ( V_47 ) && ! V_37 );
if ( V_37 == V_169 )
goto V_155;
if ( F_112 ( V_47 ) && ! V_37 ) {
V_153 -> V_159 = V_162 ;
V_37 = - V_170 ;
}
#ifdef F_11
if ( V_37 == V_151 ) {
V_153 -> V_159 = V_164 ;
V_153 -> V_171 . V_172 =
V_47 -> V_173 . V_174 ;
V_153 -> V_171 . V_175 = 0x10 ;
V_37 = 0 ;
}
#endif
if ( V_37 == - V_168 ) {
V_153 -> V_159 = V_160 ;
V_153 -> V_176 . V_150 = V_60 -> V_43 . V_66 -> V_150 ;
V_153 -> V_176 . V_177 = V_60 -> V_43 . V_66 -> V_177 ;
V_153 -> V_176 . V_178 = V_60 -> V_43 . V_66 -> V_178 ;
V_37 = 0 ;
}
if ( V_37 == - V_179 ) {
V_37 = 0 ;
}
V_153 -> V_140 = V_60 -> V_43 . V_66 -> V_86 . V_87 ;
V_153 -> V_141 = V_60 -> V_43 . V_66 -> V_86 . V_88 ;
V_153 -> V_81 . V_82 . V_167 = V_60 -> V_43 . V_66 -> V_167 ;
memcpy ( & V_153 -> V_81 . V_82 . V_134 , & V_60 -> V_43 . V_66 -> V_92 , 128 ) ;
if ( V_60 -> V_156 )
F_108 ( V_157 , & V_154 , NULL ) ;
V_60 -> V_180 . V_181 ++ ;
return V_37 ;
}
static int F_113 ( struct V_59 * V_60 , V_127 V_182 , void * V_183 ,
unsigned long V_184 , int V_167 )
{
if ( V_167 )
return F_114 ( V_60 , V_182 , V_183 , V_184 ) ;
else
return F_115 ( V_60 , V_182 , V_183 , V_184 ) ;
}
int F_116 ( struct V_59 * V_60 , unsigned long V_88 )
{
unsigned char V_185 = 1 ;
int V_167 ;
if ( V_88 == V_186 ) {
if ( F_115 ( V_60 , 163ul , & V_185 , 1 ) )
return - V_35 ;
V_88 = V_187 ;
V_167 = 0 ;
} else if ( V_88 == V_188 ) {
if ( F_114 ( V_60 , 163ul , & V_185 , 1 ) )
return - V_35 ;
V_88 = V_187 ;
V_167 = 1 ;
} else
V_167 = 0 ;
F_47 ( & V_60 -> V_43 . V_78 ) ;
F_48 ( V_60 -> V_70 -> V_81 . V_82 . V_83 ) ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_190 ) ,
V_60 -> V_43 . V_78 . V_137 , 128 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_191 ) ,
V_60 -> V_70 -> V_81 . V_82 . V_131 , 128 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_138 ) ,
& V_60 -> V_43 . V_66 -> V_86 , 16 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_192 ) ,
& V_60 -> V_43 . V_66 -> V_167 , 4 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 ,
V_88 + F_117 ( struct V_189 , V_193 ) ,
& V_60 -> V_43 . V_78 . V_79 , 4 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_194 ) ,
& V_60 -> V_43 . V_66 -> V_91 , 4 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_195 ) ,
& V_60 -> V_43 . V_66 -> V_89 , 8 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_196 ) ,
& V_60 -> V_43 . V_66 -> V_90 , 8 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 , V_88 + F_117 ( struct V_189 , V_197 ) ,
& V_60 -> V_70 -> V_81 . V_82 . V_83 , 64 , V_167 ) )
return - V_35 ;
if ( F_113 ( V_60 ,
V_88 + F_117 ( struct V_189 , V_198 ) ,
& V_60 -> V_43 . V_66 -> V_92 , 128 , V_167 ) )
return - V_35 ;
return 0 ;
}
static int F_118 ( struct V_59 * V_60 ,
struct V_199 * V_200 )
{
int V_11 ;
if ( V_200 -> V_201 )
return - V_9 ;
switch ( V_200 -> V_200 ) {
case V_19 :
if ( ! V_60 -> V_28 -> V_43 . V_58 ) {
V_60 -> V_28 -> V_43 . V_58 = 1 ;
F_119 ( V_60 -> V_28 ) ;
}
V_11 = 0 ;
break;
default:
V_11 = - V_9 ;
break;
}
return V_11 ;
}
long F_120 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_59 * V_60 = V_5 -> V_30 ;
void T_1 * V_31 = ( void T_1 * ) V_7 ;
long V_11 ;
switch ( V_6 ) {
case V_32 : {
struct V_33 V_34 ;
V_11 = - V_35 ;
if ( F_14 ( & V_34 , V_31 , sizeof( V_34 ) ) )
break;
V_11 = F_121 ( V_60 , & V_34 ) ;
break;
}
case V_202 :
V_11 = F_116 ( V_60 , V_7 ) ;
break;
case V_203 : {
T_2 V_138 ;
V_11 = - V_35 ;
if ( F_14 ( & V_138 , V_31 , sizeof( V_138 ) ) )
break;
V_11 = F_87 ( V_60 , V_138 ) ;
break;
}
case V_204 :
V_11 = F_80 ( V_60 ) ;
break;
case V_205 :
case V_206 : {
struct V_121 V_122 ;
V_11 = - V_35 ;
if ( F_14 ( & V_122 , V_31 , sizeof( V_122 ) ) )
break;
if ( V_6 == V_205 )
V_11 = F_78 ( V_60 , & V_122 ) ;
else
V_11 = F_76 ( V_60 , & V_122 ) ;
break;
}
#ifdef F_11
case V_207 : {
struct V_208 V_209 ;
if ( F_14 ( & V_209 , V_31 , sizeof( V_209 ) ) ) {
V_11 = - V_35 ;
break;
}
if ( ! F_30 ( V_60 -> V_28 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_122 ( V_60 -> V_43 . V_55 , V_209 . V_210 ,
V_209 . V_211 , V_209 . V_212 ) ;
break;
}
case V_213 : {
struct V_208 V_209 ;
if ( F_14 ( & V_209 , V_31 , sizeof( V_209 ) ) ) {
V_11 = - V_35 ;
break;
}
if ( ! F_30 ( V_60 -> V_28 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_123 ( V_60 -> V_43 . V_55 , V_209 . V_211 ,
V_209 . V_212 ) ;
break;
}
#endif
case V_214 : {
V_11 = F_124 ( V_7 , V_60 -> V_43 . V_55 ) ;
if ( ! F_125 ( V_11 ) )
V_11 = 0 ;
break;
}
case V_215 :
{
struct V_199 V_200 ;
V_11 = - V_35 ;
if ( F_14 ( & V_200 , V_31 , sizeof( V_200 ) ) )
break;
V_11 = F_118 ( V_60 , & V_200 ) ;
break;
}
default:
V_11 = - V_36 ;
}
return V_11 ;
}
int F_126 ( struct V_59 * V_60 , struct V_216 * V_217 )
{
#ifdef F_11
if ( ( V_217 -> V_218 == V_219 )
&& ( F_30 ( V_60 -> V_28 ) ) ) {
V_217 -> V_220 = F_127 ( V_60 -> V_43 . V_66 ) ;
F_128 ( V_217 -> V_220 ) ;
return 0 ;
}
#endif
return V_221 ;
}
void F_129 ( struct V_222 * free ,
struct V_222 * V_223 )
{
}
int F_130 ( struct V_222 * V_224 , unsigned long V_225 )
{
return 0 ;
}
int F_131 ( struct V_28 * V_28 ,
struct V_222 * V_226 ,
struct V_227 * V_228 ,
enum V_229 V_230 )
{
if ( V_228 -> V_231 & 0xffffful )
return - V_9 ;
if ( V_228 -> V_232 & 0xffffful )
return - V_9 ;
return 0 ;
}
void F_132 ( struct V_28 * V_28 ,
struct V_227 * V_228 ,
const struct V_222 * V_233 ,
enum V_229 V_230 )
{
int V_37 ;
if ( V_233 -> V_231 == V_228 -> V_231 &&
V_233 -> V_234 * V_235 == V_228 -> V_236 &&
V_233 -> V_225 * V_235 == V_228 -> V_232 )
return;
V_37 = F_122 ( V_28 -> V_43 . V_55 , V_228 -> V_231 ,
V_228 -> V_236 , V_228 -> V_232 ) ;
if ( V_37 )
F_133 ( V_237 L_9 ) ;
return;
}
void F_134 ( struct V_28 * V_28 )
{
}
void F_135 ( struct V_28 * V_28 ,
struct V_222 * V_224 )
{
}
static int T_4 F_136 ( void )
{
int V_238 ;
V_238 = F_137 ( NULL , sizeof( struct V_59 ) , 0 , V_239 ) ;
if ( V_238 )
return V_238 ;
V_100 = ( unsigned long long * ) F_18 ( V_46 | V_240 ) ;
if ( ! V_100 ) {
F_138 () ;
return - V_42 ;
}
memcpy ( V_100 , V_241 . V_242 , 16 ) ;
V_100 [ 0 ] &= 0xff00fff3f47c0000ULL ;
V_100 [ 1 ] &= 0x001c000000000000ULL ;
return 0 ;
}
static void T_5 F_139 ( void )
{
F_26 ( ( unsigned long ) V_100 ) ;
F_138 () ;
}
