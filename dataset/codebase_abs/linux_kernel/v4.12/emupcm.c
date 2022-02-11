static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ( V_6 = V_4 -> V_6 ) == NULL )
return;
if ( V_6 -> V_7 == NULL )
return;
#if 0
dev_dbg(emu->card->dev,
"IRQ: position = 0x%x, period = 0x%x, size = 0x%x\n",
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
V_64 = ( ( unsigned int ) V_2 -> V_64 . V_91 << V_2 -> V_92 ) | ( V_2 -> V_92 ? V_93 : V_94 ) ;
F_22 ( V_2 , V_95 , V_4 , V_64 ) ;
F_22 ( V_2 , V_96 , V_4 , V_64 ) ;
F_22 ( V_2 , V_97 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_98 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_99 , V_4 , 0 ) ;
F_22 ( V_2 , V_100 , V_4 , 0x007f ) ;
F_22 ( V_2 , V_101 , V_4 , 0x8000 ) ;
F_22 ( V_2 , V_102 , V_4 , 0x8000 ) ;
F_22 ( V_2 , V_103 , V_4 , 0 ) ;
F_22 ( V_2 , V_104 , V_4 , 0 ) ;
F_22 ( V_2 , V_105 , V_4 , 0 ) ;
F_22 ( V_2 , V_106 , V_4 , 0x8000 ) ;
F_22 ( V_2 , V_107 , V_4 , 0x7f7f ) ;
F_22 ( V_2 , V_108 , V_4 , 0x0000 ) ;
F_22 ( V_2 , V_109 , V_4 , 0x7f ) ;
F_22 ( V_2 , V_110 , V_4 , 0 ) ;
F_26 ( & V_2 -> V_73 , V_69 ) ;
}
static int F_27 ( struct V_12 * V_7 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
int V_23 ;
if ( ( V_23 = F_9 ( V_6 , F_28 ( V_112 ) ) ) < 0 )
return V_23 ;
if ( ( V_23 = F_29 ( V_7 , F_30 ( V_112 ) ) ) < 0 )
return V_23 ;
if ( V_23 > 0 ) {
int V_113 ;
if ( V_6 -> V_114 != NULL )
F_31 ( V_2 , V_6 -> V_114 ) ;
V_6 -> V_114 = F_32 ( V_2 , V_7 ) ;
V_6 -> V_60 = 0 ;
if ( ! V_6 -> V_114 )
return - V_115 ;
V_113 = ( (struct V_116 * ) V_6 -> V_114 ) -> V_117 ;
if ( V_113 < 0 )
return - V_115 ;
V_6 -> V_60 = V_113 << V_118 ;
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
if ( V_6 -> V_114 ) {
F_31 ( V_2 , V_6 -> V_114 ) ;
V_6 -> V_114 = NULL ;
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
for ( V_24 = 0 ; V_24 < V_119 ; V_24 ++ ) {
if ( V_6 -> V_19 [ V_24 ] ) {
F_10 ( V_6 -> V_2 , V_6 -> V_19 [ V_24 ] ) ;
V_6 -> V_19 [ V_24 ] = NULL ;
}
}
if ( V_6 -> V_114 ) {
F_31 ( V_2 , V_6 -> V_114 ) ;
V_6 -> V_114 = NULL ;
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
& V_2 -> V_120 [ V_7 -> V_20 ] ) ;
if ( V_6 -> V_19 [ 1 ] )
F_19 ( V_2 , 0 , 0 , V_6 -> V_19 [ 1 ] ,
V_60 , V_61 ,
& V_2 -> V_120 [ V_7 -> V_20 ] ) ;
return 0 ;
}
static int F_39 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
unsigned int V_60 , V_61 ;
unsigned int V_121 ;
int V_24 ;
V_60 = V_6 -> V_60 ;
V_61 = V_6 -> V_60 + F_38 ( V_7 ) ;
V_121 = ( V_61 - V_60 ) / V_119 ;
F_19 ( V_2 , 1 , 1 , V_6 -> V_28 ,
V_60 , V_60 + ( V_121 / 2 ) , NULL ) ;
F_19 ( V_2 , 1 , 0 , V_6 -> V_19 [ 0 ] ,
V_60 , V_60 + V_121 ,
& V_2 -> V_122 [ 0 ] ) ;
V_60 += V_121 ;
for ( V_24 = 1 ; V_24 < V_119 ; V_24 ++ ) {
F_19 ( V_2 , 0 , 0 , V_6 -> V_19 [ V_24 ] ,
V_60 , V_60 + V_121 ,
& V_2 -> V_122 [ V_24 ] ) ;
V_60 += V_121 ;
}
return 0 ;
}
static int F_40 ( struct V_12 * V_7 ,
struct V_111 * V_112 )
{
return F_29 ( V_7 , F_30 ( V_112 ) ) ;
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
int V_123 ;
F_22 ( V_2 , V_6 -> V_124 , 0 , 0 ) ;
switch ( V_6 -> type ) {
case V_125 :
F_22 ( V_2 , V_126 , 0 , 0 ) ;
break;
case V_127 :
if ( V_2 -> V_78 ) {
F_22 ( V_2 , V_128 , 0 , 0 ) ;
F_22 ( V_2 , V_129 , 0 , 0 ) ;
} else
F_22 ( V_2 , V_130 , 0 , 0 ) ;
break;
default:
break;
}
F_22 ( V_2 , V_6 -> V_131 , 0 , V_14 -> V_132 ) ;
V_6 -> V_133 = F_38 ( V_7 ) ;
V_6 -> V_134 = 0 ;
for ( V_123 = 0 ; V_123 < 31 ; V_123 ++ ) {
if ( V_135 [ V_123 ] == V_6 -> V_133 ) {
V_6 -> V_134 = V_123 + 1 ;
break;
}
}
if ( V_6 -> V_134 == 0 ) {
F_14 () ;
V_6 -> V_134 ++ ;
}
if ( V_6 -> type == V_125 ) {
V_6 -> V_136 = V_2 -> V_78 ? V_137 : V_138 ;
if ( V_14 -> V_71 > 1 )
V_6 -> V_136 |= V_2 -> V_78 ? V_139 : V_140 ;
V_6 -> V_136 |= V_2 -> V_78 ?
F_15 ( V_14 -> V_30 ) :
F_13 ( V_14 -> V_30 ) ;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , int V_28 , struct V_3 * V_59 )
{
struct V_13 * V_14 ;
unsigned int V_4 , V_56 , V_24 , V_70 , V_141 = 64 , V_142 , V_143 ;
if ( V_59 == NULL )
return;
V_14 = V_59 -> V_6 -> V_7 -> V_14 ;
V_4 = V_59 -> V_20 ;
V_56 = ( ! V_28 && V_14 -> V_71 == 2 ) ;
V_143 = F_20 ( V_14 -> V_72 ) == 16 ? 0 : 0x80808080 ;
V_70 = F_18 ( V_56 , V_143 == 0 ) ;
V_142 = ( V_143 == 0 ) ? ( 32 - V_70 ) : ( 64 - V_70 + 1 ) >> 1 ;
if ( V_142 > 16 ) V_142 = 16 ;
for ( V_24 = 0 ; V_24 < V_142 ; V_24 ++ ) {
F_22 ( V_2 , V_144 + V_24 , V_4 , V_143 ) ;
if ( V_56 ) {
F_22 ( V_2 , V_144 + V_24 , V_4 + 1 , V_143 ) ;
}
}
F_22 ( V_2 , V_145 , V_4 , 0 ) ;
F_22 ( V_2 , V_146 , V_4 , V_141 ) ;
if ( V_56 ) {
F_22 ( V_2 , V_145 , V_4 + 1 , 0 ) ;
F_22 ( V_2 , V_146 , V_4 + 1 , V_141 ) ;
}
F_22 ( V_2 , V_145 , V_4 , V_70 ) ;
if ( V_56 ) {
F_22 ( V_2 , V_145 , V_4 + 1 , V_70 ) ;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_59 ,
int V_58 , int V_28 ,
struct V_62 * V_63 )
{
struct V_12 * V_7 ;
struct V_13 * V_14 ;
unsigned int V_66 , V_147 ;
unsigned int V_4 , V_65 ;
if ( V_59 == NULL )
return;
V_7 = V_59 -> V_6 -> V_7 ;
V_14 = V_7 -> V_14 ;
V_4 = V_59 -> V_20 ;
V_66 = V_28 ? 0 : 0x00ff ;
V_65 = V_14 -> V_71 == 2 ? ( V_58 ? 1 : 2 ) : 0 ;
V_147 = V_63 != NULL ? ( V_63 -> V_66 [ V_65 ] << 16 ) : 0 ;
F_22 ( V_2 , V_148 , V_4 , V_66 ) ;
F_22 ( V_2 , V_98 , V_4 , V_147 | 0xffff ) ;
F_22 ( V_2 , V_97 , V_4 , V_147 | 0xffff ) ;
F_22 ( V_2 , V_149 , V_4 , 0x7f7f ) ;
F_45 ( V_2 , V_4 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_59 , int V_58 , int V_28 )
{
struct V_12 * V_7 ;
struct V_13 * V_14 ;
unsigned int V_4 , V_150 , V_42 ;
if ( V_59 == NULL )
return;
V_7 = V_59 -> V_6 -> V_7 ;
V_14 = V_7 -> V_14 ;
V_4 = V_59 -> V_20 ;
V_150 = F_47 ( V_14 -> V_30 ) >> 8 ;
if ( V_2 -> V_86 -> V_87 )
V_42 = V_43 ;
else
V_42 = F_16 ( V_14 -> V_30 ) ;
F_22 ( V_2 , V_151 , V_4 , V_42 ) ;
if ( V_58 || V_59 -> V_6 -> type == V_152 )
F_22 ( V_2 , V_153 , V_4 , V_42 ) ;
F_22 ( V_2 , V_154 , V_4 , V_150 ) ;
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
F_22 ( V_2 , V_151 , V_4 , 0 ) ;
F_22 ( V_2 , V_153 , V_4 , 0 ) ;
F_22 ( V_2 , V_148 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_98 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_97 , V_4 , 0xffff ) ;
F_22 ( V_2 , V_154 , V_4 , 0 ) ;
}
static inline void F_51 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_12 * V_7 ,
struct V_13 * V_14 )
{
unsigned int V_16 , V_155 ;
V_155 = V_14 -> V_8 -> V_156 - V_14 -> V_157 ;
V_155 %= V_14 -> V_158 ;
V_16 = F_8 ( V_2 , V_18 , V_6 -> V_28 -> V_20 ) ;
V_16 &= ~ 0x00ffffff ;
V_16 |= V_6 -> V_22 + V_155 ;
F_22 ( V_2 , V_18 , V_6 -> V_28 -> V_20 , V_16 ) ;
}
static int F_52 ( struct V_12 * V_7 ,
int V_159 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
struct V_62 * V_63 ;
int V_160 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_159 ) {
case V_161 :
F_43 ( V_2 , 1 , V_6 -> V_28 ) ;
F_43 ( V_2 , 0 , V_6 -> V_19 [ 0 ] ) ;
case V_162 :
case V_163 :
if ( V_159 == V_162 )
F_51 ( V_2 , V_6 , V_7 , V_14 ) ;
V_63 = & V_2 -> V_120 [ V_7 -> V_20 ] ;
F_44 ( V_2 , V_6 -> V_19 [ 0 ] , 1 , 0 , V_63 ) ;
F_44 ( V_2 , V_6 -> V_19 [ 1 ] , 0 , 0 , V_63 ) ;
F_44 ( V_2 , V_6 -> V_28 , 1 , 1 , NULL ) ;
F_46 ( V_2 , V_6 -> V_19 [ 0 ] , 1 , 0 ) ;
F_46 ( V_2 , V_6 -> V_19 [ 1 ] , 0 , 0 ) ;
F_46 ( V_2 , V_6 -> V_28 , 1 , 1 ) ;
V_6 -> V_17 = 1 ;
break;
case V_164 :
case V_165 :
case V_166 :
V_6 -> V_17 = 0 ;
F_49 ( V_2 , V_6 -> V_19 [ 0 ] ) ;
F_49 ( V_2 , V_6 -> V_19 [ 1 ] ) ;
F_49 ( V_2 , V_6 -> V_28 ) ;
break;
default:
V_160 = - V_167 ;
break;
}
F_54 ( & V_2 -> V_73 ) ;
return V_160 ;
}
static int F_55 ( struct V_12 * V_7 ,
int V_159 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
int V_160 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_159 ) {
case V_161 :
case V_163 :
F_56 ( V_6 -> V_168 , V_2 -> V_169 + V_170 ) ;
F_57 ( V_2 , V_6 -> V_171 ) ;
switch ( V_6 -> type ) {
case V_125 :
F_22 ( V_2 , V_126 , 0 , V_6 -> V_136 ) ;
break;
case V_127 :
if ( V_2 -> V_78 ) {
F_22 ( V_2 , V_128 , 0 , V_6 -> V_136 ) ;
F_22 ( V_2 , V_129 , 0 , V_6 -> V_172 ) ;
F_58 ( V_2 -> V_173 -> V_174 ,
L_1 ,
V_6 -> V_136 ,
V_6 -> V_172 ) ;
} else
F_22 ( V_2 , V_130 , 0 , V_6 -> V_136 ) ;
break;
default:
break;
}
F_22 ( V_2 , V_6 -> V_124 , 0 , V_6 -> V_134 ) ;
V_6 -> V_17 = 1 ;
V_6 -> V_175 = 1 ;
break;
case V_164 :
case V_166 :
V_6 -> V_17 = 0 ;
F_59 ( V_2 , V_6 -> V_171 ) ;
F_56 ( V_6 -> V_168 , V_2 -> V_169 + V_170 ) ;
F_22 ( V_2 , V_6 -> V_124 , 0 , 0 ) ;
switch ( V_6 -> type ) {
case V_125 :
F_22 ( V_2 , V_126 , 0 , 0 ) ;
break;
case V_127 :
if ( V_2 -> V_78 ) {
F_22 ( V_2 , V_128 , 0 , 0 ) ;
F_22 ( V_2 , V_129 , 0 , 0 ) ;
} else
F_22 ( V_2 , V_130 , 0 , 0 ) ;
break;
default:
break;
}
break;
default:
V_160 = - V_167 ;
}
F_54 ( & V_2 -> V_73 ) ;
return V_160 ;
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
int V_159 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
int V_24 ;
int V_160 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_159 ) {
case V_161 :
for ( V_24 = 0 ; V_24 < V_119 ; V_24 ++ ) {
F_43 ( V_2 , 0 , V_6 -> V_19 [ V_24 ] ) ;
}
F_43 ( V_2 , 1 , V_6 -> V_28 ) ;
case V_162 :
case V_163 :
F_44 ( V_2 , V_6 -> V_28 , 1 , 1 , NULL ) ;
F_44 ( V_2 , V_6 -> V_19 [ 0 ] , 0 , 0 ,
& V_2 -> V_122 [ 0 ] ) ;
for ( V_24 = 1 ; V_24 < V_119 ; V_24 ++ )
F_44 ( V_2 , V_6 -> V_19 [ V_24 ] , 0 , 0 ,
& V_2 -> V_122 [ V_24 ] ) ;
F_46 ( V_2 , V_6 -> V_19 [ 0 ] , 0 , 0 ) ;
F_46 ( V_2 , V_6 -> V_28 , 1 , 1 ) ;
for ( V_24 = 1 ; V_24 < V_119 ; V_24 ++ )
F_46 ( V_2 , V_6 -> V_19 [ V_24 ] , 0 , 0 ) ;
V_6 -> V_17 = 1 ;
break;
case V_166 :
case V_164 :
case V_165 :
V_6 -> V_17 = 0 ;
for ( V_24 = 0 ; V_24 < V_119 ; V_24 ++ ) {
F_49 ( V_2 , V_6 -> V_19 [ V_24 ] ) ;
}
F_49 ( V_2 , V_6 -> V_28 ) ;
break;
default:
V_160 = - V_167 ;
break;
}
F_54 ( & V_2 -> V_73 ) ;
return V_160 ;
}
static T_1 F_62 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 = V_14 -> V_15 ;
unsigned int V_16 ;
if ( ! V_6 -> V_17 )
return 0 ;
if ( V_6 -> V_175 ) {
F_63 ( 50 ) ;
V_6 -> V_175 = 0 ;
}
V_16 = F_8 ( V_2 , V_6 -> V_176 , 0 ) & 0x0000ffff ;
return F_64 ( V_14 , V_16 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_177 * V_178 , int V_123 , int V_179 )
{
struct V_180 V_181 ;
if ( ! V_178 )
return;
if ( V_179 )
V_178 -> V_182 [ V_123 ] . V_183 &= ~ V_184 ;
else
V_178 -> V_182 [ V_123 ] . V_183 |= V_184 ;
F_66 ( V_2 -> V_173 , V_185 |
V_186 ,
F_67 ( & V_181 , V_178 , V_123 ) ) ;
}
static void F_68 ( struct V_1 * V_2 , int V_123 , int V_179 )
{
F_65 ( V_2 , V_2 -> V_187 , V_123 , V_179 ) ;
F_65 ( V_2 , V_2 -> V_188 , V_123 , V_179 ) ;
F_65 ( V_2 , V_2 -> V_189 , V_123 , V_179 ) ;
}
static void F_69 ( struct V_1 * V_2 , int V_123 , int V_179 )
{
F_65 ( V_2 , V_2 -> V_190 , V_123 , V_179 ) ;
F_65 ( V_2 , V_2 -> V_191 , V_123 , V_179 ) ;
F_65 ( V_2 , V_2 -> V_192 , V_123 , V_179 ) ;
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
for ( V_24 = 0 ; V_24 < V_119 ; V_24 ++ ) {
V_63 = & V_2 -> V_122 [ V_24 ] ;
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
V_6 = F_74 ( sizeof( * V_6 ) , V_193 ) ;
if ( V_6 == NULL )
return - V_115 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_152 ;
V_6 -> V_7 = V_7 ;
V_2 -> V_194 = V_7 ;
V_14 -> V_15 = V_6 ;
V_14 -> V_195 = F_70 ;
V_14 -> V_196 = V_197 ;
for ( V_24 = 0 ; V_24 < V_119 ; V_24 ++ ) {
V_63 = & V_2 -> V_122 [ V_24 ] ;
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
int V_24 , V_23 , V_198 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_193 ) ;
if ( V_6 == NULL )
return - V_115 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_25 ;
V_6 -> V_7 = V_7 ;
V_14 -> V_15 = V_6 ;
V_14 -> V_195 = F_70 ;
V_14 -> V_196 = V_199 ;
if ( ( V_23 = F_76 ( V_14 , V_200 ) ) < 0 ) {
F_71 ( V_6 ) ;
return V_23 ;
}
if ( ( V_23 = F_77 ( V_14 , V_201 , 256 , V_202 ) ) < 0 ) {
F_71 ( V_6 ) ;
return V_23 ;
}
if ( V_2 -> V_86 -> V_87 && V_2 -> V_203 . V_204 == 0 )
V_198 = 44100 ;
else
V_198 = 48000 ;
V_23 = F_78 ( V_14 , V_198 ) ;
if ( V_23 < 0 ) {
F_71 ( V_6 ) ;
return V_23 ;
}
V_63 = & V_2 -> V_120 [ V_7 -> V_20 ] ;
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
struct V_62 * V_63 = & V_2 -> V_120 [ V_7 -> V_20 ] ;
V_63 -> V_6 = NULL ;
F_68 ( V_2 , V_7 -> V_20 , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_5 * V_6 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_193 ) ;
if ( V_6 == NULL )
return - V_115 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_125 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_168 = V_205 | V_206 ;
V_6 -> V_171 = V_207 ;
V_6 -> V_131 = V_208 ;
V_6 -> V_124 = V_209 ;
V_6 -> V_176 = V_2 -> V_78 ? V_210 : V_211 ;
V_14 -> V_15 = V_6 ;
V_14 -> V_195 = F_70 ;
V_14 -> V_196 = V_212 ;
V_2 -> V_213 = F_3 ;
V_2 -> V_9 = V_7 ;
F_81 ( V_14 , 0 , V_214 , & V_215 ) ;
F_81 ( V_14 , 0 , V_216 , & V_217 ) ;
return 0 ;
}
static int F_82 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
V_2 -> V_213 = NULL ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static int F_83 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_5 * V_6 ;
struct V_13 * V_14 = V_7 -> V_14 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_193 ) ;
if ( V_6 == NULL )
return - V_115 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_218 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_168 = V_219 | V_220 ;
V_6 -> V_171 = V_221 ;
V_6 -> V_131 = V_222 ;
V_6 -> V_124 = V_223 ;
V_6 -> V_176 = V_2 -> V_78 ? V_224 : V_225 ;
V_7 -> V_14 -> V_15 = V_6 ;
V_7 -> V_14 -> V_195 = F_70 ;
V_14 -> V_196 = V_212 ;
V_14 -> V_196 . V_226 = V_227 ;
V_14 -> V_196 . V_228 = V_14 -> V_196 . V_229 = 8000 ;
V_14 -> V_196 . V_230 = 1 ;
V_2 -> V_231 = F_4 ;
V_2 -> V_10 = V_7 ;
F_81 ( V_14 , 0 , V_214 , & V_215 ) ;
return 0 ;
}
static int F_84 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
V_2 -> V_213 = NULL ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static int F_85 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_5 * V_6 ;
struct V_13 * V_14 = V_7 -> V_14 ;
int V_232 = V_2 -> V_78 ? 64 : 32 ;
int V_123 ;
V_6 = F_74 ( sizeof( * V_6 ) , V_193 ) ;
if ( V_6 == NULL )
return - V_115 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = V_127 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_168 = V_233 | V_234 ;
V_6 -> V_171 = V_235 ;
V_6 -> V_131 = V_236 ;
V_6 -> V_124 = V_237 ;
V_6 -> V_176 = V_238 ;
V_7 -> V_14 -> V_15 = V_6 ;
V_7 -> V_14 -> V_195 = F_70 ;
V_14 -> V_196 = V_239 ;
V_14 -> V_196 . V_226 = V_240 ;
V_14 -> V_196 . V_228 = V_14 -> V_196 . V_229 = 48000 ;
F_86 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_86 -> V_87 ) {
#if 1
switch ( V_2 -> V_203 . V_204 ) {
case 0 :
V_14 -> V_196 . V_226 = V_241 ;
V_14 -> V_196 . V_228 = V_14 -> V_196 . V_229 = 44100 ;
V_14 -> V_196 . V_230 =
V_14 -> V_196 . V_242 = 16 ;
break;
case 1 :
V_14 -> V_196 . V_226 = V_240 ;
V_14 -> V_196 . V_228 = V_14 -> V_196 . V_229 = 48000 ;
V_14 -> V_196 . V_230 =
V_14 -> V_196 . V_242 = 16 ;
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
V_14 -> V_196 . V_243 = V_244 ;
} else {
V_14 -> V_196 . V_230 = V_14 -> V_196 . V_242 = 0 ;
for ( V_123 = 0 ; V_123 < V_232 ; V_123 ++ ) {
if ( V_2 -> V_245 [ V_123 / 32 ] & ( 1 << ( V_123 % 32 ) ) ) {
V_14 -> V_196 . V_230 ++ ;
V_14 -> V_196 . V_242 ++ ;
}
}
}
V_6 -> V_136 = V_2 -> V_245 [ 0 ] ;
V_6 -> V_172 = V_2 -> V_245 [ 1 ] ;
F_87 ( & V_2 -> V_73 ) ;
V_2 -> V_246 = F_5 ;
V_2 -> V_11 = V_7 ;
F_81 ( V_14 , 0 , V_214 , & V_215 ) ;
return 0 ;
}
static int F_88 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
V_2 -> V_213 = NULL ;
V_2 -> V_11 = NULL ;
return 0 ;
}
int V_5 ( struct V_1 * V_2 , int V_247 )
{
struct V_248 * V_249 ;
struct V_12 * V_7 ;
int V_23 ;
if ( ( V_23 = F_89 ( V_2 -> V_173 , L_2 , V_247 , 32 , 1 , & V_249 ) ) < 0 )
return V_23 ;
V_249 -> V_15 = V_2 ;
F_90 ( V_249 , V_250 , & V_251 ) ;
F_90 ( V_249 , V_252 , & V_253 ) ;
V_249 -> V_254 = 0 ;
V_249 -> V_255 = V_256 ;
strcpy ( V_249 -> V_257 , L_3 ) ;
V_2 -> V_249 = V_249 ;
for ( V_7 = V_249 -> V_258 [ V_250 ] . V_7 ; V_7 ; V_7 = V_7 -> V_259 )
if ( ( V_23 = F_91 ( V_7 , V_260 , F_92 ( V_2 -> V_261 ) , 64 * 1024 , 64 * 1024 ) ) < 0 )
return V_23 ;
for ( V_7 = V_249 -> V_258 [ V_252 ] . V_7 ; V_7 ; V_7 = V_7 -> V_259 )
F_91 ( V_7 , V_262 , F_92 ( V_2 -> V_261 ) , 64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , int V_247 )
{
struct V_248 * V_249 ;
struct V_12 * V_7 ;
int V_23 ;
if ( ( V_23 = F_89 ( V_2 -> V_173 , L_2 , V_247 , 1 , 0 , & V_249 ) ) < 0 )
return V_23 ;
V_249 -> V_15 = V_2 ;
F_90 ( V_249 , V_250 , & V_263 ) ;
V_249 -> V_254 = 0 ;
V_249 -> V_255 = V_256 ;
strcpy ( V_249 -> V_257 , L_4 ) ;
V_2 -> V_264 = V_249 ;
for ( V_7 = V_249 -> V_258 [ V_250 ] . V_7 ; V_7 ; V_7 = V_7 -> V_259 )
if ( ( V_23 = F_91 ( V_7 , V_260 , F_92 ( V_2 -> V_261 ) , 64 * 1024 , 64 * 1024 ) ) < 0 )
return V_23 ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , int V_247 )
{
struct V_248 * V_249 ;
int V_23 ;
if ( ( V_23 = F_89 ( V_2 -> V_173 , L_5 , V_247 , 0 , 1 , & V_249 ) ) < 0 )
return V_23 ;
V_249 -> V_15 = V_2 ;
F_90 ( V_249 , V_252 , & V_265 ) ;
V_249 -> V_254 = 0 ;
strcpy ( V_249 -> V_257 , L_6 ) ;
V_2 -> V_266 = V_249 ;
F_95 ( V_249 , V_262 , F_92 ( V_2 -> V_261 ) , 64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static int F_96 ( struct V_177 * V_267 , struct V_268 * V_269 )
{
struct V_1 * V_2 = F_97 ( V_267 ) ;
int V_232 = V_2 -> V_78 ? 64 : 32 ;
V_269 -> type = V_270 ;
V_269 -> V_271 = V_232 ;
V_269 -> V_272 . integer . V_273 = 0 ;
V_269 -> V_272 . integer . V_274 = 1 ;
return 0 ;
}
static int F_98 ( struct V_177 * V_267 , struct V_275 * V_276 )
{
struct V_1 * V_2 = F_97 ( V_267 ) ;
int V_232 = V_2 -> V_78 ? 64 : 32 ;
int V_123 ;
F_86 ( & V_2 -> V_73 ) ;
for ( V_123 = 0 ; V_123 < V_232 ; V_123 ++ )
V_276 -> V_272 . integer . V_272 [ V_123 ] = ( V_2 -> V_245 [ V_123 / 32 ] & ( 1 << ( V_123 % 32 ) ) ) ? 1 : 0 ;
F_87 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_99 ( struct V_177 * V_267 , struct V_275 * V_276 )
{
struct V_1 * V_2 = F_97 ( V_267 ) ;
unsigned int V_277 [ 2 ] , V_278 ;
int V_232 = V_2 -> V_78 ? 64 : 32 ;
int V_279 = V_2 -> V_78 ? 7 : 6 ;
int V_280 , V_123 ;
V_277 [ 0 ] = V_277 [ 1 ] = 0 ;
for ( V_123 = 0 , V_278 = 0 ; V_123 < V_232 ; V_123 ++ )
if ( V_276 -> V_272 . integer . V_272 [ V_123 ] ) {
V_277 [ V_123 / 32 ] |= 1 << ( V_123 % 32 ) ;
V_278 ++ ;
}
for ( V_123 = 0 ; V_123 < V_279 ; V_123 ++ )
if ( 1 << V_123 == V_278 )
break;
if ( V_123 >= V_279 )
return - V_167 ;
F_86 ( & V_2 -> V_73 ) ;
V_280 = ( V_277 [ 0 ] != V_2 -> V_245 [ 0 ] ) ||
( V_277 [ 1 ] != V_2 -> V_245 [ 1 ] ) ;
V_2 -> V_245 [ 0 ] = V_277 [ 0 ] ;
V_2 -> V_245 [ 1 ] = V_277 [ 1 ] ;
F_87 ( & V_2 -> V_73 ) ;
return V_280 ;
}
static void F_100 ( struct V_1 * V_2 , void * V_15 )
{
struct V_12 * V_7 = V_15 ;
F_2 ( V_7 ) ;
}
static void F_101 ( unsigned short * V_281 ,
unsigned short * V_282 ,
unsigned short * V_283 ,
unsigned int V_271 ,
unsigned int V_284 )
{
if ( ( V_284 & 1 ) == 0 ) {
while ( V_271 -- ) {
* V_281 -- = * V_283 ++ ;
* V_282 -- = * V_283 ++ ;
}
} else {
while ( V_271 -- ) {
* V_282 -- = * V_283 ++ ;
* V_281 -- = * V_283 ++ ;
}
}
}
static void F_102 ( struct V_12 * V_7 ,
struct V_285 * V_286 , T_2 V_287 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
unsigned int V_290 = V_249 -> V_21 ;
unsigned short * V_283 = ( unsigned short * ) ( V_7 -> V_14 -> V_291 + V_286 -> V_292 ) ;
unsigned int V_293 = V_287 >> 2 , V_271 ;
unsigned int V_294 = V_249 -> V_294 ;
unsigned int V_284 = V_249 -> V_284 ;
while ( V_293 > V_294 ) {
V_271 = V_294 + 1 ;
F_101 ( ( unsigned short * ) V_2 -> V_289 . V_295 . V_296 + V_294 ,
( unsigned short * ) V_2 -> V_289 . V_295 . V_296 + V_294 + V_290 / 2 ,
V_283 , V_271 , V_284 ) ;
V_283 += V_271 * 2 ;
V_293 -= V_271 ;
V_294 = ( V_290 / 2 ) - 1 ;
V_284 ++ ;
}
F_101 ( ( unsigned short * ) V_2 -> V_289 . V_295 . V_296 + V_294 ,
( unsigned short * ) V_2 -> V_289 . V_295 . V_296 + V_294 + V_290 / 2 ,
V_283 , V_293 , V_284 ) ;
V_294 -= V_293 ;
V_249 -> V_294 = V_294 ;
V_249 -> V_284 = V_284 ;
}
static int F_103 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
F_104 ( V_7 , & V_249 -> V_297 , F_102 ) ;
return 0 ;
}
static int F_105 ( struct V_12 * V_7 ,
struct V_111 * V_112 )
{
return F_29 ( V_7 , F_30 ( V_112 ) ) ;
}
static int F_106 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_249 -> V_71 ; V_24 ++ )
F_22 ( V_2 , V_298 + 0x80 + V_249 -> V_299 [ V_24 ] , 0 , 0 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static int F_107 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
unsigned int V_24 ;
memset ( & V_249 -> V_297 , 0 , sizeof( V_249 -> V_297 ) ) ;
V_249 -> V_297 . V_300 = V_249 -> V_21 * 2 ;
V_249 -> V_297 . V_301 = F_38 ( V_7 ) ;
V_249 -> V_294 = F_108 ( V_249 -> V_21 ) ;
V_249 -> V_284 = 0 ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_303 , 0 , 0 ) ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_304 , 0 , 0 ) ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_305 , 0 , V_14 -> V_21 ) ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_306 , 0 , 0 ) ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_307 , 0 , V_14 -> V_158 ) ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_308 , 0 , V_14 -> V_158 ) ;
for ( V_24 = 0 ; V_24 < V_249 -> V_71 ; V_24 ++ )
F_22 ( V_2 , V_298 + 0x80 + V_249 -> V_299 [ V_24 ] , 0 , ( V_309 | V_310 ) + V_24 * ( V_14 -> V_21 / V_249 -> V_71 ) ) ;
return 0 ;
}
static int F_109 ( struct V_12 * V_7 , int V_159 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
int V_160 = 0 ;
F_53 ( & V_2 -> V_73 ) ;
switch ( V_159 ) {
case V_161 :
case V_162 :
case V_163 :
#ifdef F_110
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 3 ; V_24 ++ ) {
unsigned int V_278 ;
V_278 = V_311 | V_312 |
V_313 | V_314 | V_315 |
0x00001200 | V_316 | V_317 | V_318 ;
F_22 ( V_2 , V_319 + V_24 , 0 , V_278 ) ;
}
}
#endif
V_160 = F_111 ( V_2 , F_100 , V_249 -> V_303 , V_7 , & V_249 -> V_320 ) ;
if ( V_160 < 0 )
goto V_321;
F_103 ( V_7 ) ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_304 , 0 , 1 ) ;
break;
case V_164 :
case V_165 :
case V_166 :
F_112 ( V_2 , V_249 -> V_320 ) ; V_249 -> V_320 = NULL ;
F_22 ( V_2 , V_2 -> V_302 + V_249 -> V_304 , 0 , 0 ) ;
V_249 -> V_294 = F_108 ( V_249 -> V_21 ) ;
V_249 -> V_284 = 0 ;
break;
default:
V_160 = - V_167 ;
break;
}
V_321:
F_54 ( & V_2 -> V_73 ) ;
return V_160 ;
}
static T_1 F_113 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
T_2 V_16 ;
if ( ! F_8 ( V_2 , V_2 -> V_302 + V_249 -> V_304 , 0 ) )
return 0 ;
V_16 = F_8 ( V_2 , V_2 -> V_302 + V_249 -> V_306 , 0 ) << 2 ;
return F_114 ( V_7 , & V_249 -> V_297 , V_16 ) ;
}
static int F_115 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
V_14 -> V_196 = V_322 ;
V_14 -> V_196 . V_230 = V_14 -> V_196 . V_242 = V_249 -> V_71 ;
V_14 -> V_196 . V_323 = ( V_249 -> V_21 * 2 ) / 2 ;
F_86 ( & V_2 -> V_73 ) ;
if ( V_249 -> V_324 == 0 ) {
F_87 ( & V_2 -> V_73 ) ;
return - V_325 ;
}
V_249 -> V_326 = 1 ;
F_87 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_116 ( struct V_12 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_288 * V_249 = & V_2 -> V_289 . V_249 [ V_7 -> V_20 ] ;
F_86 ( & V_2 -> V_73 ) ;
V_249 -> V_326 = 0 ;
F_87 ( & V_2 -> V_73 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , int V_247 )
{
struct V_248 * V_249 ;
struct V_177 * V_178 ;
int V_23 ;
if ( ( V_23 = F_89 ( V_2 -> V_173 , L_7 , V_247 , 8 , 1 , & V_249 ) ) < 0 )
return V_23 ;
V_249 -> V_15 = V_2 ;
F_90 ( V_249 , V_250 , & V_327 ) ;
F_90 ( V_249 , V_252 , & V_328 ) ;
V_249 -> V_254 = 0 ;
strcpy ( V_249 -> V_257 , L_8 ) ;
V_2 -> V_329 = V_249 ;
if ( V_2 -> V_78 ) {
V_2 -> V_245 [ 0 ] = 0 ;
if ( V_2 -> V_86 -> V_87 )
V_2 -> V_245 [ 1 ] = 0xffffffff ;
else
V_2 -> V_245 [ 1 ] = 0xffff ;
} else {
V_2 -> V_245 [ 0 ] = 0xffff0000 ;
V_2 -> V_245 [ 1 ] = 0 ;
}
V_178 = F_118 ( & V_330 , V_2 ) ;
if ( ! V_178 )
return - V_115 ;
V_178 -> V_181 . V_247 = V_247 ;
F_119 ( V_2 -> V_173 , V_178 ) ;
F_95 ( V_249 , V_262 , F_92 ( V_2 -> V_261 ) , 64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
