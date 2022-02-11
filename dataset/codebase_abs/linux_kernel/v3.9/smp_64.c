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
void T_1 F_6 ( void )
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
}
void F_21 ( void )
{
F_22 ( L_4 , F_23 () ) ;
F_24 ( L_5 ) ;
}
static inline long F_25 ( long * V_17 , long * V_18 )
{
unsigned long V_19 = 0 , V_20 = ~ 0UL , V_21 = 0 ;
unsigned long V_22 , V_23 , V_24 , V_25 ;
unsigned long V_3 ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
V_23 = V_27 -> V_28 () ;
V_29 [ V_30 ] = 1 ;
F_26 ( L_6 ) ;
while ( ! ( V_25 = V_29 [ V_31 ] ) )
F_17 () ;
V_29 [ V_31 ] = 0 ;
F_27 () ;
V_24 = V_27 -> V_28 () ;
if ( V_24 - V_23 < V_20 - V_19 )
V_19 = V_23 , V_20 = V_24 , V_21 = V_25 ;
}
* V_17 = V_20 - V_19 ;
* V_18 = V_21 - V_19 ;
V_22 = ( V_19 / 2 + V_20 / 2 ) ;
if ( V_19 % 2 + V_20 % 2 == 2 )
V_22 ++ ;
return V_22 - V_21 ;
}
void F_28 ( void )
{
long V_3 , V_32 , V_33 , V_34 = 0 , V_35 = 0 ;
unsigned long V_36 , V_17 , V_37 ;
#if V_38
struct {
long V_17 ;
long V_18 ;
long V_39 ;
long V_40 ;
} V_41 [ V_42 ] ;
#endif
V_29 [ V_30 ] = 1 ;
while ( V_29 [ V_30 ] )
F_17 () ;
F_29 ( V_36 ) ;
{
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ ) {
V_32 = F_25 ( & V_17 , & V_37 ) ;
if ( V_32 == 0 )
V_35 = 1 ;
if ( ! V_35 ) {
if ( V_3 > 0 ) {
V_34 += - V_32 ;
V_33 = - V_32 + V_34 / 4 ;
} else
V_33 = - V_32 ;
V_27 -> V_43 ( V_33 ) ;
}
#if V_38
V_41 [ V_3 ] . V_17 = V_17 ;
V_41 [ V_3 ] . V_18 = V_37 ;
V_41 [ V_3 ] . V_39 = V_32 ;
V_41 [ V_3 ] . V_40 = V_34 / 4 ;
#endif
}
}
F_30 ( V_36 ) ;
#if V_38
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ )
F_22 ( L_7 ,
V_41 [ V_3 ] . V_17 , V_41 [ V_3 ] . V_18 , V_41 [ V_3 ] . V_39 , V_41 [ V_3 ] . V_40 ) ;
#endif
F_22 ( V_44 L_8
L_9 ,
F_23 () , V_32 , V_17 ) ;
}
static void F_31 ( int V_45 )
{
unsigned long V_36 , V_3 ;
V_29 [ V_30 ] = 0 ;
F_32 ( V_45 ) ;
while ( ! V_29 [ V_30 ] )
F_17 () ;
V_29 [ V_30 ] = 0 ;
F_26 ( L_6 ) ;
F_33 ( & V_46 , V_36 ) ;
{
for ( V_3 = 0 ; V_3 < V_42 * V_26 ; V_3 ++ ) {
while ( ! V_29 [ V_30 ] )
F_17 () ;
V_29 [ V_30 ] = 0 ;
F_27 () ;
V_29 [ V_31 ] = V_27 -> V_28 () ;
F_26 ( L_6 ) ;
}
}
F_34 ( & V_46 , V_36 ) ;
}
static unsigned long F_35 ( void * V_47 )
{
unsigned long V_48 = ( unsigned long ) V_47 ;
return V_49 + ( V_48 - V_50 ) ;
}
static void T_1 F_36 ( unsigned int V_45 , unsigned long V_51 , void * * V_52 )
{
extern unsigned long V_53 ;
extern unsigned long V_54 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
struct V_58 * V_59 ;
T_2 V_60 , V_61 ;
unsigned long V_62 ;
int V_3 ;
V_56 = F_37 ( sizeof( * V_56 ) +
( sizeof( struct V_63 ) *
V_64 - 1 ) ,
V_65 ) ;
if ( ! V_56 ) {
F_22 ( V_66 L_10
L_11 ) ;
return;
}
* V_52 = V_56 ;
V_56 -> V_45 = V_45 ;
V_56 -> V_67 = V_64 ;
V_59 = & V_68 [ V_45 ] ;
V_56 -> V_69 = ( unsigned long ) & V_59 -> V_70 ;
V_56 -> V_71 = F_35 ( & V_59 -> V_70 ) ;
V_56 -> V_51 = V_51 ;
V_60 = ( unsigned long ) V_50 ;
V_61 = V_54 ;
for ( V_3 = 0 ; V_3 < V_56 -> V_67 ; V_3 ++ ) {
V_56 -> V_72 [ V_3 ] . V_73 = V_60 ;
V_56 -> V_72 [ V_3 ] . V_74 = V_61 ;
V_60 += 0x400000 ;
V_61 += 0x400000 ;
}
V_57 = F_35 ( V_75 ) ;
V_62 = F_38 ( V_45 , V_57 ,
F_35 ( & V_53 ) ,
F_39 ( V_56 ) ) ;
if ( V_62 )
F_22 ( V_66 L_12
L_13 , V_62 ) ;
}
static int T_1 F_40 ( unsigned int V_45 , struct V_76 * V_77 )
{
unsigned long V_78 =
( unsigned long ) ( & V_79 ) ;
unsigned long V_80 =
( unsigned long ) ( & V_81 ) ;
void * V_82 = NULL ;
int V_83 , V_84 ;
V_10 = 0 ;
V_81 = F_41 ( V_77 ) ;
if ( V_7 == V_8 ) {
#if F_42 ( V_85 ) && F_42 ( V_86 )
if ( V_87 )
F_36 ( V_45 ,
( unsigned long ) V_81 ,
& V_82 ) ;
else
#endif
F_43 ( V_45 , V_78 , V_80 ) ;
} else {
struct V_88 * V_89 = F_44 ( V_45 ) ;
F_45 ( V_89 -> V_90 , V_78 , V_80 ) ;
}
for ( V_83 = 0 ; V_83 < 50000 ; V_83 ++ ) {
if ( V_10 )
break;
F_46 ( 100 ) ;
}
if ( V_10 ) {
V_84 = 0 ;
} else {
F_22 ( L_14 , V_45 ) ;
V_84 = - V_91 ;
}
V_81 = NULL ;
F_47 ( V_82 ) ;
return V_84 ;
}
static void F_48 ( T_2 V_92 , T_2 V_93 , T_2 V_94 , T_2 V_95 , unsigned long V_45 )
{
T_2 V_96 , V_97 ;
int V_98 , V_99 ;
if ( V_100 ) {
V_45 = ( ( ( V_45 & 0x3c ) << 1 ) |
( ( V_45 & 0x40 ) >> 4 ) |
( V_45 & 0x3 ) ) ;
}
V_97 = ( V_45 << 14 ) | 0x70 ;
V_101:
V_99 = 0x40 ;
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
V_98 = 100000 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (result)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( V_96 == 0 ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
return;
}
V_98 -= 1 ;
if ( V_98 == 0 )
break;
} while ( V_96 & 0x1 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_98 == 0 ) {
F_22 ( L_15 ,
F_23 () , V_96 ) ;
} else {
F_46 ( 2 ) ;
goto V_101;
}
}
static void F_49 ( struct V_58 * V_59 , int V_102 )
{
T_2 * V_103 , V_92 , V_93 , V_94 ;
T_3 * V_104 ;
T_2 V_95 ;
int V_3 ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_104 = F_50 ( V_59 -> V_105 ) ;
V_103 = F_50 ( V_59 -> V_106 ) ;
V_92 = V_103 [ 0 ] ;
V_93 = V_103 [ 1 ] ;
V_94 = V_103 [ 2 ] ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ )
F_48 ( V_92 , V_93 , V_94 , V_95 , V_104 [ V_3 ] ) ;
}
static void F_51 ( struct V_58 * V_59 , int V_102 )
{
int V_107 , V_108 , V_109 ;
T_2 * V_103 , V_95 , V_110 , V_111 ;
T_3 * V_104 ;
V_104 = F_50 ( V_59 -> V_105 ) ;
V_103 = F_50 ( V_59 -> V_106 ) ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_108 = ( ( V_110 >> 32 ) == V_112 ||
( V_110 >> 32 ) == V_113 ) ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_114:
V_109 = 0 ;
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
V_107 = 0 ;
V_111 = 0 ;
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ ) {
T_2 V_97 , V_115 ;
V_115 = V_104 [ V_3 ] ;
if ( V_115 == 0xffff )
continue;
V_97 = ( V_115 << 14 ) | 0x70 ;
if ( V_108 ) {
V_111 |= ( 0x1UL << ( V_115 * 2 ) ) ;
} else {
V_97 |= ( V_107 << 24 ) ;
V_111 |= ( 0x1UL <<
( V_107 * 2 ) ) ;
}
__asm__ __volatile__(
"stxa %%g0, [%0] %1\n\t"
"membar #Sync\n\t"
:
: "r" (target), "i" (ASI_INTR_W));
V_107 ++ ;
if ( V_107 == 32 ) {
V_109 = 1 ;
break;
}
}
}
{
T_2 V_116 , V_117 ;
long V_98 ;
V_98 = 100000 * V_107 ;
V_117 = V_111 << 1 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dispatch_stat)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( ! ( V_116 & ( V_111 | V_117 ) ) ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( F_52 ( V_109 ) ) {
int V_3 , V_118 = 0 ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ ) {
if ( V_104 [ V_3 ] == 0xffff )
continue;
V_104 [ V_3 ] = 0xffff ;
V_118 ++ ;
if ( V_118 == 32 )
break;
}
goto V_114;
}
return;
}
if ( ! -- V_98 )
break;
} while ( V_116 & V_111 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_116 & V_111 ) {
F_22 ( L_15 ,
F_23 () , V_116 ) ;
} else {
int V_3 , V_119 = 0 ;
F_46 ( 2 * V_107 ) ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ ) {
T_2 V_120 , V_115 ;
V_115 = V_104 [ V_3 ] ;
if ( V_115 == 0xffff )
continue;
if ( V_108 )
V_120 = ( 0x2UL << ( 2 * V_115 ) ) ;
else
V_120 = ( 0x2UL <<
V_119 ) ;
if ( ( V_116 & V_120 ) == 0 )
V_104 [ V_3 ] = 0xffff ;
V_119 += 2 ;
if ( V_119 == 64 )
break;
}
goto V_114;
}
}
}
static void F_53 ( struct V_58 * V_59 , int V_102 )
{
int V_121 , V_122 , V_123 , V_3 , V_124 ;
unsigned long V_125 ;
T_3 * V_104 ;
V_122 = F_23 () ;
V_104 = F_50 ( V_59 -> V_105 ) ;
V_124 = 0 ;
V_121 = 0 ;
V_123 = 0 ;
do {
int V_126 , V_127 ;
V_125 = F_54 ( V_102 ,
V_59 -> V_105 ,
V_59 -> V_106 ) ;
if ( F_55 ( V_125 == V_128 ) )
break;
V_127 = 0 ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ ) {
if ( F_55 ( V_104 [ V_3 ] == 0xffff ) )
V_127 ++ ;
}
V_126 = 0 ;
if ( V_127 > V_123 )
V_126 = 1 ;
V_123 = V_127 ;
if ( F_52 ( V_125 == V_129 ) ) {
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ ) {
long V_130 ;
T_3 V_45 ;
V_45 = V_104 [ V_3 ] ;
if ( V_45 == 0xffff )
continue;
V_130 = F_56 ( V_45 ) ;
if ( V_130 == V_131 ) {
V_124 = ( V_45 + 1 ) ;
V_104 [ V_3 ] = 0xffff ;
}
}
} else if ( F_52 ( V_125 != V_132 ) )
goto V_133;
if ( F_52 ( ! V_126 ) ) {
if ( F_52 ( ++ V_121 > 10000 ) )
goto V_134;
F_46 ( 2 * V_102 ) ;
}
} while ( 1 );
if ( F_52 ( V_124 ) )
goto V_135;
return;
V_135:
F_22 ( V_136 L_16
L_17 ,
V_122 , V_124 - 1 ) ;
return;
V_134:
F_22 ( V_136 L_18
L_19 ,
V_122 , V_121 ) ;
goto V_137;
V_133:
F_22 ( V_136 L_20 ,
V_122 , V_125 ) ;
F_22 ( V_136 L_21
L_22 ,
V_122 , V_102 , V_59 -> V_105 , V_59 -> V_106 ) ;
V_137:
F_22 ( V_136 L_23 , V_122 ) ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ )
F_22 ( L_24 , V_104 [ V_3 ] ) ;
F_22 ( L_25 ) ;
}
static void F_57 ( T_2 V_92 , T_2 V_93 , T_2 V_94 , const T_4 * V_138 )
{
struct V_58 * V_59 ;
int V_122 , V_3 , V_102 ;
unsigned long V_36 ;
T_3 * V_104 ;
T_2 * V_103 ;
F_29 ( V_36 ) ;
V_122 = F_23 () ;
V_59 = & V_68 [ V_122 ] ;
V_103 = F_50 ( V_59 -> V_106 ) ;
V_103 [ 0 ] = V_92 ;
V_103 [ 1 ] = V_93 ;
V_103 [ 2 ] = V_94 ;
F_27 () ;
V_104 = F_50 ( V_59 -> V_105 ) ;
V_102 = 0 ;
F_58 (i, mask) {
if ( V_3 == V_122 || ! F_59 ( V_3 ) )
continue;
V_104 [ V_102 ++ ] = V_3 ;
}
if ( V_102 )
F_60 ( V_59 , V_102 ) ;
F_30 ( V_36 ) ;
}
static void F_61 ( unsigned long * V_139 , T_5 V_140 , T_2 V_93 , T_2 V_94 , const T_4 * V_138 )
{
T_2 V_92 = ( ( ( T_2 ) V_140 ) << 32 | ( ( ( T_2 ) V_139 ) & 0xffffffff ) ) ;
F_57 ( V_92 , V_93 , V_94 , V_138 ) ;
}
static void F_62 ( unsigned long * V_139 , T_5 V_140 , T_2 V_93 , T_2 V_94 )
{
F_61 ( V_139 , V_140 , V_93 , V_94 , V_141 ) ;
}
static void F_32 ( int V_45 )
{
F_57 ( ( T_2 ) & V_142 , 0 , 0 ,
F_63 ( V_45 ) ) ;
}
void F_64 ( const struct V_143 * V_138 )
{
F_57 ( ( T_2 ) & V_144 , 0 , 0 , V_138 ) ;
}
void F_65 ( int V_45 )
{
F_57 ( ( T_2 ) & V_145 , 0 , 0 ,
F_63 ( V_45 ) ) ;
}
void T_6 F_66 ( int V_146 , struct V_147 * V_148 )
{
F_67 ( 1 << V_146 ) ;
F_68 () ;
}
void T_6 F_69 ( int V_146 , struct V_147 * V_148 )
{
F_67 ( 1 << V_146 ) ;
F_70 () ;
}
static void F_71 ( void * V_149 )
{
struct V_58 * V_150 = & V_68 [ F_72 () ] ;
struct V_151 * V_152 = V_149 ;
if ( V_150 -> V_153 == F_39 ( V_152 -> V_154 ) )
F_73 ( V_152 ) ;
}
void F_74 ( struct V_151 * V_152 )
{
F_75 ( F_76 ( V_152 ) , F_71 , V_152 , 1 ) ;
}
static inline void F_77 ( struct V_155 * V_155 )
{
#ifdef F_78
F_79 ( F_80 ( V_155 ) ,
( ( V_7 == V_156 ) &&
F_81 ( V_155 ) != NULL ) ) ;
#else
if ( F_81 ( V_155 ) != NULL &&
V_7 == V_156 )
F_82 ( F_39 ( F_80 ( V_155 ) ) ) ;
#endif
}
void F_83 ( struct V_155 * V_155 , int V_45 )
{
int V_122 ;
if ( V_7 == V_8 )
return;
#ifdef F_84
F_14 ( & V_157 ) ;
#endif
V_122 = F_85 () ;
if ( V_45 == V_122 ) {
F_77 ( V_155 ) ;
} else if ( F_59 ( V_45 ) ) {
void * V_158 = F_80 ( V_155 ) ;
T_2 V_92 = 0 ;
if ( V_7 == V_156 ) {
V_92 = ( ( T_2 ) & V_159 ) ;
if ( F_81 ( V_155 ) != NULL )
V_92 |= ( ( T_2 ) 1 << 32 ) ;
} else if ( V_7 == V_160 || V_7 == V_161 ) {
#ifdef F_78
V_92 = ( ( T_2 ) & V_162 ) ;
#endif
}
if ( V_92 ) {
F_57 ( V_92 , F_39 ( V_158 ) ,
( T_2 ) V_158 , F_63 ( V_45 ) ) ;
#ifdef F_84
F_14 ( & V_163 ) ;
#endif
}
}
F_86 () ;
}
void F_87 ( struct V_151 * V_152 , struct V_155 * V_155 )
{
void * V_158 ;
T_2 V_92 ;
if ( V_7 == V_8 )
return;
F_20 () ;
#ifdef F_84
F_14 ( & V_157 ) ;
#endif
V_92 = 0 ;
V_158 = F_80 ( V_155 ) ;
if ( V_7 == V_156 ) {
V_92 = ( ( T_2 ) & V_159 ) ;
if ( F_81 ( V_155 ) != NULL )
V_92 |= ( ( T_2 ) 1 << 32 ) ;
} else if ( V_7 == V_160 || V_7 == V_161 ) {
#ifdef F_78
V_92 = ( ( T_2 ) & V_162 ) ;
#endif
}
if ( V_92 ) {
F_57 ( V_92 , F_39 ( V_158 ) ,
( T_2 ) V_158 , V_141 ) ;
#ifdef F_84
F_14 ( & V_163 ) ;
#endif
}
F_77 ( V_155 ) ;
F_88 () ;
}
void T_6 F_89 ( int V_146 , struct V_147 * V_148 )
{
struct V_151 * V_152 ;
unsigned long V_36 ;
F_67 ( 1 << V_146 ) ;
V_152 = V_14 -> V_15 ;
if ( F_52 ( ! V_152 || ( V_152 == & V_12 ) ) )
return;
F_33 ( & V_152 -> V_164 . V_165 , V_36 ) ;
if ( F_52 ( ! F_90 ( V_152 -> V_164 ) ) )
F_91 ( V_152 ) ;
F_34 ( & V_152 -> V_164 . V_165 , V_36 ) ;
F_92 ( V_152 ) ;
F_93 ( F_94 ( V_152 -> V_164 ) ,
V_166 ) ;
}
void F_95 ( void )
{
F_62 ( & V_167 , 0 , 0 , 0 ) ;
}
void F_96 ( unsigned long V_36 )
{
F_62 ( & V_168 , 0 , 0 , 0 ) ;
}
void F_97 ( void )
{
F_62 ( & V_169 , 0 , 0 , 0 ) ;
}
void F_98 ( void )
{
if ( V_7 == V_8 &&
V_170 >= V_171 )
F_62 ( & V_172 , 0 , 0 , 0 ) ;
else
F_62 ( & V_173 , 0 , 0 , 0 ) ;
}
void F_99 ( struct V_151 * V_152 )
{
T_5 V_140 = F_94 ( V_152 -> V_164 ) ;
int V_45 = F_85 () ;
if ( F_100 ( & V_152 -> V_174 ) == 1 ) {
F_101 ( F_76 ( V_152 ) , F_63 ( V_45 ) ) ;
goto V_175;
}
F_61 ( & V_176 ,
V_140 , 0 , 0 ,
F_76 ( V_152 ) ) ;
V_175:
F_93 ( V_140 , V_166 ) ;
F_86 () ;
}
static void F_102 ( void * V_149 )
{
struct V_177 * V_41 = V_149 ;
F_103 ( V_41 -> V_140 , V_41 -> V_115 , V_41 -> V_178 ) ;
}
void F_104 ( struct V_151 * V_152 , unsigned long V_115 , unsigned long * V_178 )
{
T_5 V_140 = F_94 ( V_152 -> V_164 ) ;
struct V_177 V_149 ;
int V_45 = F_85 () ;
V_149 . V_140 = V_140 ;
V_149 . V_115 = V_115 ;
V_149 . V_178 = V_178 ;
if ( V_152 == V_14 -> V_152 && F_100 ( & V_152 -> V_174 ) == 1 )
F_101 ( F_76 ( V_152 ) , F_63 ( V_45 ) ) ;
else
F_75 ( F_76 ( V_152 ) , F_102 ,
& V_149 , 1 ) ;
F_103 ( V_140 , V_115 , V_178 ) ;
F_86 () ;
}
void F_105 ( struct V_151 * V_152 , unsigned long V_73 )
{
unsigned long V_164 = F_94 ( V_152 -> V_164 ) ;
int V_45 = F_85 () ;
if ( V_152 == V_14 -> V_152 && F_100 ( & V_152 -> V_174 ) == 1 )
F_101 ( F_76 ( V_152 ) , F_63 ( V_45 ) ) ;
else
F_61 ( & V_179 ,
V_164 , V_73 , 0 ,
F_76 ( V_152 ) ) ;
F_106 ( V_164 , V_73 ) ;
F_86 () ;
}
void F_107 ( unsigned long V_180 , unsigned long V_181 )
{
V_180 &= V_182 ;
V_181 = F_108 ( V_181 ) ;
if ( V_180 != V_181 ) {
F_62 ( & V_183 ,
0 , V_180 , V_181 ) ;
F_109 ( V_180 , V_181 ) ;
}
}
void F_110 ( void )
{
int V_96 = F_111 ( 1 , & V_184 ) ;
if ( V_96 == 1 ) {
int V_185 = F_112 () ;
#ifdef F_113
F_22 ( L_26 ,
F_23 () ) ;
#endif
V_186 = 1 ;
F_14 ( & V_187 ) ;
F_62 ( & V_188 , 0 , 0 , 0 ) ;
while ( F_100 ( & V_187 ) != V_185 )
F_17 () ;
#ifdef F_113
F_22 ( L_27 ) ;
#endif
}
}
void F_114 ( void )
{
if ( F_115 ( & V_184 ) ) {
#ifdef F_113
F_22 ( L_28
L_29 ,
F_23 () ) ;
#endif
V_186 = 0 ;
F_26 ( L_6 ) ;
F_116 ( & V_187 ) ;
}
}
void T_6 F_117 ( int V_146 , struct V_147 * V_148 )
{
F_67 ( 1 << V_146 ) ;
F_20 () ;
__asm__ __volatile__("flushw");
F_118 ( 1 ) ;
F_14 ( & V_187 ) ;
F_26 ( L_6 ) ;
while ( V_186 )
F_17 () ;
F_116 ( & V_187 ) ;
F_118 ( 0 ) ;
F_88 () ;
}
int F_119 ( unsigned int V_189 )
{
return - V_190 ;
}
void T_7 F_120 ( unsigned int V_191 )
{
}
void F_121 ( void )
{
}
void T_7 F_122 ( void )
{
if ( V_7 == V_156 )
F_60 = F_49 ;
else if ( V_7 == V_160 || V_7 == V_161 )
F_60 = F_51 ;
else
F_60 = F_53 ;
}
void F_123 ( void )
{
unsigned int V_3 ;
F_124 (i) {
unsigned int V_192 ;
F_125 ( & V_193 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_194 == 0 ) {
F_126 ( V_3 , & V_193 [ V_3 ] ) ;
continue;
}
F_124 (j) {
if ( F_5 ( V_3 ) . V_194 ==
F_5 ( V_192 ) . V_194 )
F_126 ( V_192 , & V_193 [ V_3 ] ) ;
}
}
F_124 (i) {
unsigned int V_192 ;
F_125 ( & F_127 ( V_195 , V_3 ) ) ;
if ( F_5 ( V_3 ) . V_196 == - 1 ) {
F_126 ( V_3 , & F_127 ( V_195 , V_3 ) ) ;
continue;
}
F_124 (j) {
if ( F_5 ( V_3 ) . V_196 ==
F_5 ( V_192 ) . V_196 )
F_126 ( V_192 , & F_127 ( V_195 , V_3 ) ) ;
}
}
}
int T_1 F_128 ( unsigned int V_45 , struct V_76 * V_197 )
{
int V_84 = F_40 ( V_45 , V_197 ) ;
if ( ! V_84 ) {
F_126 ( V_45 , & V_16 ) ;
while ( ! F_59 ( V_45 ) )
F_129 () ;
if ( ! F_59 ( V_45 ) ) {
V_84 = - V_91 ;
} else {
if ( V_7 != V_8 )
F_31 ( V_45 ) ;
}
}
return V_84 ;
}
void F_130 ( void )
{
int V_45 = F_23 () ;
unsigned long V_95 ;
F_131 () ;
if ( V_7 == V_8 ) {
struct V_58 * V_59 = & V_68 [ V_45 ] ;
F_132 ( V_198 ,
V_59 -> V_199 , 0 ) ;
F_132 ( V_200 ,
V_59 -> V_201 , 0 ) ;
F_132 ( V_202 ,
V_59 -> V_203 , 0 ) ;
F_132 ( V_204 ,
V_59 -> V_205 , 0 ) ;
}
F_133 ( V_45 , & V_16 ) ;
F_26 ( L_30 ) ;
F_134 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
while ( 1 )
F_135 () ;
}
int F_136 ( void )
{
int V_45 = F_23 () ;
T_8 * V_206 ;
int V_3 ;
F_58 (i, &cpu_core_map[cpu])
F_133 ( V_45 , & V_193 [ V_3 ] ) ;
F_125 ( & V_193 [ V_45 ] ) ;
F_58 (i, &per_cpu(cpu_sibling_map, cpu))
F_133 ( V_45 , & F_127 ( V_195 , V_3 ) ) ;
F_125 ( & F_127 ( V_195 , V_45 ) ) ;
V_206 = & F_5 ( V_45 ) ;
V_206 -> V_194 = 0 ;
V_206 -> V_196 = - 1 ;
F_137 () ;
F_138 () ;
F_19 () ;
F_139 ( 1 ) ;
F_134 () ;
F_18 ( V_45 , false ) ;
F_140 () ;
return 0 ;
}
void F_141 ( unsigned int V_45 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ ) {
F_142 () ;
if ( ! F_16 ( V_45 , & V_16 ) )
break;
F_143 ( 100 ) ;
}
if ( F_16 ( V_45 , & V_16 ) ) {
F_22 ( V_66 L_31 , V_45 ) ;
} else {
#if F_42 ( V_85 )
unsigned long V_62 ;
int V_207 = 100 ;
do {
V_62 = F_144 ( V_45 ) ;
if ( V_62 == V_128 ) {
F_145 ( V_45 , false ) ;
break;
}
} while ( -- V_207 > 0 );
if ( V_207 <= 0 ) {
F_22 ( V_66 L_32 ,
V_62 ) ;
}
#endif
}
}
void T_7 F_146 ( unsigned int V_191 )
{
F_147 () ;
}
void F_148 ( int V_45 )
{
F_57 ( ( T_2 ) & V_208 , 0 , 0 ,
F_63 ( V_45 ) ) ;
}
void T_6 F_149 ( int V_146 , struct V_147 * V_148 )
{
F_67 ( 1 << V_146 ) ;
F_150 () ;
}
void F_151 ( void )
{
}
static void * T_7 F_152 ( unsigned int V_45 , T_9 V_209 ,
T_9 V_210 )
{
const unsigned long V_211 = F_39 ( V_212 ) ;
#ifdef F_153
int V_213 = F_154 ( V_45 ) ;
void * V_214 ;
if ( ! F_155 ( V_213 ) || ! F_156 ( V_213 ) ) {
V_214 = F_157 ( V_209 , V_210 , V_211 ) ;
F_158 ( L_33 ,
V_45 , V_213 ) ;
F_159 ( L_34 ,
V_45 , V_209 , F_39 ( V_214 ) ) ;
} else {
V_214 = F_160 ( F_156 ( V_213 ) ,
V_209 , V_210 , V_211 ) ;
F_159 ( L_35
L_36 , V_45 , V_209 , V_213 , F_39 ( V_214 ) ) ;
}
return V_214 ;
#else
return F_157 ( V_209 , V_210 , V_211 ) ;
#endif
}
static void T_7 F_161 ( void * V_214 , T_9 V_209 )
{
F_162 ( F_39 ( V_214 ) , V_209 ) ;
}
static int T_7 F_163 ( unsigned int V_215 , unsigned int V_216 )
{
if ( F_154 ( V_215 ) == F_154 ( V_216 ) )
return V_217 ;
else
return V_218 ;
}
static void T_7 F_164 ( unsigned long V_219 )
{
T_10 * V_154 = F_165 ( V_219 ) ;
T_11 * V_220 ;
T_12 * V_221 ;
V_220 = F_166 ( V_154 , V_219 ) ;
if ( F_167 ( * V_220 ) ) {
T_12 * V_222 ;
V_222 = F_157 ( V_223 , V_223 , V_223 ) ;
F_168 ( & V_12 , V_220 , V_222 ) ;
}
V_221 = F_169 ( V_220 , V_219 ) ;
if ( ! F_170 ( * V_221 ) ) {
T_13 * V_222 ;
V_222 = F_157 ( V_223 , V_223 , V_223 ) ;
F_171 ( & V_12 , V_221 , V_222 ) ;
}
}
void T_7 F_172 ( void )
{
unsigned long V_32 ;
unsigned int V_45 ;
int V_224 = - V_190 ;
if ( V_225 != V_226 ) {
V_224 = F_173 ( V_227 ,
V_228 , 4 << 20 ,
F_163 ,
F_152 ,
F_161 ) ;
if ( V_224 )
F_174 ( L_37
L_38 ,
V_229 [ V_225 ] , V_224 ) ;
}
if ( V_224 < 0 )
V_224 = F_175 ( V_227 ,
F_152 ,
F_161 ,
F_164 ) ;
if ( V_224 < 0 )
F_24 ( L_39 , V_224 ) ;
V_32 = ( unsigned long ) V_230 - ( unsigned long ) V_231 ;
F_176 (cpu)
F_8 ( V_45 ) = V_32 + V_232 [ V_45 ] ;
V_6 = F_8 ( F_23 () ) ;
F_177 () ;
if ( V_7 == V_8 )
F_178 ( V_233 ) ;
}
