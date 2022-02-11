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
F_10 ( V_23 L_1 ) ;
return - V_24 ;
}
V_15 = V_3 << 25 | V_19 << 16 ;
F_6 ( V_2 , V_25 , 0 , V_15 ) ;
for ( V_22 = 0 ; V_22 < 10 ; V_22 ++ ) {
V_15 = 0 ;
V_15 = V_15 | ( V_26 | V_27 | V_28 ) ;
F_6 ( V_2 , V_29 , 0 , V_15 ) ;
while ( 1 ) {
V_21 = F_1 ( V_2 , V_29 , 0 ) ;
V_20 ++ ;
if ( ( V_21 & V_27 ) == 0 )
break;
if ( V_20 > 1000 )
break;
}
if ( ( V_21 & V_30 ) == 0 )
break;
}
if ( V_22 == 10 ) {
F_10 ( V_23 L_2 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_31 )
{
unsigned long V_5 ;
unsigned int V_32 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_32 = F_4 ( V_2 -> V_9 + V_33 ) | V_31 ;
F_3 ( V_32 , V_2 -> V_9 + V_33 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_31 )
{
unsigned long V_5 ;
unsigned int V_32 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_32 = F_4 ( V_2 -> V_9 + V_33 ) & ~ V_31 ;
F_3 ( V_32 , V_2 -> V_9 + V_33 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static void F_13 ( struct V_34 * V_35 )
{
F_14 ( V_35 -> V_36 ) ;
}
static void F_15 ( struct V_1 * V_37 , int V_38 )
{
if ( V_37 -> V_39 [ V_38 ] != V_37 -> V_40 [ V_38 ] ) {
V_37 -> V_39 [ V_38 ] = V_37 -> V_40 [ V_38 ] ;
F_6 ( V_37 , V_41 + V_38 , 0 ,
V_37 -> V_39 [ V_38 ] ) ;
}
}
static int F_16 ( struct V_42 * V_43 ,
int V_44 )
{
switch ( V_44 ) {
case V_45 :
return ( V_43 -> V_46 & 0xf000 ) >> ( 4 * 3 ) ;
case V_47 :
return ( V_43 -> V_46 & 0x0f00 ) >> ( 4 * 2 ) ;
case V_48 :
return ( V_43 -> V_46 & 0x00f0 ) >> ( 4 * 1 ) ;
case V_49 :
return ( V_43 -> V_46 & 0x000f ) >> ( 4 * 0 ) ;
default:
F_10 ( V_50 L_3 ,
V_44 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_37 , int V_44 ,
int V_51 )
{
if ( V_37 -> V_43 -> V_46 ) {
const int V_52 = F_16 ( V_37 -> V_43 ,
V_44 ) ;
const int V_3 = V_53 [ V_52 ] ;
const int V_54 = V_55 [ V_52 ] ;
if ( V_51 )
V_37 -> V_56 [ V_3 ] &= ~ V_54 ;
else
V_37 -> V_56 [ V_3 ] |= V_54 ;
return F_7 ( V_37 , V_37 -> V_56 [ V_3 ] ) ;
}
return 0 ;
}
static int F_18 ( struct V_57 * V_58 ,
int V_44 )
{
struct V_1 * V_37 = F_19 ( V_58 ) ;
struct V_59 * V_60 = & ( V_37 -> V_61 [ V_44 ] ) ;
struct V_62 * V_63 ;
struct V_34 * V_35 = V_58 -> V_35 ;
int V_64 ;
V_63 = F_20 ( sizeof( * V_63 ) , V_65 ) ;
if ( V_63 == NULL )
return - V_66 ;
V_63 -> V_2 = V_37 ;
V_63 -> V_58 = V_58 ;
V_63 -> V_44 = V_44 ;
V_35 -> V_36 = V_63 ;
V_35 -> V_67 = F_13 ;
V_35 -> V_68 = V_69 ;
V_60 -> V_2 = V_37 ;
V_60 -> V_70 = V_44 ;
V_60 -> V_71 = 1 ;
V_60 -> V_63 = V_63 ;
if ( ( V_64 = F_21 ( V_35 , V_72 ) ) < 0 )
return V_64 ;
if ( ( V_64 = F_22 ( V_35 , 0 , V_73 , 64 ) ) < 0 )
return V_64 ;
F_23 ( V_58 ) ;
if ( V_44 != V_45 ) {
V_64 = F_17 ( V_37 , V_44 , 1 ) ;
if ( V_64 < 0 )
return V_64 ;
}
F_15 ( V_37 , V_44 ) ;
return 0 ;
}
static int F_24 ( struct V_57 * V_58 )
{
struct V_1 * V_37 = F_19 ( V_58 ) ;
struct V_34 * V_35 = V_58 -> V_35 ;
struct V_62 * V_63 = V_35 -> V_36 ;
V_37 -> V_61 [ V_63 -> V_44 ] . V_71 = 0 ;
F_15 ( V_37 , V_63 -> V_44 ) ;
if ( V_63 -> V_44 != V_45 ) {
int V_64 ;
V_64 = F_17 ( V_37 , V_63 -> V_44 , 0 ) ;
if ( V_64 < 0 )
return V_64 ;
}
return 0 ;
}
static int F_25 ( struct V_57 * V_58 )
{
return F_18 ( V_58 , V_45 ) ;
}
static int F_26 ( struct V_57 * V_58 )
{
return F_18 ( V_58 , V_48 ) ;
}
static int F_27 ( struct V_57 * V_58 )
{
return F_18 ( V_58 , V_49 ) ;
}
static int F_28 ( struct V_57 * V_58 )
{
return F_18 ( V_58 , V_47 ) ;
}
static int F_29 ( struct V_57 * V_58 ,
int V_44 )
{
struct V_1 * V_37 = F_19 ( V_58 ) ;
struct V_59 * V_60 = & ( V_37 -> V_74 [ V_44 ] ) ;
struct V_62 * V_63 ;
struct V_34 * V_35 = V_58 -> V_35 ;
int V_64 ;
V_63 = F_20 ( sizeof( * V_63 ) , V_65 ) ;
if ( V_63 == NULL ) {
F_10 ( V_23 L_4 ) ;
return - V_66 ;
}
V_63 -> V_2 = V_37 ;
V_63 -> V_58 = V_58 ;
V_63 -> V_44 = V_44 ;
V_35 -> V_36 = V_63 ;
V_35 -> V_67 = F_13 ;
V_35 -> V_68 = V_75 ;
V_60 -> V_2 = V_37 ;
V_60 -> V_70 = V_44 ;
V_60 -> V_71 = 1 ;
V_60 -> V_63 = V_63 ;
if ( ( V_64 = F_21 ( V_35 , V_72 ) ) < 0 )
return V_64 ;
if ( ( V_64 = F_22 ( V_35 , 0 , V_73 , 64 ) ) < 0 )
return V_64 ;
return 0 ;
}
static int F_30 ( struct V_57 * V_58 )
{
struct V_1 * V_37 = F_19 ( V_58 ) ;
struct V_34 * V_35 = V_58 -> V_35 ;
struct V_62 * V_63 = V_35 -> V_36 ;
V_37 -> V_74 [ V_63 -> V_44 ] . V_71 = 0 ;
return 0 ;
}
static int F_31 ( struct V_57 * V_58 )
{
return F_29 ( V_58 , 0 ) ;
}
static int F_32 ( struct V_57 * V_58 )
{
return F_29 ( V_58 , 1 ) ;
}
static int F_33 ( struct V_57 * V_58 )
{
return F_29 ( V_58 , 2 ) ;
}
static int F_34 ( struct V_57 * V_58 )
{
return F_29 ( V_58 , 3 ) ;
}
static int F_35 ( struct V_57 * V_58 ,
struct V_76 * V_77 )
{
return F_36 ( V_58 ,
F_37 ( V_77 ) ) ;
}
static int F_38 ( struct V_57 * V_58 )
{
return F_39 ( V_58 ) ;
}
static int F_40 ( struct V_57 * V_58 ,
struct V_76 * V_77 )
{
return F_36 ( V_58 ,
F_37 ( V_77 ) ) ;
}
static int F_41 ( struct V_57 * V_58 )
{
return F_39 ( V_58 ) ;
}
static int F_42 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
struct V_34 * V_35 = V_58 -> V_35 ;
struct V_62 * V_63 = V_35 -> V_36 ;
int V_60 = V_63 -> V_44 ;
T_1 * V_78 = ( T_1 * ) ( V_2 -> V_79 . V_80 + ( 8 * 16 * V_60 ) ) ;
T_1 V_81 = F_43 ( V_35 , V_35 -> V_82 ) ;
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
snd_printk(KERN_DEBUG
"prepare:channel_number=%d, rate=%d, format=0x%x, "
"channels=%d, buffer_size=%ld, period_size=%ld, "
"periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format,
runtime->channels, runtime->buffer_size,
runtime->period_size, runtime->periods,
frames_to_bytes(runtime, 1));
snd_printk(KERN_DEBUG "dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
snd_printk(KERN_DEBUG "dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->buffer.addr, emu->buffer.area, emu->buffer.bytes);
#endif
switch ( V_35 -> V_94 ) {
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
switch ( V_35 -> V_95 ) {
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
for( V_93 = 0 ; V_93 < V_35 -> V_99 ; V_93 ++ ) {
V_78 [ V_93 * 2 ] = V_35 -> V_100 + ( V_93 * V_81 ) ;
V_78 [ V_93 * 2 + 1 ] = V_81 << 16 ;
}
F_6 ( V_2 , V_101 , V_60 , V_2 -> V_79 . V_102 + ( 8 * 16 * V_60 ) ) ;
F_6 ( V_2 , V_103 , V_60 , ( V_35 -> V_99 - 1 ) << 19 ) ;
F_6 ( V_2 , V_104 , V_60 , 0 ) ;
F_6 ( V_2 , V_105 , V_60 , V_35 -> V_100 ) ;
F_6 ( V_2 , V_106 , V_60 , F_43 ( V_35 , V_35 -> V_82 ) << 16 ) ;
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
static int F_44 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
struct V_34 * V_35 = V_58 -> V_35 ;
struct V_62 * V_63 = V_35 -> V_36 ;
int V_60 = V_63 -> V_44 ;
T_1 V_83 = V_109 ;
T_1 V_85 = 0x00000000 ;
T_1 V_86 ;
T_1 V_110 = 0x2 ;
T_1 V_90 = 0x0000c000 ;
T_1 V_91 = 0 ;
T_1 V_92 ;
#if 0
snd_printk(KERN_DEBUG
"prepare:channel_number=%d, rate=%d, format=0x%x, "
"channels=%d, buffer_size=%ld, period_size=%ld, "
"periods=%u, frames_to_bytes=%d\n",
channel, runtime->rate, runtime->format,
runtime->channels, runtime->buffer_size,
runtime->period_size, runtime->periods,
frames_to_bytes(runtime, 1));
snd_printk(KERN_DEBUG "dma_addr=%x, dma_area=%p, table_base=%p\n",
runtime->dma_addr, runtime->dma_area, table_base);
snd_printk(KERN_DEBUG "dma_addr=%x, dma_area=%p, dma_bytes(size)=%x\n",
emu->buffer.addr, emu->buffer.area, emu->buffer.bytes);
#endif
switch ( V_35 -> V_94 ) {
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
switch ( V_35 -> V_95 ) {
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
if ( V_2 -> V_43 -> V_111 == 1 ) {
F_9 ( V_2 , V_112 , V_110 ) ;
}
F_6 ( V_2 , 0x13 , V_60 , 0 ) ;
F_6 ( V_2 , V_113 , V_60 , V_35 -> V_100 ) ;
F_6 ( V_2 , V_114 , V_60 , F_43 ( V_35 , V_35 -> V_115 ) << 16 ) ;
F_6 ( V_2 , V_116 , V_60 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_57 * V_58 ,
int V_117 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
struct V_34 * V_35 ;
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
F_46 (s, substream) {
if ( F_19 ( V_118 ) != V_2 ||
V_118 -> V_127 != V_128 )
continue;
V_35 = V_118 -> V_35 ;
V_63 = V_35 -> V_36 ;
V_60 = V_63 -> V_44 ;
V_63 -> V_122 = V_122 ;
V_119 |= ( 0x1 << V_60 ) ;
V_120 |= ( 0x10 << V_60 ) ;
F_47 ( V_118 , V_58 ) ;
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
V_17 = - V_24 ;
break;
}
return V_17 ;
}
static int F_48 ( struct V_57 * V_58 ,
int V_117 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
struct V_34 * V_35 = V_58 -> V_35 ;
struct V_62 * V_63 = V_35 -> V_36 ;
int V_60 = V_63 -> V_44 ;
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
V_17 = - V_24 ;
break;
}
return V_17 ;
}
static T_2
F_49 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
struct V_34 * V_35 = V_58 -> V_35 ;
struct V_62 * V_63 = V_35 -> V_36 ;
unsigned int V_131 , V_132 ;
int V_60 = V_63 -> V_44 ;
int V_20 = 10 ;
if ( ! V_63 -> V_122 )
return 0 ;
V_132 = - 1 ;
do {
V_131 = F_1 ( V_2 , V_104 , V_60 ) ;
V_131 = ( V_131 >> 3 ) * V_35 -> V_82 ;
V_131 += F_50 ( V_35 ,
F_1 ( V_2 , V_107 , V_60 ) ) ;
if ( V_131 >= V_35 -> V_115 )
V_131 -= V_35 -> V_115 ;
if ( V_132 == V_131 )
return V_131 ;
V_132 = V_131 ;
} while ( -- V_20 );
F_10 ( V_133 L_5 ) ;
return 0 ;
}
static T_2
F_51 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_19 ( V_58 ) ;
struct V_34 * V_35 = V_58 -> V_35 ;
struct V_62 * V_63 = V_35 -> V_36 ;
T_2 V_131 , V_134 , V_135 = 0 ;
int V_60 = V_63 -> V_44 ;
if ( ! V_63 -> V_122 )
return 0 ;
V_134 = F_1 ( V_2 , V_116 , V_60 ) ;
V_135 = F_50 ( V_35 , V_134 ) ;
V_131 = V_135 ;
if ( V_131 >= V_35 -> V_115 )
V_131 -= V_35 -> V_115 ;
return V_131 ;
}
static unsigned short F_52 ( struct V_136 * V_137 ,
unsigned short V_3 )
{
struct V_1 * V_2 = V_137 -> V_36 ;
unsigned long V_5 ;
unsigned short V_7 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_53 ( V_3 , V_2 -> V_9 + V_138 ) ;
V_7 = F_54 ( V_2 -> V_9 + V_139 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
return V_7 ;
}
static void F_55 ( struct V_136 * V_137 ,
unsigned short V_3 , unsigned short V_7 )
{
struct V_1 * V_2 = V_137 -> V_36 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_53 ( V_3 , V_2 -> V_9 + V_138 ) ;
F_56 ( V_7 , V_2 -> V_9 + V_139 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static int F_57 ( struct V_1 * V_37 )
{
struct V_140 * V_141 ;
struct V_142 V_137 ;
int V_64 ;
static struct V_143 V_144 = {
. V_145 = F_55 ,
. V_146 = F_52 ,
} ;
if ( ( V_64 = V_140 ( V_37 -> V_147 , 0 , & V_144 , NULL , & V_141 ) ) < 0 )
return V_64 ;
V_141 -> V_148 = 1 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_36 = V_37 ;
V_137 . V_149 = V_150 ;
return F_58 ( V_141 , & V_137 , & V_37 -> V_137 ) ;
}
static int F_59 ( struct V_1 * V_37 )
{
if ( V_37 -> V_151 != NULL ) {
F_60 ( V_37 ) ;
}
if ( V_37 -> V_152 >= 0 )
F_61 ( V_37 -> V_152 , V_37 ) ;
#if 1
if ( V_37 -> V_79 . V_80 )
F_62 ( & V_37 -> V_79 ) ;
#endif
F_63 ( V_37 -> V_151 ) ;
F_64 ( V_37 -> V_153 ) ;
F_14 ( V_37 ) ;
return 0 ;
}
static int F_65 ( struct V_154 * V_155 )
{
struct V_1 * V_37 = V_155 -> V_156 ;
return F_59 ( V_37 ) ;
}
static T_3 F_66 ( int V_152 , void * V_157 )
{
unsigned int V_21 ;
struct V_1 * V_37 = V_157 ;
int V_93 ;
int V_158 ;
unsigned int V_159 ;
struct V_59 * V_160 ;
V_21 = F_4 ( V_37 -> V_9 + V_161 ) ;
if ( ! V_21 )
return V_162 ;
V_159 = F_1 ( V_37 , V_163 , 0 ) ;
V_158 = 0x11 ;
for( V_93 = 0 ; V_93 < 4 ; V_93 ++ ) {
V_160 = & ( V_37 -> V_61 [ V_93 ] ) ;
if ( V_159 & V_158 ) {
if( V_160 -> V_71 ) {
F_67 ( V_160 -> V_63 -> V_58 ) ;
}
}
V_158 <<= 1 ;
}
V_158 = 0x110000 ;
for( V_93 = 0 ; V_93 < 4 ; V_93 ++ ) {
V_160 = & ( V_37 -> V_74 [ V_93 ] ) ;
if ( V_159 & V_158 ) {
if( V_160 -> V_71 ) {
F_67 ( V_160 -> V_63 -> V_58 ) ;
}
}
V_158 <<= 1 ;
}
F_6 ( V_37 , V_163 , 0 , V_159 ) ;
if ( V_37 -> V_164 . V_157 &&
( V_21 & ( V_37 -> V_164 . V_165 | V_37 -> V_164 . V_166 ) ) ) {
if ( V_37 -> V_164 . V_167 )
V_37 -> V_164 . V_167 ( & V_37 -> V_164 , V_21 ) ;
else
V_37 -> V_164 . V_168 ( & V_37 -> V_164 , V_37 -> V_164 . V_169 | V_37 -> V_164 . V_170 ) ;
}
F_3 ( V_21 , V_37 -> V_9 + V_161 ) ;
return V_171 ;
}
static int T_4 V_62 ( struct V_1 * V_2 , int V_155 )
{
struct V_172 * V_173 ;
struct V_57 * V_58 ;
int V_64 ;
V_64 = F_68 ( V_2 -> V_147 , L_6 , V_155 , 1 , 1 , & V_173 ) ;
if ( V_64 < 0 )
return V_64 ;
V_173 -> V_36 = V_2 ;
switch ( V_155 ) {
case 0 :
F_69 ( V_173 , V_128 , & V_174 ) ;
F_69 ( V_173 , V_175 , & V_176 ) ;
break;
case 1 :
F_69 ( V_173 , V_128 , & V_177 ) ;
F_69 ( V_173 , V_175 , & V_178 ) ;
break;
case 2 :
F_69 ( V_173 , V_128 , & V_179 ) ;
F_69 ( V_173 , V_175 , & V_180 ) ;
break;
case 3 :
F_69 ( V_173 , V_128 , & V_181 ) ;
F_69 ( V_173 , V_175 , & V_182 ) ;
break;
}
V_173 -> V_183 = 0 ;
strcpy ( V_173 -> V_184 , L_7 ) ;
for( V_58 = V_173 -> V_185 [ V_128 ] . V_58 ;
V_58 ;
V_58 = V_58 -> V_186 ) {
if ( ( V_64 = F_70 ( V_58 ,
V_187 ,
F_71 ( V_2 -> V_153 ) ,
64 * 1024 , 64 * 1024 ) ) < 0 )
return V_64 ;
}
for ( V_58 = V_173 -> V_185 [ V_175 ] . V_58 ;
V_58 ;
V_58 = V_58 -> V_186 ) {
if ( ( V_64 = F_70 ( V_58 ,
V_187 ,
F_71 ( V_2 -> V_153 ) ,
64 * 1024 , 64 * 1024 ) ) < 0 )
return V_64 ;
}
V_2 -> V_173 [ V_155 ] = V_173 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_37 , int V_188 )
{
int V_189 ;
unsigned int V_190 ;
F_3 ( 0 , V_37 -> V_9 + V_33 ) ;
V_190 =
V_191 | V_192 |
V_193 | V_194 |
V_195 | 0x00001200 |
0x00000000 | V_196 | V_197 ;
if ( ! V_188 ) {
V_37 -> V_39 [ 0 ] = V_37 -> V_40 [ 0 ] = V_190 ;
V_37 -> V_39 [ 1 ] = V_37 -> V_40 [ 1 ] = V_190 ;
V_37 -> V_39 [ 2 ] = V_37 -> V_40 [ 2 ] = V_190 ;
V_37 -> V_39 [ 3 ] = V_37 -> V_40 [ 3 ] = V_190 ;
}
F_6 ( V_37 , V_198 , 0 , V_37 -> V_39 [ 1 ] ) ;
F_6 ( V_37 , V_41 , 0 , V_37 -> V_39 [ 0 ] ) ;
F_6 ( V_37 , V_199 , 0 , V_37 -> V_39 [ 2 ] ) ;
F_6 ( V_37 , V_200 , 0 , V_37 -> V_39 [ 3 ] ) ;
F_6 ( V_37 , V_108 , 0 , 0x00fc0000 ) ;
F_6 ( V_37 , V_201 , 0 , 0x00fc0000 ) ;
F_53 ( V_202 , V_37 -> V_9 + V_138 ) ;
F_56 ( 0x8000 , V_37 -> V_9 + V_139 ) ;
#if 0
snd_ca0106_ptr_write(chip, SPCS0, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x42, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x43, 0, 0x2108006);
snd_ca0106_ptr_write(chip, 0x44, 0, 0x2108006);
#endif
F_6 ( V_37 , V_203 , 0 , 0xf ) ;
F_6 ( V_37 , V_204 , 0 , 0x000f0000 ) ;
V_37 -> V_205 = 0 ;
F_6 ( V_37 , V_206 , 0 , 0x40c81000 ) ;
F_6 ( V_37 , V_206 , 1 , 0xffffffff ) ;
F_6 ( V_37 , V_206 , 2 , 0x30300000 ) ;
F_6 ( V_37 , V_206 , 3 , 0x00700000 ) ;
F_6 ( V_37 , V_207 , 0 , 0x32765410 ) ;
F_6 ( V_37 , V_208 , 0 , 0x76767676 ) ;
F_6 ( V_37 , V_209 , 0 , 0x32765410 ) ;
F_6 ( V_37 , V_210 , 0 , 0x76767676 ) ;
for ( V_189 = 0 ; V_189 < 4 ; V_189 ++ ) {
F_6 ( V_37 , V_211 , V_189 , 0x30303030 ) ;
F_6 ( V_37 , V_212 , V_189 , 0x30303030 ) ;
#if 0
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME1, ch, 0x40404040);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME2, ch, 0x40404040);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME1, ch, 0xffffffff);
snd_ca0106_ptr_write(chip, PLAYBACK_VOLUME2, ch, 0xffffffff);
#endif
}
if ( V_37 -> V_43 -> V_111 == 1 ) {
F_6 ( V_37 , V_213 , 0x0 , 0x333300e4 ) ;
if ( ! V_188 )
V_37 -> V_214 = 3 ;
} else if ( V_37 -> V_43 -> V_137 == 1 ) {
F_6 ( V_37 , V_213 , 0x0 , 0x444400e4 ) ;
if ( ! V_188 )
V_37 -> V_214 = 4 ;
} else {
F_6 ( V_37 , V_213 , 0x0 , 0x333300e4 ) ;
if ( ! V_188 )
V_37 -> V_214 = 3 ;
}
if ( V_37 -> V_43 -> V_215 == 2 ) {
F_3 ( 0x0 , V_37 -> V_9 + V_216 ) ;
F_3 ( 0x005f5301 , V_37 -> V_9 + V_216 ) ;
} else if ( V_37 -> V_43 -> V_215 == 1 ) {
F_3 ( 0x0 , V_37 -> V_9 + V_216 ) ;
F_3 ( 0x005f5301 , V_37 -> V_9 + V_216 ) ;
} else {
F_3 ( 0x0 , V_37 -> V_9 + V_216 ) ;
F_3 ( 0x005f03a3 , V_37 -> V_9 + V_216 ) ;
}
F_11 ( V_37 , 0x105 ) ;
F_3 ( V_217 | V_218 , V_37 -> V_9 + V_98 ) ;
if ( V_37 -> V_43 -> V_111 == 1 ) {
int V_219 , V_16 ;
V_219 = F_73 ( V_220 ) ;
for ( V_16 = 0 ; V_16 < V_219 ; V_16 ++ )
F_9 ( V_37 , V_220 [ V_16 ] [ 0 ] ,
V_220 [ V_16 ] [ 1 ] ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_37 -> V_221 [ V_16 ] [ 0 ] = 0xcf ;
V_37 -> V_221 [ V_16 ] [ 1 ] = 0xcf ;
}
V_37 -> V_222 = 2 ;
}
if ( V_37 -> V_43 -> V_46 ) {
int V_219 , V_16 ;
V_219 = F_73 ( V_223 ) ;
for ( V_16 = 0 ; V_16 < V_219 ; V_16 ++ ) {
int V_3 = V_223 [ V_16 ] >> V_224 ;
F_7 ( V_37 , V_223 [ V_16 ] ) ;
if ( V_3 < F_73 ( V_37 -> V_56 ) )
V_37 -> V_56 [ V_3 ] = V_223 [ V_16 ] ;
}
F_17 ( V_37 , V_45 , 1 ) ;
}
}
static void F_60 ( struct V_1 * V_37 )
{
F_6 ( V_37 , V_130 , 0 , 0 ) ;
F_3 ( 0 , V_37 -> V_9 + V_33 ) ;
F_6 ( V_37 , V_129 , 0 , 0 ) ;
F_8 ( 1000 ) ;
F_3 ( 0 , V_37 -> V_9 + V_98 ) ;
}
static int T_4 F_74 ( int V_225 , struct V_226 * V_147 ,
struct V_227 * V_153 ,
struct V_1 * * V_228 )
{
struct V_1 * V_37 ;
struct V_42 * V_229 ;
int V_64 ;
static struct V_230 V_144 = {
. V_231 = F_65 ,
} ;
* V_228 = NULL ;
V_64 = F_75 ( V_153 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( F_76 ( V_153 , F_77 ( 32 ) ) < 0 ||
F_78 ( V_153 , F_77 ( 32 ) ) < 0 ) {
F_79 ( V_23 L_8 ) ;
F_64 ( V_153 ) ;
return - V_232 ;
}
V_37 = F_20 ( sizeof( * V_37 ) , V_65 ) ;
if ( V_37 == NULL ) {
F_64 ( V_153 ) ;
return - V_66 ;
}
V_37 -> V_147 = V_147 ;
V_37 -> V_153 = V_153 ;
V_37 -> V_152 = - 1 ;
F_80 ( & V_37 -> V_8 ) ;
V_37 -> V_9 = F_81 ( V_153 , 0 ) ;
V_37 -> V_151 = F_82 ( V_37 -> V_9 , 0x20 , L_9 ) ;
if ( ! V_37 -> V_151 ) {
F_59 ( V_37 ) ;
F_79 ( V_23 L_10 ) ;
return - V_233 ;
}
if ( F_83 ( V_153 -> V_152 , F_66 ,
V_234 , V_235 , V_37 ) ) {
F_59 ( V_37 ) ;
F_79 ( V_23 L_11 ) ;
return - V_233 ;
}
V_37 -> V_152 = V_153 -> V_152 ;
if ( F_84 ( V_187 , F_71 ( V_153 ) ,
1024 , & V_37 -> V_79 ) < 0 ) {
F_59 ( V_37 ) ;
return - V_66 ;
}
F_85 ( V_153 ) ;
F_86 ( V_153 , V_236 , & V_37 -> V_237 ) ;
F_87 ( V_153 , V_238 , & V_37 -> V_239 ) ;
F_79 ( V_240 L_12 ,
V_37 -> V_239 , V_153 -> V_241 , V_37 -> V_237 ) ;
strcpy ( V_147 -> V_242 , L_7 ) ;
strcpy ( V_147 -> V_243 , L_7 ) ;
for ( V_229 = V_244 ; V_229 -> V_237 ; V_229 ++ ) {
if ( V_245 [ V_225 ] ) {
if ( V_229 -> V_237 == V_245 [ V_225 ] )
break;
} else if ( V_229 -> V_237 == V_37 -> V_237 )
break;
}
V_37 -> V_43 = V_229 ;
if ( V_245 [ V_225 ] ) {
F_79 ( V_240 L_13
L_14 ,
V_229 -> V_184 , V_37 -> V_237 , V_245 [ V_225 ] ) ;
}
sprintf ( V_147 -> V_246 , L_15 ,
V_229 -> V_184 , V_37 -> V_9 , V_37 -> V_152 ) ;
F_72 ( V_37 , 0 ) ;
V_64 = F_88 ( V_147 , V_247 , V_37 , & V_144 ) ;
if ( V_64 < 0 ) {
F_59 ( V_37 ) ;
return V_64 ;
}
* V_228 = V_37 ;
return 0 ;
}
static void F_89 ( struct V_248 * V_164 , int V_249 )
{
F_11 ( (struct V_1 * ) ( V_164 -> V_157 ) , V_249 ) ;
}
static void F_90 ( struct V_248 * V_164 , int V_249 )
{
F_12 ( (struct V_1 * ) ( V_164 -> V_157 ) , V_249 ) ;
}
static unsigned char F_91 ( struct V_248 * V_164 , int V_38 )
{
return ( unsigned char ) F_1 ( (struct V_1 * ) ( V_164 -> V_157 ) ,
V_164 -> V_9 + V_38 , 0 ) ;
}
static void F_92 ( struct V_248 * V_164 , int V_12 , int V_38 )
{
F_6 ( (struct V_1 * ) ( V_164 -> V_157 ) , V_164 -> V_9 + V_38 , 0 , V_12 ) ;
}
static struct V_226 * F_93 ( void * V_157 )
{
return ( (struct V_1 * ) V_157 ) -> V_147 ;
}
static int F_94 ( void * V_157 )
{
return ( (struct V_1 * ) V_157 ) -> V_9 ;
}
static int T_4 F_95 ( struct V_1 * V_37 , unsigned int V_60 )
{
struct V_248 * V_164 ;
char * V_184 ;
int V_64 ;
if ( V_60 == V_250 ) {
V_184 = L_16 ;
V_164 = & V_37 -> V_251 ;
V_164 -> V_169 = V_252 ;
V_164 -> V_170 = V_253 ;
V_164 -> V_165 = V_254 ;
V_164 -> V_166 = V_255 ;
V_164 -> V_9 = V_256 ;
} else {
V_184 = L_17 ;
V_164 = & V_37 -> V_164 ;
V_164 -> V_169 = V_257 ;
V_164 -> V_170 = V_252 ;
V_164 -> V_165 = V_258 ;
V_164 -> V_166 = V_259 ;
V_164 -> V_9 = V_260 ;
}
V_164 -> V_13 = V_261 ;
V_164 -> V_262 = V_263 ;
V_164 -> V_264 = V_265 ;
V_164 -> V_266 = V_267 ;
V_164 -> V_268 = V_269 ;
V_164 -> V_60 = V_60 ;
V_164 -> V_270 = F_89 ;
V_164 -> V_168 = F_90 ;
V_164 -> V_146 = F_91 ;
V_164 -> V_145 = F_92 ;
V_164 -> V_271 = F_93 ;
V_164 -> V_272 = F_94 ;
V_164 -> V_157 = V_37 ;
if ( ( V_64 = F_96 ( V_37 , V_164 , 0 , V_184 ) ) < 0 )
return V_64 ;
return 0 ;
}
static int T_4 F_97 ( struct V_227 * V_153 ,
const struct V_273 * V_274 )
{
static int V_225 ;
struct V_226 * V_147 ;
struct V_1 * V_37 ;
int V_93 , V_64 ;
if ( V_225 >= V_275 )
return - V_276 ;
if ( ! V_277 [ V_225 ] ) {
V_225 ++ ;
return - V_278 ;
}
V_64 = F_98 ( V_279 [ V_225 ] , V_280 [ V_225 ] , V_281 , 0 , & V_147 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_74 ( V_225 , V_147 , V_153 , & V_37 ) ;
if ( V_64 < 0 )
goto error;
V_147 -> V_36 = V_37 ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ ) {
V_64 = V_62 ( V_37 , V_93 ) ;
if ( V_64 < 0 )
goto error;
}
if ( V_37 -> V_43 -> V_137 == 1 ) {
V_64 = F_57 ( V_37 ) ;
if ( V_64 < 0 )
goto error;
}
V_64 = F_99 ( V_37 ) ;
if ( V_64 < 0 )
goto error;
F_100 ( L_18 ) ;
V_64 = F_95 ( V_37 , V_282 ) ;
if ( V_64 < 0 )
goto error;
F_100 ( L_19 ) ;
#ifdef F_101
F_102 ( V_37 ) ;
#endif
F_103 ( V_147 , & V_153 -> V_225 ) ;
V_64 = F_104 ( V_147 ) ;
if ( V_64 < 0 )
goto error;
F_105 ( V_153 , V_147 ) ;
V_225 ++ ;
return 0 ;
error:
F_106 ( V_147 ) ;
return V_64 ;
}
static void T_5 F_107 ( struct V_227 * V_153 )
{
F_106 ( F_108 ( V_153 ) ) ;
F_105 ( V_153 , NULL ) ;
}
static int F_109 ( struct V_227 * V_153 , T_6 V_283 )
{
struct V_226 * V_147 = F_108 ( V_153 ) ;
struct V_1 * V_37 = V_147 -> V_36 ;
int V_93 ;
F_110 ( V_147 , V_284 ) ;
for ( V_93 = 0 ; V_93 < 4 ; V_93 ++ )
F_111 ( V_37 -> V_173 [ V_93 ] ) ;
if ( V_37 -> V_43 -> V_137 )
F_112 ( V_37 -> V_137 ) ;
F_113 ( V_37 ) ;
F_60 ( V_37 ) ;
F_64 ( V_153 ) ;
F_114 ( V_153 ) ;
F_115 ( V_153 , F_116 ( V_153 , V_283 ) ) ;
return 0 ;
}
static int F_117 ( struct V_227 * V_153 )
{
struct V_226 * V_147 = F_108 ( V_153 ) ;
struct V_1 * V_37 = V_147 -> V_36 ;
int V_93 ;
F_115 ( V_153 , V_285 ) ;
F_118 ( V_153 ) ;
if ( F_75 ( V_153 ) < 0 ) {
F_119 ( V_147 ) ;
return - V_286 ;
}
F_85 ( V_153 ) ;
F_72 ( V_37 , 1 ) ;
if ( V_37 -> V_43 -> V_137 )
F_120 ( V_37 -> V_137 ) ;
F_121 ( V_37 ) ;
if ( V_37 -> V_43 -> V_46 ) {
for ( V_93 = 0 ; V_93 < F_73 ( V_37 -> V_56 ) ; V_93 ++ )
F_7 ( V_37 , V_37 -> V_56 [ V_93 ] ) ;
}
F_110 ( V_147 , V_287 ) ;
return 0 ;
}
static int T_7 F_122 ( void )
{
return F_123 ( & V_242 ) ;
}
static void T_8 F_124 ( void )
{
F_125 ( & V_242 ) ;
}
