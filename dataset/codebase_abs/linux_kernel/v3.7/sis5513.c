static T_1 F_1 ( T_2 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_3 ) ;
T_3 V_5 = 0 ;
F_3 ( V_3 , 0x54 , & V_5 ) ;
return ( ( V_5 & 0x40000000 ) ? 0x70 : 0x40 ) + V_1 -> V_6 * 4 ;
}
static void F_4 ( T_2 * V_1 , const T_1 V_7 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_3 ) ;
T_4 V_8 = 0 ;
T_1 V_9 = 0x40 + V_1 -> V_6 * 2 ;
const T_4 V_10 [] = { 0x000 , 0x607 , 0x404 , 0x303 , 0x301 } ;
const T_4 V_11 [] = { 0x008 , 0x302 , 0x301 } ;
F_5 ( V_3 , V_9 , & V_8 ) ;
V_8 &= ~ 0x070f ;
if ( V_7 >= V_12 ) {
if ( V_13 > V_14 )
V_8 &= ~ 0x8000 ;
V_8 |= V_11 [ V_7 - V_12 ] ;
} else
V_8 |= V_10 [ V_7 - V_15 ] ;
F_6 ( V_3 , V_9 , V_8 ) ;
}
static void F_7 ( T_2 * V_1 , const T_1 V_7 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_3 ) ;
T_1 V_8 , V_9 = 0x40 + V_1 -> V_6 * 2 ;
const T_1 V_10 [] = { 0x00 , 0x67 , 0x44 , 0x33 , 0x31 } ;
const T_1 V_11 [] = { 0x08 , 0x32 , 0x31 } ;
if ( V_7 >= V_12 ) {
T_1 V_16 = 0 ;
F_8 ( V_3 , V_9 , & V_16 ) ;
V_16 &= ~ 0x80 ;
F_9 ( V_3 , V_9 , V_16 ) ;
V_8 = V_11 [ V_7 - V_12 ] ;
} else
V_8 = V_10 [ V_7 - V_15 ] ;
F_9 ( V_3 , V_9 + 1 , V_8 ) ;
}
static void F_10 ( T_2 * V_1 , const T_1 V_7 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_3 ) ;
T_3 V_8 = 0 ;
T_1 V_9 = F_1 ( V_1 ) , V_17 , V_18 ;
F_3 ( V_3 , V_9 , & V_8 ) ;
V_8 &= 0xc0c00fff ;
V_17 = ( V_8 & 0x08 ) ? V_19 : V_20 ;
if ( V_7 >= V_12 ) {
V_8 &= ~ 0x04 ;
V_18 = V_7 - V_12 + 5 ;
} else
V_18 = V_7 - V_15 ;
V_8 |= V_21 [ V_17 ] [ V_18 ] << 12 ;
V_8 |= V_22 [ V_17 ] [ V_18 ] << 16 ;
V_8 |= V_23 [ V_17 ] [ V_18 ] << 24 ;
F_11 ( V_3 , V_9 , V_8 ) ;
}
static void F_12 ( T_2 * V_1 , const T_1 V_7 )
{
if ( V_13 < V_20 )
F_4 ( V_1 , V_7 ) ;
else if ( V_13 < V_19 )
F_7 ( V_1 , V_7 ) ;
else
F_10 ( V_1 , V_7 ) ;
}
static void F_13 ( T_2 * V_1 )
{
T_5 * V_4 = V_1 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_4 -> V_3 ) ;
T_1 V_24 = 0 ;
T_1 V_25 = 0 ;
F_8 ( V_3 , 0x4b , & V_24 ) ;
V_25 = V_24 & ~ ( 0x11 << V_1 -> V_6 ) ;
if ( V_1 -> V_26 == V_27 )
V_25 |= 0x11 << V_1 -> V_6 ;
if ( V_24 != V_25 )
F_9 ( V_3 , 0x4b , V_25 ) ;
}
static void F_14 ( T_5 * V_4 , T_2 * V_1 )
{
F_13 ( V_1 ) ;
F_12 ( V_1 , V_1 -> V_28 ) ;
}
static void F_15 ( T_2 * V_1 , const T_1 V_7 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_3 ) ;
T_3 V_29 = 0 ;
T_1 V_9 = F_1 ( V_1 ) , V_17 , V_18 ;
F_3 ( V_3 , V_9 , & V_29 ) ;
V_29 |= 0x04 ;
V_29 &= 0xfffff00f ;
V_17 = ( V_29 & 0x08 ) ? V_19 : V_20 ;
V_18 = V_7 - V_30 ;
V_29 |= V_31 [ V_17 ] [ V_18 ] << 4 ;
V_29 |= V_32 [ V_17 ] [ V_18 ] << 8 ;
F_11 ( V_3 , V_9 , V_29 ) ;
}
static void F_16 ( T_2 * V_1 , const T_1 V_7 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_3 ) ;
T_1 V_9 = 0x40 + V_1 -> V_6 * 2 , V_33 = 0 , V_34 = V_13 ;
F_8 ( V_3 , V_9 + 1 , & V_33 ) ;
V_33 |= 0x80 ;
V_33 &= ~ ( ( 0xff >> ( 8 - V_35 [ V_34 ] ) ) << V_36 [ V_34 ] ) ;
V_33 |= V_31 [ V_34 ] [ V_7 - V_30 ] << V_36 [ V_34 ] ;
F_9 ( V_3 , V_9 + 1 , V_33 ) ;
}
static void F_17 ( T_2 * V_1 , const T_1 V_7 )
{
if ( V_13 >= V_19 )
F_15 ( V_1 , V_7 ) ;
else
F_16 ( V_1 , V_7 ) ;
}
static void F_18 ( T_5 * V_4 , T_2 * V_1 )
{
const T_1 V_37 = V_1 -> V_38 ;
if ( V_37 >= V_30 )
F_17 ( V_1 , V_37 ) ;
else
F_12 ( V_1 , V_37 ) ;
}
static T_1 F_19 ( T_2 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_3 ) ;
T_3 V_29 = 0 ;
T_1 V_9 = F_1 ( V_1 ) ;
F_3 ( V_3 , V_9 , & V_29 ) ;
return ( V_29 & 0x08 ) ? V_39 : V_40 ;
}
static int T_6 F_20 ( struct V_2 * V_3 )
{
struct V_2 * V_41 ;
int V_34 = 0 ;
V_13 = 0 ;
for ( V_34 = 0 ; V_34 < F_21 ( V_42 ) && ! V_13 ; V_34 ++ ) {
V_41 = F_22 ( V_43 , V_42 [ V_34 ] . V_44 , NULL ) ;
if ( ! V_41 )
continue;
V_13 = V_42 [ V_34 ] . V_13 ;
if ( V_42 [ V_34 ] . V_44 == V_45 ) {
if ( V_41 -> V_46 >= 0x30 )
V_13 = V_47 ;
}
F_23 ( V_41 ) ;
F_24 (KERN_INFO DRV_NAME L_1 ,
pci_name(dev), SiSHostChipInfo[i].name,
chipset_capability[chipset_family]) ;
}
if ( ! V_13 ) {
T_3 V_48 ;
T_4 V_49 ;
F_3 ( V_3 , 0x54 , & V_48 ) ;
F_11 ( V_3 , 0x54 , ( V_48 & 0x7fffffff ) ) ;
F_5 ( V_3 , V_50 , & V_49 ) ;
F_11 ( V_3 , 0x54 , V_48 ) ;
if ( V_49 == 0x5518 ) {
F_24 (KERN_INFO DRV_NAME L_2 ,
pci_name(dev)) ;
V_13 = V_19 ;
if ( ( V_48 & 0x40000000 ) == 0 ) {
F_11 ( V_3 , 0x54 , V_48 | 0x40000000 ) ;
F_24 (KERN_INFO DRV_NAME L_3 ,
pci_name(dev)) ;
}
}
}
if ( ! V_13 ) {
struct V_2 * V_51 ;
T_4 V_49 ;
T_1 V_52 ;
T_1 V_53 ;
F_8 ( V_3 , 0x4a , & V_53 ) ;
F_9 ( V_3 , 0x4a , V_53 | 0x10 ) ;
F_5 ( V_3 , V_50 , & V_49 ) ;
F_9 ( V_3 , 0x4a , V_53 ) ;
if ( V_49 == 0x5517 ) {
V_51 = F_25 ( V_3 -> V_54 , 0x10 ) ;
F_8 ( V_3 , 0x49 , & V_52 ) ;
F_23 ( V_51 ) ;
if ( V_51 -> V_46 == 0x10 && ( V_52 & 0x80 ) ) {
F_24 (KERN_INFO DRV_NAME L_4 ,
pci_name(dev)) ;
V_13 = V_55 ;
} else {
F_24 (KERN_INFO DRV_NAME L_5 ,
pci_name(dev)) ;
V_13 = V_20 ;
}
}
}
return V_13 ;
}
static int F_26 ( struct V_2 * V_3 )
{
T_1 V_33 ;
T_4 V_56 ;
switch ( V_13 ) {
case V_19 :
F_5 ( V_3 , 0x50 , & V_56 ) ;
if ( V_56 & 0x08 )
F_6 ( V_3 , 0x50 , V_56 & 0xfff7 ) ;
F_5 ( V_3 , 0x52 , & V_56 ) ;
if ( V_56 & 0x08 )
F_6 ( V_3 , 0x52 , V_56 & 0xfff7 ) ;
break;
case V_55 :
case V_20 :
F_9 ( V_3 , V_57 , 0x80 ) ;
F_8 ( V_3 , 0x49 , & V_33 ) ;
if ( ! ( V_33 & 0x01 ) )
F_9 ( V_3 , 0x49 , V_33 | 0x01 ) ;
break;
case V_47 :
case V_58 :
F_9 ( V_3 , V_57 , 0x10 ) ;
F_8 ( V_3 , 0x52 , & V_33 ) ;
if ( ! ( V_33 & 0x04 ) )
F_9 ( V_3 , 0x52 , V_33 | 0x04 ) ;
break;
case V_59 :
F_8 ( V_3 , 0x09 , & V_33 ) ;
if ( ( V_33 & 0x0f ) != 0x00 )
F_9 ( V_3 , 0x09 , V_33 & 0xf0 ) ;
case V_14 :
F_8 ( V_3 , 0x52 , & V_33 ) ;
if ( ! ( V_33 & 0x08 ) )
F_9 ( V_3 , 0x52 , V_33 | 0x08 ) ;
break;
}
return 0 ;
}
static T_1 F_27 ( T_5 * V_4 )
{
struct V_2 * V_60 = F_2 ( V_4 -> V_3 ) ;
const struct V_61 * V_62 = & V_61 [ 0 ] ;
T_1 V_63 = 0 ;
while ( V_62 -> V_64 ) {
if ( V_62 -> V_64 == V_60 -> V_64 &&
V_62 -> V_65 == V_60 -> V_66 &&
V_62 -> V_67 == V_60 -> V_68 )
return V_69 ;
V_62 ++ ;
}
if ( V_13 >= V_19 ) {
T_4 V_56 = 0 ;
T_4 V_70 = V_4 -> V_71 ? 0x52 : 0x50 ;
F_5 ( V_60 , V_70 , & V_56 ) ;
V_63 = ( V_56 & 0x8000 ) ? 0 : 1 ;
} else if ( V_13 >= V_58 ) {
T_1 V_72 = 0 ;
T_1 V_73 = V_4 -> V_71 ? 0x20 : 0x10 ;
F_8 ( V_60 , 0x48 , & V_72 ) ;
V_63 = ( V_72 & V_73 ) ? 0 : 1 ;
}
return V_63 ? V_74 : V_75 ;
}
static int T_6 F_28 ( struct V_2 * V_3 , const struct V_76 * V_77 )
{
struct V_78 V_79 = V_80 ;
T_1 V_81 [] = { 0x00 , 0x00 , 0x07 , 0x1f , 0x3f , 0x3f , 0x7f , 0x7f } ;
int V_82 ;
V_82 = F_29 ( V_3 ) ;
if ( V_82 )
return V_82 ;
if ( F_20 ( V_3 ) == 0 )
return - V_83 ;
if ( V_13 >= V_19 )
V_79 . V_84 = & V_85 ;
else
V_79 . V_84 = & V_86 ;
V_79 . V_87 = V_81 [ V_13 ] ;
return F_30 ( V_3 , & V_79 , NULL ) ;
}
static void T_7 F_31 ( struct V_2 * V_3 )
{
F_32 ( V_3 ) ;
F_33 ( V_3 ) ;
}
static int T_8 F_34 ( void )
{
return F_35 ( & V_88 ) ;
}
static void T_9 F_36 ( void )
{
F_37 ( & V_88 ) ;
}
