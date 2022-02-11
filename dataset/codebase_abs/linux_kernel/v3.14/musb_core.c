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
void F_9 ( struct V_25 * V_26 , T_4 V_27 , const T_3 * V_28 )
{
struct V_1 * V_1 = V_26 -> V_1 ;
void T_2 * V_29 = V_26 -> V_29 ;
if ( F_10 ( V_27 == 0 ) )
return;
F_11 ( ( T_3 * ) V_28 ) ;
F_12 ( V_1 -> V_30 , L_1 ,
'T' , V_26 -> V_31 , V_29 , V_27 , V_28 ) ;
if ( F_13 ( ( 0x01 & ( unsigned long ) V_28 ) == 0 ) ) {
T_4 V_32 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_28 ) == 0 ) {
if ( V_27 >= 4 ) {
F_14 ( V_29 , V_28 + V_32 , V_27 >> 2 ) ;
V_32 += V_27 & ~ 0x03 ;
}
if ( V_27 & 0x02 ) {
F_15 ( V_29 , 0 , * ( T_4 * ) & V_28 [ V_32 ] ) ;
V_32 += 2 ;
}
} else {
if ( V_27 >= 2 ) {
F_16 ( V_29 , V_28 + V_32 , V_27 >> 1 ) ;
V_32 += V_27 & ~ 0x01 ;
}
}
if ( V_27 & 0x01 )
F_6 ( V_29 , 0 , V_28 [ V_32 ] ) ;
} else {
F_17 ( V_29 , V_28 , V_27 ) ;
}
}
void F_18 ( struct V_25 * V_26 , T_4 V_27 , T_3 * V_33 )
{
struct V_1 * V_1 = V_26 -> V_1 ;
void T_2 * V_29 = V_26 -> V_29 ;
if ( F_10 ( V_27 == 0 ) )
return;
F_12 ( V_1 -> V_30 , L_1 ,
'R' , V_26 -> V_31 , V_29 , V_27 , V_33 ) ;
if ( F_13 ( ( 0x01 & ( unsigned long ) V_33 ) == 0 ) ) {
T_4 V_32 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_33 ) == 0 ) {
if ( V_27 >= 4 ) {
F_19 ( V_29 , V_33 , V_27 >> 2 ) ;
V_32 = V_27 & ~ 0x03 ;
}
if ( V_27 & 0x02 ) {
* ( T_4 * ) & V_33 [ V_32 ] = F_20 ( V_29 , 0 ) ;
V_32 += 2 ;
}
} else {
if ( V_27 >= 2 ) {
F_21 ( V_29 , V_33 , V_27 >> 1 ) ;
V_32 = V_27 & ~ 0x01 ;
}
}
if ( V_27 & 0x01 )
V_33 [ V_32 ] = F_5 ( V_29 , 0 ) ;
} else {
F_22 ( V_29 , V_33 , V_27 ) ;
}
}
void F_23 ( struct V_1 * V_1 )
{
void T_2 * V_34 = V_1 -> V_35 [ 0 ] . V_34 ;
F_24 ( V_1 -> V_36 , 0 ) ;
F_9 ( V_1 -> V_37 ,
sizeof( V_38 ) , V_38 ) ;
F_15 ( V_34 , V_39 , V_40 ) ;
}
static void F_25 ( unsigned long V_24 )
{
struct V_1 * V_1 = (struct V_1 * ) V_24 ;
unsigned long V_41 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_45 :
F_12 ( V_1 -> V_30 , L_2 ) ;
F_27 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_46 ;
V_1 -> V_47 = 0 ;
break;
case V_48 :
case V_49 :
F_12 ( V_1 -> V_30 , L_3 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
F_29 ( V_1 , 0 ) ;
V_1 -> V_43 -> V_44 = V_50 ;
break;
default:
F_12 ( V_1 -> V_30 , L_4 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
F_30 ( & V_1 -> V_42 , V_41 ) ;
}
void F_31 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = V_1 -> V_52 ;
void T_2 * V_53 = V_1 -> V_36 ;
T_3 V_54 ;
F_12 ( V_1 -> V_30 , L_5 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_55 :
F_27 ( V_1 ) ;
F_12 ( V_1 -> V_30 , L_6 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
break;
case V_56 :
F_12 ( V_1 -> V_30 , L_7 ) ;
if ( V_52 )
V_52 -> V_57 . V_58 = 0 ;
V_1 -> V_43 -> V_44 = V_46 ;
F_32 ( V_1 ) ;
V_54 = F_5 ( V_53 , V_14 ) ;
V_54 |= V_15 ;
F_6 ( V_53 , V_14 , V_54 ) ;
break;
default:
F_12 ( V_1 -> V_30 , L_8 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
V_1 -> V_59 &= ~ ( V_60 << 16 ) ;
}
static T_5 F_33 ( struct V_1 * V_1 , T_3 V_61 ,
T_3 V_62 )
{
struct V_63 * V_64 = V_1 -> V_43 -> V_64 ;
T_5 V_65 = V_66 ;
F_12 ( V_1 -> V_30 , L_9 , V_62 ,
V_61 ) ;
if ( V_61 & V_67 ) {
V_65 = V_68 ;
F_12 ( V_1 -> V_30 , L_10 , F_28 ( V_1 -> V_43 -> V_44 ) ) ;
if ( V_62 & V_69 ) {
void T_2 * V_53 = V_1 -> V_36 ;
T_3 V_11 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
V_11 = F_5 ( V_1 -> V_36 , V_14 ) ;
if ( V_11 & V_15 ) {
V_1 -> V_61 &= ~ V_70 ;
F_12 ( V_1 -> V_30 , L_11 ) ;
break;
}
V_11 &= ~ V_15 ;
F_6 ( V_53 , V_14 ,
V_11 | V_71 ) ;
V_1 -> V_59 |=
( V_72 << 16 )
| V_73 ;
V_1 -> V_74 = V_75
+ F_34 ( 20 ) ;
F_35 (
& V_1 -> V_76 ,
F_34 ( 20 ) ) ;
V_1 -> V_43 -> V_44 = V_77 ;
V_1 -> V_47 = 1 ;
F_36 ( V_1 ) ;
break;
case V_45 :
V_1 -> V_43 -> V_44 = V_46 ;
V_1 -> V_47 = 1 ;
F_32 ( V_1 ) ;
break;
default:
F_37 ( L_12 ,
L_13 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
} else {
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
V_1 -> V_43 -> V_44 = V_77 ;
F_36 ( V_1 ) ;
break;
case V_45 :
case V_46 :
if ( ( V_62 & V_78 )
!= ( 3 << V_79 )
) {
V_1 -> V_61 |= V_80 ;
V_1 -> V_61 &= ~ V_70 ;
break;
}
F_38 ( V_1 ) ;
break;
case V_81 :
V_1 -> V_61 &= ~ V_70 ;
break;
default:
F_37 ( L_12 ,
L_14 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
}
}
if ( V_61 & V_82 ) {
void T_2 * V_53 = V_1 -> V_36 ;
if ( ( V_62 & V_78 ) == V_78
&& ( V_62 & V_83 ) ) {
F_12 ( V_1 -> V_30 , L_15 ) ;
return V_68 ;
}
F_12 ( V_1 -> V_30 , L_16 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
F_6 ( V_53 , V_84 , V_85 ) ;
V_1 -> V_86 = V_87 ;
V_1 -> V_43 -> V_44 = V_88 ;
F_39 ( V_1 ) ;
F_29 ( V_1 , 1 ) ;
V_65 = V_68 ;
}
if ( V_61 & V_89 ) {
int V_90 = 0 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_77 :
case V_49 :
case V_91 :
if ( V_1 -> V_92 ) {
void T_2 * V_53 = V_1 -> V_36 ;
V_1 -> V_92 -- ;
V_90 = 1 ;
V_62 |= V_85 ;
F_6 ( V_53 , V_84 , V_62 ) ;
} else {
V_1 -> V_59 |=
V_93
| ( V_94 << 16 ) ;
}
break;
default:
break;
}
F_40 (ignore ? KERN_DEBUG : KERN_ERR, musb->controller,
L_17 ,
usb_otg_state_string(musb->xceiv->state),
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
if ( ! V_90 )
F_29 ( V_1 , 0 ) ;
V_65 = V_68 ;
}
if ( V_61 & V_70 ) {
F_12 ( V_1 -> V_30 , L_22 ,
F_28 ( V_1 -> V_43 -> V_44 ) , V_62 ) ;
V_65 = V_68 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_55 :
F_31 ( V_1 ) ;
F_36 ( V_1 ) ;
F_41 ( V_1 ) ;
F_42 ( V_1 , V_75
+ F_34 ( V_1 -> V_95
? : V_96 ) ) ;
break;
case V_81 :
if ( ! V_1 -> V_47 )
break;
case V_46 :
F_43 ( V_1 ) ;
V_1 -> V_47 = V_64 -> V_97 -> V_98 ;
if ( V_1 -> V_47 ) {
V_1 -> V_43 -> V_44 = V_45 ;
F_12 ( V_1 -> V_30 , L_23 ) ;
F_44 ( & V_1 -> V_99 , V_75
+ F_34 (
V_100 ) ) ;
}
break;
case V_49 :
if ( V_1 -> V_95 != 0 )
F_42 ( V_1 , V_75
+ F_34 ( V_1 -> V_95 ) ) ;
break;
case V_77 :
V_1 -> V_43 -> V_44 = V_48 ;
V_1 -> V_47 = V_64 -> V_101 -> V_98 ;
break;
case V_56 :
F_12 ( V_1 -> V_30 , L_24 ) ;
break;
default:
V_1 -> V_47 = 0 ;
break;
}
}
if ( V_61 & V_102 ) {
struct V_51 * V_52 = V_1 -> V_52 ;
V_65 = V_68 ;
V_1 -> V_47 = 1 ;
V_1 -> V_86 = V_87 ;
if ( F_45 ( V_1 ) ) {
}
V_1 -> V_103 = V_1 -> V_104 ;
F_15 ( V_1 -> V_36 , V_105 , V_1 -> V_103 ) ;
V_1 -> V_106 = V_1 -> V_104 & 0xfffe ;
F_15 ( V_1 -> V_36 , V_107 , V_1 -> V_106 ) ;
F_6 ( V_1 -> V_36 , V_108 , 0xf7 ) ;
V_1 -> V_59 &= ~ ( V_109
| V_110
| V_111
) ;
V_1 -> V_59 |= V_112
| ( V_60 << 16 ) ;
if ( V_62 & V_113 )
V_1 -> V_59 |= V_109 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_46 :
if ( V_61 & V_70 ) {
F_12 ( V_1 -> V_30 , L_25 ) ;
V_61 &= ~ V_70 ;
goto V_114;
} else
F_12 ( V_1 -> V_30 , L_26 ) ;
break;
case V_45 :
F_12 ( V_1 -> V_30 , L_27 ) ;
V_114:
V_1 -> V_43 -> V_44 = V_56 ;
if ( V_1 -> V_52 )
V_1 -> V_52 -> V_57 . V_58 = 1 ;
F_46 ( & V_1 -> V_99 ) ;
break;
default:
if ( ( V_62 & V_78 )
== ( 3 << V_79 ) ) {
V_1 -> V_43 -> V_44 = V_77 ;
if ( V_52 )
V_52 -> V_57 . V_58 = 0 ;
}
break;
}
F_47 ( V_1 ) ;
F_12 ( V_1 -> V_30 , L_28 ,
F_28 ( V_1 -> V_43 -> V_44 ) , V_62 ) ;
}
if ( V_61 & V_80 ) {
F_12 ( V_1 -> V_30 , L_29 ,
F_28 ( V_1 -> V_43 -> V_44 ) ,
F_48 ( V_1 ) , V_62 ) ;
V_65 = V_68 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_77 :
case V_48 :
F_36 ( V_1 ) ;
F_41 ( V_1 ) ;
if ( V_1 -> V_95 != 0 )
F_42 ( V_1 , V_75
+ F_34 ( V_1 -> V_95 ) ) ;
break;
case V_56 :
F_41 ( V_1 ) ;
if ( V_1 -> V_52 )
V_1 -> V_52 -> V_57 . V_58 = 0 ;
V_1 -> V_43 -> V_44 = V_46 ;
F_32 ( V_1 ) ;
F_27 ( V_1 ) ;
break;
case V_55 :
F_31 ( V_1 ) ;
F_41 ( V_1 ) ;
case V_45 :
case V_46 :
case V_81 :
F_27 ( V_1 ) ;
break;
default:
F_37 ( L_30 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
break;
}
}
if ( V_61 & V_115 ) {
V_65 = V_68 ;
if ( ( V_62 & V_69 ) != 0 ) {
if ( V_62 & ( V_116 | V_113 ) )
F_12 ( V_1 -> V_30 , L_31 , V_62 ) ;
else {
F_49 ( L_32 ) ;
F_6 ( V_1 -> V_36 , V_84 , 0 ) ;
}
} else {
F_12 ( V_1 -> V_30 , L_33 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
F_50 ( V_1 ) ;
case V_49 :
F_12 ( V_1 -> V_30 , L_34 ,
F_28 ( V_1 -> V_43 -> V_44 ) ,
F_51 ( V_1 ) ) ;
F_44 ( & V_1 -> V_99 , V_75
+ F_34 ( F_51 ( V_1 ) ) ) ;
break;
case V_55 :
F_46 ( & V_1 -> V_99 ) ;
F_50 ( V_1 ) ;
break;
case V_45 :
F_12 ( V_1 -> V_30 , L_35 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
V_1 -> V_43 -> V_44 = V_46 ;
F_50 ( V_1 ) ;
break;
case V_81 :
V_1 -> V_43 -> V_44 = V_46 ;
case V_46 :
F_50 ( V_1 ) ;
break;
default:
F_12 ( V_1 -> V_30 , L_36 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
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
F_52 ( & V_1 -> V_117 ) ;
return V_65 ;
}
static void F_53 ( struct V_1 * V_1 )
{
void T_2 * V_53 = V_1 -> V_36 ;
T_4 V_118 ;
F_6 ( V_53 , V_108 , 0 ) ;
V_1 -> V_103 = 0 ;
F_15 ( V_53 , V_105 , 0 ) ;
V_1 -> V_106 = 0 ;
F_15 ( V_53 , V_107 , 0 ) ;
F_6 ( V_53 , V_84 , 0 ) ;
V_118 = F_5 ( V_53 , V_119 ) ;
V_118 = F_20 ( V_53 , V_120 ) ;
V_118 = F_20 ( V_53 , V_121 ) ;
}
void F_54 ( struct V_1 * V_1 )
{
void T_2 * V_34 = V_1 -> V_36 ;
T_3 V_62 = F_5 ( V_34 , V_84 ) ;
F_12 ( V_1 -> V_30 , L_37 , V_62 ) ;
V_1 -> V_103 = V_1 -> V_104 ;
F_15 ( V_34 , V_105 , V_1 -> V_103 ) ;
V_1 -> V_106 = V_1 -> V_104 & 0xfffe ;
F_15 ( V_34 , V_107 , V_1 -> V_106 ) ;
F_6 ( V_34 , V_108 , 0xf7 ) ;
F_6 ( V_34 , V_122 , 0 ) ;
F_6 ( V_34 , V_14 , V_123
| V_124
) ;
V_1 -> V_47 = 0 ;
V_62 = F_5 ( V_34 , V_84 ) ;
V_62 &= ~ V_85 ;
if ( V_1 -> V_125 != V_126 &&
( V_62 & V_78 ) == V_78 ) {
V_1 -> V_47 = 1 ;
} else {
V_62 |= V_85 ;
}
F_55 ( V_1 ) ;
F_6 ( V_34 , V_84 , V_62 ) ;
}
void F_56 ( struct V_1 * V_1 )
{
F_57 ( V_1 ) ;
F_53 ( V_1 ) ;
F_12 ( V_1 -> V_30 , L_38 ) ;
F_42 ( V_1 , 0 ) ;
}
static void F_58 ( struct V_127 * V_128 )
{
struct V_1 * V_1 = F_1 ( & V_128 -> V_3 ) ;
unsigned long V_41 ;
F_4 ( V_1 -> V_30 ) ;
F_59 ( V_1 ) ;
F_60 ( V_1 ) ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
F_57 ( V_1 ) ;
F_53 ( V_1 ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
F_6 ( V_1 -> V_36 , V_84 , 0 ) ;
F_61 ( V_1 ) ;
F_7 ( V_1 -> V_30 ) ;
}
static int
F_62 ( struct V_1 * V_1 , struct V_25 * V_26 ,
const struct V_129 * V_130 , T_4 V_6 )
{
void T_2 * V_53 = V_1 -> V_36 ;
int V_131 = 0 ;
T_4 V_132 = V_130 -> V_132 ;
T_4 V_133 = V_6 >> 3 ;
T_3 V_134 ;
V_131 = F_63 ( F_64 ( V_132 , ( T_4 ) 8 ) ) - 1 ;
V_132 = 1 << V_131 ;
V_134 = V_131 - 3 ;
if ( V_130 -> V_135 == V_136 ) {
if ( ( V_6 + ( V_132 << 1 ) ) >
( 1 << ( V_1 -> V_137 -> V_138 + 2 ) ) )
return - V_139 ;
V_134 |= V_140 ;
} else {
if ( ( V_6 + V_132 ) > ( 1 << ( V_1 -> V_137 -> V_138 + 2 ) ) )
return - V_139 ;
}
F_6 ( V_53 , V_141 , V_26 -> V_31 ) ;
if ( V_26 -> V_31 == 1 )
V_1 -> V_142 = V_26 ;
switch ( V_130 -> V_143 ) {
case V_144 :
F_65 ( V_53 , V_134 ) ;
F_66 ( V_53 , V_133 ) ;
V_26 -> V_145 = ! ! ( V_134 & V_140 ) ;
V_26 -> V_146 = V_132 ;
break;
case V_147 :
F_67 ( V_53 , V_134 ) ;
F_68 ( V_53 , V_133 ) ;
V_26 -> V_148 = ! ! ( V_134 & V_140 ) ;
V_26 -> V_149 = V_132 ;
break;
case V_150 :
F_65 ( V_53 , V_134 ) ;
F_66 ( V_53 , V_133 ) ;
V_26 -> V_148 = ! ! ( V_134 & V_140 ) ;
V_26 -> V_149 = V_132 ;
F_67 ( V_53 , V_134 ) ;
F_68 ( V_53 , V_133 ) ;
V_26 -> V_145 = V_26 -> V_148 ;
V_26 -> V_146 = V_132 ;
V_26 -> V_151 = true ;
break;
}
V_1 -> V_104 |= ( 1 << V_26 -> V_31 ) ;
return V_6 + ( V_132 << ( ( V_134 & V_140 ) ? 1 : 0 ) ) ;
}
static int F_69 ( struct V_1 * V_1 )
{
const struct V_129 * V_130 ;
unsigned V_9 , V_152 ;
int V_6 ;
struct V_25 * V_26 = V_1 -> V_35 ;
if ( V_1 -> V_137 -> V_153 ) {
V_130 = V_1 -> V_137 -> V_153 ;
V_152 = V_1 -> V_137 -> V_154 ;
goto V_155;
}
switch ( V_156 ) {
default:
V_156 = 0 ;
case 0 :
V_130 = V_157 ;
V_152 = F_70 ( V_157 ) ;
break;
case 1 :
V_130 = V_158 ;
V_152 = F_70 ( V_158 ) ;
break;
case 2 :
V_130 = V_159 ;
V_152 = F_70 ( V_159 ) ;
break;
case 3 :
V_130 = V_160 ;
V_152 = F_70 ( V_160 ) ;
break;
case 4 :
V_130 = V_161 ;
V_152 = F_70 ( V_161 ) ;
break;
case 5 :
V_130 = V_162 ;
V_152 = F_70 ( V_162 ) ;
break;
}
F_71 ( V_163 L_39 ,
V_164 , V_156 ) ;
V_155:
V_6 = F_62 ( V_1 , V_26 , & V_165 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_152 ; V_9 ++ ) {
T_3 V_166 = V_130 -> V_167 ;
if ( V_166 >= V_1 -> V_137 -> V_168 ) {
F_72 ( L_40 ,
V_164 , V_166 ) ;
return - V_169 ;
}
V_6 = F_62 ( V_1 , V_26 + V_166 , V_130 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_72 ( L_41 ,
V_164 , V_166 ) ;
return V_6 ;
}
V_166 ++ ;
V_1 -> V_170 = F_64 ( V_166 , V_1 -> V_170 ) ;
}
F_71 ( V_163 L_42 ,
V_164 ,
V_152 + 1 , V_1 -> V_137 -> V_168 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_137 -> V_138 + 2 ) ) ) ;
if ( ! V_1 -> V_142 ) {
F_72 ( L_43 , V_164 ) ;
return - V_169 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_1 )
{
T_3 V_31 = 0 ;
struct V_25 * V_26 ;
void T_2 * V_53 = V_1 -> V_36 ;
int V_12 = 0 ;
F_12 ( V_1 -> V_30 , L_44 ) ;
for ( V_31 = 1 ; V_31 < V_1 -> V_137 -> V_168 ; V_31 ++ ) {
F_24 ( V_53 , V_31 ) ;
V_26 = V_1 -> V_35 + V_31 ;
V_12 = F_74 ( V_1 , V_26 , V_31 ) ;
if ( V_12 < 0 )
break;
if ( V_26 -> V_146 < 512
|| V_26 -> V_149 < 512 )
continue;
if ( V_1 -> V_142 )
continue;
V_1 -> V_142 = V_26 ;
}
if ( ! V_1 -> V_142 ) {
F_72 ( L_43 , V_164 ) ;
return - V_169 ;
}
return 0 ;
}
static int F_75 ( T_4 V_171 , struct V_1 * V_1 )
{
T_3 V_54 ;
char * type ;
char V_172 [ 90 ] , V_173 [ 32 ] , V_174 [ 12 ] ;
void T_2 * V_53 = V_1 -> V_36 ;
int V_175 = 0 ;
int V_9 ;
V_54 = F_76 ( V_53 ) ;
strcpy ( V_172 , ( V_54 & V_176 ) ? L_45 : L_46 ) ;
if ( V_54 & V_177 ) {
strcat ( V_172 , L_47 ) ;
V_1 -> V_178 = true ;
}
if ( V_54 & V_179 ) {
strcat ( V_172 , L_48 ) ;
V_1 -> V_180 = true ;
}
if ( V_54 & V_181 ) {
strcat ( V_172 , L_49 ) ;
V_1 -> V_182 = true ;
}
if ( V_54 & V_183 ) {
strcat ( V_172 , L_50 ) ;
V_1 -> V_184 = true ;
}
if ( V_54 & V_185 ) {
strcat ( V_172 , L_51 ) ;
V_1 -> V_186 = true ;
}
if ( V_54 & V_187 )
strcat ( V_172 , L_52 ) ;
F_71 ( V_163 L_53 ,
V_164 , V_54 , V_172 ) ;
V_174 [ 0 ] = 0 ;
if ( V_188 == V_171 ) {
V_1 -> V_189 = 1 ;
type = L_54 ;
} else {
V_1 -> V_189 = 0 ;
type = L_55 ;
#ifndef F_77
F_71 ( V_190
L_56 ,
V_164 ) ;
#endif
}
V_1 -> V_191 = F_78 ( V_53 ) ;
snprintf ( V_173 , 32 , L_57 , F_79 ( V_1 -> V_191 ) ,
F_80 ( V_1 -> V_191 ) ,
( V_1 -> V_191 & V_192 ) ? L_58 : L_55 ) ;
F_71 ( V_163 L_59 ,
V_164 , type , V_173 , V_174 ) ;
F_81 ( V_1 ) ;
V_1 -> V_170 = 1 ;
V_1 -> V_104 = 1 ;
if ( V_1 -> V_178 )
V_175 = F_69 ( V_1 ) ;
else
V_175 = F_73 ( V_1 ) ;
if ( V_175 < 0 )
return V_175 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_170 ; V_9 ++ ) {
struct V_25 * V_26 = V_1 -> V_35 + V_9 ;
V_26 -> V_29 = F_82 ( V_9 ) + V_53 ;
#if F_83 ( V_193 ) || F_83 ( V_194 )
V_26 -> V_195 = V_1 -> V_196 + 0x400 + F_82 ( V_9 ) ;
V_26 -> V_197 = V_1 -> V_198 + 0x400 + F_82 ( V_9 ) ;
V_26 -> V_199 =
V_1 -> V_200 + 0x400 + F_82 ( V_9 ) ;
if ( V_9 == 0 )
V_26 -> V_201 = V_53 - 0x400 + V_202 ;
else
V_26 -> V_201 = V_53 + 0x400 + ( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
#endif
V_26 -> V_34 = F_84 ( V_9 , 0 ) + V_53 ;
V_26 -> V_203 = F_85 ( V_9 , V_53 ) ;
V_26 -> V_204 = 1 ;
V_26 -> V_205 = 1 ;
if ( V_26 -> V_146 ) {
F_12 ( V_1 -> V_30 ,
L_60 ,
V_164 , V_9 ,
V_26 -> V_151 ? L_61 : L_62 ,
V_26 -> V_145
? L_63 : L_55 ,
V_26 -> V_146 ) ;
}
if ( V_26 -> V_149 && ! V_26 -> V_151 ) {
F_12 ( V_1 -> V_30 ,
L_60 ,
V_164 , V_9 ,
L_64 ,
V_26 -> V_148
? L_63 : L_55 ,
V_26 -> V_149 ) ;
}
if ( ! ( V_26 -> V_146 || V_26 -> V_149 ) )
F_12 ( V_1 -> V_30 , L_65 , V_9 ) ;
}
return 0 ;
}
T_5 F_86 ( struct V_1 * V_1 )
{
T_5 V_206 = V_66 ;
T_3 V_62 ;
int V_207 ;
T_1 V_54 ;
V_62 = F_5 ( V_1 -> V_36 , V_84 ) ;
F_12 ( V_1 -> V_30 , L_66 ,
( V_62 & V_69 ) ? L_13 : L_14 ,
V_1 -> V_61 , V_1 -> V_208 , V_1 -> V_209 ) ;
if ( V_1 -> V_61 )
V_206 |= F_33 ( V_1 , V_1 -> V_61 ,
V_62 ) ;
if ( V_1 -> V_208 & 1 ) {
if ( V_62 & V_69 )
V_206 |= F_87 ( V_1 ) ;
else
V_206 |= F_88 ( V_1 ) ;
}
V_54 = V_1 -> V_209 >> 1 ;
V_207 = 1 ;
while ( V_54 ) {
if ( V_54 & 1 ) {
V_206 = V_68 ;
if ( V_62 & V_69 )
F_89 ( V_1 , V_207 ) ;
else
F_90 ( V_1 , V_207 ) ;
}
V_54 >>= 1 ;
V_207 ++ ;
}
V_54 = V_1 -> V_208 >> 1 ;
V_207 = 1 ;
while ( V_54 ) {
if ( V_54 & 1 ) {
V_206 = V_68 ;
if ( V_62 & V_69 )
F_91 ( V_1 , V_207 ) ;
else
F_92 ( V_1 , V_207 ) ;
}
V_54 >>= 1 ;
V_207 ++ ;
}
return V_206 ;
}
void F_93 ( struct V_1 * V_1 , T_3 V_31 , T_3 V_210 )
{
T_3 V_62 = F_5 ( V_1 -> V_36 , V_84 ) ;
if ( ! V_31 ) {
#ifndef F_94
if ( ! F_95 () ) {
if ( V_62 & V_69 )
F_87 ( V_1 ) ;
else
F_88 ( V_1 ) ;
}
#endif
} else {
if ( V_210 ) {
if ( V_62 & V_69 )
F_91 ( V_1 , V_31 ) ;
else
F_92 ( V_1 , V_31 ) ;
} else {
if ( V_62 & V_69 )
F_89 ( V_1 , V_31 ) ;
else
F_90 ( V_1 , V_31 ) ;
}
}
}
static T_6
F_96 ( struct V_2 * V_3 , struct V_211 * V_212 , char * V_213 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
int V_12 = - V_169 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
V_12 = sprintf ( V_213 , L_67 , F_28 ( V_1 -> V_43 -> V_44 ) ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return V_12 ;
}
static T_6
F_97 ( struct V_2 * V_3 , struct V_211 * V_212 ,
const char * V_213 , T_7 V_152 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
int V_175 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
if ( F_98 ( V_213 , L_13 ) )
V_175 = F_99 ( V_1 , V_214 ) ;
else if ( F_98 ( V_213 , L_14 ) )
V_175 = F_99 ( V_1 , V_215 ) ;
else if ( F_98 ( V_213 , L_68 ) )
V_175 = F_99 ( V_1 , V_216 ) ;
else
V_175 = - V_169 ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return ( V_175 == 0 ) ? V_152 : V_175 ;
}
static T_6
F_100 ( struct V_2 * V_3 , struct V_211 * V_212 ,
const char * V_213 , T_7 V_152 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
unsigned long V_217 ;
if ( sscanf ( V_213 , L_69 , & V_217 ) < 1 ) {
F_101 ( V_3 , L_70 ) ;
return - V_169 ;
}
F_26 ( & V_1 -> V_42 , V_41 ) ;
V_1 -> V_95 = V_217 ? F_102 ( int , V_217 , V_96 ) : 0 ;
if ( V_1 -> V_43 -> V_44 == V_49 )
V_1 -> V_47 = 0 ;
F_42 ( V_1 , V_75 + F_34 ( V_217 ) ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return V_152 ;
}
static T_6
F_103 ( struct V_2 * V_3 , struct V_211 * V_212 , char * V_213 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
unsigned long V_217 ;
int V_218 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
V_217 = V_1 -> V_95 ;
V_218 = F_104 ( V_1 ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return sprintf ( V_213 , L_71 ,
V_218 ? L_72 : L_73 , V_217 ) ;
}
static T_6
F_105 ( struct V_2 * V_3 , struct V_211 * V_212 ,
const char * V_213 , T_7 V_152 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_219 ;
if ( sscanf ( V_213 , L_74 , & V_219 ) != 1
|| ( V_219 != 1 ) ) {
F_101 ( V_3 , L_75 ) ;
return - V_169 ;
}
if ( V_219 == 1 )
F_106 ( V_1 ) ;
return V_152 ;
}
static void F_107 ( struct V_220 * V_24 )
{
struct V_1 * V_1 = F_108 ( V_24 , struct V_1 , V_117 ) ;
if ( V_1 -> V_43 -> V_44 != V_1 -> V_221 ) {
V_1 -> V_221 = V_1 -> V_43 -> V_44 ;
F_109 ( & V_1 -> V_30 -> V_222 , NULL , L_76 ) ;
}
}
static struct V_1 * F_110 ( struct V_2 * V_3 ,
struct V_223 * V_137 , void T_2 * V_53 )
{
struct V_1 * V_1 ;
struct V_25 * V_224 ;
int V_31 ;
int V_12 ;
V_1 = F_111 ( V_3 , sizeof( * V_1 ) , V_225 ) ;
if ( ! V_1 )
return NULL ;
F_112 ( & V_1 -> V_226 ) ;
F_112 ( & V_1 -> V_227 ) ;
F_112 ( & V_1 -> V_228 ) ;
V_1 -> V_92 = V_229 ;
V_1 -> V_95 = V_96 ;
V_1 -> V_36 = V_53 ;
V_1 -> V_230 = V_53 ;
V_1 -> V_231 = - V_232 ;
V_1 -> V_137 = V_137 ;
F_113 ( V_1 -> V_137 -> V_168 > V_233 ) ;
for ( V_31 = 0 , V_224 = V_1 -> V_35 ;
V_31 < V_1 -> V_137 -> V_168 ;
V_31 ++ , V_224 ++ ) {
V_224 -> V_1 = V_1 ;
V_224 -> V_31 = V_31 ;
}
V_1 -> V_30 = V_3 ;
V_12 = F_114 ( V_1 ) ;
if ( V_12 < 0 )
goto V_234;
F_115 ( V_3 , V_1 ) ;
return V_1 ;
V_234:
return NULL ;
}
static void F_116 ( struct V_1 * V_1 )
{
#ifdef F_117
F_118 ( & V_1 -> V_30 -> V_222 , & V_235 ) ;
#endif
if ( V_1 -> V_231 >= 0 ) {
if ( V_1 -> V_236 )
F_119 ( V_1 -> V_231 ) ;
F_120 ( V_1 -> V_231 , V_1 ) ;
}
F_121 ( V_1 ) ;
}
static void F_122 ( struct V_220 * V_237 )
{
struct V_1 * V_1 ;
unsigned long V_41 ;
V_1 = F_108 ( V_237 , struct V_1 , V_238 . V_237 ) ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
if ( V_1 -> V_59 & V_239 )
F_123 ( V_1 , false ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
}
static int
F_124 ( struct V_2 * V_3 , int V_231 , void T_2 * V_240 )
{
int V_175 ;
struct V_1 * V_1 ;
struct V_241 * V_242 = F_125 ( V_3 ) ;
if ( ! V_242 ) {
F_12 ( V_3 , L_77 ) ;
V_175 = - V_232 ;
goto V_243;
}
V_1 = F_110 ( V_3 , V_242 -> V_137 , V_240 ) ;
if ( ! V_1 ) {
V_175 = - V_244 ;
goto V_243;
}
F_126 ( V_1 -> V_30 ) ;
F_127 ( V_1 -> V_30 , 200 ) ;
F_128 ( V_1 -> V_30 ) ;
F_129 ( & V_1 -> V_42 ) ;
V_1 -> V_245 = V_242 -> V_246 ;
V_1 -> V_247 = V_242 -> V_247 ;
V_1 -> V_248 = V_242 -> V_249 ;
V_1 -> V_125 = V_242 -> V_135 ;
V_175 = F_130 ( V_1 ) ;
if ( V_175 < 0 )
goto V_250;
if ( ! V_1 -> V_251 ) {
V_175 = - V_232 ;
goto V_252;
}
if ( ! V_1 -> V_43 -> V_253 ) {
V_1 -> V_43 -> V_13 = V_1 -> V_30 ;
V_1 -> V_43 -> V_8 = V_1 -> V_36 ;
V_1 -> V_43 -> V_253 = & V_254 ;
}
F_4 ( V_1 -> V_30 ) ;
if ( V_255 && V_3 -> V_256 ) {
V_1 -> V_257 = F_131 ( V_1 , V_1 -> V_36 ) ;
if ( F_132 ( V_1 -> V_257 ) ) {
V_175 = F_133 ( V_1 -> V_257 ) ;
goto V_258;
}
}
F_57 ( V_1 ) ;
F_53 ( V_1 ) ;
F_134 ( & V_1 -> V_117 , F_107 ) ;
F_135 ( & V_1 -> V_238 , F_122 ) ;
F_135 ( & V_1 -> V_76 , V_259 ) ;
V_175 = F_75 ( V_242 -> V_137 -> V_260
? V_188
: V_261 , V_1 ) ;
if ( V_175 < 0 )
goto V_262;
F_136 ( & V_1 -> V_99 , F_25 , ( unsigned long ) V_1 ) ;
if ( F_137 ( V_231 , V_1 -> V_251 , 0 , F_138 ( V_3 ) , V_1 ) ) {
F_101 ( V_3 , L_78 , V_231 ) ;
V_175 = - V_232 ;
goto V_262;
}
V_1 -> V_231 = V_231 ;
if ( F_139 ( V_231 ) == 0 ) {
V_1 -> V_236 = 1 ;
F_140 ( V_3 , 1 ) ;
} else {
V_1 -> V_236 = 0 ;
}
if ( V_242 -> V_263 ) {
T_3 V_264 = F_141 ( V_1 -> V_36 ) ;
V_264 |= V_265 ;
F_142 ( V_1 -> V_36 , V_264 ) ;
}
if ( V_1 -> V_43 -> V_64 -> V_266 ) {
F_39 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_88 ;
} else {
F_32 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_81 ;
}
switch ( V_1 -> V_125 ) {
case V_126 :
V_175 = F_143 ( V_1 , V_242 -> V_11 ) ;
if ( V_175 < 0 )
goto V_262;
V_175 = F_99 ( V_1 , V_214 ) ;
break;
case V_267 :
V_175 = F_144 ( V_1 ) ;
if ( V_175 < 0 )
goto V_262;
V_175 = F_99 ( V_1 , V_215 ) ;
break;
case V_268 :
V_175 = F_143 ( V_1 , V_242 -> V_11 ) ;
if ( V_175 < 0 )
goto V_262;
V_175 = F_144 ( V_1 ) ;
if ( V_175 ) {
F_59 ( V_1 ) ;
goto V_262;
}
V_175 = F_99 ( V_1 , V_216 ) ;
break;
default:
F_101 ( V_3 , L_79 , V_1 -> V_125 ) ;
break;
}
if ( V_175 < 0 )
goto V_262;
V_175 = F_145 ( V_1 ) ;
if ( V_175 < 0 )
goto V_269;
V_175 = F_146 ( & V_1 -> V_30 -> V_222 , & V_235 ) ;
if ( V_175 )
goto V_270;
F_7 ( V_1 -> V_30 ) ;
return 0 ;
V_270:
F_147 ( V_1 ) ;
V_269:
F_60 ( V_1 ) ;
F_59 ( V_1 ) ;
V_262:
F_148 ( & V_1 -> V_117 ) ;
F_149 ( & V_1 -> V_76 ) ;
F_149 ( & V_1 -> V_238 ) ;
if ( V_1 -> V_257 )
F_150 ( V_1 -> V_257 ) ;
V_258:
F_151 ( V_1 -> V_30 ) ;
V_252:
if ( V_1 -> V_236 )
F_140 ( V_3 , 0 ) ;
F_61 ( V_1 ) ;
V_250:
F_152 ( V_1 -> V_30 ) ;
F_101 ( V_1 -> V_30 ,
L_80 , V_175 ) ;
F_116 ( V_1 ) ;
V_243:
return V_175 ;
}
static int F_153 ( struct V_127 * V_128 )
{
struct V_2 * V_3 = & V_128 -> V_3 ;
int V_271 = F_154 ( V_128 , L_81 ) ;
struct V_272 * V_273 ;
void T_2 * V_274 ;
V_273 = F_155 ( V_128 , V_275 , 0 ) ;
if ( ! V_273 || V_271 <= 0 )
return - V_232 ;
V_274 = F_156 ( V_3 , V_273 ) ;
if ( F_132 ( V_274 ) )
return F_133 ( V_274 ) ;
return F_124 ( V_3 , V_271 , V_274 ) ;
}
static int F_157 ( struct V_127 * V_128 )
{
struct V_2 * V_3 = & V_128 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_147 ( V_1 ) ;
F_58 ( V_128 ) ;
if ( V_1 -> V_257 )
F_150 ( V_1 -> V_257 ) ;
F_148 ( & V_1 -> V_117 ) ;
F_149 ( & V_1 -> V_76 ) ;
F_149 ( & V_1 -> V_238 ) ;
F_116 ( V_1 ) ;
F_140 ( V_3 , 0 ) ;
return 0 ;
}
static void F_158 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_276 = V_1 -> V_36 ;
void T_2 * V_277 ;
V_1 -> V_278 . V_279 = F_20 ( V_276 , V_280 ) ;
V_1 -> V_278 . V_281 = F_5 ( V_276 , V_122 ) ;
V_1 -> V_278 . V_264 = F_141 ( V_1 -> V_36 ) ;
V_1 -> V_278 . V_11 = F_5 ( V_276 , V_14 ) ;
V_1 -> V_278 . V_282 = F_5 ( V_276 , V_108 ) ;
V_1 -> V_278 . V_32 = F_5 ( V_276 , V_141 ) ;
V_1 -> V_278 . V_62 = F_5 ( V_276 , V_84 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_137 -> V_168 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_277 = V_26 -> V_34 ;
if ( ! V_277 )
continue;
F_6 ( V_276 , V_141 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_284 =
F_20 ( V_277 , V_285 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_286 =
F_20 ( V_277 , V_287 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_288 =
F_20 ( V_277 , V_289 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_290 =
F_20 ( V_277 , V_291 ) ;
if ( V_1 -> V_178 ) {
V_1 -> V_278 . V_283 [ V_9 ] . V_292 =
F_159 ( V_276 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_293 =
F_160 ( V_276 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_294 =
F_161 ( V_276 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_295 =
F_162 ( V_276 ) ;
}
V_1 -> V_278 . V_283 [ V_9 ] . V_296 =
F_5 ( V_277 , V_297 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_298 =
F_5 ( V_277 , V_299 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_300 =
F_5 ( V_277 , V_301 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_302 =
F_5 ( V_277 , V_303 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_304 =
F_163 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_305 =
F_164 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_306 =
F_165 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_307 =
F_166 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_308 =
F_167 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_309 =
F_168 ( V_276 , V_9 ) ;
}
}
static void F_169 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_276 = V_1 -> V_36 ;
void T_2 * V_310 ;
void T_2 * V_277 ;
T_3 V_11 ;
F_15 ( V_276 , V_280 , V_1 -> V_278 . V_279 ) ;
F_6 ( V_276 , V_122 , V_1 -> V_278 . V_281 ) ;
F_142 ( V_1 -> V_36 , V_1 -> V_278 . V_264 ) ;
V_11 = F_5 ( V_276 , V_14 ) ;
V_11 &= V_15 | V_71 ;
V_1 -> V_278 . V_11 &= ~ ( V_15 | V_71 ) ;
V_11 |= V_1 -> V_278 . V_11 ;
F_6 ( V_276 , V_14 , V_11 ) ;
F_15 ( V_276 , V_105 , V_1 -> V_103 ) ;
F_15 ( V_276 , V_107 , V_1 -> V_106 ) ;
F_6 ( V_276 , V_108 , V_1 -> V_278 . V_282 ) ;
F_6 ( V_276 , V_84 , V_1 -> V_278 . V_62 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_137 -> V_168 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_277 = V_26 -> V_34 ;
if ( ! V_277 )
continue;
F_6 ( V_276 , V_141 , V_9 ) ;
F_15 ( V_277 , V_285 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_284 ) ;
F_15 ( V_277 , V_287 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_286 ) ;
F_15 ( V_277 , V_289 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_288 ) ;
F_15 ( V_277 , V_291 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_290 ) ;
if ( V_1 -> V_178 ) {
F_65 ( V_276 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_294 ) ;
F_67 ( V_276 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_295 ) ;
F_66 ( V_276 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_292 ) ;
F_68 ( V_276 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_293 ) ;
}
F_6 ( V_277 , V_297 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_296 ) ;
F_6 ( V_277 , V_299 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_298 ) ;
F_6 ( V_277 , V_301 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_300 ) ;
F_6 ( V_277 , V_303 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_302 ) ;
F_170 ( V_276 , V_9 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_304 ) ;
F_171 ( V_276 , V_9 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_305 ) ;
F_172 ( V_276 , V_9 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_306 ) ;
V_310 =
F_85 ( V_9 , V_276 ) ;
F_173 ( V_310 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_307 ) ;
F_174 ( V_310 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_308 ) ;
F_175 ( V_310 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_309 ) ;
}
F_6 ( V_276 , V_141 , V_1 -> V_278 . V_32 ) ;
}
static int F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
if ( F_45 ( V_1 ) ) {
} else if ( F_177 ( V_1 ) ) {
}
F_158 ( V_1 ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_169 ( V_1 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_158 ( V_1 ) ;
return 0 ;
}
static int F_180 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_311 = 1 ;
if ( ! V_311 )
F_169 ( V_1 ) ;
V_311 = 0 ;
return 0 ;
}
