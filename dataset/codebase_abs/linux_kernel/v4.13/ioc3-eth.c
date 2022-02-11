static inline unsigned long F_1 ( unsigned long V_1 )
{
return ( ~ V_1 + 1 ) & ( V_2 - 1UL ) ;
}
static inline struct V_3 * F_2 ( unsigned long V_4 ,
unsigned int V_5 )
{
struct V_3 * V_6 ;
V_6 = F_3 ( V_4 + V_2 - 1 , V_5 ) ;
if ( F_4 ( V_6 ) ) {
int V_7 = F_1 ( ( unsigned long ) V_6 -> V_8 ) ;
if ( V_7 )
F_5 ( V_6 , V_7 ) ;
}
return V_6 ;
}
static inline unsigned long F_6 ( void * V_9 , unsigned long V_10 )
{
#ifdef F_7
V_10 <<= 57 ;
return V_10 | ( 0xaUL << V_11 ) | V_12 |
( ( unsigned long ) V_9 & V_13 ) ;
#else
return F_8 ( V_9 ) ;
#endif
}
static inline T_1 F_9 ( T_1 V_14 , T_1 V_15 )
{
return ( V_14 << 10 ) | ( V_15 << 2 ) ;
}
static int F_10 ( struct V_16 * V_16 )
{
T_1 V_17 ;
do {
V_17 = F_11 () ;
} while ( ! ( V_17 & 2 ) );
return V_17 & 1 ;
}
static int F_12 ( struct V_16 * V_16 )
{
int V_18 ;
F_13 ( F_9 ( 500 , 65 ) ) ;
V_18 = F_10 ( V_16 ) ;
F_13 ( F_9 ( 0 , 500 ) ) ;
F_10 ( V_16 ) ;
return V_18 ;
}
static inline int F_14 ( struct V_16 * V_16 )
{
int V_19 ;
F_13 ( F_9 ( 6 , 13 ) ) ;
V_19 = F_10 ( V_16 ) ;
F_13 ( F_9 ( 0 , 100 ) ) ;
F_10 ( V_16 ) ;
return V_19 ;
}
static inline void F_15 ( struct V_16 * V_16 , int V_20 )
{
if ( V_20 )
F_13 ( F_9 ( 6 , 110 ) ) ;
else
F_13 ( F_9 ( 80 , 30 ) ) ;
F_10 ( V_16 ) ;
}
static T_1 F_16 ( struct V_16 * V_16 )
{
T_1 V_19 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
V_19 = ( V_19 >> 1 ) | ( F_14 ( V_16 ) << 7 ) ;
return V_19 ;
}
static void F_17 ( struct V_16 * V_16 , int V_22 )
{
int V_21 , V_20 ;
for ( V_21 = 8 ; V_21 ; V_21 -- ) {
V_20 = V_22 & 1 ;
V_22 >>= 1 ;
F_15 ( V_16 , V_20 ) ;
}
}
static T_2 F_18 ( struct V_16 * V_16 , int * V_23 )
{
int V_24 , V_25 , V_26 , V_27 ;
T_2 V_28 = 0 ;
F_12 ( V_16 ) ;
F_17 ( V_16 , 0xf0 ) ;
for ( V_26 = 0 , V_27 = 0 ; V_26 < 64 ; V_26 ++ ) {
V_24 = F_14 ( V_16 ) ;
V_25 = F_14 ( V_16 ) ;
if ( V_24 && V_25 ) {
F_19 ( L_1 ) ;
* V_23 = 0 ;
return 0 ;
}
if ( ! V_24 && ! V_25 ) {
if ( V_26 == * V_23 ) {
V_28 |= 1UL << V_26 ;
} else if ( V_26 > * V_23 ) {
V_28 &= ~ ( 1UL << V_26 ) ;
V_27 = V_26 ;
} else if ( ( V_28 & ( 1UL << V_26 ) ) == 0 )
V_27 = V_26 ;
F_15 ( V_16 , V_28 & ( 1UL << V_26 ) ) ;
continue;
} else {
if ( V_24 )
V_28 |= 1UL << V_26 ;
else
V_28 &= ~ ( 1UL << V_26 ) ;
F_15 ( V_16 , V_24 ) ;
continue;
}
}
* V_23 = V_27 ;
return V_28 ;
}
static int F_20 ( struct V_16 * V_16 )
{
const char * V_29 = L_2 ;
const char * type = V_29 ;
T_3 V_30 ;
T_3 V_31 [ 6 ] ;
int V_32 = 0 , V_21 ;
while ( 1 ) {
T_2 V_33 ;
V_33 = F_18 ( V_16 , & V_32 ) ;
switch ( V_33 & 0xff ) {
case 0x91 :
type = L_3 ;
break;
default:
if ( V_32 == 0 ) {
return - 1 ;
}
continue;
}
F_12 ( V_16 ) ;
F_17 ( V_16 , 0x55 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_17 ( V_16 , ( V_33 >> ( V_21 << 3 ) ) & 0xff ) ;
V_33 >>= 8 ;
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ ) {
V_31 [ V_21 ] = V_33 & 0xff ;
V_33 >>= 8 ;
}
V_30 = V_33 & 0xff ;
break;
}
F_19 ( L_4 , type ) ;
if ( type != V_29 )
F_19 ( L_5 , V_31 , V_30 ) ;
F_19 ( L_6 ) ;
return 0 ;
}
static void F_21 ( struct V_34 * V_35 )
{
struct V_16 * V_16 = V_35 -> V_36 ;
T_3 V_37 [ 14 ] ;
int V_38 = 2 ;
int V_21 ;
F_22 ( 1 << 21 ) ;
while ( V_38 -- ) {
if ( ! F_20 ( V_16 ) )
break;
F_23 ( 500 ) ;
}
if ( V_38 < 0 ) {
F_19 ( L_7 ) ;
return;
}
F_17 ( V_16 , 0xf0 ) ;
F_17 ( V_16 , 0x00 ) ;
F_17 ( V_16 , 0x00 ) ;
for ( V_21 = 13 ; V_21 >= 0 ; V_21 -- )
V_37 [ V_21 ] = F_16 ( V_16 ) ;
for ( V_21 = 2 ; V_21 < 8 ; V_21 ++ )
V_35 -> V_39 -> V_40 [ V_21 - 2 ] = V_37 [ V_21 ] ;
}
static void F_24 ( struct V_34 * V_35 )
{
F_21 ( V_35 ) ;
F_19 ( L_8 , V_35 -> V_39 -> V_40 ) ;
}
static void F_25 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
F_27 ( ( V_39 -> V_40 [ 5 ] << 8 ) | V_39 -> V_40 [ 4 ] ) ;
F_28 ( ( V_39 -> V_40 [ 3 ] << 24 ) | ( V_39 -> V_40 [ 2 ] << 16 ) |
( V_39 -> V_40 [ 1 ] << 8 ) | V_39 -> V_40 [ 0 ] ) ;
}
static int F_29 ( struct V_41 * V_39 , void * V_1 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_42 * V_43 = V_1 ;
memcpy ( V_39 -> V_40 , V_43 -> V_44 , V_39 -> V_45 ) ;
F_30 ( & V_35 -> V_46 ) ;
F_25 ( V_39 ) ;
F_31 ( & V_35 -> V_46 ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_39 , int V_47 , int V_33 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
while ( F_33 () & V_48 ) ;
F_34 ( ( V_47 << V_49 ) | V_33 | V_50 ) ;
while ( F_33 () & V_48 ) ;
return F_35 () & V_51 ;
}
static void F_36 ( struct V_41 * V_39 , int V_47 , int V_33 , int V_8 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
while ( F_33 () & V_48 ) ;
F_37 ( V_8 ) ;
F_34 ( ( V_47 << V_49 ) | V_33 ) ;
while ( F_33 () & V_48 ) ;
}
static struct V_52 * F_38 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
V_39 -> V_53 . V_54 += ( F_39 () & V_55 ) ;
return & V_39 -> V_53 ;
}
static void F_40 ( struct V_3 * V_6 , T_4 V_56 , int V_57 )
{
struct V_58 * V_59 = F_41 ( V_6 ) ;
T_4 V_60 , V_61 ;
unsigned int V_62 ;
struct V_63 * V_64 ;
T_5 * V_65 ;
unsigned char * V_66 ;
if ( V_59 -> V_67 != F_42 ( V_68 ) )
return;
V_64 = (struct V_63 * ) ( ( char * ) V_59 + V_69 ) ;
if ( F_43 ( V_64 ) )
return;
V_62 = V_64 -> V_70 ;
if ( V_62 != V_71 && V_62 != V_72 )
return;
V_60 = V_56 +
( V_64 -> V_73 - ( V_64 -> V_74 << 2 ) ) +
F_42 ( ( T_5 ) V_64 -> V_70 ) +
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
V_6 -> V_77 = V_78 ;
}
static inline void F_44 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_3 * V_6 , * V_79 ;
struct V_16 * V_16 = V_35 -> V_36 ;
int V_80 , V_81 , V_57 ;
struct V_82 * V_83 ;
unsigned long * V_84 ;
T_1 V_85 , V_86 ;
V_84 = V_35 -> V_84 ;
V_80 = V_35 -> V_87 ;
V_81 = V_35 -> V_88 ;
V_6 = V_35 -> V_89 [ V_80 ] ;
V_83 = (struct V_82 * ) ( V_6 -> V_8 - V_90 ) ;
V_85 = F_45 ( V_83 -> V_85 ) ;
while ( V_85 & V_91 ) {
V_86 = F_45 ( V_83 -> V_86 ) ;
if ( V_86 & V_92 ) {
V_57 = ( ( V_85 >> V_93 ) & 0x7ff ) - 4 ;
F_46 ( V_6 , V_57 ) ;
V_6 -> V_70 = F_47 ( V_6 , V_39 ) ;
V_79 = F_2 ( V_94 , V_95 ) ;
if ( ! V_79 ) {
V_39 -> V_53 . V_96 ++ ;
V_79 = V_6 ;
goto V_97;
}
if ( F_4 ( V_39 -> V_98 & V_99 ) )
F_40 ( V_6 ,
V_85 & V_100 , V_57 ) ;
F_48 ( V_6 ) ;
V_35 -> V_89 [ V_80 ] = NULL ;
F_49 ( V_79 , ( 1664 + V_90 ) ) ;
V_83 = (struct V_82 * ) V_79 -> V_8 ;
F_5 ( V_79 , V_90 ) ;
V_39 -> V_53 . V_101 ++ ;
V_39 -> V_53 . V_102 += V_57 ;
} else {
V_79 = V_6 ;
V_39 -> V_53 . V_103 ++ ;
}
if ( V_86 & V_104 )
V_39 -> V_53 . V_105 ++ ;
if ( V_86 & V_106 )
V_39 -> V_53 . V_107 ++ ;
V_97:
V_35 -> V_89 [ V_81 ] = V_79 ;
V_84 [ V_81 ] = F_50 ( F_6 ( V_83 , 1 ) ) ;
V_83 -> V_85 = 0 ;
V_81 = ( V_81 + 1 ) & 511 ;
V_80 = ( V_80 + 1 ) & 511 ;
V_6 = V_35 -> V_89 [ V_80 ] ;
V_83 = (struct V_82 * ) ( V_6 -> V_8 - V_90 ) ;
V_85 = F_45 ( V_83 -> V_85 ) ;
}
F_51 ( ( V_81 << 3 ) | V_108 ) ;
V_35 -> V_88 = V_81 ;
V_35 -> V_87 = V_80 ;
}
static inline void F_52 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
unsigned long V_109 , V_110 ;
struct V_16 * V_16 = V_35 -> V_36 ;
int V_111 , V_112 ;
struct V_3 * V_6 ;
T_1 V_113 ;
F_53 ( & V_35 -> V_46 ) ;
V_113 = F_54 () ;
V_111 = ( V_113 >> 7 ) & 127 ;
V_112 = V_35 -> V_114 ;
V_109 = 0 ;
V_110 = 0 ;
while ( V_112 != V_111 ) {
V_109 ++ ;
V_6 = V_35 -> V_115 [ V_112 ] ;
V_110 += V_6 -> V_57 ;
F_55 ( V_6 ) ;
V_35 -> V_115 [ V_112 ] = NULL ;
V_112 = ( V_112 + 1 ) & 127 ;
V_113 = F_54 () ;
V_111 = ( V_113 >> 7 ) & 127 ;
}
V_39 -> V_53 . V_116 += V_109 ;
V_39 -> V_53 . V_117 += V_110 ;
V_35 -> V_118 -= V_109 ;
if ( V_35 -> V_118 < 128 )
F_56 ( V_39 ) ;
V_35 -> V_114 = V_112 ;
F_57 ( & V_35 -> V_46 ) ;
}
static void F_58 ( struct V_41 * V_39 , T_1 V_119 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
unsigned char * V_120 = V_39 -> V_121 ;
F_53 ( & V_35 -> V_46 ) ;
if ( V_119 & V_122 )
F_19 ( V_123 L_9 , V_120 ) ;
if ( V_119 & V_124 )
F_19 ( V_123 L_10 , V_120 ) ;
if ( V_119 & V_125 )
F_19 ( V_123 L_11 , V_120 ) ;
if ( V_119 & V_126 )
F_19 ( V_123 L_12 , V_120 ) ;
if ( V_119 & V_127 )
F_19 ( V_123 L_13 , V_120 ) ;
if ( V_119 & V_128 )
F_19 ( V_123 L_14 , V_120 ) ;
F_59 ( V_35 ) ;
F_60 ( V_39 ) ;
F_61 ( V_35 ) ;
F_56 ( V_39 ) ;
F_57 ( & V_35 -> V_46 ) ;
}
static T_6 F_62 ( int V_129 , void * V_130 )
{
struct V_41 * V_39 = (struct V_41 * ) V_130 ;
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
const T_1 V_131 = V_132 | V_122 | V_124 |
V_125 | V_126 | V_127 |
V_133 | V_128 ;
T_1 V_119 ;
V_119 = F_63 () & V_131 ;
F_64 ( V_119 ) ;
( void ) F_63 () ;
if ( V_119 & ( V_122 | V_124 | V_125 |
V_126 | V_127 | V_128 ) )
F_58 ( V_39 , V_119 ) ;
if ( V_119 & V_132 )
F_44 ( V_39 ) ;
if ( V_119 & V_133 )
F_52 ( V_39 ) ;
return V_134 ;
}
static inline void F_65 ( struct V_34 * V_35 )
{
struct V_16 * V_16 = V_35 -> V_36 ;
if ( V_35 -> V_135 . V_136 ) {
F_66 ( V_137 ) ;
V_35 -> V_138 |= V_139 ;
} else {
F_66 ( V_140 ) ;
V_35 -> V_138 &= ~ V_139 ;
}
F_67 ( V_35 -> V_138 ) ;
}
static void F_68 ( unsigned long V_8 )
{
struct V_34 * V_35 = (struct V_34 * ) V_8 ;
F_69 ( & V_35 -> V_135 , 1 , 0 ) ;
F_65 ( V_35 ) ;
V_35 -> F_68 . V_141 = V_142 + ( ( 12 * V_143 ) / 10 ) ;
F_70 ( & V_35 -> F_68 ) ;
}
static int F_61 ( struct V_34 * V_35 )
{
int V_21 , V_144 = 0 , V_145 = 0 ;
int V_146 = 1 ;
T_7 V_147 ;
for ( V_21 = 0 ; V_21 < 32 ; V_21 ++ ) {
V_147 = F_32 ( V_35 -> V_39 , V_21 , V_148 ) ;
if ( V_147 != 0xffff && V_147 != 0x0000 ) {
V_144 = 1 ;
break;
}
}
if ( ! V_144 ) {
if ( V_146 )
V_21 = 31 ;
else {
V_35 -> V_135 . V_149 = - 1 ;
V_145 = - V_150 ;
goto V_151;
}
}
V_35 -> V_135 . V_149 = V_21 ;
V_151:
return V_145 ;
}
static void F_71 ( struct V_34 * V_35 )
{
V_35 -> F_68 . V_141 = V_142 + ( 12 * V_143 ) / 10 ;
V_35 -> F_68 . V_8 = ( unsigned long ) V_35 ;
V_35 -> F_68 . V_152 = F_68 ;
F_70 ( & V_35 -> F_68 ) ;
}
static inline void F_72 ( struct V_34 * V_35 )
{
struct V_3 * V_6 ;
int V_21 ;
for ( V_21 = V_35 -> V_87 ; V_21 & 15 ; V_21 ++ ) {
V_35 -> V_89 [ V_35 -> V_88 ] = V_35 -> V_89 [ V_35 -> V_87 ] ;
V_35 -> V_84 [ V_35 -> V_88 ++ ] = V_35 -> V_84 [ V_35 -> V_87 ++ ] ;
}
V_35 -> V_88 &= 511 ;
V_35 -> V_87 &= 511 ;
for ( V_21 = V_35 -> V_87 ; V_21 != V_35 -> V_88 ; V_21 = ( V_21 + 1 ) & 511 ) {
struct V_82 * V_83 ;
V_6 = V_35 -> V_89 [ V_21 ] ;
V_83 = (struct V_82 * ) ( V_6 -> V_8 - V_90 ) ;
V_83 -> V_85 = 0 ;
}
}
static inline void F_73 ( struct V_34 * V_35 )
{
struct V_3 * V_6 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 128 ; V_21 ++ ) {
V_6 = V_35 -> V_115 [ V_21 ] ;
if ( V_6 ) {
V_35 -> V_115 [ V_21 ] = NULL ;
F_74 ( V_6 ) ;
}
V_35 -> V_153 [ V_21 ] . V_154 = 0 ;
}
V_35 -> V_155 = 0 ;
V_35 -> V_114 = 0 ;
}
static void F_75 ( struct V_34 * V_35 )
{
struct V_3 * V_6 ;
int V_80 , V_81 ;
if ( V_35 -> V_153 ) {
F_73 ( V_35 ) ;
F_76 ( ( unsigned long ) V_35 -> V_153 , 2 ) ;
V_35 -> V_153 = NULL ;
}
if ( V_35 -> V_84 ) {
V_81 = V_35 -> V_87 ;
V_80 = V_35 -> V_88 ;
while ( V_81 != V_80 ) {
V_6 = V_35 -> V_89 [ V_81 ] ;
if ( V_6 )
F_74 ( V_6 ) ;
V_81 = ( V_81 + 1 ) & 511 ;
}
F_77 ( ( unsigned long ) V_35 -> V_84 ) ;
V_35 -> V_84 = NULL ;
}
}
static void F_78 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_82 * V_83 ;
unsigned long * V_84 ;
int V_21 ;
if ( V_35 -> V_84 == NULL ) {
V_35 -> V_84 = ( unsigned long * ) F_79 ( V_95 ) ;
V_84 = V_35 -> V_84 ;
if ( ! V_84 )
F_19 ( L_15 ) ;
for ( V_21 = 0 ; V_21 < V_156 ; V_21 ++ ) {
struct V_3 * V_6 ;
V_6 = F_2 ( V_94 , V_95 ) ;
if ( ! V_6 ) {
F_80 ( 0 , NULL ) ;
continue;
}
V_35 -> V_89 [ V_21 ] = V_6 ;
F_49 ( V_6 , ( 1664 + V_90 ) ) ;
V_83 = (struct V_82 * ) V_6 -> V_8 ;
V_84 [ V_21 ] = F_50 ( F_6 ( V_83 , 1 ) ) ;
F_5 ( V_6 , V_90 ) ;
}
V_35 -> V_87 = 0 ;
V_35 -> V_88 = V_156 ;
}
if ( V_35 -> V_153 == NULL ) {
V_35 -> V_153 = (struct V_157 * ) F_81 ( V_158 , 2 ) ;
if ( ! V_35 -> V_153 )
F_19 ( L_16 ) ;
V_35 -> V_155 = 0 ;
V_35 -> V_114 = 0 ;
}
}
static void F_82 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
unsigned long V_159 ;
F_75 ( V_35 ) ;
F_78 ( V_39 ) ;
F_72 ( V_35 ) ;
F_73 ( V_35 ) ;
V_159 = F_6 ( V_35 -> V_84 , 0 ) ;
F_83 ( V_159 >> 32 ) ;
F_84 ( V_159 & 0xffffffff ) ;
F_85 ( V_35 -> V_87 << 3 ) ;
F_51 ( ( V_35 -> V_88 << 3 ) | V_108 ) ;
V_159 = F_6 ( V_35 -> V_153 , 0 ) ;
V_35 -> V_118 = 0 ;
F_86 ( V_159 >> 32 ) ;
F_87 ( V_159 & 0xffffffff ) ;
F_88 ( V_35 -> V_155 << 7 ) ;
F_89 ( V_35 -> V_114 << 7 ) ;
( void ) F_54 () ;
}
static inline void F_90 ( struct V_34 * V_35 )
{
struct V_16 * V_16 = V_35 -> V_36 ;
volatile T_1 * V_160 = & V_16 -> V_161 [ 0x0000 ] ;
volatile T_1 * V_162 = & V_16 -> V_161 [ 0x4000 ] ;
unsigned int V_163 = 0x5555 ;
F_67 ( F_91 () | ( V_164 | V_165 ) ) ;
* V_160 = V_163 ;
* V_162 = ~ V_163 & V_166 ;
if ( ( * V_160 & V_166 ) != V_163 ||
( * V_162 & V_166 ) != ( ~ V_163 & V_166 ) ) {
V_35 -> V_138 = V_165 ;
F_67 ( F_91 () & ~ V_164 ) ;
} else
V_35 -> V_138 = V_164 | V_165 ;
}
static void F_60 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
F_92 ( & V_35 -> F_68 ) ;
F_67 ( V_167 ) ;
( void ) F_91 () ;
F_23 ( 4 ) ;
F_67 ( 0 ) ;
( void ) F_91 () ;
#ifdef F_7
F_93 ( V_168 >> 32 ) ;
#else
F_93 ( 0 ) ;
#endif
( void ) F_39 () ;
F_94 ( 15 ) ;
F_95 ( 0 ) ;
F_25 ( V_39 ) ;
F_96 ( V_35 -> V_169 ) ;
F_97 ( V_35 -> V_170 ) ;
F_98 ( 42 ) ;
F_82 ( V_39 ) ;
V_35 -> V_138 |= ( ( V_90 / 2 ) << V_171 ) | V_172 |
V_173 | V_174 | V_175 | V_176 ;
F_67 ( V_35 -> V_138 ) ;
F_99 ( V_132 | V_122 | V_124 |
V_125 | V_126 | V_127 |
V_133 | V_128 ) ;
( void ) F_100 () ;
}
static inline void F_59 ( struct V_34 * V_35 )
{
struct V_16 * V_16 = V_35 -> V_36 ;
F_67 ( 0 ) ;
F_99 ( 0 ) ;
( void ) F_100 () ;
}
static int F_101 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
if ( F_102 ( V_39 -> V_129 , F_62 , V_177 , V_178 , V_39 ) ) {
F_19 ( V_123 L_17 , V_39 -> V_121 , V_39 -> V_129 ) ;
return - V_179 ;
}
V_35 -> V_169 = 0 ;
V_35 -> V_170 = 0 ;
F_60 ( V_39 ) ;
F_71 ( V_35 ) ;
F_103 ( V_39 ) ;
return 0 ;
}
static int F_104 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
F_92 ( & V_35 -> F_68 ) ;
F_105 ( V_39 ) ;
F_59 ( V_35 ) ;
F_106 ( V_39 -> V_129 , V_39 ) ;
F_75 ( V_35 ) ;
return 0 ;
}
static int F_107 ( struct V_180 * V_181 , int V_182 )
{
struct V_180 * V_39 = F_108 ( V_181 -> V_183 , F_109 ( V_182 , 0 ) ) ;
int V_184 = 0 ;
if ( V_39 ) {
if ( V_39 -> V_185 == V_186 &&
V_39 -> V_187 == V_188 )
V_184 = 1 ;
F_110 ( V_39 ) ;
}
return V_184 ;
}
static int F_111 ( struct V_180 * V_181 )
{
return V_181 -> V_183 -> V_189 == NULL &&
F_107 ( V_181 , 0 ) &&
F_107 ( V_181 , 1 ) &&
F_107 ( V_181 , 2 ) ;
}
static void F_112 ( struct V_190 T_8 * V_191 )
{
#define F_113 6
struct V_192 V_193 = {
. V_193 = {
. V_129 = 0 ,
. V_194 = V_195 | V_196 ,
. V_197 = V_198 ,
. V_199 = 0 ,
. V_200 = ( 22000000 << 1 ) / F_113 ,
. V_201 = ( unsigned char T_8 * ) V_191 ,
. V_202 = ( unsigned long ) V_191 ,
}
} ;
unsigned char V_203 ;
V_203 = V_191 -> V_204 ;
V_191 -> V_204 = V_203 | V_205 ;
V_191 -> V_206 = F_113 ,
V_191 -> V_204 = V_203 ;
V_191 -> V_204 ;
F_114 ( & V_193 ) ;
}
static void F_115 ( struct V_180 * V_181 , struct V_16 * V_16 )
{
if ( F_111 ( V_181 ) && F_116 ( V_181 -> V_207 ) == 3 )
return;
V_16 -> V_208 = V_209 | V_210 ;
V_16 -> V_208 ;
V_16 -> V_211 = 0 ;
V_16 -> V_211 ;
V_16 -> V_212 = 0 ;
V_16 -> V_212 ;
V_16 -> V_213 = V_16 -> V_213 & ~ V_214 ;
V_16 -> V_213 ;
V_16 -> V_215 = V_16 -> V_215 & ~ V_214 ;
V_16 -> V_215 ;
V_16 -> V_216 &= ~ ( V_217 | V_218 |
V_219 | V_220 |
V_221 | V_222 |
V_223 | V_224 ) ;
V_16 -> V_216 |= V_225 ;
V_16 -> V_213 = 0 ;
V_16 -> V_216 &= ~ ( V_226 | V_227 |
V_228 | V_229 |
V_230 | V_231 |
V_232 | V_233 ) ;
V_16 -> V_216 |= V_234 ;
V_16 -> V_215 = 0 ;
F_112 ( & V_16 -> V_235 . V_236 ) ;
F_112 ( & V_16 -> V_235 . V_237 ) ;
}
static int F_117 ( struct V_180 * V_181 , const struct V_238 * V_239 )
{
unsigned int V_240 , V_241 ;
struct V_41 * V_39 = NULL ;
struct V_34 * V_35 ;
struct V_16 * V_16 ;
unsigned long V_242 , V_243 ;
T_1 V_185 , V_244 , V_245 ;
int V_86 , V_246 ;
V_86 = F_118 ( V_181 , F_119 ( 64 ) ) ;
if ( ! V_86 ) {
V_246 = 1 ;
V_86 = F_120 ( V_181 , F_119 ( 64 ) ) ;
if ( V_86 < 0 ) {
F_19 ( V_123 L_18
L_19 , F_121 ( V_181 ) ) ;
goto V_151;
}
} else {
V_86 = F_118 ( V_181 , F_119 ( 32 ) ) ;
if ( V_86 ) {
F_19 ( V_123 L_20
L_21 , F_121 ( V_181 ) ) ;
goto V_151;
}
V_246 = 0 ;
}
if ( F_122 ( V_181 ) )
return - V_150 ;
V_39 = F_123 ( sizeof( struct V_34 ) ) ;
if ( ! V_39 ) {
V_86 = - V_247 ;
goto V_248;
}
if ( V_246 )
V_39 -> V_98 |= V_249 ;
V_86 = F_124 ( V_181 , L_22 ) ;
if ( V_86 )
goto V_250;
F_125 ( V_39 , & V_181 -> V_39 ) ;
V_35 = F_26 ( V_39 ) ;
V_35 -> V_39 = V_39 ;
V_39 -> V_129 = V_181 -> V_129 ;
V_242 = F_126 ( V_181 , 0 ) ;
V_243 = F_127 ( V_181 , 0 ) ;
V_16 = (struct V_16 * ) F_128 ( V_242 , V_243 ) ;
if ( ! V_16 ) {
F_19 ( V_251 L_23 ,
F_121 ( V_181 ) ) ;
V_86 = - V_247 ;
goto V_252;
}
V_35 -> V_36 = V_16 ;
#ifdef F_129
F_115 ( V_181 , V_16 ) ;
#endif
F_130 ( & V_35 -> V_46 ) ;
F_131 ( & V_35 -> F_68 ) ;
F_59 ( V_35 ) ;
F_60 ( V_39 ) ;
V_35 -> V_181 = V_181 ;
V_35 -> V_135 . V_253 = 0x1f ;
V_35 -> V_135 . V_254 = 0x1f ;
V_35 -> V_135 . V_39 = V_39 ;
V_35 -> V_135 . V_255 = F_32 ;
V_35 -> V_135 . V_256 = F_36 ;
F_61 ( V_35 ) ;
if ( V_35 -> V_135 . V_149 == - 1 ) {
F_19 ( V_251 L_24 ,
F_121 ( V_181 ) ) ;
V_86 = - V_150 ;
goto V_257;
}
F_71 ( V_35 ) ;
F_90 ( V_35 ) ;
F_24 ( V_35 ) ;
V_39 -> V_258 = 5 * V_143 ;
V_39 -> V_259 = & V_260 ;
V_39 -> V_261 = & V_262 ;
V_39 -> V_263 = V_264 | V_99 ;
V_39 -> V_98 = V_264 ;
V_240 = F_32 ( V_39 , V_35 -> V_135 . V_149 , V_148 ) ;
V_241 = F_32 ( V_39 , V_35 -> V_135 . V_149 , V_265 ) ;
V_86 = F_132 ( V_39 ) ;
if ( V_86 )
goto V_257;
F_69 ( & V_35 -> V_135 , 1 , 1 ) ;
F_65 ( V_35 ) ;
V_185 = ( V_240 << 12 ) | ( V_241 >> 4 ) ;
V_244 = ( V_241 >> 4 ) & 0x3f ;
V_245 = V_241 & 0xf ;
F_19 ( V_266 L_25
L_26 , V_39 -> V_121 , V_35 -> V_135 . V_149 , V_185 , V_244 , V_245 ) ;
F_19 ( V_266 L_27 , V_39 -> V_121 ,
V_35 -> V_138 & V_164 ? 128 : 64 ) ;
return 0 ;
V_257:
F_59 ( V_35 ) ;
F_92 ( & V_35 -> F_68 ) ;
F_75 ( V_35 ) ;
V_252:
F_133 ( V_181 ) ;
V_250:
F_134 ( V_39 ) ;
V_248:
V_151:
return V_86 ;
}
static void F_135 ( struct V_180 * V_181 )
{
struct V_41 * V_39 = F_136 ( V_181 ) ;
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
F_137 ( V_39 ) ;
F_92 ( & V_35 -> F_68 ) ;
F_138 ( V_16 ) ;
F_133 ( V_181 ) ;
F_134 ( V_39 ) ;
}
static int F_139 ( struct V_3 * V_6 , struct V_41 * V_39 )
{
unsigned long V_8 ;
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
unsigned int V_57 ;
struct V_157 * V_267 ;
T_4 V_85 = 0 ;
int V_268 ;
if ( V_6 -> V_77 == V_269 ) {
const struct V_63 * V_64 = F_140 ( V_6 ) ;
const int V_62 = F_141 ( V_64 -> V_70 ) ;
unsigned int V_270 ;
T_4 V_60 , V_61 ;
T_5 * V_59 ;
V_59 = ( T_5 * ) V_6 -> V_8 ;
V_61 = V_59 [ 0 ] + V_59 [ 1 ] + V_59 [ 2 ] + V_59 [ 3 ] + V_59 [ 4 ] + V_59 [ 5 ] + V_59 [ 6 ] ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_61 = ( V_61 & 0xffff ) + ( V_61 >> 16 ) ;
V_60 = F_142 ( V_64 -> V_75 , V_64 -> V_76 ,
V_64 -> V_73 - ( V_64 -> V_74 << 2 ) ,
V_62 , 0xffff ^ V_61 ) ;
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
V_60 = ( V_60 & 0xffff ) + ( V_60 >> 16 ) ;
V_270 = V_69 + ( V_64 -> V_74 << 2 ) ;
if ( V_62 == V_72 ) {
V_270 += F_143 ( struct V_271 , V_272 ) ;
F_144 ( V_6 ) -> V_272 = V_60 ;
}
if ( V_62 == V_71 ) {
V_270 += F_143 ( struct V_273 , V_272 ) ;
F_145 ( V_6 ) -> V_272 = V_60 ;
}
V_85 = V_274 | ( V_270 << V_275 ) ;
}
F_30 ( & V_35 -> V_46 ) ;
V_8 = ( unsigned long ) V_6 -> V_8 ;
V_57 = V_6 -> V_57 ;
V_268 = V_35 -> V_155 ;
V_267 = & V_35 -> V_153 [ V_268 ] ;
if ( V_57 <= 104 ) {
F_146 ( V_6 , V_267 -> V_8 , V_6 -> V_57 ) ;
if ( V_57 < V_276 ) {
memset ( V_267 -> V_8 + V_57 , 0 , V_276 - V_57 ) ;
V_57 = V_276 ;
}
V_267 -> V_154 = F_147 ( V_57 | V_277 | V_278 | V_85 ) ;
V_267 -> V_279 = F_147 ( V_57 ) ;
} else if ( ( V_8 ^ ( V_8 + V_57 - 1 ) ) & 0x4000 ) {
unsigned long V_280 = ( V_8 | 0x3fffUL ) + 1UL ;
unsigned long V_281 = V_280 - V_8 ;
unsigned long V_282 = V_8 + V_57 - V_280 ;
V_267 -> V_154 = F_147 ( V_57 | V_277 |
V_283 | V_284 | V_85 ) ;
V_267 -> V_279 = F_147 ( ( V_281 << V_285 ) |
( V_282 << V_286 ) ) ;
V_267 -> V_287 = F_50 ( F_6 ( V_6 -> V_8 , 1 ) ) ;
V_267 -> V_288 = F_50 ( F_6 ( ( void * ) V_280 , 1 ) ) ;
} else {
V_267 -> V_154 = F_147 ( V_57 | V_277 | V_283 | V_85 ) ;
V_267 -> V_279 = F_147 ( V_57 << V_285 ) ;
V_267 -> V_287 = F_50 ( F_6 ( V_6 -> V_8 , 1 ) ) ;
}
F_148 () ;
V_35 -> V_115 [ V_268 ] = V_6 ;
V_268 = ( V_268 + 1 ) & 127 ;
V_35 -> V_155 = V_268 ;
F_88 ( V_268 << 7 ) ;
V_35 -> V_118 ++ ;
if ( V_35 -> V_118 >= 127 )
F_105 ( V_39 ) ;
F_31 ( & V_35 -> V_46 ) ;
return V_289 ;
}
static void F_149 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
F_19 ( V_123 L_28 , V_39 -> V_121 ) ;
F_30 ( & V_35 -> V_46 ) ;
F_59 ( V_35 ) ;
F_60 ( V_39 ) ;
F_61 ( V_35 ) ;
F_71 ( V_35 ) ;
F_31 ( & V_35 -> V_46 ) ;
F_56 ( V_39 ) ;
}
static inline unsigned int F_150 ( const unsigned char * V_1 )
{
unsigned int V_290 = 0 ;
T_1 V_30 ;
int V_291 ;
V_30 = F_151 ( V_292 , V_1 ) ;
V_30 &= 0x3f ;
for ( V_291 = 6 ; -- V_291 >= 0 ; ) {
V_290 <<= 1 ;
V_290 |= ( V_30 & 0x1 ) ;
V_30 >>= 1 ;
}
return V_290 ;
}
static void F_152 ( struct V_41 * V_39 ,
struct V_293 * V_294 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
F_153 ( V_294 -> V_295 , V_296 , sizeof( V_294 -> V_295 ) ) ;
F_153 ( V_294 -> V_297 , V_298 , sizeof( V_294 -> V_297 ) ) ;
F_153 ( V_294 -> V_299 , F_121 ( V_35 -> V_181 ) , sizeof( V_294 -> V_299 ) ) ;
}
static int F_154 ( struct V_41 * V_39 ,
struct V_300 * V_154 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
F_30 ( & V_35 -> V_46 ) ;
F_155 ( & V_35 -> V_135 , V_154 ) ;
F_31 ( & V_35 -> V_46 ) ;
return 0 ;
}
static int F_156 ( struct V_41 * V_39 ,
const struct V_300 * V_154 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
int V_301 ;
F_30 ( & V_35 -> V_46 ) ;
V_301 = F_157 ( & V_35 -> V_135 , V_154 ) ;
F_31 ( & V_35 -> V_46 ) ;
return V_301 ;
}
static int F_158 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
int V_301 ;
F_30 ( & V_35 -> V_46 ) ;
V_301 = F_159 ( & V_35 -> V_135 ) ;
F_31 ( & V_35 -> V_46 ) ;
return V_301 ;
}
static T_1 F_160 ( struct V_41 * V_39 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
int V_301 ;
F_30 ( & V_35 -> V_46 ) ;
V_301 = F_161 ( & V_35 -> V_135 ) ;
F_31 ( & V_35 -> V_46 ) ;
return V_301 ;
}
static int F_162 ( struct V_41 * V_39 , struct V_302 * V_303 , int V_154 )
{
struct V_34 * V_35 = F_26 ( V_39 ) ;
int V_301 ;
F_30 ( & V_35 -> V_46 ) ;
V_301 = F_163 ( & V_35 -> V_135 , F_164 ( V_303 ) , V_154 , NULL ) ;
F_31 ( & V_35 -> V_46 ) ;
return V_301 ;
}
static void F_165 ( struct V_41 * V_39 )
{
struct V_304 * V_305 ;
struct V_34 * V_35 = F_26 ( V_39 ) ;
struct V_16 * V_16 = V_35 -> V_36 ;
T_2 V_306 = 0 ;
F_105 ( V_39 ) ;
if ( V_39 -> V_194 & V_307 ) {
V_35 -> V_138 |= V_308 ;
F_67 ( V_35 -> V_138 ) ;
( void ) F_91 () ;
} else {
V_35 -> V_138 &= ~ V_308 ;
F_67 ( V_35 -> V_138 ) ;
( void ) F_91 () ;
if ( ( V_39 -> V_194 & V_309 ) ||
( F_166 ( V_39 ) > 64 ) ) {
V_35 -> V_169 = 0xffffffff ;
V_35 -> V_170 = 0xffffffff ;
} else {
F_167 (ha, dev) {
V_306 |= ( 1UL << F_150 ( V_305 -> V_1 ) ) ;
}
V_35 -> V_169 = V_306 >> 32 ;
V_35 -> V_170 = V_306 & 0xffffffff ;
}
F_96 ( V_35 -> V_169 ) ;
F_97 ( V_35 -> V_170 ) ;
}
F_56 ( V_39 ) ;
}
