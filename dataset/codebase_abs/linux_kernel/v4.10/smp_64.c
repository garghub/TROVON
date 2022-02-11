void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 , L_1 ) ;
F_3 (i)
F_2 ( V_2 , L_2 , V_3 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
int V_3 ;
F_3 (i)
F_2 ( V_2 ,
L_3 ,
V_3 , F_5 ( V_3 ) . V_4 ) ;
}
void F_6 ( void )
{
int V_5 = F_7 () ;
V_6 = F_8 ( V_5 ) ;
if ( V_7 == V_8 )
F_9 () ;
F_10 () ;
F_11 () ;
if ( V_9 )
F_12 () ;
V_10 = 1 ;
__asm__ __volatile__("membar #Sync\n\t"
"flush %%g6" : : : "memory");
F_13 () -> V_11 = 0 ;
F_14 ( & V_12 . V_13 ) ;
V_14 -> V_15 = & V_12 ;
F_15 ( V_5 ) ;
while ( ! F_16 ( V_5 , & V_16 ) )
F_17 () ;
F_18 ( V_5 , true ) ;
F_19 () ;
F_20 () ;
F_21 ( V_17 ) ;
}
void F_22 ( void )
{
F_23 ( L_4 , F_24 () ) ;
F_25 ( L_5 ) ;
}
static inline long F_26 ( long * V_18 , long * V_19 )
{
unsigned long V_20 = 0 , V_21 = ~ 0UL , V_22 = 0 ;
unsigned long V_23 , V_24 , V_25 , V_26 ;
unsigned long V_3 ;
for ( V_3 = 0 ; V_3 < V_27 ; V_3 ++ ) {
V_24 = V_28 -> V_29 () ;
V_30 [ V_31 ] = 1 ;
F_27 ( L_6 ) ;
while ( ! ( V_26 = V_30 [ V_32 ] ) )
F_17 () ;
V_30 [ V_32 ] = 0 ;
F_28 () ;
V_25 = V_28 -> V_29 () ;
if ( V_25 - V_24 < V_21 - V_20 )
V_20 = V_24 , V_21 = V_25 , V_22 = V_26 ;
}
* V_18 = V_21 - V_20 ;
* V_19 = V_22 - V_20 ;
V_23 = ( V_20 / 2 + V_21 / 2 ) ;
if ( V_20 % 2 + V_21 % 2 == 2 )
V_23 ++ ;
return V_23 - V_22 ;
}
void F_29 ( void )
{
long V_3 , V_33 , V_34 , V_35 = 0 , V_36 = 0 ;
unsigned long V_37 , V_18 , V_38 ;
#if V_39
struct {
long V_18 ;
long V_19 ;
long V_40 ;
long V_41 ;
} V_42 [ V_43 ] ;
#endif
V_30 [ V_31 ] = 1 ;
while ( V_30 [ V_31 ] )
F_17 () ;
F_30 ( V_37 ) ;
{
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
V_33 = F_26 ( & V_18 , & V_38 ) ;
if ( V_33 == 0 )
V_36 = 1 ;
if ( ! V_36 ) {
if ( V_3 > 0 ) {
V_35 += - V_33 ;
V_34 = - V_33 + V_35 / 4 ;
} else
V_34 = - V_33 ;
V_28 -> V_44 ( V_34 ) ;
}
#if V_39
V_42 [ V_3 ] . V_18 = V_18 ;
V_42 [ V_3 ] . V_19 = V_38 ;
V_42 [ V_3 ] . V_40 = V_33 ;
V_42 [ V_3 ] . V_41 = V_35 / 4 ;
#endif
}
}
F_31 ( V_37 ) ;
#if V_39
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
F_23 ( L_7 ,
V_42 [ V_3 ] . V_18 , V_42 [ V_3 ] . V_19 , V_42 [ V_3 ] . V_40 , V_42 [ V_3 ] . V_41 ) ;
#endif
F_23 ( V_45 L_8
L_9 ,
F_24 () , V_33 , V_18 ) ;
}
static void F_32 ( int V_46 )
{
unsigned long V_37 , V_3 ;
V_30 [ V_31 ] = 0 ;
F_33 ( V_46 ) ;
while ( ! V_30 [ V_31 ] )
F_17 () ;
V_30 [ V_31 ] = 0 ;
F_27 ( L_6 ) ;
F_34 ( & V_47 , V_37 ) ;
{
for ( V_3 = 0 ; V_3 < V_43 * V_27 ; V_3 ++ ) {
while ( ! V_30 [ V_31 ] )
F_17 () ;
V_30 [ V_31 ] = 0 ;
F_28 () ;
V_30 [ V_32 ] = V_28 -> V_29 () ;
F_27 ( L_6 ) ;
}
}
F_35 ( & V_47 , V_37 ) ;
}
static void F_36 ( unsigned int V_46 , unsigned long V_48 ,
void * * V_49 )
{
extern unsigned long V_50 ;
extern unsigned long V_51 ;
struct V_52 * V_53 ;
unsigned long V_54 ;
struct V_55 * V_56 ;
T_1 V_57 , V_58 ;
unsigned long V_59 ;
int V_3 ;
V_53 = F_37 ( sizeof( * V_53 ) +
( sizeof( struct V_60 ) *
V_61 - 1 ) ,
V_62 ) ;
if ( ! V_53 ) {
F_23 ( V_63 L_10
L_11 ) ;
return;
}
* V_49 = V_53 ;
V_53 -> V_46 = V_46 ;
V_53 -> V_64 = V_61 ;
V_56 = & V_65 [ V_46 ] ;
V_53 -> V_66 = ( unsigned long ) & V_56 -> V_67 ;
V_53 -> V_68 = F_38 ( & V_56 -> V_67 ) ;
V_53 -> V_48 = V_48 ;
V_57 = ( unsigned long ) V_69 ;
V_58 = V_51 ;
for ( V_3 = 0 ; V_3 < V_53 -> V_64 ; V_3 ++ ) {
V_53 -> V_70 [ V_3 ] . V_71 = V_57 ;
V_53 -> V_70 [ V_3 ] . V_72 = V_58 ;
V_57 += 0x400000 ;
V_58 += 0x400000 ;
}
V_54 = F_38 ( V_73 ) ;
V_59 = F_39 ( V_46 , V_54 ,
F_38 ( & V_50 ) ,
F_40 ( V_53 ) ) ;
if ( V_59 )
F_23 ( V_63 L_12
L_13 , V_59 ) ;
}
static int F_41 ( unsigned int V_46 , struct V_74 * V_75 )
{
unsigned long V_76 =
( unsigned long ) ( & V_77 ) ;
unsigned long V_78 =
( unsigned long ) ( & V_79 ) ;
void * V_80 = NULL ;
int V_81 , V_82 ;
V_10 = 0 ;
V_79 = F_42 ( V_75 ) ;
if ( V_7 == V_8 ) {
#if F_43 ( V_83 ) && F_43 ( V_84 )
if ( V_85 )
F_36 ( V_46 ,
( unsigned long ) V_79 ,
& V_80 ) ;
else
#endif
F_44 ( V_46 , V_76 , V_78 ) ;
} else {
struct V_86 * V_87 = F_45 ( V_46 ) ;
F_46 ( V_87 -> V_88 , V_76 , V_78 ) ;
}
for ( V_81 = 0 ; V_81 < 50000 ; V_81 ++ ) {
if ( V_10 )
break;
F_47 ( 100 ) ;
}
if ( V_10 ) {
V_82 = 0 ;
} else {
F_23 ( L_14 , V_46 ) ;
V_82 = - V_89 ;
}
V_79 = NULL ;
F_48 ( V_80 ) ;
return V_82 ;
}
static void F_49 ( T_1 V_90 , T_1 V_91 , T_1 V_92 , T_1 V_93 , unsigned long V_46 )
{
T_1 V_94 , V_95 ;
int V_96 , V_97 ;
if ( V_98 ) {
V_46 = ( ( ( V_46 & 0x3c ) << 1 ) |
( ( V_46 & 0x40 ) >> 4 ) |
( V_46 & 0x3 ) ) ;
}
V_95 = ( V_46 << 14 ) | 0x70 ;
V_99:
V_97 = 0x40 ;
__asm__ __volatile__(
"wrpr %1, %2, %%pstate\n\t"
"stxa %4, [%0] %3\n\t"
"stxa %5, [%0+%8] %3\n\t"
"add %0, %8, %0\n\t"
"stxa %6, [%0+%8] %3\n\t"
"membar #Sync\n\t"
"stxa %%g0, [%7] %3\n\t"
"membar #Sync\n\t"
"mov 0x20, %%g1\n\t"
"ldxa [%%g1] 0x7f, %%g0\n\t"
"membar #Sync"
: "=r" (tmp)
: "r" (pstate), "i" (PSTATE_IE), "i" (ASI_INTR_W),
"r" (data0), "r" (data1), "r" (data2), "r" (target),
"r" (0x10), "0" (tmp)
: "g1");
V_96 = 100000 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (result)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( V_94 == 0 ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
return;
}
V_96 -= 1 ;
if ( V_96 == 0 )
break;
} while ( V_94 & 0x1 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_96 == 0 ) {
F_23 ( L_15 ,
F_24 () , V_94 ) ;
} else {
F_47 ( 2 ) ;
goto V_99;
}
}
static void F_50 ( struct V_55 * V_56 , int V_100 )
{
T_1 * V_101 , V_90 , V_91 , V_92 ;
T_2 * V_102 ;
T_1 V_93 ;
int V_3 ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_102 = F_51 ( V_56 -> V_103 ) ;
V_101 = F_51 ( V_56 -> V_104 ) ;
V_90 = V_101 [ 0 ] ;
V_91 = V_101 [ 1 ] ;
V_92 = V_101 [ 2 ] ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ )
F_49 ( V_90 , V_91 , V_92 , V_93 , V_102 [ V_3 ] ) ;
}
static void F_52 ( struct V_55 * V_56 , int V_100 )
{
int V_105 , V_106 , V_107 ;
T_1 * V_101 , V_93 , V_108 , V_109 ;
T_2 * V_102 ;
V_102 = F_51 ( V_56 -> V_103 ) ;
V_101 = F_51 ( V_56 -> V_104 ) ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_106 = ( ( V_108 >> 32 ) == V_110 ||
( V_108 >> 32 ) == V_111 ) ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_112:
V_107 = 0 ;
__asm__ __volatile__("wrpr %0, %1, %%pstate\n\t"
: : "r" (pstate), "i" (PSTATE_IE));
__asm__ __volatile__("stxa %0, [%3] %6\n\t"
"stxa %1, [%4] %6\n\t"
"stxa %2, [%5] %6\n\t"
"membar #Sync\n\t"
:
: "r" (mondo[0]), "r" (mondo[1]), "r" (mondo[2]),
"r" (0x40), "r" (0x50), "r" (0x60),
"i" (ASI_INTR_W));
V_105 = 0 ;
V_109 = 0 ;
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ ) {
T_1 V_95 , V_113 ;
V_113 = V_102 [ V_3 ] ;
if ( V_113 == 0xffff )
continue;
V_95 = ( V_113 << 14 ) | 0x70 ;
if ( V_106 ) {
V_109 |= ( 0x1UL << ( V_113 * 2 ) ) ;
} else {
V_95 |= ( V_105 << 24 ) ;
V_109 |= ( 0x1UL <<
( V_105 * 2 ) ) ;
}
__asm__ __volatile__(
"stxa %%g0, [%0] %1\n\t"
"membar #Sync\n\t"
:
: "r" (target), "i" (ASI_INTR_W));
V_105 ++ ;
if ( V_105 == 32 ) {
V_107 = 1 ;
break;
}
}
}
{
T_1 V_114 , V_115 ;
long V_96 ;
V_96 = 100000 * V_105 ;
V_115 = V_109 << 1 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dispatch_stat)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( ! ( V_114 & ( V_109 | V_115 ) ) ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( F_53 ( V_107 ) ) {
int V_3 , V_116 = 0 ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ ) {
if ( V_102 [ V_3 ] == 0xffff )
continue;
V_102 [ V_3 ] = 0xffff ;
V_116 ++ ;
if ( V_116 == 32 )
break;
}
goto V_112;
}
return;
}
if ( ! -- V_96 )
break;
} while ( V_114 & V_109 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_114 & V_109 ) {
F_23 ( L_15 ,
F_24 () , V_114 ) ;
} else {
int V_3 , V_117 = 0 ;
F_47 ( 2 * V_105 ) ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ ) {
T_1 V_118 , V_113 ;
V_113 = V_102 [ V_3 ] ;
if ( V_113 == 0xffff )
continue;
if ( V_106 )
V_118 = ( 0x2UL << ( 2 * V_113 ) ) ;
else
V_118 = ( 0x2UL <<
V_117 ) ;
if ( ( V_114 & V_118 ) == 0 )
V_102 [ V_3 ] = 0xffff ;
V_117 += 2 ;
if ( V_117 == 64 )
break;
}
goto V_112;
}
}
}
static void F_54 ( struct V_55 * V_56 , int V_100 )
{
int V_119 , V_120 , V_121 , V_3 , V_122 ;
unsigned long V_123 ;
T_2 * V_102 ;
V_120 = F_24 () ;
V_102 = F_51 ( V_56 -> V_103 ) ;
V_122 = 0 ;
V_119 = 0 ;
V_121 = 0 ;
do {
int V_124 , V_125 ;
V_123 = F_55 ( V_100 ,
V_56 -> V_103 ,
V_56 -> V_104 ) ;
if ( F_56 ( V_123 == V_126 ) )
break;
V_125 = 0 ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ ) {
if ( F_56 ( V_102 [ V_3 ] == 0xffff ) )
V_125 ++ ;
}
V_124 = 0 ;
if ( V_125 > V_121 )
V_124 = 1 ;
V_121 = V_125 ;
if ( F_53 ( V_123 == V_127 ) ) {
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ ) {
long V_128 ;
T_2 V_46 ;
V_46 = V_102 [ V_3 ] ;
if ( V_46 == 0xffff )
continue;
V_128 = F_57 ( V_46 ) ;
if ( V_128 == V_129 ) {
V_122 = ( V_46 + 1 ) ;
V_102 [ V_3 ] = 0xffff ;
}
}
} else if ( F_53 ( V_123 != V_130 ) )
goto V_131;
if ( F_53 ( ! V_124 ) ) {
if ( F_53 ( ++ V_119 > 10000 ) )
goto V_132;
F_47 ( 2 * V_100 ) ;
}
} while ( 1 );
if ( F_53 ( V_122 ) )
goto V_133;
return;
V_133:
F_23 ( V_134 L_16
L_17 ,
V_120 , V_122 - 1 ) ;
return;
V_132:
F_23 ( V_134 L_18
L_19 ,
V_120 , V_119 ) ;
goto V_135;
V_131:
F_23 ( V_134 L_20 ,
V_120 , V_123 ) ;
F_23 ( V_134 L_21
L_22 ,
V_120 , V_100 , V_56 -> V_103 , V_56 -> V_104 ) ;
V_135:
F_23 ( V_134 L_23 , V_120 ) ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ )
F_23 ( L_24 , V_102 [ V_3 ] ) ;
F_23 ( L_25 ) ;
}
static void F_58 ( T_1 V_90 , T_1 V_91 , T_1 V_92 , const T_3 * V_136 )
{
struct V_55 * V_56 ;
int V_120 , V_3 , V_100 ;
unsigned long V_37 ;
T_2 * V_102 ;
T_1 * V_101 ;
F_30 ( V_37 ) ;
V_120 = F_24 () ;
V_56 = & V_65 [ V_120 ] ;
V_101 = F_51 ( V_56 -> V_104 ) ;
V_101 [ 0 ] = V_90 ;
V_101 [ 1 ] = V_91 ;
V_101 [ 2 ] = V_92 ;
F_28 () ;
V_102 = F_51 ( V_56 -> V_103 ) ;
V_100 = 0 ;
F_59 (i, mask) {
if ( V_3 == V_120 || ! F_60 ( V_3 ) )
continue;
V_102 [ V_100 ++ ] = V_3 ;
}
if ( V_100 )
F_61 ( V_56 , V_100 ) ;
F_31 ( V_37 ) ;
}
static void F_62 ( unsigned long * V_137 , T_4 V_138 , T_1 V_91 , T_1 V_92 , const T_3 * V_136 )
{
T_1 V_90 = ( ( ( T_1 ) V_138 ) << 32 | ( ( ( T_1 ) V_137 ) & 0xffffffff ) ) ;
F_58 ( V_90 , V_91 , V_92 , V_136 ) ;
}
static void F_63 ( unsigned long * V_137 , T_4 V_138 , T_1 V_91 , T_1 V_92 )
{
F_62 ( V_137 , V_138 , V_91 , V_92 , V_139 ) ;
}
static void F_33 ( int V_46 )
{
F_58 ( ( T_1 ) & V_140 , 0 , 0 ,
F_64 ( V_46 ) ) ;
}
void F_65 ( const struct V_141 * V_136 )
{
F_58 ( ( T_1 ) & V_142 , 0 , 0 , V_136 ) ;
}
void F_66 ( int V_46 )
{
F_58 ( ( T_1 ) & V_143 , 0 , 0 ,
F_64 ( V_46 ) ) ;
}
void T_5 F_67 ( int V_144 , struct V_145 * V_146 )
{
F_68 ( 1 << V_144 ) ;
F_69 () ;
F_70 () ;
F_71 () ;
}
void T_5 F_72 ( int V_144 , struct V_145 * V_146 )
{
F_68 ( 1 << V_144 ) ;
F_69 () ;
F_73 () ;
F_71 () ;
}
static void F_74 ( void * V_147 )
{
struct V_55 * V_148 = & V_65 [ F_75 () ] ;
struct V_149 * V_150 = V_147 ;
if ( V_148 -> V_151 == F_40 ( V_150 -> V_152 ) )
F_76 ( V_150 ) ;
}
void F_77 ( struct V_149 * V_150 )
{
F_78 ( F_79 ( V_150 ) , F_74 , V_150 , 1 ) ;
}
static inline void F_80 ( struct V_153 * V_153 )
{
#ifdef F_81
F_82 ( F_83 ( V_153 ) ,
( ( V_7 == V_154 ) &&
F_84 ( V_153 ) != NULL ) ) ;
#else
if ( F_84 ( V_153 ) != NULL &&
V_7 == V_154 )
F_85 ( F_40 ( F_83 ( V_153 ) ) ) ;
#endif
}
void F_86 ( struct V_153 * V_153 , int V_46 )
{
int V_120 ;
if ( V_7 == V_8 )
return;
#ifdef F_87
F_14 ( & V_155 ) ;
#endif
V_120 = F_88 () ;
if ( V_46 == V_120 ) {
F_80 ( V_153 ) ;
} else if ( F_60 ( V_46 ) ) {
void * V_156 = F_83 ( V_153 ) ;
T_1 V_90 = 0 ;
if ( V_7 == V_154 ) {
V_90 = ( ( T_1 ) & V_157 ) ;
if ( F_84 ( V_153 ) != NULL )
V_90 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_158 || V_7 == V_159 ) {
#ifdef F_81
V_90 = ( ( T_1 ) & V_160 ) ;
#endif
}
if ( V_90 ) {
F_58 ( V_90 , F_40 ( V_156 ) ,
( T_1 ) V_156 , F_64 ( V_46 ) ) ;
#ifdef F_87
F_14 ( & V_161 ) ;
#endif
}
}
F_89 () ;
}
void F_90 ( struct V_149 * V_150 , struct V_153 * V_153 )
{
void * V_156 ;
T_1 V_90 ;
if ( V_7 == V_8 )
return;
F_19 () ;
#ifdef F_87
F_14 ( & V_155 ) ;
#endif
V_90 = 0 ;
V_156 = F_83 ( V_153 ) ;
if ( V_7 == V_154 ) {
V_90 = ( ( T_1 ) & V_157 ) ;
if ( F_84 ( V_153 ) != NULL )
V_90 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_158 || V_7 == V_159 ) {
#ifdef F_81
V_90 = ( ( T_1 ) & V_160 ) ;
#endif
}
if ( V_90 ) {
F_58 ( V_90 , F_40 ( V_156 ) ,
( T_1 ) V_156 , V_139 ) ;
#ifdef F_87
F_14 ( & V_161 ) ;
#endif
}
F_80 ( V_153 ) ;
F_91 () ;
}
void T_5 F_92 ( int V_144 , struct V_145 * V_146 )
{
struct V_149 * V_150 ;
unsigned long V_37 ;
F_68 ( 1 << V_144 ) ;
V_150 = V_14 -> V_15 ;
if ( F_53 ( ! V_150 || ( V_150 == & V_12 ) ) )
return;
F_93 ( & V_150 -> V_162 . V_163 , V_37 ) ;
if ( F_53 ( ! F_94 ( V_150 -> V_162 ) ) )
F_95 ( V_150 ) ;
F_96 ( & V_150 -> V_162 . V_163 , V_37 ) ;
F_97 ( V_150 ) ;
F_98 ( F_99 ( V_150 -> V_162 ) ,
V_164 ) ;
}
void F_100 ( void )
{
F_63 ( & V_165 , 0 , 0 , 0 ) ;
}
void F_101 ( unsigned long V_37 )
{
F_63 ( & V_166 , 0 , 0 , 0 ) ;
}
void F_102 ( void )
{
F_63 ( & V_167 , 0 , 0 , 0 ) ;
}
void F_103 ( void )
{
if ( V_7 == V_8 &&
V_168 >= V_169 )
F_63 ( & V_170 , 0 , 0 , 0 ) ;
else
F_63 ( & V_171 , 0 , 0 , 0 ) ;
}
void F_104 ( struct V_149 * V_150 )
{
T_4 V_138 = F_99 ( V_150 -> V_162 ) ;
int V_46 = F_88 () ;
if ( F_105 ( & V_150 -> V_172 ) == 1 ) {
F_106 ( F_79 ( V_150 ) , F_64 ( V_46 ) ) ;
goto V_173;
}
F_62 ( & V_174 ,
V_138 , 0 , 0 ,
F_79 ( V_150 ) ) ;
V_173:
F_98 ( V_138 , V_164 ) ;
F_89 () ;
}
static void F_107 ( void * V_147 )
{
struct V_175 * V_42 = V_147 ;
F_108 ( V_42 -> V_138 , V_42 -> V_113 , V_42 -> V_176 ) ;
}
void F_109 ( struct V_149 * V_150 , unsigned long V_113 , unsigned long * V_176 )
{
T_4 V_138 = F_99 ( V_150 -> V_162 ) ;
struct V_175 V_147 ;
int V_46 = F_88 () ;
V_147 . V_138 = V_138 ;
V_147 . V_113 = V_113 ;
V_147 . V_176 = V_176 ;
if ( V_150 == V_14 -> V_150 && F_105 ( & V_150 -> V_172 ) == 1 )
F_106 ( F_79 ( V_150 ) , F_64 ( V_46 ) ) ;
else
F_78 ( F_79 ( V_150 ) , F_107 ,
& V_147 , 1 ) ;
F_108 ( V_138 , V_113 , V_176 ) ;
F_89 () ;
}
void F_110 ( struct V_149 * V_150 , unsigned long V_71 )
{
unsigned long V_162 = F_99 ( V_150 -> V_162 ) ;
int V_46 = F_88 () ;
if ( V_150 == V_14 -> V_150 && F_105 ( & V_150 -> V_172 ) == 1 )
F_106 ( F_79 ( V_150 ) , F_64 ( V_46 ) ) ;
else
F_62 ( & V_177 ,
V_162 , V_71 , 0 ,
F_79 ( V_150 ) ) ;
F_111 ( V_162 , V_71 ) ;
F_89 () ;
}
void F_112 ( unsigned long V_178 , unsigned long V_179 )
{
V_178 &= V_180 ;
V_179 = F_113 ( V_179 ) ;
if ( V_178 != V_179 ) {
F_63 ( & V_181 ,
0 , V_178 , V_179 ) ;
F_114 ( V_178 , V_179 ) ;
}
}
void F_115 ( void )
{
int V_94 = F_116 ( 1 , & V_182 ) ;
if ( V_94 == 1 ) {
int V_183 = F_117 () ;
#ifdef F_118
F_23 ( L_26 ,
F_24 () ) ;
#endif
V_184 = 1 ;
F_14 ( & V_185 ) ;
F_63 ( & V_186 , 0 , 0 , 0 ) ;
while ( F_105 ( & V_185 ) != V_183 )
F_17 () ;
#ifdef F_118
F_23 ( L_27 ) ;
#endif
}
}
void F_119 ( void )
{
if ( F_120 ( & V_182 ) ) {
#ifdef F_118
F_23 ( L_28
L_29 ,
F_24 () ) ;
#endif
V_184 = 0 ;
F_27 ( L_6 ) ;
F_121 ( & V_185 ) ;
}
}
void T_5 F_122 ( int V_144 , struct V_145 * V_146 )
{
F_68 ( 1 << V_144 ) ;
F_19 () ;
__asm__ __volatile__("flushw");
F_123 ( 1 ) ;
F_14 ( & V_185 ) ;
F_27 ( L_6 ) ;
while ( V_184 )
F_17 () ;
F_121 ( & V_185 ) ;
F_123 ( 0 ) ;
F_91 () ;
}
int F_124 ( unsigned int V_187 )
{
return - V_188 ;
}
void T_6 F_125 ( unsigned int V_189 )
{
}
void F_126 ( void )
{
}
void T_6 F_127 ( void )
{
if ( V_7 == V_154 )
F_61 = F_50 ;
else if ( V_7 == V_158 || V_7 == V_159 )
F_61 = F_52 ;
else
F_61 = F_54 ;
}
void T_6 F_128 ( void )
{
int V_190 = F_129 () ;
int V_3 ;
if ( V_190 > V_191 )
V_190 = V_191 ;
for ( V_3 = 0 ; V_3 < V_190 ; V_3 ++ )
F_130 ( V_3 , true ) ;
for (; V_3 < V_192 ; V_3 ++ )
F_130 ( V_3 , false ) ;
}
void F_131 ( void )
{
unsigned int V_3 ;
F_132 (i) {
unsigned int V_193 ;
F_133 ( & V_194 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_195 == 0 ) {
F_134 ( V_3 , & V_194 [ V_3 ] ) ;
continue;
}
F_132 (j) {
if ( F_5 ( V_3 ) . V_195 ==
F_5 ( V_193 ) . V_195 )
F_134 ( V_193 , & V_194 [ V_3 ] ) ;
}
}
F_132 (i) {
unsigned int V_193 ;
F_132 (j) {
if ( F_5 ( V_3 ) . V_196 ==
F_5 ( V_193 ) . V_196 )
F_134 ( V_193 , & V_197 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_198 == F_5 ( V_193 ) . V_198 )
F_134 ( V_193 , & V_199 [ V_3 ] ) ;
}
}
F_132 (i) {
unsigned int V_193 ;
F_133 ( & F_135 ( V_200 , V_3 ) ) ;
if ( F_5 ( V_3 ) . V_201 == - 1 ) {
F_134 ( V_3 , & F_135 ( V_200 , V_3 ) ) ;
continue;
}
F_132 (j) {
if ( F_5 ( V_3 ) . V_201 ==
F_5 ( V_193 ) . V_201 )
F_134 ( V_193 , & F_135 ( V_200 , V_3 ) ) ;
}
}
}
int F_136 ( unsigned int V_46 , struct V_74 * V_202 )
{
int V_82 = F_41 ( V_46 , V_202 ) ;
if ( ! V_82 ) {
F_134 ( V_46 , & V_16 ) ;
while ( ! F_60 ( V_46 ) )
F_137 () ;
if ( ! F_60 ( V_46 ) ) {
V_82 = - V_89 ;
} else {
if ( V_7 != V_8 )
F_32 ( V_46 ) ;
}
}
return V_82 ;
}
void F_138 ( void )
{
int V_46 = F_24 () ;
unsigned long V_93 ;
F_139 () ;
if ( V_7 == V_8 ) {
struct V_55 * V_56 = & V_65 [ V_46 ] ;
F_140 ( V_203 ,
V_56 -> V_204 , 0 ) ;
F_140 ( V_205 ,
V_56 -> V_206 , 0 ) ;
F_140 ( V_207 ,
V_56 -> V_208 , 0 ) ;
F_140 ( V_209 ,
V_56 -> V_210 , 0 ) ;
}
F_141 ( V_46 , & V_16 ) ;
F_27 ( L_30 ) ;
F_142 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
while ( 1 )
F_143 () ;
}
int F_144 ( void )
{
int V_46 = F_24 () ;
T_7 * V_211 ;
int V_3 ;
F_59 (i, &cpu_core_map[cpu])
F_141 ( V_46 , & V_194 [ V_3 ] ) ;
F_133 ( & V_194 [ V_46 ] ) ;
F_59 (i, &per_cpu(cpu_sibling_map, cpu))
F_141 ( V_46 , & F_135 ( V_200 , V_3 ) ) ;
F_133 ( & F_135 ( V_200 , V_46 ) ) ;
V_211 = & F_5 ( V_46 ) ;
V_211 -> V_195 = 0 ;
V_211 -> V_201 = - 1 ;
F_145 () ;
F_146 () ;
F_20 () ;
F_147 ( 1 ) ;
F_142 () ;
F_18 ( V_46 , false ) ;
F_148 () ;
return 0 ;
}
void F_149 ( unsigned int V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ ) {
F_150 () ;
if ( ! F_16 ( V_46 , & V_16 ) )
break;
F_151 ( 100 ) ;
}
if ( F_16 ( V_46 , & V_16 ) ) {
F_23 ( V_63 L_31 , V_46 ) ;
} else {
#if F_43 ( V_83 )
unsigned long V_59 ;
int V_212 = 100 ;
do {
V_59 = F_152 ( V_46 ) ;
if ( V_59 == V_126 ) {
F_153 ( V_46 , false ) ;
break;
}
} while ( -- V_212 > 0 );
if ( V_212 <= 0 ) {
F_23 ( V_63 L_32 ,
V_59 ) ;
}
#endif
}
}
void T_6 F_154 ( unsigned int V_189 )
{
}
void F_155 ( int V_46 )
{
if ( V_46 == F_24 () ) {
F_156 ( F_157 () ) ;
F_158 ( 1 << V_213 ) ;
} else {
F_58 ( ( T_1 ) & V_214 ,
0 , 0 , F_64 ( V_46 ) ) ;
}
}
void T_5 F_159 ( int V_144 , struct V_145 * V_146 )
{
F_68 ( 1 << V_144 ) ;
F_160 () ;
}
static void F_161 ( void * V_215 )
{
F_162 () ;
}
void F_163 ( void )
{
int V_46 ;
if ( V_7 == V_8 ) {
F_3 (cpu) {
if ( V_46 == F_24 () )
continue;
#ifdef V_83
if ( V_85 ) {
unsigned long V_59 ;
V_59 = F_152 ( V_46 ) ;
if ( V_59 )
F_23 ( V_63 L_33
L_34 , V_59 ) ;
} else
#endif
F_164 ( V_46 ) ;
}
} else
F_165 ( F_161 , NULL , 0 ) ;
}
static void * T_6 F_166 ( unsigned int V_46 , T_8 V_216 ,
T_8 V_217 )
{
const unsigned long V_218 = F_40 ( V_219 ) ;
#ifdef F_167
int V_220 = F_168 ( V_46 ) ;
void * V_221 ;
if ( ! F_169 ( V_220 ) || ! F_170 ( V_220 ) ) {
V_221 = F_171 ( V_216 , V_217 , V_218 ) ;
F_172 ( L_35 ,
V_46 , V_220 ) ;
F_173 ( L_36 ,
V_46 , V_216 , F_40 ( V_221 ) ) ;
} else {
V_221 = F_174 ( F_170 ( V_220 ) ,
V_216 , V_217 , V_218 ) ;
F_173 ( L_37
L_38 , V_46 , V_216 , V_220 , F_40 ( V_221 ) ) ;
}
return V_221 ;
#else
return F_171 ( V_216 , V_217 , V_218 ) ;
#endif
}
static void T_6 F_175 ( void * V_221 , T_8 V_216 )
{
F_176 ( F_40 ( V_221 ) , V_216 ) ;
}
static int T_6 F_177 ( unsigned int V_222 , unsigned int V_223 )
{
if ( F_168 ( V_222 ) == F_168 ( V_223 ) )
return V_224 ;
else
return V_225 ;
}
static void T_6 F_178 ( unsigned long V_226 )
{
T_9 * V_152 = F_179 ( V_226 ) ;
T_10 * V_227 ;
T_11 * V_228 ;
if ( F_180 ( * V_152 ) ) {
T_10 * V_229 ;
V_229 = F_171 ( V_230 , V_230 , V_230 ) ;
F_181 ( & V_12 , V_152 , V_229 ) ;
}
V_227 = F_182 ( V_152 , V_226 ) ;
if ( F_183 ( * V_227 ) ) {
T_11 * V_229 ;
V_229 = F_171 ( V_230 , V_230 , V_230 ) ;
F_184 ( & V_12 , V_227 , V_229 ) ;
}
V_228 = F_185 ( V_227 , V_226 ) ;
if ( ! F_186 ( * V_228 ) ) {
T_12 * V_229 ;
V_229 = F_171 ( V_230 , V_230 , V_230 ) ;
F_187 ( & V_12 , V_228 , V_229 ) ;
}
}
void T_6 F_188 ( void )
{
unsigned long V_33 ;
unsigned int V_46 ;
int V_231 = - V_188 ;
if ( V_232 != V_233 ) {
V_231 = F_189 ( V_234 ,
V_235 , 4 << 20 ,
F_177 ,
F_166 ,
F_175 ) ;
if ( V_231 )
F_190 ( L_39
L_40 ,
V_236 [ V_232 ] , V_231 ) ;
}
if ( V_231 < 0 )
V_231 = F_191 ( V_234 ,
F_166 ,
F_175 ,
F_178 ) ;
if ( V_231 < 0 )
F_25 ( L_41 , V_231 ) ;
V_33 = ( unsigned long ) V_237 - ( unsigned long ) V_238 ;
F_192 (cpu)
F_8 ( V_46 ) = V_33 + V_239 [ V_46 ] ;
V_6 = F_8 ( F_24 () ) ;
F_193 () ;
if ( V_7 == V_8 )
F_194 ( V_240 ) ;
}
