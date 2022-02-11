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
F_8 ( L_1 , V_2 -> V_27 ) ;
F_3 ( V_2 , V_28 ,
V_29 ) ;
F_9 ( 5 ) ;
V_2 -> V_30 = V_29 |
V_31 |
V_32 ;
F_3 ( V_2 , V_28 , V_2 -> V_30 ) ;
F_9 ( 5 ) ;
F_1 ( V_2 , V_33 ) ;
F_1 ( V_2 , V_34 ) ;
F_1 ( V_2 , V_35 ) ;
F_1 ( V_2 , V_36 ) ;
F_10 ( V_2 , 0 ) ;
return 0 ;
}
static int F_11 ( unsigned int V_37 ,
unsigned int * V_38 ,
unsigned int * V_39 )
{
unsigned int V_21 ;
if ( V_37 < 6900 || V_37 > 219000 )
return - V_13 ;
V_21 = ( 28224000 * 2 ) / V_37 ;
V_21 = ( V_21 - 1 ) / 2 ;
if ( V_21 < 0x100 )
* V_38 = V_21 + 0xC00 ;
else if ( V_21 < 0x200 )
* V_38 = V_21 + 0x800 ;
else if ( V_21 < 0x400 )
* V_38 = V_21 & 0x1ff ;
else if ( V_21 < 0x800 ) {
* V_38 = ( ( V_21 >> 1 ) & 0x1ff ) + 0x200 ;
V_21 &= ~ 1 ;
} else {
* V_38 = ( ( V_21 >> 2 ) & 0x1ff ) + 0x400 ;
V_21 &= ~ 3 ;
}
if ( V_39 )
* V_39 = ( 28224000 / ( V_21 + 1 ) ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned int V_40 ,
int * V_41 )
{
unsigned int V_42 , V_38 = 0 ;
int V_43 ;
unsigned V_39 = V_40 ;
switch ( V_2 -> V_44 ) {
case V_45 :
V_43 = F_11 ( V_40 , & V_38 , & V_39 ) ;
if ( V_43 )
return V_43 ;
V_2 -> V_23 &= ~ ( V_46 |
V_47 ) ;
break;
case V_48 :
V_2 -> V_23 |= V_46 ;
V_2 -> V_23 &= ~ V_47 ;
break;
case V_49 :
if ( ! V_2 -> V_50 )
return - V_13 ;
V_2 -> V_23 |= ( V_46 |
V_47 ) ;
break;
default:
return - V_13 ;
}
F_1 ( V_2 , V_51 ) ;
if ( V_2 -> V_44 == V_45 ) {
F_3 ( V_2 , V_5 , V_38 >> 8 ) ;
F_3 ( V_2 , V_52 , V_38 & 0xff ) ;
}
F_3 ( V_2 , V_53 , V_2 -> V_23 ) ;
V_42 = V_40 < 55000 ? 0 : 1 ;
if ( V_2 -> V_54 != V_42 ) {
V_2 -> V_54 = V_42 ;
if ( V_42 == 0 )
F_1 ( V_2 , V_34 ) ;
else
F_1 ( V_2 , V_55 ) ;
}
V_2 -> V_56 = V_39 ;
V_2 -> V_57 = V_2 -> V_44 ;
if ( V_41 )
* V_41 = 1 ;
F_1 ( V_2 , V_35 ) ;
F_8 ( L_2 ,
V_40 , V_39 , V_38 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
enum V_58 V_59 ,
int * V_60 )
{
int V_40 , V_61 = 0 ;
unsigned int V_62 ;
unsigned char V_4 , V_21 ;
if ( V_59 == V_48 ) {
V_4 = ( V_63 |
V_64 ) ;
V_21 = V_65 ;
} else if ( V_59 == V_49 && V_2 -> V_50 ) {
V_4 = ( V_66 |
V_67 ) ;
V_21 = V_68 ;
} else {
F_8 ( L_3 ,
V_59 ) ;
return - V_13 ;
}
if ( ( F_2 ( V_2 , V_69 ) & V_4 ) != V_4 ) {
F_8 ( L_4 , V_59 ) ;
* V_60 = 0 ;
return 0 ;
}
F_3 ( V_2 , V_25 , V_21 ) ;
V_21 |= V_70 ;
if ( V_2 -> V_71 != V_21 ) {
F_14 ( 500 ) ;
V_2 -> V_71 = V_21 ;
}
F_3 ( V_2 , V_25 , V_21 ) ;
V_62 = ( unsigned int ) F_2 ( V_2 , V_53 ) ;
V_62 = ( V_62 & 0x03 ) << 8 ;
V_62 |= ( unsigned int ) F_2 ( V_2 , V_28 ) ;
if ( V_62 != 0 )
V_61 = 28224000 / V_62 ;
if ( V_61 > 184200 )
V_40 = 192000 ;
else if ( V_61 > 152200 )
V_40 = 176400 ;
else if ( V_61 > 112000 )
V_40 = 128000 ;
else if ( V_61 > 92100 )
V_40 = 96000 ;
else if ( V_61 > 76100 )
V_40 = 88200 ;
else if ( V_61 > 56000 )
V_40 = 64000 ;
else if ( V_61 > 46050 )
V_40 = 48000 ;
else if ( V_61 > 38050 )
V_40 = 44100 ;
else if ( V_61 > 28000 )
V_40 = 32000 ;
else if ( V_61 > 23025 )
V_40 = 24000 ;
else if ( V_61 > 19025 )
V_40 = 22050 ;
else if ( V_61 > 14000 )
V_40 = 16000 ;
else if ( V_61 > 11512 )
V_40 = 12000 ;
else if ( V_61 > 9512 )
V_40 = 11025 ;
else if ( V_61 > 7000 )
V_40 = 8000 ;
else
V_40 = 0 ;
F_8 ( L_5 ,
V_40 , V_61 ) ;
* V_60 = V_40 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , int V_72 , int * V_73 )
{
if ( V_72 ) {
unsigned char V_21 = F_2 ( V_2 , V_25 ) ;
* V_73 = ( int ) ( V_21 & V_74 ) >>
V_75 ;
} else {
* V_73 = ( int ) ( V_2 -> V_30 & V_76 ) >>
V_77 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , int V_73 )
{
unsigned char V_21 = V_2 -> V_30 & ~ V_76 ;
V_21 |= ( unsigned char ) ( V_73 << V_77 ) &
V_76 ;
F_3 ( V_2 , V_28 , V_21 ) ;
V_2 -> V_30 = V_21 ;
return 0 ;
}
int F_17 ( struct V_78 * V_79 ,
int V_80 , int V_81 )
{
F_8 ( L_6 ,
V_80 ? L_7 : L_8 , V_81 ) ;
if ( V_80 ) {
int V_16 , V_17 , V_18 ;
if ( V_79 -> V_82 ) {
V_16 = V_79 -> V_83 [ 0 ] ;
V_17 = V_79 -> V_83 [ 1 ] ;
} else {
V_16 = V_84 ;
V_17 = V_84 ;
}
if ( V_79 -> V_85 )
V_18 = V_79 -> V_86 ;
else
V_18 = V_87 ;
return F_6 ( V_79 -> V_2 ,
V_16 , V_17 , V_18 ) ;
} else {
int V_88 ;
if ( V_79 -> V_89 [ V_81 ] )
V_88 = V_79 -> V_90 [ V_81 ] ;
else
V_88 = V_91 ;
return F_4 ( V_79 -> V_2 , V_81 , V_88 ) ;
}
}
int F_18 ( struct V_78 * V_79 )
{
int V_92 = 0 ;
V_79 -> V_2 -> V_23 &= ~ ( V_93 |
V_94 |
V_95 ) ;
if ( V_79 -> V_96 == V_97 ) {
V_79 -> V_2 -> V_23 |= V_93 ;
V_92 = 1 ;
} else {
if ( V_79 -> V_96 == V_98 )
V_92 = 1 ;
}
if ( V_92 ) {
V_79 -> V_2 -> V_23 |= V_94 ;
if ( V_79 -> V_2 -> V_50 ) {
V_79 -> V_2 -> V_23 |= V_95 ;
}
} else {
int V_99 = 0 ;
V_79 -> V_82 = 0 ;
V_79 -> V_85 = 0 ;
if ( V_79 -> V_96 == V_100 ||
V_79 -> V_96 == V_101 ) {
if ( V_79 -> V_82 == 0 )
V_99 = 1 ;
V_79 -> V_82 = 1 ;
}
if ( V_79 -> V_96 == V_102 ||
V_79 -> V_96 == V_101 ) {
if ( V_79 -> V_85 == 0 )
V_99 = 1 ;
V_79 -> V_85 = 1 ;
}
if ( V_99 ) {
F_17 ( V_79 , 1 , 0 ) ;
}
}
F_3 ( V_79 -> V_2 , V_53 , V_79 -> V_2 -> V_23 ) ;
return 0 ;
}
int F_19 ( struct V_78 * V_79 ,
int V_103 , unsigned char * V_104 )
{
unsigned char V_9 = ( unsigned char ) ( V_103 * 8 ) ;
unsigned char V_105 = 0 ;
unsigned char V_4 = V_79 -> V_2 -> V_50 ?
V_106 : V_107 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_3 ( V_79 -> V_2 , V_8 , V_9 ++ ) ;
V_105 <<= 1 ;
if ( F_2 ( V_79 -> V_2 , V_69 ) & V_4 )
V_105 |= 1 ;
}
F_8 ( L_9 ,
V_79 -> V_108 , V_103 , V_105 ) ;
* V_104 = V_105 ;
return 0 ;
}
int F_20 ( struct V_78 * V_79 ,
int V_103 , unsigned char V_104 )
{
int V_19 ;
unsigned char V_109 = V_104 ;
unsigned char V_110 = V_79 -> V_104 [ V_103 ] ;
unsigned char V_9 = ( unsigned char ) ( V_103 * 8 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( ( V_110 & 0x01 ) != ( V_109 & 0x01 ) ) {
F_3 ( V_79 -> V_2 , V_8 , V_9 ) ;
F_3 ( V_79 -> V_2 , V_69 , V_109 & 0x01 ?
V_111 : 0 ) ;
}
V_9 ++ ;
V_110 >>= 1 ;
V_109 >>= 1 ;
}
V_79 -> V_104 [ V_103 ] = V_104 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , int V_10 )
{
unsigned char V_112 ;
V_112 = ( unsigned char ) ( V_10 << V_113 ) ;
if ( V_112 & ( ~ V_114 ) )
return;
V_2 -> V_115 &= ~ V_114 ;
V_2 -> V_115 |= V_112 ;
F_3 ( V_2 , V_116 , V_2 -> V_115 ) ;
F_8 ( L_10 , V_112 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_117 )
{
if ( V_117 )
V_2 -> V_115 |= V_118 ;
else
V_2 -> V_115 &= ~ V_118 ;
F_3 ( V_2 , V_116 , V_2 -> V_115 ) ;
F_8 ( L_11 , V_117 ) ;
}
static int F_22 ( struct V_119 * V_120 ,
struct V_121 * V_122 )
{
V_122 -> type = V_123 ;
V_122 -> V_124 = 1 ;
V_122 -> V_73 . integer . V_125 = V_87 ;
V_122 -> V_73 . integer . V_126 = V_127 ;
return 0 ;
}
static int F_23 ( struct V_119 * V_120 ,
struct V_128 * V_129 )
{
struct V_78 * V_79 = F_24 ( V_120 ) ;
F_25 ( & V_79 -> V_2 -> V_130 ) ;
V_129 -> V_73 . integer . V_73 [ 0 ] = V_79 -> V_86 ;
F_26 ( & V_79 -> V_2 -> V_130 ) ;
return 0 ;
}
static int F_27 ( struct V_119 * V_120 ,
struct V_128 * V_129 )
{
struct V_78 * V_79 = F_24 ( V_120 ) ;
int V_41 = 0 ;
F_25 ( & V_79 -> V_2 -> V_130 ) ;
if ( V_79 -> V_86 != V_129 -> V_73 . integer . V_73 [ 0 ] ) {
V_41 = 1 ;
V_79 -> V_86 = V_129 -> V_73 . integer . V_73 [ 0 ] ;
F_17 ( V_79 , 1 , 0 ) ;
}
F_26 ( & V_79 -> V_2 -> V_130 ) ;
return V_41 ;
}
static int F_28 ( struct V_119 * V_120 ,
struct V_121 * V_122 )
{
V_122 -> type = V_123 ;
V_122 -> V_124 = 1 ;
V_122 -> V_73 . integer . V_125 = 0 ;
V_122 -> V_73 . integer . V_126 = 3 ;
return 0 ;
}
static int F_29 ( struct V_119 * V_120 ,
struct V_128 * V_129 )
{
struct V_78 * V_79 = F_24 ( V_120 ) ;
F_25 ( & V_79 -> V_2 -> V_130 ) ;
V_129 -> V_73 . integer . V_73 [ 0 ] = V_79 -> V_131 ;
F_26 ( & V_79 -> V_2 -> V_130 ) ;
return 0 ;
}
static int F_30 ( struct V_119 * V_120 ,
struct V_128 * V_129 )
{
struct V_78 * V_79 = F_24 ( V_120 ) ;
int V_41 = 0 ;
F_25 ( & V_79 -> V_2 -> V_130 ) ;
if ( V_79 -> V_131 != V_129 -> V_73 . integer . V_73 [ 0 ] ) {
V_41 = 1 ;
V_79 -> V_131 = V_129 -> V_73 . integer . V_73 [ 0 ] ;
F_10 ( V_79 -> V_2 , V_79 -> V_131 ) ;
}
F_26 ( & V_79 -> V_2 -> V_130 ) ;
return V_41 ;
}
static int F_31 ( struct V_119 * V_120 ,
struct V_128 * V_129 )
{
struct V_78 * V_79 = F_24 ( V_120 ) ;
F_25 ( & V_79 -> V_2 -> V_130 ) ;
V_129 -> V_73 . integer . V_73 [ 0 ] = V_79 -> V_132 ;
F_26 ( & V_79 -> V_2 -> V_130 ) ;
return 0 ;
}
static int F_32 ( struct V_119 * V_120 ,
struct V_128 * V_129 )
{
struct V_78 * V_79 = F_24 ( V_120 ) ;
int V_117 , V_41 = 0 ;
F_25 ( & V_79 -> V_2 -> V_130 ) ;
V_117 = ! ! V_129 -> V_73 . integer . V_73 [ 0 ] ;
if ( V_79 -> V_132 != V_117 ) {
F_21 ( V_79 -> V_2 , V_117 ) ;
V_79 -> V_132 = V_117 ;
V_41 = 1 ;
}
F_26 ( & V_79 -> V_2 -> V_130 ) ;
return V_41 ;
}
int F_33 ( struct V_78 * V_79 )
{
int V_43 ;
if ( ! V_79 -> V_2 -> V_27 )
return 0 ;
V_43 = F_34 ( V_79 -> V_133 , F_35 ( & V_134 ,
V_79 ) ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_34 ( V_79 -> V_133 , F_35 ( & V_135 ,
V_79 ) ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_34 ( V_79 -> V_133 , F_35 ( & V_136 ,
V_79 ) ) ;
return V_43 ;
}
