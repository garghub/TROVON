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
F_4 ( V_5 ,
V_9 . V_10 & ~ V_4 -> V_11 ) ;
if ( F_5 ( V_6 , V_4 -> V_7 ) ) {
struct V_12 * V_13 =
V_4 -> V_14 [ V_6 ] ;
if ( F_12 ( ! V_13 ) )
return;
F_13 ( V_13 -> V_15 . V_16 ) ;
}
}
static void F_14 ( void )
{
struct V_3 * V_4 = & F_3 ( V_3 ) ;
static const unsigned long V_17 [ 4 ] = {
0x4300B5 ,
0x4300D2 ,
0x4300B1 ,
0x4300B1
} ;
struct V_12 * V_13 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_13 = V_4 -> V_14 [ V_18 ] ;
if ( V_13 )
F_15 ( V_13 ) ;
}
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
F_4 ( V_19 + V_18 , V_17 [ V_18 ] ) ;
F_4 ( V_20 + V_18 , 0x0 ) ;
}
F_4 ( V_5 , 0xf ) ;
F_4 ( V_5 , 0x0 ) ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_13 = V_4 -> V_14 [ V_18 ] ;
if ( V_13 ) {
F_16 ( V_13 ) ;
F_17 ( & V_13 -> V_15 ,
V_21 ) ;
} else
F_4 ( V_19 + V_18 , 0x0 ) ;
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
T_1 V_22 ;
F_20 ( V_23 , V_22 ) ;
return V_22 ;
}
static inline void F_21 ( T_1 V_24 )
{
F_4 ( V_25 , V_24 ) ;
}
static void F_22 ( struct V_26 * V_27 )
{
int V_28 = V_27 -> V_28 - V_29 ;
T_1 V_30 , V_31 ;
V_31 = 0xfULL << ( V_28 * 4 ) ;
F_20 ( V_27 -> V_32 , V_30 ) ;
V_30 &= ~ V_31 ;
F_4 ( V_27 -> V_32 , V_30 ) ;
}
static void F_23 ( struct V_12 * V_13 )
{
struct V_26 * V_27 = & V_13 -> V_15 ;
struct V_3 * V_4 = & F_3 ( V_3 ) ;
if ( F_24 ( V_27 -> V_28 == V_6 ) ) {
F_6 () ;
F_25 () ;
return;
}
V_4 -> V_11 &= ~ ( 1ull << V_27 -> V_28 ) ;
V_4 -> V_33 &= ~ ( 1ull << V_27 -> V_28 ) ;
if ( F_24 ( V_27 -> V_32 == V_34 ) ) {
F_22 ( V_27 ) ;
return;
}
F_26 ( V_13 ) ;
if ( F_24 ( V_13 -> V_35 . V_36 ) )
F_27 ( V_13 ) ;
}
static void F_28 ( struct V_26 * V_27 )
{
int V_28 = V_27 -> V_28 - V_29 ;
T_1 V_30 , V_37 , V_31 ;
V_37 = 0x8ULL ;
if ( V_27 -> V_16 & V_38 )
V_37 |= 0x2 ;
if ( V_27 -> V_16 & V_39 )
V_37 |= 0x1 ;
if ( V_9 . V_40 > 2 && V_27 -> V_16 & V_41 )
V_37 |= 0x4 ;
V_37 <<= ( V_28 * 4 ) ;
V_31 = 0xfULL << ( V_28 * 4 ) ;
F_20 ( V_27 -> V_32 , V_30 ) ;
V_30 &= ~ V_31 ;
V_30 |= V_37 ;
F_4 ( V_27 -> V_32 , V_30 ) ;
}
static void F_29 ( struct V_12 * V_13 )
{
struct V_26 * V_27 = & V_13 -> V_15 ;
struct V_3 * V_4 = & F_3 ( V_3 ) ;
if ( F_24 ( V_27 -> V_28 == V_6 ) ) {
if ( ! F_30 ( V_3 . V_42 ) )
return;
F_13 ( V_27 -> V_16 ) ;
return;
}
if ( V_13 -> V_35 . V_43 )
V_4 -> V_11 |= ( 1ull << V_27 -> V_28 ) ;
if ( V_13 -> V_35 . V_44 )
V_4 -> V_33 |= ( 1ull << V_27 -> V_28 ) ;
if ( F_24 ( V_27 -> V_32 == V_34 ) ) {
F_28 ( V_27 ) ;
return;
}
if ( F_24 ( V_13 -> V_35 . V_36 ) )
F_31 ( V_13 ) ;
F_17 ( V_27 , V_21 ) ;
}
int F_32 ( struct V_12 * V_13 )
{
F_15 ( V_13 ) ;
return F_16 ( V_13 ) ;
}
static void F_33 ( void )
{
struct V_45 * V_46 = F_30 ( V_3 . V_46 ) ;
unsigned long V_47 ;
int V_28 ;
if ( ! V_9 . V_48 )
return;
F_34 ( V_47 ) ;
F_35 ( L_1 , F_36 () ) ;
for ( V_28 = 0 ; V_28 < V_9 . V_48 ; V_28 ++ ) {
F_37 ( F_38 ( V_28 ) , 0ull ) ;
F_37 ( F_39 ( V_28 ) , 0ull ) ;
}
for ( V_28 = 0 ; V_28 < V_9 . V_49 ; V_28 ++ )
F_37 ( V_50 + V_28 , 0ull ) ;
if ( V_46 )
V_46 -> V_51 = V_46 -> V_52 ;
F_40 ( V_47 ) ;
}
static int F_41 ( struct V_53 * V_54 )
{
struct V_55 V_56 ;
struct V_3 * V_4 ;
int V_57 , V_58 ;
T_1 V_22 ;
int V_59 ;
F_42 ( & V_56 , 0 ) ;
V_4 = & F_3 ( V_3 ) ;
F_43 ( V_60 , V_61 ) ;
F_2 () ;
V_59 = F_25 () ;
V_22 = F_19 () ;
if ( ! V_22 ) {
F_9 ( 0 ) ;
return V_59 ;
}
V_58 = 0 ;
V_62:
F_21 ( V_22 ) ;
if ( ++ V_58 > 100 ) {
F_44 ( 1 , L_2 ) ;
F_45 () ;
F_33 () ;
goto V_63;
}
F_46 ( V_64 ) ;
F_47 () ;
if ( F_48 ( 62 , ( unsigned long * ) & V_22 ) ) {
V_59 ++ ;
V_9 . V_65 ( V_54 ) ;
}
F_49 (bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct V_12 * V_13 = V_4 -> V_14 [ V_57 ] ;
V_59 ++ ;
if ( ! F_5 ( V_57 , V_4 -> V_7 ) )
continue;
if ( ! F_32 ( V_13 ) )
continue;
V_56 . V_66 = V_13 -> V_15 . V_67 ;
if ( F_50 ( V_13 , & V_56 , V_54 ) )
F_51 ( V_13 , 0 ) ;
}
V_22 = F_19 () ;
if ( V_22 )
goto V_62;
V_63:
F_9 ( 0 ) ;
return V_59 ;
}
static struct V_68 *
F_52 ( struct V_12 * V_13 )
{
struct V_26 * V_27 = & V_13 -> V_15 ;
unsigned int V_1 , V_69 ;
if ( V_13 -> V_35 . V_70 )
return NULL ;
V_1 = V_27 -> V_16 & V_71 ;
V_69 = V_9 . V_72 ( V_73 ) ;
if ( F_24 ( V_1 == V_69 && V_27 -> V_74 == 1 ) )
return & V_75 ;
return NULL ;
}
static bool F_53 ( struct V_12 * V_13 , int V_76 )
{
if ( ! ( V_9 . V_77 & V_78 ) )
return false ;
if ( V_13 -> V_15 . V_79 . V_28 == V_80 ) {
V_13 -> V_15 . V_16 &= ~ V_71 ;
V_13 -> V_15 . V_16 |= 0x01bb ;
V_13 -> V_15 . V_79 . V_28 = V_81 ;
V_13 -> V_15 . V_79 . V_82 = V_83 ;
} else if ( V_13 -> V_15 . V_79 . V_28 == V_81 ) {
V_13 -> V_15 . V_16 &= ~ V_71 ;
V_13 -> V_15 . V_16 |= 0x01b7 ;
V_13 -> V_15 . V_79 . V_28 = V_80 ;
V_13 -> V_15 . V_79 . V_82 = V_84 ;
}
if ( V_13 -> V_15 . V_79 . V_28 == V_76 )
return false ;
return true ;
}
static struct V_68 *
F_54 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_68 * V_85 = & V_86 ;
struct V_87 * V_82 = & V_13 -> V_15 . V_79 ;
struct V_88 * V_89 ;
unsigned long V_47 ;
int V_76 = V_82 -> V_28 ;
if ( V_82 -> V_90 )
return & V_91 ;
V_62:
V_89 = & V_4 -> V_92 -> V_54 [ V_82 -> V_28 ] ;
F_55 ( & V_89 -> V_93 , V_47 ) ;
if ( ! F_56 ( & V_89 -> V_94 ) || V_89 -> V_16 == V_82 -> V_16 ) {
V_89 -> V_16 = V_82 -> V_16 ;
V_89 -> V_82 = V_82 -> V_82 ;
F_57 ( & V_89 -> V_94 ) ;
V_82 -> V_90 = 1 ;
V_85 = & V_91 ;
} else if ( F_53 ( V_13 , V_76 ) ) {
F_58 ( & V_89 -> V_93 , V_47 ) ;
goto V_62;
}
F_58 ( & V_89 -> V_93 , V_47 ) ;
return V_85 ;
}
static void
F_59 ( struct V_3 * V_4 ,
struct V_87 * V_82 )
{
struct V_88 * V_89 ;
if ( ! V_82 -> V_90 )
return;
V_89 = & V_4 -> V_92 -> V_54 [ V_82 -> V_28 ] ;
F_60 ( & V_89 -> V_94 ) ;
V_82 -> V_90 = 0 ;
}
static struct V_68 *
F_61 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_68 * V_85 = NULL ;
if ( V_13 -> V_15 . V_79 . V_28 != V_95 )
V_85 = F_54 ( V_4 , V_13 ) ;
return V_85 ;
}
struct V_68 *
F_62 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_68 * V_85 ;
if ( V_9 . V_96 ) {
F_63 (c, x86_pmu.event_constraints) {
if ( ( V_13 -> V_15 . V_16 & V_85 -> V_97 ) == V_85 -> V_98 )
return V_85 ;
}
}
return & V_91 ;
}
static struct V_68 *
F_64 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_68 * V_85 ;
V_85 = F_52 ( V_13 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_65 ( V_13 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_61 ( V_4 , V_13 ) ;
if ( V_85 )
return V_85 ;
return F_62 ( V_4 , V_13 ) ;
}
static void
F_66 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_87 * V_82 ;
V_82 = & V_13 -> V_15 . V_79 ;
if ( V_82 -> V_28 != V_95 )
F_59 ( V_4 , V_82 ) ;
}
static void F_67 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
F_66 ( V_4 , V_13 ) ;
}
static int F_68 ( struct V_12 * V_13 )
{
int V_99 = F_69 ( V_13 ) ;
if ( V_99 )
return V_99 ;
if ( V_13 -> V_35 . V_36 &&
( V_13 -> V_15 . V_16 & V_100 ) == 0x003c ) {
T_1 V_101 = 0x108000c0 ;
V_101 |= ( V_13 -> V_15 . V_16 & ~ V_100 ) ;
V_13 -> V_15 . V_16 = V_101 ;
}
if ( V_13 -> V_35 . type != V_102 )
return 0 ;
if ( ! ( V_13 -> V_35 . V_16 & V_41 ) )
return 0 ;
if ( V_9 . V_40 < 3 )
return - V_103 ;
if ( F_70 () && ! F_71 ( V_104 ) )
return - V_105 ;
V_13 -> V_15 . V_16 |= V_41 ;
return 0 ;
}
struct V_106 * F_72 ( int * V_107 )
{
if ( V_9 . V_108 )
return V_9 . V_108 ( V_107 ) ;
* V_107 = 0 ;
return NULL ;
}
static struct V_106 * F_73 ( int * V_107 )
{
struct V_3 * V_4 = & F_3 ( V_3 ) ;
struct V_106 * V_109 = V_4 -> V_110 ;
V_109 [ 0 ] . V_111 = V_5 ;
V_109 [ 0 ] . V_112 = V_9 . V_10 & ~ V_4 -> V_11 ;
V_109 [ 0 ] . V_113 = V_9 . V_10 & ~ V_4 -> V_33 ;
* V_107 = 1 ;
return V_109 ;
}
static struct V_106 * F_74 ( int * V_107 )
{
struct V_3 * V_4 = & F_3 ( V_3 ) ;
struct V_106 * V_109 = V_4 -> V_110 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 . V_48 ; V_28 ++ ) {
struct V_12 * V_13 = V_4 -> V_14 [ V_28 ] ;
V_109 [ V_28 ] . V_111 = F_38 ( V_28 ) ;
V_109 [ V_28 ] . V_112 = V_109 [ V_28 ] . V_113 = 0 ;
if ( ! F_5 ( V_28 , V_4 -> V_7 ) )
continue;
V_109 [ V_28 ] . V_112 = V_109 [ V_28 ] . V_113 =
V_13 -> V_15 . V_16 | V_21 ;
if ( V_13 -> V_35 . V_43 )
V_109 [ V_28 ] . V_112 &= ~ V_21 ;
else if ( V_13 -> V_35 . V_44 )
V_109 [ V_28 ] . V_113 &= ~ V_21 ;
}
* V_107 = V_9 . V_48 ;
return V_109 ;
}
static void F_75 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_35 . V_43 )
F_76 ( V_13 ) ;
}
static void F_77 ( int V_8 )
{
struct V_3 * V_4 = & F_3 ( V_3 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 . V_48 ; V_28 ++ ) {
struct V_26 * V_27 = & V_4 -> V_14 [ V_28 ] -> V_15 ;
if ( ! F_5 ( V_28 , V_4 -> V_7 ) ||
V_4 -> V_14 [ V_28 ] -> V_35 . V_43 )
continue;
F_17 ( V_27 , V_21 ) ;
}
}
struct V_114 * F_78 ( int V_115 )
{
struct V_114 * V_54 ;
int V_18 ;
V_54 = F_79 ( sizeof( struct V_114 ) ,
V_116 , F_80 ( V_115 ) ) ;
if ( V_54 ) {
for ( V_18 = 0 ; V_18 < V_117 ; V_18 ++ )
F_81 ( & V_54 -> V_54 [ V_18 ] . V_93 ) ;
V_54 -> V_118 = - 1 ;
}
return V_54 ;
}
static int F_82 ( int V_115 )
{
struct V_3 * V_4 = & F_83 ( V_3 , V_115 ) ;
if ( ! V_9 . V_119 )
return V_120 ;
V_4 -> V_92 = F_78 ( V_115 ) ;
if ( ! V_4 -> V_92 )
return V_121 ;
return V_120 ;
}
static void F_84 ( int V_115 )
{
struct V_3 * V_4 = & F_83 ( V_3 , V_115 ) ;
int V_118 = F_85 ( V_115 ) ;
int V_18 ;
F_86 ( V_115 ) ;
F_87 () ;
if ( ! V_4 -> V_92 || ( V_9 . V_77 & V_122 ) )
return;
F_88 (i, topology_thread_cpumask(cpu)) {
struct V_114 * V_123 ;
V_123 = F_83 ( V_3 , V_18 ) . V_92 ;
if ( V_123 && V_123 -> V_118 == V_118 ) {
V_4 -> V_124 = V_4 -> V_92 ;
V_4 -> V_92 = V_123 ;
break;
}
}
V_4 -> V_92 -> V_118 = V_118 ;
V_4 -> V_92 -> V_125 ++ ;
}
static void F_89 ( int V_115 )
{
struct V_3 * V_4 = & F_83 ( V_3 , V_115 ) ;
struct V_114 * V_123 ;
V_123 = V_4 -> V_92 ;
if ( V_123 ) {
if ( V_123 -> V_118 == - 1 || -- V_123 -> V_125 == 0 )
F_90 ( V_123 ) ;
V_4 -> V_92 = NULL ;
}
F_91 ( V_115 ) ;
}
static void F_92 ( void )
{
F_35 ( V_126 L_3 ) ;
V_9 . V_127 = 0 ;
V_9 . V_128 = NULL ;
}
static void F_93 ( void )
{
F_35 ( V_126 L_3 ) ;
V_9 . V_127 = 0 ;
V_9 . V_128 = NULL ;
}
T_2 int F_94 ( void )
{
union V_129 V_130 ;
union V_131 V_132 ;
unsigned int V_133 ;
unsigned int V_134 ;
int V_40 ;
if ( ! F_95 ( & V_135 , V_136 ) ) {
switch ( V_135 . V_137 ) {
case 0x6 :
return F_96 () ;
case 0xf :
return F_97 () ;
}
return - V_138 ;
}
F_98 ( 10 , & V_132 . V_139 , & V_134 , & V_133 , & V_130 . V_139 ) ;
if ( V_132 . V_140 . V_141 <= V_142 )
return - V_138 ;
V_40 = V_132 . V_140 . V_143 ;
if ( V_40 < 2 )
V_9 = V_144 ;
else
V_9 = V_145 ;
V_9 . V_40 = V_40 ;
V_9 . V_48 = V_132 . V_140 . V_48 ;
V_9 . V_146 = V_132 . V_140 . V_147 ;
V_9 . V_148 = ( 1ULL << V_132 . V_140 . V_147 ) - 1 ;
if ( V_40 > 1 )
V_9 . V_49 = F_99 ( ( int ) V_130 . V_140 . V_49 , 3 ) ;
if ( V_40 > 1 ) {
T_1 V_149 ;
F_20 ( V_150 , V_149 ) ;
V_9 . V_151 . V_149 = V_149 ;
}
F_100 () ;
switch ( V_135 . V_152 ) {
case 14 :
F_101 ( L_4 ) ;
break;
case 15 :
V_9 . V_153 = F_92 ;
case 22 :
case 23 :
case 29 :
memcpy ( V_154 , V_155 ,
sizeof( V_154 ) ) ;
F_102 () ;
V_9 . V_96 = V_156 ;
V_9 . V_128 = V_157 ;
F_101 ( L_5 ) ;
break;
case 26 :
case 30 :
case 46 :
memcpy ( V_154 , V_158 ,
sizeof( V_154 ) ) ;
memcpy ( V_159 , V_160 ,
sizeof( V_159 ) ) ;
F_103 () ;
V_9 . V_96 = V_161 ;
V_9 . V_128 = V_162 ;
V_9 . V_163 = F_18 ;
V_9 . V_119 = V_164 ;
V_2 [ V_165 ] = 0x180010e ;
V_2 [ V_166 ] = 0x1803fb1 ;
if ( V_134 & 0x40 ) {
V_2 [ V_167 ] = 0x7f89 ;
F_101 ( L_6 ) ;
}
F_101 ( L_7 ) ;
break;
case 28 :
memcpy ( V_154 , V_168 ,
sizeof( V_154 ) ) ;
F_104 () ;
V_9 . V_96 = V_169 ;
V_9 . V_128 = V_170 ;
F_101 ( L_8 ) ;
break;
case 37 :
case 44 :
case 47 :
memcpy ( V_154 , V_171 ,
sizeof( V_154 ) ) ;
memcpy ( V_159 , V_160 ,
sizeof( V_159 ) ) ;
F_103 () ;
V_9 . V_96 = V_172 ;
V_9 . V_163 = F_18 ;
V_9 . V_128 = V_173 ;
V_9 . V_119 = V_174 ;
V_9 . V_77 |= V_78 ;
V_2 [ V_165 ] = 0x180010e ;
V_2 [ V_166 ] = 0x1803fb1 ;
F_101 ( L_9 ) ;
break;
case 42 :
V_9 . V_153 = F_93 ;
case 45 :
memcpy ( V_154 , V_175 ,
sizeof( V_154 ) ) ;
F_103 () ;
V_9 . V_96 = V_176 ;
V_9 . V_128 = V_177 ;
V_9 . V_119 = V_178 ;
V_9 . V_77 |= V_78 ;
V_9 . V_77 |= V_122 ;
V_2 [ V_165 ] = 0x180010e ;
V_2 [ V_166 ] = 0x18001b1 ;
F_101 ( L_10 ) ;
break;
default:
switch ( V_9 . V_40 ) {
case 1 :
V_9 . V_96 = V_179 ;
F_101 ( L_11 ) ;
break;
default:
V_9 . V_96 = V_169 ;
F_101 ( L_12 ) ;
break;
}
}
return 0 ;
}
