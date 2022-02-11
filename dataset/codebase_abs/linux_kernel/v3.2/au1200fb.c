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
static void F_6 ( struct V_49 * V_50 )
{
T_1 V_28 ;
V_28 = V_32 -> V_28 ;
V_32 -> V_28 = 0 ;
F_5 () ;
if ( V_32 -> V_51 & V_52 ) {
V_32 -> V_53 = V_54 ;
while ( ( V_32 -> V_53 & V_54 ) == 0 ) {
F_5 () ;
}
V_32 -> V_51 &= ~ V_52 ;
do {
V_32 -> V_53 = V_32 -> V_53 ;
F_5 () ;
} while ( ( V_32 -> V_53 & V_55 ) == 0 );
if ( V_42 -> V_56 != NULL )
V_42 -> V_56 () ;
}
if ( V_50 == NULL )
return;
V_42 = V_50 ;
F_3 ( L_2 , V_42 -> V_57 , V_42 -> V_43 , V_42 -> V_44 ) ;
if ( ! ( V_42 -> V_58 & V_59 ) )
{
T_1 V_60 ;
F_7 ( V_42 -> V_61 , V_62 ) ;
V_60 = F_8 ( V_63 ) & ~ 0x0000001f ;
V_60 |= V_42 -> V_64 ;
F_7 ( V_60 , V_63 ) ;
}
V_32 -> V_51 = V_42 -> V_65 ;
V_32 -> V_66 = V_42 -> V_67 ;
V_32 -> V_68 = V_42 -> V_69 ;
V_32 -> V_70 = V_42 -> V_58 ;
V_32 -> V_71 = V_42 -> V_72 ;
V_32 -> V_73 = V_42 -> V_74 ;
V_32 -> V_75 = V_42 -> V_76 ;
V_32 -> V_77 = V_42 -> V_78 ;
F_5 () ;
#if 0
au1200_setlocation(fbdev, 0, win->w[0].xpos, win->w[0].ypos);
au1200_setlocation(fbdev, 1, win->w[1].xpos, win->w[1].ypos);
au1200_setlocation(fbdev, 2, win->w[2].xpos, win->w[2].ypos);
au1200_setlocation(fbdev, 3, win->w[3].xpos, win->w[3].ypos);
#endif
V_32 -> V_28 = V_28 ;
V_32 -> V_51 |= V_52 ;
F_5 () ;
if ( V_42 -> V_79 != NULL ) V_42 -> V_79 () ;
V_32 -> V_80 = 0 ;
V_32 -> V_53 = ~ 0 ;
V_32 -> V_81 = V_38 -> V_82 ;
V_32 -> V_83 = V_38 -> V_84 ;
V_32 -> V_85 = V_38 -> V_86 ;
V_32 -> V_87 . V_88 = 0 ;
V_32 -> V_87 . V_89 = 0 ;
V_32 -> V_87 . V_90 = 0 ;
V_32 -> V_87 . V_91 = 0 ;
V_32 -> V_87 . V_92 = 0 ;
V_32 -> V_87 . V_93 = 0 ;
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
| V_38 -> V_39 [ V_24 ] . V_94
) ;
F_4 ( V_23 , V_24 , V_38 -> V_39 [ V_24 ] . V_25 , V_38 -> V_39 [ V_24 ] . V_26 ) ;
V_32 -> V_33 [ V_24 ] . V_95 = ( 0
| V_96
| V_97
| F_12 ( V_23 -> V_18 -> V_98 . V_99 )
| V_100
| V_101
) ;
V_32 -> V_28 |= V_38 -> V_39 [ V_24 ] . V_102 ;
F_5 () ;
}
static void F_13 ( struct V_18 * V_103 )
{
if ( F_14 ( V_42 ) ) {
if ( V_103 -> V_104 . V_105 <= 8 ) {
V_103 -> V_98 . V_106 = V_107 ;
V_103 -> V_98 . V_99 = V_103 -> V_104 . V_108 /
( 8 / V_103 -> V_104 . V_105 ) ;
} else {
V_103 -> V_98 . V_106 = V_109 ;
V_103 -> V_98 . V_99 = V_103 -> V_104 . V_108 * ( V_103 -> V_104 . V_105 / 8 ) ;
}
} else {
V_103 -> V_98 . V_106 = V_110 ;
V_103 -> V_98 . V_99 = V_103 -> V_104 . V_108 / 8 ;
}
V_103 -> V_111 = V_103 -> V_98 . V_99 * V_103 -> V_104 . V_112 ;
F_15 ( L_3 , V_103 -> V_98 . V_99 ) ;
F_15 ( L_4 , V_103 -> V_104 . V_105 ) ;
}
static int F_16 ( struct V_113 * V_104 ,
struct V_18 * V_103 )
{
struct V_22 * V_23 = V_103 -> V_114 ;
T_3 V_115 ;
int V_111 , V_24 ;
V_24 = V_23 -> V_24 ;
V_104 -> V_40 = V_38 -> V_39 [ V_24 ] . V_40 ;
V_104 -> V_41 = V_38 -> V_39 [ V_24 ] . V_41 ;
V_104 -> V_108 = V_104 -> V_40 ;
V_104 -> V_112 = V_104 -> V_41 ;
V_104 -> V_105 = F_1 ( V_38 -> V_39 [ V_24 ] . V_94 ) ;
V_111 = V_104 -> V_108 * V_104 -> V_112 ;
if ( V_104 -> V_105 > 8 ) V_111 *= ( V_104 -> V_105 / 8 ) ;
else V_111 /= ( 8 / V_104 -> V_105 ) ;
if ( V_23 -> V_116 < V_111 )
return - V_117 ;
V_115 = F_17 ( ( T_3 ) ( F_18 ( V_104 -> V_115 ) * 1000 ) , V_103 -> V_118 . V_119 ) ;
V_115 = F_19 ( V_115 , V_103 -> V_118 . V_120 , ( T_3 ) V_121 / 2 ) ;
if ( V_121 % V_115 ) {
int V_122 = V_121 % V_115 ;
V_115 -= V_122 ;
}
V_104 -> V_115 = F_20 ( V_115 / 1000 ) ;
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
switch ( V_104 -> V_105 ) {
case 16 :
{
int V_123 ;
V_123 = ( V_38 -> V_39 [ 0 ] . V_94 & V_3 ) >> 25 ;
V_104 -> V_124 = V_125 [ V_123 ] [ 0 ] ;
V_104 -> V_126 = V_125 [ V_123 ] [ 1 ] ;
V_104 -> V_127 = V_125 [ V_123 ] [ 2 ] ;
V_104 -> V_128 = V_125 [ V_123 ] [ 3 ] ;
break;
}
case 32 :
{
int V_123 ;
V_123 = ( V_38 -> V_39 [ 0 ] . V_94 & V_3 ) >> 25 ;
V_104 -> V_124 = V_125 [ V_123 ] [ 0 ] ;
V_104 -> V_126 = V_125 [ V_123 ] [ 1 ] ;
V_104 -> V_127 = V_125 [ V_123 ] [ 2 ] ;
V_104 -> V_128 = V_125 [ V_123 ] [ 3 ] ;
break;
}
default:
F_15 ( L_5 , V_104 -> V_105 ) ;
return - V_117 ;
}
return 0 ;
}
static int F_21 ( struct V_18 * V_103 )
{
struct V_22 * V_23 = V_103 -> V_114 ;
F_13 ( V_103 ) ;
F_10 ( V_23 ) ;
return 0 ;
}
static int F_22 ( unsigned V_129 , unsigned V_124 , unsigned V_126 ,
unsigned V_127 , unsigned V_128 , struct V_18 * V_103 )
{
volatile T_3 * V_130 = V_32 -> V_130 ;
T_3 V_131 ;
if ( V_129 > ( V_132 - 1 ) )
return - V_117 ;
if ( V_103 -> V_104 . V_133 ) {
V_124 = V_126 = V_127 =
( 19595 * V_124 + 38470 * V_126 + 7471 * V_127 ) >> 16 ;
}
if ( V_103 -> V_98 . V_106 == V_109 ) {
if ( V_129 > 16 )
return - V_117 ;
V_130 = ( T_3 * ) V_103 -> V_134 ;
V_124 >>= ( 16 - V_103 -> V_104 . V_124 . V_135 ) ;
V_126 >>= ( 16 - V_103 -> V_104 . V_126 . V_135 ) ;
V_127 >>= ( 16 - V_103 -> V_104 . V_127 . V_135 ) ;
V_131 = ( V_124 << V_103 -> V_104 . V_124 . V_136 ) |
( V_126 << V_103 -> V_104 . V_126 . V_136 ) |
( V_127 << V_103 -> V_104 . V_127 . V_136 ) ;
V_131 &= 0xFFFF ;
} else if ( 1 ) {
V_131 = ( V_124 & 0xF800 ) | ( ( V_126 >> 5 ) &
0x07E0 ) | ( ( V_127 >> 11 ) & 0x001F ) ;
V_131 &= 0xFFFF ;
} else if ( 0 ) {
V_131 = 0x1234 ;
V_131 &= 0xFFF ;
} else {
V_131 = ( V_126 >> 12 ) & 0x000F ;
V_131 &= 0xF ;
}
V_130 [ V_129 ] = V_131 ;
return 0 ;
}
static int F_23 ( int V_137 , struct V_18 * V_103 )
{
if ( V_138 )
return 0 ;
switch ( V_137 ) {
case V_139 :
case V_140 :
F_6 ( V_42 ) ;
break;
case V_141 :
case V_142 :
case V_143 :
F_6 ( NULL ) ;
break;
default:
break;
}
return ( V_137 == V_140 ) ? - V_117 : 0 ;
}
static int F_24 ( struct V_18 * V_144 , struct V_145 * V_146 )
{
unsigned int V_147 ;
unsigned long V_148 = 0 , V_149 ;
struct V_22 * V_23 = V_144 -> V_114 ;
if ( V_146 -> V_150 > ( ~ 0UL >> V_151 ) ) {
return - V_117 ;
}
V_148 = V_23 -> V_47 & V_152 ;
V_147 = F_25 ( ( V_148 & ~ V_152 ) + V_23 -> V_116 ) ;
V_149 = V_146 -> V_150 << V_151 ;
if ( ( V_146 -> V_153 - V_146 -> V_154 + V_149 ) > V_147 ) {
return - V_117 ;
}
V_149 += V_148 ;
V_146 -> V_150 = V_149 >> V_151 ;
V_146 -> V_155 = F_26 ( V_146 -> V_155 ) ;
F_27 ( V_146 -> V_155 ) |= V_156 ;
V_146 -> V_157 |= V_158 ;
return F_28 ( V_146 , V_146 -> V_154 , V_149 >> V_151 ,
V_146 -> V_153 - V_146 -> V_154 ,
V_146 -> V_155 ) ;
return 0 ;
}
static void F_29 ( T_4 V_159 , struct V_160 * V_161 )
{
unsigned int V_162 , V_163 ;
if ( V_161 -> V_164 & V_165 )
V_32 -> V_81 = V_161 -> V_81 ;
if ( V_161 -> V_164 & V_166 ) {
if ( V_161 -> V_167 < 30 ) {
V_161 -> V_167 = 30 ;
}
V_163 = ( V_32 -> V_71 & 0x3FFFF ) + 1 ;
V_162 = ( V_32 -> V_73 >> 16 ) + 1 ;
V_162 = ( ( ( V_161 -> V_167 & 0xFF ) + 1 ) * V_163 >> 8 ) ;
V_32 -> V_73 &= 0xFFFF ;
V_32 -> V_73 |= ( V_162 << 16 ) ;
}
if ( V_161 -> V_164 & V_168 )
V_32 -> V_83 = V_161 -> V_83 ;
if ( V_161 -> V_164 & V_169 )
V_32 -> V_85 = V_161 -> V_170 ;
F_5 () ;
}
static void F_30 ( T_4 V_159 , struct V_160 * V_161 )
{
unsigned int V_162 , V_163 ;
V_161 -> V_171 = ( ( V_32 -> V_51 & V_172 ) >> 19 ) + 1 ;
V_161 -> V_173 = ( ( V_32 -> V_51 & V_174 ) >> 8 ) + 1 ;
V_161 -> V_81 = V_32 -> V_81 ;
V_161 -> V_83 = V_32 -> V_83 ;
V_161 -> V_170 = V_32 -> V_85 ;
V_162 = ( V_32 -> V_73 >> 16 ) + 1 ;
V_163 = ( V_32 -> V_71 & 0x3FFFF ) + 1 ;
V_161 -> V_167 = ( ( V_162 << 8 ) / V_163 ) - 1 ;
F_5 () ;
}
static void F_31 ( unsigned int V_24 ,
struct V_175 * V_161 )
{
unsigned int V_176 , V_177 ;
if ( V_161 -> V_164 & V_178 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_27 & ~ ( V_179 |
V_180 ) ;
V_176 |= ( ( V_161 -> V_25 << 21 ) & V_179 ) ;
V_176 |= ( ( V_161 -> V_26 << 10 ) & V_180 ) ;
V_32 -> V_33 [ V_24 ] . V_27 = V_176 ;
}
if ( V_161 -> V_164 & V_181 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_27 & ~ ( V_34 ) ;
V_176 |= ( ( V_161 -> V_182 << 2 ) & V_34 ) ;
V_32 -> V_33 [ V_24 ] . V_27 = V_176 ;
}
if ( V_161 -> V_164 & V_183 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_27 & ~ ( V_35 ) ;
V_176 |= ( ( V_161 -> V_184 << 1 ) & V_35 ) ;
V_32 -> V_33 [ V_24 ] . V_27 = V_176 ;
}
if ( V_161 -> V_164 & V_185 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_186 ) ;
V_176 |= ( ( V_161 -> V_187 << 30 ) & V_186 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_176 ;
}
if ( V_161 -> V_164 & V_188 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_189 ) ;
V_176 |= ( ( V_161 -> V_190 << 29 ) & V_189 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_176 ;
}
if ( V_161 -> V_164 & V_191 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_3 ) ;
V_176 |= ( ( V_161 -> V_192 << 25 ) & V_3 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_176 ;
}
if ( V_161 -> V_164 & V_193 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_194 ) ;
V_176 |= ( ( V_161 -> V_195 << 24 ) & V_194 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_176 ;
}
if ( V_161 -> V_164 & V_196 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_197 ) ;
V_176 |= ( ( V_161 -> V_198 << 22 ) & V_197 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_176 ;
}
if ( V_161 -> V_164 & V_199 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_1 & ~ ( V_36 |
V_37 ) ;
V_176 |= ( ( ( V_161 -> V_171 << 11 ) - 1 ) & V_36 ) ;
V_176 |= ( ( ( V_161 -> V_173 ) - 1 ) & V_37 ) ;
V_32 -> V_33 [ V_24 ] . V_1 = V_176 ;
V_177 = F_1 ( V_176 ) / 8 ;
V_176 = V_32 -> V_33 [ V_24 ] . V_95 & ~ ( V_200 ) ;
V_176 |= ( ( ( V_161 -> V_171 * V_177 ) << 8 ) & V_200 ) ;
V_32 -> V_33 [ V_24 ] . V_95 = V_176 ;
}
if ( V_161 -> V_164 & V_201 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_95 & ~ ( V_202 ) ;
V_176 |= ( ( V_161 -> V_203 << 24 ) & V_202 ) ;
V_32 -> V_33 [ V_24 ] . V_95 = V_176 ;
}
if ( V_161 -> V_164 & V_204 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_95 & ~ ( V_97 ) ;
V_176 |= ( ( V_161 -> V_205 << 23 ) & V_97 ) ;
V_32 -> V_33 [ V_24 ] . V_95 = V_176 ;
}
if ( V_161 -> V_164 & V_206 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_95 & ~ ( V_207 ) ;
V_176 |= ( ( V_161 -> V_208 << 21 ) & V_207 ) ;
V_32 -> V_33 [ V_24 ] . V_95 = V_176 ;
}
if ( V_161 -> V_164 & V_209 ) {
V_176 = V_32 -> V_33 [ V_24 ] . V_95 & ~ ( V_210 |
V_211 ) ;
V_176 |= ( ( V_161 -> V_171 << 11 ) & V_210 ) ;
V_176 |= ( ( V_161 -> V_173 ) & V_211 ) ;
V_32 -> V_33 [ V_24 ] . V_95 = V_176 ;
}
if ( V_161 -> V_164 & V_212 ) {
V_176 = V_32 -> V_28 ;
V_176 &= ~ ( 1 << V_24 ) ;
V_176 |= ( V_161 -> V_213 & 1 ) << V_24 ;
V_32 -> V_28 = V_176 ;
}
F_5 () ;
}
static void F_32 ( unsigned int V_24 ,
struct V_175 * V_161 )
{
V_161 -> V_25 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_179 ) >> 21 ;
V_161 -> V_26 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_180 ) >> 10 ;
V_161 -> V_182 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_34 ) >> 2 ;
V_161 -> V_184 = ( V_32 -> V_33 [ V_24 ] . V_27 & V_35 ) >> 1 ;
V_161 -> V_187 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_186 ) >> 30 ;
V_161 -> V_190 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_189 ) >> 29 ;
V_161 -> V_192 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_3 ) >> 25 ;
V_161 -> V_195 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_194 ) >> 24 ;
V_161 -> V_198 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_197 ) >> 22 ;
V_161 -> V_171 = ( ( V_32 -> V_33 [ V_24 ] . V_1 & V_36 ) >> 11 ) + 1 ;
V_161 -> V_173 = ( V_32 -> V_33 [ V_24 ] . V_1 & V_37 ) + 1 ;
V_161 -> V_203 = ( V_32 -> V_33 [ V_24 ] . V_95 & V_202 ) >> 24 ;
V_161 -> V_205 = ( V_32 -> V_33 [ V_24 ] . V_95 & V_97 ) >> 23 ;
V_161 -> V_208 = ( V_32 -> V_33 [ V_24 ] . V_95 & V_207 ) >> 21 ;
V_161 -> V_213 = ( V_32 -> V_28 >> V_24 ) & 1 ;
F_5 () ;
}
static int F_33 ( struct V_18 * V_144 , unsigned int V_159 ,
unsigned long V_214 )
{
int V_24 ;
int V_176 ;
V_24 = F_2 ( V_144 ) ;
F_15 ( L_6 , V_159 , V_24 ) ;
if ( V_159 == V_215 ) {
struct V_216 V_217 ;
if ( F_34 ( & V_217 , ( void V_218 * ) V_214 , sizeof( V_217 ) ) )
return - V_219 ;
F_15 ( L_7 ) ;
switch ( V_217 . V_220 ) {
case V_221 :
F_15 ( L_8 ) ;
F_29 ( V_159 , & V_217 . V_222 ) ;
break;
case V_223 :
F_15 ( L_9 ) ;
F_30 ( V_159 , & V_217 . V_222 ) ;
break;
case V_224 :
F_15 ( L_10 ) ;
F_31 ( V_24 , & V_217 . V_33 ) ;
break;
case V_225 :
F_15 ( L_11 ) ;
F_32 ( V_24 , & V_217 . V_33 ) ;
break;
case V_226 :
F_15 ( L_12 ) ;
if ( ( V_217 . V_222 . V_227 >= 0 ) &&
( V_217 . V_222 . V_227 <
V_228 ) )
{
struct V_49 * V_50 ;
V_229 = V_217 . V_222 . V_227 ;
V_50 = & V_230 [ V_229 ] ;
F_6 ( V_50 ) ;
}
break;
case V_231 :
F_15 ( L_13 ) ;
V_217 . V_222 . V_227 = V_229 ;
break;
default:
return - V_117 ;
}
V_176 = F_35 ( ( void V_218 * ) V_214 , & V_217 , sizeof( V_217 ) ) ;
if ( V_176 ) {
F_15 ( L_14 , V_176 ) ;
return - V_219 ;
}
}
return 0 ;
}
static T_5 F_36 ( int V_232 , void * V_233 )
{
V_32 -> V_53 = V_32 -> V_53 ;
F_5 () ;
return V_234 ;
}
static int F_37 ( struct V_22 * V_23 )
{
struct V_18 * V_103 = V_23 -> V_18 ;
int V_177 ;
V_103 -> V_235 = & V_236 ;
V_177 = F_1 ( V_38 -> V_39 [ V_23 -> V_24 ] . V_94 ) ;
memcpy ( & V_103 -> V_118 , & V_42 -> V_118 , sizeof( struct V_237 ) ) ;
if ( ! F_38 ( & V_103 -> V_104 ,
V_103 ,
NULL ,
V_103 -> V_118 . V_238 ,
V_103 -> V_118 . V_239 ,
V_103 -> V_118 . V_238 ,
V_177 ) ) {
F_39 ( L_15 , V_42 -> V_57 ) ;
return - V_219 ;
}
V_103 -> V_134 = F_40 ( 16 , sizeof( T_3 ) , V_240 ) ;
if ( ! V_103 -> V_134 ) {
return - V_241 ;
}
if ( F_41 ( & V_103 -> V_242 , V_132 , 0 ) < 0 ) {
F_39 ( L_16 ,
V_132 ) ;
F_42 ( V_103 -> V_134 ) ;
return - V_219 ;
}
strncpy ( V_103 -> V_98 . V_243 , L_17 , sizeof( V_103 -> V_98 . V_243 ) ) ;
V_103 -> V_98 . V_244 = V_23 -> V_47 ;
V_103 -> V_98 . V_245 = V_23 -> V_116 ;
V_103 -> V_98 . type = V_246 ;
V_103 -> V_98 . V_247 = 0 ;
V_103 -> V_98 . V_248 = 0 ;
V_103 -> V_98 . V_249 = 0 ;
V_103 -> V_98 . V_250 = 0 ;
V_103 -> V_98 . V_251 = V_252 ;
V_103 -> V_253 = ( char V_254 * ) V_23 -> V_255 ;
F_13 ( V_103 ) ;
return 0 ;
}
static int T_6 F_43 ( struct V_256 * V_257 )
{
struct V_22 * V_23 ;
struct V_18 * V_103 = NULL ;
unsigned long V_258 ;
int V_177 , V_24 , V_259 , V_232 ;
V_259 = 0 ;
V_23 = NULL ;
F_6 ( V_42 ) ;
for ( V_24 = 0 ; V_24 < V_20 ; ++ V_24 ) {
V_177 = F_1 ( V_38 -> V_39 [ V_24 ] . V_94 ) ;
if ( V_38 -> V_39 [ V_24 ] . V_40 == 0 )
V_38 -> V_39 [ V_24 ] . V_40 = V_42 -> V_43 ;
if ( V_38 -> V_39 [ V_24 ] . V_41 == 0 )
V_38 -> V_39 [ V_24 ] . V_41 = V_42 -> V_44 ;
V_103 = F_44 ( sizeof( struct V_22 ) ,
& V_257 -> V_257 ) ;
if ( ! V_103 )
goto V_260;
V_21 [ V_24 ] = V_103 ;
V_23 = V_103 -> V_114 ;
V_23 -> V_18 = V_103 ;
V_23 -> V_24 = V_24 ;
V_23 -> V_116 = ( V_38 -> V_39 [ V_24 ] . V_40 * V_38 -> V_39 [ V_24 ] . V_41 * V_177 ) / 8 ;
V_23 -> V_255 = F_45 ( & V_257 -> V_257 ,
F_25 ( V_23 -> V_116 ) ,
& V_23 -> V_47 , V_240 ) ;
if ( ! V_23 -> V_255 ) {
F_39 ( L_18 ,
V_23 -> V_116 / 1024 ) ;
return - V_241 ;
}
for ( V_258 = ( unsigned long ) V_23 -> V_47 ;
V_258 < F_25 ( ( unsigned long ) V_23 -> V_47 +
V_23 -> V_116 ) ;
V_258 += V_261 ) {
F_46 ( F_47 ( V_258 >> V_151 ) ) ;
}
F_15 ( L_19 , V_23 -> V_255 ) ;
F_15 ( L_20 , V_23 -> V_47 , V_23 -> V_116 / 1024 ) ;
if ( ( V_259 = F_37 ( V_23 ) ) < 0 )
goto V_260;
V_259 = F_48 ( V_103 ) ;
if ( V_259 < 0 ) {
F_39 ( L_21 ) ;
goto V_260;
}
F_21 ( V_103 ) ;
#if ! F_49 ( V_262 ) && F_49 ( V_263 )
if ( V_24 == 0 )
if ( F_50 ( V_103 , V_264 ) ) {
F_51 ( & V_103 -> V_242 , V_103 ) ;
F_52 ( V_103 , V_264 ) ;
}
#endif
}
V_232 = F_53 ( V_257 , 0 ) ;
V_259 = F_54 ( V_232 , F_36 ,
V_265 , L_22 , ( void * ) V_257 ) ;
if ( V_259 ) {
F_39 ( L_23 ,
V_232 , V_259 ) ;
goto V_260;
}
return 0 ;
V_260:
if ( V_23 -> V_255 )
F_55 ( & V_257 -> V_257 , F_25 ( V_23 -> V_116 ) ,
V_23 -> V_255 , V_23 -> V_47 ) ;
if ( V_103 ) {
if ( V_103 -> V_242 . V_147 != 0 )
F_56 ( & V_103 -> V_242 ) ;
F_42 ( V_103 -> V_134 ) ;
}
if ( V_24 == 0 )
F_57 ( V_266 , ( void * ) V_257 ) ;
return V_259 ;
}
static int T_7 F_58 ( struct V_256 * V_257 )
{
struct V_22 * V_23 ;
struct V_18 * V_103 ;
int V_24 ;
F_6 ( NULL ) ;
for ( V_24 = 0 ; V_24 < V_20 ; ++ V_24 ) {
V_103 = V_21 [ V_24 ] ;
V_23 = V_103 -> V_114 ;
F_59 ( V_103 ) ;
if ( V_23 -> V_255 )
F_55 ( & V_257 -> V_257 ,
F_25 ( V_23 -> V_116 ) ,
V_23 -> V_255 , V_23 -> V_47 ) ;
if ( V_103 -> V_242 . V_147 != 0 )
F_56 ( & V_103 -> V_242 ) ;
F_42 ( V_103 -> V_134 ) ;
F_60 ( V_103 ) ;
V_21 [ V_24 ] = NULL ;
}
F_57 ( F_53 ( V_257 , 0 ) , ( void * ) V_257 ) ;
return 0 ;
}
static int F_61 ( struct V_267 * V_257 )
{
F_6 ( NULL ) ;
V_32 -> V_75 = 0 ;
F_5 () ;
return 0 ;
}
static int F_62 ( struct V_267 * V_257 )
{
struct V_18 * V_103 ;
int V_19 ;
F_6 ( V_42 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_103 = V_21 [ V_19 ] ;
F_21 ( V_103 ) ;
}
return 0 ;
}
static int F_63 ( void )
{
char * V_268 = NULL ;
char * V_269 , * V_270 ;
int V_271 = F_64 ( V_230 ) ;
int V_272 = - 1 ;
F_65 ( V_273 , & V_268 ) ;
if ( V_268 ) {
while ( ( V_269 = F_66 ( & V_268 , L_24 ) ) != NULL ) {
if ( ! strncmp ( V_269 , L_25 , 6 ) ) {
int V_19 ;
long int V_274 ;
char * V_270 ;
V_269 += 6 ;
V_274 = F_67 ( V_269 , & V_270 , 0 ) ;
if ( * V_270 == '\0' ) {
V_272 = ( int ) V_274 ;
}
else if ( strcmp ( V_269 , L_26 ) == 0 ) {
extern int V_275 ( void ) ;
V_272 = V_275 () ;
}
else
for ( V_19 = 0 ; V_19 < V_271 ; V_19 ++ ) {
if ( ! strcmp ( V_269 , V_230 [ V_19 ] . V_57 ) ) {
V_272 = V_19 ;
break;
}
}
if ( ( V_272 < 0 ) || ( V_272 >= V_271 ) ) {
F_68 ( L_27 , V_269 ) ;
}
else
V_229 = V_272 ;
}
else if ( strncmp ( V_269 , L_28 , 10 ) == 0 ) {
V_276 = 1 ;
}
else if ( strncmp ( V_269 , L_29 , 8 ) == 0 ) {
V_269 += 8 ;
V_20 = F_67 ( V_269 ,
& V_270 , 0 ) ;
if ( ( V_20 < 0 ) ||
( V_20 > V_277 ) )
V_20 = V_277 ;
}
else if ( strncmp ( V_269 , L_30 , 7 ) == 0 ) {
V_269 += 7 ;
V_278 = F_67 ( V_269 ,
& V_270 , 0 ) ;
if ( ( V_278 < 0 ) ||
( V_278 >= F_64 ( V_279 ) ) )
V_278 = V_280 ;
}
else if ( strncmp ( V_269 , L_31 , 3 ) == 0 )
return 1 ;
else {
F_68 ( L_32 , V_269 ) ;
}
}
}
return 0 ;
}
static int T_8 F_69 ( void )
{
F_70 ( L_33 V_281 L_33 ) ;
if ( F_63 () )
return - V_282 ;
V_42 = & V_230 [ V_229 ] ;
V_38 = & V_279 [ V_278 ] ;
F_3 ( V_273 L_34 , V_229 , V_42 -> V_57 ) ;
F_3 ( V_273 L_35 , V_278 , V_38 -> V_57 ) ;
return F_71 ( & V_283 ) ;
}
static void T_9 F_72 ( void )
{
F_73 ( & V_283 ) ;
}
