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
F_5 ( V_36
L_1
L_2 , V_12 ) ;
return V_12 ;
}
}
break;
case V_37 :
V_9 = V_38 ;
break;
case V_39 :
V_9 = V_40 ;
break;
case V_41 :
V_9 = V_42 ;
break;
case V_43 :
V_9 = V_44 ;
break;
case V_45 :
V_9 = V_46 ;
break;
case V_47 :
V_9 = V_48 ;
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
int * V_49 )
{
unsigned int V_9 , V_3 , V_50 ;
struct V_10 V_11 ;
int V_12 ;
V_12 = F_2 ( V_7 , V_8 , & V_9 , & V_3 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 < 55000 )
V_50 = 0 ;
else if ( V_8 < 100000 )
V_50 = 1 ;
else
V_50 = 2 ;
if ( V_7 -> V_51 != V_50 ) {
F_3 ( & V_11 , V_31 ) ;
V_11 . V_32 [ 0 ] |= V_52 ;
if ( F_7 ( V_7 ) ) {
V_11 . V_32 [ 1 ] = 1 ;
V_11 . V_35 = 2 ;
}
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
F_3 ( & V_11 , V_31 ) ;
V_11 . V_32 [ 0 ] |= V_53 ;
V_11 . V_32 [ 1 ] = V_50 ;
V_11 . V_35 = 2 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
}
F_8 ( L_3 , V_9 ) ;
V_12 = F_9 ( V_7 , V_54 ,
V_9 , V_49 ) ;
if ( V_12 )
return V_12 ;
V_7 -> V_55 = V_3 ;
V_7 -> V_56 = V_7 -> V_13 ;
if ( V_7 -> V_51 != V_50 ) {
F_3 ( & V_11 , V_57 ) ;
V_11 . V_32 [ 0 ] |= V_52 ;
if ( F_7 ( V_7 ) ) {
V_11 . V_32 [ 1 ] = 1 ;
V_11 . V_35 = 2 ;
}
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
V_7 -> V_51 = V_50 ;
}
F_8 ( L_4 ,
V_8 , V_3 ) ;
return 0 ;
}
int F_10 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_10 V_11 ;
int V_12 , V_49 ;
if ( V_8 == 0 )
return 0 ;
if ( V_7 -> V_58 )
V_12 = F_11 ( V_7 , V_8 , & V_49 ) ;
else
V_12 = F_6 ( V_7 , V_8 , & V_49 ) ;
if ( V_12 )
return V_12 ;
if ( V_49 ) {
F_3 ( & V_11 , V_59 ) ;
V_11 . V_32 [ 0 ] |= V_60 ;
if ( V_8 < V_61 )
V_11 . V_32 [ 1 ] = V_62 ;
else
V_11 . V_32 [ 1 ] = V_62 * 2 ;
V_11 . V_32 [ 2 ] = V_8 ;
V_11 . V_35 = 3 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
enum V_63 V_64 ,
int * V_65 )
{
struct V_10 V_11 ;
unsigned char V_4 ;
int V_12 , V_8 ;
switch ( V_64 ) {
case V_37 :
V_4 = V_66 ;
break;
case V_39 :
V_4 = V_67 ;
break;
case V_41 :
V_4 = V_68 ;
break;
case V_43 :
V_4 = V_69 ;
break;
case V_45 :
V_4 = V_70 ;
break;
case V_47 :
V_4 = V_71 ;
break;
default:
return - V_5 ;
}
F_3 ( & V_11 , V_57 ) ;
V_11 . V_35 = 2 ;
V_11 . V_32 [ 0 ] |= V_72 ;
if ( V_7 -> V_73 != V_4 ) {
V_11 . V_32 [ 1 ] = V_4 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
F_13 ( 100 ) ;
V_7 -> V_73 = V_4 ;
}
V_11 . V_32 [ 1 ] = V_74 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 )
return V_12 ;
switch ( V_11 . V_75 [ 1 ] & 0x0f ) {
case V_76 : V_8 = 32000 ; break;
case V_77 : V_8 = 44100 ; break;
case V_78 : V_8 = 48000 ; break;
case V_79 : V_8 = 64000 ; break;
case V_80 : V_8 = 88200 ; break;
case V_81 : V_8 = 96000 ; break;
case V_82 : V_8 = 128000 ; break;
case V_83 : V_8 = 176400 ; break;
case V_84 : V_8 = 192000 ; break;
default: V_8 = 0 ;
}
F_8 ( L_5 , V_8 ) ;
* V_65 = V_8 ;
return 0 ;
}
int F_14 ( struct V_6 * V_7 ,
enum V_63 V_64 ,
int * V_65 )
{
if ( V_7 -> V_58 )
return F_15 ( V_7 , V_64 ,
V_65 ) ;
else
return F_12 ( V_7 , V_64 ,
V_65 ) ;
}
static int F_16 ( struct V_85 * V_86 )
{
int V_12 ;
struct V_87 * V_88 ;
struct V_10 V_11 ;
int V_89 , V_90 ;
if ( V_86 -> V_91 == V_92 )
V_90 = 1 ;
else {
if ( V_86 -> V_91 != V_93 ) {
F_5 ( V_36 L_6
L_7 ) ;
return - V_5 ;
}
V_90 = 0 ;
}
if ( ! V_86 -> V_94 )
return - V_5 ;
V_86 -> V_95 = 0 ;
V_86 -> V_96 = 0 ;
V_86 -> V_97 = 0 ;
V_86 -> V_98 = 0 ;
V_89 =
V_86 -> V_99 -> V_100 ? 1 : 1 << V_86 -> V_94 -> V_101 ;
F_3 ( & V_11 , V_90 ? V_102 : V_103 ) ;
F_17 ( & V_11 , V_86 -> V_99 -> V_100 ,
V_86 -> V_99 -> V_104 , 0 , V_89 ) ;
V_88 = F_18 ( V_86 -> V_94 ) ;
V_12 = F_4 ( V_88 -> V_7 , & V_11 ) ;
if ( V_12 )
F_5 ( V_36 L_8 ,
V_12 ) ;
V_86 -> V_91 =
V_90 ? V_105 : V_106 ;
return V_12 ;
}
static int F_19 ( struct V_85 * V_86 )
{
int V_12 , V_100 , V_65 , V_107 ;
struct V_87 * V_88 ;
struct V_10 V_11 ;
unsigned int V_108 ;
switch ( V_86 -> V_109 ) {
case V_110 :
V_108 = V_111 ;
break;
case V_112 :
V_108 = V_111 |
V_113 | V_114 ;
break;
case V_115 :
V_108 = V_111 | V_113 ;
break;
case V_116 :
V_108 = V_111 |
V_117 | V_114 ;
break;
case V_118 :
V_108 = V_111 | V_117 ;
break;
case V_119 :
V_108 = V_120 | V_114 ;
break;
default:
F_5 ( V_36
L_9 ) ;
return - V_5 ;
}
V_88 = F_18 ( V_86 -> V_94 ) ;
V_65 = V_88 -> V_7 -> V_65 ;
if ( V_65 <= 32000 && V_65 != 0 ) {
if ( V_65 <= 11025 )
V_108 |= V_121 ;
else
V_108 |= V_122 ;
}
if ( V_86 -> V_123 == 1 )
V_108 |= V_124 ;
V_100 = V_86 -> V_99 -> V_100 ;
V_107 = V_100 ? 0 : V_86 -> V_94 -> V_101 ;
F_3 ( & V_11 , V_100 ?
V_125 : V_126 ) ;
F_17 ( & V_11 , V_100 , V_86 -> V_99 -> V_104 ,
V_107 , 0 ) ;
if ( V_100 ) {
if ( F_7 ( V_88 -> V_7 ) )
V_11 . V_32 [ 0 ] |= 1 << 10 ;
else
V_11 . V_32 [ 0 ] |= 1 << 12 ;
}
V_11 . V_32 [ 1 ] = 0 ;
V_11 . V_35 = 2 ;
if ( F_7 ( V_88 -> V_7 ) ) {
V_11 . V_32 [ 1 ] = V_86 -> V_123 ;
if ( ! V_100 ) {
V_11 . V_32 [ 2 ] = ( V_86 -> V_123 == 1 ) ? 0x01 : 0x03 ;
V_11 . V_35 = 3 ;
}
}
V_11 . V_32 [ V_11 . V_35 ++ ] = V_108 >> 8 ;
V_11 . V_32 [ V_11 . V_35 ++ ] = ( V_108 & 0xff ) << 16 ;
V_12 = F_4 ( V_88 -> V_7 , & V_11 ) ;
if ( V_12 )
F_5 ( V_36 L_10 , V_12 ) ;
return V_12 ;
}
static int F_20 ( struct V_85 * V_86 )
{
int V_12 , V_100 , V_107 ;
struct V_10 V_11 ;
struct V_127 * V_128 = V_86 -> V_94 ;
struct V_87 * V_88 = F_18 ( V_128 ) ;
V_100 = ( V_128 -> V_86 == V_129 ) ;
V_107 = V_100 ? 0 : V_128 -> V_101 ;
F_8 ( L_11
L_12 ,
V_100 ? 'c' : 'p' ,
V_88 -> V_130 , ( void * ) ( long ) V_128 -> V_131 -> V_132 ,
V_128 -> V_131 -> V_133 , V_128 -> V_101 ) ;
F_3 ( & V_11 , V_134 ) ;
F_17 ( & V_11 , V_100 , V_86 -> V_99 -> V_104 ,
V_107 , 0 ) ;
F_21 ( V_128 -> V_131 -> V_133 >= 0x200000 ) ;
V_11 . V_32 [ 1 ] = V_128 -> V_131 -> V_133 * 8 ;
V_11 . V_32 [ 2 ] = V_128 -> V_131 -> V_132 >> 24 ;
V_11 . V_32 [ 2 ] |= 1 << 19 ;
V_11 . V_32 [ 3 ] = V_128 -> V_131 -> V_132 & V_34 ;
V_11 . V_35 = 4 ;
V_12 = F_4 ( V_88 -> V_7 , & V_11 ) ;
if ( V_12 )
F_5 ( V_36
L_13 , V_12 ) ;
return V_12 ;
}
static inline int F_22 ( struct V_85 * V_86 ,
struct V_135 * * V_99 )
{
if ( V_86 -> V_91 == V_92 ) {
* V_99 = V_86 -> V_99 ;
return 1 ;
}
return 0 ;
}
static void F_23 ( unsigned long V_136 )
{
unsigned long V_137 ;
int V_138 , V_139 , V_12 ;
struct V_135 * V_99 ;
struct V_87 * V_88 ;
struct V_6 * V_7 = (struct V_6 * ) ( V_136 ) ;
int V_140 = 0 ;
int V_141 = 0 ;
#ifdef F_24
struct V_142 V_143 , V_144 ;
F_25 ( & V_143 ) ;
#endif
F_26 ( & V_7 -> V_145 ) ;
for ( V_138 = 0 ; V_138 < V_7 -> V_146 ; V_138 ++ ) {
V_88 = V_7 -> V_88 [ V_138 ] ;
for ( V_139 = 0 ; V_139 < V_88 -> V_147 ; V_139 ++ ) {
if ( F_22 ( & V_88 -> V_148 [ V_139 ] , & V_99 ) )
V_140 |= ( 1 << V_99 -> V_104 ) ;
}
for ( V_139 = 0 ; V_139 < V_88 -> V_149 ; V_139 ++ ) {
if ( F_22 ( & V_88 -> V_150 [ V_139 ] , & V_99 ) ) {
V_141 |= ( 1 << V_99 -> V_104 ) ;
break;
}
}
}
if ( V_140 == 0 && V_141 == 0 ) {
F_27 ( & V_7 -> V_145 ) ;
F_5 ( V_36 L_14 ) ;
return;
}
F_8 ( L_15
L_16 ,
V_141 , V_140 ) ;
V_12 = F_28 ( V_7 , V_141 , V_140 , 0 ) ;
if ( V_12 ) {
F_27 ( & V_7 -> V_145 ) ;
F_5 ( V_36 L_15
L_17 ,
V_141 , V_140 ) ;
return;
}
for ( V_138 = 0 ; V_138 < V_7 -> V_146 ; V_138 ++ ) {
struct V_85 * V_86 ;
V_88 = V_7 -> V_88 [ V_138 ] ;
for ( V_139 = 0 ; V_139 < V_88 -> V_147 ; V_139 ++ ) {
V_86 = & V_88 -> V_148 [ V_139 ] ;
if ( F_22 ( V_86 , & V_99 ) ) {
V_12 = F_19 ( V_86 ) ;
V_12 = F_20 ( V_86 ) ;
}
}
for ( V_139 = 0 ; V_139 < V_88 -> V_149 ; V_139 ++ ) {
V_86 = & V_88 -> V_150 [ V_139 ] ;
if ( F_22 ( V_86 , & V_99 ) ) {
V_12 = F_19 ( V_86 ) ;
V_12 = F_20 ( V_86 ) ;
}
}
}
for ( V_138 = 0 ; V_138 < V_7 -> V_146 ; V_138 ++ ) {
struct V_85 * V_86 ;
V_88 = V_7 -> V_88 [ V_138 ] ;
for ( V_139 = 0 ; V_139 < V_88 -> V_147 ; V_139 ++ ) {
V_86 = & V_88 -> V_148 [ V_139 ] ;
if ( F_22 ( V_86 , & V_99 ) )
V_12 = F_16 ( V_86 ) ;
}
for ( V_139 = 0 ; V_139 < V_88 -> V_149 ; V_139 ++ ) {
V_86 = & V_88 -> V_150 [ V_139 ] ;
if ( F_22 ( V_86 , & V_99 ) )
V_12 = F_16 ( V_86 ) ;
}
}
V_12 = F_28 ( V_7 , V_141 , V_140 , 1 ) ;
if ( V_12 ) {
F_27 ( & V_7 -> V_145 ) ;
F_5 ( V_36 L_15
L_18 ,
V_141 , V_140 ) ;
return;
}
F_29 ( & V_7 -> V_151 , V_137 ) ;
for ( V_138 = 0 ; V_138 < V_7 -> V_146 ; V_138 ++ ) {
struct V_85 * V_86 ;
V_88 = V_7 -> V_88 [ V_138 ] ;
for( V_139 = 0 ; V_139 < V_88 -> V_147 ; V_139 ++ ) {
V_86 = & V_88 -> V_148 [ V_139 ] ;
if( V_86 -> V_91 == V_105 )
V_86 -> V_91 = V_152 ;
}
for ( V_139 = 0 ; V_139 < V_88 -> V_149 ; V_139 ++ ) {
V_86 = & V_88 -> V_150 [ V_139 ] ;
if ( V_86 -> V_91 == V_105 ) {
V_86 -> V_96 += V_7 -> V_153 ;
V_86 -> V_91 = V_152 ;
}
}
}
F_30 ( & V_7 -> V_151 , V_137 ) ;
F_27 ( & V_7 -> V_145 ) ;
#ifdef F_24
F_25 ( & V_144 ) ;
F_8 ( L_19 ,
( long ) ( V_144 . V_154 - V_143 . V_154 ) , V_12 ) ;
#endif
}
static int F_31 ( struct V_127 * V_128 , int V_32 )
{
struct V_85 * V_86 ;
struct V_127 * V_155 ;
switch ( V_32 ) {
case V_156 :
F_8 ( L_20 ) ;
if ( F_32 ( V_128 ) ) {
struct V_87 * V_88 = F_18 ( V_128 ) ;
F_33 (s, subs) {
if ( F_18 ( V_155 ) != V_88 )
continue;
V_86 = V_155 -> V_131 -> V_157 ;
V_86 -> V_91 =
V_92 ;
F_34 ( V_155 , V_128 ) ;
}
F_35 ( & V_88 -> V_7 -> V_158 ) ;
} else {
V_86 = V_128 -> V_131 -> V_157 ;
F_8 ( L_21 ,
V_86 -> V_99 -> V_100 ? 'C' : 'P' ,
V_86 -> V_99 -> V_104 ) ;
if ( F_19 ( V_86 ) )
return - V_5 ;
if ( F_20 ( V_86 ) )
return - V_5 ;
V_86 -> V_91 = V_92 ;
if ( F_16 ( V_86 ) )
return - V_5 ;
V_86 -> V_91 = V_152 ;
}
break;
case V_159 :
F_8 ( L_22 ) ;
F_33 (s, subs) {
V_86 = V_155 -> V_131 -> V_157 ;
V_86 -> V_91 = V_93 ;
if ( F_16 ( V_86 ) )
return - V_5 ;
F_34 ( V_155 , V_128 ) ;
}
break;
case V_160 :
case V_161 :
default:
return - V_5 ;
}
return 0 ;
}
static int F_36 ( struct V_6 * V_7 , int V_90 )
{
struct V_10 V_11 ;
int V_12 ;
F_3 ( & V_11 , V_162 ) ;
if ( V_90 ) {
V_7 -> V_163 = V_164 ;
V_11 . V_32 [ 0 ] |= V_7 -> V_153 ;
}
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 < 0 )
F_5 ( V_36 L_23 ,
V_12 ) ;
return V_12 ;
}
static int F_37 ( struct V_127 * V_128 )
{
struct V_87 * V_88 = F_18 ( V_128 ) ;
struct V_6 * V_7 = V_88 -> V_7 ;
int V_12 = 0 ;
F_8 ( L_24 ,
V_128 -> V_131 -> V_165 , V_128 -> V_131 -> V_166 ,
V_128 -> V_131 -> V_167 ) ;
F_26 ( & V_7 -> V_145 ) ;
do {
if ( V_7 -> V_65 != V_128 -> V_131 -> V_8 ) {
V_12 = F_10 ( V_7 , V_128 -> V_131 -> V_8 ) ;
if ( V_12 )
break;
if ( V_7 -> V_65 == 0 )
V_12 = F_36 ( V_7 , 1 ) ;
V_7 -> V_65 = V_128 -> V_131 -> V_8 ;
}
} while( 0 );
F_27 ( & V_7 -> V_145 ) ;
return V_12 ;
}
static int F_38 ( struct V_127 * V_128 ,
struct V_168 * V_169 )
{
struct V_87 * V_88 = F_18 ( V_128 ) ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_85 * V_86 = V_128 -> V_131 -> V_157 ;
T_1 V_109 ;
int V_12 ;
int V_123 ;
V_123 = F_39 ( V_169 ) ;
V_109 = F_40 ( V_169 ) ;
F_26 ( & V_7 -> V_145 ) ;
V_86 -> V_123 = V_123 ;
V_86 -> V_109 = V_109 ;
V_12 = F_41 ( V_128 , F_42 ( V_169 ) ) ;
F_27 ( & V_7 -> V_145 ) ;
return V_12 ;
}
static int F_43 ( struct V_127 * V_128 )
{
F_44 ( V_128 ) ;
return 0 ;
}
static int F_45 ( struct V_127 * V_128 )
{
struct V_87 * V_88 = F_18 ( V_128 ) ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_170 * V_131 = V_128 -> V_131 ;
struct V_85 * V_86 ;
int V_12 ;
F_26 ( & V_7 -> V_145 ) ;
V_131 -> V_169 = V_171 ;
if( V_128 -> V_86 == V_172 ) {
F_8 ( L_25 ,
V_88 -> V_130 , V_128 -> V_101 ) ;
V_86 = & V_88 -> V_150 [ V_128 -> V_101 ] ;
} else {
F_8 ( L_26 ,
V_88 -> V_130 , V_128 -> V_101 ) ;
if ( V_7 -> V_173 )
V_131 -> V_169 . V_174 = 1 ;
else
V_131 -> V_169 . V_175 = 2 ;
V_86 = & V_88 -> V_148 [ V_128 -> V_101 ] ;
}
if ( V_86 -> V_91 != V_176 ) {
F_5 ( V_36 L_27 ,
V_88 -> V_130 , V_128 -> V_101 ) ;
F_27 ( & V_7 -> V_145 ) ;
return - V_177 ;
}
if ( V_7 -> V_58 )
V_131 -> V_169 . V_178 &= ~ V_179 ;
V_12 = F_46 ( V_131 ,
V_180 ) ;
if ( V_12 < 0 ) {
F_27 ( & V_7 -> V_145 ) ;
return V_12 ;
}
if ( V_7 -> V_65 )
V_131 -> V_169 . V_181 = V_131 -> V_169 . V_182 = V_7 -> V_65 ;
else {
if ( V_7 -> V_13 != V_14 ) {
int V_183 ;
if ( F_14 ( V_7 , V_7 -> V_13 ,
& V_183 ) ||
V_183 == 0 ) {
F_27 ( & V_7 -> V_145 ) ;
return - V_177 ;
}
V_131 -> V_169 . V_181 = V_183 ;
V_131 -> V_169 . V_182 = V_183 ;
}
}
V_86 -> V_91 = V_184 ;
V_86 -> V_94 = V_128 ;
V_86 -> V_123 = 0 ;
V_131 -> V_157 = V_86 ;
F_47 ( V_131 , 0 ,
V_185 , 32 ) ;
F_47 ( V_131 , 0 ,
V_186 , 32 ) ;
F_48 ( V_128 ) ;
V_7 -> V_187 ++ ;
F_27 ( & V_7 -> V_145 ) ;
return 0 ;
}
static int F_49 ( struct V_127 * V_128 )
{
struct V_87 * V_88 = F_18 ( V_128 ) ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_85 * V_86 = V_128 -> V_131 -> V_157 ;
F_26 ( & V_7 -> V_145 ) ;
F_8 ( L_28 ,
V_88 -> V_130 , V_128 -> V_101 ) ;
if ( -- V_7 -> V_187 == 0 ) {
V_7 -> V_65 = 0 ;
F_36 ( V_7 , 0 ) ;
}
V_86 -> V_91 = V_176 ;
V_86 -> V_94 = NULL ;
F_27 ( & V_7 -> V_145 ) ;
return 0 ;
}
static T_2 F_50 ( struct V_127 * V_128 )
{
unsigned long V_137 ;
T_3 V_96 ;
int V_97 ;
struct V_87 * V_88 = F_18 ( V_128 ) ;
struct V_170 * V_131 = V_128 -> V_131 ;
struct V_85 * V_86 = V_131 -> V_157 ;
F_29 ( & V_88 -> V_7 -> V_151 , V_137 ) ;
V_96 = V_86 -> V_96 ;
V_97 = V_86 -> V_97 ;
F_30 ( & V_88 -> V_7 -> V_151 , V_137 ) ;
return ( T_2 ) ( ( V_97 * V_131 -> V_165 ) +
V_96 ) ;
}
int F_51 ( struct V_87 * V_88 )
{
int V_12 ;
struct V_188 * V_189 ;
char V_190 [ 32 ] ;
sprintf ( V_190 , L_29 , V_88 -> V_130 ) ;
if ( ( V_12 = F_52 ( V_88 -> V_191 , V_190 , 0 ,
V_88 -> V_149 ,
V_88 -> V_147 , & V_189 ) ) < 0 ) {
F_5 ( V_36 L_30 , V_190 ) ;
return V_12 ;
}
V_189 -> V_157 = V_88 ;
if ( V_88 -> V_149 )
F_53 ( V_189 , V_172 , & V_192 ) ;
if ( V_88 -> V_147 )
F_53 ( V_189 , V_129 , & V_192 ) ;
V_189 -> V_193 = 0 ;
strcpy ( V_189 -> V_190 , V_190 ) ;
F_54 ( V_189 , V_194 ,
F_55 ( V_88 -> V_7 -> V_195 ) ,
32 * 1024 , 32 * 1024 ) ;
V_88 -> V_189 = V_189 ;
return 0 ;
}
static int F_56 ( struct V_87 * V_88 )
{
F_57 ( V_88 ) ;
return 0 ;
}
static int F_58 ( struct V_196 * V_197 )
{
struct V_87 * V_88 = V_197 -> V_198 ;
return F_56 ( V_88 ) ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_199 * V_191 , int V_200 )
{
int V_12 ;
struct V_87 * V_88 ;
static struct V_201 V_202 = {
. V_203 = F_58 ,
} ;
V_88 = F_60 ( sizeof( * V_88 ) , V_204 ) ;
if ( ! V_88 ) {
F_5 ( V_36 L_31 ) ;
return - V_205 ;
}
V_88 -> V_191 = V_191 ;
V_88 -> V_130 = V_200 ;
V_88 -> V_7 = V_7 ;
if ( V_200 < V_7 -> V_206 )
V_88 -> V_149 = V_207 ;
if ( V_200 < V_7 -> V_208 ) {
if ( V_7 -> V_173 )
V_88 -> V_147 = 2 ;
else
V_88 -> V_147 = 1 ;
}
if ( ( V_12 = F_61 ( V_191 , V_209 , V_88 , & V_202 ) ) < 0 ) {
F_56 ( V_88 ) ;
return V_12 ;
}
V_7 -> V_88 [ V_200 ] = V_88 ;
F_62 ( V_191 , & V_7 -> V_195 -> V_210 ) ;
return 0 ;
}
static void F_63 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_87 * V_88 = V_212 -> V_157 ;
struct V_6 * V_7 = V_88 -> V_7 ;
F_64 ( V_214 , L_32 , V_7 -> V_215 ) ;
if ( V_7 -> V_216 & ( 1 << V_217 ) ) {
struct V_10 V_11 ;
short V_218 = ( V_7 -> V_219 >> 16 ) & 0xff ;
short V_220 = ( V_7 -> V_219 >> 8 ) & 0xff ;
short V_221 = V_7 -> V_219 & 0xff ;
F_64 ( V_214 , L_33 ,
V_222 ) ;
F_64 ( V_214 , L_34 ,
V_218 , V_220 , V_221 ) ;
if ( V_7 -> V_223 )
F_64 ( V_214 , L_35 ) ;
else
F_64 ( V_214 , L_36 ) ;
F_3 ( & V_11 , V_224 ) ;
if( ! F_4 ( V_7 , & V_11 ) ) {
int V_225 = V_11 . V_75 [ 0 ] ;
int V_226 = V_11 . V_75 [ 1 ] ;
if ( V_226 > 0 ) {
if ( V_7 -> V_55 != 0 &&
V_7 -> V_55 != 48000 ) {
V_226 = ( V_226 * 48000 ) /
V_7 -> V_55 ;
if ( V_7 -> V_55 >=
V_61 )
V_226 *= 2 ;
}
V_225 = 100 - ( 100 * V_225 ) / V_226 ;
F_64 ( V_214 , L_37 , V_225 ) ;
F_64 ( V_214 , L_38 ,
V_11 . V_75 [ 2 ] , V_11 . V_75 [ 3 ] ) ;
}
}
F_64 ( V_214 , L_39 ,
V_7 -> V_153 ) ;
F_64 ( V_214 , L_40 ,
V_7 -> V_227 ) ;
F_64 ( V_214 , L_41 ,
V_7 -> V_228 ) ;
F_64 ( V_214 , L_42 ,
V_7 -> V_229 ) ;
F_64 ( V_214 , L_43 ,
V_7 -> V_230 ) ;
V_11 . V_32 [ 0 ] = 0x4200 + V_231 ;
V_11 . V_35 = 1 ;
V_11 . V_232 = V_231 ;
V_11 . V_233 = 0 ;
V_11 . V_234 = V_235 ;
if( ! F_4 ( V_7 , & V_11 ) ) {
int V_138 ;
if ( V_11 . V_232 > 8 )
V_11 . V_232 = 8 ;
for ( V_138 = 0 ; V_138 < V_11 . V_232 ; V_138 ++ )
F_64 ( V_214 , L_44 ,
V_138 , V_11 . V_75 [ V_138 ] ) ;
}
} else
F_64 ( V_214 , L_45 ) ;
F_64 ( V_214 , L_46 ) ;
}
static void F_65 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_87 * V_88 = V_212 -> V_157 ;
struct V_6 * V_7 = V_88 -> V_7 ;
static const char * V_236 [ 3 ] = {
L_47 , L_48 , L_49
} ;
static const char * V_237 [ 7 ] = {
L_47 , L_50 , L_48 ,
L_49 , L_51 , L_52 , L_53
} ;
const char * * V_238 ;
int V_239 ;
if ( V_7 -> V_58 ) {
V_238 = V_236 ;
V_239 = V_240 ;
} else {
V_238 = V_237 ;
V_239 = V_241 ;
}
F_64 ( V_214 , L_32 , V_7 -> V_215 ) ;
F_64 ( V_214 , L_54 ,
V_238 [ V_7 -> V_56 ] ) ;
F_64 ( V_214 , L_55 ,
V_7 -> V_55 ) ;
if ( V_7 -> V_216 & ( 1 << V_217 ) ) {
int V_138 , V_12 , V_65 ;
for ( V_138 = 1 ; V_138 <= V_239 ; V_138 ++ ) {
V_12 = F_14 ( V_7 , V_138 , & V_65 ) ;
if ( V_12 )
break;
F_64 ( V_214 , L_56 ,
V_238 [ V_138 ] , V_65 ) ;
}
} else
F_64 ( V_214 , L_45 ) ;
F_64 ( V_214 , L_46 ) ;
}
static void F_66 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_87 * V_88 = V_212 -> V_157 ;
struct V_6 * V_7 = V_88 -> V_7 ;
if ( V_7 -> V_216 & ( 1 << V_217 ) ) {
int V_242 = 0 ;
F_67 ( V_7 , 1 , & V_242 ) ;
F_64 ( V_214 , L_57 , V_242 ) ;
F_67 ( V_7 , 0 , & V_242 ) ;
F_64 ( V_214 , L_58 , V_242 ) ;
} else
F_64 ( V_214 , L_45 ) ;
F_64 ( V_214 , L_46 ) ;
}
static void F_68 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_87 * V_88 = V_212 -> V_157 ;
struct V_6 * V_7 = V_88 -> V_7 ;
char line [ 64 ] ;
int V_242 ;
if ( ! ( V_7 -> V_216 & ( 1 << V_217 ) ) )
return;
while ( ! F_69 ( V_214 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_59 , & V_242 ) != 1 )
continue;
F_70 ( V_7 , V_242 ) ;
}
}
static void F_71 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_87 * V_88 = V_212 -> V_157 ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_10 V_11 ;
unsigned int V_243 , V_244 , V_245 , V_246 ;
int V_12 ;
if ( ! ( V_7 -> V_216 & ( 1 << V_217 ) ) ) {
F_64 ( V_214 , L_45 ) ;
return;
}
if ( ! V_7 -> V_247 ) {
F_3 ( & V_11 , V_248 ) ;
V_11 . V_32 [ 0 ] |= V_249 ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 ) {
F_64 ( V_214 , L_60 , V_12 ) ;
return;
}
if ( V_7 -> V_58 )
F_72 ( V_7 , 1 ) ;
else
F_9 ( V_7 , V_250 ,
V_250 , NULL ) ;
V_7 -> V_247 = 1 ;
}
F_3 ( & V_11 , V_251 ) ;
V_12 = F_4 ( V_7 , & V_11 ) ;
if ( V_12 ) {
F_64 ( V_214 , L_61 , V_12 ) ;
return ;
}
V_243 = 10 * ( ( V_11 . V_75 [ 0 ] >> 8 ) & 0x3 ) + ( V_11 . V_75 [ 0 ] & 0xf ) ;
V_244 = 10 * ( ( V_11 . V_75 [ 1 ] >> 16 ) & 0x7 ) + ( ( V_11 . V_75 [ 1 ] >> 8 ) & 0xf ) ;
V_245 = 10 * ( V_11 . V_75 [ 1 ] & 0x7 ) + ( ( V_11 . V_75 [ 2 ] >> 16 ) & 0xf ) ;
V_246 = 10 * ( ( V_11 . V_75 [ 2 ] >> 8 ) & 0x3 ) + ( V_11 . V_75 [ 2 ] & 0xf ) ;
F_64 ( V_214 , L_62 ,
V_243 , V_244 , V_245 , V_246 ) ;
F_64 ( V_214 , L_63 , V_11 . V_75 [ 0 ] & 0x00ffff ,
V_11 . V_75 [ 1 ] & 0xffffff , V_11 . V_75 [ 2 ] & 0xffffff ) ;
if ( ! ( V_11 . V_75 [ 0 ] & V_252 ) ) {
F_64 ( V_214 , L_64 ) ;
}
}
static void F_73 ( struct V_87 * V_88 )
{
struct V_211 * V_212 ;
if ( ! F_74 ( V_88 -> V_191 , L_65 , & V_212 ) )
F_75 ( V_212 , V_88 , F_63 ) ;
if ( ! F_74 ( V_88 -> V_191 , L_66 , & V_212 ) )
F_75 ( V_212 , V_88 , F_65 ) ;
if ( V_88 -> V_7 -> V_58 &&
! F_74 ( V_88 -> V_191 , L_67 , & V_212 ) ) {
F_75 ( V_212 , V_88 , F_66 ) ;
V_212 -> V_253 . V_254 . V_255 = F_68 ;
V_212 -> V_256 |= V_257 ;
}
if ( ! F_74 ( V_88 -> V_191 , L_68 , & V_212 ) )
F_75 ( V_212 , V_88 , F_71 ) ;
}
static int F_76 ( struct V_6 * V_7 )
{
unsigned int V_138 ;
for ( V_138 = 0 ; V_138 < V_7 -> V_146 ; V_138 ++ ) {
if ( V_7 -> V_88 [ V_138 ] )
F_77 ( V_7 -> V_88 [ V_138 ] -> V_191 ) ;
}
if( V_7 -> V_216 ) {
F_78 ( V_7 ) ;
F_8 ( L_69 ) ;
}
if ( V_7 -> V_258 >= 0 )
F_79 ( V_7 -> V_258 , V_7 ) ;
F_80 ( V_7 -> V_195 ) ;
if ( V_7 -> V_259 . V_260 ) {
F_81 ( & V_7 -> V_259 ) ;
V_7 -> V_259 . V_260 = NULL ;
}
F_57 ( V_7 -> V_261 ) ;
F_82 ( V_7 -> V_195 ) ;
F_57 ( V_7 ) ;
return 0 ;
}
static int F_83 ( struct V_262 * V_195 ,
const struct V_263 * V_264 )
{
static int V_210 ;
struct V_6 * V_7 ;
unsigned int V_138 ;
int V_12 ;
T_4 V_265 ;
char * V_266 ;
if ( V_210 >= V_267 )
return - V_268 ;
if ( ! V_269 [ V_210 ] ) {
V_210 ++ ;
return - V_270 ;
}
if ( ( V_12 = F_84 ( V_195 ) ) < 0 )
return V_12 ;
F_85 ( V_195 ) ;
if ( F_86 ( V_195 , F_87 ( 32 ) ) < 0 ) {
F_5 ( V_36 L_70
L_71 ) ;
F_82 ( V_195 ) ;
return - V_271 ;
}
V_7 = F_60 ( sizeof( * V_7 ) , V_204 ) ;
if ( ! V_7 ) {
F_82 ( V_195 ) ;
return - V_205 ;
}
if ( F_21 ( V_264 -> V_272 >= V_273 ) ) {
F_57 ( V_7 ) ;
F_82 ( V_195 ) ;
return - V_268 ;
}
V_266 =
V_274 [ V_264 -> V_272 ] . V_275 ;
V_7 -> V_206 =
V_274 [ V_264 -> V_272 ] . V_206 ;
V_7 -> V_208 =
V_274 [ V_264 -> V_272 ] . V_208 ;
V_7 -> V_276 =
V_274 [ V_264 -> V_272 ] . V_276 ;
V_7 -> V_277 =
V_274 [ V_264 -> V_272 ] . V_277 ;
V_7 -> V_173 = V_278 [ V_210 ] ;
V_7 -> V_58 = ( V_7 -> V_206 == 1 ) ;
V_7 -> V_279 = F_88 ( V_7 ) ;
V_7 -> V_280 = ! F_89 ( V_7 ) ;
if ( V_7 -> V_58 )
V_7 -> V_153 = V_281 ;
else
V_7 -> V_153 = V_282 ;
if ( ( V_12 = F_90 ( V_195 , V_266 ) ) < 0 ) {
F_57 ( V_7 ) ;
F_82 ( V_195 ) ;
return V_12 ;
}
for ( V_138 = 0 ; V_138 < 3 ; V_138 ++ )
V_7 -> V_283 [ V_138 ] = F_91 ( V_195 , V_138 ) ;
V_7 -> V_195 = V_195 ;
V_7 -> V_258 = - 1 ;
if ( F_92 ( V_195 -> V_258 , V_284 , V_285 ,
V_286 , V_7 ) ) {
F_5 ( V_36 L_72 , V_195 -> V_258 ) ;
F_76 ( V_7 ) ;
return - V_177 ;
}
V_7 -> V_258 = V_195 -> V_258 ;
sprintf ( V_7 -> V_287 , L_73 , V_266 ) ;
sprintf ( V_7 -> V_215 , L_74 ,
V_7 -> V_287 ,
V_7 -> V_283 [ 0 ] , V_7 -> V_283 [ 1 ] , V_7 -> V_283 [ 2 ] , V_7 -> V_258 ) ;
F_93 ( & V_7 -> V_151 ) ;
F_93 ( & V_7 -> V_288 ) ;
F_94 ( & V_7 -> V_145 ) ;
F_95 ( & V_7 -> V_289 , V_290 ,
( unsigned long ) V_7 ) ;
F_95 ( & V_7 -> V_158 , F_23 ,
( unsigned long ) V_7 ) ;
V_7 -> V_261 = F_96 ( sizeof( * V_7 -> V_261 ) +
sizeof( V_291 ) * ( V_292 -
V_231 ) ,
V_204 ) ;
if ( ! V_7 -> V_261 ) {
F_76 ( V_7 ) ;
return - V_205 ;
}
for ( V_138 = 0 ; V_138 < V_293 ; V_138 ++ ) {
struct V_199 * V_191 ;
char V_294 [ 16 ] ;
int V_200 ;
if ( V_138 >= F_97 ( V_7 -> V_206 , V_7 -> V_208 ) )
break;
V_7 -> V_146 ++ ;
if ( V_295 [ V_210 ] < 0 )
V_200 = V_295 [ V_210 ] ;
else
V_200 = V_295 [ V_210 ] + V_138 ;
snprintf ( V_294 , sizeof( V_294 ) , L_75 ,
V_296 [ V_210 ] ? V_296 [ V_210 ] : V_266 , V_138 ) ;
V_12 = F_98 ( V_200 , V_294 , V_297 , 0 , & V_191 ) ;
if ( V_12 < 0 ) {
F_5 ( V_36 L_76 , V_138 ) ;
F_76 ( V_7 ) ;
return V_12 ;
}
strcpy ( V_191 -> V_298 , V_299 ) ;
sprintf ( V_191 -> V_287 , L_77 , V_7 -> V_287 , V_138 ) ;
sprintf ( V_191 -> V_215 , L_77 , V_7 -> V_215 , V_138 ) ;
if ( ( V_12 = F_59 ( V_7 , V_191 , V_138 ) ) < 0 ) {
F_77 ( V_191 ) ;
F_76 ( V_7 ) ;
return V_12 ;
}
if ( V_138 == 0 )
F_73 ( V_7 -> V_88 [ V_138 ] ) ;
if ( ( V_12 = F_99 ( V_191 ) ) < 0 ) {
F_76 ( V_7 ) ;
return V_12 ;
}
}
V_265 = F_100 ( sizeof( struct V_300 ) ) ;
if ( F_101 ( V_194 , F_55 ( V_195 ) ,
V_265 , & V_7 -> V_259 ) < 0 ) {
F_76 ( V_7 ) ;
return - V_205 ;
}
memset ( V_7 -> V_259 . V_260 , 0 , V_265 ) ;
V_12 = F_102 ( V_7 ) ;
if ( V_12 < 0 ) {
F_76 ( V_7 ) ;
return V_12 ;
}
F_103 ( V_195 , V_7 ) ;
V_210 ++ ;
return 0 ;
}
static void F_104 ( struct V_262 * V_195 )
{
F_76 ( F_105 ( V_195 ) ) ;
}
