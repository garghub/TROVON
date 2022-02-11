static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
V_4 -- ;
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
F_2 ( V_4 , V_2 -> V_5 + V_7 ) ;
F_3 ( 0x18 , V_2 -> V_5 + V_8 ) ;
#if 0
printk(KERN_DEBUG "program dmaa: addr = 0x%x, paddr = 0x%x\n",
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
printk(KERN_DEBUG "program dmac: addr = 0x%x, paddr = 0x%x\n",
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
printk(KERN_DEBUG "metric = %i, xm = %i, xn = %i\n", metric, xm, xn);
printk(KERN_DEBUG "pll: m = 0x%x, r = 0x%x, n = 0x%x\n", reg, m, r, n);
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
F_29 ( V_67 L_1 ) ;
return V_68 ;
}
if ( V_2 -> V_69 ) {
if ( V_59 & V_61 )
F_30 ( V_2 -> V_70 ) ;
if ( V_59 & V_62 )
F_30 ( V_2 -> V_71 ) ;
}
if ( V_2 -> V_72 ) {
if ( V_59 & V_63 )
F_31 ( V_57 , V_2 -> V_72 -> V_73 ) ;
}
if ( V_59 & V_74 ) {
unsigned char V_75 ;
int V_76 , V_77 , V_78 , V_79 , V_80 ;
F_26 ( & V_2 -> V_15 ) ;
V_75 = F_14 ( V_2 , V_81 ) ;
V_76 = V_75 & 0x3f ;
if ( ! ( V_75 & 0x40 ) )
V_76 = - V_76 ;
V_77 = V_79 = F_14 ( V_2 , V_82 ) ;
V_78 = V_80 = F_14 ( V_2 , V_83 ) ;
V_77 &= 0x1f ;
V_78 &= 0x1f ;
V_77 += V_76 ;
if ( V_77 < 0 )
V_77 = 0 ;
if ( V_77 > 0x1f )
V_77 = 0x1f ;
V_78 += V_76 ;
if ( V_78 < 0 )
V_78 = 0 ;
if ( V_78 > 0x1f )
V_78 = 0x1f ;
if ( V_75 & 0x80 ) {
V_79 ^= 0x80 ;
V_80 ^= 0x80 ;
}
V_77 |= V_79 & 0x80 ;
V_78 |= V_80 & 0x80 ;
F_8 ( V_2 , V_82 , V_77 ) ;
F_8 ( V_2 , V_83 , V_78 ) ;
F_27 ( & V_2 -> V_15 ) ;
F_32 ( V_2 -> V_84 , V_85 , & V_2 -> V_86 -> V_87 ) ;
F_32 ( V_2 -> V_84 , V_85 , & V_2 -> V_88 -> V_87 ) ;
}
return V_68 ;
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
V_2 -> V_70 = V_90 ;
V_93 -> V_107 = V_108 ;
F_52 ( V_93 , 0 , V_41 , F_21 , NULL , V_41 , - 1 ) ;
return 0 ;
}
static int F_53 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
struct V_92 * V_93 = V_90 -> V_93 ;
V_2 -> V_105 |= V_109 ;
V_2 -> V_71 = V_90 ;
V_93 -> V_107 = V_110 ;
F_54 ( V_93 , 0 , V_41 ,
& V_111 ) ;
return 0 ;
}
static int F_55 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
V_2 -> V_70 = NULL ;
V_2 -> V_105 &= ~ V_106 ;
return 0 ;
}
static int F_56 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_34 ( V_90 ) ;
V_2 -> V_71 = NULL ;
V_2 -> V_105 &= ~ V_109 ;
return 0 ;
}
static int T_4 F_57 ( struct V_1 * V_2 , int V_112 , struct V_113 * * V_114 )
{
struct V_113 * V_69 ;
int V_115 ;
if ( ( V_115 = F_58 ( V_2 -> V_84 , L_2 , V_112 , 1 , 1 , & V_69 ) ) < 0 )
return V_115 ;
if ( F_23 ( ! V_69 ) )
return - V_56 ;
F_59 ( V_69 , V_116 , & V_117 ) ;
F_59 ( V_69 , V_118 , & V_119 ) ;
V_69 -> V_73 = V_2 ;
V_69 -> V_120 = 0 ;
strcpy ( V_69 -> V_121 , L_3 ) ;
V_2 -> V_69 = V_69 ;
F_60 ( V_69 , V_122 ,
F_61 ( V_2 -> V_123 ) , 64 * 1024 , 128 * 1024 ) ;
if ( V_114 )
* V_114 = V_69 ;
return 0 ;
}
static int F_62 ( struct V_124 * V_125 , struct V_126 * V_127 )
{
static char * V_128 [ 7 ] = {
L_4 , L_5 , L_6 , L_7 , L_8 , L_9 , L_10
} ;
V_127 -> type = V_129 ;
V_127 -> V_4 = 2 ;
V_127 -> V_11 . V_130 . V_131 = 7 ;
if ( V_127 -> V_11 . V_130 . V_132 >= 7 )
V_127 -> V_11 . V_130 . V_132 = 6 ;
strcpy ( V_127 -> V_11 . V_130 . V_121 , V_128 [ V_127 -> V_11 . V_130 . V_132 ] ) ;
return 0 ;
}
static int F_63 ( struct V_124 * V_125 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_64 ( V_125 ) ;
F_45 ( & V_2 -> V_15 ) ;
V_134 -> V_11 . V_130 . V_132 [ 0 ] = ( ( F_14 ( V_2 , V_135 ) & V_136 ) >> 5 ) - 1 ;
V_134 -> V_11 . V_130 . V_132 [ 1 ] = ( ( F_14 ( V_2 , V_137 ) & V_136 ) >> 5 ) - 1 ;
F_46 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_124 * V_125 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_64 ( V_125 ) ;
unsigned short V_138 , V_139 , V_140 , V_141 ;
int V_142 ;
if ( V_134 -> V_11 . V_130 . V_132 [ 0 ] >= 7 ||
V_134 -> V_11 . V_130 . V_132 [ 1 ] >= 7 )
return - V_56 ;
V_138 = ( V_134 -> V_11 . V_130 . V_132 [ 0 ] + 1 ) << 5 ;
V_139 = ( V_134 -> V_11 . V_130 . V_132 [ 1 ] + 1 ) << 5 ;
F_45 ( & V_2 -> V_15 ) ;
V_140 = F_14 ( V_2 , V_135 ) ;
V_141 = F_14 ( V_2 , V_137 ) ;
V_138 = ( V_140 & ~ V_136 ) | V_138 ;
V_139 = ( V_141 & ~ V_136 ) | V_139 ;
V_142 = V_138 != V_140 || V_139 != V_141 ;
F_8 ( V_2 , V_135 , V_138 ) ;
F_8 ( V_2 , V_137 , V_139 ) ;
F_46 ( & V_2 -> V_15 ) ;
return V_142 ;
}
static int F_66 ( struct V_124 * V_125 , struct V_126 * V_127 )
{
int V_16 = ( V_125 -> V_143 >> 16 ) & 0xff ;
V_127 -> type = V_16 == 1 ? V_144 : V_145 ;
V_127 -> V_4 = 1 ;
V_127 -> V_11 . integer . V_42 = 0 ;
V_127 -> V_11 . integer . V_43 = V_16 ;
return 0 ;
}
static int F_67 ( struct V_124 * V_125 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_64 ( V_125 ) ;
int V_10 = V_125 -> V_143 & 0xff ;
int V_146 = ( V_125 -> V_143 >> 8 ) & 0xff ;
int V_16 = ( V_125 -> V_143 >> 16 ) & 0xff ;
int V_147 = ( V_125 -> V_143 >> 24 ) & 0xff ;
F_45 ( & V_2 -> V_15 ) ;
V_134 -> V_11 . integer . V_11 [ 0 ] = ( F_14 ( V_2 , V_10 ) >> V_146 ) & V_16 ;
F_46 ( & V_2 -> V_15 ) ;
if ( V_147 )
V_134 -> V_11 . integer . V_11 [ 0 ] = V_16 - V_134 -> V_11 . integer . V_11 [ 0 ] ;
return 0 ;
}
static int F_68 ( struct V_124 * V_125 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_64 ( V_125 ) ;
int V_10 = V_125 -> V_143 & 0xff ;
int V_146 = ( V_125 -> V_143 >> 8 ) & 0xff ;
int V_16 = ( V_125 -> V_143 >> 16 ) & 0xff ;
int V_147 = ( V_125 -> V_143 >> 24 ) & 0xff ;
int V_142 ;
unsigned short V_148 , V_149 ;
V_148 = ( V_134 -> V_11 . integer . V_11 [ 0 ] & V_16 ) ;
if ( V_147 )
V_148 = V_16 - V_148 ;
V_148 <<= V_146 ;
F_45 ( & V_2 -> V_15 ) ;
V_149 = F_14 ( V_2 , V_10 ) ;
V_148 = ( V_149 & ~ ( V_16 << V_146 ) ) | V_148 ;
V_142 = V_148 != V_149 ;
F_8 ( V_2 , V_10 , V_148 ) ;
F_46 ( & V_2 -> V_15 ) ;
return V_142 ;
}
static int F_69 ( struct V_124 * V_125 , struct V_126 * V_127 )
{
int V_16 = ( V_125 -> V_143 >> 24 ) & 0xff ;
V_127 -> type = V_16 == 1 ? V_144 : V_145 ;
V_127 -> V_4 = 2 ;
V_127 -> V_11 . integer . V_42 = 0 ;
V_127 -> V_11 . integer . V_43 = V_16 ;
return 0 ;
}
static int F_70 ( struct V_124 * V_125 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_64 ( V_125 ) ;
int V_150 = V_125 -> V_143 & 0xff ;
int V_151 = ( V_125 -> V_143 >> 8 ) & 0xff ;
int V_152 = ( V_125 -> V_143 >> 16 ) & 0x07 ;
int V_153 = ( V_125 -> V_143 >> 19 ) & 0x07 ;
int V_16 = ( V_125 -> V_143 >> 24 ) & 0xff ;
int V_147 = ( V_125 -> V_143 >> 22 ) & 1 ;
F_45 ( & V_2 -> V_15 ) ;
V_134 -> V_11 . integer . V_11 [ 0 ] = ( F_14 ( V_2 , V_150 ) >> V_152 ) & V_16 ;
V_134 -> V_11 . integer . V_11 [ 1 ] = ( F_14 ( V_2 , V_151 ) >> V_153 ) & V_16 ;
F_46 ( & V_2 -> V_15 ) ;
if ( V_147 ) {
V_134 -> V_11 . integer . V_11 [ 0 ] = V_16 - V_134 -> V_11 . integer . V_11 [ 0 ] ;
V_134 -> V_11 . integer . V_11 [ 1 ] = V_16 - V_134 -> V_11 . integer . V_11 [ 1 ] ;
}
return 0 ;
}
static int F_71 ( struct V_124 * V_125 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_64 ( V_125 ) ;
int V_150 = V_125 -> V_143 & 0xff ;
int V_151 = ( V_125 -> V_143 >> 8 ) & 0xff ;
int V_152 = ( V_125 -> V_143 >> 16 ) & 0x07 ;
int V_153 = ( V_125 -> V_143 >> 19 ) & 0x07 ;
int V_16 = ( V_125 -> V_143 >> 24 ) & 0xff ;
int V_147 = ( V_125 -> V_143 >> 22 ) & 1 ;
int V_142 ;
unsigned short V_154 , V_155 , V_140 , V_141 ;
V_154 = V_134 -> V_11 . integer . V_11 [ 0 ] & V_16 ;
V_155 = V_134 -> V_11 . integer . V_11 [ 1 ] & V_16 ;
if ( V_147 ) {
V_154 = V_16 - V_154 ;
V_155 = V_16 - V_155 ;
}
V_154 <<= V_152 ;
V_155 <<= V_153 ;
F_45 ( & V_2 -> V_15 ) ;
V_140 = F_14 ( V_2 , V_150 ) ;
V_141 = F_14 ( V_2 , V_151 ) ;
V_154 = ( V_140 & ~ ( V_16 << V_152 ) ) | V_154 ;
V_155 = ( V_141 & ~ ( V_16 << V_153 ) ) | V_155 ;
V_142 = V_154 != V_140 || V_155 != V_141 ;
F_8 ( V_2 , V_150 , V_154 ) ;
F_8 ( V_2 , V_151 , V_155 ) ;
F_46 ( & V_2 -> V_15 ) ;
return V_142 ;
}
static void F_72 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_64 ( V_125 ) ;
V_2 -> V_86 = NULL ;
V_2 -> V_88 = NULL ;
}
static int T_4 F_73 ( struct V_1 * V_2 )
{
struct V_156 * V_84 ;
struct V_124 * V_157 ;
unsigned int V_158 ;
int V_115 ;
if ( F_23 ( ! V_2 || ! V_2 -> V_84 ) )
return - V_56 ;
V_84 = V_2 -> V_84 ;
strcpy ( V_84 -> V_159 , L_3 ) ;
for ( V_158 = 0 ; V_158 < F_74 ( V_160 ) ; V_158 ++ ) {
if ( ( V_115 = F_75 ( V_84 , V_157 = F_76 ( & V_160 [ V_158 ] , V_2 ) ) ) < 0 )
return V_115 ;
switch ( V_158 ) {
case 0 :
case 1 : V_157 -> V_161 = F_72 ; break;
}
}
return 0 ;
}
static void F_77 ( struct V_162 * V_163 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = V_163 -> V_73 ;
unsigned char V_166 ;
V_166 = V_2 -> V_167 & 0x0f ;
F_78 ( V_165 , L_11 ,
V_2 -> V_167 & 0x80 ? L_12 : L_13 ) ;
F_78 ( V_165 , L_14 ,
V_166 == 0x00 ? L_15 :
V_166 == 0x01 ? L_16 :
V_166 == 0x02 ? L_17 :
V_166 == 0x03 ? L_18 : L_19 ) ;
V_166 = V_2 -> V_168 & 0x0f ;
F_78 ( V_165 , L_20 ,
V_166 == 0x00 ? L_15 :
V_166 == 0x01 ? L_16 :
V_166 == 0x02 ? L_17 :
V_166 == 0x03 ? L_18 : L_19 ) ;
V_166 = V_2 -> V_169 & 0x03 ;
F_78 ( V_165 , L_21 ,
V_166 == 0x00 ? L_22 :
V_166 == 0x01 ? L_23 : L_24 ) ;
V_166 = V_2 -> V_170 ;
F_78 ( V_165 , L_25 , V_166 & 0x01 ? L_13 : L_12 ) ;
F_78 ( V_165 , L_26 , V_166 & 0x02 ? L_13 : L_12 ) ;
F_78 ( V_165 , L_27 , V_166 & 0x04 ? L_13 : L_12 ) ;
}
static void T_4 F_79 ( struct V_1 * V_2 )
{
struct V_162 * V_163 ;
if ( ! F_80 ( V_2 -> V_84 , L_28 , & V_163 ) )
F_81 ( V_163 , V_2 , F_77 ) ;
}
static int T_4 F_82 ( struct V_1 * V_2 )
{
struct V_171 * V_172 ;
V_2 -> V_171 = V_172 = F_83 () ;
if ( ! V_172 ) {
F_84 ( V_67 L_29 ) ;
return - V_173 ;
}
F_85 ( V_172 , L_30 ) ;
F_86 ( V_172 , L_31 , F_87 ( V_2 -> V_123 ) ) ;
F_88 ( V_172 , & V_2 -> V_123 -> V_174 ) ;
V_172 -> V_175 = V_2 -> V_176 ;
F_89 ( V_172 ) ;
F_75 ( V_2 -> V_84 , F_76 ( & V_177 , V_2 ) ) ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_171 ) {
F_91 ( V_2 -> V_171 ) ;
V_2 -> V_171 = NULL ;
}
}
static inline int F_82 ( struct V_1 * V_2 ) { return - V_178 ; }
static inline void F_90 ( struct V_1 * V_2 ) { }
static int F_92 ( struct V_1 * V_2 )
{
F_90 ( V_2 ) ;
F_93 ( V_2 -> V_123 , 0x40 , V_2 -> V_5 ) ;
F_93 ( V_2 -> V_123 , 0x48 , V_2 -> V_9 ) ;
if ( V_2 -> V_57 >= 0 )
F_94 ( V_2 -> V_57 , V_2 ) ;
F_95 ( V_2 -> V_179 ) ;
F_95 ( V_2 -> V_180 ) ;
F_96 ( V_2 -> V_123 ) ;
F_97 ( V_2 -> V_123 ) ;
F_98 ( V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_181 * V_112 )
{
struct V_1 * V_2 = V_112 -> V_182 ;
return F_92 ( V_2 ) ;
}
static int T_4 F_100 ( struct V_156 * V_84 ,
struct V_183 * V_123 ,
int V_184 ,
int V_185 ,
struct V_1 * * V_186 )
{
struct V_1 * V_2 ;
unsigned int V_187 , V_188 ;
int V_115 ;
static struct V_189 V_190 = {
. V_191 = F_99 ,
} ;
* V_186 = NULL ;
if ( ( V_115 = F_101 ( V_123 ) ) < 0 )
return V_115 ;
if ( F_102 ( V_123 , F_103 ( 24 ) ) < 0 ||
F_104 ( V_123 , F_103 ( 24 ) ) < 0 ) {
F_29 ( V_67 L_32 ) ;
F_97 ( V_123 ) ;
return - V_192 ;
}
V_2 = F_105 ( sizeof( * V_2 ) , V_193 ) ;
if ( V_2 == NULL ) {
F_97 ( V_123 ) ;
return - V_173 ;
}
F_106 ( & V_2 -> V_15 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_123 = V_123 ;
V_2 -> V_57 = - 1 ;
if ( ( V_115 = F_107 ( V_123 , L_3 ) ) < 0 ) {
F_98 ( V_2 ) ;
F_97 ( V_123 ) ;
return V_115 ;
}
V_2 -> V_194 = F_108 ( V_123 , 0 ) ;
V_2 -> V_195 = F_108 ( V_123 , 1 ) ;
V_2 -> V_196 = F_108 ( V_123 , 2 ) ;
V_2 -> V_197 = F_108 ( V_123 , 3 ) ;
V_2 -> V_176 = F_108 ( V_123 , 4 ) ;
if ( F_109 ( V_123 -> V_57 , F_28 , V_198 ,
V_199 , V_2 ) ) {
F_29 ( V_67 L_33 , V_123 -> V_57 ) ;
F_92 ( V_2 ) ;
return - V_200 ;
}
V_2 -> V_57 = V_123 -> V_57 ;
F_110 ( V_123 , 0x40 , & V_187 ) ;
F_110 ( V_123 , 0x48 , & V_188 ) ;
V_201 &= ~ 0x0f ;
V_187 &= ~ 0x0f ;
V_188 &= ~ 0x0f ;
if ( ! V_187 ) {
V_187 = V_201 ;
V_201 += 0x10 ;
F_29 ( V_202 L_34 , V_187 ) ;
}
if ( ! V_188 ) {
V_188 = V_201 ;
V_201 += 0x10 ;
F_29 ( V_202 L_35 , V_188 ) ;
}
F_93 ( V_123 , 0x40 , V_187 ) ;
F_93 ( V_123 , 0x48 , V_188 ) ;
if ( ( V_2 -> V_179 = F_111 ( V_187 , 0x10 , L_36 ) ) == NULL ) {
F_92 ( V_2 ) ;
F_29 ( V_67 L_37 , V_187 , V_187 + 0x10 - 1 ) ;
return - V_200 ;
}
if ( ( V_2 -> V_180 = F_111 ( V_188 , 0x10 , L_38 ) ) == NULL ) {
F_92 ( V_2 ) ;
F_29 ( V_67 L_39 , V_188 , V_188 + 0x10 - 1 ) ;
return - V_200 ;
}
F_110 ( V_123 , 0x40 , & V_2 -> V_5 ) ;
F_110 ( V_123 , 0x48 , & V_2 -> V_9 ) ;
V_2 -> V_5 &= ~ 0x0f ;
V_2 -> V_9 &= ~ 0x0f ;
F_93 ( V_123 , 0x40 , V_2 -> V_5 | 9 ) ;
F_93 ( V_123 , 0x48 , V_2 -> V_9 | 9 ) ;
F_3 ( V_203 , F_9 ( V_2 , V_204 ) ) ;
F_10 ( 100 ) ;
F_3 ( 0 , F_9 ( V_2 , V_204 ) ) ;
F_10 ( 100 ) ;
F_3 ( V_205 | V_206 | ( V_184 ? V_207 : 0 ) , F_9 ( V_2 , V_204 ) ) ;
F_15 ( F_9 ( V_2 , V_60 ) ) ;
#if 1
F_11 ( V_2 , V_208 , 0 ) ;
#else
F_11 ( V_2 , V_208 , 0x40 ) ;
#endif
F_11 ( V_2 , V_54 , V_2 -> V_53 = 0 ) ;
F_3 ( V_2 -> V_65 = ~ ( V_209 | V_210 | V_211 ) , F_9 ( V_2 , V_66 ) ) ;
F_15 ( F_9 ( V_2 , V_60 ) ) ;
F_11 ( V_2 , V_36 , 0 ) ;
F_11 ( V_2 , V_212 , 0 ) ;
F_11 ( V_2 , V_213 , 0 ) ;
F_19 ( V_2 , V_34 , 8000 ) ;
F_11 ( V_2 , V_214 , V_2 -> V_167 = 0x80 ) ;
F_11 ( V_2 , V_215 , V_2 -> V_168 = 0x00 ) ;
F_11 ( V_2 , V_216 , V_2 -> V_170 = 0x05 ) ;
F_11 ( V_2 , V_217 , V_2 -> V_169 = 0x00 ) ;
F_11 ( V_2 , V_48 , ( 8000 * 65536 / V_46 ) & 0xff ) ;
F_11 ( V_2 , V_47 , ( ( 8000 * 65536 / V_46 ) >> 8 ) & 0xff ) ;
F_11 ( V_2 , V_135 , V_185 ? 0xd0 : 0xc0 ) ;
F_11 ( V_2 , V_137 , 0xc0 ) ;
F_11 ( V_2 , V_218 , 0x9f ) ;
F_11 ( V_2 , V_219 , 0x9f ) ;
F_11 ( V_2 , V_220 , 0x9f ) ;
F_11 ( V_2 , V_221 , 0x9f ) ;
F_11 ( V_2 , V_222 , 0x9f ) ;
F_11 ( V_2 , V_223 , 0x9f ) ;
F_11 ( V_2 , V_224 , 0x8f ) ;
F_11 ( V_2 , V_225 , 0x9f ) ;
F_11 ( V_2 , V_226 , 0x9f ) ;
F_11 ( V_2 , V_227 , 0x9f ) ;
F_11 ( V_2 , V_228 , 0x9f ) ;
F_11 ( V_2 , V_82 , 0x9f ) ;
F_11 ( V_2 , V_83 , 0x9f ) ;
F_11 ( V_2 , V_229 , 0xbf ) ;
F_11 ( V_2 , V_230 , 0xbf ) ;
F_11 ( V_2 , V_231 , 0xfc ) ;
#if 0
snd_sonicvibes_debug(sonic);
#endif
V_2 -> V_232 = F_16 ( V_2 , V_233 ) ;
if ( ( V_115 = F_112 ( V_84 , V_234 , V_2 , & V_190 ) ) < 0 ) {
F_92 ( V_2 ) ;
return V_115 ;
}
F_79 ( V_2 ) ;
F_113 ( V_84 , & V_123 -> V_174 ) ;
* V_186 = V_2 ;
return 0 ;
}
static int F_114 ( struct V_235 * V_236 )
{
struct V_1 * V_2 = V_236 -> V_73 ;
F_3 ( V_2 -> V_65 &= ~ V_237 , F_9 ( V_2 , V_66 ) ) ;
return 0 ;
}
static void F_115 ( struct V_235 * V_236 )
{
struct V_1 * V_2 = V_236 -> V_73 ;
F_3 ( V_2 -> V_65 |= V_237 , F_9 ( V_2 , V_66 ) ) ;
}
static int T_4 F_116 ( struct V_1 * V_2 ,
struct V_238 * V_72 )
{
struct V_235 * V_236 = V_72 -> V_73 ;
struct V_156 * V_84 = V_2 -> V_84 ;
struct V_239 * V_240 ;
unsigned int V_158 ;
int V_115 ;
V_236 -> V_73 = V_2 ;
V_236 -> V_241 = F_114 ;
V_236 -> V_242 = F_115 ;
V_240 = & V_72 -> V_243 [ V_244 ] ;
for ( V_158 = 0 ; V_158 < F_74 ( V_245 ) ; V_158 ++ )
if ( ( V_115 = F_75 ( V_84 , F_76 ( & V_245 [ V_158 ] , V_2 ) ) ) < 0 )
return V_115 ;
return 0 ;
}
static int T_4 F_117 ( struct V_183 * V_123 ,
const struct V_246 * V_247 )
{
static int V_174 ;
struct V_156 * V_84 ;
struct V_1 * V_2 ;
struct V_238 * V_248 ;
struct V_249 * V_250 ;
int V_158 , V_115 ;
if ( V_174 >= V_251 )
return - V_252 ;
if ( ! V_53 [ V_174 ] ) {
V_174 ++ ;
return - V_253 ;
}
V_115 = F_118 ( V_254 [ V_174 ] , V_87 [ V_174 ] , V_255 , 0 , & V_84 ) ;
if ( V_115 < 0 )
return V_115 ;
for ( V_158 = 0 ; V_158 < 5 ; V_158 ++ ) {
if ( F_108 ( V_123 , V_158 ) == 0 ||
! ( F_119 ( V_123 , V_158 ) & V_256 ) ) {
F_120 ( V_84 ) ;
return - V_252 ;
}
}
if ( ( V_115 = F_100 ( V_84 , V_123 ,
V_184 [ V_174 ] ? 1 : 0 ,
V_185 [ V_174 ] ? 1 : 0 ,
& V_2 ) ) < 0 ) {
F_120 ( V_84 ) ;
return V_115 ;
}
strcpy ( V_84 -> V_257 , L_40 ) ;
strcpy ( V_84 -> V_258 , L_3 ) ;
sprintf ( V_84 -> V_259 , L_41 ,
V_84 -> V_258 ,
V_2 -> V_232 ,
( unsigned long long ) F_108 ( V_123 , 1 ) ,
V_2 -> V_57 ) ;
if ( ( V_115 = F_57 ( V_2 , 0 , NULL ) ) < 0 ) {
F_120 ( V_84 ) ;
return V_115 ;
}
if ( ( V_115 = F_73 ( V_2 ) ) < 0 ) {
F_120 ( V_84 ) ;
return V_115 ;
}
if ( ( V_115 = F_121 ( V_84 , 0 , V_260 ,
V_2 -> V_197 ,
V_261 |
V_262 ,
- 1 , & V_248 ) ) < 0 ) {
F_120 ( V_84 ) ;
return V_115 ;
}
F_116 ( V_2 , V_248 ) ;
if ( ( V_115 = F_122 ( V_84 , V_2 -> V_196 ,
V_2 -> V_196 + 2 ,
V_263 , 1 , & V_250 ) ) < 0 ) {
F_120 ( V_84 ) ;
return V_115 ;
}
if ( ( V_115 = F_123 ( V_250 , 0 , 1 , NULL ) ) < 0 ) {
F_120 ( V_84 ) ;
return V_115 ;
}
F_82 ( V_2 ) ;
if ( ( V_115 = F_124 ( V_84 ) ) < 0 ) {
F_120 ( V_84 ) ;
return V_115 ;
}
F_125 ( V_123 , V_84 ) ;
V_174 ++ ;
return 0 ;
}
static void T_5 F_126 ( struct V_183 * V_123 )
{
F_120 ( F_127 ( V_123 ) ) ;
F_125 ( V_123 , NULL ) ;
}
static int T_6 F_128 ( void )
{
return F_129 ( & V_257 ) ;
}
static void T_7 F_130 ( void )
{
F_131 ( & V_257 ) ;
}
