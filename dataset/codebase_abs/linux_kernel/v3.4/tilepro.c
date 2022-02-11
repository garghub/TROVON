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
static void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
T_3 * V_19 = & V_18 -> V_20 ;
if ( -- V_19 -> V_21 == 0 ) {
T_2 V_22 = V_19 -> V_23 ;
V_19 -> V_21 = V_22 ;
F_9 ( V_19 -> V_24 , V_22 ) ;
}
}
static void F_10 ( struct V_15 * V_16 ,
void * V_25 , bool V_26 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
unsigned int V_27 = ( ( unsigned int ) ( F_11 ( V_25 ) >> 7 ) << 1 ) + V_26 ;
F_12 ( V_18 -> V_20 . V_24 , V_27 ) ;
}
static bool F_13 ( struct V_15 * V_16 ,
bool V_26 )
{
#if V_28 <= 1536
unsigned int V_29 = V_30 + 1536 ;
#else
unsigned int V_29 = V_30 + V_28 + 100 ;
#endif
unsigned int V_3 =
( ( ( V_26 ? V_31 : V_29 ) +
F_14 () - 1 ) & - F_14 () ) ;
unsigned int V_32 = 128 - V_33 ;
unsigned int V_34 ;
struct V_35 * V_36 ;
void * V_25 ;
struct V_35 * * V_37 ;
V_36 = F_15 ( V_16 -> V_38 . V_39 , V_3 + V_32 ) ;
if ( V_36 == NULL )
return false ;
V_34 = - ( long ) V_36 -> V_5 & ( 128 - 1 ) ;
F_16 ( V_34 > V_32 ) ;
F_17 ( V_36 , V_34 ) ;
V_25 = V_36 -> V_5 ;
F_16 ( ( ( ( ( long ) V_25 & ~ V_40 ) + V_3 ) & V_40 ) != 0 ) ;
#ifdef F_18
#if F_19 ()
if ( V_41 ) {
T_4 V_42 = * F_20 ( V_43 -> V_44 , ( unsigned long ) V_25 ) ;
if ( F_21 ( V_42 ) != V_45 )
F_22 ( L_7 ,
V_25 , F_21 ( V_42 ) , F_23 ( V_42 ) ) ;
}
#endif
#endif
if ( ! V_41 )
F_24 ( V_25 , V_3 ) ;
F_17 ( V_36 , V_30 ) ;
V_37 = V_25 - sizeof( * V_37 ) ;
* V_37 = V_36 ;
F_25 () ;
F_10 ( V_16 , V_25 , V_26 ) ;
return true ;
}
static void F_26 ( struct V_15 * V_16 )
{
while ( V_16 -> V_46 != 0 ) {
if ( ! F_13 ( V_16 , true ) )
goto V_47;
V_16 -> V_46 -- ;
}
while ( V_16 -> V_48 != 0 ) {
if ( ! F_13 ( V_16 , false ) )
goto V_47;
V_16 -> V_48 -- ;
}
return;
V_47:
F_4 ( L_8 ) ;
}
static unsigned int F_27 ( T_5 * V_49 ,
struct V_35 * V_50 [] ,
unsigned int V_51 ,
unsigned int V_52 )
{
unsigned int V_53 = 0 ;
unsigned int V_54 = V_49 -> V_54 ;
unsigned int V_55 = V_49 -> V_55 ;
while ( V_54 != V_55 && V_53 < V_51 ) {
V_50 [ V_53 ++ ] = V_49 -> V_50 [ V_54 ] ;
F_28 ( V_54 ) ;
}
if ( V_53 < V_52 )
return 0 ;
V_49 -> V_54 = V_54 ;
return V_53 ;
}
static bool F_29 ( struct V_56 * V_39 , bool V_57 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
T_5 * V_49 = V_59 -> V_49 ;
struct V_35 * V_60 [ 64 ] ;
unsigned int V_61 = 64 ;
unsigned int V_2 , V_53 ;
bool V_62 ;
F_31 ( & V_59 -> V_63 ) ;
if ( V_57 )
V_49 -> V_55 = V_49 -> V_64 ;
V_53 = F_27 ( V_49 , V_60 , V_61 , 0 ) ;
V_62 = ( V_49 -> V_54 != V_49 -> V_64 ) ;
F_32 ( & V_59 -> V_63 ) ;
for ( V_2 = 0 ; V_2 < V_53 ; V_2 ++ )
F_33 ( V_60 [ V_2 ] ) ;
return V_62 ;
}
static void F_34 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_65 ) {
F_35 ( & V_16 -> V_66 , V_67 + 1 ) ;
V_16 -> V_65 = true ;
}
}
static void F_36 ( unsigned long V_68 )
{
struct V_15 * V_16 = (struct V_15 * ) V_68 ;
struct V_56 * V_39 = V_16 -> V_38 . V_39 ;
V_16 -> V_65 = false ;
if ( F_29 ( V_39 , false ) )
F_34 ( V_16 ) ;
}
static bool F_37 ( char * V_69 , char * V_70 , unsigned int V_3 )
{
int V_2 ;
unsigned long long V_71 = 0 ;
V_71 |= ( 1ULL << 0x12 ) ;
V_71 |= ( 1ULL << 0x13 ) ;
V_71 |= ( 1ULL << 0x18 ) ;
V_71 |= ( 1ULL << 0x19 ) ;
V_71 |= ( 1ULL << 0x2a ) ;
V_71 |= ( 1ULL << 0x2b ) ;
V_71 |= ( 1ULL << 0x2c ) ;
V_71 |= ( 1ULL << 0x2d ) ;
V_71 |= ( 1ULL << 0x30 ) ;
V_71 |= ( 1ULL << 0x31 ) ;
V_71 |= ( 1ULL << 0x32 ) ;
V_71 |= ( 1ULL << 0x33 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ , V_71 >>= 1 ) {
if ( ( V_71 & 1 ) || ( V_69 [ V_2 ] == V_70 [ V_2 ] ) )
continue;
#ifdef F_38
if ( V_2 < 0x38 && V_2 != 0x2f &&
F_39 () )
F_6 ( L_9 , V_2 ) ;
#endif
return false ;
}
#ifdef F_40
if ( V_69 [ 0x2a ] == V_70 [ 0x2a ] &&
V_69 [ 0x2b ] == V_70 [ 0x2b ] &&
V_69 [ 0x2c ] == V_70 [ 0x2c ] &&
V_69 [ 0x2d ] == V_70 [ 0x2d ] ) {
return false ;
}
#endif
return true ;
}
static void F_41 ( struct V_15 * V_16 , int V_72 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_73 = V_18 -> V_74 ;
T_3 * V_19 = & V_18 -> V_20 ;
int V_75 = V_72 + sizeof( V_76 ) ;
int V_77 =
( ( V_75 ==
V_73 -> V_78 . V_79 ) ?
0 : V_75 ) ;
V_76 * V_80 = ( V_76 * ) ( ( unsigned long ) & V_73 [ 1 ] + V_72 ) ;
unsigned int V_27 = V_80 -> V_81 . V_82 ;
void * V_25 = F_42 ( ( V_83 ) ( V_27 >> 1 ) << 7 ) ;
struct V_35 * * V_37 = V_25 - sizeof( * V_37 ) ;
struct V_35 * V_36 = * V_37 ;
F_33 ( V_36 ) ;
V_19 -> V_84 = V_77 ;
}
static void F_43 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_73 = V_18 -> V_74 ;
T_3 * V_19 = & V_18 -> V_20 ;
while ( V_19 -> V_84 !=
V_73 -> V_78 . V_86 ) {
int V_72 = V_19 -> V_84 ;
F_41 ( V_16 , V_72 ) ;
}
}
static bool F_44 ( struct V_15 * V_16 , int V_72 )
{
struct V_56 * V_39 = V_16 -> V_38 . V_39 ;
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_73 = V_18 -> V_74 ;
T_3 * V_19 = & V_18 -> V_20 ;
struct V_87 * V_88 = & V_16 -> V_88 ;
int V_89 ;
int V_75 = V_72 + sizeof( V_76 ) ;
int V_77 =
( ( V_75 ==
V_73 -> V_78 . V_79 ) ?
0 : V_75 ) ;
V_76 * V_80 = ( V_76 * ) ( ( unsigned long ) & V_73 [ 1 ] + V_72 ) ;
T_7 * V_90 = F_45 ( V_80 ) ;
unsigned long V_3 =
( F_46 ( V_80 ) +
V_30 - V_91 ) ;
unsigned int V_27 = V_80 -> V_81 . V_82 ;
bool V_26 = ( ( V_27 & 1 ) != 0 ) ;
void * V_25 = F_42 ( ( V_83 ) ( V_27 >> 1 ) << 7 ) ;
unsigned char * V_4 = V_25 + V_30 ;
if ( ! V_41 )
F_24 ( V_4 , V_3 ) ;
V_39 -> V_92 = V_67 ;
#ifdef F_47
F_5 ( V_4 , V_3 , L_10 ) ;
#endif
#ifdef F_48
if ( ! F_49 ( V_90 , V_80 ) &&
F_50 ( V_90 , V_80 ) ) {
F_51 ( L_11 , V_3 ) ;
}
if ( ! F_52 ( V_90 , V_80 ) &&
F_53 ( V_90 , V_80 ) ) {
F_5 ( V_4 , V_3 , L_10 ) ;
F_22 ( L_12 ) ;
}
switch ( F_54 ( V_90 , V_80 ) ) {
case V_93 :
if ( V_3 >= 64 ) {
F_5 ( V_4 , V_3 , L_10 ) ;
F_22 ( L_13 ) ;
}
break;
case V_94 :
F_51 ( L_14 , V_3 ) ;
}
#endif
V_89 = 0 ;
if ( ! ( V_39 -> V_95 & V_96 ) ) {
V_89 = 1 ;
} else if ( F_54 ( V_90 , V_80 ) == V_94 ) {
V_89 = 1 ;
} else if ( ! ( V_39 -> V_95 & V_97 ) ) {
if ( ! F_55 ( V_4 ) ) {
const T_8 * V_98 = V_39 -> V_99 ;
V_89 = F_56 ( V_98 , V_4 ) ;
}
}
if ( V_89 ) {
F_10 ( V_16 , V_25 , V_26 ) ;
} else {
struct V_35 * * V_37 = V_25 - sizeof( * V_37 ) ;
struct V_35 * V_36 = * V_37 ;
if ( V_36 -> V_5 != V_4 )
F_22 ( L_15
L_16 ,
V_25 , V_36 , V_36 -> V_5 ) ;
F_57 ( V_36 , V_3 ) ;
V_36 -> V_100 = F_58 ( V_36 , V_39 ) ;
if ( F_49 ( V_90 , V_80 ) )
V_36 -> V_101 = V_102 ;
F_59 ( V_36 ) ;
V_88 -> V_103 ++ ;
V_88 -> V_104 += V_3 ;
}
F_8 ( V_16 ) ;
V_19 -> V_84 = V_77 ;
return ! V_89 ;
}
static int F_60 ( struct V_105 * V_38 , int V_106 )
{
struct V_56 * V_39 = V_38 -> V_39 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_73 = V_18 -> V_74 ;
T_3 * V_19 = & V_18 -> V_20 ;
unsigned int V_107 = 0 ;
while ( V_59 -> V_108 ) {
int V_72 = V_19 -> V_84 ;
if ( V_72 == V_73 -> V_78 . V_86 )
break;
if ( F_44 ( V_16 , V_72 ) ) {
if ( ++ V_107 >= V_106 )
goto V_109;
}
}
F_61 ( & V_16 -> V_38 ) ;
if ( ! V_59 -> V_108 )
goto V_109;
F_62 ( V_59 -> V_110 , 0 ) ;
if ( V_19 -> V_84 !=
V_73 -> V_78 . V_86 ) {
( void ) F_63 ( & V_16 -> V_38 ) ;
}
V_109:
if ( V_59 -> V_108 )
F_26 ( V_16 ) ;
return V_107 ;
}
static T_9 F_64 ( int V_111 , void * V_112 )
{
struct V_56 * V_39 = (struct V_56 * ) V_112 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
F_65 ( V_59 -> V_110 ) ;
if ( ! V_59 -> V_108 )
return V_113 ;
F_66 ( & V_16 -> V_38 ) ;
return V_113 ;
}
static int F_67 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_114 ;
int V_115 ;
unsigned int V_116 ;
V_114 = F_68 ( V_59 -> V_117 , 0 ,
( V_118 ) & V_116 , sizeof( V_116 ) ,
V_119 ) ;
if ( V_114 < 0 ) {
F_69 ( L_17 ) ;
return - V_120 ;
}
{
int V_121 = F_70 ( V_116 ) ;
F_71 ( V_59 -> V_122 , V_123 , V_121 ) ;
}
{
T_10 V_124 = {
. V_25 = 0 ,
. V_125 = F_11 ( V_59 -> V_49 ) ,
. V_42 = F_72 ( 0 ) ,
. V_126 = V_127 ,
} ;
V_124 . V_42 = F_73 ( V_124 . V_42 , V_116 ) ;
V_124 . V_42 = F_74 ( V_124 . V_42 , V_128 ) ;
V_114 = F_75 ( V_59 -> V_117 , 0 ,
( V_118 ) & V_124 ,
sizeof( V_124 ) ,
V_119 ) ;
if ( V_114 < 0 )
return - V_120 ;
}
if ( F_75 ( V_59 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_129 ) < 0 ) {
F_51 ( L_18 ) ;
return - V_120 ;
}
return 0 ;
}
static void F_76 ( void * V_112 )
{
struct V_56 * V_39 = (struct V_56 * ) V_112 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_130 =
F_77 ( V_8 , & V_59 -> V_131 ) ? 0 : 255 ;
T_11 V_132 = {
. V_95 = 0 ,
. V_133 = V_59 -> V_134 ,
. V_130 = V_130
} ;
int V_114 = 0 ;
T_6 * V_135 ;
F_78 ( L_19 , V_130 ) ;
if ( ! strcmp ( V_39 -> V_136 , L_20 ) )
V_16 = & F_79 ( V_137 ) ;
else if ( ! strcmp ( V_39 -> V_136 , L_21 ) )
V_16 = & F_79 ( V_138 ) ;
else if ( ! strcmp ( V_39 -> V_136 , L_22 ) )
V_16 = & F_79 ( V_139 ) ;
else if ( ! strcmp ( V_39 -> V_136 , L_23 ) )
V_16 = & F_79 ( V_140 ) ;
else
F_80 () ;
F_81 ( & V_16 -> V_66 ) ;
V_16 -> V_66 . V_5 = ( long ) V_16 ;
V_16 -> V_66 . V_141 = F_36 ;
V_59 -> V_85 [ V_8 ] = V_16 ;
V_114 = F_75 ( V_59 -> V_117 , 0 ,
( V_118 ) & V_132 ,
sizeof( T_11 ) ,
V_142 ) ;
F_78 ( L_24 ,
V_114 ) ;
if ( V_114 < 0 ) {
if ( V_114 != V_143 ) {
F_82 ( V_144 L_25
L_26 ,
V_114 ) ;
}
V_16 -> V_145 = ( V_114 == V_143 ) ;
return;
}
V_114 = F_68 ( V_59 -> V_117 , 0 ,
( V_118 ) & V_135 ,
sizeof( T_6 * ) ,
V_142 ) ;
F_78 ( L_27 ,
V_114 ) ;
F_78 ( L_28 , V_135 ) ;
if ( V_114 <= 0 ) {
F_69 ( L_29 ) ;
return;
}
V_18 = & V_16 -> V_18 ;
V_18 -> V_74 = V_135 ;
memset ( & V_18 -> V_20 , 0 , sizeof( T_3 ) ) ;
V_18 -> V_20 . V_23 = 4 ;
V_18 -> V_20 . V_21 =
V_18 -> V_20 . V_23 ;
V_114 = F_68 ( V_59 -> V_117 , 0 ,
( V_118 ) & V_18 -> V_20 . V_24 ,
sizeof( V_18 -> V_20 . V_24 ) ,
V_146 ) ;
F_78 ( L_30 , V_114 ) ;
V_16 -> V_147 = true ;
}
static void F_83 ( void * V_112 )
{
struct V_56 * V_39 = (struct V_56 * ) V_112 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
F_65 ( V_59 -> V_110 ) ;
if ( V_16 == NULL || ! V_16 -> V_147 )
return;
{
struct V_17 * V_18 = & V_16 -> V_18 ;
T_3 * V_19 = & V_18 -> V_20 ;
F_9 ( V_19 -> V_24 , - 1 ) ;
}
}
static void F_84 ( void * V_112 )
{
struct V_56 * V_39 = (struct V_56 * ) V_112 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
int V_114 ;
int V_115 = 0 ;
F_65 ( V_59 -> V_110 ) ;
if ( V_16 == NULL || ! V_16 -> V_147 )
return;
V_114 = F_75 ( V_59 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_148 ) ;
if ( V_114 < 0 )
F_22 ( L_31 ) ;
F_43 ( V_39 ) ;
V_16 -> V_46 = 0 ;
V_16 -> V_48 = 0 ;
F_85 ( & V_16 -> V_66 ) ;
V_16 -> V_65 = false ;
}
static void F_86 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_2 ;
int V_115 = 0 ;
F_87 ( F_84 , ( void * ) V_39 , 1 ) ;
F_88 (i) {
struct V_15 * V_16 = V_59 -> V_85 [ V_2 ] ;
if ( V_16 != NULL && V_16 -> V_147 ) {
F_89 ( & V_16 -> V_38 ) ;
V_16 -> V_147 = false ;
}
}
if ( F_75 ( V_59 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_149 ) < 0 )
F_22 ( L_32 ) ;
V_59 -> V_150 = false ;
}
static void F_90 ( void * V_112 )
{
struct V_56 * V_39 = (struct V_56 * ) V_112 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
if ( V_16 != NULL && V_16 -> V_151 ) {
F_91 ( & V_16 -> V_38 ) ;
V_16 -> V_151 = false ;
}
}
static void F_92 ( void * V_112 )
{
struct V_56 * V_39 = (struct V_56 * ) V_112 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
F_93 ( & V_16 -> V_38 ) ;
V_16 -> V_151 = true ;
F_62 ( V_59 -> V_110 , 0 ) ;
}
static int F_94 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_12 = 0 ;
int V_2 ;
int V_115 = 0 ;
F_76 ( V_39 ) ;
V_16 = V_59 -> V_85 [ V_8 ] ;
if ( ! V_16 -> V_147 ) {
if ( V_16 -> V_145 )
return 1 ;
return - V_152 ;
}
F_95 ( F_76 , ( void * ) V_39 , 1 ) ;
F_88 (i) {
struct V_15 * V_16 = V_59 -> V_85 [ V_2 ] ;
if ( V_16 -> V_147 )
F_96 ( V_39 , & V_16 -> V_38 , F_60 , 64 ) ;
else
V_12 = - V_152 ;
}
if ( V_12 != 0 ) {
F_86 ( V_39 ) ;
return V_12 ;
}
V_18 = & V_16 -> V_18 ;
if ( V_59 -> V_110 == 0 ) {
unsigned int V_111 ;
V_59 -> V_110 = V_18 -> V_74 -> V_153 ;
F_16 ( V_59 -> V_110 == 0 ) ;
V_111 = F_97 ( V_59 -> V_110 ) ;
F_98 ( V_111 , V_154 ) ;
F_16 ( F_99 ( V_111 , F_64 ,
0 , V_39 -> V_136 , ( void * ) V_39 ) != 0 ) ;
}
{
int V_155 =
V_59 -> V_156 * V_59 -> V_134 ;
V_16 -> V_46 =
F_100 ( V_157 , V_155 ) ;
V_16 -> V_48 =
F_100 ( V_158 , V_155 ) ;
F_26 ( V_16 ) ;
if ( V_16 -> V_46 != 0 ||
V_16 -> V_48 != 0 )
F_22 ( L_33 ) ;
}
V_59 -> V_108 = true ;
F_101 () ;
F_87 ( F_92 , ( void * ) V_39 , 1 ) ;
if ( F_75 ( V_59 -> V_117 , 0 , ( V_118 ) & V_115 ,
sizeof( V_115 ) , V_159 ) < 0 )
F_22 ( L_34 ) ;
F_102 ( V_39 ) ;
return 0 ;
}
static void F_103 ( struct V_160 * V_161 )
{
struct V_162 * V_163 =
F_104 ( V_161 , struct V_162 , V_107 ) ;
struct V_58 * V_59 =
F_104 ( V_163 , struct V_58 , V_164 ) ;
if ( F_94 ( V_59 -> V_39 ) != 0 )
F_105 ( & V_59 -> V_164 ,
V_165 ) ;
else
F_106 ( V_59 -> V_39 ) ;
}
static int F_107 ( struct V_56 * V_39 )
{
int V_114 = 0 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
if ( ! V_59 -> V_150 ) {
int V_9 ;
int V_166 ;
V_114 = F_67 ( V_39 ) ;
if ( V_114 < 0 ) {
F_69 ( L_35 , V_114 ) ;
return V_114 ;
}
if ( V_167 )
F_108 ( & V_59 -> V_131 ,
& V_131 ) ;
else
F_108 ( & V_59 -> V_131 , V_168 ) ;
V_9 = F_109 ( & V_59 -> V_131 ) ;
V_166 = F_110 ( 16 , ( V_158 / V_9 ) & ~ 1 ) ;
V_166 = F_100 ( V_169 , V_166 ) ;
V_59 -> V_156 = V_9 ;
V_59 -> V_134 = V_166 ;
#ifdef F_38
F_6 ( L_36 ,
V_59 -> V_156 , V_59 -> V_134 ) ;
#endif
V_59 -> V_150 = true ;
} else {
}
V_114 = F_94 ( V_39 ) ;
if ( V_114 <= 0 ) {
if ( V_114 == 0 )
F_106 ( V_39 ) ;
return V_114 ;
}
F_111 ( V_39 ) ;
F_105 ( & V_59 -> V_164 , V_165 ) ;
return 0 ;
}
static int F_112 ( struct V_58 * V_59 )
{
int V_53 = 0 ;
while ( true ) {
unsigned int V_27 ;
if ( F_68 ( V_59 -> V_117 , 0 , ( V_118 ) & V_27 ,
sizeof( V_27 ) , V_170 ) < 0 )
break;
if ( V_27 == 0 )
break;
{
void * V_25 = F_42 ( ( V_83 ) ( V_27 >> 1 ) << 7 ) ;
struct V_35 * * V_37 = V_25 - sizeof( * V_37 ) ;
struct V_35 * V_36 = * V_37 ;
F_33 ( V_36 ) ;
}
V_53 ++ ;
}
return V_53 ;
}
static int F_113 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_78 ( L_37 ) ;
V_59 -> V_108 = false ;
F_101 () ;
F_87 ( F_83 , ( void * ) V_39 , 1 ) ;
( void ) F_112 ( V_59 ) ;
F_114 ( & V_59 -> V_164 ) ;
F_115 ( V_39 ) ;
F_87 ( F_90 , ( void * ) V_39 , 1 ) ;
if ( F_112 ( V_59 ) != 0 )
F_82 ( L_38 ) ;
F_86 ( V_39 ) ;
while ( F_29 ( V_39 , true ) )
;
memset ( V_59 -> V_49 , 0 , sizeof( T_5 ) ) ;
F_101 () ;
return 0 ;
}
static unsigned int F_116 ( T_12 * V_171 ,
struct V_35 * V_36 ,
void * V_172 , unsigned int V_173 )
{
unsigned int V_2 , V_53 = 0 ;
struct V_174 * V_175 = F_117 ( V_36 ) ;
V_83 V_176 ;
if ( V_173 != 0 ) {
if ( ! V_41 )
F_118 ( V_172 , V_173 , 0 ) ;
V_176 = F_11 ( V_172 ) ;
V_171 [ V_53 ] . V_177 = V_176 ;
V_171 [ V_53 ] . V_178 = V_176 >> 32 ;
V_171 [ V_53 ] . V_6 = V_173 ;
V_171 [ V_53 ] . V_179 = V_41 ;
V_53 ++ ;
}
for ( V_2 = 0 ; V_2 < V_175 -> V_180 ; V_2 ++ ) {
T_13 * V_181 = & V_175 -> V_171 [ V_2 ] ;
unsigned long V_182 = F_119 ( F_120 ( V_181 ) ) ;
int V_179 = V_41 ;
if ( ! V_41 ) {
void * V_25 = F_121 ( V_182 ) + V_181 -> V_183 ;
F_16 ( F_122 ( F_120 ( V_181 ) ) ) ;
F_118 ( V_25 , F_123 ( V_181 ) , 0 ) ;
}
V_176 = ( ( V_83 ) V_182 << V_184 ) + V_181 -> V_183 ;
V_171 [ V_53 ] . V_177 = V_176 ;
V_171 [ V_53 ] . V_178 = V_176 >> 32 ;
V_171 [ V_53 ] . V_6 = F_123 ( V_181 ) ;
V_171 [ V_53 ] . V_179 = V_179 ;
V_53 ++ ;
}
return V_53 ;
}
static int F_124 ( struct V_35 * V_36 , struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
struct V_87 * V_88 = & V_16 -> V_88 ;
struct V_174 * V_175 = F_117 ( V_36 ) ;
unsigned char * V_5 = V_36 -> V_5 ;
struct V_185 * V_186 = F_125 ( V_36 ) ;
unsigned int V_187 = V_186 -> V_188 * 4 ;
unsigned char * V_189 = F_126 ( V_36 ) ;
unsigned int V_190 = V_189 - V_5 ;
struct V_191 * V_192 = (struct V_191 * ) ( V_189 + V_187 ) ;
unsigned int V_193 = V_192 -> V_194 * 4 ;
unsigned int V_195 = V_190 + V_187 + V_193 ;
unsigned int V_173 = F_127 ( V_36 ) - V_195 ;
unsigned int V_196 = V_173 + V_36 -> V_197 ;
unsigned int V_198 = V_175 -> V_199 ;
unsigned int V_200 = V_175 -> V_201 ;
T_2 V_202 [ ( V_203 + 3 ) / 4 ] ;
T_14 * V_204 = ( T_14 * ) V_202 ;
unsigned int V_205 =
F_116 ( V_204 -> V_171 , V_36 , V_5 + V_195 , V_173 ) ;
T_15 V_206 = F_128 ( V_205 , V_195 ) ;
T_14 V_207 = {
. V_208 = true ,
. V_209 = V_195 ,
. V_210 = V_190 ,
. V_211 = V_190 + V_187 ,
. V_212 = V_198 ,
. V_205 = V_205 ,
} ;
unsigned long V_213 ;
T_5 * V_49 = V_59 -> V_49 ;
struct V_35 * V_60 [ 8 ] ;
unsigned int V_61 = 8 ;
unsigned int V_2 , V_214 = 0 ;
unsigned int V_215 , V_216 , V_217 ;
unsigned int V_64 ;
F_16 ( V_36 -> V_100 != F_129 ( V_218 ) ) ;
F_16 ( V_186 -> V_100 != V_219 ) ;
F_16 ( V_36 -> V_101 != V_220 ) ;
F_16 ( V_205 > V_221 ) ;
F_16 ( V_200 <= 1 ) ;
* V_204 = V_207 ;
memcpy ( & V_204 -> V_171 [ V_205 ] , V_5 , V_195 ) ;
F_130 ( & V_49 -> V_64 ) ;
F_130 ( & V_49 -> V_216 ) ;
F_101 () ;
F_131 ( & V_59 -> V_63 , V_213 ) ;
if ( F_132 ( V_49 ) == 0 ) {
V_214 = F_27 ( V_49 , V_60 , V_61 , 0 ) ;
if ( V_214 == 0 ) {
V_222:
F_133 ( & V_59 -> V_63 , V_213 ) ;
return V_223 ;
}
}
V_215 = V_49 -> V_215 ;
V_216 = V_49 -> V_216 ;
V_217 = V_216 + V_206 ;
if ( V_216 < V_215 && V_217 >= V_215 )
goto V_222;
if ( V_217 > V_224 ) {
V_217 = 0 ;
if ( V_217 == V_215 )
goto V_222;
}
memcpy ( & V_49 -> V_225 [ V_216 ] , V_204 , V_206 ) ;
V_216 = V_217 ;
V_64 = V_49 -> V_64 ;
V_49 -> V_50 [ V_64 ] = V_36 ;
F_28 ( V_64 ) ;
V_49 -> V_64 = V_64 ;
F_25 () ;
V_49 -> V_216 = V_216 ;
if ( V_214 == 0 )
V_214 = F_27 ( V_49 , V_60 , V_61 , 4 ) ;
F_133 ( & V_59 -> V_63 , V_213 ) ;
for ( V_2 = 0 ; V_2 < V_214 ; V_2 ++ )
F_33 ( V_60 [ V_2 ] ) ;
V_88 -> V_226 += V_200 ;
V_88 -> V_227 += ( V_200 * V_195 ) + V_196 ;
F_34 ( V_16 ) ;
return V_228 ;
}
static int F_134 ( struct V_35 * V_36 , struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_85 [ V_8 ] ;
struct V_87 * V_88 = & V_16 -> V_88 ;
unsigned long V_213 ;
struct V_174 * V_175 = F_117 ( V_36 ) ;
unsigned int V_3 = V_36 -> V_3 ;
unsigned char * V_5 = V_36 -> V_5 ;
unsigned int V_229 = F_135 ( V_36 ) ;
T_12 V_171 [ V_221 ] ;
unsigned int V_205 ;
T_5 * V_49 = V_59 -> V_49 ;
struct V_35 * V_60 [ 8 ] ;
unsigned int V_61 = 8 ;
unsigned int V_2 , V_214 = 0 ;
unsigned int V_206 = sizeof( V_230 ) ;
unsigned int V_215 , V_216 , V_217 ;
unsigned int V_64 ;
V_230 V_225 [ V_221 ] ;
if ( ! V_16 -> V_147 )
return V_223 ;
V_39 -> V_231 = V_67 ;
#ifdef F_18
#if F_19 ()
if ( V_41 ) {
T_4 V_42 = * F_20 ( V_43 -> V_44 , ( unsigned long ) V_5 ) ;
if ( F_21 ( V_42 ) != V_45 )
F_22 ( L_39 ,
V_5 , F_21 ( V_42 ) , F_23 ( V_42 ) ) ;
}
#endif
#endif
#ifdef F_47
F_5 ( V_5 , F_127 ( V_36 ) , L_40 ) ;
#endif
if ( V_175 -> V_199 != 0 )
return F_124 ( V_36 , V_39 ) ;
V_205 = F_116 ( V_171 , V_36 , V_5 , F_127 ( V_36 ) ) ;
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
if ( V_2 == 0 && V_36 -> V_101 == V_220 ) {
V_204 . V_235 = 1 ;
V_204 . V_236 . V_237 . V_238 = V_229 ;
V_204 . V_236 . V_237 . V_9 = V_3 - V_229 ;
V_204 . V_236 . V_237 . V_239 =
V_229 + V_36 -> V_240 ;
}
V_225 [ V_2 ] = V_204 ;
}
F_130 ( & V_49 -> V_64 ) ;
F_130 ( & V_49 -> V_216 ) ;
F_101 () ;
F_131 ( & V_59 -> V_63 , V_213 ) ;
if ( F_132 ( V_49 ) == 0 ) {
V_214 = F_27 ( V_49 , V_60 , V_61 , 0 ) ;
if ( V_214 == 0 ) {
V_222:
F_133 ( & V_59 -> V_63 , V_213 ) ;
return V_223 ;
}
}
V_215 = V_49 -> V_215 ;
V_216 = V_49 -> V_216 ;
for ( V_2 = 0 ; V_2 < V_205 ; V_2 ++ ) {
V_217 = V_216 + V_206 ;
if ( V_216 < V_215 && V_217 >= V_215 )
goto V_222;
if ( V_217 > V_224 ) {
V_217 = 0 ;
if ( V_217 == V_215 )
goto V_222;
}
* ( V_230 * ) & V_49 -> V_225 [ V_216 ] = V_225 [ V_2 ] ;
V_216 = V_217 ;
}
V_64 = V_49 -> V_64 ;
V_49 -> V_50 [ V_64 ] = V_36 ;
F_28 ( V_64 ) ;
V_49 -> V_64 = V_64 ;
F_25 () ;
V_49 -> V_216 = V_216 ;
if ( V_214 == 0 )
V_214 = F_27 ( V_49 , V_60 , V_61 , 4 ) ;
F_133 ( & V_59 -> V_63 , V_213 ) ;
for ( V_2 = 0 ; V_2 < V_214 ; V_2 ++ )
F_33 ( V_60 [ V_2 ] ) ;
V_88 -> V_226 ++ ;
V_88 -> V_227 += ( ( V_3 >= V_241 ) ? V_3 : V_241 ) ;
F_34 ( V_16 ) ;
return V_228 ;
}
static void F_136 ( struct V_56 * V_39 )
{
F_78 ( L_41 ) ;
F_78 ( L_42 , V_67 ,
V_67 - V_39 -> V_231 ) ;
F_137 ( V_39 ) ;
}
static int F_138 ( struct V_56 * V_39 , struct V_242 * V_243 , int V_204 )
{
return - V_244 ;
}
static struct V_245 * F_139 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
T_2 V_103 = 0 ;
T_2 V_226 = 0 ;
T_2 V_104 = 0 ;
T_2 V_227 = 0 ;
int V_2 ;
F_88 (i) {
if ( V_59 -> V_85 [ V_2 ] ) {
V_103 += V_59 -> V_85 [ V_2 ] -> V_88 . V_103 ;
V_104 += V_59 -> V_85 [ V_2 ] -> V_88 . V_104 ;
V_226 += V_59 -> V_85 [ V_2 ] -> V_88 . V_226 ;
V_227 += V_59 -> V_85 [ V_2 ] -> V_88 . V_227 ;
}
}
V_59 -> V_88 . V_103 = V_103 ;
V_59 -> V_88 . V_104 = V_104 ;
V_59 -> V_88 . V_226 = V_226 ;
V_59 -> V_88 . V_227 = V_227 ;
return & V_59 -> V_88 ;
}
static int F_140 ( struct V_56 * V_39 , int V_246 )
{
F_78 ( L_43 ) ;
if ( ( V_246 < 68 ) || ( V_246 > 1500 ) )
return - V_247 ;
V_39 -> V_248 = V_246 ;
return 0 ;
}
static int F_141 ( struct V_56 * V_39 , void * V_249 )
{
struct V_250 * V_251 = V_249 ;
if ( ! F_142 ( V_251 -> V_252 ) )
return - V_253 ;
memcpy ( V_39 -> V_99 , V_251 -> V_252 , V_39 -> V_254 ) ;
V_39 -> V_255 &= ~ V_256 ;
return 0 ;
}
static int F_143 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
char V_257 [ 32 ] ;
int V_3 ;
T_16 V_258 = { . V_82 = V_259 } ;
int V_114 ;
strcpy ( V_257 , V_39 -> V_136 ) ;
V_3 = strlen ( V_257 ) ;
V_257 [ V_3 ] = V_257 [ V_3 - 1 ] ;
V_257 [ V_3 - 1 ] = '/' ;
V_3 ++ ;
strcpy ( V_257 + V_3 , V_41 ? L_44 : L_45 ) ;
V_59 -> V_117 = F_144 ( ( V_118 ) V_257 , 0 ) ;
F_78 ( L_46 ,
V_257 , V_59 -> V_117 , & V_59 -> V_117 ) ;
if ( V_59 -> V_117 < 0 ) {
if ( V_59 -> V_117 == V_260 )
F_82 ( V_144 L_47 ,
V_257 ) ;
else
F_82 ( V_144 L_48 ,
V_257 , V_59 -> V_117 ) ;
return - 1 ;
}
V_258 . V_237 . V_261 = V_262 ;
V_258 . V_237 . V_251 = V_263 ;
V_114 = F_68 ( V_59 -> V_117 , 0 ,
( V_118 ) V_39 -> V_99 , V_39 -> V_254 ,
V_258 . V_82 ) ;
F_78 ( L_49 , V_114 ) ;
if ( V_114 <= 0 ) {
F_82 ( V_144 L_50 ,
V_39 -> V_136 ) ;
F_145 ( V_39 ) ;
}
return 0 ;
}
static void F_146 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_65 ( V_59 -> V_110 ) ;
F_64 ( V_59 -> V_110 , V_39 ) ;
F_62 ( V_59 -> V_110 , 0 ) ;
}
static void F_147 ( struct V_56 * V_39 )
{
F_78 ( L_51 ) ;
F_148 ( V_39 ) ;
V_39 -> V_264 = & V_265 ;
V_39 -> V_266 = V_267 ;
V_39 -> V_268 |= V_269 ;
V_39 -> V_268 |= V_270 ;
V_39 -> V_268 |= V_271 ;
V_39 -> V_268 |= V_272 ;
#ifdef F_149
V_39 -> V_268 |= V_273 ;
#endif
if ( V_41 )
V_39 -> V_268 |= V_274 ;
V_39 -> V_275 = V_276 ;
V_39 -> V_248 = V_28 ;
}
static struct V_56 * F_150 ( const char * V_136 )
{
int V_114 ;
struct V_56 * V_39 ;
struct V_58 * V_59 ;
V_39 = F_151 ( sizeof( * V_59 ) , V_136 , F_147 ) ;
if ( ! V_39 ) {
F_69 ( L_52 , V_136 ) ;
return NULL ;
}
V_59 = F_30 ( V_39 ) ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_39 = V_39 ;
F_152 ( & V_59 -> V_164 , F_103 ) ;
F_153 ( & V_59 -> V_63 ) ;
V_59 -> V_122 = F_154 ( V_277 | V_278 , V_123 ) ;
if ( ! V_59 -> V_122 ) {
F_155 ( V_39 ) ;
return NULL ;
}
V_59 -> V_49 = F_156 ( V_59 -> V_122 ) ;
V_114 = F_157 ( V_39 ) ;
if ( V_114 ) {
F_69 ( L_53 , V_39 -> V_136 , V_114 ) ;
F_158 ( V_59 -> V_122 , V_123 ) ;
F_155 ( V_39 ) ;
return NULL ;
}
V_114 = F_143 ( V_39 ) ;
if ( V_114 < 0 ) {
F_159 ( V_39 ) ;
F_158 ( V_59 -> V_122 , V_123 ) ;
F_155 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
static void F_160 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_279 ; V_2 ++ ) {
if ( V_280 [ V_2 ] ) {
struct V_56 * V_39 = V_280 [ V_2 ] ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_159 ( V_39 ) ;
F_118 ( V_59 -> V_49 , V_127 , 0 ) ;
F_158 ( V_59 -> V_122 , V_123 ) ;
F_155 ( V_39 ) ;
}
}
}
static int F_161 ( void )
{
F_6 ( L_54 ) ;
V_280 [ 0 ] = F_150 ( L_20 ) ;
V_280 [ 1 ] = F_150 ( L_21 ) ;
V_280 [ 2 ] = F_150 ( L_22 ) ;
V_280 [ 3 ] = F_150 ( L_23 ) ;
return 0 ;
}
static int T_17 F_162 ( char * V_281 )
{
int V_282 = F_163 ( V_281 , & V_131 ) ;
if ( V_282 != 0 ) {
F_51 ( L_55 ,
V_281 ) ;
} else {
F_164 ( & V_131 , & V_131 ,
V_283 ) ;
if ( F_165 ( & V_131 ) ) {
F_51 ( L_56 ,
V_281 ) ;
} else {
char V_4 [ 1024 ] ;
F_166 ( V_4 , sizeof( V_4 ) , & V_131 ) ;
F_6 ( L_57 , V_4 ) ;
V_167 = true ;
}
}
return 0 ;
}
