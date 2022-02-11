static void F_1 ( char V_1 )
{
T_1 V_2 [] V_3 = { 0xff , 5 , 0 , 0 , V_1 } ;
int V_4 ;
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
do {
V_4 = F_2 ( V_5 , sizeof( V_2 ) , V_2 ) ;
} while ( V_4 == V_6 );
}
static int F_3 ( void )
{
unsigned char V_7 ;
int V_4 , V_8 ;
if ( V_9 == 0 ) {
V_4 = F_4 ( V_5 , & V_9 , V_10 ) ;
if ( V_4 != V_11 || V_10 [ 0 ] != 0xff ) {
V_9 = 0 ;
} else {
for ( V_8 = 4 ; V_8 < V_9 ; V_8 ++ )
V_10 [ V_8 - 4 ] = V_10 [ V_8 ] ;
V_9 -= 4 ;
}
}
if ( V_9 <= 0 || V_9 > 256 ) {
V_9 = 0 ;
return - 1 ;
}
V_7 = V_10 [ 0 ] ;
for ( V_8 = 1 ; V_8 < V_9 ; V_8 ++ ) {
V_10 [ V_8 - 1 ] = V_10 [ V_8 ] ;
}
V_9 -- ;
return V_7 ;
}
static int F_5 ( void )
{
int V_7 ;
for (; ; ) {
V_7 = F_3 () ;
if ( V_7 == - 1 ) {
volatile unsigned long V_12 ;
for ( V_12 = 0 ; V_12 < 2000000 ; V_12 ++ )
;
} else {
return V_7 ;
}
}
}
static void F_6 ( char V_1 )
{
char V_13 [ 16 ] ;
unsigned long V_4 ;
if ( V_1 == '\n' )
F_6 ( '\r' ) ;
V_13 [ 0 ] = V_1 ;
do {
V_4 = F_2 ( V_5 , 1 , V_13 ) ;
} while( V_4 == V_6 );
}
static int F_7 ( void )
{
char V_7 , * V_13 = ( char * ) V_14 ;
int V_8 ;
long V_4 ;
if ( V_15 == 0 ) {
V_15 = 0 ;
V_4 = F_4 ( V_5 , & V_15 , V_13 ) ;
if ( V_4 != V_11 )
V_15 = 0 ;
}
if ( V_15 <= 0 || V_15 > 16 ) {
V_15 = 0 ;
return - 1 ;
}
V_7 = V_13 [ 0 ] ;
for ( V_8 = 1 ; V_8 < V_15 ; V_8 ++ )
V_13 [ V_8 - 1 ] = V_13 [ V_8 ] ;
V_15 -- ;
return V_7 ;
}
static int F_8 ( void )
{
int V_7 ;
for (; ; ) {
V_7 = F_7 () ;
if ( V_7 == - 1 ) {
volatile unsigned long V_12 ;
for ( V_12 = 0 ; V_12 < 2000000 ; V_12 ++ )
;
} else {
return V_7 ;
}
}
}
void T_2 F_9 ( void )
{
V_5 = 0 ;
V_16 = F_6 ;
V_17 = F_8 ;
V_18 = F_7 ;
F_10 () ;
}
void T_2 F_11 ( void )
{
struct V_19 * V_20 ;
const T_3 * V_21 ;
const char * V_22 ;
if ( ! V_23 )
return;
V_22 = F_12 ( V_23 , L_1 , NULL ) ;
if ( V_22 == NULL )
return;
V_20 = F_13 ( V_22 ) ;
if ( ! V_20 )
return;
V_22 = F_12 ( V_20 , L_2 , NULL ) ;
if ( ! V_22 ) {
F_14 ( V_24 L_3 ) ;
goto V_25;
}
if ( strncmp ( V_22 , L_4 , 3 ) != 0 )
goto V_25;
V_21 = F_12 ( V_20 , L_5 , NULL ) ;
if ( V_21 == NULL )
goto V_25;
V_5 = V_21 [ 0 ] ;
if ( F_15 ( V_20 , L_6 ) ) {
V_16 = F_6 ;
V_17 = F_8 ;
V_18 = F_7 ;
F_16 ( L_7 , V_21 [ 0 ] & 0xff , NULL ) ;
} else if ( F_15 ( V_20 , L_8 ) ) {
V_5 = V_21 [ 0 ] ;
V_16 = F_1 ;
V_17 = F_5 ;
V_18 = F_3 ;
F_16 ( L_9 , V_21 [ 0 ] & 0xff , NULL ) ;
}
V_25:
F_17 ( V_20 ) ;
}
void F_18 ( int V_26 )
{
int V_27 = F_19 ( V_26 ) ;
unsigned long V_28 ;
long V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( F_20 ( V_34 ) )
F_21 ( V_26 ) . V_35 = 1 ;
V_28 = F_22 ( & F_21 ( V_26 ) ) ;
V_29 = F_23 ( V_27 , V_28 ) ;
if ( V_29 ) {
F_14 ( V_36 L_10
L_11 ,
V_26 , V_27 , V_28 , V_29 ) ;
return;
}
V_28 = F_22 ( & V_37 [ V_26 ] ) ;
if ( F_24 ( V_38 ) ) {
V_29 = F_25 ( V_27 , V_28 ) ;
if ( V_29 )
F_14 ( V_36
L_12
L_13
L_14 , V_26 , V_27 , V_28 , V_29 ) ;
}
V_31 = & V_39 [ V_26 ] ;
V_33 = V_31 -> V_40 ;
if ( V_33 ) {
V_31 -> V_41 = 0 ;
V_31 -> V_42 = V_33 ;
F_21 ( V_26 ) . V_43 = 0 ;
V_33 -> V_44 = V_45 ;
V_29 = F_26 ( V_27 , F_22 ( V_33 ) ) ;
if ( V_29 )
F_27 ( L_15 ,
V_26 , V_29 ) ;
F_21 ( V_26 ) . V_46 = 2 ;
}
}
static long F_28 ( unsigned long V_47 ,
unsigned long V_48 , unsigned long V_49 ,
unsigned long V_50 , unsigned long V_51 ,
int V_52 , int V_53 )
{
unsigned long V_54 ;
unsigned long V_55 ;
unsigned long V_56 ;
unsigned long V_57 , V_58 ;
if ( ! ( V_51 & V_59 ) )
F_29 ( L_16
L_17 ,
V_47 , V_48 , V_49 , V_50 , V_51 , V_52 ) ;
V_57 = F_30 ( V_48 , V_52 , V_53 ) | V_51 | V_60 ;
V_58 = F_31 ( V_49 , V_52 ) | V_50 ;
if ( ! ( V_51 & V_59 ) )
F_29 ( L_18 , V_57 , V_58 ) ;
V_55 = 0 ;
if ( ( V_50 & V_61 ) & ! ( V_50 & V_62 ) )
V_58 &= ~ V_63 ;
if ( F_24 ( V_64 ) && ! ( V_58 & V_65 ) )
V_55 |= V_66 ;
V_54 = F_32 ( V_55 , V_47 , V_57 , V_58 , & V_56 ) ;
if ( F_33 ( V_54 == V_67 ) ) {
if ( ! ( V_51 & V_59 ) )
F_29 ( L_19 ) ;
return - 1 ;
}
if ( F_33 ( V_54 != V_11 ) ) {
if ( ! ( V_51 & V_59 ) )
F_29 ( L_20 , V_54 ) ;
return - 2 ;
}
if ( ! ( V_51 & V_59 ) )
F_29 ( L_21 , V_56 & 7 ) ;
return ( V_56 & 7 ) | ( ! ! ( V_51 & V_68 ) << 3 ) ;
}
static long F_34 ( unsigned long V_47 )
{
unsigned long V_69 ;
unsigned long V_54 ;
int V_8 ;
unsigned long V_70 , V_71 ;
V_69 = F_35 () & 0x7 ;
for ( V_8 = 0 ; V_8 < V_72 ; V_8 ++ ) {
V_54 = F_36 ( V_73 , V_47 + V_69 ,
( 0x1UL << 4 ) , & V_70 , & V_71 ) ;
if ( V_54 == V_11 )
return V_8 ;
F_37 ( V_54 != V_74 ) ;
V_69 ++ ;
V_69 &= 0x7 ;
}
return - 1 ;
}
static void F_38 ( void )
{
unsigned long V_75 = 1UL << V_76 ;
unsigned long V_77 = V_75 >> 4 ;
struct {
unsigned long V_78 ;
unsigned long V_79 ;
} V_80 [ 4 ] ;
long V_54 ;
int V_8 , V_81 ;
for ( V_8 = 0 ; V_8 < V_77 ; V_8 += 4 ) {
V_54 = F_39 ( 0 , V_8 , ( void * ) V_80 ) ;
if ( V_54 != V_11 )
continue;
for ( V_81 = 0 ; V_81 < 4 ; V_81 ++ ) {
if ( ( V_80 [ V_81 ] . V_78 & V_82 ) ==
V_82 )
continue;
if ( V_80 [ V_81 ] . V_78 & V_60 )
F_40 ( 0 , V_8 + V_81 , 0 ,
& ( V_80 [ V_81 ] . V_78 ) , & ( V_80 [ V_81 ] . V_79 ) ) ;
}
}
}
static inline unsigned long F_41 ( unsigned long V_48 , int V_52 ,
int V_53 )
{
unsigned long V_83 ;
V_83 = ( V_48 >> 23 ) & ~ ( V_84 [ V_52 ] . V_85 ) ;
V_83 <<= V_86 ;
V_83 |= ( ( unsigned long ) V_53 ) << V_87 ;
return V_83 ;
}
static long F_42 ( unsigned long V_56 ,
unsigned long V_88 ,
unsigned long V_48 ,
int V_52 , int V_53 , int V_89 )
{
unsigned long V_54 ;
unsigned long V_55 = ( V_88 & 7 ) | V_90 ;
unsigned long V_91 ;
V_91 = F_41 ( V_48 , V_52 , V_53 ) ;
F_29 ( L_22 ,
V_91 , V_56 , V_55 , V_52 ) ;
V_54 = F_43 ( V_55 , V_56 , V_91 ) ;
if ( V_54 == V_74 ) {
F_29 ( L_23 ) ;
return - 1 ;
}
F_29 ( L_24 ) ;
F_37 ( V_54 != V_11 ) ;
return 0 ;
}
static unsigned long F_44 ( unsigned long V_56 )
{
unsigned long V_92 ;
unsigned long V_54 ;
unsigned long V_93 ;
unsigned long V_55 ;
V_55 = 0 ;
V_54 = F_45 ( V_55 , V_56 , & V_92 , & V_93 ) ;
F_37 ( V_54 != V_11 ) ;
return V_92 ;
}
static long F_46 ( unsigned long V_48 , int V_52 , int V_53 )
{
unsigned long V_94 ;
unsigned long V_8 ;
long V_56 ;
unsigned long V_91 , V_57 ;
V_94 = F_47 ( V_48 , V_84 [ V_52 ] . V_95 , V_53 ) ;
V_91 = F_41 ( V_48 , V_52 , V_53 ) ;
V_56 = ( V_94 & V_96 ) * V_72 ;
for ( V_8 = 0 ; V_8 < V_72 ; V_8 ++ ) {
V_57 = F_44 ( V_56 ) ;
if ( F_48 ( V_57 , V_91 ) && ( V_57 & V_60 ) )
return V_56 ;
++ V_56 ;
}
return - 1 ;
}
static void F_49 ( unsigned long V_88 ,
unsigned long V_97 ,
int V_52 , int V_53 )
{
unsigned long V_54 , V_56 , V_98 , V_48 , V_55 ;
V_98 = F_50 ( V_97 , V_53 ) ;
V_48 = F_51 ( V_97 , V_98 , V_53 ) ;
V_56 = F_46 ( V_48 , V_52 , V_53 ) ;
F_37 ( V_56 == - 1 ) ;
V_55 = V_88 & 7 ;
V_54 = F_43 ( V_55 , V_56 , 0 ) ;
F_37 ( V_54 != V_11 ) ;
}
static void F_52 ( unsigned long V_56 , unsigned long V_48 ,
int V_52 , int V_53 , int V_89 )
{
unsigned long V_91 ;
unsigned long V_54 ;
unsigned long V_70 , V_71 ;
F_29 ( L_25 ,
V_56 , V_48 , V_52 , V_89 ) ;
V_91 = F_41 ( V_48 , V_52 , V_53 ) ;
V_54 = F_36 ( V_90 , V_56 , V_91 , & V_70 , & V_71 ) ;
if ( V_54 == V_74 )
return;
F_37 ( V_54 != V_11 ) ;
}
static void F_53 ( unsigned long V_97 ,
int V_52 , int V_53 )
{
unsigned long V_56 , V_98 , V_48 ;
V_98 = F_50 ( V_97 , V_53 ) ;
V_48 = F_51 ( V_97 , V_98 , V_53 ) ;
V_56 = F_46 ( V_48 , V_52 , V_53 ) ;
F_37 ( V_56 == - 1 ) ;
F_52 ( V_56 , V_48 , V_52 , V_53 , 0 ) ;
}
static void F_54 ( unsigned long V_99 , int V_89 )
{
unsigned long V_8 , V_100 , V_4 ;
unsigned long V_55 = 0 ;
struct V_101 * V_102 = & F_55 ( V_101 ) ;
int V_103 = ! F_56 ( V_104 ) ;
unsigned long V_105 [ 9 ] ;
unsigned long V_48 ;
unsigned long V_94 , V_106 , V_95 , V_107 , V_56 ;
T_4 V_108 ;
int V_52 , V_53 ;
if ( V_103 )
F_57 ( & V_109 , V_55 ) ;
V_52 = V_102 -> V_52 ;
V_53 = V_102 -> V_53 ;
V_100 = 0 ;
for ( V_8 = 0 ; V_8 < V_99 ; V_8 ++ ) {
V_48 = V_102 -> V_110 [ V_8 ] ;
V_108 = V_102 -> V_108 [ V_8 ] ;
F_58 (pte, psize, va, index, shift) {
V_94 = F_47 ( V_48 , V_95 , V_53 ) ;
V_107 = F_59 ( V_108 , V_106 ) ;
if ( V_107 & V_111 )
V_94 = ~ V_94 ;
V_56 = ( V_94 & V_96 ) * V_72 ;
V_56 += V_107 & V_112 ;
if ( ! F_24 ( V_113 ) ) {
F_52 ( V_56 , V_48 , V_52 ,
V_53 , V_89 ) ;
} else {
V_105 [ V_100 ] = V_114 | V_115 | V_56 ;
V_105 [ V_100 + 1 ] = F_41 ( V_48 , V_52 ,
V_53 ) ;
V_100 += 2 ;
if ( V_100 == 8 ) {
V_4 = F_60 ( V_116 , V_105 ,
V_105 [ 0 ] , V_105 [ 1 ] , V_105 [ 2 ] ,
V_105 [ 3 ] , V_105 [ 4 ] , V_105 [ 5 ] ,
V_105 [ 6 ] , V_105 [ 7 ] ) ;
F_37 ( V_4 != V_11 ) ;
V_100 = 0 ;
}
}
} F_61 () ;
}
if ( V_100 ) {
V_105 [ V_100 ] = V_117 ;
V_4 = F_60 ( V_116 , V_105 , V_105 [ 0 ] , V_105 [ 1 ] ,
V_105 [ 2 ] , V_105 [ 3 ] , V_105 [ 4 ] , V_105 [ 5 ] ,
V_105 [ 6 ] , V_105 [ 7 ] ) ;
F_37 ( V_4 != V_11 ) ;
}
if ( V_103 )
F_62 ( & V_109 , V_55 ) ;
}
static int T_2 F_63 ( char * V_118 )
{
if ( strcmp ( V_118 , L_26 ) == 0 &&
F_24 ( V_113 ) ) {
F_14 ( V_119 L_27 ) ;
V_120 &= ~ V_113 ;
}
return 1 ;
}
void T_2 F_64 ( void )
{
V_121 . V_122 = F_52 ;
V_121 . V_123 = F_42 ;
V_121 . V_124 = F_49 ;
V_121 . V_125 = F_28 ;
V_121 . V_126 = F_34 ;
V_121 . V_127 = F_53 ;
V_121 . V_128 = F_54 ;
V_121 . V_129 = F_38 ;
}
static int T_2 F_65 ( char * V_118 )
{
char * V_130 ;
V_130 = F_66 ( V_118 ) ;
if ( strcasecmp ( V_130 , L_28 ) == 0 || strcasecmp ( V_130 , L_26 ) == 0 ) {
F_14 ( V_119 L_29 ) ;
V_131 = 0 ;
return 1 ;
}
V_131 = 1 ;
F_14 ( V_119 L_30 ) ;
if ( strcasecmp ( V_130 , L_31 ) == 0 || strcasecmp ( V_130 , L_32 ) == 0 )
return 1 ;
return 0 ;
}
static void F_67 ( struct V_132 * V_132 , int V_133 ,
unsigned long V_134 )
{
int V_8 , V_81 ;
unsigned long V_135 , V_28 ;
V_135 = F_68 () ;
V_28 = F_22 ( ( unsigned long ) F_69 ( V_132 ) ) ;
for ( V_8 = 0 ; V_8 < ( 1 << V_133 ) ; V_8 ++ , V_28 += V_136 ) {
for ( V_81 = 0 ; V_81 < V_136 ; V_81 += V_135 )
F_70 ( V_137 , V_134 , V_28 + V_81 , 0 ) ;
}
}
void F_71 ( struct V_132 * V_132 , int V_133 )
{
if ( ! V_131 || ! F_24 ( V_138 ) )
return;
F_67 ( V_132 , V_133 , V_139 ) ;
}
void F_72 ( void )
{
V_140 ++ ;
}
void F_73 ( void )
{
V_140 -- ;
}
void F_74 ( unsigned long V_141 , unsigned long * args )
{
unsigned long V_55 ;
unsigned int * V_142 ;
F_75 ( V_55 ) ;
V_142 = & F_55 ( V_143 ) ;
if ( * V_142 )
goto V_25;
( * V_142 ) ++ ;
F_76 ( V_141 , args ) ;
( * V_142 ) -- ;
V_25:
F_77 ( V_55 ) ;
}
void F_78 ( long V_141 , unsigned long V_144 ,
unsigned long * V_145 )
{
unsigned long V_55 ;
unsigned int * V_142 ;
F_75 ( V_55 ) ;
V_142 = & F_55 ( V_143 ) ;
if ( * V_142 )
goto V_25;
( * V_142 ) ++ ;
F_79 ( V_141 , V_144 , V_145 ) ;
( * V_142 ) -- ;
V_25:
F_77 ( V_55 ) ;
}
int F_80 ( struct V_146 * V_147 )
{
int V_4 ;
unsigned long V_145 [ V_148 ] ;
V_4 = F_60 ( V_149 , V_145 ) ;
V_147 -> V_150 = V_145 [ 0 ] ;
V_147 -> V_151 = V_145 [ 1 ] ;
V_147 -> V_152 = ( V_145 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_147 -> V_153 = V_145 [ 2 ] & 0xffff ;
V_147 -> V_154 = ( V_145 [ 3 ] >> 7 * 8 ) & 0xff ;
V_147 -> V_155 = ( V_145 [ 3 ] >> 6 * 8 ) & 0xff ;
V_147 -> V_156 = V_145 [ 3 ] & 0xffffffffffff ;
V_147 -> V_157 = V_145 [ 4 ] ;
V_147 -> V_158 = V_145 [ 5 ] ;
V_147 -> V_159 = V_145 [ 6 ] ;
return V_4 ;
}
int F_81 ( struct V_160 * V_161 )
{
int V_4 ;
unsigned long V_145 [ V_148 ] = { 0 } ;
V_4 = F_60 ( V_162 , V_145 ) ;
V_161 -> V_163 = V_145 [ 0 ] ;
V_161 -> V_164 = V_145 [ 1 ] ;
V_161 -> V_165 = V_145 [ 2 ] ;
V_161 -> V_166 = V_145 [ 3 ] ;
return V_4 ;
}
