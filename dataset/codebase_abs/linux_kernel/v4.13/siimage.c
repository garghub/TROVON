static int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
switch ( V_2 -> V_3 ) {
case V_4 :
case V_5 :
return 1 ;
case V_6 :
return 0 ;
}
F_3 () ;
#endif
return 0 ;
}
static inline int F_4 ( T_1 * V_7 )
{
return F_1 ( F_5 ( V_7 -> V_8 ) ) ;
}
static unsigned long F_6 ( T_1 * V_7 , int V_9 )
{
unsigned long V_10 = ( unsigned long ) V_7 -> V_11 ;
V_10 += 0xA0 + V_9 ;
if ( V_7 -> V_12 & V_13 )
V_10 += V_7 -> V_14 << 6 ;
else
V_10 += V_7 -> V_14 << 4 ;
return V_10 ;
}
static inline unsigned long F_7 ( T_2 * V_15 , int V_9 )
{
T_1 * V_7 = V_15 -> V_7 ;
unsigned long V_10 = ( unsigned long ) V_7 -> V_11 ;
T_3 V_16 = V_15 -> V_17 & 1 ;
V_10 += 0xA0 + V_9 ;
if ( V_7 -> V_12 & V_13 )
V_10 += V_7 -> V_14 << 6 ;
else
V_10 += V_7 -> V_14 << 4 ;
V_10 |= V_16 << V_16 ;
return V_10 ;
}
static T_3 F_8 ( struct V_1 * V_8 , unsigned long V_18 )
{
struct V_19 * V_20 = F_9 ( V_8 ) ;
T_3 V_21 = 0 ;
if ( V_20 -> V_22 )
V_21 = F_10 ( ( void V_23 * ) V_18 ) ;
else
F_11 ( V_8 , V_18 , & V_21 ) ;
return V_21 ;
}
static T_4 F_12 ( struct V_1 * V_8 , unsigned long V_18 )
{
struct V_19 * V_20 = F_9 ( V_8 ) ;
T_4 V_21 = 0 ;
if ( V_20 -> V_22 )
V_21 = F_13 ( ( void V_23 * ) V_18 ) ;
else
F_14 ( V_8 , V_18 , & V_21 ) ;
return V_21 ;
}
static void F_15 ( struct V_1 * V_8 , T_3 V_24 , unsigned long V_18 )
{
struct V_19 * V_20 = F_9 ( V_8 ) ;
if ( V_20 -> V_22 )
F_16 ( V_24 , ( void V_23 * ) V_18 ) ;
else
F_17 ( V_8 , V_18 , V_24 ) ;
}
static void F_18 ( struct V_1 * V_8 , T_4 V_24 , unsigned long V_18 )
{
struct V_19 * V_20 = F_9 ( V_8 ) ;
if ( V_20 -> V_22 )
F_19 ( V_24 , ( void V_23 * ) V_18 ) ;
else
F_20 ( V_8 , V_18 , V_24 ) ;
}
static void F_21 ( struct V_1 * V_8 , T_5 V_24 , unsigned long V_18 )
{
struct V_19 * V_20 = F_9 ( V_8 ) ;
if ( V_20 -> V_22 )
F_22 ( V_24 , ( void V_23 * ) V_18 ) ;
else
F_23 ( V_8 , V_18 , V_24 ) ;
}
static T_3 F_24 ( T_2 * V_15 )
{
T_1 * V_7 = V_15 -> V_7 ;
struct V_1 * V_8 = F_5 ( V_7 -> V_8 ) ;
unsigned long V_10 = ( unsigned long ) V_7 -> V_11 ;
T_3 V_25 , V_26 = 0 ;
V_10 += ( V_7 -> V_12 & V_13 ) ? 0x4A : 0x8A ;
V_25 = F_8 ( V_8 , V_10 ) ;
switch ( V_25 & 0x30 ) {
case 0x10 :
V_26 = V_27 ;
break;
case 0x20 :
V_26 = V_27 ;
break;
case 0x00 :
V_26 = V_28 ;
break;
default:
F_3 () ;
}
return V_26 ;
}
static T_3 F_25 ( T_2 * V_15 )
{
char * V_29 = ( char * ) & V_15 -> V_30 [ V_31 ] ;
return strstr ( V_29 , L_1 ) ? V_28 : V_27 ;
}
static void F_26 ( T_1 * V_7 , T_2 * V_15 )
{
static const T_4 V_32 [] = { 0x328a , 0x2283 , 0x1281 , 0x10c3 , 0x10c1 } ;
static const T_4 V_33 [] = { 0x328a , 0x2283 , 0x1104 , 0x10c3 , 0x10c1 } ;
struct V_1 * V_8 = F_5 ( V_7 -> V_8 ) ;
T_2 * V_34 = F_27 ( V_15 ) ;
T_5 V_35 = 0 ;
T_4 V_36 = 0 ;
unsigned long V_18 = F_7 ( V_15 , 0x04 ) ;
unsigned long V_37 = F_6 ( V_7 , 0x02 ) ;
unsigned long V_10 = ( unsigned long ) V_7 -> V_11 ;
const T_3 V_38 = V_15 -> V_39 - V_40 ;
T_3 V_41 = V_38 ;
T_3 V_42 = ( V_7 -> V_12 & V_13 ) ? 1 : 0 ;
T_3 V_43 = V_7 -> V_14 ? ( V_42 ? 0xF4 : 0x84 )
: ( V_42 ? 0xB4 : 0x80 ) ;
T_3 V_44 = 0 ;
T_3 V_16 = V_15 -> V_17 & 1 ;
if ( V_34 ) {
T_3 V_45 = V_34 -> V_39 - V_40 ;
if ( V_45 < V_41 )
V_41 = V_45 ;
}
V_36 = V_33 [ V_38 ] ;
V_35 = V_32 [ V_41 ] ;
F_18 ( V_8 , V_36 , V_18 ) ;
F_18 ( V_8 , V_35 , V_37 ) ;
V_36 = F_12 ( V_8 , V_37 - 2 ) ;
V_36 &= ~ 0x200 ;
V_44 = F_8 ( V_8 , V_10 + V_43 ) ;
V_44 &= ~ ( V_16 ? 0x30 : 0x03 ) ;
if ( F_28 ( V_15 , V_38 ) ) {
V_36 |= 0x200 ;
V_44 |= V_16 ? 0x10 : 0x01 ;
}
F_18 ( V_8 , V_36 , V_37 - 2 ) ;
F_15 ( V_8 , V_44 , V_10 + V_43 ) ;
}
static void F_29 ( T_1 * V_7 , T_2 * V_15 )
{
static const T_3 V_46 [] = { 0x0F , 0x0B , 0x07 , 0x05 , 0x03 , 0x02 , 0x01 } ;
static const T_3 V_47 [] = { 0x0C , 0x07 , 0x05 , 0x04 , 0x02 , 0x01 } ;
static const T_4 V_48 [] = { 0x2208 , 0x10C2 , 0x10C1 } ;
struct V_1 * V_8 = F_5 ( V_7 -> V_8 ) ;
unsigned long V_10 = ( unsigned long ) V_7 -> V_11 ;
T_4 V_49 = 0 , V_50 = 0 ;
T_3 V_44 = 0 , V_16 = V_15 -> V_17 & 1 ;
T_3 V_42 = ( V_7 -> V_12 & V_13 ) ? 1 : 0 ;
T_3 V_25 = 0 , V_43 = V_7 -> V_14 ? ( V_42 ? 0xF4 : 0x84 )
: ( V_42 ? 0xB4 : 0x80 ) ;
unsigned long V_51 = F_7 ( V_15 , 0x08 ) ;
unsigned long V_52 = F_7 ( V_15 , 0x0C ) ;
const T_3 V_53 = V_15 -> V_54 ;
V_25 = F_8 ( V_8 , V_10 + ( V_42 ? 0x4A : 0x8A ) ) ;
V_44 = F_8 ( V_8 , V_10 + V_43 ) ;
V_50 = F_12 ( V_8 , V_51 ) ;
V_49 = F_12 ( V_8 , V_52 ) ;
V_44 &= ~ ( V_16 ? 0x30 : 0x03 ) ;
V_49 &= ~ 0x3F ;
V_25 = ( ( V_25 & 0x30 ) == 0x00 ) ? 0 : 1 ;
V_25 = F_4 ( V_7 ) ? 1 : V_25 ;
if ( V_53 >= V_55 ) {
V_50 = V_48 [ 2 ] ;
V_49 |= V_25 ? V_46 [ V_53 - V_55 ] :
V_47 [ V_53 - V_55 ] ;
V_44 |= V_16 ? 0x30 : 0x03 ;
} else {
V_50 = V_48 [ V_53 - V_56 ] ;
V_44 |= V_16 ? 0x20 : 0x02 ;
}
F_15 ( V_8 , V_44 , V_10 + V_43 ) ;
F_18 ( V_8 , V_50 , V_51 ) ;
F_18 ( V_8 , V_49 , V_52 ) ;
}
static int F_30 ( T_1 * V_7 )
{
struct V_1 * V_8 = F_5 ( V_7 -> V_8 ) ;
unsigned long V_18 = F_6 ( V_7 , 1 ) ;
T_3 V_24 = F_8 ( V_8 , V_18 ) ;
return ( V_24 & 8 ) ? 1 : 0 ;
}
static int F_31 ( T_2 * V_15 )
{
T_1 * V_7 = V_15 -> V_7 ;
void V_23 * V_57
= ( void V_23 * ) V_7 -> V_58 [ V_59 ] ;
if ( V_57 ) {
unsigned long V_10 = ( unsigned long ) V_7 -> V_11 ;
T_5 V_60 = F_32 ( ( void V_23 * ) ( V_10 + 0x10 ) ) ;
T_3 V_61 = 0 ;
if ( V_60 & ( ( V_7 -> V_14 ) ? 0x40 : 0x10 ) ) {
T_5 V_62 = F_32 ( V_57 ) ;
F_22 ( V_62 , V_57 ) ;
V_61 = ( V_62 & 0x00680000 ) ? 1 : 0 ;
F_33 ( V_63 L_2
L_3 ,
V_15 -> V_64 , V_62 , V_61 , V_65 ) ;
} else
V_61 = ( V_60 & 0x8000 ) ? 1 : 0 ;
V_60 >>= 16 ;
if ( ! ( V_60 & 0x0404 ) && ! V_61 )
return 0 ;
}
if ( F_10 ( ( void V_23 * ) ( V_7 -> V_66 + V_67 ) ) & 4 )
return 1 ;
return 0 ;
}
static int F_34 ( T_2 * V_15 )
{
if ( V_15 -> V_7 -> V_12 & V_13 )
return F_31 ( V_15 ) ;
else
return F_35 ( V_15 ) ;
}
static T_6 F_36 ( T_2 * V_15 )
{
T_1 * V_7 = V_15 -> V_7 ;
void V_23 * V_68
= ( void V_23 * ) V_7 -> V_58 [ V_69 ] ;
if ( V_68 ) {
T_5 V_70 = F_32 ( V_68 ) ;
if ( ( V_70 & 0x03 ) != 0x03 ) {
F_33 ( V_63 L_4 ,
V_7 -> V_64 , V_70 ) ;
return V_71 ;
}
}
return V_72 ;
}
static void F_37 ( T_2 * V_15 )
{
if ( V_15 -> V_73 == V_74 ) {
V_15 -> V_75 &=
~ ( V_76 | V_77 ) ;
}
}
static int F_38 ( struct V_1 * V_8 )
{
struct V_19 * V_20 = F_9 ( V_8 ) ;
void V_23 * V_78 = V_20 -> V_22 ;
unsigned long V_10 , V_79 ;
T_3 V_80 = V_8 -> V_81 , V_21 ;
F_17 ( V_8 , V_82 , V_80 ? 1 : 255 ) ;
if ( V_78 )
F_39 ( V_8 ) ;
V_10 = ( unsigned long ) V_78 ;
if ( V_78 && F_1 ( V_8 ) ) {
T_5 V_83 , V_84 ;
V_84 = ( 1 << 22 ) | ( 1 << 23 ) ;
V_83 = F_32 ( V_78 + 0x48 ) ;
if ( V_83 & V_84 ) {
V_83 &= ~ V_84 ;
F_22 ( V_83 , V_78 + 0x48 ) ;
F_32 ( V_78 + 0x48 ) ;
}
F_22 ( 0 , V_78 + 0x148 ) ;
F_22 ( 0 , V_78 + 0x1C8 ) ;
}
F_15 ( V_8 , 0 , V_10 ? ( V_10 + 0xB4 ) : 0x80 ) ;
F_15 ( V_8 , 0 , V_10 ? ( V_10 + 0xF4 ) : 0x84 ) ;
V_79 = V_10 ? ( V_10 + 0x4A ) : 0x8A ;
V_21 = F_8 ( V_8 , V_79 ) ;
switch ( V_21 & 0x30 ) {
case 0x00 :
F_15 ( V_8 , V_21 | 0x10 , V_79 ) ;
break;
case 0x30 :
F_15 ( V_8 , V_21 & ~ 0x20 , V_79 ) ;
case 0x10 :
break;
case 0x20 :
break;
}
V_21 = F_8 ( V_8 , V_79 ) ;
F_15 ( V_8 , 0x72 , V_10 + 0xA1 ) ;
F_18 ( V_8 , 0x328A , V_10 + 0xA2 ) ;
F_21 ( V_8 , 0x62DD62DD , V_10 + 0xA4 ) ;
F_21 ( V_8 , 0x43924392 , V_10 + 0xA8 ) ;
F_21 ( V_8 , 0x40094009 , V_10 + 0xAC ) ;
F_15 ( V_8 , 0x72 , V_10 ? ( V_10 + 0xE1 ) : 0xB1 ) ;
F_18 ( V_8 , 0x328A , V_10 ? ( V_10 + 0xE2 ) : 0xB2 ) ;
F_21 ( V_8 , 0x62DD62DD , V_10 ? ( V_10 + 0xE4 ) : 0xB4 ) ;
F_21 ( V_8 , 0x43924392 , V_10 ? ( V_10 + 0xE8 ) : 0xB8 ) ;
F_21 ( V_8 , 0x40094009 , V_10 ? ( V_10 + 0xEC ) : 0xBC ) ;
if ( V_10 && F_1 ( V_8 ) ) {
F_22 ( 0xFFFF0000 , V_78 + 0x108 ) ;
F_22 ( 0xFFFF0000 , V_78 + 0x188 ) ;
F_22 ( 0x00680000 , V_78 + 0x148 ) ;
F_22 ( 0x00680000 , V_78 + 0x1C8 ) ;
}
if ( ! F_1 ( V_8 ) ) {
static const char * V_85 [] =
{ L_5 , L_6 , L_7 , L_8 } ;
V_21 >>= 4 ;
F_33 (KERN_INFO DRV_NAME L_9 ,
pci_name(dev), clk_str[tmp & 3]) ;
}
return 0 ;
}
static void F_40 ( T_1 * V_7 )
{
struct V_1 * V_8 = F_5 ( V_7 -> V_8 ) ;
struct V_19 * V_20 = F_9 ( V_8 ) ;
void * V_18 = V_20 -> V_22 ;
T_3 V_86 = V_7 -> V_14 ;
struct V_87 * V_88 = & V_7 -> V_88 ;
unsigned long V_10 ;
V_7 -> V_12 |= V_13 ;
V_7 -> V_11 = V_18 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_10 = ( unsigned long ) V_18 ;
if ( V_86 )
V_10 += 0xC0 ;
else
V_10 += 0x80 ;
V_88 -> V_89 = V_10 ;
V_88 -> V_90 = V_10 + 1 ;
V_88 -> V_91 = V_10 + 2 ;
V_88 -> V_92 = V_10 + 3 ;
V_88 -> V_93 = V_10 + 4 ;
V_88 -> V_94 = V_10 + 5 ;
V_88 -> V_95 = V_10 + 6 ;
V_88 -> V_96 = V_10 + 7 ;
V_88 -> V_97 = V_10 + 10 ;
if ( F_1 ( V_8 ) ) {
V_10 = ( unsigned long ) V_18 ;
if ( V_86 )
V_10 += 0x80 ;
V_7 -> V_58 [ V_69 ] = V_10 + 0x104 ;
V_7 -> V_58 [ V_59 ] = V_10 + 0x108 ;
V_7 -> V_58 [ V_98 ] = V_10 + 0x100 ;
}
V_7 -> V_99 = V_8 -> V_99 ;
V_7 -> V_66 = ( unsigned long ) V_18 + ( V_86 ? 0x08 : 0x00 ) ;
}
static int F_41 ( T_2 * V_15 )
{
const char * V_100 = ( const char * ) & V_15 -> V_30 [ V_31 ] ;
unsigned V_101 = F_42 ( V_100 , V_102 ) ;
if ( ( V_101 > 4 ) && ( ! memcmp ( V_100 , L_10 , 2 ) ) )
if ( ( ! memcmp ( V_100 + V_101 - 2 , L_11 , 2 ) ) ||
( ! memcmp ( V_100 + V_101 - 3 , L_12 , 3 ) ) ) {
F_33 ( V_103 L_13
L_14 , V_15 -> V_64 ) ;
return 1 ;
}
return 0 ;
}
static void F_43 ( T_2 * V_15 )
{
T_1 * V_7 = V_15 -> V_7 ;
if ( ! F_4 ( V_7 ) || ! F_41 ( V_15 ) )
V_7 -> V_104 = 128 ;
}
static void F_44 ( T_1 * V_7 )
{
struct V_1 * V_8 = F_5 ( V_7 -> V_8 ) ;
struct V_19 * V_20 = F_9 ( V_8 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_104 = 15 ;
if ( V_20 -> V_22 )
F_40 ( V_7 ) ;
}
static T_3 F_45 ( T_1 * V_7 )
{
struct V_1 * V_8 = F_5 ( V_7 -> V_8 ) ;
unsigned long V_18 = F_6 ( V_7 , 0 ) ;
T_3 V_105 = F_8 ( V_8 , V_18 ) ;
return ( V_105 & 0x01 ) ? V_106 : V_107 ;
}
static int F_46 ( struct V_1 * V_8 , const struct V_108 * V_30 )
{
void V_23 * V_78 = NULL ;
T_7 V_109 = F_47 ( V_8 , 5 ) ;
unsigned long V_110 = F_48 ( V_8 , 5 ) ;
int V_111 ;
struct V_112 V_113 ;
T_3 V_114 = V_30 -> V_115 ;
T_3 V_116 ;
V_113 = V_117 [ V_114 ] ;
if ( V_114 ) {
static int V_118 = 1 ;
if ( V_118 ) {
F_33 (KERN_INFO DRV_NAME L_15
L_16 ) ;
V_118 = 0 ;
}
V_113 . V_12 |= V_119 ;
}
V_111 = F_49 ( V_8 ) ;
if ( V_111 )
return V_111 ;
F_11 ( V_8 , 0x8A , & V_116 ) ;
if ( ( V_116 & 0x01 ) || V_109 ) {
if ( ! F_50 ( V_109 , V_110 , V_113 . V_64 ) ) {
F_33 (KERN_WARNING DRV_NAME L_17
L_18 , pci_name(dev)) ;
} else {
V_78 = F_51 ( V_8 , 5 ) ;
if ( V_78 == NULL )
F_52 ( V_109 , V_110 ) ;
}
}
V_111 = F_53 ( V_8 , & V_113 , V_78 ) ;
if ( V_111 ) {
if ( V_78 ) {
F_54 ( V_78 ) ;
F_52 ( V_109 , V_110 ) ;
}
F_55 ( V_8 ) ;
}
return V_111 ;
}
static void F_56 ( struct V_1 * V_8 )
{
struct V_19 * V_20 = F_9 ( V_8 ) ;
void V_23 * V_78 = V_20 -> V_22 ;
F_57 ( V_8 ) ;
if ( V_78 ) {
T_7 V_109 = F_47 ( V_8 , 5 ) ;
unsigned long V_110 = F_48 ( V_8 , 5 ) ;
F_54 ( V_78 ) ;
F_52 ( V_109 , V_110 ) ;
}
F_55 ( V_8 ) ;
}
static int T_8 F_58 ( void )
{
return F_59 ( & V_120 ) ;
}
static void T_9 F_60 ( void )
{
F_61 ( & V_120 ) ;
}
