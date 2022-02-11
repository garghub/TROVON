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
static void F_81 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
unsigned int V_104 ;
if ( F_4 ( V_2 ) ) {
V_104 = V_2 -> V_119 ( V_2 ) ;
if ( V_104 >= V_93 -> V_154 . V_155
&& V_104 <= V_93 -> V_154 . V_156 ) {
V_93 -> V_154 . V_155 = V_104 ;
V_93 -> V_154 . V_156 = V_104 ;
}
}
}
static int F_82 ( struct V_88 * V_52 )
{
struct V_153 * V_93 = V_52 -> V_93 ;
struct V_1 * V_2 = F_54 ( V_52 ) ;
int V_133 , V_160 ;
V_93 -> V_20 = ( void * ) & V_161 ;
V_2 -> V_73 = V_52 ;
V_93 -> V_154 = V_162 ;
F_83 ( V_52 ) ;
F_84 ( V_93 , 0 , 32 , 24 ) ;
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
F_85 ( V_93 , 0 , V_165 , 2 ) ;
F_65 ( & V_2 -> V_135 ) ;
F_85 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_85 ( V_93 , 0 , V_168 ,
V_167 ) ;
F_81 ( V_52 ) ;
if ( V_2 -> V_169 )
V_2 -> V_169 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_86 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
V_93 -> V_20 = ( void * ) & V_170 ;
V_2 -> V_75 = V_52 ;
V_93 -> V_154 = V_171 ;
F_83 ( V_52 ) ;
F_84 ( V_93 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_52 ) ;
F_85 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_85 ( V_93 , 0 , V_168 ,
V_167 ) ;
F_81 ( V_52 ) ;
if ( V_2 -> V_169 )
V_2 -> V_169 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_87 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_73 = NULL ;
return 0 ;
}
static int F_88 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_75 = NULL ;
return 0 ;
}
static int T_5 F_89 ( struct V_1 * V_2 , int V_174 )
{
struct V_175 * V_176 ;
int V_177 , V_134 ;
if ( ( V_2 -> V_106 . V_25 [ V_178 ] & V_179 ) ==
V_180 )
V_177 = 0 ;
else
V_177 = 1 ;
V_134 = F_90 ( V_2 -> V_181 , L_7 , V_174 , 1 , V_177 , & V_176 ) ;
if ( V_134 < 0 )
return V_134 ;
F_91 ( V_176 , V_182 , & V_183 ) ;
if ( V_177 )
F_91 ( V_176 , V_184 ,
& V_185 ) ;
V_176 -> V_20 = V_2 ;
V_176 -> V_186 = 0 ;
strcpy ( V_176 -> V_187 , L_7 ) ;
F_92 ( V_176 , V_188 ,
F_93 ( V_2 -> V_189 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_190 = V_176 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , unsigned int V_19 )
{
unsigned char V_191 , V_192 ;
V_191 = F_2 ( F_15 ( V_2 , V_193 ) ) ;
V_192 = V_191 & ~ V_194 ;
if ( V_191 != V_192 )
F_9 ( V_192 , F_15 ( V_2 , V_193 ) ) ;
F_10 ( V_19 , F_3 ( V_2 , V_195 ) ) ;
if ( V_191 != V_192 )
F_9 ( V_191 , F_15 ( V_2 , V_193 ) ) ;
F_10 ( V_19 , F_3 ( V_2 , V_195 ) ) ;
}
static void F_95 ( struct V_1 * V_2 , unsigned int V_104 )
{
unsigned int V_19 , V_196 ;
unsigned long V_55 ;
F_38 ( & V_2 -> V_53 , V_55 ) ;
V_196 = V_19 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
V_196 &= ~ ( 7 << 12 ) ;
switch ( V_104 ) {
case 44100 : break;
case 48000 : V_196 |= 2 << 12 ; break;
case 32000 : V_196 |= 3 << 12 ; break;
case 88200 : V_196 |= 4 << 12 ; break;
case 96000 : V_196 |= 5 << 12 ; break;
case 192000 : V_196 |= 6 << 12 ; break;
case 176400 : V_196 |= 7 << 12 ; break;
}
if ( V_19 != V_196 )
F_94 ( V_2 , V_196 ) ;
F_39 ( & V_2 -> V_53 , V_55 ) ;
}
static int F_96 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( ! V_2 -> V_197 )
F_95 ( V_2 , V_52 -> V_93 -> V_104 ) ;
return F_76 ( V_52 ) ;
}
static int F_97 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
V_93 -> V_20 = ( void * ) & V_198 ;
V_2 -> V_81 = V_52 ;
if ( V_2 -> V_197 ) {
V_93 -> V_154 = V_171 ;
F_79 ( V_2 , V_52 ) ;
} else
V_93 -> V_154 = V_199 ;
F_83 ( V_52 ) ;
F_84 ( V_93 , 0 , 32 , 24 ) ;
F_85 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_85 ( V_93 , 0 , V_168 ,
V_167 ) ;
F_81 ( V_52 ) ;
if ( V_2 -> V_129 . V_127 . V_200 )
V_2 -> V_129 . V_127 . V_200 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_98 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_81 = NULL ;
if ( V_2 -> V_129 . V_127 . V_201 )
V_2 -> V_129 . V_127 . V_201 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_99 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
V_93 -> V_20 = ( void * ) & V_202 ;
V_2 -> V_83 = V_52 ;
if ( V_2 -> V_203 ) {
V_93 -> V_154 = V_171 ;
F_79 ( V_2 , V_52 ) ;
} else
V_93 -> V_154 = V_199 ;
F_83 ( V_52 ) ;
F_84 ( V_93 , 0 , 32 , 24 ) ;
F_85 ( V_93 , 0 , V_166 ,
V_167 ) ;
F_85 ( V_93 , 0 , V_168 ,
V_167 ) ;
F_81 ( V_52 ) ;
if ( V_2 -> V_129 . V_127 . V_200 )
V_2 -> V_129 . V_127 . V_200 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_100 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_83 = NULL ;
if ( V_2 -> V_129 . V_127 . V_201 )
V_2 -> V_129 . V_127 . V_201 ( V_2 , V_52 ) ;
return 0 ;
}
static int T_5 F_101 ( struct V_1 * V_2 , int V_174 )
{
char * V_187 ;
struct V_175 * V_176 ;
int V_204 , V_177 ;
int V_134 ;
if ( V_2 -> V_197 ||
( V_2 -> V_106 . V_25 [ V_205 ] & V_206 ) ) {
V_204 = 1 ;
V_2 -> V_207 = 1 ;
} else
V_204 = 0 ;
if ( V_2 -> V_203 ||
( V_2 -> V_106 . V_25 [ V_205 ] & V_208 ) ) {
V_177 = 1 ;
V_2 -> V_207 = 1 ;
} else
V_177 = 0 ;
if ( ! V_204 && ! V_177 )
return 0 ;
if ( V_2 -> V_197 || V_2 -> V_203 )
V_187 = L_8 ;
else
V_187 = L_9 ;
V_134 = F_90 ( V_2 -> V_181 , V_187 , V_174 , V_204 , V_177 , & V_176 ) ;
if ( V_134 < 0 )
return V_134 ;
if ( V_204 )
F_91 ( V_176 , V_182 ,
& V_209 ) ;
if ( V_177 )
F_91 ( V_176 , V_184 ,
& V_210 ) ;
V_176 -> V_20 = V_2 ;
V_176 -> V_186 = 0 ;
strcpy ( V_176 -> V_187 , V_187 ) ;
F_92 ( V_176 , V_188 ,
F_93 ( V_2 -> V_189 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_176 = V_176 ;
return 0 ;
}
static int F_102 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
unsigned char V_19 ;
F_33 ( & V_2 -> V_53 ) ;
V_19 = 3 - V_52 -> V_211 ;
if ( F_2 ( F_3 ( V_2 , V_139 ) ) < V_19 )
F_9 ( V_19 , F_3 ( V_2 , V_139 ) ) ;
F_34 ( & V_2 -> V_53 ) ;
return F_76 ( V_52 ) ;
}
static int F_103 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
struct V_153 * V_93 = V_52 -> V_93 ;
F_64 ( & V_2 -> V_135 ) ;
if ( V_2 -> V_136 [ V_52 -> V_211 ] ) {
F_65 ( & V_2 -> V_135 ) ;
return - V_118 ;
}
F_65 ( & V_2 -> V_135 ) ;
V_93 -> V_20 = ( void * ) & V_212 [ V_52 -> V_211 ] ;
V_2 -> V_77 [ V_52 -> V_211 ] = V_52 ;
V_93 -> V_154 = V_171 ;
F_83 ( V_52 ) ;
F_84 ( V_93 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_52 ) ;
return 0 ;
}
static int F_104 ( struct V_88 * V_52 )
{
struct V_1 * V_2 = F_54 ( V_52 ) ;
if ( V_172 )
F_61 ( V_2 , V_2 -> V_173 , 0 ) ;
V_2 -> V_77 [ V_52 -> V_211 ] = NULL ;
V_2 -> V_136 [ V_52 -> V_211 ] = NULL ;
return 0 ;
}
static int T_5 F_105 ( struct V_1 * V_2 , int V_174 )
{
struct V_175 * V_176 ;
int V_204 ;
int V_134 ;
V_204 = V_2 -> V_163 / 2 - 1 ;
if ( V_204 <= 0 )
return 0 ;
V_134 = F_90 ( V_2 -> V_181 , L_10 , V_174 , V_204 , 0 , & V_176 ) ;
if ( V_134 < 0 )
return V_134 ;
F_91 ( V_176 , V_182 ,
& V_213 ) ;
V_176 -> V_20 = V_2 ;
V_176 -> V_186 = 0 ;
strcpy ( V_176 -> V_187 , L_11 ) ;
F_92 ( V_176 , V_188 ,
F_93 ( V_2 -> V_189 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_214 = V_176 ;
return 0 ;
}
static int T_5 F_106 ( struct V_1 * V_2 )
{
int V_134 ;
if ( ! ( V_2 -> V_106 . V_25 [ V_107 ] & V_108 ) ) {
struct V_215 * V_216 ;
struct V_217 V_17 ;
static struct V_218 V_127 = {
. V_219 = F_8 ,
. V_220 = F_11 ,
} ;
F_9 ( F_2 ( F_3 ( V_2 , V_9 ) ) | 0x80 , F_3 ( V_2 , V_9 ) ) ;
F_107 ( 5 ) ;
F_9 ( F_2 ( F_3 ( V_2 , V_9 ) ) & ~ 0x80 , F_3 ( V_2 , V_9 ) ) ;
V_134 = V_215 ( V_2 -> V_181 , 0 , & V_127 , NULL , & V_216 ) ;
if ( V_134 < 0 )
return V_134 ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_20 = V_2 ;
V_134 = F_108 ( V_216 , & V_17 , & V_2 -> V_17 ) ;
if ( V_134 < 0 )
F_49 ( V_221 L_12 ) ;
else
return 0 ;
}
strcat ( V_2 -> V_181 -> V_222 , L_13 ) ;
return 0 ;
}
static inline unsigned int F_109 ( struct V_1 * V_2 , int V_223 )
{
return ( unsigned int ) V_2 -> V_106 . V_25 [ V_223 ] | \
( ( unsigned int ) V_2 -> V_106 . V_25 [ V_223 + 1 ] << 8 ) | \
( ( unsigned int ) V_2 -> V_106 . V_25 [ V_223 + 2 ] << 16 ) ;
}
static void F_110 ( struct V_224 * V_225 ,
struct V_226 * V_44 )
{
struct V_1 * V_2 = V_225 -> V_20 ;
unsigned int V_223 ;
F_111 ( V_44 , L_14 , V_2 -> V_181 -> V_227 ) ;
F_111 ( V_44 , L_15 ) ;
F_111 ( V_44 , L_16 , V_2 -> V_106 . V_228 ) ;
F_111 ( V_44 , L_17 , V_2 -> V_106 . V_137 ) ;
F_111 ( V_44 , L_18 , V_2 -> V_106 . V_229 ) ;
F_111 ( V_44 , L_19 ,
V_2 -> V_106 . V_25 [ V_178 ] ) ;
F_111 ( V_44 , L_20 ,
V_2 -> V_106 . V_25 [ V_107 ] ) ;
F_111 ( V_44 , L_21 ,
V_2 -> V_106 . V_25 [ V_149 ] ) ;
F_111 ( V_44 , L_22 ,
V_2 -> V_106 . V_25 [ V_205 ] ) ;
F_111 ( V_44 , L_23 ,
V_2 -> V_106 . V_230 ) ;
F_111 ( V_44 , L_24 ,
V_2 -> V_106 . V_231 ) ;
F_111 ( V_44 , L_25 ,
V_2 -> V_106 . V_232 ) ;
for ( V_223 = 0x12 ; V_223 < V_2 -> V_106 . V_137 ; V_223 ++ )
F_111 ( V_44 , L_26 ,
V_223 , V_2 -> V_106 . V_25 [ V_223 ] ) ;
F_111 ( V_44 , L_27 ) ;
F_111 ( V_44 , L_28 ,
( unsigned ) F_17 ( F_3 ( V_2 , V_233 ) ) ) ;
for ( V_223 = 0x0 ; V_223 < 0x20 ; V_223 ++ )
F_111 ( V_44 , L_29 ,
V_223 , F_2 ( V_2 -> V_234 + V_223 ) ) ;
for ( V_223 = 0x0 ; V_223 < 0x30 ; V_223 ++ )
F_111 ( V_44 , L_30 ,
V_223 , F_2 ( V_2 -> V_147 + V_223 ) ) ;
}
static void T_5 F_112 ( struct V_1 * V_2 )
{
struct V_224 * V_225 ;
if ( ! F_113 ( V_2 -> V_181 , L_31 , & V_225 ) )
F_114 ( V_225 , V_2 , F_110 ) ;
}
static int F_115 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
V_238 -> type = V_239 ;
V_238 -> V_33 = sizeof( struct V_240 ) ;
return 0 ;
}
static int F_116 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
memcpy ( V_242 -> V_243 . V_244 . V_25 , & V_2 -> V_106 , sizeof( V_2 -> V_106 ) ) ;
return 0 ;
}
static int F_118 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
V_238 -> type = V_245 ;
V_238 -> V_33 = 1 ;
return 0 ;
}
static unsigned int F_119 ( struct V_246 * V_247 )
{
unsigned int V_19 , V_248 ;
V_19 = V_247 -> V_65 [ 0 ] & 0x03 ;
if ( V_19 & 0x01 ) {
if ( ( V_247 -> V_65 [ 0 ] & V_249 ) ==
V_250 )
V_19 |= 1U << 3 ;
V_248 = ( V_247 -> V_65 [ 4 ] >> 3 ) & 0x0f ;
if ( V_248 ) {
switch ( V_248 ) {
case 2 : V_19 |= 5 << 12 ; break;
case 3 : V_19 |= 6 << 12 ; break;
case 10 : V_19 |= 4 << 12 ; break;
case 11 : V_19 |= 7 << 12 ; break;
}
} else {
switch ( V_247 -> V_65 [ 0 ] & V_251 ) {
case V_252 :
break;
case V_253 :
V_19 |= 3U << 12 ;
break;
default:
V_19 |= 2U << 12 ;
break;
}
}
} else {
V_19 |= V_247 -> V_65 [ 1 ] & 0x04 ;
if ( ( V_247 -> V_65 [ 0 ] & V_254 ) ==
V_255 )
V_19 |= 1U << 3 ;
V_19 |= ( unsigned int ) ( V_247 -> V_65 [ 1 ] & 0x3f ) << 4 ;
V_19 |= ( unsigned int ) ( V_247 -> V_65 [ 3 ] & V_256 ) << 12 ;
}
return V_19 ;
}
static void F_120 ( struct V_246 * V_247 , unsigned int V_19 )
{
memset ( V_247 -> V_65 , 0 , sizeof( V_247 -> V_65 ) ) ;
V_247 -> V_65 [ 0 ] = V_19 & 0x03 ;
if ( V_19 & 0x01 ) {
if ( V_19 & ( 1U << 3 ) )
V_247 -> V_65 [ 0 ] |= V_250 ;
switch ( ( V_19 >> 12 ) & 0x7 ) {
case 0 :
break;
case 2 :
V_247 -> V_65 [ 0 ] |= V_253 ;
break;
default:
V_247 -> V_65 [ 0 ] |= V_257 ;
break;
}
} else {
V_247 -> V_65 [ 0 ] |= V_19 & ( 1U << 2 ) ;
if ( V_19 & ( 1U << 3 ) )
V_247 -> V_65 [ 0 ] |= V_255 ;
V_247 -> V_65 [ 1 ] |= ( V_19 >> 4 ) & 0x3f ;
V_247 -> V_65 [ 3 ] |= ( V_19 >> 12 ) & 0x07 ;
}
}
static int F_121 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
unsigned int V_19 ;
V_19 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
F_120 ( & V_242 -> V_243 . V_258 , V_19 ) ;
return 0 ;
}
static int F_122 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
unsigned int V_19 , V_91 ;
V_19 = F_119 ( & V_242 -> V_243 . V_258 ) ;
F_33 ( & V_2 -> V_53 ) ;
V_91 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
if ( V_19 != V_91 )
F_94 ( V_2 , V_19 ) ;
F_34 ( & V_2 -> V_53 ) ;
return V_19 != V_91 ;
}
static int F_123 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
V_242 -> V_243 . V_258 . V_65 [ 0 ] = V_259 |
V_260 |
V_261 |
V_254 ;
V_242 -> V_243 . V_258 . V_65 [ 1 ] = V_262 |
V_263 ;
V_242 -> V_243 . V_258 . V_65 [ 3 ] = V_256 ;
return 0 ;
}
static int F_124 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
V_242 -> V_243 . V_258 . V_65 [ 0 ] = V_259 |
V_260 |
V_251 |
V_249 ;
return 0 ;
}
static int F_125 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
V_242 -> V_243 . integer . V_243 [ 0 ] = F_2 ( F_15 ( V_2 , V_193 ) ) &
V_194 ? 1 : 0 ;
return 0 ;
}
static int F_126 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
unsigned char V_91 , V_19 ;
F_33 ( & V_2 -> V_53 ) ;
V_91 = V_19 = F_2 ( F_15 ( V_2 , V_193 ) ) ;
V_19 &= ~ V_194 ;
if ( V_242 -> V_243 . integer . V_243 [ 0 ] )
V_19 |= V_194 ;
if ( V_91 != V_19 )
F_9 ( V_19 , F_15 ( V_2 , V_193 ) ) ;
F_34 ( & V_2 -> V_53 ) ;
return V_91 != V_19 ;
}
static int F_127 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_264 = V_2 -> V_114 -> V_33 ;
V_238 -> type = V_265 ;
V_238 -> V_33 = 1 ;
V_238 -> V_243 . V_266 . V_267 = V_264 ;
if ( V_2 -> V_203 ||
( V_2 -> V_106 . V_25 [ V_205 ] & V_208 ) )
V_238 -> V_243 . V_266 . V_267 += V_2 -> V_268 ;
if ( V_238 -> V_243 . V_266 . V_269 >= V_238 -> V_243 . V_266 . V_267 )
V_238 -> V_243 . V_266 . V_269 = V_238 -> V_243 . V_266 . V_267 - 1 ;
if ( V_238 -> V_243 . V_266 . V_269 >= V_264 )
strcpy ( V_238 -> V_243 . V_266 . V_187 ,
V_2 -> V_270 [
V_238 -> V_243 . V_266 . V_269 - V_264 ] ) ;
else
sprintf ( V_238 -> V_243 . V_266 . V_187 , L_32 ,
V_2 -> V_114 -> V_41 [ V_238 -> V_243 . V_266 . V_269 ] ) ;
return 0 ;
}
static int F_128 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
unsigned int V_43 , V_104 ;
F_33 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_5 ( V_2 ) ) {
V_242 -> V_243 . V_266 . V_269 [ 0 ] = V_2 -> V_114 -> V_33 +
V_2 -> V_271 ( V_2 ) ;
} else {
V_104 = V_2 -> V_119 ( V_2 ) ;
V_242 -> V_243 . V_266 . V_269 [ 0 ] = 0 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_114 -> V_33 ; V_43 ++ ) {
if ( V_2 -> V_114 -> V_41 [ V_43 ] == V_104 ) {
V_242 -> V_243 . V_266 . V_269 [ 0 ] = V_43 ;
break;
}
}
}
F_34 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int type )
{
unsigned char V_272 ;
unsigned char V_273 ;
V_272 = F_2 ( F_3 ( V_2 , V_3 ) ) ;
F_9 ( V_272 | V_4 , F_3 ( V_2 , V_3 ) ) ;
V_273 = F_2 ( F_3 ( V_2 , V_109 ) ) ;
F_9 ( V_273 & ~ V_110 , F_3 ( V_2 , V_109 ) ) ;
return 0 ;
}
static int F_131 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
unsigned int V_113 , V_274 ;
unsigned int V_269 = V_242 -> V_243 . V_266 . V_269 [ 0 ] ;
unsigned int V_275 = V_2 -> V_114 -> V_33 ;
if ( V_269 > V_275 + V_2 -> V_268 - 1 )
return - V_103 ;
F_33 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_5 ( V_2 ) )
V_113 = 0 ;
else
V_113 = V_2 -> V_119 ( V_2 ) ;
if ( V_269 >= V_275 ) {
V_2 -> V_276 ( V_2 , V_269 - V_275 ) ;
V_274 = 0 ;
} else {
V_274 = V_2 -> V_114 -> V_41 [ V_269 ] ;
V_2 -> V_173 = V_274 ;
F_34 ( & V_2 -> V_53 ) ;
F_61 ( V_2 , V_2 -> V_173 , 1 ) ;
F_33 ( & V_2 -> V_53 ) ;
}
F_34 ( & V_2 -> V_53 ) ;
if ( V_113 != V_274 && ! V_274 ) {
unsigned int V_43 ;
if ( V_2 -> V_122 . V_124 )
V_2 -> V_122 . V_124 ( V_2 , 0 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_125 ; V_43 ++ ) {
if ( V_2 -> V_126 [ V_43 ] . V_127 . V_128 )
V_2 -> V_126 [ V_43 ] . V_127 . V_128 ( & V_2 -> V_126 [ V_43 ] , 0 ) ;
}
}
return V_113 != V_274 ;
}
static int F_132 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
V_242 -> V_243 . integer . V_243 [ 0 ] = V_6 ;
return 0 ;
}
static int F_133 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_277 = 0 , V_196 ;
V_196 = V_242 -> V_243 . integer . V_243 [ 0 ] ? 1 : 0 ;
F_33 ( & V_2 -> V_53 ) ;
V_277 = V_6 != V_196 ;
V_6 = V_196 ;
F_34 ( & V_2 -> V_53 ) ;
return V_277 ;
}
static int F_134 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
V_242 -> V_243 . integer . V_243 [ 0 ] = V_172 ? 1 : 0 ;
return 0 ;
}
static int F_135 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_277 = 0 , V_196 ;
V_196 = V_242 -> V_243 . integer . V_243 [ 0 ] ? 1 : 0 ;
F_33 ( & V_2 -> V_53 ) ;
V_277 = V_172 != V_196 ;
V_172 = V_196 ;
F_34 ( & V_2 -> V_53 ) ;
return V_277 ;
}
static int F_136 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
static char * V_278 [] = {
L_33 ,
L_34 , L_35 ,
L_36 , L_37 ,
} ;
V_238 -> type = V_265 ;
V_238 -> V_33 = 1 ;
V_238 -> V_243 . V_266 . V_267 = 5 ;
if ( V_238 -> V_243 . V_266 . V_269 >= V_238 -> V_243 . V_266 . V_267 )
V_238 -> V_243 . V_266 . V_269 = V_238 -> V_243 . V_266 . V_267 - 1 ;
strcpy ( V_238 -> V_243 . V_266 . V_187 , V_278 [ V_238 -> V_243 . V_266 . V_269 ] ) ;
return 0 ;
}
static inline int F_137 ( int V_223 )
{
return ( V_223 % 2 ) * 12 + ( ( V_223 / 2 ) * 3 ) + 8 ;
}
static inline int F_138 ( int V_223 )
{
return V_223 * 3 ;
}
int F_139 ( struct V_1 * V_2 , int V_279 )
{
unsigned long V_19 ;
unsigned char V_280 ;
static const unsigned char V_281 [ 8 ] = {
0 , 255 , 1 , 2 , 255 , 255 , 3 , 4 ,
} ;
V_19 = F_17 ( F_3 ( V_2 , V_233 ) ) ;
V_19 >>= V_279 ;
V_19 &= 7 ;
V_280 = V_281 [ V_19 ] ;
if ( V_280 == 255 ) {
F_140 () ;
return 0 ;
}
return V_280 ;
}
int F_141 ( struct V_1 * V_2 , unsigned int V_19 ,
int V_279 )
{
unsigned int V_282 , V_196 ;
int V_277 ;
static const unsigned char V_283 [ 8 ] = {
0 ,
2 ,
3 ,
6 ,
7 ,
} ;
V_196 = V_283 [ V_19 % 5 ] ;
V_19 = V_282 = F_17 ( F_3 ( V_2 , V_233 ) ) ;
V_19 &= ~ ( 0x07 << V_279 ) ;
V_19 |= V_196 << V_279 ;
V_277 = V_19 != V_282 ;
if ( V_277 )
F_14 ( V_19 , F_3 ( V_2 , V_233 ) ) ;
return V_277 ;
}
static int F_142 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_223 = F_143 ( V_236 , & V_242 -> V_284 ) ;
V_242 -> V_243 . V_266 . V_269 [ 0 ] =
F_139 ( V_2 , F_137 ( V_223 ) ) ;
return 0 ;
}
static int F_144 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_223 = F_143 ( V_236 , & V_242 -> V_284 ) ;
return F_141 ( V_2 ,
V_242 -> V_243 . V_266 . V_269 [ 0 ] ,
F_137 ( V_223 ) ) ;
}
static int F_145 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_223 = F_143 ( V_236 , & V_242 -> V_284 ) ;
V_242 -> V_243 . V_266 . V_269 [ 0 ] =
F_139 ( V_2 , F_138 ( V_223 ) ) ;
return 0 ;
}
static int F_146 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_223 = F_143 ( V_236 , & V_242 -> V_284 ) ;
return F_141 ( V_2 ,
V_242 -> V_243 . V_266 . V_269 [ 0 ] ,
F_138 ( V_223 ) ) ;
}
static int F_147 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
V_238 -> type = V_285 ;
V_238 -> V_33 = 22 ;
V_238 -> V_243 . integer . F_30 = 0 ;
V_238 -> V_243 . integer . V_286 = 255 ;
return 0 ;
}
static int F_148 ( struct V_235 * V_236 ,
struct V_241 * V_242 )
{
struct V_1 * V_2 = F_117 ( V_236 ) ;
int V_223 ;
F_33 ( & V_2 -> V_53 ) ;
for ( V_223 = 0 ; V_223 < 22 ; V_223 ++ ) {
F_9 ( V_223 , F_3 ( V_2 , V_287 ) ) ;
V_242 -> V_243 . integer . V_243 [ V_223 ] =
F_2 ( F_3 ( V_2 , V_288 ) ) ;
}
F_34 ( & V_2 -> V_53 ) ;
return 0 ;
}
static void F_149 ( struct V_1 * V_2 )
{
int V_289 = 0x10000 ;
while ( ( F_2 ( F_15 ( V_2 , V_290 ) ) & V_291 ) && V_289 -- )
;
if ( V_289 == - 1 )
F_49 ( V_13 L_38 ) ;
}
unsigned char F_150 ( struct V_1 * V_2 ,
unsigned char V_292 , unsigned char V_148 )
{
unsigned char V_19 ;
F_64 ( & V_2 -> V_293 ) ;
F_149 ( V_2 ) ;
F_9 ( V_148 , F_15 ( V_2 , V_294 ) ) ;
F_9 ( V_292 & ~ V_295 , F_15 ( V_2 , V_296 ) ) ;
F_149 ( V_2 ) ;
V_19 = F_2 ( F_15 ( V_2 , V_297 ) ) ;
F_65 ( & V_2 -> V_293 ) ;
return V_19 ;
}
void F_151 ( struct V_1 * V_2 ,
unsigned char V_292 , unsigned char V_148 , unsigned char V_25 )
{
F_64 ( & V_2 -> V_293 ) ;
F_149 ( V_2 ) ;
F_9 ( V_148 , F_15 ( V_2 , V_294 ) ) ;
F_9 ( V_25 , F_15 ( V_2 , V_297 ) ) ;
F_9 ( V_292 | V_295 , F_15 ( V_2 , V_296 ) ) ;
F_149 ( V_2 ) ;
F_65 ( & V_2 -> V_293 ) ;
}
static int T_5 F_152 ( struct V_1 * V_2 ,
const char * V_298 )
{
const int V_292 = 0xa0 ;
unsigned int V_43 , V_137 ;
struct V_299 * const * V_300 , * V_301 ;
if ( ! V_298 || ! * V_298 ) {
V_2 -> V_106 . V_228 = 0 ;
if ( ( F_2 ( F_15 ( V_2 , V_290 ) ) & V_302 ) != 0 )
V_2 -> V_106 . V_228 =
( F_150 ( V_2 , V_292 , 0x00 ) << 0 ) |
( F_150 ( V_2 , V_292 , 0x01 ) << 8 ) |
( F_150 ( V_2 , V_292 , 0x02 ) << 16 ) |
( F_150 ( V_2 , V_292 , 0x03 ) << 24 ) ;
if ( V_2 -> V_106 . V_228 == 0 ||
V_2 -> V_106 . V_228 == ( unsigned int ) - 1 ) {
T_6 V_303 , V_174 ;
F_153 ( V_2 -> V_189 , V_304 ,
& V_303 ) ;
F_153 ( V_2 -> V_189 , V_305 , & V_174 ) ;
V_2 -> V_106 . V_228 =
( ( unsigned int ) F_154 ( V_303 ) << 16 ) | F_154 ( V_174 ) ;
if ( V_2 -> V_106 . V_228 == 0 ||
V_2 -> V_106 . V_228 == ( unsigned int ) - 1 ) {
F_49 ( V_13 L_39 ) ;
return - V_306 ;
}
}
}
for ( V_300 = V_307 ; * V_300 ; V_300 ++ ) {
for ( V_301 = * V_300 ; V_301 -> V_187 ; V_301 ++ ) {
if ( V_298 && V_301 -> V_308 &&
! strcmp ( V_298 , V_301 -> V_308 ) ) {
F_49 ( V_309 L_40 ,
V_301 -> V_187 ) ;
V_2 -> V_106 . V_228 = V_301 -> V_228 ;
} else if ( V_301 -> V_228 != V_2 -> V_106 . V_228 )
continue;
if ( ! V_301 -> V_310 || ! V_301 -> V_311 )
goto V_312;
F_155 ( L_41 ) ;
V_2 -> V_106 . V_229 = 2 ;
V_2 -> V_106 . V_137 = V_301 -> V_310 + 6 ;
memcpy ( V_2 -> V_106 . V_25 , V_301 -> V_311 , V_301 -> V_310 ) ;
goto V_313;
}
}
F_49 ( V_221 L_42 ,
V_2 -> V_106 . V_228 ) ;
V_312:
V_2 -> V_106 . V_137 = F_150 ( V_2 , V_292 , 0x04 ) ;
if ( V_2 -> V_106 . V_137 < 6 )
V_2 -> V_106 . V_137 = 32 ;
else if ( V_2 -> V_106 . V_137 > 32 ) {
F_49 ( V_13 L_43 ,
V_2 -> V_106 . V_137 ) ;
return - V_15 ;
}
V_2 -> V_106 . V_229 = F_150 ( V_2 , V_292 , 0x05 ) ;
if ( V_2 -> V_106 . V_229 != 2 )
F_49 ( V_221 L_44 ,
V_2 -> V_106 . V_229 ) ;
V_137 = V_2 -> V_106 . V_137 - 6 ;
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ )
V_2 -> V_106 . V_25 [ V_43 ] = F_150 ( V_2 , V_292 , V_43 + 6 ) ;
V_313:
V_2 -> V_106 . V_231 = F_109 ( V_2 , V_314 ) ;
V_2 -> V_106 . V_232 = F_109 ( V_2 , V_315 ) ;
V_2 -> V_106 . V_230 = F_109 ( V_2 , V_316 ) ;
return 0 ;
}
static void F_156 ( struct V_1 * V_2 )
{
F_9 ( V_317 , F_15 ( V_2 , V_318 ) ) ;
F_2 ( F_15 ( V_2 , V_318 ) ) ;
F_157 ( 10 ) ;
F_9 ( 0 , F_15 ( V_2 , V_318 ) ) ;
F_2 ( F_15 ( V_2 , V_318 ) ) ;
F_157 ( 10 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_106 . V_25 [ V_178 ] , F_15 ( V_2 , V_319 ) ) ;
F_9 ( V_2 -> V_106 . V_25 [ V_107 ] , F_15 ( V_2 , V_320 ) ) ;
F_9 ( V_2 -> V_106 . V_25 [ V_149 ] , F_15 ( V_2 , V_321 ) ) ;
F_9 ( V_2 -> V_106 . V_25 [ V_205 ] , F_15 ( V_2 , V_193 ) ) ;
V_2 -> V_122 . V_322 = V_2 -> V_106 . V_231 ;
V_2 -> V_122 . V_323 = V_2 -> V_106 . V_230 ;
F_18 ( V_2 , V_2 -> V_106 . V_231 ) ;
F_13 ( V_2 , V_2 -> V_106 . V_230 ) ;
F_20 ( V_2 , V_2 -> V_106 . V_232 ) ;
F_9 ( 0 , F_15 ( V_2 , V_324 ) ) ;
F_9 ( V_61 | V_47 , F_15 ( V_2 , V_51 ) ) ;
F_9 ( V_84 , F_3 ( V_2 , V_87 ) ) ;
return 0 ;
}
static int T_5 F_159 ( struct V_1 * V_2 )
{
int V_134 ;
struct V_235 * V_325 ;
if ( F_160 ( ! V_2 -> V_176 ) )
return - V_15 ;
if ( ! V_2 -> V_326 ) {
V_134 = F_161 ( V_2 -> V_181 ,
F_162 ( & V_327 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
}
V_134 = F_161 ( V_2 -> V_181 , F_162 ( & V_328 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_161 ( V_2 -> V_181 , V_325 = F_162 ( & V_329 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_325 -> V_284 . V_174 = V_2 -> V_176 -> V_174 ;
V_134 = F_161 ( V_2 -> V_181 , V_325 = F_162 ( & V_330 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_325 -> V_284 . V_174 = V_2 -> V_176 -> V_174 ;
V_134 = F_161 ( V_2 -> V_181 , V_325 = F_162 ( & V_331 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_325 -> V_284 . V_174 = V_2 -> V_176 -> V_174 ;
#if 0
err = snd_ctl_add(ice->card, kctl = snd_ctl_new1(&snd_vt1724_spdif_stream, ice));
if (err < 0)
return err;
kctl->id.device = ice->pcm->device;
ice->spdif.stream_ctl = kctl;
#endif
return 0 ;
}
static int T_5 F_163 ( struct V_1 * V_2 )
{
int V_134 ;
V_134 = F_161 ( V_2 -> V_181 , F_162 ( & V_332 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_161 ( V_2 -> V_181 , F_162 ( & V_333 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_161 ( V_2 -> V_181 , F_162 ( & V_334 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_161 ( V_2 -> V_181 , F_162 ( & V_335 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
if ( ! V_2 -> V_326 && V_2 -> V_163 > 0 ) {
struct V_336 V_337 = V_338 ;
V_337 . V_33 = V_2 -> V_163 ;
if ( V_2 -> V_28 && V_337 . V_33 > 2 )
V_337 . V_33 = 2 ;
V_134 = F_161 ( V_2 -> V_181 , F_162 ( & V_337 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
}
V_134 = F_161 ( V_2 -> V_181 , F_162 ( & V_339 , V_2 ) ) ;
if ( V_134 < 0 )
return V_134 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_234 )
goto V_340;
F_9 ( 0xff , F_3 ( V_2 , V_87 ) ) ;
F_9 ( 0xff , F_15 ( V_2 , V_51 ) ) ;
V_340:
if ( V_2 -> V_63 >= 0 )
F_165 ( V_2 -> V_63 , V_2 ) ;
F_166 ( V_2 -> V_189 ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 -> V_189 ) ;
F_169 ( V_2 -> V_341 ) ;
F_169 ( V_2 ) ;
return 0 ;
}
static int F_170 ( struct V_342 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_343 ;
return F_164 ( V_2 ) ;
}
static int T_5 F_171 ( struct V_344 * V_181 ,
struct V_345 * V_189 ,
const char * V_298 ,
struct V_1 * * V_346 )
{
struct V_1 * V_2 ;
int V_134 ;
static struct V_347 V_127 = {
. V_348 = F_170 ,
} ;
* V_346 = NULL ;
V_134 = F_172 ( V_189 ) ;
if ( V_134 < 0 )
return V_134 ;
V_2 = F_173 ( sizeof( * V_2 ) , V_349 ) ;
if ( V_2 == NULL ) {
F_168 ( V_189 ) ;
return - V_350 ;
}
V_2 -> V_351 = 1 ;
F_174 ( & V_2 -> V_53 ) ;
F_175 ( & V_2 -> V_352 ) ;
F_175 ( & V_2 -> V_135 ) ;
F_175 ( & V_2 -> V_293 ) ;
V_2 -> V_122 . V_353 = F_18 ;
V_2 -> V_122 . V_354 = F_19 ;
V_2 -> V_122 . V_355 = F_13 ;
V_2 -> V_122 . V_356 = F_16 ;
V_2 -> V_122 . V_357 = F_20 ;
V_2 -> V_122 . V_358 = F_21 ;
V_2 -> V_181 = V_181 ;
V_2 -> V_189 = V_189 ;
V_2 -> V_63 = - 1 ;
F_176 ( V_189 ) ;
F_112 ( V_2 ) ;
F_177 ( V_189 -> V_63 ) ;
V_181 -> V_20 = V_2 ;
V_134 = F_178 ( V_189 , L_7 ) ;
if ( V_134 < 0 ) {
F_169 ( V_2 ) ;
F_168 ( V_189 ) ;
return V_134 ;
}
V_2 -> V_234 = F_179 ( V_189 , 0 ) ;
V_2 -> V_147 = F_179 ( V_189 , 1 ) ;
if ( F_180 ( V_189 -> V_63 , F_47 ,
V_359 , V_360 , V_2 ) ) {
F_181 ( V_13 L_45 , V_189 -> V_63 ) ;
F_164 ( V_2 ) ;
return - V_15 ;
}
V_2 -> V_63 = V_189 -> V_63 ;
F_156 ( V_2 ) ;
if ( F_152 ( V_2 , V_298 ) < 0 ) {
F_164 ( V_2 ) ;
return - V_15 ;
}
if ( F_158 ( V_2 ) < 0 ) {
F_164 ( V_2 ) ;
return - V_15 ;
}
V_134 = F_182 ( V_181 , V_361 , V_2 , & V_127 ) ;
if ( V_134 < 0 ) {
F_164 ( V_2 ) ;
return V_134 ;
}
F_183 ( V_181 , & V_189 -> V_292 ) ;
* V_346 = V_2 ;
return 0 ;
}
static int T_5 F_184 ( struct V_345 * V_189 ,
const struct V_362 * V_363 )
{
static int V_292 ;
struct V_344 * V_181 ;
struct V_1 * V_2 ;
int V_364 = 0 , V_134 ;
struct V_299 * const * V_300 , * V_301 ;
if ( V_292 >= V_365 )
return - V_366 ;
if ( ! V_50 [ V_292 ] ) {
V_292 ++ ;
return - V_367 ;
}
V_134 = F_185 ( V_368 [ V_292 ] , V_284 [ V_292 ] , V_369 , 0 , & V_181 ) ;
if ( V_134 < 0 )
return V_134 ;
strcpy ( V_181 -> V_370 , L_7 ) ;
strcpy ( V_181 -> V_371 , L_46 ) ;
V_134 = F_171 ( V_181 , V_189 , V_308 [ V_292 ] , & V_2 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
V_2 -> V_268 = 0 ;
for ( V_300 = V_307 ; * V_300 ; V_300 ++ ) {
for ( V_301 = * V_300 ; V_301 -> V_187 ; V_301 ++ ) {
if ( ( V_308 [ V_292 ] && V_301 -> V_308 &&
! strcmp ( V_308 [ V_292 ] , V_301 -> V_308 ) ) ||
( V_301 -> V_228 == V_2 -> V_106 . V_228 ) ) {
strcpy ( V_181 -> V_371 , V_301 -> V_187 ) ;
if ( V_301 -> V_370 )
strcpy ( V_181 -> V_370 , V_301 -> V_370 ) ;
if ( V_301 -> V_372 ) {
V_134 = V_301 -> V_372 ( V_2 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
}
goto V_373;
}
}
}
V_301 = & V_374 ;
V_373:
V_2 -> V_173 = V_375 ;
if ( ! V_2 -> V_5 )
V_2 -> V_5 = F_1 ;
if ( ! V_2 -> V_119 )
V_2 -> V_119 = F_57 ;
if ( ! V_2 -> V_120 )
V_2 -> V_120 = F_58 ;
if ( ! V_2 -> V_121 )
V_2 -> V_121 = F_60 ;
if ( ! V_2 -> V_276 )
V_2 -> V_276 = F_130 ;
if ( ! V_2 -> V_271 )
V_2 -> V_271 = F_129 ;
if ( ! V_2 -> V_270 )
V_2 -> V_270 = V_270 ;
if ( ! V_2 -> V_268 )
V_2 -> V_268 = F_59 ( V_270 ) ;
if ( ! V_2 -> V_114 )
F_78 ( V_2 ) ;
V_134 = F_89 ( V_2 , V_364 ++ ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
V_134 = F_101 ( V_2 , V_364 ++ ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
V_134 = F_105 ( V_2 , V_364 ++ ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
V_134 = F_106 ( V_2 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
V_134 = F_163 ( V_2 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
if ( V_2 -> V_176 && V_2 -> V_207 ) {
V_134 = F_159 ( V_2 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
}
if ( V_301 -> V_376 ) {
V_134 = V_301 -> V_376 ( V_2 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
}
if ( ! V_301 -> V_377 ) {
if ( V_2 -> V_106 . V_25 [ V_178 ] & V_378 ) {
struct V_379 * V_38 ;
V_134 = F_187 ( V_181 , L_47 , 0 , 1 , 1 , & V_38 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
V_2 -> V_38 [ 0 ] = V_38 ;
V_38 -> V_20 = V_2 ;
strcpy ( V_38 -> V_187 , L_48 ) ;
V_38 -> V_186 = V_380 |
V_381 |
V_382 ;
F_188 ( V_38 , V_45 ,
& V_383 ) ;
F_188 ( V_38 , V_48 ,
& V_384 ) ;
F_9 ( V_385 | 0x1 ,
F_15 ( V_2 , V_386 ) ) ;
F_9 ( 0x1 , F_15 ( V_2 , V_386 ) ) ;
F_9 ( V_387 , F_15 ( V_2 , V_59 ) ) ;
}
}
sprintf ( V_181 -> V_227 , L_49 ,
V_181 -> V_371 , V_2 -> V_234 , V_2 -> V_63 ) ;
V_134 = F_189 ( V_181 ) ;
if ( V_134 < 0 ) {
F_186 ( V_181 ) ;
return V_134 ;
}
F_190 ( V_189 , V_181 ) ;
V_292 ++ ;
return 0 ;
}
static void T_7 F_191 ( struct V_345 * V_189 )
{
F_186 ( F_192 ( V_189 ) ) ;
F_190 ( V_189 , NULL ) ;
}
static int F_193 ( struct V_174 * V_292 )
{
struct V_345 * V_189 = F_194 ( V_292 ) ;
struct V_344 * V_181 = F_195 ( V_292 ) ;
struct V_1 * V_2 = V_181 -> V_20 ;
if ( ! V_2 -> V_388 )
return 0 ;
F_196 ( V_181 , V_389 ) ;
F_197 ( V_2 -> V_176 ) ;
F_197 ( V_2 -> V_190 ) ;
F_197 ( V_2 -> V_214 ) ;
F_198 ( V_2 -> V_17 ) ;
F_33 ( & V_2 -> V_53 ) ;
V_2 -> V_390 = V_2 -> V_5 ( V_2 ) ;
V_2 -> V_391 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
V_2 -> V_392 = F_2 ( F_15 ( V_2 , V_193 ) ) ;
V_2 -> V_393 = F_17 ( F_3 ( V_2 , V_233 ) ) ;
F_34 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_394 )
V_2 -> V_394 ( V_2 ) ;
F_168 ( V_189 ) ;
F_199 ( V_189 ) ;
F_200 ( V_189 , V_395 ) ;
return 0 ;
}
static int F_201 ( struct V_174 * V_292 )
{
struct V_345 * V_189 = F_194 ( V_292 ) ;
struct V_344 * V_181 = F_195 ( V_292 ) ;
struct V_1 * V_2 = V_181 -> V_20 ;
if ( ! V_2 -> V_388 )
return 0 ;
F_200 ( V_189 , V_396 ) ;
F_202 ( V_189 ) ;
if ( F_172 ( V_189 ) < 0 ) {
F_203 ( V_181 ) ;
return - V_15 ;
}
F_176 ( V_189 ) ;
F_156 ( V_2 ) ;
if ( F_158 ( V_2 ) < 0 ) {
F_203 ( V_181 ) ;
return - V_15 ;
}
if ( V_2 -> V_397 )
V_2 -> V_397 ( V_2 ) ;
if ( V_2 -> V_390 ) {
V_2 -> V_276 ( V_2 , 0 ) ;
} else {
int V_104 ;
if ( V_2 -> V_117 )
V_104 = V_2 -> V_117 ;
else
V_104 = V_2 -> V_173 ;
F_61 ( V_2 , V_104 , 1 ) ;
}
F_94 ( V_2 , V_2 -> V_391 ) ;
F_9 ( V_2 -> V_392 , F_15 ( V_2 , V_193 ) ) ;
F_14 ( V_2 -> V_393 , F_3 ( V_2 , V_233 ) ) ;
if ( V_2 -> V_17 )
F_204 ( V_2 -> V_17 ) ;
F_196 ( V_181 , V_398 ) ;
return 0 ;
}
