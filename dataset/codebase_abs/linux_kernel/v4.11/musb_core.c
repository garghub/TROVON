static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
enum V_4 F_3 ( struct V_2 * V_3 )
{
enum V_5 V_6 ;
V_6 = F_4 ( V_3 ) ;
switch ( V_6 ) {
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
case V_12 :
default:
return V_13 ;
}
}
static int F_5 ( struct V_14 * V_15 , T_1 V_16 )
{
void T_2 * V_17 = V_15 -> V_18 ;
int V_19 = 0 ;
T_3 V_20 ;
T_3 V_21 ;
int V_22 ;
F_6 ( V_15 -> V_23 ) ;
V_21 = F_7 ( V_17 , V_24 ) ;
V_21 &= ~ V_25 ;
F_8 ( V_17 , V_24 , V_21 ) ;
F_8 ( V_17 , V_26 , ( T_3 ) V_16 ) ;
F_8 ( V_17 , V_27 ,
V_28 | V_29 ) ;
while ( ! ( F_7 ( V_17 , V_27 )
& V_30 ) ) {
V_19 ++ ;
if ( V_19 == 10000 ) {
V_22 = - V_31 ;
goto V_32;
}
}
V_20 = F_7 ( V_17 , V_27 ) ;
V_20 &= ~ V_30 ;
F_8 ( V_17 , V_27 , V_20 ) ;
V_22 = F_7 ( V_17 , V_33 ) ;
V_32:
F_9 ( V_15 -> V_23 ) ;
return V_22 ;
}
static int F_10 ( struct V_14 * V_15 , T_1 V_34 , T_1 V_16 )
{
void T_2 * V_17 = V_15 -> V_18 ;
int V_19 = 0 ;
T_3 V_20 = 0 ;
T_3 V_21 ;
int V_22 = 0 ;
F_6 ( V_15 -> V_23 ) ;
V_21 = F_7 ( V_17 , V_24 ) ;
V_21 &= ~ V_25 ;
F_8 ( V_17 , V_24 , V_21 ) ;
F_8 ( V_17 , V_26 , ( T_3 ) V_16 ) ;
F_8 ( V_17 , V_33 , ( T_3 ) V_34 ) ;
F_8 ( V_17 , V_27 , V_28 ) ;
while ( ! ( F_7 ( V_17 , V_27 )
& V_30 ) ) {
V_19 ++ ;
if ( V_19 == 10000 ) {
V_22 = - V_31 ;
goto V_32;
}
}
V_20 = F_7 ( V_17 , V_27 ) ;
V_20 &= ~ V_30 ;
F_8 ( V_17 , V_27 , V_20 ) ;
V_32:
F_9 ( V_15 -> V_23 ) ;
return V_22 ;
}
static T_1 F_11 ( T_3 V_35 )
{
return 0x20 + ( V_35 * 4 ) ;
}
static void F_12 ( void T_2 * V_36 , T_3 V_35 )
{
}
static T_1 F_13 ( T_3 V_35 , T_4 V_37 )
{
return 0x100 + ( 0x10 * V_35 ) + V_37 ;
}
static void F_14 ( void T_2 * V_36 , T_3 V_35 )
{
F_8 ( V_36 , V_38 , V_35 ) ;
}
static T_1 F_15 ( T_3 V_35 , T_4 V_37 )
{
return 0x10 + V_37 ;
}
static T_1 F_16 ( T_3 V_35 , T_4 V_37 )
{
return 0x80 + ( 0x08 * V_35 ) + V_37 ;
}
static T_3 F_17 ( const void T_2 * V_17 , unsigned V_37 )
{
T_3 V_39 = F_18 ( V_17 + V_37 ) ;
F_19 ( F_20 ( 0 ) , V_17 , V_37 , V_39 ) ;
return V_39 ;
}
static void F_21 ( void T_2 * V_17 , unsigned V_37 , T_3 V_39 )
{
F_22 ( F_20 ( 0 ) , V_17 , V_37 , V_39 ) ;
F_23 ( V_39 , V_17 + V_37 ) ;
}
static T_4 F_24 ( const void T_2 * V_17 , unsigned V_37 )
{
T_4 V_39 = F_25 ( V_17 + V_37 ) ;
F_26 ( F_20 ( 0 ) , V_17 , V_37 , V_39 ) ;
return V_39 ;
}
static void F_27 ( void T_2 * V_17 , unsigned V_37 , T_4 V_39 )
{
F_28 ( F_20 ( 0 ) , V_17 , V_37 , V_39 ) ;
F_29 ( V_39 , V_17 + V_37 ) ;
}
static T_1 F_30 ( const void T_2 * V_17 , unsigned V_37 )
{
T_1 V_39 = F_31 ( V_17 + V_37 ) ;
F_32 ( F_20 ( 0 ) , V_17 , V_37 , V_39 ) ;
return V_39 ;
}
static void F_33 ( void T_2 * V_17 , unsigned V_37 , T_1 V_39 )
{
F_34 ( F_20 ( 0 ) , V_17 , V_37 , V_39 ) ;
F_35 ( V_39 , V_17 + V_37 ) ;
}
static void F_36 ( struct V_40 * V_41 , T_4 V_42 ,
const T_3 * V_43 )
{
struct V_1 * V_1 = V_41 -> V_1 ;
void T_2 * V_44 = V_41 -> V_44 ;
if ( F_37 ( V_42 == 0 ) )
return;
F_38 ( ( T_3 * ) V_43 ) ;
F_39 ( V_1 -> V_45 , L_1 ,
'T' , V_41 -> V_35 , V_44 , V_42 , V_43 ) ;
if ( F_40 ( ( 0x01 & ( unsigned long ) V_43 ) == 0 ) ) {
T_4 V_46 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_43 ) == 0 ) {
if ( V_42 >= 4 ) {
F_41 ( V_44 , V_43 + V_46 , V_42 >> 2 ) ;
V_46 += V_42 & ~ 0x03 ;
}
if ( V_42 & 0x02 ) {
F_29 ( * ( T_4 * ) & V_43 [ V_46 ] , V_44 ) ;
V_46 += 2 ;
}
} else {
if ( V_42 >= 2 ) {
F_42 ( V_44 , V_43 + V_46 , V_42 >> 1 ) ;
V_46 += V_42 & ~ 0x01 ;
}
}
if ( V_42 & 0x01 )
F_23 ( V_43 [ V_46 ] , V_44 ) ;
} else {
F_43 ( V_44 , V_43 , V_42 ) ;
}
}
static void F_44 ( struct V_40 * V_41 , T_4 V_42 , T_3 * V_47 )
{
struct V_1 * V_1 = V_41 -> V_1 ;
void T_2 * V_44 = V_41 -> V_44 ;
if ( F_37 ( V_42 == 0 ) )
return;
F_39 ( V_1 -> V_45 , L_1 ,
'R' , V_41 -> V_35 , V_44 , V_42 , V_47 ) ;
if ( F_40 ( ( 0x01 & ( unsigned long ) V_47 ) == 0 ) ) {
T_4 V_46 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_47 ) == 0 ) {
if ( V_42 >= 4 ) {
F_45 ( V_44 , V_47 , V_42 >> 2 ) ;
V_46 = V_42 & ~ 0x03 ;
}
if ( V_42 & 0x02 ) {
* ( T_4 * ) & V_47 [ V_46 ] = F_25 ( V_44 ) ;
V_46 += 2 ;
}
} else {
if ( V_42 >= 2 ) {
F_46 ( V_44 , V_47 , V_42 >> 1 ) ;
V_46 = V_42 & ~ 0x01 ;
}
}
if ( V_42 & 0x01 )
V_47 [ V_46 ] = F_18 ( V_44 ) ;
} else {
F_47 ( V_44 , V_47 , V_42 ) ;
}
}
void F_48 ( struct V_40 * V_41 , T_4 V_42 , T_3 * V_47 )
{
return V_41 -> V_1 -> V_48 . V_49 ( V_41 , V_42 , V_47 ) ;
}
void F_49 ( struct V_40 * V_41 , T_4 V_42 , const T_3 * V_43 )
{
return V_41 -> V_1 -> V_48 . V_50 ( V_41 , V_42 , V_43 ) ;
}
void F_50 ( struct V_1 * V_1 )
{
void T_2 * V_51 = V_1 -> V_52 [ 0 ] . V_51 ;
F_51 ( V_1 -> V_53 , 0 ) ;
F_49 ( V_1 -> V_54 ,
sizeof( V_55 ) , V_55 ) ;
F_52 ( V_51 , V_56 , V_57 ) ;
}
static void F_53 ( unsigned long V_39 )
{
struct V_1 * V_1 = (struct V_1 * ) V_39 ;
unsigned long V_58 ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_63 :
F_55 ( V_1 ,
L_2 ) ;
F_56 ( V_1 ) ;
V_1 -> V_60 -> V_61 -> V_62 = V_64 ;
V_1 -> V_65 = 0 ;
break;
case V_66 :
case V_67 :
F_55 ( V_1 , L_3 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
F_58 ( V_1 , 0 ) ;
V_1 -> V_60 -> V_61 -> V_62 = V_68 ;
break;
default:
F_55 ( V_1 , L_4 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
}
F_59 ( & V_1 -> V_59 , V_58 ) ;
}
void F_60 ( struct V_1 * V_1 )
{
struct V_69 * V_70 = V_1 -> V_70 ;
void T_2 * V_36 = V_1 -> V_53 ;
T_3 V_16 ;
F_55 ( V_1 , L_5 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_71 :
F_56 ( V_1 ) ;
F_55 ( V_1 , L_6 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
break;
case V_72 :
F_55 ( V_1 , L_7 ) ;
if ( V_70 )
V_70 -> V_73 . V_74 = 0 ;
V_1 -> V_60 -> V_61 -> V_62 = V_64 ;
F_61 ( V_1 ) ;
V_16 = F_7 ( V_36 , V_24 ) ;
V_16 |= V_25 ;
F_8 ( V_36 , V_24 , V_16 ) ;
break;
default:
F_55 ( V_1 , L_8 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
}
V_1 -> V_75 &= ~ ( V_76 << 16 ) ;
}
static T_5 F_62 ( struct V_1 * V_1 , T_3 V_77 ,
T_3 V_78 )
{
T_5 V_79 = V_80 ;
F_55 ( V_1 , L_9 , V_78 , V_77 ) ;
if ( V_77 & V_81 ) {
V_79 = V_82 ;
F_55 ( V_1 , L_10 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
if ( V_78 & V_83 ) {
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_66 :
V_1 -> V_75 |=
( V_84 << 16 )
| V_85 ;
V_1 -> V_86 = V_87
+ F_63 ( V_88 ) ;
V_1 -> V_60 -> V_61 -> V_62 = V_89 ;
V_1 -> V_65 = 1 ;
F_64 ( V_1 ) ;
F_65 ( & V_1 -> V_90 ,
F_63 ( V_88 ) ) ;
break;
case V_63 :
V_1 -> V_60 -> V_61 -> V_62 = V_64 ;
V_1 -> V_65 = 1 ;
F_61 ( V_1 ) ;
break;
default:
F_66 ( L_11 ,
L_12 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
}
} else {
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_66 :
V_1 -> V_60 -> V_61 -> V_62 = V_89 ;
F_64 ( V_1 ) ;
break;
case V_63 :
case V_64 :
if ( ( V_78 & V_91 )
!= ( 3 << V_92 )
) {
V_1 -> V_77 |= V_93 ;
V_1 -> V_77 &= ~ V_94 ;
break;
}
F_67 ( V_1 ) ;
break;
case V_95 :
V_1 -> V_77 &= ~ V_94 ;
break;
default:
F_66 ( L_11 ,
L_13 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
}
}
}
if ( V_77 & V_96 ) {
void T_2 * V_36 = V_1 -> V_53 ;
if ( ( V_78 & V_91 ) == V_91
&& ( V_78 & V_97 ) ) {
F_55 ( V_1 , L_14 ) ;
return V_82 ;
}
F_55 ( V_1 , L_15 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
F_8 ( V_36 , V_98 , V_99 ) ;
V_1 -> V_100 = V_101 ;
V_1 -> V_60 -> V_61 -> V_62 = V_102 ;
F_68 ( V_1 ) ;
F_58 ( V_1 , 1 ) ;
V_79 = V_82 ;
}
if ( V_77 & V_103 ) {
int V_104 = 0 ;
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_89 :
case V_67 :
case V_105 :
if ( V_1 -> V_106 ) {
void T_2 * V_36 = V_1 -> V_53 ;
V_1 -> V_106 -- ;
V_104 = 1 ;
V_78 |= V_99 ;
F_8 ( V_36 , V_98 , V_78 ) ;
} else {
V_1 -> V_75 |=
V_107
| ( V_108 << 16 ) ;
}
break;
default:
break;
}
F_69 (ignore ? KERN_DEBUG : KERN_ERR, musb->controller,
L_16 ,
usb_otg_state_string(musb->xceiv->otg->state),
devctl,
({ char *s;
switch (devctl & MUSB_DEVCTL_VBUS) {
case 0 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_17; break;
case 1 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_18; break;
case 2 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_19; break;
default:
s = L_20; break;
} s; }),
VBUSERR_RETRY_COUNT - musb->vbuserr_retry,
musb->port1_status) ;
if ( ! V_104 )
F_58 ( V_1 , 0 ) ;
V_79 = V_82 ;
}
if ( V_77 & V_94 ) {
F_55 ( V_1 , L_21 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) , V_78 ) ;
V_79 = V_82 ;
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_71 :
F_60 ( V_1 ) ;
F_64 ( V_1 ) ;
F_70 ( V_1 ) ;
F_71 ( V_1 , V_87
+ F_63 ( V_1 -> V_109
? : V_110 ) ) ;
break;
case V_95 :
if ( ! V_1 -> V_65 )
break;
case V_64 :
F_72 ( V_1 ) ;
V_1 -> V_65 = V_1 -> V_111 . V_112 ;
if ( V_1 -> V_65 ) {
V_1 -> V_60 -> V_61 -> V_62 = V_63 ;
F_55 ( V_1 , L_22 ) ;
F_73 ( & V_1 -> V_113 , V_87
+ F_63 (
V_114 ) ) ;
}
break;
case V_67 :
if ( V_1 -> V_109 != 0 )
F_71 ( V_1 , V_87
+ F_63 ( V_1 -> V_109 ) ) ;
break;
case V_89 :
V_1 -> V_60 -> V_61 -> V_62 = V_66 ;
V_1 -> V_65 = V_1 -> V_70 -> V_73 . V_112 ;
break;
case V_72 :
F_55 ( V_1 , L_23 ) ;
break;
default:
V_1 -> V_65 = 0 ;
break;
}
}
if ( V_77 & V_115 ) {
struct V_69 * V_70 = V_1 -> V_70 ;
V_79 = V_82 ;
V_1 -> V_65 = 1 ;
V_1 -> V_100 = V_101 ;
V_1 -> V_116 = V_1 -> V_117 ;
F_52 ( V_1 -> V_53 , V_118 , V_1 -> V_116 ) ;
V_1 -> V_119 = V_1 -> V_117 & 0xfffe ;
F_52 ( V_1 -> V_53 , V_120 , V_1 -> V_119 ) ;
F_8 ( V_1 -> V_53 , V_121 , 0xf7 ) ;
V_1 -> V_75 &= ~ ( V_122
| V_123
| V_124
) ;
V_1 -> V_75 |= V_125
| ( V_76 << 16 ) ;
if ( V_78 & V_126 )
V_1 -> V_75 |= V_122 ;
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_64 :
if ( V_77 & V_94 ) {
F_55 ( V_1 , L_24 ) ;
V_77 &= ~ V_94 ;
goto V_127;
} else
F_55 ( V_1 , L_25 ) ;
break;
case V_63 :
F_55 ( V_1 , L_26 ) ;
V_127:
V_1 -> V_60 -> V_61 -> V_62 = V_72 ;
if ( V_1 -> V_70 )
V_1 -> V_70 -> V_73 . V_74 = 1 ;
F_74 ( & V_1 -> V_113 ) ;
break;
default:
if ( ( V_78 & V_91 )
== ( 3 << V_92 ) ) {
V_1 -> V_60 -> V_61 -> V_62 = V_89 ;
if ( V_70 )
V_70 -> V_73 . V_74 = 0 ;
}
break;
}
F_75 ( V_1 ) ;
F_55 ( V_1 , L_27 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) , V_78 ) ;
}
if ( V_77 & V_93 ) {
F_55 ( V_1 , L_28 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ,
F_76 ( V_1 ) , V_78 ) ;
V_79 = V_82 ;
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_89 :
case V_66 :
F_64 ( V_1 ) ;
F_70 ( V_1 ) ;
if ( V_1 -> V_109 != 0 )
F_71 ( V_1 , V_87
+ F_63 ( V_1 -> V_109 ) ) ;
break;
case V_72 :
F_70 ( V_1 ) ;
if ( V_1 -> V_70 )
V_1 -> V_70 -> V_73 . V_74 = 0 ;
V_1 -> V_60 -> V_61 -> V_62 = V_64 ;
F_61 ( V_1 ) ;
F_56 ( V_1 ) ;
break;
case V_71 :
F_60 ( V_1 ) ;
F_70 ( V_1 ) ;
case V_63 :
case V_64 :
case V_95 :
F_56 ( V_1 ) ;
break;
default:
F_66 ( L_29 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
break;
}
}
if ( V_77 & V_128 ) {
V_79 = V_82 ;
if ( V_78 & V_83 ) {
F_77 ( V_1 -> V_45 , L_30 ) ;
if ( F_78 ( V_1 ) )
F_79 ( V_1 ) ;
} else {
F_55 ( V_1 , L_31 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
switch ( V_1 -> V_60 -> V_61 -> V_62 ) {
case V_66 :
F_80 ( V_1 ) ;
case V_67 :
F_55 ( V_1 , L_32 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ,
F_81 ( V_1 ) ) ;
F_73 ( & V_1 -> V_113 , V_87
+ F_63 ( F_81 ( V_1 ) ) ) ;
break;
case V_71 :
F_74 ( & V_1 -> V_113 ) ;
F_80 ( V_1 ) ;
break;
case V_63 :
F_55 ( V_1 , L_33 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
V_1 -> V_60 -> V_61 -> V_62 = V_64 ;
F_80 ( V_1 ) ;
break;
case V_95 :
V_1 -> V_60 -> V_61 -> V_62 = V_64 ;
case V_64 :
F_80 ( V_1 ) ;
break;
default:
F_55 ( V_1 , L_34 ,
F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
}
}
}
#if 0
if (int_usb & MUSB_INTR_SOF) {
void __iomem *mbase = musb->mregs;
struct musb_hw_ep *ep;
u8 epnum;
u16 frame;
dev_dbg(musb->controller, "START_OF_FRAME\n");
handled = IRQ_HANDLED;
frame = musb_readw(mbase, MUSB_FRAME);
ep = musb->endpoints;
for (epnum = 1; (epnum < musb->nr_endpoints)
&& (musb->epmask >= (1 << epnum));
epnum++, ep++) {
if (ep->dwWaitFrame >= frame) {
ep->dwWaitFrame = 0;
pr_debug("SOF --> periodic TX%s on %d\n",
ep->tx_channel ? " DMA" : "",
epnum);
if (!ep->tx_channel)
musb_h_tx_start(musb, epnum);
else
cppi_hostdma_start(musb, epnum);
}
}
}
#endif
F_65 ( & V_1 -> V_129 , 0 ) ;
return V_79 ;
}
static void F_82 ( struct V_1 * V_1 )
{
void T_2 * V_36 = V_1 -> V_53 ;
T_4 V_130 ;
F_8 ( V_36 , V_121 , 0 ) ;
V_1 -> V_116 = 0 ;
F_52 ( V_36 , V_118 , 0 ) ;
V_1 -> V_119 = 0 ;
F_52 ( V_36 , V_120 , 0 ) ;
V_130 = F_7 ( V_36 , V_131 ) ;
V_130 = F_83 ( V_36 , V_132 ) ;
V_130 = F_83 ( V_36 , V_133 ) ;
}
static void F_84 ( struct V_1 * V_1 )
{
void T_2 * V_51 = V_1 -> V_53 ;
V_1 -> V_116 = V_1 -> V_117 ;
F_52 ( V_51 , V_118 , V_1 -> V_116 ) ;
V_1 -> V_119 = V_1 -> V_117 & 0xfffe ;
F_52 ( V_51 , V_120 , V_1 -> V_119 ) ;
F_8 ( V_51 , V_121 , 0xf7 ) ;
}
void F_85 ( struct V_1 * V_1 )
{
void T_2 * V_51 = V_1 -> V_53 ;
T_3 V_78 = F_7 ( V_51 , V_98 ) ;
T_3 V_21 ;
F_55 ( V_1 , L_35 , V_78 ) ;
F_84 ( V_1 ) ;
F_8 ( V_51 , V_134 , 0 ) ;
V_21 = V_135 ;
if ( V_1 -> V_136 -> V_137 == V_138 ||
V_1 -> V_136 -> V_137 == V_139 )
V_21 |= V_140 ;
F_8 ( V_51 , V_24 , V_21 ) ;
V_1 -> V_65 = 0 ;
V_78 = F_7 ( V_51 , V_98 ) ;
V_78 &= ~ V_99 ;
if ( V_1 -> V_141 != V_142 &&
V_1 -> V_60 -> V_61 -> V_62 != V_67 &&
( V_78 & V_91 ) == V_91 ) {
V_1 -> V_65 = 1 ;
} else {
V_78 |= V_99 ;
}
F_86 ( V_1 ) ;
F_8 ( V_51 , V_98 , V_78 ) ;
}
void F_87 ( struct V_1 * V_1 )
{
F_88 ( V_1 ) ;
F_82 ( V_1 ) ;
F_8 ( V_1 -> V_53 , V_98 , 0 ) ;
F_71 ( V_1 , 0 ) ;
}
static int
F_89 ( struct V_1 * V_1 , struct V_40 * V_41 ,
const struct V_143 * V_144 , T_4 V_37 )
{
void T_2 * V_36 = V_1 -> V_53 ;
int V_145 = 0 ;
T_4 V_146 = V_144 -> V_146 ;
T_4 V_147 = V_37 >> 3 ;
T_3 V_148 ;
V_145 = F_90 ( F_91 ( V_146 , ( T_4 ) 8 ) ) - 1 ;
V_146 = 1 << V_145 ;
V_148 = V_145 - 3 ;
if ( V_144 -> V_6 == V_149 ) {
if ( ( V_37 + ( V_146 << 1 ) ) >
( 1 << ( V_1 -> V_136 -> V_150 + 2 ) ) )
return - V_151 ;
V_148 |= V_152 ;
} else {
if ( ( V_37 + V_146 ) > ( 1 << ( V_1 -> V_136 -> V_150 + 2 ) ) )
return - V_151 ;
}
F_8 ( V_36 , V_38 , V_41 -> V_35 ) ;
if ( V_41 -> V_35 == 1 )
V_1 -> V_153 = V_41 ;
switch ( V_144 -> V_154 ) {
case V_155 :
F_92 ( V_36 , V_148 ) ;
F_93 ( V_36 , V_147 ) ;
V_41 -> V_156 = ! ! ( V_148 & V_152 ) ;
V_41 -> V_157 = V_146 ;
break;
case V_158 :
F_94 ( V_36 , V_148 ) ;
F_95 ( V_36 , V_147 ) ;
V_41 -> V_159 = ! ! ( V_148 & V_152 ) ;
V_41 -> V_160 = V_146 ;
break;
case V_161 :
F_92 ( V_36 , V_148 ) ;
F_93 ( V_36 , V_147 ) ;
V_41 -> V_159 = ! ! ( V_148 & V_152 ) ;
V_41 -> V_160 = V_146 ;
F_94 ( V_36 , V_148 ) ;
F_95 ( V_36 , V_147 ) ;
V_41 -> V_156 = V_41 -> V_159 ;
V_41 -> V_157 = V_146 ;
V_41 -> V_162 = true ;
break;
}
V_1 -> V_117 |= ( 1 << V_41 -> V_35 ) ;
return V_37 + ( V_146 << ( ( V_148 & V_152 ) ? 1 : 0 ) ) ;
}
static int F_96 ( struct V_1 * V_1 )
{
const struct V_143 * V_144 ;
unsigned V_19 , V_163 ;
int V_37 ;
struct V_40 * V_41 = V_1 -> V_52 ;
if ( V_1 -> V_136 -> V_164 ) {
V_144 = V_1 -> V_136 -> V_164 ;
V_163 = V_1 -> V_136 -> V_165 ;
goto V_166;
}
switch ( V_167 ) {
default:
V_167 = 0 ;
case 0 :
V_144 = V_168 ;
V_163 = F_97 ( V_168 ) ;
break;
case 1 :
V_144 = V_169 ;
V_163 = F_97 ( V_169 ) ;
break;
case 2 :
V_144 = V_170 ;
V_163 = F_97 ( V_170 ) ;
break;
case 3 :
V_144 = V_171 ;
V_163 = F_97 ( V_171 ) ;
break;
case 4 :
V_144 = V_172 ;
V_163 = F_97 ( V_172 ) ;
break;
case 5 :
V_144 = V_173 ;
V_163 = F_97 ( V_173 ) ;
break;
}
F_98 ( L_36 , V_174 , V_167 ) ;
V_166:
V_37 = F_89 ( V_1 , V_41 , & V_175 , 0 ) ;
for ( V_19 = 0 ; V_19 < V_163 ; V_19 ++ ) {
T_3 V_176 = V_144 -> V_177 ;
if ( V_176 >= V_1 -> V_136 -> V_178 ) {
F_98 ( L_37 ,
V_174 , V_176 ) ;
return - V_179 ;
}
V_37 = F_89 ( V_1 , V_41 + V_176 , V_144 ++ , V_37 ) ;
if ( V_37 < 0 ) {
F_98 ( L_38 ,
V_174 , V_176 ) ;
return V_37 ;
}
V_176 ++ ;
V_1 -> V_180 = F_91 ( V_176 , V_1 -> V_180 ) ;
}
F_98 ( L_39 ,
V_174 ,
V_163 + 1 , V_1 -> V_136 -> V_178 * 2 - 1 ,
V_37 , ( 1 << ( V_1 -> V_136 -> V_150 + 2 ) ) ) ;
if ( ! V_1 -> V_153 ) {
F_98 ( L_40 , V_174 ) ;
return - V_179 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_1 )
{
T_3 V_35 = 0 ;
struct V_40 * V_41 ;
void T_2 * V_36 = V_1 -> V_53 ;
int V_22 = 0 ;
F_55 ( V_1 , L_41 ) ;
for ( V_35 = 1 ; V_35 < V_1 -> V_136 -> V_178 ; V_35 ++ ) {
F_51 ( V_36 , V_35 ) ;
V_41 = V_1 -> V_52 + V_35 ;
V_22 = F_100 ( V_1 , V_41 , V_35 ) ;
if ( V_22 < 0 )
break;
if ( V_41 -> V_157 < 512
|| V_41 -> V_160 < 512 )
continue;
if ( V_1 -> V_153 )
continue;
V_1 -> V_153 = V_41 ;
}
if ( ! V_1 -> V_153 ) {
F_98 ( L_40 , V_174 ) ;
return - V_179 ;
}
return 0 ;
}
static int F_101 ( T_4 V_181 , struct V_1 * V_1 )
{
T_3 V_16 ;
char * type ;
char V_182 [ 90 ] ;
void T_2 * V_36 = V_1 -> V_53 ;
int V_183 = 0 ;
int V_19 ;
V_16 = F_102 ( V_36 ) ;
strcpy ( V_182 , ( V_16 & V_184 ) ? L_42 : L_43 ) ;
if ( V_16 & V_185 ) {
strcat ( V_182 , L_44 ) ;
V_1 -> V_186 = true ;
}
if ( V_16 & V_187 ) {
strcat ( V_182 , L_45 ) ;
V_1 -> V_188 = true ;
}
if ( V_16 & V_189 ) {
strcat ( V_182 , L_46 ) ;
V_1 -> V_190 = true ;
}
if ( V_16 & V_191 ) {
strcat ( V_182 , L_47 ) ;
V_1 -> V_192 = true ;
}
if ( V_16 & V_193 ) {
strcat ( V_182 , L_48 ) ;
V_1 -> V_194 = true ;
}
if ( V_16 & V_195 )
strcat ( V_182 , L_49 ) ;
F_98 ( L_50 , V_174 , V_16 , V_182 ) ;
if ( V_196 == V_181 ) {
V_1 -> V_197 = 1 ;
type = L_51 ;
} else {
V_1 -> V_197 = 0 ;
type = L_52 ;
#ifndef F_103
F_104 ( L_53 ,
V_174 ) ;
#endif
}
V_1 -> V_198 = F_105 ( V_36 ) ;
F_98 ( L_54 ,
V_174 , type , F_106 ( V_1 -> V_198 ) ,
F_107 ( V_1 -> V_198 ) ,
( V_1 -> V_198 & V_199 ) ? L_55 : L_52 ) ;
F_108 ( V_1 ) ;
V_1 -> V_180 = 1 ;
V_1 -> V_117 = 1 ;
if ( V_1 -> V_186 )
V_183 = F_96 ( V_1 ) ;
else
V_183 = F_99 ( V_1 ) ;
if ( V_183 < 0 )
return V_183 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_180 ; V_19 ++ ) {
struct V_40 * V_41 = V_1 -> V_52 + V_19 ;
V_41 -> V_44 = V_1 -> V_48 . V_200 ( V_19 ) + V_36 ;
#if F_109 ( V_201 )
if ( V_1 -> V_48 . V_202 & V_203 ) {
V_41 -> V_204 = V_1 -> V_205 + 0x400 +
V_1 -> V_48 . V_200 ( V_19 ) ;
V_41 -> V_206 = V_1 -> V_207 + 0x400 +
V_1 -> V_48 . V_200 ( V_19 ) ;
V_41 -> V_208 =
V_1 -> V_209 + 0x400 + V_1 -> V_48 . V_200 ( V_19 ) ;
if ( V_19 == 0 )
V_41 -> V_210 = V_36 - 0x400 + V_211 ;
else
V_41 -> V_210 = V_36 + 0x400 +
( ( ( V_19 - 1 ) & 0xf ) << 2 ) ;
}
#endif
V_41 -> V_51 = V_1 -> V_48 . V_212 ( V_19 , 0 ) + V_36 ;
V_41 -> V_213 = 1 ;
V_41 -> V_214 = 1 ;
if ( V_41 -> V_157 ) {
F_55 ( V_1 , L_56 ,
V_174 , V_19 ,
V_41 -> V_162 ? L_57 : L_58 ,
V_41 -> V_156
? L_59 : L_52 ,
V_41 -> V_157 ) ;
}
if ( V_41 -> V_160 && ! V_41 -> V_162 ) {
F_55 ( V_1 , L_56 ,
V_174 , V_19 ,
L_60 ,
V_41 -> V_159
? L_59 : L_52 ,
V_41 -> V_160 ) ;
}
if ( ! ( V_41 -> V_157 || V_41 -> V_160 ) )
F_55 ( V_1 , L_61 , V_19 ) ;
}
return 0 ;
}
T_5 F_110 ( struct V_1 * V_1 )
{
T_5 V_215 = V_80 ;
unsigned long V_183 ;
unsigned long V_35 ;
T_3 V_78 ;
if ( ! V_1 -> V_77 && ! V_1 -> V_216 && ! V_1 -> V_217 )
return V_80 ;
V_78 = F_7 ( V_1 -> V_53 , V_98 ) ;
F_111 ( V_1 ) ;
if ( V_1 -> V_77 )
V_215 |= F_62 ( V_1 , V_1 -> V_77 , V_78 ) ;
if ( V_1 -> V_216 & 1 ) {
if ( F_78 ( V_1 ) )
V_215 |= F_112 ( V_1 ) ;
else
V_215 |= F_113 ( V_1 ) ;
V_1 -> V_216 &= ~ F_114 ( 0 ) ;
}
V_183 = V_1 -> V_216 ;
F_115 (epnum, &status, 16 ) {
V_215 = V_82 ;
if ( F_78 ( V_1 ) )
F_116 ( V_1 , V_35 ) ;
else
F_117 ( V_1 , V_35 ) ;
}
V_183 = V_1 -> V_217 ;
F_115 (epnum, &status, 16 ) {
V_215 = V_82 ;
if ( F_78 ( V_1 ) )
F_118 ( V_1 , V_35 ) ;
else
F_119 ( V_1 , V_35 ) ;
}
return V_215 ;
}
void F_120 ( struct V_1 * V_1 , T_3 V_35 , T_3 V_218 )
{
if ( ! V_35 ) {
if ( ! F_121 ( V_1 ) ) {
if ( F_78 ( V_1 ) )
F_112 ( V_1 ) ;
else
F_113 ( V_1 ) ;
}
} else {
if ( V_218 ) {
if ( F_78 ( V_1 ) )
F_116 ( V_1 , V_35 ) ;
else
F_117 ( V_1 , V_35 ) ;
} else {
if ( F_78 ( V_1 ) )
F_118 ( V_1 , V_35 ) ;
else
F_119 ( V_1 , V_35 ) ;
}
}
}
int F_122 ( enum V_219 V_183 )
{
if ( V_220 )
return V_220 ( V_183 ) ;
return - V_221 ;
}
static T_6
F_123 ( struct V_2 * V_3 , struct V_222 * V_223 , char * V_224 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
int V_22 = - V_179 ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
V_22 = sprintf ( V_224 , L_62 , F_57 ( V_1 -> V_60 -> V_61 -> V_62 ) ) ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
return V_22 ;
}
static T_6
F_124 ( struct V_2 * V_3 , struct V_222 * V_223 ,
const char * V_224 , T_7 V_163 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
int V_183 ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
if ( F_125 ( V_224 , L_12 ) )
V_183 = F_126 ( V_1 , V_8 ) ;
else if ( F_125 ( V_224 , L_13 ) )
V_183 = F_126 ( V_1 , V_10 ) ;
else if ( F_125 ( V_224 , L_63 ) )
V_183 = F_126 ( V_1 , V_13 ) ;
else
V_183 = - V_179 ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
return ( V_183 == 0 ) ? V_163 : V_183 ;
}
static T_6
F_127 ( struct V_2 * V_3 , struct V_222 * V_223 ,
const char * V_224 , T_7 V_163 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
unsigned long V_34 ;
if ( sscanf ( V_224 , L_64 , & V_34 ) < 1 ) {
F_77 ( V_3 , L_65 ) ;
return - V_179 ;
}
F_54 ( & V_1 -> V_59 , V_58 ) ;
V_1 -> V_109 = V_34 ? F_128 ( int , V_34 , V_110 ) : 0 ;
if ( V_1 -> V_60 -> V_61 -> V_62 == V_67 )
V_1 -> V_65 = 0 ;
F_71 ( V_1 , V_87 + F_63 ( V_34 ) ) ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
return V_163 ;
}
static T_6
F_129 ( struct V_2 * V_3 , struct V_222 * V_223 , char * V_224 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
unsigned long V_34 ;
int V_225 ;
T_3 V_78 ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
V_34 = V_1 -> V_109 ;
V_225 = F_130 ( V_1 ) ;
if ( V_225 < 0 ) {
V_78 = F_7 ( V_1 -> V_53 , V_98 ) ;
if ( ( V_78 & V_91 )
== ( 3 << V_92 ) )
V_225 = 1 ;
else
V_225 = 0 ;
}
F_59 ( & V_1 -> V_59 , V_58 ) ;
return sprintf ( V_224 , L_66 ,
V_225 ? L_67 : L_68 , V_34 ) ;
}
static T_6
F_131 ( struct V_2 * V_3 , struct V_222 * V_223 ,
const char * V_224 , T_7 V_163 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_226 ;
if ( sscanf ( V_224 , L_69 , & V_226 ) != 1
|| ( V_226 != 1 ) ) {
F_77 ( V_3 , L_70 ) ;
return - V_179 ;
}
if ( V_226 == 1 )
F_132 ( V_1 ) ;
return V_163 ;
}
static void F_133 ( struct V_1 * V_1 )
{
T_3 V_78 , V_227 ;
int error ;
V_78 = F_7 ( V_1 -> V_53 , V_98 ) ;
V_227 = V_228 | V_126 |
V_229 ;
switch ( V_78 & ~ V_227 ) {
case V_230 :
if ( V_1 -> V_231 -- ) {
F_55 ( V_1 ,
L_71 ) ;
F_65 ( & V_1 -> V_129 ,
F_63 ( 1000 ) ) ;
return;
}
case V_232 :
if ( V_1 -> V_231 -- ) {
F_55 ( V_1 ,
L_72 ) ;
F_65 ( & V_1 -> V_129 ,
F_63 ( 1000 ) ) ;
return;
}
if ( ! V_1 -> V_233 )
break;
F_55 ( V_1 , L_73 ) ;
F_134 ( V_1 -> V_45 ) ;
F_135 ( V_1 -> V_45 ) ;
V_1 -> V_233 = false ;
return;
default:
break;
}
V_227 = V_78 & V_99 ;
if ( V_227 == V_1 -> V_233 )
return;
if ( V_227 ) {
F_55 ( V_1 , L_74 , V_78 ) ;
error = F_6 ( V_1 -> V_45 ) ;
if ( error < 0 )
F_77 ( V_1 -> V_45 , L_75 ,
error ) ;
V_1 -> V_231 = 3 ;
} else {
F_55 ( V_1 , L_76 , V_78 ) ;
F_134 ( V_1 -> V_45 ) ;
F_135 ( V_1 -> V_45 ) ;
}
V_1 -> V_233 = V_227 ;
}
static void F_136 ( struct V_234 * V_39 )
{
struct V_1 * V_1 = F_137 ( V_39 , struct V_1 , V_129 . V_235 ) ;
int error ;
error = F_6 ( V_1 -> V_45 ) ;
if ( error < 0 ) {
F_77 ( V_1 -> V_45 , L_75 , error ) ;
return;
}
F_133 ( V_1 ) ;
if ( V_1 -> V_60 -> V_61 -> V_62 != V_1 -> V_236 ) {
V_1 -> V_236 = V_1 -> V_60 -> V_61 -> V_62 ;
F_138 ( & V_1 -> V_45 -> V_237 , NULL , L_77 ) ;
}
F_134 ( V_1 -> V_45 ) ;
F_135 ( V_1 -> V_45 ) ;
}
static void F_79 ( struct V_1 * V_1 )
{
int V_22 ;
T_3 V_78 ;
F_82 ( V_1 ) ;
F_139 ( 10 ) ;
V_22 = F_140 ( V_1 ) ;
if ( V_22 ) {
F_84 ( V_1 ) ;
return;
}
V_78 = F_7 ( V_1 -> V_53 , V_98 ) ;
V_78 &= ~ V_99 ;
F_8 ( V_1 -> V_53 , V_98 , V_78 ) ;
F_70 ( V_1 ) ;
if ( V_1 -> V_186 )
V_22 = F_96 ( V_1 ) ;
else
V_22 = F_99 ( V_1 ) ;
if ( V_22 == 0 )
F_85 ( V_1 ) ;
}
static struct V_1 * F_141 ( struct V_2 * V_3 ,
const struct V_238 * V_136 , void T_2 * V_36 )
{
struct V_1 * V_1 ;
struct V_40 * V_239 ;
int V_35 ;
int V_22 ;
V_1 = F_142 ( V_3 , sizeof( * V_1 ) , V_240 ) ;
if ( ! V_1 )
return NULL ;
F_143 ( & V_1 -> V_241 ) ;
F_143 ( & V_1 -> V_242 ) ;
F_143 ( & V_1 -> V_243 ) ;
F_143 ( & V_1 -> V_244 ) ;
V_1 -> V_106 = V_245 ;
V_1 -> V_109 = V_110 ;
V_1 -> V_53 = V_36 ;
V_1 -> V_246 = V_36 ;
V_1 -> V_247 = - V_221 ;
V_1 -> V_136 = V_136 ;
F_144 ( V_1 -> V_136 -> V_178 > V_248 ) ;
for ( V_35 = 0 , V_239 = V_1 -> V_52 ;
V_35 < V_1 -> V_136 -> V_178 ;
V_35 ++ , V_239 ++ ) {
V_239 -> V_1 = V_1 ;
V_239 -> V_35 = V_35 ;
}
V_1 -> V_45 = V_3 ;
V_22 = F_145 ( V_1 ) ;
if ( V_22 < 0 )
goto V_249;
F_146 ( V_3 , V_1 ) ;
return V_1 ;
V_249:
return NULL ;
}
static void F_147 ( struct V_1 * V_1 )
{
#ifdef F_148
F_149 ( & V_1 -> V_45 -> V_237 , & V_250 ) ;
#endif
if ( V_1 -> V_247 >= 0 ) {
if ( V_1 -> V_251 )
F_150 ( V_1 -> V_247 ) ;
F_151 ( V_1 -> V_247 , V_1 ) ;
}
F_152 ( V_1 ) ;
}
static int F_153 ( struct V_1 * V_1 )
{
struct V_252 * V_253 , * V_254 ;
unsigned long V_58 ;
int error = 0 ;
F_54 ( & V_1 -> V_255 , V_58 ) ;
F_154 (w, _w, &musb->pending_list, node) {
if ( V_253 -> V_256 ) {
error = V_253 -> V_256 ( V_1 , V_253 -> V_39 ) ;
if ( error < 0 ) {
F_77 ( V_1 -> V_45 ,
L_78 ,
V_253 -> V_256 , error ) ;
}
}
F_155 ( & V_253 -> V_257 ) ;
F_156 ( V_1 -> V_45 , V_253 ) ;
}
F_59 ( & V_1 -> V_255 , V_58 ) ;
return error ;
}
int F_157 ( struct V_1 * V_1 ,
int (* V_256)( struct V_1 * V_1 , void * V_39 ) ,
void * V_39 )
{
struct V_252 * V_253 ;
unsigned long V_58 ;
int error ;
if ( F_158 ( ! V_256 ) )
return - V_179 ;
if ( F_159 ( V_1 -> V_45 ) )
return V_256 ( V_1 , V_39 ) ;
V_253 = F_142 ( V_1 -> V_45 , sizeof( * V_253 ) , V_258 ) ;
if ( ! V_253 )
return - V_259 ;
V_253 -> V_256 = V_256 ;
V_253 -> V_39 = V_39 ;
F_54 ( & V_1 -> V_255 , V_58 ) ;
if ( V_1 -> V_260 ) {
F_160 ( & V_253 -> V_257 , & V_1 -> V_244 ) ;
error = 0 ;
} else {
F_77 ( V_1 -> V_45 , L_79 ,
V_256 ) ;
F_156 ( V_1 -> V_45 , V_253 ) ;
error = - V_261 ;
}
F_59 ( & V_1 -> V_255 , V_58 ) ;
return error ;
}
static void F_161 ( struct V_234 * V_235 )
{
struct V_1 * V_1 ;
unsigned long V_58 ;
V_1 = F_137 ( V_235 , struct V_1 , V_262 . V_235 ) ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
if ( V_1 -> V_75 & V_263 )
F_162 ( V_1 , false ) ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
}
static int
F_163 ( struct V_2 * V_3 , int V_247 , void T_2 * V_264 )
{
int V_183 ;
struct V_1 * V_1 ;
struct V_265 * V_266 = F_164 ( V_3 ) ;
if ( ! V_266 ) {
F_77 ( V_3 , L_80 ) ;
V_183 = - V_221 ;
goto V_267;
}
V_1 = F_141 ( V_3 , V_266 -> V_136 , V_264 ) ;
if ( ! V_1 ) {
V_183 = - V_259 ;
goto V_267;
}
F_165 ( & V_1 -> V_59 ) ;
F_165 ( & V_1 -> V_255 ) ;
V_1 -> V_268 = V_266 -> V_269 ;
V_1 -> V_270 = V_266 -> V_270 ;
V_1 -> V_271 = V_266 -> V_272 ;
V_1 -> V_141 = V_266 -> V_6 ;
F_7 = F_17 ;
F_8 = F_21 ;
F_83 = F_24 ;
F_52 = F_27 ;
V_273 = F_30 ;
V_274 = F_33 ;
V_183 = F_166 ( V_1 ) ;
if ( V_183 < 0 )
goto V_275;
if ( ! V_1 -> V_276 ) {
V_183 = - V_221 ;
goto V_277;
}
if ( V_1 -> V_271 -> V_202 )
V_1 -> V_48 . V_202 = V_1 -> V_271 -> V_202 ;
if ( V_1 -> V_48 . V_202 & V_278 ) {
V_1 -> V_48 . V_212 = F_15 ;
V_1 -> V_48 . V_279 = F_14 ;
} else {
V_1 -> V_48 . V_212 = F_13 ;
V_1 -> V_48 . V_279 = F_12 ;
}
if ( V_1 -> V_271 -> V_212 )
V_1 -> V_48 . V_212 = V_1 -> V_271 -> V_212 ;
if ( V_1 -> V_271 -> V_279 )
V_1 -> V_48 . V_279 = V_1 -> V_271 -> V_279 ;
if ( V_1 -> V_271 -> V_167 )
V_167 = V_1 -> V_271 -> V_167 ;
else
V_167 = 4 ;
if ( V_1 -> V_271 -> V_200 )
V_1 -> V_48 . V_200 = V_1 -> V_271 -> V_200 ;
else
V_1 -> V_48 . V_200 = F_11 ;
if ( V_1 -> V_271 -> V_280 )
V_1 -> V_48 . V_280 = V_1 -> V_271 -> V_280 ;
else
V_1 -> V_48 . V_280 = F_16 ;
if ( V_1 -> V_271 -> V_281 )
F_7 = V_1 -> V_271 -> V_281 ;
if ( V_1 -> V_271 -> V_282 )
F_8 = V_1 -> V_271 -> V_282 ;
if ( V_1 -> V_271 -> V_283 )
F_83 = V_1 -> V_271 -> V_283 ;
if ( V_1 -> V_271 -> V_284 )
F_52 = V_1 -> V_271 -> V_284 ;
if ( V_1 -> V_271 -> V_285 )
V_273 = V_1 -> V_271 -> V_285 ;
if ( V_1 -> V_271 -> V_286 )
V_274 = V_1 -> V_271 -> V_286 ;
#ifndef F_167
if ( ! V_1 -> V_271 -> V_287 || ! V_1 -> V_271 -> V_288 ) {
F_77 ( V_3 , L_81 ) ;
V_183 = - V_221 ;
goto V_277;
}
V_289 = V_1 -> V_271 -> V_287 ;
V_290 = V_1 -> V_271 -> V_288 ;
#endif
if ( V_1 -> V_271 -> V_49 )
V_1 -> V_48 . V_49 = V_1 -> V_271 -> V_49 ;
else
V_1 -> V_48 . V_49 = F_44 ;
if ( V_1 -> V_271 -> V_50 )
V_1 -> V_48 . V_50 = V_1 -> V_271 -> V_50 ;
else
V_1 -> V_48 . V_50 = F_36 ;
if ( ! V_1 -> V_60 -> V_291 ) {
V_1 -> V_60 -> V_23 = V_1 -> V_45 ;
V_1 -> V_60 -> V_18 = V_1 -> V_53 ;
V_1 -> V_60 -> V_291 = & V_292 ;
}
if ( V_1 -> V_271 -> V_293 )
V_220 = V_1 -> V_271 -> V_293 ;
F_168 ( V_1 -> V_45 ) ;
F_169 ( V_1 -> V_45 , 500 ) ;
F_170 ( V_1 -> V_45 ) ;
F_6 ( V_1 -> V_45 ) ;
V_183 = F_171 ( V_1 -> V_60 ) ;
if ( V_183 < 0 )
goto V_294;
if ( V_295 && V_3 -> V_296 ) {
V_1 -> V_297 =
V_289 ( V_1 , V_1 -> V_53 ) ;
if ( F_172 ( V_1 -> V_297 ) ) {
V_183 = F_173 ( V_1 -> V_297 ) ;
goto V_298;
}
}
F_88 ( V_1 ) ;
F_82 ( V_1 ) ;
F_8 ( V_1 -> V_53 , V_98 , 0 ) ;
F_174 ( & V_1 -> V_129 , F_136 ) ;
F_174 ( & V_1 -> V_262 , F_161 ) ;
F_174 ( & V_1 -> V_90 , V_299 ) ;
V_183 = F_101 ( V_266 -> V_136 -> V_300
? V_196
: V_301 , V_1 ) ;
if ( V_183 < 0 )
goto V_302;
F_175 ( & V_1 -> V_113 , F_53 , ( unsigned long ) V_1 ) ;
if ( F_176 ( V_247 , V_1 -> V_276 , 0 , F_177 ( V_3 ) , V_1 ) ) {
F_77 ( V_3 , L_82 , V_247 ) ;
V_183 = - V_221 ;
goto V_302;
}
V_1 -> V_247 = V_247 ;
if ( F_178 ( V_247 ) == 0 ) {
V_1 -> V_251 = 1 ;
F_179 ( V_3 , 1 ) ;
} else {
V_1 -> V_251 = 0 ;
}
if ( V_266 -> V_303 ) {
T_3 V_304 = F_180 ( V_1 -> V_53 ) ;
V_304 |= V_305 ;
F_181 ( V_1 -> V_53 , V_304 ) ;
}
if ( V_1 -> V_60 -> V_61 -> V_306 ) {
F_68 ( V_1 ) ;
V_1 -> V_60 -> V_61 -> V_62 = V_102 ;
} else {
F_61 ( V_1 ) ;
V_1 -> V_60 -> V_61 -> V_62 = V_95 ;
}
switch ( V_1 -> V_141 ) {
case V_142 :
V_183 = F_182 ( V_1 , V_266 -> V_21 ) ;
if ( V_183 < 0 )
goto V_302;
V_183 = F_126 ( V_1 , V_8 ) ;
break;
case V_307 :
V_183 = F_183 ( V_1 ) ;
if ( V_183 < 0 )
goto V_302;
V_183 = F_126 ( V_1 , V_10 ) ;
break;
case V_308 :
V_183 = F_182 ( V_1 , V_266 -> V_21 ) ;
if ( V_183 < 0 )
goto V_302;
V_183 = F_183 ( V_1 ) ;
if ( V_183 ) {
F_184 ( V_1 ) ;
goto V_302;
}
V_183 = F_126 ( V_1 , V_13 ) ;
break;
default:
F_77 ( V_3 , L_83 , V_1 -> V_141 ) ;
break;
}
if ( V_183 < 0 )
goto V_302;
V_183 = F_185 ( V_1 ) ;
if ( V_183 < 0 )
goto V_309;
V_183 = F_186 ( & V_1 -> V_45 -> V_237 , & V_250 ) ;
if ( V_183 )
goto V_310;
V_1 -> V_311 = 1 ;
F_134 ( V_1 -> V_45 ) ;
F_135 ( V_1 -> V_45 ) ;
return 0 ;
V_310:
F_187 ( V_1 ) ;
V_309:
F_188 ( V_1 ) ;
F_184 ( V_1 ) ;
V_302:
F_189 ( & V_1 -> V_129 ) ;
F_189 ( & V_1 -> V_90 ) ;
F_189 ( & V_1 -> V_262 ) ;
if ( V_1 -> V_297 )
V_290 ( V_1 -> V_297 ) ;
V_298:
F_190 ( V_1 -> V_60 ) ;
V_294:
F_191 ( V_1 -> V_45 ) ;
F_192 ( V_1 -> V_45 ) ;
F_193 ( V_1 -> V_45 ) ;
V_277:
if ( V_1 -> V_251 )
F_179 ( V_3 , 0 ) ;
F_194 ( V_1 ) ;
V_275:
if ( V_183 != - V_312 )
F_77 ( V_1 -> V_45 ,
L_84 , V_313 , V_183 ) ;
F_147 ( V_1 ) ;
V_267:
return V_183 ;
}
static int F_195 ( struct V_314 * V_315 )
{
struct V_2 * V_3 = & V_315 -> V_3 ;
int V_316 = F_196 ( V_315 , L_85 ) ;
struct V_317 * V_318 ;
void T_2 * V_319 ;
if ( V_316 <= 0 )
return - V_221 ;
V_318 = F_197 ( V_315 , V_320 , 0 ) ;
V_319 = F_198 ( V_3 , V_318 ) ;
if ( F_172 ( V_319 ) )
return F_173 ( V_319 ) ;
return F_163 ( V_3 , V_316 , V_319 ) ;
}
static int F_199 ( struct V_314 * V_315 )
{
struct V_2 * V_3 = & V_315 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
F_187 ( V_1 ) ;
F_189 ( & V_1 -> V_129 ) ;
F_189 ( & V_1 -> V_90 ) ;
F_189 ( & V_1 -> V_262 ) ;
F_6 ( V_1 -> V_45 ) ;
F_184 ( V_1 ) ;
F_188 ( V_1 ) ;
F_88 ( V_1 ) ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
F_82 ( V_1 ) ;
F_8 ( V_1 -> V_53 , V_98 , 0 ) ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
F_191 ( V_1 -> V_45 ) ;
F_192 ( V_1 -> V_45 ) ;
F_193 ( V_1 -> V_45 ) ;
F_194 ( V_1 ) ;
V_220 = NULL ;
if ( V_1 -> V_297 )
V_290 ( V_1 -> V_297 ) ;
F_190 ( V_1 -> V_60 ) ;
F_147 ( V_1 ) ;
F_179 ( V_3 , 0 ) ;
return 0 ;
}
static void F_200 ( struct V_1 * V_1 )
{
int V_19 ;
void T_2 * V_321 = V_1 -> V_53 ;
void T_2 * V_322 ;
V_1 -> V_323 . V_324 = F_83 ( V_321 , V_325 ) ;
V_1 -> V_323 . V_326 = F_7 ( V_321 , V_134 ) ;
V_1 -> V_323 . V_304 = F_180 ( V_1 -> V_53 ) ;
V_1 -> V_323 . V_21 = F_7 ( V_321 , V_24 ) ;
V_1 -> V_323 . V_327 = F_7 ( V_321 , V_121 ) ;
V_1 -> V_323 . V_46 = F_7 ( V_321 , V_38 ) ;
V_1 -> V_323 . V_78 = F_7 ( V_321 , V_98 ) ;
for ( V_19 = 0 ; V_19 < V_1 -> V_136 -> V_178 ; ++ V_19 ) {
struct V_40 * V_41 ;
V_41 = & V_1 -> V_52 [ V_19 ] ;
if ( ! V_41 )
continue;
V_322 = V_41 -> V_51 ;
if ( ! V_322 )
continue;
F_8 ( V_321 , V_38 , V_19 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_329 =
F_83 ( V_322 , V_330 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_331 =
F_83 ( V_322 , V_332 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_333 =
F_83 ( V_322 , V_334 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_335 =
F_83 ( V_322 , V_336 ) ;
if ( V_1 -> V_186 ) {
V_1 -> V_323 . V_328 [ V_19 ] . V_337 =
F_201 ( V_321 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_338 =
F_202 ( V_321 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_339 =
F_203 ( V_321 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_340 =
F_204 ( V_321 ) ;
}
V_1 -> V_323 . V_328 [ V_19 ] . V_341 =
F_7 ( V_322 , V_342 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_343 =
F_7 ( V_322 , V_344 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_345 =
F_7 ( V_322 , V_346 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_347 =
F_7 ( V_322 , V_348 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_349 =
F_205 ( V_1 , V_19 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_350 =
F_206 ( V_1 , V_19 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_351 =
F_207 ( V_1 , V_19 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_352 =
F_208 ( V_1 , V_19 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_353 =
F_209 ( V_1 , V_19 ) ;
V_1 -> V_323 . V_328 [ V_19 ] . V_354 =
F_210 ( V_1 , V_19 ) ;
}
}
static void F_211 ( struct V_1 * V_1 )
{
int V_19 ;
void T_2 * V_321 = V_1 -> V_53 ;
void T_2 * V_322 ;
T_3 V_21 ;
F_52 ( V_321 , V_325 , V_1 -> V_323 . V_324 ) ;
F_8 ( V_321 , V_134 , V_1 -> V_323 . V_326 ) ;
F_181 ( V_1 -> V_53 , V_1 -> V_323 . V_304 ) ;
V_21 = F_7 ( V_321 , V_24 ) ;
V_21 &= V_25 | V_355 ;
V_1 -> V_323 . V_21 &= ~ ( V_25 | V_355 ) ;
V_21 |= V_1 -> V_323 . V_21 ;
F_8 ( V_321 , V_24 , V_21 ) ;
F_52 ( V_321 , V_118 , V_1 -> V_116 ) ;
F_52 ( V_321 , V_120 , V_1 -> V_119 ) ;
F_8 ( V_321 , V_121 , V_1 -> V_323 . V_327 ) ;
if ( V_1 -> V_323 . V_78 & V_99 )
F_8 ( V_321 , V_98 , V_1 -> V_323 . V_78 ) ;
for ( V_19 = 0 ; V_19 < V_1 -> V_136 -> V_178 ; ++ V_19 ) {
struct V_40 * V_41 ;
V_41 = & V_1 -> V_52 [ V_19 ] ;
if ( ! V_41 )
continue;
V_322 = V_41 -> V_51 ;
if ( ! V_322 )
continue;
F_8 ( V_321 , V_38 , V_19 ) ;
F_52 ( V_322 , V_330 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_329 ) ;
F_52 ( V_322 , V_332 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_331 ) ;
F_52 ( V_322 , V_334 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_333 ) ;
F_52 ( V_322 , V_336 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_335 ) ;
if ( V_1 -> V_186 ) {
F_92 ( V_321 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_339 ) ;
F_94 ( V_321 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_340 ) ;
F_93 ( V_321 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_337 ) ;
F_95 ( V_321 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_338 ) ;
}
F_8 ( V_322 , V_342 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_341 ) ;
F_8 ( V_322 , V_344 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_343 ) ;
F_8 ( V_322 , V_346 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_345 ) ;
F_8 ( V_322 , V_348 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_347 ) ;
F_212 ( V_1 , V_19 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_349 ) ;
F_213 ( V_1 , V_19 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_350 ) ;
F_214 ( V_1 , V_19 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_351 ) ;
F_215 ( V_1 , V_19 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_352 ) ;
F_216 ( V_1 , V_19 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_353 ) ;
F_217 ( V_1 , V_19 ,
V_1 -> V_323 . V_328 [ V_19 ] . V_354 ) ;
}
F_8 ( V_321 , V_38 , V_1 -> V_323 . V_46 ) ;
}
static int F_218 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
F_88 ( V_1 ) ;
F_82 ( V_1 ) ;
if ( ! ( V_1 -> V_48 . V_202 & V_356 ) )
F_8 ( V_1 -> V_53 , V_98 , 0 ) ;
F_158 ( ! F_219 ( & V_1 -> V_244 ) ) ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
if ( F_220 ( V_1 ) ) {
} else if ( F_78 ( V_1 ) ) {
}
F_200 ( V_1 ) ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
return 0 ;
}
static int F_221 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
int error ;
T_3 V_78 ;
T_3 V_357 ;
F_211 ( V_1 ) ;
V_78 = F_7 ( V_1 -> V_53 , V_98 ) ;
V_357 = V_97 | V_228 | V_126 ;
if ( ( V_78 & V_357 ) != ( V_1 -> V_323 . V_78 & V_357 ) )
V_1 -> V_75 = 0 ;
F_193 ( V_3 ) ;
F_222 ( V_3 ) ;
F_170 ( V_3 ) ;
F_85 ( V_1 ) ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
error = F_153 ( V_1 ) ;
if ( error )
F_77 ( V_1 -> V_45 , L_86 ,
error ) ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
return 0 ;
}
static int F_223 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_200 ( V_1 ) ;
V_1 -> V_260 = 1 ;
return 0 ;
}
static int F_224 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_58 ;
int error ;
if ( ! V_1 -> V_311 )
return 0 ;
F_211 ( V_1 ) ;
F_54 ( & V_1 -> V_59 , V_58 ) ;
error = F_153 ( V_1 ) ;
if ( error )
F_77 ( V_1 -> V_45 , L_86 ,
error ) ;
V_1 -> V_260 = 0 ;
F_59 ( & V_1 -> V_59 , V_58 ) ;
return 0 ;
}
