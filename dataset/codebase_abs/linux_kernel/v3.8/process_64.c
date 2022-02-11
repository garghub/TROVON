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
struct V_30 * V_31 ;
F_31 () ;
V_31 = & V_32 [ V_29 ] . V_33 ;
V_31 -> V_18 = V_7 -> V_18 ;
V_31 -> V_22 = V_7 -> V_22 ;
V_31 -> V_23 = V_7 -> V_23 ;
V_31 -> V_34 = V_7 -> V_12 [ V_35 ] ;
if ( V_7 -> V_18 & V_19 ) {
struct V_16 * V_9 ;
V_9 = (struct V_16 * )
( V_7 -> V_12 [ V_26 ] + V_21 ) ;
if ( F_32 ( V_28 , ( unsigned long ) V_9 ) ) {
V_31 -> V_36 = V_9 -> V_15 [ 7 ] ;
V_9 = (struct V_16 * )
( V_9 -> V_15 [ 6 ] + V_21 ) ;
if ( F_32 ( V_28 , ( unsigned long ) V_9 ) )
V_31 -> V_37 = V_9 -> V_15 [ 7 ] ;
}
} else {
V_31 -> V_36 = 0 ;
V_31 -> V_37 = 0 ;
}
V_31 -> V_38 = V_28 ;
}
static void F_33 ( struct V_30 * V_39 )
{
int V_40 = 0 ;
while ( ! V_39 -> V_38 && ++ V_40 < 100 ) {
F_34 () ;
F_35 ( 1 ) ;
}
}
void F_36 ( void )
{
struct V_27 * V_28 = F_37 () ;
struct V_6 * V_7 = F_38 () ;
unsigned long V_41 ;
int V_29 , V_1 ;
if ( ! V_7 )
V_7 = V_28 -> V_42 ;
F_39 ( & V_43 , V_41 ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_29 = F_40 () ;
F_30 ( V_28 , V_7 , V_29 ) ;
F_41 () ;
F_42 (cpu) {
struct V_30 * V_39 = & V_32 [ V_1 ] . V_33 ;
F_33 ( V_39 ) ;
V_28 = V_39 -> V_38 ;
F_24 ( L_17 ,
( V_1 == V_29 ? '*' : ' ' ) , V_1 ,
V_39 -> V_18 , V_39 -> V_22 , V_39 -> V_23 ,
( ( V_28 && V_28 -> V_44 ) ? V_28 -> V_44 -> V_45 : L_18 ) ,
( ( V_28 && V_28 -> V_44 ) ? V_28 -> V_44 -> V_46 : - 1 ) ) ;
if ( V_39 -> V_18 & V_19 ) {
F_24 ( L_19 ,
( void * ) V_39 -> V_22 ,
( void * ) V_39 -> V_34 ,
( void * ) V_39 -> V_36 ,
( void * ) V_39 -> V_37 ) ;
} else {
F_24 ( L_20 ,
V_39 -> V_22 , V_39 -> V_34 , V_39 -> V_36 , V_39 -> V_37 ) ;
}
}
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
F_43 ( & V_43 , V_41 ) ;
}
static void F_44 ( int V_47 )
{
F_36 () ;
}
static void F_45 ( int V_29 )
{
struct V_48 * V_49 ;
int V_50 , V_51 ;
V_49 = & V_32 [ V_29 ] . V_52 ;
V_51 = 1 ;
if ( V_2 == V_3 &&
V_53 >= V_54 )
V_51 = 4 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_49 -> V_55 [ V_50 ] = V_56 -> V_57 ( V_50 ) ;
V_49 -> V_58 [ V_50 ] = V_56 -> V_59 ( V_50 ) ;
}
}
static void F_46 ( struct V_48 * V_49 )
{
int V_40 = 0 ;
while ( ! V_49 -> V_55 [ 0 ] && ++ V_40 < 100 ) {
F_34 () ;
F_35 ( 1 ) ;
}
}
static void F_47 ( void )
{
unsigned long V_41 ;
int V_29 , V_1 ;
F_39 ( & V_43 , V_41 ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_29 = F_40 () ;
F_45 ( V_29 ) ;
F_48 () ;
F_42 (cpu) {
struct V_48 * V_49 = & V_32 [ V_1 ] . V_52 ;
F_46 ( V_49 ) ;
F_24 ( L_21 ,
( V_1 == V_29 ? '*' : ' ' ) , V_1 ,
V_49 -> V_55 [ 0 ] , V_49 -> V_55 [ 1 ] , V_49 -> V_55 [ 2 ] , V_49 -> V_55 [ 3 ] ,
V_49 -> V_58 [ 0 ] , V_49 -> V_58 [ 1 ] , V_49 -> V_58 [ 2 ] , V_49 -> V_58 [ 3 ] ) ;
}
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
F_43 ( & V_43 , V_41 ) ;
}
static void F_49 ( int V_47 )
{
F_47 () ;
}
static int T_3 F_50 ( void )
{
int V_60 = F_51 ( 'y' , & V_61 ) ;
if ( ! V_60 )
V_60 = F_51 ( 'x' , & V_62 ) ;
return V_60 ;
}
unsigned long F_52 ( struct V_63 * V_64 )
{
struct V_27 * V_65 = F_53 ( V_64 ) ;
unsigned long V_60 = 0xdeadbeefUL ;
if ( V_65 && V_65 -> V_66 ) {
unsigned long * V_67 ;
V_67 = ( unsigned long * ) ( V_65 -> V_66 + V_21 ) ;
if ( ( ( unsigned long ) V_67 & ( sizeof( long ) - 1 ) ) == 0UL &&
V_67 [ 14 ] ) {
unsigned long * V_68 ;
V_68 = ( unsigned long * ) ( V_67 [ 14 ] + V_21 ) ;
if ( ( ( unsigned long ) V_68 & ( sizeof( long ) - 1 ) ) == 0UL )
V_60 = V_68 [ 15 ] ;
}
}
return V_60 ;
}
void F_54 ( void )
{
struct V_27 * V_69 = F_37 () ;
if ( V_69 -> V_70 ) {
if ( V_69 -> V_70 [ 0 ] < 2 )
F_55 ( V_69 -> V_70 ) ;
else
V_69 -> V_70 [ 0 ] -- ;
}
}
void F_56 ( void )
{
struct V_27 * V_69 = F_37 () ;
struct V_71 * V_72 ;
V_72 = V_69 -> V_44 -> V_72 ;
if ( V_72 )
F_57 ( V_72 ) ;
F_58 ( 0 ) ;
V_69 -> V_73 [ 0 ] = 0 ;
}
static unsigned long F_59 ( unsigned long V_74 , unsigned long V_75 )
{
bool V_76 = F_60 ( V_75 ) ;
unsigned long V_68 , V_77 , V_78 ;
if ( V_76 ) {
V_74 += V_21 ;
V_75 += V_21 ;
F_61 ( V_68 , & ( ( (struct V_16 T_1 * ) V_75 ) -> V_15 [ 6 ] ) ) ;
V_68 += V_21 ;
if ( F_26 ( V_20 ) )
V_68 &= 0xffffffff ;
} else
F_61 ( V_68 , & ( ( (struct V_8 T_1 * ) V_75 ) -> V_15 [ 6 ] ) ) ;
V_74 &= ~ 15UL ;
V_77 = V_68 - V_75 ;
V_78 = ( V_74 - V_77 ) ;
if ( F_62 ( ( void T_1 * ) V_78 , ( void T_1 * ) V_75 , V_77 ) )
V_78 = 0 ;
else if ( ! V_76 ) {
if ( F_63 ( ( ( V_79 ) V_74 ) ,
& ( ( (struct V_8 T_1 * ) V_78 ) -> V_15 [ 6 ] ) ) )
V_78 = 0 ;
} else {
if ( F_63 ( ( ( V_80 ) V_74 - V_21 ) ,
& ( ( (struct V_16 T_1 * ) V_78 ) -> V_15 [ 6 ] ) ) )
V_78 = 0 ;
else
V_78 = V_78 - V_21 ;
}
return V_78 ;
}
static inline void F_64 ( int V_81 , int V_82 ,
struct V_27 * V_69 )
{
int V_50 ;
for ( V_50 = V_81 ; V_50 < V_82 ; V_50 ++ ) {
V_69 -> V_83 [ V_50 ] = V_69 -> V_83 [ V_50 + 1 ] ;
memcpy ( & V_69 -> V_16 [ V_50 ] , & V_69 -> V_16 [ V_50 + 1 ] ,
sizeof( struct V_16 ) ) ;
}
}
void F_65 ( void )
{
struct V_27 * V_69 = F_37 () ;
unsigned long V_84 ;
F_66 () ;
if ( ( V_84 = F_67 () ) != 0 ) {
V_84 -= 1 ;
do {
struct V_16 * V_85 = & V_69 -> V_16 [ V_84 ] ;
int V_86 = sizeof( struct V_16 ) ;
unsigned long V_67 ;
V_67 = V_69 -> V_83 [ V_84 ] ;
if ( F_60 ( V_67 ) )
V_67 += V_21 ;
else
V_86 = sizeof( struct V_8 ) ;
if ( ! F_68 ( ( char T_1 * ) V_67 , V_85 , V_86 ) ) {
F_64 ( V_84 , F_67 () - 1 , V_69 ) ;
F_58 ( F_67 () - 1 ) ;
}
} while ( V_84 -- );
}
}
static void F_69 ( unsigned long V_67 )
{
T_4 V_87 ;
V_87 . V_88 = V_89 ;
V_87 . V_90 = 0 ;
V_87 . V_91 = V_92 ;
V_87 . V_93 = ( void T_1 * ) V_67 ;
V_87 . V_94 = 0 ;
F_70 ( V_89 , & V_87 , V_25 ) ;
}
void F_71 ( void )
{
struct V_27 * V_69 = F_37 () ;
unsigned long V_84 ;
F_66 () ;
V_84 = F_67 () ;
if ( F_72 ( V_84 != 0 ) ) {
V_84 -= 1 ;
do {
struct V_16 * V_85 = & V_69 -> V_16 [ V_84 ] ;
int V_86 = sizeof( struct V_16 ) ;
unsigned long V_67 ;
V_67 = V_69 -> V_83 [ V_84 ] ;
if ( F_60 ( V_67 ) )
V_67 += V_21 ;
else
V_86 = sizeof( struct V_8 ) ;
if ( F_73 ( V_67 & 0x7UL ) )
F_69 ( V_67 ) ;
if ( F_73 ( F_68 ( ( char T_1 * ) V_67 ,
V_85 , V_86 ) ) )
goto V_95;
} while ( V_84 -- );
}
F_58 ( 0 ) ;
return;
V_95:
F_58 ( V_84 + 1 ) ;
F_74 ( V_96 ) ;
}
T_5 long F_75 ( unsigned long V_97 ,
unsigned long V_98 ,
struct V_6 * V_7 ,
unsigned long V_99 )
{
int T_1 * V_100 , * V_101 ;
unsigned long V_102 = V_7 -> V_12 [ V_103 ] ;
long V_60 ;
#ifdef F_76
if ( F_26 ( V_20 ) ) {
V_100 = F_20 ( V_7 -> V_12 [ V_104 ] ) ;
V_101 = F_20 ( V_7 -> V_12 [ V_105 ] ) ;
} else
#endif
{
V_100 = ( int T_1 * ) V_7 -> V_12 [ V_104 ] ;
V_101 = ( int T_1 * ) V_7 -> V_12 [ V_105 ] ;
}
V_60 = F_77 ( V_97 , V_98 , V_99 ,
V_100 , V_101 ) ;
if ( ( unsigned long ) V_60 >= - V_106 )
V_7 -> V_12 [ V_103 ] = V_102 ;
return V_60 ;
}
int F_78 ( unsigned long V_97 , unsigned long V_67 ,
unsigned long V_107 , struct V_63 * V_108 )
{
struct V_27 * V_69 = F_53 ( V_108 ) ;
struct V_6 * V_7 = F_79 () ;
struct V_109 * V_110 ;
unsigned long V_111 ;
char * V_112 ;
V_111 = ( V_113 + V_114 ) ;
V_112 = ( F_80 ( V_108 ) +
( V_115 - V_111 ) ) ;
V_69 -> V_116 = 1 ;
V_69 -> V_66 = ( ( unsigned long ) V_112 ) - V_21 ;
V_69 -> V_42 = (struct V_6 * ) ( V_112 +
sizeof( struct V_109 ) ) ;
V_69 -> V_73 [ 0 ] = 0 ;
if ( F_73 ( V_108 -> V_41 & V_117 ) ) {
memset ( V_112 , 0 , V_111 ) ;
F_81 ( V_69 ) [ V_118 ] =
( F_79 () -> V_18 + 1 ) & V_119 ;
V_69 -> V_120 = V_121 ;
V_69 -> V_42 -> V_12 [ V_122 ] = V_67 ;
V_69 -> V_42 -> V_12 [ V_123 ] = V_107 ;
return 0 ;
}
V_110 = ( (struct V_109 * ) V_7 ) - 1 ;
memcpy ( V_112 , V_110 , V_111 ) ;
if ( V_69 -> V_41 & V_124 ) {
V_67 &= 0x00000000ffffffffUL ;
V_7 -> V_12 [ V_26 ] &= 0x00000000ffffffffUL ;
}
V_69 -> V_42 -> V_12 [ V_26 ] = V_67 ;
F_81 ( V_69 ) [ V_118 ] =
( V_7 -> V_18 + 1 ) & V_119 ;
V_69 -> V_120 = V_125 ;
if ( V_67 != V_7 -> V_12 [ V_26 ] ) {
unsigned long V_74 ;
V_74 = F_59 ( V_67 , V_7 -> V_12 [ V_26 ] ) ;
if ( ! V_74 )
return - V_126 ;
V_69 -> V_42 -> V_12 [ V_26 ] = V_74 ;
}
if ( V_69 -> V_70 )
V_69 -> V_70 [ 0 ] ++ ;
V_69 -> V_42 -> V_12 [ V_127 ] = V_25 -> V_46 ;
V_69 -> V_42 -> V_12 [ V_103 ] = 1 ;
V_7 -> V_12 [ V_103 ] = 0 ;
if ( V_97 & V_128 )
V_69 -> V_42 -> V_12 [ V_129 ] = V_7 -> V_12 [ V_130 ] ;
return 0 ;
}
int F_82 ( struct V_6 * V_7 , T_6 * V_131 )
{
unsigned long * V_132 = F_37 () -> V_131 ;
unsigned long V_133 = F_37 () -> V_73 [ 0 ] ;
if ( F_26 ( V_20 ) ) {
T_7 * V_134 = ( T_7 * ) V_131 ;
if ( V_133 & V_135 )
memcpy ( & V_134 -> V_136 . V_137 [ 0 ] , V_132 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_134 -> V_136 . V_137 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
V_134 -> V_138 = 0 ;
V_134 -> V_139 = 8 ;
memset ( & V_134 -> V_140 [ 0 ] , 0 ,
(sizeof( unsigned int ) * 64 ) ) ;
if ( V_133 & V_141 ) {
V_134 -> V_142 = ( unsigned int ) F_37 () -> V_143 [ 0 ] ;
V_134 -> V_144 = 1 ;
} else {
V_134 -> V_142 = 0 ;
V_134 -> V_144 = 0 ;
}
} else {
if( V_133 & V_135 )
memcpy ( & V_131 -> V_137 [ 0 ] , V_132 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_131 -> V_137 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_133 & V_145 )
memcpy ( & V_131 -> V_137 [ 16 ] , V_132 + 16 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_131 -> V_137 [ 16 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_133 & V_141 ) {
V_131 -> V_142 = F_37 () -> V_143 [ 0 ] ;
V_131 -> V_146 = F_37 () -> V_147 [ 0 ] ;
} else {
V_131 -> V_142 = V_131 -> V_146 = 0 ;
}
V_131 -> V_148 = V_133 ;
}
return 1 ;
}
unsigned long F_83 ( struct V_63 * V_44 )
{
unsigned long V_149 , V_68 , V_150 = 0 ;
struct V_27 * V_28 ;
struct V_16 * V_9 ;
unsigned long V_60 = 0 ;
int V_151 = 0 ;
if ( ! V_44 || V_44 == V_25 ||
V_44 -> V_152 == V_153 )
goto V_154;
V_28 = F_53 ( V_44 ) ;
V_150 = V_21 ;
V_68 = F_53 ( V_44 ) -> V_66 + V_150 ;
do {
if ( ! F_32 ( V_28 , V_68 ) )
break;
V_9 = (struct V_16 * ) V_68 ;
V_149 = V_9 -> V_15 [ 7 ] ;
if ( ! F_84 ( V_149 ) ) {
V_60 = V_149 ;
goto V_154;
}
V_68 = V_9 -> V_15 [ 6 ] + V_150 ;
} while ( ++ V_151 < 16 );
V_154:
return V_60 ;
}
