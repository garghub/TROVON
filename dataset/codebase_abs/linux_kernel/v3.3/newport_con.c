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
V_6 -> V_57 . V_87 = V_88 ;
if ( F_2 ( V_6 ) )
goto V_89;
V_6 -> V_7 . V_90 = V_91 ;
if ( V_6 -> V_7 . V_92 . V_93 != F_23 ( V_91 ) )
goto V_89;
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ )
V_94 [ V_20 ] = V_95 ;
F_12 () ;
F_18 () ;
F_15 () ;
V_96 = 1 ;
return L_3 ;
V_89:
return NULL ;
}
static void F_24 ( struct V_97 * V_98 , int V_99 )
{
V_98 -> V_100 = V_31 / 8 ;
V_98 -> V_101 = V_63 / 16 ;
V_98 -> V_102 = 1 ;
}
static void F_25 ( struct V_97 * V_103 )
{
if ( ! F_26 ( & V_104 ) && V_96 ) {
F_20 () ;
V_96 = 0 ;
}
}
static void F_27 ( struct V_97 * V_98 , int V_105 , int V_106 , int V_33 ,
int V_32 )
{
int V_3 = ( ( V_106 + V_32 ) << 3 ) - 1 ;
int V_2 = ( ( V_105 << 4 ) + V_17 ) & 0x3ff ;
int V_4 = ( ( ( V_105 + V_33 ) << 4 ) + V_17 - 1 ) & 0x3ff ;
if ( V_35 )
return;
if ( V_2 < V_4 ) {
F_10 ( V_106 << 3 , V_2 , V_3 , V_4 ,
( V_98 -> V_107 & 0xf0 ) >> 4 ) ;
} else {
F_10 ( V_106 << 3 , V_2 , V_3 , 1023 ,
( V_98 -> V_107 & 0xf0 ) >> 4 ) ;
F_10 ( V_106 << 3 , 0 , V_3 , V_4 ,
( V_98 -> V_107 & 0xf0 ) >> 4 ) ;
}
}
static void F_28 ( struct V_97 * V_98 , int V_108 , int V_109 ,
int V_110 )
{
unsigned char * V_111 ;
V_111 = & V_94 [ V_98 -> V_112 ] [ ( V_108 & 0xff ) << 4 ] ;
V_108 = ( V_108 >> 8 ) & 0xff ;
V_110 <<= 3 ;
V_109 <<= 4 ;
F_1 ( V_110 , V_109 , V_110 , V_109 ,
( V_108 & 0xf0 ) >> 4 ) ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_15 = V_108 & 0xf ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_13 | V_113 |
V_114 ) ;
V_6 -> V_7 . V_16 = ( V_110 << 16 ) | ( ( V_109 + V_17 ) & 0x3ff ) ;
V_6 -> V_7 . V_19 = ( ( V_110 + 7 ) << 16 ) ;
F_2 ( V_6 ) ;
F_29 ( V_6 , V_111 ) ;
}
static void F_30 ( struct V_97 * V_98 , const unsigned short * V_115 ,
int V_116 , int V_109 , int V_110 )
{
int V_20 ;
int V_108 ;
unsigned char * V_111 ;
V_108 = ( F_31 ( V_115 ) >> 8 ) & 0xff ;
V_110 <<= 3 ;
V_109 <<= 4 ;
if ( ! V_35 )
F_1 ( V_110 , V_109 ,
V_110 + ( ( V_116 - 1 ) << 3 ) , V_109 ,
( V_108 & 0xf0 ) >> 4 ) ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_15 = V_108 & 0xf ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_13 | V_113 |
V_114 ) ;
for ( V_20 = 0 ; V_20 < V_116 ; V_20 ++ , V_110 += 8 ) {
V_111 = & V_94 [ V_98 -> V_112 ] [ ( F_31 ( V_115 ++ ) & 0xff ) << 4 ] ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_16 =
( V_110 << 16 ) | ( ( V_109 + V_17 ) & 0x3ff ) ;
V_6 -> V_7 . V_19 = ( ( V_110 + 7 ) << 16 ) ;
F_29 ( V_6 , V_111 ) ;
}
}
static void F_32 ( struct V_97 * V_98 , int V_117 )
{
unsigned short V_36 ;
int V_118 , V_119 ;
switch ( V_117 ) {
case V_120 :
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 & ~ ( V_121 ) ) ) ;
break;
case V_122 :
case V_123 :
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 | V_121 ) ) ;
V_118 = ( V_98 -> V_124 - V_98 -> V_125 ) / 2 ;
V_119 = ( ( V_118 / V_98 -> V_100 ) << 4 ) + 31 ;
V_118 = ( ( V_118 % V_98 -> V_100 ) << 3 ) + V_85 ;
F_14 ( V_6 , V_126 , V_118 ) ;
F_14 ( V_6 , V_127 , V_119 ) ;
}
}
static int F_33 ( struct V_97 * V_98 )
{
static int V_128 = 0 ;
V_17 = 0 ;
V_6 -> V_57 . V_17 = 0x3ff ;
if ( ! V_128 ) {
if ( F_7 () ) {
V_128 = 1 ;
V_35 = 1 ;
}
}
return 1 ;
}
static int F_34 ( struct V_97 * V_103 , int V_129 , int V_130 )
{
unsigned short V_36 ;
if ( V_129 == 0 ) {
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 | V_131 ) ) ;
} else {
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 & ~ ( V_131 ) ) ) ;
}
return 1 ;
}
static int F_35 ( int V_132 , struct V_133 * V_134 )
{
int V_135 = V_134 -> V_32 ;
int V_136 = V_134 -> V_33 ;
int V_137 = V_136 * V_134 -> V_138 ;
int V_20 ;
unsigned char * V_139 , * V_28 = V_134 -> V_28 , * V_111 ;
if ( ( V_135 != 8 ) || ( V_136 != 16 )
|| ( V_134 -> V_138 != 256 && V_134 -> V_138 != 512 ) )
return - V_140 ;
if ( ! ( V_139 = F_36 ( V_141 * sizeof( int ) + V_137 ,
V_142 ) ) ) return - V_143 ;
V_139 += V_141 * sizeof( int ) ;
F_37 ( V_139 ) = V_137 ;
F_38 ( V_139 ) = V_134 -> V_138 ;
F_39 ( V_139 ) = 0 ;
V_111 = V_139 ;
for ( V_20 = 0 ; V_20 < V_134 -> V_138 ; V_20 ++ ) {
memcpy ( V_111 , V_28 , V_136 ) ;
V_28 += 32 ;
V_111 += V_136 ;
}
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ ) {
if ( V_94 [ V_20 ] != V_95
&& F_37 ( V_94 [ V_20 ] ) == V_137
&& ! memcmp ( V_94 [ V_20 ] , V_139 , V_137 ) ) {
F_40 ( V_139 - V_141 * sizeof( int ) ) ;
if ( V_20 == V_132 )
return 0 ;
V_139 = V_94 [ V_20 ] ;
break;
}
}
if ( V_94 [ V_132 ] != V_95 ) {
if ( -- F_39 ( V_94 [ V_132 ] ) == 0 )
F_40 ( V_94 [ V_132 ] -
V_141 * sizeof( int ) ) ;
}
F_39 ( V_139 ) ++ ;
V_94 [ V_132 ] = V_139 ;
return 0 ;
}
static int F_21 ( int V_132 , struct V_133 * V_134 )
{
if ( V_94 [ V_132 ] != V_95 ) {
if ( -- F_39 ( V_94 [ V_132 ] ) == 0 )
F_40 ( V_94 [ V_132 ] -
V_141 * sizeof( int ) ) ;
V_94 [ V_132 ] = V_95 ;
}
return 0 ;
}
static int F_41 ( struct V_97 * V_98 , struct V_133 * V_134 , char * V_144 )
{
return F_21 ( V_98 -> V_112 , V_134 ) ;
}
static int F_42 ( struct V_97 * V_98 , struct V_133 * V_145 , unsigned V_146 )
{
return F_35 ( V_98 -> V_112 , V_145 ) ;
}
static int F_43 ( struct V_97 * V_98 , unsigned char * V_147 )
{
return - V_140 ;
}
static int F_44 ( struct V_97 * V_98 , int V_148 )
{
return 0 ;
}
static int F_45 ( struct V_97 * V_98 , int V_149 , int V_150 , int V_151 ,
int V_148 )
{
int V_116 , V_152 , V_153 ;
unsigned short * V_115 , * V_154 ;
unsigned short V_155 ;
V_35 = 0 ;
if ( V_149 == 0 && V_150 == V_98 -> V_101 ) {
if ( V_151 == V_156 ) {
V_17 = ( V_17 + ( V_148 << 4 ) ) & 0x3ff ;
F_11 ( V_98 -> V_101 - V_148 ,
V_98 -> V_101 - 1 ,
( V_98 -> V_107 & 0xf0 ) >> 4 ) ;
} else {
V_17 = ( V_17 + ( - V_148 << 4 ) ) & 0x3ff ;
F_11 ( 0 , V_148 - 1 ,
( V_98 -> V_107 & 0xf0 ) >> 4 ) ;
}
V_6 -> V_57 . V_17 = ( V_17 - 1 ) & 0x3ff ;
return 0 ;
}
V_116 = ( V_150 - V_149 - V_148 ) * V_98 -> V_100 ;
if ( V_151 == V_156 ) {
V_152 = 0 ;
V_153 = V_149 ;
V_115 = ( unsigned short * ) ( V_98 -> V_157 +
V_98 -> V_158 * ( V_149 + V_148 ) ) ;
V_154 = ( unsigned short * ) ( V_98 -> V_157 +
V_98 -> V_158 * V_149 ) ;
while ( V_116 -- ) {
V_155 = F_31 ( V_115 ++ ) ;
if ( V_155 != F_31 ( V_154 ) ) {
F_28 ( V_98 , V_155 , V_153 , V_152 ) ;
F_46 ( V_155 , V_154 ) ;
}
V_154 ++ ;
if ( ++ V_152 == V_98 -> V_100 ) {
V_152 = 0 ;
V_153 ++ ;
}
}
V_154 = ( unsigned short * ) ( V_98 -> V_157 +
V_98 -> V_158 * ( V_150 - V_148 ) ) ;
V_152 = 0 ;
V_153 = V_150 - V_148 ;
for ( V_116 = 0 ; V_116 < ( V_148 * V_98 -> V_100 ) ; V_116 ++ ) {
if ( F_31 ( V_154 ) != V_98 -> V_159 ) {
F_28 ( V_98 , V_98 -> V_159 ,
V_153 , V_152 ) ;
F_46 ( V_98 -> V_159 , V_154 ) ;
}
V_154 ++ ;
if ( ++ V_152 == V_98 -> V_100 ) {
V_152 = 0 ;
V_153 ++ ;
}
}
} else {
V_152 = V_98 -> V_100 - 1 ;
V_153 = V_150 - 1 ;
V_115 = ( unsigned short * ) ( V_98 -> V_157 +
V_98 -> V_158 * ( V_150 - V_148 ) - 2 ) ;
V_154 = ( unsigned short * ) ( V_98 -> V_157 +
V_98 -> V_158 * V_150 - 2 ) ;
while ( V_116 -- ) {
V_155 = F_31 ( V_115 -- ) ;
if ( V_155 != F_31 ( V_154 ) ) {
F_28 ( V_98 , V_155 , V_153 , V_152 ) ;
F_46 ( V_155 , V_154 ) ;
}
V_154 -- ;
if ( V_152 -- == 0 ) {
V_152 = V_98 -> V_100 - 1 ;
V_153 -- ;
}
}
V_154 = ( unsigned short * ) ( V_98 -> V_157 +
V_98 -> V_158 * V_149 ) ;
V_152 = 0 ;
V_153 = V_149 ;
for ( V_116 = 0 ; V_116 < ( V_148 * V_98 -> V_100 ) ; V_116 ++ ) {
if ( F_31 ( V_154 ) != V_98 -> V_159 ) {
F_28 ( V_98 , V_98 -> V_159 ,
V_153 , V_152 ) ;
F_46 ( V_98 -> V_159 , V_154 ) ;
}
V_154 ++ ;
if ( ++ V_152 == V_98 -> V_100 ) {
V_152 = 0 ;
V_153 ++ ;
}
}
}
return 1 ;
}
static void F_47 ( struct V_97 * V_98 , int V_105 , int V_106 , int V_160 ,
int V_161 , int V_136 , int V_135 )
{
short V_162 , V_163 , V_164 , V_165 , V_166 , V_167 , V_64 ;
V_162 = V_106 << 3 ;
V_164 = ( ( V_106 + V_135 ) << 3 ) - 1 ;
V_163 = ( ( V_105 << 4 ) + V_17 ) & 0x3ff ;
V_165 = ( ( ( V_105 + V_136 ) << 4 ) - 1 + V_17 ) & 0x3ff ;
V_166 = ( V_161 - V_106 ) << 3 ;
V_167 = ( V_160 - V_105 ) << 4 ;
if ( V_166 > 0 ) {
V_64 = V_164 ;
V_164 = V_162 ;
V_162 = V_64 ;
}
F_2 ( V_6 ) ;
V_6 -> V_7 . V_9 = ( V_168 | V_11 |
V_12 | V_13
| V_14 ) ;
V_6 -> V_7 . V_16 = ( V_162 << 16 ) | V_163 ;
V_6 -> V_7 . V_19 = ( V_164 << 16 ) | V_165 ;
V_6 -> V_18 . V_169 = ( V_166 << 16 ) | V_167 ;
}
static int F_48 ( struct V_97 * V_103 )
{
return 0 ;
}
static int F_49 ( struct V_170 * V_171 ,
const struct V_172 * V_173 )
{
unsigned long V_174 ;
if ( ! V_171 -> V_175 . V_176 )
return - V_140 ;
if ( V_6 )
return - V_177 ;
V_174 = V_171 -> V_175 . V_176 + 0xF0000 ;
if ( ! F_50 ( V_174 , 0x10000 , L_4 ) )
return - V_178 ;
V_6 = (struct V_179 * )
F_51 ( V_174 , sizeof( struct V_179 ) ) ;
return F_52 ( & V_104 , 0 , V_86 - 1 , 1 ) ;
}
static void F_53 ( struct V_170 * V_171 )
{
F_54 ( & V_104 ) ;
F_55 ( ( void * ) V_6 ) ;
}
int T_2 F_56 ( void )
{
return F_57 ( & V_180 ) ;
}
void T_3 F_58 ( void )
{
F_59 ( & V_180 ) ;
}
