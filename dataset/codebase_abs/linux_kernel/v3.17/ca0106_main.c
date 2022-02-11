unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
unsigned long V_5 ;
unsigned int V_6 , V_7 ;
V_6 = ( V_3 << 16 ) | V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_3 ( V_6 , V_2 -> V_9 + V_10 ) ;
V_7 = F_4 ( V_2 -> V_9 + V_11 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
return V_7 ;
}
void F_6 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
unsigned int V_12 )
{
unsigned int V_6 ;
unsigned long V_5 ;
V_6 = ( V_3 << 16 ) | V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_3 ( V_6 , V_2 -> V_9 + V_10 ) ;
F_3 ( V_12 , V_2 -> V_9 + V_11 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
int F_7 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
unsigned int V_13 , V_14 ;
unsigned int V_3 , V_15 ;
int V_16 , V_17 ;
V_3 = V_18 ;
if ( V_12 > 0xffff )
return 1 ;
V_15 = F_1 ( V_2 , V_3 , 0 ) ;
V_13 = ( V_15 & ~ 0x3ffff ) | 0x20000 ;
V_14 = V_13 | 0x10000 ;
F_6 ( V_2 , V_3 , 0 , V_13 | V_12 ) ;
V_15 = F_1 ( V_2 , V_3 , 0 ) ;
F_6 ( V_2 , V_3 , 0 , V_14 | V_12 ) ;
V_17 = 1 ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
F_8 ( 10 ) ;
V_15 = F_1 ( V_2 , V_3 , 0 ) ;
if ( ! ( V_15 & 0x10000 ) ) {
V_17 = 0 ;
break;
}
}
if ( V_17 )
return 1 ;
F_6 ( V_2 , V_3 , 0 , V_13 | V_12 ) ;
V_15 = F_1 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_19 )
{
T_1 V_15 ;
int V_20 = 0 ;
int V_21 ;
int V_22 ;
if ( ( V_3 > 0x7f ) || ( V_19 > 0x1ff ) ) {
F_10 ( V_2 -> V_23 -> V_24 , L_1 ) ;
return - V_25 ;
}
V_15 = V_3 << 25 | V_19 << 16 ;
F_6 ( V_2 , V_26 , 0 , V_15 ) ;
for ( V_22 = 0 ; V_22 < 10 ; V_22 ++ ) {
V_15 = 0 ;
V_15 = V_15 | ( V_27 | V_28 | V_29 ) ;
F_6 ( V_2 , V_30 , 0 , V_15 ) ;
while ( 1 ) {
V_21 = F_1 ( V_2 , V_30 , 0 ) ;
V_20 ++ ;
if ( ( V_21 & V_28 ) == 0 )
break;
if ( V_20 > 1000 )
break;
}
if ( ( V_21 & V_31 ) == 0 )
break;
}
if ( V_22 == 10 ) {
F_10 ( V_2 -> V_23 -> V_24 , L_2 ) ;
return - V_25 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_32 )
{
unsigned long V_5 ;
unsigned int V_33 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_33 = F_4 ( V_2 -> V_9 + V_34 ) | V_32 ;
F_3 ( V_33 , V_2 -> V_9 + V_34 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_32 )
{
unsigned long V_5 ;
unsigned int V_33 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_33 = F_4 ( V_2 -> V_9 + V_34 ) & ~ V_32 ;
F_3 ( V_33 , V_2 -> V_9 + V_34 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_13 ( struct V_35 * V_36 )
{
F_14 ( V_36 -> V_37 ) ;
}
static void F_15 ( struct V_1 * V_38 , int V_39 )
{
if ( V_38 -> V_40 [ V_39 ] != V_38 -> V_41 [ V_39 ] ) {
V_38 -> V_40 [ V_39 ] = V_38 -> V_41 [ V_39 ] ;
F_6 ( V_38 , V_42 + V_39 , 0 ,
V_38 -> V_40 [ V_39 ] ) ;
}
}
static int F_16 ( struct V_1 * V_38 ,
struct V_43 * V_44 ,
int V_45 )
{
switch ( V_45 ) {
case V_46 :
return ( V_44 -> V_47 & 0xf000 ) >> ( 4 * 3 ) ;
case V_48 :
return ( V_44 -> V_47 & 0x0f00 ) >> ( 4 * 2 ) ;
case V_49 :
return ( V_44 -> V_47 & 0x00f0 ) >> ( 4 * 1 ) ;
case V_50 :
return ( V_44 -> V_47 & 0x000f ) >> ( 4 * 0 ) ;
default:
F_17 ( V_38 -> V_23 -> V_24 , L_3 ,
V_45 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_38 , int V_45 ,
int V_51 )
{
if ( V_38 -> V_44 -> V_47 ) {
const int V_52 = F_16 ( V_38 , V_38 -> V_44 ,
V_45 ) ;
const int V_3 = V_53 [ V_52 ] ;
const int V_54 = V_55 [ V_52 ] ;
if ( V_51 )
V_38 -> V_56 [ V_3 ] &= ~ V_54 ;
else
V_38 -> V_56 [ V_3 ] |= V_54 ;
return F_7 ( V_38 , V_38 -> V_56 [ V_3 ] ) ;
}
return 0 ;
}
static int F_19 ( struct V_57 * V_58 ,
int V_45 )
{
struct V_1 * V_38 = F_20 ( V_58 ) ;
struct V_59 * V_60 = & ( V_38 -> V_61 [ V_45 ] ) ;
struct V_62 * V_63 ;
struct V_35 * V_36 = V_58 -> V_36 ;
int V_64 ;
V_63 = F_21 ( sizeof( * V_63 ) , V_65 ) ;
if ( V_63 == NULL )
return - V_66 ;
V_63 -> V_2 = V_38 ;
V_63 -> V_58 = V_58 ;
V_63 -> V_45 = V_45 ;
V_36 -> V_37 = V_63 ;
V_36 -> V_67 = F_13 ;
V_36 -> V_68 = V_69 ;
V_60 -> V_2 = V_38 ;
V_60 -> V_70 = V_45 ;
V_60 -> V_71 = 1 ;
V_60 -> V_63 = V_63 ;
if ( ( V_64 = F_22 ( V_36 , V_72 ) ) < 0 )
return V_64 ;
if ( ( V_64 = F_23 ( V_36 , 0 , V_73 , 64 ) ) < 0 )
return V_64 ;
F_24 ( V_58 ) ;
if ( V_45 != V_46 ) {
V_64 = F_18 ( V_38 , V_45 , 1 ) ;
if ( V_64 < 0 )
return V_64 ;
}
F_15 ( V_38 , V_45 ) ;
return 0 ;
}
static int F_25 ( struct V_57 * V_58 )
{
struct V_1 * V_38 = F_20 ( V_58 ) ;
struct V_35 * V_36 = V_58 -> V_36 ;
struct V_62 * V_63 = V_36 -> V_37 ;
V_38 -> V_61 [ V_63 -> V_45 ] . V_71 = 0 ;
F_15 ( V_38 , V_63 -> V_45 ) ;
if ( V_63 -> V_45 != V_46 ) {
int V_64 ;
V_64 = F_18 ( V_38 , V_63 -> V_45 , 0 ) ;
if ( V_64 < 0 )
return V_64 ;
}
return 0 ;
}
static int F_26 ( struct V_57 * V_58 )
{
return F_19 ( V_58 , V_46 ) ;
}
static int F_27 ( struct V_57 * V_58 )
{
return F_19 ( V_58 , V_49 ) ;
}
static int F_28 ( struct V_57 * V_58 )
{
return F_19 ( V_58 , V_50 ) ;
}
static int F_29 ( struct V_57 * V_58 )
{
return F_19 ( V_58 , V_48 ) ;
}
static int F_30 ( struct V_57 * V_58 ,
int V_45 )
{
struct V_1 * V_38 = F_20 ( V_58 ) ;
struct V_59 * V_60 = & ( V_38 -> V_74 [ V_45 ] ) ;
struct V_62 * V_63 ;
struct V_35 * V_36 = V_58 -> V_36 ;
int V_64 ;
V_63 = F_21 ( sizeof( * V_63 ) , V_65 ) ;
if ( V_63 == NULL ) {
F_10 ( V_38 -> V_23 -> V_24 ,
L_4 ) ;
return - V_66 ;
}
V_63 -> V_2 = V_38 ;
V_63 -> V_58 = V_58 ;
V_63 -> V_45 = V_45 ;
V_36 -> V_37 = V_63 ;
V_36 -> V_67 = F_13 ;
V_36 -> V_68 = V_75 ;
V_60 -> V_2 = V_38 ;
V_60 -> V_70 = V_45 ;
V_60 -> V_71 = 1 ;
V_60 -> V_63 = V_63 ;
if ( ( V_64 = F_22 ( V_36 , V_72 ) ) < 0 )
return V_64 ;
if ( ( V_64 = F_23 ( V_36 , 0 , V_73 , 64 ) ) < 0 )
return V_64 ;
return 0 ;
}
static int F_31 ( struct V_57 * V_58 )
{
struct V_1 * V_38 = F_20 ( V_58 ) ;
struct V_35 * V_36 = V_58 -> V_36 ;
struct V_62 * V_63 = V_36 -> V_37 ;
V_38 -> V_74 [ V_63 -> V_45 ] . V_71 = 0 ;
return 0 ;
}
static int F_32 ( struct V_57 * V_58 )
{
return F_30 ( V_58 , 0 ) ;
}
static int F_33 ( struct V_57 * V_58 )
{
return F_30 ( V_58 , 1 ) ;
}
static int F_34 ( struct V_57 * V_58 )
{
return F_30 ( V_58 , 2 ) ;
}
static int F_35 ( struct V_57 * V_58 )
{
return F_30 ( V_58 , 3 ) ;
}
static int F_36 ( struct V_57 * V_58 ,
struct V_76 * V_77 )
{
return F_37 ( V_58 ,
F_38 ( V_77 ) ) ;
}
static int F_39 ( struct V_57 * V_58 )
{
return F_40 ( V_58 ) ;
}
static int F_41 ( struct V_57 * V_58 ,
struct V_76 * V_77 )
{
return F_37 ( V_58 ,
F_38 ( V_77 ) ) ;
}
static int F_42 ( struct V_57 * V_58 )
{
return F_40 ( V_58 ) ;
}
static int F_43 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_20 ( V_58 ) ;
struct V_35 * V_36 = V_58 -> V_36 ;
struct V_62 * V_63 = V_36 -> V_37 ;
int V_60 = V_63 -> V_45 ;
T_1 * V_78 = ( T_1 * ) ( V_2 -> V_79 . V_80 + ( 8 * 16 * V_60 ) ) ;
T_1 V_81 = F_44 ( V_36 , V_36 -> V_82 ) ;
T_1 V_83 = V_84 ;
T_1 V_85 = 0x00000000 ;
T_1 V_86 ;
T_1 V_87 = 0x30000 << ( V_60 << 1 ) ;
T_1 V_88 = 0 ;
T_1 V_89 ;
T_1 V_90 = 0x03030000 ;
T_1 V_91 = 0 ;
T_1 V_92 ;
int V_93 ;
#if 0
dev_dbg(emu->card->dev,
"prepare:channel_number=%d, rate=%d, format=0x%x, "
"channels=%d, buffer_size=%ld, period_size=%ld, "
"periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format,
runtime->channels, runtime->buffer_size,
runtime->period_size, runtime->periods,
frames_to_bytes(runtime, 1));
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->buffer.addr, emu->buffer.area, emu->buffer.bytes);
#endif
switch ( V_36 -> V_94 ) {
case 44100 :
V_88 = 0x10000 << ( V_60 << 1 ) ;
V_91 = 0x01010000 ;
break;
case 48000 :
V_88 = 0 ;
V_91 = 0 ;
break;
case 96000 :
V_88 = 0x20000 << ( V_60 << 1 ) ;
V_91 = 0x02020000 ;
break;
case 192000 :
V_88 = 0x30000 << ( V_60 << 1 ) ;
V_91 = 0x03030000 ;
break;
default:
V_88 = 0 ;
V_91 = 0 ;
break;
}
switch ( V_36 -> V_95 ) {
case V_96 :
V_85 = 0 ;
break;
case V_97 :
V_85 = V_84 ;
break;
default:
V_85 = 0 ;
break;
}
V_86 = F_4 ( V_2 -> V_9 + V_98 ) ;
V_86 = ( V_86 & ~ V_83 ) | V_85 ;
F_3 ( V_86 , V_2 -> V_9 + V_98 ) ;
V_89 = F_1 ( V_2 , 0x40 , 0 ) ;
V_89 = ( V_89 & ~ V_87 ) | V_88 ;
F_6 ( V_2 , 0x40 , 0 , V_89 ) ;
V_92 = F_1 ( V_2 , 0x71 , 0 ) ;
V_92 = ( V_92 & ~ V_90 ) | V_91 ;
F_6 ( V_2 , 0x71 , 0 , V_92 ) ;
for( V_93 = 0 ; V_93 < V_36 -> V_99 ; V_93 ++ ) {
V_78 [ V_93 * 2 ] = V_36 -> V_100 + ( V_93 * V_81 ) ;
V_78 [ V_93 * 2 + 1 ] = V_81 << 16 ;
}
F_6 ( V_2 , V_101 , V_60 , V_2 -> V_79 . V_102 + ( 8 * 16 * V_60 ) ) ;
F_6 ( V_2 , V_103 , V_60 , ( V_36 -> V_99 - 1 ) << 19 ) ;
F_6 ( V_2 , V_104 , V_60 , 0 ) ;
F_6 ( V_2 , V_105 , V_60 , V_36 -> V_100 ) ;
F_6 ( V_2 , V_106 , V_60 , F_44 ( V_36 , V_36 -> V_82 ) << 16 ) ;
F_6 ( V_2 , V_106 , V_60 , 0 ) ;
F_6 ( V_2 , V_107 , V_60 , 0 ) ;
F_6 ( V_2 , 0x07 , V_60 , 0x0 ) ;
F_6 ( V_2 , 0x08 , V_60 , 0 ) ;
F_6 ( V_2 , V_108 , 0x0 , 0x0 ) ;
#if 0
snd_ca0106_ptr_write(emu, SPCS0, 0,
SPCS_CLKACCY_1000PPM | SPCS_SAMPLERATE_48 |
SPCS_CHANNELNUM_LEFT | SPCS_SOURCENUM_UNSPEC |
SPCS_GENERATIONSTATUS | 0x00001200 |
0x00000000 | SPCS_EMPHASIS_NONE | SPCS_COPYRIGHT );
#endif
return 0 ;
}
static int F_45 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_20 ( V_58 ) ;
struct V_35 * V_36 = V_58 -> V_36 ;
struct V_62 * V_63 = V_36 -> V_37 ;
int V_60 = V_63 -> V_45 ;
T_1 V_83 = V_109 ;
T_1 V_85 = 0x00000000 ;
T_1 V_86 ;
T_1 V_110 = 0x2 ;
T_1 V_90 = 0x0000c000 ;
T_1 V_91 = 0 ;
T_1 V_92 ;
#if 0
dev_dbg(emu->card->dev,
"prepare:channel_number=%d, rate=%d, format=0x%x, "
"channels=%d, buffer_size=%ld, period_size=%ld, "
"periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format,
runtime->channels, runtime->buffer_size,
runtime->period_size, runtime->periods,
frames_to_bytes(runtime, 1));
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
dev_dbg(emu->card->dev,
"dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->buffer.addr, emu->buffer.area, emu->buffer.bytes);
#endif
switch ( V_36 -> V_94 ) {
case 44100 :
V_91 = 0x00004000 ;
break;
case 48000 :
V_91 = 0 ;
break;
case 96000 :
V_91 = 0x00008000 ;
V_110 = 0xa ;
break;
case 192000 :
V_91 = 0x0000c000 ;
V_110 = 0xa ;
break;
default:
V_91 = 0 ;
break;
}
switch ( V_36 -> V_95 ) {
case V_96 :
V_85 = 0 ;
break;
case V_97 :
V_85 = V_109 ;
break;
default:
V_85 = 0 ;
break;
}
V_86 = F_4 ( V_2 -> V_9 + V_98 ) ;
V_86 = ( V_86 & ~ V_83 ) | V_85 ;
F_3 ( V_86 , V_2 -> V_9 + V_98 ) ;
V_92 = F_1 ( V_2 , 0x71 , 0 ) ;
V_92 = ( V_92 & ~ V_90 ) | V_91 ;
F_6 ( V_2 , 0x71 , 0 , V_92 ) ;
if ( V_2 -> V_44 -> V_111 == 1 ) {
F_9 ( V_2 , V_112 , V_110 ) ;
}
F_6 ( V_2 , 0x13 , V_60 , 0 ) ;
F_6 ( V_2 , V_113 , V_60 , V_36 -> V_100 ) ;
F_6 ( V_2 , V_114 , V_60 , F_44 ( V_36 , V_36 -> V_115 ) << 16 ) ;
F_6 ( V_2 , V_116 , V_60 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_57 * V_58 ,
int V_117 )
{
struct V_1 * V_2 = F_20 ( V_58 ) ;
struct V_35 * V_36 ;
struct V_62 * V_63 ;
int V_60 ;
int V_17 = 0 ;
struct V_57 * V_118 ;
T_1 V_119 = 0 ;
T_1 V_120 = 0 ;
T_1 V_121 ;
int V_122 = 0 ;
switch ( V_117 ) {
case V_123 :
case V_124 :
V_122 = 1 ;
break;
case V_125 :
case V_126 :
default:
V_122 = 0 ;
break;
}
F_47 (s, substream) {
if ( F_20 ( V_118 ) != V_2 ||
V_118 -> V_127 != V_128 )
continue;
V_36 = V_118 -> V_36 ;
V_63 = V_36 -> V_37 ;
V_60 = V_63 -> V_45 ;
V_63 -> V_122 = V_122 ;
V_119 |= ( 0x1 << V_60 ) ;
V_120 |= ( 0x10 << V_60 ) ;
F_48 ( V_118 , V_58 ) ;
}
switch ( V_117 ) {
case V_123 :
case V_124 :
V_121 = F_1 ( V_2 , V_129 , 0 ) ;
V_121 |= V_120 ;
F_6 ( V_2 , V_129 , 0 , V_121 ) ;
V_121 = F_1 ( V_2 , V_130 , 0 ) ;
V_121 |= V_119 ;
F_6 ( V_2 , V_130 , 0 , V_121 ) ;
break;
case V_125 :
case V_126 :
V_121 = F_1 ( V_2 , V_130 , 0 ) ;
V_121 &= ~ V_119 ;
F_6 ( V_2 , V_130 , 0 , V_121 ) ;
V_121 = F_1 ( V_2 , V_129 , 0 ) ;
V_121 &= ~ V_120 ;
F_6 ( V_2 , V_129 , 0 , V_121 ) ;
break;
default:
V_17 = - V_25 ;
break;
}
return V_17 ;
}
static int F_49 ( struct V_57 * V_58 ,
int V_117 )
{
struct V_1 * V_2 = F_20 ( V_58 ) ;
struct V_35 * V_36 = V_58 -> V_36 ;
struct V_62 * V_63 = V_36 -> V_37 ;
int V_60 = V_63 -> V_45 ;
int V_17 = 0 ;
switch ( V_117 ) {
case V_123 :
F_6 ( V_2 , V_129 , 0 , F_1 ( V_2 , V_129 , 0 ) | ( 0x110000 << V_60 ) ) ;
F_6 ( V_2 , V_130 , 0 , F_1 ( V_2 , V_130 , 0 ) | ( 0x100 << V_60 ) ) ;
V_63 -> V_122 = 1 ;
break;
case V_125 :
F_6 ( V_2 , V_130 , 0 , F_1 ( V_2 , V_130 , 0 ) & ~ ( 0x100 << V_60 ) ) ;
F_6 ( V_2 , V_129 , 0 , F_1 ( V_2 , V_129 , 0 ) & ~ ( 0x110000 << V_60 ) ) ;
V_63 -> V_122 = 0 ;
break;
default:
V_17 = - V_25 ;
break;
}
return V_17 ;
}
static T_2
F_50 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_20 ( V_58 ) ;
struct V_35 * V_36 = V_58 -> V_36 ;
struct V_62 * V_63 = V_36 -> V_37 ;
unsigned int V_131 , V_132 ;
int V_60 = V_63 -> V_45 ;
int V_20 = 10 ;
if ( ! V_63 -> V_122 )
return 0 ;
V_132 = - 1 ;
do {
V_131 = F_1 ( V_2 , V_104 , V_60 ) ;
V_131 = ( V_131 >> 3 ) * V_36 -> V_82 ;
V_131 += F_51 ( V_36 ,
F_1 ( V_2 , V_107 , V_60 ) ) ;
if ( V_131 >= V_36 -> V_115 )
V_131 -= V_36 -> V_115 ;
if ( V_132 == V_131 )
return V_131 ;
V_132 = V_131 ;
} while ( -- V_20 );
F_52 ( V_2 -> V_23 -> V_24 , L_5 ) ;
return 0 ;
}
static T_2
F_53 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_20 ( V_58 ) ;
struct V_35 * V_36 = V_58 -> V_36 ;
struct V_62 * V_63 = V_36 -> V_37 ;
T_2 V_131 , V_133 , V_134 = 0 ;
int V_60 = V_63 -> V_45 ;
if ( ! V_63 -> V_122 )
return 0 ;
V_133 = F_1 ( V_2 , V_116 , V_60 ) ;
V_134 = F_51 ( V_36 , V_133 ) ;
V_131 = V_134 ;
if ( V_131 >= V_36 -> V_115 )
V_131 -= V_36 -> V_115 ;
return V_131 ;
}
static unsigned short F_54 ( struct V_135 * V_136 ,
unsigned short V_3 )
{
struct V_1 * V_2 = V_136 -> V_37 ;
unsigned long V_5 ;
unsigned short V_7 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_55 ( V_3 , V_2 -> V_9 + V_137 ) ;
V_7 = F_56 ( V_2 -> V_9 + V_138 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
return V_7 ;
}
static void F_57 ( struct V_135 * V_136 ,
unsigned short V_3 , unsigned short V_7 )
{
struct V_1 * V_2 = V_136 -> V_37 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_55 ( V_3 , V_2 -> V_9 + V_137 ) ;
F_58 ( V_7 , V_2 -> V_9 + V_138 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static int F_59 ( struct V_1 * V_38 )
{
struct V_139 * V_140 ;
struct V_141 V_136 ;
int V_64 ;
static struct V_142 V_143 = {
. V_144 = F_57 ,
. V_145 = F_54 ,
} ;
if ( ( V_64 = V_139 ( V_38 -> V_23 , 0 , & V_143 , NULL , & V_140 ) ) < 0 )
return V_64 ;
V_140 -> V_146 = 1 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_37 = V_38 ;
V_136 . V_147 = V_148 ;
return F_60 ( V_140 , & V_136 , & V_38 -> V_136 ) ;
}
static int F_61 ( struct V_1 * V_38 )
{
if ( V_38 -> V_149 != NULL ) {
F_62 ( V_38 ) ;
}
if ( V_38 -> V_150 >= 0 )
F_63 ( V_38 -> V_150 , V_38 ) ;
#if 1
if ( V_38 -> V_79 . V_80 )
F_64 ( & V_38 -> V_79 ) ;
#endif
F_65 ( V_38 -> V_149 ) ;
F_66 ( V_38 -> V_151 ) ;
F_14 ( V_38 ) ;
return 0 ;
}
static int F_67 ( struct V_152 * V_153 )
{
struct V_1 * V_38 = V_153 -> V_154 ;
return F_61 ( V_38 ) ;
}
static T_3 F_68 ( int V_150 , void * V_155 )
{
unsigned int V_21 ;
struct V_1 * V_38 = V_155 ;
int V_93 ;
int V_156 ;
unsigned int V_157 ;
struct V_59 * V_158 ;
V_21 = F_4 ( V_38 -> V_9 + V_159 ) ;
if ( ! V_21 )
return V_160 ;
V_157 = F_1 ( V_38 , V_161 , 0 ) ;
V_156 = 0x11 ;
for( V_93 = 0 ; V_93 < 4 ; V_93 ++ ) {
V_158 = & ( V_38 -> V_61 [ V_93 ] ) ;
if ( V_157 & V_156 ) {
if( V_158 -> V_71 ) {
F_69 ( V_158 -> V_63 -> V_58 ) ;
}
}
V_156 <<= 1 ;
}
V_156 = 0x110000 ;
for( V_93 = 0 ; V_93 < 4 ; V_93 ++ ) {
V_158 = & ( V_38 -> V_74 [ V_93 ] ) ;
if ( V_157 & V_156 ) {
if( V_158 -> V_71 ) {
F_69 ( V_158 -> V_63 -> V_58 ) ;
}
}
V_156 <<= 1 ;
}
F_6 ( V_38 , V_161 , 0 , V_157 ) ;
if ( V_38 -> V_162 . V_155 &&
( V_21 & ( V_38 -> V_162 . V_163 | V_38 -> V_162 . V_164 ) ) ) {
if ( V_38 -> V_162 . V_165 )
V_38 -> V_162 . V_165 ( & V_38 -> V_162 , V_21 ) ;
else
V_38 -> V_162 . V_166 ( & V_38 -> V_162 , V_38 -> V_162 . V_167 | V_38 -> V_162 . V_168 ) ;
}
F_3 ( V_21 , V_38 -> V_9 + V_159 ) ;
return V_169 ;
}
static int V_62 ( struct V_1 * V_2 , int V_153 )
{
struct V_170 * V_171 ;
struct V_57 * V_58 ;
const struct V_172 * V_173 = NULL ;
int V_64 ;
V_64 = F_70 ( V_2 -> V_23 , L_6 , V_153 , 1 , 1 , & V_171 ) ;
if ( V_64 < 0 )
return V_64 ;
V_171 -> V_37 = V_2 ;
switch ( V_153 ) {
case 0 :
F_71 ( V_171 , V_128 , & V_174 ) ;
F_71 ( V_171 , V_175 , & V_176 ) ;
V_173 = V_177 ;
break;
case 1 :
F_71 ( V_171 , V_128 , & V_178 ) ;
F_71 ( V_171 , V_175 , & V_179 ) ;
V_173 = V_180 ;
break;
case 2 :
F_71 ( V_171 , V_128 , & V_181 ) ;
F_71 ( V_171 , V_175 , & V_182 ) ;
V_173 = V_183 ;
break;
case 3 :
F_71 ( V_171 , V_128 , & V_184 ) ;
F_71 ( V_171 , V_175 , & V_185 ) ;
V_173 = V_186 ;
break;
}
V_171 -> V_187 = 0 ;
strcpy ( V_171 -> V_188 , L_7 ) ;
for( V_58 = V_171 -> V_189 [ V_128 ] . V_58 ;
V_58 ;
V_58 = V_58 -> V_190 ) {
if ( ( V_64 = F_72 ( V_58 ,
V_191 ,
F_73 ( V_2 -> V_151 ) ,
64 * 1024 , 64 * 1024 ) ) < 0 )
return V_64 ;
}
for ( V_58 = V_171 -> V_189 [ V_175 ] . V_58 ;
V_58 ;
V_58 = V_58 -> V_190 ) {
if ( ( V_64 = F_72 ( V_58 ,
V_191 ,
F_73 ( V_2 -> V_151 ) ,
64 * 1024 , 64 * 1024 ) ) < 0 )
return V_64 ;
}
V_64 = F_74 ( V_171 , V_128 , V_173 , 2 ,
1 << 2 , NULL ) ;
if ( V_64 < 0 )
return V_64 ;
V_2 -> V_171 [ V_153 ] = V_171 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_38 , int V_192 )
{
int V_193 ;
unsigned int V_194 ;
F_3 ( 0 , V_38 -> V_9 + V_34 ) ;
V_194 =
V_195 | V_196 |
V_197 | V_198 |
V_199 | 0x00001200 |
0x00000000 | V_200 | V_201 ;
if ( ! V_192 ) {
V_38 -> V_40 [ 0 ] = V_38 -> V_41 [ 0 ] = V_194 ;
V_38 -> V_40 [ 1 ] = V_38 -> V_41 [ 1 ] = V_194 ;
V_38 -> V_40 [ 2 ] = V_38 -> V_41 [ 2 ] = V_194 ;
V_38 -> V_40 [ 3 ] = V_38 -> V_41 [ 3 ] = V_194 ;
}
F_6 ( V_38 , V_202 , 0 , V_38 -> V_40 [ 1 ] ) ;
F_6 ( V_38 , V_42 , 0 , V_38 -> V_40 [ 0 ] ) ;
F_6 ( V_38 , V_203 , 0 , V_38 -> V_40 [ 2 ] ) ;
F_6 ( V_38 , V_204 , 0 , V_38 -> V_40 [ 3 ] ) ;
F_6 ( V_38 , V_108 , 0 , 0x00fc0000 ) ;
F_6 ( V_38 , V_205 , 0 , 0x00fc0000 ) ;
F_55 ( V_206 , V_38 -> V_9 + V_137 ) ;
F_58 ( 0x8000 , V_38 -> V_9 + V_138 ) ;
#if 0
snd_ca0106_ptr_write(chip, SPCS0, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x42, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x43, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x44, 0, 0x2108006);
#endif
F_6 ( V_38 , V_207 , 0 , 0xf ) ;
F_6 ( V_38 , V_208 , 0 , 0x000f0000 ) ;
V_38 -> V_209 = 0 ;
F_6 ( V_38 , V_210 , 0 , 0x40c81000 ) ;
F_6 ( V_38 , V_210 , 1 , 0xffffffff ) ;
F_6 ( V_38 , V_210 , 2 , 0x30300000 ) ;
F_6 ( V_38 , V_210 , 3 , 0x00700000 ) ;
F_6 ( V_38 , V_211 , 0 , 0x32765410 ) ;
F_6 ( V_38 , V_212 , 0 , 0x76767676 ) ;
F_6 ( V_38 , V_213 , 0 , 0x32765410 ) ;
F_6 ( V_38 , V_214 , 0 , 0x76767676 ) ;
for ( V_193 = 0 ; V_193 < 4 ; V_193 ++ ) {
F_6 ( V_38 , V_215 , V_193 , 0x30303030 ) ;
F_6 ( V_38 , V_216 , V_193 , 0x30303030 ) ;
#if 0
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME1, ch, 0x40404040);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME2, ch, 0x40404040);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME1, ch, 0xffffffff);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME2, ch, 0xffffffff);
#endif
}
if ( V_38 -> V_44 -> V_111 == 1 ) {
F_6 ( V_38 , V_217 , 0x0 , 0x333300e4 ) ;
if ( ! V_192 )
V_38 -> V_218 = 3 ;
} else if ( V_38 -> V_44 -> V_136 == 1 ) {
F_6 ( V_38 , V_217 , 0x0 , 0x444400e4 ) ;
if ( ! V_192 )
V_38 -> V_218 = 4 ;
} else {
F_6 ( V_38 , V_217 , 0x0 , 0x333300e4 ) ;
if ( ! V_192 )
V_38 -> V_218 = 3 ;
}
if ( V_38 -> V_44 -> V_219 == 2 ) {
F_3 ( 0x0 , V_38 -> V_9 + V_220 ) ;
F_3 ( 0x005f5301 , V_38 -> V_9 + V_220 ) ;
} else if ( V_38 -> V_44 -> V_219 == 1 ) {
F_3 ( 0x0 , V_38 -> V_9 + V_220 ) ;
F_3 ( 0x005f5301 , V_38 -> V_9 + V_220 ) ;
} else {
F_3 ( 0x0 , V_38 -> V_9 + V_220 ) ;
F_3 ( 0x005f03a3 , V_38 -> V_9 + V_220 ) ;
}
F_11 ( V_38 , 0x105 ) ;
F_3 ( V_221 | V_222 , V_38 -> V_9 + V_98 ) ;
if ( V_38 -> V_44 -> V_111 == 1 ) {
int V_223 , V_16 ;
V_223 = F_76 ( V_224 ) ;
for ( V_16 = 0 ; V_16 < V_223 ; V_16 ++ )
F_9 ( V_38 , V_224 [ V_16 ] [ 0 ] ,
V_224 [ V_16 ] [ 1 ] ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_38 -> V_225 [ V_16 ] [ 0 ] = 0xcf ;
V_38 -> V_225 [ V_16 ] [ 1 ] = 0xcf ;
}
V_38 -> V_226 = 2 ;
}
if ( V_38 -> V_44 -> V_47 ) {
int V_223 , V_16 ;
V_223 = F_76 ( V_227 ) ;
for ( V_16 = 0 ; V_16 < V_223 ; V_16 ++ ) {
int V_3 = V_227 [ V_16 ] >> V_228 ;
F_7 ( V_38 , V_227 [ V_16 ] ) ;
if ( V_3 < F_76 ( V_38 -> V_56 ) )
V_38 -> V_56 [ V_3 ] = V_227 [ V_16 ] ;
}
F_18 ( V_38 , V_46 , 1 ) ;
}
}
static void F_62 ( struct V_1 * V_38 )
{
F_6 ( V_38 , V_130 , 0 , 0 ) ;
F_3 ( 0 , V_38 -> V_9 + V_34 ) ;
F_6 ( V_38 , V_129 , 0 , 0 ) ;
F_8 ( 1000 ) ;
F_3 ( 0 , V_38 -> V_9 + V_98 ) ;
}
static int F_77 ( int V_24 , struct V_229 * V_23 ,
struct V_230 * V_151 ,
struct V_1 * * V_231 )
{
struct V_1 * V_38 ;
struct V_43 * V_232 ;
int V_64 ;
static struct V_233 V_143 = {
. V_234 = F_67 ,
} ;
* V_231 = NULL ;
V_64 = F_78 ( V_151 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( F_79 ( V_151 , F_80 ( 32 ) ) < 0 ||
F_81 ( V_151 , F_80 ( 32 ) ) < 0 ) {
F_10 ( V_23 -> V_24 , L_8 ) ;
F_66 ( V_151 ) ;
return - V_235 ;
}
V_38 = F_21 ( sizeof( * V_38 ) , V_65 ) ;
if ( V_38 == NULL ) {
F_66 ( V_151 ) ;
return - V_66 ;
}
V_38 -> V_23 = V_23 ;
V_38 -> V_151 = V_151 ;
V_38 -> V_150 = - 1 ;
F_82 ( & V_38 -> V_8 ) ;
V_38 -> V_9 = F_83 ( V_151 , 0 ) ;
V_38 -> V_149 = F_84 ( V_38 -> V_9 , 0x20 , L_9 ) ;
if ( ! V_38 -> V_149 ) {
F_61 ( V_38 ) ;
F_10 ( V_23 -> V_24 , L_10 ) ;
return - V_236 ;
}
if ( F_85 ( V_151 -> V_150 , F_68 ,
V_237 , V_238 , V_38 ) ) {
F_61 ( V_38 ) ;
F_10 ( V_23 -> V_24 , L_11 ) ;
return - V_236 ;
}
V_38 -> V_150 = V_151 -> V_150 ;
if ( F_86 ( V_191 , F_73 ( V_151 ) ,
1024 , & V_38 -> V_79 ) < 0 ) {
F_61 ( V_38 ) ;
return - V_66 ;
}
F_87 ( V_151 ) ;
F_88 ( V_151 , V_239 , & V_38 -> V_240 ) ;
F_89 ( V_151 , V_241 , & V_38 -> V_242 ) ;
F_90 ( V_23 -> V_24 , L_12 ,
V_38 -> V_242 , V_151 -> V_243 , V_38 -> V_240 ) ;
strcpy ( V_23 -> V_244 , L_7 ) ;
strcpy ( V_23 -> V_245 , L_7 ) ;
for ( V_232 = V_246 ; V_232 -> V_240 ; V_232 ++ ) {
if ( V_247 [ V_24 ] ) {
if ( V_232 -> V_240 == V_247 [ V_24 ] )
break;
} else if ( V_232 -> V_240 == V_38 -> V_240 )
break;
}
V_38 -> V_44 = V_232 ;
if ( V_247 [ V_24 ] ) {
F_90 ( V_23 -> V_24 , L_13
L_14 ,
V_232 -> V_188 , V_38 -> V_240 , V_247 [ V_24 ] ) ;
}
sprintf ( V_23 -> V_248 , L_15 ,
V_232 -> V_188 , V_38 -> V_9 , V_38 -> V_150 ) ;
F_75 ( V_38 , 0 ) ;
V_64 = F_91 ( V_23 , V_249 , V_38 , & V_143 ) ;
if ( V_64 < 0 ) {
F_61 ( V_38 ) ;
return V_64 ;
}
* V_231 = V_38 ;
return 0 ;
}
static void F_92 ( struct V_250 * V_162 , int V_251 )
{
F_11 ( (struct V_1 * ) ( V_162 -> V_155 ) , V_251 ) ;
}
static void F_93 ( struct V_250 * V_162 , int V_251 )
{
F_12 ( (struct V_1 * ) ( V_162 -> V_155 ) , V_251 ) ;
}
static unsigned char F_94 ( struct V_250 * V_162 , int V_39 )
{
return ( unsigned char ) F_1 ( (struct V_1 * ) ( V_162 -> V_155 ) ,
V_162 -> V_9 + V_39 , 0 ) ;
}
static void F_95 ( struct V_250 * V_162 , int V_12 , int V_39 )
{
F_6 ( (struct V_1 * ) ( V_162 -> V_155 ) , V_162 -> V_9 + V_39 , 0 , V_12 ) ;
}
static struct V_229 * F_96 ( void * V_155 )
{
return ( (struct V_1 * ) V_155 ) -> V_23 ;
}
static int F_97 ( void * V_155 )
{
return ( (struct V_1 * ) V_155 ) -> V_9 ;
}
static int F_98 ( struct V_1 * V_38 , unsigned int V_60 )
{
struct V_250 * V_162 ;
char * V_188 ;
int V_64 ;
if ( V_60 == V_252 ) {
V_188 = L_16 ;
V_162 = & V_38 -> V_253 ;
V_162 -> V_167 = V_254 ;
V_162 -> V_168 = V_255 ;
V_162 -> V_163 = V_256 ;
V_162 -> V_164 = V_257 ;
V_162 -> V_9 = V_258 ;
} else {
V_188 = L_17 ;
V_162 = & V_38 -> V_162 ;
V_162 -> V_167 = V_259 ;
V_162 -> V_168 = V_254 ;
V_162 -> V_163 = V_260 ;
V_162 -> V_164 = V_261 ;
V_162 -> V_9 = V_262 ;
}
V_162 -> V_13 = V_263 ;
V_162 -> V_264 = V_265 ;
V_162 -> V_266 = V_267 ;
V_162 -> V_268 = V_269 ;
V_162 -> V_270 = V_271 ;
V_162 -> V_60 = V_60 ;
V_162 -> V_272 = F_92 ;
V_162 -> V_166 = F_93 ;
V_162 -> V_145 = F_94 ;
V_162 -> V_144 = F_95 ;
V_162 -> V_273 = F_96 ;
V_162 -> V_274 = F_97 ;
V_162 -> V_155 = V_38 ;
if ( ( V_64 = F_99 ( V_38 , V_162 , 0 , V_188 ) ) < 0 )
return V_64 ;
return 0 ;
}
static int F_100 ( struct V_230 * V_151 ,
const struct V_275 * V_276 )
{
static int V_24 ;
struct V_229 * V_23 ;
struct V_1 * V_38 ;
int V_93 , V_64 ;
if ( V_24 >= V_277 )
return - V_278 ;
if ( ! V_279 [ V_24 ] ) {
V_24 ++ ;
return - V_280 ;
}
V_64 = F_101 ( & V_151 -> V_24 , V_281 [ V_24 ] , V_282 [ V_24 ] , V_283 ,
0 , & V_23 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_77 ( V_24 , V_23 , V_151 , & V_38 ) ;
if ( V_64 < 0 )
goto error;
V_23 -> V_37 = V_38 ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ ) {
V_64 = V_62 ( V_38 , V_93 ) ;
if ( V_64 < 0 )
goto error;
}
if ( V_38 -> V_44 -> V_136 == 1 ) {
V_64 = F_59 ( V_38 ) ;
if ( V_64 < 0 )
goto error;
}
V_64 = F_102 ( V_38 ) ;
if ( V_64 < 0 )
goto error;
F_17 ( V_23 -> V_24 , L_18 ) ;
V_64 = F_98 ( V_38 , V_284 ) ;
if ( V_64 < 0 )
goto error;
F_17 ( V_23 -> V_24 , L_19 ) ;
#ifdef F_103
F_104 ( V_38 ) ;
#endif
V_64 = F_105 ( V_23 ) ;
if ( V_64 < 0 )
goto error;
F_106 ( V_151 , V_23 ) ;
V_24 ++ ;
return 0 ;
error:
F_107 ( V_23 ) ;
return V_64 ;
}
static void F_108 ( struct V_230 * V_151 )
{
F_107 ( F_109 ( V_151 ) ) ;
}
static int F_110 ( struct V_153 * V_24 )
{
struct V_230 * V_151 = F_111 ( V_24 ) ;
struct V_229 * V_23 = F_112 ( V_24 ) ;
struct V_1 * V_38 = V_23 -> V_37 ;
int V_93 ;
F_113 ( V_23 , V_285 ) ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ )
F_114 ( V_38 -> V_171 [ V_93 ] ) ;
if ( V_38 -> V_44 -> V_136 )
F_115 ( V_38 -> V_136 ) ;
F_116 ( V_38 ) ;
F_62 ( V_38 ) ;
F_66 ( V_151 ) ;
F_117 ( V_151 ) ;
F_118 ( V_151 , V_286 ) ;
return 0 ;
}
static int F_119 ( struct V_153 * V_24 )
{
struct V_230 * V_151 = F_111 ( V_24 ) ;
struct V_229 * V_23 = F_112 ( V_24 ) ;
struct V_1 * V_38 = V_23 -> V_37 ;
int V_93 ;
F_118 ( V_151 , V_287 ) ;
F_120 ( V_151 ) ;
if ( F_78 ( V_151 ) < 0 ) {
F_121 ( V_23 ) ;
return - V_288 ;
}
F_87 ( V_151 ) ;
F_75 ( V_38 , 1 ) ;
if ( V_38 -> V_44 -> V_136 )
F_122 ( V_38 -> V_136 ) ;
F_123 ( V_38 ) ;
if ( V_38 -> V_44 -> V_47 ) {
for ( V_93 = 0 ; V_93 < F_76 ( V_38 -> V_56 ) ; V_93 ++ )
F_7 ( V_38 , V_38 -> V_56 [ V_93 ] ) ;
}
F_113 ( V_23 , V_289 ) ;
return 0 ;
}
