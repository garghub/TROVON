static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
int V_8 , V_9 ;
union V_10 V_10 ;
F_2 ( V_11 L_1 , V_2 -> V_12 ) ;
V_7 = V_4 -> V_13 [ 0 ] ;
if ( ! V_7 || ! F_3 ( V_7 , V_14 , V_15 -> V_16 ) ) {
F_4 ( V_2 , L_2 ) ;
return - V_17 ;
}
V_2 -> V_7 = V_7 ;
F_2 ( L_3 , V_2 -> V_7 ) ;
V_2 -> V_18 = & V_19 [ 0 ] ;
V_2 -> V_20 = V_15 -> V_16 ;
if ( F_5 ( V_2 , sizeof( struct V_21 ) ) < 0 )
return - V_22 ;
V_2 -> V_23 = 4 ;
if ( F_6 ( V_2 , V_2 -> V_23 ) < 0 )
return - V_22 ;
V_6 = V_2 -> V_24 + 0 ;
V_6 -> type = V_25 ;
V_6 -> V_26 = V_27 | V_28 | V_29 ;
V_6 -> V_30 = V_15 -> V_31 ;
V_6 -> V_32 = 0x00ffffff ;
V_6 -> V_33 = V_34 ;
V_6 -> V_35 = V_36 ;
V_6 -> V_37 = V_38 ;
V_6 = V_2 -> V_24 + 1 ;
V_6 -> type = V_39 ;
V_6 -> V_26 = V_27 | V_40 ;
V_6 -> V_30 = 10 ;
V_6 -> V_32 = 0xffff ;
V_6 -> V_41 = & V_42 ;
V_6 -> V_43 = 16 ;
V_6 -> V_33 = V_44 ;
V_6 -> V_35 = V_45 ;
V_6 = V_2 -> V_24 + 2 ;
V_6 -> type = V_46 ;
V_6 -> V_26 = V_28 ;
V_6 -> V_30 = 4 ;
V_6 -> V_32 = 0xffff ;
V_6 -> V_41 = & V_42 ;
V_6 -> V_37 = V_47 ;
V_6 -> V_33 = V_48 ;
V_6 = V_2 -> V_24 + 3 ;
if ( V_15 -> V_49 ) {
V_6 -> type = V_50 ;
V_6 -> V_26 = V_27 | V_28 ;
V_6 -> V_30 = 8 ;
V_6 -> V_32 = 1 ;
V_6 -> V_41 = & V_51 ;
V_6 -> V_52 = V_53 ;
V_6 -> V_35 = V_54 ;
} else {
V_6 -> type = V_55 ;
}
F_2 ( V_11 L_4 ) ;
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
V_10 . V_56 . V_57 = 0 ;
V_10 . V_56 . V_58 = 0 ;
V_10 . V_56 . V_59 = 0 ;
V_10 . V_56 . V_60 = 2 ;
V_10 . V_56 . V_61 = 1 ;
V_10 . V_56 . V_62 = 3 ;
V_10 . V_56 . V_63 = 0 ;
V_10 . V_56 . V_64 = 0 ;
V_10 . V_56 . V_65 = 0 ;
V_10 . V_56 . V_66 = 0 ;
V_10 . V_56 . V_67 = 0 ;
V_9 = 0 ;
F_2 ( V_11 L_5 ,
V_10 . V_68 , F_7 ( V_69 , V_9 ) ) ;
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_9 ) ) ;
F_9 ( 1000 ) ;
F_2 ( V_11 L_6 ,
F_10 ( F_7 ( V_69 , V_9 ) ) ) ;
if ( V_10 . V_56 . V_59 == 0 ) {
F_8 ( 0x8000 , F_7 ( V_70 , V_9 ) ) ;
F_8 ( 0x4000 , F_7 ( V_70 , V_9 ) ) ;
}
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_9 ) ) ;
F_9 ( 1000 ) ;
F_2 ( V_11 L_6 ,
F_10 ( F_7 ( V_69 , V_9 ) ) ) ;
#endif
F_2 ( V_11 L_7 ) ;
for ( V_8 = 0 ; V_8 < V_71 ; V_8 ++ ) {
F_2 ( V_11 L_8 ,
F_11 ( V_72 [ V_8 ] ) , F_10 ( F_11 ( V_72 [ V_8 ] ) ) ) ;
}
return 1 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_2 ( V_11 L_9 , V_2 -> V_12 ) ;
if ( V_2 -> V_7 > 0 )
F_13 ( V_2 -> V_7 , V_14 ) ;
return 0 ;
}
static int V_34 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_73 * V_74 ,
unsigned int * V_75 )
{
int V_8 ;
int V_76 = F_14 ( V_74 -> V_77 ) ;
unsigned short V_78 ;
unsigned short V_79 ;
if ( V_74 -> V_9 <= 0 ) {
F_2 ( V_80 L_10 ) ;
return - V_81 ;
}
for ( V_8 = 0 ; V_8 < V_74 -> V_9 ; V_8 ++ ) {
V_78 = F_10 ( F_7 ( V_82 , V_76 ) ) ;
V_79 = F_10 ( F_7 ( V_83 , V_76 ) ) ;
V_75 [ V_8 ] = ( int ) ( V_79 & 0x00FF ) ;
V_75 [ V_8 ] = ( V_75 [ V_8 ] << 16 ) | ( V_78 & 0xFFFF ) ;
}
return V_8 ;
}
static int V_36 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_73 * V_74 , unsigned int * V_75 )
{
int V_84 = F_14 ( V_74 -> V_77 ) ;
int V_8 ;
short V_68 ;
union V_10 V_10 ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
V_86 -> V_87 [ V_84 ] . V_75 [ V_8 ] =
V_74 -> V_75 [ V_8 ] ;
}
switch ( V_74 -> V_75 [ 0 ] ) {
case V_88 :
F_2 ( V_11 L_11 ) ;
V_86 -> V_87 [ V_84 ] . V_89 =
V_90 ;
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
V_10 . V_68 = V_74 -> V_75 [ 1 ] & 0xFFFF ;
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_84 ) ) ;
if ( V_10 . V_56 . V_59 == 0 ) {
F_8 ( 0x8000 , F_7 ( V_70 , V_84 ) ) ;
}
#else
V_10 . V_56 . V_64 = 0 ;
if ( V_74 -> V_75 [ 1 ] == V_91 )
V_10 . V_56 . V_62 = 1 ;
else if ( V_74 -> V_75 [ 1 ] == V_92 )
V_10 . V_56 . V_62 = 2 ;
else
V_10 . V_56 . V_62 = 0 ;
if ( V_74 -> V_75 [ 3 ] == V_93 )
V_10 . V_56 . V_59 = 4 ;
V_10 . V_68 = ( short ) ( V_74 -> V_75 [ 1 ] & 0xFFFF ) ;
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_84 ) ) ;
V_68 = ( short ) ( ( V_74 -> V_75 [ 2 ] >> 16 ) & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_83 , V_84 ) ) ;
V_68 = ( short ) ( V_74 -> V_75 [ 2 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_82 , V_84 ) ) ;
if ( V_74 -> V_75 [ 3 ] != 0 ) {
V_68 = ( short ) ( V_74 -> V_75 [ 3 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_70 , V_84 ) ) ;
}
if ( V_10 . V_56 . V_59 == 0 ) {
F_8 ( 0x8000 , F_7 ( V_70 , V_84 ) ) ;
F_8 ( 0x4000 , F_7 ( V_70 , V_84 ) ) ;
}
#endif
break;
case V_94 :
F_2 ( V_11 L_12 ) ;
V_86 -> V_87 [ V_84 ] . V_89 =
V_95 ;
V_10 . V_68 = ( short ) ( V_74 -> V_75 [ 1 ] & 0xFFFF ) ;
V_10 . V_56 . V_66 = 0 ;
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_84 ) ) ;
V_68 = ( short ) ( ( V_74 -> V_75 [ 2 ] >> 16 ) & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_83 , V_84 ) ) ;
V_68 = ( short ) ( V_74 -> V_75 [ 2 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_82 , V_84 ) ) ;
V_10 . V_68 = ( short ) ( V_74 -> V_75 [ 1 ] & 0xFFFF ) ;
V_10 . V_56 . V_66 = 1 ;
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_84 ) ) ;
V_68 = ( short ) ( ( V_74 -> V_75 [ 3 ] >> 16 ) & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_83 , V_84 ) ) ;
V_68 = ( short ) ( V_74 -> V_75 [ 3 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_82 , V_84 ) ) ;
if ( V_74 -> V_75 [ 4 ] != 0 ) {
V_68 = ( short ) ( V_74 -> V_75 [ 4 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_70 , V_84 ) ) ;
}
break;
case V_96 :
F_2 ( V_11 L_13 ) ;
V_86 -> V_87 [ V_84 ] . V_89 =
V_97 ;
V_10 . V_68 = ( short ) ( V_74 -> V_75 [ 1 ] & 0xFFFF ) ;
V_10 . V_56 . V_66 = 0 ;
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_84 ) ) ;
V_68 = ( short ) ( ( V_74 -> V_75 [ 2 ] >> 16 ) & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_83 , V_84 ) ) ;
V_68 = ( short ) ( V_74 -> V_75 [ 2 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_82 , V_84 ) ) ;
V_10 . V_68 = ( short ) ( V_74 -> V_75 [ 1 ] & 0xFFFF ) ;
V_10 . V_56 . V_66 = 1 ;
F_8 ( V_10 . V_68 , F_7 ( V_69 , V_84 ) ) ;
V_68 = ( short ) ( ( V_74 -> V_75 [ 3 ] >> 16 ) & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_83 , V_84 ) ) ;
V_68 = ( short ) ( V_74 -> V_75 [ 3 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_82 , V_84 ) ) ;
if ( V_74 -> V_75 [ 4 ] != 0 ) {
V_68 = ( short ) ( V_74 -> V_75 [ 4 ] & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_70 , V_84 ) ) ;
}
break;
default:
F_2 ( V_80 L_14 ) ;
return - V_81 ;
break;
}
return V_74 -> V_9 ;
}
static int V_38 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_73 * V_74 ,
unsigned int * V_75 )
{
int V_84 = F_14 ( V_74 -> V_77 ) ;
short V_68 ;
union V_10 V_10 ;
F_2 ( V_11 L_15 ,
V_84 ) ;
V_10 . V_68 = F_10 ( F_7 ( V_69 , V_84 ) ) ;
F_2 ( V_11 L_16 , V_10 . V_68 ) ;
switch ( V_86 -> V_87 [ V_84 ] . V_89 ) {
case V_90 :
F_2 ( V_11 L_17 ) ;
F_8 ( 0xFFFF & ( ( * V_75 ) >> 16 ) , F_7 ( V_83 ,
V_84 ) ) ;
F_8 ( 0xFFFF & ( * V_75 ) , F_7 ( V_82 , V_84 ) ) ;
break;
case V_95 :
F_2 ( V_11 L_18 ) ;
F_8 ( 0xFFFF & ( ( * V_75 ) >> 16 ) , F_7 ( V_83 ,
V_84 ) ) ;
F_8 ( 0xFFFF & ( * V_75 ) , F_7 ( V_82 , V_84 ) ) ;
break;
case V_97 :
F_2 ( V_11 L_19 ) ;
if ( ( V_74 -> V_75 [ 1 ] > V_74 -> V_75 [ 0 ] ) && ( V_74 -> V_75 [ 0 ] > 0 ) ) {
( V_86 -> V_87 [ V_84 ] ) . V_75 [ 0 ] =
V_74 -> V_75 [ 0 ] ;
( V_86 -> V_87 [ V_84 ] ) . V_75 [ 1 ] =
V_74 -> V_75 [ 1 ] ;
} else {
F_2 ( V_80 L_20 ,
V_74 -> V_75 [ 0 ] , V_74 -> V_75 [ 1 ] ) ;
return - V_81 ;
}
V_68 = ( short ) ( ( * V_75 >> 16 ) & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_83 , V_84 ) ) ;
V_68 = ( short ) ( * V_75 & 0xFFFF ) ;
F_8 ( V_68 , F_7 ( V_82 , V_84 ) ) ;
break;
default:
F_2
( L_21 ,
V_86 -> V_87 [ V_84 ] . V_89 ) ;
return - V_81 ;
break;
}
return V_74 -> V_9 ;
}
static int V_45 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_73 * V_74 , unsigned int * V_75 )
{
int V_98 = - V_81 ;
if ( V_74 -> V_9 < 1 )
return V_98 ;
V_98 = V_74 -> V_9 ;
F_8 ( V_99 , F_11 ( V_100 ) ) ;
V_86 -> V_101 = ( V_75 [ 0 ] & 0x3FF ) << 5 ;
if ( V_75 [ 1 ] > 0 )
V_86 -> V_101 |= 0x8000 ;
V_86 -> V_101 |= 0x0001 ;
return V_98 ;
}
static int V_44 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_73 * V_74 , unsigned int * V_75 )
{
int V_9 , V_8 ;
int V_102 = F_14 ( V_74 -> V_77 ) ;
unsigned short V_68 ;
unsigned int V_103 ;
unsigned int V_104 ;
V_68 = ( V_86 -> V_101 & 0x8000 ) |
( ( 1 << 5 ) << V_102 ) | ( V_102 << 1 ) | 0x0001 ;
for ( V_9 = 0 ; V_9 < V_74 -> V_9 ; V_9 ++ ) {
F_8 ( V_68 , F_11 ( V_105 ) ) ;
#define F_15 100
for ( V_8 = 0 ; V_8 < F_15 ; V_8 ++ ) {
V_104 = F_10 ( F_11 ( V_106 ) ) ;
if ( V_104 & V_99 ) {
F_8 ( V_99 , F_11 ( V_106 ) ) ;
break;
}
}
if ( V_8 == F_15 ) {
F_2 ( V_80 L_22 ,
F_10 ( F_11 ( V_106 ) ) ) ;
return - V_107 ;
}
V_103 = F_10 ( F_11 ( V_108 ) ) ;
V_75 [ V_9 ] = V_103 ^ 0x8000 ;
}
return V_9 ;
}
static int V_47 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_73 * V_74 , unsigned int * V_75 )
{
int V_8 ;
int V_102 = F_14 ( V_74 -> V_77 ) ;
unsigned short V_109 ;
V_109 = V_102 << 1 ;
F_8 ( V_109 , F_11 ( V_110 ) ) ;
for ( V_8 = 0 ; V_8 < V_74 -> V_9 ; V_8 ++ ) {
F_8 ( V_75 [ V_8 ] , F_11 ( V_108 ) ) ;
V_86 -> V_111 [ V_102 ] = V_75 [ V_8 ] ;
F_8 ( V_109 + 1 , F_11 ( V_110 ) ) ;
}
return V_8 ;
}
static int V_48 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_73 * V_74 , unsigned int * V_75 )
{
int V_8 ;
int V_102 = F_14 ( V_74 -> V_77 ) ;
for ( V_8 = 0 ; V_8 < V_74 -> V_9 ; V_8 ++ )
V_75 [ V_8 ] = V_86 -> V_111 [ V_102 ] ;
return V_8 ;
}
static int V_53 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_73 * V_74 , unsigned int * V_75 )
{
if ( V_74 -> V_9 != 2 )
return - V_81 ;
if ( V_75 [ 0 ] ) {
V_6 -> V_112 &= ~ V_75 [ 0 ] ;
V_6 -> V_112 |= V_75 [ 0 ] & V_75 [ 1 ] ;
F_8 ( V_6 -> V_112 , F_11 ( V_113 ) ) ;
}
V_75 [ 1 ] = F_10 ( F_11 ( V_113 ) ) & 0xFF ;
return 2 ;
}
static int V_54 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_73 * V_74 , unsigned int * V_75 )
{
int V_102 = F_14 ( V_74 -> V_77 ) ;
int V_114 , V_115 ;
F_2 ( V_11 L_23 ) ;
V_114 = V_102 >> 2 ;
V_115 = 0xF << ( V_114 << 2 ) ;
switch ( V_75 [ 0 ] ) {
case V_116 :
V_6 -> V_112 |= 1 << ( V_114 + 10 ) ;
V_6 -> V_117 |= V_115 ;
break;
case V_118 :
V_6 -> V_112 &= ~ ( 1 << ( V_114 + 10 ) ) ;
V_6 -> V_117 &= ~ V_115 ;
break;
case V_119 :
V_75 [ 1 ] = ( V_6 -> V_117 & V_115 ) ? V_120 : V_121 ;
return V_74 -> V_9 ;
default:
return - V_81 ;
}
F_8 ( V_6 -> V_112 , F_11 ( V_113 ) ) ;
return 1 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_122 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_122 ) ;
}
