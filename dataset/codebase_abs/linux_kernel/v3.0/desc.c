static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 , int V_7 ,
enum V_8 type ,
unsigned int V_9 , unsigned int V_10 , unsigned int V_11 ,
unsigned int V_12 , unsigned int V_13 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 )
{
T_1 V_17 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
V_19 = & V_4 -> V_21 . V_22 . V_19 ;
if ( F_2 ( V_11 == 0 ) ) {
F_3 ( V_2 -> V_23 , L_1 ) ;
F_4 ( 1 ) ;
return - V_24 ;
}
if ( F_2 ( V_10 == 0 ) ) {
F_3 ( V_2 -> V_23 , L_2 ) ;
F_4 ( 1 ) ;
return - V_24 ;
}
memset ( & V_4 -> V_21 . V_22 , 0 , sizeof( struct V_25 ) ) ;
V_20 = V_5 - V_7 + V_26 ;
if ( V_20 & ~ V_27 )
return - V_24 ;
V_19 -> V_28 = V_20 & V_27 ;
if ( type == V_29 )
V_5 = F_5 ( V_5 , 4 ) ;
if ( V_5 & ~ V_30 )
return - V_24 ;
V_19 -> V_31 = V_5 & V_30 ;
if ( V_2 -> V_32 == V_33 ) {
if ( V_6 & ~ V_34 )
return - V_24 ;
V_19 -> V_28 |=
F_6 ( V_6 , V_34 ) ;
}
if ( V_2 -> V_32 == V_33 ) {
switch ( type ) {
case V_29 :
case V_35 :
V_17 = V_36 ;
break;
case V_37 :
V_17 = V_38 ;
break;
default:
V_17 = type ;
break;
}
V_19 -> V_28 |=
F_6 ( V_17 , V_39 ) |
F_6 ( V_10 , V_40 ) ;
} else {
V_19 -> V_28 |=
F_6 ( V_10 , V_40 ) |
F_6 ( V_13 ,
V_41 ) ;
V_19 -> V_31 |=
F_6 ( type , V_42 ) ;
}
#define F_7 ( T_2 , T_3 ) \
if (flags & AR5K_TXDESC_##_flag) { \
tx_ctl->tx_control_##_c |= \
AR5K_2W_TX_DESC_CTL##_c##_##_flag; \
}
#define F_8 ( T_2 , T_3 ) \
if (flags & AR5K_TXDESC_##_flag) { \
tx_ctl->tx_control_##_c |= \
AR5K_2W_TX_DESC_CTL##_c##_##_flag##_5211; \
}
F_7 ( 0 , V_43 ) ;
F_7 ( 0 , V_44 ) ;
F_7 ( 0 , V_45 ) ;
if ( V_2 -> V_32 == V_46 ) {
F_8 ( 0 , V_47 ) ;
F_8 ( 1 , V_48 ) ;
}
#undef F_7
#undef F_8
if ( V_12 != V_49 ) {
V_19 -> V_28 |=
V_50 ;
V_19 -> V_31 |=
F_6 ( V_12 ,
V_51 ) ;
}
if ( ( V_2 -> V_32 == V_33 ) &&
( V_14 & ( V_52 | V_53 ) ) )
V_19 -> V_31 |= V_16 &
V_54 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 , unsigned int V_6 ,
int V_7 ,
enum V_8 type , unsigned int V_9 , unsigned int V_10 ,
unsigned int V_11 , unsigned int V_12 ,
unsigned int V_13 , unsigned int V_14 ,
unsigned int V_15 ,
unsigned int V_16 )
{
struct V_55 * V_19 ;
unsigned int V_20 ;
T_1 V_56 = 0 , V_57 = 0 , V_58 = 0 , V_59 = 0 ;
V_19 = & V_4 -> V_21 . V_60 . V_19 ;
if ( F_2 ( V_11 == 0 ) ) {
F_3 ( V_2 -> V_23 , L_1 ) ;
F_4 ( 1 ) ;
return - V_24 ;
}
if ( F_2 ( V_10 == 0 ) ) {
F_3 ( V_2 -> V_23 , L_2 ) ;
F_4 ( 1 ) ;
return - V_24 ;
}
V_9 += V_2 -> V_61 . V_62 ;
if ( V_9 > V_63 )
V_9 = V_63 ;
memset ( & V_4 -> V_21 . V_60 . V_64 , 0 ,
sizeof( V_4 -> V_21 . V_60 . V_64 ) ) ;
V_20 = V_5 - V_7 + V_26 ;
if ( V_20 & ~ V_65 )
return - V_24 ;
V_56 = V_20 & V_65 ;
if ( type == V_29 )
V_5 = F_5 ( V_5 , 4 ) ;
if ( V_5 & ~ V_66 )
return - V_24 ;
V_57 = V_5 & V_66 ;
V_56 |= F_6 ( V_9 , V_67 ) |
F_6 ( V_13 , V_68 ) ;
V_57 |= F_6 ( type , V_69 ) ;
V_58 = F_6 ( V_11 , V_70 ) ;
V_59 = V_10 & V_71 ;
#define F_7 ( T_2 , T_3 ) \
if (flags & AR5K_TXDESC_##_flag) { \
txctl##_c |= AR5K_4W_TX_DESC_CTL##_c##_##_flag; \
}
F_7 ( 0 , V_43 ) ;
F_7 ( 0 , V_47 ) ;
F_7 ( 0 , V_44 ) ;
F_7 ( 0 , V_45 ) ;
F_7 ( 0 , V_72 ) ;
F_7 ( 1 , V_48 ) ;
#undef F_7
if ( V_12 != V_49 ) {
V_56 |= V_73 ;
V_57 |= F_6 ( V_12 ,
V_74 ) ;
}
if ( V_14 & ( V_52 | V_53 ) ) {
if ( ( V_14 & V_52 ) &&
( V_14 & V_53 ) )
return - V_24 ;
V_58 |= V_16 & V_75 ;
V_59 |= F_6 ( V_15 ,
V_76 ) ;
}
V_19 -> V_28 = V_56 ;
V_19 -> V_31 = V_57 ;
V_19 -> V_77 = V_58 ;
V_19 -> V_78 = V_59 ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_79 , T_4 V_80 , T_4 V_81 ,
T_4 V_82 , unsigned int V_83 , T_4 V_84 )
{
struct V_55 * V_19 ;
if ( V_2 -> V_32 < V_85 )
return 0 ;
if ( F_2 ( ( V_79 == 0 && V_80 != 0 ) ||
( V_81 == 0 && V_82 != 0 ) ||
( V_83 == 0 && V_84 != 0 ) ) ) {
F_3 ( V_2 -> V_23 , L_2 ) ;
F_4 ( 1 ) ;
return - V_24 ;
}
if ( V_2 -> V_32 == V_85 ) {
V_19 = & V_4 -> V_21 . V_60 . V_19 ;
#define F_11 ( T_5 ) \
if (tx_tries##_n) { \
tx_ctl->tx_control_2 |= \
AR5K_REG_SM(tx_tries##_n, \
AR5K_4W_TX_DESC_CTL2_XMIT_TRIES##_n); \
tx_ctl->tx_control_3 |= \
AR5K_REG_SM(tx_rate##_n, \
AR5K_4W_TX_DESC_CTL3_XMIT_RATE##_n); \
}
F_11 ( 1 ) ;
F_11 ( 2 ) ;
F_11 ( 3 ) ;
#undef F_11
return 1 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_86 * V_87 )
{
struct V_18 * V_19 ;
struct V_88 * V_89 ;
V_19 = & V_4 -> V_21 . V_22 . V_19 ;
V_89 = & V_4 -> V_21 . V_22 . V_64 ;
if ( F_2 ( ( V_89 -> V_90 & V_91 ) == 0 ) )
return - V_92 ;
V_87 -> V_93 = F_13 ( V_89 -> V_94 ,
V_95 ) ;
V_87 -> V_96 = F_13 ( V_89 -> V_94 ,
V_97 ) ;
V_87 -> V_98 = F_13 ( V_89 -> V_94 ,
V_99 ) ;
V_87 -> V_100 = F_13 ( V_89 -> V_90 ,
V_101 ) ;
V_87 -> V_102 = F_13 ( V_89 -> V_90 ,
V_103 ) ;
V_87 -> V_104 = 1 ;
V_87 -> V_105 = 0 ;
V_87 -> V_106 = 0 ;
if ( ! ( V_89 -> V_94 & V_107 ) ) {
if ( V_89 -> V_94 &
V_108 )
V_87 -> V_105 |= V_109 ;
if ( V_89 -> V_94 & V_110 )
V_87 -> V_105 |= V_111 ;
if ( V_89 -> V_94 & V_112 )
V_87 -> V_105 |= V_113 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_86 * V_87 )
{
struct V_55 * V_19 ;
struct V_88 * V_89 ;
T_1 V_114 , V_115 ;
V_19 = & V_4 -> V_21 . V_60 . V_19 ;
V_89 = & V_4 -> V_21 . V_60 . V_64 ;
V_115 = F_15 ( V_89 -> V_90 ) ;
if ( F_2 ( ! ( V_115 & V_91 ) ) )
return - V_92 ;
V_114 = F_15 ( V_89 -> V_94 ) ;
V_87 -> V_93 = F_13 ( V_114 ,
V_95 ) ;
V_87 -> V_96 = F_13 ( V_114 ,
V_97 ) ;
V_87 -> V_98 = F_13 ( V_114 ,
V_99 ) ;
V_87 -> V_100 = F_13 ( V_115 ,
V_101 ) ;
V_87 -> V_102 = F_13 ( V_115 ,
V_103 ) ;
V_87 -> V_104 = ( V_115 &
V_116 ) ? 2 : 1 ;
V_87 -> V_105 = 0 ;
V_87 -> V_106 = F_13 ( V_115 ,
V_117 ) ;
if ( ! ( V_114 & V_107 ) ) {
if ( V_114 & V_108 )
V_87 -> V_105 |= V_109 ;
if ( V_114 & V_110 )
V_87 -> V_105 |= V_111 ;
if ( V_114 & V_112 )
V_87 -> V_105 |= V_113 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_118 , unsigned int V_14 )
{
struct V_119 * V_120 ;
V_120 = & V_4 -> V_21 . V_121 . V_120 ;
memset ( & V_4 -> V_21 . V_121 , 0 , sizeof( struct V_122 ) ) ;
if ( F_2 ( V_118 & ~ V_123 ) )
return - V_24 ;
V_120 -> V_124 = V_118 & V_123 ;
if ( V_14 & V_125 )
V_120 -> V_124 |= V_126 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_127 * V_128 )
{
struct V_129 * V_130 ;
V_130 = & V_4 -> V_21 . V_121 . V_131 ;
if ( F_2 ( ! ( V_130 -> V_132 &
V_133 ) ) )
return - V_92 ;
memset ( V_128 , 0 , sizeof( struct V_127 ) ) ;
V_128 -> V_134 = V_130 -> V_135 &
V_136 ;
V_128 -> V_137 = F_13 ( V_130 -> V_135 ,
V_138 ) ;
V_128 -> V_139 = F_13 ( V_130 -> V_135 ,
V_140 ) ;
V_128 -> V_141 = ! ! ( V_130 -> V_135 &
V_142 ) ;
V_128 -> V_143 = F_13 ( V_130 -> V_132 ,
V_144 ) ;
if ( V_2 -> V_32 == V_46 )
V_128 -> V_145 = F_13 ( V_130 -> V_135 ,
V_146 ) ;
else
V_128 -> V_145 = ( V_130 -> V_135 &
V_147 )
? 2 : 1 ;
if ( V_130 -> V_132 & V_148 )
V_128 -> V_149 = F_13 ( V_130 -> V_132 ,
V_150 ) ;
else
V_128 -> V_149 = V_151 ;
if ( ! ( V_130 -> V_132 &
V_152 ) ) {
if ( V_130 -> V_132 &
V_153 )
V_128 -> V_154 |= V_155 ;
if ( ( V_2 -> V_32 == V_33 ) &&
( V_130 -> V_132 &
V_156 ) )
V_128 -> V_154 |= V_157 ;
if ( V_130 -> V_132 &
V_158 ) {
V_128 -> V_154 |= V_159 ;
V_128 -> V_160 = F_13 ( V_130 -> V_132 ,
V_158 ) ;
}
if ( V_130 -> V_132 &
V_161 )
V_128 -> V_154 |= V_162 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_127 * V_128 )
{
struct V_129 * V_130 ;
T_1 V_163 , V_164 ;
V_130 = & V_4 -> V_21 . V_121 . V_131 ;
V_164 = F_15 ( V_130 -> V_132 ) ;
if ( F_2 ( ! ( V_164 & V_165 ) ) )
return - V_92 ;
memset ( V_128 , 0 , sizeof( struct V_127 ) ) ;
V_163 = F_15 ( V_130 -> V_135 ) ;
V_128 -> V_134 = V_163 & V_166 ;
V_128 -> V_137 = F_13 ( V_163 ,
V_167 ) ;
V_128 -> V_139 = F_13 ( V_163 ,
V_168 ) ;
V_128 -> V_145 = F_13 ( V_163 ,
V_169 ) ;
V_128 -> V_141 = ! ! ( V_163 & V_170 ) ;
V_128 -> V_143 = F_13 ( V_164 ,
V_171 ) ;
if ( V_164 & V_172 )
V_128 -> V_149 = F_13 ( V_164 ,
V_173 ) ;
else
V_128 -> V_149 = V_151 ;
if ( ! ( V_164 & V_174 ) ) {
if ( V_164 & V_175 )
V_128 -> V_154 |= V_155 ;
if ( V_164 & V_176 ) {
V_128 -> V_154 |= V_159 ;
V_128 -> V_160 = F_13 ( V_164 ,
V_177 ) ;
if ( ! V_2 -> V_178 . V_179 )
F_19 ( V_2 , V_128 -> V_160 ) ;
}
if ( V_164 & V_180 )
V_128 -> V_154 |= V_162 ;
if ( V_164 & V_181 )
V_128 -> V_154 |= V_182 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 == V_85 ) {
V_2 -> V_183 = F_9 ;
V_2 -> V_184 = F_14 ;
V_2 -> V_185 = F_18 ;
} else if ( V_2 -> V_32 <= V_46 ) {
V_2 -> V_183 = F_1 ;
V_2 -> V_184 = F_12 ;
V_2 -> V_185 = F_17 ;
} else
return - V_186 ;
return 0 ;
}
