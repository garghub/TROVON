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
V_11 = 1 ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
int F_11 ( struct V_14 * V_14 ,
struct V_15 * log )
{
return 0 ;
}
long F_12 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_14 * V_14 = V_5 -> V_16 ;
void T_1 * V_17 = ( void T_1 * ) V_7 ;
int V_11 ;
switch ( V_6 ) {
case V_18 : {
struct V_19 V_20 ;
V_11 = - V_21 ;
if ( F_13 ( & V_20 , V_17 , sizeof( V_20 ) ) )
break;
V_11 = F_14 ( V_14 , & V_20 ) ;
break;
}
default:
V_11 = - V_22 ;
}
return V_11 ;
}
int F_15 ( struct V_14 * V_14 )
{
int V_23 ;
char V_24 [ 16 ] ;
V_23 = F_9 () ;
if ( V_23 )
goto V_25;
V_14 -> V_26 . V_27 = (struct V_28 * ) F_16 ( V_29 ) ;
if ( ! V_14 -> V_26 . V_27 )
goto V_25;
sprintf ( V_24 , L_1 , V_30 -> V_31 ) ;
V_14 -> V_26 . V_32 = F_17 ( V_24 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_14 -> V_26 . V_32 )
goto V_33;
F_18 ( & V_14 -> V_26 . V_34 . V_35 ) ;
F_19 ( & V_14 -> V_26 . V_34 . V_36 ) ;
F_20 ( V_14 -> V_26 . V_32 , & V_37 ) ;
F_21 ( V_14 , 3 , L_2 , L_3 ) ;
V_14 -> V_26 . V_38 = F_22 ( V_30 -> V_39 ) ;
if ( ! V_14 -> V_26 . V_38 )
goto V_40;
return 0 ;
V_40:
F_23 ( V_14 -> V_26 . V_32 ) ;
V_33:
F_24 ( ( unsigned long ) ( V_14 -> V_26 . V_27 ) ) ;
V_25:
return V_23 ;
}
void F_25 ( struct V_41 * V_42 )
{
F_26 ( V_42 , 3 , L_2 , L_4 ) ;
F_27 ( 63 - V_42 -> V_43 , ( unsigned long * ) & V_42 -> V_14 -> V_26 . V_27 -> V_44 ) ;
if ( V_42 -> V_14 -> V_26 . V_27 -> V_45 [ V_42 -> V_43 ] . V_46 ==
( V_47 ) V_42 -> V_26 . V_48 )
V_42 -> V_14 -> V_26 . V_27 -> V_45 [ V_42 -> V_43 ] . V_46 = 0 ;
F_28 () ;
F_24 ( ( unsigned long ) ( V_42 -> V_26 . V_48 ) ) ;
F_29 ( V_42 ) ;
F_30 ( V_42 ) ;
}
static void F_31 ( struct V_14 * V_14 )
{
unsigned int V_49 ;
struct V_41 * V_42 ;
F_32 (i, vcpu, kvm)
F_25 ( V_42 ) ;
F_33 ( & V_14 -> V_35 ) ;
for ( V_49 = 0 ; V_49 < F_34 ( & V_14 -> V_50 ) ; V_49 ++ )
V_14 -> V_51 [ V_49 ] = NULL ;
F_35 ( & V_14 -> V_50 , 0 ) ;
F_36 ( & V_14 -> V_35 ) ;
}
void F_37 ( struct V_14 * V_14 )
{
}
void F_38 ( struct V_14 * V_14 )
{
F_31 ( V_14 ) ;
F_24 ( ( unsigned long ) ( V_14 -> V_26 . V_27 ) ) ;
F_23 ( V_14 -> V_26 . V_32 ) ;
F_39 ( V_14 -> V_26 . V_38 ) ;
}
int F_40 ( struct V_41 * V_42 )
{
V_42 -> V_26 . V_38 = V_42 -> V_14 -> V_26 . V_38 ;
return 0 ;
}
void F_41 ( struct V_41 * V_42 )
{
}
void F_42 ( struct V_41 * V_42 , int V_45 )
{
F_43 ( & V_42 -> V_26 . V_52 ) ;
F_44 ( V_42 -> V_26 . V_53 ) ;
V_42 -> V_26 . V_54 . V_55 &= V_56 ;
F_45 ( & V_42 -> V_26 . V_54 ) ;
F_46 ( V_42 -> V_26 . V_57 ) ;
F_47 ( V_42 -> V_26 . V_38 ) ;
}
void F_48 ( struct V_41 * V_42 )
{
F_49 ( V_42 -> V_26 . V_38 ) ;
F_43 ( & V_42 -> V_26 . V_54 ) ;
F_44 ( V_42 -> V_26 . V_57 ) ;
F_45 ( & V_42 -> V_26 . V_52 ) ;
F_46 ( V_42 -> V_26 . V_53 ) ;
}
static void F_50 ( struct V_41 * V_42 )
{
V_42 -> V_26 . V_48 -> V_58 . V_59 = 0UL ;
V_42 -> V_26 . V_48 -> V_58 . V_60 = 0UL ;
V_42 -> V_26 . V_48 -> V_61 = 0UL ;
V_42 -> V_26 . V_48 -> V_62 = 0xffff ;
V_42 -> V_26 . V_48 -> V_63 = 0UL ;
V_42 -> V_26 . V_48 -> V_64 = 0UL ;
V_42 -> V_26 . V_48 -> V_65 = 0 ;
memset ( V_42 -> V_26 . V_48 -> V_66 , 0 , 16 * sizeof( V_47 ) ) ;
V_42 -> V_26 . V_48 -> V_66 [ 0 ] = 0xE0UL ;
V_42 -> V_26 . V_48 -> V_66 [ 14 ] = 0xC2000000UL ;
V_42 -> V_26 . V_54 . V_55 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_42 -> V_26 . V_48 -> V_67 = 1 ;
}
int F_51 ( struct V_41 * V_42 )
{
F_35 ( & V_42 -> V_26 . V_48 -> V_68 , V_69 | V_70 ) ;
V_42 -> V_26 . V_48 -> V_71 = 6 ;
V_42 -> V_26 . V_48 -> V_72 = 0xC1002001U ;
V_42 -> V_26 . V_48 -> V_73 = ( int ) ( long ) V_74 ;
F_52 ( & V_42 -> V_26 . V_75 , V_76 , V_77 ) ;
F_53 ( & V_42 -> V_26 . V_78 , V_79 ,
( unsigned long ) V_42 ) ;
V_42 -> V_26 . V_75 . V_80 = V_81 ;
F_54 ( & V_42 -> V_26 . V_82 ) ;
V_42 -> V_26 . V_82 . V_83 = 0xff ;
return 0 ;
}
struct V_41 * F_55 ( struct V_14 * V_14 ,
unsigned int V_84 )
{
struct V_41 * V_42 = F_56 ( sizeof( struct V_41 ) , V_29 ) ;
int V_23 = - V_85 ;
if ( ! V_42 )
goto V_86;
V_42 -> V_26 . V_48 = (struct V_87 * )
F_16 ( V_29 ) ;
if ( ! V_42 -> V_26 . V_48 )
goto V_88;
V_42 -> V_26 . V_48 -> V_89 = V_84 ;
F_57 ( ! V_14 -> V_26 . V_27 ) ;
if ( ! V_14 -> V_26 . V_27 -> V_45 [ V_84 ] . V_46 )
V_14 -> V_26 . V_27 -> V_45 [ V_84 ] . V_46 = ( V_47 ) V_42 -> V_26 . V_48 ;
V_42 -> V_26 . V_48 -> V_90 = ( V_91 ) ( ( ( V_47 ) V_14 -> V_26 . V_27 ) >> 32 ) ;
V_42 -> V_26 . V_48 -> V_92 = ( V_91 ) ( V_47 ) V_14 -> V_26 . V_27 ;
F_58 ( 63 - V_84 , ( unsigned long * ) & V_14 -> V_26 . V_27 -> V_44 ) ;
F_18 ( & V_42 -> V_26 . V_93 . V_35 ) ;
F_19 ( & V_42 -> V_26 . V_93 . V_36 ) ;
V_42 -> V_26 . V_93 . V_34 = & V_14 -> V_26 . V_34 ;
F_59 ( & V_14 -> V_26 . V_34 . V_35 ) ;
V_14 -> V_26 . V_34 . V_93 [ V_84 ] = & V_42 -> V_26 . V_93 ;
F_60 ( & V_42 -> V_26 . V_93 . V_94 ) ;
V_42 -> V_26 . V_93 . V_68 = & V_42 -> V_26 . V_48 -> V_68 ;
F_61 ( & V_14 -> V_26 . V_34 . V_35 ) ;
V_23 = F_62 ( V_42 , V_14 , V_84 ) ;
if ( V_23 )
goto V_95;
F_21 ( V_14 , 3 , L_5 , V_84 , V_42 ,
V_42 -> V_26 . V_48 ) ;
return V_42 ;
V_95:
F_24 ( ( unsigned long ) ( V_42 -> V_26 . V_48 ) ) ;
V_88:
F_30 ( V_42 ) ;
V_86:
return F_63 ( V_23 ) ;
}
int F_64 ( struct V_41 * V_42 )
{
F_65 () ;
return 0 ;
}
static int F_66 ( struct V_41 * V_42 )
{
F_50 ( V_42 ) ;
return 0 ;
}
int F_67 ( struct V_41 * V_42 , struct V_96 * V_97 )
{
memcpy ( & V_42 -> V_26 . V_98 , & V_97 -> V_99 , sizeof( V_97 -> V_99 ) ) ;
return 0 ;
}
int F_68 ( struct V_41 * V_42 , struct V_96 * V_97 )
{
memcpy ( & V_97 -> V_99 , & V_42 -> V_26 . V_98 , sizeof( V_97 -> V_99 ) ) ;
return 0 ;
}
int F_69 ( struct V_41 * V_42 ,
struct V_100 * V_101 )
{
memcpy ( & V_42 -> V_26 . V_57 , & V_101 -> V_102 , sizeof( V_101 -> V_102 ) ) ;
memcpy ( & V_42 -> V_26 . V_48 -> V_66 , & V_101 -> V_103 , sizeof( V_101 -> V_103 ) ) ;
return 0 ;
}
int F_70 ( struct V_41 * V_42 ,
struct V_100 * V_101 )
{
memcpy ( & V_101 -> V_102 , & V_42 -> V_26 . V_57 , sizeof( V_101 -> V_102 ) ) ;
memcpy ( & V_101 -> V_103 , & V_42 -> V_26 . V_48 -> V_66 , sizeof( V_101 -> V_103 ) ) ;
return 0 ;
}
int F_71 ( struct V_41 * V_42 , struct V_104 * V_105 )
{
memcpy ( & V_42 -> V_26 . V_54 . V_106 , & V_105 -> V_106 , sizeof( V_105 -> V_106 ) ) ;
V_42 -> V_26 . V_54 . V_55 = V_105 -> V_55 ;
return 0 ;
}
int F_72 ( struct V_41 * V_42 , struct V_104 * V_105 )
{
memcpy ( & V_105 -> V_106 , & V_42 -> V_26 . V_54 . V_106 , sizeof( V_105 -> V_106 ) ) ;
V_105 -> V_55 = V_42 -> V_26 . V_54 . V_55 ;
return 0 ;
}
static int F_73 ( struct V_41 * V_42 , T_2 V_107 )
{
int V_23 = 0 ;
if ( F_34 ( & V_42 -> V_26 . V_48 -> V_68 ) & V_108 )
V_23 = - V_109 ;
else {
V_42 -> V_110 -> V_111 = V_107 . V_59 ;
V_42 -> V_110 -> V_112 = V_107 . V_60 ;
}
return V_23 ;
}
int F_74 ( struct V_41 * V_42 ,
struct V_113 * V_114 )
{
return - V_9 ;
}
int F_75 ( struct V_41 * V_42 ,
struct V_115 * V_116 )
{
return - V_9 ;
}
int F_76 ( struct V_41 * V_42 ,
struct V_117 * V_118 )
{
return - V_9 ;
}
int F_77 ( struct V_41 * V_42 ,
struct V_117 * V_118 )
{
return - V_9 ;
}
static void F_78 ( struct V_41 * V_42 )
{
memcpy ( & V_42 -> V_26 . V_48 -> V_119 , & V_42 -> V_26 . V_98 [ 14 ] , 16 ) ;
if ( F_79 () )
F_80 () ;
if ( F_81 ( V_120 ) )
F_82 () ;
F_83 ( V_42 ) ;
V_42 -> V_26 . V_48 -> V_121 = 0 ;
F_84 () ;
F_85 () ;
F_86 () ;
F_26 ( V_42 , 6 , L_6 ,
F_34 ( & V_42 -> V_26 . V_48 -> V_68 ) ) ;
if ( F_87 ( V_42 -> V_26 . V_48 , V_42 -> V_26 . V_98 ) ) {
F_26 ( V_42 , 3 , L_2 , L_7 ) ;
F_88 ( V_42 , V_122 ) ;
}
F_26 ( V_42 , 6 , L_8 ,
V_42 -> V_26 . V_48 -> V_121 ) ;
F_84 () ;
F_89 () ;
F_86 () ;
memcpy ( & V_42 -> V_26 . V_98 [ 14 ] , & V_42 -> V_26 . V_48 -> V_119 , 16 ) ;
}
int F_90 ( struct V_41 * V_42 , struct V_123 * V_123 )
{
int V_23 ;
T_3 V_124 ;
V_125:
if ( V_42 -> V_126 )
F_91 ( V_127 , & V_42 -> V_128 , & V_124 ) ;
F_92 ( V_108 , & V_42 -> V_26 . V_48 -> V_68 ) ;
F_57 ( V_42 -> V_14 -> V_26 . V_34 . V_93 [ V_42 -> V_43 ] == NULL ) ;
switch ( V_123 -> V_129 ) {
case V_130 :
case V_131 :
case V_132 :
case V_133 :
break;
default:
F_65 () ;
}
V_42 -> V_26 . V_48 -> V_58 . V_59 = V_123 -> V_111 ;
V_42 -> V_26 . V_48 -> V_58 . V_60 = V_123 -> V_112 ;
F_93 () ;
do {
F_78 ( V_42 ) ;
V_23 = F_94 ( V_42 ) ;
} while ( ! F_95 ( V_30 ) && ! V_23 );
if ( V_23 == V_134 )
goto V_125;
if ( F_95 ( V_30 ) && ! V_23 ) {
V_123 -> V_129 = V_132 ;
V_23 = - V_135 ;
}
if ( V_23 == - V_136 ) {
V_123 -> V_129 = V_130 ;
V_123 -> V_137 . V_121 = V_42 -> V_26 . V_48 -> V_121 ;
V_123 -> V_137 . V_138 = V_42 -> V_26 . V_48 -> V_138 ;
V_123 -> V_137 . V_139 = V_42 -> V_26 . V_48 -> V_139 ;
V_23 = 0 ;
}
if ( V_23 == - V_140 ) {
V_23 = 0 ;
}
V_123 -> V_111 = V_42 -> V_26 . V_48 -> V_58 . V_59 ;
V_123 -> V_112 = V_42 -> V_26 . V_48 -> V_58 . V_60 ;
if ( V_42 -> V_126 )
F_91 ( V_127 , & V_124 , NULL ) ;
V_42 -> V_141 . V_142 ++ ;
return V_23 ;
}
static int F_96 ( struct V_41 * V_42 , T_4 V_143 , void * V_144 ,
unsigned long V_145 , int V_61 )
{
if ( V_61 )
return F_97 ( V_42 , V_143 , V_144 , V_145 ) ;
else
return F_98 ( V_42 , V_143 , V_144 , V_145 ) ;
}
int F_99 ( struct V_41 * V_42 , unsigned long V_60 )
{
unsigned char V_146 = 1 ;
int V_61 ;
if ( V_60 == V_147 ) {
if ( F_98 ( V_42 , 163ul , & V_146 , 1 ) )
return - V_21 ;
V_60 = V_148 ;
V_61 = 0 ;
} else if ( V_60 == V_149 ) {
if ( F_97 ( V_42 , 163ul , & V_146 , 1 ) )
return - V_21 ;
V_60 = V_148 ;
V_61 = 1 ;
} else
V_61 = 0 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_151 ) ,
V_42 -> V_26 . V_54 . V_106 , 128 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_152 ) ,
V_42 -> V_26 . V_98 , 128 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_107 ) ,
& V_42 -> V_26 . V_48 -> V_58 , 16 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_153 ) ,
& V_42 -> V_26 . V_48 -> V_61 , 4 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 ,
V_60 + F_100 ( struct V_150 , V_154 ) ,
& V_42 -> V_26 . V_54 . V_55 , 4 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_155 ) ,
& V_42 -> V_26 . V_48 -> V_65 , 4 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_156 ) ,
& V_42 -> V_26 . V_48 -> V_63 , 8 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_157 ) ,
& V_42 -> V_26 . V_48 -> V_64 , 8 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 , V_60 + F_100 ( struct V_150 , V_158 ) ,
& V_42 -> V_26 . V_57 , 64 , V_61 ) )
return - V_21 ;
if ( F_96 ( V_42 ,
V_60 + F_100 ( struct V_150 , V_159 ) ,
& V_42 -> V_26 . V_48 -> V_66 , 128 , V_61 ) )
return - V_21 ;
return 0 ;
}
long F_101 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_41 * V_42 = V_5 -> V_16 ;
void T_1 * V_17 = ( void T_1 * ) V_7 ;
long V_11 ;
switch ( V_6 ) {
case V_18 : {
struct V_19 V_20 ;
V_11 = - V_21 ;
if ( F_13 ( & V_20 , V_17 , sizeof( V_20 ) ) )
break;
V_11 = F_102 ( V_42 , & V_20 ) ;
break;
}
case V_160 :
V_11 = F_99 ( V_42 , V_7 ) ;
break;
case V_161 : {
T_2 V_107 ;
V_11 = - V_21 ;
if ( F_13 ( & V_107 , V_17 , sizeof( V_107 ) ) )
break;
V_11 = F_73 ( V_42 , V_107 ) ;
break;
}
case V_162 :
V_11 = F_66 ( V_42 ) ;
break;
default:
V_11 = - V_9 ;
}
return V_11 ;
}
int F_103 ( struct V_14 * V_14 ,
struct V_163 * V_164 ,
struct V_163 V_165 ,
struct V_166 * V_167 ,
int V_168 )
{
if ( V_167 -> V_169 )
return - V_9 ;
if ( V_167 -> V_170 )
return - V_9 ;
if ( V_167 -> V_171 & 0xffffful )
return - V_9 ;
if ( V_167 -> V_172 & 0xffffful )
return - V_9 ;
if ( ! V_168 )
return - V_9 ;
return 0 ;
}
void F_104 ( struct V_14 * V_14 ,
struct V_166 * V_167 ,
struct V_163 V_165 ,
int V_168 )
{
int V_23 ;
V_23 = F_105 ( V_14 -> V_26 . V_38 , V_167 -> V_171 ,
V_167 -> V_170 , V_167 -> V_172 ) ;
if ( V_23 )
F_106 ( V_173 L_9 ) ;
return;
}
void F_107 ( struct V_14 * V_14 )
{
}
static int T_5 F_108 ( void )
{
int V_174 ;
V_174 = F_109 ( NULL , sizeof( struct V_41 ) , 0 , V_175 ) ;
if ( V_174 )
return V_174 ;
V_74 = ( unsigned long long * ) F_16 ( V_29 | V_176 ) ;
if ( ! V_74 ) {
F_110 () ;
return - V_85 ;
}
memcpy ( V_74 , V_177 . V_178 , 16 ) ;
V_74 [ 0 ] &= 0xff00fff3f47c0000ULL ;
V_74 [ 1 ] &= 0x201c000000000000ULL ;
return 0 ;
}
static void T_6 F_111 ( void )
{
F_24 ( ( unsigned long ) V_74 ) ;
F_110 () ;
}
