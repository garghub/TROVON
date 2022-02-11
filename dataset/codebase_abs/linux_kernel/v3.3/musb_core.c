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
V_11 = F_4 ( V_7 , V_12 ) ;
V_11 &= ~ V_13 ;
F_5 ( V_7 , V_12 , V_11 ) ;
F_5 ( V_7 , V_14 , ( T_3 ) V_6 ) ;
F_5 ( V_7 , V_15 ,
V_16 | V_17 ) ;
while ( ! ( F_4 ( V_7 , V_15 )
& V_18 ) ) {
V_9 ++ ;
if ( V_9 == 10000 )
return - V_19 ;
}
V_10 = F_4 ( V_7 , V_15 ) ;
V_10 &= ~ V_18 ;
F_5 ( V_7 , V_15 , V_10 ) ;
return F_4 ( V_7 , V_20 ) ;
}
static int F_6 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 V_21 )
{
void T_2 * V_7 = V_5 -> V_8 ;
int V_9 = 0 ;
T_3 V_10 = 0 ;
T_3 V_11 ;
V_11 = F_4 ( V_7 , V_12 ) ;
V_11 &= ~ V_13 ;
F_5 ( V_7 , V_12 , V_11 ) ;
F_5 ( V_7 , V_14 , ( T_3 ) V_6 ) ;
F_5 ( V_7 , V_20 , ( T_3 ) V_21 ) ;
F_5 ( V_7 , V_15 , V_16 ) ;
while ( ! ( F_4 ( V_7 , V_15 )
& V_18 ) ) {
V_9 ++ ;
if ( V_9 == 10000 )
return - V_19 ;
}
V_10 = F_4 ( V_7 , V_15 ) ;
V_10 &= ~ V_18 ;
F_5 ( V_7 , V_15 , V_10 ) ;
return 0 ;
}
void F_7 ( struct V_22 * V_23 , T_4 V_24 , const T_3 * V_25 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
void T_2 * V_26 = V_23 -> V_26 ;
F_8 ( ( T_3 * ) V_25 ) ;
F_9 ( V_1 -> V_27 , L_1 ,
'T' , V_23 -> V_28 , V_26 , V_24 , V_25 ) ;
if ( F_10 ( ( 0x01 & ( unsigned long ) V_25 ) == 0 ) ) {
T_4 V_29 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_25 ) == 0 ) {
if ( V_24 >= 4 ) {
F_11 ( V_26 , V_25 + V_29 , V_24 >> 2 ) ;
V_29 += V_24 & ~ 0x03 ;
}
if ( V_24 & 0x02 ) {
F_12 ( V_26 , 0 , * ( T_4 * ) & V_25 [ V_29 ] ) ;
V_29 += 2 ;
}
} else {
if ( V_24 >= 2 ) {
F_13 ( V_26 , V_25 + V_29 , V_24 >> 1 ) ;
V_29 += V_24 & ~ 0x01 ;
}
}
if ( V_24 & 0x01 )
F_5 ( V_26 , 0 , V_25 [ V_29 ] ) ;
} else {
F_14 ( V_26 , V_25 , V_24 ) ;
}
}
void F_15 ( struct V_22 * V_23 , T_4 V_24 , T_3 * V_30 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
void T_2 * V_26 = V_23 -> V_26 ;
F_9 ( V_1 -> V_27 , L_1 ,
'R' , V_23 -> V_28 , V_26 , V_24 , V_30 ) ;
if ( F_10 ( ( 0x01 & ( unsigned long ) V_30 ) == 0 ) ) {
T_4 V_29 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_30 ) == 0 ) {
if ( V_24 >= 4 ) {
F_16 ( V_26 , V_30 , V_24 >> 2 ) ;
V_29 = V_24 & ~ 0x03 ;
}
if ( V_24 & 0x02 ) {
* ( T_4 * ) & V_30 [ V_29 ] = F_17 ( V_26 , 0 ) ;
V_29 += 2 ;
}
} else {
if ( V_24 >= 2 ) {
F_18 ( V_26 , V_30 , V_24 >> 1 ) ;
V_29 = V_24 & ~ 0x01 ;
}
}
if ( V_24 & 0x01 )
V_30 [ V_29 ] = F_4 ( V_26 , 0 ) ;
} else {
F_19 ( V_26 , V_30 , V_24 ) ;
}
}
void F_20 ( struct V_1 * V_1 )
{
void T_2 * V_31 = V_1 -> V_32 [ 0 ] . V_31 ;
F_21 ( V_1 -> V_33 , 0 ) ;
F_7 ( V_1 -> V_34 ,
sizeof( V_35 ) , V_35 ) ;
F_12 ( V_31 , V_36 , V_37 ) ;
}
void F_22 ( unsigned long V_21 )
{
struct V_1 * V_1 = (struct V_1 * ) V_21 ;
unsigned long V_38 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_42 :
F_9 ( V_1 -> V_27 , L_2 ) ;
F_24 ( V_1 ) ;
V_1 -> V_40 -> V_41 = V_43 ;
V_1 -> V_44 = 0 ;
break;
case V_45 :
case V_46 :
F_9 ( V_1 -> V_27 , L_3 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
F_26 ( V_1 , 0 ) ;
V_1 -> V_40 -> V_41 = V_47 ;
break;
default:
F_9 ( V_1 -> V_27 , L_4 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
}
V_1 -> V_48 = 0 ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
}
void F_28 ( struct V_1 * V_1 )
{
struct V_49 * V_50 = F_29 ( V_1 ) ;
void T_2 * V_51 = V_1 -> V_33 ;
T_3 V_52 ;
F_9 ( V_1 -> V_27 , L_5 , F_25 ( V_1 -> V_40 -> V_41 ) ) ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_53 :
F_24 ( V_1 ) ;
F_9 ( V_1 -> V_27 , L_6 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
break;
case V_54 :
F_9 ( V_1 -> V_27 , L_7 ) ;
V_50 -> V_55 . V_56 = 0 ;
V_1 -> V_40 -> V_41 = V_43 ;
F_30 ( V_1 ) ;
V_52 = F_4 ( V_51 , V_12 ) ;
V_52 |= V_13 ;
F_5 ( V_51 , V_12 , V_52 ) ;
break;
default:
F_9 ( V_1 -> V_27 , L_8 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
}
V_1 -> V_57 &= ~ ( V_58 << 16 ) ;
}
static T_5 F_31 ( struct V_1 * V_1 , T_3 V_59 ,
T_3 V_60 , T_3 V_11 )
{
T_5 V_61 = V_62 ;
F_9 ( V_1 -> V_27 , L_9 , V_11 , V_60 ,
V_59 ) ;
if ( V_59 & V_63 ) {
V_61 = V_64 ;
F_9 ( V_1 -> V_27 , L_10 , F_25 ( V_1 -> V_40 -> V_41 ) ) ;
if ( V_60 & V_65 ) {
void T_2 * V_51 = V_1 -> V_33 ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_45 :
if ( V_11 & V_13 ) {
V_1 -> V_59 &= ~ V_66 ;
F_9 ( V_1 -> V_27 , L_11 ) ;
break;
}
V_11 &= ~ V_13 ;
F_5 ( V_51 , V_12 ,
V_11 | V_67 ) ;
V_1 -> V_57 |=
( V_68 << 16 )
| V_69 ;
V_1 -> V_70 = V_71
+ F_32 ( 20 ) ;
V_1 -> V_40 -> V_41 = V_72 ;
V_1 -> V_44 = 1 ;
F_33 ( F_29 ( V_1 ) ) ;
break;
case V_42 :
V_1 -> V_40 -> V_41 = V_43 ;
V_1 -> V_44 = 1 ;
F_30 ( V_1 ) ;
break;
default:
F_34 ( L_12 ,
L_13 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
}
} else {
switch ( V_1 -> V_40 -> V_41 ) {
case V_45 :
V_1 -> V_40 -> V_41 = V_72 ;
F_33 ( F_29 ( V_1 ) ) ;
break;
case V_42 :
case V_43 :
if ( ( V_60 & V_73 )
!= ( 3 << V_74 )
) {
V_1 -> V_59 |= V_75 ;
V_1 -> V_59 &= ~ V_66 ;
break;
}
F_35 ( V_1 ) ;
break;
case V_76 :
V_1 -> V_59 &= ~ V_66 ;
break;
default:
F_34 ( L_12 ,
L_14 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
}
}
}
if ( V_59 & V_77 ) {
void T_2 * V_51 = V_1 -> V_33 ;
if ( ( V_60 & V_73 ) == V_73
&& ( V_60 & V_78 ) ) {
F_9 ( V_1 -> V_27 , L_15 ) ;
return V_64 ;
}
F_9 ( V_1 -> V_27 , L_16 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
F_5 ( V_51 , V_79 , V_80 ) ;
V_1 -> V_81 = V_82 ;
V_1 -> V_40 -> V_41 = V_83 ;
F_36 ( V_1 ) ;
F_26 ( V_1 , 1 ) ;
V_61 = V_64 ;
}
if ( V_59 & V_84 ) {
int V_85 = 0 ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_72 :
case V_46 :
case V_86 :
if ( V_1 -> V_87 ) {
void T_2 * V_51 = V_1 -> V_33 ;
V_1 -> V_87 -- ;
V_85 = 1 ;
V_60 |= V_80 ;
F_5 ( V_51 , V_79 , V_60 ) ;
} else {
V_1 -> V_57 |=
V_88
| ( V_89 << 16 ) ;
}
break;
default:
break;
}
F_9 (musb->controller, L_17 ,
otg_state_string(musb->xceiv->state),
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
if ( ! V_85 )
F_26 ( V_1 , 0 ) ;
V_61 = V_64 ;
}
if ( V_59 & V_66 ) {
F_9 ( V_1 -> V_27 , L_22 ,
F_25 ( V_1 -> V_40 -> V_41 ) , V_60 , V_11 ) ;
V_61 = V_64 ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_53 :
F_28 ( V_1 ) ;
F_33 ( F_29 ( V_1 ) ) ;
F_37 ( V_1 ) ;
F_38 ( V_1 , V_71
+ F_32 ( V_1 -> V_90
? : V_91 ) ) ;
break;
case V_76 :
if ( ! V_1 -> V_44 )
break;
case V_43 :
F_39 ( V_1 ) ;
V_1 -> V_44 = F_40 ( V_1 )
&& V_1 -> V_40 -> V_92 -> V_93 ;
if ( V_1 -> V_44 ) {
V_1 -> V_40 -> V_41 = V_42 ;
F_9 ( V_1 -> V_27 , L_23 ) ;
F_41 ( & V_1 -> V_94 , V_71
+ F_32 (
V_95 ) ) ;
}
break;
case V_46 :
if ( V_1 -> V_90 != 0 )
F_38 ( V_1 , V_71
+ F_32 ( V_1 -> V_90 ) ) ;
break;
case V_72 :
V_1 -> V_40 -> V_41 = V_45 ;
V_1 -> V_44 = F_40 ( V_1 )
&& V_1 -> V_40 -> V_96 -> V_93 ;
break;
case V_54 :
F_9 ( V_1 -> V_27 , L_24 ) ;
break;
default:
V_1 -> V_44 = 0 ;
break;
}
}
if ( V_59 & V_97 ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
V_61 = V_64 ;
V_1 -> V_44 = 1 ;
V_1 -> V_81 = V_82 ;
if ( F_42 ( V_1 ) ) {
}
F_12 ( V_1 -> V_33 , V_98 , V_1 -> V_99 ) ;
F_12 ( V_1 -> V_33 , V_100 , V_1 -> V_99 & 0xfffe ) ;
F_5 ( V_1 -> V_33 , V_101 , 0xf7 ) ;
V_1 -> V_57 &= ~ ( V_102
| V_103
| V_104
) ;
V_1 -> V_57 |= V_105
| ( V_58 << 16 ) ;
if ( V_60 & V_106 )
V_1 -> V_57 |= V_102 ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_43 :
if ( V_59 & V_66 ) {
F_9 ( V_1 -> V_27 , L_25 ) ;
V_59 &= ~ V_66 ;
goto V_107;
} else
F_9 ( V_1 -> V_27 , L_26 ) ;
break;
case V_42 :
F_9 ( V_1 -> V_27 , L_27 ) ;
V_107:
V_1 -> V_40 -> V_41 = V_54 ;
V_50 -> V_55 . V_56 = 1 ;
V_1 -> V_48 = 0 ;
F_43 ( & V_1 -> V_94 ) ;
break;
default:
if ( ( V_60 & V_73 )
== ( 3 << V_74 ) ) {
V_1 -> V_40 -> V_41 = V_72 ;
V_50 -> V_55 . V_56 = 0 ;
}
break;
}
F_36 ( V_1 ) ;
if ( V_50 -> V_108 )
F_44 ( V_50 ) ;
else
F_33 ( V_50 ) ;
F_9 ( V_1 -> V_27 , L_28 ,
F_25 ( V_1 -> V_40 -> V_41 ) , V_60 ) ;
}
if ( ( V_59 & V_75 ) && ! V_1 -> V_48 ) {
F_9 ( V_1 -> V_27 , L_29 ,
F_25 ( V_1 -> V_40 -> V_41 ) ,
F_45 ( V_1 ) , V_60 ) ;
V_61 = V_64 ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_72 :
case V_45 :
F_33 ( F_29 ( V_1 ) ) ;
F_37 ( V_1 ) ;
if ( V_1 -> V_90 != 0 && F_40 ( V_1 ) )
F_38 ( V_1 , V_71
+ F_32 ( V_1 -> V_90 ) ) ;
break;
case V_54 :
F_37 ( V_1 ) ;
F_29 ( V_1 ) -> V_55 . V_56 = 0 ;
V_1 -> V_40 -> V_41 = V_43 ;
F_30 ( V_1 ) ;
F_24 ( V_1 ) ;
break;
case V_53 :
F_28 ( V_1 ) ;
F_37 ( V_1 ) ;
case V_42 :
case V_43 :
case V_76 :
F_24 ( V_1 ) ;
break;
default:
F_34 ( L_30 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
break;
}
}
if ( V_59 & V_109 ) {
V_61 = V_64 ;
if ( F_46 () && ( V_60 & V_65 ) != 0 ) {
if ( V_60 & ( V_110 | V_106 ) )
F_9 ( V_1 -> V_27 , L_31 , V_60 ) ;
else {
F_47 ( L_32 ) ;
F_5 ( V_1 -> V_33 , V_79 , 0 ) ;
}
} else if ( F_48 () ) {
F_9 ( V_1 -> V_27 , L_33 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_45 :
V_1 -> V_48 = 1 ;
F_49 ( V_1 ) ;
case V_46 :
F_9 ( V_1 -> V_27 , L_34 ,
F_25 ( V_1 -> V_40 -> V_41 ) ,
F_50 ( V_1 ) ) ;
F_41 ( & V_1 -> V_94 , V_71
+ F_32 ( F_50 ( V_1 ) ) ) ;
break;
case V_53 :
V_1 -> V_48 = 0 ;
F_43 ( & V_1 -> V_94 ) ;
F_49 ( V_1 ) ;
break;
case V_42 :
F_9 ( V_1 -> V_27 , L_35 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
V_1 -> V_40 -> V_41 = V_43 ;
F_49 ( V_1 ) ;
break;
case V_76 :
V_1 -> V_40 -> V_41 = V_43 ;
case V_43 :
F_49 ( V_1 ) ;
break;
default:
F_9 ( V_1 -> V_27 , L_36 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
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
F_51 ( & V_1 -> V_111 ) ;
return V_61 ;
}
void F_52 ( struct V_1 * V_1 )
{
void T_2 * V_31 = V_1 -> V_33 ;
T_3 V_60 = F_4 ( V_31 , V_79 ) ;
F_9 ( V_1 -> V_27 , L_37 , V_60 ) ;
F_12 ( V_31 , V_98 , V_1 -> V_99 ) ;
F_12 ( V_31 , V_100 , V_1 -> V_99 & 0xfffe ) ;
F_5 ( V_31 , V_101 , 0xf7 ) ;
F_5 ( V_31 , V_112 , 0 ) ;
F_5 ( V_31 , V_12 , V_113
| V_114
) ;
V_1 -> V_44 = 0 ;
V_60 = F_4 ( V_31 , V_79 ) ;
V_60 &= ~ V_80 ;
if ( F_40 ( V_1 ) ) {
if ( ( V_60 & V_73 ) == V_73 )
V_1 -> V_44 = 1 ;
else
V_60 |= V_80 ;
} else if ( F_53 ( V_1 ) ) {
V_60 |= V_80 ;
} else {
if ( ( V_60 & V_73 ) == V_73 )
V_1 -> V_44 = 1 ;
}
F_54 ( V_1 ) ;
F_5 ( V_31 , V_79 , V_60 ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
void T_2 * V_51 = V_1 -> V_33 ;
T_4 V_115 ;
F_5 ( V_51 , V_101 , 0 ) ;
F_12 ( V_51 , V_98 , 0 ) ;
F_12 ( V_51 , V_100 , 0 ) ;
F_5 ( V_51 , V_79 , 0 ) ;
V_115 = F_4 ( V_51 , V_116 ) ;
V_115 = F_17 ( V_51 , V_117 ) ;
V_115 = F_17 ( V_51 , V_118 ) ;
}
void F_56 ( struct V_1 * V_1 )
{
F_57 ( V_1 ) ;
F_55 ( V_1 ) ;
F_9 ( V_1 -> V_27 , L_38 ) ;
F_38 ( V_1 , 0 ) ;
}
static void F_58 ( struct V_119 * V_120 )
{
struct V_1 * V_1 = F_1 ( & V_120 -> V_3 ) ;
unsigned long V_38 ;
F_59 ( V_1 -> V_27 ) ;
F_60 ( V_1 ) ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
F_57 ( V_1 ) ;
F_55 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
if ( ! F_40 ( V_1 ) && F_53 ( V_1 ) )
F_61 ( F_29 ( V_1 ) ) ;
F_5 ( V_1 -> V_33 , V_79 , 0 ) ;
F_62 ( V_1 ) ;
F_63 ( V_1 -> V_27 ) ;
}
static int T_6
F_64 ( struct V_1 * V_1 , struct V_22 * V_23 ,
const struct V_121 * V_122 , T_4 V_6 )
{
void T_2 * V_51 = V_1 -> V_33 ;
int V_123 = 0 ;
T_4 V_124 = V_122 -> V_124 ;
T_4 V_125 = V_6 >> 3 ;
T_3 V_126 ;
V_123 = F_65 ( F_66 ( V_124 , ( T_4 ) 8 ) ) - 1 ;
V_124 = 1 << V_123 ;
V_126 = V_123 - 3 ;
if ( V_122 -> V_127 == V_128 ) {
if ( ( V_6 + ( V_124 << 1 ) ) >
( 1 << ( V_1 -> V_129 -> V_130 + 2 ) ) )
return - V_131 ;
V_126 |= V_132 ;
} else {
if ( ( V_6 + V_124 ) > ( 1 << ( V_1 -> V_129 -> V_130 + 2 ) ) )
return - V_131 ;
}
F_5 ( V_51 , V_133 , V_23 -> V_28 ) ;
if ( V_23 -> V_28 == 1 )
V_1 -> V_134 = V_23 ;
switch ( V_122 -> V_135 ) {
case V_136 :
F_67 ( V_51 , V_126 ) ;
F_68 ( V_51 , V_125 ) ;
V_23 -> V_137 = ! ! ( V_126 & V_132 ) ;
V_23 -> V_138 = V_124 ;
break;
case V_139 :
F_69 ( V_51 , V_126 ) ;
F_70 ( V_51 , V_125 ) ;
V_23 -> V_140 = ! ! ( V_126 & V_132 ) ;
V_23 -> V_141 = V_124 ;
break;
case V_142 :
F_67 ( V_51 , V_126 ) ;
F_68 ( V_51 , V_125 ) ;
V_23 -> V_140 = ! ! ( V_126 & V_132 ) ;
V_23 -> V_141 = V_124 ;
F_69 ( V_51 , V_126 ) ;
F_70 ( V_51 , V_125 ) ;
V_23 -> V_137 = V_23 -> V_140 ;
V_23 -> V_138 = V_124 ;
V_23 -> V_143 = true ;
break;
}
V_1 -> V_99 |= ( 1 << V_23 -> V_28 ) ;
return V_6 + ( V_124 << ( ( V_126 & V_132 ) ? 1 : 0 ) ) ;
}
static int T_6 F_71 ( struct V_1 * V_1 )
{
const struct V_121 * V_122 ;
unsigned V_9 , V_144 ;
int V_6 ;
struct V_22 * V_23 = V_1 -> V_32 ;
if ( V_1 -> V_129 -> V_145 ) {
V_122 = V_1 -> V_129 -> V_145 ;
V_144 = V_1 -> V_129 -> V_146 ;
goto V_147;
}
switch ( V_148 ) {
default:
V_148 = 0 ;
case 0 :
V_122 = V_149 ;
V_144 = F_72 ( V_149 ) ;
break;
case 1 :
V_122 = V_150 ;
V_144 = F_72 ( V_150 ) ;
break;
case 2 :
V_122 = V_151 ;
V_144 = F_72 ( V_151 ) ;
break;
case 3 :
V_122 = V_152 ;
V_144 = F_72 ( V_152 ) ;
break;
case 4 :
V_122 = V_153 ;
V_144 = F_72 ( V_153 ) ;
break;
case 5 :
V_122 = V_154 ;
V_144 = F_72 ( V_154 ) ;
break;
}
F_73 ( V_155 L_39 ,
V_156 , V_148 ) ;
V_147:
V_6 = F_64 ( V_1 , V_23 , & V_157 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_144 ; V_9 ++ ) {
T_3 V_158 = V_122 -> V_159 ;
if ( V_158 >= V_1 -> V_129 -> V_160 ) {
F_74 ( L_40 ,
V_156 , V_158 ) ;
return - V_161 ;
}
V_6 = F_64 ( V_1 , V_23 + V_158 , V_122 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_74 ( L_41 ,
V_156 , V_158 ) ;
return - V_161 ;
}
V_158 ++ ;
V_1 -> V_162 = F_66 ( V_158 , V_1 -> V_162 ) ;
}
F_73 ( V_155 L_42 ,
V_156 ,
V_144 + 1 , V_1 -> V_129 -> V_160 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_129 -> V_130 + 2 ) ) ) ;
if ( ! V_1 -> V_134 ) {
F_74 ( L_43 , V_156 ) ;
return - V_161 ;
}
return 0 ;
}
static int T_6 F_75 ( struct V_1 * V_1 )
{
T_3 V_28 = 0 ;
struct V_22 * V_23 ;
void * V_51 = V_1 -> V_33 ;
int V_163 = 0 ;
F_9 ( V_1 -> V_27 , L_44 ) ;
for ( V_28 = 1 ; V_28 < V_1 -> V_129 -> V_160 ; V_28 ++ ) {
F_21 ( V_51 , V_28 ) ;
V_23 = V_1 -> V_32 + V_28 ;
V_163 = F_76 ( V_1 , V_23 , V_28 ) ;
if ( V_163 < 0 )
break;
if ( V_23 -> V_138 < 512
|| V_23 -> V_141 < 512 )
continue;
if ( V_1 -> V_134 )
continue;
V_1 -> V_134 = V_23 ;
}
if ( ! V_1 -> V_134 ) {
F_74 ( L_43 , V_156 ) ;
return - V_161 ;
}
return 0 ;
}
static int T_6 F_77 ( T_4 V_164 , struct V_1 * V_1 )
{
T_3 V_52 ;
char * type ;
char V_165 [ 90 ] , V_166 [ 32 ] , V_167 [ 12 ] ;
void T_2 * V_51 = V_1 -> V_33 ;
int V_168 = 0 ;
int V_9 ;
V_52 = F_78 ( V_51 ) ;
strcpy ( V_165 , ( V_52 & V_169 ) ? L_45 : L_46 ) ;
if ( V_52 & V_170 ) {
strcat ( V_165 , L_47 ) ;
V_1 -> V_171 = true ;
}
if ( V_52 & V_172 ) {
strcat ( V_165 , L_48 ) ;
V_1 -> V_173 = true ;
}
if ( V_52 & V_174 ) {
strcat ( V_165 , L_49 ) ;
V_1 -> V_175 = true ;
}
if ( V_52 & V_176 ) {
strcat ( V_165 , L_50 ) ;
V_1 -> V_177 = true ;
}
if ( V_52 & V_178 ) {
strcat ( V_165 , L_51 ) ;
V_1 -> V_179 = true ;
}
if ( V_52 & V_180 )
strcat ( V_165 , L_52 ) ;
F_73 ( V_155 L_53 ,
V_156 , V_52 , V_165 ) ;
V_167 [ 0 ] = 0 ;
if ( V_181 == V_164 ) {
V_1 -> V_182 = 1 ;
type = L_54 ;
} else {
V_1 -> V_182 = 0 ;
type = L_55 ;
#ifndef F_79
F_73 ( V_183
L_56 ,
V_156 ) ;
#endif
}
V_1 -> V_184 = F_80 ( V_51 ) ;
snprintf ( V_166 , 32 , L_57 , F_81 ( V_1 -> V_184 ) ,
F_82 ( V_1 -> V_184 ) ,
( V_1 -> V_184 & V_185 ) ? L_58 : L_55 ) ;
F_73 ( V_155 L_59 ,
V_156 , type , V_166 , V_167 ) ;
F_83 ( V_1 ) ;
V_1 -> V_162 = 1 ;
V_1 -> V_99 = 1 ;
if ( V_1 -> V_171 )
V_168 = F_71 ( V_1 ) ;
else
V_168 = F_75 ( V_1 ) ;
if ( V_168 < 0 )
return V_168 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_162 ; V_9 ++ ) {
struct V_22 * V_23 = V_1 -> V_32 + V_9 ;
V_23 -> V_26 = F_84 ( V_9 ) + V_51 ;
#if F_85 ( V_186 ) || F_85 ( V_187 )
V_23 -> V_188 = V_1 -> V_189 + 0x400 + F_84 ( V_9 ) ;
V_23 -> V_190 = V_1 -> V_191 + 0x400 + F_84 ( V_9 ) ;
V_23 -> V_192 =
V_1 -> V_193 + 0x400 + F_84 ( V_9 ) ;
if ( V_9 == 0 )
V_23 -> V_194 = V_51 - 0x400 + V_195 ;
else
V_23 -> V_194 = V_51 + 0x400 + ( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
#endif
V_23 -> V_31 = F_86 ( V_9 , 0 ) + V_51 ;
V_23 -> V_196 = F_87 ( V_9 , V_51 ) ;
V_23 -> V_197 = 1 ;
V_23 -> V_198 = 1 ;
if ( V_23 -> V_138 ) {
F_9 ( V_1 -> V_27 ,
L_60 ,
V_156 , V_9 ,
V_23 -> V_143 ? L_61 : L_62 ,
V_23 -> V_137
? L_63 : L_55 ,
V_23 -> V_138 ) ;
}
if ( V_23 -> V_141 && ! V_23 -> V_143 ) {
F_9 ( V_1 -> V_27 ,
L_60 ,
V_156 , V_9 ,
L_64 ,
V_23 -> V_140
? L_63 : L_55 ,
V_23 -> V_141 ) ;
}
if ( ! ( V_23 -> V_138 || V_23 -> V_141 ) )
F_9 ( V_1 -> V_27 , L_65 , V_9 ) ;
}
return 0 ;
}
static T_5 F_88 ( int V_199 , void * V_200 )
{
unsigned long V_38 ;
T_5 V_201 = V_62 ;
struct V_1 * V_1 = V_200 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_1 -> V_59 = F_4 ( V_1 -> V_33 , V_116 ) ;
V_1 -> V_202 = F_17 ( V_1 -> V_33 , V_117 ) ;
V_1 -> V_203 = F_17 ( V_1 -> V_33 , V_118 ) ;
if ( V_1 -> V_59 || V_1 -> V_202 || V_1 -> V_203 )
V_201 = F_89 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_201 ;
}
T_5 F_89 ( struct V_1 * V_1 )
{
T_5 V_201 = V_62 ;
T_3 V_60 , V_11 ;
int V_204 ;
T_1 V_52 ;
V_60 = F_4 ( V_1 -> V_33 , V_79 ) ;
V_11 = F_4 ( V_1 -> V_33 , V_12 ) ;
F_9 ( V_1 -> V_27 , L_66 ,
( V_60 & V_65 ) ? L_13 : L_14 ,
V_1 -> V_59 , V_1 -> V_202 , V_1 -> V_203 ) ;
if ( V_1 -> V_59 )
V_201 |= F_31 ( V_1 , V_1 -> V_59 ,
V_60 , V_11 ) ;
if ( V_1 -> V_202 & 1 ) {
if ( V_60 & V_65 )
V_201 |= F_90 ( V_1 ) ;
else
V_201 |= F_91 ( V_1 ) ;
}
V_52 = V_1 -> V_203 >> 1 ;
V_204 = 1 ;
while ( V_52 ) {
if ( V_52 & 1 ) {
V_201 = V_64 ;
if ( V_60 & V_65 ) {
if ( F_46 () )
F_92 ( V_1 , V_204 ) ;
} else {
if ( F_48 () )
F_93 ( V_1 , V_204 ) ;
}
}
V_52 >>= 1 ;
V_204 ++ ;
}
V_52 = V_1 -> V_202 >> 1 ;
V_204 = 1 ;
while ( V_52 ) {
if ( V_52 & 1 ) {
V_201 = V_64 ;
if ( V_60 & V_65 ) {
if ( F_46 () )
F_94 ( V_1 , V_204 ) ;
} else {
if ( F_48 () )
F_95 ( V_1 , V_204 ) ;
}
}
V_52 >>= 1 ;
V_204 ++ ;
}
return V_201 ;
}
void F_96 ( struct V_1 * V_1 , T_3 V_28 , T_3 V_205 )
{
T_3 V_60 = F_4 ( V_1 -> V_33 , V_79 ) ;
if ( ! V_28 ) {
#ifndef F_97
if ( ! F_98 () ) {
if ( V_60 & V_65 )
F_90 ( V_1 ) ;
else
F_91 ( V_1 ) ;
}
#endif
} else {
if ( V_205 ) {
if ( V_60 & V_65 ) {
if ( F_46 () )
F_94 ( V_1 , V_28 ) ;
} else {
if ( F_48 () )
F_95 ( V_1 , V_28 ) ;
}
} else {
if ( V_60 & V_65 ) {
if ( F_46 () )
F_92 ( V_1 , V_28 ) ;
} else {
if ( F_48 () )
F_93 ( V_1 , V_28 ) ;
}
}
}
}
static T_7
F_99 ( struct V_2 * V_3 , struct V_206 * V_207 , char * V_208 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
int V_163 = - V_161 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_163 = sprintf ( V_208 , L_67 , F_25 ( V_1 -> V_40 -> V_41 ) ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_163 ;
}
static T_7
F_100 ( struct V_2 * V_3 , struct V_206 * V_207 ,
const char * V_208 , T_8 V_144 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
int V_168 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
if ( F_101 ( V_208 , L_13 ) )
V_168 = F_102 ( V_1 , V_209 ) ;
else if ( F_101 ( V_208 , L_14 ) )
V_168 = F_102 ( V_1 , V_210 ) ;
else if ( F_101 ( V_208 , L_68 ) )
V_168 = F_102 ( V_1 , V_211 ) ;
else
V_168 = - V_161 ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return ( V_168 == 0 ) ? V_144 : V_168 ;
}
static T_7
F_103 ( struct V_2 * V_3 , struct V_206 * V_207 ,
const char * V_208 , T_8 V_144 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
unsigned long V_212 ;
if ( sscanf ( V_208 , L_69 , & V_212 ) < 1 ) {
F_104 ( V_3 , L_70 ) ;
return - V_161 ;
}
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_1 -> V_90 = V_212 ? F_105 ( int , V_212 , V_91 ) : 0 ;
if ( V_1 -> V_40 -> V_41 == V_46 )
V_1 -> V_44 = 0 ;
F_38 ( V_1 , V_71 + F_32 ( V_212 ) ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_144 ;
}
static T_7
F_106 ( struct V_2 * V_3 , struct V_206 * V_207 , char * V_208 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
unsigned long V_212 ;
int V_213 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_212 = V_1 -> V_90 ;
V_213 = F_107 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return sprintf ( V_208 , L_71 ,
V_213 ? L_72 : L_73 , V_212 ) ;
}
static T_7
F_108 ( struct V_2 * V_3 , struct V_206 * V_207 ,
const char * V_208 , T_8 V_144 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_214 ;
if ( sscanf ( V_208 , L_74 , & V_214 ) != 1
|| ( V_214 != 1 ) ) {
F_104 ( V_3 , L_75 ) ;
return - V_161 ;
}
if ( V_214 == 1 )
F_109 ( V_1 ) ;
return V_144 ;
}
static void F_110 ( struct V_215 * V_21 )
{
struct V_1 * V_1 = F_111 ( V_21 , struct V_1 , V_111 ) ;
static int V_216 ;
if ( V_1 -> V_40 -> V_41 != V_216 ) {
V_216 = V_1 -> V_40 -> V_41 ;
F_112 ( & V_1 -> V_27 -> V_217 , NULL , L_76 ) ;
}
}
static struct V_1 * T_6
F_113 ( struct V_2 * V_3 ,
struct V_218 * V_129 , void T_2 * V_51 )
{
struct V_1 * V_1 ;
struct V_22 * V_219 ;
int V_28 ;
struct V_49 * V_50 ;
V_50 = F_114 ( & V_220 , V_3 , F_115 ( V_3 ) ) ;
if ( ! V_50 )
return NULL ;
V_1 = F_116 ( V_50 ) ;
F_117 ( & V_1 -> V_221 ) ;
F_117 ( & V_1 -> V_222 ) ;
F_117 ( & V_1 -> V_223 ) ;
V_50 -> V_224 = 1 ;
V_50 -> V_225 = 1 ;
V_1 -> V_87 = V_226 ;
V_1 -> V_90 = V_91 ;
F_118 ( V_3 , V_1 ) ;
V_1 -> V_33 = V_51 ;
V_1 -> V_227 = V_51 ;
V_1 -> V_228 = - V_229 ;
V_1 -> V_129 = V_129 ;
F_119 ( V_1 -> V_129 -> V_160 > V_230 ) ;
for ( V_28 = 0 , V_219 = V_1 -> V_32 ;
V_28 < V_1 -> V_129 -> V_160 ;
V_28 ++ , V_219 ++ ) {
V_219 -> V_1 = V_1 ;
V_219 -> V_28 = V_28 ;
}
V_1 -> V_27 = V_3 ;
return V_1 ;
}
static void F_120 ( struct V_1 * V_1 )
{
#ifdef F_121
F_122 ( & V_1 -> V_27 -> V_217 , & V_231 ) ;
#endif
if ( V_1 -> V_228 >= 0 ) {
if ( V_1 -> V_232 )
F_123 ( V_1 -> V_228 ) ;
F_124 ( V_1 -> V_228 , V_1 ) ;
}
if ( F_125 () && V_1 -> V_233 ) {
struct V_233 * V_234 = V_1 -> V_233 ;
( void ) V_234 -> V_235 ( V_234 ) ;
F_126 ( V_234 ) ;
}
F_127 ( V_1 ) ;
}
static int T_6
F_128 ( struct V_2 * V_3 , int V_228 , void T_2 * V_236 )
{
int V_168 ;
struct V_1 * V_1 ;
struct V_237 * V_238 = V_3 -> V_239 ;
if ( ! V_238 ) {
F_9 ( V_3 , L_77 ) ;
V_168 = - V_229 ;
goto V_240;
}
V_1 = F_113 ( V_3 , V_238 -> V_129 , V_236 ) ;
if ( ! V_1 ) {
V_168 = - V_241 ;
goto V_240;
}
F_129 ( V_1 -> V_27 ) ;
F_130 ( V_1 -> V_27 , 200 ) ;
F_131 ( V_1 -> V_27 ) ;
F_132 ( & V_1 -> V_39 ) ;
V_1 -> V_242 = V_238 -> V_127 ;
V_1 -> V_243 = V_238 -> V_244 ;
V_1 -> V_245 = V_238 -> V_245 ;
V_1 -> V_246 = V_238 -> V_247 ;
V_1 -> V_248 = F_88 ;
V_168 = F_133 ( V_1 ) ;
if ( V_168 < 0 )
goto V_249;
if ( ! V_1 -> V_248 ) {
V_168 = - V_229 ;
goto V_250;
}
if ( ! V_1 -> V_40 -> V_251 ) {
V_1 -> V_40 -> V_8 = V_1 -> V_33 ;
V_1 -> V_40 -> V_251 = & V_252 ;
}
#ifndef F_134
if ( V_253 && V_3 -> V_254 ) {
struct V_233 * V_234 ;
V_234 = F_135 ( V_1 , V_1 -> V_33 ) ;
V_1 -> V_233 = V_234 ;
if ( V_234 )
( void ) V_234 -> V_255 ( V_234 ) ;
}
#endif
if ( ! F_125 () || ! V_1 -> V_233 )
V_3 -> V_254 = NULL ;
F_57 ( V_1 ) ;
F_55 ( V_1 ) ;
V_168 = F_77 ( V_238 -> V_129 -> V_256
? V_181
: V_257 , V_1 ) ;
if ( V_168 < 0 )
goto V_250;
F_136 ( & V_1 -> V_94 , F_22 , ( unsigned long ) V_1 ) ;
F_137 ( & V_1 -> V_111 , F_110 ) ;
if ( F_138 ( V_228 , V_1 -> V_248 , 0 , F_115 ( V_3 ) , V_1 ) ) {
F_104 ( V_3 , L_78 , V_228 ) ;
V_168 = - V_229 ;
goto V_250;
}
V_1 -> V_228 = V_228 ;
if ( F_139 ( V_228 ) == 0 ) {
V_1 -> V_232 = 1 ;
F_140 ( V_3 , 1 ) ;
} else {
V_1 -> V_232 = 0 ;
}
if ( F_53 ( V_1 ) ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
F_141 ( V_1 -> V_40 , & V_50 -> V_55 ) ;
if ( F_40 ( V_1 ) )
V_50 -> V_55 . V_258 = 1 ;
V_1 -> V_40 -> V_96 = & V_50 -> V_55 ;
V_50 -> V_259 = 2 * ( V_238 -> V_11 ? : 250 ) ;
if ( V_238 -> V_260 ) {
T_3 V_261 = F_142 ( V_1 -> V_33 ) ;
V_261 |= V_262 ;
F_143 ( V_1 -> V_33 , V_261 ) ;
}
}
if ( ! F_40 ( V_1 ) && F_53 ( V_1 ) ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
F_36 ( V_1 ) ;
V_1 -> V_40 -> V_263 = 1 ;
V_1 -> V_40 -> V_41 = V_83 ;
V_168 = F_144 ( F_29 ( V_1 ) , - 1 , 0 ) ;
V_50 -> V_55 . V_264 = 1 ;
F_9 ( V_1 -> V_27 , L_79 ,
L_80 , V_168 ,
F_4 ( V_1 -> V_33 , V_79 ) ,
( F_4 ( V_1 -> V_33 , V_79 )
& V_78
? 'B' : 'A' ) ) ;
} else {
F_30 ( V_1 ) ;
V_1 -> V_40 -> V_263 = 0 ;
V_1 -> V_40 -> V_41 = V_76 ;
V_168 = F_145 ( V_1 ) ;
F_9 ( V_1 -> V_27 , L_81 ,
F_40 ( V_1 ) ? L_82 : L_83 ,
V_168 ,
F_4 ( V_1 -> V_33 , V_79 ) ) ;
}
if ( V_168 < 0 )
goto V_250;
V_168 = F_146 ( V_1 ) ;
if ( V_168 < 0 )
goto V_265;
#ifdef F_121
V_168 = F_147 ( & V_1 -> V_27 -> V_217 , & V_231 ) ;
if ( V_168 )
goto V_266;
#endif
F_148 (dev, L_84 ,
({char *s;
switch (musb->board_mode) {
case MUSB_HOST: s = L_85; break;
case MUSB_PERIPHERAL: s = L_86; break;
default: s = L_82; break;
}; s; }),
ctrl,
(is_dma_capable() && musb->dma_controller)
? L_87 : L_88 ,
musb->nIrq) ;
return 0 ;
V_266:
F_149 ( V_1 ) ;
V_265:
if ( ! F_40 ( V_1 ) && F_53 ( V_1 ) )
F_61 ( F_29 ( V_1 ) ) ;
else
F_60 ( V_1 ) ;
V_250:
if ( V_1 -> V_232 )
F_140 ( V_3 , 0 ) ;
F_62 ( V_1 ) ;
V_249:
F_104 ( V_1 -> V_27 ,
L_89 , V_168 ) ;
F_120 ( V_1 ) ;
V_240:
return V_168 ;
}
static int T_6 F_150 ( struct V_119 * V_120 )
{
struct V_2 * V_3 = & V_120 -> V_3 ;
int V_199 = F_151 ( V_120 , L_90 ) ;
int V_168 ;
struct V_267 * V_268 ;
void T_2 * V_269 ;
V_268 = F_152 ( V_120 , V_270 , 0 ) ;
if ( ! V_268 || V_199 <= 0 )
return - V_229 ;
V_269 = F_153 ( V_268 -> V_255 , F_154 ( V_268 ) ) ;
if ( ! V_269 ) {
F_104 ( V_3 , L_91 ) ;
return - V_241 ;
}
#ifndef F_134
V_271 = V_3 -> V_254 ;
#endif
V_168 = F_128 ( V_3 , V_199 , V_269 ) ;
if ( V_168 < 0 )
F_155 ( V_269 ) ;
return V_168 ;
}
static int T_9 F_156 ( struct V_119 * V_120 )
{
struct V_1 * V_1 = F_1 ( & V_120 -> V_3 ) ;
void T_2 * V_227 = V_1 -> V_227 ;
F_59 ( V_1 -> V_27 ) ;
F_149 ( V_1 ) ;
F_58 ( V_120 ) ;
F_63 ( V_1 -> V_27 ) ;
F_120 ( V_1 ) ;
F_155 ( V_227 ) ;
F_140 ( & V_120 -> V_3 , 0 ) ;
#ifndef F_134
V_120 -> V_3 . V_254 = V_271 ;
#endif
return 0 ;
}
static void F_157 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_272 = V_1 -> V_33 ;
void T_2 * V_273 ;
if ( F_53 ( V_1 ) ) {
V_1 -> V_274 . V_275 = F_17 ( V_272 , V_276 ) ;
V_1 -> V_274 . V_277 = F_4 ( V_272 , V_112 ) ;
V_1 -> V_274 . V_261 = F_142 ( V_1 -> V_33 ) ;
}
V_1 -> V_274 . V_11 = F_4 ( V_272 , V_12 ) ;
V_1 -> V_274 . V_278 = F_17 ( V_272 , V_98 ) ;
V_1 -> V_274 . V_279 = F_17 ( V_272 , V_100 ) ;
V_1 -> V_274 . V_280 = F_4 ( V_272 , V_101 ) ;
V_1 -> V_274 . V_29 = F_4 ( V_272 , V_133 ) ;
V_1 -> V_274 . V_60 = F_4 ( V_272 , V_79 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_129 -> V_160 ; ++ V_9 ) {
struct V_22 * V_23 ;
V_23 = & V_1 -> V_32 [ V_9 ] ;
if ( ! V_23 )
continue;
V_273 = V_23 -> V_31 ;
if ( ! V_273 )
continue;
F_5 ( V_272 , V_133 , V_9 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_282 =
F_17 ( V_273 , V_283 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_284 =
F_17 ( V_273 , V_285 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_286 =
F_17 ( V_273 , V_287 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_288 =
F_17 ( V_273 , V_289 ) ;
if ( V_1 -> V_171 ) {
V_1 -> V_274 . V_281 [ V_9 ] . V_290 =
F_158 ( V_272 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_291 =
F_159 ( V_272 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_292 =
F_160 ( V_272 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_293 =
F_161 ( V_272 ) ;
}
if ( F_53 ( V_1 ) ) {
V_1 -> V_274 . V_281 [ V_9 ] . V_294 =
F_4 ( V_273 , V_295 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_296 =
F_4 ( V_273 , V_297 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_298 =
F_4 ( V_273 , V_299 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_300 =
F_4 ( V_273 , V_301 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_302 =
F_162 ( V_272 , V_9 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_303 =
F_163 ( V_272 , V_9 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_304 =
F_164 ( V_272 , V_9 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_305 =
F_165 ( V_272 , V_9 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_306 =
F_166 ( V_272 , V_9 ) ;
V_1 -> V_274 . V_281 [ V_9 ] . V_307 =
F_167 ( V_272 , V_9 ) ;
}
}
}
static void F_168 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_272 = V_1 -> V_33 ;
void T_2 * V_308 ;
void T_2 * V_273 ;
if ( F_53 ( V_1 ) ) {
F_12 ( V_272 , V_276 , V_1 -> V_274 . V_275 ) ;
F_5 ( V_272 , V_112 , V_1 -> V_274 . V_277 ) ;
F_143 ( V_1 -> V_33 , V_1 -> V_274 . V_261 ) ;
}
F_5 ( V_272 , V_12 , V_1 -> V_274 . V_11 ) ;
F_12 ( V_272 , V_98 , V_1 -> V_274 . V_278 ) ;
F_12 ( V_272 , V_100 , V_1 -> V_274 . V_279 ) ;
F_5 ( V_272 , V_101 , V_1 -> V_274 . V_280 ) ;
F_5 ( V_272 , V_79 , V_1 -> V_274 . V_60 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_129 -> V_160 ; ++ V_9 ) {
struct V_22 * V_23 ;
V_23 = & V_1 -> V_32 [ V_9 ] ;
if ( ! V_23 )
continue;
V_273 = V_23 -> V_31 ;
if ( ! V_273 )
continue;
F_5 ( V_272 , V_133 , V_9 ) ;
F_12 ( V_273 , V_283 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_282 ) ;
F_12 ( V_273 , V_285 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_284 ) ;
F_12 ( V_273 , V_287 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_286 ) ;
F_12 ( V_273 , V_289 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_288 ) ;
if ( V_1 -> V_171 ) {
F_67 ( V_272 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_292 ) ;
F_69 ( V_272 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_293 ) ;
F_68 ( V_272 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_290 ) ;
F_70 ( V_272 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_291 ) ;
}
if ( F_53 ( V_1 ) ) {
F_5 ( V_273 , V_295 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_294 ) ;
F_5 ( V_273 , V_297 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_296 ) ;
F_5 ( V_273 , V_299 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_298 ) ;
F_5 ( V_273 , V_301 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_300 ) ;
F_169 ( V_272 , V_9 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_302 ) ;
F_170 ( V_272 , V_9 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_303 ) ;
F_171 ( V_272 , V_9 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_304 ) ;
V_308 =
F_87 ( V_9 , V_272 ) ;
F_172 ( V_308 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_305 ) ;
F_173 ( V_308 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_306 ) ;
F_174 ( V_308 ,
V_1 -> V_274 . V_281 [ V_9 ] . V_307 ) ;
}
}
F_5 ( V_272 , V_133 , V_1 -> V_274 . V_29 ) ;
}
static int F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
if ( F_42 ( V_1 ) ) {
} else if ( F_176 ( V_1 ) ) {
}
F_27 ( & V_1 -> V_39 , V_38 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_178 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_157 ( V_1 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_309 = 1 ;
if ( ! V_309 )
F_168 ( V_1 ) ;
V_309 = 0 ;
return 0 ;
}
static int T_6 F_180 ( void )
{
if ( F_181 () )
return 0 ;
F_182 ( L_92 V_310 L_93
L_94
L_93
L_95 ,
V_156 ) ;
return F_183 ( & V_311 , F_150 ) ;
}
static void T_9 F_184 ( void )
{
F_185 ( & V_311 ) ;
}
