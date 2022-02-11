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
unsigned long F_48 ( struct V_65 * V_66 )
{
struct V_26 * V_67 = F_49 ( V_66 ) ;
unsigned long V_62 = 0xdeadbeefUL ;
if ( V_67 && V_67 -> V_68 ) {
unsigned long * V_69 ;
V_69 = ( unsigned long * ) ( V_67 -> V_68 + V_19 ) ;
if ( ( ( unsigned long ) V_69 & ( sizeof( long ) - 1 ) ) == 0UL &&
V_69 [ 14 ] ) {
unsigned long * V_70 ;
V_70 = ( unsigned long * ) ( V_69 [ 14 ] + V_19 ) ;
if ( ( ( unsigned long ) V_70 & ( sizeof( long ) - 1 ) ) == 0UL )
V_62 = V_70 [ 15 ] ;
}
}
return V_62 ;
}
void F_50 ( struct V_65 * V_66 )
{
struct V_26 * V_71 = F_49 ( V_66 ) ;
if ( V_71 -> V_72 ) {
if ( V_71 -> V_72 [ 0 ] < 2 )
F_51 ( V_71 -> V_72 ) ;
else
V_71 -> V_72 [ 0 ] -- ;
}
}
void F_52 ( void )
{
struct V_26 * V_71 = F_30 () ;
struct V_73 * V_74 ;
V_74 = V_71 -> V_46 -> V_74 ;
if ( V_74 )
F_53 ( V_74 ) ;
F_54 ( 0 ) ;
V_71 -> V_75 [ 0 ] = 0 ;
}
static unsigned long F_55 ( unsigned long V_76 , unsigned long V_77 )
{
bool V_78 = F_56 ( V_77 ) ;
unsigned long V_70 , V_79 , V_80 ;
if ( V_78 ) {
V_76 += V_19 ;
V_77 += V_19 ;
F_57 ( V_70 , & ( ( (struct V_14 T_1 * ) V_77 ) -> V_13 [ 6 ] ) ) ;
V_70 += V_19 ;
if ( F_18 ( V_18 ) )
V_70 &= 0xffffffff ;
} else
F_57 ( V_70 , & ( ( (struct V_6 T_1 * ) V_77 ) -> V_13 [ 6 ] ) ) ;
V_76 &= ~ 15UL ;
V_79 = V_70 - V_77 ;
V_80 = ( V_76 - V_79 ) ;
if ( F_58 ( ( void T_1 * ) V_80 , ( void T_1 * ) V_77 , V_79 ) )
V_80 = 0 ;
else if ( ! V_78 ) {
if ( F_59 ( ( ( V_81 ) V_76 ) ,
& ( ( (struct V_6 T_1 * ) V_80 ) -> V_13 [ 6 ] ) ) )
V_80 = 0 ;
} else {
if ( F_59 ( ( ( V_82 ) V_76 - V_19 ) ,
& ( ( (struct V_14 T_1 * ) V_80 ) -> V_13 [ 6 ] ) ) )
V_80 = 0 ;
else
V_80 = V_80 - V_19 ;
}
return V_80 ;
}
static inline void F_60 ( int V_83 , int V_84 ,
struct V_26 * V_71 )
{
int V_52 ;
for ( V_52 = V_83 ; V_52 < V_84 ; V_52 ++ ) {
V_71 -> V_85 [ V_52 ] = V_71 -> V_85 [ V_52 + 1 ] ;
memcpy ( & V_71 -> V_14 [ V_52 ] , & V_71 -> V_14 [ V_52 + 1 ] ,
sizeof( struct V_14 ) ) ;
}
}
void F_61 ( void )
{
struct V_26 * V_71 = F_30 () ;
unsigned long V_86 ;
F_62 () ;
if ( ( V_86 = F_63 () ) != 0 ) {
V_86 -= 1 ;
do {
struct V_14 * V_87 = & V_71 -> V_14 [ V_86 ] ;
int V_88 = sizeof( struct V_14 ) ;
unsigned long V_69 ;
V_69 = V_71 -> V_85 [ V_86 ] ;
if ( F_56 ( V_69 ) )
V_69 += V_19 ;
else
V_88 = sizeof( struct V_6 ) ;
if ( ! F_64 ( ( char T_1 * ) V_69 , V_87 , V_88 ) ) {
F_60 ( V_86 , F_63 () - 1 , V_71 ) ;
F_54 ( F_63 () - 1 ) ;
}
} while ( V_86 -- );
}
}
static void F_65 ( unsigned long V_69 )
{
T_5 V_89 ;
V_89 . V_90 = V_91 ;
V_89 . V_92 = 0 ;
V_89 . V_93 = V_94 ;
V_89 . V_95 = ( void T_1 * ) V_69 ;
V_89 . V_96 = 0 ;
F_66 ( V_91 , & V_89 , V_24 ) ;
}
void F_67 ( void )
{
struct V_26 * V_71 = F_30 () ;
unsigned long V_86 ;
F_62 () ;
V_86 = F_63 () ;
if ( F_68 ( V_86 != 0 ) ) {
V_86 -= 1 ;
do {
struct V_14 * V_87 = & V_71 -> V_14 [ V_86 ] ;
int V_88 = sizeof( struct V_14 ) ;
unsigned long V_69 ;
V_69 = V_71 -> V_85 [ V_86 ] ;
if ( F_56 ( V_69 ) )
V_69 += V_19 ;
else
V_88 = sizeof( struct V_6 ) ;
if ( F_69 ( V_69 & 0x7UL ) )
F_65 ( V_69 ) ;
if ( F_69 ( F_64 ( ( char T_1 * ) V_69 ,
V_87 , V_88 ) ) )
goto V_97;
} while ( V_86 -- );
}
F_54 ( 0 ) ;
return;
V_97:
F_54 ( V_86 + 1 ) ;
F_70 () ;
F_71 ( V_98 ) ;
}
T_6 long F_72 ( unsigned long V_99 ,
unsigned long V_100 ,
struct V_4 * V_5 ,
unsigned long V_101 )
{
int T_1 * V_102 , * V_103 ;
unsigned long V_104 = V_5 -> V_10 [ V_105 ] ;
long V_62 ;
#ifdef F_73
if ( F_18 ( V_18 ) ) {
V_102 = F_12 ( V_5 -> V_10 [ V_106 ] ) ;
V_103 = F_12 ( V_5 -> V_10 [ V_107 ] ) ;
} else
#endif
{
V_102 = ( int T_1 * ) V_5 -> V_10 [ V_106 ] ;
V_103 = ( int T_1 * ) V_5 -> V_10 [ V_107 ] ;
}
V_62 = F_74 ( V_99 , V_100 , V_101 ,
V_102 , V_103 ) ;
if ( ( unsigned long ) V_62 >= - V_108 )
V_5 -> V_10 [ V_105 ] = V_104 ;
return V_62 ;
}
int F_75 ( unsigned long V_99 , unsigned long V_69 ,
unsigned long V_109 , struct V_65 * V_110 )
{
struct V_26 * V_71 = F_49 ( V_110 ) ;
struct V_4 * V_5 = F_76 () ;
struct V_111 * V_112 ;
unsigned long V_113 ;
char * V_114 ;
V_113 = ( V_115 + V_116 ) ;
V_114 = ( F_77 ( V_110 ) +
( V_117 - V_113 ) ) ;
V_71 -> V_118 = 1 ;
V_71 -> V_68 = ( ( unsigned long ) V_114 ) - V_19 ;
V_71 -> V_44 = (struct V_4 * ) ( V_114 +
sizeof( struct V_111 ) ) ;
V_71 -> V_75 [ 0 ] = 0 ;
if ( F_69 ( V_110 -> V_42 & V_119 ) ) {
memset ( V_114 , 0 , V_113 ) ;
F_78 ( V_71 ) [ V_120 ] =
( F_76 () -> V_16 + 1 ) & V_121 ;
V_71 -> V_122 = V_123 ;
V_71 -> V_44 -> V_10 [ V_124 ] = V_69 ;
V_71 -> V_44 -> V_10 [ V_125 ] = V_109 ;
return 0 ;
}
V_112 = ( (struct V_111 * ) V_5 ) - 1 ;
memcpy ( V_114 , V_112 , V_113 ) ;
if ( V_71 -> V_42 & V_126 ) {
V_69 &= 0x00000000ffffffffUL ;
V_5 -> V_10 [ V_25 ] &= 0x00000000ffffffffUL ;
}
V_71 -> V_44 -> V_10 [ V_25 ] = V_69 ;
F_78 ( V_71 ) [ V_120 ] =
( V_5 -> V_16 + 1 ) & V_121 ;
V_71 -> V_122 = V_127 ;
if ( V_69 != V_5 -> V_10 [ V_25 ] ) {
unsigned long V_76 ;
V_76 = F_55 ( V_69 , V_5 -> V_10 [ V_25 ] ) ;
if ( ! V_76 )
return - V_128 ;
V_71 -> V_44 -> V_10 [ V_25 ] = V_76 ;
}
if ( V_71 -> V_72 )
V_71 -> V_72 [ 0 ] ++ ;
V_71 -> V_44 -> V_10 [ V_129 ] = V_24 -> V_48 ;
V_71 -> V_44 -> V_10 [ V_105 ] = 1 ;
V_5 -> V_10 [ V_105 ] = 0 ;
if ( V_99 & V_130 )
V_71 -> V_44 -> V_10 [ V_131 ] = V_5 -> V_10 [ V_132 ] ;
return 0 ;
}
int F_79 ( struct V_4 * V_5 , T_7 * V_133 )
{
unsigned long * V_134 = F_30 () -> V_133 ;
unsigned long V_135 = F_30 () -> V_75 [ 0 ] ;
if ( F_18 ( V_18 ) ) {
T_8 * V_136 = ( T_8 * ) V_133 ;
if ( V_135 & V_137 )
memcpy ( & V_136 -> V_138 . V_139 [ 0 ] , V_134 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_136 -> V_138 . V_139 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
V_136 -> V_140 = 0 ;
V_136 -> V_141 = 8 ;
memset ( & V_136 -> V_142 [ 0 ] , 0 ,
(sizeof( unsigned int ) * 64 ) ) ;
if ( V_135 & V_143 ) {
V_136 -> V_144 = ( unsigned int ) F_30 () -> V_145 [ 0 ] ;
V_136 -> V_146 = 1 ;
} else {
V_136 -> V_144 = 0 ;
V_136 -> V_146 = 0 ;
}
} else {
if( V_135 & V_137 )
memcpy ( & V_133 -> V_139 [ 0 ] , V_134 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_133 -> V_139 [ 0 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_135 & V_147 )
memcpy ( & V_133 -> V_139 [ 16 ] , V_134 + 16 ,
sizeof( unsigned int ) * 32 ) ;
else
memset ( & V_133 -> V_139 [ 16 ] , 0 ,
sizeof( unsigned int ) * 32 ) ;
if( V_135 & V_143 ) {
V_133 -> V_144 = F_30 () -> V_145 [ 0 ] ;
V_133 -> V_148 = F_30 () -> V_149 [ 0 ] ;
} else {
V_133 -> V_144 = V_133 -> V_148 = 0 ;
}
V_133 -> V_150 = V_135 ;
}
return 1 ;
}
unsigned long F_80 ( struct V_65 * V_46 )
{
unsigned long V_151 , V_70 , V_152 = 0 ;
struct V_26 * V_27 ;
struct V_14 * V_7 ;
unsigned long V_62 = 0 ;
int V_153 = 0 ;
if ( ! V_46 || V_46 == V_24 ||
V_46 -> V_154 == V_155 )
goto V_156;
V_27 = F_49 ( V_46 ) ;
V_152 = V_19 ;
V_70 = F_49 ( V_46 ) -> V_68 + V_152 ;
do {
if ( ! F_25 ( V_27 , V_70 ) )
break;
V_7 = (struct V_14 * ) V_70 ;
V_151 = V_7 -> V_13 [ 7 ] ;
if ( ! F_81 ( V_151 ) ) {
V_62 = V_151 ;
goto V_156;
}
V_70 = V_7 -> V_13 [ 6 ] + V_152 ;
} while ( ++ V_153 < 16 );
V_156:
return V_62 ;
}
