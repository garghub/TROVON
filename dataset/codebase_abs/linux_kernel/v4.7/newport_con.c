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
int V_59 , V_100 ;
V_59 = V_31 / 8 ;
V_100 = V_63 / 16 ;
V_98 -> V_101 = 1 ;
if ( V_99 ) {
V_98 -> V_102 = V_59 ;
V_98 -> V_103 = V_100 ;
} else
F_25 ( V_98 , V_59 , V_100 ) ;
}
static void F_26 ( struct V_97 * V_104 )
{
if ( ! F_27 ( & V_105 ) && V_96 ) {
F_20 () ;
V_96 = 0 ;
}
}
static void F_28 ( struct V_97 * V_98 , int V_106 , int V_107 , int V_33 ,
int V_32 )
{
int V_3 = ( ( V_107 + V_32 ) << 3 ) - 1 ;
int V_2 = ( ( V_106 << 4 ) + V_17 ) & 0x3ff ;
int V_4 = ( ( ( V_106 + V_33 ) << 4 ) + V_17 - 1 ) & 0x3ff ;
if ( V_35 )
return;
if ( V_2 < V_4 ) {
F_10 ( V_107 << 3 , V_2 , V_3 , V_4 ,
( V_98 -> V_108 & 0xf0 ) >> 4 ) ;
} else {
F_10 ( V_107 << 3 , V_2 , V_3 , 1023 ,
( V_98 -> V_108 & 0xf0 ) >> 4 ) ;
F_10 ( V_107 << 3 , 0 , V_3 , V_4 ,
( V_98 -> V_108 & 0xf0 ) >> 4 ) ;
}
}
static void F_29 ( struct V_97 * V_98 , int V_109 , int V_110 ,
int V_111 )
{
unsigned char * V_112 ;
V_112 = & V_94 [ V_98 -> V_113 ] [ ( V_109 & 0xff ) << 4 ] ;
V_109 = ( V_109 >> 8 ) & 0xff ;
V_111 <<= 3 ;
V_110 <<= 4 ;
F_1 ( V_111 , V_110 , V_111 , V_110 ,
( V_109 & 0xf0 ) >> 4 ) ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_15 = V_109 & 0xf ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_13 | V_114 |
V_115 ) ;
V_6 -> V_7 . V_16 = ( V_111 << 16 ) | ( ( V_110 + V_17 ) & 0x3ff ) ;
V_6 -> V_7 . V_19 = ( ( V_111 + 7 ) << 16 ) ;
F_2 ( V_6 ) ;
F_30 ( V_6 , V_112 ) ;
}
static void F_31 ( struct V_97 * V_98 , const unsigned short * V_116 ,
int V_117 , int V_110 , int V_111 )
{
int V_20 ;
int V_109 ;
unsigned char * V_112 ;
V_109 = ( F_32 ( V_116 ) >> 8 ) & 0xff ;
V_111 <<= 3 ;
V_110 <<= 4 ;
if ( ! V_35 )
F_1 ( V_111 , V_110 ,
V_111 + ( ( V_117 - 1 ) << 3 ) , V_110 ,
( V_109 & 0xf0 ) >> 4 ) ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_15 = V_109 & 0xf ;
V_6 -> V_7 . V_9 = ( V_10 | V_11 |
V_13 | V_114 |
V_115 ) ;
for ( V_20 = 0 ; V_20 < V_117 ; V_20 ++ , V_111 += 8 ) {
V_112 = & V_94 [ V_98 -> V_113 ] [ ( F_32 ( V_116 ++ ) & 0xff ) << 4 ] ;
F_2 ( V_6 ) ;
V_6 -> V_7 . V_16 =
( V_111 << 16 ) | ( ( V_110 + V_17 ) & 0x3ff ) ;
V_6 -> V_7 . V_19 = ( ( V_111 + 7 ) << 16 ) ;
F_30 ( V_6 , V_112 ) ;
}
}
static void F_33 ( struct V_97 * V_98 , int V_118 )
{
unsigned short V_36 ;
int V_119 , V_120 ;
switch ( V_118 ) {
case V_121 :
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 & ~ ( V_122 ) ) ) ;
break;
case V_123 :
case V_124 :
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 | V_122 ) ) ;
V_119 = ( V_98 -> V_125 - V_98 -> V_126 ) / 2 ;
V_120 = ( ( V_119 / V_98 -> V_102 ) << 4 ) + 31 ;
V_119 = ( ( V_119 % V_98 -> V_102 ) << 3 ) + V_85 ;
F_14 ( V_6 , V_127 , V_119 ) ;
F_14 ( V_6 , V_128 , V_120 ) ;
}
}
static int F_34 ( struct V_97 * V_98 )
{
static int V_129 = 0 ;
V_17 = 0 ;
V_6 -> V_57 . V_17 = 0x3ff ;
if ( ! V_129 ) {
if ( F_7 () ) {
V_129 = 1 ;
V_35 = 1 ;
}
}
return 1 ;
}
static int F_35 ( struct V_97 * V_104 , int V_130 , int V_131 )
{
unsigned short V_36 ;
if ( V_130 == 0 ) {
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 | V_132 ) ) ;
} else {
V_36 = F_13 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_37 ,
( V_36 & ~ ( V_132 ) ) ) ;
}
return 1 ;
}
static int F_36 ( int V_133 , struct V_134 * V_135 )
{
int V_136 = V_135 -> V_32 ;
int V_137 = V_135 -> V_33 ;
int V_138 = V_137 * V_135 -> V_139 ;
int V_20 ;
unsigned char * V_140 , * V_28 = V_135 -> V_28 , * V_112 ;
if ( ( V_136 != 8 ) || ( V_137 != 16 )
|| ( V_135 -> V_139 != 256 && V_135 -> V_139 != 512 ) )
return - V_141 ;
if ( ! ( V_140 = F_37 ( V_142 * sizeof( int ) + V_138 ,
V_143 ) ) ) return - V_144 ;
V_140 += V_142 * sizeof( int ) ;
F_38 ( V_140 ) = V_138 ;
F_39 ( V_140 ) = V_135 -> V_139 ;
F_40 ( V_140 ) = 0 ;
V_112 = V_140 ;
for ( V_20 = 0 ; V_20 < V_135 -> V_139 ; V_20 ++ ) {
memcpy ( V_112 , V_28 , V_137 ) ;
V_28 += 32 ;
V_112 += V_137 ;
}
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ ) {
if ( V_94 [ V_20 ] != V_95
&& F_38 ( V_94 [ V_20 ] ) == V_138
&& ! memcmp ( V_94 [ V_20 ] , V_140 , V_138 ) ) {
F_41 ( V_140 - V_142 * sizeof( int ) ) ;
if ( V_20 == V_133 )
return 0 ;
V_140 = V_94 [ V_20 ] ;
break;
}
}
if ( V_94 [ V_133 ] != V_95 ) {
if ( -- F_40 ( V_94 [ V_133 ] ) == 0 )
F_41 ( V_94 [ V_133 ] -
V_142 * sizeof( int ) ) ;
}
F_40 ( V_140 ) ++ ;
V_94 [ V_133 ] = V_140 ;
return 0 ;
}
static int F_21 ( int V_133 , struct V_134 * V_135 )
{
if ( V_94 [ V_133 ] != V_95 ) {
if ( -- F_40 ( V_94 [ V_133 ] ) == 0 )
F_41 ( V_94 [ V_133 ] -
V_142 * sizeof( int ) ) ;
V_94 [ V_133 ] = V_95 ;
}
return 0 ;
}
static int F_42 ( struct V_97 * V_98 , struct V_134 * V_135 , char * V_145 )
{
return F_21 ( V_98 -> V_113 , V_135 ) ;
}
static int F_43 ( struct V_97 * V_98 , struct V_134 * V_146 , unsigned V_147 )
{
return F_36 ( V_98 -> V_113 , V_146 ) ;
}
static int F_44 ( struct V_97 * V_98 , const unsigned char * V_148 )
{
return - V_141 ;
}
static int F_45 ( struct V_97 * V_98 , int V_149 )
{
return 0 ;
}
static int F_46 ( struct V_97 * V_98 , int V_150 , int V_151 , int V_152 ,
int V_149 )
{
int V_117 , V_153 , V_154 ;
unsigned short * V_116 , * V_155 ;
unsigned short V_156 ;
V_35 = 0 ;
if ( V_150 == 0 && V_151 == V_98 -> V_103 ) {
if ( V_152 == V_157 ) {
V_17 = ( V_17 + ( V_149 << 4 ) ) & 0x3ff ;
F_11 ( V_98 -> V_103 - V_149 ,
V_98 -> V_103 - 1 ,
( V_98 -> V_108 & 0xf0 ) >> 4 ) ;
} else {
V_17 = ( V_17 + ( - V_149 << 4 ) ) & 0x3ff ;
F_11 ( 0 , V_149 - 1 ,
( V_98 -> V_108 & 0xf0 ) >> 4 ) ;
}
V_6 -> V_57 . V_17 = ( V_17 - 1 ) & 0x3ff ;
return 0 ;
}
V_117 = ( V_151 - V_150 - V_149 ) * V_98 -> V_102 ;
if ( V_152 == V_157 ) {
V_153 = 0 ;
V_154 = V_150 ;
V_116 = ( unsigned short * ) ( V_98 -> V_158 +
V_98 -> V_159 * ( V_150 + V_149 ) ) ;
V_155 = ( unsigned short * ) ( V_98 -> V_158 +
V_98 -> V_159 * V_150 ) ;
while ( V_117 -- ) {
V_156 = F_32 ( V_116 ++ ) ;
if ( V_156 != F_32 ( V_155 ) ) {
F_29 ( V_98 , V_156 , V_154 , V_153 ) ;
F_47 ( V_156 , V_155 ) ;
}
V_155 ++ ;
if ( ++ V_153 == V_98 -> V_102 ) {
V_153 = 0 ;
V_154 ++ ;
}
}
V_155 = ( unsigned short * ) ( V_98 -> V_158 +
V_98 -> V_159 * ( V_151 - V_149 ) ) ;
V_153 = 0 ;
V_154 = V_151 - V_149 ;
for ( V_117 = 0 ; V_117 < ( V_149 * V_98 -> V_102 ) ; V_117 ++ ) {
if ( F_32 ( V_155 ) != V_98 -> V_160 ) {
F_29 ( V_98 , V_98 -> V_160 ,
V_154 , V_153 ) ;
F_47 ( V_98 -> V_160 , V_155 ) ;
}
V_155 ++ ;
if ( ++ V_153 == V_98 -> V_102 ) {
V_153 = 0 ;
V_154 ++ ;
}
}
} else {
V_153 = V_98 -> V_102 - 1 ;
V_154 = V_151 - 1 ;
V_116 = ( unsigned short * ) ( V_98 -> V_158 +
V_98 -> V_159 * ( V_151 - V_149 ) - 2 ) ;
V_155 = ( unsigned short * ) ( V_98 -> V_158 +
V_98 -> V_159 * V_151 - 2 ) ;
while ( V_117 -- ) {
V_156 = F_32 ( V_116 -- ) ;
if ( V_156 != F_32 ( V_155 ) ) {
F_29 ( V_98 , V_156 , V_154 , V_153 ) ;
F_47 ( V_156 , V_155 ) ;
}
V_155 -- ;
if ( V_153 -- == 0 ) {
V_153 = V_98 -> V_102 - 1 ;
V_154 -- ;
}
}
V_155 = ( unsigned short * ) ( V_98 -> V_158 +
V_98 -> V_159 * V_150 ) ;
V_153 = 0 ;
V_154 = V_150 ;
for ( V_117 = 0 ; V_117 < ( V_149 * V_98 -> V_102 ) ; V_117 ++ ) {
if ( F_32 ( V_155 ) != V_98 -> V_160 ) {
F_29 ( V_98 , V_98 -> V_160 ,
V_154 , V_153 ) ;
F_47 ( V_98 -> V_160 , V_155 ) ;
}
V_155 ++ ;
if ( ++ V_153 == V_98 -> V_102 ) {
V_153 = 0 ;
V_154 ++ ;
}
}
}
return 1 ;
}
static void F_48 ( struct V_97 * V_98 , int V_106 , int V_107 , int V_161 ,
int V_162 , int V_137 , int V_136 )
{
short V_163 , V_164 , V_165 , V_166 , V_167 , V_168 ;
V_163 = V_107 << 3 ;
V_165 = ( ( V_107 + V_136 ) << 3 ) - 1 ;
V_164 = ( ( V_106 << 4 ) + V_17 ) & 0x3ff ;
V_166 = ( ( ( V_106 + V_137 ) << 4 ) - 1 + V_17 ) & 0x3ff ;
V_167 = ( V_162 - V_107 ) << 3 ;
V_168 = ( V_161 - V_106 ) << 4 ;
if ( V_167 > 0 ) {
F_49 ( V_165 , V_163 ) ;
}
F_2 ( V_6 ) ;
V_6 -> V_7 . V_9 = ( V_169 | V_11 |
V_12 | V_13
| V_14 ) ;
V_6 -> V_7 . V_16 = ( V_163 << 16 ) | V_164 ;
V_6 -> V_7 . V_19 = ( V_165 << 16 ) | V_166 ;
V_6 -> V_18 . V_170 = ( V_167 << 16 ) | V_168 ;
}
static int F_50 ( struct V_97 * V_104 )
{
return 0 ;
}
static int F_51 ( struct V_171 * V_172 ,
const struct V_173 * V_174 )
{
unsigned long V_175 ;
int V_176 ;
if ( ! V_172 -> V_177 . V_178 )
return - V_141 ;
if ( V_6 )
return - V_179 ;
V_175 = V_172 -> V_177 . V_178 + 0xF0000 ;
if ( ! F_52 ( V_175 , 0x10000 , L_4 ) )
return - V_180 ;
V_6 = (struct V_181 * )
F_53 ( V_175 , sizeof( struct V_181 ) ) ;
F_54 () ;
V_176 = F_55 ( & V_105 , 0 , V_86 - 1 , 1 ) ;
F_56 () ;
return V_176 ;
}
static void F_57 ( struct V_171 * V_172 )
{
F_58 ( & V_105 ) ;
F_59 ( ( void * ) V_6 ) ;
}
int T_2 F_60 ( void )
{
return F_61 ( & V_182 ) ;
}
void T_3 F_62 ( void )
{
F_63 ( & V_182 ) ;
}
