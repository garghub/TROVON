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
V_55 , sizeof V_55 ) ;
F_12 ( V_2 , V_56 ,
V_57 , sizeof V_57 ) ;
F_12 ( V_2 , V_58 ,
V_59 , sizeof V_59 ) ;
}
static void F_15 ( struct V_9 * V_10 , bool V_60 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_8 ( V_2 , V_11 , V_60 ?
V_62 : 0 , V_62 ) ;
F_3 ( V_2 , V_31 , V_60 ?
V_63 : 0 ) ;
}
static void F_16 ( struct V_9 * V_10 , unsigned int V_64 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 ;
V_5 = ( V_10 -> V_65 ? V_66 :
V_67 ) ;
if ( V_64 == 480 )
V_5 |= V_68 | V_69 ;
else if ( V_64 == 576 )
V_5 |= V_70 | V_69 ;
else if ( V_64 == 720 )
V_5 |= V_71 | V_72 ;
else if ( V_64 == 1080 )
V_5 |= V_73 | V_72 ;
else
V_5 |= V_71 | V_72 ;
F_8 ( V_2 , V_12 , V_5 , V_74 ) ;
}
static void F_17 ( struct V_9 * V_10 , unsigned int V_64 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 ;
if ( V_64 == 480 ) {
V_5 = V_75 ;
} else if ( V_64 == 576 ) {
V_5 = V_75 ;
} else if ( V_64 == 720 ) {
V_5 = V_76 ;
F_7 ( V_2 , V_77 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_7 ( V_2 , V_78 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_7 ( V_2 , V_79 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else if ( V_64 == 1080 ) {
V_5 = V_76 ;
F_7 ( V_2 , V_77 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_7 ( V_2 , V_78 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_7 ( V_2 , V_79 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
} else {
V_5 = V_76 ;
F_7 ( V_2 , V_77 ,
( 1 << 30 ) | ( 94 << 20 ) | ( 314 << 10 ) |
( 32 << 0 ) ) ;
F_7 ( V_2 , V_78 ,
( 972 << 20 ) | ( 851 << 10 ) | ( 225 << 0 ) ) ;
F_7 ( V_2 , V_79 ,
( 225 << 20 ) | ( 820 << 10 ) | ( 1004 << 0 ) ) ;
}
F_8 ( V_2 , V_12 , V_5 , V_80 ) ;
}
static void F_18 ( struct V_9 * V_10 , int V_81 , bool V_60 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 = V_60 ? ~ 0 : 0 ;
switch ( V_81 ) {
case 0 :
F_8 ( V_2 , V_12 , V_5 , V_82 ) ;
break;
case 1 :
F_8 ( V_2 , V_12 , V_5 , V_83 ) ;
break;
case 2 :
F_5 ( V_2 , V_29 , V_5 , V_84 ) ;
F_8 ( V_2 , V_12 , V_5 , V_85 ) ;
break;
}
}
static void F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_8 ( V_2 , V_11 , ~ 0 , V_86 ) ;
F_9 ( V_10 ) ;
}
static void F_20 ( struct V_9 * V_10 , int V_81 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
unsigned long V_87 ;
struct V_88 * V_89 ;
unsigned int V_90 , V_91 , V_92 , V_64 ;
unsigned int V_93 , V_94 ;
unsigned int V_95 , V_96 , V_97 , V_98 ;
unsigned int V_99 , V_100 ;
unsigned int V_101 ;
T_3 V_102 [ 2 ] , V_103 [ 2 ] ;
bool V_104 = false ;
bool V_105 = false ;
T_1 V_5 ;
V_89 = & V_10 -> V_89 [ V_81 ] ;
switch ( V_89 -> V_106 ) {
case V_107 :
V_104 = true ;
case V_108 :
V_105 = false ;
V_101 = 2 ;
break;
default:
if ( ! V_89 -> V_109 )
break;
F_21 ( L_1 ,
V_89 -> V_106 ) ;
return;
}
V_90 = V_89 -> V_110 ;
V_91 = V_89 -> V_111 ;
V_92 = V_89 -> V_112 ;
V_64 = V_89 -> V_113 ;
V_99 = V_89 -> V_99 ;
V_100 = V_89 -> V_100 ;
V_93 = ( V_92 << 16 ) / V_92 ;
V_94 = ( V_64 << 16 ) / V_64 ;
V_95 = V_89 -> V_114 ;
V_96 = V_89 -> V_115 ;
V_97 = V_89 -> V_116 ;
V_98 = V_89 -> V_117 ;
if ( V_101 == 2 ) {
V_102 [ 0 ] = V_89 -> V_109 ;
V_103 [ 0 ] = V_89 -> V_118 ;
} else {
V_102 [ 0 ] = V_89 -> V_109 ;
V_103 [ 0 ] = V_89 -> V_109
+ ( V_90 * V_91 ) ;
}
if ( V_89 -> V_119 & V_120 ) {
V_10 -> V_65 = true ;
if ( V_104 ) {
V_102 [ 1 ] = V_102 [ 0 ] + 0x40 ;
V_103 [ 1 ] = V_103 [ 0 ] + 0x40 ;
} else {
V_102 [ 1 ] = V_102 [ 0 ] + V_90 ;
V_103 [ 1 ] = V_103 [ 0 ] + V_90 ;
}
} else {
V_10 -> V_65 = false ;
V_102 [ 1 ] = 0 ;
V_103 [ 1 ] = 0 ;
}
F_22 ( & V_2 -> V_121 , V_87 ) ;
F_15 ( V_10 , false ) ;
V_5 = ( V_10 -> V_65 ? ~ 0 : 0 ) ;
F_5 ( V_2 , V_33 , V_5 , V_122 ) ;
V_5 = ( V_105 ? V_123 : V_124 ) ;
V_5 |= ( V_104 ? V_125 : V_126 ) ;
F_5 ( V_2 , V_33 , V_5 , V_127 ) ;
F_3 ( V_2 , V_34 , F_23 ( V_90 ) |
F_24 ( V_91 ) ) ;
F_3 ( V_2 , V_35 , F_23 ( V_90 ) |
F_24 ( V_91 / 2 ) ) ;
F_3 ( V_2 , V_44 , V_92 ) ;
F_3 ( V_2 , V_45 , V_64 ) ;
F_3 ( V_2 , V_42 ,
F_25 ( V_95 ) ) ;
F_3 ( V_2 , V_43 , V_96 ) ;
F_3 ( V_2 , V_48 , V_92 ) ;
F_3 ( V_2 , V_46 , V_97 ) ;
if ( V_10 -> V_65 ) {
F_3 ( V_2 , V_49 , V_64 / 2 ) ;
F_3 ( V_2 , V_47 , V_98 / 2 ) ;
} else {
F_3 ( V_2 , V_49 , V_64 ) ;
F_3 ( V_2 , V_47 , V_98 ) ;
}
F_3 ( V_2 , V_50 , V_93 ) ;
F_3 ( V_2 , V_51 , V_94 ) ;
F_3 ( V_2 , V_41 , V_128 ) ;
F_3 ( V_2 , V_37 , V_102 [ 0 ] ) ;
F_3 ( V_2 , V_38 , V_102 [ 1 ] ) ;
F_3 ( V_2 , V_39 , V_103 [ 0 ] ) ;
F_3 ( V_2 , V_40 , V_103 [ 1 ] ) ;
F_16 ( V_10 , V_100 ) ;
F_17 ( V_10 , V_100 ) ;
F_18 ( V_10 , V_81 , true ) ;
F_19 ( V_10 ) ;
F_15 ( V_10 , true ) ;
F_26 ( & V_2 -> V_121 , V_87 ) ;
F_11 ( V_10 ) ;
}
static void F_27 ( struct V_9 * V_10 , int V_81 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
unsigned long V_87 ;
struct V_88 * V_89 ;
unsigned int V_90 , V_92 , V_64 ;
unsigned int V_93 , V_94 ;
unsigned int V_95 , V_96 , V_97 , V_98 ;
unsigned int V_99 , V_100 ;
T_3 V_109 ;
unsigned int V_129 ;
T_1 V_5 ;
V_89 = & V_10 -> V_89 [ V_81 ] ;
#define F_28 4
#define F_29 5
#define F_30 6
#define F_31 7
switch ( V_89 -> V_130 ) {
case 16 :
V_129 = F_30 ;
break;
case 32 :
V_129 = F_31 ;
break;
default:
V_129 = F_31 ;
}
V_109 = V_89 -> V_109 ;
V_90 = V_89 -> V_110 ;
V_92 = V_89 -> V_112 ;
V_64 = V_89 -> V_113 ;
V_99 = V_89 -> V_99 ;
V_100 = V_89 -> V_100 ;
V_93 = 0 ;
V_94 = 0 ;
V_95 = V_89 -> V_114 ;
V_96 = V_89 -> V_115 ;
V_97 = V_89 -> V_116 ;
V_98 = V_89 -> V_117 ;
V_109 = V_109
+ ( V_95 * V_89 -> V_130 >> 3 )
+ ( V_96 * V_90 * V_89 -> V_130 >> 3 ) ;
V_95 = 0 ;
V_96 = 0 ;
if ( V_89 -> V_119 & V_120 )
V_10 -> V_65 = true ;
else
V_10 -> V_65 = false ;
F_22 ( & V_2 -> V_121 , V_87 ) ;
F_15 ( V_10 , false ) ;
F_8 ( V_2 , F_32 ( V_81 ) ,
F_33 ( V_129 ) , V_131 ) ;
F_7 ( V_2 , F_34 ( V_81 ) , V_90 ) ;
V_5 = F_35 ( V_92 ) ;
V_5 |= F_36 ( V_64 ) ;
V_5 |= F_37 ( V_93 ) ;
V_5 |= F_38 ( V_94 ) ;
F_7 ( V_2 , F_39 ( V_81 ) , V_5 ) ;
V_5 = F_40 ( V_95 ) ;
V_5 |= F_41 ( V_96 ) ;
F_7 ( V_2 , F_42 ( V_81 ) , V_5 ) ;
V_5 = F_43 ( V_97 ) ;
V_5 |= F_44 ( V_98 ) ;
F_7 ( V_2 , F_45 ( V_81 ) , V_5 ) ;
F_7 ( V_2 , F_46 ( V_81 ) , V_109 ) ;
F_16 ( V_10 , V_100 ) ;
F_17 ( V_10 , V_100 ) ;
F_18 ( V_10 , V_81 , true ) ;
F_19 ( V_10 ) ;
F_15 ( V_10 , true ) ;
F_26 ( & V_2 -> V_121 , V_87 ) ;
}
static void F_47 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
int V_132 = 100 ;
F_3 ( V_2 , V_30 , V_133 ) ;
for ( V_132 = 100 ; V_132 ; -- V_132 ) {
if ( ~ F_1 ( V_2 , V_30 ) & V_133 )
break;
F_48 ( 10 ) ;
}
F_49 ( V_132 == 0 , L_2 ) ;
}
static int F_50 ( void * V_10 , int V_134 )
{
struct V_9 * V_135 = V_10 ;
struct V_1 * V_2 = & V_135 -> V_61 ;
F_51 ( L_3 , __LINE__ , V_136 ) ;
V_135 -> V_134 = V_134 ;
F_8 ( V_2 , V_13 , V_137 ,
V_137 ) ;
return 0 ;
}
static void F_52 ( void * V_10 )
{
struct V_9 * V_135 = V_10 ;
struct V_1 * V_2 = & V_135 -> V_61 ;
F_51 ( L_3 , __LINE__ , V_136 ) ;
F_8 ( V_2 , V_13 , 0 , V_137 ) ;
}
static void F_53 ( void * V_10 ,
struct V_138 * V_139 )
{
struct V_9 * V_135 = V_10 ;
struct V_88 * V_89 ;
int V_81 ;
F_51 ( L_3 , __LINE__ , V_136 ) ;
if ( ! V_139 ) {
F_21 ( L_4 ) ;
return;
}
F_51 ( L_5 ,
V_139 -> V_110 , V_139 -> V_111 ,
V_139 -> V_114 , V_139 -> V_115 ,
V_139 -> V_112 , V_139 -> V_113 ,
V_139 -> V_116 , V_139 -> V_117 ) ;
V_81 = V_139 -> V_140 ;
if ( V_81 == V_141 )
V_81 = V_135 -> V_142 ;
if ( V_81 < 0 || V_81 > V_143 ) {
F_21 ( L_6 , V_81 ) ;
return;
}
V_89 = & V_135 -> V_89 [ V_81 ] ;
V_89 -> V_109 = V_139 -> V_109 [ 0 ] ;
V_89 -> V_144 = V_139 -> V_144 [ 0 ] ;
V_89 -> V_118 = V_139 -> V_109 [ 1 ] ;
V_89 -> V_145 = V_139 -> V_144 [ 1 ] ;
V_89 -> V_106 = V_139 -> V_106 ;
V_89 -> V_130 = V_139 -> V_130 ;
V_89 -> V_116 = V_139 -> V_116 ;
V_89 -> V_117 = V_139 -> V_117 ;
V_89 -> V_112 = V_139 -> V_112 ;
V_89 -> V_113 = V_139 -> V_113 ;
V_89 -> V_114 = V_139 -> V_114 ;
V_89 -> V_115 = V_139 -> V_115 ;
V_89 -> V_110 = V_139 -> V_110 ;
V_89 -> V_111 = V_139 -> V_111 ;
V_89 -> V_99 = V_139 -> V_99 ;
V_89 -> V_100 = V_139 -> V_100 ;
V_89 -> V_119 = V_139 -> V_146 ;
}
static void F_54 ( void * V_10 , int V_140 )
{
struct V_9 * V_135 = V_10 ;
int V_81 = V_140 ;
F_51 ( L_7 , __LINE__ , V_136 , V_81 ) ;
if ( V_81 == V_141 )
V_81 = V_135 -> V_142 ;
if ( V_81 < 0 || V_81 > V_143 ) {
F_21 ( L_6 , V_81 ) ;
return;
}
if ( V_81 > 1 )
F_20 ( V_135 , V_81 ) ;
else
F_27 ( V_135 , V_81 ) ;
}
static void F_55 ( void * V_10 , int V_140 )
{
struct V_9 * V_135 = V_10 ;
struct V_1 * V_2 = & V_135 -> V_61 ;
unsigned long V_87 ;
int V_81 = V_140 ;
F_51 ( L_7 , __LINE__ , V_136 , V_81 ) ;
if ( V_81 == V_141 )
V_81 = V_135 -> V_142 ;
if ( V_81 < 0 || V_81 > V_143 ) {
F_21 ( L_6 , V_81 ) ;
return;
}
F_22 ( & V_2 -> V_121 , V_87 ) ;
F_15 ( V_135 , false ) ;
F_18 ( V_135 , V_81 , false ) ;
F_15 ( V_135 , true ) ;
F_26 ( & V_2 -> V_121 , V_87 ) ;
}
static void F_56 ( struct V_147 * V_148 , int V_149 )
{
struct V_150 * V_151 = V_148 -> V_152 ;
struct V_153 * V_154 , * V_155 ;
struct V_156 V_157 ;
unsigned long V_87 ;
bool V_158 = false ;
F_22 ( & V_148 -> V_159 , V_87 ) ;
F_57 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_149 != V_154 -> V_134 )
continue;
V_158 = true ;
F_58 ( & V_157 ) ;
V_154 -> V_160 . V_161 = 0 ;
V_154 -> V_160 . V_162 = V_157 . V_162 ;
V_154 -> V_160 . V_163 = V_157 . V_163 ;
F_59 ( & V_154 -> V_164 . V_165 , & V_154 -> V_164 . V_166 -> V_167 ) ;
F_60 ( & V_154 -> V_164 . V_166 -> V_168 ) ;
}
if ( V_158 )
if ( F_61 ( & V_148 -> V_169 [ V_149 ] ) > 0 )
F_62 ( V_148 , V_149 ) ;
F_26 ( & V_148 -> V_159 , V_87 ) ;
}
static T_4 F_63 ( int V_170 , void * V_171 )
{
struct V_172 * V_173 = V_171 ;
struct V_9 * V_10 =
(struct V_9 * ) V_173 -> V_10 ;
struct V_1 * V_2 = & V_10 -> V_61 ;
T_1 V_5 , V_174 ;
F_64 ( & V_2 -> V_121 ) ;
V_5 = F_6 ( V_2 , V_14 ) ;
if ( V_5 & V_175 ) {
if ( V_10 -> V_65 ) {
V_174 = F_6 ( V_2 , F_65 ( 0 ) ) ;
if ( V_10 -> V_89 [ 0 ] . V_109 != V_174 )
goto V_176;
V_174 = F_6 ( V_2 , F_65 ( 1 ) ) ;
if ( V_10 -> V_89 [ 1 ] . V_109 != V_174 )
goto V_176;
}
F_66 ( V_173 -> V_148 , V_10 -> V_134 ) ;
F_56 ( V_173 -> V_148 , V_10 -> V_134 ) ;
}
V_176:
if ( ~ V_5 & V_137 ) {
V_5 &= ~ V_137 ;
V_5 |= V_177 ;
}
F_7 ( V_2 , V_14 , V_5 ) ;
F_67 ( & V_2 -> V_121 ) ;
return V_178 ;
}
static void F_68 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
unsigned long V_87 ;
T_1 V_5 ;
F_22 ( & V_2 -> V_121 , V_87 ) ;
F_15 ( V_10 , false ) ;
F_8 ( V_2 , V_12 , V_179 , V_180 ) ;
F_8 ( V_2 , V_12 , V_181 , V_182 ) ;
F_8 ( V_2 , V_11 , V_183 ,
V_184 ) ;
V_5 = F_69 ( 3 ) ;
V_5 |= F_70 ( 2 ) ;
V_5 |= F_71 ( 1 ) ;
F_7 ( V_2 , V_15 , V_5 ) ;
F_7 ( V_2 , V_185 , 0x008080 ) ;
F_7 ( V_2 , V_186 , 0x008080 ) ;
F_7 ( V_2 , V_187 , 0x008080 ) ;
V_5 = V_188 ;
V_5 |= V_189 ;
V_5 |= F_72 ( 0xff ) ;
F_7 ( V_2 , F_32 ( 0 ) , V_5 ) ;
V_5 |= V_190 ;
V_5 |= V_191 ;
F_7 ( V_2 , F_32 ( 1 ) , V_5 ) ;
F_47 ( V_10 ) ;
F_14 ( V_2 ) ;
F_8 ( V_2 , V_12 , 0 , V_82 ) ;
F_8 ( V_2 , V_12 , 0 , V_83 ) ;
F_8 ( V_2 , V_12 , 0 , V_85 ) ;
F_15 ( V_10 , true ) ;
F_26 ( & V_2 -> V_121 , V_87 ) ;
}
static void F_73 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_51 ( L_3 , __LINE__ , V_136 ) ;
F_74 ( V_2 -> V_192 ) ;
F_74 ( V_2 -> V_193 ) ;
F_74 ( V_2 -> V_194 ) ;
F_68 ( V_10 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_51 ( L_3 , __LINE__ , V_136 ) ;
F_76 ( V_2 -> V_192 ) ;
F_76 ( V_2 -> V_193 ) ;
F_76 ( V_2 -> V_194 ) ;
}
static int F_77 ( struct V_195 * V_196 )
{
struct V_172 * V_10 = F_78 ( V_196 ) ;
F_51 ( L_8 ) ;
F_73 ( (struct V_9 * ) V_10 -> V_10 ) ;
return 0 ;
}
static int F_79 ( struct V_195 * V_196 )
{
struct V_172 * V_10 = F_78 ( V_196 ) ;
F_51 ( L_9 ) ;
F_75 ( (struct V_9 * ) V_10 -> V_10 ) ;
return 0 ;
}
static int T_5 F_80 ( struct V_172 * V_10 ,
struct V_197 * V_198 )
{
struct V_9 * V_135 =
(struct V_9 * ) V_10 -> V_10 ;
struct V_195 * V_196 = & V_198 -> V_196 ;
struct V_1 * V_61 = & V_135 -> V_61 ;
struct V_199 * V_2 ;
int V_200 ;
V_61 -> V_196 = V_196 ;
F_81 ( & V_61 -> V_121 ) ;
V_61 -> V_192 = F_82 ( V_196 , L_10 ) ;
if ( F_83 ( V_61 -> V_192 ) ) {
F_84 ( V_196 , L_11 ) ;
V_200 = - V_201 ;
goto V_202;
}
V_61 -> V_193 = F_82 ( V_196 , L_12 ) ;
if ( F_83 ( V_61 -> V_193 ) ) {
F_84 ( V_196 , L_13 ) ;
V_200 = - V_201 ;
goto V_202;
}
V_61 -> V_194 = F_82 ( V_196 , L_14 ) ;
if ( F_83 ( V_61 -> V_194 ) ) {
F_84 ( V_196 , L_15 ) ;
V_200 = - V_201 ;
goto V_202;
}
V_61 -> V_203 = F_82 ( V_196 , L_16 ) ;
if ( F_83 ( V_61 -> V_203 ) ) {
F_84 ( V_196 , L_17 ) ;
V_200 = - V_201 ;
goto V_202;
}
V_61 -> V_204 = F_82 ( V_196 , L_18 ) ;
if ( F_83 ( V_61 -> V_204 ) ) {
F_84 ( V_196 , L_19 ) ;
V_200 = - V_201 ;
goto V_202;
}
V_2 = F_85 ( V_198 , V_205 , L_20 ) ;
if ( V_2 == NULL ) {
F_84 ( V_196 , L_21 ) ;
V_200 = - V_206 ;
goto V_202;
}
F_86 ( V_61 -> V_194 , V_61 -> V_203 ) ;
V_61 -> V_8 = F_87 ( V_2 -> V_207 , F_88 ( V_2 ) ) ;
if ( V_61 -> V_8 == NULL ) {
F_84 ( V_196 , L_22 ) ;
V_200 = - V_206 ;
goto V_202;
}
V_2 = F_85 ( V_198 , V_205 , L_12 ) ;
if ( V_2 == NULL ) {
F_84 ( V_196 , L_21 ) ;
V_200 = - V_206 ;
goto V_208;
}
V_61 -> V_4 = F_87 ( V_2 -> V_207 , F_88 ( V_2 ) ) ;
if ( V_61 -> V_4 == NULL ) {
F_84 ( V_196 , L_22 ) ;
V_200 = - V_206 ;
goto V_208;
}
V_2 = F_85 ( V_198 , V_209 , L_23 ) ;
if ( V_2 == NULL ) {
F_84 ( V_196 , L_24 ) ;
V_200 = - V_206 ;
goto V_210;
}
V_200 = F_89 ( V_2 -> V_207 , F_63 , 0 , L_25 , V_10 ) ;
if ( V_200 ) {
F_84 ( V_196 , L_26 ) ;
goto V_210;
}
V_61 -> V_170 = V_2 -> V_207 ;
return 0 ;
V_210:
F_90 ( V_61 -> V_4 ) ;
V_208:
F_90 ( V_61 -> V_8 ) ;
V_202:
if ( ! F_83 ( V_61 -> V_204 ) )
F_91 ( V_61 -> V_204 ) ;
if ( ! F_83 ( V_61 -> V_203 ) )
F_91 ( V_61 -> V_203 ) ;
if ( ! F_83 ( V_61 -> V_194 ) )
F_91 ( V_61 -> V_194 ) ;
if ( ! F_83 ( V_61 -> V_193 ) )
F_91 ( V_61 -> V_193 ) ;
if ( ! F_83 ( V_61 -> V_192 ) )
F_91 ( V_61 -> V_192 ) ;
V_61 -> V_196 = NULL ;
return V_200 ;
}
static void F_92 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_10 -> V_61 ;
F_93 ( V_2 -> V_170 ) ;
F_94 ( V_2 -> V_170 , V_10 ) ;
F_90 ( V_2 -> V_4 ) ;
F_90 ( V_2 -> V_8 ) ;
}
static int T_5 F_95 ( struct V_197 * V_198 )
{
struct V_195 * V_196 = & V_198 -> V_196 ;
struct V_172 * V_173 ;
struct V_9 * V_10 ;
int V_200 ;
F_96 ( V_196 , L_27 ) ;
V_173 = F_97 ( sizeof( * V_173 ) , V_211 ) ;
if ( ! V_173 ) {
F_21 ( L_28 ) ;
return - V_212 ;
}
V_10 = F_97 ( sizeof( * V_10 ) , V_211 ) ;
if ( ! V_10 ) {
F_21 ( L_29 ) ;
F_98 ( V_173 ) ;
return - V_212 ;
}
V_173 -> V_10 = ( void * ) V_10 ;
F_99 ( V_198 , V_173 ) ;
V_200 = F_80 ( V_173 , V_198 ) ;
if ( V_200 )
goto V_202;
F_100 ( & V_213 ) ;
F_73 ( V_10 ) ;
return 0 ;
V_202:
F_96 ( V_196 , L_30 ) ;
return V_200 ;
}
static int F_101 ( struct V_197 * V_198 )
{
struct V_195 * V_196 = & V_198 -> V_196 ;
struct V_172 * V_173 =
F_102 ( V_198 ) ;
struct V_9 * V_10 = (struct V_9 * ) V_173 -> V_10 ;
F_96 ( V_196 , L_31 ) ;
F_75 ( V_10 ) ;
F_92 ( V_10 ) ;
return 0 ;
}
