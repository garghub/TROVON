static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned long V_10 = V_2 -> V_11 + V_8 * 8 ;
unsigned int V_12 ;
unsigned int V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_15 ; V_14 ++ ) {
V_12 = F_3 ( V_10 + V_16 ) & 0xffff ;
V_13 = F_3 ( V_10 + V_17 ) & 0xff ;
V_7 [ V_14 ] = ( V_13 << 16 ) | V_12 ;
}
return V_6 -> V_15 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned long V_10 = V_2 -> V_11 + V_8 * 8 ;
unsigned int V_21 ;
union V_22 V_22 ;
switch ( V_7 [ 0 ] ) {
case V_23 :
V_19 -> V_24 [ V_8 ] = V_7 [ 0 ] ;
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
outw(cmReg.value, chan_iobase + REG_C0M);
outw(0x0001, chan_iobase + REG_C0H);
outw(0x3C68, chan_iobase + REG_C0L);
outw(0x8000, chan_iobase + REG_C0C);
outw(0x4000, chan_iobase + REG_C0C);
outw(0x0008, chan_iobase + REG_C0C);
#endif
#if 1
V_22 . V_25 = V_7 [ 1 ] & 0xffff ;
F_5 ( V_22 . V_25 , V_10 + V_26 ) ;
if ( V_22 . V_27 . V_28 == 0 ) {
F_5 ( 0x8000 , V_10 + V_29 ) ;
}
#else
V_22 . V_27 . V_30 = 0 ;
if ( V_7 [ 1 ] == V_31 )
V_22 . V_27 . V_32 = 1 ;
else if ( V_7 [ 1 ] == V_33 )
V_22 . V_27 . V_32 = 2 ;
else
V_22 . V_27 . V_32 = 0 ;
if ( V_7 [ 3 ] == V_34 )
V_22 . V_27 . V_28 = 4 ;
V_22 . V_25 = V_7 [ 1 ] & 0xffff ;
F_5 ( V_22 . V_25 , V_10 + V_26 ) ;
V_21 = ( V_7 [ 2 ] >> 16 ) & 0xffff ;
F_5 ( V_21 , V_10 + V_17 ) ;
V_21 = V_7 [ 2 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_16 ) ;
if ( V_7 [ 3 ] ) {
V_21 = V_7 [ 3 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_29 ) ;
}
if ( V_22 . V_27 . V_28 == 0 ) {
F_5 ( 0x8000 , V_10 + V_29 ) ;
F_5 ( 0x4000 , V_10 + V_29 ) ;
}
#endif
break;
case V_35 :
V_19 -> V_24 [ V_8 ] = V_7 [ 0 ] ;
V_22 . V_25 = V_7 [ 1 ] & 0xffff ;
V_22 . V_27 . V_36 = 0 ;
F_5 ( V_22 . V_25 , V_10 + V_26 ) ;
V_21 = ( V_7 [ 2 ] >> 16 ) & 0xffff ;
F_5 ( V_21 , V_10 + V_17 ) ;
V_21 = V_7 [ 2 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_16 ) ;
V_22 . V_25 = V_7 [ 1 ] & 0xffff ;
V_22 . V_27 . V_36 = 1 ;
F_5 ( V_22 . V_25 , V_10 + V_26 ) ;
V_21 = ( V_7 [ 3 ] >> 16 ) & 0xffff ;
F_5 ( V_21 , V_10 + V_17 ) ;
V_21 = V_7 [ 3 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_16 ) ;
if ( V_7 [ 4 ] ) {
V_21 = V_7 [ 4 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_29 ) ;
}
break;
case V_37 :
V_19 -> V_24 [ V_8 ] = V_7 [ 0 ] ;
V_22 . V_25 = V_7 [ 1 ] & 0xffff ;
V_22 . V_27 . V_36 = 0 ;
F_5 ( V_22 . V_25 , V_10 + V_26 ) ;
V_21 = ( V_7 [ 2 ] >> 16 ) & 0xffff ;
F_5 ( V_21 , V_10 + V_17 ) ;
V_21 = V_7 [ 2 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_16 ) ;
V_22 . V_25 = V_7 [ 1 ] & 0xffff ;
V_22 . V_27 . V_36 = 1 ;
F_5 ( V_22 . V_25 , V_10 + V_26 ) ;
V_21 = ( V_7 [ 3 ] >> 16 ) & 0xffff ;
F_5 ( V_21 , V_10 + V_17 ) ;
V_21 = V_7 [ 3 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_16 ) ;
if ( V_7 [ 4 ] ) {
V_21 = V_7 [ 4 ] & 0xffff ;
F_5 ( V_21 , V_10 + V_29 ) ;
}
break;
default:
return - V_38 ;
break;
}
return V_6 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned long V_10 = V_2 -> V_11 + V_8 * 8 ;
F_3 ( V_10 + V_26 ) ;
switch ( V_19 -> V_24 [ V_8 ] ) {
case V_37 :
if ( ( V_7 [ 1 ] <= V_7 [ 0 ] ) || ! V_7 [ 0 ] )
return - V_38 ;
case V_23 :
case V_35 :
F_5 ( ( V_7 [ 0 ] >> 16 ) & 0xffff , V_10 + V_17 ) ;
F_5 ( V_7 [ 0 ] & 0xffff , V_10 + V_16 ) ;
break;
default:
return - V_38 ;
}
return V_6 -> V_15 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
int V_39 = - V_38 ;
if ( V_6 -> V_15 < 1 )
return V_39 ;
V_39 = V_6 -> V_15 ;
F_5 ( V_40 , V_2 -> V_11 + V_41 ) ;
V_19 -> V_42 = ( V_7 [ 0 ] & 0x3ff ) << 5 ;
if ( V_7 [ 1 ] > 0 )
V_19 -> V_42 |= 0x8000 ;
V_19 -> V_42 |= 0x0001 ;
return V_39 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
int V_15 , V_14 ;
unsigned short V_25 ;
unsigned int V_43 ;
unsigned int V_44 ;
V_25 = ( V_19 -> V_42 & 0x8000 ) |
( ( 1 << 5 ) << V_8 ) | ( V_8 << 1 ) | 0x0001 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
F_5 ( V_25 , V_2 -> V_11 + V_45 ) ;
#define F_9 100
for ( V_14 = 0 ; V_14 < F_9 ; V_14 ++ ) {
V_44 = F_3 ( V_2 -> V_11 + V_46 ) ;
if ( V_44 & V_40 ) {
F_5 ( V_40 , V_2 -> V_11 + V_46 ) ;
break;
}
}
if ( V_14 == F_9 )
return - V_47 ;
V_43 = F_3 ( V_2 -> V_11 + V_48 ) ;
V_7 [ V_15 ] = V_43 ^ 0x8000 ;
}
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned short V_21 ;
int V_14 ;
V_21 = V_8 << 1 ;
F_5 ( V_21 , V_2 -> V_11 + V_49 ) ;
for ( V_14 = 0 ; V_14 < V_6 -> V_15 ; V_14 ++ ) {
F_5 ( V_7 [ V_14 ] , V_2 -> V_11 + V_48 ) ;
V_19 -> V_50 [ V_8 ] = V_7 [ V_14 ] ;
F_5 ( V_21 + 1 , V_2 -> V_11 + V_49 ) ;
}
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_15 ; V_14 ++ )
V_7 [ V_14 ] = V_19 -> V_50 [ V_8 ] ;
return V_14 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_51 &= ~ V_7 [ 0 ] ;
V_4 -> V_51 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_5 ( V_4 -> V_51 , V_2 -> V_11 + V_52 ) ;
}
V_7 [ 1 ] = F_3 ( V_2 -> V_11 + V_52 ) & 0xff ;
return V_6 -> V_15 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_53 ;
int V_54 ;
if ( V_8 < 4 )
V_53 = 0x0f ;
else
V_53 = 0xf0 ;
V_54 = F_14 ( V_2 , V_4 , V_6 , V_7 , V_53 ) ;
if ( V_54 )
return V_54 ;
if ( V_4 -> V_55 & 0x0f )
V_4 -> V_51 |= ( 1 << 10 ) ;
else
V_4 -> V_51 &= ~ ( 1 << 10 ) ;
if ( V_4 -> V_55 & 0xf0 )
V_4 -> V_51 |= ( 1 << 11 ) ;
else
V_4 -> V_51 &= ~ ( 1 << 11 ) ;
F_5 ( V_4 -> V_51 , V_2 -> V_11 + V_52 ) ;
return V_6 -> V_15 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_18 * V_19 ;
struct V_3 * V_4 ;
int V_54 ;
V_54 = F_16 ( V_2 , V_57 -> V_58 [ 0 ] , V_59 ) ;
if ( V_54 )
return V_54 ;
V_19 = F_17 ( V_2 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_60 ;
V_54 = F_18 ( V_2 , 4 ) ;
if ( V_54 )
return V_54 ;
V_4 = & V_2 -> V_61 [ 0 ] ;
V_4 -> type = V_62 ;
V_4 -> V_63 = V_64 | V_65 | V_66 ;
V_4 -> V_67 = 4 ;
V_4 -> V_68 = 0x00ffffff ;
V_4 -> V_69 = F_1 ;
V_4 -> V_70 = F_4 ;
V_4 -> V_71 = F_6 ;
V_4 = & V_2 -> V_61 [ 1 ] ;
V_4 -> type = V_72 ;
V_4 -> V_63 = V_64 | V_73 ;
V_4 -> V_67 = 10 ;
V_4 -> V_68 = 0xffff ;
V_4 -> V_74 = & V_75 ;
V_4 -> V_76 = 16 ;
V_4 -> V_69 = F_8 ;
V_4 -> V_70 = F_7 ;
V_4 = & V_2 -> V_61 [ 2 ] ;
V_4 -> type = V_77 ;
V_4 -> V_63 = V_65 ;
V_4 -> V_67 = 4 ;
V_4 -> V_68 = 0xffff ;
V_4 -> V_74 = & V_75 ;
V_4 -> V_71 = F_10 ;
V_4 -> V_69 = F_11 ;
V_4 = & V_2 -> V_61 [ 3 ] ;
V_4 -> type = V_78 ;
V_4 -> V_63 = V_64 | V_65 ;
V_4 -> V_67 = 8 ;
V_4 -> V_68 = 1 ;
V_4 -> V_74 = & V_79 ;
V_4 -> V_80 = F_12 ;
V_4 -> V_70 = F_13 ;
return 1 ;
}
