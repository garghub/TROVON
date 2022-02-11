static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 ,
. V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
int V_13 ;
F_2 ( L_1 , V_14 , V_3 , V_4 ) ;
V_13 = F_3 ( V_2 -> V_15 , & V_7 , 1 ) ;
if ( V_13 != 1 ) {
F_4 ( V_16 L_2
L_3 , V_14 , V_13 , V_3 , V_4 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_18 * V_19 , int V_20 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
if ( V_20 )
F_1 ( V_2 , 0x03 , 0x12 ) ;
else
F_1 ( V_2 , 0x03 , 0x02 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
const T_1 * V_4 , T_2 V_12 )
{
int V_22 , V_23 = 0 ;
struct V_6 V_7 ;
T_1 * V_5 ;
V_5 = F_7 ( 33 , V_24 ) ;
if ( V_5 == NULL ) {
F_4 ( V_16 L_4 ) ;
return - V_25 ;
}
* ( V_5 ) = V_3 ;
V_7 . V_8 = V_2 -> V_9 -> V_10 ;
V_7 . V_11 = 0 ;
V_7 . V_5 = V_5 ;
V_7 . V_12 = 33 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 += 32 ) {
memcpy ( V_5 + 1 , V_4 + V_22 , 32 ) ;
F_2 ( L_5 , V_14 , V_3 , V_12 ) ;
V_23 = F_3 ( V_2 -> V_15 , & V_7 , 1 ) ;
if ( V_23 != 1 ) {
F_4 ( V_16 L_6
L_7 , V_14 , V_23 , V_3 ) ;
V_23 = - V_17 ;
goto error;
}
}
V_23 = 0 ;
error:
F_8 ( V_5 ) ;
return V_23 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_23 ;
T_1 V_26 [] = { V_3 } ;
T_1 V_27 [] = { 0 } ;
struct V_6 V_7 [] = {
{
. V_8 = V_2 -> V_9 -> V_10 ,
. V_11 = 0 ,
. V_5 = V_26 ,
. V_12 = 1
} , {
. V_8 = V_2 -> V_9 -> V_10 ,
. V_11 = V_28 ,
. V_5 = V_27 ,
. V_12 = 1
}
} ;
V_23 = F_3 ( V_2 -> V_15 , V_7 , 2 ) ;
if ( V_23 != 2 ) {
F_4 ( V_16 L_8 , V_14 , V_3 , V_23 ) ;
return V_23 ;
}
F_2 ( L_9 , V_14 , V_3 , V_27 [ 0 ] ) ;
return V_27 [ 0 ] ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
const struct V_29 * V_30 ;
int V_23 = 0 ;
F_2 ( L_10 , V_14 ) ;
V_23 = F_9 ( V_2 , 0xb2 ) ;
if ( V_23 < 0 )
return V_23 ;
F_4 ( V_31 L_11 , V_14 ,
V_32 ) ;
V_23 = F_11 ( & V_30 , V_32 ,
V_2 -> V_15 -> V_33 . V_34 ) ;
F_4 ( V_31 L_12 , V_14 ) ;
if ( V_23 ) {
F_4 ( V_16 L_13
L_14 , V_14 ) ;
return V_23 ;
}
V_23 = F_12 ( V_19 , V_30 ) ;
if ( V_23 )
F_4 ( L_15 , V_14 ) ;
F_13 ( V_30 ) ;
F_2 ( L_16 , V_14 ,
V_23 == 0 ? L_17 : L_18 ) ;
return V_23 ;
}
static int F_12 ( struct V_18 * V_19 ,
const struct V_29 * V_30 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
int V_23 = 0 ;
F_2 ( L_19 , V_14 ) ;
F_2 ( L_20 ,
V_30 -> V_35 ,
V_30 -> V_4 [ 0 ] ,
V_30 -> V_4 [ 1 ] ,
V_30 -> V_4 [ V_30 -> V_35 - 2 ] ,
V_30 -> V_4 [ V_30 -> V_35 - 1 ] ) ;
F_1 ( V_2 , 0xb2 , 0x01 ) ;
V_23 = F_6 ( V_2 , 0xb0 , V_30 -> V_4 , V_30 -> V_35 ) ;
F_1 ( V_2 , 0xb2 , 0x00 ) ;
return V_23 ;
}
static int F_14 ( struct V_18 * V_19 , T_3 V_36 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
T_1 V_4 ;
F_2 ( L_21 , V_14 , V_36 ) ;
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 |= 0x03 ;
switch ( V_36 ) {
case V_37 :
V_4 &= ~ 0x03 ;
break;
case V_38 :
V_4 &= ~ 0x03 ;
V_4 |= 0x01 ;
break;
case V_39 :
break;
}
F_1 ( V_2 , 0xa2 , V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 , T_4 * V_40 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_41 * V_42 = & V_19 -> V_43 ;
int V_44 ;
* V_40 = 0 ;
switch ( V_42 -> V_45 ) {
case V_46 :
V_44 = F_9 ( V_2 , 0xd1 ) ;
if ( ( V_44 & 0x07 ) == 0x07 )
* V_40 = V_47 | V_48 |
V_49 | V_50 |
V_51 ;
break;
case V_52 :
V_44 = F_9 ( V_2 , 0x0d ) ;
if ( ( V_44 & 0x8f ) == 0x8f )
* V_40 = V_47 | V_48 |
V_49 | V_50 |
V_51 ;
break;
default:
return 1 ;
}
if ( V_2 -> V_9 -> V_53 )
V_2 -> V_9 -> V_53 ( V_19 , * V_40 == 0 ? 0 : 1 ) ;
F_2 ( L_22 , V_14 , V_44 ) ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 , T_5 * V_54 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_41 * V_42 = & V_19 -> V_43 ;
T_1 V_4 ;
T_5 V_55 , V_56 ;
F_2 ( L_10 , V_14 ) ;
switch ( V_42 -> V_45 ) {
case V_46 :
F_1 ( V_2 , 0xf9 , 0x04 ) ;
V_4 = F_9 ( V_2 , 0xf8 ) ;
if ( ( V_4 & 0x10 ) == 0 ) {
* V_54 = ( F_9 ( V_2 , 0xf7 ) << 8 ) |
F_9 ( V_2 , 0xf6 ) ;
V_4 |= 0x10 ;
F_1 ( V_2 , 0xf8 , V_4 ) ;
F_1 ( V_2 , 0xf8 , V_4 ) ;
} else
* V_54 = 0xffffffff ;
break;
case V_52 :
V_56 = ( F_9 ( V_2 , 0xd7 ) << 16 ) |
( F_9 ( V_2 , 0xd6 ) << 8 ) |
F_9 ( V_2 , 0xd5 ) ;
V_55 = ( F_9 ( V_2 , 0xf8 ) << 8 ) |
F_9 ( V_2 , 0xf7 ) ;
if ( V_56 > 750 ) {
F_1 ( V_2 , 0xd1 , 0x01 ) ;
F_1 ( V_2 , 0xf9 , 0x01 ) ;
F_1 ( V_2 , 0xf9 , 0x00 ) ;
F_1 ( V_2 , 0xd1 , 0x00 ) ;
* V_54 = V_55 ;
} else
* V_54 = 0xffffffff ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_17 ( struct V_18 * V_19 ,
T_2 * V_57 )
{
if ( V_19 -> V_58 . V_59 . V_60 )
V_19 -> V_58 . V_59 . V_60 ( V_19 , V_57 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , T_2 * V_61 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_41 * V_42 = & V_19 -> V_43 ;
T_1 V_62 , V_63 ;
T_5 V_64 , V_65 , V_66 ;
static const T_2 V_67 [] = {
0x0000 , 0x1b13 , 0x2aea , 0x3627 , 0x3ede , 0x45fe , 0x4c03 ,
0x513a , 0x55d4 , 0x59f2 , 0x5dab , 0x6111 , 0x6431 , 0x6717 ,
0x69c9 , 0x6c4e , 0x6eac , 0x70e8 , 0x7304 , 0x7505
} ;
static const T_2 V_68 [] = {
0x0000 , 0x0bc2 , 0x12a3 , 0x1785 , 0x1b4e , 0x1e65 , 0x2103 ,
0x2347 , 0x2546 , 0x2710 , 0x28ae , 0x2a28 , 0x2b83 , 0x2cc5 ,
0x2df1 , 0x2f09 , 0x3010 , 0x3109 , 0x31f4 , 0x32d2 , 0x33a6 ,
0x3470 , 0x3531 , 0x35ea , 0x369b , 0x3746 , 0x37ea , 0x3888 ,
0x3920 , 0x39b3 , 0x3a42 , 0x3acc , 0x3b51 , 0x3bd3 , 0x3c51 ,
0x3ccb , 0x3d42 , 0x3db6 , 0x3e27 , 0x3e95 , 0x3f00 , 0x3f68 ,
0x3fcf , 0x4033 , 0x4094 , 0x40f4 , 0x4151 , 0x41ac , 0x4206 ,
0x425e , 0x42b4 , 0x4308 , 0x435b , 0x43ac , 0x43fc , 0x444a ,
0x4497 , 0x44e2 , 0x452d , 0x4576 , 0x45bd , 0x4604 , 0x4649 ,
0x468e , 0x46d1 , 0x4713 , 0x4755 , 0x4795 , 0x47d4 , 0x4813 ,
0x4851 , 0x488d , 0x48c9 , 0x4904 , 0x493f , 0x4978 , 0x49b1 ,
0x49e9 , 0x4a20 , 0x4a57
} ;
F_2 ( L_10 , V_14 ) ;
switch ( V_42 -> V_45 ) {
case V_46 :
V_62 = F_9 ( V_2 , 0xff ) ;
V_62 /= 8 ;
if ( V_62 == 0 )
* V_61 = 0x0000 ;
else {
if ( V_62 > 20 )
V_62 = 20 ;
V_63 = V_67 [ V_62 - 1 ] * 10 / 23026 ;
* V_61 = V_63 * 8 * 655 ;
}
F_2 ( L_23 , V_14 ,
V_62 , * V_61 ) ;
break;
case V_52 :
V_65 = ( F_9 ( V_2 , 0x8c ) & 0x3f ) +
( F_9 ( V_2 , 0x8d ) << 4 ) ;
V_64 = F_9 ( V_2 , 0x8e ) ;
V_66 = V_64 * V_64 >> 1 ;
if ( V_66 == 0 ) {
* V_61 = 0x0000 ;
return 0 ;
}
if ( V_65 == 0 ) {
V_63 = 0x0013 ;
* V_61 = 0xffff ;
return 0 ;
}
if ( V_66 > V_65 ) {
V_62 = V_66 / V_65 ;
if ( V_62 > 80 )
V_62 = 80 ;
V_63 = V_68 [ V_62 - 1 ] / 1000 ;
* V_61 = V_63 * 5 * 655 ;
} else {
V_62 = V_65 / V_66 ;
if ( V_62 > 80 )
V_62 = 80 ;
* V_61 = - ( V_68 [ V_62 - 1 ] / 1000 ) ;
}
F_2 ( L_23 , V_14 ,
V_62 , * V_61 ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_19 ( struct V_18 * V_19 , T_5 * V_69 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_41 * V_42 = & V_19 -> V_43 ;
T_1 V_4 ;
T_2 V_70 ;
F_2 ( L_10 , V_14 ) ;
switch ( V_42 -> V_45 ) {
case V_46 :
* V_69 = ( F_9 ( V_2 , 0xf5 ) << 8 ) |
F_9 ( V_2 , 0xf4 ) ;
V_4 = F_9 ( V_2 , 0xf8 ) ;
V_4 &= ~ 0x20 ;
F_1 ( V_2 , 0xf8 , V_4 ) ;
V_4 |= 0x20 ;
F_1 ( V_2 , 0xf8 , V_4 ) ;
break;
case V_52 :
V_70 = ( F_9 ( V_2 , 0xe2 ) << 8 ) |
F_9 ( V_2 , 0xe1 ) ;
if ( V_70 > V_2 -> V_71 )
* V_69 = V_70 - V_2 -> V_71 ;
else
* V_69 = V_2 -> V_71 - V_70 ;
V_2 -> V_71 = V_70 ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , T_6 V_72 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
T_1 V_4 ;
F_2 ( L_21 , V_14 , V_72 ) ;
if ( ( V_72 != V_73 ) && ( V_72 != V_74 ) ) {
F_4 ( V_16 L_24 , V_14 , V_72 ) ;
return - V_75 ;
}
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 &= ~ 0xc0 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
switch ( V_72 ) {
case V_73 :
F_2 ( L_25 , V_14 ) ;
V_4 = F_9 ( V_2 , 0xa1 ) ;
V_4 &= ~ 0x43 ;
V_4 |= 0x04 ;
F_1 ( V_2 , 0xa1 , V_4 ) ;
break;
case V_74 :
F_2 ( L_26 , V_14 ) ;
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 |= 0x80 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
break;
}
return 0 ;
}
static int F_21 ( struct V_18 * V_19 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
int V_22 ;
T_1 V_4 ;
F_2 ( L_27 , V_14 ) ;
for ( V_22 = 0 ; V_22 < V_77 -> V_78 ; ) {
F_2 ( L_28 , V_77 -> V_7 [ V_22 ] ) ;
if ( ++ V_22 < V_77 -> V_78 )
F_2 ( L_29 ) ;
}
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 &= ~ 0xc0 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
for ( V_22 = 0 ; V_22 < V_77 -> V_78 ; V_22 ++ )
F_1 ( V_2 , 0xa3 + V_22 , V_77 -> V_7 [ V_22 ] ) ;
V_4 = F_9 ( V_2 , 0xa1 ) ;
V_4 &= ~ 0xf8 ;
V_4 |= ( ( V_77 -> V_78 - 1 ) << 3 ) | 0x07 ;
F_1 ( V_2 , 0xa1 , V_4 ) ;
for ( V_22 = 0 ; V_22 < 15 ; V_22 ++ ) {
V_4 = F_9 ( V_2 , 0xa1 ) ;
if ( ( V_4 & 0x40 ) == 0 )
break;
F_22 ( 10 ) ;
}
if ( V_22 == 15 ) {
V_4 = F_9 ( V_2 , 0xa1 ) ;
V_4 &= ~ 0x80 ;
V_4 |= 0x40 ;
F_1 ( V_2 , 0xa1 , V_4 ) ;
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 &= ~ 0xc0 ;
V_4 |= 0x80 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
return 1 ;
}
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 &= ~ 0xc0 ;
V_4 |= 0x80 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 ,
T_7 V_79 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
int V_22 ;
T_1 V_4 ;
F_2 ( L_10 , V_14 ) ;
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 &= ~ 0xc0 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
if ( V_79 == V_80 )
F_1 ( V_2 , 0xa1 , 0x02 ) ;
else if ( V_79 == V_81 )
F_1 ( V_2 , 0xa1 , 0x01 ) ;
else
return - V_75 ;
F_22 ( 13 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
V_4 = F_9 ( V_2 , 0xa1 ) ;
if ( ( V_4 & 0x40 ) == 0 )
break;
F_22 ( 1 ) ;
}
if ( V_22 == 5 ) {
V_4 = F_9 ( V_2 , 0xa1 ) ;
V_4 &= ~ 0x80 ;
V_4 |= 0x40 ;
F_1 ( V_2 , 0xa1 , V_4 ) ;
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 &= ~ 0xc0 ;
V_4 |= 0x80 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
return 1 ;
}
V_4 = F_9 ( V_2 , 0xa2 ) ;
V_4 &= ~ 0xc0 ;
V_4 |= 0x80 ;
F_1 ( V_2 , 0xa2 , V_4 ) ;
return 0 ;
}
static void F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
if ( V_2 -> V_9 -> V_53 )
V_2 -> V_9 -> V_53 ( V_19 , 0 ) ;
F_2 ( L_19 , V_14 ) ;
F_8 ( V_2 ) ;
}
struct V_18 * F_25 ( const struct V_82 * V_9 ,
struct V_83 * V_15 )
{
struct V_1 * V_2 = NULL ;
int V_23 ;
F_2 ( L_19 , V_14 ) ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_24 ) ;
if ( V_2 == NULL ) {
F_4 ( V_16 L_4 ) ;
goto V_84;
}
V_2 -> V_9 = V_9 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_71 = 0 ;
V_23 = F_9 ( V_2 , 0x00 ) & 0xfe ;
if ( V_23 != 0xe0 ) {
F_4 ( V_16 L_30 ) ;
goto V_85;
}
F_4 ( V_31 L_31 ,
F_9 ( V_2 , 0x02 ) ,
F_9 ( V_2 , 0x01 ) ) ;
memcpy ( & V_2 -> V_86 . V_58 , & V_87 ,
sizeof( struct V_88 ) ) ;
V_2 -> V_86 . V_21 = V_2 ;
F_14 ( & V_2 -> V_86 , V_39 ) ;
return & V_2 -> V_86 ;
V_85:
F_8 ( V_2 ) ;
V_84:
return NULL ;
}
static int F_27 ( struct V_18 * V_19 ,
T_8 V_89 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
T_8 V_66 ;
V_66 = V_89 ;
V_66 *= 65536 ;
V_66 = ( 2 * V_66 + V_90 ) / ( 2 * V_90 ) ;
if ( V_66 < 0 )
V_66 += 65536 ;
F_1 ( V_2 , 0x5f , V_66 >> 8 ) ;
F_1 ( V_2 , 0x5e , V_66 & 0xff ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_41 * V_42 = & V_19 -> V_43 ;
int V_22 ;
T_4 V_40 ;
T_8 V_91 ;
T_5 V_92 ;
T_2 V_93 ;
F_2 ( L_32 , V_14 ) ;
if ( V_2 -> V_9 -> V_94 )
V_2 -> V_9 -> V_94 ( V_19 , 0 ) ;
if ( V_19 -> V_58 . V_59 . V_95 )
V_19 -> V_58 . V_59 . V_95 ( V_19 ) ;
F_1 ( V_2 , 0x07 , 0x80 ) ;
F_1 ( V_2 , 0x07 , 0x00 ) ;
F_1 ( V_2 , 0xb2 , 0x01 ) ;
F_1 ( V_2 , 0x00 , 0x01 ) ;
switch ( V_42 -> V_45 ) {
case V_46 :
for ( V_22 = 0 ; V_22 < sizeof( V_96 ) ; V_22 += 2 )
F_1 ( V_2 ,
V_96 [ V_22 ] ,
V_96 [ V_22 + 1 ] ) ;
V_93 = F_9 ( V_2 , 0xfe ) ;
V_93 &= 0xc0 ;
V_93 |= 0x1b ;
F_1 ( V_2 , 0xfe , V_93 ) ;
break;
case V_52 :
for ( V_22 = 0 ; V_22 < sizeof( V_97 ) ; V_22 += 2 )
F_1 ( V_2 ,
V_97 [ V_22 ] ,
V_97 [ V_22 + 1 ] ) ;
if ( V_42 -> V_98 >= 30000000 )
F_1 ( V_2 , 0xfe , 0x54 ) ;
else
F_1 ( V_2 , 0xfe , 0x98 ) ;
break;
default:
return 1 ;
}
F_1 ( V_2 , 0x29 , 0x80 ) ;
F_1 ( V_2 , 0x25 , 0x8a ) ;
if ( ( V_42 -> V_98 / 1000 ) <= 5000 ) {
V_93 = 29777 / ( V_42 -> V_98 / 1000 ) + 1 ;
if ( V_93 % 2 != 0 )
V_93 ++ ;
F_1 ( V_2 , 0xc3 , 0x0d ) ;
F_1 ( V_2 , 0xc8 , V_93 ) ;
F_1 ( V_2 , 0xc4 , 0x10 ) ;
F_1 ( V_2 , 0xc7 , 0x0e ) ;
} else if ( ( V_42 -> V_98 / 1000 ) <= 10000 ) {
V_93 = 92166 / ( V_42 -> V_98 / 1000 ) + 1 ;
if ( V_93 % 2 != 0 )
V_93 ++ ;
F_1 ( V_2 , 0xc3 , 0x07 ) ;
F_1 ( V_2 , 0xc8 , V_93 ) ;
F_1 ( V_2 , 0xc4 , 0x09 ) ;
F_1 ( V_2 , 0xc7 , 0x12 ) ;
} else if ( ( V_42 -> V_98 / 1000 ) <= 20000 ) {
V_93 = 64516 / ( V_42 -> V_98 / 1000 ) + 1 ;
F_1 ( V_2 , 0xc3 , V_93 ) ;
F_1 ( V_2 , 0xc8 , 0x0e ) ;
F_1 ( V_2 , 0xc4 , 0x07 ) ;
F_1 ( V_2 , 0xc7 , 0x18 ) ;
} else {
V_93 = 129032 / ( V_42 -> V_98 / 1000 ) + 1 ;
F_1 ( V_2 , 0xc3 , V_93 ) ;
F_1 ( V_2 , 0xc8 , 0x0a ) ;
F_1 ( V_2 , 0xc4 , 0x05 ) ;
F_1 ( V_2 , 0xc7 , 0x24 ) ;
}
V_93 = ( ( ( V_42 -> V_98 / 1000 ) << 16 ) +
( V_90 / 2 ) ) / V_90 ;
F_1 ( V_2 , 0x61 , V_93 & 0x00ff ) ;
F_1 ( V_2 , 0x62 , ( V_93 & 0xff00 ) >> 8 ) ;
F_1 ( V_2 , 0x56 , 0x00 ) ;
F_1 ( V_2 , 0x76 , 0x00 ) ;
if ( V_2 -> V_9 -> V_99 ) {
switch ( V_42 -> V_45 ) {
case V_46 :
default:
F_1 ( V_2 , 0xfd , 0x80 ) ;
break;
case V_52 :
F_1 ( V_2 , 0xfd , 0x01 ) ;
break;
}
}
F_1 ( V_2 , 0x00 , 0x00 ) ;
F_1 ( V_2 , 0xb2 , 0x00 ) ;
if ( V_19 -> V_58 . V_59 . V_100 ) {
V_19 -> V_58 . V_59 . V_100 ( V_19 , & V_92 ) ;
V_91 = V_92 - V_42 -> V_92 ;
F_27 ( V_19 , V_91 ) ;
}
for ( V_22 = 0 ; V_22 < 30 ; V_22 ++ ) {
F_15 ( V_19 , & V_40 ) ;
if ( V_40 & V_51 )
break;
F_22 ( 10 ) ;
}
return 0 ;
}
static int F_29 ( struct V_18 * V_19 ,
bool V_101 ,
unsigned int V_102 ,
unsigned int * V_103 ,
T_4 * V_40 )
{
if ( V_101 ) {
int V_23 = F_28 ( V_19 ) ;
if ( V_23 )
return V_23 ;
}
* V_103 = V_104 / 5 ;
return F_15 ( V_19 , V_40 ) ;
}
static enum V_105 F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
if ( V_2 -> V_9 -> V_53 )
V_2 -> V_9 -> V_53 ( V_19 , 0 ) ;
F_2 ( L_10 , V_14 ) ;
return V_106 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
int V_23 ;
F_2 ( L_10 , V_14 ) ;
F_1 ( V_2 , 0x08 , 0x01 | F_9 ( V_2 , 0x08 ) ) ;
F_22 ( 1 ) ;
V_23 = F_10 ( V_19 ) ;
if ( V_23 != 0 ) {
F_4 ( V_16 L_33 , V_14 ) ;
return V_23 ;
}
return 0 ;
}
