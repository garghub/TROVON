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
static int F_8 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_24 ;
struct V_1 * V_2 = V_21 -> V_25 ;
static const T_1 V_26 [] = { 7 , 0 , 1 , 2 , 9 , 3 , 10 , 4 } ;
static const T_1 V_27 [] = { 2 , 4 , 0 , 6 } ;
static const T_1 V_28 [] = { 1 , 2 , 4 , 8 } ;
static const T_2 V_29 = 8000 ;
T_2 V_30 ;
T_2 V_31 ;
T_2 V_32 ;
T_1 V_33 ;
T_1 V_34 ;
T_1 V_35 ;
int V_36 ;
switch ( V_23 -> V_37 ) {
case 8000000 :
V_36 = 8 ;
break;
case 7000000 :
V_36 = 7 ;
break;
case 6000000 :
V_36 = 6 ;
break;
default:
return - V_38 ;
}
if ( V_21 -> V_39 . V_40 . V_41 ) {
V_21 -> V_39 . V_40 . V_41 ( V_21 ) ;
if ( V_21 -> V_39 . V_42 ) V_21 -> V_39 . V_42 ( V_21 , 0 ) ;
}
if ( V_23 -> V_43 != V_44 &&
V_23 -> V_43 != V_45 )
return - V_38 ;
if ( V_23 -> V_46 != V_47 && V_23 -> V_46 != V_48 &&
V_23 -> V_46 != V_49 && V_23 -> V_46 != V_50 &&
V_23 -> V_46 != V_51 )
return - V_38 ;
if ( V_23 -> V_52 != V_53 &&
( V_23 -> V_54 != V_47 && V_23 -> V_54 != V_48 &&
V_23 -> V_54 != V_49 && V_23 -> V_54 != V_50 &&
V_23 -> V_54 != V_51 ) )
return - V_38 ;
if ( V_23 -> V_55 != V_56 && V_23 -> V_55 != V_57 &&
V_23 -> V_55 != V_58 )
return - V_38 ;
if ( V_23 -> V_59 != V_60 &&
V_23 -> V_59 != V_61 )
return - V_38 ;
if ( ( int ) V_23 -> V_62 < V_63 ||
V_23 -> V_62 > V_64 )
return - V_38 ;
if ( ( int ) V_23 -> V_52 < V_53 ||
V_23 -> V_52 > V_65 )
return - V_38 ;
V_30 = 0x4000 - ( V_29 << 16 ) / V_36 / 1000000 ;
V_31 = ( ( ( 8UL << 25 ) + ( 8UL << 19 ) / 25 * V_29 / ( 15625 / 25 ) ) /
V_36 & 0xFFFFFF ) ;
V_32 = 378 * ( 1 << 10 ) ;
V_32 *= 16 ;
V_32 *= V_36 ;
V_32 *= V_27 [ V_23 -> V_55 ] ;
V_32 /= V_23 -> V_46 + 1 ;
V_32 /= ( V_28 [ V_23 -> V_62 ] + 32 ) ;
V_32 *= 1000 ;
V_32 /= 1000 + V_29 / 1000 ;
V_32 *= V_23 -> V_46 ;
V_33 = ( V_23 -> V_59 << 2 ) | V_23 -> V_62 ;
V_34 = V_26 [ V_23 -> V_46 ] ;
if ( V_23 -> V_52 != V_53 )
V_34 |= ( V_23 -> V_54 - V_47 ) << 3 ;
V_35 = ( V_23 -> V_52 << 2 ) | V_23 -> V_55 ;
F_1 ( V_2 , 0x04 , V_33 ) ;
F_1 ( V_2 , 0x05 , V_34 ) ;
F_1 ( V_2 , 0x06 , V_35 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 , 0x15 ,
V_23 -> V_59 == V_60 ? 1 : 3 ) ;
F_1 ( V_2 , 0x16 , V_31 & 0xff ) ;
F_1 ( V_2 , 0x17 , ( V_31 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x18 , ( V_31 >> 16 ) & 0xff ) ;
F_1 ( V_2 , 0x1b , V_32 & 0xff ) ;
F_1 ( V_2 , 0x1c , ( V_32 >> 8 ) & 0xff ) ;
F_1 ( V_2 , 0x1d , ( ( V_32 >> 16 ) & 0x7f ) |
( V_23 -> V_43 == V_44 ? 0x80 : 0x00 ) ) ;
F_1 ( V_2 , 0x22 , V_30 & 0xff ) ;
F_1 ( V_2 , 0x23 , ( V_30 >> 8 ) & 0x3f ) ;
F_4 ( V_2 , 0x00 ) ;
F_4 ( V_2 , 0x01 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
int V_66 ;
V_66 = F_4 ( V_2 , 0x04 ) ;
switch( V_66 & 3 ) {
case 0 :
V_23 -> V_62 = V_63 ;
break;
case 1 :
V_23 -> V_62 = V_67 ;
break;
case 2 :
V_23 -> V_62 = V_68 ;
break;
case 3 :
V_23 -> V_62 = V_64 ;
break;
}
switch( ( V_66 >> 2 ) & 3 ) {
case 0 :
V_23 -> V_59 = V_60 ;
break;
case 1 :
V_23 -> V_59 = V_61 ;
break;
default:
F_10 ( V_69 L_2 ) ;
}
V_66 = F_4 ( V_2 , 0x05 ) ;
switch( V_66 & 7 ) {
case 0 :
V_23 -> V_46 = V_47 ;
break;
case 1 :
V_23 -> V_46 = V_48 ;
break;
case 2 :
V_23 -> V_46 = V_49 ;
break;
case 3 :
V_23 -> V_46 = V_50 ;
break;
case 4 :
V_23 -> V_46 = V_51 ;
break;
default:
F_10 ( L_3 ) ;
}
switch( ( V_66 >> 3 ) & 7 ) {
case 0 :
V_23 -> V_54 = V_47 ;
break;
case 1 :
V_23 -> V_54 = V_48 ;
break;
case 2 :
V_23 -> V_54 = V_49 ;
break;
case 3 :
V_23 -> V_54 = V_50 ;
break;
case 4 :
V_23 -> V_54 = V_51 ;
break;
default:
F_10 ( L_4 ) ;
}
V_66 = F_4 ( V_2 , 0x06 ) ;
switch( V_66 & 3 ) {
case 0 :
V_23 -> V_55 = V_56 ;
break;
case 1 :
V_23 -> V_55 = V_57 ;
break;
case 2 :
V_23 -> V_55 = V_58 ;
break;
default:
F_10 ( V_69 L_5 ) ;
}
switch( ( V_66 >> 2 ) & 7 ) {
case 0 :
V_23 -> V_52 = V_53 ;
break;
case 1 :
V_23 -> V_52 = V_70 ;
break;
case 2 :
V_23 -> V_52 = V_71 ;
break;
case 3 :
V_23 -> V_52 = V_65 ;
break;
default:
F_10 ( L_6 ) ;
}
V_66 = F_4 ( V_2 , 0x1d ) ;
V_23 -> V_43 = ( V_66 & 0x80 ) ? V_44 : V_45 ;
V_66 = ( int ) ( F_4 ( V_2 , 0x08 ) |
( F_4 ( V_2 , 0x09 ) << 8 ) |
( F_4 ( V_2 , 0x0a ) << 16 ) ) ;
V_23 -> V_72 += V_66 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 , enum V_73 * V_74 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
int V_75 = F_4 ( V_2 , 0x32 ) ;
int V_76 = F_4 ( V_2 , 0x0e ) ;
F_4 ( V_2 , 0x00 ) ;
F_4 ( V_2 , 0x01 ) ;
* V_74 = 0 ;
if ( V_76 > 5 )
* V_74 |= V_77 ;
if ( V_75 & 0x02 )
* V_74 |= V_78 ;
if ( V_75 & 0x20 )
* V_74 |= V_79 ;
if ( V_75 & 0x40 )
* V_74 |= V_80 ;
if ( V_75 == 0x7f )
* V_74 |= V_81 ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , T_2 * V_82 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
* V_82 = F_4 ( V_2 , 0x39 )
| ( F_4 ( V_2 , 0x3a ) << 8 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 , T_3 * V_83 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
T_1 V_76 = F_4 ( V_2 , 0x0e ) ;
* V_83 = ( V_76 << 8 ) | V_76 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 , T_3 * V_84 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
T_1 V_85 = 0xff - F_4 ( V_2 , 0x33 ) ;
* V_84 = ( V_85 << 8 ) | V_85 ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , T_2 * V_86 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
* V_86 = F_4 ( V_2 , 0x37 )
| ( F_4 ( V_2 , 0x38 ) << 8 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
return F_1 ( V_2 , 0x3e , 0x5a ) ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
F_7 ( V_2 ) ;
F_1 ( V_2 , 0x3e , 0xa5 ) ;
F_1 ( V_2 , 0x2a , 0x04 ) ;
F_1 ( V_2 , 0x2a , 0x00 ) ;
F_1 ( V_2 , 0x07 , 0x8e ) ;
F_1 ( V_2 , 0x0b , 0x81 ) ;
F_1 ( V_2 , 0x0c , 0x84 ) ;
F_1 ( V_2 , 0x0d , 0x8c ) ;
F_1 ( V_2 , 0x1e , 0x09 ) ;
if ( V_2 -> V_87 ) {
V_2 -> V_87 = 0 ;
F_18 ( 200 ) ;
}
return 0 ;
}
static int F_19 ( struct V_20 * V_21 ,
struct V_88 * V_89 )
{
V_89 -> V_90 = 4000 ;
V_89 -> V_91 = 0 ;
V_89 -> V_92 = 0 ;
return 0 ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
F_21 ( V_2 ) ;
}
struct V_20 * F_22 ( const struct V_93 * V_10 ,
struct V_94 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_95 = - 1 ;
T_1 V_16 [] = { 0x1a } ;
T_1 V_17 [] = { 0x00 } ;
struct V_7 V_8 [] = { { . V_9 = V_10 -> V_11 , . V_12 = 0 , . V_6 = V_16 , . V_13 = 1 } ,
{ . V_9 = V_10 -> V_11 , . V_12 = V_18 , . V_6 = V_17 , . V_13 = 1 } } ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_96 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_87 = 1 ;
if ( F_7 ( V_2 ) < 0 ) {
F_3 ( L_7 ) ;
goto error;
}
if ( F_2 ( V_2 -> V_14 , V_8 , 2 ) != 2 ) {
F_3 ( L_8 ) ;
goto error;
}
V_95 = F_4 ( V_2 , 0x3e ) ;
if ( V_95 != 0 ) {
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
memcpy ( & V_2 -> V_97 . V_39 , & V_98 , sizeof( struct V_99 ) ) ;
V_2 -> V_97 . V_25 = V_2 ;
return & V_2 -> V_97 ;
error:
if ( V_95 >= 0 )
F_1 ( V_2 , 0x3e , V_95 ) ;
F_21 ( V_2 ) ;
return NULL ;
}
