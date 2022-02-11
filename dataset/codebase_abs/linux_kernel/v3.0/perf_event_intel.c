static T_1 F_1 ( int V_1 )
{
return V_2 [ V_1 ] ;
}
static void F_2 ( void )
{
struct V_3 * V_4 = & F_3 ( V_3 ) ;
F_4 ( V_5 , 0 ) ;
if ( F_5 ( V_6 , V_4 -> V_7 ) )
F_6 () ;
F_7 () ;
F_8 () ;
}
static void F_9 ( int V_8 )
{
struct V_3 * V_4 = & F_3 ( V_3 ) ;
F_10 () ;
F_11 () ;
F_4 ( V_5 , V_9 . V_10 ) ;
if ( F_5 ( V_6 , V_4 -> V_7 ) ) {
struct V_11 * V_12 =
V_4 -> V_13 [ V_6 ] ;
if ( F_12 ( ! V_12 ) )
return;
F_13 ( V_12 -> V_14 . V_15 ) ;
}
}
static void F_14 ( void )
{
struct V_3 * V_4 = & F_3 ( V_3 ) ;
static const unsigned long V_16 [ 4 ] = {
0x4300B5 ,
0x4300D2 ,
0x4300B1 ,
0x4300B1
} ;
struct V_11 * V_12 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
V_12 = V_4 -> V_13 [ V_17 ] ;
if ( V_12 )
F_15 ( V_12 ) ;
}
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
F_4 ( V_18 + V_17 , V_16 [ V_17 ] ) ;
F_4 ( V_19 + V_17 , 0x0 ) ;
}
F_4 ( V_5 , 0xf ) ;
F_4 ( V_5 , 0x0 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
V_12 = V_4 -> V_13 [ V_17 ] ;
if ( V_12 ) {
F_16 ( V_12 ) ;
F_17 ( & V_12 -> V_14 ,
V_20 ) ;
} else
F_4 ( V_18 + V_17 , 0x0 ) ;
}
}
static void F_18 ( int V_8 )
{
if ( V_8 )
F_14 () ;
F_9 ( V_8 ) ;
}
static inline T_1 F_19 ( void )
{
T_1 V_21 ;
F_20 ( V_22 , V_21 ) ;
return V_21 ;
}
static inline void F_21 ( T_1 V_23 )
{
F_4 ( V_24 , V_23 ) ;
}
static void F_22 ( struct V_25 * V_26 )
{
int V_27 = V_26 -> V_27 - V_28 ;
T_1 V_29 , V_30 ;
V_30 = 0xfULL << ( V_27 * 4 ) ;
F_20 ( V_26 -> V_31 , V_29 ) ;
V_29 &= ~ V_30 ;
F_4 ( V_26 -> V_31 , V_29 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_25 * V_26 = & V_12 -> V_14 ;
if ( F_24 ( V_26 -> V_27 == V_6 ) ) {
F_6 () ;
F_25 () ;
return;
}
if ( F_24 ( V_26 -> V_31 == V_32 ) ) {
F_22 ( V_26 ) ;
return;
}
F_26 ( V_12 ) ;
if ( F_24 ( V_12 -> V_33 . V_34 ) )
F_27 ( V_12 ) ;
}
static void F_28 ( struct V_25 * V_26 )
{
int V_27 = V_26 -> V_27 - V_28 ;
T_1 V_29 , V_35 , V_30 ;
V_35 = 0x8ULL ;
if ( V_26 -> V_15 & V_36 )
V_35 |= 0x2 ;
if ( V_26 -> V_15 & V_37 )
V_35 |= 0x1 ;
if ( V_9 . V_38 > 2 && V_26 -> V_15 & V_39 )
V_35 |= 0x4 ;
V_35 <<= ( V_27 * 4 ) ;
V_30 = 0xfULL << ( V_27 * 4 ) ;
F_20 ( V_26 -> V_31 , V_29 ) ;
V_29 &= ~ V_30 ;
V_29 |= V_35 ;
F_4 ( V_26 -> V_31 , V_29 ) ;
}
static void F_29 ( struct V_11 * V_12 )
{
struct V_25 * V_26 = & V_12 -> V_14 ;
if ( F_24 ( V_26 -> V_27 == V_6 ) ) {
if ( ! F_30 ( V_3 . V_40 ) )
return;
F_13 ( V_26 -> V_15 ) ;
return;
}
if ( F_24 ( V_26 -> V_31 == V_32 ) ) {
F_28 ( V_26 ) ;
return;
}
if ( F_24 ( V_12 -> V_33 . V_34 ) )
F_31 ( V_12 ) ;
F_17 ( V_26 , V_20 ) ;
}
static int F_32 ( struct V_11 * V_12 )
{
F_15 ( V_12 ) ;
return F_16 ( V_12 ) ;
}
static void F_33 ( void )
{
struct V_41 * V_42 = F_30 ( V_3 . V_42 ) ;
unsigned long V_43 ;
int V_27 ;
if ( ! V_9 . V_44 )
return;
F_34 ( V_43 ) ;
F_35 ( L_1 , F_36 () ) ;
for ( V_27 = 0 ; V_27 < V_9 . V_44 ; V_27 ++ ) {
F_37 ( F_38 ( V_27 ) , 0ull ) ;
F_37 ( F_39 ( V_27 ) , 0ull ) ;
}
for ( V_27 = 0 ; V_27 < V_9 . V_45 ; V_27 ++ )
F_37 ( V_46 + V_27 , 0ull ) ;
if ( V_42 )
V_42 -> V_47 = V_42 -> V_48 ;
F_40 ( V_43 ) ;
}
static int F_41 ( struct V_49 * V_50 )
{
struct V_51 V_52 ;
struct V_3 * V_4 ;
int V_53 , V_54 ;
T_1 V_21 ;
int V_55 ;
F_42 ( & V_52 , 0 ) ;
V_4 = & F_3 ( V_3 ) ;
F_43 ( V_56 , V_57 ) ;
F_2 () ;
V_55 = F_25 () ;
V_21 = F_19 () ;
if ( ! V_21 ) {
F_9 ( 0 ) ;
return V_55 ;
}
V_54 = 0 ;
V_58:
F_21 ( V_21 ) ;
if ( ++ V_54 > 100 ) {
F_44 ( 1 , L_2 ) ;
F_45 () ;
F_33 () ;
goto V_59;
}
F_46 ( V_60 ) ;
F_47 () ;
if ( F_48 ( 62 , ( unsigned long * ) & V_21 ) ) {
V_55 ++ ;
V_9 . V_61 ( V_50 ) ;
}
F_49 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_11 * V_12 = V_4 -> V_13 [ V_53 ] ;
V_55 ++ ;
if ( ! F_5 ( V_53 , V_4 -> V_7 ) )
continue;
if ( ! F_32 ( V_12 ) )
continue;
V_52 . V_62 = V_12 -> V_14 . V_63 ;
if ( F_50 ( V_12 , 1 , & V_52 , V_50 ) )
F_51 ( V_12 , 0 ) ;
}
V_21 = F_19 () ;
if ( V_21 )
goto V_58;
V_59:
F_9 ( 0 ) ;
return V_55 ;
}
static struct V_64 *
F_52 ( struct V_11 * V_12 )
{
struct V_25 * V_26 = & V_12 -> V_14 ;
unsigned int V_1 , V_65 ;
if ( V_12 -> V_33 . V_66 )
return NULL ;
V_1 = V_26 -> V_15 & V_67 ;
V_65 = V_9 . V_68 ( V_69 ) ;
if ( F_24 ( V_1 == V_65 && V_26 -> V_70 == 1 ) )
return & V_71 ;
return NULL ;
}
static struct V_64 *
F_53 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_25 * V_26 = & V_12 -> V_14 ;
unsigned int V_72 = V_26 -> V_15 & V_73 ;
struct V_64 * V_74 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
int V_17 ;
int V_79 ;
int V_80 ;
if ( ! V_9 . V_81 || V_26 -> V_82 )
return NULL ;
for ( V_74 = V_9 . V_81 ; V_74 -> V_83 ; V_74 ++ ) {
if ( V_72 != V_74 -> V_84 )
continue;
V_76 = V_4 -> V_85 ;
if ( ! V_76 )
break;
V_74 = & V_86 ;
F_54 ( & V_76 -> V_87 ) ;
V_79 = - 1 ;
V_80 = 0 ;
for ( V_17 = 0 ; V_17 < V_88 ; V_17 ++ ) {
V_78 = & V_76 -> V_50 [ V_17 ] ;
if ( V_78 -> V_89 > 0 && V_26 -> V_90 == V_78 -> V_90 ) {
if ( V_26 -> V_91 == V_78 -> V_91 ) {
V_78 -> V_89 ++ ;
V_4 -> V_92 = 1 ;
V_26 -> V_82 = 1 ;
V_74 = NULL ;
}
V_80 = 1 ;
break;
} else if ( V_78 -> V_89 == 0 && V_79 == - 1 )
V_79 = V_17 ;
}
if ( ! V_80 && V_79 != - 1 ) {
V_78 = & V_76 -> V_50 [ V_79 ] ;
V_78 -> V_89 = 1 ;
V_78 -> V_90 = V_26 -> V_90 ;
V_78 -> V_91 = V_26 -> V_91 ;
V_4 -> V_92 = 1 ;
V_26 -> V_82 = 1 ;
V_74 = NULL ;
}
F_55 ( & V_76 -> V_87 ) ;
return V_74 ;
}
return NULL ;
}
static struct V_64 *
F_56 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_64 * V_74 ;
V_74 = F_52 ( V_12 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_57 ( V_12 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_53 ( V_4 , V_12 ) ;
if ( V_74 )
return V_74 ;
return F_58 ( V_4 , V_12 ) ;
}
static void F_59 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_90 * V_93 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_25 * V_26 = & V_12 -> V_14 ;
int V_17 , V_94 ;
if ( ! V_4 -> V_92 )
return;
for ( V_93 = V_9 . V_95 ; V_93 -> V_96 ; V_93 ++ ) {
if ( V_93 -> V_12 != ( V_26 -> V_15 & V_93 -> V_97 ) )
continue;
V_76 = V_4 -> V_85 ;
F_54 ( & V_76 -> V_87 ) ;
for ( V_17 = 0 ; V_17 < V_88 ; V_17 ++ ) {
V_78 = & V_76 -> V_50 [ V_17 ] ;
if ( V_78 -> V_89 > 0 &&
V_78 -> V_91 == V_26 -> V_91 &&
V_78 -> V_90 == V_93 -> V_96 ) {
V_78 -> V_89 -- ;
V_26 -> V_82 = 0 ;
break;
}
}
V_94 = 0 ;
for ( V_17 = 0 ; V_17 < V_88 ; V_17 ++ )
V_94 += V_76 -> V_50 [ V_17 ] . V_89 ;
if ( V_94 == 0 )
V_4 -> V_92 = 0 ;
F_55 ( & V_76 -> V_87 ) ;
break;
}
}
static int F_60 ( struct V_11 * V_12 )
{
int V_98 = F_61 ( V_12 ) ;
if ( V_98 )
return V_98 ;
if ( V_12 -> V_33 . V_34 &&
( V_12 -> V_14 . V_15 & V_99 ) == 0x003c ) {
T_1 V_100 = 0x108000c0 ;
V_100 |= ( V_12 -> V_14 . V_15 & ~ V_99 ) ;
V_12 -> V_14 . V_15 = V_100 ;
}
if ( V_12 -> V_33 . type != V_101 )
return 0 ;
if ( ! ( V_12 -> V_33 . V_15 & V_39 ) )
return 0 ;
if ( V_9 . V_38 < 3 )
return - V_102 ;
if ( F_62 () && ! F_63 ( V_103 ) )
return - V_104 ;
V_12 -> V_14 . V_15 |= V_39 ;
return 0 ;
}
static int F_64 ( int V_105 )
{
struct V_3 * V_4 = & F_65 ( V_3 , V_105 ) ;
if ( ! F_66 () )
return V_106 ;
V_4 -> V_85 = F_67 ( sizeof( struct V_75 ) ,
V_107 , F_68 ( V_105 ) ) ;
if ( ! V_4 -> V_85 )
return V_108 ;
F_69 ( & V_4 -> V_85 -> V_87 ) ;
V_4 -> V_85 -> V_109 = - 1 ;
return V_106 ;
}
static void F_70 ( int V_105 )
{
struct V_3 * V_4 = & F_65 ( V_3 , V_105 ) ;
int V_109 = F_71 ( V_105 ) ;
int V_17 ;
F_72 ( V_105 ) ;
F_73 () ;
if ( ! F_66 () )
return;
F_74 (i, topology_thread_cpumask(cpu)) {
struct V_75 * V_76 = F_65 ( V_3 , V_17 ) . V_85 ;
if ( V_76 && V_76 -> V_109 == V_109 ) {
F_75 ( V_4 -> V_85 ) ;
V_4 -> V_85 = V_76 ;
break;
}
}
V_4 -> V_85 -> V_109 = V_109 ;
V_4 -> V_85 -> V_110 ++ ;
}
static void F_76 ( int V_105 )
{
struct V_3 * V_4 = & F_65 ( V_3 , V_105 ) ;
struct V_75 * V_76 = V_4 -> V_85 ;
if ( V_76 ) {
if ( V_76 -> V_109 == - 1 || -- V_76 -> V_110 == 0 )
F_75 ( V_76 ) ;
V_4 -> V_85 = NULL ;
}
F_77 ( V_105 ) ;
}
static void F_78 ( void )
{
F_35 ( V_111 L_3 ) ;
V_9 . V_112 = 0 ;
V_9 . V_113 = NULL ;
}
static T_2 int F_79 ( void )
{
union V_114 V_115 ;
union V_116 V_117 ;
unsigned int V_118 ;
unsigned int V_119 ;
int V_38 ;
if ( ! F_80 ( & V_120 , V_121 ) ) {
switch ( V_120 . V_122 ) {
case 0x6 :
return F_81 () ;
case 0xf :
return F_82 () ;
}
return - V_123 ;
}
F_83 ( 10 , & V_117 . V_124 , & V_119 , & V_118 , & V_115 . V_124 ) ;
if ( V_117 . V_125 . V_126 <= V_127 )
return - V_123 ;
V_38 = V_117 . V_125 . V_128 ;
if ( V_38 < 2 )
V_9 = V_129 ;
else
V_9 = V_130 ;
V_9 . V_38 = V_38 ;
V_9 . V_44 = V_117 . V_125 . V_44 ;
V_9 . V_131 = V_117 . V_125 . V_132 ;
V_9 . V_133 = ( 1ULL << V_117 . V_125 . V_132 ) - 1 ;
if ( V_38 > 1 )
V_9 . V_45 = F_84 ( ( int ) V_115 . V_125 . V_45 , 3 ) ;
if ( V_38 > 1 ) {
T_1 V_134 ;
F_20 ( V_135 , V_134 ) ;
V_9 . V_136 . V_134 = V_134 ;
}
F_85 () ;
switch ( V_120 . V_137 ) {
case 14 :
F_86 ( L_4 ) ;
break;
case 15 :
V_9 . V_138 = F_78 ;
case 22 :
case 23 :
case 29 :
memcpy ( V_139 , V_140 ,
sizeof( V_139 ) ) ;
F_87 () ;
V_9 . V_141 = V_142 ;
V_9 . V_113 = V_143 ;
F_86 ( L_5 ) ;
break;
case 26 :
case 30 :
case 46 :
memcpy ( V_139 , V_144 ,
sizeof( V_139 ) ) ;
memcpy ( V_145 , V_146 ,
sizeof( V_145 ) ) ;
F_88 () ;
V_9 . V_141 = V_147 ;
V_9 . V_113 = V_148 ;
V_9 . V_81 = V_149 ;
V_9 . V_150 = F_18 ;
V_9 . V_95 = V_151 ;
V_2 [ V_152 ] = 0x180010e ;
V_2 [ V_153 ] = 0x1803fb1 ;
if ( V_119 & 0x40 ) {
V_2 [ V_154 ] = 0x7f89 ;
F_86 ( L_6 ) ;
}
F_86 ( L_7 ) ;
break;
case 28 :
memcpy ( V_139 , V_155 ,
sizeof( V_139 ) ) ;
F_89 () ;
V_9 . V_141 = V_156 ;
V_9 . V_113 = V_157 ;
F_86 ( L_8 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_139 , V_158 ,
sizeof( V_139 ) ) ;
memcpy ( V_145 , V_146 ,
sizeof( V_145 ) ) ;
F_88 () ;
V_9 . V_141 = V_159 ;
V_9 . V_81 = V_160 ;
V_9 . V_150 = F_18 ;
V_9 . V_113 = V_161 ;
V_9 . V_95 = V_162 ;
V_2 [ V_152 ] = 0x180010e ;
V_2 [ V_153 ] = 0x1803fb1 ;
F_86 ( L_9 ) ;
break;
case 42 :
memcpy ( V_139 , V_163 ,
sizeof( V_139 ) ) ;
F_88 () ;
V_9 . V_141 = V_164 ;
V_9 . V_113 = V_165 ;
V_2 [ V_152 ] = 0x180010e ;
V_2 [ V_153 ] = 0x18001b1 ;
F_86 ( L_10 ) ;
break;
default:
V_9 . V_141 = V_156 ;
F_86 ( L_11 ) ;
}
return 0 ;
}
static int F_79 ( void )
{
return 0 ;
}
