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
F_14 ( & V_12 ) ;
V_13 -> V_14 = & V_12 ;
F_15 ( V_5 ) ;
while ( ! F_16 ( V_5 , & V_15 ) )
F_17 () ;
F_18 ( V_5 , true ) ;
F_19 () ;
F_20 () ;
F_21 ( V_16 ) ;
}
void F_22 ( void )
{
F_23 ( L_4 , F_24 () ) ;
F_25 ( L_5 ) ;
}
static inline long F_26 ( long * V_17 , long * V_18 )
{
unsigned long V_19 = 0 , V_20 = ~ 0UL , V_21 = 0 ;
unsigned long V_22 , V_23 , V_24 , V_25 ;
unsigned long V_3 ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
V_23 = V_27 -> V_28 () ;
V_29 [ V_30 ] = 1 ;
F_27 ( L_6 ) ;
while ( ! ( V_25 = V_29 [ V_31 ] ) )
F_17 () ;
V_29 [ V_31 ] = 0 ;
F_28 () ;
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
void F_29 ( void )
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
F_30 ( V_36 ) ;
{
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ ) {
V_32 = F_26 ( & V_17 , & V_37 ) ;
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
F_31 ( V_36 ) ;
#if V_38
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ )
F_23 ( L_7 ,
V_41 [ V_3 ] . V_17 , V_41 [ V_3 ] . V_18 , V_41 [ V_3 ] . V_39 , V_41 [ V_3 ] . V_40 ) ;
#endif
F_23 ( V_44 L_8
L_9 ,
F_24 () , V_32 , V_17 ) ;
}
static void F_32 ( int V_45 )
{
unsigned long V_36 , V_3 ;
V_29 [ V_30 ] = 0 ;
F_33 ( V_45 ) ;
while ( ! V_29 [ V_30 ] )
F_17 () ;
V_29 [ V_30 ] = 0 ;
F_27 ( L_6 ) ;
F_34 ( & V_46 , V_36 ) ;
{
for ( V_3 = 0 ; V_3 < V_42 * V_26 ; V_3 ++ ) {
while ( ! V_29 [ V_30 ] )
F_17 () ;
V_29 [ V_30 ] = 0 ;
F_28 () ;
V_29 [ V_31 ] = V_27 -> V_28 () ;
F_27 ( L_6 ) ;
}
}
F_35 ( & V_46 , V_36 ) ;
}
static void F_36 ( unsigned int V_45 , unsigned long V_47 ,
void * * V_48 )
{
extern unsigned long V_49 ;
extern unsigned long V_50 ;
struct V_51 * V_52 ;
unsigned long V_53 ;
struct V_54 * V_55 ;
T_1 V_56 , V_57 ;
unsigned long V_58 ;
int V_3 ;
V_52 = F_37 ( sizeof( * V_52 ) +
( sizeof( struct V_59 ) *
V_60 - 1 ) ,
V_61 ) ;
if ( ! V_52 ) {
F_23 ( V_62 L_10
L_11 ) ;
return;
}
* V_48 = V_52 ;
V_52 -> V_45 = V_45 ;
V_52 -> V_63 = V_60 ;
V_55 = & V_64 [ V_45 ] ;
V_52 -> V_65 = ( unsigned long ) & V_55 -> V_66 ;
V_52 -> V_67 = F_38 ( & V_55 -> V_66 ) ;
V_52 -> V_47 = V_47 ;
V_56 = ( unsigned long ) V_68 ;
V_57 = V_50 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_63 ; V_3 ++ ) {
V_52 -> V_69 [ V_3 ] . V_70 = V_56 ;
V_52 -> V_69 [ V_3 ] . V_71 = V_57 ;
V_56 += 0x400000 ;
V_57 += 0x400000 ;
}
V_53 = F_38 ( V_72 ) ;
V_58 = F_39 ( V_45 , V_53 ,
F_38 ( & V_49 ) ,
F_40 ( V_52 ) ) ;
if ( V_58 )
F_23 ( V_62 L_12
L_13 , V_58 ) ;
}
static int F_41 ( unsigned int V_45 , struct V_73 * V_74 )
{
unsigned long V_75 =
( unsigned long ) ( & V_76 ) ;
unsigned long V_77 =
( unsigned long ) ( & V_78 ) ;
void * V_79 = NULL ;
int V_80 , V_81 ;
V_10 = 0 ;
V_78 = F_42 ( V_74 ) ;
if ( V_7 == V_8 ) {
#if F_43 ( V_82 ) && F_43 ( V_83 )
if ( V_84 )
F_36 ( V_45 ,
( unsigned long ) V_78 ,
& V_79 ) ;
else
#endif
F_44 ( V_45 , V_75 , V_77 ) ;
} else {
struct V_85 * V_86 = F_45 ( V_45 ) ;
F_46 ( V_86 -> V_87 , V_75 , V_77 ) ;
}
for ( V_80 = 0 ; V_80 < 50000 ; V_80 ++ ) {
if ( V_10 )
break;
F_47 ( 100 ) ;
}
if ( V_10 ) {
V_81 = 0 ;
} else {
F_23 ( L_14 , V_45 ) ;
V_81 = - V_88 ;
}
V_78 = NULL ;
F_48 ( V_79 ) ;
return V_81 ;
}
static void F_49 ( T_1 V_89 , T_1 V_90 , T_1 V_91 , T_1 V_92 , unsigned long V_45 )
{
T_1 V_93 , V_94 ;
int V_95 , V_96 ;
if ( V_97 ) {
V_45 = ( ( ( V_45 & 0x3c ) << 1 ) |
( ( V_45 & 0x40 ) >> 4 ) |
( V_45 & 0x3 ) ) ;
}
V_94 = ( V_45 << 14 ) | 0x70 ;
V_98:
V_96 = 0x40 ;
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
V_95 = 100000 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (result)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( V_93 == 0 ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
return;
}
V_95 -= 1 ;
if ( V_95 == 0 )
break;
} while ( V_93 & 0x1 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_95 == 0 ) {
F_23 ( L_15 ,
F_24 () , V_93 ) ;
} else {
F_47 ( 2 ) ;
goto V_98;
}
}
static void F_50 ( struct V_54 * V_55 , int V_99 )
{
T_1 * V_100 , V_89 , V_90 , V_91 ;
T_2 * V_101 ;
T_1 V_92 ;
int V_3 ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_101 = F_51 ( V_55 -> V_102 ) ;
V_100 = F_51 ( V_55 -> V_103 ) ;
V_89 = V_100 [ 0 ] ;
V_90 = V_100 [ 1 ] ;
V_91 = V_100 [ 2 ] ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ )
F_49 ( V_89 , V_90 , V_91 , V_92 , V_101 [ V_3 ] ) ;
}
static void F_52 ( struct V_54 * V_55 , int V_99 )
{
int V_104 , V_105 , V_106 ;
T_1 * V_100 , V_92 , V_107 , V_108 ;
T_2 * V_101 ;
V_101 = F_51 ( V_55 -> V_102 ) ;
V_100 = F_51 ( V_55 -> V_103 ) ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_105 = ( ( V_107 >> 32 ) == V_109 ||
( V_107 >> 32 ) == V_110 ) ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_111:
V_106 = 0 ;
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
V_104 = 0 ;
V_108 = 0 ;
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
T_1 V_94 , V_112 ;
V_112 = V_101 [ V_3 ] ;
if ( V_112 == 0xffff )
continue;
V_94 = ( V_112 << 14 ) | 0x70 ;
if ( V_105 ) {
V_108 |= ( 0x1UL << ( V_112 * 2 ) ) ;
} else {
V_94 |= ( V_104 << 24 ) ;
V_108 |= ( 0x1UL <<
( V_104 * 2 ) ) ;
}
__asm__ __volatile__(
"stxa %%g0, [%0] %1\n\t"
"membar #Sync\n\t"
:
: "r" (target), "i" (ASI_INTR_W));
V_104 ++ ;
if ( V_104 == 32 ) {
V_106 = 1 ;
break;
}
}
}
{
T_1 V_113 , V_114 ;
long V_95 ;
V_95 = 100000 * V_104 ;
V_114 = V_108 << 1 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dispatch_stat)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( ! ( V_113 & ( V_108 | V_114 ) ) ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( F_53 ( V_106 ) ) {
int V_3 , V_115 = 0 ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
if ( V_101 [ V_3 ] == 0xffff )
continue;
V_101 [ V_3 ] = 0xffff ;
V_115 ++ ;
if ( V_115 == 32 )
break;
}
goto V_111;
}
return;
}
if ( ! -- V_95 )
break;
} while ( V_113 & V_108 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_113 & V_108 ) {
F_23 ( L_15 ,
F_24 () , V_113 ) ;
} else {
int V_3 , V_116 = 0 ;
F_47 ( 2 * V_104 ) ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
T_1 V_117 , V_112 ;
V_112 = V_101 [ V_3 ] ;
if ( V_112 == 0xffff )
continue;
if ( V_105 )
V_117 = ( 0x2UL << ( 2 * V_112 ) ) ;
else
V_117 = ( 0x2UL <<
V_116 ) ;
if ( ( V_113 & V_117 ) == 0 )
V_101 [ V_3 ] = 0xffff ;
V_116 += 2 ;
if ( V_116 == 64 )
break;
}
goto V_111;
}
}
}
static void F_54 ( struct V_54 * V_55 , int V_99 )
{
int V_118 , V_119 , V_120 , V_3 , V_121 ;
unsigned long V_122 ;
T_2 * V_101 ;
V_119 = F_24 () ;
V_101 = F_51 ( V_55 -> V_102 ) ;
V_121 = 0 ;
V_118 = 0 ;
V_120 = 0 ;
do {
int V_123 , V_124 ;
V_122 = F_55 ( V_99 ,
V_55 -> V_102 ,
V_55 -> V_103 ) ;
if ( F_56 ( V_122 == V_125 ) )
break;
V_124 = 0 ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
if ( F_56 ( V_101 [ V_3 ] == 0xffff ) )
V_124 ++ ;
}
V_123 = 0 ;
if ( V_124 > V_120 )
V_123 = 1 ;
V_120 = V_124 ;
if ( F_53 ( V_122 == V_126 ) ) {
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
long V_127 ;
T_2 V_45 ;
V_45 = V_101 [ V_3 ] ;
if ( V_45 == 0xffff )
continue;
V_127 = F_57 ( V_45 ) ;
if ( V_127 == V_128 ) {
V_121 = ( V_45 + 1 ) ;
V_101 [ V_3 ] = 0xffff ;
}
}
} else if ( F_53 ( V_122 != V_129 ) )
goto V_130;
if ( F_53 ( ! V_123 ) ) {
if ( F_53 ( ++ V_118 > 10000 ) )
goto V_131;
F_47 ( 2 * V_99 ) ;
}
} while ( 1 );
if ( F_53 ( V_121 ) )
goto V_132;
return;
V_132:
F_23 ( V_133 L_16
L_17 ,
V_119 , V_121 - 1 ) ;
return;
V_131:
F_23 ( V_133 L_18
L_19 ,
V_119 , V_118 ) ;
goto V_134;
V_130:
F_23 ( V_133 L_20 ,
V_119 , V_122 ) ;
F_23 ( V_133 L_21
L_22 ,
V_119 , V_99 , V_55 -> V_102 , V_55 -> V_103 ) ;
V_134:
F_23 ( V_133 L_23 , V_119 ) ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ )
F_23 ( L_24 , V_101 [ V_3 ] ) ;
F_23 ( L_25 ) ;
}
static void F_58 ( T_1 V_89 , T_1 V_90 , T_1 V_91 , const T_3 * V_135 )
{
struct V_54 * V_55 ;
int V_119 , V_3 , V_99 ;
unsigned long V_36 ;
T_2 * V_101 ;
T_1 * V_100 ;
F_30 ( V_36 ) ;
V_119 = F_24 () ;
V_55 = & V_64 [ V_119 ] ;
V_100 = F_51 ( V_55 -> V_103 ) ;
V_100 [ 0 ] = V_89 ;
V_100 [ 1 ] = V_90 ;
V_100 [ 2 ] = V_91 ;
F_28 () ;
V_101 = F_51 ( V_55 -> V_102 ) ;
V_99 = 0 ;
F_59 (i, mask) {
if ( V_3 == V_119 || ! F_60 ( V_3 ) )
continue;
V_101 [ V_99 ++ ] = V_3 ;
}
if ( V_99 )
F_61 ( V_55 , V_99 ) ;
F_31 ( V_36 ) ;
}
static void F_62 ( unsigned long * V_136 , T_4 V_137 , T_1 V_90 , T_1 V_91 , const T_3 * V_135 )
{
T_1 V_89 = ( ( ( T_1 ) V_137 ) << 32 | ( ( ( T_1 ) V_136 ) & 0xffffffff ) ) ;
F_58 ( V_89 , V_90 , V_91 , V_135 ) ;
}
static void F_63 ( unsigned long * V_136 , T_4 V_137 , T_1 V_90 , T_1 V_91 )
{
F_62 ( V_136 , V_137 , V_90 , V_91 , V_138 ) ;
}
static void F_33 ( int V_45 )
{
F_58 ( ( T_1 ) & V_139 , 0 , 0 ,
F_64 ( V_45 ) ) ;
}
void F_65 ( const struct V_140 * V_135 )
{
F_58 ( ( T_1 ) & V_141 , 0 , 0 , V_135 ) ;
}
void F_66 ( int V_45 )
{
F_58 ( ( T_1 ) & V_142 , 0 , 0 ,
F_64 ( V_45 ) ) ;
}
void T_5 F_67 ( int V_143 , struct V_144 * V_145 )
{
F_68 ( 1 << V_143 ) ;
F_69 () ;
F_70 () ;
F_71 () ;
}
void T_5 F_72 ( int V_143 , struct V_144 * V_145 )
{
F_68 ( 1 << V_143 ) ;
F_69 () ;
F_73 () ;
F_71 () ;
}
static void F_74 ( void * V_146 )
{
struct V_54 * V_147 = & V_64 [ F_75 () ] ;
struct V_148 * V_149 = V_146 ;
if ( V_147 -> V_150 == F_40 ( V_149 -> V_151 ) )
F_76 ( V_149 ) ;
}
void F_77 ( struct V_148 * V_149 )
{
F_78 ( F_79 ( V_149 ) , F_74 , V_149 , 1 ) ;
}
static inline void F_80 ( struct V_152 * V_152 )
{
#ifdef F_81
F_82 ( F_83 ( V_152 ) ,
( ( V_7 == V_153 ) &&
F_84 ( V_152 ) != NULL ) ) ;
#else
if ( F_84 ( V_152 ) != NULL &&
V_7 == V_153 )
F_85 ( F_40 ( F_83 ( V_152 ) ) ) ;
#endif
}
void F_86 ( struct V_152 * V_152 , int V_45 )
{
int V_119 ;
if ( V_7 == V_8 )
return;
#ifdef F_87
F_88 ( & V_154 ) ;
#endif
V_119 = F_89 () ;
if ( V_45 == V_119 ) {
F_80 ( V_152 ) ;
} else if ( F_60 ( V_45 ) ) {
void * V_155 = F_83 ( V_152 ) ;
T_1 V_89 = 0 ;
if ( V_7 == V_153 ) {
V_89 = ( ( T_1 ) & V_156 ) ;
if ( F_84 ( V_152 ) != NULL )
V_89 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_157 || V_7 == V_158 ) {
#ifdef F_81
V_89 = ( ( T_1 ) & V_159 ) ;
#endif
}
if ( V_89 ) {
F_58 ( V_89 , F_40 ( V_155 ) ,
( T_1 ) V_155 , F_64 ( V_45 ) ) ;
#ifdef F_87
F_88 ( & V_160 ) ;
#endif
}
}
F_90 () ;
}
void F_91 ( struct V_148 * V_149 , struct V_152 * V_152 )
{
void * V_155 ;
T_1 V_89 ;
if ( V_7 == V_8 )
return;
F_19 () ;
#ifdef F_87
F_88 ( & V_154 ) ;
#endif
V_89 = 0 ;
V_155 = F_83 ( V_152 ) ;
if ( V_7 == V_153 ) {
V_89 = ( ( T_1 ) & V_156 ) ;
if ( F_84 ( V_152 ) != NULL )
V_89 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_157 || V_7 == V_158 ) {
#ifdef F_81
V_89 = ( ( T_1 ) & V_159 ) ;
#endif
}
if ( V_89 ) {
F_58 ( V_89 , F_40 ( V_155 ) ,
( T_1 ) V_155 , V_138 ) ;
#ifdef F_87
F_88 ( & V_160 ) ;
#endif
}
F_80 ( V_152 ) ;
F_92 () ;
}
void T_5 F_93 ( int V_143 , struct V_144 * V_145 )
{
struct V_148 * V_149 ;
unsigned long V_36 ;
F_68 ( 1 << V_143 ) ;
V_149 = V_13 -> V_14 ;
if ( F_53 ( ! V_149 || ( V_149 == & V_12 ) ) )
return;
F_94 ( & V_149 -> V_161 . V_162 , V_36 ) ;
if ( F_53 ( ! F_95 ( V_149 -> V_161 ) ) )
F_96 ( V_149 ) ;
F_97 ( & V_149 -> V_161 . V_162 , V_36 ) ;
F_98 ( V_149 ) ;
F_99 ( F_100 ( V_149 -> V_161 ) ,
V_163 ) ;
}
void F_101 ( void )
{
F_63 ( & V_164 , 0 , 0 , 0 ) ;
}
void F_102 ( unsigned long V_36 )
{
F_63 ( & V_165 , 0 , 0 , 0 ) ;
}
void F_103 ( void )
{
F_63 ( & V_166 , 0 , 0 , 0 ) ;
}
void F_104 ( void )
{
if ( V_7 == V_8 &&
V_167 >= V_168 )
F_63 ( & V_169 , 0 , 0 , 0 ) ;
else
F_63 ( & V_170 , 0 , 0 , 0 ) ;
}
void F_105 ( struct V_148 * V_149 )
{
T_4 V_137 = F_100 ( V_149 -> V_161 ) ;
int V_45 = F_89 () ;
if ( F_106 ( & V_149 -> V_171 ) == 1 ) {
F_107 ( F_79 ( V_149 ) , F_64 ( V_45 ) ) ;
goto V_172;
}
F_62 ( & V_173 ,
V_137 , 0 , 0 ,
F_79 ( V_149 ) ) ;
V_172:
F_99 ( V_137 , V_163 ) ;
F_90 () ;
}
static void F_108 ( void * V_146 )
{
struct V_174 * V_41 = V_146 ;
F_109 ( V_41 -> V_137 , V_41 -> V_112 , V_41 -> V_175 ) ;
}
void F_110 ( struct V_148 * V_149 , unsigned long V_112 , unsigned long * V_175 )
{
T_4 V_137 = F_100 ( V_149 -> V_161 ) ;
struct V_174 V_146 ;
int V_45 = F_89 () ;
V_146 . V_137 = V_137 ;
V_146 . V_112 = V_112 ;
V_146 . V_175 = V_175 ;
if ( V_149 == V_13 -> V_149 && F_106 ( & V_149 -> V_171 ) == 1 )
F_107 ( F_79 ( V_149 ) , F_64 ( V_45 ) ) ;
else
F_78 ( F_79 ( V_149 ) , F_108 ,
& V_146 , 1 ) ;
F_109 ( V_137 , V_112 , V_175 ) ;
F_90 () ;
}
void F_111 ( struct V_148 * V_149 , unsigned long V_70 )
{
unsigned long V_161 = F_100 ( V_149 -> V_161 ) ;
int V_45 = F_89 () ;
if ( V_149 == V_13 -> V_149 && F_106 ( & V_149 -> V_171 ) == 1 )
F_107 ( F_79 ( V_149 ) , F_64 ( V_45 ) ) ;
else
F_62 ( & V_176 ,
V_161 , V_70 , 0 ,
F_79 ( V_149 ) ) ;
F_112 ( V_161 , V_70 ) ;
F_90 () ;
}
void F_113 ( unsigned long V_177 , unsigned long V_178 )
{
V_177 &= V_179 ;
V_178 = F_114 ( V_178 ) ;
if ( V_177 != V_178 ) {
F_63 ( & V_180 ,
0 , V_177 , V_178 ) ;
F_115 ( V_177 , V_178 ) ;
}
}
void F_116 ( void )
{
int V_93 = F_117 ( 1 , & V_181 ) ;
if ( V_93 == 1 ) {
int V_182 = F_118 () ;
#ifdef F_119
F_23 ( L_26 ,
F_24 () ) ;
#endif
V_183 = 1 ;
F_88 ( & V_184 ) ;
F_63 ( & V_185 , 0 , 0 , 0 ) ;
while ( F_106 ( & V_184 ) != V_182 )
F_17 () ;
#ifdef F_119
F_23 ( L_27 ) ;
#endif
}
}
void F_120 ( void )
{
if ( F_121 ( & V_181 ) ) {
#ifdef F_119
F_23 ( L_28
L_29 ,
F_24 () ) ;
#endif
V_183 = 0 ;
F_27 ( L_6 ) ;
F_122 ( & V_184 ) ;
}
}
void T_5 F_123 ( int V_143 , struct V_144 * V_145 )
{
F_68 ( 1 << V_143 ) ;
F_19 () ;
__asm__ __volatile__("flushw");
F_124 ( 1 ) ;
F_88 ( & V_184 ) ;
F_27 ( L_6 ) ;
while ( V_183 )
F_17 () ;
F_122 ( & V_184 ) ;
F_124 ( 0 ) ;
F_92 () ;
}
int F_125 ( unsigned int V_186 )
{
return - V_187 ;
}
void T_6 F_126 ( unsigned int V_188 )
{
}
void F_127 ( void )
{
}
void T_6 F_128 ( void )
{
if ( V_7 == V_153 )
F_61 = F_50 ;
else if ( V_7 == V_157 || V_7 == V_158 )
F_61 = F_52 ;
else
F_61 = F_54 ;
}
void T_6 F_129 ( void )
{
int V_189 = F_130 () ;
int V_3 ;
if ( V_189 > V_190 )
V_189 = V_190 ;
for ( V_3 = 0 ; V_3 < V_189 ; V_3 ++ )
F_131 ( V_3 , true ) ;
for (; V_3 < V_191 ; V_3 ++ )
F_131 ( V_3 , false ) ;
}
void F_132 ( void )
{
unsigned int V_3 ;
F_133 (i) {
unsigned int V_192 ;
F_134 ( & V_193 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_194 == 0 ) {
F_135 ( V_3 , & V_193 [ V_3 ] ) ;
continue;
}
F_133 (j) {
if ( F_5 ( V_3 ) . V_194 ==
F_5 ( V_192 ) . V_194 )
F_135 ( V_192 , & V_193 [ V_3 ] ) ;
}
}
F_133 (i) {
unsigned int V_192 ;
F_133 (j) {
if ( F_5 ( V_3 ) . V_195 ==
F_5 ( V_192 ) . V_195 )
F_135 ( V_192 , & V_196 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_197 == F_5 ( V_192 ) . V_197 )
F_135 ( V_192 , & V_198 [ V_3 ] ) ;
}
}
F_133 (i) {
unsigned int V_192 ;
F_134 ( & F_136 ( V_199 , V_3 ) ) ;
if ( F_5 ( V_3 ) . V_200 == - 1 ) {
F_135 ( V_3 , & F_136 ( V_199 , V_3 ) ) ;
continue;
}
F_133 (j) {
if ( F_5 ( V_3 ) . V_200 ==
F_5 ( V_192 ) . V_200 )
F_135 ( V_192 , & F_136 ( V_199 , V_3 ) ) ;
}
}
}
int F_137 ( unsigned int V_45 , struct V_73 * V_201 )
{
int V_81 = F_41 ( V_45 , V_201 ) ;
if ( ! V_81 ) {
F_135 ( V_45 , & V_15 ) ;
while ( ! F_60 ( V_45 ) )
F_138 () ;
if ( ! F_60 ( V_45 ) ) {
V_81 = - V_88 ;
} else {
if ( V_7 != V_8 )
F_32 ( V_45 ) ;
}
}
return V_81 ;
}
void F_139 ( void )
{
int V_45 = F_24 () ;
unsigned long V_92 ;
F_140 () ;
if ( V_7 == V_8 ) {
struct V_54 * V_55 = & V_64 [ V_45 ] ;
F_141 ( V_202 ,
V_55 -> V_203 , 0 ) ;
F_141 ( V_204 ,
V_55 -> V_205 , 0 ) ;
F_141 ( V_206 ,
V_55 -> V_207 , 0 ) ;
F_141 ( V_208 ,
V_55 -> V_209 , 0 ) ;
}
F_142 ( V_45 , & V_15 ) ;
F_27 ( L_30 ) ;
F_143 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
while ( 1 )
F_144 () ;
}
int F_145 ( void )
{
int V_45 = F_24 () ;
T_7 * V_210 ;
int V_3 ;
F_59 (i, &cpu_core_map[cpu])
F_142 ( V_45 , & V_193 [ V_3 ] ) ;
F_134 ( & V_193 [ V_45 ] ) ;
F_59 (i, &per_cpu(cpu_sibling_map, cpu))
F_142 ( V_45 , & F_136 ( V_199 , V_3 ) ) ;
F_134 ( & F_136 ( V_199 , V_45 ) ) ;
V_210 = & F_5 ( V_45 ) ;
V_210 -> V_194 = 0 ;
V_210 -> V_200 = - 1 ;
F_146 () ;
F_147 () ;
F_20 () ;
F_148 ( 1 ) ;
F_143 () ;
F_18 ( V_45 , false ) ;
F_149 () ;
return 0 ;
}
void F_150 ( unsigned int V_45 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ ) {
F_151 () ;
if ( ! F_16 ( V_45 , & V_15 ) )
break;
F_152 ( 100 ) ;
}
if ( F_16 ( V_45 , & V_15 ) ) {
F_23 ( V_62 L_31 , V_45 ) ;
} else {
#if F_43 ( V_82 )
unsigned long V_58 ;
int V_211 = 100 ;
do {
V_58 = F_153 ( V_45 ) ;
if ( V_58 == V_125 ) {
F_154 ( V_45 , false ) ;
break;
}
} while ( -- V_211 > 0 );
if ( V_211 <= 0 ) {
F_23 ( V_62 L_32 ,
V_58 ) ;
}
#endif
}
}
void T_6 F_155 ( unsigned int V_188 )
{
}
void F_156 ( int V_45 )
{
if ( V_45 == F_24 () ) {
F_157 ( F_158 () ) ;
F_159 ( 1 << V_212 ) ;
} else {
F_58 ( ( T_1 ) & V_213 ,
0 , 0 , F_64 ( V_45 ) ) ;
}
}
void T_5 F_160 ( int V_143 , struct V_144 * V_145 )
{
F_68 ( 1 << V_143 ) ;
F_161 () ;
}
static void F_162 ( void * V_214 )
{
F_18 ( F_24 () , false ) ;
F_163 () ;
}
void F_164 ( void )
{
int V_45 ;
if ( V_7 == V_8 ) {
int V_119 = F_24 () ;
#ifdef F_165
F_166 ( V_119 ) ;
#endif
F_3 (cpu) {
if ( V_45 == V_119 )
continue;
F_18 ( V_45 , false ) ;
#ifdef V_82
if ( V_84 ) {
unsigned long V_58 ;
V_58 = F_153 ( V_45 ) ;
if ( V_58 )
F_23 ( V_62 L_33
L_34 , V_58 ) ;
} else
#endif
F_167 ( V_45 ) ;
}
} else
F_168 ( F_162 , NULL , 0 ) ;
}
static void * T_6 F_169 ( unsigned int V_45 , T_8 V_215 ,
T_8 V_216 )
{
const unsigned long V_217 = F_40 ( V_218 ) ;
#ifdef F_170
int V_219 = F_171 ( V_45 ) ;
void * V_220 ;
if ( ! F_172 ( V_219 ) || ! F_173 ( V_219 ) ) {
V_220 = F_174 ( V_215 , V_216 , V_217 ) ;
F_175 ( L_35 ,
V_45 , V_219 ) ;
F_176 ( L_36 ,
V_45 , V_215 , F_40 ( V_220 ) ) ;
} else {
V_220 = F_177 ( F_173 ( V_219 ) ,
V_215 , V_216 , V_217 ) ;
F_176 ( L_37
L_38 , V_45 , V_215 , V_219 , F_40 ( V_220 ) ) ;
}
return V_220 ;
#else
return F_174 ( V_215 , V_216 , V_217 ) ;
#endif
}
static void T_6 F_178 ( void * V_220 , T_8 V_215 )
{
F_179 ( F_40 ( V_220 ) , V_215 ) ;
}
static int T_6 F_180 ( unsigned int V_221 , unsigned int V_222 )
{
if ( F_171 ( V_221 ) == F_171 ( V_222 ) )
return V_223 ;
else
return V_224 ;
}
static void T_6 F_181 ( unsigned long V_225 )
{
T_9 * V_151 = F_182 ( V_225 ) ;
T_10 * V_226 ;
T_11 * V_227 ;
if ( F_183 ( * V_151 ) ) {
T_10 * V_228 ;
V_228 = F_174 ( V_229 , V_229 , V_229 ) ;
F_184 ( & V_12 , V_151 , V_228 ) ;
}
V_226 = F_185 ( V_151 , V_225 ) ;
if ( F_186 ( * V_226 ) ) {
T_11 * V_228 ;
V_228 = F_174 ( V_229 , V_229 , V_229 ) ;
F_187 ( & V_12 , V_226 , V_228 ) ;
}
V_227 = F_188 ( V_226 , V_225 ) ;
if ( ! F_189 ( * V_227 ) ) {
T_12 * V_228 ;
V_228 = F_174 ( V_229 , V_229 , V_229 ) ;
F_190 ( & V_12 , V_227 , V_228 ) ;
}
}
void T_6 F_191 ( void )
{
unsigned long V_32 ;
unsigned int V_45 ;
int V_230 = - V_187 ;
if ( V_231 != V_232 ) {
V_230 = F_192 ( V_233 ,
V_234 , 4 << 20 ,
F_180 ,
F_169 ,
F_178 ) ;
if ( V_230 )
F_193 ( L_39
L_40 ,
V_235 [ V_231 ] , V_230 ) ;
}
if ( V_230 < 0 )
V_230 = F_194 ( V_233 ,
F_169 ,
F_178 ,
F_181 ) ;
if ( V_230 < 0 )
F_25 ( L_41 , V_230 ) ;
V_32 = ( unsigned long ) V_236 - ( unsigned long ) V_237 ;
F_195 (cpu)
F_8 ( V_45 ) = V_32 + V_238 [ V_45 ] ;
V_6 = F_8 ( F_24 () ) ;
F_196 () ;
if ( V_7 == V_8 )
F_197 ( V_239 ) ;
}
