static void F_1 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
T_1 V_11 [ 2 ] ;
int V_12 ;
V_11 [ 0 ] = F_2 ( F_3 ( V_3 & 2 ? 0xC : 0x03 , V_3 ) | V_13 ) ;
V_11 [ 1 ] = F_2 ( V_4 ) ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 4 ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_1 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
T_1 V_11 [ 2 ] ;
int V_12 ;
int V_19 ;
V_19 = 1 << ( V_3 & 3 ) ;
V_11 [ 0 ] = F_2 ( F_3 ( V_19 , V_3 ) | V_13 ) ;
V_11 [ 1 ] = V_4 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 3 ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_1 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned V_20 ,
T_2 * V_21 , unsigned V_22 )
{
struct V_5 * V_6 ;
struct V_8 * V_9 ;
T_1 * V_11 = ( T_1 * ) V_2 -> V_23 ;
T_2 * V_24 = V_2 -> V_25 ;
int V_12 ;
V_11 [ 0 ] = F_2 ( V_20 | V_26 ) ;
if ( V_2 -> V_17 -> V_27 -> V_28 & V_29 ) {
V_9 = & V_2 -> V_30 ;
V_6 = V_2 -> V_31 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 2 ;
V_6 ++ ;
V_6 -> V_14 = NULL ;
V_6 -> V_15 = V_24 ;
V_6 -> V_16 = V_22 ;
} else {
V_9 = & V_2 -> V_10 ;
V_6 = & V_2 -> V_7 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = V_24 ;
V_6 -> V_16 = V_22 + 2 ;
}
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_2 ) ;
else if ( V_2 -> V_17 -> V_27 -> V_28 & V_29 )
memcpy ( V_21 , V_24 , V_22 ) ;
else
memcpy ( V_21 , V_24 + 2 , V_22 ) ;
}
static unsigned F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_21 [ 1 ] ;
F_7 ( V_2 , F_3 ( 1 << ( V_3 & 3 ) , V_3 ) , V_21 , 1 ) ;
return V_21 [ 0 ] ;
}
static unsigned F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_32 = 0 ;
F_7 ( V_2 , F_3 ( V_3 & 2 ? 0xC : 0x3 , V_3 ) , ( T_2 * ) & V_32 , 2 ) ;
return F_10 ( V_32 ) ;
}
static unsigned F_11 ( struct V_1 * V_2 , unsigned V_3 )
{
T_3 V_32 = 0 ;
F_12 ( V_3 & 3 ) ;
F_7 ( V_2 , F_3 ( 0xf , V_3 ) , ( T_2 * ) & V_32 , 4 ) ;
return F_13 ( V_32 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_20 )
{
F_1 ( V_2 , V_33 , V_20 ) ;
F_15 ( 1 ) ;
F_1 ( V_2 , V_33 , 0 ) ;
F_15 ( 1 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned V_34 )
{
unsigned V_35 ;
F_17 ( V_2 , V_36 , V_2 -> V_18 , L_3 , V_34 ) ;
V_35 = F_9 ( V_2 , V_37 ) ;
V_35 &= ~ V_38 ;
V_35 |= V_34 ;
F_1 ( V_2 , V_37 , V_35 ) ;
}
static int F_18 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
int V_41 ;
F_20 ( & V_2 -> V_42 ) ;
F_16 ( V_2 , V_43 ) ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ )
F_6 ( V_2 , F_21 ( V_41 ) , V_40 -> V_45 [ V_41 ] ) ;
if ( ! F_22 ( V_40 ) )
F_16 ( V_2 , V_46 ) ;
F_23 ( & V_2 -> V_42 ) ;
return 0 ;
}
static void F_24 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
int V_41 ;
F_20 ( & V_2 -> V_42 ) ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ )
V_40 -> V_45 [ V_41 ] = F_8 ( V_2 , F_21 ( V_41 ) ) ;
F_23 ( & V_2 -> V_42 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_18 ;
if ( V_2 -> V_47 & V_48 ) {
F_24 ( V_40 ) ;
if ( F_26 ( V_40 -> V_45 ) )
return;
F_5 ( V_2 -> V_18 , L_4 ,
V_40 -> V_45 ) ;
}
F_27 ( V_40 ) ;
F_18 ( V_40 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_2 * V_49 , unsigned V_16 )
{
struct V_5 * V_6 = V_2 -> V_31 ;
struct V_8 * V_9 = & V_2 -> V_30 ;
T_2 V_11 [ 1 ] ;
int V_12 ;
F_17 ( V_2 , V_50 , V_2 -> V_18 ,
L_5 , V_51 , V_16 , V_49 ) ;
V_11 [ 0 ] = V_52 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 1 ;
V_6 ++ ;
V_6 -> V_15 = V_49 ;
V_6 -> V_14 = NULL ;
V_6 -> V_16 = V_16 ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_6 , V_51 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_53 )
{
F_30 ( V_2 -> V_18 ,
L_7 ,
V_53 [ 4 ] , V_53 [ 5 ] , V_53 [ 6 ] , V_53 [ 7 ] ,
V_53 [ 8 ] , V_53 [ 9 ] , V_53 [ 10 ] , V_53 [ 11 ] ,
V_53 [ 12 ] , V_53 [ 13 ] , V_53 [ 14 ] , V_53 [ 15 ] ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
unsigned V_56 ;
unsigned V_57 ;
unsigned V_58 ;
T_4 V_59 ;
T_2 * V_53 ;
V_56 = F_8 ( V_2 , V_60 ) ;
F_17 ( V_2 , V_50 , V_2 -> V_18 ,
L_8 , V_51 , V_56 ) ;
for (; V_56 != 0 ; V_56 -- ) {
V_59 = F_11 ( V_2 , V_61 ) ;
V_58 = V_59 & 0xffff ;
V_57 = ( V_59 >> 16 ) & 0xfff ;
F_17 ( V_2 , V_50 , V_2 -> V_18 ,
L_9 , V_58 , V_57 ) ;
F_1 ( V_2 , V_62 , V_63 | 0x00 ) ;
F_1 ( V_2 , V_64 ,
V_2 -> V_65 | V_66 | V_67 ) ;
if ( V_57 > 4 ) {
unsigned int V_68 ;
V_57 -= 4 ;
V_68 = F_32 ( V_57 , 4 ) ;
V_55 = F_33 ( V_2 -> V_18 , V_68 ) ;
if ( V_55 ) {
V_53 = F_34 ( V_55 , V_57 ) - 8 ;
F_28 ( V_2 , V_53 , V_68 + 8 ) ;
if ( F_35 ( V_2 ) )
F_29 ( V_2 , V_53 ) ;
V_55 -> V_69 = F_36 ( V_55 , V_2 -> V_18 ) ;
F_37 ( V_55 ) ;
V_2 -> V_18 -> V_70 . V_71 ++ ;
V_2 -> V_18 -> V_70 . V_72 += V_57 ;
}
}
F_1 ( V_2 , V_64 , V_2 -> V_65 ) ;
}
}
static T_5 F_38 ( int V_73 , void * V_74 )
{
struct V_1 * V_2 = V_74 ;
unsigned V_75 ;
unsigned V_76 = 0 ;
F_20 ( & V_2 -> V_42 ) ;
V_75 = F_9 ( V_2 , V_77 ) ;
F_17 ( V_2 , V_78 , V_2 -> V_18 ,
L_10 , V_51 , V_75 ) ;
if ( V_75 & V_79 )
V_76 |= V_79 ;
if ( V_75 & V_80 ) {
T_6 V_35 = F_9 ( V_2 , V_37 ) ;
V_35 &= ~ V_81 ;
F_1 ( V_2 , V_37 , V_35 | V_82 ) ;
V_76 |= V_80 ;
}
if ( V_75 & V_83 )
V_76 |= V_83 ;
if ( V_75 & V_84 ) {
V_76 |= V_84 ;
V_2 -> V_85 = F_9 ( V_2 , V_86 ) ;
F_17 ( V_2 , V_78 , V_2 -> V_18 ,
L_11 , V_51 , V_2 -> V_85 ) ;
}
if ( V_75 & V_87 )
V_76 |= V_87 ;
if ( V_75 & V_88 ) {
F_39 ( & V_2 -> V_17 -> V_40 , L_12 , V_51 ) ;
V_76 |= V_88 ;
}
F_1 ( V_2 , V_77 , V_76 ) ;
if ( V_75 & V_87 ) {
F_31 ( V_2 ) ;
}
if ( V_75 & V_83 ) {
struct V_89 * V_90 = & V_2 -> V_91 ;
F_1 ( V_2 , V_92 , V_90 -> V_93 [ 0 ] ) ;
F_1 ( V_2 , V_94 , V_90 -> V_93 [ 1 ] ) ;
F_1 ( V_2 , V_95 , V_90 -> V_93 [ 2 ] ) ;
F_1 ( V_2 , V_96 , V_90 -> V_93 [ 3 ] ) ;
F_1 ( V_2 , V_97 , V_90 -> V_98 ) ;
F_1 ( V_2 , V_99 , V_90 -> V_100 ) ;
}
F_23 ( & V_2 -> V_42 ) ;
if ( V_75 & V_79 )
F_40 ( & V_2 -> V_101 ) ;
if ( V_75 & V_84 )
F_41 ( V_2 -> V_18 ) ;
return V_102 ;
}
static inline unsigned F_42 ( unsigned V_16 )
{
return F_32 ( V_16 + 4 , 4 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_54 * V_103 , bool V_73 )
{
struct V_5 * V_6 = V_2 -> V_31 ;
struct V_8 * V_9 = & V_2 -> V_30 ;
unsigned V_104 = 0 ;
int V_12 ;
F_17 ( V_2 , V_105 , V_2 -> V_18 , L_13 ,
V_51 , V_103 , V_103 -> V_16 , V_103 -> V_106 , V_73 ) ;
V_104 = V_2 -> V_104 ++ ;
V_104 &= V_107 ;
if ( V_73 )
V_104 |= V_108 ;
V_2 -> V_109 . V_11 [ 1 ] = V_110 ;
V_2 -> V_109 . V_111 [ 1 ] = F_2 ( V_104 ) ;
V_2 -> V_109 . V_111 [ 2 ] = F_2 ( V_103 -> V_16 ) ;
V_6 -> V_14 = & V_2 -> V_109 . V_11 [ 1 ] ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 5 ;
V_6 ++ ;
V_6 -> V_14 = V_103 -> V_106 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = F_32 ( V_103 -> V_16 , 4 ) ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_6 , V_51 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_54 * V_11 )
{
struct V_39 * V_40 = V_2 -> V_18 ;
V_40 -> V_70 . V_112 += V_11 -> V_16 ;
V_40 -> V_70 . V_113 ++ ;
F_45 ( V_11 ) ;
}
static void F_46 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = F_47 ( V_115 , struct V_1 , V_116 ) ;
struct V_54 * V_11 ;
bool V_117 = F_48 ( & V_2 -> V_118 ) ;
F_20 ( & V_2 -> V_42 ) ;
while ( ! V_117 ) {
V_11 = F_49 ( & V_2 -> V_118 ) ;
V_117 = F_48 ( & V_2 -> V_118 ) ;
if ( V_11 != NULL ) {
F_1 ( V_2 , V_64 , V_2 -> V_65 | V_66 ) ;
F_43 ( V_2 , V_11 , V_117 ) ;
F_1 ( V_2 , V_64 , V_2 -> V_65 ) ;
F_1 ( V_2 , V_119 , V_120 ) ;
F_44 ( V_2 , V_11 ) ;
}
}
F_23 ( & V_2 -> V_42 ) ;
}
static int F_50 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
F_20 ( & V_2 -> V_42 ) ;
F_17 ( V_2 , V_121 , V_2 -> V_18 , L_14 ) ;
F_16 ( V_2 , V_43 ) ;
F_14 ( V_2 , V_122 ) ;
F_1 ( V_2 , V_123 , ( V_124 |
V_125 |
V_126 |
V_127 ) ) ;
F_1 ( V_2 , V_128 , V_129 ) ;
F_1 ( V_2 , V_99 , ( V_130 |
V_131 |
V_132 |
V_133 |
V_134 ) ) ;
F_1 ( V_2 , V_97 , V_135 ) ;
F_1 ( V_2 , V_136 , 1000 ) ;
F_1 ( V_2 , V_137 , 4096 ) ;
F_1 ( V_2 , V_138 , 10 ) ;
V_2 -> V_65 = ( V_139 |
V_140 |
V_141 ) ;
F_1 ( V_2 , V_64 , V_2 -> V_65 ) ;
#define F_51 (IRQ_LCI | \
IRQ_TXI | \
IRQ_RXI | \
IRQ_SPIBEI | \
IRQ_TXPSI | \
IRQ_RXPSI)
V_2 -> V_142 = F_51 ;
F_1 ( V_2 , V_77 , F_51 ) ;
F_1 ( V_2 , V_143 , F_51 ) ;
F_52 ( V_2 -> V_18 ) ;
F_17 ( V_2 , V_121 , V_2 -> V_18 , L_15 ) ;
F_23 ( & V_2 -> V_42 ) ;
return 0 ;
}
static int F_53 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
F_54 ( V_2 , V_144 , V_40 , L_16 ) ;
F_55 ( V_40 ) ;
F_20 ( & V_2 -> V_42 ) ;
F_1 ( V_2 , V_143 , 0x0000 ) ;
F_1 ( V_2 , V_77 , 0xffff ) ;
F_23 ( & V_2 -> V_42 ) ;
F_56 ( & V_2 -> V_116 ) ;
F_56 ( & V_2 -> V_145 ) ;
F_20 ( & V_2 -> V_42 ) ;
F_1 ( V_2 , V_99 , 0x0000 ) ;
F_1 ( V_2 , V_123 , 0x0000 ) ;
F_16 ( V_2 , V_46 ) ;
F_23 ( & V_2 -> V_42 ) ;
while ( ! F_48 ( & V_2 -> V_118 ) ) {
struct V_54 * V_11 = F_49 ( & V_2 -> V_118 ) ;
F_17 ( V_2 , V_144 , V_2 -> V_18 ,
L_17 , V_51 , V_11 ) ;
F_45 ( V_11 ) ;
}
return 0 ;
}
static T_7 F_57 ( struct V_54 * V_55 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
unsigned V_146 = F_42 ( V_55 -> V_16 ) ;
T_7 V_12 = V_147 ;
F_17 ( V_2 , V_105 , V_2 -> V_18 ,
L_18 , V_51 , V_55 , V_55 -> V_16 , V_55 -> V_106 ) ;
F_58 ( & V_2 -> V_148 ) ;
if ( V_146 > V_2 -> V_85 ) {
F_55 ( V_40 ) ;
V_12 = V_149 ;
} else {
V_2 -> V_85 -= V_146 ;
F_59 ( & V_2 -> V_118 , V_55 ) ;
}
F_60 ( & V_2 -> V_148 ) ;
F_61 ( & V_2 -> V_116 ) ;
return V_12 ;
}
static void F_62 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = F_47 ( V_115 , struct V_1 , V_145 ) ;
F_20 ( & V_2 -> V_42 ) ;
F_1 ( V_2 , V_99 , 0x00 ) ;
F_23 ( & V_2 -> V_42 ) ;
}
static void F_63 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
struct V_89 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
if ( V_40 -> V_28 & V_150 ) {
V_91 . V_100 = V_151 | V_152 ;
} else if ( V_40 -> V_28 & V_153 ) {
V_91 . V_100 = ( V_154 | V_151 |
V_130 | V_155 ) ;
} else if ( V_40 -> V_28 & V_156 && ! F_64 ( V_40 ) ) {
struct V_157 * V_158 ;
T_4 V_159 ;
F_65 (ha, dev) {
V_159 = F_66 ( V_44 , V_158 -> V_160 ) ;
V_159 >>= ( 32 - 6 ) ;
V_91 . V_93 [ V_159 >> 4 ] |= ( 1 << ( V_159 & 0xf ) ) ;
}
V_91 . V_100 = V_154 | V_130 ;
} else {
V_91 . V_100 = V_130 ;
}
V_91 . V_100 |= ( V_133 |
V_132 |
V_134 |
V_131 ) ;
V_91 . V_98 |= V_135 ;
F_58 ( & V_2 -> V_148 ) ;
if ( memcmp ( & V_91 , & V_2 -> V_91 , sizeof( V_91 ) ) != 0 ) {
memcpy ( & V_2 -> V_91 , & V_91 , sizeof( V_2 -> V_91 ) ) ;
F_61 ( & V_2 -> V_145 ) ;
}
F_60 ( & V_2 -> V_148 ) ;
}
static int F_67 ( struct V_39 * V_40 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
if ( F_22 ( V_40 ) )
return - V_163 ;
if ( ! F_26 ( V_162 -> V_164 ) )
return - V_165 ;
memcpy ( V_40 -> V_45 , V_162 -> V_164 , V_44 ) ;
return F_18 ( V_40 ) ;
}
static int F_68 ( struct V_39 * V_40 , struct V_166 * V_167 , int V_168 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
if ( ! F_22 ( V_40 ) )
return - V_169 ;
return F_69 ( & V_2 -> V_101 , F_70 ( V_167 ) , V_168 , NULL ) ;
}
static void F_71 ( struct V_39 * V_40 ,
struct V_170 * V_171 )
{
F_72 ( V_171 -> V_172 , L_19 , sizeof( V_171 -> V_172 ) ) ;
F_72 ( V_171 -> V_173 , L_20 , sizeof( V_171 -> V_173 ) ) ;
F_72 ( V_171 -> V_174 , F_73 ( V_40 -> V_40 . V_175 ) , sizeof( V_171 -> V_174 ) ) ;
}
static T_4 F_74 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
return V_2 -> V_176 ;
}
static void F_75 ( struct V_39 * V_40 , T_4 V_177 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
V_2 -> V_176 = V_177 ;
}
static int F_76 ( struct V_39 * V_40 ,
struct V_178 * V_168 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
F_77 ( & V_2 -> V_101 , V_168 ) ;
return 0 ;
}
static int F_78 ( struct V_39 * V_40 ,
const struct V_178 * V_168 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
return F_79 ( & V_2 -> V_101 , V_168 ) ;
}
static T_4 F_80 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
return F_81 ( & V_2 -> V_101 ) ;
}
static int F_82 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
return F_83 ( & V_2 -> V_101 ) ;
}
static void F_84 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = V_180 -> V_106 ;
unsigned V_4 ;
V_4 = F_9 ( V_2 , V_181 ) ;
V_180 -> V_182 = ( V_4 & V_183 ) ? 1 : 0 ;
V_180 -> V_184 = ( V_4 & V_185 ) ? 1 : 0 ;
V_180 -> V_186 = ( V_4 & V_187 ) ? 1 : 0 ;
}
static void F_85 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = V_180 -> V_106 ;
unsigned V_4 = V_188 ;
if ( V_180 -> V_189 )
V_4 |= V_190 ;
if ( V_180 -> V_191 )
V_4 |= V_192 ;
if ( V_180 -> V_184 )
V_4 |= V_185 ;
if ( V_180 -> V_186 )
V_4 |= V_187 ;
F_1 ( V_2 , V_181 , V_4 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_47 & V_48 ) )
return - V_193 ;
F_20 ( & V_2 -> V_42 ) ;
F_1 ( V_2 , V_181 , V_188 | V_187 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned V_4 = F_9 ( V_2 , V_181 ) ;
F_1 ( V_2 , V_181 , V_4 & ~ V_188 ) ;
F_23 ( & V_2 -> V_42 ) ;
}
static int F_88 ( struct V_39 * V_40 ,
struct V_194 * V_180 , T_2 * V_106 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
int V_195 = V_180 -> V_195 ;
int V_16 = V_180 -> V_16 ;
T_6 V_196 ;
if ( V_16 != 1 )
return - V_169 ;
if ( V_180 -> V_197 != V_198 )
return - V_169 ;
if ( F_86 ( V_2 ) )
return - V_193 ;
F_89 ( & V_2 -> V_199 , true ) ;
F_90 ( & V_2 -> V_199 , V_195 / 2 , & V_196 ) ;
if ( V_195 & 1 ) {
V_196 &= 0xff ;
V_196 |= * V_106 << 8 ;
} else {
V_196 &= 0xff00 ;
V_196 |= * V_106 ;
}
F_91 ( & V_2 -> V_199 , V_195 / 2 , V_196 ) ;
F_89 ( & V_2 -> V_199 , false ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_39 * V_40 ,
struct V_194 * V_180 , T_2 * V_106 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
int V_195 = V_180 -> V_195 ;
int V_16 = V_180 -> V_16 ;
if ( V_16 & 1 || V_195 & 1 )
return - V_169 ;
if ( F_86 ( V_2 ) )
return - V_193 ;
V_180 -> V_197 = V_198 ;
F_93 ( & V_2 -> V_199 , V_195 / 2 , ( T_1 * ) V_106 , V_16 / 2 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
return V_2 -> V_47 & V_48 ? 128 : 0 ;
}
static int F_95 ( int V_3 )
{
switch ( V_3 ) {
case V_200 :
return V_201 ;
case V_202 :
return V_203 ;
case V_204 :
return V_205 ;
case V_206 :
return V_207 ;
case V_208 :
return V_209 ;
case V_210 :
return V_211 ;
}
return 0x0 ;
}
static int F_96 ( struct V_39 * V_40 , int V_212 , int V_3 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
int V_213 ;
int V_214 ;
V_213 = F_95 ( V_3 ) ;
if ( ! V_213 )
return 0x0 ;
F_20 ( & V_2 -> V_42 ) ;
V_214 = F_9 ( V_2 , V_213 ) ;
F_23 ( & V_2 -> V_42 ) ;
return V_214 ;
}
static void F_97 ( struct V_39 * V_40 ,
int V_215 , int V_3 , int V_216 )
{
struct V_1 * V_2 = F_19 ( V_40 ) ;
int V_213 ;
V_213 = F_95 ( V_3 ) ;
if ( V_213 ) {
F_20 ( & V_2 -> V_42 ) ;
F_1 ( V_2 , V_213 , V_216 ) ;
F_23 ( & V_2 -> V_42 ) ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
unsigned V_217 = V_218 | V_219 ;
int V_12 = 0 ;
unsigned V_220 ;
V_220 = F_9 ( V_2 , V_221 ) ;
if ( ( V_220 & V_217 ) != V_217 ) {
F_99 ( V_2 -> V_18 , L_21 ) ;
return 0 ;
}
if ( V_220 & V_222 ) {
F_5 ( V_2 -> V_18 , L_22 ) ;
V_12 |= 1 ;
}
if ( V_220 & V_223 ) {
F_5 ( V_2 -> V_18 , L_23 ) ;
V_12 |= 2 ;
}
return 0 ;
}
static int F_100 ( struct V_224 * V_40 )
{
struct V_1 * V_2 = F_101 ( V_40 ) ;
struct V_39 * V_18 = V_2 -> V_18 ;
if ( F_22 ( V_18 ) ) {
F_102 ( V_18 ) ;
F_53 ( V_18 ) ;
}
return 0 ;
}
static int F_103 ( struct V_224 * V_40 )
{
struct V_1 * V_2 = F_101 ( V_40 ) ;
struct V_39 * V_18 = V_2 -> V_18 ;
if ( F_22 ( V_18 ) ) {
F_50 ( V_18 ) ;
F_104 ( V_18 ) ;
}
return 0 ;
}
static int F_105 ( struct V_225 * V_226 )
{
struct V_39 * V_227 ;
struct V_1 * V_2 ;
int V_12 ;
unsigned V_228 ;
int V_229 ;
V_227 = F_106 ( sizeof( struct V_1 ) ) ;
if ( ! V_227 )
return - V_230 ;
V_226 -> V_231 = 8 ;
V_2 = F_19 ( V_227 ) ;
V_2 -> V_18 = V_227 ;
V_2 -> V_17 = V_226 ;
V_2 -> V_85 = 6144 ;
V_229 = F_107 ( V_226 -> V_40 . V_232 , L_24 ,
0 , NULL ) ;
if ( V_229 == - V_233 ) {
V_12 = V_229 ;
goto V_234;
}
V_2 -> V_229 = V_229 ;
if ( F_108 ( V_229 ) ) {
V_12 = F_109 ( & V_226 -> V_40 , V_229 ,
V_235 , L_25 ) ;
if ( V_12 ) {
F_39 ( & V_226 -> V_40 , L_26 ) ;
goto V_234;
}
}
V_2 -> V_236 = F_110 ( & V_226 -> V_40 , L_27 ) ;
if ( F_111 ( V_2 -> V_236 ) ) {
V_12 = F_112 ( V_2 -> V_236 ) ;
goto V_237;
}
V_12 = F_113 ( V_2 -> V_236 ) ;
if ( V_12 ) {
F_39 ( & V_226 -> V_40 , L_28 ,
V_12 ) ;
goto V_237;
}
V_2 -> V_238 = F_110 ( & V_226 -> V_40 , L_29 ) ;
if ( F_111 ( V_2 -> V_238 ) ) {
V_12 = F_112 ( V_2 -> V_238 ) ;
goto V_239;
}
V_12 = F_113 ( V_2 -> V_238 ) ;
if ( V_12 ) {
F_39 ( & V_226 -> V_40 , L_30 ,
V_12 ) ;
goto V_239;
}
if ( F_108 ( V_229 ) ) {
F_114 ( 10000 , 11000 ) ;
F_115 ( V_229 , 1 ) ;
}
F_116 ( & V_2 -> V_42 ) ;
F_117 ( & V_2 -> V_148 ) ;
F_118 ( & V_2 -> V_116 , F_46 ) ;
F_118 ( & V_2 -> V_145 , F_62 ) ;
F_119 ( & V_2 -> V_10 ) ;
F_120 ( & V_2 -> V_7 , & V_2 -> V_10 ) ;
F_119 ( & V_2 -> V_30 ) ;
F_120 ( & V_2 -> V_31 [ 0 ] , & V_2 -> V_30 ) ;
F_120 ( & V_2 -> V_31 [ 1 ] , & V_2 -> V_30 ) ;
V_2 -> V_199 . V_106 = V_2 ;
V_2 -> V_199 . V_240 = V_241 ;
V_2 -> V_199 . V_242 = F_84 ;
V_2 -> V_199 . V_243 = F_85 ;
V_2 -> V_101 . V_40 = V_227 ;
V_2 -> V_101 . V_244 = 1 ,
V_2 -> V_101 . V_245 = 1 ;
V_2 -> V_101 . V_246 = 0xf ;
V_2 -> V_101 . V_247 = F_96 ;
V_2 -> V_101 . V_248 = F_97 ;
F_121 ( & V_226 -> V_40 , L_31 , V_176 ) ;
V_2 -> V_176 = F_122 ( V_176 , ( V_249 |
V_250 |
V_251 ) ) ;
F_123 ( & V_2 -> V_118 ) ;
V_227 -> V_252 = & V_253 ;
F_124 ( V_227 , & V_226 -> V_40 ) ;
F_125 ( V_226 , V_2 ) ;
V_227 -> V_254 = V_255 ;
V_227 -> V_256 = & V_257 ;
V_227 -> V_73 = V_226 -> V_73 ;
F_14 ( V_2 , V_258 ) ;
V_228 = F_9 ( V_2 , V_259 ) ;
if ( ( V_228 & ~ V_260 ) != V_261 ) {
F_39 ( & V_226 -> V_40 , L_32 ) ;
V_12 = - V_262 ;
goto V_263;
}
V_2 -> V_47 = F_9 ( V_2 , V_264 ) ;
F_98 ( V_2 ) ;
F_25 ( V_2 ) ;
V_12 = F_126 ( V_226 -> V_73 , NULL , F_38 ,
V_265 | V_266 ,
V_227 -> V_267 , V_2 ) ;
if ( V_12 < 0 ) {
F_39 ( & V_226 -> V_40 , L_33 ) ;
goto V_268;
}
V_12 = F_127 ( V_227 ) ;
if ( V_12 ) {
F_39 ( & V_226 -> V_40 , L_34 ) ;
goto V_269;
}
F_128 ( V_227 , L_35 ,
F_129 ( V_228 ) , V_227 -> V_45 , V_227 -> V_73 ,
V_2 -> V_47 & V_48 ? L_36 : L_37 ) ;
return 0 ;
V_269:
F_130 ( V_227 -> V_73 , V_2 ) ;
V_268:
if ( F_108 ( V_229 ) )
F_115 ( V_229 , 0 ) ;
V_263:
F_131 ( V_2 -> V_238 ) ;
V_239:
F_131 ( V_2 -> V_236 ) ;
V_237:
V_234:
F_132 ( V_227 ) ;
return V_12 ;
}
static int F_133 ( struct V_225 * V_226 )
{
struct V_1 * V_270 = F_134 ( V_226 ) ;
if ( F_135 ( V_270 ) )
F_121 ( & V_226 -> V_40 , L_38 ) ;
F_136 ( V_270 -> V_18 ) ;
F_130 ( V_226 -> V_73 , V_270 ) ;
if ( F_108 ( V_270 -> V_229 ) )
F_115 ( V_270 -> V_229 , 0 ) ;
F_131 ( V_270 -> V_238 ) ;
F_131 ( V_270 -> V_236 ) ;
F_132 ( V_270 -> V_18 ) ;
return 0 ;
}
