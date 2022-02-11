static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( V_4 ) ;
if ( V_2 -> V_5 == V_6 && V_3 == V_7 )
V_3 = ( T_1 ) - 1 ;
if ( V_2 -> V_5 == V_8 && V_3 == V_6 )
V_3 = V_7 ;
if ( V_3 != ( T_1 ) - 1 ) {
V_2 -> V_5 = V_3 ;
F_3 ( & V_2 -> V_9 ) ;
}
F_4 ( V_4 ) ;
}
static inline T_1 F_5 ( T_1 V_10 , struct V_11 * V_12 )
{
V_10 &= 0xffff ;
V_10 >>= 16 - V_12 -> V_13 ;
return V_10 << V_12 -> V_14 ;
}
static inline T_1 F_6 ( struct V_15 * V_16 )
{
int V_17 = 0 ;
switch ( V_16 -> V_18 ) {
case 4 : V_17 = 0 << 12 ; break;
case 8 : V_17 = 1 << 12 ; break;
case 16 : V_17 = 2 << 12 ; break;
}
return V_17 ;
}
static int
F_7 ( T_1 V_19 , T_1 V_20 , T_1 V_21 , T_1 V_22 ,
T_1 V_23 , struct V_24 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
T_1 V_26 , V_17 = 1 ;
if ( V_19 < V_2 -> V_27 ) {
V_26 = ( ( V_20 >> 4 ) & 0xf00 ) ;
V_26 |= ( ( V_21 >> 8 ) & 0x0f0 ) ;
V_26 |= ( ( V_22 >> 12 ) & 0x00f ) ;
if ( V_19 == 0 )
V_26 |= F_6 ( & V_2 -> V_28 . V_16 ) ;
V_2 -> V_29 [ V_19 ] = V_26 ;
V_17 = 0 ;
}
return V_17 ;
}
static int
F_8 ( T_1 V_19 , T_1 V_20 , T_1 V_21 , T_1 V_22 ,
T_1 V_23 , struct V_24 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
unsigned int V_26 ;
int V_17 = 1 ;
if ( V_2 -> V_30 -> V_31 ) {
V_20 = 0xffff - V_20 ;
V_21 = 0xffff - V_21 ;
V_22 = 0xffff - V_22 ;
}
if ( V_2 -> V_28 . V_16 . V_32 )
V_20 = V_21 = V_22 = ( 19595 * V_20 + 38470 * V_21 +
7471 * V_22 ) >> 16 ;
switch ( V_2 -> V_28 . V_33 . V_34 ) {
case V_35 :
if ( V_19 < 16 ) {
T_2 * V_36 = V_2 -> V_28 . V_37 ;
V_26 = F_5 ( V_20 , & V_2 -> V_28 . V_16 . V_20 ) ;
V_26 |= F_5 ( V_21 , & V_2 -> V_28 . V_16 . V_21 ) ;
V_26 |= F_5 ( V_22 , & V_2 -> V_28 . V_16 . V_22 ) ;
V_36 [ V_19 ] = V_26 ;
V_17 = 0 ;
}
break;
case V_38 :
case V_39 :
V_17 = F_7 ( V_19 , V_20 , V_21 , V_22 , V_23 , V_25 ) ;
break;
}
return V_17 ;
}
static inline unsigned int F_9 ( struct V_15 * V_16 )
{
return V_16 -> V_40 * 8 * 16 / V_16 -> V_18 ;
}
static int
F_10 ( struct V_15 * V_16 , struct V_24 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
int V_41 ;
if ( V_16 -> V_42 < V_43 )
V_16 -> V_42 = V_43 ;
if ( V_16 -> V_44 < V_45 )
V_16 -> V_44 = V_45 ;
if ( V_16 -> V_42 > V_2 -> V_30 -> V_42 )
V_16 -> V_42 = V_2 -> V_30 -> V_42 ;
if ( V_16 -> V_44 > V_2 -> V_30 -> V_44 )
V_16 -> V_44 = V_2 -> V_30 -> V_44 ;
V_16 -> V_46 = F_11 ( V_16 -> V_46 , V_16 -> V_42 ) ;
V_16 -> V_47 = F_11 ( V_16 -> V_47 , V_16 -> V_44 ) ;
F_12 ( V_2 -> V_48 , L_1 , V_16 -> V_18 ) ;
switch ( V_16 -> V_18 ) {
case 4 :
V_41 = V_49 ;
break;
case 8 :
V_41 = V_50 ;
break;
case 16 :
V_41 = V_51 ;
break;
default:
return - V_52 ;
}
V_16 -> V_20 = V_2 -> V_53 [ V_41 ] -> V_20 ;
V_16 -> V_21 = V_2 -> V_53 [ V_41 ] -> V_21 ;
V_16 -> V_22 = V_2 -> V_53 [ V_41 ] -> V_22 ;
V_16 -> V_54 = V_2 -> V_53 [ V_41 ] -> V_54 ;
F_12 ( V_2 -> V_48 , L_2 ,
V_16 -> V_20 . V_13 , V_16 -> V_21 . V_13 , V_16 -> V_22 . V_13 ,
V_16 -> V_54 . V_13 ) ;
F_12 ( V_2 -> V_48 , L_3 ,
V_16 -> V_20 . V_14 , V_16 -> V_21 . V_14 , V_16 -> V_22 . V_14 ,
V_16 -> V_54 . V_14 ) ;
#ifdef F_13
F_12 ( V_2 -> V_48 , L_4 ,
F_9 ( V_16 ) ,
F_14 ( F_15 () ) ) ;
#endif
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_34 )
{
if ( V_2 -> V_30 -> V_55 )
V_2 -> V_30 -> V_55 ( V_34 ) ;
}
static int F_17 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
struct V_15 * V_16 = & V_25 -> V_16 ;
unsigned long V_56 ;
F_12 ( V_2 -> V_48 , L_5 ) ;
if ( V_16 -> V_18 == 16 )
V_2 -> V_28 . V_33 . V_34 = V_35 ;
else if ( ! V_2 -> V_30 -> V_57 )
V_2 -> V_28 . V_33 . V_34 = V_39 ;
else {
V_2 -> V_28 . V_33 . V_34 = V_38 ;
}
V_2 -> V_28 . V_33 . V_58 = V_16 -> V_46 *
V_16 -> V_18 / 8 ;
V_2 -> V_27 = V_16 -> V_18 == 8 ? 256 : 16 ;
V_56 = V_2 -> V_27 * sizeof( V_59 ) ;
F_12 ( V_2 -> V_48 , L_6 , V_56 ) ;
V_2 -> V_29 = ( V_59 * ) ( V_2 -> V_60 + V_61 - V_56 ) ;
V_2 -> V_62 = V_2 -> V_63 + V_61 - V_56 ;
F_16 ( V_2 , V_2 -> V_28 . V_33 . V_34 ) ;
F_18 ( V_16 , V_2 ) ;
return 0 ;
}
static int F_19 ( int V_64 , struct V_24 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
int V_65 ;
F_12 ( V_2 -> V_48 , L_7 , V_64 ) ;
switch ( V_64 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
if ( V_2 -> V_28 . V_33 . V_34 == V_39 ||
V_2 -> V_28 . V_33 . V_34 == V_38 )
for ( V_65 = 0 ; V_65 < V_2 -> V_27 ; V_65 ++ )
F_7 ( V_65 , 0 , 0 , 0 , 0 , V_25 ) ;
F_1 ( V_2 , V_8 ) ;
break;
case V_70 :
if ( V_2 -> V_28 . V_33 . V_34 == V_39 ||
V_2 -> V_28 . V_33 . V_34 == V_38 )
F_20 ( & V_2 -> V_28 . V_71 , V_25 ) ;
F_1 ( V_2 , V_6 ) ;
}
return 0 ;
}
static int F_21 ( struct V_24 * V_25 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
unsigned long V_74 = V_73 -> V_75 << V_76 ;
if ( V_74 < V_25 -> V_33 . V_77 ) {
V_73 -> V_75 += 1 ;
return F_22 ( V_2 -> V_48 , V_73 , V_2 -> V_60 ,
V_2 -> V_63 , V_2 -> V_78 ) ;
}
V_73 -> V_79 = F_23 ( V_73 -> V_79 ) ;
return F_24 ( V_73 , V_25 -> V_33 . V_80 , V_25 -> V_33 . V_81 ) ;
}
static inline unsigned int F_25 ( unsigned int V_40 , unsigned int V_82 )
{
unsigned int V_83 = V_82 / 100 ;
V_83 *= V_40 ;
V_83 /= 10000000 ;
return V_83 + 1 ;
}
static int F_18 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_84 V_85 ;
T_1 V_86 , V_44 , V_83 ;
T_3 V_4 ;
F_12 ( V_2 -> V_48 , L_8 ) ;
F_12 ( V_2 -> V_48 , L_9 ,
V_16 -> V_42 , V_16 -> V_87 ,
V_16 -> V_88 , V_16 -> V_89 ) ;
F_12 ( V_2 -> V_48 , L_10 ,
V_16 -> V_44 , V_16 -> V_90 ,
V_16 -> V_91 , V_16 -> V_92 ) ;
#if V_93
if ( V_16 -> V_42 < 16 || V_16 -> V_42 > 1024 )
F_26 ( V_2 -> V_48 , L_11 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_42 ) ;
if ( V_16 -> V_87 < 1 || V_16 -> V_87 > 64 )
F_26 ( V_2 -> V_48 , L_12 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_87 ) ;
if ( V_16 -> V_88 < 1 || V_16 -> V_88 > 255 )
F_26 ( V_2 -> V_48 , L_13 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_88 ) ;
if ( V_16 -> V_89 < 1 || V_16 -> V_89 > 255 )
F_26 ( V_2 -> V_48 , L_14 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_89 ) ;
if ( V_16 -> V_44 < 1 || V_16 -> V_44 > 1024 )
F_26 ( V_2 -> V_48 , L_15 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_44 ) ;
if ( V_16 -> V_90 < 1 || V_16 -> V_90 > 64 )
F_26 ( V_2 -> V_48 , L_16 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_90 ) ;
if ( V_16 -> V_91 < 0 || V_16 -> V_91 > 255 )
F_26 ( V_2 -> V_48 , L_17 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_91 ) ;
if ( V_16 -> V_92 < 0 || V_16 -> V_92 > 255 )
F_26 ( V_2 -> V_48 , L_18 ,
V_2 -> V_28 . V_33 . V_94 , V_16 -> V_92 ) ;
#endif
V_85 . V_95 = V_2 -> V_30 -> V_95 |
V_96 | V_97 | V_98 |
V_99 | V_100 | F_27 ( 0 ) ;
V_85 . V_101 =
F_28 ( V_16 -> V_42 ) +
F_29 ( V_16 -> V_87 ) +
F_30 ( V_16 -> V_88 ) +
F_31 ( V_16 -> V_89 ) ;
V_44 = V_16 -> V_44 ;
if ( V_2 -> V_30 -> V_95 & V_102 )
V_44 /= 2 ;
V_85 . V_103 =
F_32 ( V_44 ) +
F_33 ( V_16 -> V_90 ) +
F_34 ( V_16 -> V_91 ) +
F_35 ( V_16 -> V_92 ) ;
V_83 = F_25 ( V_16 -> V_40 , F_14 ( 0 ) ) ;
V_85 . V_104 = F_36 ( V_83 ) | V_2 -> V_30 -> V_104 |
( V_16 -> V_105 & V_106 ? V_107 : V_108 ) |
( V_16 -> V_105 & V_109 ? V_110 : V_111 ) ;
F_12 ( V_2 -> V_48 , L_19 , V_85 . V_95 ) ;
F_12 ( V_2 -> V_48 , L_20 , V_85 . V_101 ) ;
F_12 ( V_2 -> V_48 , L_21 , V_85 . V_103 ) ;
F_12 ( V_2 -> V_48 , L_22 , V_85 . V_104 ) ;
V_86 = V_16 -> V_18 ;
V_86 = V_86 * V_16 -> V_42 * V_16 -> V_44 / 16 ;
F_2 ( V_4 ) ;
V_2 -> V_112 = V_2 -> V_62 ;
V_2 -> V_113 = V_2 -> V_114 + V_86 ;
V_2 -> V_115 = V_85 . V_95 ;
V_2 -> V_116 = V_85 . V_101 ;
V_2 -> V_117 = V_85 . V_103 ;
V_2 -> V_118 = V_85 . V_104 ;
F_4 ( V_4 ) ;
if ( F_37 ( V_2 -> V_119 + V_120 ) != V_2 -> V_115 ||
F_37 ( V_2 -> V_119 + V_121 ) != V_2 -> V_116 ||
F_37 ( V_2 -> V_119 + V_122 ) != V_2 -> V_117 ||
F_37 ( V_2 -> V_119 + V_123 ) != V_2 -> V_118 ||
F_37 ( V_2 -> V_119 + V_124 ) != V_2 -> V_112 ||
F_37 ( V_2 -> V_119 + V_125 ) != V_2 -> V_113 )
F_1 ( V_2 , V_7 ) ;
return 0 ;
}
static inline void F_38 ( struct V_1 * V_2 , int V_126 )
{
F_12 ( V_2 -> V_48 , L_23 , V_126 ? L_24 : L_25 ) ;
if ( V_2 -> V_30 -> V_127 )
V_2 -> V_30 -> V_127 ( V_126 ) ;
}
static inline void F_39 ( struct V_1 * V_2 , int V_126 )
{
F_12 ( V_2 -> V_48 , L_26 , V_126 ? L_24 : L_25 ) ;
if ( V_2 -> V_30 -> V_128 )
V_2 -> V_30 -> V_128 ( V_126 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_129 = 0 ;
if ( ( V_2 -> V_115 & V_130 ) == V_131 &&
( V_2 -> V_115 & ( V_102 | V_132 ) ) != 0 ) {
V_129 = V_133 | V_134 | V_135 | V_136 ;
if ( V_2 -> V_28 . V_16 . V_18 > 8 ||
( V_2 -> V_115 & ( V_102 | V_132 ) ) == V_102 )
V_129 |= V_137 | V_138 | V_139 | V_140 ;
}
if ( V_129 ) {
unsigned long V_4 ;
F_2 ( V_4 ) ;
V_141 |= V_129 ;
V_142 |= V_129 ;
F_4 ( V_4 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_48 , L_27 ) ;
V_2 -> V_29 [ 0 ] &= 0xcfff ;
V_2 -> V_29 [ 0 ] |= F_6 ( & V_2 -> V_28 . V_16 ) ;
F_42 ( V_2 -> V_118 , V_2 -> V_119 + V_123 ) ;
F_42 ( V_2 -> V_117 , V_2 -> V_119 + V_122 ) ;
F_42 ( V_2 -> V_116 , V_2 -> V_119 + V_121 ) ;
F_42 ( V_2 -> V_115 & ~ V_96 , V_2 -> V_119 + V_120 ) ;
F_42 ( V_2 -> V_112 , V_2 -> V_119 + V_124 ) ;
F_42 ( V_2 -> V_113 , V_2 -> V_119 + V_125 ) ;
F_42 ( V_2 -> V_115 | V_96 , V_2 -> V_119 + V_120 ) ;
if ( F_43 () )
F_44 ( V_143 , 1 ) ;
F_12 ( V_2 -> V_48 , L_28 , F_37 ( V_2 -> V_119 + V_124 ) ) ;
F_12 ( V_2 -> V_48 , L_29 , F_37 ( V_2 -> V_119 + V_125 ) ) ;
F_12 ( V_2 -> V_48 , L_30 , F_37 ( V_2 -> V_119 + V_120 ) ) ;
F_12 ( V_2 -> V_48 , L_31 , F_37 ( V_2 -> V_119 + V_121 ) ) ;
F_12 ( V_2 -> V_48 , L_32 , F_37 ( V_2 -> V_119 + V_122 ) ) ;
F_12 ( V_2 -> V_48 , L_33 , F_37 ( V_2 -> V_119 + V_123 ) ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_144 , V_145 ) ;
T_2 V_95 ;
F_12 ( V_2 -> V_48 , L_34 ) ;
if ( F_43 () )
F_44 ( V_143 , 0 ) ;
F_47 ( V_146 ) ;
F_48 ( & V_2 -> V_147 , & V_144 ) ;
F_42 ( ~ 0 , V_2 -> V_119 + V_148 ) ;
V_95 = F_37 ( V_2 -> V_119 + V_120 ) ;
V_95 &= ~ V_97 ;
F_42 ( V_95 , V_2 -> V_119 + V_120 ) ;
V_95 &= ~ V_96 ;
F_42 ( V_95 , V_2 -> V_119 + V_120 ) ;
F_49 ( 20 * V_149 / 1000 ) ;
F_50 ( & V_2 -> V_147 , & V_144 ) ;
}
static T_4 F_51 ( int V_150 , void * V_151 )
{
struct V_1 * V_2 = V_151 ;
unsigned int V_152 = F_37 ( V_2 -> V_119 + V_148 ) ;
if ( V_152 & V_153 ) {
T_2 V_95 = F_37 ( V_2 -> V_119 + V_120 ) | V_97 ;
F_42 ( V_95 , V_2 -> V_119 + V_120 ) ;
F_52 ( & V_2 -> V_147 ) ;
}
F_42 ( V_152 , V_2 -> V_119 + V_148 ) ;
return V_154 ;
}
static void F_53 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_155 ;
F_54 ( & V_2 -> V_156 ) ;
V_155 = V_2 -> V_3 ;
if ( V_155 == V_157 && V_3 == V_7 )
V_3 = V_6 ;
switch ( V_3 ) {
case V_158 :
if ( V_155 != V_8 && V_155 != V_159 ) {
V_2 -> V_3 = V_3 ;
F_45 ( V_2 ) ;
}
break;
case V_159 :
case V_8 :
if ( V_155 != V_8 ) {
V_2 -> V_3 = V_3 ;
F_38 ( V_2 , 0 ) ;
if ( V_155 != V_158 )
F_45 ( V_2 ) ;
F_39 ( V_2 , 0 ) ;
}
break;
case V_160 :
if ( V_155 == V_158 ) {
V_2 -> V_3 = V_6 ;
F_41 ( V_2 ) ;
}
break;
case V_7 :
if ( V_155 == V_6 ) {
F_45 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
break;
case V_161 :
if ( V_155 != V_159 )
break;
case V_6 :
if ( V_155 != V_6 ) {
V_2 -> V_3 = V_6 ;
F_40 ( V_2 ) ;
F_39 ( V_2 , 1 ) ;
F_41 ( V_2 ) ;
F_38 ( V_2 , 1 ) ;
}
break;
}
F_55 ( & V_2 -> V_156 ) ;
}
static void F_56 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = F_57 ( V_163 , struct V_1 , V_9 ) ;
T_1 V_3 = F_58 ( & V_2 -> V_5 , - 1 ) ;
F_53 ( V_2 , V_3 ) ;
}
static unsigned int F_59 ( struct V_1 * V_2 )
{
#if 0
unsigned int min_period = (unsigned int)-1;
int i;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
struct display *disp = &fb_display[i];
unsigned int period;
if (disp->fb_info != &fbi->fb)
continue;
period = sa1100fb_display_dma_period(&disp->var);
if (period < min_period)
min_period = period;
}
return min_period;
#else
return F_9 ( & V_2 -> V_28 . V_16 ) ;
#endif
}
static int
F_60 ( struct V_164 * V_165 , unsigned long V_26 ,
void * V_166 )
{
struct V_1 * V_2 = F_61 ( V_165 , V_167 ) ;
struct V_168 * V_169 = V_166 ;
T_1 V_83 ;
switch ( V_26 ) {
case V_170 :
F_53 ( V_2 , V_158 ) ;
break;
case V_171 :
V_83 = F_25 ( V_2 -> V_28 . V_16 . V_40 , V_169 -> V_172 ) ;
V_2 -> V_118 = ( V_2 -> V_118 & ~ 0xff ) | F_36 ( V_83 ) ;
F_53 ( V_2 , V_160 ) ;
break;
}
return 0 ;
}
static int
F_62 ( struct V_164 * V_165 , unsigned long V_26 ,
void * V_166 )
{
struct V_1 * V_2 = F_61 ( V_165 , V_173 ) ;
struct V_174 * V_175 = V_166 ;
switch ( V_26 ) {
case V_176 :
case V_177 :
F_12 ( V_2 -> V_48 , L_35
L_36 , F_59 ( V_2 ) ,
V_175 -> F_11 ) ;
break;
case V_178 :
do {} while( 0 );
break;
}
return 0 ;
}
static int F_63 ( struct V_179 * V_48 , T_5 V_3 )
{
struct V_1 * V_2 = F_64 ( V_48 ) ;
F_53 ( V_2 , V_159 ) ;
return 0 ;
}
static int F_65 ( struct V_179 * V_48 )
{
struct V_1 * V_2 = F_64 ( V_48 ) ;
F_53 ( V_2 , V_161 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
V_2 -> V_78 = F_67 ( V_2 -> V_28 . V_33 . V_77 + V_61 ) ;
V_2 -> V_60 = F_68 ( V_2 -> V_48 , V_2 -> V_78 ,
& V_2 -> V_63 , V_180 ) ;
if ( V_2 -> V_60 ) {
V_2 -> V_28 . V_181 = V_2 -> V_60 + V_61 ;
V_2 -> V_114 = V_2 -> V_63 + V_61 ;
V_2 -> V_28 . V_33 . V_182 = V_2 -> V_114 ;
}
return V_2 -> V_60 ? 0 : - V_183 ;
}
static struct V_1 * F_69 ( struct V_184 * V_48 )
{
struct V_185 * V_30 = V_48 -> V_186 ;
struct V_1 * V_2 ;
unsigned V_65 ;
V_2 = F_70 ( sizeof( struct V_1 ) + sizeof( T_2 ) * 16 ,
V_180 ) ;
if ( ! V_2 )
return NULL ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_48 = V_48 ;
strcpy ( V_2 -> V_28 . V_33 . V_94 , V_187 ) ;
V_2 -> V_28 . V_33 . type = V_188 ;
V_2 -> V_28 . V_33 . V_189 = 0 ;
V_2 -> V_28 . V_33 . V_190 = 0 ;
V_2 -> V_28 . V_33 . V_191 = 0 ;
V_2 -> V_28 . V_33 . V_192 = 0 ;
V_2 -> V_28 . V_33 . V_193 = V_194 ;
V_2 -> V_28 . V_16 . V_195 = 0 ;
V_2 -> V_28 . V_16 . V_196 = V_197 ;
V_2 -> V_28 . V_16 . V_198 = - 1 ;
V_2 -> V_28 . V_16 . V_199 = - 1 ;
V_2 -> V_28 . V_16 . V_200 = 0 ;
V_2 -> V_28 . V_16 . V_201 = V_202 ;
V_2 -> V_28 . V_203 = & V_204 ;
V_2 -> V_28 . V_4 = V_205 ;
V_2 -> V_28 . V_206 = V_206 ;
V_2 -> V_28 . V_37 = ( V_2 + 1 ) ;
V_2 -> V_53 [ V_49 ] = & V_207 ;
V_2 -> V_53 [ V_50 ] = & V_208 ;
V_2 -> V_53 [ V_51 ] = & V_209 ;
if ( V_30 -> V_104 & ( V_111 | V_108 | 0xff ) ||
V_30 -> V_40 == 0 )
F_71 ( L_37
L_38 ) ;
V_2 -> V_28 . V_16 . V_42 = V_30 -> V_42 ;
V_2 -> V_28 . V_16 . V_46 = V_30 -> V_42 ;
V_2 -> V_28 . V_16 . V_44 = V_30 -> V_44 ;
V_2 -> V_28 . V_16 . V_47 = V_30 -> V_44 ;
V_2 -> V_28 . V_16 . V_18 = V_30 -> V_210 ;
V_2 -> V_28 . V_16 . V_40 = V_30 -> V_40 ;
V_2 -> V_28 . V_16 . V_87 = V_30 -> V_87 ;
V_2 -> V_28 . V_16 . V_88 = V_30 -> V_88 ;
V_2 -> V_28 . V_16 . V_89 = V_30 -> V_89 ;
V_2 -> V_28 . V_16 . V_90 = V_30 -> V_90 ;
V_2 -> V_28 . V_16 . V_91 = V_30 -> V_91 ;
V_2 -> V_28 . V_16 . V_92 = V_30 -> V_92 ;
V_2 -> V_28 . V_16 . V_105 = V_30 -> V_105 ;
V_2 -> V_28 . V_16 . V_32 = V_30 -> V_211 ;
V_2 -> V_3 = V_157 ;
V_2 -> V_5 = ( V_212 ) - 1 ;
V_2 -> V_28 . V_33 . V_77 = V_30 -> V_42 * V_30 -> V_44 *
V_30 -> V_210 / 8 ;
V_2 -> V_30 = V_30 ;
for ( V_65 = 0 ; V_65 < V_213 ; V_65 ++ )
if ( V_30 -> V_53 [ V_65 ] )
V_2 -> V_53 [ V_65 ] = V_30 -> V_53 [ V_65 ] ;
F_72 ( & V_2 -> V_147 ) ;
F_73 ( & V_2 -> V_9 , F_56 ) ;
F_74 ( & V_2 -> V_156 ) ;
return V_2 ;
}
static int F_75 ( struct V_179 * V_214 )
{
struct V_1 * V_2 ;
struct V_215 * V_216 ;
int V_17 , V_150 ;
if ( ! V_214 -> V_48 . V_186 ) {
F_26 ( & V_214 -> V_48 , L_39 ) ;
return - V_52 ;
}
V_216 = F_76 ( V_214 , V_217 , 0 ) ;
V_150 = F_77 ( V_214 , 0 ) ;
if ( V_150 < 0 || ! V_216 )
return - V_52 ;
if ( ! F_78 ( V_216 -> V_218 , F_79 ( V_216 ) , L_40 ) )
return - V_219 ;
V_2 = F_69 ( & V_214 -> V_48 ) ;
V_17 = - V_183 ;
if ( ! V_2 )
goto V_220;
V_2 -> V_119 = F_80 ( V_216 -> V_218 , F_79 ( V_216 ) ) ;
if ( ! V_2 -> V_119 )
goto V_220;
V_17 = F_66 ( V_2 ) ;
if ( V_17 )
goto V_220;
V_17 = F_81 ( V_150 , F_51 , 0 , L_40 , V_2 ) ;
if ( V_17 ) {
F_26 ( & V_214 -> V_48 , L_41 , V_17 ) ;
goto V_220;
}
if ( F_43 () ) {
V_17 = F_82 ( V_143 ,
V_221 , L_42 ) ;
if ( V_17 )
goto V_222;
}
F_10 ( & V_2 -> V_28 . V_16 , & V_2 -> V_28 ) ;
F_83 ( V_214 , V_2 ) ;
V_17 = F_84 ( & V_2 -> V_28 ) ;
if ( V_17 < 0 )
goto V_223;
#ifdef F_13
V_2 -> V_167 . V_224 = F_60 ;
V_2 -> V_173 . V_224 = F_62 ;
F_85 ( & V_2 -> V_167 , V_225 ) ;
F_85 ( & V_2 -> V_173 , V_226 ) ;
#endif
return 0 ;
V_223:
if ( F_43 () )
F_86 ( V_143 ) ;
V_222:
F_87 ( V_150 , V_2 ) ;
V_220:
if ( V_2 )
F_88 ( V_2 -> V_119 ) ;
F_89 ( V_2 ) ;
F_90 ( V_216 -> V_218 , F_79 ( V_216 ) ) ;
return V_17 ;
}
int T_6 F_91 ( void )
{
if ( F_92 ( L_43 , NULL ) )
return - V_227 ;
return F_93 ( & V_228 ) ;
}
int T_6 F_94 ( char * V_229 )
{
#if 0
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "bpp:", 4))
current_par.max_bpp =
simple_strtoul(this_opt + 4, NULL, 0);
if (!strncmp(this_opt, "lccr0:", 6))
lcd_shadow.lccr0 =
simple_strtoul(this_opt + 6, NULL, 0);
if (!strncmp(this_opt, "lccr1:", 6)) {
lcd_shadow.lccr1 =
simple_strtoul(this_opt + 6, NULL, 0);
current_par.max_xres =
(lcd_shadow.lccr1 & 0x3ff) + 16;
}
if (!strncmp(this_opt, "lccr2:", 6)) {
lcd_shadow.lccr2 =
simple_strtoul(this_opt + 6, NULL, 0);
current_par.max_yres =
(lcd_shadow.
lccr0 & LCCR0_SDS) ? ((lcd_shadow.
lccr2 & 0x3ff) +
1) *
2 : ((lcd_shadow.lccr2 & 0x3ff) + 1);
}
if (!strncmp(this_opt, "lccr3:", 6))
lcd_shadow.lccr3 =
simple_strtoul(this_opt + 6, NULL, 0);
}
#endif
return 0 ;
}
