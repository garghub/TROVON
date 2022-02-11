static int F_1 ( unsigned int V_1 )
{
int V_2 = 0 ;
switch ( V_1 & V_3 ) {
case V_4 :
V_2 = 1 ;
break;
case V_5 :
V_2 = 2 ;
break;
case V_6 :
V_2 = 4 ;
break;
case V_7 :
V_2 = 8 ;
break;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_2 = 16 ;
break;
case V_16 :
case V_17 :
V_2 = 32 ;
break;
}
return V_2 ;
}
static int F_2 ( struct V_18 * V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; ++ V_19 ) {
if ( V_18 == V_21 [ V_19 ] )
return V_19 ;
}
F_3 ( L_1 ) ;
return - 1 ;
}
static int F_4 ( struct V_22 * V_23 , int V_24 ,
int V_25 , int V_26 )
{
T_1 V_27 , V_1 , V_28 , V_29 = 0 ;
int V_30 , V_31 ;
V_27 = V_32 -> V_33 [ V_24 ] . V_27 ;
V_1 = V_32 -> V_33 [ V_24 ] . V_1 ;
V_27 &= ( V_34 | V_35 ) ;
V_1 &= ~ ( V_36 | V_37 ) ;
V_30 = V_38 -> V_39 [ V_24 ] . V_40 ;
V_31 = V_38 -> V_39 [ V_24 ] . V_41 ;
if ( ( V_25 + V_38 -> V_39 [ V_24 ] . V_40 ) > V_42 -> V_43 ) {
V_30 = V_42 -> V_43 - V_25 ;
}
if ( ( V_26 + V_38 -> V_39 [ V_24 ] . V_41 ) > V_42 -> V_44 ) {
V_31 = V_42 -> V_44 - V_26 ;
}
if ( V_25 < 0 ) {
V_30 = V_38 -> V_39 [ V_24 ] . V_40 + V_25 ;
V_29 += ( ( ( 0 - V_25 ) * F_1 ( V_32 -> V_33 [ V_24 ] . V_1 ) ) / 8 ) ;
V_25 = 0 ;
}
if ( V_26 < 0 ) {
V_31 = V_38 -> V_39 [ V_24 ] . V_41 + V_26 ;
V_26 = 0 ;
}
V_38 -> V_39 [ V_24 ] . V_25 = V_25 ;
V_38 -> V_39 [ V_24 ] . V_26 = V_26 ;
V_30 -= 1 ;
V_31 -= 1 ;
V_27 |= ( V_25 << 21 ) ;
V_27 |= ( V_26 << 10 ) ;
V_1 |= ( V_30 << 11 ) ;
V_1 |= ( V_31 << 0 ) ;
V_28 = V_32 -> V_28 & ( 1 << V_24 ) ;
F_5 () ;
V_32 -> V_28 &= ~ ( 1 << V_24 ) ;
V_32 -> V_33 [ V_24 ] . V_27 = V_27 ;
V_32 -> V_33 [ V_24 ] . V_1 = V_1 ;
V_32 -> V_33 [ V_24 ] . V_45 =
V_32 -> V_33 [ V_24 ] . V_46 = V_23 -> V_47 ;
V_32 -> V_33 [ V_24 ] . V_48 = 0 ;
V_32 -> V_28 |= V_28 ;
F_5 () ;
return 0 ;
}
static void F_6 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
T_1 V_28 ;
V_28 = V_32 -> V_28 ;
V_32 -> V_28 = 0 ;
F_5 () ;
if ( V_32 -> V_53 & V_54 ) {
V_32 -> V_55 = V_56 ;
while ( ( V_32 -> V_55 & V_56 ) == 0 ) {
F_5 () ;
}
V_32 -> V_53 &= ~ V_54 ;
do {
V_32 -> V_55 = V_32 -> V_55 ;
F_5 () ;
} while ( ( V_32 -> V_55 & V_57 ) == 0 );
if ( V_52 -> V_58 )
V_52 -> V_58 () ;
}
if ( V_50 == NULL )
return;
V_42 = V_50 ;
F_3 ( L_2 , V_42 -> V_59 , V_42 -> V_43 , V_42 -> V_44 ) ;
if ( ! ( V_42 -> V_60 & V_61 ) )
{
T_1 V_62 ;
F_7 ( V_42 -> V_63 , V_64 ) ;
V_62 = F_8 ( V_65 ) & ~ 0x0000001f ;
V_62 |= V_42 -> V_66 ;
F_7 ( V_62 , V_65 ) ;
}
V_32 -> V_53 = V_42 -> V_67 ;
V_32 -> V_68 = V_42 -> V_69 ;
V_32 -> V_70 = V_42 -> V_71 ;
V_32 -> V_72 = V_42 -> V_60 ;
V_32 -> V_73 = V_42 -> V_74 ;
V_32 -> V_75 = V_42 -> V_76 ;
V_32 -> V_77 = V_42 -> V_78 ;
V_32 -> V_79 = V_42 -> V_80 ;
F_5 () ;
#if 0
au1200_setlocation(fbdev, 0, win->w[0].xpos, win->w[0].ypos);
au1200_setlocation(fbdev, 1, win->w[1].xpos, win->w[1].ypos);
au1200_setlocation(fbdev, 2, win->w[2].xpos, win->w[2].ypos);
au1200_setlocation(fbdev, 3, win->w[3].xpos, win->w[3].ypos);
#endif
V_32 -> V_28 = V_28 ;
V_32 -> V_53 |= V_54 ;
F_5 () ;
if ( V_52 -> V_81 )
V_52 -> V_81 () ;
V_32 -> V_82 = 0 ;
V_32 -> V_55 = ~ 0 ;
V_32 -> V_83 = V_38 -> V_84 ;
V_32 -> V_85 = V_38 -> V_86 ;
V_32 -> V_87 = V_38 -> V_88 ;
V_32 -> V_89 . V_90 = 0 ;
V_32 -> V_89 . V_91 = 0 ;
V_32 -> V_89 . V_92 = 0 ;
V_32 -> V_89 . V_93 = 0 ;
V_32 -> V_89 . V_94 = 0 ;
V_32 -> V_89 . V_95 = 0 ;
#if 0
#define F_9 ( T_2 ) printk("%25s: %08X\n", #X, X)
D(lcd->screen);
D(lcd->horztiming);
D(lcd->verttiming);
D(lcd->clkcontrol);
D(lcd->pwmdiv);
D(lcd->pwmhi);
D(lcd->outmask);
D(lcd->fifoctrl);
D(lcd->window[0].winctrl0);
D(lcd->window[0].winctrl1);
D(lcd->window[0].winctrl2);
D(lcd->window[0].winbuf0);
D(lcd->window[0].winbuf1);
D(lcd->window[0].winbufctrl);
D(lcd->window[1].winctrl0);
D(lcd->window[1].winctrl1);
D(lcd->window[1].winctrl2);
D(lcd->window[1].winbuf0);
D(lcd->window[1].winbuf1);
D(lcd->window[1].winbufctrl);
D(lcd->window[2].winctrl0);
D(lcd->window[2].winctrl1);
D(lcd->window[2].winctrl2);
D(lcd->window[2].winbuf0);
D(lcd->window[2].winbuf1);
D(lcd->window[2].winbufctrl);
D(lcd->window[3].winctrl0);
D(lcd->window[3].winctrl1);
D(lcd->window[3].winctrl2);
D(lcd->window[3].winbuf0);
D(lcd->window[3].winbuf1);
D(lcd->window[3].winbufctrl);
D(lcd->winenable);
D(lcd->intenable);
D(lcd->intstatus);
D(lcd->backcolor);
D(lcd->winenable);
D(lcd->colorkey);
D(lcd->colorkeymsk);
D(lcd->hwc.cursorctrl);
D(lcd->hwc.cursorpos);
D(lcd->hwc.cursorcolor0);
D(lcd->hwc.cursorcolor1);
D(lcd->hwc.cursorcolor2);
D(lcd->hwc.cursorcolor3);
#endif
}
static void F_10 ( struct V_22 * V_23 )
{
int V_24 = V_23 -> V_24 ;
V_32 -> V_33 [ V_24 ] . V_1 = ( 0
| F_11 ( V_24 )
| V_38 -> V_39 [ V_24 ] . V_96
) ;
F_4 ( V_23 , V_24 , V_38 -> V_39 [ V_24 ] . V_25 , V_38 -> V_39 [ V_24 ] . V_26 ) ;
V_32 -> V_33 [ V_24 ] . V_97 = ( 0
| V_98
| V_99
| F_12 ( V_23 -> V_18 -> V_100 . V_101 )
| V_102
| V_103
) ;
V_32 -> V_28 |= V_38 -> V_39 [ V_24 ] . V_104 ;
F_5 () ;
}
static void F_13 ( struct V_18 * V_105 )
{
if ( F_14 ( V_42 ) ) {
if ( V_105 -> V_106 . V_107 <= 8 ) {
V_105 -> V_100 . V_108 = V_109 ;
V_105 -> V_100 . V_101 = V_105 -> V_106 . V_110 /
( 8 / V_105 -> V_106 . V_107 ) ;
} else {
V_105 -> V_100 . V_108 = V_111 ;
V_105 -> V_100 . V_101 = V_105 -> V_106 . V_110 * ( V_105 -> V_106 . V_107 / 8 ) ;
}
} else {
V_105 -> V_100 . V_108 = V_112 ;
V_105 -> V_100 . V_101 = V_105 -> V_106 . V_110 / 8 ;
}
V_105 -> V_113 = V_105 -> V_100 . V_101 * V_105 -> V_106 . V_114 ;
F_15 ( L_3 , V_105 -> V_100 . V_101 ) ;
F_15 ( L_4 , V_105 -> V_106 . V_107 ) ;
}
static int F_16 ( struct V_115 * V_106 ,
struct V_18 * V_105 )
{
struct V_22 * V_23 = V_105 -> V_116 ;
T_3 V_117 ;
int V_113 , V_24 ;
V_24 = V_23 -> V_24 ;
V_106 -> V_40 = V_38 -> V_39 [ V_24 ] . V_40 ;
V_106 -> V_41 = V_38 -> V_39 [ V_24 ] . V_41 ;
V_106 -> V_110 = V_106 -> V_40 ;
V_106 -> V_114 = V_106 -> V_41 ;
V_106 -> V_107 = F_1 ( V_38 -> V_39 [ V_24 ] . V_96 ) ;
V_113 = V_106 -> V_110 * V_106 -> V_114 ;
if ( V_106 -> V_107 > 8 ) V_113 *= ( V_106 -> V_107 / 8 ) ;
else V_113 /= ( 8 / V_106 -> V_107 ) ;
if ( V_23 -> V_118 < V_113 )
return - V_119 ;
V_117 = F_17 ( ( T_3 ) ( F_18 ( V_106 -> V_117 ) * 1000 ) , V_105 -> V_120 . V_121 ) ;
V_117 = F_19 ( V_117 , V_105 -> V_120 . V_122 , ( T_3 ) V_123 / 2 ) ;
if ( V_123 % V_117 ) {
int V_124 = V_123 % V_117 ;
V_117 -= V_124 ;
}
V_106 -> V_117 = F_20 ( V_117 / 1000 ) ;
#if 0
if (!panel_is_active(panel)) {
int pcd = AU1200_LCD_MAX_CLK / (pixclock * 2) - 1;
if (!panel_is_color(panel)
&& (panel->control_base & LCD_CONTROL_MPI) && (pcd < 3)) {
var->pixclock = KHZ2PICOS(6000);
} else if (!pcd) {
var->pixclock = KHZ2PICOS(12000);
}
}
#endif
switch ( V_106 -> V_107 ) {
case 16 :
{
int V_125 ;
V_125 = ( V_38 -> V_39 [ 0 ] . V_96 & V_3 ) >> 25 ;
V_106 -> V_126 = V_127 [ V_125 ] [ 0 ] ;
V_106 -> V_128 = V_127 [ V_125 ] [ 1 ] ;
V_106 -> V_129 = V_127 [ V_125 ] [ 2 ] ;
V_106 -> V_130 = V_127 [ V_125 ] [ 3 ] ;
break;
}
case 32 :
{
int V_125 ;
V_125 = ( V_38 -> V_39 [ 0 ] . V_96 & V_3 ) >> 25 ;
V_106 -> V_126 = V_127 [ V_125 ] [ 0 ] ;
V_106 -> V_128 = V_127 [ V_125 ] [ 1 ] ;
V_106 -> V_129 = V_127 [ V_125 ] [ 2 ] ;
V_106 -> V_130 = V_127 [ V_125 ] [ 3 ] ;
break;
}
default:
F_15 ( L_5 , V_106 -> V_107 ) ;
return - V_119 ;
}
return 0 ;
}
static int F_21 ( struct V_18 * V_105 )
{
struct V_22 * V_23 = V_105 -> V_116 ;
F_13 ( V_105 ) ;
F_10 ( V_23 ) ;
return 0 ;
}
static int F_22 ( unsigned V_131 , unsigned V_126 , unsigned V_128 ,
unsigned V_129 , unsigned V_130 , struct V_18 * V_105 )
{
volatile T_3 * V_132 = V_32 -> V_132 ;
T_3 V_133 ;
if ( V_131 > ( V_134 - 1 ) )
return - V_119 ;
if ( V_105 -> V_106 . V_135 ) {
V_126 = V_128 = V_129 =
( 19595 * V_126 + 38470 * V_128 + 7471 * V_129 ) >> 16 ;
}
if ( V_105 -> V_100 . V_108 == V_111 ) {
if ( V_131 > 16 )
return - V_119 ;
V_132 = ( T_3 * ) V_105 -> V_136 ;
V_126 >>= ( 16 - V_105 -> V_106 . V_126 . V_137 ) ;
V_128 >>= ( 16 - V_105 -> V_106 . V_128 . V_137 ) ;
V_129 >>= ( 16 - V_105 -> V_106 . V_129 . V_137 ) ;
V_133 = ( V_126 << V_105 -> V_106 . V_126 . V_138 ) |
( V_128 << V_105 -> V_106 . V_128 . V_138 ) |
( V_129 << V_105 -> V_106 . V_129 . V_138 ) ;
V_133 &= 0xFFFF ;
} else if ( 1 ) {
V_133 = ( V_126 & 0xF800 ) | ( ( V_128 >> 5 ) &
0x07E0 ) | ( ( V_129 >> 11 ) & 0x001F ) ;
V_133 &= 0xFFFF ;
} else if ( 0 ) {
V_133 = 0x1234 ;
V_133 &= 0xFFF ;
} else {
V_133 = ( V_128 >> 12 ) & 0x000F ;
V_133 &= 0xF ;
}
V_132 [ V_131 ] = V_133 ;
return 0 ;
}
static int F_23 ( int V_139 , struct V_18 * V_105 )
{
struct V_22 * V_23 = V_105 -> V_116 ;
if ( V_140 )
return 0 ;
switch ( V_139 ) {
case V_141 :
case V_142 :
F_6 ( V_42 , V_23 -> V_52 ) ;
break;
case V_143 :
case V_144 :
case V_145 :
F_6 ( NULL , V_23 -> V_52 ) ;
break;
default:
break;
}
return ( V_139 == V_142 ) ? - V_119 : 0 ;
}
static int F_24 ( struct V_18 * V_146 , struct V_147 * V_148 )
{
unsigned int V_149 ;
unsigned long V_150 = 0 , V_151 ;
struct V_22 * V_23 = V_146 -> V_116 ;
if ( V_148 -> V_152 > ( ~ 0UL >> V_153 ) ) {
return - V_119 ;
}
V_150 = V_23 -> V_47 & V_154 ;
V_149 = F_25 ( ( V_150 & ~ V_154 ) + V_23 -> V_118 ) ;
V_151 = V_148 -> V_152 << V_153 ;
if ( ( V_148 -> V_155 - V_148 -> V_156 + V_151 ) > V_149 ) {
return - V_119 ;
}
V_151 += V_150 ;
V_148 -> V_152 = V_151 >> V_153 ;
V_148 -> V_157 = F_26 ( V_148 -> V_157 ) ;
F_27 ( V_148 -> V_157 ) |= V_158 ;
V_148 -> V_159 |= V_160 ;
return F_28 ( V_148 , V_148 -> V_156 , V_151 >> V_153 ,
V_148 -> V_155 - V_148 -> V_156 ,
V_148 -> V_157 ) ;
return 0 ;
}
static void F_29 ( T_4 V_161 , struct V_162 * V_163 )
{
unsigned int V_164 , V_165 ;
if ( V_163 -> V_166 & V_167 )
V_32 -> V_83 = V_163 -> V_83 ;
if ( V_163 -> V_166 & V_168 ) {
if ( V_163 -> V_169 < 30 ) {
V_163 -> V_169 = 30 ;
}
V_165 = ( V_32 -> V_73 & 0x3FFFF ) + 1 ;
V_164 = ( V_32 -> V_75 >> 16 ) + 1 ;
V_164 = ( ( ( V_163 -> V_169 & 0xFF ) + 1 ) * V_165 >> 8 ) ;
V_32 -> V_75 &= 0xFFFF ;
V_32 -> V_75 |= ( V_164 << 16 ) ;
}
if ( V_163 -> V_166 & V_170 )
V_32 -> V_85 = V_163 -> V_85 ;
if ( V_163 -> V_166 & V_171 )
V_32 -> V_87 = V_163 -> V_172 ;
F_5 () ;
}
static void F_30 ( T_4 V_161 , struct V_162 * V_163 )
{
unsigned int V_164 , V_165 ;
V_163 -> V_173 = ( ( V_32 -> V_53 & V_174 ) >> 19 ) + 1 ;
V_163 -> V_175 = ( ( V_32 -> V_53 & V_176 ) >> 8 ) + 1 ;
V_163 -> V_83 = V_32 -> V_83 ;
V_163 -> V_85 = V_32 -> V_85 ;
V_163 -> V_172 = V_32 -> V_87 ;
V_164 = ( V_32 -> V_75 >> 16 ) + 1 ;
V_165 = ( V_32 -> V_73 & 0x3FFFF ) + 1 ;
V_163 -> V_169 = ( ( V_164 << 8 ) / V_165 ) - 1 ;
F_5 () ;
}
static void F_31 ( unsigned int V_24 ,
struct V_177 * V_163 )
{
unsigned int V_178 , V_179 ;
if ( V_163 -> V_166 & V_180 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_27 & ~ ( V_181 |
V_182 ) ;
V_178 |= ( ( V_163 -> V_25 << 21 ) & V_181 ) ;
V_178 |= ( ( V_163 -> V_26 << 10 ) & V_182 ) ;
V_32 -> V_33 [ V_24 ] . V_27 = V_178 ;
}
if ( V_163 -> V_166 & V_183 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_27 & ~ ( V_34 ) ;
V_178 |= ( ( V_163 -> V_184 << 2 ) & V_34 ) ;
V_32 -> V_33 [ V_24 ] . V_27 = V_178 ;
}
if ( V_163 -> V_166 & V_185 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_27 & ~ ( V_35 ) ;
V_178 |= ( ( V_163 -> V_186 << 1 ) & V_35 ) ;
V_32 -> V_33 [ V_24 ] . V_27 = V_178 ;
}
if ( V_163 -> V_166 & V_187 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_188 ) ;
V_178 |= ( ( V_163 -> V_189 << 30 ) & V_188 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_178 ;
}
if ( V_163 -> V_166 & V_190 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_191 ) ;
V_178 |= ( ( V_163 -> V_192 << 29 ) & V_191 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_178 ;
}
if ( V_163 -> V_166 & V_193 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_3 ) ;
V_178 |= ( ( V_163 -> V_194 << 25 ) & V_3 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_178 ;
}
if ( V_163 -> V_166 & V_195 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_196 ) ;
V_178 |= ( ( V_163 -> V_197 << 24 ) & V_196 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_178 ;
}
if ( V_163 -> V_166 & V_198 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_199 ) ;
V_178 |= ( ( V_163 -> V_200 << 22 ) & V_199 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_178 ;
}
if ( V_163 -> V_166 & V_201 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_36 |
V_37 ) ;
V_178 |= ( ( ( V_163 -> V_173 << 11 ) - 1 ) & V_36 ) ;
V_178 |= ( ( ( V_163 -> V_175 ) - 1 ) & V_37 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_178 ;
V_179 = F_1 ( V_178 ) / 8 ;
V_178 = V_32 -> V_33 [ V_24 ] . V_97 & ~ ( V_202 ) ;
V_178 |= ( ( ( V_163 -> V_173 * V_179 ) << 8 ) & V_202 ) ;
V_32 -> V_33 [ V_24 ] . V_97 = V_178 ;
}
if ( V_163 -> V_166 & V_203 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_97 & ~ ( V_204 ) ;
V_178 |= ( ( V_163 -> V_205 << 24 ) & V_204 ) ;
V_32 -> V_33 [ V_24 ] . V_97 = V_178 ;
}
if ( V_163 -> V_166 & V_206 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_97 & ~ ( V_99 ) ;
V_178 |= ( ( V_163 -> V_207 << 23 ) & V_99 ) ;
V_32 -> V_33 [ V_24 ] . V_97 = V_178 ;
}
if ( V_163 -> V_166 & V_208 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_97 & ~ ( V_209 ) ;
V_178 |= ( ( V_163 -> V_210 << 21 ) & V_209 ) ;
V_32 -> V_33 [ V_24 ] . V_97 = V_178 ;
}
if ( V_163 -> V_166 & V_211 ) {
V_178 = V_32 -> V_33 [ V_24 ] . V_97 & ~ ( V_212 |
V_213 ) ;
V_178 |= ( ( V_163 -> V_173 << 11 ) & V_212 ) ;
V_178 |= ( ( V_163 -> V_175 ) & V_213 ) ;
V_32 -> V_33 [ V_24 ] . V_97 = V_178 ;
}
if ( V_163 -> V_166 & V_214 ) {
V_178 = V_32 -> V_28 ;
V_178 &= ~ ( 1 << V_24 ) ;
V_178 |= ( V_163 -> V_215 & 1 ) << V_24 ;
V_32 -> V_28 = V_178 ;
}
F_5 () ;
}
static void F_32 ( unsigned int V_24 ,
struct V_177 * V_163 )
{
V_163 -> V_25 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_181 ) >> 21 ;
V_163 -> V_26 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_182 ) >> 10 ;
V_163 -> V_184 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_34 ) >> 2 ;
V_163 -> V_186 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_35 ) >> 1 ;
V_163 -> V_189 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_188 ) >> 30 ;
V_163 -> V_192 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_191 ) >> 29 ;
V_163 -> V_194 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_3 ) >> 25 ;
V_163 -> V_197 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_196 ) >> 24 ;
V_163 -> V_200 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_199 ) >> 22 ;
V_163 -> V_173 = ( ( V_32 -> V_33 [ V_24 ] . V_1 & V_36 ) >> 11 ) + 1 ;
V_163 -> V_175 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_37 ) + 1 ;
V_163 -> V_205 = ( V_32 -> V_33 [ V_24 ] . V_97 & V_204 ) >> 24 ;
V_163 -> V_207 = ( V_32 -> V_33 [ V_24 ] . V_97 & V_99 ) >> 23 ;
V_163 -> V_210 = ( V_32 -> V_33 [ V_24 ] . V_97 & V_209 ) >> 21 ;
V_163 -> V_215 = ( V_32 -> V_28 >> V_24 ) & 1 ;
F_5 () ;
}
static int F_33 ( struct V_18 * V_146 , unsigned int V_161 ,
unsigned long V_216 )
{
struct V_22 * V_23 = V_146 -> V_116 ;
int V_24 ;
int V_178 ;
V_24 = F_2 ( V_146 ) ;
F_15 ( L_6 , V_161 , V_24 ) ;
if ( V_161 == V_217 ) {
struct V_218 V_219 ;
if ( F_34 ( & V_219 , ( void V_220 * ) V_216 , sizeof( V_219 ) ) )
return - V_221 ;
F_15 ( L_7 ) ;
switch ( V_219 . V_222 ) {
case V_223 :
F_15 ( L_8 ) ;
F_29 ( V_161 , & V_219 . V_224 ) ;
break;
case V_225 :
F_15 ( L_9 ) ;
F_30 ( V_161 , & V_219 . V_224 ) ;
break;
case V_226 :
F_15 ( L_10 ) ;
F_31 ( V_24 , & V_219 . V_33 ) ;
break;
case V_227 :
F_15 ( L_11 ) ;
F_32 ( V_24 , & V_219 . V_33 ) ;
break;
case V_228 :
F_15 ( L_12 ) ;
if ( ( V_219 . V_224 . V_229 >= 0 ) &&
( V_219 . V_224 . V_229 <
V_230 ) )
{
struct V_49 * V_50 ;
V_231 = V_219 . V_224 . V_229 ;
V_50 = & V_232 [ V_231 ] ;
F_6 ( V_50 , V_23 -> V_52 ) ;
}
break;
case V_233 :
F_15 ( L_13 ) ;
V_219 . V_224 . V_229 = V_231 ;
break;
default:
return - V_119 ;
}
V_178 = F_35 ( ( void V_220 * ) V_216 , & V_219 , sizeof( V_219 ) ) ;
if ( V_178 ) {
F_15 ( L_14 , V_178 ) ;
return - V_221 ;
}
}
return 0 ;
}
static T_5 F_36 ( int V_234 , void * V_235 )
{
V_32 -> V_55 = V_32 -> V_55 ;
F_5 () ;
return V_236 ;
}
static int F_37 ( struct V_22 * V_23 )
{
struct V_18 * V_105 = V_23 -> V_18 ;
int V_179 ;
V_105 -> V_237 = & V_238 ;
V_179 = F_1 ( V_38 -> V_39 [ V_23 -> V_24 ] . V_96 ) ;
memcpy ( & V_105 -> V_120 , & V_42 -> V_120 , sizeof( struct V_239 ) ) ;
if ( ! F_38 ( & V_105 -> V_106 ,
V_105 ,
NULL ,
V_105 -> V_120 . V_240 ,
V_105 -> V_120 . V_241 ,
V_105 -> V_120 . V_240 ,
V_179 ) ) {
F_39 ( L_15 , V_42 -> V_59 ) ;
return - V_221 ;
}
V_105 -> V_136 = F_40 ( 16 , sizeof( T_3 ) , V_242 ) ;
if ( ! V_105 -> V_136 ) {
return - V_243 ;
}
if ( F_41 ( & V_105 -> V_244 , V_134 , 0 ) < 0 ) {
F_39 ( L_16 ,
V_134 ) ;
F_42 ( V_105 -> V_136 ) ;
return - V_221 ;
}
strncpy ( V_105 -> V_100 . V_245 , L_17 , sizeof( V_105 -> V_100 . V_245 ) ) ;
V_105 -> V_100 . V_246 = V_23 -> V_47 ;
V_105 -> V_100 . V_247 = V_23 -> V_118 ;
V_105 -> V_100 . type = V_248 ;
V_105 -> V_100 . V_249 = 0 ;
V_105 -> V_100 . V_250 = 0 ;
V_105 -> V_100 . V_251 = 0 ;
V_105 -> V_100 . V_252 = 0 ;
V_105 -> V_100 . V_253 = V_254 ;
V_105 -> V_255 = ( char V_256 * ) V_23 -> V_257 ;
F_13 ( V_105 ) ;
return 0 ;
}
static int F_43 ( struct V_51 * V_52 )
{
char * V_258 = NULL ;
char * V_259 , * V_260 ;
int V_261 = F_44 ( V_232 ) ;
int V_262 = - 1 ;
F_45 ( V_263 , & V_258 ) ;
if ( ! V_258 )
goto V_264;
while ( ( V_259 = F_46 ( & V_258 , L_18 ) ) != NULL ) {
if ( ! strncmp ( V_259 , L_19 , 6 ) ) {
int V_19 ;
long int V_265 ;
char * V_260 ;
V_259 += 6 ;
V_265 = F_47 ( V_259 , & V_260 , 0 ) ;
if ( * V_260 == '\0' )
V_262 = ( int ) V_265 ;
else if ( strcmp ( V_259 , L_20 ) == 0 )
V_262 = V_52 -> V_231 () ;
else {
for ( V_19 = 0 ; V_19 < V_261 ; V_19 ++ ) {
if ( ! strcmp ( V_259 ,
V_232 [ V_19 ] . V_59 ) ) {
V_262 = V_19 ;
break;
}
}
}
if ( ( V_262 < 0 ) || ( V_262 >= V_261 ) )
F_48 ( L_21 , V_259 ) ;
else
V_231 = V_262 ;
} else if ( strncmp ( V_259 , L_22 , 10 ) == 0 )
V_266 = 1 ;
else if ( strncmp ( V_259 , L_23 , 8 ) == 0 ) {
V_259 += 8 ;
V_20 = F_47 ( V_259 , & V_260 , 0 ) ;
if ( ( V_20 < 0 ) ||
( V_20 > V_267 ) )
V_20 = V_267 ;
} else if ( strncmp ( V_259 , L_24 , 7 ) == 0 ) {
V_259 += 7 ;
V_268 = F_47 ( V_259 , & V_260 , 0 ) ;
if ( ( V_268 < 0 ) ||
( V_268 >= F_44 ( V_269 ) ) )
V_268 = V_270 ;
} else if ( strncmp ( V_259 , L_25 , 3 ) == 0 )
return 1 ;
else
F_48 ( L_26 , V_259 ) ;
}
V_264:
return 0 ;
}
static int T_6 F_49 ( struct V_271 * V_272 )
{
struct V_22 * V_23 ;
struct V_51 * V_52 ;
struct V_18 * V_105 = NULL ;
unsigned long V_273 ;
int V_179 , V_24 , V_274 , V_234 ;
F_50 ( L_27 V_275 L_27 ) ;
V_52 = V_272 -> V_272 . V_276 ;
if ( ! V_52 )
return - V_277 ;
if ( F_43 ( V_52 ) )
return - V_277 ;
V_42 = & V_232 [ V_231 ] ;
V_38 = & V_269 [ V_268 ] ;
F_3 ( V_263 L_28 , V_231 , V_42 -> V_59 ) ;
F_3 ( V_263 L_29 , V_268 , V_38 -> V_59 ) ;
V_274 = 0 ;
V_23 = NULL ;
for ( V_24 = 0 ; V_24 < V_20 ; ++ V_24 ) {
V_179 = F_1 ( V_38 -> V_39 [ V_24 ] . V_96 ) ;
if ( V_38 -> V_39 [ V_24 ] . V_40 == 0 )
V_38 -> V_39 [ V_24 ] . V_40 = V_42 -> V_43 ;
if ( V_38 -> V_39 [ V_24 ] . V_41 == 0 )
V_38 -> V_39 [ V_24 ] . V_41 = V_42 -> V_44 ;
V_105 = F_51 ( sizeof( struct V_22 ) ,
& V_272 -> V_272 ) ;
if ( ! V_105 )
goto V_278;
V_21 [ V_24 ] = V_105 ;
V_23 = V_105 -> V_116 ;
V_23 -> V_18 = V_105 ;
V_23 -> V_52 = V_52 ;
V_23 -> V_24 = V_24 ;
V_23 -> V_118 = ( V_38 -> V_39 [ V_24 ] . V_40 * V_38 -> V_39 [ V_24 ] . V_41 * V_179 ) / 8 ;
V_23 -> V_257 = F_52 ( & V_272 -> V_272 ,
F_25 ( V_23 -> V_118 ) ,
& V_23 -> V_47 , V_242 ) ;
if ( ! V_23 -> V_257 ) {
F_39 ( L_30 ,
V_23 -> V_118 / 1024 ) ;
return - V_243 ;
}
for ( V_273 = ( unsigned long ) V_23 -> V_47 ;
V_273 < F_25 ( ( unsigned long ) V_23 -> V_47 +
V_23 -> V_118 ) ;
V_273 += V_279 ) {
F_53 ( F_54 ( V_273 >> V_153 ) ) ;
}
F_15 ( L_31 , V_23 -> V_257 ) ;
F_15 ( L_32 , V_23 -> V_47 , V_23 -> V_118 / 1024 ) ;
if ( ( V_274 = F_37 ( V_23 ) ) < 0 )
goto V_278;
V_274 = F_55 ( V_105 ) ;
if ( V_274 < 0 ) {
F_39 ( L_33 ) ;
goto V_278;
}
F_21 ( V_105 ) ;
#if ! F_56 ( V_280 ) && F_56 ( V_281 )
if ( V_24 == 0 )
if ( F_57 ( V_105 , V_282 ) ) {
F_58 ( & V_105 -> V_244 , V_105 ) ;
F_59 ( V_105 , V_282 ) ;
}
#endif
}
V_234 = F_60 ( V_272 , 0 ) ;
V_274 = F_61 ( V_234 , F_36 ,
V_283 , L_34 , ( void * ) V_272 ) ;
if ( V_274 ) {
F_39 ( L_35 ,
V_234 , V_274 ) ;
goto V_278;
}
F_62 ( V_272 , V_52 ) ;
F_6 ( V_42 , V_52 ) ;
return 0 ;
V_278:
if ( V_23 -> V_257 )
F_63 ( & V_272 -> V_272 , F_25 ( V_23 -> V_118 ) ,
V_23 -> V_257 , V_23 -> V_47 ) ;
if ( V_105 ) {
if ( V_105 -> V_244 . V_149 != 0 )
F_64 ( & V_105 -> V_244 ) ;
F_42 ( V_105 -> V_136 ) ;
}
if ( V_24 == 0 )
F_65 ( V_284 , ( void * ) V_272 ) ;
return V_274 ;
}
static int T_7 F_66 ( struct V_271 * V_272 )
{
struct V_51 * V_52 = F_67 ( V_272 ) ;
struct V_22 * V_23 ;
struct V_18 * V_105 ;
int V_24 ;
F_6 ( NULL , V_52 ) ;
for ( V_24 = 0 ; V_24 < V_20 ; ++ V_24 ) {
V_105 = V_21 [ V_24 ] ;
V_23 = V_105 -> V_116 ;
F_68 ( V_105 ) ;
if ( V_23 -> V_257 )
F_63 ( & V_272 -> V_272 ,
F_25 ( V_23 -> V_118 ) ,
V_23 -> V_257 , V_23 -> V_47 ) ;
if ( V_105 -> V_244 . V_149 != 0 )
F_64 ( & V_105 -> V_244 ) ;
F_42 ( V_105 -> V_136 ) ;
F_69 ( V_105 ) ;
V_21 [ V_24 ] = NULL ;
}
F_65 ( F_60 ( V_272 , 0 ) , ( void * ) V_272 ) ;
return 0 ;
}
static int F_70 ( struct V_285 * V_272 )
{
struct V_51 * V_52 = F_71 ( V_272 ) ;
F_6 ( NULL , V_52 ) ;
V_32 -> V_77 = 0 ;
F_5 () ;
return 0 ;
}
static int F_72 ( struct V_285 * V_272 )
{
struct V_51 * V_52 = F_71 ( V_272 ) ;
struct V_18 * V_105 ;
int V_19 ;
F_6 ( V_42 , V_52 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_105 = V_21 [ V_19 ] ;
F_21 ( V_105 ) ;
}
return 0 ;
}
static int T_8 F_73 ( void )
{
return F_74 ( & V_286 ) ;
}
static void T_9 F_75 ( void )
{
F_76 ( & V_286 ) ;
}
