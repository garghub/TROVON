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
V_39 -> V_90 = V_67 ;
#ifdef F_44
F_5 ( V_4 , V_3 , L_9 ) ;
#endif
#ifdef F_45
if ( V_88 == V_91 && V_3 >= 64 ) {
F_5 ( V_4 , V_3 , L_9 ) ;
F_22 ( L_10 ) ;
}
#endif
V_86 = 0 ;
if ( V_88 == V_92 ) {
V_86 = 2 ;
} else if ( ! ( V_39 -> V_93 & V_94 ) ) {
V_86 = 1 ;
} else if ( F_46 ( V_87 , V_77 ) &&
V_88 == V_95 ) {
V_86 = 2 ;
} else if ( ! ( V_39 -> V_93 & V_96 ) ) {
if ( ! F_47 ( V_4 ) ) {
const T_9 * V_97 = V_39 -> V_98 ;
V_86 = ! F_48 ( V_97 , V_4 ) ;
}
}
F_49 ( & V_85 -> V_99 ) ;
if ( V_86 != 0 ) {
if ( V_86 == 1 )
V_85 -> V_100 ++ ;
else
V_85 -> V_101 ++ ;
F_10 ( V_16 , V_25 , V_26 ) ;
} else {
struct V_35 * * V_37 = V_25 - sizeof( * V_37 ) ;
struct V_35 * V_36 = * V_37 ;
if ( V_36 -> V_5 != V_4 )
F_22 ( L_11
L_12 ,
V_25 , V_36 , V_36 -> V_5 ) ;
F_50 ( V_36 , V_3 ) ;
V_36 -> V_102 = F_51 ( V_36 , V_39 ) ;
if ( F_52 ( V_87 , V_77 ) )
V_36 -> V_103 = V_104 ;
F_53 ( V_36 ) ;
V_85 -> V_105 ++ ;
V_85 -> V_106 += V_3 ;
}
F_54 ( & V_85 -> V_99 ) ;
F_8 ( V_16 ) ;
V_19 -> V_81 = V_74 ;
return ! V_86 ;
}
static int F_55 ( struct V_107 * V_38 , int V_108 )
{
struct V_56 * V_39 = V_38 -> V_39 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
struct V_17 * V_18 = & V_16 -> V_18 ;
T_6 * V_70 = V_18 -> V_71 ;
T_3 * V_19 = & V_18 -> V_20 ;
unsigned int V_109 = 0 ;
if ( V_108 <= 0 )
goto V_110;
while ( V_59 -> V_111 ) {
int V_69 = V_19 -> V_81 ;
if ( V_69 == V_70 -> V_75 . V_83 )
break;
if ( F_40 ( V_16 , V_69 ) ) {
if ( ++ V_109 >= V_108 )
goto V_110;
}
}
F_56 ( & V_16 -> V_38 ) ;
if ( ! V_59 -> V_111 )
goto V_110;
F_57 ( V_59 -> V_112 , 0 ) ;
if ( V_19 -> V_81 !=
V_70 -> V_75 . V_83 ) {
( void ) F_58 ( & V_16 -> V_38 ) ;
}
V_110:
if ( V_59 -> V_111 )
F_26 ( V_16 ) ;
return V_109 ;
}
static T_10 F_59 ( int V_113 , void * V_114 )
{
struct V_56 * V_39 = (struct V_56 * ) V_114 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
F_60 ( V_59 -> V_112 ) ;
if ( ! V_59 -> V_111 )
return V_115 ;
F_61 ( & V_16 -> V_38 ) ;
return V_115 ;
}
static int F_62 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_116 ;
int V_117 ;
unsigned int V_118 ;
V_116 = F_63 ( V_59 -> V_119 , 0 ,
( V_120 ) & V_118 , sizeof( V_118 ) ,
V_121 ) ;
if ( V_116 < 0 ) {
F_64 ( L_13 ) ;
return - V_122 ;
}
{
int V_123 = F_65 ( V_118 ) ;
F_66 ( V_59 -> V_124 , V_125 , V_123 ) ;
}
{
T_11 V_126 = {
. V_25 = 0 ,
. V_127 = F_11 ( V_59 -> V_49 ) ,
. V_42 = F_67 ( 0 ) ,
. V_128 = V_129 ,
} ;
V_126 . V_42 = F_68 ( V_126 . V_42 , V_118 ) ;
V_126 . V_42 = F_69 ( V_126 . V_42 , V_130 ) ;
V_116 = F_70 ( V_59 -> V_119 , 0 ,
( V_120 ) & V_126 ,
sizeof( V_126 ) ,
V_121 ) ;
if ( V_116 < 0 )
return - V_122 ;
}
if ( F_70 ( V_59 -> V_119 , 0 , ( V_120 ) & V_117 ,
sizeof( V_117 ) , V_131 ) < 0 ) {
F_71 ( L_14 ) ;
return - V_122 ;
}
return 0 ;
}
static void F_72 ( void * V_114 )
{
struct V_56 * V_39 = (struct V_56 * ) V_114 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_132 =
F_73 ( V_8 , & V_59 -> V_133 ) ? 0 : 255 ;
T_12 V_134 = {
. V_93 = 0 ,
. V_135 = V_59 -> V_136 ,
. V_132 = V_132
} ;
int V_116 = 0 ;
T_6 * V_137 ;
F_74 ( L_15 , V_132 ) ;
if ( ! strcmp ( V_39 -> V_138 , L_16 ) )
V_16 = F_75 ( & V_139 ) ;
else if ( ! strcmp ( V_39 -> V_138 , L_17 ) )
V_16 = F_75 ( & V_140 ) ;
else if ( ! strcmp ( V_39 -> V_138 , L_18 ) )
V_16 = F_75 ( & V_141 ) ;
else if ( ! strcmp ( V_39 -> V_138 , L_19 ) )
V_16 = F_75 ( & V_142 ) ;
else
F_76 () ;
F_77 ( & V_16 -> V_66 ) ;
V_16 -> V_66 . V_5 = ( long ) V_16 ;
V_16 -> V_66 . V_143 = F_36 ;
F_78 ( & V_16 -> V_85 . V_99 ) ;
V_59 -> V_82 [ V_8 ] = V_16 ;
V_116 = F_70 ( V_59 -> V_119 , 0 ,
( V_120 ) & V_134 ,
sizeof( T_12 ) ,
V_144 ) ;
F_74 ( L_20 ,
V_116 ) ;
if ( V_116 < 0 ) {
if ( V_116 != V_145 ) {
F_79 ( V_146 L_21
L_22 ,
V_116 ) ;
}
V_16 -> V_147 = ( V_116 == V_145 ) ;
return;
}
V_116 = F_63 ( V_59 -> V_119 , 0 ,
( V_120 ) & V_137 ,
sizeof( T_6 * ) ,
V_144 ) ;
F_74 ( L_23 ,
V_116 ) ;
F_74 ( L_24 , V_137 ) ;
if ( V_116 <= 0 ) {
F_64 ( L_25 ) ;
return;
}
V_18 = & V_16 -> V_18 ;
V_18 -> V_71 = V_137 ;
memset ( & V_18 -> V_20 , 0 , sizeof( T_3 ) ) ;
V_18 -> V_20 . V_23 = 4 ;
V_18 -> V_20 . V_21 =
V_18 -> V_20 . V_23 ;
V_116 = F_63 ( V_59 -> V_119 , 0 ,
( V_120 ) & V_18 -> V_20 . V_24 ,
sizeof( V_18 -> V_20 . V_24 ) ,
V_148 ) ;
F_74 ( L_26 , V_116 ) ;
V_16 -> V_149 = true ;
}
static void F_80 ( void * V_114 )
{
struct V_56 * V_39 = (struct V_56 * ) V_114 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
F_60 ( V_59 -> V_112 ) ;
if ( V_16 == NULL || ! V_16 -> V_149 )
return;
{
struct V_17 * V_18 = & V_16 -> V_18 ;
T_3 * V_19 = & V_18 -> V_20 ;
F_9 ( V_19 -> V_24 , - 1 ) ;
}
}
static void F_81 ( void * V_114 )
{
struct V_56 * V_39 = (struct V_56 * ) V_114 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
int V_116 ;
int V_117 = 0 ;
F_60 ( V_59 -> V_112 ) ;
if ( V_16 == NULL || ! V_16 -> V_149 )
return;
V_116 = F_70 ( V_59 -> V_119 , 0 , ( V_120 ) & V_117 ,
sizeof( V_117 ) , V_150 ) ;
if ( V_116 < 0 )
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
int V_117 = 0 ;
F_84 ( F_81 , ( void * ) V_39 , 1 ) ;
F_85 (i) {
struct V_15 * V_16 = V_59 -> V_82 [ V_2 ] ;
if ( V_16 != NULL && V_16 -> V_149 ) {
F_86 ( & V_16 -> V_38 ) ;
V_16 -> V_149 = false ;
}
}
if ( F_70 ( V_59 -> V_119 , 0 , ( V_120 ) & V_117 ,
sizeof( V_117 ) , V_151 ) < 0 )
F_22 ( L_28 ) ;
V_59 -> V_152 = false ;
}
static void F_87 ( void * V_114 )
{
struct V_56 * V_39 = (struct V_56 * ) V_114 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
if ( V_16 != NULL && V_16 -> V_153 ) {
F_88 ( & V_16 -> V_38 ) ;
V_16 -> V_153 = false ;
}
}
static void F_89 ( void * V_114 )
{
struct V_56 * V_39 = (struct V_56 * ) V_114 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
F_90 ( & V_16 -> V_38 ) ;
V_16 -> V_153 = true ;
F_57 ( V_59 -> V_112 , 0 ) ;
}
static int F_91 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_12 = 0 ;
int V_2 ;
int V_117 = 0 ;
F_72 ( V_39 ) ;
V_16 = V_59 -> V_82 [ V_8 ] ;
if ( ! V_16 -> V_149 ) {
if ( V_16 -> V_147 )
return 1 ;
return - V_154 ;
}
F_92 ( F_72 , ( void * ) V_39 , 1 ) ;
F_85 (i) {
struct V_15 * V_16 = V_59 -> V_82 [ V_2 ] ;
if ( V_16 -> V_149 )
F_93 ( V_39 , & V_16 -> V_38 , F_55 , 64 ) ;
else
V_12 = - V_154 ;
}
if ( V_12 != 0 ) {
F_83 ( V_39 ) ;
return V_12 ;
}
V_18 = & V_16 -> V_18 ;
if ( V_59 -> V_112 == 0 ) {
unsigned int V_113 ;
V_59 -> V_112 = V_18 -> V_71 -> V_155 ;
F_16 ( V_59 -> V_112 == 0 ) ;
V_113 = F_94 ( V_59 -> V_112 ) ;
F_95 ( V_113 , V_156 ) ;
F_16 ( F_96 ( V_113 , F_59 ,
0 , V_39 -> V_138 , ( void * ) V_39 ) != 0 ) ;
}
{
int V_157 =
V_59 -> V_158 * V_59 -> V_136 ;
V_16 -> V_46 =
F_97 ( V_159 , V_157 ) ;
V_16 -> V_48 =
F_97 ( V_160 , V_157 ) ;
F_26 ( V_16 ) ;
if ( V_16 -> V_46 != 0 ||
V_16 -> V_48 != 0 )
F_22 ( L_29 ) ;
}
V_59 -> V_111 = true ;
F_98 () ;
F_84 ( F_89 , ( void * ) V_39 , 1 ) ;
if ( F_70 ( V_59 -> V_119 , 0 , ( V_120 ) & V_117 ,
sizeof( V_117 ) , V_161 ) < 0 )
F_22 ( L_30 ) ;
F_99 ( V_39 ) ;
return 0 ;
}
static void F_100 ( struct V_162 * V_163 )
{
struct V_164 * V_165 =
F_101 ( V_163 , struct V_164 , V_109 ) ;
struct V_58 * V_59 =
F_101 ( V_165 , struct V_58 , V_166 ) ;
if ( F_91 ( V_59 -> V_39 ) != 0 )
F_102 ( & V_59 -> V_166 ,
V_167 ) ;
else
F_103 ( V_59 -> V_39 ) ;
}
static int F_104 ( struct V_56 * V_39 )
{
int V_116 = 0 ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
if ( ! V_59 -> V_152 ) {
int V_9 ;
int V_168 ;
V_116 = F_62 ( V_39 ) ;
if ( V_116 < 0 ) {
F_64 ( L_31 , V_116 ) ;
return V_116 ;
}
if ( V_169 )
F_105 ( & V_59 -> V_133 ,
& V_133 ) ;
else
F_105 ( & V_59 -> V_133 , V_170 ) ;
V_9 = F_106 ( & V_59 -> V_133 ) ;
V_168 = F_107 ( 16 , ( V_160 / V_9 ) & ~ 1 ) ;
V_168 = F_97 ( V_171 , V_168 ) ;
V_59 -> V_158 = V_9 ;
V_59 -> V_136 = V_168 ;
#ifdef F_108
F_6 ( L_32 ,
V_59 -> V_158 , V_59 -> V_136 ) ;
#endif
V_59 -> V_152 = true ;
} else {
}
V_116 = F_91 ( V_39 ) ;
if ( V_116 <= 0 ) {
if ( V_116 == 0 )
F_103 ( V_39 ) ;
return V_116 ;
}
F_109 ( V_39 ) ;
F_102 ( & V_59 -> V_166 , V_167 ) ;
return 0 ;
}
static int F_110 ( struct V_58 * V_59 )
{
int V_53 = 0 ;
while ( true ) {
unsigned int V_27 ;
if ( F_63 ( V_59 -> V_119 , 0 , ( V_120 ) & V_27 ,
sizeof( V_27 ) , V_172 ) < 0 )
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
static int F_111 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_74 ( L_33 ) ;
V_59 -> V_111 = false ;
F_98 () ;
F_84 ( F_80 , ( void * ) V_39 , 1 ) ;
( void ) F_110 ( V_59 ) ;
F_112 ( & V_59 -> V_166 ) ;
F_113 ( V_39 ) ;
F_84 ( F_87 , ( void * ) V_39 , 1 ) ;
if ( F_110 ( V_59 ) != 0 )
F_79 ( L_34 ) ;
F_83 ( V_39 ) ;
while ( F_29 ( V_39 , true ) )
;
memset ( V_59 -> V_49 , 0 , sizeof( T_5 ) ) ;
F_98 () ;
return 0 ;
}
static unsigned int F_114 ( T_13 * V_173 ,
struct V_35 * V_36 ,
void * V_174 , unsigned int V_175 )
{
unsigned int V_2 , V_53 = 0 ;
struct V_176 * V_177 = F_115 ( V_36 ) ;
V_80 V_178 ;
if ( V_175 != 0 ) {
if ( ! V_41 )
F_116 ( V_174 , V_175 , 0 ) ;
V_178 = F_11 ( V_174 ) ;
V_173 [ V_53 ] . V_179 = V_178 ;
V_173 [ V_53 ] . V_180 = V_178 >> 32 ;
V_173 [ V_53 ] . V_6 = V_175 ;
V_173 [ V_53 ] . V_181 = V_41 ;
V_53 ++ ;
}
for ( V_2 = 0 ; V_2 < V_177 -> V_182 ; V_2 ++ ) {
T_14 * V_183 = & V_177 -> V_173 [ V_2 ] ;
unsigned long V_184 = F_117 ( F_118 ( V_183 ) ) ;
int V_181 = V_41 ;
if ( ! V_41 ) {
void * V_25 = F_119 ( V_184 ) + V_183 -> V_185 ;
F_16 ( F_120 ( F_118 ( V_183 ) ) ) ;
F_116 ( V_25 , F_121 ( V_183 ) , 0 ) ;
}
V_178 = ( ( V_80 ) V_184 << V_186 ) + V_183 -> V_185 ;
V_173 [ V_53 ] . V_179 = V_178 ;
V_173 [ V_53 ] . V_180 = V_178 >> 32 ;
V_173 [ V_53 ] . V_6 = F_121 ( V_183 ) ;
V_173 [ V_53 ] . V_181 = V_181 ;
V_53 ++ ;
}
return V_53 ;
}
static int F_122 ( struct V_35 * V_36 , struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
struct V_84 * V_85 = & V_16 -> V_85 ;
struct V_176 * V_177 = F_115 ( V_36 ) ;
unsigned char * V_5 = V_36 -> V_5 ;
struct V_187 * V_188 = F_123 ( V_36 ) ;
unsigned int V_189 = V_188 -> V_190 * 4 ;
unsigned char * V_191 = F_124 ( V_36 ) ;
unsigned int V_192 = V_191 - V_5 ;
struct V_193 * V_194 = (struct V_193 * ) ( V_191 + V_189 ) ;
unsigned int V_195 = V_194 -> V_196 * 4 ;
unsigned int V_197 = V_192 + V_189 + V_195 ;
unsigned int V_175 = F_125 ( V_36 ) - V_197 ;
unsigned int V_198 = V_175 + V_36 -> V_199 ;
unsigned int V_200 = V_177 -> V_201 ;
unsigned int V_202 = V_177 -> V_203 ;
T_2 V_204 [ ( V_205 + 3 ) / 4 ] ;
T_15 * V_206 = ( T_15 * ) V_204 ;
unsigned int V_207 =
F_114 ( V_206 -> V_173 , V_36 , V_5 + V_197 , V_175 ) ;
T_16 V_208 = F_126 ( V_207 , V_197 ) ;
T_15 V_209 = {
. V_210 = true ,
. V_211 = V_197 ,
. V_212 = V_192 ,
. V_213 = V_192 + V_189 ,
. V_214 = V_200 ,
. V_207 = V_207 ,
} ;
unsigned long V_215 ;
T_5 * V_49 = V_59 -> V_49 ;
struct V_35 * V_60 [ 8 ] ;
unsigned int V_61 = 8 ;
unsigned int V_2 , V_216 = 0 ;
unsigned int V_217 , V_218 , V_219 ;
unsigned int V_64 ;
F_16 ( V_36 -> V_102 != F_127 ( V_220 ) ) ;
F_16 ( V_188 -> V_102 != V_221 ) ;
F_16 ( V_36 -> V_103 != V_222 ) ;
F_16 ( V_207 > V_223 ) ;
F_16 ( V_202 <= 1 ) ;
* V_206 = V_209 ;
memcpy ( & V_206 -> V_173 [ V_207 ] , V_5 , V_197 ) ;
F_128 ( & V_49 -> V_64 ) ;
F_128 ( & V_49 -> V_218 ) ;
F_98 () ;
F_129 ( & V_59 -> V_63 , V_215 ) ;
if ( F_130 ( V_49 ) == 0 ) {
V_216 = F_27 ( V_49 , V_60 , V_61 , 0 ) ;
if ( V_216 == 0 ) {
V_224:
F_131 ( & V_59 -> V_63 , V_215 ) ;
return V_225 ;
}
}
V_217 = V_49 -> V_217 ;
V_218 = V_49 -> V_218 ;
V_219 = V_218 + V_208 ;
if ( V_218 < V_217 && V_219 >= V_217 )
goto V_224;
if ( V_219 > V_226 ) {
V_219 = 0 ;
if ( V_219 == V_217 )
goto V_224;
}
memcpy ( & V_49 -> V_227 [ V_218 ] , V_206 , V_208 ) ;
V_218 = V_219 ;
V_64 = V_49 -> V_64 ;
V_49 -> V_50 [ V_64 ] = V_36 ;
F_28 ( V_64 ) ;
V_49 -> V_64 = V_64 ;
F_25 () ;
V_49 -> V_218 = V_218 ;
if ( V_216 == 0 )
V_216 = F_27 ( V_49 , V_60 , V_61 , 4 ) ;
F_131 ( & V_59 -> V_63 , V_215 ) ;
for ( V_2 = 0 ; V_2 < V_216 ; V_2 ++ )
F_132 ( V_60 [ V_2 ] ) ;
F_49 ( & V_85 -> V_99 ) ;
V_85 -> V_228 += V_202 ;
V_85 -> V_229 += ( V_202 * V_197 ) + V_198 ;
F_54 ( & V_85 -> V_99 ) ;
F_34 ( V_16 ) ;
return V_230 ;
}
static int F_133 ( struct V_35 * V_36 , struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
int V_8 = F_2 () ;
struct V_15 * V_16 = V_59 -> V_82 [ V_8 ] ;
struct V_84 * V_85 = & V_16 -> V_85 ;
unsigned long V_215 ;
struct V_176 * V_177 = F_115 ( V_36 ) ;
unsigned int V_3 = V_36 -> V_3 ;
unsigned char * V_5 = V_36 -> V_5 ;
unsigned int V_231 = F_134 ( V_36 ) ;
T_13 V_173 [ 1 + V_232 ] ;
unsigned int V_207 ;
T_5 * V_49 = V_59 -> V_49 ;
struct V_35 * V_60 [ 8 ] ;
unsigned int V_61 = 8 ;
unsigned int V_2 , V_216 = 0 ;
unsigned int V_208 = sizeof( V_233 ) ;
unsigned int V_217 , V_218 , V_219 ;
unsigned int V_64 ;
V_233 V_227 [ 1 + V_232 ] ;
if ( ! V_16 -> V_149 )
return V_225 ;
V_39 -> V_234 = V_67 ;
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
F_5 ( V_5 , F_125 ( V_36 ) , L_36 ) ;
#endif
if ( V_177 -> V_201 != 0 )
return F_122 ( V_36 , V_39 ) ;
V_207 = F_114 ( V_173 , V_36 , V_5 , F_125 ( V_36 ) ) ;
for ( V_2 = 0 ; V_2 < V_207 ; V_2 ++ ) {
bool V_235 = ( V_2 == V_207 - 1 ) ;
V_233 V_206 = {
. V_179 = V_173 [ V_2 ] . V_179 ,
. V_180 = V_173 [ V_2 ] . V_180 ,
. V_6 = V_173 [ V_2 ] . V_6 ,
. V_181 = V_173 [ V_2 ] . V_181 ,
. V_236 = V_235 ,
. V_237 = V_235
} ;
if ( V_2 == 0 && V_36 -> V_103 == V_222 ) {
V_206 . V_238 = 1 ;
V_206 . V_239 . V_240 . V_241 = V_231 ;
V_206 . V_239 . V_240 . V_9 = V_3 - V_231 ;
V_206 . V_239 . V_240 . V_242 =
V_231 + V_36 -> V_243 ;
}
V_227 [ V_2 ] = V_206 ;
}
F_128 ( & V_49 -> V_64 ) ;
F_128 ( & V_49 -> V_218 ) ;
F_98 () ;
F_129 ( & V_59 -> V_63 , V_215 ) ;
if ( F_130 ( V_49 ) == 0 ) {
V_216 = F_27 ( V_49 , V_60 , V_61 , 0 ) ;
if ( V_216 == 0 ) {
V_224:
F_131 ( & V_59 -> V_63 , V_215 ) ;
return V_225 ;
}
}
V_217 = V_49 -> V_217 ;
V_218 = V_49 -> V_218 ;
for ( V_2 = 0 ; V_2 < V_207 ; V_2 ++ ) {
V_219 = V_218 + V_208 ;
if ( V_218 < V_217 && V_219 >= V_217 )
goto V_224;
if ( V_219 > V_226 ) {
V_219 = 0 ;
if ( V_219 == V_217 )
goto V_224;
}
* ( V_233 * ) & V_49 -> V_227 [ V_218 ] = V_227 [ V_2 ] ;
V_218 = V_219 ;
}
V_64 = V_49 -> V_64 ;
V_49 -> V_50 [ V_64 ] = V_36 ;
F_28 ( V_64 ) ;
V_49 -> V_64 = V_64 ;
F_25 () ;
V_49 -> V_218 = V_218 ;
if ( V_216 == 0 )
V_216 = F_27 ( V_49 , V_60 , V_61 , 4 ) ;
F_131 ( & V_59 -> V_63 , V_215 ) ;
for ( V_2 = 0 ; V_2 < V_216 ; V_2 ++ )
F_132 ( V_60 [ V_2 ] ) ;
F_49 ( & V_85 -> V_99 ) ;
V_85 -> V_228 ++ ;
V_85 -> V_229 += ( ( V_3 >= V_244 ) ? V_3 : V_244 ) ;
F_54 ( & V_85 -> V_99 ) ;
F_34 ( V_16 ) ;
return V_230 ;
}
static void F_135 ( struct V_56 * V_39 )
{
F_74 ( L_37 ) ;
F_74 ( L_38 , V_67 ,
V_67 - V_39 -> V_234 ) ;
F_136 ( V_39 ) ;
}
static int F_137 ( struct V_56 * V_39 , struct V_245 * V_246 , int V_206 )
{
return - V_247 ;
}
static struct V_248 * F_138 ( struct V_56 * V_39 ,
struct V_248 * V_85 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
T_17 V_105 = 0 , V_228 = 0 ;
T_17 V_106 = 0 , V_229 = 0 ;
T_17 V_101 = 0 , V_100 = 0 ;
int V_2 ;
F_85 (i) {
struct V_84 * V_249 ;
T_17 V_250 , V_251 , V_252 , V_253 ;
T_17 V_254 , V_255 ;
unsigned int V_256 ;
if ( V_59 -> V_82 [ V_2 ] == NULL )
continue;
V_249 = & V_59 -> V_82 [ V_2 ] -> V_85 ;
do {
V_256 = F_139 ( & V_249 -> V_99 ) ;
V_250 = V_249 -> V_105 ;
V_251 = V_249 -> V_228 ;
V_252 = V_249 -> V_106 ;
V_253 = V_249 -> V_229 ;
V_254 = V_249 -> V_101 ;
V_255 = V_249 -> V_100 ;
} while ( F_140 ( & V_249 -> V_99 , V_256 ) );
V_105 += V_250 ;
V_228 += V_251 ;
V_106 += V_252 ;
V_229 += V_253 ;
V_101 += V_254 ;
V_100 += V_255 ;
}
V_85 -> V_105 = V_105 ;
V_85 -> V_228 = V_228 ;
V_85 -> V_106 = V_106 ;
V_85 -> V_229 = V_229 ;
V_85 -> V_101 = V_101 ;
V_85 -> V_100 = V_100 ;
return V_85 ;
}
static int F_141 ( struct V_56 * V_39 , int V_257 )
{
F_74 ( L_39 ) ;
if ( ( V_257 < 68 ) || ( V_257 > 1500 ) )
return - V_258 ;
V_39 -> V_259 = V_257 ;
return 0 ;
}
static int F_142 ( struct V_56 * V_39 , void * V_260 )
{
struct V_261 * V_262 = V_260 ;
if ( ! F_143 ( V_262 -> V_263 ) )
return - V_264 ;
memcpy ( V_39 -> V_98 , V_262 -> V_263 , V_39 -> V_265 ) ;
return 0 ;
}
static int F_144 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
char V_266 [ 32 ] ;
int V_3 ;
T_18 V_267 = { . V_79 = V_268 } ;
int V_116 ;
strcpy ( V_266 , V_39 -> V_138 ) ;
V_3 = strlen ( V_266 ) ;
V_266 [ V_3 ] = V_266 [ V_3 - 1 ] ;
V_266 [ V_3 - 1 ] = '/' ;
V_3 ++ ;
strcpy ( V_266 + V_3 , V_41 ? L_40 : L_41 ) ;
V_59 -> V_119 = F_145 ( ( V_120 ) V_266 , 0 ) ;
F_74 ( L_42 ,
V_266 , V_59 -> V_119 , & V_59 -> V_119 ) ;
if ( V_59 -> V_119 < 0 ) {
if ( V_59 -> V_119 == V_269 )
F_79 ( V_146 L_43 ,
V_266 ) ;
else
F_79 ( V_146 L_44 ,
V_266 , V_59 -> V_119 ) ;
return - 1 ;
}
V_267 . V_240 . V_270 = V_271 ;
V_267 . V_240 . V_262 = V_272 ;
V_116 = F_63 ( V_59 -> V_119 , 0 ,
( V_120 ) V_39 -> V_98 , V_39 -> V_265 ,
V_267 . V_79 ) ;
F_74 ( L_45 , V_116 ) ;
if ( V_116 <= 0 ) {
F_79 ( V_146 L_46 ,
V_39 -> V_138 ) ;
F_146 ( V_39 ) ;
}
return 0 ;
}
static void F_147 ( struct V_56 * V_39 )
{
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_60 ( V_59 -> V_112 ) ;
F_59 ( V_59 -> V_112 , V_39 ) ;
F_57 ( V_59 -> V_112 , 0 ) ;
}
static void F_148 ( struct V_56 * V_39 )
{
T_19 V_273 = 0 ;
F_149 ( V_39 ) ;
V_39 -> V_274 = & V_275 ;
V_39 -> V_276 = V_277 ;
V_39 -> V_278 = V_279 ;
V_39 -> V_259 = V_28 ;
V_273 |= V_280 ;
V_273 |= V_281 ;
if ( V_223 >= 1 + V_232 )
V_273 |= V_282 ;
if ( V_41 )
V_273 |= V_283 ;
V_39 -> V_284 |= V_273 ;
V_39 -> V_285 |= V_273 ;
V_39 -> V_273 |= V_273 ;
}
static struct V_56 * F_150 ( const char * V_138 )
{
int V_116 ;
struct V_56 * V_39 ;
struct V_58 * V_59 ;
V_39 = F_151 ( sizeof( * V_59 ) , V_138 , V_286 ,
F_148 ) ;
if ( ! V_39 ) {
F_64 ( L_47 , V_138 ) ;
return NULL ;
}
V_59 = F_30 ( V_39 ) ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_39 = V_39 ;
F_152 ( & V_59 -> V_166 , F_100 ) ;
F_153 ( & V_59 -> V_63 ) ;
V_59 -> V_124 = F_154 ( V_287 | V_288 , V_125 ) ;
if ( ! V_59 -> V_124 ) {
F_155 ( V_39 ) ;
return NULL ;
}
V_59 -> V_49 = F_156 ( V_59 -> V_124 ) ;
V_116 = F_157 ( V_39 ) ;
if ( V_116 ) {
F_64 ( L_48 , V_39 -> V_138 , V_116 ) ;
F_158 ( V_59 -> V_124 , V_125 ) ;
F_155 ( V_39 ) ;
return NULL ;
}
V_116 = F_144 ( V_39 ) ;
if ( V_116 < 0 ) {
F_159 ( V_39 ) ;
F_158 ( V_59 -> V_124 , V_125 ) ;
F_155 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
static void F_160 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_289 ; V_2 ++ ) {
if ( V_290 [ V_2 ] ) {
struct V_56 * V_39 = V_290 [ V_2 ] ;
struct V_58 * V_59 = F_30 ( V_39 ) ;
F_159 ( V_39 ) ;
F_116 ( V_59 -> V_49 , V_129 , 0 ) ;
F_158 ( V_59 -> V_124 , V_125 ) ;
F_155 ( V_39 ) ;
}
}
}
static int F_161 ( void )
{
F_6 ( L_49 ) ;
V_290 [ 0 ] = F_150 ( L_16 ) ;
V_290 [ 1 ] = F_150 ( L_17 ) ;
V_290 [ 2 ] = F_150 ( L_18 ) ;
V_290 [ 3 ] = F_150 ( L_19 ) ;
return 0 ;
}
static int T_20 F_162 ( char * V_291 )
{
int V_292 = F_163 ( V_291 , & V_133 ) ;
if ( V_292 != 0 ) {
F_71 ( L_50 , V_291 ) ;
} else {
F_164 ( & V_133 , & V_133 ,
V_293 ) ;
if ( F_165 ( & V_133 ) ) {
F_71 ( L_51 , V_291 ) ;
} else {
F_6 ( L_52 ,
F_166 ( & V_133 ) ) ;
V_169 = true ;
}
}
return 0 ;
}
