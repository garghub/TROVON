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
V_17 = 1 ;
break;
case V_34 :
case V_35 :
V_17 = V_36 ;
break;
case V_37 :
V_17 = V_38 ;
break;
case V_39 :
V_17 = V_40 ;
break;
default:
V_17 = 0 ;
}
return V_17 ;
}
static void F_15 ( struct V_15 * V_15 ,
struct V_41 * V_42 )
{
T_1 V_43 , V_44 ;
unsigned long V_45 ;
struct V_46 * V_46 = V_15 -> V_47 . V_46 ;
F_16 ( & V_46 -> V_48 -> V_49 ) ;
V_44 = V_42 -> V_50 + V_42 -> V_51 ;
for ( V_43 = V_42 -> V_50 ; V_43 <= V_44 ; V_43 ++ ) {
V_45 = F_17 ( V_42 , V_43 ) ;
if ( F_18 ( V_45 , V_46 ) )
F_19 ( V_15 , V_43 ) ;
}
F_20 ( & V_46 -> V_48 -> V_49 ) ;
}
int F_21 ( struct V_15 * V_15 ,
struct V_52 * log )
{
int V_17 ;
unsigned long V_53 ;
struct V_41 * V_42 ;
int V_54 = 0 ;
F_22 ( & V_15 -> V_55 ) ;
V_17 = - V_14 ;
if ( log -> V_56 >= V_38 )
goto V_57;
V_42 = F_23 ( V_15 -> V_58 , log -> V_56 ) ;
V_17 = - V_59 ;
if ( ! V_42 -> V_60 )
goto V_57;
F_15 ( V_15 , V_42 ) ;
V_17 = F_24 ( V_15 , log , & V_54 ) ;
if ( V_17 )
goto V_57;
if ( V_54 ) {
V_53 = F_25 ( V_42 ) ;
memset ( V_42 -> V_60 , 0 , V_53 ) ;
}
V_17 = 0 ;
V_57:
F_26 ( & V_15 -> V_55 ) ;
return V_17 ;
}
static int F_27 ( struct V_15 * V_15 , struct V_61 * V_62 )
{
int V_17 ;
if ( V_62 -> V_63 )
return - V_14 ;
switch ( V_62 -> V_62 ) {
case V_30 :
V_15 -> V_47 . V_64 = 1 ;
V_17 = 0 ;
break;
case V_33 :
V_15 -> V_47 . V_65 = 1 ;
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
static int F_28 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 ;
switch ( V_67 -> V_67 ) {
case V_69 :
V_68 = 0 ;
if ( F_29 ( V_15 -> V_47 . V_46 -> V_70 , ( V_71 V_72 * ) V_67 -> V_73 ) )
V_68 = - V_74 ;
break;
default:
V_68 = - V_75 ;
break;
}
return V_68 ;
}
static int F_30 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 ;
unsigned int V_76 ;
switch ( V_67 -> V_67 ) {
case V_77 :
V_68 = - V_78 ;
F_22 ( & V_15 -> V_79 ) ;
if ( F_31 ( & V_15 -> V_80 ) == 0 ) {
V_15 -> V_47 . V_81 = 1 ;
V_68 = 0 ;
}
F_26 ( & V_15 -> V_79 ) ;
break;
case V_82 :
F_22 ( & V_15 -> V_79 ) ;
V_76 = F_32 ( & V_15 -> V_83 ) ;
F_33 ( V_15 -> V_47 . V_46 -> V_48 ) ;
F_34 ( & V_15 -> V_83 , V_76 ) ;
F_26 ( & V_15 -> V_79 ) ;
V_68 = 0 ;
break;
case V_69 : {
unsigned long V_84 ;
if ( F_35 ( V_15 ) )
return - V_14 ;
if ( F_36 ( V_84 , ( V_71 V_72 * ) V_67 -> V_73 ) )
return - V_74 ;
if ( V_84 > V_15 -> V_47 . V_46 -> V_70 )
return - V_85 ;
V_68 = - V_78 ;
F_22 ( & V_15 -> V_79 ) ;
if ( F_31 ( & V_15 -> V_80 ) == 0 ) {
struct V_46 * V_86 = F_37 ( V_87 -> V_48 , V_84 ) ;
if ( ! V_86 ) {
V_68 = - V_88 ;
} else {
F_38 ( V_15 -> V_47 . V_46 ) ;
V_86 -> V_89 = V_15 ;
V_15 -> V_47 . V_46 = V_86 ;
V_68 = 0 ;
}
}
F_26 ( & V_15 -> V_79 ) ;
break;
}
default:
V_68 = - V_75 ;
break;
}
return V_68 ;
}
static int F_39 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
struct V_90 * V_91 ;
int V_92 ;
if ( ! F_40 ( V_15 , 76 ) )
return - V_14 ;
F_22 ( & V_15 -> V_79 ) ;
switch ( V_67 -> V_67 ) {
case V_93 :
F_41 (
V_15 -> V_47 . V_94 . V_95 -> V_96 ,
sizeof( V_15 -> V_47 . V_94 . V_95 -> V_96 ) ) ;
V_15 -> V_47 . V_94 . V_97 = 1 ;
break;
case V_98 :
F_41 (
V_15 -> V_47 . V_94 . V_95 -> V_99 ,
sizeof( V_15 -> V_47 . V_94 . V_95 -> V_99 ) ) ;
V_15 -> V_47 . V_94 . V_100 = 1 ;
break;
case V_101 :
V_15 -> V_47 . V_94 . V_97 = 0 ;
memset ( V_15 -> V_47 . V_94 . V_95 -> V_96 , 0 ,
sizeof( V_15 -> V_47 . V_94 . V_95 -> V_96 ) ) ;
break;
case V_102 :
V_15 -> V_47 . V_94 . V_100 = 0 ;
memset ( V_15 -> V_47 . V_94 . V_95 -> V_99 , 0 ,
sizeof( V_15 -> V_47 . V_94 . V_95 -> V_99 ) ) ;
break;
default:
F_26 ( & V_15 -> V_79 ) ;
return - V_75 ;
}
F_42 (i, vcpu, kvm) {
F_43 ( V_91 ) ;
F_44 ( V_91 ) ;
}
F_26 ( & V_15 -> V_79 ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
T_2 V_103 ;
if ( F_46 ( & V_103 , ( void V_72 * ) V_67 -> V_73 ,
sizeof( V_103 ) ) )
return - V_74 ;
if ( V_103 != 0 )
return - V_14 ;
return 0 ;
}
static int F_47 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
struct V_90 * V_104 ;
unsigned int V_105 ;
V_71 V_106 , V_107 ;
int V_17 ;
if ( F_46 ( & V_107 , ( void V_72 * ) V_67 -> V_73 , sizeof( V_107 ) ) )
return - V_74 ;
V_17 = F_48 ( & V_106 ) ;
if ( V_17 )
return V_17 ;
F_22 ( & V_15 -> V_79 ) ;
V_15 -> V_47 . V_108 = V_107 - V_106 ;
F_42 (vcpu_idx, cur_vcpu, kvm) {
V_104 -> V_47 . V_109 -> V_108 = V_15 -> V_47 . V_108 ;
F_44 ( V_104 ) ;
}
F_26 ( & V_15 -> V_79 ) ;
return 0 ;
}
static int F_49 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 ;
if ( V_67 -> V_63 )
return - V_14 ;
switch ( V_67 -> V_67 ) {
case V_110 :
V_68 = F_45 ( V_15 , V_67 ) ;
break;
case V_111 :
V_68 = F_47 ( V_15 , V_67 ) ;
break;
default:
V_68 = - V_75 ;
break;
}
return V_68 ;
}
static int F_50 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
T_2 V_103 = 0 ;
if ( F_51 ( ( void V_72 * ) V_67 -> V_73 , & V_103 ,
sizeof( V_103 ) ) )
return - V_74 ;
return 0 ;
}
static int F_52 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
V_71 V_106 , V_107 ;
int V_17 ;
V_17 = F_48 ( & V_106 ) ;
if ( V_17 )
return V_17 ;
V_107 = V_106 + V_15 -> V_47 . V_108 ;
if ( F_51 ( ( void V_72 * ) V_67 -> V_73 , & V_107 , sizeof( V_107 ) ) )
return - V_74 ;
return 0 ;
}
static int F_53 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 ;
if ( V_67 -> V_63 )
return - V_14 ;
switch ( V_67 -> V_67 ) {
case V_110 :
V_68 = F_50 ( V_15 , V_67 ) ;
break;
case V_111 :
V_68 = F_52 ( V_15 , V_67 ) ;
break;
default:
V_68 = - V_75 ;
break;
}
return V_68 ;
}
static int F_54 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
struct V_112 * V_113 ;
int V_68 = 0 ;
F_22 ( & V_15 -> V_79 ) ;
if ( F_31 ( & V_15 -> V_80 ) ) {
V_68 = - V_78 ;
goto V_57;
}
V_113 = F_55 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 ) {
V_68 = - V_88 ;
goto V_57;
}
if ( ! F_46 ( V_113 , ( void V_72 * ) V_67 -> V_73 ,
sizeof( * V_113 ) ) ) {
memcpy ( & V_15 -> V_47 . V_115 . V_116 , & V_113 -> V_117 ,
sizeof( struct V_117 ) ) ;
V_15 -> V_47 . V_115 . V_118 = V_113 -> V_118 ;
memcpy ( V_15 -> V_47 . V_115 . V_119 -> V_120 , V_113 -> V_121 ,
V_122 ) ;
} else
V_68 = - V_74 ;
F_56 ( V_113 ) ;
V_57:
F_26 ( & V_15 -> V_79 ) ;
return V_68 ;
}
static int F_57 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 = - V_75 ;
switch ( V_67 -> V_67 ) {
case V_123 :
V_68 = F_54 ( V_15 , V_67 ) ;
break;
}
return V_68 ;
}
static int F_58 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
struct V_112 * V_113 ;
int V_68 = 0 ;
V_113 = F_55 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 ) {
V_68 = - V_88 ;
goto V_57;
}
memcpy ( & V_113 -> V_117 , & V_15 -> V_47 . V_115 . V_116 , sizeof( struct V_117 ) ) ;
V_113 -> V_118 = V_15 -> V_47 . V_115 . V_118 ;
memcpy ( & V_113 -> V_121 , V_15 -> V_47 . V_115 . V_119 -> V_120 , V_122 ) ;
if ( F_51 ( ( void V_72 * ) V_67 -> V_73 , V_113 , sizeof( * V_113 ) ) )
V_68 = - V_74 ;
F_56 ( V_113 ) ;
V_57:
return V_68 ;
}
static int F_59 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
struct V_124 * V_125 ;
int V_68 = 0 ;
V_125 = F_55 ( sizeof( * V_125 ) , V_114 ) ;
if ( ! V_125 ) {
V_68 = - V_88 ;
goto V_57;
}
F_60 ( (struct V_117 * ) & V_125 -> V_117 ) ;
V_125 -> V_118 = F_61 () ;
memcpy ( & V_125 -> V_126 , V_15 -> V_47 . V_115 . V_119 -> V_127 ,
V_122 ) ;
memcpy ( ( unsigned long * ) & V_125 -> V_121 , V_128 . V_129 ,
V_122 ) ;
if ( F_51 ( ( void V_72 * ) V_67 -> V_73 , V_125 , sizeof( * V_125 ) ) )
V_68 = - V_74 ;
F_56 ( V_125 ) ;
V_57:
return V_68 ;
}
static int F_62 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 = - V_75 ;
switch ( V_67 -> V_67 ) {
case V_123 :
V_68 = F_58 ( V_15 , V_67 ) ;
break;
case V_130 :
V_68 = F_59 ( V_15 , V_67 ) ;
break;
}
return V_68 ;
}
static int F_63 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 ;
switch ( V_67 -> V_131 ) {
case V_132 :
V_68 = F_30 ( V_15 , V_67 ) ;
break;
case V_133 :
V_68 = F_49 ( V_15 , V_67 ) ;
break;
case V_134 :
V_68 = F_57 ( V_15 , V_67 ) ;
break;
case V_135 :
V_68 = F_39 ( V_15 , V_67 ) ;
break;
default:
V_68 = - V_75 ;
break;
}
return V_68 ;
}
static int F_64 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 ;
switch ( V_67 -> V_131 ) {
case V_132 :
V_68 = F_28 ( V_15 , V_67 ) ;
break;
case V_133 :
V_68 = F_53 ( V_15 , V_67 ) ;
break;
case V_134 :
V_68 = F_62 ( V_15 , V_67 ) ;
break;
default:
V_68 = - V_75 ;
break;
}
return V_68 ;
}
static int F_65 ( struct V_15 * V_15 , struct V_66 * V_67 )
{
int V_68 ;
switch ( V_67 -> V_131 ) {
case V_132 :
switch ( V_67 -> V_67 ) {
case V_77 :
case V_82 :
case V_69 :
V_68 = 0 ;
break;
default:
V_68 = - V_75 ;
break;
}
break;
case V_133 :
switch ( V_67 -> V_67 ) {
case V_111 :
case V_110 :
V_68 = 0 ;
break;
default:
V_68 = - V_75 ;
break;
}
break;
case V_134 :
switch ( V_67 -> V_67 ) {
case V_123 :
case V_130 :
V_68 = 0 ;
break;
default:
V_68 = - V_75 ;
break;
}
break;
case V_135 :
switch ( V_67 -> V_67 ) {
case V_93 :
case V_98 :
case V_101 :
case V_102 :
V_68 = 0 ;
break;
default:
V_68 = - V_75 ;
break;
}
break;
default:
V_68 = - V_75 ;
break;
}
return V_68 ;
}
long F_66 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_15 * V_15 = V_10 -> V_136 ;
void V_72 * V_137 = ( void V_72 * ) V_12 ;
struct V_66 V_67 ;
int V_17 ;
switch ( V_11 ) {
case V_138 : {
struct V_139 V_140 ;
V_17 = - V_74 ;
if ( F_46 ( & V_140 , V_137 , sizeof( V_140 ) ) )
break;
V_17 = F_67 ( V_15 , & V_140 ) ;
break;
}
case V_141 : {
struct V_61 V_62 ;
V_17 = - V_74 ;
if ( F_46 ( & V_62 , V_137 , sizeof( V_62 ) ) )
break;
V_17 = F_27 ( V_15 , & V_62 ) ;
break;
}
case V_142 : {
struct V_143 V_144 ;
V_17 = - V_14 ;
if ( V_15 -> V_47 . V_64 ) {
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
F_68 ( V_15 , & V_144 , 0 , 0 ) ;
V_17 = 0 ;
}
break;
}
case V_145 : {
V_17 = - V_74 ;
if ( F_46 ( & V_67 , ( void V_72 * ) V_12 , sizeof( V_67 ) ) )
break;
V_17 = F_63 ( V_15 , & V_67 ) ;
break;
}
case V_146 : {
V_17 = - V_74 ;
if ( F_46 ( & V_67 , ( void V_72 * ) V_12 , sizeof( V_67 ) ) )
break;
V_17 = F_64 ( V_15 , & V_67 ) ;
break;
}
case V_147 : {
V_17 = - V_74 ;
if ( F_46 ( & V_67 , ( void V_72 * ) V_12 , sizeof( V_67 ) ) )
break;
V_17 = F_65 ( V_15 , & V_67 ) ;
break;
}
default:
V_17 = - V_148 ;
}
return V_17 ;
}
static int F_69 ( T_2 * V_149 )
{
T_3 V_150 = 0x04000000UL ;
T_3 V_151 = 0 ;
memset ( V_149 , 0 , 128 ) ;
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
return V_151 ;
}
static int F_70 ( void )
{
T_2 V_149 [ 128 ] ;
int V_151 ;
if ( F_71 ( 2 ) && F_71 ( 12 ) ) {
V_151 = F_69 ( V_149 ) ;
if ( V_151 )
F_72 ( L_1 , V_151 ) ;
else
return V_149 [ 0 ] & 0x40 ;
}
return 0 ;
}
static void F_73 ( struct V_15 * V_15 )
{
V_15 -> V_47 . V_94 . V_152 = ( V_153 ) ( unsigned long ) V_15 -> V_47 . V_94 . V_95 ;
if ( F_70 () )
V_15 -> V_47 . V_94 . V_152 |= V_154 ;
else
V_15 -> V_47 . V_94 . V_152 |= V_155 ;
}
static void F_74 ( struct V_117 * V_116 )
{
F_60 ( V_116 ) ;
V_116 -> V_156 = 0xff ;
}
static int F_75 ( struct V_15 * V_15 )
{
if ( ! F_40 ( V_15 , 76 ) )
return 0 ;
V_15 -> V_47 . V_94 . V_95 = F_55 ( sizeof( * V_15 -> V_47 . V_94 . V_95 ) ,
V_114 | V_157 ) ;
if ( ! V_15 -> V_47 . V_94 . V_95 )
return - V_88 ;
F_73 ( V_15 ) ;
V_15 -> V_47 . V_94 . V_97 = 1 ;
V_15 -> V_47 . V_94 . V_100 = 1 ;
F_41 ( V_15 -> V_47 . V_94 . V_95 -> V_96 ,
sizeof( V_15 -> V_47 . V_94 . V_95 -> V_96 ) ) ;
F_41 ( V_15 -> V_47 . V_94 . V_95 -> V_99 ,
sizeof( V_15 -> V_47 . V_94 . V_95 -> V_99 ) ) ;
return 0 ;
}
int F_76 ( struct V_15 * V_15 , unsigned long type )
{
int V_92 , V_158 ;
char V_159 [ 16 ] ;
static unsigned long V_160 ;
V_158 = - V_14 ;
#ifdef F_14
if ( type & ~ V_161 )
goto V_162;
if ( ( type & V_161 ) && ( ! F_77 ( V_163 ) ) )
goto V_162;
#else
if ( type )
goto V_162;
#endif
V_158 = F_12 () ;
if ( V_158 )
goto V_162;
V_158 = - V_88 ;
V_15 -> V_47 . V_164 = (struct V_165 * ) F_78 ( V_114 ) ;
if ( ! V_15 -> V_47 . V_164 )
goto V_162;
F_79 ( & V_166 ) ;
V_160 = ( V_160 + 16 ) & 0x7f0 ;
V_15 -> V_47 . V_164 = (struct V_165 * ) ( ( char * ) V_15 -> V_47 . V_164 + V_160 ) ;
F_80 ( & V_166 ) ;
sprintf ( V_159 , L_2 , V_87 -> V_167 ) ;
V_15 -> V_47 . V_168 = F_81 ( V_159 , 8 , 2 , 8 * sizeof( long ) ) ;
if ( ! V_15 -> V_47 . V_168 )
goto V_169;
V_15 -> V_47 . V_115 . V_119 =
(struct V_170 * ) F_78 ( V_114 | V_157 ) ;
if ( ! V_15 -> V_47 . V_115 . V_119 )
goto V_171;
memcpy ( V_15 -> V_47 . V_115 . V_119 -> V_127 , V_128 . V_129 ,
V_122 ) ;
for ( V_92 = 0 ; V_92 < V_172 ; V_92 ++ ) {
if ( V_92 < F_1 () )
V_15 -> V_47 . V_115 . V_119 -> V_127 [ V_92 ] &= V_1 [ V_92 ] ;
else
V_15 -> V_47 . V_115 . V_119 -> V_127 [ V_92 ] = 0UL ;
}
memcpy ( V_15 -> V_47 . V_115 . V_119 -> V_120 , V_15 -> V_47 . V_115 . V_119 -> V_127 ,
V_122 ) ;
F_74 ( & V_15 -> V_47 . V_115 . V_116 ) ;
V_15 -> V_47 . V_115 . V_118 = F_61 () & 0x0fff ;
if ( F_75 ( V_15 ) < 0 )
goto V_173;
F_82 ( & V_15 -> V_47 . V_174 . V_79 ) ;
F_83 ( & V_15 -> V_47 . V_174 . V_120 ) ;
F_84 ( & V_15 -> V_47 . V_175 ) ;
F_85 ( & V_15 -> V_47 . V_176 ) ;
F_86 ( V_15 -> V_47 . V_168 , & V_177 ) ;
F_87 ( V_15 , 3 , L_3 , L_4 ) ;
if ( type & V_161 ) {
V_15 -> V_47 . V_46 = NULL ;
} else {
V_15 -> V_47 . V_46 = F_37 ( V_87 -> V_48 , ( 1UL << 44 ) - 1 ) ;
if ( ! V_15 -> V_47 . V_46 )
goto V_178;
V_15 -> V_47 . V_46 -> V_89 = V_15 ;
V_15 -> V_47 . V_46 -> V_179 = 0 ;
}
V_15 -> V_47 . V_180 = 0 ;
V_15 -> V_47 . V_64 = 0 ;
V_15 -> V_47 . V_108 = 0 ;
F_82 ( & V_15 -> V_47 . V_181 ) ;
return 0 ;
V_178:
F_56 ( V_15 -> V_47 . V_94 . V_95 ) ;
V_173:
F_88 ( ( unsigned long ) V_15 -> V_47 . V_115 . V_119 ) ;
V_171:
F_89 ( V_15 -> V_47 . V_168 ) ;
V_169:
F_88 ( ( unsigned long ) ( V_15 -> V_47 . V_164 ) ) ;
V_162:
return V_158 ;
}
void F_90 ( struct V_90 * V_91 )
{
F_91 ( V_91 , 3 , L_3 , L_5 ) ;
F_92 ( V_91 -> V_182 ) ;
F_93 ( V_91 ) ;
F_94 ( V_91 ) ;
if ( ! F_35 ( V_91 -> V_15 ) ) {
F_95 ( 63 - V_91 -> V_182 ,
( unsigned long * ) & V_91 -> V_15 -> V_47 . V_164 -> V_183 ) ;
if ( V_91 -> V_15 -> V_47 . V_164 -> V_184 [ V_91 -> V_182 ] . V_185 ==
( V_186 ) V_91 -> V_47 . V_109 )
V_91 -> V_15 -> V_47 . V_164 -> V_184 [ V_91 -> V_182 ] . V_185 = 0 ;
}
F_96 () ;
if ( F_35 ( V_91 -> V_15 ) )
F_38 ( V_91 -> V_47 . V_46 ) ;
if ( F_97 ( V_91 -> V_15 ) )
F_98 ( V_91 ) ;
F_88 ( ( unsigned long ) ( V_91 -> V_47 . V_109 ) ) ;
F_99 ( V_91 ) ;
F_100 ( V_187 , V_91 ) ;
}
static void F_101 ( struct V_15 * V_15 )
{
unsigned int V_92 ;
struct V_90 * V_91 ;
F_42 (i, vcpu, kvm)
F_90 ( V_91 ) ;
F_22 ( & V_15 -> V_79 ) ;
for ( V_92 = 0 ; V_92 < F_31 ( & V_15 -> V_80 ) ; V_92 ++ )
V_15 -> V_188 [ V_92 ] = NULL ;
F_102 ( & V_15 -> V_80 , 0 ) ;
F_26 ( & V_15 -> V_79 ) ;
}
void F_103 ( struct V_15 * V_15 )
{
F_101 ( V_15 ) ;
F_88 ( ( unsigned long ) V_15 -> V_47 . V_115 . V_119 ) ;
F_88 ( ( unsigned long ) ( V_15 -> V_47 . V_164 ) ) ;
F_89 ( V_15 -> V_47 . V_168 ) ;
F_56 ( V_15 -> V_47 . V_94 . V_95 ) ;
if ( ! F_35 ( V_15 ) )
F_38 ( V_15 -> V_47 . V_46 ) ;
F_104 ( V_15 ) ;
F_105 ( V_15 ) ;
}
static int F_106 ( struct V_90 * V_91 )
{
V_91 -> V_47 . V_46 = F_37 ( V_87 -> V_48 , - 1UL ) ;
if ( ! V_91 -> V_47 . V_46 )
return - V_88 ;
V_91 -> V_47 . V_46 -> V_89 = V_91 -> V_15 ;
return 0 ;
}
int F_107 ( struct V_90 * V_91 )
{
V_91 -> V_47 . V_189 = V_190 ;
F_94 ( V_91 ) ;
V_91 -> V_191 -> V_192 = V_193 |
V_194 |
V_195 |
V_196 |
V_197 |
V_198 ;
if ( F_35 ( V_91 -> V_15 ) )
return F_106 ( V_91 ) ;
return 0 ;
}
void F_108 ( struct V_90 * V_91 , int V_184 )
{
F_109 ( & V_91 -> V_47 . V_199 . V_200 ) ;
F_110 ( V_91 -> V_47 . V_199 . V_201 ) ;
F_111 ( V_91 -> V_47 . V_202 ) ;
F_112 ( & V_91 -> V_47 . V_203 . V_200 ) ;
F_113 ( V_91 -> V_47 . V_203 . V_201 ) ;
F_114 ( V_91 -> V_191 -> V_204 . V_205 . V_206 ) ;
F_115 ( V_91 -> V_47 . V_46 ) ;
F_116 ( V_207 , & V_91 -> V_47 . V_109 -> V_208 ) ;
}
void F_117 ( struct V_90 * V_91 )
{
F_118 ( V_207 , & V_91 -> V_47 . V_109 -> V_208 ) ;
F_119 ( V_91 -> V_47 . V_46 ) ;
F_109 ( & V_91 -> V_47 . V_203 . V_200 ) ;
F_110 ( V_91 -> V_47 . V_203 . V_201 ) ;
F_111 ( V_91 -> V_191 -> V_204 . V_205 . V_206 ) ;
F_112 ( & V_91 -> V_47 . V_199 . V_200 ) ;
F_113 ( V_91 -> V_47 . V_199 . V_201 ) ;
F_114 ( V_91 -> V_47 . V_202 ) ;
}
static void F_120 ( struct V_90 * V_91 )
{
V_91 -> V_47 . V_109 -> V_209 . V_127 = 0UL ;
V_91 -> V_47 . V_109 -> V_209 . V_73 = 0UL ;
F_121 ( V_91 , 0 ) ;
V_91 -> V_47 . V_109 -> V_210 = 0UL ;
V_91 -> V_47 . V_109 -> V_211 = 0UL ;
V_91 -> V_47 . V_109 -> V_212 = 0 ;
memset ( V_91 -> V_47 . V_109 -> V_213 , 0 , 16 * sizeof( V_186 ) ) ;
V_91 -> V_47 . V_109 -> V_213 [ 0 ] = 0xE0UL ;
V_91 -> V_47 . V_109 -> V_213 [ 14 ] = 0xC2000000UL ;
V_91 -> V_47 . V_203 . V_200 = 0 ;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
V_91 -> V_47 . V_109 -> V_214 = 1 ;
V_91 -> V_47 . V_109 -> V_215 = 0 ;
V_91 -> V_47 . V_189 = V_190 ;
F_94 ( V_91 ) ;
if ( ! F_122 ( V_91 -> V_15 ) )
F_123 ( V_91 ) ;
F_93 ( V_91 ) ;
}
void F_124 ( struct V_90 * V_91 )
{
F_22 ( & V_91 -> V_15 -> V_79 ) ;
V_91 -> V_47 . V_109 -> V_108 = V_91 -> V_15 -> V_47 . V_108 ;
F_26 ( & V_91 -> V_15 -> V_79 ) ;
if ( ! F_35 ( V_91 -> V_15 ) )
V_91 -> V_47 . V_46 = V_91 -> V_15 -> V_47 . V_46 ;
}
static void F_43 ( struct V_90 * V_91 )
{
if ( ! F_40 ( V_91 -> V_15 , 76 ) )
return;
V_91 -> V_47 . V_109 -> V_216 &= ~ ( V_217 | V_218 ) ;
if ( V_91 -> V_15 -> V_47 . V_94 . V_97 )
V_91 -> V_47 . V_109 -> V_216 |= V_217 ;
if ( V_91 -> V_15 -> V_47 . V_94 . V_100 )
V_91 -> V_47 . V_109 -> V_216 |= V_218 ;
V_91 -> V_47 . V_109 -> V_152 = V_91 -> V_15 -> V_47 . V_94 . V_152 ;
}
void F_98 ( struct V_90 * V_91 )
{
F_88 ( V_91 -> V_47 . V_109 -> V_219 ) ;
V_91 -> V_47 . V_109 -> V_219 = 0 ;
}
int F_125 ( struct V_90 * V_91 )
{
V_91 -> V_47 . V_109 -> V_219 = F_78 ( V_114 ) ;
if ( ! V_91 -> V_47 . V_109 -> V_219 )
return - V_88 ;
V_91 -> V_47 . V_109 -> V_220 |= 0x80 ;
V_91 -> V_47 . V_109 -> V_220 &= ~ 0x08 ;
return 0 ;
}
int F_126 ( struct V_90 * V_91 )
{
int V_158 = 0 ;
F_102 ( & V_91 -> V_47 . V_109 -> V_208 , V_221 |
V_222 |
V_223 |
V_224 ) ;
V_91 -> V_47 . V_109 -> V_225 = 6 ;
if ( F_40 ( V_91 -> V_15 , 50 ) && F_40 ( V_91 -> V_15 , 73 ) )
V_91 -> V_47 . V_109 -> V_225 |= 0x10 ;
V_91 -> V_47 . V_109 -> V_220 = 8 ;
V_91 -> V_47 . V_109 -> V_226 = 0xC1002000U ;
if ( F_127 () )
V_91 -> V_47 . V_109 -> V_226 |= 1 ;
if ( F_128 () )
V_91 -> V_47 . V_109 -> V_226 |= 0x10000000U ;
V_91 -> V_47 . V_109 -> V_227 |= V_228 | V_229 | V_230 |
V_231 ;
if ( F_97 ( V_91 -> V_15 ) ) {
V_158 = F_125 ( V_91 ) ;
if ( V_158 )
return V_158 ;
}
F_129 ( & V_91 -> V_47 . V_232 , V_233 , V_234 ) ;
V_91 -> V_47 . V_232 . V_235 = V_236 ;
F_22 ( & V_91 -> V_15 -> V_79 ) ;
V_91 -> V_47 . V_116 = V_91 -> V_15 -> V_47 . V_115 . V_116 ;
V_91 -> V_47 . V_109 -> V_118 = V_91 -> V_15 -> V_47 . V_115 . V_118 ;
F_26 ( & V_91 -> V_15 -> V_79 ) ;
F_43 ( V_91 ) ;
return V_158 ;
}
struct V_90 * F_130 ( struct V_15 * V_15 ,
unsigned int V_237 )
{
struct V_90 * V_91 ;
struct V_238 * V_238 ;
int V_158 = - V_14 ;
if ( V_237 >= V_36 )
goto V_57;
V_158 = - V_88 ;
V_91 = F_131 ( V_187 , V_114 ) ;
if ( ! V_91 )
goto V_57;
V_238 = (struct V_238 * ) F_78 ( V_114 ) ;
if ( ! V_238 )
goto V_239;
V_91 -> V_47 . V_109 = & V_238 -> V_109 ;
V_91 -> V_47 . V_109 -> V_240 = ( unsigned long ) & V_238 -> V_241 ;
V_91 -> V_47 . V_109 -> V_242 = V_237 ;
if ( ! F_35 ( V_15 ) ) {
if ( ! V_15 -> V_47 . V_164 ) {
F_132 ( 1 ) ;
goto V_239;
}
if ( ! V_15 -> V_47 . V_164 -> V_184 [ V_237 ] . V_185 )
V_15 -> V_47 . V_164 -> V_184 [ V_237 ] . V_185 =
( V_186 ) V_91 -> V_47 . V_109 ;
V_91 -> V_47 . V_109 -> V_243 =
( V_153 ) ( ( ( V_186 ) V_15 -> V_47 . V_164 ) >> 32 ) ;
V_91 -> V_47 . V_109 -> V_244 = ( V_153 ) ( V_186 ) V_15 -> V_47 . V_164 ;
F_133 ( 63 - V_237 , ( unsigned long * ) & V_15 -> V_47 . V_164 -> V_183 ) ;
}
V_91 -> V_47 . V_109 -> V_119 = ( int ) ( long ) V_15 -> V_47 . V_115 . V_119 -> V_120 ;
F_82 ( & V_91 -> V_47 . V_245 . V_79 ) ;
V_91 -> V_47 . V_245 . V_174 = & V_15 -> V_47 . V_174 ;
V_91 -> V_47 . V_245 . V_246 = & V_91 -> V_246 ;
V_91 -> V_47 . V_245 . V_208 = & V_91 -> V_47 . V_109 -> V_208 ;
V_158 = F_134 ( V_91 , V_15 , V_237 ) ;
if ( V_158 )
goto V_247;
F_87 ( V_15 , 3 , L_6 , V_237 , V_91 ,
V_91 -> V_47 . V_109 ) ;
F_135 ( V_237 , V_91 , V_91 -> V_47 . V_109 ) ;
return V_91 ;
V_247:
F_88 ( ( unsigned long ) ( V_91 -> V_47 . V_109 ) ) ;
V_239:
F_100 ( V_187 , V_91 ) ;
V_57:
return F_136 ( V_158 ) ;
}
int F_137 ( struct V_90 * V_91 )
{
return F_138 ( V_91 , 0 ) ;
}
void F_139 ( struct V_90 * V_91 )
{
F_116 ( V_248 , & V_91 -> V_47 . V_109 -> V_249 ) ;
}
void F_140 ( struct V_90 * V_91 )
{
F_118 ( V_248 , & V_91 -> V_47 . V_109 -> V_249 ) ;
}
void F_44 ( struct V_90 * V_91 )
{
F_116 ( V_250 , & V_91 -> V_47 . V_109 -> V_208 ) ;
while ( V_91 -> V_47 . V_109 -> V_251 & V_252 )
F_141 () ;
}
void F_142 ( struct V_90 * V_91 )
{
F_139 ( V_91 ) ;
F_44 ( V_91 ) ;
}
static void V_5 ( struct V_46 * V_46 , unsigned long V_45 )
{
int V_92 ;
struct V_15 * V_15 = V_46 -> V_89 ;
struct V_90 * V_91 ;
F_42 (i, vcpu, kvm) {
if ( F_143 ( V_91 ) == ( V_45 & ~ 0x1000UL ) ) {
F_91 ( V_91 , 2 , L_7 , V_45 ) ;
F_144 ( V_253 , V_91 ) ;
F_142 ( V_91 ) ;
}
}
}
int F_145 ( struct V_90 * V_91 )
{
F_146 () ;
return 0 ;
}
static int F_147 ( struct V_90 * V_91 ,
struct V_254 * V_255 )
{
int V_17 = - V_14 ;
switch ( V_255 -> V_237 ) {
case V_256 :
V_17 = F_29 ( V_91 -> V_47 . V_109 -> V_212 ,
( T_3 V_72 * ) V_255 -> V_73 ) ;
break;
case V_257 :
V_17 = F_29 ( V_91 -> V_47 . V_109 -> V_108 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_258 :
V_17 = F_29 ( V_91 -> V_47 . V_109 -> V_210 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_259 :
V_17 = F_29 ( V_91 -> V_47 . V_109 -> V_211 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_260 :
V_17 = F_29 ( V_91 -> V_47 . V_189 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_261 :
V_17 = F_29 ( V_91 -> V_47 . V_262 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_263 :
V_17 = F_29 ( V_91 -> V_47 . V_264 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_265 :
V_17 = F_29 ( V_91 -> V_47 . V_109 -> V_215 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_266 :
V_17 = F_29 ( V_91 -> V_47 . V_109 -> V_214 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_148 ( struct V_90 * V_91 ,
struct V_254 * V_255 )
{
int V_17 = - V_14 ;
switch ( V_255 -> V_237 ) {
case V_256 :
V_17 = F_36 ( V_91 -> V_47 . V_109 -> V_212 ,
( T_3 V_72 * ) V_255 -> V_73 ) ;
break;
case V_257 :
V_17 = F_36 ( V_91 -> V_47 . V_109 -> V_108 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_258 :
V_17 = F_36 ( V_91 -> V_47 . V_109 -> V_210 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_259 :
V_17 = F_36 ( V_91 -> V_47 . V_109 -> V_211 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_260 :
V_17 = F_36 ( V_91 -> V_47 . V_189 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
if ( V_91 -> V_47 . V_189 == V_190 )
F_94 ( V_91 ) ;
break;
case V_261 :
V_17 = F_36 ( V_91 -> V_47 . V_262 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_263 :
V_17 = F_36 ( V_91 -> V_47 . V_264 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_265 :
V_17 = F_36 ( V_91 -> V_47 . V_109 -> V_215 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
case V_266 :
V_17 = F_36 ( V_91 -> V_47 . V_109 -> V_214 ,
( V_71 V_72 * ) V_255 -> V_73 ) ;
break;
default:
break;
}
return V_17 ;
}
static int F_149 ( struct V_90 * V_91 )
{
F_120 ( V_91 ) ;
return 0 ;
}
int F_150 ( struct V_90 * V_91 , struct V_267 * V_205 )
{
memcpy ( & V_91 -> V_191 -> V_204 . V_205 . V_268 , & V_205 -> V_268 , sizeof( V_205 -> V_268 ) ) ;
return 0 ;
}
int F_151 ( struct V_90 * V_91 , struct V_267 * V_205 )
{
memcpy ( & V_205 -> V_268 , & V_91 -> V_191 -> V_204 . V_205 . V_268 , sizeof( V_205 -> V_268 ) ) ;
return 0 ;
}
int F_152 ( struct V_90 * V_91 ,
struct V_269 * V_270 )
{
memcpy ( & V_91 -> V_191 -> V_204 . V_205 . V_206 , & V_270 -> V_206 , sizeof( V_270 -> V_206 ) ) ;
memcpy ( & V_91 -> V_47 . V_109 -> V_213 , & V_270 -> V_271 , sizeof( V_270 -> V_271 ) ) ;
F_114 ( V_91 -> V_191 -> V_204 . V_205 . V_206 ) ;
return 0 ;
}
int F_153 ( struct V_90 * V_91 ,
struct V_269 * V_270 )
{
memcpy ( & V_270 -> V_206 , & V_91 -> V_191 -> V_204 . V_205 . V_206 , sizeof( V_270 -> V_206 ) ) ;
memcpy ( & V_270 -> V_271 , & V_91 -> V_47 . V_109 -> V_213 , sizeof( V_270 -> V_271 ) ) ;
return 0 ;
}
int F_154 ( struct V_90 * V_91 , struct V_272 * V_273 )
{
if ( F_155 ( V_273 -> V_200 ) )
return - V_14 ;
memcpy ( & V_91 -> V_47 . V_203 . V_201 , & V_273 -> V_201 , sizeof( V_273 -> V_201 ) ) ;
V_91 -> V_47 . V_203 . V_200 = V_273 -> V_200 ;
F_112 ( & V_91 -> V_47 . V_203 . V_200 ) ;
F_113 ( V_91 -> V_47 . V_203 . V_201 ) ;
return 0 ;
}
int F_156 ( struct V_90 * V_91 , struct V_272 * V_273 )
{
memcpy ( & V_273 -> V_201 , & V_91 -> V_47 . V_203 . V_201 , sizeof( V_273 -> V_201 ) ) ;
V_273 -> V_200 = V_91 -> V_47 . V_203 . V_200 ;
return 0 ;
}
static int F_157 ( struct V_90 * V_91 , T_4 V_274 )
{
int V_158 = 0 ;
if ( ! F_158 ( V_91 ) )
V_158 = - V_78 ;
else {
V_91 -> V_191 -> V_275 = V_274 . V_127 ;
V_91 -> V_191 -> V_276 = V_274 . V_73 ;
}
return V_158 ;
}
int F_159 ( struct V_90 * V_91 ,
struct V_277 * V_278 )
{
return - V_14 ;
}
int F_160 ( struct V_90 * V_91 ,
struct V_279 * V_280 )
{
int V_158 = 0 ;
V_91 -> V_281 = 0 ;
F_161 ( V_91 ) ;
if ( V_280 -> V_282 & ~ V_283 )
return - V_14 ;
if ( V_280 -> V_282 & V_284 ) {
V_91 -> V_281 = V_280 -> V_282 ;
F_116 ( V_285 , & V_91 -> V_47 . V_109 -> V_208 ) ;
if ( V_280 -> V_282 & V_286 )
V_158 = F_162 ( V_91 , V_280 ) ;
} else {
F_118 ( V_285 , & V_91 -> V_47 . V_109 -> V_208 ) ;
V_91 -> V_47 . V_287 . V_288 = 0 ;
}
if ( V_158 ) {
V_91 -> V_281 = 0 ;
F_161 ( V_91 ) ;
F_118 ( V_285 , & V_91 -> V_47 . V_109 -> V_208 ) ;
}
return V_158 ;
}
int F_163 ( struct V_90 * V_91 ,
struct V_289 * V_290 )
{
return F_158 ( V_91 ) ? V_291 :
V_292 ;
}
int F_164 ( struct V_90 * V_91 ,
struct V_289 * V_290 )
{
int V_158 = 0 ;
V_91 -> V_15 -> V_47 . V_293 = 1 ;
switch ( V_290 -> V_290 ) {
case V_291 :
F_123 ( V_91 ) ;
break;
case V_292 :
F_165 ( V_91 ) ;
break;
case V_294 :
case V_295 :
default:
V_158 = - V_75 ;
}
return V_158 ;
}
bool F_97 ( struct V_15 * V_15 )
{
if ( ! V_296 )
return false ;
if ( ! V_297 )
return false ;
if ( ! V_15 -> V_47 . V_81 )
return false ;
return true ;
}
static bool F_166 ( struct V_90 * V_91 )
{
return F_31 ( & V_91 -> V_47 . V_109 -> V_208 ) & V_298 ;
}
static int F_167 ( struct V_90 * V_91 )
{
V_299:
F_140 ( V_91 ) ;
if ( F_168 ( V_253 , V_91 ) ) {
int V_158 ;
V_158 = F_169 ( V_91 -> V_47 . V_46 ,
F_143 ( V_91 ) ,
V_300 * 2 ) ;
if ( V_158 )
return V_158 ;
goto V_299;
}
if ( F_168 ( V_301 , V_91 ) ) {
V_91 -> V_47 . V_109 -> V_302 = 0xffff ;
goto V_299;
}
if ( F_168 ( V_303 , V_91 ) ) {
if ( ! F_166 ( V_91 ) ) {
F_170 ( V_91 -> V_182 , 1 ) ;
F_116 ( V_298 ,
& V_91 -> V_47 . V_109 -> V_208 ) ;
}
goto V_299;
}
if ( F_168 ( V_304 , V_91 ) ) {
if ( F_166 ( V_91 ) ) {
F_170 ( V_91 -> V_182 , 0 ) ;
F_118 ( V_298 ,
& V_91 -> V_47 . V_109 -> V_208 ) ;
}
goto V_299;
}
F_95 ( V_305 , & V_91 -> V_306 ) ;
return 0 ;
}
long F_171 ( struct V_90 * V_91 , T_5 V_307 , int V_308 )
{
return F_172 ( V_91 -> V_47 . V_46 , V_307 ,
V_308 ? V_309 : 0 ) ;
}
static void F_173 ( struct V_90 * V_91 , bool V_310 ,
unsigned long V_311 )
{
struct V_139 V_312 ;
struct V_313 V_314 ;
if ( V_310 ) {
V_314 . V_315 . V_16 . V_316 = V_311 ;
V_314 . type = V_317 ;
F_132 ( F_174 ( V_91 , & V_314 ) ) ;
} else {
V_312 . type = V_318 ;
V_312 . V_319 = V_311 ;
F_132 ( F_67 ( V_91 -> V_15 , & V_312 ) ) ;
}
}
void F_175 ( struct V_90 * V_91 ,
struct V_320 * V_321 )
{
F_176 ( V_91 , V_321 -> V_47 . V_189 ) ;
F_173 ( V_91 , true , V_321 -> V_47 . V_189 ) ;
}
void F_177 ( struct V_90 * V_91 ,
struct V_320 * V_321 )
{
F_178 ( V_91 , V_321 -> V_47 . V_189 ) ;
F_173 ( V_91 , false , V_321 -> V_47 . V_189 ) ;
}
void F_179 ( struct V_90 * V_91 ,
struct V_320 * V_321 )
{
}
bool F_180 ( struct V_90 * V_91 )
{
return true ;
}
static int F_181 ( struct V_90 * V_91 )
{
T_6 V_322 ;
struct V_323 V_47 ;
int V_158 ;
if ( V_91 -> V_47 . V_189 == V_190 )
return 0 ;
if ( ( V_91 -> V_47 . V_109 -> V_209 . V_127 & V_91 -> V_47 . V_264 ) !=
V_91 -> V_47 . V_262 )
return 0 ;
if ( F_182 ( V_91 ) )
return 0 ;
if ( F_138 ( V_91 , 0 ) )
return 0 ;
if ( ! ( V_91 -> V_47 . V_109 -> V_213 [ 0 ] & 0x200ul ) )
return 0 ;
if ( ! V_91 -> V_47 . V_46 -> V_179 )
return 0 ;
V_322 = F_183 ( V_91 -> V_15 , F_184 ( V_87 -> V_324 . V_325 ) ) ;
V_322 += V_87 -> V_324 . V_325 & ~ V_326 ;
if ( F_185 ( V_91 , V_91 -> V_47 . V_189 , & V_47 . V_189 , 8 ) )
return 0 ;
V_158 = F_186 ( V_91 , V_87 -> V_324 . V_325 , V_322 , & V_47 ) ;
return V_158 ;
}
static int F_187 ( struct V_90 * V_91 )
{
int V_158 , V_208 ;
F_188 ( V_91 ) ;
memcpy ( & V_91 -> V_47 . V_109 -> V_327 , & V_91 -> V_191 -> V_204 . V_205 . V_268 [ 14 ] , 16 ) ;
if ( F_189 () )
F_190 () ;
if ( F_191 ( V_328 ) )
F_192 () ;
if ( ! F_35 ( V_91 -> V_15 ) ) {
V_158 = F_193 ( V_91 ) ;
if ( V_158 )
return V_158 ;
}
V_158 = F_167 ( V_91 ) ;
if ( V_158 )
return V_158 ;
if ( F_194 ( V_91 ) ) {
F_195 ( V_91 ) ;
F_196 ( V_91 ) ;
}
V_91 -> V_47 . V_109 -> V_329 = 0 ;
V_208 = F_31 ( & V_91 -> V_47 . V_109 -> V_208 ) ;
F_91 ( V_91 , 6 , L_8 , V_208 ) ;
F_197 ( V_91 , V_208 ) ;
return 0 ;
}
static int F_198 ( struct V_90 * V_91 , int V_330 )
{
int V_158 = - 1 ;
F_91 ( V_91 , 6 , L_9 ,
V_91 -> V_47 . V_109 -> V_329 ) ;
F_199 ( V_91 , V_91 -> V_47 . V_109 -> V_329 ) ;
if ( F_194 ( V_91 ) )
F_200 ( V_91 ) ;
if ( V_330 >= 0 ) {
V_158 = 0 ;
} else if ( F_35 ( V_91 -> V_15 ) ) {
V_91 -> V_191 -> V_330 = V_331 ;
V_91 -> V_191 -> V_332 . V_333 =
V_87 -> V_324 . V_325 ;
V_91 -> V_191 -> V_332 . V_334 = 0x10 ;
V_158 = - V_335 ;
} else if ( V_87 -> V_324 . V_336 ) {
F_201 ( V_91 ) ;
V_87 -> V_324 . V_336 = 0 ;
if ( F_181 ( V_91 ) ) {
V_158 = 0 ;
} else {
T_5 V_307 = V_87 -> V_324 . V_325 ;
V_158 = F_171 ( V_91 , V_307 , 1 ) ;
}
}
if ( V_158 == - 1 ) {
F_91 ( V_91 , 3 , L_3 , L_10 ) ;
F_202 ( V_91 ) ;
V_158 = F_203 ( V_91 , V_337 ) ;
}
memcpy ( & V_91 -> V_191 -> V_204 . V_205 . V_268 [ 14 ] , & V_91 -> V_47 . V_109 -> V_327 , 16 ) ;
if ( V_158 == 0 ) {
if ( F_35 ( V_91 -> V_15 ) )
V_158 = V_91 -> V_47 . V_109 -> V_329 ? - V_338 : 0 ;
else
V_158 = F_204 ( V_91 ) ;
}
return V_158 ;
}
static int F_205 ( struct V_90 * V_91 )
{
int V_158 , V_330 ;
V_91 -> V_339 = F_32 ( & V_91 -> V_15 -> V_83 ) ;
do {
V_158 = F_187 ( V_91 ) ;
if ( V_158 )
break;
F_34 ( & V_91 -> V_15 -> V_83 , V_91 -> V_339 ) ;
F_206 () ;
F_207 () ;
F_208 () ;
V_330 = F_209 ( V_91 -> V_47 . V_109 ,
V_91 -> V_191 -> V_204 . V_205 . V_268 ) ;
F_210 () ;
V_91 -> V_339 = F_32 ( & V_91 -> V_15 -> V_83 ) ;
V_158 = F_198 ( V_91 , V_330 ) ;
} while ( ! F_211 ( V_87 ) && ! F_212 ( V_91 ) && ! V_158 );
F_34 ( & V_91 -> V_15 -> V_83 , V_91 -> V_339 ) ;
return V_158 ;
}
static void F_213 ( struct V_90 * V_91 , struct V_340 * V_340 )
{
V_91 -> V_47 . V_109 -> V_209 . V_127 = V_340 -> V_275 ;
V_91 -> V_47 . V_109 -> V_209 . V_73 = V_340 -> V_276 ;
if ( V_340 -> V_341 & V_193 )
F_121 ( V_91 , V_340 -> V_204 . V_205 . V_342 ) ;
if ( V_340 -> V_341 & V_196 ) {
memcpy ( & V_91 -> V_47 . V_109 -> V_213 , & V_340 -> V_204 . V_205 . V_271 , 128 ) ;
F_144 ( V_301 , V_91 ) ;
}
if ( V_340 -> V_341 & V_197 ) {
V_91 -> V_47 . V_109 -> V_210 = V_340 -> V_204 . V_205 . V_210 ;
V_91 -> V_47 . V_109 -> V_211 = V_340 -> V_204 . V_205 . V_211 ;
V_91 -> V_47 . V_109 -> V_212 = V_340 -> V_204 . V_205 . V_212 ;
V_91 -> V_47 . V_109 -> V_215 = V_340 -> V_204 . V_205 . V_215 ;
V_91 -> V_47 . V_109 -> V_214 = V_340 -> V_204 . V_205 . V_214 ;
}
if ( V_340 -> V_341 & V_198 ) {
V_91 -> V_47 . V_189 = V_340 -> V_204 . V_205 . V_343 ;
V_91 -> V_47 . V_264 = V_340 -> V_204 . V_205 . V_344 ;
V_91 -> V_47 . V_262 = V_340 -> V_204 . V_205 . V_345 ;
if ( V_91 -> V_47 . V_189 == V_190 )
F_94 ( V_91 ) ;
}
V_340 -> V_341 = 0 ;
}
static void F_214 ( struct V_90 * V_91 , struct V_340 * V_340 )
{
V_340 -> V_275 = V_91 -> V_47 . V_109 -> V_209 . V_127 ;
V_340 -> V_276 = V_91 -> V_47 . V_109 -> V_209 . V_73 ;
V_340 -> V_204 . V_205 . V_342 = F_143 ( V_91 ) ;
memcpy ( & V_340 -> V_204 . V_205 . V_271 , & V_91 -> V_47 . V_109 -> V_213 , 128 ) ;
V_340 -> V_204 . V_205 . V_210 = V_91 -> V_47 . V_109 -> V_210 ;
V_340 -> V_204 . V_205 . V_211 = V_91 -> V_47 . V_109 -> V_211 ;
V_340 -> V_204 . V_205 . V_212 = V_91 -> V_47 . V_109 -> V_212 ;
V_340 -> V_204 . V_205 . V_215 = V_91 -> V_47 . V_109 -> V_215 ;
V_340 -> V_204 . V_205 . V_214 = V_91 -> V_47 . V_109 -> V_214 ;
V_340 -> V_204 . V_205 . V_343 = V_91 -> V_47 . V_189 ;
V_340 -> V_204 . V_205 . V_344 = V_91 -> V_47 . V_264 ;
V_340 -> V_204 . V_205 . V_345 = V_91 -> V_47 . V_262 ;
}
int F_215 ( struct V_90 * V_91 , struct V_340 * V_340 )
{
int V_158 ;
T_7 V_346 ;
if ( F_212 ( V_91 ) ) {
F_216 ( V_91 ) ;
return 0 ;
}
if ( V_91 -> V_347 )
F_217 ( V_348 , & V_91 -> V_349 , & V_346 ) ;
if ( ! F_122 ( V_91 -> V_15 ) ) {
F_165 ( V_91 ) ;
} else if ( F_158 ( V_91 ) ) {
F_218 ( L_11 ,
V_91 -> V_182 ) ;
return - V_14 ;
}
F_213 ( V_91 , V_340 ) ;
F_219 () ;
V_158 = F_205 ( V_91 ) ;
if ( F_211 ( V_87 ) && ! V_158 ) {
V_340 -> V_330 = V_350 ;
V_158 = - V_351 ;
}
if ( F_212 ( V_91 ) && ! V_158 ) {
F_216 ( V_91 ) ;
V_158 = 0 ;
}
if ( V_158 == - V_338 ) {
V_340 -> V_330 = V_352 ;
V_340 -> V_353 . V_329 = V_91 -> V_47 . V_109 -> V_329 ;
V_340 -> V_353 . V_354 = V_91 -> V_47 . V_109 -> V_354 ;
V_340 -> V_353 . V_355 = V_91 -> V_47 . V_109 -> V_355 ;
V_158 = 0 ;
}
if ( V_158 == - V_335 ) {
V_158 = 0 ;
}
F_214 ( V_91 , V_340 ) ;
if ( V_91 -> V_347 )
F_217 ( V_348 , & V_346 , NULL ) ;
V_91 -> V_356 . V_357 ++ ;
return V_158 ;
}
int F_220 ( struct V_90 * V_91 , unsigned long V_307 )
{
unsigned char V_358 = 1 ;
unsigned int V_359 ;
V_71 V_360 ;
int V_158 ;
if ( V_307 == V_361 ) {
if ( F_221 ( V_91 , 163 , & V_358 , 1 ) )
return - V_74 ;
V_307 = V_362 ;
} else if ( V_307 == V_363 ) {
if ( F_222 ( V_91 , 163 , & V_358 , 1 ) )
return - V_74 ;
V_307 = F_223 ( V_91 , V_362 ) ;
}
V_158 = F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_365 ) ,
V_91 -> V_47 . V_203 . V_201 , 128 ) ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_366 ) ,
V_91 -> V_191 -> V_204 . V_205 . V_268 , 128 ) ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_274 ) ,
& V_91 -> V_47 . V_109 -> V_209 , 16 ) ;
V_359 = F_143 ( V_91 ) ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_367 ) ,
& V_359 , 4 ) ;
V_158 |= F_221 ( V_91 ,
V_307 + F_224 ( struct V_364 , V_368 ) ,
& V_91 -> V_47 . V_203 . V_200 , 4 ) ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_369 ) ,
& V_91 -> V_47 . V_109 -> V_212 , 4 ) ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_370 ) ,
& V_91 -> V_47 . V_109 -> V_210 , 8 ) ;
V_360 = V_91 -> V_47 . V_109 -> V_211 >> 8 ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_371 ) ,
& V_360 , 8 ) ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_372 ) ,
& V_91 -> V_191 -> V_204 . V_205 . V_206 , 64 ) ;
V_158 |= F_221 ( V_91 , V_307 + F_224 ( struct V_364 , V_373 ) ,
& V_91 -> V_47 . V_109 -> V_213 , 128 ) ;
return V_158 ? - V_74 : 0 ;
}
int F_225 ( struct V_90 * V_91 , unsigned long V_73 )
{
F_109 ( & V_91 -> V_47 . V_203 . V_200 ) ;
F_110 ( V_91 -> V_47 . V_203 . V_201 ) ;
F_111 ( V_91 -> V_191 -> V_204 . V_205 . V_206 ) ;
return F_220 ( V_91 , V_73 ) ;
}
static void F_226 ( struct V_90 * V_91 )
{
F_168 ( V_303 , V_91 ) ;
F_144 ( V_304 , V_91 ) ;
F_142 ( V_91 ) ;
}
static void F_227 ( struct V_15 * V_15 )
{
unsigned int V_92 ;
struct V_90 * V_91 ;
F_42 (i, vcpu, kvm) {
F_226 ( V_91 ) ;
}
}
static void F_228 ( struct V_90 * V_91 )
{
F_168 ( V_304 , V_91 ) ;
F_144 ( V_303 , V_91 ) ;
F_142 ( V_91 ) ;
}
void F_165 ( struct V_90 * V_91 )
{
int V_92 , V_80 , V_374 = 0 ;
if ( ! F_158 ( V_91 ) )
return;
F_229 ( V_91 -> V_182 , 1 ) ;
F_79 ( & V_91 -> V_15 -> V_47 . V_181 ) ;
V_80 = F_31 ( & V_91 -> V_15 -> V_80 ) ;
for ( V_92 = 0 ; V_92 < V_80 ; V_92 ++ ) {
if ( ! F_158 ( V_91 -> V_15 -> V_188 [ V_92 ] ) )
V_374 ++ ;
}
if ( V_374 == 0 ) {
F_228 ( V_91 ) ;
} else if ( V_374 == 1 ) {
F_227 ( V_91 -> V_15 ) ;
}
F_118 ( V_223 , & V_91 -> V_47 . V_109 -> V_208 ) ;
F_144 ( V_301 , V_91 ) ;
F_80 ( & V_91 -> V_15 -> V_47 . V_181 ) ;
return;
}
void F_123 ( struct V_90 * V_91 )
{
int V_92 , V_80 , V_374 = 0 ;
struct V_90 * V_375 = NULL ;
if ( F_158 ( V_91 ) )
return;
F_229 ( V_91 -> V_182 , 0 ) ;
F_79 ( & V_91 -> V_15 -> V_47 . V_181 ) ;
V_80 = F_31 ( & V_91 -> V_15 -> V_80 ) ;
F_230 ( V_91 ) ;
F_116 ( V_223 , & V_91 -> V_47 . V_109 -> V_208 ) ;
F_226 ( V_91 ) ;
for ( V_92 = 0 ; V_92 < V_80 ; V_92 ++ ) {
if ( ! F_158 ( V_91 -> V_15 -> V_188 [ V_92 ] ) ) {
V_374 ++ ;
V_375 = V_91 -> V_15 -> V_188 [ V_92 ] ;
}
}
if ( V_374 == 1 ) {
F_228 ( V_375 ) ;
}
F_80 ( & V_91 -> V_15 -> V_47 . V_181 ) ;
return;
}
static int F_231 ( struct V_90 * V_91 ,
struct V_61 * V_62 )
{
int V_17 ;
if ( V_62 -> V_63 )
return - V_14 ;
switch ( V_62 -> V_62 ) {
case V_26 :
if ( ! V_91 -> V_15 -> V_47 . V_180 ) {
V_91 -> V_15 -> V_47 . V_180 = 1 ;
F_232 ( V_91 -> V_15 ) ;
}
V_17 = 0 ;
break;
default:
V_17 = - V_14 ;
break;
}
return V_17 ;
}
long F_233 ( struct V_9 * V_10 ,
unsigned int V_11 , unsigned long V_12 )
{
struct V_90 * V_91 = V_10 -> V_136 ;
void V_72 * V_137 = ( void V_72 * ) V_12 ;
int V_76 ;
long V_17 ;
switch ( V_11 ) {
case V_138 : {
struct V_139 V_140 ;
struct V_313 V_376 ;
V_17 = - V_74 ;
if ( F_46 ( & V_140 , V_137 , sizeof( V_140 ) ) )
break;
if ( F_234 ( & V_140 , & V_376 ) )
return - V_14 ;
V_17 = F_174 ( V_91 , & V_376 ) ;
break;
}
case V_377 :
V_76 = F_32 ( & V_91 -> V_15 -> V_83 ) ;
V_17 = F_225 ( V_91 , V_12 ) ;
F_34 ( & V_91 -> V_15 -> V_83 , V_76 ) ;
break;
case V_378 : {
T_4 V_274 ;
V_17 = - V_74 ;
if ( F_46 ( & V_274 , V_137 , sizeof( V_274 ) ) )
break;
V_17 = F_157 ( V_91 , V_274 ) ;
break;
}
case V_379 :
V_17 = F_149 ( V_91 ) ;
break;
case V_380 :
case V_381 : {
struct V_254 V_255 ;
V_17 = - V_74 ;
if ( F_46 ( & V_255 , V_137 , sizeof( V_255 ) ) )
break;
if ( V_11 == V_380 )
V_17 = F_148 ( V_91 , & V_255 ) ;
else
V_17 = F_147 ( V_91 , & V_255 ) ;
break;
}
#ifdef F_14
case V_382 : {
struct V_383 V_384 ;
if ( F_46 ( & V_384 , V_137 , sizeof( V_384 ) ) ) {
V_17 = - V_74 ;
break;
}
if ( ! F_35 ( V_91 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_235 ( V_91 -> V_47 . V_46 , V_384 . V_385 ,
V_384 . V_386 , V_384 . V_387 ) ;
break;
}
case V_388 : {
struct V_383 V_384 ;
if ( F_46 ( & V_384 , V_137 , sizeof( V_384 ) ) ) {
V_17 = - V_74 ;
break;
}
if ( ! F_35 ( V_91 -> V_15 ) ) {
V_17 = - V_14 ;
break;
}
V_17 = F_236 ( V_91 -> V_47 . V_46 , V_384 . V_386 ,
V_384 . V_387 ) ;
break;
}
#endif
case V_389 : {
V_17 = F_172 ( V_91 -> V_47 . V_46 , V_12 , 0 ) ;
break;
}
case V_141 :
{
struct V_61 V_62 ;
V_17 = - V_74 ;
if ( F_46 ( & V_62 , V_137 , sizeof( V_62 ) ) )
break;
V_17 = F_231 ( V_91 , & V_62 ) ;
break;
}
default:
V_17 = - V_148 ;
}
return V_17 ;
}
int F_237 ( struct V_90 * V_91 , struct V_390 * V_391 )
{
#ifdef F_14
if ( ( V_391 -> V_392 == V_393 )
&& ( F_35 ( V_91 -> V_15 ) ) ) {
V_391 -> V_394 = F_238 ( V_91 -> V_47 . V_109 ) ;
F_239 ( V_391 -> V_394 ) ;
return 0 ;
}
#endif
return V_395 ;
}
int F_240 ( struct V_15 * V_15 , struct V_41 * V_56 ,
unsigned long V_51 )
{
return 0 ;
}
int F_241 ( struct V_15 * V_15 ,
struct V_41 * V_42 ,
struct V_396 * V_397 ,
enum V_398 V_399 )
{
if ( V_397 -> V_400 & 0xffffful )
return - V_14 ;
if ( V_397 -> V_401 & 0xffffful )
return - V_14 ;
return 0 ;
}
void F_242 ( struct V_15 * V_15 ,
struct V_396 * V_397 ,
const struct V_41 * V_402 ,
enum V_398 V_399 )
{
int V_158 ;
if ( V_402 -> V_400 == V_397 -> V_400 &&
V_402 -> V_50 * V_300 == V_397 -> V_403 &&
V_402 -> V_51 * V_300 == V_397 -> V_401 )
return;
V_158 = F_235 ( V_15 -> V_47 . V_46 , V_397 -> V_400 ,
V_397 -> V_403 , V_397 -> V_401 ) ;
if ( V_158 )
F_243 ( V_404 L_12 ) ;
return;
}
static int T_8 F_244 ( void )
{
return F_245 ( NULL , sizeof( struct V_90 ) , 0 , V_405 ) ;
}
static void T_9 F_246 ( void )
{
F_247 () ;
}
