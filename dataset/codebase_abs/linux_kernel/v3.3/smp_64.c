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
F_13 () ;
V_10 = 1 ;
__asm__ __volatile__("membar #Sync\n\t"
"flush %%g6" : : : "memory");
F_14 () -> V_11 = 0 ;
F_15 ( & V_12 . V_13 ) ;
V_14 -> V_15 = & V_12 ;
F_16 ( V_5 ) ;
while ( ! F_17 ( V_5 , & V_16 ) )
F_18 () ;
F_19 () ;
F_20 ( V_5 , true ) ;
F_21 () ;
F_22 () ;
}
void F_23 ( void )
{
F_24 ( L_4 , F_25 () ) ;
F_26 ( L_5 ) ;
}
static inline long F_27 ( long * V_17 , long * V_18 )
{
unsigned long V_19 = 0 , V_20 = ~ 0UL , V_21 = 0 ;
unsigned long V_22 , V_23 , V_24 , V_25 ;
unsigned long V_3 ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
V_23 = V_27 -> V_28 () ;
V_29 [ V_30 ] = 1 ;
F_28 ( L_6 ) ;
while ( ! ( V_25 = V_29 [ V_31 ] ) )
F_18 () ;
V_29 [ V_31 ] = 0 ;
F_29 () ;
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
void F_30 ( void )
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
F_18 () ;
F_31 ( V_36 ) ;
{
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ ) {
V_32 = F_27 ( & V_17 , & V_37 ) ;
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
F_32 ( V_36 ) ;
#if V_38
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ )
F_24 ( L_7 ,
V_41 [ V_3 ] . V_17 , V_41 [ V_3 ] . V_18 , V_41 [ V_3 ] . V_39 , V_41 [ V_3 ] . V_40 ) ;
#endif
F_24 ( V_44 L_8
L_9 ,
F_25 () , V_32 , V_17 ) ;
}
static void F_33 ( int V_45 )
{
unsigned long V_36 , V_3 ;
V_29 [ V_30 ] = 0 ;
F_34 ( V_45 ) ;
while ( ! V_29 [ V_30 ] )
F_18 () ;
V_29 [ V_30 ] = 0 ;
F_28 ( L_6 ) ;
F_35 ( & V_46 , V_36 ) ;
{
for ( V_3 = 0 ; V_3 < V_42 * V_26 ; V_3 ++ ) {
while ( ! V_29 [ V_30 ] )
F_18 () ;
V_29 [ V_30 ] = 0 ;
F_29 () ;
V_29 [ V_31 ] = V_27 -> V_28 () ;
F_28 ( L_6 ) ;
}
}
F_36 ( & V_46 , V_36 ) ;
}
static unsigned long F_37 ( void * V_47 )
{
unsigned long V_48 = ( unsigned long ) V_47 ;
return V_49 + ( V_48 - V_50 ) ;
}
static void T_1 F_38 ( unsigned int V_45 , unsigned long V_51 , void * * V_52 )
{
extern unsigned long V_53 ;
extern unsigned long V_54 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
struct V_58 * V_59 ;
T_2 V_60 , V_61 ;
unsigned long V_62 ;
int V_3 ;
V_56 = F_39 ( sizeof( * V_56 ) +
( sizeof( struct V_63 ) *
V_64 - 1 ) ,
V_65 ) ;
if ( ! V_56 ) {
F_24 ( V_66 L_10
L_11 ) ;
return;
}
* V_52 = V_56 ;
V_56 -> V_45 = V_45 ;
V_56 -> V_67 = V_64 ;
V_59 = & V_68 [ V_45 ] ;
V_56 -> V_69 = ( unsigned long ) & V_59 -> V_70 ;
V_56 -> V_71 = F_37 ( & V_59 -> V_70 ) ;
V_56 -> V_51 = V_51 ;
V_60 = ( unsigned long ) V_50 ;
V_61 = V_54 ;
for ( V_3 = 0 ; V_3 < V_56 -> V_67 ; V_3 ++ ) {
V_56 -> V_72 [ V_3 ] . V_73 = V_60 ;
V_56 -> V_72 [ V_3 ] . V_74 = V_61 ;
V_60 += 0x400000 ;
V_61 += 0x400000 ;
}
V_57 = F_37 ( V_75 ) ;
V_62 = F_40 ( V_45 , V_57 ,
F_37 ( & V_53 ) ,
F_41 ( V_56 ) ) ;
if ( V_62 )
F_24 ( V_66 L_12
L_13 , V_62 ) ;
}
static int T_1 F_42 ( unsigned int V_45 )
{
unsigned long V_76 =
( unsigned long ) ( & V_77 ) ;
unsigned long V_78 =
( unsigned long ) ( & V_79 ) ;
struct V_80 * V_47 ;
void * V_81 = NULL ;
int V_82 , V_83 ;
V_47 = F_43 ( V_45 ) ;
if ( F_44 ( V_47 ) )
return F_45 ( V_47 ) ;
V_10 = 0 ;
V_79 = F_46 ( V_47 ) ;
if ( V_7 == V_8 ) {
#if F_47 ( V_84 ) && F_47 ( V_85 )
if ( V_86 )
F_38 ( V_45 ,
( unsigned long ) V_79 ,
& V_81 ) ;
else
#endif
F_48 ( V_45 , V_76 , V_78 ) ;
} else {
struct V_87 * V_88 = F_49 ( V_45 ) ;
F_50 ( V_88 -> V_89 , V_76 , V_78 ) ;
}
for ( V_82 = 0 ; V_82 < 50000 ; V_82 ++ ) {
if ( V_10 )
break;
F_51 ( 100 ) ;
}
if ( V_10 ) {
V_83 = 0 ;
} else {
F_24 ( L_14 , V_45 ) ;
V_83 = - V_90 ;
}
V_79 = NULL ;
F_52 ( V_81 ) ;
return V_83 ;
}
static void F_53 ( T_2 V_91 , T_2 V_92 , T_2 V_93 , T_2 V_94 , unsigned long V_45 )
{
T_2 V_95 , V_96 ;
int V_97 , V_98 ;
if ( V_99 ) {
V_45 = ( ( ( V_45 & 0x3c ) << 1 ) |
( ( V_45 & 0x40 ) >> 4 ) |
( V_45 & 0x3 ) ) ;
}
V_96 = ( V_45 << 14 ) | 0x70 ;
V_100:
V_98 = 0x40 ;
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
V_97 = 100000 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (result)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( V_95 == 0 ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
return;
}
V_97 -= 1 ;
if ( V_97 == 0 )
break;
} while ( V_95 & 0x1 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_97 == 0 ) {
F_24 ( L_15 ,
F_25 () , V_95 ) ;
} else {
F_51 ( 2 ) ;
goto V_100;
}
}
static void F_54 ( struct V_58 * V_59 , int V_101 )
{
T_2 * V_102 , V_91 , V_92 , V_93 ;
T_3 * V_103 ;
T_2 V_94 ;
int V_3 ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_103 = F_55 ( V_59 -> V_104 ) ;
V_102 = F_55 ( V_59 -> V_105 ) ;
V_91 = V_102 [ 0 ] ;
V_92 = V_102 [ 1 ] ;
V_93 = V_102 [ 2 ] ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ )
F_53 ( V_91 , V_92 , V_93 , V_94 , V_103 [ V_3 ] ) ;
}
static void F_56 ( struct V_58 * V_59 , int V_101 )
{
int V_106 , V_107 , V_108 ;
T_2 * V_102 , V_94 , V_109 , V_110 ;
T_3 * V_103 ;
V_103 = F_55 ( V_59 -> V_104 ) ;
V_102 = F_55 ( V_59 -> V_105 ) ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_107 = ( ( V_109 >> 32 ) == V_111 ||
( V_109 >> 32 ) == V_112 ) ;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
V_113:
V_108 = 0 ;
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
V_106 = 0 ;
V_110 = 0 ;
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
T_2 V_96 , V_114 ;
V_114 = V_103 [ V_3 ] ;
if ( V_114 == 0xffff )
continue;
V_96 = ( V_114 << 14 ) | 0x70 ;
if ( V_107 ) {
V_110 |= ( 0x1UL << ( V_114 * 2 ) ) ;
} else {
V_96 |= ( V_106 << 24 ) ;
V_110 |= ( 0x1UL <<
( V_106 * 2 ) ) ;
}
__asm__ __volatile__(
"stxa %%g0, [%0] %1\n\t"
"membar #Sync\n\t"
:
: "r" (target), "i" (ASI_INTR_W));
V_106 ++ ;
if ( V_106 == 32 ) {
V_108 = 1 ;
break;
}
}
}
{
T_2 V_115 , V_116 ;
long V_97 ;
V_97 = 100000 * V_106 ;
V_116 = V_110 << 1 ;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dispatch_stat)
: "i" (ASI_INTR_DISPATCH_STAT));
if ( ! ( V_115 & ( V_110 | V_116 ) ) ) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( F_57 ( V_108 ) ) {
int V_3 , V_117 = 0 ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
if ( V_103 [ V_3 ] == 0xffff )
continue;
V_103 [ V_3 ] = 0xffff ;
V_117 ++ ;
if ( V_117 == 32 )
break;
}
goto V_113;
}
return;
}
if ( ! -- V_97 )
break;
} while ( V_115 & V_110 );
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if ( V_115 & V_110 ) {
F_24 ( L_15 ,
F_25 () , V_115 ) ;
} else {
int V_3 , V_118 = 0 ;
F_51 ( 2 * V_106 ) ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
T_2 V_119 , V_114 ;
V_114 = V_103 [ V_3 ] ;
if ( V_114 == 0xffff )
continue;
if ( V_107 )
V_119 = ( 0x2UL << ( 2 * V_114 ) ) ;
else
V_119 = ( 0x2UL <<
V_118 ) ;
if ( ( V_115 & V_119 ) == 0 )
V_103 [ V_3 ] = 0xffff ;
V_118 += 2 ;
if ( V_118 == 64 )
break;
}
goto V_113;
}
}
}
static void F_58 ( struct V_58 * V_59 , int V_101 )
{
int V_120 , V_121 , V_122 , V_3 , V_123 ;
unsigned long V_124 ;
T_3 * V_103 ;
V_121 = F_25 () ;
V_103 = F_55 ( V_59 -> V_104 ) ;
V_123 = 0 ;
V_120 = 0 ;
V_122 = 0 ;
do {
int V_125 , V_126 ;
V_124 = F_59 ( V_101 ,
V_59 -> V_104 ,
V_59 -> V_105 ) ;
if ( F_60 ( V_124 == V_127 ) )
break;
V_126 = 0 ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
if ( F_60 ( V_103 [ V_3 ] == 0xffff ) )
V_126 ++ ;
}
V_125 = 0 ;
if ( V_126 > V_122 )
V_125 = 1 ;
V_122 = V_126 ;
if ( F_57 ( V_124 == V_128 ) ) {
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ ) {
long V_129 ;
T_3 V_45 ;
V_45 = V_103 [ V_3 ] ;
if ( V_45 == 0xffff )
continue;
V_129 = F_61 ( V_45 ) ;
if ( V_129 == V_130 ) {
V_123 = ( V_45 + 1 ) ;
V_103 [ V_3 ] = 0xffff ;
}
}
} else if ( F_57 ( V_124 != V_131 ) )
goto V_132;
if ( F_57 ( ! V_125 ) ) {
if ( F_57 ( ++ V_120 > 10000 ) )
goto V_133;
F_51 ( 2 * V_101 ) ;
}
} while ( 1 );
if ( F_57 ( V_123 ) )
goto V_134;
return;
V_134:
F_24 ( V_135 L_16
L_17 ,
V_121 , V_123 - 1 ) ;
return;
V_133:
F_24 ( V_135 L_18
L_19 ,
V_121 , V_120 ) ;
goto V_136;
V_132:
F_24 ( V_135 L_20 ,
V_121 , V_124 ) ;
F_24 ( V_135 L_21
L_22 ,
V_121 , V_101 , V_59 -> V_104 , V_59 -> V_105 ) ;
V_136:
F_24 ( V_135 L_23 , V_121 ) ;
for ( V_3 = 0 ; V_3 < V_101 ; V_3 ++ )
F_24 ( L_24 , V_103 [ V_3 ] ) ;
F_24 ( L_25 ) ;
}
static void F_62 ( T_2 V_91 , T_2 V_92 , T_2 V_93 , const T_4 * V_137 )
{
struct V_58 * V_59 ;
int V_121 , V_3 , V_101 ;
unsigned long V_36 ;
T_3 * V_103 ;
T_2 * V_102 ;
F_31 ( V_36 ) ;
V_121 = F_25 () ;
V_59 = & V_68 [ V_121 ] ;
V_102 = F_55 ( V_59 -> V_105 ) ;
V_102 [ 0 ] = V_91 ;
V_102 [ 1 ] = V_92 ;
V_102 [ 2 ] = V_93 ;
F_29 () ;
V_103 = F_55 ( V_59 -> V_104 ) ;
V_101 = 0 ;
F_63 (i, mask) {
if ( V_3 == V_121 || ! F_64 ( V_3 ) )
continue;
V_103 [ V_101 ++ ] = V_3 ;
}
if ( V_101 )
F_65 ( V_59 , V_101 ) ;
F_32 ( V_36 ) ;
}
static void F_66 ( unsigned long * V_138 , T_5 V_139 , T_2 V_92 , T_2 V_93 , const T_4 * V_137 )
{
T_2 V_91 = ( ( ( T_2 ) V_139 ) << 32 | ( ( ( T_2 ) V_138 ) & 0xffffffff ) ) ;
F_62 ( V_91 , V_92 , V_93 , V_137 ) ;
}
static void F_67 ( unsigned long * V_138 , T_5 V_139 , T_2 V_92 , T_2 V_93 )
{
F_66 ( V_138 , V_139 , V_92 , V_93 , V_140 ) ;
}
static void F_34 ( int V_45 )
{
F_62 ( ( T_2 ) & V_141 , 0 , 0 ,
F_68 ( V_45 ) ) ;
}
void F_69 ( const struct V_142 * V_137 )
{
F_62 ( ( T_2 ) & V_143 , 0 , 0 , V_137 ) ;
}
void F_70 ( int V_45 )
{
F_62 ( ( T_2 ) & V_144 , 0 , 0 ,
F_68 ( V_45 ) ) ;
}
void T_6 F_71 ( int V_145 , struct V_146 * V_147 )
{
F_72 ( 1 << V_145 ) ;
F_73 () ;
}
void T_6 F_74 ( int V_145 , struct V_146 * V_147 )
{
F_72 ( 1 << V_145 ) ;
F_75 () ;
}
static void F_76 ( void * V_148 )
{
struct V_58 * V_149 = & V_68 [ F_77 () ] ;
struct V_150 * V_151 = V_148 ;
if ( V_149 -> V_152 == F_41 ( V_151 -> V_153 ) )
F_78 ( V_151 ) ;
}
void F_79 ( struct V_150 * V_151 )
{
F_80 ( F_81 ( V_151 ) , F_76 , V_151 , 1 ) ;
}
static inline void F_82 ( struct V_154 * V_154 )
{
#ifdef F_83
F_84 ( F_85 ( V_154 ) ,
( ( V_7 == V_155 ) &&
F_86 ( V_154 ) != NULL ) ) ;
#else
if ( F_86 ( V_154 ) != NULL &&
V_7 == V_155 )
F_87 ( F_41 ( F_85 ( V_154 ) ) ) ;
#endif
}
void F_88 ( struct V_154 * V_154 , int V_45 )
{
int V_121 ;
if ( V_7 == V_8 )
return;
#ifdef F_89
F_15 ( & V_156 ) ;
#endif
V_121 = F_90 () ;
if ( V_45 == V_121 ) {
F_82 ( V_154 ) ;
} else if ( F_64 ( V_45 ) ) {
void * V_157 = F_85 ( V_154 ) ;
T_2 V_91 = 0 ;
if ( V_7 == V_155 ) {
V_91 = ( ( T_2 ) & V_158 ) ;
if ( F_86 ( V_154 ) != NULL )
V_91 |= ( ( T_2 ) 1 << 32 ) ;
} else if ( V_7 == V_159 || V_7 == V_160 ) {
#ifdef F_83
V_91 = ( ( T_2 ) & V_161 ) ;
#endif
}
if ( V_91 ) {
F_62 ( V_91 , F_41 ( V_157 ) ,
( T_2 ) V_157 , F_68 ( V_45 ) ) ;
#ifdef F_89
F_15 ( & V_162 ) ;
#endif
}
}
F_91 () ;
}
void F_92 ( struct V_150 * V_151 , struct V_154 * V_154 )
{
void * V_157 ;
T_2 V_91 ;
if ( V_7 == V_8 )
return;
F_22 () ;
#ifdef F_89
F_15 ( & V_156 ) ;
#endif
V_91 = 0 ;
V_157 = F_85 ( V_154 ) ;
if ( V_7 == V_155 ) {
V_91 = ( ( T_2 ) & V_158 ) ;
if ( F_86 ( V_154 ) != NULL )
V_91 |= ( ( T_2 ) 1 << 32 ) ;
} else if ( V_7 == V_159 || V_7 == V_160 ) {
#ifdef F_83
V_91 = ( ( T_2 ) & V_161 ) ;
#endif
}
if ( V_91 ) {
F_62 ( V_91 , F_41 ( V_157 ) ,
( T_2 ) V_157 , V_140 ) ;
#ifdef F_89
F_15 ( & V_162 ) ;
#endif
}
F_82 ( V_154 ) ;
F_93 () ;
}
void T_6 F_94 ( int V_145 , struct V_146 * V_147 )
{
struct V_150 * V_151 ;
unsigned long V_36 ;
F_72 ( 1 << V_145 ) ;
V_151 = V_14 -> V_15 ;
if ( F_57 ( ! V_151 || ( V_151 == & V_12 ) ) )
return;
F_35 ( & V_151 -> V_163 . V_164 , V_36 ) ;
if ( F_57 ( ! F_95 ( V_151 -> V_163 ) ) )
F_96 ( V_151 ) ;
F_36 ( & V_151 -> V_163 . V_164 , V_36 ) ;
F_97 ( V_151 ) ;
F_98 ( F_99 ( V_151 -> V_163 ) ,
V_165 ) ;
}
void F_100 ( void )
{
F_67 ( & V_166 , 0 , 0 , 0 ) ;
}
void F_101 ( unsigned long V_36 )
{
F_67 ( & V_167 , 0 , 0 , 0 ) ;
}
void F_102 ( void )
{
F_67 ( & V_168 , 0 , 0 , 0 ) ;
}
void F_103 ( struct V_150 * V_151 )
{
T_5 V_139 = F_99 ( V_151 -> V_163 ) ;
int V_45 = F_90 () ;
if ( F_104 ( & V_151 -> V_169 ) == 1 ) {
F_105 ( F_81 ( V_151 ) , F_68 ( V_45 ) ) ;
goto V_170;
}
F_66 ( & V_171 ,
V_139 , 0 , 0 ,
F_81 ( V_151 ) ) ;
V_170:
F_98 ( V_139 , V_165 ) ;
F_91 () ;
}
void F_106 ( struct V_150 * V_151 , unsigned long V_114 , unsigned long * V_172 )
{
T_5 V_139 = F_99 ( V_151 -> V_163 ) ;
int V_45 = F_90 () ;
if ( V_151 == V_14 -> V_151 && F_104 ( & V_151 -> V_169 ) == 1 )
F_105 ( F_81 ( V_151 ) , F_68 ( V_45 ) ) ;
else
F_66 ( & V_173 ,
V_139 , V_114 , ( unsigned long ) V_172 ,
F_81 ( V_151 ) ) ;
F_107 ( V_139 , V_114 , V_172 ) ;
F_91 () ;
}
void F_108 ( unsigned long V_174 , unsigned long V_175 )
{
V_174 &= V_176 ;
V_175 = F_109 ( V_175 ) ;
if ( V_174 != V_175 ) {
F_67 ( & V_177 ,
0 , V_174 , V_175 ) ;
F_110 ( V_174 , V_175 ) ;
}
}
void F_111 ( void )
{
int V_95 = F_112 ( 1 , & V_178 ) ;
if ( V_95 == 1 ) {
int V_179 = F_113 () ;
#ifdef F_114
F_24 ( L_26 ,
F_25 () ) ;
#endif
V_180 = 1 ;
F_15 ( & V_181 ) ;
F_67 ( & V_182 , 0 , 0 , 0 ) ;
while ( F_104 ( & V_181 ) != V_179 )
F_18 () ;
#ifdef F_114
F_24 ( L_27 ) ;
#endif
}
}
void F_115 ( void )
{
if ( F_116 ( & V_178 ) ) {
#ifdef F_114
F_24 ( L_28
L_29 ,
F_25 () ) ;
#endif
V_180 = 0 ;
F_28 ( L_6 ) ;
F_117 ( & V_181 ) ;
}
}
void T_6 F_118 ( int V_145 , struct V_146 * V_147 )
{
F_72 ( 1 << V_145 ) ;
F_22 () ;
__asm__ __volatile__("flushw");
F_119 ( 1 ) ;
F_15 ( & V_181 ) ;
F_28 ( L_6 ) ;
while ( V_180 )
F_18 () ;
F_117 ( & V_181 ) ;
F_119 ( 0 ) ;
F_93 () ;
}
int F_120 ( unsigned int V_183 )
{
return - V_184 ;
}
void T_7 F_121 ( unsigned int V_185 )
{
}
void T_8 F_122 ( void )
{
}
void T_7 F_123 ( void )
{
if ( V_7 == V_155 )
F_65 = F_54 ;
else if ( V_7 == V_159 || V_7 == V_160 )
F_65 = F_56 ;
else
F_65 = F_58 ;
}
void T_8 F_124 ( void )
{
unsigned int V_3 ;
F_125 (i) {
unsigned int V_186 ;
F_126 ( & V_187 [ V_3 ] ) ;
if ( F_5 ( V_3 ) . V_188 == 0 ) {
F_127 ( V_3 , & V_187 [ V_3 ] ) ;
continue;
}
F_125 (j) {
if ( F_5 ( V_3 ) . V_188 ==
F_5 ( V_186 ) . V_188 )
F_127 ( V_186 , & V_187 [ V_3 ] ) ;
}
}
F_125 (i) {
unsigned int V_186 ;
F_126 ( & F_128 ( V_189 , V_3 ) ) ;
if ( F_5 ( V_3 ) . V_190 == - 1 ) {
F_127 ( V_3 , & F_128 ( V_189 , V_3 ) ) ;
continue;
}
F_125 (j) {
if ( F_5 ( V_3 ) . V_190 ==
F_5 ( V_186 ) . V_190 )
F_127 ( V_186 , & F_128 ( V_189 , V_3 ) ) ;
}
}
}
int T_1 F_129 ( unsigned int V_45 )
{
int V_83 = F_42 ( V_45 ) ;
if ( ! V_83 ) {
F_127 ( V_45 , & V_16 ) ;
while ( ! F_64 ( V_45 ) )
F_130 () ;
if ( ! F_64 ( V_45 ) ) {
V_83 = - V_90 ;
} else {
if ( V_7 != V_8 )
F_33 ( V_45 ) ;
}
}
return V_83 ;
}
void F_131 ( void )
{
int V_45 = F_25 () ;
unsigned long V_94 ;
F_132 () ;
if ( V_7 == V_8 ) {
struct V_58 * V_59 = & V_68 [ V_45 ] ;
F_133 ( V_191 ,
V_59 -> V_192 , 0 ) ;
F_133 ( V_193 ,
V_59 -> V_194 , 0 ) ;
F_133 ( V_195 ,
V_59 -> V_196 , 0 ) ;
F_133 ( V_197 ,
V_59 -> V_198 , 0 ) ;
}
F_134 ( V_45 , & V_16 ) ;
F_28 ( L_30 ) ;
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
int V_45 = F_25 () ;
T_9 * V_199 ;
int V_3 ;
F_63 (i, &cpu_core_map[cpu])
F_134 ( V_45 , & V_187 [ V_3 ] ) ;
F_126 ( & V_187 [ V_45 ] ) ;
F_63 (i, &per_cpu(cpu_sibling_map, cpu))
F_134 ( V_45 , & F_128 ( V_189 , V_3 ) ) ;
F_126 ( & F_128 ( V_189 , V_45 ) ) ;
V_199 = & F_5 ( V_45 ) ;
V_199 -> V_188 = 0 ;
V_199 -> V_190 = - 1 ;
F_138 () ;
F_139 () ;
F_13 () ;
F_140 ( 1 ) ;
F_135 () ;
F_141 () ;
F_20 ( V_45 , false ) ;
F_142 () ;
F_143 () ;
return 0 ;
}
void F_144 ( unsigned int V_45 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ ) {
F_145 () ;
if ( ! F_17 ( V_45 , & V_16 ) )
break;
F_146 ( 100 ) ;
}
if ( F_17 ( V_45 , & V_16 ) ) {
F_24 ( V_66 L_31 , V_45 ) ;
} else {
#if F_47 ( V_84 )
unsigned long V_62 ;
int V_200 = 100 ;
do {
V_62 = F_147 ( V_45 ) ;
if ( V_62 == V_127 ) {
F_148 ( V_45 , false ) ;
break;
}
} while ( -- V_200 > 0 );
if ( V_200 <= 0 ) {
F_24 ( V_66 L_32 ,
V_62 ) ;
}
#endif
}
}
void T_7 F_149 ( unsigned int V_185 )
{
F_150 () ;
}
void F_151 ( int V_45 )
{
F_62 ( ( T_2 ) & V_201 , 0 , 0 ,
F_68 ( V_45 ) ) ;
}
void T_6 F_152 ( int V_145 , struct V_146 * V_147 )
{
F_72 ( 1 << V_145 ) ;
F_153 () ;
}
void F_154 ( void )
{
}
static void * T_7 F_155 ( unsigned int V_45 , T_10 V_202 ,
T_10 V_203 )
{
const unsigned long V_204 = F_41 ( V_205 ) ;
#ifdef F_156
int V_206 = F_157 ( V_45 ) ;
void * V_207 ;
if ( ! F_158 ( V_206 ) || ! F_159 ( V_206 ) ) {
V_207 = F_160 ( V_202 , V_203 , V_204 ) ;
F_161 ( L_33 ,
V_45 , V_206 ) ;
F_162 ( L_34 ,
V_45 , V_202 , F_41 ( V_207 ) ) ;
} else {
V_207 = F_163 ( F_159 ( V_206 ) ,
V_202 , V_203 , V_204 ) ;
F_162 ( L_35
L_36 , V_45 , V_202 , V_206 , F_41 ( V_207 ) ) ;
}
return V_207 ;
#else
return F_160 ( V_202 , V_203 , V_204 ) ;
#endif
}
static void T_7 F_164 ( void * V_207 , T_10 V_202 )
{
F_165 ( F_41 ( V_207 ) , V_202 ) ;
}
static int T_7 F_166 ( unsigned int V_208 , unsigned int V_209 )
{
if ( F_157 ( V_208 ) == F_157 ( V_209 ) )
return V_210 ;
else
return V_211 ;
}
static void T_7 F_167 ( unsigned long V_212 )
{
T_11 * V_153 = F_168 ( V_212 ) ;
T_12 * V_213 ;
T_13 * V_214 ;
V_213 = F_169 ( V_153 , V_212 ) ;
if ( F_170 ( * V_213 ) ) {
T_13 * V_215 ;
V_215 = F_160 ( V_216 , V_216 , V_216 ) ;
F_171 ( & V_12 , V_213 , V_215 ) ;
}
V_214 = F_172 ( V_213 , V_212 ) ;
if ( ! F_173 ( * V_214 ) ) {
T_14 * V_215 ;
V_215 = F_160 ( V_216 , V_216 , V_216 ) ;
F_174 ( & V_12 , V_214 , V_215 ) ;
}
}
void T_7 F_175 ( void )
{
unsigned long V_32 ;
unsigned int V_45 ;
int V_217 = - V_184 ;
if ( V_218 != V_219 ) {
V_217 = F_176 ( V_220 ,
V_221 , 4 << 20 ,
F_166 ,
F_155 ,
F_164 ) ;
if ( V_217 )
F_177 ( L_37
L_38 ,
V_222 [ V_218 ] , V_217 ) ;
}
if ( V_217 < 0 )
V_217 = F_178 ( V_220 ,
F_155 ,
F_164 ,
F_167 ) ;
if ( V_217 < 0 )
F_26 ( L_39 , V_217 ) ;
V_32 = ( unsigned long ) V_223 - ( unsigned long ) V_224 ;
F_179 (cpu)
F_8 ( V_45 ) = V_32 + V_225 [ V_45 ] ;
V_6 = F_8 ( F_25 () ) ;
F_180 () ;
if ( V_7 == V_8 )
F_181 ( V_226 ) ;
}
