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
V_1 -> V_43 -> V_44 = V_76 ;
V_1 -> V_47 = 1 ;
F_35 ( V_1 ) ;
break;
case V_45 :
V_1 -> V_43 -> V_44 = V_46 ;
V_1 -> V_47 = 1 ;
F_32 ( V_1 ) ;
break;
default:
F_36 ( L_12 ,
L_13 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
} else {
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
V_1 -> V_43 -> V_44 = V_76 ;
F_35 ( V_1 ) ;
break;
case V_45 :
case V_46 :
if ( ( V_62 & V_77 )
!= ( 3 << V_78 )
) {
V_1 -> V_61 |= V_79 ;
V_1 -> V_61 &= ~ V_70 ;
break;
}
F_37 ( V_1 ) ;
break;
case V_80 :
V_1 -> V_61 &= ~ V_70 ;
break;
default:
F_36 ( L_12 ,
L_14 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
}
}
if ( V_61 & V_81 ) {
void T_2 * V_53 = V_1 -> V_36 ;
if ( ( V_62 & V_77 ) == V_77
&& ( V_62 & V_82 ) ) {
F_12 ( V_1 -> V_30 , L_15 ) ;
return V_68 ;
}
F_12 ( V_1 -> V_30 , L_16 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
F_6 ( V_53 , V_83 , V_84 ) ;
V_1 -> V_85 = V_86 ;
V_1 -> V_43 -> V_44 = V_87 ;
F_38 ( V_1 ) ;
F_29 ( V_1 , 1 ) ;
V_65 = V_68 ;
}
if ( V_61 & V_88 ) {
int V_89 = 0 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_76 :
case V_49 :
case V_90 :
if ( V_1 -> V_91 ) {
void T_2 * V_53 = V_1 -> V_36 ;
V_1 -> V_91 -- ;
V_89 = 1 ;
V_62 |= V_84 ;
F_6 ( V_53 , V_83 , V_62 ) ;
} else {
V_1 -> V_59 |=
V_92
| ( V_93 << 16 ) ;
}
break;
default:
break;
}
F_39 (ignore ? KERN_DEBUG : KERN_ERR, musb->controller,
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
if ( ! V_89 )
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
F_35 ( V_1 ) ;
F_40 ( V_1 ) ;
F_41 ( V_1 , V_75
+ F_34 ( V_1 -> V_94
? : V_95 ) ) ;
break;
case V_80 :
if ( ! V_1 -> V_47 )
break;
case V_46 :
F_42 ( V_1 ) ;
V_1 -> V_47 = V_64 -> V_96 -> V_97 ;
if ( V_1 -> V_47 ) {
V_1 -> V_43 -> V_44 = V_45 ;
F_12 ( V_1 -> V_30 , L_23 ) ;
F_43 ( & V_1 -> V_98 , V_75
+ F_34 (
V_99 ) ) ;
}
break;
case V_49 :
if ( V_1 -> V_94 != 0 )
F_41 ( V_1 , V_75
+ F_34 ( V_1 -> V_94 ) ) ;
break;
case V_76 :
V_1 -> V_43 -> V_44 = V_48 ;
V_1 -> V_47 = V_64 -> V_100 -> V_97 ;
break;
case V_56 :
F_12 ( V_1 -> V_30 , L_24 ) ;
break;
default:
V_1 -> V_47 = 0 ;
break;
}
}
if ( V_61 & V_101 ) {
struct V_51 * V_52 = V_1 -> V_52 ;
V_65 = V_68 ;
V_1 -> V_47 = 1 ;
V_1 -> V_85 = V_86 ;
if ( F_44 ( V_1 ) ) {
}
V_1 -> V_102 = V_1 -> V_103 ;
F_15 ( V_1 -> V_36 , V_104 , V_1 -> V_102 ) ;
V_1 -> V_105 = V_1 -> V_103 & 0xfffe ;
F_15 ( V_1 -> V_36 , V_106 , V_1 -> V_105 ) ;
F_6 ( V_1 -> V_36 , V_107 , 0xf7 ) ;
V_1 -> V_59 &= ~ ( V_108
| V_109
| V_110
) ;
V_1 -> V_59 |= V_111
| ( V_60 << 16 ) ;
if ( V_62 & V_112 )
V_1 -> V_59 |= V_108 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_46 :
if ( V_61 & V_70 ) {
F_12 ( V_1 -> V_30 , L_25 ) ;
V_61 &= ~ V_70 ;
goto V_113;
} else
F_12 ( V_1 -> V_30 , L_26 ) ;
break;
case V_45 :
F_12 ( V_1 -> V_30 , L_27 ) ;
V_113:
V_1 -> V_43 -> V_44 = V_56 ;
if ( V_1 -> V_52 )
V_1 -> V_52 -> V_57 . V_58 = 1 ;
F_45 ( & V_1 -> V_98 ) ;
break;
default:
if ( ( V_62 & V_77 )
== ( 3 << V_78 ) ) {
V_1 -> V_43 -> V_44 = V_76 ;
if ( V_52 )
V_52 -> V_57 . V_58 = 0 ;
}
break;
}
F_46 ( V_1 ) ;
F_12 ( V_1 -> V_30 , L_28 ,
F_28 ( V_1 -> V_43 -> V_44 ) , V_62 ) ;
}
if ( V_61 & V_79 ) {
F_12 ( V_1 -> V_30 , L_29 ,
F_28 ( V_1 -> V_43 -> V_44 ) ,
F_47 ( V_1 ) , V_62 ) ;
V_65 = V_68 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_76 :
case V_48 :
F_35 ( V_1 ) ;
F_40 ( V_1 ) ;
if ( V_1 -> V_94 != 0 )
F_41 ( V_1 , V_75
+ F_34 ( V_1 -> V_94 ) ) ;
break;
case V_56 :
F_40 ( V_1 ) ;
if ( V_1 -> V_52 )
V_1 -> V_52 -> V_57 . V_58 = 0 ;
V_1 -> V_43 -> V_44 = V_46 ;
F_32 ( V_1 ) ;
F_27 ( V_1 ) ;
break;
case V_55 :
F_31 ( V_1 ) ;
F_40 ( V_1 ) ;
case V_45 :
case V_46 :
case V_80 :
F_27 ( V_1 ) ;
break;
default:
F_36 ( L_30 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
break;
}
}
if ( V_61 & V_114 ) {
V_65 = V_68 ;
if ( ( V_62 & V_69 ) != 0 ) {
if ( V_62 & ( V_115 | V_112 ) )
F_12 ( V_1 -> V_30 , L_31 , V_62 ) ;
else {
F_48 ( L_32 ) ;
F_6 ( V_1 -> V_36 , V_83 , 0 ) ;
}
} else {
F_12 ( V_1 -> V_30 , L_33 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
F_49 ( V_1 ) ;
case V_49 :
F_12 ( V_1 -> V_30 , L_34 ,
F_28 ( V_1 -> V_43 -> V_44 ) ,
F_50 ( V_1 ) ) ;
F_43 ( & V_1 -> V_98 , V_75
+ F_34 ( F_50 ( V_1 ) ) ) ;
break;
case V_55 :
F_45 ( & V_1 -> V_98 ) ;
F_49 ( V_1 ) ;
break;
case V_45 :
F_12 ( V_1 -> V_30 , L_35 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
V_1 -> V_43 -> V_44 = V_46 ;
F_49 ( V_1 ) ;
break;
case V_80 :
V_1 -> V_43 -> V_44 = V_46 ;
case V_46 :
F_49 ( V_1 ) ;
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
F_51 ( & V_1 -> V_116 ) ;
return V_65 ;
}
static void F_52 ( struct V_1 * V_1 )
{
void T_2 * V_53 = V_1 -> V_36 ;
T_4 V_117 ;
F_6 ( V_53 , V_107 , 0 ) ;
V_1 -> V_102 = 0 ;
F_15 ( V_53 , V_104 , 0 ) ;
V_1 -> V_105 = 0 ;
F_15 ( V_53 , V_106 , 0 ) ;
F_6 ( V_53 , V_83 , 0 ) ;
V_117 = F_5 ( V_53 , V_118 ) ;
V_117 = F_20 ( V_53 , V_119 ) ;
V_117 = F_20 ( V_53 , V_120 ) ;
}
void F_53 ( struct V_1 * V_1 )
{
void T_2 * V_34 = V_1 -> V_36 ;
T_3 V_62 = F_5 ( V_34 , V_83 ) ;
F_12 ( V_1 -> V_30 , L_37 , V_62 ) ;
V_1 -> V_102 = V_1 -> V_103 ;
F_15 ( V_34 , V_104 , V_1 -> V_102 ) ;
V_1 -> V_105 = V_1 -> V_103 & 0xfffe ;
F_15 ( V_34 , V_106 , V_1 -> V_105 ) ;
F_6 ( V_34 , V_107 , 0xf7 ) ;
F_6 ( V_34 , V_121 , 0 ) ;
F_6 ( V_34 , V_14 , V_122
| V_123
) ;
V_1 -> V_47 = 0 ;
V_62 = F_5 ( V_34 , V_83 ) ;
V_62 &= ~ V_84 ;
if ( V_1 -> V_124 != V_125 &&
( V_62 & V_77 ) == V_77 ) {
V_1 -> V_47 = 1 ;
} else {
V_62 |= V_84 ;
}
F_54 ( V_1 ) ;
F_6 ( V_34 , V_83 , V_62 ) ;
}
void F_55 ( struct V_1 * V_1 )
{
F_56 ( V_1 ) ;
F_52 ( V_1 ) ;
F_12 ( V_1 -> V_30 , L_38 ) ;
F_41 ( V_1 , 0 ) ;
}
static void F_57 ( struct V_126 * V_127 )
{
struct V_1 * V_1 = F_1 ( & V_127 -> V_3 ) ;
unsigned long V_41 ;
F_4 ( V_1 -> V_30 ) ;
F_58 ( V_1 ) ;
F_59 ( V_1 ) ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
F_56 ( V_1 ) ;
F_52 ( V_1 ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
F_6 ( V_1 -> V_36 , V_83 , 0 ) ;
F_60 ( V_1 ) ;
F_7 ( V_1 -> V_30 ) ;
}
static int
F_61 ( struct V_1 * V_1 , struct V_25 * V_26 ,
const struct V_128 * V_129 , T_4 V_6 )
{
void T_2 * V_53 = V_1 -> V_36 ;
int V_130 = 0 ;
T_4 V_131 = V_129 -> V_131 ;
T_4 V_132 = V_6 >> 3 ;
T_3 V_133 ;
V_130 = F_62 ( F_63 ( V_131 , ( T_4 ) 8 ) ) - 1 ;
V_131 = 1 << V_130 ;
V_133 = V_130 - 3 ;
if ( V_129 -> V_134 == V_135 ) {
if ( ( V_6 + ( V_131 << 1 ) ) >
( 1 << ( V_1 -> V_136 -> V_137 + 2 ) ) )
return - V_138 ;
V_133 |= V_139 ;
} else {
if ( ( V_6 + V_131 ) > ( 1 << ( V_1 -> V_136 -> V_137 + 2 ) ) )
return - V_138 ;
}
F_6 ( V_53 , V_140 , V_26 -> V_31 ) ;
if ( V_26 -> V_31 == 1 )
V_1 -> V_141 = V_26 ;
switch ( V_129 -> V_142 ) {
case V_143 :
F_64 ( V_53 , V_133 ) ;
F_65 ( V_53 , V_132 ) ;
V_26 -> V_144 = ! ! ( V_133 & V_139 ) ;
V_26 -> V_145 = V_131 ;
break;
case V_146 :
F_66 ( V_53 , V_133 ) ;
F_67 ( V_53 , V_132 ) ;
V_26 -> V_147 = ! ! ( V_133 & V_139 ) ;
V_26 -> V_148 = V_131 ;
break;
case V_149 :
F_64 ( V_53 , V_133 ) ;
F_65 ( V_53 , V_132 ) ;
V_26 -> V_147 = ! ! ( V_133 & V_139 ) ;
V_26 -> V_148 = V_131 ;
F_66 ( V_53 , V_133 ) ;
F_67 ( V_53 , V_132 ) ;
V_26 -> V_144 = V_26 -> V_147 ;
V_26 -> V_145 = V_131 ;
V_26 -> V_150 = true ;
break;
}
V_1 -> V_103 |= ( 1 << V_26 -> V_31 ) ;
return V_6 + ( V_131 << ( ( V_133 & V_139 ) ? 1 : 0 ) ) ;
}
static int F_68 ( struct V_1 * V_1 )
{
const struct V_128 * V_129 ;
unsigned V_9 , V_151 ;
int V_6 ;
struct V_25 * V_26 = V_1 -> V_35 ;
if ( V_1 -> V_136 -> V_152 ) {
V_129 = V_1 -> V_136 -> V_152 ;
V_151 = V_1 -> V_136 -> V_153 ;
goto V_154;
}
switch ( V_155 ) {
default:
V_155 = 0 ;
case 0 :
V_129 = V_156 ;
V_151 = F_69 ( V_156 ) ;
break;
case 1 :
V_129 = V_157 ;
V_151 = F_69 ( V_157 ) ;
break;
case 2 :
V_129 = V_158 ;
V_151 = F_69 ( V_158 ) ;
break;
case 3 :
V_129 = V_159 ;
V_151 = F_69 ( V_159 ) ;
break;
case 4 :
V_129 = V_160 ;
V_151 = F_69 ( V_160 ) ;
break;
case 5 :
V_129 = V_161 ;
V_151 = F_69 ( V_161 ) ;
break;
}
F_70 ( V_162 L_39 ,
V_163 , V_155 ) ;
V_154:
V_6 = F_61 ( V_1 , V_26 , & V_164 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_151 ; V_9 ++ ) {
T_3 V_165 = V_129 -> V_166 ;
if ( V_165 >= V_1 -> V_136 -> V_167 ) {
F_71 ( L_40 ,
V_163 , V_165 ) ;
return - V_168 ;
}
V_6 = F_61 ( V_1 , V_26 + V_165 , V_129 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_71 ( L_41 ,
V_163 , V_165 ) ;
return V_6 ;
}
V_165 ++ ;
V_1 -> V_169 = F_63 ( V_165 , V_1 -> V_169 ) ;
}
F_70 ( V_162 L_42 ,
V_163 ,
V_151 + 1 , V_1 -> V_136 -> V_167 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_136 -> V_137 + 2 ) ) ) ;
if ( ! V_1 -> V_141 ) {
F_71 ( L_43 , V_163 ) ;
return - V_168 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_1 )
{
T_3 V_31 = 0 ;
struct V_25 * V_26 ;
void T_2 * V_53 = V_1 -> V_36 ;
int V_12 = 0 ;
F_12 ( V_1 -> V_30 , L_44 ) ;
for ( V_31 = 1 ; V_31 < V_1 -> V_136 -> V_167 ; V_31 ++ ) {
F_24 ( V_53 , V_31 ) ;
V_26 = V_1 -> V_35 + V_31 ;
V_12 = F_73 ( V_1 , V_26 , V_31 ) ;
if ( V_12 < 0 )
break;
if ( V_26 -> V_145 < 512
|| V_26 -> V_148 < 512 )
continue;
if ( V_1 -> V_141 )
continue;
V_1 -> V_141 = V_26 ;
}
if ( ! V_1 -> V_141 ) {
F_71 ( L_43 , V_163 ) ;
return - V_168 ;
}
return 0 ;
}
static int F_74 ( T_4 V_170 , struct V_1 * V_1 )
{
T_3 V_54 ;
char * type ;
char V_171 [ 90 ] , V_172 [ 32 ] , V_173 [ 12 ] ;
void T_2 * V_53 = V_1 -> V_36 ;
int V_174 = 0 ;
int V_9 ;
V_54 = F_75 ( V_53 ) ;
strcpy ( V_171 , ( V_54 & V_175 ) ? L_45 : L_46 ) ;
if ( V_54 & V_176 ) {
strcat ( V_171 , L_47 ) ;
V_1 -> V_177 = true ;
}
if ( V_54 & V_178 ) {
strcat ( V_171 , L_48 ) ;
V_1 -> V_179 = true ;
}
if ( V_54 & V_180 ) {
strcat ( V_171 , L_49 ) ;
V_1 -> V_181 = true ;
}
if ( V_54 & V_182 ) {
strcat ( V_171 , L_50 ) ;
V_1 -> V_183 = true ;
}
if ( V_54 & V_184 ) {
strcat ( V_171 , L_51 ) ;
V_1 -> V_185 = true ;
}
if ( V_54 & V_186 )
strcat ( V_171 , L_52 ) ;
F_70 ( V_162 L_53 ,
V_163 , V_54 , V_171 ) ;
V_173 [ 0 ] = 0 ;
if ( V_187 == V_170 ) {
V_1 -> V_188 = 1 ;
type = L_54 ;
} else {
V_1 -> V_188 = 0 ;
type = L_55 ;
#ifndef F_76
F_70 ( V_189
L_56 ,
V_163 ) ;
#endif
}
V_1 -> V_190 = F_77 ( V_53 ) ;
snprintf ( V_172 , 32 , L_57 , F_78 ( V_1 -> V_190 ) ,
F_79 ( V_1 -> V_190 ) ,
( V_1 -> V_190 & V_191 ) ? L_58 : L_55 ) ;
F_70 ( V_162 L_59 ,
V_163 , type , V_172 , V_173 ) ;
F_80 ( V_1 ) ;
V_1 -> V_169 = 1 ;
V_1 -> V_103 = 1 ;
if ( V_1 -> V_177 )
V_174 = F_68 ( V_1 ) ;
else
V_174 = F_72 ( V_1 ) ;
if ( V_174 < 0 )
return V_174 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_169 ; V_9 ++ ) {
struct V_25 * V_26 = V_1 -> V_35 + V_9 ;
V_26 -> V_29 = F_81 ( V_9 ) + V_53 ;
#if F_82 ( V_192 ) || F_82 ( V_193 )
V_26 -> V_194 = V_1 -> V_195 + 0x400 + F_81 ( V_9 ) ;
V_26 -> V_196 = V_1 -> V_197 + 0x400 + F_81 ( V_9 ) ;
V_26 -> V_198 =
V_1 -> V_199 + 0x400 + F_81 ( V_9 ) ;
if ( V_9 == 0 )
V_26 -> V_200 = V_53 - 0x400 + V_201 ;
else
V_26 -> V_200 = V_53 + 0x400 + ( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
#endif
V_26 -> V_34 = F_83 ( V_9 , 0 ) + V_53 ;
V_26 -> V_202 = F_84 ( V_9 , V_53 ) ;
V_26 -> V_203 = 1 ;
V_26 -> V_204 = 1 ;
if ( V_26 -> V_145 ) {
F_12 ( V_1 -> V_30 ,
L_60 ,
V_163 , V_9 ,
V_26 -> V_150 ? L_61 : L_62 ,
V_26 -> V_144
? L_63 : L_55 ,
V_26 -> V_145 ) ;
}
if ( V_26 -> V_148 && ! V_26 -> V_150 ) {
F_12 ( V_1 -> V_30 ,
L_60 ,
V_163 , V_9 ,
L_64 ,
V_26 -> V_147
? L_63 : L_55 ,
V_26 -> V_148 ) ;
}
if ( ! ( V_26 -> V_145 || V_26 -> V_148 ) )
F_12 ( V_1 -> V_30 , L_65 , V_9 ) ;
}
return 0 ;
}
T_5 F_85 ( struct V_1 * V_1 )
{
T_5 V_205 = V_66 ;
T_3 V_62 ;
int V_206 ;
T_1 V_54 ;
V_62 = F_5 ( V_1 -> V_36 , V_83 ) ;
F_12 ( V_1 -> V_30 , L_66 ,
( V_62 & V_69 ) ? L_13 : L_14 ,
V_1 -> V_61 , V_1 -> V_207 , V_1 -> V_208 ) ;
if ( V_1 -> V_61 )
V_205 |= F_33 ( V_1 , V_1 -> V_61 ,
V_62 ) ;
if ( V_1 -> V_207 & 1 ) {
if ( V_62 & V_69 )
V_205 |= F_86 ( V_1 ) ;
else
V_205 |= F_87 ( V_1 ) ;
}
V_54 = V_1 -> V_208 >> 1 ;
V_206 = 1 ;
while ( V_54 ) {
if ( V_54 & 1 ) {
V_205 = V_68 ;
if ( V_62 & V_69 )
F_88 ( V_1 , V_206 ) ;
else
F_89 ( V_1 , V_206 ) ;
}
V_54 >>= 1 ;
V_206 ++ ;
}
V_54 = V_1 -> V_207 >> 1 ;
V_206 = 1 ;
while ( V_54 ) {
if ( V_54 & 1 ) {
V_205 = V_68 ;
if ( V_62 & V_69 )
F_90 ( V_1 , V_206 ) ;
else
F_91 ( V_1 , V_206 ) ;
}
V_54 >>= 1 ;
V_206 ++ ;
}
return V_205 ;
}
void F_92 ( struct V_1 * V_1 , T_3 V_31 , T_3 V_209 )
{
T_3 V_62 = F_5 ( V_1 -> V_36 , V_83 ) ;
if ( ! V_31 ) {
#ifndef F_93
if ( ! F_94 () ) {
if ( V_62 & V_69 )
F_86 ( V_1 ) ;
else
F_87 ( V_1 ) ;
}
#endif
} else {
if ( V_209 ) {
if ( V_62 & V_69 )
F_90 ( V_1 , V_31 ) ;
else
F_91 ( V_1 , V_31 ) ;
} else {
if ( V_62 & V_69 )
F_88 ( V_1 , V_31 ) ;
else
F_89 ( V_1 , V_31 ) ;
}
}
}
static T_6
F_95 ( struct V_2 * V_3 , struct V_210 * V_211 , char * V_212 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
int V_12 = - V_168 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
V_12 = sprintf ( V_212 , L_67 , F_28 ( V_1 -> V_43 -> V_44 ) ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return V_12 ;
}
static T_6
F_96 ( struct V_2 * V_3 , struct V_210 * V_211 ,
const char * V_212 , T_7 V_151 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
int V_174 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
if ( F_97 ( V_212 , L_13 ) )
V_174 = F_98 ( V_1 , V_213 ) ;
else if ( F_97 ( V_212 , L_14 ) )
V_174 = F_98 ( V_1 , V_214 ) ;
else if ( F_97 ( V_212 , L_68 ) )
V_174 = F_98 ( V_1 , V_215 ) ;
else
V_174 = - V_168 ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return ( V_174 == 0 ) ? V_151 : V_174 ;
}
static T_6
F_99 ( struct V_2 * V_3 , struct V_210 * V_211 ,
const char * V_212 , T_7 V_151 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
unsigned long V_216 ;
if ( sscanf ( V_212 , L_69 , & V_216 ) < 1 ) {
F_100 ( V_3 , L_70 ) ;
return - V_168 ;
}
F_26 ( & V_1 -> V_42 , V_41 ) ;
V_1 -> V_94 = V_216 ? F_101 ( int , V_216 , V_95 ) : 0 ;
if ( V_1 -> V_43 -> V_44 == V_49 )
V_1 -> V_47 = 0 ;
F_41 ( V_1 , V_75 + F_34 ( V_216 ) ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return V_151 ;
}
static T_6
F_102 ( struct V_2 * V_3 , struct V_210 * V_211 , char * V_212 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
unsigned long V_216 ;
int V_217 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
V_216 = V_1 -> V_94 ;
V_217 = F_103 ( V_1 ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
return sprintf ( V_212 , L_71 ,
V_217 ? L_72 : L_73 , V_216 ) ;
}
static T_6
F_104 ( struct V_2 * V_3 , struct V_210 * V_211 ,
const char * V_212 , T_7 V_151 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_218 ;
if ( sscanf ( V_212 , L_74 , & V_218 ) != 1
|| ( V_218 != 1 ) ) {
F_100 ( V_3 , L_75 ) ;
return - V_168 ;
}
if ( V_218 == 1 )
F_105 ( V_1 ) ;
return V_151 ;
}
static void F_106 ( struct V_219 * V_24 )
{
struct V_1 * V_1 = F_107 ( V_24 , struct V_1 , V_116 ) ;
if ( V_1 -> V_43 -> V_44 != V_1 -> V_220 ) {
V_1 -> V_220 = V_1 -> V_43 -> V_44 ;
F_108 ( & V_1 -> V_30 -> V_221 , NULL , L_76 ) ;
}
}
static struct V_1 * F_109 ( struct V_2 * V_3 ,
struct V_222 * V_136 , void T_2 * V_53 )
{
struct V_1 * V_1 ;
struct V_25 * V_223 ;
int V_31 ;
int V_12 ;
V_1 = F_110 ( V_3 , sizeof( * V_1 ) , V_224 ) ;
if ( ! V_1 )
return NULL ;
F_111 ( & V_1 -> V_225 ) ;
F_111 ( & V_1 -> V_226 ) ;
F_111 ( & V_1 -> V_227 ) ;
V_1 -> V_91 = V_228 ;
V_1 -> V_94 = V_95 ;
V_1 -> V_36 = V_53 ;
V_1 -> V_229 = V_53 ;
V_1 -> V_230 = - V_231 ;
V_1 -> V_136 = V_136 ;
F_112 ( V_1 -> V_136 -> V_167 > V_232 ) ;
for ( V_31 = 0 , V_223 = V_1 -> V_35 ;
V_31 < V_1 -> V_136 -> V_167 ;
V_31 ++ , V_223 ++ ) {
V_223 -> V_1 = V_1 ;
V_223 -> V_31 = V_31 ;
}
V_1 -> V_30 = V_3 ;
V_12 = F_113 ( V_1 ) ;
if ( V_12 < 0 )
goto V_233;
F_114 ( V_3 , V_1 ) ;
return V_1 ;
V_233:
return NULL ;
}
static void F_115 ( struct V_1 * V_1 )
{
#ifdef F_116
F_117 ( & V_1 -> V_30 -> V_221 , & V_234 ) ;
#endif
if ( V_1 -> V_230 >= 0 ) {
if ( V_1 -> V_235 )
F_118 ( V_1 -> V_230 ) ;
F_119 ( V_1 -> V_230 , V_1 ) ;
}
F_120 ( V_1 ) ;
}
static int
F_121 ( struct V_2 * V_3 , int V_230 , void T_2 * V_236 )
{
int V_174 ;
struct V_1 * V_1 ;
struct V_237 * V_238 = F_122 ( V_3 ) ;
if ( ! V_238 ) {
F_12 ( V_3 , L_77 ) ;
V_174 = - V_231 ;
goto V_239;
}
V_1 = F_109 ( V_3 , V_238 -> V_136 , V_236 ) ;
if ( ! V_1 ) {
V_174 = - V_240 ;
goto V_239;
}
F_123 ( V_1 -> V_30 ) ;
F_124 ( V_1 -> V_30 , 200 ) ;
F_125 ( V_1 -> V_30 ) ;
F_126 ( & V_1 -> V_42 ) ;
V_1 -> V_241 = V_238 -> V_242 ;
V_1 -> V_243 = V_238 -> V_243 ;
V_1 -> V_244 = V_238 -> V_245 ;
V_1 -> V_124 = V_238 -> V_134 ;
V_174 = F_127 ( V_1 ) ;
if ( V_174 < 0 )
goto V_246;
if ( ! V_1 -> V_247 ) {
V_174 = - V_231 ;
goto V_248;
}
if ( ! V_1 -> V_43 -> V_249 ) {
V_1 -> V_43 -> V_13 = V_1 -> V_30 ;
V_1 -> V_43 -> V_8 = V_1 -> V_36 ;
V_1 -> V_43 -> V_249 = & V_250 ;
}
F_4 ( V_1 -> V_30 ) ;
if ( V_251 && V_3 -> V_252 ) {
V_1 -> V_253 = F_128 ( V_1 , V_1 -> V_36 ) ;
if ( F_129 ( V_1 -> V_253 ) ) {
V_174 = F_130 ( V_1 -> V_253 ) ;
goto V_254;
}
}
F_56 ( V_1 ) ;
F_52 ( V_1 ) ;
F_131 ( & V_1 -> V_116 , F_106 ) ;
V_174 = F_74 ( V_238 -> V_136 -> V_255
? V_187
: V_256 , V_1 ) ;
if ( V_174 < 0 )
goto V_257;
F_132 ( & V_1 -> V_98 , F_25 , ( unsigned long ) V_1 ) ;
if ( F_133 ( V_230 , V_1 -> V_247 , 0 , F_134 ( V_3 ) , V_1 ) ) {
F_100 ( V_3 , L_78 , V_230 ) ;
V_174 = - V_231 ;
goto V_257;
}
V_1 -> V_230 = V_230 ;
if ( F_135 ( V_230 ) == 0 ) {
V_1 -> V_235 = 1 ;
F_136 ( V_3 , 1 ) ;
} else {
V_1 -> V_235 = 0 ;
}
if ( V_238 -> V_258 ) {
T_3 V_259 = F_137 ( V_1 -> V_36 ) ;
V_259 |= V_260 ;
F_138 ( V_1 -> V_36 , V_259 ) ;
}
if ( V_1 -> V_43 -> V_64 -> V_261 ) {
F_38 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_87 ;
} else {
F_32 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_80 ;
}
switch ( V_1 -> V_124 ) {
case V_125 :
V_174 = F_139 ( V_1 , V_238 -> V_11 ) ;
break;
case V_262 :
V_174 = F_140 ( V_1 ) ;
break;
case V_263 :
V_174 = F_139 ( V_1 , V_238 -> V_11 ) ;
if ( V_174 < 0 )
goto V_257;
V_174 = F_140 ( V_1 ) ;
if ( V_174 )
F_58 ( V_1 ) ;
break;
default:
F_100 ( V_3 , L_79 , V_1 -> V_124 ) ;
break;
}
if ( V_174 < 0 )
goto V_257;
V_174 = F_141 ( V_1 ) ;
if ( V_174 < 0 )
goto V_264;
V_174 = F_142 ( & V_1 -> V_30 -> V_221 , & V_234 ) ;
if ( V_174 )
goto V_265;
F_7 ( V_1 -> V_30 ) ;
return 0 ;
V_265:
F_143 ( V_1 ) ;
V_264:
F_59 ( V_1 ) ;
F_58 ( V_1 ) ;
V_257:
F_144 ( & V_1 -> V_116 ) ;
if ( V_1 -> V_253 )
F_145 ( V_1 -> V_253 ) ;
V_254:
F_146 ( V_1 -> V_30 ) ;
V_248:
if ( V_1 -> V_235 )
F_136 ( V_3 , 0 ) ;
F_60 ( V_1 ) ;
V_246:
F_147 ( V_1 -> V_30 ) ;
F_100 ( V_1 -> V_30 ,
L_80 , V_174 ) ;
F_115 ( V_1 ) ;
V_239:
return V_174 ;
}
static int F_148 ( struct V_126 * V_127 )
{
struct V_2 * V_3 = & V_127 -> V_3 ;
int V_266 = F_149 ( V_127 , L_81 ) ;
struct V_267 * V_268 ;
void T_2 * V_269 ;
V_268 = F_150 ( V_127 , V_270 , 0 ) ;
if ( ! V_268 || V_266 <= 0 )
return - V_231 ;
V_269 = F_151 ( V_3 , V_268 ) ;
if ( F_129 ( V_269 ) )
return F_130 ( V_269 ) ;
return F_121 ( V_3 , V_266 , V_269 ) ;
}
static int F_152 ( struct V_126 * V_127 )
{
struct V_2 * V_3 = & V_127 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_143 ( V_1 ) ;
F_57 ( V_127 ) ;
if ( V_1 -> V_253 )
F_145 ( V_1 -> V_253 ) ;
F_144 ( & V_1 -> V_116 ) ;
F_115 ( V_1 ) ;
F_136 ( V_3 , 0 ) ;
return 0 ;
}
static void F_153 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_271 = V_1 -> V_36 ;
void T_2 * V_272 ;
V_1 -> V_273 . V_274 = F_20 ( V_271 , V_275 ) ;
V_1 -> V_273 . V_276 = F_5 ( V_271 , V_121 ) ;
V_1 -> V_273 . V_259 = F_137 ( V_1 -> V_36 ) ;
V_1 -> V_273 . V_11 = F_5 ( V_271 , V_14 ) ;
V_1 -> V_273 . V_277 = F_5 ( V_271 , V_107 ) ;
V_1 -> V_273 . V_32 = F_5 ( V_271 , V_140 ) ;
V_1 -> V_273 . V_62 = F_5 ( V_271 , V_83 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_136 -> V_167 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_272 = V_26 -> V_34 ;
if ( ! V_272 )
continue;
F_6 ( V_271 , V_140 , V_9 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_279 =
F_20 ( V_272 , V_280 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_281 =
F_20 ( V_272 , V_282 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_283 =
F_20 ( V_272 , V_284 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_285 =
F_20 ( V_272 , V_286 ) ;
if ( V_1 -> V_177 ) {
V_1 -> V_273 . V_278 [ V_9 ] . V_287 =
F_154 ( V_271 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_288 =
F_155 ( V_271 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_289 =
F_156 ( V_271 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_290 =
F_157 ( V_271 ) ;
}
V_1 -> V_273 . V_278 [ V_9 ] . V_291 =
F_5 ( V_272 , V_292 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_293 =
F_5 ( V_272 , V_294 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_295 =
F_5 ( V_272 , V_296 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_297 =
F_5 ( V_272 , V_298 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_299 =
F_158 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_300 =
F_159 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_301 =
F_160 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_302 =
F_161 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_303 =
F_162 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_278 [ V_9 ] . V_304 =
F_163 ( V_271 , V_9 ) ;
}
}
static void F_164 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_271 = V_1 -> V_36 ;
void T_2 * V_305 ;
void T_2 * V_272 ;
F_15 ( V_271 , V_275 , V_1 -> V_273 . V_274 ) ;
F_6 ( V_271 , V_121 , V_1 -> V_273 . V_276 ) ;
F_138 ( V_1 -> V_36 , V_1 -> V_273 . V_259 ) ;
F_6 ( V_271 , V_14 , V_1 -> V_273 . V_11 ) ;
F_15 ( V_271 , V_104 , V_1 -> V_102 ) ;
F_15 ( V_271 , V_106 , V_1 -> V_105 ) ;
F_6 ( V_271 , V_107 , V_1 -> V_273 . V_277 ) ;
F_6 ( V_271 , V_83 , V_1 -> V_273 . V_62 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_136 -> V_167 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_272 = V_26 -> V_34 ;
if ( ! V_272 )
continue;
F_6 ( V_271 , V_140 , V_9 ) ;
F_15 ( V_272 , V_280 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_279 ) ;
F_15 ( V_272 , V_282 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_281 ) ;
F_15 ( V_272 , V_284 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_283 ) ;
F_15 ( V_272 , V_286 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_285 ) ;
if ( V_1 -> V_177 ) {
F_64 ( V_271 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_289 ) ;
F_66 ( V_271 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_290 ) ;
F_65 ( V_271 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_287 ) ;
F_67 ( V_271 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_288 ) ;
}
F_6 ( V_272 , V_292 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_291 ) ;
F_6 ( V_272 , V_294 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_293 ) ;
F_6 ( V_272 , V_296 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_295 ) ;
F_6 ( V_272 , V_298 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_297 ) ;
F_165 ( V_271 , V_9 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_299 ) ;
F_166 ( V_271 , V_9 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_300 ) ;
F_167 ( V_271 , V_9 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_301 ) ;
V_305 =
F_84 ( V_9 , V_271 ) ;
F_168 ( V_305 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_302 ) ;
F_169 ( V_305 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_303 ) ;
F_170 ( V_305 ,
V_1 -> V_273 . V_278 [ V_9 ] . V_304 ) ;
}
F_6 ( V_271 , V_140 , V_1 -> V_273 . V_32 ) ;
}
static int F_171 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
if ( F_44 ( V_1 ) ) {
} else if ( F_172 ( V_1 ) ) {
}
F_30 ( & V_1 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_173 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_174 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_153 ( V_1 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_306 = 1 ;
if ( ! V_306 )
F_164 ( V_1 ) ;
V_306 = 0 ;
return 0 ;
}
static int T_8 F_176 ( void )
{
if ( F_177 () )
return 0 ;
return F_178 ( & V_307 ) ;
}
static void T_9 F_179 ( void )
{
F_180 ( & V_307 ) ;
}
