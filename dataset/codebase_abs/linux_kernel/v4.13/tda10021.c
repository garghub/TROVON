static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
int V_13 ;
V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ;
if ( V_13 != 1 )
F_3 ( L_1 ,
V_2 -> V_15 . V_16 -> V_17 , V_18 , V_3 , V_4 , V_13 ) ;
F_4 ( 10 ) ;
return ( V_13 != 1 ) ? - V_19 : 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_20 [] = { V_3 } ;
T_1 V_21 [] = { 0 } ;
struct V_6 V_7 [] = { { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_20 , . V_12 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_22 , . V_5 = V_21 , . V_12 = 1 } } ;
int V_13 ;
V_13 = F_2 ( V_2 -> V_14 , V_7 , 2 ) ;
if ( V_13 != 2 && V_3 != 0x1a )
F_3 ( L_2 ,
V_18 , V_13 ) ;
return V_21 [ 0 ] ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] = { 0x0f , V_23 [ 0x0f ] | 0x80 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
if( F_2 ( V_2 -> V_14 , & V_7 , 1 ) != 1 )
{
F_3 ( L_3 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] = { 0x0f , V_23 [ 0x0f ] & 0x7f } ;
struct V_6 V_24 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
if( F_2 ( V_2 -> V_14 , & V_24 , 1 ) != 1 )
{
F_3 ( L_4 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_25 ,
enum V_26 V_27 )
{
V_25 |= V_2 -> V_25 & 0x63 ;
if ( ( V_28 == V_27 ) ^ ( V_2 -> V_9 -> V_29 == 0 ) )
V_25 &= ~ 0x20 ;
else
V_25 |= 0x20 ;
F_1 ( V_2 , 0x00 , V_25 & 0xfe ) ;
F_1 ( V_2 , 0x00 , V_25 | 0x01 ) ;
V_2 -> V_25 = V_25 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_30 )
{
T_3 V_31 ;
T_3 V_32 ;
T_4 V_33 = 0 ;
T_5 V_34 = 0 ;
T_2 V_35 , V_36 ;
if ( V_30 > V_37 / 2 )
V_30 = V_37 / 2 ;
if ( V_30 < 500000 )
V_30 = 500000 ;
if ( V_30 < V_37 / 16 ) V_34 = 1 ;
if ( V_30 < V_37 / 32 ) V_34 = 2 ;
if ( V_30 < V_37 / 64 ) V_34 = 3 ;
if ( V_30 < ( T_2 ) ( V_37 / 12.3 ) ) V_33 = 1 ;
if ( V_30 < ( T_2 ) ( V_37 / 16 ) ) V_33 = 0 ;
if ( V_30 < ( T_2 ) ( V_37 / 24.6 ) ) V_33 = 1 ;
if ( V_30 < ( T_2 ) ( V_37 / 32 ) ) V_33 = 0 ;
if ( V_30 < ( T_2 ) ( V_37 / 49.2 ) ) V_33 = 1 ;
if ( V_30 < ( T_2 ) ( V_37 / 64 ) ) V_33 = 0 ;
if ( V_30 < ( T_2 ) ( V_37 / 98.4 ) ) V_33 = 1 ;
V_30 <<= V_34 ;
V_36 = ( V_30 << 4 ) / V_38 ;
V_35 = ( ( V_30 << 4 ) % V_38 ) << 8 ;
V_36 = ( V_36 << 8 ) + V_35 / V_38 ;
V_35 = ( V_35 % V_38 ) << 8 ;
V_36 = ( V_36 << 8 ) + F_10 ( V_35 , V_38 ) ;
V_31 = V_36 ;
V_32 = ( ( ( V_37 << 5 ) / V_30 ) + 1 ) / 2 ;
if ( V_32 > 0xFF )
V_32 = 0xFF ;
V_33 = ( V_33 << 4 ) | V_23 [ 0x0E ] ;
V_34 = ( V_34 << 6 ) | V_23 [ 0x03 ] ;
F_1 ( V_2 , 0x03 , V_34 ) ;
F_1 ( V_2 , 0x0a , V_31 & 0xff ) ;
F_1 ( V_2 , 0x0b , ( V_31 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0c , ( V_31 >> 16 ) & 0x3f ) ;
F_1 ( V_2 , 0x0d , V_32 ) ;
F_1 ( V_2 , 0x0e , V_33 ) ;
return 0 ;
}
static int F_11 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
int V_42 ;
F_12 ( L_5 , V_40 -> V_43 -> V_17 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ )
F_1 ( V_2 , V_42 , V_23 [ V_42 ] ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_45 ) ;
F_1 ( V_2 , 0x2a , V_23 [ 0x2a ] & 0xef ) ;
return 0 ;
}
static int F_13 ( struct V_39 * V_40 )
{
struct V_46 * V_47 = & V_40 -> V_48 ;
T_2 V_49 = V_47 -> V_50 ;
unsigned V_51 = V_47 -> V_52 ;
bool V_53 ;
T_2 V_54 ;
struct V_1 * V_2 = V_40 -> V_41 ;
static const struct V_55 V_55 [] = {
[ V_56 ] = { 0x14 , 0x78 , 0x78 , 0x8c , 0x96 } ,
[ V_57 ] = { 0x00 , 0x8c , 0x87 , 0xa2 , 0x91 } ,
[ V_58 ] = { 0x04 , 0x8c , 0x64 , 0x74 , 0x96 } ,
[ V_59 ] = { 0x08 , 0x6a , 0x46 , 0x43 , 0x6a } ,
[ V_60 ] = { 0x0c , 0x78 , 0x36 , 0x34 , 0x7e } ,
[ V_61 ] = { 0x10 , 0x5c , 0x26 , 0x23 , 0x6b } ,
} ;
switch ( V_49 ) {
case V_62 :
V_53 = false ;
break;
case V_63 :
V_53 = true ;
break;
default:
return - V_64 ;
}
switch ( V_51 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
break;
default:
return - V_64 ;
}
if ( V_47 -> V_27 != V_28 && V_47 -> V_27 != V_65 )
return - V_64 ;
if ( V_40 -> V_66 . V_67 . V_68 ) {
V_40 -> V_66 . V_67 . V_68 ( V_40 ) ;
if ( V_40 -> V_66 . V_69 ) V_40 -> V_66 . V_69 ( V_40 , 0 ) ;
}
F_9 ( V_2 , V_47 -> V_70 ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_45 ) ;
F_1 ( V_2 , 0x01 , V_55 [ V_51 ] . V_71 ) ;
F_1 ( V_2 , 0x05 , V_55 [ V_51 ] . V_72 ) ;
F_1 ( V_2 , 0x08 , V_55 [ V_51 ] . V_73 ) ;
F_1 ( V_2 , 0x09 , V_55 [ V_51 ] . V_74 ) ;
V_54 = F_5 ( V_2 , 0x3d ) ;
if ( V_53 )
F_1 ( V_2 , 0x3d , 0x01 | V_54 ) ;
else
F_1 ( V_2 , 0x3d , 0xfe & V_54 ) ;
F_8 ( V_2 , V_55 [ V_51 ] . V_75 , V_47 -> V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_39 * V_40 ,
enum V_76 * V_77 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
int V_78 ;
* V_77 = 0 ;
V_78 = F_5 ( V_2 , 0x11 ) ;
if ( V_78 & 2 )
* V_77 |= V_79 | V_80 ;
if ( V_78 & 4 )
* V_77 |= V_81 | V_82 ;
if ( V_78 & 8 )
* V_77 |= V_83 ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 , T_2 * V_84 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
T_2 V_85 = F_5 ( V_2 , 0x14 ) |
( F_5 ( V_2 , 0x15 ) << 8 ) |
( ( F_5 ( V_2 , 0x16 ) & 0x0f ) << 16 ) ;
F_1 ( V_2 , 0x10 , ( F_5 ( V_2 , 0x10 ) & ~ 0xc0 )
| ( V_23 [ 0x10 ] & 0xc0 ) ) ;
* V_84 = 10 * V_85 ;
return 0 ;
}
static int F_16 ( struct V_39 * V_40 , T_5 * V_86 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
T_1 V_9 = F_5 ( V_2 , 0x02 ) ;
T_1 V_87 = F_5 ( V_2 , 0x17 ) ;
if ( V_9 & 0x02 )
V_87 = ~ V_87 ;
* V_86 = ( V_87 << 8 ) | V_87 ;
return 0 ;
}
static int F_17 ( struct V_39 * V_40 , T_5 * V_88 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
T_1 V_89 = ~ F_5 ( V_2 , 0x18 ) ;
* V_88 = ( V_89 << 8 ) | V_89 ;
return 0 ;
}
static int F_18 ( struct V_39 * V_40 , T_2 * V_90 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
* V_90 = F_5 ( V_2 , 0x13 ) & 0x7f ;
if ( * V_90 == 0x7f )
* V_90 = 0xffffffff ;
F_1 ( V_2 , 0x10 , V_23 [ 0x10 ] & 0xdf ) ;
F_1 ( V_2 , 0x10 , V_23 [ 0x10 ] ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_40 ,
struct V_46 * V_91 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
int V_78 ;
T_6 V_92 = 0 ;
V_78 = F_5 ( V_2 , 0x11 ) ;
V_92 = F_5 ( V_2 , 0x19 ) ;
if ( V_93 ) {
F_3 ( V_78 & 2 ? L_6 :
L_7 ,
V_2 -> V_15 . V_16 -> V_17 , V_92 ,
- ( ( T_3 ) V_91 -> V_70 * V_92 ) >> 10 ) ;
}
V_91 -> V_27 = ( ( V_2 -> V_25 & 0x20 ) == 0x20 ) ^ ( V_2 -> V_9 -> V_29 != 0 ) ? V_28 : V_65 ;
V_91 -> V_52 = ( ( V_2 -> V_25 >> 2 ) & 7 ) + V_57 ;
V_91 -> V_94 = V_95 ;
V_91 -> V_96 = ( ( V_91 -> V_96 + 31250 ) / 62500 ) * 62500 ;
if ( V_78 & 2 )
V_91 -> V_96 -= ( ( T_3 ) V_91 -> V_70 * V_92 ) >> 10 ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 , int V_97 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
if ( V_97 ) {
F_6 ( V_2 ) ;
} else {
F_7 ( V_2 ) ;
}
return 0 ;
}
static int F_21 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
F_1 ( V_2 , 0x1b , 0x02 ) ;
F_1 ( V_2 , 0x00 , 0x80 ) ;
return 0 ;
}
static void F_22 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_41 ;
F_23 ( V_2 ) ;
}
struct V_39 * F_24 ( const struct V_98 * V_9 ,
struct V_99 * V_14 ,
T_1 V_45 )
{
struct V_1 * V_2 = NULL ;
T_1 V_100 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_101 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_25 = V_23 [ 0 ] ;
V_100 = F_5 ( V_2 , 0x1a ) ;
if ( ( V_100 & 0xf0 ) != 0x70 ) goto error;
if ( V_100 == 0x7d )
goto error;
F_3 ( L_8 ,
V_2 -> V_9 -> V_10 , V_100 ) ;
memcpy ( & V_2 -> V_15 . V_66 , & V_102 , sizeof( struct V_103 ) ) ;
V_2 -> V_15 . V_41 = V_2 ;
return & V_2 -> V_15 ;
error:
F_23 ( V_2 ) ;
return NULL ;
}
