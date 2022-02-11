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
if ( F_50 ( V_12 , & V_52 , V_50 ) )
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
static bool F_53 ( struct V_11 * V_12 , int V_72 )
{
if ( ! ( V_9 . V_73 & V_74 ) )
return false ;
if ( V_12 -> V_14 . V_75 . V_27 == V_76 ) {
V_12 -> V_14 . V_15 &= ~ V_67 ;
V_12 -> V_14 . V_15 |= 0x01bb ;
V_12 -> V_14 . V_75 . V_27 = V_77 ;
V_12 -> V_14 . V_75 . V_78 = V_79 ;
} else if ( V_12 -> V_14 . V_75 . V_27 == V_77 ) {
V_12 -> V_14 . V_15 &= ~ V_67 ;
V_12 -> V_14 . V_15 |= 0x01b7 ;
V_12 -> V_14 . V_75 . V_27 = V_76 ;
V_12 -> V_14 . V_75 . V_78 = V_80 ;
}
if ( V_12 -> V_14 . V_75 . V_27 == V_72 )
return false ;
return true ;
}
static struct V_64 *
F_54 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_64 * V_81 = & V_82 ;
struct V_83 * V_78 = & V_12 -> V_14 . V_75 ;
struct V_84 * V_85 ;
unsigned long V_43 ;
int V_72 = V_78 -> V_27 ;
if ( V_78 -> V_86 )
return & V_87 ;
V_58:
V_85 = & V_4 -> V_88 -> V_50 [ V_78 -> V_27 ] ;
F_55 ( & V_85 -> V_89 , V_43 ) ;
if ( ! F_56 ( & V_85 -> V_90 ) || V_85 -> V_15 == V_78 -> V_15 ) {
V_85 -> V_15 = V_78 -> V_15 ;
V_85 -> V_78 = V_78 -> V_78 ;
F_57 ( & V_85 -> V_90 ) ;
V_78 -> V_86 = 1 ;
V_81 = & V_87 ;
} else if ( F_53 ( V_12 , V_72 ) ) {
F_58 ( & V_85 -> V_89 ) ;
goto V_58;
}
F_59 ( & V_85 -> V_89 , V_43 ) ;
return V_81 ;
}
static void
F_60 ( struct V_3 * V_4 ,
struct V_83 * V_78 )
{
struct V_84 * V_85 ;
if ( ! V_78 -> V_86 )
return;
V_85 = & V_4 -> V_88 -> V_50 [ V_78 -> V_27 ] ;
F_61 ( & V_85 -> V_90 ) ;
V_78 -> V_86 = 0 ;
}
static struct V_64 *
F_62 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_64 * V_81 = NULL ;
if ( V_12 -> V_14 . V_75 . V_27 != V_91 )
V_81 = F_54 ( V_4 , V_12 ) ;
return V_81 ;
}
static struct V_64 *
F_63 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_64 * V_81 ;
V_81 = F_52 ( V_12 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_64 ( V_12 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_62 ( V_4 , V_12 ) ;
if ( V_81 )
return V_81 ;
return F_65 ( V_4 , V_12 ) ;
}
static void
F_66 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_83 * V_78 ;
V_78 = & V_12 -> V_14 . V_75 ;
if ( V_78 -> V_27 != V_91 )
F_60 ( V_4 , V_78 ) ;
}
static void F_67 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
F_66 ( V_4 , V_12 ) ;
}
static int F_68 ( struct V_11 * V_12 )
{
int V_92 = F_69 ( V_12 ) ;
if ( V_92 )
return V_92 ;
if ( V_12 -> V_33 . V_34 &&
( V_12 -> V_14 . V_15 & V_93 ) == 0x003c ) {
T_1 V_94 = 0x108000c0 ;
V_94 |= ( V_12 -> V_14 . V_15 & ~ V_93 ) ;
V_12 -> V_14 . V_15 = V_94 ;
}
if ( V_12 -> V_33 . type != V_95 )
return 0 ;
if ( ! ( V_12 -> V_33 . V_15 & V_39 ) )
return 0 ;
if ( V_9 . V_38 < 3 )
return - V_96 ;
if ( F_70 () && ! F_71 ( V_97 ) )
return - V_98 ;
V_12 -> V_14 . V_15 |= V_39 ;
return 0 ;
}
static struct V_99 * F_72 ( int V_100 )
{
struct V_99 * V_50 ;
int V_17 ;
V_50 = F_73 ( sizeof( struct V_99 ) ,
V_101 , F_74 ( V_100 ) ) ;
if ( V_50 ) {
for ( V_17 = 0 ; V_17 < V_102 ; V_17 ++ )
F_75 ( & V_50 -> V_50 [ V_17 ] . V_89 ) ;
V_50 -> V_103 = - 1 ;
}
return V_50 ;
}
static int F_76 ( int V_100 )
{
struct V_3 * V_4 = & F_77 ( V_3 , V_100 ) ;
if ( ! V_9 . V_104 )
return V_105 ;
V_4 -> V_88 = F_72 ( V_100 ) ;
if ( ! V_4 -> V_88 )
return V_106 ;
return V_105 ;
}
static void F_78 ( int V_100 )
{
struct V_3 * V_4 = & F_77 ( V_3 , V_100 ) ;
int V_103 = F_79 ( V_100 ) ;
int V_17 ;
F_80 ( V_100 ) ;
F_81 () ;
if ( ! V_4 -> V_88 || ( V_9 . V_73 & V_107 ) )
return;
F_82 (i, topology_thread_cpumask(cpu)) {
struct V_99 * V_108 ;
V_108 = F_77 ( V_3 , V_17 ) . V_88 ;
if ( V_108 && V_108 -> V_103 == V_103 ) {
F_83 ( V_4 -> V_88 ) ;
V_4 -> V_88 = V_108 ;
break;
}
}
V_4 -> V_88 -> V_103 = V_103 ;
V_4 -> V_88 -> V_109 ++ ;
}
static void F_84 ( int V_100 )
{
struct V_3 * V_4 = & F_77 ( V_3 , V_100 ) ;
struct V_99 * V_108 ;
V_108 = V_4 -> V_88 ;
if ( V_108 ) {
if ( V_108 -> V_103 == - 1 || -- V_108 -> V_109 == 0 )
F_83 ( V_108 ) ;
V_4 -> V_88 = NULL ;
}
F_85 ( V_100 ) ;
}
static void F_86 ( void )
{
F_35 ( V_110 L_3 ) ;
V_9 . V_111 = 0 ;
V_9 . V_112 = NULL ;
}
static T_2 int F_87 ( void )
{
union V_113 V_114 ;
union V_115 V_116 ;
unsigned int V_117 ;
unsigned int V_118 ;
int V_38 ;
if ( ! F_88 ( & V_119 , V_120 ) ) {
switch ( V_119 . V_121 ) {
case 0x6 :
return F_89 () ;
case 0xf :
return F_90 () ;
}
return - V_122 ;
}
F_91 ( 10 , & V_116 . V_123 , & V_118 , & V_117 , & V_114 . V_123 ) ;
if ( V_116 . V_124 . V_125 <= V_126 )
return - V_122 ;
V_38 = V_116 . V_124 . V_127 ;
if ( V_38 < 2 )
V_9 = V_128 ;
else
V_9 = V_129 ;
V_9 . V_38 = V_38 ;
V_9 . V_44 = V_116 . V_124 . V_44 ;
V_9 . V_130 = V_116 . V_124 . V_131 ;
V_9 . V_132 = ( 1ULL << V_116 . V_124 . V_131 ) - 1 ;
if ( V_38 > 1 )
V_9 . V_45 = F_92 ( ( int ) V_114 . V_124 . V_45 , 3 ) ;
if ( V_38 > 1 ) {
T_1 V_133 ;
F_20 ( V_134 , V_133 ) ;
V_9 . V_135 . V_133 = V_133 ;
}
F_93 () ;
switch ( V_119 . V_136 ) {
case 14 :
F_94 ( L_4 ) ;
break;
case 15 :
V_9 . V_137 = F_86 ;
case 22 :
case 23 :
case 29 :
memcpy ( V_138 , V_139 ,
sizeof( V_138 ) ) ;
F_95 () ;
V_9 . V_140 = V_141 ;
V_9 . V_112 = V_142 ;
F_94 ( L_5 ) ;
break;
case 26 :
case 30 :
case 46 :
memcpy ( V_138 , V_143 ,
sizeof( V_138 ) ) ;
memcpy ( V_144 , V_145 ,
sizeof( V_144 ) ) ;
F_96 () ;
V_9 . V_140 = V_146 ;
V_9 . V_112 = V_147 ;
V_9 . V_148 = F_18 ;
V_9 . V_104 = V_149 ;
V_2 [ V_150 ] = 0x180010e ;
V_2 [ V_151 ] = 0x1803fb1 ;
if ( V_118 & 0x40 ) {
V_2 [ V_152 ] = 0x7f89 ;
F_94 ( L_6 ) ;
}
F_94 ( L_7 ) ;
break;
case 28 :
memcpy ( V_138 , V_153 ,
sizeof( V_138 ) ) ;
F_97 () ;
V_9 . V_140 = V_154 ;
V_9 . V_112 = V_155 ;
F_94 ( L_8 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_138 , V_156 ,
sizeof( V_138 ) ) ;
memcpy ( V_144 , V_145 ,
sizeof( V_144 ) ) ;
F_96 () ;
V_9 . V_140 = V_157 ;
V_9 . V_148 = F_18 ;
V_9 . V_112 = V_158 ;
V_9 . V_104 = V_159 ;
V_9 . V_73 |= V_74 ;
V_2 [ V_150 ] = 0x180010e ;
V_2 [ V_151 ] = 0x1803fb1 ;
F_94 ( L_9 ) ;
break;
case 42 :
case 45 :
memcpy ( V_138 , V_160 ,
sizeof( V_138 ) ) ;
F_96 () ;
V_9 . V_140 = V_161 ;
V_9 . V_112 = V_162 ;
V_9 . V_104 = V_163 ;
V_9 . V_73 |= V_74 ;
V_9 . V_73 |= V_107 ;
V_2 [ V_150 ] = 0x180010e ;
V_2 [ V_151 ] = 0x18001b1 ;
F_94 ( L_10 ) ;
break;
default:
switch ( V_9 . V_38 ) {
case 1 :
V_9 . V_140 = V_164 ;
F_94 ( L_11 ) ;
break;
default:
V_9 . V_140 = V_154 ;
F_94 ( L_12 ) ;
break;
}
}
return 0 ;
}
static int F_87 ( void )
{
return 0 ;
}
static struct V_99 * F_72 ( int V_100 )
{
return NULL ;
}
