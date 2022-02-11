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
#ifdef F_32
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
+ F_33 ( 20 ) ;
V_1 -> V_40 -> V_41 = V_72 ;
V_1 -> V_44 = 1 ;
F_34 ( F_29 ( V_1 ) ) ;
break;
case V_42 :
V_1 -> V_40 -> V_41 = V_43 ;
V_1 -> V_44 = 1 ;
F_30 ( V_1 ) ;
break;
default:
F_35 ( L_12 ,
L_13 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
}
#endif
} else {
switch ( V_1 -> V_40 -> V_41 ) {
#ifdef F_32
case V_45 :
V_1 -> V_40 -> V_41 = V_72 ;
F_34 ( F_29 ( V_1 ) ) ;
break;
#endif
#ifdef F_36
case V_42 :
case V_43 :
if ( ( V_60 & V_73 )
!= ( 3 << V_74 )
) {
V_1 -> V_59 |= V_75 ;
V_1 -> V_59 &= ~ V_66 ;
break;
}
F_37 ( V_1 ) ;
break;
case V_76 :
V_1 -> V_59 &= ~ V_66 ;
break;
#endif
default:
F_35 ( L_12 ,
L_14 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
}
}
}
#ifdef F_32
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
F_38 ( V_1 ) ;
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
#endif
if ( V_59 & V_66 ) {
F_9 ( V_1 -> V_27 , L_22 ,
F_25 ( V_1 -> V_40 -> V_41 ) , V_60 , V_11 ) ;
V_61 = V_64 ;
switch ( V_1 -> V_40 -> V_41 ) {
#ifdef F_39
case V_53 :
F_28 ( V_1 ) ;
F_34 ( F_29 ( V_1 ) ) ;
F_40 ( V_1 ) ;
F_41 ( V_1 , V_71
+ F_33 ( V_1 -> V_90
? : V_91 ) ) ;
break;
#endif
case V_76 :
if ( ! V_1 -> V_44 )
break;
case V_43 :
F_42 ( V_1 ) ;
V_1 -> V_44 = F_43 ( V_1 )
&& V_1 -> V_40 -> V_92 -> V_93 ;
if ( V_1 -> V_44 ) {
#ifdef F_39
V_1 -> V_40 -> V_41 = V_42 ;
F_9 ( V_1 -> V_27 , L_23 ) ;
F_44 ( & V_1 -> V_94 , V_71
+ F_33 (
V_95 ) ) ;
#endif
}
break;
case V_46 :
if ( V_1 -> V_90 != 0 )
F_41 ( V_1 , V_71
+ F_33 ( V_1 -> V_90 ) ) ;
break;
case V_72 :
V_1 -> V_40 -> V_41 = V_45 ;
V_1 -> V_44 = F_43 ( V_1 )
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
#ifdef F_32
if ( V_59 & V_97 ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
V_61 = V_64 ;
V_1 -> V_44 = 1 ;
F_45 ( V_98 , & V_50 -> V_38 ) ;
V_1 -> V_81 = V_82 ;
#ifdef F_39
if ( F_46 ( V_1 ) ) {
}
F_12 ( V_1 -> V_33 , V_99 , V_1 -> V_100 ) ;
F_12 ( V_1 -> V_33 , V_101 , V_1 -> V_100 & 0xfffe ) ;
F_5 ( V_1 -> V_33 , V_102 , 0xf7 ) ;
#endif
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
F_47 ( & V_1 -> V_94 ) ;
break;
default:
if ( ( V_60 & V_73 )
== ( 3 << V_74 ) ) {
V_1 -> V_40 -> V_41 = V_72 ;
V_50 -> V_55 . V_56 = 0 ;
}
break;
}
F_38 ( V_1 ) ;
if ( V_50 -> V_109 )
F_48 ( V_50 ) ;
else
F_34 ( V_50 ) ;
F_9 ( V_1 -> V_27 , L_28 ,
F_25 ( V_1 -> V_40 -> V_41 ) , V_60 ) ;
}
#endif
if ( ( V_59 & V_75 ) && ! V_1 -> V_48 ) {
F_9 ( V_1 -> V_27 , L_29 ,
F_25 ( V_1 -> V_40 -> V_41 ) ,
F_49 ( V_1 ) , V_60 ) ;
V_61 = V_64 ;
switch ( V_1 -> V_40 -> V_41 ) {
#ifdef F_32
case V_72 :
case V_45 :
F_34 ( F_29 ( V_1 ) ) ;
F_40 ( V_1 ) ;
if ( V_1 -> V_90 != 0 && F_43 ( V_1 ) )
F_41 ( V_1 , V_71
+ F_33 ( V_1 -> V_90 ) ) ;
break;
#endif
#ifdef F_39
case V_54 :
F_40 ( V_1 ) ;
F_29 ( V_1 ) -> V_55 . V_56 = 0 ;
V_1 -> V_40 -> V_41 = V_43 ;
F_30 ( V_1 ) ;
F_24 ( V_1 ) ;
break;
case V_53 :
F_28 ( V_1 ) ;
F_40 ( V_1 ) ;
case V_42 :
#endif
#ifdef F_36
case V_43 :
case V_76 :
F_24 ( V_1 ) ;
break;
#endif
default:
F_35 ( L_30 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
break;
}
}
if ( V_59 & V_110 ) {
V_61 = V_64 ;
if ( F_50 () && ( V_60 & V_65 ) != 0 ) {
if ( V_60 & ( V_111 | V_107 ) )
F_9 ( V_1 -> V_27 , L_31 , V_60 ) ;
else {
F_51 ( L_32 ) ;
F_5 ( V_1 -> V_33 , V_79 , 0 ) ;
}
} else if ( F_52 () ) {
F_9 ( V_1 -> V_27 , L_33 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
switch ( V_1 -> V_40 -> V_41 ) {
#ifdef F_53
case V_45 :
V_1 -> V_48 = 1 ;
F_54 ( V_1 ) ;
case V_46 :
F_9 ( V_1 -> V_27 , L_34 ,
F_25 ( V_1 -> V_40 -> V_41 ) ,
F_55 ( V_1 ) ) ;
F_44 ( & V_1 -> V_94 , V_71
+ F_33 ( F_55 ( V_1 ) ) ) ;
break;
case V_53 :
V_1 -> V_48 = 0 ;
F_47 ( & V_1 -> V_94 ) ;
F_54 ( V_1 ) ;
break;
case V_42 :
F_9 ( V_1 -> V_27 , L_35 ,
F_25 ( V_1 -> V_40 -> V_41 ) ) ;
V_1 -> V_40 -> V_41 = V_43 ;
F_54 ( V_1 ) ;
break;
#endif
case V_76 :
V_1 -> V_40 -> V_41 = V_43 ;
case V_43 :
F_54 ( V_1 ) ;
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
F_56 ( & V_1 -> V_112 ) ;
return V_61 ;
}
void F_57 ( struct V_1 * V_1 )
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
| V_116
) ;
V_1 -> V_44 = 0 ;
V_60 = F_4 ( V_31 , V_79 ) ;
V_60 &= ~ V_80 ;
if ( F_43 ( V_1 ) ) {
if ( ( V_60 & V_73 ) == V_73 )
V_1 -> V_44 = 1 ;
else
V_60 |= V_80 ;
} else if ( F_58 ( V_1 ) ) {
V_60 |= V_80 ;
} else {
if ( ( V_60 & V_73 ) == V_73 )
V_1 -> V_44 = 1 ;
}
F_59 ( V_1 ) ;
F_5 ( V_31 , V_79 , V_60 ) ;
}
static void F_60 ( struct V_1 * V_1 )
{
void T_2 * V_51 = V_1 -> V_33 ;
T_4 V_117 ;
F_5 ( V_51 , V_102 , 0 ) ;
F_12 ( V_51 , V_99 , 0 ) ;
F_12 ( V_51 , V_101 , 0 ) ;
F_5 ( V_51 , V_79 , 0 ) ;
V_117 = F_4 ( V_51 , V_118 ) ;
V_117 = F_17 ( V_51 , V_119 ) ;
V_117 = F_17 ( V_51 , V_120 ) ;
}
void F_61 ( struct V_1 * V_1 )
{
F_62 ( V_1 ) ;
F_60 ( V_1 ) ;
F_9 ( V_1 -> V_27 , L_38 ) ;
F_41 ( V_1 , 0 ) ;
}
static void F_63 ( struct V_121 * V_122 )
{
struct V_1 * V_1 = F_1 ( & V_122 -> V_3 ) ;
unsigned long V_38 ;
F_64 ( V_1 -> V_27 ) ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
F_62 ( V_1 ) ;
F_60 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
if ( ! F_43 ( V_1 ) && F_58 ( V_1 ) )
F_65 ( F_29 ( V_1 ) ) ;
F_5 ( V_1 -> V_33 , V_79 , 0 ) ;
F_66 ( V_1 ) ;
F_67 ( V_1 -> V_27 ) ;
}
static int T_6
F_68 ( struct V_1 * V_1 , struct V_22 * V_23 ,
const struct V_123 * V_124 , T_4 V_6 )
{
void T_2 * V_51 = V_1 -> V_33 ;
int V_125 = 0 ;
T_4 V_126 = V_124 -> V_126 ;
T_4 V_127 = V_6 >> 3 ;
T_3 V_128 ;
V_125 = F_69 ( F_70 ( V_126 , ( T_4 ) 8 ) ) - 1 ;
V_126 = 1 << V_125 ;
V_128 = V_125 - 3 ;
if ( V_124 -> V_129 == V_130 ) {
if ( ( V_6 + ( V_126 << 1 ) ) >
( 1 << ( V_1 -> V_131 -> V_132 + 2 ) ) )
return - V_133 ;
V_128 |= V_134 ;
} else {
if ( ( V_6 + V_126 ) > ( 1 << ( V_1 -> V_131 -> V_132 + 2 ) ) )
return - V_133 ;
}
F_5 ( V_51 , V_135 , V_23 -> V_28 ) ;
#ifdef F_32
if ( V_23 -> V_28 == 1 )
V_1 -> V_136 = V_23 ;
#endif
switch ( V_124 -> V_137 ) {
case V_138 :
F_71 ( V_51 , V_128 ) ;
F_72 ( V_51 , V_127 ) ;
V_23 -> V_139 = ! ! ( V_128 & V_134 ) ;
V_23 -> V_140 = V_126 ;
break;
case V_141 :
F_73 ( V_51 , V_128 ) ;
F_74 ( V_51 , V_127 ) ;
V_23 -> V_142 = ! ! ( V_128 & V_134 ) ;
V_23 -> V_143 = V_126 ;
break;
case V_144 :
F_71 ( V_51 , V_128 ) ;
F_72 ( V_51 , V_127 ) ;
V_23 -> V_142 = ! ! ( V_128 & V_134 ) ;
V_23 -> V_143 = V_126 ;
F_73 ( V_51 , V_128 ) ;
F_74 ( V_51 , V_127 ) ;
V_23 -> V_139 = V_23 -> V_142 ;
V_23 -> V_140 = V_126 ;
V_23 -> V_145 = true ;
break;
}
V_1 -> V_100 |= ( 1 << V_23 -> V_28 ) ;
return V_6 + ( V_126 << ( ( V_128 & V_134 ) ? 1 : 0 ) ) ;
}
static int T_6 F_75 ( struct V_1 * V_1 )
{
const struct V_123 * V_124 ;
unsigned V_9 , V_146 ;
int V_6 ;
struct V_22 * V_23 = V_1 -> V_32 ;
if ( V_1 -> V_131 -> V_147 ) {
V_124 = V_1 -> V_131 -> V_147 ;
V_146 = V_1 -> V_131 -> V_148 ;
goto V_149;
}
switch ( V_150 ) {
default:
V_150 = 0 ;
case 0 :
V_124 = V_151 ;
V_146 = F_76 ( V_151 ) ;
break;
case 1 :
V_124 = V_152 ;
V_146 = F_76 ( V_152 ) ;
break;
case 2 :
V_124 = V_153 ;
V_146 = F_76 ( V_153 ) ;
break;
case 3 :
V_124 = V_154 ;
V_146 = F_76 ( V_154 ) ;
break;
case 4 :
V_124 = V_155 ;
V_146 = F_76 ( V_155 ) ;
break;
case 5 :
V_124 = V_156 ;
V_146 = F_76 ( V_156 ) ;
break;
}
F_77 ( V_157 L_39 ,
V_158 , V_150 ) ;
V_149:
V_6 = F_68 ( V_1 , V_23 , & V_159 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_146 ; V_9 ++ ) {
T_3 V_160 = V_124 -> V_161 ;
if ( V_160 >= V_1 -> V_131 -> V_162 ) {
F_78 ( L_40 ,
V_158 , V_160 ) ;
return - V_163 ;
}
V_6 = F_68 ( V_1 , V_23 + V_160 , V_124 ++ , V_6 ) ;
if ( V_6 < 0 ) {
F_78 ( L_41 ,
V_158 , V_160 ) ;
return - V_163 ;
}
V_160 ++ ;
V_1 -> V_164 = F_70 ( V_160 , V_1 -> V_164 ) ;
}
F_77 ( V_157 L_42 ,
V_158 ,
V_146 + 1 , V_1 -> V_131 -> V_162 * 2 - 1 ,
V_6 , ( 1 << ( V_1 -> V_131 -> V_132 + 2 ) ) ) ;
#ifdef F_32
if ( ! V_1 -> V_136 ) {
F_78 ( L_43 , V_158 ) ;
return - V_163 ;
}
#endif
return 0 ;
}
static int T_6 F_79 ( struct V_1 * V_1 )
{
T_3 V_28 = 0 ;
struct V_22 * V_23 ;
void * V_51 = V_1 -> V_33 ;
int V_165 = 0 ;
F_9 ( V_1 -> V_27 , L_44 ) ;
for ( V_28 = 1 ; V_28 < V_1 -> V_131 -> V_162 ; V_28 ++ ) {
F_21 ( V_51 , V_28 ) ;
V_23 = V_1 -> V_32 + V_28 ;
V_165 = F_80 ( V_1 , V_23 , V_28 ) ;
if ( V_165 < 0 )
break;
#ifdef F_32
if ( V_23 -> V_140 < 512
|| V_23 -> V_143 < 512 )
continue;
if ( V_1 -> V_136 )
continue;
V_1 -> V_136 = V_23 ;
#endif
}
#ifdef F_32
if ( ! V_1 -> V_136 ) {
F_78 ( L_43 , V_158 ) ;
return - V_163 ;
}
#endif
return 0 ;
}
static int T_6 F_81 ( T_4 V_166 , struct V_1 * V_1 )
{
T_3 V_52 ;
char * type ;
char V_167 [ 90 ] , V_168 [ 32 ] , V_169 [ 12 ] ;
void T_2 * V_51 = V_1 -> V_33 ;
int V_170 = 0 ;
int V_9 ;
V_52 = F_82 ( V_51 ) ;
strcpy ( V_167 , ( V_52 & V_171 ) ? L_45 : L_46 ) ;
if ( V_52 & V_172 ) {
strcat ( V_167 , L_47 ) ;
V_1 -> V_173 = true ;
}
if ( V_52 & V_174 ) {
strcat ( V_167 , L_48 ) ;
V_1 -> V_175 = true ;
}
if ( V_52 & V_176 ) {
strcat ( V_167 , L_49 ) ;
V_1 -> V_177 = true ;
}
if ( V_52 & V_178 ) {
strcat ( V_167 , L_50 ) ;
V_1 -> V_179 = true ;
}
if ( V_52 & V_180 ) {
strcat ( V_167 , L_51 ) ;
V_1 -> V_181 = true ;
}
if ( V_52 & V_182 )
strcat ( V_167 , L_52 ) ;
F_77 ( V_157 L_53 ,
V_158 , V_52 , V_167 ) ;
V_169 [ 0 ] = 0 ;
if ( V_183 == V_166 ) {
V_1 -> V_184 = 1 ;
type = L_54 ;
} else {
V_1 -> V_184 = 0 ;
type = L_55 ;
#ifdef F_32
#ifndef F_83
F_77 ( V_185
L_56 ,
V_158 ) ;
#endif
#endif
}
V_1 -> V_186 = F_84 ( V_51 ) ;
snprintf ( V_168 , 32 , L_57 , F_85 ( V_1 -> V_186 ) ,
F_86 ( V_1 -> V_186 ) ,
( V_1 -> V_186 & V_187 ) ? L_58 : L_55 ) ;
F_77 ( V_157 L_59 ,
V_158 , type , V_168 , V_169 ) ;
F_87 ( V_1 ) ;
V_1 -> V_164 = 1 ;
V_1 -> V_100 = 1 ;
if ( V_1 -> V_173 )
V_170 = F_75 ( V_1 ) ;
else
V_170 = F_79 ( V_1 ) ;
if ( V_170 < 0 )
return V_170 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_164 ; V_9 ++ ) {
struct V_22 * V_23 = V_1 -> V_32 + V_9 ;
V_23 -> V_26 = F_88 ( V_9 ) + V_51 ;
#ifdef F_89
V_23 -> V_188 = V_1 -> V_189 + 0x400 + F_88 ( V_9 ) ;
V_23 -> V_190 = V_1 -> V_191 + 0x400 + F_88 ( V_9 ) ;
V_23 -> V_192 =
V_1 -> V_193 + 0x400 + F_88 ( V_9 ) ;
if ( V_9 == 0 )
V_23 -> V_194 = V_51 - 0x400 + V_195 ;
else
V_23 -> V_194 = V_51 + 0x400 + ( ( ( V_9 - 1 ) & 0xf ) << 2 ) ;
#endif
V_23 -> V_31 = F_90 ( V_9 , 0 ) + V_51 ;
#ifdef F_32
V_23 -> V_196 = F_91 ( V_9 , V_51 ) ;
V_23 -> V_197 = 1 ;
V_23 -> V_198 = 1 ;
#endif
if ( V_23 -> V_140 ) {
F_9 ( V_1 -> V_27 ,
L_60 ,
V_158 , V_9 ,
V_23 -> V_145 ? L_61 : L_62 ,
V_23 -> V_139
? L_63 : L_55 ,
V_23 -> V_140 ) ;
}
if ( V_23 -> V_143 && ! V_23 -> V_145 ) {
F_9 ( V_1 -> V_27 ,
L_60 ,
V_158 , V_9 ,
L_64 ,
V_23 -> V_142
? L_63 : L_55 ,
V_23 -> V_143 ) ;
}
if ( ! ( V_23 -> V_140 || V_23 -> V_143 ) )
F_9 ( V_1 -> V_27 , L_65 , V_9 ) ;
}
return 0 ;
}
static T_5 F_92 ( int V_199 , void * V_200 )
{
unsigned long V_38 ;
T_5 V_201 = V_62 ;
struct V_1 * V_1 = V_200 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_1 -> V_59 = F_4 ( V_1 -> V_33 , V_118 ) ;
V_1 -> V_202 = F_17 ( V_1 -> V_33 , V_119 ) ;
V_1 -> V_203 = F_17 ( V_1 -> V_33 , V_120 ) ;
if ( V_1 -> V_59 || V_1 -> V_202 || V_1 -> V_203 )
V_201 = F_93 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_201 ;
}
T_5 F_93 ( struct V_1 * V_1 )
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
#ifdef F_36
if ( F_43 ( V_1 ) || F_94 ( V_1 ) )
if ( ! V_1 -> V_205 ) {
F_9 ( V_1 -> V_27 , L_67 ) ;
return V_64 ;
}
#endif
if ( V_1 -> V_59 )
V_201 |= F_31 ( V_1 , V_1 -> V_59 ,
V_60 , V_11 ) ;
if ( V_1 -> V_202 & 1 ) {
if ( V_60 & V_65 )
V_201 |= F_95 ( V_1 ) ;
else
V_201 |= F_96 ( V_1 ) ;
}
V_52 = V_1 -> V_203 >> 1 ;
V_204 = 1 ;
while ( V_52 ) {
if ( V_52 & 1 ) {
V_201 = V_64 ;
if ( V_60 & V_65 ) {
if ( F_50 () )
F_97 ( V_1 , V_204 ) ;
} else {
if ( F_52 () )
F_98 ( V_1 , V_204 ) ;
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
if ( F_50 () )
F_99 ( V_1 , V_204 ) ;
} else {
if ( F_52 () )
F_100 ( V_1 , V_204 ) ;
}
}
V_52 >>= 1 ;
V_204 ++ ;
}
return V_201 ;
}
void F_101 ( struct V_1 * V_1 , T_3 V_28 , T_3 V_206 )
{
T_3 V_60 = F_4 ( V_1 -> V_33 , V_79 ) ;
if ( ! V_28 ) {
#ifndef F_102
if ( ! F_103 () ) {
if ( V_60 & V_65 )
F_95 ( V_1 ) ;
else
F_96 ( V_1 ) ;
}
#endif
} else {
if ( V_206 ) {
if ( V_60 & V_65 ) {
if ( F_50 () )
F_99 ( V_1 , V_28 ) ;
} else {
if ( F_52 () )
F_100 ( V_1 , V_28 ) ;
}
} else {
if ( V_60 & V_65 ) {
if ( F_50 () )
F_97 ( V_1 , V_28 ) ;
} else {
if ( F_52 () )
F_98 ( V_1 , V_28 ) ;
}
}
}
}
static T_7
F_104 ( struct V_2 * V_3 , struct V_207 * V_208 , char * V_209 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
int V_165 = - V_163 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_165 = sprintf ( V_209 , L_68 , F_25 ( V_1 -> V_40 -> V_41 ) ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_165 ;
}
static T_7
F_105 ( struct V_2 * V_3 , struct V_207 * V_208 ,
const char * V_209 , T_8 V_146 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
int V_170 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
if ( F_106 ( V_209 , L_13 ) )
V_170 = F_107 ( V_1 , V_210 ) ;
else if ( F_106 ( V_209 , L_14 ) )
V_170 = F_107 ( V_1 , V_211 ) ;
else if ( F_106 ( V_209 , L_69 ) )
V_170 = F_107 ( V_1 , V_212 ) ;
else
V_170 = - V_163 ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return ( V_170 == 0 ) ? V_146 : V_170 ;
}
static T_7
F_108 ( struct V_2 * V_3 , struct V_207 * V_208 ,
const char * V_209 , T_8 V_146 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
unsigned long V_213 ;
if ( sscanf ( V_209 , L_70 , & V_213 ) < 1 ) {
F_109 ( V_3 , L_71 ) ;
return - V_163 ;
}
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_1 -> V_90 = V_213 ? F_110 ( int , V_213 , V_91 ) : 0 ;
if ( V_1 -> V_40 -> V_41 == V_46 )
V_1 -> V_44 = 0 ;
F_41 ( V_1 , V_71 + F_33 ( V_213 ) ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return V_146 ;
}
static T_7
F_111 ( struct V_2 * V_3 , struct V_207 * V_208 , char * V_209 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_38 ;
unsigned long V_213 ;
int V_214 ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
V_213 = V_1 -> V_90 ;
V_214 = F_112 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return sprintf ( V_209 , L_72 ,
V_214 ? L_73 : L_74 , V_213 ) ;
}
static T_7
F_113 ( struct V_2 * V_3 , struct V_207 * V_208 ,
const char * V_209 , T_8 V_146 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_215 ;
if ( sscanf ( V_209 , L_75 , & V_215 ) != 1
|| ( V_215 != 1 ) ) {
F_109 ( V_3 , L_76 ) ;
return - V_163 ;
}
if ( V_215 == 1 )
F_114 ( V_1 ) ;
return V_146 ;
}
static void F_115 ( struct V_216 * V_21 )
{
struct V_1 * V_1 = F_116 ( V_21 , struct V_1 , V_112 ) ;
static int V_217 ;
if ( V_1 -> V_40 -> V_41 != V_217 ) {
V_217 = V_1 -> V_40 -> V_41 ;
F_117 ( & V_1 -> V_27 -> V_218 , NULL , L_77 ) ;
}
}
static struct V_1 * T_6
F_118 ( struct V_2 * V_3 ,
struct V_219 * V_131 , void T_2 * V_51 )
{
struct V_1 * V_1 ;
struct V_22 * V_220 ;
int V_28 ;
#ifdef F_32
struct V_49 * V_50 ;
V_50 = F_119 ( & V_221 , V_3 , F_120 ( V_3 ) ) ;
if ( ! V_50 )
return NULL ;
V_1 = F_121 ( V_50 ) ;
F_122 ( & V_1 -> V_222 ) ;
F_122 ( & V_1 -> V_223 ) ;
F_122 ( & V_1 -> V_224 ) ;
V_50 -> V_225 = 1 ;
V_50 -> V_226 = 1 ;
V_1 -> V_87 = V_227 ;
V_1 -> V_90 = V_91 ;
#else
V_1 = F_123 ( sizeof *V_1 , V_228 ) ;
if ( ! V_1 )
return NULL ;
#endif
F_124 ( V_3 , V_1 ) ;
V_1 -> V_33 = V_51 ;
V_1 -> V_229 = V_51 ;
V_1 -> V_230 = - V_231 ;
V_1 -> V_131 = V_131 ;
F_125 ( V_1 -> V_131 -> V_162 > V_232 ) ;
for ( V_28 = 0 , V_220 = V_1 -> V_32 ;
V_28 < V_1 -> V_131 -> V_162 ;
V_28 ++ , V_220 ++ ) {
V_220 -> V_1 = V_1 ;
V_220 -> V_28 = V_28 ;
}
V_1 -> V_27 = V_3 ;
return V_1 ;
}
static void F_126 ( struct V_1 * V_1 )
{
#ifdef F_127
F_128 ( & V_1 -> V_27 -> V_218 , & V_233 ) ;
#endif
#ifdef F_36
F_129 ( V_1 ) ;
#endif
if ( V_1 -> V_230 >= 0 ) {
if ( V_1 -> V_234 )
F_130 ( V_1 -> V_230 ) ;
F_131 ( V_1 -> V_230 , V_1 ) ;
}
if ( F_132 () && V_1 -> V_235 ) {
struct V_235 * V_236 = V_1 -> V_235 ;
( void ) V_236 -> V_237 ( V_236 ) ;
F_133 ( V_236 ) ;
}
#ifdef F_32
F_134 ( F_29 ( V_1 ) ) ;
#else
F_135 ( V_1 ) ;
#endif
}
static int T_6
F_136 ( struct V_2 * V_3 , int V_230 , void T_2 * V_238 )
{
int V_170 ;
struct V_1 * V_1 ;
struct V_239 * V_240 = V_3 -> V_241 ;
if ( ! V_240 ) {
F_9 ( V_3 , L_78 ) ;
V_170 = - V_231 ;
goto V_242;
}
V_1 = F_118 ( V_3 , V_240 -> V_131 , V_238 ) ;
if ( ! V_1 ) {
V_170 = - V_243 ;
goto V_242;
}
F_137 ( V_1 -> V_27 ) ;
F_138 ( V_1 -> V_27 , 200 ) ;
F_139 ( V_1 -> V_27 ) ;
F_140 ( & V_1 -> V_39 ) ;
V_1 -> V_244 = V_240 -> V_129 ;
V_1 -> V_245 = V_240 -> V_246 ;
V_1 -> V_247 = V_240 -> V_247 ;
V_1 -> V_248 = V_240 -> V_249 ;
V_1 -> V_250 = F_92 ;
V_170 = F_141 ( V_1 ) ;
if ( V_170 < 0 )
goto V_251;
if ( ! V_1 -> V_250 ) {
V_170 = - V_231 ;
goto V_252;
}
if ( ! V_1 -> V_40 -> V_253 ) {
V_1 -> V_40 -> V_8 = V_1 -> V_33 ;
V_1 -> V_40 -> V_253 = & V_254 ;
}
#ifndef F_142
if ( V_255 && V_3 -> V_256 ) {
struct V_235 * V_236 ;
V_236 = F_143 ( V_1 , V_1 -> V_33 ) ;
V_1 -> V_235 = V_236 ;
if ( V_236 )
( void ) V_236 -> V_257 ( V_236 ) ;
}
#endif
if ( ! F_132 () || ! V_1 -> V_235 )
V_3 -> V_256 = NULL ;
F_62 ( V_1 ) ;
F_60 ( V_1 ) ;
V_170 = F_81 ( V_240 -> V_131 -> V_258
? V_183
: V_259 , V_1 ) ;
if ( V_170 < 0 )
goto V_252;
#ifdef F_39
F_144 ( & V_1 -> V_94 , F_22 , ( unsigned long ) V_1 ) ;
#endif
F_145 ( & V_1 -> V_112 , F_115 ) ;
if ( F_146 ( V_230 , V_1 -> V_250 , 0 , F_120 ( V_3 ) , V_1 ) ) {
F_109 ( V_3 , L_79 , V_230 ) ;
V_170 = - V_231 ;
goto V_252;
}
V_1 -> V_230 = V_230 ;
if ( F_147 ( V_230 ) == 0 ) {
V_1 -> V_234 = 1 ;
F_148 ( V_3 , 1 ) ;
} else {
V_1 -> V_234 = 0 ;
}
if ( F_58 ( V_1 ) ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
F_149 ( V_1 -> V_40 , & V_50 -> V_55 ) ;
if ( F_43 ( V_1 ) )
V_50 -> V_55 . V_260 = 1 ;
V_1 -> V_40 -> V_96 = & V_50 -> V_55 ;
V_50 -> V_261 = 2 * ( V_240 -> V_11 ? : 250 ) ;
if ( V_240 -> V_262 ) {
T_3 V_263 = F_150 ( V_1 -> V_33 ) ;
V_263 |= V_264 ;
F_151 ( V_1 -> V_33 , V_263 ) ;
}
}
if ( ! F_43 ( V_1 ) && F_58 ( V_1 ) ) {
struct V_49 * V_50 = F_29 ( V_1 ) ;
F_38 ( V_1 ) ;
V_1 -> V_40 -> V_265 = 1 ;
V_1 -> V_40 -> V_41 = V_83 ;
V_170 = F_152 ( F_29 ( V_1 ) , - 1 , 0 ) ;
V_50 -> V_55 . V_266 = 1 ;
F_9 ( V_1 -> V_27 , L_80 ,
L_81 , V_170 ,
F_4 ( V_1 -> V_33 , V_79 ) ,
( F_4 ( V_1 -> V_33 , V_79 )
& V_78
? 'B' : 'A' ) ) ;
} else {
F_30 ( V_1 ) ;
V_1 -> V_40 -> V_265 = 0 ;
V_1 -> V_40 -> V_41 = V_76 ;
V_170 = F_153 ( V_1 ) ;
F_9 ( V_1 -> V_27 , L_82 ,
F_43 ( V_1 ) ? L_83 : L_84 ,
V_170 ,
F_4 ( V_1 -> V_33 , V_79 ) ) ;
}
if ( V_170 < 0 )
goto V_252;
F_67 ( V_1 -> V_27 ) ;
V_170 = F_154 ( V_1 ) ;
if ( V_170 < 0 )
goto V_267;
#ifdef F_127
V_170 = F_155 ( & V_1 -> V_27 -> V_218 , & V_233 ) ;
if ( V_170 )
goto V_268;
#endif
F_156 (dev, L_85 ,
({char *s;
switch (musb->board_mode) {
case MUSB_HOST: s = L_86; break;
case MUSB_PERIPHERAL: s = L_87; break;
default: s = L_83; break;
}; s; }),
ctrl,
(is_dma_capable() && musb->dma_controller)
? L_88 : L_89 ,
musb->nIrq) ;
return 0 ;
V_268:
F_157 ( V_1 ) ;
V_267:
if ( ! F_43 ( V_1 ) && F_58 ( V_1 ) )
F_65 ( F_29 ( V_1 ) ) ;
else
F_129 ( V_1 ) ;
V_252:
if ( V_1 -> V_234 )
F_148 ( V_3 , 0 ) ;
F_66 ( V_1 ) ;
V_251:
F_109 ( V_1 -> V_27 ,
L_90 , V_170 ) ;
F_126 ( V_1 ) ;
V_242:
return V_170 ;
}
static int T_6 F_158 ( struct V_121 * V_122 )
{
struct V_2 * V_3 = & V_122 -> V_3 ;
int V_199 = F_159 ( V_122 , L_91 ) ;
int V_170 ;
struct V_269 * V_270 ;
void T_2 * V_271 ;
V_270 = F_160 ( V_122 , V_272 , 0 ) ;
if ( ! V_270 || V_199 <= 0 )
return - V_231 ;
V_271 = F_161 ( V_270 -> V_257 , F_162 ( V_270 ) ) ;
if ( ! V_271 ) {
F_109 ( V_3 , L_92 ) ;
return - V_243 ;
}
#ifndef F_142
V_273 = V_3 -> V_256 ;
#endif
V_170 = F_136 ( V_3 , V_199 , V_271 ) ;
if ( V_170 < 0 )
F_163 ( V_271 ) ;
return V_170 ;
}
static int T_9 F_164 ( struct V_121 * V_122 )
{
struct V_1 * V_1 = F_1 ( & V_122 -> V_3 ) ;
void T_2 * V_229 = V_1 -> V_229 ;
F_64 ( V_1 -> V_27 ) ;
F_157 ( V_1 ) ;
F_63 ( V_122 ) ;
F_67 ( V_1 -> V_27 ) ;
F_126 ( V_1 ) ;
F_163 ( V_229 ) ;
F_148 ( & V_122 -> V_3 , 0 ) ;
#ifndef F_142
V_122 -> V_3 . V_256 = V_273 ;
#endif
return 0 ;
}
static void F_165 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_274 = V_1 -> V_33 ;
void T_2 * V_275 ;
if ( F_58 ( V_1 ) ) {
V_1 -> V_276 . V_277 = F_17 ( V_274 , V_278 ) ;
V_1 -> V_276 . V_279 = F_4 ( V_274 , V_113 ) ;
V_1 -> V_276 . V_263 = F_150 ( V_1 -> V_33 ) ;
}
V_1 -> V_276 . V_11 = F_4 ( V_274 , V_12 ) ;
V_1 -> V_276 . V_280 = F_17 ( V_274 , V_99 ) ;
V_1 -> V_276 . V_281 = F_17 ( V_274 , V_101 ) ;
V_1 -> V_276 . V_282 = F_4 ( V_274 , V_102 ) ;
V_1 -> V_276 . V_29 = F_4 ( V_274 , V_135 ) ;
V_1 -> V_276 . V_60 = F_4 ( V_274 , V_79 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_131 -> V_162 ; ++ V_9 ) {
V_275 = V_1 -> V_32 [ V_9 ] . V_31 ;
V_1 -> V_276 . V_283 [ V_9 ] . V_284 =
F_17 ( V_275 , V_285 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_286 =
F_17 ( V_275 , V_287 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_288 =
F_17 ( V_275 , V_289 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_290 =
F_17 ( V_275 , V_291 ) ;
if ( V_1 -> V_173 ) {
V_1 -> V_276 . V_283 [ V_9 ] . V_292 =
F_166 ( V_274 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_293 =
F_167 ( V_274 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_294 =
F_168 ( V_274 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_295 =
F_169 ( V_274 ) ;
}
if ( F_58 ( V_1 ) ) {
V_1 -> V_276 . V_283 [ V_9 ] . V_296 =
F_4 ( V_275 , V_297 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_298 =
F_4 ( V_275 , V_299 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_300 =
F_4 ( V_275 , V_301 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_302 =
F_4 ( V_275 , V_303 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_304 =
F_170 ( V_274 , V_9 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_305 =
F_171 ( V_274 , V_9 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_306 =
F_172 ( V_274 , V_9 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_307 =
F_173 ( V_274 , V_9 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_308 =
F_174 ( V_274 , V_9 ) ;
V_1 -> V_276 . V_283 [ V_9 ] . V_309 =
F_175 ( V_274 , V_9 ) ;
}
}
}
static void F_176 ( struct V_1 * V_1 )
{
int V_9 ;
void T_2 * V_274 = V_1 -> V_33 ;
void T_2 * V_310 ;
void T_2 * V_275 ;
if ( F_58 ( V_1 ) ) {
F_12 ( V_274 , V_278 , V_1 -> V_276 . V_277 ) ;
F_5 ( V_274 , V_113 , V_1 -> V_276 . V_279 ) ;
F_151 ( V_1 -> V_33 , V_1 -> V_276 . V_263 ) ;
}
F_5 ( V_274 , V_12 , V_1 -> V_276 . V_11 ) ;
F_12 ( V_274 , V_99 , V_1 -> V_276 . V_280 ) ;
F_12 ( V_274 , V_101 , V_1 -> V_276 . V_281 ) ;
F_5 ( V_274 , V_102 , V_1 -> V_276 . V_282 ) ;
F_5 ( V_274 , V_79 , V_1 -> V_276 . V_60 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_131 -> V_162 ; ++ V_9 ) {
V_275 = V_1 -> V_32 [ V_9 ] . V_31 ;
F_12 ( V_275 , V_285 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_284 ) ;
F_12 ( V_275 , V_287 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_286 ) ;
F_12 ( V_275 , V_289 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_288 ) ;
F_12 ( V_275 , V_291 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_290 ) ;
if ( V_1 -> V_173 ) {
F_71 ( V_274 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_294 ) ;
F_73 ( V_274 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_295 ) ;
F_72 ( V_274 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_292 ) ;
F_74 ( V_274 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_293 ) ;
}
if ( F_58 ( V_1 ) ) {
F_5 ( V_275 , V_297 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_296 ) ;
F_5 ( V_275 , V_299 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_298 ) ;
F_5 ( V_275 , V_301 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_300 ) ;
F_5 ( V_275 , V_303 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_302 ) ;
F_177 ( V_274 , V_9 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_304 ) ;
F_178 ( V_274 , V_9 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_305 ) ;
F_179 ( V_274 , V_9 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_306 ) ;
V_310 =
F_91 ( V_9 , V_274 ) ;
F_180 ( V_310 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_307 ) ;
F_181 ( V_310 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_308 ) ;
F_182 ( V_310 ,
V_1 -> V_276 . V_283 [ V_9 ] . V_309 ) ;
}
}
}
static int F_183 ( struct V_2 * V_3 )
{
struct V_121 * V_122 = F_184 ( V_3 ) ;
unsigned long V_38 ;
struct V_1 * V_1 = F_1 ( & V_122 -> V_3 ) ;
F_23 ( & V_1 -> V_39 , V_38 ) ;
if ( F_46 ( V_1 ) ) {
} else if ( F_185 ( V_1 ) ) {
}
F_165 ( V_1 ) ;
F_27 ( & V_1 -> V_39 , V_38 ) ;
return 0 ;
}
static int F_186 ( struct V_2 * V_3 )
{
struct V_121 * V_122 = F_184 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( & V_122 -> V_3 ) ;
F_176 ( V_1 ) ;
return 0 ;
}
static int F_187 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_165 ( V_1 ) ;
return 0 ;
}
static int F_188 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
static int V_311 = 1 ;
if ( ! V_311 )
F_176 ( V_1 ) ;
V_311 = 0 ;
return 0 ;
}
static int T_6 F_189 ( void )
{
#ifdef F_32
if ( F_190 () )
return 0 ;
#endif
F_191 ( L_93 V_312 L_94
#ifdef F_142
L_95
#elif F_192 ( V_313 )
L_96
#elif F_192 ( V_314 )
L_97
#elif F_192 ( F_102 )
L_98
#elif F_192 ( V_315 )
L_99
#else
L_100
#endif
L_94
#ifdef F_39
L_101
#elif F_192 ( F_36 )
L_14
#elif F_192 ( F_32 )
L_13
#endif
,
V_158 ) ;
return F_193 ( & V_316 , F_158 ) ;
}
static void T_9 F_194 ( void )
{
F_195 ( & V_316 ) ;
}
