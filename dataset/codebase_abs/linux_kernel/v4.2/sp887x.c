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
switch ( V_36 -> V_39 ) {
case V_40 :
break;
case V_41 :
* V_37 |= ( 1 << 10 ) ;
break;
case V_42 :
* V_37 |= ( 2 << 10 ) ;
break;
case V_43 :
V_38 = 0 ;
break;
default:
return - V_44 ;
}
switch ( V_36 -> V_45 ) {
case V_46 :
break;
case V_47 :
* V_37 |= ( 1 << 7 ) ;
break;
case V_48 :
* V_37 |= ( 2 << 7 ) ;
break;
case V_49 :
* V_37 |= ( 3 << 7 ) ;
break;
case V_50 :
V_38 = 0 ;
break;
default:
return - V_44 ;
}
switch ( V_36 -> V_51 ) {
case V_52 :
break;
case V_53 :
* V_37 |= ( 1 << 3 ) ;
break;
case V_54 :
* V_37 |= ( 2 << 3 ) ;
break;
case V_55 :
* V_37 |= ( 3 << 3 ) ;
break;
case V_56 :
* V_37 |= ( 4 << 3 ) ;
break;
case V_57 :
V_38 = 0 ;
break;
default:
return - V_44 ;
}
if ( V_38 )
* V_37 |= ( 2 << 1 ) ;
else
* V_37 |= ( 1 << 1 ) ;
return 0 ;
}
static void F_12 ( int V_58 , int V_59 , int * V_60 , int * V_61 )
{
unsigned int V_62 , V_63 ;
V_63 = ( V_58 % V_59 ) << 8 ;
V_62 = ( V_63 / V_59 ) ;
if ( V_60 )
* V_60 = V_62 ;
if ( V_61 ) {
V_63 = ( V_63 % V_59 ) << 8 ;
V_62 = ( V_62 << 8 ) | ( V_63 / V_59 ) ;
V_63 = ( V_63 % V_59 ) << 8 ;
* V_61 = ( V_62 << 8 ) | ( V_63 / V_59 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_64 )
{
static const T_3 V_65 [] = { 1879617 , 4544878 , 8098561 } ;
int V_66 ;
int V_67 = V_64 - V_36 -> V_68 ;
int V_69 = 61003 ;
int V_70 = 36000000 ;
int V_71 ;
int V_72 ;
switch ( V_36 -> V_73 ) {
default:
case 8000000 :
V_66 = 0 ;
break;
case 7000000 :
V_66 = 1 ;
break;
case 6000000 :
V_66 = 2 ;
break;
}
if ( V_36 -> V_74 == V_75 )
V_71 = V_70 - V_67 ;
else
V_71 = V_70 + V_67 ;
F_12 ( V_71 / 333 , V_69 , NULL , & V_72 ) ;
if ( V_36 -> V_74 == V_75 )
V_72 = - V_72 ;
F_4 ( V_2 , 0x319 , V_65 [ V_66 ] >> 12 ) ;
F_4 ( V_2 , 0x31a , V_65 [ V_66 ] & 0xfff ) ;
F_4 ( V_2 , 0x309 , V_72 >> 12 ) ;
F_4 ( V_2 , 0x30a , V_72 & 0xfff ) ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_35 * V_36 = & V_23 -> V_76 ;
struct V_1 * V_2 = V_23 -> V_26 ;
unsigned V_64 ;
int V_11 ;
T_2 V_77 , V_37 ;
if ( V_36 -> V_73 != 8000000 &&
V_36 -> V_73 != 7000000 &&
V_36 -> V_73 != 6000000 )
return - V_44 ;
if ( ( V_11 = F_11 ( V_36 , & V_37 ) ) )
return V_11 ;
F_6 ( V_2 ) ;
if ( V_23 -> V_78 . V_79 . V_80 ) {
V_23 -> V_78 . V_79 . V_80 ( V_23 ) ;
if ( V_23 -> V_78 . V_81 ) V_23 -> V_78 . V_81 ( V_23 , 0 ) ;
}
if ( V_23 -> V_78 . V_79 . V_82 ) {
V_23 -> V_78 . V_79 . V_82 ( V_23 , & V_64 ) ;
if ( V_23 -> V_78 . V_81 ) V_23 -> V_78 . V_81 ( V_23 , 0 ) ;
} else {
V_64 = V_36 -> V_68 ;
}
F_5 ( V_2 , 0x200 ) ;
F_13 ( V_2 , V_36 , V_64 ) ;
if ( V_36 -> V_73 == 6000000 )
V_77 = 2 ;
else if ( V_36 -> V_73 == 7000000 )
V_77 = 1 ;
else
V_77 = 0 ;
F_4 ( V_2 , 0x311 , V_77 ) ;
if ( V_36 -> V_83 == V_84 )
F_4 ( V_2 , 0x338 , 0x000 ) ;
else
F_4 ( V_2 , 0x338 , 0x001 ) ;
F_4 ( V_2 , 0xc05 , V_37 ) ;
if ( V_36 -> V_73 == 6000000 )
V_77 = 2 << 3 ;
else if ( V_36 -> V_73 == 7000000 )
V_77 = 3 << 3 ;
else
V_77 = 0 << 3 ;
F_4 ( V_2 , 0xf14 , 0x160 | V_77 ) ;
F_4 ( V_2 , 0xf15 , 0x000 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_23 , enum V_85 * V_86 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_2 V_87 = F_5 ( V_2 , 0xf16 ) ;
T_2 V_88 = F_5 ( V_2 , 0x200 ) ;
T_2 V_89 = F_5 ( V_2 , 0xf17 ) ;
* V_86 = 0 ;
if ( V_87 > 0x00f )
* V_86 |= V_90 ;
if ( ( V_89 & 0x00f ) == 0x002 ) {
* V_86 |= V_91 ;
* V_86 |= V_92 | V_93 | V_94 ;
}
if ( V_88 & 0x001 ) {
int V_95 = ( V_88 >> 4 ) & 0x00f ;
if ( V_95 & 0x008 )
V_95 = - V_95 ;
F_7 ( L_9 ,
V_95 ) ;
}
return 0 ;
}
static int F_16 ( struct V_22 * V_23 , T_3 * V_96 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
* V_96 = ( F_5 ( V_2 , 0xc08 ) & 0x3f ) |
( F_5 ( V_2 , 0xc07 ) << 6 ) ;
F_4 ( V_2 , 0xc08 , 0x000 ) ;
F_4 ( V_2 , 0xc07 , 0x000 ) ;
if ( * V_96 >= 0x3fff0 )
* V_96 = ~ 0 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 , T_2 * V_97 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_2 V_87 = F_5 ( V_2 , 0xf16 ) ;
T_3 signal = 3 * ( V_87 << 4 ) ;
* V_97 = ( signal < 0xffff ) ? signal : 0xffff ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 , T_2 * V_98 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_2 V_87 = F_5 ( V_2 , 0xf16 ) ;
* V_98 = ( V_87 << 4 ) | ( V_87 >> 8 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 , T_3 * V_99 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
* V_99 = F_5 ( V_2 , 0xc0c ) ;
if ( * V_99 == 0xfff )
* V_99 = ~ 0 ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , int V_100 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
if ( V_100 ) {
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
if ( ! V_2 -> V_101 ) {
F_3 ( L_10 , V_102 ) ;
V_18 = V_2 -> V_8 -> V_103 ( V_23 , & V_25 , V_102 ) ;
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
V_2 -> V_101 = 1 ;
}
F_4 ( V_2 , 0xc18 , 0x00d ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 , struct V_104 * V_105 )
{
V_105 -> V_106 = 350 ;
V_105 -> V_107 = 166666 * 2 ;
V_105 -> V_108 = ( 166666 * 2 ) + 1 ;
return 0 ;
}
static void F_25 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
F_26 ( V_2 ) ;
}
struct V_22 * F_27 ( const struct V_109 * V_8 ,
struct V_110 * V_12 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_111 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_8 = V_8 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_101 = 0 ;
if ( F_5 ( V_2 , 0x0200 ) < 0 ) goto error;
memcpy ( & V_2 -> V_112 . V_78 , & V_113 , sizeof( struct V_114 ) ) ;
V_2 -> V_112 . V_26 = V_2 ;
return & V_2 -> V_112 ;
error:
F_26 ( V_2 ) ;
return NULL ;
}
