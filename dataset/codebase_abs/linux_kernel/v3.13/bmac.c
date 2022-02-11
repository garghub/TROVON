static inline void
F_1 ( volatile T_1 T_2 * V_1 , unsigned long V_2 )
{
__asm__ volatile( "stwbrx %0,0,%1" : : "r" (x), "r" (a) : "memory");
}
static inline unsigned long
F_2 ( volatile T_1 T_2 * V_1 )
{
T_1 V_3 ;
__asm__ volatile ("lwbrx %0,0,%1" : "=r" (swap) : "r" (a));
return V_3 ;
}
static void
F_3 ( volatile struct V_4 T_2 * V_5 )
{
F_1 ( & V_5 -> V_6 ,
F_4 ( V_7 | V_8 ) | F_5 ( V_9 | V_10 ) ) ;
F_6 () ;
}
static void
F_7 ( volatile struct V_4 T_2 * V_5 )
{
F_1 ( & V_5 -> V_6 ,
F_5 ( V_11 | V_10 | V_8 | V_12 | V_9 | V_7 ) ) ;
F_6 () ;
while ( F_2 ( & V_5 -> V_13 ) & V_7 )
F_6 () ;
}
static void
F_8 ( volatile struct V_14 * V_15 ,
unsigned short V_16 , unsigned V_17 , unsigned long V_18 ,
unsigned long V_19 )
{
F_9 ( & V_15 -> V_20 , V_16 ) ;
F_9 ( & V_15 -> V_21 , V_17 ) ;
F_10 ( & V_15 -> V_22 , V_18 ) ;
F_10 ( & V_15 -> V_19 , V_19 ) ;
F_9 ( & V_15 -> V_23 , 0 ) ;
F_9 ( & V_15 -> V_24 , 0 ) ;
}
static inline
void F_11 ( struct V_25 * V_26 , unsigned long V_27 , unsigned V_28 )
{
F_9 ( ( void T_2 * ) V_26 -> V_29 + V_27 , V_28 ) ;
}
static inline
unsigned short F_12 ( struct V_25 * V_26 , unsigned long V_27 )
{
return F_13 ( ( void T_2 * ) V_26 -> V_29 + V_27 ) ;
}
static void
F_14 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_4 T_2 * V_32 = V_31 -> V_33 ;
volatile struct V_4 T_2 * V_34 = V_31 -> V_35 ;
if ( V_32 )
F_7 ( V_32 ) ;
if ( V_34 )
F_7 ( V_34 ) ;
F_16 ( V_36 , F_17 ( V_31 -> V_37 ) , 0 , 1 ) ;
}
static unsigned int
F_18 ( struct V_25 * V_26 , int V_38 )
{
unsigned int V_39 = 0 ;
while ( -- V_38 >= 0 ) {
F_11 ( V_26 , V_40 , 0 ) ;
V_41 ;
if ( F_12 ( V_26 , V_40 ) & 8 )
V_39 |= 1 << V_38 ;
F_11 ( V_26 , V_40 , 1 ) ;
V_41 ;
}
F_11 ( V_26 , V_40 , 0 ) ;
V_41 ;
F_11 ( V_26 , V_40 , 1 ) ;
V_41 ;
return V_39 ;
}
static void
F_19 ( struct V_25 * V_26 , unsigned int V_39 , int V_38 )
{
int V_42 ;
while ( -- V_38 >= 0 ) {
V_42 = ( V_39 & ( 1 << V_38 ) ) ? 6 : 4 ;
F_11 ( V_26 , V_40 , V_42 ) ;
V_41 ;
F_11 ( V_26 , V_40 , V_42 | 1 ) ;
V_41 ;
}
}
static unsigned int
F_20 ( struct V_25 * V_26 , unsigned int V_18 )
{
unsigned int V_39 ;
F_11 ( V_26 , V_40 , 4 ) ;
V_41 ;
F_19 ( V_26 , ~ 0U , 32 ) ;
F_19 ( V_26 , 6 , 4 ) ;
F_19 ( V_26 , V_18 , 10 ) ;
F_11 ( V_26 , V_40 , 2 ) ;
V_41 ;
F_11 ( V_26 , V_40 , 1 ) ;
V_41 ;
V_39 = F_18 ( V_26 , 17 ) ;
F_11 ( V_26 , V_40 , 4 ) ;
V_41 ;
return V_39 ;
}
static void
F_21 ( struct V_25 * V_26 , unsigned int V_18 , unsigned int V_39 )
{
F_11 ( V_26 , V_40 , 4 ) ;
V_41 ;
F_19 ( V_26 , ~ 0U , 32 ) ;
F_19 ( V_26 , 5 , 4 ) ;
F_19 ( V_26 , V_18 , 10 ) ;
F_19 ( V_26 , 2 , 2 ) ;
F_19 ( V_26 , V_39 , 16 ) ;
F_19 ( V_26 , 3 , 2 ) ;
}
static void
F_22 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile unsigned short V_43 ;
unsigned short * V_44 ;
int V_45 ;
F_11 ( V_26 , V_46 , V_47 ) ;
F_11 ( V_26 , V_48 , V_49 ) ;
V_45 = 100 ;
do {
-- V_45 ;
F_23 ( 10000 ) ;
V_43 = F_12 ( V_26 , V_48 ) ;
} while ( ( V_43 & V_49 ) && V_45 > 0 );
if ( ! V_31 -> V_50 ) {
V_43 = F_12 ( V_26 , V_51 ) ;
V_43 |= V_52 | V_53 | V_54 ;
F_11 ( V_26 , V_51 , V_43 ) ;
F_23 ( 10000 ) ;
}
F_11 ( V_26 , V_55 , ( unsigned short ) 0x1968 ) ;
V_43 = F_12 ( V_26 , V_56 ) ;
V_43 |= V_57 ;
F_11 ( V_26 , V_56 , V_43 ) ;
F_12 ( V_26 , V_58 ) ;
F_11 ( V_26 , V_59 , 0 ) ;
F_11 ( V_26 , V_60 , 0 ) ;
F_11 ( V_26 , V_61 , 0 ) ;
F_11 ( V_26 , V_62 , 0 ) ;
F_11 ( V_26 , V_63 , 0 ) ;
F_11 ( V_26 , V_64 , 0 ) ;
F_11 ( V_26 , V_65 , 0 ) ;
F_11 ( V_26 , V_66 , 0 ) ;
F_11 ( V_26 , V_67 , 0 ) ;
F_11 ( V_26 , V_68 , 4 ) ;
F_11 ( V_26 , V_69 , 0 ) ;
F_11 ( V_26 , V_69 , V_70 ) ;
F_11 ( V_26 , V_71 , 0 ) ;
F_11 ( V_26 , V_71 , V_72 ) ;
F_12 ( V_26 , V_73 ) ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) V_31 -> V_74 [ V_45 ] = 0 ;
F_11 ( V_26 , V_75 , V_31 -> V_74 [ 0 ] ) ;
F_11 ( V_26 , V_76 , V_31 -> V_74 [ 1 ] ) ;
F_11 ( V_26 , V_77 , V_31 -> V_74 [ 2 ] ) ;
F_11 ( V_26 , V_78 , V_31 -> V_74 [ 3 ] ) ;
V_44 = ( unsigned short * ) V_26 -> V_79 ;
F_11 ( V_26 , V_80 , * V_44 ++ ) ;
F_11 ( V_26 , V_81 , * V_44 ++ ) ;
F_11 ( V_26 , V_82 , * V_44 ) ;
F_11 ( V_26 , V_83 , V_84 | V_85 | V_86 ) ;
F_11 ( V_26 , V_87 , V_88 ) ;
}
static void
F_24 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_4 T_2 * V_32 = V_31 -> V_33 ;
unsigned short V_89 ;
F_3 ( V_32 ) ;
V_89 = F_12 ( V_26 , V_90 ) ;
F_11 ( V_26 , V_90 , V_89 | V_91 ) ;
V_89 = F_12 ( V_26 , V_83 ) ;
F_11 ( V_26 , V_83 , V_89 | V_92 ) ;
F_23 ( 20000 ) ;
}
static void
F_25 ( struct V_25 * V_26 )
{
unsigned int V_18 ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
F_26 ( V_93 L_1 ) ;
for ( V_18 = 0 ; V_18 < 32 ; ++ V_18 ) {
if ( ( V_18 & 7 ) == 0 )
F_26 ( V_93 ) ;
F_26 ( V_94 L_2 , F_20 ( V_26 , V_18 ) ) ;
}
F_26 ( V_94 L_3 ) ;
if ( V_31 -> V_50 ) {
unsigned int V_95 , V_96 ;
V_96 = F_20 ( V_26 , 0 ) ;
V_95 = ( ( F_20 ( V_26 , 1 ) & 0xf800 ) >> 6 ) | 1 ;
if ( F_20 ( V_26 , 4 ) != V_95 ||
( V_96 & 0x1000 ) == 0 ) {
F_21 ( V_26 , 4 , V_95 ) ;
F_21 ( V_26 , 0 , 0x1200 ) ;
} else
F_21 ( V_26 , 0 , 0x1000 ) ;
}
}
static void F_27 ( struct V_25 * V_26 )
{
F_25 ( V_26 ) ;
F_22 ( V_26 ) ;
}
static int F_28 ( struct V_97 * V_37 , T_3 V_98 )
{
struct V_25 * V_26 = F_29 ( V_37 ) ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
unsigned long V_99 ;
unsigned short V_100 ;
int V_45 ;
F_30 ( V_26 ) ;
F_31 ( & V_31 -> V_101 , V_99 ) ;
if ( V_31 -> V_102 ) {
F_32 ( & V_31 -> V_103 ) ;
V_31 -> V_102 = 0 ;
}
F_33 ( V_26 -> V_104 ) ;
F_33 ( V_31 -> V_105 ) ;
F_33 ( V_31 -> V_106 ) ;
V_31 -> V_107 = 1 ;
F_34 ( & V_31 -> V_101 , V_99 ) ;
if ( V_31 -> V_108 ) {
volatile struct V_4 T_2 * V_32 = V_31 -> V_33 ;
volatile struct V_4 T_2 * V_34 = V_31 -> V_35 ;
V_100 = F_12 ( V_26 , V_83 ) ;
F_11 ( V_26 , V_83 , ( V_100 & ~ V_92 ) ) ;
V_100 = F_12 ( V_26 , V_90 ) ;
F_11 ( V_26 , V_90 , ( V_100 & ~ V_91 ) ) ;
F_11 ( V_26 , V_87 , V_109 ) ;
F_35 ( & V_32 -> V_6 , F_5 ( V_7 | V_9 | V_12 | V_8 ) ) ;
F_35 ( & V_34 -> V_6 , F_5 ( V_7 | V_9 | V_12 | V_8 ) ) ;
for ( V_45 = 0 ; V_45 < V_110 ; V_45 ++ ) {
if ( V_31 -> V_111 [ V_45 ] != NULL ) {
F_36 ( V_31 -> V_111 [ V_45 ] ) ;
V_31 -> V_111 [ V_45 ] = NULL ;
}
}
for ( V_45 = 0 ; V_45 < V_112 ; V_45 ++ ) {
if ( V_31 -> V_113 [ V_45 ] != NULL ) {
F_36 ( V_31 -> V_113 [ V_45 ] ) ;
V_31 -> V_113 [ V_45 ] = NULL ;
}
}
}
F_16 ( V_36 , F_17 ( V_31 -> V_37 ) , 0 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_97 * V_37 )
{
struct V_25 * V_26 = F_29 ( V_37 ) ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
if ( V_31 -> V_108 )
F_38 ( V_26 ) ;
F_39 ( V_26 -> V_104 ) ;
F_39 ( V_31 -> V_105 ) ;
F_39 ( V_31 -> V_106 ) ;
F_40 ( V_26 ) ;
return 0 ;
}
static int F_41 ( struct V_25 * V_26 , void * V_18 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
unsigned char * V_114 = V_18 ;
unsigned short * V_44 ;
unsigned long V_99 ;
int V_45 ;
F_42 ( ( L_4 ) ) ;
F_31 ( & V_31 -> V_101 , V_99 ) ;
for ( V_45 = 0 ; V_45 < 6 ; ++ V_45 ) {
V_26 -> V_79 [ V_45 ] = V_114 [ V_45 ] ;
}
V_44 = ( unsigned short * ) V_26 -> V_79 ;
F_11 ( V_26 , V_80 , * V_44 ++ ) ;
F_11 ( V_26 , V_81 , * V_44 ++ ) ;
F_11 ( V_26 , V_82 , * V_44 ) ;
F_34 ( & V_31 -> V_101 , V_99 ) ;
F_42 ( ( L_5 ) ) ;
return 0 ;
}
static inline void F_43 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
unsigned long V_99 ;
F_31 ( & V_31 -> V_101 , V_99 ) ;
if ( V_31 -> V_102 )
F_32 ( & V_31 -> V_103 ) ;
V_31 -> V_103 . V_115 = V_116 + V_117 ;
V_31 -> V_103 . V_118 = V_119 ;
V_31 -> V_103 . V_28 = ( unsigned long ) V_26 ;
F_44 ( & V_31 -> V_103 ) ;
V_31 -> V_102 = 1 ;
F_34 ( & V_31 -> V_101 , V_99 ) ;
}
static void
F_45 ( struct V_120 * V_121 , volatile struct V_14 * V_15 )
{
void * V_122 ;
unsigned long V_123 ;
unsigned long V_124 ;
V_124 = V_121 -> V_124 ;
V_122 = V_121 -> V_28 ;
V_123 = F_46 ( V_122 ) ;
F_8 ( V_15 , ( V_125 | V_126 | V_127 ) , V_124 , V_123 , 0 ) ;
}
static void
F_47 ( struct V_120 * V_121 , volatile struct V_14 * V_15 )
{
unsigned char * V_18 = V_121 ? V_121 -> V_28 : V_128 ;
F_8 ( V_15 , ( V_129 | V_126 ) , V_130 ,
F_46 ( V_18 ) , 0 ) ;
}
static void
F_48 ( struct V_30 * V_31 )
{
volatile struct V_4 T_2 * V_34 = V_31 -> V_35 ;
memset ( ( char * ) V_31 -> V_131 , 0 , ( V_112 + 1 ) * sizeof( struct V_14 ) ) ;
V_31 -> V_132 = 0 ;
V_31 -> V_133 = 0 ;
V_31 -> V_134 = 0 ;
F_8 ( & V_31 -> V_131 [ V_112 ] ,
( V_135 | V_136 ) , 0 , 0 , F_46 ( V_31 -> V_131 ) ) ;
F_7 ( V_34 ) ;
F_10 ( & V_34 -> V_137 , 0x00200020 ) ;
F_10 ( & V_34 -> V_138 , F_46 ( V_31 -> V_131 ) ) ;
}
static int
F_49 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_4 T_2 * V_32 = V_31 -> V_33 ;
int V_45 ;
struct V_120 * V_121 ;
memset ( ( char * ) V_31 -> V_139 , 0 ,
( V_110 + 1 ) * sizeof( struct V_14 ) ) ;
for ( V_45 = 0 ; V_45 < V_110 ; V_45 ++ ) {
if ( ( V_121 = V_31 -> V_111 [ V_45 ] ) == NULL ) {
V_31 -> V_111 [ V_45 ] = V_121 = F_50 ( V_26 , V_130 + 2 ) ;
if ( V_121 != NULL )
F_51 ( V_121 , 2 ) ;
}
F_47 ( V_121 , & V_31 -> V_139 [ V_45 ] ) ;
}
V_31 -> V_140 = 0 ;
V_31 -> V_141 = V_45 ;
F_8 ( & V_31 -> V_139 [ V_110 ] ,
( V_135 | V_136 ) , 0 , 0 , F_46 ( V_31 -> V_139 ) ) ;
F_7 ( V_32 ) ;
F_10 ( & V_32 -> V_138 , F_46 ( V_31 -> V_139 ) ) ;
return 1 ;
}
static int F_52 ( struct V_120 * V_121 , struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_4 T_2 * V_34 = V_31 -> V_35 ;
int V_45 ;
V_45 = V_31 -> V_133 + 1 ;
if ( V_45 >= V_112 )
V_45 = 0 ;
if ( V_45 == V_31 -> V_132 ) {
F_53 ( V_26 ) ;
V_31 -> V_134 = 1 ;
F_42 ( ( L_6 ) ) ;
return - 1 ;
}
F_8 ( & V_31 -> V_131 [ V_45 ] , V_142 , 0 , 0 , 0 ) ;
F_45 ( V_121 , & V_31 -> V_131 [ V_31 -> V_133 ] ) ;
V_31 -> V_113 [ V_31 -> V_133 ] = V_121 ;
V_31 -> V_133 = V_45 ;
V_26 -> V_143 . V_144 += V_121 -> V_124 ;
F_3 ( V_34 ) ;
return 0 ;
}
static T_4 F_54 ( int V_104 , void * V_145 )
{
struct V_25 * V_26 = (struct V_25 * ) V_145 ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_4 T_2 * V_32 = V_31 -> V_33 ;
volatile struct V_14 * V_15 ;
int V_45 , V_38 , V_146 ;
struct V_120 * V_121 ;
unsigned int V_147 ;
int V_148 ;
unsigned long V_99 ;
F_31 ( & V_31 -> V_101 , V_99 ) ;
if ( ++ V_149 < 10 ) {
F_42 ( ( L_7 ) ) ;
}
V_148 = - 1 ;
V_45 = V_31 -> V_140 ;
while ( 1 ) {
V_15 = & V_31 -> V_139 [ V_45 ] ;
V_146 = F_55 ( & V_15 -> V_23 ) ;
V_147 = F_55 ( & V_15 -> V_24 ) ;
if ( ( V_146 & V_11 ) == 0 )
break;
V_38 = V_130 - V_147 - 2 ;
if ( V_38 < ( V_150 - V_151 ) ) {
V_121 = NULL ;
V_26 -> V_143 . V_152 ++ ;
V_26 -> V_143 . V_153 ++ ;
} else {
V_121 = V_31 -> V_111 [ V_45 ] ;
V_31 -> V_111 [ V_45 ] = NULL ;
}
if ( V_121 != NULL ) {
V_38 -= V_151 ;
F_56 ( V_121 , V_38 ) ;
V_121 -> V_154 = F_57 ( V_121 , V_26 ) ;
F_58 ( V_121 ) ;
++ V_26 -> V_143 . V_155 ;
V_26 -> V_143 . V_156 += V_38 ;
} else {
++ V_26 -> V_143 . V_157 ;
}
if ( ( V_121 = V_31 -> V_111 [ V_45 ] ) == NULL ) {
V_31 -> V_111 [ V_45 ] = V_121 = F_50 ( V_26 , V_130 + 2 ) ;
if ( V_121 != NULL )
F_51 ( V_31 -> V_111 [ V_45 ] , 2 ) ;
}
F_47 ( V_121 , & V_31 -> V_139 [ V_45 ] ) ;
F_59 ( & V_15 -> V_24 , 0 ) ;
F_59 ( & V_15 -> V_23 , 0 ) ;
V_148 = V_45 ;
if ( ++ V_45 >= V_110 ) V_45 = 0 ;
}
if ( V_148 != - 1 ) {
V_31 -> V_141 = V_148 ;
V_31 -> V_140 = V_45 ;
}
F_3 ( V_32 ) ;
F_34 ( & V_31 -> V_101 , V_99 ) ;
if ( V_149 < 10 ) {
F_42 ( ( L_8 ) ) ;
}
return V_158 ;
}
static T_4 F_60 ( int V_104 , void * V_145 )
{
struct V_25 * V_26 = (struct V_25 * ) V_145 ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_14 * V_15 ;
int V_146 ;
unsigned long V_99 ;
F_31 ( & V_31 -> V_101 , V_99 ) ;
if ( V_159 ++ < 10 ) {
F_42 ( ( L_9 ) ) ;
}
while ( 1 ) {
V_15 = & V_31 -> V_131 [ V_31 -> V_132 ] ;
V_146 = F_55 ( & V_15 -> V_23 ) ;
if ( V_159 < 10 ) {
F_42 ( ( L_10 , V_146 ) ) ;
}
if ( ! ( V_146 & V_11 ) ) {
if ( V_15 == F_61 ( F_62 ( & V_31 -> V_35 -> V_138 ) ) )
break;
}
if ( V_31 -> V_113 [ V_31 -> V_132 ] ) {
++ V_26 -> V_143 . V_160 ;
F_63 ( V_31 -> V_113 [ V_31 -> V_132 ] ) ;
}
V_31 -> V_113 [ V_31 -> V_132 ] = NULL ;
V_31 -> V_134 = 0 ;
F_64 ( V_26 ) ;
if ( ++ V_31 -> V_132 >= V_112 )
V_31 -> V_132 = 0 ;
if ( V_31 -> V_132 == V_31 -> V_133 )
break;
}
F_34 ( & V_31 -> V_101 , V_99 ) ;
if ( V_159 < 10 ) {
F_42 ( ( L_11 ) ) ;
}
F_65 ( V_26 ) ;
return V_158 ;
}
static unsigned int
F_66 ( unsigned int V_161 , unsigned short V_162 )
{
register unsigned int V_163 , V_164 = V_161 , V_165 = V_162 ;
register int V_166 , V_167 ;
V_165 = ( ( V_165 & 0x00FF ) << 8 ) | ( V_165 >> 8 ) ;
for ( V_163 = 0 ; V_163 < 16 ; ++ V_163 ) {
if ( ( V_164 & 0x80000000 ) == 0 ) V_166 = 0 ;
else V_166 = 1 ;
V_164 = V_164 << 1 ;
if ( ( V_165 & 0x0001 ) == 0 ) V_167 = 0 ;
else V_167 = 1 ;
V_165 = V_165 >> 1 ;
if ( V_166 ^ V_167 ) V_164 = V_164 ^ V_168 ;
}
return V_164 ;
}
static unsigned int
F_67 ( unsigned short * V_169 )
{
unsigned int V_170 ;
F_42 ( ( L_12 , * V_169 , V_169 [ 1 ] , V_169 [ 2 ] ) ) ;
V_170 = F_66 ( 0xffffffff , * V_169 ) ;
V_170 = F_66 ( V_170 , V_169 [ 1 ] ) ;
V_170 = F_66 ( V_170 , V_169 [ 2 ] ) ;
return ( V_170 ) ;
}
static void
F_68 ( struct V_30 * V_31 , unsigned char * V_18 )
{
unsigned int V_171 ;
unsigned short V_172 ;
if ( ! ( * V_18 ) ) return;
V_171 = F_67 ( ( unsigned short * ) V_18 ) & 0x3f ;
V_171 = V_173 [ V_171 ] ;
if ( V_31 -> V_174 [ V_171 ] ++ ) return;
V_172 = V_171 % 16 ;
V_172 = ( unsigned char ) 1 << V_172 ;
V_31 -> V_174 [ V_171 / 16 ] |= V_172 ;
}
static void
F_69 ( struct V_30 * V_31 , unsigned char * V_18 )
{
unsigned int V_171 ;
unsigned char V_172 ;
V_171 = F_67 ( ( unsigned short * ) V_18 ) & 0x3f ;
V_171 = V_173 [ V_171 ] ;
if ( V_31 -> V_174 [ V_171 ] == 0 ) return;
if ( -- V_31 -> V_174 [ V_171 ] ) return;
V_172 = V_171 % 16 ;
V_172 = ( ( unsigned char ) 1 << V_172 ) ^ 0xffff ;
V_31 -> V_74 [ V_171 / 16 ] &= V_172 ;
}
static void
F_70 ( struct V_25 * V_26 )
{
unsigned short V_175 ;
V_175 = F_12 ( V_26 , V_83 ) ;
V_175 &= ~ V_92 ;
F_11 ( V_26 , V_83 , V_175 ) ;
do {
V_175 = F_12 ( V_26 , V_83 ) ;
} while ( V_175 & V_92 );
}
unsigned short
F_71 ( struct V_25 * V_26 , int V_176 , int V_177 )
{
unsigned short V_175 ;
V_175 = F_12 ( V_26 , V_83 ) ;
V_175 |= V_92 ;
if ( V_176 ) V_175 |= V_85 ;
else V_175 &= ~ V_85 ;
if ( V_177 ) V_175 |= V_178 ;
else V_175 &= ~ V_178 ;
F_11 ( V_26 , V_46 , V_47 ) ;
F_11 ( V_26 , V_71 , 0 ) ;
F_11 ( V_26 , V_71 , V_72 ) ;
F_11 ( V_26 , V_83 , V_175 ) ;
return V_175 ;
}
static void
F_72 ( struct V_25 * V_26 , struct V_30 * V_31 )
{
F_11 ( V_26 , V_75 , V_31 -> V_74 [ 0 ] ) ;
F_11 ( V_26 , V_76 , V_31 -> V_74 [ 1 ] ) ;
F_11 ( V_26 , V_77 , V_31 -> V_74 [ 2 ] ) ;
F_11 ( V_26 , V_78 , V_31 -> V_74 [ 3 ] ) ;
}
static void F_73 ( struct V_25 * V_26 )
{
struct V_179 * V_180 ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
int V_181 = F_74 ( V_26 ) ;
unsigned short V_175 ;
int V_45 ;
if ( V_31 -> V_107 )
return;
F_42 ( ( L_13 , V_181 ) ) ;
if( ( V_26 -> V_99 & V_182 ) || ( F_74 ( V_26 ) > 64 ) ) {
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) V_31 -> V_74 [ V_45 ] = 0xffff ;
F_72 ( V_26 , V_31 ) ;
V_175 = F_71 ( V_26 , 1 , 0 ) ;
F_42 ( ( L_14 ) ) ;
} else if ( ( V_26 -> V_99 & V_183 ) || ( V_181 < 0 ) ) {
V_175 = F_12 ( V_26 , V_83 ) ;
V_175 |= V_178 ;
F_11 ( V_26 , V_83 , V_175 ) ;
V_175 = F_71 ( V_26 , 0 , 1 ) ;
F_42 ( ( L_15 , V_175 ) ) ;
} else {
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) V_31 -> V_74 [ V_45 ] = 0 ;
for ( V_45 = 0 ; V_45 < 64 ; V_45 ++ ) V_31 -> V_174 [ V_45 ] = 0 ;
if ( V_181 == 0 ) {
V_175 = F_71 ( V_26 , 0 , 0 ) ;
F_42 ( ( L_16 , V_175 ) ) ;
} else {
F_75 (ha, dev)
F_68 ( V_31 , V_180 -> V_18 ) ;
F_72 ( V_26 , V_31 ) ;
V_175 = F_71 ( V_26 , 1 , 0 ) ;
F_42 ( ( L_17 , V_175 ) ) ;
}
}
}
static void F_73 ( struct V_25 * V_26 )
{
struct V_179 * V_180 ;
unsigned short V_175 ;
T_5 V_171 ;
if( ( V_26 -> V_99 & V_182 ) || ( F_74 ( V_26 ) > 64 ) ) {
F_11 ( V_26 , V_78 , 0xffff ) ;
F_11 ( V_26 , V_77 , 0xffff ) ;
F_11 ( V_26 , V_76 , 0xffff ) ;
F_11 ( V_26 , V_75 , 0xffff ) ;
} else if( V_26 -> V_99 & V_183 ) {
V_175 = F_12 ( V_26 , V_83 ) ;
V_175 |= V_178 ;
F_11 ( V_26 , V_83 , V_175 ) ;
} else {
T_6 V_184 [ 4 ] = { 0 } ;
V_175 = F_12 ( V_26 , V_83 ) ;
V_175 &= ~ V_178 ;
F_11 ( V_26 , V_83 , V_175 ) ;
F_75 (ha, dev) {
V_171 = F_76 ( 6 , V_180 -> V_18 ) ;
V_171 >>= 26 ;
V_184 [ V_171 >> 4 ] |= 1 << ( V_171 & 0xf ) ;
}
F_11 ( V_26 , V_78 , V_184 [ 0 ] ) ;
F_11 ( V_26 , V_77 , V_184 [ 1 ] ) ;
F_11 ( V_26 , V_76 , V_184 [ 2 ] ) ;
F_11 ( V_26 , V_75 , V_184 [ 3 ] ) ;
}
}
static T_4 F_77 ( int V_104 , void * V_145 )
{
struct V_25 * V_26 = (struct V_25 * ) V_145 ;
unsigned int V_13 = F_12 ( V_26 , V_73 ) ;
if ( V_185 ++ < 10 ) {
F_42 ( ( L_18 ) ) ;
}
if ( V_13 & V_186 ) V_26 -> V_143 . V_153 ++ ;
if ( V_13 & V_187 ) V_26 -> V_143 . V_188 ++ ;
if ( V_13 & V_189 ) V_26 -> V_143 . V_152 ++ ;
if ( V_13 & V_190 ) V_26 -> V_143 . V_191 ++ ;
if ( V_13 & V_192 ) V_26 -> V_143 . V_193 ++ ;
if ( V_13 & V_194 ) V_26 -> V_143 . V_195 ++ ;
if ( V_13 & V_196 ) V_26 -> V_143 . V_197 ++ ;
if ( V_13 & V_198 ) V_26 -> V_143 . V_199 ++ ;
return V_158 ;
}
static unsigned char
F_78 ( struct V_25 * V_26 )
{
unsigned short V_28 ;
unsigned short V_39 ;
F_11 ( V_26 , V_200 , V_201 | V_202 ) ;
F_23 ( V_203 ) ;
V_28 = F_12 ( V_26 , V_200 ) ;
F_23 ( V_203 ) ;
V_39 = ( V_28 >> V_204 ) & 1 ;
F_11 ( V_26 , V_200 , V_201 ) ;
F_23 ( V_203 ) ;
return V_39 ;
}
static void
F_79 ( struct V_25 * V_26 , unsigned int V_39 )
{
unsigned short V_28 ;
if ( V_39 != 0 && V_39 != 1 ) return;
V_28 = ( V_39 << V_205 ) ;
F_11 ( V_26 , V_200 , V_28 | V_201 ) ;
F_23 ( V_203 ) ;
F_11 ( V_26 , V_200 , V_28 | V_201 | V_202 ) ;
F_23 ( V_203 ) ;
F_11 ( V_26 , V_200 , V_28 | V_201 ) ;
F_23 ( V_203 ) ;
}
static void
F_80 ( struct V_25 * V_26 )
{
F_11 ( V_26 , V_200 , 0 ) ;
F_23 ( V_203 ) ;
F_79 ( V_26 , 1 ) ;
F_79 ( V_26 , 1 ) ;
F_79 ( V_26 , 0 ) ;
}
static unsigned short
F_81 ( struct V_25 * V_26 , unsigned int V_18 , unsigned int V_206 )
{
unsigned short V_28 , V_39 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_206 ; V_45 ++ ) {
V_39 = V_18 >> ( V_206 - V_45 - 1 ) ;
F_79 ( V_26 , V_39 & 1 ) ;
}
V_28 = 0 ;
for ( V_45 = 0 ; V_45 < 16 ; V_45 ++ ) {
V_39 = F_78 ( V_26 ) ;
V_28 <<= 1 ;
V_28 |= V_39 ;
}
F_11 ( V_26 , V_200 , 0 ) ;
return V_28 ;
}
static int
F_82 ( struct V_25 * V_26 )
{
unsigned short V_28 , V_207 ;
F_80 ( V_26 ) ;
V_28 = F_81 ( V_26 , 3 , V_208 ) ;
V_207 = ( ( V_28 >> 8 ) & 0x0ff ) | ( ( V_28 << 8 ) & 0xff00 ) ;
return 0 ;
}
static void
F_83 ( struct V_25 * V_26 , unsigned char * V_209 )
{
int V_45 ;
unsigned short V_28 ;
for ( V_45 = 0 ; V_45 < 6 ; V_45 ++ )
{
F_80 ( V_26 ) ;
V_28 = F_81 ( V_26 , V_45 + V_210 / 2 , V_208 ) ;
V_209 [ 2 * V_45 ] = F_84 ( V_28 & 0x0ff ) ;
V_209 [ 2 * V_45 + 1 ] = F_84 ( ( V_28 >> 8 ) & 0x0ff ) ;
}
}
static void F_38 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
unsigned long V_99 ;
struct V_120 * V_121 ;
unsigned char * V_28 ;
F_31 ( & V_31 -> V_101 , V_99 ) ;
F_14 ( V_26 ) ;
F_48 ( V_31 ) ;
F_49 ( V_26 ) ;
F_27 ( V_26 ) ;
F_24 ( V_26 ) ;
F_11 ( V_26 , V_87 , V_88 ) ;
V_31 -> V_107 = 0 ;
V_121 = F_50 ( V_26 , V_150 ) ;
if ( V_121 != NULL ) {
V_28 = F_56 ( V_121 , V_150 ) ;
memset ( V_28 , 0 , V_150 ) ;
memcpy ( V_28 , V_26 -> V_79 , V_211 ) ;
memcpy ( V_28 + V_211 , V_26 -> V_79 , V_211 ) ;
F_52 ( V_121 , V_26 ) ;
}
F_34 ( & V_31 -> V_101 , V_99 ) ;
}
static int F_85 ( struct V_97 * V_37 , const struct V_212 * V_213 )
{
int V_214 , V_215 , V_216 ;
struct V_30 * V_31 ;
const unsigned char * V_217 ;
unsigned char V_18 [ 6 ] ;
struct V_25 * V_26 ;
int V_50 = ( ( int ) V_213 -> V_28 ) != 0 ;
if ( F_86 ( V_37 ) != 3 || F_87 ( V_37 ) != 3 ) {
F_26 ( V_218 L_19 ) ;
return - V_219 ;
}
V_217 = F_88 ( F_17 ( V_37 ) ,
L_20 , NULL ) ;
if ( V_217 == NULL ) {
V_217 = F_88 ( F_17 ( V_37 ) ,
L_21 , NULL ) ;
if ( V_217 == NULL ) {
F_26 ( V_218 L_22 ) ;
return - V_219 ;
}
}
memcpy ( V_18 , V_217 , sizeof( V_18 ) ) ;
V_26 = F_89 ( V_220 ) ;
if ( ! V_26 )
return - V_221 ;
V_31 = F_15 ( V_26 ) ;
F_90 ( V_26 , & V_37 -> V_222 . V_26 ) ;
F_91 ( V_37 , V_26 ) ;
V_31 -> V_37 = V_37 ;
F_92 ( & V_31 -> V_101 ) ;
if ( F_93 ( V_37 , L_23 ) ) {
F_26 ( V_218 L_24 ) ;
goto V_223;
}
V_26 -> V_29 = ( unsigned long )
F_94 ( F_95 ( V_37 , 0 ) , F_96 ( V_37 , 0 ) ) ;
if ( V_26 -> V_29 == 0 )
goto V_224;
V_26 -> V_104 = F_97 ( V_37 , 0 ) ;
F_14 ( V_26 ) ;
F_11 ( V_26 , V_87 , V_109 ) ;
V_215 = V_18 [ 0 ] == 0 && V_18 [ 1 ] == 0xA0 ;
for ( V_214 = 0 ; V_214 < 6 ; ++ V_214 )
V_26 -> V_79 [ V_214 ] = V_215 ? F_84 ( V_18 [ V_214 ] ) : V_18 [ V_214 ] ;
F_14 ( V_26 ) ;
F_11 ( V_26 , V_87 , V_109 ) ;
V_26 -> V_225 = & V_226 ;
V_26 -> V_227 = & V_228 ;
F_83 ( V_26 , V_18 ) ;
if ( F_82 ( V_26 ) != 0 )
goto V_229;
V_31 -> V_50 = V_50 ;
V_31 -> V_35 = F_94 ( F_95 ( V_37 , 1 ) , F_96 ( V_37 , 1 ) ) ;
if ( ! V_31 -> V_35 )
goto V_229;
V_31 -> V_105 = F_97 ( V_37 , 1 ) ;
V_31 -> V_33 = F_94 ( F_95 ( V_37 , 2 ) , F_96 ( V_37 , 2 ) ) ;
if ( ! V_31 -> V_33 )
goto V_230;
V_31 -> V_106 = F_97 ( V_37 , 2 ) ;
V_31 -> V_131 = ( volatile struct V_14 * ) F_98 ( V_31 + 1 ) ;
V_31 -> V_139 = V_31 -> V_131 + V_112 + 1 ;
V_31 -> V_231 = (struct V_232 * ) ( V_31 -> V_139 + V_110 + 1 ) ;
F_99 ( V_31 -> V_231 ) ;
F_100 ( & V_31 -> V_103 ) ;
V_216 = F_101 ( V_26 -> V_104 , F_77 , 0 , L_25 , V_26 ) ;
if ( V_216 ) {
F_26 ( V_218 L_26 , V_26 -> V_104 ) ;
goto V_233;
}
V_216 = F_101 ( V_31 -> V_105 , F_60 , 0 , L_27 , V_26 ) ;
if ( V_216 ) {
F_26 ( V_218 L_26 , V_31 -> V_105 ) ;
goto V_234;
}
V_216 = F_101 ( V_31 -> V_106 , F_54 , 0 , L_28 , V_26 ) ;
if ( V_216 ) {
F_26 ( V_218 L_26 , V_31 -> V_106 ) ;
goto V_235;
}
F_33 ( V_26 -> V_104 ) ;
F_16 ( V_36 , F_17 ( V_31 -> V_37 ) , 0 , 0 ) ;
if ( F_102 ( V_26 ) != 0 ) {
F_26 ( V_218 L_29 ) ;
goto V_236;
}
F_26 ( V_237 L_30 ,
V_26 -> V_238 , ( V_50 ? L_31 : L_32 ) , V_26 -> V_79 ) ;
F_42 ( ( L_33 , V_26 -> V_29 ) ) ;
F_26 ( L_3 ) ;
return 0 ;
V_236:
F_103 ( V_31 -> V_106 , V_26 ) ;
V_235:
F_103 ( V_31 -> V_105 , V_26 ) ;
V_234:
F_103 ( V_26 -> V_104 , V_26 ) ;
V_233:
F_104 ( V_31 -> V_33 ) ;
V_230:
F_104 ( V_31 -> V_35 ) ;
V_229:
F_104 ( ( void T_2 * ) V_26 -> V_29 ) ;
V_224:
F_105 ( V_37 ) ;
V_223:
F_16 ( V_36 , F_17 ( V_31 -> V_37 ) , 0 , 0 ) ;
F_106 ( V_26 ) ;
return - V_219 ;
}
static int F_107 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
V_31 -> V_108 = 1 ;
F_38 ( V_26 ) ;
F_39 ( V_26 -> V_104 ) ;
return 0 ;
}
static int F_108 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_4 T_2 * V_32 = V_31 -> V_33 ;
volatile struct V_4 T_2 * V_34 = V_31 -> V_35 ;
unsigned short V_100 ;
int V_45 ;
V_31 -> V_107 = 1 ;
V_100 = F_12 ( V_26 , V_83 ) ;
F_11 ( V_26 , V_83 , ( V_100 & ~ V_92 ) ) ;
V_100 = F_12 ( V_26 , V_90 ) ;
F_11 ( V_26 , V_90 , ( V_100 & ~ V_91 ) ) ;
F_11 ( V_26 , V_87 , V_109 ) ;
F_35 ( & V_32 -> V_6 , F_5 ( V_7 | V_9 | V_12 | V_8 ) ) ;
F_35 ( & V_34 -> V_6 , F_5 ( V_7 | V_9 | V_12 | V_8 ) ) ;
F_42 ( ( L_34 ) ) ;
for ( V_45 = 0 ; V_45 < V_110 ; V_45 ++ ) {
if ( V_31 -> V_111 [ V_45 ] != NULL ) {
F_36 ( V_31 -> V_111 [ V_45 ] ) ;
V_31 -> V_111 [ V_45 ] = NULL ;
}
}
F_42 ( ( L_35 ) ) ;
for ( V_45 = 0 ; V_45 < V_112 ; V_45 ++ ) {
if ( V_31 -> V_113 [ V_45 ] != NULL ) {
F_36 ( V_31 -> V_113 [ V_45 ] ) ;
V_31 -> V_113 [ V_45 ] = NULL ;
}
}
F_42 ( ( L_36 ) ) ;
V_31 -> V_108 = 0 ;
F_33 ( V_26 -> V_104 ) ;
F_16 ( V_36 , F_17 ( V_31 -> V_37 ) , 0 , 0 ) ;
return 0 ;
}
static void
F_65 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
int V_45 ;
struct V_120 * V_121 ;
unsigned long V_99 ;
if ( V_31 -> V_107 )
return;
F_31 ( & V_31 -> V_101 , V_99 ) ;
while ( 1 ) {
V_45 = V_31 -> V_133 + 1 ;
if ( V_45 >= V_112 )
V_45 = 0 ;
if ( V_45 == V_31 -> V_132 )
break;
V_121 = F_109 ( V_31 -> V_231 ) ;
if ( V_121 == NULL )
break;
F_52 ( V_121 , V_26 ) ;
}
F_34 ( & V_31 -> V_101 , V_99 ) ;
}
static int
F_110 ( struct V_120 * V_121 , struct V_25 * V_26 )
{
struct V_30 * V_31 = F_15 ( V_26 ) ;
F_111 ( V_31 -> V_231 , V_121 ) ;
F_65 ( V_26 ) ;
return V_239 ;
}
static void V_119 ( unsigned long V_28 )
{
struct V_25 * V_26 = (struct V_25 * ) V_28 ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
volatile struct V_4 T_2 * V_34 = V_31 -> V_35 ;
volatile struct V_4 T_2 * V_32 = V_31 -> V_33 ;
volatile struct V_14 * V_15 ;
unsigned long V_99 ;
unsigned short V_100 , V_89 ;
int V_45 ;
F_42 ( ( L_37 ) ) ;
F_31 ( & V_31 -> V_101 , V_99 ) ;
V_31 -> V_102 = 0 ;
V_15 = & V_31 -> V_131 [ V_31 -> V_132 ] ;
V_100 = F_12 ( V_26 , V_83 ) ;
F_11 ( V_26 , V_83 , ( V_100 & ~ V_92 ) ) ;
V_100 = F_12 ( V_26 , V_90 ) ;
F_11 ( V_26 , V_90 , ( V_100 & ~ V_91 ) ) ;
F_10 ( & V_34 -> V_6 , F_5 ( V_7 | V_9 | V_12 | V_8 | V_11 | V_10 ) ) ;
F_26 ( V_218 L_38 ) ;
F_14 ( V_26 ) ;
V_15 = F_61 ( F_112 ( & V_32 -> V_138 ) ) ;
F_10 ( & V_32 -> V_6 , F_5 ( V_7 | V_9 | V_12 | V_8 | V_11 | V_10 ) ) ;
F_9 ( & V_15 -> V_23 , 0 ) ;
F_10 ( & V_32 -> V_138 , F_46 ( V_15 ) ) ;
F_10 ( & V_32 -> V_6 , F_4 ( V_7 | V_8 ) ) ;
F_42 ( ( V_93 L_39 ,
V_31 -> V_132 , V_31 -> V_133 , V_31 -> V_134 ) ) ;
V_45 = V_31 -> V_132 ;
++ V_26 -> V_143 . V_195 ;
if ( V_45 != V_31 -> V_133 ) {
F_36 ( V_31 -> V_113 [ V_45 ] ) ;
V_31 -> V_113 [ V_45 ] = NULL ;
if ( ++ V_45 >= V_112 ) V_45 = 0 ;
V_31 -> V_132 = V_45 ;
}
V_31 -> V_134 = 0 ;
F_64 ( V_26 ) ;
if ( V_45 != V_31 -> V_133 ) {
V_15 = & V_31 -> V_131 [ V_45 ] ;
F_9 ( & V_15 -> V_23 , 0 ) ;
F_9 ( & V_15 -> V_20 , V_125 ) ;
F_10 ( & V_34 -> V_138 , F_46 ( V_15 ) ) ;
F_10 ( & V_34 -> V_6 , F_4 ( V_7 ) ) ;
F_42 ( ( V_93 L_40 , V_45 ) ) ;
}
V_89 = F_12 ( V_26 , V_83 ) ;
F_11 ( V_26 , V_83 , V_89 | V_92 ) ;
V_89 = F_12 ( V_26 , V_90 ) ;
F_11 ( V_26 , V_90 , V_89 | V_91 ) ;
F_34 ( & V_31 -> V_101 , V_99 ) ;
}
static int F_113 ( struct V_97 * V_37 )
{
struct V_25 * V_26 = F_29 ( V_37 ) ;
struct V_30 * V_31 = F_15 ( V_26 ) ;
F_114 ( V_26 ) ;
F_103 ( V_26 -> V_104 , V_26 ) ;
F_103 ( V_31 -> V_105 , V_26 ) ;
F_103 ( V_31 -> V_106 , V_26 ) ;
F_104 ( ( void T_2 * ) V_26 -> V_29 ) ;
F_104 ( V_31 -> V_35 ) ;
F_104 ( V_31 -> V_33 ) ;
F_105 ( V_37 ) ;
F_106 ( V_26 ) ;
return 0 ;
}
static int T_7 F_115 ( void )
{
if ( V_128 == NULL ) {
V_128 = F_116 ( V_130 , V_240 ) ;
if ( V_128 == NULL )
return - V_221 ;
}
return F_117 ( & V_241 ) ;
}
static void T_8 F_118 ( void )
{
F_119 ( & V_241 ) ;
F_120 ( V_128 ) ;
V_128 = NULL ;
}
