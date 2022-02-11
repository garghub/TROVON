static int F_1 ( T_1 * V_1 , const char * * V_2 )
{
char * V_3 = ( char * ) & V_1 -> V_4 [ V_5 ] ;
while ( * V_2 )
if ( ! strcmp ( * V_2 ++ , V_3 ) )
return 1 ;
return 0 ;
}
static T_2 F_2 ( T_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 -> V_8 -> V_7 ) ;
if ( V_7 -> V_9 == V_10 ) {
return 0x1f ;
} else if ( V_7 -> V_11 < V_12 ) {
return 0x07 ;
} else {
T_2 V_13 = 0 , V_14 , V_15 ;
F_4 ( V_7 , 0x5A , & V_13 ) ;
V_14 = V_13 & 0x3 ;
if ( V_14 > 2 && F_1 ( V_1 , V_16 ) )
V_14 = 2 ;
switch( V_14 ) {
case 3 : V_15 = 0x3f ; break;
case 2 : V_15 = 0x1f ; break;
case 1 : V_15 = 0x07 ; break;
default: V_15 = 0x00 ; break;
}
return V_15 ;
}
}
static T_2 F_5 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_9 ) {
case V_17 :
case V_18 :
case V_19 :
case V_10 :
return 1 ;
default:
break;
}
return 0 ;
}
static void F_6 ( T_3 * V_8 , T_1 * V_1 )
{
static const T_2 V_20 [] = { 0x5d , 0x47 , 0x34 , 0x22 , 0x20 } ;
static const T_2 V_21 [] = { 0x41 , 0x40 , 0x43 , 0x42 } ;
struct V_6 * V_7 = F_3 ( V_8 -> V_7 ) ;
const T_2 V_22 = V_1 -> V_23 - V_24 ;
F_7 ( V_7 , V_21 [ V_1 -> V_25 ] , V_20 [ V_22 ] ) ;
if ( F_5 ( V_7 ) ) {
T_4 V_26 = 0 ;
F_8 ( V_7 , 0x4a , & V_26 ) ;
V_26 &= ~ ( 0x0f << ( 4 * V_1 -> V_25 ) ) ;
V_26 |= ( V_22 << ( 4 * V_1 -> V_25 ) ) ;
F_9 ( V_7 , 0x4a , V_26 ) ;
}
}
static void F_10 ( T_3 * V_8 , T_1 * V_1 )
{
static const T_2 V_27 [] = { 0x00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 } ;
static const T_2 V_28 [] = { 0x77 , 0x21 , 0x20 } ;
static const T_2 V_29 [] = { 0x45 , 0x44 , 0x47 , 0x46 } ;
struct V_6 * V_7 = F_3 ( V_8 -> V_7 ) ;
const T_2 V_30 = V_1 -> V_31 ;
T_2 V_32 = V_1 -> V_25 & 1 ;
T_2 V_33 = 0 , V_34 = 0 , V_35 = 0 ;
F_4 ( V_7 , ( 0x56 | V_8 -> V_36 ) , & V_34 ) ;
F_4 ( V_7 , 0x54 , & V_33 ) ;
V_34 &= ~ ( 0x0F << ( 4 * V_32 ) ) ;
V_33 &= ~ ( 0x01 << V_1 -> V_25 ) ;
if ( V_30 >= V_37 ) {
V_35 |= V_28 [ 2 ] ;
V_34 |= ( V_27 [ V_30 - V_37 ] << ( 4 * V_32 ) ) ;
V_33 |= ( 0x01 << V_1 -> V_25 ) ;
} else if ( V_30 >= V_38 )
V_35 |= V_28 [ V_30 - V_38 ] ;
F_7 ( V_7 , V_29 [ V_1 -> V_25 ] , V_35 ) ;
F_7 ( V_7 , ( 0x56 | V_8 -> V_36 ) , V_34 ) ;
F_7 ( V_7 , 0x54 , V_33 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
unsigned int V_39 ;
T_2 V_13 ;
F_7 ( V_7 , V_40 , 0x40 ) ;
if ( V_7 -> V_9 == V_41 ) {
struct V_6 * V_42 =
F_12 ( V_43 ,
V_44 , NULL ) ;
if ( V_42 ) {
F_13 ( V_42 , 0x64 , & V_39 ) ;
V_39 &= ~ 0x00002000 ;
if( ! ( V_39 & 0x00004000 ) )
F_14 (KERN_DEBUG DRV_NAME L_1
L_2 , pci_name(dev)) ;
V_39 |= 0x00004000 ;
F_15 ( V_42 , 0x64 , V_39 ) ;
F_16 ( V_42 ) ;
}
}
else if ( ( V_7 -> V_9 == V_17 ) ||
( V_7 -> V_9 == V_18 ) ||
( V_7 -> V_9 == V_19 ) ) {
if ( ! ( F_17 ( V_7 -> V_45 ) & 1 ) ) {
struct V_6 * V_46 = NULL ;
T_5 V_47 = 0 ;
V_46 = F_12 ( V_43 ,
V_48 , NULL ) ;
if ( V_46 ) {
F_13 ( V_46 , 0x4C , & V_47 ) ;
V_47 &= ~ 0x000007FF ;
V_47 |= 0x00000040 ;
V_47 |= 0x00000020 ;
F_15 ( V_46 , 0x4C , V_47 ) ;
F_16 ( V_46 ) ;
}
F_18 ( 0x06 , 0x0c00 ) ;
V_7 -> V_49 = F_19 ( 0x0c01 ) ;
} else {
struct V_6 * V_46 = NULL ;
T_2 V_50 = 0 ;
V_46 = F_12 ( V_43 ,
V_51 , NULL ) ;
if ( V_46 ) {
F_4 ( V_46 , 0x41 , & V_50 ) ;
V_50 &= ~ 0x40 ;
F_7 ( V_46 , 0x41 , V_50 ) ;
F_16 ( V_46 ) ;
}
if ( ( V_7 -> V_52 >> 8 ) == V_53 )
V_7 -> V_49 = 0 ;
}
F_4 ( V_7 , 0x5A , & V_13 ) ;
V_13 &= ~ 0x40 ;
if ( ! ( F_17 ( V_7 -> V_45 ) & 1 ) )
V_13 |= 0x2 ;
else
V_13 |= ( V_7 -> V_11 >= V_12 ) ? 0x3 : 0x2 ;
F_7 ( V_7 , 0x5A , V_13 ) ;
}
else if ( V_7 -> V_9 == V_10 ) {
F_4 ( V_7 , 0x5A , & V_13 ) ;
V_13 &= ~ 0x40 ;
V_13 |= 0x3 ;
F_7 ( V_7 , 0x5A , V_13 ) ;
}
return 0 ;
}
static T_2 F_20 ( T_3 * V_8 )
{
return V_54 ;
}
static T_2 F_21 ( T_3 * V_8 )
{
struct V_6 * V_7 = F_3 ( V_8 -> V_7 ) ;
if ( V_7 -> V_55 == V_56 &&
V_7 -> V_57 == V_43 &&
( V_7 -> V_9 == V_17 ||
V_7 -> V_9 == V_18 ) )
return ( ( 1 << ( V_8 -> V_36 + 14 ) ) &
V_7 -> V_58 ) ? V_54 : V_59 ;
return V_59 ;
}
static T_2 F_22 ( T_3 * V_8 )
{
struct V_6 * V_7 = F_3 ( V_8 -> V_7 ) ;
if ( V_7 -> V_55 == V_60 &&
V_7 -> V_57 == V_43 &&
V_7 -> V_9 == V_17 )
return ( ( 1 << ( V_8 -> V_36 + 14 ) ) &
V_7 -> V_58 ) ? V_54 : V_59 ;
return V_59 ;
}
static T_2 F_23 ( T_3 * V_8 )
{
struct V_6 * V_7 = F_3 ( V_8 -> V_7 ) ;
if ( V_7 -> V_55 == V_43 )
return F_20 ( V_8 ) ;
if ( V_7 -> V_55 == V_56 )
return F_21 ( V_8 ) ;
if ( V_7 -> V_55 == V_60 )
return F_22 ( V_8 ) ;
if ( ( V_7 -> V_9 == V_18 ) ||
( V_7 -> V_9 == V_19 ) )
return V_54 ;
return V_59 ;
}
static int F_24 ( struct V_6 * V_7 , const struct V_61 * V_4 )
{
struct V_62 V_63 ;
T_2 V_64 = V_4 -> V_65 ;
V_63 = V_66 [ V_64 ] ;
if ( V_64 == 1 )
V_63 . V_67 |= V_68 ;
else if ( V_64 == 2 || V_64 == 3 ) {
if ( ( F_17 ( V_7 -> V_45 ) & 1 ) == 0 ) {
if ( F_25 ( V_7 , 0 ) != 0x01f1 )
V_63 . V_67 |= V_69 ;
V_63 . V_67 |= V_70 ;
} else
V_63 . V_67 &= ~ V_70 ;
}
return F_26 ( V_7 , & V_63 , NULL ) ;
}
static int T_6 F_27 ( void )
{
return F_28 ( & V_71 ) ;
}
static void T_7 F_29 ( void )
{
F_30 ( & V_71 ) ;
}
