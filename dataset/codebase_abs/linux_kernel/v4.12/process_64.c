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
V_7 = F_12 ( ( unsigned int ) V_5 -> V_10 [ 14 ] ) ;
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
void F_29 ( const T_3 * V_40 , bool V_41 )
{
struct V_26 * V_27 = F_30 () ;
struct V_4 * V_5 = F_31 () ;
unsigned long V_42 ;
int V_28 , V_43 ;
if ( ! V_5 )
V_5 = V_27 -> V_44 ;
F_32 ( & V_45 , V_42 ) ;
V_28 = F_33 () ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
if ( F_34 ( V_28 , V_40 ) && ! V_41 )
F_23 ( V_27 , V_5 , V_28 ) ;
F_35 () ;
F_36 (cpu, mask) {
struct V_29 * V_38 ;
if ( V_41 && V_43 == V_28 )
continue;
V_38 = & V_31 [ V_43 ] . V_32 ;
F_26 ( V_38 ) ;
V_27 = V_38 -> V_37 ;
F_16 ( L_17 ,
( V_43 == V_28 ? '*' : ' ' ) , V_43 ,
V_38 -> V_16 , V_38 -> V_21 , V_38 -> V_22 ,
( ( V_27 && V_27 -> V_46 ) ? V_27 -> V_46 -> V_47 : L_18 ) ,
( ( V_27 && V_27 -> V_46 ) ? V_27 -> V_46 -> V_48 : - 1 ) ) ;
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
F_2 () ;
}
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_37 ( & V_45 , V_42 ) ;
}
static void F_38 ( int V_49 )
{
F_39 () ;
}
static void F_40 ( int V_28 )
{
struct V_50 * V_51 ;
int V_52 , V_53 ;
if ( ! V_54 )
return;
V_51 = & V_31 [ V_28 ] . V_55 ;
V_53 = 1 ;
if ( V_1 == V_2 &&
V_56 >= V_57 )
V_53 = 4 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_51 -> V_58 [ V_52 ] = V_54 -> V_59 ( V_52 ) ;
V_51 -> V_60 [ V_52 ] = V_54 -> V_61 ( V_52 ) ;
}
}
static void F_41 ( struct V_50 * V_51 )
{
int V_39 = 0 ;
while ( ! V_51 -> V_58 [ 0 ] && ++ V_39 < 100 ) {
F_27 () ;
F_28 ( 1 ) ;
}
}
static void F_42 ( void )
{
unsigned long V_42 ;
int V_28 , V_43 ;
F_32 ( & V_45 , V_42 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_28 = F_33 () ;
F_40 ( V_28 ) ;
F_43 () ;
F_44 (cpu) {
struct V_50 * V_51 = & V_31 [ V_43 ] . V_55 ;
F_41 ( V_51 ) ;
F_16 ( L_21 ,
( V_43 == V_28 ? '*' : ' ' ) , V_43 ,
V_51 -> V_58 [ 0 ] , V_51 -> V_58 [ 1 ] , V_51 -> V_58 [ 2 ] , V_51 -> V_58 [ 3 ] ,
V_51 -> V_60 [ 0 ] , V_51 -> V_60 [ 1 ] , V_51 -> V_60 [ 2 ] , V_51 -> V_60 [ 3 ] ) ;
F_2 () ;
}
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_37 ( & V_45 , V_42 ) ;
}
static void F_45 ( int V_49 )
{
F_42 () ;
}
static int T_4 F_46 ( void )
{
int V_62 = F_47 ( 'y' , & V_63 ) ;
if ( ! V_62 )
V_62 = F_47 ( 'x' , & V_64 ) ;
return V_62 ;
}
void F_48 ( struct V_65 * V_66 )
{
struct V_26 * V_67 = F_49 ( V_66 ) ;
if ( V_67 -> V_68 ) {
if ( V_67 -> V_68 [ 0 ] < 2 )
F_50 ( V_67 -> V_68 ) ;
else
V_67 -> V_68 [ 0 ] -- ;
}
}
void F_51 ( void )
{
struct V_26 * V_67 = F_30 () ;
struct V_69 * V_70 ;
V_70 = V_67 -> V_46 -> V_70 ;
if ( V_70 )
F_52 ( V_70 ) ;
F_53 ( 0 ) ;
V_67 -> V_71 [ 0 ] = 0 ;
}
static unsigned long F_54 ( unsigned long V_72 , unsigned long V_73 )
{
bool V_74 = F_55 ( V_73 ) ;
unsigned long V_75 , V_76 , V_77 ;
if ( V_74 ) {
V_72 += V_19 ;
V_73 += V_19 ;
F_56 ( V_75 , & ( ( (struct V_14 T_1 * ) V_73 ) -> V_13 [ 6 ] ) ) ;
V_75 += V_19 ;
if ( F_18 ( V_18 ) )
V_75 &= 0xffffffff ;
} else
F_56 ( V_75 , & ( ( (struct V_6 T_1 * ) V_73 ) -> V_13 [ 6 ] ) ) ;
V_72 &= ~ 15UL ;
V_76 = V_75 - V_73 ;
V_77 = ( V_72 - V_76 ) ;
if ( F_57 ( ( void T_1 * ) V_77 , ( void T_1 * ) V_73 , V_76 ) )
V_77 = 0 ;
else if ( ! V_74 ) {
if ( F_58 ( ( ( V_78 ) V_72 ) ,
& ( ( (struct V_6 T_1 * ) V_77 ) -> V_13 [ 6 ] ) ) )
V_77 = 0 ;
} else {
if ( F_58 ( ( ( V_79 ) V_72 - V_19 ) ,
& ( ( (struct V_14 T_1 * ) V_77 ) -> V_13 [ 6 ] ) ) )
V_77 = 0 ;
else
V_77 = V_77 - V_19 ;
}
return V_77 ;
}
static inline void F_59 ( int V_80 , int V_81 ,
struct V_26 * V_67 )
{
int V_52 ;
for ( V_52 = V_80 ; V_52 < V_81 ; V_52 ++ ) {
V_67 -> V_82 [ V_52 ] = V_67 -> V_82 [ V_52 + 1 ] ;
memcpy ( & V_67 -> V_14 [ V_52 ] , & V_67 -> V_14 [ V_52 + 1 ] ,
sizeof( struct V_14 ) ) ;
}
}
void F_60 ( void )
{
struct V_26 * V_67 = F_30 () ;
unsigned long V_83 ;
F_61 () ;
if ( ( V_83 = F_62 () ) != 0 ) {
V_83 -= 1 ;
do {
struct V_14 * V_84 = & V_67 -> V_14 [ V_83 ] ;
int V_85 = sizeof( struct V_14 ) ;
unsigned long V_86 ;
V_86 = V_67 -> V_82 [ V_83 ] ;
if ( F_55 ( V_86 ) )
V_86 += V_19 ;
else
V_85 = sizeof( struct V_6 ) ;
if ( ! F_63 ( ( char T_1 * ) V_86 , V_84 , V_85 ) ) {
F_59 ( V_83 , F_62 () - 1 , V_67 ) ;
F_53 ( F_62 () - 1 ) ;
}
} while ( V_83 -- );
}
}
static void F_64 ( unsigned long V_86 )
{
T_5 V_87 ;
V_87 . V_88 = V_89 ;
V_87 . V_90 = 0 ;
V_87 . V_91 = V_92 ;
V_87 . V_93 = ( void T_1 * ) V_86 ;
V_87 . V_94 = 0 ;
F_65 ( V_89 , & V_87 , V_24 ) ;
}
void F_66 ( void )
{
struct V_26 * V_67 = F_30 () ;
unsigned long V_83 ;
F_61 () ;
V_83 = F_62 () ;
if ( F_67 ( V_83 != 0 ) ) {
V_83 -= 1 ;
do {
struct V_14 * V_84 = & V_67 -> V_14 [ V_83 ] ;
int V_85 = sizeof( struct V_14 ) ;
unsigned long V_86 ;
V_86 = V_67 -> V_82 [ V_83 ] ;
if ( F_55 ( V_86 ) )
V_86 += V_19 ;
else
V_85 = sizeof( struct V_6 ) ;
if ( F_68 ( V_86 & 0x7UL ) )
F_64 ( V_86 ) ;
if ( F_68 ( F_63 ( ( char T_1 * ) V_86 ,
V_84 , V_85 ) ) )
goto V_95;
} while ( V_83 -- );
}
F_53 ( 0 ) ;
return;
V_95:
F_53 ( V_83 + 1 ) ;
F_69 () ;
F_70 ( V_96 ) ;
}
T_6 long F_71 ( unsigned long V_97 ,
unsigned long V_98 ,
struct V_4 * V_5 ,
unsigned long V_99 )
{
int T_1 * V_100 , * V_101 ;
unsigned long V_102 = V_5 -> V_10 [ V_103 ] ;
long V_62 ;
#ifdef F_72
if ( F_18 ( V_18 ) ) {
V_100 = F_12 ( V_5 -> V_10 [ V_104 ] ) ;
V_101 = F_12 ( V_5 -> V_10 [ V_105 ] ) ;
} else
#endif
{
V_100 = ( int T_1 * ) V_5 -> V_10 [ V_104 ] ;
V_101 = ( int T_1 * ) V_5 -> V_10 [ V_105 ] ;
}
V_62 = F_73 ( V_97 , V_98 , V_99 ,
V_100 , V_101 ) ;
if ( ( unsigned long ) V_62 >= - V_106 )
V_5 -> V_10 [ V_103 ] = V_102 ;
return V_62 ;
}
int F_74 ( unsigned long V_97 , unsigned long V_86 ,
unsigned long V_107 , struct V_65 * V_108 )
{
struct V_26 * V_67 = F_49 ( V_108 ) ;
struct V_4 * V_5 = F_75 () ;
struct V_109 * V_110 ;
unsigned long V_111 ;
char * V_112 ;
V_111 = ( V_113 + V_114 ) ;
V_112 = ( F_76 ( V_108 ) +
( V_115 - V_111 ) ) ;
V_67 -> V_116 = 1 ;
V_67 -> V_117 = ( ( unsigned long ) V_112 ) - V_19 ;
V_67 -> V_44 = (struct V_4 * ) ( V_112 +
sizeof( struct V_109 ) ) ;
V_67 -> V_71 [ 0 ] = 0 ;
if ( F_68 ( V_108 -> V_42 & V_118 ) ) {
memset ( V_112 , 0 , V_111 ) ;
F_77 ( V_67 ) [ V_119 ] =
( F_75 () -> V_16 + 1 ) & V_120 ;
V_67 -> V_121 = V_122 ;
V_67 -> V_44 -> V_10 [ V_123 ] = V_86 ;
V_67 -> V_44 -> V_10 [ V_124 ] = V_107 ;
return 0 ;
}
V_110 = ( (struct V_109 * ) V_5 ) - 1 ;
memcpy ( V_112 , V_110 , V_111 ) ;
if ( V_67 -> V_42 & V_125 ) {
V_86 &= 0x00000000ffffffffUL ;
V_5 -> V_10 [ V_25 ] &= 0x00000000ffffffffUL ;
}
V_67 -> V_44 -> V_10 [ V_25 ] = V_86 ;
F_77 ( V_67 ) [ V_119 ] =
( V_5 -> V_16 + 1 ) & V_120 ;
V_67 -> V_121 = V_126 ;
if ( V_86 != V_5 -> V_10 [ V_25 ] ) {
unsigned long V_72 ;
V_72 = F_54 ( V_86 , V_5 -> V_10 [ V_25 ] ) ;
if ( ! V_72 )
return - V_127 ;
V_67 -> V_44 -> V_10 [ V_25 ] = V_72 ;
}
if ( V_67 -> V_68 )
V_67 -> V_68 [ 0 ] ++ ;
V_67 -> V_44 -> V_10 [ V_128 ] = V_24 -> V_48 ;
V_67 -> V_44 -> V_10 [ V_103 ] = 1 ;
V_5 -> V_10 [ V_103 ] = 0 ;
if ( V_97 & V_129 )
V_67 -> V_44 -> V_10 [ V_130 ] = V_5 -> V_10 [ V_131 ] ;
return 0 ;
}
int F_78 ( struct V_4 * V_5 , T_7 * V_132 )
{
unsigned long * V_133 = F_30 () -> V_132 ;
unsigned long V_134 = F_30 () -> V_71 [ 0 ] ;
if ( F_18 ( V_18 ) ) {
T_8 * V_135 = ( T_8 * ) V_132 ;
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
unsigned long F_79 ( struct V_65 * V_46 )
{
unsigned long V_150 , V_75 , V_151 = 0 ;
struct V_26 * V_27 ;
struct V_14 * V_7 ;
unsigned long V_62 = 0 ;
int V_152 = 0 ;
if ( ! V_46 || V_46 == V_24 ||
V_46 -> V_153 == V_154 )
goto V_155;
V_27 = F_49 ( V_46 ) ;
V_151 = V_19 ;
V_75 = F_49 ( V_46 ) -> V_117 + V_151 ;
do {
if ( ! F_25 ( V_27 , V_75 ) )
break;
V_7 = (struct V_14 * ) V_75 ;
V_150 = V_7 -> V_13 [ 7 ] ;
if ( ! F_80 ( V_150 ) ) {
V_62 = V_150 ;
goto V_155;
}
V_75 = V_7 -> V_13 [ 6 ] + V_151 ;
} while ( ++ V_152 < 16 );
V_155:
return V_62 ;
}
