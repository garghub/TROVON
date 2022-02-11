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
V_11 = 1 ;
break;
case V_20 :
case V_21 :
V_11 = V_22 ;
break;
case V_23 :
V_11 = V_24 ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
int F_12 ( struct V_25 * V_25 ,
struct V_26 * log )
{
return 0 ;
}
long F_13 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned long V_7 )
{
struct V_25 * V_25 = V_5 -> V_27 ;
void T_1 * V_28 = ( void T_1 * ) V_7 ;
int V_11 ;
switch ( V_6 ) {
case V_29 : {
struct V_30 V_31 ;
V_11 = - V_32 ;
if ( F_14 ( & V_31 , V_28 , sizeof( V_31 ) ) )
break;
V_11 = F_15 ( V_25 , & V_31 ) ;
break;
}
default:
V_11 = - V_33 ;
}
return V_11 ;
}
int F_16 ( struct V_25 * V_25 , unsigned long type )
{
int V_34 ;
char V_35 [ 16 ] ;
V_34 = - V_9 ;
#ifdef F_11
if ( type & ~ V_36 )
goto V_37;
if ( ( type & V_36 ) && ( ! F_17 ( V_38 ) ) )
goto V_37;
#else
if ( type )
goto V_37;
#endif
V_34 = F_9 () ;
if ( V_34 )
goto V_37;
V_34 = - V_39 ;
V_25 -> V_40 . V_41 = (struct V_42 * ) F_18 ( V_43 ) ;
if ( ! V_25 -> V_40 . V_41 )
goto V_37;
sprintf ( V_35 , L_1 , V_44 -> V_45 ) ;
V_25 -> V_40 . V_46 = F_19 ( V_35 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_25 -> V_40 . V_46 )
goto V_47;
F_20 ( & V_25 -> V_40 . V_48 . V_49 ) ;
F_21 ( & V_25 -> V_40 . V_48 . V_50 ) ;
F_22 ( V_25 -> V_40 . V_46 , & V_51 ) ;
F_23 ( V_25 , 3 , L_2 , L_3 ) ;
if ( type & V_36 ) {
V_25 -> V_40 . V_52 = NULL ;
} else {
V_25 -> V_40 . V_52 = F_24 ( V_44 -> V_53 ) ;
if ( ! V_25 -> V_40 . V_52 )
goto V_54;
}
V_25 -> V_40 . V_55 = 0 ;
return 0 ;
V_54:
F_25 ( V_25 -> V_40 . V_46 ) ;
V_47:
F_26 ( ( unsigned long ) ( V_25 -> V_40 . V_41 ) ) ;
V_37:
return V_34 ;
}
void F_27 ( struct V_56 * V_57 )
{
F_28 ( V_57 , 3 , L_2 , L_4 ) ;
F_29 ( V_57 -> V_58 ) ;
if ( ! F_30 ( V_57 -> V_25 ) ) {
F_31 ( 63 - V_57 -> V_58 ,
( unsigned long * ) & V_57 -> V_25 -> V_40 . V_41 -> V_59 ) ;
if ( V_57 -> V_25 -> V_40 . V_41 -> V_60 [ V_57 -> V_58 ] . V_61 ==
( V_62 ) V_57 -> V_40 . V_63 )
V_57 -> V_25 -> V_40 . V_41 -> V_60 [ V_57 -> V_58 ] . V_61 = 0 ;
}
F_32 () ;
if ( F_30 ( V_57 -> V_25 ) )
F_33 ( V_57 -> V_40 . V_52 ) ;
F_26 ( ( unsigned long ) ( V_57 -> V_40 . V_63 ) ) ;
F_34 ( V_57 ) ;
F_35 ( V_57 ) ;
}
static void F_36 ( struct V_25 * V_25 )
{
unsigned int V_64 ;
struct V_56 * V_57 ;
F_37 (i, vcpu, kvm)
F_27 ( V_57 ) ;
F_38 ( & V_25 -> V_49 ) ;
for ( V_64 = 0 ; V_64 < F_39 ( & V_25 -> V_65 ) ; V_64 ++ )
V_25 -> V_66 [ V_64 ] = NULL ;
F_40 ( & V_25 -> V_65 , 0 ) ;
F_41 ( & V_25 -> V_49 ) ;
}
void F_42 ( struct V_25 * V_25 )
{
}
void F_43 ( struct V_25 * V_25 )
{
F_36 ( V_25 ) ;
F_26 ( ( unsigned long ) ( V_25 -> V_40 . V_41 ) ) ;
F_25 ( V_25 -> V_40 . V_46 ) ;
if ( ! F_30 ( V_25 ) )
F_33 ( V_25 -> V_40 . V_52 ) ;
}
int F_44 ( struct V_56 * V_57 )
{
if ( F_30 ( V_57 -> V_25 ) ) {
V_57 -> V_40 . V_52 = F_24 ( V_44 -> V_53 ) ;
if ( ! V_57 -> V_40 . V_52 )
return - V_39 ;
return 0 ;
}
V_57 -> V_40 . V_52 = V_57 -> V_25 -> V_40 . V_52 ;
V_57 -> V_67 -> V_68 = V_69 |
V_70 |
V_71 |
V_72 ;
return 0 ;
}
void F_45 ( struct V_56 * V_57 )
{
}
void F_46 ( struct V_56 * V_57 , int V_60 )
{
F_47 ( & V_57 -> V_40 . V_73 ) ;
F_48 ( V_57 -> V_40 . V_74 ) ;
V_57 -> V_40 . V_75 . V_76 &= V_77 ;
F_49 ( & V_57 -> V_40 . V_75 ) ;
F_50 ( V_57 -> V_67 -> V_78 . V_79 . V_80 ) ;
F_51 ( V_57 -> V_40 . V_52 ) ;
F_52 ( V_81 , & V_57 -> V_40 . V_63 -> V_82 ) ;
}
void F_53 ( struct V_56 * V_57 )
{
F_54 ( V_81 , & V_57 -> V_40 . V_63 -> V_82 ) ;
F_55 ( V_57 -> V_40 . V_52 ) ;
F_47 ( & V_57 -> V_40 . V_75 ) ;
F_48 ( V_57 -> V_67 -> V_78 . V_79 . V_80 ) ;
F_49 ( & V_57 -> V_40 . V_73 ) ;
F_50 ( V_57 -> V_40 . V_74 ) ;
}
static void F_56 ( struct V_56 * V_57 )
{
V_57 -> V_40 . V_63 -> V_83 . V_84 = 0UL ;
V_57 -> V_40 . V_63 -> V_83 . V_85 = 0UL ;
F_57 ( V_57 , 0 ) ;
V_57 -> V_40 . V_63 -> V_86 = 0UL ;
V_57 -> V_40 . V_63 -> V_87 = 0UL ;
V_57 -> V_40 . V_63 -> V_88 = 0 ;
memset ( V_57 -> V_40 . V_63 -> V_89 , 0 , 16 * sizeof( V_62 ) ) ;
V_57 -> V_40 . V_63 -> V_89 [ 0 ] = 0xE0UL ;
V_57 -> V_40 . V_63 -> V_89 [ 14 ] = 0xC2000000UL ;
V_57 -> V_40 . V_75 . V_76 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_57 -> V_40 . V_63 -> V_90 = 1 ;
F_52 ( V_91 , & V_57 -> V_40 . V_63 -> V_82 ) ;
}
int F_58 ( struct V_56 * V_57 )
{
return 0 ;
}
int F_59 ( struct V_56 * V_57 )
{
F_40 ( & V_57 -> V_40 . V_63 -> V_82 , V_92 |
V_93 |
V_91 ) ;
V_57 -> V_40 . V_63 -> V_94 = 6 ;
V_57 -> V_40 . V_63 -> V_95 = 0xC1002001U ;
V_57 -> V_40 . V_63 -> V_96 = ( int ) ( long ) V_97 ;
F_60 ( & V_57 -> V_40 . V_98 , V_99 , V_100 ) ;
F_61 ( & V_57 -> V_40 . V_101 , V_102 ,
( unsigned long ) V_57 ) ;
V_57 -> V_40 . V_98 . V_103 = V_104 ;
F_62 ( & V_57 -> V_40 . V_105 ) ;
V_57 -> V_40 . V_105 . V_106 = 0xff ;
return 0 ;
}
struct V_56 * F_63 ( struct V_25 * V_25 ,
unsigned int V_107 )
{
struct V_56 * V_57 ;
int V_34 = - V_9 ;
if ( V_107 >= V_22 )
goto V_108;
V_34 = - V_39 ;
V_57 = F_64 ( sizeof( struct V_56 ) , V_43 ) ;
if ( ! V_57 )
goto V_108;
V_57 -> V_40 . V_63 = (struct V_109 * )
F_18 ( V_43 ) ;
if ( ! V_57 -> V_40 . V_63 )
goto V_110;
V_57 -> V_40 . V_63 -> V_111 = V_107 ;
if ( ! F_30 ( V_25 ) ) {
if ( ! V_25 -> V_40 . V_41 ) {
F_65 ( 1 ) ;
goto V_110;
}
if ( ! V_25 -> V_40 . V_41 -> V_60 [ V_107 ] . V_61 )
V_25 -> V_40 . V_41 -> V_60 [ V_107 ] . V_61 =
( V_62 ) V_57 -> V_40 . V_63 ;
V_57 -> V_40 . V_63 -> V_112 =
( V_113 ) ( ( ( V_62 ) V_25 -> V_40 . V_41 ) >> 32 ) ;
V_57 -> V_40 . V_63 -> V_114 = ( V_113 ) ( V_62 ) V_25 -> V_40 . V_41 ;
F_66 ( 63 - V_107 , ( unsigned long * ) & V_25 -> V_40 . V_41 -> V_59 ) ;
}
F_20 ( & V_57 -> V_40 . V_115 . V_49 ) ;
F_21 ( & V_57 -> V_40 . V_115 . V_50 ) ;
V_57 -> V_40 . V_115 . V_48 = & V_25 -> V_40 . V_48 ;
F_67 ( & V_25 -> V_40 . V_48 . V_49 ) ;
V_25 -> V_40 . V_48 . V_115 [ V_107 ] = & V_57 -> V_40 . V_115 ;
F_68 ( & V_57 -> V_40 . V_115 . V_116 ) ;
V_57 -> V_40 . V_115 . V_82 = & V_57 -> V_40 . V_63 -> V_82 ;
F_69 ( & V_25 -> V_40 . V_48 . V_49 ) ;
V_34 = F_70 ( V_57 , V_25 , V_107 ) ;
if ( V_34 )
goto V_117;
F_23 ( V_25 , 3 , L_5 , V_107 , V_57 ,
V_57 -> V_40 . V_63 ) ;
F_71 ( V_107 , V_57 , V_57 -> V_40 . V_63 ) ;
return V_57 ;
V_117:
F_26 ( ( unsigned long ) ( V_57 -> V_40 . V_63 ) ) ;
V_110:
F_35 ( V_57 ) ;
V_108:
return F_72 ( V_34 ) ;
}
int F_73 ( struct V_56 * V_57 )
{
F_74 () ;
return 0 ;
}
int F_75 ( struct V_56 * V_57 )
{
F_74 () ;
return 0 ;
}
static int F_76 ( struct V_56 * V_57 ,
struct V_118 * V_119 )
{
int V_11 = - V_9 ;
switch ( V_119 -> V_107 ) {
case V_120 :
V_11 = F_77 ( V_57 -> V_40 . V_63 -> V_88 ,
( V_121 T_1 * ) V_119 -> V_85 ) ;
break;
case V_122 :
V_11 = F_77 ( V_57 -> V_40 . V_63 -> V_123 ,
( V_124 T_1 * ) V_119 -> V_85 ) ;
break;
case V_125 :
V_11 = F_77 ( V_57 -> V_40 . V_63 -> V_86 ,
( V_124 T_1 * ) V_119 -> V_85 ) ;
break;
case V_126 :
V_11 = F_77 ( V_57 -> V_40 . V_63 -> V_87 ,
( V_124 T_1 * ) V_119 -> V_85 ) ;
break;
default:
break;
}
return V_11 ;
}
static int F_78 ( struct V_56 * V_57 ,
struct V_118 * V_119 )
{
int V_11 = - V_9 ;
switch ( V_119 -> V_107 ) {
case V_120 :
V_11 = F_79 ( V_57 -> V_40 . V_63 -> V_88 ,
( V_121 T_1 * ) V_119 -> V_85 ) ;
break;
case V_122 :
V_11 = F_79 ( V_57 -> V_40 . V_63 -> V_123 ,
( V_124 T_1 * ) V_119 -> V_85 ) ;
break;
case V_125 :
V_11 = F_79 ( V_57 -> V_40 . V_63 -> V_86 ,
( V_124 T_1 * ) V_119 -> V_85 ) ;
break;
case V_126 :
V_11 = F_79 ( V_57 -> V_40 . V_63 -> V_87 ,
( V_124 T_1 * ) V_119 -> V_85 ) ;
break;
default:
break;
}
return V_11 ;
}
static int F_80 ( struct V_56 * V_57 )
{
F_56 ( V_57 ) ;
return 0 ;
}
int F_81 ( struct V_56 * V_57 , struct V_127 * V_79 )
{
memcpy ( & V_57 -> V_67 -> V_78 . V_79 . V_128 , & V_79 -> V_128 , sizeof( V_79 -> V_128 ) ) ;
return 0 ;
}
int F_82 ( struct V_56 * V_57 , struct V_127 * V_79 )
{
memcpy ( & V_79 -> V_128 , & V_57 -> V_67 -> V_78 . V_79 . V_128 , sizeof( V_79 -> V_128 ) ) ;
return 0 ;
}
int F_83 ( struct V_56 * V_57 ,
struct V_129 * V_130 )
{
memcpy ( & V_57 -> V_67 -> V_78 . V_79 . V_80 , & V_130 -> V_80 , sizeof( V_130 -> V_80 ) ) ;
memcpy ( & V_57 -> V_40 . V_63 -> V_89 , & V_130 -> V_131 , sizeof( V_130 -> V_131 ) ) ;
F_50 ( V_57 -> V_67 -> V_78 . V_79 . V_80 ) ;
return 0 ;
}
int F_84 ( struct V_56 * V_57 ,
struct V_129 * V_130 )
{
memcpy ( & V_130 -> V_80 , & V_57 -> V_67 -> V_78 . V_79 . V_80 , sizeof( V_130 -> V_80 ) ) ;
memcpy ( & V_130 -> V_131 , & V_57 -> V_40 . V_63 -> V_89 , sizeof( V_130 -> V_131 ) ) ;
return 0 ;
}
int F_85 ( struct V_56 * V_57 , struct V_132 * V_133 )
{
memcpy ( & V_57 -> V_40 . V_75 . V_134 , & V_133 -> V_134 , sizeof( V_133 -> V_134 ) ) ;
V_57 -> V_40 . V_75 . V_76 = V_133 -> V_76 & V_77 ;
F_49 ( & V_57 -> V_40 . V_75 ) ;
return 0 ;
}
int F_86 ( struct V_56 * V_57 , struct V_132 * V_133 )
{
memcpy ( & V_133 -> V_134 , & V_57 -> V_40 . V_75 . V_134 , sizeof( V_133 -> V_134 ) ) ;
V_133 -> V_76 = V_57 -> V_40 . V_75 . V_76 ;
return 0 ;
}
static int F_87 ( struct V_56 * V_57 , T_2 V_135 )
{
int V_34 = 0 ;
if ( ! ( F_39 ( & V_57 -> V_40 . V_63 -> V_82 ) & V_91 ) )
V_34 = - V_136 ;
else {
V_57 -> V_67 -> V_137 = V_135 . V_84 ;
V_57 -> V_67 -> V_138 = V_135 . V_85 ;
}
return V_34 ;
}
int F_88 ( struct V_56 * V_57 ,
struct V_139 * V_140 )
{
return - V_9 ;
}
int F_89 ( struct V_56 * V_57 ,
struct V_141 * V_142 )
{
return - V_9 ;
}
int F_90 ( struct V_56 * V_57 ,
struct V_143 * V_144 )
{
return - V_9 ;
}
int F_91 ( struct V_56 * V_57 ,
struct V_143 * V_144 )
{
return - V_9 ;
}
static int F_92 ( struct V_56 * V_57 )
{
int V_34 ;
memcpy ( & V_57 -> V_40 . V_63 -> V_145 , & V_57 -> V_67 -> V_78 . V_79 . V_128 [ 14 ] , 16 ) ;
if ( F_93 () )
F_94 () ;
if ( F_95 ( V_146 ) )
F_96 () ;
if ( ! F_30 ( V_57 -> V_25 ) )
F_97 ( V_57 ) ;
V_57 -> V_40 . V_63 -> V_147 = 0 ;
F_98 () ;
F_99 () ;
F_100 () ;
F_28 ( V_57 , 6 , L_6 ,
F_39 ( & V_57 -> V_40 . V_63 -> V_82 ) ) ;
F_101 ( V_57 ,
F_39 ( & V_57 -> V_40 . V_63 -> V_82 ) ) ;
V_34 = F_102 ( V_57 -> V_40 . V_63 , V_57 -> V_67 -> V_78 . V_79 . V_128 ) ;
if ( V_34 ) {
if ( F_30 ( V_57 -> V_25 ) ) {
V_34 = V_148 ;
} else {
F_28 ( V_57 , 3 , L_2 , L_7 ) ;
F_103 ( V_57 ) ;
F_104 ( V_57 , V_149 ) ;
V_34 = 0 ;
}
}
F_28 ( V_57 , 6 , L_8 ,
V_57 -> V_40 . V_63 -> V_147 ) ;
F_105 ( V_57 , V_57 -> V_40 . V_63 -> V_147 ) ;
F_106 () ;
memcpy ( & V_57 -> V_67 -> V_78 . V_79 . V_128 [ 14 ] , & V_57 -> V_40 . V_63 -> V_145 , 16 ) ;
return V_34 ;
}
int F_107 ( struct V_56 * V_57 , struct V_150 * V_150 )
{
int V_34 ;
T_3 V_151 ;
V_152:
if ( V_57 -> V_153 )
F_108 ( V_154 , & V_57 -> V_155 , & V_151 ) ;
F_54 ( V_91 , & V_57 -> V_40 . V_63 -> V_82 ) ;
F_109 ( V_57 -> V_25 -> V_40 . V_48 . V_115 [ V_57 -> V_58 ] == NULL ) ;
switch ( V_150 -> V_156 ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
break;
default:
F_74 () ;
}
V_57 -> V_40 . V_63 -> V_83 . V_84 = V_150 -> V_137 ;
V_57 -> V_40 . V_63 -> V_83 . V_85 = V_150 -> V_138 ;
if ( V_150 -> V_163 & V_69 ) {
V_150 -> V_163 &= ~ V_69 ;
F_57 ( V_57 , V_150 -> V_78 . V_79 . V_164 ) ;
}
if ( V_150 -> V_163 & V_72 ) {
V_150 -> V_163 &= ~ V_72 ;
memcpy ( & V_57 -> V_40 . V_63 -> V_89 , & V_150 -> V_78 . V_79 . V_131 , 128 ) ;
F_57 ( V_57 , V_150 -> V_78 . V_79 . V_164 ) ;
}
F_110 () ;
do {
V_34 = F_92 ( V_57 ) ;
if ( V_34 )
break;
if ( F_30 ( V_57 -> V_25 ) )
V_34 = - V_165 ;
else
V_34 = F_111 ( V_57 ) ;
} while ( ! F_112 ( V_44 ) && ! V_34 );
if ( V_34 == V_166 )
goto V_152;
if ( F_112 ( V_44 ) && ! V_34 ) {
V_150 -> V_156 = V_159 ;
V_34 = - V_167 ;
}
#ifdef F_11
if ( V_34 == V_148 ) {
V_150 -> V_156 = V_161 ;
V_150 -> V_168 . V_169 =
V_44 -> V_170 . V_171 ;
V_150 -> V_168 . V_172 = 0x10 ;
V_34 = 0 ;
}
#endif
if ( V_34 == - V_165 ) {
V_150 -> V_156 = V_157 ;
V_150 -> V_173 . V_147 = V_57 -> V_40 . V_63 -> V_147 ;
V_150 -> V_173 . V_174 = V_57 -> V_40 . V_63 -> V_174 ;
V_150 -> V_173 . V_175 = V_57 -> V_40 . V_63 -> V_175 ;
V_34 = 0 ;
}
if ( V_34 == - V_176 ) {
V_34 = 0 ;
}
V_150 -> V_137 = V_57 -> V_40 . V_63 -> V_83 . V_84 ;
V_150 -> V_138 = V_57 -> V_40 . V_63 -> V_83 . V_85 ;
V_150 -> V_78 . V_79 . V_164 = V_57 -> V_40 . V_63 -> V_164 ;
memcpy ( & V_150 -> V_78 . V_79 . V_131 , & V_57 -> V_40 . V_63 -> V_89 , 128 ) ;
if ( V_57 -> V_153 )
F_108 ( V_154 , & V_151 , NULL ) ;
V_57 -> V_177 . V_178 ++ ;
return V_34 ;
}
static int F_113 ( struct V_56 * V_57 , V_124 V_179 , void * V_180 ,
unsigned long V_181 , int V_164 )
{
if ( V_164 )
return F_114 ( V_57 , V_179 , V_180 , V_181 ) ;
else
return F_115 ( V_57 , V_179 , V_180 , V_181 ) ;
}
int F_116 ( struct V_56 * V_57 , unsigned long V_85 )
{
unsigned char V_182 = 1 ;
int V_164 ;
if ( V_85 == V_183 ) {
if ( F_115 ( V_57 , 163ul , & V_182 , 1 ) )
return - V_32 ;
V_85 = V_184 ;
V_164 = 0 ;
} else if ( V_85 == V_185 ) {
if ( F_114 ( V_57 , 163ul , & V_182 , 1 ) )
return - V_32 ;
V_85 = V_184 ;
V_164 = 1 ;
} else
V_164 = 0 ;
F_47 ( & V_57 -> V_40 . V_75 ) ;
F_48 ( V_57 -> V_67 -> V_78 . V_79 . V_80 ) ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_187 ) ,
V_57 -> V_40 . V_75 . V_134 , 128 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_188 ) ,
V_57 -> V_67 -> V_78 . V_79 . V_128 , 128 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_135 ) ,
& V_57 -> V_40 . V_63 -> V_83 , 16 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_189 ) ,
& V_57 -> V_40 . V_63 -> V_164 , 4 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 ,
V_85 + F_117 ( struct V_186 , V_190 ) ,
& V_57 -> V_40 . V_75 . V_76 , 4 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_191 ) ,
& V_57 -> V_40 . V_63 -> V_88 , 4 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_192 ) ,
& V_57 -> V_40 . V_63 -> V_86 , 8 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_193 ) ,
& V_57 -> V_40 . V_63 -> V_87 , 8 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 , V_85 + F_117 ( struct V_186 , V_194 ) ,
& V_57 -> V_67 -> V_78 . V_79 . V_80 , 64 , V_164 ) )
return - V_32 ;
if ( F_113 ( V_57 ,
V_85 + F_117 ( struct V_186 , V_195 ) ,
& V_57 -> V_40 . V_63 -> V_89 , 128 , V_164 ) )
return - V_32 ;
return 0 ;
}
static int F_118 ( struct V_56 * V_57 ,
struct V_196 * V_197 )
{
int V_11 ;
if ( V_197 -> V_198 )
return - V_9 ;
switch ( V_197 -> V_197 ) {
case V_19 :
if ( ! V_57 -> V_25 -> V_40 . V_55 ) {
V_57 -> V_25 -> V_40 . V_55 = 1 ;
F_119 ( V_57 -> V_25 ) ;
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
struct V_56 * V_57 = V_5 -> V_27 ;
void T_1 * V_28 = ( void T_1 * ) V_7 ;
long V_11 ;
switch ( V_6 ) {
case V_29 : {
struct V_30 V_31 ;
V_11 = - V_32 ;
if ( F_14 ( & V_31 , V_28 , sizeof( V_31 ) ) )
break;
V_11 = F_121 ( V_57 , & V_31 ) ;
break;
}
case V_199 :
V_11 = F_116 ( V_57 , V_7 ) ;
break;
case V_200 : {
T_2 V_135 ;
V_11 = - V_32 ;
if ( F_14 ( & V_135 , V_28 , sizeof( V_135 ) ) )
break;
V_11 = F_87 ( V_57 , V_135 ) ;
break;
}
case V_201 :
V_11 = F_80 ( V_57 ) ;
break;
case V_202 :
case V_203 : {
struct V_118 V_119 ;
V_11 = - V_32 ;
if ( F_14 ( & V_119 , V_28 , sizeof( V_119 ) ) )
break;
if ( V_6 == V_202 )
V_11 = F_78 ( V_57 , & V_119 ) ;
else
V_11 = F_76 ( V_57 , & V_119 ) ;
break;
}
#ifdef F_11
case V_204 : {
struct V_205 V_206 ;
if ( F_14 ( & V_206 , V_28 , sizeof( V_206 ) ) ) {
V_11 = - V_32 ;
break;
}
if ( ! F_30 ( V_57 -> V_25 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_122 ( V_57 -> V_40 . V_52 , V_206 . V_207 ,
V_206 . V_208 , V_206 . V_209 ) ;
break;
}
case V_210 : {
struct V_205 V_206 ;
if ( F_14 ( & V_206 , V_28 , sizeof( V_206 ) ) ) {
V_11 = - V_32 ;
break;
}
if ( ! F_30 ( V_57 -> V_25 ) ) {
V_11 = - V_9 ;
break;
}
V_11 = F_123 ( V_57 -> V_40 . V_52 , V_206 . V_208 ,
V_206 . V_209 ) ;
break;
}
#endif
case V_211 : {
V_11 = F_124 ( V_7 , V_57 -> V_40 . V_52 ) ;
if ( ! F_125 ( V_11 ) )
V_11 = 0 ;
break;
}
case V_212 :
{
struct V_196 V_197 ;
V_11 = - V_32 ;
if ( F_14 ( & V_197 , V_28 , sizeof( V_197 ) ) )
break;
V_11 = F_118 ( V_57 , & V_197 ) ;
break;
}
default:
V_11 = - V_33 ;
}
return V_11 ;
}
int F_126 ( struct V_56 * V_57 , struct V_213 * V_214 )
{
#ifdef F_11
if ( ( V_214 -> V_215 == V_216 )
&& ( F_30 ( V_57 -> V_25 ) ) ) {
V_214 -> V_217 = F_127 ( V_57 -> V_40 . V_63 ) ;
F_128 ( V_214 -> V_217 ) ;
return 0 ;
}
#endif
return V_218 ;
}
void F_129 ( struct V_219 * free ,
struct V_219 * V_220 )
{
}
int F_130 ( struct V_219 * V_221 , unsigned long V_222 )
{
return 0 ;
}
int F_131 ( struct V_25 * V_25 ,
struct V_219 * V_223 ,
struct V_219 V_224 ,
struct V_225 * V_226 ,
bool V_227 )
{
if ( V_226 -> V_221 )
return - V_9 ;
if ( V_226 -> V_228 )
return - V_9 ;
if ( V_226 -> V_229 & 0xffffful )
return - V_9 ;
if ( V_226 -> V_230 & 0xffffful )
return - V_9 ;
if ( ! V_227 )
return - V_9 ;
return 0 ;
}
void F_132 ( struct V_25 * V_25 ,
struct V_225 * V_226 ,
struct V_219 V_224 ,
bool V_227 )
{
int V_34 ;
V_34 = F_122 ( V_25 -> V_40 . V_52 , V_226 -> V_229 ,
V_226 -> V_228 , V_226 -> V_230 ) ;
if ( V_34 )
F_133 ( V_231 L_9 ) ;
return;
}
void F_134 ( struct V_25 * V_25 )
{
}
void F_135 ( struct V_25 * V_25 ,
struct V_219 * V_221 )
{
}
static int T_4 F_136 ( void )
{
int V_232 ;
V_232 = F_137 ( NULL , sizeof( struct V_56 ) , 0 , V_233 ) ;
if ( V_232 )
return V_232 ;
V_97 = ( unsigned long long * ) F_18 ( V_43 | V_234 ) ;
if ( ! V_97 ) {
F_138 () ;
return - V_39 ;
}
memcpy ( V_97 , V_235 . V_236 , 16 ) ;
V_97 [ 0 ] &= 0xff00fff3f47c0000ULL ;
V_97 [ 1 ] &= 0x001c000000000000ULL ;
return 0 ;
}
static void T_5 F_139 ( void )
{
F_26 ( ( unsigned long ) V_97 ) ;
F_138 () ;
}
