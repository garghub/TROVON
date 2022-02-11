static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
void T_2 * V_7 = V_5 -> V_8 ;
int V_9 = 0 ;
T_3 V_10 ;
T_3 V_11 ;
int V_12 ;
F_4 ( V_5 -> V_13 ) ;
V_11 = F_5 ( V_7 , V_14 ) ;
V_11 &= ~ V_15 ;
F_6 ( V_7 , V_14 , V_11 ) ;
F_6 ( V_7 , V_16 , ( T_3 ) V_6 ) ;
F_6 ( V_7 , V_17 ,
V_18 | V_19 ) ;
while ( ! ( F_5 ( V_7 , V_17 )
& V_20 ) ) {
V_9 ++ ;
if ( V_9 == 10000 ) {
V_12 = - V_21 ;
goto V_22;
}
}
V_10 = F_5 ( V_7 , V_17 ) ;
V_10 &= ~ V_20 ;
F_6 ( V_7 , V_17 , V_10 ) ;
V_12 = F_5 ( V_7 , V_23 ) ;
V_22:
F_7 ( V_5 -> V_13 ) ;
return V_12 ;
}
static int F_8 ( struct V_4 * V_5 , T_1 V_24 , T_1 V_6 )
{
void T_2 * V_7 = V_5 -> V_8 ;
int V_9 = 0 ;
T_3 V_10 = 0 ;
T_3 V_11 ;
int V_12 = 0 ;
F_4 ( V_5 -> V_13 ) ;
V_11 = F_5 ( V_7 , V_14 ) ;
V_11 &= ~ V_15 ;
F_6 ( V_7 , V_14 , V_11 ) ;
F_6 ( V_7 , V_16 , ( T_3 ) V_6 ) ;
F_6 ( V_7 , V_23 , ( T_3 ) V_24 ) ;
F_6 ( V_7 , V_17 , V_18 ) ;
while ( ! ( F_5 ( V_7 , V_17 )
& V_20 ) ) {
V_9 ++ ;
if ( V_9 == 10000 ) {
V_12 = - V_21 ;
goto V_22;
}
}
V_10 = F_5 ( V_7 , V_17 ) ;
V_10 &= ~ V_20 ;
F_6 ( V_7 , V_17 , V_10 ) ;
V_22:
F_7 ( V_5 -> V_13 ) ;
return V_12 ;
}
static T_1 F_9 ( T_3 V_25 )
{
return 0x20 + ( V_25 * 4 ) ;
}
static void F_10 ( void T_2 * V_26 , T_3 V_25 )
{
}
static T_1 F_11 ( T_3 V_25 , T_4 V_27 )
{
return 0x100 + ( 0x10 * V_25 ) + V_27 ;
}
static void F_12 ( void T_2 * V_26 , T_3 V_25 )
{
F_6 ( V_26 , V_28 , V_25 ) ;
}
static T_1 F_13 ( T_3 V_25 , T_4 V_27 )
{
return 0x10 + V_27 ;
}
static T_1 F_14 ( T_3 V_25 , T_4 V_27 )
{
return 0x80 + ( 0x08 * V_25 ) + V_27 ;
}
static T_3 F_15 ( const void T_2 * V_7 , unsigned V_27 )
{
return F_16 ( V_7 + V_27 ) ;
}
static void F_17 ( void T_2 * V_7 , unsigned V_27 , T_3 V_29 )
{
F_18 ( V_29 , V_7 + V_27 ) ;
}
static T_4 F_19 ( const void T_2 * V_7 , unsigned V_27 )
{
return F_20 ( V_7 + V_27 ) ;
}
static void F_21 ( void T_2 * V_7 , unsigned V_27 , T_4 V_29 )
{
F_22 ( V_29 , V_7 + V_27 ) ;
}
static T_1 F_23 ( const void T_2 * V_7 , unsigned V_27 )
{
return F_24 ( V_7 + V_27 ) ;
}
static void F_25 ( void T_2 * V_7 , unsigned V_27 , T_1 V_29 )
{
F_26 ( V_29 , V_7 + V_27 ) ;
}
static void F_27 ( struct V_30 * V_31 , T_4 V_32 ,
const T_3 * V_33 )
{
struct V_1 * V_1 = V_31 -> V_1 ;
void T_2 * V_34 = V_31 -> V_34 ;
if ( F_28 ( V_32 == 0 ) )
return;
F_29 ( ( T_3 * ) V_33 ) ;
F_30 ( V_1 -> V_35 , L_1 ,
'T' , V_31 -> V_25 , V_34 , V_32 , V_33 ) ;
if ( F_31 ( ( 0x01 & ( unsigned long ) V_33 ) == 0 ) ) {
T_4 V_36 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_33 ) == 0 ) {
if ( V_32 >= 4 ) {
F_32 ( V_34 , V_33 + V_36 , V_32 >> 2 ) ;
V_36 += V_32 & ~ 0x03 ;
}
if ( V_32 & 0x02 ) {
F_22 ( * ( T_4 * ) & V_33 [ V_36 ] , V_34 ) ;
V_36 += 2 ;
}
} else {
if ( V_32 >= 2 ) {
F_33 ( V_34 , V_33 + V_36 , V_32 >> 1 ) ;
V_36 += V_32 & ~ 0x01 ;
}
}
if ( V_32 & 0x01 )
F_18 ( V_33 [ V_36 ] , V_34 ) ;
} else {
F_34 ( V_34 , V_33 , V_32 ) ;
}
}
static void F_35 ( struct V_30 * V_31 , T_4 V_32 , T_3 * V_37 )
{
struct V_1 * V_1 = V_31 -> V_1 ;
void T_2 * V_34 = V_31 -> V_34 ;
if ( F_28 ( V_32 == 0 ) )
return;
F_30 ( V_1 -> V_35 , L_1 ,
'R' , V_31 -> V_25 , V_34 , V_32 , V_37 ) ;
if ( F_31 ( ( 0x01 & ( unsigned long ) V_37 ) == 0 ) ) {
T_4 V_36 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_37 ) == 0 ) {
if ( V_32 >= 4 ) {
F_36 ( V_34 , V_37 , V_32 >> 2 ) ;
V_36 = V_32 & ~ 0x03 ;
}
if ( V_32 & 0x02 ) {
* ( T_4 * ) & V_37 [ V_36 ] = F_20 ( V_34 ) ;
V_36 += 2 ;
}
} else {
if ( V_32 >= 2 ) {
F_37 ( V_34 , V_37 , V_32 >> 1 ) ;
V_36 = V_32 & ~ 0x01 ;
}
}
if ( V_32 & 0x01 )
V_37 [ V_36 ] = F_16 ( V_34 ) ;
} else {
F_38 ( V_34 , V_37 , V_32 ) ;
}
}
void F_39 ( struct V_30 * V_31 , T_4 V_32 , T_3 * V_37 )
{
return V_31 -> V_1 -> V_38 . V_39 ( V_31 , V_32 , V_37 ) ;
}
void F_40 ( struct V_30 * V_31 , T_4 V_32 , const T_3 * V_33 )
{
return V_31 -> V_1 -> V_38 . V_40 ( V_31 , V_32 , V_33 ) ;
}
void F_41 ( struct V_1 * V_1 )
{
void T_2 * V_41 = V_1 -> V_42 [ 0 ] . V_41 ;
F_42 ( V_1 -> V_43 , 0 ) ;
F_40 ( V_1 -> V_44 ,
sizeof( V_45 ) , V_45 ) ;
F_43 ( V_41 , V_46 , V_47 ) ;
}
static void F_44 ( unsigned long V_29 )
{
struct V_1 * V_1 = (struct V_1 * ) V_29 ;
unsigned long V_48 ;
F_45 ( & V_1 -> V_49 , V_48 ) ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_53 :
F_30 ( V_1 -> V_35 , L_2 ) ;
F_46 ( V_1 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
V_1 -> V_55 = 0 ;
break;
case V_56 :
case V_57 :
F_30 ( V_1 -> V_35 , L_3 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
F_48 ( V_1 , 0 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_58 ;
break;
default:
F_30 ( V_1 -> V_35 , L_4 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
F_49 ( & V_1 -> V_49 , V_48 ) ;
}
void F_50 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = V_1 -> V_60 ;
void T_2 * V_26 = V_1 -> V_43 ;
T_3 V_6 ;
F_30 ( V_1 -> V_35 , L_5 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_61 :
F_46 ( V_1 ) ;
F_30 ( V_1 -> V_35 , L_6 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
break;
case V_62 :
F_30 ( V_1 -> V_35 , L_7 ) ;
if ( V_60 )
V_60 -> V_63 . V_64 = 0 ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
F_51 ( V_1 ) ;
V_6 = F_5 ( V_26 , V_14 ) ;
V_6 |= V_15 ;
F_6 ( V_26 , V_14 , V_6 ) ;
break;
default:
F_30 ( V_1 -> V_35 , L_8 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
V_1 -> V_65 &= ~ ( V_66 << 16 ) ;
}
static T_5 F_52 ( struct V_1 * V_1 , T_3 V_67 ,
T_3 V_68 )
{
T_5 V_69 = V_70 ;
F_30 ( V_1 -> V_35 , L_9 , V_68 ,
V_67 ) ;
if ( V_67 & V_71 ) {
V_69 = V_72 ;
F_30 ( V_1 -> V_35 , L_10 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
if ( V_68 & V_73 ) {
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_56 :
V_1 -> V_65 |=
( V_74 << 16 )
| V_75 ;
V_1 -> V_76 = V_77
+ F_53 ( V_78 ) ;
V_1 -> V_79 = 1 ;
V_1 -> V_50 -> V_51 -> V_52 = V_80 ;
V_1 -> V_55 = 1 ;
F_54 ( V_1 ) ;
break;
case V_53 :
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
V_1 -> V_55 = 1 ;
F_51 ( V_1 ) ;
break;
default:
F_55 ( L_11 ,
L_12 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
} else {
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_56 :
V_1 -> V_50 -> V_51 -> V_52 = V_80 ;
F_54 ( V_1 ) ;
break;
case V_53 :
case V_54 :
if ( ( V_68 & V_81 )
!= ( 3 << V_82 )
) {
V_1 -> V_67 |= V_83 ;
V_1 -> V_67 &= ~ V_84 ;
break;
}
F_56 ( V_1 ) ;
break;
case V_85 :
V_1 -> V_67 &= ~ V_84 ;
break;
default:
F_55 ( L_11 ,
L_13 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
}
}
if ( V_67 & V_86 ) {
void T_2 * V_26 = V_1 -> V_43 ;
if ( ( V_68 & V_81 ) == V_81
&& ( V_68 & V_87 ) ) {
F_30 ( V_1 -> V_35 , L_14 ) ;
return V_72 ;
}
F_30 ( V_1 -> V_35 , L_15 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
F_6 ( V_26 , V_88 , V_89 ) ;
V_1 -> V_90 = V_91 ;
V_1 -> V_50 -> V_51 -> V_52 = V_92 ;
F_57 ( V_1 ) ;
F_48 ( V_1 , 1 ) ;
V_69 = V_72 ;
}
if ( V_67 & V_93 ) {
int V_94 = 0 ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_80 :
case V_57 :
case V_95 :
if ( V_1 -> V_96 ) {
void T_2 * V_26 = V_1 -> V_43 ;
V_1 -> V_96 -- ;
V_94 = 1 ;
V_68 |= V_89 ;
F_6 ( V_26 , V_88 , V_68 ) ;
} else {
V_1 -> V_65 |=
V_97
| ( V_98 << 16 ) ;
}
break;
default:
break;
}
F_58 (ignore ? KERN_DEBUG : KERN_ERR, musb->controller,
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
if ( ! V_94 )
F_48 ( V_1 , 0 ) ;
V_69 = V_72 ;
}
if ( V_67 & V_84 ) {
F_30 ( V_1 -> V_35 , L_21 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) , V_68 ) ;
V_69 = V_72 ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_61 :
F_50 ( V_1 ) ;
F_54 ( V_1 ) ;
F_59 ( V_1 ) ;
F_60 ( V_1 , V_77
+ F_53 ( V_1 -> V_99
? : V_100 ) ) ;
break;
case V_85 :
if ( ! V_1 -> V_55 )
break;
case V_54 :
F_61 ( V_1 ) ;
V_1 -> V_55 = V_1 -> V_101 . V_102 ;
if ( V_1 -> V_55 ) {
V_1 -> V_50 -> V_51 -> V_52 = V_53 ;
F_30 ( V_1 -> V_35 , L_22 ) ;
F_62 ( & V_1 -> V_103 , V_77
+ F_53 (
V_104 ) ) ;
}
break;
case V_57 :
if ( V_1 -> V_99 != 0 )
F_60 ( V_1 , V_77
+ F_53 ( V_1 -> V_99 ) ) ;
break;
case V_80 :
V_1 -> V_50 -> V_51 -> V_52 = V_56 ;
V_1 -> V_55 = V_1 -> V_60 -> V_63 . V_102 ;
break;
case V_62 :
F_30 ( V_1 -> V_35 , L_23 ) ;
break;
default:
V_1 -> V_55 = 0 ;
break;
}
}
if ( V_67 & V_105 ) {
struct V_59 * V_60 = V_1 -> V_60 ;
V_69 = V_72 ;
V_1 -> V_55 = 1 ;
V_1 -> V_90 = V_91 ;
V_1 -> V_106 = V_1 -> V_107 ;
F_43 ( V_1 -> V_43 , V_108 , V_1 -> V_106 ) ;
V_1 -> V_109 = V_1 -> V_107 & 0xfffe ;
F_43 ( V_1 -> V_43 , V_110 , V_1 -> V_109 ) ;
F_6 ( V_1 -> V_43 , V_111 , 0xf7 ) ;
V_1 -> V_65 &= ~ ( V_112
| V_113
| V_114
) ;
V_1 -> V_65 |= V_115
| ( V_66 << 16 ) ;
if ( V_68 & V_116 )
V_1 -> V_65 |= V_112 ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_54 :
if ( V_67 & V_84 ) {
F_30 ( V_1 -> V_35 , L_24 ) ;
V_67 &= ~ V_84 ;
goto V_117;
} else
F_30 ( V_1 -> V_35 , L_25 ) ;
break;
case V_53 :
F_30 ( V_1 -> V_35 , L_26 ) ;
V_117:
V_1 -> V_50 -> V_51 -> V_52 = V_62 ;
if ( V_1 -> V_60 )
V_1 -> V_60 -> V_63 . V_64 = 1 ;
F_63 ( & V_1 -> V_103 ) ;
break;
default:
if ( ( V_68 & V_81 )
== ( 3 << V_82 ) ) {
V_1 -> V_50 -> V_51 -> V_52 = V_80 ;
if ( V_60 )
V_60 -> V_63 . V_64 = 0 ;
}
break;
}
F_64 ( V_1 ) ;
F_30 ( V_1 -> V_35 , L_27 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) , V_68 ) ;
}
if ( V_67 & V_83 ) {
F_30 ( V_1 -> V_35 , L_28 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ,
F_65 ( V_1 ) , V_68 ) ;
V_69 = V_72 ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_80 :
case V_56 :
F_54 ( V_1 ) ;
F_59 ( V_1 ) ;
if ( V_1 -> V_99 != 0 )
F_60 ( V_1 , V_77
+ F_53 ( V_1 -> V_99 ) ) ;
break;
case V_62 :
F_59 ( V_1 ) ;
if ( V_1 -> V_60 )
V_1 -> V_60 -> V_63 . V_64 = 0 ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
F_51 ( V_1 ) ;
F_46 ( V_1 ) ;
break;
case V_61 :
F_50 ( V_1 ) ;
F_59 ( V_1 ) ;
case V_53 :
case V_54 :
case V_85 :
F_46 ( V_1 ) ;
break;
default:
F_55 ( L_29 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
break;
}
}
if ( V_67 & V_118 ) {
V_69 = V_72 ;
if ( V_68 & V_73 ) {
F_66 ( V_1 -> V_35 , L_30 ) ;
if ( F_67 ( V_1 ) )
F_68 ( V_1 ) ;
} else {
F_30 ( V_1 -> V_35 , L_31 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_56 :
F_69 ( V_1 ) ;
case V_57 :
F_30 ( V_1 -> V_35 , L_32 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ,
F_70 ( V_1 ) ) ;
F_62 ( & V_1 -> V_103 , V_77
+ F_53 ( F_70 ( V_1 ) ) ) ;
break;
case V_61 :
F_63 ( & V_1 -> V_103 ) ;
F_69 ( V_1 ) ;
break;
case V_53 :
F_30 ( V_1 -> V_35 , L_33 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
F_69 ( V_1 ) ;
break;
case V_85 :
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
case V_54 :
F_69 ( V_1 ) ;
break;
default:
F_30 ( V_1 -> V_35 , L_34 ,
F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
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
F_71 ( & V_1 -> V_119 ) ;
return V_69 ;
}
static void F_72 ( struct V_1 * V_1 )
{
void T_2 * V_26 = V_1 -> V_43 ;
T_4 V_120 ;
F_6 ( V_26 , V_111 , 0 ) ;
V_1 -> V_106 = 0 ;
F_43 ( V_26 , V_108 , 0 ) ;
V_1 -> V_109 = 0 ;
F_43 ( V_26 , V_110 , 0 ) ;
V_120 = F_5 ( V_26 , V_121 ) ;
V_120 = F_73 ( V_26 , V_122 ) ;
V_120 = F_73 ( V_26 , V_123 ) ;
}
static void F_74 ( struct V_1 * V_1 )
{
void T_2 * V_41 = V_1 -> V_43 ;
V_1 -> V_106 = V_1 -> V_107 ;
F_43 ( V_41 , V_108 , V_1 -> V_106 ) ;
V_1 -> V_109 = V_1 -> V_107 & 0xfffe ;
F_43 ( V_41 , V_110 , V_1 -> V_109 ) ;
F_6 ( V_41 , V_111 , 0xf7 ) ;
}
static void F_75 ( struct V_1 * V_1 )
{
void T_2 * V_26 = V_1 -> V_43 ;
F_72 ( V_1 ) ;
F_6 ( V_26 , V_88 , 0 ) ;
}
void F_76 ( struct V_1 * V_1 )
{
void T_2 * V_41 = V_1 -> V_43 ;
T_3 V_68 = F_5 ( V_41 , V_88 ) ;
T_3 V_11 ;
F_30 ( V_1 -> V_35 , L_35 , V_68 ) ;
F_74 ( V_1 ) ;
F_6 ( V_41 , V_124 , 0 ) ;
V_11 = V_125 ;
if ( V_1 -> V_126 -> V_127 == V_128 ||
V_1 -> V_126 -> V_127 == V_129 )
V_11 |= V_130 ;
F_6 ( V_41 , V_14 , V_11 ) ;
V_1 -> V_55 = 0 ;
V_68 = F_5 ( V_41 , V_88 ) ;
V_68 &= ~ V_89 ;
if ( V_1 -> V_131 != V_132 &&
V_1 -> V_50 -> V_51 -> V_52 != V_57 &&
( V_68 & V_81 ) == V_81 ) {
V_1 -> V_55 = 1 ;
} else {
V_68 |= V_89 ;
}
F_77 ( V_1 ) ;
F_6 ( V_41 , V_88 , V_68 ) ;
}
void F_78 ( struct V_1 * V_1 )
{
F_79 ( V_1 ) ;
F_75 ( V_1 ) ;
F_30 ( V_1 -> V_35 , L_36 ) ;
F_60 ( V_1 , 0 ) ;
}
static void F_80 ( struct V_133 * V_134 )
{
struct V_1 * V_1 = F_1 ( & V_134 -> V_3 ) ;
unsigned long V_48 ;
F_4 ( V_1 -> V_35 ) ;
F_81 ( V_1 ) ;
F_82 ( V_1 ) ;
F_45 ( & V_1 -> V_49 , V_48 ) ;
F_79 ( V_1 ) ;
F_75 ( V_1 ) ;
F_49 ( & V_1 -> V_49 , V_48 ) ;
F_6 ( V_1 -> V_43 , V_88 , 0 ) ;
F_83 ( V_1 ) ;
F_7 ( V_1 -> V_35 ) ;
}
static int
F_84 ( struct V_1 * V_1 , struct V_30 * V_31 ,
const struct V_135 * V_136 , T_4 V_27 )
{
void T_2 * V_26 = V_1 -> V_43 ;
int V_137 = 0 ;
T_4 V_138 = V_136 -> V_138 ;
T_4 V_139 = V_27 >> 3 ;
T_3 V_140 ;
V_137 = F_85 ( F_86 ( V_138 , ( T_4 ) 8 ) ) - 1 ;
V_138 = 1 << V_137 ;
V_140 = V_137 - 3 ;
if ( V_136 -> V_141 == V_142 ) {
if ( ( V_27 + ( V_138 << 1 ) ) >
( 1 << ( V_1 -> V_126 -> V_143 + 2 ) ) )
return - V_144 ;
V_140 |= V_145 ;
} else {
if ( ( V_27 + V_138 ) > ( 1 << ( V_1 -> V_126 -> V_143 + 2 ) ) )
return - V_144 ;
}
F_6 ( V_26 , V_28 , V_31 -> V_25 ) ;
if ( V_31 -> V_25 == 1 )
V_1 -> V_146 = V_31 ;
switch ( V_136 -> V_147 ) {
case V_148 :
F_87 ( V_26 , V_140 ) ;
F_88 ( V_26 , V_139 ) ;
V_31 -> V_149 = ! ! ( V_140 & V_145 ) ;
V_31 -> V_150 = V_138 ;
break;
case V_151 :
F_89 ( V_26 , V_140 ) ;
F_90 ( V_26 , V_139 ) ;
V_31 -> V_152 = ! ! ( V_140 & V_145 ) ;
V_31 -> V_153 = V_138 ;
break;
case V_154 :
F_87 ( V_26 , V_140 ) ;
F_88 ( V_26 , V_139 ) ;
V_31 -> V_152 = ! ! ( V_140 & V_145 ) ;
V_31 -> V_153 = V_138 ;
F_89 ( V_26 , V_140 ) ;
F_90 ( V_26 , V_139 ) ;
V_31 -> V_149 = V_31 -> V_152 ;
V_31 -> V_150 = V_138 ;
V_31 -> V_155 = true ;
break;
}
V_1 -> V_107 |= ( 1 << V_31 -> V_25 ) ;
return V_27 + ( V_138 << ( ( V_140 & V_145 ) ? 1 : 0 ) ) ;
}
static int F_91 ( struct V_1 * V_1 )
{
const struct V_135 * V_136 ;
unsigned V_9 , V_156 ;
int V_27 ;
struct V_30 * V_31 = V_1 -> V_42 ;
if ( V_1 -> V_126 -> V_157 ) {
V_136 = V_1 -> V_126 -> V_157 ;
V_156 = V_1 -> V_126 -> V_158 ;
goto V_159;
}
switch ( V_160 ) {
default:
V_160 = 0 ;
case 0 :
V_136 = V_161 ;
V_156 = F_92 ( V_161 ) ;
break;
case 1 :
V_136 = V_162 ;
V_156 = F_92 ( V_162 ) ;
break;
case 2 :
V_136 = V_163 ;
V_156 = F_92 ( V_163 ) ;
break;
case 3 :
V_136 = V_164 ;
V_156 = F_92 ( V_164 ) ;
break;
case 4 :
V_136 = V_165 ;
V_156 = F_92 ( V_165 ) ;
break;
case 5 :
V_136 = V_166 ;
V_156 = F_92 ( V_166 ) ;
break;
}
F_93 ( V_167 L_37 ,
V_168 , V_160 ) ;
V_159:
V_27 = F_84 ( V_1 , V_31 , & V_169 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_156 ; V_9 ++ ) {
T_3 V_170 = V_136 -> V_171 ;
if ( V_170 >= V_1 -> V_126 -> V_172 ) {
F_94 ( L_38 ,
V_168 , V_170 ) ;
return - V_173 ;
}
V_27 = F_84 ( V_1 , V_31 + V_170 , V_136 ++ , V_27 ) ;
if ( V_27 < 0 ) {
F_94 ( L_39 ,
V_168 , V_170 ) ;
return V_27 ;
}
V_170 ++ ;
V_1 -> V_174 = F_86 ( V_170 , V_1 -> V_174 ) ;
}
F_93 ( V_167 L_40 ,
V_168 ,
V_156 + 1 , V_1 -> V_126 -> V_172 * 2 - 1 ,
V_27 , ( 1 << ( V_1 -> V_126 -> V_143 + 2 ) ) ) ;
if ( ! V_1 -> V_146 ) {
F_94 ( L_41 , V_168 ) ;
return - V_173 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_1 )
{
T_3 V_25 = 0 ;
struct V_30 * V_31 ;
void T_2 * V_26 = V_1 -> V_43 ;
int V_12 = 0 ;
F_30 ( V_1 -> V_35 , L_42 ) ;
for ( V_25 = 1 ; V_25 < V_1 -> V_126 -> V_172 ; V_25 ++ ) {
F_42 ( V_26 , V_25 ) ;
V_31 = V_1 -> V_42 + V_25 ;
V_12 = F_96 ( V_1 , V_31 , V_25 ) ;
if ( V_12 < 0 )
break;
if ( V_31 -> V_150 < 512
|| V_31 -> V_153 < 512 )
continue;
if ( V_1 -> V_146 )
continue;
V_1 -> V_146 = V_31 ;
}
if ( ! V_1 -> V_146 ) {
F_94 ( L_41 , V_168 ) ;
return - V_173 ;
}
return 0 ;
}
static int F_97 ( T_4 V_175 , struct V_1 * V_1 )
{
T_3 V_6 ;
char * type ;
char V_176 [ 90 ] , V_177 [ 32 ] , V_178 [ 12 ] ;
void T_2 * V_26 = V_1 -> V_43 ;
int V_179 = 0 ;
int V_9 ;
V_6 = F_98 ( V_26 ) ;
strcpy ( V_176 , ( V_6 & V_180 ) ? L_43 : L_44 ) ;
if ( V_6 & V_181 ) {
strcat ( V_176 , L_45 ) ;
V_1 -> V_182 = true ;
}
if ( V_6 & V_183 ) {
strcat ( V_176 , L_46 ) ;
V_1 -> V_184 = true ;
}
if ( V_6 & V_185 ) {
strcat ( V_176 , L_47 ) ;
V_1 -> V_186 = true ;
}
if ( V_6 & V_187 ) {
strcat ( V_176 , L_48 ) ;
V_1 -> V_188 = true ;
}
if ( V_6 & V_189 ) {
strcat ( V_176 , L_49 ) ;
V_1 -> V_190 = true ;
}
if ( V_6 & V_191 )
strcat ( V_176 , L_50 ) ;
F_93 ( V_167 L_51 ,
V_168 , V_6 , V_176 ) ;
V_178 [ 0 ] = 0 ;
if ( V_192 == V_175 ) {
V_1 -> V_193 = 1 ;
type = L_52 ;
} else {
V_1 -> V_193 = 0 ;
type = L_53 ;
#ifndef F_99
F_93 ( V_194
L_54 ,
V_168 ) ;
#endif
}
V_1 -> V_195 = F_100 ( V_26 ) ;
snprintf ( V_177 , 32 , L_55 , F_101 ( V_1 -> V_195 ) ,
F_102 ( V_1 -> V_195 ) ,
( V_1 -> V_195 & V_196 ) ? L_56 : L_53 ) ;
F_93 ( V_167 L_57 ,
V_168 , type , V_177 , V_178 ) ;
F_103 ( V_1 ) ;
V_1 -> V_174 = 1 ;
V_1 -> V_107 = 1 ;
if ( V_1 -> V_182 )
V_179 = F_91 ( V_1 ) ;
else
V_179 = F_95 ( V_1 ) ;
if ( V_179 < 0 )
return V_179 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_174 ; V_9 ++ ) {
struct V_30 * V_31 = V_1 -> V_42 + V_9 ;
V_31 -> V_34 = V_1 -> V_38 . V_197 ( V_9 ) + V_26 ;
#if F_104 ( V_198 )
if ( V_1 -> V_38 . V_199 & V_200 ) {
V_31 -> V_201 = V_1 -> V_202 + 0x400 +
V_1 -> V_38 . V_197 ( V_9 ) ;
V_31 -> V_203 = V_1 -> V_204 + 0x400 +
V_1 -> V_38 . V_197 ( V_9 ) ;
V_31 -> V_205 =
V_1 -> V_206 + 0x400 + V_1 -> V_38 . V_197 ( V_9 ) ;
if ( V_9 == 0 )
V_31 -> V_207 = V_26 - 0x400 + V_208 ;
else
V_31 -> V_207 = V_26 + 0x400 +
( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
}
#endif
V_31 -> V_41 = V_1 -> V_38 . V_209 ( V_9 , 0 ) + V_26 ;
V_31 -> V_210 = 1 ;
V_31 -> V_211 = 1 ;
if ( V_31 -> V_150 ) {
F_30 ( V_1 -> V_35 ,
L_58 ,
V_168 , V_9 ,
V_31 -> V_155 ? L_59 : L_60 ,
V_31 -> V_149
? L_61 : L_53 ,
V_31 -> V_150 ) ;
}
if ( V_31 -> V_153 && ! V_31 -> V_155 ) {
F_30 ( V_1 -> V_35 ,
L_58 ,
V_168 , V_9 ,
L_62 ,
V_31 -> V_152
? L_61 : L_53 ,
V_31 -> V_153 ) ;
}
if ( ! ( V_31 -> V_150 || V_31 -> V_153 ) )
F_30 ( V_1 -> V_35 , L_63 , V_9 ) ;
}
return 0 ;
}
T_5 F_105 ( struct V_1 * V_1 )
{
T_5 V_212 = V_70 ;
unsigned long V_179 ;
unsigned long V_25 ;
T_3 V_68 ;
if ( ! V_1 -> V_67 && ! V_1 -> V_213 && ! V_1 -> V_214 )
return V_70 ;
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
F_30 ( V_1 -> V_35 , L_64 ,
F_67 ( V_1 ) ? L_12 : L_13 ,
V_1 -> V_67 , V_1 -> V_213 , V_1 -> V_214 ) ;
if ( V_1 -> V_67 )
V_212 |= F_52 ( V_1 , V_1 -> V_67 , V_68 ) ;
if ( V_1 -> V_213 & 1 ) {
if ( F_67 ( V_1 ) )
V_212 |= F_106 ( V_1 ) ;
else
V_212 |= F_107 ( V_1 ) ;
V_1 -> V_213 &= ~ F_108 ( 0 ) ;
}
V_179 = V_1 -> V_213 ;
F_109 (epnum, &status, 16 ) {
V_212 = V_72 ;
if ( F_67 ( V_1 ) )
F_110 ( V_1 , V_25 ) ;
else
F_111 ( V_1 , V_25 ) ;
}
V_179 = V_1 -> V_214 ;
F_109 (epnum, &status, 16 ) {
V_212 = V_72 ;
if ( F_67 ( V_1 ) )
F_112 ( V_1 , V_25 ) ;
else
F_113 ( V_1 , V_25 ) ;
}
return V_212 ;
}
void F_114 ( struct V_1 * V_1 , T_3 V_25 , T_3 V_215 )
{
if ( ! V_25 ) {
if ( ! F_115 ( V_1 ) ) {
if ( F_67 ( V_1 ) )
F_106 ( V_1 ) ;
else
F_107 ( V_1 ) ;
}
} else {
if ( V_215 ) {
if ( F_67 ( V_1 ) )
F_110 ( V_1 , V_25 ) ;
else
F_111 ( V_1 , V_25 ) ;
} else {
if ( F_67 ( V_1 ) )
F_112 ( V_1 , V_25 ) ;
else
F_113 ( V_1 , V_25 ) ;
}
}
}
static T_6
F_116 ( struct V_2 * V_3 , struct V_216 * V_217 , char * V_218 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
int V_12 = - V_173 ;
F_45 ( & V_1 -> V_49 , V_48 ) ;
V_12 = sprintf ( V_218 , L_65 , F_47 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
F_49 ( & V_1 -> V_49 , V_48 ) ;
return V_12 ;
}
static T_6
F_117 ( struct V_2 * V_3 , struct V_216 * V_217 ,
const char * V_218 , T_7 V_156 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
int V_179 ;
F_45 ( & V_1 -> V_49 , V_48 ) ;
if ( F_118 ( V_218 , L_12 ) )
V_179 = F_119 ( V_1 , V_219 ) ;
else if ( F_118 ( V_218 , L_13 ) )
V_179 = F_119 ( V_1 , V_220 ) ;
else if ( F_118 ( V_218 , L_66 ) )
V_179 = F_119 ( V_1 , V_221 ) ;
else
V_179 = - V_173 ;
F_49 ( & V_1 -> V_49 , V_48 ) ;
return ( V_179 == 0 ) ? V_156 : V_179 ;
}
static T_6
F_120 ( struct V_2 * V_3 , struct V_216 * V_217 ,
const char * V_218 , T_7 V_156 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
unsigned long V_24 ;
if ( sscanf ( V_218 , L_67 , & V_24 ) < 1 ) {
F_66 ( V_3 , L_68 ) ;
return - V_173 ;
}
F_45 ( & V_1 -> V_49 , V_48 ) ;
V_1 -> V_99 = V_24 ? F_121 ( int , V_24 , V_100 ) : 0 ;
if ( V_1 -> V_50 -> V_51 -> V_52 == V_57 )
V_1 -> V_55 = 0 ;
F_60 ( V_1 , V_77 + F_53 ( V_24 ) ) ;
F_49 ( & V_1 -> V_49 , V_48 ) ;
return V_156 ;
}
static T_6
F_122 ( struct V_2 * V_3 , struct V_216 * V_217 , char * V_218 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
unsigned long V_24 ;
int V_222 ;
T_3 V_68 ;
F_45 ( & V_1 -> V_49 , V_48 ) ;
V_24 = V_1 -> V_99 ;
V_222 = F_123 ( V_1 ) ;
if ( V_222 < 0 ) {
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
if ( ( V_68 & V_81 )
== ( 3 << V_82 ) )
V_222 = 1 ;
else
V_222 = 0 ;
}
F_49 ( & V_1 -> V_49 , V_48 ) ;
return sprintf ( V_218 , L_69 ,
V_222 ? L_70 : L_71 , V_24 ) ;
}
static T_6
F_124 ( struct V_2 * V_3 , struct V_216 * V_217 ,
const char * V_218 , T_7 V_156 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_223 ;
if ( sscanf ( V_218 , L_72 , & V_223 ) != 1
|| ( V_223 != 1 ) ) {
F_66 ( V_3 , L_73 ) ;
return - V_173 ;
}
if ( V_223 == 1 )
F_125 ( V_1 ) ;
return V_156 ;
}
static void F_126 ( struct V_224 * V_29 )
{
struct V_1 * V_1 = F_127 ( V_29 , struct V_1 , V_119 ) ;
if ( V_1 -> V_50 -> V_51 -> V_52 != V_1 -> V_225 ) {
V_1 -> V_225 = V_1 -> V_50 -> V_51 -> V_52 ;
F_128 ( & V_1 -> V_35 -> V_226 , NULL , L_74 ) ;
}
}
static void F_68 ( struct V_1 * V_1 )
{
int V_12 ;
T_3 V_68 ;
F_72 ( V_1 ) ;
F_129 ( 10 ) ;
V_12 = F_130 ( V_1 ) ;
if ( V_12 ) {
F_74 ( V_1 ) ;
return;
}
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
V_68 &= ~ V_89 ;
F_6 ( V_1 -> V_43 , V_88 , V_68 ) ;
F_59 ( V_1 ) ;
if ( V_1 -> V_182 )
V_12 = F_91 ( V_1 ) ;
else
V_12 = F_95 ( V_1 ) ;
if ( V_12 == 0 )
F_76 ( V_1 ) ;
}
static struct V_1 * F_131 ( struct V_2 * V_3 ,
struct V_227 * V_126 , void T_2 * V_26 )
{
struct V_1 * V_1 ;
struct V_30 * V_228 ;
int V_25 ;
int V_12 ;
V_1 = F_132 ( V_3 , sizeof( * V_1 ) , V_229 ) ;
if ( ! V_1 )
return NULL ;
F_133 ( & V_1 -> V_230 ) ;
F_133 ( & V_1 -> V_231 ) ;
F_133 ( & V_1 -> V_232 ) ;
V_1 -> V_96 = V_233 ;
V_1 -> V_99 = V_100 ;
V_1 -> V_43 = V_26 ;
V_1 -> V_234 = V_26 ;
V_1 -> V_235 = - V_236 ;
V_1 -> V_126 = V_126 ;
F_134 ( V_1 -> V_126 -> V_172 > V_237 ) ;
for ( V_25 = 0 , V_228 = V_1 -> V_42 ;
V_25 < V_1 -> V_126 -> V_172 ;
V_25 ++ , V_228 ++ ) {
V_228 -> V_1 = V_1 ;
V_228 -> V_25 = V_25 ;
}
V_1 -> V_35 = V_3 ;
V_12 = F_135 ( V_1 ) ;
if ( V_12 < 0 )
goto V_238;
F_136 ( V_3 , V_1 ) ;
return V_1 ;
V_238:
return NULL ;
}
static void F_137 ( struct V_1 * V_1 )
{
#ifdef F_138
F_139 ( & V_1 -> V_35 -> V_226 , & V_239 ) ;
#endif
if ( V_1 -> V_235 >= 0 ) {
if ( V_1 -> V_240 )
F_140 ( V_1 -> V_235 ) ;
F_141 ( V_1 -> V_235 , V_1 ) ;
}
F_142 ( V_1 ) ;
}
static void F_143 ( struct V_224 * V_241 )
{
struct V_1 * V_1 ;
unsigned long V_48 ;
V_1 = F_127 ( V_241 , struct V_1 , V_242 . V_241 ) ;
F_45 ( & V_1 -> V_49 , V_48 ) ;
if ( V_1 -> V_65 & V_243 )
F_144 ( V_1 , false ) ;
F_49 ( & V_1 -> V_49 , V_48 ) ;
}
static int
F_145 ( struct V_2 * V_3 , int V_235 , void T_2 * V_244 )
{
int V_179 ;
struct V_1 * V_1 ;
struct V_245 * V_246 = F_146 ( V_3 ) ;
if ( ! V_246 ) {
F_30 ( V_3 , L_75 ) ;
V_179 = - V_236 ;
goto V_247;
}
V_1 = F_131 ( V_3 , V_246 -> V_126 , V_244 ) ;
if ( ! V_1 ) {
V_179 = - V_248 ;
goto V_247;
}
F_147 ( & V_1 -> V_49 ) ;
V_1 -> V_249 = V_246 -> V_250 ;
V_1 -> V_251 = V_246 -> V_251 ;
V_1 -> V_252 = V_246 -> V_253 ;
V_1 -> V_131 = V_246 -> V_141 ;
F_5 = F_15 ;
F_6 = F_17 ;
F_73 = F_19 ;
F_43 = F_21 ;
V_254 = F_23 ;
V_255 = F_25 ;
F_148 ( V_1 -> V_35 ) ;
F_149 ( V_1 -> V_35 , 200 ) ;
F_150 ( V_1 -> V_35 ) ;
V_179 = F_151 ( V_1 ) ;
if ( V_179 < 0 )
goto V_256;
if ( ! V_1 -> V_257 ) {
V_179 = - V_236 ;
goto V_258;
}
if ( V_1 -> V_252 -> V_199 )
V_1 -> V_38 . V_199 = V_1 -> V_252 -> V_199 ;
if ( V_1 -> V_38 . V_199 & V_259 ) {
V_1 -> V_38 . V_209 = F_13 ;
V_1 -> V_38 . V_260 = F_12 ;
} else {
V_1 -> V_38 . V_209 = F_11 ;
V_1 -> V_38 . V_260 = F_10 ;
}
if ( V_1 -> V_252 -> V_209 )
V_1 -> V_38 . V_209 = V_1 -> V_252 -> V_209 ;
if ( V_1 -> V_252 -> V_260 )
V_1 -> V_38 . V_260 = V_1 -> V_252 -> V_260 ;
if ( V_1 -> V_252 -> V_209 )
V_1 -> V_38 . V_209 = V_1 -> V_252 -> V_209 ;
if ( V_1 -> V_252 -> V_260 )
V_1 -> V_38 . V_260 = V_1 -> V_252 -> V_260 ;
if ( V_1 -> V_252 -> V_160 )
V_160 = V_1 -> V_252 -> V_160 ;
else
V_160 = 4 ;
if ( V_1 -> V_252 -> V_197 )
V_1 -> V_38 . V_197 = V_1 -> V_252 -> V_197 ;
else
V_1 -> V_38 . V_197 = F_9 ;
if ( V_1 -> V_252 -> V_261 )
V_1 -> V_38 . V_261 = V_1 -> V_252 -> V_261 ;
else
V_1 -> V_38 . V_261 = F_14 ;
if ( V_1 -> V_252 -> V_262 )
F_5 = V_1 -> V_252 -> V_262 ;
if ( V_1 -> V_252 -> V_263 )
F_6 = V_1 -> V_252 -> V_263 ;
if ( V_1 -> V_252 -> V_264 )
F_73 = V_1 -> V_252 -> V_264 ;
if ( V_1 -> V_252 -> V_265 )
F_43 = V_1 -> V_252 -> V_265 ;
if ( V_1 -> V_252 -> V_266 )
V_254 = V_1 -> V_252 -> V_266 ;
if ( V_1 -> V_252 -> V_267 )
V_255 = V_1 -> V_252 -> V_267 ;
#ifndef F_152
if ( ! V_1 -> V_252 -> V_268 || ! V_1 -> V_252 -> V_269 ) {
F_66 ( V_3 , L_76 ) ;
V_179 = - V_236 ;
goto V_258;
}
V_270 = V_1 -> V_252 -> V_268 ;
V_271 = V_1 -> V_252 -> V_269 ;
#endif
if ( V_1 -> V_252 -> V_39 )
V_1 -> V_38 . V_39 = V_1 -> V_252 -> V_39 ;
else
V_1 -> V_38 . V_39 = F_35 ;
if ( V_1 -> V_252 -> V_40 )
V_1 -> V_38 . V_40 = V_1 -> V_252 -> V_40 ;
else
V_1 -> V_38 . V_40 = F_27 ;
if ( ! V_1 -> V_50 -> V_272 ) {
V_1 -> V_50 -> V_13 = V_1 -> V_35 ;
V_1 -> V_50 -> V_8 = V_1 -> V_43 ;
V_1 -> V_50 -> V_272 = & V_273 ;
}
F_4 ( V_1 -> V_35 ) ;
if ( V_274 && V_3 -> V_275 ) {
V_1 -> V_276 =
V_270 ( V_1 , V_1 -> V_43 ) ;
if ( F_153 ( V_1 -> V_276 ) ) {
V_179 = F_154 ( V_1 -> V_276 ) ;
goto V_277;
}
}
F_79 ( V_1 ) ;
F_75 ( V_1 ) ;
F_155 ( & V_1 -> V_119 , F_126 ) ;
F_156 ( & V_1 -> V_242 , F_143 ) ;
F_156 ( & V_1 -> V_278 , V_279 ) ;
V_179 = F_97 ( V_246 -> V_126 -> V_280
? V_192
: V_281 , V_1 ) ;
if ( V_179 < 0 )
goto V_282;
F_157 ( & V_1 -> V_103 , F_44 , ( unsigned long ) V_1 ) ;
if ( F_158 ( V_235 , V_1 -> V_257 , 0 , F_159 ( V_3 ) , V_1 ) ) {
F_66 ( V_3 , L_77 , V_235 ) ;
V_179 = - V_236 ;
goto V_282;
}
V_1 -> V_235 = V_235 ;
if ( F_160 ( V_235 ) == 0 ) {
V_1 -> V_240 = 1 ;
F_161 ( V_3 , 1 ) ;
} else {
V_1 -> V_240 = 0 ;
}
if ( V_246 -> V_283 ) {
T_3 V_284 = F_162 ( V_1 -> V_43 ) ;
V_284 |= V_285 ;
F_163 ( V_1 -> V_43 , V_284 ) ;
}
if ( V_1 -> V_50 -> V_51 -> V_286 ) {
F_57 ( V_1 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_92 ;
} else {
F_51 ( V_1 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_85 ;
}
switch ( V_1 -> V_131 ) {
case V_132 :
V_179 = F_164 ( V_1 , V_246 -> V_11 ) ;
if ( V_179 < 0 )
goto V_282;
V_179 = F_119 ( V_1 , V_219 ) ;
break;
case V_287 :
V_179 = F_165 ( V_1 ) ;
if ( V_179 < 0 )
goto V_282;
V_179 = F_119 ( V_1 , V_220 ) ;
break;
case V_288 :
V_179 = F_164 ( V_1 , V_246 -> V_11 ) ;
if ( V_179 < 0 )
goto V_282;
V_179 = F_165 ( V_1 ) ;
if ( V_179 ) {
F_81 ( V_1 ) ;
goto V_282;
}
V_179 = F_119 ( V_1 , V_221 ) ;
break;
default:
F_66 ( V_3 , L_78 , V_1 -> V_131 ) ;
break;
}
if ( V_179 < 0 )
goto V_282;
V_179 = F_166 ( V_1 ) ;
if ( V_179 < 0 )
goto V_289;
V_179 = F_167 ( & V_1 -> V_35 -> V_226 , & V_239 ) ;
if ( V_179 )
goto V_290;
F_7 ( V_1 -> V_35 ) ;
F_168 ( V_1 -> V_35 ) ;
return 0 ;
V_290:
F_169 ( V_1 ) ;
V_289:
F_82 ( V_1 ) ;
F_81 ( V_1 ) ;
V_282:
F_170 ( & V_1 -> V_119 ) ;
F_171 ( & V_1 -> V_278 ) ;
F_171 ( & V_1 -> V_242 ) ;
if ( V_1 -> V_276 )
V_271 ( V_1 -> V_276 ) ;
V_277:
F_172 ( V_1 -> V_35 ) ;
V_258:
if ( V_1 -> V_240 )
F_161 ( V_3 , 0 ) ;
F_83 ( V_1 ) ;
V_256:
F_173 ( V_1 -> V_35 ) ;
F_66 ( V_1 -> V_35 ,
L_79 , V_179 ) ;
F_137 ( V_1 ) ;
V_247:
return V_179 ;
}
static int F_174 ( struct V_133 * V_134 )
{
struct V_2 * V_3 = & V_134 -> V_3 ;
int V_291 = F_175 ( V_134 , L_80 ) ;
struct V_292 * V_293 ;
void T_2 * V_294 ;
if ( V_291 <= 0 )
return - V_236 ;
V_293 = F_176 ( V_134 , V_295 , 0 ) ;
V_294 = F_177 ( V_3 , V_293 ) ;
if ( F_153 ( V_294 ) )
return F_154 ( V_294 ) ;
return F_145 ( V_3 , V_291 , V_294 ) ;
}
static int F_178 ( struct V_133 * V_134 )
{
struct V_2 * V_3 = & V_134 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_169 ( V_1 ) ;
F_80 ( V_134 ) ;
if ( V_1 -> V_276 )
V_271 ( V_1 -> V_276 ) ;
F_170 ( & V_1 -> V_119 ) ;
F_171 ( & V_1 -> V_278 ) ;
F_171 ( & V_1 -> V_242 ) ;
F_137 ( V_1 ) ;
F_161 ( V_3 , 0 ) ;
return 0 ;
}
static void F_179 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_296 = V_1 -> V_43 ;
void T_2 * V_297 ;
V_1 -> V_298 . V_299 = F_73 ( V_296 , V_300 ) ;
V_1 -> V_298 . V_301 = F_5 ( V_296 , V_124 ) ;
V_1 -> V_298 . V_284 = F_162 ( V_1 -> V_43 ) ;
V_1 -> V_298 . V_11 = F_5 ( V_296 , V_14 ) ;
V_1 -> V_298 . V_302 = F_5 ( V_296 , V_111 ) ;
V_1 -> V_298 . V_36 = F_5 ( V_296 , V_28 ) ;
V_1 -> V_298 . V_68 = F_5 ( V_296 , V_88 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_126 -> V_172 ; ++ V_9 ) {
struct V_30 * V_31 ;
V_31 = & V_1 -> V_42 [ V_9 ] ;
if ( ! V_31 )
continue;
V_297 = V_31 -> V_41 ;
if ( ! V_297 )
continue;
F_6 ( V_296 , V_28 , V_9 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_304 =
F_73 ( V_297 , V_305 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_306 =
F_73 ( V_297 , V_307 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_308 =
F_73 ( V_297 , V_309 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_310 =
F_73 ( V_297 , V_311 ) ;
if ( V_1 -> V_182 ) {
V_1 -> V_298 . V_303 [ V_9 ] . V_312 =
F_180 ( V_296 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_313 =
F_181 ( V_296 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_314 =
F_182 ( V_296 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_315 =
F_183 ( V_296 ) ;
}
V_1 -> V_298 . V_303 [ V_9 ] . V_316 =
F_5 ( V_297 , V_317 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_318 =
F_5 ( V_297 , V_319 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_320 =
F_5 ( V_297 , V_321 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_322 =
F_5 ( V_297 , V_323 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_324 =
F_184 ( V_1 , V_9 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_325 =
F_185 ( V_1 , V_9 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_326 =
F_186 ( V_1 , V_9 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_327 =
F_187 ( V_1 , V_9 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_328 =
F_188 ( V_1 , V_9 ) ;
V_1 -> V_298 . V_303 [ V_9 ] . V_329 =
F_189 ( V_1 , V_9 ) ;
}
}
static void F_190 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_296 = V_1 -> V_43 ;
void T_2 * V_297 ;
T_3 V_11 ;
F_43 ( V_296 , V_300 , V_1 -> V_298 . V_299 ) ;
F_6 ( V_296 , V_124 , V_1 -> V_298 . V_301 ) ;
F_163 ( V_1 -> V_43 , V_1 -> V_298 . V_284 ) ;
V_11 = F_5 ( V_296 , V_14 ) ;
V_11 &= V_15 | V_330 ;
V_1 -> V_298 . V_11 &= ~ ( V_15 | V_330 ) ;
V_11 |= V_1 -> V_298 . V_11 ;
F_6 ( V_296 , V_14 , V_11 ) ;
F_43 ( V_296 , V_108 , V_1 -> V_106 ) ;
F_43 ( V_296 , V_110 , V_1 -> V_109 ) ;
F_6 ( V_296 , V_111 , V_1 -> V_298 . V_302 ) ;
F_6 ( V_296 , V_88 , V_1 -> V_298 . V_68 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_126 -> V_172 ; ++ V_9 ) {
struct V_30 * V_31 ;
V_31 = & V_1 -> V_42 [ V_9 ] ;
if ( ! V_31 )
continue;
V_297 = V_31 -> V_41 ;
if ( ! V_297 )
continue;
F_6 ( V_296 , V_28 , V_9 ) ;
F_43 ( V_297 , V_305 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_304 ) ;
F_43 ( V_297 , V_307 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_306 ) ;
F_43 ( V_297 , V_309 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_308 ) ;
F_43 ( V_297 , V_311 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_310 ) ;
if ( V_1 -> V_182 ) {
F_87 ( V_296 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_314 ) ;
F_89 ( V_296 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_315 ) ;
F_88 ( V_296 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_312 ) ;
F_90 ( V_296 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_313 ) ;
}
F_6 ( V_297 , V_317 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_316 ) ;
F_6 ( V_297 , V_319 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_318 ) ;
F_6 ( V_297 , V_321 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_320 ) ;
F_6 ( V_297 , V_323 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_322 ) ;
F_191 ( V_1 , V_9 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_324 ) ;
F_192 ( V_1 , V_9 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_325 ) ;
F_193 ( V_1 , V_9 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_326 ) ;
F_194 ( V_1 , V_9 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_327 ) ;
F_195 ( V_1 , V_9 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_328 ) ;
F_196 ( V_1 , V_9 ,
V_1 -> V_298 . V_303 [ V_9 ] . V_329 ) ;
}
F_6 ( V_296 , V_28 , V_1 -> V_298 . V_36 ) ;
}
static int F_197 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_79 ( V_1 ) ;
F_75 ( V_1 ) ;
F_45 ( & V_1 -> V_49 , V_48 ) ;
if ( F_198 ( V_1 ) ) {
} else if ( F_67 ( V_1 ) ) {
}
F_179 ( V_1 ) ;
F_49 ( & V_1 -> V_49 , V_48 ) ;
return 0 ;
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_68 ;
T_3 V_331 ;
F_190 ( V_1 ) ;
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
V_331 = V_87 | V_332 | V_116 ;
if ( ( V_68 & V_331 ) != ( V_1 -> V_298 . V_68 & V_331 ) )
V_1 -> V_65 = 0 ;
if ( V_1 -> V_79 ) {
V_1 -> V_79 = 0 ;
F_200 ( & V_1 -> V_278 ,
F_53 ( V_78 ) ) ;
}
F_173 ( V_3 ) ;
F_201 ( V_3 ) ;
F_150 ( V_3 ) ;
F_76 ( V_1 ) ;
return 0 ;
}
static int F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_179 ( V_1 ) ;
return 0 ;
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_333 = 1 ;
if ( ! V_333 )
F_190 ( V_1 ) ;
V_333 = 0 ;
if ( V_1 -> V_79 ) {
V_1 -> V_79 = 0 ;
F_200 ( & V_1 -> V_278 ,
F_53 ( V_78 ) ) ;
}
return 0 ;
}
