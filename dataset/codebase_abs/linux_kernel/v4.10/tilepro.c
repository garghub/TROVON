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
static void F_37 ( struct V_15 * V_16 , int V_69 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_70 = V_18 -> V_71 ;
T_3 * V_19 = & V_18 -> V_20 ;
int V_72 = V_69 + sizeof( V_73 ) ;
int V_74 =
( ( V_72 ==
V_70 -> V_75 . V_76 ) ?
0 : V_72 ) ;
V_73 * V_77 = ( V_73 * ) ( ( unsigned long ) & V_70 [ 1 ] + V_69 ) ;
unsigned int V_27 = V_77 -> V_78 . V_79 ;
void * V_25 = F_38 ( ( V_80 ) ( V_27 >> 1 ) << 7 ) ;
struct V_35 * * V_37 = V_25 - sizeof( * V_37 ) ;
struct V_35 * V_36 = * V_37 ;
F_33 ( V_36 ) ;
V_19 -> V_81 = V_74 ;
}
static void F_39 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_70 = V_18 -> V_71 ;
T_3 * V_19 = & V_18 -> V_20 ;
while ( V_19 -> V_81 !=
V_70 -> V_75 . V_83 ) {
int V_69 = V_19 -> V_81 ;
F_37 ( V_16 , V_69 ) ;
}
}
static bool F_40 ( struct V_15 * V_16 , int V_69 )
{
struct V_56 * V_39 = V_16 -> V_38 . V_39 ;
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_70 = V_18 -> V_71 ;
T_3 * V_19 = & V_18 -> V_20 ;
struct V_84 * V_85 = & V_16 -> V_85 ;
int V_86 ;
int V_72 = V_69 + sizeof( V_73 ) ;
int V_74 =
( ( V_72 ==
V_70 -> V_75 . V_76 ) ?
0 : V_72 ) ;
V_73 * V_77 = ( V_73 * ) ( ( unsigned long ) & V_70 [ 1 ] + V_69 ) ;
T_7 * V_87 = F_41 ( V_77 ) ;
T_8 V_88 = F_42 ( V_87 , V_77 ) ;
unsigned long V_3 =
( F_43 ( V_77 ) +
V_30 - V_89 ) ;
unsigned int V_27 = V_77 -> V_78 . V_79 ;
bool V_26 = ( ( V_27 & 1 ) != 0 ) ;
void * V_25 = F_38 ( ( V_80 ) ( V_27 >> 1 ) << 7 ) ;
unsigned char * V_4 = V_25 + V_30 ;
if ( ! V_41 )
F_24 ( V_4 , V_3 ) ;
#ifdef F_44
F_5 ( V_4 , V_3 , L_9 ) ;
#endif
#ifdef F_45
if ( V_88 == V_90 && V_3 >= 64 ) {
F_5 ( V_4 , V_3 , L_9 ) ;
F_22 ( L_10 ) ;
}
#endif
V_86 = 0 ;
if ( V_88 == V_91 ) {
V_86 = 2 ;
} else if ( ! ( V_39 -> V_92 & V_93 ) ) {
V_86 = 1 ;
} else if ( F_46 ( V_87 , V_77 ) &&
V_88 == V_94 ) {
V_86 = 2 ;
} else if ( ! ( V_39 -> V_92 & V_95 ) ) {
if ( ! F_47 ( V_4 ) ) {
const T_9 * V_96 = V_39 -> V_97 ;
V_86 = ! F_48 ( V_96 , V_4 ) ;
}
}
F_49 ( & V_85 -> V_98 ) ;
if ( V_86 != 0 ) {
if ( V_86 == 1 )
V_85 -> V_99 ++ ;
else
V_85 -> V_100 ++ ;
F_10 ( V_16 , V_25 , V_26 ) ;
} else {
struct V_35 * * V_37 = V_25 - sizeof( * V_37 ) ;
struct V_35 * V_36 = * V_37 ;
if ( V_36 -> V_5 != V_4 )
F_22 ( L_11
L_12 ,
V_25 , V_36 , V_36 -> V_5 ) ;
F_50 ( V_36 , V_3 ) ;
V_36 -> V_101 = F_51 ( V_36 , V_39 ) ;
if ( F_52 ( V_87 , V_77 ) )
V_36 -> V_102 = V_103 ;
F_53 ( V_36 ) ;
V_85 -> V_104 ++ ;
V_85 -> V_105 += V_3 ;
}
F_54 ( & V_85 -> V_98 ) ;
F_8 ( V_16 ) ;
V_19 -> V_81 = V_74 ;
return ! V_86 ;
}
static int F_55 ( struct V_106 * V_38 , int V_107 )
{
struct V_56 * V_39 = V_38 -> V_39 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_70 = V_18 -> V_71 ;
T_3 * V_19 = & V_18 -> V_20 ;
unsigned int V_108 = 0 ;
if ( V_107 <= 0 )
goto V_109;
while ( V_59 -> V_110 ) {
int V_69 = V_19 -> V_81 ;
if ( V_69 == V_70 -> V_75 . V_83 )
break;
if ( F_40 ( V_16 , V_69 ) ) {
if ( ++ V_108 >= V_107 )
goto V_109;
}
}
F_56 ( & V_16 -> V_38 ) ;
if ( ! V_59 -> V_110 )
goto V_109;
F_57 ( V_59 -> V_111 , 0 ) ;
if ( V_19 -> V_81 !=
V_70 -> V_75 . V_83 ) {
( void ) F_58 ( & V_16 -> V_38 ) ;
}
V_109:
if ( V_59 -> V_110 )
F_26 ( V_16 ) ;
return V_108 ;
}
static T_10 F_59 ( int V_112 , void * V_113 )
{
struct V_56 * V_39 = (struct V_56 * ) V_113 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
F_60 ( V_59 -> V_111 ) ;
if ( ! V_59 -> V_110 )
return V_114 ;
F_61 ( & V_16 -> V_38 ) ;
return V_114 ;
}
static int F_62 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_115 ;
int V_116 ;
unsigned int V_117 ;
V_115 = F_63 ( V_59 -> V_118 , 0 ,
( V_119 ) & V_117 , sizeof( V_117 ) ,
V_120 ) ;
if ( V_115 < 0 ) {
F_64 ( L_13 ) ;
return - V_121 ;
}
{
int V_122 = F_65 ( V_117 ) ;
F_66 ( V_59 -> V_123 , V_124 , V_122 ) ;
}
{
T_11 V_125 = {
. V_25 = 0 ,
. V_126 = F_11 ( V_59 -> V_49 ) ,
. V_42 = F_67 ( 0 ) ,
. V_127 = V_128 ,
} ;
V_125 . V_42 = F_68 ( V_125 . V_42 , V_117 ) ;
V_125 . V_42 = F_69 ( V_125 . V_42 , V_129 ) ;
V_115 = F_70 ( V_59 -> V_118 , 0 ,
( V_119 ) & V_125 ,
sizeof( V_125 ) ,
V_120 ) ;
if ( V_115 < 0 )
return - V_121 ;
}
if ( F_70 ( V_59 -> V_118 , 0 , ( V_119 ) & V_116 ,
sizeof( V_116 ) , V_130 ) < 0 ) {
F_71 ( L_14 ) ;
return - V_121 ;
}
return 0 ;
}
static void F_72 ( void * V_113 )
{
struct V_56 * V_39 = (struct V_56 * ) V_113 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_131 =
F_73 ( V_8 , & V_59 -> V_132 ) ? 0 : 255 ;
T_12 V_133 = {
. V_92 = 0 ,
. V_134 = V_59 -> V_135 ,
. V_131 = V_131
} ;
int V_115 = 0 ;
T_6 * V_136 ;
F_74 ( L_15 , V_131 ) ;
if ( ! strcmp ( V_39 -> V_137 , L_16 ) )
V_16 = F_75 ( & V_138 ) ;
else if ( ! strcmp ( V_39 -> V_137 , L_17 ) )
V_16 = F_75 ( & V_139 ) ;
else if ( ! strcmp ( V_39 -> V_137 , L_18 ) )
V_16 = F_75 ( & V_140 ) ;
else if ( ! strcmp ( V_39 -> V_137 , L_19 ) )
V_16 = F_75 ( & V_141 ) ;
else
F_76 () ;
F_77 ( & V_16 -> V_66 ) ;
V_16 -> V_66 . V_5 = ( long ) V_16 ;
V_16 -> V_66 . V_142 = F_36 ;
F_78 ( & V_16 -> V_85 . V_98 ) ;
V_59 -> V_82 [ V_8 ] = V_16 ;
V_115 = F_70 ( V_59 -> V_118 , 0 ,
( V_119 ) & V_133 ,
sizeof( T_12 ) ,
V_143 ) ;
F_74 ( L_20 ,
V_115 ) ;
if ( V_115 < 0 ) {
if ( V_115 != V_144 ) {
F_79 ( V_145 L_21
L_22 ,
V_115 ) ;
}
V_16 -> V_146 = ( V_115 == V_144 ) ;
return;
}
V_115 = F_63 ( V_59 -> V_118 , 0 ,
( V_119 ) & V_136 ,
sizeof( T_6 * ) ,
V_143 ) ;
F_74 ( L_23 ,
V_115 ) ;
F_74 ( L_24 , V_136 ) ;
if ( V_115 <= 0 ) {
F_64 ( L_25 ) ;
return;
}
V_18 = & V_16 -> V_18 ;
V_18 -> V_71 = V_136 ;
memset ( & V_18 -> V_20 , 0 , sizeof( T_3 ) ) ;
V_18 -> V_20 . V_23 = 4 ;
V_18 -> V_20 . V_21 =
V_18 -> V_20 . V_23 ;
V_115 = F_63 ( V_59 -> V_118 , 0 ,
( V_119 ) & V_18 -> V_20 . V_24 ,
sizeof( V_18 -> V_20 . V_24 ) ,
V_147 ) ;
F_74 ( L_26 , V_115 ) ;
V_16 -> V_148 = true ;
}
static void F_80 ( void * V_113 )
{
struct V_56 * V_39 = (struct V_56 * ) V_113 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
F_60 ( V_59 -> V_111 ) ;
if ( V_16 == NULL || ! V_16 -> V_148 )
return;
{
struct V_17 * V_18 = & V_16 -> V_18 ;
T_3 * V_19 = & V_18 -> V_20 ;
F_9 ( V_19 -> V_24 , - 1 ) ;
}
}
static void F_81 ( void * V_113 )
{
struct V_56 * V_39 = (struct V_56 * ) V_113 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
int V_115 ;
int V_116 = 0 ;
F_60 ( V_59 -> V_111 ) ;
if ( V_16 == NULL || ! V_16 -> V_148 )
return;
V_115 = F_70 ( V_59 -> V_118 , 0 , ( V_119 ) & V_116 ,
sizeof( V_116 ) , V_149 ) ;
if ( V_115 < 0 )
F_22 ( L_27 ) ;
F_39 ( V_39 ) ;
V_16 -> V_46 = 0 ;
V_16 -> V_48 = 0 ;
F_82 ( & V_16 -> V_66 ) ;
V_16 -> V_65 = false ;
}
static void F_83 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_2 ;
int V_116 = 0 ;
F_84 ( F_81 , ( void * ) V_39 , 1 ) ;
F_85 (i) {
struct V_15 * V_16 = V_59 -> V_82 [ V_2 ] ;
if ( V_16 != NULL && V_16 -> V_148 ) {
F_86 ( & V_16 -> V_38 ) ;
V_16 -> V_148 = false ;
}
}
if ( F_70 ( V_59 -> V_118 , 0 , ( V_119 ) & V_116 ,
sizeof( V_116 ) , V_150 ) < 0 )
F_22 ( L_28 ) ;
V_59 -> V_151 = false ;
}
static void F_87 ( void * V_113 )
{
struct V_56 * V_39 = (struct V_56 * ) V_113 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
if ( V_16 != NULL && V_16 -> V_152 ) {
F_88 ( & V_16 -> V_38 ) ;
V_16 -> V_152 = false ;
}
}
static void F_89 ( void * V_113 )
{
struct V_56 * V_39 = (struct V_56 * ) V_113 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
F_90 ( & V_16 -> V_38 ) ;
V_16 -> V_152 = true ;
F_57 ( V_59 -> V_111 , 0 ) ;
}
static int F_91 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_12 = 0 ;
int V_2 ;
int V_116 = 0 ;
F_72 ( V_39 ) ;
V_16 = V_59 -> V_82 [ V_8 ] ;
if ( ! V_16 -> V_148 ) {
if ( V_16 -> V_146 )
return 1 ;
return - V_153 ;
}
F_92 ( F_72 , ( void * ) V_39 , 1 ) ;
F_85 (i) {
struct V_15 * V_16 = V_59 -> V_82 [ V_2 ] ;
if ( V_16 -> V_148 )
F_93 ( V_39 , & V_16 -> V_38 , F_55 , 64 ) ;
else
V_12 = - V_153 ;
}
if ( V_12 != 0 ) {
F_83 ( V_39 ) ;
return V_12 ;
}
V_18 = & V_16 -> V_18 ;
if ( V_59 -> V_111 == 0 ) {
unsigned int V_112 ;
V_59 -> V_111 = V_18 -> V_71 -> V_154 ;
F_16 ( V_59 -> V_111 == 0 ) ;
V_112 = F_94 ( V_59 -> V_111 ) ;
F_95 ( V_112 , V_155 ) ;
F_16 ( F_96 ( V_112 , F_59 ,
0 , V_39 -> V_137 , ( void * ) V_39 ) != 0 ) ;
}
{
int V_156 =
V_59 -> V_157 * V_59 -> V_135 ;
V_16 -> V_46 =
F_97 ( V_158 , V_156 ) ;
V_16 -> V_48 =
F_97 ( V_159 , V_156 ) ;
F_26 ( V_16 ) ;
if ( V_16 -> V_46 != 0 ||
V_16 -> V_48 != 0 )
F_22 ( L_29 ) ;
}
V_59 -> V_110 = true ;
F_98 () ;
F_84 ( F_89 , ( void * ) V_39 , 1 ) ;
if ( F_70 ( V_59 -> V_118 , 0 , ( V_119 ) & V_116 ,
sizeof( V_116 ) , V_160 ) < 0 )
F_22 ( L_30 ) ;
F_99 ( V_39 ) ;
return 0 ;
}
static void F_100 ( struct V_161 * V_162 )
{
struct V_163 * V_164 = F_101 ( V_162 ) ;
struct V_58 * V_59 =
F_102 ( V_164 , struct V_58 , V_165 ) ;
if ( F_91 ( V_59 -> V_39 ) != 0 )
F_103 ( & V_59 -> V_165 ,
V_166 ) ;
else
F_104 ( V_59 -> V_39 ) ;
}
static int F_105 ( struct V_56 * V_39 )
{
int V_115 = 0 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
if ( ! V_59 -> V_151 ) {
int V_9 ;
int V_167 ;
V_115 = F_62 ( V_39 ) ;
if ( V_115 < 0 ) {
F_64 ( L_31 , V_115 ) ;
return V_115 ;
}
if ( V_168 )
F_106 ( & V_59 -> V_132 ,
& V_132 ) ;
else
F_106 ( & V_59 -> V_132 , V_169 ) ;
V_9 = F_107 ( & V_59 -> V_132 ) ;
V_167 = F_108 ( 16 , ( V_159 / V_9 ) & ~ 1 ) ;
V_167 = F_97 ( V_170 , V_167 ) ;
V_59 -> V_157 = V_9 ;
V_59 -> V_135 = V_167 ;
#ifdef F_109
F_6 ( L_32 ,
V_59 -> V_157 , V_59 -> V_135 ) ;
#endif
V_59 -> V_151 = true ;
} else {
}
V_115 = F_91 ( V_39 ) ;
if ( V_115 <= 0 ) {
if ( V_115 == 0 )
F_104 ( V_39 ) ;
return V_115 ;
}
F_110 ( V_39 ) ;
F_103 ( & V_59 -> V_165 , V_166 ) ;
return 0 ;
}
static int F_111 ( struct V_58 * V_59 )
{
int V_53 = 0 ;
while ( true ) {
unsigned int V_27 ;
if ( F_63 ( V_59 -> V_118 , 0 , ( V_119 ) & V_27 ,
sizeof( V_27 ) , V_171 ) < 0 )
break;
if ( V_27 == 0 )
break;
{
void * V_25 = F_38 ( ( V_80 ) ( V_27 >> 1 ) << 7 ) ;
struct V_35 * * V_37 = V_25 - sizeof( * V_37 ) ;
struct V_35 * V_36 = * V_37 ;
F_33 ( V_36 ) ;
}
V_53 ++ ;
}
return V_53 ;
}
static int F_112 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_74 ( L_33 ) ;
V_59 -> V_110 = false ;
F_98 () ;
F_84 ( F_80 , ( void * ) V_39 , 1 ) ;
( void ) F_111 ( V_59 ) ;
F_113 ( & V_59 -> V_165 ) ;
F_114 ( V_39 ) ;
F_84 ( F_87 , ( void * ) V_39 , 1 ) ;
if ( F_111 ( V_59 ) != 0 )
F_79 ( L_34 ) ;
F_83 ( V_39 ) ;
while ( F_29 ( V_39 , true ) )
;
memset ( V_59 -> V_49 , 0 , sizeof( T_5 ) ) ;
F_98 () ;
return 0 ;
}
static unsigned int F_115 ( T_13 * V_172 ,
struct V_35 * V_36 ,
void * V_173 , unsigned int V_174 )
{
unsigned int V_2 , V_53 = 0 ;
struct V_175 * V_176 = F_116 ( V_36 ) ;
V_80 V_177 ;
if ( V_174 != 0 ) {
if ( ! V_41 )
F_117 ( V_173 , V_174 , 0 ) ;
V_177 = F_11 ( V_173 ) ;
V_172 [ V_53 ] . V_178 = V_177 ;
V_172 [ V_53 ] . V_179 = V_177 >> 32 ;
V_172 [ V_53 ] . V_6 = V_174 ;
V_172 [ V_53 ] . V_180 = V_41 ;
V_53 ++ ;
}
for ( V_2 = 0 ; V_2 < V_176 -> V_181 ; V_2 ++ ) {
T_14 * V_182 = & V_176 -> V_172 [ V_2 ] ;
unsigned long V_183 = F_118 ( F_119 ( V_182 ) ) ;
int V_180 = V_41 ;
if ( ! V_41 ) {
void * V_25 = F_120 ( V_183 ) + V_182 -> V_184 ;
F_16 ( F_121 ( F_119 ( V_182 ) ) ) ;
F_117 ( V_25 , F_122 ( V_182 ) , 0 ) ;
}
V_177 = ( ( V_80 ) V_183 << V_185 ) + V_182 -> V_184 ;
V_172 [ V_53 ] . V_178 = V_177 ;
V_172 [ V_53 ] . V_179 = V_177 >> 32 ;
V_172 [ V_53 ] . V_6 = F_122 ( V_182 ) ;
V_172 [ V_53 ] . V_180 = V_180 ;
V_53 ++ ;
}
return V_53 ;
}
static int F_123 ( struct V_35 * V_36 , struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
struct V_84 * V_85 = & V_16 -> V_85 ;
struct V_175 * V_176 = F_116 ( V_36 ) ;
unsigned char * V_5 = V_36 -> V_5 ;
struct V_186 * V_187 = F_124 ( V_36 ) ;
unsigned int V_188 = V_187 -> V_189 * 4 ;
unsigned char * V_190 = F_125 ( V_36 ) ;
unsigned int V_191 = V_190 - V_5 ;
struct V_192 * V_193 = (struct V_192 * ) ( V_190 + V_188 ) ;
unsigned int V_194 = V_193 -> V_195 * 4 ;
unsigned int V_196 = V_191 + V_188 + V_194 ;
unsigned int V_174 = F_126 ( V_36 ) - V_196 ;
unsigned int V_197 = V_174 + V_36 -> V_198 ;
unsigned int V_199 = V_176 -> V_200 ;
unsigned int V_201 = V_176 -> V_202 ;
T_2 V_203 [ ( V_204 + 3 ) / 4 ] ;
T_15 * V_205 = ( T_15 * ) V_203 ;
unsigned int V_206 =
F_115 ( V_205 -> V_172 , V_36 , V_5 + V_196 , V_174 ) ;
T_16 V_207 = F_127 ( V_206 , V_196 ) ;
T_15 V_208 = {
. V_209 = true ,
. V_210 = V_196 ,
. V_211 = V_191 ,
. V_212 = V_191 + V_188 ,
. V_213 = V_199 ,
. V_206 = V_206 ,
} ;
unsigned long V_214 ;
T_5 * V_49 = V_59 -> V_49 ;
struct V_35 * V_60 [ 8 ] ;
unsigned int V_61 = 8 ;
unsigned int V_2 , V_215 = 0 ;
unsigned int V_216 , V_217 , V_218 ;
unsigned int V_64 ;
F_16 ( V_36 -> V_101 != F_128 ( V_219 ) ) ;
F_16 ( V_187 -> V_101 != V_220 ) ;
F_16 ( V_36 -> V_102 != V_221 ) ;
F_16 ( V_206 > V_222 ) ;
F_16 ( V_201 <= 1 ) ;
* V_205 = V_208 ;
memcpy ( & V_205 -> V_172 [ V_206 ] , V_5 , V_196 ) ;
F_129 ( & V_49 -> V_64 ) ;
F_129 ( & V_49 -> V_217 ) ;
F_98 () ;
F_130 ( & V_59 -> V_63 , V_214 ) ;
if ( F_131 ( V_49 ) == 0 ) {
V_215 = F_27 ( V_49 , V_60 , V_61 , 0 ) ;
if ( V_215 == 0 ) {
V_223:
F_132 ( & V_59 -> V_63 , V_214 ) ;
return V_224 ;
}
}
V_216 = V_49 -> V_216 ;
V_217 = V_49 -> V_217 ;
V_218 = V_217 + V_207 ;
if ( V_217 < V_216 && V_218 >= V_216 )
goto V_223;
if ( V_218 > V_225 ) {
V_218 = 0 ;
if ( V_218 == V_216 )
goto V_223;
}
memcpy ( & V_49 -> V_226 [ V_217 ] , V_205 , V_207 ) ;
V_217 = V_218 ;
V_64 = V_49 -> V_64 ;
V_49 -> V_50 [ V_64 ] = V_36 ;
F_28 ( V_64 ) ;
V_49 -> V_64 = V_64 ;
F_25 () ;
V_49 -> V_217 = V_217 ;
if ( V_215 == 0 )
V_215 = F_27 ( V_49 , V_60 , V_61 , 4 ) ;
F_132 ( & V_59 -> V_63 , V_214 ) ;
for ( V_2 = 0 ; V_2 < V_215 ; V_2 ++ )
F_133 ( V_60 [ V_2 ] ) ;
F_49 ( & V_85 -> V_98 ) ;
V_85 -> V_227 += V_201 ;
V_85 -> V_228 += ( V_201 * V_196 ) + V_197 ;
F_54 ( & V_85 -> V_98 ) ;
F_34 ( V_16 ) ;
return V_229 ;
}
static int F_134 ( struct V_35 * V_36 , struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
struct V_84 * V_85 = & V_16 -> V_85 ;
unsigned long V_214 ;
struct V_175 * V_176 = F_116 ( V_36 ) ;
unsigned int V_3 = V_36 -> V_3 ;
unsigned char * V_5 = V_36 -> V_5 ;
unsigned int V_230 = F_135 ( V_36 ) ;
T_13 V_172 [ 1 + V_231 ] ;
unsigned int V_206 ;
T_5 * V_49 = V_59 -> V_49 ;
struct V_35 * V_60 [ 8 ] ;
unsigned int V_61 = 8 ;
unsigned int V_2 , V_215 = 0 ;
unsigned int V_207 = sizeof( V_232 ) ;
unsigned int V_216 , V_217 , V_218 ;
unsigned int V_64 ;
V_232 V_226 [ 1 + V_231 ] ;
if ( ! V_16 -> V_148 )
return V_224 ;
F_136 ( V_39 ) ;
#ifdef F_18
#if F_19 ()
if ( V_41 ) {
T_4 V_42 = * F_20 ( V_43 -> V_44 , ( unsigned long ) V_5 ) ;
if ( F_21 ( V_42 ) != V_45 )
F_22 ( L_35 ,
V_5 , F_21 ( V_42 ) , F_23 ( V_42 ) ) ;
}
#endif
#endif
#ifdef F_44
F_5 ( V_5 , F_126 ( V_36 ) , L_36 ) ;
#endif
if ( V_176 -> V_200 != 0 )
return F_123 ( V_36 , V_39 ) ;
V_206 = F_115 ( V_172 , V_36 , V_5 , F_126 ( V_36 ) ) ;
for ( V_2 = 0 ; V_2 < V_206 ; V_2 ++ ) {
bool V_233 = ( V_2 == V_206 - 1 ) ;
V_232 V_205 = {
. V_178 = V_172 [ V_2 ] . V_178 ,
. V_179 = V_172 [ V_2 ] . V_179 ,
. V_6 = V_172 [ V_2 ] . V_6 ,
. V_180 = V_172 [ V_2 ] . V_180 ,
. V_234 = V_233 ,
. V_235 = V_233
} ;
if ( V_2 == 0 && V_36 -> V_102 == V_221 ) {
V_205 . V_236 = 1 ;
V_205 . V_237 . V_238 . V_239 = V_230 ;
V_205 . V_237 . V_238 . V_9 = V_3 - V_230 ;
V_205 . V_237 . V_238 . V_240 =
V_230 + V_36 -> V_241 ;
}
V_226 [ V_2 ] = V_205 ;
}
F_129 ( & V_49 -> V_64 ) ;
F_129 ( & V_49 -> V_217 ) ;
F_98 () ;
F_130 ( & V_59 -> V_63 , V_214 ) ;
if ( F_131 ( V_49 ) == 0 ) {
V_215 = F_27 ( V_49 , V_60 , V_61 , 0 ) ;
if ( V_215 == 0 ) {
V_223:
F_132 ( & V_59 -> V_63 , V_214 ) ;
return V_224 ;
}
}
V_216 = V_49 -> V_216 ;
V_217 = V_49 -> V_217 ;
for ( V_2 = 0 ; V_2 < V_206 ; V_2 ++ ) {
V_218 = V_217 + V_207 ;
if ( V_217 < V_216 && V_218 >= V_216 )
goto V_223;
if ( V_218 > V_225 ) {
V_218 = 0 ;
if ( V_218 == V_216 )
goto V_223;
}
* ( V_232 * ) & V_49 -> V_226 [ V_217 ] = V_226 [ V_2 ] ;
V_217 = V_218 ;
}
V_64 = V_49 -> V_64 ;
V_49 -> V_50 [ V_64 ] = V_36 ;
F_28 ( V_64 ) ;
V_49 -> V_64 = V_64 ;
F_25 () ;
V_49 -> V_217 = V_217 ;
if ( V_215 == 0 )
V_215 = F_27 ( V_49 , V_60 , V_61 , 4 ) ;
F_132 ( & V_59 -> V_63 , V_214 ) ;
for ( V_2 = 0 ; V_2 < V_215 ; V_2 ++ )
F_133 ( V_60 [ V_2 ] ) ;
F_49 ( & V_85 -> V_98 ) ;
V_85 -> V_227 ++ ;
V_85 -> V_228 += ( ( V_3 >= V_242 ) ? V_3 : V_242 ) ;
F_54 ( & V_85 -> V_98 ) ;
F_34 ( V_16 ) ;
return V_229 ;
}
static void F_137 ( struct V_56 * V_39 )
{
F_74 ( L_37 ) ;
F_74 ( L_38 , V_67 ,
V_67 - F_138 ( V_39 ) ) ;
F_139 ( V_39 ) ;
}
static int F_140 ( struct V_56 * V_39 , struct V_243 * V_244 , int V_205 )
{
return - V_245 ;
}
static struct V_246 * F_141 ( struct V_56 * V_39 ,
struct V_246 * V_85 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
T_17 V_104 = 0 , V_227 = 0 ;
T_17 V_105 = 0 , V_228 = 0 ;
T_17 V_100 = 0 , V_99 = 0 ;
int V_2 ;
F_85 (i) {
struct V_84 * V_247 ;
T_17 V_248 , V_249 , V_250 , V_251 ;
T_17 V_252 , V_253 ;
unsigned int V_254 ;
if ( V_59 -> V_82 [ V_2 ] == NULL )
continue;
V_247 = & V_59 -> V_82 [ V_2 ] -> V_85 ;
do {
V_254 = F_142 ( & V_247 -> V_98 ) ;
V_248 = V_247 -> V_104 ;
V_249 = V_247 -> V_227 ;
V_250 = V_247 -> V_105 ;
V_251 = V_247 -> V_228 ;
V_252 = V_247 -> V_100 ;
V_253 = V_247 -> V_99 ;
} while ( F_143 ( & V_247 -> V_98 , V_254 ) );
V_104 += V_248 ;
V_227 += V_249 ;
V_105 += V_250 ;
V_228 += V_251 ;
V_100 += V_252 ;
V_99 += V_253 ;
}
V_85 -> V_104 = V_104 ;
V_85 -> V_227 = V_227 ;
V_85 -> V_105 = V_105 ;
V_85 -> V_228 = V_228 ;
V_85 -> V_100 = V_100 ;
V_85 -> V_99 = V_99 ;
return V_85 ;
}
static int F_144 ( struct V_56 * V_39 , void * V_255 )
{
struct V_256 * V_257 = V_255 ;
if ( ! F_145 ( V_257 -> V_258 ) )
return - V_259 ;
memcpy ( V_39 -> V_97 , V_257 -> V_258 , V_39 -> V_260 ) ;
return 0 ;
}
static int F_146 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
char V_261 [ 32 ] ;
int V_3 ;
T_18 V_262 = { . V_79 = V_263 } ;
int V_115 ;
strcpy ( V_261 , V_39 -> V_137 ) ;
V_3 = strlen ( V_261 ) ;
V_261 [ V_3 ] = V_261 [ V_3 - 1 ] ;
V_261 [ V_3 - 1 ] = '/' ;
V_3 ++ ;
strcpy ( V_261 + V_3 , V_41 ? L_39 : L_40 ) ;
V_59 -> V_118 = F_147 ( ( V_119 ) V_261 , 0 ) ;
F_74 ( L_41 ,
V_261 , V_59 -> V_118 , & V_59 -> V_118 ) ;
if ( V_59 -> V_118 < 0 ) {
if ( V_59 -> V_118 == V_264 )
F_79 ( V_145 L_42 ,
V_261 ) ;
else
F_79 ( V_145 L_43 ,
V_261 , V_59 -> V_118 ) ;
return - 1 ;
}
V_262 . V_238 . V_265 = V_266 ;
V_262 . V_238 . V_257 = V_267 ;
V_115 = F_63 ( V_59 -> V_118 , 0 ,
( V_119 ) V_39 -> V_97 , V_39 -> V_260 ,
V_262 . V_79 ) ;
F_74 ( L_44 , V_115 ) ;
if ( V_115 <= 0 ) {
F_79 ( V_145 L_45 ,
V_39 -> V_137 ) ;
F_148 ( V_39 ) ;
}
return 0 ;
}
static void F_149 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_60 ( V_59 -> V_111 ) ;
F_59 ( V_59 -> V_111 , V_39 ) ;
F_57 ( V_59 -> V_111 , 0 ) ;
}
static void F_150 ( struct V_56 * V_39 )
{
T_19 V_268 = 0 ;
F_151 ( V_39 ) ;
V_39 -> V_269 = & V_270 ;
V_39 -> V_271 = V_272 ;
V_39 -> V_273 = V_274 ;
V_39 -> V_275 = V_28 ;
V_39 -> V_276 = V_277 ;
V_39 -> V_278 = V_28 ;
V_268 |= V_279 ;
V_268 |= V_280 ;
if ( V_222 >= 1 + V_231 )
V_268 |= V_281 ;
if ( V_41 )
V_268 |= V_282 ;
V_39 -> V_283 |= V_268 ;
V_39 -> V_284 |= V_268 ;
V_39 -> V_268 |= V_268 ;
}
static struct V_56 * F_152 ( const char * V_137 )
{
int V_115 ;
struct V_56 * V_39 ;
struct V_58 * V_59 ;
V_39 = F_153 ( sizeof( * V_59 ) , V_137 , V_285 ,
F_150 ) ;
if ( ! V_39 ) {
F_64 ( L_46 , V_137 ) ;
return NULL ;
}
V_59 = F_30 ( V_39 ) ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_39 = V_39 ;
F_154 ( & V_59 -> V_165 , F_100 ) ;
F_155 ( & V_59 -> V_63 ) ;
V_59 -> V_123 = F_156 ( V_286 | V_287 , V_124 ) ;
if ( ! V_59 -> V_123 ) {
F_157 ( V_39 ) ;
return NULL ;
}
V_59 -> V_49 = F_158 ( V_59 -> V_123 ) ;
V_115 = F_159 ( V_39 ) ;
if ( V_115 ) {
F_64 ( L_47 , V_39 -> V_137 , V_115 ) ;
F_160 ( V_59 -> V_123 , V_124 ) ;
F_157 ( V_39 ) ;
return NULL ;
}
V_115 = F_146 ( V_39 ) ;
if ( V_115 < 0 ) {
F_161 ( V_39 ) ;
F_160 ( V_59 -> V_123 , V_124 ) ;
F_157 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
static void F_162 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_288 ; V_2 ++ ) {
if ( V_289 [ V_2 ] ) {
struct V_56 * V_39 = V_289 [ V_2 ] ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_161 ( V_39 ) ;
F_117 ( V_59 -> V_49 , V_128 , 0 ) ;
F_160 ( V_59 -> V_123 , V_124 ) ;
F_157 ( V_39 ) ;
}
}
}
static int F_163 ( void )
{
F_6 ( L_48 ) ;
V_289 [ 0 ] = F_152 ( L_16 ) ;
V_289 [ 1 ] = F_152 ( L_17 ) ;
V_289 [ 2 ] = F_152 ( L_18 ) ;
V_289 [ 3 ] = F_152 ( L_19 ) ;
return 0 ;
}
static int T_20 F_164 ( char * V_290 )
{
int V_291 = F_165 ( V_290 , & V_132 ) ;
if ( V_291 != 0 ) {
F_71 ( L_49 , V_290 ) ;
} else {
F_166 ( & V_132 , & V_132 ,
V_292 ) ;
if ( F_167 ( & V_132 ) ) {
F_71 ( L_50 , V_290 ) ;
} else {
F_6 ( L_51 ,
F_168 ( & V_132 ) ) ;
V_168 = true ;
}
}
return 0 ;
}
