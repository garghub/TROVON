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
F_6 ( V_2 -> V_13 -> V_14 , L_1 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char V_15 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 0x10000 ; V_8 ++ )
if ( ( F_2 ( F_3 ( V_2 , V_9 ) ) & V_15 ) == 0 )
return 0 ;
F_6 ( V_2 -> V_13 -> V_14 , L_2 ) ;
return - V_16 ;
}
static void F_8 ( struct V_17 * V_18 ,
unsigned short V_19 ,
unsigned short V_20 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
unsigned char V_7 ;
V_7 = F_5 ( V_2 ) ;
V_7 &= ~ V_22 ;
V_7 |= V_18 -> V_23 ;
F_9 ( V_19 , F_3 ( V_2 , V_24 ) ) ;
F_10 ( V_20 , F_3 ( V_2 , V_25 ) ) ;
F_9 ( V_7 | V_10 , F_3 ( V_2 , V_9 ) ) ;
F_7 ( V_2 , V_10 ) ;
}
static unsigned short F_11 ( struct V_17 * V_18 , unsigned short V_19 )
{
struct V_1 * V_2 = V_18 -> V_21 ;
unsigned char V_7 ;
V_7 = F_5 ( V_2 ) ;
V_7 &= ~ V_22 ;
V_7 |= V_18 -> V_23 ;
F_9 ( V_19 , F_3 ( V_2 , V_24 ) ) ;
F_9 ( V_7 | V_11 , F_3 ( V_2 , V_9 ) ) ;
if ( F_7 ( V_2 , V_11 ) < 0 )
return ~ 0 ;
return F_12 ( F_3 ( V_2 , V_25 ) ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_26 )
{
F_14 ( V_26 , F_15 ( V_2 , V_27 ) ) ;
F_12 ( F_15 ( V_2 , V_27 ) ) ;
}
static unsigned int F_16 ( struct V_1 * V_2 )
{
return F_17 ( F_15 ( V_2 , V_27 ) ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_26 )
{
F_10 ( V_26 , F_15 ( V_2 , V_28 ) ) ;
if ( ! V_2 -> V_29 )
F_9 ( ( V_26 >> 16 ) & 0xff , F_15 ( V_2 , V_30 ) ) ;
F_12 ( F_15 ( V_2 , V_28 ) ) ;
}
static unsigned int F_19 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
if ( ! V_2 -> V_29 )
V_31 = ( unsigned int ) F_2 ( F_15 ( V_2 , V_30 ) ) ;
else
V_31 = 0 ;
V_31 = ( V_31 << 16 ) | F_12 ( F_15 ( V_2 , V_28 ) ) ;
return V_31 ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_26 )
{
F_10 ( V_26 , F_15 ( V_2 , V_32 ) ) ;
if ( ! V_2 -> V_29 )
F_9 ( V_26 >> 16 , F_15 ( V_2 , V_33 ) ) ;
F_12 ( F_15 ( V_2 , V_32 ) ) ;
}
static unsigned int F_21 ( struct V_1 * V_2 )
{
unsigned int V_26 ;
if ( ! V_2 -> V_29 )
V_26 = ( unsigned int ) F_2 ( F_15 ( V_2 , V_33 ) ) ;
else
V_26 = 0 ;
V_26 = ( V_26 << 16 ) | F_12 ( F_15 ( V_2 , V_32 ) ) ;
return V_26 ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned int V_34 ;
for ( V_34 = F_2 ( F_15 ( V_2 , V_35 ) ) ; V_34 > 0 ; -- V_34 )
F_2 ( F_15 ( V_2 , V_36 ) ) ;
}
static inline struct V_37 *
F_23 ( struct V_1 * V_2 , unsigned int V_38 )
{
return F_24 ( & V_2 -> V_39 [ 0 ] -> V_40 [ V_38 ] . V_41 ,
struct V_37 , V_42 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_37 * V_43 ;
int V_34 , V_44 ;
T_1 V_45 [ 32 ] ;
V_43 = F_23 ( V_2 , V_46 ) ;
V_34 = 31 - F_2 ( F_15 ( V_2 , V_47 ) ) ;
if ( V_34 > 0 ) {
V_34 = F_26 ( V_43 , V_45 , V_34 ) ;
for ( V_44 = 0 ; V_44 < V_34 ; ++ V_44 )
F_9 ( V_45 [ V_44 ] , F_15 ( V_2 , V_36 ) ) ;
}
F_27 ( V_2 , V_48 ,
! F_28 ( V_43 ) ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_37 * V_43 ;
int V_34 , V_44 ;
T_1 V_45 [ 32 ] ;
V_43 = F_23 ( V_2 , V_49 ) ;
V_34 = F_2 ( F_15 ( V_2 , V_35 ) ) ;
if ( V_34 > 0 ) {
V_34 = F_30 ( V_34 , 32 ) ;
for ( V_44 = 0 ; V_44 < V_34 ; ++ V_44 )
V_45 [ V_44 ] = F_2 ( F_15 ( V_2 , V_36 ) ) ;
F_31 ( V_43 , V_45 , V_34 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , T_1 V_50 , int V_51 )
{
T_1 V_31 = F_2 ( F_15 ( V_2 , V_52 ) ) ;
if ( V_51 )
V_31 &= ~ V_50 ;
else
V_31 |= V_50 ;
F_9 ( V_31 , F_15 ( V_2 , V_52 ) ) ;
}
static void F_32 ( struct V_37 * V_53 ,
T_1 V_50 , int V_51 )
{
struct V_1 * V_2 = V_53 -> V_39 -> V_21 ;
F_33 ( & V_2 -> V_54 ) ;
F_27 ( V_2 , V_50 , V_51 ) ;
F_34 ( & V_2 -> V_54 ) ;
}
static int F_35 ( struct V_37 * V_43 )
{
return 0 ;
}
static int F_36 ( struct V_37 * V_43 )
{
return 0 ;
}
static void F_37 ( struct V_37 * V_43 , int V_55 )
{
struct V_1 * V_2 = V_43 -> V_39 -> V_21 ;
unsigned long V_56 ;
F_38 ( & V_2 -> V_54 , V_56 ) ;
if ( V_55 ) {
V_2 -> V_57 = 1 ;
F_25 ( V_2 ) ;
} else {
V_2 -> V_57 = 0 ;
F_27 ( V_2 , V_48 , 0 ) ;
}
F_39 ( & V_2 -> V_54 , V_56 ) ;
}
static void F_40 ( struct V_37 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_39 -> V_21 ;
unsigned long V_58 ;
F_32 ( V_43 , V_48 , 0 ) ;
V_58 = V_59 + F_41 ( 15 ) ;
do {
if ( F_2 ( F_15 ( V_2 , V_60 ) ) & V_61 )
break;
F_42 ( 1 ) ;
} while ( F_43 ( V_58 , V_59 ) );
}
static int F_44 ( struct V_37 * V_43 )
{
F_22 ( V_43 -> V_39 -> V_21 ) ;
F_32 ( V_43 , V_62 , 1 ) ;
return 0 ;
}
static int F_45 ( struct V_37 * V_43 )
{
F_32 ( V_43 , V_62 , 0 ) ;
return 0 ;
}
static void F_46 ( struct V_37 * V_43 , int V_55 )
{
struct V_1 * V_2 = V_43 -> V_39 -> V_21 ;
unsigned long V_56 ;
F_38 ( & V_2 -> V_54 , V_56 ) ;
if ( V_55 ) {
V_2 -> V_63 = 1 ;
F_29 ( V_2 ) ;
} else {
V_2 -> V_63 = 0 ;
}
F_39 ( & V_2 -> V_54 , V_56 ) ;
}
static T_2 F_47 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned char V_66 ;
unsigned char V_67 =
V_62 | V_48 | V_68 ;
int V_69 = 0 ;
int V_58 = 0 ;
while ( 1 ) {
V_66 = F_2 ( F_15 ( V_2 , V_70 ) ) ;
V_66 &= V_67 ;
if ( V_66 == 0 )
break;
F_48 ( & V_2 -> V_54 ) ;
if ( ++ V_58 > 10 ) {
V_66 = F_2 ( F_15 ( V_2 , V_70 ) ) ;
F_49 ( V_2 -> V_13 -> V_14 ,
L_3 , V_66 ) ;
if ( V_66 & V_48 ) {
F_49 ( V_2 -> V_13 -> V_14 , L_4 ) ;
F_27 ( V_2 , V_48 , 0 ) ;
}
F_50 ( & V_2 -> V_54 ) ;
break;
}
V_69 = 1 ;
if ( V_66 & V_48 ) {
if ( V_2 -> V_57 )
F_25 ( V_2 ) ;
else
F_27 ( V_2 , V_48 , 0 ) ;
V_67 &= ~ V_48 ;
}
if ( V_66 & V_62 ) {
if ( V_2 -> V_63 )
F_29 ( V_2 ) ;
else
F_22 ( V_2 ) ;
}
F_9 ( V_66 , F_15 ( V_2 , V_70 ) ) ;
F_50 ( & V_2 -> V_54 ) ;
if ( V_66 & V_68 ) {
unsigned char V_71 = F_2 ( F_3 ( V_2 , V_72 ) ) ;
if ( V_71 & V_73 ) {
if ( V_2 -> V_74 )
F_51 ( V_2 -> V_74 ) ;
}
if ( V_71 & V_75 ) {
if ( V_2 -> V_76 )
F_51 ( V_2 -> V_76 ) ;
}
if ( V_71 & V_77 ) {
if ( V_2 -> V_78 [ 0 ] )
F_51 ( V_2 -> V_78 [ 0 ] ) ;
}
if ( V_71 & V_79 ) {
if ( V_2 -> V_78 [ 1 ] )
F_51 ( V_2 -> V_78 [ 1 ] ) ;
}
if ( V_71 & V_80 ) {
if ( V_2 -> V_78 [ 2 ] )
F_51 ( V_2 -> V_78 [ 2 ] ) ;
}
if ( V_71 & V_81 ) {
if ( V_2 -> V_82 )
F_51 ( V_2 -> V_82 ) ;
}
if ( V_71 & V_83 ) {
if ( V_2 -> V_84 )
F_51 ( V_2 -> V_84 ) ;
}
F_9 ( V_71 , F_3 ( V_2 , V_72 ) ) ;
if ( V_71 & V_85 ) {
unsigned char V_86 = F_2 ( F_3 ( V_2 , V_87 ) ) ;
F_9 ( V_86 , F_3 ( V_2 , V_87 ) ) ;
F_9 ( V_85 | F_2 ( F_3 ( V_2 , V_88 ) ) , F_3 ( V_2 , V_88 ) ) ;
}
}
}
return F_52 ( V_69 ) ;
}
static int F_53 ( struct V_89 * V_53 , int V_90 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
unsigned char V_91 ;
unsigned char V_92 ;
struct V_89 * V_43 ;
V_91 = 0 ;
F_55 (s, substream) {
if ( F_54 ( V_43 ) == V_2 ) {
const struct V_93 * V_19 ;
V_19 = V_43 -> V_94 -> V_21 ;
V_91 |= V_19 -> V_95 ;
F_56 ( V_43 , V_53 ) ;
}
}
switch ( V_90 ) {
case V_96 :
case V_97 :
F_48 ( & V_2 -> V_54 ) ;
V_92 = F_2 ( F_3 ( V_2 , V_98 ) ) ;
if ( V_90 == V_96 )
V_92 |= V_91 ;
else
V_92 &= ~ V_91 ;
F_9 ( V_92 , F_3 ( V_2 , V_98 ) ) ;
F_50 ( & V_2 -> V_54 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
F_48 ( & V_2 -> V_54 ) ;
V_92 = F_2 ( F_3 ( V_2 , V_102 ) ) ;
if ( V_90 == V_99 )
V_92 |= V_91 ;
else
V_92 &= ~ V_91 ;
F_9 ( V_92 , F_3 ( V_2 , V_102 ) ) ;
F_50 ( & V_2 -> V_54 ) ;
break;
case V_103 :
break;
default:
return - V_104 ;
}
return 0 ;
}
static unsigned int F_57 ( struct V_1 * V_2 )
{
unsigned int V_105 ;
V_105 = V_106 [ F_2 ( F_3 ( V_2 , V_3 ) ) & 15 ] ;
return V_105 ;
}
static void F_58 ( struct V_1 * V_2 , unsigned int V_105 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_59 ( V_106 ) ; V_44 ++ ) {
if ( V_106 [ V_44 ] == V_105 ) {
F_9 ( V_44 , F_3 ( V_2 , V_3 ) ) ;
return;
}
}
}
static unsigned char F_60 ( struct V_1 * V_2 ,
unsigned int V_105 )
{
unsigned char V_20 , V_92 ;
if ( V_2 -> V_107 . V_26 [ V_108 ] & V_109 ) {
V_20 = V_92 = F_2 ( F_3 ( V_2 , V_110 ) ) ;
if ( V_105 > 96000 )
V_20 |= V_111 ;
else
V_20 &= ~ V_111 ;
if ( V_20 != V_92 ) {
F_9 ( V_20 , F_3 ( V_2 , V_110 ) ) ;
return 1 ;
}
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned int V_105 ,
int V_112 )
{
unsigned long V_56 ;
unsigned char V_113 ;
unsigned int V_44 , V_114 ;
if ( V_105 > V_2 -> V_115 -> V_42 [ V_2 -> V_115 -> V_34 - 1 ] )
return - V_104 ;
F_38 ( & V_2 -> V_54 , V_56 ) ;
if ( ( F_2 ( F_3 ( V_2 , V_102 ) ) & V_116 ) ||
( F_2 ( F_3 ( V_2 , V_98 ) ) & V_117 ) ) {
F_39 ( & V_2 -> V_54 , V_56 ) ;
return ( ( V_105 == V_2 -> V_118 ) && ! V_112 ) ? 0 : - V_119 ;
}
if ( ! V_112 && F_4 ( V_2 ) ) {
F_39 ( & V_2 -> V_54 , V_56 ) ;
return ( V_105 == V_2 -> V_118 ) ? 0 : - V_119 ;
}
if ( V_112 || ! V_2 -> V_5 ( V_2 ) ) {
V_114 = V_2 -> V_120 ( V_2 ) ;
if ( V_112 || ( V_114 != V_105 ) )
V_2 -> V_121 ( V_2 , V_105 ) ;
else if ( V_105 == V_2 -> V_118 ) {
F_39 ( & V_2 -> V_54 , V_56 ) ;
return 0 ;
}
}
V_2 -> V_118 = V_105 ;
V_113 = V_2 -> V_122 ( V_2 , V_105 ) ;
F_39 ( & V_2 -> V_54 , V_56 ) ;
if ( V_113 && V_2 -> V_123 . V_124 )
V_2 -> V_123 . V_124 ( V_2 ) ;
if ( V_2 -> V_123 . V_125 )
V_2 -> V_123 . V_125 ( V_2 , V_105 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_126 ; V_44 ++ ) {
if ( V_2 -> V_127 [ V_44 ] . V_128 . V_129 )
V_2 -> V_127 [ V_44 ] . V_128 . V_129 ( & V_2 -> V_127 [ V_44 ] , V_105 ) ;
}
if ( V_2 -> V_130 . V_128 . V_131 )
V_2 -> V_130 . V_128 . V_131 ( V_2 , V_105 ) ;
return 0 ;
}
static int F_62 ( struct V_89 * V_53 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
int V_44 , V_134 , V_135 ;
V_134 = F_63 ( V_133 ) ;
F_64 ( & V_2 -> V_136 ) ;
if ( V_53 == V_2 -> V_74 ) {
V_134 = V_134 / 2 - 1 ;
for ( V_44 = 0 ; V_44 < V_134 ; V_44 ++ ) {
if ( V_2 -> V_137 [ V_44 ] &&
V_2 -> V_137 [ V_44 ] != V_53 ) {
F_65 ( & V_2 -> V_136 ) ;
return - V_119 ;
}
V_2 -> V_137 [ V_44 ] = V_53 ;
}
for (; V_44 < 3 ; V_44 ++ ) {
if ( V_2 -> V_137 [ V_44 ] == V_53 )
V_2 -> V_137 [ V_44 ] = NULL ;
}
} else {
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ ) {
if ( V_2 -> V_78 [ V_44 ] == V_53 ) {
if ( V_2 -> V_137 [ V_44 ] &&
V_2 -> V_137 [ V_44 ] != V_53 ) {
F_65 ( & V_2 -> V_136 ) ;
return - V_119 ;
}
V_2 -> V_137 [ V_44 ] = V_53 ;
break;
}
}
}
F_65 ( & V_2 -> V_136 ) ;
V_135 = F_61 ( V_2 , F_66 ( V_133 ) , 0 ) ;
if ( V_135 < 0 )
return V_135 ;
return F_67 ( V_53 , F_68 ( V_133 ) ) ;
}
static int F_69 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
int V_44 ;
F_64 ( & V_2 -> V_136 ) ;
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ )
if ( V_2 -> V_137 [ V_44 ] == V_53 )
V_2 -> V_137 [ V_44 ] = NULL ;
F_65 ( & V_2 -> V_136 ) ;
return F_70 ( V_53 ) ;
}
static int F_71 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
unsigned char V_20 ;
unsigned int V_138 ;
F_33 ( & V_2 -> V_54 ) ;
V_20 = ( 8 - V_53 -> V_94 -> V_139 ) >> 1 ;
F_9 ( V_20 , F_3 ( V_2 , V_140 ) ) ;
F_14 ( V_53 -> V_94 -> V_141 , F_3 ( V_2 , V_142 ) ) ;
V_138 = ( F_72 ( V_53 ) >> 2 ) - 1 ;
F_10 ( V_138 , F_3 ( V_2 , V_143 ) ) ;
F_9 ( V_138 >> 16 , F_3 ( V_2 , V_143 ) + 2 ) ;
V_138 = ( F_73 ( V_53 ) >> 2 ) - 1 ;
F_10 ( V_138 , F_3 ( V_2 , V_144 ) ) ;
F_9 ( V_138 >> 16 , F_3 ( V_2 , V_144 ) + 2 ) ;
F_34 ( & V_2 -> V_54 ) ;
return 0 ;
}
static T_3 F_74 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
T_4 V_145 ;
if ( ! ( F_17 ( F_3 ( V_2 , V_102 ) ) & V_146 ) )
return 0 ;
#if 0
ptr = inl(ICEMT1724(ice, PLAYBACK_ADDR));
if (ptr < substream->runtime->dma_addr) {
dev_dbg(ice->card->dev, "invalid negative ptr\n");
return 0;
}
ptr -= substream->runtime->dma_addr;
ptr = bytes_to_frames(substream->runtime, ptr);
if (ptr >= substream->runtime->buffer_size) {
dev_dbg(ice->card->dev, "invalid ptr %d (size=%d)\n",
(int)ptr, (int)substream->runtime->period_size);
return 0;
}
#else
V_145 = F_17 ( F_3 ( V_2 , V_143 ) ) & 0xffffff ;
V_145 = ( V_145 + 1 ) << 2 ;
V_145 = F_75 ( V_53 -> V_94 , V_145 ) ;
if ( ! V_145 )
;
else if ( V_145 <= V_53 -> V_94 -> V_147 )
V_145 = V_53 -> V_94 -> V_147 - V_145 ;
else {
F_6 ( V_2 -> V_13 -> V_14 , L_5 ,
( int ) V_145 , ( int ) V_53 -> V_94 -> V_147 ) ;
V_145 = 0 ;
}
#endif
return V_145 ;
}
static int F_76 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
const struct V_93 * V_19 = V_53 -> V_94 -> V_21 ;
F_33 ( & V_2 -> V_54 ) ;
F_14 ( V_53 -> V_94 -> V_141 , V_2 -> V_148 + V_19 -> V_149 ) ;
F_10 ( ( F_72 ( V_53 ) >> 2 ) - 1 ,
V_2 -> V_148 + V_19 -> V_138 ) ;
F_10 ( ( F_73 ( V_53 ) >> 2 ) - 1 ,
V_2 -> V_148 + V_19 -> V_34 ) ;
F_34 ( & V_2 -> V_54 ) ;
return 0 ;
}
static T_3 F_77 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
const struct V_93 * V_19 = V_53 -> V_94 -> V_21 ;
T_4 V_145 ;
if ( ! ( F_17 ( F_3 ( V_2 , V_102 ) ) & V_19 -> V_95 ) )
return 0 ;
#if 0
ptr = inl(ice->profi_port + reg->addr);
ptr -= substream->runtime->dma_addr;
return bytes_to_frames(substream->runtime, ptr);
#else
V_145 = F_12 ( V_2 -> V_148 + V_19 -> V_138 ) ;
V_145 = ( V_145 + 1 ) << 2 ;
V_145 = F_75 ( V_53 -> V_94 , V_145 ) ;
if ( ! V_145 )
;
else if ( V_145 <= V_53 -> V_94 -> V_147 )
V_145 = V_53 -> V_94 -> V_147 - V_145 ;
else {
F_6 ( V_2 -> V_13 -> V_14 , L_5 ,
( int ) V_145 , ( int ) V_53 -> V_94 -> V_147 ) ;
V_145 = 0 ;
}
return V_145 ;
#endif
}
static void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_107 . V_26 [ V_108 ] & V_109 ) {
if ( ( V_2 -> V_107 . V_26 [ V_150 ] & 0x08 ) && ! V_2 -> V_29 )
V_2 -> V_115 = & V_151 ;
else
V_2 -> V_115 = & V_152 ;
} else {
V_2 -> V_115 = & V_153 ;
}
}
static int F_79 ( struct V_1 * V_2 ,
struct V_89 * V_53 )
{
struct V_154 * V_94 = V_53 -> V_94 ;
V_94 -> V_155 . V_156 = V_2 -> V_115 -> V_42 [ 0 ] ;
V_94 -> V_155 . V_157 = V_2 -> V_115 -> V_42 [ V_2 -> V_115 -> V_34 - 1 ] ;
V_94 -> V_155 . V_158 = V_159 ;
return F_80 ( V_94 , 0 ,
V_160 ,
V_2 -> V_115 ) ;
}
static void F_81 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
struct V_154 * V_94 = V_53 -> V_94 ;
unsigned int V_105 ;
if ( F_4 ( V_2 ) ) {
V_105 = V_2 -> V_120 ( V_2 ) ;
if ( V_105 >= V_94 -> V_155 . V_156
&& V_105 <= V_94 -> V_155 . V_157 ) {
V_94 -> V_155 . V_156 = V_105 ;
V_94 -> V_155 . V_157 = V_105 ;
}
}
}
static int F_82 ( struct V_89 * V_53 )
{
struct V_154 * V_94 = V_53 -> V_94 ;
struct V_1 * V_2 = F_54 ( V_53 ) ;
int V_134 , V_161 ;
V_94 -> V_21 = ( void * ) & V_162 ;
V_2 -> V_74 = V_53 ;
V_94 -> V_155 = V_163 ;
F_83 ( V_53 ) ;
F_84 ( V_94 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_53 ) ;
F_64 ( & V_2 -> V_136 ) ;
V_161 = V_2 -> V_164 / 2 - 1 ;
for ( V_134 = 0 ; V_134 < V_161 ; V_134 ++ ) {
if ( V_2 -> V_137 [ V_134 ] )
break;
}
V_134 = ( V_134 + 1 ) * 2 ;
V_94 -> V_155 . V_165 = V_134 ;
if ( V_134 > 2 )
F_85 ( V_94 , 0 , V_166 , 2 ) ;
F_65 ( & V_2 -> V_136 ) ;
F_85 ( V_94 , 0 , V_167 ,
V_168 ) ;
F_85 ( V_94 , 0 , V_169 ,
V_168 ) ;
F_81 ( V_53 ) ;
if ( V_2 -> V_170 )
V_2 -> V_170 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_86 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
struct V_154 * V_94 = V_53 -> V_94 ;
V_94 -> V_21 = ( void * ) & V_171 ;
V_2 -> V_76 = V_53 ;
V_94 -> V_155 = V_172 ;
F_83 ( V_53 ) ;
F_84 ( V_94 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_53 ) ;
F_85 ( V_94 , 0 , V_167 ,
V_168 ) ;
F_85 ( V_94 , 0 , V_169 ,
V_168 ) ;
F_81 ( V_53 ) ;
if ( V_2 -> V_170 )
V_2 -> V_170 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_87 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
if ( V_173 )
F_61 ( V_2 , V_2 -> V_174 , 0 ) ;
V_2 -> V_74 = NULL ;
return 0 ;
}
static int F_88 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
if ( V_173 )
F_61 ( V_2 , V_2 -> V_174 , 0 ) ;
V_2 -> V_76 = NULL ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int V_175 )
{
struct V_176 * V_177 ;
int V_178 , V_135 ;
if ( ( V_2 -> V_107 . V_26 [ V_179 ] & V_180 ) ==
V_181 )
V_178 = 0 ;
else
V_178 = 1 ;
V_135 = F_90 ( V_2 -> V_13 , L_6 , V_175 , 1 , V_178 , & V_177 ) ;
if ( V_135 < 0 )
return V_135 ;
F_91 ( V_177 , V_182 , & V_183 ) ;
if ( V_178 )
F_91 ( V_177 , V_184 ,
& V_185 ) ;
V_177 -> V_21 = V_2 ;
V_177 -> V_186 = 0 ;
strcpy ( V_177 -> V_187 , L_6 ) ;
F_92 ( V_177 , V_188 ,
F_93 ( V_2 -> V_189 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_190 = V_177 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 , unsigned int V_20 )
{
unsigned char V_191 , V_192 ;
V_191 = F_2 ( F_15 ( V_2 , V_193 ) ) ;
V_192 = V_191 & ~ V_194 ;
if ( V_191 != V_192 )
F_9 ( V_192 , F_15 ( V_2 , V_193 ) ) ;
F_10 ( V_20 , F_3 ( V_2 , V_195 ) ) ;
if ( V_191 != V_192 )
F_9 ( V_191 , F_15 ( V_2 , V_193 ) ) ;
F_10 ( V_20 , F_3 ( V_2 , V_195 ) ) ;
}
static void F_95 ( struct V_1 * V_2 , unsigned int V_105 )
{
unsigned int V_20 , V_196 ;
unsigned long V_56 ;
F_38 ( & V_2 -> V_54 , V_56 ) ;
V_196 = V_20 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
V_196 &= ~ ( 7 << 12 ) ;
switch ( V_105 ) {
case 44100 : break;
case 48000 : V_196 |= 2 << 12 ; break;
case 32000 : V_196 |= 3 << 12 ; break;
case 88200 : V_196 |= 4 << 12 ; break;
case 96000 : V_196 |= 5 << 12 ; break;
case 192000 : V_196 |= 6 << 12 ; break;
case 176400 : V_196 |= 7 << 12 ; break;
}
if ( V_20 != V_196 )
F_94 ( V_2 , V_196 ) ;
F_39 ( & V_2 -> V_54 , V_56 ) ;
}
static int F_96 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
if ( ! V_2 -> V_197 )
F_95 ( V_2 , V_53 -> V_94 -> V_105 ) ;
return F_76 ( V_53 ) ;
}
static int F_97 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
struct V_154 * V_94 = V_53 -> V_94 ;
V_94 -> V_21 = ( void * ) & V_198 ;
V_2 -> V_82 = V_53 ;
if ( V_2 -> V_197 ) {
V_94 -> V_155 = V_172 ;
F_79 ( V_2 , V_53 ) ;
} else
V_94 -> V_155 = V_199 ;
F_83 ( V_53 ) ;
F_84 ( V_94 , 0 , 32 , 24 ) ;
F_85 ( V_94 , 0 , V_167 ,
V_168 ) ;
F_85 ( V_94 , 0 , V_169 ,
V_168 ) ;
F_81 ( V_53 ) ;
if ( V_2 -> V_130 . V_128 . V_200 )
V_2 -> V_130 . V_128 . V_200 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_98 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
if ( V_173 )
F_61 ( V_2 , V_2 -> V_174 , 0 ) ;
V_2 -> V_82 = NULL ;
if ( V_2 -> V_130 . V_128 . V_201 )
V_2 -> V_130 . V_128 . V_201 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_99 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
struct V_154 * V_94 = V_53 -> V_94 ;
V_94 -> V_21 = ( void * ) & V_202 ;
V_2 -> V_84 = V_53 ;
if ( V_2 -> V_203 ) {
V_94 -> V_155 = V_172 ;
F_79 ( V_2 , V_53 ) ;
} else
V_94 -> V_155 = V_199 ;
F_83 ( V_53 ) ;
F_84 ( V_94 , 0 , 32 , 24 ) ;
F_85 ( V_94 , 0 , V_167 ,
V_168 ) ;
F_85 ( V_94 , 0 , V_169 ,
V_168 ) ;
F_81 ( V_53 ) ;
if ( V_2 -> V_130 . V_128 . V_200 )
V_2 -> V_130 . V_128 . V_200 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_100 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
if ( V_173 )
F_61 ( V_2 , V_2 -> V_174 , 0 ) ;
V_2 -> V_84 = NULL ;
if ( V_2 -> V_130 . V_128 . V_201 )
V_2 -> V_130 . V_128 . V_201 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , int V_175 )
{
char * V_187 ;
struct V_176 * V_177 ;
int V_204 , V_178 ;
int V_135 ;
if ( V_2 -> V_197 ||
( V_2 -> V_107 . V_26 [ V_205 ] & V_206 ) ) {
V_204 = 1 ;
V_2 -> V_207 = 1 ;
} else
V_204 = 0 ;
if ( V_2 -> V_203 ||
( V_2 -> V_107 . V_26 [ V_205 ] & V_208 ) ) {
V_178 = 1 ;
V_2 -> V_207 = 1 ;
} else
V_178 = 0 ;
if ( ! V_204 && ! V_178 )
return 0 ;
if ( V_2 -> V_197 || V_2 -> V_203 )
V_187 = L_7 ;
else
V_187 = L_8 ;
V_135 = F_90 ( V_2 -> V_13 , V_187 , V_175 , V_204 , V_178 , & V_177 ) ;
if ( V_135 < 0 )
return V_135 ;
if ( V_204 )
F_91 ( V_177 , V_182 ,
& V_209 ) ;
if ( V_178 )
F_91 ( V_177 , V_184 ,
& V_210 ) ;
V_177 -> V_21 = V_2 ;
V_177 -> V_186 = 0 ;
strcpy ( V_177 -> V_187 , V_187 ) ;
F_92 ( V_177 , V_188 ,
F_93 ( V_2 -> V_189 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_177 = V_177 ;
return 0 ;
}
static int F_102 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
unsigned char V_20 ;
F_33 ( & V_2 -> V_54 ) ;
V_20 = 3 - V_53 -> V_211 ;
if ( F_2 ( F_3 ( V_2 , V_140 ) ) < V_20 )
F_9 ( V_20 , F_3 ( V_2 , V_140 ) ) ;
F_34 ( & V_2 -> V_54 ) ;
return F_76 ( V_53 ) ;
}
static int F_103 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
struct V_154 * V_94 = V_53 -> V_94 ;
F_64 ( & V_2 -> V_136 ) ;
if ( V_2 -> V_137 [ V_53 -> V_211 ] ) {
F_65 ( & V_2 -> V_136 ) ;
return - V_119 ;
}
F_65 ( & V_2 -> V_136 ) ;
V_94 -> V_21 = ( void * ) & V_212 [ V_53 -> V_211 ] ;
V_2 -> V_78 [ V_53 -> V_211 ] = V_53 ;
V_94 -> V_155 = V_172 ;
F_83 ( V_53 ) ;
F_84 ( V_94 , 0 , 32 , 24 ) ;
F_79 ( V_2 , V_53 ) ;
return 0 ;
}
static int F_104 ( struct V_89 * V_53 )
{
struct V_1 * V_2 = F_54 ( V_53 ) ;
if ( V_173 )
F_61 ( V_2 , V_2 -> V_174 , 0 ) ;
V_2 -> V_78 [ V_53 -> V_211 ] = NULL ;
V_2 -> V_137 [ V_53 -> V_211 ] = NULL ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , int V_175 )
{
struct V_176 * V_177 ;
int V_204 ;
int V_135 ;
V_204 = V_2 -> V_164 / 2 - 1 ;
if ( V_204 <= 0 )
return 0 ;
V_135 = F_90 ( V_2 -> V_13 , L_9 , V_175 , V_204 , 0 , & V_177 ) ;
if ( V_135 < 0 )
return V_135 ;
F_91 ( V_177 , V_182 ,
& V_213 ) ;
V_177 -> V_21 = V_2 ;
V_177 -> V_186 = 0 ;
strcpy ( V_177 -> V_187 , L_10 ) ;
F_92 ( V_177 , V_188 ,
F_93 ( V_2 -> V_189 ) ,
256 * 1024 , 256 * 1024 ) ;
V_2 -> V_214 = V_177 ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_135 ;
if ( ! ( V_2 -> V_107 . V_26 [ V_108 ] & V_109 ) ) {
struct V_215 * V_216 ;
struct V_217 V_18 ;
static struct V_218 V_128 = {
. V_219 = F_8 ,
. V_220 = F_11 ,
} ;
F_9 ( F_2 ( F_3 ( V_2 , V_9 ) ) | 0x80 , F_3 ( V_2 , V_9 ) ) ;
F_107 ( 5 ) ;
F_9 ( F_2 ( F_3 ( V_2 , V_9 ) ) & ~ 0x80 , F_3 ( V_2 , V_9 ) ) ;
V_135 = V_215 ( V_2 -> V_13 , 0 , & V_128 , NULL , & V_216 ) ;
if ( V_135 < 0 )
return V_135 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_21 = V_2 ;
V_135 = F_108 ( V_216 , & V_18 , & V_2 -> V_18 ) ;
if ( V_135 < 0 )
F_109 ( V_2 -> V_13 -> V_14 ,
L_11 ) ;
else
return 0 ;
}
strcat ( V_2 -> V_13 -> V_221 , L_12 ) ;
return 0 ;
}
static inline unsigned int F_110 ( struct V_1 * V_2 , int V_222 )
{
return ( unsigned int ) V_2 -> V_107 . V_26 [ V_222 ] | \
( ( unsigned int ) V_2 -> V_107 . V_26 [ V_222 + 1 ] << 8 ) | \
( ( unsigned int ) V_2 -> V_107 . V_26 [ V_222 + 2 ] << 16 ) ;
}
static void F_111 ( struct V_223 * V_224 ,
struct V_225 * V_45 )
{
struct V_1 * V_2 = V_224 -> V_21 ;
unsigned int V_222 ;
F_112 ( V_45 , L_13 , V_2 -> V_13 -> V_226 ) ;
F_112 ( V_45 , L_14 ) ;
F_112 ( V_45 , L_15 , V_2 -> V_107 . V_227 ) ;
F_112 ( V_45 , L_16 , V_2 -> V_107 . V_138 ) ;
F_112 ( V_45 , L_17 , V_2 -> V_107 . V_228 ) ;
F_112 ( V_45 , L_18 ,
V_2 -> V_107 . V_26 [ V_179 ] ) ;
F_112 ( V_45 , L_19 ,
V_2 -> V_107 . V_26 [ V_108 ] ) ;
F_112 ( V_45 , L_20 ,
V_2 -> V_107 . V_26 [ V_150 ] ) ;
F_112 ( V_45 , L_21 ,
V_2 -> V_107 . V_26 [ V_205 ] ) ;
F_112 ( V_45 , L_22 ,
V_2 -> V_107 . V_229 ) ;
F_112 ( V_45 , L_23 ,
V_2 -> V_107 . V_230 ) ;
F_112 ( V_45 , L_24 ,
V_2 -> V_107 . V_231 ) ;
for ( V_222 = 0x12 ; V_222 < V_2 -> V_107 . V_138 ; V_222 ++ )
F_112 ( V_45 , L_25 ,
V_222 , V_2 -> V_107 . V_26 [ V_222 ] ) ;
F_112 ( V_45 , L_26 ) ;
F_112 ( V_45 , L_27 ,
( unsigned ) F_17 ( F_3 ( V_2 , V_232 ) ) ) ;
for ( V_222 = 0x0 ; V_222 < 0x20 ; V_222 ++ )
F_112 ( V_45 , L_28 ,
V_222 , F_2 ( V_2 -> V_233 + V_222 ) ) ;
for ( V_222 = 0x0 ; V_222 < 0x30 ; V_222 ++ )
F_112 ( V_45 , L_29 ,
V_222 , F_2 ( V_2 -> V_148 + V_222 ) ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_223 * V_224 ;
if ( ! F_114 ( V_2 -> V_13 , L_30 , & V_224 ) )
F_115 ( V_224 , V_2 , F_111 ) ;
}
static int F_116 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
V_237 -> type = V_238 ;
V_237 -> V_34 = sizeof( struct V_239 ) ;
return 0 ;
}
static int F_117 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
memcpy ( V_241 -> V_242 . V_243 . V_26 , & V_2 -> V_107 , sizeof( V_2 -> V_107 ) ) ;
return 0 ;
}
static int F_119 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
V_237 -> type = V_244 ;
V_237 -> V_34 = 1 ;
return 0 ;
}
static unsigned int F_120 ( struct V_245 * V_246 )
{
unsigned int V_20 , V_247 ;
V_20 = V_246 -> V_66 [ 0 ] & 0x03 ;
if ( V_20 & 0x01 ) {
if ( ( V_246 -> V_66 [ 0 ] & V_248 ) ==
V_249 )
V_20 |= 1U << 3 ;
V_247 = ( V_246 -> V_66 [ 4 ] >> 3 ) & 0x0f ;
if ( V_247 ) {
switch ( V_247 ) {
case 2 : V_20 |= 5 << 12 ; break;
case 3 : V_20 |= 6 << 12 ; break;
case 10 : V_20 |= 4 << 12 ; break;
case 11 : V_20 |= 7 << 12 ; break;
}
} else {
switch ( V_246 -> V_66 [ 0 ] & V_250 ) {
case V_251 :
break;
case V_252 :
V_20 |= 3U << 12 ;
break;
default:
V_20 |= 2U << 12 ;
break;
}
}
} else {
V_20 |= V_246 -> V_66 [ 1 ] & 0x04 ;
if ( ( V_246 -> V_66 [ 0 ] & V_253 ) ==
V_254 )
V_20 |= 1U << 3 ;
V_20 |= ( unsigned int ) ( V_246 -> V_66 [ 1 ] & 0x3f ) << 4 ;
V_20 |= ( unsigned int ) ( V_246 -> V_66 [ 3 ] & V_255 ) << 12 ;
}
return V_20 ;
}
static void F_121 ( struct V_245 * V_246 , unsigned int V_20 )
{
memset ( V_246 -> V_66 , 0 , sizeof( V_246 -> V_66 ) ) ;
V_246 -> V_66 [ 0 ] = V_20 & 0x03 ;
if ( V_20 & 0x01 ) {
if ( V_20 & ( 1U << 3 ) )
V_246 -> V_66 [ 0 ] |= V_249 ;
switch ( ( V_20 >> 12 ) & 0x7 ) {
case 0 :
break;
case 2 :
V_246 -> V_66 [ 0 ] |= V_252 ;
break;
default:
V_246 -> V_66 [ 0 ] |= V_256 ;
break;
}
} else {
V_246 -> V_66 [ 0 ] |= V_20 & ( 1U << 2 ) ;
if ( V_20 & ( 1U << 3 ) )
V_246 -> V_66 [ 0 ] |= V_254 ;
V_246 -> V_66 [ 1 ] |= ( V_20 >> 4 ) & 0x3f ;
V_246 -> V_66 [ 3 ] |= ( V_20 >> 12 ) & 0x07 ;
}
}
static int F_122 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
unsigned int V_20 ;
V_20 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
F_121 ( & V_241 -> V_242 . V_257 , V_20 ) ;
return 0 ;
}
static int F_123 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
unsigned int V_20 , V_92 ;
V_20 = F_120 ( & V_241 -> V_242 . V_257 ) ;
F_33 ( & V_2 -> V_54 ) ;
V_92 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
if ( V_20 != V_92 )
F_94 ( V_2 , V_20 ) ;
F_34 ( & V_2 -> V_54 ) ;
return V_20 != V_92 ;
}
static int F_124 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
V_241 -> V_242 . V_257 . V_66 [ 0 ] = V_258 |
V_259 |
V_260 |
V_253 ;
V_241 -> V_242 . V_257 . V_66 [ 1 ] = V_261 |
V_262 ;
V_241 -> V_242 . V_257 . V_66 [ 3 ] = V_255 ;
return 0 ;
}
static int F_125 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
V_241 -> V_242 . V_257 . V_66 [ 0 ] = V_258 |
V_259 |
V_250 |
V_248 ;
return 0 ;
}
static int F_126 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
V_241 -> V_242 . integer . V_242 [ 0 ] = F_2 ( F_15 ( V_2 , V_193 ) ) &
V_194 ? 1 : 0 ;
return 0 ;
}
static int F_127 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
unsigned char V_92 , V_20 ;
F_33 ( & V_2 -> V_54 ) ;
V_92 = V_20 = F_2 ( F_15 ( V_2 , V_193 ) ) ;
V_20 &= ~ V_194 ;
if ( V_241 -> V_242 . integer . V_242 [ 0 ] )
V_20 |= V_194 ;
if ( V_92 != V_20 )
F_9 ( V_20 , F_15 ( V_2 , V_193 ) ) ;
F_34 ( & V_2 -> V_54 ) ;
return V_92 != V_20 ;
}
static int F_128 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_263 = V_2 -> V_115 -> V_34 ;
V_237 -> type = V_264 ;
V_237 -> V_34 = 1 ;
V_237 -> V_242 . V_265 . V_266 = V_263 ;
if ( V_2 -> V_203 ||
( V_2 -> V_107 . V_26 [ V_205 ] & V_208 ) )
V_237 -> V_242 . V_265 . V_266 += V_2 -> V_267 ;
if ( V_237 -> V_242 . V_265 . V_268 >= V_237 -> V_242 . V_265 . V_266 )
V_237 -> V_242 . V_265 . V_268 = V_237 -> V_242 . V_265 . V_266 - 1 ;
if ( V_237 -> V_242 . V_265 . V_268 >= V_263 )
strcpy ( V_237 -> V_242 . V_265 . V_187 ,
V_2 -> V_269 [
V_237 -> V_242 . V_265 . V_268 - V_263 ] ) ;
else
sprintf ( V_237 -> V_242 . V_265 . V_187 , L_31 ,
V_2 -> V_115 -> V_42 [ V_237 -> V_242 . V_265 . V_268 ] ) ;
return 0 ;
}
static int F_129 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
unsigned int V_44 , V_105 ;
F_33 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_5 ( V_2 ) ) {
V_241 -> V_242 . V_265 . V_268 [ 0 ] = V_2 -> V_115 -> V_34 +
V_2 -> V_270 ( V_2 ) ;
} else {
V_105 = V_2 -> V_120 ( V_2 ) ;
V_241 -> V_242 . V_265 . V_268 [ 0 ] = 0 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_115 -> V_34 ; V_44 ++ ) {
if ( V_2 -> V_115 -> V_42 [ V_44 ] == V_105 ) {
V_241 -> V_242 . V_265 . V_268 [ 0 ] = V_44 ;
break;
}
}
}
F_34 ( & V_2 -> V_54 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , int type )
{
unsigned char V_271 ;
unsigned char V_272 ;
V_271 = F_2 ( F_3 ( V_2 , V_3 ) ) ;
F_9 ( V_271 | V_4 , F_3 ( V_2 , V_3 ) ) ;
V_272 = F_2 ( F_3 ( V_2 , V_110 ) ) ;
F_9 ( V_272 & ~ V_111 , F_3 ( V_2 , V_110 ) ) ;
return 0 ;
}
static int F_132 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
unsigned int V_114 , V_273 ;
unsigned int V_268 = V_241 -> V_242 . V_265 . V_268 [ 0 ] ;
unsigned int V_274 = V_2 -> V_115 -> V_34 ;
if ( V_268 > V_274 + V_2 -> V_267 - 1 )
return - V_104 ;
F_33 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_5 ( V_2 ) )
V_114 = 0 ;
else
V_114 = V_2 -> V_120 ( V_2 ) ;
if ( V_268 >= V_274 ) {
V_2 -> V_275 ( V_2 , V_268 - V_274 ) ;
V_273 = 0 ;
} else {
V_273 = V_2 -> V_115 -> V_42 [ V_268 ] ;
V_2 -> V_174 = V_273 ;
F_34 ( & V_2 -> V_54 ) ;
F_61 ( V_2 , V_2 -> V_174 , 1 ) ;
F_33 ( & V_2 -> V_54 ) ;
}
F_34 ( & V_2 -> V_54 ) ;
if ( V_114 != V_273 && ! V_273 ) {
unsigned int V_44 ;
if ( V_2 -> V_123 . V_125 )
V_2 -> V_123 . V_125 ( V_2 , 0 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_126 ; V_44 ++ ) {
if ( V_2 -> V_127 [ V_44 ] . V_128 . V_129 )
V_2 -> V_127 [ V_44 ] . V_128 . V_129 ( & V_2 -> V_127 [ V_44 ] , 0 ) ;
}
}
return V_114 != V_273 ;
}
static int F_133 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
V_241 -> V_242 . integer . V_242 [ 0 ] = V_6 ;
return 0 ;
}
static int F_134 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_276 = 0 , V_196 ;
V_196 = V_241 -> V_242 . integer . V_242 [ 0 ] ? 1 : 0 ;
F_33 ( & V_2 -> V_54 ) ;
V_276 = V_6 != V_196 ;
V_6 = V_196 ;
F_34 ( & V_2 -> V_54 ) ;
return V_276 ;
}
static int F_135 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
V_241 -> V_242 . integer . V_242 [ 0 ] = V_173 ? 1 : 0 ;
return 0 ;
}
static int F_136 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_276 = 0 , V_196 ;
V_196 = V_241 -> V_242 . integer . V_242 [ 0 ] ? 1 : 0 ;
F_33 ( & V_2 -> V_54 ) ;
V_276 = V_173 != V_196 ;
V_173 = V_196 ;
F_34 ( & V_2 -> V_54 ) ;
return V_276 ;
}
static int F_137 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
static const char * const V_277 [] = {
L_32 ,
L_33 , L_34 ,
L_35 , L_36 ,
} ;
return F_138 ( V_237 , 1 , 5 , V_277 ) ;
}
static inline int F_139 ( int V_222 )
{
return ( V_222 % 2 ) * 12 + ( ( V_222 / 2 ) * 3 ) + 8 ;
}
static inline int F_140 ( int V_222 )
{
return V_222 * 3 ;
}
int F_141 ( struct V_1 * V_2 , int V_278 )
{
unsigned long V_20 ;
unsigned char V_279 ;
static const unsigned char V_280 [ 8 ] = {
0 , 255 , 1 , 2 , 255 , 255 , 3 , 4 ,
} ;
V_20 = F_17 ( F_3 ( V_2 , V_232 ) ) ;
V_20 >>= V_278 ;
V_20 &= 7 ;
V_279 = V_280 [ V_20 ] ;
if ( V_279 == 255 ) {
F_142 () ;
return 0 ;
}
return V_279 ;
}
int F_143 ( struct V_1 * V_2 , unsigned int V_20 ,
int V_278 )
{
unsigned int V_281 , V_196 ;
int V_276 ;
static const unsigned char V_282 [ 8 ] = {
0 ,
2 ,
3 ,
6 ,
7 ,
} ;
V_196 = V_282 [ V_20 % 5 ] ;
V_20 = V_281 = F_17 ( F_3 ( V_2 , V_232 ) ) ;
V_20 &= ~ ( 0x07 << V_278 ) ;
V_20 |= V_196 << V_278 ;
V_276 = V_20 != V_281 ;
if ( V_276 )
F_14 ( V_20 , F_3 ( V_2 , V_232 ) ) ;
return V_276 ;
}
static int F_144 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_222 = F_145 ( V_235 , & V_241 -> V_283 ) ;
V_241 -> V_242 . V_265 . V_268 [ 0 ] =
F_141 ( V_2 , F_139 ( V_222 ) ) ;
return 0 ;
}
static int F_146 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_222 = F_145 ( V_235 , & V_241 -> V_283 ) ;
return F_143 ( V_2 ,
V_241 -> V_242 . V_265 . V_268 [ 0 ] ,
F_139 ( V_222 ) ) ;
}
static int F_147 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_222 = F_145 ( V_235 , & V_241 -> V_283 ) ;
V_241 -> V_242 . V_265 . V_268 [ 0 ] =
F_141 ( V_2 , F_140 ( V_222 ) ) ;
return 0 ;
}
static int F_148 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_222 = F_145 ( V_235 , & V_241 -> V_283 ) ;
return F_143 ( V_2 ,
V_241 -> V_242 . V_265 . V_268 [ 0 ] ,
F_140 ( V_222 ) ) ;
}
static int F_149 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
V_237 -> type = V_284 ;
V_237 -> V_34 = 22 ;
V_237 -> V_242 . integer . F_30 = 0 ;
V_237 -> V_242 . integer . V_285 = 255 ;
return 0 ;
}
static int F_150 ( struct V_234 * V_235 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = F_118 ( V_235 ) ;
int V_222 ;
F_33 ( & V_2 -> V_54 ) ;
for ( V_222 = 0 ; V_222 < 22 ; V_222 ++ ) {
F_9 ( V_222 , F_3 ( V_2 , V_286 ) ) ;
V_241 -> V_242 . integer . V_242 [ V_222 ] =
F_2 ( F_3 ( V_2 , V_287 ) ) ;
}
F_34 ( & V_2 -> V_54 ) ;
return 0 ;
}
static void F_151 ( struct V_1 * V_2 )
{
int V_288 = 0x10000 ;
while ( ( F_2 ( F_15 ( V_2 , V_289 ) ) & V_290 ) && V_288 -- )
;
if ( V_288 == - 1 )
F_49 ( V_2 -> V_13 -> V_14 , L_37 ) ;
}
unsigned char F_152 ( struct V_1 * V_2 ,
unsigned char V_14 , unsigned char V_149 )
{
unsigned char V_20 ;
F_64 ( & V_2 -> V_291 ) ;
F_151 ( V_2 ) ;
F_9 ( V_149 , F_15 ( V_2 , V_292 ) ) ;
F_9 ( V_14 & ~ V_293 , F_15 ( V_2 , V_294 ) ) ;
F_151 ( V_2 ) ;
V_20 = F_2 ( F_15 ( V_2 , V_295 ) ) ;
F_65 ( & V_2 -> V_291 ) ;
return V_20 ;
}
void F_153 ( struct V_1 * V_2 ,
unsigned char V_14 , unsigned char V_149 , unsigned char V_26 )
{
F_64 ( & V_2 -> V_291 ) ;
F_151 ( V_2 ) ;
F_9 ( V_149 , F_15 ( V_2 , V_292 ) ) ;
F_9 ( V_26 , F_15 ( V_2 , V_295 ) ) ;
F_9 ( V_14 | V_293 , F_15 ( V_2 , V_294 ) ) ;
F_151 ( V_2 ) ;
F_65 ( & V_2 -> V_291 ) ;
}
static int F_154 ( struct V_1 * V_2 ,
const char * V_296 )
{
const int V_14 = 0xa0 ;
unsigned int V_44 , V_138 ;
struct V_297 * const * V_298 , * V_299 ;
if ( ! V_296 || ! * V_296 ) {
V_2 -> V_107 . V_227 = 0 ;
if ( ( F_2 ( F_15 ( V_2 , V_289 ) ) & V_300 ) != 0 )
V_2 -> V_107 . V_227 =
( F_152 ( V_2 , V_14 , 0x00 ) << 0 ) |
( F_152 ( V_2 , V_14 , 0x01 ) << 8 ) |
( F_152 ( V_2 , V_14 , 0x02 ) << 16 ) |
( F_152 ( V_2 , V_14 , 0x03 ) << 24 ) ;
if ( V_2 -> V_107 . V_227 == 0 ||
V_2 -> V_107 . V_227 == ( unsigned int ) - 1 ) {
T_5 V_301 , V_175 ;
F_155 ( V_2 -> V_189 , V_302 ,
& V_301 ) ;
F_155 ( V_2 -> V_189 , V_303 , & V_175 ) ;
V_2 -> V_107 . V_227 =
( ( unsigned int ) F_156 ( V_301 ) << 16 ) | F_156 ( V_175 ) ;
if ( V_2 -> V_107 . V_227 == 0 ||
V_2 -> V_107 . V_227 == ( unsigned int ) - 1 ) {
F_49 ( V_2 -> V_13 -> V_14 ,
L_38 ) ;
return - V_304 ;
}
}
}
for ( V_298 = V_305 ; * V_298 ; V_298 ++ ) {
for ( V_299 = * V_298 ; V_299 -> V_187 ; V_299 ++ ) {
if ( V_296 && V_299 -> V_306 &&
! strcmp ( V_296 , V_299 -> V_306 ) ) {
F_157 ( V_2 -> V_13 -> V_14 ,
L_39 ,
V_299 -> V_187 ) ;
V_2 -> V_107 . V_227 = V_299 -> V_227 ;
} else if ( V_299 -> V_227 != V_2 -> V_107 . V_227 )
continue;
V_2 -> V_307 = V_299 ;
if ( ! V_299 -> V_308 || ! V_299 -> V_309 )
goto V_310;
F_6 ( V_2 -> V_13 -> V_14 , L_40 ) ;
V_2 -> V_107 . V_228 = 2 ;
V_2 -> V_107 . V_138 = V_299 -> V_308 + 6 ;
memcpy ( V_2 -> V_107 . V_26 , V_299 -> V_309 , V_299 -> V_308 ) ;
goto V_311;
}
}
F_109 ( V_2 -> V_13 -> V_14 , L_41 ,
V_2 -> V_107 . V_227 ) ;
#ifdef F_158
V_2 -> V_312 = 1 ;
#endif
V_310:
V_2 -> V_107 . V_138 = F_152 ( V_2 , V_14 , 0x04 ) ;
if ( V_2 -> V_107 . V_138 < 6 )
V_2 -> V_107 . V_138 = 32 ;
else if ( V_2 -> V_107 . V_138 > 32 ) {
F_49 ( V_2 -> V_13 -> V_14 , L_42 ,
V_2 -> V_107 . V_138 ) ;
return - V_16 ;
}
V_2 -> V_107 . V_228 = F_152 ( V_2 , V_14 , 0x05 ) ;
if ( V_2 -> V_107 . V_228 != 1 && V_2 -> V_107 . V_228 != 2 )
F_109 ( V_2 -> V_13 -> V_14 , L_43 ,
V_2 -> V_107 . V_228 ) ;
V_138 = V_2 -> V_107 . V_138 - 6 ;
for ( V_44 = 0 ; V_44 < V_138 ; V_44 ++ )
V_2 -> V_107 . V_26 [ V_44 ] = F_152 ( V_2 , V_14 , V_44 + 6 ) ;
V_311:
V_2 -> V_107 . V_230 = F_110 ( V_2 , V_313 ) ;
V_2 -> V_107 . V_231 = F_110 ( V_2 , V_314 ) ;
V_2 -> V_107 . V_229 = F_110 ( V_2 , V_315 ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_9 ( V_316 , F_15 ( V_2 , V_317 ) ) ;
F_2 ( F_15 ( V_2 , V_317 ) ) ;
F_160 ( 10 ) ;
F_9 ( 0 , F_15 ( V_2 , V_317 ) ) ;
F_2 ( F_15 ( V_2 , V_317 ) ) ;
F_160 ( 10 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_107 . V_26 [ V_179 ] , F_15 ( V_2 , V_318 ) ) ;
F_9 ( V_2 -> V_107 . V_26 [ V_108 ] , F_15 ( V_2 , V_319 ) ) ;
F_9 ( V_2 -> V_107 . V_26 [ V_150 ] , F_15 ( V_2 , V_320 ) ) ;
F_9 ( V_2 -> V_107 . V_26 [ V_205 ] , F_15 ( V_2 , V_193 ) ) ;
V_2 -> V_123 . V_321 = V_2 -> V_107 . V_230 ;
V_2 -> V_123 . V_322 = V_2 -> V_107 . V_229 ;
F_18 ( V_2 , V_2 -> V_107 . V_230 ) ;
F_13 ( V_2 , V_2 -> V_107 . V_229 ) ;
F_20 ( V_2 , V_2 -> V_107 . V_231 ) ;
F_9 ( 0 , F_15 ( V_2 , V_323 ) ) ;
F_9 ( V_62 | V_48 , F_15 ( V_2 , V_52 ) ) ;
F_9 ( V_85 , F_3 ( V_2 , V_88 ) ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 )
{
int V_135 ;
struct V_234 * V_324 ;
if ( F_163 ( ! V_2 -> V_177 ) )
return - V_16 ;
if ( ! V_2 -> V_325 ) {
V_135 = F_164 ( V_2 -> V_13 ,
F_165 ( & V_326 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
}
V_135 = F_164 ( V_2 -> V_13 , F_165 ( & V_327 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_135 = F_164 ( V_2 -> V_13 , V_324 = F_165 ( & V_328 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_324 -> V_283 . V_175 = V_2 -> V_177 -> V_175 ;
V_135 = F_164 ( V_2 -> V_13 , V_324 = F_165 ( & V_329 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_324 -> V_283 . V_175 = V_2 -> V_177 -> V_175 ;
V_135 = F_164 ( V_2 -> V_13 , V_324 = F_165 ( & V_330 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_324 -> V_283 . V_175 = V_2 -> V_177 -> V_175 ;
#if 0
err = snd_ctl_add(ice->card, kctl = snd_ctl_new1(&snd_vt1724_spdif_stream, ice));
if (err < 0)
return err;
kctl->id.device = ice->pcm->device;
ice->spdif.stream_ctl = kctl;
#endif
return 0 ;
}
static int F_166 ( struct V_1 * V_2 )
{
int V_135 ;
V_135 = F_164 ( V_2 -> V_13 , F_165 ( & V_331 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_135 = F_164 ( V_2 -> V_13 , F_165 ( & V_332 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_135 = F_164 ( V_2 -> V_13 , F_165 ( & V_333 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
V_135 = F_164 ( V_2 -> V_13 , F_165 ( & V_334 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
if ( ! V_2 -> V_325 && V_2 -> V_164 > 0 ) {
struct V_335 V_336 = V_337 ;
V_336 . V_34 = V_2 -> V_164 ;
if ( V_2 -> V_29 && V_336 . V_34 > 2 )
V_336 . V_34 = 2 ;
V_135 = F_164 ( V_2 -> V_13 , F_165 ( & V_336 , V_2 ) ) ;
if ( V_135 < 0 )
return V_135 ;
}
return F_164 ( V_2 -> V_13 ,
F_165 ( & V_338 , V_2 ) ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_233 )
goto V_339;
F_9 ( 0xff , F_3 ( V_2 , V_88 ) ) ;
F_9 ( 0xff , F_15 ( V_2 , V_52 ) ) ;
V_339:
if ( V_2 -> V_64 >= 0 )
F_168 ( V_2 -> V_64 , V_2 ) ;
F_169 ( V_2 -> V_189 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 -> V_189 ) ;
F_172 ( V_2 -> V_340 ) ;
F_172 ( V_2 ) ;
return 0 ;
}
static int F_173 ( struct V_341 * V_175 )
{
struct V_1 * V_2 = V_175 -> V_342 ;
return F_167 ( V_2 ) ;
}
static int F_174 ( struct V_343 * V_13 ,
struct V_344 * V_189 ,
const char * V_296 ,
struct V_1 * * V_345 )
{
struct V_1 * V_2 ;
int V_135 ;
static struct V_346 V_128 = {
. V_347 = F_173 ,
} ;
* V_345 = NULL ;
V_135 = F_175 ( V_189 ) ;
if ( V_135 < 0 )
return V_135 ;
V_2 = F_176 ( sizeof( * V_2 ) , V_348 ) ;
if ( V_2 == NULL ) {
F_171 ( V_189 ) ;
return - V_349 ;
}
V_2 -> V_350 = 1 ;
F_177 ( & V_2 -> V_54 ) ;
F_178 ( & V_2 -> V_351 ) ;
F_178 ( & V_2 -> V_136 ) ;
F_178 ( & V_2 -> V_291 ) ;
V_2 -> V_123 . V_352 = F_18 ;
V_2 -> V_123 . V_353 = F_19 ;
V_2 -> V_123 . V_354 = F_13 ;
V_2 -> V_123 . V_355 = F_16 ;
V_2 -> V_123 . V_356 = F_20 ;
V_2 -> V_123 . V_357 = F_21 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_189 = V_189 ;
V_2 -> V_64 = - 1 ;
F_179 ( V_189 ) ;
F_113 ( V_2 ) ;
F_180 ( V_189 -> V_64 ) ;
V_13 -> V_21 = V_2 ;
V_135 = F_181 ( V_189 , L_6 ) ;
if ( V_135 < 0 ) {
F_172 ( V_2 ) ;
F_171 ( V_189 ) ;
return V_135 ;
}
V_2 -> V_233 = F_182 ( V_189 , 0 ) ;
V_2 -> V_148 = F_182 ( V_189 , 1 ) ;
if ( F_183 ( V_189 -> V_64 , F_47 ,
V_358 , V_359 , V_2 ) ) {
F_49 ( V_13 -> V_14 , L_44 , V_189 -> V_64 ) ;
F_167 ( V_2 ) ;
return - V_16 ;
}
V_2 -> V_64 = V_189 -> V_64 ;
F_159 ( V_2 ) ;
if ( F_154 ( V_2 , V_296 ) < 0 ) {
F_167 ( V_2 ) ;
return - V_16 ;
}
if ( F_161 ( V_2 ) < 0 ) {
F_167 ( V_2 ) ;
return - V_16 ;
}
V_135 = F_184 ( V_13 , V_360 , V_2 , & V_128 ) ;
if ( V_135 < 0 ) {
F_167 ( V_2 ) ;
return V_135 ;
}
* V_345 = V_2 ;
return 0 ;
}
static int F_185 ( struct V_344 * V_189 ,
const struct V_361 * V_362 )
{
static int V_14 ;
struct V_343 * V_13 ;
struct V_1 * V_2 ;
int V_363 = 0 , V_135 ;
struct V_297 * const * V_298 , * V_299 ;
if ( V_14 >= V_364 )
return - V_365 ;
if ( ! V_51 [ V_14 ] ) {
V_14 ++ ;
return - V_366 ;
}
V_135 = F_186 ( & V_189 -> V_14 , V_367 [ V_14 ] , V_283 [ V_14 ] , V_368 ,
0 , & V_13 ) ;
if ( V_135 < 0 )
return V_135 ;
strcpy ( V_13 -> V_369 , L_6 ) ;
strcpy ( V_13 -> V_370 , L_45 ) ;
V_135 = F_174 ( V_13 , V_189 , V_306 [ V_14 ] , & V_2 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
V_2 -> V_267 = 0 ;
for ( V_298 = V_305 ; * V_298 ; V_298 ++ ) {
for ( V_299 = * V_298 ; V_299 -> V_187 ; V_299 ++ ) {
if ( ( V_306 [ V_14 ] && V_299 -> V_306 &&
! strcmp ( V_306 [ V_14 ] , V_299 -> V_306 ) ) ||
( V_299 -> V_227 == V_2 -> V_107 . V_227 ) ) {
strcpy ( V_13 -> V_370 , V_299 -> V_187 ) ;
if ( V_299 -> V_369 )
strcpy ( V_13 -> V_369 , V_299 -> V_369 ) ;
if ( V_299 -> V_371 ) {
V_135 = V_299 -> V_371 ( V_2 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
}
goto V_372;
}
}
}
V_299 = & V_373 ;
V_372:
V_2 -> V_174 = V_374 ;
if ( ! V_2 -> V_5 )
V_2 -> V_5 = F_1 ;
if ( ! V_2 -> V_120 )
V_2 -> V_120 = F_57 ;
if ( ! V_2 -> V_121 )
V_2 -> V_121 = F_58 ;
if ( ! V_2 -> V_122 )
V_2 -> V_122 = F_60 ;
if ( ! V_2 -> V_275 )
V_2 -> V_275 = F_131 ;
if ( ! V_2 -> V_270 )
V_2 -> V_270 = F_130 ;
if ( ! V_2 -> V_269 )
V_2 -> V_269 = V_269 ;
if ( ! V_2 -> V_267 )
V_2 -> V_267 = F_59 ( V_269 ) ;
if ( ! V_2 -> V_115 )
F_78 ( V_2 ) ;
V_135 = F_89 ( V_2 , V_363 ++ ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
V_135 = F_101 ( V_2 , V_363 ++ ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
V_135 = F_105 ( V_2 , V_363 ++ ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
V_135 = F_106 ( V_2 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
V_135 = F_166 ( V_2 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
if ( V_2 -> V_177 && V_2 -> V_207 ) {
V_135 = F_162 ( V_2 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
}
if ( V_299 -> V_375 ) {
V_135 = V_299 -> V_375 ( V_2 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
}
if ( ! V_299 -> V_376 ) {
if ( V_2 -> V_107 . V_26 [ V_179 ] & V_377 ) {
struct V_378 * V_39 ;
V_135 = F_188 ( V_13 , L_46 , 0 , 1 , 1 , & V_39 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
V_2 -> V_39 [ 0 ] = V_39 ;
V_39 -> V_21 = V_2 ;
strcpy ( V_39 -> V_187 , L_47 ) ;
V_39 -> V_186 = V_379 |
V_380 |
V_381 ;
F_189 ( V_39 , V_46 ,
& V_382 ) ;
F_189 ( V_39 , V_49 ,
& V_383 ) ;
F_9 ( V_384 | 0x1 ,
F_15 ( V_2 , V_385 ) ) ;
F_9 ( 0x1 , F_15 ( V_2 , V_385 ) ) ;
F_9 ( V_386 , F_15 ( V_2 , V_60 ) ) ;
}
}
sprintf ( V_13 -> V_226 , L_48 ,
V_13 -> V_370 , V_2 -> V_233 , V_2 -> V_64 ) ;
V_135 = F_190 ( V_13 ) ;
if ( V_135 < 0 ) {
F_187 ( V_13 ) ;
return V_135 ;
}
F_191 ( V_189 , V_13 ) ;
V_14 ++ ;
return 0 ;
}
static void F_192 ( struct V_344 * V_189 )
{
struct V_343 * V_13 = F_193 ( V_189 ) ;
struct V_1 * V_2 = V_13 -> V_21 ;
if ( V_2 -> V_307 && V_2 -> V_307 -> V_387 )
V_2 -> V_307 -> V_387 ( V_2 ) ;
F_187 ( V_13 ) ;
}
static int F_194 ( struct V_175 * V_14 )
{
struct V_344 * V_189 = F_195 ( V_14 ) ;
struct V_343 * V_13 = F_196 ( V_14 ) ;
struct V_1 * V_2 = V_13 -> V_21 ;
if ( ! V_2 -> V_312 )
return 0 ;
F_197 ( V_13 , V_388 ) ;
F_198 ( V_2 -> V_177 ) ;
F_198 ( V_2 -> V_190 ) ;
F_198 ( V_2 -> V_214 ) ;
F_199 ( V_2 -> V_18 ) ;
F_33 ( & V_2 -> V_54 ) ;
V_2 -> V_389 = V_2 -> V_5 ( V_2 ) ;
V_2 -> V_390 = F_12 ( F_3 ( V_2 , V_195 ) ) ;
V_2 -> V_391 = F_2 ( F_15 ( V_2 , V_193 ) ) ;
V_2 -> V_392 = F_17 ( F_3 ( V_2 , V_232 ) ) ;
F_34 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_393 )
V_2 -> V_393 ( V_2 ) ;
F_171 ( V_189 ) ;
F_200 ( V_189 ) ;
F_201 ( V_189 , V_394 ) ;
return 0 ;
}
static int F_202 ( struct V_175 * V_14 )
{
struct V_344 * V_189 = F_195 ( V_14 ) ;
struct V_343 * V_13 = F_196 ( V_14 ) ;
struct V_1 * V_2 = V_13 -> V_21 ;
if ( ! V_2 -> V_312 )
return 0 ;
F_201 ( V_189 , V_395 ) ;
F_203 ( V_189 ) ;
if ( F_175 ( V_189 ) < 0 ) {
F_204 ( V_13 ) ;
return - V_16 ;
}
F_179 ( V_189 ) ;
F_159 ( V_2 ) ;
if ( F_161 ( V_2 ) < 0 ) {
F_204 ( V_13 ) ;
return - V_16 ;
}
if ( V_2 -> V_396 )
V_2 -> V_396 ( V_2 ) ;
if ( V_2 -> V_389 ) {
V_2 -> V_275 ( V_2 , 0 ) ;
} else {
int V_105 ;
if ( V_2 -> V_118 )
V_105 = V_2 -> V_118 ;
else
V_105 = V_2 -> V_174 ;
F_61 ( V_2 , V_105 , 1 ) ;
}
F_94 ( V_2 , V_2 -> V_390 ) ;
F_9 ( V_2 -> V_391 , F_15 ( V_2 , V_193 ) ) ;
F_14 ( V_2 -> V_392 , F_3 ( V_2 , V_232 ) ) ;
F_205 ( V_2 -> V_18 ) ;
F_197 ( V_13 , V_397 ) ;
return 0 ;
}
