static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
struct V_5 V_6 = { . V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_3 = V_3 , . V_4 = V_4 } ;
int V_11 ;
if ( ( V_11 = F_2 ( V_2 -> V_12 , & V_6 , 1 ) ) != 1 ) {
F_3 ( L_1 ,
V_13 , V_2 -> V_8 -> V_9 , V_11 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_15 , T_2 V_16 )
{
T_1 V_17 [] = { V_15 >> 8 , V_15 & 0xff , V_16 >> 8 , V_16 & 0xff } ;
struct V_5 V_6 = { . V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_3 = V_17 , . V_4 = 4 } ;
int V_18 ;
if ( ( V_18 = F_2 ( V_2 -> V_12 , & V_6 , 1 ) ) != 1 ) {
if ( ! ( V_15 == 0xf1a && V_16 == 0x000 &&
( V_18 == - V_14 || V_18 == - V_19 ) ) )
{
F_3 ( L_2
L_3 ,
V_13 , V_15 & 0xffff , V_16 & 0xffff , V_18 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_15 )
{
T_1 V_17 [] = { V_15 >> 8 , V_15 & 0xff } ;
T_1 V_20 [ 2 ] ;
int V_18 ;
struct V_5 V_6 [] = { { . V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_3 = V_17 , . V_4 = 2 } ,
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = V_21 , . V_3 = V_20 , . V_4 = 2 } } ;
if ( ( V_18 = F_2 ( V_2 -> V_12 , V_6 , 2 ) ) != 2 ) {
F_3 ( L_4 , V_13 , V_18 ) ;
return - 1 ;
}
return ( ( ( V_20 [ 0 ] << 8 ) | V_20 [ 1 ] ) & 0xfff ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( L_5 , V_13 ) ;
F_4 ( V_2 , 0xf08 , 0x000 ) ;
F_4 ( V_2 , 0xf09 , 0x000 ) ;
F_4 ( V_2 , 0xf00 , 0x000 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_7 ( L_5 , V_13 ) ;
F_4 ( V_2 , 0xf08 , 0x000 ) ;
F_4 ( V_2 , 0xf09 , 0x000 ) ;
F_4 ( V_2 , 0xf00 , 0x001 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_7 ( L_5 , V_13 ) ;
F_4 ( V_2 , 0x33c , 0x054 ) ;
F_4 ( V_2 , 0x33b , 0x04c ) ;
F_4 ( V_2 , 0x328 , 0x000 ) ;
F_4 ( V_2 , 0x327 , 0x005 ) ;
F_4 ( V_2 , 0x326 , 0x001 ) ;
F_4 ( V_2 , 0x325 , 0x001 ) ;
F_4 ( V_2 , 0x324 , 0x001 ) ;
F_4 ( V_2 , 0x318 , 0x050 ) ;
F_4 ( V_2 , 0x317 , 0x3fe ) ;
F_4 ( V_2 , 0x316 , 0x001 ) ;
F_4 ( V_2 , 0x313 , 0x005 ) ;
F_4 ( V_2 , 0x312 , 0x002 ) ;
F_4 ( V_2 , 0x306 , 0x000 ) ;
F_4 ( V_2 , 0x303 , 0x000 ) ;
}
static int F_10 ( struct V_22 * V_23 , const struct V_24 * V_25 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_1 V_3 [ V_27 + 2 ] ;
int V_28 ;
int V_29 = V_25 -> V_30 ;
const unsigned char * V_31 = V_25 -> V_16 ;
F_7 ( L_5 , V_13 ) ;
if ( V_29 < V_32 + 10 )
return - V_33 ;
V_31 = V_25 -> V_16 + 10 ;
F_4 ( V_2 , 0xf1a , 0x000 ) ;
F_6 ( V_2 ) ;
F_3 ( L_6 , V_13 ) ;
F_4 ( V_2 , 0x8f08 , 0x1fff ) ;
F_4 ( V_2 , 0x8f0a , 0x0000 ) ;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 += V_27 ) {
int V_34 = V_27 ;
int V_11 ;
if ( V_28 + V_34 > V_32 )
V_34 = V_32 - V_28 ;
V_3 [ 0 ] = 0xcf ;
V_3 [ 1 ] = 0x0a ;
memcpy ( & V_3 [ 2 ] , V_31 + V_28 , V_34 ) ;
if ( ( V_11 = F_1 ( V_2 , V_3 , V_34 + 2 ) ) < 0 ) {
F_3 ( L_7 ) ;
F_3 ( L_8 , V_13 , V_11 ) ;
return V_11 ;
}
}
F_4 ( V_2 , 0xc13 , 0x001 ) ;
F_4 ( V_2 , 0xc14 , 0x000 ) ;
F_4 ( V_2 , 0xc1a , 0x872 ) ;
F_4 ( V_2 , 0xc1b , 0x001 ) ;
F_4 ( V_2 , 0xc1c , 0x000 ) ;
F_4 ( V_2 , 0xc1a , 0x871 ) ;
F_4 ( V_2 , 0x301 , 0x002 ) ;
F_9 ( V_2 ) ;
F_4 ( V_2 , 0xd00 , 0x010 ) ;
F_4 ( V_2 , 0x0d1 , 0x000 ) ;
return 0 ;
}
static int F_11 ( struct V_35 * V_36 , T_2 * V_37 )
{
int V_38 = 1 ;
* V_37 = 0x000 ;
switch ( V_36 -> V_39 . V_40 . V_41 ) {
case V_42 :
break;
case V_43 :
* V_37 |= ( 1 << 10 ) ;
break;
case V_44 :
* V_37 |= ( 2 << 10 ) ;
break;
case V_45 :
V_38 = 0 ;
break;
default:
return - V_46 ;
} ;
switch ( V_36 -> V_39 . V_40 . V_47 ) {
case V_48 :
break;
case V_49 :
* V_37 |= ( 1 << 7 ) ;
break;
case V_50 :
* V_37 |= ( 2 << 7 ) ;
break;
case V_51 :
* V_37 |= ( 3 << 7 ) ;
break;
case V_52 :
V_38 = 0 ;
break;
default:
return - V_46 ;
} ;
switch ( V_36 -> V_39 . V_40 . V_53 ) {
case V_54 :
break;
case V_55 :
* V_37 |= ( 1 << 3 ) ;
break;
case V_56 :
* V_37 |= ( 2 << 3 ) ;
break;
case V_57 :
* V_37 |= ( 3 << 3 ) ;
break;
case V_58 :
* V_37 |= ( 4 << 3 ) ;
break;
case V_59 :
V_38 = 0 ;
break;
default:
return - V_46 ;
} ;
if ( V_38 )
* V_37 |= ( 2 << 1 ) ;
else
* V_37 |= ( 1 << 1 ) ;
return 0 ;
}
static void F_12 ( int V_60 , int V_61 , int * V_62 , int * V_63 )
{
unsigned int V_64 , V_65 ;
V_65 = ( V_60 % V_61 ) << 8 ;
V_64 = ( V_65 / V_61 ) ;
if ( V_62 )
* V_62 = V_64 ;
if ( V_63 ) {
V_65 = ( V_65 % V_61 ) << 8 ;
V_64 = ( V_64 << 8 ) | ( V_65 / V_61 ) ;
V_65 = ( V_65 % V_61 ) << 8 ;
* V_63 = ( V_64 << 8 ) | ( V_65 / V_61 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_66 )
{
static const T_3 V_67 [] = { 1879617 , 4544878 , 8098561 } ;
int V_68 = V_36 -> V_39 . V_40 . V_69 - V_70 ;
int V_71 = V_66 - V_36 -> V_72 ;
int V_73 = 61003 ;
int V_74 = 36000000 ;
int V_75 ;
int V_76 ;
if ( V_36 -> V_77 == V_78 )
V_75 = V_74 - V_71 ;
else
V_75 = V_74 + V_71 ;
F_12 ( V_75 / 333 , V_73 , NULL , & V_76 ) ;
if ( V_36 -> V_77 == V_78 )
V_76 = - V_76 ;
F_4 ( V_2 , 0x319 , V_67 [ V_68 ] >> 12 ) ;
F_4 ( V_2 , 0x31a , V_67 [ V_68 ] & 0xfff ) ;
F_4 ( V_2 , 0x309 , V_76 >> 12 ) ;
F_4 ( V_2 , 0x30a , V_76 & 0xfff ) ;
}
static int F_14 ( struct V_22 * V_23 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
unsigned V_66 ;
int V_11 ;
T_2 V_79 , V_37 ;
if ( V_36 -> V_39 . V_40 . V_69 != V_70 &&
V_36 -> V_39 . V_40 . V_69 != V_80 &&
V_36 -> V_39 . V_40 . V_69 != V_81 )
return - V_46 ;
if ( ( V_11 = F_11 ( V_36 , & V_37 ) ) )
return V_11 ;
F_6 ( V_2 ) ;
if ( V_23 -> V_82 . V_83 . V_84 ) {
V_23 -> V_82 . V_83 . V_84 ( V_23 , V_36 ) ;
if ( V_23 -> V_82 . V_85 ) V_23 -> V_82 . V_85 ( V_23 , 0 ) ;
}
if ( V_23 -> V_82 . V_83 . V_86 ) {
V_23 -> V_82 . V_83 . V_86 ( V_23 , & V_66 ) ;
if ( V_23 -> V_82 . V_85 ) V_23 -> V_82 . V_85 ( V_23 , 0 ) ;
} else {
V_66 = V_36 -> V_72 ;
}
F_5 ( V_2 , 0x200 ) ;
F_13 ( V_2 , V_36 , V_66 ) ;
if ( V_36 -> V_39 . V_40 . V_69 == V_81 )
V_79 = 2 ;
else if ( V_36 -> V_39 . V_40 . V_69 == V_80 )
V_79 = 1 ;
else
V_79 = 0 ;
F_4 ( V_2 , 0x311 , V_79 ) ;
if ( V_36 -> V_39 . V_40 . V_87 == V_88 )
F_4 ( V_2 , 0x338 , 0x000 ) ;
else
F_4 ( V_2 , 0x338 , 0x001 ) ;
F_4 ( V_2 , 0xc05 , V_37 ) ;
if ( V_36 -> V_39 . V_40 . V_69 == V_81 )
V_79 = 2 << 3 ;
else if ( V_36 -> V_39 . V_40 . V_69 == V_80 )
V_79 = 3 << 3 ;
else
V_79 = 0 << 3 ;
F_4 ( V_2 , 0xf14 , 0x160 | V_79 ) ;
F_4 ( V_2 , 0xf15 , 0x000 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_23 , T_4 * V_89 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_2 V_90 = F_5 ( V_2 , 0xf16 ) ;
T_2 V_91 = F_5 ( V_2 , 0x200 ) ;
T_2 V_92 = F_5 ( V_2 , 0xf17 ) ;
* V_89 = 0 ;
if ( V_90 > 0x00f )
* V_89 |= V_93 ;
if ( ( V_92 & 0x00f ) == 0x002 ) {
* V_89 |= V_94 ;
* V_89 |= V_95 | V_96 | V_97 ;
}
if ( V_91 & 0x001 ) {
int V_98 = ( V_91 >> 4 ) & 0x00f ;
if ( V_98 & 0x008 )
V_98 = - V_98 ;
F_7 ( L_9 ,
V_98 ) ;
}
return 0 ;
}
static int F_16 ( struct V_22 * V_23 , T_3 * V_99 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
* V_99 = ( F_5 ( V_2 , 0xc08 ) & 0x3f ) |
( F_5 ( V_2 , 0xc07 ) << 6 ) ;
F_4 ( V_2 , 0xc08 , 0x000 ) ;
F_4 ( V_2 , 0xc07 , 0x000 ) ;
if ( * V_99 >= 0x3fff0 )
* V_99 = ~ 0 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 , T_2 * V_100 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_2 V_90 = F_5 ( V_2 , 0xf16 ) ;
T_3 signal = 3 * ( V_90 << 4 ) ;
* V_100 = ( signal < 0xffff ) ? signal : 0xffff ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 , T_2 * V_101 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_2 V_90 = F_5 ( V_2 , 0xf16 ) ;
* V_101 = ( V_90 << 4 ) | ( V_90 >> 8 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 , T_3 * V_102 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
* V_102 = F_5 ( V_2 , 0xc0c ) ;
if ( * V_102 == 0xfff )
* V_102 = ~ 0 ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , int V_103 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
if ( V_103 ) {
return F_4 ( V_2 , 0x206 , 0x001 ) ;
} else {
return F_4 ( V_2 , 0x206 , 0x000 ) ;
}
}
static int F_21 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_4 ( V_2 , 0xc18 , 0x000 ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
const struct V_24 * V_25 = NULL ;
int V_18 ;
if ( ! V_2 -> V_104 ) {
F_3 ( L_10 , V_105 ) ;
V_18 = V_2 -> V_8 -> V_106 ( V_23 , & V_25 , V_105 ) ;
if ( V_18 ) {
F_3 ( L_11 ) ;
return V_18 ;
}
V_18 = F_10 ( V_23 , V_25 ) ;
F_23 ( V_25 ) ;
if ( V_18 ) {
F_3 ( L_12 ) ;
return V_18 ;
}
F_3 ( L_13 ) ;
V_2 -> V_104 = 1 ;
}
F_4 ( V_2 , 0xc18 , 0x00d ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 , struct V_107 * V_108 )
{
V_108 -> V_109 = 350 ;
V_108 -> V_110 = 166666 * 2 ;
V_108 -> V_111 = ( 166666 * 2 ) + 1 ;
return 0 ;
}
static void F_25 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_26 ( V_2 ) ;
}
struct V_22 * F_27 ( const struct V_112 * V_8 ,
struct V_113 * V_12 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_114 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_8 = V_8 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_104 = 0 ;
if ( F_5 ( V_2 , 0x0200 ) < 0 ) goto error;
memcpy ( & V_2 -> V_115 . V_82 , & V_116 , sizeof( struct V_117 ) ) ;
V_2 -> V_115 . V_26 = V_2 ;
return & V_2 -> V_115 ;
error:
F_26 ( V_2 ) ;
return NULL ;
}
