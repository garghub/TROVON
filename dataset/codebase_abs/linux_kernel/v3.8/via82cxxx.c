static void F_1 ( T_1 * V_1 , T_2 V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_2 V_12 ;
if ( ~ V_10 -> V_13 -> V_14 & V_15 ) {
F_4 ( V_6 , V_16 , & V_12 ) ;
V_12 = ( V_12 & ~ ( 3 << ( ( 3 - V_2 ) << 1 ) ) ) | ( ( F_5 ( V_4 -> V_17 , 1 , 4 ) - 1 ) << ( ( 3 - V_2 ) << 1 ) ) ;
F_6 ( V_6 , V_16 , V_12 ) ;
}
F_6 ( V_6 , V_18 + ( 1 - ( V_2 >> 1 ) ) ,
( ( F_5 ( V_4 -> V_19 , 1 , 16 ) - 1 ) << 4 ) | ( F_5 ( V_4 -> V_20 , 1 , 16 ) - 1 ) ) ;
F_6 ( V_6 , V_21 + ( 3 - V_2 ) ,
( ( F_5 ( V_4 -> V_22 , 1 , 16 ) - 1 ) << 4 ) | ( F_5 ( V_4 -> V_23 , 1 , 16 ) - 1 ) ) ;
switch ( V_10 -> V_13 -> V_24 ) {
case V_25 : V_12 = V_4 -> V_26 ? ( 0xe0 | ( F_5 ( V_4 -> V_26 , 2 , 5 ) - 2 ) ) : 0x03 ; break;
case V_27 : V_12 = V_4 -> V_26 ? ( 0xe8 | ( F_5 ( V_4 -> V_26 , 2 , 9 ) - 2 ) ) : 0x0f ; break;
case V_28 : V_12 = V_4 -> V_26 ? ( 0xe0 | ( F_5 ( V_4 -> V_26 , 2 , 9 ) - 2 ) ) : 0x07 ; break;
case V_29 : V_12 = V_4 -> V_26 ? ( 0xe0 | ( F_5 ( V_4 -> V_26 , 2 , 9 ) - 2 ) ) : 0x07 ; break;
}
if ( V_10 -> V_13 -> V_24 ) {
T_2 V_30 ;
F_4 ( V_6 , V_31 + 3 - V_2 , & V_30 ) ;
V_30 &= ~ 0x20 ;
if ( V_4 -> V_26 ) {
V_30 &= 0x10 ;
V_30 |= V_12 ;
}
F_6 ( V_6 , V_31 + 3 - V_2 , V_30 ) ;
}
}
static void F_7 ( T_1 * V_1 , T_3 * V_32 )
{
T_3 * V_33 = F_8 ( V_32 ) ;
struct V_5 * V_6 = F_2 ( V_1 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_3 V_12 , V_34 ;
unsigned int V_35 , V_36 ;
const T_2 V_37 = V_32 -> V_38 ;
V_35 = 1000000000 / V_39 ;
switch ( V_10 -> V_13 -> V_24 ) {
case V_25 : V_36 = V_35 ; break;
case V_27 : V_36 = V_35 / 2 ; break;
case V_28 : V_36 = V_35 / 3 ; break;
case V_29 : V_36 = V_35 / 4 ; break;
default: V_36 = V_35 ;
}
F_9 ( V_32 , V_37 , & V_12 , V_35 , V_36 ) ;
if ( V_33 ) {
F_9 ( V_33 , V_33 -> V_40 , & V_34 , V_35 , V_36 ) ;
F_10 ( & V_34 , & V_12 , & V_12 , V_41 ) ;
}
F_1 ( V_1 , V_32 -> V_2 , & V_12 ) ;
}
static void F_11 ( T_1 * V_1 , T_3 * V_32 )
{
V_32 -> V_38 = V_32 -> V_40 ;
F_7 ( V_1 , V_32 ) ;
}
static struct V_42 * F_12 ( struct V_5 * * V_43 )
{
struct V_42 * V_13 ;
for ( V_13 = V_44 ;
V_13 -> V_45 != V_46 ; V_13 ++ )
if ( ( * V_43 = F_13 ( V_47 +
! ! ( V_13 -> V_14 & V_48 ) ,
V_13 -> V_45 , NULL ) ) ) {
if ( ( * V_43 ) -> V_49 >= V_13 -> V_50 &&
( * V_43 ) -> V_49 <= V_13 -> V_51 )
break;
F_14 ( * V_43 ) ;
}
return V_13 ;
}
static void F_15 ( struct V_9 * V_10 , T_4 V_52 )
{
int V_53 ;
switch ( V_10 -> V_13 -> V_24 ) {
case V_27 :
for ( V_53 = 24 ; V_53 >= 0 ; V_53 -= 8 )
if ( ( ( V_52 >> ( V_53 & 16 ) ) & 8 ) &&
( ( V_52 >> V_53 ) & 0x20 ) &&
( ( ( V_52 >> V_53 ) & 7 ) < 2 ) ) {
V_10 -> V_54 |= ( 1 << ( 1 - ( V_53 >> 4 ) ) ) ;
}
break;
case V_28 :
for ( V_53 = 24 ; V_53 >= 0 ; V_53 -= 8 )
if ( ( ( V_52 >> V_53 ) & 0x10 ) ||
( ( ( V_52 >> V_53 ) & 0x20 ) &&
( ( ( V_52 >> V_53 ) & 7 ) < 4 ) ) ) {
V_10 -> V_54 |= ( 1 << ( 1 - ( V_53 >> 4 ) ) ) ;
}
break;
case V_29 :
for ( V_53 = 24 ; V_53 >= 0 ; V_53 -= 8 )
if ( ( ( V_52 >> V_53 ) & 0x10 ) ||
( ( ( V_52 >> V_53 ) & 0x20 ) &&
( ( ( V_52 >> V_53 ) & 7 ) < 6 ) ) ) {
V_10 -> V_54 |= ( 1 << ( 1 - ( V_53 >> 4 ) ) ) ;
}
break;
}
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_42 * V_13 = V_10 -> V_13 ;
T_2 V_12 , V_55 ;
T_4 V_52 ;
F_17 ( V_6 , V_31 , & V_52 ) ;
F_15 ( V_10 , V_52 ) ;
if ( V_13 -> V_24 == V_27 ) {
F_18 ( V_6 , V_31 , V_52 | 0x80008 ) ;
} else if ( V_13 -> V_14 & V_56 ) {
F_18 ( V_6 , V_31 , V_52 & ~ 0x80008 ) ;
}
F_4 ( V_6 , V_57 , & V_55 ) ;
F_4 ( V_6 , V_58 , & V_12 ) ;
if ( V_13 -> V_14 & V_59 ) {
V_12 &= 0x7f ;
}
if ( V_13 -> V_14 & V_60 ) {
V_12 &= ( V_12 & 0x9f ) ;
switch ( V_55 & 3 ) {
case 2 : V_12 |= 0x00 ; break;
case 1 : V_12 |= 0x60 ; break;
case 3 : V_12 |= 0x20 ; break;
}
}
F_6 ( V_6 , V_58 , V_12 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_61 )
{
if ( F_20 ( V_62 ) )
return 1 ;
if ( V_61 -> V_63 == 0x161F &&
V_61 -> V_64 == 0x2032 )
return 1 ;
return 0 ;
}
static T_2 F_21 ( T_1 * V_1 )
{
struct V_5 * V_61 = F_2 ( V_1 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( V_61 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
if ( F_19 ( V_61 ) )
return V_65 ;
if ( ( V_10 -> V_13 -> V_14 & V_66 ) && V_1 -> V_67 == 0 )
return V_68 ;
if ( ( V_10 -> V_54 >> V_1 -> V_67 ) & 1 )
return V_69 ;
else
return V_70 ;
}
static int F_22 ( struct V_5 * V_6 , const struct V_71 * V_45 )
{
struct V_5 * V_43 = NULL ;
struct V_42 * V_13 ;
struct V_9 * V_10 ;
int V_72 ;
T_2 V_73 = V_45 -> V_74 ;
struct V_75 V_76 ;
V_76 = V_77 ;
V_13 = F_12 ( & V_43 ) ;
F_23 (KERN_INFO DRV_NAME L_1 ,
pci_name(dev), via_config->name, isa->revision,
via_config->udma_mask ? L_2 : L_3 ,
via_dma[via_config->udma_mask ?
(fls(via_config->udma_mask) - 1) : 0]) ;
F_14 ( V_43 ) ;
V_39 = ( V_78 ? V_78 : 33 ) * 1000 ;
switch ( V_39 ) {
case 33000 : V_39 = 33333 ; break;
case 37000 : V_39 = 37500 ; break;
case 41000 : V_39 = 41666 ; break;
}
if ( V_39 < 20000 || V_39 > 50000 ) {
F_23 (KERN_WARNING DRV_NAME L_4
L_5 , via_clock) ;
V_39 = 33333 ;
}
if ( V_73 == 1 )
V_76 . V_79 [ 1 ] . V_80 = V_76 . V_79 [ 0 ] . V_80 = 0 ;
else
V_76 . V_81 |= V_82 ;
if ( V_73 == V_83 )
V_76 . V_81 |= V_84 ;
if ( ( V_13 -> V_14 & V_85 ) == 0 )
V_76 . V_81 |= V_86 ;
V_76 . V_24 = V_13 -> V_24 ;
V_10 = F_24 ( sizeof( * V_10 ) , V_87 ) ;
if ( ! V_10 ) {
F_23 (KERN_ERR DRV_NAME L_6 ,
pci_name(dev)) ;
return - V_88 ;
}
V_10 -> V_13 = V_13 ;
V_72 = F_25 ( V_6 , & V_76 , V_10 ) ;
if ( V_72 )
F_26 ( V_10 ) ;
return V_72 ;
}
static void F_27 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
F_28 ( V_6 ) ;
F_26 ( V_10 ) ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_89 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_89 ) ;
}
