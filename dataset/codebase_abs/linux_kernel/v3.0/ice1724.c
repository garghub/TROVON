static inline int F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( F_3 ( V_2 , V_3 ) ) & V_4 ) ? 1 : 0 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return ( ! V_2 -> V_5 ( V_2 ) ) && V_6 ;
}
static unsigned char F_5 ( struct V_1 * V_2 )
{
unsigned char V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 0x10000 ; V_8 ++ ) {
V_7 = F_2 ( F_3 ( V_2 , V_9 ) ) ;
if ( V_7 & ( V_10 | V_11 ) )
continue;
if ( ! ( V_7 & V_12 ) )
continue;
return V_7 ;
}
F_6 ( V_13 L_1 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char V_14 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 0x10000 ; V_8 ++ )
if ( ( F_2 ( F_3 ( V_2 , V_9 ) ) & V_14 ) == 0 )
return 0 ;
F_6 ( V_13 L_2 ) ;
return - V_15 ;
}
static void F_8 ( struct V_16 * V_17 ,
unsigned short V_18 ,
unsigned short V_19 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
unsigned char V_7 ;
V_7 = F_5 ( V_2 ) ;
V_7 &= ~ V_21 ;
V_7 |= V_17 -> V_22 ;
F_9 ( V_18 , F_3 ( V_2 , V_23 ) ) ;
F_10 ( V_19 , F_3 ( V_2 , V_24 ) ) ;
F_9 ( V_7 | V_10 , F_3 ( V_2 , V_9 ) ) ;
F_7 ( V_2 , V_10 ) ;
}
static unsigned short F_11 ( struct V_16 * V_17 , unsigned short V_18 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
unsigned char V_7 ;
V_7 = F_5 ( V_2 ) ;
V_7 &= ~ V_21 ;
V_7 |= V_17 -> V_22 ;
F_9 ( V_18 , F_3 ( V_2 , V_23 ) ) ;
F_9 ( V_7 | V_11 , F_3 ( V_2 , V_9 ) ) ;
if ( F_7 ( V_2 , V_11 ) < 0 )
return ~ 0 ;
return F_12 ( F_3 ( V_2 , V_24 ) ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_25 )
{
F_14 ( V_25 , F_15 ( V_2 , V_26 ) ) ;
F_12 ( F_15 ( V_2 , V_26 ) ) ;
}
static unsigned int F_16 ( struct V_1 * V_2 )
{
return F_17 ( F_15 ( V_2 , V_26 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_25 )
{
F_10 ( V_25 , F_15 ( V_2 , V_27 ) ) ;
if ( ! V_2 -> V_28 )
F_9 ( ( V_25 >> 16 ) & 0xff , F_15 ( V_2 , V_29 ) ) ;
F_12 ( F_15 ( V_2 , V_27 ) ) ;
}
static unsigned int F_19 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
if ( ! V_2 -> V_28 )
V_30 = ( unsigned int ) F_2 ( F_15 ( V_2 , V_29 ) ) ;
else
V_30 = 0 ;
V_30 = ( V_30 << 16 ) | F_12 ( F_15 ( V_2 , V_27 ) ) ;
return V_30 ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_25 )
{
F_10 ( V_25 , F_15 ( V_2 , V_31 ) ) ;
if ( ! V_2 -> V_28 )
F_9 ( V_25 >> 16 , F_15 ( V_2 , V_32 ) ) ;
F_12 ( F_15 ( V_2 , V_31 ) ) ;
}
static unsigned int F_21 ( struct V_1 * V_2 )
{
unsigned int V_25 ;
if ( ! V_2 -> V_28 )
V_25 = ( unsigned int ) F_2 ( F_15 ( V_2 , V_32 ) ) ;
else
V_25 = 0 ;
V_25 = ( V_25 << 16 ) | F_12 ( F_15 ( V_2 , V_31 ) ) ;
return V_25 ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned int V_33 ;
for ( V_33 = F_2 ( F_15 ( V_2 , V_34 ) ) ; V_33 > 0 ; -- V_33 )
F_2 ( F_15 ( V_2 , V_35 ) ) ;
}
static inline struct V_36 *
F_23 ( struct V_1 * V_2 , unsigned int V_37 )
{
return F_24 ( & V_2 -> V_38 [ 0 ] -> V_39 [ V_37 ] . V_40 ,
struct V_36 , V_41 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_36 * V_42 ;
int V_33 , V_43 ;
T_1 V_44 [ 32 ] ;
V_42 = F_23 ( V_2 , V_45 ) ;
V_33 = 31 - F_2 ( F_15 ( V_2 , V_46 ) ) ;
if ( V_33 > 0 ) {
V_33 = F_26 ( V_42 , V_44 , V_33 ) ;
for ( V_43 = 0 ; V_43 < V_33 ; ++ V_43 )
F_9 ( V_44 [ V_43 ] , F_15 ( V_2 , V_35 ) ) ;
}
F_27 ( V_2 , V_47 ,
! F_28 ( V_42 ) ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_36 * V_42 ;
int V_33 , V_43 ;
T_1 V_44 [ 32 ] ;
V_42 = F_23 ( V_2 , V_48 ) ;
V_33 = F_2 ( F_15 ( V_2 , V_34 ) ) ;
if ( V_33 > 0 ) {
V_33 = F_30 ( V_33 , 32 ) ;
for ( V_43 = 0 ; V_43 < V_33 ; ++ V_43 )
V_44 [ V_43 ] = F_2 ( F_15 ( V_2 , V_35 ) ) ;
F_31 ( V_42 , V_44 , V_33 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , T_1 V_49 , int V_50 )
{
T_1 V_30 = F_2 ( F_15 ( V_2 , V_51 ) ) ;
if ( V_50 )
V_30 &= ~ V_49 ;
else
V_30 |= V_49 ;
F_9 ( V_30 , F_15 ( V_2 , V_51 ) ) ;
}
static void F_32 ( struct V_36 * V_52 ,
T_1 V_49 , int V_50 )
{
struct V_1 * V_2 = V_52 -> V_38 -> V_20 ;
F_33 ( & V_2 -> V_53 ) ;
F_27 ( V_2 , V_49 , V_50 ) ;
F_34 ( & V_2 -> V_53 ) ;
}
static int F_35 ( struct V_36 * V_42 )
{
return 0 ;
}
static int F_36 ( struct V_36 * V_42 )
{
return 0 ;
}
static void F_37 ( struct V_36 * V_42 , int V_54 )
{
struct V_1 * V_2 = V_42 -> V_38 -> V_20 ;
unsigned long V_55 ;
F_38 ( & V_2 -> V_53 , V_55 ) ;
if ( V_54 ) {
V_2 -> V_56 = 1 ;
F_25 ( V_2 ) ;
} else {
V_2 -> V_56 = 0 ;
F_27 ( V_2 , V_47 , 0 ) ;
}
F_39 ( & V_2 -> V_53 , V_55 ) ;
}
static void F_40 ( struct V_36 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_38 -> V_20 ;
unsigned long V_57 ;
F_32 ( V_42 , V_47 , 0 ) ;
V_57 = V_58 + F_41 ( 15 ) ;
do {
if ( F_2 ( F_15 ( V_2 , V_59 ) ) & V_60 )
break;
F_42 ( 1 ) ;
} while ( F_43 ( V_57 , V_58 ) );
}
static int F_44 ( struct V_36 * V_42 )
{
F_22 ( V_42 -> V_38 -> V_20 ) ;
F_32 ( V_42 , V_61 , 1 ) ;
return 0 ;
}
static int F_45 ( struct V_36 * V_42 )
{
F_32 ( V_42 , V_61 , 0 ) ;
return 0 ;
}
static void F_46 ( struct V_36 * V_42 , int V_54 )
{
struct V_1 * V_2 = V_42 -> V_38 -> V_20 ;
unsigned long V_55 ;
F_38 ( & V_2 -> V_53 , V_55 ) ;
if ( V_54 ) {
V_2 -> V_62 = 1 ;
F_29 ( V_2 ) ;
} else {
V_2 -> V_62 = 0 ;
}
F_39 ( & V_2 -> V_53 , V_55 ) ;
}
static T_2 F_47 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
unsigned char V_65 ;
unsigned char V_66 =
V_61 | V_47 | V_67 ;
int V_68 = 0 ;
int V_57 = 0 ;
while ( 1 ) {
V_65 = F_2 ( F_15 ( V_2 , V_69 ) ) ;
V_65 &= V_66 ;
if ( V_65 == 0 )
break;
F_48 ( & V_2 -> V_53 ) ;
if ( ++ V_57 > 10 ) {
V_65 = F_2 ( F_15 ( V_2 , V_69 ) ) ;
F_49 ( V_13 L_3
L_4 , V_65 ) ;
if ( V_65 & V_47 ) {
F_49 ( V_13 L_5 ) ;
F_27 ( V_2 , V_47 , 0 ) ;
}
F_50 ( & V_2 -> V_53 ) ;
break;
}
V_68 = 1 ;
if ( V_65 & V_47 ) {
if ( V_2 -> V_56 )
F_25 ( V_2 ) ;
else
F_27 ( V_2 , V_47 , 0 ) ;
V_66 &= ~ V_47 ;
}
if ( V_65 & V_61 ) {
if ( V_2 -> V_62 )
F_29 ( V_2 ) ;
else
F_22 ( V_2 ) ;
}
F_9 ( V_65 , F_15 ( V_2 , V_69 ) ) ;
F_50 ( & V_2 -> V_53 ) ;
if ( V_65 & V_67 ) {
unsigned char V_70 = F_2 ( F_3 ( V_2 , V_71 ) ) ;
if ( V_70 & V_72 ) {
if ( V_2 -> V_73 )
F_51 ( V_2 -> V_73 ) ;
}
if ( V_70 & V_74 ) {
if ( V_2 -> V_75 )
F_51 ( V_2 -> V_75 ) ;
}
if ( V_70 & V_76 ) {
if ( V_2 -> V_77 [ 0 ] )
F_51 ( V_2 -> V_77 [ 0 ] ) ;
}
if ( V_70 & V_78 ) {
if ( V_2 -> V_77 [ 1 ] )
F_51 ( V_2 -> V_77 [ 1 ] ) ;
}
if ( V_70 & V_79 ) {
if ( V_2 -> V_77 [ 2 ] )
F_51 ( V_2 -> V_77 [ 2 ] ) ;
}
if ( V_70 & V_80 ) {
if ( V_2 -> V_81 )
F_51 ( V_2 -> V_81 ) ;
}
if ( V_70 & V_82 ) {
if ( V_2 -> V_83 )
F_51 ( V_2 -> V_83 ) ;
}
F_9 ( V_70 , F_3 ( V_2 , V_71 ) ) ;
if ( V_70 & V_84 ) {
unsigned char V_85 = F_2 ( F_3 ( V_2 , V_86 ) ) ;
F_9 ( V_85 , F_3 ( V_2 , V_86 ) ) ;
F_9 ( V_84 | F_2 ( F_3 ( V_2 , V_87 ) ) , F_3 ( V_2 , V_87 ) ) ;
}
}
}
return F_52 ( V_68 ) ;
}
static int F_53 ( struct V_88 * V_52 , int V_89 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
unsigned char V_90 ;
unsigned char V_91 ;
struct V_88 * V_42 ;
V_90 = 0 ;
F_55 (s, substream) {
if ( F_54 ( V_42 ) == V_2 ) {
const struct V_92 * V_18 ;
V_18 = V_42 -> V_93 -> V_20 ;
V_90 |= V_18 -> V_94 ;
F_56 ( V_42 , V_52 ) ;
}
}
switch ( V_89 ) {
case V_95 :
case V_96 :
F_48 ( & V_2 -> V_53 ) ;
V_91 = F_2 ( F_3 ( V_2 , V_97 ) ) ;
if ( V_89 == V_95 )
V_91 |= V_90 ;
else
V_91 &= ~ V_90 ;
F_9 ( V_91 , F_3 ( V_2 , V_97 ) ) ;
F_50 ( & V_2 -> V_53 ) ;
break;
case V_98 :
case V_99 :
case V_100 :
F_48 ( & V_2 -> V_53 ) ;
V_91 = F_2 ( F_3 ( V_2 , V_101 ) ) ;
if ( V_89 == V_98 )
V_91 |= V_90 ;
else
V_91 &= ~ V_90 ;
F_9 ( V_91 , F_3 ( V_2 , V_101 ) ) ;
F_50 ( & V_2 -> V_53 ) ;
break;
case V_102 :
break;
default:
return - V_103 ;
}
return 0 ;
}
static unsigned int F_57 ( struct V_1 * V_2 )
{
unsigned int V_104 ;
V_104 = V_105 [ F_2 ( F_3 ( V_2 , V_3 ) ) & 15 ] ;
return V_104 ;
}
static void F_58 ( struct V_1 * V_2 , unsigned int V_104 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_59 ( V_105 ) ; V_43 ++ ) {
if ( V_105 [ V_43 ] == V_104 ) {
F_9 ( V_43 , F_3 ( V_2 , V_3 ) ) ;
return;
}
}
}
static unsigned char F_60 ( struct V_1 * V_2 ,
unsigned int V_104 )
{
unsigned char V_19 , V_91 ;
if ( V_2 -> V_106 . V_25 [ V_107 ] & V_108 ) {
V_19 = V_91 = F_2 ( F_3 ( V_2 , V_109 ) ) ;
if ( V_104 > 96000 )
V_19 |= V_110 ;
else
V_19 &= ~ V_110 ;
if ( V_19 != V_91 ) {
F_9 ( V_19 , F_3 ( V_2 , V_109 ) ) ;
return 1 ;
}
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned int V_104 ,
int V_111 )
{
unsigned long V_55 ;
unsigned char V_112 ;
unsigned int V_43 , V_113 ;
if ( V_104 > V_2 -> V_114 -> V_41 [ V_2 -> V_114 -> V_33 - 1 ] )
return - V_103 ;
F_38 ( & V_2 -> V_53 , V_55 ) ;
if ( ( F_2 ( F_3 ( V_2 , V_101 ) ) & V_115 ) ||
( F_2 ( F_3 ( V_2 , V_97 ) ) & V_116 ) ) {
F_39 ( & V_2 -> V_53 , V_55 ) ;
return ( ( V_104 == V_2 -> V_117 ) && ! V_111 ) ? 0 : - V_118 ;
}
if ( ! V_111 && F_4 ( V_2 ) ) {
F_39 ( & V_2 -> V_53 , V_55 ) ;
return ( V_104 == V_2 -> V_117 ) ? 0 : - V_118 ;
}
if ( V_111 || ! V_2 -> V_5 ( V_2 ) ) {
V_113 = V_2 -> V_119 ( V_2 ) ;
if ( V_111 || ( V_113 != V_104 ) )
V_2 -> V_120 ( V_2 , V_104 ) ;
else if ( V_104 == V_2 -> V_117 ) {
F_39 ( & V_2 -> V_53 , V_55 ) ;
return 0 ;
}
}
V_2 -> V_117 = V_104 ;
V_112 = V_2 -> V_121 ( V_2 , V_104 ) ;
F_39 ( & V_2 -> V_53 , V_55 ) ;
if ( V_112 && V_2 -> V_122 . V_123 )
V_2 -> V_122 . V_123 ( V_2 ) ;
if ( V_2 -> V_122 . V_124 )
V_2 -> V_122 . V_124 ( V_2 , V_104 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_125 ; V_43 ++ ) {
if ( V_2 -> V_126 [ V_43 ] . V_127 . V_128 )
V_2 -> V_126 [ V_43 ] . V_127 . V_128 ( & V_2 -> V_126 [ V_43 ] , V_104 ) ;
}
if ( V_2 -> V_129 . V_127 . V_130 )
V_2 -> V_129 . V_127 . V_130 ( V_2 , V_104 ) ;
return 0 ;
}
static int F_62 ( struct V_88 * V_52 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
int V_43 , V_133 , V_134 ;
V_133 = F_63 ( V_132 ) ;
F_64 ( & V_2 -> V_135 ) ;
if ( V_52 == V_2 -> V_73 ) {
V_133 = V_133 / 2 - 1 ;
for ( V_43 = 0 ; V_43 < V_133 ; V_43 ++ ) {
if ( V_2 -> V_136 [ V_43 ] &&
V_2 -> V_136 [ V_43 ] != V_52 ) {
F_65 ( & V_2 -> V_135 ) ;
return - V_118 ;
}
V_2 -> V_136 [ V_43 ] = V_52 ;
}
for (; V_43 < 3 ; V_43 ++ ) {
if ( V_2 -> V_136 [ V_43 ] == V_52 )
V_2 -> V_136 [ V_43 ] = NULL ;
}
} else {
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
if ( V_2 -> V_77 [ V_43 ] == V_52 ) {
if ( V_2 -> V_136 [ V_43 ] &&
V_2 -> V_136 [ V_43 ] != V_52 ) {
F_65 ( & V_2 -> V_135 ) ;
return - V_118 ;
}
V_2 -> V_136 [ V_43 ] = V_52 ;
break;
}
}
}
F_65 ( & V_2 -> V_135 ) ;
V_134 = F_61 ( V_2 , F_66 ( V_132 ) , 0 ) ;
if ( V_134 < 0 )
return V_134 ;
return F_67 ( V_52 , F_68 ( V_132 ) ) ;
}
static int F_69 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
int V_43 ;
F_64 ( & V_2 -> V_135 ) ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ )
if ( V_2 -> V_136 [ V_43 ] == V_52 )
V_2 -> V_136 [ V_43 ] = NULL ;
F_65 ( & V_2 -> V_135 ) ;
return F_70 ( V_52 ) ;
}
static int F_71 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
unsigned char V_19 ;
unsigned int V_137 ;
F_33 ( & V_2 -> V_53 ) ;
V_19 = ( 8 - V_52 -> V_93 -> V_138 ) >> 1 ;
F_9 ( V_19 , F_3 ( V_2 , V_139 ) ) ;
F_14 ( V_52 -> V_93 -> V_140 , F_3 ( V_2 , V_141 ) ) ;
V_137 = ( F_72 ( V_52 ) >> 2 ) - 1 ;
F_10 ( V_137 , F_3 ( V_2 , V_142 ) ) ;
F_9 ( V_137 >> 16 , F_3 ( V_2 , V_142 ) + 2 ) ;
V_137 = ( F_73 ( V_52 ) >> 2 ) - 1 ;
F_10 ( V_137 , F_3 ( V_2 , V_143 ) ) ;
F_9 ( V_137 >> 16 , F_3 ( V_2 , V_143 ) + 2 ) ;
F_34 ( & V_2 -> V_53 ) ;
return 0 ;
}
static T_3 F_74 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
T_4 V_144 ;
if ( ! ( F_17 ( F_3 ( V_2 , V_101 ) ) & V_145 ) )
return 0 ;
#if 0
ptr = inl(ICEMT1724(ice, PLAYBACK_ADDR));
if (ptr < substream->runtime->dma_addr) {
snd_printd("ice1724: invalid negative ptr\n");
return 0;
}
ptr -= substream->runtime->dma_addr;
ptr = bytes_to_frames(substream->runtime, ptr);
if (ptr >= substream->runtime->buffer_size) {
snd_printd("ice1724: invalid ptr %d (size=%d)\n",
(int)ptr, (int)substream->runtime->period_size);
return 0;
}
#else
V_144 = F_17 ( F_3 ( V_2 , V_142 ) ) & 0xffffff ;
V_144 = ( V_144 + 1 ) << 2 ;
V_144 = F_75 ( V_52 -> V_93 , V_144 ) ;
if ( ! V_144 )
;
else if ( V_144 <= V_52 -> V_93 -> V_146 )
V_144 = V_52 -> V_93 -> V_146 - V_144 ;
else {
F_6 ( L_6 ,
( int ) V_144 , ( int ) V_52 -> V_93 -> V_146 ) ;
V_144 = 0 ;
}
#endif
return V_144 ;
}
static int F_76 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
const struct V_92 * V_18 = V_52 -> V_93 -> V_20 ;
F_33 ( & V_2 -> V_53 ) ;
F_14 ( V_52 -> V_93 -> V_140 , V_2 -> V_147 + V_18 -> V_148 ) ;
F_10 ( ( F_72 ( V_52 ) >> 2 ) - 1 ,
V_2 -> V_147 + V_18 -> V_137 ) ;
F_10 ( ( F_73 ( V_52 ) >> 2 ) - 1 ,
V_2 -> V_147 + V_18 -> V_33 ) ;
F_34 ( & V_2 -> V_53 ) ;
return 0 ;
}
static T_3 F_77 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
const struct V_92 * V_18 = V_52 -> V_93 -> V_20 ;
T_4 V_144 ;
if ( ! ( F_17 ( F_3 ( V_2 , V_101 ) ) & V_18 -> V_94 ) )
return 0 ;
#if 0
ptr = inl(ice->profi_port + reg->addr);
ptr -= substream->runtime->dma_addr;
return bytes_to_frames(substream->runtime, ptr);
#else
V_144 = F_12 ( V_2 -> V_147 + V_18 -> V_137 ) ;
V_144 = ( V_144 + 1 ) << 2 ;
V_144 = F_75 ( V_52 -> V_93 , V_144 ) ;
if ( ! V_144 )
;
else if ( V_144 <= V_52 -> V_93 -> V_146 )
V_144 = V_52 -> V_93 -> V_146 - V_144 ;
else {
F_6 ( L_6 ,
( int ) V_144 , ( int ) V_52 -> V_93 -> V_146 ) ;
V_144 = 0 ;
}
return V_144 ;
#endif
}
static void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_106 . V_25 [ V_107 ] & V_108 ) {
if ( ( V_2 -> V_106 . V_25 [ V_149 ] & 0x08 ) && ! V_2 -> V_28 )
V_2 -> V_114 = & V_150 ;
else
V_2 -> V_114 = & V_151 ;
} else {
V_2 -> V_114 = & V_152 ;
}
}
static int F_79 ( struct V_1 * V_2 ,
struct V_88 * V_52 )
{
struct V_153 * V_93 = V_52 -> V_93 ;
V_93 -> V_154 . V_155 = V_2 -> V_114 -> V_41 [ 0 ] ;
V_93 -> V_154 . V_156 = V_2 -> V_114 -> V_41 [ V_2 -> V_114 -> V_33 - 1 ] ;
V_93 -> V_154 . V_157 = V_158 ;
return F_80 ( V_93 , 0 ,
V_159 ,
V_2 -> V_114 ) ;
}
static int F_81 ( struct V_88 * V_52 )
{
struct V_153 * V_93 = V_52 -> V_93 ;
struct V_1 * V_2 = F_54 ( V_52 ) ;
int V_133 , V_160 ;
V_93 -> V_20 = ( void * ) & V_161 ;
V_2 -> V_73 = V_52 ;
V_93 -> V_154 = V_162 ;
F_82 ( V_52 ) ;
F_83 ( V_93 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_52 ) ;
F_64 ( & V_2 -> V_135 ) ;
V_160 = V_2 -> V_163 / 2 - 1 ;
for ( V_133 = 0 ; V_133 < V_160 ; V_133 ++ ) {
if ( V_2 -> V_136 [ V_133 ] )
break;
}
V_133 = ( V_133 + 1 ) * 2 ;
V_93 -> V_154 . V_164 = V_133 ;
if ( V_133 > 2 )
F_84 ( V_93 , 0 , V_165 , 2 ) ;
F_65 ( & V_2 -> V_135 ) ;
F_84 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_84 ( V_93 , 0 , V_168 ,
V_167 ) ;
if ( V_2 -> V_169 )
V_2 -> V_169 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_85 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
V_93 -> V_20 = ( void * ) & V_170 ;
V_2 -> V_75 = V_52 ;
V_93 -> V_154 = V_171 ;
F_82 ( V_52 ) ;
F_83 ( V_93 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_52 ) ;
F_84 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_84 ( V_93 , 0 , V_168 ,
V_167 ) ;
if ( V_2 -> V_169 )
V_2 -> V_169 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_86 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_73 = NULL ;
return 0 ;
}
static int F_87 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_75 = NULL ;
return 0 ;
}
static int T_5 F_88 ( struct V_1 * V_2 , int V_174 )
{
struct V_175 * V_176 ;
int V_134 ;
V_134 = F_89 ( V_2 -> V_177 , L_7 , V_174 , 1 , 1 , & V_176 ) ;
if ( V_134 < 0 )
return V_134 ;
F_90 ( V_176 , V_178 , & V_179 ) ;
F_90 ( V_176 , V_180 , & V_181 ) ;
V_176 -> V_20 = V_2 ;
V_176 -> V_182 = 0 ;
strcpy ( V_176 -> V_183 , L_7 ) ;
F_91 ( V_176 , V_184 ,
F_92 ( V_2 -> V_185 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_186 = V_176 ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 , unsigned int V_19 )
{
unsigned char V_187 , V_188 ;
V_187 = F_2 ( F_15 ( V_2 , V_189 ) ) ;
V_188 = V_187 & ~ V_190 ;
if ( V_187 != V_188 )
F_9 ( V_188 , F_15 ( V_2 , V_189 ) ) ;
F_10 ( V_19 , F_3 ( V_2 , V_191 ) ) ;
if ( V_187 != V_188 )
F_9 ( V_187 , F_15 ( V_2 , V_189 ) ) ;
F_10 ( V_19 , F_3 ( V_2 , V_191 ) ) ;
}
static void F_94 ( struct V_1 * V_2 , unsigned int V_104 )
{
unsigned int V_19 , V_192 ;
unsigned long V_55 ;
F_38 ( & V_2 -> V_53 , V_55 ) ;
V_192 = V_19 = F_12 ( F_3 ( V_2 , V_191 ) ) ;
V_192 &= ~ ( 7 << 12 ) ;
switch ( V_104 ) {
case 44100 : break;
case 48000 : V_192 |= 2 << 12 ; break;
case 32000 : V_192 |= 3 << 12 ; break;
case 88200 : V_192 |= 4 << 12 ; break;
case 96000 : V_192 |= 5 << 12 ; break;
case 192000 : V_192 |= 6 << 12 ; break;
case 176400 : V_192 |= 7 << 12 ; break;
}
if ( V_19 != V_192 )
F_93 ( V_2 , V_192 ) ;
F_39 ( & V_2 -> V_53 , V_55 ) ;
}
static int F_95 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( ! V_2 -> V_193 )
F_94 ( V_2 , V_52 -> V_93 -> V_104 ) ;
return F_76 ( V_52 ) ;
}
static int F_96 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
V_93 -> V_20 = ( void * ) & V_194 ;
V_2 -> V_81 = V_52 ;
if ( V_2 -> V_193 ) {
V_93 -> V_154 = V_171 ;
F_79 ( V_2 , V_52 ) ;
} else
V_93 -> V_154 = V_195 ;
F_82 ( V_52 ) ;
F_83 ( V_93 , 0 , 32 , 24 ) ;
F_84 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_84 ( V_93 , 0 , V_168 ,
V_167 ) ;
if ( V_2 -> V_129 . V_127 . V_196 )
V_2 -> V_129 . V_127 . V_196 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_97 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_81 = NULL ;
if ( V_2 -> V_129 . V_127 . V_197 )
V_2 -> V_129 . V_127 . V_197 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_98 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
V_93 -> V_20 = ( void * ) & V_198 ;
V_2 -> V_83 = V_52 ;
if ( V_2 -> V_199 ) {
V_93 -> V_154 = V_171 ;
F_79 ( V_2 , V_52 ) ;
} else
V_93 -> V_154 = V_195 ;
F_82 ( V_52 ) ;
F_83 ( V_93 , 0 , 32 , 24 ) ;
F_84 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_84 ( V_93 , 0 , V_168 ,
V_167 ) ;
if ( V_2 -> V_129 . V_127 . V_196 )
V_2 -> V_129 . V_127 . V_196 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_99 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_83 = NULL ;
if ( V_2 -> V_129 . V_127 . V_197 )
V_2 -> V_129 . V_127 . V_197 ( V_2 , V_52 ) ;
return 0 ;
}
static int T_5 F_100 ( struct V_1 * V_2 , int V_174 )
{
char * V_183 ;
struct V_175 * V_176 ;
int V_200 , V_201 ;
int V_134 ;
if ( V_2 -> V_193 ||
( V_2 -> V_106 . V_25 [ V_202 ] & V_203 ) ) {
V_200 = 1 ;
V_2 -> V_204 = 1 ;
} else
V_200 = 0 ;
if ( V_2 -> V_199 ||
( V_2 -> V_106 . V_25 [ V_202 ] & V_205 ) ) {
V_201 = 1 ;
V_2 -> V_204 = 1 ;
} else
V_201 = 0 ;
if ( ! V_200 && ! V_201 )
return 0 ;
if ( V_2 -> V_193 || V_2 -> V_199 )
V_183 = L_8 ;
else
V_183 = L_9 ;
V_134 = F_89 ( V_2 -> V_177 , V_183 , V_174 , V_200 , V_201 , & V_176 ) ;
if ( V_134 < 0 )
return V_134 ;
if ( V_200 )
F_90 ( V_176 , V_178 ,
& V_206 ) ;
if ( V_201 )
F_90 ( V_176 , V_180 ,
& V_207 ) ;
V_176 -> V_20 = V_2 ;
V_176 -> V_182 = 0 ;
strcpy ( V_176 -> V_183 , V_183 ) ;
F_91 ( V_176 , V_184 ,
F_92 ( V_2 -> V_185 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_176 = V_176 ;
return 0 ;
}
static int F_101 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
unsigned char V_19 ;
F_33 ( & V_2 -> V_53 ) ;
V_19 = 3 - V_52 -> V_208 ;
if ( F_2 ( F_3 ( V_2 , V_139 ) ) < V_19 )
F_9 ( V_19 , F_3 ( V_2 , V_139 ) ) ;
F_34 ( & V_2 -> V_53 ) ;
return F_76 ( V_52 ) ;
}
static int F_102 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
F_64 ( & V_2 -> V_135 ) ;
if ( V_2 -> V_136 [ V_52 -> V_208 ] ) {
F_65 ( & V_2 -> V_135 ) ;
return - V_118 ;
}
F_65 ( & V_2 -> V_135 ) ;
V_93 -> V_20 = ( void * ) & V_209 [ V_52 -> V_208 ] ;
V_2 -> V_77 [ V_52 -> V_208 ] = V_52 ;
V_93 -> V_154 = V_171 ;
F_82 ( V_52 ) ;
F_83 ( V_93 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_103 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_77 [ V_52 -> V_208 ] = NULL ;
V_2 -> V_136 [ V_52 -> V_208 ] = NULL ;
return 0 ;
}
static int T_5 F_104 ( struct V_1 * V_2 , int V_174 )
{
struct V_175 * V_176 ;
int V_200 ;
int V_134 ;
V_200 = V_2 -> V_163 / 2 - 1 ;
if ( V_200 <= 0 )
return 0 ;
V_134 = F_89 ( V_2 -> V_177 , L_10 , V_174 , V_200 , 0 , & V_176 ) ;
if ( V_134 < 0 )
return V_134 ;
F_90 ( V_176 , V_178 ,
& V_210 ) ;
V_176 -> V_20 = V_2 ;
V_176 -> V_182 = 0 ;
strcpy ( V_176 -> V_183 , L_11 ) ;
F_91 ( V_176 , V_184 ,
F_92 ( V_2 -> V_185 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_211 = V_176 ;
return 0 ;
}
static int T_5 F_105 ( struct V_1 * V_2 )
{
int V_134 ;
if ( ! ( V_2 -> V_106 . V_25 [ V_107 ] & V_108 ) ) {
struct V_212 * V_213 ;
struct V_214 V_17 ;
static struct V_215 V_127 = {
. V_216 = F_8 ,
. V_217 = F_11 ,
} ;
F_9 ( F_2 ( F_3 ( V_2 , V_9 ) ) | 0x80 , F_3 ( V_2 , V_9 ) ) ;
F_106 ( 5 ) ;
F_9 ( F_2 ( F_3 ( V_2 , V_9 ) ) & ~ 0x80 , F_3 ( V_2 , V_9 ) ) ;
V_134 = V_212 ( V_2 -> V_177 , 0 , & V_127 , NULL , & V_213 ) ;
if ( V_134 < 0 )
return V_134 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_20 = V_2 ;
V_134 = F_107 ( V_213 , & V_17 , & V_2 -> V_17 ) ;
if ( V_134 < 0 )
F_49 ( V_218 L_12 ) ;
else
return 0 ;
}
strcat ( V_2 -> V_177 -> V_219 , L_13 ) ;
return 0 ;
}
static inline unsigned int F_108 ( struct V_1 * V_2 , int V_220 )
{
return ( unsigned int ) V_2 -> V_106 . V_25 [ V_220 ] | \
( ( unsigned int ) V_2 -> V_106 . V_25 [ V_220 + 1 ] << 8 ) | \
( ( unsigned int ) V_2 -> V_106 . V_25 [ V_220 + 2 ] << 16 ) ;
}
static void F_109 ( struct V_221 * V_222 ,
struct V_223 * V_44 )
{
struct V_1 * V_2 = V_222 -> V_20 ;
unsigned int V_220 ;
F_110 ( V_44 , L_14 , V_2 -> V_177 -> V_224 ) ;
F_110 ( V_44 , L_15 ) ;
F_110 ( V_44 , L_16 , V_2 -> V_106 . V_225 ) ;
F_110 ( V_44 , L_17 , V_2 -> V_106 . V_137 ) ;
F_110 ( V_44 , L_18 , V_2 -> V_106 . V_226 ) ;
F_110 ( V_44 , L_19 ,
V_2 -> V_106 . V_25 [ V_227 ] ) ;
F_110 ( V_44 , L_20 ,
V_2 -> V_106 . V_25 [ V_107 ] ) ;
F_110 ( V_44 , L_21 ,
V_2 -> V_106 . V_25 [ V_149 ] ) ;
F_110 ( V_44 , L_22 ,
V_2 -> V_106 . V_25 [ V_202 ] ) ;
F_110 ( V_44 , L_23 ,
V_2 -> V_106 . V_228 ) ;
F_110 ( V_44 , L_24 ,
V_2 -> V_106 . V_229 ) ;
F_110 ( V_44 , L_25 ,
V_2 -> V_106 . V_230 ) ;
for ( V_220 = 0x12 ; V_220 < V_2 -> V_106 . V_137 ; V_220 ++ )
F_110 ( V_44 , L_26 ,
V_220 , V_2 -> V_106 . V_25 [ V_220 ] ) ;
F_110 ( V_44 , L_27 ) ;
F_110 ( V_44 , L_28 ,
( unsigned ) F_17 ( F_3 ( V_2 , V_231 ) ) ) ;
for ( V_220 = 0x0 ; V_220 < 0x20 ; V_220 ++ )
F_110 ( V_44 , L_29 ,
V_220 , F_2 ( V_2 -> V_232 + V_220 ) ) ;
for ( V_220 = 0x0 ; V_220 < 0x30 ; V_220 ++ )
F_110 ( V_44 , L_30 ,
V_220 , F_2 ( V_2 -> V_147 + V_220 ) ) ;
}
static void T_5 F_111 ( struct V_1 * V_2 )
{
struct V_221 * V_222 ;
if ( ! F_112 ( V_2 -> V_177 , L_31 , & V_222 ) )
F_113 ( V_222 , V_2 , F_109 ) ;
}
static int F_114 ( struct V_233 * V_234 ,
struct V_235 * V_236 )
{
V_236 -> type = V_237 ;
V_236 -> V_33 = sizeof( struct V_238 ) ;
return 0 ;
}
static int F_115 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
memcpy ( V_240 -> V_241 . V_242 . V_25 , & V_2 -> V_106 , sizeof( V_2 -> V_106 ) ) ;
return 0 ;
}
static int F_117 ( struct V_233 * V_234 ,
struct V_235 * V_236 )
{
V_236 -> type = V_243 ;
V_236 -> V_33 = 1 ;
return 0 ;
}
static unsigned int F_118 ( struct V_244 * V_245 )
{
unsigned int V_19 , V_246 ;
V_19 = V_245 -> V_65 [ 0 ] & 0x03 ;
if ( V_19 & 0x01 ) {
if ( ( V_245 -> V_65 [ 0 ] & V_247 ) ==
V_248 )
V_19 |= 1U << 3 ;
V_246 = ( V_245 -> V_65 [ 4 ] >> 3 ) & 0x0f ;
if ( V_246 ) {
switch ( V_246 ) {
case 2 : V_19 |= 5 << 12 ; break;
case 3 : V_19 |= 6 << 12 ; break;
case 10 : V_19 |= 4 << 12 ; break;
case 11 : V_19 |= 7 << 12 ; break;
}
} else {
switch ( V_245 -> V_65 [ 0 ] & V_249 ) {
case V_250 :
break;
case V_251 :
V_19 |= 3U << 12 ;
break;
default:
V_19 |= 2U << 12 ;
break;
}
}
} else {
V_19 |= V_245 -> V_65 [ 1 ] & 0x04 ;
if ( ( V_245 -> V_65 [ 0 ] & V_252 ) ==
V_253 )
V_19 |= 1U << 3 ;
V_19 |= ( unsigned int ) ( V_245 -> V_65 [ 1 ] & 0x3f ) << 4 ;
V_19 |= ( unsigned int ) ( V_245 -> V_65 [ 3 ] & V_254 ) << 12 ;
}
return V_19 ;
}
static void F_119 ( struct V_244 * V_245 , unsigned int V_19 )
{
memset ( V_245 -> V_65 , 0 , sizeof( V_245 -> V_65 ) ) ;
V_245 -> V_65 [ 0 ] = V_19 & 0x03 ;
if ( V_19 & 0x01 ) {
if ( V_19 & ( 1U << 3 ) )
V_245 -> V_65 [ 0 ] |= V_248 ;
switch ( ( V_19 >> 12 ) & 0x7 ) {
case 0 :
break;
case 2 :
V_245 -> V_65 [ 0 ] |= V_251 ;
break;
default:
V_245 -> V_65 [ 0 ] |= V_255 ;
break;
}
} else {
V_245 -> V_65 [ 0 ] |= V_19 & ( 1U << 2 ) ;
if ( V_19 & ( 1U << 3 ) )
V_245 -> V_65 [ 0 ] |= V_253 ;
V_245 -> V_65 [ 1 ] |= ( V_19 >> 4 ) & 0x3f ;
V_245 -> V_65 [ 3 ] |= ( V_19 >> 12 ) & 0x07 ;
}
}
static int F_120 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
unsigned int V_19 ;
V_19 = F_12 ( F_3 ( V_2 , V_191 ) ) ;
F_119 ( & V_240 -> V_241 . V_256 , V_19 ) ;
return 0 ;
}
static int F_121 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
unsigned int V_19 , V_91 ;
V_19 = F_118 ( & V_240 -> V_241 . V_256 ) ;
F_33 ( & V_2 -> V_53 ) ;
V_91 = F_12 ( F_3 ( V_2 , V_191 ) ) ;
if ( V_19 != V_91 )
F_93 ( V_2 , V_19 ) ;
F_34 ( & V_2 -> V_53 ) ;
return V_19 != V_91 ;
}
static int F_122 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
V_240 -> V_241 . V_256 . V_65 [ 0 ] = V_257 |
V_258 |
V_259 |
V_252 ;
V_240 -> V_241 . V_256 . V_65 [ 1 ] = V_260 |
V_261 ;
V_240 -> V_241 . V_256 . V_65 [ 3 ] = V_254 ;
return 0 ;
}
static int F_123 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
V_240 -> V_241 . V_256 . V_65 [ 0 ] = V_257 |
V_258 |
V_249 |
V_247 ;
return 0 ;
}
static int F_124 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
V_240 -> V_241 . integer . V_241 [ 0 ] = F_2 ( F_15 ( V_2 , V_189 ) ) &
V_190 ? 1 : 0 ;
return 0 ;
}
static int F_125 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
unsigned char V_91 , V_19 ;
F_33 ( & V_2 -> V_53 ) ;
V_91 = V_19 = F_2 ( F_15 ( V_2 , V_189 ) ) ;
V_19 &= ~ V_190 ;
if ( V_240 -> V_241 . integer . V_241 [ 0 ] )
V_19 |= V_190 ;
if ( V_91 != V_19 )
F_9 ( V_19 , F_15 ( V_2 , V_189 ) ) ;
F_34 ( & V_2 -> V_53 ) ;
return V_91 != V_19 ;
}
static int F_126 ( struct V_233 * V_234 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_262 = V_2 -> V_114 -> V_33 ;
V_236 -> type = V_263 ;
V_236 -> V_33 = 1 ;
V_236 -> V_241 . V_264 . V_265 = V_262 + V_2 -> V_266 ;
if ( V_236 -> V_241 . V_264 . V_267 >= V_236 -> V_241 . V_264 . V_265 )
V_236 -> V_241 . V_264 . V_267 = V_236 -> V_241 . V_264 . V_265 - 1 ;
if ( V_236 -> V_241 . V_264 . V_267 >= V_262 )
strcpy ( V_236 -> V_241 . V_264 . V_183 ,
V_2 -> V_268 [
V_236 -> V_241 . V_264 . V_267 - V_262 ] ) ;
else
sprintf ( V_236 -> V_241 . V_264 . V_183 , L_32 ,
V_2 -> V_114 -> V_41 [ V_236 -> V_241 . V_264 . V_267 ] ) ;
return 0 ;
}
static int F_127 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
unsigned int V_43 , V_104 ;
F_33 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_5 ( V_2 ) ) {
V_240 -> V_241 . V_264 . V_267 [ 0 ] = V_2 -> V_114 -> V_33 +
V_2 -> V_269 ( V_2 ) ;
} else {
V_104 = V_2 -> V_119 ( V_2 ) ;
V_240 -> V_241 . V_264 . V_267 [ 0 ] = 0 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_114 -> V_33 ; V_43 ++ ) {
if ( V_2 -> V_114 -> V_41 [ V_43 ] == V_104 ) {
V_240 -> V_241 . V_264 . V_267 [ 0 ] = V_43 ;
break;
}
}
}
F_34 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , int type )
{
unsigned char V_270 ;
unsigned char V_271 ;
V_270 = F_2 ( F_3 ( V_2 , V_3 ) ) ;
F_9 ( V_270 | V_4 , F_3 ( V_2 , V_3 ) ) ;
V_271 = F_2 ( F_3 ( V_2 , V_109 ) ) ;
F_9 ( V_271 & ~ V_110 , F_3 ( V_2 , V_109 ) ) ;
return 0 ;
}
static int F_130 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
unsigned int V_113 , V_272 ;
unsigned int V_267 = V_240 -> V_241 . V_264 . V_267 [ 0 ] ;
unsigned int V_273 = V_2 -> V_114 -> V_33 ;
if ( V_267 > V_273 + V_2 -> V_266 - 1 )
return - V_103 ;
F_33 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_5 ( V_2 ) )
V_113 = 0 ;
else
V_113 = V_2 -> V_119 ( V_2 ) ;
if ( V_267 >= V_273 ) {
V_2 -> V_274 ( V_2 , V_267 - V_273 ) ;
V_272 = 0 ;
} else {
V_272 = V_2 -> V_114 -> V_41 [ V_267 ] ;
V_2 -> V_173 = V_272 ;
F_34 ( & V_2 -> V_53 ) ;
F_61 ( V_2 , V_2 -> V_173 , 1 ) ;
F_33 ( & V_2 -> V_53 ) ;
}
F_34 ( & V_2 -> V_53 ) ;
if ( V_113 != V_272 && ! V_272 ) {
unsigned int V_43 ;
if ( V_2 -> V_122 . V_124 )
V_2 -> V_122 . V_124 ( V_2 , 0 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_125 ; V_43 ++ ) {
if ( V_2 -> V_126 [ V_43 ] . V_127 . V_128 )
V_2 -> V_126 [ V_43 ] . V_127 . V_128 ( & V_2 -> V_126 [ V_43 ] , 0 ) ;
}
}
return V_113 != V_272 ;
}
static int F_131 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
V_240 -> V_241 . integer . V_241 [ 0 ] = V_6 ;
return 0 ;
}
static int F_132 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_275 = 0 , V_192 ;
V_192 = V_240 -> V_241 . integer . V_241 [ 0 ] ? 1 : 0 ;
F_33 ( & V_2 -> V_53 ) ;
V_275 = V_6 != V_192 ;
V_6 = V_192 ;
F_34 ( & V_2 -> V_53 ) ;
return V_275 ;
}
static int F_133 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
V_240 -> V_241 . integer . V_241 [ 0 ] = V_172 ? 1 : 0 ;
return 0 ;
}
static int F_134 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_275 = 0 , V_192 ;
V_192 = V_240 -> V_241 . integer . V_241 [ 0 ] ? 1 : 0 ;
F_33 ( & V_2 -> V_53 ) ;
V_275 = V_172 != V_192 ;
V_172 = V_192 ;
F_34 ( & V_2 -> V_53 ) ;
return V_275 ;
}
static int F_135 ( struct V_233 * V_234 ,
struct V_235 * V_236 )
{
static char * V_276 [] = {
L_33 ,
L_34 , L_35 ,
L_36 , L_37 ,
} ;
V_236 -> type = V_263 ;
V_236 -> V_33 = 1 ;
V_236 -> V_241 . V_264 . V_265 = 5 ;
if ( V_236 -> V_241 . V_264 . V_267 >= V_236 -> V_241 . V_264 . V_265 )
V_236 -> V_241 . V_264 . V_267 = V_236 -> V_241 . V_264 . V_265 - 1 ;
strcpy ( V_236 -> V_241 . V_264 . V_183 , V_276 [ V_236 -> V_241 . V_264 . V_267 ] ) ;
return 0 ;
}
static inline int F_136 ( int V_220 )
{
return ( V_220 % 2 ) * 12 + ( ( V_220 / 2 ) * 3 ) + 8 ;
}
static inline int F_137 ( int V_220 )
{
return V_220 * 3 ;
}
int F_138 ( struct V_1 * V_2 , int V_277 )
{
unsigned long V_19 ;
unsigned char V_278 ;
static const unsigned char V_279 [ 8 ] = {
0 , 255 , 1 , 2 , 255 , 255 , 3 , 4 ,
} ;
V_19 = F_17 ( F_3 ( V_2 , V_231 ) ) ;
V_19 >>= V_277 ;
V_19 &= 7 ;
V_278 = V_279 [ V_19 ] ;
if ( V_278 == 255 ) {
F_139 () ;
return 0 ;
}
return V_278 ;
}
int F_140 ( struct V_1 * V_2 , unsigned int V_19 ,
int V_277 )
{
unsigned int V_280 , V_192 ;
int V_275 ;
static const unsigned char V_281 [ 8 ] = {
0 ,
2 ,
3 ,
6 ,
7 ,
} ;
V_192 = V_281 [ V_19 % 5 ] ;
V_19 = V_280 = F_17 ( F_3 ( V_2 , V_231 ) ) ;
V_19 &= ~ ( 0x07 << V_277 ) ;
V_19 |= V_192 << V_277 ;
V_275 = V_19 != V_280 ;
if ( V_275 )
F_14 ( V_19 , F_3 ( V_2 , V_231 ) ) ;
return V_275 ;
}
static int F_141 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_220 = F_142 ( V_234 , & V_240 -> V_282 ) ;
V_240 -> V_241 . V_264 . V_267 [ 0 ] =
F_138 ( V_2 , F_136 ( V_220 ) ) ;
return 0 ;
}
static int F_143 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_220 = F_142 ( V_234 , & V_240 -> V_282 ) ;
return F_140 ( V_2 ,
V_240 -> V_241 . V_264 . V_267 [ 0 ] ,
F_136 ( V_220 ) ) ;
}
static int F_144 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_220 = F_142 ( V_234 , & V_240 -> V_282 ) ;
V_240 -> V_241 . V_264 . V_267 [ 0 ] =
F_138 ( V_2 , F_137 ( V_220 ) ) ;
return 0 ;
}
static int F_145 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_220 = F_142 ( V_234 , & V_240 -> V_282 ) ;
return F_140 ( V_2 ,
V_240 -> V_241 . V_264 . V_267 [ 0 ] ,
F_137 ( V_220 ) ) ;
}
static int F_146 ( struct V_233 * V_234 ,
struct V_235 * V_236 )
{
V_236 -> type = V_283 ;
V_236 -> V_33 = 22 ;
V_236 -> V_241 . integer . F_30 = 0 ;
V_236 -> V_241 . integer . V_284 = 255 ;
return 0 ;
}
static int F_147 ( struct V_233 * V_234 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = F_116 ( V_234 ) ;
int V_220 ;
F_33 ( & V_2 -> V_53 ) ;
for ( V_220 = 0 ; V_220 < 22 ; V_220 ++ ) {
F_9 ( V_220 , F_3 ( V_2 , V_285 ) ) ;
V_240 -> V_241 . integer . V_241 [ V_220 ] =
F_2 ( F_3 ( V_2 , V_286 ) ) ;
}
F_34 ( & V_2 -> V_53 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 )
{
int V_287 = 0x10000 ;
while ( ( F_2 ( F_15 ( V_2 , V_288 ) ) & V_289 ) && V_287 -- )
;
if ( V_287 == - 1 )
F_49 ( V_13 L_38 ) ;
}
unsigned char F_149 ( struct V_1 * V_2 ,
unsigned char V_290 , unsigned char V_148 )
{
unsigned char V_19 ;
F_64 ( & V_2 -> V_291 ) ;
F_148 ( V_2 ) ;
F_9 ( V_148 , F_15 ( V_2 , V_292 ) ) ;
F_9 ( V_290 & ~ V_293 , F_15 ( V_2 , V_294 ) ) ;
F_148 ( V_2 ) ;
V_19 = F_2 ( F_15 ( V_2 , V_295 ) ) ;
F_65 ( & V_2 -> V_291 ) ;
return V_19 ;
}
void F_150 ( struct V_1 * V_2 ,
unsigned char V_290 , unsigned char V_148 , unsigned char V_25 )
{
F_64 ( & V_2 -> V_291 ) ;
F_148 ( V_2 ) ;
F_9 ( V_148 , F_15 ( V_2 , V_292 ) ) ;
F_9 ( V_25 , F_15 ( V_2 , V_295 ) ) ;
F_9 ( V_290 | V_293 , F_15 ( V_2 , V_294 ) ) ;
F_148 ( V_2 ) ;
F_65 ( & V_2 -> V_291 ) ;
}
static int T_5 F_151 ( struct V_1 * V_2 ,
const char * V_296 )
{
const int V_290 = 0xa0 ;
unsigned int V_43 , V_137 ;
struct V_297 * const * V_298 , * V_299 ;
if ( ! V_296 || ! * V_296 ) {
V_2 -> V_106 . V_225 = 0 ;
if ( ( F_2 ( F_15 ( V_2 , V_288 ) ) & V_300 ) != 0 )
V_2 -> V_106 . V_225 =
( F_149 ( V_2 , V_290 , 0x00 ) << 0 ) |
( F_149 ( V_2 , V_290 , 0x01 ) << 8 ) |
( F_149 ( V_2 , V_290 , 0x02 ) << 16 ) |
( F_149 ( V_2 , V_290 , 0x03 ) << 24 ) ;
if ( V_2 -> V_106 . V_225 == 0 ||
V_2 -> V_106 . V_225 == ( unsigned int ) - 1 ) {
T_6 V_301 , V_174 ;
F_152 ( V_2 -> V_185 , V_302 ,
& V_301 ) ;
F_152 ( V_2 -> V_185 , V_303 , & V_174 ) ;
V_2 -> V_106 . V_225 =
( ( unsigned int ) F_153 ( V_301 ) << 16 ) | F_153 ( V_174 ) ;
if ( V_2 -> V_106 . V_225 == 0 ||
V_2 -> V_106 . V_225 == ( unsigned int ) - 1 ) {
F_49 ( V_13 L_39 ) ;
return - V_304 ;
}
}
}
for ( V_298 = V_305 ; * V_298 ; V_298 ++ ) {
for ( V_299 = * V_298 ; V_299 -> V_225 ; V_299 ++ ) {
if ( V_296 && V_299 -> V_306 &&
! strcmp ( V_296 , V_299 -> V_306 ) ) {
F_49 ( V_307 L_40 ,
V_299 -> V_183 ) ;
V_2 -> V_106 . V_225 = V_299 -> V_225 ;
} else if ( V_299 -> V_225 != V_2 -> V_106 . V_225 )
continue;
if ( ! V_299 -> V_308 || ! V_299 -> V_309 )
goto V_310;
F_154 ( L_41 ) ;
V_2 -> V_106 . V_226 = 2 ;
V_2 -> V_106 . V_137 = V_299 -> V_308 + 6 ;
memcpy ( V_2 -> V_106 . V_25 , V_299 -> V_309 , V_299 -> V_308 ) ;
goto V_311;
}
}
F_49 ( V_218 L_42 ,
V_2 -> V_106 . V_225 ) ;
V_310:
V_2 -> V_106 . V_137 = F_149 ( V_2 , V_290 , 0x04 ) ;
if ( V_2 -> V_106 . V_137 < 6 )
V_2 -> V_106 . V_137 = 32 ;
else if ( V_2 -> V_106 . V_137 > 32 ) {
F_49 ( V_13 L_43 ,
V_2 -> V_106 . V_137 ) ;
return - V_15 ;
}
V_2 -> V_106 . V_226 = F_149 ( V_2 , V_290 , 0x05 ) ;
if ( V_2 -> V_106 . V_226 != 2 )
F_49 ( V_218 L_44 ,
V_2 -> V_106 . V_226 ) ;
V_137 = V_2 -> V_106 . V_137 - 6 ;
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ )
V_2 -> V_106 . V_25 [ V_43 ] = F_149 ( V_2 , V_290 , V_43 + 6 ) ;
V_311:
V_2 -> V_106 . V_229 = F_108 ( V_2 , V_312 ) ;
V_2 -> V_106 . V_230 = F_108 ( V_2 , V_313 ) ;
V_2 -> V_106 . V_228 = F_108 ( V_2 , V_314 ) ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 )
{
F_9 ( V_315 , F_15 ( V_2 , V_316 ) ) ;
F_2 ( F_15 ( V_2 , V_316 ) ) ;
F_156 ( 10 ) ;
F_9 ( 0 , F_15 ( V_2 , V_316 ) ) ;
F_2 ( F_15 ( V_2 , V_316 ) ) ;
F_156 ( 10 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_106 . V_25 [ V_227 ] , F_15 ( V_2 , V_317 ) ) ;
F_9 ( V_2 -> V_106 . V_25 [ V_107 ] , F_15 ( V_2 , V_318 ) ) ;
F_9 ( V_2 -> V_106 . V_25 [ V_149 ] , F_15 ( V_2 , V_319 ) ) ;
F_9 ( V_2 -> V_106 . V_25 [ V_202 ] , F_15 ( V_2 , V_189 ) ) ;
V_2 -> V_122 . V_320 = V_2 -> V_106 . V_229 ;
V_2 -> V_122 . V_321 = V_2 -> V_106 . V_228 ;
F_18 ( V_2 , V_2 -> V_106 . V_229 ) ;
F_13 ( V_2 , V_2 -> V_106 . V_228 ) ;
F_20 ( V_2 , V_2 -> V_106 . V_230 ) ;
F_9 ( 0 , F_15 ( V_2 , V_322 ) ) ;
F_9 ( V_61 | V_47 , F_15 ( V_2 , V_51 ) ) ;
F_9 ( V_84 , F_3 ( V_2 , V_87 ) ) ;
return 0 ;
}
static int T_5 F_158 ( struct V_1 * V_2 )
{
int V_134 ;
struct V_233 * V_323 ;
if ( F_159 ( ! V_2 -> V_176 ) )
return - V_15 ;
if ( ! V_2 -> V_324 ) {
V_134 = F_160 ( V_2 -> V_177 ,
F_161 ( & V_325 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
}
V_134 = F_160 ( V_2 -> V_177 , F_161 ( & V_326 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_160 ( V_2 -> V_177 , V_323 = F_161 ( & V_327 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_323 -> V_282 . V_174 = V_2 -> V_176 -> V_174 ;
V_134 = F_160 ( V_2 -> V_177 , V_323 = F_161 ( & V_328 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_323 -> V_282 . V_174 = V_2 -> V_176 -> V_174 ;
V_134 = F_160 ( V_2 -> V_177 , V_323 = F_161 ( & V_329 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_323 -> V_282 . V_174 = V_2 -> V_176 -> V_174 ;
#if 0
err = snd_ctl_add(ice->card, kctl = snd_ctl_new1(&snd_vt1724_spdif_stream, ice));
if (err < 0)
return err;
kctl->id.device = ice->pcm->device;
ice->spdif.stream_ctl = kctl;
#endif
return 0 ;
}
static int T_5 F_162 ( struct V_1 * V_2 )
{
int V_134 ;
V_134 = F_160 ( V_2 -> V_177 , F_161 ( & V_330 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_160 ( V_2 -> V_177 , F_161 ( & V_331 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_160 ( V_2 -> V_177 , F_161 ( & V_332 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_160 ( V_2 -> V_177 , F_161 ( & V_333 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
if ( ! V_2 -> V_324 && V_2 -> V_163 > 0 ) {
struct V_334 V_335 = V_336 ;
V_335 . V_33 = V_2 -> V_163 ;
if ( V_2 -> V_28 && V_335 . V_33 > 2 )
V_335 . V_33 = 2 ;
V_134 = F_160 ( V_2 -> V_177 , F_161 ( & V_335 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
}
V_134 = F_160 ( V_2 -> V_177 , F_161 ( & V_337 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_232 )
goto V_338;
F_9 ( 0xff , F_3 ( V_2 , V_87 ) ) ;
F_9 ( 0xff , F_15 ( V_2 , V_51 ) ) ;
V_338:
if ( V_2 -> V_63 >= 0 )
F_164 ( V_2 -> V_63 , V_2 ) ;
F_165 ( V_2 -> V_185 ) ;
F_166 ( V_2 ) ;
F_167 ( V_2 -> V_185 ) ;
F_168 ( V_2 -> V_339 ) ;
F_168 ( V_2 ) ;
return 0 ;
}
static int F_169 ( struct V_340 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_341 ;
return F_163 ( V_2 ) ;
}
static int T_5 F_170 ( struct V_342 * V_177 ,
struct V_343 * V_185 ,
const char * V_296 ,
struct V_1 * * V_344 )
{
struct V_1 * V_2 ;
int V_134 ;
static struct V_345 V_127 = {
. V_346 = F_169 ,
} ;
* V_344 = NULL ;
V_134 = F_171 ( V_185 ) ;
if ( V_134 < 0 )
return V_134 ;
V_2 = F_172 ( sizeof( * V_2 ) , V_347 ) ;
if ( V_2 == NULL ) {
F_167 ( V_185 ) ;
return - V_348 ;
}
V_2 -> V_349 = 1 ;
F_173 ( & V_2 -> V_53 ) ;
F_174 ( & V_2 -> V_350 ) ;
F_174 ( & V_2 -> V_135 ) ;
F_174 ( & V_2 -> V_291 ) ;
V_2 -> V_122 . V_351 = F_18 ;
V_2 -> V_122 . V_352 = F_19 ;
V_2 -> V_122 . V_353 = F_13 ;
V_2 -> V_122 . V_354 = F_16 ;
V_2 -> V_122 . V_355 = F_20 ;
V_2 -> V_122 . V_356 = F_21 ;
V_2 -> V_177 = V_177 ;
V_2 -> V_185 = V_185 ;
V_2 -> V_63 = - 1 ;
F_175 ( V_185 ) ;
F_111 ( V_2 ) ;
F_176 ( V_185 -> V_63 ) ;
V_177 -> V_20 = V_2 ;
V_134 = F_177 ( V_185 , L_7 ) ;
if ( V_134 < 0 ) {
F_168 ( V_2 ) ;
F_167 ( V_185 ) ;
return V_134 ;
}
V_2 -> V_232 = F_178 ( V_185 , 0 ) ;
V_2 -> V_147 = F_178 ( V_185 , 1 ) ;
if ( F_179 ( V_185 -> V_63 , F_47 ,
V_357 , L_7 , V_2 ) ) {
F_180 ( V_13 L_45 , V_185 -> V_63 ) ;
F_163 ( V_2 ) ;
return - V_15 ;
}
V_2 -> V_63 = V_185 -> V_63 ;
F_155 ( V_2 ) ;
if ( F_151 ( V_2 , V_296 ) < 0 ) {
F_163 ( V_2 ) ;
return - V_15 ;
}
if ( F_157 ( V_2 ) < 0 ) {
F_163 ( V_2 ) ;
return - V_15 ;
}
V_134 = F_181 ( V_177 , V_358 , V_2 , & V_127 ) ;
if ( V_134 < 0 ) {
F_163 ( V_2 ) ;
return V_134 ;
}
F_182 ( V_177 , & V_185 -> V_290 ) ;
* V_344 = V_2 ;
return 0 ;
}
static int T_5 F_183 ( struct V_343 * V_185 ,
const struct V_359 * V_360 )
{
static int V_290 ;
struct V_342 * V_177 ;
struct V_1 * V_2 ;
int V_361 = 0 , V_134 ;
struct V_297 * const * V_298 , * V_299 ;
if ( V_290 >= V_362 )
return - V_363 ;
if ( ! V_50 [ V_290 ] ) {
V_290 ++ ;
return - V_364 ;
}
V_134 = F_184 ( V_365 [ V_290 ] , V_282 [ V_290 ] , V_366 , 0 , & V_177 ) ;
if ( V_134 < 0 )
return V_134 ;
strcpy ( V_177 -> V_367 , L_7 ) ;
strcpy ( V_177 -> V_368 , L_46 ) ;
V_134 = F_170 ( V_177 , V_185 , V_306 [ V_290 ] , & V_2 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
V_2 -> V_266 = 0 ;
for ( V_298 = V_305 ; * V_298 ; V_298 ++ ) {
for ( V_299 = * V_298 ; V_299 -> V_225 ; V_299 ++ ) {
if ( V_299 -> V_225 == V_2 -> V_106 . V_225 ) {
strcpy ( V_177 -> V_368 , V_299 -> V_183 ) ;
if ( V_299 -> V_367 )
strcpy ( V_177 -> V_367 , V_299 -> V_367 ) ;
if ( V_299 -> V_369 ) {
V_134 = V_299 -> V_369 ( V_2 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
}
goto V_370;
}
}
}
V_299 = & V_371 ;
V_370:
V_2 -> V_173 = V_372 ;
if ( ! V_2 -> V_5 )
V_2 -> V_5 = F_1 ;
if ( ! V_2 -> V_119 )
V_2 -> V_119 = F_57 ;
if ( ! V_2 -> V_120 )
V_2 -> V_120 = F_58 ;
if ( ! V_2 -> V_121 )
V_2 -> V_121 = F_60 ;
if ( ! V_2 -> V_274 )
V_2 -> V_274 = F_129 ;
if ( ! V_2 -> V_269 )
V_2 -> V_269 = F_128 ;
if ( ! V_2 -> V_268 )
V_2 -> V_268 = V_268 ;
if ( ! V_2 -> V_266 )
V_2 -> V_266 = F_59 ( V_268 ) ;
if ( ! V_2 -> V_114 )
F_78 ( V_2 ) ;
V_134 = F_88 ( V_2 , V_361 ++ ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
V_134 = F_100 ( V_2 , V_361 ++ ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
V_134 = F_104 ( V_2 , V_361 ++ ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
V_134 = F_105 ( V_2 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
V_134 = F_162 ( V_2 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
if ( V_2 -> V_176 && V_2 -> V_204 ) {
V_134 = F_158 ( V_2 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
}
if ( V_299 -> V_373 ) {
V_134 = V_299 -> V_373 ( V_2 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
}
if ( ! V_299 -> V_374 ) {
if ( V_2 -> V_106 . V_25 [ V_227 ] & V_375 ) {
struct V_376 * V_38 ;
V_134 = F_186 ( V_177 , L_47 , 0 , 1 , 1 , & V_38 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
V_2 -> V_38 [ 0 ] = V_38 ;
V_38 -> V_20 = V_2 ;
strcpy ( V_38 -> V_183 , L_48 ) ;
V_38 -> V_182 = V_377 |
V_378 |
V_379 ;
F_187 ( V_38 , V_45 ,
& V_380 ) ;
F_187 ( V_38 , V_48 ,
& V_381 ) ;
F_9 ( V_382 | 0x1 ,
F_15 ( V_2 , V_383 ) ) ;
F_9 ( 0x1 , F_15 ( V_2 , V_383 ) ) ;
F_9 ( V_384 , F_15 ( V_2 , V_59 ) ) ;
}
}
sprintf ( V_177 -> V_224 , L_49 ,
V_177 -> V_368 , V_2 -> V_232 , V_2 -> V_63 ) ;
V_134 = F_188 ( V_177 ) ;
if ( V_134 < 0 ) {
F_185 ( V_177 ) ;
return V_134 ;
}
F_189 ( V_185 , V_177 ) ;
V_290 ++ ;
return 0 ;
}
static void T_7 F_190 ( struct V_343 * V_185 )
{
F_185 ( F_191 ( V_185 ) ) ;
F_189 ( V_185 , NULL ) ;
}
static int F_192 ( struct V_343 * V_185 , T_8 V_385 )
{
struct V_342 * V_177 = F_191 ( V_185 ) ;
struct V_1 * V_2 = V_177 -> V_20 ;
if ( ! V_2 -> V_386 )
return 0 ;
F_193 ( V_177 , V_387 ) ;
F_194 ( V_2 -> V_176 ) ;
F_194 ( V_2 -> V_186 ) ;
F_194 ( V_2 -> V_211 ) ;
F_195 ( V_2 -> V_17 ) ;
F_33 ( & V_2 -> V_53 ) ;
V_2 -> V_388 = V_2 -> V_5 ( V_2 ) ;
V_2 -> V_389 = F_12 ( F_3 ( V_2 , V_191 ) ) ;
V_2 -> V_390 = F_2 ( F_15 ( V_2 , V_189 ) ) ;
V_2 -> V_391 = F_17 ( F_3 ( V_2 , V_231 ) ) ;
F_34 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_392 )
V_2 -> V_392 ( V_2 ) ;
F_167 ( V_185 ) ;
F_196 ( V_185 ) ;
F_197 ( V_185 , F_198 ( V_185 , V_385 ) ) ;
return 0 ;
}
static int F_199 ( struct V_343 * V_185 )
{
struct V_342 * V_177 = F_191 ( V_185 ) ;
struct V_1 * V_2 = V_177 -> V_20 ;
if ( ! V_2 -> V_386 )
return 0 ;
F_197 ( V_185 , V_393 ) ;
F_200 ( V_185 ) ;
if ( F_171 ( V_185 ) < 0 ) {
F_201 ( V_177 ) ;
return - V_15 ;
}
F_175 ( V_185 ) ;
F_155 ( V_2 ) ;
if ( F_157 ( V_2 ) < 0 ) {
F_201 ( V_177 ) ;
return - V_15 ;
}
if ( V_2 -> V_394 )
V_2 -> V_394 ( V_2 ) ;
if ( V_2 -> V_388 ) {
V_2 -> V_274 ( V_2 , 0 ) ;
} else {
F_61 ( V_2 , V_2 -> V_173 , 1 ) ;
}
F_93 ( V_2 , V_2 -> V_389 ) ;
F_9 ( V_2 -> V_390 , F_15 ( V_2 , V_189 ) ) ;
F_14 ( V_2 -> V_391 , F_3 ( V_2 , V_231 ) ) ;
if ( V_2 -> V_17 )
F_202 ( V_2 -> V_17 ) ;
F_193 ( V_177 , V_395 ) ;
return 0 ;
}
static int T_9 F_203 ( void )
{
return F_204 ( & V_367 ) ;
}
static void T_10 F_205 ( void )
{
F_206 ( & V_367 ) ;
}
