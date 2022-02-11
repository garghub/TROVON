static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
char * V_6 ;
int V_7 ;
int V_8 ;
struct V_9 * V_10 ;
T_1 V_11 [ 4 ] ;
V_10 = & V_12 [ V_5 -> type - 200 ] ;
if ( V_3 < V_10 -> V_13 ) {
V_6 = L_1 ;
V_8 = V_10 -> V_14 ;
} else if ( V_3 < V_10 -> V_15 ) {
V_6 = L_2 ;
V_8 = V_10 -> V_16 ;
} else {
V_6 = L_3 ;
V_8 = V_10 -> V_17 ;
}
F_3 ( V_18 L_4 ,
V_3 / 16 , ( V_3 % 16 ) * 625 , V_6 ) ;
V_7 = V_3 + V_10 -> V_19 ;
V_11 [ 0 ] = V_7 >> 8 ;
V_11 [ 1 ] = V_7 & 0xff ;
V_11 [ 2 ] = V_10 -> V_20 ;
V_11 [ 3 ] = V_8 ;
F_4 ( V_2 , V_11 , 4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_21 , int V_22 , int V_23 )
{
T_1 V_11 [ 5 ] ;
struct V_24 V_25 ;
V_11 [ 0 ] = V_21 ;
V_11 [ 1 ] = V_22 >> 8 ;
V_11 [ 2 ] = V_22 & 0xff ;
V_11 [ 3 ] = V_23 >> 8 ;
V_11 [ 4 ] = V_23 & 0xff ;
V_25 . V_22 = V_26 ;
V_25 . V_27 = 0 ;
V_25 . V_28 = 5 ;
V_25 . V_29 = V_11 ;
F_6 ( V_2 -> V_30 , & V_25 , 1 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_31 = 0 ;
T_1 V_11 [ 3 ] ;
struct V_24 V_25 ;
V_11 [ 0 ] = 0x00 ;
V_11 [ 1 ] = 0x80 ;
V_11 [ 2 ] = 0x00 ;
V_25 . V_22 = V_26 ;
V_25 . V_27 = 0 ;
V_25 . V_28 = 3 ;
V_25 . V_29 = V_11 ;
F_6 ( V_2 -> V_30 , & V_25 , 1 ) ;
V_11 [ 1 ] = 0x00 ;
F_6 ( V_2 -> V_30 , & V_25 , 1 ) ;
if ( V_32 [ V_5 -> V_33 ] . V_34 != V_35 ) {
switch ( V_5 -> V_36 ) {
case V_37 :
switch ( V_32 [ V_5 -> V_33 ] . V_34 ) {
case V_38 :
V_31 = V_32 [ V_5 -> V_33 ] . V_31 ;
break;
case V_39 :
V_31 = 0x0000 ;
break;
case V_40 :
V_31 = 0x0200 ;
break;
default:
break;
}
break;
case V_41 :
V_31 = V_32 [ V_5 -> V_33 ] . V_31 ;
break;
case V_42 :
V_31 = 0x0300 ;
break;
case V_43 :
V_31 = 0x0400 ;
break;
}
V_31 |= V_32 [ V_5 -> V_33 ] . V_31 & 0x00ff ;
} else
V_31 = V_32 [ V_5 -> V_33 ] . V_31 ;
F_5 ( V_2 , 0x10 , 0x0030 , V_32 [ V_5 -> V_33 ] . V_44 ) ;
F_5 ( V_2 , 0x12 , 0x0008 , V_31 ) ;
F_5 ( V_2 , 0x12 , 0x0013 , V_32 [ V_5 -> V_33 ] . V_45 ) ;
F_5 ( V_2 , 0x12 , 0x000e ,
V_32 [ V_5 -> V_33 ] . V_46 ) ;
F_5 ( V_2 , 0x12 , 0x0010 ,
V_32 [ V_5 -> V_33 ] . V_47 ) ;
F_5 ( V_2 , 0x12 , 0x000d ,
V_32 [ V_5 -> V_33 ] . V_48 ) ;
F_5 ( V_2 , 0x10 , 0x0020 , V_32 [ V_5 -> V_33 ] . system ) ;
F_5 ( V_2 , 0x12 , 0x0000 , V_32 [ V_5 -> V_33 ] . V_49 ) ;
if ( V_32 [ V_5 -> V_33 ] . V_34 == V_38 )
F_5 ( V_2 , 0x10 , 0x0022 ,
V_5 -> V_36 == V_37 ? 0x07f0 : 0x0190 ) ;
#ifdef F_8
{
T_1 V_50 [ 3 ] , V_51 [ 2 ] ;
struct V_24 V_52 [ 2 ] ;
F_3 ( V_18 L_5
L_6 ,
V_32 [ V_5 -> V_33 ] . V_44 ,
V_31 ,
V_32 [ V_5 -> V_33 ] . V_45 ,
V_32 [ V_5 -> V_33 ] . V_46 ,
V_32 [ V_5 -> V_33 ] . V_47 ,
V_32 [ V_5 -> V_33 ] . V_48 ,
V_32 [ V_5 -> V_33 ] . system ,
V_32 [ V_5 -> V_33 ] . V_49 ) ;
V_50 [ 0 ] = 0x11 ;
V_50 [ 1 ] = 0x00 ;
V_50 [ 2 ] = 0x7e ;
V_52 [ 0 ] . V_22 = V_26 ;
V_52 [ 0 ] . V_27 = 0 ;
V_52 [ 0 ] . V_28 = 3 ;
V_52 [ 0 ] . V_29 = V_50 ;
V_52 [ 1 ] . V_22 = V_26 ;
V_52 [ 1 ] . V_27 = V_53 ;
V_52 [ 1 ] . V_28 = 2 ;
V_52 [ 1 ] . V_29 = V_51 ;
F_6 ( V_2 -> V_30 , V_52 , 2 ) ;
F_3 ( V_18 L_7 ,
V_51 [ 0 ] , V_51 [ 1 ] ) ;
V_50 [ 0 ] = 0x11 ;
V_50 [ 1 ] = 0x02 ;
V_50 [ 2 ] = 0x00 ;
F_6 ( V_2 -> V_30 , V_52 , 2 ) ;
F_3 ( V_18 L_8 ,
V_51 [ 0 ] , V_51 [ 1 ] ) ;
}
#endif
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 [ 4 ] ;
struct V_24 V_25 ;
int V_54 = 0 ;
V_11 [ 0 ] = 0 ;
if ( V_5 -> V_55 & V_56 ) {
V_11 [ 1 ] = 0x94 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x49 ;
V_54 = 1 ;
} else if ( V_5 -> V_55 & V_57 ) {
V_11 [ 1 ] = 0x14 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x4a ;
V_54 = 4 ;
} else if ( V_5 -> V_55 & V_58 ) {
V_11 [ 1 ] = 0x14 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x4b ;
V_54 = 6 ;
} else if ( V_5 -> V_55 & V_59 ) {
V_11 [ 1 ] = 0x04 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x4b ;
V_54 = 11 ;
}
V_25 . V_22 = V_60 ;
V_25 . V_27 = 0 ;
V_25 . V_28 = 4 ;
V_25 . V_29 = V_11 ;
F_6 ( V_2 -> V_30 , & V_25 , 1 ) ;
if ( V_61 >= 0 && V_61 < V_62 )
V_5 -> V_33 = V_61 ;
else
V_5 -> V_33 = V_54 ;
F_3 ( V_18 L_9 ,
V_5 -> V_33 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_63 , void * V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_63 ) {
#if 0
#ifdef F_11
case TUNER_SET_TYPE_ADDR:
{
struct tuner_setup *tun_setup = arg;
int *type = &tun_setup->type;
#else
case TUNER_SET_TYPE:
{
int *type = arg;
#endif
if (t->type >= 0) {
if (t->type != *type)
printk(KERN_ERR "wis-sony-tuner: type already "
"set to %d, ignoring request for %d\n",
t->type, *type);
break;
}
t->type = *type;
switch (t->type) {
case TUNER_SONY_BTF_PG472Z:
switch (force_band_str[0]) {
case 'b':
case 'B':
case 'g':
case 'G':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to PAL-B/G bands\n");
force_band = V4L2_STD_PAL_BG;
break;
case 'i':
case 'I':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to PAL-I band\n");
force_band = V4L2_STD_PAL_I;
break;
case 'd':
case 'D':
case 'k':
case 'K':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to PAL-D/K bands\n");
force_band = V4L2_STD_PAL_I;
break;
case 'l':
case 'L':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to SECAM-L band\n");
force_band = V4L2_STD_SECAM_L;
break;
default:
force_band = 0;
break;
}
if (force_band)
t->std = force_band;
else
t->std = V4L2_STD_PAL_BG;
set_if(client);
break;
case TUNER_SONY_BTF_PK467Z:
t->std = V4L2_STD_NTSC_M_JP;
break;
case TUNER_SONY_BTF_PB463Z:
t->std = V4L2_STD_NTSC_M;
break;
default:
printk(KERN_ERR "wis-sony-tuner: tuner type %d is not "
"supported by this module\n", *type);
break;
}
if (type >= 0)
printk(KERN_INFO
"wis-sony-tuner: type set to %d (%s)\n",
t->type, sony_tuners[t->type - 200].name);
break;
}
#endif
case V_65 :
{
struct V_66 * V_67 = V_64 ;
V_67 -> V_68 = V_5 -> V_3 ;
break;
}
case V_69 :
{
struct V_66 * V_67 = V_64 ;
V_5 -> V_3 = V_67 -> V_68 ;
F_1 ( V_2 , V_5 -> V_3 ) ;
break;
}
case V_70 :
{
struct V_71 * V_55 = V_64 ;
switch ( V_5 -> type ) {
case V_72 :
switch ( V_55 -> V_73 ) {
case 0 :
F_12 ( V_55 ,
V_56 , L_10 ) ;
break;
case 1 :
F_12 ( V_55 ,
V_57 , L_11 ) ;
break;
case 2 :
F_12 ( V_55 ,
V_58 , L_12 ) ;
break;
case 3 :
F_12 ( V_55 ,
V_59 , L_13 ) ;
break;
default:
V_55 -> V_74 = 0 ;
break;
}
break;
case V_75 :
if ( V_55 -> V_73 != 0 ) {
V_55 -> V_74 = 0 ;
break;
}
F_12 ( V_55 ,
V_76 , L_14 ) ;
break;
case V_77 :
if ( V_55 -> V_73 != 0 ) {
V_55 -> V_74 = 0 ;
break;
}
F_12 ( V_55 , V_78 , L_15 ) ;
break;
}
break;
}
case V_79 :
{
T_3 * V_55 = V_64 ;
* V_55 = V_5 -> V_55 ;
break;
}
case V_80 :
{
T_3 * V_55 = V_64 ;
T_3 V_81 = V_5 -> V_55 ;
switch ( V_5 -> type ) {
case V_72 :
if ( V_82 && ( * V_55 & V_82 ) != * V_55 &&
* V_55 != V_83 &&
* V_55 != V_84 ) {
F_3 ( V_18 L_16
L_17
L_18 ) ;
V_5 -> V_55 = V_82 ;
} else if ( * V_55 & V_56 ) {
V_5 -> V_55 = V_56 ;
} else if ( * V_55 & V_57 ) {
V_5 -> V_55 = V_57 ;
} else if ( * V_55 & V_58 ) {
V_5 -> V_55 = V_58 ;
} else if ( * V_55 & V_59 ) {
V_5 -> V_55 = V_59 ;
} else {
F_3 ( V_85 L_19
L_20 ) ;
* V_55 = 0 ;
break;
}
if ( V_81 != V_5 -> V_55 )
F_9 ( V_2 ) ;
break;
case V_75 :
if ( ! ( * V_55 & V_76 ) ) {
F_3 ( V_85 L_19
L_20 ) ;
* V_55 = 0 ;
}
break;
case V_77 :
if ( ! ( * V_55 & V_78 ) ) {
F_3 ( V_85 L_19
L_20 ) ;
* V_55 = 0 ;
}
break;
}
break;
}
case V_86 :
{
T_3 * V_55 = V_64 ;
switch ( V_5 -> type ) {
case V_72 :
if ( V_82 )
* V_55 = V_82 ;
else
* V_55 = V_56 | V_57 |
V_58 | V_59 ;
break;
case V_75 :
* V_55 = V_76 ;
break;
case V_77 :
* V_55 = V_78 ;
break;
}
break;
}
case V_87 :
{
struct V_88 * V_10 = V_64 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
strcpy ( V_10 -> V_89 , L_21 ) ;
V_10 -> type = V_90 ;
V_10 -> V_91 = 0UL ;
V_10 -> V_92 = 0xffffffffUL ;
switch ( V_5 -> type ) {
case V_72 :
V_10 -> V_93 = V_94 |
V_95 | V_96 |
V_97 ;
V_10 -> V_98 = V_99 |
V_100 | V_101 |
V_102 ;
break;
case V_75 :
case V_77 :
V_10 -> V_93 = V_95 ;
V_10 -> V_98 = V_99 |
V_100 ;
break;
}
V_10 -> V_36 = V_5 -> V_36 ;
return 0 ;
}
case V_103 :
{
struct V_88 * V_10 = V_64 ;
switch ( V_5 -> type ) {
case V_72 :
if ( V_10 -> V_36 != V_5 -> V_36 ) {
V_5 -> V_36 = V_10 -> V_36 ;
F_7 ( V_2 ) ;
}
break;
case V_75 :
case V_77 :
break;
}
return 0 ;
}
default:
break;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_104 * V_74 )
{
struct V_105 * V_30 = V_2 -> V_30 ;
struct V_4 * V_5 ;
if ( ! F_14 ( V_30 , V_106 ) )
return - V_107 ;
V_5 = F_15 ( sizeof( struct V_4 ) , V_108 ) ;
if ( V_5 == NULL )
return - V_109 ;
V_5 -> type = - 1 ;
V_5 -> V_3 = 0 ;
V_5 -> V_33 = 0 ;
V_5 -> V_36 = V_41 ;
F_16 ( V_2 , V_5 ) ;
F_3 ( V_18
L_22 ,
V_2 -> V_22 , V_30 -> V_89 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_18 ( V_5 ) ;
return 0 ;
}
