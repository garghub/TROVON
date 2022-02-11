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
static void * F_11 ( int V_21 , int V_22 )
{
int V_23 ;
unsigned long V_24 ;
if ( V_21 < V_25 ) {
F_12 ( V_26 L_1 ,
V_21 ) ;
V_21 = V_25 ;
}
if ( V_21 & ( V_25 - 1 ) ) {
F_12 ( V_26 L_2 ,
V_21 ) ;
V_21 += V_25 - 1 ;
}
F_13 ( V_22 > V_27 ) ;
V_23 = F_14 ( & V_28 ,
V_21 >> V_25 ,
V_22 >> V_25 ) ;
if ( V_23 == - 1 ) {
F_12 ( V_26 L_3 ,
V_21 , ( int ) V_29 ,
V_28 . V_30 << V_25 ) ;
return NULL ;
}
V_24 = V_31 + ( V_23 << V_25 ) ;
return ( void * ) V_24 ;
}
void * F_15 ( int V_21 , int V_22 )
{
void * V_32 ;
V_32 = F_11 ( V_21 , V_22 ) ;
if ( V_32 )
memset ( V_32 , 0 , V_21 ) ;
return V_32 ;
}
void F_16 ( void * V_24 , int V_21 )
{
unsigned long V_33 ;
int V_23 ;
V_33 = ( unsigned long ) V_24 ;
if ( V_33 < V_31 ) {
F_12 ( L_4 ,
V_33 , ( unsigned long ) V_31 ) ;
F_17 () ;
}
if ( V_33 + V_21 > V_34 ) {
F_12 ( L_5 ,
V_33 , V_34 ) ;
F_17 () ;
}
if ( ! F_18 ( V_21 ) ) {
F_12 ( L_6 , V_21 ) ;
F_17 () ;
}
if ( V_21 < V_25 ) {
F_12 ( L_7 , V_21 ) ;
F_17 () ;
}
if ( V_33 & ( V_21 - 1 ) ) {
F_12 ( L_8 , V_33 , V_21 ) ;
F_17 () ;
}
V_23 = ( V_33 - V_31 ) >> V_25 ;
V_21 = V_21 >> V_25 ;
F_19 ( & V_28 , V_23 , V_21 ) ;
}
static unsigned long T_4 F_20 ( void )
{
unsigned long V_35 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_36 [ V_9 ] . V_37 ; V_9 ++ )
V_35 += V_36 [ V_9 ] . V_37 ;
return V_35 ;
}
static void T_4 F_21 ( void )
{
unsigned long V_38 = F_20 () / 1024 ;
int V_39 ;
V_39 =
V_38 / V_40 / 1024 * 256 ;
if ( V_39 < V_41 )
V_39 = V_41 ;
if ( V_39 > V_42 )
V_39 = V_42 ;
V_29 = V_39 * V_43 ;
V_34 = V_31 + V_29 ;
}
static void T_4 F_22 ( void )
{
void * V_44 ;
unsigned int V_45 ;
T_3 * V_46 ;
T_1 * V_1 ;
V_4 * V_19 ;
unsigned long V_47 , V_33 ;
unsigned long V_48 ;
V_45 = V_29 >> V_25 ;
V_49 = F_23 ( V_29 ,
V_27 , 0UL ) ;
memset ( V_49 , 0 , V_29 ) ;
V_44 =
F_23 ( F_24 ( V_45 ) * sizeof( long ) ,
V_50 , 0UL ) ;
F_25 ( & V_28 , V_44 , V_45 ) ;
V_51 = F_11 ( V_52 , V_52 ) ;
memset ( F_26 ( V_51 ) , 0 , V_52 ) ;
V_53 . V_46 = V_51 ;
F_27 ( V_31 , V_34 ) ;
V_47 = F_28 ( ( unsigned long ) V_49 ) ;
V_33 = V_31 ;
while ( V_33 < V_34 ) {
V_46 = F_29 ( V_33 ) ;
V_1 = F_30 ( F_26 ( V_46 ) , V_33 ) ;
V_19 = F_9 ( F_26 ( V_1 ) , V_33 ) ;
V_48 = ( ( V_47 >> 4 ) | V_54 | V_55 ) ;
if ( V_56 )
V_48 |= V_57 ;
F_4 ( F_26 ( V_19 ) , F_31 ( V_48 ) ) ;
V_33 += V_43 ;
V_47 += V_43 ;
}
F_32 () ;
F_33 () ;
}
T_3 * F_34 ( void )
{
T_3 * V_46 = NULL ;
V_46 = F_11 ( V_52 , V_52 ) ;
if ( V_46 ) {
T_3 * V_58 = F_29 ( 0 ) ;
memset ( V_46 , 0 , V_59 * sizeof( T_3 ) ) ;
memcpy ( V_46 + V_59 , V_58 + V_59 ,
( V_60 - V_59 ) * sizeof( T_3 ) ) ;
}
return V_46 ;
}
T_5 F_35 ( struct V_13 * V_14 , unsigned long V_18 )
{
unsigned long V_19 ;
struct V_15 * V_15 ;
if ( ( V_19 = ( unsigned long ) F_36 ( V_14 , V_18 ) ) == 0 )
return NULL ;
V_15 = F_37 ( F_5 ( V_19 ) >> V_16 ) ;
if ( ! F_38 ( V_15 ) ) {
F_39 ( V_15 ) ;
return NULL ;
}
return V_15 ;
}
void F_40 ( struct V_13 * V_14 , T_5 V_19 )
{
unsigned long V_61 ;
F_41 ( V_19 ) ;
V_61 = ( unsigned long ) F_42 ( V_19 ) ;
if ( V_61 == 0 )
F_17 () ;
V_61 = F_8 ( V_19 ) << V_16 ;
F_16 ( F_10 ( V_61 ) , V_62 ) ;
}
static inline void F_43 ( struct V_63 * V_64 )
{
V_64 -> V_65 -> V_66 = V_64 -> V_66 ;
V_64 -> V_66 -> V_65 = V_64 -> V_65 ;
}
static inline void F_44 ( struct V_63 * V_67 , struct V_63 * V_64 )
{
V_64 -> V_65 = V_67 ;
( V_64 -> V_66 = V_67 -> V_66 ) -> V_65 = V_64 ;
V_67 -> V_66 = V_64 ;
}
static inline void F_45 ( struct V_13 * V_68 , struct V_13 * V_14 )
{
struct V_63 * V_2 ;
V_2 = V_69 . V_65 ;
if ( V_2 != & V_69 ) {
F_43 ( V_2 ) ;
F_46 ( V_2 ) ;
V_14 -> V_70 = V_2 -> V_71 ;
V_2 -> V_72 = V_14 ;
return;
}
V_2 = V_73 . V_65 ;
if ( V_2 -> V_72 == V_68 )
V_2 = V_2 -> V_65 ;
if ( V_2 == & V_73 )
F_47 ( L_9 ) ;
F_48 ( V_2 -> V_72 ) ;
F_49 ( V_2 -> V_72 ) ;
F_43 ( V_2 ) ;
F_46 ( V_2 ) ;
V_2 -> V_72 -> V_70 = V_74 ;
V_2 -> V_72 = V_14 ;
V_14 -> V_70 = V_2 -> V_71 ;
}
static inline void F_50 ( int V_70 )
{
struct V_63 * V_75 ;
V_75 = V_76 + V_70 ;
F_43 ( V_75 ) ;
F_51 ( V_75 ) ;
}
static void T_4 F_52 ( int V_77 )
{
int V_78 ;
unsigned long V_21 ;
V_21 = V_77 * sizeof( struct V_63 ) ;
V_76 = F_23 ( V_21 , V_50 , 0UL ) ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
struct V_63 * V_79 ;
V_79 = ( V_76 + V_78 ) ;
V_79 -> V_71 = V_78 ;
V_79 -> V_72 = NULL ;
}
V_69 . V_65 = V_69 . V_66 = & V_69 ;
V_73 . V_65 = V_73 . V_66 = & V_73 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ )
F_51 ( V_76 + V_78 ) ;
}
void F_53 ( struct V_13 * V_68 , struct V_13 * V_14 ,
struct V_80 * V_81 )
{
unsigned long V_82 ;
if ( V_14 -> V_70 == V_74 ) {
F_54 ( & V_83 , V_82 ) ;
F_45 ( V_68 , V_14 ) ;
F_55 ( & V_83 , V_82 ) ;
F_3 ( & V_84 [ V_14 -> V_70 ] , V_14 -> V_46 ) ;
}
if ( V_85 == V_86 )
F_56 () ;
if ( V_87 )
F_57 () ;
F_58 ( V_14 -> V_70 ) ;
}
static inline void F_59 ( unsigned long V_88 ,
unsigned long V_89 , int V_90 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
unsigned long V_32 ;
V_88 &= V_91 ;
V_3 = F_29 ( V_89 ) ;
V_6 = F_30 ( V_3 , V_89 ) ;
V_7 = F_9 ( V_6 , V_89 ) ;
V_32 = ( V_88 >> 4 ) | V_54 ;
V_32 |= ( V_90 << 28 ) ;
V_32 |= V_55 ;
F_60 ( V_89 ) ;
F_4 ( V_7 , F_31 ( V_32 ) ) ;
}
void F_61 ( unsigned int V_92 , unsigned long V_93 ,
unsigned long V_94 , unsigned int V_95 )
{
while ( V_95 != 0 ) {
V_95 -= V_43 ;
F_59 ( V_93 , V_94 , V_92 ) ;
V_94 += V_43 ;
V_93 += V_43 ;
}
F_33 () ;
}
static inline void F_62 ( unsigned long V_89 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
V_3 = F_29 ( V_89 ) ;
V_6 = F_30 ( V_3 , V_89 ) ;
V_7 = F_9 ( V_6 , V_89 ) ;
F_63 ( V_7 ) ;
}
void F_64 ( unsigned long V_89 , unsigned int V_95 )
{
while ( V_95 != 0 ) {
V_95 -= V_43 ;
F_62 ( V_89 ) ;
V_89 += V_43 ;
}
F_33 () ;
}
static void T_4 F_65 ( char * type )
{
F_66 ( L_10 , type ) ;
F_67 () ;
}
static void T_4 F_27 ( unsigned long V_96 ,
unsigned long V_97 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
while ( V_96 < V_97 ) {
V_3 = F_29 ( V_96 ) ;
if ( F_68 ( * ( T_3 * ) F_26 ( V_3 ) ) ) {
V_6 = F_11 (
V_98 , V_98 ) ;
if ( V_6 == NULL )
F_65 ( L_11 ) ;
memset ( F_26 ( V_6 ) , 0 , V_98 ) ;
F_69 ( F_26 ( V_3 ) , V_6 ) ;
}
V_6 = F_30 ( F_26 ( V_3 ) , V_96 ) ;
if ( F_1 ( * ( T_1 * ) F_26 ( V_6 ) ) ) {
V_7 = F_11 ( V_62 , V_62 ) ;
if ( V_7 == NULL )
F_65 ( L_12 ) ;
memset ( F_26 ( V_7 ) , 0 , V_62 ) ;
F_6 ( F_26 ( V_6 ) , V_7 ) ;
}
if ( V_96 > ( 0xffffffffUL - V_99 ) )
break;
V_96 = ( V_96 + V_99 ) & V_100 ;
}
}
static void T_4 F_70 ( unsigned long V_96 ,
unsigned long V_97 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
while ( V_96 < V_97 ) {
V_3 = F_29 ( V_96 ) ;
if ( F_68 ( * V_3 ) ) {
V_6 = F_11 ( V_98 , V_98 ) ;
if ( V_6 == NULL )
F_65 ( L_11 ) ;
memset ( V_6 , 0 , V_98 ) ;
F_69 ( V_3 , V_6 ) ;
}
V_6 = F_30 ( V_3 , V_96 ) ;
if ( F_1 ( * V_6 ) ) {
V_7 = F_11 ( V_62 ,
V_62 ) ;
if ( V_7 == NULL )
F_65 ( L_12 ) ;
memset ( V_7 , 0 , V_62 ) ;
F_6 ( V_6 , V_7 ) ;
}
if ( V_96 > ( 0xffffffffUL - V_99 ) )
break;
V_96 = ( V_96 + V_99 ) & V_100 ;
}
}
static inline unsigned long F_71 ( unsigned long V_33 )
{
unsigned long V_101 ;
if ( V_85 != V_86 ) {
V_33 &= V_91 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t" :
"=r" (retval) :
"r" (vaddr | 0x400), "i" (ASI_M_FLUSH_PROBE));
} else {
V_101 = F_72 ( V_33 , NULL ) ;
}
return V_101 ;
}
static void T_4 F_73 ( unsigned long V_96 ,
unsigned long V_97 )
{
unsigned long V_102 ;
unsigned long V_24 ;
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
int V_103 ;
while ( V_96 <= V_97 ) {
if ( V_96 == 0 )
break;
if ( V_96 == 0xfef00000 )
V_96 = V_104 ;
V_102 = F_71 ( V_96 ) ;
if ( ! V_102 ) {
V_96 += V_43 ;
continue;
}
V_103 = 0 ;
V_24 = V_96 - V_43 ;
if ( ! ( V_96 & ~ ( V_105 ) ) ) {
if ( F_71 ( V_24 + V_106 ) == V_102 )
V_103 = 1 ;
}
if ( ! ( V_96 & ~ ( V_107 ) ) ) {
if ( F_71 ( V_24 + V_108 ) == V_102 )
V_103 = 2 ;
}
V_3 = F_29 ( V_96 ) ;
if ( V_103 == 2 ) {
* ( T_3 * ) F_26 ( V_3 ) = F_74 ( V_102 ) ;
V_96 += V_108 ;
continue;
}
if ( F_68 ( * ( T_3 * ) F_26 ( V_3 ) ) ) {
V_6 = F_11 ( V_98 ,
V_98 ) ;
if ( V_6 == NULL )
F_65 ( L_11 ) ;
memset ( F_26 ( V_6 ) , 0 , V_98 ) ;
F_69 ( F_26 ( V_3 ) , V_6 ) ;
}
V_6 = F_30 ( F_26 ( V_3 ) , V_96 ) ;
if ( F_1 ( * ( T_1 * ) F_26 ( V_6 ) ) ) {
V_7 = F_11 ( V_62 , V_62 ) ;
if ( V_7 == NULL )
F_65 ( L_12 ) ;
memset ( F_26 ( V_7 ) , 0 , V_62 ) ;
F_6 ( F_26 ( V_6 ) , V_7 ) ;
}
if ( V_103 == 1 ) {
unsigned int V_109 ;
unsigned long * V_110 ;
V_109 = ( V_96 >> V_111 ) & 15 ;
V_110 = & V_6 -> V_12 [ V_109 ] ;
* ( unsigned long * ) F_26 ( V_110 ) = V_102 ;
V_96 += V_106 ;
continue;
}
V_7 = F_9 ( F_26 ( V_6 ) , V_96 ) ;
* ( V_4 * ) F_26 ( V_7 ) = F_31 ( V_102 ) ;
V_96 += V_43 ;
}
}
static void T_4 F_75 ( unsigned long V_33 , unsigned long V_112 )
{
T_3 * V_3 = F_29 ( V_33 ) ;
unsigned long V_113 ;
V_113 = F_76 ( V_112 >> 4 ) ;
* ( T_3 * ) F_26 ( V_3 ) = F_74 ( V_113 ) ;
}
static unsigned long T_4 F_77 ( unsigned long V_114 , int V_115 )
{
unsigned long V_116 = ( V_36 [ V_115 ] . V_117 & V_107 ) ;
unsigned long V_118 = ( V_114 & V_107 ) ;
unsigned long V_119 = F_78 ( V_114 + V_36 [ V_115 ] . V_37 ) ;
const unsigned long V_120 = V_121 ;
const unsigned long V_122 = V_121 + V_123 ;
if ( V_118 < V_120 || V_118 >= V_122 )
return V_118 ;
if ( V_119 > V_122 || V_119 < V_120 )
V_119 = V_122 ;
while ( V_118 < V_119 ) {
F_75 ( V_118 , V_116 ) ;
V_118 += V_108 ; V_116 += V_108 ;
}
return V_118 ;
}
static void T_4 F_79 ( void )
{
int V_9 ;
if ( V_112 > 0 ) {
F_75 ( V_121 , V_112 ) ;
}
for ( V_9 = 0 ; V_36 [ V_9 ] . V_37 != 0 ; V_9 ++ ) {
F_77 ( ( unsigned long ) F_80 ( V_36 [ V_9 ] . V_117 ) , V_9 ) ;
}
}
void T_4 F_81 ( void )
{
int V_9 ;
T_6 V_124 ;
char V_125 [ 128 ] ;
T_3 * V_46 ;
T_1 * V_1 ;
V_4 * V_19 ;
unsigned long V_126 ;
V_53 . V_70 = ( unsigned long ) V_74 ;
V_127 . V_96 = V_128 ;
if ( V_85 == V_129 )
V_130 = 65536 ;
else {
V_124 = F_82 ( V_131 ) ;
V_130 = 0 ;
while ( V_124 != 0 ) {
F_83 ( V_124 , L_13 , V_125 , sizeof( V_125 ) ) ;
if ( ! strcmp ( V_125 , L_14 ) ) {
V_130 = F_84 ( V_124 , L_15 , 0x8 ) ;
break;
}
V_124 = F_85 ( V_124 ) ;
}
}
if ( ! V_130 ) {
F_66 ( L_16 ) ;
F_67 () ;
}
V_126 = 0 ;
V_132 = F_86 ( & V_126 ) ;
F_21 () ;
F_22 () ;
F_73 ( 0xfe400000 , ( V_133 - V_43 ) ) ;
F_79 () ;
V_84 = F_11 ( V_130 * sizeof( T_2 ) , V_130 * sizeof( T_2 ) ) ;
V_134 = ( T_2 * ) F_5 ( ( unsigned long ) V_84 ) ;
for ( V_9 = 0 ; V_9 < V_130 ; V_9 ++ )
F_3 ( ( T_2 * ) F_26 ( & V_84 [ V_9 ] ) , V_51 ) ;
F_32 () ;
F_87 ( ( unsigned long ) V_134 ) ;
#ifdef F_88
V_135 -> V_136 () ;
#else
F_33 () ;
#endif
F_89 () ;
F_70 ( V_127 . V_96 , V_137 ) ;
F_70 ( V_138 , V_139 ) ;
F_70 (
F_90 ( V_140 - 1 ) , V_141 ) ;
F_70 ( V_142 , V_143 ) ;
V_46 = F_29 ( V_142 ) ;
V_1 = F_30 ( V_46 , V_142 ) ;
V_19 = F_9 ( V_1 , V_142 ) ;
V_144 = V_19 ;
F_32 () ;
F_33 () ;
F_52 ( V_130 ) ;
F_91 () ;
{
unsigned long V_145 [ V_146 ] ;
unsigned long V_147 [ V_146 ] ;
unsigned long V_148 ;
int V_149 ;
for ( V_149 = 0 ; V_149 < V_146 ; V_149 ++ )
V_145 [ V_149 ] = V_147 [ V_149 ] = 0 ;
V_148 = V_150 - V_151 ;
V_145 [ V_152 ] = V_148 ;
V_147 [ V_152 ] = V_148 - V_126 ;
V_148 = V_153 - V_150 ;
V_145 [ V_154 ] = V_148 ;
V_147 [ V_154 ] = V_148 - F_92 () ;
F_93 ( 0 , V_145 , V_151 , V_147 ) ;
}
}
void F_94 ( struct V_155 * V_156 )
{
F_95 ( V_156 ,
L_17
L_18
L_19
L_20 ,
V_157 ,
V_130 ,
V_29 ,
V_28 . V_30 << V_25 ) ;
}
int F_96 ( struct V_80 * V_81 , struct V_13 * V_14 )
{
V_14 -> V_70 = V_74 ;
return 0 ;
}
void F_97 ( struct V_13 * V_14 )
{
unsigned long V_82 ;
if ( V_14 -> V_70 != V_74 ) {
F_48 ( V_14 ) ;
F_3 ( & V_84 [ V_14 -> V_70 ] , V_51 ) ;
F_49 ( V_14 ) ;
F_54 ( & V_83 , V_82 ) ;
F_50 ( V_14 -> V_70 ) ;
F_55 ( & V_83 , V_82 ) ;
V_14 -> V_70 = V_74 ;
}
}
static void T_4 F_98 ( void )
{
F_66 ( L_21 ) ;
F_67 () ;
}
static void T_4 F_99 ( void )
{
T_6 V_158 ;
int V_159 ;
char V_125 [ 128 ] ;
#ifdef F_88
int V_160 = 0 ;
unsigned long V_161 = 0 ;
unsigned long V_162 = 0x10000000 ;
#endif
V_158 = F_82 ( V_131 ) ;
while ( ( V_158 = F_85 ( V_158 ) ) != 0 ) {
F_83 ( V_158 , L_13 , V_125 , sizeof( V_125 ) ) ;
if ( ! strcmp ( V_125 , L_14 ) ) {
V_163 = F_100 ( V_158 , L_22 ) ;
if ( V_163 == - 1 ) {
F_66 ( L_23 ) ;
F_67 () ;
}
V_159 = F_100 ( V_158 , L_24 ) ;
if ( V_159 == - 1 ) {
F_66 ( L_25 ) ;
F_67 () ;
}
V_164 = V_159 * V_163 ;
#ifdef F_88
if ( V_164 > V_161 )
V_161 = V_164 ;
if ( V_163 < V_162 )
V_162 = V_163 ;
V_160 ++ ;
if ( V_160 >= V_165 || ! F_101 ( V_160 ) )
break;
#else
break;
#endif
}
}
if ( V_158 == 0 ) {
F_66 ( L_26 ) ;
F_67 () ;
}
#ifdef F_88
V_164 = V_161 ;
V_163 = V_162 ;
#endif
F_12 ( L_27 ,
( int ) V_164 , ( int ) V_163 ) ;
}
static void F_102 ( void )
{
volatile unsigned long V_166 ;
unsigned long V_167 = F_103 () ;
F_104 () ;
V_167 &= ~ ( V_168 ) ;
V_167 |= ( V_169 | V_170 ) ;
V_167 |= ( V_171 ) ;
F_105 ( V_167 ) ;
#if 0
hyper_clear_all_tags();
#endif
F_106 ( V_172 | V_173 ) ;
F_57 () ;
V_166 = F_107 () ;
V_166 = F_108 () ;
}
static void T_4 F_109 ( void )
{
V_157 = L_28 ;
V_174 = V_175 ;
F_99 () ;
V_87 = 1 ;
V_176 = & V_177 ;
F_89 = F_102 ;
F_110 () ;
}
static void F_111 ( void )
{
unsigned long V_167 ;
F_112 () ;
V_167 = F_103 () ;
V_167 |= ( V_178 | V_179 ) ;
V_167 &= ~ ( V_180 ) ;
F_105 ( V_167 ) ;
}
static void T_4 F_113 ( void )
{
unsigned long V_181 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t"
"srl %0, 0x18, %0\n\t" :
"=r" (swift_rev) :
"r" (SWIFT_MASKID_ADDR), "i" (ASI_M_BYPASS));
V_157 = L_29 ;
switch ( V_181 ) {
case 0x11 :
case 0x20 :
case 0x23 :
case 0x30 :
V_174 = V_182 ;
V_183 |= ( V_184 | V_185 ) ;
break;
case 0x25 :
case 0x31 :
V_174 = V_186 ;
V_183 |= V_185 ;
break;
default:
V_174 = V_187 ;
break;
}
V_176 = & V_188 ;
V_189 = 0 ;
F_89 = F_111 ;
}
static void F_114 ( void )
{
F_115 () ;
F_116 () ;
}
static void F_117 ( struct V_13 * V_14 )
{
F_118 (mm)
F_115 () ;
F_116 () ;
V_190
}
static void F_119 ( struct V_191 * V_192 , unsigned long V_96 , unsigned long V_97 )
{
F_118 (vma->vm_mm)
F_115 () ;
F_116 () ;
V_190
}
static void F_120 ( struct V_191 * V_192 , unsigned long V_15 )
{
F_118 (vma->vm_mm)
F_115 () ;
if ( V_192 -> V_193 & V_194 )
F_121 () ;
F_122 () ;
V_190
}
static void F_123 ( unsigned long V_15 )
{
#ifdef F_124
volatile unsigned long V_166 ;
if ( F_71 ( V_15 ) )
F_125 ( V_15 ) ;
V_166 = F_108 () ;
#endif
}
static void F_126 ( struct V_13 * V_14 , unsigned long V_195 )
{
}
static void F_127 ( unsigned long V_15 )
{
F_122 () ;
}
static void F_128 ( void )
{
F_129 () ;
}
static void F_130 ( struct V_13 * V_14 )
{
F_118 (mm)
F_129 () ;
V_190
}
static void F_131 ( struct V_191 * V_192 , unsigned long V_96 , unsigned long V_97 )
{
F_118 (vma->vm_mm)
F_129 () ;
V_190
}
static void F_132 ( struct V_191 * V_192 , unsigned long V_15 )
{
F_118 (vma->vm_mm)
F_129 () ;
V_190
}
static void F_133 ( void )
{
unsigned long V_167 = F_103 () ;
unsigned long V_196 ;
F_114 () ;
V_167 &= ~ ( V_197 | V_198 ) ;
V_167 &= ~ ( V_199 ) ;
F_105 ( V_167 ) ;
V_196 = F_134 () ;
#ifdef F_124
V_196 |= ( V_200 ) ;
V_196 &= ~ ( V_201 | V_202 ) ;
#else
V_196 |= ( V_200 | V_202 ) ;
V_196 &= ~ ( V_201 ) ;
#endif
switch ( V_196 & 7 ) {
case 0 :
case 7 :
break;
default:
V_196 |= ( V_203 ) ;
}
F_135 ( V_196 ) ;
V_167 |= ( V_197 | V_198 ) ;
V_167 |= ( V_204 ) ;
F_105 ( V_167 ) ;
}
static void T_4 F_136 ( void )
{
V_157 = L_30 ;
V_174 = V_205 ;
V_176 = & V_206 ;
F_89 = F_133 ;
}
static void F_137 ( void )
{
unsigned long V_167 = F_103 () ;
F_138 () ;
F_139 () ;
V_167 &= ~ V_207 ;
V_167 |= ( V_208 | V_209 ) ;
F_105 ( V_167 ) ;
}
static void T_4 F_140 ( void )
{
V_157 = L_31 ;
V_174 = V_210 ;
V_176 = & V_211 ;
F_89 = F_137 ;
F_141 () ;
}
static void F_142 ( void )
{
unsigned long V_167 = F_103 () ;
static int V_212 ;
if ( V_213 ) {
unsigned long V_214 = F_143 () ;
V_214 |= ( V_215 | V_216 | V_217 ) ;
V_214 &= ~ ( V_218 ) ;
F_144 ( V_214 ) ;
V_167 |= V_219 ;
} else {
unsigned long V_220 ;
V_167 &= ~ ( V_219 ) ;
if ( V_212 ++ ) {
V_220 = F_145 () ;
V_220 &= ~ ( V_221 ) ;
F_146 ( V_220 ) ;
F_147 () ;
}
}
V_167 |= V_222 ;
V_167 |= ( V_223 | V_224 ) ;
V_167 |= V_225 ;
V_167 &= ~ ( V_226 ) ;
F_105 ( V_167 ) ;
}
static void T_4 F_148 ( void )
{
unsigned long V_167 = F_103 () ;
if ( V_167 & V_227 ) {
V_157 = L_32 ;
V_213 = 0 ;
F_147 () ;
V_228 . V_229 = V_230 ;
#ifdef F_88
V_231 . V_229 = V_230 ;
#endif
V_189 = 0 ;
} else {
V_157 = L_33 ;
V_213 = 1 ;
V_56 = 1 ;
}
V_176 = ( const struct V_176 * )
& V_228 ;
#ifdef F_88
if ( V_85 == V_129 )
V_176 = ( const struct V_176 * )
& V_231 ;
#endif
F_89 = F_142 ;
}
static void T_4 F_149 ( void )
{
unsigned long V_167 , V_232 ;
unsigned long V_233 , V_234 , V_235 , V_236 ;
V_174 = V_237 ;
V_183 = 0 ;
V_167 = F_103 () ; V_232 = F_150 () ;
V_233 = ( V_167 & 0xf0000000 ) >> 28 ;
V_234 = ( V_167 & 0x0f000000 ) >> 24 ;
V_235 = ( V_232 >> 28 ) & 0xf ;
V_236 = ( V_232 >> 24 ) & 0xf ;
if ( V_85 == V_86 ) {
F_151 () ;
return;
}
if ( V_233 == 1 ) {
switch ( V_234 ) {
case 7 :
F_109 () ;
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
F_66 ( L_34 ) ;
F_67 () ;
break;
}
return;
}
if ( V_235 == 0 && V_236 == 5 ) {
F_136 () ;
return;
}
if ( V_235 == 0 && V_236 == 4 ) {
T_6 V_124 ;
char V_125 [ 128 ] ;
V_124 = F_82 ( V_131 ) ;
while ( ( V_124 = F_85 ( V_124 ) ) != 0 ) {
F_83 ( V_124 , L_13 , V_125 , sizeof( V_125 ) ) ;
if ( ! strcmp ( V_125 , L_14 ) ) {
if ( ! F_84 ( V_124 , L_35 , 1 ) &&
F_84 ( V_124 , L_36 , 1 ) == 5 ) {
F_136 () ;
return;
}
break;
}
}
F_113 () ;
return;
}
if ( V_235 == 4 &&
( ( V_236 == 0 ) ||
( ( V_236 == 1 ) && ( V_233 == 0 ) && ( V_234 == 0 ) ) ) ) {
F_148 () ;
return;
}
if ( V_235 == 4 && V_236 == 1 && ( V_233 || V_234 ) ) {
F_140 () ;
return;
}
F_98 () ;
}
static void F_152 ( unsigned long V_15 )
{
F_153 ( ( V_238 ) V_135 -> V_229 , V_15 ) ;
V_135 -> V_229 ( V_15 ) ;
}
static void F_154 ( void )
{
F_155 ( ( V_238 ) V_135 -> V_239 ) ;
V_135 -> V_239 () ;
}
static void F_156 ( void )
{
F_155 ( ( V_238 ) V_135 -> V_136 ) ;
V_135 -> V_136 () ;
}
static void F_157 ( struct V_13 * V_14 )
{
if ( V_14 -> V_70 != V_74 ) {
T_7 V_240 ;
F_158 ( & V_240 , F_159 ( V_14 ) ) ;
F_160 ( F_161 () , & V_240 ) ;
if ( ! F_162 ( & V_240 ) )
F_153 ( ( V_238 ) V_135 -> V_241 , ( unsigned long ) V_14 ) ;
V_135 -> V_241 ( V_14 ) ;
}
}
static void F_163 ( struct V_13 * V_14 )
{
if ( V_14 -> V_70 != V_74 ) {
T_7 V_240 ;
F_158 ( & V_240 , F_159 ( V_14 ) ) ;
F_160 ( F_161 () , & V_240 ) ;
if ( ! F_162 ( & V_240 ) ) {
F_153 ( ( V_238 ) V_135 -> V_242 , ( unsigned long ) V_14 ) ;
if ( F_164 ( & V_14 -> V_243 ) == 1 && V_244 -> V_245 == V_14 )
F_158 ( F_159 ( V_14 ) ,
F_165 ( F_161 () ) ) ;
}
V_135 -> V_242 ( V_14 ) ;
}
}
static void F_166 ( struct V_191 * V_192 ,
unsigned long V_96 ,
unsigned long V_97 )
{
struct V_13 * V_14 = V_192 -> V_246 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_240 ;
F_158 ( & V_240 , F_159 ( V_14 ) ) ;
F_160 ( F_161 () , & V_240 ) ;
if ( ! F_162 ( & V_240 ) )
F_167 ( ( V_238 ) V_135 -> V_247 ,
( unsigned long ) V_192 , V_96 , V_97 ) ;
V_135 -> V_247 ( V_192 , V_96 , V_97 ) ;
}
}
static void F_168 ( struct V_191 * V_192 ,
unsigned long V_96 ,
unsigned long V_97 )
{
struct V_13 * V_14 = V_192 -> V_246 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_240 ;
F_158 ( & V_240 , F_159 ( V_14 ) ) ;
F_160 ( F_161 () , & V_240 ) ;
if ( ! F_162 ( & V_240 ) )
F_167 ( ( V_238 ) V_135 -> V_248 ,
( unsigned long ) V_192 , V_96 , V_97 ) ;
V_135 -> V_248 ( V_192 , V_96 , V_97 ) ;
}
}
static void F_169 ( struct V_191 * V_192 , unsigned long V_15 )
{
struct V_13 * V_14 = V_192 -> V_246 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_240 ;
F_158 ( & V_240 , F_159 ( V_14 ) ) ;
F_160 ( F_161 () , & V_240 ) ;
if ( ! F_162 ( & V_240 ) )
F_170 ( ( V_238 ) V_135 -> V_249 ,
( unsigned long ) V_192 , V_15 ) ;
V_135 -> V_249 ( V_192 , V_15 ) ;
}
}
static void F_171 ( struct V_191 * V_192 , unsigned long V_15 )
{
struct V_13 * V_14 = V_192 -> V_246 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_240 ;
F_158 ( & V_240 , F_159 ( V_14 ) ) ;
F_160 ( F_161 () , & V_240 ) ;
if ( ! F_162 ( & V_240 ) )
F_170 ( ( V_238 ) V_135 -> V_250 ,
( unsigned long ) V_192 , V_15 ) ;
V_135 -> V_250 ( V_192 , V_15 ) ;
}
}
static void F_172 ( unsigned long V_15 )
{
#if 1
F_153 ( ( V_238 ) V_135 -> V_251 , V_15 ) ;
#endif
V_135 -> V_251 ( V_15 ) ;
}
static void F_173 ( struct V_13 * V_14 , unsigned long V_195 )
{
T_7 V_240 ;
F_158 ( & V_240 , F_159 ( V_14 ) ) ;
F_160 ( F_161 () , & V_240 ) ;
if ( ! F_162 ( & V_240 ) )
F_170 ( ( V_238 ) V_135 -> V_252 ,
( unsigned long ) V_14 , V_195 ) ;
V_135 -> V_252 ( V_14 , V_195 ) ;
}
void T_4 F_174 ( void )
{
F_149 () ;
#ifdef F_88
V_135 = V_176 ;
if ( V_85 == V_129 || V_85 == V_86 ) {
V_253 . V_136 = V_135 -> V_136 ;
V_253 . V_242 = V_135 -> V_242 ;
V_253 . V_248 = V_135 -> V_248 ;
V_253 . V_250 = V_135 -> V_250 ;
}
if ( F_89 == F_142 ) {
V_253 . V_239 = V_135 -> V_239 ;
V_253 . V_241 = V_135 -> V_241 ;
V_253 . V_247 = V_135 -> V_247 ;
V_253 . V_249 = V_135 -> V_249 ;
V_253 . V_251 = V_135 -> V_251 ;
V_253 . V_252 = V_135 -> V_252 ;
V_253 . V_229 = V_135 -> V_229 ;
}
V_176 = ( const struct V_176 * )
& V_253 ;
#endif
if ( V_85 == V_129 )
F_175 () ;
else
F_176 () ;
#ifdef F_88
if ( V_85 == V_129 )
F_177 () ;
else if ( V_85 == V_86 )
F_178 () ;
else
F_179 () ;
#endif
}
