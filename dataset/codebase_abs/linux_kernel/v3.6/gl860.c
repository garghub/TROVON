static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
struct V_3 * V_4 ;
int V_5 = 0 ;
if ( V_6 )
V_4 = V_7 ;
else if ( V_8 )
V_4 = V_9 ;
else if ( V_10 )
V_4 = V_11 ;
else if ( V_12 )
V_4 = V_13 ;
else
return 0 ;
memset ( V_4 , 0 , V_14 * sizeof( struct V_3 ) ) ;
F_2 (V4L2_CID_BRIGHTNESS,
V4L2_CTRL_TYPE_INTEGER, L_1 , brightness)
F_2 (V4L2_CID_SHARPNESS,
V4L2_CTRL_TYPE_INTEGER, L_2 , sharpness)
F_2 (V4L2_CID_CONTRAST,
V4L2_CTRL_TYPE_INTEGER, L_3 , contrast)
F_2 (V4L2_CID_GAMMA,
V4L2_CTRL_TYPE_INTEGER, L_4 , gamma)
F_2 (V4L2_CID_HUE,
V4L2_CTRL_TYPE_INTEGER, L_5 , hue)
F_2 (V4L2_CID_SATURATION,
V4L2_CTRL_TYPE_INTEGER, L_6 , saturation)
F_2 (V4L2_CID_WHITE_BALANCE_TEMPERATURE,
V4L2_CTRL_TYPE_INTEGER, L_7 , whitebal)
F_2 (V4L2_CID_BACKLIGHT_COMPENSATION,
V4L2_CTRL_TYPE_INTEGER, L_8 , backlight)
F_2 (V4L2_CID_HFLIP,
V4L2_CTRL_TYPE_BOOLEAN, L_9 , mirror)
F_2 (V4L2_CID_VFLIP,
V4L2_CTRL_TYPE_BOOLEAN, L_10 , flip)
F_2 (V4L2_CID_POWER_LINE_FREQUENCY,
V4L2_CTRL_TYPE_BOOLEAN, L_11 , AC50Hz)
return V_5 ;
}
static int F_3 ( struct V_1 * V_1 ,
const struct V_15 * V_16 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
struct V_17 * V_17 ;
T_1 V_18 , V_19 ;
V_18 = V_16 -> V_20 ;
V_19 = V_16 -> V_21 ;
V_2 -> V_22 = 1 ;
V_2 -> V_23 = - 1 ;
V_2 -> V_24 = 0xff ;
if ( strcmp ( V_24 , L_12 ) == 0 )
V_2 -> V_24 = V_25 ;
else if ( strcmp ( V_24 , L_13 ) == 0 )
V_2 -> V_24 = V_26 ;
else if ( strcmp ( V_24 , L_14 ) == 0 )
V_2 -> V_24 = V_27 ;
else if ( strcmp ( V_24 , L_15 ) == 0 )
V_2 -> V_24 = V_28 ;
if ( F_4 ( V_1 , V_18 , V_19 ) == - 1 )
return - 1 ;
V_17 = & V_1 -> V_17 ;
switch ( V_2 -> V_24 ) {
case V_25 :
V_1 -> V_29 = & V_30 ;
V_17 -> V_31 = V_32 ;
V_17 -> V_33 = F_5 ( V_32 ) ;
V_34 = V_35 ;
break;
case V_28 :
V_1 -> V_29 = & V_36 ;
V_17 -> V_31 = V_37 ;
V_17 -> V_33 = F_5 ( V_37 ) ;
V_34 = V_38 ;
break;
case V_26 :
V_1 -> V_29 = & V_39 ;
V_17 -> V_31 = V_40 ;
V_17 -> V_33 = F_5 ( V_40 ) ;
V_34 = V_41 ;
break;
case V_27 :
V_1 -> V_29 = & V_42 ;
V_17 -> V_31 = V_43 ;
V_17 -> V_33 = F_5 ( V_43 ) ;
V_34 = V_44 ;
break;
}
V_34 ( V_1 ) ;
if ( V_45 != 0xff )
( (struct V_2 * ) V_1 ) -> V_46 . V_45 = V_45 ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
return V_2 -> V_47 ( V_1 ) ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
return V_2 -> V_48 ( V_1 ) ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
return V_2 -> V_49 ( V_1 ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
if ( ! V_2 -> V_1 . V_50 )
return;
return V_2 -> V_51 ( V_1 ) ;
}
static void F_10 ( struct V_1 * V_1 ,
T_2 * V_52 , int V_53 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
static T_3 V_54 ;
T_3 V_55 = ( T_3 ) V_1 -> V_56 ;
T_3 V_57 =
V_2 -> V_58 * ( V_1 -> V_17 . V_31 [ V_55 ] . V_59 + 1 ) ;
switch ( * ( V_60 * ) V_52 ) {
case 0x0202 :
F_11 ( V_1 , V_61 , NULL , 0 ) ;
V_54 = 0 ;
if ( V_2 -> V_23 >= 0 && V_2 -> V_23 < 10 )
V_2 -> V_23 ++ ;
F_11 ( V_1 , V_62 , NULL , 0 ) ;
break;
default:
V_52 += 2 ;
V_53 -= 2 ;
if ( V_54 + V_53 <= V_57 )
V_54 += V_53 ;
else {
if ( V_54 < V_57 && V_54 + V_53 > V_57 ) {
V_52 += V_57 - V_54 ;
V_53 -= V_57 - V_54 ;
V_54 = V_57 + 1 ;
}
F_11 ( V_1 ,
V_63 , V_52 , V_53 ) ;
}
break;
}
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
if ( ! V_12 ) {
T_2 V_64 ;
T_2 V_65 ;
F_13 ( V_1 , 0xc0 , 2 , 0x0000 , 0x0000 , 1 , ( void * ) & V_64 ) ;
V_65 = ( V_64 == 0xc8 || V_64 == 0x40 ) ;
if ( V_65 && V_2 -> V_22 > - 4 ) {
if ( V_2 -> V_22 > 0 )
V_2 -> V_22 = 0 ;
if ( V_2 -> V_22 == - 3 ) {
V_2 -> V_66 = 1 ;
V_2 -> V_67 = 1 ;
}
V_2 -> V_22 -- ;
}
if ( ! V_65 && V_2 -> V_22 < 4 ) {
if ( V_2 -> V_22 < 0 )
V_2 -> V_22 = 0 ;
if ( V_2 -> V_22 == 3 ) {
V_2 -> V_66 = 0 ;
V_2 -> V_67 = 1 ;
}
V_2 -> V_22 ++ ;
}
}
if ( V_2 -> V_67 )
V_2 -> V_68 ( V_1 ) ;
}
static int F_14 ( struct V_69 * V_70 ,
const struct V_15 * V_16 )
{
return F_15 ( V_70 , V_16 ,
& V_30 , sizeof( struct V_2 ) , V_71 ) ;
}
static void F_16 ( struct V_69 * V_70 )
{
F_17 ( V_70 ) ;
}
int F_18 ( struct V_1 * V_1 ,
unsigned char V_72 , T_4 V_73 , T_1 V_74 , T_1 V_75 ,
T_3 V_53 , void * V_76 )
{
struct V_77 * V_78 = V_1 -> V_79 ;
T_3 V_80 = 0 ;
if ( V_72 == 0x40 ) {
if ( V_53 > 0 ) {
memcpy ( V_1 -> V_81 , V_76 , V_53 ) ;
V_80 = F_19 ( V_78 , F_20 ( V_78 , 0 ) ,
V_73 , V_72 , V_74 , V_75 ,
V_1 -> V_81 ,
V_53 , 400 + 200 * ( V_53 > 1 ) ) ;
} else {
V_80 = F_19 ( V_78 , F_20 ( V_78 , 0 ) ,
V_73 , V_72 , V_74 , V_75 , NULL , V_53 , 400 ) ;
}
} else {
if ( V_53 > 0 ) {
V_80 = F_19 ( V_78 , F_21 ( V_78 , 0 ) ,
V_73 , V_72 , V_74 , V_75 ,
V_1 -> V_81 ,
V_53 , 400 + 200 * ( V_53 > 1 ) ) ;
memcpy ( V_76 , V_1 -> V_81 , V_53 ) ;
} else {
V_80 = F_19 ( V_78 , F_21 ( V_78 , 0 ) ,
V_73 , V_72 , V_74 , V_75 , NULL , V_53 , 400 ) ;
}
}
if ( V_80 < 0 )
F_22 ( L_16 ,
V_80 , V_72 , V_73 , V_74 , V_75 , V_53 ) ;
else if ( V_53 > 1 && V_80 < V_53 )
F_23 ( V_82 , L_17 , V_80 , V_53 ) ;
F_24 ( 1 ) ;
return V_80 ;
}
int F_25 ( struct V_1 * V_1 , struct V_83 * V_84 , int V_53 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_53 ; V_85 ++ ) {
if ( V_84 [ V_85 ] . V_86 != 0xffff )
F_26 ( V_1 , 0x40 , 1 , V_84 [ V_85 ] . V_74 ,
V_84 [ V_85 ] . V_86 , 0 , NULL ) ;
else if ( V_84 [ V_85 ] . V_74 == 0xffff )
break;
else
F_24 ( V_84 [ V_85 ] . V_74 ) ;
}
return V_85 ;
}
int F_27 ( struct V_1 * V_1 , struct V_83 * V_84 ,
int V_53 , int V_85 )
{
while ( ++ V_85 < V_53 ) {
if ( V_84 [ V_85 ] . V_86 != 0xffff )
F_26 ( V_1 , 0x40 , 1 , V_84 [ V_85 ] . V_74 , V_84 [ V_85 ] . V_86 ,
0 , NULL ) ;
else if ( V_84 [ V_85 ] . V_74 == 0xffff )
break;
else
F_24 ( V_84 [ V_85 ] . V_74 ) ;
}
return V_85 ;
}
void F_28 ( struct V_1 * V_1 , struct V_87 * V_84 , int V_53 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_53 ; V_85 ++ ) {
if ( memcmp ( V_84 [ V_85 ] . V_52 , L_18 , 3 ) != 0 )
F_26 ( V_1 , 0x40 , 3 , 0x7a00 , V_84 [ V_85 ] . V_86 ,
3 , V_84 [ V_85 ] . V_52 ) ;
else
F_24 ( V_84 [ V_85 ] . V_86 ) ;
}
}
static int F_4 ( struct V_1 * V_1 ,
T_1 V_18 , T_1 V_19 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
T_2 V_88 , V_89 , V_90 , V_91 , V_92 ;
if ( V_19 == 0xf191 )
V_2 -> V_24 = V_25 ;
if ( V_2 -> V_24 == 0xff ) {
F_13 ( V_1 , 0xc0 , 2 , 0x0000 , 0x0004 , 1 , & V_88 ) ;
F_13 ( V_1 , 0xc0 , 2 , 0x0000 , 0x0004 , 1 , & V_88 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x0000 , 0x0000 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x0010 , 0x0010 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x0008 , 0x00c0 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x0001 , 0x00c1 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x0001 , 0x00c2 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x0020 , 0x0006 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x006a , 0x000d , 0 , NULL ) ;
F_24 ( 56 ) ;
F_23 ( V_93 , L_19 ) ;
V_91 = 0 ;
for ( V_92 = 0 ; V_92 < 4 ; V_92 ++ ) {
F_26 ( V_1 , 0x40 , 1 , 0x0040 , 0x0000 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x0063 , 0x0006 , 0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x7a00 , 0x8030 , 0 , NULL ) ;
F_24 ( 10 ) ;
F_13 ( V_1 , 0xc0 , 2 , 0x7a00 , 0x8030 , 1 , & V_88 ) ;
F_23 ( V_93 , L_20 , V_88 ) ;
if ( V_88 == 0xff )
V_91 ++ ;
}
if ( V_91 ) {
F_23 ( V_93 , L_21 ) ;
F_23 ( V_93 , L_22 ) ;
V_89 = V_90 = 0 ;
for ( V_92 = 0 ; V_92 < 4 ; V_92 ++ ) {
F_26 ( V_1 , 0x40 , 1 , 0x0040 , 0x0000 ,
0 , NULL ) ;
F_24 ( 3 ) ;
F_26 ( V_1 , 0x40 , 1 , 0x6000 , 0x800a ,
0 , NULL ) ;
F_24 ( 10 ) ;
F_13 ( V_1 , 0xc0 , 2 , 0x6000 , 0x800a ,
1 , & V_88 ) ;
if ( V_88 == 0x26 || V_88 == 0x40 ) {
F_23 ( V_93 ,
L_23 ,
V_88 ) ;
V_2 -> V_24 = V_26 ;
V_89 += 4 ;
break;
}
if ( V_88 == 0x96 || V_88 == 0x55 ) {
F_23 ( V_93 ,
L_24 ,
V_88 ) ;
V_2 -> V_24 = V_27 ;
V_90 += 4 ;
break;
}
F_23 ( V_93 , L_20 , V_88 ) ;
if ( V_88 == 0x00 )
V_89 ++ ;
if ( V_88 == 0xff )
V_90 ++ ;
F_24 ( 3 ) ;
}
if ( V_89 < 4 && V_90 < 4 )
return - 1 ;
} else {
F_23 ( V_93 , L_25 ) ;
V_2 -> V_24 = V_28 ;
}
}
if ( V_6 ) {
F_23 ( V_93 , L_26 ) ;
} else if ( V_8 ) {
F_23 ( V_93 , L_27 ) ;
} else if ( V_12 ) {
F_23 ( V_93 , L_28 ) ;
} else if ( V_10 ) {
F_23 ( V_93 , L_29 ) ;
} else {
F_23 ( V_93 , L_30 ) ;
return - 1 ;
}
return 0 ;
}
