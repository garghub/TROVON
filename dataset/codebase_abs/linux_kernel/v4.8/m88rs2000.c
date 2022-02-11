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
enum V_35 V_36 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_37 , V_38 ;
F_3 ( L_5 , V_15 ) ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
F_10 ( 50 ) ;
V_37 = F_4 ( V_2 , 0xb1 ) ;
V_38 = F_4 ( V_2 , 0xb2 ) ;
F_1 ( V_2 , 0xb2 , V_38 ) ;
F_1 ( V_2 , 0xb1 , V_37 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 ,
enum V_39 V_40 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_37 , V_38 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_37 = F_4 ( V_2 , 0xb1 ) ;
V_38 = F_4 ( V_2 , 0xb2 ) ;
V_38 &= 0x3f ;
switch ( V_40 ) {
case V_41 :
V_37 |= 0x4 ;
V_37 &= 0xbc ;
break;
case V_42 :
V_38 |= 0x80 ;
break;
default:
break;
}
F_1 ( V_2 , 0xb2 , V_38 ) ;
F_1 ( V_2 , 0xb1 , V_37 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
int V_5 = 0 ;
T_1 V_33 ;
if ( V_44 == NULL )
return - V_27 ;
for ( V_33 = 0 ; V_33 < 255 ; V_33 ++ ) {
switch ( V_44 [ V_33 ] . V_45 ) {
case 0x01 :
V_5 = F_1 ( V_2 , V_44 [ V_33 ] . V_3 ,
V_44 [ V_33 ] . V_46 ) ;
break;
case 0x10 :
if ( V_44 [ V_33 ] . V_3 > 0 )
F_14 ( V_44 [ V_33 ] . V_3 ) ;
break;
case 0xff :
if ( V_44 [ V_33 ] . V_3 == 0xaa && V_44 [ V_33 ] . V_46 == 0xff )
return 0 ;
case 0x00 :
break;
default:
return - V_27 ;
}
if ( V_5 < 0 )
return - V_47 ;
}
return 0 ;
}
static int F_15 ( struct V_20 * V_21 ,
enum V_48 V_49 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_4 ;
V_4 = F_4 ( V_2 , 0xb2 ) ;
V_4 |= 0x03 ;
switch ( V_49 ) {
case V_50 :
V_4 &= ~ 0x03 ;
break;
case V_51 :
V_4 &= ~ 0x03 ;
V_4 |= 0x01 ;
break;
case V_52 :
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
if ( V_2 -> V_10 -> V_43 )
V_5 = F_13 ( V_2 ,
(struct V_43 * ) V_2 -> V_10 -> V_43 ) ;
else
V_5 = F_13 ( V_2 , V_53 ) ;
return V_5 ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_5 ;
V_5 = F_13 ( V_2 , V_54 ) ;
return V_5 ;
}
static int F_18 ( struct V_20 * V_21 ,
enum V_55 * V_56 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_3 = F_4 ( V_2 , 0x8c ) ;
* V_56 = 0 ;
if ( ( V_3 & 0xee ) == 0xee ) {
* V_56 = V_57 | V_58 | V_59
| V_60 | V_61 ;
if ( V_2 -> V_10 -> V_62 )
V_2 -> V_10 -> V_62 ( V_21 , V_63 ) ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , T_2 * V_64 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_65 , V_66 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_65 = F_4 ( V_2 , 0xd8 ) ;
if ( ( V_65 & 0x10 ) != 0 ) {
F_1 ( V_2 , 0x9a , 0xb0 ) ;
* V_64 = 0xffffffff ;
return 0 ;
}
* V_64 = ( F_4 ( V_2 , 0xd7 ) << 8 ) |
F_4 ( V_2 , 0xd6 ) ;
V_66 = F_4 ( V_2 , 0xd9 ) ;
F_1 ( V_2 , 0xd9 , ( V_66 & ~ 7 ) | 4 ) ;
F_1 ( V_2 , 0xd8 , ( V_65 & ~ 8 ) | 0x30 ) ;
F_1 ( V_2 , 0xd8 , ( V_65 & ~ 8 ) | 0x30 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
T_6 * V_67 )
{
if ( V_21 -> V_68 . V_69 . V_70 )
V_21 -> V_68 . V_69 . V_70 ( V_21 , V_67 ) ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 , T_6 * V_71 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
* V_71 = 512 * F_4 ( V_2 , 0x65 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 , T_2 * V_72 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_26 ;
* V_72 = ( F_4 ( V_2 , 0xd5 ) << 8 ) |
F_4 ( V_2 , 0xd4 ) ;
V_26 = F_4 ( V_2 , 0xd8 ) ;
F_1 ( V_2 , 0xd8 , V_26 & ~ 0x20 ) ;
F_1 ( V_2 , 0xd8 , V_26 | 0x20 ) ;
F_1 ( V_2 , 0xd8 , V_26 | 0x20 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_73 V_74 )
{
T_1 V_75 , V_3 ;
int V_5 ;
switch ( V_74 ) {
case V_76 :
V_75 = 0x8 ;
break;
case V_77 :
V_75 = 0x10 ;
break;
case V_78 :
V_75 = 0x20 ;
break;
case V_79 :
V_75 = 0x40 ;
break;
case V_80 :
V_75 = 0x80 ;
break;
case V_81 :
default:
V_75 = 0x0 ;
}
V_3 = F_4 ( V_2 , 0x70 ) ;
V_3 &= 0x7 ;
V_5 = F_1 ( V_2 , 0x70 , V_3 | V_75 ) ;
V_5 |= F_1 ( V_2 , 0x76 , 0x8 ) ;
return V_5 ;
}
static enum V_73 F_24 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_1 ( V_2 , 0x9a , 0x30 ) ;
V_3 = F_4 ( V_2 , 0x76 ) ;
F_1 ( V_2 , 0x9a , 0xb0 ) ;
V_3 &= 0xf0 ;
V_3 >>= 5 ;
switch ( V_3 ) {
case 0x4 :
return V_76 ;
case 0x3 :
return V_77 ;
case 0x2 :
return V_78 ;
case 0x1 :
return V_79 ;
case 0x0 :
return V_80 ;
default:
break;
}
return V_81 ;
}
static int F_25 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
struct V_82 * V_83 = & V_21 -> V_84 ;
enum V_55 V_56 = 0 ;
int V_33 , V_5 = 0 ;
T_2 V_85 ;
T_3 V_25 = 0 ;
T_1 V_3 ;
V_2 -> V_86 = 0 ;
if ( V_83 -> V_87 != V_88 ) {
F_3 ( L_7
L_8 ,
V_15 , V_83 -> V_87 ) ;
return - V_89 ;
}
if ( V_21 -> V_68 . V_69 . V_90 )
V_5 = V_21 -> V_68 . V_69 . V_90 ( V_21 ) ;
if ( V_5 < 0 )
return - V_47 ;
if ( V_21 -> V_68 . V_69 . V_91 )
V_5 = V_21 -> V_68 . V_69 . V_91 ( V_21 , & V_85 ) ;
if ( V_5 < 0 )
return - V_47 ;
V_25 = ( T_3 ) ( ( T_4 ) V_85 - V_83 -> V_92 ) ;
if ( ( ( V_83 -> V_92 % 192857 ) >= ( 192857 - 3000 ) ) ||
( V_83 -> V_92 % 192857 ) <= 3000 )
V_5 = F_1 ( V_2 , 0x86 , 0xc2 ) ;
else
V_5 = F_1 ( V_2 , 0x86 , 0xc6 ) ;
V_5 |= F_6 ( V_21 , V_25 ) ;
if ( V_5 < 0 )
return - V_47 ;
if ( V_83 -> V_93 > 27500000 )
V_5 = F_1 ( V_2 , 0xf1 , 0xa4 ) ;
else
V_5 = F_1 ( V_2 , 0xf1 , 0xbf ) ;
V_5 |= F_13 ( V_2 , V_94 ) ;
if ( V_5 < 0 )
return - V_47 ;
V_5 = F_23 ( V_2 , V_83 -> V_95 ) ;
V_5 |= F_1 ( V_2 , 0x85 , 0x1 ) ;
V_5 |= F_1 ( V_2 , 0x8a , 0xbf ) ;
V_5 |= F_1 ( V_2 , 0x8d , 0x1e ) ;
V_5 |= F_1 ( V_2 , 0x90 , 0xf1 ) ;
V_5 |= F_1 ( V_2 , 0x91 , 0x08 ) ;
if ( V_5 < 0 )
return - V_47 ;
V_5 = F_7 ( V_21 , V_83 -> V_93 ) ;
if ( V_5 < 0 )
return - V_47 ;
V_5 = F_13 ( V_2 , V_96 ) ;
if ( V_5 < 0 )
return - V_47 ;
for ( V_33 = 0 ; V_33 < 25 ; V_33 ++ ) {
V_3 = F_4 ( V_2 , 0x8c ) ;
if ( ( V_3 & 0xee ) == 0xee ) {
V_56 = V_61 ;
break;
}
V_2 -> V_86 ++ ;
if ( V_2 -> V_86 == 15 ) {
V_3 = F_4 ( V_2 , 0x70 ) ;
V_3 ^= 0x4 ;
F_1 ( V_2 , 0x70 , V_3 ) ;
V_2 -> V_86 = 0 ;
}
F_10 ( 20 ) ;
}
if ( V_56 & V_61 ) {
V_2 -> V_95 = F_24 ( V_2 ) ;
V_3 = F_4 ( V_2 , 0x65 ) ;
}
V_2 -> V_97 = V_83 -> V_92 ;
V_2 -> V_93 = V_83 -> V_93 ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
V_83 -> V_95 = V_2 -> V_95 ;
V_83 -> V_92 = V_2 -> V_97 ;
V_83 -> V_93 = V_2 -> V_93 ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 ,
struct V_98 * V_99 )
{
struct V_82 * V_83 = & V_21 -> V_84 ;
if ( V_83 -> V_93 > 3000000 )
V_99 -> V_100 = 2000 ;
else
V_99 -> V_100 = 3000 ;
V_99 -> V_101 = V_83 -> V_93 / 16000 ;
V_99 -> V_102 = V_83 -> V_93 / 2000 ;
return 0 ;
}
static int F_28 ( struct V_20 * V_21 , int V_103 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
if ( V_103 )
F_1 ( V_2 , 0x81 , 0x84 ) ;
else
F_1 ( V_2 , 0x81 , 0x81 ) ;
F_29 ( 10 ) ;
return 0 ;
}
static void F_30 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_31 ( V_2 ) ;
}
struct V_20 * F_32 ( const struct V_104 * V_10 ,
struct V_105 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_106 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_97 = 0 ;
V_2 -> V_93 = 0 ;
V_2 -> V_95 = 0 ;
memcpy ( & V_2 -> V_107 . V_68 , & V_108 ,
sizeof( struct V_109 ) ) ;
V_2 -> V_107 . V_22 = V_2 ;
return & V_2 -> V_107 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
