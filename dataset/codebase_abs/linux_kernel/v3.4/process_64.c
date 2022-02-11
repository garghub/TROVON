static void F_1 ( int V_1 )
{
if ( V_2 != V_3 ) {
F_2 () ;
return;
}
F_3 ( V_4 ) ;
F_4 () ;
while ( ! F_5 () && ! F_6 ( V_1 ) ) {
unsigned long V_5 ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"andn %0, %1, %0\n\t"
"wrpr %0, %%g0, %%pstate"
: "=&r" (pstate)
: "i" (PSTATE_IE));
if ( ! F_5 () && ! F_6 ( V_1 ) )
F_7 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"or %0, %1, %0\n\t"
"wrpr %0, %%g0, %%pstate"
: "=&r" (pstate)
: "i" (PSTATE_IE));
}
F_8 ( V_4 ) ;
}
void F_9 ( void )
{
int V_1 = F_10 () ;
F_8 ( V_4 ) ;
while( 1 ) {
F_11 () ;
F_12 () ;
while ( ! F_5 () && ! F_6 ( V_1 ) )
F_1 ( V_1 ) ;
F_13 () ;
F_14 () ;
#ifdef F_15
if ( F_6 ( V_1 ) ) {
F_16 () ;
F_17 () ;
}
#endif
F_18 () ;
}
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_8 T_1 * V_9 ;
struct V_8 V_10 ;
T_2 V_11 ;
__asm__ __volatile__ ("flushw");
V_9 = F_20 ( ( unsigned ) V_7 -> V_12 [ 14 ] ) ;
V_11 = F_21 () ;
F_22 ( V_13 ) ;
if ( F_23 ( & V_10 , V_9 , sizeof( V_10 ) ) ) {
F_22 ( V_11 ) ;
return;
}
F_22 ( V_11 ) ;
F_24 ( L_1
L_2 ,
V_10 . V_14 [ 0 ] , V_10 . V_14 [ 1 ] , V_10 . V_14 [ 2 ] , V_10 . V_14 [ 3 ] ,
V_10 . V_14 [ 4 ] , V_10 . V_14 [ 5 ] , V_10 . V_14 [ 6 ] , V_10 . V_14 [ 7 ] ) ;
F_24 ( L_3
L_4 ,
V_10 . V_15 [ 0 ] , V_10 . V_15 [ 1 ] , V_10 . V_15 [ 2 ] , V_10 . V_15 [ 3 ] ,
V_10 . V_15 [ 4 ] , V_10 . V_15 [ 5 ] , V_10 . V_15 [ 6 ] , V_10 . V_15 [ 7 ] ) ;
}
static void F_25 ( struct V_6 * V_7 )
{
struct V_16 T_1 * V_9 ;
struct V_16 * V_17 ;
struct V_16 V_10 ;
T_2 V_11 ;
if ( ( V_7 -> V_18 & V_19 ) || ! ( F_26 ( V_20 ) ) ) {
__asm__ __volatile__ ("flushw");
V_9 = (struct V_16 T_1 * )
( V_7 -> V_12 [ 14 ] + V_21 ) ;
V_17 = (struct V_16 * )
( V_7 -> V_12 [ 14 ] + V_21 ) ;
if ( ! ( V_7 -> V_18 & V_19 ) ) {
V_11 = F_21 () ;
F_22 ( V_13 ) ;
if ( F_23 ( & V_10 , V_9 , sizeof( V_10 ) ) ) {
F_22 ( V_11 ) ;
return;
}
V_17 = & V_10 ;
F_22 ( V_11 ) ;
}
} else {
F_19 ( V_7 ) ;
return;
}
F_24 ( L_5 ,
V_17 -> V_14 [ 0 ] , V_17 -> V_14 [ 1 ] , V_17 -> V_14 [ 2 ] , V_17 -> V_14 [ 3 ] ) ;
F_24 ( L_6 ,
V_17 -> V_14 [ 4 ] , V_17 -> V_14 [ 5 ] , V_17 -> V_14 [ 6 ] , V_17 -> V_14 [ 7 ] ) ;
F_24 ( L_7 ,
V_17 -> V_15 [ 0 ] , V_17 -> V_15 [ 1 ] , V_17 -> V_15 [ 2 ] , V_17 -> V_15 [ 3 ] ) ;
F_24 ( L_8 ,
V_17 -> V_15 [ 4 ] , V_17 -> V_15 [ 5 ] , V_17 -> V_15 [ 6 ] , V_17 -> V_15 [ 7 ] ) ;
if ( V_7 -> V_18 & V_19 )
F_24 ( L_9 , ( void * ) V_17 -> V_15 [ 7 ] ) ;
}
void F_27 ( struct V_6 * V_7 )
{
F_24 ( L_10 , V_7 -> V_18 ,
V_7 -> V_22 , V_7 -> V_23 , V_7 -> V_24 , F_28 () ) ;
F_24 ( L_11 , ( void * ) V_7 -> V_22 ) ;
F_24 ( L_12 ,
V_7 -> V_12 [ 0 ] , V_7 -> V_12 [ 1 ] , V_7 -> V_12 [ 2 ] ,
V_7 -> V_12 [ 3 ] ) ;
F_24 ( L_13 ,
V_7 -> V_12 [ 4 ] , V_7 -> V_12 [ 5 ] , V_7 -> V_12 [ 6 ] ,
V_7 -> V_12 [ 7 ] ) ;
F_24 ( L_14 ,
V_7 -> V_12 [ 8 ] , V_7 -> V_12 [ 9 ] , V_7 -> V_12 [ 10 ] ,
V_7 -> V_12 [ 11 ] ) ;
F_24 ( L_15 ,
V_7 -> V_12 [ 12 ] , V_7 -> V_12 [ 13 ] , V_7 -> V_12 [ 14 ] ,
V_7 -> V_12 [ 15 ] ) ;
F_24 ( L_16 , ( void * ) V_7 -> V_12 [ 15 ] ) ;
F_25 ( V_7 ) ;
F_29 ( V_25 , ( unsigned long * ) V_7 -> V_12 [ V_26 ] ) ;
}
static void F_30 ( struct V_27 * V_28 , struct V_6 * V_7 ,
int V_29 )
{
F_31 () ;
V_30 [ V_29 ] . V_18 = V_7 -> V_18 ;
V_30 [ V_29 ] . V_22 = V_7 -> V_22 ;
V_30 [ V_29 ] . V_23 = V_7 -> V_23 ;
V_30 [ V_29 ] . V_31 = V_7 -> V_12 [ V_32 ] ;
if ( V_7 -> V_18 & V_19 ) {
struct V_16 * V_9 ;
V_9 = (struct V_16 * )
( V_7 -> V_12 [ V_26 ] + V_21 ) ;
if ( F_32 ( V_28 , ( unsigned long ) V_9 ) ) {
V_30 [ V_29 ] . V_33 = V_9 -> V_15 [ 7 ] ;
V_9 = (struct V_16 * )
( V_9 -> V_15 [ 6 ] + V_21 ) ;
if ( F_32 ( V_28 , ( unsigned long ) V_9 ) )
V_30 [ V_29 ] . V_34 = V_9 -> V_15 [ 7 ] ;
}
} else {
V_30 [ V_29 ] . V_33 = 0 ;
V_30 [ V_29 ] . V_34 = 0 ;
}
V_30 [ V_29 ] . V_35 = V_28 ;
}
static void F_33 ( struct V_30 * V_36 )
{
int V_37 = 0 ;
while ( ! V_36 -> V_35 && ++ V_37 < 100 ) {
F_34 () ;
F_35 ( 1 ) ;
}
}
void F_36 ( void )
{
struct V_27 * V_28 = F_37 () ;
struct V_6 * V_7 = F_38 () ;
unsigned long V_38 ;
int V_29 , V_1 ;
if ( ! V_7 )
V_7 = V_28 -> V_39 ;
F_39 ( & V_40 , V_38 ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
V_29 = F_40 () ;
F_30 ( V_28 , V_7 , V_29 ) ;
F_41 () ;
F_42 (cpu) {
struct V_30 * V_36 = & V_30 [ V_1 ] ;
F_33 ( V_36 ) ;
V_28 = V_36 -> V_35 ;
F_24 ( L_17 ,
( V_1 == V_29 ? '*' : ' ' ) , V_1 ,
V_36 -> V_18 , V_36 -> V_22 , V_36 -> V_23 ,
( ( V_28 && V_28 -> V_41 ) ? V_28 -> V_41 -> V_42 : L_18 ) ,
( ( V_28 && V_28 -> V_41 ) ? V_28 -> V_41 -> V_43 : - 1 ) ) ;
if ( V_36 -> V_18 & V_19 ) {
F_24 ( L_19 ,
( void * ) V_36 -> V_22 ,
( void * ) V_36 -> V_31 ,
( void * ) V_36 -> V_33 ,
( void * ) V_36 -> V_34 ) ;
} else {
F_24 ( L_20 ,
V_36 -> V_22 , V_36 -> V_31 , V_36 -> V_33 , V_36 -> V_34 ) ;
}
}
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
F_43 ( & V_40 , V_38 ) ;
}
static void F_44 ( int V_44 )
{
F_36 () ;
}
static int T_3 F_45 ( void )
{
return F_46 ( 'y' , & V_45 ) ;
}
unsigned long F_47 ( struct V_46 * V_47 )
{
struct V_27 * V_48 = F_48 ( V_47 ) ;
unsigned long V_49 = 0xdeadbeefUL ;
if ( V_48 && V_48 -> V_50 ) {
unsigned long * V_51 ;
V_51 = ( unsigned long * ) ( V_48 -> V_50 + V_21 ) ;
if ( ( ( unsigned long ) V_51 & ( sizeof( long ) - 1 ) ) == 0UL &&
V_51 [ 14 ] ) {
unsigned long * V_52 ;
V_52 = ( unsigned long * ) ( V_51 [ 14 ] + V_21 ) ;
if ( ( ( unsigned long ) V_52 & ( sizeof( long ) - 1 ) ) == 0UL )
V_49 = V_52 [ 15 ] ;
}
}
return V_49 ;
}
void F_49 ( void )
{
struct V_27 * V_53 = F_37 () ;
if ( V_53 -> V_54 ) {
if ( V_53 -> V_54 [ 0 ] < 2 )
F_50 ( V_53 -> V_54 ) ;
else
V_53 -> V_54 [ 0 ] -- ;
}
}
void F_51 ( void )
{
struct V_27 * V_53 = F_37 () ;
struct V_55 * V_56 ;
V_56 = V_53 -> V_41 -> V_56 ;
if ( V_56 )
F_52 ( V_56 ) ;
F_53 ( 0 ) ;
V_53 -> V_57 [ 0 ] = 0 ;
}
static unsigned long F_54 ( unsigned long V_58 , unsigned long V_59 )
{
unsigned long V_52 , V_60 , V_61 ;
if ( ! ( F_26 ( V_20 ) ) ) {
V_58 += V_21 ;
V_59 += V_21 ;
F_55 ( V_52 , & ( ( (struct V_16 T_1 * ) V_59 ) -> V_15 [ 6 ] ) ) ;
V_52 += V_21 ;
} else
F_55 ( V_52 , & ( ( (struct V_8 T_1 * ) V_59 ) -> V_15 [ 6 ] ) ) ;
V_58 &= ~ 15UL ;
V_60 = V_52 - V_59 ;
V_61 = ( V_58 - V_60 ) ;
if ( F_56 ( ( void T_1 * ) V_61 , ( void T_1 * ) V_59 , V_60 ) )
V_61 = 0 ;
else if ( F_26 ( V_20 ) ) {
if ( F_57 ( ( ( V_62 ) V_58 ) ,
& ( ( (struct V_8 T_1 * ) V_61 ) -> V_15 [ 6 ] ) ) )
V_61 = 0 ;
} else {
if ( F_57 ( ( ( V_63 ) V_58 - V_21 ) ,
& ( ( (struct V_16 T_1 * ) V_61 ) -> V_15 [ 6 ] ) ) )
V_61 = 0 ;
else
V_61 = V_61 - V_21 ;
}
return V_61 ;
}
static inline void F_58 ( int V_64 , int V_65 ,
struct V_27 * V_53 )
{
int V_66 ;
for ( V_66 = V_64 ; V_66 < V_65 ; V_66 ++ ) {
V_53 -> V_67 [ V_66 ] = V_53 -> V_67 [ V_66 + 1 ] ;
memcpy ( & V_53 -> V_16 [ V_66 ] , & V_53 -> V_16 [ V_66 + 1 ] ,
sizeof( struct V_16 ) ) ;
}
}
void F_59 ( void )
{
struct V_27 * V_53 = F_37 () ;
unsigned long V_68 ;
F_60 () ;
if ( ( V_68 = F_61 () ) != 0 ) {
int V_69 = sizeof( struct V_16 ) ;
int V_70 = 0 ;
if ( F_26 ( V_20 ) )
V_69 = sizeof( struct V_8 ) ;
else
V_70 = V_21 ;
V_68 -= 1 ;
do {
unsigned long V_51 = ( V_53 -> V_67 [ V_68 ] + V_70 ) ;
struct V_16 * V_71 = & V_53 -> V_16 [ V_68 ] ;
if ( ! F_62 ( ( char T_1 * ) V_51 , V_71 , V_69 ) ) {
F_58 ( V_68 , F_61 () - 1 , V_53 ) ;
F_53 ( F_61 () - 1 ) ;
}
} while ( V_68 -- );
}
}
static void F_63 ( unsigned long V_51 )
{
T_4 V_72 ;
V_72 . V_73 = V_74 ;
V_72 . V_75 = 0 ;
V_72 . V_76 = V_77 ;
V_72 . V_78 = ( void T_1 * ) V_51 ;
V_72 . V_79 = 0 ;
F_64 ( V_74 , & V_72 , V_25 ) ;
}
void F_65 ( void )
{
struct V_27 * V_53 = F_37 () ;
unsigned long V_68 ;
int V_69 = sizeof( struct V_16 ) ;
int V_70 = 0 ;
if ( F_26 ( V_20 ) )
V_69 = sizeof( struct V_8 ) ;
else
V_70 = V_21 ;
F_60 () ;
V_68 = F_61 () ;
if ( F_66 ( V_68 != 0 ) ) {
V_68 -= 1 ;
do {
unsigned long V_51 = ( V_53 -> V_67 [ V_68 ] + V_70 ) ;
struct V_16 * V_71 = & V_53 -> V_16 [ V_68 ] ;
if ( F_67 ( V_51 & 0x7UL ) )
F_63 ( V_51 ) ;
if ( F_67 ( F_62 ( ( char T_1 * ) V_51 ,
V_71 , V_69 ) ) )
goto V_80;
} while ( V_68 -- );
}
F_53 ( 0 ) ;
return;
V_80:
F_53 ( V_68 + 1 ) ;
F_68 ( V_81 ) ;
}
T_5 long F_69 ( unsigned long V_82 ,
unsigned long V_83 ,
struct V_6 * V_7 ,
unsigned long V_84 )
{
int T_1 * V_85 , * V_86 ;
unsigned long V_87 = V_7 -> V_12 [ V_88 ] ;
long V_49 ;
#ifdef F_70
if ( F_26 ( V_20 ) ) {
V_85 = F_20 ( V_7 -> V_12 [ V_89 ] ) ;
V_86 = F_20 ( V_7 -> V_12 [ V_90 ] ) ;
} else
#endif
{
V_85 = ( int T_1 * ) V_7 -> V_12 [ V_89 ] ;
V_86 = ( int T_1 * ) V_7 -> V_12 [ V_90 ] ;
}
V_49 = F_71 ( V_82 , V_83 ,
V_7 , V_84 ,
V_85 , V_86 ) ;
if ( ( unsigned long ) V_49 >= - V_91 )
V_7 -> V_12 [ V_88 ] = V_87 ;
return V_49 ;
}
int F_72 ( unsigned long V_82 , unsigned long V_51 ,
unsigned long V_92 ,
struct V_46 * V_93 , struct V_6 * V_7 )
{
struct V_27 * V_53 = F_48 ( V_93 ) ;
struct V_94 * V_95 ;
unsigned long V_96 ;
char * V_97 ;
int V_98 ;
V_98 = ( V_7 -> V_18 & V_19 ) ? 1 : 0 ;
V_95 = ( (struct V_94 * ) V_7 ) - 1 ;
V_96 = ( ( V_99 + V_100 ) +
( V_98 ? V_99 : 0 ) ) ;
V_97 = ( F_73 ( V_93 ) +
( V_101 - V_96 ) ) ;
memcpy ( V_97 , V_95 , V_96 ) ;
V_53 -> V_38 = ( V_53 -> V_38 & ~ ( ( 0xffUL << V_102 ) |
( 0xffUL << V_103 ) ) ) |
( ( ( V_7 -> V_18 + 1 ) & V_104 ) << V_102 ) ;
V_53 -> V_105 = 1 ;
V_53 -> V_50 = ( ( unsigned long ) V_97 ) - V_21 ;
V_53 -> V_39 = (struct V_6 * ) ( V_97 +
sizeof( struct V_94 ) ) ;
V_53 -> V_57 [ 0 ] = 0 ;
if ( V_98 ) {
struct V_94 * V_106 = (struct V_94 * )
( V_97 + ( V_99 + V_100 ) ) ;
V_106 -> V_52 = NULL ;
V_53 -> V_39 -> V_12 [ V_26 ] =
( ( unsigned long ) V_106 ) - V_21 ;
V_53 -> V_38 |= ( ( long ) V_107 << V_103 ) ;
V_53 -> V_39 -> V_12 [ V_108 ] = ( unsigned long ) V_53 ;
V_53 -> V_39 -> V_12 [ V_109 ] = ( unsigned long ) V_53 -> V_41 ;
} else {
if ( V_53 -> V_38 & V_110 ) {
V_51 &= 0x00000000ffffffffUL ;
V_7 -> V_12 [ V_26 ] &= 0x00000000ffffffffUL ;
}
V_53 -> V_39 -> V_12 [ V_26 ] = V_51 ;
V_53 -> V_38 |= ( ( long ) V_111 << V_103 ) ;
if ( V_51 != V_7 -> V_12 [ V_26 ] ) {
unsigned long V_58 ;
V_58 = F_54 ( V_51 , V_7 -> V_12 [ V_26 ] ) ;
if ( ! V_58 )
return - V_112 ;
V_53 -> V_39 -> V_12 [ V_26 ] = V_58 ;
}
if ( V_53 -> V_54 )
V_53 -> V_54 [ 0 ] ++ ;
}
V_53 -> V_39 -> V_12 [ V_113 ] = V_25 -> V_43 ;
V_53 -> V_39 -> V_12 [ V_88 ] = 1 ;
V_7 -> V_12 [ V_88 ] = 0 ;
if ( V_82 & V_114 )
V_53 -> V_39 -> V_12 [ V_115 ] = V_7 -> V_12 [ V_116 ] ;
return 0 ;
}
T_6 V_98 ( int (* F_74)( void * ) , void * V_117 , unsigned long V_38 )
{
long V_118 ;
__asm__ __volatile__("mov %4, %%g2\n\t"
"mov %5, %%g3\n\t"
"mov %1, %%g1\n\t"
"mov %2, %%o0\n\t"
"mov 0, %%o1\n\t"
"t 0x6d\n\t"
"brz,a,pn %%o1, 1f\n\t"
" mov %%o0, %0\n\t"
"jmpl %%g2, %%o7\n\t"
" mov %%g3, %%o0\n\t"
"mov %3, %%g1\n\t"
"t 0x6d\n\t"
"1:" :
"=r" (retval) :
"i" (__NR_clone), "r" (flags | CLONE_VM | CLONE_UNTRACED),
"i" (__NR_exit), "r" (fn), "r" (arg) :
"g1", "g2", "g3", "o0", "o1", "memory", "cc");
return V_118 ;
}
int F_75 ( struct V_6 * V_7 , T_7 * V_119 )
{
unsigned long * V_120 = F_37 () -> V_119 ;
unsigned long V_121 = F_37 () -> V_57 [ 0 ] ;
if ( F_26 ( V_20 ) ) {
T_8 * V_122 = ( T_8 * ) V_119 ;
if ( V_121 & V_123 )
memcpy ( & V_122 -> V_124 . V_125 [ 0 ] , V_120 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_122 -> V_124 . V_125 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
V_122 -> V_126 = 0 ;
V_122 -> V_127 = 8 ;
memset ( & V_122 -> V_128 [ 0 ] , 0 ,
(sizeof( unsigned int ) * 64 ) ) ;
if ( V_121 & V_129 ) {
V_122 -> V_130 = ( unsigned int ) F_37 () -> V_131 [ 0 ] ;
V_122 -> V_132 = 1 ;
} else {
V_122 -> V_130 = 0 ;
V_122 -> V_132 = 0 ;
}
} else {
if( V_121 & V_123 )
memcpy ( & V_119 -> V_125 [ 0 ] , V_120 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_119 -> V_125 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_121 & V_133 )
memcpy ( & V_119 -> V_125 [ 16 ] , V_120 + 16 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_119 -> V_125 [ 16 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_121 & V_129 ) {
V_119 -> V_130 = F_37 () -> V_131 [ 0 ] ;
V_119 -> V_134 = F_37 () -> V_135 [ 0 ] ;
} else {
V_119 -> V_130 = V_119 -> V_134 = 0 ;
}
V_119 -> V_136 = V_121 ;
}
return 1 ;
}
T_5 int F_76 ( struct V_6 * V_7 )
{
int error , V_137 = 0 ;
char * V_138 ;
if ( V_7 -> V_12 [ V_139 ] == 0 )
V_137 = 1 ;
V_138 = F_77 ( ( char T_1 * ) V_7 -> V_12 [ V_137 + V_113 ] ) ;
error = F_78 ( V_138 ) ;
if ( F_79 ( V_138 ) )
goto V_140;
error = F_80 ( V_138 ,
( const char T_1 * const T_1 * )
V_7 -> V_12 [ V_137 + V_88 ] ,
( const char T_1 * const T_1 * )
V_7 -> V_12 [ V_137 + V_89 ] , V_7 ) ;
F_81 ( V_138 ) ;
if ( ! error ) {
F_82 ( 0 ) ;
F_37 () -> V_131 [ 0 ] = 0 ;
F_37 () -> V_57 [ 0 ] = 0 ;
V_7 -> V_18 &= ~ V_141 ;
}
V_140:
return error ;
}
unsigned long F_83 ( struct V_46 * V_41 )
{
unsigned long V_142 , V_52 , V_70 = 0 ;
struct V_27 * V_28 ;
struct V_16 * V_9 ;
unsigned long V_49 = 0 ;
int V_143 = 0 ;
if ( ! V_41 || V_41 == V_25 ||
V_41 -> V_144 == V_145 )
goto V_140;
V_28 = F_48 ( V_41 ) ;
V_70 = V_21 ;
V_52 = F_48 ( V_41 ) -> V_50 + V_70 ;
do {
if ( ! F_32 ( V_28 , V_52 ) )
break;
V_9 = (struct V_16 * ) V_52 ;
V_142 = V_9 -> V_15 [ 7 ] ;
if ( ! F_84 ( V_142 ) ) {
V_49 = V_142 ;
goto V_140;
}
V_52 = V_9 -> V_15 [ 6 ] + V_70 ;
} while ( ++ V_143 < 16 );
V_140:
return V_49 ;
}
