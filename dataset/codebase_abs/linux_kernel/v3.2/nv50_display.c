static inline int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 < 0x90 ||
V_4 -> V_6 == 0x92 ||
V_4 -> V_6 == 0xa0 )
return 2 ;
return 4 ;
}
int
F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
void
F_3 ( struct V_1 * V_2 )
{
}
int
F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = & V_4 -> V_9 . V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
T_1 V_17 ;
F_5 ( V_2 , L_1 ) ;
F_6 ( V_2 , 0x00610184 , F_7 ( V_2 , 0x00614004 ) ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_17 = F_7 ( V_2 , 0x00616100 + ( V_16 * 0x800 ) ) ;
F_6 ( V_2 , 0x00610190 + ( V_16 * 0x10 ) , V_17 ) ;
V_17 = F_7 ( V_2 , 0x00616104 + ( V_16 * 0x800 ) ) ;
F_6 ( V_2 , 0x00610194 + ( V_16 * 0x10 ) , V_17 ) ;
V_17 = F_7 ( V_2 , 0x00616108 + ( V_16 * 0x800 ) ) ;
F_6 ( V_2 , 0x00610198 + ( V_16 * 0x10 ) , V_17 ) ;
V_17 = F_7 ( V_2 , 0x0061610c + ( V_16 * 0x800 ) ) ;
F_6 ( V_2 , 0x0061019c + ( V_16 * 0x10 ) , V_17 ) ;
}
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
V_17 = F_7 ( V_2 , 0x0061a000 + ( V_16 * 0x800 ) ) ;
F_6 ( V_2 , 0x006101d0 + ( V_16 * 0x04 ) , V_17 ) ;
}
for ( V_16 = 0 ; V_16 < F_1 ( V_2 ) ; V_16 ++ ) {
V_17 = F_7 ( V_2 , 0x0061c000 + ( V_16 * 0x800 ) ) ;
F_6 ( V_2 , 0x006101e0 + ( V_16 * 0x04 ) , V_17 ) ;
}
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
V_17 = F_7 ( V_2 , 0x0061e000 + ( V_16 * 0x800 ) ) ;
F_6 ( V_2 , 0x006101f0 + ( V_16 * 0x04 ) , V_17 ) ;
}
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
F_6 ( V_2 , F_8 ( V_16 ) , 0x00550000 |
V_18 ) ;
F_6 ( V_2 , F_9 ( V_16 ) , 0x00000001 ) ;
}
if ( F_7 ( V_2 , V_19 ) & 0x100 ) {
F_6 ( V_2 , V_19 , 0x100 ) ;
F_6 ( V_2 , 0x006194e8 , F_7 ( V_2 , 0x006194e8 ) & ~ 1 ) ;
if ( ! F_10 ( V_2 , 0x006194e8 , 2 , 0 ) ) {
F_11 ( V_2 , L_2 ) ;
F_11 ( V_2 , L_3 ,
F_7 ( V_2 , 0x6194e8 ) ) ;
return - V_20 ;
}
}
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
F_6 ( V_2 , F_12 ( V_16 ) , 0x2000 ) ;
if ( ! F_10 ( V_2 , F_12 ( V_16 ) ,
V_21 , 0 ) ) {
F_11 ( V_2 , L_4 ) ;
F_11 ( V_2 , L_5 ,
F_7 ( V_2 , F_12 ( V_16 ) ) ) ;
return - V_20 ;
}
F_6 ( V_2 , F_12 ( V_16 ) ,
V_22 ) ;
if ( ! F_10 ( V_2 , F_12 ( V_16 ) ,
V_21 ,
V_23 ) ) {
F_11 ( V_2 , L_6
L_7 , V_16 ) ;
F_11 ( V_2 , L_8 , V_16 ,
F_7 ( V_2 , F_12 ( V_16 ) ) ) ;
return - V_20 ;
}
}
F_6 ( V_2 , V_24 , 0x00000000 ) ;
F_13 ( V_2 , V_25 , 0x00000000 , 0x00000000 ) ;
F_6 ( V_2 , V_26 , 0x00000000 ) ;
F_13 ( V_2 , V_19 , 0x00000000 , 0x00000000 ) ;
F_6 ( V_2 , V_27 ,
V_28 |
V_29 |
V_30 ) ;
F_14 (connector, &dev->mode_config.connector_list, head) {
struct V_31 * V_32 = V_31 ( V_12 ) ;
if ( V_32 -> V_33 -> V_34 == 0xff )
continue;
V_8 -> V_35 ( V_2 , V_32 -> V_33 -> V_34 , true ) ;
}
V_15 = F_15 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_14 = F_16 ( V_2 ) -> V_36 ;
F_6 ( V_2 , V_37 , ( V_14 -> V_38 -> V_39 >> 8 ) | 9 ) ;
V_15 = F_17 ( V_14 , 15 ) ;
if ( V_15 )
return V_15 ;
F_18 ( V_14 , 0 , V_40 , 2 ) ;
F_19 ( V_14 , V_41 ) ;
F_19 ( V_14 , V_42 ) ;
F_18 ( V_14 , 0 , F_20 ( 0 , V_43 ) , 1 ) ;
F_19 ( V_14 , V_44 ) ;
F_18 ( V_14 , 0 , F_20 ( 0 , V_45 ) , 1 ) ;
F_19 ( V_14 , 0 ) ;
F_18 ( V_14 , 0 , F_20 ( 0 , V_46 ) , 1 ) ;
F_19 ( V_14 , 0 ) ;
F_18 ( V_14 , 0 , F_20 ( 0 , V_47 ) , 1 ) ;
F_19 ( V_14 , 0 ) ;
F_18 ( V_14 , 0 , F_20 ( 0 , V_48 ) , 1 ) ;
F_19 ( V_14 , 0x00000311 ) ;
F_18 ( V_14 , 0 , F_20 ( 1 , V_48 ) , 1 ) ;
F_19 ( V_14 , 0x00000311 ) ;
F_21 ( V_14 ) ;
if ( ! F_10 ( V_2 , 0x640004 , 0xffffffff , V_14 -> V_49 . V_50 << 2 ) )
F_11 ( V_2 , L_9 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct F_16 * V_51 = F_16 ( V_2 ) ;
struct V_13 * V_14 = V_51 -> V_36 ;
struct V_52 * V_52 ;
int V_15 , V_16 ;
F_5 ( V_2 , L_1 ) ;
F_14 (drm_crtc, &dev->mode_config.crtc_list, head) {
struct V_53 * V_54 = V_53 ( V_52 ) ;
F_23 ( V_54 , true ) ;
}
V_15 = F_17 ( V_14 , 2 ) ;
if ( V_15 == 0 ) {
F_18 ( V_14 , 0 , V_55 , 1 ) ;
F_19 ( V_14 , 0 ) ;
}
F_21 ( V_14 ) ;
F_14 (drm_crtc, &dev->mode_config.crtc_list, head) {
struct V_53 * V_54 = V_53 ( V_52 ) ;
T_2 V_56 = F_24 ( V_54 -> V_57 ) ;
if ( ! V_54 -> V_58 . V_59 )
continue;
F_6 ( V_2 , V_19 , V_56 ) ;
if ( ! F_10 ( V_2 , V_19 , V_56 , V_56 ) ) {
F_11 ( V_2 , L_10
L_11 , V_56 , V_56 ) ;
F_11 ( V_2 , L_12 ,
F_7 ( V_2 , V_19 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
F_6 ( V_2 , F_12 ( V_16 ) , 0 ) ;
if ( ! F_10 ( V_2 , F_12 ( V_16 ) ,
V_21 , 0 ) ) {
F_11 ( V_2 , L_4 ) ;
F_11 ( V_2 , L_5 ,
F_7 ( V_2 , F_12 ( V_16 ) ) ) ;
}
}
F_25 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
if ( ! F_10 ( V_2 , F_26 ( V_16 ) ,
V_60 , 0 ) ) {
F_11 ( V_2 , L_13 , V_16 ) ;
F_11 ( V_2 , L_14 , V_16 ,
F_7 ( V_2 , F_26 ( V_16 ) ) ) ;
}
}
F_6 ( V_2 , V_27 , 0x00000000 ) ;
F_6 ( V_2 , 0xe054 , 0xffffffff ) ;
F_6 ( V_2 , 0xe050 , 0x00000000 ) ;
if ( V_4 -> V_6 >= 0x90 ) {
F_6 ( V_2 , 0xe074 , 0xffffffff ) ;
F_6 ( V_2 , 0xe070 , 0x00000000 ) ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_61 * V_33 = & V_4 -> V_62 . V_33 ;
struct V_11 * V_12 , * V_63 ;
struct F_16 * V_64 ;
int V_15 , V_16 ;
F_5 ( V_2 , L_1 ) ;
V_64 = F_28 ( sizeof( * V_64 ) , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
V_4 -> V_9 . V_67 . V_64 = V_64 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_29 ( V_2 , V_16 ) ;
for ( V_16 = 0 ; V_16 < V_33 -> V_68 ; V_16 ++ ) {
struct V_69 * V_70 = & V_33 -> V_70 [ V_16 ] ;
if ( V_70 -> V_71 != V_72 ) {
F_30 ( V_2 , L_15 ,
V_70 -> type , F_31 ( V_70 -> V_73 ) - 1 ) ;
continue;
}
V_12 = F_32 ( V_2 , V_70 -> V_12 ) ;
if ( F_33 ( V_12 ) )
continue;
switch ( V_70 -> type ) {
case V_74 :
case V_75 :
case V_76 :
F_34 ( V_12 , V_70 ) ;
break;
case V_77 :
F_35 ( V_12 , V_70 ) ;
break;
default:
F_30 ( V_2 , L_16 , V_70 -> type ) ;
continue;
}
}
F_36 (connector, ct,
&dev->mode_config.connector_list, head) {
if ( ! V_12 -> V_78 [ 0 ] ) {
F_30 ( V_2 , L_17 ,
F_37 ( V_12 ) ) ;
V_12 -> V_79 -> V_80 ( V_12 ) ;
}
}
F_38 ( & V_64 -> V_81 , V_82 , ( unsigned long ) V_2 ) ;
F_39 ( V_2 , 26 , V_83 ) ;
V_15 = F_4 ( V_2 ) ;
if ( V_15 ) {
F_40 ( V_2 ) ;
return V_15 ;
}
return 0 ;
}
void
F_40 ( struct V_1 * V_2 )
{
struct F_16 * V_51 = F_16 ( V_2 ) ;
F_5 ( V_2 , L_1 ) ;
F_22 ( V_2 ) ;
F_41 ( V_2 , 26 ) ;
F_42 ( V_51 ) ;
}
void
F_43 ( struct V_52 * V_54 )
{
struct F_16 * V_51 = F_16 ( V_54 -> V_2 ) ;
struct V_53 * V_84 = V_53 ( V_54 ) ;
struct V_85 * V_86 = & V_51 -> V_54 [ V_84 -> V_57 ] ;
struct V_13 * V_14 = V_86 -> V_87 ;
int V_15 ;
V_15 = F_17 ( V_14 , 8 ) ;
if ( V_15 ) {
F_44 ( 1 ) ;
return;
}
F_18 ( V_14 , 0 , 0x0084 , 1 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_18 ( V_14 , 0 , 0x0094 , 1 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_18 ( V_14 , 0 , 0x00c0 , 1 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_18 ( V_14 , 0 , 0x0080 , 1 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_21 ( V_14 ) ;
}
int
F_45 ( struct V_52 * V_54 , struct V_88 * V_89 ,
struct V_13 * V_90 )
{
struct V_3 * V_4 = V_54 -> V_2 -> V_5 ;
struct V_91 * V_92 = V_91 ( V_89 ) ;
struct F_16 * V_51 = F_16 ( V_54 -> V_2 ) ;
struct V_53 * V_84 = V_53 ( V_54 ) ;
struct V_85 * V_86 = & V_51 -> V_54 [ V_84 -> V_57 ] ;
struct V_13 * V_14 = V_86 -> V_87 ;
int V_15 ;
V_15 = F_17 ( V_14 , V_90 ? 25 : 27 ) ;
if ( F_46 ( V_15 ) )
return V_15 ;
if ( F_47 ( V_90 ) ) {
V_15 = F_17 ( V_90 , 10 ) ;
if ( V_15 ) {
F_48 ( V_14 ) ;
return V_15 ;
}
if ( V_4 -> V_6 < 0xc0 ) {
F_18 ( V_90 , V_93 , 0x0060 , 2 ) ;
F_19 ( V_90 , V_94 + V_84 -> V_57 ) ;
F_19 ( V_90 , V_86 -> V_95 . V_96 ) ;
F_18 ( V_90 , V_93 , 0x006c , 1 ) ;
F_19 ( V_90 , 0xf00d0000 | V_86 -> V_95 . V_97 ) ;
F_18 ( V_90 , V_93 , 0x0064 , 2 ) ;
F_19 ( V_90 , V_86 -> V_95 . V_96 ^ 0x10 ) ;
F_19 ( V_90 , 0x74b1e000 ) ;
F_18 ( V_90 , V_93 , 0x0060 , 1 ) ;
if ( V_4 -> V_6 < 0x84 )
F_19 ( V_90 , V_98 ) ;
else
F_19 ( V_90 , V_90 -> V_99 ) ;
} else {
T_3 V_96 = V_90 -> V_100 [ V_84 -> V_57 ] . V_96 ;
V_96 += V_86 -> V_95 . V_96 ;
F_49 ( V_90 , 2 , V_101 , 0x0010 , 4 ) ;
F_19 ( V_90 , F_50 ( V_96 ) ) ;
F_19 ( V_90 , F_51 ( V_96 ) ) ;
F_19 ( V_90 , 0xf00d0000 | V_86 -> V_95 . V_97 ) ;
F_19 ( V_90 , 0x1002 ) ;
F_49 ( V_90 , 2 , V_101 , 0x0010 , 4 ) ;
F_19 ( V_90 , F_50 ( V_96 ) ) ;
F_19 ( V_90 , F_51 ( V_96 ^ 0x10 ) ) ;
F_19 ( V_90 , 0x74b1e000 ) ;
F_19 ( V_90 , 0x1001 ) ;
}
F_21 ( V_90 ) ;
} else {
F_52 ( V_86 -> V_95 . V_102 , V_86 -> V_95 . V_96 / 4 ,
0xf00d0000 | V_86 -> V_95 . V_97 ) ;
}
F_18 ( V_14 , 0 , 0x0100 , 1 ) ;
F_19 ( V_14 , 0xfffe0000 ) ;
if ( V_90 ) {
F_18 ( V_14 , 0 , 0x0084 , 1 ) ;
F_19 ( V_14 , 0x00000100 ) ;
} else {
F_18 ( V_14 , 0 , 0x0084 , 1 ) ;
F_19 ( V_14 , 0x00000010 ) ;
F_18 ( V_14 , 0 , 0x00e0 , 1 ) ;
F_19 ( V_14 , 0x40000000 ) ;
}
F_18 ( V_14 , 0 , 0x0088 , 4 ) ;
F_19 ( V_14 , V_86 -> V_95 . V_96 ) ;
F_19 ( V_14 , 0xf00d0000 | V_86 -> V_95 . V_97 ) ;
F_19 ( V_14 , 0x74b1e000 ) ;
F_19 ( V_14 , V_42 ) ;
F_18 ( V_14 , 0 , 0x00a0 , 2 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_18 ( V_14 , 0 , 0x00c0 , 1 ) ;
F_19 ( V_14 , V_92 -> V_103 ) ;
F_18 ( V_14 , 0 , 0x0110 , 2 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_18 ( V_14 , 0 , 0x0800 , 5 ) ;
F_19 ( V_14 , V_92 -> V_104 -> V_102 . V_96 >> 8 ) ;
F_19 ( V_14 , 0 ) ;
F_19 ( V_14 , ( V_89 -> V_105 << 16 ) | V_89 -> V_106 ) ;
F_19 ( V_14 , V_92 -> V_107 ) ;
F_19 ( V_14 , V_92 -> V_108 ) ;
F_18 ( V_14 , 0 , 0x0080 , 1 ) ;
F_19 ( V_14 , 0x00000000 ) ;
F_21 ( V_14 ) ;
V_86 -> V_95 . V_96 ^= 0x10 ;
V_86 -> V_95 . V_97 ++ ;
return 0 ;
}
static T_4
F_53 ( struct V_1 * V_2 , struct V_69 * V_33 ,
T_1 V_109 , int V_110 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_111 = NULL ;
struct V_112 * V_113 ;
struct V_114 * V_115 = & V_4 -> V_62 ;
T_1 V_116 = 0 , V_73 ;
F_14 (encoder, &dev->mode_config.encoder_list, head) {
struct V_117 * V_118 = V_117 ( V_113 ) ;
if ( V_118 -> V_33 != V_33 )
continue;
V_111 = F_54 ( V_118 ) ;
break;
}
V_73 = F_31 ( V_33 -> V_73 ) - 1 ;
switch ( V_33 -> type ) {
case V_75 :
V_116 = ( V_109 >> 8 ) & 0xf ;
if ( V_115 -> V_119 ) {
if ( V_115 -> V_120 . V_121 )
V_116 |= 0x0100 ;
if ( V_115 -> V_120 . V_122 )
V_116 |= 0x0200 ;
} else {
if ( V_111 && V_111 -> V_123 &&
V_111 -> V_33 -> type == V_124 ) {
if ( ( ( V_125 * ) V_111 -> V_123 ) [ 121 ] == 2 )
V_116 |= 0x0100 ;
} else
if ( V_110 >= V_115 -> V_120 . V_126 ) {
V_116 |= 0x0100 ;
}
if ( V_116 & 0x0100 ) {
if ( V_115 -> V_120 . V_127 & 2 )
V_116 |= 0x0200 ;
} else {
if ( V_115 -> V_120 . V_127 & 1 )
V_116 |= 0x0200 ;
}
if ( V_111 && V_111 -> V_123 &&
( V_111 -> V_123 -> V_128 >= 4 ) &&
( V_111 -> V_123 -> V_129 & 0x70 ) >= 0x20 )
V_116 |= 0x0200 ;
}
if ( V_130 >= 0 ) {
F_55 ( V_2 , L_18
L_19 , V_116 ,
V_130 , V_73 ) ;
V_116 = V_130 ;
}
break;
case V_74 :
V_116 = ( V_109 >> 8 ) & 0xf ;
if ( V_110 >= 165000 )
V_116 |= 0x0100 ;
if ( V_131 >= 0 ) {
F_55 ( V_2 , L_18
L_20 , V_116 ,
V_131 , V_73 ) ;
V_116 = V_131 ;
}
break;
case V_76 :
V_116 = ( V_109 >> 8 ) & 0xf ;
break;
case V_77 :
V_116 = 0xff ;
break;
default:
F_11 ( V_2 , L_21 ) ;
break;
}
return V_116 ;
}
static void
F_56 ( struct V_1 * V_2 , int V_54 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_90 , * V_132 ;
F_36 (chan, tmp, &dev_priv->vbl_waiting,
nvsw.vbl_wait) {
if ( V_90 -> V_133 . V_134 != V_54 )
continue;
F_52 ( V_90 -> V_135 , V_90 -> V_133 . V_136 ,
V_90 -> V_133 . V_137 ) ;
F_57 ( & V_90 -> V_133 . V_138 ) ;
F_58 ( V_2 , V_54 ) ;
}
F_59 ( V_2 , V_54 ) ;
}
static void
F_60 ( struct V_1 * V_2 , T_2 V_139 )
{
if ( V_139 & V_140 )
F_56 ( V_2 , 0 ) ;
if ( V_139 & V_141 )
F_56 ( V_2 , 1 ) ;
F_6 ( V_2 , V_19 , V_142 ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct F_16 * V_51 = F_16 ( V_2 ) ;
T_1 V_143 = F_7 ( V_2 , 0x610030 ) , V_109 ;
int V_16 , V_54 , V_73 = 0 , type = V_144 ;
F_5 ( V_2 , L_22 , V_143 ) ;
V_51 -> V_145 . V_33 = NULL ;
F_6 ( V_2 , 0x619494 , F_7 ( V_2 , 0x619494 ) & ~ 8 ) ;
V_54 = F_31 ( ( V_143 & 0x00000060 ) >> 5 ) - 1 ;
if ( V_54 < 0 )
goto V_146;
V_54 = F_31 ( ( V_143 & 0x00000180 ) >> 7 ) - 1 ;
if ( V_54 < 0 )
goto V_146;
for ( V_16 = 0 ; type == V_144 && V_16 < 3 ; V_16 ++ ) {
V_109 = F_7 ( V_2 , F_62 ( V_16 ) ) ;
F_5 ( V_2 , L_23 , V_16 , V_109 ) ;
if ( ! ( V_109 & ( 1 << V_54 ) ) )
continue;
switch ( ( V_109 & 0x00000f00 ) >> 8 ) {
case 0 : type = V_77 ; break;
case 1 : type = V_147 ; break;
default:
F_11 ( V_2 , L_24 , V_16 , V_109 ) ;
goto V_146;
}
V_73 = V_16 ;
}
for ( V_16 = 0 ; type == V_144 && V_16 < F_1 ( V_2 ) ; V_16 ++ ) {
if ( V_4 -> V_6 < 0x90 ||
V_4 -> V_6 == 0x92 ||
V_4 -> V_6 == 0xa0 )
V_109 = F_7 ( V_2 , F_63 ( V_16 ) ) ;
else
V_109 = F_7 ( V_2 , F_64 ( V_16 ) ) ;
F_5 ( V_2 , L_25 , V_16 , V_109 ) ;
if ( ! ( V_109 & ( 1 << V_54 ) ) )
continue;
switch ( ( V_109 & 0x00000f00 ) >> 8 ) {
case 0 : type = V_75 ; break;
case 1 : type = V_74 ; break;
case 2 : type = V_74 ; break;
case 5 : type = V_74 ; break;
case 8 : type = V_76 ; break;
case 9 : type = V_76 ; break;
default:
F_11 ( V_2 , L_26 , V_16 , V_109 ) ;
goto V_146;
}
V_73 = V_16 ;
}
if ( type == V_144 )
goto V_146;
for ( V_16 = 0 ; V_16 < V_4 -> V_62 . V_33 . V_68 ; V_16 ++ ) {
struct V_69 * V_33 = & V_4 -> V_62 . V_33 . V_70 [ V_16 ] ;
if ( V_33 -> type == type && ( V_33 -> V_73 & ( 1 << V_73 ) ) ) {
F_65 ( V_2 , 0 , - 1 , V_33 , - 1 ) ;
V_51 -> V_145 . V_33 = V_33 ;
goto V_146;
}
}
F_11 ( V_2 , L_27 , V_73 , type , V_109 ) ;
V_146:
F_6 ( V_2 , V_19 , V_148 ) ;
F_6 ( V_2 , 0x610030 , 0x80000000 ) ;
}
static void
F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct F_16 * V_51 = F_16 ( V_2 ) ;
T_1 V_143 = F_7 ( V_2 , 0x610030 ) , V_132 , V_149 , V_116 , V_109 = 0 ;
struct V_69 * V_33 ;
int V_16 , V_54 , V_73 = 0 , type = V_144 ;
F_5 ( V_2 , L_22 , V_143 ) ;
V_33 = V_51 -> V_145 . V_33 ;
if ( V_33 ) {
F_65 ( V_2 , 0 , - 2 , V_33 , - 1 ) ;
V_51 -> V_145 . V_33 = NULL ;
}
V_54 = F_31 ( ( V_143 & 0x00000600 ) >> 9 ) - 1 ;
if ( V_54 >= 0 ) {
V_149 = F_7 ( V_2 , F_67 ( V_54 , CLOCK ) ) ;
V_149 &= 0x003fffff ;
F_68 ( V_2 , V_54 , V_149 ) ;
V_132 = F_7 ( V_2 , F_69 ( V_54 ) ) ;
V_132 &= ~ 0x000000f ;
F_6 ( V_2 , F_69 ( V_54 ) , V_132 ) ;
}
V_54 = F_31 ( ( V_143 & 0x00000180 ) >> 7 ) - 1 ;
if ( V_54 < 0 )
goto V_146;
V_149 = F_7 ( V_2 , F_67 ( V_54 , CLOCK ) ) & 0x003fffff ;
for ( V_16 = 0 ; type == V_144 && V_16 < 3 ; V_16 ++ ) {
V_109 = F_7 ( V_2 , F_70 ( V_16 ) ) ;
F_5 ( V_2 , L_23 , V_16 , V_109 ) ;
if ( ! ( V_109 & ( 1 << V_54 ) ) )
continue;
switch ( ( V_109 & 0x00000f00 ) >> 8 ) {
case 0 : type = V_77 ; break;
case 1 : type = V_147 ; break;
default:
F_11 ( V_2 , L_24 , V_16 , V_109 ) ;
goto V_146;
}
V_73 = V_16 ;
}
for ( V_16 = 0 ; type == V_144 && V_16 < F_1 ( V_2 ) ; V_16 ++ ) {
if ( V_4 -> V_6 < 0x90 ||
V_4 -> V_6 == 0x92 ||
V_4 -> V_6 == 0xa0 )
V_109 = F_7 ( V_2 , F_71 ( V_16 ) ) ;
else
V_109 = F_7 ( V_2 , F_72 ( V_16 ) ) ;
F_5 ( V_2 , L_25 , V_16 , V_109 ) ;
if ( ! ( V_109 & ( 1 << V_54 ) ) )
continue;
switch ( ( V_109 & 0x00000f00 ) >> 8 ) {
case 0 : type = V_75 ; break;
case 1 : type = V_74 ; break;
case 2 : type = V_74 ; break;
case 5 : type = V_74 ; break;
case 8 : type = V_76 ; break;
case 9 : type = V_76 ; break;
default:
F_11 ( V_2 , L_26 , V_16 , V_109 ) ;
goto V_146;
}
V_73 = V_16 ;
}
if ( type == V_144 )
goto V_146;
for ( V_16 = 0 ; V_16 < V_4 -> V_62 . V_33 . V_68 ; V_16 ++ ) {
V_33 = & V_4 -> V_62 . V_33 . V_70 [ V_16 ] ;
if ( V_33 -> type == type && ( V_33 -> V_73 & ( 1 << V_73 ) ) )
break;
}
if ( V_16 == V_4 -> V_62 . V_33 . V_68 ) {
F_11 ( V_2 , L_27 , V_73 , type , V_109 ) ;
goto V_146;
}
V_116 = F_53 ( V_2 , V_33 , V_109 , V_149 ) ;
F_65 ( V_2 , V_116 , V_149 , V_33 , - 1 ) ;
if ( type == V_76 ) {
int V_150 = ! ( V_33 -> V_151 . V_152 . V_150 & 1 ) ;
if ( ( V_109 & 0x000f0000 ) == 0x00020000 )
F_73 ( V_2 , V_73 , V_150 , V_149 , 18 ) ;
else
F_73 ( V_2 , V_73 , V_150 , V_149 , 24 ) ;
}
if ( V_33 -> type != V_77 ) {
V_132 = F_7 ( V_2 , F_74 ( V_73 ) ) ;
V_132 &= ~ 0x00000f0f ;
if ( V_116 & 0x0100 )
V_132 |= 0x00000101 ;
F_6 ( V_2 , F_74 ( V_73 ) , V_132 ) ;
} else {
F_6 ( V_2 , F_75 ( V_73 ) , 0 ) ;
}
V_51 -> V_145 . V_33 = V_33 ;
V_51 -> V_145 . V_149 = V_149 ;
V_51 -> V_145 . V_116 = V_116 ;
V_146:
F_6 ( V_2 , V_19 , V_153 ) ;
F_6 ( V_2 , 0x610030 , 0x80000000 ) ;
}
static void
F_76 ( struct V_1 * V_2 , struct V_69 * V_33 )
{
int V_73 = F_31 ( V_33 -> V_73 ) - 1 , V_150 = ! ( V_33 -> V_151 . V_152 . V_150 & 1 ) ;
struct V_112 * V_113 ;
T_1 V_132 ;
if ( V_33 -> type != V_74 )
return;
F_14 (encoder, &dev->mode_config.encoder_list, head) {
struct V_117 * V_118 = V_117 ( V_113 ) ;
if ( V_118 -> V_33 -> type == V_76 &&
V_118 -> V_33 -> V_73 & ( 1 << V_73 ) ) {
V_132 = F_7 ( V_2 , F_77 ( V_73 , V_150 ) ) ;
V_132 &= ~ V_154 ;
F_6 ( V_2 , F_77 ( V_73 , V_150 ) , V_132 ) ;
break;
}
}
}
static void
F_78 ( struct V_1 * V_2 )
{
struct F_16 * V_51 = F_16 ( V_2 ) ;
struct V_69 * V_33 = V_51 -> V_145 . V_33 ;
T_4 V_116 = V_51 -> V_145 . V_116 ;
T_1 V_143 = F_7 ( V_2 , 0x610030 ) , V_149 = V_51 -> V_145 . V_149 ;
F_5 ( V_2 , L_22 , V_143 ) ;
V_51 -> V_145 . V_33 = NULL ;
if ( ! V_33 )
goto V_146;
F_65 ( V_2 , V_116 , - V_149 , V_33 , - 1 ) ;
F_76 ( V_2 , V_33 ) ;
V_146:
F_6 ( V_2 , V_19 , V_155 ) ;
F_6 ( V_2 , 0x610030 , 0x80000000 ) ;
F_6 ( V_2 , 0x619494 , F_7 ( V_2 , 0x619494 ) | 8 ) ;
}
static void
V_82 ( unsigned long V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_156 ;
for (; ; ) {
T_2 V_157 = F_7 ( V_2 , V_25 ) ;
T_2 V_158 = F_7 ( V_2 , V_19 ) ;
F_5 ( V_2 , L_28 , V_157 , V_158 ) ;
if ( V_158 & V_148 )
F_61 ( V_2 ) ;
else
if ( V_158 & V_153 )
F_66 ( V_2 ) ;
else
if ( V_158 & V_155 )
F_78 ( V_2 ) ;
else
break;
}
F_6 ( V_2 , V_159 , 1 ) ;
}
static void
F_79 ( struct V_1 * V_2 )
{
T_1 V_160 = ( F_7 ( V_2 , V_25 ) & 0x001f0000 ) >> 16 ;
T_1 V_161 , V_156 ;
int V_162 ;
for ( V_162 = 0 ; V_162 < 5 ; V_162 ++ ) {
if ( ! ( V_160 & ( 1 << V_162 ) ) )
continue;
F_6 ( V_2 , V_25 , 0x00010000 << V_162 ) ;
V_161 = F_7 ( V_2 , F_80 ( V_162 ) ) ;
V_156 = F_7 ( V_2 , F_81 ( V_162 ) ) ;
F_11 ( V_2 , L_29
L_30 , V_162 ,
V_161 & 0xffc , V_156 , V_161 >> 16 , ( V_161 >> 12 ) & 0xf ) ;
F_6 ( V_2 , F_80 ( V_162 ) , 0x90000000 ) ;
}
}
static void
V_83 ( struct V_1 * V_2 )
{
struct F_16 * V_51 = F_16 ( V_2 ) ;
T_2 V_163 = 0 ;
while ( F_7 ( V_2 , V_164 ) & V_165 ) {
T_2 V_157 = F_7 ( V_2 , V_25 ) ;
T_2 V_158 = F_7 ( V_2 , V_19 ) ;
T_2 clock ;
F_5 ( V_2 , L_31 , V_157 , V_158 ) ;
if ( ! V_157 && ! ( V_158 & ~ V_163 ) )
break;
if ( V_157 & 0x001f0000 ) {
F_79 ( V_2 ) ;
V_157 &= ~ 0x001f0000 ;
}
if ( V_158 & V_142 ) {
F_60 ( V_2 , V_158 ) ;
V_158 &= ~ V_142 ;
}
clock = ( V_158 & ( V_148 |
V_153 |
V_155 ) ) ;
if ( clock ) {
F_6 ( V_2 , V_159 , 0 ) ;
F_82 ( & V_51 -> V_81 ) ;
V_163 |= clock ;
V_158 &= ~ clock ;
}
if ( V_157 ) {
F_11 ( V_2 , L_32 , V_157 ) ;
F_6 ( V_2 , V_25 , V_157 ) ;
}
if ( V_158 ) {
F_11 ( V_2 ,
L_33 , V_158 ) ;
F_6 ( V_2 , V_19 , V_158 ) ;
}
}
}
