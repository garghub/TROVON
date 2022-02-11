static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return ( void * ) V_3 - ( ( sizeof( struct V_1 ) + 31 ) & ~ 31 ) ;
}
static inline unsigned long F_2 ( unsigned long V_4 )
{
return ( ~ V_4 + 1 ) & ( V_5 - 1UL ) ;
}
static inline struct V_6 * F_3 ( unsigned long V_7 ,
unsigned int V_8 )
{
struct V_6 * V_9 ;
V_9 = F_4 ( V_7 + V_5 - 1 , V_8 ) ;
if ( F_5 ( V_9 ) ) {
int V_10 = F_2 ( ( unsigned long ) V_9 -> V_11 ) ;
if ( V_10 )
F_6 ( V_9 , V_10 ) ;
}
return V_9 ;
}
static inline unsigned long F_7 ( void * V_12 , unsigned long V_13 )
{
#ifdef F_8
V_13 <<= 57 ;
return V_13 | ( 0xaUL << V_14 ) | V_15 |
( ( unsigned long ) V_12 & V_16 ) ;
#else
return F_9 ( V_12 ) ;
#endif
}
static inline T_1 F_10 ( T_1 V_17 , T_1 V_18 )
{
return ( V_17 << 10 ) | ( V_18 << 2 ) ;
}
static int F_11 ( struct V_19 * V_19 )
{
T_1 V_20 ;
do {
V_20 = F_12 () ;
} while ( ! ( V_20 & 2 ) );
return V_20 & 1 ;
}
static int F_13 ( struct V_19 * V_19 )
{
int V_21 ;
F_14 ( F_10 ( 500 , 65 ) ) ;
V_21 = F_11 ( V_19 ) ;
F_14 ( F_10 ( 0 , 500 ) ) ;
F_11 ( V_19 ) ;
return V_21 ;
}
static inline int F_15 ( struct V_19 * V_19 )
{
int V_22 ;
F_14 ( F_10 ( 6 , 13 ) ) ;
V_22 = F_11 ( V_19 ) ;
F_14 ( F_10 ( 0 , 100 ) ) ;
F_11 ( V_19 ) ;
return V_22 ;
}
static inline void F_16 ( struct V_19 * V_19 , int V_23 )
{
if ( V_23 )
F_14 ( F_10 ( 6 , 110 ) ) ;
else
F_14 ( F_10 ( 80 , 30 ) ) ;
F_11 ( V_19 ) ;
}
static T_1 F_17 ( struct V_19 * V_19 )
{
T_1 V_22 = 0 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ )
V_22 = ( V_22 >> 1 ) | ( F_15 ( V_19 ) << 7 ) ;
return V_22 ;
}
static void F_18 ( struct V_19 * V_19 , int V_25 )
{
int V_24 , V_23 ;
for ( V_24 = 8 ; V_24 ; V_24 -- ) {
V_23 = V_25 & 1 ;
V_25 >>= 1 ;
F_16 ( V_19 , V_23 ) ;
}
}
static T_2 F_19 ( struct V_19 * V_19 , int * V_26 )
{
int V_27 , V_28 , V_29 , V_30 ;
T_2 V_31 = 0 ;
F_13 ( V_19 ) ;
F_18 ( V_19 , 0xf0 ) ;
for ( V_29 = 0 , V_30 = 0 ; V_29 < 64 ; V_29 ++ ) {
V_27 = F_15 ( V_19 ) ;
V_28 = F_15 ( V_19 ) ;
if ( V_27 && V_28 ) {
F_20 ( L_1 ) ;
* V_26 = 0 ;
return 0 ;
}
if ( ! V_27 && ! V_28 ) {
if ( V_29 == * V_26 ) {
V_31 |= 1UL << V_29 ;
} else if ( V_29 > * V_26 ) {
V_31 &= ~ ( 1UL << V_29 ) ;
V_30 = V_29 ;
} else if ( ( V_31 & ( 1UL << V_29 ) ) == 0 )
V_30 = V_29 ;
F_16 ( V_19 , V_31 & ( 1UL << V_29 ) ) ;
continue;
} else {
if ( V_27 )
V_31 |= 1UL << V_29 ;
else
V_31 &= ~ ( 1UL << V_29 ) ;
F_16 ( V_19 , V_27 ) ;
continue;
}
}
* V_26 = V_30 ;
return V_31 ;
}
static int F_21 ( struct V_19 * V_19 )
{
const char * V_32 = L_2 ;
const char * type = V_32 ;
T_3 V_33 ;
T_3 V_34 [ 6 ] ;
int V_35 = 0 , V_24 ;
while ( 1 ) {
T_2 V_36 ;
V_36 = F_19 ( V_19 , & V_35 ) ;
switch ( V_36 & 0xff ) {
case 0x91 :
type = L_3 ;
break;
default:
if ( V_35 == 0 ) {
return - 1 ;
}
continue;
}
F_13 ( V_19 ) ;
F_18 ( V_19 , 0x55 ) ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ )
F_18 ( V_19 , ( V_36 >> ( V_24 << 3 ) ) & 0xff ) ;
V_36 >>= 8 ;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
V_34 [ V_24 ] = V_36 & 0xff ;
V_36 >>= 8 ;
}
V_33 = V_36 & 0xff ;
break;
}
F_20 ( L_4 , type ) ;
if ( type != V_32 )
F_20 ( L_5 , V_34 , V_33 ) ;
F_20 ( L_6 ) ;
return 0 ;
}
static void F_22 ( struct V_2 * V_37 )
{
struct V_19 * V_19 = V_37 -> V_38 ;
T_3 V_39 [ 14 ] ;
int V_40 = 2 ;
int V_24 ;
F_23 ( 1 << 21 ) ;
while ( V_40 -- ) {
if ( ! F_21 ( V_19 ) )
break;
F_24 ( 500 ) ;
}
if ( V_40 < 0 ) {
F_20 ( L_7 ) ;
return;
}
F_18 ( V_19 , 0xf0 ) ;
F_18 ( V_19 , 0x00 ) ;
F_18 ( V_19 , 0x00 ) ;
for ( V_24 = 13 ; V_24 >= 0 ; V_24 -- )
V_39 [ V_24 ] = F_17 ( V_19 ) ;
for ( V_24 = 2 ; V_24 < 8 ; V_24 ++ )
F_1 ( V_37 ) -> V_41 [ V_24 - 2 ] = V_39 [ V_24 ] ;
}
static void F_25 ( struct V_2 * V_37 )
{
F_22 ( V_37 ) ;
F_20 ( L_8 , F_1 ( V_37 ) -> V_41 ) ;
}
static void F_26 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
F_28 ( ( V_3 -> V_41 [ 5 ] << 8 ) | V_3 -> V_41 [ 4 ] ) ;
F_29 ( ( V_3 -> V_41 [ 3 ] << 24 ) | ( V_3 -> V_41 [ 2 ] << 16 ) |
( V_3 -> V_41 [ 1 ] << 8 ) | V_3 -> V_41 [ 0 ] ) ;
}
static int F_30 ( struct V_1 * V_3 , void * V_4 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_42 * V_43 = V_4 ;
memcpy ( V_3 -> V_41 , V_43 -> V_44 , V_3 -> V_45 ) ;
F_31 ( & V_37 -> V_46 ) ;
F_26 ( V_3 ) ;
F_32 ( & V_37 -> V_46 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_3 , int V_47 , int V_36 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
while ( F_34 () & V_48 ) ;
F_35 ( ( V_47 << V_49 ) | V_36 | V_50 ) ;
while ( F_34 () & V_48 ) ;
return F_36 () & V_51 ;
}
static void F_37 ( struct V_1 * V_3 , int V_47 , int V_36 , int V_11 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
while ( F_34 () & V_48 ) ;
F_38 ( V_11 ) ;
F_35 ( ( V_47 << V_49 ) | V_36 ) ;
while ( F_34 () & V_48 ) ;
}
static struct V_52 * F_39 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
V_3 -> V_53 . V_54 += ( F_40 () & V_55 ) ;
return & V_3 -> V_53 ;
}
static void F_41 ( struct V_6 * V_9 , T_4 V_56 , int V_57 )
{
struct V_58 * V_59 = F_42 ( V_9 ) ;
T_4 V_60 , V_61 ;
unsigned int V_62 ;
struct V_63 * V_64 ;
T_5 * V_65 ;
unsigned char * V_66 ;
if ( V_59 -> V_67 != F_43 ( V_68 ) )
return;
V_64 = (struct V_63 * ) ( ( char * ) V_59 + V_69 ) ;
if ( V_64 -> V_70 & F_43 ( V_71 | V_72 ) )
return;
V_62 = V_64 -> V_73 ;
if ( V_62 != V_74 && V_62 != V_75 )
return;
V_60 = V_56 +
( V_64 -> V_76 - ( V_64 -> V_77 << 2 ) ) +
F_43 ( ( T_5 ) V_64 -> V_73 ) +
( V_64 -> V_78 >> 16 ) + ( V_64 -> V_78 & 0xffff ) +
( V_64 -> V_79 >> 16 ) + ( V_64 -> V_79 & 0xffff ) ;
V_65 = ( T_5 * ) V_59 ;
V_61 = V_65 [ 0 ] + V_65 [ 1 ] + V_65 [ 2 ] + V_65 [ 3 ] + V_65 [ 4 ] + V_65 [ 5 ] + V_65 [ 6 ] ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_60 += 0xffff ^ V_61 ;
V_66 = ( char * ) V_59 + V_57 ;
if ( V_57 & 1 ) {
V_60 += 0xffff ^ ( T_5 ) ( ( V_66 [ 1 ] << 8 ) | V_66 [ 0 ] ) ;
V_60 += 0xffff ^ ( T_5 ) ( ( V_66 [ 3 ] << 8 ) | V_66 [ 2 ] ) ;
} else {
V_60 += 0xffff ^ ( T_5 ) ( ( V_66 [ 0 ] << 8 ) | V_66 [ 1 ] ) ;
V_60 += 0xffff ^ ( T_5 ) ( ( V_66 [ 2 ] << 8 ) | V_66 [ 3 ] ) ;
}
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
if ( V_60 == 0xffff )
V_9 -> V_80 = V_81 ;
}
static inline void F_44 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_6 * V_9 , * V_82 ;
struct V_19 * V_19 = V_37 -> V_38 ;
int V_83 , V_84 , V_57 ;
struct V_85 * V_86 ;
unsigned long * V_87 ;
T_1 V_88 , V_89 ;
V_87 = ( unsigned long * ) V_37 -> V_87 ;
V_83 = V_37 -> V_90 ;
V_84 = V_37 -> V_91 ;
V_9 = V_37 -> V_92 [ V_83 ] ;
V_86 = (struct V_85 * ) ( V_9 -> V_11 - V_93 ) ;
V_88 = F_45 ( V_86 -> V_88 ) ;
while ( V_88 & V_94 ) {
V_89 = F_45 ( V_86 -> V_89 ) ;
if ( V_89 & V_95 ) {
V_57 = ( ( V_88 >> V_96 ) & 0x7ff ) - 4 ;
F_46 ( V_9 , V_57 ) ;
V_9 -> V_73 = F_47 ( V_9 , V_3 ) ;
V_82 = F_3 ( V_97 , V_98 ) ;
if ( ! V_82 ) {
V_3 -> V_53 . V_99 ++ ;
V_82 = V_9 ;
goto V_100;
}
if ( F_5 ( V_3 -> V_101 & V_102 ) )
F_41 ( V_9 ,
V_88 & V_103 , V_57 ) ;
F_48 ( V_9 ) ;
V_37 -> V_92 [ V_83 ] = NULL ;
F_49 ( V_82 , ( 1664 + V_93 ) ) ;
V_86 = (struct V_85 * ) V_82 -> V_11 ;
F_6 ( V_82 , V_93 ) ;
V_3 -> V_53 . V_104 ++ ;
V_3 -> V_53 . V_105 += V_57 ;
} else {
V_82 = V_9 ;
V_3 -> V_53 . V_106 ++ ;
}
if ( V_89 & V_107 )
V_3 -> V_53 . V_108 ++ ;
if ( V_89 & V_109 )
V_3 -> V_53 . V_110 ++ ;
V_100:
V_37 -> V_92 [ V_84 ] = V_82 ;
V_87 [ V_84 ] = F_50 ( F_7 ( V_86 , 1 ) ) ;
V_86 -> V_88 = 0 ;
V_84 = ( V_84 + 1 ) & 511 ;
V_83 = ( V_83 + 1 ) & 511 ;
V_9 = V_37 -> V_92 [ V_83 ] ;
V_86 = (struct V_85 * ) ( V_9 -> V_11 - V_93 ) ;
V_88 = F_45 ( V_86 -> V_88 ) ;
}
F_51 ( ( V_84 << 3 ) | V_111 ) ;
V_37 -> V_91 = V_84 ;
V_37 -> V_90 = V_83 ;
}
static inline void F_52 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
unsigned long V_112 , V_113 ;
struct V_19 * V_19 = V_37 -> V_38 ;
int V_114 , V_115 ;
struct V_6 * V_9 ;
T_1 V_116 ;
F_53 ( & V_37 -> V_46 ) ;
V_116 = F_54 () ;
V_114 = ( V_116 >> 7 ) & 127 ;
V_115 = V_37 -> V_117 ;
V_112 = 0 ;
V_113 = 0 ;
while ( V_115 != V_114 ) {
V_112 ++ ;
V_9 = V_37 -> V_118 [ V_115 ] ;
V_113 += V_9 -> V_57 ;
F_55 ( V_9 ) ;
V_37 -> V_118 [ V_115 ] = NULL ;
V_115 = ( V_115 + 1 ) & 127 ;
V_116 = F_54 () ;
V_114 = ( V_116 >> 7 ) & 127 ;
}
V_3 -> V_53 . V_119 += V_112 ;
V_3 -> V_53 . V_120 += V_113 ;
V_37 -> V_121 -= V_112 ;
if ( V_37 -> V_121 < 128 )
F_56 ( V_3 ) ;
V_37 -> V_117 = V_115 ;
F_57 ( & V_37 -> V_46 ) ;
}
static void F_58 ( struct V_1 * V_3 , T_1 V_122 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
unsigned char * V_123 = V_3 -> V_124 ;
F_53 ( & V_37 -> V_46 ) ;
if ( V_122 & V_125 )
F_20 ( V_126 L_9 , V_123 ) ;
if ( V_122 & V_127 )
F_20 ( V_126 L_10 , V_123 ) ;
if ( V_122 & V_128 )
F_20 ( V_126 L_11 , V_123 ) ;
if ( V_122 & V_129 )
F_20 ( V_126 L_12 , V_123 ) ;
if ( V_122 & V_130 )
F_20 ( V_126 L_13 , V_123 ) ;
if ( V_122 & V_131 )
F_20 ( V_126 L_14 , V_123 ) ;
F_59 ( V_37 ) ;
F_60 ( V_3 ) ;
F_61 ( V_37 ) ;
F_56 ( V_3 ) ;
F_57 ( & V_37 -> V_46 ) ;
}
static T_6 F_62 ( int V_132 , void * V_133 )
{
struct V_1 * V_3 = (struct V_1 * ) V_133 ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
const T_1 V_134 = V_135 | V_125 | V_127 |
V_128 | V_129 | V_130 |
V_136 | V_131 ;
T_1 V_122 ;
V_122 = F_63 () & V_134 ;
F_64 ( V_122 ) ;
( void ) F_63 () ;
if ( V_122 & ( V_125 | V_127 | V_128 |
V_129 | V_130 | V_131 ) )
F_58 ( V_3 , V_122 ) ;
if ( V_122 & V_135 )
F_44 ( V_3 ) ;
if ( V_122 & V_136 )
F_52 ( V_3 ) ;
return V_137 ;
}
static inline void F_65 ( struct V_2 * V_37 )
{
struct V_19 * V_19 = V_37 -> V_38 ;
if ( V_37 -> V_138 . V_139 ) {
F_66 ( V_140 ) ;
V_37 -> V_141 |= V_142 ;
} else {
F_66 ( V_143 ) ;
V_37 -> V_141 &= ~ V_142 ;
}
F_67 ( V_37 -> V_141 ) ;
}
static void F_68 ( unsigned long V_11 )
{
struct V_2 * V_37 = (struct V_2 * ) V_11 ;
F_69 ( & V_37 -> V_138 , 1 , 0 ) ;
F_65 ( V_37 ) ;
V_37 -> F_68 . V_144 = V_145 + ( ( 12 * V_146 ) / 10 ) ;
F_70 ( & V_37 -> F_68 ) ;
}
static int F_61 ( struct V_2 * V_37 )
{
struct V_1 * V_3 = F_1 ( V_37 ) ;
int V_24 , V_147 = 0 , V_148 = 0 ;
int V_149 = 1 ;
T_7 V_150 ;
for ( V_24 = 0 ; V_24 < 32 ; V_24 ++ ) {
V_150 = F_33 ( V_3 , V_24 , V_151 ) ;
if ( V_150 != 0xffff && V_150 != 0x0000 ) {
V_147 = 1 ;
break;
}
}
if ( ! V_147 ) {
if ( V_149 )
V_24 = 31 ;
else {
V_37 -> V_138 . V_152 = - 1 ;
V_148 = - V_153 ;
goto V_154;
}
}
V_37 -> V_138 . V_152 = V_24 ;
V_154:
return V_148 ;
}
static void F_71 ( struct V_2 * V_37 )
{
V_37 -> F_68 . V_144 = V_145 + ( 12 * V_146 ) / 10 ;
V_37 -> F_68 . V_11 = ( unsigned long ) V_37 ;
V_37 -> F_68 . V_155 = F_68 ;
F_70 ( & V_37 -> F_68 ) ;
}
static inline void F_72 ( struct V_2 * V_37 )
{
struct V_6 * V_9 ;
int V_24 ;
for ( V_24 = V_37 -> V_90 ; V_24 & 15 ; V_24 ++ ) {
V_37 -> V_92 [ V_37 -> V_91 ] = V_37 -> V_92 [ V_37 -> V_90 ] ;
V_37 -> V_87 [ V_37 -> V_91 ++ ] = V_37 -> V_87 [ V_37 -> V_90 ++ ] ;
}
V_37 -> V_91 &= 511 ;
V_37 -> V_90 &= 511 ;
for ( V_24 = V_37 -> V_90 ; V_24 != V_37 -> V_91 ; V_24 = ( V_24 + 1 ) & 511 ) {
struct V_85 * V_86 ;
V_9 = V_37 -> V_92 [ V_24 ] ;
V_86 = (struct V_85 * ) ( V_9 -> V_11 - V_93 ) ;
V_86 -> V_88 = 0 ;
}
}
static inline void F_73 ( struct V_2 * V_37 )
{
struct V_6 * V_9 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 128 ; V_24 ++ ) {
V_9 = V_37 -> V_118 [ V_24 ] ;
if ( V_9 ) {
V_37 -> V_118 [ V_24 ] = NULL ;
F_74 ( V_9 ) ;
}
V_37 -> V_156 [ V_24 ] . V_157 = 0 ;
}
V_37 -> V_158 = 0 ;
V_37 -> V_117 = 0 ;
}
static void F_75 ( struct V_2 * V_37 )
{
struct V_6 * V_9 ;
int V_83 , V_84 ;
if ( V_37 -> V_156 ) {
F_73 ( V_37 ) ;
F_76 ( ( unsigned long ) V_37 -> V_156 , 2 ) ;
V_37 -> V_156 = NULL ;
}
if ( V_37 -> V_87 ) {
V_84 = V_37 -> V_90 ;
V_83 = V_37 -> V_91 ;
while ( V_84 != V_83 ) {
V_9 = V_37 -> V_92 [ V_84 ] ;
if ( V_9 )
F_74 ( V_9 ) ;
V_84 = ( V_84 + 1 ) & 511 ;
}
F_77 ( ( unsigned long ) V_37 -> V_87 ) ;
V_37 -> V_87 = NULL ;
}
}
static void F_78 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_85 * V_86 ;
unsigned long * V_87 ;
int V_24 ;
if ( V_37 -> V_87 == NULL ) {
V_37 -> V_87 = ( unsigned long * ) F_79 ( V_98 ) ;
V_87 = ( unsigned long * ) V_37 -> V_87 ;
if ( ! V_87 )
F_20 ( L_15 ) ;
for ( V_24 = 0 ; V_24 < V_159 ; V_24 ++ ) {
struct V_6 * V_9 ;
V_9 = F_3 ( V_97 , V_98 ) ;
if ( ! V_9 ) {
F_80 ( 0 ) ;
continue;
}
V_37 -> V_92 [ V_24 ] = V_9 ;
F_49 ( V_9 , ( 1664 + V_93 ) ) ;
V_86 = (struct V_85 * ) V_9 -> V_11 ;
V_87 [ V_24 ] = F_50 ( F_7 ( V_86 , 1 ) ) ;
F_6 ( V_9 , V_93 ) ;
}
V_37 -> V_90 = 0 ;
V_37 -> V_91 = V_159 ;
}
if ( V_37 -> V_156 == NULL ) {
V_37 -> V_156 = (struct V_160 * ) F_81 ( V_161 , 2 ) ;
if ( ! V_37 -> V_156 )
F_20 ( L_16 ) ;
V_37 -> V_158 = 0 ;
V_37 -> V_117 = 0 ;
}
}
static void F_82 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
unsigned long V_162 ;
F_75 ( V_37 ) ;
F_78 ( V_3 ) ;
F_72 ( V_37 ) ;
F_73 ( V_37 ) ;
V_162 = F_7 ( V_37 -> V_87 , 0 ) ;
F_83 ( V_162 >> 32 ) ;
F_84 ( V_162 & 0xffffffff ) ;
F_85 ( V_37 -> V_90 << 3 ) ;
F_51 ( ( V_37 -> V_91 << 3 ) | V_111 ) ;
V_162 = F_7 ( V_37 -> V_156 , 0 ) ;
V_37 -> V_121 = 0 ;
F_86 ( V_162 >> 32 ) ;
F_87 ( V_162 & 0xffffffff ) ;
F_88 ( V_37 -> V_158 << 7 ) ;
F_89 ( V_37 -> V_117 << 7 ) ;
( void ) F_54 () ;
}
static inline void F_90 ( struct V_2 * V_37 )
{
struct V_19 * V_19 = V_37 -> V_38 ;
volatile T_1 * V_163 = & V_19 -> V_164 [ 0x0000 ] ;
volatile T_1 * V_165 = & V_19 -> V_164 [ 0x4000 ] ;
unsigned int V_166 = 0x5555 ;
F_67 ( F_91 () | ( V_167 | V_168 ) ) ;
* V_163 = V_166 ;
* V_165 = ~ V_166 & V_169 ;
if ( ( * V_163 & V_169 ) != V_166 ||
( * V_165 & V_169 ) != ( ~ V_166 & V_169 ) ) {
V_37 -> V_141 = V_168 ;
F_67 ( F_91 () & ~ V_167 ) ;
} else
V_37 -> V_141 = V_167 | V_168 ;
}
static void F_60 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
F_92 ( & V_37 -> F_68 ) ;
F_67 ( V_170 ) ;
( void ) F_91 () ;
F_24 ( 4 ) ;
F_67 ( 0 ) ;
( void ) F_91 () ;
#ifdef F_8
F_93 ( V_171 >> 32 ) ;
#else
F_93 ( 0 ) ;
#endif
( void ) F_40 () ;
F_94 ( 15 ) ;
F_95 ( 0 ) ;
F_26 ( V_3 ) ;
F_96 ( V_37 -> V_172 ) ;
F_97 ( V_37 -> V_173 ) ;
F_98 ( 42 ) ;
F_82 ( V_3 ) ;
V_37 -> V_141 |= ( ( V_93 / 2 ) << V_174 ) | V_175 |
V_176 | V_177 | V_178 | V_179 ;
F_67 ( V_37 -> V_141 ) ;
F_99 ( V_135 | V_125 | V_127 |
V_128 | V_129 | V_130 |
V_136 | V_131 ) ;
( void ) F_100 () ;
}
static inline void F_59 ( struct V_2 * V_37 )
{
struct V_19 * V_19 = V_37 -> V_38 ;
F_67 ( 0 ) ;
F_99 ( 0 ) ;
( void ) F_100 () ;
}
static int F_101 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
if ( F_102 ( V_3 -> V_132 , F_62 , V_180 , V_181 , V_3 ) ) {
F_20 ( V_126 L_17 , V_3 -> V_124 , V_3 -> V_132 ) ;
return - V_182 ;
}
V_37 -> V_172 = 0 ;
V_37 -> V_173 = 0 ;
F_60 ( V_3 ) ;
F_71 ( V_37 ) ;
F_103 ( V_3 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
F_92 ( & V_37 -> F_68 ) ;
F_105 ( V_3 ) ;
F_59 ( V_37 ) ;
F_106 ( V_3 -> V_132 , V_3 ) ;
F_75 ( V_37 ) ;
return 0 ;
}
static int F_107 ( struct V_183 * V_184 , int V_185 )
{
struct V_183 * V_3 = F_108 ( V_184 -> V_186 , F_109 ( V_185 , 0 ) ) ;
int V_187 = 0 ;
if ( V_3 ) {
if ( V_3 -> V_188 == V_189 &&
V_3 -> V_190 == V_191 )
V_187 = 1 ;
F_110 ( V_3 ) ;
}
return V_187 ;
}
static int F_111 ( struct V_183 * V_184 )
{
return V_184 -> V_186 -> V_192 == NULL &&
F_107 ( V_184 , 0 ) &&
F_107 ( V_184 , 1 ) &&
F_107 ( V_184 , 2 ) ;
}
static void T_8 F_112 ( struct V_193 T_9 * V_194 )
{
#define F_113 6
struct V_195 V_196 = {
. V_132 = 0 ,
. V_197 = V_198 | V_199 ,
. V_200 = V_201 ,
. V_202 = 0 ,
. V_203 = ( 22000000 << 1 ) / F_113 ,
. V_204 = ( unsigned char T_9 * ) V_194 ,
. V_205 = ( unsigned long ) V_194 ,
} ;
unsigned char V_206 ;
V_206 = V_194 -> V_207 ;
V_194 -> V_207 = V_206 | V_208 ;
V_194 -> V_209 = F_113 ,
V_194 -> V_207 = V_206 ;
V_194 -> V_207 ;
F_114 ( & V_196 ) ;
}
static void T_8 F_115 ( struct V_183 * V_184 , struct V_19 * V_19 )
{
if ( F_111 ( V_184 ) && F_116 ( V_184 -> V_210 ) == 3 )
return;
V_19 -> V_211 = V_212 | V_213 ;
V_19 -> V_211 ;
V_19 -> V_214 = 0 ;
V_19 -> V_214 ;
V_19 -> V_215 = 0 ;
V_19 -> V_215 ;
V_19 -> V_216 = V_19 -> V_216 & ~ V_217 ;
V_19 -> V_216 ;
V_19 -> V_218 = V_19 -> V_218 & ~ V_217 ;
V_19 -> V_218 ;
V_19 -> V_219 &= ~ ( V_220 | V_221 |
V_222 | V_223 |
V_224 | V_225 |
V_226 | V_227 ) ;
V_19 -> V_219 |= V_228 ;
V_19 -> V_216 = 0 ;
V_19 -> V_219 &= ~ ( V_229 | V_230 |
V_231 | V_232 |
V_233 | V_234 |
V_235 | V_236 ) ;
V_19 -> V_219 |= V_237 ;
V_19 -> V_218 = 0 ;
F_112 ( & V_19 -> V_238 . V_239 ) ;
F_112 ( & V_19 -> V_238 . V_240 ) ;
}
static int T_8 F_117 ( struct V_183 * V_184 ,
const struct V_241 * V_242 )
{
unsigned int V_243 , V_244 ;
struct V_1 * V_3 = NULL ;
struct V_2 * V_37 ;
struct V_19 * V_19 ;
unsigned long V_245 , V_246 ;
T_1 V_188 , V_247 , V_248 ;
int V_89 , V_249 ;
V_89 = F_118 ( V_184 , F_119 ( 64 ) ) ;
if ( ! V_89 ) {
V_249 = 1 ;
V_89 = F_120 ( V_184 , F_119 ( 64 ) ) ;
if ( V_89 < 0 ) {
F_20 ( V_126 L_18
L_19 , F_121 ( V_184 ) ) ;
goto V_154;
}
} else {
V_89 = F_118 ( V_184 , F_119 ( 32 ) ) ;
if ( V_89 ) {
F_20 ( V_126 L_20
L_21 , F_121 ( V_184 ) ) ;
goto V_154;
}
V_249 = 0 ;
}
if ( F_122 ( V_184 ) )
return - V_153 ;
V_3 = F_123 ( sizeof( struct V_2 ) ) ;
if ( ! V_3 ) {
V_89 = - V_250 ;
goto V_251;
}
if ( V_249 )
V_3 -> V_101 |= V_252 ;
V_89 = F_124 ( V_184 , L_22 ) ;
if ( V_89 )
goto V_253;
F_125 ( V_3 , & V_184 -> V_3 ) ;
V_37 = F_27 ( V_3 ) ;
V_3 -> V_132 = V_184 -> V_132 ;
V_245 = F_126 ( V_184 , 0 ) ;
V_246 = F_127 ( V_184 , 0 ) ;
V_19 = (struct V_19 * ) F_128 ( V_245 , V_246 ) ;
if ( ! V_19 ) {
F_20 ( V_254 L_23 ,
F_121 ( V_184 ) ) ;
V_89 = - V_250 ;
goto V_255;
}
V_37 -> V_38 = V_19 ;
#ifdef F_129
F_115 ( V_184 , V_19 ) ;
#endif
F_130 ( & V_37 -> V_46 ) ;
F_131 ( & V_37 -> F_68 ) ;
F_59 ( V_37 ) ;
F_60 ( V_3 ) ;
V_37 -> V_184 = V_184 ;
V_37 -> V_138 . V_256 = 0x1f ;
V_37 -> V_138 . V_257 = 0x1f ;
V_37 -> V_138 . V_3 = V_3 ;
V_37 -> V_138 . V_258 = F_33 ;
V_37 -> V_138 . V_259 = F_37 ;
F_61 ( V_37 ) ;
if ( V_37 -> V_138 . V_152 == - 1 ) {
F_20 ( V_254 L_24 ,
F_121 ( V_184 ) ) ;
V_89 = - V_153 ;
goto V_260;
}
F_71 ( V_37 ) ;
F_90 ( V_37 ) ;
F_25 ( V_37 ) ;
V_3 -> V_261 = 5 * V_146 ;
V_3 -> V_262 = & V_263 ;
V_3 -> V_264 = & V_265 ;
V_3 -> V_266 = V_267 | V_102 ;
V_3 -> V_101 = V_267 ;
V_243 = F_33 ( V_3 , V_37 -> V_138 . V_152 , V_151 ) ;
V_244 = F_33 ( V_3 , V_37 -> V_138 . V_152 , V_268 ) ;
V_89 = F_132 ( V_3 ) ;
if ( V_89 )
goto V_260;
F_69 ( & V_37 -> V_138 , 1 , 1 ) ;
F_65 ( V_37 ) ;
V_188 = ( V_243 << 12 ) | ( V_244 >> 4 ) ;
V_247 = ( V_244 >> 4 ) & 0x3f ;
V_248 = V_244 & 0xf ;
F_20 ( V_269 L_25
L_26 , V_3 -> V_124 , V_37 -> V_138 . V_152 , V_188 , V_247 , V_248 ) ;
F_20 ( V_269 L_27 , V_3 -> V_124 ,
V_37 -> V_141 & V_167 ? 128 : 64 ) ;
return 0 ;
V_260:
F_59 ( V_37 ) ;
F_92 ( & V_37 -> F_68 ) ;
F_75 ( V_37 ) ;
V_255:
F_133 ( V_184 ) ;
V_253:
F_134 ( V_3 ) ;
V_251:
V_154:
return V_89 ;
}
static void T_10 F_135 ( struct V_183 * V_184 )
{
struct V_1 * V_3 = F_136 ( V_184 ) ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
F_137 ( V_3 ) ;
F_92 ( & V_37 -> F_68 ) ;
F_138 ( V_19 ) ;
F_133 ( V_184 ) ;
F_134 ( V_3 ) ;
}
static int T_11 F_139 ( void )
{
return F_140 ( & V_270 ) ;
}
static void T_12 F_141 ( void )
{
F_142 ( & V_270 ) ;
}
static int F_143 ( struct V_6 * V_9 , struct V_1 * V_3 )
{
unsigned long V_11 ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
unsigned int V_57 ;
struct V_160 * V_271 ;
T_4 V_88 = 0 ;
int V_272 ;
if ( V_9 -> V_80 == V_273 ) {
const struct V_63 * V_64 = F_144 ( V_9 ) ;
const int V_62 = F_145 ( V_64 -> V_73 ) ;
unsigned int V_274 ;
T_4 V_60 , V_61 ;
T_5 * V_59 ;
V_59 = ( T_5 * ) V_9 -> V_11 ;
V_61 = V_59 [ 0 ] + V_59 [ 1 ] + V_59 [ 2 ] + V_59 [ 3 ] + V_59 [ 4 ] + V_59 [ 5 ] + V_59 [ 6 ] ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_60 = F_146 ( V_64 -> V_78 , V_64 -> V_79 ,
V_64 -> V_76 - ( V_64 -> V_77 << 2 ) ,
V_62 , 0xffff ^ V_61 ) ;
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
V_274 = V_69 + ( V_64 -> V_77 << 2 ) ;
if ( V_62 == V_75 ) {
V_274 += F_147 ( struct V_275 , V_276 ) ;
F_148 ( V_9 ) -> V_276 = V_60 ;
}
if ( V_62 == V_74 ) {
V_274 += F_147 ( struct V_277 , V_276 ) ;
F_149 ( V_9 ) -> V_276 = V_60 ;
}
V_88 = V_278 | ( V_274 << V_279 ) ;
}
F_31 ( & V_37 -> V_46 ) ;
V_11 = ( unsigned long ) V_9 -> V_11 ;
V_57 = V_9 -> V_57 ;
V_272 = V_37 -> V_158 ;
V_271 = & V_37 -> V_156 [ V_272 ] ;
if ( V_57 <= 104 ) {
F_150 ( V_9 , V_271 -> V_11 , V_9 -> V_57 ) ;
if ( V_57 < V_280 ) {
memset ( V_271 -> V_11 + V_57 , 0 , V_280 - V_57 ) ;
V_57 = V_280 ;
}
V_271 -> V_157 = F_151 ( V_57 | V_281 | V_282 | V_88 ) ;
V_271 -> V_283 = F_151 ( V_57 ) ;
} else if ( ( V_11 ^ ( V_11 + V_57 - 1 ) ) & 0x4000 ) {
unsigned long V_284 = ( V_11 | 0x3fffUL ) + 1UL ;
unsigned long V_285 = V_284 - V_11 ;
unsigned long V_286 = V_11 + V_57 - V_284 ;
V_271 -> V_157 = F_151 ( V_57 | V_281 |
V_287 | V_288 | V_88 ) ;
V_271 -> V_283 = F_151 ( ( V_285 << V_289 ) |
( V_286 << V_290 ) ) ;
V_271 -> V_291 = F_50 ( F_7 ( V_9 -> V_11 , 1 ) ) ;
V_271 -> V_292 = F_50 ( F_7 ( ( void * ) V_284 , 1 ) ) ;
} else {
V_271 -> V_157 = F_151 ( V_57 | V_281 | V_287 | V_88 ) ;
V_271 -> V_283 = F_151 ( V_57 << V_289 ) ;
V_271 -> V_291 = F_50 ( F_7 ( V_9 -> V_11 , 1 ) ) ;
}
F_152 () ;
V_37 -> V_118 [ V_272 ] = V_9 ;
V_272 = ( V_272 + 1 ) & 127 ;
V_37 -> V_158 = V_272 ;
F_88 ( V_272 << 7 ) ;
V_37 -> V_121 ++ ;
if ( V_37 -> V_121 >= 127 )
F_105 ( V_3 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_293 ;
}
static void F_153 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
F_20 ( V_126 L_28 , V_3 -> V_124 ) ;
F_31 ( & V_37 -> V_46 ) ;
F_59 ( V_37 ) ;
F_60 ( V_3 ) ;
F_61 ( V_37 ) ;
F_71 ( V_37 ) ;
F_32 ( & V_37 -> V_46 ) ;
F_56 ( V_3 ) ;
}
static inline unsigned int F_154 ( const unsigned char * V_4 )
{
unsigned int V_294 = 0 ;
T_1 V_33 ;
int V_295 ;
V_33 = F_155 ( V_296 , V_4 ) ;
V_33 &= 0x3f ;
for ( V_295 = 6 ; -- V_295 >= 0 ; ) {
V_294 <<= 1 ;
V_294 |= ( V_33 & 0x1 ) ;
V_33 >>= 1 ;
}
return V_294 ;
}
static void F_156 ( struct V_1 * V_3 ,
struct V_297 * V_298 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
strcpy ( V_298 -> V_299 , V_300 ) ;
strcpy ( V_298 -> V_301 , V_302 ) ;
strcpy ( V_298 -> V_303 , F_121 ( V_37 -> V_184 ) ) ;
}
static int F_157 ( struct V_1 * V_3 , struct V_304 * V_157 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_305 ;
F_31 ( & V_37 -> V_46 ) ;
V_305 = F_158 ( & V_37 -> V_138 , V_157 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_305 ;
}
static int F_159 ( struct V_1 * V_3 , struct V_304 * V_157 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_305 ;
F_31 ( & V_37 -> V_46 ) ;
V_305 = F_160 ( & V_37 -> V_138 , V_157 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_305 ;
}
static int F_161 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_305 ;
F_31 ( & V_37 -> V_46 ) ;
V_305 = F_162 ( & V_37 -> V_138 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_305 ;
}
static T_1 F_163 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_305 ;
F_31 ( & V_37 -> V_46 ) ;
V_305 = F_164 ( & V_37 -> V_138 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_305 ;
}
static int F_165 ( struct V_1 * V_3 , struct V_306 * V_307 , int V_157 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_305 ;
F_31 ( & V_37 -> V_46 ) ;
V_305 = F_166 ( & V_37 -> V_138 , F_167 ( V_307 ) , V_157 , NULL ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_305 ;
}
static void F_168 ( struct V_1 * V_3 )
{
struct V_308 * V_309 ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
T_2 V_310 = 0 ;
F_105 ( V_3 ) ;
if ( V_3 -> V_197 & V_311 ) {
V_37 -> V_141 |= V_312 ;
F_67 ( V_37 -> V_141 ) ;
( void ) F_91 () ;
} else {
V_37 -> V_141 &= ~ V_312 ;
F_67 ( V_37 -> V_141 ) ;
( void ) F_91 () ;
if ( ( V_3 -> V_197 & V_313 ) ||
( F_169 ( V_3 ) > 64 ) ) {
V_37 -> V_172 = 0xffffffff ;
V_37 -> V_173 = 0xffffffff ;
} else {
F_170 (ha, dev) {
char * V_4 = V_309 -> V_4 ;
if ( ! ( * V_4 & 1 ) )
continue;
V_310 |= ( 1UL << F_154 ( V_4 ) ) ;
}
V_37 -> V_172 = V_310 >> 32 ;
V_37 -> V_173 = V_310 & 0xffffffff ;
}
F_96 ( V_37 -> V_172 ) ;
F_97 ( V_37 -> V_173 ) ;
}
F_56 ( V_3 ) ;
}
