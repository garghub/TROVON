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
static int F_8 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_24 )
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
static T_1 F_11 ( T_3 V_25 , T_4 V_6 )
{
return 0x100 + ( 0x10 * V_25 ) + V_6 ;
}
static void F_12 ( void T_2 * V_26 , T_3 V_25 )
{
F_6 ( V_26 , V_27 , V_25 ) ;
}
static T_1 F_13 ( T_3 V_25 , T_4 V_6 )
{
return 0x10 + V_6 ;
}
static T_3 F_14 ( const void T_2 * V_7 , unsigned V_6 )
{
return F_15 ( V_7 + V_6 ) ;
}
static void F_16 ( void T_2 * V_7 , unsigned V_6 , T_3 V_24 )
{
F_17 ( V_24 , V_7 + V_6 ) ;
}
static T_4 F_18 ( const void T_2 * V_7 , unsigned V_6 )
{
return F_19 ( V_7 + V_6 ) ;
}
static void F_20 ( void T_2 * V_7 , unsigned V_6 , T_4 V_24 )
{
F_21 ( V_24 , V_7 + V_6 ) ;
}
static T_1 F_22 ( const void T_2 * V_7 , unsigned V_6 )
{
return F_23 ( V_7 + V_6 ) ;
}
static void F_24 ( void T_2 * V_7 , unsigned V_6 , T_1 V_24 )
{
F_25 ( V_24 , V_7 + V_6 ) ;
}
static void F_26 ( struct V_28 * V_29 , T_4 V_30 ,
const T_3 * V_31 )
{
struct V_1 * V_1 = V_29 -> V_1 ;
void T_2 * V_32 = V_29 -> V_32 ;
if ( F_27 ( V_30 == 0 ) )
return;
F_28 ( ( T_3 * ) V_31 ) ;
F_29 ( V_1 -> V_33 , L_1 ,
'T' , V_29 -> V_25 , V_32 , V_30 , V_31 ) ;
if ( F_30 ( ( 0x01 & ( unsigned long ) V_31 ) == 0 ) ) {
T_4 V_34 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_31 ) == 0 ) {
if ( V_30 >= 4 ) {
F_31 ( V_32 , V_31 + V_34 , V_30 >> 2 ) ;
V_34 += V_30 & ~ 0x03 ;
}
if ( V_30 & 0x02 ) {
F_32 ( V_32 , 0 , * ( T_4 * ) & V_31 [ V_34 ] ) ;
V_34 += 2 ;
}
} else {
if ( V_30 >= 2 ) {
F_33 ( V_32 , V_31 + V_34 , V_30 >> 1 ) ;
V_34 += V_30 & ~ 0x01 ;
}
}
if ( V_30 & 0x01 )
F_6 ( V_32 , 0 , V_31 [ V_34 ] ) ;
} else {
F_34 ( V_32 , V_31 , V_30 ) ;
}
}
static void F_35 ( struct V_28 * V_29 , T_4 V_30 , T_3 * V_35 )
{
struct V_1 * V_1 = V_29 -> V_1 ;
void T_2 * V_32 = V_29 -> V_32 ;
if ( F_27 ( V_30 == 0 ) )
return;
F_29 ( V_1 -> V_33 , L_1 ,
'R' , V_29 -> V_25 , V_32 , V_30 , V_35 ) ;
if ( F_30 ( ( 0x01 & ( unsigned long ) V_35 ) == 0 ) ) {
T_4 V_34 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_35 ) == 0 ) {
if ( V_30 >= 4 ) {
F_36 ( V_32 , V_35 , V_30 >> 2 ) ;
V_34 = V_30 & ~ 0x03 ;
}
if ( V_30 & 0x02 ) {
* ( T_4 * ) & V_35 [ V_34 ] = F_37 ( V_32 , 0 ) ;
V_34 += 2 ;
}
} else {
if ( V_30 >= 2 ) {
F_38 ( V_32 , V_35 , V_30 >> 1 ) ;
V_34 = V_30 & ~ 0x01 ;
}
}
if ( V_30 & 0x01 )
V_35 [ V_34 ] = F_5 ( V_32 , 0 ) ;
} else {
F_39 ( V_32 , V_35 , V_30 ) ;
}
}
void F_40 ( struct V_28 * V_29 , T_4 V_30 , T_3 * V_35 )
{
return V_29 -> V_1 -> V_36 . V_37 ( V_29 , V_30 , V_35 ) ;
}
void F_41 ( struct V_28 * V_29 , T_4 V_30 , const T_3 * V_31 )
{
return V_29 -> V_1 -> V_36 . V_38 ( V_29 , V_30 , V_31 ) ;
}
void F_42 ( struct V_1 * V_1 )
{
void T_2 * V_39 = V_1 -> V_40 [ 0 ] . V_39 ;
F_43 ( V_1 -> V_41 , 0 ) ;
F_41 ( V_1 -> V_42 ,
sizeof( V_43 ) , V_43 ) ;
F_32 ( V_39 , V_44 , V_45 ) ;
}
static void F_44 ( unsigned long V_24 )
{
struct V_1 * V_1 = (struct V_1 * ) V_24 ;
unsigned long V_46 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_51 :
F_29 ( V_1 -> V_33 , L_2 ) ;
F_46 ( V_1 ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
V_1 -> V_53 = 0 ;
break;
case V_54 :
case V_55 :
F_29 ( V_1 -> V_33 , L_3 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
F_48 ( V_1 , 0 ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_56 ;
break;
default:
F_29 ( V_1 -> V_33 , L_4 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
}
F_49 ( & V_1 -> V_47 , V_46 ) ;
}
void F_50 ( struct V_1 * V_1 )
{
struct V_57 * V_58 = V_1 -> V_58 ;
void T_2 * V_26 = V_1 -> V_41 ;
T_3 V_59 ;
F_29 ( V_1 -> V_33 , L_5 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_60 :
F_46 ( V_1 ) ;
F_29 ( V_1 -> V_33 , L_6 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
break;
case V_61 :
F_29 ( V_1 -> V_33 , L_7 ) ;
if ( V_58 )
V_58 -> V_62 . V_63 = 0 ;
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
F_51 ( V_1 ) ;
V_59 = F_5 ( V_26 , V_14 ) ;
V_59 |= V_15 ;
F_6 ( V_26 , V_14 , V_59 ) ;
break;
default:
F_29 ( V_1 -> V_33 , L_8 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
}
V_1 -> V_64 &= ~ ( V_65 << 16 ) ;
}
static T_5 F_52 ( struct V_1 * V_1 , T_3 V_66 ,
T_3 V_67 )
{
T_5 V_68 = V_69 ;
F_29 ( V_1 -> V_33 , L_9 , V_67 ,
V_66 ) ;
if ( V_66 & V_70 ) {
V_68 = V_71 ;
F_29 ( V_1 -> V_33 , L_10 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
if ( V_67 & V_72 ) {
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_54 :
V_1 -> V_64 |=
( V_73 << 16 )
| V_74 ;
V_1 -> V_75 = V_76
+ F_53 ( V_77 ) ;
V_1 -> V_78 = 1 ;
V_1 -> V_48 -> V_49 -> V_50 = V_79 ;
V_1 -> V_53 = 1 ;
F_54 ( V_1 ) ;
break;
case V_51 :
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
V_1 -> V_53 = 1 ;
F_51 ( V_1 ) ;
break;
default:
F_55 ( L_11 ,
L_12 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
}
} else {
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_54 :
V_1 -> V_48 -> V_49 -> V_50 = V_79 ;
F_54 ( V_1 ) ;
break;
case V_51 :
case V_52 :
if ( ( V_67 & V_80 )
!= ( 3 << V_81 )
) {
V_1 -> V_66 |= V_82 ;
V_1 -> V_66 &= ~ V_83 ;
break;
}
F_56 ( V_1 ) ;
break;
case V_84 :
V_1 -> V_66 &= ~ V_83 ;
break;
default:
F_55 ( L_11 ,
L_13 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
}
}
}
if ( V_66 & V_85 ) {
void T_2 * V_26 = V_1 -> V_41 ;
if ( ( V_67 & V_80 ) == V_80
&& ( V_67 & V_86 ) ) {
F_29 ( V_1 -> V_33 , L_14 ) ;
return V_71 ;
}
F_29 ( V_1 -> V_33 , L_15 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
F_6 ( V_26 , V_87 , V_88 ) ;
V_1 -> V_89 = V_90 ;
V_1 -> V_48 -> V_49 -> V_50 = V_91 ;
F_57 ( V_1 ) ;
F_48 ( V_1 , 1 ) ;
V_68 = V_71 ;
}
if ( V_66 & V_92 ) {
int V_93 = 0 ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_79 :
case V_55 :
case V_94 :
if ( V_1 -> V_95 ) {
void T_2 * V_26 = V_1 -> V_41 ;
V_1 -> V_95 -- ;
V_93 = 1 ;
V_67 |= V_88 ;
F_6 ( V_26 , V_87 , V_67 ) ;
} else {
V_1 -> V_64 |=
V_96
| ( V_97 << 16 ) ;
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
if ( ! V_93 )
F_48 ( V_1 , 0 ) ;
V_68 = V_71 ;
}
if ( V_66 & V_83 ) {
F_29 ( V_1 -> V_33 , L_21 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) , V_67 ) ;
V_68 = V_71 ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_60 :
F_50 ( V_1 ) ;
F_54 ( V_1 ) ;
F_59 ( V_1 ) ;
F_60 ( V_1 , V_76
+ F_53 ( V_1 -> V_98
? : V_99 ) ) ;
break;
case V_84 :
if ( ! V_1 -> V_53 )
break;
case V_52 :
F_61 ( V_1 ) ;
V_1 -> V_53 = V_1 -> V_100 . V_101 ;
if ( V_1 -> V_53 ) {
V_1 -> V_48 -> V_49 -> V_50 = V_51 ;
F_29 ( V_1 -> V_33 , L_22 ) ;
F_62 ( & V_1 -> V_102 , V_76
+ F_53 (
V_103 ) ) ;
}
break;
case V_55 :
if ( V_1 -> V_98 != 0 )
F_60 ( V_1 , V_76
+ F_53 ( V_1 -> V_98 ) ) ;
break;
case V_79 :
V_1 -> V_48 -> V_49 -> V_50 = V_54 ;
V_1 -> V_53 = V_1 -> V_58 -> V_62 . V_101 ;
break;
case V_61 :
F_29 ( V_1 -> V_33 , L_23 ) ;
break;
default:
V_1 -> V_53 = 0 ;
break;
}
}
if ( V_66 & V_104 ) {
struct V_57 * V_58 = V_1 -> V_58 ;
V_68 = V_71 ;
V_1 -> V_53 = 1 ;
V_1 -> V_89 = V_90 ;
V_1 -> V_105 = V_1 -> V_106 ;
F_32 ( V_1 -> V_41 , V_107 , V_1 -> V_105 ) ;
V_1 -> V_108 = V_1 -> V_106 & 0xfffe ;
F_32 ( V_1 -> V_41 , V_109 , V_1 -> V_108 ) ;
F_6 ( V_1 -> V_41 , V_110 , 0xf7 ) ;
V_1 -> V_64 &= ~ ( V_111
| V_112
| V_113
) ;
V_1 -> V_64 |= V_114
| ( V_65 << 16 ) ;
if ( V_67 & V_115 )
V_1 -> V_64 |= V_111 ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_52 :
if ( V_66 & V_83 ) {
F_29 ( V_1 -> V_33 , L_24 ) ;
V_66 &= ~ V_83 ;
goto V_116;
} else
F_29 ( V_1 -> V_33 , L_25 ) ;
break;
case V_51 :
F_29 ( V_1 -> V_33 , L_26 ) ;
V_116:
V_1 -> V_48 -> V_49 -> V_50 = V_61 ;
if ( V_1 -> V_58 )
V_1 -> V_58 -> V_62 . V_63 = 1 ;
F_63 ( & V_1 -> V_102 ) ;
break;
default:
if ( ( V_67 & V_80 )
== ( 3 << V_81 ) ) {
V_1 -> V_48 -> V_49 -> V_50 = V_79 ;
if ( V_58 )
V_58 -> V_62 . V_63 = 0 ;
}
break;
}
F_64 ( V_1 ) ;
F_29 ( V_1 -> V_33 , L_27 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) , V_67 ) ;
}
if ( V_66 & V_82 ) {
F_29 ( V_1 -> V_33 , L_28 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ,
F_65 ( V_1 ) , V_67 ) ;
V_68 = V_71 ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_79 :
case V_54 :
F_54 ( V_1 ) ;
F_59 ( V_1 ) ;
if ( V_1 -> V_98 != 0 )
F_60 ( V_1 , V_76
+ F_53 ( V_1 -> V_98 ) ) ;
break;
case V_61 :
F_59 ( V_1 ) ;
if ( V_1 -> V_58 )
V_1 -> V_58 -> V_62 . V_63 = 0 ;
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
F_51 ( V_1 ) ;
F_46 ( V_1 ) ;
break;
case V_60 :
F_50 ( V_1 ) ;
F_59 ( V_1 ) ;
case V_51 :
case V_52 :
case V_84 :
F_46 ( V_1 ) ;
break;
default:
F_55 ( L_29 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
break;
}
}
if ( V_66 & V_117 ) {
V_68 = V_71 ;
if ( V_67 & V_72 ) {
F_66 ( V_1 -> V_33 , L_30 ) ;
if ( F_67 ( V_1 ) )
F_68 ( V_1 ) ;
} else {
F_29 ( V_1 -> V_33 , L_31 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_54 :
F_69 ( V_1 ) ;
case V_55 :
F_29 ( V_1 -> V_33 , L_32 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ,
F_70 ( V_1 ) ) ;
F_62 ( & V_1 -> V_102 , V_76
+ F_53 ( F_70 ( V_1 ) ) ) ;
break;
case V_60 :
F_63 ( & V_1 -> V_102 ) ;
F_69 ( V_1 ) ;
break;
case V_51 :
F_29 ( V_1 -> V_33 , L_33 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
F_69 ( V_1 ) ;
break;
case V_84 :
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
case V_52 :
F_69 ( V_1 ) ;
break;
default:
F_29 ( V_1 -> V_33 , L_34 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
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
F_71 ( & V_1 -> V_118 ) ;
return V_68 ;
}
static void F_72 ( struct V_1 * V_1 )
{
void T_2 * V_26 = V_1 -> V_41 ;
T_4 V_119 ;
F_6 ( V_26 , V_110 , 0 ) ;
V_1 -> V_105 = 0 ;
F_32 ( V_26 , V_107 , 0 ) ;
V_1 -> V_108 = 0 ;
F_32 ( V_26 , V_109 , 0 ) ;
V_119 = F_5 ( V_26 , V_120 ) ;
V_119 = F_37 ( V_26 , V_121 ) ;
V_119 = F_37 ( V_26 , V_122 ) ;
}
static void F_73 ( struct V_1 * V_1 )
{
void T_2 * V_39 = V_1 -> V_41 ;
V_1 -> V_105 = V_1 -> V_106 ;
F_32 ( V_39 , V_107 , V_1 -> V_105 ) ;
V_1 -> V_108 = V_1 -> V_106 & 0xfffe ;
F_32 ( V_39 , V_109 , V_1 -> V_108 ) ;
F_6 ( V_39 , V_110 , 0xf7 ) ;
}
static void F_74 ( struct V_1 * V_1 )
{
void T_2 * V_26 = V_1 -> V_41 ;
F_72 ( V_1 ) ;
F_6 ( V_26 , V_87 , 0 ) ;
}
void F_75 ( struct V_1 * V_1 )
{
void T_2 * V_39 = V_1 -> V_41 ;
T_3 V_67 = F_5 ( V_39 , V_87 ) ;
F_29 ( V_1 -> V_33 , L_35 , V_67 ) ;
F_73 ( V_1 ) ;
F_6 ( V_39 , V_123 , 0 ) ;
F_6 ( V_39 , V_14 , V_124
| V_125
) ;
V_1 -> V_53 = 0 ;
V_67 = F_5 ( V_39 , V_87 ) ;
V_67 &= ~ V_88 ;
if ( V_1 -> V_126 != V_127 &&
( V_67 & V_80 ) == V_80 ) {
V_1 -> V_53 = 1 ;
} else {
V_67 |= V_88 ;
}
F_76 ( V_1 ) ;
F_6 ( V_39 , V_87 , V_67 ) ;
}
void F_77 ( struct V_1 * V_1 )
{
F_78 ( V_1 ) ;
F_74 ( V_1 ) ;
F_29 ( V_1 -> V_33 , L_36 ) ;
F_60 ( V_1 , 0 ) ;
}
static void F_79 ( struct V_128 * V_129 )
{
struct V_1 * V_1 = F_1 ( & V_129 -> V_3 ) ;
unsigned long V_46 ;
F_4 ( V_1 -> V_33 ) ;
F_80 ( V_1 ) ;
F_81 ( V_1 ) ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
F_78 ( V_1 ) ;
F_74 ( V_1 ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
F_6 ( V_1 -> V_41 , V_87 , 0 ) ;
F_82 ( V_1 ) ;
F_7 ( V_1 -> V_33 ) ;
}
static int
F_83 ( struct V_1 * V_1 , struct V_28 * V_29 ,
const struct V_130 * V_131 , T_4 V_6 )
{
void T_2 * V_26 = V_1 -> V_41 ;
int V_132 = 0 ;
T_4 V_133 = V_131 -> V_133 ;
T_4 V_134 = V_6 >> 3 ;
T_3 V_135 ;
V_132 = F_84 ( F_85 ( V_133 , ( T_4 ) 8 ) ) - 1 ;
V_133 = 1 << V_132 ;
V_135 = V_132 - 3 ;
if ( V_131 -> V_136 == V_137 ) {
if ( ( V_6 + ( V_133 << 1 ) ) >
( 1 << ( V_1 -> V_138 -> V_139 + 2 ) ) )
return - V_140 ;
V_135 |= V_141 ;
} else {
if ( ( V_6 + V_133 ) > ( 1 << ( V_1 -> V_138 -> V_139 + 2 ) ) )
return - V_140 ;
}
F_6 ( V_26 , V_27 , V_29 -> V_25 ) ;
if ( V_29 -> V_25 == 1 )
V_1 -> V_142 = V_29 ;
switch ( V_131 -> V_143 ) {
case V_144 :
F_86 ( V_26 , V_135 ) ;
F_87 ( V_26 , V_134 ) ;
V_29 -> V_145 = ! ! ( V_135 & V_141 ) ;
V_29 -> V_146 = V_133 ;
break;
case V_147 :
F_88 ( V_26 , V_135 ) ;
F_89 ( V_26 , V_134 ) ;
V_29 -> V_148 = ! ! ( V_135 & V_141 ) ;
V_29 -> V_149 = V_133 ;
break;
case V_150 :
F_86 ( V_26 , V_135 ) ;
F_87 ( V_26 , V_134 ) ;
V_29 -> V_148 = ! ! ( V_135 & V_141 ) ;
V_29 -> V_149 = V_133 ;
F_88 ( V_26 , V_135 ) ;
F_89 ( V_26 , V_134 ) ;
V_29 -> V_145 = V_29 -> V_148 ;
V_29 -> V_146 = V_133 ;
V_29 -> V_151 = true ;
break;
}
V_1 -> V_106 |= ( 1 << V_29 -> V_25 ) ;
return V_6 + ( V_133 << ( ( V_135 & V_141 ) ? 1 : 0 ) ) ;
}
static int F_90 ( struct V_1 * V_1 )
{
const struct V_130 * V_131 ;
unsigned V_9 , V_152 ;
int V_6 ;
struct V_28 * V_29 = V_1 -> V_40 ;
if ( V_1 -> V_138 -> V_153 ) {
V_131 = V_1 -> V_138 -> V_153 ;
V_152 = V_1 -> V_138 -> V_154 ;
goto V_155;
}
switch ( V_156 ) {
default:
V_156 = 0 ;
case 0 :
V_131 = V_157 ;
V_152 = F_91 ( V_157 ) ;
break;
case 1 :
V_131 = V_158 ;
V_152 = F_91 ( V_158 ) ;
break;
case 2 :
V_131 = V_159 ;
V_152 = F_91 ( V_159 ) ;
break;
case 3 :
V_131 = V_160 ;
V_152 = F_91 ( V_160 ) ;
break;
case 4 :
V_131 = V_161 ;
V_152 = F_91 ( V_161 ) ;
break;
case 5 :
V_131 = V_162 ;
V_152 = F_91 ( V_162 ) ;
break;
}
F_92 ( V_163 L_37 ,
V_164 , V_156 ) ;
V_155:
V_6 = F_83 ( V_1 , V_29 , & V_165 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_152 ; V_9 ++ ) {
T_3 V_166 = V_131 -> V_167 ;
if ( V_166 >= V_1 -> V_138 -> V_168 ) {
F_93 ( L_38 ,
V_164 , V_166 ) ;
return - V_169 ;
}
V_6 = F_83 ( V_1 , V_29 + V_166 , V_131 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_93 ( L_39 ,
V_164 , V_166 ) ;
return V_6 ;
}
V_166 ++ ;
V_1 -> V_170 = F_85 ( V_166 , V_1 -> V_170 ) ;
}
F_92 ( V_163 L_40 ,
V_164 ,
V_152 + 1 , V_1 -> V_138 -> V_168 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_138 -> V_139 + 2 ) ) ) ;
if ( ! V_1 -> V_142 ) {
F_93 ( L_41 , V_164 ) ;
return - V_169 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_1 )
{
T_3 V_25 = 0 ;
struct V_28 * V_29 ;
void T_2 * V_26 = V_1 -> V_41 ;
int V_12 = 0 ;
F_29 ( V_1 -> V_33 , L_42 ) ;
for ( V_25 = 1 ; V_25 < V_1 -> V_138 -> V_168 ; V_25 ++ ) {
F_43 ( V_26 , V_25 ) ;
V_29 = V_1 -> V_40 + V_25 ;
V_12 = F_95 ( V_1 , V_29 , V_25 ) ;
if ( V_12 < 0 )
break;
if ( V_29 -> V_146 < 512
|| V_29 -> V_149 < 512 )
continue;
if ( V_1 -> V_142 )
continue;
V_1 -> V_142 = V_29 ;
}
if ( ! V_1 -> V_142 ) {
F_93 ( L_41 , V_164 ) ;
return - V_169 ;
}
return 0 ;
}
static int F_96 ( T_4 V_171 , struct V_1 * V_1 )
{
T_3 V_59 ;
char * type ;
char V_172 [ 90 ] , V_173 [ 32 ] , V_174 [ 12 ] ;
void T_2 * V_26 = V_1 -> V_41 ;
int V_175 = 0 ;
int V_9 ;
V_59 = F_97 ( V_26 ) ;
strcpy ( V_172 , ( V_59 & V_176 ) ? L_43 : L_44 ) ;
if ( V_59 & V_177 ) {
strcat ( V_172 , L_45 ) ;
V_1 -> V_178 = true ;
}
if ( V_59 & V_179 ) {
strcat ( V_172 , L_46 ) ;
V_1 -> V_180 = true ;
}
if ( V_59 & V_181 ) {
strcat ( V_172 , L_47 ) ;
V_1 -> V_182 = true ;
}
if ( V_59 & V_183 ) {
strcat ( V_172 , L_48 ) ;
V_1 -> V_184 = true ;
}
if ( V_59 & V_185 ) {
strcat ( V_172 , L_49 ) ;
V_1 -> V_186 = true ;
}
if ( V_59 & V_187 )
strcat ( V_172 , L_50 ) ;
F_92 ( V_163 L_51 ,
V_164 , V_59 , V_172 ) ;
V_174 [ 0 ] = 0 ;
if ( V_188 == V_171 ) {
V_1 -> V_189 = 1 ;
type = L_52 ;
} else {
V_1 -> V_189 = 0 ;
type = L_53 ;
#ifndef F_98
F_92 ( V_190
L_54 ,
V_164 ) ;
#endif
}
V_1 -> V_191 = F_99 ( V_26 ) ;
snprintf ( V_173 , 32 , L_55 , F_100 ( V_1 -> V_191 ) ,
F_101 ( V_1 -> V_191 ) ,
( V_1 -> V_191 & V_192 ) ? L_56 : L_53 ) ;
F_92 ( V_163 L_57 ,
V_164 , type , V_173 , V_174 ) ;
F_102 ( V_1 ) ;
V_1 -> V_170 = 1 ;
V_1 -> V_106 = 1 ;
if ( V_1 -> V_178 )
V_175 = F_90 ( V_1 ) ;
else
V_175 = F_94 ( V_1 ) ;
if ( V_175 < 0 )
return V_175 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_170 ; V_9 ++ ) {
struct V_28 * V_29 = V_1 -> V_40 + V_9 ;
V_29 -> V_32 = V_1 -> V_36 . V_193 ( V_9 ) + V_26 ;
#if F_103 ( V_194 )
if ( V_1 -> V_36 . V_195 & V_196 ) {
V_29 -> V_197 = V_1 -> V_198 + 0x400 +
V_1 -> V_36 . V_193 ( V_9 ) ;
V_29 -> V_199 = V_1 -> V_200 + 0x400 +
V_1 -> V_36 . V_193 ( V_9 ) ;
V_29 -> V_201 =
V_1 -> V_202 + 0x400 + V_1 -> V_36 . V_193 ( V_9 ) ;
if ( V_9 == 0 )
V_29 -> V_203 = V_26 - 0x400 + V_204 ;
else
V_29 -> V_203 = V_26 + 0x400 +
( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
}
#endif
V_29 -> V_39 = V_1 -> V_36 . V_205 ( V_9 , 0 ) + V_26 ;
V_29 -> V_206 = F_104 ( V_9 , V_26 ) ;
V_29 -> V_207 = 1 ;
V_29 -> V_208 = 1 ;
if ( V_29 -> V_146 ) {
F_29 ( V_1 -> V_33 ,
L_58 ,
V_164 , V_9 ,
V_29 -> V_151 ? L_59 : L_60 ,
V_29 -> V_145
? L_61 : L_53 ,
V_29 -> V_146 ) ;
}
if ( V_29 -> V_149 && ! V_29 -> V_151 ) {
F_29 ( V_1 -> V_33 ,
L_58 ,
V_164 , V_9 ,
L_62 ,
V_29 -> V_148
? L_61 : L_53 ,
V_29 -> V_149 ) ;
}
if ( ! ( V_29 -> V_146 || V_29 -> V_149 ) )
F_29 ( V_1 -> V_33 , L_63 , V_9 ) ;
}
return 0 ;
}
T_5 F_105 ( struct V_1 * V_1 )
{
T_5 V_209 = V_69 ;
unsigned long V_175 ;
unsigned long V_25 ;
T_3 V_67 ;
if ( ! V_1 -> V_66 && ! V_1 -> V_210 && ! V_1 -> V_211 )
return V_69 ;
V_67 = F_5 ( V_1 -> V_41 , V_87 ) ;
F_29 ( V_1 -> V_33 , L_64 ,
F_67 ( V_1 ) ? L_12 : L_13 ,
V_1 -> V_66 , V_1 -> V_210 , V_1 -> V_211 ) ;
if ( V_1 -> V_66 )
V_209 |= F_52 ( V_1 , V_1 -> V_66 , V_67 ) ;
if ( V_1 -> V_210 & 1 ) {
if ( F_67 ( V_1 ) )
V_209 |= F_106 ( V_1 ) ;
else
V_209 |= F_107 ( V_1 ) ;
V_1 -> V_210 &= ~ F_108 ( 0 ) ;
}
V_175 = V_1 -> V_210 ;
F_109 (epnum, &status, 16 ) {
V_209 = V_71 ;
if ( F_67 ( V_1 ) )
F_110 ( V_1 , V_25 ) ;
else
F_111 ( V_1 , V_25 ) ;
}
V_175 = V_1 -> V_211 ;
F_109 (epnum, &status, 16 ) {
V_209 = V_71 ;
if ( F_67 ( V_1 ) )
F_112 ( V_1 , V_25 ) ;
else
F_113 ( V_1 , V_25 ) ;
}
return V_209 ;
}
void F_114 ( struct V_1 * V_1 , T_3 V_25 , T_3 V_212 )
{
if ( ! V_25 ) {
#ifndef F_115
if ( ! F_116 () ) {
if ( F_67 ( V_1 ) )
F_106 ( V_1 ) ;
else
F_107 ( V_1 ) ;
}
#endif
} else {
if ( V_212 ) {
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
F_117 ( struct V_2 * V_3 , struct V_213 * V_214 , char * V_215 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
int V_12 = - V_169 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
V_12 = sprintf ( V_215 , L_65 , F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return V_12 ;
}
static T_6
F_118 ( struct V_2 * V_3 , struct V_213 * V_214 ,
const char * V_215 , T_7 V_152 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
int V_175 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
if ( F_119 ( V_215 , L_12 ) )
V_175 = F_120 ( V_1 , V_216 ) ;
else if ( F_119 ( V_215 , L_13 ) )
V_175 = F_120 ( V_1 , V_217 ) ;
else if ( F_119 ( V_215 , L_66 ) )
V_175 = F_120 ( V_1 , V_218 ) ;
else
V_175 = - V_169 ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return ( V_175 == 0 ) ? V_152 : V_175 ;
}
static T_6
F_121 ( struct V_2 * V_3 , struct V_213 * V_214 ,
const char * V_215 , T_7 V_152 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
unsigned long V_219 ;
if ( sscanf ( V_215 , L_67 , & V_219 ) < 1 ) {
F_66 ( V_3 , L_68 ) ;
return - V_169 ;
}
F_45 ( & V_1 -> V_47 , V_46 ) ;
V_1 -> V_98 = V_219 ? F_122 ( int , V_219 , V_99 ) : 0 ;
if ( V_1 -> V_48 -> V_49 -> V_50 == V_55 )
V_1 -> V_53 = 0 ;
F_60 ( V_1 , V_76 + F_53 ( V_219 ) ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return V_152 ;
}
static T_6
F_123 ( struct V_2 * V_3 , struct V_213 * V_214 , char * V_215 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
unsigned long V_219 ;
int V_220 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
V_219 = V_1 -> V_98 ;
V_220 = F_124 ( V_1 ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return sprintf ( V_215 , L_69 ,
V_220 ? L_70 : L_71 , V_219 ) ;
}
static T_6
F_125 ( struct V_2 * V_3 , struct V_213 * V_214 ,
const char * V_215 , T_7 V_152 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_221 ;
if ( sscanf ( V_215 , L_72 , & V_221 ) != 1
|| ( V_221 != 1 ) ) {
F_66 ( V_3 , L_73 ) ;
return - V_169 ;
}
if ( V_221 == 1 )
F_126 ( V_1 ) ;
return V_152 ;
}
static void F_127 ( struct V_222 * V_24 )
{
struct V_1 * V_1 = F_128 ( V_24 , struct V_1 , V_118 ) ;
if ( V_1 -> V_48 -> V_49 -> V_50 != V_1 -> V_223 ) {
V_1 -> V_223 = V_1 -> V_48 -> V_49 -> V_50 ;
F_129 ( & V_1 -> V_33 -> V_224 , NULL , L_74 ) ;
}
}
static void F_68 ( struct V_1 * V_1 )
{
int V_12 ;
T_3 V_67 ;
F_72 ( V_1 ) ;
F_130 ( 10 ) ;
V_12 = F_131 ( V_1 ) ;
if ( V_12 ) {
F_73 ( V_1 ) ;
return;
}
V_67 = F_5 ( V_1 -> V_41 , V_87 ) ;
V_67 &= ~ V_88 ;
F_6 ( V_1 -> V_41 , V_87 , V_67 ) ;
F_59 ( V_1 ) ;
if ( V_1 -> V_178 )
V_12 = F_90 ( V_1 ) ;
else
V_12 = F_94 ( V_1 ) ;
if ( V_12 == 0 )
F_75 ( V_1 ) ;
}
static struct V_1 * F_132 ( struct V_2 * V_3 ,
struct V_225 * V_138 , void T_2 * V_26 )
{
struct V_1 * V_1 ;
struct V_28 * V_226 ;
int V_25 ;
int V_12 ;
V_1 = F_133 ( V_3 , sizeof( * V_1 ) , V_227 ) ;
if ( ! V_1 )
return NULL ;
F_134 ( & V_1 -> V_228 ) ;
F_134 ( & V_1 -> V_229 ) ;
F_134 ( & V_1 -> V_230 ) ;
V_1 -> V_95 = V_231 ;
V_1 -> V_98 = V_99 ;
V_1 -> V_41 = V_26 ;
V_1 -> V_232 = V_26 ;
V_1 -> V_233 = - V_234 ;
V_1 -> V_138 = V_138 ;
F_135 ( V_1 -> V_138 -> V_168 > V_235 ) ;
for ( V_25 = 0 , V_226 = V_1 -> V_40 ;
V_25 < V_1 -> V_138 -> V_168 ;
V_25 ++ , V_226 ++ ) {
V_226 -> V_1 = V_1 ;
V_226 -> V_25 = V_25 ;
}
V_1 -> V_33 = V_3 ;
V_12 = F_136 ( V_1 ) ;
if ( V_12 < 0 )
goto V_236;
F_137 ( V_3 , V_1 ) ;
return V_1 ;
V_236:
return NULL ;
}
static void F_138 ( struct V_1 * V_1 )
{
#ifdef F_139
F_140 ( & V_1 -> V_33 -> V_224 , & V_237 ) ;
#endif
if ( V_1 -> V_233 >= 0 ) {
if ( V_1 -> V_238 )
F_141 ( V_1 -> V_233 ) ;
F_142 ( V_1 -> V_233 , V_1 ) ;
}
F_143 ( V_1 ) ;
}
static void F_144 ( struct V_222 * V_239 )
{
struct V_1 * V_1 ;
unsigned long V_46 ;
V_1 = F_128 ( V_239 , struct V_1 , V_240 . V_239 ) ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
if ( V_1 -> V_64 & V_241 )
F_145 ( V_1 , false ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
}
static int
F_146 ( struct V_2 * V_3 , int V_233 , void T_2 * V_242 )
{
int V_175 ;
struct V_1 * V_1 ;
struct V_243 * V_244 = F_147 ( V_3 ) ;
if ( ! V_244 ) {
F_29 ( V_3 , L_75 ) ;
V_175 = - V_234 ;
goto V_245;
}
V_1 = F_132 ( V_3 , V_244 -> V_138 , V_242 ) ;
if ( ! V_1 ) {
V_175 = - V_246 ;
goto V_245;
}
F_148 ( & V_1 -> V_47 ) ;
V_1 -> V_247 = V_244 -> V_248 ;
V_1 -> V_249 = V_244 -> V_249 ;
V_1 -> V_250 = V_244 -> V_251 ;
V_1 -> V_126 = V_244 -> V_136 ;
F_5 = F_14 ;
F_6 = F_16 ;
F_37 = F_18 ;
F_32 = F_20 ;
V_252 = F_22 ;
V_253 = F_24 ;
F_149 ( V_1 -> V_33 ) ;
F_150 ( V_1 -> V_33 , 200 ) ;
F_151 ( V_1 -> V_33 ) ;
F_152 ( V_1 -> V_33 ) ;
V_175 = F_153 ( V_1 ) ;
if ( V_175 < 0 )
goto V_254;
if ( ! V_1 -> V_255 ) {
V_175 = - V_234 ;
goto V_256;
}
if ( V_1 -> V_250 -> V_195 )
V_1 -> V_36 . V_195 = V_1 -> V_250 -> V_195 ;
if ( V_1 -> V_36 . V_195 & V_257 ) {
V_1 -> V_36 . V_205 = F_13 ;
V_1 -> V_36 . V_258 = F_12 ;
} else {
V_1 -> V_36 . V_205 = F_11 ;
V_1 -> V_36 . V_258 = F_10 ;
}
if ( V_1 -> V_250 -> V_205 )
V_1 -> V_36 . V_205 = V_1 -> V_250 -> V_205 ;
if ( V_1 -> V_250 -> V_258 )
V_1 -> V_36 . V_258 = V_1 -> V_250 -> V_258 ;
if ( V_1 -> V_250 -> V_156 )
V_156 = V_1 -> V_250 -> V_156 ;
else
V_156 = 4 ;
if ( V_1 -> V_250 -> V_193 )
V_1 -> V_36 . V_193 = V_1 -> V_250 -> V_193 ;
else
V_1 -> V_36 . V_193 = F_9 ;
if ( V_1 -> V_250 -> V_259 )
F_5 = V_1 -> V_250 -> V_259 ;
if ( V_1 -> V_250 -> V_260 )
F_6 = V_1 -> V_250 -> V_260 ;
if ( V_1 -> V_250 -> V_261 )
F_37 = V_1 -> V_250 -> V_261 ;
if ( V_1 -> V_250 -> V_262 )
F_32 = V_1 -> V_250 -> V_262 ;
if ( V_1 -> V_250 -> V_263 )
V_252 = V_1 -> V_250 -> V_263 ;
if ( V_1 -> V_250 -> V_264 )
V_253 = V_1 -> V_250 -> V_264 ;
if ( V_1 -> V_250 -> V_37 )
V_1 -> V_36 . V_37 = V_1 -> V_250 -> V_37 ;
else
V_1 -> V_36 . V_37 = F_35 ;
if ( V_1 -> V_250 -> V_38 )
V_1 -> V_36 . V_38 = V_1 -> V_250 -> V_38 ;
else
V_1 -> V_36 . V_38 = F_26 ;
if ( ! V_1 -> V_48 -> V_265 ) {
V_1 -> V_48 -> V_13 = V_1 -> V_33 ;
V_1 -> V_48 -> V_8 = V_1 -> V_41 ;
V_1 -> V_48 -> V_265 = & V_266 ;
}
F_4 ( V_1 -> V_33 ) ;
if ( V_267 && V_3 -> V_268 ) {
V_1 -> V_269 = F_154 ( V_1 , V_1 -> V_41 ) ;
if ( F_155 ( V_1 -> V_269 ) ) {
V_175 = F_156 ( V_1 -> V_269 ) ;
goto V_270;
}
}
F_78 ( V_1 ) ;
F_74 ( V_1 ) ;
F_157 ( & V_1 -> V_118 , F_127 ) ;
F_158 ( & V_1 -> V_240 , F_144 ) ;
F_158 ( & V_1 -> V_271 , V_272 ) ;
V_175 = F_96 ( V_244 -> V_138 -> V_273
? V_188
: V_274 , V_1 ) ;
if ( V_175 < 0 )
goto V_275;
F_159 ( & V_1 -> V_102 , F_44 , ( unsigned long ) V_1 ) ;
if ( F_160 ( V_233 , V_1 -> V_255 , 0 , F_161 ( V_3 ) , V_1 ) ) {
F_66 ( V_3 , L_76 , V_233 ) ;
V_175 = - V_234 ;
goto V_275;
}
V_1 -> V_233 = V_233 ;
if ( F_162 ( V_233 ) == 0 ) {
V_1 -> V_238 = 1 ;
F_163 ( V_3 , 1 ) ;
} else {
V_1 -> V_238 = 0 ;
}
if ( V_244 -> V_276 ) {
T_3 V_277 = F_164 ( V_1 -> V_41 ) ;
V_277 |= V_278 ;
F_165 ( V_1 -> V_41 , V_277 ) ;
}
if ( V_1 -> V_48 -> V_49 -> V_279 ) {
F_57 ( V_1 ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_91 ;
} else {
F_51 ( V_1 ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_84 ;
}
switch ( V_1 -> V_126 ) {
case V_127 :
V_175 = F_166 ( V_1 , V_244 -> V_11 ) ;
if ( V_175 < 0 )
goto V_275;
V_175 = F_120 ( V_1 , V_216 ) ;
break;
case V_280 :
V_175 = F_167 ( V_1 ) ;
if ( V_175 < 0 )
goto V_275;
V_175 = F_120 ( V_1 , V_217 ) ;
break;
case V_281 :
V_175 = F_166 ( V_1 , V_244 -> V_11 ) ;
if ( V_175 < 0 )
goto V_275;
V_175 = F_167 ( V_1 ) ;
if ( V_175 ) {
F_80 ( V_1 ) ;
goto V_275;
}
V_175 = F_120 ( V_1 , V_218 ) ;
break;
default:
F_66 ( V_3 , L_77 , V_1 -> V_126 ) ;
break;
}
if ( V_175 < 0 )
goto V_275;
V_175 = F_168 ( V_1 ) ;
if ( V_175 < 0 )
goto V_282;
V_175 = F_169 ( & V_1 -> V_33 -> V_224 , & V_237 ) ;
if ( V_175 )
goto V_283;
F_7 ( V_1 -> V_33 ) ;
return 0 ;
V_283:
F_170 ( V_1 ) ;
V_282:
F_81 ( V_1 ) ;
F_80 ( V_1 ) ;
V_275:
F_171 ( & V_1 -> V_118 ) ;
F_172 ( & V_1 -> V_271 ) ;
F_172 ( & V_1 -> V_240 ) ;
if ( V_1 -> V_269 )
F_173 ( V_1 -> V_269 ) ;
V_270:
F_174 ( V_1 -> V_33 ) ;
V_256:
if ( V_1 -> V_238 )
F_163 ( V_3 , 0 ) ;
F_82 ( V_1 ) ;
V_254:
F_175 ( V_1 -> V_33 ) ;
F_66 ( V_1 -> V_33 ,
L_78 , V_175 ) ;
F_138 ( V_1 ) ;
V_245:
return V_175 ;
}
static int F_176 ( struct V_128 * V_129 )
{
struct V_2 * V_3 = & V_129 -> V_3 ;
int V_284 = F_177 ( V_129 , L_79 ) ;
struct V_285 * V_286 ;
void T_2 * V_287 ;
if ( V_284 <= 0 )
return - V_234 ;
V_286 = F_178 ( V_129 , V_288 , 0 ) ;
V_287 = F_179 ( V_3 , V_286 ) ;
if ( F_155 ( V_287 ) )
return F_156 ( V_287 ) ;
return F_146 ( V_3 , V_284 , V_287 ) ;
}
static int F_180 ( struct V_128 * V_129 )
{
struct V_2 * V_3 = & V_129 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_170 ( V_1 ) ;
F_79 ( V_129 ) ;
if ( V_1 -> V_269 )
F_173 ( V_1 -> V_269 ) ;
F_171 ( & V_1 -> V_118 ) ;
F_172 ( & V_1 -> V_271 ) ;
F_172 ( & V_1 -> V_240 ) ;
F_138 ( V_1 ) ;
F_163 ( V_3 , 0 ) ;
return 0 ;
}
static void F_181 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_289 = V_1 -> V_41 ;
void T_2 * V_290 ;
V_1 -> V_291 . V_292 = F_37 ( V_289 , V_293 ) ;
V_1 -> V_291 . V_294 = F_5 ( V_289 , V_123 ) ;
V_1 -> V_291 . V_277 = F_164 ( V_1 -> V_41 ) ;
V_1 -> V_291 . V_11 = F_5 ( V_289 , V_14 ) ;
V_1 -> V_291 . V_295 = F_5 ( V_289 , V_110 ) ;
V_1 -> V_291 . V_34 = F_5 ( V_289 , V_27 ) ;
V_1 -> V_291 . V_67 = F_5 ( V_289 , V_87 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_138 -> V_168 ; ++ V_9 ) {
struct V_28 * V_29 ;
V_29 = & V_1 -> V_40 [ V_9 ] ;
if ( ! V_29 )
continue;
V_290 = V_29 -> V_39 ;
if ( ! V_290 )
continue;
F_6 ( V_289 , V_27 , V_9 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_297 =
F_37 ( V_290 , V_298 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_299 =
F_37 ( V_290 , V_300 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_301 =
F_37 ( V_290 , V_302 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_303 =
F_37 ( V_290 , V_304 ) ;
if ( V_1 -> V_178 ) {
V_1 -> V_291 . V_296 [ V_9 ] . V_305 =
F_182 ( V_289 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_306 =
F_183 ( V_289 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_307 =
F_184 ( V_289 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_308 =
F_185 ( V_289 ) ;
}
V_1 -> V_291 . V_296 [ V_9 ] . V_309 =
F_5 ( V_290 , V_310 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_311 =
F_5 ( V_290 , V_312 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_313 =
F_5 ( V_290 , V_314 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_315 =
F_5 ( V_290 , V_316 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_317 =
F_186 ( V_289 , V_9 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_318 =
F_187 ( V_289 , V_9 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_319 =
F_188 ( V_289 , V_9 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_320 =
F_189 ( V_289 , V_9 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_321 =
F_190 ( V_289 , V_9 ) ;
V_1 -> V_291 . V_296 [ V_9 ] . V_322 =
F_191 ( V_289 , V_9 ) ;
}
}
static void F_192 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_289 = V_1 -> V_41 ;
void T_2 * V_323 ;
void T_2 * V_290 ;
T_3 V_11 ;
F_32 ( V_289 , V_293 , V_1 -> V_291 . V_292 ) ;
F_6 ( V_289 , V_123 , V_1 -> V_291 . V_294 ) ;
F_165 ( V_1 -> V_41 , V_1 -> V_291 . V_277 ) ;
V_11 = F_5 ( V_289 , V_14 ) ;
V_11 &= V_15 | V_324 ;
V_1 -> V_291 . V_11 &= ~ ( V_15 | V_324 ) ;
V_11 |= V_1 -> V_291 . V_11 ;
F_6 ( V_289 , V_14 , V_11 ) ;
F_32 ( V_289 , V_107 , V_1 -> V_105 ) ;
F_32 ( V_289 , V_109 , V_1 -> V_108 ) ;
F_6 ( V_289 , V_110 , V_1 -> V_291 . V_295 ) ;
F_6 ( V_289 , V_87 , V_1 -> V_291 . V_67 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_138 -> V_168 ; ++ V_9 ) {
struct V_28 * V_29 ;
V_29 = & V_1 -> V_40 [ V_9 ] ;
if ( ! V_29 )
continue;
V_290 = V_29 -> V_39 ;
if ( ! V_290 )
continue;
F_6 ( V_289 , V_27 , V_9 ) ;
F_32 ( V_290 , V_298 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_297 ) ;
F_32 ( V_290 , V_300 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_299 ) ;
F_32 ( V_290 , V_302 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_301 ) ;
F_32 ( V_290 , V_304 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_303 ) ;
if ( V_1 -> V_178 ) {
F_86 ( V_289 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_307 ) ;
F_88 ( V_289 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_308 ) ;
F_87 ( V_289 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_305 ) ;
F_89 ( V_289 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_306 ) ;
}
F_6 ( V_290 , V_310 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_309 ) ;
F_6 ( V_290 , V_312 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_311 ) ;
F_6 ( V_290 , V_314 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_313 ) ;
F_6 ( V_290 , V_316 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_315 ) ;
F_193 ( V_289 , V_9 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_317 ) ;
F_194 ( V_289 , V_9 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_318 ) ;
F_195 ( V_289 , V_9 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_319 ) ;
V_323 =
F_104 ( V_9 , V_289 ) ;
F_196 ( V_323 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_320 ) ;
F_197 ( V_323 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_321 ) ;
F_198 ( V_323 ,
V_1 -> V_291 . V_296 [ V_9 ] . V_322 ) ;
}
F_6 ( V_289 , V_27 , V_1 -> V_291 . V_34 ) ;
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
if ( F_200 ( V_1 ) ) {
} else if ( F_67 ( V_1 ) ) {
}
F_181 ( V_1 ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_67 ;
T_3 V_325 ;
F_192 ( V_1 ) ;
V_67 = F_5 ( V_1 -> V_41 , V_87 ) ;
V_325 = V_86 | V_326 | V_115 ;
if ( ( V_67 & V_325 ) != ( V_1 -> V_291 . V_67 & V_325 ) )
V_1 -> V_64 = 0 ;
if ( V_1 -> V_78 ) {
V_1 -> V_78 = 0 ;
F_202 ( & V_1 -> V_271 ,
F_53 ( V_77 ) ) ;
}
F_175 ( V_3 ) ;
F_203 ( V_3 ) ;
F_152 ( V_3 ) ;
return 0 ;
}
static int F_204 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_181 ( V_1 ) ;
return 0 ;
}
static int F_205 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_327 = 1 ;
if ( ! V_327 )
F_192 ( V_1 ) ;
V_327 = 0 ;
if ( V_1 -> V_78 ) {
V_1 -> V_78 = 0 ;
F_202 ( & V_1 -> V_271 ,
F_53 ( V_77 ) ) ;
}
return 0 ;
}
