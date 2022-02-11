static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 >> 8 , V_4 & 0xff } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 , . V_6 = V_6 , . V_13 = 3 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( V_15 L_1
L_2 , V_16 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static T_2 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_17 [] = { V_3 } ;
T_1 V_18 [] = { 0 , 0 } ;
struct V_7 V_8 [] = {
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 ,
. V_6 = V_17 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_19 ,
. V_6 = V_18 , . V_13 = 2 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( L_3 , V_16 , V_5 ) ;
return ( V_18 [ 0 ] << 8 ) | V_18 [ 1 ] ;
}
static int F_5 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_4 , V_16 ) ;
F_1 ( V_2 , 0xf5 , 0 ) ;
F_1 ( V_2 , 0xf5 , 1 ) ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = V_25 ;
return 0 ;
}
static int F_7 ( struct V_20 * V_21 , int V_26 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_5 , V_16 , V_26 ) ;
switch ( V_26 ) {
case 4000 :
F_1 ( V_2 , 0x87 , 0x014b ) ;
F_1 ( V_2 , 0x88 , 0x0cb5 ) ;
F_1 ( V_2 , 0x89 , 0x03e2 ) ;
break;
case 5380 :
case 44000 :
default:
F_1 ( V_2 , 0x87 , 0x01be ) ;
F_1 ( V_2 , 0x88 , 0x0436 ) ;
F_1 ( V_2 , 0x89 , 0x054d ) ;
break;
}
V_2 -> V_27 = V_26 ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 , int V_28 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_6 , V_16 , V_28 ) ;
if ( V_28 == 1 )
return F_1 ( V_2 , 0x1b , 0x1101 ) ;
else
return F_1 ( V_2 , 0x1b , 0x0110 ) ;
}
static int F_9 ( struct V_20 * V_21 ,
enum V_29 V_30 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_7 , V_16 , V_30 ) ;
switch ( V_30 ) {
case V_31 :
F_6 ( L_8 , V_16 ) ;
if ( V_2 -> V_27 != V_32 )
F_7 ( V_21 , V_32 ) ;
F_1 ( V_2 , 0xf4 , 0 ) ;
break;
case V_33 :
case V_34 :
case V_35 :
F_6 ( L_9 , V_16 ) ;
if ( V_2 -> V_27 != V_36 )
F_7 ( V_21 , V_36 ) ;
F_1 ( V_2 , 0xf4 , 1 ) ;
F_1 ( V_2 , 0x85 , 0x110 ) ;
break;
default:
F_6 ( L_10 , V_16 ) ;
return - V_37 ;
}
V_2 -> V_38 = V_30 ;
F_5 ( V_21 ) ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 , int V_39 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_6 , V_16 , V_39 ) ;
if ( V_39 )
return F_1 ( V_2 , 0xf3 , 1 ) ;
else
return F_1 ( V_2 , 0xf3 , 0 ) ;
}
static int F_11 ( struct V_20 * V_21 , int V_39 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_6 , V_16 , V_39 ) ;
if ( V_39 )
return F_1 ( V_2 , 0xe3 ,
F_4 ( V_2 , 0xe3 ) | 0x1100 ) ;
else
return F_1 ( V_2 , 0xe3 ,
F_4 ( V_2 , 0xe3 ) & 0xfeff ) ;
}
static int F_12 ( struct V_20 * V_21 , int V_39 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_6 , V_16 , V_39 ) ;
return F_1 ( V_2 , 0xf2 , V_39 ) ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_4 , V_16 ) ;
return F_1 ( V_2 , 0xfa , 0 ) ;
}
static void F_14 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_3 ;
if ( V_2 -> V_24 < V_40 ) {
return;
}
if ( V_2 -> V_24 == V_41 ) {
return;
}
V_3 = F_4 ( V_2 , 0xf0 ) ;
if ( ( V_3 >> 13 ) & 0x1 ) {
V_3 &= 0xff ;
F_1 ( V_2 , 0x96 , 0x000c ) ;
if ( V_3 < 0x68 ) {
if ( V_2 -> V_24 < V_41 ) {
F_6 ( L_11 ,
V_16 ) ;
F_1 ( V_2 , 0x93 , 0x3130 ) ;
F_1 ( V_2 , 0x9e , 0x2836 ) ;
V_2 -> V_24 = V_41 ;
}
} else {
if ( V_2 -> V_24 < V_42 ) {
F_6 ( L_12 ,
V_16 ) ;
F_1 ( V_2 , 0x93 , 0x3332 ) ;
F_1 ( V_2 , 0x9e , 0x2c37 ) ;
V_2 -> V_24 = V_42 ;
}
}
} else {
if ( V_2 -> V_24 < V_43 ) {
F_6 ( L_13 , V_16 ) ;
F_1 ( V_2 , 0x96 , 0x0008 ) ;
F_1 ( V_2 , 0x93 , 0x3332 ) ;
F_1 ( V_2 , 0x9e , 0x2c37 ) ;
V_2 -> V_24 = V_43 ;
}
}
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_3 ;
if ( V_2 -> V_23 )
return;
V_3 = F_4 ( V_2 , 0xf0 ) ;
if ( ( V_3 >> 13 ) & 0x1 ) {
V_2 -> V_23 = 1 ;
V_3 &= 0xff ;
F_1 ( V_2 , 0x96 , 0x00c ) ;
if ( ( V_3 < 0x38 ) || ( V_3 > 0x68 ) ) {
F_1 ( V_2 , 0x93 , 0x3332 ) ;
F_1 ( V_2 , 0x9e , 0x2c37 ) ;
} else {
F_1 ( V_2 , 0x93 , 0x3130 ) ;
F_1 ( V_2 , 0x9e , 0x2836 ) ;
}
} else {
F_1 ( V_2 , 0x96 , 0x0008 ) ;
F_1 ( V_2 , 0x93 , 0x3332 ) ;
F_1 ( V_2 , 0x9e , 0x2c37 ) ;
}
}
static void F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_3 , V_44 , V_45 ;
if ( V_2 -> V_24 >= V_40 ) {
return;
}
V_3 = F_4 ( V_2 , 0xf1 ) ;
if ( ( V_3 >> 15 ) & 0x1 ) {
if ( V_2 -> V_24 == V_25 ||
V_2 -> V_24 == V_46 ) {
F_6 ( L_14 ,
V_16 ) ;
V_44 = F_4 ( V_2 , 0xb2 ) ;
V_45 = F_4 ( V_2 , 0xad ) ;
F_1 ( V_2 , 0x96 , 0x0020 ) ;
F_1 ( V_2 , 0xad ,
( ( ( V_44 & 0xf000 ) >> 4 ) | ( V_45 & 0xf0ff ) ) ) ;
V_2 -> V_24 = V_40 ;
}
} else {
if ( V_2 -> V_24 == V_25 ) {
F_6 ( L_15 ,
V_16 ) ;
F_1 ( V_2 , 0x96 , 0x08 ) ;
F_1 ( V_2 , 0xab ,
F_4 ( V_2 , 0xab ) | 0x1001 ) ;
V_2 -> V_24 = V_46 ;
}
}
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_3 , V_44 , V_45 ;
V_3 = F_4 ( V_2 , 0xf1 ) ;
if ( ( V_3 >> 15 ) & 0x1 ) {
if ( V_2 -> V_24 != 2 ) {
V_2 -> V_24 = 2 ;
V_44 = F_4 ( V_2 , 0xb2 ) ;
V_45 = F_4 ( V_2 , 0xad ) ;
F_1 ( V_2 , 0x96 , 0x20 ) ;
F_1 ( V_2 , 0xad ,
( ( ( V_44 & 0xf000 ) >> 4 ) | ( V_45 & 0xf0ff ) ) ) ;
F_1 ( V_2 , 0xab ,
F_4 ( V_2 , 0xab ) & 0xeffe ) ;
}
} else {
if ( V_2 -> V_24 != 1 ) {
V_2 -> V_24 = 1 ;
F_1 ( V_2 , 0x96 , 0x08 ) ;
F_1 ( V_2 , 0xab ,
F_4 ( V_2 , 0xab ) | 0x1001 ) ;
}
}
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_47 * V_48 = & V_21 -> V_49 ;
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_16 , V_16 , V_48 -> V_50 ) ;
F_5 ( V_21 ) ;
V_2 -> V_51 = V_48 -> V_50 ;
F_9 ( V_21 , V_48 -> V_52 ) ;
if ( V_21 -> V_53 . V_54 . V_55 ) {
if ( V_21 -> V_53 . V_56 )
V_21 -> V_53 . V_56 ( V_21 , 1 ) ;
V_21 -> V_53 . V_54 . V_55 ( V_21 ) ;
if ( V_21 -> V_53 . V_56 )
V_21 -> V_53 . V_56 ( V_21 , 0 ) ;
}
F_5 ( V_21 ) ;
if ( V_2 -> V_38 != V_31 ) {
if ( V_2 -> V_10 -> V_57 == V_58 ) {
F_16 ( V_21 ) ;
F_14 ( V_21 ) ;
} else {
F_15 ( V_21 ) ;
F_17 ( V_21 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , int V_59 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_60 ;
F_6 ( L_6 , V_16 , V_59 ) ;
V_60 = F_4 ( V_2 , 0xac ) & 0xcfff ;
switch ( V_59 ) {
case V_61 :
V_60 |= 0x0000 ;
break;
case V_62 :
F_6 ( L_17 , V_16 , V_59 ) ;
V_60 |= 0x1000 ;
break;
case V_63 :
V_60 |= 0x2000 ;
break;
case V_64 :
V_60 |= 0x3000 ;
break;
default:
return - V_37 ;
}
return F_1 ( V_2 , 0xac , V_60 ) ;
}
static int F_20 ( struct V_20 * V_21 )
{
int V_65 ;
struct V_1 * V_2 = V_21 -> V_22 ;
F_6 ( L_4 , V_16 ) ;
F_12 ( V_21 , 0 ) ;
F_13 ( V_21 ) ;
for ( V_65 = 0 ; V_65 < F_21 ( V_66 ) ; V_65 ++ )
F_1 ( V_2 , V_66 [ V_65 ] . V_3 , V_66 [ V_65 ] . V_4 ) ;
V_2 -> V_38 = V_31 ;
if ( V_2 -> V_10 -> V_57 == V_58 ) {
F_1 ( V_2 , 0x09 , 0x0050 ) ;
F_1 ( V_2 , 0x21 , 0x0001 ) ;
F_1 ( V_2 , 0x50 , 0x030e ) ;
F_1 ( V_2 , 0x82 , 0x0800 ) ;
}
if ( V_2 -> V_10 -> V_67 == V_68 )
F_1 ( V_2 , 0xab ,
F_4 ( V_2 , 0xab ) | 0x100 ) ;
else
F_1 ( V_2 , 0xab ,
F_4 ( V_2 , 0xab ) & 0xfeff ) ;
F_8 ( V_21 , V_2 -> V_10 -> V_69 ) ;
F_7 ( V_21 , V_2 -> V_27 ) ;
F_11 ( V_21 , V_2 -> V_10 -> V_70 ) ;
F_19 ( V_21 , V_2 -> V_10 -> V_71 ) ;
F_5 ( V_21 ) ;
F_10 ( V_21 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 , enum V_72 * V_73 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_3 ;
T_3 V_74 = 0 ;
* V_73 = 0 ;
if ( V_2 -> V_38 != V_31 ) {
if ( V_2 -> V_10 -> V_57 == V_58 ) {
F_16 ( V_21 ) ;
F_14 ( V_21 ) ;
}
}
V_3 = F_4 ( V_2 , 0xf1 ) ;
if ( V_3 & 0x1000 )
* V_73 |= V_75 ;
if ( V_3 & 0x8000 )
* V_73 |= V_76 | V_77 ;
switch ( V_2 -> V_10 -> V_78 ) {
case V_79 :
if ( * V_73 & V_75 )
* V_73 |= V_80 | V_81 ;
break;
case V_82 :
if ( V_21 -> V_53 . V_54 . V_83 ) {
if ( V_21 -> V_53 . V_56 )
V_21 -> V_53 . V_56 ( V_21 , 1 ) ;
V_21 -> V_53 . V_54 . V_83 ( V_21 , & V_74 ) ;
if ( V_21 -> V_53 . V_56 )
V_21 -> V_53 . V_56 ( V_21 , 0 ) ;
}
if ( V_74 )
* V_73 |= V_80 | V_81 ;
break;
}
F_6 ( L_18 , V_16 , * V_73 ) ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 , T_2 * V_84 , T_2 V_85 )
{
int V_65 , V_5 = - V_37 ;
F_6 ( L_4 , V_16 ) ;
for ( V_65 = 0 ; V_65 < F_21 ( V_86 ) ; V_65 ++ ) {
if ( V_85 < V_86 [ V_65 ] . V_60 ) {
* V_84 = V_86 [ V_65 ] . V_4 ;
V_5 = 0 ;
break;
}
}
return V_5 ;
}
static int F_24 ( struct V_20 * V_21 , T_2 * V_84 , T_2 V_85 )
{
int V_65 , V_5 = - V_37 ;
F_6 ( L_4 , V_16 ) ;
for ( V_65 = 0 ; V_65 < F_21 ( V_87 ) ; V_65 ++ ) {
if ( V_85 < V_87 [ V_65 ] . V_60 ) {
* V_84 = V_87 [ V_65 ] . V_4 ;
V_5 = 0 ;
break;
}
}
return V_5 ;
}
static int F_25 ( struct V_20 * V_21 , T_2 * V_84 , T_2 V_85 )
{
int V_65 , V_5 = - V_37 ;
F_6 ( L_4 , V_16 ) ;
for ( V_65 = 0 ; V_65 < F_21 ( V_88 ) ; V_65 ++ ) {
if ( V_85 > V_88 [ V_65 ] . V_60 ) {
* V_84 = V_88 [ V_65 ] . V_4 ;
V_5 = 0 ;
break;
}
}
F_6 ( L_19 , V_16 , * V_84 ) ;
return V_5 ;
}
static int F_26 ( struct V_20 * V_21 , T_2 * V_84 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_3 ;
F_6 ( L_4 , V_16 ) ;
switch ( V_2 -> V_38 ) {
case V_33 :
V_3 = F_4 ( V_2 , 0xf0 ) & 0xff ;
return F_24 ( V_21 , V_84 , V_3 ) ;
case V_34 :
V_3 = F_4 ( V_2 , 0xf0 ) & 0xff ;
return F_23 ( V_21 , V_84 , V_3 ) ;
case V_31 :
V_3 = F_4 ( V_2 , 0xf1 ) & 0x3ff ;
return F_25 ( V_21 , V_84 , V_3 ) ;
default:
break;
}
return - V_37 ;
}
static int F_27 ( struct V_20 * V_21 ,
T_2 * V_89 )
{
T_2 V_84 ;
T_3 V_90 ;
int V_5 = F_26 ( V_21 , & V_84 ) ;
* V_89 = 0 ;
if ( 0 == V_5 ) {
V_90 = ( V_84 * ( ( 1 << 24 ) / 10 ) ) ;
if ( V_90 >= 8960 * 0x10000 )
* V_89 = 0xffff ;
else
* V_89 = V_90 / 8960 ;
}
return V_5 ;
}
static int F_28 ( struct V_20 * V_21 , T_3 * V_91 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
* V_91 = F_4 ( V_2 , 0xb5 ) ;
return 0 ;
}
static int F_29 ( struct V_20 * V_21 , T_3 * V_92 )
{
return F_28 ( V_21 , V_92 ) ;
}
static int F_30 ( struct V_20 * V_21 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
V_48 -> V_50 = V_2 -> V_51 ;
V_48 -> V_52 = V_2 -> V_38 ;
return 0 ;
}
static int F_31 ( struct V_20 * V_21 ,
struct V_93 * V_94 )
{
V_94 -> V_95 = 1000 ;
return 0 ;
}
static void F_32 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_33 ( V_2 ) ;
}
struct V_20 * F_34 ( const struct V_96 * V_10 ,
struct V_97 * V_14 )
{
struct V_1 * V_2 = NULL ;
T_2 V_3 ;
V_2 = F_35 ( sizeof( struct V_1 ) , V_98 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_38 = 0 ;
V_2 -> V_27 = V_32 ;
V_3 = F_4 ( V_2 , 0x04 ) ;
if ( ( V_3 != 0x0066 ) && ( V_3 != 0x007f ) )
goto error;
memcpy ( & V_2 -> V_99 . V_53 , & V_100 ,
sizeof( struct V_101 ) ) ;
V_2 -> V_99 . V_22 = V_2 ;
if ( F_20 ( & V_2 -> V_99 ) != 0 ) {
F_3 ( V_15 L_20 ,
V_16 ) ;
goto error;
}
F_10 ( & V_2 -> V_99 , 1 ) ;
return & V_2 -> V_99 ;
error:
F_33 ( V_2 ) ;
return NULL ;
}
