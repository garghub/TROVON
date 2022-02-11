static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ( V_6 = V_4 -> V_6 ) == NULL )
return;
if ( V_6 -> V_7 == NULL )
return;
#if 0
printk(KERN_DEBUG "IRQ: position = 0x%x, period = 0x%x, size = 0x%x\n",
epcm->substream->runtime->hw->pointer(emu, epcm->substream),
snd_pcm_lib_period_bytes(epcm->substream),
snd_pcm_lib_buffer_bytes(epcm->substream));
#endif
F_2 ( V_6 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
#if 0
if (status & IPR_ADCBUFHALFFULL) {
if (emu->pcm_capture_substream->runtime->mode == SNDRV_PCM_MODE_FRAME)
return;
}
#endif
F_2 ( V_2 -> V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
#if 0
if (status & IPR_MICBUFHALFFULL) {
if (emu->pcm_capture_mic_substream->runtime->mode == SNDRV_PCM_MODE_FRAME)
return;
}
#endif
F_2 ( V_2 -> V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
#if 0
if (status & IPR_EFXBUFHALFFULL) {
if (emu->pcm_capture_efx_substream->runtime->mode == SNDRV_PCM_MODE_FRAME)
return;
}
#endif
F_2 ( V_2 -> V_11 ) ;
}
static T_1 F_6 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
unsigned int V_16 ;
if ( ! V_6 -> V_17 )
return 0 ;
V_16 = F_8 ( V_2 , V_18 , V_6 -> V_19 [ 0 ] -> V_20 ) & 0x00ffffff ;
V_16 += V_14 -> V_21 ;
V_16 -= V_6 -> V_22 ;
V_16 %= V_14 -> V_21 ;
return V_16 ;
}
static int F_9 ( struct V_5 * V_6 , int V_19 )
{
int V_23 , V_24 ;
if ( V_6 -> V_19 [ 1 ] != NULL && V_19 < 2 ) {
F_10 ( V_6 -> V_2 , V_6 -> V_19 [ 1 ] ) ;
V_6 -> V_19 [ 1 ] = NULL ;
}
for ( V_24 = 0 ; V_24 < V_19 ; V_24 ++ ) {
if ( V_6 -> V_19 [ V_24 ] == NULL )
break;
}
if ( V_24 == V_19 )
return 0 ;
for ( V_24 = 0 ; V_24 < F_11 ( V_6 -> V_19 ) ; V_24 ++ ) {
if ( V_6 -> V_19 [ V_24 ] ) {
F_10 ( V_6 -> V_2 , V_6 -> V_19 [ V_24 ] ) ;
V_6 -> V_19 [ V_24 ] = NULL ;
}
}
V_23 = F_12 ( V_6 -> V_2 ,
V_6 -> type == V_25 ? V_26 : V_27 ,
V_19 ,
& V_6 -> V_19 [ 0 ] ) ;
if ( V_23 < 0 )
return V_23 ;
V_6 -> V_19 [ 0 ] -> V_6 = V_6 ;
if ( V_19 > 1 ) {
for ( V_24 = 1 ; V_24 < V_19 ; V_24 ++ ) {
V_6 -> V_19 [ V_24 ] = & V_6 -> V_2 -> V_19 [ V_6 -> V_19 [ 0 ] -> V_20 + V_24 ] ;
V_6 -> V_19 [ V_24 ] -> V_6 = V_6 ;
}
}
if ( V_6 -> V_28 == NULL ) {
V_23 = F_12 ( V_6 -> V_2 ,
V_6 -> type == V_25 ? V_26 : V_27 ,
1 ,
& V_6 -> V_28 ) ;
if ( V_23 < 0 ) {
for ( V_24 = 0 ; V_24 < V_19 ; V_24 ++ ) {
F_10 ( V_6 -> V_2 , V_6 -> V_19 [ V_24 ] ) ;
V_6 -> V_19 [ V_24 ] = NULL ;
}
return V_23 ;
}
V_6 -> V_28 -> V_6 = V_6 ;
V_6 -> V_28 -> V_29 = F_1 ;
}
return 0 ;
}
static unsigned int F_13 ( unsigned int V_30 )
{
switch ( V_30 ) {
case 8000 : return V_31 ;
case 11025 : return V_32 ;
case 16000 : return V_33 ;
case 22050 : return V_34 ;
case 24000 : return V_35 ;
case 32000 : return V_36 ;
case 44100 : return V_37 ;
case 48000 : return V_38 ;
default:
F_14 () ;
return V_31 ;
}
}
static unsigned int F_15 ( unsigned int V_30 )
{
switch ( V_30 ) {
case 8000 : return V_39 ;
case 11025 : return V_40 ;
case 12000 : return V_41 ;
case 16000 : return V_33 ;
case 22050 : return V_34 ;
case 24000 : return V_35 ;
case 32000 : return V_36 ;
case 44100 : return V_37 ;
case 48000 : return V_38 ;
default:
F_14 () ;
return V_39 ;
}
}
static unsigned int F_16 ( unsigned int V_30 )
{
unsigned int V_42 ;
V_42 = ( V_30 << 8 ) / 375 ;
V_42 = ( V_42 >> 1 ) + ( V_42 & 1 ) ;
return V_42 ;
}
static unsigned int F_17 ( unsigned int V_42 )
{
if ( V_42 == V_43 )
return V_44 ;
else if ( V_42 < V_43 )
return V_45 ;
else if ( V_42 >= V_46 )
return V_44 ;
else if ( V_42 >= V_47 )
return V_48 ;
else if ( V_42 >= V_49 )
return V_50 ;
else if ( V_42 >= V_51 )
return V_52 ;
else if ( V_42 >= V_53 )
return V_54 ;
else
return V_55 ;
}
static inline int F_18 ( int V_56 , int V_57 )
{
if ( V_57 ) {
return V_56 ? 24 : 26 ;
} else {
return V_56 ? 24 * 2 : 26 * 2 ;
}
}
static void F_19 ( struct V_1 * V_2 ,
int V_58 , int V_28 ,
struct V_3 * V_59 ,
unsigned int V_60 ,
unsigned int V_61 ,
struct V_62 * V_63 )
{
struct V_12 * V_7 = V_59 -> V_6 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 ;
unsigned int V_64 , V_65 ;
int V_4 , V_56 , V_57 ;
unsigned char V_66 , V_67 [ 8 ] ;
unsigned char V_68 [ 8 ] ;
unsigned long V_69 ;
unsigned int V_42 ;
unsigned int V_70 ;
V_4 = V_59 -> V_20 ;
V_56 = V_14 -> V_71 == 2 ;
V_57 = F_20 ( V_14 -> V_72 ) == 16 ;
if ( ! V_28 && V_56 ) {
V_60 >>= 1 ;
V_61 >>= 1 ;
}
if ( V_57 ) {
V_60 >>= 1 ;
V_61 >>= 1 ;
}
F_21 ( & V_2 -> V_73 , V_69 ) ;
if ( V_28 ) {
V_66 = 0 ;
memset ( V_68 , 0 , sizeof( V_68 ) ) ;
V_68 [ 0 ] = 0 ;
V_68 [ 1 ] = 1 ;
V_68 [ 2 ] = 2 ;
V_68 [ 3 ] = 3 ;
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
} else {
V_65 = V_56 ? ( V_58 ? 1 : 2 ) : 0 ;
memcpy ( V_68 , & V_63 -> V_68 [ V_65 ] [ 0 ] , 8 ) ;
memcpy ( V_67 , & V_63 -> V_74 [ V_65 ] [ 0 ] , 8 ) ;
}
V_70 = F_18 ( V_56 , V_57 ) ;
if ( V_58 ) {
V_59 -> V_6 -> V_22 = V_60 + V_70 ;
if ( V_28 ) {
V_60 += V_70 ;
V_61 += V_70 + V_2 -> V_75 ;
}
if ( V_56 && ! V_28 ) {
F_22 ( V_2 , V_76 , V_4 , V_77 ) ;
F_22 ( V_2 , V_76 , ( V_4 + 1 ) , V_77 ) ;
} else {
F_22 ( V_2 , V_76 , V_4 , 0 ) ;
}
}
if ( V_2 -> V_78 ) {
F_22 ( V_2 , V_79 , V_4 ,
F_23 ( V_68 ) ) ;
F_22 ( V_2 , V_80 , V_4 ,
F_24 ( V_68 ) ) ;
F_22 ( V_2 , V_81 , V_4 ,
( ( unsigned int ) V_67 [ 4 ] << 24 ) |
( ( unsigned int ) V_67 [ 5 ] << 16 ) |
( ( unsigned int ) V_67 [ 6 ] << 8 ) |
( unsigned int ) V_67 [ 7 ] ) ;
} else
F_22 ( V_2 , V_82 , V_4 ,
F_25 ( V_68 ) ) ;
F_22 ( V_2 , V_83 , V_4 , ( V_67 [ 0 ] << 8 ) | V_67 [ 1 ] ) ;
F_22 ( V_2 , V_84 , V_4 , V_61 | ( V_67 [ 3 ] << 24 ) ) ;
F_22 ( V_2 , V_85 , V_4 ,
( V_60 + ( V_28 ? V_2 -> V_75 : 0 ) ) |
( V_67 [ 2 ] << 24 ) ) ;
if ( V_2 -> V_86 -> V_87 )
V_42 = V_43 ;
else
V_42 = F_16 ( V_14 -> V_30 ) ;
if ( V_28 )
F_22 ( V_2 , V_18 , V_4 , V_60 |
F_17 ( V_42 ) |
( V_57 ? 0 : V_88 ) ) ;
else
F_22 ( V_2 , V_18 , V_4 , ( V_60 + V_70 ) |
F_17 ( V_42 ) |
( V_57 ? 0 : V_88 ) ) ;
F_22 ( V_2 , V_89 , V_4 , 0 ) ;
F_22 ( V_2 , V_90 , V_4 , 0 ) ;
V_64 = ( ( unsigned int ) V_2 -> V_64 . V_91 << 1 ) | V_92 ;
F_22 ( V_2 , V_93 , V_4 , V_64 ) ;
F_22 ( V_2 , V_94 , V_4 , V_64 ) ;
F_22 ( V_2 , V_95 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_96 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_97 , V_4 , 0 ) ;
F_22 ( V_2 , V_98 , V_4 , 0x007f ) ;
F_22 ( V_2 , V_99 , V_4 , 0x8000 ) ;
F_22 ( V_2 , V_100 , V_4 , 0x8000 ) ;
F_22 ( V_2 , V_101 , V_4 , 0 ) ;
F_22 ( V_2 , V_102 , V_4 , 0 ) ;
F_22 ( V_2 , V_103 , V_4 , 0 ) ;
F_22 ( V_2 , V_104 , V_4 , 0x8000 ) ;
F_22 ( V_2 , V_105 , V_4 , 0x7f7f ) ;
F_22 ( V_2 , V_106 , V_4 , 0x0000 ) ;
F_22 ( V_2 , V_107 , V_4 , 0x7f ) ;
F_22 ( V_2 , V_108 , V_4 , 0 ) ;
F_26 ( & V_2 -> V_73 , V_69 ) ;
}
static int F_27 ( struct V_12 * V_7 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
int V_23 ;
if ( ( V_23 = F_9 ( V_6 , F_28 ( V_110 ) ) ) < 0 )
return V_23 ;
if ( ( V_23 = F_29 ( V_7 , F_30 ( V_110 ) ) ) < 0 )
return V_23 ;
if ( V_23 > 0 ) {
int V_111 ;
if ( V_6 -> V_112 != NULL )
F_31 ( V_2 , V_6 -> V_112 ) ;
V_6 -> V_112 = F_32 ( V_2 , V_7 ) ;
V_6 -> V_60 = 0 ;
if ( ! V_6 -> V_112 )
return - V_113 ;
V_111 = ( (struct V_114 * ) V_6 -> V_112 ) -> V_115 ;
if ( V_111 < 0 )
return - V_113 ;
V_6 -> V_60 = V_111 << V_116 ;
}
return 0 ;
}
static int F_33 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 ;
if ( V_14 -> V_15 == NULL )
return 0 ;
V_6 = V_14 -> V_15 ;
if ( V_6 -> V_28 ) {
F_10 ( V_6 -> V_2 , V_6 -> V_28 ) ;
V_6 -> V_28 = NULL ;
}
if ( V_6 -> V_19 [ 1 ] ) {
F_10 ( V_6 -> V_2 , V_6 -> V_19 [ 1 ] ) ;
V_6 -> V_19 [ 1 ] = NULL ;
}
if ( V_6 -> V_19 [ 0 ] ) {
F_10 ( V_6 -> V_2 , V_6 -> V_19 [ 0 ] ) ;
V_6 -> V_19 [ 0 ] = NULL ;
}
if ( V_6 -> V_112 ) {
F_31 ( V_2 , V_6 -> V_112 ) ;
V_6 -> V_112 = NULL ;
V_6 -> V_60 = 0 ;
}
F_34 ( V_7 ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 ;
int V_24 ;
if ( V_14 -> V_15 == NULL )
return 0 ;
V_6 = V_14 -> V_15 ;
if ( V_6 -> V_28 ) {
F_10 ( V_6 -> V_2 , V_6 -> V_28 ) ;
V_6 -> V_28 = NULL ;
}
for ( V_24 = 0 ; V_24 < V_117 ; V_24 ++ ) {
if ( V_6 -> V_19 [ V_24 ] ) {
F_10 ( V_6 -> V_2 , V_6 -> V_19 [ V_24 ] ) ;
V_6 -> V_19 [ V_24 ] = NULL ;
}
}
if ( V_6 -> V_112 ) {
F_31 ( V_2 , V_6 -> V_112 ) ;
V_6 -> V_112 = NULL ;
V_6 -> V_60 = 0 ;
}
F_34 ( V_7 ) ;
return 0 ;
}
static int F_36 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
unsigned int V_60 , V_61 ;
V_60 = V_6 -> V_60 ;
V_61 = F_37 ( V_7 ) ;
if ( V_14 -> V_71 == 2 ) {
V_60 >>= 1 ;
V_61 >>= 1 ;
}
V_61 += V_60 ;
F_19 ( V_2 , 1 , 1 , V_6 -> V_28 ,
V_60 , V_61 , NULL ) ;
V_60 = V_6 -> V_60 ;
V_61 = V_6 -> V_60 + F_38 ( V_7 ) ;
F_19 ( V_2 , 1 , 0 , V_6 -> V_19 [ 0 ] ,
V_60 , V_61 ,
& V_2 -> V_118 [ V_7 -> V_20 ] ) ;
if ( V_6 -> V_19 [ 1 ] )
F_19 ( V_2 , 0 , 0 , V_6 -> V_19 [ 1 ] ,
V_60 , V_61 ,
& V_2 -> V_118 [ V_7 -> V_20 ] ) ;
return 0 ;
}
static int F_39 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
unsigned int V_60 , V_61 ;
unsigned int V_119 ;
int V_24 ;
V_60 = V_6 -> V_60 ;
V_61 = V_6 -> V_60 + F_38 ( V_7 ) ;
V_119 = ( V_61 - V_60 ) / V_117 ;
F_19 ( V_2 , 1 , 1 , V_6 -> V_28 ,
V_60 , V_60 + ( V_119 / 2 ) , NULL ) ;
F_19 ( V_2 , 1 , 0 , V_6 -> V_19 [ 0 ] ,
V_60 , V_60 + V_119 ,
& V_2 -> V_120 [ 0 ] ) ;
V_60 += V_119 ;
for ( V_24 = 1 ; V_24 < V_117 ; V_24 ++ ) {
F_19 ( V_2 , 0 , 0 , V_6 -> V_19 [ V_24 ] ,
V_60 , V_60 + V_119 ,
& V_2 -> V_120 [ V_24 ] ) ;
V_60 += V_119 ;
}
return 0 ;
}
static int F_40 ( struct V_12 * V_7 ,
struct V_109 * V_110 )
{
return F_29 ( V_7 , F_30 ( V_110 ) ) ;
}
static int F_41 ( struct V_12 * V_7 )
{
return F_34 ( V_7 ) ;
}
static int F_42 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
int V_121 ;
F_22 ( V_2 , V_6 -> V_122 , 0 , 0 ) ;
switch ( V_6 -> type ) {
case V_123 :
F_22 ( V_2 , V_124 , 0 , 0 ) ;
break;
case V_125 :
if ( V_2 -> V_78 ) {
F_22 ( V_2 , V_126 , 0 , 0 ) ;
F_22 ( V_2 , V_127 , 0 , 0 ) ;
} else
F_22 ( V_2 , V_128 , 0 , 0 ) ;
break;
default:
break;
}
F_22 ( V_2 , V_6 -> V_129 , 0 , V_14 -> V_130 ) ;
V_6 -> V_131 = F_38 ( V_7 ) ;
V_6 -> V_132 = 0 ;
for ( V_121 = 0 ; V_121 < 31 ; V_121 ++ ) {
if ( V_133 [ V_121 ] == V_6 -> V_131 ) {
V_6 -> V_132 = V_121 + 1 ;
break;
}
}
if ( V_6 -> V_132 == 0 ) {
F_14 () ;
V_6 -> V_132 ++ ;
}
if ( V_6 -> type == V_123 ) {
V_6 -> V_134 = V_2 -> V_78 ? V_135 : V_136 ;
if ( V_14 -> V_71 > 1 )
V_6 -> V_134 |= V_2 -> V_78 ? V_137 : V_138 ;
V_6 -> V_134 |= V_2 -> V_78 ?
F_15 ( V_14 -> V_30 ) :
F_13 ( V_14 -> V_30 ) ;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , int V_28 , struct V_3 * V_59 )
{
struct V_13 * V_14 ;
unsigned int V_4 , V_56 , V_24 , V_70 , V_139 = 64 , V_140 , V_141 ;
if ( V_59 == NULL )
return;
V_14 = V_59 -> V_6 -> V_7 -> V_14 ;
V_4 = V_59 -> V_20 ;
V_56 = ( ! V_28 && V_14 -> V_71 == 2 ) ;
V_141 = F_20 ( V_14 -> V_72 ) == 16 ? 0 : 0x80808080 ;
V_70 = F_18 ( V_56 , V_141 == 0 ) ;
V_140 = ( V_141 == 0 ) ? ( 32 - V_70 ) : ( 64 - V_70 + 1 ) >> 1 ;
if ( V_140 > 16 ) V_140 = 16 ;
for ( V_24 = 0 ; V_24 < V_140 ; V_24 ++ ) {
F_22 ( V_2 , V_142 + V_24 , V_4 , V_141 ) ;
if ( V_56 ) {
F_22 ( V_2 , V_142 + V_24 , V_4 + 1 , V_141 ) ;
}
}
F_22 ( V_2 , V_143 , V_4 , 0 ) ;
F_22 ( V_2 , V_144 , V_4 , V_139 ) ;
if ( V_56 ) {
F_22 ( V_2 , V_143 , V_4 + 1 , 0 ) ;
F_22 ( V_2 , V_144 , V_4 + 1 , V_139 ) ;
}
F_22 ( V_2 , V_143 , V_4 , V_70 ) ;
if ( V_56 ) {
F_22 ( V_2 , V_143 , V_4 + 1 , V_70 ) ;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_59 ,
int V_58 , int V_28 ,
struct V_62 * V_63 )
{
struct V_12 * V_7 ;
struct V_13 * V_14 ;
unsigned int V_66 , V_145 ;
unsigned int V_4 , V_65 ;
if ( V_59 == NULL )
return;
V_7 = V_59 -> V_6 -> V_7 ;
V_14 = V_7 -> V_14 ;
V_4 = V_59 -> V_20 ;
V_66 = V_28 ? 0 : 0x00ff ;
V_65 = V_14 -> V_71 == 2 ? ( V_58 ? 1 : 2 ) : 0 ;
V_145 = V_63 != NULL ? ( V_63 -> V_66 [ V_65 ] << 16 ) : 0 ;
F_22 ( V_2 , V_146 , V_4 , V_66 ) ;
F_22 ( V_2 , V_96 , V_4 , V_145 | 0xffff ) ;
F_22 ( V_2 , V_95 , V_4 , V_145 | 0xffff ) ;
F_22 ( V_2 , V_147 , V_4 , 0x7f7f ) ;
F_45 ( V_2 , V_4 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_59 , int V_58 , int V_28 )
{
struct V_12 * V_7 ;
struct V_13 * V_14 ;
unsigned int V_4 , V_148 , V_42 ;
if ( V_59 == NULL )
return;
V_7 = V_59 -> V_6 -> V_7 ;
V_14 = V_7 -> V_14 ;
V_4 = V_59 -> V_20 ;
V_148 = F_47 ( V_14 -> V_30 ) >> 8 ;
if ( V_2 -> V_86 -> V_87 )
V_42 = V_43 ;
else
V_42 = F_16 ( V_14 -> V_30 ) ;
F_22 ( V_2 , V_149 , V_4 , V_42 ) ;
if ( V_58 || V_59 -> V_6 -> type == V_150 )
F_22 ( V_2 , V_151 , V_4 , V_42 ) ;
F_22 ( V_2 , V_152 , V_4 , V_148 ) ;
if ( V_28 )
F_48 ( V_2 , V_4 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_3 * V_59 )
{
unsigned int V_4 ;
if ( V_59 == NULL )
return;
V_4 = V_59 -> V_20 ;
F_50 ( V_2 , V_4 ) ;
F_22 ( V_2 , V_149 , V_4 , 0 ) ;
F_22 ( V_2 , V_151 , V_4 , 0 ) ;
F_22 ( V_2 , V_146 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_96 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_95 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_152 , V_4 , 0 ) ;
}
static inline void F_51 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_12 * V_7 ,
struct V_13 * V_14 )
{
unsigned int V_16 , V_153 ;
V_153 = V_14 -> V_8 -> V_154 - V_14 -> V_155 ;
V_153 %= V_14 -> V_156 ;
V_16 = F_8 ( V_2 , V_18 , V_6 -> V_28 -> V_20 ) ;
V_16 &= ~ 0x00ffffff ;
V_16 |= V_6 -> V_22 + V_153 ;
F_22 ( V_2 , V_18 , V_6 -> V_28 -> V_20 , V_16 ) ;
}
static int F_52 ( struct V_12 * V_7 ,
int V_157 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
struct V_62 * V_63 ;
int V_158 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_157 ) {
case V_159 :
F_43 ( V_2 , 1 , V_6 -> V_28 ) ;
F_43 ( V_2 , 0 , V_6 -> V_19 [ 0 ] ) ;
case V_160 :
case V_161 :
if ( V_157 == V_160 )
F_51 ( V_2 , V_6 , V_7 , V_14 ) ;
V_63 = & V_2 -> V_118 [ V_7 -> V_20 ] ;
F_44 ( V_2 , V_6 -> V_19 [ 0 ] , 1 , 0 , V_63 ) ;
F_44 ( V_2 , V_6 -> V_19 [ 1 ] , 0 , 0 , V_63 ) ;
F_44 ( V_2 , V_6 -> V_28 , 1 , 1 , NULL ) ;
F_46 ( V_2 , V_6 -> V_19 [ 0 ] , 1 , 0 ) ;
F_46 ( V_2 , V_6 -> V_19 [ 1 ] , 0 , 0 ) ;
F_46 ( V_2 , V_6 -> V_28 , 1 , 1 ) ;
V_6 -> V_17 = 1 ;
break;
case V_162 :
case V_163 :
case V_164 :
V_6 -> V_17 = 0 ;
F_49 ( V_2 , V_6 -> V_19 [ 0 ] ) ;
F_49 ( V_2 , V_6 -> V_19 [ 1 ] ) ;
F_49 ( V_2 , V_6 -> V_28 ) ;
break;
default:
V_158 = - V_165 ;
break;
}
F_54 ( & V_2 -> V_73 ) ;
return V_158 ;
}
static int F_55 ( struct V_12 * V_7 ,
int V_157 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
int V_158 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_157 ) {
case V_159 :
case V_161 :
F_56 ( V_6 -> V_166 , V_2 -> V_167 + V_168 ) ;
F_57 ( V_2 , V_6 -> V_169 ) ;
switch ( V_6 -> type ) {
case V_123 :
F_22 ( V_2 , V_124 , 0 , V_6 -> V_134 ) ;
break;
case V_125 :
if ( V_2 -> V_78 ) {
F_22 ( V_2 , V_126 , 0 , V_6 -> V_134 ) ;
F_22 ( V_2 , V_127 , 0 , V_6 -> V_170 ) ;
F_58 ( L_1 , V_6 -> V_134 , V_6 -> V_170 ) ;
} else
F_22 ( V_2 , V_128 , 0 , V_6 -> V_134 ) ;
break;
default:
break;
}
F_22 ( V_2 , V_6 -> V_122 , 0 , V_6 -> V_132 ) ;
V_6 -> V_17 = 1 ;
V_6 -> V_171 = 1 ;
break;
case V_162 :
case V_164 :
V_6 -> V_17 = 0 ;
F_59 ( V_2 , V_6 -> V_169 ) ;
F_56 ( V_6 -> V_166 , V_2 -> V_167 + V_168 ) ;
F_22 ( V_2 , V_6 -> V_122 , 0 , 0 ) ;
switch ( V_6 -> type ) {
case V_123 :
F_22 ( V_2 , V_124 , 0 , 0 ) ;
break;
case V_125 :
if ( V_2 -> V_78 ) {
F_22 ( V_2 , V_126 , 0 , 0 ) ;
F_22 ( V_2 , V_127 , 0 , 0 ) ;
} else
F_22 ( V_2 , V_128 , 0 , 0 ) ;
break;
default:
break;
}
break;
default:
V_158 = - V_165 ;
}
F_54 ( & V_2 -> V_73 ) ;
return V_158 ;
}
static T_1 F_60 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
unsigned int V_16 ;
if ( ! V_6 -> V_17 )
return 0 ;
V_16 = F_8 ( V_2 , V_18 , V_6 -> V_19 [ 0 ] -> V_20 ) & 0x00ffffff ;
#if 0
ptr += runtime->buffer_size;
ptr -= epcm->ccca_start_addr;
ptr %= runtime->buffer_size;
#else
if ( V_16 < V_6 -> V_22 )
V_16 += V_14 -> V_21 - V_6 -> V_22 ;
else {
V_16 -= V_6 -> V_22 ;
if ( V_16 >= V_14 -> V_21 )
V_16 -= V_14 -> V_21 ;
}
#endif
return V_16 ;
}
static int F_61 ( struct V_12 * V_7 ,
int V_157 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
int V_24 ;
int V_158 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_157 ) {
case V_159 :
for ( V_24 = 0 ; V_24 < V_117 ; V_24 ++ ) {
F_43 ( V_2 , 0 , V_6 -> V_19 [ V_24 ] ) ;
}
F_43 ( V_2 , 1 , V_6 -> V_28 ) ;
case V_160 :
case V_161 :
F_44 ( V_2 , V_6 -> V_28 , 1 , 1 , NULL ) ;
F_44 ( V_2 , V_6 -> V_19 [ 0 ] , 0 , 0 ,
& V_2 -> V_120 [ 0 ] ) ;
for ( V_24 = 1 ; V_24 < V_117 ; V_24 ++ )
F_44 ( V_2 , V_6 -> V_19 [ V_24 ] , 0 , 0 ,
& V_2 -> V_120 [ V_24 ] ) ;
F_46 ( V_2 , V_6 -> V_19 [ 0 ] , 0 , 0 ) ;
F_46 ( V_2 , V_6 -> V_28 , 1 , 1 ) ;
for ( V_24 = 1 ; V_24 < V_117 ; V_24 ++ )
F_46 ( V_2 , V_6 -> V_19 [ V_24 ] , 0 , 0 ) ;
V_6 -> V_17 = 1 ;
break;
case V_164 :
case V_162 :
case V_163 :
V_6 -> V_17 = 0 ;
for ( V_24 = 0 ; V_24 < V_117 ; V_24 ++ ) {
F_49 ( V_2 , V_6 -> V_19 [ V_24 ] ) ;
}
F_49 ( V_2 , V_6 -> V_28 ) ;
break;
default:
V_158 = - V_165 ;
break;
}
F_54 ( & V_2 -> V_73 ) ;
return V_158 ;
}
static T_1 F_62 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
unsigned int V_16 ;
if ( ! V_6 -> V_17 )
return 0 ;
if ( V_6 -> V_171 ) {
F_63 ( 50 ) ;
V_6 -> V_171 = 0 ;
}
V_16 = F_8 ( V_2 , V_6 -> V_172 , 0 ) & 0x0000ffff ;
return F_64 ( V_14 , V_16 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_173 * V_174 , int V_121 , int V_175 )
{
struct V_176 V_177 ;
if ( ! V_174 )
return;
if ( V_175 )
V_174 -> V_178 [ V_121 ] . V_179 &= ~ V_180 ;
else
V_174 -> V_178 [ V_121 ] . V_179 |= V_180 ;
F_66 ( V_2 -> V_181 , V_182 |
V_183 ,
F_67 ( & V_177 , V_174 , V_121 ) ) ;
}
static void F_68 ( struct V_1 * V_2 , int V_121 , int V_175 )
{
F_65 ( V_2 , V_2 -> V_184 , V_121 , V_175 ) ;
F_65 ( V_2 , V_2 -> V_185 , V_121 , V_175 ) ;
F_65 ( V_2 , V_2 -> V_186 , V_121 , V_175 ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_121 , int V_175 )
{
F_65 ( V_2 , V_2 -> V_187 , V_121 , V_175 ) ;
F_65 ( V_2 , V_2 -> V_188 , V_121 , V_175 ) ;
F_65 ( V_2 , V_2 -> V_189 , V_121 , V_175 ) ;
}
static void F_70 ( struct V_13 * V_14 )
{
F_71 ( V_14 -> V_15 ) ;
}
static int F_72 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_62 * V_63 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_117 ; V_24 ++ ) {
V_63 = & V_2 -> V_120 [ V_24 ] ;
V_63 -> V_6 = NULL ;
F_69 ( V_2 , V_24 , 0 ) ;
}
return 0 ;
}
static int F_73 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_5 * V_6 ;
struct V_62 * V_63 ;
struct V_13 * V_14 = V_7 -> V_14 ;
int V_24 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_190 ) ;
if ( V_6 == NULL )
return - V_113 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_150 ;
V_6 -> V_7 = V_7 ;
V_2 -> V_191 = V_7 ;
V_14 -> V_15 = V_6 ;
V_14 -> V_192 = F_70 ;
V_14 -> V_193 = V_194 ;
for ( V_24 = 0 ; V_24 < V_117 ; V_24 ++ ) {
V_63 = & V_2 -> V_120 [ V_24 ] ;
V_63 -> V_68 [ 0 ] [ 0 ] = V_24 ;
memset ( & V_63 -> V_74 , 0 , sizeof( V_63 -> V_74 ) ) ;
V_63 -> V_74 [ 0 ] [ 0 ] = 255 ;
V_63 -> V_66 [ 0 ] = 0xffff ;
V_63 -> V_6 = V_6 ;
F_69 ( V_2 , V_24 , 1 ) ;
}
return 0 ;
}
static int F_75 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_5 * V_6 ;
struct V_62 * V_63 ;
struct V_13 * V_14 = V_7 -> V_14 ;
int V_24 , V_23 , V_195 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_190 ) ;
if ( V_6 == NULL )
return - V_113 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_25 ;
V_6 -> V_7 = V_7 ;
V_14 -> V_15 = V_6 ;
V_14 -> V_192 = F_70 ;
V_14 -> V_193 = V_196 ;
if ( ( V_23 = F_76 ( V_14 , V_197 ) ) < 0 ) {
F_71 ( V_6 ) ;
return V_23 ;
}
if ( ( V_23 = F_77 ( V_14 , V_198 , 256 , V_199 ) ) < 0 ) {
F_71 ( V_6 ) ;
return V_23 ;
}
if ( V_2 -> V_86 -> V_87 && V_2 -> V_200 . V_201 == 0 )
V_195 = 44100 ;
else
V_195 = 48000 ;
V_23 = F_78 ( V_14 , V_195 ) ;
if ( V_23 < 0 ) {
F_71 ( V_6 ) ;
return V_23 ;
}
V_63 = & V_2 -> V_118 [ V_7 -> V_20 ] ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ )
V_63 -> V_68 [ 0 ] [ V_24 ] = V_63 -> V_68 [ 1 ] [ V_24 ] = V_63 -> V_68 [ 2 ] [ V_24 ] = V_24 ;
memset ( & V_63 -> V_74 , 0 , sizeof( V_63 -> V_74 ) ) ;
V_63 -> V_74 [ 0 ] [ 0 ] = V_63 -> V_74 [ 0 ] [ 1 ] =
V_63 -> V_74 [ 1 ] [ 0 ] = V_63 -> V_74 [ 2 ] [ 1 ] = 255 ;
V_63 -> V_66 [ 0 ] = V_63 -> V_66 [ 1 ] = V_63 -> V_66 [ 2 ] = 0xffff ;
V_63 -> V_6 = V_6 ;
F_68 ( V_2 , V_7 -> V_20 , 1 ) ;
return 0 ;
}
static int F_79 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_62 * V_63 = & V_2 -> V_118 [ V_7 -> V_20 ] ;
V_63 -> V_6 = NULL ;
F_68 ( V_2 , V_7 -> V_20 , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_190 ) ;
if ( V_6 == NULL )
return - V_113 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_123 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_166 = V_202 | V_203 ;
V_6 -> V_169 = V_204 ;
V_6 -> V_129 = V_205 ;
V_6 -> V_122 = V_206 ;
V_6 -> V_172 = V_2 -> V_78 ? V_207 : V_208 ;
V_14 -> V_15 = V_6 ;
V_14 -> V_192 = F_70 ;
V_14 -> V_193 = V_209 ;
V_2 -> V_210 = F_3 ;
V_2 -> V_9 = V_7 ;
F_81 ( V_14 , 0 , V_211 , & V_212 ) ;
F_81 ( V_14 , 0 , V_213 , & V_214 ) ;
return 0 ;
}
static int F_82 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
V_2 -> V_210 = NULL ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static int F_83 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_5 * V_6 ;
struct V_13 * V_14 = V_7 -> V_14 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_190 ) ;
if ( V_6 == NULL )
return - V_113 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_215 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_166 = V_216 | V_217 ;
V_6 -> V_169 = V_218 ;
V_6 -> V_129 = V_219 ;
V_6 -> V_122 = V_220 ;
V_6 -> V_172 = V_2 -> V_78 ? V_221 : V_222 ;
V_7 -> V_14 -> V_15 = V_6 ;
V_7 -> V_14 -> V_192 = F_70 ;
V_14 -> V_193 = V_209 ;
V_14 -> V_193 . V_223 = V_224 ;
V_14 -> V_193 . V_225 = V_14 -> V_193 . V_226 = 8000 ;
V_14 -> V_193 . V_227 = 1 ;
V_2 -> V_228 = F_4 ;
V_2 -> V_10 = V_7 ;
F_81 ( V_14 , 0 , V_211 , & V_212 ) ;
return 0 ;
}
static int F_84 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
V_2 -> V_210 = NULL ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static int F_85 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_5 * V_6 ;
struct V_13 * V_14 = V_7 -> V_14 ;
int V_229 = V_2 -> V_78 ? 64 : 32 ;
int V_121 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_190 ) ;
if ( V_6 == NULL )
return - V_113 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_125 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_166 = V_230 | V_231 ;
V_6 -> V_169 = V_232 ;
V_6 -> V_129 = V_233 ;
V_6 -> V_122 = V_234 ;
V_6 -> V_172 = V_235 ;
V_7 -> V_14 -> V_15 = V_6 ;
V_7 -> V_14 -> V_192 = F_70 ;
V_14 -> V_193 = V_236 ;
V_14 -> V_193 . V_223 = V_237 ;
V_14 -> V_193 . V_225 = V_14 -> V_193 . V_226 = 48000 ;
F_86 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_86 -> V_87 ) {
#if 1
switch ( V_2 -> V_200 . V_201 ) {
case 0 :
V_14 -> V_193 . V_223 = V_238 ;
V_14 -> V_193 . V_225 = V_14 -> V_193 . V_226 = 44100 ;
V_14 -> V_193 . V_227 =
V_14 -> V_193 . V_239 = 16 ;
break;
case 1 :
V_14 -> V_193 . V_223 = V_237 ;
V_14 -> V_193 . V_225 = V_14 -> V_193 . V_226 = 48000 ;
V_14 -> V_193 . V_227 =
V_14 -> V_193 . V_239 = 16 ;
break;
}
#endif
#if 0
runtime->hw.rates = SNDRV_PCM_RATE_96000;
runtime->hw.rate_min = runtime->hw.rate_max = 96000;
runtime->hw.channels_min = runtime->hw.channels_max = 4;
#endif
#if 0
runtime->hw.rates = SNDRV_PCM_RATE_192000;
runtime->hw.rate_min = runtime->hw.rate_max = 192000;
runtime->hw.channels_min = runtime->hw.channels_max = 2;
#endif
V_14 -> V_193 . V_240 = V_241 ;
} else {
V_14 -> V_193 . V_227 = V_14 -> V_193 . V_239 = 0 ;
for ( V_121 = 0 ; V_121 < V_229 ; V_121 ++ ) {
if ( V_2 -> V_242 [ V_121 / 32 ] & ( 1 << ( V_121 % 32 ) ) ) {
V_14 -> V_193 . V_227 ++ ;
V_14 -> V_193 . V_239 ++ ;
}
}
}
V_6 -> V_134 = V_2 -> V_242 [ 0 ] ;
V_6 -> V_170 = V_2 -> V_242 [ 1 ] ;
F_87 ( & V_2 -> V_73 ) ;
V_2 -> V_243 = F_5 ;
V_2 -> V_11 = V_7 ;
F_81 ( V_14 , 0 , V_211 , & V_212 ) ;
return 0 ;
}
static int F_88 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
V_2 -> V_210 = NULL ;
V_2 -> V_11 = NULL ;
return 0 ;
}
int V_5 ( struct V_1 * V_2 , int V_244 , struct V_245 * * V_246 )
{
struct V_245 * V_247 ;
struct V_12 * V_7 ;
int V_23 ;
if ( V_246 )
* V_246 = NULL ;
if ( ( V_23 = F_89 ( V_2 -> V_181 , L_2 , V_244 , 32 , 1 , & V_247 ) ) < 0 )
return V_23 ;
V_247 -> V_15 = V_2 ;
F_90 ( V_247 , V_248 , & V_249 ) ;
F_90 ( V_247 , V_250 , & V_251 ) ;
V_247 -> V_252 = 0 ;
V_247 -> V_253 = V_254 ;
strcpy ( V_247 -> V_255 , L_3 ) ;
V_2 -> V_247 = V_247 ;
for ( V_7 = V_247 -> V_256 [ V_248 ] . V_7 ; V_7 ; V_7 = V_7 -> V_257 )
if ( ( V_23 = F_91 ( V_7 , V_258 , F_92 ( V_2 -> V_259 ) , 64 * 1024 , 64 * 1024 ) ) < 0 )
return V_23 ;
for ( V_7 = V_247 -> V_256 [ V_250 ] . V_7 ; V_7 ; V_7 = V_7 -> V_257 )
F_91 ( V_7 , V_260 , F_92 ( V_2 -> V_259 ) , 64 * 1024 , 64 * 1024 ) ;
if ( V_246 )
* V_246 = V_247 ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , int V_244 ,
struct V_245 * * V_246 )
{
struct V_245 * V_247 ;
struct V_12 * V_7 ;
int V_23 ;
if ( V_246 )
* V_246 = NULL ;
if ( ( V_23 = F_89 ( V_2 -> V_181 , L_2 , V_244 , 1 , 0 , & V_247 ) ) < 0 )
return V_23 ;
V_247 -> V_15 = V_2 ;
F_90 ( V_247 , V_248 , & V_261 ) ;
V_247 -> V_252 = 0 ;
V_247 -> V_253 = V_254 ;
strcpy ( V_247 -> V_255 , L_4 ) ;
V_2 -> V_262 = V_247 ;
for ( V_7 = V_247 -> V_256 [ V_248 ] . V_7 ; V_7 ; V_7 = V_7 -> V_257 )
if ( ( V_23 = F_91 ( V_7 , V_258 , F_92 ( V_2 -> V_259 ) , 64 * 1024 , 64 * 1024 ) ) < 0 )
return V_23 ;
if ( V_246 )
* V_246 = V_247 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , int V_244 ,
struct V_245 * * V_246 )
{
struct V_245 * V_247 ;
int V_23 ;
if ( V_246 )
* V_246 = NULL ;
if ( ( V_23 = F_89 ( V_2 -> V_181 , L_5 , V_244 , 0 , 1 , & V_247 ) ) < 0 )
return V_23 ;
V_247 -> V_15 = V_2 ;
F_90 ( V_247 , V_250 , & V_263 ) ;
V_247 -> V_252 = 0 ;
strcpy ( V_247 -> V_255 , L_6 ) ;
V_2 -> V_264 = V_247 ;
F_95 ( V_247 , V_260 , F_92 ( V_2 -> V_259 ) , 64 * 1024 , 64 * 1024 ) ;
if ( V_246 )
* V_246 = V_247 ;
return 0 ;
}
static int F_96 ( struct V_173 * V_265 , struct V_266 * V_267 )
{
struct V_1 * V_2 = F_97 ( V_265 ) ;
int V_229 = V_2 -> V_78 ? 64 : 32 ;
V_267 -> type = V_268 ;
V_267 -> V_269 = V_229 ;
V_267 -> V_270 . integer . V_271 = 0 ;
V_267 -> V_270 . integer . V_272 = 1 ;
return 0 ;
}
static int F_98 ( struct V_173 * V_265 , struct V_273 * V_274 )
{
struct V_1 * V_2 = F_97 ( V_265 ) ;
int V_229 = V_2 -> V_78 ? 64 : 32 ;
int V_121 ;
F_86 ( & V_2 -> V_73 ) ;
for ( V_121 = 0 ; V_121 < V_229 ; V_121 ++ )
V_274 -> V_270 . integer . V_270 [ V_121 ] = ( V_2 -> V_242 [ V_121 / 32 ] & ( 1 << ( V_121 % 32 ) ) ) ? 1 : 0 ;
F_87 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_99 ( struct V_173 * V_265 , struct V_273 * V_274 )
{
struct V_1 * V_2 = F_97 ( V_265 ) ;
unsigned int V_275 [ 2 ] , V_276 ;
int V_229 = V_2 -> V_78 ? 64 : 32 ;
int V_277 = V_2 -> V_78 ? 7 : 6 ;
int V_278 , V_121 ;
V_275 [ 0 ] = V_275 [ 1 ] = 0 ;
for ( V_121 = 0 , V_276 = 0 ; V_121 < V_229 ; V_121 ++ )
if ( V_274 -> V_270 . integer . V_270 [ V_121 ] ) {
V_275 [ V_121 / 32 ] |= 1 << ( V_121 % 32 ) ;
V_276 ++ ;
}
for ( V_121 = 0 ; V_121 < V_277 ; V_121 ++ )
if ( 1 << V_121 == V_276 )
break;
if ( V_121 >= V_277 )
return - V_165 ;
F_86 ( & V_2 -> V_73 ) ;
V_278 = ( V_275 [ 0 ] != V_2 -> V_242 [ 0 ] ) ||
( V_275 [ 1 ] != V_2 -> V_242 [ 1 ] ) ;
V_2 -> V_242 [ 0 ] = V_275 [ 0 ] ;
V_2 -> V_242 [ 1 ] = V_275 [ 1 ] ;
F_87 ( & V_2 -> V_73 ) ;
return V_278 ;
}
static void F_100 ( struct V_1 * V_2 , void * V_15 )
{
struct V_12 * V_7 = V_15 ;
F_2 ( V_7 ) ;
}
static void F_101 ( unsigned short * V_279 ,
unsigned short * V_280 ,
unsigned short * V_281 ,
unsigned int V_269 ,
unsigned int V_282 )
{
if ( ( V_282 & 1 ) == 0 ) {
while ( V_269 -- ) {
* V_279 -- = * V_281 ++ ;
* V_280 -- = * V_281 ++ ;
}
} else {
while ( V_269 -- ) {
* V_280 -- = * V_281 ++ ;
* V_279 -- = * V_281 ++ ;
}
}
}
static void F_102 ( struct V_12 * V_7 ,
struct V_283 * V_284 , T_2 V_285 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
unsigned int V_288 = V_247 -> V_21 ;
unsigned short * V_281 = ( unsigned short * ) ( V_7 -> V_14 -> V_289 + V_284 -> V_290 ) ;
unsigned int V_291 = V_285 >> 2 , V_269 ;
unsigned int V_292 = V_247 -> V_292 ;
unsigned int V_282 = V_247 -> V_282 ;
while ( V_291 > V_292 ) {
V_269 = V_292 + 1 ;
F_101 ( ( unsigned short * ) V_2 -> V_287 . V_293 . V_294 + V_292 ,
( unsigned short * ) V_2 -> V_287 . V_293 . V_294 + V_292 + V_288 / 2 ,
V_281 , V_269 , V_282 ) ;
V_281 += V_269 * 2 ;
V_291 -= V_269 ;
V_292 = ( V_288 / 2 ) - 1 ;
V_282 ++ ;
}
F_101 ( ( unsigned short * ) V_2 -> V_287 . V_293 . V_294 + V_292 ,
( unsigned short * ) V_2 -> V_287 . V_293 . V_294 + V_292 + V_288 / 2 ,
V_281 , V_291 , V_282 ) ;
V_292 -= V_291 ;
V_247 -> V_292 = V_292 ;
V_247 -> V_282 = V_282 ;
}
static int F_103 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
F_104 ( V_7 , & V_247 -> V_295 , F_102 ) ;
return 0 ;
}
static int F_105 ( struct V_12 * V_7 ,
struct V_109 * V_110 )
{
return F_29 ( V_7 , F_30 ( V_110 ) ) ;
}
static int F_106 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_247 -> V_71 ; V_24 ++ )
F_22 ( V_2 , V_296 + 0x80 + V_247 -> V_297 [ V_24 ] , 0 , 0 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static int F_107 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
unsigned int V_24 ;
memset ( & V_247 -> V_295 , 0 , sizeof( V_247 -> V_295 ) ) ;
V_247 -> V_295 . V_298 = V_247 -> V_21 * 2 ;
V_247 -> V_295 . V_299 = F_38 ( V_7 ) ;
V_247 -> V_292 = F_108 ( V_247 -> V_21 ) ;
V_247 -> V_282 = 0 ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_301 , 0 , 0 ) ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_302 , 0 , 0 ) ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_303 , 0 , V_14 -> V_21 ) ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_304 , 0 , 0 ) ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_305 , 0 , V_14 -> V_156 ) ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_306 , 0 , V_14 -> V_156 ) ;
for ( V_24 = 0 ; V_24 < V_247 -> V_71 ; V_24 ++ )
F_22 ( V_2 , V_296 + 0x80 + V_247 -> V_297 [ V_24 ] , 0 , ( V_307 | V_308 ) + V_24 * ( V_14 -> V_21 / V_247 -> V_71 ) ) ;
return 0 ;
}
static int F_109 ( struct V_12 * V_7 , int V_157 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
int V_158 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_157 ) {
case V_159 :
case V_160 :
case V_161 :
#ifdef F_110
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 3 ; V_24 ++ ) {
unsigned int V_276 ;
V_276 = V_309 | V_310 |
V_311 | V_312 | V_313 |
0x00001200 | V_314 | V_315 | V_316 ;
F_22 ( V_2 , V_317 + V_24 , 0 , V_276 ) ;
}
}
#endif
V_158 = F_111 ( V_2 , F_100 , V_247 -> V_301 , V_7 , & V_247 -> V_318 ) ;
if ( V_158 < 0 )
goto V_319;
F_103 ( V_7 ) ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_302 , 0 , 1 ) ;
break;
case V_162 :
case V_163 :
case V_164 :
F_112 ( V_2 , V_247 -> V_318 ) ; V_247 -> V_318 = NULL ;
F_22 ( V_2 , V_2 -> V_300 + V_247 -> V_302 , 0 , 0 ) ;
V_247 -> V_292 = F_108 ( V_247 -> V_21 ) ;
V_247 -> V_282 = 0 ;
break;
default:
V_158 = - V_165 ;
break;
}
V_319:
F_54 ( & V_2 -> V_73 ) ;
return V_158 ;
}
static T_1 F_113 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
T_2 V_16 ;
if ( ! F_8 ( V_2 , V_2 -> V_300 + V_247 -> V_302 , 0 ) )
return 0 ;
V_16 = F_8 ( V_2 , V_2 -> V_300 + V_247 -> V_304 , 0 ) << 2 ;
return F_114 ( V_7 , & V_247 -> V_295 , V_16 ) ;
}
static int F_115 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
V_14 -> V_193 = V_320 ;
V_14 -> V_193 . V_227 = V_14 -> V_193 . V_239 = V_247 -> V_71 ;
V_14 -> V_193 . V_321 = ( V_247 -> V_21 * 2 ) / 2 ;
F_86 ( & V_2 -> V_73 ) ;
if ( V_247 -> V_322 == 0 ) {
F_87 ( & V_2 -> V_73 ) ;
return - V_323 ;
}
V_247 -> V_324 = 1 ;
F_87 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_116 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_286 * V_247 = & V_2 -> V_287 . V_247 [ V_7 -> V_20 ] ;
F_86 ( & V_2 -> V_73 ) ;
V_247 -> V_324 = 0 ;
F_87 ( & V_2 -> V_73 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , int V_244 ,
struct V_245 * * V_246 )
{
struct V_245 * V_247 ;
struct V_173 * V_174 ;
int V_23 ;
if ( V_246 )
* V_246 = NULL ;
if ( ( V_23 = F_89 ( V_2 -> V_181 , L_7 , V_244 , 8 , 1 , & V_247 ) ) < 0 )
return V_23 ;
V_247 -> V_15 = V_2 ;
F_90 ( V_247 , V_248 , & V_325 ) ;
F_90 ( V_247 , V_250 , & V_326 ) ;
V_247 -> V_252 = 0 ;
strcpy ( V_247 -> V_255 , L_8 ) ;
V_2 -> V_327 = V_247 ;
if ( V_246 )
* V_246 = V_247 ;
if ( V_2 -> V_78 ) {
V_2 -> V_242 [ 0 ] = 0 ;
if ( V_2 -> V_86 -> V_87 )
V_2 -> V_242 [ 1 ] = 0xffffffff ;
else
V_2 -> V_242 [ 1 ] = 0xffff ;
} else {
V_2 -> V_242 [ 0 ] = 0xffff0000 ;
V_2 -> V_242 [ 1 ] = 0 ;
}
V_174 = F_118 ( & V_328 , V_2 ) ;
if ( ! V_174 )
return - V_113 ;
V_174 -> V_177 . V_244 = V_244 ;
F_119 ( V_2 -> V_181 , V_174 ) ;
F_95 ( V_247 , V_260 , F_92 ( V_2 -> V_259 ) , 64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
