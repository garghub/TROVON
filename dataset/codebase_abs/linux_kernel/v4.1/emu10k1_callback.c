void
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
}
int
F_2 ( struct V_5 * V_6 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 [ V_12 ] ;
int V_13 ;
V_7 = V_6 -> V_14 ;
F_3 ( V_7 , V_6 , V_11 , 1 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_11 [ V_13 ] . V_15 >= 0 ) {
int V_16 ;
V_9 = & V_7 -> V_17 [ V_11 [ V_13 ] . V_15 ] ;
if ( ( V_16 = V_9 -> V_16 ) < 0 ) {
continue;
}
V_9 -> V_7 -> V_18 -- ;
V_9 -> V_16 = - 1 ;
V_9 -> V_19 = V_20 ;
return V_16 ;
}
}
return - V_21 ;
}
static void
F_4 ( struct V_8 * V_9 )
{
int V_22 ;
struct V_5 * V_6 ;
V_6 = V_9 -> V_6 ;
V_22 = 0x8000 | ( unsigned char ) V_9 -> V_23 . V_24 . V_25 ;
F_5 ( V_6 , V_26 , V_9 -> V_16 , V_22 ) ;
V_22 = 0x8000 | ( unsigned char ) V_9 -> V_23 . V_24 . V_27 | V_28 ;
F_5 ( V_6 , V_29 , V_9 -> V_16 , V_22 ) ;
}
static void
F_6 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
if ( F_7 ( ! V_9 ) )
return;
V_6 = V_9 -> V_6 ;
F_5 ( V_6 , V_29 , V_9 -> V_16 , 0x807f | V_28 ) ;
if ( V_9 -> V_30 ) {
struct V_31 * V_32 ;
V_32 = (struct V_31 * ) V_9 -> V_30 ;
if ( V_32 -> V_33 > 0 )
V_32 -> V_33 -- ;
}
}
static void
F_8 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
V_6 = V_9 -> V_6 ;
if ( V_6 && ( V_9 -> V_16 >= 0 ) ) {
F_5 ( V_6 , V_34 , V_9 -> V_16 , 0xff00 ) ;
F_5 ( V_6 , V_29 , V_9 -> V_16 , 0x807f | V_28 ) ;
F_5 ( V_6 , V_35 , V_9 -> V_16 , 0xffff ) ;
F_5 ( V_6 , V_36 , V_9 -> V_16 , 0xffff ) ;
F_9 ( V_6 , & V_6 -> V_17 [ V_9 -> V_16 ] ) ;
V_9 -> V_7 -> V_18 -- ;
V_9 -> V_16 = - 1 ;
}
}
static void
F_10 ( struct V_8 * V_9 , int V_37 )
{
struct V_5 * V_6 ;
V_6 = V_9 -> V_6 ;
if ( V_37 & V_38 )
F_5 ( V_6 , V_39 , V_9 -> V_16 , V_9 -> V_40 ) ;
if ( V_37 & V_41 )
F_5 ( V_6 , V_42 , V_9 -> V_16 , V_9 -> V_43 ) ;
if ( V_37 & V_44 ) {
F_5 ( V_6 , V_45 , V_9 -> V_16 , V_9 -> V_46 ) ;
F_5 ( V_6 , V_47 , V_9 -> V_16 , V_9 -> V_48 ) ;
}
if ( V_37 & V_49 )
F_11 ( V_6 , V_9 ) ;
if ( V_37 & V_50 )
F_5 ( V_6 , V_51 , V_9 -> V_16 , V_9 -> V_23 . V_24 . V_52 ) ;
if ( V_37 & V_53 )
F_12 ( V_6 , V_9 ) ;
if ( V_37 & V_54 )
F_13 ( V_6 , V_9 ) ;
}
static void
F_3 ( struct V_1 * V_7 , struct V_5 * V_6 ,
struct V_10 * V_11 , int V_55 )
{
struct V_8 * V_9 ;
struct V_10 * V_56 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_11 [ V_13 ] . time = ( unsigned int ) - 1 ;
V_11 [ V_13 ] . V_15 = - 1 ;
}
for ( V_13 = 0 ; V_13 < V_7 -> V_57 ; V_13 ++ ) {
int V_19 , V_58 ;
V_9 = & V_7 -> V_17 [ V_13 ] ;
V_19 = V_9 -> V_19 ;
if ( V_19 == V_20 ) {
if ( V_9 -> V_16 < 0 ) {
if ( V_55 )
continue;
V_56 = V_11 + V_59 ;
} else
V_56 = V_11 + V_60 ;
}
else if ( V_19 == V_61 ||
V_19 == V_62 ) {
V_56 = V_11 + V_63 ;
#if 1
V_58 = F_14 ( V_6 , V_64 , V_9 -> V_16 ) ;
if ( ! V_58 )
V_56 = V_11 + V_60 ;
#endif
}
else if ( V_19 == V_65 )
continue;
else if ( V_19 & V_66 )
V_56 = V_11 + V_67 ;
else
continue;
if ( V_56 != V_11 + V_60 && V_56 != V_11 + V_59 &&
( V_9 -> V_23 . V_68 & V_69 ) ) {
V_58 = F_14 ( V_6 , V_70 , V_9 -> V_16 ) ;
if ( V_58 >= V_9 -> V_23 . V_71 )
V_56 = V_11 + V_60 ;
}
if ( V_9 -> time < V_56 -> time ) {
V_56 -> time = V_9 -> time ;
V_56 -> V_15 = V_13 ;
}
}
}
static struct V_8 *
F_15 ( struct V_1 * V_7 , struct V_72 * V_73 )
{
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_10 V_11 [ V_12 ] ;
int V_13 ;
V_6 = V_7 -> V_6 ;
F_3 ( V_7 , V_6 , V_11 , 0 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_11 [ V_13 ] . V_15 >= 0 ) {
V_9 = & V_7 -> V_17 [ V_11 [ V_13 ] . V_15 ] ;
if ( V_9 -> V_16 < 0 ) {
struct V_74 * V_75 ;
if ( F_16 ( V_6 , V_76 , 1 , & V_75 ) < 0 || V_75 == NULL )
continue;
V_9 -> V_16 = V_75 -> V_77 ;
V_7 -> V_18 ++ ;
}
return V_9 ;
}
}
return NULL ;
}
static int
F_17 ( struct V_8 * V_9 )
{
unsigned int V_78 ;
int V_16 ;
unsigned int V_79 , V_80 ;
struct V_81 * V_82 ;
struct V_5 * V_6 ;
struct V_31 * V_32 ;
V_6 = V_9 -> V_6 ;
V_16 = V_9 -> V_16 ;
if ( F_7 ( V_16 < 0 ) )
return - V_83 ;
V_82 = V_9 -> V_82 ;
V_32 = (struct V_31 * ) V_9 -> V_30 ;
if ( V_32 == NULL )
return - V_83 ;
V_32 -> V_33 ++ ;
if ( F_18 ( V_6 , V_32 ) < 0 ) {
return - V_21 ;
}
V_80 = F_19 ( V_32 ) >> 1 ;
V_9 -> V_23 . V_84 += V_80 ;
V_9 -> V_23 . V_85 += V_80 ;
V_9 -> V_23 . V_71 += V_80 ;
V_9 -> V_23 . V_86 += V_80 ;
if ( V_6 -> V_87 ) {
V_78 = V_88 | ( V_89 << 8 ) |
( V_90 << 16 ) | ( V_91 << 24 ) ;
F_5 ( V_6 , V_92 , V_16 , V_78 ) ;
} else {
V_78 = ( V_88 << 16 ) | ( V_89 << 20 ) |
( V_90 << 24 ) | ( V_91 << 28 ) ;
F_5 ( V_6 , V_93 , V_16 , V_78 ) ;
}
F_5 ( V_6 , V_29 , V_16 , 0x0000 ) ;
F_5 ( V_6 , V_35 , V_16 , 0x0000FFFF ) ;
F_5 ( V_6 , V_36 , V_16 , 0x0000FFFF ) ;
F_5 ( V_6 , V_94 , V_16 , 0 ) ;
F_5 ( V_6 , V_95 , V_16 , 0 ) ;
F_5 ( V_6 , V_42 , V_9 -> V_16 , V_9 -> V_43 ) ;
F_5 ( V_6 , V_96 , V_16 , V_9 -> V_23 . V_24 . V_97 ) ;
F_5 ( V_6 , V_98 , V_16 , V_9 -> V_23 . V_24 . V_99 ) ;
F_5 ( V_6 , V_26 , V_16 , V_9 -> V_23 . V_24 . V_100 ) ;
F_5 ( V_6 , V_101 , V_16 , V_9 -> V_23 . V_24 . V_102 ) ;
F_5 ( V_6 , V_103 , V_16 , V_9 -> V_23 . V_24 . V_104 ) ;
V_78 = ( unsigned int ) V_9 -> V_105 << 8 | ( unsigned char ) V_9 -> V_40 ;
F_5 ( V_6 , V_34 , V_9 -> V_16 , V_78 ) ;
F_5 ( V_6 , V_106 , V_16 , V_9 -> V_23 . V_24 . V_107 ) ;
F_5 ( V_6 , V_108 , V_16 , V_9 -> V_23 . V_24 . V_109 ) ;
F_5 ( V_6 , V_110 , V_16 , V_9 -> V_23 . V_24 . V_111 ) ;
F_11 ( V_6 , V_9 ) ;
F_5 ( V_6 , V_51 , V_9 -> V_16 , V_9 -> V_23 . V_24 . V_52 ) ;
F_12 ( V_6 , V_9 ) ;
V_78 = V_9 -> V_23 . V_24 . V_112 ;
V_78 += ( int ) V_9 -> V_82 -> V_113 [ V_114 ] * 9 / 10 ;
F_20 ( V_78 , 255 ) ;
V_79 = V_9 -> V_23 . V_71 ;
F_5 ( V_6 , V_115 , V_9 -> V_16 , ( V_78 << 24 ) | V_79 ) ;
V_79 = V_9 -> V_23 . V_86 ;
V_78 = V_9 -> V_23 . V_24 . V_116 ;
V_78 += ( int ) V_82 -> V_113 [ V_117 ] * 9 / 10 ;
F_20 ( V_78 , 255 ) ;
V_78 = ( V_78 << 24 ) | V_79 ;
F_5 ( V_6 , V_118 , V_16 , V_78 ) ;
F_5 ( V_6 , V_119 , V_16 , 0 ) ;
F_5 ( V_6 , V_120 , V_16 , 0 ) ;
V_78 = ( V_6 -> V_121 . V_79 << V_6 -> V_122 ) | ( V_6 -> V_122 ? V_123 : V_124 ) ;
F_5 ( V_6 , V_125 , V_16 , V_78 ) ;
F_5 ( V_6 , V_126 , V_16 , V_78 ) ;
#if 0
{
unsigned int val, sample;
val = 32;
if (vp->reg.sample_mode & SNDRV_SFNT_SAMPLE_8BITS)
sample = 0x80808080;
else {
sample = 0;
val *= 2;
}
snd_emu10k1_ptr_write(hw, CCR, ch, 0x1c << 16);
snd_emu10k1_ptr_write(hw, CDE, ch, sample);
snd_emu10k1_ptr_write(hw, CDF, ch, sample);
temp = ((unsigned int)hw->silent_page.addr << hw_address_mode) | (hw->address_mode ? MAP_PTI_MASK1 : MAP_PTI_MASK0);
snd_emu10k1_ptr_write(hw, MAPA, ch, temp);
snd_emu10k1_ptr_write(hw, MAPB, ch, temp);
val -= 4;
val <<= 25;
val |= 0x1c << 16;
snd_emu10k1_ptr_write(hw, CCR, ch, val);
}
#endif
V_79 = V_9 -> V_23 . V_84 ;
V_78 = V_9 -> V_23 . V_24 . V_127 ;
V_78 = ( V_78 << 28 ) | V_79 ;
if ( V_9 -> V_43 < 0xe400 )
V_78 |= V_128 ;
else {
unsigned int V_129 = ( V_9 -> V_43 - 0xe000 ) >> 10 ;
V_78 |= V_129 << 25 ;
}
if ( V_9 -> V_23 . V_68 & V_130 )
V_78 |= V_131 ;
F_5 ( V_6 , V_132 , V_16 , V_78 ) ;
V_78 = ( unsigned int ) V_9 -> V_133 << 16 ;
F_5 ( V_6 , V_35 , V_16 , V_78 | V_9 -> V_134 ) ;
F_5 ( V_6 , V_36 , V_16 , V_78 | 0xff00 ) ;
return 0 ;
}
static void
F_21 ( struct V_8 * V_9 )
{
unsigned int V_78 , V_135 ;
struct V_5 * V_6 ;
struct V_31 * V_32 ;
V_6 = V_9 -> V_6 ;
V_32 = (struct V_31 * ) V_9 -> V_30 ;
if ( ! V_32 || V_32 -> V_136 < 0 )
return;
#if 0
ptarget = (unsigned int)vp->ptarget << 16;
#else
V_135 = F_22 ( V_9 -> V_43 ) ;
#endif
V_78 = V_135 | ( V_9 -> V_46 << 8 ) | V_9 -> V_48 ;
F_5 ( V_6 , V_94 , V_9 -> V_16 , V_78 ) ;
F_5 ( V_6 , V_95 , V_9 -> V_16 , V_135 ) ;
F_5 ( V_6 , V_29 , V_9 -> V_16 , V_9 -> V_23 . V_24 . V_137 | V_28 ) ;
}
static void
F_11 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
unsigned short V_138 ;
short V_139 ;
unsigned char V_140 ;
int V_141 ;
V_139 = ( char ) ( V_9 -> V_23 . V_24 . V_138 >> 8 ) ;
V_140 = ( V_9 -> V_23 . V_24 . V_138 & 0xff ) ;
V_141 = V_9 -> V_82 -> V_142 + V_9 -> V_82 -> V_143 ;
V_139 += ( V_144 * V_141 ) / 1200 ;
F_23 ( V_139 , - 128 , 127 ) ;
V_138 = ( ( unsigned char ) V_139 << 8 ) | V_140 ;
F_5 ( V_6 , V_145 , V_9 -> V_16 , V_138 ) ;
}
static void
F_12 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
unsigned short V_146 ;
short V_139 ;
unsigned char V_147 ;
int V_141 ;
V_139 = ( char ) ( V_9 -> V_23 . V_24 . V_146 >> 8 ) ;
V_147 = V_9 -> V_23 . V_24 . V_146 & 0xff ;
V_141 = V_9 -> V_82 -> V_142 + V_9 -> V_82 -> V_143 ;
V_139 += ( V_144 * V_141 ) / 1200 ;
F_23 ( V_139 , - 128 , 127 ) ;
V_146 = ( ( unsigned char ) V_139 << 8 ) | V_147 ;
F_5 ( V_6 , V_148 , V_9 -> V_16 , V_146 ) ;
}
static void
F_13 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
unsigned int V_58 ;
V_58 = F_14 ( V_6 , V_132 , V_9 -> V_16 ) & ~ V_149 ;
V_58 |= ( V_9 -> V_23 . V_24 . V_127 << 28 ) ;
F_5 ( V_6 , V_132 , V_9 -> V_16 , V_58 ) ;
}
