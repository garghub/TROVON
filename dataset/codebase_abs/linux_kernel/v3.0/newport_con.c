static inline void F_1 ( int V_1 , int V_2 ,
int V_3 , int V_4 , int V_5 )
{
F_2 ( V_6 ) ;
V_6 -> V_7 . V_8 = 0xffffffff ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_12 | V_13
| V_14 ) ;
V_6 -> V_7 . V_15 = V_5 ;
V_6 -> V_7 . V_16 =
( V_1 << 16 ) | ( ( V_2 + V_17 ) & 0x3ff ) ;
V_6 -> V_18 . V_19 =
( ( V_3 + 7 ) << 16 ) | ( ( V_4 + V_17 + 15 ) & 0x3ff ) ;
}
static inline void F_3 ( void )
{
unsigned short V_20 ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ ) {
F_4 ( V_6 ) ;
F_5 ( V_6 , V_21 [ V_20 ] ) ;
F_6 ( V_6 ,
V_22 [ V_20 ] ,
V_23 [ V_20 ] , V_24 [ V_20 ] ) ;
}
}
static const struct V_25 * F_7 ( void )
{
#ifdef F_8
const struct V_25 * V_26 = F_9 ( 8 ) ;
const unsigned char * V_27 ;
const unsigned char * V_28 ;
unsigned long V_20 ;
if ( ! V_26 )
return NULL ;
V_27 = V_26 -> V_27 ;
V_28 = V_26 -> V_28 ;
for ( V_20 = 0 ; V_20 < V_26 -> V_29 ; V_20 ++ ) {
F_4 ( V_6 ) ;
F_5 ( V_6 , V_20 + 0x20 ) ;
F_6 ( V_6 , V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] ) ;
V_27 += 3 ;
}
F_2 ( V_6 ) ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_30 ) ;
V_6 -> V_7 . V_16 = ( ( V_31 - V_26 -> V_32 ) << 16 ) | ( 0 ) ;
V_6 -> V_7 . V_19 = ( ( V_31 - 1 ) << 16 ) ;
F_2 ( V_6 ) ;
for ( V_20 = 0 ; V_20 < V_26 -> V_32 * V_26 -> V_33 ; V_20 ++ )
V_6 -> V_18 . V_34 = * V_28 ++ << 24 ;
return V_26 ;
#endif
}
static inline void F_10 ( int V_1 , int V_2 , int V_3 ,
int V_4 , int V_5 )
{
if ( V_35 )
return;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_8 = 0xffffffff ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_12 | V_13
| V_14 ) ;
V_6 -> V_7 . V_15 = V_5 ;
V_6 -> V_7 . V_16 = ( V_1 << 16 ) | V_2 ;
V_6 -> V_18 . V_19 = ( V_3 << 16 ) | V_4 ;
}
static inline void F_11 ( int V_2 , int V_4 , int V_5 )
{
V_2 = ( ( V_2 << 4 ) + V_17 ) & 0x3ff ;
V_4 = ( ( V_4 << 4 ) + V_17 + 15 ) & 0x3ff ;
F_10 ( 0 , V_2 , 1280 + 63 , V_4 , V_5 ) ;
}
static void F_12 ( void )
{
unsigned short V_36 ;
int V_20 ;
F_2 ( V_6 ) ;
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 | V_38 ) ) ;
V_36 = F_13 ( V_6 , V_39 ) ;
F_14 ( V_6 , V_40 , V_36 ) ;
V_6 -> V_7 . V_41 = ( V_42 | V_43 |
V_44 | V_45 ) ;
for ( V_20 = 0 ; V_20 < 128 ; V_20 ++ ) {
F_4 ( V_6 ) ;
if ( V_20 == 92 || V_20 == 94 )
V_6 -> V_7 . V_46 . V_47 . V_48 = 0xff00 ;
else
V_6 -> V_7 . V_46 . V_47 . V_48 = 0x0000 ;
}
F_3 () ;
V_6 -> V_7 . V_41 = ( V_49 | V_50 |
V_51 | V_52 ) ;
V_6 -> V_7 . V_46 . V_53 . V_54 &= ~ V_55 ;
V_6 -> V_7 . V_41 = ( V_56 | V_50 |
V_51 | V_52 ) ;
V_6 -> V_7 . V_46 . V_53 . V_54 &= ~ V_55 ;
V_17 = 0 ;
V_6 -> V_57 . V_17 = 0x3ff ;
V_6 -> V_57 . V_58 = ( 4096 << 16 ) | 4096 ;
F_10 ( 0 , 0 , 1280 + 63 , 1024 , 0 ) ;
}
static void F_15 ( void )
{
int V_20 , V_59 ;
unsigned short V_60 , V_36 ;
unsigned short V_61 [ 128 ] ;
V_60 = F_13 ( V_6 , V_62 ) ;
F_14 ( V_6 , V_40 , V_60 ) ;
V_6 -> V_7 . V_41 = ( V_42 | V_43 |
V_44 | V_45 ) ;
for ( V_20 = 0 ; V_20 < 128 ; V_20 ++ ) {
F_4 ( V_6 ) ;
V_61 [ V_20 ] = V_6 -> V_7 . V_46 . V_47 . V_48 ;
}
V_31 = V_63 = 0 ;
for ( V_20 = 0 ; V_20 < F_16 ( V_61 ) - 1 && V_61 [ V_20 + 1 ] ; V_20 += 2 ) {
V_59 = 0 ;
F_14 ( V_6 , V_40 , V_61 [ V_20 ] ) ;
V_6 -> V_7 . V_41 = ( V_42 | V_43 |
V_44 | V_45 ) ;
do {
F_4 ( V_6 ) ;
V_36 = V_6 -> V_7 . V_46 . V_47 . V_48 ;
if ( ( V_36 & 1 ) == 0 )
V_59 += ( V_36 >> 7 ) & 0xfe ;
if ( ( V_36 & 0x80 ) == 0 ) {
F_4 ( V_6 ) ;
V_36 = V_6 -> V_7 . V_46 . V_47 . V_48 ;
}
} while ( ( V_36 & 0x8000 ) == 0 );
if ( V_59 ) {
if ( V_59 > V_31 )
V_31 = V_59 ;
V_63 += V_61 [ V_20 + 1 ] ;
}
}
F_17 ( L_1 , V_31 , V_63 ) ;
}
static void F_18 ( void )
{
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
unsigned int V_70 ;
unsigned int V_71 ;
V_66 = V_6 -> V_57 . V_72 & V_73 ;
V_6 -> V_7 . V_41 = ( V_74 | V_75 |
V_76 | V_52 ) ;
V_64 = V_6 -> V_7 . V_46 . V_53 . V_54 ;
V_68 = V_64 & 7 ;
V_65 = ( V_64 >> 4 ) & 7 ;
V_71 = ( ( V_65 > 1 ) && ( V_64 & 0x80 ) ) ? 8 : 24 ;
V_6 -> V_7 . V_41 = ( V_77 | V_75 |
V_76 | V_52 ) ;
V_64 = V_6 -> V_7 . V_46 . V_53 . V_54 ;
if ( ( V_64 & 7 ) < V_68 )
V_68 = ( V_64 & 7 ) ;
V_67 = ( F_13 ( V_6 , V_78 ) >> 5 ) & 7 ;
V_6 -> V_7 . V_41 = ( V_49 | V_50 |
V_79 | V_52 ) ;
V_69 = V_6 -> V_7 . V_46 . V_53 . V_54 & 7 ;
V_6 -> V_7 . V_41 = ( V_80 | V_81 |
V_82 | V_52 ) ;
V_6 -> V_7 . V_46 . V_53 . V_54 = V_83 ;
V_6 -> V_7 . V_41 = ( V_80 | V_81 |
V_84 | V_52 ) ;
V_70 = ( V_6 -> V_7 . V_46 . V_53 . V_54 >> 4 ) - 0x0a ;
#define F_19 ( T_1 ) (char)('A'+(a))
F_17
( L_2 ,
V_65 , V_71 , F_19 ( V_66 ) , F_19 ( V_67 ) , F_19 ( V_69 ) ,
F_19 ( V_68 ? ( V_68 + 1 ) : 0 ) , F_19 ( V_70 ) ) ;
#undef F_19
if ( V_65 == 3 )
V_85 = 21 ;
}
static void F_20 ( void )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ )
F_21 ( V_20 , NULL ) ;
}
static const char * F_22 ( void )
{
int V_20 ;
if ( ! V_87 )
return NULL ;
if ( ! V_6 )
V_6 = (struct V_88 * )
F_23 ( V_87 , sizeof( struct V_88 ) ) ;
V_6 -> V_57 . V_89 = V_90 ;
if ( F_2 ( V_6 ) )
goto V_91;
V_6 -> V_7 . V_92 = V_93 ;
if ( V_6 -> V_7 . V_94 . V_95 != F_24 ( V_93 ) )
goto V_91;
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ )
V_96 [ V_20 ] = V_97 ;
F_12 () ;
F_18 () ;
F_15 () ;
V_98 = 1 ;
return L_3 ;
V_91:
return NULL ;
}
static void F_25 ( struct V_99 * V_100 , int V_101 )
{
V_100 -> V_102 = V_31 / 8 ;
V_100 -> V_103 = V_63 / 16 ;
V_100 -> V_104 = 1 ;
}
static void F_26 ( struct V_99 * V_105 )
{
if ( ! F_27 ( & V_106 ) && V_98 ) {
F_20 () ;
V_98 = 0 ;
}
}
static void F_28 ( struct V_99 * V_100 , int V_107 , int V_108 , int V_33 ,
int V_32 )
{
int V_3 = ( ( V_108 + V_32 ) << 3 ) - 1 ;
int V_2 = ( ( V_107 << 4 ) + V_17 ) & 0x3ff ;
int V_4 = ( ( ( V_107 + V_33 ) << 4 ) + V_17 - 1 ) & 0x3ff ;
if ( V_35 )
return;
if ( V_2 < V_4 ) {
F_10 ( V_108 << 3 , V_2 , V_3 , V_4 ,
( V_100 -> V_109 & 0xf0 ) >> 4 ) ;
} else {
F_10 ( V_108 << 3 , V_2 , V_3 , 1023 ,
( V_100 -> V_109 & 0xf0 ) >> 4 ) ;
F_10 ( V_108 << 3 , 0 , V_3 , V_4 ,
( V_100 -> V_109 & 0xf0 ) >> 4 ) ;
}
}
static void F_29 ( struct V_99 * V_100 , int V_110 , int V_111 ,
int V_112 )
{
unsigned char * V_113 ;
V_113 = & V_96 [ V_100 -> V_114 ] [ ( V_110 & 0xff ) << 4 ] ;
V_110 = ( V_110 >> 8 ) & 0xff ;
V_112 <<= 3 ;
V_111 <<= 4 ;
F_1 ( V_112 , V_111 , V_112 , V_111 ,
( V_110 & 0xf0 ) >> 4 ) ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_15 = V_110 & 0xf ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_13 | V_115 |
V_116 ) ;
V_6 -> V_7 . V_16 = ( V_112 << 16 ) | ( ( V_111 + V_17 ) & 0x3ff ) ;
V_6 -> V_7 . V_19 = ( ( V_112 + 7 ) << 16 ) ;
F_2 ( V_6 ) ;
F_30 ( V_6 , V_113 ) ;
}
static void F_31 ( struct V_99 * V_100 , const unsigned short * V_117 ,
int V_118 , int V_111 , int V_112 )
{
int V_20 ;
int V_110 ;
unsigned char * V_113 ;
V_110 = ( F_32 ( V_117 ) >> 8 ) & 0xff ;
V_112 <<= 3 ;
V_111 <<= 4 ;
if ( ! V_35 )
F_1 ( V_112 , V_111 ,
V_112 + ( ( V_118 - 1 ) << 3 ) , V_111 ,
( V_110 & 0xf0 ) >> 4 ) ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_15 = V_110 & 0xf ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_13 | V_115 |
V_116 ) ;
for ( V_20 = 0 ; V_20 < V_118 ; V_20 ++ , V_112 += 8 ) {
V_113 = & V_96 [ V_100 -> V_114 ] [ ( F_32 ( V_117 ++ ) & 0xff ) << 4 ] ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_16 =
( V_112 << 16 ) | ( ( V_111 + V_17 ) & 0x3ff ) ;
V_6 -> V_7 . V_19 = ( ( V_112 + 7 ) << 16 ) ;
F_30 ( V_6 , V_113 ) ;
}
}
static void F_33 ( struct V_99 * V_100 , int V_119 )
{
unsigned short V_36 ;
int V_120 , V_121 ;
switch ( V_119 ) {
case V_122 :
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 & ~ ( V_123 ) ) ) ;
break;
case V_124 :
case V_125 :
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 | V_123 ) ) ;
V_120 = ( V_100 -> V_126 - V_100 -> V_127 ) / 2 ;
V_121 = ( ( V_120 / V_100 -> V_102 ) << 4 ) + 31 ;
V_120 = ( ( V_120 % V_100 -> V_102 ) << 3 ) + V_85 ;
F_14 ( V_6 , V_128 , V_120 ) ;
F_14 ( V_6 , V_129 , V_121 ) ;
}
}
static int F_34 ( struct V_99 * V_100 )
{
static int V_130 = 0 ;
V_17 = 0 ;
V_6 -> V_57 . V_17 = 0x3ff ;
if ( ! V_130 ) {
if ( F_7 () ) {
V_130 = 1 ;
V_35 = 1 ;
}
}
return 1 ;
}
static int F_35 ( struct V_99 * V_105 , int V_131 , int V_132 )
{
unsigned short V_36 ;
if ( V_131 == 0 ) {
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 | V_133 ) ) ;
} else {
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 & ~ ( V_133 ) ) ) ;
}
return 1 ;
}
static int F_36 ( int V_134 , struct V_135 * V_136 )
{
int V_137 = V_136 -> V_32 ;
int V_138 = V_136 -> V_33 ;
int V_139 = V_138 * V_136 -> V_140 ;
int V_20 ;
unsigned char * V_141 , * V_28 = V_136 -> V_28 , * V_113 ;
if ( ( V_137 != 8 ) || ( V_138 != 16 )
|| ( V_136 -> V_140 != 256 && V_136 -> V_140 != 512 ) )
return - V_142 ;
if ( ! ( V_141 = F_37 ( V_143 * sizeof( int ) + V_139 ,
V_144 ) ) ) return - V_145 ;
V_141 += V_143 * sizeof( int ) ;
F_38 ( V_141 ) = V_139 ;
F_39 ( V_141 ) = V_136 -> V_140 ;
F_40 ( V_141 ) = 0 ;
V_113 = V_141 ;
for ( V_20 = 0 ; V_20 < V_136 -> V_140 ; V_20 ++ ) {
memcpy ( V_113 , V_28 , V_138 ) ;
V_28 += 32 ;
V_113 += V_138 ;
}
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ ) {
if ( V_96 [ V_20 ] != V_97
&& F_38 ( V_96 [ V_20 ] ) == V_139
&& ! memcmp ( V_96 [ V_20 ] , V_141 , V_139 ) ) {
F_41 ( V_141 - V_143 * sizeof( int ) ) ;
if ( V_20 == V_134 )
return 0 ;
V_141 = V_96 [ V_20 ] ;
break;
}
}
if ( V_96 [ V_134 ] != V_97 ) {
if ( -- F_40 ( V_96 [ V_134 ] ) == 0 )
F_41 ( V_96 [ V_134 ] -
V_143 * sizeof( int ) ) ;
}
F_40 ( V_141 ) ++ ;
V_96 [ V_134 ] = V_141 ;
return 0 ;
}
static int F_21 ( int V_134 , struct V_135 * V_136 )
{
if ( V_96 [ V_134 ] != V_97 ) {
if ( -- F_40 ( V_96 [ V_134 ] ) == 0 )
F_41 ( V_96 [ V_134 ] -
V_143 * sizeof( int ) ) ;
V_96 [ V_134 ] = V_97 ;
}
return 0 ;
}
static int F_42 ( struct V_99 * V_100 , struct V_135 * V_136 , char * V_146 )
{
return F_21 ( V_100 -> V_114 , V_136 ) ;
}
static int F_43 ( struct V_99 * V_100 , struct V_135 * V_147 , unsigned V_148 )
{
return F_36 ( V_100 -> V_114 , V_147 ) ;
}
static int F_44 ( struct V_99 * V_100 , unsigned char * V_149 )
{
return - V_142 ;
}
static int F_45 ( struct V_99 * V_100 , int V_150 )
{
return 0 ;
}
static int F_46 ( struct V_99 * V_100 , int V_151 , int V_152 , int V_153 ,
int V_150 )
{
int V_118 , V_154 , V_155 ;
unsigned short * V_117 , * V_156 ;
unsigned short V_157 ;
V_35 = 0 ;
if ( V_151 == 0 && V_152 == V_100 -> V_103 ) {
if ( V_153 == V_158 ) {
V_17 = ( V_17 + ( V_150 << 4 ) ) & 0x3ff ;
F_11 ( V_100 -> V_103 - V_150 ,
V_100 -> V_103 - 1 ,
( V_100 -> V_109 & 0xf0 ) >> 4 ) ;
} else {
V_17 = ( V_17 + ( - V_150 << 4 ) ) & 0x3ff ;
F_11 ( 0 , V_150 - 1 ,
( V_100 -> V_109 & 0xf0 ) >> 4 ) ;
}
V_6 -> V_57 . V_17 = ( V_17 - 1 ) & 0x3ff ;
return 0 ;
}
V_118 = ( V_152 - V_151 - V_150 ) * V_100 -> V_102 ;
if ( V_153 == V_158 ) {
V_154 = 0 ;
V_155 = V_151 ;
V_117 = ( unsigned short * ) ( V_100 -> V_159 +
V_100 -> V_160 * ( V_151 + V_150 ) ) ;
V_156 = ( unsigned short * ) ( V_100 -> V_159 +
V_100 -> V_160 * V_151 ) ;
while ( V_118 -- ) {
V_157 = F_32 ( V_117 ++ ) ;
if ( V_157 != F_32 ( V_156 ) ) {
F_29 ( V_100 , V_157 , V_155 , V_154 ) ;
F_47 ( V_157 , V_156 ) ;
}
V_156 ++ ;
if ( ++ V_154 == V_100 -> V_102 ) {
V_154 = 0 ;
V_155 ++ ;
}
}
V_156 = ( unsigned short * ) ( V_100 -> V_159 +
V_100 -> V_160 * ( V_152 - V_150 ) ) ;
V_154 = 0 ;
V_155 = V_152 - V_150 ;
for ( V_118 = 0 ; V_118 < ( V_150 * V_100 -> V_102 ) ; V_118 ++ ) {
if ( F_32 ( V_156 ) != V_100 -> V_161 ) {
F_29 ( V_100 , V_100 -> V_161 ,
V_155 , V_154 ) ;
F_47 ( V_100 -> V_161 , V_156 ) ;
}
V_156 ++ ;
if ( ++ V_154 == V_100 -> V_102 ) {
V_154 = 0 ;
V_155 ++ ;
}
}
} else {
V_154 = V_100 -> V_102 - 1 ;
V_155 = V_152 - 1 ;
V_117 = ( unsigned short * ) ( V_100 -> V_159 +
V_100 -> V_160 * ( V_152 - V_150 ) - 2 ) ;
V_156 = ( unsigned short * ) ( V_100 -> V_159 +
V_100 -> V_160 * V_152 - 2 ) ;
while ( V_118 -- ) {
V_157 = F_32 ( V_117 -- ) ;
if ( V_157 != F_32 ( V_156 ) ) {
F_29 ( V_100 , V_157 , V_155 , V_154 ) ;
F_47 ( V_157 , V_156 ) ;
}
V_156 -- ;
if ( V_154 -- == 0 ) {
V_154 = V_100 -> V_102 - 1 ;
V_155 -- ;
}
}
V_156 = ( unsigned short * ) ( V_100 -> V_159 +
V_100 -> V_160 * V_151 ) ;
V_154 = 0 ;
V_155 = V_151 ;
for ( V_118 = 0 ; V_118 < ( V_150 * V_100 -> V_102 ) ; V_118 ++ ) {
if ( F_32 ( V_156 ) != V_100 -> V_161 ) {
F_29 ( V_100 , V_100 -> V_161 ,
V_155 , V_154 ) ;
F_47 ( V_100 -> V_161 , V_156 ) ;
}
V_156 ++ ;
if ( ++ V_154 == V_100 -> V_102 ) {
V_154 = 0 ;
V_155 ++ ;
}
}
}
return 1 ;
}
static void F_48 ( struct V_99 * V_100 , int V_107 , int V_108 , int V_162 ,
int V_163 , int V_138 , int V_137 )
{
short V_164 , V_165 , V_166 , V_167 , V_168 , V_169 , V_64 ;
V_164 = V_108 << 3 ;
V_166 = ( ( V_108 + V_137 ) << 3 ) - 1 ;
V_165 = ( ( V_107 << 4 ) + V_17 ) & 0x3ff ;
V_167 = ( ( ( V_107 + V_138 ) << 4 ) - 1 + V_17 ) & 0x3ff ;
V_168 = ( V_163 - V_108 ) << 3 ;
V_169 = ( V_162 - V_107 ) << 4 ;
if ( V_168 > 0 ) {
V_64 = V_166 ;
V_166 = V_164 ;
V_164 = V_64 ;
}
F_2 ( V_6 ) ;
V_6 -> V_7 . V_9 = ( V_170 | V_11 |
V_12 | V_13
| V_14 ) ;
V_6 -> V_7 . V_16 = ( V_164 << 16 ) | V_165 ;
V_6 -> V_7 . V_19 = ( V_166 << 16 ) | V_167 ;
V_6 -> V_18 . V_171 = ( V_168 << 16 ) | V_169 ;
}
static int F_49 ( struct V_99 * V_105 )
{
return 0 ;
}
static int T_2 F_50 ( void )
{
if ( ! V_87 )
return 0 ;
if ( ! V_6 )
V_6 = (struct V_88 * )
F_23 ( V_87 , sizeof( struct V_88 ) ) ;
return F_51 ( & V_106 , 0 , V_86 - 1 , 1 ) ;
}
static void T_3 F_52 ( void )
{
F_53 ( & V_106 ) ;
F_54 ( ( void * ) V_6 ) ;
}
