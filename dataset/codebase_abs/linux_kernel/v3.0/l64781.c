static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_6 , . V_13 = 2 } ;
if ( ( V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ) != 1 )
F_3 ( L_1 ,
V_15 , V_3 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_16 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
struct V_7 V_8 [] = { { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_16 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_18 , . V_6 = V_17 , . V_13 = 1 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 ) return V_5 ;
return V_17 [ 0 ] ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x2a , 0x00 ) ;
F_1 ( V_2 , 0x2a , 0x01 ) ;
F_1 ( V_2 , 0x2a , 0x02 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x07 , 0x9e ) ;
F_1 ( V_2 , 0x08 , 0 ) ;
F_1 ( V_2 , 0x09 , 0 ) ;
F_1 ( V_2 , 0x0a , 0 ) ;
F_1 ( V_2 , 0x07 , 0x8e ) ;
F_1 ( V_2 , 0x0e , 0 ) ;
F_1 ( V_2 , 0x11 , 0x80 ) ;
F_1 ( V_2 , 0x10 , 0 ) ;
F_1 ( V_2 , 0x12 , 0 ) ;
F_1 ( V_2 , 0x13 , 0 ) ;
F_1 ( V_2 , 0x11 , 0x00 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_6 [] = { 0x06 } ;
struct V_7 V_8 = { . V_9 = 0x00 , . V_12 = 0 , . V_6 = V_6 , . V_13 = 1 } ;
return ( F_2 ( V_2 -> V_14 , & V_8 , 1 ) == 1 ) ? 0 : - V_19 ;
}
static int F_8 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
static const T_1 V_25 [] = { 7 , 0 , 1 , 2 , 9 , 3 , 10 , 4 } ;
static const T_1 V_26 [] = { 2 , 4 , 0 , 6 } ;
static const T_1 V_27 [] = { 8 , 7 , 6 } ;
static const T_1 V_28 [] = { 1 , 2 , 4 , 8 } ;
static const T_2 V_29 = 8000 ;
struct V_30 * V_31 = & V_23 -> V_32 . V_33 ;
T_2 V_34 ;
T_2 V_35 ;
T_2 V_36 ;
T_1 V_37 ;
T_1 V_38 ;
T_1 V_39 ;
int V_40 = V_31 -> V_41 - V_42 ;
if ( V_21 -> V_43 . V_44 . V_45 ) {
V_21 -> V_43 . V_44 . V_45 ( V_21 , V_23 ) ;
if ( V_21 -> V_43 . V_46 ) V_21 -> V_43 . V_46 ( V_21 , 0 ) ;
}
if ( V_23 -> V_47 != V_48 &&
V_23 -> V_47 != V_49 )
return - V_50 ;
if ( V_40 < 0 || V_40 > 2 )
return - V_50 ;
if ( V_31 -> V_51 != V_52 && V_31 -> V_51 != V_53 &&
V_31 -> V_51 != V_54 && V_31 -> V_51 != V_55 &&
V_31 -> V_51 != V_56 )
return - V_50 ;
if ( V_31 -> V_57 != V_58 &&
( V_31 -> V_59 != V_52 && V_31 -> V_59 != V_53 &&
V_31 -> V_59 != V_54 && V_31 -> V_59 != V_55 &&
V_31 -> V_59 != V_56 ) )
return - V_50 ;
if ( V_31 -> V_60 != V_61 && V_31 -> V_60 != V_62 &&
V_31 -> V_60 != V_63 )
return - V_50 ;
if ( V_31 -> V_64 != V_65 &&
V_31 -> V_64 != V_66 )
return - V_50 ;
if ( V_31 -> V_67 < V_68 ||
V_31 -> V_67 > V_69 )
return - V_50 ;
if ( V_31 -> V_57 < V_58 ||
V_31 -> V_57 > V_70 )
return - V_50 ;
V_34 = 0x4000 - ( V_29 << 16 ) / V_27 [ V_31 -> V_41 ] / 1000000 ;
V_35 = ( ( ( 8UL << 25 ) + ( 8UL << 19 ) / 25 * V_29 / ( 15625 / 25 ) ) /
V_27 [ V_31 -> V_41 ] & 0xFFFFFF ) ;
V_36 = 378 * ( 1 << 10 ) ;
V_36 *= 16 ;
V_36 *= V_27 [ V_31 -> V_41 ] ;
V_36 *= V_26 [ V_31 -> V_60 ] ;
V_36 /= V_31 -> V_51 + 1 ;
V_36 /= ( V_28 [ V_31 -> V_67 ] + 32 ) ;
V_36 *= 1000 ;
V_36 /= 1000 + V_29 / 1000 ;
V_36 *= V_31 -> V_51 ;
V_37 = ( V_31 -> V_64 << 2 ) | V_31 -> V_67 ;
V_38 = V_25 [ V_31 -> V_51 ] ;
if ( V_31 -> V_57 != V_58 )
V_38 |= ( V_31 -> V_59 - V_52 ) << 3 ;
V_39 = ( V_31 -> V_57 << 2 ) | V_31 -> V_60 ;
F_1 ( V_2 , 0x04 , V_37 ) ;
F_1 ( V_2 , 0x05 , V_38 ) ;
F_1 ( V_2 , 0x06 , V_39 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 , 0x15 ,
V_31 -> V_64 == V_65 ? 1 : 3 ) ;
F_1 ( V_2 , 0x16 , V_35 & 0xff ) ;
F_1 ( V_2 , 0x17 , ( V_35 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x18 , ( V_35 >> 16 ) & 0xff ) ;
F_1 ( V_2 , 0x1b , V_36 & 0xff ) ;
F_1 ( V_2 , 0x1c , ( V_36 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x1d , ( ( V_36 >> 16 ) & 0x7f ) |
( V_23 -> V_47 == V_48 ? 0x80 : 0x00 ) ) ;
F_1 ( V_2 , 0x22 , V_34 & 0xff ) ;
F_1 ( V_2 , 0x23 , ( V_34 >> 8 ) & 0x3f ) ;
F_4 ( V_2 , 0x00 ) ;
F_4 ( V_2 , 0x01 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
int V_71 ;
V_71 = F_4 ( V_2 , 0x04 ) ;
switch( V_71 & 3 ) {
case 0 :
V_23 -> V_32 . V_33 . V_67 = V_68 ;
break;
case 1 :
V_23 -> V_32 . V_33 . V_67 = V_72 ;
break;
case 2 :
V_23 -> V_32 . V_33 . V_67 = V_73 ;
break;
case 3 :
V_23 -> V_32 . V_33 . V_67 = V_69 ;
break;
}
switch( ( V_71 >> 2 ) & 3 ) {
case 0 :
V_23 -> V_32 . V_33 . V_64 = V_65 ;
break;
case 1 :
V_23 -> V_32 . V_33 . V_64 = V_66 ;
break;
default:
F_10 ( L_2 ) ;
}
V_71 = F_4 ( V_2 , 0x05 ) ;
switch( V_71 & 7 ) {
case 0 :
V_23 -> V_32 . V_33 . V_51 = V_52 ;
break;
case 1 :
V_23 -> V_32 . V_33 . V_51 = V_53 ;
break;
case 2 :
V_23 -> V_32 . V_33 . V_51 = V_54 ;
break;
case 3 :
V_23 -> V_32 . V_33 . V_51 = V_55 ;
break;
case 4 :
V_23 -> V_32 . V_33 . V_51 = V_56 ;
break;
default:
F_10 ( L_3 ) ;
}
switch( ( V_71 >> 3 ) & 7 ) {
case 0 :
V_23 -> V_32 . V_33 . V_59 = V_52 ;
break;
case 1 :
V_23 -> V_32 . V_33 . V_59 = V_53 ;
break;
case 2 :
V_23 -> V_32 . V_33 . V_59 = V_54 ;
break;
case 3 :
V_23 -> V_32 . V_33 . V_59 = V_55 ;
break;
case 4 :
V_23 -> V_32 . V_33 . V_59 = V_56 ;
break;
default:
F_10 ( L_4 ) ;
}
V_71 = F_4 ( V_2 , 0x06 ) ;
switch( V_71 & 3 ) {
case 0 :
V_23 -> V_32 . V_33 . V_60 = V_61 ;
break;
case 1 :
V_23 -> V_32 . V_33 . V_60 = V_62 ;
break;
case 2 :
V_23 -> V_32 . V_33 . V_60 = V_63 ;
break;
default:
F_10 ( L_5 ) ;
}
switch( ( V_71 >> 2 ) & 7 ) {
case 0 :
V_23 -> V_32 . V_33 . V_57 = V_58 ;
break;
case 1 :
V_23 -> V_32 . V_33 . V_57 = V_74 ;
break;
case 2 :
V_23 -> V_32 . V_33 . V_57 = V_75 ;
break;
case 3 :
V_23 -> V_32 . V_33 . V_57 = V_70 ;
break;
default:
F_10 ( L_6 ) ;
}
V_71 = F_4 ( V_2 , 0x1d ) ;
V_23 -> V_47 = ( V_71 & 0x80 ) ? V_48 : V_49 ;
V_71 = ( int ) ( F_4 ( V_2 , 0x08 ) |
( F_4 ( V_2 , 0x09 ) << 8 ) |
( F_4 ( V_2 , 0x0a ) << 16 ) ) ;
V_23 -> V_76 += V_71 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 , T_3 * V_77 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
int V_78 = F_4 ( V_2 , 0x32 ) ;
int V_79 = F_4 ( V_2 , 0x0e ) ;
F_4 ( V_2 , 0x00 ) ;
F_4 ( V_2 , 0x01 ) ;
* V_77 = 0 ;
if ( V_79 > 5 )
* V_77 |= V_80 ;
if ( V_78 & 0x02 )
* V_77 |= V_81 ;
if ( V_78 & 0x20 )
* V_77 |= V_82 ;
if ( V_78 & 0x40 )
* V_77 |= V_83 ;
if ( V_78 == 0x7f )
* V_77 |= V_84 ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , T_2 * V_85 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
* V_85 = F_4 ( V_2 , 0x39 )
| ( F_4 ( V_2 , 0x3a ) << 8 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 , T_4 * V_86 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
T_1 V_79 = F_4 ( V_2 , 0x0e ) ;
* V_86 = ( V_79 << 8 ) | V_79 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 , T_4 * V_87 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
T_1 V_88 = 0xff - F_4 ( V_2 , 0x33 ) ;
* V_87 = ( V_88 << 8 ) | V_88 ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , T_2 * V_89 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
* V_89 = F_4 ( V_2 , 0x37 )
| ( F_4 ( V_2 , 0x38 ) << 8 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
return F_1 ( V_2 , 0x3e , 0x5a ) ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
F_7 ( V_2 ) ;
F_1 ( V_2 , 0x3e , 0xa5 ) ;
F_1 ( V_2 , 0x2a , 0x04 ) ;
F_1 ( V_2 , 0x2a , 0x00 ) ;
F_1 ( V_2 , 0x07 , 0x8e ) ;
F_1 ( V_2 , 0x0b , 0x81 ) ;
F_1 ( V_2 , 0x0c , 0x84 ) ;
F_1 ( V_2 , 0x0d , 0x8c ) ;
F_1 ( V_2 , 0x1e , 0x09 ) ;
if ( V_2 -> V_90 ) {
V_2 -> V_90 = 0 ;
F_18 ( 200 ) ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 ,
struct V_91 * V_92 )
{
V_92 -> V_93 = 4000 ;
V_92 -> V_94 = 0 ;
V_92 -> V_95 = 0 ;
return 0 ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_24 ;
F_21 ( V_2 ) ;
}
struct V_20 * F_22 ( const struct V_96 * V_10 ,
struct V_97 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_98 = - 1 ;
T_1 V_16 [] = { 0x1a } ;
T_1 V_17 [] = { 0x00 } ;
struct V_7 V_8 [] = { { . V_9 = V_10 -> V_11 , . V_12 = 0 , . V_6 = V_16 , . V_13 = 1 } ,
{ . V_9 = V_10 -> V_11 , . V_12 = V_18 , . V_6 = V_17 , . V_13 = 1 } } ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_99 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_90 = 1 ;
if ( F_7 ( V_2 ) < 0 ) {
F_3 ( L_7 ) ;
goto error;
}
if ( F_2 ( V_2 -> V_14 , V_8 , 2 ) != 2 ) {
F_3 ( L_8 ) ;
goto error;
}
V_98 = F_4 ( V_2 , 0x3e ) ;
if ( V_98 != 0 ) {
F_3 ( L_9 ) ;
goto error;
}
F_1 ( V_2 , 0x3e , 0x5a ) ;
if ( F_4 ( V_2 , 0x1a ) != 0 ) {
F_3 ( L_10 ) ;
goto error;
}
F_1 ( V_2 , 0x3e , 0xa5 ) ;
if ( F_4 ( V_2 , 0x1a ) != 0xa1 ) {
F_3 ( L_11 ) ;
goto error;
}
memcpy ( & V_2 -> V_100 . V_43 , & V_101 , sizeof( struct V_102 ) ) ;
V_2 -> V_100 . V_24 = V_2 ;
return & V_2 -> V_100 ;
error:
if ( V_98 >= 0 )
F_1 ( V_2 , 0x3e , V_98 ) ;
F_21 ( V_2 ) ;
return NULL ;
}
