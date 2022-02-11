static void F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
unsigned short V_4 = 0x8000 ;
F_2 ( V_2 , V_5 ) ;
while ( V_4 ) {
F_3 ( V_2 , V_6 ,
V_3 & V_4 ? V_7 : 0 ) ;
V_4 >>= 1 ;
}
F_2 ( V_2 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_9 , int V_10 )
{
unsigned short V_11 ;
if ( V_9 > 1 ||
V_10 < 0 ||
V_10 >= F_5 ( V_12 ) )
return - V_13 ;
if ( V_9 == 0 )
V_11 = V_14 ;
else
V_11 = V_15 ;
V_11 += V_12 [ V_10 ] ;
F_1 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_16 , int V_17 , int V_18 )
{
unsigned int V_3 ;
int V_19 ;
if ( ! V_2 -> V_20 )
return - V_13 ;
V_3 = ( ( V_18 & 0xff ) << 24 ) ;
V_3 |= ( ( V_18 & 0xff ) << 16 ) ;
V_3 |= ( ( V_17 & 0xff ) << 8 ) ;
V_3 |= ( V_16 & 0xff ) ;
F_2 ( V_2 , V_6 ) ;
for ( V_19 = 0 ; V_19 < 32 ; V_19 ++ , V_3 <<= 1 ) {
F_3 ( V_2 , V_6 ,
( V_3 & 0x80000000 ) ? V_7 : 0 ) ;
}
F_2 ( V_2 , V_8 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
unsigned char V_21 ;
V_2 -> V_22 = 1 ;
V_2 -> V_23 = V_24 ;
V_21 = F_2 ( V_2 , V_25 ) ;
if ( V_21 & V_26 )
V_2 -> V_27 = 1 ;
F_8 ( & V_2 -> V_28 -> V_29 ,
L_1 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_30 ,
V_31 ) ;
F_9 ( 5 ) ;
V_2 -> V_32 = V_31 |
V_33 |
V_34 ;
F_3 ( V_2 , V_30 , V_2 -> V_32 ) ;
F_9 ( 5 ) ;
F_1 ( V_2 , V_35 ) ;
F_1 ( V_2 , V_36 ) ;
F_1 ( V_2 , V_37 ) ;
F_1 ( V_2 , V_38 ) ;
F_10 ( V_2 , 0 ) ;
return 0 ;
}
static int F_11 ( unsigned int V_39 ,
unsigned int * V_40 ,
unsigned int * V_41 )
{
unsigned int V_21 ;
if ( V_39 < 6900 || V_39 > 219000 )
return - V_13 ;
V_21 = ( 28224000 * 2 ) / V_39 ;
V_21 = ( V_21 - 1 ) / 2 ;
if ( V_21 < 0x100 )
* V_40 = V_21 + 0xC00 ;
else if ( V_21 < 0x200 )
* V_40 = V_21 + 0x800 ;
else if ( V_21 < 0x400 )
* V_40 = V_21 & 0x1ff ;
else if ( V_21 < 0x800 ) {
* V_40 = ( ( V_21 >> 1 ) & 0x1ff ) + 0x200 ;
V_21 &= ~ 1 ;
} else {
* V_40 = ( ( V_21 >> 2 ) & 0x1ff ) + 0x400 ;
V_21 &= ~ 3 ;
}
if ( V_41 )
* V_41 = ( 28224000 / ( V_21 + 1 ) ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned int V_42 ,
int * V_43 )
{
unsigned int V_44 , V_40 = 0 ;
int V_45 ;
unsigned V_41 = V_42 ;
switch ( V_2 -> V_46 ) {
case V_47 :
V_45 = F_11 ( V_42 , & V_40 , & V_41 ) ;
if ( V_45 )
return V_45 ;
V_2 -> V_23 &= ~ ( V_48 |
V_49 ) ;
break;
case V_50 :
V_2 -> V_23 |= V_48 ;
V_2 -> V_23 &= ~ V_49 ;
break;
case V_51 :
if ( ! V_2 -> V_52 )
return - V_13 ;
V_2 -> V_23 |= ( V_48 |
V_49 ) ;
break;
default:
return - V_13 ;
}
F_1 ( V_2 , V_53 ) ;
if ( V_2 -> V_46 == V_47 ) {
F_3 ( V_2 , V_5 , V_40 >> 8 ) ;
F_3 ( V_2 , V_54 , V_40 & 0xff ) ;
}
F_3 ( V_2 , V_55 , V_2 -> V_23 ) ;
V_44 = V_42 < 55000 ? 0 : 1 ;
if ( V_2 -> V_56 != V_44 ) {
V_2 -> V_56 = V_44 ;
if ( V_44 == 0 )
F_1 ( V_2 , V_36 ) ;
else
F_1 ( V_2 , V_57 ) ;
}
V_2 -> V_58 = V_41 ;
V_2 -> V_59 = V_2 -> V_46 ;
if ( V_43 )
* V_43 = 1 ;
F_1 ( V_2 , V_37 ) ;
F_8 ( & V_2 -> V_28 -> V_29 , L_2 ,
V_42 , V_41 , V_40 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
enum V_60 V_61 ,
int * V_62 )
{
int V_42 , V_63 = 0 ;
unsigned int V_64 ;
unsigned char V_4 , V_21 ;
if ( V_61 == V_50 ) {
V_4 = ( V_65 |
V_66 ) ;
V_21 = V_67 ;
} else if ( V_61 == V_51 && V_2 -> V_52 ) {
V_4 = ( V_68 |
V_69 ) ;
V_21 = V_70 ;
} else {
F_8 ( & V_2 -> V_28 -> V_29 ,
L_3 ,
V_61 ) ;
return - V_13 ;
}
if ( ( F_2 ( V_2 , V_71 ) & V_4 ) != V_4 ) {
F_8 ( & V_2 -> V_28 -> V_29 ,
L_4 , V_61 ) ;
* V_62 = 0 ;
return 0 ;
}
F_3 ( V_2 , V_25 , V_21 ) ;
V_21 |= V_72 ;
if ( V_2 -> V_73 != V_21 ) {
F_14 ( 500 ) ;
V_2 -> V_73 = V_21 ;
}
F_3 ( V_2 , V_25 , V_21 ) ;
V_64 = ( unsigned int ) F_2 ( V_2 , V_55 ) ;
V_64 = ( V_64 & 0x03 ) << 8 ;
V_64 |= ( unsigned int ) F_2 ( V_2 , V_30 ) ;
if ( V_64 != 0 )
V_63 = 28224000 / V_64 ;
if ( V_63 > 184200 )
V_42 = 192000 ;
else if ( V_63 > 152200 )
V_42 = 176400 ;
else if ( V_63 > 112000 )
V_42 = 128000 ;
else if ( V_63 > 92100 )
V_42 = 96000 ;
else if ( V_63 > 76100 )
V_42 = 88200 ;
else if ( V_63 > 56000 )
V_42 = 64000 ;
else if ( V_63 > 46050 )
V_42 = 48000 ;
else if ( V_63 > 38050 )
V_42 = 44100 ;
else if ( V_63 > 28000 )
V_42 = 32000 ;
else if ( V_63 > 23025 )
V_42 = 24000 ;
else if ( V_63 > 19025 )
V_42 = 22050 ;
else if ( V_63 > 14000 )
V_42 = 16000 ;
else if ( V_63 > 11512 )
V_42 = 12000 ;
else if ( V_63 > 9512 )
V_42 = 11025 ;
else if ( V_63 > 7000 )
V_42 = 8000 ;
else
V_42 = 0 ;
F_8 ( & V_2 -> V_28 -> V_29 , L_5 ,
V_42 , V_63 ) ;
* V_62 = V_42 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , int V_74 , int * V_75 )
{
if ( V_74 ) {
unsigned char V_21 = F_2 ( V_2 , V_25 ) ;
* V_75 = ( int ) ( V_21 & V_76 ) >>
V_77 ;
} else {
* V_75 = ( int ) ( V_2 -> V_32 & V_78 ) >>
V_79 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , int V_75 )
{
unsigned char V_21 = V_2 -> V_32 & ~ V_78 ;
V_21 |= ( unsigned char ) ( V_75 << V_79 ) &
V_78 ;
F_3 ( V_2 , V_30 , V_21 ) ;
V_2 -> V_32 = V_21 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , int V_80 )
{
if ( V_80 )
V_2 -> V_32 |= V_81 ;
else
V_2 -> V_32 &= ~ V_81 ;
F_3 ( V_2 , V_30 , V_2 -> V_32 ) ;
return 0 ;
}
int F_18 ( struct V_82 * V_83 ,
int V_84 , int V_85 )
{
F_8 ( V_83 -> V_86 -> V_29 ,
L_6 ,
V_84 ? L_7 : L_8 , V_85 ) ;
if ( V_84 ) {
int V_16 , V_17 , V_18 ;
if ( V_83 -> V_87 ) {
V_16 = V_83 -> V_88 [ 0 ] ;
V_17 = V_83 -> V_88 [ 1 ] ;
} else {
V_16 = V_89 ;
V_17 = V_89 ;
}
if ( V_83 -> V_90 )
V_18 = V_83 -> V_91 ;
else
V_18 = V_92 ;
return F_6 ( V_83 -> V_2 ,
V_16 , V_17 , V_18 ) ;
} else {
int V_93 ;
if ( V_83 -> V_94 [ V_85 ] )
V_93 = V_83 -> V_95 [ V_85 ] ;
else
V_93 = V_96 ;
return F_4 ( V_83 -> V_2 , V_85 , V_93 ) ;
}
}
int F_19 ( struct V_82 * V_83 )
{
int V_97 = 0 ;
V_83 -> V_2 -> V_23 &= ~ ( V_98 |
V_99 |
V_100 ) ;
if ( V_83 -> V_101 == V_102 ) {
V_83 -> V_2 -> V_23 |= V_98 ;
V_97 = 1 ;
} else {
if ( V_83 -> V_101 == V_103 )
V_97 = 1 ;
}
if ( V_97 ) {
V_83 -> V_2 -> V_23 |= V_99 ;
if ( V_83 -> V_2 -> V_52 ) {
V_83 -> V_2 -> V_23 |= V_100 ;
}
} else {
int V_104 = 0 ;
V_83 -> V_87 = 0 ;
V_83 -> V_90 = 0 ;
if ( V_83 -> V_101 == V_105 ||
V_83 -> V_101 == V_106 ) {
if ( V_83 -> V_87 == 0 )
V_104 = 1 ;
V_83 -> V_87 = 1 ;
}
if ( V_83 -> V_101 == V_107 ||
V_83 -> V_101 == V_106 ) {
if ( V_83 -> V_90 == 0 )
V_104 = 1 ;
V_83 -> V_90 = 1 ;
}
if ( V_104 ) {
F_18 ( V_83 , 1 , 0 ) ;
}
}
F_3 ( V_83 -> V_2 , V_55 , V_83 -> V_2 -> V_23 ) ;
return 0 ;
}
int F_20 ( struct V_82 * V_83 ,
int V_108 , unsigned char * V_109 )
{
unsigned char V_9 = ( unsigned char ) ( V_108 * 8 ) ;
unsigned char V_110 = 0 ;
unsigned char V_4 = V_83 -> V_2 -> V_52 ?
V_111 : V_112 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_3 ( V_83 -> V_2 , V_8 , V_9 ++ ) ;
V_110 <<= 1 ;
if ( F_2 ( V_83 -> V_2 , V_71 ) & V_4 )
V_110 |= 1 ;
}
F_8 ( V_83 -> V_86 -> V_29 , L_9 ,
V_83 -> V_113 , V_108 , V_110 ) ;
* V_109 = V_110 ;
return 0 ;
}
int F_21 ( struct V_82 * V_83 ,
int V_108 , unsigned char V_109 )
{
int V_19 ;
unsigned char V_114 = V_109 ;
unsigned char V_115 = V_83 -> V_109 [ V_108 ] ;
unsigned char V_9 = ( unsigned char ) ( V_108 * 8 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( ( V_115 & 0x01 ) != ( V_114 & 0x01 ) ) {
F_3 ( V_83 -> V_2 , V_8 , V_9 ) ;
F_3 ( V_83 -> V_2 , V_71 , V_114 & 0x01 ?
V_116 : 0 ) ;
}
V_9 ++ ;
V_115 >>= 1 ;
V_114 >>= 1 ;
}
V_83 -> V_109 [ V_108 ] = V_109 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , int V_10 )
{
unsigned char V_117 ;
V_117 = ( unsigned char ) ( V_10 << V_118 ) ;
if ( V_117 & ( ~ V_119 ) )
return;
V_2 -> V_120 &= ~ V_119 ;
V_2 -> V_120 |= V_117 ;
F_3 ( V_2 , V_121 , V_2 -> V_120 ) ;
F_8 ( & V_2 -> V_28 -> V_29 , L_10 , V_117 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_122 )
{
if ( V_122 )
V_2 -> V_120 |= V_123 ;
else
V_2 -> V_120 &= ~ V_123 ;
F_3 ( V_2 , V_121 , V_2 -> V_120 ) ;
F_8 ( & V_2 -> V_28 -> V_29 , L_11 , V_122 ) ;
}
static int F_23 ( struct V_124 * V_125 ,
struct V_126 * V_127 )
{
V_127 -> type = V_128 ;
V_127 -> V_129 = 1 ;
V_127 -> V_75 . integer . V_130 = V_92 ;
V_127 -> V_75 . integer . V_131 = V_132 ;
return 0 ;
}
static int F_24 ( struct V_124 * V_125 ,
struct V_133 * V_134 )
{
struct V_82 * V_83 = F_25 ( V_125 ) ;
F_26 ( & V_83 -> V_2 -> V_135 ) ;
V_134 -> V_75 . integer . V_75 [ 0 ] = V_83 -> V_91 ;
F_27 ( & V_83 -> V_2 -> V_135 ) ;
return 0 ;
}
static int F_28 ( struct V_124 * V_125 ,
struct V_133 * V_134 )
{
struct V_82 * V_83 = F_25 ( V_125 ) ;
int V_43 = 0 ;
F_26 ( & V_83 -> V_2 -> V_135 ) ;
if ( V_83 -> V_91 != V_134 -> V_75 . integer . V_75 [ 0 ] ) {
V_43 = 1 ;
V_83 -> V_91 = V_134 -> V_75 . integer . V_75 [ 0 ] ;
F_18 ( V_83 , 1 , 0 ) ;
}
F_27 ( & V_83 -> V_2 -> V_135 ) ;
return V_43 ;
}
static int F_29 ( struct V_124 * V_125 ,
struct V_126 * V_127 )
{
V_127 -> type = V_128 ;
V_127 -> V_129 = 1 ;
V_127 -> V_75 . integer . V_130 = 0 ;
V_127 -> V_75 . integer . V_131 = 3 ;
return 0 ;
}
static int F_30 ( struct V_124 * V_125 ,
struct V_133 * V_134 )
{
struct V_82 * V_83 = F_25 ( V_125 ) ;
F_26 ( & V_83 -> V_2 -> V_135 ) ;
V_134 -> V_75 . integer . V_75 [ 0 ] = V_83 -> V_136 ;
F_27 ( & V_83 -> V_2 -> V_135 ) ;
return 0 ;
}
static int F_31 ( struct V_124 * V_125 ,
struct V_133 * V_134 )
{
struct V_82 * V_83 = F_25 ( V_125 ) ;
int V_43 = 0 ;
F_26 ( & V_83 -> V_2 -> V_135 ) ;
if ( V_83 -> V_136 != V_134 -> V_75 . integer . V_75 [ 0 ] ) {
V_43 = 1 ;
V_83 -> V_136 = V_134 -> V_75 . integer . V_75 [ 0 ] ;
F_10 ( V_83 -> V_2 , V_83 -> V_136 ) ;
}
F_27 ( & V_83 -> V_2 -> V_135 ) ;
return V_43 ;
}
static int F_32 ( struct V_124 * V_125 ,
struct V_133 * V_134 )
{
struct V_82 * V_83 = F_25 ( V_125 ) ;
F_26 ( & V_83 -> V_2 -> V_135 ) ;
V_134 -> V_75 . integer . V_75 [ 0 ] = V_83 -> V_137 ;
F_27 ( & V_83 -> V_2 -> V_135 ) ;
return 0 ;
}
static int F_33 ( struct V_124 * V_125 ,
struct V_133 * V_134 )
{
struct V_82 * V_83 = F_25 ( V_125 ) ;
int V_122 , V_43 = 0 ;
F_26 ( & V_83 -> V_2 -> V_135 ) ;
V_122 = ! ! V_134 -> V_75 . integer . V_75 [ 0 ] ;
if ( V_83 -> V_137 != V_122 ) {
F_22 ( V_83 -> V_2 , V_122 ) ;
V_83 -> V_137 = V_122 ;
V_43 = 1 ;
}
F_27 ( & V_83 -> V_2 -> V_135 ) ;
return V_43 ;
}
int F_34 ( struct V_82 * V_83 )
{
int V_45 ;
if ( ! V_83 -> V_2 -> V_27 )
return 0 ;
V_45 = F_35 ( V_83 -> V_86 , F_36 ( & V_138 ,
V_83 ) ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_35 ( V_83 -> V_86 , F_36 ( & V_139 ,
V_83 ) ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_35 ( V_83 -> V_86 , F_36 ( & V_140 ,
V_83 ) ) ;
return V_45 ;
}
