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
static T_4 F_29 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
F_30 ( V_46 ) ;
F_31 ( & V_2 -> V_48 ) ;
return V_49 ;
}
static void F_32 ( struct V_1 * V_2 , T_2 * V_50 , unsigned V_16 )
{
struct V_5 * V_6 = V_2 -> V_28 ;
struct V_8 * V_9 = & V_2 -> V_27 ;
T_2 V_11 [ 1 ] ;
int V_12 ;
F_18 ( V_2 , V_51 , V_2 -> V_18 ,
L_5 , V_52 , V_16 , V_50 ) ;
V_11 [ 0 ] = V_53 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 1 ;
V_6 ++ ;
V_6 -> V_15 = V_50 ;
V_6 -> V_14 = NULL ;
V_6 -> V_16 = V_16 ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_6 , V_52 ) ;
}
static void F_33 ( struct V_1 * V_2 , T_2 * V_54 )
{
F_34 ( V_2 -> V_18 ,
L_7 ,
V_54 [ 4 ] , V_54 [ 5 ] , V_54 [ 6 ] , V_54 [ 7 ] ,
V_54 [ 8 ] , V_54 [ 9 ] , V_54 [ 10 ] , V_54 [ 11 ] ,
V_54 [ 12 ] , V_54 [ 13 ] , V_54 [ 14 ] , V_54 [ 15 ] ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
unsigned V_57 ;
unsigned V_58 ;
unsigned V_59 ;
T_5 V_60 ;
T_2 * V_54 ;
V_57 = F_9 ( V_2 , V_61 ) ;
F_18 ( V_2 , V_51 , V_2 -> V_18 ,
L_8 , V_52 , V_57 ) ;
for (; V_57 != 0 ; V_57 -- ) {
V_60 = F_12 ( V_2 , V_62 ) ;
V_59 = V_60 & 0xffff ;
V_58 = V_60 >> 16 ;
F_18 ( V_2 , V_51 , V_2 -> V_18 ,
L_9 , V_59 , V_58 ) ;
F_1 ( V_2 , V_63 , V_64 | 0x00 ) ;
F_1 ( V_2 , V_65 ,
V_2 -> V_66 | V_67 | V_68 ) ;
if ( V_58 > 4 ) {
unsigned int V_69 ;
V_58 -= 4 ;
V_69 = F_36 ( V_58 , 4 ) ;
V_56 = F_37 ( V_2 -> V_18 , V_69 ) ;
if ( V_56 ) {
V_54 = F_38 ( V_56 , V_58 ) - 8 ;
F_32 ( V_2 , V_54 , V_69 + 8 ) ;
if ( F_39 ( V_2 ) )
F_33 ( V_2 , V_54 ) ;
V_56 -> V_70 = F_40 ( V_56 , V_2 -> V_18 ) ;
F_41 ( V_56 ) ;
V_2 -> V_18 -> V_71 . V_72 ++ ;
V_2 -> V_18 -> V_71 . V_73 += V_58 ;
}
}
F_1 ( V_2 , V_65 , V_2 -> V_66 ) ;
}
}
static void F_42 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_43 ( V_75 , struct V_1 , V_48 ) ;
unsigned V_76 ;
unsigned V_77 = 0 ;
F_21 ( & V_2 -> V_39 ) ;
V_76 = F_10 ( V_2 , V_78 ) ;
F_18 ( V_2 , V_79 , V_2 -> V_18 ,
L_10 , V_52 , V_76 ) ;
if ( V_76 & V_80 )
V_77 |= V_80 ;
if ( V_76 & V_81 ) {
T_6 V_32 = F_10 ( V_2 , V_34 ) ;
V_32 &= ~ V_82 ;
F_1 ( V_2 , V_34 , V_32 | V_83 ) ;
V_77 |= V_81 ;
}
if ( V_76 & V_84 )
V_77 |= V_84 ;
if ( V_76 & V_85 ) {
V_77 |= V_85 ;
V_2 -> V_86 = F_10 ( V_2 , V_87 ) ;
F_18 ( V_2 , V_79 , V_2 -> V_18 ,
L_11 , V_52 , V_2 -> V_86 ) ;
}
if ( V_76 & V_88 )
V_77 |= V_88 ;
if ( V_76 & V_89 ) {
F_44 ( & V_2 -> V_17 -> V_37 , L_12 , V_52 ) ;
V_77 |= V_89 ;
}
F_1 ( V_2 , V_78 , V_77 ) ;
if ( V_76 & V_88 ) {
F_35 ( V_2 ) ;
}
if ( V_76 & V_84 ) {
struct V_90 * V_91 = & V_2 -> V_92 ;
F_1 ( V_2 , V_93 , V_91 -> V_94 [ 0 ] ) ;
F_1 ( V_2 , V_95 , V_91 -> V_94 [ 1 ] ) ;
F_1 ( V_2 , V_96 , V_91 -> V_94 [ 2 ] ) ;
F_1 ( V_2 , V_97 , V_91 -> V_94 [ 3 ] ) ;
F_1 ( V_2 , V_98 , V_91 -> V_99 ) ;
F_1 ( V_2 , V_100 , V_91 -> V_101 ) ;
}
F_24 ( & V_2 -> V_39 ) ;
if ( V_76 & V_80 )
F_45 ( & V_2 -> V_102 ) ;
if ( V_76 & V_85 )
F_46 ( V_2 -> V_18 ) ;
F_47 ( V_2 -> V_18 -> V_46 ) ;
}
static inline unsigned F_48 ( unsigned V_16 )
{
return F_36 ( V_16 + 4 , 4 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_55 * V_103 , bool V_46 )
{
struct V_5 * V_6 = V_2 -> V_28 ;
struct V_8 * V_9 = & V_2 -> V_27 ;
unsigned V_104 = 0 ;
int V_12 ;
F_18 ( V_2 , V_105 , V_2 -> V_18 , L_13 ,
V_52 , V_103 , V_103 -> V_16 , V_103 -> V_106 , V_46 ) ;
V_104 = V_2 -> V_104 ++ ;
V_104 &= V_107 ;
if ( V_46 )
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
V_6 -> V_16 = F_36 ( V_103 -> V_16 , 4 ) ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_6 , V_52 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_55 * V_11 )
{
struct V_36 * V_37 = V_2 -> V_18 ;
V_37 -> V_71 . V_112 += V_11 -> V_16 ;
V_37 -> V_71 . V_113 ++ ;
F_51 ( V_11 ) ;
}
static void F_52 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_43 ( V_75 , struct V_1 , V_114 ) ;
struct V_55 * V_11 ;
bool V_115 = F_53 ( & V_2 -> V_116 ) ;
F_21 ( & V_2 -> V_39 ) ;
while ( ! V_115 ) {
V_11 = F_54 ( & V_2 -> V_116 ) ;
V_115 = F_53 ( & V_2 -> V_116 ) ;
if ( V_11 != NULL ) {
F_1 ( V_2 , V_65 , V_2 -> V_66 | V_67 ) ;
F_49 ( V_2 , V_11 , V_115 ) ;
F_1 ( V_2 , V_65 , V_2 -> V_66 ) ;
F_1 ( V_2 , V_117 , V_118 ) ;
F_50 ( V_2 , V_11 ) ;
}
}
F_24 ( & V_2 -> V_39 ) ;
}
static int F_55 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_18 ( V_2 , V_119 , V_2 -> V_18 , L_14 ) ;
F_17 ( V_2 , V_40 ) ;
F_15 ( V_2 , V_120 ) ;
F_1 ( V_2 , V_121 , ( V_122 |
V_123 |
V_124 |
V_125 ) ) ;
F_1 ( V_2 , V_126 , V_127 ) ;
F_1 ( V_2 , V_100 , ( V_128 |
V_129 |
V_130 |
V_131 |
V_132 ) ) ;
F_1 ( V_2 , V_98 , V_133 ) ;
F_1 ( V_2 , V_134 , 1000 ) ;
F_1 ( V_2 , V_135 , 4096 ) ;
F_1 ( V_2 , V_136 , 10 ) ;
V_2 -> V_66 = ( V_137 |
V_138 |
V_139 ) ;
F_1 ( V_2 , V_65 , V_2 -> V_66 ) ;
#define F_56 (IRQ_LCI | \
IRQ_TXI | \
IRQ_RXI | \
IRQ_SPIBEI | \
IRQ_TXPSI | \
IRQ_RXPSI)
V_2 -> V_140 = F_56 ;
F_1 ( V_2 , V_78 , F_56 ) ;
F_1 ( V_2 , V_141 , F_56 ) ;
F_57 ( V_2 -> V_18 ) ;
F_18 ( V_2 , V_119 , V_2 -> V_18 , L_15 ) ;
F_24 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_58 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
F_59 ( V_2 , V_142 , V_37 , L_16 ) ;
F_60 ( V_37 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_141 , 0x0000 ) ;
F_1 ( V_2 , V_78 , 0xffff ) ;
F_24 ( & V_2 -> V_39 ) ;
F_61 ( & V_2 -> V_48 ) ;
F_61 ( & V_2 -> V_114 ) ;
F_61 ( & V_2 -> V_143 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_100 , 0x0000 ) ;
F_1 ( V_2 , V_121 , 0x0000 ) ;
F_17 ( V_2 , V_43 ) ;
F_24 ( & V_2 -> V_39 ) ;
while ( ! F_53 ( & V_2 -> V_116 ) ) {
struct V_55 * V_11 = F_54 ( & V_2 -> V_116 ) ;
F_18 ( V_2 , V_142 , V_2 -> V_18 ,
L_17 , V_52 , V_11 ) ;
F_51 ( V_11 ) ;
}
return 0 ;
}
static T_7 F_62 ( struct V_55 * V_56 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
unsigned V_144 = F_48 ( V_56 -> V_16 ) ;
T_7 V_12 = V_145 ;
F_18 ( V_2 , V_105 , V_2 -> V_18 ,
L_18 , V_52 , V_56 , V_56 -> V_16 , V_56 -> V_106 ) ;
F_63 ( & V_2 -> V_146 ) ;
if ( V_144 > V_2 -> V_86 ) {
F_60 ( V_37 ) ;
V_12 = V_147 ;
} else {
V_2 -> V_86 -= V_144 ;
F_64 ( & V_2 -> V_116 , V_56 ) ;
}
F_65 ( & V_2 -> V_146 ) ;
F_31 ( & V_2 -> V_114 ) ;
return V_12 ;
}
static void F_66 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_43 ( V_75 , struct V_1 , V_143 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_100 , 0x00 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
static void F_67 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
struct V_90 V_92 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
if ( V_37 -> V_148 & V_149 ) {
V_92 . V_101 = V_150 | V_151 ;
} else if ( V_37 -> V_148 & V_152 ) {
V_92 . V_101 = ( V_153 | V_150 |
V_128 | V_154 ) ;
} else if ( V_37 -> V_148 & V_155 && ! F_68 ( V_37 ) ) {
struct V_156 * V_157 ;
T_5 V_158 ;
F_69 (ha, dev) {
V_158 = F_70 ( V_41 , V_157 -> V_159 ) ;
V_158 >>= ( 32 - 6 ) ;
V_92 . V_94 [ V_158 >> 4 ] |= ( 1 << ( V_158 & 0xf ) ) ;
}
V_92 . V_101 = V_153 | V_128 ;
} else {
V_92 . V_101 = V_128 ;
}
V_92 . V_101 |= ( V_131 |
V_130 |
V_132 |
V_129 ) ;
V_92 . V_99 |= V_133 ;
F_63 ( & V_2 -> V_146 ) ;
if ( memcmp ( & V_92 , & V_2 -> V_92 , sizeof( V_92 ) ) != 0 ) {
memcpy ( & V_2 -> V_92 , & V_92 , sizeof( V_2 -> V_92 ) ) ;
F_31 ( & V_2 -> V_143 ) ;
}
F_65 ( & V_2 -> V_146 ) ;
}
static int F_71 ( struct V_36 * V_37 , void * V_159 )
{
struct V_160 * V_161 = V_159 ;
if ( F_23 ( V_37 ) )
return - V_162 ;
if ( ! F_27 ( V_161 -> V_163 ) )
return - V_164 ;
V_37 -> V_165 &= ~ V_166 ;
memcpy ( V_37 -> V_42 , V_161 -> V_163 , V_41 ) ;
return F_19 ( V_37 ) ;
}
static int F_72 ( struct V_36 * V_37 , struct V_167 * V_168 , int V_169 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
if ( ! F_23 ( V_37 ) )
return - V_170 ;
return F_73 ( & V_2 -> V_102 , F_74 ( V_168 ) , V_169 , NULL ) ;
}
static void F_75 ( struct V_36 * V_37 ,
struct V_171 * V_172 )
{
F_76 ( V_172 -> V_173 , L_19 , sizeof( V_172 -> V_173 ) ) ;
F_76 ( V_172 -> V_174 , L_20 , sizeof( V_172 -> V_174 ) ) ;
F_76 ( V_172 -> V_175 , F_77 ( V_37 -> V_37 . V_176 ) , sizeof( V_172 -> V_175 ) ) ;
}
static T_5 F_78 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return V_2 -> V_177 ;
}
static void F_79 ( struct V_36 * V_37 , T_5 V_178 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
V_2 -> V_177 = V_178 ;
}
static int F_80 ( struct V_36 * V_37 , struct V_179 * V_169 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_81 ( & V_2 -> V_102 , V_169 ) ;
}
static int F_82 ( struct V_36 * V_37 , struct V_179 * V_169 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_83 ( & V_2 -> V_102 , V_169 ) ;
}
static T_5 F_84 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_85 ( & V_2 -> V_102 ) ;
}
static int F_86 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_87 ( & V_2 -> V_102 ) ;
}
static void F_88 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = V_181 -> V_106 ;
unsigned V_4 ;
V_4 = F_10 ( V_2 , V_182 ) ;
V_181 -> V_183 = ( V_4 & V_184 ) ? 1 : 0 ;
V_181 -> V_185 = ( V_4 & V_186 ) ? 1 : 0 ;
V_181 -> V_187 = ( V_4 & V_188 ) ? 1 : 0 ;
}
static void F_89 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = V_181 -> V_106 ;
unsigned V_4 = V_189 ;
if ( V_181 -> V_190 )
V_4 |= V_191 ;
if ( V_181 -> V_192 )
V_4 |= V_193 ;
if ( V_181 -> V_185 )
V_4 |= V_186 ;
if ( V_181 -> V_187 )
V_4 |= V_188 ;
F_1 ( V_2 , V_182 , V_4 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_44 & V_45 ) )
return - V_194 ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_182 , V_189 | V_188 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
unsigned V_4 = F_10 ( V_2 , V_182 ) ;
F_1 ( V_2 , V_182 , V_4 & ~ V_189 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
static int F_92 ( struct V_36 * V_37 ,
struct V_195 * V_181 , T_2 * V_106 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_196 = V_181 -> V_196 ;
int V_16 = V_181 -> V_16 ;
T_6 V_197 ;
if ( V_16 != 1 )
return - V_170 ;
if ( V_181 -> V_198 != V_199 )
return - V_170 ;
if ( F_90 ( V_2 ) )
return - V_194 ;
F_93 ( & V_2 -> V_200 , true ) ;
F_94 ( & V_2 -> V_200 , V_196 / 2 , & V_197 ) ;
if ( V_196 & 1 ) {
V_197 &= 0xff ;
V_197 |= * V_106 << 8 ;
} else {
V_197 &= 0xff00 ;
V_197 |= * V_106 ;
}
F_95 ( & V_2 -> V_200 , V_196 / 2 , V_197 ) ;
F_93 ( & V_2 -> V_200 , false ) ;
F_91 ( V_2 ) ;
return 0 ;
}
static int F_96 ( struct V_36 * V_37 ,
struct V_195 * V_181 , T_2 * V_106 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_196 = V_181 -> V_196 ;
int V_16 = V_181 -> V_16 ;
if ( V_16 & 1 || V_196 & 1 )
return - V_170 ;
if ( F_90 ( V_2 ) )
return - V_194 ;
V_181 -> V_198 = V_199 ;
F_97 ( & V_2 -> V_200 , V_196 / 2 , ( T_1 * ) V_106 , V_16 / 2 ) ;
F_91 ( V_2 ) ;
return 0 ;
}
static int F_98 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return V_2 -> V_44 & V_45 ? 128 : 0 ;
}
static int F_99 ( int V_3 )
{
switch ( V_3 ) {
case V_201 :
return V_202 ;
case V_203 :
return V_204 ;
case V_205 :
return V_206 ;
case V_207 :
return V_208 ;
case V_209 :
return V_210 ;
case V_211 :
return V_212 ;
}
return 0x0 ;
}
static int F_100 ( struct V_36 * V_37 , int V_213 , int V_3 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_214 ;
int V_215 ;
V_214 = F_99 ( V_3 ) ;
if ( ! V_214 )
return 0x0 ;
F_21 ( & V_2 -> V_39 ) ;
V_215 = F_10 ( V_2 , V_214 ) ;
F_24 ( & V_2 -> V_39 ) ;
return V_215 ;
}
static void F_101 ( struct V_36 * V_37 ,
int V_216 , int V_3 , int V_217 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_214 ;
V_214 = F_99 ( V_3 ) ;
if ( V_214 ) {
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_214 , V_217 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
unsigned V_218 = V_219 | V_220 ;
int V_12 = 0 ;
unsigned V_221 ;
V_221 = F_10 ( V_2 , V_222 ) ;
if ( ( V_221 & V_218 ) != V_218 ) {
F_103 ( V_2 -> V_18 , L_21 ) ;
return 0 ;
}
if ( V_221 & V_223 ) {
F_5 ( V_2 -> V_18 , L_22 ) ;
V_12 |= 1 ;
}
if ( V_221 & V_224 ) {
F_5 ( V_2 -> V_18 , L_23 ) ;
V_12 |= 2 ;
}
return 0 ;
}
static int F_104 ( struct V_225 * V_226 , T_8 V_227 )
{
struct V_1 * V_2 = F_105 ( & V_226 -> V_37 ) ;
struct V_36 * V_37 = V_2 -> V_18 ;
if ( F_23 ( V_37 ) ) {
F_106 ( V_37 ) ;
F_58 ( V_37 ) ;
}
return 0 ;
}
static int F_107 ( struct V_225 * V_226 )
{
struct V_1 * V_2 = F_105 ( & V_226 -> V_37 ) ;
struct V_36 * V_37 = V_2 -> V_18 ;
if ( F_23 ( V_37 ) ) {
F_55 ( V_37 ) ;
F_108 ( V_37 ) ;
}
return 0 ;
}
static int T_9 F_109 ( struct V_225 * V_226 )
{
struct V_36 * V_228 ;
struct V_1 * V_2 ;
int V_12 ;
unsigned V_229 ;
V_228 = F_110 ( sizeof( struct V_1 ) ) ;
if ( ! V_228 )
return - V_230 ;
V_226 -> V_231 = 8 ;
V_2 = F_20 ( V_228 ) ;
V_2 -> V_18 = V_228 ;
V_2 -> V_17 = V_226 ;
V_2 -> V_86 = 6144 ;
F_111 ( & V_2 -> V_39 ) ;
F_112 ( & V_2 -> V_146 ) ;
F_113 ( & V_2 -> V_114 , F_52 ) ;
F_113 ( & V_2 -> V_48 , F_42 ) ;
F_113 ( & V_2 -> V_143 , F_66 ) ;
F_114 ( & V_2 -> V_10 ) ;
F_115 ( & V_2 -> V_7 , & V_2 -> V_10 ) ;
F_114 ( & V_2 -> V_27 ) ;
F_115 ( & V_2 -> V_28 [ 0 ] , & V_2 -> V_27 ) ;
F_115 ( & V_2 -> V_28 [ 1 ] , & V_2 -> V_27 ) ;
V_2 -> V_200 . V_106 = V_2 ;
V_2 -> V_200 . V_232 = V_233 ;
V_2 -> V_200 . V_234 = F_88 ;
V_2 -> V_200 . V_235 = F_89 ;
V_2 -> V_102 . V_37 = V_228 ;
V_2 -> V_102 . V_236 = 1 ,
V_2 -> V_102 . V_237 = 1 ;
V_2 -> V_102 . V_238 = 0xf ;
V_2 -> V_102 . V_239 = F_100 ;
V_2 -> V_102 . V_240 = F_101 ;
F_116 ( & V_226 -> V_37 , L_24 , V_177 ) ;
V_2 -> V_177 = F_117 ( V_177 , ( V_241 |
V_242 |
V_243 ) ) ;
F_118 ( & V_2 -> V_116 ) ;
F_119 ( V_228 , & V_244 ) ;
F_120 ( V_228 , & V_226 -> V_37 ) ;
F_121 ( & V_226 -> V_37 , V_2 ) ;
V_228 -> V_245 = V_246 ;
V_228 -> V_247 = & V_248 ;
V_228 -> V_46 = V_226 -> V_46 ;
F_15 ( V_2 , V_249 ) ;
V_229 = F_10 ( V_2 , V_250 ) ;
if ( ( V_229 & ~ V_251 ) != V_252 ) {
F_44 ( & V_226 -> V_37 , L_25 ) ;
V_12 = - V_253 ;
goto V_254;
}
V_2 -> V_44 = F_10 ( V_2 , V_255 ) ;
if ( V_2 -> V_44 & V_45 )
V_2 -> V_256 = 128 ;
else
V_2 -> V_256 = 0 ;
F_102 ( V_2 ) ;
F_26 ( V_2 ) ;
V_12 = F_122 ( V_226 -> V_46 , F_29 , V_257 ,
V_228 -> V_258 , V_2 ) ;
if ( V_12 < 0 ) {
F_44 ( & V_226 -> V_37 , L_26 ) ;
goto V_259;
}
V_12 = F_123 ( V_228 ) ;
if ( V_12 ) {
F_44 ( & V_226 -> V_37 , L_27 ) ;
goto V_260;
}
F_124 ( V_228 , L_28 ,
F_125 ( V_229 ) , V_228 -> V_42 , V_228 -> V_46 ,
V_2 -> V_44 & V_45 ? L_29 : L_30 ) ;
return 0 ;
V_260:
F_126 ( V_228 -> V_46 , V_2 ) ;
V_254:
V_259:
F_127 ( V_228 ) ;
return V_12 ;
}
static int T_10 F_128 ( struct V_225 * V_226 )
{
struct V_1 * V_261 = F_105 ( & V_226 -> V_37 ) ;
if ( F_129 ( V_261 ) )
F_116 ( & V_226 -> V_37 , L_31 ) ;
F_130 ( V_261 -> V_18 ) ;
F_126 ( V_226 -> V_46 , V_261 ) ;
F_127 ( V_261 -> V_18 ) ;
return 0 ;
}
static int T_11 F_131 ( void )
{
return F_132 ( & V_262 ) ;
}
static void T_12 F_133 ( void )
{
F_134 ( & V_262 ) ;
}
