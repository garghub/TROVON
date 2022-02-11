static inline int F_1 ( T_1 V_1 )
{ return ! ( F_2 ( V_1 ) & 0xFFFFFFF ) ; }
static inline void F_3 ( T_2 * V_2 , T_3 * V_3 )
{ F_4 ( ( V_4 * ) V_2 , ( V_5 | ( F_5 ( ( unsigned long ) V_3 ) >> 4 ) ) ) ; }
void F_6 ( T_1 * V_6 , V_4 * V_7 )
{
unsigned long V_8 ;
int V_9 ;
V_8 = F_5 ( ( unsigned long ) V_7 ) >> 4 ;
for ( V_9 = 0 ; V_9 < V_10 / V_11 ; V_9 ++ ) {
F_4 ( ( V_4 * ) & V_6 -> V_12 [ V_9 ] , V_5 | V_8 ) ;
V_8 += ( V_11 * sizeof( V_4 ) >> 4 ) ;
}
}
void F_7 ( struct V_13 * V_14 , T_1 * V_6 , struct V_15 * V_7 )
{
unsigned long V_8 ;
int V_9 ;
V_8 = F_8 ( V_7 ) << ( V_16 - 4 ) ;
for ( V_9 = 0 ; V_9 < V_10 / V_11 ; V_9 ++ ) {
F_4 ( ( V_4 * ) & V_6 -> V_12 [ V_9 ] , V_5 | V_8 ) ;
V_8 += ( V_11 * sizeof( V_4 ) >> 4 ) ;
}
}
V_4 * F_9 ( T_1 * V_17 , unsigned long V_18 )
{
void * V_19 ;
V_19 = F_10 ( ( V_17 -> V_12 [ 0 ] & V_20 ) << 4 ) ;
return ( V_4 * ) V_19 +
( ( V_18 >> V_16 ) & ( V_10 - 1 ) ) ;
}
static unsigned long F_11 ( int V_21 , int V_22 )
{
int V_23 ;
if ( V_21 < V_24 ) {
F_12 ( L_1 , V_21 ) ;
V_21 = V_24 ;
}
if ( V_21 & ( V_24 - 1 ) ) {
F_12 ( L_2 , V_21 ) ;
V_21 += V_24 - 1 ;
}
F_13 ( V_22 > V_25 ) ;
V_23 = F_14 ( & V_26 ,
V_21 >> V_24 ,
V_22 >> V_24 ) ;
if ( V_23 == - 1 ) {
F_12 ( L_3 ,
V_21 , ( int ) V_27 ,
V_26 . V_28 << V_24 ) ;
return 0 ;
}
return ( V_29 + ( V_23 << V_24 ) ) ;
}
unsigned long F_15 ( int V_21 , int V_22 )
{
unsigned long V_30 ;
V_30 = F_11 ( V_21 , V_22 ) ;
if ( V_30 )
memset ( ( void * ) V_30 , 0 , V_21 ) ;
return V_30 ;
}
void F_16 ( unsigned long V_31 , int V_21 )
{
int V_23 ;
if ( V_31 < V_29 ) {
F_12 ( L_4 ,
V_31 , ( unsigned long ) V_29 ) ;
F_17 () ;
}
if ( V_31 + V_21 > V_32 ) {
F_12 ( L_5 ,
V_31 , V_32 ) ;
F_17 () ;
}
if ( ! F_18 ( V_21 ) ) {
F_12 ( L_6 , V_21 ) ;
F_17 () ;
}
if ( V_21 < V_24 ) {
F_12 ( L_7 , V_21 ) ;
F_17 () ;
}
if ( V_31 & ( V_21 - 1 ) ) {
F_12 ( L_8 , V_31 , V_21 ) ;
F_17 () ;
}
V_23 = ( V_31 - V_29 ) >> V_24 ;
V_21 = V_21 >> V_24 ;
F_19 ( & V_26 , V_23 , V_21 ) ;
}
static void F_20 ( void )
{
unsigned long V_33 = F_21 () / 1024 ;
int V_34 ;
V_34 =
V_33 / V_35 / 1024 * 256 ;
if ( V_34 < V_36 )
V_34 = V_36 ;
if ( V_34 > V_37 )
V_34 = V_37 ;
V_27 = V_34 * V_38 ;
V_32 = V_29 + V_27 ;
}
static void T_4 F_22 ( void )
{
unsigned int V_39 ;
T_3 * V_40 ;
T_1 * V_1 ;
V_4 * V_19 ;
unsigned long V_41 , V_31 ;
unsigned long V_42 ;
V_39 = V_27 >> V_24 ;
V_43 = F_23 ( V_27 ,
V_25 , 0UL ) ;
memset ( V_43 , 0 , V_27 ) ;
V_44 = F_23 ( V_39 >> 3 , V_45 , 0UL ) ;
F_24 ( & V_26 , V_44 , V_39 ) ;
V_46 = ( T_3 * ) F_11 ( V_47 , V_47 ) ;
memset ( F_25 ( V_46 ) , 0 , V_47 ) ;
V_48 . V_40 = V_46 ;
F_26 ( V_29 , V_32 ) ;
V_41 = F_27 ( ( unsigned long ) V_43 ) ;
V_31 = V_29 ;
while ( V_31 < V_32 ) {
V_40 = F_28 ( V_31 ) ;
V_1 = F_29 ( F_25 ( V_40 ) , V_31 ) ;
V_19 = F_9 ( F_25 ( V_1 ) , V_31 ) ;
V_42 = ( ( V_41 >> 4 ) | V_49 | V_50 ) ;
if ( V_51 )
V_42 |= V_52 ;
F_4 ( F_25 ( V_19 ) , F_30 ( V_42 ) ) ;
V_31 += V_38 ;
V_41 += V_38 ;
}
F_31 () ;
F_32 () ;
}
T_3 * F_33 ( void )
{
T_3 * V_40 = NULL ;
V_40 = ( T_3 * ) F_11 ( V_47 , V_47 ) ;
if ( V_40 ) {
T_3 * V_53 = F_28 ( 0 ) ;
memset ( V_40 , 0 , V_54 * sizeof( T_3 ) ) ;
memcpy ( V_40 + V_54 , V_53 + V_54 ,
( V_55 - V_54 ) * sizeof( T_3 ) ) ;
}
return V_40 ;
}
T_5 F_34 ( struct V_13 * V_14 , unsigned long V_18 )
{
unsigned long V_19 ;
struct V_15 * V_15 ;
if ( ( V_19 = ( unsigned long ) F_35 ( V_14 , V_18 ) ) == 0 )
return NULL ;
V_15 = F_36 ( F_5 ( V_19 ) >> V_16 ) ;
F_37 ( V_15 ) ;
return V_15 ;
}
void F_38 ( struct V_13 * V_14 , T_5 V_19 )
{
unsigned long V_56 ;
F_39 ( V_19 ) ;
V_56 = ( unsigned long ) F_40 ( V_19 ) ;
if ( V_56 == 0 )
F_17 () ;
V_56 = F_8 ( V_19 ) << V_16 ;
V_56 = ( unsigned long ) F_10 ( V_56 ) ;
F_16 ( V_56 , V_57 ) ;
}
static inline void F_41 ( struct V_13 * V_58 , struct V_13 * V_14 )
{
struct V_59 * V_2 ;
V_2 = V_60 . V_61 ;
if( V_2 != & V_60 ) {
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
V_14 -> V_62 = V_2 -> V_63 ;
V_2 -> V_64 = V_14 ;
return;
}
V_2 = V_65 . V_61 ;
if( V_2 -> V_64 == V_58 )
V_2 = V_2 -> V_61 ;
if( V_2 == & V_65 )
F_44 ( L_9 ) ;
F_45 ( V_2 -> V_64 ) ;
F_46 ( V_2 -> V_64 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
V_2 -> V_64 -> V_62 = V_66 ;
V_2 -> V_64 = V_14 ;
V_14 -> V_62 = V_2 -> V_63 ;
}
static inline void F_47 ( int V_62 )
{
struct V_59 * V_67 ;
V_67 = V_68 + V_62 ;
F_42 ( V_67 ) ;
F_48 ( V_67 ) ;
}
void F_49 ( struct V_13 * V_58 , struct V_13 * V_14 ,
struct V_69 * V_70 )
{
if( V_14 -> V_62 == V_66 ) {
F_50 ( & V_71 ) ;
F_41 ( V_58 , V_14 ) ;
F_51 ( & V_71 ) ;
F_3 ( & V_72 [ V_14 -> V_62 ] , V_14 -> V_40 ) ;
}
if ( V_73 == V_74 )
F_52 () ;
if ( V_75 )
F_53 () ;
F_54 ( V_14 -> V_62 ) ;
}
static inline void F_55 ( unsigned long V_76 ,
unsigned long V_77 , int V_78 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
unsigned long V_30 ;
V_76 &= V_79 ;
V_3 = F_28 ( V_77 ) ;
V_6 = F_29 ( V_3 , V_77 ) ;
V_7 = F_9 ( V_6 , V_77 ) ;
V_30 = ( V_76 >> 4 ) | V_49 ;
V_30 |= ( V_78 << 28 ) ;
V_30 |= V_50 ;
F_56 ( V_77 ) ;
F_4 ( V_7 , F_30 ( V_30 ) ) ;
}
void F_57 ( unsigned int V_80 , unsigned long V_81 ,
unsigned long V_82 , unsigned int V_83 )
{
while ( V_83 != 0 ) {
V_83 -= V_38 ;
F_55 ( V_81 , V_82 , V_80 ) ;
V_82 += V_38 ;
V_81 += V_38 ;
}
F_32 () ;
}
static inline void F_58 ( unsigned long V_77 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
V_3 = F_28 ( V_77 ) ;
V_6 = F_29 ( V_3 , V_77 ) ;
V_7 = F_9 ( V_6 , V_77 ) ;
F_59 ( V_7 ) ;
}
void F_60 ( unsigned long V_77 , unsigned int V_83 )
{
while ( V_83 != 0 ) {
V_83 -= V_38 ;
F_58 ( V_77 ) ;
V_77 += V_38 ;
}
F_32 () ;
}
static void T_4 F_61 ( char * type )
{
F_62 ( L_10 , type ) ;
F_63 () ;
}
static void T_4 F_26 ( unsigned long V_84 ,
unsigned long V_85 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
while( V_84 < V_85 ) {
V_3 = F_28 ( V_84 ) ;
if ( F_64 ( * ( T_3 * ) F_25 ( V_3 ) ) ) {
V_6 = ( T_1 * ) F_11 (
V_86 , V_86 ) ;
if ( V_6 == NULL )
F_61 ( L_11 ) ;
memset ( F_25 ( V_6 ) , 0 , V_86 ) ;
F_65 ( F_25 ( V_3 ) , V_6 ) ;
}
V_6 = F_29 ( F_25 ( V_3 ) , V_84 ) ;
if( F_1 ( * ( T_1 * ) F_25 ( V_6 ) ) ) {
V_7 = ( V_4 * ) F_11 ( V_57 , V_57 ) ;
if ( V_7 == NULL )
F_61 ( L_12 ) ;
memset ( F_25 ( V_7 ) , 0 , V_57 ) ;
F_6 ( F_25 ( V_6 ) , V_7 ) ;
}
if ( V_84 > ( 0xffffffffUL - V_87 ) )
break;
V_84 = ( V_84 + V_87 ) & V_88 ;
}
}
static void T_4 F_66 ( unsigned long V_84 ,
unsigned long V_85 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
while( V_84 < V_85 ) {
V_3 = F_28 ( V_84 ) ;
if ( F_64 ( * V_3 ) ) {
V_6 = ( T_1 * ) F_11 ( V_86 , V_86 ) ;
if ( V_6 == NULL )
F_61 ( L_11 ) ;
memset ( V_6 , 0 , V_86 ) ;
F_65 ( V_3 , V_6 ) ;
}
V_6 = F_29 ( V_3 , V_84 ) ;
if( F_1 ( * V_6 ) ) {
V_7 = ( V_4 * ) F_11 ( V_57 ,
V_57 ) ;
if ( V_7 == NULL )
F_61 ( L_12 ) ;
memset ( V_7 , 0 , V_57 ) ;
F_6 ( V_6 , V_7 ) ;
}
if ( V_84 > ( 0xffffffffUL - V_87 ) )
break;
V_84 = ( V_84 + V_87 ) & V_88 ;
}
}
static inline unsigned long F_67 ( unsigned long V_31 )
{
unsigned long V_89 ;
if ( V_73 != V_74 ) {
V_31 &= V_79 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t" :
"=r" (retval) :
"r" (vaddr | 0x400), "i" (ASI_M_FLUSH_PROBE));
} else {
V_89 = F_68 ( V_31 , 0 ) ;
}
return V_89 ;
}
static void T_4 F_69 ( unsigned long V_84 ,
unsigned long V_85 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
int V_90 = 0 ;
unsigned long V_91 ;
while( V_84 <= V_85 ) {
if ( V_84 == 0 )
break;
if( V_84 == 0xfef00000 )
V_84 = V_92 ;
if( ! ( V_91 = F_67 ( V_84 ) ) ) {
V_84 += V_38 ;
continue;
}
V_90 = 0 ;
if( ! ( V_84 & ~ ( V_93 ) ) ) {
if( F_67 ( ( V_84 - V_38 ) + V_94 ) == V_91 )
V_90 = 1 ;
}
if( ! ( V_84 & ~ ( V_95 ) ) ) {
if( F_67 ( ( V_84 - V_38 ) + V_96 ) ==
V_91 )
V_90 = 2 ;
}
V_3 = F_28 ( V_84 ) ;
if( V_90 == 2 ) {
* ( T_3 * ) F_25 ( V_3 ) = F_70 ( V_91 ) ;
V_84 += V_96 ;
continue;
}
if ( F_64 ( * ( T_3 * ) F_25 ( V_3 ) ) ) {
V_6 = ( T_1 * ) F_11 ( V_86 , V_86 ) ;
if ( V_6 == NULL )
F_61 ( L_11 ) ;
memset ( F_25 ( V_6 ) , 0 , V_86 ) ;
F_65 ( F_25 ( V_3 ) , V_6 ) ;
}
V_6 = F_29 ( F_25 ( V_3 ) , V_84 ) ;
if( F_1 ( * ( T_1 * ) F_25 ( V_6 ) ) ) {
V_7 = ( V_4 * ) F_11 ( V_57 ,
V_57 ) ;
if ( V_7 == NULL )
F_61 ( L_12 ) ;
memset ( F_25 ( V_7 ) , 0 , V_57 ) ;
F_6 ( F_25 ( V_6 ) , V_7 ) ;
}
if( V_90 == 1 ) {
unsigned int V_97 ;
V_97 = ( V_84 >> V_98 ) & 15 ;
* ( unsigned long * ) F_25 ( & V_6 -> V_12 [ V_97 ] ) = V_91 ;
V_84 += V_94 ;
continue;
}
V_7 = F_9 ( F_25 ( V_6 ) , V_84 ) ;
* ( V_4 * ) F_25 ( V_7 ) = F_30 ( V_91 ) ;
V_84 += V_38 ;
}
}
static void T_4 F_71 ( unsigned long V_31 , unsigned long V_99 )
{
T_3 * V_3 = F_28 ( V_31 ) ;
unsigned long V_100 ;
V_100 = F_72 ( V_99 >> 4 ) ;
* ( T_3 * ) F_25 ( V_3 ) = F_70 ( V_100 ) ;
}
static unsigned long T_4 F_73 ( unsigned long V_101 , int V_102 )
{
unsigned long V_103 = ( V_104 [ V_102 ] . V_105 & V_95 ) ;
unsigned long V_106 = ( V_101 & V_95 ) ;
unsigned long V_107 = F_74 ( V_101 + V_104 [ V_102 ] . V_108 ) ;
const unsigned long V_109 = V_110 ;
const unsigned long V_111 = V_110 + V_112 ;
if ( V_106 < V_109 || V_106 >= V_111 )
return V_106 ;
if ( V_107 > V_111 || V_107 < V_109 )
V_107 = V_111 ;
while( V_106 < V_107 ) {
F_71 ( V_106 , V_103 ) ;
V_106 += V_96 ; V_103 += V_96 ;
}
return V_106 ;
}
static inline void F_75 ( void )
{
int V_9 ;
if ( V_99 > 0 ) {
F_71 ( V_110 , V_99 ) ;
}
for ( V_9 = 0 ; V_104 [ V_9 ] . V_108 != 0 ; V_9 ++ ) {
F_73 ( ( unsigned long ) F_76 ( V_104 [ V_9 ] . V_105 ) , V_9 ) ;
}
}
void T_4 F_77 ( void )
{
int V_9 ;
T_6 V_113 ;
char V_114 [ 128 ] ;
T_3 * V_40 ;
T_1 * V_1 ;
V_4 * V_19 ;
unsigned long V_115 ;
V_116 . V_84 = V_117 ;
if ( V_73 == V_118 )
V_119 = 65536 ;
else {
V_113 = F_78 ( V_120 ) ;
V_119 = 0 ;
while( V_113 != 0 ) {
F_79 ( V_113 , L_13 , V_114 , sizeof( V_114 ) ) ;
if( ! strcmp ( V_114 , L_14 ) ) {
V_119 = F_80 ( V_113 , L_15 , 0x8 ) ;
break;
}
V_113 = F_81 ( V_113 ) ;
}
}
if( ! V_119 ) {
F_62 ( L_16 ) ;
F_63 () ;
}
V_115 = 0 ;
V_121 = F_82 ( & V_115 ) ;
F_20 () ;
F_22 () ;
F_69 ( 0xfe400000 , ( V_122 - V_38 ) ) ;
F_75 () ;
V_72 = ( T_2 * ) F_11 ( V_119 * sizeof( T_2 ) , V_119 * sizeof( T_2 ) ) ;
V_123 = ( T_2 * ) F_5 ( ( unsigned long ) V_72 ) ;
for( V_9 = 0 ; V_9 < V_119 ; V_9 ++ )
F_3 ( ( T_2 * ) F_25 ( & V_72 [ V_9 ] ) , V_46 ) ;
F_31 () ;
F_83 ( ( unsigned long ) V_123 ) ;
#ifdef F_84
V_124 -> V_125 () ;
#else
F_32 () ;
#endif
F_85 () ;
F_66 ( V_116 . V_84 , V_126 ) ;
F_66 ( V_127 , V_128 ) ;
F_66 (
F_86 ( V_129 - 1 ) , V_130 ) ;
F_66 ( V_131 , V_132 ) ;
V_40 = F_28 ( V_131 ) ;
V_1 = F_29 ( V_40 , V_131 ) ;
V_19 = F_9 ( V_1 , V_131 ) ;
V_133 = V_19 ;
F_31 () ;
F_32 () ;
F_87 ( V_119 ) ;
F_88 () ;
{
unsigned long V_134 [ V_135 ] ;
unsigned long V_136 [ V_135 ] ;
unsigned long V_137 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < V_135 ; V_138 ++ )
V_134 [ V_138 ] = V_136 [ V_138 ] = 0 ;
V_137 = V_139 - V_140 ;
V_134 [ V_141 ] = V_137 ;
V_136 [ V_141 ] = V_137 - V_115 ;
V_137 = V_142 - V_139 ;
V_134 [ V_143 ] = V_137 ;
V_136 [ V_143 ] = V_137 - F_89 () ;
F_90 ( 0 , V_134 , V_140 , V_136 ) ;
}
}
void F_91 ( struct V_144 * V_145 )
{
F_92 ( V_145 ,
L_17
L_18
L_19
L_20 ,
V_146 ,
V_119 ,
V_27 ,
V_26 . V_28 << V_24 ) ;
}
void F_93 ( struct V_13 * V_14 )
{
if( V_14 -> V_62 != V_66 ) {
F_45 ( V_14 ) ;
F_3 ( & V_72 [ V_14 -> V_62 ] , V_46 ) ;
F_46 ( V_14 ) ;
F_50 ( & V_71 ) ;
F_47 ( V_14 -> V_62 ) ;
F_51 ( & V_71 ) ;
V_14 -> V_62 = V_66 ;
}
}
static void T_4 F_94 ( void )
{
F_62 ( L_21 ) ;
F_63 () ;
}
static void T_4 F_95 ( void )
{
T_6 V_147 ;
int V_148 ;
char V_114 [ 128 ] ;
#ifdef F_84
int V_149 = 0 ;
unsigned long V_150 = 0 ;
unsigned long V_151 = 0x10000000 ;
#endif
V_147 = F_78 ( V_120 ) ;
while( ( V_147 = F_81 ( V_147 ) ) != 0 ) {
F_79 ( V_147 , L_13 , V_114 , sizeof( V_114 ) ) ;
if( ! strcmp ( V_114 , L_14 ) ) {
V_152 = F_96 ( V_147 , L_22 ) ;
if ( V_152 == - 1 ) {
F_62 ( L_23
L_24 ) ;
F_63 () ;
}
V_148 = F_96 ( V_147 , L_25 ) ;
if ( V_148 == - 1 ) {
F_62 ( L_26 ) ;
F_63 () ;
}
V_153 = V_148 * V_152 ;
#ifdef F_84
if( V_153 > V_150 )
V_150 = V_153 ;
if( V_152 < V_151 )
V_151 = V_152 ;
V_149 ++ ;
if ( V_149 >= V_154 || ! F_97 ( V_149 ) )
break;
#else
break;
#endif
}
}
if( V_147 == 0 ) {
F_62 ( L_27 ) ;
F_63 () ;
}
#ifdef F_84
V_153 = V_150 ;
V_152 = V_151 ;
#endif
F_12 ( L_28 ,
( int ) V_153 , ( int ) V_152 ) ;
}
static void T_7 F_98 ( void )
{
volatile unsigned long V_155 ;
unsigned long V_156 = F_99 () ;
F_100 () ;
V_156 &= ~ ( V_157 ) ;
V_156 |= ( V_158 | V_159 ) ;
V_156 |= ( V_160 ) ;
F_101 ( V_156 ) ;
#if 0
hyper_clear_all_tags();
#endif
F_102 ( V_161 | V_162 ) ;
F_53 () ;
V_155 = F_103 () ;
V_155 = F_104 () ;
}
static void T_4 F_105 ( void )
{
V_146 = L_29 ;
V_163 = V_164 ;
F_95 () ;
V_75 = 1 ;
V_165 = & V_166 ;
F_85 = F_98 ;
F_106 () ;
}
static void T_7 F_107 ( void )
{
unsigned long V_156 ;
F_108 () ;
V_156 = F_99 () ;
V_156 |= ( V_167 | V_168 ) ;
V_156 &= ~ ( V_169 ) ;
F_101 ( V_156 ) ;
}
static void T_4 F_109 ( void )
{
unsigned long V_170 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t"
"srl %0, 0x18, %0\n\t" :
"=r" (swift_rev) :
"r" (SWIFT_MASKID_ADDR), "i" (ASI_M_BYPASS));
V_146 = L_30 ;
switch( V_170 ) {
case 0x11 :
case 0x20 :
case 0x23 :
case 0x30 :
V_163 = V_171 ;
V_172 |= ( V_173 | V_174 ) ;
break;
case 0x25 :
case 0x31 :
V_163 = V_175 ;
V_172 |= V_174 ;
break;
default:
V_163 = V_176 ;
break;
}
V_165 = & V_177 ;
V_178 = 0 ;
F_85 = F_107 ;
}
static void F_110 ( void )
{
F_111 () ;
F_112 () ;
}
static void F_113 ( struct V_13 * V_14 )
{
F_114 (mm)
F_111 () ;
F_112 () ;
V_179
}
static void F_115 ( struct V_180 * V_181 , unsigned long V_84 , unsigned long V_85 )
{
F_114 (vma->vm_mm)
F_111 () ;
F_112 () ;
V_179
}
static void F_116 ( struct V_180 * V_181 , unsigned long V_15 )
{
F_114 (vma->vm_mm)
F_111 () ;
if ( V_181 -> V_182 & V_183 )
F_117 () ;
F_118 () ;
V_179
}
static void F_119 ( unsigned long V_15 )
{
#ifdef F_120
volatile unsigned long V_155 ;
if ( F_67 ( V_15 ) )
F_121 ( V_15 ) ;
V_155 = F_104 () ;
#endif
}
static void F_122 ( struct V_13 * V_14 , unsigned long V_184 )
{
}
static void F_123 ( unsigned long V_15 )
{
F_118 () ;
}
static void F_124 ( void )
{
F_125 () ;
}
static void F_126 ( struct V_13 * V_14 )
{
F_114 (mm)
F_125 () ;
V_179
}
static void F_127 ( struct V_180 * V_181 , unsigned long V_84 , unsigned long V_85 )
{
F_114 (vma->vm_mm)
F_125 () ;
V_179
}
static void F_128 ( struct V_180 * V_181 , unsigned long V_15 )
{
F_114 (vma->vm_mm)
F_125 () ;
V_179
}
static void T_7 F_129 ( void )
{
unsigned long V_156 = F_99 () ;
unsigned long V_185 ;
F_110 () ;
V_156 &= ~ ( V_186 | V_187 ) ;
V_156 &= ~ ( V_188 ) ;
F_101 ( V_156 ) ;
V_185 = F_130 () ;
#ifdef F_120
V_185 |= ( V_189 ) ;
V_185 &= ~ ( V_190 | V_191 ) ;
#else
V_185 |= ( V_189 | V_191 ) ;
V_185 &= ~ ( V_190 ) ;
#endif
switch ( V_185 & 7 ) {
case 0 :
case 7 :
break;
default:
V_185 |= ( V_192 ) ;
}
F_131 ( V_185 ) ;
V_156 |= ( V_186 | V_187 ) ;
V_156 |= ( V_193 ) ;
F_101 ( V_156 ) ;
}
static void T_4 F_132 ( void )
{
V_146 = L_31 ;
V_163 = V_194 ;
V_165 = & V_195 ;
F_85 = F_129 ;
}
static void T_7 F_133 ( void )
{
unsigned long V_156 = F_99 () ;
F_134 () ;
F_135 () ;
V_156 &= ~ V_196 ;
V_156 |= ( V_197 | V_198 ) ;
F_101 ( V_156 ) ;
}
static void T_4 F_136 ( void )
{
V_146 = L_32 ;
V_163 = V_199 ;
V_165 = & V_200 ;
F_85 = F_133 ;
F_137 () ;
}
static void T_7 F_138 ( void )
{
unsigned long V_156 = F_99 () ;
static int V_201 ;
if ( V_202 ) {
unsigned long V_203 = F_139 () ;
V_203 |= ( V_204 | V_205 | V_206 ) ;
V_203 &= ~ ( V_207 ) ;
F_140 ( V_203 ) ;
V_156 |= V_208 ;
} else {
unsigned long V_209 ;
V_156 &= ~ ( V_208 ) ;
if( V_201 ++ ) {
V_209 = F_141 () ;
V_209 &= ~ ( V_210 ) ;
F_142 ( V_209 ) ;
F_143 () ;
}
}
V_156 |= V_211 ;
V_156 |= ( V_212 | V_213 ) ;
V_156 |= V_214 ;
V_156 &= ~ ( V_215 ) ;
F_101 ( V_156 ) ;
}
static void T_4 F_144 ( void )
{
unsigned long V_156 = F_99 () ;
if( V_156 & V_216 ) {
V_146 = L_33 ;
V_202 = 0 ;
F_143 () ;
V_217 . V_218 = V_219 ;
#ifdef F_84
V_220 . V_218 = V_219 ;
#endif
V_178 = 0 ;
} else {
V_146 = L_34 ;
V_202 = 1 ;
V_51 = 1 ;
}
V_165 = ( const struct V_165 * )
& V_217 ;
#ifdef F_84
if ( V_73 == V_118 )
V_165 = ( const struct V_165 * )
& V_220 ;
#endif
F_85 = F_138 ;
}
static void T_4 F_145 ( void )
{
unsigned long V_156 , V_221 ;
unsigned long V_222 , V_223 , V_224 , V_225 ;
V_163 = V_226 ;
V_172 = 0 ;
V_156 = F_99 () ; V_221 = F_146 () ;
V_222 = ( V_156 & 0xf0000000 ) >> 28 ;
V_223 = ( V_156 & 0x0f000000 ) >> 24 ;
V_224 = ( V_221 >> 28 ) & 0xf ;
V_225 = ( V_221 >> 24 ) & 0xf ;
if ( V_73 == V_74 ) {
F_147 () ;
return;
}
if( V_222 == 1 ) {
switch( V_223 ) {
case 7 :
F_105 () ;
break;
case 0 :
case 2 :
case 10 :
case 11 :
case 12 :
case 13 :
case 14 :
case 15 :
default:
F_62 ( L_35 ) ;
F_63 () ;
break;
}
return;
}
if ( V_224 == 0 && V_225 == 5 ) {
F_132 () ;
return;
}
if( V_224 == 0 && V_225 == 4 ) {
T_6 V_113 ;
char V_114 [ 128 ] ;
V_113 = F_78 ( V_120 ) ;
while( ( V_113 = F_81 ( V_113 ) ) != 0 ) {
F_79 ( V_113 , L_13 , V_114 , sizeof( V_114 ) ) ;
if( ! strcmp ( V_114 , L_14 ) ) {
if ( ! F_80 ( V_113 , L_36 , 1 ) &&
F_80 ( V_113 , L_37 , 1 ) == 5 ) {
F_132 () ;
return;
}
break;
}
}
F_109 () ;
return;
}
if( V_224 == 4 &&
( ( V_225 == 0 ) ||
( ( V_225 == 1 ) && ( V_222 == 0 ) && ( V_223 == 0 ) ) ) ) {
F_144 () ;
return;
}
if( V_224 == 4 && V_225 == 1 && ( V_222 || V_223 ) ) {
F_136 () ;
return;
}
F_94 () ;
}
static void F_148 ( unsigned long V_15 )
{
F_149 ( ( V_227 ) V_124 -> V_218 , V_15 ) ;
V_124 -> V_218 ( V_15 ) ;
}
static void F_150 ( void )
{
F_151 ( ( V_227 ) V_124 -> V_228 ) ;
V_124 -> V_228 () ;
}
static void F_152 ( void )
{
F_151 ( ( V_227 ) V_124 -> V_125 ) ;
V_124 -> V_125 () ;
}
static void F_153 ( struct V_13 * V_14 )
{
if ( V_14 -> V_62 != V_66 ) {
T_8 V_229 ;
F_154 ( & V_229 , F_155 ( V_14 ) ) ;
F_156 ( F_157 () , & V_229 ) ;
if ( ! F_158 ( & V_229 ) )
F_149 ( ( V_227 ) V_124 -> V_230 , ( unsigned long ) V_14 ) ;
V_124 -> V_230 ( V_14 ) ;
}
}
static void F_159 ( struct V_13 * V_14 )
{
if ( V_14 -> V_62 != V_66 ) {
T_8 V_229 ;
F_154 ( & V_229 , F_155 ( V_14 ) ) ;
F_156 ( F_157 () , & V_229 ) ;
if ( ! F_158 ( & V_229 ) ) {
F_149 ( ( V_227 ) V_124 -> V_231 , ( unsigned long ) V_14 ) ;
if ( F_160 ( & V_14 -> V_232 ) == 1 && V_233 -> V_234 == V_14 )
F_154 ( F_155 ( V_14 ) ,
F_161 ( F_157 () ) ) ;
}
V_124 -> V_231 ( V_14 ) ;
}
}
static void F_162 ( struct V_180 * V_181 ,
unsigned long V_84 ,
unsigned long V_85 )
{
struct V_13 * V_14 = V_181 -> V_235 ;
if ( V_14 -> V_62 != V_66 ) {
T_8 V_229 ;
F_154 ( & V_229 , F_155 ( V_14 ) ) ;
F_156 ( F_157 () , & V_229 ) ;
if ( ! F_158 ( & V_229 ) )
F_163 ( ( V_227 ) V_124 -> V_236 ,
( unsigned long ) V_181 , V_84 , V_85 ) ;
V_124 -> V_236 ( V_181 , V_84 , V_85 ) ;
}
}
static void F_164 ( struct V_180 * V_181 ,
unsigned long V_84 ,
unsigned long V_85 )
{
struct V_13 * V_14 = V_181 -> V_235 ;
if ( V_14 -> V_62 != V_66 ) {
T_8 V_229 ;
F_154 ( & V_229 , F_155 ( V_14 ) ) ;
F_156 ( F_157 () , & V_229 ) ;
if ( ! F_158 ( & V_229 ) )
F_163 ( ( V_227 ) V_124 -> V_237 ,
( unsigned long ) V_181 , V_84 , V_85 ) ;
V_124 -> V_237 ( V_181 , V_84 , V_85 ) ;
}
}
static void F_165 ( struct V_180 * V_181 , unsigned long V_15 )
{
struct V_13 * V_14 = V_181 -> V_235 ;
if ( V_14 -> V_62 != V_66 ) {
T_8 V_229 ;
F_154 ( & V_229 , F_155 ( V_14 ) ) ;
F_156 ( F_157 () , & V_229 ) ;
if ( ! F_158 ( & V_229 ) )
F_166 ( ( V_227 ) V_124 -> V_238 ,
( unsigned long ) V_181 , V_15 ) ;
V_124 -> V_238 ( V_181 , V_15 ) ;
}
}
static void F_167 ( struct V_180 * V_181 , unsigned long V_15 )
{
struct V_13 * V_14 = V_181 -> V_235 ;
if ( V_14 -> V_62 != V_66 ) {
T_8 V_229 ;
F_154 ( & V_229 , F_155 ( V_14 ) ) ;
F_156 ( F_157 () , & V_229 ) ;
if ( ! F_158 ( & V_229 ) )
F_166 ( ( V_227 ) V_124 -> V_239 ,
( unsigned long ) V_181 , V_15 ) ;
V_124 -> V_239 ( V_181 , V_15 ) ;
}
}
static void F_168 ( unsigned long V_15 )
{
#if 1
F_149 ( ( V_227 ) V_124 -> V_240 , V_15 ) ;
#endif
V_124 -> V_240 ( V_15 ) ;
}
static void F_169 ( struct V_13 * V_14 , unsigned long V_184 )
{
T_8 V_229 ;
F_154 ( & V_229 , F_155 ( V_14 ) ) ;
F_156 ( F_157 () , & V_229 ) ;
if ( ! F_158 ( & V_229 ) )
F_166 ( ( V_227 ) V_124 -> V_241 ,
( unsigned long ) V_14 , V_184 ) ;
V_124 -> V_241 ( V_14 , V_184 ) ;
}
void T_4 F_170 ( void )
{
extern void V_242 ( void ) ;
extern void V_243 ( void ) ;
F_145 () ;
#ifdef F_84
V_124 = V_165 ;
if ( V_73 == V_118 || V_73 == V_74 ) {
V_244 . V_125 = V_124 -> V_125 ;
V_244 . V_231 = V_124 -> V_231 ;
V_244 . V_237 = V_124 -> V_237 ;
V_244 . V_239 = V_124 -> V_239 ;
}
if ( F_85 == F_138 ) {
V_244 . V_228 = V_124 -> V_228 ;
V_244 . V_230 = V_124 -> V_230 ;
V_244 . V_236 = V_124 -> V_236 ;
V_244 . V_238 = V_124 -> V_238 ;
V_244 . V_240 = V_124 -> V_240 ;
V_244 . V_241 = V_124 -> V_241 ;
V_244 . V_218 = V_124 -> V_218 ;
}
V_165 = ( const struct V_165 * )
& V_244 ;
#endif
if ( V_73 == V_118 )
V_243 () ;
else
V_242 () ;
#ifdef F_84
if ( V_73 == V_118 )
F_171 () ;
else if ( V_73 == V_74 )
F_172 () ;
else
F_173 () ;
#endif
}
