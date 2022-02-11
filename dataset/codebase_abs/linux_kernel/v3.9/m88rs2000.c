static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_6 ,
. V_13 = 2
} ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1
L_2 , V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - V_16 : 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_17 [] = { V_3 } ;
T_1 V_18 [] = { 0 } ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_17 ,
. V_13 = 1
} , {
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = V_19 ,
. V_6 = V_18 ,
. V_13 = 1
}
} ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( L_3 ,
V_15 , V_3 , V_5 ) ;
return V_18 [ 0 ] ;
}
static int F_5 ( struct V_20 * V_21 , T_2 V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_5 ;
T_2 V_24 ;
T_1 V_25 [ 3 ] ;
if ( ( V_22 < 1000000 ) || ( V_22 > 45000000 ) )
return - V_26 ;
V_24 = V_22 / 1000 ;
V_24 *= 11831 ;
V_24 /= 68 ;
V_24 -= 3 ;
V_25 [ 0 ] = ( T_1 ) ( V_24 >> 16 ) & 0xff ;
V_25 [ 1 ] = ( T_1 ) ( V_24 >> 8 ) & 0xff ;
V_25 [ 2 ] = ( T_1 ) V_24 & 0xff ;
V_5 = F_1 ( V_2 , 0x93 , V_25 [ 2 ] ) ;
V_5 |= F_1 ( V_2 , 0x94 , V_25 [ 1 ] ) ;
V_5 |= F_1 ( V_2 , 0x95 , V_25 [ 0 ] ) ;
F_3 ( L_4 ) ;
return V_5 ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_29 ;
T_1 V_3 ;
F_3 ( L_5 , V_15 ) ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_3 = F_4 ( V_2 , 0xb2 ) ;
V_3 &= 0x3f ;
F_1 ( V_2 , 0xb2 , V_3 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_30 ; V_29 ++ )
F_1 ( V_2 , 0xb3 + V_29 , V_28 -> V_8 [ V_29 ] ) ;
V_3 = F_4 ( V_2 , 0xb1 ) ;
V_3 &= 0x87 ;
V_3 |= ( ( V_28 -> V_30 - 1 ) << 3 ) | 0x07 ;
V_3 &= 0x7f ;
F_1 ( V_2 , 0xb1 , V_3 ) ;
for ( V_29 = 0 ; V_29 < 15 ; V_29 ++ ) {
if ( ( F_4 ( V_2 , 0xb1 ) & 0x40 ) == 0x0 )
break;
F_7 ( 20 ) ;
}
V_3 = F_4 ( V_2 , 0xb1 ) ;
if ( ( V_3 & 0x40 ) > 0x0 ) {
V_3 &= 0x7f ;
V_3 |= 0x40 ;
F_1 ( V_2 , 0xb1 , V_3 ) ;
}
V_3 = F_4 ( V_2 , 0xb2 ) ;
V_3 &= 0x3f ;
V_3 |= 0x80 ;
F_1 ( V_2 , 0xb2 , V_3 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 ,
T_3 V_31 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_1 V_32 , V_33 ;
F_3 ( L_5 , V_15 ) ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
F_7 ( 50 ) ;
V_32 = F_4 ( V_2 , 0xb1 ) ;
V_33 = F_4 ( V_2 , 0xb2 ) ;
F_1 ( V_2 , 0xb2 , V_33 ) ;
F_1 ( V_2 , 0xb1 , V_32 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 , T_4 V_34 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_1 V_32 , V_33 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_32 = F_4 ( V_2 , 0xb1 ) ;
V_33 = F_4 ( V_2 , 0xb2 ) ;
V_33 &= 0x3f ;
switch ( V_34 ) {
case V_35 :
V_32 |= 0x4 ;
V_32 &= 0xbc ;
break;
case V_36 :
V_33 |= 0x80 ;
break;
default:
break;
}
F_1 ( V_2 , 0xb2 , V_33 ) ;
F_1 ( V_2 , 0xb1 , V_32 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
int V_5 = 0 ;
T_1 V_29 ;
if ( V_38 == NULL )
return - V_26 ;
for ( V_29 = 0 ; V_29 < 255 ; V_29 ++ ) {
switch ( V_38 [ V_29 ] . V_39 ) {
case 0x01 :
V_5 = F_1 ( V_2 , V_38 [ V_29 ] . V_3 ,
V_38 [ V_29 ] . V_40 ) ;
break;
case 0x10 :
if ( V_38 [ V_29 ] . V_3 > 0 )
F_11 ( V_38 [ V_29 ] . V_3 ) ;
break;
case 0xff :
if ( V_38 [ V_29 ] . V_3 == 0xaa && V_38 [ V_29 ] . V_40 == 0xff )
return 0 ;
case 0x00 :
break;
default:
return - V_26 ;
}
if ( V_5 < 0 )
return - V_41 ;
}
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , T_5 V_42 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_1 V_4 ;
V_4 = F_4 ( V_2 , 0xb2 ) ;
V_4 |= 0x03 ;
switch ( V_42 ) {
case V_43 :
V_4 &= ~ 0x03 ;
break;
case V_44 :
V_4 &= ~ 0x03 ;
V_4 |= 0x01 ;
break;
case V_45 :
break;
}
F_1 ( V_2 , 0xb2 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_5 ;
F_3 ( L_6 ) ;
if ( V_2 -> V_10 -> V_37 )
V_5 = F_10 ( V_2 ,
(struct V_37 * ) V_2 -> V_10 -> V_37 ) ;
else
V_5 = F_10 ( V_2 , V_46 ) ;
return V_5 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_5 ;
V_5 = F_10 ( V_2 , V_47 ) ;
return V_5 ;
}
static int F_15 ( struct V_20 * V_21 , T_6 * V_48 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_1 V_3 = F_4 ( V_2 , 0x8c ) ;
* V_48 = 0 ;
if ( ( V_3 & 0x7 ) == 0x7 ) {
* V_48 = V_49 | V_50 | V_51
| V_52 | V_53 ;
if ( V_2 -> V_10 -> V_54 )
V_2 -> V_10 -> V_54 ( V_21 , V_55 ) ;
}
return 0 ;
}
static int F_16 ( struct V_20 * V_21 , T_2 * V_56 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_1 V_57 , V_58 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_57 = F_4 ( V_2 , 0xd8 ) ;
if ( ( V_57 & 0x10 ) != 0 ) {
F_1 ( V_2 , 0x9a , 0xb0 ) ;
* V_56 = 0xffffffff ;
return 0 ;
}
* V_56 = ( F_4 ( V_2 , 0xd7 ) << 8 ) |
F_4 ( V_2 , 0xd6 ) ;
V_58 = F_4 ( V_2 , 0xd9 ) ;
F_1 ( V_2 , 0xd9 , ( V_58 & ~ 7 ) | 4 ) ;
F_1 ( V_2 , 0xd8 , ( V_57 & ~ 8 ) | 0x30 ) ;
F_1 ( V_2 , 0xd8 , ( V_57 & ~ 8 ) | 0x30 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 ,
T_7 * V_59 )
{
if ( V_21 -> V_60 . V_61 . V_62 )
V_21 -> V_60 . V_61 . V_62 ( V_21 , V_59 ) ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 , T_7 * V_63 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
* V_63 = 512 * F_4 ( V_2 , 0x65 ) ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , T_2 * V_64 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_1 V_65 ;
* V_64 = ( F_4 ( V_2 , 0xd5 ) << 8 ) |
F_4 ( V_2 , 0xd4 ) ;
V_65 = F_4 ( V_2 , 0xd8 ) ;
F_1 ( V_2 , 0xd8 , V_65 & ~ 0x20 ) ;
F_1 ( V_2 , 0xd8 , V_65 | 0x20 ) ;
F_1 ( V_2 , 0xd8 , V_65 | 0x20 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_8 V_66 )
{
T_7 V_67 ;
switch ( V_66 ) {
case V_68 :
default:
V_67 = 0x08 ;
}
F_1 ( V_2 , 0x76 , V_67 ) ;
return 0 ;
}
static T_8 F_21 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_3 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
switch ( V_3 ) {
case 0x88 :
return V_69 ;
case 0x68 :
return V_70 ;
case 0x48 :
return V_71 ;
case 0x28 :
return V_72 ;
case 0x18 :
return V_73 ;
case 0x08 :
default:
break;
}
return V_68 ;
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
struct V_74 * V_75 = & V_21 -> V_76 ;
T_6 V_48 ;
int V_29 , V_5 = 0 ;
T_9 V_65 ;
T_2 V_77 ;
T_7 V_78 = 0 ;
T_1 V_3 ;
V_2 -> V_79 = 0 ;
if ( V_75 -> V_80 != V_81 ) {
F_3 ( L_7
L_8 ,
V_15 , V_75 -> V_80 ) ;
return - V_82 ;
}
if ( V_21 -> V_60 . V_61 . V_83 )
V_5 = V_21 -> V_60 . V_61 . V_83 ( V_21 ) ;
if ( V_5 < 0 )
return - V_41 ;
if ( V_21 -> V_60 . V_61 . V_84 )
V_5 = V_21 -> V_60 . V_61 . V_84 ( V_21 , & V_77 ) ;
if ( V_5 < 0 )
return - V_41 ;
V_78 = V_77 - V_75 -> V_85 ;
V_65 = V_78 ;
V_65 *= 65536 ;
V_65 = ( 2 * V_65 + 96000 ) / ( 2 * 96000 ) ;
if ( V_65 < 0 )
V_65 += 65536 ;
V_78 = V_65 & 0xffff ;
V_5 = F_1 ( V_2 , 0x9a , 0x30 ) ;
V_3 = F_4 ( V_2 , 0x86 ) ;
V_5 |= F_1 ( V_2 , 0x86 , V_3 ) ;
V_5 |= F_1 ( V_2 , 0x9c , ( V_78 >> 8 ) ) ;
V_5 |= F_1 ( V_2 , 0x9d , V_78 & 0xf0 ) ;
V_5 = F_10 ( V_2 , V_86 ) ;
if ( V_5 < 0 )
return - V_41 ;
V_3 = F_4 ( V_2 , 0x70 ) ;
V_5 = F_1 ( V_2 , 0x70 , V_3 ) ;
V_5 |= F_20 ( V_2 , V_75 -> V_87 ) ;
V_5 |= F_1 ( V_2 , 0x85 , 0x1 ) ;
V_5 |= F_1 ( V_2 , 0x8a , 0xbf ) ;
V_5 |= F_1 ( V_2 , 0x8d , 0x1e ) ;
V_5 |= F_1 ( V_2 , 0x90 , 0xf1 ) ;
V_5 |= F_1 ( V_2 , 0x91 , 0x08 ) ;
if ( V_5 < 0 )
return - V_41 ;
V_5 = F_5 ( V_21 , V_75 -> V_88 ) ;
if ( V_5 < 0 )
return - V_41 ;
V_5 = F_10 ( V_2 , V_89 ) ;
if ( V_5 < 0 )
return - V_41 ;
for ( V_29 = 0 ; V_29 < 25 ; V_29 ++ ) {
V_3 = F_4 ( V_2 , 0x8c ) ;
if ( ( V_3 & 0x7 ) == 0x7 ) {
V_48 = V_53 ;
break;
}
V_2 -> V_79 ++ ;
if ( V_2 -> V_79 == 15 ) {
V_3 = F_4 ( V_2 , 0x70 ) ;
V_3 ^= 0x4 ;
F_1 ( V_2 , 0x70 , V_3 ) ;
V_2 -> V_79 = 0 ;
}
F_7 ( 20 ) ;
}
if ( V_48 & V_53 ) {
V_2 -> V_87 = F_21 ( V_2 ) ;
V_3 = F_4 ( V_2 , 0x65 ) ;
}
V_2 -> V_90 = V_75 -> V_85 ;
V_2 -> V_88 = V_75 -> V_88 ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 )
{
struct V_74 * V_75 = & V_21 -> V_76 ;
struct V_1 * V_2 = V_21 -> V_23 ;
V_75 -> V_87 = V_2 -> V_87 ;
V_75 -> V_85 = V_2 -> V_90 ;
V_75 -> V_88 = V_2 -> V_88 ;
return 0 ;
}
static int F_24 ( struct V_20 * V_21 , int V_91 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
if ( V_91 )
F_1 ( V_2 , 0x81 , 0x84 ) ;
else
F_1 ( V_2 , 0x81 , 0x81 ) ;
F_25 ( 10 ) ;
return 0 ;
}
static void F_26 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_27 ( V_2 ) ;
}
struct V_20 * F_28 ( const struct V_92 * V_10 ,
struct V_93 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_94 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_90 = 0 ;
V_2 -> V_88 = 0 ;
V_2 -> V_87 = 0 ;
memcpy ( & V_2 -> V_95 . V_60 , & V_96 ,
sizeof( struct V_97 ) ) ;
V_2 -> V_95 . V_23 = V_2 ;
return & V_2 -> V_95 ;
error:
F_27 ( V_2 ) ;
return NULL ;
}
