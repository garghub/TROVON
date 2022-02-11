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
F_3 ( & V_2 -> V_18 , L_4 ,
V_3 / 16 , ( V_3 % 16 ) * 625 , V_6 ) ;
V_7 = V_3 + V_10 -> V_19 ;
V_11 [ 0 ] = V_7 >> 8 ;
V_11 [ 1 ] = V_7 & 0xff ;
V_11 [ 2 ] = V_10 -> V_20 ;
V_11 [ 3 ] = V_8 ;
F_4 ( V_2 , V_11 , 4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_18 , int V_21 , int V_22 )
{
T_1 V_11 [ 5 ] ;
struct V_23 V_24 ;
V_11 [ 0 ] = V_18 ;
V_11 [ 1 ] = V_21 >> 8 ;
V_11 [ 2 ] = V_21 & 0xff ;
V_11 [ 3 ] = V_22 >> 8 ;
V_11 [ 4 ] = V_22 & 0xff ;
V_24 . V_21 = V_25 ;
V_24 . V_26 = 0 ;
V_24 . V_27 = 5 ;
V_24 . V_28 = V_11 ;
F_6 ( V_2 -> V_29 , & V_24 , 1 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_30 = 0 ;
T_1 V_11 [ 3 ] ;
struct V_23 V_24 ;
V_11 [ 0 ] = 0x00 ;
V_11 [ 1 ] = 0x80 ;
V_11 [ 2 ] = 0x00 ;
V_24 . V_21 = V_25 ;
V_24 . V_26 = 0 ;
V_24 . V_27 = 3 ;
V_24 . V_28 = V_11 ;
F_6 ( V_2 -> V_29 , & V_24 , 1 ) ;
V_11 [ 1 ] = 0x00 ;
F_6 ( V_2 -> V_29 , & V_24 , 1 ) ;
if ( V_31 [ V_5 -> V_32 ] . V_33 != V_34 ) {
switch ( V_5 -> V_35 ) {
case V_36 :
switch ( V_31 [ V_5 -> V_32 ] . V_33 ) {
case V_37 :
V_30 = V_31 [ V_5 -> V_32 ] . V_30 ;
break;
case V_38 :
V_30 = 0x0000 ;
break;
case V_39 :
V_30 = 0x0200 ;
break;
default:
break;
}
break;
case V_40 :
V_30 = V_31 [ V_5 -> V_32 ] . V_30 ;
break;
case V_41 :
V_30 = 0x0300 ;
break;
case V_42 :
V_30 = 0x0400 ;
break;
}
V_30 |= V_31 [ V_5 -> V_32 ] . V_30 & 0x00ff ;
} else
V_30 = V_31 [ V_5 -> V_32 ] . V_30 ;
F_5 ( V_2 , 0x10 , 0x0030 , V_31 [ V_5 -> V_32 ] . V_43 ) ;
F_5 ( V_2 , 0x12 , 0x0008 , V_30 ) ;
F_5 ( V_2 , 0x12 , 0x0013 , V_31 [ V_5 -> V_32 ] . V_44 ) ;
F_5 ( V_2 , 0x12 , 0x000e ,
V_31 [ V_5 -> V_32 ] . V_45 ) ;
F_5 ( V_2 , 0x12 , 0x0010 ,
V_31 [ V_5 -> V_32 ] . V_46 ) ;
F_5 ( V_2 , 0x12 , 0x000d ,
V_31 [ V_5 -> V_32 ] . V_47 ) ;
F_5 ( V_2 , 0x10 , 0x0020 , V_31 [ V_5 -> V_32 ] . system ) ;
F_5 ( V_2 , 0x12 , 0x0000 , V_31 [ V_5 -> V_32 ] . V_48 ) ;
if ( V_31 [ V_5 -> V_32 ] . V_33 == V_37 )
F_5 ( V_2 , 0x10 , 0x0022 ,
V_5 -> V_35 == V_36 ? 0x07f0 : 0x0190 ) ;
#ifdef F_8
{
T_1 V_49 [ 3 ] , V_50 [ 2 ] ;
struct V_23 V_51 [ 2 ] ;
F_3 ( & V_2 -> V_18 ,
L_5 ,
V_31 [ V_5 -> V_32 ] . V_43 ,
V_30 ,
V_31 [ V_5 -> V_32 ] . V_44 ,
V_31 [ V_5 -> V_32 ] . V_45 ,
V_31 [ V_5 -> V_32 ] . V_46 ,
V_31 [ V_5 -> V_32 ] . V_47 ,
V_31 [ V_5 -> V_32 ] . system ,
V_31 [ V_5 -> V_32 ] . V_48 ) ;
V_49 [ 0 ] = 0x11 ;
V_49 [ 1 ] = 0x00 ;
V_49 [ 2 ] = 0x7e ;
V_51 [ 0 ] . V_21 = V_25 ;
V_51 [ 0 ] . V_26 = 0 ;
V_51 [ 0 ] . V_27 = 3 ;
V_51 [ 0 ] . V_28 = V_49 ;
V_51 [ 1 ] . V_21 = V_25 ;
V_51 [ 1 ] . V_26 = V_52 ;
V_51 [ 1 ] . V_27 = 2 ;
V_51 [ 1 ] . V_28 = V_50 ;
F_6 ( V_2 -> V_29 , V_51 , 2 ) ;
F_3 ( & V_2 -> V_18 , L_6 ,
V_50 [ 0 ] , V_50 [ 1 ] ) ;
V_49 [ 0 ] = 0x11 ;
V_49 [ 1 ] = 0x02 ;
V_49 [ 2 ] = 0x00 ;
F_6 ( V_2 -> V_29 , V_51 , 2 ) ;
F_3 ( & V_2 -> V_18 , L_7 ,
V_50 [ 0 ] , V_50 [ 1 ] ) ;
}
#endif
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_11 [ 4 ] ;
struct V_23 V_24 ;
int V_53 = 0 ;
V_11 [ 0 ] = 0 ;
if ( V_5 -> V_54 & V_55 ) {
V_11 [ 1 ] = 0x94 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x49 ;
V_53 = 1 ;
} else if ( V_5 -> V_54 & V_56 ) {
V_11 [ 1 ] = 0x14 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x4a ;
V_53 = 4 ;
} else if ( V_5 -> V_54 & V_57 ) {
V_11 [ 1 ] = 0x14 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x4b ;
V_53 = 6 ;
} else if ( V_5 -> V_54 & V_58 ) {
V_11 [ 1 ] = 0x04 ;
V_11 [ 2 ] = 0x70 ;
V_11 [ 3 ] = 0x4b ;
V_53 = 11 ;
}
V_24 . V_21 = V_59 ;
V_24 . V_26 = 0 ;
V_24 . V_27 = 4 ;
V_24 . V_28 = V_11 ;
F_6 ( V_2 -> V_29 , & V_24 , 1 ) ;
if ( V_60 >= 0 && V_60 < V_61 )
V_5 -> V_32 = V_60 ;
else
V_5 -> V_32 = V_53 ;
F_3 ( & V_2 -> V_18 , L_8 , V_5 -> V_32 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_62 , void * V_63 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_62 ) {
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
dev_err(&client->dev,
"type already set to %d, ignoring request for %d\n",
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
dev_info(&client->dev,
"forcing tuner to PAL-B/G bands\n");
force_band = V4L2_STD_PAL_BG;
break;
case 'i':
case 'I':
dev_info(&client->dev,
"forcing tuner to PAL-I band\n");
force_band = V4L2_STD_PAL_I;
break;
case 'd':
case 'D':
case 'k':
case 'K':
dev_info(&client->dev,
"forcing tuner to PAL-D/K bands\n");
force_band = V4L2_STD_PAL_I;
break;
case 'l':
case 'L':
dev_info(&client->dev,
"forcing tuner to SECAM-L band\n");
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
dev_err(&client->dev,
"tuner type %d is not supported by this module\n",
*type);
break;
}
if (type >= 0)
dev_info(&clinet->dev,
"type set to %d (%s)\n",
t->type, sony_tuners[t->type - 200].name);
break;
}
#endif
case V_64 :
{
struct V_65 * V_66 = V_63 ;
V_66 -> V_67 = V_5 -> V_3 ;
break;
}
case V_68 :
{
struct V_65 * V_66 = V_63 ;
V_5 -> V_3 = V_66 -> V_67 ;
F_1 ( V_2 , V_5 -> V_3 ) ;
break;
}
case V_69 :
{
struct V_70 * V_54 = V_63 ;
switch ( V_5 -> type ) {
case V_71 :
switch ( V_54 -> V_72 ) {
case 0 :
F_12 ( V_54 ,
V_55 , L_9 ) ;
break;
case 1 :
F_12 ( V_54 ,
V_56 , L_10 ) ;
break;
case 2 :
F_12 ( V_54 ,
V_57 , L_11 ) ;
break;
case 3 :
F_12 ( V_54 ,
V_58 , L_12 ) ;
break;
default:
V_54 -> V_73 = 0 ;
break;
}
break;
case V_74 :
if ( V_54 -> V_72 != 0 ) {
V_54 -> V_73 = 0 ;
break;
}
F_12 ( V_54 ,
V_75 , L_13 ) ;
break;
case V_76 :
if ( V_54 -> V_72 != 0 ) {
V_54 -> V_73 = 0 ;
break;
}
F_12 ( V_54 , V_77 , L_14 ) ;
break;
}
break;
}
case V_78 :
{
T_3 * V_54 = V_63 ;
* V_54 = V_5 -> V_54 ;
break;
}
case V_79 :
{
T_3 * V_54 = V_63 ;
T_3 V_80 = V_5 -> V_54 ;
switch ( V_5 -> type ) {
case V_71 :
if ( V_81 && ( * V_54 & V_81 ) != * V_54 &&
* V_54 != V_82 &&
* V_54 != V_83 ) {
F_3 ( & V_2 -> V_18 ,
L_15 ) ;
V_5 -> V_54 = V_81 ;
} else if ( * V_54 & V_55 ) {
V_5 -> V_54 = V_55 ;
} else if ( * V_54 & V_56 ) {
V_5 -> V_54 = V_56 ;
} else if ( * V_54 & V_57 ) {
V_5 -> V_54 = V_57 ;
} else if ( * V_54 & V_58 ) {
V_5 -> V_54 = V_58 ;
} else {
F_13 ( & V_2 -> V_18 ,
L_16 ) ;
* V_54 = 0 ;
break;
}
if ( V_80 != V_5 -> V_54 )
F_9 ( V_2 ) ;
break;
case V_74 :
if ( ! ( * V_54 & V_75 ) ) {
F_13 ( & V_2 -> V_18 ,
L_16 ) ;
* V_54 = 0 ;
}
break;
case V_76 :
if ( ! ( * V_54 & V_77 ) ) {
F_13 ( & V_2 -> V_18 ,
L_16 ) ;
* V_54 = 0 ;
}
break;
}
break;
}
case V_84 :
{
T_3 * V_54 = V_63 ;
switch ( V_5 -> type ) {
case V_71 :
if ( V_81 )
* V_54 = V_81 ;
else
* V_54 = V_55 | V_56 |
V_57 | V_58 ;
break;
case V_74 :
* V_54 = V_75 ;
break;
case V_76 :
* V_54 = V_77 ;
break;
}
break;
}
case V_85 :
{
struct V_86 * V_10 = V_63 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
strcpy ( V_10 -> V_87 , L_17 ) ;
V_10 -> type = V_88 ;
V_10 -> V_89 = 0UL ;
V_10 -> V_90 = 0xffffffffUL ;
switch ( V_5 -> type ) {
case V_71 :
V_10 -> V_91 = V_92 |
V_93 | V_94 |
V_95 ;
V_10 -> V_96 = V_97 |
V_98 | V_99 |
V_100 ;
break;
case V_74 :
case V_76 :
V_10 -> V_91 = V_93 ;
V_10 -> V_96 = V_97 |
V_98 ;
break;
}
V_10 -> V_35 = V_5 -> V_35 ;
return 0 ;
}
case V_101 :
{
struct V_86 * V_10 = V_63 ;
switch ( V_5 -> type ) {
case V_71 :
if ( V_10 -> V_35 != V_5 -> V_35 ) {
V_5 -> V_35 = V_10 -> V_35 ;
F_7 ( V_2 ) ;
}
break;
case V_74 :
case V_76 :
break;
}
return 0 ;
}
default:
break;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_102 * V_73 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
struct V_4 * V_5 ;
if ( ! F_15 ( V_29 , V_104 ) )
return - V_105 ;
V_5 = F_16 ( sizeof( struct V_4 ) , V_106 ) ;
if ( V_5 == NULL )
return - V_107 ;
V_5 -> type = - 1 ;
V_5 -> V_3 = 0 ;
V_5 -> V_32 = 0 ;
V_5 -> V_35 = V_40 ;
F_17 ( V_2 , V_5 ) ;
F_3 ( & V_2 -> V_18 , L_18 ,
V_2 -> V_21 , V_29 -> V_87 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_19 ( V_5 ) ;
return 0 ;
}
