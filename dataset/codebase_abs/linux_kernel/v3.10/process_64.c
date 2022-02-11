void F_1 ( void )
{
if ( V_1 != V_2 ) {
F_2 () ;
} else {
unsigned long V_3 ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"andn %0, %1, %0\n\t"
"wrpr %0, %%g0, %%pstate"
: "=&r" (pstate)
: "i" (PSTATE_IE));
if ( ! F_3 () && ! F_4 ( F_5 () ) )
F_6 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"or %0, %1, %0\n\t"
"wrpr %0, %%g0, %%pstate"
: "=&r" (pstate)
: "i" (PSTATE_IE));
}
F_7 () ;
}
void F_8 ()
{
F_9 () ;
F_10 () ;
}
static void F_11 ( struct V_4 * V_5 )
{
struct V_6 T_1 * V_7 ;
struct V_6 V_8 ;
T_2 V_9 ;
__asm__ __volatile__ ("flushw");
V_7 = F_12 ( ( unsigned ) V_5 -> V_10 [ 14 ] ) ;
V_9 = F_13 () ;
F_14 ( V_11 ) ;
if ( F_15 ( & V_8 , V_7 , sizeof( V_8 ) ) ) {
F_14 ( V_9 ) ;
return;
}
F_14 ( V_9 ) ;
F_16 ( L_1
L_2 ,
V_8 . V_12 [ 0 ] , V_8 . V_12 [ 1 ] , V_8 . V_12 [ 2 ] , V_8 . V_12 [ 3 ] ,
V_8 . V_12 [ 4 ] , V_8 . V_12 [ 5 ] , V_8 . V_12 [ 6 ] , V_8 . V_12 [ 7 ] ) ;
F_16 ( L_3
L_4 ,
V_8 . V_13 [ 0 ] , V_8 . V_13 [ 1 ] , V_8 . V_13 [ 2 ] , V_8 . V_13 [ 3 ] ,
V_8 . V_13 [ 4 ] , V_8 . V_13 [ 5 ] , V_8 . V_13 [ 6 ] , V_8 . V_13 [ 7 ] ) ;
}
static void F_17 ( struct V_4 * V_5 )
{
struct V_14 T_1 * V_7 ;
struct V_14 * V_15 ;
struct V_14 V_8 ;
T_2 V_9 ;
if ( ( V_5 -> V_16 & V_17 ) || ! ( F_18 ( V_18 ) ) ) {
__asm__ __volatile__ ("flushw");
V_7 = (struct V_14 T_1 * )
( V_5 -> V_10 [ 14 ] + V_19 ) ;
V_15 = (struct V_14 * )
( V_5 -> V_10 [ 14 ] + V_19 ) ;
if ( ! ( V_5 -> V_16 & V_17 ) ) {
V_9 = F_13 () ;
F_14 ( V_11 ) ;
if ( F_15 ( & V_8 , V_7 , sizeof( V_8 ) ) ) {
F_14 ( V_9 ) ;
return;
}
V_15 = & V_8 ;
F_14 ( V_9 ) ;
}
} else {
F_11 ( V_5 ) ;
return;
}
F_16 ( L_5 ,
V_15 -> V_12 [ 0 ] , V_15 -> V_12 [ 1 ] , V_15 -> V_12 [ 2 ] , V_15 -> V_12 [ 3 ] ) ;
F_16 ( L_6 ,
V_15 -> V_12 [ 4 ] , V_15 -> V_12 [ 5 ] , V_15 -> V_12 [ 6 ] , V_15 -> V_12 [ 7 ] ) ;
F_16 ( L_7 ,
V_15 -> V_13 [ 0 ] , V_15 -> V_13 [ 1 ] , V_15 -> V_13 [ 2 ] , V_15 -> V_13 [ 3 ] ) ;
F_16 ( L_8 ,
V_15 -> V_13 [ 4 ] , V_15 -> V_13 [ 5 ] , V_15 -> V_13 [ 6 ] , V_15 -> V_13 [ 7 ] ) ;
if ( V_5 -> V_16 & V_17 )
F_16 ( L_9 , ( void * ) V_15 -> V_13 [ 7 ] ) ;
}
void F_19 ( struct V_4 * V_5 )
{
F_20 ( V_20 ) ;
F_16 ( L_10 , V_5 -> V_16 ,
V_5 -> V_21 , V_5 -> V_22 , V_5 -> V_23 , F_21 () ) ;
F_16 ( L_11 , ( void * ) V_5 -> V_21 ) ;
F_16 ( L_12 ,
V_5 -> V_10 [ 0 ] , V_5 -> V_10 [ 1 ] , V_5 -> V_10 [ 2 ] ,
V_5 -> V_10 [ 3 ] ) ;
F_16 ( L_13 ,
V_5 -> V_10 [ 4 ] , V_5 -> V_10 [ 5 ] , V_5 -> V_10 [ 6 ] ,
V_5 -> V_10 [ 7 ] ) ;
F_16 ( L_14 ,
V_5 -> V_10 [ 8 ] , V_5 -> V_10 [ 9 ] , V_5 -> V_10 [ 10 ] ,
V_5 -> V_10 [ 11 ] ) ;
F_16 ( L_15 ,
V_5 -> V_10 [ 12 ] , V_5 -> V_10 [ 13 ] , V_5 -> V_10 [ 14 ] ,
V_5 -> V_10 [ 15 ] ) ;
F_16 ( L_16 , ( void * ) V_5 -> V_10 [ 15 ] ) ;
F_17 ( V_5 ) ;
F_22 ( V_24 , ( unsigned long * ) V_5 -> V_10 [ V_25 ] ) ;
}
static void F_23 ( struct V_26 * V_27 , struct V_4 * V_5 ,
int V_28 )
{
struct V_29 * V_30 ;
F_24 () ;
V_30 = & V_31 [ V_28 ] . V_32 ;
V_30 -> V_16 = V_5 -> V_16 ;
V_30 -> V_21 = V_5 -> V_21 ;
V_30 -> V_22 = V_5 -> V_22 ;
V_30 -> V_33 = V_5 -> V_10 [ V_34 ] ;
if ( V_5 -> V_16 & V_17 ) {
struct V_14 * V_7 ;
V_7 = (struct V_14 * )
( V_5 -> V_10 [ V_25 ] + V_19 ) ;
if ( F_25 ( V_27 , ( unsigned long ) V_7 ) ) {
V_30 -> V_35 = V_7 -> V_13 [ 7 ] ;
V_7 = (struct V_14 * )
( V_7 -> V_13 [ 6 ] + V_19 ) ;
if ( F_25 ( V_27 , ( unsigned long ) V_7 ) )
V_30 -> V_36 = V_7 -> V_13 [ 7 ] ;
}
} else {
V_30 -> V_35 = 0 ;
V_30 -> V_36 = 0 ;
}
V_30 -> V_37 = V_27 ;
}
static void F_26 ( struct V_29 * V_38 )
{
int V_39 = 0 ;
while ( ! V_38 -> V_37 && ++ V_39 < 100 ) {
F_27 () ;
F_28 ( 1 ) ;
}
}
void F_29 ( void )
{
struct V_26 * V_27 = F_30 () ;
struct V_4 * V_5 = F_31 () ;
unsigned long V_40 ;
int V_28 , V_41 ;
if ( ! V_5 )
V_5 = V_27 -> V_42 ;
F_32 ( & V_43 , V_40 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_28 = F_33 () ;
F_23 ( V_27 , V_5 , V_28 ) ;
F_34 () ;
F_35 (cpu) {
struct V_29 * V_38 = & V_31 [ V_41 ] . V_32 ;
F_26 ( V_38 ) ;
V_27 = V_38 -> V_37 ;
F_16 ( L_17 ,
( V_41 == V_28 ? '*' : ' ' ) , V_41 ,
V_38 -> V_16 , V_38 -> V_21 , V_38 -> V_22 ,
( ( V_27 && V_27 -> V_44 ) ? V_27 -> V_44 -> V_45 : L_18 ) ,
( ( V_27 && V_27 -> V_44 ) ? V_27 -> V_44 -> V_46 : - 1 ) ) ;
if ( V_38 -> V_16 & V_17 ) {
F_16 ( L_19 ,
( void * ) V_38 -> V_21 ,
( void * ) V_38 -> V_33 ,
( void * ) V_38 -> V_35 ,
( void * ) V_38 -> V_36 ) ;
} else {
F_16 ( L_20 ,
V_38 -> V_21 , V_38 -> V_33 , V_38 -> V_35 , V_38 -> V_36 ) ;
}
}
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_36 ( & V_43 , V_40 ) ;
}
static void F_37 ( int V_47 )
{
F_29 () ;
}
static void F_38 ( int V_28 )
{
struct V_48 * V_49 ;
int V_50 , V_51 ;
V_49 = & V_31 [ V_28 ] . V_52 ;
V_51 = 1 ;
if ( V_1 == V_2 &&
V_53 >= V_54 )
V_51 = 4 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_49 -> V_55 [ V_50 ] = V_56 -> V_57 ( V_50 ) ;
V_49 -> V_58 [ V_50 ] = V_56 -> V_59 ( V_50 ) ;
}
}
static void F_39 ( struct V_48 * V_49 )
{
int V_39 = 0 ;
while ( ! V_49 -> V_55 [ 0 ] && ++ V_39 < 100 ) {
F_27 () ;
F_28 ( 1 ) ;
}
}
static void F_40 ( void )
{
unsigned long V_40 ;
int V_28 , V_41 ;
F_32 ( & V_43 , V_40 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_28 = F_33 () ;
F_38 ( V_28 ) ;
F_41 () ;
F_35 (cpu) {
struct V_48 * V_49 = & V_31 [ V_41 ] . V_52 ;
F_39 ( V_49 ) ;
F_16 ( L_21 ,
( V_41 == V_28 ? '*' : ' ' ) , V_41 ,
V_49 -> V_55 [ 0 ] , V_49 -> V_55 [ 1 ] , V_49 -> V_55 [ 2 ] , V_49 -> V_55 [ 3 ] ,
V_49 -> V_58 [ 0 ] , V_49 -> V_58 [ 1 ] , V_49 -> V_58 [ 2 ] , V_49 -> V_58 [ 3 ] ) ;
}
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_36 ( & V_43 , V_40 ) ;
}
static void F_42 ( int V_47 )
{
F_40 () ;
}
static int T_3 F_43 ( void )
{
int V_60 = F_44 ( 'y' , & V_61 ) ;
if ( ! V_60 )
V_60 = F_44 ( 'x' , & V_62 ) ;
return V_60 ;
}
unsigned long F_45 ( struct V_63 * V_64 )
{
struct V_26 * V_65 = F_46 ( V_64 ) ;
unsigned long V_60 = 0xdeadbeefUL ;
if ( V_65 && V_65 -> V_66 ) {
unsigned long * V_67 ;
V_67 = ( unsigned long * ) ( V_65 -> V_66 + V_19 ) ;
if ( ( ( unsigned long ) V_67 & ( sizeof( long ) - 1 ) ) == 0UL &&
V_67 [ 14 ] ) {
unsigned long * V_68 ;
V_68 = ( unsigned long * ) ( V_67 [ 14 ] + V_19 ) ;
if ( ( ( unsigned long ) V_68 & ( sizeof( long ) - 1 ) ) == 0UL )
V_60 = V_68 [ 15 ] ;
}
}
return V_60 ;
}
void F_47 ( void )
{
struct V_26 * V_69 = F_30 () ;
if ( V_69 -> V_70 ) {
if ( V_69 -> V_70 [ 0 ] < 2 )
F_48 ( V_69 -> V_70 ) ;
else
V_69 -> V_70 [ 0 ] -- ;
}
}
void F_49 ( void )
{
struct V_26 * V_69 = F_30 () ;
struct V_71 * V_72 ;
V_72 = V_69 -> V_44 -> V_72 ;
if ( V_72 )
F_50 ( V_72 ) ;
F_51 ( 0 ) ;
V_69 -> V_73 [ 0 ] = 0 ;
}
static unsigned long F_52 ( unsigned long V_74 , unsigned long V_75 )
{
bool V_76 = F_53 ( V_75 ) ;
unsigned long V_68 , V_77 , V_78 ;
if ( V_76 ) {
V_74 += V_19 ;
V_75 += V_19 ;
F_54 ( V_68 , & ( ( (struct V_14 T_1 * ) V_75 ) -> V_13 [ 6 ] ) ) ;
V_68 += V_19 ;
if ( F_18 ( V_18 ) )
V_68 &= 0xffffffff ;
} else
F_54 ( V_68 , & ( ( (struct V_6 T_1 * ) V_75 ) -> V_13 [ 6 ] ) ) ;
V_74 &= ~ 15UL ;
V_77 = V_68 - V_75 ;
V_78 = ( V_74 - V_77 ) ;
if ( F_55 ( ( void T_1 * ) V_78 , ( void T_1 * ) V_75 , V_77 ) )
V_78 = 0 ;
else if ( ! V_76 ) {
if ( F_56 ( ( ( V_79 ) V_74 ) ,
& ( ( (struct V_6 T_1 * ) V_78 ) -> V_13 [ 6 ] ) ) )
V_78 = 0 ;
} else {
if ( F_56 ( ( ( V_80 ) V_74 - V_19 ) ,
& ( ( (struct V_14 T_1 * ) V_78 ) -> V_13 [ 6 ] ) ) )
V_78 = 0 ;
else
V_78 = V_78 - V_19 ;
}
return V_78 ;
}
static inline void F_57 ( int V_81 , int V_82 ,
struct V_26 * V_69 )
{
int V_50 ;
for ( V_50 = V_81 ; V_50 < V_82 ; V_50 ++ ) {
V_69 -> V_83 [ V_50 ] = V_69 -> V_83 [ V_50 + 1 ] ;
memcpy ( & V_69 -> V_14 [ V_50 ] , & V_69 -> V_14 [ V_50 + 1 ] ,
sizeof( struct V_14 ) ) ;
}
}
void F_58 ( void )
{
struct V_26 * V_69 = F_30 () ;
unsigned long V_84 ;
F_59 () ;
if ( ( V_84 = F_60 () ) != 0 ) {
V_84 -= 1 ;
do {
struct V_14 * V_85 = & V_69 -> V_14 [ V_84 ] ;
int V_86 = sizeof( struct V_14 ) ;
unsigned long V_67 ;
V_67 = V_69 -> V_83 [ V_84 ] ;
if ( F_53 ( V_67 ) )
V_67 += V_19 ;
else
V_86 = sizeof( struct V_6 ) ;
if ( ! F_61 ( ( char T_1 * ) V_67 , V_85 , V_86 ) ) {
F_57 ( V_84 , F_60 () - 1 , V_69 ) ;
F_51 ( F_60 () - 1 ) ;
}
} while ( V_84 -- );
}
}
static void F_62 ( unsigned long V_67 )
{
T_4 V_87 ;
V_87 . V_88 = V_89 ;
V_87 . V_90 = 0 ;
V_87 . V_91 = V_92 ;
V_87 . V_93 = ( void T_1 * ) V_67 ;
V_87 . V_94 = 0 ;
F_63 ( V_89 , & V_87 , V_24 ) ;
}
void F_64 ( void )
{
struct V_26 * V_69 = F_30 () ;
unsigned long V_84 ;
F_59 () ;
V_84 = F_60 () ;
if ( F_65 ( V_84 != 0 ) ) {
V_84 -= 1 ;
do {
struct V_14 * V_85 = & V_69 -> V_14 [ V_84 ] ;
int V_86 = sizeof( struct V_14 ) ;
unsigned long V_67 ;
V_67 = V_69 -> V_83 [ V_84 ] ;
if ( F_53 ( V_67 ) )
V_67 += V_19 ;
else
V_86 = sizeof( struct V_6 ) ;
if ( F_66 ( V_67 & 0x7UL ) )
F_62 ( V_67 ) ;
if ( F_66 ( F_61 ( ( char T_1 * ) V_67 ,
V_85 , V_86 ) ) )
goto V_95;
} while ( V_84 -- );
}
F_51 ( 0 ) ;
return;
V_95:
F_51 ( V_84 + 1 ) ;
F_67 ( V_96 ) ;
}
T_5 long F_68 ( unsigned long V_97 ,
unsigned long V_98 ,
struct V_4 * V_5 ,
unsigned long V_99 )
{
int T_1 * V_100 , * V_101 ;
unsigned long V_102 = V_5 -> V_10 [ V_103 ] ;
long V_60 ;
#ifdef F_69
if ( F_18 ( V_18 ) ) {
V_100 = F_12 ( V_5 -> V_10 [ V_104 ] ) ;
V_101 = F_12 ( V_5 -> V_10 [ V_105 ] ) ;
} else
#endif
{
V_100 = ( int T_1 * ) V_5 -> V_10 [ V_104 ] ;
V_101 = ( int T_1 * ) V_5 -> V_10 [ V_105 ] ;
}
V_60 = F_70 ( V_97 , V_98 , V_99 ,
V_100 , V_101 ) ;
if ( ( unsigned long ) V_60 >= - V_106 )
V_5 -> V_10 [ V_103 ] = V_102 ;
return V_60 ;
}
int F_71 ( unsigned long V_97 , unsigned long V_67 ,
unsigned long V_107 , struct V_63 * V_108 )
{
struct V_26 * V_69 = F_46 ( V_108 ) ;
struct V_4 * V_5 = F_72 () ;
struct V_109 * V_110 ;
unsigned long V_111 ;
char * V_112 ;
V_111 = ( V_113 + V_114 ) ;
V_112 = ( F_73 ( V_108 ) +
( V_115 - V_111 ) ) ;
V_69 -> V_116 = 1 ;
V_69 -> V_66 = ( ( unsigned long ) V_112 ) - V_19 ;
V_69 -> V_42 = (struct V_4 * ) ( V_112 +
sizeof( struct V_109 ) ) ;
V_69 -> V_73 [ 0 ] = 0 ;
if ( F_66 ( V_108 -> V_40 & V_117 ) ) {
memset ( V_112 , 0 , V_111 ) ;
F_74 ( V_69 ) [ V_118 ] =
( F_72 () -> V_16 + 1 ) & V_119 ;
V_69 -> V_120 = V_121 ;
V_69 -> V_42 -> V_10 [ V_122 ] = V_67 ;
V_69 -> V_42 -> V_10 [ V_123 ] = V_107 ;
return 0 ;
}
V_110 = ( (struct V_109 * ) V_5 ) - 1 ;
memcpy ( V_112 , V_110 , V_111 ) ;
if ( V_69 -> V_40 & V_124 ) {
V_67 &= 0x00000000ffffffffUL ;
V_5 -> V_10 [ V_25 ] &= 0x00000000ffffffffUL ;
}
V_69 -> V_42 -> V_10 [ V_25 ] = V_67 ;
F_74 ( V_69 ) [ V_118 ] =
( V_5 -> V_16 + 1 ) & V_119 ;
V_69 -> V_120 = V_125 ;
if ( V_67 != V_5 -> V_10 [ V_25 ] ) {
unsigned long V_74 ;
V_74 = F_52 ( V_67 , V_5 -> V_10 [ V_25 ] ) ;
if ( ! V_74 )
return - V_126 ;
V_69 -> V_42 -> V_10 [ V_25 ] = V_74 ;
}
if ( V_69 -> V_70 )
V_69 -> V_70 [ 0 ] ++ ;
V_69 -> V_42 -> V_10 [ V_127 ] = V_24 -> V_46 ;
V_69 -> V_42 -> V_10 [ V_103 ] = 1 ;
V_5 -> V_10 [ V_103 ] = 0 ;
if ( V_97 & V_128 )
V_69 -> V_42 -> V_10 [ V_129 ] = V_5 -> V_10 [ V_130 ] ;
return 0 ;
}
int F_75 ( struct V_4 * V_5 , T_6 * V_131 )
{
unsigned long * V_132 = F_30 () -> V_131 ;
unsigned long V_133 = F_30 () -> V_73 [ 0 ] ;
if ( F_18 ( V_18 ) ) {
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
V_134 -> V_142 = ( unsigned int ) F_30 () -> V_143 [ 0 ] ;
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
V_131 -> V_142 = F_30 () -> V_143 [ 0 ] ;
V_131 -> V_146 = F_30 () -> V_147 [ 0 ] ;
} else {
V_131 -> V_142 = V_131 -> V_146 = 0 ;
}
V_131 -> V_148 = V_133 ;
}
return 1 ;
}
unsigned long F_76 ( struct V_63 * V_44 )
{
unsigned long V_149 , V_68 , V_150 = 0 ;
struct V_26 * V_27 ;
struct V_14 * V_7 ;
unsigned long V_60 = 0 ;
int V_151 = 0 ;
if ( ! V_44 || V_44 == V_24 ||
V_44 -> V_152 == V_153 )
goto V_154;
V_27 = F_46 ( V_44 ) ;
V_150 = V_19 ;
V_68 = F_46 ( V_44 ) -> V_66 + V_150 ;
do {
if ( ! F_25 ( V_27 , V_68 ) )
break;
V_7 = (struct V_14 * ) V_68 ;
V_149 = V_7 -> V_13 [ 7 ] ;
if ( ! F_77 ( V_149 ) ) {
V_60 = V_149 ;
goto V_154;
}
V_68 = V_7 -> V_13 [ 6 ] + V_150 ;
} while ( ++ V_151 < 16 );
V_154:
return V_60 ;
}
