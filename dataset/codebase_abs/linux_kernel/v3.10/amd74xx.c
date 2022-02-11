static inline T_1 F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_4 ) ? 0x10 : 0 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_6 ,
struct V_7 * V_8 )
{
T_1 V_9 = 0 , V_10 = F_1 ( V_2 ) ;
F_3 ( V_2 , V_11 + V_10 , & V_9 ) ;
V_9 = ( V_9 & ~ ( 3 << ( ( 3 - V_5 ) << 1 ) ) ) | ( ( F_4 ( V_8 -> V_12 , 1 , 4 ) - 1 ) << ( ( 3 - V_5 ) << 1 ) ) ;
F_5 ( V_2 , V_11 + V_10 , V_9 ) ;
F_5 ( V_2 , V_13 + V_10 + ( 1 - ( V_5 >> 1 ) ) ,
( ( F_4 ( V_8 -> V_14 , 1 , 16 ) - 1 ) << 4 ) | ( F_4 ( V_8 -> V_15 , 1 , 16 ) - 1 ) ) ;
F_5 ( V_2 , V_16 + V_10 + ( 3 - V_5 ) ,
( ( F_4 ( V_8 -> V_17 , 1 , 16 ) - 1 ) << 4 ) | ( F_4 ( V_8 -> V_18 , 1 , 16 ) - 1 ) ) ;
switch ( V_6 ) {
case V_19 : V_9 = V_8 -> V_20 ? ( 0xc0 | ( F_4 ( V_8 -> V_20 , 2 , 5 ) - 2 ) ) : 0x03 ; break;
case V_21 : V_9 = V_8 -> V_20 ? ( 0xc0 | V_22 [ F_4 ( V_8 -> V_20 , 2 , 10 ) ] ) : 0x03 ; break;
case V_23 : V_9 = V_8 -> V_20 ? ( 0xc0 | V_22 [ F_4 ( V_8 -> V_20 , 1 , 10 ) ] ) : 0x03 ; break;
case V_24 : V_9 = V_8 -> V_20 ? ( 0xc0 | V_22 [ F_4 ( V_8 -> V_20 , 1 , 15 ) ] ) : 0x03 ; break;
default: return;
}
if ( V_8 -> V_20 )
F_5 ( V_2 , V_25 + V_10 + 3 - V_5 , V_9 ) ;
}
static void F_6 ( T_2 * V_26 , T_3 * V_27 )
{
struct V_1 * V_2 = F_7 ( V_26 -> V_2 ) ;
T_3 * V_28 = F_8 ( V_27 ) ;
struct V_7 V_9 , V_29 ;
int V_30 , V_31 ;
T_1 V_6 = V_26 -> V_32 ;
const T_1 V_33 = V_27 -> V_34 ;
V_30 = 1000000000 / V_35 ;
V_31 = ( V_6 == V_19 ) ? V_30 : ( V_30 / 2 ) ;
F_9 ( V_27 , V_33 , & V_9 , V_30 , V_31 ) ;
if ( V_28 ) {
F_9 ( V_28 , V_28 -> V_36 , & V_29 , V_30 , V_31 ) ;
F_10 ( & V_29 , & V_9 , & V_9 , V_37 ) ;
}
if ( V_33 == V_38 && V_35 <= 33333 ) V_9 . V_20 = 1 ;
if ( V_33 == V_39 && V_35 <= 33333 ) V_9 . V_20 = 15 ;
F_2 ( V_2 , V_27 -> V_5 , V_6 , & V_9 ) ;
}
static void F_11 ( T_2 * V_26 , T_3 * V_27 )
{
V_27 -> V_34 = V_27 -> V_36 ;
F_6 ( V_26 , V_27 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
V_40 = 0x03 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_41 ;
T_4 V_42 = 0 ;
T_1 V_9 = 0 , V_10 = F_1 ( V_2 ) ;
F_3 ( V_2 , V_43 + V_10 , & V_9 ) ;
F_14 ( V_2 , V_25 + V_10 , & V_42 ) ;
V_40 = ( ( V_9 & 0x3 ) ? 1 : 0 ) | ( ( V_9 & 0xc ) ? 2 : 0 ) ;
for ( V_41 = 24 ; V_41 >= 0 ; V_41 -= 8 )
if ( ( ( V_42 >> V_41 ) & 4 ) && ! ( V_40 & ( 1 << ( 1 - ( V_41 >> 4 ) ) ) ) ) {
F_15 (KERN_WARNING DRV_NAME L_1
L_2 ,
pci_name(dev)) ;
V_40 |= ( 1 << ( 1 - ( V_41 >> 4 ) ) ) ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_9 = 0 , V_10 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 == V_44 &&
V_2 -> V_45 == V_46 )
;
else if ( V_2 -> V_3 == V_44 &&
V_2 -> V_45 == V_47 )
F_12 ( V_2 ) ;
else
F_13 ( V_2 ) ;
F_3 ( V_2 , V_48 + V_10 , & V_9 ) ;
if ( V_2 -> V_3 == V_44 &&
V_2 -> V_45 == V_49 )
V_9 &= 0x0f ;
else
V_9 |= 0xf0 ;
F_5 ( V_2 , V_48 + V_10 , V_9 ) ;
return 0 ;
}
static T_1 F_17 ( T_2 * V_26 )
{
if ( ( V_40 >> V_26 -> V_50 ) & 1 )
return V_51 ;
else
return V_52 ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_53 * V_54 )
{
struct V_55 V_56 ;
T_1 V_57 = V_54 -> V_58 ;
V_56 = V_59 [ V_57 ] ;
if ( V_57 == 1 ) {
if ( V_2 -> V_60 <= 7 )
V_56 . V_61 = 0 ;
V_56 . V_62 |= V_63 ;
} else if ( V_57 == 3 ) {
if ( V_2 -> V_64 == V_44 &&
V_2 -> V_65 == V_66 )
V_56 . V_6 = V_23 ;
}
if ( V_2 -> V_3 == V_4 &&
F_19 ( V_2 ) )
V_56 . V_62 |= V_67 ;
F_15 ( V_68 L_3 ,
V_56 . V_69 , F_20 ( V_2 ) , V_70 [ F_21 ( V_56 . V_6 ) - 1 ] ) ;
V_35 = ( V_71 ? V_71 : 33 ) * 1000 ;
switch ( V_35 ) {
case 33000 : V_35 = 33333 ; break;
case 37000 : V_35 = 37500 ; break;
case 41000 : V_35 = 41666 ; break;
}
if ( V_35 < 20000 || V_35 > 50000 ) {
F_15 ( V_72 L_4
L_5 ,
V_56 . V_69 , V_35 ) ;
V_35 = 33333 ;
}
return F_22 ( V_2 , & V_56 , NULL ) ;
}
static int T_5 F_23 ( void )
{
return F_24 ( & V_73 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_73 ) ;
}
