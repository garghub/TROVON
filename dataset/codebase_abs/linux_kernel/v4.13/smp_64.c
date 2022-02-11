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
int V_122 , V_123 , V_124 ;
T_2 V_125 = 0xffff ;
unsigned long V_126 = 0 ;
unsigned long V_127 ;
int V_128 = 0 ;
int V_129 = 0 ;
T_2 * V_101 ;
T_2 V_45 ;
V_118 = F_24 () ;
V_101 = F_51 ( V_55 -> V_102 ) ;
V_122 = V_99 * V_130 ;
if ( V_122 > V_131 )
V_122 = V_131 ;
V_123 = V_124 = 0 ;
V_119 = V_99 ;
V_120 = 0 ;
do {
int V_132 , V_133 , V_134 ;
V_127 = F_55 ( V_99 ,
V_55 -> V_102 ,
V_55 -> V_103 ) ;
if ( F_56 ( V_127 == V_135 ) )
goto V_136;
if ( F_53 ( ( V_127 != V_137 ) &&
( V_127 != V_138 ) &&
( V_127 != V_139 ) ) )
goto V_140;
V_121 = 0 ;
V_132 = 0 ;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
V_45 = V_101 [ V_3 ] ;
if ( F_56 ( V_45 == 0xffff ) ) {
V_132 ++ ;
} else if ( ( V_127 == V_138 ) &&
( F_57 ( V_45 ) == V_141 ) ) {
V_128 = V_45 + 1 ;
} else if ( V_127 == V_139 && ! F_58 ( V_45 ) ) {
V_129 = V_45 + 1 ;
} else {
V_101 [ V_121 ++ ] = V_45 ;
}
}
if ( V_121 == 0 )
break;
V_99 = V_121 ;
if ( V_125 != V_101 [ 0 ] ) {
V_125 = V_101 [ 0 ] ;
V_126 = F_59 ( V_125 ) ;
}
V_133 = ( V_132 > V_120 ) ;
V_120 = V_132 ;
V_134 = ( V_126 < F_59 ( V_125 ) ) ;
V_126 = F_59 ( V_125 ) ;
if ( F_56 ( V_133 || V_134 ) ) {
V_124 += V_123 ;
V_123 = 0 ;
} else if ( F_53 ( V_123 > V_142 ) ) {
goto V_143;
}
if ( ! V_133 )
F_47 ( V_122 ) ;
V_123 ++ ;
} while ( 1 );
V_136:
if ( F_53 ( V_128 > 0 ) ) {
F_60 ( L_16 ,
V_118 , V_128 - 1 ) ;
} else if ( F_53 ( V_129 > 0 ) ) {
F_60 ( L_17 ,
V_118 , V_129 - 1 ) ;
}
return;
V_140:
F_60 ( L_18 ,
V_118 , V_119 , V_55 -> V_102 , V_55 -> V_103 ) ;
F_25 ( L_19 , V_127 ) ;
V_143:
F_60 ( L_20 ,
V_118 , V_125 , ( V_124 + V_123 ) , V_119 ) ;
F_25 ( L_21 ) ;
}
static void F_61 ( T_1 V_89 , T_1 V_90 , T_1 V_91 , const T_3 * V_144 )
{
struct V_54 * V_55 ;
int V_118 , V_3 , V_99 ;
unsigned long V_36 ;
T_2 * V_101 ;
T_1 * V_100 ;
F_30 ( V_36 ) ;
V_118 = F_24 () ;
V_55 = & V_64 [ V_118 ] ;
V_100 = F_51 ( V_55 -> V_103 ) ;
V_100 [ 0 ] = V_89 ;
V_100 [ 1 ] = V_90 ;
V_100 [ 2 ] = V_91 ;
F_28 () ;
V_101 = F_51 ( V_55 -> V_102 ) ;
V_99 = 0 ;
F_62 (i, mask) {
if ( V_3 == V_118 || ! F_58 ( V_3 ) )
continue;
V_101 [ V_99 ++ ] = V_3 ;
}
if ( V_99 )
F_63 ( V_55 , V_99 ) ;
F_31 ( V_36 ) ;
}
static void F_64 ( unsigned long * V_145 , T_4 V_146 , T_1 V_90 , T_1 V_91 , const T_3 * V_144 )
{
T_1 V_89 = ( ( ( T_1 ) V_146 ) << 32 | ( ( ( T_1 ) V_145 ) & 0xffffffff ) ) ;
F_61 ( V_89 , V_90 , V_91 , V_144 ) ;
}
static void F_65 ( unsigned long * V_145 , T_4 V_146 , T_1 V_90 , T_1 V_91 )
{
F_64 ( V_145 , V_146 , V_90 , V_91 , V_147 ) ;
}
static void F_33 ( int V_45 )
{
F_61 ( ( T_1 ) & V_148 , 0 , 0 ,
F_66 ( V_45 ) ) ;
}
void F_67 ( const struct V_149 * V_144 )
{
F_61 ( ( T_1 ) & V_150 , 0 , 0 , V_144 ) ;
}
void F_68 ( int V_45 )
{
F_61 ( ( T_1 ) & V_151 , 0 , 0 ,
F_66 ( V_45 ) ) ;
}
void T_5 F_69 ( int V_152 , struct V_153 * V_154 )
{
F_70 ( 1 << V_152 ) ;
F_71 () ;
F_72 () ;
F_73 () ;
}
void T_5 F_74 ( int V_152 , struct V_153 * V_154 )
{
F_70 ( 1 << V_152 ) ;
F_71 () ;
F_75 () ;
F_73 () ;
}
static void F_76 ( void * V_155 )
{
struct V_54 * V_156 = & V_64 [ F_77 () ] ;
struct V_157 * V_158 = V_155 ;
if ( V_156 -> V_159 == F_40 ( V_158 -> V_160 ) )
F_78 ( V_158 ) ;
}
void F_79 ( struct V_157 * V_158 )
{
F_80 ( F_81 ( V_158 ) , F_76 , V_158 , 1 ) ;
}
static inline void F_82 ( struct V_161 * V_161 )
{
#ifdef F_83
F_84 ( F_85 ( V_161 ) ,
( ( V_7 == V_162 ) &&
F_86 ( V_161 ) != NULL ) ) ;
#else
if ( F_86 ( V_161 ) != NULL &&
V_7 == V_162 )
F_87 ( F_40 ( F_85 ( V_161 ) ) ) ;
#endif
}
void F_88 ( struct V_161 * V_161 , int V_45 )
{
int V_118 ;
if ( V_7 == V_8 )
return;
#ifdef F_89
F_90 ( & V_163 ) ;
#endif
V_118 = F_91 () ;
if ( V_45 == V_118 ) {
F_82 ( V_161 ) ;
} else if ( F_58 ( V_45 ) ) {
void * V_164 = F_85 ( V_161 ) ;
T_1 V_89 = 0 ;
if ( V_7 == V_162 ) {
V_89 = ( ( T_1 ) & V_165 ) ;
if ( F_86 ( V_161 ) != NULL )
V_89 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_166 || V_7 == V_167 ) {
#ifdef F_83
V_89 = ( ( T_1 ) & V_168 ) ;
#endif
}
if ( V_89 ) {
F_61 ( V_89 , F_40 ( V_164 ) ,
( T_1 ) V_164 , F_66 ( V_45 ) ) ;
#ifdef F_89
F_90 ( & V_169 ) ;
#endif
}
}
F_92 () ;
}
void F_93 ( struct V_157 * V_158 , struct V_161 * V_161 )
{
void * V_164 ;
T_1 V_89 ;
if ( V_7 == V_8 )
return;
F_19 () ;
#ifdef F_89
F_90 ( & V_163 ) ;
#endif
V_89 = 0 ;
V_164 = F_85 ( V_161 ) ;
if ( V_7 == V_162 ) {
V_89 = ( ( T_1 ) & V_165 ) ;
if ( F_86 ( V_161 ) != NULL )
V_89 |= ( ( T_1 ) 1 << 32 ) ;
} else if ( V_7 == V_166 || V_7 == V_167 ) {
#ifdef F_83
V_89 = ( ( T_1 ) & V_168 ) ;
#endif
}
if ( V_89 ) {
F_61 ( V_89 , F_40 ( V_164 ) ,
( T_1 ) V_164 , V_147 ) ;
#ifdef F_89
F_90 ( & V_169 ) ;
#endif
}
F_82 ( V_161 ) ;
F_94 () ;
}
void F_95 ( unsigned long V_36 )
{
F_65 ( & V_170 , 0 , 0 , 0 ) ;
}
void F_96 ( void )
{
F_65 ( & V_171 , 0 , 0 , 0 ) ;
}
void F_97 ( void )
{
if ( V_7 == V_8 &&
V_172 >= V_173 )
F_65 ( & V_174 , 0 , 0 , 0 ) ;
else
F_65 ( & V_175 , 0 , 0 , 0 ) ;
}
void F_98 ( struct V_157 * V_158 )
{
T_4 V_146 = F_99 ( V_158 -> V_176 ) ;
int V_45 = F_91 () ;
if ( F_100 ( & V_158 -> V_177 ) == 1 ) {
F_101 ( F_81 ( V_158 ) , F_66 ( V_45 ) ) ;
goto V_178;
}
F_64 ( & V_179 ,
V_146 , 0 , 0 ,
F_81 ( V_158 ) ) ;
V_178:
F_102 ( V_146 , V_180 ) ;
F_92 () ;
}
static void F_103 ( void * V_155 )
{
struct V_181 * V_41 = V_155 ;
F_104 ( V_41 -> V_146 , V_41 -> V_112 , V_41 -> V_182 ) ;
}
void F_105 ( struct V_157 * V_158 , unsigned long V_112 , unsigned long * V_182 )
{
T_4 V_146 = F_99 ( V_158 -> V_176 ) ;
struct V_181 V_155 ;
int V_45 = F_91 () ;
V_155 . V_146 = V_146 ;
V_155 . V_112 = V_112 ;
V_155 . V_182 = V_182 ;
if ( V_158 == V_13 -> V_158 && F_100 ( & V_158 -> V_177 ) == 1 )
F_101 ( F_81 ( V_158 ) , F_66 ( V_45 ) ) ;
else
F_80 ( F_81 ( V_158 ) , F_103 ,
& V_155 , 1 ) ;
F_104 ( V_146 , V_112 , V_182 ) ;
F_92 () ;
}
void F_106 ( struct V_157 * V_158 , unsigned long V_70 )
{
unsigned long V_176 = F_99 ( V_158 -> V_176 ) ;
int V_45 = F_91 () ;
if ( V_158 == V_13 -> V_158 && F_100 ( & V_158 -> V_177 ) == 1 )
F_101 ( F_81 ( V_158 ) , F_66 ( V_45 ) ) ;
else
F_64 ( & V_183 ,
V_176 , V_70 , 0 ,
F_81 ( V_158 ) ) ;
F_107 ( V_176 , V_70 ) ;
F_92 () ;
}
void F_108 ( unsigned long V_184 , unsigned long V_185 )
{
V_184 &= V_186 ;
V_185 = F_109 ( V_185 ) ;
if ( V_184 != V_185 ) {
F_65 ( & V_187 ,
0 , V_184 , V_185 ) ;
F_110 ( V_184 , V_185 ) ;
}
}
void F_111 ( void )
{
int V_93 = F_112 ( 1 , & V_188 ) ;
if ( V_93 == 1 ) {
int V_189 = F_113 () ;
#ifdef F_114
F_23 ( L_22 ,
F_24 () ) ;
#endif
V_190 = 1 ;
F_90 ( & V_191 ) ;
F_65 ( & V_192 , 0 , 0 , 0 ) ;
while ( F_100 ( & V_191 ) != V_189 )
F_17 () ;
#ifdef F_114
F_23 ( L_23 ) ;
#endif
}
}
void F_115 ( void )
{
if ( F_116 ( & V_188 ) ) {
#ifdef F_114
F_23 ( L_24
L_25 ,
F_24 () ) ;
#endif
V_190 = 0 ;
F_27 ( L_6 ) ;
F_117 ( & V_191 ) ;
}
}
void T_5 F_118 ( int V_152 , struct V_153 * V_154 )
{
F_70 ( 1 << V_152 ) ;
F_19 () ;
__asm__ __volatile__("flushw");
F_119 ( 1 ) ;
F_90 ( & V_191 ) ;
F_27 ( L_6 ) ;
while ( V_190 )
F_17 () ;
F_117 ( & V_191 ) ;
F_119 ( 0 ) ;
F_94 () ;
}
int F_120 ( unsigned int V_193 )
{
return - V_194 ;
}
void T_6 F_121 ( unsigned int V_195 )
{
}
void F_122 ( void )
{
}
void T_6 F_123 ( void )
{
if ( V_7 == V_162 )
F_63 = F_50 ;
else if ( V_7 == V_166 || V_7 == V_167 )
F_63 = F_52 ;
else
F_63 = F_54 ;
}
void T_6 F_124 ( void )
{
int V_196 = F_125 () ;
int V_3 ;
if ( V_196 > V_197 )
V_196 = V_197 ;
for ( V_3 = 0 ; V_3 < V_196 ; V_3 ++ )
F_126 ( V_3 , true ) ;
for (; V_3 < V_198 ; V_3 ++ )
F_126 ( V_3 , false ) ;
}
void F_127 ( void )
{
unsigned int V_3 ;
F_128 (i) {
unsigned int V_199 ;
F_129 ( & V_200 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_201 == 0 ) {
F_130 ( V_3 , & V_200 [ V_3 ] ) ;
continue;
}
F_128 (j) {
if ( F_5 ( V_3 ) . V_201 ==
F_5 ( V_199 ) . V_201 )
F_130 ( V_199 , & V_200 [ V_3 ] ) ;
}
}
F_128 (i) {
unsigned int V_199 ;
F_128 (j) {
if ( F_5 ( V_3 ) . V_202 ==
F_5 ( V_199 ) . V_202 )
F_130 ( V_199 , & V_203 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_204 == F_5 ( V_199 ) . V_204 )
F_130 ( V_199 , & V_205 [ V_3 ] ) ;
}
}
F_128 (i) {
unsigned int V_199 ;
F_129 ( & F_131 ( V_206 , V_3 ) ) ;
if ( F_5 ( V_3 ) . V_207 == - 1 ) {
F_130 ( V_3 , & F_131 ( V_206 , V_3 ) ) ;
continue;
}
F_128 (j) {
if ( F_5 ( V_3 ) . V_207 ==
F_5 ( V_199 ) . V_207 )
F_130 ( V_199 , & F_131 ( V_206 , V_3 ) ) ;
}
}
}
int F_132 ( unsigned int V_45 , struct V_73 * V_208 )
{
int V_81 = F_41 ( V_45 , V_208 ) ;
if ( ! V_81 ) {
F_130 ( V_45 , & V_15 ) ;
while ( ! F_58 ( V_45 ) )
F_133 () ;
if ( ! F_58 ( V_45 ) ) {
V_81 = - V_88 ;
} else {
if ( V_7 != V_8 )
F_32 ( V_45 ) ;
}
}
return V_81 ;
}
void F_134 ( void )
{
int V_45 = F_24 () ;
unsigned long V_92 ;
F_135 () ;
if ( V_7 == V_8 ) {
struct V_54 * V_55 = & V_64 [ V_45 ] ;
F_136 ( V_209 ,
V_55 -> V_210 , 0 ) ;
F_136 ( V_211 ,
V_55 -> V_212 , 0 ) ;
F_136 ( V_213 ,
V_55 -> V_214 , 0 ) ;
F_136 ( V_215 ,
V_55 -> V_216 , 0 ) ;
}
F_137 ( V_45 , & V_15 ) ;
F_27 ( L_26 ) ;
F_138 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
while ( 1 )
F_139 () ;
}
int F_140 ( void )
{
int V_45 = F_24 () ;
T_7 * V_217 ;
int V_3 ;
F_62 (i, &cpu_core_map[cpu])
F_137 ( V_45 , & V_200 [ V_3 ] ) ;
F_129 ( & V_200 [ V_45 ] ) ;
F_62 (i, &per_cpu(cpu_sibling_map, cpu))
F_137 ( V_45 , & F_131 ( V_206 , V_3 ) ) ;
F_129 ( & F_131 ( V_206 , V_45 ) ) ;
V_217 = & F_5 ( V_45 ) ;
V_217 -> V_201 = 0 ;
V_217 -> V_207 = - 1 ;
F_141 () ;
F_142 () ;
F_20 () ;
F_143 ( 1 ) ;
F_138 () ;
F_18 ( V_45 , false ) ;
F_144 () ;
return 0 ;
}
void F_145 ( unsigned int V_45 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ ) {
F_146 () ;
if ( ! F_16 ( V_45 , & V_15 ) )
break;
F_147 ( 100 ) ;
}
if ( F_16 ( V_45 , & V_15 ) ) {
F_23 ( V_62 L_27 , V_45 ) ;
} else {
#if F_43 ( V_82 )
unsigned long V_58 ;
int V_218 = 100 ;
do {
V_58 = F_148 ( V_45 ) ;
if ( V_58 == V_135 ) {
F_149 ( V_45 , false ) ;
break;
}
} while ( -- V_218 > 0 );
if ( V_218 <= 0 ) {
F_23 ( V_62 L_28 ,
V_58 ) ;
}
#endif
}
}
void T_6 F_150 ( unsigned int V_195 )
{
}
void F_151 ( int V_45 )
{
if ( V_45 == F_24 () ) {
F_152 ( F_153 () ) ;
F_154 ( 1 << V_219 ) ;
} else {
F_61 ( ( T_1 ) & V_220 ,
0 , 0 , F_66 ( V_45 ) ) ;
}
}
void T_5 F_155 ( int V_152 , struct V_153 * V_154 )
{
F_70 ( 1 << V_152 ) ;
F_156 () ;
}
static void F_157 ( void * V_221 )
{
F_18 ( F_24 () , false ) ;
F_158 () ;
}
void F_159 ( void )
{
int V_45 ;
if ( V_7 == V_8 ) {
int V_118 = F_24 () ;
#ifdef F_160
F_161 ( V_118 ) ;
#endif
F_3 (cpu) {
if ( V_45 == V_118 )
continue;
F_18 ( V_45 , false ) ;
#ifdef V_82
if ( V_84 ) {
unsigned long V_58 ;
V_58 = F_148 ( V_45 ) ;
if ( V_58 )
F_23 ( V_62 L_29
L_30 , V_58 ) ;
} else
#endif
F_162 ( V_45 ) ;
}
} else
F_163 ( F_157 , NULL , 0 ) ;
}
static void * T_6 F_164 ( unsigned int V_45 , T_8 V_222 ,
T_8 V_223 )
{
const unsigned long V_224 = F_40 ( V_225 ) ;
#ifdef F_165
int V_226 = F_166 ( V_45 ) ;
void * V_227 ;
if ( ! F_167 ( V_226 ) || ! F_168 ( V_226 ) ) {
V_227 = F_169 ( V_222 , V_223 , V_224 ) ;
F_170 ( L_31 ,
V_45 , V_226 ) ;
F_171 ( L_32 ,
V_45 , V_222 , F_40 ( V_227 ) ) ;
} else {
V_227 = F_172 ( F_168 ( V_226 ) ,
V_222 , V_223 , V_224 ) ;
F_171 ( L_33
L_34 , V_45 , V_222 , V_226 , F_40 ( V_227 ) ) ;
}
return V_227 ;
#else
return F_169 ( V_222 , V_223 , V_224 ) ;
#endif
}
static void T_6 F_173 ( void * V_227 , T_8 V_222 )
{
F_174 ( F_40 ( V_227 ) , V_222 ) ;
}
static int T_6 F_175 ( unsigned int V_228 , unsigned int V_229 )
{
if ( F_166 ( V_228 ) == F_166 ( V_229 ) )
return V_230 ;
else
return V_231 ;
}
static void T_6 F_176 ( unsigned long V_232 )
{
T_9 * V_160 = F_177 ( V_232 ) ;
T_10 * V_233 ;
T_11 * V_234 ;
if ( F_178 ( * V_160 ) ) {
T_10 * V_235 ;
V_235 = F_169 ( V_236 , V_236 , V_236 ) ;
F_179 ( & V_12 , V_160 , V_235 ) ;
}
V_233 = F_180 ( V_160 , V_232 ) ;
if ( F_181 ( * V_233 ) ) {
T_11 * V_235 ;
V_235 = F_169 ( V_236 , V_236 , V_236 ) ;
F_182 ( & V_12 , V_233 , V_235 ) ;
}
V_234 = F_183 ( V_233 , V_232 ) ;
if ( ! F_184 ( * V_234 ) ) {
T_12 * V_235 ;
V_235 = F_169 ( V_236 , V_236 , V_236 ) ;
F_185 ( & V_12 , V_234 , V_235 ) ;
}
}
void T_6 F_186 ( void )
{
unsigned long V_32 ;
unsigned int V_45 ;
int V_237 = - V_194 ;
if ( V_238 != V_239 ) {
V_237 = F_187 ( V_240 ,
V_241 , 4 << 20 ,
F_175 ,
F_164 ,
F_173 ) ;
if ( V_237 )
F_188 ( L_35
L_36 ,
V_242 [ V_238 ] , V_237 ) ;
}
if ( V_237 < 0 )
V_237 = F_189 ( V_240 ,
F_164 ,
F_173 ,
F_176 ) ;
if ( V_237 < 0 )
F_25 ( L_37 , V_237 ) ;
V_32 = ( unsigned long ) V_243 - ( unsigned long ) V_244 ;
F_190 (cpu)
F_8 ( V_45 ) = V_32 + V_245 [ V_45 ] ;
V_6 = F_8 ( F_24 () ) ;
F_191 () ;
if ( V_7 == V_8 )
F_192 ( V_246 ) ;
}
