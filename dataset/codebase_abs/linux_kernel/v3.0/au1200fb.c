static int F_1 ( unsigned int V_1 )
{
unsigned int V_2 , V_3 ;
if ( V_1 < 30 ) {
V_1 = 30 ;
}
V_3 = ( V_4 -> V_5 & 0x3FFFF ) + 1 ;
V_2 = ( V_4 -> V_6 >> 16 ) + 1 ;
V_2 = ( ( ( V_1 & 0xFF ) + 1 ) * V_3 >> 8 ) ;
V_4 -> V_6 &= 0xFFFF ;
V_4 -> V_6 |= ( V_2 << 16 ) ;
return V_1 ;
}
static int F_2 ( unsigned int V_7 )
{
int V_8 = 0 ;
switch ( V_7 & V_9 ) {
case V_10 :
V_8 = 1 ;
break;
case V_11 :
V_8 = 2 ;
break;
case V_12 :
V_8 = 4 ;
break;
case V_13 :
V_8 = 8 ;
break;
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_8 = 16 ;
break;
case V_22 :
case V_23 :
V_8 = 32 ;
break;
}
return V_8 ;
}
static int F_3 ( struct V_24 * V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( V_24 == (struct V_24 * ) ( & V_27 [ V_25 ] . V_24 ) )
return V_25 ;
}
F_4 ( L_1 ) ;
return - 1 ;
}
static int F_5 ( struct V_28 * V_29 , int V_30 ,
int V_31 , int V_32 )
{
T_1 V_33 , V_7 , V_34 , V_35 = 0 ;
int V_36 , V_37 ;
V_33 = V_4 -> V_38 [ V_30 ] . V_33 ;
V_7 = V_4 -> V_38 [ V_30 ] . V_7 ;
V_33 &= ( V_39 | V_40 ) ;
V_7 &= ~ ( V_41 | V_42 ) ;
V_36 = V_43 -> V_44 [ V_30 ] . V_45 ;
V_37 = V_43 -> V_44 [ V_30 ] . V_46 ;
if ( ( V_31 + V_43 -> V_44 [ V_30 ] . V_45 ) > V_47 -> V_48 ) {
V_36 = V_47 -> V_48 - V_31 ;
}
if ( ( V_32 + V_43 -> V_44 [ V_30 ] . V_46 ) > V_47 -> V_49 ) {
V_37 = V_47 -> V_49 - V_32 ;
}
if ( V_31 < 0 ) {
V_36 = V_43 -> V_44 [ V_30 ] . V_45 + V_31 ;
V_35 += ( ( ( 0 - V_31 ) * F_2 ( V_4 -> V_38 [ V_30 ] . V_7 ) ) / 8 ) ;
V_31 = 0 ;
}
if ( V_32 < 0 ) {
V_37 = V_43 -> V_44 [ V_30 ] . V_46 + V_32 ;
V_32 = 0 ;
}
V_43 -> V_44 [ V_30 ] . V_31 = V_31 ;
V_43 -> V_44 [ V_30 ] . V_32 = V_32 ;
V_36 -= 1 ;
V_37 -= 1 ;
V_33 |= ( V_31 << 21 ) ;
V_33 |= ( V_32 << 10 ) ;
V_7 |= ( V_36 << 11 ) ;
V_7 |= ( V_37 << 0 ) ;
V_34 = V_4 -> V_34 & ( 1 << V_30 ) ;
F_6 () ;
V_4 -> V_34 &= ~ ( 1 << V_30 ) ;
V_4 -> V_38 [ V_30 ] . V_33 = V_33 ;
V_4 -> V_38 [ V_30 ] . V_7 = V_7 ;
V_4 -> V_38 [ V_30 ] . V_50 =
V_4 -> V_38 [ V_30 ] . V_51 = V_29 -> V_52 ;
V_4 -> V_38 [ V_30 ] . V_53 = 0 ;
V_4 -> V_34 |= V_34 ;
F_6 () ;
return 0 ;
}
static void F_7 ( struct V_54 * V_55 )
{
T_1 V_34 ;
V_34 = V_4 -> V_34 ;
V_4 -> V_34 = 0 ;
F_6 () ;
if ( V_4 -> V_56 & V_57 ) {
V_4 -> V_58 = V_59 ;
while ( ( V_4 -> V_58 & V_59 ) == 0 ) {
F_6 () ;
}
V_4 -> V_56 &= ~ V_57 ;
do {
V_4 -> V_58 = V_4 -> V_58 ;
F_6 () ;
} while ( ( V_4 -> V_58 & V_60 ) == 0 );
if ( V_47 -> V_61 != NULL )
V_47 -> V_61 () ;
}
if ( V_55 == NULL )
return;
V_47 = V_55 ;
F_4 ( L_2 , V_47 -> V_62 , V_47 -> V_48 , V_47 -> V_49 ) ;
if ( ! ( V_47 -> V_63 & V_64 ) )
{
T_1 V_65 ;
F_8 ( V_47 -> V_66 , V_67 ) ;
V_65 = F_9 ( V_68 ) & ~ 0x0000001f ;
V_65 |= V_47 -> V_69 ;
F_8 ( V_65 , V_68 ) ;
}
V_4 -> V_56 = V_47 -> V_70 ;
V_4 -> V_71 = V_47 -> V_72 ;
V_4 -> V_73 = V_47 -> V_74 ;
V_4 -> V_75 = V_47 -> V_63 ;
V_4 -> V_5 = V_47 -> V_76 ;
V_4 -> V_6 = V_47 -> V_77 ;
V_4 -> V_78 = V_47 -> V_79 ;
V_4 -> V_80 = V_47 -> V_81 ;
F_6 () ;
#if 0
au1200_setlocation(fbdev, 0, win->w[0].xpos, win->w[0].ypos);
au1200_setlocation(fbdev, 1, win->w[1].xpos, win->w[1].ypos);
au1200_setlocation(fbdev, 2, win->w[2].xpos, win->w[2].ypos);
au1200_setlocation(fbdev, 3, win->w[3].xpos, win->w[3].ypos);
#endif
V_4 -> V_34 = V_34 ;
V_4 -> V_56 |= V_57 ;
F_6 () ;
if ( V_47 -> V_82 != NULL ) V_47 -> V_82 () ;
V_4 -> V_83 = 0 ;
V_4 -> V_58 = ~ 0 ;
V_4 -> V_84 = V_43 -> V_85 ;
V_4 -> V_86 = V_43 -> V_87 ;
V_4 -> V_88 = V_43 -> V_89 ;
V_4 -> V_90 . V_91 = 0 ;
V_4 -> V_90 . V_92 = 0 ;
V_4 -> V_90 . V_93 = 0 ;
V_4 -> V_90 . V_94 = 0 ;
V_4 -> V_90 . V_95 = 0 ;
V_4 -> V_90 . V_96 = 0 ;
#if 0
#define F_10 ( T_2 ) printk("%25s: %08X\n", #X, X)
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
static void F_11 ( struct V_28 * V_29 )
{
int V_30 = V_29 -> V_30 ;
V_4 -> V_38 [ V_30 ] . V_7 = ( 0
| F_12 ( V_30 )
| V_43 -> V_44 [ V_30 ] . V_97
) ;
F_5 ( V_29 , V_30 , V_43 -> V_44 [ V_30 ] . V_31 , V_43 -> V_44 [ V_30 ] . V_32 ) ;
V_4 -> V_38 [ V_30 ] . V_98 = ( 0
| V_99
| V_100
| F_13 ( V_29 -> V_24 . V_101 . V_102 )
| V_103
| V_104
) ;
V_4 -> V_34 |= V_43 -> V_44 [ V_30 ] . V_105 ;
F_6 () ;
}
static void F_14 ( struct V_24 * V_106 )
{
if ( F_15 ( V_47 ) ) {
if ( V_106 -> V_107 . V_108 <= 8 ) {
V_106 -> V_101 . V_109 = V_110 ;
V_106 -> V_101 . V_102 = V_106 -> V_107 . V_111 /
( 8 / V_106 -> V_107 . V_108 ) ;
} else {
V_106 -> V_101 . V_109 = V_112 ;
V_106 -> V_101 . V_102 = V_106 -> V_107 . V_111 * ( V_106 -> V_107 . V_108 / 8 ) ;
}
} else {
V_106 -> V_101 . V_109 = V_113 ;
V_106 -> V_101 . V_102 = V_106 -> V_107 . V_111 / 8 ;
}
V_106 -> V_114 = V_106 -> V_101 . V_102 * V_106 -> V_107 . V_115 ;
F_16 ( L_3 , V_106 -> V_101 . V_102 ) ;
F_16 ( L_4 , V_106 -> V_107 . V_108 ) ;
}
static int F_17 ( struct V_116 * V_107 ,
struct V_24 * V_106 )
{
struct V_28 * V_29 = (struct V_28 * ) V_106 ;
T_3 V_117 ;
int V_114 , V_30 ;
V_30 = V_29 -> V_30 ;
V_107 -> V_45 = V_43 -> V_44 [ V_30 ] . V_45 ;
V_107 -> V_46 = V_43 -> V_44 [ V_30 ] . V_46 ;
V_107 -> V_111 = V_107 -> V_45 ;
V_107 -> V_115 = V_107 -> V_46 ;
V_107 -> V_108 = F_2 ( V_43 -> V_44 [ V_30 ] . V_97 ) ;
V_114 = V_107 -> V_111 * V_107 -> V_115 ;
if ( V_107 -> V_108 > 8 ) V_114 *= ( V_107 -> V_108 / 8 ) ;
else V_114 /= ( 8 / V_107 -> V_108 ) ;
if ( V_29 -> V_118 < V_114 )
return - V_119 ;
V_117 = F_18 ( ( T_3 ) ( F_19 ( V_107 -> V_117 ) * 1000 ) , V_106 -> V_120 . V_121 ) ;
V_117 = F_20 ( V_117 , V_106 -> V_120 . V_122 , ( T_3 ) V_123 / 2 ) ;
if ( V_123 % V_117 ) {
int V_124 = V_123 % V_117 ;
V_117 -= V_124 ;
}
V_107 -> V_117 = F_21 ( V_117 / 1000 ) ;
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
switch ( V_107 -> V_108 ) {
case 16 :
{
int V_125 ;
V_125 = ( V_43 -> V_44 [ 0 ] . V_97 & V_9 ) >> 25 ;
V_107 -> V_126 = V_127 [ V_125 ] [ 0 ] ;
V_107 -> V_128 = V_127 [ V_125 ] [ 1 ] ;
V_107 -> V_129 = V_127 [ V_125 ] [ 2 ] ;
V_107 -> V_130 = V_127 [ V_125 ] [ 3 ] ;
break;
}
case 32 :
{
int V_125 ;
V_125 = ( V_43 -> V_44 [ 0 ] . V_97 & V_9 ) >> 25 ;
V_107 -> V_126 = V_127 [ V_125 ] [ 0 ] ;
V_107 -> V_128 = V_127 [ V_125 ] [ 1 ] ;
V_107 -> V_129 = V_127 [ V_125 ] [ 2 ] ;
V_107 -> V_130 = V_127 [ V_125 ] [ 3 ] ;
break;
}
default:
F_16 ( L_5 , V_107 -> V_108 ) ;
return - V_119 ;
}
return 0 ;
}
static int F_22 ( struct V_24 * V_106 )
{
struct V_28 * V_29 = (struct V_28 * ) V_106 ;
F_14 ( V_106 ) ;
F_11 ( V_29 ) ;
return 0 ;
}
static int F_23 ( unsigned V_131 , unsigned V_126 , unsigned V_128 ,
unsigned V_129 , unsigned V_130 , struct V_24 * V_106 )
{
volatile T_3 * V_132 = V_4 -> V_132 ;
T_3 V_133 ;
if ( V_131 > ( V_134 - 1 ) )
return - V_119 ;
if ( V_106 -> V_107 . V_135 ) {
V_126 = V_128 = V_129 =
( 19595 * V_126 + 38470 * V_128 + 7471 * V_129 ) >> 16 ;
}
if ( V_106 -> V_101 . V_109 == V_112 ) {
if ( V_131 > 16 )
return - V_119 ;
V_132 = ( T_3 * ) V_106 -> V_136 ;
V_126 >>= ( 16 - V_106 -> V_107 . V_126 . V_137 ) ;
V_128 >>= ( 16 - V_106 -> V_107 . V_128 . V_137 ) ;
V_129 >>= ( 16 - V_106 -> V_107 . V_129 . V_137 ) ;
V_133 = ( V_126 << V_106 -> V_107 . V_126 . V_138 ) |
( V_128 << V_106 -> V_107 . V_128 . V_138 ) |
( V_129 << V_106 -> V_107 . V_129 . V_138 ) ;
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
static int F_24 ( int V_139 , struct V_24 * V_106 )
{
if ( V_140 )
return 0 ;
switch ( V_139 ) {
case V_141 :
case V_142 :
F_7 ( V_47 ) ;
break;
case V_143 :
case V_144 :
case V_145 :
F_7 ( NULL ) ;
break;
default:
break;
}
return ( V_139 == V_142 ) ? - V_119 : 0 ;
}
static int F_25 ( struct V_24 * V_146 , struct V_147 * V_148 )
{
unsigned int V_149 ;
unsigned long V_150 = 0 , V_151 ;
struct V_28 * V_29 = (struct V_28 * ) V_146 ;
#ifdef F_26
F_27 ( V_152 ) ;
#endif
if ( V_148 -> V_153 > ( ~ 0UL >> V_154 ) ) {
return - V_119 ;
}
V_150 = V_29 -> V_52 & V_155 ;
V_149 = F_28 ( ( V_150 & ~ V_155 ) + V_29 -> V_118 ) ;
V_151 = V_148 -> V_153 << V_154 ;
if ( ( V_148 -> V_156 - V_148 -> V_157 + V_151 ) > V_149 ) {
return - V_119 ;
}
V_151 += V_150 ;
V_148 -> V_153 = V_151 >> V_154 ;
V_148 -> V_158 = F_29 ( V_148 -> V_158 ) ;
F_30 ( V_148 -> V_158 ) |= V_159 ;
V_148 -> V_160 |= V_161 ;
return F_31 ( V_148 , V_148 -> V_157 , V_151 >> V_154 ,
V_148 -> V_156 - V_148 -> V_157 ,
V_148 -> V_158 ) ;
return 0 ;
}
static void F_32 ( T_4 V_162 , struct V_163 * V_164 )
{
unsigned int V_2 , V_3 ;
if ( V_164 -> V_165 & V_166 )
V_4 -> V_84 = V_164 -> V_84 ;
if ( V_164 -> V_165 & V_167 ) {
if ( V_164 -> V_1 < 30 ) {
V_164 -> V_1 = 30 ;
}
V_3 = ( V_4 -> V_5 & 0x3FFFF ) + 1 ;
V_2 = ( V_4 -> V_6 >> 16 ) + 1 ;
V_2 = ( ( ( V_164 -> V_1 & 0xFF ) + 1 ) * V_3 >> 8 ) ;
V_4 -> V_6 &= 0xFFFF ;
V_4 -> V_6 |= ( V_2 << 16 ) ;
}
if ( V_164 -> V_165 & V_168 )
V_4 -> V_86 = V_164 -> V_86 ;
if ( V_164 -> V_165 & V_169 )
V_4 -> V_88 = V_164 -> V_170 ;
F_6 () ;
}
static void F_33 ( T_4 V_162 , struct V_163 * V_164 )
{
unsigned int V_2 , V_3 ;
V_164 -> V_171 = ( ( V_4 -> V_56 & V_172 ) >> 19 ) + 1 ;
V_164 -> V_173 = ( ( V_4 -> V_56 & V_174 ) >> 8 ) + 1 ;
V_164 -> V_84 = V_4 -> V_84 ;
V_164 -> V_86 = V_4 -> V_86 ;
V_164 -> V_170 = V_4 -> V_88 ;
V_2 = ( V_4 -> V_6 >> 16 ) + 1 ;
V_3 = ( V_4 -> V_5 & 0x3FFFF ) + 1 ;
V_164 -> V_1 = ( ( V_2 << 8 ) / V_3 ) - 1 ;
F_6 () ;
}
static void F_34 ( unsigned int V_30 ,
struct V_175 * V_164 )
{
unsigned int V_176 , V_177 ;
if ( V_164 -> V_165 & V_178 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_33 & ~ ( V_179 |
V_180 ) ;
V_176 |= ( ( V_164 -> V_31 << 21 ) & V_179 ) ;
V_176 |= ( ( V_164 -> V_32 << 10 ) & V_180 ) ;
V_4 -> V_38 [ V_30 ] . V_33 = V_176 ;
}
if ( V_164 -> V_165 & V_181 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_33 & ~ ( V_39 ) ;
V_176 |= ( ( V_164 -> V_182 << 2 ) & V_39 ) ;
V_4 -> V_38 [ V_30 ] . V_33 = V_176 ;
}
if ( V_164 -> V_165 & V_183 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_33 & ~ ( V_40 ) ;
V_176 |= ( ( V_164 -> V_184 << 1 ) & V_40 ) ;
V_4 -> V_38 [ V_30 ] . V_33 = V_176 ;
}
if ( V_164 -> V_165 & V_185 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_7 & ~ ( V_186 ) ;
V_176 |= ( ( V_164 -> V_187 << 30 ) & V_186 ) ;
V_4 -> V_38 [ V_30 ] . V_7 = V_176 ;
}
if ( V_164 -> V_165 & V_188 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_7 & ~ ( V_189 ) ;
V_176 |= ( ( V_164 -> V_190 << 29 ) & V_189 ) ;
V_4 -> V_38 [ V_30 ] . V_7 = V_176 ;
}
if ( V_164 -> V_165 & V_191 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_7 & ~ ( V_9 ) ;
V_176 |= ( ( V_164 -> V_192 << 25 ) & V_9 ) ;
V_4 -> V_38 [ V_30 ] . V_7 = V_176 ;
}
if ( V_164 -> V_165 & V_193 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_7 & ~ ( V_194 ) ;
V_176 |= ( ( V_164 -> V_195 << 24 ) & V_194 ) ;
V_4 -> V_38 [ V_30 ] . V_7 = V_176 ;
}
if ( V_164 -> V_165 & V_196 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_7 & ~ ( V_197 ) ;
V_176 |= ( ( V_164 -> V_198 << 22 ) & V_197 ) ;
V_4 -> V_38 [ V_30 ] . V_7 = V_176 ;
}
if ( V_164 -> V_165 & V_199 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_7 & ~ ( V_41 |
V_42 ) ;
V_176 |= ( ( ( V_164 -> V_171 << 11 ) - 1 ) & V_41 ) ;
V_176 |= ( ( ( V_164 -> V_173 ) - 1 ) & V_42 ) ;
V_4 -> V_38 [ V_30 ] . V_7 = V_176 ;
V_177 = F_2 ( V_176 ) / 8 ;
V_176 = V_4 -> V_38 [ V_30 ] . V_98 & ~ ( V_200 ) ;
V_176 |= ( ( ( V_164 -> V_171 * V_177 ) << 8 ) & V_200 ) ;
V_4 -> V_38 [ V_30 ] . V_98 = V_176 ;
}
if ( V_164 -> V_165 & V_201 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_98 & ~ ( V_202 ) ;
V_176 |= ( ( V_164 -> V_203 << 24 ) & V_202 ) ;
V_4 -> V_38 [ V_30 ] . V_98 = V_176 ;
}
if ( V_164 -> V_165 & V_204 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_98 & ~ ( V_100 ) ;
V_176 |= ( ( V_164 -> V_205 << 23 ) & V_100 ) ;
V_4 -> V_38 [ V_30 ] . V_98 = V_176 ;
}
if ( V_164 -> V_165 & V_206 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_98 & ~ ( V_207 ) ;
V_176 |= ( ( V_164 -> V_208 << 21 ) & V_207 ) ;
V_4 -> V_38 [ V_30 ] . V_98 = V_176 ;
}
if ( V_164 -> V_165 & V_209 ) {
V_176 = V_4 -> V_38 [ V_30 ] . V_98 & ~ ( V_210 |
V_211 ) ;
V_176 |= ( ( V_164 -> V_171 << 11 ) & V_210 ) ;
V_176 |= ( ( V_164 -> V_173 ) & V_211 ) ;
V_4 -> V_38 [ V_30 ] . V_98 = V_176 ;
}
if ( V_164 -> V_165 & V_212 ) {
V_176 = V_4 -> V_34 ;
V_176 &= ~ ( 1 << V_30 ) ;
V_176 |= ( V_164 -> V_213 & 1 ) << V_30 ;
V_4 -> V_34 = V_176 ;
}
F_6 () ;
}
static void F_35 ( unsigned int V_30 ,
struct V_175 * V_164 )
{
V_164 -> V_31 = ( V_4 -> V_38 [ V_30 ] . V_33 & V_179 ) >> 21 ;
V_164 -> V_32 = ( V_4 -> V_38 [ V_30 ] . V_33 & V_180 ) >> 10 ;
V_164 -> V_182 = ( V_4 -> V_38 [ V_30 ] . V_33 & V_39 ) >> 2 ;
V_164 -> V_184 = ( V_4 -> V_38 [ V_30 ] . V_33 & V_40 ) >> 1 ;
V_164 -> V_187 = ( V_4 -> V_38 [ V_30 ] . V_7 & V_186 ) >> 30 ;
V_164 -> V_190 = ( V_4 -> V_38 [ V_30 ] . V_7 & V_189 ) >> 29 ;
V_164 -> V_192 = ( V_4 -> V_38 [ V_30 ] . V_7 & V_9 ) >> 25 ;
V_164 -> V_195 = ( V_4 -> V_38 [ V_30 ] . V_7 & V_194 ) >> 24 ;
V_164 -> V_198 = ( V_4 -> V_38 [ V_30 ] . V_7 & V_197 ) >> 22 ;
V_164 -> V_171 = ( ( V_4 -> V_38 [ V_30 ] . V_7 & V_41 ) >> 11 ) + 1 ;
V_164 -> V_173 = ( V_4 -> V_38 [ V_30 ] . V_7 & V_42 ) + 1 ;
V_164 -> V_203 = ( V_4 -> V_38 [ V_30 ] . V_98 & V_202 ) >> 24 ;
V_164 -> V_205 = ( V_4 -> V_38 [ V_30 ] . V_98 & V_100 ) >> 23 ;
V_164 -> V_208 = ( V_4 -> V_38 [ V_30 ] . V_98 & V_207 ) >> 21 ;
V_164 -> V_213 = ( V_4 -> V_34 >> V_30 ) & 1 ;
F_6 () ;
}
static int F_36 ( struct V_24 * V_146 , unsigned int V_162 ,
unsigned long V_214 )
{
int V_30 ;
int V_176 ;
#ifdef F_26
F_27 ( V_152 ) ;
#endif
V_30 = F_3 ( V_146 ) ;
F_16 ( L_6 , V_162 , V_30 ) ;
if ( V_162 == V_215 ) {
struct V_216 V_217 ;
if ( F_37 ( & V_217 , ( void V_218 * ) V_214 , sizeof( V_217 ) ) )
return - V_219 ;
F_16 ( L_7 ) ;
switch ( V_217 . V_220 ) {
case V_221 :
F_16 ( L_8 ) ;
F_32 ( V_162 , & V_217 . V_222 ) ;
break;
case V_223 :
F_16 ( L_9 ) ;
F_33 ( V_162 , & V_217 . V_222 ) ;
break;
case V_224 :
F_16 ( L_10 ) ;
F_34 ( V_30 , & V_217 . V_38 ) ;
break;
case V_225 :
F_16 ( L_11 ) ;
F_35 ( V_30 , & V_217 . V_38 ) ;
break;
case V_226 :
F_16 ( L_12 ) ;
if ( ( V_217 . V_222 . V_227 >= 0 ) &&
( V_217 . V_222 . V_227 <
V_228 ) )
{
struct V_54 * V_55 ;
V_229 = V_217 . V_222 . V_227 ;
V_55 = & V_230 [ V_229 ] ;
F_7 ( V_55 ) ;
}
break;
case V_231 :
F_16 ( L_13 ) ;
V_217 . V_222 . V_227 = V_229 ;
break;
default:
return - V_119 ;
}
V_176 = F_38 ( ( void V_218 * ) V_214 , & V_217 , sizeof( V_217 ) ) ;
if ( V_176 ) {
F_16 ( L_14 , V_176 ) ;
return - V_219 ;
}
}
return 0 ;
}
static T_5 F_39 ( int V_232 , void * V_233 )
{
V_4 -> V_58 = V_4 -> V_58 ;
F_6 () ;
return V_234 ;
}
static int F_40 ( struct V_28 * V_29 )
{
struct V_24 * V_106 = & V_29 -> V_24 ;
int V_177 ;
memset ( V_106 , 0 , sizeof( struct V_24 ) ) ;
V_106 -> V_235 = & V_236 ;
V_177 = F_2 ( V_43 -> V_44 [ V_29 -> V_30 ] . V_97 ) ;
memcpy ( & V_106 -> V_120 , & V_47 -> V_120 , sizeof( struct V_237 ) ) ;
if ( ! F_41 ( & V_106 -> V_107 ,
V_106 ,
NULL ,
V_106 -> V_120 . V_238 ,
V_106 -> V_120 . V_239 ,
V_106 -> V_120 . V_238 ,
V_177 ) ) {
F_42 ( L_15 , V_47 -> V_62 ) ;
return - V_219 ;
}
V_106 -> V_136 = F_43 ( 16 , sizeof( T_3 ) , V_240 ) ;
if ( ! V_106 -> V_136 ) {
return - V_241 ;
}
if ( F_44 ( & V_106 -> V_242 , V_134 , 0 ) < 0 ) {
F_42 ( L_16 ,
V_134 ) ;
F_45 ( V_106 -> V_136 ) ;
return - V_219 ;
}
strncpy ( V_106 -> V_101 . V_243 , L_17 , sizeof( V_106 -> V_101 . V_243 ) ) ;
V_106 -> V_101 . V_244 = V_29 -> V_52 ;
V_106 -> V_101 . V_245 = V_29 -> V_118 ;
V_106 -> V_101 . type = V_246 ;
V_106 -> V_101 . V_247 = 0 ;
V_106 -> V_101 . V_248 = 0 ;
V_106 -> V_101 . V_249 = 0 ;
V_106 -> V_101 . V_250 = 0 ;
V_106 -> V_101 . V_251 = V_252 ;
V_106 -> V_253 = ( char V_254 * ) V_29 -> V_255 ;
F_14 ( V_106 ) ;
return 0 ;
}
static int F_46 ( struct V_256 * V_257 )
{
struct V_28 * V_29 ;
unsigned long V_258 ;
int V_177 , V_30 , V_259 ;
if ( ! V_257 )
return - V_119 ;
for ( V_30 = 0 ; V_30 < V_26 ; ++ V_30 ) {
V_177 = F_2 ( V_43 -> V_44 [ V_30 ] . V_97 ) ;
if ( V_43 -> V_44 [ V_30 ] . V_45 == 0 )
V_43 -> V_44 [ V_30 ] . V_45 = V_47 -> V_48 ;
if ( V_43 -> V_44 [ V_30 ] . V_46 == 0 )
V_43 -> V_44 [ V_30 ] . V_46 = V_47 -> V_49 ;
V_29 = & V_27 [ V_30 ] ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_30 = V_30 ;
V_29 -> V_118 = ( V_43 -> V_44 [ V_30 ] . V_45 * V_43 -> V_44 [ V_30 ] . V_46 * V_177 ) / 8 ;
V_29 -> V_255 = F_47 ( & V_257 -> V_257 ,
F_28 ( V_29 -> V_118 ) ,
& V_29 -> V_52 , V_240 ) ;
if ( ! V_29 -> V_255 ) {
F_42 ( L_18 ,
V_29 -> V_118 / 1024 ) ;
return - V_241 ;
}
for ( V_258 = ( unsigned long ) V_29 -> V_52 ;
V_258 < F_28 ( ( unsigned long ) V_29 -> V_52 +
V_29 -> V_118 ) ;
V_258 += V_260 ) {
F_48 ( F_49 ( V_258 >> V_154 ) ) ;
}
F_16 ( L_19 , V_29 -> V_255 ) ;
F_16 ( L_20 , V_29 -> V_52 , V_29 -> V_118 / 1024 ) ;
if ( ( V_259 = F_40 ( V_29 ) ) < 0 )
goto V_261;
if ( ( V_259 = F_50 ( & V_29 -> V_24 ) ) < 0 ) {
F_42 ( L_21 ) ;
goto V_261;
}
F_22 ( & V_29 -> V_24 ) ;
#if ! F_51 ( V_262 ) && F_51 ( V_263 )
if ( V_30 == 0 )
if ( F_52 ( & V_29 -> V_24 , V_264 ) ) {
F_53 ( & V_29 -> V_24 . V_242 ,
& V_29 -> V_24 ) ;
F_54 ( & V_29 -> V_24 , V_264 ) ;
}
#endif
}
if ( ( V_259 = F_55 ( V_265 , F_39 ,
V_266 | V_267 , L_22 , ( void * ) V_257 ) ) < 0 ) {
F_42 ( L_23 ,
V_265 , V_259 ) ;
goto V_261;
}
return 0 ;
V_261:
if ( V_29 -> V_255 )
F_56 ( V_257 , F_28 ( V_29 -> V_118 ) ,
V_29 -> V_255 , V_29 -> V_52 ) ;
if ( V_29 -> V_24 . V_242 . V_149 != 0 )
F_57 ( & V_29 -> V_24 . V_242 ) ;
if ( V_29 -> V_24 . V_136 )
F_45 ( V_29 -> V_24 . V_136 ) ;
if ( V_30 == 0 )
F_58 ( V_265 , ( void * ) V_257 ) ;
return V_259 ;
}
static int F_59 ( struct V_256 * V_257 )
{
struct V_28 * V_29 ;
int V_30 ;
if ( ! V_257 )
return - V_268 ;
F_7 ( NULL ) ;
for ( V_30 = 0 ; V_30 < V_26 ; ++ V_30 )
{
V_29 = & V_27 [ V_30 ] ;
F_60 ( & V_29 -> V_24 ) ;
if ( V_29 -> V_255 )
F_56 ( & V_257 -> V_257 ,
F_28 ( V_29 -> V_118 ) ,
V_29 -> V_255 , V_29 -> V_52 ) ;
if ( V_29 -> V_24 . V_242 . V_149 != 0 )
F_57 ( & V_29 -> V_24 . V_242 ) ;
if ( V_29 -> V_24 . V_136 )
F_45 ( V_29 -> V_24 . V_136 ) ;
}
F_58 ( V_265 , ( void * ) V_257 ) ;
return 0 ;
}
static int F_61 ( struct V_256 * V_257 , T_3 V_269 )
{
return 0 ;
}
static int F_62 ( struct V_256 * V_257 )
{
return 0 ;
}
static void F_63 ( void )
{
char * V_270 = NULL ;
char * V_271 ;
int V_272 = F_64 ( V_230 ) ;
int V_273 = - 1 ;
F_65 ( V_274 , & V_270 ) ;
if ( V_270 ) {
while ( ( V_271 = F_66 ( & V_270 , L_24 ) ) != NULL ) {
if ( ! strncmp ( V_271 , L_25 , 6 ) ) {
int V_25 ;
long int V_275 ;
char * V_276 ;
V_271 += 6 ;
V_275 = F_67 ( V_271 , & V_276 , 0 ) ;
if ( * V_276 == '\0' ) {
V_273 = ( int ) V_275 ;
}
else if ( strcmp ( V_271 , L_26 ) == 0 ) {
extern int V_277 ( void ) ;
V_273 = V_277 () ;
}
else
for ( V_25 = 0 ; V_25 < V_272 ; V_25 ++ ) {
if ( ! strcmp ( V_271 , V_230 [ V_25 ] . V_62 ) ) {
V_273 = V_25 ;
break;
}
}
if ( ( V_273 < 0 ) || ( V_273 >= V_272 ) ) {
F_68 ( L_27 , V_271 ) ;
}
else
V_229 = V_273 ;
}
else if ( strncmp ( V_271 , L_28 , 10 ) == 0 ) {
V_278 = 1 ;
}
else {
F_68 ( L_29 , V_271 ) ;
}
}
}
}
static int F_69 ( T_6 * V_257 ,
T_7 V_279 , void * V_280 ) {
int V_281 = - 1 ;
unsigned int V_282 = 0 ;
unsigned int V_1 = 0 ;
if ( V_279 == V_283 ) {
F_70 () ;
}
else if ( V_279 == V_284 ) {
if( V_257 -> V_285 == V_286 )
{
int V_30 ;
F_7 ( V_47 ) ;
for ( V_30 = 0 ; V_30 < V_26 ; ++ V_30 ) {
struct V_28 * V_29 ;
V_29 = & V_27 [ V_30 ] ;
F_22 ( & V_29 -> V_24 ) ;
}
}
V_282 = * ( ( unsigned int * ) V_280 ) ;
if( V_282 <= 10 ) V_1 = 26 ;
else if( V_282 <= 20 ) V_1 = 51 ;
else if( V_282 <= 30 ) V_1 = 77 ;
else if( V_282 <= 40 ) V_1 = 102 ;
else if( V_282 <= 50 ) V_1 = 128 ;
else if( V_282 <= 60 ) V_1 = 153 ;
else if( V_282 <= 70 ) V_1 = 179 ;
else if( V_282 <= 80 ) V_1 = 204 ;
else if( V_282 <= 90 ) V_1 = 230 ;
else V_1 = 255 ;
F_1 ( V_1 ) ;
} else if ( V_279 == V_287 ) {
return V_257 -> V_288 ;
} else if ( V_279 == V_289 ) {
if ( V_257 -> V_288 != V_286 )
return V_281 ;
else {
F_7 ( V_47 ) ;
}
} else if ( V_279 == V_290 ) {
} else if ( V_279 == V_291 ) {
}
return V_281 ;
}
static int T_8 F_71 ( void )
{
F_72 ( L_30 V_292 L_30 ) ;
F_63 () ;
V_47 = & V_230 [ V_229 ] ;
V_43 = & V_293 [ V_294 ] ;
F_4 ( V_274 L_31 , V_229 , V_47 -> V_62 ) ;
F_4 ( V_274 L_32 , V_294 , V_43 -> V_62 ) ;
F_7 ( V_47 ) ;
#ifdef F_26
V_152 = F_73 ( L_33 , & F_69 , NULL ) ;
if ( V_152 == NULL )
F_4 ( V_295 L_34 ) ;
else
F_4 ( V_295 L_35 ) ;
#endif
return F_74 ( & V_296 ) ;
}
static void T_9 F_75 ( void )
{
F_76 ( & V_296 ) ;
}
