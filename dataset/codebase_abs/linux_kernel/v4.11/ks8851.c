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
static inline bool F_7 ( struct V_1 * V_2 )
{
return true ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_20 ,
T_2 * V_21 , unsigned V_22 )
{
struct V_5 * V_6 ;
struct V_8 * V_9 ;
T_1 * V_11 = ( T_1 * ) V_2 -> V_23 ;
T_2 * V_24 = V_2 -> V_25 ;
int V_12 ;
V_11 [ 0 ] = F_2 ( V_20 | V_26 ) ;
if ( F_7 ( V_2 ) ) {
V_9 = & V_2 -> V_10 ;
V_6 = & V_2 -> V_7 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = V_24 ;
V_6 -> V_16 = V_22 + 2 ;
} else {
V_9 = & V_2 -> V_27 ;
V_6 = V_2 -> V_28 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 2 ;
V_6 ++ ;
V_6 -> V_14 = NULL ;
V_6 -> V_15 = V_24 ;
V_6 -> V_16 = V_22 ;
}
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_2 ) ;
else if ( F_7 ( V_2 ) )
memcpy ( V_21 , V_24 + 2 , V_22 ) ;
else
memcpy ( V_21 , V_24 , V_22 ) ;
}
static unsigned F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_21 [ 1 ] ;
F_8 ( V_2 , F_3 ( 1 << ( V_3 & 3 ) , V_3 ) , V_21 , 1 ) ;
return V_21 [ 0 ] ;
}
static unsigned F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_29 = 0 ;
F_8 ( V_2 , F_3 ( V_3 & 2 ? 0xC : 0x3 , V_3 ) , ( T_2 * ) & V_29 , 2 ) ;
return F_11 ( V_29 ) ;
}
static unsigned F_12 ( struct V_1 * V_2 , unsigned V_3 )
{
T_3 V_29 = 0 ;
F_13 ( V_3 & 3 ) ;
F_8 ( V_2 , F_3 ( 0xf , V_3 ) , ( T_2 * ) & V_29 , 4 ) ;
return F_14 ( V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned V_20 )
{
F_1 ( V_2 , V_30 , V_20 ) ;
F_16 ( 1 ) ;
F_1 ( V_2 , V_30 , 0 ) ;
F_16 ( 1 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_31 )
{
unsigned V_32 ;
F_18 ( V_2 , V_33 , V_2 -> V_18 , L_3 , V_31 ) ;
V_32 = F_10 ( V_2 , V_34 ) ;
V_32 &= ~ V_35 ;
V_32 |= V_31 ;
F_1 ( V_2 , V_34 , V_32 ) ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_38 ;
F_21 ( & V_2 -> V_39 ) ;
F_17 ( V_2 , V_40 ) ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ )
F_6 ( V_2 , F_22 ( V_38 ) , V_37 -> V_42 [ V_38 ] ) ;
if ( ! F_23 ( V_37 ) )
F_17 ( V_2 , V_43 ) ;
F_24 ( & V_2 -> V_39 ) ;
return 0 ;
}
static void F_25 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_38 ;
F_21 ( & V_2 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ )
V_37 -> V_42 [ V_38 ] = F_9 ( V_2 , F_22 ( V_38 ) ) ;
F_24 ( & V_2 -> V_39 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_18 ;
if ( V_2 -> V_44 & V_45 ) {
F_25 ( V_37 ) ;
if ( F_27 ( V_37 -> V_42 ) )
return;
F_5 ( V_2 -> V_18 , L_4 ,
V_37 -> V_42 ) ;
}
F_28 ( V_37 ) ;
F_19 ( V_37 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_46 , unsigned V_16 )
{
struct V_5 * V_6 = V_2 -> V_28 ;
struct V_8 * V_9 = & V_2 -> V_27 ;
T_2 V_11 [ 1 ] ;
int V_12 ;
F_18 ( V_2 , V_47 , V_2 -> V_18 ,
L_5 , V_48 , V_16 , V_46 ) ;
V_11 [ 0 ] = V_49 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 1 ;
V_6 ++ ;
V_6 -> V_15 = V_46 ;
V_6 -> V_14 = NULL ;
V_6 -> V_16 = V_16 ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_6 , V_48 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_2 * V_50 )
{
F_31 ( V_2 -> V_18 ,
L_7 ,
V_50 [ 4 ] , V_50 [ 5 ] , V_50 [ 6 ] , V_50 [ 7 ] ,
V_50 [ 8 ] , V_50 [ 9 ] , V_50 [ 10 ] , V_50 [ 11 ] ,
V_50 [ 12 ] , V_50 [ 13 ] , V_50 [ 14 ] , V_50 [ 15 ] ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
unsigned V_53 ;
unsigned V_54 ;
unsigned V_55 ;
T_4 V_56 ;
T_2 * V_50 ;
V_53 = F_9 ( V_2 , V_57 ) ;
F_18 ( V_2 , V_47 , V_2 -> V_18 ,
L_8 , V_48 , V_53 ) ;
for (; V_53 != 0 ; V_53 -- ) {
V_56 = F_12 ( V_2 , V_58 ) ;
V_55 = V_56 & 0xffff ;
V_54 = ( V_56 >> 16 ) & 0xfff ;
F_18 ( V_2 , V_47 , V_2 -> V_18 ,
L_9 , V_55 , V_54 ) ;
F_1 ( V_2 , V_59 , V_60 | 0x00 ) ;
F_1 ( V_2 , V_61 ,
V_2 -> V_62 | V_63 | V_64 ) ;
if ( V_54 > 4 ) {
unsigned int V_65 ;
V_54 -= 4 ;
V_65 = F_33 ( V_54 , 4 ) ;
V_52 = F_34 ( V_2 -> V_18 , V_65 ) ;
if ( V_52 ) {
V_50 = F_35 ( V_52 , V_54 ) - 8 ;
F_29 ( V_2 , V_50 , V_65 + 8 ) ;
if ( F_36 ( V_2 ) )
F_30 ( V_2 , V_50 ) ;
V_52 -> V_66 = F_37 ( V_52 , V_2 -> V_18 ) ;
F_38 ( V_52 ) ;
V_2 -> V_18 -> V_67 . V_68 ++ ;
V_2 -> V_18 -> V_67 . V_69 += V_54 ;
}
}
F_1 ( V_2 , V_61 , V_2 -> V_62 ) ;
}
}
static T_5 F_39 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
unsigned V_72 ;
unsigned V_73 = 0 ;
F_21 ( & V_2 -> V_39 ) ;
V_72 = F_10 ( V_2 , V_74 ) ;
F_18 ( V_2 , V_75 , V_2 -> V_18 ,
L_10 , V_48 , V_72 ) ;
if ( V_72 & V_76 )
V_73 |= V_76 ;
if ( V_72 & V_77 ) {
T_6 V_32 = F_10 ( V_2 , V_34 ) ;
V_32 &= ~ V_78 ;
F_1 ( V_2 , V_34 , V_32 | V_79 ) ;
V_73 |= V_77 ;
}
if ( V_72 & V_80 )
V_73 |= V_80 ;
if ( V_72 & V_81 ) {
V_73 |= V_81 ;
V_2 -> V_82 = F_10 ( V_2 , V_83 ) ;
F_18 ( V_2 , V_75 , V_2 -> V_18 ,
L_11 , V_48 , V_2 -> V_82 ) ;
}
if ( V_72 & V_84 )
V_73 |= V_84 ;
if ( V_72 & V_85 ) {
F_40 ( & V_2 -> V_17 -> V_37 , L_12 , V_48 ) ;
V_73 |= V_85 ;
}
F_1 ( V_2 , V_74 , V_73 ) ;
if ( V_72 & V_84 ) {
F_32 ( V_2 ) ;
}
if ( V_72 & V_80 ) {
struct V_86 * V_87 = & V_2 -> V_88 ;
F_1 ( V_2 , V_89 , V_87 -> V_90 [ 0 ] ) ;
F_1 ( V_2 , V_91 , V_87 -> V_90 [ 1 ] ) ;
F_1 ( V_2 , V_92 , V_87 -> V_90 [ 2 ] ) ;
F_1 ( V_2 , V_93 , V_87 -> V_90 [ 3 ] ) ;
F_1 ( V_2 , V_94 , V_87 -> V_95 ) ;
F_1 ( V_2 , V_96 , V_87 -> V_97 ) ;
}
F_24 ( & V_2 -> V_39 ) ;
if ( V_72 & V_76 )
F_41 ( & V_2 -> V_98 ) ;
if ( V_72 & V_81 )
F_42 ( V_2 -> V_18 ) ;
return V_99 ;
}
static inline unsigned F_43 ( unsigned V_16 )
{
return F_33 ( V_16 + 4 , 4 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_51 * V_100 , bool V_70 )
{
struct V_5 * V_6 = V_2 -> V_28 ;
struct V_8 * V_9 = & V_2 -> V_27 ;
unsigned V_101 = 0 ;
int V_12 ;
F_18 ( V_2 , V_102 , V_2 -> V_18 , L_13 ,
V_48 , V_100 , V_100 -> V_16 , V_100 -> V_103 , V_70 ) ;
V_101 = V_2 -> V_101 ++ ;
V_101 &= V_104 ;
if ( V_70 )
V_101 |= V_105 ;
V_2 -> V_106 . V_11 [ 1 ] = V_107 ;
V_2 -> V_106 . V_108 [ 1 ] = F_2 ( V_101 ) ;
V_2 -> V_106 . V_108 [ 2 ] = F_2 ( V_100 -> V_16 ) ;
V_6 -> V_14 = & V_2 -> V_106 . V_11 [ 1 ] ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 5 ;
V_6 ++ ;
V_6 -> V_14 = V_100 -> V_103 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = F_33 ( V_100 -> V_16 , 4 ) ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_6 , V_48 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_51 * V_11 )
{
struct V_36 * V_37 = V_2 -> V_18 ;
V_37 -> V_67 . V_109 += V_11 -> V_16 ;
V_37 -> V_67 . V_110 ++ ;
F_46 ( V_11 ) ;
}
static void F_47 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_48 ( V_112 , struct V_1 , V_113 ) ;
struct V_51 * V_11 ;
bool V_114 = F_49 ( & V_2 -> V_115 ) ;
F_21 ( & V_2 -> V_39 ) ;
while ( ! V_114 ) {
V_11 = F_50 ( & V_2 -> V_115 ) ;
V_114 = F_49 ( & V_2 -> V_115 ) ;
if ( V_11 != NULL ) {
F_1 ( V_2 , V_61 , V_2 -> V_62 | V_63 ) ;
F_44 ( V_2 , V_11 , V_114 ) ;
F_1 ( V_2 , V_61 , V_2 -> V_62 ) ;
F_1 ( V_2 , V_116 , V_117 ) ;
F_45 ( V_2 , V_11 ) ;
}
}
F_24 ( & V_2 -> V_39 ) ;
}
static int F_51 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_18 ( V_2 , V_118 , V_2 -> V_18 , L_14 ) ;
F_17 ( V_2 , V_40 ) ;
F_15 ( V_2 , V_119 ) ;
F_1 ( V_2 , V_120 , ( V_121 |
V_122 |
V_123 |
V_124 ) ) ;
F_1 ( V_2 , V_125 , V_126 ) ;
F_1 ( V_2 , V_96 , ( V_127 |
V_128 |
V_129 |
V_130 |
V_131 ) ) ;
F_1 ( V_2 , V_94 , V_132 ) ;
F_1 ( V_2 , V_133 , 1000 ) ;
F_1 ( V_2 , V_134 , 4096 ) ;
F_1 ( V_2 , V_135 , 10 ) ;
V_2 -> V_62 = ( V_136 |
V_137 |
V_138 ) ;
F_1 ( V_2 , V_61 , V_2 -> V_62 ) ;
#define F_52 (IRQ_LCI | \
IRQ_TXI | \
IRQ_RXI | \
IRQ_SPIBEI | \
IRQ_TXPSI | \
IRQ_RXPSI)
V_2 -> V_139 = F_52 ;
F_1 ( V_2 , V_74 , F_52 ) ;
F_1 ( V_2 , V_140 , F_52 ) ;
F_53 ( V_2 -> V_18 ) ;
F_18 ( V_2 , V_118 , V_2 -> V_18 , L_15 ) ;
F_24 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_54 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
F_55 ( V_2 , V_141 , V_37 , L_16 ) ;
F_56 ( V_37 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_140 , 0x0000 ) ;
F_1 ( V_2 , V_74 , 0xffff ) ;
F_24 ( & V_2 -> V_39 ) ;
F_57 ( & V_2 -> V_113 ) ;
F_57 ( & V_2 -> V_142 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_96 , 0x0000 ) ;
F_1 ( V_2 , V_120 , 0x0000 ) ;
F_17 ( V_2 , V_43 ) ;
F_24 ( & V_2 -> V_39 ) ;
while ( ! F_49 ( & V_2 -> V_115 ) ) {
struct V_51 * V_11 = F_50 ( & V_2 -> V_115 ) ;
F_18 ( V_2 , V_141 , V_2 -> V_18 ,
L_17 , V_48 , V_11 ) ;
F_46 ( V_11 ) ;
}
return 0 ;
}
static T_7 F_58 ( struct V_51 * V_52 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
unsigned V_143 = F_43 ( V_52 -> V_16 ) ;
T_7 V_12 = V_144 ;
F_18 ( V_2 , V_102 , V_2 -> V_18 ,
L_18 , V_48 , V_52 , V_52 -> V_16 , V_52 -> V_103 ) ;
F_59 ( & V_2 -> V_145 ) ;
if ( V_143 > V_2 -> V_82 ) {
F_56 ( V_37 ) ;
V_12 = V_146 ;
} else {
V_2 -> V_82 -= V_143 ;
F_60 ( & V_2 -> V_115 , V_52 ) ;
}
F_61 ( & V_2 -> V_145 ) ;
F_62 ( & V_2 -> V_113 ) ;
return V_12 ;
}
static void F_63 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_48 ( V_112 , struct V_1 , V_142 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_96 , 0x00 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
static void F_64 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
struct V_86 V_88 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
if ( V_37 -> V_147 & V_148 ) {
V_88 . V_97 = V_149 | V_150 ;
} else if ( V_37 -> V_147 & V_151 ) {
V_88 . V_97 = ( V_152 | V_149 |
V_127 | V_153 ) ;
} else if ( V_37 -> V_147 & V_154 && ! F_65 ( V_37 ) ) {
struct V_155 * V_156 ;
T_4 V_157 ;
F_66 (ha, dev) {
V_157 = F_67 ( V_41 , V_156 -> V_158 ) ;
V_157 >>= ( 32 - 6 ) ;
V_88 . V_90 [ V_157 >> 4 ] |= ( 1 << ( V_157 & 0xf ) ) ;
}
V_88 . V_97 = V_152 | V_127 ;
} else {
V_88 . V_97 = V_127 ;
}
V_88 . V_97 |= ( V_130 |
V_129 |
V_131 |
V_128 ) ;
V_88 . V_95 |= V_132 ;
F_59 ( & V_2 -> V_145 ) ;
if ( memcmp ( & V_88 , & V_2 -> V_88 , sizeof( V_88 ) ) != 0 ) {
memcpy ( & V_2 -> V_88 , & V_88 , sizeof( V_2 -> V_88 ) ) ;
F_62 ( & V_2 -> V_142 ) ;
}
F_61 ( & V_2 -> V_145 ) ;
}
static int F_68 ( struct V_36 * V_37 , void * V_158 )
{
struct V_159 * V_160 = V_158 ;
if ( F_23 ( V_37 ) )
return - V_161 ;
if ( ! F_27 ( V_160 -> V_162 ) )
return - V_163 ;
memcpy ( V_37 -> V_42 , V_160 -> V_162 , V_41 ) ;
return F_19 ( V_37 ) ;
}
static int F_69 ( struct V_36 * V_37 , struct V_164 * V_165 , int V_166 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
if ( ! F_23 ( V_37 ) )
return - V_167 ;
return F_70 ( & V_2 -> V_98 , F_71 ( V_165 ) , V_166 , NULL ) ;
}
static void F_72 ( struct V_36 * V_37 ,
struct V_168 * V_169 )
{
F_73 ( V_169 -> V_170 , L_19 , sizeof( V_169 -> V_170 ) ) ;
F_73 ( V_169 -> V_171 , L_20 , sizeof( V_169 -> V_171 ) ) ;
F_73 ( V_169 -> V_172 , F_74 ( V_37 -> V_37 . V_173 ) , sizeof( V_169 -> V_172 ) ) ;
}
static T_4 F_75 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return V_2 -> V_174 ;
}
static void F_76 ( struct V_36 * V_37 , T_4 V_175 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
V_2 -> V_174 = V_175 ;
}
static int F_77 ( struct V_36 * V_37 ,
struct V_176 * V_166 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_78 ( & V_2 -> V_98 , V_166 ) ;
}
static int F_79 ( struct V_36 * V_37 ,
const struct V_176 * V_166 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_80 ( & V_2 -> V_98 , V_166 ) ;
}
static T_4 F_81 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_82 ( & V_2 -> V_98 ) ;
}
static int F_83 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_84 ( & V_2 -> V_98 ) ;
}
static void F_85 ( struct V_177 * V_178 )
{
struct V_1 * V_2 = V_178 -> V_103 ;
unsigned V_4 ;
V_4 = F_10 ( V_2 , V_179 ) ;
V_178 -> V_180 = ( V_4 & V_181 ) ? 1 : 0 ;
V_178 -> V_182 = ( V_4 & V_183 ) ? 1 : 0 ;
V_178 -> V_184 = ( V_4 & V_185 ) ? 1 : 0 ;
}
static void F_86 ( struct V_177 * V_178 )
{
struct V_1 * V_2 = V_178 -> V_103 ;
unsigned V_4 = V_186 ;
if ( V_178 -> V_187 )
V_4 |= V_188 ;
if ( V_178 -> V_189 )
V_4 |= V_190 ;
if ( V_178 -> V_182 )
V_4 |= V_183 ;
if ( V_178 -> V_184 )
V_4 |= V_185 ;
F_1 ( V_2 , V_179 , V_4 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_44 & V_45 ) )
return - V_191 ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_179 , V_186 | V_185 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned V_4 = F_10 ( V_2 , V_179 ) ;
F_1 ( V_2 , V_179 , V_4 & ~ V_186 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
static int F_89 ( struct V_36 * V_37 ,
struct V_192 * V_178 , T_2 * V_103 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_193 = V_178 -> V_193 ;
int V_16 = V_178 -> V_16 ;
T_6 V_194 ;
if ( V_16 != 1 )
return - V_167 ;
if ( V_178 -> V_195 != V_196 )
return - V_167 ;
if ( F_87 ( V_2 ) )
return - V_191 ;
F_90 ( & V_2 -> V_197 , true ) ;
F_91 ( & V_2 -> V_197 , V_193 / 2 , & V_194 ) ;
if ( V_193 & 1 ) {
V_194 &= 0xff ;
V_194 |= * V_103 << 8 ;
} else {
V_194 &= 0xff00 ;
V_194 |= * V_103 ;
}
F_92 ( & V_2 -> V_197 , V_193 / 2 , V_194 ) ;
F_90 ( & V_2 -> V_197 , false ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_36 * V_37 ,
struct V_192 * V_178 , T_2 * V_103 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_193 = V_178 -> V_193 ;
int V_16 = V_178 -> V_16 ;
if ( V_16 & 1 || V_193 & 1 )
return - V_167 ;
if ( F_87 ( V_2 ) )
return - V_191 ;
V_178 -> V_195 = V_196 ;
F_94 ( & V_2 -> V_197 , V_193 / 2 , ( T_1 * ) V_103 , V_16 / 2 ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return V_2 -> V_44 & V_45 ? 128 : 0 ;
}
static int F_96 ( int V_3 )
{
switch ( V_3 ) {
case V_198 :
return V_199 ;
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
}
return 0x0 ;
}
static int F_97 ( struct V_36 * V_37 , int V_210 , int V_3 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_211 ;
int V_212 ;
V_211 = F_96 ( V_3 ) ;
if ( ! V_211 )
return 0x0 ;
F_21 ( & V_2 -> V_39 ) ;
V_212 = F_10 ( V_2 , V_211 ) ;
F_24 ( & V_2 -> V_39 ) ;
return V_212 ;
}
static void F_98 ( struct V_36 * V_37 ,
int V_213 , int V_3 , int V_214 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_211 ;
V_211 = F_96 ( V_3 ) ;
if ( V_211 ) {
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_211 , V_214 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
}
static int F_99 ( struct V_1 * V_2 )
{
unsigned V_215 = V_216 | V_217 ;
int V_12 = 0 ;
unsigned V_218 ;
V_218 = F_10 ( V_2 , V_219 ) ;
if ( ( V_218 & V_215 ) != V_215 ) {
F_100 ( V_2 -> V_18 , L_21 ) ;
return 0 ;
}
if ( V_218 & V_220 ) {
F_5 ( V_2 -> V_18 , L_22 ) ;
V_12 |= 1 ;
}
if ( V_218 & V_221 ) {
F_5 ( V_2 -> V_18 , L_23 ) ;
V_12 |= 2 ;
}
return 0 ;
}
static int F_101 ( struct V_222 * V_37 )
{
struct V_1 * V_2 = F_102 ( V_37 ) ;
struct V_36 * V_18 = V_2 -> V_18 ;
if ( F_23 ( V_18 ) ) {
F_103 ( V_18 ) ;
F_54 ( V_18 ) ;
}
return 0 ;
}
static int F_104 ( struct V_222 * V_37 )
{
struct V_1 * V_2 = F_102 ( V_37 ) ;
struct V_36 * V_18 = V_2 -> V_18 ;
if ( F_23 ( V_18 ) ) {
F_51 ( V_18 ) ;
F_105 ( V_18 ) ;
}
return 0 ;
}
static int F_106 ( struct V_223 * V_224 )
{
struct V_36 * V_225 ;
struct V_1 * V_2 ;
int V_12 ;
unsigned V_226 ;
int V_227 ;
V_225 = F_107 ( sizeof( struct V_1 ) ) ;
if ( ! V_225 )
return - V_228 ;
V_224 -> V_229 = 8 ;
V_2 = F_20 ( V_225 ) ;
V_2 -> V_18 = V_225 ;
V_2 -> V_17 = V_224 ;
V_2 -> V_82 = 6144 ;
V_227 = F_108 ( V_224 -> V_37 . V_230 , L_24 ,
0 , NULL ) ;
if ( V_227 == - V_231 ) {
V_12 = V_227 ;
goto V_232;
}
V_2 -> V_227 = V_227 ;
if ( F_109 ( V_227 ) ) {
V_12 = F_110 ( & V_224 -> V_37 , V_227 ,
V_233 , L_25 ) ;
if ( V_12 ) {
F_40 ( & V_224 -> V_37 , L_26 ) ;
goto V_232;
}
}
V_2 -> V_234 = F_111 ( & V_224 -> V_37 , L_27 ) ;
if ( F_112 ( V_2 -> V_234 ) ) {
V_12 = F_113 ( V_2 -> V_234 ) ;
goto V_235;
}
V_12 = F_114 ( V_2 -> V_234 ) ;
if ( V_12 ) {
F_40 ( & V_224 -> V_37 , L_28 ,
V_12 ) ;
goto V_235;
}
V_2 -> V_236 = F_111 ( & V_224 -> V_37 , L_29 ) ;
if ( F_112 ( V_2 -> V_236 ) ) {
V_12 = F_113 ( V_2 -> V_236 ) ;
goto V_237;
}
V_12 = F_114 ( V_2 -> V_236 ) ;
if ( V_12 ) {
F_40 ( & V_224 -> V_37 , L_30 ,
V_12 ) ;
goto V_237;
}
if ( F_109 ( V_227 ) ) {
F_115 ( 10000 , 11000 ) ;
F_116 ( V_227 , 1 ) ;
}
F_117 ( & V_2 -> V_39 ) ;
F_118 ( & V_2 -> V_145 ) ;
F_119 ( & V_2 -> V_113 , F_47 ) ;
F_119 ( & V_2 -> V_142 , F_63 ) ;
F_120 ( & V_2 -> V_10 ) ;
F_121 ( & V_2 -> V_7 , & V_2 -> V_10 ) ;
F_120 ( & V_2 -> V_27 ) ;
F_121 ( & V_2 -> V_28 [ 0 ] , & V_2 -> V_27 ) ;
F_121 ( & V_2 -> V_28 [ 1 ] , & V_2 -> V_27 ) ;
V_2 -> V_197 . V_103 = V_2 ;
V_2 -> V_197 . V_238 = V_239 ;
V_2 -> V_197 . V_240 = F_85 ;
V_2 -> V_197 . V_241 = F_86 ;
V_2 -> V_98 . V_37 = V_225 ;
V_2 -> V_98 . V_242 = 1 ,
V_2 -> V_98 . V_243 = 1 ;
V_2 -> V_98 . V_244 = 0xf ;
V_2 -> V_98 . V_245 = F_97 ;
V_2 -> V_98 . V_246 = F_98 ;
F_122 ( & V_224 -> V_37 , L_31 , V_174 ) ;
V_2 -> V_174 = F_123 ( V_174 , ( V_247 |
V_248 |
V_249 ) ) ;
F_124 ( & V_2 -> V_115 ) ;
V_225 -> V_250 = & V_251 ;
F_125 ( V_225 , & V_224 -> V_37 ) ;
F_126 ( V_224 , V_2 ) ;
V_225 -> V_252 = V_253 ;
V_225 -> V_254 = & V_255 ;
V_225 -> V_70 = V_224 -> V_70 ;
F_15 ( V_2 , V_256 ) ;
V_226 = F_10 ( V_2 , V_257 ) ;
if ( ( V_226 & ~ V_258 ) != V_259 ) {
F_40 ( & V_224 -> V_37 , L_32 ) ;
V_12 = - V_260 ;
goto V_261;
}
V_2 -> V_44 = F_10 ( V_2 , V_262 ) ;
F_99 ( V_2 ) ;
F_26 ( V_2 ) ;
V_12 = F_127 ( V_224 -> V_70 , NULL , F_39 ,
V_263 | V_264 ,
V_225 -> V_265 , V_2 ) ;
if ( V_12 < 0 ) {
F_40 ( & V_224 -> V_37 , L_33 ) ;
goto V_266;
}
V_12 = F_128 ( V_225 ) ;
if ( V_12 ) {
F_40 ( & V_224 -> V_37 , L_34 ) ;
goto V_267;
}
F_129 ( V_225 , L_35 ,
F_130 ( V_226 ) , V_225 -> V_42 , V_225 -> V_70 ,
V_2 -> V_44 & V_45 ? L_36 : L_37 ) ;
return 0 ;
V_267:
F_131 ( V_225 -> V_70 , V_2 ) ;
V_266:
if ( F_109 ( V_227 ) )
F_116 ( V_227 , 0 ) ;
V_261:
F_132 ( V_2 -> V_236 ) ;
V_237:
F_132 ( V_2 -> V_234 ) ;
V_235:
V_232:
F_133 ( V_225 ) ;
return V_12 ;
}
static int F_134 ( struct V_223 * V_224 )
{
struct V_1 * V_268 = F_135 ( V_224 ) ;
if ( F_136 ( V_268 ) )
F_122 ( & V_224 -> V_37 , L_38 ) ;
F_137 ( V_268 -> V_18 ) ;
F_131 ( V_224 -> V_70 , V_268 ) ;
if ( F_109 ( V_268 -> V_227 ) )
F_116 ( V_268 -> V_227 , 0 ) ;
F_132 ( V_268 -> V_236 ) ;
F_132 ( V_268 -> V_234 ) ;
F_133 ( V_268 -> V_18 ) ;
return 0 ;
}
