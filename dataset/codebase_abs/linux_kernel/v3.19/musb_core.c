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
F_29 ( V_1 -> V_33 , L_10 , F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
if ( V_67 & V_72 ) {
void T_2 * V_26 = V_1 -> V_41 ;
T_3 V_11 ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_54 :
V_11 = F_5 ( V_1 -> V_41 , V_14 ) ;
if ( V_11 & V_15 ) {
V_1 -> V_66 &= ~ V_73 ;
F_29 ( V_1 -> V_33 , L_11 ) ;
break;
}
V_11 &= ~ V_15 ;
F_6 ( V_26 , V_14 ,
V_11 | V_74 ) ;
V_1 -> V_64 |=
( V_75 << 16 )
| V_76 ;
V_1 -> V_77 = V_78
+ F_53 ( 20 ) ;
V_1 -> V_79 = 1 ;
V_1 -> V_48 -> V_49 -> V_50 = V_80 ;
V_1 -> V_53 = 1 ;
break;
case V_51 :
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
V_1 -> V_53 = 1 ;
F_51 ( V_1 ) ;
break;
default:
F_54 ( L_12 ,
L_13 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
}
} else {
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_54 :
V_1 -> V_48 -> V_49 -> V_50 = V_80 ;
F_55 ( V_1 ) ;
break;
case V_51 :
case V_52 :
if ( ( V_67 & V_81 )
!= ( 3 << V_82 )
) {
V_1 -> V_66 |= V_83 ;
V_1 -> V_66 &= ~ V_73 ;
break;
}
F_56 ( V_1 ) ;
break;
case V_84 :
V_1 -> V_66 &= ~ V_73 ;
break;
default:
F_54 ( L_12 ,
L_14 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
}
}
}
if ( V_66 & V_85 ) {
void T_2 * V_26 = V_1 -> V_41 ;
if ( ( V_67 & V_81 ) == V_81
&& ( V_67 & V_86 ) ) {
F_29 ( V_1 -> V_33 , L_15 ) ;
return V_71 ;
}
F_29 ( V_1 -> V_33 , L_16 ,
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
case V_80 :
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
L_17 ,
usb_otg_state_string(musb->xceiv->otg->state),
devctl,
({ char *s;
switch (devctl & MUSB_DEVCTL_VBUS) {
case 0 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_18; break;
case 1 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_19; break;
case 2 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_20; break;
default:
s = L_21; break;
} s; }),
VBUSERR_RETRY_COUNT - musb->vbuserr_retry,
musb->port1_status) ;
if ( ! V_93 )
F_48 ( V_1 , 0 ) ;
V_68 = V_71 ;
}
if ( V_66 & V_73 ) {
F_29 ( V_1 -> V_33 , L_22 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) , V_67 ) ;
V_68 = V_71 ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_60 :
F_50 ( V_1 ) ;
F_55 ( V_1 ) ;
F_59 ( V_1 ) ;
F_60 ( V_1 , V_78
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
F_29 ( V_1 -> V_33 , L_23 ) ;
F_62 ( & V_1 -> V_102 , V_78
+ F_53 (
V_103 ) ) ;
}
break;
case V_55 :
if ( V_1 -> V_98 != 0 )
F_60 ( V_1 , V_78
+ F_53 ( V_1 -> V_98 ) ) ;
break;
case V_80 :
V_1 -> V_48 -> V_49 -> V_50 = V_54 ;
V_1 -> V_53 = V_1 -> V_58 -> V_62 . V_101 ;
break;
case V_61 :
F_29 ( V_1 -> V_33 , L_24 ) ;
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
if ( F_63 ( V_1 ) ) {
}
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
if ( V_66 & V_73 ) {
F_29 ( V_1 -> V_33 , L_25 ) ;
V_66 &= ~ V_73 ;
goto V_116;
} else
F_29 ( V_1 -> V_33 , L_26 ) ;
break;
case V_51 :
F_29 ( V_1 -> V_33 , L_27 ) ;
V_116:
V_1 -> V_48 -> V_49 -> V_50 = V_61 ;
if ( V_1 -> V_58 )
V_1 -> V_58 -> V_62 . V_63 = 1 ;
F_64 ( & V_1 -> V_102 ) ;
break;
default:
if ( ( V_67 & V_81 )
== ( 3 << V_82 ) ) {
V_1 -> V_48 -> V_49 -> V_50 = V_80 ;
if ( V_58 )
V_58 -> V_62 . V_63 = 0 ;
}
break;
}
F_65 ( V_1 ) ;
F_29 ( V_1 -> V_33 , L_28 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) , V_67 ) ;
}
if ( V_66 & V_83 ) {
F_29 ( V_1 -> V_33 , L_29 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ,
F_66 ( V_1 ) , V_67 ) ;
V_68 = V_71 ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_80 :
case V_54 :
F_55 ( V_1 ) ;
F_59 ( V_1 ) ;
if ( V_1 -> V_98 != 0 )
F_60 ( V_1 , V_78
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
F_54 ( L_30 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
break;
}
}
if ( V_66 & V_117 ) {
V_68 = V_71 ;
if ( ( V_67 & V_72 ) != 0 ) {
if ( V_67 & ( V_118 | V_115 ) )
F_29 ( V_1 -> V_33 , L_31 , V_67 ) ;
else {
F_67 ( L_32 ) ;
F_6 ( V_1 -> V_41 , V_87 , 0 ) ;
}
} else {
F_29 ( V_1 -> V_33 , L_33 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
switch ( V_1 -> V_48 -> V_49 -> V_50 ) {
case V_54 :
F_68 ( V_1 ) ;
case V_55 :
F_29 ( V_1 -> V_33 , L_34 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ,
F_69 ( V_1 ) ) ;
F_62 ( & V_1 -> V_102 , V_78
+ F_53 ( F_69 ( V_1 ) ) ) ;
break;
case V_60 :
F_64 ( & V_1 -> V_102 ) ;
F_68 ( V_1 ) ;
break;
case V_51 :
F_29 ( V_1 -> V_33 , L_35 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
F_68 ( V_1 ) ;
break;
case V_84 :
V_1 -> V_48 -> V_49 -> V_50 = V_52 ;
case V_52 :
F_68 ( V_1 ) ;
break;
default:
F_29 ( V_1 -> V_33 , L_36 ,
F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
}
}
}
if ( V_66 & V_119 && F_70 ( V_1 ) ) {
F_71 ( V_1 ) ;
F_72 ( & V_1 -> V_120 ,
F_53 ( 100 ) ) ;
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
F_73 ( & V_1 -> V_121 ) ;
return V_68 ;
}
static void F_71 ( struct V_1 * V_1 )
{
void T_2 * V_26 = V_1 -> V_41 ;
T_4 V_122 ;
F_6 ( V_26 , V_110 , 0 ) ;
V_1 -> V_105 = 0 ;
F_32 ( V_26 , V_107 , 0 ) ;
V_1 -> V_108 = 0 ;
F_32 ( V_26 , V_109 , 0 ) ;
F_6 ( V_26 , V_87 , 0 ) ;
V_122 = F_5 ( V_26 , V_123 ) ;
V_122 = F_37 ( V_26 , V_124 ) ;
V_122 = F_37 ( V_26 , V_125 ) ;
}
void F_74 ( struct V_1 * V_1 )
{
void T_2 * V_39 = V_1 -> V_41 ;
T_3 V_67 = F_5 ( V_39 , V_87 ) ;
F_29 ( V_1 -> V_33 , L_37 , V_67 ) ;
V_1 -> V_105 = V_1 -> V_106 ;
F_32 ( V_39 , V_107 , V_1 -> V_105 ) ;
V_1 -> V_108 = V_1 -> V_106 & 0xfffe ;
F_32 ( V_39 , V_109 , V_1 -> V_108 ) ;
F_6 ( V_39 , V_110 , 0xf7 ) ;
F_6 ( V_39 , V_126 , 0 ) ;
F_6 ( V_39 , V_14 , V_127
| V_128
) ;
V_1 -> V_53 = 0 ;
V_67 = F_5 ( V_39 , V_87 ) ;
V_67 &= ~ V_88 ;
if ( V_1 -> V_129 != V_130 &&
( V_67 & V_81 ) == V_81 ) {
V_1 -> V_53 = 1 ;
} else {
V_67 |= V_88 ;
}
F_75 ( V_1 ) ;
F_6 ( V_39 , V_87 , V_67 ) ;
}
void F_76 ( struct V_1 * V_1 )
{
F_77 ( V_1 ) ;
F_71 ( V_1 ) ;
F_29 ( V_1 -> V_33 , L_38 ) ;
F_60 ( V_1 , 0 ) ;
}
static void F_78 ( struct V_131 * V_132 )
{
struct V_1 * V_1 = F_1 ( & V_132 -> V_3 ) ;
unsigned long V_46 ;
F_4 ( V_1 -> V_33 ) ;
F_79 ( V_1 ) ;
F_80 ( V_1 ) ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
F_77 ( V_1 ) ;
F_71 ( V_1 ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
F_6 ( V_1 -> V_41 , V_87 , 0 ) ;
F_81 ( V_1 ) ;
F_7 ( V_1 -> V_33 ) ;
}
static int
F_82 ( struct V_1 * V_1 , struct V_28 * V_29 ,
const struct V_133 * V_134 , T_4 V_6 )
{
void T_2 * V_26 = V_1 -> V_41 ;
int V_135 = 0 ;
T_4 V_136 = V_134 -> V_136 ;
T_4 V_137 = V_6 >> 3 ;
T_3 V_138 ;
V_135 = F_83 ( F_84 ( V_136 , ( T_4 ) 8 ) ) - 1 ;
V_136 = 1 << V_135 ;
V_138 = V_135 - 3 ;
if ( V_134 -> V_139 == V_140 ) {
if ( ( V_6 + ( V_136 << 1 ) ) >
( 1 << ( V_1 -> V_141 -> V_142 + 2 ) ) )
return - V_143 ;
V_138 |= V_144 ;
} else {
if ( ( V_6 + V_136 ) > ( 1 << ( V_1 -> V_141 -> V_142 + 2 ) ) )
return - V_143 ;
}
F_6 ( V_26 , V_27 , V_29 -> V_25 ) ;
if ( V_29 -> V_25 == 1 )
V_1 -> V_145 = V_29 ;
switch ( V_134 -> V_146 ) {
case V_147 :
F_85 ( V_26 , V_138 ) ;
F_86 ( V_26 , V_137 ) ;
V_29 -> V_148 = ! ! ( V_138 & V_144 ) ;
V_29 -> V_149 = V_136 ;
break;
case V_150 :
F_87 ( V_26 , V_138 ) ;
F_88 ( V_26 , V_137 ) ;
V_29 -> V_151 = ! ! ( V_138 & V_144 ) ;
V_29 -> V_152 = V_136 ;
break;
case V_153 :
F_85 ( V_26 , V_138 ) ;
F_86 ( V_26 , V_137 ) ;
V_29 -> V_151 = ! ! ( V_138 & V_144 ) ;
V_29 -> V_152 = V_136 ;
F_87 ( V_26 , V_138 ) ;
F_88 ( V_26 , V_137 ) ;
V_29 -> V_148 = V_29 -> V_151 ;
V_29 -> V_149 = V_136 ;
V_29 -> V_154 = true ;
break;
}
V_1 -> V_106 |= ( 1 << V_29 -> V_25 ) ;
return V_6 + ( V_136 << ( ( V_138 & V_144 ) ? 1 : 0 ) ) ;
}
static int F_89 ( struct V_1 * V_1 )
{
const struct V_133 * V_134 ;
unsigned V_9 , V_155 ;
int V_6 ;
struct V_28 * V_29 = V_1 -> V_40 ;
if ( V_1 -> V_141 -> V_156 ) {
V_134 = V_1 -> V_141 -> V_156 ;
V_155 = V_1 -> V_141 -> V_157 ;
goto V_158;
}
switch ( V_159 ) {
default:
V_159 = 0 ;
case 0 :
V_134 = V_160 ;
V_155 = F_90 ( V_160 ) ;
break;
case 1 :
V_134 = V_161 ;
V_155 = F_90 ( V_161 ) ;
break;
case 2 :
V_134 = V_162 ;
V_155 = F_90 ( V_162 ) ;
break;
case 3 :
V_134 = V_163 ;
V_155 = F_90 ( V_163 ) ;
break;
case 4 :
V_134 = V_164 ;
V_155 = F_90 ( V_164 ) ;
break;
case 5 :
V_134 = V_165 ;
V_155 = F_90 ( V_165 ) ;
break;
}
F_91 ( V_166 L_39 ,
V_167 , V_159 ) ;
V_158:
V_6 = F_82 ( V_1 , V_29 , & V_168 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_155 ; V_9 ++ ) {
T_3 V_169 = V_134 -> V_170 ;
if ( V_169 >= V_1 -> V_141 -> V_171 ) {
F_92 ( L_40 ,
V_167 , V_169 ) ;
return - V_172 ;
}
V_6 = F_82 ( V_1 , V_29 + V_169 , V_134 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_92 ( L_41 ,
V_167 , V_169 ) ;
return V_6 ;
}
V_169 ++ ;
V_1 -> V_173 = F_84 ( V_169 , V_1 -> V_173 ) ;
}
F_91 ( V_166 L_42 ,
V_167 ,
V_155 + 1 , V_1 -> V_141 -> V_171 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_141 -> V_142 + 2 ) ) ) ;
if ( ! V_1 -> V_145 ) {
F_92 ( L_43 , V_167 ) ;
return - V_172 ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_1 )
{
T_3 V_25 = 0 ;
struct V_28 * V_29 ;
void T_2 * V_26 = V_1 -> V_41 ;
int V_12 = 0 ;
F_29 ( V_1 -> V_33 , L_44 ) ;
for ( V_25 = 1 ; V_25 < V_1 -> V_141 -> V_171 ; V_25 ++ ) {
F_43 ( V_26 , V_25 ) ;
V_29 = V_1 -> V_40 + V_25 ;
V_12 = F_94 ( V_1 , V_29 , V_25 ) ;
if ( V_12 < 0 )
break;
if ( V_29 -> V_149 < 512
|| V_29 -> V_152 < 512 )
continue;
if ( V_1 -> V_145 )
continue;
V_1 -> V_145 = V_29 ;
}
if ( ! V_1 -> V_145 ) {
F_92 ( L_43 , V_167 ) ;
return - V_172 ;
}
return 0 ;
}
static int F_95 ( T_4 V_174 , struct V_1 * V_1 )
{
T_3 V_59 ;
char * type ;
char V_175 [ 90 ] , V_176 [ 32 ] , V_177 [ 12 ] ;
void T_2 * V_26 = V_1 -> V_41 ;
int V_178 = 0 ;
int V_9 ;
V_59 = F_96 ( V_26 ) ;
strcpy ( V_175 , ( V_59 & V_179 ) ? L_45 : L_46 ) ;
if ( V_59 & V_180 ) {
strcat ( V_175 , L_47 ) ;
V_1 -> V_181 = true ;
}
if ( V_59 & V_182 ) {
strcat ( V_175 , L_48 ) ;
V_1 -> V_183 = true ;
}
if ( V_59 & V_184 ) {
strcat ( V_175 , L_49 ) ;
V_1 -> V_185 = true ;
}
if ( V_59 & V_186 ) {
strcat ( V_175 , L_50 ) ;
V_1 -> V_187 = true ;
}
if ( V_59 & V_188 ) {
strcat ( V_175 , L_51 ) ;
V_1 -> V_189 = true ;
}
if ( V_59 & V_190 )
strcat ( V_175 , L_52 ) ;
F_91 ( V_166 L_53 ,
V_167 , V_59 , V_175 ) ;
V_177 [ 0 ] = 0 ;
if ( V_191 == V_174 ) {
V_1 -> V_192 = 1 ;
type = L_54 ;
} else {
V_1 -> V_192 = 0 ;
type = L_55 ;
#ifndef F_97
F_91 ( V_193
L_56 ,
V_167 ) ;
#endif
}
V_1 -> V_194 = F_98 ( V_26 ) ;
snprintf ( V_176 , 32 , L_57 , F_99 ( V_1 -> V_194 ) ,
F_100 ( V_1 -> V_194 ) ,
( V_1 -> V_194 & V_195 ) ? L_58 : L_55 ) ;
F_91 ( V_166 L_59 ,
V_167 , type , V_176 , V_177 ) ;
F_101 ( V_1 ) ;
V_1 -> V_173 = 1 ;
V_1 -> V_106 = 1 ;
if ( V_1 -> V_181 )
V_178 = F_89 ( V_1 ) ;
else
V_178 = F_93 ( V_1 ) ;
if ( V_178 < 0 )
return V_178 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_173 ; V_9 ++ ) {
struct V_28 * V_29 = V_1 -> V_40 + V_9 ;
V_29 -> V_32 = V_1 -> V_36 . V_196 ( V_9 ) + V_26 ;
#if F_102 ( V_197 )
if ( V_1 -> V_36 . V_198 & V_199 ) {
V_29 -> V_200 = V_1 -> V_201 + 0x400 +
V_1 -> V_36 . V_196 ( V_9 ) ;
V_29 -> V_202 = V_1 -> V_203 + 0x400 +
V_1 -> V_36 . V_196 ( V_9 ) ;
V_29 -> V_204 =
V_1 -> V_205 + 0x400 + V_1 -> V_36 . V_196 ( V_9 ) ;
if ( V_9 == 0 )
V_29 -> V_206 = V_26 - 0x400 + V_207 ;
else
V_29 -> V_206 = V_26 + 0x400 +
( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
}
#endif
V_29 -> V_39 = V_1 -> V_36 . V_208 ( V_9 , 0 ) + V_26 ;
V_29 -> V_209 = F_103 ( V_9 , V_26 ) ;
V_29 -> V_210 = 1 ;
V_29 -> V_211 = 1 ;
if ( V_29 -> V_149 ) {
F_29 ( V_1 -> V_33 ,
L_60 ,
V_167 , V_9 ,
V_29 -> V_154 ? L_61 : L_62 ,
V_29 -> V_148
? L_63 : L_55 ,
V_29 -> V_149 ) ;
}
if ( V_29 -> V_152 && ! V_29 -> V_154 ) {
F_29 ( V_1 -> V_33 ,
L_60 ,
V_167 , V_9 ,
L_64 ,
V_29 -> V_151
? L_63 : L_55 ,
V_29 -> V_152 ) ;
}
if ( ! ( V_29 -> V_149 || V_29 -> V_152 ) )
F_29 ( V_1 -> V_33 , L_65 , V_9 ) ;
}
return 0 ;
}
T_5 F_104 ( struct V_1 * V_1 )
{
T_5 V_212 = V_69 ;
T_3 V_67 ;
int V_213 ;
T_1 V_59 ;
V_67 = F_5 ( V_1 -> V_41 , V_87 ) ;
F_29 ( V_1 -> V_33 , L_66 ,
F_70 ( V_1 ) ? L_13 : L_14 ,
V_1 -> V_66 , V_1 -> V_214 , V_1 -> V_215 ) ;
if ( V_1 -> V_66 )
V_212 |= F_52 ( V_1 , V_1 -> V_66 ,
V_67 ) ;
if ( V_1 -> V_214 & 1 ) {
if ( F_70 ( V_1 ) )
V_212 |= F_105 ( V_1 ) ;
else
V_212 |= F_106 ( V_1 ) ;
}
V_59 = V_1 -> V_215 >> 1 ;
V_213 = 1 ;
while ( V_59 ) {
if ( V_59 & 1 ) {
V_212 = V_71 ;
if ( F_70 ( V_1 ) )
F_107 ( V_1 , V_213 ) ;
else
F_108 ( V_1 , V_213 ) ;
}
V_59 >>= 1 ;
V_213 ++ ;
}
V_59 = V_1 -> V_214 >> 1 ;
V_213 = 1 ;
while ( V_59 ) {
if ( V_59 & 1 ) {
V_212 = V_71 ;
if ( F_70 ( V_1 ) )
F_109 ( V_1 , V_213 ) ;
else
F_110 ( V_1 , V_213 ) ;
}
V_59 >>= 1 ;
V_213 ++ ;
}
return V_212 ;
}
void F_111 ( struct V_1 * V_1 , T_3 V_25 , T_3 V_216 )
{
if ( ! V_25 ) {
#ifndef F_112
if ( ! F_113 () ) {
if ( F_70 ( V_1 ) )
F_105 ( V_1 ) ;
else
F_106 ( V_1 ) ;
}
#endif
} else {
if ( V_216 ) {
if ( F_70 ( V_1 ) )
F_109 ( V_1 , V_25 ) ;
else
F_110 ( V_1 , V_25 ) ;
} else {
if ( F_70 ( V_1 ) )
F_107 ( V_1 , V_25 ) ;
else
F_108 ( V_1 , V_25 ) ;
}
}
}
static T_6
F_114 ( struct V_2 * V_3 , struct V_217 * V_218 , char * V_219 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
int V_12 = - V_172 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
V_12 = sprintf ( V_219 , L_67 , F_47 ( V_1 -> V_48 -> V_49 -> V_50 ) ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return V_12 ;
}
static T_6
F_115 ( struct V_2 * V_3 , struct V_217 * V_218 ,
const char * V_219 , T_7 V_155 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
int V_178 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
if ( F_116 ( V_219 , L_13 ) )
V_178 = F_117 ( V_1 , V_220 ) ;
else if ( F_116 ( V_219 , L_14 ) )
V_178 = F_117 ( V_1 , V_221 ) ;
else if ( F_116 ( V_219 , L_68 ) )
V_178 = F_117 ( V_1 , V_222 ) ;
else
V_178 = - V_172 ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return ( V_178 == 0 ) ? V_155 : V_178 ;
}
static T_6
F_118 ( struct V_2 * V_3 , struct V_217 * V_218 ,
const char * V_219 , T_7 V_155 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
unsigned long V_223 ;
if ( sscanf ( V_219 , L_69 , & V_223 ) < 1 ) {
F_119 ( V_3 , L_70 ) ;
return - V_172 ;
}
F_45 ( & V_1 -> V_47 , V_46 ) ;
V_1 -> V_98 = V_223 ? F_120 ( int , V_223 , V_99 ) : 0 ;
if ( V_1 -> V_48 -> V_49 -> V_50 == V_55 )
V_1 -> V_53 = 0 ;
F_60 ( V_1 , V_78 + F_53 ( V_223 ) ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return V_155 ;
}
static T_6
F_121 ( struct V_2 * V_3 , struct V_217 * V_218 , char * V_219 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
unsigned long V_223 ;
int V_224 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
V_223 = V_1 -> V_98 ;
V_224 = F_122 ( V_1 ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return sprintf ( V_219 , L_71 ,
V_224 ? L_72 : L_73 , V_223 ) ;
}
static T_6
F_123 ( struct V_2 * V_3 , struct V_217 * V_218 ,
const char * V_219 , T_7 V_155 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_225 ;
if ( sscanf ( V_219 , L_74 , & V_225 ) != 1
|| ( V_225 != 1 ) ) {
F_119 ( V_3 , L_75 ) ;
return - V_172 ;
}
if ( V_225 == 1 )
F_124 ( V_1 ) ;
return V_155 ;
}
static void F_125 ( struct V_226 * V_24 )
{
struct V_1 * V_1 = F_126 ( V_24 , struct V_1 , V_121 ) ;
if ( V_1 -> V_48 -> V_49 -> V_50 != V_1 -> V_227 ) {
V_1 -> V_227 = V_1 -> V_48 -> V_49 -> V_50 ;
F_127 ( & V_1 -> V_33 -> V_228 , NULL , L_76 ) ;
}
}
static void F_128 ( struct V_226 * V_24 )
{
struct V_1 * V_1 = F_126 ( V_24 , struct V_1 , V_120 . V_229 ) ;
int V_178 , V_12 ;
V_12 = F_129 ( V_1 ) ;
if ( V_12 )
return;
F_130 ( V_1 -> V_48 ) ;
F_131 ( 100 , 200 ) ;
F_132 ( V_1 -> V_48 ) ;
F_131 ( 100 , 200 ) ;
if ( V_1 -> V_181 )
V_178 = F_89 ( V_1 ) ;
else
V_178 = F_93 ( V_1 ) ;
if ( V_178 == 0 )
F_74 ( V_1 ) ;
}
static struct V_1 * F_133 ( struct V_2 * V_3 ,
struct V_230 * V_141 , void T_2 * V_26 )
{
struct V_1 * V_1 ;
struct V_28 * V_231 ;
int V_25 ;
int V_12 ;
V_1 = F_134 ( V_3 , sizeof( * V_1 ) , V_232 ) ;
if ( ! V_1 )
return NULL ;
F_135 ( & V_1 -> V_233 ) ;
F_135 ( & V_1 -> V_234 ) ;
F_135 ( & V_1 -> V_235 ) ;
V_1 -> V_95 = V_236 ;
V_1 -> V_98 = V_99 ;
V_1 -> V_41 = V_26 ;
V_1 -> V_237 = V_26 ;
V_1 -> V_238 = - V_239 ;
V_1 -> V_141 = V_141 ;
F_136 ( V_1 -> V_141 -> V_171 > V_240 ) ;
for ( V_25 = 0 , V_231 = V_1 -> V_40 ;
V_25 < V_1 -> V_141 -> V_171 ;
V_25 ++ , V_231 ++ ) {
V_231 -> V_1 = V_1 ;
V_231 -> V_25 = V_25 ;
}
V_1 -> V_33 = V_3 ;
V_12 = F_137 ( V_1 ) ;
if ( V_12 < 0 )
goto V_241;
F_138 ( V_3 , V_1 ) ;
return V_1 ;
V_241:
return NULL ;
}
static void F_139 ( struct V_1 * V_1 )
{
#ifdef F_140
F_141 ( & V_1 -> V_33 -> V_228 , & V_242 ) ;
#endif
if ( V_1 -> V_238 >= 0 ) {
if ( V_1 -> V_243 )
F_142 ( V_1 -> V_238 ) ;
F_143 ( V_1 -> V_238 , V_1 ) ;
}
F_144 ( V_1 ) ;
}
static void F_145 ( struct V_226 * V_229 )
{
struct V_1 * V_1 ;
unsigned long V_46 ;
V_1 = F_126 ( V_229 , struct V_1 , V_244 . V_229 ) ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
if ( V_1 -> V_64 & V_245 )
F_146 ( V_1 , false ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
}
static int
F_147 ( struct V_2 * V_3 , int V_238 , void T_2 * V_246 )
{
int V_178 ;
struct V_1 * V_1 ;
struct V_247 * V_248 = F_148 ( V_3 ) ;
if ( ! V_248 ) {
F_29 ( V_3 , L_77 ) ;
V_178 = - V_239 ;
goto V_249;
}
V_1 = F_133 ( V_3 , V_248 -> V_141 , V_246 ) ;
if ( ! V_1 ) {
V_178 = - V_250 ;
goto V_249;
}
F_149 ( V_1 -> V_33 ) ;
F_150 ( V_1 -> V_33 , 200 ) ;
F_151 ( V_1 -> V_33 ) ;
F_152 ( & V_1 -> V_47 ) ;
V_1 -> V_251 = V_248 -> V_252 ;
V_1 -> V_253 = V_248 -> V_253 ;
V_1 -> V_254 = V_248 -> V_255 ;
V_1 -> V_129 = V_248 -> V_139 ;
F_5 = F_14 ;
F_6 = F_16 ;
F_37 = F_18 ;
F_32 = F_20 ;
V_256 = F_22 ;
V_257 = F_24 ;
V_178 = F_153 ( V_1 ) ;
if ( V_178 < 0 )
goto V_258;
if ( ! V_1 -> V_259 ) {
V_178 = - V_239 ;
goto V_260;
}
if ( V_1 -> V_254 -> V_198 )
V_1 -> V_36 . V_198 = V_1 -> V_254 -> V_198 ;
if ( V_1 -> V_254 -> V_208 )
V_1 -> V_36 . V_208 = V_1 -> V_254 -> V_208 ;
if ( V_1 -> V_254 -> V_261 )
V_1 -> V_36 . V_261 = V_1 -> V_254 -> V_261 ;
if ( V_1 -> V_36 . V_198 & V_262 ) {
V_1 -> V_36 . V_208 = F_13 ;
V_1 -> V_36 . V_261 = F_12 ;
} else {
V_1 -> V_36 . V_208 = F_11 ;
V_1 -> V_36 . V_261 = F_10 ;
}
if ( V_1 -> V_254 -> V_159 )
V_159 = V_1 -> V_254 -> V_159 ;
else
V_159 = 4 ;
if ( V_1 -> V_254 -> V_196 )
V_1 -> V_36 . V_196 = V_1 -> V_254 -> V_196 ;
else
V_1 -> V_36 . V_196 = F_9 ;
if ( V_1 -> V_254 -> V_263 )
F_5 = V_1 -> V_254 -> V_263 ;
if ( V_1 -> V_254 -> V_264 )
F_6 = V_1 -> V_254 -> V_264 ;
if ( V_1 -> V_254 -> V_265 )
F_37 = V_1 -> V_254 -> V_265 ;
if ( V_1 -> V_254 -> V_266 )
F_32 = V_1 -> V_254 -> V_266 ;
if ( V_1 -> V_254 -> V_267 )
V_256 = V_1 -> V_254 -> V_267 ;
if ( V_1 -> V_254 -> V_268 )
V_257 = V_1 -> V_254 -> V_268 ;
if ( V_1 -> V_254 -> V_37 )
V_1 -> V_36 . V_37 = V_1 -> V_254 -> V_37 ;
else
V_1 -> V_36 . V_37 = F_35 ;
if ( V_1 -> V_254 -> V_38 )
V_1 -> V_36 . V_38 = V_1 -> V_254 -> V_38 ;
else
V_1 -> V_36 . V_38 = F_26 ;
if ( ! V_1 -> V_48 -> V_269 ) {
V_1 -> V_48 -> V_13 = V_1 -> V_33 ;
V_1 -> V_48 -> V_8 = V_1 -> V_41 ;
V_1 -> V_48 -> V_269 = & V_270 ;
}
F_4 ( V_1 -> V_33 ) ;
if ( V_271 && V_3 -> V_272 ) {
V_1 -> V_273 = F_154 ( V_1 , V_1 -> V_41 ) ;
if ( F_155 ( V_1 -> V_273 ) ) {
V_178 = F_156 ( V_1 -> V_273 ) ;
goto V_274;
}
}
F_77 ( V_1 ) ;
F_71 ( V_1 ) ;
F_157 ( & V_1 -> V_121 , F_125 ) ;
F_158 ( & V_1 -> V_120 , F_128 ) ;
F_158 ( & V_1 -> V_244 , F_145 ) ;
F_158 ( & V_1 -> V_275 , V_276 ) ;
V_178 = F_95 ( V_248 -> V_141 -> V_277
? V_191
: V_278 , V_1 ) ;
if ( V_178 < 0 )
goto V_279;
F_159 ( & V_1 -> V_102 , F_44 , ( unsigned long ) V_1 ) ;
if ( F_160 ( V_238 , V_1 -> V_259 , 0 , F_161 ( V_3 ) , V_1 ) ) {
F_119 ( V_3 , L_78 , V_238 ) ;
V_178 = - V_239 ;
goto V_279;
}
V_1 -> V_238 = V_238 ;
if ( F_162 ( V_238 ) == 0 ) {
V_1 -> V_243 = 1 ;
F_163 ( V_3 , 1 ) ;
} else {
V_1 -> V_243 = 0 ;
}
if ( V_248 -> V_280 ) {
T_3 V_281 = F_164 ( V_1 -> V_41 ) ;
V_281 |= V_282 ;
F_165 ( V_1 -> V_41 , V_281 ) ;
}
if ( V_1 -> V_48 -> V_49 -> V_283 ) {
F_57 ( V_1 ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_91 ;
} else {
F_51 ( V_1 ) ;
V_1 -> V_48 -> V_49 -> V_50 = V_84 ;
}
switch ( V_1 -> V_129 ) {
case V_130 :
V_178 = F_166 ( V_1 , V_248 -> V_11 ) ;
if ( V_178 < 0 )
goto V_279;
V_178 = F_117 ( V_1 , V_220 ) ;
break;
case V_284 :
V_178 = F_167 ( V_1 ) ;
if ( V_178 < 0 )
goto V_279;
V_178 = F_117 ( V_1 , V_221 ) ;
break;
case V_285 :
V_178 = F_166 ( V_1 , V_248 -> V_11 ) ;
if ( V_178 < 0 )
goto V_279;
V_178 = F_167 ( V_1 ) ;
if ( V_178 ) {
F_79 ( V_1 ) ;
goto V_279;
}
V_178 = F_117 ( V_1 , V_222 ) ;
break;
default:
F_119 ( V_3 , L_79 , V_1 -> V_129 ) ;
break;
}
if ( V_178 < 0 )
goto V_279;
V_178 = F_168 ( V_1 ) ;
if ( V_178 < 0 )
goto V_286;
V_178 = F_169 ( & V_1 -> V_33 -> V_228 , & V_242 ) ;
if ( V_178 )
goto V_287;
F_7 ( V_1 -> V_33 ) ;
return 0 ;
V_287:
F_170 ( V_1 ) ;
V_286:
F_80 ( V_1 ) ;
F_79 ( V_1 ) ;
V_279:
F_171 ( & V_1 -> V_121 ) ;
F_172 ( & V_1 -> V_120 ) ;
F_172 ( & V_1 -> V_275 ) ;
F_172 ( & V_1 -> V_244 ) ;
if ( V_1 -> V_273 )
F_173 ( V_1 -> V_273 ) ;
V_274:
F_174 ( V_1 -> V_33 ) ;
V_260:
if ( V_1 -> V_243 )
F_163 ( V_3 , 0 ) ;
F_81 ( V_1 ) ;
V_258:
F_175 ( V_1 -> V_33 ) ;
F_119 ( V_1 -> V_33 ,
L_80 , V_178 ) ;
F_139 ( V_1 ) ;
V_249:
return V_178 ;
}
static int F_176 ( struct V_131 * V_132 )
{
struct V_2 * V_3 = & V_132 -> V_3 ;
int V_288 = F_177 ( V_132 , L_81 ) ;
struct V_289 * V_290 ;
void T_2 * V_291 ;
if ( V_288 <= 0 )
return - V_239 ;
V_290 = F_178 ( V_132 , V_292 , 0 ) ;
V_291 = F_179 ( V_3 , V_290 ) ;
if ( F_155 ( V_291 ) )
return F_156 ( V_291 ) ;
return F_147 ( V_3 , V_288 , V_291 ) ;
}
static int F_180 ( struct V_131 * V_132 )
{
struct V_2 * V_3 = & V_132 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_170 ( V_1 ) ;
F_78 ( V_132 ) ;
if ( V_1 -> V_273 )
F_173 ( V_1 -> V_273 ) ;
F_171 ( & V_1 -> V_121 ) ;
F_172 ( & V_1 -> V_120 ) ;
F_172 ( & V_1 -> V_275 ) ;
F_172 ( & V_1 -> V_244 ) ;
F_139 ( V_1 ) ;
F_163 ( V_3 , 0 ) ;
return 0 ;
}
static void F_181 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_293 = V_1 -> V_41 ;
void T_2 * V_294 ;
V_1 -> V_295 . V_296 = F_37 ( V_293 , V_297 ) ;
V_1 -> V_295 . V_298 = F_5 ( V_293 , V_126 ) ;
V_1 -> V_295 . V_281 = F_164 ( V_1 -> V_41 ) ;
V_1 -> V_295 . V_11 = F_5 ( V_293 , V_14 ) ;
V_1 -> V_295 . V_299 = F_5 ( V_293 , V_110 ) ;
V_1 -> V_295 . V_34 = F_5 ( V_293 , V_27 ) ;
V_1 -> V_295 . V_67 = F_5 ( V_293 , V_87 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_141 -> V_171 ; ++ V_9 ) {
struct V_28 * V_29 ;
V_29 = & V_1 -> V_40 [ V_9 ] ;
if ( ! V_29 )
continue;
V_294 = V_29 -> V_39 ;
if ( ! V_294 )
continue;
F_6 ( V_293 , V_27 , V_9 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_301 =
F_37 ( V_294 , V_302 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_303 =
F_37 ( V_294 , V_304 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_305 =
F_37 ( V_294 , V_306 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_307 =
F_37 ( V_294 , V_308 ) ;
if ( V_1 -> V_181 ) {
V_1 -> V_295 . V_300 [ V_9 ] . V_309 =
F_182 ( V_293 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_310 =
F_183 ( V_293 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_311 =
F_184 ( V_293 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_312 =
F_185 ( V_293 ) ;
}
V_1 -> V_295 . V_300 [ V_9 ] . V_313 =
F_5 ( V_294 , V_314 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_315 =
F_5 ( V_294 , V_316 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_317 =
F_5 ( V_294 , V_318 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_319 =
F_5 ( V_294 , V_320 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_321 =
F_186 ( V_293 , V_9 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_322 =
F_187 ( V_293 , V_9 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_323 =
F_188 ( V_293 , V_9 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_324 =
F_189 ( V_293 , V_9 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_325 =
F_190 ( V_293 , V_9 ) ;
V_1 -> V_295 . V_300 [ V_9 ] . V_326 =
F_191 ( V_293 , V_9 ) ;
}
}
static void F_192 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_293 = V_1 -> V_41 ;
void T_2 * V_327 ;
void T_2 * V_294 ;
T_3 V_11 ;
F_32 ( V_293 , V_297 , V_1 -> V_295 . V_296 ) ;
F_6 ( V_293 , V_126 , V_1 -> V_295 . V_298 ) ;
F_165 ( V_1 -> V_41 , V_1 -> V_295 . V_281 ) ;
V_11 = F_5 ( V_293 , V_14 ) ;
V_11 &= V_15 | V_74 ;
V_1 -> V_295 . V_11 &= ~ ( V_15 | V_74 ) ;
V_11 |= V_1 -> V_295 . V_11 ;
F_6 ( V_293 , V_14 , V_11 ) ;
F_32 ( V_293 , V_107 , V_1 -> V_105 ) ;
F_32 ( V_293 , V_109 , V_1 -> V_108 ) ;
F_6 ( V_293 , V_110 , V_1 -> V_295 . V_299 ) ;
F_6 ( V_293 , V_87 , V_1 -> V_295 . V_67 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_141 -> V_171 ; ++ V_9 ) {
struct V_28 * V_29 ;
V_29 = & V_1 -> V_40 [ V_9 ] ;
if ( ! V_29 )
continue;
V_294 = V_29 -> V_39 ;
if ( ! V_294 )
continue;
F_6 ( V_293 , V_27 , V_9 ) ;
F_32 ( V_294 , V_302 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_301 ) ;
F_32 ( V_294 , V_304 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_303 ) ;
F_32 ( V_294 , V_306 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_305 ) ;
F_32 ( V_294 , V_308 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_307 ) ;
if ( V_1 -> V_181 ) {
F_85 ( V_293 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_311 ) ;
F_87 ( V_293 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_312 ) ;
F_86 ( V_293 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_309 ) ;
F_88 ( V_293 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_310 ) ;
}
F_6 ( V_294 , V_314 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_313 ) ;
F_6 ( V_294 , V_316 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_315 ) ;
F_6 ( V_294 , V_318 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_317 ) ;
F_6 ( V_294 , V_320 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_319 ) ;
F_193 ( V_293 , V_9 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_321 ) ;
F_194 ( V_293 , V_9 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_322 ) ;
F_195 ( V_293 , V_9 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_323 ) ;
V_327 =
F_103 ( V_9 , V_293 ) ;
F_196 ( V_327 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_324 ) ;
F_197 ( V_327 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_325 ) ;
F_198 ( V_327 ,
V_1 -> V_295 . V_300 [ V_9 ] . V_326 ) ;
}
F_6 ( V_293 , V_27 , V_1 -> V_295 . V_34 ) ;
}
static int F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_46 ;
F_45 ( & V_1 -> V_47 , V_46 ) ;
if ( F_63 ( V_1 ) ) {
} else if ( F_70 ( V_1 ) ) {
}
F_181 ( V_1 ) ;
F_49 ( & V_1 -> V_47 , V_46 ) ;
return 0 ;
}
static int F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_67 ;
T_3 V_328 ;
F_192 ( V_1 ) ;
V_67 = F_5 ( V_1 -> V_41 , V_87 ) ;
V_328 = V_86 | V_118 | V_115 ;
if ( ( V_67 & V_328 ) != ( V_1 -> V_295 . V_67 & V_328 ) )
V_1 -> V_64 = 0 ;
if ( V_1 -> V_79 ) {
V_1 -> V_79 = 0 ;
F_72 ( & V_1 -> V_275 ,
F_53 ( 20 ) ) ;
}
F_175 ( V_3 ) ;
F_201 ( V_3 ) ;
F_151 ( V_3 ) ;
return 0 ;
}
static int F_202 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_181 ( V_1 ) ;
return 0 ;
}
static int F_203 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_329 = 1 ;
if ( ! V_329 )
F_192 ( V_1 ) ;
V_329 = 0 ;
return 0 ;
}
