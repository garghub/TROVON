static struct V_1 * T_1
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
#ifdef F_2
if ( F_3 () ) {
#ifndef F_4
V_4 = & V_5 ;
#else
V_4 = & V_6 ;
#endif
}
#endif
#ifdef F_5
if ( F_6 () ) {
V_4 = & V_7 ;
}
#endif
#ifdef F_7
if ( F_8 () ) {
V_4 = & V_8 ;
V_3 -> V_9 [ V_10 ] = & V_11 ;
}
#endif
#ifdef F_9
if ( F_10 () ) {
V_4 = & V_12 ;
}
#endif
#ifdef F_11
if ( F_12 () ) {
#ifdef F_13
V_4 = & V_13 ;
#endif
#ifdef F_14
V_4 = & V_14 ;
#endif
#ifdef F_15
V_4 = & V_15 ;
#endif
#ifdef F_16
V_4 = & V_16 ;
#endif
}
#endif
#ifdef F_17
if ( F_18 () ) {
V_4 = & V_17 ;
}
#endif
return V_4 ;
}
static inline void F_19 ( struct V_2 * V_3 , T_2 V_18 )
{
unsigned long V_19 ;
F_20 ( V_19 ) ;
if ( V_3 -> V_20 == V_21 && V_18 == V_22 )
V_18 = ( T_2 ) - 1 ;
if ( V_3 -> V_20 == V_23 && V_18 == V_21 )
V_18 = V_22 ;
if ( V_18 != ( T_2 ) - 1 ) {
V_3 -> V_20 = V_18 ;
F_21 ( & V_3 -> V_24 ) ;
}
F_22 ( V_19 ) ;
}
static inline T_2 F_23 ( T_2 V_25 , struct V_26 * V_27 )
{
V_25 &= 0xffff ;
V_25 >>= 16 - V_27 -> V_28 ;
return V_25 << V_27 -> V_29 ;
}
static inline T_2 F_24 ( struct V_30 * V_31 )
{
int V_32 = 0 ;
switch ( V_31 -> V_33 ) {
case 4 : V_32 = 0 << 12 ; break;
case 8 : V_32 = 1 << 12 ; break;
case 16 : V_32 = 2 << 12 ; break;
}
return V_32 ;
}
static int
F_25 ( T_2 V_34 , T_2 V_35 , T_2 V_36 , T_2 V_37 ,
T_2 V_38 , struct V_39 * V_40 )
{
struct V_2 * V_3 = (struct V_2 * ) V_40 ;
T_2 V_41 , V_32 = 1 ;
if ( V_34 < V_3 -> V_42 ) {
V_41 = ( ( V_35 >> 4 ) & 0xf00 ) ;
V_41 |= ( ( V_36 >> 8 ) & 0x0f0 ) ;
V_41 |= ( ( V_37 >> 12 ) & 0x00f ) ;
if ( V_34 == 0 )
V_41 |= F_24 ( & V_3 -> V_43 . V_31 ) ;
V_3 -> V_44 [ V_34 ] = V_41 ;
V_32 = 0 ;
}
return V_32 ;
}
static int
F_26 ( T_2 V_34 , T_2 V_35 , T_2 V_36 , T_2 V_37 ,
T_2 V_38 , struct V_39 * V_40 )
{
struct V_2 * V_3 = (struct V_2 * ) V_40 ;
unsigned int V_41 ;
int V_32 = 1 ;
if ( V_3 -> V_45 ) {
V_35 = 0xffff - V_35 ;
V_36 = 0xffff - V_36 ;
V_37 = 0xffff - V_37 ;
}
if ( V_3 -> V_43 . V_31 . V_46 )
V_35 = V_36 = V_37 = ( 19595 * V_35 + 38470 * V_36 +
7471 * V_37 ) >> 16 ;
switch ( V_3 -> V_43 . V_47 . V_48 ) {
case V_49 :
if ( V_34 < 16 ) {
T_3 * V_50 = V_3 -> V_43 . V_51 ;
V_41 = F_23 ( V_35 , & V_3 -> V_43 . V_31 . V_35 ) ;
V_41 |= F_23 ( V_36 , & V_3 -> V_43 . V_31 . V_36 ) ;
V_41 |= F_23 ( V_37 , & V_3 -> V_43 . V_31 . V_37 ) ;
V_50 [ V_34 ] = V_41 ;
V_32 = 0 ;
}
break;
case V_52 :
case V_53 :
V_32 = F_25 ( V_34 , V_35 , V_36 , V_37 , V_38 , V_40 ) ;
break;
}
return V_32 ;
}
static inline unsigned int F_27 ( struct V_30 * V_31 )
{
return V_31 -> V_54 * 8 * 16 / V_31 -> V_33 ;
}
static int
F_28 ( struct V_30 * V_31 , struct V_39 * V_40 )
{
struct V_2 * V_3 = (struct V_2 * ) V_40 ;
int V_55 ;
if ( V_31 -> V_56 < V_57 )
V_31 -> V_56 = V_57 ;
if ( V_31 -> V_58 < V_59 )
V_31 -> V_58 = V_59 ;
if ( V_31 -> V_56 > V_3 -> V_60 )
V_31 -> V_56 = V_3 -> V_60 ;
if ( V_31 -> V_58 > V_3 -> V_61 )
V_31 -> V_58 = V_3 -> V_61 ;
V_31 -> V_62 = F_29 ( V_31 -> V_62 , V_31 -> V_56 ) ;
V_31 -> V_63 = F_29 ( V_31 -> V_63 , V_31 -> V_58 ) ;
F_30 ( L_1 , V_31 -> V_33 ) ;
switch ( V_31 -> V_33 ) {
case 4 :
V_55 = V_64 ;
break;
case 8 :
V_55 = V_65 ;
break;
case 16 :
V_55 = V_10 ;
break;
default:
return - V_66 ;
}
V_31 -> V_35 = V_3 -> V_9 [ V_55 ] -> V_35 ;
V_31 -> V_36 = V_3 -> V_9 [ V_55 ] -> V_36 ;
V_31 -> V_37 = V_3 -> V_9 [ V_55 ] -> V_37 ;
V_31 -> V_67 = V_3 -> V_9 [ V_55 ] -> V_67 ;
F_30 ( L_2 ,
V_31 -> V_35 . V_28 , V_31 -> V_36 . V_28 , V_31 -> V_37 . V_28 ,
V_31 -> V_67 . V_28 ) ;
F_30 ( L_3 ,
V_31 -> V_35 . V_29 , V_31 -> V_36 . V_29 , V_31 -> V_37 . V_29 ,
V_31 -> V_67 . V_29 ) ;
#ifdef F_31
F_32 ( V_68 L_4 ,
F_27 ( V_31 ) ,
F_33 ( F_34 () ) ) ;
#endif
return 0 ;
}
static inline void F_35 ( T_2 V_69 )
{
if ( F_3 () ) {
#if 1
if ( V_69 )
F_36 ( V_70 ) ;
else
F_37 ( V_70 ) ;
#else
if ( V_69 )
F_37 ( V_70 ) ;
else
F_36 ( V_70 ) ;
#endif
}
}
static int F_38 ( struct V_39 * V_40 )
{
struct V_2 * V_3 = (struct V_2 * ) V_40 ;
struct V_30 * V_31 = & V_40 -> V_31 ;
unsigned long V_71 ;
F_30 ( L_5 ) ;
if ( V_31 -> V_33 == 16 )
V_3 -> V_43 . V_47 . V_48 = V_49 ;
else if ( ! V_3 -> V_72 )
V_3 -> V_43 . V_47 . V_48 = V_53 ;
else {
V_3 -> V_43 . V_47 . V_48 = V_52 ;
}
V_3 -> V_43 . V_47 . V_73 = V_31 -> V_62 *
V_31 -> V_33 / 8 ;
V_3 -> V_42 = V_31 -> V_33 == 8 ? 256 : 16 ;
V_71 = V_3 -> V_42 * sizeof( V_74 ) ;
F_30 ( L_6 , ( V_75 ) V_71 ) ;
V_3 -> V_44 = ( V_74 * ) ( V_3 -> V_76 + V_77 - V_71 ) ;
V_3 -> V_78 = V_3 -> V_79 + V_77 - V_71 ;
F_35 ( V_3 -> V_43 . V_47 . V_48 == V_49 ) ;
F_39 ( V_31 , V_3 ) ;
return 0 ;
}
static int F_40 ( int V_80 , struct V_39 * V_40 )
{
struct V_2 * V_3 = (struct V_2 * ) V_40 ;
int V_81 ;
F_30 ( L_7 , V_80 ) ;
switch ( V_80 ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( V_3 -> V_43 . V_47 . V_48 == V_53 ||
V_3 -> V_43 . V_47 . V_48 == V_52 )
for ( V_81 = 0 ; V_81 < V_3 -> V_42 ; V_81 ++ )
F_25 ( V_81 , 0 , 0 , 0 , 0 , V_40 ) ;
F_19 ( V_3 , V_23 ) ;
break;
case V_86 :
if ( V_3 -> V_43 . V_47 . V_48 == V_53 ||
V_3 -> V_43 . V_47 . V_48 == V_52 )
F_41 ( & V_3 -> V_43 . V_87 , V_40 ) ;
F_19 ( V_3 , V_21 ) ;
}
return 0 ;
}
static int F_42 ( struct V_39 * V_40 ,
struct V_88 * V_89 )
{
struct V_2 * V_3 = (struct V_2 * ) V_40 ;
unsigned long V_90 , V_91 , V_92 = V_89 -> V_93 << V_94 ;
if ( V_92 < V_40 -> V_47 . V_95 ) {
V_89 -> V_93 += 1 ;
return F_43 ( V_3 -> V_96 , V_89 , V_3 -> V_76 ,
V_3 -> V_79 , V_3 -> V_97 ) ;
}
V_90 = V_40 -> V_47 . V_98 ;
V_91 = F_44 ( ( V_90 & ~ V_99 ) + V_40 -> V_47 . V_100 ) ;
if ( ( V_89 -> V_101 - V_89 -> V_102 + V_92 ) > V_91 )
return - V_66 ;
V_92 += V_90 & V_99 ;
V_89 -> V_93 = V_92 >> V_94 ;
V_89 -> V_103 |= V_104 ;
V_89 -> V_105 = F_45 ( V_89 -> V_105 ) ;
return F_46 ( V_89 , V_89 -> V_102 , V_92 >> V_94 ,
V_89 -> V_101 - V_89 -> V_102 ,
V_89 -> V_105 ) ;
}
static inline unsigned int F_47 ( unsigned int V_54 , unsigned int V_106 )
{
unsigned int V_107 = V_106 / 100 ;
V_107 *= V_54 ;
V_107 /= 10000000 ;
return V_107 + 1 ;
}
static int F_39 ( struct V_30 * V_31 , struct V_2 * V_3 )
{
struct V_108 V_109 ;
T_2 V_110 , V_58 , V_107 ;
V_75 V_19 ;
F_30 ( L_8 ) ;
F_30 ( L_9 ,
V_31 -> V_56 , V_31 -> V_111 ,
V_31 -> V_112 , V_31 -> V_113 ) ;
F_30 ( L_10 ,
V_31 -> V_58 , V_31 -> V_114 ,
V_31 -> V_115 , V_31 -> V_116 ) ;
#if V_117
if ( V_31 -> V_56 < 16 || V_31 -> V_56 > 1024 )
F_32 ( V_118 L_11 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_56 ) ;
if ( V_31 -> V_111 < 1 || V_31 -> V_111 > 64 )
F_32 ( V_118 L_12 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_111 ) ;
if ( V_31 -> V_112 < 1 || V_31 -> V_112 > 255 )
F_32 ( V_118 L_13 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_112 ) ;
if ( V_31 -> V_113 < 1 || V_31 -> V_113 > 255 )
F_32 ( V_118 L_14 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_113 ) ;
if ( V_31 -> V_58 < 1 || V_31 -> V_58 > 1024 )
F_32 ( V_118 L_15 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_58 ) ;
if ( V_31 -> V_114 < 1 || V_31 -> V_114 > 64 )
F_32 ( V_118 L_16 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_114 ) ;
if ( V_31 -> V_115 < 0 || V_31 -> V_115 > 255 )
F_32 ( V_118 L_17 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_115 ) ;
if ( V_31 -> V_116 < 0 || V_31 -> V_116 > 255 )
F_32 ( V_118 L_18 ,
V_3 -> V_43 . V_47 . V_119 , V_31 -> V_116 ) ;
#endif
V_109 . V_120 = V_3 -> V_120 |
V_121 | V_122 | V_123 |
V_124 | V_125 | F_48 ( 0 ) ;
V_109 . V_126 =
F_49 ( V_31 -> V_56 ) +
F_50 ( V_31 -> V_111 ) +
F_51 ( V_31 -> V_112 ) +
F_52 ( V_31 -> V_113 ) ;
V_58 = V_31 -> V_58 ;
if ( V_3 -> V_120 & V_127 )
V_58 /= 2 ;
V_109 . V_128 =
F_53 ( V_58 ) +
F_54 ( V_31 -> V_114 ) +
F_55 ( V_31 -> V_115 ) +
F_56 ( V_31 -> V_116 ) ;
V_107 = F_47 ( V_31 -> V_54 , F_33 ( 0 ) ) ;
V_109 . V_129 = F_57 ( V_107 ) | V_3 -> V_129 |
( V_31 -> V_130 & V_131 ? V_132 : V_133 ) |
( V_31 -> V_130 & V_134 ? V_135 : V_136 ) ;
F_30 ( L_19 , V_109 . V_120 ) ;
F_30 ( L_20 , V_109 . V_126 ) ;
F_30 ( L_21 , V_109 . V_128 ) ;
F_30 ( L_22 , V_109 . V_129 ) ;
V_110 = V_31 -> V_33 ;
V_110 = V_110 * V_31 -> V_56 * V_31 -> V_58 / 16 ;
F_20 ( V_19 ) ;
V_3 -> V_137 = V_3 -> V_78 ;
V_3 -> V_138 = V_3 -> V_139 + V_110 ;
V_3 -> V_140 = V_109 . V_120 ;
V_3 -> V_141 = V_109 . V_126 ;
V_3 -> V_142 = V_109 . V_128 ;
V_3 -> V_143 = V_109 . V_129 ;
F_22 ( V_19 ) ;
if ( ( V_144 != V_3 -> V_140 ) || ( V_145 != V_3 -> V_141 ) ||
( V_146 != V_3 -> V_142 ) || ( V_147 != V_3 -> V_143 ) ||
( V_148 != V_3 -> V_137 ) || ( V_149 != V_3 -> V_138 ) )
F_19 ( V_3 , V_22 ) ;
return 0 ;
}
static inline void F_58 ( struct V_2 * V_3 , int V_150 )
{
F_30 ( L_23 , V_150 ? L_24 : L_25 ) ;
if ( V_151 )
V_151 ( V_150 ) ;
}
static inline void F_59 ( struct V_2 * V_3 , int V_150 )
{
F_30 ( L_26 , V_150 ? L_24 : L_25 ) ;
if ( V_152 )
V_152 ( V_150 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
T_2 V_153 = 0 ;
if ( ( V_3 -> V_140 & V_154 ) == V_155 &&
( V_3 -> V_140 & ( V_127 | V_156 ) ) != 0 ) {
V_153 = V_157 | V_158 | V_159 | V_160 ;
if ( V_3 -> V_43 . V_31 . V_33 > 8 ||
( V_3 -> V_140 & ( V_127 | V_156 ) ) == V_127 )
V_153 |= V_161 | V_162 | V_163 | V_164 ;
}
if ( V_153 ) {
V_165 |= V_153 ;
V_166 |= V_153 ;
}
}
static void F_61 ( struct V_2 * V_3 )
{
F_30 ( L_27 ) ;
V_3 -> V_44 [ 0 ] &= 0xcfff ;
V_3 -> V_44 [ 0 ] |= F_24 ( & V_3 -> V_43 . V_31 ) ;
V_147 = V_3 -> V_143 ;
V_146 = V_3 -> V_142 ;
V_145 = V_3 -> V_141 ;
V_144 = V_3 -> V_140 & ~ V_121 ;
V_148 = V_3 -> V_137 ;
V_149 = V_3 -> V_138 ;
V_144 |= V_121 ;
if ( F_18 () ) {
V_165 |= V_167 ;
V_168 |= V_167 ;
}
F_30 ( L_28 , V_148 ) ;
F_30 ( L_29 , V_149 ) ;
F_30 ( L_30 , V_144 ) ;
F_30 ( L_31 , V_145 ) ;
F_30 ( L_32 , V_146 ) ;
F_30 ( L_33 , V_147 ) ;
}
static void F_62 ( struct V_2 * V_3 )
{
F_63 ( V_169 , V_170 ) ;
F_30 ( L_34 ) ;
if ( F_18 () ) {
V_171 |= V_167 ;
}
F_64 ( V_172 ) ;
F_65 ( & V_3 -> V_173 , & V_169 ) ;
V_174 = 0xffffffff ;
V_144 &= ~ V_122 ;
V_144 &= ~ V_121 ;
F_66 ( 20 * V_175 / 1000 ) ;
F_67 ( & V_3 -> V_173 , & V_169 ) ;
}
static T_4 F_68 ( int V_176 , void * V_177 )
{
struct V_2 * V_3 = V_177 ;
unsigned int V_178 = V_174 ;
if ( V_178 & V_179 ) {
V_144 |= V_122 ;
F_69 ( & V_3 -> V_173 ) ;
}
V_174 = V_178 ;
return V_180 ;
}
static void F_70 ( struct V_2 * V_3 , T_2 V_18 )
{
T_2 V_181 ;
F_71 ( & V_3 -> V_182 ) ;
V_181 = V_3 -> V_18 ;
if ( V_181 == V_183 && V_18 == V_22 )
V_18 = V_21 ;
switch ( V_18 ) {
case V_184 :
if ( V_181 != V_23 && V_181 != V_185 ) {
V_3 -> V_18 = V_18 ;
F_62 ( V_3 ) ;
}
break;
case V_185 :
case V_23 :
if ( V_181 != V_23 ) {
V_3 -> V_18 = V_18 ;
F_58 ( V_3 , 0 ) ;
if ( V_181 != V_184 )
F_62 ( V_3 ) ;
F_59 ( V_3 , 0 ) ;
}
break;
case V_186 :
if ( V_181 == V_184 ) {
V_3 -> V_18 = V_21 ;
F_61 ( V_3 ) ;
}
break;
case V_22 :
if ( V_181 == V_21 ) {
F_62 ( V_3 ) ;
F_60 ( V_3 ) ;
F_61 ( V_3 ) ;
}
break;
case V_187 :
if ( V_181 != V_185 )
break;
case V_21 :
if ( V_181 != V_21 ) {
V_3 -> V_18 = V_21 ;
F_60 ( V_3 ) ;
F_59 ( V_3 , 1 ) ;
F_61 ( V_3 ) ;
F_58 ( V_3 , 1 ) ;
}
break;
}
F_72 ( & V_3 -> V_182 ) ;
}
static void F_73 ( struct V_188 * V_189 )
{
struct V_2 * V_3 = F_74 ( V_189 , struct V_2 , V_24 ) ;
T_2 V_18 = F_75 ( & V_3 -> V_20 , - 1 ) ;
F_70 ( V_3 , V_18 ) ;
}
static unsigned int F_76 ( struct V_2 * V_3 )
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
return F_27 ( & V_3 -> V_43 . V_31 ) ;
#endif
}
static int
F_77 ( struct V_190 * V_191 , unsigned long V_41 ,
void * V_192 )
{
struct V_2 * V_3 = F_78 ( V_191 , V_193 ) ;
struct V_194 * V_195 = V_192 ;
T_2 V_107 ;
switch ( V_41 ) {
case V_196 :
F_70 ( V_3 , V_184 ) ;
break;
case V_197 :
V_107 = F_47 ( V_3 -> V_43 . V_31 . V_54 , V_195 -> V_198 ) ;
V_3 -> V_143 = ( V_3 -> V_143 & ~ 0xff ) | F_57 ( V_107 ) ;
F_70 ( V_3 , V_186 ) ;
break;
}
return 0 ;
}
static int
F_79 ( struct V_190 * V_191 , unsigned long V_41 ,
void * V_192 )
{
struct V_2 * V_3 = F_78 ( V_191 , V_199 ) ;
struct V_200 * V_201 = V_192 ;
switch ( V_41 ) {
case V_202 :
case V_203 :
F_32 ( V_68 L_35
L_36 , F_76 ( V_3 ) ,
V_201 -> F_29 ) ;
break;
case V_204 :
do {} while( 0 );
break;
}
return 0 ;
}
static int F_80 ( struct V_205 * V_96 , T_5 V_18 )
{
struct V_2 * V_3 = F_81 ( V_96 ) ;
F_70 ( V_3 , V_185 ) ;
return 0 ;
}
static int F_82 ( struct V_205 * V_96 )
{
struct V_2 * V_3 = F_81 ( V_96 ) ;
F_70 ( V_3 , V_187 ) ;
return 0 ;
}
static int T_1 F_83 ( struct V_2 * V_3 )
{
V_3 -> V_97 = F_44 ( V_3 -> V_43 . V_47 . V_95 + V_77 ) ;
V_3 -> V_76 = F_84 ( V_3 -> V_96 , V_3 -> V_97 ,
& V_3 -> V_79 , V_206 ) ;
if ( V_3 -> V_76 ) {
V_3 -> V_43 . V_207 = V_3 -> V_76 + V_77 ;
V_3 -> V_139 = V_3 -> V_79 + V_77 ;
V_3 -> V_43 . V_47 . V_208 = V_3 -> V_139 ;
}
return V_3 -> V_76 ? 0 : - V_209 ;
}
static struct V_2 * T_1 F_85 ( struct V_210 * V_96 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
V_3 = F_86 ( sizeof( struct V_2 ) + sizeof( T_3 ) * 16 ,
V_206 ) ;
if ( ! V_3 )
return NULL ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_3 -> V_96 = V_96 ;
strcpy ( V_3 -> V_43 . V_47 . V_119 , V_211 ) ;
V_3 -> V_43 . V_47 . type = V_212 ;
V_3 -> V_43 . V_47 . V_213 = 0 ;
V_3 -> V_43 . V_47 . V_214 = 0 ;
V_3 -> V_43 . V_47 . V_215 = 0 ;
V_3 -> V_43 . V_47 . V_216 = 0 ;
V_3 -> V_43 . V_47 . V_217 = V_218 ;
V_3 -> V_43 . V_31 . V_219 = 0 ;
V_3 -> V_43 . V_31 . V_220 = V_221 ;
V_3 -> V_43 . V_31 . V_222 = - 1 ;
V_3 -> V_43 . V_31 . V_223 = - 1 ;
V_3 -> V_43 . V_31 . V_224 = 0 ;
V_3 -> V_43 . V_31 . V_225 = V_226 ;
V_3 -> V_43 . V_227 = & V_228 ;
V_3 -> V_43 . V_19 = V_229 ;
V_3 -> V_43 . V_230 = V_230 ;
V_3 -> V_43 . V_51 = ( V_3 + 1 ) ;
V_3 -> V_9 [ V_64 ] = & V_231 ;
V_3 -> V_9 [ V_65 ] = & V_232 ;
V_3 -> V_9 [ V_10 ] = & V_233 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_129 & ( V_136 | V_133 | 0xff ) ||
V_4 -> V_54 == 0 )
F_87 ( L_37
L_38 ) ;
V_3 -> V_60 = V_4 -> V_56 ;
V_3 -> V_43 . V_31 . V_56 = V_4 -> V_56 ;
V_3 -> V_43 . V_31 . V_62 = V_4 -> V_56 ;
V_3 -> V_61 = V_4 -> V_58 ;
V_3 -> V_43 . V_31 . V_58 = V_4 -> V_58 ;
V_3 -> V_43 . V_31 . V_63 = V_4 -> V_58 ;
V_3 -> V_234 = V_4 -> V_235 ;
V_3 -> V_43 . V_31 . V_33 = V_4 -> V_235 ;
V_3 -> V_43 . V_31 . V_54 = V_4 -> V_54 ;
V_3 -> V_43 . V_31 . V_111 = V_4 -> V_111 ;
V_3 -> V_43 . V_31 . V_112 = V_4 -> V_112 ;
V_3 -> V_43 . V_31 . V_113 = V_4 -> V_113 ;
V_3 -> V_43 . V_31 . V_114 = V_4 -> V_114 ;
V_3 -> V_43 . V_31 . V_115 = V_4 -> V_115 ;
V_3 -> V_43 . V_31 . V_116 = V_4 -> V_116 ;
V_3 -> V_43 . V_31 . V_130 = V_4 -> V_130 ;
V_3 -> V_43 . V_31 . V_46 = V_4 -> V_236 ;
V_3 -> V_45 = V_4 -> V_45 ;
V_3 -> V_72 = V_4 -> V_72 ;
V_3 -> V_120 = V_4 -> V_120 ;
V_3 -> V_129 = V_4 -> V_129 ;
V_3 -> V_18 = V_183 ;
V_3 -> V_20 = ( V_237 ) - 1 ;
V_3 -> V_43 . V_47 . V_95 = V_3 -> V_60 * V_3 -> V_61 *
V_3 -> V_234 / 8 ;
F_88 ( & V_3 -> V_173 ) ;
F_89 ( & V_3 -> V_24 , F_73 ) ;
F_90 ( & V_3 -> V_182 ) ;
return V_3 ;
}
static int T_6 F_91 ( struct V_205 * V_238 )
{
struct V_2 * V_3 ;
int V_32 , V_176 ;
V_176 = F_92 ( V_238 , 0 ) ;
if ( V_176 < 0 )
return - V_66 ;
if ( ! F_93 ( 0xb0100000 , 0x10000 , L_39 ) )
return - V_239 ;
V_3 = F_85 ( & V_238 -> V_96 ) ;
V_32 = - V_209 ;
if ( ! V_3 )
goto V_240;
V_32 = F_83 ( V_3 ) ;
if ( V_32 )
goto V_240;
V_32 = F_94 ( V_176 , F_68 , 0 , L_39 , V_3 ) ;
if ( V_32 ) {
F_32 ( V_118 L_40 , V_32 ) ;
goto V_240;
}
#ifdef F_4
if ( F_3 () )
F_37 ( V_241 ) ;
#endif
F_28 ( & V_3 -> V_43 . V_31 , & V_3 -> V_43 ) ;
F_95 ( V_238 , V_3 ) ;
V_32 = F_96 ( & V_3 -> V_43 ) ;
if ( V_32 < 0 )
goto V_242;
#ifdef F_31
V_3 -> V_193 . V_243 = F_77 ;
V_3 -> V_199 . V_243 = F_79 ;
F_97 ( & V_3 -> V_193 , V_244 ) ;
F_97 ( & V_3 -> V_199 , V_245 ) ;
#endif
return 0 ;
V_242:
F_98 ( V_176 , V_3 ) ;
V_240:
F_95 ( V_238 , NULL ) ;
F_99 ( V_3 ) ;
F_100 ( 0xb0100000 , 0x10000 ) ;
return V_32 ;
}
int T_1 F_101 ( void )
{
if ( F_102 ( L_41 , NULL ) )
return - V_246 ;
return F_103 ( & V_247 ) ;
}
int T_1 F_104 ( char * V_248 )
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
