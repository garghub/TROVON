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
V_1 -> V_51 = 0 ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
}
void F_31 ( struct V_1 * V_1 )
{
struct V_52 * V_53 = F_32 ( V_1 ) ;
void T_2 * V_54 = V_1 -> V_36 ;
T_3 V_55 ;
F_12 ( V_1 -> V_30 , L_5 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_56 :
F_27 ( V_1 ) ;
F_12 ( V_1 -> V_30 , L_6 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
break;
case V_57 :
F_12 ( V_1 -> V_30 , L_7 ) ;
V_53 -> V_58 . V_59 = 0 ;
V_1 -> V_43 -> V_44 = V_46 ;
F_33 ( V_1 ) ;
V_55 = F_5 ( V_54 , V_14 ) ;
V_55 |= V_15 ;
F_6 ( V_54 , V_14 , V_55 ) ;
break;
default:
F_12 ( V_1 -> V_30 , L_8 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
V_1 -> V_60 &= ~ ( V_61 << 16 ) ;
}
static T_5 F_34 ( struct V_1 * V_1 , T_3 V_62 ,
T_3 V_63 )
{
struct V_64 * V_65 = V_1 -> V_43 -> V_65 ;
T_5 V_66 = V_67 ;
F_12 ( V_1 -> V_30 , L_9 , V_63 ,
V_62 ) ;
if ( V_62 & V_68 ) {
V_66 = V_69 ;
F_12 ( V_1 -> V_30 , L_10 , F_28 ( V_1 -> V_43 -> V_44 ) ) ;
if ( V_63 & V_70 ) {
void T_2 * V_54 = V_1 -> V_36 ;
T_3 V_11 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
V_11 = F_5 ( V_1 -> V_36 , V_14 ) ;
if ( V_11 & V_15 ) {
V_1 -> V_62 &= ~ V_71 ;
F_12 ( V_1 -> V_30 , L_11 ) ;
break;
}
V_11 &= ~ V_15 ;
F_6 ( V_54 , V_14 ,
V_11 | V_72 ) ;
V_1 -> V_60 |=
( V_73 << 16 )
| V_74 ;
V_1 -> V_75 = V_76
+ F_35 ( 20 ) ;
V_1 -> V_43 -> V_44 = V_77 ;
V_1 -> V_47 = 1 ;
F_36 ( F_32 ( V_1 ) ) ;
break;
case V_45 :
V_1 -> V_43 -> V_44 = V_46 ;
V_1 -> V_47 = 1 ;
F_33 ( V_1 ) ;
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
F_36 ( F_32 ( V_1 ) ) ;
break;
case V_45 :
case V_46 :
if ( ( V_63 & V_78 )
!= ( 3 << V_79 )
) {
V_1 -> V_62 |= V_80 ;
V_1 -> V_62 &= ~ V_71 ;
break;
}
F_38 ( V_1 ) ;
break;
case V_81 :
V_1 -> V_62 &= ~ V_71 ;
break;
default:
F_37 ( L_12 ,
L_14 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
}
}
}
if ( V_62 & V_82 ) {
void T_2 * V_54 = V_1 -> V_36 ;
if ( ( V_63 & V_78 ) == V_78
&& ( V_63 & V_83 ) ) {
F_12 ( V_1 -> V_30 , L_15 ) ;
return V_69 ;
}
F_12 ( V_1 -> V_30 , L_16 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
F_6 ( V_54 , V_84 , V_85 ) ;
V_1 -> V_86 = V_87 ;
V_1 -> V_43 -> V_44 = V_88 ;
F_39 ( V_1 ) ;
F_29 ( V_1 , 1 ) ;
V_66 = V_69 ;
}
if ( V_62 & V_89 ) {
int V_90 = 0 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_77 :
case V_49 :
case V_91 :
if ( V_1 -> V_92 ) {
void T_2 * V_54 = V_1 -> V_36 ;
V_1 -> V_92 -- ;
V_90 = 1 ;
V_63 |= V_85 ;
F_6 ( V_54 , V_84 , V_63 ) ;
} else {
V_1 -> V_60 |=
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
}; s; }),
VBUSERR_RETRY_COUNT - musb->vbuserr_retry,
musb->port1_status) ;
if ( ! V_90 )
F_29 ( V_1 , 0 ) ;
V_66 = V_69 ;
}
if ( V_62 & V_71 ) {
F_12 ( V_1 -> V_30 , L_22 ,
F_28 ( V_1 -> V_43 -> V_44 ) , V_63 ) ;
V_66 = V_69 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_56 :
F_31 ( V_1 ) ;
F_36 ( F_32 ( V_1 ) ) ;
F_41 ( V_1 ) ;
F_42 ( V_1 , V_76
+ F_35 ( V_1 -> V_95
? : V_96 ) ) ;
break;
case V_81 :
if ( ! V_1 -> V_47 )
break;
case V_46 :
F_43 ( V_1 ) ;
V_1 -> V_47 = V_65 -> V_97 -> V_98 ;
if ( V_1 -> V_47 ) {
V_1 -> V_43 -> V_44 = V_45 ;
F_12 ( V_1 -> V_30 , L_23 ) ;
F_44 ( & V_1 -> V_99 , V_76
+ F_35 (
V_100 ) ) ;
}
break;
case V_49 :
if ( V_1 -> V_95 != 0 )
F_42 ( V_1 , V_76
+ F_35 ( V_1 -> V_95 ) ) ;
break;
case V_77 :
V_1 -> V_43 -> V_44 = V_48 ;
V_1 -> V_47 = V_65 -> V_101 -> V_98 ;
break;
case V_57 :
F_12 ( V_1 -> V_30 , L_24 ) ;
break;
default:
V_1 -> V_47 = 0 ;
break;
}
}
if ( V_62 & V_102 ) {
struct V_52 * V_53 = F_32 ( V_1 ) ;
V_66 = V_69 ;
V_1 -> V_47 = 1 ;
V_1 -> V_86 = V_87 ;
if ( F_45 ( V_1 ) ) {
}
V_1 -> V_103 = V_1 -> V_104 ;
F_15 ( V_1 -> V_36 , V_105 , V_1 -> V_103 ) ;
V_1 -> V_106 = V_1 -> V_104 & 0xfffe ;
F_15 ( V_1 -> V_36 , V_107 , V_1 -> V_106 ) ;
F_6 ( V_1 -> V_36 , V_108 , 0xf7 ) ;
V_1 -> V_60 &= ~ ( V_109
| V_110
| V_111
) ;
V_1 -> V_60 |= V_112
| ( V_61 << 16 ) ;
if ( V_63 & V_113 )
V_1 -> V_60 |= V_109 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_46 :
if ( V_62 & V_71 ) {
F_12 ( V_1 -> V_30 , L_25 ) ;
V_62 &= ~ V_71 ;
goto V_114;
} else
F_12 ( V_1 -> V_30 , L_26 ) ;
break;
case V_45 :
F_12 ( V_1 -> V_30 , L_27 ) ;
V_114:
V_1 -> V_43 -> V_44 = V_57 ;
V_53 -> V_58 . V_59 = 1 ;
V_1 -> V_51 = 0 ;
F_46 ( & V_1 -> V_99 ) ;
break;
default:
if ( ( V_63 & V_78 )
== ( 3 << V_79 ) ) {
V_1 -> V_43 -> V_44 = V_77 ;
V_53 -> V_58 . V_59 = 0 ;
}
break;
}
F_39 ( V_1 ) ;
if ( V_53 -> V_115 )
F_47 ( V_53 ) ;
else
F_36 ( V_53 ) ;
F_12 ( V_1 -> V_30 , L_28 ,
F_28 ( V_1 -> V_43 -> V_44 ) , V_63 ) ;
}
if ( ( V_62 & V_80 ) && ! V_1 -> V_51 ) {
F_12 ( V_1 -> V_30 , L_29 ,
F_28 ( V_1 -> V_43 -> V_44 ) ,
F_48 ( V_1 ) , V_63 ) ;
V_66 = V_69 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_77 :
case V_48 :
F_36 ( F_32 ( V_1 ) ) ;
F_41 ( V_1 ) ;
if ( V_1 -> V_95 != 0 )
F_42 ( V_1 , V_76
+ F_35 ( V_1 -> V_95 ) ) ;
break;
case V_57 :
F_41 ( V_1 ) ;
F_32 ( V_1 ) -> V_58 . V_59 = 0 ;
V_1 -> V_43 -> V_44 = V_46 ;
F_33 ( V_1 ) ;
F_27 ( V_1 ) ;
break;
case V_56 :
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
if ( V_62 & V_116 ) {
V_66 = V_69 ;
if ( ( V_63 & V_70 ) != 0 ) {
if ( V_63 & ( V_117 | V_113 ) )
F_12 ( V_1 -> V_30 , L_31 , V_63 ) ;
else {
F_49 ( L_32 ) ;
F_6 ( V_1 -> V_36 , V_84 , 0 ) ;
}
} else {
F_12 ( V_1 -> V_30 , L_33 ,
F_28 ( V_1 -> V_43 -> V_44 ) ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
V_1 -> V_51 = 1 ;
F_50 ( V_1 ) ;
case V_49 :
F_12 ( V_1 -> V_30 , L_34 ,
F_28 ( V_1 -> V_43 -> V_44 ) ,
F_51 ( V_1 ) ) ;
F_44 ( & V_1 -> V_99 , V_76
+ F_35 ( F_51 ( V_1 ) ) ) ;
break;
case V_56 :
V_1 -> V_51 = 0 ;
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
F_52 ( & V_1 -> V_118 ) ;
return V_66 ;
}
void F_53 ( struct V_1 * V_1 )
{
void T_2 * V_34 = V_1 -> V_36 ;
T_3 V_63 = F_5 ( V_34 , V_84 ) ;
F_12 ( V_1 -> V_30 , L_37 , V_63 ) ;
V_1 -> V_103 = V_1 -> V_104 ;
F_15 ( V_34 , V_105 , V_1 -> V_103 ) ;
V_1 -> V_106 = V_1 -> V_104 & 0xfffe ;
F_15 ( V_34 , V_107 , V_1 -> V_106 ) ;
F_6 ( V_34 , V_108 , 0xf7 ) ;
F_6 ( V_34 , V_119 , 0 ) ;
F_6 ( V_34 , V_14 , V_120
| V_121
) ;
V_1 -> V_47 = 0 ;
V_63 = F_5 ( V_34 , V_84 ) ;
V_63 &= ~ V_85 ;
if ( ( V_63 & V_78 ) == V_78 )
V_1 -> V_47 = 1 ;
else
V_63 |= V_85 ;
F_54 ( V_1 ) ;
F_6 ( V_34 , V_84 , V_63 ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
void T_2 * V_54 = V_1 -> V_36 ;
T_4 V_122 ;
F_6 ( V_54 , V_108 , 0 ) ;
V_1 -> V_103 = 0 ;
F_15 ( V_54 , V_105 , 0 ) ;
V_1 -> V_106 = 0 ;
F_15 ( V_54 , V_107 , 0 ) ;
F_6 ( V_54 , V_84 , 0 ) ;
V_122 = F_5 ( V_54 , V_123 ) ;
V_122 = F_20 ( V_54 , V_124 ) ;
V_122 = F_20 ( V_54 , V_125 ) ;
}
void F_56 ( struct V_1 * V_1 )
{
F_57 ( V_1 ) ;
F_55 ( V_1 ) ;
F_12 ( V_1 -> V_30 , L_38 ) ;
F_42 ( V_1 , 0 ) ;
}
static void F_58 ( struct V_126 * V_127 )
{
struct V_1 * V_1 = F_1 ( & V_127 -> V_3 ) ;
unsigned long V_41 ;
F_4 ( V_1 -> V_30 ) ;
F_59 ( V_1 ) ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
F_57 ( V_1 ) ;
F_55 ( V_1 ) ;
F_30 ( & V_1 -> V_42 , V_41 ) ;
F_6 ( V_1 -> V_36 , V_84 , 0 ) ;
F_60 ( V_1 ) ;
F_7 ( V_1 -> V_30 ) ;
}
static int
F_61 ( struct V_1 * V_1 , struct V_25 * V_26 ,
const struct V_128 * V_129 , T_4 V_6 )
{
void T_2 * V_54 = V_1 -> V_36 ;
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
F_6 ( V_54 , V_140 , V_26 -> V_31 ) ;
if ( V_26 -> V_31 == 1 )
V_1 -> V_141 = V_26 ;
switch ( V_129 -> V_142 ) {
case V_143 :
F_64 ( V_54 , V_133 ) ;
F_65 ( V_54 , V_132 ) ;
V_26 -> V_144 = ! ! ( V_133 & V_139 ) ;
V_26 -> V_145 = V_131 ;
break;
case V_146 :
F_66 ( V_54 , V_133 ) ;
F_67 ( V_54 , V_132 ) ;
V_26 -> V_147 = ! ! ( V_133 & V_139 ) ;
V_26 -> V_148 = V_131 ;
break;
case V_149 :
F_64 ( V_54 , V_133 ) ;
F_65 ( V_54 , V_132 ) ;
V_26 -> V_147 = ! ! ( V_133 & V_139 ) ;
V_26 -> V_148 = V_131 ;
F_66 ( V_54 , V_133 ) ;
F_67 ( V_54 , V_132 ) ;
V_26 -> V_144 = V_26 -> V_147 ;
V_26 -> V_145 = V_131 ;
V_26 -> V_150 = true ;
break;
}
V_1 -> V_104 |= ( 1 << V_26 -> V_31 ) ;
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
void T_2 * V_54 = V_1 -> V_36 ;
int V_12 = 0 ;
F_12 ( V_1 -> V_30 , L_44 ) ;
for ( V_31 = 1 ; V_31 < V_1 -> V_136 -> V_167 ; V_31 ++ ) {
F_24 ( V_54 , V_31 ) ;
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
T_3 V_55 ;
char * type ;
char V_171 [ 90 ] , V_172 [ 32 ] , V_173 [ 12 ] ;
void T_2 * V_54 = V_1 -> V_36 ;
int V_174 = 0 ;
int V_9 ;
V_55 = F_75 ( V_54 ) ;
strcpy ( V_171 , ( V_55 & V_175 ) ? L_45 : L_46 ) ;
if ( V_55 & V_176 ) {
strcat ( V_171 , L_47 ) ;
V_1 -> V_177 = true ;
}
if ( V_55 & V_178 ) {
strcat ( V_171 , L_48 ) ;
V_1 -> V_179 = true ;
}
if ( V_55 & V_180 ) {
strcat ( V_171 , L_49 ) ;
V_1 -> V_181 = true ;
}
if ( V_55 & V_182 ) {
strcat ( V_171 , L_50 ) ;
V_1 -> V_183 = true ;
}
if ( V_55 & V_184 ) {
strcat ( V_171 , L_51 ) ;
V_1 -> V_185 = true ;
}
if ( V_55 & V_186 )
strcat ( V_171 , L_52 ) ;
F_70 ( V_162 L_53 ,
V_163 , V_55 , V_171 ) ;
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
V_1 -> V_190 = F_77 ( V_54 ) ;
snprintf ( V_172 , 32 , L_57 , F_78 ( V_1 -> V_190 ) ,
F_79 ( V_1 -> V_190 ) ,
( V_1 -> V_190 & V_191 ) ? L_58 : L_55 ) ;
F_70 ( V_162 L_59 ,
V_163 , type , V_172 , V_173 ) ;
F_80 ( V_1 ) ;
V_1 -> V_169 = 1 ;
V_1 -> V_104 = 1 ;
if ( V_1 -> V_177 )
V_174 = F_68 ( V_1 ) ;
else
V_174 = F_72 ( V_1 ) ;
if ( V_174 < 0 )
return V_174 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_169 ; V_9 ++ ) {
struct V_25 * V_26 = V_1 -> V_35 + V_9 ;
V_26 -> V_29 = F_81 ( V_9 ) + V_54 ;
#if F_82 ( V_192 ) || F_82 ( V_193 )
V_26 -> V_194 = V_1 -> V_195 + 0x400 + F_81 ( V_9 ) ;
V_26 -> V_196 = V_1 -> V_197 + 0x400 + F_81 ( V_9 ) ;
V_26 -> V_198 =
V_1 -> V_199 + 0x400 + F_81 ( V_9 ) ;
if ( V_9 == 0 )
V_26 -> V_200 = V_54 - 0x400 + V_201 ;
else
V_26 -> V_200 = V_54 + 0x400 + ( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
#endif
V_26 -> V_34 = F_83 ( V_9 , 0 ) + V_54 ;
V_26 -> V_202 = F_84 ( V_9 , V_54 ) ;
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
T_5 V_205 = V_67 ;
T_3 V_63 ;
int V_206 ;
T_1 V_55 ;
V_63 = F_5 ( V_1 -> V_36 , V_84 ) ;
F_12 ( V_1 -> V_30 , L_66 ,
( V_63 & V_70 ) ? L_13 : L_14 ,
V_1 -> V_62 , V_1 -> V_207 , V_1 -> V_208 ) ;
if ( V_1 -> V_62 )
V_205 |= F_34 ( V_1 , V_1 -> V_62 ,
V_63 ) ;
if ( V_1 -> V_207 & 1 ) {
if ( V_63 & V_70 )
V_205 |= F_86 ( V_1 ) ;
else
V_205 |= F_87 ( V_1 ) ;
}
V_55 = V_1 -> V_208 >> 1 ;
V_206 = 1 ;
while ( V_55 ) {
if ( V_55 & 1 ) {
V_205 = V_69 ;
if ( V_63 & V_70 )
F_88 ( V_1 , V_206 ) ;
else
F_89 ( V_1 , V_206 ) ;
}
V_55 >>= 1 ;
V_206 ++ ;
}
V_55 = V_1 -> V_207 >> 1 ;
V_206 = 1 ;
while ( V_55 ) {
if ( V_55 & 1 ) {
V_205 = V_69 ;
if ( V_63 & V_70 )
F_90 ( V_1 , V_206 ) ;
else
F_91 ( V_1 , V_206 ) ;
}
V_55 >>= 1 ;
V_206 ++ ;
}
return V_205 ;
}
void F_92 ( struct V_1 * V_1 , T_3 V_31 , T_3 V_209 )
{
T_3 V_63 = F_5 ( V_1 -> V_36 , V_84 ) ;
if ( ! V_31 ) {
#ifndef F_93
if ( ! F_94 () ) {
if ( V_63 & V_70 )
F_86 ( V_1 ) ;
else
F_87 ( V_1 ) ;
}
#endif
} else {
if ( V_209 ) {
if ( V_63 & V_70 )
F_90 ( V_1 , V_31 ) ;
else
F_91 ( V_1 , V_31 ) ;
} else {
if ( V_63 & V_70 )
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
V_1 -> V_95 = V_216 ? F_101 ( int , V_216 , V_96 ) : 0 ;
if ( V_1 -> V_43 -> V_44 == V_49 )
V_1 -> V_47 = 0 ;
F_42 ( V_1 , V_76 + F_35 ( V_216 ) ) ;
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
V_216 = V_1 -> V_95 ;
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
struct V_1 * V_1 = F_107 ( V_24 , struct V_1 , V_118 ) ;
if ( V_1 -> V_43 -> V_44 != V_1 -> V_220 ) {
V_1 -> V_220 = V_1 -> V_43 -> V_44 ;
F_108 ( & V_1 -> V_30 -> V_221 , NULL , L_76 ) ;
}
}
static struct V_1 * F_109 ( struct V_2 * V_3 ,
struct V_222 * V_136 , void T_2 * V_54 )
{
struct V_1 * V_1 ;
struct V_25 * V_223 ;
int V_31 ;
struct V_52 * V_53 ;
V_53 = F_110 ( & V_224 , V_3 , F_111 ( V_3 ) ) ;
if ( ! V_53 )
return NULL ;
V_1 = F_112 ( V_53 ) ;
F_113 ( & V_1 -> V_225 ) ;
F_113 ( & V_1 -> V_226 ) ;
F_113 ( & V_1 -> V_227 ) ;
V_53 -> V_228 = 1 ;
V_53 -> V_229 = 1 ;
V_1 -> V_92 = V_230 ;
V_1 -> V_95 = V_96 ;
F_114 ( V_3 , V_1 ) ;
V_1 -> V_36 = V_54 ;
V_1 -> V_231 = V_54 ;
V_1 -> V_232 = - V_233 ;
V_1 -> V_136 = V_136 ;
F_115 ( V_1 -> V_136 -> V_167 > V_234 ) ;
for ( V_31 = 0 , V_223 = V_1 -> V_35 ;
V_31 < V_1 -> V_136 -> V_167 ;
V_31 ++ , V_223 ++ ) {
V_223 -> V_1 = V_1 ;
V_223 -> V_31 = V_31 ;
}
V_1 -> V_30 = V_3 ;
return V_1 ;
}
static void F_116 ( struct V_1 * V_1 )
{
#ifdef F_117
F_118 ( & V_1 -> V_30 -> V_221 , & V_235 ) ;
#endif
if ( V_1 -> V_232 >= 0 ) {
if ( V_1 -> V_236 )
F_119 ( V_1 -> V_232 ) ;
F_120 ( V_1 -> V_232 , V_1 ) ;
}
if ( F_121 () && V_1 -> V_237 ) {
struct V_237 * V_238 = V_1 -> V_237 ;
( void ) V_238 -> V_239 ( V_238 ) ;
F_122 ( V_238 ) ;
}
F_123 ( F_32 ( V_1 ) ) ;
}
static int
F_124 ( struct V_2 * V_3 , int V_232 , void T_2 * V_240 )
{
int V_174 ;
struct V_1 * V_1 ;
struct V_241 * V_242 = V_3 -> V_243 ;
struct V_52 * V_53 ;
if ( ! V_242 ) {
F_12 ( V_3 , L_77 ) ;
V_174 = - V_233 ;
goto V_244;
}
V_1 = F_109 ( V_3 , V_242 -> V_136 , V_240 ) ;
if ( ! V_1 ) {
V_174 = - V_245 ;
goto V_244;
}
F_125 ( V_1 -> V_30 ) ;
F_126 ( V_1 -> V_30 , 200 ) ;
F_127 ( V_1 -> V_30 ) ;
F_128 ( & V_1 -> V_42 ) ;
V_1 -> V_246 = V_242 -> V_247 ;
V_1 -> V_248 = V_242 -> V_248 ;
V_1 -> V_249 = V_242 -> V_250 ;
V_174 = F_129 ( V_1 ) ;
if ( V_174 < 0 )
goto V_251;
if ( ! V_1 -> V_252 ) {
V_174 = - V_233 ;
goto V_253;
}
if ( ! V_1 -> V_43 -> V_254 ) {
V_1 -> V_43 -> V_13 = V_1 -> V_30 ;
V_1 -> V_43 -> V_8 = V_1 -> V_36 ;
V_1 -> V_43 -> V_254 = & V_255 ;
}
F_4 ( V_1 -> V_30 ) ;
#ifndef F_130
if ( V_256 && V_3 -> V_257 ) {
struct V_237 * V_238 ;
V_238 = F_131 ( V_1 , V_1 -> V_36 ) ;
V_1 -> V_237 = V_238 ;
if ( V_238 )
( void ) V_238 -> V_258 ( V_238 ) ;
}
#endif
if ( ! F_121 () || ! V_1 -> V_237 )
V_3 -> V_257 = NULL ;
F_57 ( V_1 ) ;
F_55 ( V_1 ) ;
V_174 = F_74 ( V_242 -> V_136 -> V_259
? V_187
: V_260 , V_1 ) ;
if ( V_174 < 0 )
goto V_261;
F_132 ( & V_1 -> V_99 , F_25 , ( unsigned long ) V_1 ) ;
F_133 ( & V_1 -> V_118 , F_106 ) ;
if ( F_134 ( V_232 , V_1 -> V_252 , 0 , F_111 ( V_3 ) , V_1 ) ) {
F_100 ( V_3 , L_78 , V_232 ) ;
V_174 = - V_233 ;
goto V_261;
}
V_1 -> V_232 = V_232 ;
if ( F_135 ( V_232 ) == 0 ) {
V_1 -> V_236 = 1 ;
F_136 ( V_3 , 1 ) ;
} else {
V_1 -> V_236 = 0 ;
}
V_53 = F_32 ( V_1 ) ;
F_137 ( V_1 -> V_43 -> V_65 , & V_53 -> V_58 ) ;
V_53 -> V_58 . V_262 = 1 ;
V_1 -> V_43 -> V_65 -> V_101 = & V_53 -> V_58 ;
V_53 -> V_263 = 2 * ( V_242 -> V_11 ? : 250 ) ;
if ( V_242 -> V_264 ) {
T_3 V_265 = F_138 ( V_1 -> V_36 ) ;
V_265 |= V_266 ;
F_139 ( V_1 -> V_36 , V_265 ) ;
}
if ( V_1 -> V_43 -> V_65 -> V_267 ) {
F_39 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_88 ;
} else {
F_33 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_81 ;
}
V_174 = F_140 ( V_1 ) ;
if ( V_174 < 0 )
goto V_261;
V_174 = F_141 ( V_1 ) ;
if ( V_174 < 0 )
goto V_268;
V_174 = F_142 ( & V_1 -> V_30 -> V_221 , & V_235 ) ;
if ( V_174 )
goto V_269;
F_7 ( V_1 -> V_30 ) ;
return 0 ;
V_269:
F_143 ( V_1 ) ;
V_268:
F_59 ( V_1 ) ;
V_261:
F_144 ( V_1 -> V_30 ) ;
V_253:
if ( V_1 -> V_236 )
F_136 ( V_3 , 0 ) ;
F_60 ( V_1 ) ;
V_251:
F_145 ( V_1 -> V_30 ) ;
F_100 ( V_1 -> V_30 ,
L_79 , V_174 ) ;
F_116 ( V_1 ) ;
V_244:
return V_174 ;
}
static int F_146 ( struct V_126 * V_127 )
{
struct V_2 * V_3 = & V_127 -> V_3 ;
int V_270 = F_147 ( V_127 , L_80 ) ;
struct V_271 * V_272 ;
void T_2 * V_273 ;
V_272 = F_148 ( V_127 , V_274 , 0 ) ;
if ( ! V_272 || V_270 <= 0 )
return - V_233 ;
V_273 = F_149 ( V_3 , V_272 ) ;
if ( F_150 ( V_273 ) )
return F_151 ( V_273 ) ;
return F_124 ( V_3 , V_270 , V_273 ) ;
}
static int F_152 ( struct V_126 * V_127 )
{
struct V_2 * V_3 = & V_127 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_143 ( V_1 ) ;
F_58 ( V_127 ) ;
F_116 ( V_1 ) ;
F_136 ( V_3 , 0 ) ;
#ifndef F_130
F_153 ( V_3 , * V_3 -> V_275 -> V_257 ) ;
#endif
return 0 ;
}
static void F_154 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_276 = V_1 -> V_36 ;
void T_2 * V_277 ;
V_1 -> V_278 . V_279 = F_20 ( V_276 , V_280 ) ;
V_1 -> V_278 . V_281 = F_5 ( V_276 , V_119 ) ;
V_1 -> V_278 . V_265 = F_138 ( V_1 -> V_36 ) ;
V_1 -> V_278 . V_11 = F_5 ( V_276 , V_14 ) ;
V_1 -> V_278 . V_282 = F_5 ( V_276 , V_108 ) ;
V_1 -> V_278 . V_32 = F_5 ( V_276 , V_140 ) ;
V_1 -> V_278 . V_63 = F_5 ( V_276 , V_84 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_136 -> V_167 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_277 = V_26 -> V_34 ;
if ( ! V_277 )
continue;
F_6 ( V_276 , V_140 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_284 =
F_20 ( V_277 , V_285 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_286 =
F_20 ( V_277 , V_287 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_288 =
F_20 ( V_277 , V_289 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_290 =
F_20 ( V_277 , V_291 ) ;
if ( V_1 -> V_177 ) {
V_1 -> V_278 . V_283 [ V_9 ] . V_292 =
F_155 ( V_276 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_293 =
F_156 ( V_276 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_294 =
F_157 ( V_276 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_295 =
F_158 ( V_276 ) ;
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
F_159 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_305 =
F_160 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_306 =
F_161 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_307 =
F_162 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_308 =
F_163 ( V_276 , V_9 ) ;
V_1 -> V_278 . V_283 [ V_9 ] . V_309 =
F_164 ( V_276 , V_9 ) ;
}
}
static void F_165 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_276 = V_1 -> V_36 ;
void T_2 * V_310 ;
void T_2 * V_277 ;
F_15 ( V_276 , V_280 , V_1 -> V_278 . V_279 ) ;
F_6 ( V_276 , V_119 , V_1 -> V_278 . V_281 ) ;
F_139 ( V_1 -> V_36 , V_1 -> V_278 . V_265 ) ;
F_6 ( V_276 , V_14 , V_1 -> V_278 . V_11 ) ;
F_15 ( V_276 , V_105 , V_1 -> V_103 ) ;
F_15 ( V_276 , V_107 , V_1 -> V_106 ) ;
F_6 ( V_276 , V_108 , V_1 -> V_278 . V_282 ) ;
F_6 ( V_276 , V_84 , V_1 -> V_278 . V_63 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_136 -> V_167 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_277 = V_26 -> V_34 ;
if ( ! V_277 )
continue;
F_6 ( V_276 , V_140 , V_9 ) ;
F_15 ( V_277 , V_285 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_284 ) ;
F_15 ( V_277 , V_287 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_286 ) ;
F_15 ( V_277 , V_289 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_288 ) ;
F_15 ( V_277 , V_291 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_290 ) ;
if ( V_1 -> V_177 ) {
F_64 ( V_276 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_294 ) ;
F_66 ( V_276 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_295 ) ;
F_65 ( V_276 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_292 ) ;
F_67 ( V_276 ,
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
F_166 ( V_276 , V_9 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_304 ) ;
F_167 ( V_276 , V_9 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_305 ) ;
F_168 ( V_276 , V_9 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_306 ) ;
V_310 =
F_84 ( V_9 , V_276 ) ;
F_169 ( V_310 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_307 ) ;
F_170 ( V_310 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_308 ) ;
F_171 ( V_310 ,
V_1 -> V_278 . V_283 [ V_9 ] . V_309 ) ;
}
F_6 ( V_276 , V_140 , V_1 -> V_278 . V_32 ) ;
}
static int F_172 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
F_26 ( & V_1 -> V_42 , V_41 ) ;
if ( F_45 ( V_1 ) ) {
} else if ( F_173 ( V_1 ) ) {
}
F_30 ( & V_1 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_174 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_154 ( V_1 ) ;
return 0 ;
}
static int F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_311 = 1 ;
if ( ! V_311 )
F_165 ( V_1 ) ;
V_311 = 0 ;
return 0 ;
}
static int T_8 F_177 ( void )
{
if ( F_178 () )
return 0 ;
return F_179 ( & V_312 ) ;
}
static void T_9 F_180 ( void )
{
F_181 ( & V_312 ) ;
}
