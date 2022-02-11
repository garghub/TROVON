static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
V_4 -- ;
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_7 ) ;
F_3 ( 0x18 , V_2 -> V_5 + V_8 ) ;
#if 0
dev_dbg(sonic->card->dev, "program dmaa: addr = 0x%x, paddr = 0x%x\n",
addr, inl(sonic->dmaa_port + SV_DMA_ADDR0));
#endif
}
static inline void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
V_4 >>= 1 ;
V_4 -- ;
F_2 ( V_3 , V_2 -> V_9 + V_6 ) ;
F_2 ( V_4 , V_2 -> V_9 + V_7 ) ;
F_3 ( 0x14 , V_2 -> V_9 + V_8 ) ;
#if 0
dev_dbg(sonic->card->dev, "program dmac: addr = 0x%x, paddr = 0x%x\n",
addr, inl(sonic->dmac_port + SV_DMA_ADDR0));
#endif
}
static inline unsigned int F_5 ( struct V_1 * V_2 )
{
return ( F_6 ( V_2 -> V_5 + V_7 ) & 0xffffff ) + 1 ;
}
static inline unsigned int F_7 ( struct V_1 * V_2 )
{
return ( ( F_6 ( V_2 -> V_9 + V_7 ) & 0xffffff ) + 1 ) << 1 ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char V_10 ,
unsigned char V_11 )
{
F_3 ( V_10 , F_9 ( V_2 , V_12 ) ) ;
F_10 ( 10 ) ;
F_3 ( V_11 , F_9 ( V_2 , V_13 ) ) ;
F_10 ( 10 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char V_10 ,
unsigned char V_11 )
{
unsigned long V_14 ;
F_12 ( & V_2 -> V_15 , V_14 ) ;
F_3 ( V_10 , F_9 ( V_2 , V_12 ) ) ;
F_10 ( 10 ) ;
F_3 ( V_11 , F_9 ( V_2 , V_13 ) ) ;
F_10 ( 10 ) ;
F_13 ( & V_2 -> V_15 , V_14 ) ;
}
static unsigned char F_14 ( struct V_1 * V_2 , unsigned char V_10 )
{
unsigned char V_11 ;
F_3 ( V_10 , F_9 ( V_2 , V_12 ) ) ;
F_10 ( 10 ) ;
V_11 = F_15 ( F_9 ( V_2 , V_13 ) ) ;
F_10 ( 10 ) ;
return V_11 ;
}
static unsigned char F_16 ( struct V_1 * V_2 , unsigned char V_10 )
{
unsigned long V_14 ;
unsigned char V_11 ;
F_12 ( & V_2 -> V_15 , V_14 ) ;
F_3 ( V_10 , F_9 ( V_2 , V_12 ) ) ;
F_10 ( 10 ) ;
V_11 = F_15 ( F_9 ( V_2 , V_13 ) ) ;
F_10 ( 10 ) ;
F_13 ( & V_2 -> V_15 , V_14 ) ;
return V_11 ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned char V_16 ,
unsigned char V_11 )
{
unsigned long V_14 ;
F_12 ( & V_2 -> V_15 , V_14 ) ;
F_3 ( V_17 | V_18 , F_9 ( V_2 , V_12 ) ) ;
if ( V_16 ) {
V_2 -> V_19 = F_15 ( F_9 ( V_2 , V_13 ) ) ;
F_10 ( 10 ) ;
}
V_2 -> V_19 = ( V_2 -> V_19 & V_16 ) | V_11 ;
F_3 ( V_2 -> V_19 , F_9 ( V_2 , V_13 ) ) ;
F_10 ( 10 ) ;
F_3 ( 0 , F_9 ( V_2 , V_12 ) ) ;
F_10 ( 10 ) ;
F_13 ( & V_2 -> V_15 , V_14 ) ;
}
static void F_18 ( unsigned int V_20 ,
unsigned int * V_21 ,
unsigned int * V_22 ,
unsigned int * V_23 )
{
unsigned int V_24 , V_25 = 0 , V_26 = 0 ;
unsigned int V_27 , V_28 , V_29 , V_30 , V_31 = ~ 0U ;
if ( V_20 < 625000 / V_32 )
V_20 = 625000 / V_32 ;
if ( V_20 > 150000000 / V_32 )
V_20 = 150000000 / V_32 ;
for ( V_24 = 0 ; V_20 < 75000000 / V_32 ; V_24 += 0x20 , V_20 <<= 1 ) ;
for ( V_28 = 3 ; V_28 < 33 ; V_28 ++ )
for ( V_27 = 3 ; V_27 < 257 ; V_27 ++ ) {
V_29 = ( ( V_33 / V_32 ) * V_27 ) / V_28 ;
if ( V_29 >= V_20 )
V_30 = V_29 - V_20 ;
else
V_30 = V_20 - V_29 ;
if ( V_30 < V_31 ) {
V_31 = V_30 ;
V_25 = V_27 - 2 ;
V_26 = V_28 - 2 ;
}
}
* V_21 = V_24 ;
* V_22 = V_25 ;
* V_23 = V_26 ;
#if 0
dev_dbg(sonic->card->dev,
"metric = %i, xm = %i, xn = %i\n", metric, xm, xn);
dev_dbg(sonic->card->dev,
"pll: m = 0x%x, r = 0x%x, n = 0x%x\n", reg, m, r, n);
#endif
}
static void F_19 ( struct V_1 * V_2 ,
unsigned char V_10 ,
unsigned int V_20 )
{
unsigned long V_14 ;
unsigned int V_24 , V_25 , V_26 ;
F_18 ( V_20 , & V_24 , & V_25 , & V_26 ) ;
if ( V_2 != NULL ) {
F_12 ( & V_2 -> V_15 , V_14 ) ;
F_8 ( V_2 , V_10 , V_25 ) ;
F_8 ( V_2 , V_10 + 1 , V_24 | V_26 ) ;
F_13 ( & V_2 -> V_15 , V_14 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_20 )
{
unsigned long V_14 ;
unsigned int div ;
unsigned char clock ;
div = 48000 / V_20 ;
if ( div > 8 )
div = 8 ;
if ( ( 48000 / div ) == V_20 ) {
clock = 0x10 ;
} else {
clock = 0x00 ;
F_19 ( V_2 , V_34 , V_20 ) ;
}
F_12 ( & V_2 -> V_15 , V_14 ) ;
F_8 ( V_2 , V_35 , ( div - 1 ) << 4 ) ;
F_8 ( V_2 , V_36 , clock ) ;
F_13 ( & V_2 -> V_15 , V_14 ) ;
}
static int F_21 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
unsigned int V_20 , div , V_24 , V_25 , V_26 ;
if ( F_22 ( V_38 , V_41 ) -> V_42 ==
F_22 ( V_38 , V_41 ) -> V_43 ) {
V_20 = F_22 ( V_38 , V_41 ) -> V_42 ;
div = 48000 / V_20 ;
if ( div > 8 )
div = 8 ;
if ( ( 48000 / div ) == V_20 ) {
V_38 -> V_44 = V_20 ;
V_38 -> V_45 = 1 ;
} else {
F_18 ( V_20 , & V_24 , & V_25 , & V_26 ) ;
F_23 ( V_33 % 16 ) ;
F_23 ( V_32 % 512 ) ;
V_38 -> V_44 = ( V_33 / 16 ) * ( V_26 + 2 ) * V_24 ;
V_38 -> V_45 = ( V_32 / 512 ) * ( V_25 + 2 ) ;
}
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_20 )
{
unsigned int div ;
unsigned long V_14 ;
div = ( V_20 * 65536 + V_46 / 2 ) / V_46 ;
if ( div > 65535 )
div = 65535 ;
F_12 ( & V_2 -> V_15 , V_14 ) ;
F_8 ( V_2 , V_47 , div >> 8 ) ;
F_8 ( V_2 , V_48 , div ) ;
F_13 ( & V_2 -> V_15 , V_14 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_49 , int V_50 )
{
int V_51 = 0 ;
F_26 ( & V_2 -> V_15 ) ;
if ( V_50 == V_52 ) {
if ( ! ( V_2 -> V_53 & V_49 ) ) {
V_2 -> V_53 |= V_49 ;
F_8 ( V_2 , V_54 , V_2 -> V_53 ) ;
}
} else if ( V_50 == V_55 ) {
if ( V_2 -> V_53 & V_49 ) {
V_2 -> V_53 &= ~ V_49 ;
F_8 ( V_2 , V_54 , V_2 -> V_53 ) ;
}
} else {
V_51 = - V_56 ;
}
F_27 ( & V_2 -> V_15 ) ;
return V_51 ;
}
static T_1 F_28 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
unsigned char V_59 ;
V_59 = F_15 ( F_9 ( V_2 , V_60 ) ) ;
if ( ! ( V_59 & ( V_61 | V_62 | V_63 ) ) )
return V_64 ;
if ( V_59 == 0xff ) {
F_3 ( V_2 -> V_65 = ~ 0 , F_9 ( V_2 , V_66 ) ) ;
F_29 ( V_2 -> V_67 -> V_68 ,
L_1 ) ;
return V_69 ;
}
if ( V_2 -> V_70 ) {
if ( V_59 & V_61 )
F_30 ( V_2 -> V_71 ) ;
if ( V_59 & V_62 )
F_30 ( V_2 -> V_72 ) ;
}
if ( V_2 -> V_73 ) {
if ( V_59 & V_63 )
F_31 ( V_57 , V_2 -> V_73 -> V_74 ) ;
}
if ( V_59 & V_75 ) {
unsigned char V_76 ;
int V_77 , V_78 , V_79 , V_80 , V_81 ;
F_26 ( & V_2 -> V_15 ) ;
V_76 = F_14 ( V_2 , V_82 ) ;
V_77 = V_76 & 0x3f ;
if ( ! ( V_76 & 0x40 ) )
V_77 = - V_77 ;
V_78 = V_80 = F_14 ( V_2 , V_83 ) ;
V_79 = V_81 = F_14 ( V_2 , V_84 ) ;
V_78 &= 0x1f ;
V_79 &= 0x1f ;
V_78 += V_77 ;
if ( V_78 < 0 )
V_78 = 0 ;
if ( V_78 > 0x1f )
V_78 = 0x1f ;
V_79 += V_77 ;
if ( V_79 < 0 )
V_79 = 0 ;
if ( V_79 > 0x1f )
V_79 = 0x1f ;
if ( V_76 & 0x80 ) {
V_80 ^= 0x80 ;
V_81 ^= 0x80 ;
}
V_78 |= V_80 & 0x80 ;
V_79 |= V_81 & 0x80 ;
F_8 ( V_2 , V_83 , V_78 ) ;
F_8 ( V_2 , V_84 , V_79 ) ;
F_27 ( & V_2 -> V_15 ) ;
F_32 ( V_2 -> V_67 , V_85 , & V_2 -> V_86 -> V_87 ) ;
F_32 ( V_2 -> V_67 , V_85 , & V_2 -> V_88 -> V_87 ) ;
}
return V_69 ;
}
static int F_33 ( struct V_89 * V_90 ,
int V_50 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
return F_25 ( V_2 , 1 , V_50 ) ;
}
static int F_35 ( struct V_89 * V_90 ,
int V_50 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
return F_25 ( V_2 , 2 , V_50 ) ;
}
static int F_36 ( struct V_89 * V_90 ,
struct V_37 * V_91 )
{
return F_37 ( V_90 , F_38 ( V_91 ) ) ;
}
static int F_39 ( struct V_89 * V_90 )
{
return F_40 ( V_90 ) ;
}
static int F_41 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
struct V_92 * V_93 = V_90 -> V_93 ;
unsigned char V_94 = 0 ;
unsigned int V_95 = F_42 ( V_90 ) ;
unsigned int V_4 = F_43 ( V_90 ) ;
V_2 -> V_96 = V_95 ;
V_4 -- ;
if ( V_93 -> V_97 > 1 )
V_94 |= 1 ;
if ( F_44 ( V_93 -> V_19 ) == 16 )
V_94 |= 2 ;
F_17 ( V_2 , ~ 3 , V_94 ) ;
F_24 ( V_2 , V_93 -> V_20 ) ;
F_45 ( & V_2 -> V_15 ) ;
F_1 ( V_2 , V_93 -> V_98 , V_95 ) ;
F_8 ( V_2 , V_99 , V_4 >> 8 ) ;
F_8 ( V_2 , V_100 , V_4 ) ;
F_46 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
struct V_92 * V_93 = V_90 -> V_93 ;
unsigned char V_94 = 0 ;
unsigned int V_95 = F_42 ( V_90 ) ;
unsigned int V_4 = F_43 ( V_90 ) ;
V_2 -> V_101 = V_95 ;
V_4 >>= 1 ;
V_4 -- ;
if ( V_93 -> V_97 > 1 )
V_94 |= 0x10 ;
if ( F_44 ( V_93 -> V_19 ) == 16 )
V_94 |= 0x20 ;
F_17 ( V_2 , ~ 0x30 , V_94 ) ;
F_20 ( V_2 , V_93 -> V_20 ) ;
F_45 ( & V_2 -> V_15 ) ;
F_4 ( V_2 , V_93 -> V_98 , V_95 ) ;
F_8 ( V_2 , V_102 , V_4 >> 8 ) ;
F_8 ( V_2 , V_103 , V_4 ) ;
F_46 ( & V_2 -> V_15 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
T_3 V_104 ;
if ( ! ( V_2 -> V_53 & 1 ) )
return 0 ;
V_104 = V_2 -> V_96 - F_5 ( V_2 ) ;
return F_49 ( V_90 -> V_93 , V_104 ) ;
}
static T_2 F_50 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
T_3 V_104 ;
if ( ! ( V_2 -> V_53 & 2 ) )
return 0 ;
V_104 = V_2 -> V_101 - F_7 ( V_2 ) ;
return F_49 ( V_90 -> V_93 , V_104 ) ;
}
static int F_51 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
struct V_92 * V_93 = V_90 -> V_93 ;
V_2 -> V_105 |= V_106 ;
V_2 -> V_71 = V_90 ;
V_93 -> V_107 = V_108 ;
F_52 ( V_93 , 0 , V_41 , F_21 , NULL , V_41 , - 1 ) ;
return 0 ;
}
static int F_53 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
struct V_92 * V_93 = V_90 -> V_93 ;
V_2 -> V_105 |= V_109 ;
V_2 -> V_72 = V_90 ;
V_93 -> V_107 = V_110 ;
F_54 ( V_93 , 0 , V_41 ,
& V_111 ) ;
return 0 ;
}
static int F_55 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
V_2 -> V_71 = NULL ;
V_2 -> V_105 &= ~ V_106 ;
return 0 ;
}
static int F_56 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_105 &= ~ V_109 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , int V_112 )
{
struct V_113 * V_70 ;
int V_114 ;
if ( ( V_114 = F_58 ( V_2 -> V_67 , L_2 , V_112 , 1 , 1 , & V_70 ) ) < 0 )
return V_114 ;
if ( F_23 ( ! V_70 ) )
return - V_56 ;
F_59 ( V_70 , V_115 , & V_116 ) ;
F_59 ( V_70 , V_117 , & V_118 ) ;
V_70 -> V_74 = V_2 ;
V_70 -> V_119 = 0 ;
strcpy ( V_70 -> V_120 , L_3 ) ;
V_2 -> V_70 = V_70 ;
F_60 ( V_70 , V_121 ,
F_61 ( V_2 -> V_122 ) , 64 * 1024 , 128 * 1024 ) ;
return 0 ;
}
static int F_62 ( struct V_123 * V_124 , struct V_125 * V_126 )
{
static const char * const V_127 [ 7 ] = {
L_4 , L_5 , L_6 , L_7 , L_8 , L_9 , L_10
} ;
return F_63 ( V_126 , 2 , 7 , V_127 ) ;
}
static int F_64 ( struct V_123 * V_124 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_65 ( V_124 ) ;
F_45 ( & V_2 -> V_15 ) ;
V_129 -> V_11 . V_130 . V_131 [ 0 ] = ( ( F_14 ( V_2 , V_132 ) & V_133 ) >> 5 ) - 1 ;
V_129 -> V_11 . V_130 . V_131 [ 1 ] = ( ( F_14 ( V_2 , V_134 ) & V_133 ) >> 5 ) - 1 ;
F_46 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_66 ( struct V_123 * V_124 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_65 ( V_124 ) ;
unsigned short V_135 , V_136 , V_137 , V_138 ;
int V_139 ;
if ( V_129 -> V_11 . V_130 . V_131 [ 0 ] >= 7 ||
V_129 -> V_11 . V_130 . V_131 [ 1 ] >= 7 )
return - V_56 ;
V_135 = ( V_129 -> V_11 . V_130 . V_131 [ 0 ] + 1 ) << 5 ;
V_136 = ( V_129 -> V_11 . V_130 . V_131 [ 1 ] + 1 ) << 5 ;
F_45 ( & V_2 -> V_15 ) ;
V_137 = F_14 ( V_2 , V_132 ) ;
V_138 = F_14 ( V_2 , V_134 ) ;
V_135 = ( V_137 & ~ V_133 ) | V_135 ;
V_136 = ( V_138 & ~ V_133 ) | V_136 ;
V_139 = V_135 != V_137 || V_136 != V_138 ;
F_8 ( V_2 , V_132 , V_135 ) ;
F_8 ( V_2 , V_134 , V_136 ) ;
F_46 ( & V_2 -> V_15 ) ;
return V_139 ;
}
static int F_67 ( struct V_123 * V_124 , struct V_125 * V_126 )
{
int V_16 = ( V_124 -> V_140 >> 16 ) & 0xff ;
V_126 -> type = V_16 == 1 ? V_141 : V_142 ;
V_126 -> V_4 = 1 ;
V_126 -> V_11 . integer . V_42 = 0 ;
V_126 -> V_11 . integer . V_43 = V_16 ;
return 0 ;
}
static int F_68 ( struct V_123 * V_124 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_65 ( V_124 ) ;
int V_10 = V_124 -> V_140 & 0xff ;
int V_143 = ( V_124 -> V_140 >> 8 ) & 0xff ;
int V_16 = ( V_124 -> V_140 >> 16 ) & 0xff ;
int V_144 = ( V_124 -> V_140 >> 24 ) & 0xff ;
F_45 ( & V_2 -> V_15 ) ;
V_129 -> V_11 . integer . V_11 [ 0 ] = ( F_14 ( V_2 , V_10 ) >> V_143 ) & V_16 ;
F_46 ( & V_2 -> V_15 ) ;
if ( V_144 )
V_129 -> V_11 . integer . V_11 [ 0 ] = V_16 - V_129 -> V_11 . integer . V_11 [ 0 ] ;
return 0 ;
}
static int F_69 ( struct V_123 * V_124 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_65 ( V_124 ) ;
int V_10 = V_124 -> V_140 & 0xff ;
int V_143 = ( V_124 -> V_140 >> 8 ) & 0xff ;
int V_16 = ( V_124 -> V_140 >> 16 ) & 0xff ;
int V_144 = ( V_124 -> V_140 >> 24 ) & 0xff ;
int V_139 ;
unsigned short V_145 , V_146 ;
V_145 = ( V_129 -> V_11 . integer . V_11 [ 0 ] & V_16 ) ;
if ( V_144 )
V_145 = V_16 - V_145 ;
V_145 <<= V_143 ;
F_45 ( & V_2 -> V_15 ) ;
V_146 = F_14 ( V_2 , V_10 ) ;
V_145 = ( V_146 & ~ ( V_16 << V_143 ) ) | V_145 ;
V_139 = V_145 != V_146 ;
F_8 ( V_2 , V_10 , V_145 ) ;
F_46 ( & V_2 -> V_15 ) ;
return V_139 ;
}
static int F_70 ( struct V_123 * V_124 , struct V_125 * V_126 )
{
int V_16 = ( V_124 -> V_140 >> 24 ) & 0xff ;
V_126 -> type = V_16 == 1 ? V_141 : V_142 ;
V_126 -> V_4 = 2 ;
V_126 -> V_11 . integer . V_42 = 0 ;
V_126 -> V_11 . integer . V_43 = V_16 ;
return 0 ;
}
static int F_71 ( struct V_123 * V_124 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_65 ( V_124 ) ;
int V_147 = V_124 -> V_140 & 0xff ;
int V_148 = ( V_124 -> V_140 >> 8 ) & 0xff ;
int V_149 = ( V_124 -> V_140 >> 16 ) & 0x07 ;
int V_150 = ( V_124 -> V_140 >> 19 ) & 0x07 ;
int V_16 = ( V_124 -> V_140 >> 24 ) & 0xff ;
int V_144 = ( V_124 -> V_140 >> 22 ) & 1 ;
F_45 ( & V_2 -> V_15 ) ;
V_129 -> V_11 . integer . V_11 [ 0 ] = ( F_14 ( V_2 , V_147 ) >> V_149 ) & V_16 ;
V_129 -> V_11 . integer . V_11 [ 1 ] = ( F_14 ( V_2 , V_148 ) >> V_150 ) & V_16 ;
F_46 ( & V_2 -> V_15 ) ;
if ( V_144 ) {
V_129 -> V_11 . integer . V_11 [ 0 ] = V_16 - V_129 -> V_11 . integer . V_11 [ 0 ] ;
V_129 -> V_11 . integer . V_11 [ 1 ] = V_16 - V_129 -> V_11 . integer . V_11 [ 1 ] ;
}
return 0 ;
}
static int F_72 ( struct V_123 * V_124 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_65 ( V_124 ) ;
int V_147 = V_124 -> V_140 & 0xff ;
int V_148 = ( V_124 -> V_140 >> 8 ) & 0xff ;
int V_149 = ( V_124 -> V_140 >> 16 ) & 0x07 ;
int V_150 = ( V_124 -> V_140 >> 19 ) & 0x07 ;
int V_16 = ( V_124 -> V_140 >> 24 ) & 0xff ;
int V_144 = ( V_124 -> V_140 >> 22 ) & 1 ;
int V_139 ;
unsigned short V_151 , V_152 , V_137 , V_138 ;
V_151 = V_129 -> V_11 . integer . V_11 [ 0 ] & V_16 ;
V_152 = V_129 -> V_11 . integer . V_11 [ 1 ] & V_16 ;
if ( V_144 ) {
V_151 = V_16 - V_151 ;
V_152 = V_16 - V_152 ;
}
V_151 <<= V_149 ;
V_152 <<= V_150 ;
F_45 ( & V_2 -> V_15 ) ;
V_137 = F_14 ( V_2 , V_147 ) ;
V_138 = F_14 ( V_2 , V_148 ) ;
V_151 = ( V_137 & ~ ( V_16 << V_149 ) ) | V_151 ;
V_152 = ( V_138 & ~ ( V_16 << V_150 ) ) | V_152 ;
V_139 = V_151 != V_137 || V_152 != V_138 ;
F_8 ( V_2 , V_147 , V_151 ) ;
F_8 ( V_2 , V_148 , V_152 ) ;
F_46 ( & V_2 -> V_15 ) ;
return V_139 ;
}
static void F_73 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_65 ( V_124 ) ;
V_2 -> V_86 = NULL ;
V_2 -> V_88 = NULL ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_153 * V_67 ;
struct V_123 * V_154 ;
unsigned int V_155 ;
int V_114 ;
if ( F_23 ( ! V_2 || ! V_2 -> V_67 ) )
return - V_56 ;
V_67 = V_2 -> V_67 ;
strcpy ( V_67 -> V_156 , L_3 ) ;
for ( V_155 = 0 ; V_155 < F_75 ( V_157 ) ; V_155 ++ ) {
if ( ( V_114 = F_76 ( V_67 , V_154 = F_77 ( & V_157 [ V_155 ] , V_2 ) ) ) < 0 )
return V_114 ;
switch ( V_155 ) {
case 0 :
case 1 : V_154 -> V_158 = F_73 ; break;
}
}
return 0 ;
}
static void F_78 ( struct V_159 * V_160 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 = V_160 -> V_74 ;
unsigned char V_163 ;
V_163 = V_2 -> V_164 & 0x0f ;
F_79 ( V_162 , L_11 ,
V_2 -> V_164 & 0x80 ? L_12 : L_13 ) ;
F_79 ( V_162 , L_14 ,
V_163 == 0x00 ? L_15 :
V_163 == 0x01 ? L_16 :
V_163 == 0x02 ? L_17 :
V_163 == 0x03 ? L_18 : L_19 ) ;
V_163 = V_2 -> V_165 & 0x0f ;
F_79 ( V_162 , L_20 ,
V_163 == 0x00 ? L_15 :
V_163 == 0x01 ? L_16 :
V_163 == 0x02 ? L_17 :
V_163 == 0x03 ? L_18 : L_19 ) ;
V_163 = V_2 -> V_166 & 0x03 ;
F_79 ( V_162 , L_21 ,
V_163 == 0x00 ? L_22 :
V_163 == 0x01 ? L_23 : L_24 ) ;
V_163 = V_2 -> V_167 ;
F_79 ( V_162 , L_25 , V_163 & 0x01 ? L_13 : L_12 ) ;
F_79 ( V_162 , L_26 , V_163 & 0x02 ? L_13 : L_12 ) ;
F_79 ( V_162 , L_27 , V_163 & 0x04 ? L_13 : L_12 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_159 * V_160 ;
if ( ! F_81 ( V_2 -> V_67 , L_28 , & V_160 ) )
F_82 ( V_160 , V_2 , F_78 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_168 * V_169 ;
V_2 -> V_168 = V_169 = F_84 () ;
if ( ! V_169 ) {
F_29 ( V_2 -> V_67 -> V_68 ,
L_29 ) ;
return - V_170 ;
}
F_85 ( V_169 , L_30 ) ;
F_86 ( V_169 , L_31 , F_87 ( V_2 -> V_122 ) ) ;
F_88 ( V_169 , & V_2 -> V_122 -> V_68 ) ;
V_169 -> V_171 = V_2 -> V_172 ;
F_89 ( V_169 ) ;
F_76 ( V_2 -> V_67 , F_77 ( & V_173 , V_2 ) ) ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_168 ) {
F_91 ( V_2 -> V_168 ) ;
V_2 -> V_168 = NULL ;
}
}
static inline int F_83 ( struct V_1 * V_2 ) { return - V_174 ; }
static inline void F_90 ( struct V_1 * V_2 ) { }
static int F_92 ( struct V_1 * V_2 )
{
F_90 ( V_2 ) ;
F_93 ( V_2 -> V_122 , 0x40 , V_2 -> V_5 ) ;
F_93 ( V_2 -> V_122 , 0x48 , V_2 -> V_9 ) ;
if ( V_2 -> V_57 >= 0 )
F_94 ( V_2 -> V_57 , V_2 ) ;
F_95 ( V_2 -> V_175 ) ;
F_95 ( V_2 -> V_176 ) ;
F_96 ( V_2 -> V_122 ) ;
F_97 ( V_2 -> V_122 ) ;
F_98 ( V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_177 * V_112 )
{
struct V_1 * V_2 = V_112 -> V_178 ;
return F_92 ( V_2 ) ;
}
static int F_100 ( struct V_153 * V_67 ,
struct V_179 * V_122 ,
int V_180 ,
int V_181 ,
struct V_1 * * V_182 )
{
struct V_1 * V_2 ;
unsigned int V_183 , V_184 ;
int V_114 ;
static struct V_185 V_186 = {
. V_187 = F_99 ,
} ;
* V_182 = NULL ;
if ( ( V_114 = F_101 ( V_122 ) ) < 0 )
return V_114 ;
if ( F_102 ( & V_122 -> V_68 , F_103 ( 24 ) ) < 0 ||
F_104 ( & V_122 -> V_68 , F_103 ( 24 ) ) < 0 ) {
F_29 ( V_67 -> V_68 ,
L_32 ) ;
F_97 ( V_122 ) ;
return - V_188 ;
}
V_2 = F_105 ( sizeof( * V_2 ) , V_189 ) ;
if ( V_2 == NULL ) {
F_97 ( V_122 ) ;
return - V_170 ;
}
F_106 ( & V_2 -> V_15 ) ;
V_2 -> V_67 = V_67 ;
V_2 -> V_122 = V_122 ;
V_2 -> V_57 = - 1 ;
if ( ( V_114 = F_107 ( V_122 , L_3 ) ) < 0 ) {
F_98 ( V_2 ) ;
F_97 ( V_122 ) ;
return V_114 ;
}
V_2 -> V_190 = F_108 ( V_122 , 0 ) ;
V_2 -> V_191 = F_108 ( V_122 , 1 ) ;
V_2 -> V_192 = F_108 ( V_122 , 2 ) ;
V_2 -> V_193 = F_108 ( V_122 , 3 ) ;
V_2 -> V_172 = F_108 ( V_122 , 4 ) ;
if ( F_109 ( V_122 -> V_57 , F_28 , V_194 ,
V_195 , V_2 ) ) {
F_29 ( V_67 -> V_68 , L_33 , V_122 -> V_57 ) ;
F_92 ( V_2 ) ;
return - V_196 ;
}
V_2 -> V_57 = V_122 -> V_57 ;
F_110 ( V_122 , 0x40 , & V_183 ) ;
F_110 ( V_122 , 0x48 , & V_184 ) ;
V_197 &= ~ 0x0f ;
V_183 &= ~ 0x0f ;
V_184 &= ~ 0x0f ;
if ( ! V_183 ) {
V_183 = V_197 ;
V_197 += 0x10 ;
F_111 ( V_67 -> V_68 ,
L_34 ,
V_183 ) ;
}
if ( ! V_184 ) {
V_184 = V_197 ;
V_197 += 0x10 ;
F_111 ( V_67 -> V_68 ,
L_35 ,
V_184 ) ;
}
F_93 ( V_122 , 0x40 , V_183 ) ;
F_93 ( V_122 , 0x48 , V_184 ) ;
if ( ( V_2 -> V_175 = F_112 ( V_183 , 0x10 , L_36 ) ) == NULL ) {
F_92 ( V_2 ) ;
F_29 ( V_67 -> V_68 ,
L_37 ,
V_183 , V_183 + 0x10 - 1 ) ;
return - V_196 ;
}
if ( ( V_2 -> V_176 = F_112 ( V_184 , 0x10 , L_38 ) ) == NULL ) {
F_92 ( V_2 ) ;
F_29 ( V_67 -> V_68 ,
L_39 ,
V_184 , V_184 + 0x10 - 1 ) ;
return - V_196 ;
}
F_110 ( V_122 , 0x40 , & V_2 -> V_5 ) ;
F_110 ( V_122 , 0x48 , & V_2 -> V_9 ) ;
V_2 -> V_5 &= ~ 0x0f ;
V_2 -> V_9 &= ~ 0x0f ;
F_93 ( V_122 , 0x40 , V_2 -> V_5 | 9 ) ;
F_93 ( V_122 , 0x48 , V_2 -> V_9 | 9 ) ;
F_3 ( V_198 , F_9 ( V_2 , V_199 ) ) ;
F_10 ( 100 ) ;
F_3 ( 0 , F_9 ( V_2 , V_199 ) ) ;
F_10 ( 100 ) ;
F_3 ( V_200 | V_201 | ( V_180 ? V_202 : 0 ) , F_9 ( V_2 , V_199 ) ) ;
F_15 ( F_9 ( V_2 , V_60 ) ) ;
#if 1
F_11 ( V_2 , V_203 , 0 ) ;
#else
F_11 ( V_2 , V_203 , 0x40 ) ;
#endif
F_11 ( V_2 , V_54 , V_2 -> V_53 = 0 ) ;
F_3 ( V_2 -> V_65 = ~ ( V_204 | V_205 | V_206 ) , F_9 ( V_2 , V_66 ) ) ;
F_15 ( F_9 ( V_2 , V_60 ) ) ;
F_11 ( V_2 , V_36 , 0 ) ;
F_11 ( V_2 , V_207 , 0 ) ;
F_11 ( V_2 , V_208 , 0 ) ;
F_19 ( V_2 , V_34 , 8000 ) ;
F_11 ( V_2 , V_209 , V_2 -> V_164 = 0x80 ) ;
F_11 ( V_2 , V_210 , V_2 -> V_165 = 0x00 ) ;
F_11 ( V_2 , V_211 , V_2 -> V_167 = 0x05 ) ;
F_11 ( V_2 , V_212 , V_2 -> V_166 = 0x00 ) ;
F_11 ( V_2 , V_48 , ( 8000 * 65536 / V_46 ) & 0xff ) ;
F_11 ( V_2 , V_47 , ( ( 8000 * 65536 / V_46 ) >> 8 ) & 0xff ) ;
F_11 ( V_2 , V_132 , V_181 ? 0xd0 : 0xc0 ) ;
F_11 ( V_2 , V_134 , 0xc0 ) ;
F_11 ( V_2 , V_213 , 0x9f ) ;
F_11 ( V_2 , V_214 , 0x9f ) ;
F_11 ( V_2 , V_215 , 0x9f ) ;
F_11 ( V_2 , V_216 , 0x9f ) ;
F_11 ( V_2 , V_217 , 0x9f ) ;
F_11 ( V_2 , V_218 , 0x9f ) ;
F_11 ( V_2 , V_219 , 0x8f ) ;
F_11 ( V_2 , V_220 , 0x9f ) ;
F_11 ( V_2 , V_221 , 0x9f ) ;
F_11 ( V_2 , V_222 , 0x9f ) ;
F_11 ( V_2 , V_223 , 0x9f ) ;
F_11 ( V_2 , V_83 , 0x9f ) ;
F_11 ( V_2 , V_84 , 0x9f ) ;
F_11 ( V_2 , V_224 , 0xbf ) ;
F_11 ( V_2 , V_225 , 0xbf ) ;
F_11 ( V_2 , V_226 , 0xfc ) ;
#if 0
snd_sonicvibes_debug(sonic);
#endif
V_2 -> V_227 = F_16 ( V_2 , V_228 ) ;
if ( ( V_114 = F_113 ( V_67 , V_229 , V_2 , & V_186 ) ) < 0 ) {
F_92 ( V_2 ) ;
return V_114 ;
}
F_80 ( V_2 ) ;
* V_182 = V_2 ;
return 0 ;
}
static int F_114 ( struct V_230 * V_231 )
{
struct V_1 * V_2 = V_231 -> V_74 ;
F_3 ( V_2 -> V_65 &= ~ V_232 , F_9 ( V_2 , V_66 ) ) ;
return 0 ;
}
static void F_115 ( struct V_230 * V_231 )
{
struct V_1 * V_2 = V_231 -> V_74 ;
F_3 ( V_2 -> V_65 |= V_232 , F_9 ( V_2 , V_66 ) ) ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_233 * V_73 )
{
struct V_230 * V_231 = V_73 -> V_74 ;
struct V_153 * V_67 = V_2 -> V_67 ;
struct V_234 * V_235 ;
unsigned int V_155 ;
int V_114 ;
V_231 -> V_74 = V_2 ;
V_231 -> V_236 = F_114 ;
V_231 -> V_237 = F_115 ;
V_235 = & V_73 -> V_238 [ V_239 ] ;
for ( V_155 = 0 ; V_155 < F_75 ( V_240 ) ; V_155 ++ )
if ( ( V_114 = F_76 ( V_67 , F_77 ( & V_240 [ V_155 ] , V_2 ) ) ) < 0 )
return V_114 ;
return 0 ;
}
static int F_117 ( struct V_179 * V_122 ,
const struct V_241 * V_242 )
{
static int V_68 ;
struct V_153 * V_67 ;
struct V_1 * V_2 ;
struct V_233 * V_243 ;
struct V_244 * V_245 ;
int V_155 , V_114 ;
if ( V_68 >= V_246 )
return - V_247 ;
if ( ! V_53 [ V_68 ] ) {
V_68 ++ ;
return - V_248 ;
}
V_114 = F_118 ( & V_122 -> V_68 , V_249 [ V_68 ] , V_87 [ V_68 ] , V_250 ,
0 , & V_67 ) ;
if ( V_114 < 0 )
return V_114 ;
for ( V_155 = 0 ; V_155 < 5 ; V_155 ++ ) {
if ( F_108 ( V_122 , V_155 ) == 0 ||
! ( F_119 ( V_122 , V_155 ) & V_251 ) ) {
F_120 ( V_67 ) ;
return - V_247 ;
}
}
if ( ( V_114 = F_100 ( V_67 , V_122 ,
V_180 [ V_68 ] ? 1 : 0 ,
V_181 [ V_68 ] ? 1 : 0 ,
& V_2 ) ) < 0 ) {
F_120 ( V_67 ) ;
return V_114 ;
}
strcpy ( V_67 -> V_252 , L_40 ) ;
strcpy ( V_67 -> V_253 , L_3 ) ;
sprintf ( V_67 -> V_254 , L_41 ,
V_67 -> V_253 ,
V_2 -> V_227 ,
( unsigned long long ) F_108 ( V_122 , 1 ) ,
V_2 -> V_57 ) ;
if ( ( V_114 = F_57 ( V_2 , 0 ) ) < 0 ) {
F_120 ( V_67 ) ;
return V_114 ;
}
if ( ( V_114 = F_74 ( V_2 ) ) < 0 ) {
F_120 ( V_67 ) ;
return V_114 ;
}
if ( ( V_114 = F_121 ( V_67 , 0 , V_255 ,
V_2 -> V_193 ,
V_256 |
V_257 ,
- 1 , & V_243 ) ) < 0 ) {
F_120 ( V_67 ) ;
return V_114 ;
}
F_116 ( V_2 , V_243 ) ;
if ( ( V_114 = F_122 ( V_67 , V_2 -> V_192 ,
V_2 -> V_192 + 2 ,
V_258 , 1 , & V_245 ) ) < 0 ) {
F_120 ( V_67 ) ;
return V_114 ;
}
if ( ( V_114 = F_123 ( V_245 , 0 , 1 , NULL ) ) < 0 ) {
F_120 ( V_67 ) ;
return V_114 ;
}
F_83 ( V_2 ) ;
if ( ( V_114 = F_124 ( V_67 ) ) < 0 ) {
F_120 ( V_67 ) ;
return V_114 ;
}
F_125 ( V_122 , V_67 ) ;
V_68 ++ ;
return 0 ;
}
static void F_126 ( struct V_179 * V_122 )
{
F_120 ( F_127 ( V_122 ) ) ;
}
