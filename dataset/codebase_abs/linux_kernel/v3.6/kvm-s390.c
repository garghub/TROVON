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
V_11 = 1 ;
break;
case V_18 :
case V_19 :
V_11 = V_20 ;
break;
case V_21 :
V_11 = F_12 () & 0x2 ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
int F_13 ( struct V_22 * V_22 ,
struct V_23 * log )
{
return 0 ;
}
long F_14 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_22 * V_22 = V_5 -> V_24 ;
void T_1 * V_25 = ( void T_1 * ) V_7 ;
int V_11 ;
switch ( V_6 ) {
case V_26 : {
struct V_27 V_28 ;
V_11 = - V_29 ;
if ( F_15 ( & V_28 , V_25 , sizeof( V_28 ) ) )
break;
V_11 = F_16 ( V_22 , & V_28 ) ;
break;
}
default:
V_11 = - V_30 ;
}
return V_11 ;
}
int F_17 ( struct V_22 * V_22 , unsigned long type )
{
int V_31 ;
char V_32 [ 16 ] ;
V_31 = - V_9 ;
#ifdef F_11
if ( type & ~ V_33 )
goto V_34;
if ( ( type & V_33 ) && ( ! F_18 ( V_35 ) ) )
goto V_34;
#else
if ( type )
goto V_34;
#endif
V_31 = F_9 () ;
if ( V_31 )
goto V_34;
V_31 = - V_36 ;
V_22 -> V_37 . V_38 = (struct V_39 * ) F_19 ( V_40 ) ;
if ( ! V_22 -> V_37 . V_38 )
goto V_34;
sprintf ( V_32 , L_1 , V_41 -> V_42 ) ;
V_22 -> V_37 . V_43 = F_20 ( V_32 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_22 -> V_37 . V_43 )
goto V_44;
F_21 ( & V_22 -> V_37 . V_45 . V_46 ) ;
F_22 ( & V_22 -> V_37 . V_45 . V_47 ) ;
F_23 ( V_22 -> V_37 . V_43 , & V_48 ) ;
F_24 ( V_22 , 3 , L_2 , L_3 ) ;
if ( type & V_33 ) {
V_22 -> V_37 . V_49 = NULL ;
} else {
V_22 -> V_37 . V_49 = F_25 ( V_41 -> V_50 ) ;
if ( ! V_22 -> V_37 . V_49 )
goto V_51;
}
return 0 ;
V_51:
F_26 ( V_22 -> V_37 . V_43 ) ;
V_44:
F_27 ( ( unsigned long ) ( V_22 -> V_37 . V_38 ) ) ;
V_34:
return V_31 ;
}
void F_28 ( struct V_52 * V_53 )
{
F_29 ( V_53 , 3 , L_2 , L_4 ) ;
if ( ! F_30 ( V_53 -> V_22 ) ) {
F_31 ( 63 - V_53 -> V_54 ,
( unsigned long * ) & V_53 -> V_22 -> V_37 . V_38 -> V_55 ) ;
if ( V_53 -> V_22 -> V_37 . V_38 -> V_56 [ V_53 -> V_54 ] . V_57 ==
( V_58 ) V_53 -> V_37 . V_59 )
V_53 -> V_22 -> V_37 . V_38 -> V_56 [ V_53 -> V_54 ] . V_57 = 0 ;
}
F_32 () ;
if ( F_30 ( V_53 -> V_22 ) )
F_33 ( V_53 -> V_37 . V_49 ) ;
F_27 ( ( unsigned long ) ( V_53 -> V_37 . V_59 ) ) ;
F_34 ( V_53 ) ;
F_35 ( V_53 ) ;
}
static void F_36 ( struct V_22 * V_22 )
{
unsigned int V_60 ;
struct V_52 * V_53 ;
F_37 (i, vcpu, kvm)
F_28 ( V_53 ) ;
F_38 ( & V_22 -> V_46 ) ;
for ( V_60 = 0 ; V_60 < F_39 ( & V_22 -> V_61 ) ; V_60 ++ )
V_22 -> V_62 [ V_60 ] = NULL ;
F_40 ( & V_22 -> V_61 , 0 ) ;
F_41 ( & V_22 -> V_46 ) ;
}
void F_42 ( struct V_22 * V_22 )
{
}
void F_43 ( struct V_22 * V_22 )
{
F_36 ( V_22 ) ;
F_27 ( ( unsigned long ) ( V_22 -> V_37 . V_38 ) ) ;
F_26 ( V_22 -> V_37 . V_43 ) ;
if ( ! F_30 ( V_22 ) )
F_33 ( V_22 -> V_37 . V_49 ) ;
}
int F_44 ( struct V_52 * V_53 )
{
if ( F_30 ( V_53 -> V_22 ) ) {
V_53 -> V_37 . V_49 = F_25 ( V_41 -> V_50 ) ;
if ( ! V_53 -> V_37 . V_49 )
return - V_36 ;
return 0 ;
}
V_53 -> V_37 . V_49 = V_53 -> V_22 -> V_37 . V_49 ;
V_53 -> V_63 -> V_64 = V_65 |
V_66 |
V_67 |
V_68 ;
return 0 ;
}
void F_45 ( struct V_52 * V_53 )
{
}
void F_46 ( struct V_52 * V_53 , int V_56 )
{
F_47 ( & V_53 -> V_37 . V_69 ) ;
F_48 ( V_53 -> V_37 . V_70 ) ;
V_53 -> V_37 . V_71 . V_72 &= V_73 ;
F_49 ( & V_53 -> V_37 . V_71 ) ;
F_50 ( V_53 -> V_63 -> V_74 . V_75 . V_76 ) ;
F_51 ( V_53 -> V_37 . V_49 ) ;
F_52 ( V_77 , & V_53 -> V_37 . V_59 -> V_78 ) ;
}
void F_53 ( struct V_52 * V_53 )
{
F_54 ( V_77 , & V_53 -> V_37 . V_59 -> V_78 ) ;
F_55 ( V_53 -> V_37 . V_49 ) ;
F_47 ( & V_53 -> V_37 . V_71 ) ;
F_48 ( V_53 -> V_63 -> V_74 . V_75 . V_76 ) ;
F_49 ( & V_53 -> V_37 . V_69 ) ;
F_50 ( V_53 -> V_37 . V_70 ) ;
}
static void F_56 ( struct V_52 * V_53 )
{
V_53 -> V_37 . V_59 -> V_79 . V_80 = 0UL ;
V_53 -> V_37 . V_59 -> V_79 . V_81 = 0UL ;
F_57 ( V_53 , 0 ) ;
V_53 -> V_37 . V_59 -> V_82 = 0UL ;
V_53 -> V_37 . V_59 -> V_83 = 0UL ;
V_53 -> V_37 . V_59 -> V_84 = 0 ;
memset ( V_53 -> V_37 . V_59 -> V_85 , 0 , 16 * sizeof( V_58 ) ) ;
V_53 -> V_37 . V_59 -> V_85 [ 0 ] = 0xE0UL ;
V_53 -> V_37 . V_59 -> V_85 [ 14 ] = 0xC2000000UL ;
V_53 -> V_37 . V_71 . V_72 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_53 -> V_37 . V_59 -> V_86 = 1 ;
F_52 ( V_87 , & V_53 -> V_37 . V_59 -> V_78 ) ;
}
int F_58 ( struct V_52 * V_53 )
{
F_40 ( & V_53 -> V_37 . V_59 -> V_78 , V_88 |
V_89 |
V_87 ) ;
V_53 -> V_37 . V_59 -> V_90 = 6 ;
V_53 -> V_37 . V_59 -> V_91 = 0xC1002001U ;
V_53 -> V_37 . V_59 -> V_92 = ( int ) ( long ) V_93 ;
F_59 ( & V_53 -> V_37 . V_94 , V_95 , V_96 ) ;
F_60 ( & V_53 -> V_37 . V_97 , V_98 ,
( unsigned long ) V_53 ) ;
V_53 -> V_37 . V_94 . V_99 = V_100 ;
F_61 ( & V_53 -> V_37 . V_101 ) ;
V_53 -> V_37 . V_101 . V_102 = 0xff ;
return 0 ;
}
struct V_52 * F_62 ( struct V_22 * V_22 ,
unsigned int V_103 )
{
struct V_52 * V_53 ;
int V_31 = - V_9 ;
if ( V_103 >= V_20 )
goto V_104;
V_31 = - V_36 ;
V_53 = F_63 ( sizeof( struct V_52 ) , V_40 ) ;
if ( ! V_53 )
goto V_104;
V_53 -> V_37 . V_59 = (struct V_105 * )
F_19 ( V_40 ) ;
if ( ! V_53 -> V_37 . V_59 )
goto V_106;
V_53 -> V_37 . V_59 -> V_107 = V_103 ;
if ( ! F_30 ( V_22 ) ) {
if ( ! V_22 -> V_37 . V_38 ) {
F_64 ( 1 ) ;
goto V_106;
}
if ( ! V_22 -> V_37 . V_38 -> V_56 [ V_103 ] . V_57 )
V_22 -> V_37 . V_38 -> V_56 [ V_103 ] . V_57 =
( V_58 ) V_53 -> V_37 . V_59 ;
V_53 -> V_37 . V_59 -> V_108 =
( V_109 ) ( ( ( V_58 ) V_22 -> V_37 . V_38 ) >> 32 ) ;
V_53 -> V_37 . V_59 -> V_110 = ( V_109 ) ( V_58 ) V_22 -> V_37 . V_38 ;
F_65 ( 63 - V_103 , ( unsigned long * ) & V_22 -> V_37 . V_38 -> V_55 ) ;
}
F_21 ( & V_53 -> V_37 . V_111 . V_46 ) ;
F_22 ( & V_53 -> V_37 . V_111 . V_47 ) ;
V_53 -> V_37 . V_111 . V_45 = & V_22 -> V_37 . V_45 ;
F_66 ( & V_22 -> V_37 . V_45 . V_46 ) ;
V_22 -> V_37 . V_45 . V_111 [ V_103 ] = & V_53 -> V_37 . V_111 ;
F_67 ( & V_53 -> V_37 . V_111 . V_112 ) ;
V_53 -> V_37 . V_111 . V_78 = & V_53 -> V_37 . V_59 -> V_78 ;
F_68 ( & V_22 -> V_37 . V_45 . V_46 ) ;
V_31 = F_69 ( V_53 , V_22 , V_103 ) ;
if ( V_31 )
goto V_113;
F_24 ( V_22 , 3 , L_5 , V_103 , V_53 ,
V_53 -> V_37 . V_59 ) ;
return V_53 ;
V_113:
F_27 ( ( unsigned long ) ( V_53 -> V_37 . V_59 ) ) ;
V_106:
F_35 ( V_53 ) ;
V_104:
return F_70 ( V_31 ) ;
}
int F_71 ( struct V_52 * V_53 )
{
F_72 () ;
return 0 ;
}
int F_73 ( struct V_52 * V_53 )
{
F_72 () ;
return 0 ;
}
static int F_74 ( struct V_52 * V_53 ,
struct V_114 * V_115 )
{
int V_11 = - V_9 ;
switch ( V_115 -> V_103 ) {
case V_116 :
V_11 = F_75 ( V_53 -> V_37 . V_59 -> V_84 ,
( V_117 T_1 * ) V_115 -> V_81 ) ;
break;
case V_118 :
V_11 = F_75 ( V_53 -> V_37 . V_59 -> V_119 ,
( V_120 T_1 * ) V_115 -> V_81 ) ;
break;
case V_121 :
V_11 = F_75 ( V_53 -> V_37 . V_59 -> V_82 ,
( V_120 T_1 * ) V_115 -> V_81 ) ;
break;
case V_122 :
V_11 = F_75 ( V_53 -> V_37 . V_59 -> V_83 ,
( V_120 T_1 * ) V_115 -> V_81 ) ;
break;
default:
break;
}
return V_11 ;
}
static int F_76 ( struct V_52 * V_53 ,
struct V_114 * V_115 )
{
int V_11 = - V_9 ;
switch ( V_115 -> V_103 ) {
case V_116 :
V_11 = F_77 ( V_53 -> V_37 . V_59 -> V_84 ,
( V_117 T_1 * ) V_115 -> V_81 ) ;
break;
case V_118 :
V_11 = F_77 ( V_53 -> V_37 . V_59 -> V_119 ,
( V_120 T_1 * ) V_115 -> V_81 ) ;
break;
case V_121 :
V_11 = F_77 ( V_53 -> V_37 . V_59 -> V_82 ,
( V_120 T_1 * ) V_115 -> V_81 ) ;
break;
case V_122 :
V_11 = F_77 ( V_53 -> V_37 . V_59 -> V_83 ,
( V_120 T_1 * ) V_115 -> V_81 ) ;
break;
default:
break;
}
return V_11 ;
}
static int F_78 ( struct V_52 * V_53 )
{
F_56 ( V_53 ) ;
return 0 ;
}
int F_79 ( struct V_52 * V_53 , struct V_123 * V_75 )
{
memcpy ( & V_53 -> V_63 -> V_74 . V_75 . V_124 , & V_75 -> V_124 , sizeof( V_75 -> V_124 ) ) ;
return 0 ;
}
int F_80 ( struct V_52 * V_53 , struct V_123 * V_75 )
{
memcpy ( & V_75 -> V_124 , & V_53 -> V_63 -> V_74 . V_75 . V_124 , sizeof( V_75 -> V_124 ) ) ;
return 0 ;
}
int F_81 ( struct V_52 * V_53 ,
struct V_125 * V_126 )
{
memcpy ( & V_53 -> V_63 -> V_74 . V_75 . V_76 , & V_126 -> V_76 , sizeof( V_126 -> V_76 ) ) ;
memcpy ( & V_53 -> V_37 . V_59 -> V_85 , & V_126 -> V_127 , sizeof( V_126 -> V_127 ) ) ;
F_50 ( V_53 -> V_63 -> V_74 . V_75 . V_76 ) ;
return 0 ;
}
int F_82 ( struct V_52 * V_53 ,
struct V_125 * V_126 )
{
memcpy ( & V_126 -> V_76 , & V_53 -> V_63 -> V_74 . V_75 . V_76 , sizeof( V_126 -> V_76 ) ) ;
memcpy ( & V_126 -> V_127 , & V_53 -> V_37 . V_59 -> V_85 , sizeof( V_126 -> V_127 ) ) ;
return 0 ;
}
int F_83 ( struct V_52 * V_53 , struct V_128 * V_129 )
{
memcpy ( & V_53 -> V_37 . V_71 . V_130 , & V_129 -> V_130 , sizeof( V_129 -> V_130 ) ) ;
V_53 -> V_37 . V_71 . V_72 = V_129 -> V_72 & V_73 ;
F_49 ( & V_53 -> V_37 . V_71 ) ;
return 0 ;
}
int F_84 ( struct V_52 * V_53 , struct V_128 * V_129 )
{
memcpy ( & V_129 -> V_130 , & V_53 -> V_37 . V_71 . V_130 , sizeof( V_129 -> V_130 ) ) ;
V_129 -> V_72 = V_53 -> V_37 . V_71 . V_72 ;
return 0 ;
}
static int F_85 ( struct V_52 * V_53 , T_2 V_131 )
{
int V_31 = 0 ;
if ( ! ( F_39 ( & V_53 -> V_37 . V_59 -> V_78 ) & V_87 ) )
V_31 = - V_132 ;
else {
V_53 -> V_63 -> V_133 = V_131 . V_80 ;
V_53 -> V_63 -> V_134 = V_131 . V_81 ;
}
return V_31 ;
}
int F_86 ( struct V_52 * V_53 ,
struct V_135 * V_136 )
{
return - V_9 ;
}
int F_87 ( struct V_52 * V_53 ,
struct V_137 * V_138 )
{
return - V_9 ;
}
int F_88 ( struct V_52 * V_53 ,
struct V_139 * V_140 )
{
return - V_9 ;
}
int F_89 ( struct V_52 * V_53 ,
struct V_139 * V_140 )
{
return - V_9 ;
}
static int F_90 ( struct V_52 * V_53 )
{
int V_31 ;
memcpy ( & V_53 -> V_37 . V_59 -> V_141 , & V_53 -> V_63 -> V_74 . V_75 . V_124 [ 14 ] , 16 ) ;
if ( F_91 () )
F_92 () ;
if ( F_93 ( V_142 ) )
F_94 () ;
if ( ! F_30 ( V_53 -> V_22 ) )
F_95 ( V_53 ) ;
V_53 -> V_37 . V_59 -> V_143 = 0 ;
F_96 () ;
F_97 () ;
F_98 () ;
F_29 ( V_53 , 6 , L_6 ,
F_39 ( & V_53 -> V_37 . V_59 -> V_78 ) ) ;
V_31 = F_99 ( V_53 -> V_37 . V_59 , V_53 -> V_63 -> V_74 . V_75 . V_124 ) ;
if ( V_31 ) {
if ( F_30 ( V_53 -> V_22 ) ) {
V_31 = V_144 ;
} else {
F_29 ( V_53 , 3 , L_2 , L_7 ) ;
F_100 ( V_53 , V_145 ) ;
V_31 = 0 ;
}
}
F_29 ( V_53 , 6 , L_8 ,
V_53 -> V_37 . V_59 -> V_143 ) ;
F_96 () ;
F_101 () ;
F_98 () ;
memcpy ( & V_53 -> V_63 -> V_74 . V_75 . V_124 [ 14 ] , & V_53 -> V_37 . V_59 -> V_141 , 16 ) ;
return V_31 ;
}
int F_102 ( struct V_52 * V_53 , struct V_146 * V_146 )
{
int V_31 ;
T_3 V_147 ;
V_148:
if ( V_53 -> V_149 )
F_103 ( V_150 , & V_53 -> V_151 , & V_147 ) ;
F_54 ( V_87 , & V_53 -> V_37 . V_59 -> V_78 ) ;
F_104 ( V_53 -> V_22 -> V_37 . V_45 . V_111 [ V_53 -> V_54 ] == NULL ) ;
switch ( V_146 -> V_152 ) {
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
break;
default:
F_72 () ;
}
V_53 -> V_37 . V_59 -> V_79 . V_80 = V_146 -> V_133 ;
V_53 -> V_37 . V_59 -> V_79 . V_81 = V_146 -> V_134 ;
if ( V_146 -> V_158 & V_65 ) {
V_146 -> V_158 &= ~ V_65 ;
F_57 ( V_53 , V_146 -> V_74 . V_75 . V_159 ) ;
}
if ( V_146 -> V_158 & V_68 ) {
V_146 -> V_158 &= ~ V_68 ;
memcpy ( & V_53 -> V_37 . V_59 -> V_85 , & V_146 -> V_74 . V_75 . V_127 , 128 ) ;
F_57 ( V_53 , V_146 -> V_74 . V_75 . V_159 ) ;
}
F_105 () ;
do {
V_31 = F_90 ( V_53 ) ;
if ( V_31 )
break;
if ( F_30 ( V_53 -> V_22 ) )
V_31 = - V_160 ;
else
V_31 = F_106 ( V_53 ) ;
} while ( ! F_107 ( V_41 ) && ! V_31 );
if ( V_31 == V_161 )
goto V_148;
if ( F_107 ( V_41 ) && ! V_31 ) {
V_146 -> V_152 = V_155 ;
V_31 = - V_162 ;
}
#ifdef F_11
if ( V_31 == V_144 ) {
V_146 -> V_152 = V_157 ;
V_146 -> V_163 . V_164 =
V_41 -> V_165 . V_166 ;
V_146 -> V_163 . V_167 = 0x10 ;
V_31 = 0 ;
}
#endif
if ( V_31 == - V_160 ) {
V_146 -> V_152 = V_153 ;
V_146 -> V_168 . V_143 = V_53 -> V_37 . V_59 -> V_143 ;
V_146 -> V_168 . V_169 = V_53 -> V_37 . V_59 -> V_169 ;
V_146 -> V_168 . V_170 = V_53 -> V_37 . V_59 -> V_170 ;
V_31 = 0 ;
}
if ( V_31 == - V_171 ) {
V_31 = 0 ;
}
V_146 -> V_133 = V_53 -> V_37 . V_59 -> V_79 . V_80 ;
V_146 -> V_134 = V_53 -> V_37 . V_59 -> V_79 . V_81 ;
V_146 -> V_74 . V_75 . V_159 = V_53 -> V_37 . V_59 -> V_159 ;
memcpy ( & V_146 -> V_74 . V_75 . V_127 , & V_53 -> V_37 . V_59 -> V_85 , 128 ) ;
if ( V_53 -> V_149 )
F_103 ( V_150 , & V_147 , NULL ) ;
V_53 -> V_172 . V_173 ++ ;
return V_31 ;
}
static int F_108 ( struct V_52 * V_53 , V_120 V_174 , void * V_175 ,
unsigned long V_176 , int V_159 )
{
if ( V_159 )
return F_109 ( V_53 , V_174 , V_175 , V_176 ) ;
else
return F_110 ( V_53 , V_174 , V_175 , V_176 ) ;
}
int F_111 ( struct V_52 * V_53 , unsigned long V_81 )
{
unsigned char V_177 = 1 ;
int V_159 ;
if ( V_81 == V_178 ) {
if ( F_110 ( V_53 , 163ul , & V_177 , 1 ) )
return - V_29 ;
V_81 = V_179 ;
V_159 = 0 ;
} else if ( V_81 == V_180 ) {
if ( F_109 ( V_53 , 163ul , & V_177 , 1 ) )
return - V_29 ;
V_81 = V_179 ;
V_159 = 1 ;
} else
V_159 = 0 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_182 ) ,
V_53 -> V_37 . V_71 . V_130 , 128 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_183 ) ,
V_53 -> V_63 -> V_74 . V_75 . V_124 , 128 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_131 ) ,
& V_53 -> V_37 . V_59 -> V_79 , 16 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_184 ) ,
& V_53 -> V_37 . V_59 -> V_159 , 4 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 ,
V_81 + F_112 ( struct V_181 , V_185 ) ,
& V_53 -> V_37 . V_71 . V_72 , 4 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_186 ) ,
& V_53 -> V_37 . V_59 -> V_84 , 4 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_187 ) ,
& V_53 -> V_37 . V_59 -> V_82 , 8 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_188 ) ,
& V_53 -> V_37 . V_59 -> V_83 , 8 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 , V_81 + F_112 ( struct V_181 , V_189 ) ,
& V_53 -> V_63 -> V_74 . V_75 . V_76 , 64 , V_159 ) )
return - V_29 ;
if ( F_108 ( V_53 ,
V_81 + F_112 ( struct V_181 , V_190 ) ,
& V_53 -> V_37 . V_59 -> V_85 , 128 , V_159 ) )
return - V_29 ;
return 0 ;
}
long F_113 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_52 * V_53 = V_5 -> V_24 ;
void T_1 * V_25 = ( void T_1 * ) V_7 ;
long V_11 ;
switch ( V_6 ) {
case V_26 : {
struct V_27 V_28 ;
V_11 = - V_29 ;
if ( F_15 ( & V_28 , V_25 , sizeof( V_28 ) ) )
break;
V_11 = F_114 ( V_53 , & V_28 ) ;
break;
}
case V_191 :
V_11 = F_111 ( V_53 , V_7 ) ;
break;
case V_192 : {
T_2 V_131 ;
V_11 = - V_29 ;
if ( F_15 ( & V_131 , V_25 , sizeof( V_131 ) ) )
break;
V_11 = F_85 ( V_53 , V_131 ) ;
break;
}
case V_193 :
V_11 = F_78 ( V_53 ) ;
break;
case V_194 :
case V_195 : {
struct V_114 V_115 ;
V_11 = - V_29 ;
if ( F_15 ( & V_115 , V_25 , sizeof( V_115 ) ) )
break;
if ( V_6 == V_194 )
V_11 = F_76 ( V_53 , & V_115 ) ;
else
V_11 = F_74 ( V_53 , & V_115 ) ;
break;
}
#ifdef F_11
case V_196 : {
struct V_197 V_198 ;
if ( F_15 ( & V_198 , V_25 , sizeof( V_198 ) ) ) {
V_11 = - V_29 ;
break;
}
if ( ! F_30 ( V_53 -> V_22 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_115 ( V_53 -> V_37 . V_49 , V_198 . V_199 ,
V_198 . V_200 , V_198 . V_201 ) ;
break;
}
case V_202 : {
struct V_197 V_198 ;
if ( F_15 ( & V_198 , V_25 , sizeof( V_198 ) ) ) {
V_11 = - V_29 ;
break;
}
if ( ! F_30 ( V_53 -> V_22 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_116 ( V_53 -> V_37 . V_49 , V_198 . V_200 ,
V_198 . V_201 ) ;
break;
}
#endif
case V_203 : {
V_11 = F_117 ( V_7 , V_53 -> V_37 . V_49 ) ;
if ( ! F_118 ( V_11 ) )
V_11 = 0 ;
break;
}
default:
V_11 = - V_30 ;
}
return V_11 ;
}
int F_119 ( struct V_52 * V_53 , struct V_204 * V_205 )
{
#ifdef F_11
if ( ( V_205 -> V_206 == V_207 )
&& ( F_30 ( V_53 -> V_22 ) ) ) {
V_205 -> V_208 = F_120 ( V_53 -> V_37 . V_59 ) ;
F_121 ( V_205 -> V_208 ) ;
return 0 ;
}
#endif
return V_209 ;
}
void F_122 ( struct V_210 * free ,
struct V_210 * V_211 )
{
}
int F_123 ( struct V_210 * V_212 , unsigned long V_213 )
{
return 0 ;
}
int F_124 ( struct V_22 * V_22 ,
struct V_210 * V_214 ,
struct V_210 V_215 ,
struct V_216 * V_217 ,
int V_218 )
{
if ( V_217 -> V_212 )
return - V_9 ;
if ( V_217 -> V_219 )
return - V_9 ;
if ( V_217 -> V_220 & 0xffffful )
return - V_9 ;
if ( V_217 -> V_221 & 0xffffful )
return - V_9 ;
if ( ! V_218 )
return - V_9 ;
return 0 ;
}
void F_125 ( struct V_22 * V_22 ,
struct V_216 * V_217 ,
struct V_210 V_215 ,
int V_218 )
{
int V_31 ;
V_31 = F_115 ( V_22 -> V_37 . V_49 , V_217 -> V_220 ,
V_217 -> V_219 , V_217 -> V_221 ) ;
if ( V_31 )
F_126 ( V_222 L_9 ) ;
return;
}
void F_127 ( struct V_22 * V_22 )
{
}
static int T_4 F_128 ( void )
{
int V_223 ;
V_223 = F_129 ( NULL , sizeof( struct V_52 ) , 0 , V_224 ) ;
if ( V_223 )
return V_223 ;
V_93 = ( unsigned long long * ) F_19 ( V_40 | V_225 ) ;
if ( ! V_93 ) {
F_130 () ;
return - V_36 ;
}
memcpy ( V_93 , V_226 . V_227 , 16 ) ;
V_93 [ 0 ] &= 0xff00fff3f47c0000ULL ;
V_93 [ 1 ] &= 0x201c000000000000ULL ;
return 0 ;
}
static void T_5 F_131 ( void )
{
F_27 ( ( unsigned long ) V_93 ) ;
F_130 () ;
}
