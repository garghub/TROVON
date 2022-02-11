static void F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_1 * V_4 ,
int V_5 )
{
int V_6 = V_3 - V_7 ;
if ( V_6 < 0 ) {
V_5 += V_6 ;
V_6 = 0 ;
}
if ( V_5 <= 0 )
return;
if ( V_5 > V_8 - V_6 )
V_5 = V_8 - V_6 ;
F_2 ( L_1 ,
V_9 , V_6 + V_7 , V_5 , V_5 , V_4 ) ;
memcpy ( & V_2 -> V_10 [ V_6 ] , V_4 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , const T_1 * V_4 ,
int V_5 )
{
int V_11 , V_12 , V_13 = 0 ;
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
do {
if ( V_5 > V_2 -> V_14 -> V_15 - 1 )
V_12 = V_2 -> V_14 -> V_15 - 1 ;
else
V_12 = V_5 ;
V_2 -> V_16 [ 0 ] = V_3 ;
memcpy ( & V_2 -> V_16 [ 1 ] , & V_4 [ V_13 ] , V_12 ) ;
V_11 = F_4 ( & V_2 -> V_17 , V_2 -> V_16 , V_12 + 1 ) ;
if ( V_11 != V_12 + 1 ) {
F_5 ( L_2 ,
V_9 , V_11 , V_3 , V_12 , V_12 , & V_2 -> V_16 [ 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
return - V_18 ;
}
F_2 ( L_3 ,
V_9 , V_3 , V_12 , V_12 , & V_2 -> V_16 [ 1 ] ) ;
V_3 += V_12 ;
V_5 -= V_12 ;
V_13 += V_12 ;
} while ( V_5 > 0 );
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_3 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 )
{
V_3 -= V_7 ;
if ( V_3 >= 0 && V_3 < V_8 )
return V_2 -> V_10 [ V_3 ] ;
else
return - V_19 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_20 )
{
int V_11 = F_7 ( V_2 , V_3 ) ;
if ( V_11 < 0 )
return V_11 ;
V_4 = ( V_11 & ~ V_20 ) | ( V_4 & V_20 ) ;
return F_3 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_11 , V_21 ;
T_1 * V_22 = & V_2 -> V_16 [ 1 ] ;
V_2 -> V_16 [ 0 ] = V_3 ;
V_11 = F_10 ( & V_2 -> V_17 , V_2 -> V_16 , 1 , V_22 , V_5 ) ;
if ( V_11 != V_5 ) {
F_5 ( L_4 ,
V_9 , V_11 , V_3 , V_5 , V_5 , V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
return - V_18 ;
}
for ( V_21 = 0 ; V_21 < V_5 ; V_21 ++ )
V_4 [ V_21 ] = F_11 ( V_22 [ V_21 ] ) ;
F_2 ( L_5 ,
V_9 , V_3 , V_5 , V_5 , V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_23 )
{
const struct V_24 * V_25 ;
int V_21 , V_11 ;
T_1 V_4 , V_26 , V_27 ;
V_23 = V_23 / 1000000 ;
for ( V_21 = 0 ; V_21 < F_13 ( V_28 ) - 1 ; V_21 ++ ) {
if ( V_23 < V_28 [ V_21 + 1 ] . V_23 )
break;
}
V_25 = & V_28 [ V_21 ] ;
F_2 ( L_6 , V_21 , V_23 ) ;
V_11 = F_8 ( V_2 , 0x17 , V_25 -> V_29 , 0x08 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1a , V_25 -> V_30 , 0xc3 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x1b , V_25 -> V_31 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_2 -> V_32 ) {
case V_33 :
case V_34 :
V_4 = V_25 -> V_35 | 0x08 ;
break;
case V_36 :
V_4 = V_25 -> V_37 | 0x08 ;
break;
case V_38 :
V_4 = V_25 -> V_39 | 0x00 ;
break;
default:
case V_40 :
V_4 = V_25 -> V_39 | 0x08 ;
break;
}
V_11 = F_8 ( V_2 , 0x10 , V_4 , 0x0b ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_2 -> V_41 ) {
V_26 = V_2 -> V_42 [ V_25 -> V_43 ] . V_44 ;
V_27 = V_2 -> V_42 [ V_25 -> V_43 ] . V_45 ;
} else {
V_26 = 0 ;
V_27 = 0 ;
}
V_11 = F_8 ( V_2 , 0x08 , V_26 , 0x3f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x09 , V_27 , 0x3f ) ;
return V_11 ;
}
static int F_14 ( struct V_1 * V_2 , enum V_46 type ,
T_2 V_23 )
{
T_2 V_47 ;
int V_11 , V_21 ;
unsigned V_48 = 10000 ;
T_2 V_49 ;
T_2 V_50 = 1770000 ;
T_2 V_51 = V_50 * 2 ;
T_2 V_52 ;
T_3 V_53 = 2 ;
T_3 V_54 = 0 ;
T_1 V_55 = 2 ;
T_1 V_56 = 0 ;
T_1 V_57 = 0 ;
T_1 V_58 = 0 ;
T_1 V_59 , V_60 , V_61 , V_62 , V_4 ;
T_1 V_63 [ 5 ] ;
V_23 = V_23 / 1000 ;
V_52 = V_2 -> V_14 -> V_64 / 1000 ;
#if 0
if ((priv->cfg->rafael_chip == CHIP_R620D) ||
(priv->cfg->rafael_chip == CHIP_R828D) ||
(priv->cfg->rafael_chip == CHIP_R828)) {
if (type != V4L2_TUNER_DIGITAL_TV) {
pll_ref /= 2;
refdiv2 = 0x10;
sleep_time = 20000;
}
} else {
if (priv->cfg->xtal > 24000000) {
pll_ref /= 2;
refdiv2 = 0x10;
}
}
#endif
V_11 = F_8 ( V_2 , 0x10 , V_58 , 0x10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1a , 0x00 , 0x0c ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x12 , 0x80 , 0xe0 ) ;
if ( V_11 < 0 )
return V_11 ;
while ( V_55 <= 64 ) {
if ( ( ( V_23 * V_55 ) >= V_50 ) &&
( ( V_23 * V_55 ) < V_51 ) ) {
V_56 = V_55 ;
while ( V_56 > 2 ) {
V_56 = V_56 >> 1 ;
V_57 ++ ;
}
break;
}
V_55 = V_55 << 1 ;
}
V_11 = F_9 ( V_2 , 0x00 , V_63 , sizeof( V_63 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_62 = ( V_63 [ 4 ] & 0x30 ) >> 4 ;
F_2 ( L_7 ,
V_55 , V_57 , V_62 ) ;
if ( V_2 -> V_14 -> V_65 != V_66 ) {
if ( V_62 > V_67 )
V_57 = V_57 - 1 ;
else if ( V_62 < V_67 )
V_57 = V_57 + 1 ;
}
V_11 = F_8 ( V_2 , 0x10 , V_57 << 5 , 0xe0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_47 = V_23 * V_55 ;
V_61 = V_47 / ( 2 * V_52 ) ;
V_49 = V_47 - 2 * V_52 * V_61 ;
if ( V_49 < V_52 / 64 ) {
V_49 = 0 ;
} else if ( V_49 > V_52 * 127 / 64 ) {
V_49 = 0 ;
V_61 ++ ;
} else if ( ( V_49 > V_52 * 127 / 128 ) && ( V_49 < V_52 ) ) {
V_49 = V_52 * 127 / 128 ;
} else if ( ( V_49 > V_52 ) && ( V_49 < V_52 * 129 / 128 ) ) {
V_49 = V_52 * 129 / 128 ;
}
V_59 = ( V_61 - 13 ) / 4 ;
V_60 = V_61 - 4 * V_59 - 13 ;
V_11 = F_6 ( V_2 , 0x14 , V_59 + ( V_60 << 6 ) ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! V_49 )
V_4 = 0x08 ;
else
V_4 = 0x00 ;
V_11 = F_8 ( V_2 , 0x12 , V_4 , 0x08 ) ;
if ( V_11 < 0 )
return V_11 ;
while ( V_49 > 1 ) {
if ( V_49 > ( 2 * V_52 / V_53 ) ) {
V_54 = V_54 + 32768 / ( V_53 / 2 ) ;
V_49 = V_49 - 2 * V_52 / V_53 ;
if ( V_53 >= 0x8000 )
break;
}
V_53 = V_53 << 1 ;
}
F_2 ( L_8 ,
V_23 , V_52 , V_58 ? L_9 : L_10 , V_54 ) ;
V_11 = F_6 ( V_2 , 0x16 , V_54 >> 8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x15 , V_54 & 0xff ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
F_15 ( V_48 , V_48 + 1000 ) ;
V_11 = F_9 ( V_2 , 0x00 , V_63 , 3 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_63 [ 2 ] & 0x40 )
break;
if ( ! V_21 ) {
V_11 = F_8 ( V_2 , 0x12 , 0x60 , 0xe0 ) ;
if ( V_11 < 0 )
return V_11 ;
}
}
if ( ! ( V_63 [ 2 ] & 0x40 ) ) {
V_2 -> V_68 = false ;
return 0 ;
}
V_2 -> V_68 = true ;
F_2 ( L_11 , V_23 ) ;
V_11 = F_8 ( V_2 , 0x1a , 0x08 , 0x08 ) ;
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_23 ,
enum V_46 type ,
T_4 V_69 ,
T_2 V_70 )
{
int V_11 ;
T_1 V_71 , V_72 , V_73 , V_74 , V_75 , V_76 ;
T_1 V_77 , V_78 , V_79 , V_80 , V_81 ;
F_2 ( L_12 ) ;
switch ( V_70 ) {
case V_82 :
if ( ( V_23 == 506000000 ) || ( V_23 == 666000000 ) ||
( V_23 == 818000000 ) ) {
V_71 = 0x14 ;
V_72 = 0xe5 ;
V_73 = 0x28 ;
V_74 = 0x20 ;
} else {
V_71 = 0x24 ;
V_72 = 0xe5 ;
V_73 = 0x38 ;
V_74 = 0x30 ;
}
V_75 = 0x53 ;
V_76 = 0x75 ;
V_77 = 0x00 ;
V_78 = 0x00 ;
V_79 = 0x40 ;
V_80 = 14 ;
V_81 = 0x40 ;
break;
case V_83 :
V_71 = 0x24 ;
V_72 = 0xe5 ;
V_75 = 0x53 ;
V_76 = 0x75 ;
V_77 = 0x00 ;
V_78 = 0x00 ;
V_79 = 0x40 ;
V_80 = 14 ;
V_73 = 0x38 ;
V_74 = 0x30 ;
V_81 = 0x40 ;
break;
case V_84 :
V_71 = 0x24 ;
V_72 = 0xe5 ;
V_75 = 0x75 ;
V_76 = 0x75 ;
V_77 = 0x00 ;
V_78 = 0x00 ;
V_79 = 0x40 ;
V_80 = 14 ;
V_73 = 0x38 ;
V_74 = 0x30 ;
V_81 = 0x40 ;
break;
default:
V_71 = 0x24 ;
V_72 = 0xe5 ;
V_75 = 0x53 ;
V_76 = 0x75 ;
V_77 = 0x00 ;
V_78 = 0x00 ;
V_79 = 0x40 ;
V_80 = 14 ;
V_73 = 0x38 ;
V_74 = 0x30 ;
V_81 = 0x40 ;
break;
}
if ( V_2 -> V_14 -> V_85 &&
( ( V_2 -> V_14 -> V_65 == V_86 ) ||
( V_2 -> V_14 -> V_65 == V_87 ) ||
( V_2 -> V_14 -> V_65 == V_88 ) ) ) {
if ( V_23 > V_89 )
V_77 = 0x00 ;
else
V_77 = 0x60 ;
V_78 = 0x00 ;
}
if ( V_2 -> V_14 -> V_90 ) {
V_11 = F_8 ( V_2 , 0x06 , V_79 , 0x40 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_11 = F_8 ( V_2 , 0x1d , V_72 , 0xc7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1c , V_71 , 0xf8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x0d , V_75 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x0e , V_76 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x05 , V_77 , 0x60 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x06 , V_78 , 0x08 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x11 , V_73 , 0x38 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x17 , V_74 , 0x30 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0a , V_81 , 0x60 ) ;
if ( V_11 < 0 )
return V_11 ;
F_2 ( L_13 ) ;
if ( type != V_91 ) {
V_11 = F_8 ( V_2 , 0x1d , 0 , 0x38 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1c , 0 , 0x04 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x06 , 0 , 0x40 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1a , 0x30 , 0x30 ) ;
if ( V_11 < 0 )
return V_11 ;
F_17 ( 250 ) ;
V_11 = F_8 ( V_2 , 0x1d , 0x18 , 0x38 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1c , V_71 , 0x04 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1e , V_80 , 0x1f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1a , 0x20 , 0x30 ) ;
if ( V_11 < 0 )
return V_11 ;
} else {
V_11 = F_8 ( V_2 , 0x06 , 0 , 0x40 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1d , V_72 , 0x38 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1c , V_71 , 0x04 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1e , V_80 , 0x1f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1a , 0x00 , 0x30 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x10 , 0x00 , 0x04 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_92 ,
enum V_46 type ,
T_4 V_69 , T_2 V_70 )
{
int V_11 , V_21 ;
T_2 V_93 , V_94 ;
T_1 V_63 [ 5 ] , V_4 ;
T_1 V_95 , V_96 , V_97 , V_98 , V_99 , V_100 ;
T_1 V_101 , V_102 , V_103 ;
bool V_104 ;
F_2 ( L_14 ) ;
if ( V_70 == V_84 ) {
V_93 = 4063 ;
V_94 = 59000 ;
V_95 = 0x10 ;
V_96 = 0x00 ;
V_97 = 0x10 ;
V_98 = 0x6a ;
V_99 = 0x40 ;
V_100 = 0x00 ;
V_101 = 0x00 ;
V_102 = 0x00 ;
V_103 = 0x60 ;
} else {
if ( V_92 <= 6 ) {
V_93 = 3570 ;
V_94 = 56000 ;
V_95 = 0x10 ;
V_96 = 0x00 ;
V_97 = 0x10 ;
V_98 = 0x6b ;
V_99 = 0x60 ;
V_100 = 0x00 ;
V_101 = 0x00 ;
V_102 = 0x00 ;
V_103 = 0x60 ;
} else if ( V_92 == 7 ) {
#if 0
if_khz = 4070;
filt_cal_lo = 60000;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x2b;
ext_enable = 0x60;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x00;
polyfil_cur = 0x60;
#endif
V_93 = 4570 ;
V_94 = 63000 ;
V_95 = 0x10 ;
V_96 = 0x00 ;
V_97 = 0x10 ;
V_98 = 0x2a ;
V_99 = 0x60 ;
V_100 = 0x00 ;
V_101 = 0x00 ;
V_102 = 0x00 ;
V_103 = 0x60 ;
} else {
V_93 = 4570 ;
V_94 = 68500 ;
V_95 = 0x10 ;
V_96 = 0x00 ;
V_97 = 0x10 ;
V_98 = 0x0b ;
V_99 = 0x60 ;
V_100 = 0x00 ;
V_101 = 0x00 ;
V_102 = 0x00 ;
V_103 = 0x60 ;
}
}
memcpy ( V_2 -> V_10 , V_105 , sizeof( V_105 ) ) ;
if ( V_2 -> V_41 )
V_4 = 1 | V_2 -> V_32 << 1 ;
else
V_4 = 0 ;
V_11 = F_8 ( V_2 , 0x0c , V_4 , 0x0f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x13 , V_106 , 0x3f ) ;
if ( V_11 < 0 )
return V_11 ;
if ( type != V_91 ) {
V_11 = F_8 ( V_2 , 0x1d , 0x00 , 0x38 ) ;
if ( V_11 < 0 )
return V_11 ;
F_15 ( 1000 , 2000 ) ;
}
V_2 -> V_107 = V_93 * 1000 ;
if ( type != V_2 -> type )
V_104 = true ;
else if ( ( type == V_91 ) && ( V_69 != V_2 -> V_69 ) )
V_104 = true ;
else if ( ( type == V_108 ) &&
( ( V_70 != V_2 -> V_70 ) || V_92 != V_2 -> V_92 ) )
V_104 = true ;
else
V_104 = false ;
if ( V_104 ) {
F_2 ( L_15 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
V_11 = F_8 ( V_2 , 0x0b , V_98 , 0x60 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0f , 0x04 , 0x04 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x10 , 0x00 , 0x03 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_14 ( V_2 , type , V_94 * 1000 ) ;
if ( V_11 < 0 || ! V_2 -> V_68 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0b , 0x10 , 0x10 ) ;
if ( V_11 < 0 )
return V_11 ;
F_15 ( 1000 , 2000 ) ;
V_11 = F_8 ( V_2 , 0x0b , 0x00 , 0x10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0f , 0x00 , 0x04 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_2 , 0x00 , V_63 , sizeof( V_63 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_109 = V_63 [ 4 ] & 0x0f ;
if ( V_2 -> V_109 && V_2 -> V_109 != 0x0f )
break;
}
if ( V_2 -> V_109 == 0x0f )
V_2 -> V_109 = 0 ;
}
V_11 = F_8 ( V_2 , 0x0a ,
V_97 | V_2 -> V_109 , 0x1f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0b , V_98 , 0xef ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x07 , V_96 , 0x80 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x06 , V_95 , 0x30 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1e , V_99 , 0x60 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x05 , V_100 , 0x80 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1f , V_101 , 0x80 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0f , V_102 , 0x80 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x19 , V_103 , 0x60 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_70 = V_70 ;
V_2 -> type = type ;
V_2 -> V_69 = V_69 ;
V_2 -> V_92 = V_92 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_1 V_63 [ 4 ] ;
int V_11 ;
V_11 = F_9 ( V_2 , 0x00 , V_63 , sizeof( V_63 ) ) ;
if ( V_11 < 0 )
return V_11 ;
return ( ( V_63 [ 3 ] & 0x0f ) << 1 ) + ( ( V_63 [ 3 ] & 0xf0 ) >> 4 ) ;
}
static int F_20 ( struct V_110 * V_111 ,
T_2 V_23 ,
unsigned V_92 ,
enum V_46 type ,
T_4 V_69 , T_2 V_70 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
int V_11 = - V_19 ;
T_2 V_113 ;
F_2 ( L_16 ,
V_23 / 1000 , V_92 ) ;
V_11 = F_18 ( V_2 , V_92 , type , V_69 , V_70 ) ;
if ( V_11 < 0 )
goto V_114;
if ( ( type == V_91 ) && ( V_69 == V_115 ) )
V_113 = V_23 - V_2 -> V_107 ;
else
V_113 = V_23 + V_2 -> V_107 ;
V_11 = F_12 ( V_2 , V_113 ) ;
if ( V_11 < 0 )
goto V_114;
V_11 = F_14 ( V_2 , type , V_113 ) ;
if ( V_11 < 0 || ! V_2 -> V_68 )
goto V_114;
V_11 = F_16 ( V_2 , V_23 , type , V_69 , V_70 ) ;
if ( V_11 < 0 )
goto V_114;
F_2 ( L_17 ,
V_9 , V_23 , F_19 ( V_2 ) ) ;
V_114:
if ( V_11 < 0 )
F_2 ( L_18 , V_9 , V_11 ) ;
return V_11 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! V_2 -> V_116 )
return 0 ;
V_11 = F_6 ( V_2 , 0x06 , 0xb1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x05 , 0x03 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x07 , 0x3a ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x08 , 0x40 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x09 , 0xc0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x0a , 0x36 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x0c , 0x35 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x0f , 0x68 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x11 , 0x03 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x17 , 0xf4 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x19 , 0x0c ) ;
V_2 -> type = - 1 ;
return V_11 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_11 , V_21 ;
T_1 V_63 [ 3 ] , V_4 ;
memcpy ( V_2 -> V_10 , V_105 , sizeof( V_105 ) ) ;
V_11 = F_8 ( V_2 , 0x10 , 0x0b , 0x0b ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1a , 0x00 , 0x0c ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x13 , 0x7f , 0x7f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x13 , 0x00 , 0x40 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_21 = 0 ; V_21 < F_13 ( V_117 ) ; V_21 ++ ) {
V_11 = F_8 ( V_2 , 0x10 ,
V_117 [ V_21 ] [ 0 ] , 0x1b ) ;
if ( V_11 < 0 )
return V_11 ;
F_15 ( 5000 , 6000 ) ;
V_11 = F_9 ( V_2 , 0x00 , V_63 , sizeof( V_63 ) ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! ( V_63 [ 2 ] & 0x40 ) )
continue;
V_4 = V_63 [ 2 ] & 0x3f ;
if ( V_2 -> V_14 -> V_64 == 16000000 && ( V_4 > 29 || V_4 < 23 ) )
break;
if ( V_4 != 0x3f )
break;
}
if ( V_21 == F_13 ( V_117 ) )
return - V_19 ;
return V_117 [ V_21 ] [ 1 ] ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_11 ;
memcpy ( V_2 -> V_10 , V_105 , sizeof( V_105 ) ) ;
V_11 = F_8 ( V_2 , 0x05 , 0x20 , 0x20 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x07 , 0 , 0x10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0a , 0x0f , 0x0f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0b , 0x60 , 0x6f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0c , 0x0b , 0x9f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x0f , 0 , 0x08 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x18 , 0x10 , 0x10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1c , 0x02 , 0x02 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x1e , 0x80 , 0x80 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x06 , 0x20 , 0x20 ) ;
return V_11 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_11 , V_21 ;
T_1 V_63 [ 2 ] , V_118 = 0 , V_119 = 255 , V_120 = 0 ;
F_15 ( 5000 , 6000 ) ;
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ ) {
V_11 = F_9 ( V_2 , 0x00 , V_63 , sizeof( V_63 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_120 += V_63 [ 1 ] ;
if ( V_63 [ 1 ] < V_118 )
V_118 = V_63 [ 1 ] ;
if ( V_63 [ 1 ] > V_119 )
V_119 = V_63 [ 1 ] ;
}
V_11 = V_120 - V_119 - V_118 ;
return V_11 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_121 V_122 [ 3 ] ,
T_1 * V_123 )
{
struct V_121 V_124 [ 5 ] ;
struct V_121 V_125 ;
int V_21 , V_11 ;
T_1 V_26 , V_27 ;
V_26 = F_7 ( V_2 , 8 ) & 0xc0 ;
V_27 = F_7 ( V_2 , 9 ) & 0xc0 ;
V_125 . V_44 = 0 ;
V_125 . V_45 = 0 ;
V_125 . V_126 = 255 ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
switch ( V_21 ) {
case 0 :
V_124 [ V_21 ] . V_44 = V_26 ;
V_124 [ V_21 ] . V_45 = V_27 ;
break;
case 1 :
V_124 [ V_21 ] . V_44 = V_26 ;
V_124 [ V_21 ] . V_45 = V_27 + 1 ;
break;
case 2 :
V_124 [ V_21 ] . V_44 = V_26 ;
V_124 [ V_21 ] . V_45 = ( V_27 | 0x20 ) + 1 ;
break;
case 3 :
V_124 [ V_21 ] . V_44 = V_26 + 1 ;
V_124 [ V_21 ] . V_45 = V_27 ;
break;
default:
V_124 [ V_21 ] . V_44 = ( V_26 | 0x20 ) + 1 ;
V_124 [ V_21 ] . V_45 = V_27 ;
}
V_11 = F_6 ( V_2 , 0x08 , V_124 [ V_21 ] . V_44 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x09 , V_124 [ V_21 ] . V_45 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_24 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_124 [ V_21 ] . V_126 = V_11 ;
if ( V_124 [ V_21 ] . V_126 < V_125 . V_126 )
memcpy ( & V_125 , & V_124 [ V_21 ] , sizeof( V_125 ) ) ;
}
if ( ( V_125 . V_45 & 0x1f ) == 1 ) {
* V_123 = 0 ;
V_122 [ 0 ] = V_124 [ 0 ] ;
V_122 [ 1 ] = V_124 [ 1 ] ;
V_122 [ 2 ] = V_124 [ 2 ] ;
} else {
* V_123 = 1 ;
V_122 [ 0 ] = V_124 [ 0 ] ;
V_122 [ 1 ] = V_124 [ 3 ] ;
V_122 [ 2 ] = V_124 [ 4 ] ;
}
return 0 ;
}
static void F_26 ( struct V_121 V_127 [ 3 ] )
{
int V_21 ;
for ( V_21 = 3 ; V_21 > 0 ; V_21 -- ) {
if ( V_127 [ 0 ] . V_126 > V_127 [ V_21 - 1 ] . V_126 )
F_27 ( V_127 [ 0 ] , V_127 [ V_21 - 1 ] ) ;
}
}
static int F_28 ( struct V_1 * V_2 ,
struct V_121 V_127 [ 3 ] , T_1 V_3 )
{
int V_11 ;
struct V_121 V_125 ;
V_125 . V_45 = V_127 [ 0 ] . V_45 ;
V_125 . V_44 = V_127 [ 0 ] . V_44 ;
while ( ( ( V_125 . V_44 & 0x1f ) < V_128 ) &&
( ( V_125 . V_45 & 0x1f ) < V_128 ) ) {
if ( V_3 == 0x08 )
V_125 . V_44 ++ ;
else
V_125 . V_45 ++ ;
V_11 = F_6 ( V_2 , 0x08 , V_125 . V_44 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x09 , V_125 . V_45 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_24 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_125 . V_126 = V_11 ;
if ( V_125 . V_126 <= V_127 [ 0 ] . V_126 ) {
V_127 [ 0 ] . V_44 = V_125 . V_44 ;
V_127 [ 0 ] . V_45 = V_125 . V_45 ;
V_127 [ 0 ] . V_126 = V_125 . V_126 ;
} else {
return 0 ;
}
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_121 V_127 [ 3 ] ,
T_1 V_129 , T_1 V_130 , T_1 V_131 )
{
int V_11 , V_21 ;
T_1 V_125 , V_132 ;
if ( V_131 == 0x08 )
V_132 = 0x09 ;
else
V_132 = 0x08 ;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ ) {
V_11 = F_6 ( V_2 , V_131 , V_129 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , V_132 , V_130 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_24 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_127 [ V_21 ] . V_126 = V_11 ;
if ( V_131 == 0x08 ) {
V_127 [ V_21 ] . V_44 = V_129 ;
V_127 [ V_21 ] . V_45 = V_130 ;
} else {
V_127 [ V_21 ] . V_45 = V_129 ;
V_127 [ V_21 ] . V_44 = V_130 ;
}
if ( V_21 == 0 ) {
V_130 ++ ;
} else if ( V_21 == 1 ) {
if ( ( V_130 & 0x1f ) < 0x02 ) {
V_125 = 2 - ( V_130 & 0x1f ) ;
if ( V_130 & 0x20 ) {
V_130 &= 0xc0 ;
V_130 |= V_125 ;
} else {
V_130 |= 0x20 | V_125 ;
}
} else {
V_130 -= 2 ;
}
}
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
int V_11 ;
struct V_121 V_133 [ 3 ] , V_134 [ 3 ] ;
if ( ! ( V_122 -> V_44 & 0x1f ) )
V_133 [ 0 ] . V_44 = ( ( V_122 -> V_44 ) & 0xdf ) + 1 ;
else
V_133 [ 0 ] . V_44 = V_122 -> V_44 - 1 ;
V_133 [ 0 ] . V_45 = V_122 -> V_45 ;
V_11 = F_29 ( V_2 , V_133 , V_133 [ 0 ] . V_44 ,
V_133 [ 0 ] . V_45 , 0x08 ) ;
if ( V_11 < 0 )
return V_11 ;
F_26 ( V_133 ) ;
V_134 [ 0 ] = V_133 [ 0 ] ;
V_133 [ 0 ] . V_44 = V_122 -> V_44 ;
V_133 [ 0 ] . V_45 = V_122 -> V_45 ;
V_11 = F_29 ( V_2 , V_133 , V_133 [ 0 ] . V_44 ,
V_133 [ 0 ] . V_45 , 0x08 ) ;
if ( V_11 < 0 )
return V_11 ;
F_26 ( V_133 ) ;
V_134 [ 1 ] = V_133 [ 0 ] ;
if ( ( V_122 -> V_44 & 0x1f ) == 0x00 )
V_133 [ 0 ] . V_44 = ( ( V_122 -> V_44 ) | 0x20 ) + 1 ;
else
V_133 [ 0 ] . V_44 = V_122 -> V_44 + 1 ;
V_133 [ 0 ] . V_45 = V_122 -> V_45 ;
V_11 = F_29 ( V_2 , V_133 , V_133 [ 0 ] . V_44 ,
V_133 [ 0 ] . V_45 , 0x08 ) ;
if ( V_11 < 0 )
return V_11 ;
F_26 ( V_133 ) ;
V_134 [ 2 ] = V_133 [ 0 ] ;
F_26 ( V_134 ) ;
* V_122 = V_134 [ 0 ] ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_135 ;
for ( V_135 = 12 ; V_135 < 16 ; V_135 ++ ) {
V_11 = F_8 ( V_2 , 0x0c , V_135 , 0x0f ) ;
if ( V_11 < 0 )
return V_11 ;
F_15 ( 10000 , 11000 ) ;
V_11 = F_24 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 > 40 * 4 )
break;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_121 * V_136 )
{
struct V_121 V_133 [ 3 ] ;
int V_11 ;
T_1 V_137 = 0 ;
T_1 V_138 , V_139 ;
F_31 ( V_2 ) ;
V_11 = F_25 ( V_2 , V_133 , & V_137 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_137 == 1 ) {
V_138 = 0x08 ;
V_139 = 0x09 ;
} else {
V_138 = 0x09 ;
V_139 = 0x08 ;
}
F_26 ( V_133 ) ;
V_11 = F_28 ( V_2 , V_133 , V_138 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_29 ( V_2 , V_133 , V_133 [ 0 ] . V_44 ,
V_133 [ 0 ] . V_45 , V_138 ) ;
if ( V_11 < 0 )
return V_11 ;
F_26 ( V_133 ) ;
V_11 = F_28 ( V_2 , V_133 , V_139 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_29 ( V_2 , V_133 , V_133 [ 0 ] . V_44 ,
V_133 [ 0 ] . V_45 , V_139 ) ;
if ( V_11 < 0 )
return V_11 ;
F_26 ( V_133 ) ;
V_11 = F_30 ( V_2 , V_133 ) ;
* V_136 = V_133 [ 0 ] ;
V_11 = F_8 ( V_2 , 0x08 , 0 , 0x3f ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_2 , 0x09 , 0 , 0x3f ) ;
return V_11 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_121 * V_136 )
{
int V_11 ;
F_31 ( V_2 ) ;
V_11 = F_30 ( V_2 , V_136 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , unsigned V_43 , bool V_140 )
{
struct V_121 V_141 ;
int V_11 ;
T_2 V_142 , V_143 , V_144 ;
T_1 V_145 , V_146 ;
int V_147 , V_148 , V_149 ;
if ( V_2 -> V_14 -> V_64 > 24000000 )
V_144 = V_2 -> V_14 -> V_64 / 2000 ;
else
V_144 = V_2 -> V_14 -> V_64 / 1000 ;
V_145 = 15 ;
for ( V_146 = 0 ; V_146 < 16 ; V_146 ++ ) {
if ( ( 16 + V_146 ) * 8 * V_144 >= 3100000 ) {
V_145 = V_146 ;
break;
}
}
V_147 = F_7 ( V_2 , 0x18 ) ;
V_148 = F_7 ( V_2 , 0x19 ) ;
V_149 = F_7 ( V_2 , 0x1f ) ;
V_147 &= 0xf0 ;
V_147 |= V_145 ;
V_142 = ( 16 + V_145 ) * 8 * V_144 ;
V_147 &= 0xdf ;
V_148 &= 0xfc ;
V_149 &= 0xfc ;
switch ( V_43 ) {
case 0 :
V_143 = V_142 / 48 ;
V_147 |= 0x20 ;
V_148 |= 0x03 ;
V_149 |= 0x02 ;
break;
case 1 :
V_143 = V_142 / 16 ;
V_147 |= 0x00 ;
V_148 |= 0x02 ;
V_149 |= 0x00 ;
break;
case 2 :
V_143 = V_142 / 8 ;
V_147 |= 0x00 ;
V_148 |= 0x01 ;
V_149 |= 0x03 ;
break;
case 3 :
V_143 = V_142 / 6 ;
V_147 |= 0x20 ;
V_148 |= 0x00 ;
V_149 |= 0x03 ;
break;
case 4 :
V_143 = V_142 / 4 ;
V_147 |= 0x00 ;
V_148 |= 0x00 ;
V_149 |= 0x01 ;
break;
default:
V_143 = V_142 / 4 ;
V_147 |= 0x00 ;
V_148 |= 0x00 ;
V_149 |= 0x01 ;
break;
}
V_11 = F_6 ( V_2 , 0x18 , V_147 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x19 , V_148 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_2 , 0x1f , V_149 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_12 ( V_2 , ( V_143 - 5300 ) * 1000 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_14 ( V_2 , V_108 ,
( V_143 - 5300 ) * 1000 ) ;
if ( ! V_2 -> V_68 )
V_11 = - V_19 ;
if ( V_11 < 0 )
return V_11 ;
if ( V_140 ) {
V_11 = F_32 ( V_2 , & V_141 ) ;
} else {
V_141 . V_44 = V_2 -> V_42 [ 3 ] . V_44 ;
V_141 . V_45 = V_2 -> V_42 [ 3 ] . V_45 ;
V_141 . V_126 = V_2 -> V_42 [ 3 ] . V_126 ;
V_11 = F_33 ( V_2 , & V_141 ) ;
}
if ( V_11 < 0 )
return V_11 ;
switch ( V_43 ) {
case 0 :
V_2 -> V_42 [ 0 ] . V_44 = V_141 . V_44 ;
V_2 -> V_42 [ 0 ] . V_45 = V_141 . V_45 ;
V_2 -> V_42 [ 0 ] . V_126 = V_141 . V_126 ;
break;
case 1 :
V_2 -> V_42 [ 1 ] . V_44 = V_141 . V_44 ;
V_2 -> V_42 [ 1 ] . V_45 = V_141 . V_45 ;
V_2 -> V_42 [ 1 ] . V_126 = V_141 . V_126 ;
break;
case 2 :
V_2 -> V_42 [ 2 ] . V_44 = V_141 . V_44 ;
V_2 -> V_42 [ 2 ] . V_45 = V_141 . V_45 ;
V_2 -> V_42 [ 2 ] . V_126 = V_141 . V_126 ;
break;
case 3 :
V_2 -> V_42 [ 3 ] . V_44 = V_141 . V_44 ;
V_2 -> V_42 [ 3 ] . V_45 = V_141 . V_45 ;
V_2 -> V_42 [ 3 ] . V_126 = V_141 . V_126 ;
break;
case 4 :
V_2 -> V_42 [ 4 ] . V_44 = V_141 . V_44 ;
V_2 -> V_42 [ 4 ] . V_45 = V_141 . V_45 ;
V_2 -> V_42 [ 4 ] . V_126 = V_141 . V_126 ;
break;
default:
V_2 -> V_42 [ 4 ] . V_44 = V_141 . V_44 ;
V_2 -> V_42 [ 4 ] . V_45 = V_141 . V_45 ;
V_2 -> V_42 [ 4 ] . V_126 = V_141 . V_126 ;
break;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_11 , V_21 ;
int V_150 = 0 ;
if ( V_2 -> V_116 )
return 0 ;
if ( ( V_2 -> V_14 -> V_65 == V_86 ) ||
( V_2 -> V_14 -> V_65 == V_87 ) ||
( V_2 -> V_14 -> V_65 == V_88 ) ) {
V_2 -> V_32 = V_38 ;
} else {
V_11 = F_3 ( V_2 , 0x05 ,
V_105 , sizeof( V_105 ) ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ ) {
V_11 = F_22 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ! V_21 || V_11 > V_150 )
V_150 = V_11 ;
}
V_2 -> V_32 = V_150 ;
}
if ( V_151 ) {
V_2 -> V_116 = true ;
return 0 ;
}
V_11 = F_3 ( V_2 , 0x05 ,
V_105 , sizeof( V_105 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_23 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_34 ( V_2 , 3 , true ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_34 ( V_2 , 1 , false ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_34 ( V_2 , 0 , false ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_34 ( V_2 , 2 , false ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_34 ( V_2 , 4 , false ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_116 = true ;
V_2 -> V_41 = true ;
return 0 ;
}
static int F_36 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
int V_11 ;
F_2 ( L_19 , V_9 ) ;
F_37 ( & V_2 -> V_152 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 1 ) ;
V_11 = F_35 ( V_2 ) ;
if ( V_11 < 0 )
goto V_114;
V_11 = F_3 ( V_2 , 0x05 ,
V_105 , sizeof( V_105 ) ) ;
V_114:
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 0 ) ;
F_38 ( & V_2 -> V_152 ) ;
if ( V_11 < 0 )
F_2 ( L_18 , V_9 , V_11 ) ;
return V_11 ;
}
static int F_39 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
int V_11 ;
F_2 ( L_19 , V_9 ) ;
F_37 ( & V_2 -> V_152 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 1 ) ;
V_11 = F_21 ( V_2 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 0 ) ;
F_38 ( & V_2 -> V_152 ) ;
F_2 ( L_18 , V_9 , V_11 ) ;
return V_11 ;
}
static int F_40 ( struct V_110 * V_111 ,
struct V_155 * V_22 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
unsigned V_92 ;
int V_11 ;
F_2 ( L_20 , V_9 ) ;
if ( ! V_22 -> V_69 )
V_22 -> V_69 = V_156 ;
if ( ( V_22 -> V_69 == V_157 ) || ( V_22 -> V_69 == V_158 ) )
V_92 = 6 ;
else
V_92 = 8 ;
F_37 ( & V_2 -> V_152 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 1 ) ;
V_11 = F_20 ( V_111 , 62500l * V_22 -> V_159 , V_92 ,
V_91 , V_22 -> V_69 , V_160 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 0 ) ;
F_38 ( & V_2 -> V_152 ) ;
return V_11 ;
}
static int F_41 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
struct V_161 * V_162 = & V_111 -> V_163 ;
int V_11 ;
unsigned V_92 ;
F_2 ( L_21 ,
V_9 , V_162 -> V_164 , V_162 -> V_159 , V_162 -> V_165 ) ;
F_37 ( & V_2 -> V_152 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 1 ) ;
V_92 = ( V_162 -> V_165 + 500000 ) / 1000000 ;
if ( ! V_92 )
V_92 = 8 ;
V_11 = F_20 ( V_111 , V_162 -> V_159 , V_92 ,
V_108 , 0 , V_162 -> V_164 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 0 ) ;
F_38 ( & V_2 -> V_152 ) ;
if ( V_11 )
F_2 ( L_18 , V_9 , V_11 ) ;
return V_11 ;
}
static int F_42 ( struct V_110 * V_111 , T_3 * V_166 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
int V_11 = 0 ;
F_37 ( & V_2 -> V_152 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 1 ) ;
if ( V_2 -> V_68 ) {
V_11 = F_19 ( V_2 ) ;
if ( V_11 < 0 )
goto V_114;
* V_166 = ( 45 - V_11 ) << 4 | 0xff ;
if ( * V_166 == 0xff )
* V_166 = 0 ;
} else {
* V_166 = 0 ;
}
V_114:
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 0 ) ;
F_38 ( & V_2 -> V_152 ) ;
F_2 ( L_22 ,
V_9 ,
V_2 -> V_68 ? L_23 : L_24 ,
V_11 , * V_166 ) ;
return 0 ;
}
static int F_43 ( struct V_110 * V_111 , T_2 * V_159 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
F_2 ( L_19 , V_9 ) ;
* V_159 = V_2 -> V_107 ;
return 0 ;
}
static int F_44 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_112 ;
F_2 ( L_19 , V_9 ) ;
F_37 ( & V_167 ) ;
if ( V_2 )
F_45 ( V_2 ) ;
F_38 ( & V_167 ) ;
V_111 -> V_112 = NULL ;
return 0 ;
}
struct V_110 * F_46 ( struct V_110 * V_111 ,
struct V_168 * V_169 ,
const struct V_170 * V_14 )
{
struct V_1 * V_2 ;
int V_11 = - V_171 ;
T_1 V_63 [ 5 ] ;
int V_172 ;
F_37 ( & V_167 ) ;
V_172 = F_47 ( struct V_1 , V_2 ,
V_173 ,
V_169 , V_14 -> V_174 ,
L_25 ) ;
switch ( V_172 ) {
case 0 :
goto V_175;
break;
case 1 :
V_2 -> V_14 = V_14 ;
F_48 ( & V_2 -> V_152 ) ;
V_111 -> V_112 = V_2 ;
break;
case 2 :
V_111 -> V_112 = V_2 ;
break;
}
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 1 ) ;
V_11 = F_9 ( V_2 , 0x00 , V_63 , sizeof( V_63 ) ) ;
if ( V_11 < 0 )
goto V_114;
V_11 = F_39 ( V_111 ) ;
if ( V_11 < 0 )
goto V_114;
F_5 ( L_26 ) ;
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 0 ) ;
F_38 ( & V_167 ) ;
memcpy ( & V_111 -> V_153 . V_176 , & V_177 ,
sizeof( struct V_178 ) ) ;
return V_111 ;
V_114:
if ( V_111 -> V_153 . V_154 )
V_111 -> V_153 . V_154 ( V_111 , 0 ) ;
V_175:
F_38 ( & V_167 ) ;
F_5 ( L_18 , V_9 , V_11 ) ;
F_44 ( V_111 ) ;
return NULL ;
}
