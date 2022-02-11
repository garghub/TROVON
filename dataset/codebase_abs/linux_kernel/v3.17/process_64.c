void F_1 ( void )
{
if ( V_1 != V_2 ) {
F_2 () ;
F_3 () ;
} else {
unsigned long V_3 ;
F_3 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"andn %0, %1, %0\n\t"
"wrpr %0, %%g0, %%pstate"
: "=&r" (pstate)
: "i" (PSTATE_IE));
if ( ! F_4 () && ! F_5 ( F_6 () ) )
F_7 () ;
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"or %0, %1, %0\n\t"
"wrpr %0, %%g0, %%pstate"
: "=&r" (pstate)
: "i" (PSTATE_IE));
}
}
void F_8 ( void )
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
void F_29 ( bool V_40 )
{
struct V_26 * V_27 = F_30 () ;
struct V_4 * V_5 = F_31 () ;
unsigned long V_41 ;
int V_28 , V_42 ;
if ( ! V_5 )
V_5 = V_27 -> V_43 ;
F_32 ( & V_44 , V_41 ) ;
V_28 = F_33 () ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
if ( V_40 )
F_23 ( V_27 , V_5 , V_28 ) ;
F_34 () ;
F_35 (cpu) {
struct V_29 * V_38 ;
if ( ! V_40 && V_42 == V_28 )
continue;
V_38 = & V_31 [ V_42 ] . V_32 ;
F_26 ( V_38 ) ;
V_27 = V_38 -> V_37 ;
F_16 ( L_17 ,
( V_42 == V_28 ? '*' : ' ' ) , V_42 ,
V_38 -> V_16 , V_38 -> V_21 , V_38 -> V_22 ,
( ( V_27 && V_27 -> V_45 ) ? V_27 -> V_45 -> V_46 : L_18 ) ,
( ( V_27 && V_27 -> V_45 ) ? V_27 -> V_45 -> V_47 : - 1 ) ) ;
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
F_36 ( & V_44 , V_41 ) ;
}
static void F_37 ( int V_48 )
{
F_29 ( true ) ;
}
static void F_38 ( int V_28 )
{
struct V_49 * V_50 ;
int V_51 , V_52 ;
if ( ! V_53 )
return;
V_50 = & V_31 [ V_28 ] . V_54 ;
V_52 = 1 ;
if ( V_1 == V_2 &&
V_55 >= V_56 )
V_52 = 4 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_50 -> V_57 [ V_51 ] = V_53 -> V_58 ( V_51 ) ;
V_50 -> V_59 [ V_51 ] = V_53 -> V_60 ( V_51 ) ;
}
}
static void F_39 ( struct V_49 * V_50 )
{
int V_39 = 0 ;
while ( ! V_50 -> V_57 [ 0 ] && ++ V_39 < 100 ) {
F_27 () ;
F_28 ( 1 ) ;
}
}
static void F_40 ( void )
{
unsigned long V_41 ;
int V_28 , V_42 ;
F_32 ( & V_44 , V_41 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_28 = F_33 () ;
F_38 ( V_28 ) ;
F_41 () ;
F_35 (cpu) {
struct V_49 * V_50 = & V_31 [ V_42 ] . V_54 ;
F_39 ( V_50 ) ;
F_16 ( L_21 ,
( V_42 == V_28 ? '*' : ' ' ) , V_42 ,
V_50 -> V_57 [ 0 ] , V_50 -> V_57 [ 1 ] , V_50 -> V_57 [ 2 ] , V_50 -> V_57 [ 3 ] ,
V_50 -> V_59 [ 0 ] , V_50 -> V_59 [ 1 ] , V_50 -> V_59 [ 2 ] , V_50 -> V_59 [ 3 ] ) ;
}
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_36 ( & V_44 , V_41 ) ;
}
static void F_42 ( int V_48 )
{
F_40 () ;
}
static int T_3 F_43 ( void )
{
int V_61 = F_44 ( 'y' , & V_62 ) ;
if ( ! V_61 )
V_61 = F_44 ( 'x' , & V_63 ) ;
return V_61 ;
}
unsigned long F_45 ( struct V_64 * V_65 )
{
struct V_26 * V_66 = F_46 ( V_65 ) ;
unsigned long V_61 = 0xdeadbeefUL ;
if ( V_66 && V_66 -> V_67 ) {
unsigned long * V_68 ;
V_68 = ( unsigned long * ) ( V_66 -> V_67 + V_19 ) ;
if ( ( ( unsigned long ) V_68 & ( sizeof( long ) - 1 ) ) == 0UL &&
V_68 [ 14 ] ) {
unsigned long * V_69 ;
V_69 = ( unsigned long * ) ( V_68 [ 14 ] + V_19 ) ;
if ( ( ( unsigned long ) V_69 & ( sizeof( long ) - 1 ) ) == 0UL )
V_61 = V_69 [ 15 ] ;
}
}
return V_61 ;
}
void F_47 ( void )
{
struct V_26 * V_70 = F_30 () ;
if ( V_70 -> V_71 ) {
if ( V_70 -> V_71 [ 0 ] < 2 )
F_48 ( V_70 -> V_71 ) ;
else
V_70 -> V_71 [ 0 ] -- ;
}
}
void F_49 ( void )
{
struct V_26 * V_70 = F_30 () ;
struct V_72 * V_73 ;
V_73 = V_70 -> V_45 -> V_73 ;
if ( V_73 )
F_50 ( V_73 ) ;
F_51 ( 0 ) ;
V_70 -> V_74 [ 0 ] = 0 ;
}
static unsigned long F_52 ( unsigned long V_75 , unsigned long V_76 )
{
bool V_77 = F_53 ( V_76 ) ;
unsigned long V_69 , V_78 , V_79 ;
if ( V_77 ) {
V_75 += V_19 ;
V_76 += V_19 ;
F_54 ( V_69 , & ( ( (struct V_14 T_1 * ) V_76 ) -> V_13 [ 6 ] ) ) ;
V_69 += V_19 ;
if ( F_18 ( V_18 ) )
V_69 &= 0xffffffff ;
} else
F_54 ( V_69 , & ( ( (struct V_6 T_1 * ) V_76 ) -> V_13 [ 6 ] ) ) ;
V_75 &= ~ 15UL ;
V_78 = V_69 - V_76 ;
V_79 = ( V_75 - V_78 ) ;
if ( F_55 ( ( void T_1 * ) V_79 , ( void T_1 * ) V_76 , V_78 ) )
V_79 = 0 ;
else if ( ! V_77 ) {
if ( F_56 ( ( ( V_80 ) V_75 ) ,
& ( ( (struct V_6 T_1 * ) V_79 ) -> V_13 [ 6 ] ) ) )
V_79 = 0 ;
} else {
if ( F_56 ( ( ( V_81 ) V_75 - V_19 ) ,
& ( ( (struct V_14 T_1 * ) V_79 ) -> V_13 [ 6 ] ) ) )
V_79 = 0 ;
else
V_79 = V_79 - V_19 ;
}
return V_79 ;
}
static inline void F_57 ( int V_82 , int V_83 ,
struct V_26 * V_70 )
{
int V_51 ;
for ( V_51 = V_82 ; V_51 < V_83 ; V_51 ++ ) {
V_70 -> V_84 [ V_51 ] = V_70 -> V_84 [ V_51 + 1 ] ;
memcpy ( & V_70 -> V_14 [ V_51 ] , & V_70 -> V_14 [ V_51 + 1 ] ,
sizeof( struct V_14 ) ) ;
}
}
void F_58 ( void )
{
struct V_26 * V_70 = F_30 () ;
unsigned long V_85 ;
F_59 () ;
if ( ( V_85 = F_60 () ) != 0 ) {
V_85 -= 1 ;
do {
struct V_14 * V_86 = & V_70 -> V_14 [ V_85 ] ;
int V_87 = sizeof( struct V_14 ) ;
unsigned long V_68 ;
V_68 = V_70 -> V_84 [ V_85 ] ;
if ( F_53 ( V_68 ) )
V_68 += V_19 ;
else
V_87 = sizeof( struct V_6 ) ;
if ( ! F_61 ( ( char T_1 * ) V_68 , V_86 , V_87 ) ) {
F_57 ( V_85 , F_60 () - 1 , V_70 ) ;
F_51 ( F_60 () - 1 ) ;
}
} while ( V_85 -- );
}
}
static void F_62 ( unsigned long V_68 )
{
T_4 V_88 ;
V_88 . V_89 = V_90 ;
V_88 . V_91 = 0 ;
V_88 . V_92 = V_93 ;
V_88 . V_94 = ( void T_1 * ) V_68 ;
V_88 . V_95 = 0 ;
F_63 ( V_90 , & V_88 , V_24 ) ;
}
void F_64 ( void )
{
struct V_26 * V_70 = F_30 () ;
unsigned long V_85 ;
F_59 () ;
V_85 = F_60 () ;
if ( F_65 ( V_85 != 0 ) ) {
V_85 -= 1 ;
do {
struct V_14 * V_86 = & V_70 -> V_14 [ V_85 ] ;
int V_87 = sizeof( struct V_14 ) ;
unsigned long V_68 ;
V_68 = V_70 -> V_84 [ V_85 ] ;
if ( F_53 ( V_68 ) )
V_68 += V_19 ;
else
V_87 = sizeof( struct V_6 ) ;
if ( F_66 ( V_68 & 0x7UL ) )
F_62 ( V_68 ) ;
if ( F_66 ( F_61 ( ( char T_1 * ) V_68 ,
V_86 , V_87 ) ) )
goto V_96;
} while ( V_85 -- );
}
F_51 ( 0 ) ;
return;
V_96:
F_51 ( V_85 + 1 ) ;
F_67 () ;
F_68 ( V_97 ) ;
}
T_5 long F_69 ( unsigned long V_98 ,
unsigned long V_99 ,
struct V_4 * V_5 ,
unsigned long V_100 )
{
int T_1 * V_101 , * V_102 ;
unsigned long V_103 = V_5 -> V_10 [ V_104 ] ;
long V_61 ;
#ifdef F_70
if ( F_18 ( V_18 ) ) {
V_101 = F_12 ( V_5 -> V_10 [ V_105 ] ) ;
V_102 = F_12 ( V_5 -> V_10 [ V_106 ] ) ;
} else
#endif
{
V_101 = ( int T_1 * ) V_5 -> V_10 [ V_105 ] ;
V_102 = ( int T_1 * ) V_5 -> V_10 [ V_106 ] ;
}
V_61 = F_71 ( V_98 , V_99 , V_100 ,
V_101 , V_102 ) ;
if ( ( unsigned long ) V_61 >= - V_107 )
V_5 -> V_10 [ V_104 ] = V_103 ;
return V_61 ;
}
int F_72 ( unsigned long V_98 , unsigned long V_68 ,
unsigned long V_108 , struct V_64 * V_109 )
{
struct V_26 * V_70 = F_46 ( V_109 ) ;
struct V_4 * V_5 = F_73 () ;
struct V_110 * V_111 ;
unsigned long V_112 ;
char * V_113 ;
V_112 = ( V_114 + V_115 ) ;
V_113 = ( F_74 ( V_109 ) +
( V_116 - V_112 ) ) ;
V_70 -> V_117 = 1 ;
V_70 -> V_67 = ( ( unsigned long ) V_113 ) - V_19 ;
V_70 -> V_43 = (struct V_4 * ) ( V_113 +
sizeof( struct V_110 ) ) ;
V_70 -> V_74 [ 0 ] = 0 ;
if ( F_66 ( V_109 -> V_41 & V_118 ) ) {
memset ( V_113 , 0 , V_112 ) ;
F_75 ( V_70 ) [ V_119 ] =
( F_73 () -> V_16 + 1 ) & V_120 ;
V_70 -> V_121 = V_122 ;
V_70 -> V_43 -> V_10 [ V_123 ] = V_68 ;
V_70 -> V_43 -> V_10 [ V_124 ] = V_108 ;
return 0 ;
}
V_111 = ( (struct V_110 * ) V_5 ) - 1 ;
memcpy ( V_113 , V_111 , V_112 ) ;
if ( V_70 -> V_41 & V_125 ) {
V_68 &= 0x00000000ffffffffUL ;
V_5 -> V_10 [ V_25 ] &= 0x00000000ffffffffUL ;
}
V_70 -> V_43 -> V_10 [ V_25 ] = V_68 ;
F_75 ( V_70 ) [ V_119 ] =
( V_5 -> V_16 + 1 ) & V_120 ;
V_70 -> V_121 = V_126 ;
if ( V_68 != V_5 -> V_10 [ V_25 ] ) {
unsigned long V_75 ;
V_75 = F_52 ( V_68 , V_5 -> V_10 [ V_25 ] ) ;
if ( ! V_75 )
return - V_127 ;
V_70 -> V_43 -> V_10 [ V_25 ] = V_75 ;
}
if ( V_70 -> V_71 )
V_70 -> V_71 [ 0 ] ++ ;
V_70 -> V_43 -> V_10 [ V_128 ] = V_24 -> V_47 ;
V_70 -> V_43 -> V_10 [ V_104 ] = 1 ;
V_5 -> V_10 [ V_104 ] = 0 ;
if ( V_98 & V_129 )
V_70 -> V_43 -> V_10 [ V_130 ] = V_5 -> V_10 [ V_131 ] ;
return 0 ;
}
int F_76 ( struct V_4 * V_5 , T_6 * V_132 )
{
unsigned long * V_133 = F_30 () -> V_132 ;
unsigned long V_134 = F_30 () -> V_74 [ 0 ] ;
if ( F_18 ( V_18 ) ) {
T_7 * V_135 = ( T_7 * ) V_132 ;
if ( V_134 & V_136 )
memcpy ( & V_135 -> V_137 . V_138 [ 0 ] , V_133 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_135 -> V_137 . V_138 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
V_135 -> V_139 = 0 ;
V_135 -> V_140 = 8 ;
memset ( & V_135 -> V_141 [ 0 ] , 0 ,
(sizeof( unsigned int ) * 64 ) ) ;
if ( V_134 & V_142 ) {
V_135 -> V_143 = ( unsigned int ) F_30 () -> V_144 [ 0 ] ;
V_135 -> V_145 = 1 ;
} else {
V_135 -> V_143 = 0 ;
V_135 -> V_145 = 0 ;
}
} else {
if( V_134 & V_136 )
memcpy ( & V_132 -> V_138 [ 0 ] , V_133 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_132 -> V_138 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_134 & V_146 )
memcpy ( & V_132 -> V_138 [ 16 ] , V_133 + 16 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_132 -> V_138 [ 16 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_134 & V_142 ) {
V_132 -> V_143 = F_30 () -> V_144 [ 0 ] ;
V_132 -> V_147 = F_30 () -> V_148 [ 0 ] ;
} else {
V_132 -> V_143 = V_132 -> V_147 = 0 ;
}
V_132 -> V_149 = V_134 ;
}
return 1 ;
}
unsigned long F_77 ( struct V_64 * V_45 )
{
unsigned long V_150 , V_69 , V_151 = 0 ;
struct V_26 * V_27 ;
struct V_14 * V_7 ;
unsigned long V_61 = 0 ;
int V_152 = 0 ;
if ( ! V_45 || V_45 == V_24 ||
V_45 -> V_153 == V_154 )
goto V_155;
V_27 = F_46 ( V_45 ) ;
V_151 = V_19 ;
V_69 = F_46 ( V_45 ) -> V_67 + V_151 ;
do {
if ( ! F_25 ( V_27 , V_69 ) )
break;
V_7 = (struct V_14 * ) V_69 ;
V_150 = V_7 -> V_13 [ 7 ] ;
if ( ! F_78 ( V_150 ) ) {
V_61 = V_150 ;
goto V_155;
}
V_69 = V_7 -> V_13 [ 6 ] + V_151 ;
} while ( ++ V_152 < 16 );
V_155:
return V_61 ;
}
