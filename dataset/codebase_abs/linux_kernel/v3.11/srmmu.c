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
return 0 ;
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
unsigned int V_44 ;
T_3 * V_45 ;
T_1 * V_1 ;
V_4 * V_19 ;
unsigned long V_46 , V_33 ;
unsigned long V_47 ;
V_44 = V_29 >> V_25 ;
V_48 = F_23 ( V_29 ,
V_27 , 0UL ) ;
memset ( V_48 , 0 , V_29 ) ;
V_49 =
F_23 ( F_24 ( V_44 ) * sizeof( long ) ,
V_50 , 0UL ) ;
F_25 ( & V_28 , V_49 , V_44 ) ;
V_51 = F_11 ( V_52 , V_52 ) ;
memset ( F_26 ( V_51 ) , 0 , V_52 ) ;
V_53 . V_45 = V_51 ;
F_27 ( V_31 , V_34 ) ;
V_46 = F_28 ( ( unsigned long ) V_48 ) ;
V_33 = V_31 ;
while ( V_33 < V_34 ) {
V_45 = F_29 ( V_33 ) ;
V_1 = F_30 ( F_26 ( V_45 ) , V_33 ) ;
V_19 = F_9 ( F_26 ( V_1 ) , V_33 ) ;
V_47 = ( ( V_46 >> 4 ) | V_54 | V_55 ) ;
if ( V_56 )
V_47 |= V_57 ;
F_4 ( F_26 ( V_19 ) , F_31 ( V_47 ) ) ;
V_33 += V_43 ;
V_46 += V_43 ;
}
F_32 () ;
F_33 () ;
}
T_3 * F_34 ( void )
{
T_3 * V_45 = NULL ;
V_45 = F_11 ( V_52 , V_52 ) ;
if ( V_45 ) {
T_3 * V_58 = F_29 ( 0 ) ;
memset ( V_45 , 0 , V_59 * sizeof( T_3 ) ) ;
memcpy ( V_45 + V_59 , V_58 + V_59 ,
( V_60 - V_59 ) * sizeof( T_3 ) ) ;
}
return V_45 ;
}
T_5 F_35 ( struct V_13 * V_14 , unsigned long V_18 )
{
unsigned long V_19 ;
struct V_15 * V_15 ;
if ( ( V_19 = ( unsigned long ) F_36 ( V_14 , V_18 ) ) == 0 )
return NULL ;
V_15 = F_37 ( F_5 ( V_19 ) >> V_16 ) ;
F_38 ( V_15 ) ;
return V_15 ;
}
void F_39 ( struct V_13 * V_14 , T_5 V_19 )
{
unsigned long V_61 ;
F_40 ( V_19 ) ;
V_61 = ( unsigned long ) F_41 ( V_19 ) ;
if ( V_61 == 0 )
F_17 () ;
V_61 = F_8 ( V_19 ) << V_16 ;
F_16 ( F_10 ( V_61 ) , V_62 ) ;
}
static inline void F_42 ( struct V_63 * V_64 )
{
V_64 -> V_65 -> V_66 = V_64 -> V_66 ;
V_64 -> V_66 -> V_65 = V_64 -> V_65 ;
}
static inline void F_43 ( struct V_63 * V_67 , struct V_63 * V_64 )
{
V_64 -> V_65 = V_67 ;
( V_64 -> V_66 = V_67 -> V_66 ) -> V_65 = V_64 ;
V_67 -> V_66 = V_64 ;
}
static inline void F_44 ( struct V_13 * V_68 , struct V_13 * V_14 )
{
struct V_63 * V_2 ;
V_2 = V_69 . V_65 ;
if ( V_2 != & V_69 ) {
F_42 ( V_2 ) ;
F_45 ( V_2 ) ;
V_14 -> V_70 = V_2 -> V_71 ;
V_2 -> V_72 = V_14 ;
return;
}
V_2 = V_73 . V_65 ;
if ( V_2 -> V_72 == V_68 )
V_2 = V_2 -> V_65 ;
if ( V_2 == & V_73 )
F_46 ( L_9 ) ;
F_47 ( V_2 -> V_72 ) ;
F_48 ( V_2 -> V_72 ) ;
F_42 ( V_2 ) ;
F_45 ( V_2 ) ;
V_2 -> V_72 -> V_70 = V_74 ;
V_2 -> V_72 = V_14 ;
V_14 -> V_70 = V_2 -> V_71 ;
}
static inline void F_49 ( int V_70 )
{
struct V_63 * V_75 ;
V_75 = V_76 + V_70 ;
F_42 ( V_75 ) ;
F_50 ( V_75 ) ;
}
static void T_4 F_51 ( int V_77 )
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
F_50 ( V_76 + V_78 ) ;
}
void F_52 ( struct V_13 * V_68 , struct V_13 * V_14 ,
struct V_80 * V_81 )
{
if ( V_14 -> V_70 == V_74 ) {
F_53 ( & V_82 ) ;
F_44 ( V_68 , V_14 ) ;
F_54 ( & V_82 ) ;
F_3 ( & V_83 [ V_14 -> V_70 ] , V_14 -> V_45 ) ;
}
if ( V_84 == V_85 )
F_55 () ;
if ( V_86 )
F_56 () ;
F_57 ( V_14 -> V_70 ) ;
}
static inline void F_58 ( unsigned long V_87 ,
unsigned long V_88 , int V_89 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
unsigned long V_32 ;
V_87 &= V_90 ;
V_3 = F_29 ( V_88 ) ;
V_6 = F_30 ( V_3 , V_88 ) ;
V_7 = F_9 ( V_6 , V_88 ) ;
V_32 = ( V_87 >> 4 ) | V_54 ;
V_32 |= ( V_89 << 28 ) ;
V_32 |= V_55 ;
F_59 ( V_88 ) ;
F_4 ( V_7 , F_31 ( V_32 ) ) ;
}
void F_60 ( unsigned int V_91 , unsigned long V_92 ,
unsigned long V_93 , unsigned int V_94 )
{
while ( V_94 != 0 ) {
V_94 -= V_43 ;
F_58 ( V_92 , V_93 , V_91 ) ;
V_93 += V_43 ;
V_92 += V_43 ;
}
F_33 () ;
}
static inline void F_61 ( unsigned long V_88 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
V_3 = F_29 ( V_88 ) ;
V_6 = F_30 ( V_3 , V_88 ) ;
V_7 = F_9 ( V_6 , V_88 ) ;
F_62 ( V_7 ) ;
}
void F_63 ( unsigned long V_88 , unsigned int V_94 )
{
while ( V_94 != 0 ) {
V_94 -= V_43 ;
F_61 ( V_88 ) ;
V_88 += V_43 ;
}
F_33 () ;
}
static void T_4 F_64 ( char * type )
{
F_65 ( L_10 , type ) ;
F_66 () ;
}
static void T_4 F_27 ( unsigned long V_95 ,
unsigned long V_96 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
while ( V_95 < V_96 ) {
V_3 = F_29 ( V_95 ) ;
if ( F_67 ( * ( T_3 * ) F_26 ( V_3 ) ) ) {
V_6 = F_11 (
V_97 , V_97 ) ;
if ( V_6 == NULL )
F_64 ( L_11 ) ;
memset ( F_26 ( V_6 ) , 0 , V_97 ) ;
F_68 ( F_26 ( V_3 ) , V_6 ) ;
}
V_6 = F_30 ( F_26 ( V_3 ) , V_95 ) ;
if ( F_1 ( * ( T_1 * ) F_26 ( V_6 ) ) ) {
V_7 = F_11 ( V_62 , V_62 ) ;
if ( V_7 == NULL )
F_64 ( L_12 ) ;
memset ( F_26 ( V_7 ) , 0 , V_62 ) ;
F_6 ( F_26 ( V_6 ) , V_7 ) ;
}
if ( V_95 > ( 0xffffffffUL - V_98 ) )
break;
V_95 = ( V_95 + V_98 ) & V_99 ;
}
}
static void T_4 F_69 ( unsigned long V_95 ,
unsigned long V_96 )
{
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
while ( V_95 < V_96 ) {
V_3 = F_29 ( V_95 ) ;
if ( F_67 ( * V_3 ) ) {
V_6 = F_11 ( V_97 , V_97 ) ;
if ( V_6 == NULL )
F_64 ( L_11 ) ;
memset ( V_6 , 0 , V_97 ) ;
F_68 ( V_3 , V_6 ) ;
}
V_6 = F_30 ( V_3 , V_95 ) ;
if ( F_1 ( * V_6 ) ) {
V_7 = F_11 ( V_62 ,
V_62 ) ;
if ( V_7 == NULL )
F_64 ( L_12 ) ;
memset ( V_7 , 0 , V_62 ) ;
F_6 ( V_6 , V_7 ) ;
}
if ( V_95 > ( 0xffffffffUL - V_98 ) )
break;
V_95 = ( V_95 + V_98 ) & V_99 ;
}
}
static inline unsigned long F_70 ( unsigned long V_33 )
{
unsigned long V_100 ;
if ( V_84 != V_85 ) {
V_33 &= V_90 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t" :
"=r" (retval) :
"r" (vaddr | 0x400), "i" (ASI_M_FLUSH_PROBE));
} else {
V_100 = F_71 ( V_33 , 0 ) ;
}
return V_100 ;
}
static void T_4 F_72 ( unsigned long V_95 ,
unsigned long V_96 )
{
unsigned long V_101 ;
unsigned long V_24 ;
T_3 * V_3 ;
T_1 * V_6 ;
V_4 * V_7 ;
int V_102 ;
while ( V_95 <= V_96 ) {
if ( V_95 == 0 )
break;
if ( V_95 == 0xfef00000 )
V_95 = V_103 ;
V_101 = F_70 ( V_95 ) ;
if ( ! V_101 ) {
V_95 += V_43 ;
continue;
}
V_102 = 0 ;
V_24 = V_95 - V_43 ;
if ( ! ( V_95 & ~ ( V_104 ) ) ) {
if ( F_70 ( V_24 + V_105 ) == V_101 )
V_102 = 1 ;
}
if ( ! ( V_95 & ~ ( V_106 ) ) ) {
if ( F_70 ( V_24 + V_107 ) == V_101 )
V_102 = 2 ;
}
V_3 = F_29 ( V_95 ) ;
if ( V_102 == 2 ) {
* ( T_3 * ) F_26 ( V_3 ) = F_73 ( V_101 ) ;
V_95 += V_107 ;
continue;
}
if ( F_67 ( * ( T_3 * ) F_26 ( V_3 ) ) ) {
V_6 = F_11 ( V_97 ,
V_97 ) ;
if ( V_6 == NULL )
F_64 ( L_11 ) ;
memset ( F_26 ( V_6 ) , 0 , V_97 ) ;
F_68 ( F_26 ( V_3 ) , V_6 ) ;
}
V_6 = F_30 ( F_26 ( V_3 ) , V_95 ) ;
if ( F_1 ( * ( T_1 * ) F_26 ( V_6 ) ) ) {
V_7 = F_11 ( V_62 , V_62 ) ;
if ( V_7 == NULL )
F_64 ( L_12 ) ;
memset ( F_26 ( V_7 ) , 0 , V_62 ) ;
F_6 ( F_26 ( V_6 ) , V_7 ) ;
}
if ( V_102 == 1 ) {
unsigned int V_108 ;
unsigned long * V_109 ;
V_108 = ( V_95 >> V_110 ) & 15 ;
V_109 = & V_6 -> V_12 [ V_108 ] ;
* ( unsigned long * ) F_26 ( V_109 ) = V_101 ;
V_95 += V_105 ;
continue;
}
V_7 = F_9 ( F_26 ( V_6 ) , V_95 ) ;
* ( V_4 * ) F_26 ( V_7 ) = F_31 ( V_101 ) ;
V_95 += V_43 ;
}
}
static void T_4 F_74 ( unsigned long V_33 , unsigned long V_111 )
{
T_3 * V_3 = F_29 ( V_33 ) ;
unsigned long V_112 ;
V_112 = F_75 ( V_111 >> 4 ) ;
* ( T_3 * ) F_26 ( V_3 ) = F_73 ( V_112 ) ;
}
static unsigned long T_4 F_76 ( unsigned long V_113 , int V_114 )
{
unsigned long V_115 = ( V_36 [ V_114 ] . V_116 & V_106 ) ;
unsigned long V_117 = ( V_113 & V_106 ) ;
unsigned long V_118 = F_77 ( V_113 + V_36 [ V_114 ] . V_37 ) ;
const unsigned long V_119 = V_120 ;
const unsigned long V_121 = V_120 + V_122 ;
if ( V_117 < V_119 || V_117 >= V_121 )
return V_117 ;
if ( V_118 > V_121 || V_118 < V_119 )
V_118 = V_121 ;
while ( V_117 < V_118 ) {
F_74 ( V_117 , V_115 ) ;
V_117 += V_107 ; V_115 += V_107 ;
}
return V_117 ;
}
static void T_4 F_78 ( void )
{
int V_9 ;
if ( V_111 > 0 ) {
F_74 ( V_120 , V_111 ) ;
}
for ( V_9 = 0 ; V_36 [ V_9 ] . V_37 != 0 ; V_9 ++ ) {
F_76 ( ( unsigned long ) F_79 ( V_36 [ V_9 ] . V_116 ) , V_9 ) ;
}
}
void T_4 F_80 ( void )
{
int V_9 ;
T_6 V_123 ;
char V_124 [ 128 ] ;
T_3 * V_45 ;
T_1 * V_1 ;
V_4 * V_19 ;
unsigned long V_125 ;
V_53 . V_70 = ( unsigned long ) V_74 ;
V_126 . V_95 = V_127 ;
if ( V_84 == V_128 )
V_129 = 65536 ;
else {
V_123 = F_81 ( V_130 ) ;
V_129 = 0 ;
while ( V_123 != 0 ) {
F_82 ( V_123 , L_13 , V_124 , sizeof( V_124 ) ) ;
if ( ! strcmp ( V_124 , L_14 ) ) {
V_129 = F_83 ( V_123 , L_15 , 0x8 ) ;
break;
}
V_123 = F_84 ( V_123 ) ;
}
}
if ( ! V_129 ) {
F_65 ( L_16 ) ;
F_66 () ;
}
V_125 = 0 ;
V_131 = F_85 ( & V_125 ) ;
F_21 () ;
F_22 () ;
F_72 ( 0xfe400000 , ( V_132 - V_43 ) ) ;
F_78 () ;
V_83 = F_11 ( V_129 * sizeof( T_2 ) , V_129 * sizeof( T_2 ) ) ;
V_133 = ( T_2 * ) F_5 ( ( unsigned long ) V_83 ) ;
for ( V_9 = 0 ; V_9 < V_129 ; V_9 ++ )
F_3 ( ( T_2 * ) F_26 ( & V_83 [ V_9 ] ) , V_51 ) ;
F_32 () ;
F_86 ( ( unsigned long ) V_133 ) ;
#ifdef F_87
V_134 -> V_135 () ;
#else
F_33 () ;
#endif
F_88 () ;
F_69 ( V_126 . V_95 , V_136 ) ;
F_69 ( V_137 , V_138 ) ;
F_69 (
F_89 ( V_139 - 1 ) , V_140 ) ;
F_69 ( V_141 , V_142 ) ;
V_45 = F_29 ( V_141 ) ;
V_1 = F_30 ( V_45 , V_141 ) ;
V_19 = F_9 ( V_1 , V_141 ) ;
V_143 = V_19 ;
F_32 () ;
F_33 () ;
F_51 ( V_129 ) ;
F_90 () ;
{
unsigned long V_144 [ V_145 ] ;
unsigned long V_146 [ V_145 ] ;
unsigned long V_147 ;
int V_148 ;
for ( V_148 = 0 ; V_148 < V_145 ; V_148 ++ )
V_144 [ V_148 ] = V_146 [ V_148 ] = 0 ;
V_147 = V_149 - V_150 ;
V_144 [ V_151 ] = V_147 ;
V_146 [ V_151 ] = V_147 - V_125 ;
V_147 = V_152 - V_149 ;
V_144 [ V_153 ] = V_147 ;
V_146 [ V_153 ] = V_147 - F_91 () ;
F_92 ( 0 , V_144 , V_150 , V_146 ) ;
}
}
void F_93 ( struct V_154 * V_155 )
{
F_94 ( V_155 ,
L_17
L_18
L_19
L_20 ,
V_156 ,
V_129 ,
V_29 ,
V_28 . V_30 << V_25 ) ;
}
int F_95 ( struct V_80 * V_81 , struct V_13 * V_14 )
{
V_14 -> V_70 = V_74 ;
return 0 ;
}
void F_96 ( struct V_13 * V_14 )
{
if ( V_14 -> V_70 != V_74 ) {
F_47 ( V_14 ) ;
F_3 ( & V_83 [ V_14 -> V_70 ] , V_51 ) ;
F_48 ( V_14 ) ;
F_53 ( & V_82 ) ;
F_49 ( V_14 -> V_70 ) ;
F_54 ( & V_82 ) ;
V_14 -> V_70 = V_74 ;
}
}
static void T_4 F_97 ( void )
{
F_65 ( L_21 ) ;
F_66 () ;
}
static void T_4 F_98 ( void )
{
T_6 V_157 ;
int V_158 ;
char V_124 [ 128 ] ;
#ifdef F_87
int V_159 = 0 ;
unsigned long V_160 = 0 ;
unsigned long V_161 = 0x10000000 ;
#endif
V_157 = F_81 ( V_130 ) ;
while ( ( V_157 = F_84 ( V_157 ) ) != 0 ) {
F_82 ( V_157 , L_13 , V_124 , sizeof( V_124 ) ) ;
if ( ! strcmp ( V_124 , L_14 ) ) {
V_162 = F_99 ( V_157 , L_22 ) ;
if ( V_162 == - 1 ) {
F_65 ( L_23 ) ;
F_66 () ;
}
V_158 = F_99 ( V_157 , L_24 ) ;
if ( V_158 == - 1 ) {
F_65 ( L_25 ) ;
F_66 () ;
}
V_163 = V_158 * V_162 ;
#ifdef F_87
if ( V_163 > V_160 )
V_160 = V_163 ;
if ( V_162 < V_161 )
V_161 = V_162 ;
V_159 ++ ;
if ( V_159 >= V_164 || ! F_100 ( V_159 ) )
break;
#else
break;
#endif
}
}
if ( V_157 == 0 ) {
F_65 ( L_26 ) ;
F_66 () ;
}
#ifdef F_87
V_163 = V_160 ;
V_162 = V_161 ;
#endif
F_12 ( L_27 ,
( int ) V_163 , ( int ) V_162 ) ;
}
static void F_101 ( void )
{
volatile unsigned long V_165 ;
unsigned long V_166 = F_102 () ;
F_103 () ;
V_166 &= ~ ( V_167 ) ;
V_166 |= ( V_168 | V_169 ) ;
V_166 |= ( V_170 ) ;
F_104 ( V_166 ) ;
#if 0
hyper_clear_all_tags();
#endif
F_105 ( V_171 | V_172 ) ;
F_56 () ;
V_165 = F_106 () ;
V_165 = F_107 () ;
}
static void T_4 F_108 ( void )
{
V_156 = L_28 ;
V_173 = V_174 ;
F_98 () ;
V_86 = 1 ;
V_175 = & V_176 ;
F_88 = F_101 ;
F_109 () ;
}
static void F_110 ( void )
{
unsigned long V_166 ;
F_111 () ;
V_166 = F_102 () ;
V_166 |= ( V_177 | V_178 ) ;
V_166 &= ~ ( V_179 ) ;
F_104 ( V_166 ) ;
}
static void T_4 F_112 ( void )
{
unsigned long V_180 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t"
"srl %0, 0x18, %0\n\t" :
"=r" (swift_rev) :
"r" (SWIFT_MASKID_ADDR), "i" (ASI_M_BYPASS));
V_156 = L_29 ;
switch ( V_180 ) {
case 0x11 :
case 0x20 :
case 0x23 :
case 0x30 :
V_173 = V_181 ;
V_182 |= ( V_183 | V_184 ) ;
break;
case 0x25 :
case 0x31 :
V_173 = V_185 ;
V_182 |= V_184 ;
break;
default:
V_173 = V_186 ;
break;
}
V_175 = & V_187 ;
V_188 = 0 ;
F_88 = F_110 ;
}
static void F_113 ( void )
{
F_114 () ;
F_115 () ;
}
static void F_116 ( struct V_13 * V_14 )
{
F_117 (mm)
F_114 () ;
F_115 () ;
V_189
}
static void F_118 ( struct V_190 * V_191 , unsigned long V_95 , unsigned long V_96 )
{
F_117 (vma->vm_mm)
F_114 () ;
F_115 () ;
V_189
}
static void F_119 ( struct V_190 * V_191 , unsigned long V_15 )
{
F_117 (vma->vm_mm)
F_114 () ;
if ( V_191 -> V_192 & V_193 )
F_120 () ;
F_121 () ;
V_189
}
static void F_122 ( unsigned long V_15 )
{
#ifdef F_123
volatile unsigned long V_165 ;
if ( F_70 ( V_15 ) )
F_124 ( V_15 ) ;
V_165 = F_107 () ;
#endif
}
static void F_125 ( struct V_13 * V_14 , unsigned long V_194 )
{
}
static void F_126 ( unsigned long V_15 )
{
F_121 () ;
}
static void F_127 ( void )
{
F_128 () ;
}
static void F_129 ( struct V_13 * V_14 )
{
F_117 (mm)
F_128 () ;
V_189
}
static void F_130 ( struct V_190 * V_191 , unsigned long V_95 , unsigned long V_96 )
{
F_117 (vma->vm_mm)
F_128 () ;
V_189
}
static void F_131 ( struct V_190 * V_191 , unsigned long V_15 )
{
F_117 (vma->vm_mm)
F_128 () ;
V_189
}
static void F_132 ( void )
{
unsigned long V_166 = F_102 () ;
unsigned long V_195 ;
F_113 () ;
V_166 &= ~ ( V_196 | V_197 ) ;
V_166 &= ~ ( V_198 ) ;
F_104 ( V_166 ) ;
V_195 = F_133 () ;
#ifdef F_123
V_195 |= ( V_199 ) ;
V_195 &= ~ ( V_200 | V_201 ) ;
#else
V_195 |= ( V_199 | V_201 ) ;
V_195 &= ~ ( V_200 ) ;
#endif
switch ( V_195 & 7 ) {
case 0 :
case 7 :
break;
default:
V_195 |= ( V_202 ) ;
}
F_134 ( V_195 ) ;
V_166 |= ( V_196 | V_197 ) ;
V_166 |= ( V_203 ) ;
F_104 ( V_166 ) ;
}
static void T_4 F_135 ( void )
{
V_156 = L_30 ;
V_173 = V_204 ;
V_175 = & V_205 ;
F_88 = F_132 ;
}
static void F_136 ( void )
{
unsigned long V_166 = F_102 () ;
F_137 () ;
F_138 () ;
V_166 &= ~ V_206 ;
V_166 |= ( V_207 | V_208 ) ;
F_104 ( V_166 ) ;
}
static void T_4 F_139 ( void )
{
V_156 = L_31 ;
V_173 = V_209 ;
V_175 = & V_210 ;
F_88 = F_136 ;
F_140 () ;
}
static void F_141 ( void )
{
unsigned long V_166 = F_102 () ;
static int V_211 ;
if ( V_212 ) {
unsigned long V_213 = F_142 () ;
V_213 |= ( V_214 | V_215 | V_216 ) ;
V_213 &= ~ ( V_217 ) ;
F_143 ( V_213 ) ;
V_166 |= V_218 ;
} else {
unsigned long V_219 ;
V_166 &= ~ ( V_218 ) ;
if ( V_211 ++ ) {
V_219 = F_144 () ;
V_219 &= ~ ( V_220 ) ;
F_145 ( V_219 ) ;
F_146 () ;
}
}
V_166 |= V_221 ;
V_166 |= ( V_222 | V_223 ) ;
V_166 |= V_224 ;
V_166 &= ~ ( V_225 ) ;
F_104 ( V_166 ) ;
}
static void T_4 F_147 ( void )
{
unsigned long V_166 = F_102 () ;
if ( V_166 & V_226 ) {
V_156 = L_32 ;
V_212 = 0 ;
F_146 () ;
V_227 . V_228 = V_229 ;
#ifdef F_87
V_230 . V_228 = V_229 ;
#endif
V_188 = 0 ;
} else {
V_156 = L_33 ;
V_212 = 1 ;
V_56 = 1 ;
}
V_175 = ( const struct V_175 * )
& V_227 ;
#ifdef F_87
if ( V_84 == V_128 )
V_175 = ( const struct V_175 * )
& V_230 ;
#endif
F_88 = F_141 ;
}
static void T_4 F_148 ( void )
{
unsigned long V_166 , V_231 ;
unsigned long V_232 , V_233 , V_234 , V_235 ;
V_173 = V_236 ;
V_182 = 0 ;
V_166 = F_102 () ; V_231 = F_149 () ;
V_232 = ( V_166 & 0xf0000000 ) >> 28 ;
V_233 = ( V_166 & 0x0f000000 ) >> 24 ;
V_234 = ( V_231 >> 28 ) & 0xf ;
V_235 = ( V_231 >> 24 ) & 0xf ;
if ( V_84 == V_85 ) {
F_150 () ;
return;
}
if ( V_232 == 1 ) {
switch ( V_233 ) {
case 7 :
F_108 () ;
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
F_65 ( L_34 ) ;
F_66 () ;
break;
}
return;
}
if ( V_234 == 0 && V_235 == 5 ) {
F_135 () ;
return;
}
if ( V_234 == 0 && V_235 == 4 ) {
T_6 V_123 ;
char V_124 [ 128 ] ;
V_123 = F_81 ( V_130 ) ;
while ( ( V_123 = F_84 ( V_123 ) ) != 0 ) {
F_82 ( V_123 , L_13 , V_124 , sizeof( V_124 ) ) ;
if ( ! strcmp ( V_124 , L_14 ) ) {
if ( ! F_83 ( V_123 , L_35 , 1 ) &&
F_83 ( V_123 , L_36 , 1 ) == 5 ) {
F_135 () ;
return;
}
break;
}
}
F_112 () ;
return;
}
if ( V_234 == 4 &&
( ( V_235 == 0 ) ||
( ( V_235 == 1 ) && ( V_232 == 0 ) && ( V_233 == 0 ) ) ) ) {
F_147 () ;
return;
}
if ( V_234 == 4 && V_235 == 1 && ( V_232 || V_233 ) ) {
F_139 () ;
return;
}
F_97 () ;
}
static void F_151 ( unsigned long V_15 )
{
F_152 ( ( V_237 ) V_134 -> V_228 , V_15 ) ;
V_134 -> V_228 ( V_15 ) ;
}
static void F_153 ( void )
{
F_154 ( ( V_237 ) V_134 -> V_238 ) ;
V_134 -> V_238 () ;
}
static void F_155 ( void )
{
F_154 ( ( V_237 ) V_134 -> V_135 ) ;
V_134 -> V_135 () ;
}
static void F_156 ( struct V_13 * V_14 )
{
if ( V_14 -> V_70 != V_74 ) {
T_7 V_239 ;
F_157 ( & V_239 , F_158 ( V_14 ) ) ;
F_159 ( F_160 () , & V_239 ) ;
if ( ! F_161 ( & V_239 ) )
F_152 ( ( V_237 ) V_134 -> V_240 , ( unsigned long ) V_14 ) ;
V_134 -> V_240 ( V_14 ) ;
}
}
static void F_162 ( struct V_13 * V_14 )
{
if ( V_14 -> V_70 != V_74 ) {
T_7 V_239 ;
F_157 ( & V_239 , F_158 ( V_14 ) ) ;
F_159 ( F_160 () , & V_239 ) ;
if ( ! F_161 ( & V_239 ) ) {
F_152 ( ( V_237 ) V_134 -> V_241 , ( unsigned long ) V_14 ) ;
if ( F_163 ( & V_14 -> V_242 ) == 1 && V_243 -> V_244 == V_14 )
F_157 ( F_158 ( V_14 ) ,
F_164 ( F_160 () ) ) ;
}
V_134 -> V_241 ( V_14 ) ;
}
}
static void F_165 ( struct V_190 * V_191 ,
unsigned long V_95 ,
unsigned long V_96 )
{
struct V_13 * V_14 = V_191 -> V_245 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_239 ;
F_157 ( & V_239 , F_158 ( V_14 ) ) ;
F_159 ( F_160 () , & V_239 ) ;
if ( ! F_161 ( & V_239 ) )
F_166 ( ( V_237 ) V_134 -> V_246 ,
( unsigned long ) V_191 , V_95 , V_96 ) ;
V_134 -> V_246 ( V_191 , V_95 , V_96 ) ;
}
}
static void F_167 ( struct V_190 * V_191 ,
unsigned long V_95 ,
unsigned long V_96 )
{
struct V_13 * V_14 = V_191 -> V_245 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_239 ;
F_157 ( & V_239 , F_158 ( V_14 ) ) ;
F_159 ( F_160 () , & V_239 ) ;
if ( ! F_161 ( & V_239 ) )
F_166 ( ( V_237 ) V_134 -> V_247 ,
( unsigned long ) V_191 , V_95 , V_96 ) ;
V_134 -> V_247 ( V_191 , V_95 , V_96 ) ;
}
}
static void F_168 ( struct V_190 * V_191 , unsigned long V_15 )
{
struct V_13 * V_14 = V_191 -> V_245 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_239 ;
F_157 ( & V_239 , F_158 ( V_14 ) ) ;
F_159 ( F_160 () , & V_239 ) ;
if ( ! F_161 ( & V_239 ) )
F_169 ( ( V_237 ) V_134 -> V_248 ,
( unsigned long ) V_191 , V_15 ) ;
V_134 -> V_248 ( V_191 , V_15 ) ;
}
}
static void F_170 ( struct V_190 * V_191 , unsigned long V_15 )
{
struct V_13 * V_14 = V_191 -> V_245 ;
if ( V_14 -> V_70 != V_74 ) {
T_7 V_239 ;
F_157 ( & V_239 , F_158 ( V_14 ) ) ;
F_159 ( F_160 () , & V_239 ) ;
if ( ! F_161 ( & V_239 ) )
F_169 ( ( V_237 ) V_134 -> V_249 ,
( unsigned long ) V_191 , V_15 ) ;
V_134 -> V_249 ( V_191 , V_15 ) ;
}
}
static void F_171 ( unsigned long V_15 )
{
#if 1
F_152 ( ( V_237 ) V_134 -> V_250 , V_15 ) ;
#endif
V_134 -> V_250 ( V_15 ) ;
}
static void F_172 ( struct V_13 * V_14 , unsigned long V_194 )
{
T_7 V_239 ;
F_157 ( & V_239 , F_158 ( V_14 ) ) ;
F_159 ( F_160 () , & V_239 ) ;
if ( ! F_161 ( & V_239 ) )
F_169 ( ( V_237 ) V_134 -> V_251 ,
( unsigned long ) V_14 , V_194 ) ;
V_134 -> V_251 ( V_14 , V_194 ) ;
}
void T_4 F_173 ( void )
{
extern void V_252 ( void ) ;
extern void V_253 ( void ) ;
F_148 () ;
#ifdef F_87
V_134 = V_175 ;
if ( V_84 == V_128 || V_84 == V_85 ) {
V_254 . V_135 = V_134 -> V_135 ;
V_254 . V_241 = V_134 -> V_241 ;
V_254 . V_247 = V_134 -> V_247 ;
V_254 . V_249 = V_134 -> V_249 ;
}
if ( F_88 == F_141 ) {
V_254 . V_238 = V_134 -> V_238 ;
V_254 . V_240 = V_134 -> V_240 ;
V_254 . V_246 = V_134 -> V_246 ;
V_254 . V_248 = V_134 -> V_248 ;
V_254 . V_250 = V_134 -> V_250 ;
V_254 . V_251 = V_134 -> V_251 ;
V_254 . V_228 = V_134 -> V_228 ;
}
V_175 = ( const struct V_175 * )
& V_254 ;
#endif
if ( V_84 == V_128 )
V_253 () ;
else
V_252 () ;
#ifdef F_87
if ( V_84 == V_128 )
F_174 () ;
else if ( V_84 == V_85 )
F_175 () ;
else
F_176 () ;
#endif
}
