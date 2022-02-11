static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
int V_13 ;
V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ;
if ( V_13 != 1 )
F_3 ( L_1
L_2 ,
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
F_3 ( L_3 ,
V_18 , V_13 ) ;
return V_21 [ 0 ] ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] = { 0x0f , V_23 [ 0x0f ] | 0x80 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
if( F_2 ( V_2 -> V_14 , & V_7 , 1 ) != 1 )
{
F_3 ( L_4 ) ;
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
F_3 ( L_5 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_25 ,
T_2 V_26 )
{
V_25 |= V_2 -> V_25 & 0x63 ;
if ( ( V_27 == V_26 ) ^ ( V_2 -> V_9 -> V_28 == 0 ) )
V_25 &= ~ 0x20 ;
else
V_25 |= 0x20 ;
F_1 ( V_2 , 0x00 , V_25 & 0xfe ) ;
F_1 ( V_2 , 0x00 , V_25 | 0x01 ) ;
V_2 -> V_25 = V_25 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_3 V_29 )
{
T_4 V_30 ;
T_4 V_31 ;
T_5 V_32 = 0 ;
T_6 V_33 = 0 ;
T_3 V_34 , V_35 ;
if ( V_29 > V_36 / 2 )
V_29 = V_36 / 2 ;
if ( V_29 < 500000 )
V_29 = 500000 ;
if ( V_29 < V_36 / 16 ) V_33 = 1 ;
if ( V_29 < V_36 / 32 ) V_33 = 2 ;
if ( V_29 < V_36 / 64 ) V_33 = 3 ;
if ( V_29 < ( T_3 ) ( V_36 / 12.3 ) ) V_32 = 1 ;
if ( V_29 < ( T_3 ) ( V_36 / 16 ) ) V_32 = 0 ;
if ( V_29 < ( T_3 ) ( V_36 / 24.6 ) ) V_32 = 1 ;
if ( V_29 < ( T_3 ) ( V_36 / 32 ) ) V_32 = 0 ;
if ( V_29 < ( T_3 ) ( V_36 / 49.2 ) ) V_32 = 1 ;
if ( V_29 < ( T_3 ) ( V_36 / 64 ) ) V_32 = 0 ;
if ( V_29 < ( T_3 ) ( V_36 / 98.4 ) ) V_32 = 1 ;
V_29 <<= V_33 ;
V_35 = ( V_29 << 4 ) / V_37 ;
V_34 = ( ( V_29 << 4 ) % V_37 ) << 8 ;
V_35 = ( V_35 << 8 ) + V_34 / V_37 ;
V_34 = ( V_34 % V_37 ) << 8 ;
V_35 = ( V_35 << 8 ) + F_10 ( V_34 , V_37 ) ;
V_30 = V_35 ;
V_31 = ( ( ( V_36 << 5 ) / V_29 ) + 1 ) / 2 ;
if ( V_31 > 0xFF )
V_31 = 0xFF ;
V_32 = ( V_32 << 4 ) | V_23 [ 0x0E ] ;
V_33 = ( V_33 << 6 ) | V_23 [ 0x03 ] ;
F_1 ( V_2 , 0x03 , V_33 ) ;
F_1 ( V_2 , 0x0a , V_30 & 0xff ) ;
F_1 ( V_2 , 0x0b , ( V_30 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x0c , ( V_30 >> 16 ) & 0x3f ) ;
F_1 ( V_2 , 0x0d , V_31 ) ;
F_1 ( V_2 , 0x0e , V_32 ) ;
return 0 ;
}
static int F_11 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
int V_41 ;
F_12 ( L_6 , V_39 -> V_42 -> V_17 ) ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
F_1 ( V_2 , V_41 , V_23 [ V_41 ] ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_44 ) ;
F_1 ( V_2 , 0x2a , V_23 [ 0x2a ] & 0xef ) ;
return 0 ;
}
static int F_13 ( struct V_38 * V_39 )
{
struct V_45 * V_46 = & V_39 -> V_47 ;
T_3 V_48 = V_46 -> V_49 ;
unsigned V_50 = V_46 -> V_51 ;
bool V_52 ;
T_3 V_53 ;
struct V_1 * V_2 = V_39 -> V_40 ;
static const struct V_54 V_54 [] = {
[ V_55 ] = { 0x14 , 0x78 , 0x78 , 0x8c , 0x96 } ,
[ V_56 ] = { 0x00 , 0x8c , 0x87 , 0xa2 , 0x91 } ,
[ V_57 ] = { 0x04 , 0x8c , 0x64 , 0x74 , 0x96 } ,
[ V_58 ] = { 0x08 , 0x6a , 0x46 , 0x43 , 0x6a } ,
[ V_59 ] = { 0x0c , 0x78 , 0x36 , 0x34 , 0x7e } ,
[ V_60 ] = { 0x10 , 0x5c , 0x26 , 0x23 , 0x6b } ,
} ;
switch ( V_48 ) {
case V_61 :
V_52 = false ;
break;
case V_62 :
V_52 = true ;
break;
default:
return - V_63 ;
}
switch ( V_50 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
break;
default:
return - V_63 ;
}
if ( V_46 -> V_26 != V_27 && V_46 -> V_26 != V_64 )
return - V_63 ;
if ( V_39 -> V_65 . V_66 . V_67 ) {
V_39 -> V_65 . V_66 . V_67 ( V_39 ) ;
if ( V_39 -> V_65 . V_68 ) V_39 -> V_65 . V_68 ( V_39 , 0 ) ;
}
F_9 ( V_2 , V_46 -> V_69 ) ;
F_1 ( V_2 , 0x34 , V_2 -> V_44 ) ;
F_1 ( V_2 , 0x01 , V_54 [ V_50 ] . V_70 ) ;
F_1 ( V_2 , 0x05 , V_54 [ V_50 ] . V_71 ) ;
F_1 ( V_2 , 0x08 , V_54 [ V_50 ] . V_72 ) ;
F_1 ( V_2 , 0x09 , V_54 [ V_50 ] . V_73 ) ;
V_53 = F_5 ( V_2 , 0x3d ) ;
if ( V_52 )
F_1 ( V_2 , 0x3d , 0x01 | V_53 ) ;
else
F_1 ( V_2 , 0x3d , 0xfe & V_53 ) ;
F_8 ( V_2 , V_54 [ V_50 ] . V_74 , V_46 -> V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 , T_7 * V_75 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
int V_76 ;
* V_75 = 0 ;
V_76 = F_5 ( V_2 , 0x11 ) ;
if ( V_76 & 2 )
* V_75 |= V_77 | V_78 ;
if ( V_76 & 4 )
* V_75 |= V_79 | V_80 ;
if ( V_76 & 8 )
* V_75 |= V_81 ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 , T_3 * V_82 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_3 V_83 = F_5 ( V_2 , 0x14 ) |
( F_5 ( V_2 , 0x15 ) << 8 ) |
( ( F_5 ( V_2 , 0x16 ) & 0x0f ) << 16 ) ;
F_1 ( V_2 , 0x10 , ( F_5 ( V_2 , 0x10 ) & ~ 0xc0 )
| ( V_23 [ 0x10 ] & 0xc0 ) ) ;
* V_82 = 10 * V_83 ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 , T_6 * V_84 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_9 = F_5 ( V_2 , 0x02 ) ;
T_1 V_85 = F_5 ( V_2 , 0x17 ) ;
if ( V_9 & 0x02 )
V_85 = ~ V_85 ;
* V_84 = ( V_85 << 8 ) | V_85 ;
return 0 ;
}
static int F_17 ( struct V_38 * V_39 , T_6 * V_86 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
T_1 V_87 = ~ F_5 ( V_2 , 0x18 ) ;
* V_86 = ( V_87 << 8 ) | V_87 ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 , T_3 * V_88 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
* V_88 = F_5 ( V_2 , 0x13 ) & 0x7f ;
if ( * V_88 == 0x7f )
* V_88 = 0xffffffff ;
F_1 ( V_2 , 0x10 , V_23 [ 0x10 ] & 0xdf ) ;
F_1 ( V_2 , 0x10 , V_23 [ 0x10 ] ) ;
return 0 ;
}
static int F_19 ( struct V_38 * V_39 )
{
struct V_45 * V_89 = & V_39 -> V_47 ;
struct V_1 * V_2 = V_39 -> V_40 ;
int V_76 ;
T_8 V_90 = 0 ;
V_76 = F_5 ( V_2 , 0x11 ) ;
V_90 = F_5 ( V_2 , 0x19 ) ;
if ( V_91 ) {
F_3 ( V_76 & 2 ? L_7 :
L_8 ,
V_2 -> V_15 . V_16 -> V_17 , V_90 ,
- ( ( T_4 ) V_89 -> V_69 * V_90 ) >> 10 ) ;
}
V_89 -> V_26 = ( ( V_2 -> V_25 & 0x20 ) == 0x20 ) ^ ( V_2 -> V_9 -> V_28 != 0 ) ? V_27 : V_64 ;
V_89 -> V_51 = ( ( V_2 -> V_25 >> 2 ) & 7 ) + V_56 ;
V_89 -> V_92 = V_93 ;
V_89 -> V_94 = ( ( V_89 -> V_94 + 31250 ) / 62500 ) * 62500 ;
if ( V_76 & 2 )
V_89 -> V_94 -= ( ( T_4 ) V_89 -> V_69 * V_90 ) >> 10 ;
return 0 ;
}
static int F_20 ( struct V_38 * V_39 , int V_95 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
if ( V_95 ) {
F_6 ( V_2 ) ;
} else {
F_7 ( V_2 ) ;
}
return 0 ;
}
static int F_21 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
F_1 ( V_2 , 0x1b , 0x02 ) ;
F_1 ( V_2 , 0x00 , 0x80 ) ;
return 0 ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
F_23 ( V_2 ) ;
}
struct V_38 * F_24 ( const struct V_96 * V_9 ,
struct V_97 * V_14 ,
T_1 V_44 )
{
struct V_1 * V_2 = NULL ;
T_1 V_98 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_99 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_25 = V_23 [ 0 ] ;
V_98 = F_5 ( V_2 , 0x1a ) ;
if ( ( V_98 & 0xf0 ) != 0x70 ) goto error;
if ( V_98 == 0x7d )
goto error;
F_3 ( L_9 ,
V_2 -> V_9 -> V_10 , V_98 ) ;
memcpy ( & V_2 -> V_15 . V_65 , & V_100 , sizeof( struct V_101 ) ) ;
V_2 -> V_15 . V_40 = V_2 ;
return & V_2 -> V_15 ;
error:
F_23 ( V_2 ) ;
return NULL ;
}
