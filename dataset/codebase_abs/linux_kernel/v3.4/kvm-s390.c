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
V_11 = 1 ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
int F_12 ( struct V_17 * V_17 ,
struct V_18 * log )
{
return 0 ;
}
long F_13 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_17 * V_17 = V_5 -> V_19 ;
void T_1 * V_20 = ( void T_1 * ) V_7 ;
int V_11 ;
switch ( V_6 ) {
case V_21 : {
struct V_22 V_23 ;
V_11 = - V_24 ;
if ( F_14 ( & V_23 , V_20 , sizeof( V_23 ) ) )
break;
V_11 = F_15 ( V_17 , & V_23 ) ;
break;
}
default:
V_11 = - V_25 ;
}
return V_11 ;
}
int F_16 ( struct V_17 * V_17 , unsigned long type )
{
int V_26 ;
char V_27 [ 16 ] ;
V_26 = - V_9 ;
#ifdef F_11
if ( type & ~ V_28 )
goto V_29;
if ( ( type & V_28 ) && ( ! F_17 ( V_30 ) ) )
goto V_29;
#else
if ( type )
goto V_29;
#endif
V_26 = F_9 () ;
if ( V_26 )
goto V_29;
V_26 = - V_31 ;
V_17 -> V_32 . V_33 = (struct V_34 * ) F_18 ( V_35 ) ;
if ( ! V_17 -> V_32 . V_33 )
goto V_29;
sprintf ( V_27 , L_1 , V_36 -> V_37 ) ;
V_17 -> V_32 . V_38 = F_19 ( V_27 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_17 -> V_32 . V_38 )
goto V_39;
F_20 ( & V_17 -> V_32 . V_40 . V_41 ) ;
F_21 ( & V_17 -> V_32 . V_40 . V_42 ) ;
F_22 ( V_17 -> V_32 . V_38 , & V_43 ) ;
F_23 ( V_17 , 3 , L_2 , L_3 ) ;
if ( type & V_28 ) {
V_17 -> V_32 . V_44 = NULL ;
} else {
V_17 -> V_32 . V_44 = F_24 ( V_36 -> V_45 ) ;
if ( ! V_17 -> V_32 . V_44 )
goto V_46;
}
return 0 ;
V_46:
F_25 ( V_17 -> V_32 . V_38 ) ;
V_39:
F_26 ( ( unsigned long ) ( V_17 -> V_32 . V_33 ) ) ;
V_29:
return V_26 ;
}
void F_27 ( struct V_47 * V_48 )
{
F_28 ( V_48 , 3 , L_2 , L_4 ) ;
if ( ! F_29 ( V_48 -> V_17 ) ) {
F_30 ( 63 - V_48 -> V_49 ,
( unsigned long * ) & V_48 -> V_17 -> V_32 . V_33 -> V_50 ) ;
if ( V_48 -> V_17 -> V_32 . V_33 -> V_51 [ V_48 -> V_49 ] . V_52 ==
( V_53 ) V_48 -> V_32 . V_54 )
V_48 -> V_17 -> V_32 . V_33 -> V_51 [ V_48 -> V_49 ] . V_52 = 0 ;
}
F_31 () ;
if ( F_29 ( V_48 -> V_17 ) )
F_32 ( V_48 -> V_32 . V_44 ) ;
F_26 ( ( unsigned long ) ( V_48 -> V_32 . V_54 ) ) ;
F_33 ( V_48 ) ;
F_34 ( V_48 ) ;
}
static void F_35 ( struct V_17 * V_17 )
{
unsigned int V_55 ;
struct V_47 * V_48 ;
F_36 (i, vcpu, kvm)
F_27 ( V_48 ) ;
F_37 ( & V_17 -> V_41 ) ;
for ( V_55 = 0 ; V_55 < F_38 ( & V_17 -> V_56 ) ; V_55 ++ )
V_17 -> V_57 [ V_55 ] = NULL ;
F_39 ( & V_17 -> V_56 , 0 ) ;
F_40 ( & V_17 -> V_41 ) ;
}
void F_41 ( struct V_17 * V_17 )
{
}
void F_42 ( struct V_17 * V_17 )
{
F_35 ( V_17 ) ;
F_26 ( ( unsigned long ) ( V_17 -> V_32 . V_33 ) ) ;
F_25 ( V_17 -> V_32 . V_38 ) ;
if ( ! F_29 ( V_17 ) )
F_32 ( V_17 -> V_32 . V_44 ) ;
}
int F_43 ( struct V_47 * V_48 )
{
if ( F_29 ( V_48 -> V_17 ) ) {
V_48 -> V_32 . V_44 = F_24 ( V_36 -> V_45 ) ;
if ( ! V_48 -> V_32 . V_44 )
return - V_31 ;
return 0 ;
}
V_48 -> V_32 . V_44 = V_48 -> V_17 -> V_32 . V_44 ;
V_48 -> V_58 -> V_59 = V_60 |
V_61 |
V_62 |
V_63 ;
return 0 ;
}
void F_44 ( struct V_47 * V_48 )
{
}
void F_45 ( struct V_47 * V_48 , int V_51 )
{
F_46 ( & V_48 -> V_32 . V_64 ) ;
F_47 ( V_48 -> V_32 . V_65 ) ;
V_48 -> V_32 . V_66 . V_67 &= V_68 ;
F_48 ( & V_48 -> V_32 . V_66 ) ;
F_49 ( V_48 -> V_58 -> V_69 . V_70 . V_71 ) ;
F_50 ( V_48 -> V_32 . V_44 ) ;
F_51 ( V_72 , & V_48 -> V_32 . V_54 -> V_73 ) ;
}
void F_52 ( struct V_47 * V_48 )
{
F_53 ( V_72 , & V_48 -> V_32 . V_54 -> V_73 ) ;
F_54 ( V_48 -> V_32 . V_44 ) ;
F_46 ( & V_48 -> V_32 . V_66 ) ;
F_47 ( V_48 -> V_58 -> V_69 . V_70 . V_71 ) ;
F_48 ( & V_48 -> V_32 . V_64 ) ;
F_49 ( V_48 -> V_32 . V_65 ) ;
}
static void F_55 ( struct V_47 * V_48 )
{
V_48 -> V_32 . V_54 -> V_74 . V_75 = 0UL ;
V_48 -> V_32 . V_54 -> V_74 . V_76 = 0UL ;
F_56 ( V_48 , 0 ) ;
V_48 -> V_32 . V_54 -> V_77 = 0UL ;
V_48 -> V_32 . V_54 -> V_78 = 0UL ;
V_48 -> V_32 . V_54 -> V_79 = 0 ;
memset ( V_48 -> V_32 . V_54 -> V_80 , 0 , 16 * sizeof( V_53 ) ) ;
V_48 -> V_32 . V_54 -> V_80 [ 0 ] = 0xE0UL ;
V_48 -> V_32 . V_54 -> V_80 [ 14 ] = 0xC2000000UL ;
V_48 -> V_32 . V_66 . V_67 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_48 -> V_32 . V_54 -> V_81 = 1 ;
}
int F_57 ( struct V_47 * V_48 )
{
F_39 ( & V_48 -> V_32 . V_54 -> V_73 , V_82 |
V_83 |
V_84 ) ;
V_48 -> V_32 . V_54 -> V_85 = 6 ;
V_48 -> V_32 . V_54 -> V_86 = 0xC1002001U ;
V_48 -> V_32 . V_54 -> V_87 = ( int ) ( long ) V_88 ;
F_58 ( & V_48 -> V_32 . V_89 , V_90 , V_91 ) ;
F_59 ( & V_48 -> V_32 . V_92 , V_93 ,
( unsigned long ) V_48 ) ;
V_48 -> V_32 . V_89 . V_94 = V_95 ;
F_60 ( & V_48 -> V_32 . V_96 ) ;
V_48 -> V_32 . V_96 . V_97 = 0xff ;
return 0 ;
}
struct V_47 * F_61 ( struct V_17 * V_17 ,
unsigned int V_98 )
{
struct V_47 * V_48 ;
int V_26 = - V_9 ;
if ( V_98 >= V_99 )
goto V_100;
V_26 = - V_31 ;
V_48 = F_62 ( sizeof( struct V_47 ) , V_35 ) ;
if ( ! V_48 )
goto V_100;
V_48 -> V_32 . V_54 = (struct V_101 * )
F_18 ( V_35 ) ;
if ( ! V_48 -> V_32 . V_54 )
goto V_102;
V_48 -> V_32 . V_54 -> V_103 = V_98 ;
if ( ! F_29 ( V_17 ) ) {
if ( ! V_17 -> V_32 . V_33 ) {
F_63 ( 1 ) ;
goto V_102;
}
if ( ! V_17 -> V_32 . V_33 -> V_51 [ V_98 ] . V_52 )
V_17 -> V_32 . V_33 -> V_51 [ V_98 ] . V_52 =
( V_53 ) V_48 -> V_32 . V_54 ;
V_48 -> V_32 . V_54 -> V_104 =
( V_105 ) ( ( ( V_53 ) V_17 -> V_32 . V_33 ) >> 32 ) ;
V_48 -> V_32 . V_54 -> V_106 = ( V_105 ) ( V_53 ) V_17 -> V_32 . V_33 ;
F_64 ( 63 - V_98 , ( unsigned long * ) & V_17 -> V_32 . V_33 -> V_50 ) ;
}
F_20 ( & V_48 -> V_32 . V_107 . V_41 ) ;
F_21 ( & V_48 -> V_32 . V_107 . V_42 ) ;
V_48 -> V_32 . V_107 . V_40 = & V_17 -> V_32 . V_40 ;
F_65 ( & V_17 -> V_32 . V_40 . V_41 ) ;
V_17 -> V_32 . V_40 . V_107 [ V_98 ] = & V_48 -> V_32 . V_107 ;
F_66 ( & V_48 -> V_32 . V_107 . V_108 ) ;
V_48 -> V_32 . V_107 . V_73 = & V_48 -> V_32 . V_54 -> V_73 ;
F_67 ( & V_17 -> V_32 . V_40 . V_41 ) ;
V_26 = F_68 ( V_48 , V_17 , V_98 ) ;
if ( V_26 )
goto V_109;
F_23 ( V_17 , 3 , L_5 , V_98 , V_48 ,
V_48 -> V_32 . V_54 ) ;
return V_48 ;
V_109:
F_26 ( ( unsigned long ) ( V_48 -> V_32 . V_54 ) ) ;
V_102:
F_34 ( V_48 ) ;
V_100:
return F_69 ( V_26 ) ;
}
int F_70 ( struct V_47 * V_48 )
{
F_71 () ;
return 0 ;
}
static int F_72 ( struct V_47 * V_48 )
{
F_55 ( V_48 ) ;
return 0 ;
}
int F_73 ( struct V_47 * V_48 , struct V_110 * V_70 )
{
memcpy ( & V_48 -> V_58 -> V_69 . V_70 . V_111 , & V_70 -> V_111 , sizeof( V_70 -> V_111 ) ) ;
return 0 ;
}
int F_74 ( struct V_47 * V_48 , struct V_110 * V_70 )
{
memcpy ( & V_70 -> V_111 , & V_48 -> V_58 -> V_69 . V_70 . V_111 , sizeof( V_70 -> V_111 ) ) ;
return 0 ;
}
int F_75 ( struct V_47 * V_48 ,
struct V_112 * V_113 )
{
memcpy ( & V_48 -> V_58 -> V_69 . V_70 . V_71 , & V_113 -> V_71 , sizeof( V_113 -> V_71 ) ) ;
memcpy ( & V_48 -> V_32 . V_54 -> V_80 , & V_113 -> V_114 , sizeof( V_113 -> V_114 ) ) ;
F_49 ( V_48 -> V_58 -> V_69 . V_70 . V_71 ) ;
return 0 ;
}
int F_76 ( struct V_47 * V_48 ,
struct V_112 * V_113 )
{
memcpy ( & V_113 -> V_71 , & V_48 -> V_58 -> V_69 . V_70 . V_71 , sizeof( V_113 -> V_71 ) ) ;
memcpy ( & V_113 -> V_114 , & V_48 -> V_32 . V_54 -> V_80 , sizeof( V_113 -> V_114 ) ) ;
return 0 ;
}
int F_77 ( struct V_47 * V_48 , struct V_115 * V_116 )
{
memcpy ( & V_48 -> V_32 . V_66 . V_117 , & V_116 -> V_117 , sizeof( V_116 -> V_117 ) ) ;
V_48 -> V_32 . V_66 . V_67 = V_116 -> V_67 & V_68 ;
F_48 ( & V_48 -> V_32 . V_66 ) ;
return 0 ;
}
int F_78 ( struct V_47 * V_48 , struct V_115 * V_116 )
{
memcpy ( & V_116 -> V_117 , & V_48 -> V_32 . V_66 . V_117 , sizeof( V_116 -> V_117 ) ) ;
V_116 -> V_67 = V_48 -> V_32 . V_66 . V_67 ;
return 0 ;
}
static int F_79 ( struct V_47 * V_48 , T_2 V_118 )
{
int V_26 = 0 ;
if ( ! ( F_38 ( & V_48 -> V_32 . V_54 -> V_73 ) & V_84 ) )
V_26 = - V_119 ;
else {
V_48 -> V_58 -> V_120 = V_118 . V_75 ;
V_48 -> V_58 -> V_121 = V_118 . V_76 ;
}
return V_26 ;
}
int F_80 ( struct V_47 * V_48 ,
struct V_122 * V_123 )
{
return - V_9 ;
}
int F_81 ( struct V_47 * V_48 ,
struct V_124 * V_125 )
{
return - V_9 ;
}
int F_82 ( struct V_47 * V_48 ,
struct V_126 * V_127 )
{
return - V_9 ;
}
int F_83 ( struct V_47 * V_48 ,
struct V_126 * V_127 )
{
return - V_9 ;
}
static int F_84 ( struct V_47 * V_48 )
{
int V_26 ;
memcpy ( & V_48 -> V_32 . V_54 -> V_128 , & V_48 -> V_58 -> V_69 . V_70 . V_111 [ 14 ] , 16 ) ;
if ( F_85 () )
F_86 () ;
if ( F_87 ( V_129 ) )
F_88 () ;
if ( ! F_29 ( V_48 -> V_17 ) )
F_89 ( V_48 ) ;
V_48 -> V_32 . V_54 -> V_130 = 0 ;
F_90 () ;
F_91 () ;
F_92 () ;
F_28 ( V_48 , 6 , L_6 ,
F_38 ( & V_48 -> V_32 . V_54 -> V_73 ) ) ;
V_26 = F_93 ( V_48 -> V_32 . V_54 , V_48 -> V_58 -> V_69 . V_70 . V_111 ) ;
if ( V_26 ) {
if ( F_29 ( V_48 -> V_17 ) ) {
V_26 = V_131 ;
} else {
F_28 ( V_48 , 3 , L_2 , L_7 ) ;
F_94 ( V_48 , V_132 ) ;
V_26 = 0 ;
}
}
F_28 ( V_48 , 6 , L_8 ,
V_48 -> V_32 . V_54 -> V_130 ) ;
F_90 () ;
F_95 () ;
F_92 () ;
memcpy ( & V_48 -> V_58 -> V_69 . V_70 . V_111 [ 14 ] , & V_48 -> V_32 . V_54 -> V_128 , 16 ) ;
return V_26 ;
}
int F_96 ( struct V_47 * V_48 , struct V_133 * V_133 )
{
int V_26 ;
T_3 V_134 ;
V_135:
if ( V_48 -> V_136 )
F_97 ( V_137 , & V_48 -> V_138 , & V_134 ) ;
F_53 ( V_84 , & V_48 -> V_32 . V_54 -> V_73 ) ;
F_98 ( V_48 -> V_17 -> V_32 . V_40 . V_107 [ V_48 -> V_49 ] == NULL ) ;
switch ( V_133 -> V_139 ) {
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
break;
default:
F_71 () ;
}
V_48 -> V_32 . V_54 -> V_74 . V_75 = V_133 -> V_120 ;
V_48 -> V_32 . V_54 -> V_74 . V_76 = V_133 -> V_121 ;
if ( V_133 -> V_145 & V_60 ) {
V_133 -> V_145 &= ~ V_60 ;
F_56 ( V_48 , V_133 -> V_69 . V_70 . V_146 ) ;
}
if ( V_133 -> V_145 & V_63 ) {
V_133 -> V_145 &= ~ V_63 ;
memcpy ( & V_48 -> V_32 . V_54 -> V_80 , & V_133 -> V_69 . V_70 . V_114 , 128 ) ;
F_56 ( V_48 , V_133 -> V_69 . V_70 . V_146 ) ;
}
F_99 () ;
do {
V_26 = F_84 ( V_48 ) ;
if ( V_26 )
break;
if ( F_29 ( V_48 -> V_17 ) )
V_26 = - V_147 ;
else
V_26 = F_100 ( V_48 ) ;
} while ( ! F_101 ( V_36 ) && ! V_26 );
if ( V_26 == V_148 )
goto V_135;
if ( F_101 ( V_36 ) && ! V_26 ) {
V_133 -> V_139 = V_142 ;
V_26 = - V_149 ;
}
#ifdef F_11
if ( V_26 == V_131 ) {
V_133 -> V_139 = V_144 ;
V_133 -> V_150 . V_151 =
V_36 -> V_152 . V_153 ;
V_133 -> V_150 . V_154 = 0x10 ;
V_26 = 0 ;
}
#endif
if ( V_26 == - V_147 ) {
V_133 -> V_139 = V_140 ;
V_133 -> V_155 . V_130 = V_48 -> V_32 . V_54 -> V_130 ;
V_133 -> V_155 . V_156 = V_48 -> V_32 . V_54 -> V_156 ;
V_133 -> V_155 . V_157 = V_48 -> V_32 . V_54 -> V_157 ;
V_26 = 0 ;
}
if ( V_26 == - V_158 ) {
V_26 = 0 ;
}
V_133 -> V_120 = V_48 -> V_32 . V_54 -> V_74 . V_75 ;
V_133 -> V_121 = V_48 -> V_32 . V_54 -> V_74 . V_76 ;
V_133 -> V_69 . V_70 . V_146 = V_48 -> V_32 . V_54 -> V_146 ;
memcpy ( & V_133 -> V_69 . V_70 . V_114 , & V_48 -> V_32 . V_54 -> V_80 , 128 ) ;
if ( V_48 -> V_136 )
F_97 ( V_137 , & V_134 , NULL ) ;
V_48 -> V_159 . V_160 ++ ;
return V_26 ;
}
static int F_102 ( struct V_47 * V_48 , T_4 V_161 , void * V_162 ,
unsigned long V_163 , int V_146 )
{
if ( V_146 )
return F_103 ( V_48 , V_161 , V_162 , V_163 ) ;
else
return F_104 ( V_48 , V_161 , V_162 , V_163 ) ;
}
int F_105 ( struct V_47 * V_48 , unsigned long V_76 )
{
unsigned char V_164 = 1 ;
int V_146 ;
if ( V_76 == V_165 ) {
if ( F_104 ( V_48 , 163ul , & V_164 , 1 ) )
return - V_24 ;
V_76 = V_166 ;
V_146 = 0 ;
} else if ( V_76 == V_167 ) {
if ( F_103 ( V_48 , 163ul , & V_164 , 1 ) )
return - V_24 ;
V_76 = V_166 ;
V_146 = 1 ;
} else
V_146 = 0 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_169 ) ,
V_48 -> V_32 . V_66 . V_117 , 128 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_170 ) ,
V_48 -> V_58 -> V_69 . V_70 . V_111 , 128 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_118 ) ,
& V_48 -> V_32 . V_54 -> V_74 , 16 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_171 ) ,
& V_48 -> V_32 . V_54 -> V_146 , 4 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 ,
V_76 + F_106 ( struct V_168 , V_172 ) ,
& V_48 -> V_32 . V_66 . V_67 , 4 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_173 ) ,
& V_48 -> V_32 . V_54 -> V_79 , 4 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_174 ) ,
& V_48 -> V_32 . V_54 -> V_77 , 8 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_175 ) ,
& V_48 -> V_32 . V_54 -> V_78 , 8 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 , V_76 + F_106 ( struct V_168 , V_176 ) ,
& V_48 -> V_58 -> V_69 . V_70 . V_71 , 64 , V_146 ) )
return - V_24 ;
if ( F_102 ( V_48 ,
V_76 + F_106 ( struct V_168 , V_177 ) ,
& V_48 -> V_32 . V_54 -> V_80 , 128 , V_146 ) )
return - V_24 ;
return 0 ;
}
long F_107 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_47 * V_48 = V_5 -> V_19 ;
void T_1 * V_20 = ( void T_1 * ) V_7 ;
long V_11 ;
switch ( V_6 ) {
case V_21 : {
struct V_22 V_23 ;
V_11 = - V_24 ;
if ( F_14 ( & V_23 , V_20 , sizeof( V_23 ) ) )
break;
V_11 = F_108 ( V_48 , & V_23 ) ;
break;
}
case V_178 :
V_11 = F_105 ( V_48 , V_7 ) ;
break;
case V_179 : {
T_2 V_118 ;
V_11 = - V_24 ;
if ( F_14 ( & V_118 , V_20 , sizeof( V_118 ) ) )
break;
V_11 = F_79 ( V_48 , V_118 ) ;
break;
}
case V_180 :
V_11 = F_72 ( V_48 ) ;
break;
#ifdef F_11
case V_181 : {
struct V_182 V_183 ;
if ( F_14 ( & V_183 , V_20 , sizeof( V_183 ) ) ) {
V_11 = - V_24 ;
break;
}
if ( ! F_29 ( V_48 -> V_17 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_109 ( V_48 -> V_32 . V_44 , V_183 . V_184 ,
V_183 . V_185 , V_183 . V_186 ) ;
break;
}
case V_187 : {
struct V_182 V_183 ;
if ( F_14 ( & V_183 , V_20 , sizeof( V_183 ) ) ) {
V_11 = - V_24 ;
break;
}
if ( ! F_29 ( V_48 -> V_17 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_110 ( V_48 -> V_32 . V_44 , V_183 . V_185 ,
V_183 . V_186 ) ;
break;
}
#endif
case V_188 : {
V_11 = F_111 ( V_7 , V_48 -> V_32 . V_44 ) ;
if ( ! F_112 ( V_11 ) )
V_11 = 0 ;
break;
}
default:
V_11 = - V_25 ;
}
return V_11 ;
}
int F_113 ( struct V_47 * V_48 , struct V_189 * V_190 )
{
#ifdef F_11
if ( ( V_190 -> V_191 == V_192 )
&& ( F_29 ( V_48 -> V_17 ) ) ) {
V_190 -> V_193 = F_114 ( V_48 -> V_32 . V_54 ) ;
F_115 ( V_190 -> V_193 ) ;
return 0 ;
}
#endif
return V_194 ;
}
void F_116 ( struct V_195 * free ,
struct V_195 * V_196 )
{
}
int F_117 ( struct V_195 * V_197 , unsigned long V_198 )
{
return 0 ;
}
int F_118 ( struct V_17 * V_17 ,
struct V_195 * V_199 ,
struct V_195 V_200 ,
struct V_201 * V_202 ,
int V_203 )
{
if ( V_202 -> V_197 )
return - V_9 ;
if ( V_202 -> V_204 )
return - V_9 ;
if ( V_202 -> V_205 & 0xffffful )
return - V_9 ;
if ( V_202 -> V_206 & 0xffffful )
return - V_9 ;
if ( ! V_203 )
return - V_9 ;
return 0 ;
}
void F_119 ( struct V_17 * V_17 ,
struct V_201 * V_202 ,
struct V_195 V_200 ,
int V_203 )
{
int V_26 ;
V_26 = F_109 ( V_17 -> V_32 . V_44 , V_202 -> V_205 ,
V_202 -> V_204 , V_202 -> V_206 ) ;
if ( V_26 )
F_120 ( V_207 L_9 ) ;
return;
}
void F_121 ( struct V_17 * V_17 )
{
}
static int T_5 F_122 ( void )
{
int V_208 ;
V_208 = F_123 ( NULL , sizeof( struct V_47 ) , 0 , V_209 ) ;
if ( V_208 )
return V_208 ;
V_88 = ( unsigned long long * ) F_18 ( V_35 | V_210 ) ;
if ( ! V_88 ) {
F_124 () ;
return - V_31 ;
}
memcpy ( V_88 , V_211 . V_212 , 16 ) ;
V_88 [ 0 ] &= 0xff00fff3f47c0000ULL ;
V_88 [ 1 ] &= 0x201c000000000000ULL ;
return 0 ;
}
static void T_6 F_125 ( void )
{
F_26 ( ( unsigned long ) V_88 ) ;
F_124 () ;
}
