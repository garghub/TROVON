static int F_1 ( unsigned int V_1 , unsigned int * V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
if ( V_1 < 6900 || V_1 > 110000 )
return - V_5 ;
V_4 = ( 28224000 * 2 ) / V_1 ;
V_4 = ( V_4 - 1 ) / 2 ;
if ( V_4 < 0x200 )
* V_2 = V_4 + 0x800 ;
else if ( V_4 < 0x400 )
* V_2 = V_4 & 0x1ff ;
else if ( V_4 < 0x800 ) {
* V_2 = ( ( V_4 >> 1 ) & 0x1ff ) + 0x200 ;
V_4 &= ~ 1 ;
} else {
* V_2 = ( ( V_4 >> 2 ) & 0x1ff ) + 0x400 ;
V_4 &= ~ 3 ;
}
if ( V_3 )
* V_3 = ( 28224000 / ( V_4 + 1 ) ) ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned int * V_4 , unsigned int * V_1 )
{
unsigned int V_9 , V_3 , V_2 ;
struct V_10 V_11 ;
int V_12 ;
V_3 = V_8 ;
switch ( V_7 -> V_13 ) {
case V_14 :
switch ( V_8 ) {
case 48000 : V_9 = V_15 ; break;
case 24000 : V_9 = V_16 ; break;
case 12000 : V_9 = V_17 ; break;
case 32000 : V_9 = V_18 ; break;
case 16000 : V_9 = V_19 ; break;
case 8000 : V_9 = V_20 ; break;
case 44100 : V_9 = V_21 ; break;
case 22050 : V_9 = V_22 ; break;
case 11025 : V_9 = V_23 ; break;
case 192000 : V_9 = V_24 ; break;
case 96000 : V_9 = V_25 ; break;
case 176400 : V_9 = V_26 ; break;
case 88200 : V_9 = V_27 ; break;
case 128000 : V_9 = V_28 ; break;
case 64000 : V_9 = V_29 ; break;
default :
V_9 = V_30 ;
V_12 = F_1 ( V_8 , & V_2 , & V_3 ) ;
if ( V_12 )
return V_12 ;
F_3 ( & V_11 , V_31 ) ;
V_11 . V_32 [ 0 ] |= V_33 ;
V_11 . V_32 [ 1 ] = V_2 & V_34 ;
V_11 . V_32 [ 2 ] = V_2 >> 24 ;
V_11 . V_35 = 3 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_7 -> V_36 -> V_37 ,
L_1
L_2 , V_12 ) ;
return V_12 ;
}
}
break;
case V_38 :
V_9 = V_39 ;
break;
case V_40 :
V_9 = V_41 ;
break;
case V_42 :
V_9 = V_43 ;
break;
case V_44 :
V_9 = V_45 ;
break;
case V_46 :
V_9 = V_47 ;
break;
case V_48 :
V_9 = V_49 ;
break;
default:
return - V_5 ;
}
* V_4 = V_9 ;
* V_1 = V_3 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
unsigned int V_8 ,
int * V_50 )
{
unsigned int V_9 , V_3 , V_51 ;
struct V_10 V_11 ;
int V_12 ;
V_12 = F_2 ( V_7 , V_8 , & V_9 , & V_3 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 < 55000 )
V_51 = 0 ;
else if ( V_8 < 100000 )
V_51 = 1 ;
else
V_51 = 2 ;
if ( V_7 -> V_52 != V_51 ) {
F_3 ( & V_11 , V_31 ) ;
V_11 . V_32 [ 0 ] |= V_53 ;
if ( F_7 ( V_7 ) ) {
V_11 . V_32 [ 1 ] = 1 ;
V_11 . V_35 = 2 ;
}
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
F_3 ( & V_11 , V_31 ) ;
V_11 . V_32 [ 0 ] |= V_54 ;
V_11 . V_32 [ 1 ] = V_51 ;
V_11 . V_35 = 2 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
}
F_8 ( & V_7 -> V_36 -> V_37 , L_3 , V_9 ) ;
V_12 = F_9 ( V_7 , V_55 ,
V_9 , V_50 ) ;
if ( V_12 )
return V_12 ;
V_7 -> V_56 = V_3 ;
V_7 -> V_57 = V_7 -> V_13 ;
if ( V_7 -> V_52 != V_51 ) {
F_3 ( & V_11 , V_58 ) ;
V_11 . V_32 [ 0 ] |= V_53 ;
if ( F_7 ( V_7 ) ) {
V_11 . V_32 [ 1 ] = 1 ;
V_11 . V_35 = 2 ;
}
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
V_7 -> V_52 = V_51 ;
}
F_8 ( & V_7 -> V_36 -> V_37 , L_4 ,
V_8 , V_3 ) ;
return 0 ;
}
int F_10 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_10 V_11 ;
int V_12 , V_50 ;
if ( V_8 == 0 )
return 0 ;
if ( V_7 -> V_59 )
V_12 = F_11 ( V_7 , V_8 , & V_50 ) ;
else
V_12 = F_6 ( V_7 , V_8 , & V_50 ) ;
if ( V_12 )
return V_12 ;
if ( V_50 ) {
F_3 ( & V_11 , V_60 ) ;
V_11 . V_32 [ 0 ] |= V_61 ;
if ( V_8 < V_62 )
V_11 . V_32 [ 1 ] = V_63 ;
else
V_11 . V_32 [ 1 ] = V_63 * 2 ;
V_11 . V_32 [ 2 ] = V_8 ;
V_11 . V_35 = 3 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
enum V_64 V_65 ,
int * V_66 )
{
struct V_10 V_11 ;
unsigned char V_4 ;
int V_12 , V_8 ;
switch ( V_65 ) {
case V_38 :
V_4 = V_67 ;
break;
case V_40 :
V_4 = V_68 ;
break;
case V_42 :
V_4 = V_69 ;
break;
case V_44 :
V_4 = V_70 ;
break;
case V_46 :
V_4 = V_71 ;
break;
case V_48 :
V_4 = V_72 ;
break;
default:
return - V_5 ;
}
F_3 ( & V_11 , V_58 ) ;
V_11 . V_35 = 2 ;
V_11 . V_32 [ 0 ] |= V_73 ;
if ( V_7 -> V_74 != V_4 ) {
V_11 . V_32 [ 1 ] = V_4 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
F_13 ( 100 ) ;
V_7 -> V_74 = V_4 ;
}
V_11 . V_32 [ 1 ] = V_75 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
switch ( V_11 . V_76 [ 1 ] & 0x0f ) {
case V_77 : V_8 = 32000 ; break;
case V_78 : V_8 = 44100 ; break;
case V_79 : V_8 = 48000 ; break;
case V_80 : V_8 = 64000 ; break;
case V_81 : V_8 = 88200 ; break;
case V_82 : V_8 = 96000 ; break;
case V_83 : V_8 = 128000 ; break;
case V_84 : V_8 = 176400 ; break;
case V_85 : V_8 = 192000 ; break;
default: V_8 = 0 ;
}
F_8 ( & V_7 -> V_36 -> V_37 , L_5 , V_8 ) ;
* V_66 = V_8 ;
return 0 ;
}
int F_14 ( struct V_6 * V_7 ,
enum V_64 V_65 ,
int * V_66 )
{
if ( V_7 -> V_59 )
return F_15 ( V_7 , V_65 ,
V_66 ) ;
else
return F_12 ( V_7 , V_65 ,
V_66 ) ;
}
static int F_16 ( struct V_86 * V_87 )
{
int V_12 ;
struct V_88 * V_89 ;
struct V_10 V_11 ;
int V_90 , V_91 ;
if ( V_87 -> V_92 == V_93 )
V_91 = 1 ;
else {
if ( V_87 -> V_92 != V_94 ) {
F_17 ( V_95 L_6
L_7 ) ;
return - V_5 ;
}
V_91 = 0 ;
}
if ( ! V_87 -> V_96 )
return - V_5 ;
V_87 -> V_97 = 0 ;
V_87 -> V_98 = 0 ;
V_87 -> V_99 = 0 ;
V_87 -> V_100 = 0 ;
V_90 =
V_87 -> V_101 -> V_102 ? 1 : 1 << V_87 -> V_96 -> V_103 ;
F_3 ( & V_11 , V_91 ? V_104 : V_105 ) ;
F_18 ( & V_11 , V_87 -> V_101 -> V_102 ,
V_87 -> V_101 -> V_106 , 0 , V_90 ) ;
V_89 = F_19 ( V_87 -> V_96 ) ;
V_12 = F_4 ( V_89 -> V_7 , & V_11 ) ;
if ( V_12 )
F_5 ( V_89 -> V_107 -> V_37 ,
L_8 , V_12 ) ;
V_87 -> V_92 =
V_91 ? V_108 : V_109 ;
return V_12 ;
}
static int F_20 ( struct V_86 * V_87 )
{
int V_12 , V_102 , V_66 , V_110 ;
struct V_88 * V_89 ;
struct V_10 V_11 ;
unsigned int V_111 ;
switch ( V_87 -> V_112 ) {
case V_113 :
V_111 = V_114 ;
break;
case V_115 :
V_111 = V_114 |
V_116 | V_117 ;
break;
case V_118 :
V_111 = V_114 | V_116 ;
break;
case V_119 :
V_111 = V_114 |
V_120 | V_117 ;
break;
case V_121 :
V_111 = V_114 | V_120 ;
break;
case V_122 :
V_111 = V_123 | V_117 ;
break;
default:
F_17 ( V_95
L_9 ) ;
return - V_5 ;
}
V_89 = F_19 ( V_87 -> V_96 ) ;
V_66 = V_89 -> V_7 -> V_66 ;
if ( V_66 <= 32000 && V_66 != 0 ) {
if ( V_66 <= 11025 )
V_111 |= V_124 ;
else
V_111 |= V_125 ;
}
if ( V_87 -> V_126 == 1 )
V_111 |= V_127 ;
V_102 = V_87 -> V_101 -> V_102 ;
V_110 = V_102 ? 0 : V_87 -> V_96 -> V_103 ;
F_3 ( & V_11 , V_102 ?
V_128 : V_129 ) ;
F_18 ( & V_11 , V_102 , V_87 -> V_101 -> V_106 ,
V_110 , 0 ) ;
if ( V_102 ) {
if ( F_7 ( V_89 -> V_7 ) )
V_11 . V_32 [ 0 ] |= 1 << 10 ;
else
V_11 . V_32 [ 0 ] |= 1 << 12 ;
}
V_11 . V_32 [ 1 ] = 0 ;
V_11 . V_35 = 2 ;
if ( F_7 ( V_89 -> V_7 ) ) {
V_11 . V_32 [ 1 ] = V_87 -> V_126 ;
if ( ! V_102 ) {
V_11 . V_32 [ 2 ] = ( V_87 -> V_126 == 1 ) ? 0x01 : 0x03 ;
V_11 . V_35 = 3 ;
}
}
V_11 . V_32 [ V_11 . V_35 ++ ] = V_111 >> 8 ;
V_11 . V_32 [ V_11 . V_35 ++ ] = ( V_111 & 0xff ) << 16 ;
V_12 = F_4 ( V_89 -> V_7 , & V_11 ) ;
if ( V_12 )
F_5 ( V_89 -> V_107 -> V_37 ,
L_10 , V_12 ) ;
return V_12 ;
}
static int F_21 ( struct V_86 * V_87 )
{
int V_12 , V_102 , V_110 ;
struct V_10 V_11 ;
struct V_130 * V_131 = V_87 -> V_96 ;
struct V_88 * V_89 = F_19 ( V_131 ) ;
V_102 = ( V_131 -> V_87 == V_132 ) ;
V_110 = V_102 ? 0 : V_131 -> V_103 ;
F_22 ( L_11
L_12 ,
V_102 ? 'c' : 'p' ,
V_89 -> V_133 , ( void * ) ( long ) V_131 -> V_134 -> V_135 ,
V_131 -> V_134 -> V_136 , V_131 -> V_103 ) ;
F_3 ( & V_11 , V_137 ) ;
F_18 ( & V_11 , V_102 , V_87 -> V_101 -> V_106 ,
V_110 , 0 ) ;
F_23 ( V_131 -> V_134 -> V_136 >= 0x200000 ) ;
V_11 . V_32 [ 1 ] = V_131 -> V_134 -> V_136 * 8 ;
V_11 . V_32 [ 2 ] = V_131 -> V_134 -> V_135 >> 24 ;
V_11 . V_32 [ 2 ] |= 1 << 19 ;
V_11 . V_32 [ 3 ] = V_131 -> V_134 -> V_135 & V_34 ;
V_11 . V_35 = 4 ;
V_12 = F_4 ( V_89 -> V_7 , & V_11 ) ;
if ( V_12 )
F_5 ( V_89 -> V_107 -> V_37 ,
L_13 , V_12 ) ;
return V_12 ;
}
static inline int F_24 ( struct V_86 * V_87 ,
struct V_138 * * V_101 )
{
if ( V_87 -> V_92 == V_93 ) {
* V_101 = V_87 -> V_101 ;
return 1 ;
}
return 0 ;
}
static void F_25 ( unsigned long V_139 )
{
unsigned long V_140 ;
int V_141 , V_142 , V_12 ;
struct V_138 * V_101 ;
struct V_88 * V_89 ;
struct V_6 * V_7 = (struct V_6 * ) ( V_139 ) ;
int V_143 = 0 ;
int V_144 = 0 ;
#ifdef F_26
struct V_145 V_146 , V_147 ;
F_27 ( & V_146 ) ;
#endif
F_28 ( & V_7 -> V_148 ) ;
for ( V_141 = 0 ; V_141 < V_7 -> V_149 ; V_141 ++ ) {
V_89 = V_7 -> V_89 [ V_141 ] ;
for ( V_142 = 0 ; V_142 < V_89 -> V_150 ; V_142 ++ ) {
if ( F_24 ( & V_89 -> V_151 [ V_142 ] , & V_101 ) )
V_143 |= ( 1 << V_101 -> V_106 ) ;
}
for ( V_142 = 0 ; V_142 < V_89 -> V_152 ; V_142 ++ ) {
if ( F_24 ( & V_89 -> V_153 [ V_142 ] , & V_101 ) ) {
V_144 |= ( 1 << V_101 -> V_106 ) ;
break;
}
}
}
if ( V_143 == 0 && V_144 == 0 ) {
F_29 ( & V_7 -> V_148 ) ;
F_5 ( & V_7 -> V_36 -> V_37 , L_14 ) ;
return;
}
F_8 ( & V_7 -> V_36 -> V_37 , L_15
L_16 ,
V_144 , V_143 ) ;
V_12 = F_30 ( V_7 , V_144 , V_143 , 0 ) ;
if ( V_12 ) {
F_29 ( & V_7 -> V_148 ) ;
F_5 ( & V_7 -> V_36 -> V_37 , L_15
L_17 ,
V_144 , V_143 ) ;
return;
}
for ( V_141 = 0 ; V_141 < V_7 -> V_149 ; V_141 ++ ) {
struct V_86 * V_87 ;
V_89 = V_7 -> V_89 [ V_141 ] ;
for ( V_142 = 0 ; V_142 < V_89 -> V_150 ; V_142 ++ ) {
V_87 = & V_89 -> V_151 [ V_142 ] ;
if ( F_24 ( V_87 , & V_101 ) ) {
V_12 = F_20 ( V_87 ) ;
V_12 = F_21 ( V_87 ) ;
}
}
for ( V_142 = 0 ; V_142 < V_89 -> V_152 ; V_142 ++ ) {
V_87 = & V_89 -> V_153 [ V_142 ] ;
if ( F_24 ( V_87 , & V_101 ) ) {
V_12 = F_20 ( V_87 ) ;
V_12 = F_21 ( V_87 ) ;
}
}
}
for ( V_141 = 0 ; V_141 < V_7 -> V_149 ; V_141 ++ ) {
struct V_86 * V_87 ;
V_89 = V_7 -> V_89 [ V_141 ] ;
for ( V_142 = 0 ; V_142 < V_89 -> V_150 ; V_142 ++ ) {
V_87 = & V_89 -> V_151 [ V_142 ] ;
if ( F_24 ( V_87 , & V_101 ) )
V_12 = F_16 ( V_87 ) ;
}
for ( V_142 = 0 ; V_142 < V_89 -> V_152 ; V_142 ++ ) {
V_87 = & V_89 -> V_153 [ V_142 ] ;
if ( F_24 ( V_87 , & V_101 ) )
V_12 = F_16 ( V_87 ) ;
}
}
V_12 = F_30 ( V_7 , V_144 , V_143 , 1 ) ;
if ( V_12 ) {
F_29 ( & V_7 -> V_148 ) ;
F_5 ( & V_7 -> V_36 -> V_37 , L_15
L_18 ,
V_144 , V_143 ) ;
return;
}
F_31 ( & V_7 -> V_154 , V_140 ) ;
for ( V_141 = 0 ; V_141 < V_7 -> V_149 ; V_141 ++ ) {
struct V_86 * V_87 ;
V_89 = V_7 -> V_89 [ V_141 ] ;
for( V_142 = 0 ; V_142 < V_89 -> V_150 ; V_142 ++ ) {
V_87 = & V_89 -> V_151 [ V_142 ] ;
if( V_87 -> V_92 == V_108 )
V_87 -> V_92 = V_155 ;
}
for ( V_142 = 0 ; V_142 < V_89 -> V_152 ; V_142 ++ ) {
V_87 = & V_89 -> V_153 [ V_142 ] ;
if ( V_87 -> V_92 == V_108 ) {
V_87 -> V_98 += V_7 -> V_156 ;
V_87 -> V_92 = V_155 ;
}
}
}
F_32 ( & V_7 -> V_154 , V_140 ) ;
F_29 ( & V_7 -> V_148 ) ;
#ifdef F_26
F_27 ( & V_147 ) ;
F_8 ( & V_7 -> V_36 -> V_37 , L_19 ,
( long ) ( V_147 . V_157 - V_146 . V_157 ) , V_12 ) ;
#endif
}
static int F_33 ( struct V_130 * V_131 , int V_32 )
{
struct V_86 * V_87 ;
struct V_130 * V_158 ;
switch ( V_32 ) {
case V_159 :
F_22 ( L_20 ) ;
if ( F_34 ( V_131 ) ) {
struct V_88 * V_89 = F_19 ( V_131 ) ;
F_35 (s, subs) {
if ( F_19 ( V_158 ) != V_89 )
continue;
V_87 = V_158 -> V_134 -> V_160 ;
V_87 -> V_92 =
V_93 ;
F_36 ( V_158 , V_131 ) ;
}
F_37 ( & V_89 -> V_7 -> V_161 ) ;
} else {
V_87 = V_131 -> V_134 -> V_160 ;
F_22 ( L_21 ,
V_87 -> V_101 -> V_102 ? 'C' : 'P' ,
V_87 -> V_101 -> V_106 ) ;
if ( F_20 ( V_87 ) )
return - V_5 ;
if ( F_21 ( V_87 ) )
return - V_5 ;
V_87 -> V_92 = V_93 ;
if ( F_16 ( V_87 ) )
return - V_5 ;
V_87 -> V_92 = V_155 ;
}
break;
case V_162 :
F_22 ( L_22 ) ;
F_35 (s, subs) {
V_87 = V_158 -> V_134 -> V_160 ;
V_87 -> V_92 = V_94 ;
if ( F_16 ( V_87 ) )
return - V_5 ;
F_36 ( V_158 , V_131 ) ;
}
break;
case V_163 :
case V_164 :
default:
return - V_5 ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , int V_91 )
{
struct V_10 V_11 ;
int V_12 ;
F_3 ( & V_11 , V_165 ) ;
if ( V_91 ) {
V_7 -> V_166 = V_167 ;
V_11 . V_32 [ 0 ] |= V_7 -> V_156 ;
}
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 < 0 )
F_5 ( & V_7 -> V_36 -> V_37 , L_23 ,
V_12 ) ;
return V_12 ;
}
static int F_39 ( struct V_130 * V_131 )
{
struct V_88 * V_89 = F_19 ( V_131 ) ;
struct V_6 * V_7 = V_89 -> V_7 ;
int V_12 = 0 ;
F_8 ( V_89 -> V_107 -> V_37 ,
L_24 ,
V_131 -> V_134 -> V_168 , V_131 -> V_134 -> V_169 ,
V_131 -> V_134 -> V_170 ) ;
F_28 ( & V_7 -> V_148 ) ;
do {
if ( V_7 -> V_66 != V_131 -> V_134 -> V_8 ) {
V_12 = F_10 ( V_7 , V_131 -> V_134 -> V_8 ) ;
if ( V_12 )
break;
if ( V_7 -> V_66 == 0 )
V_12 = F_38 ( V_7 , 1 ) ;
V_7 -> V_66 = V_131 -> V_134 -> V_8 ;
}
} while( 0 );
F_29 ( & V_7 -> V_148 ) ;
return V_12 ;
}
static int F_40 ( struct V_130 * V_131 ,
struct V_171 * V_172 )
{
struct V_88 * V_89 = F_19 ( V_131 ) ;
struct V_6 * V_7 = V_89 -> V_7 ;
struct V_86 * V_87 = V_131 -> V_134 -> V_160 ;
T_1 V_112 ;
int V_12 ;
int V_126 ;
V_126 = F_41 ( V_172 ) ;
V_112 = F_42 ( V_172 ) ;
F_28 ( & V_7 -> V_148 ) ;
V_87 -> V_126 = V_126 ;
V_87 -> V_112 = V_112 ;
V_12 = F_43 ( V_131 , F_44 ( V_172 ) ) ;
F_29 ( & V_7 -> V_148 ) ;
return V_12 ;
}
static int F_45 ( struct V_130 * V_131 )
{
F_46 ( V_131 ) ;
return 0 ;
}
static int F_47 ( struct V_130 * V_131 )
{
struct V_88 * V_89 = F_19 ( V_131 ) ;
struct V_6 * V_7 = V_89 -> V_7 ;
struct V_173 * V_134 = V_131 -> V_134 ;
struct V_86 * V_87 ;
int V_12 ;
F_28 ( & V_7 -> V_148 ) ;
V_134 -> V_172 = V_174 ;
if( V_131 -> V_87 == V_175 ) {
F_8 ( V_89 -> V_107 -> V_37 , L_25 ,
V_89 -> V_133 , V_131 -> V_103 ) ;
V_87 = & V_89 -> V_153 [ V_131 -> V_103 ] ;
} else {
F_8 ( V_89 -> V_107 -> V_37 , L_26 ,
V_89 -> V_133 , V_131 -> V_103 ) ;
if ( V_7 -> V_176 )
V_134 -> V_172 . V_177 = 1 ;
else
V_134 -> V_172 . V_178 = 2 ;
V_87 = & V_89 -> V_151 [ V_131 -> V_103 ] ;
}
if ( V_87 -> V_92 != V_179 ) {
F_5 ( V_89 -> V_107 -> V_37 , L_27 ,
V_89 -> V_133 , V_131 -> V_103 ) ;
F_29 ( & V_7 -> V_148 ) ;
return - V_180 ;
}
if ( V_7 -> V_59 )
V_134 -> V_172 . V_181 &= ~ V_182 ;
V_12 = F_48 ( V_134 ,
V_183 ) ;
if ( V_12 < 0 ) {
F_29 ( & V_7 -> V_148 ) ;
return V_12 ;
}
if ( V_7 -> V_66 )
V_134 -> V_172 . V_184 = V_134 -> V_172 . V_185 = V_7 -> V_66 ;
else {
if ( V_7 -> V_13 != V_14 ) {
int V_186 ;
if ( F_14 ( V_7 , V_7 -> V_13 ,
& V_186 ) ||
V_186 == 0 ) {
F_29 ( & V_7 -> V_148 ) ;
return - V_180 ;
}
V_134 -> V_172 . V_184 = V_186 ;
V_134 -> V_172 . V_185 = V_186 ;
}
}
V_87 -> V_92 = V_187 ;
V_87 -> V_96 = V_131 ;
V_87 -> V_126 = 0 ;
V_134 -> V_160 = V_87 ;
F_49 ( V_134 , 0 ,
V_188 , 32 ) ;
F_49 ( V_134 , 0 ,
V_189 , 32 ) ;
F_50 ( V_131 ) ;
V_7 -> V_190 ++ ;
F_29 ( & V_7 -> V_148 ) ;
return 0 ;
}
static int F_51 ( struct V_130 * V_131 )
{
struct V_88 * V_89 = F_19 ( V_131 ) ;
struct V_6 * V_7 = V_89 -> V_7 ;
struct V_86 * V_87 = V_131 -> V_134 -> V_160 ;
F_28 ( & V_7 -> V_148 ) ;
F_8 ( V_89 -> V_107 -> V_37 , L_28 ,
V_89 -> V_133 , V_131 -> V_103 ) ;
if ( -- V_7 -> V_190 == 0 ) {
V_7 -> V_66 = 0 ;
F_38 ( V_7 , 0 ) ;
}
V_87 -> V_92 = V_179 ;
V_87 -> V_96 = NULL ;
F_29 ( & V_7 -> V_148 ) ;
return 0 ;
}
static T_2 F_52 ( struct V_130 * V_131 )
{
unsigned long V_140 ;
T_3 V_98 ;
int V_99 ;
struct V_88 * V_89 = F_19 ( V_131 ) ;
struct V_173 * V_134 = V_131 -> V_134 ;
struct V_86 * V_87 = V_134 -> V_160 ;
F_31 ( & V_89 -> V_7 -> V_154 , V_140 ) ;
V_98 = V_87 -> V_98 ;
V_99 = V_87 -> V_99 ;
F_32 ( & V_89 -> V_7 -> V_154 , V_140 ) ;
return ( T_2 ) ( ( V_99 * V_134 -> V_168 ) +
V_98 ) ;
}
int F_53 ( struct V_88 * V_89 )
{
int V_12 ;
struct V_191 * V_192 ;
char V_193 [ 32 ] ;
sprintf ( V_193 , L_29 , V_89 -> V_133 ) ;
if ( ( V_12 = F_54 ( V_89 -> V_107 , V_193 , 0 ,
V_89 -> V_152 ,
V_89 -> V_150 , & V_192 ) ) < 0 ) {
F_5 ( V_89 -> V_107 -> V_37 , L_30 , V_193 ) ;
return V_12 ;
}
V_192 -> V_160 = V_89 ;
if ( V_89 -> V_152 )
F_55 ( V_192 , V_175 , & V_194 ) ;
if ( V_89 -> V_150 )
F_55 ( V_192 , V_132 , & V_194 ) ;
V_192 -> V_195 = 0 ;
strcpy ( V_192 -> V_193 , V_193 ) ;
F_56 ( V_192 , V_196 ,
F_57 ( V_89 -> V_7 -> V_36 ) ,
32 * 1024 , 32 * 1024 ) ;
V_89 -> V_192 = V_192 ;
return 0 ;
}
static int F_58 ( struct V_88 * V_89 )
{
F_59 ( V_89 ) ;
return 0 ;
}
static int F_60 ( struct V_197 * V_198 )
{
struct V_88 * V_89 = V_198 -> V_199 ;
return F_58 ( V_89 ) ;
}
static int F_61 ( struct V_6 * V_7 ,
struct V_200 * V_107 , int V_201 )
{
int V_12 ;
struct V_88 * V_89 ;
static struct V_202 V_203 = {
. V_204 = F_60 ,
} ;
V_89 = F_62 ( sizeof( * V_89 ) , V_205 ) ;
if ( ! V_89 ) {
F_5 ( V_107 -> V_37 , L_31 ) ;
return - V_206 ;
}
V_89 -> V_107 = V_107 ;
V_89 -> V_133 = V_201 ;
V_89 -> V_7 = V_7 ;
if ( V_201 < V_7 -> V_207 )
V_89 -> V_152 = V_208 ;
if ( V_201 < V_7 -> V_209 ) {
if ( V_7 -> V_176 )
V_89 -> V_150 = 2 ;
else
V_89 -> V_150 = 1 ;
}
if ( ( V_12 = F_63 ( V_107 , V_210 , V_89 , & V_203 ) ) < 0 ) {
F_58 ( V_89 ) ;
return V_12 ;
}
V_7 -> V_89 [ V_201 ] = V_89 ;
return 0 ;
}
static void F_64 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_88 * V_89 = V_212 -> V_160 ;
struct V_6 * V_7 = V_89 -> V_7 ;
F_65 ( V_214 , L_32 , V_7 -> V_215 ) ;
if ( V_7 -> V_216 & ( 1 << V_217 ) ) {
struct V_10 V_11 ;
short V_218 = ( V_7 -> V_219 >> 16 ) & 0xff ;
short V_220 = ( V_7 -> V_219 >> 8 ) & 0xff ;
short V_221 = V_7 -> V_219 & 0xff ;
F_65 ( V_214 , L_33 ,
V_222 ) ;
F_65 ( V_214 , L_34 ,
V_218 , V_220 , V_221 ) ;
if ( V_7 -> V_223 )
F_65 ( V_214 , L_35 ) ;
else
F_65 ( V_214 , L_36 ) ;
F_3 ( & V_11 , V_224 ) ;
if( ! F_4 ( V_7 , & V_11 ) ) {
int V_225 = V_11 . V_76 [ 0 ] ;
int V_226 = V_11 . V_76 [ 1 ] ;
if ( V_226 > 0 ) {
if ( V_7 -> V_56 != 0 &&
V_7 -> V_56 != 48000 ) {
V_226 = ( V_226 * 48000 ) /
V_7 -> V_56 ;
if ( V_7 -> V_56 >=
V_62 )
V_226 *= 2 ;
}
V_225 = 100 - ( 100 * V_225 ) / V_226 ;
F_65 ( V_214 , L_37 , V_225 ) ;
F_65 ( V_214 , L_38 ,
V_11 . V_76 [ 2 ] , V_11 . V_76 [ 3 ] ) ;
}
}
F_65 ( V_214 , L_39 ,
V_7 -> V_156 ) ;
F_65 ( V_214 , L_40 ,
V_7 -> V_227 ) ;
F_65 ( V_214 , L_41 ,
V_7 -> V_228 ) ;
F_65 ( V_214 , L_42 ,
V_7 -> V_229 ) ;
F_65 ( V_214 , L_43 ,
V_7 -> V_230 ) ;
V_11 . V_32 [ 0 ] = 0x4200 + V_231 ;
V_11 . V_35 = 1 ;
V_11 . V_232 = V_231 ;
V_11 . V_233 = 0 ;
V_11 . V_234 = V_235 ;
if( ! F_4 ( V_7 , & V_11 ) ) {
int V_141 ;
if ( V_11 . V_232 > 8 )
V_11 . V_232 = 8 ;
for ( V_141 = 0 ; V_141 < V_11 . V_232 ; V_141 ++ )
F_65 ( V_214 , L_44 ,
V_141 , V_11 . V_76 [ V_141 ] ) ;
}
} else
F_65 ( V_214 , L_45 ) ;
F_65 ( V_214 , L_46 ) ;
}
static void F_66 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_88 * V_89 = V_212 -> V_160 ;
struct V_6 * V_7 = V_89 -> V_7 ;
static const char * V_236 [ 3 ] = {
L_47 , L_48 , L_49
} ;
static const char * V_237 [ 7 ] = {
L_47 , L_50 , L_48 ,
L_49 , L_51 , L_52 , L_53
} ;
const char * * V_238 ;
int V_239 ;
if ( V_7 -> V_59 ) {
V_238 = V_236 ;
V_239 = V_240 ;
} else {
V_238 = V_237 ;
V_239 = V_241 ;
}
F_65 ( V_214 , L_32 , V_7 -> V_215 ) ;
F_65 ( V_214 , L_54 ,
V_238 [ V_7 -> V_57 ] ) ;
F_65 ( V_214 , L_55 ,
V_7 -> V_56 ) ;
if ( V_7 -> V_216 & ( 1 << V_217 ) ) {
int V_141 , V_12 , V_66 ;
for ( V_141 = 1 ; V_141 <= V_239 ; V_141 ++ ) {
V_12 = F_14 ( V_7 , V_141 , & V_66 ) ;
if ( V_12 )
break;
F_65 ( V_214 , L_56 ,
V_238 [ V_141 ] , V_66 ) ;
}
} else
F_65 ( V_214 , L_45 ) ;
F_65 ( V_214 , L_46 ) ;
}
static void F_67 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_88 * V_89 = V_212 -> V_160 ;
struct V_6 * V_7 = V_89 -> V_7 ;
if ( V_7 -> V_216 & ( 1 << V_217 ) ) {
int V_242 = 0 ;
F_68 ( V_7 , 1 , & V_242 ) ;
F_65 ( V_214 , L_57 , V_242 ) ;
F_68 ( V_7 , 0 , & V_242 ) ;
F_65 ( V_214 , L_58 , V_242 ) ;
} else
F_65 ( V_214 , L_45 ) ;
F_65 ( V_214 , L_46 ) ;
}
static void F_69 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_88 * V_89 = V_212 -> V_160 ;
struct V_6 * V_7 = V_89 -> V_7 ;
char line [ 64 ] ;
int V_242 ;
if ( ! ( V_7 -> V_216 & ( 1 << V_217 ) ) )
return;
while ( ! F_70 ( V_214 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_59 , & V_242 ) != 1 )
continue;
F_71 ( V_7 , V_242 ) ;
}
}
static void F_72 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_88 * V_89 = V_212 -> V_160 ;
struct V_6 * V_7 = V_89 -> V_7 ;
struct V_10 V_11 ;
unsigned int V_243 , V_244 , V_245 , V_246 ;
int V_12 ;
if ( ! ( V_7 -> V_216 & ( 1 << V_217 ) ) ) {
F_65 ( V_214 , L_45 ) ;
return;
}
if ( ! V_7 -> V_247 ) {
F_3 ( & V_11 , V_248 ) ;
V_11 . V_32 [ 0 ] |= V_249 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 ) {
F_65 ( V_214 , L_60 , V_12 ) ;
return;
}
if ( V_7 -> V_59 )
F_73 ( V_7 , 1 ) ;
else
F_9 ( V_7 , V_250 ,
V_250 , NULL ) ;
V_7 -> V_247 = 1 ;
}
F_3 ( & V_11 , V_251 ) ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 ) {
F_65 ( V_214 , L_61 , V_12 ) ;
return ;
}
V_243 = 10 * ( ( V_11 . V_76 [ 0 ] >> 8 ) & 0x3 ) + ( V_11 . V_76 [ 0 ] & 0xf ) ;
V_244 = 10 * ( ( V_11 . V_76 [ 1 ] >> 16 ) & 0x7 ) + ( ( V_11 . V_76 [ 1 ] >> 8 ) & 0xf ) ;
V_245 = 10 * ( V_11 . V_76 [ 1 ] & 0x7 ) + ( ( V_11 . V_76 [ 2 ] >> 16 ) & 0xf ) ;
V_246 = 10 * ( ( V_11 . V_76 [ 2 ] >> 8 ) & 0x3 ) + ( V_11 . V_76 [ 2 ] & 0xf ) ;
F_65 ( V_214 , L_62 ,
V_243 , V_244 , V_245 , V_246 ) ;
F_65 ( V_214 , L_63 , V_11 . V_76 [ 0 ] & 0x00ffff ,
V_11 . V_76 [ 1 ] & 0xffffff , V_11 . V_76 [ 2 ] & 0xffffff ) ;
if ( ! ( V_11 . V_76 [ 0 ] & V_252 ) ) {
F_65 ( V_214 , L_64 ) ;
}
}
static void F_74 ( struct V_88 * V_89 )
{
struct V_211 * V_212 ;
if ( ! F_75 ( V_89 -> V_107 , L_65 , & V_212 ) )
F_76 ( V_212 , V_89 , F_64 ) ;
if ( ! F_75 ( V_89 -> V_107 , L_66 , & V_212 ) )
F_76 ( V_212 , V_89 , F_66 ) ;
if ( V_89 -> V_7 -> V_59 &&
! F_75 ( V_89 -> V_107 , L_67 , & V_212 ) ) {
F_76 ( V_212 , V_89 , F_67 ) ;
V_212 -> V_253 . V_254 . V_255 = F_69 ;
V_212 -> V_256 |= V_257 ;
}
if ( ! F_75 ( V_89 -> V_107 , L_68 , & V_212 ) )
F_76 ( V_212 , V_89 , F_72 ) ;
}
static int F_77 ( struct V_6 * V_7 )
{
unsigned int V_141 ;
for ( V_141 = 0 ; V_141 < V_7 -> V_149 ; V_141 ++ ) {
if ( V_7 -> V_89 [ V_141 ] )
F_78 ( V_7 -> V_89 [ V_141 ] -> V_107 ) ;
}
if( V_7 -> V_216 ) {
F_79 ( V_7 ) ;
F_8 ( & V_7 -> V_36 -> V_37 , L_69 ) ;
}
if ( V_7 -> V_258 >= 0 )
F_80 ( V_7 -> V_258 , V_7 ) ;
F_81 ( V_7 -> V_36 ) ;
if ( V_7 -> V_259 . V_260 ) {
F_82 ( & V_7 -> V_259 ) ;
V_7 -> V_259 . V_260 = NULL ;
}
F_59 ( V_7 -> V_261 ) ;
F_83 ( V_7 -> V_36 ) ;
F_59 ( V_7 ) ;
return 0 ;
}
static int F_84 ( struct V_262 * V_36 ,
const struct V_263 * V_264 )
{
static int V_37 ;
struct V_6 * V_7 ;
unsigned int V_141 ;
int V_12 ;
T_4 V_265 ;
char * V_266 ;
if ( V_37 >= V_267 )
return - V_268 ;
if ( ! V_269 [ V_37 ] ) {
V_37 ++ ;
return - V_270 ;
}
if ( ( V_12 = F_85 ( V_36 ) ) < 0 )
return V_12 ;
F_86 ( V_36 ) ;
if ( F_87 ( V_36 , F_88 ( 32 ) ) < 0 ) {
F_5 ( & V_36 -> V_37 ,
L_70 ) ;
F_83 ( V_36 ) ;
return - V_271 ;
}
V_7 = F_62 ( sizeof( * V_7 ) , V_205 ) ;
if ( ! V_7 ) {
F_83 ( V_36 ) ;
return - V_206 ;
}
if ( F_23 ( V_264 -> V_272 >= V_273 ) ) {
F_59 ( V_7 ) ;
F_83 ( V_36 ) ;
return - V_268 ;
}
V_266 =
V_274 [ V_264 -> V_272 ] . V_275 ;
V_7 -> V_207 =
V_274 [ V_264 -> V_272 ] . V_207 ;
V_7 -> V_209 =
V_274 [ V_264 -> V_272 ] . V_209 ;
V_7 -> V_276 =
V_274 [ V_264 -> V_272 ] . V_276 ;
V_7 -> V_277 =
V_274 [ V_264 -> V_272 ] . V_277 ;
V_7 -> V_176 = V_278 [ V_37 ] ;
V_7 -> V_59 = ( V_7 -> V_207 == 1 ) ;
V_7 -> V_279 = F_89 ( V_7 ) ;
V_7 -> V_280 = ! F_90 ( V_7 ) ;
if ( V_7 -> V_59 )
V_7 -> V_156 = V_281 ;
else
V_7 -> V_156 = V_282 ;
if ( ( V_12 = F_91 ( V_36 , V_266 ) ) < 0 ) {
F_59 ( V_7 ) ;
F_83 ( V_36 ) ;
return V_12 ;
}
for ( V_141 = 0 ; V_141 < 3 ; V_141 ++ )
V_7 -> V_283 [ V_141 ] = F_92 ( V_36 , V_141 ) ;
V_7 -> V_36 = V_36 ;
V_7 -> V_258 = - 1 ;
if ( F_93 ( V_36 -> V_258 , V_284 , V_285 ,
V_286 , V_7 ) ) {
F_5 ( & V_36 -> V_37 , L_71 , V_36 -> V_258 ) ;
F_77 ( V_7 ) ;
return - V_180 ;
}
V_7 -> V_258 = V_36 -> V_258 ;
sprintf ( V_7 -> V_287 , L_72 , V_266 ) ;
sprintf ( V_7 -> V_215 , L_73 ,
V_7 -> V_287 ,
V_7 -> V_283 [ 0 ] , V_7 -> V_283 [ 1 ] , V_7 -> V_283 [ 2 ] , V_7 -> V_258 ) ;
F_94 ( & V_7 -> V_154 ) ;
F_94 ( & V_7 -> V_288 ) ;
F_95 ( & V_7 -> V_148 ) ;
F_96 ( & V_7 -> V_289 , V_290 ,
( unsigned long ) V_7 ) ;
F_96 ( & V_7 -> V_161 , F_25 ,
( unsigned long ) V_7 ) ;
V_7 -> V_261 = F_97 ( sizeof( * V_7 -> V_261 ) +
sizeof( V_291 ) * ( V_292 -
V_231 ) ,
V_205 ) ;
if ( ! V_7 -> V_261 ) {
F_77 ( V_7 ) ;
return - V_206 ;
}
for ( V_141 = 0 ; V_141 < V_293 ; V_141 ++ ) {
struct V_200 * V_107 ;
char V_294 [ 16 ] ;
int V_201 ;
if ( V_141 >= F_98 ( V_7 -> V_207 , V_7 -> V_209 ) )
break;
V_7 -> V_149 ++ ;
if ( V_295 [ V_37 ] < 0 )
V_201 = V_295 [ V_37 ] ;
else
V_201 = V_295 [ V_37 ] + V_141 ;
snprintf ( V_294 , sizeof( V_294 ) , L_74 ,
V_296 [ V_37 ] ? V_296 [ V_37 ] : V_266 , V_141 ) ;
V_12 = F_99 ( & V_36 -> V_37 , V_201 , V_294 , V_297 ,
0 , & V_107 ) ;
if ( V_12 < 0 ) {
F_5 ( V_107 -> V_37 , L_75 , V_141 ) ;
F_77 ( V_7 ) ;
return V_12 ;
}
strcpy ( V_107 -> V_298 , V_299 ) ;
sprintf ( V_107 -> V_287 , L_76 , V_7 -> V_287 , V_141 ) ;
sprintf ( V_107 -> V_215 , L_76 , V_7 -> V_215 , V_141 ) ;
if ( ( V_12 = F_61 ( V_7 , V_107 , V_141 ) ) < 0 ) {
F_78 ( V_107 ) ;
F_77 ( V_7 ) ;
return V_12 ;
}
if ( V_141 == 0 )
F_74 ( V_7 -> V_89 [ V_141 ] ) ;
if ( ( V_12 = F_100 ( V_107 ) ) < 0 ) {
F_77 ( V_7 ) ;
return V_12 ;
}
}
V_265 = F_101 ( sizeof( struct V_300 ) ) ;
if ( F_102 ( V_196 , F_57 ( V_36 ) ,
V_265 , & V_7 -> V_259 ) < 0 ) {
F_77 ( V_7 ) ;
return - V_206 ;
}
memset ( V_7 -> V_259 . V_260 , 0 , V_265 ) ;
V_12 = F_103 ( V_7 ) ;
if ( V_12 < 0 ) {
F_77 ( V_7 ) ;
return V_12 ;
}
F_104 ( V_36 , V_7 ) ;
V_37 ++ ;
return 0 ;
}
static void F_105 ( struct V_262 * V_36 )
{
F_77 ( F_106 ( V_36 ) ) ;
}
