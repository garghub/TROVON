static void F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
int V_8 = V_3 -> V_8 ;
T_4 V_9 ;
if( V_7 -> V_10 == V_11 )
V_9 = V_2 >> 8 ;
else
V_9 = V_2 & 0xFF ;
F_4 ( V_5 , 0x54 + 4 * V_8 , V_9 ) ;
}
static void F_5 ( T_1 * V_1 , T_2 V_2 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
int V_8 = V_3 -> V_8 ;
T_4 V_12 = V_1 -> V_13 & 1 , V_9 ;
if( V_7 -> V_10 == V_11 )
V_9 = V_2 >> 8 ;
else
V_9 = V_2 & 0xFF ;
if ( V_7 -> V_14 == 0 )
F_4 ( V_5 , 0x56 + 4 * V_8 + V_12 , V_9 ) ;
else {
F_4 ( V_5 , 0x56 + 4 * V_8 , V_9 ) ;
F_4 ( V_5 , 0x56 + 4 * V_8 + 1 , V_9 ) ;
}
}
static void F_6 ( T_1 * V_1 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 * V_15 = F_7 ( V_1 ) ;
int clock , V_16 , V_17 = 0 ;
T_4 V_12 = V_1 -> V_13 & 1 , V_18 ;
if( V_7 -> V_19 [ 0 ] [ 0 ] > V_7 -> V_19 [ 1 ] [ 0 ] ) {
clock = V_7 -> V_19 [ 0 ] [ 1 ] ;
V_16 = V_7 -> V_19 [ 1 ] [ 1 ] ;
} else {
clock = V_7 -> V_19 [ 1 ] [ 1 ] ;
V_16 = V_7 -> V_19 [ 0 ] [ 1 ] ;
}
if ( clock == V_20 )
clock = V_16 ;
if( clock == V_20 )
return;
if( clock == V_7 -> V_10 )
return;
if( clock == V_11 )
V_7 -> V_10 = V_11 ;
else {
V_7 -> V_10 = V_21 ;
V_17 = 1 ;
}
F_8 ( V_5 , 0x50 , & V_18 ) ;
V_18 &= ~ ( 1 << ( 1 + V_3 -> V_8 ) ) ;
V_18 |= V_17 << ( 1 + V_3 -> V_8 ) ;
F_4 ( V_5 , 0x50 , V_18 ) ;
if( V_15 && V_7 -> V_22 [ 1 - V_12 ] != V_23 ) {
F_5 ( V_15 , V_7 -> V_22 [ 1 - V_12 ] ) ;
F_1 ( V_15 , V_7 -> V_24 [ 1 - V_12 ] ) ;
}
if( V_7 -> V_22 [ V_12 ] != V_23 ) {
F_5 ( V_1 , V_7 -> V_22 [ V_12 ] ) ;
F_1 ( V_1 , V_7 -> V_24 [ V_12 ] ) ;
}
}
static void F_9 ( T_3 * V_3 , T_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 * V_15 = F_7 ( V_1 ) ;
const T_4 V_24 = V_1 -> V_25 - V_26 ;
T_4 V_12 = V_1 -> V_13 & 1 , V_27 = V_24 ;
static T_2 V_28 [] = { 0xAA88 , 0xA382 , 0xA181 , 0x3332 , 0x3121 } ;
static T_4 V_29 [] = { V_11 , V_11 , V_11 , V_11 , V_20 } ;
if ( V_15 ) {
T_4 V_30 = V_15 -> V_25 - V_26 ;
if ( V_30 < V_27 )
V_27 = V_30 ;
}
V_7 -> V_19 [ V_12 ] [ 1 ] = V_29 [ V_27 ] ;
V_7 -> V_19 [ V_12 ] [ 0 ] = 1 ;
V_7 -> V_24 [ V_12 ] = V_28 [ V_27 ] ;
F_6 ( V_1 ) ;
F_1 ( V_1 , V_7 -> V_24 [ V_12 ] ) ;
}
static void F_10 ( T_1 * V_1 , T_4 V_31 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
struct V_6 * V_7 = ( void * ) F_3 ( V_3 ) ;
T_4 V_12 = V_1 -> V_13 & 1 , V_8 = V_3 -> V_8 , V_9 ;
static T_2 V_32 [] = { 0x8866 , 0x3222 , 0x3121 } ;
static T_4 V_33 [] = { V_20 , V_11 , V_20 } ;
V_7 -> V_19 [ V_12 ] [ 1 ] = V_33 [ V_31 ] ;
V_7 -> V_19 [ V_12 ] [ 0 ] = 2 ;
V_7 -> V_34 [ V_12 ] = V_32 [ V_31 ] ;
V_7 -> V_22 [ V_12 ] = V_23 ;
F_8 ( V_5 , 0x50 , & V_9 ) ;
if ( V_7 -> V_14 )
V_9 |= V_8 ? 0x60 : 0x18 ;
else
V_9 |= 1 << ( 3 + 2 * V_8 + V_12 ) ;
F_4 ( V_5 , 0x50 , V_9 ) ;
F_6 ( V_1 ) ;
}
static void F_11 ( T_1 * V_1 , T_4 V_31 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_4 V_12 = V_1 -> V_13 & 1 , V_8 = V_3 -> V_8 , V_9 ;
static T_2 V_22 [] = { 0x4433 , 0x4231 , 0x3121 , 0x2121 , 0x1111 , 0x2211 , 0x1111 } ;
static T_4 V_35 [] = { V_20 , V_21 , V_20 , V_11 , V_11 , V_21 , V_11 } ;
V_7 -> V_19 [ V_12 ] [ 1 ] = V_35 [ V_31 ] ;
V_7 -> V_19 [ V_12 ] [ 0 ] = 3 ;
V_7 -> V_34 [ V_12 ] = V_36 ;
V_7 -> V_22 [ V_12 ] = V_22 [ V_31 ] ;
if( V_31 >= 5 )
V_7 -> V_22 [ V_12 ] |= 0x8080 ;
F_8 ( V_5 , 0x50 , & V_9 ) ;
if ( V_7 -> V_14 )
V_9 &= V_8 ? 0x9F : 0xE7 ;
else
V_9 &= ~ ( 1 << ( 3 + 2 * V_8 + V_12 ) ) ;
F_4 ( V_5 , 0x50 , V_9 ) ;
F_6 ( V_1 ) ;
F_5 ( V_1 , V_7 -> V_22 [ V_12 ] ) ;
}
static void F_12 ( T_1 * V_1 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_4 V_12 = V_1 -> V_13 & 1 ;
if( V_7 -> V_34 [ V_12 ] != V_36 )
F_1 ( V_1 , V_7 -> V_34 [ V_12 ] ) ;
else if( V_7 -> V_22 [ V_12 ] != V_23 && V_7 -> V_14 )
F_5 ( V_1 , V_7 -> V_22 [ V_12 ] ) ;
F_13 ( V_1 ) ;
}
static int F_14 ( T_1 * V_1 )
{
T_3 * V_3 = V_1 -> V_3 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
int V_37 = F_15 ( V_1 ) ;
T_4 V_12 = V_1 -> V_13 & 1 ;
if( V_7 -> V_34 [ V_12 ] != V_36 )
F_1 ( V_1 , V_7 -> V_24 [ V_12 ] ) ;
return V_37 ;
}
static void F_16 ( T_3 * V_3 , T_1 * V_1 )
{
const T_4 V_38 = V_1 -> V_39 ;
if ( V_38 >= V_40 && V_38 <= V_41 )
F_11 ( V_1 , V_38 - V_40 ) ;
else if ( V_38 >= V_42 && V_38 <= V_43 )
F_10 ( V_1 , V_38 - V_42 ) ;
}
static T_4 F_17 ( T_3 * V_3 )
{
return V_44 ;
}
static void F_18 ( T_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 -> V_3 ) ;
T_2 * V_45 = V_1 -> V_45 ;
if ( ! V_7 -> V_46 ) {
V_1 -> V_47 |= V_48 ;
} else {
if ( strstr ( ( char * ) & V_45 [ V_49 ] ,
L_1 ) ) {
V_45 [ V_50 ] |= ( 3 << 8 ) ;
V_45 [ V_51 ] |= 0x0400 ;
V_45 [ V_52 ] |= 0x0400 ;
F_19 ( V_53 L_2 ,
V_1 -> V_54 , V_45 [ 147 ] ? L_3 : L_4 ,
V_45 [ V_55 ] ) ;
if ( V_45 [ V_55 ] != 1 )
F_19 ( V_56 L_5 , V_45 [ 146 ] ) ;
F_19 ( V_56 L_6 ) ;
} else {
V_45 [ V_57 ] &= 3 ;
V_45 [ V_58 ] = 0 ;
V_45 [ V_59 ] = 0 ;
V_45 [ V_51 ] &= 0xC400 ;
V_45 [ V_60 ] &= 0xC000 ;
V_45 [ V_61 ] = 0 ;
V_45 [ V_52 ] &= 0xC400 ;
V_45 [ V_62 ] &= 0xC000 ;
V_45 [ 127 ] = 0 ;
V_45 [ V_63 ] = 0 ;
V_45 [ V_55 ] = 0 ;
V_45 [ V_64 ] = 0 ;
F_19 ( V_53 L_7 ,
V_1 -> V_54 ) ;
}
if ( F_20 ( V_45 ) ) {
V_45 [ V_65 ] |= 0x0101 ;
V_1 -> V_66 = V_42 ;
}
}
}
static void F_21 ( T_3 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_5 ) ;
struct V_67 * V_68 = F_22 ( V_5 ) ;
struct V_6 * V_69 = V_68 -> V_70 ;
struct V_6 * V_71 = V_69 + V_3 -> V_8 ;
T_4 V_9 ;
F_23 ( V_3 , V_71 ) ;
F_8 ( V_5 , 0x50 , & V_9 ) ;
if ( V_9 & 1 ) {
V_71 -> V_46 = 1 ;
V_3 -> V_72 |= V_73 ;
V_3 -> V_74 = 256 ;
}
if ( V_9 & ( 1 << ( 1 + V_3 -> V_8 ) ) )
V_71 -> V_10 = V_21 ;
else
V_71 -> V_10 = V_11 ;
V_71 -> V_19 [ 0 ] [ 1 ] = V_20 ;
V_71 -> V_19 [ 1 ] [ 1 ] = V_20 ;
if ( V_5 -> V_75 == 0x10 ) {
V_71 -> V_14 = 1 ;
V_3 -> V_72 |= V_73 ;
if ( V_71 -> V_46 == 0 )
F_19 (KERN_WARNING DRV_NAME L_8
L_9 , pci_name(dev)) ;
}
if ( V_71 -> V_46 == 0 ) {
V_3 -> V_76 = & V_77 ;
} else
V_3 -> V_72 |= V_78 ;
if ( V_3 -> V_79 == 0 )
return;
V_3 -> V_80 = V_81 ;
V_3 -> V_82 = V_83 ;
if ( V_71 -> V_84 & V_85 ) {
if ( V_5 -> V_75 == 0x11 )
V_3 -> V_80 = 0 ;
}
}
static void F_24 ( struct V_4 * V_5 )
{
F_4 ( V_5 , 0x5E , 0x01 ) ;
F_4 ( V_5 , 0x50 , 0x00 ) ;
F_25 ( V_5 , V_86 ,
V_87 | V_88 |
V_89 | V_90 ) ;
F_25 ( V_5 , 0x40 , 0xA0F3 ) ;
F_26 ( V_5 , 0x4C , 0x02040204 ) ;
F_4 ( V_5 , 0x42 , 0x36 ) ;
F_4 ( V_5 , V_91 , 0x20 ) ;
}
static int F_27 ( struct V_4 * V_5 )
{
T_4 V_9 ;
static char * V_92 [ 2 ] = { L_10 , L_11 } ;
if ( V_93 ) {
F_19 (KERN_INFO DRV_NAME L_12 ,
pci_name(dev)) ;
F_24 ( V_5 ) ;
}
F_8 ( V_5 , 0x50 , & V_9 ) ;
F_19 (KERN_INFO DRV_NAME L_13 ,
pci_name(dev), mode[conf & 1]) ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 , const struct V_94 * V_45 )
{
struct V_6 * V_69 ;
int V_95 ;
V_69 = F_29 ( 2 * sizeof( * V_69 ) , V_96 ) ;
if ( V_69 == NULL ) {
F_19 (KERN_ERR DRV_NAME L_14 , pci_name(dev)) ;
return - V_97 ;
}
V_69 -> V_84 = V_45 -> V_98 ;
V_95 = F_30 ( V_5 , & V_99 , V_69 ) ;
if ( V_95 )
F_31 ( V_69 ) ;
return V_95 ;
}
static void F_32 ( struct V_4 * V_5 )
{
struct V_67 * V_68 = F_22 ( V_5 ) ;
struct V_6 * V_69 = V_68 -> V_70 ;
F_33 ( V_5 ) ;
F_31 ( V_69 ) ;
}
static int T_5 F_34 ( void )
{
return F_35 ( & V_100 ) ;
}
static void T_6 F_36 ( void )
{
F_37 ( & V_100 ) ;
}
