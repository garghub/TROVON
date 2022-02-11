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
F_28 ( V_37 -> V_42 ) ;
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
if ( V_76 & V_80 ) {
V_77 |= V_80 ;
}
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
if ( V_76 & V_85 )
F_45 ( V_2 -> V_18 ) ;
F_46 ( V_2 -> V_18 -> V_46 ) ;
}
static inline unsigned F_47 ( unsigned V_16 )
{
return F_36 ( V_16 + 4 , 4 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_55 * V_102 , bool V_46 )
{
struct V_5 * V_6 = V_2 -> V_28 ;
struct V_8 * V_9 = & V_2 -> V_27 ;
unsigned V_103 = 0 ;
int V_12 ;
F_18 ( V_2 , V_104 , V_2 -> V_18 , L_13 ,
V_52 , V_102 , V_102 -> V_16 , V_102 -> V_105 , V_46 ) ;
V_103 = V_2 -> V_103 ++ ;
V_103 &= V_106 ;
if ( V_46 )
V_103 |= V_107 ;
V_2 -> V_108 . V_11 [ 1 ] = V_109 ;
V_2 -> V_108 . V_110 [ 1 ] = F_2 ( V_103 ) ;
V_2 -> V_108 . V_110 [ 2 ] = F_2 ( V_102 -> V_16 ) ;
V_6 -> V_14 = & V_2 -> V_108 . V_11 [ 1 ] ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 5 ;
V_6 ++ ;
V_6 -> V_14 = V_102 -> V_105 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = F_36 ( V_102 -> V_16 , 4 ) ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_6 , V_52 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_55 * V_11 )
{
struct V_36 * V_37 = V_2 -> V_18 ;
V_37 -> V_71 . V_111 += V_11 -> V_16 ;
V_37 -> V_71 . V_112 ++ ;
F_50 ( V_11 ) ;
}
static void F_51 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_43 ( V_75 , struct V_1 , V_113 ) ;
struct V_55 * V_11 ;
bool V_114 = F_52 ( & V_2 -> V_115 ) ;
F_21 ( & V_2 -> V_39 ) ;
while ( ! V_114 ) {
V_11 = F_53 ( & V_2 -> V_115 ) ;
V_114 = F_52 ( & V_2 -> V_115 ) ;
if ( V_11 != NULL ) {
F_1 ( V_2 , V_65 , V_2 -> V_66 | V_67 ) ;
F_48 ( V_2 , V_11 , V_114 ) ;
F_1 ( V_2 , V_65 , V_2 -> V_66 ) ;
F_1 ( V_2 , V_116 , V_117 ) ;
F_49 ( V_2 , V_11 ) ;
}
}
F_24 ( & V_2 -> V_39 ) ;
}
static int F_54 ( struct V_36 * V_37 )
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
F_1 ( V_2 , V_100 , ( V_127 |
V_128 |
V_129 |
V_130 |
V_131 ) ) ;
F_1 ( V_2 , V_98 , V_132 ) ;
F_1 ( V_2 , V_133 , 1000 ) ;
F_1 ( V_2 , V_134 , 4096 ) ;
F_1 ( V_2 , V_135 , 10 ) ;
V_2 -> V_66 = ( V_136 |
V_137 |
V_138 ) ;
F_1 ( V_2 , V_65 , V_2 -> V_66 ) ;
#define F_55 (IRQ_LCI | \
IRQ_TXI | \
IRQ_RXI | \
IRQ_SPIBEI | \
IRQ_TXPSI | \
IRQ_RXPSI)
V_2 -> V_139 = F_55 ;
F_1 ( V_2 , V_78 , F_55 ) ;
F_1 ( V_2 , V_140 , F_55 ) ;
F_56 ( V_2 -> V_18 ) ;
F_18 ( V_2 , V_118 , V_2 -> V_18 , L_15 ) ;
F_24 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_57 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
F_58 ( V_2 , V_141 , V_37 , L_16 ) ;
F_59 ( V_37 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_60 ( & V_2 -> V_48 ) ;
F_60 ( & V_2 -> V_113 ) ;
F_60 ( & V_2 -> V_142 ) ;
F_1 ( V_2 , V_140 , 0x0000 ) ;
F_1 ( V_2 , V_78 , 0xffff ) ;
F_1 ( V_2 , V_100 , 0x0000 ) ;
F_1 ( V_2 , V_120 , 0x0000 ) ;
F_17 ( V_2 , V_43 ) ;
while ( ! F_52 ( & V_2 -> V_115 ) ) {
struct V_55 * V_11 = F_53 ( & V_2 -> V_115 ) ;
F_18 ( V_2 , V_141 , V_2 -> V_18 ,
L_17 , V_52 , V_11 ) ;
F_50 ( V_11 ) ;
}
F_24 ( & V_2 -> V_39 ) ;
return 0 ;
}
static T_7 F_61 ( struct V_55 * V_56 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
unsigned V_143 = F_47 ( V_56 -> V_16 ) ;
T_7 V_12 = V_144 ;
F_18 ( V_2 , V_104 , V_2 -> V_18 ,
L_18 , V_52 , V_56 , V_56 -> V_16 , V_56 -> V_105 ) ;
F_62 ( & V_2 -> V_145 ) ;
if ( V_143 > V_2 -> V_86 ) {
F_59 ( V_37 ) ;
V_12 = V_146 ;
} else {
V_2 -> V_86 -= V_143 ;
F_63 ( & V_2 -> V_115 , V_56 ) ;
}
F_64 ( & V_2 -> V_145 ) ;
F_31 ( & V_2 -> V_113 ) ;
return V_12 ;
}
static void F_65 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_43 ( V_75 , struct V_1 , V_142 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_100 , 0x00 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
static void F_66 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
struct V_90 V_92 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
if ( V_37 -> V_147 & V_148 ) {
V_92 . V_101 = V_149 | V_150 ;
} else if ( V_37 -> V_147 & V_151 ) {
V_92 . V_101 = ( V_152 | V_149 |
V_127 | V_153 ) ;
} else if ( V_37 -> V_147 & V_154 && ! F_67 ( V_37 ) ) {
struct V_155 * V_156 ;
T_5 V_157 ;
F_68 (ha, dev) {
V_157 = F_69 ( V_41 , V_156 -> V_158 ) ;
V_157 >>= ( 32 - 6 ) ;
V_92 . V_94 [ V_157 >> 4 ] |= ( 1 << ( V_157 & 0xf ) ) ;
}
V_92 . V_101 = V_152 | V_127 ;
} else {
V_92 . V_101 = V_127 ;
}
V_92 . V_101 |= ( V_130 |
V_129 |
V_131 |
V_128 ) ;
V_92 . V_99 |= V_132 ;
F_62 ( & V_2 -> V_145 ) ;
if ( memcmp ( & V_92 , & V_2 -> V_92 , sizeof( V_92 ) ) != 0 ) {
memcpy ( & V_2 -> V_92 , & V_92 , sizeof( V_2 -> V_92 ) ) ;
F_31 ( & V_2 -> V_142 ) ;
}
F_64 ( & V_2 -> V_145 ) ;
}
static int F_70 ( struct V_36 * V_37 , void * V_158 )
{
struct V_159 * V_160 = V_158 ;
if ( F_23 ( V_37 ) )
return - V_161 ;
if ( ! F_27 ( V_160 -> V_162 ) )
return - V_163 ;
memcpy ( V_37 -> V_42 , V_160 -> V_162 , V_41 ) ;
return F_19 ( V_37 ) ;
}
static int F_71 ( struct V_36 * V_37 , struct V_164 * V_165 , int V_166 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
if ( ! F_23 ( V_37 ) )
return - V_167 ;
return F_72 ( & V_2 -> V_168 , F_73 ( V_165 ) , V_166 , NULL ) ;
}
static void F_74 ( struct V_36 * V_37 ,
struct V_169 * V_170 )
{
F_75 ( V_170 -> V_171 , L_19 , sizeof( V_170 -> V_171 ) ) ;
F_75 ( V_170 -> V_172 , L_20 , sizeof( V_170 -> V_172 ) ) ;
F_75 ( V_170 -> V_173 , F_76 ( V_37 -> V_37 . V_174 ) , sizeof( V_170 -> V_173 ) ) ;
}
static T_5 F_77 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return V_2 -> V_175 ;
}
static void F_78 ( struct V_36 * V_37 , T_5 V_176 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
V_2 -> V_175 = V_176 ;
}
static int F_79 ( struct V_36 * V_37 , struct V_177 * V_166 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_80 ( & V_2 -> V_168 , V_166 ) ;
}
static int F_81 ( struct V_36 * V_37 , struct V_177 * V_166 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_82 ( & V_2 -> V_168 , V_166 ) ;
}
static T_5 F_83 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_84 ( & V_2 -> V_168 ) ;
}
static int F_85 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return F_86 ( & V_2 -> V_168 ) ;
}
static void F_87 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = V_179 -> V_105 ;
unsigned V_4 ;
V_4 = F_10 ( V_2 , V_180 ) ;
V_179 -> V_181 = ( V_4 & V_182 ) ? 1 : 0 ;
V_179 -> V_183 = ( V_4 & V_184 ) ? 1 : 0 ;
V_179 -> V_185 = ( V_4 & V_186 ) ? 1 : 0 ;
}
static void F_88 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = V_179 -> V_105 ;
unsigned V_4 = V_187 ;
if ( V_179 -> V_188 )
V_4 |= V_189 ;
if ( V_179 -> V_190 )
V_4 |= V_191 ;
if ( V_179 -> V_183 )
V_4 |= V_184 ;
if ( V_179 -> V_185 )
V_4 |= V_186 ;
F_1 ( V_2 , V_180 , V_4 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_44 & V_45 ) )
return - V_192 ;
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_180 , V_187 | V_186 ) ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned V_4 = F_10 ( V_2 , V_180 ) ;
F_1 ( V_2 , V_180 , V_4 & ~ V_187 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
static int F_91 ( struct V_36 * V_37 ,
struct V_193 * V_179 , T_2 * V_105 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_194 = V_179 -> V_194 ;
int V_16 = V_179 -> V_16 ;
T_6 V_195 ;
if ( V_16 != 1 )
return - V_167 ;
if ( V_179 -> V_196 != V_197 )
return - V_167 ;
if ( F_89 ( V_2 ) )
return - V_192 ;
F_92 ( & V_2 -> V_198 , true ) ;
F_93 ( & V_2 -> V_198 , V_194 / 2 , & V_195 ) ;
if ( V_194 & 1 ) {
V_195 &= 0xff ;
V_195 |= * V_105 << 8 ;
} else {
V_195 &= 0xff00 ;
V_195 |= * V_105 ;
}
F_94 ( & V_2 -> V_198 , V_194 / 2 , V_195 ) ;
F_92 ( & V_2 -> V_198 , false ) ;
F_90 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_36 * V_37 ,
struct V_193 * V_179 , T_2 * V_105 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_194 = V_179 -> V_194 ;
int V_16 = V_179 -> V_16 ;
if ( V_16 & 1 || V_194 & 1 )
return - V_167 ;
if ( F_89 ( V_2 ) )
return - V_192 ;
V_179 -> V_196 = V_197 ;
F_96 ( & V_2 -> V_198 , V_194 / 2 , ( T_1 * ) V_105 , V_16 / 2 ) ;
F_90 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
return V_2 -> V_44 & V_45 ? 128 : 0 ;
}
static int F_98 ( int V_3 )
{
switch ( V_3 ) {
case V_199 :
return V_200 ;
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
}
return 0x0 ;
}
static int F_99 ( struct V_36 * V_37 , int V_211 , int V_3 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_212 ;
int V_213 ;
V_212 = F_98 ( V_3 ) ;
if ( ! V_212 )
return 0x0 ;
F_21 ( & V_2 -> V_39 ) ;
V_213 = F_10 ( V_2 , V_212 ) ;
F_24 ( & V_2 -> V_39 ) ;
return V_213 ;
}
static void F_100 ( struct V_36 * V_37 ,
int V_214 , int V_3 , int V_215 )
{
struct V_1 * V_2 = F_20 ( V_37 ) ;
int V_212 ;
V_212 = F_98 ( V_3 ) ;
if ( V_212 ) {
F_21 ( & V_2 -> V_39 ) ;
F_1 ( V_2 , V_212 , V_215 ) ;
F_24 ( & V_2 -> V_39 ) ;
}
}
static int F_101 ( struct V_1 * V_2 )
{
unsigned V_216 = V_217 | V_218 ;
int V_12 = 0 ;
unsigned V_219 ;
V_219 = F_10 ( V_2 , V_220 ) ;
if ( ( V_219 & V_216 ) != V_216 ) {
F_102 ( V_2 -> V_18 , L_21 ) ;
return 0 ;
}
if ( V_219 & V_221 ) {
F_5 ( V_2 -> V_18 , L_22 ) ;
V_12 |= 1 ;
}
if ( V_219 & V_222 ) {
F_5 ( V_2 -> V_18 , L_23 ) ;
V_12 |= 2 ;
}
return 0 ;
}
static int F_103 ( struct V_223 * V_224 , T_8 V_225 )
{
struct V_1 * V_2 = F_104 ( & V_224 -> V_37 ) ;
struct V_36 * V_37 = V_2 -> V_18 ;
if ( F_23 ( V_37 ) ) {
F_105 ( V_37 ) ;
F_57 ( V_37 ) ;
}
return 0 ;
}
static int F_106 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_104 ( & V_224 -> V_37 ) ;
struct V_36 * V_37 = V_2 -> V_18 ;
if ( F_23 ( V_37 ) ) {
F_54 ( V_37 ) ;
F_107 ( V_37 ) ;
}
return 0 ;
}
static int T_9 F_108 ( struct V_223 * V_224 )
{
struct V_36 * V_226 ;
struct V_1 * V_2 ;
int V_12 ;
V_226 = F_109 ( sizeof( struct V_1 ) ) ;
if ( ! V_226 ) {
F_44 ( & V_224 -> V_37 , L_24 ) ;
return - V_227 ;
}
V_224 -> V_228 = 8 ;
V_2 = F_20 ( V_226 ) ;
V_2 -> V_18 = V_226 ;
V_2 -> V_17 = V_224 ;
V_2 -> V_86 = 6144 ;
F_110 ( & V_2 -> V_39 ) ;
F_111 ( & V_2 -> V_145 ) ;
F_112 ( & V_2 -> V_113 , F_51 ) ;
F_112 ( & V_2 -> V_48 , F_42 ) ;
F_112 ( & V_2 -> V_142 , F_65 ) ;
F_113 ( & V_2 -> V_10 ) ;
F_114 ( & V_2 -> V_7 , & V_2 -> V_10 ) ;
F_113 ( & V_2 -> V_27 ) ;
F_114 ( & V_2 -> V_28 [ 0 ] , & V_2 -> V_27 ) ;
F_114 ( & V_2 -> V_28 [ 1 ] , & V_2 -> V_27 ) ;
V_2 -> V_198 . V_105 = V_2 ;
V_2 -> V_198 . V_229 = V_230 ;
V_2 -> V_198 . V_231 = F_87 ;
V_2 -> V_198 . V_232 = F_88 ;
V_2 -> V_168 . V_37 = V_226 ;
V_2 -> V_168 . V_233 = 1 ,
V_2 -> V_168 . V_234 = 1 ;
V_2 -> V_168 . V_235 = 0xf ;
V_2 -> V_168 . V_236 = F_99 ;
V_2 -> V_168 . V_237 = F_100 ;
F_115 ( & V_224 -> V_37 , L_25 , V_175 ) ;
V_2 -> V_175 = F_116 ( V_175 , ( V_238 |
V_239 |
V_240 ) ) ;
F_117 ( & V_2 -> V_115 ) ;
F_118 ( V_226 , & V_241 ) ;
F_119 ( V_226 , & V_224 -> V_37 ) ;
F_120 ( & V_224 -> V_37 , V_2 ) ;
V_226 -> V_242 = V_243 ;
V_226 -> V_244 = & V_245 ;
V_226 -> V_46 = V_224 -> V_46 ;
F_15 ( V_2 , V_246 ) ;
if ( ( F_10 ( V_2 , V_247 ) & ~ V_248 ) != V_249 ) {
F_44 ( & V_224 -> V_37 , L_26 ) ;
V_12 = - V_250 ;
goto V_251;
}
V_2 -> V_44 = F_10 ( V_2 , V_252 ) ;
if ( V_2 -> V_44 & V_45 )
V_2 -> V_253 = 128 ;
else
V_2 -> V_253 = 0 ;
F_101 ( V_2 ) ;
F_26 ( V_2 ) ;
V_12 = F_121 ( V_224 -> V_46 , F_29 , V_254 ,
V_226 -> V_255 , V_2 ) ;
if ( V_12 < 0 ) {
F_44 ( & V_224 -> V_37 , L_27 ) ;
goto V_256;
}
V_12 = F_122 ( V_226 ) ;
if ( V_12 ) {
F_44 ( & V_224 -> V_37 , L_28 ) ;
goto V_257;
}
F_123 ( V_226 , L_29 ,
F_124 ( F_10 ( V_2 , V_247 ) ) ,
V_226 -> V_42 , V_226 -> V_46 ,
V_2 -> V_44 & V_45 ? L_30 : L_31 ) ;
return 0 ;
V_257:
F_125 ( V_226 -> V_46 , V_226 ) ;
V_251:
V_256:
F_126 ( V_226 ) ;
return V_12 ;
}
static int T_10 F_127 ( struct V_223 * V_224 )
{
struct V_1 * V_258 = F_104 ( & V_224 -> V_37 ) ;
if ( F_128 ( V_258 ) )
F_115 ( & V_224 -> V_37 , L_32 ) ;
F_129 ( V_258 -> V_18 ) ;
F_125 ( V_224 -> V_46 , V_258 ) ;
F_126 ( V_258 -> V_18 ) ;
return 0 ;
}
static int T_11 F_130 ( void )
{
return F_131 ( & V_259 ) ;
}
static void T_12 F_132 ( void )
{
F_133 ( & V_259 ) ;
}
