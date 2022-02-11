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
static unsigned long F_36 ( void * V_48 )
{
unsigned long V_49 = ( unsigned long ) V_48 ;
return V_50 + ( V_49 - V_51 ) ;
}
static void F_37 ( unsigned int V_46 , unsigned long V_52 ,
void * * V_53 )
{
extern unsigned long V_54 ;
extern unsigned long V_55 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
struct V_59 * V_60 ;
T_1 V_61 , V_62 ;
unsigned long V_63 ;
int V_3 ;
V_57 = F_38 ( sizeof( * V_57 ) +
( sizeof( struct V_64 ) *
V_65 - 1 ) ,
V_66 ) ;
if ( ! V_57 ) {
F_23 ( V_67 L_10
L_11 ) ;
return;
}
* V_53 = V_57 ;
V_57 -> V_46 = V_46 ;
V_57 -> V_68 = V_65 ;
V_60 = & V_69 [ V_46 ] ;
V_57 -> V_70 = ( unsigned long ) & V_60 -> V_71 ;
V_57 -> V_72 = F_36 ( & V_60 -> V_71 ) ;
V_57 -> V_52 = V_52 ;
V_61 = ( unsigned long ) V_51 ;
V_62 = V_55 ;
for ( V_3 = 0 ; V_3 < V_57 -> V_68 ; V_3 ++ ) {
V_57 -> V_73 [ V_3 ] . V_74 = V_61 ;
V_57 -> V_73 [ V_3 ] . V_75 = V_62 ;
V_61 += 0x400000 ;
V_62 += 0x400000 ;
}
V_58 = F_36 ( V_76 ) ;
V_63 = F_39 ( V_46 , V_58 ,
F_36 ( & V_54 ) ,
F_40 ( V_57 ) ) ;
if ( V_63 )
F_23 ( V_67 L_12
L_13 , V_63 ) ;
}
static int F_41 ( unsigned int V_46 , struct V_77 * V_78 )
{
unsigned long V_79 =
( unsigned long ) ( & V_80 ) ;
unsigned long V_81 =
( unsigned long ) ( & V_82 ) ;
void * V_83 = NULL ;
int V_84 , V_85 ;
V_10 = 0 ;
V_82 = F_42 ( V_78 ) ;
if ( V_7 == V_8 ) {
#if F_43 ( V_86 ) && F_43 ( V_87 )
if ( V_88 )
F_37 ( V_46 ,
( unsigned long ) V_82 ,
& V_83 ) ;
else
#endif
F_44 ( V_46 , V_79 , V_81 ) ;
} else {
struct V_89 * V_90 = F_45 ( V_46 ) ;
F_46 ( V_90 -> V_91 , V_79 , V_81 ) ;
}
for ( V_84 = 0 ; V_84 < 50000 ; V_84 ++ ) {
if ( V_10 )
break;
F_47 ( 100 ) ;
}
if ( V_10 ) {
V_85 = 0 ;
} else {
F_23 ( L_14 , V_46 ) ;
V_85 = - V_92 ;
}
V_82 = NULL ;
F_48 ( V_83 ) ;
return V_85 ;
}
static void F_49 ( T_1 V_93 , T_1 V_94 , T_1 V_95 , T_1 V_96 , unsigned long V_46 )
{
T_1 V_97 , V_98 ;
int V_99 , V_100 ;
if ( V_101 ) {
V_46 = ( ( ( V_46 & 0x3c ) << 1 ) |
( ( V_46 & 0x40 ) >> 4 ) |
( V_46 & 0x3 ) ) ;
}
V_98 = ( V_46 << 14 ) | 0x70 ;
V_102:
V_100 = 0x40 ;
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
V_99 = 100000 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (result)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( V_97 == 0 ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
return;
}
V_99 -= 1 ;
if ( V_99 == 0 )
break;
} while ( V_97 & 0x1 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_99 == 0 ) {
F_23 ( L_15 ,
F_24 () , V_97 ) ;
} else {
F_47 ( 2 ) ;
goto V_102;
}
}
static void F_50 ( struct V_59 * V_60 , int V_103 )
{
T_1 * V_104 , V_93 , V_94 , V_95 ;
T_2 * V_105 ;
T_1 V_96 ;
int V_3 ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_105 = F_51 ( V_60 -> V_106 ) ;
V_104 = F_51 ( V_60 -> V_107 ) ;
V_93 = V_104 [ 0 ] ;
V_94 = V_104 [ 1 ] ;
V_95 = V_104 [ 2 ] ;
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ )
F_49 ( V_93 , V_94 , V_95 , V_96 , V_105 [ V_3 ] ) ;
}
static void F_52 ( struct V_59 * V_60 , int V_103 )
{
int V_108 , V_109 , V_110 ;
T_1 * V_104 , V_96 , V_111 , V_112 ;
T_2 * V_105 ;
V_105 = F_51 ( V_60 -> V_106 ) ;
V_104 = F_51 ( V_60 -> V_107 ) ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_109 = ( ( V_111 >> 32 ) == V_113 ||
( V_111 >> 32 ) == V_114 ) ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_115:
V_110 = 0 ;
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
V_108 = 0 ;
V_112 = 0 ;
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ ) {
T_1 V_98 , V_116 ;
V_116 = V_105 [ V_3 ] ;
if ( V_116 == 0xffff )
continue;
V_98 = ( V_116 << 14 ) | 0x70 ;
if ( V_109 ) {
V_112 |= ( 0x1UL << ( V_116 * 2 ) ) ;
} else {
V_98 |= ( V_108 << 24 ) ;
V_112 |= ( 0x1UL <<
( V_108 * 2 ) ) ;
}
__asm__ __volatile__(
"stxa %%g0, [%0] %1\n\t"
"membar #Sync\n\t"
:
: "r" (target), "i" (ASI_INTR_W));
V_108 ++ ;
if ( V_108 == 32 ) {
V_110 = 1 ;
break;
}
}
}
{
T_1 V_117 , V_118 ;
long V_99 ;
V_99 = 100000 * V_108 ;
V_118 = V_112 << 1 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dispatch_stat)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( ! ( V_117 & ( V_112 | V_118 ) ) ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( F_53 ( V_110 ) ) {
int V_3 , V_119 = 0 ;
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ ) {
if ( V_105 [ V_3 ] == 0xffff )
continue;
V_105 [ V_3 ] = 0xffff ;
V_119 ++ ;
if ( V_119 == 32 )
break;
}
goto V_115;
}
return;
}
if ( ! -- V_99 )
break;
} while ( V_117 & V_112 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_117 & V_112 ) {
F_23 ( L_15 ,
F_24 () , V_117 ) ;
} else {
int V_3 , V_120 = 0 ;
F_47 ( 2 * V_108 ) ;
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ ) {
T_1 V_121 , V_116 ;
V_116 = V_105 [ V_3 ] ;
if ( V_116 == 0xffff )
continue;
if ( V_109 )
V_121 = ( 0x2UL << ( 2 * V_116 ) ) ;
else
V_121 = ( 0x2UL <<
V_120 ) ;
if ( ( V_117 & V_121 ) == 0 )
V_105 [ V_3 ] = 0xffff ;
V_120 += 2 ;
if ( V_120 == 64 )
break;
}
goto V_115;
}
}
}
static void F_54 ( struct V_59 * V_60 , int V_103 )
{
int V_122 , V_123 , V_124 , V_3 , V_125 ;
unsigned long V_126 ;
T_2 * V_105 ;
V_123 = F_24 () ;
V_105 = F_51 ( V_60 -> V_106 ) ;
V_125 = 0 ;
V_122 = 0 ;
V_124 = 0 ;
do {
int V_127 , V_128 ;
V_126 = F_55 ( V_103 ,
V_60 -> V_106 ,
V_60 -> V_107 ) ;
if ( F_56 ( V_126 == V_129 ) )
break;
V_128 = 0 ;
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ ) {
if ( F_56 ( V_105 [ V_3 ] == 0xffff ) )
V_128 ++ ;
}
V_127 = 0 ;
if ( V_128 > V_124 )
V_127 = 1 ;
V_124 = V_128 ;
if ( F_53 ( V_126 == V_130 ) ) {
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ ) {
long V_131 ;
T_2 V_46 ;
V_46 = V_105 [ V_3 ] ;
if ( V_46 == 0xffff )
continue;
V_131 = F_57 ( V_46 ) ;
if ( V_131 == V_132 ) {
V_125 = ( V_46 + 1 ) ;
V_105 [ V_3 ] = 0xffff ;
}
}
} else if ( F_53 ( V_126 != V_133 ) )
goto V_134;
if ( F_53 ( ! V_127 ) ) {
if ( F_53 ( ++ V_122 > 10000 ) )
goto V_135;
F_47 ( 2 * V_103 ) ;
}
} while ( 1 );
if ( F_53 ( V_125 ) )
goto V_136;
return;
V_136:
F_23 ( V_137 L_16
L_17 ,
V_123 , V_125 - 1 ) ;
return;
V_135:
F_23 ( V_137 L_18
L_19 ,
V_123 , V_122 ) ;
goto V_138;
V_134:
F_23 ( V_137 L_20 ,
V_123 , V_126 ) ;
F_23 ( V_137 L_21
L_22 ,
V_123 , V_103 , V_60 -> V_106 , V_60 -> V_107 ) ;
V_138:
F_23 ( V_137 L_23 , V_123 ) ;
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ )
F_23 ( L_24 , V_105 [ V_3 ] ) ;
F_23 ( L_25 ) ;
}
static void F_58 ( T_1 V_93 , T_1 V_94 , T_1 V_95 , const T_3 * V_139 )
{
struct V_59 * V_60 ;
int V_123 , V_3 , V_103 ;
unsigned long V_37 ;
T_2 * V_105 ;
T_1 * V_104 ;
F_30 ( V_37 ) ;
V_123 = F_24 () ;
V_60 = & V_69 [ V_123 ] ;
V_104 = F_51 ( V_60 -> V_107 ) ;
V_104 [ 0 ] = V_93 ;
V_104 [ 1 ] = V_94 ;
V_104 [ 2 ] = V_95 ;
F_28 () ;
V_105 = F_51 ( V_60 -> V_106 ) ;
V_103 = 0 ;
F_59 (i, mask) {
if ( V_3 == V_123 || ! F_60 ( V_3 ) )
continue;
V_105 [ V_103 ++ ] = V_3 ;
}
if ( V_103 )
F_61 ( V_60 , V_103 ) ;
F_31 ( V_37 ) ;
}
static void F_62 ( unsigned long * V_140 , T_4 V_141 , T_1 V_94 , T_1 V_95 , const T_3 * V_139 )
{
T_1 V_93 = ( ( ( T_1 ) V_141 ) << 32 | ( ( ( T_1 ) V_140 ) & 0xffffffff ) ) ;
F_58 ( V_93 , V_94 , V_95 , V_139 ) ;
}
static void F_63 ( unsigned long * V_140 , T_4 V_141 , T_1 V_94 , T_1 V_95 )
{
F_62 ( V_140 , V_141 , V_94 , V_95 , V_142 ) ;
}
static void F_33 ( int V_46 )
{
F_58 ( ( T_1 ) & V_143 , 0 , 0 ,
F_64 ( V_46 ) ) ;
}
void F_65 ( const struct V_144 * V_139 )
{
F_58 ( ( T_1 ) & V_145 , 0 , 0 , V_139 ) ;
}
void F_66 ( int V_46 )
{
F_58 ( ( T_1 ) & V_146 , 0 , 0 ,
F_64 ( V_46 ) ) ;
}
void T_5 F_67 ( int V_147 , struct V_148 * V_149 )
{
F_68 ( 1 << V_147 ) ;
F_69 () ;
}
void T_5 F_70 ( int V_147 , struct V_148 * V_149 )
{
F_68 ( 1 << V_147 ) ;
F_71 () ;
}
static void F_72 ( void * V_150 )
{
struct V_59 * V_151 = & V_69 [ F_73 () ] ;
struct V_152 * V_153 = V_150 ;
if ( V_151 -> V_154 == F_40 ( V_153 -> V_155 ) )
F_74 ( V_153 ) ;
}
void F_75 ( struct V_152 * V_153 )
{
F_76 ( F_77 ( V_153 ) , F_72 , V_153 , 1 ) ;
}
static inline void F_78 ( struct V_156 * V_156 )
{
#ifdef F_79
F_80 ( F_81 ( V_156 ) ,
( ( V_7 == V_157 ) &&
F_82 ( V_156 ) != NULL ) ) ;
#else
if ( F_82 ( V_156 ) != NULL &&
V_7 == V_157 )
F_83 ( F_40 ( F_81 ( V_156 ) ) ) ;
#endif
}
void F_84 ( struct V_156 * V_156 , int V_46 )
{
int V_123 ;
if ( V_7 == V_8 )
return;
#ifdef F_85
F_14 ( & V_158 ) ;
#endif
V_123 = F_86 () ;
if ( V_46 == V_123 ) {
F_78 ( V_156 ) ;
} else if ( F_60 ( V_46 ) ) {
void * V_159 = F_81 ( V_156 ) ;
T_1 V_93 = 0 ;
if ( V_7 == V_157 ) {
V_93 = ( ( T_1 ) & V_160 ) ;
if ( F_82 ( V_156 ) != NULL )
V_93 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_161 || V_7 == V_162 ) {
#ifdef F_79
V_93 = ( ( T_1 ) & V_163 ) ;
#endif
}
if ( V_93 ) {
F_58 ( V_93 , F_40 ( V_159 ) ,
( T_1 ) V_159 , F_64 ( V_46 ) ) ;
#ifdef F_85
F_14 ( & V_164 ) ;
#endif
}
}
F_87 () ;
}
void F_88 ( struct V_152 * V_153 , struct V_156 * V_156 )
{
void * V_159 ;
T_1 V_93 ;
if ( V_7 == V_8 )
return;
F_20 () ;
#ifdef F_85
F_14 ( & V_158 ) ;
#endif
V_93 = 0 ;
V_159 = F_81 ( V_156 ) ;
if ( V_7 == V_157 ) {
V_93 = ( ( T_1 ) & V_160 ) ;
if ( F_82 ( V_156 ) != NULL )
V_93 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_161 || V_7 == V_162 ) {
#ifdef F_79
V_93 = ( ( T_1 ) & V_163 ) ;
#endif
}
if ( V_93 ) {
F_58 ( V_93 , F_40 ( V_159 ) ,
( T_1 ) V_159 , V_142 ) ;
#ifdef F_85
F_14 ( & V_164 ) ;
#endif
}
F_78 ( V_156 ) ;
F_89 () ;
}
void T_5 F_90 ( int V_147 , struct V_148 * V_149 )
{
struct V_152 * V_153 ;
unsigned long V_37 ;
F_68 ( 1 << V_147 ) ;
V_153 = V_14 -> V_15 ;
if ( F_53 ( ! V_153 || ( V_153 == & V_12 ) ) )
return;
F_34 ( & V_153 -> V_165 . V_166 , V_37 ) ;
if ( F_53 ( ! F_91 ( V_153 -> V_165 ) ) )
F_92 ( V_153 ) ;
F_35 ( & V_153 -> V_165 . V_166 , V_37 ) ;
F_93 ( V_153 ) ;
F_94 ( F_95 ( V_153 -> V_165 ) ,
V_167 ) ;
}
void F_96 ( void )
{
F_63 ( & V_168 , 0 , 0 , 0 ) ;
}
void F_97 ( unsigned long V_37 )
{
F_63 ( & V_169 , 0 , 0 , 0 ) ;
}
void F_98 ( void )
{
F_63 ( & V_170 , 0 , 0 , 0 ) ;
}
void F_99 ( void )
{
if ( V_7 == V_8 &&
V_171 >= V_172 )
F_63 ( & V_173 , 0 , 0 , 0 ) ;
else
F_63 ( & V_174 , 0 , 0 , 0 ) ;
}
void F_100 ( struct V_152 * V_153 )
{
T_4 V_141 = F_95 ( V_153 -> V_165 ) ;
int V_46 = F_86 () ;
if ( F_101 ( & V_153 -> V_175 ) == 1 ) {
F_102 ( F_77 ( V_153 ) , F_64 ( V_46 ) ) ;
goto V_176;
}
F_62 ( & V_177 ,
V_141 , 0 , 0 ,
F_77 ( V_153 ) ) ;
V_176:
F_94 ( V_141 , V_167 ) ;
F_87 () ;
}
static void F_103 ( void * V_150 )
{
struct V_178 * V_42 = V_150 ;
F_104 ( V_42 -> V_141 , V_42 -> V_116 , V_42 -> V_179 ) ;
}
void F_105 ( struct V_152 * V_153 , unsigned long V_116 , unsigned long * V_179 )
{
T_4 V_141 = F_95 ( V_153 -> V_165 ) ;
struct V_178 V_150 ;
int V_46 = F_86 () ;
V_150 . V_141 = V_141 ;
V_150 . V_116 = V_116 ;
V_150 . V_179 = V_179 ;
if ( V_153 == V_14 -> V_153 && F_101 ( & V_153 -> V_175 ) == 1 )
F_102 ( F_77 ( V_153 ) , F_64 ( V_46 ) ) ;
else
F_76 ( F_77 ( V_153 ) , F_103 ,
& V_150 , 1 ) ;
F_104 ( V_141 , V_116 , V_179 ) ;
F_87 () ;
}
void F_106 ( struct V_152 * V_153 , unsigned long V_74 )
{
unsigned long V_165 = F_95 ( V_153 -> V_165 ) ;
int V_46 = F_86 () ;
if ( V_153 == V_14 -> V_153 && F_101 ( & V_153 -> V_175 ) == 1 )
F_102 ( F_77 ( V_153 ) , F_64 ( V_46 ) ) ;
else
F_62 ( & V_180 ,
V_165 , V_74 , 0 ,
F_77 ( V_153 ) ) ;
F_107 ( V_165 , V_74 ) ;
F_87 () ;
}
void F_108 ( unsigned long V_181 , unsigned long V_182 )
{
V_181 &= V_183 ;
V_182 = F_109 ( V_182 ) ;
if ( V_181 != V_182 ) {
F_63 ( & V_184 ,
0 , V_181 , V_182 ) ;
F_110 ( V_181 , V_182 ) ;
}
}
void F_111 ( void )
{
int V_97 = F_112 ( 1 , & V_185 ) ;
if ( V_97 == 1 ) {
int V_186 = F_113 () ;
#ifdef F_114
F_23 ( L_26 ,
F_24 () ) ;
#endif
V_187 = 1 ;
F_14 ( & V_188 ) ;
F_63 ( & V_189 , 0 , 0 , 0 ) ;
while ( F_101 ( & V_188 ) != V_186 )
F_17 () ;
#ifdef F_114
F_23 ( L_27 ) ;
#endif
}
}
void F_115 ( void )
{
if ( F_116 ( & V_185 ) ) {
#ifdef F_114
F_23 ( L_28
L_29 ,
F_24 () ) ;
#endif
V_187 = 0 ;
F_27 ( L_6 ) ;
F_117 ( & V_188 ) ;
}
}
void T_5 F_118 ( int V_147 , struct V_148 * V_149 )
{
F_68 ( 1 << V_147 ) ;
F_20 () ;
__asm__ __volatile__("flushw");
F_119 ( 1 ) ;
F_14 ( & V_188 ) ;
F_27 ( L_6 ) ;
while ( V_187 )
F_17 () ;
F_117 ( & V_188 ) ;
F_119 ( 0 ) ;
F_89 () ;
}
int F_120 ( unsigned int V_190 )
{
return - V_191 ;
}
void T_6 F_121 ( unsigned int V_192 )
{
}
void F_122 ( void )
{
}
void T_6 F_123 ( void )
{
if ( V_7 == V_157 )
F_61 = F_50 ;
else if ( V_7 == V_161 || V_7 == V_162 )
F_61 = F_52 ;
else
F_61 = F_54 ;
}
void F_124 ( void )
{
unsigned int V_3 ;
F_125 (i) {
unsigned int V_193 ;
F_126 ( & V_194 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_195 == 0 ) {
F_127 ( V_3 , & V_194 [ V_3 ] ) ;
continue;
}
F_125 (j) {
if ( F_5 ( V_3 ) . V_195 ==
F_5 ( V_193 ) . V_195 )
F_127 ( V_193 , & V_194 [ V_3 ] ) ;
}
}
F_125 (i) {
unsigned int V_193 ;
F_126 ( & F_128 ( V_196 , V_3 ) ) ;
if ( F_5 ( V_3 ) . V_197 == - 1 ) {
F_127 ( V_3 , & F_128 ( V_196 , V_3 ) ) ;
continue;
}
F_125 (j) {
if ( F_5 ( V_3 ) . V_197 ==
F_5 ( V_193 ) . V_197 )
F_127 ( V_193 , & F_128 ( V_196 , V_3 ) ) ;
}
}
}
int F_129 ( unsigned int V_46 , struct V_77 * V_198 )
{
int V_85 = F_41 ( V_46 , V_198 ) ;
if ( ! V_85 ) {
F_127 ( V_46 , & V_16 ) ;
while ( ! F_60 ( V_46 ) )
F_130 () ;
if ( ! F_60 ( V_46 ) ) {
V_85 = - V_92 ;
} else {
if ( V_7 != V_8 )
F_32 ( V_46 ) ;
}
}
return V_85 ;
}
void F_131 ( void )
{
int V_46 = F_24 () ;
unsigned long V_96 ;
F_132 () ;
if ( V_7 == V_8 ) {
struct V_59 * V_60 = & V_69 [ V_46 ] ;
F_133 ( V_199 ,
V_60 -> V_200 , 0 ) ;
F_133 ( V_201 ,
V_60 -> V_202 , 0 ) ;
F_133 ( V_203 ,
V_60 -> V_204 , 0 ) ;
F_133 ( V_205 ,
V_60 -> V_206 , 0 ) ;
}
F_134 ( V_46 , & V_16 ) ;
F_27 ( L_30 ) ;
F_135 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
while ( 1 )
F_136 () ;
}
int F_137 ( void )
{
int V_46 = F_24 () ;
T_7 * V_207 ;
int V_3 ;
F_59 (i, &cpu_core_map[cpu])
F_134 ( V_46 , & V_194 [ V_3 ] ) ;
F_126 ( & V_194 [ V_46 ] ) ;
F_59 (i, &per_cpu(cpu_sibling_map, cpu))
F_134 ( V_46 , & F_128 ( V_196 , V_3 ) ) ;
F_126 ( & F_128 ( V_196 , V_46 ) ) ;
V_207 = & F_5 ( V_46 ) ;
V_207 -> V_195 = 0 ;
V_207 -> V_197 = - 1 ;
F_138 () ;
F_139 () ;
F_19 () ;
F_140 ( 1 ) ;
F_135 () ;
F_18 ( V_46 , false ) ;
F_141 () ;
return 0 ;
}
void F_142 ( unsigned int V_46 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ ) {
F_143 () ;
if ( ! F_16 ( V_46 , & V_16 ) )
break;
F_144 ( 100 ) ;
}
if ( F_16 ( V_46 , & V_16 ) ) {
F_23 ( V_67 L_31 , V_46 ) ;
} else {
#if F_43 ( V_86 )
unsigned long V_63 ;
int V_208 = 100 ;
do {
V_63 = F_145 ( V_46 ) ;
if ( V_63 == V_129 ) {
F_146 ( V_46 , false ) ;
break;
}
} while ( -- V_208 > 0 );
if ( V_208 <= 0 ) {
F_23 ( V_67 L_32 ,
V_63 ) ;
}
#endif
}
}
void T_6 F_147 ( unsigned int V_192 )
{
F_148 () ;
}
void F_149 ( int V_46 )
{
F_58 ( ( T_1 ) & V_209 , 0 , 0 ,
F_64 ( V_46 ) ) ;
}
void T_5 F_150 ( int V_147 , struct V_148 * V_149 )
{
F_68 ( 1 << V_147 ) ;
F_151 () ;
}
void F_152 ( void )
{
}
static void * T_6 F_153 ( unsigned int V_46 , T_8 V_210 ,
T_8 V_211 )
{
const unsigned long V_212 = F_40 ( V_213 ) ;
#ifdef F_154
int V_214 = F_155 ( V_46 ) ;
void * V_215 ;
if ( ! F_156 ( V_214 ) || ! F_157 ( V_214 ) ) {
V_215 = F_158 ( V_210 , V_211 , V_212 ) ;
F_159 ( L_33 ,
V_46 , V_214 ) ;
F_160 ( L_34 ,
V_46 , V_210 , F_40 ( V_215 ) ) ;
} else {
V_215 = F_161 ( F_157 ( V_214 ) ,
V_210 , V_211 , V_212 ) ;
F_160 ( L_35
L_36 , V_46 , V_210 , V_214 , F_40 ( V_215 ) ) ;
}
return V_215 ;
#else
return F_158 ( V_210 , V_211 , V_212 ) ;
#endif
}
static void T_6 F_162 ( void * V_215 , T_8 V_210 )
{
F_163 ( F_40 ( V_215 ) , V_210 ) ;
}
static int T_6 F_164 ( unsigned int V_216 , unsigned int V_217 )
{
if ( F_155 ( V_216 ) == F_155 ( V_217 ) )
return V_218 ;
else
return V_219 ;
}
static void T_6 F_165 ( unsigned long V_220 )
{
T_9 * V_155 = F_166 ( V_220 ) ;
T_10 * V_221 ;
T_11 * V_222 ;
V_221 = F_167 ( V_155 , V_220 ) ;
if ( F_168 ( * V_221 ) ) {
T_11 * V_223 ;
V_223 = F_158 ( V_224 , V_224 , V_224 ) ;
F_169 ( & V_12 , V_221 , V_223 ) ;
}
V_222 = F_170 ( V_221 , V_220 ) ;
if ( ! F_171 ( * V_222 ) ) {
T_12 * V_223 ;
V_223 = F_158 ( V_224 , V_224 , V_224 ) ;
F_172 ( & V_12 , V_222 , V_223 ) ;
}
}
void T_6 F_173 ( void )
{
unsigned long V_33 ;
unsigned int V_46 ;
int V_225 = - V_191 ;
if ( V_226 != V_227 ) {
V_225 = F_174 ( V_228 ,
V_229 , 4 << 20 ,
F_164 ,
F_153 ,
F_162 ) ;
if ( V_225 )
F_175 ( L_37
L_38 ,
V_230 [ V_226 ] , V_225 ) ;
}
if ( V_225 < 0 )
V_225 = F_176 ( V_228 ,
F_153 ,
F_162 ,
F_165 ) ;
if ( V_225 < 0 )
F_25 ( L_39 , V_225 ) ;
V_33 = ( unsigned long ) V_231 - ( unsigned long ) V_232 ;
F_177 (cpu)
F_8 ( V_46 ) = V_33 + V_233 [ V_46 ] ;
V_6 = F_8 ( F_24 () ) ;
F_178 () ;
if ( V_7 == V_8 )
F_179 ( V_234 ) ;
}
