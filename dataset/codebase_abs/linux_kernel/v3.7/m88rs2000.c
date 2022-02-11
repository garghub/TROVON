static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
int V_6 ;
T_1 V_7 = ( V_3 == 0 ) ? V_2 -> V_8 -> V_9 :
V_2 -> V_8 -> V_10 ;
T_1 V_11 [] = { V_4 , V_5 } ;
struct V_12 V_13 = {
. V_7 = V_7 ,
. V_14 = 0 ,
. V_11 = V_11 ,
. V_15 = 2
} ;
V_6 = F_2 ( V_2 -> V_16 , & V_13 , 1 ) ;
if ( V_6 != 1 )
F_3 ( L_1
L_2 , V_17 , V_4 , V_5 , V_6 ) ;
return ( V_6 != 1 ) ? - V_18 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
return F_1 ( V_2 , 1 , V_4 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_4 , T_1 V_5 )
{
F_4 ( V_2 , 0x81 , 0x84 ) ;
F_6 ( 10 ) ;
return F_1 ( V_2 , 0 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_19 * V_20 , const T_1 V_11 [] , int V_15 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
if ( V_15 != 2 )
return - V_22 ;
return F_1 ( V_2 , 1 , V_11 [ 0 ] , V_11 [ 1 ] ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_6 ;
T_1 V_23 [] = { V_4 } ;
T_1 V_24 [] = { 0 } ;
T_1 V_7 = ( V_3 == 0 ) ? V_2 -> V_8 -> V_9 :
V_2 -> V_8 -> V_10 ;
struct V_12 V_13 [] = {
{
. V_7 = V_7 ,
. V_14 = 0 ,
. V_11 = V_23 ,
. V_15 = 1
} , {
. V_7 = V_7 ,
. V_14 = V_25 ,
. V_11 = V_24 ,
. V_15 = 1
}
} ;
V_6 = F_2 ( V_2 -> V_16 , V_13 , 2 ) ;
if ( V_6 != 2 )
F_3 ( L_3 ,
V_17 , V_4 , V_6 ) ;
return V_24 [ 0 ] ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_8 ( V_2 , 1 , V_4 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 V_4 )
{
F_4 ( V_2 , 0x81 , 0x85 ) ;
F_6 ( 10 ) ;
return F_8 ( V_2 , 0 , V_4 ) ;
}
static int F_11 ( struct V_19 * V_20 , T_2 V_26 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
T_2 V_27 ;
T_1 V_28 [ 3 ] ;
if ( ( V_26 < 1000000 ) || ( V_26 > 45000000 ) )
return - V_22 ;
V_27 = V_26 / 1000 ;
V_27 *= 11831 ;
V_27 /= 68 ;
V_27 -= 3 ;
V_28 [ 0 ] = ( T_1 ) ( V_27 >> 16 ) & 0xff ;
V_28 [ 1 ] = ( T_1 ) ( V_27 >> 8 ) & 0xff ;
V_28 [ 2 ] = ( T_1 ) V_27 & 0xff ;
V_6 = F_4 ( V_2 , 0x93 , V_28 [ 2 ] ) ;
V_6 |= F_4 ( V_2 , 0x94 , V_28 [ 1 ] ) ;
V_6 |= F_4 ( V_2 , 0x95 , V_28 [ 0 ] ) ;
F_3 ( L_4 ) ;
return V_6 ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_31 ;
T_1 V_4 ;
F_3 ( L_5 , V_17 ) ;
F_4 ( V_2 , 0x9a , 0x30 ) ;
V_4 = F_9 ( V_2 , 0xb2 ) ;
V_4 &= 0x3f ;
F_4 ( V_2 , 0xb2 , V_4 ) ;
for ( V_31 = 0 ; V_31 < V_30 -> V_32 ; V_31 ++ )
F_4 ( V_2 , 0xb3 + V_31 , V_30 -> V_13 [ V_31 ] ) ;
V_4 = F_9 ( V_2 , 0xb1 ) ;
V_4 &= 0x87 ;
V_4 |= ( ( V_30 -> V_32 - 1 ) << 3 ) | 0x07 ;
V_4 &= 0x7f ;
F_4 ( V_2 , 0xb1 , V_4 ) ;
for ( V_31 = 0 ; V_31 < 15 ; V_31 ++ ) {
if ( ( F_9 ( V_2 , 0xb1 ) & 0x40 ) == 0x0 )
break;
F_13 ( 20 ) ;
}
V_4 = F_9 ( V_2 , 0xb1 ) ;
if ( ( V_4 & 0x40 ) > 0x0 ) {
V_4 &= 0x7f ;
V_4 |= 0x40 ;
F_4 ( V_2 , 0xb1 , V_4 ) ;
}
V_4 = F_9 ( V_2 , 0xb2 ) ;
V_4 &= 0x3f ;
V_4 |= 0x80 ;
F_4 ( V_2 , 0xb2 , V_4 ) ;
F_4 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 ,
T_3 V_33 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_34 , V_35 ;
F_3 ( L_5 , V_17 ) ;
F_4 ( V_2 , 0x9a , 0x30 ) ;
F_13 ( 50 ) ;
V_34 = F_9 ( V_2 , 0xb1 ) ;
V_35 = F_9 ( V_2 , 0xb2 ) ;
F_4 ( V_2 , 0xb2 , V_35 ) ;
F_4 ( V_2 , 0xb1 , V_34 ) ;
F_4 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 , T_4 V_36 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_34 , V_35 ;
F_4 ( V_2 , 0x9a , 0x30 ) ;
V_34 = F_9 ( V_2 , 0xb1 ) ;
V_35 = F_9 ( V_2 , 0xb2 ) ;
V_35 &= 0x3f ;
switch ( V_36 ) {
case V_37 :
V_34 |= 0x4 ;
V_34 &= 0xbc ;
break;
case V_38 :
V_35 |= 0x80 ;
break;
default:
break;
}
F_4 ( V_2 , 0xb2 , V_35 ) ;
F_4 ( V_2 , 0xb1 , V_34 ) ;
F_4 ( V_2 , 0x9a , 0xb0 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
int V_6 = 0 ;
T_1 V_31 ;
if ( V_40 == NULL )
return - V_22 ;
for ( V_31 = 0 ; V_31 < 255 ; V_31 ++ ) {
switch ( V_40 [ V_31 ] . V_41 ) {
case 0x01 :
V_6 = F_4 ( V_2 , V_40 [ V_31 ] . V_4 ,
V_40 [ V_31 ] . V_42 ) ;
break;
case 0x02 :
V_6 = F_5 ( V_2 , V_40 [ V_31 ] . V_4 ,
V_40 [ V_31 ] . V_42 ) ;
break;
case 0x10 :
if ( V_40 [ V_31 ] . V_4 > 0 )
F_17 ( V_40 [ V_31 ] . V_4 ) ;
break;
case 0xff :
if ( V_40 [ V_31 ] . V_4 == 0xaa && V_40 [ V_31 ] . V_42 == 0xff )
return 0 ;
case 0x00 :
break;
default:
return - V_22 ;
}
if ( V_6 < 0 )
return - V_43 ;
}
return 0 ;
}
static int F_18 ( struct V_19 * V_20 , T_5 V_44 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_5 ;
V_5 = F_9 ( V_2 , 0xb2 ) ;
V_5 |= 0x03 ;
switch ( V_44 ) {
case V_45 :
V_5 &= ~ 0x03 ;
break;
case V_46 :
V_5 &= ~ 0x03 ;
V_5 |= 0x01 ;
break;
case V_47 :
break;
}
F_4 ( V_2 , 0xb2 , V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_4 ;
V_4 = F_10 ( V_2 , 0x00 ) ;
if ( ( V_4 & 0x40 ) == 0 )
V_6 = - V_43 ;
return V_6 ;
}
static int F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
F_3 ( L_6 ) ;
V_6 = F_16 ( V_2 , V_48 ) ;
return V_6 ;
}
static int F_21 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
V_6 = F_16 ( V_2 , V_49 ) ;
return V_6 ;
}
static int F_22 ( struct V_19 * V_20 , T_6 * V_50 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
T_1 V_4 = F_9 ( V_2 , 0x8c ) ;
* V_50 = 0 ;
if ( ( V_4 & 0x7 ) == 0x7 ) {
* V_50 = V_51 | V_52 | V_53
| V_54 | V_55 ;
if ( V_2 -> V_8 -> V_56 )
V_2 -> V_8 -> V_56 ( V_20 , V_57 ) ;
}
return 0 ;
}
static int F_23 ( struct V_19 * V_20 , T_2 * V_58 )
{
F_3 ( L_7 , * V_58 ) ;
* V_58 = 0 ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 ,
T_7 * V_59 )
{
* V_59 = 0 ;
return 0 ;
}
static int F_25 ( struct V_19 * V_20 , T_7 * V_60 )
{
F_3 ( L_8 , * V_60 ) ;
* V_60 = 0 ;
return 0 ;
}
static int F_26 ( struct V_19 * V_20 , T_2 * V_61 )
{
F_3 ( L_7 , * V_61 ) ;
* V_61 = 0 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_62 )
{
int V_6 ;
V_6 = F_5 ( V_2 , 0x51 , 0x1f - V_62 ) ;
V_6 |= F_5 ( V_2 , 0x51 , 0x1f ) ;
V_6 |= F_5 ( V_2 , 0x50 , V_62 ) ;
V_6 |= F_5 ( V_2 , 0x50 , 0x00 ) ;
F_13 ( 20 ) ;
return V_6 ;
}
static int F_28 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
int V_4 ;
V_4 = F_10 ( V_2 , 0x3d ) ;
V_4 &= 0x7f ;
if ( V_4 < 0x16 )
V_4 = 0xa1 ;
else if ( V_4 == 0x16 )
V_4 = 0x99 ;
else
V_4 = 0xf9 ;
F_5 ( V_2 , 0x60 , V_4 ) ;
V_4 = F_27 ( V_2 , 0x08 ) ;
if ( V_20 -> V_63 . V_64 )
V_20 -> V_63 . V_64 ( V_20 , 0 ) ;
return V_4 ;
}
static int F_29 ( struct V_19 * V_20 , T_7 * V_62 )
{
struct V_65 * V_66 = & V_20 -> V_67 ;
struct V_1 * V_2 = V_20 -> V_21 ;
int V_6 ;
T_2 V_68 = V_66 -> V_68 ;
T_8 V_69 ;
T_8 V_70 ;
T_2 V_71 = ( V_66 -> V_71 / 1000 ) ;
T_2 V_72 , V_73 ;
T_7 V_74 , V_75 , V_76 ;
T_1 V_77 , V_78 , V_79 , V_80 ;
T_1 V_81 = 0x01 , V_82 = 0x0 ;
V_6 = F_16 ( V_2 , V_83 ) ;
if ( V_68 < 1060000 ) {
V_81 |= 0x10 ;
V_82 = 0x1 ;
V_75 = ( V_68 * 14 * 4 ) / V_84 ;
} else
V_75 = ( V_68 * 14 * 2 ) / V_84 ;
V_75 = V_75 + V_75 % 2 ;
V_75 = V_75 - 1024 ;
V_6 = F_5 ( V_2 , 0x10 , 0x80 | V_81 ) ;
V_6 |= F_5 ( V_2 , 0x01 , ( V_75 >> 8 ) & 0xf ) ;
V_6 |= F_5 ( V_2 , 0x02 , V_75 & 0xff ) ;
V_6 |= F_5 ( V_2 , 0x03 , 0x06 ) ;
V_6 |= F_27 ( V_2 , 0x10 ) ;
if ( V_6 < 0 )
return - V_43 ;
V_6 = F_5 ( V_2 , 0x10 , V_81 ) ;
V_6 |= F_27 ( V_2 , 0x08 ) ;
V_6 |= F_28 ( V_20 ) ;
V_73 = ( V_84 / 1000 * 1694 + 500 ) / 1000 ;
V_6 |= F_5 ( V_2 , 0x04 , V_73 & 0xff ) ;
V_6 |= F_27 ( V_2 , 0x04 ) ;
if ( V_6 < 0 )
return - V_43 ;
V_74 = F_10 ( V_2 , 0x26 ) ;
V_72 = ( V_71 * 135 ) / 200 + 2000 ;
V_72 += V_85 ;
if ( V_72 < 7000 )
V_72 = 7000 ;
if ( V_72 > 40000 )
V_72 = 40000 ;
V_73 = V_73 * 207 / ( V_74 * 2 + 151 ) ;
V_78 = V_73 * 135 / 100 ;
V_79 = V_73 * 78 / 100 ;
if ( V_78 > 63 )
V_78 = 63 ;
V_76 = 2766 ;
V_80 = ( V_72 * V_73 * 2 / V_76 /
( V_84 / 1000 ) + 1 ) / 2 ;
if ( V_80 > 23 )
V_80 = 23 ;
if ( V_80 < 1 )
V_80 = 1 ;
V_77 = ( V_80 * ( V_84 / 1000 )
* V_76 * 2 / V_72 + 1 ) / 2 ;
if ( V_77 < V_79 ) {
V_80 ++ ;
V_77 = ( V_80 * ( V_84 / 1000 )
* V_76 * 2 / V_72 + 1 ) / 2 ;
}
if ( V_77 > V_78 )
V_77 = V_78 ;
V_6 = F_5 ( V_2 , 0x04 , V_77 ) ;
V_6 |= F_5 ( V_2 , 0x06 , V_80 ) ;
V_6 |= F_27 ( V_2 , 0x04 ) ;
V_6 |= F_27 ( V_2 , 0x01 ) ;
F_13 ( 80 ) ;
V_69 = ( V_75 - V_75 % 2 + 1024 ) * V_84
/ 14 / ( V_82 + 1 ) / 2 ;
V_69 -= V_68 ;
V_70 = V_69 ;
V_70 *= 65536 ;
V_70 = ( 2 * V_70 + 96000 ) / ( 2 * 96000 ) ;
if ( V_70 < 0 )
V_70 += 65536 ;
* V_62 = V_70 & 0xffff ;
if ( V_20 -> V_63 . V_64 )
V_20 -> V_63 . V_64 ( V_20 , 0 ) ;
return ( V_6 < 0 ) ? - V_22 : 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
T_9 V_86 )
{
T_7 V_87 ;
switch ( V_86 ) {
case V_88 :
default:
V_87 = 0x08 ;
}
F_4 ( V_2 , 0x76 , V_87 ) ;
return 0 ;
}
static T_9 F_31 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_4 ( V_2 , 0x9a , 0x30 ) ;
V_4 = F_9 ( V_2 , 0x76 ) ;
F_4 ( V_2 , 0x9a , 0xb0 ) ;
switch ( V_4 ) {
case 0x88 :
return V_89 ;
case 0x68 :
return V_90 ;
case 0x48 :
return V_91 ;
case 0x28 :
return V_92 ;
case 0x18 :
return V_93 ;
case 0x08 :
default:
break;
}
return V_88 ;
}
static int F_32 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_65 * V_66 = & V_20 -> V_67 ;
T_6 V_50 ;
int V_31 , V_6 ;
T_7 V_62 = 0 ;
T_1 V_4 ;
V_2 -> V_94 = 0 ;
if ( V_66 -> V_95 != V_96 ) {
F_3 ( L_9
L_10 ,
V_17 , V_66 -> V_95 ) ;
return - V_97 ;
}
V_6 = F_29 ( V_20 , & V_62 ) ;
if ( V_6 < 0 )
return - V_43 ;
V_6 = F_4 ( V_2 , 0x9a , 0x30 ) ;
V_4 = F_9 ( V_2 , 0x86 ) ;
V_6 |= F_4 ( V_2 , 0x86 , V_4 ) ;
V_6 |= F_4 ( V_2 , 0x9c , ( V_62 >> 8 ) ) ;
V_6 |= F_4 ( V_2 , 0x9d , V_62 & 0xf0 ) ;
V_6 = F_16 ( V_2 , V_98 ) ;
if ( V_6 < 0 )
return - V_43 ;
V_4 = F_9 ( V_2 , 0x70 ) ;
V_6 = F_4 ( V_2 , 0x70 , V_4 ) ;
V_6 |= F_30 ( V_2 , V_66 -> V_99 ) ;
V_6 |= F_4 ( V_2 , 0x85 , 0x1 ) ;
V_6 |= F_4 ( V_2 , 0x8a , 0xbf ) ;
V_6 |= F_4 ( V_2 , 0x8d , 0x1e ) ;
V_6 |= F_4 ( V_2 , 0x90 , 0xf1 ) ;
V_6 |= F_4 ( V_2 , 0x91 , 0x08 ) ;
if ( V_6 < 0 )
return - V_43 ;
V_6 = F_11 ( V_20 , V_66 -> V_71 ) ;
if ( V_6 < 0 )
return - V_43 ;
V_6 = F_16 ( V_2 , V_100 ) ;
if ( V_6 < 0 )
return - V_43 ;
for ( V_31 = 0 ; V_31 < 25 ; V_31 ++ ) {
V_4 = F_9 ( V_2 , 0x8c ) ;
if ( ( V_4 & 0x7 ) == 0x7 ) {
V_50 = V_55 ;
break;
}
V_2 -> V_94 ++ ;
if ( V_2 -> V_94 == 15 ) {
V_4 = F_9 ( V_2 , 0x70 ) ;
V_4 ^= 0x4 ;
F_4 ( V_2 , 0x70 , V_4 ) ;
V_2 -> V_94 = 0 ;
}
if ( V_2 -> V_94 == 20 )
F_28 ( V_20 ) ;
F_13 ( 20 ) ;
}
if ( V_50 & V_55 ) {
V_2 -> V_99 = F_31 ( V_2 ) ;
V_4 = F_9 ( V_2 , 0x65 ) ;
}
V_2 -> V_101 = V_66 -> V_68 ;
V_2 -> V_71 = V_66 -> V_71 ;
return 0 ;
}
static int F_33 ( struct V_19 * V_20 )
{
struct V_65 * V_66 = & V_20 -> V_67 ;
struct V_1 * V_2 = V_20 -> V_21 ;
V_66 -> V_99 = V_2 -> V_99 ;
V_66 -> V_68 = V_2 -> V_101 ;
V_66 -> V_71 = V_2 -> V_71 ;
return 0 ;
}
static int F_34 ( struct V_19 * V_20 , int V_102 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
if ( V_102 )
F_4 ( V_2 , 0x81 , 0x84 ) ;
else
F_4 ( V_2 , 0x81 , 0x81 ) ;
F_6 ( 10 ) ;
return 0 ;
}
static void F_35 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 ;
F_36 ( V_2 ) ;
}
struct V_19 * F_37 ( const struct V_103 * V_8 ,
struct V_104 * V_16 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_105 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_8 = V_8 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_101 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_99 = 0 ;
if ( F_19 ( V_2 ) < 0 )
goto error;
memcpy ( & V_2 -> V_106 . V_63 , & V_107 ,
sizeof( struct V_108 ) ) ;
V_2 -> V_106 . V_21 = V_2 ;
return & V_2 -> V_106 ;
error:
F_36 ( V_2 ) ;
return NULL ;
}
