static void F_1 ( char * V_1 , ... )
{
int V_2 ;
int V_3 ;
T_1 args ;
static char V_4 [ 256 ] ;
V_3 = sprintf ( V_4 , L_1 , F_2 () ) ;
va_start ( args , V_1 ) ;
V_2 = F_3 ( V_4 + V_3 , sizeof( V_4 ) - V_3 - 1 , V_1 , args ) ;
va_end ( args ) ;
V_4 [ 255 ] = '\0' ;
F_4 ( V_4 ) ;
}
static void F_5 ( unsigned char * V_5 , unsigned long V_6 , char * V_7 )
{
int V_8 = F_2 () ;
unsigned long V_2 ;
char V_4 [ 128 ] ;
static unsigned int V_9 ;
F_6 ( L_2 ,
V_5 , V_6 , V_7 , V_9 ++ ) ;
F_6 ( L_3 ) ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
if ( ( V_2 & 0xf ) == 0 )
sprintf ( V_4 , L_4 , V_8 , V_2 ) ;
sprintf ( V_4 + strlen ( V_4 ) , L_5 , V_5 [ V_2 ] ) ;
if ( ( V_2 & 0xf ) == 0xf || V_2 == V_6 - 1 ) {
strcat ( V_4 , L_3 ) ;
F_6 ( L_6 , V_4 ) ;
}
}
}
inline int F_7 ( T_2 V_10 , T_2 V_11 )
{
long V_12 , V_13 , V_14 ;
asm volatile("swint2"
: "=R00" (result),
"=R01" (clobber_r1), "=R10" (clobber_r10)
: "R10" (fastio_index), "R01" (arg0)
: "memory", "r2", "r3", "r4",
"r5", "r6", "r7", "r8", "r9",
"r11", "r12", "r13", "r14",
"r15", "r16", "r17", "r18", "r19",
"r20", "r21", "r22", "r23", "r24",
"r25", "r26", "r27", "r28", "r29");
return V_12 ;
}
static void F_8 ( struct V_15 * V_16 ,
void * V_17 , bool V_18 )
{
struct V_19 * V_20 = & V_16 -> V_20 ;
unsigned int V_21 = ( ( unsigned int ) ( F_9 ( V_17 ) >> 7 ) << 1 ) + V_18 ;
F_10 ( V_20 -> V_22 . V_23 , V_21 ) ;
}
static bool F_11 ( struct V_15 * V_16 ,
bool V_18 )
{
#if V_24 <= 1536
unsigned int V_25 = V_26 + 1536 ;
#else
unsigned int V_25 = V_26 + V_24 + 100 ;
#endif
unsigned int V_3 =
( ( ( V_18 ? V_27 : V_25 ) +
F_12 () - 1 ) & - F_12 () ) ;
unsigned int V_28 = 128 - V_29 ;
unsigned int V_30 ;
struct V_31 * V_32 ;
void * V_17 ;
struct V_31 * * V_33 ;
V_32 = F_13 ( V_3 + V_28 ) ;
if ( V_32 == NULL )
return false ;
V_30 = - ( long ) V_32 -> V_5 & ( 128 - 1 ) ;
F_14 ( V_30 > V_28 ) ;
F_15 ( V_32 , V_30 ) ;
V_17 = V_32 -> V_5 ;
F_14 ( ( ( ( ( long ) V_17 & ~ V_34 ) + V_3 ) & V_34 ) != 0 ) ;
#ifdef F_16
#if F_17 ()
if ( V_35 ) {
T_3 V_36 = * F_18 ( V_37 -> V_38 , ( unsigned long ) V_17 ) ;
if ( F_19 ( V_36 ) != V_39 )
F_20 ( L_7 ,
V_17 , F_19 ( V_36 ) , F_21 ( V_36 ) ) ;
}
#endif
#endif
if ( ! V_35 )
F_22 ( V_17 , V_3 ) ;
F_15 ( V_32 , V_26 ) ;
V_33 = V_17 - sizeof( * V_33 ) ;
* V_33 = V_32 ;
F_23 () ;
F_8 ( V_16 , V_17 , V_18 ) ;
return true ;
}
static void F_24 ( struct V_15 * V_16 )
{
while ( V_16 -> V_40 != 0 ) {
if ( ! F_11 ( V_16 , true ) )
goto V_41;
V_16 -> V_40 -- ;
}
while ( V_16 -> V_42 != 0 ) {
if ( ! F_11 ( V_16 , false ) )
goto V_41;
V_16 -> V_42 -- ;
}
return;
V_41:
F_4 ( L_8 ) ;
}
static unsigned int F_25 ( T_4 * V_43 ,
struct V_31 * V_44 [] ,
unsigned int V_45 ,
unsigned int V_46 )
{
unsigned int V_47 = 0 ;
unsigned int V_48 = V_43 -> V_48 ;
unsigned int V_49 = V_43 -> V_49 ;
while ( V_48 != V_49 && V_47 < V_45 ) {
V_44 [ V_47 ++ ] = V_43 -> V_44 [ V_48 ] ;
F_26 ( V_48 ) ;
}
if ( V_47 < V_46 )
return 0 ;
V_43 -> V_48 = V_48 ;
return V_47 ;
}
static bool F_27 ( struct V_50 * V_51 , bool V_52 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
T_4 * V_43 = V_54 -> V_43 ;
struct V_31 * V_55 [ 64 ] ;
unsigned int V_56 = 64 ;
unsigned int V_2 , V_47 ;
bool V_57 ;
F_29 ( & V_54 -> V_58 ) ;
if ( V_52 )
V_43 -> V_49 = V_43 -> V_59 ;
V_47 = F_25 ( V_43 , V_55 , V_56 , 0 ) ;
V_57 = ( V_43 -> V_48 != V_43 -> V_59 ) ;
F_30 ( & V_54 -> V_58 ) ;
for ( V_2 = 0 ; V_2 < V_47 ; V_2 ++ )
F_31 ( V_55 [ V_2 ] ) ;
return V_57 ;
}
static void F_32 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_60 ) {
F_33 ( & V_16 -> V_61 , V_62 + 1 ) ;
V_16 -> V_60 = true ;
}
}
static void F_34 ( unsigned long V_63 )
{
struct V_15 * V_16 = (struct V_15 * ) V_63 ;
struct V_50 * V_51 = V_16 -> V_64 . V_51 ;
V_16 -> V_60 = false ;
if ( F_27 ( V_51 , false ) )
F_32 ( V_16 ) ;
}
static bool F_35 ( char * V_65 , char * V_66 , unsigned int V_3 )
{
int V_2 ;
unsigned long long V_67 = 0 ;
V_67 |= ( 1ULL << 0x12 ) ;
V_67 |= ( 1ULL << 0x13 ) ;
V_67 |= ( 1ULL << 0x18 ) ;
V_67 |= ( 1ULL << 0x19 ) ;
V_67 |= ( 1ULL << 0x2a ) ;
V_67 |= ( 1ULL << 0x2b ) ;
V_67 |= ( 1ULL << 0x2c ) ;
V_67 |= ( 1ULL << 0x2d ) ;
V_67 |= ( 1ULL << 0x30 ) ;
V_67 |= ( 1ULL << 0x31 ) ;
V_67 |= ( 1ULL << 0x32 ) ;
V_67 |= ( 1ULL << 0x33 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ , V_67 >>= 1 ) {
if ( ( V_67 & 1 ) || ( V_65 [ V_2 ] == V_66 [ V_2 ] ) )
continue;
#ifdef F_36
if ( V_2 < 0x38 && V_2 != 0x2f &&
F_37 () )
F_6 ( L_9 , V_2 ) ;
#endif
return false ;
}
#ifdef F_38
if ( V_65 [ 0x2a ] == V_66 [ 0x2a ] &&
V_65 [ 0x2b ] == V_66 [ 0x2b ] &&
V_65 [ 0x2c ] == V_66 [ 0x2c ] &&
V_65 [ 0x2d ] == V_66 [ 0x2d ] ) {
return false ;
}
#endif
return true ;
}
static void F_39 ( struct V_15 * V_16 , int V_68 )
{
struct V_19 * V_20 = & V_16 -> V_20 ;
T_5 * V_69 = V_20 -> V_70 ;
T_6 * V_71 = & V_20 -> V_22 ;
int V_72 = V_68 + sizeof( V_73 ) ;
int V_74 =
( ( V_72 ==
V_69 -> V_75 . V_76 ) ?
0 : V_72 ) ;
V_73 * V_77 = ( V_73 * ) ( ( unsigned long ) & V_69 [ 1 ] + V_68 ) ;
unsigned int V_21 = V_77 -> V_78 . V_79 ;
void * V_17 = F_40 ( ( V_80 ) ( V_21 >> 1 ) << 7 ) ;
struct V_31 * * V_33 = V_17 - sizeof( * V_33 ) ;
struct V_31 * V_32 = * V_33 ;
F_31 ( V_32 ) ;
V_71 -> V_81 = V_74 ;
}
static void F_41 ( struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
struct V_19 * V_20 = & V_16 -> V_20 ;
T_5 * V_69 = V_20 -> V_70 ;
T_6 * V_71 = & V_20 -> V_22 ;
while ( V_71 -> V_81 !=
V_69 -> V_75 . V_83 ) {
int V_68 = V_71 -> V_81 ;
F_39 ( V_16 , V_68 ) ;
}
}
static bool F_42 ( struct V_15 * V_16 , int V_68 )
{
struct V_50 * V_51 = V_16 -> V_64 . V_51 ;
struct V_19 * V_20 = & V_16 -> V_20 ;
T_5 * V_69 = V_20 -> V_70 ;
T_6 * V_71 = & V_20 -> V_22 ;
struct V_84 * V_85 = & V_16 -> V_85 ;
int V_86 ;
int V_72 = V_68 + sizeof( V_73 ) ;
int V_74 =
( ( V_72 ==
V_69 -> V_75 . V_76 ) ?
0 : V_72 ) ;
V_73 * V_77 = ( V_73 * ) ( ( unsigned long ) & V_69 [ 1 ] + V_68 ) ;
T_7 * V_87 = F_43 ( V_77 ) ;
unsigned long V_3 =
( F_44 ( V_77 ) +
V_26 - V_88 ) ;
unsigned int V_21 = V_77 -> V_78 . V_79 ;
bool V_18 = ( ( V_21 & 1 ) != 0 ) ;
void * V_17 = F_40 ( ( V_80 ) ( V_21 >> 1 ) << 7 ) ;
unsigned char * V_4 = V_17 + V_26 ;
if ( ! V_35 )
F_22 ( V_4 , V_3 ) ;
V_51 -> V_89 = V_62 ;
#ifdef F_45
F_5 ( V_4 , V_3 , L_10 ) ;
#endif
#ifdef F_46
if ( ! F_47 ( V_87 , V_77 ) &&
F_48 ( V_87 , V_77 ) ) {
F_49 ( L_11 , V_3 ) ;
}
if ( ! F_50 ( V_87 , V_77 ) &&
F_51 ( V_87 , V_77 ) ) {
F_5 ( V_4 , V_3 , L_10 ) ;
F_20 ( L_12 ) ;
}
switch ( F_52 ( V_87 , V_77 ) ) {
case V_90 :
if ( V_3 >= 64 ) {
F_5 ( V_4 , V_3 , L_10 ) ;
F_20 ( L_13 ) ;
}
break;
case V_91 :
F_49 ( L_14 , V_3 ) ;
}
#endif
V_86 = 0 ;
if ( ! ( V_51 -> V_92 & V_93 ) ) {
V_86 = 1 ;
} else if ( F_52 ( V_87 , V_77 ) == V_91 ) {
V_86 = 1 ;
} else if ( ! ( V_51 -> V_92 & V_94 ) ) {
if ( ! F_53 ( V_4 ) ) {
const T_8 * V_95 = V_51 -> V_96 ;
V_86 = F_54 ( V_95 , V_4 ) ;
}
}
if ( V_86 ) {
F_8 ( V_16 , V_17 , V_18 ) ;
} else {
struct V_31 * * V_33 = V_17 - sizeof( * V_33 ) ;
struct V_31 * V_32 = * V_33 ;
if ( V_32 -> V_5 != V_4 )
F_20 ( L_15
L_16 ,
V_17 , V_32 , V_32 -> V_5 ) ;
F_55 ( V_32 , V_3 ) ;
V_32 -> V_97 = F_56 ( V_32 , V_51 ) ;
if ( F_47 ( V_87 , V_77 ) )
V_32 -> V_98 = V_99 ;
F_57 ( V_32 ) ;
V_85 -> V_100 ++ ;
V_85 -> V_101 += V_3 ;
if ( V_18 )
V_16 -> V_40 ++ ;
else
V_16 -> V_42 ++ ;
}
if ( -- V_71 -> V_102 == 0 ) {
T_2 V_103 = V_71 -> V_104 ;
V_71 -> V_102 = V_103 ;
F_58 ( V_71 -> V_23 , V_103 ) ;
}
V_71 -> V_81 = V_74 ;
return ! V_86 ;
}
static int F_59 ( struct V_105 * V_64 , int V_106 )
{
struct V_50 * V_51 = V_64 -> V_51 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
struct V_19 * V_20 = & V_16 -> V_20 ;
T_5 * V_69 = V_20 -> V_70 ;
T_6 * V_71 = & V_20 -> V_22 ;
unsigned int V_107 = 0 ;
while ( V_54 -> V_108 ) {
int V_68 = V_71 -> V_81 ;
if ( V_68 == V_69 -> V_75 . V_83 )
break;
if ( F_42 ( V_16 , V_68 ) ) {
if ( ++ V_107 >= V_106 )
goto V_109;
}
}
F_60 ( & V_16 -> V_64 ) ;
if ( ! V_54 -> V_108 )
goto V_109;
F_61 ( V_54 -> V_110 , 0 ) ;
if ( V_71 -> V_81 !=
V_69 -> V_75 . V_83 ) {
( void ) F_62 ( & V_16 -> V_64 ) ;
}
V_109:
if ( V_54 -> V_108 )
F_24 ( V_16 ) ;
return V_107 ;
}
static T_9 F_63 ( int V_111 , void * V_112 )
{
struct V_50 * V_51 = (struct V_50 * ) V_112 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
F_64 ( V_54 -> V_110 ) ;
if ( ! V_54 -> V_108 )
return V_113 ;
F_65 ( & V_16 -> V_64 ) ;
return V_113 ;
}
static int F_66 ( struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_114 ;
int V_115 ;
unsigned int V_116 ;
V_114 = F_67 ( V_54 -> V_117 , 0 ,
( V_118 ) & V_116 , sizeof( V_116 ) ,
V_119 ) ;
if ( V_114 < 0 ) {
F_68 ( L_17 ) ;
return - V_120 ;
}
{
int V_121 = F_69 ( V_116 ) ;
F_70 ( V_54 -> V_122 , V_123 , V_121 ) ;
}
{
T_10 V_124 = {
. V_17 = 0 ,
. V_125 = F_9 ( V_54 -> V_43 ) ,
. V_36 = F_71 ( 0 ) ,
. V_126 = V_127 ,
} ;
V_124 . V_36 = F_72 ( V_124 . V_36 , V_116 ) ;
V_124 . V_36 = F_73 ( V_124 . V_36 , V_128 ) ;
V_114 = F_74 ( V_54 -> V_117 , 0 ,
( V_118 ) & V_124 ,
sizeof( V_124 ) ,
V_119 ) ;
if ( V_114 < 0 )
return - V_120 ;
}
if ( F_74 ( V_54 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_129 ) < 0 ) {
F_49 ( L_18 ) ;
return - V_120 ;
}
return 0 ;
}
static void F_75 ( void * V_112 )
{
struct V_50 * V_51 = (struct V_50 * ) V_112 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_19 * V_20 ;
int V_130 =
F_76 ( V_8 , & V_54 -> V_131 ) ? 0 : 255 ;
T_11 V_132 = {
. V_92 = 0 ,
. V_133 = V_54 -> V_134 ,
. V_130 = V_130
} ;
int V_114 = 0 ;
T_5 * V_135 ;
F_77 ( L_19 , V_130 ) ;
if ( ! strcmp ( V_51 -> V_136 , L_20 ) )
V_16 = & F_78 ( V_137 ) ;
else if ( ! strcmp ( V_51 -> V_136 , L_21 ) )
V_16 = & F_78 ( V_138 ) ;
else if ( ! strcmp ( V_51 -> V_136 , L_22 ) )
V_16 = & F_78 ( V_139 ) ;
else if ( ! strcmp ( V_51 -> V_136 , L_23 ) )
V_16 = & F_78 ( V_140 ) ;
else
F_79 () ;
F_80 ( & V_16 -> V_61 ) ;
V_16 -> V_61 . V_5 = ( long ) V_16 ;
V_16 -> V_61 . V_141 = F_34 ;
V_54 -> V_82 [ V_8 ] = V_16 ;
V_114 = F_74 ( V_54 -> V_117 , 0 ,
( V_118 ) & V_132 ,
sizeof( T_11 ) ,
V_142 ) ;
F_77 ( L_24 ,
V_114 ) ;
if ( V_114 < 0 ) {
if ( V_114 != V_143 ) {
F_81 ( V_144 L_25
L_26 ,
V_114 ) ;
}
V_16 -> V_145 = ( V_114 == V_143 ) ;
return;
}
V_114 = F_67 ( V_54 -> V_117 , 0 ,
( V_118 ) & V_135 ,
sizeof( T_5 * ) ,
V_142 ) ;
F_77 ( L_27 ,
V_114 ) ;
F_77 ( L_28 , V_135 ) ;
if ( V_114 <= 0 ) {
F_68 ( L_29 ) ;
return;
}
V_20 = & V_16 -> V_20 ;
V_20 -> V_70 = V_135 ;
memset ( & V_20 -> V_22 , 0 , sizeof( T_6 ) ) ;
V_20 -> V_22 . V_104 = 4 ;
V_20 -> V_22 . V_102 =
V_20 -> V_22 . V_104 ;
V_114 = F_67 ( V_54 -> V_117 , 0 ,
( V_118 ) & V_20 -> V_22 . V_23 ,
sizeof( V_20 -> V_22 . V_23 ) ,
V_146 ) ;
F_77 ( L_30 , V_114 ) ;
V_16 -> V_147 = true ;
}
static void F_82 ( void * V_112 )
{
struct V_50 * V_51 = (struct V_50 * ) V_112 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
F_64 ( V_54 -> V_110 ) ;
if ( V_16 == NULL || ! V_16 -> V_147 )
return;
{
struct V_19 * V_20 = & V_16 -> V_20 ;
T_6 * V_71 = & V_20 -> V_22 ;
F_58 ( V_71 -> V_23 , - 1 ) ;
}
}
static void F_83 ( void * V_112 )
{
struct V_50 * V_51 = (struct V_50 * ) V_112 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
int V_114 ;
int V_115 = 0 ;
F_64 ( V_54 -> V_110 ) ;
if ( V_16 == NULL || ! V_16 -> V_147 )
return;
V_114 = F_74 ( V_54 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_148 ) ;
if ( V_114 < 0 )
F_20 ( L_31 ) ;
F_41 ( V_51 ) ;
V_16 -> V_40 = 0 ;
V_16 -> V_42 = 0 ;
F_84 ( & V_16 -> V_61 ) ;
V_16 -> V_60 = false ;
}
static void F_85 ( struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_2 ;
int V_115 = 0 ;
F_86 ( F_83 , ( void * ) V_51 , 1 ) ;
F_87 (i) {
struct V_15 * V_16 = V_54 -> V_82 [ V_2 ] ;
if ( V_16 != NULL && V_16 -> V_147 ) {
F_88 ( & V_16 -> V_64 ) ;
V_16 -> V_147 = false ;
}
}
if ( F_74 ( V_54 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_149 ) < 0 )
F_20 ( L_32 ) ;
V_54 -> V_150 = false ;
}
static void F_89 ( void * V_112 )
{
struct V_50 * V_51 = (struct V_50 * ) V_112 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
if ( V_16 != NULL && V_16 -> V_151 ) {
F_90 ( & V_16 -> V_64 ) ;
V_16 -> V_151 = false ;
}
}
static void F_91 ( void * V_112 )
{
struct V_50 * V_51 = (struct V_50 * ) V_112 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
F_92 ( & V_16 -> V_64 ) ;
V_16 -> V_151 = true ;
F_61 ( V_54 -> V_110 , 0 ) ;
}
static int F_93 ( struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_19 * V_20 ;
int V_12 = 0 ;
int V_2 ;
int V_115 = 0 ;
F_75 ( V_51 ) ;
V_16 = V_54 -> V_82 [ V_8 ] ;
if ( ! V_16 -> V_147 ) {
if ( V_16 -> V_145 )
return 1 ;
return - V_152 ;
}
F_94 ( F_75 , ( void * ) V_51 , 1 ) ;
F_87 (i) {
struct V_15 * V_16 = V_54 -> V_82 [ V_2 ] ;
if ( V_16 -> V_147 )
F_95 ( V_51 , & V_16 -> V_64 , F_59 , 64 ) ;
else
V_12 = - V_152 ;
}
if ( V_12 != 0 ) {
F_85 ( V_51 ) ;
return V_12 ;
}
V_20 = & V_16 -> V_20 ;
if ( V_54 -> V_110 == 0 ) {
unsigned int V_111 ;
V_54 -> V_110 = V_20 -> V_70 -> V_153 ;
F_14 ( V_54 -> V_110 == 0 ) ;
V_111 = F_96 ( V_54 -> V_110 ) ;
F_97 ( V_111 , V_154 ) ;
F_14 ( F_98 ( V_111 , F_63 ,
0 , V_51 -> V_136 , ( void * ) V_51 ) != 0 ) ;
}
{
int V_155 =
V_54 -> V_156 * V_54 -> V_134 ;
V_16 -> V_40 =
F_99 ( V_157 , V_155 ) ;
V_16 -> V_42 =
F_99 ( V_158 , V_155 ) ;
F_24 ( V_16 ) ;
if ( V_16 -> V_40 != 0 ||
V_16 -> V_42 != 0 )
F_20 ( L_33 ) ;
}
V_54 -> V_108 = true ;
F_100 () ;
F_86 ( F_91 , ( void * ) V_51 , 1 ) ;
if ( F_74 ( V_54 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_159 ) < 0 )
F_20 ( L_34 ) ;
F_101 ( V_51 ) ;
return 0 ;
}
static void F_102 ( struct V_160 * V_161 )
{
struct V_162 * V_163 =
F_103 ( V_161 , struct V_162 , V_107 ) ;
struct V_53 * V_54 =
F_103 ( V_163 , struct V_53 , V_164 ) ;
if ( F_93 ( V_54 -> V_51 ) != 0 )
F_104 ( & V_54 -> V_164 ,
V_165 ) ;
else
F_105 ( V_54 -> V_51 ) ;
}
static int F_106 ( struct V_50 * V_51 )
{
int V_114 = 0 ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
if ( ! V_54 -> V_150 ) {
int V_9 ;
int V_166 ;
V_114 = F_66 ( V_51 ) ;
if ( V_114 < 0 ) {
F_68 ( L_35 , V_114 ) ;
return V_114 ;
}
if ( V_167 )
F_107 ( & V_54 -> V_131 ,
& V_131 ) ;
else
F_107 ( & V_54 -> V_131 , V_168 ) ;
V_9 = F_108 ( & V_54 -> V_131 ) ;
V_166 = F_109 ( 16 , ( V_158 / V_9 ) & ~ 1 ) ;
V_166 = F_99 ( V_169 , V_166 ) ;
V_54 -> V_156 = V_9 ;
V_54 -> V_134 = V_166 ;
#ifdef F_36
F_6 ( L_36 ,
V_54 -> V_156 , V_54 -> V_134 ) ;
#endif
V_54 -> V_150 = true ;
} else {
}
V_114 = F_93 ( V_51 ) ;
if ( V_114 <= 0 ) {
if ( V_114 == 0 )
F_105 ( V_51 ) ;
return V_114 ;
}
F_110 ( V_51 ) ;
F_104 ( & V_54 -> V_164 , V_165 ) ;
return 0 ;
}
static int F_111 ( struct V_53 * V_54 )
{
int V_47 = 0 ;
while ( true ) {
int V_21 ;
if ( F_67 ( V_54 -> V_117 , 0 , ( V_118 ) & V_21 ,
sizeof( V_21 ) , V_170 ) < 0 )
break;
if ( V_21 == 0 )
break;
{
void * V_17 = F_40 ( ( V_80 ) ( V_21 >> 1 ) << 7 ) ;
struct V_31 * * V_33 = V_17 - sizeof( * V_33 ) ;
struct V_31 * V_32 = * V_33 ;
F_31 ( V_32 ) ;
}
V_47 ++ ;
}
return V_47 ;
}
static int F_112 ( struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
F_77 ( L_37 ) ;
V_54 -> V_108 = false ;
F_100 () ;
F_86 ( F_82 , ( void * ) V_51 , 1 ) ;
( void ) F_111 ( V_54 ) ;
F_113 ( & V_54 -> V_164 ) ;
F_114 ( V_51 ) ;
F_86 ( F_89 , ( void * ) V_51 , 1 ) ;
if ( F_111 ( V_54 ) != 0 )
F_81 ( L_38 ) ;
F_85 ( V_51 ) ;
while ( F_27 ( V_51 , true ) )
;
memset ( V_54 -> V_43 , 0 , sizeof( T_4 ) ) ;
F_100 () ;
return 0 ;
}
static unsigned int F_115 ( T_12 * V_171 ,
struct V_31 * V_32 ,
void * V_172 , unsigned int V_173 )
{
unsigned int V_2 , V_47 = 0 ;
struct V_174 * V_175 = F_116 ( V_32 ) ;
V_80 V_176 ;
if ( V_173 != 0 ) {
if ( ! V_35 )
F_117 ( V_172 , V_173 , 0 ) ;
V_176 = F_9 ( V_172 ) ;
V_171 [ V_47 ] . V_177 = V_176 ;
V_171 [ V_47 ] . V_178 = V_176 >> 32 ;
V_171 [ V_47 ] . V_6 = V_173 ;
V_171 [ V_47 ] . V_179 = V_35 ;
V_47 ++ ;
}
for ( V_2 = 0 ; V_2 < V_175 -> V_180 ; V_2 ++ ) {
T_13 * V_181 = & V_175 -> V_171 [ V_2 ] ;
unsigned long V_182 = F_118 ( F_119 ( V_181 ) ) ;
int V_179 = V_35 ;
if ( ! V_35 ) {
void * V_17 = F_120 ( V_182 ) + V_181 -> V_183 ;
F_14 ( F_121 ( F_119 ( V_181 ) ) ) ;
F_117 ( V_17 , V_181 -> V_126 , 0 ) ;
}
V_176 = ( ( V_80 ) V_182 << V_184 ) + V_181 -> V_183 ;
V_171 [ V_47 ] . V_177 = V_176 ;
V_171 [ V_47 ] . V_178 = V_176 >> 32 ;
V_171 [ V_47 ] . V_6 = F_122 ( V_181 ) ;
V_171 [ V_47 ] . V_179 = V_179 ;
V_47 ++ ;
}
return V_47 ;
}
static int F_123 ( struct V_31 * V_32 , struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
struct V_84 * V_85 = & V_16 -> V_85 ;
struct V_174 * V_175 = F_116 ( V_32 ) ;
unsigned char * V_5 = V_32 -> V_5 ;
struct V_185 * V_186 = F_124 ( V_32 ) ;
unsigned int V_187 = V_186 -> V_188 * 4 ;
unsigned char * V_189 = F_125 ( V_32 ) ;
unsigned int V_190 = V_189 - V_5 ;
struct V_191 * V_192 = (struct V_191 * ) ( V_189 + V_187 ) ;
unsigned int V_193 = V_192 -> V_194 * 4 ;
unsigned int V_195 = V_190 + V_187 + V_193 ;
unsigned int V_173 = F_126 ( V_32 ) - V_195 ;
unsigned int V_196 = V_173 + V_32 -> V_197 ;
unsigned int V_198 = V_175 -> V_199 ;
unsigned int V_200 = V_175 -> V_201 ;
T_2 V_202 [ ( V_203 + 3 ) / 4 ] ;
T_14 * V_204 = ( T_14 * ) V_202 ;
unsigned int V_205 =
F_115 ( V_204 -> V_171 , V_32 , V_5 + V_195 , V_173 ) ;
T_15 V_206 = F_127 ( V_205 , V_195 ) ;
T_14 V_207 = {
. V_208 = true ,
. V_209 = V_195 ,
. V_210 = V_190 ,
. V_211 = V_190 + V_187 ,
. V_212 = V_198 ,
. V_205 = V_205 ,
} ;
unsigned long V_213 ;
T_4 * V_43 = V_54 -> V_43 ;
struct V_31 * V_55 [ 8 ] ;
unsigned int V_56 = 8 ;
unsigned int V_2 , V_214 = 0 ;
unsigned int V_215 , V_216 , V_217 ;
unsigned int V_59 ;
F_14 ( V_32 -> V_97 != F_128 ( V_218 ) ) ;
F_14 ( V_186 -> V_97 != V_219 ) ;
F_14 ( V_32 -> V_98 != V_220 ) ;
F_14 ( V_205 > V_221 ) ;
F_14 ( V_200 <= 1 ) ;
* V_204 = V_207 ;
memcpy ( & V_204 -> V_171 [ V_205 ] , V_5 , V_195 ) ;
F_129 ( & V_43 -> V_59 ) ;
F_129 ( & V_43 -> V_216 ) ;
F_100 () ;
F_130 ( & V_54 -> V_58 , V_213 ) ;
if ( F_131 ( V_43 ) == 0 ) {
V_214 = F_25 ( V_43 , V_55 , V_56 , 0 ) ;
if ( V_214 == 0 ) {
V_222:
F_132 ( & V_54 -> V_58 , V_213 ) ;
return V_223 ;
}
}
V_215 = V_43 -> V_215 ;
V_216 = V_43 -> V_216 ;
V_217 = V_216 + V_206 ;
if ( V_216 < V_215 && V_217 >= V_215 )
goto V_222;
if ( V_217 > V_224 ) {
V_217 = 0 ;
if ( V_217 == V_215 )
goto V_222;
}
memcpy ( & V_43 -> V_225 [ V_216 ] , V_204 , V_206 ) ;
V_216 = V_217 ;
V_59 = V_43 -> V_59 ;
V_43 -> V_44 [ V_59 ] = V_32 ;
F_26 ( V_59 ) ;
V_43 -> V_59 = V_59 ;
F_23 () ;
V_43 -> V_216 = V_216 ;
if ( V_214 == 0 )
V_214 = F_25 ( V_43 , V_55 , V_56 , 4 ) ;
F_132 ( & V_54 -> V_58 , V_213 ) ;
for ( V_2 = 0 ; V_2 < V_214 ; V_2 ++ )
F_31 ( V_55 [ V_2 ] ) ;
V_85 -> V_226 += V_200 ;
V_85 -> V_227 += ( V_200 * V_195 ) + V_196 ;
F_32 ( V_16 ) ;
return V_228 ;
}
static int F_133 ( struct V_31 * V_32 , struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_54 -> V_82 [ V_8 ] ;
struct V_84 * V_85 = & V_16 -> V_85 ;
unsigned long V_213 ;
struct V_174 * V_175 = F_116 ( V_32 ) ;
unsigned int V_3 = V_32 -> V_3 ;
unsigned char * V_5 = V_32 -> V_5 ;
unsigned int V_229 = F_134 ( V_32 ) ;
T_12 V_171 [ V_221 ] ;
unsigned int V_205 ;
T_4 * V_43 = V_54 -> V_43 ;
struct V_31 * V_55 [ 8 ] ;
unsigned int V_56 = 8 ;
unsigned int V_2 , V_214 = 0 ;
unsigned int V_206 = sizeof( V_230 ) ;
unsigned int V_215 , V_216 , V_217 ;
unsigned int V_59 ;
V_230 V_225 [ V_221 ] ;
if ( ! V_16 -> V_147 )
return V_223 ;
V_51 -> V_231 = V_62 ;
#ifdef F_16
#if F_17 ()
if ( V_35 ) {
T_3 V_36 = * F_18 ( V_37 -> V_38 , ( unsigned long ) V_5 ) ;
if ( F_19 ( V_36 ) != V_39 )
F_20 ( L_39 ,
V_5 , F_19 ( V_36 ) , F_21 ( V_36 ) ) ;
}
#endif
#endif
#ifdef F_45
F_5 ( V_5 , F_126 ( V_32 ) , L_40 ) ;
#endif
if ( V_175 -> V_199 != 0 )
return F_123 ( V_32 , V_51 ) ;
V_205 = F_115 ( V_171 , V_32 , V_5 , F_126 ( V_32 ) ) ;
for ( V_2 = 0 ; V_2 < V_205 ; V_2 ++ ) {
bool V_232 = ( V_2 == V_205 - 1 ) ;
V_230 V_204 = {
. V_177 = V_171 [ V_2 ] . V_177 ,
. V_178 = V_171 [ V_2 ] . V_178 ,
. V_6 = V_171 [ V_2 ] . V_6 ,
. V_179 = V_171 [ V_2 ] . V_179 ,
. V_233 = V_232 ,
. V_234 = V_232
} ;
if ( V_2 == 0 && V_32 -> V_98 == V_220 ) {
V_204 . V_235 = 1 ;
V_204 . V_236 . V_237 . V_238 = V_229 ;
V_204 . V_236 . V_237 . V_9 = V_3 - V_229 ;
V_204 . V_236 . V_237 . V_239 =
V_229 + V_32 -> V_240 ;
}
V_225 [ V_2 ] = V_204 ;
}
F_129 ( & V_43 -> V_59 ) ;
F_129 ( & V_43 -> V_216 ) ;
F_100 () ;
F_130 ( & V_54 -> V_58 , V_213 ) ;
if ( F_131 ( V_43 ) == 0 ) {
V_214 = F_25 ( V_43 , V_55 , V_56 , 0 ) ;
if ( V_214 == 0 ) {
V_222:
F_132 ( & V_54 -> V_58 , V_213 ) ;
return V_223 ;
}
}
V_215 = V_43 -> V_215 ;
V_216 = V_43 -> V_216 ;
for ( V_2 = 0 ; V_2 < V_205 ; V_2 ++ ) {
V_217 = V_216 + V_206 ;
if ( V_216 < V_215 && V_217 >= V_215 )
goto V_222;
if ( V_217 > V_224 ) {
V_217 = 0 ;
if ( V_217 == V_215 )
goto V_222;
}
* ( V_230 * ) & V_43 -> V_225 [ V_216 ] = V_225 [ V_2 ] ;
V_216 = V_217 ;
}
V_59 = V_43 -> V_59 ;
V_43 -> V_44 [ V_59 ] = V_32 ;
F_26 ( V_59 ) ;
V_43 -> V_59 = V_59 ;
F_23 () ;
V_43 -> V_216 = V_216 ;
if ( V_214 == 0 )
V_214 = F_25 ( V_43 , V_55 , V_56 , 4 ) ;
F_132 ( & V_54 -> V_58 , V_213 ) ;
for ( V_2 = 0 ; V_2 < V_214 ; V_2 ++ )
F_31 ( V_55 [ V_2 ] ) ;
V_85 -> V_226 ++ ;
V_85 -> V_227 += ( ( V_3 >= V_241 ) ? V_3 : V_241 ) ;
F_32 ( V_16 ) ;
return V_228 ;
}
static void F_135 ( struct V_50 * V_51 )
{
F_77 ( L_41 ) ;
F_77 ( L_42 , V_62 ,
V_62 - V_51 -> V_231 ) ;
F_136 ( V_51 ) ;
}
static int F_137 ( struct V_50 * V_51 , struct V_242 * V_243 , int V_204 )
{
return - V_244 ;
}
static struct V_245 * F_138 ( struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
T_2 V_100 = 0 ;
T_2 V_226 = 0 ;
T_2 V_101 = 0 ;
T_2 V_227 = 0 ;
int V_2 ;
F_87 (i) {
if ( V_54 -> V_82 [ V_2 ] ) {
V_100 += V_54 -> V_82 [ V_2 ] -> V_85 . V_100 ;
V_101 += V_54 -> V_82 [ V_2 ] -> V_85 . V_101 ;
V_226 += V_54 -> V_82 [ V_2 ] -> V_85 . V_226 ;
V_227 += V_54 -> V_82 [ V_2 ] -> V_85 . V_227 ;
}
}
V_54 -> V_85 . V_100 = V_100 ;
V_54 -> V_85 . V_101 = V_101 ;
V_54 -> V_85 . V_226 = V_226 ;
V_54 -> V_85 . V_227 = V_227 ;
return & V_54 -> V_85 ;
}
static int F_139 ( struct V_50 * V_51 , int V_246 )
{
F_77 ( L_43 ) ;
if ( ( V_246 < 68 ) || ( V_246 > 1500 ) )
return - V_247 ;
V_51 -> V_248 = V_246 ;
return 0 ;
}
static int F_140 ( struct V_50 * V_51 , void * V_249 )
{
struct V_250 * V_251 = V_249 ;
if ( ! F_141 ( V_251 -> V_252 ) )
return - V_247 ;
memcpy ( V_51 -> V_96 , V_251 -> V_252 , V_51 -> V_253 ) ;
return 0 ;
}
static int F_142 ( struct V_50 * V_51 )
{
struct V_53 * V_54 = F_28 ( V_51 ) ;
char V_254 [ 32 ] ;
int V_3 ;
T_16 V_255 = { . V_79 = V_256 } ;
int V_114 ;
strcpy ( V_254 , V_51 -> V_136 ) ;
V_3 = strlen ( V_254 ) ;
V_254 [ V_3 ] = V_254 [ V_3 - 1 ] ;
V_254 [ V_3 - 1 ] = '/' ;
V_3 ++ ;
strcpy ( V_254 + V_3 , V_35 ? L_44 : L_45 ) ;
V_54 -> V_117 = F_143 ( ( V_118 ) V_254 , 0 ) ;
F_77 ( L_46 ,
V_254 , V_54 -> V_117 , & V_54 -> V_117 ) ;
if ( V_54 -> V_117 < 0 ) {
if ( V_54 -> V_117 == V_257 )
F_81 ( V_144 L_47 ,
V_254 ) ;
else
F_81 ( V_144 L_48 ,
V_254 , V_54 -> V_117 ) ;
return - 1 ;
}
V_255 . V_237 . V_258 = V_259 ;
V_255 . V_237 . V_251 = V_260 ;
V_114 = F_67 ( V_54 -> V_117 , 0 ,
( V_118 ) V_51 -> V_96 , V_51 -> V_253 ,
V_255 . V_79 ) ;
F_77 ( L_49 , V_114 ) ;
if ( V_114 <= 0 ) {
F_81 ( V_144 L_50 ,
V_51 -> V_136 ) ;
F_144 ( V_51 -> V_96 ) ;
}
return 0 ;
}
static void F_145 ( struct V_50 * V_51 )
{
F_77 ( L_51 ) ;
F_146 ( V_51 ) ;
V_51 -> V_261 = & V_262 ;
V_51 -> V_263 = V_264 ;
V_51 -> V_265 |= V_266 ;
V_51 -> V_265 |= V_267 ;
V_51 -> V_265 |= V_268 ;
V_51 -> V_265 |= V_269 ;
#ifdef F_147
V_51 -> V_265 |= V_270 ;
#endif
if ( V_35 )
V_51 -> V_265 |= V_271 ;
V_51 -> V_272 = V_273 ;
V_51 -> V_248 = V_24 ;
}
static struct V_50 * F_148 ( const char * V_136 )
{
int V_114 ;
struct V_50 * V_51 ;
struct V_53 * V_54 ;
V_51 = F_149 ( sizeof( * V_54 ) , V_136 , F_145 ) ;
if ( ! V_51 ) {
F_68 ( L_52 , V_136 ) ;
return NULL ;
}
V_54 = F_28 ( V_51 ) ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_51 = V_51 ;
F_150 ( & V_54 -> V_164 , F_102 ) ;
F_151 ( & V_54 -> V_58 ) ;
V_54 -> V_122 = F_152 ( V_274 | V_275 , V_123 ) ;
if ( ! V_54 -> V_122 ) {
F_153 ( V_51 ) ;
return NULL ;
}
V_54 -> V_43 = F_154 ( V_54 -> V_122 ) ;
V_114 = F_155 ( V_51 ) ;
if ( V_114 ) {
F_68 ( L_53 , V_51 -> V_136 , V_114 ) ;
F_156 ( V_54 -> V_122 , V_123 ) ;
F_153 ( V_51 ) ;
return NULL ;
}
V_114 = F_142 ( V_51 ) ;
if ( V_114 < 0 ) {
F_157 ( V_51 ) ;
F_156 ( V_54 -> V_122 , V_123 ) ;
F_153 ( V_51 ) ;
return NULL ;
}
return V_51 ;
}
static void F_158 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_276 ; V_2 ++ ) {
if ( V_277 [ V_2 ] ) {
struct V_50 * V_51 = V_277 [ V_2 ] ;
struct V_53 * V_54 = F_28 ( V_51 ) ;
F_157 ( V_51 ) ;
F_117 ( V_54 -> V_43 , V_127 , 0 ) ;
F_156 ( V_54 -> V_122 , V_123 ) ;
F_153 ( V_51 ) ;
}
}
}
static int F_159 ( void )
{
F_6 ( L_54 ) ;
V_277 [ 0 ] = F_148 ( L_20 ) ;
V_277 [ 1 ] = F_148 ( L_21 ) ;
V_277 [ 2 ] = F_148 ( L_22 ) ;
V_277 [ 3 ] = F_148 ( L_23 ) ;
return 0 ;
}
static int T_17 F_160 ( char * V_278 )
{
int V_279 = F_161 ( V_278 , & V_131 ) ;
if ( V_279 != 0 ) {
F_49 ( L_55 ,
V_278 ) ;
} else {
F_162 ( & V_131 , & V_131 ,
V_280 ) ;
if ( F_163 ( & V_131 ) ) {
F_49 ( L_56 ,
V_278 ) ;
} else {
char V_4 [ 1024 ] ;
F_164 ( V_4 , sizeof( V_4 ) , & V_131 ) ;
F_6 ( L_57 , V_4 ) ;
V_167 = true ;
}
}
return 0 ;
}
