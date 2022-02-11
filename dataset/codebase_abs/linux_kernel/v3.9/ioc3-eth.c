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
if ( F_44 ( V_64 ) )
return;
V_62 = V_64 -> V_70 ;
if ( V_62 != V_71 && V_62 != V_72 )
return;
V_60 = V_56 +
( V_64 -> V_73 - ( V_64 -> V_74 << 2 ) ) +
F_43 ( ( T_5 ) V_64 -> V_70 ) +
( V_64 -> V_75 >> 16 ) + ( V_64 -> V_75 & 0xffff ) +
( V_64 -> V_76 >> 16 ) + ( V_64 -> V_76 & 0xffff ) ;
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
V_9 -> V_77 = V_78 ;
}
static inline void F_45 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_6 * V_9 , * V_79 ;
struct V_19 * V_19 = V_37 -> V_38 ;
int V_80 , V_81 , V_57 ;
struct V_82 * V_83 ;
unsigned long * V_84 ;
T_1 V_85 , V_86 ;
V_84 = V_37 -> V_84 ;
V_80 = V_37 -> V_87 ;
V_81 = V_37 -> V_88 ;
V_9 = V_37 -> V_89 [ V_80 ] ;
V_83 = (struct V_82 * ) ( V_9 -> V_11 - V_90 ) ;
V_85 = F_46 ( V_83 -> V_85 ) ;
while ( V_85 & V_91 ) {
V_86 = F_46 ( V_83 -> V_86 ) ;
if ( V_86 & V_92 ) {
V_57 = ( ( V_85 >> V_93 ) & 0x7ff ) - 4 ;
F_47 ( V_9 , V_57 ) ;
V_9 -> V_70 = F_48 ( V_9 , V_3 ) ;
V_79 = F_3 ( V_94 , V_95 ) ;
if ( ! V_79 ) {
V_3 -> V_53 . V_96 ++ ;
V_79 = V_9 ;
goto V_97;
}
if ( F_5 ( V_3 -> V_98 & V_99 ) )
F_41 ( V_9 ,
V_85 & V_100 , V_57 ) ;
F_49 ( V_9 ) ;
V_37 -> V_89 [ V_80 ] = NULL ;
F_50 ( V_79 , ( 1664 + V_90 ) ) ;
V_83 = (struct V_82 * ) V_79 -> V_11 ;
F_6 ( V_79 , V_90 ) ;
V_3 -> V_53 . V_101 ++ ;
V_3 -> V_53 . V_102 += V_57 ;
} else {
V_79 = V_9 ;
V_3 -> V_53 . V_103 ++ ;
}
if ( V_86 & V_104 )
V_3 -> V_53 . V_105 ++ ;
if ( V_86 & V_106 )
V_3 -> V_53 . V_107 ++ ;
V_97:
V_37 -> V_89 [ V_81 ] = V_79 ;
V_84 [ V_81 ] = F_51 ( F_7 ( V_83 , 1 ) ) ;
V_83 -> V_85 = 0 ;
V_81 = ( V_81 + 1 ) & 511 ;
V_80 = ( V_80 + 1 ) & 511 ;
V_9 = V_37 -> V_89 [ V_80 ] ;
V_83 = (struct V_82 * ) ( V_9 -> V_11 - V_90 ) ;
V_85 = F_46 ( V_83 -> V_85 ) ;
}
F_52 ( ( V_81 << 3 ) | V_108 ) ;
V_37 -> V_88 = V_81 ;
V_37 -> V_87 = V_80 ;
}
static inline void F_53 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
unsigned long V_109 , V_110 ;
struct V_19 * V_19 = V_37 -> V_38 ;
int V_111 , V_112 ;
struct V_6 * V_9 ;
T_1 V_113 ;
F_54 ( & V_37 -> V_46 ) ;
V_113 = F_55 () ;
V_111 = ( V_113 >> 7 ) & 127 ;
V_112 = V_37 -> V_114 ;
V_109 = 0 ;
V_110 = 0 ;
while ( V_112 != V_111 ) {
V_109 ++ ;
V_9 = V_37 -> V_115 [ V_112 ] ;
V_110 += V_9 -> V_57 ;
F_56 ( V_9 ) ;
V_37 -> V_115 [ V_112 ] = NULL ;
V_112 = ( V_112 + 1 ) & 127 ;
V_113 = F_55 () ;
V_111 = ( V_113 >> 7 ) & 127 ;
}
V_3 -> V_53 . V_116 += V_109 ;
V_3 -> V_53 . V_117 += V_110 ;
V_37 -> V_118 -= V_109 ;
if ( V_37 -> V_118 < 128 )
F_57 ( V_3 ) ;
V_37 -> V_114 = V_112 ;
F_58 ( & V_37 -> V_46 ) ;
}
static void F_59 ( struct V_1 * V_3 , T_1 V_119 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
unsigned char * V_120 = V_3 -> V_121 ;
F_54 ( & V_37 -> V_46 ) ;
if ( V_119 & V_122 )
F_20 ( V_123 L_9 , V_120 ) ;
if ( V_119 & V_124 )
F_20 ( V_123 L_10 , V_120 ) ;
if ( V_119 & V_125 )
F_20 ( V_123 L_11 , V_120 ) ;
if ( V_119 & V_126 )
F_20 ( V_123 L_12 , V_120 ) ;
if ( V_119 & V_127 )
F_20 ( V_123 L_13 , V_120 ) ;
if ( V_119 & V_128 )
F_20 ( V_123 L_14 , V_120 ) ;
F_60 ( V_37 ) ;
F_61 ( V_3 ) ;
F_62 ( V_37 ) ;
F_57 ( V_3 ) ;
F_58 ( & V_37 -> V_46 ) ;
}
static T_6 F_63 ( int V_129 , void * V_130 )
{
struct V_1 * V_3 = (struct V_1 * ) V_130 ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
const T_1 V_131 = V_132 | V_122 | V_124 |
V_125 | V_126 | V_127 |
V_133 | V_128 ;
T_1 V_119 ;
V_119 = F_64 () & V_131 ;
F_65 ( V_119 ) ;
( void ) F_64 () ;
if ( V_119 & ( V_122 | V_124 | V_125 |
V_126 | V_127 | V_128 ) )
F_59 ( V_3 , V_119 ) ;
if ( V_119 & V_132 )
F_45 ( V_3 ) ;
if ( V_119 & V_133 )
F_53 ( V_3 ) ;
return V_134 ;
}
static inline void F_66 ( struct V_2 * V_37 )
{
struct V_19 * V_19 = V_37 -> V_38 ;
if ( V_37 -> V_135 . V_136 ) {
F_67 ( V_137 ) ;
V_37 -> V_138 |= V_139 ;
} else {
F_67 ( V_140 ) ;
V_37 -> V_138 &= ~ V_139 ;
}
F_68 ( V_37 -> V_138 ) ;
}
static void F_69 ( unsigned long V_11 )
{
struct V_2 * V_37 = (struct V_2 * ) V_11 ;
F_70 ( & V_37 -> V_135 , 1 , 0 ) ;
F_66 ( V_37 ) ;
V_37 -> F_69 . V_141 = V_142 + ( ( 12 * V_143 ) / 10 ) ;
F_71 ( & V_37 -> F_69 ) ;
}
static int F_62 ( struct V_2 * V_37 )
{
struct V_1 * V_3 = F_1 ( V_37 ) ;
int V_24 , V_144 = 0 , V_145 = 0 ;
int V_146 = 1 ;
T_7 V_147 ;
for ( V_24 = 0 ; V_24 < 32 ; V_24 ++ ) {
V_147 = F_33 ( V_3 , V_24 , V_148 ) ;
if ( V_147 != 0xffff && V_147 != 0x0000 ) {
V_144 = 1 ;
break;
}
}
if ( ! V_144 ) {
if ( V_146 )
V_24 = 31 ;
else {
V_37 -> V_135 . V_149 = - 1 ;
V_145 = - V_150 ;
goto V_151;
}
}
V_37 -> V_135 . V_149 = V_24 ;
V_151:
return V_145 ;
}
static void F_72 ( struct V_2 * V_37 )
{
V_37 -> F_69 . V_141 = V_142 + ( 12 * V_143 ) / 10 ;
V_37 -> F_69 . V_11 = ( unsigned long ) V_37 ;
V_37 -> F_69 . V_152 = F_69 ;
F_71 ( & V_37 -> F_69 ) ;
}
static inline void F_73 ( struct V_2 * V_37 )
{
struct V_6 * V_9 ;
int V_24 ;
for ( V_24 = V_37 -> V_87 ; V_24 & 15 ; V_24 ++ ) {
V_37 -> V_89 [ V_37 -> V_88 ] = V_37 -> V_89 [ V_37 -> V_87 ] ;
V_37 -> V_84 [ V_37 -> V_88 ++ ] = V_37 -> V_84 [ V_37 -> V_87 ++ ] ;
}
V_37 -> V_88 &= 511 ;
V_37 -> V_87 &= 511 ;
for ( V_24 = V_37 -> V_87 ; V_24 != V_37 -> V_88 ; V_24 = ( V_24 + 1 ) & 511 ) {
struct V_82 * V_83 ;
V_9 = V_37 -> V_89 [ V_24 ] ;
V_83 = (struct V_82 * ) ( V_9 -> V_11 - V_90 ) ;
V_83 -> V_85 = 0 ;
}
}
static inline void F_74 ( struct V_2 * V_37 )
{
struct V_6 * V_9 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 128 ; V_24 ++ ) {
V_9 = V_37 -> V_115 [ V_24 ] ;
if ( V_9 ) {
V_37 -> V_115 [ V_24 ] = NULL ;
F_75 ( V_9 ) ;
}
V_37 -> V_153 [ V_24 ] . V_154 = 0 ;
}
V_37 -> V_155 = 0 ;
V_37 -> V_114 = 0 ;
}
static void F_76 ( struct V_2 * V_37 )
{
struct V_6 * V_9 ;
int V_80 , V_81 ;
if ( V_37 -> V_153 ) {
F_74 ( V_37 ) ;
F_77 ( ( unsigned long ) V_37 -> V_153 , 2 ) ;
V_37 -> V_153 = NULL ;
}
if ( V_37 -> V_84 ) {
V_81 = V_37 -> V_87 ;
V_80 = V_37 -> V_88 ;
while ( V_81 != V_80 ) {
V_9 = V_37 -> V_89 [ V_81 ] ;
if ( V_9 )
F_75 ( V_9 ) ;
V_81 = ( V_81 + 1 ) & 511 ;
}
F_78 ( ( unsigned long ) V_37 -> V_84 ) ;
V_37 -> V_84 = NULL ;
}
}
static void F_79 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_82 * V_83 ;
unsigned long * V_84 ;
int V_24 ;
if ( V_37 -> V_84 == NULL ) {
V_37 -> V_84 = ( unsigned long * ) F_80 ( V_95 ) ;
V_84 = V_37 -> V_84 ;
if ( ! V_84 )
F_20 ( L_15 ) ;
for ( V_24 = 0 ; V_24 < V_156 ; V_24 ++ ) {
struct V_6 * V_9 ;
V_9 = F_3 ( V_94 , V_95 ) ;
if ( ! V_9 ) {
F_81 ( 0 ) ;
continue;
}
V_37 -> V_89 [ V_24 ] = V_9 ;
F_50 ( V_9 , ( 1664 + V_90 ) ) ;
V_83 = (struct V_82 * ) V_9 -> V_11 ;
V_84 [ V_24 ] = F_51 ( F_7 ( V_83 , 1 ) ) ;
F_6 ( V_9 , V_90 ) ;
}
V_37 -> V_87 = 0 ;
V_37 -> V_88 = V_156 ;
}
if ( V_37 -> V_153 == NULL ) {
V_37 -> V_153 = (struct V_157 * ) F_82 ( V_158 , 2 ) ;
if ( ! V_37 -> V_153 )
F_20 ( L_16 ) ;
V_37 -> V_155 = 0 ;
V_37 -> V_114 = 0 ;
}
}
static void F_83 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
unsigned long V_159 ;
F_76 ( V_37 ) ;
F_79 ( V_3 ) ;
F_73 ( V_37 ) ;
F_74 ( V_37 ) ;
V_159 = F_7 ( V_37 -> V_84 , 0 ) ;
F_84 ( V_159 >> 32 ) ;
F_85 ( V_159 & 0xffffffff ) ;
F_86 ( V_37 -> V_87 << 3 ) ;
F_52 ( ( V_37 -> V_88 << 3 ) | V_108 ) ;
V_159 = F_7 ( V_37 -> V_153 , 0 ) ;
V_37 -> V_118 = 0 ;
F_87 ( V_159 >> 32 ) ;
F_88 ( V_159 & 0xffffffff ) ;
F_89 ( V_37 -> V_155 << 7 ) ;
F_90 ( V_37 -> V_114 << 7 ) ;
( void ) F_55 () ;
}
static inline void F_91 ( struct V_2 * V_37 )
{
struct V_19 * V_19 = V_37 -> V_38 ;
volatile T_1 * V_160 = & V_19 -> V_161 [ 0x0000 ] ;
volatile T_1 * V_162 = & V_19 -> V_161 [ 0x4000 ] ;
unsigned int V_163 = 0x5555 ;
F_68 ( F_92 () | ( V_164 | V_165 ) ) ;
* V_160 = V_163 ;
* V_162 = ~ V_163 & V_166 ;
if ( ( * V_160 & V_166 ) != V_163 ||
( * V_162 & V_166 ) != ( ~ V_163 & V_166 ) ) {
V_37 -> V_138 = V_165 ;
F_68 ( F_92 () & ~ V_164 ) ;
} else
V_37 -> V_138 = V_164 | V_165 ;
}
static void F_61 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
F_93 ( & V_37 -> F_69 ) ;
F_68 ( V_167 ) ;
( void ) F_92 () ;
F_24 ( 4 ) ;
F_68 ( 0 ) ;
( void ) F_92 () ;
#ifdef F_8
F_94 ( V_168 >> 32 ) ;
#else
F_94 ( 0 ) ;
#endif
( void ) F_40 () ;
F_95 ( 15 ) ;
F_96 ( 0 ) ;
F_26 ( V_3 ) ;
F_97 ( V_37 -> V_169 ) ;
F_98 ( V_37 -> V_170 ) ;
F_99 ( 42 ) ;
F_83 ( V_3 ) ;
V_37 -> V_138 |= ( ( V_90 / 2 ) << V_171 ) | V_172 |
V_173 | V_174 | V_175 | V_176 ;
F_68 ( V_37 -> V_138 ) ;
F_100 ( V_132 | V_122 | V_124 |
V_125 | V_126 | V_127 |
V_133 | V_128 ) ;
( void ) F_101 () ;
}
static inline void F_60 ( struct V_2 * V_37 )
{
struct V_19 * V_19 = V_37 -> V_38 ;
F_68 ( 0 ) ;
F_100 ( 0 ) ;
( void ) F_101 () ;
}
static int F_102 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
if ( F_103 ( V_3 -> V_129 , F_63 , V_177 , V_178 , V_3 ) ) {
F_20 ( V_123 L_17 , V_3 -> V_121 , V_3 -> V_129 ) ;
return - V_179 ;
}
V_37 -> V_169 = 0 ;
V_37 -> V_170 = 0 ;
F_61 ( V_3 ) ;
F_72 ( V_37 ) ;
F_104 ( V_3 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
F_93 ( & V_37 -> F_69 ) ;
F_106 ( V_3 ) ;
F_60 ( V_37 ) ;
F_107 ( V_3 -> V_129 , V_3 ) ;
F_76 ( V_37 ) ;
return 0 ;
}
static int F_108 ( struct V_180 * V_181 , int V_182 )
{
struct V_180 * V_3 = F_109 ( V_181 -> V_183 , F_110 ( V_182 , 0 ) ) ;
int V_184 = 0 ;
if ( V_3 ) {
if ( V_3 -> V_185 == V_186 &&
V_3 -> V_187 == V_188 )
V_184 = 1 ;
F_111 ( V_3 ) ;
}
return V_184 ;
}
static int F_112 ( struct V_180 * V_181 )
{
return V_181 -> V_183 -> V_189 == NULL &&
F_108 ( V_181 , 0 ) &&
F_108 ( V_181 , 1 ) &&
F_108 ( V_181 , 2 ) ;
}
static void F_113 ( struct V_190 T_8 * V_191 )
{
#define F_114 6
struct V_192 V_193 = {
. V_193 = {
. V_129 = 0 ,
. V_194 = V_195 | V_196 ,
. V_197 = V_198 ,
. V_199 = 0 ,
. V_200 = ( 22000000 << 1 ) / F_114 ,
. V_201 = ( unsigned char T_8 * ) V_191 ,
. V_202 = ( unsigned long ) V_191 ,
}
} ;
unsigned char V_203 ;
V_203 = V_191 -> V_204 ;
V_191 -> V_204 = V_203 | V_205 ;
V_191 -> V_206 = F_114 ,
V_191 -> V_204 = V_203 ;
V_191 -> V_204 ;
F_115 ( & V_193 ) ;
}
static void F_116 ( struct V_180 * V_181 , struct V_19 * V_19 )
{
if ( F_112 ( V_181 ) && F_117 ( V_181 -> V_207 ) == 3 )
return;
V_19 -> V_208 = V_209 | V_210 ;
V_19 -> V_208 ;
V_19 -> V_211 = 0 ;
V_19 -> V_211 ;
V_19 -> V_212 = 0 ;
V_19 -> V_212 ;
V_19 -> V_213 = V_19 -> V_213 & ~ V_214 ;
V_19 -> V_213 ;
V_19 -> V_215 = V_19 -> V_215 & ~ V_214 ;
V_19 -> V_215 ;
V_19 -> V_216 &= ~ ( V_217 | V_218 |
V_219 | V_220 |
V_221 | V_222 |
V_223 | V_224 ) ;
V_19 -> V_216 |= V_225 ;
V_19 -> V_213 = 0 ;
V_19 -> V_216 &= ~ ( V_226 | V_227 |
V_228 | V_229 |
V_230 | V_231 |
V_232 | V_233 ) ;
V_19 -> V_216 |= V_234 ;
V_19 -> V_215 = 0 ;
F_113 ( & V_19 -> V_235 . V_236 ) ;
F_113 ( & V_19 -> V_235 . V_237 ) ;
}
static int F_118 ( struct V_180 * V_181 , const struct V_238 * V_239 )
{
unsigned int V_240 , V_241 ;
struct V_1 * V_3 = NULL ;
struct V_2 * V_37 ;
struct V_19 * V_19 ;
unsigned long V_242 , V_243 ;
T_1 V_185 , V_244 , V_245 ;
int V_86 , V_246 ;
V_86 = F_119 ( V_181 , F_120 ( 64 ) ) ;
if ( ! V_86 ) {
V_246 = 1 ;
V_86 = F_121 ( V_181 , F_120 ( 64 ) ) ;
if ( V_86 < 0 ) {
F_20 ( V_123 L_18
L_19 , F_122 ( V_181 ) ) ;
goto V_151;
}
} else {
V_86 = F_119 ( V_181 , F_120 ( 32 ) ) ;
if ( V_86 ) {
F_20 ( V_123 L_20
L_21 , F_122 ( V_181 ) ) ;
goto V_151;
}
V_246 = 0 ;
}
if ( F_123 ( V_181 ) )
return - V_150 ;
V_3 = F_124 ( sizeof( struct V_2 ) ) ;
if ( ! V_3 ) {
V_86 = - V_247 ;
goto V_248;
}
if ( V_246 )
V_3 -> V_98 |= V_249 ;
V_86 = F_125 ( V_181 , L_22 ) ;
if ( V_86 )
goto V_250;
F_126 ( V_3 , & V_181 -> V_3 ) ;
V_37 = F_27 ( V_3 ) ;
V_3 -> V_129 = V_181 -> V_129 ;
V_242 = F_127 ( V_181 , 0 ) ;
V_243 = F_128 ( V_181 , 0 ) ;
V_19 = (struct V_19 * ) F_129 ( V_242 , V_243 ) ;
if ( ! V_19 ) {
F_20 ( V_251 L_23 ,
F_122 ( V_181 ) ) ;
V_86 = - V_247 ;
goto V_252;
}
V_37 -> V_38 = V_19 ;
#ifdef F_130
F_116 ( V_181 , V_19 ) ;
#endif
F_131 ( & V_37 -> V_46 ) ;
F_132 ( & V_37 -> F_69 ) ;
F_60 ( V_37 ) ;
F_61 ( V_3 ) ;
V_37 -> V_181 = V_181 ;
V_37 -> V_135 . V_253 = 0x1f ;
V_37 -> V_135 . V_254 = 0x1f ;
V_37 -> V_135 . V_3 = V_3 ;
V_37 -> V_135 . V_255 = F_33 ;
V_37 -> V_135 . V_256 = F_37 ;
F_62 ( V_37 ) ;
if ( V_37 -> V_135 . V_149 == - 1 ) {
F_20 ( V_251 L_24 ,
F_122 ( V_181 ) ) ;
V_86 = - V_150 ;
goto V_257;
}
F_72 ( V_37 ) ;
F_91 ( V_37 ) ;
F_25 ( V_37 ) ;
V_3 -> V_258 = 5 * V_143 ;
V_3 -> V_259 = & V_260 ;
V_3 -> V_261 = & V_262 ;
V_3 -> V_263 = V_264 | V_99 ;
V_3 -> V_98 = V_264 ;
V_240 = F_33 ( V_3 , V_37 -> V_135 . V_149 , V_148 ) ;
V_241 = F_33 ( V_3 , V_37 -> V_135 . V_149 , V_265 ) ;
V_86 = F_133 ( V_3 ) ;
if ( V_86 )
goto V_257;
F_70 ( & V_37 -> V_135 , 1 , 1 ) ;
F_66 ( V_37 ) ;
V_185 = ( V_240 << 12 ) | ( V_241 >> 4 ) ;
V_244 = ( V_241 >> 4 ) & 0x3f ;
V_245 = V_241 & 0xf ;
F_20 ( V_266 L_25
L_26 , V_3 -> V_121 , V_37 -> V_135 . V_149 , V_185 , V_244 , V_245 ) ;
F_20 ( V_266 L_27 , V_3 -> V_121 ,
V_37 -> V_138 & V_164 ? 128 : 64 ) ;
return 0 ;
V_257:
F_60 ( V_37 ) ;
F_93 ( & V_37 -> F_69 ) ;
F_76 ( V_37 ) ;
V_252:
F_134 ( V_181 ) ;
V_250:
F_135 ( V_3 ) ;
V_248:
V_151:
return V_86 ;
}
static void F_136 ( struct V_180 * V_181 )
{
struct V_1 * V_3 = F_137 ( V_181 ) ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
F_138 ( V_3 ) ;
F_93 ( & V_37 -> F_69 ) ;
F_139 ( V_19 ) ;
F_134 ( V_181 ) ;
F_135 ( V_3 ) ;
}
static int T_9 F_140 ( void )
{
return F_141 ( & V_267 ) ;
}
static void T_10 F_142 ( void )
{
F_143 ( & V_267 ) ;
}
static int F_144 ( struct V_6 * V_9 , struct V_1 * V_3 )
{
unsigned long V_11 ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
unsigned int V_57 ;
struct V_157 * V_268 ;
T_4 V_85 = 0 ;
int V_269 ;
if ( V_9 -> V_77 == V_270 ) {
const struct V_63 * V_64 = F_145 ( V_9 ) ;
const int V_62 = F_146 ( V_64 -> V_70 ) ;
unsigned int V_271 ;
T_4 V_60 , V_61 ;
T_5 * V_59 ;
V_59 = ( T_5 * ) V_9 -> V_11 ;
V_61 = V_59 [ 0 ] + V_59 [ 1 ] + V_59 [ 2 ] + V_59 [ 3 ] + V_59 [ 4 ] + V_59 [ 5 ] + V_59 [ 6 ] ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_60 = F_147 ( V_64 -> V_75 , V_64 -> V_76 ,
V_64 -> V_73 - ( V_64 -> V_74 << 2 ) ,
V_62 , 0xffff ^ V_61 ) ;
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
V_271 = V_69 + ( V_64 -> V_74 << 2 ) ;
if ( V_62 == V_72 ) {
V_271 += F_148 ( struct V_272 , V_273 ) ;
F_149 ( V_9 ) -> V_273 = V_60 ;
}
if ( V_62 == V_71 ) {
V_271 += F_148 ( struct V_274 , V_273 ) ;
F_150 ( V_9 ) -> V_273 = V_60 ;
}
V_85 = V_275 | ( V_271 << V_276 ) ;
}
F_31 ( & V_37 -> V_46 ) ;
V_11 = ( unsigned long ) V_9 -> V_11 ;
V_57 = V_9 -> V_57 ;
V_269 = V_37 -> V_155 ;
V_268 = & V_37 -> V_153 [ V_269 ] ;
if ( V_57 <= 104 ) {
F_151 ( V_9 , V_268 -> V_11 , V_9 -> V_57 ) ;
if ( V_57 < V_277 ) {
memset ( V_268 -> V_11 + V_57 , 0 , V_277 - V_57 ) ;
V_57 = V_277 ;
}
V_268 -> V_154 = F_152 ( V_57 | V_278 | V_279 | V_85 ) ;
V_268 -> V_280 = F_152 ( V_57 ) ;
} else if ( ( V_11 ^ ( V_11 + V_57 - 1 ) ) & 0x4000 ) {
unsigned long V_281 = ( V_11 | 0x3fffUL ) + 1UL ;
unsigned long V_282 = V_281 - V_11 ;
unsigned long V_283 = V_11 + V_57 - V_281 ;
V_268 -> V_154 = F_152 ( V_57 | V_278 |
V_284 | V_285 | V_85 ) ;
V_268 -> V_280 = F_152 ( ( V_282 << V_286 ) |
( V_283 << V_287 ) ) ;
V_268 -> V_288 = F_51 ( F_7 ( V_9 -> V_11 , 1 ) ) ;
V_268 -> V_289 = F_51 ( F_7 ( ( void * ) V_281 , 1 ) ) ;
} else {
V_268 -> V_154 = F_152 ( V_57 | V_278 | V_284 | V_85 ) ;
V_268 -> V_280 = F_152 ( V_57 << V_286 ) ;
V_268 -> V_288 = F_51 ( F_7 ( V_9 -> V_11 , 1 ) ) ;
}
F_153 () ;
V_37 -> V_115 [ V_269 ] = V_9 ;
V_269 = ( V_269 + 1 ) & 127 ;
V_37 -> V_155 = V_269 ;
F_89 ( V_269 << 7 ) ;
V_37 -> V_118 ++ ;
if ( V_37 -> V_118 >= 127 )
F_106 ( V_3 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_290 ;
}
static void F_154 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
F_20 ( V_123 L_28 , V_3 -> V_121 ) ;
F_31 ( & V_37 -> V_46 ) ;
F_60 ( V_37 ) ;
F_61 ( V_3 ) ;
F_62 ( V_37 ) ;
F_72 ( V_37 ) ;
F_32 ( & V_37 -> V_46 ) ;
F_57 ( V_3 ) ;
}
static inline unsigned int F_155 ( const unsigned char * V_4 )
{
unsigned int V_291 = 0 ;
T_1 V_33 ;
int V_292 ;
V_33 = F_156 ( V_293 , V_4 ) ;
V_33 &= 0x3f ;
for ( V_292 = 6 ; -- V_292 >= 0 ; ) {
V_291 <<= 1 ;
V_291 |= ( V_33 & 0x1 ) ;
V_33 >>= 1 ;
}
return V_291 ;
}
static void F_157 ( struct V_1 * V_3 ,
struct V_294 * V_295 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
F_158 ( V_295 -> V_296 , V_297 , sizeof( V_295 -> V_296 ) ) ;
F_158 ( V_295 -> V_298 , V_299 , sizeof( V_295 -> V_298 ) ) ;
F_158 ( V_295 -> V_300 , F_122 ( V_37 -> V_181 ) , sizeof( V_295 -> V_300 ) ) ;
}
static int F_159 ( struct V_1 * V_3 , struct V_301 * V_154 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_302 ;
F_31 ( & V_37 -> V_46 ) ;
V_302 = F_160 ( & V_37 -> V_135 , V_154 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_302 ;
}
static int F_161 ( struct V_1 * V_3 , struct V_301 * V_154 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_302 ;
F_31 ( & V_37 -> V_46 ) ;
V_302 = F_162 ( & V_37 -> V_135 , V_154 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_302 ;
}
static int F_163 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_302 ;
F_31 ( & V_37 -> V_46 ) ;
V_302 = F_164 ( & V_37 -> V_135 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_302 ;
}
static T_1 F_165 ( struct V_1 * V_3 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_302 ;
F_31 ( & V_37 -> V_46 ) ;
V_302 = F_166 ( & V_37 -> V_135 ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_302 ;
}
static int F_167 ( struct V_1 * V_3 , struct V_303 * V_304 , int V_154 )
{
struct V_2 * V_37 = F_27 ( V_3 ) ;
int V_302 ;
F_31 ( & V_37 -> V_46 ) ;
V_302 = F_168 ( & V_37 -> V_135 , F_169 ( V_304 ) , V_154 , NULL ) ;
F_32 ( & V_37 -> V_46 ) ;
return V_302 ;
}
static void F_170 ( struct V_1 * V_3 )
{
struct V_305 * V_306 ;
struct V_2 * V_37 = F_27 ( V_3 ) ;
struct V_19 * V_19 = V_37 -> V_38 ;
T_2 V_307 = 0 ;
F_106 ( V_3 ) ;
if ( V_3 -> V_194 & V_308 ) {
V_37 -> V_138 |= V_309 ;
F_68 ( V_37 -> V_138 ) ;
( void ) F_92 () ;
} else {
V_37 -> V_138 &= ~ V_309 ;
F_68 ( V_37 -> V_138 ) ;
( void ) F_92 () ;
if ( ( V_3 -> V_194 & V_310 ) ||
( F_171 ( V_3 ) > 64 ) ) {
V_37 -> V_169 = 0xffffffff ;
V_37 -> V_170 = 0xffffffff ;
} else {
F_172 (ha, dev) {
V_307 |= ( 1UL << F_155 ( V_306 -> V_4 ) ) ;
}
V_37 -> V_169 = V_307 >> 32 ;
V_37 -> V_170 = V_307 & 0xffffffff ;
}
F_97 ( V_37 -> V_169 ) ;
F_98 ( V_37 -> V_170 ) ;
}
F_57 ( V_3 ) ;
}
