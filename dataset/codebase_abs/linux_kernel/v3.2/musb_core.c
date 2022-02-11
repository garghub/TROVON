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
F_42 ( V_98 , & V_50 -> V_38 ) ;
V_1 -> V_81 = V_82 ;
if ( F_43 ( V_1 ) ) {
}
F_12 ( V_1 -> V_33 , V_99 , V_1 -> V_100 ) ;
F_12 ( V_1 -> V_33 , V_101 , V_1 -> V_100 & 0xfffe ) ;
F_5 ( V_1 -> V_33 , V_102 , 0xf7 ) ;
V_1 -> V_57 &= ~ ( V_103
| V_104
| V_105
) ;
V_1 -> V_57 |= V_106
| ( V_58 << 16 ) ;
if ( V_60 & V_107 )
V_1 -> V_57 |= V_103 ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_43 :
if ( V_59 & V_66 ) {
F_9 ( V_1 -> V_27 , L_25 ) ;
V_59 &= ~ V_66 ;
goto V_108;
} else
F_9 ( V_1 -> V_27 , L_26 ) ;
break;
case V_42 :
F_9 ( V_1 -> V_27 , L_27 ) ;
V_108:
V_1 -> V_40 -> V_41 = V_54 ;
V_50 -> V_55 . V_56 = 1 ;
V_1 -> V_48 = 0 ;
F_44 ( & V_1 -> V_94 ) ;
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
if ( V_50 -> V_109 )
F_45 ( V_50 ) ;
else
F_33 ( V_50 ) ;
F_9 ( V_1 -> V_27 , L_28 ,
F_25 ( V_1 -> V_40 -> V_41 ) , V_60 ) ;
}
if ( ( V_59 & V_75 ) && ! V_1 -> V_48 ) {
F_9 ( V_1 -> V_27 , L_29 ,
F_25 ( V_1 -> V_40 -> V_41 ) ,
F_46 ( V_1 ) , V_60 ) ;
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
if ( V_59 & V_110 ) {
V_61 = V_64 ;
if ( F_47 () && ( V_60 & V_65 ) != 0 ) {
if ( V_60 & ( V_111 | V_107 ) )
F_9 ( V_1 -> V_27 , L_31 , V_60 ) ;
else {
F_48 ( L_32 ) ;
F_5 ( V_1 -> V_33 , V_79 , 0 ) ;
}
} else if ( F_49 () ) {
F_9 ( V_1 -> V_27 , L_33 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
switch ( V_1 -> V_40 -> V_41 ) {
case V_45 :
V_1 -> V_48 = 1 ;
F_50 ( V_1 ) ;
case V_46 :
F_9 ( V_1 -> V_27 , L_34 ,
F_25 ( V_1 -> V_40 -> V_41 ) ,
F_51 ( V_1 ) ) ;
F_41 ( & V_1 -> V_94 , V_71
+ F_32 ( F_51 ( V_1 ) ) ) ;
break;
case V_53 :
V_1 -> V_48 = 0 ;
F_44 ( & V_1 -> V_94 ) ;
F_50 ( V_1 ) ;
break;
case V_42 :
F_9 ( V_1 -> V_27 , L_35 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
V_1 -> V_40 -> V_41 = V_43 ;
F_50 ( V_1 ) ;
break;
case V_76 :
V_1 -> V_40 -> V_41 = V_43 ;
case V_43 :
F_50 ( V_1 ) ;
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
F_52 ( & V_1 -> V_112 ) ;
return V_61 ;
}
void F_53 ( struct V_1 * V_1 )
{
void T_2 * V_31 = V_1 -> V_33 ;
T_3 V_60 = F_4 ( V_31 , V_79 ) ;
F_9 ( V_1 -> V_27 , L_37 , V_60 ) ;
F_12 ( V_31 , V_99 , V_1 -> V_100 ) ;
F_12 ( V_31 , V_101 , V_1 -> V_100 & 0xfffe ) ;
F_5 ( V_31 , V_102 , 0xf7 ) ;
F_5 ( V_31 , V_113 , 0 ) ;
F_5 ( V_31 , V_12 , V_114
| V_115
) ;
V_1 -> V_44 = 0 ;
V_60 = F_4 ( V_31 , V_79 ) ;
V_60 &= ~ V_80 ;
if ( F_40 ( V_1 ) ) {
if ( ( V_60 & V_73 ) == V_73 )
V_1 -> V_44 = 1 ;
else
V_60 |= V_80 ;
} else if ( F_54 ( V_1 ) ) {
V_60 |= V_80 ;
} else {
if ( ( V_60 & V_73 ) == V_73 )
V_1 -> V_44 = 1 ;
}
F_55 ( V_1 ) ;
F_5 ( V_31 , V_79 , V_60 ) ;
}
static void F_56 ( struct V_1 * V_1 )
{
void T_2 * V_51 = V_1 -> V_33 ;
T_4 V_116 ;
F_5 ( V_51 , V_102 , 0 ) ;
F_12 ( V_51 , V_99 , 0 ) ;
F_12 ( V_51 , V_101 , 0 ) ;
F_5 ( V_51 , V_79 , 0 ) ;
V_116 = F_4 ( V_51 , V_117 ) ;
V_116 = F_17 ( V_51 , V_118 ) ;
V_116 = F_17 ( V_51 , V_119 ) ;
}
void F_57 ( struct V_1 * V_1 )
{
F_58 ( V_1 ) ;
F_56 ( V_1 ) ;
F_9 ( V_1 -> V_27 , L_38 ) ;
F_38 ( V_1 , 0 ) ;
}
static void F_59 ( struct V_120 * V_121 )
{
struct V_1 * V_1 = F_1 ( & V_121 -> V_3 ) ;
unsigned long V_38 ;
F_60 ( V_1 -> V_27 ) ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
F_58 ( V_1 ) ;
F_56 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
if ( ! F_40 ( V_1 ) && F_54 ( V_1 ) )
F_61 ( F_29 ( V_1 ) ) ;
F_5 ( V_1 -> V_33 , V_79 , 0 ) ;
F_62 ( V_1 ) ;
F_63 ( V_1 -> V_27 ) ;
}
static int T_6
F_64 ( struct V_1 * V_1 , struct V_22 * V_23 ,
const struct V_122 * V_123 , T_4 V_6 )
{
void T_2 * V_51 = V_1 -> V_33 ;
int V_124 = 0 ;
T_4 V_125 = V_123 -> V_125 ;
T_4 V_126 = V_6 >> 3 ;
T_3 V_127 ;
V_124 = F_65 ( F_66 ( V_125 , ( T_4 ) 8 ) ) - 1 ;
V_125 = 1 << V_124 ;
V_127 = V_124 - 3 ;
if ( V_123 -> V_128 == V_129 ) {
if ( ( V_6 + ( V_125 << 1 ) ) >
( 1 << ( V_1 -> V_130 -> V_131 + 2 ) ) )
return - V_132 ;
V_127 |= V_133 ;
} else {
if ( ( V_6 + V_125 ) > ( 1 << ( V_1 -> V_130 -> V_131 + 2 ) ) )
return - V_132 ;
}
F_5 ( V_51 , V_134 , V_23 -> V_28 ) ;
if ( V_23 -> V_28 == 1 )
V_1 -> V_135 = V_23 ;
switch ( V_123 -> V_136 ) {
case V_137 :
F_67 ( V_51 , V_127 ) ;
F_68 ( V_51 , V_126 ) ;
V_23 -> V_138 = ! ! ( V_127 & V_133 ) ;
V_23 -> V_139 = V_125 ;
break;
case V_140 :
F_69 ( V_51 , V_127 ) ;
F_70 ( V_51 , V_126 ) ;
V_23 -> V_141 = ! ! ( V_127 & V_133 ) ;
V_23 -> V_142 = V_125 ;
break;
case V_143 :
F_67 ( V_51 , V_127 ) ;
F_68 ( V_51 , V_126 ) ;
V_23 -> V_141 = ! ! ( V_127 & V_133 ) ;
V_23 -> V_142 = V_125 ;
F_69 ( V_51 , V_127 ) ;
F_70 ( V_51 , V_126 ) ;
V_23 -> V_138 = V_23 -> V_141 ;
V_23 -> V_139 = V_125 ;
V_23 -> V_144 = true ;
break;
}
V_1 -> V_100 |= ( 1 << V_23 -> V_28 ) ;
return V_6 + ( V_125 << ( ( V_127 & V_133 ) ? 1 : 0 ) ) ;
}
static int T_6 F_71 ( struct V_1 * V_1 )
{
const struct V_122 * V_123 ;
unsigned V_9 , V_145 ;
int V_6 ;
struct V_22 * V_23 = V_1 -> V_32 ;
if ( V_1 -> V_130 -> V_146 ) {
V_123 = V_1 -> V_130 -> V_146 ;
V_145 = V_1 -> V_130 -> V_147 ;
goto V_148;
}
switch ( V_149 ) {
default:
V_149 = 0 ;
case 0 :
V_123 = V_150 ;
V_145 = F_72 ( V_150 ) ;
break;
case 1 :
V_123 = V_151 ;
V_145 = F_72 ( V_151 ) ;
break;
case 2 :
V_123 = V_152 ;
V_145 = F_72 ( V_152 ) ;
break;
case 3 :
V_123 = V_153 ;
V_145 = F_72 ( V_153 ) ;
break;
case 4 :
V_123 = V_154 ;
V_145 = F_72 ( V_154 ) ;
break;
case 5 :
V_123 = V_155 ;
V_145 = F_72 ( V_155 ) ;
break;
}
F_73 ( V_156 L_39 ,
V_157 , V_149 ) ;
V_148:
V_6 = F_64 ( V_1 , V_23 , & V_158 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_145 ; V_9 ++ ) {
T_3 V_159 = V_123 -> V_160 ;
if ( V_159 >= V_1 -> V_130 -> V_161 ) {
F_74 ( L_40 ,
V_157 , V_159 ) ;
return - V_162 ;
}
V_6 = F_64 ( V_1 , V_23 + V_159 , V_123 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_74 ( L_41 ,
V_157 , V_159 ) ;
return - V_162 ;
}
V_159 ++ ;
V_1 -> V_163 = F_66 ( V_159 , V_1 -> V_163 ) ;
}
F_73 ( V_156 L_42 ,
V_157 ,
V_145 + 1 , V_1 -> V_130 -> V_161 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_130 -> V_131 + 2 ) ) ) ;
if ( ! V_1 -> V_135 ) {
F_74 ( L_43 , V_157 ) ;
return - V_162 ;
}
return 0 ;
}
static int T_6 F_75 ( struct V_1 * V_1 )
{
T_3 V_28 = 0 ;
struct V_22 * V_23 ;
void * V_51 = V_1 -> V_33 ;
int V_164 = 0 ;
F_9 ( V_1 -> V_27 , L_44 ) ;
for ( V_28 = 1 ; V_28 < V_1 -> V_130 -> V_161 ; V_28 ++ ) {
F_21 ( V_51 , V_28 ) ;
V_23 = V_1 -> V_32 + V_28 ;
V_164 = F_76 ( V_1 , V_23 , V_28 ) ;
if ( V_164 < 0 )
break;
if ( V_23 -> V_139 < 512
|| V_23 -> V_142 < 512 )
continue;
if ( V_1 -> V_135 )
continue;
V_1 -> V_135 = V_23 ;
}
if ( ! V_1 -> V_135 ) {
F_74 ( L_43 , V_157 ) ;
return - V_162 ;
}
return 0 ;
}
static int T_6 F_77 ( T_4 V_165 , struct V_1 * V_1 )
{
T_3 V_52 ;
char * type ;
char V_166 [ 90 ] , V_167 [ 32 ] , V_168 [ 12 ] ;
void T_2 * V_51 = V_1 -> V_33 ;
int V_169 = 0 ;
int V_9 ;
V_52 = F_78 ( V_51 ) ;
strcpy ( V_166 , ( V_52 & V_170 ) ? L_45 : L_46 ) ;
if ( V_52 & V_171 ) {
strcat ( V_166 , L_47 ) ;
V_1 -> V_172 = true ;
}
if ( V_52 & V_173 ) {
strcat ( V_166 , L_48 ) ;
V_1 -> V_174 = true ;
}
if ( V_52 & V_175 ) {
strcat ( V_166 , L_49 ) ;
V_1 -> V_176 = true ;
}
if ( V_52 & V_177 ) {
strcat ( V_166 , L_50 ) ;
V_1 -> V_178 = true ;
}
if ( V_52 & V_179 ) {
strcat ( V_166 , L_51 ) ;
V_1 -> V_180 = true ;
}
if ( V_52 & V_181 )
strcat ( V_166 , L_52 ) ;
F_73 ( V_156 L_53 ,
V_157 , V_52 , V_166 ) ;
V_168 [ 0 ] = 0 ;
if ( V_182 == V_165 ) {
V_1 -> V_183 = 1 ;
type = L_54 ;
} else {
V_1 -> V_183 = 0 ;
type = L_55 ;
#ifndef F_79
F_73 ( V_184
L_56 ,
V_157 ) ;
#endif
}
V_1 -> V_185 = F_80 ( V_51 ) ;
snprintf ( V_167 , 32 , L_57 , F_81 ( V_1 -> V_185 ) ,
F_82 ( V_1 -> V_185 ) ,
( V_1 -> V_185 & V_186 ) ? L_58 : L_55 ) ;
F_73 ( V_156 L_59 ,
V_157 , type , V_167 , V_168 ) ;
F_83 ( V_1 ) ;
V_1 -> V_163 = 1 ;
V_1 -> V_100 = 1 ;
if ( V_1 -> V_172 )
V_169 = F_71 ( V_1 ) ;
else
V_169 = F_75 ( V_1 ) ;
if ( V_169 < 0 )
return V_169 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_163 ; V_9 ++ ) {
struct V_22 * V_23 = V_1 -> V_32 + V_9 ;
V_23 -> V_26 = F_84 ( V_9 ) + V_51 ;
#ifdef F_85
V_23 -> V_187 = V_1 -> V_188 + 0x400 + F_84 ( V_9 ) ;
V_23 -> V_189 = V_1 -> V_190 + 0x400 + F_84 ( V_9 ) ;
V_23 -> V_191 =
V_1 -> V_192 + 0x400 + F_84 ( V_9 ) ;
if ( V_9 == 0 )
V_23 -> V_193 = V_51 - 0x400 + V_194 ;
else
V_23 -> V_193 = V_51 + 0x400 + ( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
#endif
V_23 -> V_31 = F_86 ( V_9 , 0 ) + V_51 ;
V_23 -> V_195 = F_87 ( V_9 , V_51 ) ;
V_23 -> V_196 = 1 ;
V_23 -> V_197 = 1 ;
if ( V_23 -> V_139 ) {
F_9 ( V_1 -> V_27 ,
L_60 ,
V_157 , V_9 ,
V_23 -> V_144 ? L_61 : L_62 ,
V_23 -> V_138
? L_63 : L_55 ,
V_23 -> V_139 ) ;
}
if ( V_23 -> V_142 && ! V_23 -> V_144 ) {
F_9 ( V_1 -> V_27 ,
L_60 ,
V_157 , V_9 ,
L_64 ,
V_23 -> V_141
? L_63 : L_55 ,
V_23 -> V_142 ) ;
}
if ( ! ( V_23 -> V_139 || V_23 -> V_142 ) )
F_9 ( V_1 -> V_27 , L_65 , V_9 ) ;
}
return 0 ;
}
static T_5 F_88 ( int V_198 , void * V_199 )
{
unsigned long V_38 ;
T_5 V_200 = V_62 ;
struct V_1 * V_1 = V_199 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_1 -> V_59 = F_4 ( V_1 -> V_33 , V_117 ) ;
V_1 -> V_201 = F_17 ( V_1 -> V_33 , V_118 ) ;
V_1 -> V_202 = F_17 ( V_1 -> V_33 , V_119 ) ;
if ( V_1 -> V_59 || V_1 -> V_201 || V_1 -> V_202 )
V_200 = F_89 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_200 ;
}
T_5 F_89 ( struct V_1 * V_1 )
{
T_5 V_200 = V_62 ;
T_3 V_60 , V_11 ;
int V_203 ;
T_1 V_52 ;
V_60 = F_4 ( V_1 -> V_33 , V_79 ) ;
V_11 = F_4 ( V_1 -> V_33 , V_12 ) ;
F_9 ( V_1 -> V_27 , L_66 ,
( V_60 & V_65 ) ? L_13 : L_14 ,
V_1 -> V_59 , V_1 -> V_201 , V_1 -> V_202 ) ;
if ( V_1 -> V_59 )
V_200 |= F_31 ( V_1 , V_1 -> V_59 ,
V_60 , V_11 ) ;
if ( V_1 -> V_201 & 1 ) {
if ( V_60 & V_65 )
V_200 |= F_90 ( V_1 ) ;
else
V_200 |= F_91 ( V_1 ) ;
}
V_52 = V_1 -> V_202 >> 1 ;
V_203 = 1 ;
while ( V_52 ) {
if ( V_52 & 1 ) {
V_200 = V_64 ;
if ( V_60 & V_65 ) {
if ( F_47 () )
F_92 ( V_1 , V_203 ) ;
} else {
if ( F_49 () )
F_93 ( V_1 , V_203 ) ;
}
}
V_52 >>= 1 ;
V_203 ++ ;
}
V_52 = V_1 -> V_201 >> 1 ;
V_203 = 1 ;
while ( V_52 ) {
if ( V_52 & 1 ) {
V_200 = V_64 ;
if ( V_60 & V_65 ) {
if ( F_47 () )
F_94 ( V_1 , V_203 ) ;
} else {
if ( F_49 () )
F_95 ( V_1 , V_203 ) ;
}
}
V_52 >>= 1 ;
V_203 ++ ;
}
return V_200 ;
}
void F_96 ( struct V_1 * V_1 , T_3 V_28 , T_3 V_204 )
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
if ( V_204 ) {
if ( V_60 & V_65 ) {
if ( F_47 () )
F_94 ( V_1 , V_28 ) ;
} else {
if ( F_49 () )
F_95 ( V_1 , V_28 ) ;
}
} else {
if ( V_60 & V_65 ) {
if ( F_47 () )
F_92 ( V_1 , V_28 ) ;
} else {
if ( F_49 () )
F_93 ( V_1 , V_28 ) ;
}
}
}
}
static T_7
F_99 ( struct V_2 * V_3 , struct V_205 * V_206 , char * V_207 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
int V_164 = - V_162 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_164 = sprintf ( V_207 , L_67 , F_25 ( V_1 -> V_40 -> V_41 ) ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_164 ;
}
static T_7
F_100 ( struct V_2 * V_3 , struct V_205 * V_206 ,
const char * V_207 , T_8 V_145 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
int V_169 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
if ( F_101 ( V_207 , L_13 ) )
V_169 = F_102 ( V_1 , V_208 ) ;
else if ( F_101 ( V_207 , L_14 ) )
V_169 = F_102 ( V_1 , V_209 ) ;
else if ( F_101 ( V_207 , L_68 ) )
V_169 = F_102 ( V_1 , V_210 ) ;
else
V_169 = - V_162 ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return ( V_169 == 0 ) ? V_145 : V_169 ;
}
static T_7
F_103 ( struct V_2 * V_3 , struct V_205 * V_206 ,
const char * V_207 , T_8 V_145 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
unsigned long V_211 ;
if ( sscanf ( V_207 , L_69 , & V_211 ) < 1 ) {
F_104 ( V_3 , L_70 ) ;
return - V_162 ;
}
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_1 -> V_90 = V_211 ? F_105 ( int , V_211 , V_91 ) : 0 ;
if ( V_1 -> V_40 -> V_41 == V_46 )
V_1 -> V_44 = 0 ;
F_38 ( V_1 , V_71 + F_32 ( V_211 ) ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_145 ;
}
static T_7
F_106 ( struct V_2 * V_3 , struct V_205 * V_206 , char * V_207 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
unsigned long V_211 ;
int V_212 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_211 = V_1 -> V_90 ;
V_212 = F_107 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return sprintf ( V_207 , L_71 ,
V_212 ? L_72 : L_73 , V_211 ) ;
}
static T_7
F_108 ( struct V_2 * V_3 , struct V_205 * V_206 ,
const char * V_207 , T_8 V_145 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_213 ;
if ( sscanf ( V_207 , L_74 , & V_213 ) != 1
|| ( V_213 != 1 ) ) {
F_104 ( V_3 , L_75 ) ;
return - V_162 ;
}
if ( V_213 == 1 )
F_109 ( V_1 ) ;
return V_145 ;
}
static void F_110 ( struct V_214 * V_21 )
{
struct V_1 * V_1 = F_111 ( V_21 , struct V_1 , V_112 ) ;
static int V_215 ;
if ( V_1 -> V_40 -> V_41 != V_215 ) {
V_215 = V_1 -> V_40 -> V_41 ;
F_112 ( & V_1 -> V_27 -> V_216 , NULL , L_76 ) ;
}
}
static struct V_1 * T_6
F_113 ( struct V_2 * V_3 ,
struct V_217 * V_130 , void T_2 * V_51 )
{
struct V_1 * V_1 ;
struct V_22 * V_218 ;
int V_28 ;
struct V_49 * V_50 ;
V_50 = F_114 ( & V_219 , V_3 , F_115 ( V_3 ) ) ;
if ( ! V_50 )
return NULL ;
V_1 = F_116 ( V_50 ) ;
F_117 ( & V_1 -> V_220 ) ;
F_117 ( & V_1 -> V_221 ) ;
F_117 ( & V_1 -> V_222 ) ;
V_50 -> V_223 = 1 ;
V_50 -> V_224 = 1 ;
V_1 -> V_87 = V_225 ;
V_1 -> V_90 = V_91 ;
F_118 ( V_3 , V_1 ) ;
V_1 -> V_33 = V_51 ;
V_1 -> V_226 = V_51 ;
V_1 -> V_227 = - V_228 ;
V_1 -> V_130 = V_130 ;
F_119 ( V_1 -> V_130 -> V_161 > V_229 ) ;
for ( V_28 = 0 , V_218 = V_1 -> V_32 ;
V_28 < V_1 -> V_130 -> V_161 ;
V_28 ++ , V_218 ++ ) {
V_218 -> V_1 = V_1 ;
V_218 -> V_28 = V_28 ;
}
V_1 -> V_27 = V_3 ;
return V_1 ;
}
static void F_120 ( struct V_1 * V_1 )
{
#ifdef F_121
F_122 ( & V_1 -> V_27 -> V_216 , & V_230 ) ;
#endif
F_123 ( V_1 ) ;
if ( V_1 -> V_227 >= 0 ) {
if ( V_1 -> V_231 )
F_124 ( V_1 -> V_227 ) ;
F_125 ( V_1 -> V_227 , V_1 ) ;
}
if ( F_126 () && V_1 -> V_232 ) {
struct V_232 * V_233 = V_1 -> V_232 ;
( void ) V_233 -> V_234 ( V_233 ) ;
F_127 ( V_233 ) ;
}
F_128 ( V_1 ) ;
}
static int T_6
F_129 ( struct V_2 * V_3 , int V_227 , void T_2 * V_235 )
{
int V_169 ;
struct V_1 * V_1 ;
struct V_236 * V_237 = V_3 -> V_238 ;
if ( ! V_237 ) {
F_9 ( V_3 , L_77 ) ;
V_169 = - V_228 ;
goto V_239;
}
V_1 = F_113 ( V_3 , V_237 -> V_130 , V_235 ) ;
if ( ! V_1 ) {
V_169 = - V_240 ;
goto V_239;
}
F_130 ( V_1 -> V_27 ) ;
F_131 ( V_1 -> V_27 , 200 ) ;
F_132 ( V_1 -> V_27 ) ;
F_133 ( & V_1 -> V_39 ) ;
V_1 -> V_241 = V_237 -> V_128 ;
V_1 -> V_242 = V_237 -> V_243 ;
V_1 -> V_244 = V_237 -> V_244 ;
V_1 -> V_245 = V_237 -> V_246 ;
V_1 -> V_247 = F_88 ;
V_169 = F_134 ( V_1 ) ;
if ( V_169 < 0 )
goto V_248;
if ( ! V_1 -> V_247 ) {
V_169 = - V_228 ;
goto V_249;
}
if ( ! V_1 -> V_40 -> V_250 ) {
V_1 -> V_40 -> V_8 = V_1 -> V_33 ;
V_1 -> V_40 -> V_250 = & V_251 ;
}
#ifndef F_135
if ( V_252 && V_3 -> V_253 ) {
struct V_232 * V_233 ;
V_233 = F_136 ( V_1 , V_1 -> V_33 ) ;
V_1 -> V_232 = V_233 ;
if ( V_233 )
( void ) V_233 -> V_254 ( V_233 ) ;
}
#endif
if ( ! F_126 () || ! V_1 -> V_232 )
V_3 -> V_253 = NULL ;
F_58 ( V_1 ) ;
F_56 ( V_1 ) ;
V_169 = F_77 ( V_237 -> V_130 -> V_255
? V_182
: V_256 , V_1 ) ;
if ( V_169 < 0 )
goto V_249;
F_137 ( & V_1 -> V_94 , F_22 , ( unsigned long ) V_1 ) ;
F_138 ( & V_1 -> V_112 , F_110 ) ;
if ( F_139 ( V_227 , V_1 -> V_247 , 0 , F_115 ( V_3 ) , V_1 ) ) {
F_104 ( V_3 , L_78 , V_227 ) ;
V_169 = - V_228 ;
goto V_249;
}
V_1 -> V_227 = V_227 ;
if ( F_140 ( V_227 ) == 0 ) {
V_1 -> V_231 = 1 ;
F_141 ( V_3 , 1 ) ;
} else {
V_1 -> V_231 = 0 ;
}
if ( F_54 ( V_1 ) ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
F_142 ( V_1 -> V_40 , & V_50 -> V_55 ) ;
if ( F_40 ( V_1 ) )
V_50 -> V_55 . V_257 = 1 ;
V_1 -> V_40 -> V_96 = & V_50 -> V_55 ;
V_50 -> V_258 = 2 * ( V_237 -> V_11 ? : 250 ) ;
if ( V_237 -> V_259 ) {
T_3 V_260 = F_143 ( V_1 -> V_33 ) ;
V_260 |= V_261 ;
F_144 ( V_1 -> V_33 , V_260 ) ;
}
}
if ( ! F_40 ( V_1 ) && F_54 ( V_1 ) ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
F_36 ( V_1 ) ;
V_1 -> V_40 -> V_262 = 1 ;
V_1 -> V_40 -> V_41 = V_83 ;
V_169 = F_145 ( F_29 ( V_1 ) , - 1 , 0 ) ;
V_50 -> V_55 . V_263 = 1 ;
F_9 ( V_1 -> V_27 , L_79 ,
L_80 , V_169 ,
F_4 ( V_1 -> V_33 , V_79 ) ,
( F_4 ( V_1 -> V_33 , V_79 )
& V_78
? 'B' : 'A' ) ) ;
} else {
F_30 ( V_1 ) ;
V_1 -> V_40 -> V_262 = 0 ;
V_1 -> V_40 -> V_41 = V_76 ;
V_169 = F_146 ( V_1 ) ;
F_9 ( V_1 -> V_27 , L_81 ,
F_40 ( V_1 ) ? L_82 : L_83 ,
V_169 ,
F_4 ( V_1 -> V_33 , V_79 ) ) ;
}
if ( V_169 < 0 )
goto V_249;
F_63 ( V_1 -> V_27 ) ;
V_169 = F_147 ( V_1 ) ;
if ( V_169 < 0 )
goto V_264;
#ifdef F_121
V_169 = F_148 ( & V_1 -> V_27 -> V_216 , & V_230 ) ;
if ( V_169 )
goto V_265;
#endif
F_149 (dev, L_84 ,
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
V_265:
F_150 ( V_1 ) ;
V_264:
if ( ! F_40 ( V_1 ) && F_54 ( V_1 ) )
F_61 ( F_29 ( V_1 ) ) ;
else
F_123 ( V_1 ) ;
V_249:
if ( V_1 -> V_231 )
F_141 ( V_3 , 0 ) ;
F_62 ( V_1 ) ;
V_248:
F_104 ( V_1 -> V_27 ,
L_89 , V_169 ) ;
F_120 ( V_1 ) ;
V_239:
return V_169 ;
}
static int T_6 F_151 ( struct V_120 * V_121 )
{
struct V_2 * V_3 = & V_121 -> V_3 ;
int V_198 = F_152 ( V_121 , L_90 ) ;
int V_169 ;
struct V_266 * V_267 ;
void T_2 * V_268 ;
V_267 = F_153 ( V_121 , V_269 , 0 ) ;
if ( ! V_267 || V_198 <= 0 )
return - V_228 ;
V_268 = F_154 ( V_267 -> V_254 , F_155 ( V_267 ) ) ;
if ( ! V_268 ) {
F_104 ( V_3 , L_91 ) ;
return - V_240 ;
}
#ifndef F_135
V_270 = V_3 -> V_253 ;
#endif
V_169 = F_129 ( V_3 , V_198 , V_268 ) ;
if ( V_169 < 0 )
F_156 ( V_268 ) ;
return V_169 ;
}
static int T_9 F_157 ( struct V_120 * V_121 )
{
struct V_1 * V_1 = F_1 ( & V_121 -> V_3 ) ;
void T_2 * V_226 = V_1 -> V_226 ;
F_60 ( V_1 -> V_27 ) ;
F_150 ( V_1 ) ;
F_59 ( V_121 ) ;
F_63 ( V_1 -> V_27 ) ;
F_120 ( V_1 ) ;
F_156 ( V_226 ) ;
F_141 ( & V_121 -> V_3 , 0 ) ;
#ifndef F_135
V_121 -> V_3 . V_253 = V_270 ;
#endif
return 0 ;
}
static void F_158 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_271 = V_1 -> V_33 ;
void T_2 * V_272 ;
if ( F_54 ( V_1 ) ) {
V_1 -> V_273 . V_274 = F_17 ( V_271 , V_275 ) ;
V_1 -> V_273 . V_276 = F_4 ( V_271 , V_113 ) ;
V_1 -> V_273 . V_260 = F_143 ( V_1 -> V_33 ) ;
}
V_1 -> V_273 . V_11 = F_4 ( V_271 , V_12 ) ;
V_1 -> V_273 . V_277 = F_17 ( V_271 , V_99 ) ;
V_1 -> V_273 . V_278 = F_17 ( V_271 , V_101 ) ;
V_1 -> V_273 . V_279 = F_4 ( V_271 , V_102 ) ;
V_1 -> V_273 . V_29 = F_4 ( V_271 , V_134 ) ;
V_1 -> V_273 . V_60 = F_4 ( V_271 , V_79 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_130 -> V_161 ; ++ V_9 ) {
struct V_22 * V_23 ;
V_23 = & V_1 -> V_32 [ V_9 ] ;
if ( ! V_23 )
continue;
V_272 = V_23 -> V_31 ;
if ( ! V_272 )
continue;
V_1 -> V_273 . V_280 [ V_9 ] . V_281 =
F_17 ( V_272 , V_282 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_283 =
F_17 ( V_272 , V_284 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_285 =
F_17 ( V_272 , V_286 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_287 =
F_17 ( V_272 , V_288 ) ;
if ( V_1 -> V_172 ) {
V_1 -> V_273 . V_280 [ V_9 ] . V_289 =
F_159 ( V_271 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_290 =
F_160 ( V_271 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_291 =
F_161 ( V_271 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_292 =
F_162 ( V_271 ) ;
}
if ( F_54 ( V_1 ) ) {
V_1 -> V_273 . V_280 [ V_9 ] . V_293 =
F_4 ( V_272 , V_294 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_295 =
F_4 ( V_272 , V_296 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_297 =
F_4 ( V_272 , V_298 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_299 =
F_4 ( V_272 , V_300 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_301 =
F_163 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_302 =
F_164 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_303 =
F_165 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_304 =
F_166 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_305 =
F_167 ( V_271 , V_9 ) ;
V_1 -> V_273 . V_280 [ V_9 ] . V_306 =
F_168 ( V_271 , V_9 ) ;
}
}
}
static void F_169 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_271 = V_1 -> V_33 ;
void T_2 * V_307 ;
void T_2 * V_272 ;
if ( F_54 ( V_1 ) ) {
F_12 ( V_271 , V_275 , V_1 -> V_273 . V_274 ) ;
F_5 ( V_271 , V_113 , V_1 -> V_273 . V_276 ) ;
F_144 ( V_1 -> V_33 , V_1 -> V_273 . V_260 ) ;
}
F_5 ( V_271 , V_12 , V_1 -> V_273 . V_11 ) ;
F_12 ( V_271 , V_99 , V_1 -> V_273 . V_277 ) ;
F_12 ( V_271 , V_101 , V_1 -> V_273 . V_278 ) ;
F_5 ( V_271 , V_102 , V_1 -> V_273 . V_279 ) ;
F_5 ( V_271 , V_79 , V_1 -> V_273 . V_60 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_130 -> V_161 ; ++ V_9 ) {
struct V_22 * V_23 ;
V_23 = & V_1 -> V_32 [ V_9 ] ;
if ( ! V_23 )
continue;
V_272 = V_23 -> V_31 ;
if ( ! V_272 )
continue;
F_12 ( V_272 , V_282 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_281 ) ;
F_12 ( V_272 , V_284 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_283 ) ;
F_12 ( V_272 , V_286 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_285 ) ;
F_12 ( V_272 , V_288 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_287 ) ;
if ( V_1 -> V_172 ) {
F_67 ( V_271 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_291 ) ;
F_69 ( V_271 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_292 ) ;
F_68 ( V_271 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_289 ) ;
F_70 ( V_271 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_290 ) ;
}
if ( F_54 ( V_1 ) ) {
F_5 ( V_272 , V_294 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_293 ) ;
F_5 ( V_272 , V_296 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_295 ) ;
F_5 ( V_272 , V_298 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_297 ) ;
F_5 ( V_272 , V_300 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_299 ) ;
F_170 ( V_271 , V_9 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_301 ) ;
F_171 ( V_271 , V_9 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_302 ) ;
F_172 ( V_271 , V_9 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_303 ) ;
V_307 =
F_87 ( V_9 , V_271 ) ;
F_173 ( V_307 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_304 ) ;
F_174 ( V_307 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_305 ) ;
F_175 ( V_307 ,
V_1 -> V_273 . V_280 [ V_9 ] . V_306 ) ;
}
}
F_5 ( V_271 , V_134 , V_1 -> V_273 . V_29 ) ;
}
static int F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
if ( F_43 ( V_1 ) ) {
} else if ( F_177 ( V_1 ) ) {
}
F_27 ( & V_1 -> V_39 , V_38 ) ;
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
static int V_308 = 1 ;
if ( ! V_308 )
F_169 ( V_1 ) ;
V_308 = 0 ;
return 0 ;
}
static int T_6 F_181 ( void )
{
if ( F_182 () )
return 0 ;
F_183 ( L_92 V_309 L_93
L_94
L_93
L_95 ,
V_157 ) ;
return F_184 ( & V_310 , F_151 ) ;
}
static void T_9 F_185 ( void )
{
F_186 ( & V_310 ) ;
}
