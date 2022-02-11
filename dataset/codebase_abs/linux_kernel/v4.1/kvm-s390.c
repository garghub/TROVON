unsigned long F_1 ( void )
{
F_2 ( F_3 ( V_1 ) > V_2 ) ;
return F_3 ( V_1 ) ;
}
int F_4 ( void )
{
return 0 ;
}
int F_5 ( void )
{
V_3 . V_4 = V_5 ;
F_6 ( & V_3 ) ;
return 0 ;
}
void F_7 ( void )
{
F_8 ( & V_3 ) ;
}
int F_9 ( void * V_6 )
{
return F_10 ( & V_7 , V_8 ) ;
}
long F_11 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
if ( V_11 == V_13 )
return F_12 () ;
return - V_14 ;
}
int F_13 ( struct V_15 * V_15 , long V_16 )
{
int V_17 ;
switch ( V_16 ) {
case V_18 :
case V_19 :
case V_20 :
#ifdef F_14
case V_21 :
#endif
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_17 = 1 ;
break;
case V_38 :
V_17 = V_39 ;
break;
case V_40 :
case V_41 :
V_17 = V_42 ;
break;
case V_43 :
V_17 = V_44 ;
break;
case V_45 :
V_17 = V_46 ;
break;
case V_47 :
V_17 = V_48 ;
break;
default:
V_17 = 0 ;
}
return V_17 ;
}
static void F_15 ( struct V_15 * V_15 ,
struct V_49 * V_50 )
{
T_1 V_51 , V_52 ;
unsigned long V_53 ;
struct V_54 * V_54 = V_15 -> V_55 . V_54 ;
F_16 ( & V_54 -> V_56 -> V_57 ) ;
V_52 = V_50 -> V_58 + V_50 -> V_59 ;
for ( V_51 = V_50 -> V_58 ; V_51 <= V_52 ; V_51 ++ ) {
V_53 = F_17 ( V_50 , V_51 ) ;
if ( F_18 ( V_53 , V_54 ) )
F_19 ( V_15 , V_51 ) ;
}
F_20 ( & V_54 -> V_56 -> V_57 ) ;
}
int F_21 ( struct V_15 * V_15 ,
struct V_60 * log )
{
int V_17 ;
unsigned long V_61 ;
struct V_49 * V_50 ;
int V_62 = 0 ;
F_22 ( & V_15 -> V_63 ) ;
V_17 = - V_14 ;
if ( log -> V_64 >= V_44 )
goto V_65;
V_50 = F_23 ( V_15 -> V_66 , log -> V_64 ) ;
V_17 = - V_67 ;
if ( ! V_50 -> V_68 )
goto V_65;
F_15 ( V_15 , V_50 ) ;
V_17 = F_24 ( V_15 , log , & V_62 ) ;
if ( V_17 )
goto V_65;
if ( V_62 ) {
V_61 = F_25 ( V_50 ) ;
memset ( V_50 -> V_68 , 0 , V_61 ) ;
}
V_17 = 0 ;
V_65:
F_26 ( & V_15 -> V_63 ) ;
return V_17 ;
}
static int F_27 ( struct V_15 * V_15 , struct V_69 * V_70 )
{
int V_17 ;
if ( V_70 -> V_71 )
return - V_14 ;
switch ( V_70 -> V_70 ) {
case V_30 :
V_15 -> V_55 . V_72 = 1 ;
V_17 = 0 ;
break;
case V_34 :
V_15 -> V_55 . V_73 = 1 ;
V_17 = 0 ;
break;
case V_47 :
if ( V_48 ) {
F_28 ( V_15 -> V_55 . V_74 . V_75 -> V_76 , 129 ) ;
F_28 ( V_15 -> V_55 . V_74 . V_75 -> V_77 , 129 ) ;
V_17 = 0 ;
} else
V_17 = - V_14 ;
break;
case V_35 :
V_15 -> V_55 . V_78 = 1 ;
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
static int F_29 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 ;
switch ( V_80 -> V_80 ) {
case V_82 :
V_81 = 0 ;
if ( F_30 ( V_15 -> V_55 . V_54 -> V_83 , ( V_84 V_85 * ) V_80 -> V_86 ) )
V_81 = - V_87 ;
break;
default:
V_81 = - V_88 ;
break;
}
return V_81 ;
}
static int F_31 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 ;
unsigned int V_89 ;
switch ( V_80 -> V_80 ) {
case V_90 :
V_81 = - V_91 ;
F_22 ( & V_15 -> V_92 ) ;
if ( F_32 ( & V_15 -> V_93 ) == 0 ) {
V_15 -> V_55 . V_94 = 1 ;
V_81 = 0 ;
}
F_26 ( & V_15 -> V_92 ) ;
break;
case V_95 :
F_22 ( & V_15 -> V_92 ) ;
V_89 = F_33 ( & V_15 -> V_96 ) ;
F_34 ( V_15 -> V_55 . V_54 -> V_56 ) ;
F_35 ( & V_15 -> V_96 , V_89 ) ;
F_26 ( & V_15 -> V_92 ) ;
V_81 = 0 ;
break;
case V_82 : {
unsigned long V_97 ;
if ( F_36 ( V_15 ) )
return - V_14 ;
if ( F_37 ( V_97 , ( V_84 V_85 * ) V_80 -> V_86 ) )
return - V_87 ;
if ( V_97 > V_15 -> V_55 . V_54 -> V_83 )
return - V_98 ;
V_81 = - V_91 ;
F_22 ( & V_15 -> V_92 ) ;
if ( F_32 ( & V_15 -> V_93 ) == 0 ) {
struct V_54 * V_99 = F_38 ( V_100 -> V_56 , V_97 ) ;
if ( ! V_99 ) {
V_81 = - V_101 ;
} else {
F_39 ( V_15 -> V_55 . V_54 ) ;
V_99 -> V_102 = V_15 ;
V_15 -> V_55 . V_54 = V_99 ;
V_81 = 0 ;
}
}
F_26 ( & V_15 -> V_92 ) ;
break;
}
default:
V_81 = - V_88 ;
break;
}
return V_81 ;
}
static int F_40 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
struct V_103 * V_104 ;
int V_105 ;
if ( ! F_41 ( V_15 , 76 ) )
return - V_14 ;
F_22 ( & V_15 -> V_92 ) ;
switch ( V_80 -> V_80 ) {
case V_106 :
F_42 (
V_15 -> V_55 . V_107 . V_108 -> V_109 ,
sizeof( V_15 -> V_55 . V_107 . V_108 -> V_109 ) ) ;
V_15 -> V_55 . V_107 . V_110 = 1 ;
break;
case V_111 :
F_42 (
V_15 -> V_55 . V_107 . V_108 -> V_112 ,
sizeof( V_15 -> V_55 . V_107 . V_108 -> V_112 ) ) ;
V_15 -> V_55 . V_107 . V_113 = 1 ;
break;
case V_114 :
V_15 -> V_55 . V_107 . V_110 = 0 ;
memset ( V_15 -> V_55 . V_107 . V_108 -> V_109 , 0 ,
sizeof( V_15 -> V_55 . V_107 . V_108 -> V_109 ) ) ;
break;
case V_115 :
V_15 -> V_55 . V_107 . V_113 = 0 ;
memset ( V_15 -> V_55 . V_107 . V_108 -> V_112 , 0 ,
sizeof( V_15 -> V_55 . V_107 . V_108 -> V_112 ) ) ;
break;
default:
F_26 ( & V_15 -> V_92 ) ;
return - V_88 ;
}
F_43 (i, vcpu, kvm) {
F_44 ( V_104 ) ;
F_45 ( V_104 ) ;
}
F_26 ( & V_15 -> V_92 ) ;
return 0 ;
}
static int F_46 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
T_2 V_116 ;
if ( F_47 ( & V_116 , ( void V_85 * ) V_80 -> V_86 ,
sizeof( V_116 ) ) )
return - V_87 ;
if ( V_116 != 0 )
return - V_14 ;
return 0 ;
}
static int F_48 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
struct V_103 * V_117 ;
unsigned int V_118 ;
V_84 V_119 , V_120 ;
int V_17 ;
if ( F_47 ( & V_120 , ( void V_85 * ) V_80 -> V_86 , sizeof( V_120 ) ) )
return - V_87 ;
V_17 = F_49 ( & V_119 ) ;
if ( V_17 )
return V_17 ;
F_22 ( & V_15 -> V_92 ) ;
V_15 -> V_55 . V_121 = V_120 - V_119 ;
F_43 (vcpu_idx, cur_vcpu, kvm) {
V_117 -> V_55 . V_122 -> V_121 = V_15 -> V_55 . V_121 ;
F_45 ( V_117 ) ;
}
F_26 ( & V_15 -> V_92 ) ;
return 0 ;
}
static int F_50 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 ;
if ( V_80 -> V_71 )
return - V_14 ;
switch ( V_80 -> V_80 ) {
case V_123 :
V_81 = F_46 ( V_15 , V_80 ) ;
break;
case V_124 :
V_81 = F_48 ( V_15 , V_80 ) ;
break;
default:
V_81 = - V_88 ;
break;
}
return V_81 ;
}
static int F_51 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
T_2 V_116 = 0 ;
if ( F_52 ( ( void V_85 * ) V_80 -> V_86 , & V_116 ,
sizeof( V_116 ) ) )
return - V_87 ;
return 0 ;
}
static int F_53 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
V_84 V_119 , V_120 ;
int V_17 ;
V_17 = F_49 ( & V_119 ) ;
if ( V_17 )
return V_17 ;
V_120 = V_119 + V_15 -> V_55 . V_121 ;
if ( F_52 ( ( void V_85 * ) V_80 -> V_86 , & V_120 , sizeof( V_120 ) ) )
return - V_87 ;
return 0 ;
}
static int F_54 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 ;
if ( V_80 -> V_71 )
return - V_14 ;
switch ( V_80 -> V_80 ) {
case V_123 :
V_81 = F_51 ( V_15 , V_80 ) ;
break;
case V_124 :
V_81 = F_53 ( V_15 , V_80 ) ;
break;
default:
V_81 = - V_88 ;
break;
}
return V_81 ;
}
static int F_55 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
struct V_125 * V_126 ;
int V_81 = 0 ;
F_22 ( & V_15 -> V_92 ) ;
if ( F_32 ( & V_15 -> V_93 ) ) {
V_81 = - V_91 ;
goto V_65;
}
V_126 = F_56 ( sizeof( * V_126 ) , V_127 ) ;
if ( ! V_126 ) {
V_81 = - V_101 ;
goto V_65;
}
if ( ! F_47 ( V_126 , ( void V_85 * ) V_80 -> V_86 ,
sizeof( * V_126 ) ) ) {
memcpy ( & V_15 -> V_55 . V_74 . V_128 , & V_126 -> V_129 ,
sizeof( struct V_129 ) ) ;
V_15 -> V_55 . V_74 . V_130 = V_126 -> V_130 ;
memcpy ( V_15 -> V_55 . V_74 . V_75 -> V_77 , V_126 -> V_131 ,
V_132 ) ;
} else
V_81 = - V_87 ;
F_57 ( V_126 ) ;
V_65:
F_26 ( & V_15 -> V_92 ) ;
return V_81 ;
}
static int F_58 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 = - V_88 ;
switch ( V_80 -> V_80 ) {
case V_133 :
V_81 = F_55 ( V_15 , V_80 ) ;
break;
}
return V_81 ;
}
static int F_59 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
struct V_125 * V_126 ;
int V_81 = 0 ;
V_126 = F_56 ( sizeof( * V_126 ) , V_127 ) ;
if ( ! V_126 ) {
V_81 = - V_101 ;
goto V_65;
}
memcpy ( & V_126 -> V_129 , & V_15 -> V_55 . V_74 . V_128 , sizeof( struct V_129 ) ) ;
V_126 -> V_130 = V_15 -> V_55 . V_74 . V_130 ;
memcpy ( & V_126 -> V_131 , V_15 -> V_55 . V_74 . V_75 -> V_77 , V_132 ) ;
if ( F_52 ( ( void V_85 * ) V_80 -> V_86 , V_126 , sizeof( * V_126 ) ) )
V_81 = - V_87 ;
F_57 ( V_126 ) ;
V_65:
return V_81 ;
}
static int F_60 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
struct V_134 * V_135 ;
int V_81 = 0 ;
V_135 = F_56 ( sizeof( * V_135 ) , V_127 ) ;
if ( ! V_135 ) {
V_81 = - V_101 ;
goto V_65;
}
F_61 ( (struct V_129 * ) & V_135 -> V_129 ) ;
V_135 -> V_130 = F_62 () ;
memcpy ( & V_135 -> V_136 , V_15 -> V_55 . V_74 . V_75 -> V_76 ,
V_132 ) ;
memcpy ( ( unsigned long * ) & V_135 -> V_131 , V_137 . V_138 ,
V_132 ) ;
if ( F_52 ( ( void V_85 * ) V_80 -> V_86 , V_135 , sizeof( * V_135 ) ) )
V_81 = - V_87 ;
F_57 ( V_135 ) ;
V_65:
return V_81 ;
}
static int F_63 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 = - V_88 ;
switch ( V_80 -> V_80 ) {
case V_133 :
V_81 = F_59 ( V_15 , V_80 ) ;
break;
case V_139 :
V_81 = F_60 ( V_15 , V_80 ) ;
break;
}
return V_81 ;
}
static int F_64 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 ;
switch ( V_80 -> V_140 ) {
case V_141 :
V_81 = F_31 ( V_15 , V_80 ) ;
break;
case V_142 :
V_81 = F_50 ( V_15 , V_80 ) ;
break;
case V_143 :
V_81 = F_58 ( V_15 , V_80 ) ;
break;
case V_144 :
V_81 = F_40 ( V_15 , V_80 ) ;
break;
default:
V_81 = - V_88 ;
break;
}
return V_81 ;
}
static int F_65 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 ;
switch ( V_80 -> V_140 ) {
case V_141 :
V_81 = F_29 ( V_15 , V_80 ) ;
break;
case V_142 :
V_81 = F_54 ( V_15 , V_80 ) ;
break;
case V_143 :
V_81 = F_63 ( V_15 , V_80 ) ;
break;
default:
V_81 = - V_88 ;
break;
}
return V_81 ;
}
static int F_66 ( struct V_15 * V_15 , struct V_79 * V_80 )
{
int V_81 ;
switch ( V_80 -> V_140 ) {
case V_141 :
switch ( V_80 -> V_80 ) {
case V_90 :
case V_95 :
case V_82 :
V_81 = 0 ;
break;
default:
V_81 = - V_88 ;
break;
}
break;
case V_142 :
switch ( V_80 -> V_80 ) {
case V_124 :
case V_123 :
V_81 = 0 ;
break;
default:
V_81 = - V_88 ;
break;
}
break;
case V_143 :
switch ( V_80 -> V_80 ) {
case V_133 :
case V_139 :
V_81 = 0 ;
break;
default:
V_81 = - V_88 ;
break;
}
break;
case V_144 :
switch ( V_80 -> V_80 ) {
case V_106 :
case V_111 :
case V_114 :
case V_115 :
V_81 = 0 ;
break;
default:
V_81 = - V_88 ;
break;
}
break;
default:
V_81 = - V_88 ;
break;
}
return V_81 ;
}
static long F_67 ( struct V_15 * V_15 , struct V_145 * args )
{
T_3 * V_146 ;
T_4 V_147 ;
unsigned long V_148 ;
int V_105 , V_17 = 0 ;
if ( args -> V_71 != 0 )
return - V_14 ;
if ( ! F_68 ( V_100 -> V_56 ) )
return V_149 ;
if ( args -> V_150 < 1 || args -> V_150 > V_151 )
return - V_14 ;
V_146 = F_69 ( args -> V_150 , sizeof( T_3 ) ,
V_127 | V_152 ) ;
if ( ! V_146 )
V_146 = F_70 ( sizeof( T_3 ) * args -> V_150 ) ;
if ( ! V_146 )
return - V_101 ;
for ( V_105 = 0 ; V_105 < args -> V_150 ; V_105 ++ ) {
V_147 = F_71 ( V_15 , args -> V_153 + V_105 ) ;
if ( F_72 ( V_147 ) ) {
V_17 = - V_87 ;
goto V_65;
}
V_148 = F_73 ( V_100 -> V_56 , V_147 ) ;
if ( F_74 ( V_148 ) ) {
V_17 = V_148 ;
goto V_65;
}
V_146 [ V_105 ] = V_148 ;
}
V_17 = F_52 ( ( T_3 V_85 * ) args -> V_154 , V_146 ,
sizeof( T_3 ) * args -> V_150 ) ;
if ( V_17 )
V_17 = - V_87 ;
V_65:
F_75 ( V_146 ) ;
return V_17 ;
}
static long F_76 ( struct V_15 * V_15 , struct V_145 * args )
{
T_3 * V_146 ;
T_4 V_147 ;
int V_105 , V_17 = 0 ;
if ( args -> V_71 != 0 )
return - V_14 ;
if ( args -> V_150 < 1 || args -> V_150 > V_151 )
return - V_14 ;
V_146 = F_69 ( args -> V_150 , sizeof( T_3 ) ,
V_127 | V_152 ) ;
if ( ! V_146 )
V_146 = F_70 ( sizeof( T_3 ) * args -> V_150 ) ;
if ( ! V_146 )
return - V_101 ;
V_17 = F_47 ( V_146 , ( T_3 V_85 * ) args -> V_154 ,
sizeof( T_3 ) * args -> V_150 ) ;
if ( V_17 ) {
V_17 = - V_87 ;
goto V_65;
}
F_77 () ;
for ( V_105 = 0 ; V_105 < args -> V_150 ; V_105 ++ ) {
V_147 = F_71 ( V_15 , args -> V_153 + V_105 ) ;
if ( F_72 ( V_147 ) ) {
V_17 = - V_87 ;
goto V_65;
}
if ( V_146 [ V_105 ] & 0x01 ) {
V_17 = - V_14 ;
goto V_65;
}
V_17 = F_78 ( V_100 -> V_56 , V_147 ,
( unsigned long ) V_146 [ V_105 ] , 0 ) ;
if ( V_17 )
goto V_65;
}
V_65:
F_75 ( V_146 ) ;
return V_17 ;
}
long F_79 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_15 * V_15 = V_10 -> V_155 ;
void V_85 * V_156 = ( void V_85 * ) V_12 ;
struct V_79 V_80 ;
int V_17 ;
switch ( V_11 ) {
case V_157 : {
struct V_158 V_159 ;
V_17 = - V_87 ;
if ( F_47 ( & V_159 , V_156 , sizeof( V_159 ) ) )
break;
V_17 = F_80 ( V_15 , & V_159 ) ;
break;
}
case V_160 : {
struct V_69 V_70 ;
V_17 = - V_87 ;
if ( F_47 ( & V_70 , V_156 , sizeof( V_70 ) ) )
break;
V_17 = F_27 ( V_15 , & V_70 ) ;
break;
}
case V_161 : {
struct V_162 V_163 ;
V_17 = - V_14 ;
if ( V_15 -> V_55 . V_72 ) {
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
F_81 ( V_15 , & V_163 , 0 , 0 ) ;
V_17 = 0 ;
}
break;
}
case V_164 : {
V_17 = - V_87 ;
if ( F_47 ( & V_80 , ( void V_85 * ) V_12 , sizeof( V_80 ) ) )
break;
V_17 = F_64 ( V_15 , & V_80 ) ;
break;
}
case V_165 : {
V_17 = - V_87 ;
if ( F_47 ( & V_80 , ( void V_85 * ) V_12 , sizeof( V_80 ) ) )
break;
V_17 = F_65 ( V_15 , & V_80 ) ;
break;
}
case V_166 : {
V_17 = - V_87 ;
if ( F_47 ( & V_80 , ( void V_85 * ) V_12 , sizeof( V_80 ) ) )
break;
V_17 = F_66 ( V_15 , & V_80 ) ;
break;
}
case V_167 : {
struct V_145 args ;
V_17 = - V_87 ;
if ( F_47 ( & args , V_156 ,
sizeof( struct V_145 ) ) )
break;
V_17 = F_67 ( V_15 , & args ) ;
break;
}
case V_168 : {
struct V_145 args ;
V_17 = - V_87 ;
if ( F_47 ( & args , V_156 ,
sizeof( struct V_145 ) ) )
break;
V_17 = F_76 ( V_15 , & args ) ;
break;
}
default:
V_17 = - V_169 ;
}
return V_17 ;
}
static int F_82 ( T_2 * V_170 )
{
T_5 V_171 = 0x04000000UL ;
T_5 V_172 = 0 ;
memset ( V_170 , 0 , 128 ) ;
asm volatile(
"lgr 0,%1\n"
"lgr 2,%2\n"
".long 0xb2af0000\n"
"0: ipm %0\n"
"srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+r" (cc)
: "r" (fcn_code), "r" (config)
: "cc", "0", "2", "memory"
);
return V_172 ;
}
static int F_83 ( void )
{
T_2 V_170 [ 128 ] ;
int V_172 ;
if ( F_84 ( 2 ) && F_84 ( 12 ) ) {
V_172 = F_82 ( V_170 ) ;
if ( V_172 )
F_85 ( L_1 , V_172 ) ;
else
return V_170 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_86 ( struct V_15 * V_15 )
{
V_15 -> V_55 . V_107 . V_173 = ( V_174 ) ( unsigned long ) V_15 -> V_55 . V_107 . V_108 ;
if ( F_83 () )
V_15 -> V_55 . V_107 . V_173 |= V_175 ;
else
V_15 -> V_55 . V_107 . V_173 |= V_176 ;
}
static void F_87 ( struct V_129 * V_128 )
{
F_61 ( V_128 ) ;
V_128 -> V_177 = 0xff ;
}
static int F_88 ( struct V_15 * V_15 )
{
if ( ! F_41 ( V_15 , 76 ) )
return 0 ;
V_15 -> V_55 . V_107 . V_108 = F_56 ( sizeof( * V_15 -> V_55 . V_107 . V_108 ) ,
V_127 | V_178 ) ;
if ( ! V_15 -> V_55 . V_107 . V_108 )
return - V_101 ;
F_86 ( V_15 ) ;
V_15 -> V_55 . V_107 . V_110 = 1 ;
V_15 -> V_55 . V_107 . V_113 = 1 ;
F_42 ( V_15 -> V_55 . V_107 . V_108 -> V_109 ,
sizeof( V_15 -> V_55 . V_107 . V_108 -> V_109 ) ) ;
F_42 ( V_15 -> V_55 . V_107 . V_108 -> V_112 ,
sizeof( V_15 -> V_55 . V_107 . V_108 -> V_112 ) ) ;
return 0 ;
}
int F_89 ( struct V_15 * V_15 , unsigned long type )
{
int V_105 , V_179 ;
char V_180 [ 16 ] ;
static unsigned long V_181 ;
V_179 = - V_14 ;
#ifdef F_14
if ( type & ~ V_182 )
goto V_183;
if ( ( type & V_182 ) && ( ! F_90 ( V_184 ) ) )
goto V_183;
#else
if ( type )
goto V_183;
#endif
V_179 = F_12 () ;
if ( V_179 )
goto V_183;
V_179 = - V_101 ;
V_15 -> V_55 . V_185 = (struct V_186 * ) F_91 ( V_127 ) ;
if ( ! V_15 -> V_55 . V_185 )
goto V_183;
F_92 ( & V_187 ) ;
V_181 = ( V_181 + 16 ) & 0x7f0 ;
V_15 -> V_55 . V_185 = (struct V_186 * ) ( ( char * ) V_15 -> V_55 . V_185 + V_181 ) ;
F_93 ( & V_187 ) ;
sprintf ( V_180 , L_2 , V_100 -> V_188 ) ;
V_15 -> V_55 . V_189 = F_94 ( V_180 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_15 -> V_55 . V_189 )
goto V_183;
V_15 -> V_55 . V_74 . V_75 =
(struct V_190 * ) F_91 ( V_127 | V_178 ) ;
if ( ! V_15 -> V_55 . V_74 . V_75 )
goto V_183;
memcpy ( V_15 -> V_55 . V_74 . V_75 -> V_76 , V_137 . V_138 ,
V_132 ) ;
for ( V_105 = 0 ; V_105 < V_191 ; V_105 ++ ) {
if ( V_105 < F_1 () )
V_15 -> V_55 . V_74 . V_75 -> V_76 [ V_105 ] &= V_1 [ V_105 ] ;
else
V_15 -> V_55 . V_74 . V_75 -> V_76 [ V_105 ] = 0UL ;
}
memcpy ( V_15 -> V_55 . V_74 . V_75 -> V_77 , V_15 -> V_55 . V_74 . V_75 -> V_76 ,
V_132 ) ;
F_87 ( & V_15 -> V_55 . V_74 . V_128 ) ;
V_15 -> V_55 . V_74 . V_130 = F_62 () & 0x0fff ;
if ( F_88 ( V_15 ) < 0 )
goto V_183;
F_95 ( & V_15 -> V_55 . V_192 . V_92 ) ;
for ( V_105 = 0 ; V_105 < V_193 ; V_105 ++ )
F_96 ( & V_15 -> V_55 . V_192 . V_194 [ V_105 ] ) ;
F_97 ( & V_15 -> V_55 . V_195 ) ;
F_98 ( & V_15 -> V_55 . V_196 ) ;
F_99 ( V_15 -> V_55 . V_189 , & V_197 ) ;
F_100 ( V_15 , 3 , L_3 , L_4 ) ;
if ( type & V_182 ) {
V_15 -> V_55 . V_54 = NULL ;
} else {
V_15 -> V_55 . V_54 = F_38 ( V_100 -> V_56 , ( 1UL << 44 ) - 1 ) ;
if ( ! V_15 -> V_55 . V_54 )
goto V_183;
V_15 -> V_55 . V_54 -> V_102 = V_15 ;
V_15 -> V_55 . V_54 -> V_198 = 0 ;
}
V_15 -> V_55 . V_199 = 0 ;
V_15 -> V_55 . V_72 = 0 ;
V_15 -> V_55 . V_121 = 0 ;
F_95 ( & V_15 -> V_55 . V_200 ) ;
return 0 ;
V_183:
F_57 ( V_15 -> V_55 . V_107 . V_108 ) ;
F_101 ( ( unsigned long ) V_15 -> V_55 . V_74 . V_75 ) ;
F_102 ( V_15 -> V_55 . V_189 ) ;
F_101 ( ( unsigned long ) ( V_15 -> V_55 . V_185 ) ) ;
return V_179 ;
}
void F_103 ( struct V_103 * V_104 )
{
F_104 ( V_104 , 3 , L_3 , L_5 ) ;
F_105 ( V_104 -> V_201 ) ;
F_106 ( V_104 ) ;
F_107 ( V_104 ) ;
if ( ! F_36 ( V_104 -> V_15 ) ) {
F_108 ( 63 - V_104 -> V_201 ,
( unsigned long * ) & V_104 -> V_15 -> V_55 . V_185 -> V_202 ) ;
if ( V_104 -> V_15 -> V_55 . V_185 -> V_203 [ V_104 -> V_201 ] . V_204 ==
( V_205 ) V_104 -> V_55 . V_122 )
V_104 -> V_15 -> V_55 . V_185 -> V_203 [ V_104 -> V_201 ] . V_204 = 0 ;
}
F_109 () ;
if ( F_36 ( V_104 -> V_15 ) )
F_39 ( V_104 -> V_55 . V_54 ) ;
if ( F_110 ( V_104 -> V_15 ) )
F_111 ( V_104 ) ;
F_101 ( ( unsigned long ) ( V_104 -> V_55 . V_122 ) ) ;
F_112 ( V_104 ) ;
F_113 ( V_206 , V_104 ) ;
}
static void F_114 ( struct V_15 * V_15 )
{
unsigned int V_105 ;
struct V_103 * V_104 ;
F_43 (i, vcpu, kvm)
F_103 ( V_104 ) ;
F_22 ( & V_15 -> V_92 ) ;
for ( V_105 = 0 ; V_105 < F_32 ( & V_15 -> V_93 ) ; V_105 ++ )
V_15 -> V_207 [ V_105 ] = NULL ;
F_115 ( & V_15 -> V_93 , 0 ) ;
F_26 ( & V_15 -> V_92 ) ;
}
void F_116 ( struct V_15 * V_15 )
{
F_114 ( V_15 ) ;
F_101 ( ( unsigned long ) V_15 -> V_55 . V_74 . V_75 ) ;
F_101 ( ( unsigned long ) ( V_15 -> V_55 . V_185 ) ) ;
F_102 ( V_15 -> V_55 . V_189 ) ;
F_57 ( V_15 -> V_55 . V_107 . V_108 ) ;
if ( ! F_36 ( V_15 ) )
F_39 ( V_15 -> V_55 . V_54 ) ;
F_117 ( V_15 ) ;
F_118 ( V_15 ) ;
}
static int F_119 ( struct V_103 * V_104 )
{
V_104 -> V_55 . V_54 = F_38 ( V_100 -> V_56 , - 1UL ) ;
if ( ! V_104 -> V_55 . V_54 )
return - V_101 ;
V_104 -> V_55 . V_54 -> V_102 = V_104 -> V_15 ;
return 0 ;
}
int F_120 ( struct V_103 * V_104 )
{
V_104 -> V_55 . V_208 = V_209 ;
F_107 ( V_104 ) ;
V_104 -> V_210 -> V_211 = V_212 |
V_213 |
V_214 |
V_215 |
V_216 |
V_217 ;
if ( F_41 ( V_104 -> V_15 , 129 ) )
V_104 -> V_210 -> V_211 |= V_218 ;
if ( F_36 ( V_104 -> V_15 ) )
return F_119 ( V_104 ) ;
return 0 ;
}
void F_121 ( struct V_103 * V_104 , int V_203 )
{
F_122 ( & V_104 -> V_55 . V_219 . V_220 ) ;
if ( F_41 ( V_104 -> V_15 , 129 ) )
F_123 ( ( V_221 * ) & V_104 -> V_55 . V_222 -> V_223 ) ;
else
F_124 ( V_104 -> V_55 . V_219 . V_224 ) ;
F_125 ( V_104 -> V_55 . V_225 ) ;
if ( F_41 ( V_104 -> V_15 , 129 ) ) {
F_126 ( & V_104 -> V_210 -> V_226 . V_227 . V_220 ) ;
F_127 ( ( V_221 * ) & V_104 -> V_210 -> V_226 . V_227 . V_223 ) ;
} else {
F_126 ( & V_104 -> V_55 . V_228 . V_220 ) ;
F_128 ( V_104 -> V_55 . V_228 . V_224 ) ;
}
F_129 ( V_104 -> V_210 -> V_226 . V_227 . V_229 ) ;
F_130 ( V_104 -> V_55 . V_54 ) ;
F_131 ( V_230 , & V_104 -> V_55 . V_122 -> V_231 ) ;
}
void F_132 ( struct V_103 * V_104 )
{
F_133 ( V_230 , & V_104 -> V_55 . V_122 -> V_231 ) ;
F_134 ( V_104 -> V_55 . V_54 ) ;
if ( F_41 ( V_104 -> V_15 , 129 ) ) {
F_122 ( & V_104 -> V_210 -> V_226 . V_227 . V_220 ) ;
F_123 ( ( V_221 * ) & V_104 -> V_210 -> V_226 . V_227 . V_223 ) ;
} else {
F_122 ( & V_104 -> V_55 . V_228 . V_220 ) ;
F_124 ( V_104 -> V_55 . V_228 . V_224 ) ;
}
F_125 ( V_104 -> V_210 -> V_226 . V_227 . V_229 ) ;
F_126 ( & V_104 -> V_55 . V_219 . V_220 ) ;
if ( F_41 ( V_104 -> V_15 , 129 ) )
F_127 ( ( V_221 * ) & V_104 -> V_55 . V_222 -> V_223 ) ;
else
F_128 ( V_104 -> V_55 . V_219 . V_224 ) ;
F_129 ( V_104 -> V_55 . V_225 ) ;
}
static void F_135 ( struct V_103 * V_104 )
{
V_104 -> V_55 . V_122 -> V_232 . V_76 = 0UL ;
V_104 -> V_55 . V_122 -> V_232 . V_86 = 0UL ;
F_136 ( V_104 , 0 ) ;
V_104 -> V_55 . V_122 -> V_233 = 0UL ;
V_104 -> V_55 . V_122 -> V_234 = 0UL ;
V_104 -> V_55 . V_122 -> V_235 = 0 ;
memset ( V_104 -> V_55 . V_122 -> V_236 , 0 , 16 * sizeof( V_205 ) ) ;
V_104 -> V_55 . V_122 -> V_236 [ 0 ] = 0xE0UL ;
V_104 -> V_55 . V_122 -> V_236 [ 14 ] = 0xC2000000UL ;
V_104 -> V_55 . V_228 . V_220 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_104 -> V_55 . V_122 -> V_237 = 1 ;
V_104 -> V_55 . V_122 -> V_238 = 0 ;
V_104 -> V_55 . V_208 = V_209 ;
F_107 ( V_104 ) ;
if ( ! F_137 ( V_104 -> V_15 ) )
F_138 ( V_104 ) ;
F_106 ( V_104 ) ;
}
void F_139 ( struct V_103 * V_104 )
{
F_22 ( & V_104 -> V_15 -> V_92 ) ;
V_104 -> V_55 . V_122 -> V_121 = V_104 -> V_15 -> V_55 . V_121 ;
F_26 ( & V_104 -> V_15 -> V_92 ) ;
if ( ! F_36 ( V_104 -> V_15 ) )
V_104 -> V_55 . V_54 = V_104 -> V_15 -> V_55 . V_54 ;
}
static void F_44 ( struct V_103 * V_104 )
{
if ( ! F_41 ( V_104 -> V_15 , 76 ) )
return;
V_104 -> V_55 . V_122 -> V_239 &= ~ ( V_240 | V_241 ) ;
if ( V_104 -> V_15 -> V_55 . V_107 . V_110 )
V_104 -> V_55 . V_122 -> V_239 |= V_240 ;
if ( V_104 -> V_15 -> V_55 . V_107 . V_113 )
V_104 -> V_55 . V_122 -> V_239 |= V_241 ;
V_104 -> V_55 . V_122 -> V_173 = V_104 -> V_15 -> V_55 . V_107 . V_173 ;
}
void F_111 ( struct V_103 * V_104 )
{
F_101 ( V_104 -> V_55 . V_122 -> V_242 ) ;
V_104 -> V_55 . V_122 -> V_242 = 0 ;
}
int F_140 ( struct V_103 * V_104 )
{
V_104 -> V_55 . V_122 -> V_242 = F_91 ( V_127 ) ;
if ( ! V_104 -> V_55 . V_122 -> V_242 )
return - V_101 ;
V_104 -> V_55 . V_122 -> V_243 |= 0x80 ;
V_104 -> V_55 . V_122 -> V_243 &= ~ 0x08 ;
return 0 ;
}
static void F_141 ( struct V_103 * V_104 )
{
struct V_244 * V_74 = & V_104 -> V_15 -> V_55 . V_74 ;
V_104 -> V_55 . V_128 = V_74 -> V_128 ;
V_104 -> V_55 . V_122 -> V_130 = V_74 -> V_130 ;
V_104 -> V_55 . V_122 -> V_75 = ( int ) ( long ) V_74 -> V_75 -> V_77 ;
}
int F_142 ( struct V_103 * V_104 )
{
int V_179 = 0 ;
F_115 ( & V_104 -> V_55 . V_122 -> V_231 , V_245 |
V_246 |
V_247 |
V_248 ) ;
F_141 ( V_104 ) ;
V_104 -> V_55 . V_122 -> V_249 = 6 ;
if ( F_41 ( V_104 -> V_15 , 50 ) && F_41 ( V_104 -> V_15 , 73 ) )
V_104 -> V_55 . V_122 -> V_249 |= 0x10 ;
V_104 -> V_55 . V_122 -> V_243 = 8 ;
V_104 -> V_55 . V_122 -> V_250 = 0xC1002000U ;
if ( F_143 () )
V_104 -> V_55 . V_122 -> V_250 |= 1 ;
if ( F_144 () )
V_104 -> V_55 . V_122 -> V_250 |= 0x10000000U ;
if ( F_41 ( V_104 -> V_15 , 129 ) ) {
V_104 -> V_55 . V_122 -> V_250 |= 0x00020000 ;
V_104 -> V_55 . V_122 -> V_251 |= 0x20000000 ;
}
V_104 -> V_55 . V_122 -> V_252 |= V_253 | V_254 | V_255 ;
if ( F_110 ( V_104 -> V_15 ) ) {
V_179 = F_140 ( V_104 ) ;
if ( V_179 )
return V_179 ;
}
F_145 ( & V_104 -> V_55 . V_256 , V_257 , V_258 ) ;
V_104 -> V_55 . V_256 . V_259 = V_260 ;
F_44 ( V_104 ) ;
return V_179 ;
}
struct V_103 * F_146 ( struct V_15 * V_15 ,
unsigned int V_261 )
{
struct V_103 * V_104 ;
struct V_262 * V_262 ;
int V_179 = - V_14 ;
if ( V_261 >= V_42 )
goto V_65;
V_179 = - V_101 ;
V_104 = F_147 ( V_206 , V_127 ) ;
if ( ! V_104 )
goto V_65;
V_262 = (struct V_262 * ) F_91 ( V_127 ) ;
if ( ! V_262 )
goto V_263;
V_104 -> V_55 . V_122 = & V_262 -> V_122 ;
V_104 -> V_55 . V_122 -> V_264 = ( unsigned long ) & V_262 -> V_265 ;
V_104 -> V_55 . V_222 = & V_262 -> V_266 ;
V_104 -> V_55 . V_122 -> V_267 = V_261 ;
if ( ! F_36 ( V_15 ) ) {
if ( ! V_15 -> V_55 . V_185 ) {
F_148 ( 1 ) ;
goto V_263;
}
if ( ! V_15 -> V_55 . V_185 -> V_203 [ V_261 ] . V_204 )
V_15 -> V_55 . V_185 -> V_203 [ V_261 ] . V_204 =
( V_205 ) V_104 -> V_55 . V_122 ;
V_104 -> V_55 . V_122 -> V_268 =
( V_174 ) ( ( ( V_205 ) V_15 -> V_55 . V_185 ) >> 32 ) ;
V_104 -> V_55 . V_122 -> V_269 = ( V_174 ) ( V_205 ) V_15 -> V_55 . V_185 ;
F_149 ( 63 - V_261 , ( unsigned long * ) & V_15 -> V_55 . V_185 -> V_202 ) ;
}
F_95 ( & V_104 -> V_55 . V_270 . V_92 ) ;
V_104 -> V_55 . V_270 . V_192 = & V_15 -> V_55 . V_192 ;
V_104 -> V_55 . V_270 . V_271 = & V_104 -> V_271 ;
V_104 -> V_55 . V_270 . V_231 = & V_104 -> V_55 . V_122 -> V_231 ;
V_179 = F_150 ( V_104 , V_15 , V_261 ) ;
if ( V_179 )
goto V_272;
F_100 ( V_15 , 3 , L_6 , V_261 , V_104 ,
V_104 -> V_55 . V_122 ) ;
F_151 ( V_261 , V_104 , V_104 -> V_55 . V_122 ) ;
return V_104 ;
V_272:
F_101 ( ( unsigned long ) ( V_104 -> V_55 . V_122 ) ) ;
V_263:
F_113 ( V_206 , V_104 ) ;
V_65:
return F_152 ( V_179 ) ;
}
int F_153 ( struct V_103 * V_104 )
{
return F_154 ( V_104 , 0 ) ;
}
void F_155 ( struct V_103 * V_104 )
{
F_131 ( V_273 , & V_104 -> V_55 . V_122 -> V_274 ) ;
}
void F_156 ( struct V_103 * V_104 )
{
F_133 ( V_273 , & V_104 -> V_55 . V_122 -> V_274 ) ;
}
void F_45 ( struct V_103 * V_104 )
{
F_131 ( V_275 , & V_104 -> V_55 . V_122 -> V_231 ) ;
while ( V_104 -> V_55 . V_122 -> V_276 & V_277 )
F_157 () ;
}
void F_158 ( struct V_103 * V_104 )
{
F_155 ( V_104 ) ;
F_45 ( V_104 ) ;
}
static void V_5 ( struct V_54 * V_54 , unsigned long V_53 )
{
int V_105 ;
struct V_15 * V_15 = V_54 -> V_102 ;
struct V_103 * V_104 ;
F_43 (i, vcpu, kvm) {
if ( F_159 ( V_104 ) == ( V_53 & ~ 0x1000UL ) ) {
F_104 ( V_104 , 2 , L_7 , V_53 ) ;
F_160 ( V_278 , V_104 ) ;
F_158 ( V_104 ) ;
}
}
}
int F_161 ( struct V_103 * V_104 )
{
F_162 () ;
return 0 ;
}
static int F_163 ( struct V_103 * V_104 ,
struct V_279 * V_280 )
{
int V_17 = - V_14 ;
switch ( V_280 -> V_261 ) {
case V_281 :
V_17 = F_30 ( V_104 -> V_55 . V_122 -> V_235 ,
( T_5 V_85 * ) V_280 -> V_86 ) ;
break;
case V_282 :
V_17 = F_30 ( V_104 -> V_55 . V_122 -> V_121 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_283 :
V_17 = F_30 ( V_104 -> V_55 . V_122 -> V_233 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_284 :
V_17 = F_30 ( V_104 -> V_55 . V_122 -> V_234 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_285 :
V_17 = F_30 ( V_104 -> V_55 . V_208 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_286 :
V_17 = F_30 ( V_104 -> V_55 . V_287 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_288 :
V_17 = F_30 ( V_104 -> V_55 . V_289 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_290 :
V_17 = F_30 ( V_104 -> V_55 . V_122 -> V_238 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_291 :
V_17 = F_30 ( V_104 -> V_55 . V_122 -> V_237 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_164 ( struct V_103 * V_104 ,
struct V_279 * V_280 )
{
int V_17 = - V_14 ;
switch ( V_280 -> V_261 ) {
case V_281 :
V_17 = F_37 ( V_104 -> V_55 . V_122 -> V_235 ,
( T_5 V_85 * ) V_280 -> V_86 ) ;
break;
case V_282 :
V_17 = F_37 ( V_104 -> V_55 . V_122 -> V_121 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_283 :
V_17 = F_37 ( V_104 -> V_55 . V_122 -> V_233 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_284 :
V_17 = F_37 ( V_104 -> V_55 . V_122 -> V_234 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_285 :
V_17 = F_37 ( V_104 -> V_55 . V_208 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
if ( V_104 -> V_55 . V_208 == V_209 )
F_107 ( V_104 ) ;
break;
case V_286 :
V_17 = F_37 ( V_104 -> V_55 . V_287 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_288 :
V_17 = F_37 ( V_104 -> V_55 . V_289 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_290 :
V_17 = F_37 ( V_104 -> V_55 . V_122 -> V_238 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
case V_291 :
V_17 = F_37 ( V_104 -> V_55 . V_122 -> V_237 ,
( V_84 V_85 * ) V_280 -> V_86 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_165 ( struct V_103 * V_104 )
{
F_135 ( V_104 ) ;
return 0 ;
}
int F_166 ( struct V_103 * V_104 , struct V_292 * V_227 )
{
memcpy ( & V_104 -> V_210 -> V_226 . V_227 . V_293 , & V_227 -> V_293 , sizeof( V_227 -> V_293 ) ) ;
return 0 ;
}
int F_167 ( struct V_103 * V_104 , struct V_292 * V_227 )
{
memcpy ( & V_227 -> V_293 , & V_104 -> V_210 -> V_226 . V_227 . V_293 , sizeof( V_227 -> V_293 ) ) ;
return 0 ;
}
int F_168 ( struct V_103 * V_104 ,
struct V_294 * V_295 )
{
memcpy ( & V_104 -> V_210 -> V_226 . V_227 . V_229 , & V_295 -> V_229 , sizeof( V_295 -> V_229 ) ) ;
memcpy ( & V_104 -> V_55 . V_122 -> V_236 , & V_295 -> V_296 , sizeof( V_295 -> V_296 ) ) ;
F_129 ( V_104 -> V_210 -> V_226 . V_227 . V_229 ) ;
return 0 ;
}
int F_169 ( struct V_103 * V_104 ,
struct V_294 * V_295 )
{
memcpy ( & V_295 -> V_229 , & V_104 -> V_210 -> V_226 . V_227 . V_229 , sizeof( V_295 -> V_229 ) ) ;
memcpy ( & V_295 -> V_296 , & V_104 -> V_55 . V_122 -> V_236 , sizeof( V_295 -> V_296 ) ) ;
return 0 ;
}
int F_170 ( struct V_103 * V_104 , struct V_297 * V_298 )
{
if ( F_171 ( V_298 -> V_220 ) )
return - V_14 ;
memcpy ( & V_104 -> V_55 . V_228 . V_224 , & V_298 -> V_224 , sizeof( V_298 -> V_224 ) ) ;
V_104 -> V_55 . V_228 . V_220 = V_298 -> V_220 ;
F_126 ( & V_104 -> V_55 . V_228 . V_220 ) ;
F_128 ( V_104 -> V_55 . V_228 . V_224 ) ;
return 0 ;
}
int F_172 ( struct V_103 * V_104 , struct V_297 * V_298 )
{
memcpy ( & V_298 -> V_224 , & V_104 -> V_55 . V_228 . V_224 , sizeof( V_298 -> V_224 ) ) ;
V_298 -> V_220 = V_104 -> V_55 . V_228 . V_220 ;
return 0 ;
}
static int F_173 ( struct V_103 * V_104 , T_6 V_299 )
{
int V_179 = 0 ;
if ( ! F_174 ( V_104 ) )
V_179 = - V_91 ;
else {
V_104 -> V_210 -> V_300 = V_299 . V_76 ;
V_104 -> V_210 -> V_301 = V_299 . V_86 ;
}
return V_179 ;
}
int F_175 ( struct V_103 * V_104 ,
struct V_302 * V_303 )
{
return - V_14 ;
}
int F_176 ( struct V_103 * V_104 ,
struct V_304 * V_305 )
{
int V_179 = 0 ;
V_104 -> V_306 = 0 ;
F_177 ( V_104 ) ;
if ( V_305 -> V_307 & ~ V_308 )
return - V_14 ;
if ( V_305 -> V_307 & V_309 ) {
V_104 -> V_306 = V_305 -> V_307 ;
F_131 ( V_310 , & V_104 -> V_55 . V_122 -> V_231 ) ;
if ( V_305 -> V_307 & V_311 )
V_179 = F_178 ( V_104 , V_305 ) ;
} else {
F_133 ( V_310 , & V_104 -> V_55 . V_122 -> V_231 ) ;
V_104 -> V_55 . V_312 . V_313 = 0 ;
}
if ( V_179 ) {
V_104 -> V_306 = 0 ;
F_177 ( V_104 ) ;
F_133 ( V_310 , & V_104 -> V_55 . V_122 -> V_231 ) ;
}
return V_179 ;
}
int F_179 ( struct V_103 * V_104 ,
struct V_314 * V_315 )
{
return F_174 ( V_104 ) ? V_316 :
V_317 ;
}
int F_180 ( struct V_103 * V_104 ,
struct V_314 * V_315 )
{
int V_179 = 0 ;
V_104 -> V_15 -> V_55 . V_318 = 1 ;
switch ( V_315 -> V_315 ) {
case V_316 :
F_138 ( V_104 ) ;
break;
case V_317 :
F_181 ( V_104 ) ;
break;
case V_319 :
case V_320 :
default:
V_179 = - V_88 ;
}
return V_179 ;
}
bool F_110 ( struct V_15 * V_15 )
{
if ( ! V_321 )
return false ;
if ( ! V_322 )
return false ;
if ( ! V_15 -> V_55 . V_94 )
return false ;
return true ;
}
static bool F_182 ( struct V_103 * V_104 )
{
return F_32 ( & V_104 -> V_55 . V_122 -> V_231 ) & V_323 ;
}
static int F_183 ( struct V_103 * V_104 )
{
V_324:
F_156 ( V_104 ) ;
if ( F_184 ( V_278 , V_104 ) ) {
int V_179 ;
V_179 = F_185 ( V_104 -> V_55 . V_54 ,
F_159 ( V_104 ) ,
V_325 * 2 ) ;
if ( V_179 )
return V_179 ;
goto V_324;
}
if ( F_184 ( V_326 , V_104 ) ) {
V_104 -> V_55 . V_122 -> V_327 = 0xffff ;
goto V_324;
}
if ( F_184 ( V_328 , V_104 ) ) {
if ( ! F_182 ( V_104 ) ) {
F_186 ( V_104 -> V_201 , 1 ) ;
F_131 ( V_323 ,
& V_104 -> V_55 . V_122 -> V_231 ) ;
}
goto V_324;
}
if ( F_184 ( V_329 , V_104 ) ) {
if ( F_182 ( V_104 ) ) {
F_186 ( V_104 -> V_201 , 0 ) ;
F_133 ( V_323 ,
& V_104 -> V_55 . V_122 -> V_231 ) ;
}
goto V_324;
}
F_108 ( V_330 , & V_104 -> V_331 ) ;
return 0 ;
}
long F_187 ( struct V_103 * V_104 , T_7 V_332 , int V_333 )
{
return F_188 ( V_104 -> V_55 . V_54 , V_332 ,
V_333 ? V_334 : 0 ) ;
}
static void F_189 ( struct V_103 * V_104 , bool V_335 ,
unsigned long V_336 )
{
struct V_158 V_337 ;
struct V_338 V_339 ;
if ( V_335 ) {
V_339 . V_340 . V_16 . V_341 = V_336 ;
V_339 . type = V_342 ;
F_148 ( F_190 ( V_104 , & V_339 ) ) ;
} else {
V_337 . type = V_343 ;
V_337 . V_344 = V_336 ;
F_148 ( F_80 ( V_104 -> V_15 , & V_337 ) ) ;
}
}
void F_191 ( struct V_103 * V_104 ,
struct V_345 * V_346 )
{
F_192 ( V_104 , V_346 -> V_55 . V_208 ) ;
F_189 ( V_104 , true , V_346 -> V_55 . V_208 ) ;
}
void F_193 ( struct V_103 * V_104 ,
struct V_345 * V_346 )
{
F_194 ( V_104 , V_346 -> V_55 . V_208 ) ;
F_189 ( V_104 , false , V_346 -> V_55 . V_208 ) ;
}
void F_195 ( struct V_103 * V_104 ,
struct V_345 * V_346 )
{
}
bool F_196 ( struct V_103 * V_104 )
{
return true ;
}
static int F_197 ( struct V_103 * V_104 )
{
T_8 V_147 ;
struct V_347 V_55 ;
int V_179 ;
if ( V_104 -> V_55 . V_208 == V_209 )
return 0 ;
if ( ( V_104 -> V_55 . V_122 -> V_232 . V_76 & V_104 -> V_55 . V_289 ) !=
V_104 -> V_55 . V_287 )
return 0 ;
if ( F_198 ( V_104 ) )
return 0 ;
if ( F_154 ( V_104 , 0 ) )
return 0 ;
if ( ! ( V_104 -> V_55 . V_122 -> V_236 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_104 -> V_55 . V_54 -> V_198 )
return 0 ;
V_147 = F_71 ( V_104 -> V_15 , F_199 ( V_100 -> V_348 . V_349 ) ) ;
V_147 += V_100 -> V_348 . V_349 & ~ V_350 ;
if ( F_200 ( V_104 , V_104 -> V_55 . V_208 , & V_55 . V_208 , 8 ) )
return 0 ;
V_179 = F_201 ( V_104 , V_100 -> V_348 . V_349 , V_147 , & V_55 ) ;
return V_179 ;
}
static int F_202 ( struct V_103 * V_104 )
{
int V_179 , V_231 ;
F_203 ( V_104 ) ;
memcpy ( & V_104 -> V_55 . V_122 -> V_351 , & V_104 -> V_210 -> V_226 . V_227 . V_293 [ 14 ] , 16 ) ;
if ( F_204 () )
F_205 () ;
if ( F_206 ( V_352 ) )
F_207 () ;
if ( ! F_36 ( V_104 -> V_15 ) ) {
V_179 = F_208 ( V_104 ) ;
if ( V_179 )
return V_179 ;
}
V_179 = F_183 ( V_104 ) ;
if ( V_179 )
return V_179 ;
if ( F_209 ( V_104 ) ) {
F_210 ( V_104 ) ;
F_211 ( V_104 ) ;
}
V_104 -> V_55 . V_122 -> V_353 = 0 ;
V_231 = F_32 ( & V_104 -> V_55 . V_122 -> V_231 ) ;
F_104 ( V_104 , 6 , L_8 , V_231 ) ;
F_212 ( V_104 , V_231 ) ;
return 0 ;
}
static int F_213 ( struct V_103 * V_104 )
{
T_6 * V_299 = & V_104 -> V_55 . V_122 -> V_232 ;
T_2 V_354 ;
int V_179 ;
F_104 ( V_104 , 3 , L_3 , L_9 ) ;
F_214 ( V_104 ) ;
V_179 = F_215 ( V_104 , V_299 -> V_86 , 0 , & V_354 , 1 ) ;
if ( V_179 )
return F_216 ( V_104 , V_179 ) ;
V_299 -> V_86 = F_217 ( * V_299 , - F_218 ( V_354 ) ) ;
return F_219 ( V_104 , V_355 ) ;
}
static int F_220 ( struct V_103 * V_104 , int V_356 )
{
int V_179 = - 1 ;
F_104 ( V_104 , 6 , L_10 ,
V_104 -> V_55 . V_122 -> V_353 ) ;
F_221 ( V_104 , V_104 -> V_55 . V_122 -> V_353 ) ;
if ( F_209 ( V_104 ) )
F_222 ( V_104 ) ;
if ( V_356 >= 0 ) {
V_179 = 0 ;
} else if ( F_36 ( V_104 -> V_15 ) ) {
V_104 -> V_210 -> V_356 = V_357 ;
V_104 -> V_210 -> V_358 . V_359 =
V_100 -> V_348 . V_349 ;
V_104 -> V_210 -> V_358 . V_360 = 0x10 ;
V_179 = - V_361 ;
} else if ( V_100 -> V_348 . V_362 ) {
F_223 ( V_104 ) ;
V_100 -> V_348 . V_362 = 0 ;
if ( F_197 ( V_104 ) ) {
V_179 = 0 ;
} else {
T_7 V_332 = V_100 -> V_348 . V_349 ;
V_179 = F_187 ( V_104 , V_332 , 1 ) ;
}
}
if ( V_179 == - 1 )
V_179 = F_213 ( V_104 ) ;
memcpy ( & V_104 -> V_210 -> V_226 . V_227 . V_293 [ 14 ] , & V_104 -> V_55 . V_122 -> V_351 , 16 ) ;
if ( V_179 == 0 ) {
if ( F_36 ( V_104 -> V_15 ) )
V_179 = V_104 -> V_55 . V_122 -> V_353 ? - V_363 : 0 ;
else
V_179 = F_224 ( V_104 ) ;
}
return V_179 ;
}
static int F_225 ( struct V_103 * V_104 )
{
int V_179 , V_356 ;
V_104 -> V_364 = F_33 ( & V_104 -> V_15 -> V_96 ) ;
do {
V_179 = F_202 ( V_104 ) ;
if ( V_179 )
break;
F_35 ( & V_104 -> V_15 -> V_96 , V_104 -> V_364 ) ;
F_226 () ;
F_227 () ;
F_228 () ;
V_356 = F_229 ( V_104 -> V_55 . V_122 ,
V_104 -> V_210 -> V_226 . V_227 . V_293 ) ;
F_230 () ;
V_104 -> V_364 = F_33 ( & V_104 -> V_15 -> V_96 ) ;
V_179 = F_220 ( V_104 , V_356 ) ;
} while ( ! F_231 ( V_100 ) && ! F_232 ( V_104 ) && ! V_179 );
F_35 ( & V_104 -> V_15 -> V_96 , V_104 -> V_364 ) ;
return V_179 ;
}
static void F_233 ( struct V_103 * V_104 , struct V_365 * V_365 )
{
V_104 -> V_55 . V_122 -> V_232 . V_76 = V_365 -> V_300 ;
V_104 -> V_55 . V_122 -> V_232 . V_86 = V_365 -> V_301 ;
if ( V_365 -> V_366 & V_212 )
F_136 ( V_104 , V_365 -> V_226 . V_227 . V_367 ) ;
if ( V_365 -> V_366 & V_215 ) {
memcpy ( & V_104 -> V_55 . V_122 -> V_236 , & V_365 -> V_226 . V_227 . V_296 , 128 ) ;
F_160 ( V_326 , V_104 ) ;
}
if ( V_365 -> V_366 & V_216 ) {
V_104 -> V_55 . V_122 -> V_233 = V_365 -> V_226 . V_227 . V_233 ;
V_104 -> V_55 . V_122 -> V_234 = V_365 -> V_226 . V_227 . V_234 ;
V_104 -> V_55 . V_122 -> V_235 = V_365 -> V_226 . V_227 . V_235 ;
V_104 -> V_55 . V_122 -> V_238 = V_365 -> V_226 . V_227 . V_238 ;
V_104 -> V_55 . V_122 -> V_237 = V_365 -> V_226 . V_227 . V_237 ;
}
if ( V_365 -> V_366 & V_217 ) {
V_104 -> V_55 . V_208 = V_365 -> V_226 . V_227 . V_368 ;
V_104 -> V_55 . V_289 = V_365 -> V_226 . V_227 . V_369 ;
V_104 -> V_55 . V_287 = V_365 -> V_226 . V_227 . V_370 ;
if ( V_104 -> V_55 . V_208 == V_209 )
F_107 ( V_104 ) ;
}
V_365 -> V_366 = 0 ;
}
static void F_234 ( struct V_103 * V_104 , struct V_365 * V_365 )
{
V_365 -> V_300 = V_104 -> V_55 . V_122 -> V_232 . V_76 ;
V_365 -> V_301 = V_104 -> V_55 . V_122 -> V_232 . V_86 ;
V_365 -> V_226 . V_227 . V_367 = F_159 ( V_104 ) ;
memcpy ( & V_365 -> V_226 . V_227 . V_296 , & V_104 -> V_55 . V_122 -> V_236 , 128 ) ;
V_365 -> V_226 . V_227 . V_233 = V_104 -> V_55 . V_122 -> V_233 ;
V_365 -> V_226 . V_227 . V_234 = V_104 -> V_55 . V_122 -> V_234 ;
V_365 -> V_226 . V_227 . V_235 = V_104 -> V_55 . V_122 -> V_235 ;
V_365 -> V_226 . V_227 . V_238 = V_104 -> V_55 . V_122 -> V_238 ;
V_365 -> V_226 . V_227 . V_237 = V_104 -> V_55 . V_122 -> V_237 ;
V_365 -> V_226 . V_227 . V_368 = V_104 -> V_55 . V_208 ;
V_365 -> V_226 . V_227 . V_369 = V_104 -> V_55 . V_289 ;
V_365 -> V_226 . V_227 . V_370 = V_104 -> V_55 . V_287 ;
}
int F_235 ( struct V_103 * V_104 , struct V_365 * V_365 )
{
int V_179 ;
T_9 V_371 ;
if ( F_232 ( V_104 ) ) {
F_236 ( V_104 ) ;
return 0 ;
}
if ( V_104 -> V_372 )
F_237 ( V_373 , & V_104 -> V_374 , & V_371 ) ;
if ( ! F_137 ( V_104 -> V_15 ) ) {
F_181 ( V_104 ) ;
} else if ( F_174 ( V_104 ) ) {
F_238 ( L_11 ,
V_104 -> V_201 ) ;
return - V_14 ;
}
F_233 ( V_104 , V_365 ) ;
F_239 () ;
V_179 = F_225 ( V_104 ) ;
if ( F_231 ( V_100 ) && ! V_179 ) {
V_365 -> V_356 = V_375 ;
V_179 = - V_376 ;
}
if ( F_232 ( V_104 ) && ! V_179 ) {
F_236 ( V_104 ) ;
V_179 = 0 ;
}
if ( V_179 == - V_363 ) {
V_365 -> V_356 = V_377 ;
V_365 -> V_378 . V_353 = V_104 -> V_55 . V_122 -> V_353 ;
V_365 -> V_378 . V_379 = V_104 -> V_55 . V_122 -> V_379 ;
V_365 -> V_378 . V_380 = V_104 -> V_55 . V_122 -> V_380 ;
V_179 = 0 ;
}
if ( V_179 == - V_361 ) {
V_179 = 0 ;
}
F_234 ( V_104 , V_365 ) ;
if ( V_104 -> V_372 )
F_237 ( V_373 , & V_371 , NULL ) ;
V_104 -> V_381 . V_382 ++ ;
return V_179 ;
}
int F_240 ( struct V_103 * V_104 , unsigned long V_332 )
{
unsigned char V_383 = 1 ;
unsigned int V_384 ;
V_84 V_385 ;
int V_179 ;
if ( V_332 == V_386 ) {
if ( F_241 ( V_104 , 163 , & V_383 , 1 ) )
return - V_87 ;
V_332 = V_387 ;
} else if ( V_332 == V_388 ) {
if ( F_242 ( V_104 , 163 , & V_383 , 1 ) )
return - V_87 ;
V_332 = F_243 ( V_104 , V_387 ) ;
}
V_179 = F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_390 ) ,
V_104 -> V_55 . V_228 . V_224 , 128 ) ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_391 ) ,
V_104 -> V_210 -> V_226 . V_227 . V_293 , 128 ) ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_299 ) ,
& V_104 -> V_55 . V_122 -> V_232 , 16 ) ;
V_384 = F_159 ( V_104 ) ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_392 ) ,
& V_384 , 4 ) ;
V_179 |= F_241 ( V_104 ,
V_332 + F_244 ( struct V_389 , V_393 ) ,
& V_104 -> V_55 . V_228 . V_220 , 4 ) ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_394 ) ,
& V_104 -> V_55 . V_122 -> V_235 , 4 ) ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_395 ) ,
& V_104 -> V_55 . V_122 -> V_233 , 8 ) ;
V_385 = V_104 -> V_55 . V_122 -> V_234 >> 8 ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_396 ) ,
& V_385 , 8 ) ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_397 ) ,
& V_104 -> V_210 -> V_226 . V_227 . V_229 , 64 ) ;
V_179 |= F_241 ( V_104 , V_332 + F_244 ( struct V_389 , V_398 ) ,
& V_104 -> V_55 . V_122 -> V_236 , 128 ) ;
return V_179 ? - V_87 : 0 ;
}
int F_245 ( struct V_103 * V_104 , unsigned long V_86 )
{
F_122 ( & V_104 -> V_55 . V_228 . V_220 ) ;
F_124 ( V_104 -> V_55 . V_228 . V_224 ) ;
F_125 ( V_104 -> V_210 -> V_226 . V_227 . V_229 ) ;
return F_240 ( V_104 , V_86 ) ;
}
int F_246 ( struct V_103 * V_104 ,
unsigned long V_332 )
{
if ( ! ( V_332 & ~ 0x3ff ) )
return 0 ;
return F_241 ( V_104 , V_332 & ~ 0x3ff ,
( void * ) & V_104 -> V_210 -> V_226 . V_227 . V_223 , 512 ) ;
}
int F_247 ( struct V_103 * V_104 , unsigned long V_86 )
{
if ( ! F_41 ( V_104 -> V_15 , 129 ) )
return 0 ;
F_123 ( ( V_221 * ) & V_104 -> V_210 -> V_226 . V_227 . V_223 ) ;
return F_246 ( V_104 , V_86 ) ;
}
static void F_248 ( struct V_103 * V_104 )
{
F_184 ( V_328 , V_104 ) ;
F_160 ( V_329 , V_104 ) ;
F_158 ( V_104 ) ;
}
static void F_249 ( struct V_15 * V_15 )
{
unsigned int V_105 ;
struct V_103 * V_104 ;
F_43 (i, vcpu, kvm) {
F_248 ( V_104 ) ;
}
}
static void F_250 ( struct V_103 * V_104 )
{
F_184 ( V_329 , V_104 ) ;
F_160 ( V_328 , V_104 ) ;
F_158 ( V_104 ) ;
}
void F_181 ( struct V_103 * V_104 )
{
int V_105 , V_93 , V_399 = 0 ;
if ( ! F_174 ( V_104 ) )
return;
F_251 ( V_104 -> V_201 , 1 ) ;
F_92 ( & V_104 -> V_15 -> V_55 . V_200 ) ;
V_93 = F_32 ( & V_104 -> V_15 -> V_93 ) ;
for ( V_105 = 0 ; V_105 < V_93 ; V_105 ++ ) {
if ( ! F_174 ( V_104 -> V_15 -> V_207 [ V_105 ] ) )
V_399 ++ ;
}
if ( V_399 == 0 ) {
F_250 ( V_104 ) ;
} else if ( V_399 == 1 ) {
F_249 ( V_104 -> V_15 ) ;
}
F_133 ( V_247 , & V_104 -> V_55 . V_122 -> V_231 ) ;
F_160 ( V_326 , V_104 ) ;
F_93 ( & V_104 -> V_15 -> V_55 . V_200 ) ;
return;
}
void F_138 ( struct V_103 * V_104 )
{
int V_105 , V_93 , V_399 = 0 ;
struct V_103 * V_400 = NULL ;
if ( F_174 ( V_104 ) )
return;
F_251 ( V_104 -> V_201 , 0 ) ;
F_92 ( & V_104 -> V_15 -> V_55 . V_200 ) ;
V_93 = F_32 ( & V_104 -> V_15 -> V_93 ) ;
F_252 ( V_104 ) ;
F_131 ( V_247 , & V_104 -> V_55 . V_122 -> V_231 ) ;
F_248 ( V_104 ) ;
for ( V_105 = 0 ; V_105 < V_93 ; V_105 ++ ) {
if ( ! F_174 ( V_104 -> V_15 -> V_207 [ V_105 ] ) ) {
V_399 ++ ;
V_400 = V_104 -> V_15 -> V_207 [ V_105 ] ;
}
}
if ( V_399 == 1 ) {
F_250 ( V_400 ) ;
}
F_93 ( & V_104 -> V_15 -> V_55 . V_200 ) ;
return;
}
static int F_253 ( struct V_103 * V_104 ,
struct V_69 * V_70 )
{
int V_17 ;
if ( V_70 -> V_71 )
return - V_14 ;
switch ( V_70 -> V_70 ) {
case V_26 :
if ( ! V_104 -> V_15 -> V_55 . V_199 ) {
V_104 -> V_15 -> V_55 . V_199 = 1 ;
F_254 ( V_104 -> V_15 ) ;
}
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
static long F_255 ( struct V_103 * V_104 ,
struct V_401 * V_402 )
{
void V_85 * V_403 = ( void V_85 * ) V_402 -> V_404 ;
void * V_405 = NULL ;
int V_17 , V_364 ;
const V_84 V_406 = V_407
| V_408 ;
if ( V_402 -> V_71 & ~ V_406 )
return - V_14 ;
if ( V_402 -> V_409 > V_39 )
return - V_98 ;
if ( ! ( V_402 -> V_71 & V_408 ) ) {
V_405 = F_70 ( V_402 -> V_409 ) ;
if ( ! V_405 )
return - V_101 ;
}
V_364 = F_33 ( & V_104 -> V_15 -> V_96 ) ;
switch ( V_402 -> V_410 ) {
case V_411 :
if ( V_402 -> V_71 & V_408 ) {
V_17 = F_256 ( V_104 , V_402 -> V_412 , V_402 -> V_413 , V_402 -> V_409 , false ) ;
break;
}
V_17 = F_215 ( V_104 , V_402 -> V_412 , V_402 -> V_413 , V_405 , V_402 -> V_409 ) ;
if ( V_17 == 0 ) {
if ( F_52 ( V_403 , V_405 , V_402 -> V_409 ) )
V_17 = - V_87 ;
}
break;
case V_414 :
if ( V_402 -> V_71 & V_408 ) {
V_17 = F_256 ( V_104 , V_402 -> V_412 , V_402 -> V_413 , V_402 -> V_409 , true ) ;
break;
}
if ( F_47 ( V_405 , V_403 , V_402 -> V_409 ) ) {
V_17 = - V_87 ;
break;
}
V_17 = F_257 ( V_104 , V_402 -> V_412 , V_402 -> V_413 , V_405 , V_402 -> V_409 ) ;
break;
default:
V_17 = - V_14 ;
}
F_35 ( & V_104 -> V_15 -> V_96 , V_364 ) ;
if ( V_17 > 0 && ( V_402 -> V_71 & V_407 ) != 0 )
F_258 ( V_104 , & V_104 -> V_55 . V_415 ) ;
F_259 ( V_405 ) ;
return V_17 ;
}
long F_260 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_103 * V_104 = V_10 -> V_155 ;
void V_85 * V_156 = ( void V_85 * ) V_12 ;
int V_89 ;
long V_17 ;
switch ( V_11 ) {
case V_416 : {
struct V_338 V_417 ;
V_17 = - V_87 ;
if ( F_47 ( & V_417 , V_156 , sizeof( V_417 ) ) )
break;
V_17 = F_190 ( V_104 , & V_417 ) ;
break;
}
case V_157 : {
struct V_158 V_159 ;
struct V_338 V_417 ;
V_17 = - V_87 ;
if ( F_47 ( & V_159 , V_156 , sizeof( V_159 ) ) )
break;
if ( F_261 ( & V_159 , & V_417 ) )
return - V_14 ;
V_17 = F_190 ( V_104 , & V_417 ) ;
break;
}
case V_418 :
V_89 = F_33 ( & V_104 -> V_15 -> V_96 ) ;
V_17 = F_245 ( V_104 , V_12 ) ;
F_35 ( & V_104 -> V_15 -> V_96 , V_89 ) ;
break;
case V_419 : {
T_6 V_299 ;
V_17 = - V_87 ;
if ( F_47 ( & V_299 , V_156 , sizeof( V_299 ) ) )
break;
V_17 = F_173 ( V_104 , V_299 ) ;
break;
}
case V_420 :
V_17 = F_165 ( V_104 ) ;
break;
case V_421 :
case V_422 : {
struct V_279 V_280 ;
V_17 = - V_87 ;
if ( F_47 ( & V_280 , V_156 , sizeof( V_280 ) ) )
break;
if ( V_11 == V_421 )
V_17 = F_164 ( V_104 , & V_280 ) ;
else
V_17 = F_163 ( V_104 , & V_280 ) ;
break;
}
#ifdef F_14
case V_423 : {
struct V_424 V_425 ;
if ( F_47 ( & V_425 , V_156 , sizeof( V_425 ) ) ) {
V_17 = - V_87 ;
break;
}
if ( ! F_36 ( V_104 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_262 ( V_104 -> V_55 . V_54 , V_425 . V_426 ,
V_425 . V_427 , V_425 . V_428 ) ;
break;
}
case V_429 : {
struct V_424 V_425 ;
if ( F_47 ( & V_425 , V_156 , sizeof( V_425 ) ) ) {
V_17 = - V_87 ;
break;
}
if ( ! F_36 ( V_104 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_263 ( V_104 -> V_55 . V_54 , V_425 . V_427 ,
V_425 . V_428 ) ;
break;
}
#endif
case V_430 : {
V_17 = F_188 ( V_104 -> V_55 . V_54 , V_12 , 0 ) ;
break;
}
case V_160 :
{
struct V_69 V_70 ;
V_17 = - V_87 ;
if ( F_47 ( & V_70 , V_156 , sizeof( V_70 ) ) )
break;
V_17 = F_253 ( V_104 , & V_70 ) ;
break;
}
case V_431 : {
struct V_401 V_432 ;
if ( F_47 ( & V_432 , V_156 , sizeof( V_432 ) ) == 0 )
V_17 = F_255 ( V_104 , & V_432 ) ;
else
V_17 = - V_87 ;
break;
}
case V_433 : {
struct V_434 V_435 ;
V_17 = - V_87 ;
if ( F_47 ( & V_435 , V_156 , sizeof( V_435 ) ) )
break;
if ( V_435 . V_436 > V_437 ||
V_435 . V_436 == 0 ||
V_435 . V_436 % sizeof( struct V_338 ) > 0 ) {
V_17 = - V_14 ;
break;
}
V_17 = F_264 ( V_104 ,
( void V_85 * ) V_435 . V_404 ,
V_435 . V_436 ) ;
break;
}
case V_438 : {
struct V_434 V_435 ;
V_17 = - V_87 ;
if ( F_47 ( & V_435 , V_156 , sizeof( V_435 ) ) )
break;
if ( V_435 . V_436 == 0 ) {
V_17 = - V_14 ;
break;
}
V_17 = F_265 ( V_104 ,
( V_439 V_85 * ) V_435 . V_404 ,
V_435 . V_436 ) ;
break;
}
default:
V_17 = - V_169 ;
}
return V_17 ;
}
int F_266 ( struct V_103 * V_104 , struct V_440 * V_441 )
{
#ifdef F_14
if ( ( V_441 -> V_442 == V_443 )
&& ( F_36 ( V_104 -> V_15 ) ) ) {
V_441 -> V_444 = F_267 ( V_104 -> V_55 . V_122 ) ;
F_268 ( V_441 -> V_444 ) ;
return 0 ;
}
#endif
return V_445 ;
}
int F_269 ( struct V_15 * V_15 , struct V_49 * V_64 ,
unsigned long V_59 )
{
return 0 ;
}
int F_270 ( struct V_15 * V_15 ,
struct V_49 * V_50 ,
struct V_446 * V_447 ,
enum V_448 V_449 )
{
if ( V_447 -> V_450 & 0xffffful )
return - V_14 ;
if ( V_447 -> V_451 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_271 ( struct V_15 * V_15 ,
struct V_446 * V_447 ,
const struct V_49 * V_452 ,
enum V_448 V_449 )
{
int V_179 ;
if ( V_452 -> V_450 == V_447 -> V_450 &&
V_452 -> V_58 * V_325 == V_447 -> V_453 &&
V_452 -> V_59 * V_325 == V_447 -> V_451 )
return;
V_179 = F_262 ( V_15 -> V_55 . V_54 , V_447 -> V_450 ,
V_447 -> V_453 , V_447 -> V_451 ) ;
if ( V_179 )
F_272 ( V_454 L_12 ) ;
return;
}
static int T_10 F_273 ( void )
{
return F_274 ( NULL , sizeof( struct V_103 ) , 0 , V_455 ) ;
}
static void T_11 F_275 ( void )
{
F_276 () ;
}
