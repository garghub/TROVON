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
F_3 ( V_2 , L_1 ) ;
F_4 ( 1 ) ;
return - V_23 ;
}
if ( F_2 ( V_10 == 0 ) ) {
F_3 ( V_2 , L_2 ) ;
F_4 ( 1 ) ;
return - V_23 ;
}
memset ( & V_4 -> V_21 . V_22 , 0 , sizeof( struct V_24 ) ) ;
V_20 = V_5 - V_7 + V_25 ;
if ( V_20 & ~ V_26 )
return - V_23 ;
V_19 -> V_27 = V_20 & V_26 ;
if ( type == V_28 )
V_5 = F_5 ( V_5 , 4 ) ;
if ( V_5 & ~ V_29 )
return - V_23 ;
V_19 -> V_30 = V_5 & V_29 ;
if ( V_2 -> V_31 == V_32 ) {
if ( V_6 & ~ V_33 )
return - V_23 ;
V_19 -> V_27 |=
F_6 ( V_6 , V_33 ) ;
}
if ( V_2 -> V_31 == V_32 ) {
switch ( type ) {
case V_28 :
case V_34 :
V_17 = V_35 ;
break;
case V_36 :
V_17 = V_37 ;
break;
default:
V_17 = type ;
break;
}
V_19 -> V_27 |=
F_6 ( V_17 , V_38 ) |
F_6 ( V_10 , V_39 ) ;
} else {
V_19 -> V_27 |=
F_6 ( V_10 , V_39 ) |
F_6 ( V_13 ,
V_40 ) ;
V_19 -> V_30 |=
F_6 ( type , V_41 ) ;
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
F_7 ( 0 , V_42 ) ;
F_7 ( 0 , V_43 ) ;
F_7 ( 0 , V_44 ) ;
if ( V_2 -> V_31 == V_45 ) {
F_8 ( 0 , V_46 ) ;
F_8 ( 1 , V_47 ) ;
}
#undef F_7
#undef F_8
if ( V_12 != V_48 ) {
V_19 -> V_27 |=
V_49 ;
V_19 -> V_30 |=
F_6 ( V_12 ,
V_50 ) ;
}
if ( ( V_2 -> V_31 == V_32 ) &&
( V_14 & ( V_51 | V_52 ) ) )
V_19 -> V_30 |= V_16 &
V_53 ;
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
struct V_54 * V_19 ;
unsigned int V_20 ;
T_1 V_55 = 0 , V_56 = 0 , V_57 = 0 , V_58 = 0 ;
V_19 = & V_4 -> V_21 . V_59 . V_19 ;
if ( F_2 ( V_11 == 0 ) ) {
F_3 ( V_2 , L_1 ) ;
F_4 ( 1 ) ;
return - V_23 ;
}
if ( F_2 ( V_10 == 0 ) ) {
F_3 ( V_2 , L_2 ) ;
F_4 ( 1 ) ;
return - V_23 ;
}
V_9 += V_2 -> V_60 . V_61 ;
if ( V_9 > V_62 )
V_9 = V_62 ;
memset ( & V_4 -> V_21 . V_59 . V_63 , 0 ,
sizeof( V_4 -> V_21 . V_59 . V_63 ) ) ;
V_20 = V_5 - V_7 + V_25 ;
if ( V_20 & ~ V_64 )
return - V_23 ;
V_55 = V_20 & V_64 ;
if ( type == V_28 )
V_5 = F_5 ( V_5 , 4 ) ;
if ( V_5 & ~ V_65 )
return - V_23 ;
V_56 = V_5 & V_65 ;
V_55 |= F_6 ( V_9 , V_66 ) |
F_6 ( V_13 , V_67 ) ;
V_56 |= F_6 ( type , V_68 ) ;
V_57 = F_6 ( V_11 , V_69 ) ;
V_58 = V_10 & V_70 ;
#define F_7 ( T_2 , T_3 ) \
if (flags & AR5K_TXDESC_##_flag) { \
txctl##_c |= AR5K_4W_TX_DESC_CTL##_c##_##_flag; \
}
F_7 ( 0 , V_42 ) ;
F_7 ( 0 , V_46 ) ;
F_7 ( 0 , V_43 ) ;
F_7 ( 0 , V_44 ) ;
F_7 ( 0 , V_71 ) ;
F_7 ( 1 , V_47 ) ;
#undef F_7
if ( V_12 != V_48 ) {
V_55 |= V_72 ;
V_56 |= F_6 ( V_12 ,
V_73 ) ;
}
if ( V_14 & ( V_51 | V_52 ) ) {
if ( ( V_14 & V_51 ) &&
( V_14 & V_52 ) )
return - V_23 ;
V_57 |= V_16 & V_74 ;
V_58 |= F_6 ( V_15 ,
V_75 ) ;
}
V_19 -> V_27 = V_55 ;
V_19 -> V_30 = V_56 ;
V_19 -> V_76 = V_57 ;
V_19 -> V_77 = V_58 ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_78 , T_4 V_79 , T_4 V_80 ,
T_4 V_81 , unsigned int V_82 , T_4 V_83 )
{
struct V_54 * V_19 ;
if ( V_2 -> V_31 < V_84 )
return 0 ;
if ( F_2 ( ( V_78 == 0 && V_79 != 0 ) ||
( V_80 == 0 && V_81 != 0 ) ||
( V_82 == 0 && V_83 != 0 ) ) ) {
F_3 ( V_2 , L_2 ) ;
F_4 ( 1 ) ;
return - V_23 ;
}
if ( V_2 -> V_31 == V_84 ) {
V_19 = & V_4 -> V_21 . V_59 . V_19 ;
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
struct V_3 * V_4 , struct V_85 * V_86 )
{
struct V_18 * V_19 ;
struct V_87 * V_88 ;
V_19 = & V_4 -> V_21 . V_22 . V_19 ;
V_88 = & V_4 -> V_21 . V_22 . V_63 ;
if ( F_2 ( ( V_88 -> V_89 & V_90 ) == 0 ) )
return - V_91 ;
V_86 -> V_92 = F_13 ( V_88 -> V_93 ,
V_94 ) ;
V_86 -> V_95 = F_13 ( V_88 -> V_93 ,
V_96 ) ;
V_86 -> V_97 = F_13 ( V_88 -> V_93 ,
V_98 ) ;
V_86 -> V_99 = F_13 ( V_88 -> V_89 ,
V_100 ) ;
V_86 -> V_101 = F_13 ( V_88 -> V_89 ,
V_102 ) ;
V_86 -> V_103 = 1 ;
V_86 -> V_104 = 0 ;
V_86 -> V_105 = 0 ;
if ( ! ( V_88 -> V_93 & V_106 ) ) {
if ( V_88 -> V_93 &
V_107 )
V_86 -> V_104 |= V_108 ;
if ( V_88 -> V_93 & V_109 )
V_86 -> V_104 |= V_110 ;
if ( V_88 -> V_93 & V_111 )
V_86 -> V_104 |= V_112 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_85 * V_86 )
{
struct V_54 * V_19 ;
struct V_87 * V_88 ;
T_1 V_113 , V_114 ;
V_19 = & V_4 -> V_21 . V_59 . V_19 ;
V_88 = & V_4 -> V_21 . V_59 . V_63 ;
V_114 = F_15 ( V_88 -> V_89 ) ;
if ( F_2 ( ! ( V_114 & V_90 ) ) )
return - V_91 ;
V_113 = F_15 ( V_88 -> V_93 ) ;
V_86 -> V_92 = F_13 ( V_113 ,
V_94 ) ;
V_86 -> V_95 = F_13 ( V_113 ,
V_96 ) ;
V_86 -> V_97 = F_13 ( V_113 ,
V_98 ) ;
V_86 -> V_99 = F_13 ( V_114 ,
V_100 ) ;
V_86 -> V_101 = F_13 ( V_114 ,
V_102 ) ;
V_86 -> V_103 = ( V_114 &
V_115 ) ? 2 : 1 ;
V_86 -> V_104 = 0 ;
V_86 -> V_105 = F_13 ( V_114 ,
V_116 ) ;
if ( ! ( V_113 & V_106 ) ) {
if ( V_113 & V_107 )
V_86 -> V_104 |= V_108 ;
if ( V_113 & V_109 )
V_86 -> V_104 |= V_110 ;
if ( V_113 & V_111 )
V_86 -> V_104 |= V_112 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_117 , unsigned int V_14 )
{
struct V_118 * V_119 ;
V_119 = & V_4 -> V_21 . V_120 . V_119 ;
memset ( & V_4 -> V_21 . V_120 , 0 , sizeof( struct V_121 ) ) ;
if ( F_2 ( V_117 & ~ V_122 ) )
return - V_23 ;
V_119 -> V_123 = V_117 & V_122 ;
if ( V_14 & V_124 )
V_119 -> V_123 |= V_125 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_126 * V_127 )
{
struct V_128 * V_129 ;
V_129 = & V_4 -> V_21 . V_120 . V_130 ;
if ( F_2 ( ! ( V_129 -> V_131 &
V_132 ) ) )
return - V_91 ;
memset ( V_127 , 0 , sizeof( struct V_126 ) ) ;
V_127 -> V_133 = V_129 -> V_134 &
V_135 ;
V_127 -> V_136 = F_13 ( V_129 -> V_134 ,
V_137 ) ;
V_127 -> V_138 = F_13 ( V_129 -> V_134 ,
V_139 ) ;
V_127 -> V_140 = ! ! ( V_129 -> V_134 &
V_141 ) ;
V_127 -> V_142 = F_13 ( V_129 -> V_131 ,
V_143 ) ;
if ( V_2 -> V_31 == V_45 )
V_127 -> V_144 = F_13 ( V_129 -> V_134 ,
V_145 ) ;
else
V_127 -> V_144 = ( V_129 -> V_134 &
V_146 )
? 2 : 1 ;
if ( V_129 -> V_131 & V_147 )
V_127 -> V_148 = F_13 ( V_129 -> V_131 ,
V_149 ) ;
else
V_127 -> V_148 = V_150 ;
if ( ! ( V_129 -> V_131 &
V_151 ) ) {
if ( V_129 -> V_131 &
V_152 )
V_127 -> V_153 |= V_154 ;
if ( ( V_2 -> V_31 == V_32 ) &&
( V_129 -> V_131 &
V_155 ) )
V_127 -> V_153 |= V_156 ;
if ( V_129 -> V_131 &
V_157 ) {
V_127 -> V_153 |= V_158 ;
V_127 -> V_159 = F_13 ( V_129 -> V_131 ,
V_157 ) ;
}
if ( V_129 -> V_131 &
V_160 )
V_127 -> V_153 |= V_161 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_126 * V_127 )
{
struct V_128 * V_129 ;
T_1 V_162 , V_163 ;
V_129 = & V_4 -> V_21 . V_120 . V_130 ;
V_163 = F_15 ( V_129 -> V_131 ) ;
if ( F_2 ( ! ( V_163 & V_164 ) ) )
return - V_91 ;
memset ( V_127 , 0 , sizeof( struct V_126 ) ) ;
V_162 = F_15 ( V_129 -> V_134 ) ;
V_127 -> V_133 = V_162 & V_165 ;
V_127 -> V_136 = F_13 ( V_162 ,
V_166 ) ;
V_127 -> V_138 = F_13 ( V_162 ,
V_167 ) ;
V_127 -> V_144 = F_13 ( V_162 ,
V_168 ) ;
V_127 -> V_140 = ! ! ( V_162 & V_169 ) ;
V_127 -> V_142 = F_13 ( V_163 ,
V_170 ) ;
if ( V_163 & V_171 )
V_127 -> V_148 = F_13 ( V_163 ,
V_172 ) ;
else
V_127 -> V_148 = V_150 ;
if ( ! ( V_163 & V_173 ) ) {
if ( V_163 & V_174 )
V_127 -> V_153 |= V_154 ;
if ( V_163 & V_175 ) {
V_127 -> V_153 |= V_158 ;
V_127 -> V_159 = F_13 ( V_163 ,
V_176 ) ;
if ( ! V_2 -> V_177 . V_178 )
F_19 ( V_2 , V_127 -> V_159 ) ;
}
if ( V_163 & V_179 )
V_127 -> V_153 |= V_161 ;
if ( V_163 & V_180 )
V_127 -> V_153 |= V_181 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == V_84 ) {
V_2 -> V_182 = F_9 ;
V_2 -> V_183 = F_14 ;
V_2 -> V_184 = F_18 ;
} else if ( V_2 -> V_31 <= V_45 ) {
V_2 -> V_182 = F_1 ;
V_2 -> V_183 = F_12 ;
V_2 -> V_184 = F_17 ;
} else
return - V_185 ;
return 0 ;
}
