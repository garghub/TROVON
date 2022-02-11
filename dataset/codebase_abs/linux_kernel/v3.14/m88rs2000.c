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
static T_2 F_5 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_23 ;
T_1 V_3 ;
V_3 = F_4 ( V_2 , 0x86 ) ;
if ( ! V_3 || V_3 == 0xff )
return 0 ;
V_3 /= 2 ;
V_3 += 1 ;
V_23 = ( T_2 ) ( V_3 * V_24 + 28 / 2 ) / 28 ;
return V_23 ;
}
static int F_6 ( struct V_20 * V_21 , T_3 V_25 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_23 ;
T_4 V_26 ;
T_1 V_3 ;
int V_5 ;
V_23 = F_5 ( V_21 ) ;
if ( ! V_23 )
return - V_27 ;
V_26 = ( V_25 * 4096 + ( T_4 ) V_23 / 2 ) / ( T_4 ) V_23 ;
if ( V_26 < 0 )
V_26 += 4096 ;
V_5 = F_1 ( V_2 , 0x9c , ( T_1 ) ( V_26 >> 4 ) ) ;
V_3 = F_4 ( V_2 , 0x9d ) ;
V_3 &= 0xf ;
V_3 |= ( T_1 ) ( V_26 & 0xf ) << 4 ;
V_5 |= F_1 ( V_2 , 0x9d , V_3 ) ;
return V_5 ;
}
static int F_7 ( struct V_20 * V_21 , T_2 V_28 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_5 ;
T_5 V_29 ;
T_2 V_23 ;
T_1 V_30 [ 3 ] ;
if ( ( V_28 < 1000000 ) || ( V_28 > 45000000 ) )
return - V_27 ;
V_23 = F_5 ( V_21 ) ;
if ( ! V_23 )
return - V_27 ;
V_29 = V_28 / 1000 ;
V_29 *= 1 << 24 ;
F_8 ( V_29 , V_23 ) ;
V_30 [ 0 ] = ( T_1 ) ( V_29 >> 16 ) & 0xff ;
V_30 [ 1 ] = ( T_1 ) ( V_29 >> 8 ) & 0xff ;
V_30 [ 2 ] = ( T_1 ) V_29 & 0xff ;
V_5 = F_1 ( V_2 , 0x93 , V_30 [ 2 ] ) ;
V_5 |= F_1 ( V_2 , 0x94 , V_30 [ 1 ] ) ;
V_5 |= F_1 ( V_2 , 0x95 , V_30 [ 0 ] ) ;
if ( V_28 > 10000000 )
V_5 |= F_1 ( V_2 , 0xa0 , 0x20 ) ;
else
V_5 |= F_1 ( V_2 , 0xa0 , 0x60 ) ;
V_5 |= F_1 ( V_2 , 0xa1 , 0xe0 ) ;
if ( V_28 > 12000000 )
V_5 |= F_1 ( V_2 , 0xa3 , 0x20 ) ;
else if ( V_28 > 2800000 )
V_5 |= F_1 ( V_2 , 0xa3 , 0x98 ) ;
else
V_5 |= F_1 ( V_2 , 0xa3 , 0x90 ) ;
F_3 ( L_4 ) ;
return V_5 ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_33 ;
T_1 V_3 ;
F_3 ( L_5 , V_15 ) ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_3 = F_4 ( V_2 , 0xb2 ) ;
V_3 &= 0x3f ;
F_1 ( V_2 , 0xb2 , V_3 ) ;
for ( V_33 = 0 ; V_33 < V_32 -> V_34 ; V_33 ++ )
F_1 ( V_2 , 0xb3 + V_33 , V_32 -> V_8 [ V_33 ] ) ;
V_3 = F_4 ( V_2 , 0xb1 ) ;
V_3 &= 0x87 ;
V_3 |= ( ( V_32 -> V_34 - 1 ) << 3 ) | 0x07 ;
V_3 &= 0x7f ;
F_1 ( V_2 , 0xb1 , V_3 ) ;
for ( V_33 = 0 ; V_33 < 15 ; V_33 ++ ) {
if ( ( F_4 ( V_2 , 0xb1 ) & 0x40 ) == 0x0 )
break;
F_10 ( 20 ) ;
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
static int F_11 ( struct V_20 * V_21 ,
T_6 V_35 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_36 , V_37 ;
F_3 ( L_5 , V_15 ) ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
F_10 ( 50 ) ;
V_36 = F_4 ( V_2 , 0xb1 ) ;
V_37 = F_4 ( V_2 , 0xb2 ) ;
F_1 ( V_2 , 0xb2 , V_37 ) ;
F_1 ( V_2 , 0xb1 , V_36 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , T_7 V_38 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_36 , V_37 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_36 = F_4 ( V_2 , 0xb1 ) ;
V_37 = F_4 ( V_2 , 0xb2 ) ;
V_37 &= 0x3f ;
switch ( V_38 ) {
case V_39 :
V_36 |= 0x4 ;
V_36 &= 0xbc ;
break;
case V_40 :
V_37 |= 0x80 ;
break;
default:
break;
}
F_1 ( V_2 , 0xb2 , V_37 ) ;
F_1 ( V_2 , 0xb1 , V_36 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_5 = 0 ;
T_1 V_33 ;
if ( V_42 == NULL )
return - V_27 ;
for ( V_33 = 0 ; V_33 < 255 ; V_33 ++ ) {
switch ( V_42 [ V_33 ] . V_43 ) {
case 0x01 :
V_5 = F_1 ( V_2 , V_42 [ V_33 ] . V_3 ,
V_42 [ V_33 ] . V_44 ) ;
break;
case 0x10 :
if ( V_42 [ V_33 ] . V_3 > 0 )
F_14 ( V_42 [ V_33 ] . V_3 ) ;
break;
case 0xff :
if ( V_42 [ V_33 ] . V_3 == 0xaa && V_42 [ V_33 ] . V_44 == 0xff )
return 0 ;
case 0x00 :
break;
default:
return - V_27 ;
}
if ( V_5 < 0 )
return - V_45 ;
}
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , T_8 V_46 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_4 ;
V_4 = F_4 ( V_2 , 0xb2 ) ;
V_4 |= 0x03 ;
switch ( V_46 ) {
case V_47 :
V_4 &= ~ 0x03 ;
break;
case V_48 :
V_4 &= ~ 0x03 ;
V_4 |= 0x01 ;
break;
case V_49 :
break;
}
F_1 ( V_2 , 0xb2 , V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_5 ;
F_3 ( L_6 ) ;
if ( V_2 -> V_10 -> V_41 )
V_5 = F_13 ( V_2 ,
(struct V_41 * ) V_2 -> V_10 -> V_41 ) ;
else
V_5 = F_13 ( V_2 , V_50 ) ;
return V_5 ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_5 ;
V_5 = F_13 ( V_2 , V_51 ) ;
return V_5 ;
}
static int F_18 ( struct V_20 * V_21 , T_9 * V_52 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_3 = F_4 ( V_2 , 0x8c ) ;
* V_52 = 0 ;
if ( ( V_3 & 0xee ) == 0xee ) {
* V_52 = V_53 | V_54 | V_55
| V_56 | V_57 ;
if ( V_2 -> V_10 -> V_58 )
V_2 -> V_10 -> V_58 ( V_21 , V_59 ) ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , T_2 * V_60 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_61 , V_62 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_61 = F_4 ( V_2 , 0xd8 ) ;
if ( ( V_61 & 0x10 ) != 0 ) {
F_1 ( V_2 , 0x9a , 0xb0 ) ;
* V_60 = 0xffffffff ;
return 0 ;
}
* V_60 = ( F_4 ( V_2 , 0xd7 ) << 8 ) |
F_4 ( V_2 , 0xd6 ) ;
V_62 = F_4 ( V_2 , 0xd9 ) ;
F_1 ( V_2 , 0xd9 , ( V_62 & ~ 7 ) | 4 ) ;
F_1 ( V_2 , 0xd8 , ( V_61 & ~ 8 ) | 0x30 ) ;
F_1 ( V_2 , 0xd8 , ( V_61 & ~ 8 ) | 0x30 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
T_10 * V_63 )
{
if ( V_21 -> V_64 . V_65 . V_66 )
V_21 -> V_64 . V_65 . V_66 ( V_21 , V_63 ) ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 , T_10 * V_67 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
* V_67 = 512 * F_4 ( V_2 , 0x65 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 , T_2 * V_68 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_26 ;
* V_68 = ( F_4 ( V_2 , 0xd5 ) << 8 ) |
F_4 ( V_2 , 0xd4 ) ;
V_26 = F_4 ( V_2 , 0xd8 ) ;
F_1 ( V_2 , 0xd8 , V_26 & ~ 0x20 ) ;
F_1 ( V_2 , 0xd8 , V_26 | 0x20 ) ;
F_1 ( V_2 , 0xd8 , V_26 | 0x20 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_11 V_69 )
{
T_1 V_70 , V_3 ;
int V_5 ;
switch ( V_69 ) {
case V_71 :
V_70 = 0x8 ;
break;
case V_72 :
V_70 = 0x10 ;
break;
case V_73 :
V_70 = 0x20 ;
break;
case V_74 :
V_70 = 0x40 ;
break;
case V_75 :
V_70 = 0x80 ;
break;
case V_76 :
default:
V_70 = 0x0 ;
}
V_3 = F_4 ( V_2 , 0x70 ) ;
V_3 &= 0x7 ;
V_5 = F_1 ( V_2 , 0x70 , V_3 | V_70 ) ;
V_5 |= F_1 ( V_2 , 0x76 , 0x8 ) ;
return V_5 ;
}
static T_11 F_24 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_3 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
V_3 &= 0xf0 ;
V_3 >>= 5 ;
switch ( V_3 ) {
case 0x4 :
return V_71 ;
case 0x3 :
return V_72 ;
case 0x2 :
return V_73 ;
case 0x1 :
return V_74 ;
case 0x0 :
return V_75 ;
default:
break;
}
return V_76 ;
}
static int F_25 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
struct V_77 * V_78 = & V_21 -> V_79 ;
T_9 V_52 ;
int V_33 , V_5 = 0 ;
T_2 V_80 ;
T_3 V_25 = 0 ;
T_1 V_3 ;
V_2 -> V_81 = 0 ;
if ( V_78 -> V_82 != V_83 ) {
F_3 ( L_7
L_8 ,
V_15 , V_78 -> V_82 ) ;
return - V_84 ;
}
if ( V_21 -> V_64 . V_65 . V_85 )
V_5 = V_21 -> V_64 . V_65 . V_85 ( V_21 ) ;
if ( V_5 < 0 )
return - V_45 ;
if ( V_21 -> V_64 . V_65 . V_86 )
V_5 = V_21 -> V_64 . V_65 . V_86 ( V_21 , & V_80 ) ;
if ( V_5 < 0 )
return - V_45 ;
V_25 = ( T_3 ) ( ( T_4 ) V_80 - V_78 -> V_87 ) ;
if ( ( ( V_78 -> V_87 % 192857 ) >= ( 192857 - 3000 ) ) ||
( V_78 -> V_87 % 192857 ) <= 3000 )
V_5 = F_1 ( V_2 , 0x86 , 0xc2 ) ;
else
V_5 = F_1 ( V_2 , 0x86 , 0xc6 ) ;
V_5 |= F_6 ( V_21 , V_25 ) ;
if ( V_5 < 0 )
return - V_45 ;
if ( V_78 -> V_88 > 27500000 )
V_5 = F_1 ( V_2 , 0xf1 , 0xa4 ) ;
else
V_5 = F_1 ( V_2 , 0xf1 , 0xbf ) ;
V_5 |= F_13 ( V_2 , V_89 ) ;
if ( V_5 < 0 )
return - V_45 ;
V_5 = F_23 ( V_2 , V_78 -> V_90 ) ;
V_5 |= F_1 ( V_2 , 0x85 , 0x1 ) ;
V_5 |= F_1 ( V_2 , 0x8a , 0xbf ) ;
V_5 |= F_1 ( V_2 , 0x8d , 0x1e ) ;
V_5 |= F_1 ( V_2 , 0x90 , 0xf1 ) ;
V_5 |= F_1 ( V_2 , 0x91 , 0x08 ) ;
if ( V_5 < 0 )
return - V_45 ;
V_5 = F_7 ( V_21 , V_78 -> V_88 ) ;
if ( V_5 < 0 )
return - V_45 ;
V_5 = F_13 ( V_2 , V_91 ) ;
if ( V_5 < 0 )
return - V_45 ;
for ( V_33 = 0 ; V_33 < 25 ; V_33 ++ ) {
V_3 = F_4 ( V_2 , 0x8c ) ;
if ( ( V_3 & 0xee ) == 0xee ) {
V_52 = V_57 ;
break;
}
V_2 -> V_81 ++ ;
if ( V_2 -> V_81 == 15 ) {
V_3 = F_4 ( V_2 , 0x70 ) ;
V_3 ^= 0x4 ;
F_1 ( V_2 , 0x70 , V_3 ) ;
V_2 -> V_81 = 0 ;
}
F_10 ( 20 ) ;
}
if ( V_52 & V_57 ) {
V_2 -> V_90 = F_24 ( V_2 ) ;
V_3 = F_4 ( V_2 , 0x65 ) ;
}
V_2 -> V_92 = V_78 -> V_87 ;
V_2 -> V_88 = V_78 -> V_88 ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 )
{
struct V_77 * V_78 = & V_21 -> V_79 ;
struct V_1 * V_2 = V_21 -> V_22 ;
V_78 -> V_90 = V_2 -> V_90 ;
V_78 -> V_87 = V_2 -> V_92 ;
V_78 -> V_88 = V_2 -> V_88 ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 , int V_93 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
if ( V_93 )
F_1 ( V_2 , 0x81 , 0x84 ) ;
else
F_1 ( V_2 , 0x81 , 0x81 ) ;
F_28 ( 10 ) ;
return 0 ;
}
static void F_29 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_30 ( V_2 ) ;
}
struct V_20 * F_31 ( const struct V_94 * V_10 ,
struct V_95 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_96 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_92 = 0 ;
V_2 -> V_88 = 0 ;
V_2 -> V_90 = 0 ;
memcpy ( & V_2 -> V_97 . V_64 , & V_98 ,
sizeof( struct V_99 ) ) ;
V_2 -> V_97 . V_22 = V_2 ;
return & V_2 -> V_97 ;
error:
F_30 ( V_2 ) ;
return NULL ;
}
