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
F_10 ( ( T_3 * ) V_28 ) ;
F_11 ( V_1 -> V_30 , L_1 ,
'T' , V_26 -> V_31 , V_29 , V_27 , V_28 ) ;
if ( F_12 ( ( 0x01 & ( unsigned long ) V_28 ) == 0 ) ) {
T_4 V_32 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_28 ) == 0 ) {
if ( V_27 >= 4 ) {
F_13 ( V_29 , V_28 + V_32 , V_27 >> 2 ) ;
V_32 += V_27 & ~ 0x03 ;
}
if ( V_27 & 0x02 ) {
F_14 ( V_29 , 0 , * ( T_4 * ) & V_28 [ V_32 ] ) ;
V_32 += 2 ;
}
} else {
if ( V_27 >= 2 ) {
F_15 ( V_29 , V_28 + V_32 , V_27 >> 1 ) ;
V_32 += V_27 & ~ 0x01 ;
}
}
if ( V_27 & 0x01 )
F_6 ( V_29 , 0 , V_28 [ V_32 ] ) ;
} else {
F_16 ( V_29 , V_28 , V_27 ) ;
}
}
void F_17 ( struct V_25 * V_26 , T_4 V_27 , T_3 * V_33 )
{
struct V_1 * V_1 = V_26 -> V_1 ;
void T_2 * V_29 = V_26 -> V_29 ;
F_11 ( V_1 -> V_30 , L_1 ,
'R' , V_26 -> V_31 , V_29 , V_27 , V_33 ) ;
if ( F_12 ( ( 0x01 & ( unsigned long ) V_33 ) == 0 ) ) {
T_4 V_32 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_33 ) == 0 ) {
if ( V_27 >= 4 ) {
F_18 ( V_29 , V_33 , V_27 >> 2 ) ;
V_32 = V_27 & ~ 0x03 ;
}
if ( V_27 & 0x02 ) {
* ( T_4 * ) & V_33 [ V_32 ] = F_19 ( V_29 , 0 ) ;
V_32 += 2 ;
}
} else {
if ( V_27 >= 2 ) {
F_20 ( V_29 , V_33 , V_27 >> 1 ) ;
V_32 = V_27 & ~ 0x01 ;
}
}
if ( V_27 & 0x01 )
V_33 [ V_32 ] = F_5 ( V_29 , 0 ) ;
} else {
F_21 ( V_29 , V_33 , V_27 ) ;
}
}
void F_22 ( struct V_1 * V_1 )
{
void T_2 * V_34 = V_1 -> V_35 [ 0 ] . V_34 ;
F_23 ( V_1 -> V_36 , 0 ) ;
F_9 ( V_1 -> V_37 ,
sizeof( V_38 ) , V_38 ) ;
F_14 ( V_34 , V_39 , V_40 ) ;
}
void F_24 ( unsigned long V_24 )
{
struct V_1 * V_1 = (struct V_1 * ) V_24 ;
unsigned long V_41 ;
F_25 ( & V_1 -> V_42 , V_41 ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_45 :
F_11 ( V_1 -> V_30 , L_2 ) ;
F_26 ( V_1 ) ;
V_1 -> V_43 -> V_44 = V_46 ;
V_1 -> V_47 = 0 ;
break;
case V_48 :
case V_49 :
F_11 ( V_1 -> V_30 , L_3 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
F_28 ( V_1 , 0 ) ;
V_1 -> V_43 -> V_44 = V_50 ;
break;
default:
F_11 ( V_1 -> V_30 , L_4 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
}
V_1 -> V_51 = 0 ;
F_29 ( & V_1 -> V_42 , V_41 ) ;
}
void F_30 ( struct V_1 * V_1 )
{
struct V_52 * V_53 = F_31 ( V_1 ) ;
void T_2 * V_54 = V_1 -> V_36 ;
T_3 V_55 ;
F_11 ( V_1 -> V_30 , L_5 , F_27 ( V_1 -> V_43 -> V_44 ) ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_56 :
F_26 ( V_1 ) ;
F_11 ( V_1 -> V_30 , L_6 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
break;
case V_57 :
F_11 ( V_1 -> V_30 , L_7 ) ;
V_53 -> V_58 . V_59 = 0 ;
V_1 -> V_43 -> V_44 = V_46 ;
F_32 ( V_1 ) ;
V_55 = F_5 ( V_54 , V_14 ) ;
V_55 |= V_15 ;
F_6 ( V_54 , V_14 , V_55 ) ;
break;
default:
F_11 ( V_1 -> V_30 , L_8 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
}
V_1 -> V_60 &= ~ ( V_61 << 16 ) ;
}
static T_5 F_33 ( struct V_1 * V_1 , T_3 V_62 ,
T_3 V_63 , T_3 V_11 )
{
struct V_64 * V_65 = V_1 -> V_43 -> V_65 ;
T_5 V_66 = V_67 ;
F_11 ( V_1 -> V_30 , L_9 , V_11 , V_63 ,
V_62 ) ;
if ( V_62 & V_68 ) {
V_66 = V_69 ;
F_11 ( V_1 -> V_30 , L_10 , F_27 ( V_1 -> V_43 -> V_44 ) ) ;
if ( V_63 & V_70 ) {
void T_2 * V_54 = V_1 -> V_36 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
if ( V_11 & V_15 ) {
V_1 -> V_62 &= ~ V_71 ;
F_11 ( V_1 -> V_30 , L_11 ) ;
break;
}
V_11 &= ~ V_15 ;
F_6 ( V_54 , V_14 ,
V_11 | V_72 ) ;
V_1 -> V_60 |=
( V_73 << 16 )
| V_74 ;
V_1 -> V_75 = V_76
+ F_34 ( 20 ) ;
V_1 -> V_43 -> V_44 = V_77 ;
V_1 -> V_47 = 1 ;
F_35 ( F_31 ( V_1 ) ) ;
break;
case V_45 :
V_1 -> V_43 -> V_44 = V_46 ;
V_1 -> V_47 = 1 ;
F_32 ( V_1 ) ;
break;
default:
F_36 ( L_12 ,
L_13 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
}
} else {
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
V_1 -> V_43 -> V_44 = V_77 ;
F_35 ( F_31 ( V_1 ) ) ;
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
F_37 ( V_1 ) ;
break;
case V_81 :
V_1 -> V_62 &= ~ V_71 ;
break;
default:
F_36 ( L_12 ,
L_14 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
}
}
}
if ( V_62 & V_82 ) {
void T_2 * V_54 = V_1 -> V_36 ;
if ( ( V_63 & V_78 ) == V_78
&& ( V_63 & V_83 ) ) {
F_11 ( V_1 -> V_30 , L_15 ) ;
return V_69 ;
}
F_11 ( V_1 -> V_30 , L_16 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
F_6 ( V_54 , V_84 , V_85 ) ;
V_1 -> V_86 = V_87 ;
V_1 -> V_43 -> V_44 = V_88 ;
F_38 ( V_1 ) ;
F_28 ( V_1 , 1 ) ;
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
F_11 (musb->controller, L_17 ,
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
if ( ! V_90 )
F_28 ( V_1 , 0 ) ;
V_66 = V_69 ;
}
if ( V_62 & V_71 ) {
F_11 ( V_1 -> V_30 , L_22 ,
F_27 ( V_1 -> V_43 -> V_44 ) , V_63 , V_11 ) ;
V_66 = V_69 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_56 :
F_30 ( V_1 ) ;
F_35 ( F_31 ( V_1 ) ) ;
F_39 ( V_1 ) ;
F_40 ( V_1 , V_76
+ F_34 ( V_1 -> V_95
? : V_96 ) ) ;
break;
case V_81 :
if ( ! V_1 -> V_47 )
break;
case V_46 :
F_41 ( V_1 ) ;
V_1 -> V_47 = F_42 ( V_1 )
&& V_65 -> V_97 -> V_98 ;
if ( V_1 -> V_47 ) {
V_1 -> V_43 -> V_44 = V_45 ;
F_11 ( V_1 -> V_30 , L_23 ) ;
F_43 ( & V_1 -> V_99 , V_76
+ F_34 (
V_100 ) ) ;
}
break;
case V_49 :
if ( V_1 -> V_95 != 0 )
F_40 ( V_1 , V_76
+ F_34 ( V_1 -> V_95 ) ) ;
break;
case V_77 :
V_1 -> V_43 -> V_44 = V_48 ;
V_1 -> V_47 = F_42 ( V_1 )
&& V_65 -> V_101 -> V_98 ;
break;
case V_57 :
F_11 ( V_1 -> V_30 , L_24 ) ;
break;
default:
V_1 -> V_47 = 0 ;
break;
}
}
if ( V_62 & V_102 ) {
struct V_52 * V_53 = F_31 ( V_1 ) ;
V_66 = V_69 ;
V_1 -> V_47 = 1 ;
V_1 -> V_86 = V_87 ;
if ( F_44 ( V_1 ) ) {
}
F_14 ( V_1 -> V_36 , V_103 , V_1 -> V_104 ) ;
F_14 ( V_1 -> V_36 , V_105 , V_1 -> V_104 & 0xfffe ) ;
F_6 ( V_1 -> V_36 , V_106 , 0xf7 ) ;
V_1 -> V_60 &= ~ ( V_107
| V_108
| V_109
) ;
V_1 -> V_60 |= V_110
| ( V_61 << 16 ) ;
if ( V_63 & V_111 )
V_1 -> V_60 |= V_107 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_46 :
if ( V_62 & V_71 ) {
F_11 ( V_1 -> V_30 , L_25 ) ;
V_62 &= ~ V_71 ;
goto V_112;
} else
F_11 ( V_1 -> V_30 , L_26 ) ;
break;
case V_45 :
F_11 ( V_1 -> V_30 , L_27 ) ;
V_112:
V_1 -> V_43 -> V_44 = V_57 ;
V_53 -> V_58 . V_59 = 1 ;
V_1 -> V_51 = 0 ;
F_45 ( & V_1 -> V_99 ) ;
break;
default:
if ( ( V_63 & V_78 )
== ( 3 << V_79 ) ) {
V_1 -> V_43 -> V_44 = V_77 ;
V_53 -> V_58 . V_59 = 0 ;
}
break;
}
F_38 ( V_1 ) ;
if ( V_53 -> V_113 )
F_46 ( V_53 ) ;
else
F_35 ( V_53 ) ;
F_11 ( V_1 -> V_30 , L_28 ,
F_27 ( V_1 -> V_43 -> V_44 ) , V_63 ) ;
}
if ( ( V_62 & V_80 ) && ! V_1 -> V_51 ) {
F_11 ( V_1 -> V_30 , L_29 ,
F_27 ( V_1 -> V_43 -> V_44 ) ,
F_47 ( V_1 ) , V_63 ) ;
V_66 = V_69 ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_77 :
case V_48 :
F_35 ( F_31 ( V_1 ) ) ;
F_39 ( V_1 ) ;
if ( V_1 -> V_95 != 0 && F_42 ( V_1 ) )
F_40 ( V_1 , V_76
+ F_34 ( V_1 -> V_95 ) ) ;
break;
case V_57 :
F_39 ( V_1 ) ;
F_31 ( V_1 ) -> V_58 . V_59 = 0 ;
V_1 -> V_43 -> V_44 = V_46 ;
F_32 ( V_1 ) ;
F_26 ( V_1 ) ;
break;
case V_56 :
F_30 ( V_1 ) ;
F_39 ( V_1 ) ;
case V_45 :
case V_46 :
case V_81 :
F_26 ( V_1 ) ;
break;
default:
F_36 ( L_30 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
break;
}
}
if ( V_62 & V_114 ) {
V_66 = V_69 ;
if ( F_48 () && ( V_63 & V_70 ) != 0 ) {
if ( V_63 & ( V_115 | V_111 ) )
F_11 ( V_1 -> V_30 , L_31 , V_63 ) ;
else {
F_49 ( L_32 ) ;
F_6 ( V_1 -> V_36 , V_84 , 0 ) ;
}
} else if ( F_50 () ) {
F_11 ( V_1 -> V_30 , L_33 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
switch ( V_1 -> V_43 -> V_44 ) {
case V_48 :
V_1 -> V_51 = 1 ;
F_51 ( V_1 ) ;
case V_49 :
F_11 ( V_1 -> V_30 , L_34 ,
F_27 ( V_1 -> V_43 -> V_44 ) ,
F_52 ( V_1 ) ) ;
F_43 ( & V_1 -> V_99 , V_76
+ F_34 ( F_52 ( V_1 ) ) ) ;
break;
case V_56 :
V_1 -> V_51 = 0 ;
F_45 ( & V_1 -> V_99 ) ;
F_51 ( V_1 ) ;
break;
case V_45 :
F_11 ( V_1 -> V_30 , L_35 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
V_1 -> V_43 -> V_44 = V_46 ;
F_51 ( V_1 ) ;
break;
case V_81 :
V_1 -> V_43 -> V_44 = V_46 ;
case V_46 :
F_51 ( V_1 ) ;
break;
default:
F_11 ( V_1 -> V_30 , L_36 ,
F_27 ( V_1 -> V_43 -> V_44 ) ) ;
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
F_53 ( & V_1 -> V_116 ) ;
return V_66 ;
}
void F_54 ( struct V_1 * V_1 )
{
void T_2 * V_34 = V_1 -> V_36 ;
T_3 V_63 = F_5 ( V_34 , V_84 ) ;
F_11 ( V_1 -> V_30 , L_37 , V_63 ) ;
F_14 ( V_34 , V_103 , V_1 -> V_104 ) ;
F_14 ( V_34 , V_105 , V_1 -> V_104 & 0xfffe ) ;
F_6 ( V_34 , V_106 , 0xf7 ) ;
F_6 ( V_34 , V_117 , 0 ) ;
F_6 ( V_34 , V_14 , V_118
| V_119
) ;
V_1 -> V_47 = 0 ;
V_63 = F_5 ( V_34 , V_84 ) ;
V_63 &= ~ V_85 ;
if ( F_42 ( V_1 ) ) {
if ( ( V_63 & V_78 ) == V_78 )
V_1 -> V_47 = 1 ;
else
V_63 |= V_85 ;
} else if ( F_55 ( V_1 ) ) {
V_63 |= V_85 ;
} else {
if ( ( V_63 & V_78 ) == V_78 )
V_1 -> V_47 = 1 ;
}
F_56 ( V_1 ) ;
F_6 ( V_34 , V_84 , V_63 ) ;
}
static void F_57 ( struct V_1 * V_1 )
{
void T_2 * V_54 = V_1 -> V_36 ;
T_4 V_120 ;
F_6 ( V_54 , V_106 , 0 ) ;
F_14 ( V_54 , V_103 , 0 ) ;
F_14 ( V_54 , V_105 , 0 ) ;
F_6 ( V_54 , V_84 , 0 ) ;
V_120 = F_5 ( V_54 , V_121 ) ;
V_120 = F_19 ( V_54 , V_122 ) ;
V_120 = F_19 ( V_54 , V_123 ) ;
}
void F_58 ( struct V_1 * V_1 )
{
F_59 ( V_1 ) ;
F_57 ( V_1 ) ;
F_11 ( V_1 -> V_30 , L_38 ) ;
F_40 ( V_1 , 0 ) ;
}
static void F_60 ( struct V_124 * V_125 )
{
struct V_1 * V_1 = F_1 ( & V_125 -> V_3 ) ;
unsigned long V_41 ;
F_4 ( V_1 -> V_30 ) ;
F_61 ( V_1 ) ;
F_25 ( & V_1 -> V_42 , V_41 ) ;
F_59 ( V_1 ) ;
F_57 ( V_1 ) ;
F_29 ( & V_1 -> V_42 , V_41 ) ;
if ( ! F_42 ( V_1 ) && F_55 ( V_1 ) )
F_62 ( F_31 ( V_1 ) ) ;
F_6 ( V_1 -> V_36 , V_84 , 0 ) ;
F_63 ( V_1 ) ;
F_7 ( V_1 -> V_30 ) ;
}
static int T_6
F_64 ( struct V_1 * V_1 , struct V_25 * V_26 ,
const struct V_126 * V_127 , T_4 V_6 )
{
void T_2 * V_54 = V_1 -> V_36 ;
int V_128 = 0 ;
T_4 V_129 = V_127 -> V_129 ;
T_4 V_130 = V_6 >> 3 ;
T_3 V_131 ;
V_128 = F_65 ( F_66 ( V_129 , ( T_4 ) 8 ) ) - 1 ;
V_129 = 1 << V_128 ;
V_131 = V_128 - 3 ;
if ( V_127 -> V_132 == V_133 ) {
if ( ( V_6 + ( V_129 << 1 ) ) >
( 1 << ( V_1 -> V_134 -> V_135 + 2 ) ) )
return - V_136 ;
V_131 |= V_137 ;
} else {
if ( ( V_6 + V_129 ) > ( 1 << ( V_1 -> V_134 -> V_135 + 2 ) ) )
return - V_136 ;
}
F_6 ( V_54 , V_138 , V_26 -> V_31 ) ;
if ( V_26 -> V_31 == 1 )
V_1 -> V_139 = V_26 ;
switch ( V_127 -> V_140 ) {
case V_141 :
F_67 ( V_54 , V_131 ) ;
F_68 ( V_54 , V_130 ) ;
V_26 -> V_142 = ! ! ( V_131 & V_137 ) ;
V_26 -> V_143 = V_129 ;
break;
case V_144 :
F_69 ( V_54 , V_131 ) ;
F_70 ( V_54 , V_130 ) ;
V_26 -> V_145 = ! ! ( V_131 & V_137 ) ;
V_26 -> V_146 = V_129 ;
break;
case V_147 :
F_67 ( V_54 , V_131 ) ;
F_68 ( V_54 , V_130 ) ;
V_26 -> V_145 = ! ! ( V_131 & V_137 ) ;
V_26 -> V_146 = V_129 ;
F_69 ( V_54 , V_131 ) ;
F_70 ( V_54 , V_130 ) ;
V_26 -> V_142 = V_26 -> V_145 ;
V_26 -> V_143 = V_129 ;
V_26 -> V_148 = true ;
break;
}
V_1 -> V_104 |= ( 1 << V_26 -> V_31 ) ;
return V_6 + ( V_129 << ( ( V_131 & V_137 ) ? 1 : 0 ) ) ;
}
static int T_6 F_71 ( struct V_1 * V_1 )
{
const struct V_126 * V_127 ;
unsigned V_9 , V_149 ;
int V_6 ;
struct V_25 * V_26 = V_1 -> V_35 ;
if ( V_1 -> V_134 -> V_150 ) {
V_127 = V_1 -> V_134 -> V_150 ;
V_149 = V_1 -> V_134 -> V_151 ;
goto V_152;
}
switch ( V_153 ) {
default:
V_153 = 0 ;
case 0 :
V_127 = V_154 ;
V_149 = F_72 ( V_154 ) ;
break;
case 1 :
V_127 = V_155 ;
V_149 = F_72 ( V_155 ) ;
break;
case 2 :
V_127 = V_156 ;
V_149 = F_72 ( V_156 ) ;
break;
case 3 :
V_127 = V_157 ;
V_149 = F_72 ( V_157 ) ;
break;
case 4 :
V_127 = V_158 ;
V_149 = F_72 ( V_158 ) ;
break;
case 5 :
V_127 = V_159 ;
V_149 = F_72 ( V_159 ) ;
break;
}
F_73 ( V_160 L_39 ,
V_161 , V_153 ) ;
V_152:
V_6 = F_64 ( V_1 , V_26 , & V_162 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
T_3 V_163 = V_127 -> V_164 ;
if ( V_163 >= V_1 -> V_134 -> V_165 ) {
F_74 ( L_40 ,
V_161 , V_163 ) ;
return - V_166 ;
}
V_6 = F_64 ( V_1 , V_26 + V_163 , V_127 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_74 ( L_41 ,
V_161 , V_163 ) ;
return - V_166 ;
}
V_163 ++ ;
V_1 -> V_167 = F_66 ( V_163 , V_1 -> V_167 ) ;
}
F_73 ( V_160 L_42 ,
V_161 ,
V_149 + 1 , V_1 -> V_134 -> V_165 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_134 -> V_135 + 2 ) ) ) ;
if ( ! V_1 -> V_139 ) {
F_74 ( L_43 , V_161 ) ;
return - V_166 ;
}
return 0 ;
}
static int T_6 F_75 ( struct V_1 * V_1 )
{
T_3 V_31 = 0 ;
struct V_25 * V_26 ;
void * V_54 = V_1 -> V_36 ;
int V_12 = 0 ;
F_11 ( V_1 -> V_30 , L_44 ) ;
for ( V_31 = 1 ; V_31 < V_1 -> V_134 -> V_165 ; V_31 ++ ) {
F_23 ( V_54 , V_31 ) ;
V_26 = V_1 -> V_35 + V_31 ;
V_12 = F_76 ( V_1 , V_26 , V_31 ) ;
if ( V_12 < 0 )
break;
if ( V_26 -> V_143 < 512
|| V_26 -> V_146 < 512 )
continue;
if ( V_1 -> V_139 )
continue;
V_1 -> V_139 = V_26 ;
}
if ( ! V_1 -> V_139 ) {
F_74 ( L_43 , V_161 ) ;
return - V_166 ;
}
return 0 ;
}
static int T_6 F_77 ( T_4 V_168 , struct V_1 * V_1 )
{
T_3 V_55 ;
char * type ;
char V_169 [ 90 ] , V_170 [ 32 ] , V_171 [ 12 ] ;
void T_2 * V_54 = V_1 -> V_36 ;
int V_172 = 0 ;
int V_9 ;
V_55 = F_78 ( V_54 ) ;
strcpy ( V_169 , ( V_55 & V_173 ) ? L_45 : L_46 ) ;
if ( V_55 & V_174 ) {
strcat ( V_169 , L_47 ) ;
V_1 -> V_175 = true ;
}
if ( V_55 & V_176 ) {
strcat ( V_169 , L_48 ) ;
V_1 -> V_177 = true ;
}
if ( V_55 & V_178 ) {
strcat ( V_169 , L_49 ) ;
V_1 -> V_179 = true ;
}
if ( V_55 & V_180 ) {
strcat ( V_169 , L_50 ) ;
V_1 -> V_181 = true ;
}
if ( V_55 & V_182 ) {
strcat ( V_169 , L_51 ) ;
V_1 -> V_183 = true ;
}
if ( V_55 & V_184 )
strcat ( V_169 , L_52 ) ;
F_73 ( V_160 L_53 ,
V_161 , V_55 , V_169 ) ;
V_171 [ 0 ] = 0 ;
if ( V_185 == V_168 ) {
V_1 -> V_186 = 1 ;
type = L_54 ;
} else {
V_1 -> V_186 = 0 ;
type = L_55 ;
#ifndef F_79
F_73 ( V_187
L_56 ,
V_161 ) ;
#endif
}
V_1 -> V_188 = F_80 ( V_54 ) ;
snprintf ( V_170 , 32 , L_57 , F_81 ( V_1 -> V_188 ) ,
F_82 ( V_1 -> V_188 ) ,
( V_1 -> V_188 & V_189 ) ? L_58 : L_55 ) ;
F_73 ( V_160 L_59 ,
V_161 , type , V_170 , V_171 ) ;
F_83 ( V_1 ) ;
V_1 -> V_167 = 1 ;
V_1 -> V_104 = 1 ;
if ( V_1 -> V_175 )
V_172 = F_71 ( V_1 ) ;
else
V_172 = F_75 ( V_1 ) ;
if ( V_172 < 0 )
return V_172 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_167 ; V_9 ++ ) {
struct V_25 * V_26 = V_1 -> V_35 + V_9 ;
V_26 -> V_29 = F_84 ( V_9 ) + V_54 ;
#if F_85 ( V_190 ) || F_85 ( V_191 )
V_26 -> V_192 = V_1 -> V_193 + 0x400 + F_84 ( V_9 ) ;
V_26 -> V_194 = V_1 -> V_195 + 0x400 + F_84 ( V_9 ) ;
V_26 -> V_196 =
V_1 -> V_197 + 0x400 + F_84 ( V_9 ) ;
if ( V_9 == 0 )
V_26 -> V_198 = V_54 - 0x400 + V_199 ;
else
V_26 -> V_198 = V_54 + 0x400 + ( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
#endif
V_26 -> V_34 = F_86 ( V_9 , 0 ) + V_54 ;
V_26 -> V_200 = F_87 ( V_9 , V_54 ) ;
V_26 -> V_201 = 1 ;
V_26 -> V_202 = 1 ;
if ( V_26 -> V_143 ) {
F_11 ( V_1 -> V_30 ,
L_60 ,
V_161 , V_9 ,
V_26 -> V_148 ? L_61 : L_62 ,
V_26 -> V_142
? L_63 : L_55 ,
V_26 -> V_143 ) ;
}
if ( V_26 -> V_146 && ! V_26 -> V_148 ) {
F_11 ( V_1 -> V_30 ,
L_60 ,
V_161 , V_9 ,
L_64 ,
V_26 -> V_145
? L_63 : L_55 ,
V_26 -> V_146 ) ;
}
if ( ! ( V_26 -> V_143 || V_26 -> V_146 ) )
F_11 ( V_1 -> V_30 , L_65 , V_9 ) ;
}
return 0 ;
}
static T_5 F_88 ( int V_203 , void * V_204 )
{
unsigned long V_41 ;
T_5 V_205 = V_67 ;
struct V_1 * V_1 = V_204 ;
F_25 ( & V_1 -> V_42 , V_41 ) ;
V_1 -> V_62 = F_5 ( V_1 -> V_36 , V_121 ) ;
V_1 -> V_206 = F_19 ( V_1 -> V_36 , V_122 ) ;
V_1 -> V_207 = F_19 ( V_1 -> V_36 , V_123 ) ;
if ( V_1 -> V_62 || V_1 -> V_206 || V_1 -> V_207 )
V_205 = F_89 ( V_1 ) ;
F_29 ( & V_1 -> V_42 , V_41 ) ;
return V_205 ;
}
T_5 F_89 ( struct V_1 * V_1 )
{
T_5 V_205 = V_67 ;
T_3 V_63 , V_11 ;
int V_208 ;
T_1 V_55 ;
V_63 = F_5 ( V_1 -> V_36 , V_84 ) ;
V_11 = F_5 ( V_1 -> V_36 , V_14 ) ;
F_11 ( V_1 -> V_30 , L_66 ,
( V_63 & V_70 ) ? L_13 : L_14 ,
V_1 -> V_62 , V_1 -> V_206 , V_1 -> V_207 ) ;
if ( V_1 -> V_62 )
V_205 |= F_33 ( V_1 , V_1 -> V_62 ,
V_63 , V_11 ) ;
if ( V_1 -> V_206 & 1 ) {
if ( V_63 & V_70 )
V_205 |= F_90 ( V_1 ) ;
else
V_205 |= F_91 ( V_1 ) ;
}
V_55 = V_1 -> V_207 >> 1 ;
V_208 = 1 ;
while ( V_55 ) {
if ( V_55 & 1 ) {
V_205 = V_69 ;
if ( V_63 & V_70 ) {
if ( F_48 () )
F_92 ( V_1 , V_208 ) ;
} else {
if ( F_50 () )
F_93 ( V_1 , V_208 ) ;
}
}
V_55 >>= 1 ;
V_208 ++ ;
}
V_55 = V_1 -> V_206 >> 1 ;
V_208 = 1 ;
while ( V_55 ) {
if ( V_55 & 1 ) {
V_205 = V_69 ;
if ( V_63 & V_70 ) {
if ( F_48 () )
F_94 ( V_1 , V_208 ) ;
} else {
if ( F_50 () )
F_95 ( V_1 , V_208 ) ;
}
}
V_55 >>= 1 ;
V_208 ++ ;
}
return V_205 ;
}
void F_96 ( struct V_1 * V_1 , T_3 V_31 , T_3 V_209 )
{
T_3 V_63 = F_5 ( V_1 -> V_36 , V_84 ) ;
if ( ! V_31 ) {
#ifndef F_97
if ( ! F_98 () ) {
if ( V_63 & V_70 )
F_90 ( V_1 ) ;
else
F_91 ( V_1 ) ;
}
#endif
} else {
if ( V_209 ) {
if ( V_63 & V_70 ) {
if ( F_48 () )
F_94 ( V_1 , V_31 ) ;
} else {
if ( F_50 () )
F_95 ( V_1 , V_31 ) ;
}
} else {
if ( V_63 & V_70 ) {
if ( F_48 () )
F_92 ( V_1 , V_31 ) ;
} else {
if ( F_50 () )
F_93 ( V_1 , V_31 ) ;
}
}
}
}
static T_7
F_99 ( struct V_2 * V_3 , struct V_210 * V_211 , char * V_212 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
int V_12 = - V_166 ;
F_25 ( & V_1 -> V_42 , V_41 ) ;
V_12 = sprintf ( V_212 , L_67 , F_27 ( V_1 -> V_43 -> V_44 ) ) ;
F_29 ( & V_1 -> V_42 , V_41 ) ;
return V_12 ;
}
static T_7
F_100 ( struct V_2 * V_3 , struct V_210 * V_211 ,
const char * V_212 , T_8 V_149 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
int V_172 ;
F_25 ( & V_1 -> V_42 , V_41 ) ;
if ( F_101 ( V_212 , L_13 ) )
V_172 = F_102 ( V_1 , V_213 ) ;
else if ( F_101 ( V_212 , L_14 ) )
V_172 = F_102 ( V_1 , V_214 ) ;
else if ( F_101 ( V_212 , L_68 ) )
V_172 = F_102 ( V_1 , V_215 ) ;
else
V_172 = - V_166 ;
F_29 ( & V_1 -> V_42 , V_41 ) ;
return ( V_172 == 0 ) ? V_149 : V_172 ;
}
static T_7
F_103 ( struct V_2 * V_3 , struct V_210 * V_211 ,
const char * V_212 , T_8 V_149 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
unsigned long V_216 ;
if ( sscanf ( V_212 , L_69 , & V_216 ) < 1 ) {
F_104 ( V_3 , L_70 ) ;
return - V_166 ;
}
F_25 ( & V_1 -> V_42 , V_41 ) ;
V_1 -> V_95 = V_216 ? F_105 ( int , V_216 , V_96 ) : 0 ;
if ( V_1 -> V_43 -> V_44 == V_49 )
V_1 -> V_47 = 0 ;
F_40 ( V_1 , V_76 + F_34 ( V_216 ) ) ;
F_29 ( & V_1 -> V_42 , V_41 ) ;
return V_149 ;
}
static T_7
F_106 ( struct V_2 * V_3 , struct V_210 * V_211 , char * V_212 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
unsigned long V_216 ;
int V_217 ;
F_25 ( & V_1 -> V_42 , V_41 ) ;
V_216 = V_1 -> V_95 ;
V_217 = F_107 ( V_1 ) ;
F_29 ( & V_1 -> V_42 , V_41 ) ;
return sprintf ( V_212 , L_71 ,
V_217 ? L_72 : L_73 , V_216 ) ;
}
static T_7
F_108 ( struct V_2 * V_3 , struct V_210 * V_211 ,
const char * V_212 , T_8 V_149 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_218 ;
if ( sscanf ( V_212 , L_74 , & V_218 ) != 1
|| ( V_218 != 1 ) ) {
F_104 ( V_3 , L_75 ) ;
return - V_166 ;
}
if ( V_218 == 1 )
F_109 ( V_1 ) ;
return V_149 ;
}
static void F_110 ( struct V_219 * V_24 )
{
struct V_1 * V_1 = F_111 ( V_24 , struct V_1 , V_116 ) ;
static int V_220 ;
if ( V_1 -> V_43 -> V_44 != V_220 ) {
V_220 = V_1 -> V_43 -> V_44 ;
F_112 ( & V_1 -> V_30 -> V_221 , NULL , L_76 ) ;
}
}
static struct V_1 * T_6
F_113 ( struct V_2 * V_3 ,
struct V_222 * V_134 , void T_2 * V_54 )
{
struct V_1 * V_1 ;
struct V_25 * V_223 ;
int V_31 ;
struct V_52 * V_53 ;
V_53 = F_114 ( & V_224 , V_3 , F_115 ( V_3 ) ) ;
if ( ! V_53 )
return NULL ;
V_1 = F_116 ( V_53 ) ;
F_117 ( & V_1 -> V_225 ) ;
F_117 ( & V_1 -> V_226 ) ;
F_117 ( & V_1 -> V_227 ) ;
V_53 -> V_228 = 1 ;
V_53 -> V_229 = 1 ;
V_1 -> V_92 = V_230 ;
V_1 -> V_95 = V_96 ;
F_118 ( V_3 , V_1 ) ;
V_1 -> V_36 = V_54 ;
V_1 -> V_231 = V_54 ;
V_1 -> V_232 = - V_233 ;
V_1 -> V_134 = V_134 ;
F_119 ( V_1 -> V_134 -> V_165 > V_234 ) ;
for ( V_31 = 0 , V_223 = V_1 -> V_35 ;
V_31 < V_1 -> V_134 -> V_165 ;
V_31 ++ , V_223 ++ ) {
V_223 -> V_1 = V_1 ;
V_223 -> V_31 = V_31 ;
}
V_1 -> V_30 = V_3 ;
return V_1 ;
}
static void F_120 ( struct V_1 * V_1 )
{
#ifdef F_121
F_122 ( & V_1 -> V_30 -> V_221 , & V_235 ) ;
#endif
if ( V_1 -> V_232 >= 0 ) {
if ( V_1 -> V_236 )
F_123 ( V_1 -> V_232 ) ;
F_124 ( V_1 -> V_232 , V_1 ) ;
}
if ( F_125 () && V_1 -> V_237 ) {
struct V_237 * V_238 = V_1 -> V_237 ;
( void ) V_238 -> V_239 ( V_238 ) ;
F_126 ( V_238 ) ;
}
F_127 ( V_1 ) ;
}
static int T_6
F_128 ( struct V_2 * V_3 , int V_232 , void T_2 * V_240 )
{
int V_172 ;
struct V_1 * V_1 ;
struct V_241 * V_242 = V_3 -> V_243 ;
if ( ! V_242 ) {
F_11 ( V_3 , L_77 ) ;
V_172 = - V_233 ;
goto V_244;
}
V_1 = F_113 ( V_3 , V_242 -> V_134 , V_240 ) ;
if ( ! V_1 ) {
V_172 = - V_245 ;
goto V_244;
}
F_129 ( V_1 -> V_30 ) ;
F_130 ( V_1 -> V_30 , 200 ) ;
F_131 ( V_1 -> V_30 ) ;
F_132 ( & V_1 -> V_42 ) ;
V_1 -> V_246 = V_242 -> V_132 ;
V_1 -> V_247 = V_242 -> V_248 ;
V_1 -> V_249 = V_242 -> V_249 ;
V_1 -> V_250 = V_242 -> V_251 ;
V_1 -> V_252 = F_88 ;
V_172 = F_133 ( V_1 ) ;
if ( V_172 < 0 )
goto V_253;
if ( ! V_1 -> V_252 ) {
V_172 = - V_233 ;
goto V_254;
}
if ( ! V_1 -> V_43 -> V_255 ) {
V_1 -> V_43 -> V_13 = V_1 -> V_30 ;
V_1 -> V_43 -> V_8 = V_1 -> V_36 ;
V_1 -> V_43 -> V_255 = & V_256 ;
}
F_4 ( V_1 -> V_30 ) ;
#ifndef F_134
if ( V_257 && V_3 -> V_258 ) {
struct V_237 * V_238 ;
V_238 = F_135 ( V_1 , V_1 -> V_36 ) ;
V_1 -> V_237 = V_238 ;
if ( V_238 )
( void ) V_238 -> V_259 ( V_238 ) ;
}
#endif
if ( ! F_125 () || ! V_1 -> V_237 )
V_3 -> V_258 = NULL ;
F_59 ( V_1 ) ;
F_57 ( V_1 ) ;
V_172 = F_77 ( V_242 -> V_134 -> V_260
? V_185
: V_261 , V_1 ) ;
if ( V_172 < 0 )
goto V_262;
F_136 ( & V_1 -> V_99 , F_24 , ( unsigned long ) V_1 ) ;
F_137 ( & V_1 -> V_116 , F_110 ) ;
if ( F_138 ( V_232 , V_1 -> V_252 , 0 , F_115 ( V_3 ) , V_1 ) ) {
F_104 ( V_3 , L_78 , V_232 ) ;
V_172 = - V_233 ;
goto V_262;
}
V_1 -> V_232 = V_232 ;
if ( F_139 ( V_232 ) == 0 ) {
V_1 -> V_236 = 1 ;
F_140 ( V_3 , 1 ) ;
} else {
V_1 -> V_236 = 0 ;
}
if ( F_55 ( V_1 ) ) {
struct V_52 * V_53 = F_31 ( V_1 ) ;
F_141 ( V_1 -> V_43 -> V_65 , & V_53 -> V_58 ) ;
if ( F_42 ( V_1 ) )
V_53 -> V_58 . V_263 = 1 ;
V_1 -> V_43 -> V_65 -> V_101 = & V_53 -> V_58 ;
V_53 -> V_264 = 2 * ( V_242 -> V_11 ? : 250 ) ;
if ( V_242 -> V_265 ) {
T_3 V_266 = F_142 ( V_1 -> V_36 ) ;
V_266 |= V_267 ;
F_143 ( V_1 -> V_36 , V_266 ) ;
}
}
if ( ! F_42 ( V_1 ) && F_55 ( V_1 ) ) {
struct V_52 * V_53 = F_31 ( V_1 ) ;
F_38 ( V_1 ) ;
V_1 -> V_43 -> V_65 -> V_268 = 1 ;
V_1 -> V_43 -> V_44 = V_88 ;
V_172 = F_144 ( F_31 ( V_1 ) , 0 , 0 ) ;
V_53 -> V_58 . V_269 = 1 ;
F_11 ( V_1 -> V_30 , L_79 ,
L_80 , V_172 ,
F_5 ( V_1 -> V_36 , V_84 ) ,
( F_5 ( V_1 -> V_36 , V_84 )
& V_83
? 'B' : 'A' ) ) ;
} else {
F_32 ( V_1 ) ;
V_1 -> V_43 -> V_65 -> V_268 = 0 ;
V_1 -> V_43 -> V_44 = V_81 ;
V_172 = F_145 ( V_1 ) ;
F_11 ( V_1 -> V_30 , L_81 ,
F_42 ( V_1 ) ? L_82 : L_83 ,
V_172 ,
F_5 ( V_1 -> V_36 , V_84 ) ) ;
}
if ( V_172 < 0 )
goto V_262;
V_172 = F_146 ( V_1 ) ;
if ( V_172 < 0 )
goto V_270;
#ifdef F_121
V_172 = F_147 ( & V_1 -> V_30 -> V_221 , & V_235 ) ;
if ( V_172 )
goto V_271;
#endif
F_7 ( V_1 -> V_30 ) ;
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
V_271:
F_149 ( V_1 ) ;
V_270:
if ( ! F_42 ( V_1 ) && F_55 ( V_1 ) )
F_62 ( F_31 ( V_1 ) ) ;
else
F_61 ( V_1 ) ;
V_262:
F_150 ( V_1 -> V_30 ) ;
V_254:
if ( V_1 -> V_236 )
F_140 ( V_3 , 0 ) ;
F_63 ( V_1 ) ;
V_253:
F_104 ( V_1 -> V_30 ,
L_89 , V_172 ) ;
F_120 ( V_1 ) ;
V_244:
return V_172 ;
}
static int T_6 F_151 ( struct V_124 * V_125 )
{
struct V_2 * V_3 = & V_125 -> V_3 ;
int V_203 = F_152 ( V_125 , L_90 ) ;
int V_172 ;
struct V_272 * V_273 ;
void T_2 * V_274 ;
V_273 = F_153 ( V_125 , V_275 , 0 ) ;
if ( ! V_273 || V_203 <= 0 )
return - V_233 ;
V_274 = F_154 ( V_273 -> V_259 , F_155 ( V_273 ) ) ;
if ( ! V_274 ) {
F_104 ( V_3 , L_91 ) ;
return - V_245 ;
}
#ifndef F_134
V_276 = V_3 -> V_258 ;
#endif
V_172 = F_128 ( V_3 , V_203 , V_274 ) ;
if ( V_172 < 0 )
F_156 ( V_274 ) ;
return V_172 ;
}
static int T_9 F_157 ( struct V_124 * V_125 )
{
struct V_1 * V_1 = F_1 ( & V_125 -> V_3 ) ;
void T_2 * V_231 = V_1 -> V_231 ;
F_149 ( V_1 ) ;
F_60 ( V_125 ) ;
F_120 ( V_1 ) ;
F_156 ( V_231 ) ;
F_140 ( & V_125 -> V_3 , 0 ) ;
#ifndef F_134
V_125 -> V_3 . V_258 = V_276 ;
#endif
return 0 ;
}
static void F_158 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_277 = V_1 -> V_36 ;
void T_2 * V_278 ;
if ( F_55 ( V_1 ) ) {
V_1 -> V_279 . V_280 = F_19 ( V_277 , V_281 ) ;
V_1 -> V_279 . V_282 = F_5 ( V_277 , V_117 ) ;
V_1 -> V_279 . V_266 = F_142 ( V_1 -> V_36 ) ;
}
V_1 -> V_279 . V_11 = F_5 ( V_277 , V_14 ) ;
V_1 -> V_279 . V_283 = F_19 ( V_277 , V_103 ) ;
V_1 -> V_279 . V_284 = F_19 ( V_277 , V_105 ) ;
V_1 -> V_279 . V_285 = F_5 ( V_277 , V_106 ) ;
V_1 -> V_279 . V_32 = F_5 ( V_277 , V_138 ) ;
V_1 -> V_279 . V_63 = F_5 ( V_277 , V_84 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_134 -> V_165 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_278 = V_26 -> V_34 ;
if ( ! V_278 )
continue;
F_6 ( V_277 , V_138 , V_9 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_287 =
F_19 ( V_278 , V_288 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_289 =
F_19 ( V_278 , V_290 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_291 =
F_19 ( V_278 , V_292 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_293 =
F_19 ( V_278 , V_294 ) ;
if ( V_1 -> V_175 ) {
V_1 -> V_279 . V_286 [ V_9 ] . V_295 =
F_159 ( V_277 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_296 =
F_160 ( V_277 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_297 =
F_161 ( V_277 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_298 =
F_162 ( V_277 ) ;
}
if ( F_55 ( V_1 ) ) {
V_1 -> V_279 . V_286 [ V_9 ] . V_299 =
F_5 ( V_278 , V_300 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_301 =
F_5 ( V_278 , V_302 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_303 =
F_5 ( V_278 , V_304 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_305 =
F_5 ( V_278 , V_306 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_307 =
F_163 ( V_277 , V_9 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_308 =
F_164 ( V_277 , V_9 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_309 =
F_165 ( V_277 , V_9 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_310 =
F_166 ( V_277 , V_9 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_311 =
F_167 ( V_277 , V_9 ) ;
V_1 -> V_279 . V_286 [ V_9 ] . V_312 =
F_168 ( V_277 , V_9 ) ;
}
}
}
static void F_169 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_277 = V_1 -> V_36 ;
void T_2 * V_313 ;
void T_2 * V_278 ;
if ( F_55 ( V_1 ) ) {
F_14 ( V_277 , V_281 , V_1 -> V_279 . V_280 ) ;
F_6 ( V_277 , V_117 , V_1 -> V_279 . V_282 ) ;
F_143 ( V_1 -> V_36 , V_1 -> V_279 . V_266 ) ;
}
F_6 ( V_277 , V_14 , V_1 -> V_279 . V_11 ) ;
F_14 ( V_277 , V_103 , V_1 -> V_279 . V_283 ) ;
F_14 ( V_277 , V_105 , V_1 -> V_279 . V_284 ) ;
F_6 ( V_277 , V_106 , V_1 -> V_279 . V_285 ) ;
F_6 ( V_277 , V_84 , V_1 -> V_279 . V_63 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_134 -> V_165 ; ++ V_9 ) {
struct V_25 * V_26 ;
V_26 = & V_1 -> V_35 [ V_9 ] ;
if ( ! V_26 )
continue;
V_278 = V_26 -> V_34 ;
if ( ! V_278 )
continue;
F_6 ( V_277 , V_138 , V_9 ) ;
F_14 ( V_278 , V_288 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_287 ) ;
F_14 ( V_278 , V_290 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_289 ) ;
F_14 ( V_278 , V_292 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_291 ) ;
F_14 ( V_278 , V_294 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_293 ) ;
if ( V_1 -> V_175 ) {
F_67 ( V_277 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_297 ) ;
F_69 ( V_277 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_298 ) ;
F_68 ( V_277 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_295 ) ;
F_70 ( V_277 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_296 ) ;
}
if ( F_55 ( V_1 ) ) {
F_6 ( V_278 , V_300 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_299 ) ;
F_6 ( V_278 , V_302 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_301 ) ;
F_6 ( V_278 , V_304 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_303 ) ;
F_6 ( V_278 , V_306 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_305 ) ;
F_170 ( V_277 , V_9 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_307 ) ;
F_171 ( V_277 , V_9 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_308 ) ;
F_172 ( V_277 , V_9 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_309 ) ;
V_313 =
F_87 ( V_9 , V_277 ) ;
F_173 ( V_313 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_310 ) ;
F_174 ( V_313 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_311 ) ;
F_175 ( V_313 ,
V_1 -> V_279 . V_286 [ V_9 ] . V_312 ) ;
}
}
F_6 ( V_277 , V_138 , V_1 -> V_279 . V_32 ) ;
}
static int F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_41 ;
F_25 ( & V_1 -> V_42 , V_41 ) ;
if ( F_44 ( V_1 ) ) {
} else if ( F_177 ( V_1 ) ) {
}
F_29 ( & V_1 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_3 )
{
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
static int V_314 = 1 ;
if ( ! V_314 )
F_169 ( V_1 ) ;
V_314 = 0 ;
return 0 ;
}
static int T_10 F_181 ( void )
{
if ( F_182 () )
return 0 ;
F_183 ( L_92 V_315 L_93
L_94
L_93
L_95 ,
V_161 ) ;
return F_184 ( & V_316 ) ;
}
static void T_11 F_185 ( void )
{
F_186 ( & V_316 ) ;
}
