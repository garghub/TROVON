static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = F_1 ( V_2 , V_3 ) ;
V_5 = ( V_5 & V_6 ) | ( V_7 & ~ V_6 ) ;
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_8 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_8 + V_3 ) ;
}
static inline void F_8 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = F_6 ( V_2 , V_3 ) ;
V_5 = ( V_5 & V_6 ) | ( V_7 & ~ V_6 ) ;
F_4 ( V_5 , V_2 -> V_8 + V_3 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
#define F_10 ( V_3 ) \
do { \
DRM_DEBUG_KMS(#reg_id " = %08x\n", \
(u32)readl(ctx->mixer_res.mixer_regs + reg_id)); \
} while (0)
F_10 ( V_11 ) ;
F_10 ( V_12 ) ;
F_10 ( V_13 ) ;
F_10 ( V_14 ) ;
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
F_10 ( V_17 ) ;
F_10 ( V_18 ) ;
F_10 ( V_19 ) ;
F_10 ( V_20 ) ;
F_10 ( V_21 ) ;
F_10 ( V_22 ) ;
F_10 ( V_23 ) ;
F_10 ( V_24 ) ;
F_10 ( V_25 ) ;
F_10 ( V_26 ) ;
F_10 ( V_27 ) ;
F_10 ( V_28 ) ;
#undef F_10
}
static void F_11 ( struct V_9 * V_10 )
{
#define F_10 ( V_3 ) \
do { \
DRM_DEBUG_KMS(#reg_id " = %08x\n", \
(u32) readl(ctx->mixer_res.vp_regs + reg_id)); \
} while (0)
F_10 ( V_29 ) ;
F_10 ( V_30 ) ;
F_10 ( V_31 ) ;
F_10 ( V_32 ) ;
F_10 ( V_33 ) ;
F_10 ( V_34 ) ;
F_10 ( V_35 ) ;
F_10 ( V_36 ) ;
F_10 ( V_37 ) ;
F_10 ( V_38 ) ;
F_10 ( V_39 ) ;
F_10 ( V_40 ) ;
F_10 ( V_41 ) ;
F_10 ( V_42 ) ;
F_10 ( V_43 ) ;
F_10 ( V_44 ) ;
F_10 ( V_45 ) ;
F_10 ( V_46 ) ;
F_10 ( V_47 ) ;
F_10 ( V_48 ) ;
F_10 ( V_49 ) ;
F_10 ( V_50 ) ;
F_10 ( V_51 ) ;
#undef F_10
}
static inline void F_12 ( struct V_1 * V_2 ,
int V_3 , const T_2 * V_52 , unsigned int V_53 )
{
F_13 ( V_53 & 3 ) ;
for (; V_53 ; V_53 -= 4 , V_3 += 4 , V_52 += 4 ) {
T_1 V_5 = ( V_52 [ 0 ] << 24 ) | ( V_52 [ 1 ] << 16 ) |
( V_52 [ 2 ] << 8 ) | V_52 [ 3 ] ;
F_3 ( V_2 , V_3 , V_5 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_54 ,
V_55 , sizeof( V_55 ) ) ;
F_12 ( V_2 , V_56 ,
V_57 , sizeof( V_57 ) ) ;
F_12 ( V_2 , V_58 ,
V_59 , sizeof( V_59 ) ) ;
}
static void F_15 ( struct V_9 * V_10 , bool V_60 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_8 ( V_2 , V_11 , V_60 ?
V_62 : 0 , V_62 ) ;
if ( V_10 -> V_63 )
F_3 ( V_2 , V_31 , V_60 ?
V_64 : 0 ) ;
}
static void F_16 ( struct V_9 * V_10 , unsigned int V_65 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 ;
V_5 = ( V_10 -> V_66 ? V_67 :
V_68 ) ;
if ( V_10 -> V_69 != V_70 ) {
if ( V_65 <= 480 )
V_5 |= V_71 | V_72 ;
else if ( V_65 <= 576 )
V_5 |= V_73 | V_72 ;
else if ( V_65 <= 720 )
V_5 |= V_74 | V_75 ;
else if ( V_65 <= 1080 )
V_5 |= V_76 | V_75 ;
else
V_5 |= V_74 | V_75 ;
}
F_8 ( V_2 , V_12 , V_5 , V_77 ) ;
}
static void F_17 ( struct V_9 * V_10 , unsigned int V_65 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 ;
if ( V_65 == 480 ) {
V_5 = V_78 ;
} else if ( V_65 == 576 ) {
V_5 = V_78 ;
} else if ( V_65 == 720 ) {
V_5 = V_79 ;
F_7 ( V_2 , V_80 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_7 ( V_2 , V_81 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_7 ( V_2 , V_82 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else if ( V_65 == 1080 ) {
V_5 = V_79 ;
F_7 ( V_2 , V_80 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_7 ( V_2 , V_81 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_7 ( V_2 , V_82 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else {
V_5 = V_79 ;
F_7 ( V_2 , V_80 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_7 ( V_2 , V_81 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_7 ( V_2 , V_82 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
}
F_8 ( V_2 , V_12 , V_5 , V_83 ) ;
}
static void F_18 ( struct V_9 * V_10 , int V_84 , bool V_60 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 = V_60 ? ~ 0 : 0 ;
switch ( V_84 ) {
case 0 :
F_8 ( V_2 , V_12 , V_5 , V_85 ) ;
break;
case 1 :
F_8 ( V_2 , V_12 , V_5 , V_86 ) ;
break;
case 2 :
if ( V_10 -> V_63 ) {
F_5 ( V_2 , V_29 , V_5 , V_87 ) ;
F_8 ( V_2 , V_12 , V_5 ,
V_88 ) ;
}
break;
}
}
static void F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_8 ( V_2 , V_11 , ~ 0 , V_89 ) ;
F_9 ( V_10 ) ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
int V_90 = 20 ;
F_8 ( V_2 , V_11 , 0 , V_89 ) ;
while ( ! ( F_6 ( V_2 , V_11 ) & V_91 ) &&
-- V_90 )
F_21 ( 10000 , 12000 ) ;
F_9 ( V_10 ) ;
}
static void F_22 ( struct V_9 * V_10 , int V_84 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
unsigned long V_92 ;
struct V_93 * V_94 ;
unsigned int V_95 , V_96 ;
unsigned int V_97 = 1 ;
T_3 V_98 [ 2 ] , V_99 [ 2 ] ;
bool V_100 = false ;
bool V_101 = false ;
T_1 V_5 ;
V_94 = & V_10 -> V_94 [ V_84 ] ;
switch ( V_94 -> V_102 ) {
case V_103 :
V_100 = true ;
case V_104 :
V_101 = false ;
V_97 = 2 ;
break;
default:
if ( ! V_94 -> V_105 )
break;
F_23 ( L_1 ,
V_94 -> V_102 ) ;
return;
}
V_95 = ( V_94 -> V_106 << 16 ) / V_94 -> V_107 ;
V_96 = ( V_94 -> V_108 << 16 ) / V_94 -> V_109 ;
if ( V_97 == 2 ) {
V_98 [ 0 ] = V_94 -> V_105 ;
V_99 [ 0 ] = V_94 -> V_110 ;
} else {
V_98 [ 0 ] = V_94 -> V_105 ;
V_99 [ 0 ] = V_94 -> V_105
+ ( V_94 -> V_111 * V_94 -> V_112 ) ;
}
if ( V_94 -> V_113 & V_114 ) {
V_10 -> V_66 = true ;
if ( V_100 ) {
V_98 [ 1 ] = V_98 [ 0 ] + 0x40 ;
V_99 [ 1 ] = V_99 [ 0 ] + 0x40 ;
} else {
V_98 [ 1 ] = V_98 [ 0 ] + V_94 -> V_111 ;
V_99 [ 1 ] = V_99 [ 0 ] + V_94 -> V_111 ;
}
} else {
V_10 -> V_66 = false ;
V_98 [ 1 ] = 0 ;
V_99 [ 1 ] = 0 ;
}
F_24 ( & V_2 -> V_115 , V_92 ) ;
F_15 ( V_10 , false ) ;
V_5 = ( V_10 -> V_66 ? ~ 0 : 0 ) ;
F_5 ( V_2 , V_33 , V_5 , V_116 ) ;
V_5 = ( V_101 ? V_117 : V_118 ) ;
V_5 |= ( V_100 ? V_119 : V_120 ) ;
F_5 ( V_2 , V_33 , V_5 , V_121 ) ;
F_3 ( V_2 , V_34 , F_25 ( V_94 -> V_111 ) |
F_26 ( V_94 -> V_112 ) ) ;
F_3 ( V_2 , V_35 , F_25 ( V_94 -> V_111 ) |
F_26 ( V_94 -> V_112 / 2 ) ) ;
F_3 ( V_2 , V_44 , V_94 -> V_106 ) ;
F_3 ( V_2 , V_45 , V_94 -> V_108 ) ;
F_3 ( V_2 , V_42 ,
F_27 ( V_94 -> V_122 ) ) ;
F_3 ( V_2 , V_43 , V_94 -> V_123 ) ;
F_3 ( V_2 , V_48 , V_94 -> V_107 ) ;
F_3 ( V_2 , V_46 , V_94 -> V_124 ) ;
if ( V_10 -> V_66 ) {
F_3 ( V_2 , V_49 , V_94 -> V_109 / 2 ) ;
F_3 ( V_2 , V_47 , V_94 -> V_125 / 2 ) ;
} else {
F_3 ( V_2 , V_49 , V_94 -> V_109 ) ;
F_3 ( V_2 , V_47 , V_94 -> V_125 ) ;
}
F_3 ( V_2 , V_50 , V_95 ) ;
F_3 ( V_2 , V_51 , V_96 ) ;
F_3 ( V_2 , V_41 , V_126 ) ;
F_3 ( V_2 , V_37 , V_98 [ 0 ] ) ;
F_3 ( V_2 , V_38 , V_98 [ 1 ] ) ;
F_3 ( V_2 , V_39 , V_99 [ 0 ] ) ;
F_3 ( V_2 , V_40 , V_99 [ 1 ] ) ;
F_16 ( V_10 , V_94 -> V_127 ) ;
F_17 ( V_10 , V_94 -> V_127 ) ;
F_18 ( V_10 , V_84 , true ) ;
F_19 ( V_10 ) ;
F_15 ( V_10 , true ) ;
F_28 ( & V_2 -> V_115 , V_92 ) ;
F_11 ( V_10 ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_8 ( V_2 , V_12 , ~ 0 , V_128 ) ;
}
static void F_30 ( struct V_9 * V_10 , int V_84 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
unsigned long V_92 ;
struct V_93 * V_94 ;
unsigned int V_95 , V_96 ;
unsigned int V_129 , V_130 , V_131 , V_132 ;
T_3 V_105 ;
unsigned int V_133 ;
T_1 V_5 ;
V_94 = & V_10 -> V_94 [ V_84 ] ;
#define F_31 4
#define F_32 5
#define F_33 6
#define F_34 7
switch ( V_94 -> V_134 ) {
case 16 :
V_133 = F_33 ;
break;
case 32 :
V_133 = F_34 ;
break;
default:
V_133 = F_34 ;
}
V_95 = 0 ;
V_96 = 0 ;
V_131 = V_94 -> V_124 ;
V_132 = V_94 -> V_125 ;
V_105 = V_94 -> V_105
+ ( V_94 -> V_122 * V_94 -> V_134 >> 3 )
+ ( V_94 -> V_123 * V_94 -> V_111 * V_94 -> V_134 >> 3 ) ;
V_129 = 0 ;
V_130 = 0 ;
if ( V_94 -> V_113 & V_114 )
V_10 -> V_66 = true ;
else
V_10 -> V_66 = false ;
F_24 ( & V_2 -> V_115 , V_92 ) ;
F_15 ( V_10 , false ) ;
F_8 ( V_2 , F_35 ( V_84 ) ,
F_36 ( V_133 ) , V_135 ) ;
F_7 ( V_2 , F_37 ( V_84 ) , V_94 -> V_111 ) ;
if ( V_10 -> V_69 == V_70 &&
V_84 == V_136 ) {
V_5 = F_38 ( V_94 -> V_112 ) ;
V_5 |= F_39 ( V_94 -> V_111 ) ;
F_7 ( V_2 , V_137 , V_5 ) ;
}
V_5 = F_40 ( V_94 -> V_107 ) ;
V_5 |= F_41 ( V_94 -> V_109 ) ;
V_5 |= F_42 ( V_95 ) ;
V_5 |= F_43 ( V_96 ) ;
F_7 ( V_2 , F_44 ( V_84 ) , V_5 ) ;
V_5 = F_45 ( V_129 ) ;
V_5 |= F_46 ( V_130 ) ;
F_7 ( V_2 , F_47 ( V_84 ) , V_5 ) ;
V_5 = F_48 ( V_131 ) ;
V_5 |= F_49 ( V_132 ) ;
F_7 ( V_2 , F_50 ( V_84 ) , V_5 ) ;
F_7 ( V_2 , F_51 ( V_84 ) , V_105 ) ;
F_16 ( V_10 , V_94 -> V_127 ) ;
F_17 ( V_10 , V_94 -> V_127 ) ;
F_18 ( V_10 , V_84 , true ) ;
if ( V_10 -> V_69 == V_138 ||
V_10 -> V_69 == V_70 )
F_29 ( V_10 ) ;
F_19 ( V_10 ) ;
F_15 ( V_10 , true ) ;
F_28 ( & V_2 -> V_115 , V_92 ) ;
}
static void F_52 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
int V_139 = 100 ;
F_3 ( V_2 , V_30 , V_140 ) ;
for ( V_139 = 100 ; V_139 ; -- V_139 ) {
if ( ~ F_1 ( V_2 , V_30 ) & V_140 )
break;
F_21 ( 10000 , 12000 ) ;
}
F_53 ( V_139 == 0 , L_2 ) ;
}
static void F_54 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
unsigned long V_92 ;
T_1 V_5 ;
F_24 ( & V_2 -> V_115 , V_92 ) ;
F_15 ( V_10 , false ) ;
F_8 ( V_2 , V_12 , V_141 , V_142 ) ;
F_8 ( V_2 , V_12 , V_143 , V_144 ) ;
F_8 ( V_2 , V_11 , V_145 ,
V_146 ) ;
V_5 = F_55 ( 3 ) ;
V_5 |= F_56 ( 2 ) ;
if ( V_10 -> V_63 )
V_5 |= F_57 ( 1 ) ;
F_7 ( V_2 , V_15 , V_5 ) ;
F_7 ( V_2 , V_147 , 0x008080 ) ;
F_7 ( V_2 , V_148 , 0x008080 ) ;
F_7 ( V_2 , V_149 , 0x008080 ) ;
V_5 = V_150 ;
V_5 |= V_151 ;
V_5 |= F_58 ( 0xff ) ;
F_7 ( V_2 , F_35 ( 0 ) , V_5 ) ;
V_5 |= V_152 ;
V_5 |= V_153 ;
F_7 ( V_2 , F_35 ( 1 ) , V_5 ) ;
V_5 = F_58 ( 0 ) ;
F_7 ( V_2 , V_16 , V_5 ) ;
if ( V_10 -> V_63 ) {
F_52 ( V_10 ) ;
F_14 ( V_2 ) ;
}
F_8 ( V_2 , V_12 , 0 , V_85 ) ;
F_8 ( V_2 , V_12 , 0 , V_86 ) ;
if ( V_10 -> V_63 )
F_8 ( V_2 , V_12 , 0 , V_88 ) ;
F_15 ( V_10 , true ) ;
F_28 ( & V_2 -> V_115 , V_92 ) ;
}
static T_4 F_59 ( int V_154 , void * V_155 )
{
struct V_9 * V_10 = V_155 ;
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 , V_156 , V_157 ;
F_60 ( & V_2 -> V_115 ) ;
V_5 = F_6 ( V_2 , V_14 ) ;
if ( V_5 & V_158 ) {
if ( V_10 -> V_66 ) {
V_156 = F_6 ( V_2 , F_51 ( 0 ) ) ;
V_157 = F_6 ( V_2 , F_61 ( 0 ) ) ;
if ( V_156 != V_157 )
goto V_159;
V_156 = F_6 ( V_2 , F_51 ( 1 ) ) ;
V_157 = F_6 ( V_2 , F_61 ( 1 ) ) ;
if ( V_156 != V_157 )
goto V_159;
}
F_62 ( V_10 -> V_160 , V_10 -> V_161 ) ;
F_63 ( V_10 -> V_160 , V_10 -> V_161 ) ;
if ( F_64 ( & V_10 -> V_162 ) ) {
F_65 ( & V_10 -> V_162 , 0 ) ;
F_66 ( & V_10 -> V_163 ) ;
}
}
V_159:
if ( ~ V_5 & V_164 ) {
V_5 &= ~ V_164 ;
V_5 |= V_165 ;
}
F_7 ( V_2 , V_14 , V_5 ) ;
F_67 ( & V_2 -> V_115 ) ;
return V_166 ;
}
static int F_68 ( struct V_9 * V_167 )
{
struct V_168 * V_169 = & V_167 -> V_170 -> V_169 ;
struct V_1 * V_61 = & V_167 -> V_61 ;
struct V_171 * V_2 ;
int V_172 ;
F_69 ( & V_61 -> V_115 ) ;
V_61 -> V_173 = F_70 ( V_169 , L_3 ) ;
if ( F_71 ( V_61 -> V_173 ) ) {
F_72 ( V_169 , L_4 ) ;
return - V_174 ;
}
V_61 -> V_175 = F_70 ( V_169 , L_5 ) ;
if ( F_71 ( V_61 -> V_175 ) ) {
F_72 ( V_169 , L_6 ) ;
return - V_174 ;
}
V_2 = F_73 ( V_167 -> V_170 , V_176 , 0 ) ;
if ( V_2 == NULL ) {
F_72 ( V_169 , L_7 ) ;
return - V_177 ;
}
V_61 -> V_8 = F_74 ( V_169 , V_2 -> V_178 ,
F_75 ( V_2 ) ) ;
if ( V_61 -> V_8 == NULL ) {
F_72 ( V_169 , L_8 ) ;
return - V_177 ;
}
V_2 = F_73 ( V_167 -> V_170 , V_179 , 0 ) ;
if ( V_2 == NULL ) {
F_72 ( V_169 , L_9 ) ;
return - V_177 ;
}
V_172 = F_76 ( V_169 , V_2 -> V_178 , F_59 ,
0 , L_10 , V_167 ) ;
if ( V_172 ) {
F_72 ( V_169 , L_11 ) ;
return V_172 ;
}
V_61 -> V_154 = V_2 -> V_178 ;
return 0 ;
}
static int F_77 ( struct V_9 * V_167 )
{
struct V_168 * V_169 = & V_167 -> V_170 -> V_169 ;
struct V_1 * V_61 = & V_167 -> V_61 ;
struct V_171 * V_2 ;
V_61 -> V_180 = F_70 ( V_169 , L_12 ) ;
if ( F_71 ( V_61 -> V_180 ) ) {
F_72 ( V_169 , L_13 ) ;
return - V_174 ;
}
V_61 -> V_181 = F_70 ( V_169 , L_14 ) ;
if ( F_71 ( V_61 -> V_181 ) ) {
F_72 ( V_169 , L_15 ) ;
return - V_174 ;
}
V_61 -> V_182 = F_70 ( V_169 , L_16 ) ;
if ( F_71 ( V_61 -> V_182 ) ) {
F_72 ( V_169 , L_17 ) ;
return - V_174 ;
}
if ( V_61 -> V_175 )
F_78 ( V_61 -> V_181 , V_61 -> V_175 ) ;
V_2 = F_73 ( V_167 -> V_170 , V_176 , 1 ) ;
if ( V_2 == NULL ) {
F_72 ( V_169 , L_7 ) ;
return - V_177 ;
}
V_61 -> V_4 = F_74 ( V_169 , V_2 -> V_178 ,
F_75 ( V_2 ) ) ;
if ( V_61 -> V_4 == NULL ) {
F_72 ( V_169 , L_8 ) ;
return - V_177 ;
}
return 0 ;
}
static int F_79 ( struct V_183 * V_184 ,
struct V_185 * V_160 )
{
int V_172 ;
struct V_9 * V_167 = V_184 -> V_10 ;
struct V_186 * V_187 ;
V_187 = V_160 -> V_188 ;
V_184 -> V_160 = V_167 -> V_160 = V_160 ;
V_184 -> V_161 = V_167 -> V_161 = V_187 -> V_161 ++ ;
V_172 = F_68 ( V_167 ) ;
if ( V_172 ) {
F_23 ( L_18 , V_172 ) ;
return V_172 ;
}
if ( V_167 -> V_63 ) {
V_172 = F_77 ( V_167 ) ;
if ( V_172 ) {
F_23 ( L_19 , V_172 ) ;
return V_172 ;
}
}
if ( ! F_80 ( V_167 -> V_160 ) )
return 0 ;
return F_81 ( V_167 -> V_160 , V_167 -> V_169 ) ;
}
static void F_82 ( struct V_183 * V_184 )
{
struct V_9 * V_167 = V_184 -> V_10 ;
if ( F_80 ( V_167 -> V_160 ) )
F_83 ( V_167 -> V_160 , V_167 -> V_169 ) ;
}
static int F_84 ( struct V_183 * V_184 )
{
struct V_9 * V_167 = V_184 -> V_10 ;
struct V_1 * V_2 = & V_167 -> V_61 ;
if ( ! V_167 -> V_189 ) {
V_167 -> V_190 |= V_164 ;
return 0 ;
}
F_8 ( V_2 , V_13 , V_164 ,
V_164 ) ;
return 0 ;
}
static void F_85 ( struct V_183 * V_184 )
{
struct V_9 * V_167 = V_184 -> V_10 ;
struct V_1 * V_2 = & V_167 -> V_61 ;
F_8 ( V_2 , V_13 , 0 , V_164 ) ;
}
static void F_86 ( struct V_183 * V_184 ,
struct V_191 * V_192 )
{
struct V_9 * V_167 = V_184 -> V_10 ;
struct V_93 * V_94 ;
int V_84 ;
if ( ! V_192 ) {
F_23 ( L_20 ) ;
return;
}
F_87 ( L_21 ,
V_192 -> V_111 , V_192 -> V_112 ,
V_192 -> V_122 , V_192 -> V_123 ,
V_192 -> V_107 , V_192 -> V_109 ,
V_192 -> V_124 , V_192 -> V_125 ) ;
V_84 = V_192 -> V_193 ;
if ( V_84 == V_194 )
V_84 = V_136 ;
if ( V_84 < 0 || V_84 >= V_195 ) {
F_23 ( L_22 , V_84 ) ;
return;
}
V_94 = & V_167 -> V_94 [ V_84 ] ;
V_94 -> V_105 = V_192 -> V_105 [ 0 ] ;
V_94 -> V_110 = V_192 -> V_105 [ 1 ] ;
V_94 -> V_102 = V_192 -> V_102 ;
V_94 -> V_134 = V_192 -> V_134 ;
V_94 -> V_124 = V_192 -> V_124 ;
V_94 -> V_125 = V_192 -> V_125 ;
V_94 -> V_107 = V_192 -> V_107 ;
V_94 -> V_109 = V_192 -> V_109 ;
V_94 -> V_122 = V_192 -> V_122 ;
V_94 -> V_123 = V_192 -> V_123 ;
V_94 -> V_111 = V_192 -> V_111 ;
V_94 -> V_112 = V_192 -> V_112 ;
V_94 -> V_106 = V_192 -> V_106 ;
V_94 -> V_108 = V_192 -> V_108 ;
V_94 -> V_196 = V_192 -> V_196 ;
V_94 -> V_127 = V_192 -> V_127 ;
V_94 -> V_113 = V_192 -> V_197 ;
}
static void F_88 ( struct V_183 * V_184 , int V_193 )
{
struct V_9 * V_167 = V_184 -> V_10 ;
int V_84 = V_193 == V_194 ? V_136 : V_193 ;
F_87 ( L_23 , V_84 ) ;
F_89 ( & V_167 -> V_198 ) ;
if ( ! V_167 -> V_189 ) {
F_90 ( & V_167 -> V_198 ) ;
return;
}
F_90 ( & V_167 -> V_198 ) ;
if ( V_84 > 1 && V_167 -> V_63 )
F_22 ( V_167 , V_84 ) ;
else
F_30 ( V_167 , V_84 ) ;
V_167 -> V_94 [ V_84 ] . V_199 = true ;
}
static void F_91 ( struct V_183 * V_184 , int V_193 )
{
struct V_9 * V_167 = V_184 -> V_10 ;
struct V_1 * V_2 = & V_167 -> V_61 ;
int V_84 = V_193 == V_194 ? V_136 : V_193 ;
unsigned long V_92 ;
F_87 ( L_23 , V_84 ) ;
F_89 ( & V_167 -> V_198 ) ;
if ( ! V_167 -> V_189 ) {
F_90 ( & V_167 -> V_198 ) ;
V_167 -> V_94 [ V_84 ] . V_200 = false ;
return;
}
F_90 ( & V_167 -> V_198 ) ;
F_24 ( & V_2 -> V_115 , V_92 ) ;
F_15 ( V_167 , false ) ;
F_18 ( V_167 , V_84 , false ) ;
F_15 ( V_167 , true ) ;
F_28 ( & V_2 -> V_115 , V_92 ) ;
V_167 -> V_94 [ V_84 ] . V_199 = false ;
}
static void F_92 ( struct V_183 * V_184 )
{
struct V_9 * V_167 = V_184 -> V_10 ;
F_89 ( & V_167 -> V_198 ) ;
if ( ! V_167 -> V_189 ) {
F_90 ( & V_167 -> V_198 ) ;
return;
}
F_90 ( & V_167 -> V_198 ) ;
F_93 ( V_184 -> V_201 -> V_169 , V_167 -> V_161 ) ;
F_65 ( & V_167 -> V_162 , 1 ) ;
if ( ! F_94 ( V_167 -> V_163 ,
! F_64 ( & V_167 -> V_162 ) ,
V_202 / 20 ) )
F_87 ( L_24 ) ;
F_95 ( V_184 -> V_201 -> V_169 , V_167 -> V_161 ) ;
}
static void F_96 ( struct V_183 * V_184 )
{
struct V_9 * V_10 = V_184 -> V_10 ;
struct V_93 * V_94 ;
int V_203 ;
for ( V_203 = 0 ; V_203 < V_195 ; V_203 ++ ) {
V_94 = & V_10 -> V_94 [ V_203 ] ;
V_94 -> V_200 = V_94 -> V_199 ;
F_91 ( V_184 , V_203 ) ;
}
F_92 ( V_184 ) ;
}
static void F_97 ( struct V_183 * V_184 )
{
struct V_9 * V_10 = V_184 -> V_10 ;
struct V_93 * V_94 ;
int V_203 ;
for ( V_203 = 0 ; V_203 < V_195 ; V_203 ++ ) {
V_94 = & V_10 -> V_94 [ V_203 ] ;
V_94 -> V_199 = V_94 -> V_200 ;
V_94 -> V_200 = false ;
if ( V_94 -> V_199 )
F_88 ( V_184 , V_203 ) ;
}
}
static void F_98 ( struct V_183 * V_184 )
{
struct V_9 * V_10 = V_184 -> V_10 ;
struct V_1 * V_2 = & V_10 -> V_61 ;
F_89 ( & V_10 -> V_198 ) ;
if ( V_10 -> V_189 ) {
F_90 ( & V_10 -> V_198 ) ;
return;
}
F_90 ( & V_10 -> V_198 ) ;
F_99 ( V_10 -> V_169 ) ;
F_100 ( V_2 -> V_173 ) ;
if ( V_10 -> V_63 ) {
F_100 ( V_2 -> V_180 ) ;
F_100 ( V_2 -> V_181 ) ;
}
F_89 ( & V_10 -> V_198 ) ;
V_10 -> V_189 = true ;
F_90 ( & V_10 -> V_198 ) ;
F_8 ( V_2 , V_11 , ~ 0 , V_204 ) ;
F_7 ( V_2 , V_13 , V_10 -> V_190 ) ;
F_54 ( V_10 ) ;
F_97 ( V_184 ) ;
}
static void F_101 ( struct V_183 * V_184 )
{
struct V_9 * V_10 = V_184 -> V_10 ;
struct V_1 * V_2 = & V_10 -> V_61 ;
F_89 ( & V_10 -> V_198 ) ;
if ( ! V_10 -> V_189 ) {
F_90 ( & V_10 -> V_198 ) ;
return;
}
F_90 ( & V_10 -> V_198 ) ;
F_20 ( V_10 ) ;
F_96 ( V_184 ) ;
V_10 -> V_190 = F_6 ( V_2 , V_13 ) ;
F_89 ( & V_10 -> V_198 ) ;
V_10 -> V_189 = false ;
F_90 ( & V_10 -> V_198 ) ;
F_102 ( V_2 -> V_173 ) ;
if ( V_10 -> V_63 ) {
F_102 ( V_2 -> V_180 ) ;
F_102 ( V_2 -> V_181 ) ;
}
F_103 ( V_10 -> V_169 ) ;
}
static void F_104 ( struct V_183 * V_184 , int V_205 )
{
switch ( V_205 ) {
case V_206 :
F_98 ( V_184 ) ;
break;
case V_207 :
case V_208 :
case V_209 :
F_101 ( V_184 ) ;
break;
default:
F_87 ( L_25 , V_205 ) ;
break;
}
}
int F_105 ( struct V_210 * V_205 )
{
T_1 V_211 , V_212 ;
V_211 = V_205 -> V_213 ;
V_212 = V_205 -> V_214 ;
F_87 ( L_26 ,
V_205 -> V_213 , V_205 -> V_214 , V_205 -> V_215 ,
( V_205 -> V_92 & V_114 ) ? 1 : 0 ) ;
if ( ( V_211 >= 464 && V_211 <= 720 && V_212 >= 261 && V_212 <= 576 ) ||
( V_211 >= 1024 && V_211 <= 1280 && V_212 >= 576 && V_212 <= 720 ) ||
( V_211 >= 1664 && V_211 <= 1920 && V_212 >= 936 && V_212 <= 1080 ) )
return 0 ;
return - V_216 ;
}
static int F_106 ( struct V_168 * V_169 , struct V_168 * V_217 , void * V_52 )
{
struct V_218 * V_170 = F_107 ( V_169 ) ;
struct V_185 * V_160 = V_52 ;
struct V_9 * V_10 ;
struct V_219 * V_220 ;
int V_172 ;
F_108 ( V_169 , L_27 ) ;
V_10 = F_109 ( & V_170 -> V_169 , sizeof( * V_10 ) , V_221 ) ;
if ( ! V_10 ) {
F_23 ( L_28 ) ;
return - V_222 ;
}
F_110 ( & V_10 -> V_198 ) ;
if ( V_169 -> V_223 ) {
const struct V_224 * V_225 ;
V_225 = F_111 ( V_226 , V_169 -> V_223 ) ;
V_220 = (struct V_219 * ) V_225 -> V_52 ;
} else {
V_220 = (struct V_219 * )
F_112 ( V_170 ) -> V_227 ;
}
V_10 -> V_170 = V_170 ;
V_10 -> V_169 = V_169 ;
V_10 -> V_63 = V_220 -> V_228 ;
V_10 -> V_69 = V_220 -> V_229 ;
F_113 ( & V_10 -> V_163 ) ;
F_65 ( & V_10 -> V_162 , 0 ) ;
V_230 . V_10 = V_10 ;
V_172 = F_79 ( & V_230 , V_160 ) ;
if ( V_172 )
return V_172 ;
F_114 ( V_170 , & V_230 ) ;
V_172 = F_115 ( & V_230 ) ;
if ( V_172 ) {
F_82 ( & V_230 ) ;
return V_172 ;
}
F_116 ( V_169 ) ;
return 0 ;
}
static void F_117 ( struct V_168 * V_169 , struct V_168 * V_231 , void * V_52 )
{
struct V_183 * V_184 = F_118 ( V_169 ) ;
struct V_232 * V_201 = V_184 -> V_201 ;
F_108 ( V_169 , L_29 ) ;
F_82 ( V_184 ) ;
F_119 ( V_169 ) ;
V_201 -> V_233 -> V_234 ( V_201 ) ;
}
static int F_120 ( struct V_218 * V_170 )
{
int V_172 ;
V_172 = F_121 ( & V_170 -> V_169 , V_235 ,
V_230 . type ) ;
if ( V_172 )
return V_172 ;
V_172 = F_122 ( & V_170 -> V_169 , & V_236 ) ;
if ( V_172 )
F_123 ( & V_170 -> V_169 , V_235 ) ;
return V_172 ;
}
static int F_124 ( struct V_218 * V_170 )
{
F_125 ( & V_170 -> V_169 , & V_236 ) ;
F_123 ( & V_170 -> V_169 , V_235 ) ;
return 0 ;
}
