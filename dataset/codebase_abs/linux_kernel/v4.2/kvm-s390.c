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
struct V_62 * V_63 ;
struct V_49 * V_50 ;
int V_64 = 0 ;
F_22 ( & V_15 -> V_65 ) ;
V_17 = - V_14 ;
if ( log -> V_66 >= V_44 )
goto V_67;
V_63 = V_62 ( V_15 ) ;
V_50 = F_23 ( V_63 , log -> V_66 ) ;
V_17 = - V_68 ;
if ( ! V_50 -> V_69 )
goto V_67;
F_15 ( V_15 , V_50 ) ;
V_17 = F_24 ( V_15 , log , & V_64 ) ;
if ( V_17 )
goto V_67;
if ( V_64 ) {
V_61 = F_25 ( V_50 ) ;
memset ( V_50 -> V_69 , 0 , V_61 ) ;
}
V_17 = 0 ;
V_67:
F_26 ( & V_15 -> V_65 ) ;
return V_17 ;
}
static int F_27 ( struct V_15 * V_15 , struct V_70 * V_71 )
{
int V_17 ;
if ( V_71 -> V_72 )
return - V_14 ;
switch ( V_71 -> V_71 ) {
case V_30 :
V_15 -> V_55 . V_73 = 1 ;
V_17 = 0 ;
break;
case V_34 :
V_15 -> V_55 . V_74 = 1 ;
V_17 = 0 ;
break;
case V_47 :
if ( V_48 ) {
F_28 ( V_15 -> V_55 . V_75 . V_76 -> V_77 , 129 ) ;
F_28 ( V_15 -> V_55 . V_75 . V_76 -> V_78 , 129 ) ;
V_17 = 0 ;
} else
V_17 = - V_14 ;
break;
case V_35 :
V_15 -> V_55 . V_79 = 1 ;
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
static int F_29 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 ;
switch ( V_81 -> V_81 ) {
case V_83 :
V_82 = 0 ;
if ( F_30 ( V_15 -> V_55 . V_54 -> V_84 , ( V_85 V_86 * ) V_81 -> V_87 ) )
V_82 = - V_88 ;
break;
default:
V_82 = - V_89 ;
break;
}
return V_82 ;
}
static int F_31 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 ;
unsigned int V_90 ;
switch ( V_81 -> V_81 ) {
case V_91 :
V_82 = - V_92 ;
F_22 ( & V_15 -> V_93 ) ;
if ( F_32 ( & V_15 -> V_94 ) == 0 ) {
V_15 -> V_55 . V_95 = 1 ;
V_82 = 0 ;
}
F_26 ( & V_15 -> V_93 ) ;
break;
case V_96 :
F_22 ( & V_15 -> V_93 ) ;
V_90 = F_33 ( & V_15 -> V_97 ) ;
F_34 ( V_15 -> V_55 . V_54 -> V_56 ) ;
F_35 ( & V_15 -> V_97 , V_90 ) ;
F_26 ( & V_15 -> V_93 ) ;
V_82 = 0 ;
break;
case V_83 : {
unsigned long V_98 ;
if ( F_36 ( V_15 ) )
return - V_14 ;
if ( F_37 ( V_98 , ( V_85 V_86 * ) V_81 -> V_87 ) )
return - V_88 ;
if ( V_98 > V_15 -> V_55 . V_54 -> V_84 )
return - V_99 ;
V_82 = - V_92 ;
F_22 ( & V_15 -> V_93 ) ;
if ( F_32 ( & V_15 -> V_94 ) == 0 ) {
struct V_54 * V_100 = F_38 ( V_101 -> V_56 , V_98 ) ;
if ( ! V_100 ) {
V_82 = - V_102 ;
} else {
F_39 ( V_15 -> V_55 . V_54 ) ;
V_100 -> V_103 = V_15 ;
V_15 -> V_55 . V_54 = V_100 ;
V_82 = 0 ;
}
}
F_26 ( & V_15 -> V_93 ) ;
break;
}
default:
V_82 = - V_89 ;
break;
}
return V_82 ;
}
static int F_40 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
struct V_104 * V_105 ;
int V_106 ;
if ( ! F_41 ( V_15 , 76 ) )
return - V_14 ;
F_22 ( & V_15 -> V_93 ) ;
switch ( V_81 -> V_81 ) {
case V_107 :
F_42 (
V_15 -> V_55 . V_108 . V_109 -> V_110 ,
sizeof( V_15 -> V_55 . V_108 . V_109 -> V_110 ) ) ;
V_15 -> V_55 . V_108 . V_111 = 1 ;
break;
case V_112 :
F_42 (
V_15 -> V_55 . V_108 . V_109 -> V_113 ,
sizeof( V_15 -> V_55 . V_108 . V_109 -> V_113 ) ) ;
V_15 -> V_55 . V_108 . V_114 = 1 ;
break;
case V_115 :
V_15 -> V_55 . V_108 . V_111 = 0 ;
memset ( V_15 -> V_55 . V_108 . V_109 -> V_110 , 0 ,
sizeof( V_15 -> V_55 . V_108 . V_109 -> V_110 ) ) ;
break;
case V_116 :
V_15 -> V_55 . V_108 . V_114 = 0 ;
memset ( V_15 -> V_55 . V_108 . V_109 -> V_113 , 0 ,
sizeof( V_15 -> V_55 . V_108 . V_109 -> V_113 ) ) ;
break;
default:
F_26 ( & V_15 -> V_93 ) ;
return - V_89 ;
}
F_43 (i, vcpu, kvm) {
F_44 ( V_105 ) ;
F_45 ( V_105 ) ;
}
F_26 ( & V_15 -> V_93 ) ;
return 0 ;
}
static int F_46 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
T_2 V_117 ;
if ( F_47 ( & V_117 , ( void V_86 * ) V_81 -> V_87 ,
sizeof( V_117 ) ) )
return - V_88 ;
if ( V_117 != 0 )
return - V_14 ;
return 0 ;
}
static int F_48 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
struct V_104 * V_118 ;
unsigned int V_119 ;
V_85 V_120 , V_121 ;
int V_17 ;
if ( F_47 ( & V_121 , ( void V_86 * ) V_81 -> V_87 , sizeof( V_121 ) ) )
return - V_88 ;
V_17 = F_49 ( & V_120 ) ;
if ( V_17 )
return V_17 ;
F_22 ( & V_15 -> V_93 ) ;
V_15 -> V_55 . V_122 = V_121 - V_120 ;
F_50 ( V_15 ) ;
F_43 (vcpu_idx, cur_vcpu, kvm)
V_118 -> V_55 . V_123 -> V_122 = V_15 -> V_55 . V_122 ;
F_51 ( V_15 ) ;
F_26 ( & V_15 -> V_93 ) ;
return 0 ;
}
static int F_52 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 ;
if ( V_81 -> V_72 )
return - V_14 ;
switch ( V_81 -> V_81 ) {
case V_124 :
V_82 = F_46 ( V_15 , V_81 ) ;
break;
case V_125 :
V_82 = F_48 ( V_15 , V_81 ) ;
break;
default:
V_82 = - V_89 ;
break;
}
return V_82 ;
}
static int F_53 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
T_2 V_117 = 0 ;
if ( F_54 ( ( void V_86 * ) V_81 -> V_87 , & V_117 ,
sizeof( V_117 ) ) )
return - V_88 ;
return 0 ;
}
static int F_55 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
V_85 V_120 , V_121 ;
int V_17 ;
V_17 = F_49 ( & V_120 ) ;
if ( V_17 )
return V_17 ;
V_121 = V_120 + V_15 -> V_55 . V_122 ;
if ( F_54 ( ( void V_86 * ) V_81 -> V_87 , & V_121 , sizeof( V_121 ) ) )
return - V_88 ;
return 0 ;
}
static int F_56 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 ;
if ( V_81 -> V_72 )
return - V_14 ;
switch ( V_81 -> V_81 ) {
case V_124 :
V_82 = F_53 ( V_15 , V_81 ) ;
break;
case V_125 :
V_82 = F_55 ( V_15 , V_81 ) ;
break;
default:
V_82 = - V_89 ;
break;
}
return V_82 ;
}
static int F_57 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
struct V_126 * V_127 ;
int V_82 = 0 ;
F_22 ( & V_15 -> V_93 ) ;
if ( F_32 ( & V_15 -> V_94 ) ) {
V_82 = - V_92 ;
goto V_67;
}
V_127 = F_58 ( sizeof( * V_127 ) , V_128 ) ;
if ( ! V_127 ) {
V_82 = - V_102 ;
goto V_67;
}
if ( ! F_47 ( V_127 , ( void V_86 * ) V_81 -> V_87 ,
sizeof( * V_127 ) ) ) {
memcpy ( & V_15 -> V_55 . V_75 . V_129 , & V_127 -> V_130 ,
sizeof( struct V_130 ) ) ;
V_15 -> V_55 . V_75 . V_131 = V_127 -> V_131 ;
memcpy ( V_15 -> V_55 . V_75 . V_76 -> V_78 , V_127 -> V_132 ,
V_133 ) ;
} else
V_82 = - V_88 ;
F_59 ( V_127 ) ;
V_67:
F_26 ( & V_15 -> V_93 ) ;
return V_82 ;
}
static int F_60 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 = - V_89 ;
switch ( V_81 -> V_81 ) {
case V_134 :
V_82 = F_57 ( V_15 , V_81 ) ;
break;
}
return V_82 ;
}
static int F_61 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
struct V_126 * V_127 ;
int V_82 = 0 ;
V_127 = F_58 ( sizeof( * V_127 ) , V_128 ) ;
if ( ! V_127 ) {
V_82 = - V_102 ;
goto V_67;
}
memcpy ( & V_127 -> V_130 , & V_15 -> V_55 . V_75 . V_129 , sizeof( struct V_130 ) ) ;
V_127 -> V_131 = V_15 -> V_55 . V_75 . V_131 ;
memcpy ( & V_127 -> V_132 , V_15 -> V_55 . V_75 . V_76 -> V_78 , V_133 ) ;
if ( F_54 ( ( void V_86 * ) V_81 -> V_87 , V_127 , sizeof( * V_127 ) ) )
V_82 = - V_88 ;
F_59 ( V_127 ) ;
V_67:
return V_82 ;
}
static int F_62 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
struct V_135 * V_136 ;
int V_82 = 0 ;
V_136 = F_58 ( sizeof( * V_136 ) , V_128 ) ;
if ( ! V_136 ) {
V_82 = - V_102 ;
goto V_67;
}
F_63 ( (struct V_130 * ) & V_136 -> V_130 ) ;
V_136 -> V_131 = V_137 . V_131 ;
memcpy ( & V_136 -> V_138 , V_15 -> V_55 . V_75 . V_76 -> V_77 ,
V_133 ) ;
memcpy ( ( unsigned long * ) & V_136 -> V_132 , V_139 . V_140 ,
V_133 ) ;
if ( F_54 ( ( void V_86 * ) V_81 -> V_87 , V_136 , sizeof( * V_136 ) ) )
V_82 = - V_88 ;
F_59 ( V_136 ) ;
V_67:
return V_82 ;
}
static int F_64 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 = - V_89 ;
switch ( V_81 -> V_81 ) {
case V_134 :
V_82 = F_61 ( V_15 , V_81 ) ;
break;
case V_141 :
V_82 = F_62 ( V_15 , V_81 ) ;
break;
}
return V_82 ;
}
static int F_65 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 ;
switch ( V_81 -> V_142 ) {
case V_143 :
V_82 = F_31 ( V_15 , V_81 ) ;
break;
case V_144 :
V_82 = F_52 ( V_15 , V_81 ) ;
break;
case V_145 :
V_82 = F_60 ( V_15 , V_81 ) ;
break;
case V_146 :
V_82 = F_40 ( V_15 , V_81 ) ;
break;
default:
V_82 = - V_89 ;
break;
}
return V_82 ;
}
static int F_66 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 ;
switch ( V_81 -> V_142 ) {
case V_143 :
V_82 = F_29 ( V_15 , V_81 ) ;
break;
case V_144 :
V_82 = F_56 ( V_15 , V_81 ) ;
break;
case V_145 :
V_82 = F_64 ( V_15 , V_81 ) ;
break;
default:
V_82 = - V_89 ;
break;
}
return V_82 ;
}
static int F_67 ( struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_82 ;
switch ( V_81 -> V_142 ) {
case V_143 :
switch ( V_81 -> V_81 ) {
case V_91 :
case V_96 :
case V_83 :
V_82 = 0 ;
break;
default:
V_82 = - V_89 ;
break;
}
break;
case V_144 :
switch ( V_81 -> V_81 ) {
case V_125 :
case V_124 :
V_82 = 0 ;
break;
default:
V_82 = - V_89 ;
break;
}
break;
case V_145 :
switch ( V_81 -> V_81 ) {
case V_134 :
case V_141 :
V_82 = 0 ;
break;
default:
V_82 = - V_89 ;
break;
}
break;
case V_146 :
switch ( V_81 -> V_81 ) {
case V_107 :
case V_112 :
case V_115 :
case V_116 :
V_82 = 0 ;
break;
default:
V_82 = - V_89 ;
break;
}
break;
default:
V_82 = - V_89 ;
break;
}
return V_82 ;
}
static long F_68 ( struct V_15 * V_15 , struct V_147 * args )
{
T_3 * V_148 ;
T_4 V_149 ;
unsigned long V_150 ;
int V_106 , V_17 = 0 ;
if ( args -> V_72 != 0 )
return - V_14 ;
if ( ! F_69 ( V_101 -> V_56 ) )
return V_151 ;
if ( args -> V_152 < 1 || args -> V_152 > V_153 )
return - V_14 ;
V_148 = F_70 ( args -> V_152 , sizeof( T_3 ) ,
V_128 | V_154 ) ;
if ( ! V_148 )
V_148 = F_71 ( sizeof( T_3 ) * args -> V_152 ) ;
if ( ! V_148 )
return - V_102 ;
for ( V_106 = 0 ; V_106 < args -> V_152 ; V_106 ++ ) {
V_149 = F_72 ( V_15 , args -> V_155 + V_106 ) ;
if ( F_73 ( V_149 ) ) {
V_17 = - V_88 ;
goto V_67;
}
V_150 = F_74 ( V_101 -> V_56 , V_149 ) ;
if ( F_75 ( V_150 ) ) {
V_17 = V_150 ;
goto V_67;
}
V_148 [ V_106 ] = V_150 ;
}
V_17 = F_54 ( ( T_3 V_86 * ) args -> V_156 , V_148 ,
sizeof( T_3 ) * args -> V_152 ) ;
if ( V_17 )
V_17 = - V_88 ;
V_67:
F_76 ( V_148 ) ;
return V_17 ;
}
static long F_77 ( struct V_15 * V_15 , struct V_147 * args )
{
T_3 * V_148 ;
T_4 V_149 ;
int V_106 , V_17 = 0 ;
if ( args -> V_72 != 0 )
return - V_14 ;
if ( args -> V_152 < 1 || args -> V_152 > V_153 )
return - V_14 ;
V_148 = F_70 ( args -> V_152 , sizeof( T_3 ) ,
V_128 | V_154 ) ;
if ( ! V_148 )
V_148 = F_71 ( sizeof( T_3 ) * args -> V_152 ) ;
if ( ! V_148 )
return - V_102 ;
V_17 = F_47 ( V_148 , ( T_3 V_86 * ) args -> V_156 ,
sizeof( T_3 ) * args -> V_152 ) ;
if ( V_17 ) {
V_17 = - V_88 ;
goto V_67;
}
F_78 () ;
for ( V_106 = 0 ; V_106 < args -> V_152 ; V_106 ++ ) {
V_149 = F_72 ( V_15 , args -> V_155 + V_106 ) ;
if ( F_73 ( V_149 ) ) {
V_17 = - V_88 ;
goto V_67;
}
if ( V_148 [ V_106 ] & 0x01 ) {
V_17 = - V_14 ;
goto V_67;
}
V_17 = F_79 ( V_101 -> V_56 , V_149 ,
( unsigned long ) V_148 [ V_106 ] , 0 ) ;
if ( V_17 )
goto V_67;
}
V_67:
F_76 ( V_148 ) ;
return V_17 ;
}
long F_80 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_15 * V_15 = V_10 -> V_157 ;
void V_86 * V_158 = ( void V_86 * ) V_12 ;
struct V_80 V_81 ;
int V_17 ;
switch ( V_11 ) {
case V_159 : {
struct V_160 V_161 ;
V_17 = - V_88 ;
if ( F_47 ( & V_161 , V_158 , sizeof( V_161 ) ) )
break;
V_17 = F_81 ( V_15 , & V_161 ) ;
break;
}
case V_162 : {
struct V_70 V_71 ;
V_17 = - V_88 ;
if ( F_47 ( & V_71 , V_158 , sizeof( V_71 ) ) )
break;
V_17 = F_27 ( V_15 , & V_71 ) ;
break;
}
case V_163 : {
struct V_164 V_165 ;
V_17 = - V_14 ;
if ( V_15 -> V_55 . V_73 ) {
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
F_82 ( V_15 , & V_165 , 0 , 0 ) ;
V_17 = 0 ;
}
break;
}
case V_166 : {
V_17 = - V_88 ;
if ( F_47 ( & V_81 , ( void V_86 * ) V_12 , sizeof( V_81 ) ) )
break;
V_17 = F_65 ( V_15 , & V_81 ) ;
break;
}
case V_167 : {
V_17 = - V_88 ;
if ( F_47 ( & V_81 , ( void V_86 * ) V_12 , sizeof( V_81 ) ) )
break;
V_17 = F_66 ( V_15 , & V_81 ) ;
break;
}
case V_168 : {
V_17 = - V_88 ;
if ( F_47 ( & V_81 , ( void V_86 * ) V_12 , sizeof( V_81 ) ) )
break;
V_17 = F_67 ( V_15 , & V_81 ) ;
break;
}
case V_169 : {
struct V_147 args ;
V_17 = - V_88 ;
if ( F_47 ( & args , V_158 ,
sizeof( struct V_147 ) ) )
break;
V_17 = F_68 ( V_15 , & args ) ;
break;
}
case V_170 : {
struct V_147 args ;
V_17 = - V_88 ;
if ( F_47 ( & args , V_158 ,
sizeof( struct V_147 ) ) )
break;
V_17 = F_77 ( V_15 , & args ) ;
break;
}
default:
V_17 = - V_171 ;
}
return V_17 ;
}
static int F_83 ( T_2 * V_172 )
{
T_5 V_173 = 0x04000000UL ;
T_5 V_174 = 0 ;
memset ( V_172 , 0 , 128 ) ;
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
return V_174 ;
}
static int F_84 ( void )
{
T_2 V_172 [ 128 ] ;
int V_174 ;
if ( F_85 ( 2 ) && F_85 ( 12 ) ) {
V_174 = F_83 ( V_172 ) ;
if ( V_174 )
F_86 ( L_1 , V_174 ) ;
else
return V_172 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_87 ( struct V_15 * V_15 )
{
V_15 -> V_55 . V_108 . V_175 = ( V_176 ) ( unsigned long ) V_15 -> V_55 . V_108 . V_109 ;
if ( F_84 () )
V_15 -> V_55 . V_108 . V_175 |= V_177 ;
else
V_15 -> V_55 . V_108 . V_175 |= V_178 ;
}
static void F_88 ( struct V_130 * V_129 )
{
F_63 ( V_129 ) ;
V_129 -> V_179 = 0xff ;
}
static int F_89 ( struct V_15 * V_15 )
{
if ( ! F_41 ( V_15 , 76 ) )
return 0 ;
V_15 -> V_55 . V_108 . V_109 = F_58 ( sizeof( * V_15 -> V_55 . V_108 . V_109 ) ,
V_128 | V_180 ) ;
if ( ! V_15 -> V_55 . V_108 . V_109 )
return - V_102 ;
F_87 ( V_15 ) ;
V_15 -> V_55 . V_108 . V_111 = 1 ;
V_15 -> V_55 . V_108 . V_114 = 1 ;
F_42 ( V_15 -> V_55 . V_108 . V_109 -> V_110 ,
sizeof( V_15 -> V_55 . V_108 . V_109 -> V_110 ) ) ;
F_42 ( V_15 -> V_55 . V_108 . V_109 -> V_113 ,
sizeof( V_15 -> V_55 . V_108 . V_109 -> V_113 ) ) ;
return 0 ;
}
int F_90 ( struct V_15 * V_15 , unsigned long type )
{
int V_106 , V_181 ;
char V_182 [ 16 ] ;
static unsigned long V_183 ;
V_181 = - V_14 ;
#ifdef F_14
if ( type & ~ V_184 )
goto V_185;
if ( ( type & V_184 ) && ( ! F_91 ( V_186 ) ) )
goto V_185;
#else
if ( type )
goto V_185;
#endif
V_181 = F_12 () ;
if ( V_181 )
goto V_185;
V_181 = - V_102 ;
V_15 -> V_55 . V_187 = (struct V_188 * ) F_92 ( V_128 ) ;
if ( ! V_15 -> V_55 . V_187 )
goto V_185;
F_93 ( & V_189 ) ;
V_183 = ( V_183 + 16 ) & 0x7f0 ;
V_15 -> V_55 . V_187 = (struct V_188 * ) ( ( char * ) V_15 -> V_55 . V_187 + V_183 ) ;
F_94 ( & V_189 ) ;
sprintf ( V_182 , L_2 , V_101 -> V_190 ) ;
V_15 -> V_55 . V_191 = F_95 ( V_182 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_15 -> V_55 . V_191 )
goto V_185;
V_15 -> V_55 . V_75 . V_76 =
(struct V_192 * ) F_92 ( V_128 | V_180 ) ;
if ( ! V_15 -> V_55 . V_75 . V_76 )
goto V_185;
memcpy ( V_15 -> V_55 . V_75 . V_76 -> V_77 , V_139 . V_140 ,
V_133 ) ;
for ( V_106 = 0 ; V_106 < V_193 ; V_106 ++ ) {
if ( V_106 < F_1 () )
V_15 -> V_55 . V_75 . V_76 -> V_77 [ V_106 ] &= V_1 [ V_106 ] ;
else
V_15 -> V_55 . V_75 . V_76 -> V_77 [ V_106 ] = 0UL ;
}
memcpy ( V_15 -> V_55 . V_75 . V_76 -> V_78 , V_15 -> V_55 . V_75 . V_76 -> V_77 ,
V_133 ) ;
F_88 ( & V_15 -> V_55 . V_75 . V_129 ) ;
V_15 -> V_55 . V_75 . V_131 = V_137 . V_131 & 0x0fff ;
if ( F_89 ( V_15 ) < 0 )
goto V_185;
F_96 ( & V_15 -> V_55 . V_194 . V_93 ) ;
for ( V_106 = 0 ; V_106 < V_195 ; V_106 ++ )
F_97 ( & V_15 -> V_55 . V_194 . V_196 [ V_106 ] ) ;
F_98 ( & V_15 -> V_55 . V_197 ) ;
F_99 ( & V_15 -> V_55 . V_198 ) ;
F_100 ( V_15 -> V_55 . V_191 , & V_199 ) ;
F_101 ( V_15 , 3 , L_3 , L_4 ) ;
if ( type & V_184 ) {
V_15 -> V_55 . V_54 = NULL ;
} else {
V_15 -> V_55 . V_54 = F_38 ( V_101 -> V_56 , ( 1UL << 44 ) - 1 ) ;
if ( ! V_15 -> V_55 . V_54 )
goto V_185;
V_15 -> V_55 . V_54 -> V_103 = V_15 ;
V_15 -> V_55 . V_54 -> V_200 = 0 ;
}
V_15 -> V_55 . V_201 = 0 ;
V_15 -> V_55 . V_73 = 0 ;
V_15 -> V_55 . V_122 = 0 ;
F_96 ( & V_15 -> V_55 . V_202 ) ;
return 0 ;
V_185:
F_59 ( V_15 -> V_55 . V_108 . V_109 ) ;
F_102 ( ( unsigned long ) V_15 -> V_55 . V_75 . V_76 ) ;
F_103 ( V_15 -> V_55 . V_191 ) ;
F_102 ( ( unsigned long ) ( V_15 -> V_55 . V_187 ) ) ;
return V_181 ;
}
void F_104 ( struct V_104 * V_105 )
{
F_105 ( V_105 , 3 , L_3 , L_5 ) ;
F_106 ( V_105 -> V_203 ) ;
F_107 ( V_105 ) ;
F_108 ( V_105 ) ;
if ( ! F_36 ( V_105 -> V_15 ) ) {
F_109 ( 63 - V_105 -> V_203 ,
( unsigned long * ) & V_105 -> V_15 -> V_55 . V_187 -> V_204 ) ;
if ( V_105 -> V_15 -> V_55 . V_187 -> V_205 [ V_105 -> V_203 ] . V_206 ==
( V_207 ) V_105 -> V_55 . V_123 )
V_105 -> V_15 -> V_55 . V_187 -> V_205 [ V_105 -> V_203 ] . V_206 = 0 ;
}
F_110 () ;
if ( F_36 ( V_105 -> V_15 ) )
F_39 ( V_105 -> V_55 . V_54 ) ;
if ( F_111 ( V_105 -> V_15 ) )
F_112 ( V_105 ) ;
F_102 ( ( unsigned long ) ( V_105 -> V_55 . V_123 ) ) ;
F_113 ( V_105 ) ;
F_114 ( V_208 , V_105 ) ;
}
static void F_115 ( struct V_15 * V_15 )
{
unsigned int V_106 ;
struct V_104 * V_105 ;
F_43 (i, vcpu, kvm)
F_104 ( V_105 ) ;
F_22 ( & V_15 -> V_93 ) ;
for ( V_106 = 0 ; V_106 < F_32 ( & V_15 -> V_94 ) ; V_106 ++ )
V_15 -> V_209 [ V_106 ] = NULL ;
F_116 ( & V_15 -> V_94 , 0 ) ;
F_26 ( & V_15 -> V_93 ) ;
}
void F_117 ( struct V_15 * V_15 )
{
F_115 ( V_15 ) ;
F_102 ( ( unsigned long ) V_15 -> V_55 . V_75 . V_76 ) ;
F_102 ( ( unsigned long ) ( V_15 -> V_55 . V_187 ) ) ;
F_103 ( V_15 -> V_55 . V_191 ) ;
F_59 ( V_15 -> V_55 . V_108 . V_109 ) ;
if ( ! F_36 ( V_15 ) )
F_39 ( V_15 -> V_55 . V_54 ) ;
F_118 ( V_15 ) ;
F_119 ( V_15 ) ;
}
static int F_120 ( struct V_104 * V_105 )
{
V_105 -> V_55 . V_54 = F_38 ( V_101 -> V_56 , - 1UL ) ;
if ( ! V_105 -> V_55 . V_54 )
return - V_102 ;
V_105 -> V_55 . V_54 -> V_103 = V_105 -> V_15 ;
return 0 ;
}
int F_121 ( struct V_104 * V_105 )
{
V_105 -> V_55 . V_210 = V_211 ;
F_108 ( V_105 ) ;
V_105 -> V_212 -> V_213 = V_214 |
V_215 |
V_216 |
V_217 |
V_218 |
V_219 ;
if ( F_41 ( V_105 -> V_15 , 129 ) )
V_105 -> V_212 -> V_213 |= V_220 ;
if ( F_36 ( V_105 -> V_15 ) )
return F_120 ( V_105 ) ;
return 0 ;
}
void F_122 ( struct V_104 * V_105 , int V_205 )
{
F_123 ( & V_105 -> V_55 . V_221 . V_222 ) ;
if ( F_41 ( V_105 -> V_15 , 129 ) )
F_124 ( ( V_223 * ) & V_105 -> V_55 . V_224 -> V_225 ) ;
else
F_125 ( V_105 -> V_55 . V_221 . V_226 ) ;
F_126 ( V_105 -> V_55 . V_227 ) ;
if ( F_41 ( V_105 -> V_15 , 129 ) ) {
F_127 ( & V_105 -> V_212 -> V_228 . V_229 . V_222 ) ;
F_128 ( ( V_223 * ) & V_105 -> V_212 -> V_228 . V_229 . V_225 ) ;
} else {
F_127 ( & V_105 -> V_55 . V_230 . V_222 ) ;
F_129 ( V_105 -> V_55 . V_230 . V_226 ) ;
}
F_130 ( V_105 -> V_212 -> V_228 . V_229 . V_231 ) ;
F_131 ( V_105 -> V_55 . V_54 ) ;
F_132 ( V_232 , & V_105 -> V_55 . V_123 -> V_233 ) ;
}
void F_133 ( struct V_104 * V_105 )
{
F_134 ( V_232 , & V_105 -> V_55 . V_123 -> V_233 ) ;
F_135 ( V_105 -> V_55 . V_54 ) ;
if ( F_41 ( V_105 -> V_15 , 129 ) ) {
F_123 ( & V_105 -> V_212 -> V_228 . V_229 . V_222 ) ;
F_124 ( ( V_223 * ) & V_105 -> V_212 -> V_228 . V_229 . V_225 ) ;
} else {
F_123 ( & V_105 -> V_55 . V_230 . V_222 ) ;
F_125 ( V_105 -> V_55 . V_230 . V_226 ) ;
}
F_126 ( V_105 -> V_212 -> V_228 . V_229 . V_231 ) ;
F_127 ( & V_105 -> V_55 . V_221 . V_222 ) ;
if ( F_41 ( V_105 -> V_15 , 129 ) )
F_128 ( ( V_223 * ) & V_105 -> V_55 . V_224 -> V_225 ) ;
else
F_129 ( V_105 -> V_55 . V_221 . V_226 ) ;
F_130 ( V_105 -> V_55 . V_227 ) ;
}
static void F_136 ( struct V_104 * V_105 )
{
V_105 -> V_55 . V_123 -> V_234 . V_77 = 0UL ;
V_105 -> V_55 . V_123 -> V_234 . V_87 = 0UL ;
F_137 ( V_105 , 0 ) ;
V_105 -> V_55 . V_123 -> V_235 = 0UL ;
V_105 -> V_55 . V_123 -> V_236 = 0UL ;
V_105 -> V_55 . V_123 -> V_237 = 0 ;
memset ( V_105 -> V_55 . V_123 -> V_238 , 0 , 16 * sizeof( V_207 ) ) ;
V_105 -> V_55 . V_123 -> V_238 [ 0 ] = 0xE0UL ;
V_105 -> V_55 . V_123 -> V_238 [ 14 ] = 0xC2000000UL ;
V_105 -> V_55 . V_230 . V_222 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_105 -> V_55 . V_123 -> V_239 = 1 ;
V_105 -> V_55 . V_123 -> V_240 = 0 ;
V_105 -> V_55 . V_210 = V_211 ;
F_108 ( V_105 ) ;
if ( ! F_138 ( V_105 -> V_15 ) )
F_139 ( V_105 ) ;
F_107 ( V_105 ) ;
}
void F_140 ( struct V_104 * V_105 )
{
F_22 ( & V_105 -> V_15 -> V_93 ) ;
V_105 -> V_55 . V_123 -> V_122 = V_105 -> V_15 -> V_55 . V_122 ;
F_26 ( & V_105 -> V_15 -> V_93 ) ;
if ( ! F_36 ( V_105 -> V_15 ) )
V_105 -> V_55 . V_54 = V_105 -> V_15 -> V_55 . V_54 ;
}
static void F_44 ( struct V_104 * V_105 )
{
if ( ! F_41 ( V_105 -> V_15 , 76 ) )
return;
V_105 -> V_55 . V_123 -> V_241 &= ~ ( V_242 | V_243 ) ;
if ( V_105 -> V_15 -> V_55 . V_108 . V_111 )
V_105 -> V_55 . V_123 -> V_241 |= V_242 ;
if ( V_105 -> V_15 -> V_55 . V_108 . V_114 )
V_105 -> V_55 . V_123 -> V_241 |= V_243 ;
V_105 -> V_55 . V_123 -> V_175 = V_105 -> V_15 -> V_55 . V_108 . V_175 ;
}
void F_112 ( struct V_104 * V_105 )
{
F_102 ( V_105 -> V_55 . V_123 -> V_244 ) ;
V_105 -> V_55 . V_123 -> V_244 = 0 ;
}
int F_141 ( struct V_104 * V_105 )
{
V_105 -> V_55 . V_123 -> V_244 = F_92 ( V_128 ) ;
if ( ! V_105 -> V_55 . V_123 -> V_244 )
return - V_102 ;
V_105 -> V_55 . V_123 -> V_245 |= 0x80 ;
V_105 -> V_55 . V_123 -> V_245 &= ~ 0x08 ;
return 0 ;
}
static void F_142 ( struct V_104 * V_105 )
{
struct V_246 * V_75 = & V_105 -> V_15 -> V_55 . V_75 ;
V_105 -> V_55 . V_129 = V_75 -> V_129 ;
V_105 -> V_55 . V_123 -> V_131 = V_75 -> V_131 ;
V_105 -> V_55 . V_123 -> V_76 = ( int ) ( long ) V_75 -> V_76 -> V_78 ;
}
int F_143 ( struct V_104 * V_105 )
{
int V_181 = 0 ;
F_116 ( & V_105 -> V_55 . V_123 -> V_233 , V_247 |
V_248 |
V_249 ) ;
if ( F_41 ( V_105 -> V_15 , 78 ) )
F_132 ( V_250 , & V_105 -> V_55 . V_123 -> V_233 ) ;
else if ( F_41 ( V_105 -> V_15 , 8 ) )
F_132 ( V_251 , & V_105 -> V_55 . V_123 -> V_233 ) ;
F_142 ( V_105 ) ;
V_105 -> V_55 . V_123 -> V_252 = 6 ;
if ( F_41 ( V_105 -> V_15 , 50 ) && F_41 ( V_105 -> V_15 , 73 ) )
V_105 -> V_55 . V_123 -> V_252 |= 0x10 ;
V_105 -> V_55 . V_123 -> V_245 = 8 ;
V_105 -> V_55 . V_123 -> V_253 = 0xC1002000U ;
if ( V_137 . V_254 )
V_105 -> V_55 . V_123 -> V_253 |= 1 ;
if ( V_137 . V_255 )
V_105 -> V_55 . V_123 -> V_253 |= 0x10000000U ;
if ( F_41 ( V_105 -> V_15 , 129 ) ) {
V_105 -> V_55 . V_123 -> V_253 |= 0x00020000 ;
V_105 -> V_55 . V_123 -> V_256 |= 0x20000000 ;
}
V_105 -> V_55 . V_123 -> V_257 |= V_258 | V_259 | V_260 ;
if ( F_111 ( V_105 -> V_15 ) ) {
V_181 = F_141 ( V_105 ) ;
if ( V_181 )
return V_181 ;
}
F_144 ( & V_105 -> V_55 . V_261 , V_262 , V_263 ) ;
V_105 -> V_55 . V_261 . V_264 = V_265 ;
F_44 ( V_105 ) ;
return V_181 ;
}
struct V_104 * F_145 ( struct V_15 * V_15 ,
unsigned int V_266 )
{
struct V_104 * V_105 ;
struct V_267 * V_267 ;
int V_181 = - V_14 ;
if ( V_266 >= V_42 )
goto V_67;
V_181 = - V_102 ;
V_105 = F_146 ( V_208 , V_128 ) ;
if ( ! V_105 )
goto V_67;
V_267 = (struct V_267 * ) F_92 ( V_128 ) ;
if ( ! V_267 )
goto V_268;
V_105 -> V_55 . V_123 = & V_267 -> V_123 ;
V_105 -> V_55 . V_123 -> V_269 = ( unsigned long ) & V_267 -> V_270 ;
V_105 -> V_55 . V_224 = & V_267 -> V_271 ;
V_105 -> V_55 . V_123 -> V_272 = V_266 ;
if ( ! F_36 ( V_15 ) ) {
if ( ! V_15 -> V_55 . V_187 ) {
F_147 ( 1 ) ;
goto V_268;
}
if ( ! V_15 -> V_55 . V_187 -> V_205 [ V_266 ] . V_206 )
V_15 -> V_55 . V_187 -> V_205 [ V_266 ] . V_206 =
( V_207 ) V_105 -> V_55 . V_123 ;
V_105 -> V_55 . V_123 -> V_273 =
( V_176 ) ( ( ( V_207 ) V_15 -> V_55 . V_187 ) >> 32 ) ;
V_105 -> V_55 . V_123 -> V_274 = ( V_176 ) ( V_207 ) V_15 -> V_55 . V_187 ;
F_148 ( 63 - V_266 , ( unsigned long * ) & V_15 -> V_55 . V_187 -> V_204 ) ;
}
F_96 ( & V_105 -> V_55 . V_275 . V_93 ) ;
V_105 -> V_55 . V_275 . V_194 = & V_15 -> V_55 . V_194 ;
V_105 -> V_55 . V_275 . V_276 = & V_105 -> V_276 ;
V_105 -> V_55 . V_275 . V_233 = & V_105 -> V_55 . V_123 -> V_233 ;
V_181 = F_149 ( V_105 , V_15 , V_266 ) ;
if ( V_181 )
goto V_277;
F_101 ( V_15 , 3 , L_6 , V_266 , V_105 ,
V_105 -> V_55 . V_123 ) ;
F_150 ( V_266 , V_105 , V_105 -> V_55 . V_123 ) ;
return V_105 ;
V_277:
F_102 ( ( unsigned long ) ( V_105 -> V_55 . V_123 ) ) ;
V_268:
F_114 ( V_208 , V_105 ) ;
V_67:
return F_151 ( V_181 ) ;
}
int F_152 ( struct V_104 * V_105 )
{
return F_153 ( V_105 , 0 ) ;
}
void F_154 ( struct V_104 * V_105 )
{
F_132 ( V_278 , & V_105 -> V_55 . V_123 -> V_279 ) ;
F_45 ( V_105 ) ;
}
void F_155 ( struct V_104 * V_105 )
{
F_134 ( V_278 , & V_105 -> V_55 . V_123 -> V_279 ) ;
}
static void F_156 ( struct V_104 * V_105 )
{
F_132 ( V_280 , & V_105 -> V_55 . V_123 -> V_279 ) ;
F_45 ( V_105 ) ;
}
static void F_157 ( struct V_104 * V_105 )
{
F_134 ( V_280 , & V_105 -> V_55 . V_123 -> V_279 ) ;
}
void F_45 ( struct V_104 * V_105 )
{
F_132 ( V_281 , & V_105 -> V_55 . V_123 -> V_233 ) ;
while ( V_105 -> V_55 . V_123 -> V_282 & V_283 )
F_158 () ;
}
void F_159 ( int V_284 , struct V_104 * V_105 )
{
F_160 ( V_284 , V_105 ) ;
F_156 ( V_105 ) ;
}
static void V_5 ( struct V_54 * V_54 , unsigned long V_53 )
{
int V_106 ;
struct V_15 * V_15 = V_54 -> V_103 ;
struct V_104 * V_105 ;
F_43 (i, vcpu, kvm) {
if ( F_161 ( V_105 ) == ( V_53 & ~ 0x1000UL ) ) {
F_105 ( V_105 , 2 , L_7 , V_53 ) ;
F_159 ( V_285 , V_105 ) ;
}
}
}
int F_162 ( struct V_104 * V_105 )
{
F_163 () ;
return 0 ;
}
static int F_164 ( struct V_104 * V_105 ,
struct V_286 * V_287 )
{
int V_17 = - V_14 ;
switch ( V_287 -> V_266 ) {
case V_288 :
V_17 = F_30 ( V_105 -> V_55 . V_123 -> V_237 ,
( T_5 V_86 * ) V_287 -> V_87 ) ;
break;
case V_289 :
V_17 = F_30 ( V_105 -> V_55 . V_123 -> V_122 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_290 :
V_17 = F_30 ( V_105 -> V_55 . V_123 -> V_235 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_291 :
V_17 = F_30 ( V_105 -> V_55 . V_123 -> V_236 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_292 :
V_17 = F_30 ( V_105 -> V_55 . V_210 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_293 :
V_17 = F_30 ( V_105 -> V_55 . V_294 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_295 :
V_17 = F_30 ( V_105 -> V_55 . V_296 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_297 :
V_17 = F_30 ( V_105 -> V_55 . V_123 -> V_240 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_298 :
V_17 = F_30 ( V_105 -> V_55 . V_123 -> V_239 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_165 ( struct V_104 * V_105 ,
struct V_286 * V_287 )
{
int V_17 = - V_14 ;
switch ( V_287 -> V_266 ) {
case V_288 :
V_17 = F_37 ( V_105 -> V_55 . V_123 -> V_237 ,
( T_5 V_86 * ) V_287 -> V_87 ) ;
break;
case V_289 :
V_17 = F_37 ( V_105 -> V_55 . V_123 -> V_122 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_290 :
V_17 = F_37 ( V_105 -> V_55 . V_123 -> V_235 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_291 :
V_17 = F_37 ( V_105 -> V_55 . V_123 -> V_236 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_292 :
V_17 = F_37 ( V_105 -> V_55 . V_210 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
if ( V_105 -> V_55 . V_210 == V_211 )
F_108 ( V_105 ) ;
break;
case V_293 :
V_17 = F_37 ( V_105 -> V_55 . V_294 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_295 :
V_17 = F_37 ( V_105 -> V_55 . V_296 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_297 :
V_17 = F_37 ( V_105 -> V_55 . V_123 -> V_240 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
case V_298 :
V_17 = F_37 ( V_105 -> V_55 . V_123 -> V_239 ,
( V_85 V_86 * ) V_287 -> V_87 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_166 ( struct V_104 * V_105 )
{
F_136 ( V_105 ) ;
return 0 ;
}
int F_167 ( struct V_104 * V_105 , struct V_299 * V_229 )
{
memcpy ( & V_105 -> V_212 -> V_228 . V_229 . V_300 , & V_229 -> V_300 , sizeof( V_229 -> V_300 ) ) ;
return 0 ;
}
int F_168 ( struct V_104 * V_105 , struct V_299 * V_229 )
{
memcpy ( & V_229 -> V_300 , & V_105 -> V_212 -> V_228 . V_229 . V_300 , sizeof( V_229 -> V_300 ) ) ;
return 0 ;
}
int F_169 ( struct V_104 * V_105 ,
struct V_301 * V_302 )
{
memcpy ( & V_105 -> V_212 -> V_228 . V_229 . V_231 , & V_302 -> V_231 , sizeof( V_302 -> V_231 ) ) ;
memcpy ( & V_105 -> V_55 . V_123 -> V_238 , & V_302 -> V_303 , sizeof( V_302 -> V_303 ) ) ;
F_130 ( V_105 -> V_212 -> V_228 . V_229 . V_231 ) ;
return 0 ;
}
int F_170 ( struct V_104 * V_105 ,
struct V_301 * V_302 )
{
memcpy ( & V_302 -> V_231 , & V_105 -> V_212 -> V_228 . V_229 . V_231 , sizeof( V_302 -> V_231 ) ) ;
memcpy ( & V_302 -> V_303 , & V_105 -> V_55 . V_123 -> V_238 , sizeof( V_302 -> V_303 ) ) ;
return 0 ;
}
int F_171 ( struct V_104 * V_105 , struct V_304 * V_305 )
{
if ( F_172 ( V_305 -> V_222 ) )
return - V_14 ;
memcpy ( & V_105 -> V_55 . V_230 . V_226 , & V_305 -> V_226 , sizeof( V_305 -> V_226 ) ) ;
V_105 -> V_55 . V_230 . V_222 = V_305 -> V_222 ;
F_127 ( & V_105 -> V_55 . V_230 . V_222 ) ;
F_129 ( V_105 -> V_55 . V_230 . V_226 ) ;
return 0 ;
}
int F_173 ( struct V_104 * V_105 , struct V_304 * V_305 )
{
memcpy ( & V_305 -> V_226 , & V_105 -> V_55 . V_230 . V_226 , sizeof( V_305 -> V_226 ) ) ;
V_305 -> V_222 = V_105 -> V_55 . V_230 . V_222 ;
return 0 ;
}
static int F_174 ( struct V_104 * V_105 , T_6 V_306 )
{
int V_181 = 0 ;
if ( ! F_175 ( V_105 ) )
V_181 = - V_92 ;
else {
V_105 -> V_212 -> V_307 = V_306 . V_77 ;
V_105 -> V_212 -> V_308 = V_306 . V_87 ;
}
return V_181 ;
}
int F_176 ( struct V_104 * V_105 ,
struct V_309 * V_310 )
{
return - V_14 ;
}
int F_177 ( struct V_104 * V_105 ,
struct V_311 * V_312 )
{
int V_181 = 0 ;
V_105 -> V_313 = 0 ;
F_178 ( V_105 ) ;
if ( V_312 -> V_314 & ~ V_315 )
return - V_14 ;
if ( V_312 -> V_314 & V_316 ) {
V_105 -> V_313 = V_312 -> V_314 ;
F_132 ( V_317 , & V_105 -> V_55 . V_123 -> V_233 ) ;
if ( V_312 -> V_314 & V_318 )
V_181 = F_179 ( V_105 , V_312 ) ;
} else {
F_134 ( V_317 , & V_105 -> V_55 . V_123 -> V_233 ) ;
V_105 -> V_55 . V_319 . V_320 = 0 ;
}
if ( V_181 ) {
V_105 -> V_313 = 0 ;
F_178 ( V_105 ) ;
F_134 ( V_317 , & V_105 -> V_55 . V_123 -> V_233 ) ;
}
return V_181 ;
}
int F_180 ( struct V_104 * V_105 ,
struct V_321 * V_322 )
{
return F_175 ( V_105 ) ? V_323 :
V_324 ;
}
int F_181 ( struct V_104 * V_105 ,
struct V_321 * V_322 )
{
int V_181 = 0 ;
V_105 -> V_15 -> V_55 . V_325 = 1 ;
switch ( V_322 -> V_322 ) {
case V_323 :
F_139 ( V_105 ) ;
break;
case V_324 :
F_182 ( V_105 ) ;
break;
case V_326 :
case V_327 :
default:
V_181 = - V_89 ;
}
return V_181 ;
}
bool F_111 ( struct V_15 * V_15 )
{
if ( ! V_328 )
return false ;
if ( ! V_329 )
return false ;
if ( ! V_15 -> V_55 . V_95 )
return false ;
return true ;
}
static bool F_183 ( struct V_104 * V_105 )
{
return F_32 ( & V_105 -> V_55 . V_123 -> V_233 ) & V_330 ;
}
static int F_184 ( struct V_104 * V_105 )
{
V_331:
F_157 ( V_105 ) ;
if ( ! V_105 -> V_332 )
return 0 ;
if ( F_185 ( V_285 , V_105 ) ) {
int V_181 ;
V_181 = F_186 ( V_105 -> V_55 . V_54 ,
F_161 ( V_105 ) ,
V_333 * 2 ) ;
if ( V_181 )
return V_181 ;
goto V_331;
}
if ( F_185 ( V_334 , V_105 ) ) {
V_105 -> V_55 . V_123 -> V_335 = 0xffff ;
goto V_331;
}
if ( F_185 ( V_336 , V_105 ) ) {
if ( ! F_183 ( V_105 ) ) {
F_187 ( V_105 -> V_203 , 1 ) ;
F_132 ( V_330 ,
& V_105 -> V_55 . V_123 -> V_233 ) ;
}
goto V_331;
}
if ( F_185 ( V_337 , V_105 ) ) {
if ( F_183 ( V_105 ) ) {
F_187 ( V_105 -> V_203 , 0 ) ;
F_134 ( V_330 ,
& V_105 -> V_55 . V_123 -> V_233 ) ;
}
goto V_331;
}
F_109 ( V_338 , & V_105 -> V_332 ) ;
return 0 ;
}
long F_188 ( struct V_104 * V_105 , T_7 V_339 , int V_340 )
{
return F_189 ( V_105 -> V_55 . V_54 , V_339 ,
V_340 ? V_341 : 0 ) ;
}
static void F_190 ( struct V_104 * V_105 , bool V_342 ,
unsigned long V_343 )
{
struct V_160 V_344 ;
struct V_345 V_346 ;
if ( V_342 ) {
V_346 . V_347 . V_16 . V_348 = V_343 ;
V_346 . type = V_349 ;
F_147 ( F_191 ( V_105 , & V_346 ) ) ;
} else {
V_344 . type = V_350 ;
V_344 . V_351 = V_343 ;
F_147 ( F_81 ( V_105 -> V_15 , & V_344 ) ) ;
}
}
void F_192 ( struct V_104 * V_105 ,
struct V_352 * V_353 )
{
F_193 ( V_105 , V_353 -> V_55 . V_210 ) ;
F_190 ( V_105 , true , V_353 -> V_55 . V_210 ) ;
}
void F_194 ( struct V_104 * V_105 ,
struct V_352 * V_353 )
{
F_195 ( V_105 , V_353 -> V_55 . V_210 ) ;
F_190 ( V_105 , false , V_353 -> V_55 . V_210 ) ;
}
void F_196 ( struct V_104 * V_105 ,
struct V_352 * V_353 )
{
}
bool F_197 ( struct V_104 * V_105 )
{
return true ;
}
static int F_198 ( struct V_104 * V_105 )
{
T_8 V_149 ;
struct V_354 V_55 ;
int V_181 ;
if ( V_105 -> V_55 . V_210 == V_211 )
return 0 ;
if ( ( V_105 -> V_55 . V_123 -> V_234 . V_77 & V_105 -> V_55 . V_296 ) !=
V_105 -> V_55 . V_294 )
return 0 ;
if ( F_199 ( V_105 ) )
return 0 ;
if ( F_153 ( V_105 , 0 ) )
return 0 ;
if ( ! ( V_105 -> V_55 . V_123 -> V_238 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_105 -> V_55 . V_54 -> V_200 )
return 0 ;
V_149 = F_72 ( V_105 -> V_15 , F_200 ( V_101 -> V_355 . V_356 ) ) ;
V_149 += V_101 -> V_355 . V_356 & ~ V_357 ;
if ( F_201 ( V_105 , V_105 -> V_55 . V_210 , & V_55 . V_210 , 8 ) )
return 0 ;
V_181 = F_202 ( V_105 , V_101 -> V_355 . V_356 , V_149 , & V_55 ) ;
return V_181 ;
}
static int F_203 ( struct V_104 * V_105 )
{
int V_181 , V_233 ;
F_204 ( V_105 ) ;
memcpy ( & V_105 -> V_55 . V_123 -> V_358 , & V_105 -> V_212 -> V_228 . V_229 . V_300 [ 14 ] , 16 ) ;
if ( F_205 () )
F_206 () ;
if ( F_207 ( V_359 ) )
F_208 () ;
if ( ! F_36 ( V_105 -> V_15 ) ) {
V_181 = F_209 ( V_105 ) ;
if ( V_181 )
return V_181 ;
}
V_181 = F_184 ( V_105 ) ;
if ( V_181 )
return V_181 ;
if ( F_210 ( V_105 ) ) {
F_211 ( V_105 ) ;
F_212 ( V_105 ) ;
}
V_105 -> V_55 . V_123 -> V_360 = 0 ;
V_233 = F_32 ( & V_105 -> V_55 . V_123 -> V_233 ) ;
F_105 ( V_105 , 6 , L_8 , V_233 ) ;
F_213 ( V_105 , V_233 ) ;
return 0 ;
}
static int F_214 ( struct V_104 * V_105 )
{
T_6 * V_306 = & V_105 -> V_55 . V_123 -> V_234 ;
T_2 V_361 ;
int V_181 ;
F_105 ( V_105 , 3 , L_3 , L_9 ) ;
F_215 ( V_105 ) ;
V_181 = F_216 ( V_105 , V_306 -> V_87 , 0 , & V_361 , 1 ) ;
if ( V_181 )
return F_217 ( V_105 , V_181 ) ;
V_306 -> V_87 = F_218 ( * V_306 , - F_219 ( V_361 ) ) ;
return F_220 ( V_105 , V_362 ) ;
}
static int F_221 ( struct V_104 * V_105 , int V_363 )
{
int V_181 = - 1 ;
F_105 ( V_105 , 6 , L_10 ,
V_105 -> V_55 . V_123 -> V_360 ) ;
F_222 ( V_105 , V_105 -> V_55 . V_123 -> V_360 ) ;
if ( F_210 ( V_105 ) )
F_223 ( V_105 ) ;
if ( V_363 >= 0 ) {
V_181 = 0 ;
} else if ( F_36 ( V_105 -> V_15 ) ) {
V_105 -> V_212 -> V_363 = V_364 ;
V_105 -> V_212 -> V_365 . V_366 =
V_101 -> V_355 . V_356 ;
V_105 -> V_212 -> V_365 . V_367 = 0x10 ;
V_181 = - V_368 ;
} else if ( V_101 -> V_355 . V_369 ) {
F_224 ( V_105 ) ;
V_101 -> V_355 . V_369 = 0 ;
if ( F_198 ( V_105 ) ) {
V_181 = 0 ;
} else {
T_7 V_339 = V_101 -> V_355 . V_356 ;
V_181 = F_188 ( V_105 , V_339 , 1 ) ;
}
}
if ( V_181 == - 1 )
V_181 = F_214 ( V_105 ) ;
memcpy ( & V_105 -> V_212 -> V_228 . V_229 . V_300 [ 14 ] , & V_105 -> V_55 . V_123 -> V_358 , 16 ) ;
if ( V_181 == 0 ) {
if ( F_36 ( V_105 -> V_15 ) )
V_181 = V_105 -> V_55 . V_123 -> V_360 ? - V_370 : 0 ;
else
V_181 = F_225 ( V_105 ) ;
}
return V_181 ;
}
static int F_226 ( struct V_104 * V_105 )
{
int V_181 , V_363 ;
V_105 -> V_371 = F_33 ( & V_105 -> V_15 -> V_97 ) ;
do {
V_181 = F_203 ( V_105 ) ;
if ( V_181 )
break;
F_35 ( & V_105 -> V_15 -> V_97 , V_105 -> V_371 ) ;
F_227 () ;
F_228 () ;
F_229 () ;
V_363 = F_230 ( V_105 -> V_55 . V_123 ,
V_105 -> V_212 -> V_228 . V_229 . V_300 ) ;
F_227 () ;
F_231 () ;
F_229 () ;
V_105 -> V_371 = F_33 ( & V_105 -> V_15 -> V_97 ) ;
V_181 = F_221 ( V_105 , V_363 ) ;
} while ( ! F_232 ( V_101 ) && ! F_233 ( V_105 ) && ! V_181 );
F_35 ( & V_105 -> V_15 -> V_97 , V_105 -> V_371 ) ;
return V_181 ;
}
static void F_234 ( struct V_104 * V_105 , struct V_372 * V_372 )
{
V_105 -> V_55 . V_123 -> V_234 . V_77 = V_372 -> V_307 ;
V_105 -> V_55 . V_123 -> V_234 . V_87 = V_372 -> V_308 ;
if ( V_372 -> V_373 & V_214 )
F_137 ( V_105 , V_372 -> V_228 . V_229 . V_374 ) ;
if ( V_372 -> V_373 & V_217 ) {
memcpy ( & V_105 -> V_55 . V_123 -> V_238 , & V_372 -> V_228 . V_229 . V_303 , 128 ) ;
F_160 ( V_334 , V_105 ) ;
}
if ( V_372 -> V_373 & V_218 ) {
V_105 -> V_55 . V_123 -> V_235 = V_372 -> V_228 . V_229 . V_235 ;
V_105 -> V_55 . V_123 -> V_236 = V_372 -> V_228 . V_229 . V_236 ;
V_105 -> V_55 . V_123 -> V_237 = V_372 -> V_228 . V_229 . V_237 ;
V_105 -> V_55 . V_123 -> V_240 = V_372 -> V_228 . V_229 . V_240 ;
V_105 -> V_55 . V_123 -> V_239 = V_372 -> V_228 . V_229 . V_239 ;
}
if ( V_372 -> V_373 & V_219 ) {
V_105 -> V_55 . V_210 = V_372 -> V_228 . V_229 . V_375 ;
V_105 -> V_55 . V_296 = V_372 -> V_228 . V_229 . V_376 ;
V_105 -> V_55 . V_294 = V_372 -> V_228 . V_229 . V_377 ;
if ( V_105 -> V_55 . V_210 == V_211 )
F_108 ( V_105 ) ;
}
V_372 -> V_373 = 0 ;
}
static void F_235 ( struct V_104 * V_105 , struct V_372 * V_372 )
{
V_372 -> V_307 = V_105 -> V_55 . V_123 -> V_234 . V_77 ;
V_372 -> V_308 = V_105 -> V_55 . V_123 -> V_234 . V_87 ;
V_372 -> V_228 . V_229 . V_374 = F_161 ( V_105 ) ;
memcpy ( & V_372 -> V_228 . V_229 . V_303 , & V_105 -> V_55 . V_123 -> V_238 , 128 ) ;
V_372 -> V_228 . V_229 . V_235 = V_105 -> V_55 . V_123 -> V_235 ;
V_372 -> V_228 . V_229 . V_236 = V_105 -> V_55 . V_123 -> V_236 ;
V_372 -> V_228 . V_229 . V_237 = V_105 -> V_55 . V_123 -> V_237 ;
V_372 -> V_228 . V_229 . V_240 = V_105 -> V_55 . V_123 -> V_240 ;
V_372 -> V_228 . V_229 . V_239 = V_105 -> V_55 . V_123 -> V_239 ;
V_372 -> V_228 . V_229 . V_375 = V_105 -> V_55 . V_210 ;
V_372 -> V_228 . V_229 . V_376 = V_105 -> V_55 . V_296 ;
V_372 -> V_228 . V_229 . V_377 = V_105 -> V_55 . V_294 ;
}
int F_236 ( struct V_104 * V_105 , struct V_372 * V_372 )
{
int V_181 ;
T_9 V_378 ;
if ( F_233 ( V_105 ) ) {
F_237 ( V_105 ) ;
return 0 ;
}
if ( V_105 -> V_379 )
F_238 ( V_380 , & V_105 -> V_381 , & V_378 ) ;
if ( ! F_138 ( V_105 -> V_15 ) ) {
F_182 ( V_105 ) ;
} else if ( F_175 ( V_105 ) ) {
F_239 ( L_11 ,
V_105 -> V_203 ) ;
return - V_14 ;
}
F_234 ( V_105 , V_372 ) ;
F_240 () ;
V_181 = F_226 ( V_105 ) ;
if ( F_232 ( V_101 ) && ! V_181 ) {
V_372 -> V_363 = V_382 ;
V_181 = - V_383 ;
}
if ( F_233 ( V_105 ) && ! V_181 ) {
F_237 ( V_105 ) ;
V_181 = 0 ;
}
if ( V_181 == - V_370 ) {
V_372 -> V_363 = V_384 ;
V_372 -> V_385 . V_360 = V_105 -> V_55 . V_123 -> V_360 ;
V_372 -> V_385 . V_386 = V_105 -> V_55 . V_123 -> V_386 ;
V_372 -> V_385 . V_387 = V_105 -> V_55 . V_123 -> V_387 ;
V_181 = 0 ;
}
if ( V_181 == - V_368 ) {
V_181 = 0 ;
}
F_235 ( V_105 , V_372 ) ;
if ( V_105 -> V_379 )
F_238 ( V_380 , & V_378 , NULL ) ;
V_105 -> V_388 . V_389 ++ ;
return V_181 ;
}
int F_241 ( struct V_104 * V_105 , unsigned long V_339 )
{
unsigned char V_390 = 1 ;
unsigned int V_391 ;
V_85 V_392 ;
int V_181 ;
if ( V_339 == V_393 ) {
if ( F_242 ( V_105 , 163 , & V_390 , 1 ) )
return - V_88 ;
V_339 = V_394 ;
} else if ( V_339 == V_395 ) {
if ( F_243 ( V_105 , 163 , & V_390 , 1 ) )
return - V_88 ;
V_339 = F_244 ( V_105 , V_394 ) ;
}
V_181 = F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_397 ) ,
V_105 -> V_55 . V_230 . V_226 , 128 ) ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_398 ) ,
V_105 -> V_212 -> V_228 . V_229 . V_300 , 128 ) ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_306 ) ,
& V_105 -> V_55 . V_123 -> V_234 , 16 ) ;
V_391 = F_161 ( V_105 ) ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_399 ) ,
& V_391 , 4 ) ;
V_181 |= F_242 ( V_105 ,
V_339 + F_245 ( struct V_396 , V_400 ) ,
& V_105 -> V_55 . V_230 . V_222 , 4 ) ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_401 ) ,
& V_105 -> V_55 . V_123 -> V_237 , 4 ) ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_402 ) ,
& V_105 -> V_55 . V_123 -> V_235 , 8 ) ;
V_392 = V_105 -> V_55 . V_123 -> V_236 >> 8 ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_403 ) ,
& V_392 , 8 ) ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_404 ) ,
& V_105 -> V_212 -> V_228 . V_229 . V_231 , 64 ) ;
V_181 |= F_242 ( V_105 , V_339 + F_245 ( struct V_396 , V_405 ) ,
& V_105 -> V_55 . V_123 -> V_238 , 128 ) ;
return V_181 ? - V_88 : 0 ;
}
int F_246 ( struct V_104 * V_105 , unsigned long V_87 )
{
F_123 ( & V_105 -> V_55 . V_230 . V_222 ) ;
F_125 ( V_105 -> V_55 . V_230 . V_226 ) ;
F_126 ( V_105 -> V_212 -> V_228 . V_229 . V_231 ) ;
return F_241 ( V_105 , V_87 ) ;
}
int F_247 ( struct V_104 * V_105 ,
unsigned long V_339 )
{
if ( ! ( V_339 & ~ 0x3ff ) )
return 0 ;
return F_242 ( V_105 , V_339 & ~ 0x3ff ,
( void * ) & V_105 -> V_212 -> V_228 . V_229 . V_225 , 512 ) ;
}
int F_248 ( struct V_104 * V_105 , unsigned long V_87 )
{
if ( ! F_41 ( V_105 -> V_15 , 129 ) )
return 0 ;
F_124 ( ( V_223 * ) & V_105 -> V_212 -> V_228 . V_229 . V_225 ) ;
return F_247 ( V_105 , V_87 ) ;
}
static void F_249 ( struct V_104 * V_105 )
{
F_185 ( V_336 , V_105 ) ;
F_159 ( V_337 , V_105 ) ;
}
static void F_250 ( struct V_15 * V_15 )
{
unsigned int V_106 ;
struct V_104 * V_105 ;
F_43 (i, vcpu, kvm) {
F_249 ( V_105 ) ;
}
}
static void F_251 ( struct V_104 * V_105 )
{
F_185 ( V_337 , V_105 ) ;
F_159 ( V_336 , V_105 ) ;
}
void F_182 ( struct V_104 * V_105 )
{
int V_106 , V_94 , V_406 = 0 ;
if ( ! F_175 ( V_105 ) )
return;
F_252 ( V_105 -> V_203 , 1 ) ;
F_93 ( & V_105 -> V_15 -> V_55 . V_202 ) ;
V_94 = F_32 ( & V_105 -> V_15 -> V_94 ) ;
for ( V_106 = 0 ; V_106 < V_94 ; V_106 ++ ) {
if ( ! F_175 ( V_105 -> V_15 -> V_209 [ V_106 ] ) )
V_406 ++ ;
}
if ( V_406 == 0 ) {
F_251 ( V_105 ) ;
} else if ( V_406 == 1 ) {
F_250 ( V_105 -> V_15 ) ;
}
F_134 ( V_249 , & V_105 -> V_55 . V_123 -> V_233 ) ;
F_160 ( V_334 , V_105 ) ;
F_94 ( & V_105 -> V_15 -> V_55 . V_202 ) ;
return;
}
void F_139 ( struct V_104 * V_105 )
{
int V_106 , V_94 , V_406 = 0 ;
struct V_104 * V_407 = NULL ;
if ( F_175 ( V_105 ) )
return;
F_252 ( V_105 -> V_203 , 0 ) ;
F_93 ( & V_105 -> V_15 -> V_55 . V_202 ) ;
V_94 = F_32 ( & V_105 -> V_15 -> V_94 ) ;
F_253 ( V_105 ) ;
F_132 ( V_249 , & V_105 -> V_55 . V_123 -> V_233 ) ;
F_249 ( V_105 ) ;
for ( V_106 = 0 ; V_106 < V_94 ; V_106 ++ ) {
if ( ! F_175 ( V_105 -> V_15 -> V_209 [ V_106 ] ) ) {
V_406 ++ ;
V_407 = V_105 -> V_15 -> V_209 [ V_106 ] ;
}
}
if ( V_406 == 1 ) {
F_251 ( V_407 ) ;
}
F_94 ( & V_105 -> V_15 -> V_55 . V_202 ) ;
return;
}
static int F_254 ( struct V_104 * V_105 ,
struct V_70 * V_71 )
{
int V_17 ;
if ( V_71 -> V_72 )
return - V_14 ;
switch ( V_71 -> V_71 ) {
case V_26 :
if ( ! V_105 -> V_15 -> V_55 . V_201 ) {
V_105 -> V_15 -> V_55 . V_201 = 1 ;
F_255 ( V_105 -> V_15 ) ;
}
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
static long F_256 ( struct V_104 * V_105 ,
struct V_408 * V_409 )
{
void V_86 * V_410 = ( void V_86 * ) V_409 -> V_411 ;
void * V_412 = NULL ;
int V_17 , V_371 ;
const V_85 V_413 = V_414
| V_415 ;
if ( V_409 -> V_72 & ~ V_413 )
return - V_14 ;
if ( V_409 -> V_416 > V_39 )
return - V_99 ;
if ( ! ( V_409 -> V_72 & V_415 ) ) {
V_412 = F_71 ( V_409 -> V_416 ) ;
if ( ! V_412 )
return - V_102 ;
}
V_371 = F_33 ( & V_105 -> V_15 -> V_97 ) ;
switch ( V_409 -> V_417 ) {
case V_418 :
if ( V_409 -> V_72 & V_415 ) {
V_17 = F_257 ( V_105 , V_409 -> V_419 , V_409 -> V_420 , V_409 -> V_416 , false ) ;
break;
}
V_17 = F_216 ( V_105 , V_409 -> V_419 , V_409 -> V_420 , V_412 , V_409 -> V_416 ) ;
if ( V_17 == 0 ) {
if ( F_54 ( V_410 , V_412 , V_409 -> V_416 ) )
V_17 = - V_88 ;
}
break;
case V_421 :
if ( V_409 -> V_72 & V_415 ) {
V_17 = F_257 ( V_105 , V_409 -> V_419 , V_409 -> V_420 , V_409 -> V_416 , true ) ;
break;
}
if ( F_47 ( V_412 , V_410 , V_409 -> V_416 ) ) {
V_17 = - V_88 ;
break;
}
V_17 = F_258 ( V_105 , V_409 -> V_419 , V_409 -> V_420 , V_412 , V_409 -> V_416 ) ;
break;
default:
V_17 = - V_14 ;
}
F_35 ( & V_105 -> V_15 -> V_97 , V_371 ) ;
if ( V_17 > 0 && ( V_409 -> V_72 & V_414 ) != 0 )
F_259 ( V_105 , & V_105 -> V_55 . V_422 ) ;
F_260 ( V_412 ) ;
return V_17 ;
}
long F_261 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_104 * V_105 = V_10 -> V_157 ;
void V_86 * V_158 = ( void V_86 * ) V_12 ;
int V_90 ;
long V_17 ;
switch ( V_11 ) {
case V_423 : {
struct V_345 V_424 ;
V_17 = - V_88 ;
if ( F_47 ( & V_424 , V_158 , sizeof( V_424 ) ) )
break;
V_17 = F_191 ( V_105 , & V_424 ) ;
break;
}
case V_159 : {
struct V_160 V_161 ;
struct V_345 V_424 ;
V_17 = - V_88 ;
if ( F_47 ( & V_161 , V_158 , sizeof( V_161 ) ) )
break;
if ( F_262 ( & V_161 , & V_424 ) )
return - V_14 ;
V_17 = F_191 ( V_105 , & V_424 ) ;
break;
}
case V_425 :
V_90 = F_33 ( & V_105 -> V_15 -> V_97 ) ;
V_17 = F_246 ( V_105 , V_12 ) ;
F_35 ( & V_105 -> V_15 -> V_97 , V_90 ) ;
break;
case V_426 : {
T_6 V_306 ;
V_17 = - V_88 ;
if ( F_47 ( & V_306 , V_158 , sizeof( V_306 ) ) )
break;
V_17 = F_174 ( V_105 , V_306 ) ;
break;
}
case V_427 :
V_17 = F_166 ( V_105 ) ;
break;
case V_428 :
case V_429 : {
struct V_286 V_287 ;
V_17 = - V_88 ;
if ( F_47 ( & V_287 , V_158 , sizeof( V_287 ) ) )
break;
if ( V_11 == V_428 )
V_17 = F_165 ( V_105 , & V_287 ) ;
else
V_17 = F_164 ( V_105 , & V_287 ) ;
break;
}
#ifdef F_14
case V_430 : {
struct V_431 V_432 ;
if ( F_47 ( & V_432 , V_158 , sizeof( V_432 ) ) ) {
V_17 = - V_88 ;
break;
}
if ( ! F_36 ( V_105 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_263 ( V_105 -> V_55 . V_54 , V_432 . V_433 ,
V_432 . V_434 , V_432 . V_435 ) ;
break;
}
case V_436 : {
struct V_431 V_432 ;
if ( F_47 ( & V_432 , V_158 , sizeof( V_432 ) ) ) {
V_17 = - V_88 ;
break;
}
if ( ! F_36 ( V_105 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_264 ( V_105 -> V_55 . V_54 , V_432 . V_434 ,
V_432 . V_435 ) ;
break;
}
#endif
case V_437 : {
V_17 = F_189 ( V_105 -> V_55 . V_54 , V_12 , 0 ) ;
break;
}
case V_162 :
{
struct V_70 V_71 ;
V_17 = - V_88 ;
if ( F_47 ( & V_71 , V_158 , sizeof( V_71 ) ) )
break;
V_17 = F_254 ( V_105 , & V_71 ) ;
break;
}
case V_438 : {
struct V_408 V_439 ;
if ( F_47 ( & V_439 , V_158 , sizeof( V_439 ) ) == 0 )
V_17 = F_256 ( V_105 , & V_439 ) ;
else
V_17 = - V_88 ;
break;
}
case V_440 : {
struct V_441 V_442 ;
V_17 = - V_88 ;
if ( F_47 ( & V_442 , V_158 , sizeof( V_442 ) ) )
break;
if ( V_442 . V_443 > V_444 ||
V_442 . V_443 == 0 ||
V_442 . V_443 % sizeof( struct V_345 ) > 0 ) {
V_17 = - V_14 ;
break;
}
V_17 = F_265 ( V_105 ,
( void V_86 * ) V_442 . V_411 ,
V_442 . V_443 ) ;
break;
}
case V_445 : {
struct V_441 V_442 ;
V_17 = - V_88 ;
if ( F_47 ( & V_442 , V_158 , sizeof( V_442 ) ) )
break;
if ( V_442 . V_443 == 0 ) {
V_17 = - V_14 ;
break;
}
V_17 = F_266 ( V_105 ,
( V_446 V_86 * ) V_442 . V_411 ,
V_442 . V_443 ) ;
break;
}
default:
V_17 = - V_171 ;
}
return V_17 ;
}
int F_267 ( struct V_104 * V_105 , struct V_447 * V_448 )
{
#ifdef F_14
if ( ( V_448 -> V_449 == V_450 )
&& ( F_36 ( V_105 -> V_15 ) ) ) {
V_448 -> V_451 = F_268 ( V_105 -> V_55 . V_123 ) ;
F_269 ( V_448 -> V_451 ) ;
return 0 ;
}
#endif
return V_452 ;
}
int F_270 ( struct V_15 * V_15 , struct V_49 * V_66 ,
unsigned long V_59 )
{
return 0 ;
}
int F_271 ( struct V_15 * V_15 ,
struct V_49 * V_50 ,
const struct V_453 * V_454 ,
enum V_455 V_456 )
{
if ( V_454 -> V_457 & 0xffffful )
return - V_14 ;
if ( V_454 -> V_458 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_272 ( struct V_15 * V_15 ,
const struct V_453 * V_454 ,
const struct V_49 * V_459 ,
const struct V_49 * V_100 ,
enum V_455 V_456 )
{
int V_181 ;
if ( V_459 -> V_457 == V_454 -> V_457 &&
V_459 -> V_58 * V_333 == V_454 -> V_460 &&
V_459 -> V_59 * V_333 == V_454 -> V_458 )
return;
V_181 = F_263 ( V_15 -> V_55 . V_54 , V_454 -> V_457 ,
V_454 -> V_460 , V_454 -> V_458 ) ;
if ( V_181 )
F_273 ( L_12 ) ;
return;
}
static int T_10 F_274 ( void )
{
return F_275 ( NULL , sizeof( struct V_104 ) , 0 , V_461 ) ;
}
static void T_11 F_276 ( void )
{
F_277 () ;
}
