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
V_11 = 1 ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
int F_11 ( struct V_15 * V_15 ,
struct V_16 * log )
{
return 0 ;
}
long F_12 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_15 * V_15 = V_5 -> V_17 ;
void T_1 * V_18 = ( void T_1 * ) V_7 ;
int V_11 ;
switch ( V_6 ) {
case V_19 : {
struct V_20 V_21 ;
V_11 = - V_22 ;
if ( F_13 ( & V_21 , V_18 , sizeof( V_21 ) ) )
break;
V_11 = F_14 ( V_15 , & V_21 ) ;
break;
}
default:
V_11 = - V_23 ;
}
return V_11 ;
}
int F_15 ( struct V_15 * V_15 )
{
int V_24 ;
char V_25 [ 16 ] ;
V_24 = F_9 () ;
if ( V_24 )
goto V_26;
V_24 = - V_27 ;
V_15 -> V_28 . V_29 = (struct V_30 * ) F_16 ( V_31 ) ;
if ( ! V_15 -> V_28 . V_29 )
goto V_26;
sprintf ( V_25 , L_1 , V_32 -> V_33 ) ;
V_15 -> V_28 . V_34 = F_17 ( V_25 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_15 -> V_28 . V_34 )
goto V_35;
F_18 ( & V_15 -> V_28 . V_36 . V_37 ) ;
F_19 ( & V_15 -> V_28 . V_36 . V_38 ) ;
F_20 ( V_15 -> V_28 . V_34 , & V_39 ) ;
F_21 ( V_15 , 3 , L_2 , L_3 ) ;
V_15 -> V_28 . V_40 = F_22 ( V_32 -> V_41 ) ;
if ( ! V_15 -> V_28 . V_40 )
goto V_42;
return 0 ;
V_42:
F_23 ( V_15 -> V_28 . V_34 ) ;
V_35:
F_24 ( ( unsigned long ) ( V_15 -> V_28 . V_29 ) ) ;
V_26:
return V_24 ;
}
void F_25 ( struct V_43 * V_44 )
{
F_26 ( V_44 , 3 , L_2 , L_4 ) ;
F_27 ( 63 - V_44 -> V_45 , ( unsigned long * ) & V_44 -> V_15 -> V_28 . V_29 -> V_46 ) ;
if ( V_44 -> V_15 -> V_28 . V_29 -> V_47 [ V_44 -> V_45 ] . V_48 ==
( V_49 ) V_44 -> V_28 . V_50 )
V_44 -> V_15 -> V_28 . V_29 -> V_47 [ V_44 -> V_45 ] . V_48 = 0 ;
F_28 () ;
F_24 ( ( unsigned long ) ( V_44 -> V_28 . V_50 ) ) ;
F_29 ( V_44 ) ;
F_30 ( V_44 ) ;
}
static void F_31 ( struct V_15 * V_15 )
{
unsigned int V_51 ;
struct V_43 * V_44 ;
F_32 (i, vcpu, kvm)
F_25 ( V_44 ) ;
F_33 ( & V_15 -> V_37 ) ;
for ( V_51 = 0 ; V_51 < F_34 ( & V_15 -> V_52 ) ; V_51 ++ )
V_15 -> V_53 [ V_51 ] = NULL ;
F_35 ( & V_15 -> V_52 , 0 ) ;
F_36 ( & V_15 -> V_37 ) ;
}
void F_37 ( struct V_15 * V_15 )
{
}
void F_38 ( struct V_15 * V_15 )
{
F_31 ( V_15 ) ;
F_24 ( ( unsigned long ) ( V_15 -> V_28 . V_29 ) ) ;
F_23 ( V_15 -> V_28 . V_34 ) ;
F_39 ( V_15 -> V_28 . V_40 ) ;
}
int F_40 ( struct V_43 * V_44 )
{
V_44 -> V_28 . V_40 = V_44 -> V_15 -> V_28 . V_40 ;
return 0 ;
}
void F_41 ( struct V_43 * V_44 )
{
}
void F_42 ( struct V_43 * V_44 , int V_47 )
{
F_43 ( & V_44 -> V_28 . V_54 ) ;
F_44 ( V_44 -> V_28 . V_55 ) ;
V_44 -> V_28 . V_56 . V_57 &= V_58 ;
F_45 ( & V_44 -> V_28 . V_56 ) ;
F_46 ( V_44 -> V_28 . V_59 ) ;
F_47 ( V_44 -> V_28 . V_40 ) ;
F_48 ( V_60 , & V_44 -> V_28 . V_50 -> V_61 ) ;
}
void F_49 ( struct V_43 * V_44 )
{
F_50 ( V_60 , & V_44 -> V_28 . V_50 -> V_61 ) ;
F_51 ( V_44 -> V_28 . V_40 ) ;
F_43 ( & V_44 -> V_28 . V_56 ) ;
F_44 ( V_44 -> V_28 . V_59 ) ;
F_45 ( & V_44 -> V_28 . V_54 ) ;
F_46 ( V_44 -> V_28 . V_55 ) ;
}
static void F_52 ( struct V_43 * V_44 )
{
V_44 -> V_28 . V_50 -> V_62 . V_63 = 0UL ;
V_44 -> V_28 . V_50 -> V_62 . V_64 = 0UL ;
V_44 -> V_28 . V_50 -> V_65 = 0UL ;
V_44 -> V_28 . V_50 -> V_66 = 0xffff ;
V_44 -> V_28 . V_50 -> V_67 = 0UL ;
V_44 -> V_28 . V_50 -> V_68 = 0UL ;
V_44 -> V_28 . V_50 -> V_69 = 0 ;
memset ( V_44 -> V_28 . V_50 -> V_70 , 0 , 16 * sizeof( V_49 ) ) ;
V_44 -> V_28 . V_50 -> V_70 [ 0 ] = 0xE0UL ;
V_44 -> V_28 . V_50 -> V_70 [ 14 ] = 0xC2000000UL ;
V_44 -> V_28 . V_56 . V_57 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_44 -> V_28 . V_50 -> V_71 = 1 ;
}
int F_53 ( struct V_43 * V_44 )
{
F_35 ( & V_44 -> V_28 . V_50 -> V_61 , V_72 |
V_73 |
V_74 ) ;
V_44 -> V_28 . V_50 -> V_75 = 6 ;
V_44 -> V_28 . V_50 -> V_76 = 0xC1002001U ;
V_44 -> V_28 . V_50 -> V_77 = ( int ) ( long ) V_78 ;
F_54 ( & V_44 -> V_28 . V_79 , V_80 , V_81 ) ;
F_55 ( & V_44 -> V_28 . V_82 , V_83 ,
( unsigned long ) V_44 ) ;
V_44 -> V_28 . V_79 . V_84 = V_85 ;
F_56 ( & V_44 -> V_28 . V_86 ) ;
V_44 -> V_28 . V_86 . V_87 = 0xff ;
return 0 ;
}
struct V_43 * F_57 ( struct V_15 * V_15 ,
unsigned int V_88 )
{
struct V_43 * V_44 ;
int V_24 = - V_9 ;
if ( V_88 >= V_89 )
goto V_90;
V_24 = - V_27 ;
V_44 = F_58 ( sizeof( struct V_43 ) , V_31 ) ;
if ( ! V_44 )
goto V_90;
V_44 -> V_28 . V_50 = (struct V_91 * )
F_16 ( V_31 ) ;
if ( ! V_44 -> V_28 . V_50 )
goto V_92;
V_44 -> V_28 . V_50 -> V_93 = V_88 ;
F_59 ( ! V_15 -> V_28 . V_29 ) ;
if ( ! V_15 -> V_28 . V_29 -> V_47 [ V_88 ] . V_48 )
V_15 -> V_28 . V_29 -> V_47 [ V_88 ] . V_48 = ( V_49 ) V_44 -> V_28 . V_50 ;
V_44 -> V_28 . V_50 -> V_94 = ( V_95 ) ( ( ( V_49 ) V_15 -> V_28 . V_29 ) >> 32 ) ;
V_44 -> V_28 . V_50 -> V_96 = ( V_95 ) ( V_49 ) V_15 -> V_28 . V_29 ;
F_60 ( 63 - V_88 , ( unsigned long * ) & V_15 -> V_28 . V_29 -> V_46 ) ;
F_18 ( & V_44 -> V_28 . V_97 . V_37 ) ;
F_19 ( & V_44 -> V_28 . V_97 . V_38 ) ;
V_44 -> V_28 . V_97 . V_36 = & V_15 -> V_28 . V_36 ;
F_61 ( & V_15 -> V_28 . V_36 . V_37 ) ;
V_15 -> V_28 . V_36 . V_97 [ V_88 ] = & V_44 -> V_28 . V_97 ;
F_62 ( & V_44 -> V_28 . V_97 . V_98 ) ;
V_44 -> V_28 . V_97 . V_61 = & V_44 -> V_28 . V_50 -> V_61 ;
F_63 ( & V_15 -> V_28 . V_36 . V_37 ) ;
V_24 = F_64 ( V_44 , V_15 , V_88 ) ;
if ( V_24 )
goto V_99;
F_21 ( V_15 , 3 , L_5 , V_88 , V_44 ,
V_44 -> V_28 . V_50 ) ;
return V_44 ;
V_99:
F_24 ( ( unsigned long ) ( V_44 -> V_28 . V_50 ) ) ;
V_92:
F_30 ( V_44 ) ;
V_90:
return F_65 ( V_24 ) ;
}
int F_66 ( struct V_43 * V_44 )
{
F_67 () ;
return 0 ;
}
static int F_68 ( struct V_43 * V_44 )
{
F_52 ( V_44 ) ;
return 0 ;
}
int F_69 ( struct V_43 * V_44 , struct V_100 * V_101 )
{
memcpy ( & V_44 -> V_28 . V_102 , & V_101 -> V_103 , sizeof( V_101 -> V_103 ) ) ;
return 0 ;
}
int F_70 ( struct V_43 * V_44 , struct V_100 * V_101 )
{
memcpy ( & V_101 -> V_103 , & V_44 -> V_28 . V_102 , sizeof( V_101 -> V_103 ) ) ;
return 0 ;
}
int F_71 ( struct V_43 * V_44 ,
struct V_104 * V_105 )
{
memcpy ( & V_44 -> V_28 . V_59 , & V_105 -> V_106 , sizeof( V_105 -> V_106 ) ) ;
memcpy ( & V_44 -> V_28 . V_50 -> V_70 , & V_105 -> V_107 , sizeof( V_105 -> V_107 ) ) ;
F_46 ( V_44 -> V_28 . V_59 ) ;
return 0 ;
}
int F_72 ( struct V_43 * V_44 ,
struct V_104 * V_105 )
{
memcpy ( & V_105 -> V_106 , & V_44 -> V_28 . V_59 , sizeof( V_105 -> V_106 ) ) ;
memcpy ( & V_105 -> V_107 , & V_44 -> V_28 . V_50 -> V_70 , sizeof( V_105 -> V_107 ) ) ;
return 0 ;
}
int F_73 ( struct V_43 * V_44 , struct V_108 * V_109 )
{
memcpy ( & V_44 -> V_28 . V_56 . V_110 , & V_109 -> V_110 , sizeof( V_109 -> V_110 ) ) ;
V_44 -> V_28 . V_56 . V_57 = V_109 -> V_57 ;
F_45 ( & V_44 -> V_28 . V_56 ) ;
return 0 ;
}
int F_74 ( struct V_43 * V_44 , struct V_108 * V_109 )
{
memcpy ( & V_109 -> V_110 , & V_44 -> V_28 . V_56 . V_110 , sizeof( V_109 -> V_110 ) ) ;
V_109 -> V_57 = V_44 -> V_28 . V_56 . V_57 ;
return 0 ;
}
static int F_75 ( struct V_43 * V_44 , T_2 V_111 )
{
int V_24 = 0 ;
if ( ! ( F_34 ( & V_44 -> V_28 . V_50 -> V_61 ) & V_74 ) )
V_24 = - V_112 ;
else {
V_44 -> V_113 -> V_114 = V_111 . V_63 ;
V_44 -> V_113 -> V_115 = V_111 . V_64 ;
}
return V_24 ;
}
int F_76 ( struct V_43 * V_44 ,
struct V_116 * V_117 )
{
return - V_9 ;
}
int F_77 ( struct V_43 * V_44 ,
struct V_118 * V_119 )
{
return - V_9 ;
}
int F_78 ( struct V_43 * V_44 ,
struct V_120 * V_121 )
{
return - V_9 ;
}
int F_79 ( struct V_43 * V_44 ,
struct V_120 * V_121 )
{
return - V_9 ;
}
static void F_80 ( struct V_43 * V_44 )
{
memcpy ( & V_44 -> V_28 . V_50 -> V_122 , & V_44 -> V_28 . V_102 [ 14 ] , 16 ) ;
if ( F_81 () )
F_82 () ;
if ( F_83 ( V_123 ) )
F_84 () ;
F_85 ( V_44 ) ;
V_44 -> V_28 . V_50 -> V_124 = 0 ;
F_86 () ;
F_87 () ;
F_88 () ;
F_26 ( V_44 , 6 , L_6 ,
F_34 ( & V_44 -> V_28 . V_50 -> V_61 ) ) ;
if ( F_89 ( V_44 -> V_28 . V_50 , V_44 -> V_28 . V_102 ) ) {
F_26 ( V_44 , 3 , L_2 , L_7 ) ;
F_90 ( V_44 , V_125 ) ;
}
F_26 ( V_44 , 6 , L_8 ,
V_44 -> V_28 . V_50 -> V_124 ) ;
F_86 () ;
F_91 () ;
F_88 () ;
memcpy ( & V_44 -> V_28 . V_102 [ 14 ] , & V_44 -> V_28 . V_50 -> V_122 , 16 ) ;
}
int F_92 ( struct V_43 * V_44 , struct V_126 * V_126 )
{
int V_24 ;
T_3 V_127 ;
V_128:
if ( V_44 -> V_129 )
F_93 ( V_130 , & V_44 -> V_131 , & V_127 ) ;
F_50 ( V_74 , & V_44 -> V_28 . V_50 -> V_61 ) ;
F_59 ( V_44 -> V_15 -> V_28 . V_36 . V_97 [ V_44 -> V_45 ] == NULL ) ;
switch ( V_126 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
break;
default:
F_67 () ;
}
V_44 -> V_28 . V_50 -> V_62 . V_63 = V_126 -> V_114 ;
V_44 -> V_28 . V_50 -> V_62 . V_64 = V_126 -> V_115 ;
F_94 () ;
do {
F_80 ( V_44 ) ;
V_24 = F_95 ( V_44 ) ;
} while ( ! F_96 ( V_32 ) && ! V_24 );
if ( V_24 == V_137 )
goto V_128;
if ( F_96 ( V_32 ) && ! V_24 ) {
V_126 -> V_132 = V_135 ;
V_24 = - V_138 ;
}
if ( V_24 == - V_139 ) {
V_126 -> V_132 = V_133 ;
V_126 -> V_140 . V_124 = V_44 -> V_28 . V_50 -> V_124 ;
V_126 -> V_140 . V_141 = V_44 -> V_28 . V_50 -> V_141 ;
V_126 -> V_140 . V_142 = V_44 -> V_28 . V_50 -> V_142 ;
V_24 = 0 ;
}
if ( V_24 == - V_143 ) {
V_24 = 0 ;
}
V_126 -> V_114 = V_44 -> V_28 . V_50 -> V_62 . V_63 ;
V_126 -> V_115 = V_44 -> V_28 . V_50 -> V_62 . V_64 ;
if ( V_44 -> V_129 )
F_93 ( V_130 , & V_127 , NULL ) ;
V_44 -> V_144 . V_145 ++ ;
return V_24 ;
}
static int F_97 ( struct V_43 * V_44 , T_4 V_146 , void * V_147 ,
unsigned long V_148 , int V_65 )
{
if ( V_65 )
return F_98 ( V_44 , V_146 , V_147 , V_148 ) ;
else
return F_99 ( V_44 , V_146 , V_147 , V_148 ) ;
}
int F_100 ( struct V_43 * V_44 , unsigned long V_64 )
{
unsigned char V_149 = 1 ;
int V_65 ;
if ( V_64 == V_150 ) {
if ( F_99 ( V_44 , 163ul , & V_149 , 1 ) )
return - V_22 ;
V_64 = V_151 ;
V_65 = 0 ;
} else if ( V_64 == V_152 ) {
if ( F_98 ( V_44 , 163ul , & V_149 , 1 ) )
return - V_22 ;
V_64 = V_151 ;
V_65 = 1 ;
} else
V_65 = 0 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_154 ) ,
V_44 -> V_28 . V_56 . V_110 , 128 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_155 ) ,
V_44 -> V_28 . V_102 , 128 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_111 ) ,
& V_44 -> V_28 . V_50 -> V_62 , 16 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_156 ) ,
& V_44 -> V_28 . V_50 -> V_65 , 4 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 ,
V_64 + F_101 ( struct V_153 , V_157 ) ,
& V_44 -> V_28 . V_56 . V_57 , 4 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_158 ) ,
& V_44 -> V_28 . V_50 -> V_69 , 4 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_159 ) ,
& V_44 -> V_28 . V_50 -> V_67 , 8 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_160 ) ,
& V_44 -> V_28 . V_50 -> V_68 , 8 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 , V_64 + F_101 ( struct V_153 , V_161 ) ,
& V_44 -> V_28 . V_59 , 64 , V_65 ) )
return - V_22 ;
if ( F_97 ( V_44 ,
V_64 + F_101 ( struct V_153 , V_162 ) ,
& V_44 -> V_28 . V_50 -> V_70 , 128 , V_65 ) )
return - V_22 ;
return 0 ;
}
long F_102 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_43 * V_44 = V_5 -> V_17 ;
void T_1 * V_18 = ( void T_1 * ) V_7 ;
long V_11 ;
switch ( V_6 ) {
case V_19 : {
struct V_20 V_21 ;
V_11 = - V_22 ;
if ( F_13 ( & V_21 , V_18 , sizeof( V_21 ) ) )
break;
V_11 = F_103 ( V_44 , & V_21 ) ;
break;
}
case V_163 :
V_11 = F_100 ( V_44 , V_7 ) ;
break;
case V_164 : {
T_2 V_111 ;
V_11 = - V_22 ;
if ( F_13 ( & V_111 , V_18 , sizeof( V_111 ) ) )
break;
V_11 = F_75 ( V_44 , V_111 ) ;
break;
}
case V_165 :
V_11 = F_68 ( V_44 ) ;
break;
default:
V_11 = - V_9 ;
}
return V_11 ;
}
int F_104 ( struct V_15 * V_15 ,
struct V_166 * V_167 ,
struct V_166 V_168 ,
struct V_169 * V_170 ,
int V_171 )
{
if ( V_170 -> V_172 )
return - V_9 ;
if ( V_170 -> V_173 )
return - V_9 ;
if ( V_170 -> V_174 & 0xffffful )
return - V_9 ;
if ( V_170 -> V_175 & 0xffffful )
return - V_9 ;
if ( ! V_171 )
return - V_9 ;
return 0 ;
}
void F_105 ( struct V_15 * V_15 ,
struct V_169 * V_170 ,
struct V_166 V_168 ,
int V_171 )
{
int V_24 ;
V_24 = F_106 ( V_15 -> V_28 . V_40 , V_170 -> V_174 ,
V_170 -> V_173 , V_170 -> V_175 ) ;
if ( V_24 )
F_107 ( V_176 L_9 ) ;
return;
}
void F_108 ( struct V_15 * V_15 )
{
}
static int T_5 F_109 ( void )
{
int V_177 ;
V_177 = F_110 ( NULL , sizeof( struct V_43 ) , 0 , V_178 ) ;
if ( V_177 )
return V_177 ;
V_78 = ( unsigned long long * ) F_16 ( V_31 | V_179 ) ;
if ( ! V_78 ) {
F_111 () ;
return - V_27 ;
}
memcpy ( V_78 , V_180 . V_181 , 16 ) ;
V_78 [ 0 ] &= 0xff00fff3f47c0000ULL ;
V_78 [ 1 ] &= 0x201c000000000000ULL ;
return 0 ;
}
static void T_6 F_112 ( void )
{
F_24 ( ( unsigned long ) V_78 ) ;
F_111 () ;
}
