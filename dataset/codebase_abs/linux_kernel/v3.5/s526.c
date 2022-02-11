static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 ;
int V_9 = F_2 ( V_6 -> V_10 ) ;
unsigned short V_11 ;
unsigned short V_12 ;
if ( V_6 -> V_13 <= 0 ) {
F_3 ( V_14 L_1 ) ;
return - V_15 ;
}
for ( V_8 = 0 ; V_8 < V_6 -> V_13 ; V_8 ++ ) {
V_11 = F_4 ( F_5 ( V_16 , V_9 ) ) ;
V_12 = F_4 ( F_5 ( V_17 , V_9 ) ) ;
V_7 [ V_8 ] = ( int ) ( V_12 & 0x00FF ) ;
V_7 [ V_8 ] = ( V_7 [ V_8 ] << 16 ) | ( V_11 & 0xFFFF ) ;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_18 = F_2 ( V_6 -> V_10 ) ;
int V_8 ;
short V_19 ;
union V_20 V_20 ;
for ( V_8 = 0 ; V_8 < V_21 ; V_8 ++ ) {
V_22 -> V_23 [ V_18 ] . V_7 [ V_8 ] =
V_6 -> V_7 [ V_8 ] ;
}
switch ( V_6 -> V_7 [ 0 ] ) {
case V_24 :
F_3 ( V_25 L_2 ) ;
V_22 -> V_23 [ V_18 ] . V_26 =
V_27 ;
#if 0
cmReg.reg.coutSource = 0;
cmReg.reg.coutPolarity = 1;
cmReg.reg.autoLoadResetRcap = 0;
cmReg.reg.hwCtEnableSource = 3;
cmReg.reg.ctEnableCtrl = 2;
cmReg.reg.clockSource = 2;
cmReg.reg.countDir = 1;
cmReg.reg.countDirCtrl = 1;
cmReg.reg.outputRegLatchCtrl = 0;
cmReg.reg.preloadRegSel = 0;
cmReg.reg.reserved = 0;
outw(cmReg.value, ADDR_CHAN_REG(REG_C0M, subdev_channel));
outw(0x0001, ADDR_CHAN_REG(REG_C0H, subdev_channel));
outw(0x3C68, ADDR_CHAN_REG(REG_C0L, subdev_channel));
outw(0x8000, ADDR_CHAN_REG(REG_C0C, subdev_channel));
outw(0x4000, ADDR_CHAN_REG(REG_C0C, subdev_channel));
outw(0x0008, ADDR_CHAN_REG(REG_C0C, subdev_channel));
#endif
#if 1
V_20 . V_19 = V_6 -> V_7 [ 1 ] & 0xFFFF ;
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_18 ) ) ;
if ( V_20 . V_29 . V_30 == 0 ) {
F_7 ( 0x8000 , F_5 ( V_31 , V_18 ) ) ;
}
#else
V_20 . V_29 . V_32 = 0 ;
if ( V_6 -> V_7 [ 1 ] == V_33 )
V_20 . V_29 . V_34 = 1 ;
else if ( V_6 -> V_7 [ 1 ] == V_35 )
V_20 . V_29 . V_34 = 2 ;
else
V_20 . V_29 . V_34 = 0 ;
if ( V_6 -> V_7 [ 3 ] == V_36 )
V_20 . V_29 . V_30 = 4 ;
V_20 . V_19 = ( short ) ( V_6 -> V_7 [ 1 ] & 0xFFFF ) ;
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_18 ) ) ;
V_19 = ( short ) ( ( V_6 -> V_7 [ 2 ] >> 16 ) & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_17 , V_18 ) ) ;
V_19 = ( short ) ( V_6 -> V_7 [ 2 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_16 , V_18 ) ) ;
if ( V_6 -> V_7 [ 3 ] != 0 ) {
V_19 = ( short ) ( V_6 -> V_7 [ 3 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_31 , V_18 ) ) ;
}
if ( V_20 . V_29 . V_30 == 0 ) {
F_7 ( 0x8000 , F_5 ( V_31 , V_18 ) ) ;
F_7 ( 0x4000 , F_5 ( V_31 , V_18 ) ) ;
}
#endif
break;
case V_37 :
F_3 ( V_25 L_3 ) ;
V_22 -> V_23 [ V_18 ] . V_26 =
V_38 ;
V_20 . V_19 = ( short ) ( V_6 -> V_7 [ 1 ] & 0xFFFF ) ;
V_20 . V_29 . V_39 = 0 ;
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_18 ) ) ;
V_19 = ( short ) ( ( V_6 -> V_7 [ 2 ] >> 16 ) & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_17 , V_18 ) ) ;
V_19 = ( short ) ( V_6 -> V_7 [ 2 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_16 , V_18 ) ) ;
V_20 . V_19 = ( short ) ( V_6 -> V_7 [ 1 ] & 0xFFFF ) ;
V_20 . V_29 . V_39 = 1 ;
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_18 ) ) ;
V_19 = ( short ) ( ( V_6 -> V_7 [ 3 ] >> 16 ) & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_17 , V_18 ) ) ;
V_19 = ( short ) ( V_6 -> V_7 [ 3 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_16 , V_18 ) ) ;
if ( V_6 -> V_7 [ 4 ] != 0 ) {
V_19 = ( short ) ( V_6 -> V_7 [ 4 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_31 , V_18 ) ) ;
}
break;
case V_40 :
F_3 ( V_25 L_4 ) ;
V_22 -> V_23 [ V_18 ] . V_26 =
V_41 ;
V_20 . V_19 = ( short ) ( V_6 -> V_7 [ 1 ] & 0xFFFF ) ;
V_20 . V_29 . V_39 = 0 ;
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_18 ) ) ;
V_19 = ( short ) ( ( V_6 -> V_7 [ 2 ] >> 16 ) & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_17 , V_18 ) ) ;
V_19 = ( short ) ( V_6 -> V_7 [ 2 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_16 , V_18 ) ) ;
V_20 . V_19 = ( short ) ( V_6 -> V_7 [ 1 ] & 0xFFFF ) ;
V_20 . V_29 . V_39 = 1 ;
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_18 ) ) ;
V_19 = ( short ) ( ( V_6 -> V_7 [ 3 ] >> 16 ) & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_17 , V_18 ) ) ;
V_19 = ( short ) ( V_6 -> V_7 [ 3 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_16 , V_18 ) ) ;
if ( V_6 -> V_7 [ 4 ] != 0 ) {
V_19 = ( short ) ( V_6 -> V_7 [ 4 ] & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_31 , V_18 ) ) ;
}
break;
default:
F_3 ( V_14 L_5 ) ;
return - V_15 ;
break;
}
return V_6 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_18 = F_2 ( V_6 -> V_10 ) ;
short V_19 ;
union V_20 V_20 ;
F_3 ( V_25 L_6 ,
V_18 ) ;
V_20 . V_19 = F_4 ( F_5 ( V_28 , V_18 ) ) ;
F_3 ( V_25 L_7 , V_20 . V_19 ) ;
switch ( V_22 -> V_23 [ V_18 ] . V_26 ) {
case V_27 :
F_3 ( V_25 L_8 ) ;
F_7 ( 0xFFFF & ( ( * V_7 ) >> 16 ) , F_5 ( V_17 ,
V_18 ) ) ;
F_7 ( 0xFFFF & ( * V_7 ) , F_5 ( V_16 , V_18 ) ) ;
break;
case V_38 :
F_3 ( V_25 L_9 ) ;
F_7 ( 0xFFFF & ( ( * V_7 ) >> 16 ) , F_5 ( V_17 ,
V_18 ) ) ;
F_7 ( 0xFFFF & ( * V_7 ) , F_5 ( V_16 , V_18 ) ) ;
break;
case V_41 :
F_3 ( V_25 L_10 ) ;
if ( ( V_6 -> V_7 [ 1 ] > V_6 -> V_7 [ 0 ] ) && ( V_6 -> V_7 [ 0 ] > 0 ) ) {
( V_22 -> V_23 [ V_18 ] ) . V_7 [ 0 ] =
V_6 -> V_7 [ 0 ] ;
( V_22 -> V_23 [ V_18 ] ) . V_7 [ 1 ] =
V_6 -> V_7 [ 1 ] ;
} else {
F_3 ( V_14 L_11 ,
V_6 -> V_7 [ 0 ] , V_6 -> V_7 [ 1 ] ) ;
return - V_15 ;
}
V_19 = ( short ) ( ( * V_7 >> 16 ) & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_17 , V_18 ) ) ;
V_19 = ( short ) ( * V_7 & 0xFFFF ) ;
F_7 ( V_19 , F_5 ( V_16 , V_18 ) ) ;
break;
default:
F_3
( L_12 ,
V_22 -> V_23 [ V_18 ] . V_26 ) ;
return - V_15 ;
break;
}
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_42 = - V_15 ;
if ( V_6 -> V_13 < 1 )
return V_42 ;
V_42 = V_6 -> V_13 ;
F_7 ( V_43 , F_10 ( V_44 ) ) ;
V_22 -> V_45 = ( V_7 [ 0 ] & 0x3FF ) << 5 ;
if ( V_7 [ 1 ] > 0 )
V_22 -> V_45 |= 0x8000 ;
V_22 -> V_45 |= 0x0001 ;
return V_42 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_13 , V_8 ;
int V_46 = F_2 ( V_6 -> V_10 ) ;
unsigned short V_19 ;
unsigned int V_47 ;
unsigned int V_48 ;
V_19 = ( V_22 -> V_45 & 0x8000 ) |
( ( 1 << 5 ) << V_46 ) | ( V_46 << 1 ) | 0x0001 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
F_7 ( V_19 , F_10 ( V_49 ) ) ;
#define F_12 100
for ( V_8 = 0 ; V_8 < F_12 ; V_8 ++ ) {
V_48 = F_4 ( F_10 ( V_50 ) ) ;
if ( V_48 & V_43 ) {
F_7 ( V_43 , F_10 ( V_50 ) ) ;
break;
}
}
if ( V_8 == F_12 ) {
F_3 ( V_14 L_13 ,
F_4 ( F_10 ( V_50 ) ) ) ;
return - V_51 ;
}
V_47 = F_4 ( F_10 ( V_52 ) ) ;
V_7 [ V_13 ] = V_47 ^ 0x8000 ;
}
return V_13 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_46 = F_2 ( V_6 -> V_10 ) ;
unsigned short V_53 ;
V_53 = V_46 << 1 ;
F_7 ( V_53 , F_10 ( V_54 ) ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_13 ; V_8 ++ ) {
F_7 ( V_7 [ V_8 ] , F_10 ( V_52 ) ) ;
V_22 -> V_55 [ V_46 ] = V_7 [ V_8 ] ;
F_7 ( V_53 + 1 , F_10 ( V_54 ) ) ;
}
return V_8 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_46 = F_2 ( V_6 -> V_10 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_13 ; V_8 ++ )
V_7 [ V_8 ] = V_22 -> V_55 [ V_46 ] ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_13 != 2 )
return - V_15 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_56 &= ~ V_7 [ 0 ] ;
V_4 -> V_56 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_7 ( V_4 -> V_56 , F_10 ( V_57 ) ) ;
}
V_7 [ 1 ] = F_4 ( F_10 ( V_57 ) ) & 0xFF ;
return 2 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_46 = F_2 ( V_6 -> V_10 ) ;
int V_58 , V_59 ;
F_3 ( V_25 L_14 ) ;
V_58 = V_46 >> 2 ;
V_59 = 0xF << ( V_58 << 2 ) ;
switch ( V_7 [ 0 ] ) {
case V_60 :
V_4 -> V_56 |= 1 << ( V_58 + 10 ) ;
V_4 -> V_61 |= V_59 ;
break;
case V_62 :
V_4 -> V_56 &= ~ ( 1 << ( V_58 + 10 ) ) ;
V_4 -> V_61 &= ~ V_59 ;
break;
case V_63 :
V_7 [ 1 ] = ( V_4 -> V_61 & V_59 ) ? V_64 : V_65 ;
return V_6 -> V_13 ;
default:
return - V_15 ;
}
F_7 ( V_4 -> V_56 , F_10 ( V_57 ) ) ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_3 * V_4 ;
int V_68 ;
int V_8 , V_13 ;
union V_20 V_20 ;
F_3 ( V_25 L_15 , V_2 -> V_69 ) ;
V_68 = V_67 -> V_70 [ 0 ] ;
if ( ! V_68 || ! F_18 ( V_68 , V_71 , V_72 -> V_73 ) ) {
F_19 ( V_2 , L_16 ) ;
return - V_74 ;
}
V_2 -> V_68 = V_68 ;
F_3 ( L_17 , V_2 -> V_68 ) ;
V_2 -> V_75 = & V_76 [ 0 ] ;
V_2 -> V_77 = V_72 -> V_73 ;
if ( F_20 ( V_2 , sizeof( struct V_78 ) ) < 0 )
return - V_79 ;
V_2 -> V_80 = 4 ;
if ( F_21 ( V_2 , V_2 -> V_80 ) < 0 )
return - V_79 ;
V_4 = V_2 -> V_81 + 0 ;
V_4 -> type = V_82 ;
V_4 -> V_83 = V_84 | V_85 | V_86 ;
V_4 -> V_87 = V_72 -> V_88 ;
V_4 -> V_89 = 0x00ffffff ;
V_4 -> V_90 = F_1 ;
V_4 -> V_91 = F_6 ;
V_4 -> V_92 = F_8 ;
V_4 = V_2 -> V_81 + 1 ;
V_4 -> type = V_93 ;
V_4 -> V_83 = V_84 | V_94 ;
V_4 -> V_87 = 10 ;
V_4 -> V_89 = 0xffff ;
V_4 -> V_95 = & V_96 ;
V_4 -> V_97 = 16 ;
V_4 -> V_90 = F_11 ;
V_4 -> V_91 = F_9 ;
V_4 = V_2 -> V_81 + 2 ;
V_4 -> type = V_98 ;
V_4 -> V_83 = V_85 ;
V_4 -> V_87 = 4 ;
V_4 -> V_89 = 0xffff ;
V_4 -> V_95 = & V_96 ;
V_4 -> V_92 = F_13 ;
V_4 -> V_90 = F_14 ;
V_4 = V_2 -> V_81 + 3 ;
if ( V_72 -> V_99 ) {
V_4 -> type = V_100 ;
V_4 -> V_83 = V_84 | V_85 ;
V_4 -> V_87 = 8 ;
V_4 -> V_89 = 1 ;
V_4 -> V_95 = & V_101 ;
V_4 -> V_102 = F_15 ;
V_4 -> V_91 = F_16 ;
} else {
V_4 -> type = V_103 ;
}
F_3 ( V_25 L_18 ) ;
return 1 ;
#if 0
cmReg.reg.coutSource = 0;
cmReg.reg.coutPolarity = 1;
cmReg.reg.autoLoadResetRcap = 1;
cmReg.reg.hwCtEnableSource = 3;
cmReg.reg.ctEnableCtrl = 2;
cmReg.reg.clockSource = 2;
cmReg.reg.countDir = 1;
cmReg.reg.countDirCtrl = 1;
cmReg.reg.outputRegLatchCtrl = 0;
cmReg.reg.preloadRegSel = 0;
cmReg.reg.reserved = 0;
outw(cmReg.value, ADDR_CHAN_REG(REG_C0M, subdev_channel));
outw(0x0001, ADDR_CHAN_REG(REG_C0H, subdev_channel));
outw(0x3C68, ADDR_CHAN_REG(REG_C0L, subdev_channel));
outw(0x8000, ADDR_CHAN_REG(REG_C0C, subdev_channel));
outw(0x4000, ADDR_CHAN_REG(REG_C0C, subdev_channel));
outw(0x0008, ADDR_CHAN_REG(REG_C0C, subdev_channel));
#else
V_20 . V_29 . V_104 = 0 ;
V_20 . V_29 . V_105 = 0 ;
V_20 . V_29 . V_30 = 0 ;
V_20 . V_29 . V_106 = 2 ;
V_20 . V_29 . V_107 = 1 ;
V_20 . V_29 . V_34 = 3 ;
V_20 . V_29 . V_108 = 0 ;
V_20 . V_29 . V_32 = 0 ;
V_20 . V_29 . V_109 = 0 ;
V_20 . V_29 . V_39 = 0 ;
V_20 . V_29 . V_110 = 0 ;
V_13 = 0 ;
F_3 ( V_25 L_19 ,
V_20 . V_19 , F_5 ( V_28 , V_13 ) ) ;
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_13 ) ) ;
F_22 ( 1000 ) ;
F_3 ( V_25 L_20 ,
F_4 ( F_5 ( V_28 , V_13 ) ) ) ;
if ( V_20 . V_29 . V_30 == 0 ) {
F_7 ( 0x8000 , F_5 ( V_31 , V_13 ) ) ;
F_7 ( 0x4000 , F_5 ( V_31 , V_13 ) ) ;
}
F_7 ( V_20 . V_19 , F_5 ( V_28 , V_13 ) ) ;
F_22 ( 1000 ) ;
F_3 ( V_25 L_20 ,
F_4 ( F_5 ( V_28 , V_13 ) ) ) ;
#endif
F_3 ( V_25 L_21 ) ;
for ( V_8 = 0 ; V_8 < V_111 ; V_8 ++ ) {
F_3 ( V_25 L_22 ,
F_10 ( V_112 [ V_8 ] ) , F_4 ( F_10 ( V_112 [ V_8 ] ) ) ) ;
}
return 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 > 0 )
F_24 ( V_2 -> V_68 , V_71 ) ;
}
