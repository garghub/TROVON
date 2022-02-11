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
static int F_17 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
int V_33 ;
F_19 ( & V_2 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ )
F_6 ( V_2 , F_20 ( V_33 ) , V_32 -> V_36 [ V_33 ] ) ;
F_21 ( & V_2 -> V_34 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_18 ;
F_23 ( V_32 -> V_36 ) ;
F_17 ( V_32 ) ;
}
static T_4 F_24 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
F_25 ( V_37 ) ;
F_26 ( & V_2 -> V_39 ) ;
return V_40 ;
}
static void F_27 ( struct V_1 * V_2 , T_2 * V_41 , unsigned V_16 )
{
struct V_5 * V_6 = V_2 -> V_28 ;
struct V_8 * V_9 = & V_2 -> V_27 ;
T_2 V_11 [ 1 ] ;
int V_12 ;
F_28 ( V_2 , V_42 , V_2 -> V_18 ,
L_3 , V_43 , V_16 , V_41 ) ;
V_11 [ 0 ] = V_44 ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 1 ;
V_6 ++ ;
V_6 -> V_15 = V_41 ;
V_6 -> V_14 = NULL ;
V_6 -> V_16 = V_16 ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_4 , V_43 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_45 )
{
F_30 ( V_2 -> V_18 ,
L_5 ,
V_45 [ 4 ] , V_45 [ 5 ] , V_45 [ 6 ] , V_45 [ 7 ] ,
V_45 [ 8 ] , V_45 [ 9 ] , V_45 [ 10 ] , V_45 [ 11 ] ,
V_45 [ 12 ] , V_45 [ 13 ] , V_45 [ 14 ] , V_45 [ 15 ] ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
unsigned V_48 ;
unsigned V_49 ;
unsigned V_50 ;
T_5 V_51 ;
T_2 * V_45 ;
V_48 = F_9 ( V_2 , V_52 ) ;
F_28 ( V_2 , V_42 , V_2 -> V_18 ,
L_6 , V_43 , V_48 ) ;
for (; V_48 != 0 ; V_48 -- ) {
V_51 = F_12 ( V_2 , V_53 ) ;
V_50 = V_51 & 0xffff ;
V_49 = V_51 >> 16 ;
F_28 ( V_2 , V_42 , V_2 -> V_18 ,
L_7 , V_50 , V_49 ) ;
F_1 ( V_2 , V_54 , V_55 | 0x00 ) ;
F_1 ( V_2 , V_56 ,
V_2 -> V_57 | V_58 | V_59 ) ;
if ( V_49 > 4 ) {
unsigned int V_60 ;
V_49 -= 4 ;
V_60 = F_32 ( V_49 , 4 ) ;
V_47 = F_33 ( V_2 -> V_18 , V_60 ) ;
if ( V_47 ) {
V_45 = F_34 ( V_47 , V_49 ) - 8 ;
F_27 ( V_2 , V_45 , V_60 + 8 ) ;
if ( F_35 ( V_2 ) )
F_29 ( V_2 , V_45 ) ;
V_47 -> V_61 = F_36 ( V_47 , V_2 -> V_18 ) ;
F_37 ( V_47 ) ;
V_2 -> V_18 -> V_62 . V_63 ++ ;
V_2 -> V_18 -> V_62 . V_64 += V_49 ;
}
}
F_1 ( V_2 , V_56 , V_2 -> V_57 ) ;
}
}
static void F_38 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_39 ( V_66 , struct V_1 , V_39 ) ;
unsigned V_67 ;
unsigned V_68 = 0 ;
F_19 ( & V_2 -> V_34 ) ;
V_67 = F_10 ( V_2 , V_69 ) ;
F_28 ( V_2 , V_70 , V_2 -> V_18 ,
L_8 , V_43 , V_67 ) ;
if ( V_67 & V_71 ) {
V_68 |= V_71 ;
}
if ( V_67 & V_72 ) {
T_6 V_73 = F_10 ( V_2 , V_74 ) ;
V_73 &= ~ V_75 ;
F_1 ( V_2 , V_74 , V_73 | V_76 ) ;
V_68 |= V_72 ;
}
if ( V_67 & V_77 )
V_68 |= V_77 ;
if ( V_67 & V_78 ) {
V_68 |= V_78 ;
V_2 -> V_79 = F_10 ( V_2 , V_80 ) ;
F_28 ( V_2 , V_70 , V_2 -> V_18 ,
L_9 , V_43 , V_2 -> V_79 ) ;
}
if ( V_67 & V_81 )
V_68 |= V_81 ;
if ( V_67 & V_82 ) {
F_40 ( & V_2 -> V_17 -> V_32 , L_10 , V_43 ) ;
V_68 |= V_82 ;
}
F_1 ( V_2 , V_69 , V_68 ) ;
if ( V_67 & V_81 ) {
F_31 ( V_2 ) ;
}
if ( V_67 & V_77 ) {
struct V_83 * V_84 = & V_2 -> V_85 ;
F_1 ( V_2 , V_86 , V_84 -> V_87 [ 0 ] ) ;
F_1 ( V_2 , V_88 , V_84 -> V_87 [ 1 ] ) ;
F_1 ( V_2 , V_89 , V_84 -> V_87 [ 2 ] ) ;
F_1 ( V_2 , V_90 , V_84 -> V_87 [ 3 ] ) ;
F_1 ( V_2 , V_91 , V_84 -> V_92 ) ;
F_1 ( V_2 , V_93 , V_84 -> V_94 ) ;
}
F_21 ( & V_2 -> V_34 ) ;
if ( V_67 & V_78 )
F_41 ( V_2 -> V_18 ) ;
F_42 ( V_2 -> V_18 -> V_37 ) ;
}
static inline unsigned F_43 ( unsigned V_16 )
{
return F_32 ( V_16 + 4 , 4 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_46 * V_95 , bool V_37 )
{
struct V_5 * V_6 = V_2 -> V_28 ;
struct V_8 * V_9 = & V_2 -> V_27 ;
unsigned V_96 = 0 ;
int V_12 ;
F_28 ( V_2 , V_97 , V_2 -> V_18 , L_11 ,
V_43 , V_95 , V_95 -> V_16 , V_95 -> V_98 , V_37 ) ;
V_96 = V_2 -> V_96 ++ ;
V_96 &= V_99 ;
if ( V_37 )
V_96 |= V_100 ;
V_2 -> V_101 . V_11 [ 1 ] = V_102 ;
V_2 -> V_101 . V_103 [ 1 ] = F_2 ( V_96 ) ;
V_2 -> V_101 . V_103 [ 2 ] = F_2 ( V_95 -> V_16 ) ;
V_6 -> V_14 = & V_2 -> V_101 . V_11 [ 1 ] ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = 5 ;
V_6 ++ ;
V_6 -> V_14 = V_95 -> V_98 ;
V_6 -> V_15 = NULL ;
V_6 -> V_16 = F_32 ( V_95 -> V_16 , 4 ) ;
V_12 = F_4 ( V_2 -> V_17 , V_9 ) ;
if ( V_12 < 0 )
F_5 ( V_2 -> V_18 , L_4 , V_43 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_46 * V_11 )
{
struct V_31 * V_32 = V_2 -> V_18 ;
V_32 -> V_62 . V_104 += V_11 -> V_16 ;
V_32 -> V_62 . V_105 ++ ;
F_46 ( V_11 ) ;
}
static void F_47 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_39 ( V_66 , struct V_1 , V_106 ) ;
struct V_46 * V_11 ;
bool V_107 = F_48 ( & V_2 -> V_108 ) ;
F_19 ( & V_2 -> V_34 ) ;
while ( ! V_107 ) {
V_11 = F_49 ( & V_2 -> V_108 ) ;
V_107 = F_48 ( & V_2 -> V_108 ) ;
if ( V_11 != NULL ) {
F_1 ( V_2 , V_56 , V_2 -> V_57 | V_58 ) ;
F_44 ( V_2 , V_11 , V_107 ) ;
F_1 ( V_2 , V_56 , V_2 -> V_57 ) ;
F_1 ( V_2 , V_109 , V_110 ) ;
F_45 ( V_2 , V_11 ) ;
}
}
F_21 ( & V_2 -> V_34 ) ;
}
static void F_50 ( struct V_1 * V_2 , unsigned V_111 )
{
unsigned V_73 ;
F_28 ( V_2 , V_112 , V_2 -> V_18 , L_12 , V_111 ) ;
V_73 = F_10 ( V_2 , V_74 ) ;
V_73 &= ~ V_113 ;
V_73 |= V_111 ;
F_1 ( V_2 , V_74 , V_73 ) ;
}
static int F_51 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
F_19 ( & V_2 -> V_34 ) ;
F_28 ( V_2 , V_114 , V_2 -> V_18 , L_13 ) ;
F_50 ( V_2 , V_115 ) ;
F_15 ( V_2 , V_116 ) ;
F_1 ( V_2 , V_117 , ( V_118 |
V_119 |
V_120 |
V_121 ) ) ;
F_1 ( V_2 , V_122 , V_123 ) ;
F_1 ( V_2 , V_93 , ( V_124 |
V_125 |
V_126 |
V_127 |
V_128 ) ) ;
F_1 ( V_2 , V_91 , V_129 ) ;
F_1 ( V_2 , V_130 , 1000 ) ;
F_1 ( V_2 , V_131 , 4096 ) ;
F_1 ( V_2 , V_132 , 10 ) ;
V_2 -> V_57 = ( V_133 |
V_134 |
V_135 ) ;
F_1 ( V_2 , V_56 , V_2 -> V_57 ) ;
#define F_52 (IRQ_LCI | \
IRQ_TXI | \
IRQ_RXI | \
IRQ_SPIBEI | \
IRQ_TXPSI | \
IRQ_RXPSI)
V_2 -> V_136 = F_52 ;
F_1 ( V_2 , V_69 , F_52 ) ;
F_1 ( V_2 , V_137 , F_52 ) ;
F_53 ( V_2 -> V_18 ) ;
F_28 ( V_2 , V_114 , V_2 -> V_18 , L_14 ) ;
F_21 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_54 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
F_55 ( V_2 , V_138 , V_32 , L_15 ) ;
F_56 ( V_32 ) ;
F_19 ( & V_2 -> V_34 ) ;
F_57 ( & V_2 -> V_39 ) ;
F_57 ( & V_2 -> V_106 ) ;
F_57 ( & V_2 -> V_139 ) ;
F_1 ( V_2 , V_137 , 0x0000 ) ;
F_1 ( V_2 , V_69 , 0xffff ) ;
F_1 ( V_2 , V_93 , 0x0000 ) ;
F_1 ( V_2 , V_117 , 0x0000 ) ;
F_50 ( V_2 , V_140 ) ;
while ( ! F_48 ( & V_2 -> V_108 ) ) {
struct V_46 * V_11 = F_49 ( & V_2 -> V_108 ) ;
F_28 ( V_2 , V_138 , V_2 -> V_18 ,
L_16 , V_43 , V_11 ) ;
F_46 ( V_11 ) ;
}
F_21 ( & V_2 -> V_34 ) ;
return 0 ;
}
static T_7 F_58 ( struct V_46 * V_47 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
unsigned V_141 = F_43 ( V_47 -> V_16 ) ;
T_7 V_12 = V_142 ;
F_28 ( V_2 , V_97 , V_2 -> V_18 ,
L_17 , V_43 , V_47 , V_47 -> V_16 , V_47 -> V_98 ) ;
F_59 ( & V_2 -> V_143 ) ;
if ( V_141 > V_2 -> V_79 ) {
F_56 ( V_32 ) ;
V_12 = V_144 ;
} else {
V_2 -> V_79 -= V_141 ;
F_60 ( & V_2 -> V_108 , V_47 ) ;
}
F_61 ( & V_2 -> V_143 ) ;
F_26 ( & V_2 -> V_106 ) ;
return V_12 ;
}
static void F_62 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_39 ( V_66 , struct V_1 , V_139 ) ;
F_19 ( & V_2 -> V_34 ) ;
F_1 ( V_2 , V_93 , 0x00 ) ;
F_21 ( & V_2 -> V_34 ) ;
}
static void F_63 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
struct V_83 V_85 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
if ( V_32 -> V_145 & V_146 ) {
V_85 . V_94 = V_147 | V_148 ;
} else if ( V_32 -> V_145 & V_149 ) {
V_85 . V_94 = ( V_150 | V_147 |
V_124 | V_151 ) ;
} else if ( V_32 -> V_145 & V_152 && ! F_64 ( V_32 ) ) {
struct V_153 * V_154 ;
T_5 V_155 ;
F_65 (ha, dev) {
V_155 = F_66 ( V_35 , V_154 -> V_156 ) ;
V_155 >>= ( 32 - 6 ) ;
V_85 . V_87 [ V_155 >> 4 ] |= ( 1 << ( V_155 & 0xf ) ) ;
}
V_85 . V_94 = V_150 | V_124 ;
} else {
V_85 . V_94 = V_124 ;
}
V_85 . V_94 |= ( V_127 |
V_126 |
V_128 |
V_125 ) ;
V_85 . V_92 |= V_129 ;
F_59 ( & V_2 -> V_143 ) ;
if ( memcmp ( & V_85 , & V_2 -> V_85 , sizeof( V_85 ) ) != 0 ) {
memcpy ( & V_2 -> V_85 , & V_85 , sizeof( V_2 -> V_85 ) ) ;
F_26 ( & V_2 -> V_139 ) ;
}
F_61 ( & V_2 -> V_143 ) ;
}
static int F_67 ( struct V_31 * V_32 , void * V_156 )
{
struct V_157 * V_158 = V_156 ;
if ( F_68 ( V_32 ) )
return - V_159 ;
if ( ! F_69 ( V_158 -> V_160 ) )
return - V_161 ;
memcpy ( V_32 -> V_36 , V_158 -> V_160 , V_35 ) ;
return F_17 ( V_32 ) ;
}
static int F_70 ( struct V_31 * V_32 , struct V_162 * V_163 , int V_164 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
if ( ! F_68 ( V_32 ) )
return - V_165 ;
return F_71 ( & V_2 -> V_166 , F_72 ( V_163 ) , V_164 , NULL ) ;
}
unsigned int F_73 ( struct V_31 * V_32 , unsigned int V_156 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
int V_167 ;
int V_168 = V_169 ;
int V_170 = V_171 ;
int V_172 = V_173 - 1 ;
unsigned int V_98 = 0 ;
int V_174 ;
unsigned int V_175 ;
V_175 = ( V_2 -> V_176 == 128 ) ? 6 : 8 ;
F_19 ( & V_2 -> V_34 ) ;
V_167 = V_177 | V_178 ;
F_1 ( V_2 , V_179 , V_167 ) ;
V_167 |= V_180 ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
while ( V_170 != V_181 ) {
V_167 &= ~ V_182 ;
switch ( V_170 ) {
case V_171 :
V_167 |= ( ( V_168 >> V_172 ) & 1 ) << 2 ;
if ( V_172 -- <= 0 ) {
V_172 = V_175 - 1 ;
V_170 = V_183 ;
}
break;
case V_183 :
V_167 |= ( ( V_156 >> V_172 ) & 1 ) << 2 ;
V_172 -- ;
break;
case V_184 :
V_167 &= ~ V_178 ;
break;
}
V_167 &= ~ V_185 ;
F_19 ( & V_2 -> V_34 ) ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
F_74 ( V_186 / 2 ) ;
F_19 ( & V_2 -> V_34 ) ;
V_167 |= V_185 ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
switch ( V_170 ) {
case V_183 :
if ( V_172 < 0 ) {
V_172 = V_187 - 1 ;
V_170 = V_184 ;
}
break;
case V_184 :
F_19 ( & V_2 -> V_34 ) ;
V_174 = F_10 ( V_2 , V_179 ) ;
F_21 ( & V_2 -> V_34 ) ;
V_98 |= ( ( V_174 >> V_188 ) & 1 ) << V_172 ;
if ( V_172 -- <= 0 )
V_170 = V_181 ;
break;
}
F_74 ( V_186 / 2 ) ;
}
F_19 ( & V_2 -> V_34 ) ;
V_167 &= ~ V_180 ;
F_1 ( V_2 , V_179 , V_167 ) ;
V_167 = 0 ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
return V_98 ;
}
void F_75 ( struct V_31 * V_32 , unsigned int V_20 ,
unsigned int V_156 , unsigned int V_98 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
int V_167 ;
int V_170 = V_171 ;
int V_172 = V_173 - 1 ;
unsigned int V_175 ;
V_175 = ( V_2 -> V_176 == 128 ) ? 6 : 8 ;
switch ( V_20 ) {
case V_189 :
V_156 = 0x30 ;
break;
case V_190 :
V_156 = 0 ;
break;
}
F_19 ( & V_2 -> V_34 ) ;
V_167 = V_177 | V_178 ;
F_1 ( V_2 , V_179 , V_167 ) ;
V_167 |= V_180 ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
while ( V_170 != V_181 ) {
V_167 &= ~ V_182 ;
switch ( V_170 ) {
case V_171 :
V_167 |= ( ( V_20 >> V_172 ) & 1 ) << 2 ;
if ( V_172 -- <= 0 ) {
V_172 = V_175 - 1 ;
V_170 = V_183 ;
}
break;
case V_183 :
V_167 |= ( ( V_156 >> V_172 ) & 1 ) << 2 ;
if ( V_172 -- <= 0 ) {
if ( V_20 == V_191 ) {
V_172 = V_187 - 1 ;
V_170 = V_184 ;
} else {
V_170 = V_181 ;
}
}
break;
case V_184 :
V_167 |= ( ( V_98 >> V_172 ) & 1 ) << 2 ;
if ( V_172 -- <= 0 )
V_170 = V_181 ;
break;
}
V_167 &= ~ V_185 ;
F_19 ( & V_2 -> V_34 ) ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
F_74 ( V_186 / 2 ) ;
V_167 |= V_185 ;
F_19 ( & V_2 -> V_34 ) ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
F_74 ( V_186 / 2 ) ;
}
F_19 ( & V_2 -> V_34 ) ;
V_167 &= ~ V_180 ;
F_1 ( V_2 , V_179 , V_167 ) ;
V_167 = 0 ;
F_1 ( V_2 , V_179 , V_167 ) ;
F_21 ( & V_2 -> V_34 ) ;
}
static void F_76 ( struct V_31 * V_32 ,
struct V_192 * V_193 )
{
F_77 ( V_193 -> V_194 , L_18 , sizeof( V_193 -> V_194 ) ) ;
F_77 ( V_193 -> V_195 , L_19 , sizeof( V_193 -> V_195 ) ) ;
F_77 ( V_193 -> V_196 , F_78 ( V_32 -> V_32 . V_197 ) , sizeof( V_193 -> V_196 ) ) ;
}
static T_5 F_79 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
return V_2 -> V_198 ;
}
static void F_80 ( struct V_31 * V_32 , T_5 V_199 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
V_2 -> V_198 = V_199 ;
}
static int F_81 ( struct V_31 * V_32 , struct V_200 * V_164 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
return F_82 ( & V_2 -> V_166 , V_164 ) ;
}
static int F_83 ( struct V_31 * V_32 , struct V_200 * V_164 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
return F_84 ( & V_2 -> V_166 , V_164 ) ;
}
static T_5 F_85 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
return F_86 ( & V_2 -> V_166 ) ;
}
static int F_87 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
return F_88 ( & V_2 -> V_166 ) ;
}
static int F_89 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
return V_2 -> V_176 ;
}
static int F_90 ( struct V_31 * V_32 ,
struct V_201 * V_202 , T_2 * V_203 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
T_6 * V_204 ;
int V_205 ;
int V_206 ;
int V_207 = 0 ;
T_6 V_33 ;
if ( V_202 -> V_16 == 0 )
return - V_165 ;
if ( V_202 -> V_16 > V_2 -> V_176 )
return - V_165 ;
V_202 -> V_208 = F_10 ( V_2 , V_209 ) ;
V_205 = V_202 -> V_210 >> 1 ;
V_206 = ( V_202 -> V_210 + V_202 -> V_16 - 1 ) >> 1 ;
V_204 = F_91 ( sizeof( T_6 ) *
( V_206 - V_205 + 1 ) , V_211 ) ;
if ( ! V_204 )
return - V_212 ;
for ( V_33 = 0 ; V_33 < V_206 - V_205 + 1 ; V_33 ++ )
V_204 [ V_33 ] = F_73 ( V_32 , V_205 + 1 ) ;
for ( V_33 = 0 ; V_33 < V_206 - V_205 + 1 ; V_33 ++ )
F_92 ( & V_204 [ V_33 ] ) ;
memcpy ( V_203 , ( T_2 * ) V_204 + ( V_202 -> V_210 & 1 ) , V_202 -> V_16 ) ;
F_93 ( V_204 ) ;
return V_207 ;
}
static int F_94 ( struct V_31 * V_32 ,
struct V_201 * V_202 , T_2 * V_203 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
T_6 * V_204 ;
void * V_213 ;
int V_214 ;
int V_205 ;
int V_206 ;
int V_207 = 0 ;
T_6 V_33 ;
if ( V_202 -> V_16 == 0 )
return - V_215 ;
if ( V_202 -> V_16 > V_2 -> V_176 )
return - V_165 ;
if ( V_202 -> V_208 != F_10 ( V_2 , V_209 ) )
return - V_216 ;
V_205 = V_202 -> V_210 >> 1 ;
V_206 = ( V_202 -> V_210 + V_202 -> V_16 - 1 ) >> 1 ;
V_214 = ( V_206 - V_205 + 1 ) * 2 ;
V_204 = F_91 ( V_214 , V_211 ) ;
if ( ! V_204 )
return - V_212 ;
V_213 = ( void * ) V_204 ;
if ( V_202 -> V_210 & 1 ) {
V_204 [ 0 ] = F_73 ( V_32 , V_205 ) ;
V_213 ++ ;
}
if ( ( V_202 -> V_210 + V_202 -> V_16 ) & 1 )
V_204 [ V_206 - V_205 ] =
F_73 ( V_32 , V_206 ) ;
F_92 ( & V_204 [ 0 ] ) ;
F_92 ( & V_204 [ V_206 - V_205 ] ) ;
memcpy ( V_213 , V_203 , V_202 -> V_16 ) ;
for ( V_33 = 0 ; V_33 < V_206 - V_205 + 1 ; V_33 ++ )
V_204 [ V_33 ] = F_2 ( V_204 [ V_33 ] ) ;
F_75 ( V_32 , V_189 , 0 , 0 ) ;
for ( V_33 = 0 ; V_33 < V_206 - V_205 + 1 ; V_33 ++ ) {
F_75 ( V_32 , V_191 , V_205 + V_33 ,
V_204 [ V_33 ] ) ;
F_16 ( V_217 ) ;
}
F_75 ( V_32 , V_190 , 0 , 0 ) ;
F_93 ( V_204 ) ;
return V_207 ;
}
static int F_95 ( int V_3 )
{
switch ( V_3 ) {
case V_218 :
return V_219 ;
case V_220 :
return V_221 ;
case V_222 :
return V_223 ;
case V_224 :
return V_225 ;
case V_226 :
return V_227 ;
case V_228 :
return V_229 ;
}
return 0x0 ;
}
static int F_96 ( struct V_31 * V_32 , int V_230 , int V_3 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
int V_231 ;
int V_232 ;
V_231 = F_95 ( V_3 ) ;
if ( ! V_231 )
return 0x0 ;
F_19 ( & V_2 -> V_34 ) ;
V_232 = F_10 ( V_2 , V_231 ) ;
F_21 ( & V_2 -> V_34 ) ;
return V_232 ;
}
static void F_97 ( struct V_31 * V_32 ,
int V_233 , int V_3 , int V_234 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
int V_231 ;
V_231 = F_95 ( V_3 ) ;
if ( V_231 ) {
F_19 ( & V_2 -> V_34 ) ;
F_1 ( V_2 , V_231 , V_234 ) ;
F_21 ( & V_2 -> V_34 ) ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
unsigned V_235 = V_236 | V_237 ;
int V_12 = 0 ;
unsigned V_238 ;
V_238 = F_10 ( V_2 , V_239 ) ;
if ( ( V_238 & V_235 ) != V_235 ) {
F_99 ( V_2 -> V_18 , L_20 ) ;
return 0 ;
}
if ( V_238 & V_240 ) {
F_5 ( V_2 -> V_18 , L_21 ) ;
V_12 |= 1 ;
}
if ( V_238 & V_241 ) {
F_5 ( V_2 -> V_18 , L_22 ) ;
V_12 |= 2 ;
}
return 0 ;
}
static int F_100 ( struct V_242 * V_243 , T_8 V_170 )
{
struct V_1 * V_2 = F_101 ( & V_243 -> V_32 ) ;
struct V_31 * V_32 = V_2 -> V_18 ;
if ( F_68 ( V_32 ) ) {
F_102 ( V_32 ) ;
F_54 ( V_32 ) ;
}
return 0 ;
}
static int F_103 ( struct V_242 * V_243 )
{
struct V_1 * V_2 = F_101 ( & V_243 -> V_32 ) ;
struct V_31 * V_32 = V_2 -> V_18 ;
if ( F_68 ( V_32 ) ) {
F_51 ( V_32 ) ;
F_104 ( V_32 ) ;
}
return 0 ;
}
static int T_9 F_105 ( struct V_242 * V_243 )
{
struct V_31 * V_244 ;
struct V_1 * V_2 ;
int V_12 ;
V_244 = F_106 ( sizeof( struct V_1 ) ) ;
if ( ! V_244 ) {
F_40 ( & V_243 -> V_32 , L_23 ) ;
return - V_212 ;
}
V_243 -> V_245 = 8 ;
V_2 = F_18 ( V_244 ) ;
V_2 -> V_18 = V_244 ;
V_2 -> V_17 = V_243 ;
V_2 -> V_79 = 6144 ;
F_107 ( & V_2 -> V_34 ) ;
F_108 ( & V_2 -> V_143 ) ;
F_109 ( & V_2 -> V_106 , F_47 ) ;
F_109 ( & V_2 -> V_39 , F_38 ) ;
F_109 ( & V_2 -> V_139 , F_62 ) ;
F_110 ( & V_2 -> V_10 ) ;
F_111 ( & V_2 -> V_7 , & V_2 -> V_10 ) ;
F_110 ( & V_2 -> V_27 ) ;
F_111 ( & V_2 -> V_28 [ 0 ] , & V_2 -> V_27 ) ;
F_111 ( & V_2 -> V_28 [ 1 ] , & V_2 -> V_27 ) ;
V_2 -> V_166 . V_32 = V_244 ;
V_2 -> V_166 . V_246 = 1 ,
V_2 -> V_166 . V_247 = 1 ;
V_2 -> V_166 . V_248 = 0xf ;
V_2 -> V_166 . V_249 = F_96 ;
V_2 -> V_166 . V_250 = F_97 ;
F_112 ( & V_243 -> V_32 , L_24 , V_198 ) ;
V_2 -> V_198 = F_113 ( V_198 , ( V_251 |
V_252 |
V_253 ) ) ;
F_114 ( & V_2 -> V_108 ) ;
F_115 ( V_244 , & V_254 ) ;
F_116 ( V_244 , & V_243 -> V_32 ) ;
F_117 ( & V_243 -> V_32 , V_2 ) ;
V_244 -> V_255 = V_256 ;
V_244 -> V_257 = & V_258 ;
V_244 -> V_37 = V_243 -> V_37 ;
F_15 ( V_2 , V_259 ) ;
if ( ( F_10 ( V_2 , V_209 ) & ~ V_260 ) != V_261 ) {
F_40 ( & V_243 -> V_32 , L_25 ) ;
V_12 = - V_262 ;
goto V_263;
}
V_2 -> V_264 = F_10 ( V_2 , V_265 ) ;
if ( V_2 -> V_264 & V_266 )
V_2 -> V_176 = 128 ;
else
V_2 -> V_176 = 0 ;
F_98 ( V_2 ) ;
F_22 ( V_2 ) ;
V_12 = F_118 ( V_243 -> V_37 , F_24 , V_267 ,
V_244 -> V_268 , V_2 ) ;
if ( V_12 < 0 ) {
F_40 ( & V_243 -> V_32 , L_26 ) ;
goto V_269;
}
V_12 = F_119 ( V_244 ) ;
if ( V_12 ) {
F_40 ( & V_243 -> V_32 , L_27 ) ;
goto V_270;
}
F_120 ( V_244 , L_28 ,
F_121 ( F_10 ( V_2 , V_209 ) ) ,
V_244 -> V_36 , V_244 -> V_37 ) ;
return 0 ;
V_270:
F_122 ( V_244 -> V_37 , V_244 ) ;
V_263:
V_269:
F_123 ( V_244 ) ;
return V_12 ;
}
static int T_10 F_124 ( struct V_242 * V_243 )
{
struct V_1 * V_271 = F_101 ( & V_243 -> V_32 ) ;
if ( F_125 ( V_271 ) )
F_112 ( & V_243 -> V_32 , L_29 ) ;
F_126 ( V_271 -> V_18 ) ;
F_122 ( V_243 -> V_37 , V_271 ) ;
F_123 ( V_271 -> V_18 ) ;
return 0 ;
}
static int T_11 F_127 ( void )
{
return F_128 ( & V_272 ) ;
}
static void T_12 F_129 ( void )
{
F_130 ( & V_272 ) ;
}
