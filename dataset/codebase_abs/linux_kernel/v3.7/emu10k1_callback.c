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
unsigned long V_13 ;
int V_14 ;
V_7 = V_6 -> V_15 ;
F_3 ( & V_7 -> V_16 , V_13 ) ;
F_4 ( V_7 , V_6 , V_11 , 1 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_11 [ V_14 ] . V_17 >= 0 ) {
int V_18 ;
V_9 = & V_7 -> V_19 [ V_11 [ V_14 ] . V_17 ] ;
if ( ( V_18 = V_9 -> V_18 ) < 0 ) {
continue;
}
V_9 -> V_7 -> V_20 -- ;
V_9 -> V_18 = - 1 ;
V_9 -> V_21 = V_22 ;
F_5 ( & V_7 -> V_16 , V_13 ) ;
return V_18 ;
}
}
F_5 ( & V_7 -> V_16 , V_13 ) ;
return - V_23 ;
}
static void
F_6 ( struct V_8 * V_9 )
{
int V_24 ;
struct V_5 * V_6 ;
V_6 = V_9 -> V_6 ;
V_24 = 0x8000 | ( unsigned char ) V_9 -> V_25 . V_26 . V_27 ;
F_7 ( V_6 , V_28 , V_9 -> V_18 , V_24 ) ;
V_24 = 0x8000 | ( unsigned char ) V_9 -> V_25 . V_26 . V_29 | V_30 ;
F_7 ( V_6 , V_31 , V_9 -> V_18 , V_24 ) ;
}
static void
F_8 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
if ( F_9 ( ! V_9 ) )
return;
V_6 = V_9 -> V_6 ;
F_7 ( V_6 , V_31 , V_9 -> V_18 , 0x807f | V_30 ) ;
if ( V_9 -> V_32 ) {
struct V_33 * V_34 ;
V_34 = (struct V_33 * ) V_9 -> V_32 ;
if ( V_34 -> V_35 > 0 )
V_34 -> V_35 -- ;
}
}
static void
F_10 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
V_6 = V_9 -> V_6 ;
if ( V_6 && ( V_9 -> V_18 >= 0 ) ) {
F_7 ( V_6 , V_36 , V_9 -> V_18 , 0xff00 ) ;
F_7 ( V_6 , V_31 , V_9 -> V_18 , 0x807f | V_30 ) ;
F_7 ( V_6 , V_37 , V_9 -> V_18 , 0xffff ) ;
F_7 ( V_6 , V_38 , V_9 -> V_18 , 0xffff ) ;
F_11 ( V_6 , & V_6 -> V_19 [ V_9 -> V_18 ] ) ;
V_9 -> V_7 -> V_20 -- ;
V_9 -> V_18 = - 1 ;
}
}
static void
F_12 ( struct V_8 * V_9 , int V_39 )
{
struct V_5 * V_6 ;
V_6 = V_9 -> V_6 ;
if ( V_39 & V_40 )
F_7 ( V_6 , V_41 , V_9 -> V_18 , V_9 -> V_42 ) ;
if ( V_39 & V_43 )
F_7 ( V_6 , V_44 , V_9 -> V_18 , V_9 -> V_45 ) ;
if ( V_39 & V_46 ) {
F_7 ( V_6 , V_47 , V_9 -> V_18 , V_9 -> V_48 ) ;
F_7 ( V_6 , V_49 , V_9 -> V_18 , V_9 -> V_50 ) ;
}
if ( V_39 & V_51 )
F_13 ( V_6 , V_9 ) ;
if ( V_39 & V_52 )
F_7 ( V_6 , V_53 , V_9 -> V_18 , V_9 -> V_25 . V_26 . V_54 ) ;
if ( V_39 & V_55 )
F_14 ( V_6 , V_9 ) ;
if ( V_39 & V_56 )
F_15 ( V_6 , V_9 ) ;
}
static void
F_4 ( struct V_1 * V_7 , struct V_5 * V_6 ,
struct V_10 * V_11 , int V_57 )
{
struct V_8 * V_9 ;
struct V_10 * V_58 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
V_11 [ V_14 ] . time = ( unsigned int ) - 1 ;
V_11 [ V_14 ] . V_17 = - 1 ;
}
for ( V_14 = 0 ; V_14 < V_7 -> V_59 ; V_14 ++ ) {
int V_21 , V_60 ;
V_9 = & V_7 -> V_19 [ V_14 ] ;
V_21 = V_9 -> V_21 ;
if ( V_21 == V_22 ) {
if ( V_9 -> V_18 < 0 ) {
if ( V_57 )
continue;
V_58 = V_11 + V_61 ;
} else
V_58 = V_11 + V_62 ;
}
else if ( V_21 == V_63 ||
V_21 == V_64 ) {
V_58 = V_11 + V_65 ;
#if 1
V_60 = F_16 ( V_6 , V_66 , V_9 -> V_18 ) ;
if ( ! V_60 )
V_58 = V_11 + V_62 ;
#endif
}
else if ( V_21 == V_67 )
continue;
else if ( V_21 & V_68 )
V_58 = V_11 + V_69 ;
else
continue;
if ( V_58 != V_11 + V_62 && V_58 != V_11 + V_61 &&
( V_9 -> V_25 . V_70 & V_71 ) ) {
V_60 = F_16 ( V_6 , V_72 , V_9 -> V_18 ) ;
if ( V_60 >= V_9 -> V_25 . V_73 )
V_58 = V_11 + V_62 ;
}
if ( V_9 -> time < V_58 -> time ) {
V_58 -> time = V_9 -> time ;
V_58 -> V_17 = V_14 ;
}
}
}
static struct V_8 *
F_17 ( struct V_1 * V_7 , struct V_74 * V_75 )
{
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_10 V_11 [ V_12 ] ;
int V_14 ;
V_6 = V_7 -> V_6 ;
F_4 ( V_7 , V_6 , V_11 , 0 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( V_11 [ V_14 ] . V_17 >= 0 ) {
V_9 = & V_7 -> V_19 [ V_11 [ V_14 ] . V_17 ] ;
if ( V_9 -> V_18 < 0 ) {
struct V_76 * V_77 ;
if ( F_18 ( V_6 , V_78 , 1 , & V_77 ) < 0 || V_77 == NULL )
continue;
V_9 -> V_18 = V_77 -> V_79 ;
V_7 -> V_20 ++ ;
}
return V_9 ;
}
}
return NULL ;
}
static int
F_19 ( struct V_8 * V_9 )
{
unsigned int V_80 ;
int V_18 ;
unsigned int V_81 , V_82 ;
struct V_83 * V_84 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
V_6 = V_9 -> V_6 ;
V_18 = V_9 -> V_18 ;
if ( F_9 ( V_18 < 0 ) )
return - V_85 ;
V_84 = V_9 -> V_84 ;
V_34 = (struct V_33 * ) V_9 -> V_32 ;
if ( V_34 == NULL )
return - V_85 ;
V_34 -> V_35 ++ ;
if ( F_20 ( V_6 , V_34 ) < 0 ) {
return - V_23 ;
}
V_82 = F_21 ( V_34 ) >> 1 ;
V_9 -> V_25 . V_86 += V_82 ;
V_9 -> V_25 . V_87 += V_82 ;
V_9 -> V_25 . V_73 += V_82 ;
V_9 -> V_25 . V_88 += V_82 ;
if ( V_6 -> V_89 ) {
V_80 = V_90 | ( V_91 << 8 ) |
( V_92 << 16 ) | ( V_93 << 24 ) ;
F_7 ( V_6 , V_94 , V_18 , V_80 ) ;
} else {
V_80 = ( V_90 << 16 ) | ( V_91 << 20 ) |
( V_92 << 24 ) | ( V_93 << 28 ) ;
F_7 ( V_6 , V_95 , V_18 , V_80 ) ;
}
F_7 ( V_6 , V_31 , V_18 , 0x0000 ) ;
F_7 ( V_6 , V_37 , V_18 , 0x0000FFFF ) ;
F_7 ( V_6 , V_38 , V_18 , 0x0000FFFF ) ;
F_7 ( V_6 , V_96 , V_18 , 0 ) ;
F_7 ( V_6 , V_97 , V_18 , 0 ) ;
F_7 ( V_6 , V_44 , V_9 -> V_18 , V_9 -> V_45 ) ;
F_7 ( V_6 , V_98 , V_18 , V_9 -> V_25 . V_26 . V_99 ) ;
F_7 ( V_6 , V_100 , V_18 , V_9 -> V_25 . V_26 . V_101 ) ;
F_7 ( V_6 , V_28 , V_18 , V_9 -> V_25 . V_26 . V_102 ) ;
F_7 ( V_6 , V_103 , V_18 , V_9 -> V_25 . V_26 . V_104 ) ;
F_7 ( V_6 , V_105 , V_18 , V_9 -> V_25 . V_26 . V_106 ) ;
V_80 = ( unsigned int ) V_9 -> V_107 << 8 | ( unsigned char ) V_9 -> V_42 ;
F_7 ( V_6 , V_36 , V_9 -> V_18 , V_80 ) ;
F_7 ( V_6 , V_108 , V_18 , V_9 -> V_25 . V_26 . V_109 ) ;
F_7 ( V_6 , V_110 , V_18 , V_9 -> V_25 . V_26 . V_111 ) ;
F_7 ( V_6 , V_112 , V_18 , V_9 -> V_25 . V_26 . V_113 ) ;
F_13 ( V_6 , V_9 ) ;
F_7 ( V_6 , V_53 , V_9 -> V_18 , V_9 -> V_25 . V_26 . V_54 ) ;
F_14 ( V_6 , V_9 ) ;
V_80 = V_9 -> V_25 . V_26 . V_114 ;
V_80 += ( int ) V_9 -> V_84 -> V_115 [ V_116 ] * 9 / 10 ;
F_22 ( V_80 , 255 ) ;
V_81 = V_9 -> V_25 . V_73 ;
F_7 ( V_6 , V_117 , V_9 -> V_18 , ( V_80 << 24 ) | V_81 ) ;
V_81 = V_9 -> V_25 . V_88 ;
V_80 = V_9 -> V_25 . V_26 . V_118 ;
V_80 += ( int ) V_84 -> V_115 [ V_119 ] * 9 / 10 ;
F_22 ( V_80 , 255 ) ;
V_80 = ( V_80 << 24 ) | V_81 ;
F_7 ( V_6 , V_120 , V_18 , V_80 ) ;
F_7 ( V_6 , V_121 , V_18 , 0 ) ;
F_7 ( V_6 , V_122 , V_18 , 0 ) ;
V_80 = ( V_6 -> V_123 . V_81 << 1 ) | V_124 ;
F_7 ( V_6 , V_125 , V_18 , V_80 ) ;
F_7 ( V_6 , V_126 , V_18 , V_80 ) ;
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
temp = ((unsigned int)hw->silent_page.addr << 1) | MAP_PTI_MASK;
snd_emu10k1_ptr_write(hw, MAPA, ch, temp);
snd_emu10k1_ptr_write(hw, MAPB, ch, temp);
val -= 4;
val <<= 25;
val |= 0x1c << 16;
snd_emu10k1_ptr_write(hw, CCR, ch, val);
}
#endif
V_81 = V_9 -> V_25 . V_86 ;
V_80 = V_9 -> V_25 . V_26 . V_127 ;
V_80 = ( V_80 << 28 ) | V_81 ;
if ( V_9 -> V_45 < 0xe400 )
V_80 |= V_128 ;
else {
unsigned int V_129 = ( V_9 -> V_45 - 0xe000 ) >> 10 ;
V_80 |= V_129 << 25 ;
}
if ( V_9 -> V_25 . V_70 & V_130 )
V_80 |= V_131 ;
F_7 ( V_6 , V_132 , V_18 , V_80 ) ;
V_80 = ( unsigned int ) V_9 -> V_133 << 16 ;
F_7 ( V_6 , V_37 , V_18 , V_80 | V_9 -> V_134 ) ;
F_7 ( V_6 , V_38 , V_18 , V_80 | 0xff00 ) ;
return 0 ;
}
static void
F_23 ( struct V_8 * V_9 )
{
unsigned int V_80 , V_135 ;
struct V_5 * V_6 ;
struct V_33 * V_34 ;
V_6 = V_9 -> V_6 ;
V_34 = (struct V_33 * ) V_9 -> V_32 ;
if ( ! V_34 || V_34 -> V_136 < 0 )
return;
#if 0
ptarget = (unsigned int)vp->ptarget << 16;
#else
V_135 = F_24 ( V_9 -> V_45 ) ;
#endif
V_80 = V_135 | ( V_9 -> V_48 << 8 ) | V_9 -> V_50 ;
F_7 ( V_6 , V_96 , V_9 -> V_18 , V_80 ) ;
F_7 ( V_6 , V_97 , V_9 -> V_18 , V_135 ) ;
F_7 ( V_6 , V_31 , V_9 -> V_18 , V_9 -> V_25 . V_26 . V_137 | V_30 ) ;
}
static void
F_13 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
unsigned short V_138 ;
short V_139 ;
unsigned char V_140 ;
int V_141 ;
V_139 = ( char ) ( V_9 -> V_25 . V_26 . V_138 >> 8 ) ;
V_140 = ( V_9 -> V_25 . V_26 . V_138 & 0xff ) ;
V_141 = V_9 -> V_84 -> V_142 + V_9 -> V_84 -> V_143 ;
V_139 += ( V_144 * V_141 ) / 1200 ;
F_25 ( V_139 , - 128 , 127 ) ;
V_138 = ( ( unsigned char ) V_139 << 8 ) | V_140 ;
F_7 ( V_6 , V_145 , V_9 -> V_18 , V_138 ) ;
}
static void
F_14 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
unsigned short V_146 ;
short V_139 ;
unsigned char V_147 ;
int V_141 ;
V_139 = ( char ) ( V_9 -> V_25 . V_26 . V_146 >> 8 ) ;
V_147 = V_9 -> V_25 . V_26 . V_146 & 0xff ;
V_141 = V_9 -> V_84 -> V_142 + V_9 -> V_84 -> V_143 ;
V_139 += ( V_144 * V_141 ) / 1200 ;
F_25 ( V_139 , - 128 , 127 ) ;
V_146 = ( ( unsigned char ) V_139 << 8 ) | V_147 ;
F_7 ( V_6 , V_148 , V_9 -> V_18 , V_146 ) ;
}
static void
F_15 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
unsigned int V_60 ;
V_60 = F_16 ( V_6 , V_132 , V_9 -> V_18 ) & ~ V_149 ;
V_60 |= ( V_9 -> V_25 . V_26 . V_127 << 28 ) ;
F_7 ( V_6 , V_132 , V_9 -> V_18 , V_60 ) ;
}
