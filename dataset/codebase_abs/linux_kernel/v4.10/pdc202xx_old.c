static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
T_3 V_5 = 0x60 + ( V_2 -> V_6 << 2 ) ;
const T_3 V_7 = V_2 -> V_8 ;
T_3 V_9 = 0 , V_10 = 0 , V_11 = 0 ;
T_3 V_12 = 0 , V_13 = 0 , V_14 = 0 ;
F_3 ( V_4 , V_5 , & V_9 ) ;
F_3 ( V_4 , V_5 + 1 , & V_10 ) ;
F_3 ( V_4 , V_5 + 2 , & V_11 ) ;
switch( V_7 ) {
case V_15 :
case V_16 : V_13 = 0x20 ; V_14 = 0x01 ; break;
case V_17 : V_13 = 0x20 ; V_14 = 0x01 ; break;
case V_18 :
case V_19 : V_13 = 0x40 ; V_14 = 0x02 ; break;
case V_20 :
case V_21 : V_13 = 0x60 ; V_14 = 0x03 ; break;
case V_22 : V_13 = 0x60 ; V_14 = 0x04 ; break;
case V_23 : V_13 = 0xE0 ; V_14 = 0x0F ; break;
case V_24 : V_12 = 0x01 ; V_13 = 0x04 ; break;
case V_25 : V_12 = 0x02 ; V_13 = 0x06 ; break;
case V_26 : V_12 = 0x03 ; V_13 = 0x08 ; break;
case V_27 : V_12 = 0x05 ; V_13 = 0x0C ; break;
case V_28 :
default: V_12 = 0x09 ; V_13 = 0x13 ; break;
}
if ( V_7 < V_29 ) {
V_9 &= ~ 0x3f ;
if ( F_4 ( V_2 , V_7 - V_28 ) )
V_9 |= 0x20 ;
if ( V_2 -> V_30 == V_31 )
V_9 |= 0x10 ;
V_10 &= ~ 0x1f ;
F_5 ( V_4 , V_5 , V_9 | V_12 ) ;
F_5 ( V_4 , V_5 + 1 , V_10 | V_13 ) ;
} else {
V_10 &= ~ 0xe0 ;
V_11 &= ~ 0x0f ;
F_5 ( V_4 , V_5 + 1 , V_10 | V_13 ) ;
F_5 ( V_4 , V_5 + 2 , V_11 | V_14 ) ;
}
}
static void F_6 ( T_1 * V_1 , T_2 * V_2 )
{
V_2 -> V_8 = V_2 -> V_32 ;
F_1 ( V_1 , V_2 ) ;
}
static int F_7 ( T_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
unsigned long V_33 = F_8 ( V_4 , 4 ) ;
T_3 V_34 = F_9 ( V_33 + 0x1d ) ;
if ( V_1 -> V_35 ) {
return ( V_34 & 0x40 ) ? 1 : 0 ;
} else {
return ( V_34 & 0x04 ) ? 1 : 0 ;
}
}
static T_3 F_10 ( T_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_4 ) ;
T_4 V_36 , V_37 = V_1 -> V_35 ? ( 1 << 11 ) : ( 1 << 10 ) ;
F_11 ( V_4 , 0x50 , & V_36 ) ;
return ( V_36 & V_37 ) ? V_38 : V_39 ;
}
static void F_12 ( T_1 * V_1 )
{
unsigned long V_40 = V_1 -> V_41 + 0x01 ;
T_3 clock = F_9 ( V_40 ) ;
F_13 ( clock | ( V_1 -> V_35 ? 0x08 : 0x02 ) , V_40 ) ;
}
static void F_14 ( T_1 * V_1 )
{
unsigned long V_40 = V_1 -> V_41 + 0x01 ;
T_3 clock = F_9 ( V_40 ) ;
F_13 ( clock & ~ ( V_1 -> V_35 ? 0x08 : 0x02 ) , V_40 ) ;
}
static void F_15 ( T_1 * V_1 )
{
F_14 ( V_1 ) ;
}
static void F_16 ( T_2 * V_2 )
{
if ( V_2 -> V_42 > V_17 )
F_12 ( V_2 -> V_1 ) ;
if ( V_2 -> V_30 != V_31 || ( V_2 -> V_43 & V_44 ) ) {
T_1 * V_1 = V_2 -> V_1 ;
struct V_45 * V_46 = V_1 -> V_46 ;
unsigned long V_33 = V_1 -> V_41 - 16 ;
unsigned long V_47 = V_33 + ( V_1 -> V_35 ? 0x24 : 0x20 ) ;
T_5 V_48 = 0 ;
T_3 clock = F_9 ( V_33 + 0x11 ) ;
F_13 ( clock | ( V_1 -> V_35 ? 0x08 : 0x02 ) , V_33 + 0x11 ) ;
V_48 = ( F_17 ( V_46 ) << 8 ) ;
V_48 = ( F_18 ( V_46 ) == V_49 ) ?
V_48 | 0x05000000 :
V_48 | 0x06000000 ;
F_19 ( V_48 , V_47 ) ;
}
F_20 ( V_2 ) ;
}
static int F_21 ( T_2 * V_2 )
{
if ( V_2 -> V_30 != V_31 || ( V_2 -> V_43 & V_44 ) ) {
T_1 * V_1 = V_2 -> V_1 ;
unsigned long V_33 = V_1 -> V_41 - 16 ;
unsigned long V_47 = V_33 + ( V_1 -> V_35 ? 0x24 : 0x20 ) ;
T_3 clock = 0 ;
F_19 ( 0 , V_47 ) ;
clock = F_9 ( V_33 + 0x11 ) ;
F_13 ( clock & ~ ( V_1 -> V_35 ? 0x08 : 0x02 ) , V_33 + 0x11 ) ;
}
if ( V_2 -> V_42 > V_17 )
F_14 ( V_2 -> V_1 ) ;
return F_22 ( V_2 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
unsigned long V_50 = F_8 ( V_4 , 4 ) ;
T_3 V_51 = 0 , V_52 = 0 , V_53 = 0 ;
if ( V_50 == 0 )
goto V_54;
V_51 = F_9 ( V_50 | 0x1f ) ;
V_52 = F_9 ( V_50 | 0x1a ) ;
V_53 = F_9 ( V_50 | 0x1b ) ;
F_24 ( V_55 L_1 \
L_2 \
L_3 , F_25 ( V_4 ) ,
( V_51 & 1 ) ? L_4 : L_5 ,
( V_52 & 1 ) ? L_6 : L_7 ,
( V_53 & 1 ) ? L_6 : L_7 ) ;
if ( ! ( V_51 & 1 ) ) {
F_24 ( V_55 L_8 ,
F_25 ( V_4 ) , V_51 ,
( V_51 | 1 ) ) ;
F_13 ( V_51 | 1 , V_50 | 0x1f ) ;
F_24 ( L_9 , ( F_9 ( V_50 | 0x1f ) & 1 ) ? L_10 : L_11 ) ;
}
V_54:
return 0 ;
}
static void F_26 ( struct V_3 * V_4 , const char * V_56 )
{
if ( ( V_4 -> V_57 >> 8 ) != V_58 ) {
T_3 V_59 = 0 , V_60 = 0 ;
F_3 ( V_4 , V_61 , & V_59 ) ;
F_3 ( V_4 , ( V_61 ) | 0x80 , & V_60 ) ;
if ( V_59 != V_60 ) {
F_5 ( V_4 ,
( V_61 ) | 0x80 , V_59 ) ;
F_24 ( V_55 L_12
L_13 , V_56 , F_25 ( V_4 ) ) ;
}
}
}
static int F_27 ( struct V_3 * V_4 ,
const struct V_62 * V_63 )
{
const struct V_64 * V_65 ;
T_3 V_66 = V_63 -> V_67 ;
V_65 = & V_68 [ V_66 ] ;
if ( V_66 < 2 )
F_26 ( V_4 , V_65 -> V_56 ) ;
if ( V_4 -> V_69 == V_70 ) {
struct V_3 * V_71 = V_4 -> V_72 -> V_73 ;
if ( V_71 &&
V_71 -> V_69 == V_74 &&
( V_71 -> V_75 == V_76 ||
V_71 -> V_75 == V_77 ) ) {
F_24 (KERN_INFO DRV_NAME L_14
L_15 ,
pci_name(dev)) ;
return - V_78 ;
}
}
return F_28 ( V_4 , V_65 , NULL ) ;
}
static int T_6 F_29 ( void )
{
return F_30 ( & V_79 ) ;
}
static void T_7 F_31 ( void )
{
F_32 ( & V_79 ) ;
}
