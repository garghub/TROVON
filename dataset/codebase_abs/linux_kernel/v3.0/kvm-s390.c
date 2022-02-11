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
V_11 = 1 ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
int F_11 ( struct V_13 * V_13 ,
struct V_14 * log )
{
return 0 ;
}
long F_12 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_13 * V_13 = V_5 -> V_15 ;
void T_1 * V_16 = ( void T_1 * ) V_7 ;
int V_11 ;
switch ( V_6 ) {
case V_17 : {
struct V_18 V_19 ;
V_11 = - V_20 ;
if ( F_13 ( & V_19 , V_16 , sizeof( V_19 ) ) )
break;
V_11 = F_14 ( V_13 , & V_19 ) ;
break;
}
default:
V_11 = - V_21 ;
}
return V_11 ;
}
int F_15 ( struct V_13 * V_13 )
{
int V_22 ;
char V_23 [ 16 ] ;
V_22 = F_9 () ;
if ( V_22 )
goto V_24;
V_13 -> V_25 . V_26 = (struct V_27 * ) F_16 ( V_28 ) ;
if ( ! V_13 -> V_25 . V_26 )
goto V_24;
sprintf ( V_23 , L_1 , V_29 -> V_30 ) ;
V_13 -> V_25 . V_31 = F_17 ( V_23 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_13 -> V_25 . V_31 )
goto V_32;
F_18 ( & V_13 -> V_25 . V_33 . V_34 ) ;
F_19 ( & V_13 -> V_25 . V_33 . V_35 ) ;
F_20 ( V_13 -> V_25 . V_31 , & V_36 ) ;
F_21 ( V_13 , 3 , L_2 , L_3 ) ;
return 0 ;
V_32:
F_22 ( ( unsigned long ) ( V_13 -> V_25 . V_26 ) ) ;
V_24:
return V_22 ;
}
void F_23 ( struct V_37 * V_38 )
{
F_24 ( V_38 , 3 , L_2 , L_4 ) ;
F_25 ( 63 - V_38 -> V_39 , ( unsigned long * ) & V_38 -> V_13 -> V_25 . V_26 -> V_40 ) ;
if ( V_38 -> V_13 -> V_25 . V_26 -> V_41 [ V_38 -> V_39 ] . V_42 ==
( V_43 ) V_38 -> V_25 . V_44 )
V_38 -> V_13 -> V_25 . V_26 -> V_41 [ V_38 -> V_39 ] . V_42 = 0 ;
F_26 () ;
F_22 ( ( unsigned long ) ( V_38 -> V_25 . V_44 ) ) ;
F_27 ( V_38 ) ;
F_28 ( V_38 ) ;
}
static void F_29 ( struct V_13 * V_13 )
{
unsigned int V_45 ;
struct V_37 * V_38 ;
F_30 (i, vcpu, kvm)
F_23 ( V_38 ) ;
F_31 ( & V_13 -> V_34 ) ;
for ( V_45 = 0 ; V_45 < F_32 ( & V_13 -> V_46 ) ; V_45 ++ )
V_13 -> V_47 [ V_45 ] = NULL ;
F_33 ( & V_13 -> V_46 , 0 ) ;
F_34 ( & V_13 -> V_34 ) ;
}
void F_35 ( struct V_13 * V_13 )
{
}
void F_36 ( struct V_13 * V_13 )
{
F_29 ( V_13 ) ;
F_22 ( ( unsigned long ) ( V_13 -> V_25 . V_26 ) ) ;
F_37 ( V_13 -> V_25 . V_31 ) ;
}
int F_38 ( struct V_37 * V_38 )
{
return 0 ;
}
void F_39 ( struct V_37 * V_38 )
{
}
void F_40 ( struct V_37 * V_38 , int V_41 )
{
F_41 ( & V_38 -> V_25 . V_48 ) ;
F_42 ( V_38 -> V_25 . V_49 ) ;
V_38 -> V_25 . V_50 . V_51 &= V_52 ;
F_43 ( & V_38 -> V_25 . V_50 ) ;
F_44 ( V_38 -> V_25 . V_53 ) ;
}
void F_45 ( struct V_37 * V_38 )
{
F_41 ( & V_38 -> V_25 . V_50 ) ;
F_42 ( V_38 -> V_25 . V_53 ) ;
F_43 ( & V_38 -> V_25 . V_48 ) ;
F_44 ( V_38 -> V_25 . V_49 ) ;
}
static void F_46 ( struct V_37 * V_38 )
{
V_38 -> V_25 . V_44 -> V_54 . V_55 = 0UL ;
V_38 -> V_25 . V_44 -> V_54 . V_56 = 0UL ;
V_38 -> V_25 . V_44 -> V_57 = 0UL ;
V_38 -> V_25 . V_44 -> V_58 = 0xffff ;
V_38 -> V_25 . V_44 -> V_59 = 0UL ;
V_38 -> V_25 . V_44 -> V_60 = 0UL ;
V_38 -> V_25 . V_44 -> V_61 = 0 ;
memset ( V_38 -> V_25 . V_44 -> V_62 , 0 , 16 * sizeof( V_43 ) ) ;
V_38 -> V_25 . V_44 -> V_62 [ 0 ] = 0xE0UL ;
V_38 -> V_25 . V_44 -> V_62 [ 14 ] = 0xC2000000UL ;
V_38 -> V_25 . V_50 . V_51 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_38 -> V_25 . V_44 -> V_63 = 1 ;
}
int F_47 ( struct V_37 * V_38 )
{
F_33 ( & V_38 -> V_25 . V_44 -> V_64 , V_65 ) ;
F_48 ( V_66 , & V_38 -> V_67 ) ;
V_38 -> V_25 . V_44 -> V_68 = 6 ;
V_38 -> V_25 . V_44 -> V_69 = 0xC1002001U ;
V_38 -> V_25 . V_44 -> V_70 = ( int ) ( long ) V_71 ;
F_49 ( & V_38 -> V_25 . V_72 , V_73 , V_74 ) ;
F_50 ( & V_38 -> V_25 . V_75 , V_76 ,
( unsigned long ) V_38 ) ;
V_38 -> V_25 . V_72 . V_77 = V_78 ;
F_51 ( & V_38 -> V_25 . V_79 ) ;
V_38 -> V_25 . V_79 . V_80 = 0xff ;
return 0 ;
}
struct V_37 * F_52 ( struct V_13 * V_13 ,
unsigned int V_81 )
{
struct V_37 * V_38 = F_53 ( sizeof( struct V_37 ) , V_28 ) ;
int V_22 = - V_82 ;
if ( ! V_38 )
goto V_83;
V_38 -> V_25 . V_44 = (struct V_84 * )
F_16 ( V_28 ) ;
if ( ! V_38 -> V_25 . V_44 )
goto V_85;
V_38 -> V_25 . V_44 -> V_86 = V_81 ;
F_54 ( ! V_13 -> V_25 . V_26 ) ;
if ( ! V_13 -> V_25 . V_26 -> V_41 [ V_81 ] . V_42 )
V_13 -> V_25 . V_26 -> V_41 [ V_81 ] . V_42 = ( V_43 ) V_38 -> V_25 . V_44 ;
V_38 -> V_25 . V_44 -> V_87 = ( V_88 ) ( ( ( V_43 ) V_13 -> V_25 . V_26 ) >> 32 ) ;
V_38 -> V_25 . V_44 -> V_89 = ( V_88 ) ( V_43 ) V_13 -> V_25 . V_26 ;
F_48 ( 63 - V_81 , ( unsigned long * ) & V_13 -> V_25 . V_26 -> V_40 ) ;
F_18 ( & V_38 -> V_25 . V_90 . V_34 ) ;
F_19 ( & V_38 -> V_25 . V_90 . V_35 ) ;
V_38 -> V_25 . V_90 . V_33 = & V_13 -> V_25 . V_33 ;
F_55 ( & V_13 -> V_25 . V_33 . V_34 ) ;
V_13 -> V_25 . V_33 . V_90 [ V_81 ] = & V_38 -> V_25 . V_90 ;
F_56 ( & V_38 -> V_25 . V_90 . V_91 ) ;
V_38 -> V_25 . V_90 . V_64 = & V_38 -> V_25 . V_44 -> V_64 ;
F_57 ( & V_13 -> V_25 . V_33 . V_34 ) ;
V_22 = F_58 ( V_38 , V_13 , V_81 ) ;
if ( V_22 )
goto V_92;
F_21 ( V_13 , 3 , L_5 , V_81 , V_38 ,
V_38 -> V_25 . V_44 ) ;
return V_38 ;
V_92:
F_22 ( ( unsigned long ) ( V_38 -> V_25 . V_44 ) ) ;
V_85:
F_28 ( V_38 ) ;
V_83:
return F_59 ( V_22 ) ;
}
int F_60 ( struct V_37 * V_38 )
{
F_61 () ;
return 0 ;
}
static int F_62 ( struct V_37 * V_38 )
{
F_46 ( V_38 ) ;
return 0 ;
}
int F_63 ( struct V_37 * V_38 , struct V_93 * V_94 )
{
memcpy ( & V_38 -> V_25 . V_95 , & V_94 -> V_96 , sizeof( V_94 -> V_96 ) ) ;
return 0 ;
}
int F_64 ( struct V_37 * V_38 , struct V_93 * V_94 )
{
memcpy ( & V_94 -> V_96 , & V_38 -> V_25 . V_95 , sizeof( V_94 -> V_96 ) ) ;
return 0 ;
}
int F_65 ( struct V_37 * V_38 ,
struct V_97 * V_98 )
{
memcpy ( & V_38 -> V_25 . V_53 , & V_98 -> V_99 , sizeof( V_98 -> V_99 ) ) ;
memcpy ( & V_38 -> V_25 . V_44 -> V_62 , & V_98 -> V_100 , sizeof( V_98 -> V_100 ) ) ;
return 0 ;
}
int F_66 ( struct V_37 * V_38 ,
struct V_97 * V_98 )
{
memcpy ( & V_98 -> V_99 , & V_38 -> V_25 . V_53 , sizeof( V_98 -> V_99 ) ) ;
memcpy ( & V_98 -> V_100 , & V_38 -> V_25 . V_44 -> V_62 , sizeof( V_98 -> V_100 ) ) ;
return 0 ;
}
int F_67 ( struct V_37 * V_38 , struct V_101 * V_102 )
{
memcpy ( & V_38 -> V_25 . V_50 . V_103 , & V_102 -> V_103 , sizeof( V_102 -> V_103 ) ) ;
V_38 -> V_25 . V_50 . V_51 = V_102 -> V_51 ;
return 0 ;
}
int F_68 ( struct V_37 * V_38 , struct V_101 * V_102 )
{
memcpy ( & V_102 -> V_103 , & V_38 -> V_25 . V_50 . V_103 , sizeof( V_102 -> V_103 ) ) ;
V_102 -> V_51 = V_38 -> V_25 . V_50 . V_51 ;
return 0 ;
}
static int F_69 ( struct V_37 * V_38 , T_2 V_104 )
{
int V_22 = 0 ;
if ( F_32 ( & V_38 -> V_25 . V_44 -> V_64 ) & V_105 )
V_22 = - V_106 ;
else {
V_38 -> V_107 -> V_108 = V_104 . V_55 ;
V_38 -> V_107 -> V_109 = V_104 . V_56 ;
}
return V_22 ;
}
int F_70 ( struct V_37 * V_38 ,
struct V_110 * V_111 )
{
return - V_9 ;
}
int F_71 ( struct V_37 * V_38 ,
struct V_112 * V_113 )
{
return - V_9 ;
}
int F_72 ( struct V_37 * V_38 ,
struct V_114 * V_115 )
{
return - V_9 ;
}
int F_73 ( struct V_37 * V_38 ,
struct V_114 * V_115 )
{
return - V_9 ;
}
static void F_74 ( struct V_37 * V_38 )
{
memcpy ( & V_38 -> V_25 . V_44 -> V_116 , & V_38 -> V_25 . V_95 [ 14 ] , 16 ) ;
if ( F_75 () )
F_76 () ;
if ( F_77 ( V_117 ) )
F_78 () ;
F_79 ( V_38 ) ;
V_38 -> V_25 . V_44 -> V_118 = 0 ;
F_80 () ;
F_81 () ;
F_82 () ;
F_24 ( V_38 , 6 , L_6 ,
F_32 ( & V_38 -> V_25 . V_44 -> V_64 ) ) ;
if ( F_83 ( V_38 -> V_25 . V_44 , V_38 -> V_25 . V_95 ) ) {
F_24 ( V_38 , 3 , L_2 , L_7 ) ;
F_84 ( V_38 , V_119 ) ;
}
F_24 ( V_38 , 6 , L_8 ,
V_38 -> V_25 . V_44 -> V_118 ) ;
F_80 () ;
F_85 () ;
F_82 () ;
memcpy ( & V_38 -> V_25 . V_95 [ 14 ] , & V_38 -> V_25 . V_44 -> V_116 , 16 ) ;
}
int F_86 ( struct V_37 * V_38 , struct V_120 * V_120 )
{
int V_22 ;
T_3 V_121 ;
V_122:
if ( V_38 -> V_67 )
if ( F_87 ( V_66 , & V_38 -> V_67 ) )
F_88 ( V_38 ) ;
if ( ! V_38 -> V_25 . V_44 -> V_123 ) {
F_89 ( V_38 ) ;
F_24 ( V_38 , 3 , L_2 , L_9 ) ;
return - V_9 ;
}
if ( V_38 -> V_124 )
F_90 ( V_125 , & V_38 -> V_126 , & V_121 ) ;
F_91 ( V_105 , & V_38 -> V_25 . V_44 -> V_64 ) ;
F_54 ( V_38 -> V_13 -> V_25 . V_33 . V_90 [ V_38 -> V_39 ] == NULL ) ;
switch ( V_120 -> V_127 ) {
case V_128 :
case V_129 :
case V_130 :
case V_131 :
break;
default:
F_61 () ;
}
V_38 -> V_25 . V_44 -> V_54 . V_55 = V_120 -> V_108 ;
V_38 -> V_25 . V_44 -> V_54 . V_56 = V_120 -> V_109 ;
F_92 () ;
do {
F_74 ( V_38 ) ;
V_22 = F_93 ( V_38 ) ;
} while ( ! F_94 ( V_29 ) && ! V_22 );
if ( V_22 == V_132 )
goto V_122;
if ( F_94 ( V_29 ) && ! V_22 ) {
V_120 -> V_127 = V_130 ;
V_22 = - V_133 ;
}
if ( V_22 == - V_134 ) {
V_120 -> V_127 = V_128 ;
V_120 -> V_135 . V_118 = V_38 -> V_25 . V_44 -> V_118 ;
V_120 -> V_135 . V_136 = V_38 -> V_25 . V_44 -> V_136 ;
V_120 -> V_135 . V_137 = V_38 -> V_25 . V_44 -> V_137 ;
V_22 = 0 ;
}
if ( V_22 == - V_138 ) {
V_22 = 0 ;
}
V_120 -> V_108 = V_38 -> V_25 . V_44 -> V_54 . V_55 ;
V_120 -> V_109 = V_38 -> V_25 . V_44 -> V_54 . V_56 ;
if ( V_38 -> V_124 )
F_90 ( V_125 , & V_121 , NULL ) ;
V_38 -> V_139 . V_140 ++ ;
return V_22 ;
}
static int F_95 ( struct V_37 * V_38 , T_4 V_141 , const void * V_142 ,
unsigned long V_143 , int V_57 )
{
if ( V_57 )
return F_96 ( V_38 , V_141 , V_142 , V_143 ) ;
else
return F_97 ( V_38 , V_141 , V_142 , V_143 ) ;
}
int F_98 ( struct V_37 * V_38 , unsigned long V_56 )
{
const unsigned char V_144 = 1 ;
int V_57 ;
if ( V_56 == V_145 ) {
if ( F_97 ( V_38 , 163ul , & V_144 , 1 ) )
return - V_20 ;
V_56 = V_146 ;
V_57 = 0 ;
} else if ( V_56 == V_147 ) {
if ( F_96 ( V_38 , 163ul , & V_144 , 1 ) )
return - V_20 ;
V_56 = V_146 ;
V_57 = 1 ;
} else
V_57 = 0 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_149 ) ,
V_38 -> V_25 . V_50 . V_103 , 128 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_150 ) ,
V_38 -> V_25 . V_95 , 128 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_104 ) ,
& V_38 -> V_25 . V_44 -> V_54 , 16 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_151 ) ,
& V_38 -> V_25 . V_44 -> V_57 , 4 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 ,
V_56 + F_99 ( struct V_148 , V_152 ) ,
& V_38 -> V_25 . V_50 . V_51 , 4 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_153 ) ,
& V_38 -> V_25 . V_44 -> V_61 , 4 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_154 ) ,
& V_38 -> V_25 . V_44 -> V_59 , 8 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_155 ) ,
& V_38 -> V_25 . V_44 -> V_60 , 8 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 , V_56 + F_99 ( struct V_148 , V_156 ) ,
& V_38 -> V_25 . V_53 , 64 , V_57 ) )
return - V_20 ;
if ( F_95 ( V_38 ,
V_56 + F_99 ( struct V_148 , V_157 ) ,
& V_38 -> V_25 . V_44 -> V_62 , 128 , V_57 ) )
return - V_20 ;
return 0 ;
}
long F_100 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_37 * V_38 = V_5 -> V_15 ;
void T_1 * V_16 = ( void T_1 * ) V_7 ;
long V_11 ;
switch ( V_6 ) {
case V_17 : {
struct V_18 V_19 ;
V_11 = - V_20 ;
if ( F_13 ( & V_19 , V_16 , sizeof( V_19 ) ) )
break;
V_11 = F_101 ( V_38 , & V_19 ) ;
break;
}
case V_158 :
V_11 = F_98 ( V_38 , V_7 ) ;
break;
case V_159 : {
T_2 V_104 ;
V_11 = - V_20 ;
if ( F_13 ( & V_104 , V_16 , sizeof( V_104 ) ) )
break;
V_11 = F_69 ( V_38 , V_104 ) ;
break;
}
case V_160 :
V_11 = F_62 ( V_38 ) ;
break;
default:
V_11 = - V_9 ;
}
return V_11 ;
}
int F_102 ( struct V_13 * V_13 ,
struct V_161 * V_162 ,
struct V_161 V_163 ,
struct V_164 * V_165 ,
int V_166 )
{
if ( V_165 -> V_167 )
return - V_9 ;
if ( V_165 -> V_168 )
return - V_9 ;
if ( V_165 -> V_169 & ( V_170 - 1 ) )
return - V_9 ;
if ( V_165 -> V_171 & ( V_170 - 1 ) )
return - V_9 ;
if ( ! V_166 )
return - V_9 ;
return 0 ;
}
void F_103 ( struct V_13 * V_13 ,
struct V_164 * V_165 ,
struct V_161 V_163 ,
int V_166 )
{
int V_45 ;
struct V_37 * V_38 ;
F_30 (i, vcpu, kvm) {
if ( F_104 ( V_66 , & V_38 -> V_67 ) )
continue;
F_105 ( V_38 , V_172 ) ;
}
}
void F_106 ( struct V_13 * V_13 )
{
}
static int T_5 F_107 ( void )
{
int V_173 ;
V_173 = F_108 ( NULL , sizeof( struct V_37 ) , 0 , V_174 ) ;
if ( V_173 )
return V_173 ;
V_71 = ( unsigned long long * ) F_16 ( V_28 | V_175 ) ;
if ( ! V_71 ) {
F_109 () ;
return - V_82 ;
}
memcpy ( V_71 , V_176 . V_177 , 16 ) ;
V_71 [ 0 ] &= 0xff00fff3f47c0000ULL ;
V_71 [ 1 ] &= 0x201c000000000000ULL ;
return 0 ;
}
static void T_6 F_110 ( void )
{
F_22 ( ( unsigned long ) V_71 ) ;
F_109 () ;
}
