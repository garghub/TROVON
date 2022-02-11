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
T_3 V_29 = F_16 ( V_7 + V_27 ) ;
F_17 ( F_18 ( 0 ) , V_7 , V_27 , V_29 ) ;
return V_29 ;
}
static void F_19 ( void T_2 * V_7 , unsigned V_27 , T_3 V_29 )
{
F_20 ( F_18 ( 0 ) , V_7 , V_27 , V_29 ) ;
F_21 ( V_29 , V_7 + V_27 ) ;
}
static T_4 F_22 ( const void T_2 * V_7 , unsigned V_27 )
{
T_4 V_29 = F_23 ( V_7 + V_27 ) ;
F_24 ( F_18 ( 0 ) , V_7 , V_27 , V_29 ) ;
return V_29 ;
}
static void F_25 ( void T_2 * V_7 , unsigned V_27 , T_4 V_29 )
{
F_26 ( F_18 ( 0 ) , V_7 , V_27 , V_29 ) ;
F_27 ( V_29 , V_7 + V_27 ) ;
}
static T_1 F_28 ( const void T_2 * V_7 , unsigned V_27 )
{
T_1 V_29 = F_29 ( V_7 + V_27 ) ;
F_30 ( F_18 ( 0 ) , V_7 , V_27 , V_29 ) ;
return V_29 ;
}
static void F_31 ( void T_2 * V_7 , unsigned V_27 , T_1 V_29 )
{
F_32 ( F_18 ( 0 ) , V_7 , V_27 , V_29 ) ;
F_33 ( V_29 , V_7 + V_27 ) ;
}
static void F_34 ( struct V_30 * V_31 , T_4 V_32 ,
const T_3 * V_33 )
{
struct V_1 * V_1 = V_31 -> V_1 ;
void T_2 * V_34 = V_31 -> V_34 ;
if ( F_35 ( V_32 == 0 ) )
return;
F_36 ( ( T_3 * ) V_33 ) ;
F_37 ( V_1 -> V_35 , L_1 ,
'T' , V_31 -> V_25 , V_34 , V_32 , V_33 ) ;
if ( F_38 ( ( 0x01 & ( unsigned long ) V_33 ) == 0 ) ) {
T_4 V_36 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_33 ) == 0 ) {
if ( V_32 >= 4 ) {
F_39 ( V_34 , V_33 + V_36 , V_32 >> 2 ) ;
V_36 += V_32 & ~ 0x03 ;
}
if ( V_32 & 0x02 ) {
F_27 ( * ( T_4 * ) & V_33 [ V_36 ] , V_34 ) ;
V_36 += 2 ;
}
} else {
if ( V_32 >= 2 ) {
F_40 ( V_34 , V_33 + V_36 , V_32 >> 1 ) ;
V_36 += V_32 & ~ 0x01 ;
}
}
if ( V_32 & 0x01 )
F_21 ( V_33 [ V_36 ] , V_34 ) ;
} else {
F_41 ( V_34 , V_33 , V_32 ) ;
}
}
static void F_42 ( struct V_30 * V_31 , T_4 V_32 , T_3 * V_37 )
{
struct V_1 * V_1 = V_31 -> V_1 ;
void T_2 * V_34 = V_31 -> V_34 ;
if ( F_35 ( V_32 == 0 ) )
return;
F_37 ( V_1 -> V_35 , L_1 ,
'R' , V_31 -> V_25 , V_34 , V_32 , V_37 ) ;
if ( F_38 ( ( 0x01 & ( unsigned long ) V_37 ) == 0 ) ) {
T_4 V_36 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_37 ) == 0 ) {
if ( V_32 >= 4 ) {
F_43 ( V_34 , V_37 , V_32 >> 2 ) ;
V_36 = V_32 & ~ 0x03 ;
}
if ( V_32 & 0x02 ) {
* ( T_4 * ) & V_37 [ V_36 ] = F_23 ( V_34 ) ;
V_36 += 2 ;
}
} else {
if ( V_32 >= 2 ) {
F_44 ( V_34 , V_37 , V_32 >> 1 ) ;
V_36 = V_32 & ~ 0x01 ;
}
}
if ( V_32 & 0x01 )
V_37 [ V_36 ] = F_16 ( V_34 ) ;
} else {
F_45 ( V_34 , V_37 , V_32 ) ;
}
}
void F_46 ( struct V_30 * V_31 , T_4 V_32 , T_3 * V_37 )
{
return V_31 -> V_1 -> V_38 . V_39 ( V_31 , V_32 , V_37 ) ;
}
void F_47 ( struct V_30 * V_31 , T_4 V_32 , const T_3 * V_33 )
{
return V_31 -> V_1 -> V_38 . V_40 ( V_31 , V_32 , V_33 ) ;
}
void F_48 ( struct V_1 * V_1 )
{
void T_2 * V_41 = V_1 -> V_42 [ 0 ] . V_41 ;
F_49 ( V_1 -> V_43 , 0 ) ;
F_47 ( V_1 -> V_44 ,
sizeof( V_45 ) , V_45 ) ;
F_50 ( V_41 , V_46 , V_47 ) ;
}
static void F_51 ( unsigned long V_29 )
{
struct V_1 * V_1 = (struct V_1 * ) V_29 ;
unsigned long V_48 ;
F_52 ( & V_1 -> V_49 , V_48 ) ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_53 :
F_53 ( V_1 ,
L_2 ) ;
F_54 ( V_1 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
V_1 -> V_55 = 0 ;
break;
case V_56 :
case V_57 :
F_53 ( V_1 , L_3 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
F_56 ( V_1 , 0 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_58 ;
break;
default:
F_53 ( V_1 , L_4 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
F_57 ( & V_1 -> V_49 , V_48 ) ;
}
void F_58 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = V_1 -> V_60 ;
void T_2 * V_26 = V_1 -> V_43 ;
T_3 V_6 ;
F_53 ( V_1 , L_5 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_61 :
F_54 ( V_1 ) ;
F_53 ( V_1 , L_6 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
break;
case V_62 :
F_53 ( V_1 , L_7 ) ;
if ( V_60 )
V_60 -> V_63 . V_64 = 0 ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
F_59 ( V_1 ) ;
V_6 = F_5 ( V_26 , V_14 ) ;
V_6 |= V_15 ;
F_6 ( V_26 , V_14 , V_6 ) ;
break;
default:
F_53 ( V_1 , L_8 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
V_1 -> V_65 &= ~ ( V_66 << 16 ) ;
}
static T_5 F_60 ( struct V_1 * V_1 , T_3 V_67 ,
T_3 V_68 )
{
T_5 V_69 = V_70 ;
F_53 ( V_1 , L_9 , V_68 , V_67 ) ;
if ( V_67 & V_71 ) {
V_69 = V_72 ;
F_53 ( V_1 , L_10 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
if ( V_68 & V_73 ) {
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_56 :
V_1 -> V_65 |=
( V_74 << 16 )
| V_75 ;
V_1 -> V_76 = V_77
+ F_61 ( V_78 ) ;
V_1 -> V_79 = 1 ;
V_1 -> V_50 -> V_51 -> V_52 = V_80 ;
V_1 -> V_55 = 1 ;
F_62 ( V_1 ) ;
break;
case V_53 :
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
V_1 -> V_55 = 1 ;
F_59 ( V_1 ) ;
break;
default:
F_63 ( L_11 ,
L_12 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
} else {
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_56 :
V_1 -> V_50 -> V_51 -> V_52 = V_80 ;
F_62 ( V_1 ) ;
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
F_64 ( V_1 ) ;
break;
case V_85 :
V_1 -> V_67 &= ~ V_84 ;
break;
default:
F_63 ( L_11 ,
L_13 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
}
}
}
if ( V_67 & V_86 ) {
void T_2 * V_26 = V_1 -> V_43 ;
if ( ( V_68 & V_81 ) == V_81
&& ( V_68 & V_87 ) ) {
F_53 ( V_1 , L_14 ) ;
return V_72 ;
}
F_53 ( V_1 , L_15 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
F_6 ( V_26 , V_88 , V_89 ) ;
V_1 -> V_90 = V_91 ;
V_1 -> V_50 -> V_51 -> V_52 = V_92 ;
F_65 ( V_1 ) ;
F_56 ( V_1 , 1 ) ;
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
F_66 (ignore ? KERN_DEBUG : KERN_ERR, musb->controller,
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
F_56 ( V_1 , 0 ) ;
V_69 = V_72 ;
}
if ( V_67 & V_84 ) {
F_53 ( V_1 , L_21 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) , V_68 ) ;
V_69 = V_72 ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_61 :
F_58 ( V_1 ) ;
F_62 ( V_1 ) ;
F_67 ( V_1 ) ;
F_68 ( V_1 , V_77
+ F_61 ( V_1 -> V_99
? : V_100 ) ) ;
break;
case V_85 :
if ( ! V_1 -> V_55 )
break;
case V_54 :
F_69 ( V_1 ) ;
V_1 -> V_55 = V_1 -> V_101 . V_102 ;
if ( V_1 -> V_55 ) {
V_1 -> V_50 -> V_51 -> V_52 = V_53 ;
F_53 ( V_1 , L_22 ) ;
F_70 ( & V_1 -> V_103 , V_77
+ F_61 (
V_104 ) ) ;
}
break;
case V_57 :
if ( V_1 -> V_99 != 0 )
F_68 ( V_1 , V_77
+ F_61 ( V_1 -> V_99 ) ) ;
break;
case V_80 :
V_1 -> V_50 -> V_51 -> V_52 = V_56 ;
V_1 -> V_55 = V_1 -> V_60 -> V_63 . V_102 ;
break;
case V_62 :
F_53 ( V_1 , L_23 ) ;
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
F_50 ( V_1 -> V_43 , V_108 , V_1 -> V_106 ) ;
V_1 -> V_109 = V_1 -> V_107 & 0xfffe ;
F_50 ( V_1 -> V_43 , V_110 , V_1 -> V_109 ) ;
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
F_53 ( V_1 , L_24 ) ;
V_67 &= ~ V_84 ;
goto V_117;
} else
F_53 ( V_1 , L_25 ) ;
break;
case V_53 :
F_53 ( V_1 , L_26 ) ;
V_117:
V_1 -> V_50 -> V_51 -> V_52 = V_62 ;
if ( V_1 -> V_60 )
V_1 -> V_60 -> V_63 . V_64 = 1 ;
F_71 ( & V_1 -> V_103 ) ;
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
F_72 ( V_1 ) ;
F_53 ( V_1 , L_27 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) , V_68 ) ;
}
if ( V_67 & V_83 ) {
F_53 ( V_1 , L_28 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ,
F_73 ( V_1 ) , V_68 ) ;
V_69 = V_72 ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_80 :
case V_56 :
F_62 ( V_1 ) ;
F_67 ( V_1 ) ;
if ( V_1 -> V_99 != 0 )
F_68 ( V_1 , V_77
+ F_61 ( V_1 -> V_99 ) ) ;
break;
case V_62 :
F_67 ( V_1 ) ;
if ( V_1 -> V_60 )
V_1 -> V_60 -> V_63 . V_64 = 0 ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
F_59 ( V_1 ) ;
F_54 ( V_1 ) ;
break;
case V_61 :
F_58 ( V_1 ) ;
F_67 ( V_1 ) ;
case V_53 :
case V_54 :
case V_85 :
F_54 ( V_1 ) ;
break;
default:
F_63 ( L_29 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
break;
}
}
if ( V_67 & V_118 ) {
V_69 = V_72 ;
if ( V_68 & V_73 ) {
F_74 ( V_1 -> V_35 , L_30 ) ;
if ( F_75 ( V_1 ) )
F_76 ( V_1 ) ;
} else {
F_53 ( V_1 , L_31 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
switch ( V_1 -> V_50 -> V_51 -> V_52 ) {
case V_56 :
F_77 ( V_1 ) ;
case V_57 :
F_53 ( V_1 , L_32 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ,
F_78 ( V_1 ) ) ;
F_70 ( & V_1 -> V_103 , V_77
+ F_61 ( F_78 ( V_1 ) ) ) ;
break;
case V_61 :
F_71 ( & V_1 -> V_103 ) ;
F_77 ( V_1 ) ;
break;
case V_53 :
F_53 ( V_1 , L_33 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
F_77 ( V_1 ) ;
break;
case V_85 :
V_1 -> V_50 -> V_51 -> V_52 = V_54 ;
case V_54 :
F_77 ( V_1 ) ;
break;
default:
F_53 ( V_1 , L_34 ,
F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
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
F_79 ( & V_1 -> V_119 ) ;
return V_69 ;
}
static void F_80 ( struct V_1 * V_1 )
{
void T_2 * V_26 = V_1 -> V_43 ;
T_4 V_120 ;
F_6 ( V_26 , V_111 , 0 ) ;
V_1 -> V_106 = 0 ;
F_50 ( V_26 , V_108 , 0 ) ;
V_1 -> V_109 = 0 ;
F_50 ( V_26 , V_110 , 0 ) ;
V_120 = F_5 ( V_26 , V_121 ) ;
V_120 = F_81 ( V_26 , V_122 ) ;
V_120 = F_81 ( V_26 , V_123 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
void T_2 * V_41 = V_1 -> V_43 ;
V_1 -> V_106 = V_1 -> V_107 ;
F_50 ( V_41 , V_108 , V_1 -> V_106 ) ;
V_1 -> V_109 = V_1 -> V_107 & 0xfffe ;
F_50 ( V_41 , V_110 , V_1 -> V_109 ) ;
F_6 ( V_41 , V_111 , 0xf7 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
void T_2 * V_26 = V_1 -> V_43 ;
F_80 ( V_1 ) ;
F_6 ( V_26 , V_88 , 0 ) ;
}
void F_84 ( struct V_1 * V_1 )
{
void T_2 * V_41 = V_1 -> V_43 ;
T_3 V_68 = F_5 ( V_41 , V_88 ) ;
T_3 V_11 ;
F_53 ( V_1 , L_35 , V_68 ) ;
F_82 ( V_1 ) ;
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
F_85 ( V_1 ) ;
F_6 ( V_41 , V_88 , V_68 ) ;
}
void F_86 ( struct V_1 * V_1 )
{
F_87 ( V_1 ) ;
F_83 ( V_1 ) ;
F_53 ( V_1 , L_36 ) ;
F_68 ( V_1 , 0 ) ;
}
static int
F_88 ( struct V_1 * V_1 , struct V_30 * V_31 ,
const struct V_133 * V_134 , T_4 V_27 )
{
void T_2 * V_26 = V_1 -> V_43 ;
int V_135 = 0 ;
T_4 V_136 = V_134 -> V_136 ;
T_4 V_137 = V_27 >> 3 ;
T_3 V_138 ;
V_135 = F_89 ( F_90 ( V_136 , ( T_4 ) 8 ) ) - 1 ;
V_136 = 1 << V_135 ;
V_138 = V_135 - 3 ;
if ( V_134 -> V_139 == V_140 ) {
if ( ( V_27 + ( V_136 << 1 ) ) >
( 1 << ( V_1 -> V_126 -> V_141 + 2 ) ) )
return - V_142 ;
V_138 |= V_143 ;
} else {
if ( ( V_27 + V_136 ) > ( 1 << ( V_1 -> V_126 -> V_141 + 2 ) ) )
return - V_142 ;
}
F_6 ( V_26 , V_28 , V_31 -> V_25 ) ;
if ( V_31 -> V_25 == 1 )
V_1 -> V_144 = V_31 ;
switch ( V_134 -> V_145 ) {
case V_146 :
F_91 ( V_26 , V_138 ) ;
F_92 ( V_26 , V_137 ) ;
V_31 -> V_147 = ! ! ( V_138 & V_143 ) ;
V_31 -> V_148 = V_136 ;
break;
case V_149 :
F_93 ( V_26 , V_138 ) ;
F_94 ( V_26 , V_137 ) ;
V_31 -> V_150 = ! ! ( V_138 & V_143 ) ;
V_31 -> V_151 = V_136 ;
break;
case V_152 :
F_91 ( V_26 , V_138 ) ;
F_92 ( V_26 , V_137 ) ;
V_31 -> V_150 = ! ! ( V_138 & V_143 ) ;
V_31 -> V_151 = V_136 ;
F_93 ( V_26 , V_138 ) ;
F_94 ( V_26 , V_137 ) ;
V_31 -> V_147 = V_31 -> V_150 ;
V_31 -> V_148 = V_136 ;
V_31 -> V_153 = true ;
break;
}
V_1 -> V_107 |= ( 1 << V_31 -> V_25 ) ;
return V_27 + ( V_136 << ( ( V_138 & V_143 ) ? 1 : 0 ) ) ;
}
static int F_95 ( struct V_1 * V_1 )
{
const struct V_133 * V_134 ;
unsigned V_9 , V_154 ;
int V_27 ;
struct V_30 * V_31 = V_1 -> V_42 ;
if ( V_1 -> V_126 -> V_155 ) {
V_134 = V_1 -> V_126 -> V_155 ;
V_154 = V_1 -> V_126 -> V_156 ;
goto V_157;
}
switch ( V_158 ) {
default:
V_158 = 0 ;
case 0 :
V_134 = V_159 ;
V_154 = F_96 ( V_159 ) ;
break;
case 1 :
V_134 = V_160 ;
V_154 = F_96 ( V_160 ) ;
break;
case 2 :
V_134 = V_161 ;
V_154 = F_96 ( V_161 ) ;
break;
case 3 :
V_134 = V_162 ;
V_154 = F_96 ( V_162 ) ;
break;
case 4 :
V_134 = V_163 ;
V_154 = F_96 ( V_163 ) ;
break;
case 5 :
V_134 = V_164 ;
V_154 = F_96 ( V_164 ) ;
break;
}
F_97 ( L_37 , V_165 , V_158 ) ;
V_157:
V_27 = F_88 ( V_1 , V_31 , & V_166 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_154 ; V_9 ++ ) {
T_3 V_167 = V_134 -> V_168 ;
if ( V_167 >= V_1 -> V_126 -> V_169 ) {
F_97 ( L_38 ,
V_165 , V_167 ) ;
return - V_170 ;
}
V_27 = F_88 ( V_1 , V_31 + V_167 , V_134 ++ , V_27 ) ;
if ( V_27 < 0 ) {
F_97 ( L_39 ,
V_165 , V_167 ) ;
return V_27 ;
}
V_167 ++ ;
V_1 -> V_171 = F_90 ( V_167 , V_1 -> V_171 ) ;
}
F_97 ( L_40 ,
V_165 ,
V_154 + 1 , V_1 -> V_126 -> V_169 * 2 - 1 ,
V_27 , ( 1 << ( V_1 -> V_126 -> V_141 + 2 ) ) ) ;
if ( ! V_1 -> V_144 ) {
F_97 ( L_41 , V_165 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_1 )
{
T_3 V_25 = 0 ;
struct V_30 * V_31 ;
void T_2 * V_26 = V_1 -> V_43 ;
int V_12 = 0 ;
F_53 ( V_1 , L_42 ) ;
for ( V_25 = 1 ; V_25 < V_1 -> V_126 -> V_169 ; V_25 ++ ) {
F_49 ( V_26 , V_25 ) ;
V_31 = V_1 -> V_42 + V_25 ;
V_12 = F_99 ( V_1 , V_31 , V_25 ) ;
if ( V_12 < 0 )
break;
if ( V_31 -> V_148 < 512
|| V_31 -> V_151 < 512 )
continue;
if ( V_1 -> V_144 )
continue;
V_1 -> V_144 = V_31 ;
}
if ( ! V_1 -> V_144 ) {
F_97 ( L_41 , V_165 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_100 ( T_4 V_172 , struct V_1 * V_1 )
{
T_3 V_6 ;
char * type ;
char V_173 [ 90 ] , V_174 [ 32 ] , V_175 [ 12 ] ;
void T_2 * V_26 = V_1 -> V_43 ;
int V_176 = 0 ;
int V_9 ;
V_6 = F_101 ( V_26 ) ;
strcpy ( V_173 , ( V_6 & V_177 ) ? L_43 : L_44 ) ;
if ( V_6 & V_178 ) {
strcat ( V_173 , L_45 ) ;
V_1 -> V_179 = true ;
}
if ( V_6 & V_180 ) {
strcat ( V_173 , L_46 ) ;
V_1 -> V_181 = true ;
}
if ( V_6 & V_182 ) {
strcat ( V_173 , L_47 ) ;
V_1 -> V_183 = true ;
}
if ( V_6 & V_184 ) {
strcat ( V_173 , L_48 ) ;
V_1 -> V_185 = true ;
}
if ( V_6 & V_186 ) {
strcat ( V_173 , L_49 ) ;
V_1 -> V_187 = true ;
}
if ( V_6 & V_188 )
strcat ( V_173 , L_50 ) ;
F_97 ( L_51 , V_165 , V_6 , V_173 ) ;
V_175 [ 0 ] = 0 ;
if ( V_189 == V_172 ) {
V_1 -> V_190 = 1 ;
type = L_52 ;
} else {
V_1 -> V_190 = 0 ;
type = L_53 ;
#ifndef F_102
F_103 ( L_54 ,
V_165 ) ;
#endif
}
V_1 -> V_191 = F_104 ( V_26 ) ;
snprintf ( V_174 , 32 , L_55 , F_105 ( V_1 -> V_191 ) ,
F_106 ( V_1 -> V_191 ) ,
( V_1 -> V_191 & V_192 ) ? L_56 : L_53 ) ;
F_97 ( L_57 ,
V_165 , type , V_174 , V_175 ) ;
F_107 ( V_1 ) ;
V_1 -> V_171 = 1 ;
V_1 -> V_107 = 1 ;
if ( V_1 -> V_179 )
V_176 = F_95 ( V_1 ) ;
else
V_176 = F_98 ( V_1 ) ;
if ( V_176 < 0 )
return V_176 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_171 ; V_9 ++ ) {
struct V_30 * V_31 = V_1 -> V_42 + V_9 ;
V_31 -> V_34 = V_1 -> V_38 . V_193 ( V_9 ) + V_26 ;
#if F_108 ( V_194 )
if ( V_1 -> V_38 . V_195 & V_196 ) {
V_31 -> V_197 = V_1 -> V_198 + 0x400 +
V_1 -> V_38 . V_193 ( V_9 ) ;
V_31 -> V_199 = V_1 -> V_200 + 0x400 +
V_1 -> V_38 . V_193 ( V_9 ) ;
V_31 -> V_201 =
V_1 -> V_202 + 0x400 + V_1 -> V_38 . V_193 ( V_9 ) ;
if ( V_9 == 0 )
V_31 -> V_203 = V_26 - 0x400 + V_204 ;
else
V_31 -> V_203 = V_26 + 0x400 +
( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
}
#endif
V_31 -> V_41 = V_1 -> V_38 . V_205 ( V_9 , 0 ) + V_26 ;
V_31 -> V_206 = 1 ;
V_31 -> V_207 = 1 ;
if ( V_31 -> V_148 ) {
F_53 ( V_1 , L_58 ,
V_165 , V_9 ,
V_31 -> V_153 ? L_59 : L_60 ,
V_31 -> V_147
? L_61 : L_53 ,
V_31 -> V_148 ) ;
}
if ( V_31 -> V_151 && ! V_31 -> V_153 ) {
F_53 ( V_1 , L_58 ,
V_165 , V_9 ,
L_62 ,
V_31 -> V_150
? L_61 : L_53 ,
V_31 -> V_151 ) ;
}
if ( ! ( V_31 -> V_148 || V_31 -> V_151 ) )
F_53 ( V_1 , L_63 , V_9 ) ;
}
return 0 ;
}
T_5 F_109 ( struct V_1 * V_1 )
{
T_5 V_208 = V_70 ;
unsigned long V_176 ;
unsigned long V_25 ;
T_3 V_68 ;
if ( ! V_1 -> V_67 && ! V_1 -> V_209 && ! V_1 -> V_210 )
return V_70 ;
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
F_110 ( V_1 ) ;
if ( V_1 -> V_67 )
V_208 |= F_60 ( V_1 , V_1 -> V_67 , V_68 ) ;
if ( V_1 -> V_209 & 1 ) {
if ( F_75 ( V_1 ) )
V_208 |= F_111 ( V_1 ) ;
else
V_208 |= F_112 ( V_1 ) ;
V_1 -> V_209 &= ~ F_113 ( 0 ) ;
}
V_176 = V_1 -> V_209 ;
F_114 (epnum, &status, 16 ) {
V_208 = V_72 ;
if ( F_75 ( V_1 ) )
F_115 ( V_1 , V_25 ) ;
else
F_116 ( V_1 , V_25 ) ;
}
V_176 = V_1 -> V_210 ;
F_114 (epnum, &status, 16 ) {
V_208 = V_72 ;
if ( F_75 ( V_1 ) )
F_117 ( V_1 , V_25 ) ;
else
F_118 ( V_1 , V_25 ) ;
}
return V_208 ;
}
void F_119 ( struct V_1 * V_1 , T_3 V_25 , T_3 V_211 )
{
if ( ! V_25 ) {
if ( ! F_120 ( V_1 ) ) {
if ( F_75 ( V_1 ) )
F_111 ( V_1 ) ;
else
F_112 ( V_1 ) ;
}
} else {
if ( V_211 ) {
if ( F_75 ( V_1 ) )
F_115 ( V_1 , V_25 ) ;
else
F_116 ( V_1 , V_25 ) ;
} else {
if ( F_75 ( V_1 ) )
F_117 ( V_1 , V_25 ) ;
else
F_118 ( V_1 , V_25 ) ;
}
}
}
int F_121 ( enum V_212 V_176 )
{
if ( V_213 )
return V_213 ( V_176 ) ;
return - V_214 ;
}
static T_6
F_122 ( struct V_2 * V_3 , struct V_215 * V_216 , char * V_217 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
int V_12 = - V_170 ;
F_52 ( & V_1 -> V_49 , V_48 ) ;
V_12 = sprintf ( V_217 , L_64 , F_55 ( V_1 -> V_50 -> V_51 -> V_52 ) ) ;
F_57 ( & V_1 -> V_49 , V_48 ) ;
return V_12 ;
}
static T_6
F_123 ( struct V_2 * V_3 , struct V_215 * V_216 ,
const char * V_217 , T_7 V_154 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
int V_176 ;
F_52 ( & V_1 -> V_49 , V_48 ) ;
if ( F_124 ( V_217 , L_12 ) )
V_176 = F_125 ( V_1 , V_218 ) ;
else if ( F_124 ( V_217 , L_13 ) )
V_176 = F_125 ( V_1 , V_219 ) ;
else if ( F_124 ( V_217 , L_65 ) )
V_176 = F_125 ( V_1 , V_220 ) ;
else
V_176 = - V_170 ;
F_57 ( & V_1 -> V_49 , V_48 ) ;
return ( V_176 == 0 ) ? V_154 : V_176 ;
}
static T_6
F_126 ( struct V_2 * V_3 , struct V_215 * V_216 ,
const char * V_217 , T_7 V_154 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
unsigned long V_24 ;
if ( sscanf ( V_217 , L_66 , & V_24 ) < 1 ) {
F_74 ( V_3 , L_67 ) ;
return - V_170 ;
}
F_52 ( & V_1 -> V_49 , V_48 ) ;
V_1 -> V_99 = V_24 ? F_127 ( int , V_24 , V_100 ) : 0 ;
if ( V_1 -> V_50 -> V_51 -> V_52 == V_57 )
V_1 -> V_55 = 0 ;
F_68 ( V_1 , V_77 + F_61 ( V_24 ) ) ;
F_57 ( & V_1 -> V_49 , V_48 ) ;
return V_154 ;
}
static T_6
F_128 ( struct V_2 * V_3 , struct V_215 * V_216 , char * V_217 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
unsigned long V_24 ;
int V_221 ;
T_3 V_68 ;
F_52 ( & V_1 -> V_49 , V_48 ) ;
V_24 = V_1 -> V_99 ;
V_221 = F_129 ( V_1 ) ;
if ( V_221 < 0 ) {
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
if ( ( V_68 & V_81 )
== ( 3 << V_82 ) )
V_221 = 1 ;
else
V_221 = 0 ;
}
F_57 ( & V_1 -> V_49 , V_48 ) ;
return sprintf ( V_217 , L_68 ,
V_221 ? L_69 : L_70 , V_24 ) ;
}
static T_6
F_130 ( struct V_2 * V_3 , struct V_215 * V_216 ,
const char * V_217 , T_7 V_154 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_222 ;
if ( sscanf ( V_217 , L_71 , & V_222 ) != 1
|| ( V_222 != 1 ) ) {
F_74 ( V_3 , L_72 ) ;
return - V_170 ;
}
if ( V_222 == 1 )
F_131 ( V_1 ) ;
return V_154 ;
}
static void F_132 ( struct V_223 * V_29 )
{
struct V_1 * V_1 = F_133 ( V_29 , struct V_1 , V_119 ) ;
if ( V_1 -> V_50 -> V_51 -> V_52 != V_1 -> V_224 ) {
V_1 -> V_224 = V_1 -> V_50 -> V_51 -> V_52 ;
F_134 ( & V_1 -> V_35 -> V_225 , NULL , L_73 ) ;
}
}
static void F_76 ( struct V_1 * V_1 )
{
int V_12 ;
T_3 V_68 ;
F_80 ( V_1 ) ;
F_135 ( 10 ) ;
V_12 = F_136 ( V_1 ) ;
if ( V_12 ) {
F_82 ( V_1 ) ;
return;
}
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
V_68 &= ~ V_89 ;
F_6 ( V_1 -> V_43 , V_88 , V_68 ) ;
F_67 ( V_1 ) ;
if ( V_1 -> V_179 )
V_12 = F_95 ( V_1 ) ;
else
V_12 = F_98 ( V_1 ) ;
if ( V_12 == 0 )
F_84 ( V_1 ) ;
}
static struct V_1 * F_137 ( struct V_2 * V_3 ,
const struct V_226 * V_126 , void T_2 * V_26 )
{
struct V_1 * V_1 ;
struct V_30 * V_227 ;
int V_25 ;
int V_12 ;
V_1 = F_138 ( V_3 , sizeof( * V_1 ) , V_228 ) ;
if ( ! V_1 )
return NULL ;
F_139 ( & V_1 -> V_229 ) ;
F_139 ( & V_1 -> V_230 ) ;
F_139 ( & V_1 -> V_231 ) ;
V_1 -> V_96 = V_232 ;
V_1 -> V_99 = V_100 ;
V_1 -> V_43 = V_26 ;
V_1 -> V_233 = V_26 ;
V_1 -> V_234 = - V_214 ;
V_1 -> V_126 = V_126 ;
F_140 ( V_1 -> V_126 -> V_169 > V_235 ) ;
for ( V_25 = 0 , V_227 = V_1 -> V_42 ;
V_25 < V_1 -> V_126 -> V_169 ;
V_25 ++ , V_227 ++ ) {
V_227 -> V_1 = V_1 ;
V_227 -> V_25 = V_25 ;
}
V_1 -> V_35 = V_3 ;
V_12 = F_141 ( V_1 ) ;
if ( V_12 < 0 )
goto V_236;
F_142 ( V_3 , V_1 ) ;
return V_1 ;
V_236:
return NULL ;
}
static void F_143 ( struct V_1 * V_1 )
{
#ifdef F_144
F_145 ( & V_1 -> V_35 -> V_225 , & V_237 ) ;
#endif
if ( V_1 -> V_234 >= 0 ) {
if ( V_1 -> V_238 )
F_146 ( V_1 -> V_234 ) ;
F_147 ( V_1 -> V_234 , V_1 ) ;
}
F_148 ( V_1 ) ;
}
static void F_149 ( struct V_223 * V_239 )
{
struct V_1 * V_1 ;
unsigned long V_48 ;
V_1 = F_133 ( V_239 , struct V_1 , V_240 . V_239 ) ;
F_52 ( & V_1 -> V_49 , V_48 ) ;
if ( V_1 -> V_65 & V_241 )
F_150 ( V_1 , false ) ;
F_57 ( & V_1 -> V_49 , V_48 ) ;
}
static int
F_151 ( struct V_2 * V_3 , int V_234 , void T_2 * V_242 )
{
int V_176 ;
struct V_1 * V_1 ;
struct V_243 * V_244 = F_152 ( V_3 ) ;
if ( ! V_244 ) {
F_74 ( V_3 , L_74 ) ;
V_176 = - V_214 ;
goto V_245;
}
V_1 = F_137 ( V_3 , V_244 -> V_126 , V_242 ) ;
if ( ! V_1 ) {
V_176 = - V_246 ;
goto V_245;
}
F_153 ( & V_1 -> V_49 ) ;
V_1 -> V_247 = V_244 -> V_248 ;
V_1 -> V_249 = V_244 -> V_249 ;
V_1 -> V_250 = V_244 -> V_251 ;
V_1 -> V_131 = V_244 -> V_139 ;
F_5 = F_15 ;
F_6 = F_19 ;
F_81 = F_22 ;
F_50 = F_25 ;
V_252 = F_28 ;
V_253 = F_31 ;
V_176 = F_154 ( V_1 ) ;
if ( V_176 < 0 )
goto V_254;
if ( ! V_1 -> V_255 ) {
V_176 = - V_214 ;
goto V_256;
}
if ( V_1 -> V_250 -> V_195 )
V_1 -> V_38 . V_195 = V_1 -> V_250 -> V_195 ;
if ( V_1 -> V_38 . V_195 & V_257 ) {
V_1 -> V_38 . V_205 = F_13 ;
V_1 -> V_38 . V_258 = F_12 ;
} else {
V_1 -> V_38 . V_205 = F_11 ;
V_1 -> V_38 . V_258 = F_10 ;
}
if ( V_1 -> V_250 -> V_205 )
V_1 -> V_38 . V_205 = V_1 -> V_250 -> V_205 ;
if ( V_1 -> V_250 -> V_258 )
V_1 -> V_38 . V_258 = V_1 -> V_250 -> V_258 ;
if ( V_1 -> V_250 -> V_205 )
V_1 -> V_38 . V_205 = V_1 -> V_250 -> V_205 ;
if ( V_1 -> V_250 -> V_258 )
V_1 -> V_38 . V_258 = V_1 -> V_250 -> V_258 ;
if ( V_1 -> V_250 -> V_158 )
V_158 = V_1 -> V_250 -> V_158 ;
else
V_158 = 4 ;
if ( V_1 -> V_250 -> V_193 )
V_1 -> V_38 . V_193 = V_1 -> V_250 -> V_193 ;
else
V_1 -> V_38 . V_193 = F_9 ;
if ( V_1 -> V_250 -> V_259 )
V_1 -> V_38 . V_259 = V_1 -> V_250 -> V_259 ;
else
V_1 -> V_38 . V_259 = F_14 ;
if ( V_1 -> V_250 -> V_260 )
F_5 = V_1 -> V_250 -> V_260 ;
if ( V_1 -> V_250 -> V_261 )
F_6 = V_1 -> V_250 -> V_261 ;
if ( V_1 -> V_250 -> V_262 )
F_81 = V_1 -> V_250 -> V_262 ;
if ( V_1 -> V_250 -> V_263 )
F_50 = V_1 -> V_250 -> V_263 ;
if ( V_1 -> V_250 -> V_264 )
V_252 = V_1 -> V_250 -> V_264 ;
if ( V_1 -> V_250 -> V_265 )
V_253 = V_1 -> V_250 -> V_265 ;
#ifndef F_155
if ( ! V_1 -> V_250 -> V_266 || ! V_1 -> V_250 -> V_267 ) {
F_74 ( V_3 , L_75 ) ;
V_176 = - V_214 ;
goto V_256;
}
V_268 = V_1 -> V_250 -> V_266 ;
V_269 = V_1 -> V_250 -> V_267 ;
#endif
if ( V_1 -> V_250 -> V_39 )
V_1 -> V_38 . V_39 = V_1 -> V_250 -> V_39 ;
else
V_1 -> V_38 . V_39 = F_42 ;
if ( V_1 -> V_250 -> V_40 )
V_1 -> V_38 . V_40 = V_1 -> V_250 -> V_40 ;
else
V_1 -> V_38 . V_40 = F_34 ;
if ( ! V_1 -> V_50 -> V_270 ) {
V_1 -> V_50 -> V_13 = V_1 -> V_35 ;
V_1 -> V_50 -> V_8 = V_1 -> V_43 ;
V_1 -> V_50 -> V_270 = & V_271 ;
}
if ( V_1 -> V_250 -> V_272 )
V_213 = V_1 -> V_250 -> V_272 ;
F_156 ( V_1 -> V_35 ) ;
F_157 ( V_1 -> V_35 , 500 ) ;
F_158 ( V_1 -> V_35 ) ;
F_4 ( V_1 -> V_35 ) ;
V_176 = F_159 ( V_1 -> V_50 ) ;
if ( V_176 < 0 )
goto V_273;
if ( V_274 && V_3 -> V_275 ) {
V_1 -> V_276 =
V_268 ( V_1 , V_1 -> V_43 ) ;
if ( F_160 ( V_1 -> V_276 ) ) {
V_176 = F_161 ( V_1 -> V_276 ) ;
goto V_277;
}
}
F_87 ( V_1 ) ;
F_83 ( V_1 ) ;
F_162 ( & V_1 -> V_119 , F_132 ) ;
F_163 ( & V_1 -> V_240 , F_149 ) ;
F_163 ( & V_1 -> V_278 , V_279 ) ;
V_176 = F_100 ( V_244 -> V_126 -> V_280
? V_189
: V_281 , V_1 ) ;
if ( V_176 < 0 )
goto V_282;
F_164 ( & V_1 -> V_103 , F_51 , ( unsigned long ) V_1 ) ;
if ( F_165 ( V_234 , V_1 -> V_255 , 0 , F_166 ( V_3 ) , V_1 ) ) {
F_74 ( V_3 , L_76 , V_234 ) ;
V_176 = - V_214 ;
goto V_282;
}
V_1 -> V_234 = V_234 ;
if ( F_167 ( V_234 ) == 0 ) {
V_1 -> V_238 = 1 ;
F_168 ( V_3 , 1 ) ;
} else {
V_1 -> V_238 = 0 ;
}
if ( V_244 -> V_283 ) {
T_3 V_284 = F_169 ( V_1 -> V_43 ) ;
V_284 |= V_285 ;
F_170 ( V_1 -> V_43 , V_284 ) ;
}
if ( V_1 -> V_50 -> V_51 -> V_286 ) {
F_65 ( V_1 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_92 ;
} else {
F_59 ( V_1 ) ;
V_1 -> V_50 -> V_51 -> V_52 = V_85 ;
}
switch ( V_1 -> V_131 ) {
case V_132 :
V_176 = F_171 ( V_1 , V_244 -> V_11 ) ;
if ( V_176 < 0 )
goto V_282;
V_176 = F_125 ( V_1 , V_218 ) ;
break;
case V_287 :
V_176 = F_172 ( V_1 ) ;
if ( V_176 < 0 )
goto V_282;
V_176 = F_125 ( V_1 , V_219 ) ;
break;
case V_288 :
V_176 = F_171 ( V_1 , V_244 -> V_11 ) ;
if ( V_176 < 0 )
goto V_282;
V_176 = F_172 ( V_1 ) ;
if ( V_176 ) {
F_173 ( V_1 ) ;
goto V_282;
}
V_176 = F_125 ( V_1 , V_220 ) ;
break;
default:
F_74 ( V_3 , L_77 , V_1 -> V_131 ) ;
break;
}
if ( V_176 < 0 )
goto V_282;
V_176 = F_174 ( V_1 ) ;
if ( V_176 < 0 )
goto V_289;
V_176 = F_175 ( & V_1 -> V_35 -> V_225 , & V_237 ) ;
if ( V_176 )
goto V_290;
F_176 ( V_1 -> V_35 ) ;
F_177 ( V_1 -> V_35 ) ;
return 0 ;
V_290:
F_178 ( V_1 ) ;
V_289:
F_179 ( V_1 ) ;
F_173 ( V_1 ) ;
V_282:
F_180 ( & V_1 -> V_119 ) ;
F_181 ( & V_1 -> V_278 ) ;
F_181 ( & V_1 -> V_240 ) ;
if ( V_1 -> V_276 )
V_269 ( V_1 -> V_276 ) ;
V_277:
F_182 ( V_1 -> V_50 ) ;
V_273:
F_183 ( V_1 -> V_35 ) ;
F_184 ( V_1 -> V_35 ) ;
F_185 ( V_1 -> V_35 ) ;
V_256:
if ( V_1 -> V_238 )
F_168 ( V_3 , 0 ) ;
F_186 ( V_1 ) ;
V_254:
F_74 ( V_1 -> V_35 ,
L_78 , V_176 ) ;
F_143 ( V_1 ) ;
V_245:
return V_176 ;
}
static int F_187 ( struct V_291 * V_292 )
{
struct V_2 * V_3 = & V_292 -> V_3 ;
int V_293 = F_188 ( V_292 , L_79 ) ;
struct V_294 * V_295 ;
void T_2 * V_296 ;
if ( V_293 <= 0 )
return - V_214 ;
V_295 = F_189 ( V_292 , V_297 , 0 ) ;
V_296 = F_190 ( V_3 , V_295 ) ;
if ( F_160 ( V_296 ) )
return F_161 ( V_296 ) ;
return F_151 ( V_3 , V_293 , V_296 ) ;
}
static int F_191 ( struct V_291 * V_292 )
{
struct V_2 * V_3 = & V_292 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_178 ( V_1 ) ;
F_180 ( & V_1 -> V_119 ) ;
F_181 ( & V_1 -> V_278 ) ;
F_181 ( & V_1 -> V_240 ) ;
F_4 ( V_1 -> V_35 ) ;
F_173 ( V_1 ) ;
F_179 ( V_1 ) ;
F_52 ( & V_1 -> V_49 , V_48 ) ;
F_87 ( V_1 ) ;
F_83 ( V_1 ) ;
F_57 ( & V_1 -> V_49 , V_48 ) ;
F_6 ( V_1 -> V_43 , V_88 , 0 ) ;
F_183 ( V_1 -> V_35 ) ;
F_184 ( V_1 -> V_35 ) ;
F_185 ( V_1 -> V_35 ) ;
F_186 ( V_1 ) ;
V_213 = NULL ;
if ( V_1 -> V_276 )
V_269 ( V_1 -> V_276 ) ;
F_182 ( V_1 -> V_50 ) ;
F_143 ( V_1 ) ;
F_168 ( V_3 , 0 ) ;
return 0 ;
}
static void F_192 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_298 = V_1 -> V_43 ;
void T_2 * V_299 ;
V_1 -> V_300 . V_301 = F_81 ( V_298 , V_302 ) ;
V_1 -> V_300 . V_303 = F_5 ( V_298 , V_124 ) ;
V_1 -> V_300 . V_284 = F_169 ( V_1 -> V_43 ) ;
V_1 -> V_300 . V_11 = F_5 ( V_298 , V_14 ) ;
V_1 -> V_300 . V_304 = F_5 ( V_298 , V_111 ) ;
V_1 -> V_300 . V_36 = F_5 ( V_298 , V_28 ) ;
V_1 -> V_300 . V_68 = F_5 ( V_298 , V_88 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_126 -> V_169 ; ++ V_9 ) {
struct V_30 * V_31 ;
V_31 = & V_1 -> V_42 [ V_9 ] ;
if ( ! V_31 )
continue;
V_299 = V_31 -> V_41 ;
if ( ! V_299 )
continue;
F_6 ( V_298 , V_28 , V_9 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_306 =
F_81 ( V_299 , V_307 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_308 =
F_81 ( V_299 , V_309 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_310 =
F_81 ( V_299 , V_311 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_312 =
F_81 ( V_299 , V_313 ) ;
if ( V_1 -> V_179 ) {
V_1 -> V_300 . V_305 [ V_9 ] . V_314 =
F_193 ( V_298 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_315 =
F_194 ( V_298 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_316 =
F_195 ( V_298 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_317 =
F_196 ( V_298 ) ;
}
V_1 -> V_300 . V_305 [ V_9 ] . V_318 =
F_5 ( V_299 , V_319 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_320 =
F_5 ( V_299 , V_321 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_322 =
F_5 ( V_299 , V_323 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_324 =
F_5 ( V_299 , V_325 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_326 =
F_197 ( V_1 , V_9 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_327 =
F_198 ( V_1 , V_9 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_328 =
F_199 ( V_1 , V_9 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_329 =
F_200 ( V_1 , V_9 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_330 =
F_201 ( V_1 , V_9 ) ;
V_1 -> V_300 . V_305 [ V_9 ] . V_331 =
F_202 ( V_1 , V_9 ) ;
}
}
static void F_203 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_298 = V_1 -> V_43 ;
void T_2 * V_299 ;
T_3 V_11 ;
F_50 ( V_298 , V_302 , V_1 -> V_300 . V_301 ) ;
F_6 ( V_298 , V_124 , V_1 -> V_300 . V_303 ) ;
F_170 ( V_1 -> V_43 , V_1 -> V_300 . V_284 ) ;
V_11 = F_5 ( V_298 , V_14 ) ;
V_11 &= V_15 | V_332 ;
V_1 -> V_300 . V_11 &= ~ ( V_15 | V_332 ) ;
V_11 |= V_1 -> V_300 . V_11 ;
F_6 ( V_298 , V_14 , V_11 ) ;
F_50 ( V_298 , V_108 , V_1 -> V_106 ) ;
F_50 ( V_298 , V_110 , V_1 -> V_109 ) ;
F_6 ( V_298 , V_111 , V_1 -> V_300 . V_304 ) ;
if ( V_1 -> V_300 . V_68 & V_89 )
F_6 ( V_298 , V_88 , V_1 -> V_300 . V_68 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_126 -> V_169 ; ++ V_9 ) {
struct V_30 * V_31 ;
V_31 = & V_1 -> V_42 [ V_9 ] ;
if ( ! V_31 )
continue;
V_299 = V_31 -> V_41 ;
if ( ! V_299 )
continue;
F_6 ( V_298 , V_28 , V_9 ) ;
F_50 ( V_299 , V_307 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_306 ) ;
F_50 ( V_299 , V_309 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_308 ) ;
F_50 ( V_299 , V_311 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_310 ) ;
F_50 ( V_299 , V_313 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_312 ) ;
if ( V_1 -> V_179 ) {
F_91 ( V_298 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_316 ) ;
F_93 ( V_298 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_317 ) ;
F_92 ( V_298 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_314 ) ;
F_94 ( V_298 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_315 ) ;
}
F_6 ( V_299 , V_319 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_318 ) ;
F_6 ( V_299 , V_321 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_320 ) ;
F_6 ( V_299 , V_323 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_322 ) ;
F_6 ( V_299 , V_325 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_324 ) ;
F_204 ( V_1 , V_9 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_326 ) ;
F_205 ( V_1 , V_9 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_327 ) ;
F_206 ( V_1 , V_9 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_328 ) ;
F_207 ( V_1 , V_9 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_329 ) ;
F_208 ( V_1 , V_9 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_330 ) ;
F_209 ( V_1 , V_9 ,
V_1 -> V_300 . V_305 [ V_9 ] . V_331 ) ;
}
F_6 ( V_298 , V_28 , V_1 -> V_300 . V_36 ) ;
}
static int F_210 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_87 ( V_1 ) ;
F_83 ( V_1 ) ;
F_52 ( & V_1 -> V_49 , V_48 ) ;
if ( F_211 ( V_1 ) ) {
} else if ( F_75 ( V_1 ) ) {
}
F_192 ( V_1 ) ;
F_57 ( & V_1 -> V_49 , V_48 ) ;
return 0 ;
}
static int F_212 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_68 ;
T_3 V_333 ;
F_203 ( V_1 ) ;
V_68 = F_5 ( V_1 -> V_43 , V_88 ) ;
V_333 = V_87 | V_334 | V_116 ;
if ( ( V_68 & V_333 ) != ( V_1 -> V_300 . V_68 & V_333 ) )
V_1 -> V_65 = 0 ;
if ( V_1 -> V_79 ) {
V_1 -> V_79 = 0 ;
F_213 ( & V_1 -> V_278 ,
F_61 ( V_78 ) ) ;
}
F_185 ( V_3 ) ;
F_214 ( V_3 ) ;
F_158 ( V_3 ) ;
F_84 ( V_1 ) ;
return 0 ;
}
static int F_215 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_192 ( V_1 ) ;
return 0 ;
}
static int F_216 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_335 = 1 ;
if ( ! V_335 )
F_203 ( V_1 ) ;
V_335 = 0 ;
if ( V_1 -> V_79 ) {
V_1 -> V_79 = 0 ;
F_213 ( & V_1 -> V_278 ,
F_61 ( V_78 ) ) ;
}
return 0 ;
}
