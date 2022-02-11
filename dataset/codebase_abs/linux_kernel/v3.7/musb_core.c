static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
int F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_5 ;
int V_6 ;
V_5 = F_4 ( & V_7 , V_4 ) ;
if ( ! V_5 ) {
F_5 ( V_3 , L_1 ) ;
return - V_8 ;
}
V_5 = F_6 ( & V_7 , & V_6 ) ;
if ( V_5 < 0 ) {
F_5 ( V_3 , L_2 ) ;
return V_5 ;
}
return V_6 ;
}
void F_7 ( struct V_2 * V_3 , int V_6 )
{
F_8 ( V_3 , L_3 , V_6 ) ;
F_9 ( & V_7 , V_6 ) ;
}
static int F_10 ( struct V_9 * V_10 , T_2 V_11 )
{
void T_3 * V_12 = V_10 -> V_13 ;
int V_14 = 0 ;
T_4 V_15 ;
T_4 V_16 ;
int V_5 ;
F_11 ( V_10 -> V_17 ) ;
V_16 = F_12 ( V_12 , V_18 ) ;
V_16 &= ~ V_19 ;
F_13 ( V_12 , V_18 , V_16 ) ;
F_13 ( V_12 , V_20 , ( T_4 ) V_11 ) ;
F_13 ( V_12 , V_21 ,
V_22 | V_23 ) ;
while ( ! ( F_12 ( V_12 , V_21 )
& V_24 ) ) {
V_14 ++ ;
if ( V_14 == 10000 ) {
V_5 = - V_25 ;
goto V_26;
}
}
V_15 = F_12 ( V_12 , V_21 ) ;
V_15 &= ~ V_24 ;
F_13 ( V_12 , V_21 , V_15 ) ;
V_5 = F_12 ( V_12 , V_27 ) ;
V_26:
F_14 ( V_10 -> V_17 ) ;
return V_5 ;
}
static int F_15 ( struct V_9 * V_10 , T_2 V_11 , T_2 V_28 )
{
void T_3 * V_12 = V_10 -> V_13 ;
int V_14 = 0 ;
T_4 V_15 = 0 ;
T_4 V_16 ;
int V_5 = 0 ;
F_11 ( V_10 -> V_17 ) ;
V_16 = F_12 ( V_12 , V_18 ) ;
V_16 &= ~ V_19 ;
F_13 ( V_12 , V_18 , V_16 ) ;
F_13 ( V_12 , V_20 , ( T_4 ) V_11 ) ;
F_13 ( V_12 , V_27 , ( T_4 ) V_28 ) ;
F_13 ( V_12 , V_21 , V_22 ) ;
while ( ! ( F_12 ( V_12 , V_21 )
& V_24 ) ) {
V_14 ++ ;
if ( V_14 == 10000 ) {
V_5 = - V_25 ;
goto V_26;
}
}
V_15 = F_12 ( V_12 , V_21 ) ;
V_15 &= ~ V_24 ;
F_13 ( V_12 , V_21 , V_15 ) ;
V_26:
F_14 ( V_10 -> V_17 ) ;
return V_5 ;
}
void F_16 ( struct V_29 * V_30 , T_5 V_31 , const T_4 * V_32 )
{
struct V_1 * V_1 = V_30 -> V_1 ;
void T_3 * V_33 = V_30 -> V_33 ;
if ( F_17 ( V_31 == 0 ) )
return;
F_18 ( ( T_4 * ) V_32 ) ;
F_8 ( V_1 -> V_34 , L_4 ,
'T' , V_30 -> V_35 , V_33 , V_31 , V_32 ) ;
if ( F_19 ( ( 0x01 & ( unsigned long ) V_32 ) == 0 ) ) {
T_5 V_36 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_32 ) == 0 ) {
if ( V_31 >= 4 ) {
F_20 ( V_33 , V_32 + V_36 , V_31 >> 2 ) ;
V_36 += V_31 & ~ 0x03 ;
}
if ( V_31 & 0x02 ) {
F_21 ( V_33 , 0 , * ( T_5 * ) & V_32 [ V_36 ] ) ;
V_36 += 2 ;
}
} else {
if ( V_31 >= 2 ) {
F_22 ( V_33 , V_32 + V_36 , V_31 >> 1 ) ;
V_36 += V_31 & ~ 0x01 ;
}
}
if ( V_31 & 0x01 )
F_13 ( V_33 , 0 , V_32 [ V_36 ] ) ;
} else {
F_23 ( V_33 , V_32 , V_31 ) ;
}
}
void F_24 ( struct V_29 * V_30 , T_5 V_31 , T_4 * V_37 )
{
struct V_1 * V_1 = V_30 -> V_1 ;
void T_3 * V_33 = V_30 -> V_33 ;
if ( F_17 ( V_31 == 0 ) )
return;
F_8 ( V_1 -> V_34 , L_4 ,
'R' , V_30 -> V_35 , V_33 , V_31 , V_37 ) ;
if ( F_19 ( ( 0x01 & ( unsigned long ) V_37 ) == 0 ) ) {
T_5 V_36 = 0 ;
if ( ( 0x02 & ( unsigned long ) V_37 ) == 0 ) {
if ( V_31 >= 4 ) {
F_25 ( V_33 , V_37 , V_31 >> 2 ) ;
V_36 = V_31 & ~ 0x03 ;
}
if ( V_31 & 0x02 ) {
* ( T_5 * ) & V_37 [ V_36 ] = F_26 ( V_33 , 0 ) ;
V_36 += 2 ;
}
} else {
if ( V_31 >= 2 ) {
F_27 ( V_33 , V_37 , V_31 >> 1 ) ;
V_36 = V_31 & ~ 0x01 ;
}
}
if ( V_31 & 0x01 )
V_37 [ V_36 ] = F_12 ( V_33 , 0 ) ;
} else {
F_28 ( V_33 , V_37 , V_31 ) ;
}
}
void F_29 ( struct V_1 * V_1 )
{
void T_3 * V_38 = V_1 -> V_39 [ 0 ] . V_38 ;
F_30 ( V_1 -> V_40 , 0 ) ;
F_16 ( V_1 -> V_41 ,
sizeof( V_42 ) , V_42 ) ;
F_21 ( V_38 , V_43 , V_44 ) ;
}
static void F_31 ( unsigned long V_28 )
{
struct V_1 * V_1 = (struct V_1 * ) V_28 ;
unsigned long V_45 ;
F_32 ( & V_1 -> V_46 , V_45 ) ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_49 :
F_8 ( V_1 -> V_34 , L_5 ) ;
F_33 ( V_1 ) ;
V_1 -> V_47 -> V_48 = V_50 ;
V_1 -> V_51 = 0 ;
break;
case V_52 :
case V_53 :
F_8 ( V_1 -> V_34 , L_6 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
F_35 ( V_1 , 0 ) ;
V_1 -> V_47 -> V_48 = V_54 ;
break;
default:
F_8 ( V_1 -> V_34 , L_7 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
}
V_1 -> V_55 = 0 ;
F_36 ( & V_1 -> V_46 , V_45 ) ;
}
void F_37 ( struct V_1 * V_1 )
{
struct V_56 * V_57 = F_38 ( V_1 ) ;
void T_3 * V_58 = V_1 -> V_40 ;
T_4 V_59 ;
F_8 ( V_1 -> V_34 , L_8 , F_34 ( V_1 -> V_47 -> V_48 ) ) ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_60 :
F_33 ( V_1 ) ;
F_8 ( V_1 -> V_34 , L_9 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
break;
case V_61 :
F_8 ( V_1 -> V_34 , L_10 ) ;
V_57 -> V_62 . V_63 = 0 ;
V_1 -> V_47 -> V_48 = V_50 ;
F_39 ( V_1 ) ;
V_59 = F_12 ( V_58 , V_18 ) ;
V_59 |= V_19 ;
F_13 ( V_58 , V_18 , V_59 ) ;
break;
default:
F_8 ( V_1 -> V_34 , L_11 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
}
V_1 -> V_64 &= ~ ( V_65 << 16 ) ;
}
static T_6 F_40 ( struct V_1 * V_1 , T_4 V_66 ,
T_4 V_67 , T_4 V_16 )
{
struct V_68 * V_69 = V_1 -> V_47 -> V_69 ;
T_6 V_70 = V_71 ;
F_8 ( V_1 -> V_34 , L_12 , V_16 , V_67 ,
V_66 ) ;
if ( V_66 & V_72 ) {
V_70 = V_73 ;
F_8 ( V_1 -> V_34 , L_13 , F_34 ( V_1 -> V_47 -> V_48 ) ) ;
if ( V_67 & V_74 ) {
void T_3 * V_58 = V_1 -> V_40 ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_52 :
if ( V_16 & V_19 ) {
V_1 -> V_66 &= ~ V_75 ;
F_8 ( V_1 -> V_34 , L_14 ) ;
break;
}
V_16 &= ~ V_19 ;
F_13 ( V_58 , V_18 ,
V_16 | V_76 ) ;
V_1 -> V_64 |=
( V_77 << 16 )
| V_78 ;
V_1 -> V_79 = V_80
+ F_41 ( 20 ) ;
V_1 -> V_47 -> V_48 = V_81 ;
V_1 -> V_51 = 1 ;
F_42 ( F_38 ( V_1 ) ) ;
break;
case V_49 :
V_1 -> V_47 -> V_48 = V_50 ;
V_1 -> V_51 = 1 ;
F_39 ( V_1 ) ;
break;
default:
F_43 ( L_15 ,
L_16 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
}
} else {
switch ( V_1 -> V_47 -> V_48 ) {
case V_52 :
V_1 -> V_47 -> V_48 = V_81 ;
F_42 ( F_38 ( V_1 ) ) ;
break;
case V_49 :
case V_50 :
if ( ( V_67 & V_82 )
!= ( 3 << V_83 )
) {
V_1 -> V_66 |= V_84 ;
V_1 -> V_66 &= ~ V_75 ;
break;
}
F_44 ( V_1 ) ;
break;
case V_85 :
V_1 -> V_66 &= ~ V_75 ;
break;
default:
F_43 ( L_15 ,
L_17 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
}
}
}
if ( V_66 & V_86 ) {
void T_3 * V_58 = V_1 -> V_40 ;
if ( ( V_67 & V_82 ) == V_82
&& ( V_67 & V_87 ) ) {
F_8 ( V_1 -> V_34 , L_18 ) ;
return V_73 ;
}
F_8 ( V_1 -> V_34 , L_19 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
F_13 ( V_58 , V_88 , V_89 ) ;
V_1 -> V_90 = V_91 ;
V_1 -> V_47 -> V_48 = V_92 ;
F_45 ( V_1 ) ;
F_35 ( V_1 , 1 ) ;
V_70 = V_73 ;
}
if ( V_66 & V_93 ) {
int V_94 = 0 ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_81 :
case V_53 :
case V_95 :
if ( V_1 -> V_96 ) {
void T_3 * V_58 = V_1 -> V_40 ;
V_1 -> V_96 -- ;
V_94 = 1 ;
V_67 |= V_89 ;
F_13 ( V_58 , V_88 , V_67 ) ;
} else {
V_1 -> V_64 |=
V_97
| ( V_98 << 16 ) ;
}
break;
default:
break;
}
F_8 (musb->controller, L_20 ,
otg_state_string(musb->xceiv->state),
devctl,
({ char *s;
switch (devctl & MUSB_DEVCTL_VBUS) {
case 0 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_21; break;
case 1 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_22; break;
case 2 << MUSB_DEVCTL_VBUS_SHIFT:
s = L_23; break;
default:
s = L_24; break;
}; s; }),
VBUSERR_RETRY_COUNT - musb->vbuserr_retry,
musb->port1_status) ;
if ( ! V_94 )
F_35 ( V_1 , 0 ) ;
V_70 = V_73 ;
}
if ( V_66 & V_75 ) {
F_8 ( V_1 -> V_34 , L_25 ,
F_34 ( V_1 -> V_47 -> V_48 ) , V_67 , V_16 ) ;
V_70 = V_73 ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_60 :
F_37 ( V_1 ) ;
F_42 ( F_38 ( V_1 ) ) ;
F_46 ( V_1 ) ;
F_47 ( V_1 , V_80
+ F_41 ( V_1 -> V_99
? : V_100 ) ) ;
break;
case V_85 :
if ( ! V_1 -> V_51 )
break;
case V_50 :
F_48 ( V_1 ) ;
V_1 -> V_51 = V_69 -> V_101 -> V_102 ;
if ( V_1 -> V_51 ) {
V_1 -> V_47 -> V_48 = V_49 ;
F_8 ( V_1 -> V_34 , L_26 ) ;
F_49 ( & V_1 -> V_103 , V_80
+ F_41 (
V_104 ) ) ;
}
break;
case V_53 :
if ( V_1 -> V_99 != 0 )
F_47 ( V_1 , V_80
+ F_41 ( V_1 -> V_99 ) ) ;
break;
case V_81 :
V_1 -> V_47 -> V_48 = V_52 ;
V_1 -> V_51 = V_69 -> V_105 -> V_102 ;
break;
case V_61 :
F_8 ( V_1 -> V_34 , L_27 ) ;
break;
default:
V_1 -> V_51 = 0 ;
break;
}
}
if ( V_66 & V_106 ) {
struct V_56 * V_57 = F_38 ( V_1 ) ;
V_70 = V_73 ;
V_1 -> V_51 = 1 ;
V_1 -> V_90 = V_91 ;
if ( F_50 ( V_1 ) ) {
}
F_21 ( V_1 -> V_40 , V_107 , V_1 -> V_108 ) ;
F_21 ( V_1 -> V_40 , V_109 , V_1 -> V_108 & 0xfffe ) ;
F_13 ( V_1 -> V_40 , V_110 , 0xf7 ) ;
V_1 -> V_64 &= ~ ( V_111
| V_112
| V_113
) ;
V_1 -> V_64 |= V_114
| ( V_65 << 16 ) ;
if ( V_67 & V_115 )
V_1 -> V_64 |= V_111 ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_50 :
if ( V_66 & V_75 ) {
F_8 ( V_1 -> V_34 , L_28 ) ;
V_66 &= ~ V_75 ;
goto V_116;
} else
F_8 ( V_1 -> V_34 , L_29 ) ;
break;
case V_49 :
F_8 ( V_1 -> V_34 , L_30 ) ;
V_116:
V_1 -> V_47 -> V_48 = V_61 ;
V_57 -> V_62 . V_63 = 1 ;
V_1 -> V_55 = 0 ;
F_51 ( & V_1 -> V_103 ) ;
break;
default:
if ( ( V_67 & V_82 )
== ( 3 << V_83 ) ) {
V_1 -> V_47 -> V_48 = V_81 ;
V_57 -> V_62 . V_63 = 0 ;
}
break;
}
F_45 ( V_1 ) ;
if ( V_57 -> V_117 )
F_52 ( V_57 ) ;
else
F_42 ( V_57 ) ;
F_8 ( V_1 -> V_34 , L_31 ,
F_34 ( V_1 -> V_47 -> V_48 ) , V_67 ) ;
}
if ( ( V_66 & V_84 ) && ! V_1 -> V_55 ) {
F_8 ( V_1 -> V_34 , L_32 ,
F_34 ( V_1 -> V_47 -> V_48 ) ,
F_53 ( V_1 ) , V_67 ) ;
V_70 = V_73 ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_81 :
case V_52 :
F_42 ( F_38 ( V_1 ) ) ;
F_46 ( V_1 ) ;
if ( V_1 -> V_99 != 0 )
F_47 ( V_1 , V_80
+ F_41 ( V_1 -> V_99 ) ) ;
break;
case V_61 :
F_46 ( V_1 ) ;
F_38 ( V_1 ) -> V_62 . V_63 = 0 ;
V_1 -> V_47 -> V_48 = V_50 ;
F_39 ( V_1 ) ;
F_33 ( V_1 ) ;
break;
case V_60 :
F_37 ( V_1 ) ;
F_46 ( V_1 ) ;
case V_49 :
case V_50 :
case V_85 :
F_33 ( V_1 ) ;
break;
default:
F_43 ( L_33 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
break;
}
}
if ( V_66 & V_118 ) {
V_70 = V_73 ;
if ( ( V_67 & V_74 ) != 0 ) {
if ( V_67 & ( V_119 | V_115 ) )
F_8 ( V_1 -> V_34 , L_34 , V_67 ) ;
else {
F_54 ( L_35 ) ;
F_13 ( V_1 -> V_40 , V_88 , 0 ) ;
}
} else {
F_8 ( V_1 -> V_34 , L_36 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
switch ( V_1 -> V_47 -> V_48 ) {
case V_52 :
V_1 -> V_55 = 1 ;
F_55 ( V_1 ) ;
case V_53 :
F_8 ( V_1 -> V_34 , L_37 ,
F_34 ( V_1 -> V_47 -> V_48 ) ,
F_56 ( V_1 ) ) ;
F_49 ( & V_1 -> V_103 , V_80
+ F_41 ( F_56 ( V_1 ) ) ) ;
break;
case V_60 :
V_1 -> V_55 = 0 ;
F_51 ( & V_1 -> V_103 ) ;
F_55 ( V_1 ) ;
break;
case V_49 :
F_8 ( V_1 -> V_34 , L_38 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
V_1 -> V_47 -> V_48 = V_50 ;
F_55 ( V_1 ) ;
break;
case V_85 :
V_1 -> V_47 -> V_48 = V_50 ;
case V_50 :
F_55 ( V_1 ) ;
break;
default:
F_8 ( V_1 -> V_34 , L_39 ,
F_34 ( V_1 -> V_47 -> V_48 ) ) ;
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
F_57 ( & V_1 -> V_120 ) ;
return V_70 ;
}
void F_58 ( struct V_1 * V_1 )
{
void T_3 * V_38 = V_1 -> V_40 ;
T_4 V_67 = F_12 ( V_38 , V_88 ) ;
F_8 ( V_1 -> V_34 , L_40 , V_67 ) ;
F_21 ( V_38 , V_107 , V_1 -> V_108 ) ;
F_21 ( V_38 , V_109 , V_1 -> V_108 & 0xfffe ) ;
F_13 ( V_38 , V_110 , 0xf7 ) ;
F_13 ( V_38 , V_121 , 0 ) ;
F_13 ( V_38 , V_18 , V_122
| V_123
) ;
V_1 -> V_51 = 0 ;
V_67 = F_12 ( V_38 , V_88 ) ;
V_67 &= ~ V_89 ;
if ( ( V_67 & V_82 ) == V_82 )
V_1 -> V_51 = 1 ;
else
V_67 |= V_89 ;
F_59 ( V_1 ) ;
F_13 ( V_38 , V_88 , V_67 ) ;
}
static void F_60 ( struct V_1 * V_1 )
{
void T_3 * V_58 = V_1 -> V_40 ;
T_5 V_124 ;
F_13 ( V_58 , V_110 , 0 ) ;
F_21 ( V_58 , V_107 , 0 ) ;
F_21 ( V_58 , V_109 , 0 ) ;
F_13 ( V_58 , V_88 , 0 ) ;
V_124 = F_12 ( V_58 , V_125 ) ;
V_124 = F_26 ( V_58 , V_126 ) ;
V_124 = F_26 ( V_58 , V_127 ) ;
}
void F_61 ( struct V_1 * V_1 )
{
F_62 ( V_1 ) ;
F_60 ( V_1 ) ;
F_8 ( V_1 -> V_34 , L_41 ) ;
F_47 ( V_1 , 0 ) ;
}
static void F_63 ( struct V_128 * V_129 )
{
struct V_1 * V_1 = F_1 ( & V_129 -> V_3 ) ;
unsigned long V_45 ;
F_11 ( V_1 -> V_34 ) ;
F_64 ( V_1 ) ;
F_32 ( & V_1 -> V_46 , V_45 ) ;
F_62 ( V_1 ) ;
F_60 ( V_1 ) ;
F_36 ( & V_1 -> V_46 , V_45 ) ;
F_13 ( V_1 -> V_40 , V_88 , 0 ) ;
F_65 ( V_1 ) ;
F_14 ( V_1 -> V_34 ) ;
}
static int T_7
F_66 ( struct V_1 * V_1 , struct V_29 * V_30 ,
const struct V_130 * V_131 , T_5 V_11 )
{
void T_3 * V_58 = V_1 -> V_40 ;
int V_132 = 0 ;
T_5 V_133 = V_131 -> V_133 ;
T_5 V_134 = V_11 >> 3 ;
T_4 V_135 ;
V_132 = F_67 ( F_68 ( V_133 , ( T_5 ) 8 ) ) - 1 ;
V_133 = 1 << V_132 ;
V_135 = V_132 - 3 ;
if ( V_131 -> V_136 == V_137 ) {
if ( ( V_11 + ( V_133 << 1 ) ) >
( 1 << ( V_1 -> V_138 -> V_139 + 2 ) ) )
return - V_140 ;
V_135 |= V_141 ;
} else {
if ( ( V_11 + V_133 ) > ( 1 << ( V_1 -> V_138 -> V_139 + 2 ) ) )
return - V_140 ;
}
F_13 ( V_58 , V_142 , V_30 -> V_35 ) ;
if ( V_30 -> V_35 == 1 )
V_1 -> V_143 = V_30 ;
switch ( V_131 -> V_144 ) {
case V_145 :
F_69 ( V_58 , V_135 ) ;
F_70 ( V_58 , V_134 ) ;
V_30 -> V_146 = ! ! ( V_135 & V_141 ) ;
V_30 -> V_147 = V_133 ;
break;
case V_148 :
F_71 ( V_58 , V_135 ) ;
F_72 ( V_58 , V_134 ) ;
V_30 -> V_149 = ! ! ( V_135 & V_141 ) ;
V_30 -> V_150 = V_133 ;
break;
case V_151 :
F_69 ( V_58 , V_135 ) ;
F_70 ( V_58 , V_134 ) ;
V_30 -> V_149 = ! ! ( V_135 & V_141 ) ;
V_30 -> V_150 = V_133 ;
F_71 ( V_58 , V_135 ) ;
F_72 ( V_58 , V_134 ) ;
V_30 -> V_146 = V_30 -> V_149 ;
V_30 -> V_147 = V_133 ;
V_30 -> V_152 = true ;
break;
}
V_1 -> V_108 |= ( 1 << V_30 -> V_35 ) ;
return V_11 + ( V_133 << ( ( V_135 & V_141 ) ? 1 : 0 ) ) ;
}
static int T_7 F_73 ( struct V_1 * V_1 )
{
const struct V_130 * V_131 ;
unsigned V_14 , V_153 ;
int V_11 ;
struct V_29 * V_30 = V_1 -> V_39 ;
if ( V_1 -> V_138 -> V_154 ) {
V_131 = V_1 -> V_138 -> V_154 ;
V_153 = V_1 -> V_138 -> V_155 ;
goto V_156;
}
switch ( V_157 ) {
default:
V_157 = 0 ;
case 0 :
V_131 = V_158 ;
V_153 = F_74 ( V_158 ) ;
break;
case 1 :
V_131 = V_159 ;
V_153 = F_74 ( V_159 ) ;
break;
case 2 :
V_131 = V_160 ;
V_153 = F_74 ( V_160 ) ;
break;
case 3 :
V_131 = V_161 ;
V_153 = F_74 ( V_161 ) ;
break;
case 4 :
V_131 = V_162 ;
V_153 = F_74 ( V_162 ) ;
break;
case 5 :
V_131 = V_163 ;
V_153 = F_74 ( V_163 ) ;
break;
}
F_75 ( V_164 L_42 ,
V_165 , V_157 ) ;
V_156:
V_11 = F_66 ( V_1 , V_30 , & V_166 , 0 ) ;
for ( V_14 = 0 ; V_14 < V_153 ; V_14 ++ ) {
T_4 V_167 = V_131 -> V_168 ;
if ( V_167 >= V_1 -> V_138 -> V_169 ) {
F_76 ( L_43 ,
V_165 , V_167 ) ;
return - V_170 ;
}
V_11 = F_66 ( V_1 , V_30 + V_167 , V_131 ++ , V_11 ) ;
if ( V_11 < 0 ) {
F_76 ( L_44 ,
V_165 , V_167 ) ;
return V_11 ;
}
V_167 ++ ;
V_1 -> V_171 = F_68 ( V_167 , V_1 -> V_171 ) ;
}
F_75 ( V_164 L_45 ,
V_165 ,
V_153 + 1 , V_1 -> V_138 -> V_169 * 2 - 1 ,
V_11 , ( 1 << ( V_1 -> V_138 -> V_139 + 2 ) ) ) ;
if ( ! V_1 -> V_143 ) {
F_76 ( L_46 , V_165 ) ;
return - V_170 ;
}
return 0 ;
}
static int T_7 F_77 ( struct V_1 * V_1 )
{
T_4 V_35 = 0 ;
struct V_29 * V_30 ;
void T_3 * V_58 = V_1 -> V_40 ;
int V_5 = 0 ;
F_8 ( V_1 -> V_34 , L_47 ) ;
for ( V_35 = 1 ; V_35 < V_1 -> V_138 -> V_169 ; V_35 ++ ) {
F_30 ( V_58 , V_35 ) ;
V_30 = V_1 -> V_39 + V_35 ;
V_5 = F_78 ( V_1 , V_30 , V_35 ) ;
if ( V_5 < 0 )
break;
if ( V_30 -> V_147 < 512
|| V_30 -> V_150 < 512 )
continue;
if ( V_1 -> V_143 )
continue;
V_1 -> V_143 = V_30 ;
}
if ( ! V_1 -> V_143 ) {
F_76 ( L_46 , V_165 ) ;
return - V_170 ;
}
return 0 ;
}
static int T_7 F_79 ( T_5 V_172 , struct V_1 * V_1 )
{
T_4 V_59 ;
char * type ;
char V_173 [ 90 ] , V_174 [ 32 ] , V_175 [ 12 ] ;
void T_3 * V_58 = V_1 -> V_40 ;
int V_176 = 0 ;
int V_14 ;
V_59 = F_80 ( V_58 ) ;
strcpy ( V_173 , ( V_59 & V_177 ) ? L_48 : L_49 ) ;
if ( V_59 & V_178 ) {
strcat ( V_173 , L_50 ) ;
V_1 -> V_179 = true ;
}
if ( V_59 & V_180 ) {
strcat ( V_173 , L_51 ) ;
V_1 -> V_181 = true ;
}
if ( V_59 & V_182 ) {
strcat ( V_173 , L_52 ) ;
V_1 -> V_183 = true ;
}
if ( V_59 & V_184 ) {
strcat ( V_173 , L_53 ) ;
V_1 -> V_185 = true ;
}
if ( V_59 & V_186 ) {
strcat ( V_173 , L_54 ) ;
V_1 -> V_187 = true ;
}
if ( V_59 & V_188 )
strcat ( V_173 , L_55 ) ;
F_75 ( V_164 L_56 ,
V_165 , V_59 , V_173 ) ;
V_175 [ 0 ] = 0 ;
if ( V_189 == V_172 ) {
V_1 -> V_190 = 1 ;
type = L_57 ;
} else {
V_1 -> V_190 = 0 ;
type = L_58 ;
#ifndef F_81
F_75 ( V_191
L_59 ,
V_165 ) ;
#endif
}
V_1 -> V_192 = F_82 ( V_58 ) ;
snprintf ( V_174 , 32 , L_60 , F_83 ( V_1 -> V_192 ) ,
F_84 ( V_1 -> V_192 ) ,
( V_1 -> V_192 & V_193 ) ? L_61 : L_58 ) ;
F_75 ( V_164 L_62 ,
V_165 , type , V_174 , V_175 ) ;
F_85 ( V_1 ) ;
V_1 -> V_171 = 1 ;
V_1 -> V_108 = 1 ;
if ( V_1 -> V_179 )
V_176 = F_73 ( V_1 ) ;
else
V_176 = F_77 ( V_1 ) ;
if ( V_176 < 0 )
return V_176 ;
for ( V_14 = 0 ; V_14 < V_1 -> V_171 ; V_14 ++ ) {
struct V_29 * V_30 = V_1 -> V_39 + V_14 ;
V_30 -> V_33 = F_86 ( V_14 ) + V_58 ;
#if F_87 ( V_194 ) || F_87 ( V_195 )
V_30 -> V_196 = V_1 -> V_197 + 0x400 + F_86 ( V_14 ) ;
V_30 -> V_198 = V_1 -> V_199 + 0x400 + F_86 ( V_14 ) ;
V_30 -> V_200 =
V_1 -> V_201 + 0x400 + F_86 ( V_14 ) ;
if ( V_14 == 0 )
V_30 -> V_202 = V_58 - 0x400 + V_203 ;
else
V_30 -> V_202 = V_58 + 0x400 + ( ( ( V_14 - 1 ) & 0xf ) << 2 ) ;
#endif
V_30 -> V_38 = F_88 ( V_14 , 0 ) + V_58 ;
V_30 -> V_204 = F_89 ( V_14 , V_58 ) ;
V_30 -> V_205 = 1 ;
V_30 -> V_206 = 1 ;
if ( V_30 -> V_147 ) {
F_8 ( V_1 -> V_34 ,
L_63 ,
V_165 , V_14 ,
V_30 -> V_152 ? L_64 : L_65 ,
V_30 -> V_146
? L_66 : L_58 ,
V_30 -> V_147 ) ;
}
if ( V_30 -> V_150 && ! V_30 -> V_152 ) {
F_8 ( V_1 -> V_34 ,
L_63 ,
V_165 , V_14 ,
L_67 ,
V_30 -> V_149
? L_66 : L_58 ,
V_30 -> V_150 ) ;
}
if ( ! ( V_30 -> V_147 || V_30 -> V_150 ) )
F_8 ( V_1 -> V_34 , L_68 , V_14 ) ;
}
return 0 ;
}
static T_6 F_90 ( int V_207 , void * V_208 )
{
unsigned long V_45 ;
T_6 V_209 = V_71 ;
struct V_1 * V_1 = V_208 ;
F_32 ( & V_1 -> V_46 , V_45 ) ;
V_1 -> V_66 = F_12 ( V_1 -> V_40 , V_125 ) ;
V_1 -> V_210 = F_26 ( V_1 -> V_40 , V_126 ) ;
V_1 -> V_211 = F_26 ( V_1 -> V_40 , V_127 ) ;
if ( V_1 -> V_66 || V_1 -> V_210 || V_1 -> V_211 )
V_209 = F_91 ( V_1 ) ;
F_36 ( & V_1 -> V_46 , V_45 ) ;
return V_209 ;
}
T_6 F_91 ( struct V_1 * V_1 )
{
T_6 V_209 = V_71 ;
T_4 V_67 , V_16 ;
int V_212 ;
T_2 V_59 ;
V_67 = F_12 ( V_1 -> V_40 , V_88 ) ;
V_16 = F_12 ( V_1 -> V_40 , V_18 ) ;
F_8 ( V_1 -> V_34 , L_69 ,
( V_67 & V_74 ) ? L_16 : L_17 ,
V_1 -> V_66 , V_1 -> V_210 , V_1 -> V_211 ) ;
if ( V_1 -> V_66 )
V_209 |= F_40 ( V_1 , V_1 -> V_66 ,
V_67 , V_16 ) ;
if ( V_1 -> V_210 & 1 ) {
if ( V_67 & V_74 )
V_209 |= F_92 ( V_1 ) ;
else
V_209 |= F_93 ( V_1 ) ;
}
V_59 = V_1 -> V_211 >> 1 ;
V_212 = 1 ;
while ( V_59 ) {
if ( V_59 & 1 ) {
V_209 = V_73 ;
if ( V_67 & V_74 )
F_94 ( V_1 , V_212 ) ;
else
F_95 ( V_1 , V_212 ) ;
}
V_59 >>= 1 ;
V_212 ++ ;
}
V_59 = V_1 -> V_210 >> 1 ;
V_212 = 1 ;
while ( V_59 ) {
if ( V_59 & 1 ) {
V_209 = V_73 ;
if ( V_67 & V_74 )
F_96 ( V_1 , V_212 ) ;
else
F_97 ( V_1 , V_212 ) ;
}
V_59 >>= 1 ;
V_212 ++ ;
}
return V_209 ;
}
void F_98 ( struct V_1 * V_1 , T_4 V_35 , T_4 V_213 )
{
T_4 V_67 = F_12 ( V_1 -> V_40 , V_88 ) ;
if ( ! V_35 ) {
#ifndef F_99
if ( ! F_100 () ) {
if ( V_67 & V_74 )
F_92 ( V_1 ) ;
else
F_93 ( V_1 ) ;
}
#endif
} else {
if ( V_213 ) {
if ( V_67 & V_74 )
F_96 ( V_1 , V_35 ) ;
else
F_97 ( V_1 , V_35 ) ;
} else {
if ( V_67 & V_74 )
F_94 ( V_1 , V_35 ) ;
else
F_95 ( V_1 , V_35 ) ;
}
}
}
static T_8
F_101 ( struct V_2 * V_3 , struct V_214 * V_215 , char * V_216 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_45 ;
int V_5 = - V_170 ;
F_32 ( & V_1 -> V_46 , V_45 ) ;
V_5 = sprintf ( V_216 , L_70 , F_34 ( V_1 -> V_47 -> V_48 ) ) ;
F_36 ( & V_1 -> V_46 , V_45 ) ;
return V_5 ;
}
static T_8
F_102 ( struct V_2 * V_3 , struct V_214 * V_215 ,
const char * V_216 , T_9 V_153 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_45 ;
int V_176 ;
F_32 ( & V_1 -> V_46 , V_45 ) ;
if ( F_103 ( V_216 , L_16 ) )
V_176 = F_104 ( V_1 , V_217 ) ;
else if ( F_103 ( V_216 , L_17 ) )
V_176 = F_104 ( V_1 , V_218 ) ;
else if ( F_103 ( V_216 , L_71 ) )
V_176 = F_104 ( V_1 , V_219 ) ;
else
V_176 = - V_170 ;
F_36 ( & V_1 -> V_46 , V_45 ) ;
return ( V_176 == 0 ) ? V_153 : V_176 ;
}
static T_8
F_105 ( struct V_2 * V_3 , struct V_214 * V_215 ,
const char * V_216 , T_9 V_153 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_45 ;
unsigned long V_220 ;
if ( sscanf ( V_216 , L_72 , & V_220 ) < 1 ) {
F_5 ( V_3 , L_73 ) ;
return - V_170 ;
}
F_32 ( & V_1 -> V_46 , V_45 ) ;
V_1 -> V_99 = V_220 ? F_106 ( int , V_220 , V_100 ) : 0 ;
if ( V_1 -> V_47 -> V_48 == V_53 )
V_1 -> V_51 = 0 ;
F_47 ( V_1 , V_80 + F_41 ( V_220 ) ) ;
F_36 ( & V_1 -> V_46 , V_45 ) ;
return V_153 ;
}
static T_8
F_107 ( struct V_2 * V_3 , struct V_214 * V_215 , char * V_216 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_45 ;
unsigned long V_220 ;
int V_221 ;
F_32 ( & V_1 -> V_46 , V_45 ) ;
V_220 = V_1 -> V_99 ;
V_221 = F_108 ( V_1 ) ;
F_36 ( & V_1 -> V_46 , V_45 ) ;
return sprintf ( V_216 , L_74 ,
V_221 ? L_75 : L_76 , V_220 ) ;
}
static T_8
F_109 ( struct V_2 * V_3 , struct V_214 * V_215 ,
const char * V_216 , T_9 V_153 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned short V_222 ;
if ( sscanf ( V_216 , L_77 , & V_222 ) != 1
|| ( V_222 != 1 ) ) {
F_5 ( V_3 , L_78 ) ;
return - V_170 ;
}
if ( V_222 == 1 )
F_110 ( V_1 ) ;
return V_153 ;
}
static void F_111 ( struct V_223 * V_28 )
{
struct V_1 * V_1 = F_112 ( V_28 , struct V_1 , V_120 ) ;
if ( V_1 -> V_47 -> V_48 != V_1 -> V_224 ) {
V_1 -> V_224 = V_1 -> V_47 -> V_48 ;
F_113 ( & V_1 -> V_34 -> V_225 , NULL , L_79 ) ;
}
}
static struct V_1 * T_7
F_114 ( struct V_2 * V_3 ,
struct V_226 * V_138 , void T_3 * V_58 )
{
struct V_1 * V_1 ;
struct V_29 * V_227 ;
int V_35 ;
struct V_56 * V_57 ;
V_57 = F_115 ( & V_228 , V_3 , F_116 ( V_3 ) ) ;
if ( ! V_57 )
return NULL ;
V_1 = F_117 ( V_57 ) ;
F_118 ( & V_1 -> V_229 ) ;
F_118 ( & V_1 -> V_230 ) ;
F_118 ( & V_1 -> V_231 ) ;
V_57 -> V_232 = 1 ;
V_57 -> V_233 = 1 ;
V_1 -> V_96 = V_234 ;
V_1 -> V_99 = V_100 ;
F_119 ( V_3 , V_1 ) ;
V_1 -> V_40 = V_58 ;
V_1 -> V_235 = V_58 ;
V_1 -> V_236 = - V_237 ;
V_1 -> V_138 = V_138 ;
F_120 ( V_1 -> V_138 -> V_169 > V_238 ) ;
for ( V_35 = 0 , V_227 = V_1 -> V_39 ;
V_35 < V_1 -> V_138 -> V_169 ;
V_35 ++ , V_227 ++ ) {
V_227 -> V_1 = V_1 ;
V_227 -> V_35 = V_35 ;
}
V_1 -> V_34 = V_3 ;
return V_1 ;
}
static void F_121 ( struct V_1 * V_1 )
{
#ifdef F_122
F_123 ( & V_1 -> V_34 -> V_225 , & V_239 ) ;
#endif
if ( V_1 -> V_236 >= 0 ) {
if ( V_1 -> V_240 )
F_124 ( V_1 -> V_236 ) ;
F_125 ( V_1 -> V_236 , V_1 ) ;
}
if ( F_126 () && V_1 -> V_241 ) {
struct V_241 * V_242 = V_1 -> V_241 ;
( void ) V_242 -> V_243 ( V_242 ) ;
F_127 ( V_242 ) ;
}
F_128 ( F_38 ( V_1 ) ) ;
}
static int T_7
F_129 ( struct V_2 * V_3 , int V_236 , void T_3 * V_244 )
{
int V_176 ;
struct V_1 * V_1 ;
struct V_245 * V_246 = V_3 -> V_247 ;
struct V_56 * V_57 ;
if ( ! V_246 ) {
F_8 ( V_3 , L_80 ) ;
V_176 = - V_237 ;
goto V_248;
}
V_1 = F_114 ( V_3 , V_246 -> V_138 , V_244 ) ;
if ( ! V_1 ) {
V_176 = - V_8 ;
goto V_248;
}
F_130 ( V_1 -> V_34 ) ;
F_131 ( V_1 -> V_34 , 200 ) ;
F_132 ( V_1 -> V_34 ) ;
F_133 ( & V_1 -> V_46 ) ;
V_1 -> V_249 = V_246 -> V_250 ;
V_1 -> V_251 = V_246 -> V_251 ;
V_1 -> V_252 = V_246 -> V_253 ;
V_1 -> V_254 = F_90 ;
V_176 = F_134 ( V_1 ) ;
if ( V_176 < 0 )
goto V_255;
if ( ! V_1 -> V_254 ) {
V_176 = - V_237 ;
goto V_256;
}
if ( ! V_1 -> V_47 -> V_257 ) {
V_1 -> V_47 -> V_17 = V_1 -> V_34 ;
V_1 -> V_47 -> V_13 = V_1 -> V_40 ;
V_1 -> V_47 -> V_257 = & V_258 ;
}
F_11 ( V_1 -> V_34 ) ;
#ifndef F_135
if ( V_259 && V_3 -> V_260 ) {
struct V_241 * V_242 ;
V_242 = F_136 ( V_1 , V_1 -> V_40 ) ;
V_1 -> V_241 = V_242 ;
if ( V_242 )
( void ) V_242 -> V_261 ( V_242 ) ;
}
#endif
if ( ! F_126 () || ! V_1 -> V_241 )
V_3 -> V_260 = NULL ;
F_62 ( V_1 ) ;
F_60 ( V_1 ) ;
V_176 = F_79 ( V_246 -> V_138 -> V_262
? V_189
: V_263 , V_1 ) ;
if ( V_176 < 0 )
goto V_264;
F_137 ( & V_1 -> V_103 , F_31 , ( unsigned long ) V_1 ) ;
F_138 ( & V_1 -> V_120 , F_111 ) ;
if ( F_139 ( V_236 , V_1 -> V_254 , 0 , F_116 ( V_3 ) , V_1 ) ) {
F_5 ( V_3 , L_81 , V_236 ) ;
V_176 = - V_237 ;
goto V_264;
}
V_1 -> V_236 = V_236 ;
if ( F_140 ( V_236 ) == 0 ) {
V_1 -> V_240 = 1 ;
F_141 ( V_3 , 1 ) ;
} else {
V_1 -> V_240 = 0 ;
}
V_57 = F_38 ( V_1 ) ;
F_142 ( V_1 -> V_47 -> V_69 , & V_57 -> V_62 ) ;
V_57 -> V_62 . V_265 = 1 ;
V_1 -> V_47 -> V_69 -> V_105 = & V_57 -> V_62 ;
V_57 -> V_266 = 2 * ( V_246 -> V_16 ? : 250 ) ;
if ( V_246 -> V_267 ) {
T_4 V_268 = F_143 ( V_1 -> V_40 ) ;
V_268 |= V_269 ;
F_144 ( V_1 -> V_40 , V_268 ) ;
}
F_39 ( V_1 ) ;
V_1 -> V_47 -> V_69 -> V_270 = 0 ;
V_1 -> V_47 -> V_48 = V_85 ;
V_176 = F_145 ( V_1 ) ;
if ( V_176 < 0 )
goto V_264;
V_176 = F_146 ( V_1 ) ;
if ( V_176 < 0 )
goto V_271;
#ifdef F_122
V_176 = F_147 ( & V_1 -> V_34 -> V_225 , & V_239 ) ;
if ( V_176 )
goto V_272;
#endif
F_14 ( V_1 -> V_34 ) ;
return 0 ;
V_272:
F_148 ( V_1 ) ;
V_271:
F_64 ( V_1 ) ;
V_264:
F_149 ( V_1 -> V_34 ) ;
V_256:
if ( V_1 -> V_240 )
F_141 ( V_3 , 0 ) ;
F_65 ( V_1 ) ;
V_255:
F_5 ( V_1 -> V_34 ,
L_82 , V_176 ) ;
F_121 ( V_1 ) ;
V_248:
return V_176 ;
}
static int T_7 F_150 ( struct V_128 * V_129 )
{
struct V_2 * V_3 = & V_129 -> V_3 ;
int V_207 = F_151 ( V_129 , L_83 ) ;
int V_176 ;
struct V_273 * V_274 ;
void T_3 * V_275 ;
V_274 = F_152 ( V_129 , V_276 , 0 ) ;
if ( ! V_274 || V_207 <= 0 )
return - V_237 ;
V_275 = F_153 ( V_274 -> V_261 , F_154 ( V_274 ) ) ;
if ( ! V_275 ) {
F_5 ( V_3 , L_84 ) ;
return - V_8 ;
}
V_176 = F_129 ( V_3 , V_207 , V_275 ) ;
if ( V_176 < 0 )
F_155 ( V_275 ) ;
return V_176 ;
}
static int T_10 F_156 ( struct V_128 * V_129 )
{
struct V_2 * V_3 = & V_129 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
void T_3 * V_235 = V_1 -> V_235 ;
F_148 ( V_1 ) ;
F_63 ( V_129 ) ;
F_121 ( V_1 ) ;
F_155 ( V_235 ) ;
F_141 ( V_3 , 0 ) ;
#ifndef F_135
F_157 ( V_3 , * V_3 -> V_277 -> V_260 ) ;
#endif
return 0 ;
}
static void F_158 ( struct V_1 * V_1 )
{
int V_14 ;
void T_3 * V_278 = V_1 -> V_40 ;
void T_3 * V_279 ;
V_1 -> V_280 . V_281 = F_26 ( V_278 , V_282 ) ;
V_1 -> V_280 . V_283 = F_12 ( V_278 , V_121 ) ;
V_1 -> V_280 . V_268 = F_143 ( V_1 -> V_40 ) ;
V_1 -> V_280 . V_16 = F_12 ( V_278 , V_18 ) ;
V_1 -> V_280 . V_284 = F_26 ( V_278 , V_107 ) ;
V_1 -> V_280 . V_285 = F_26 ( V_278 , V_109 ) ;
V_1 -> V_280 . V_286 = F_12 ( V_278 , V_110 ) ;
V_1 -> V_280 . V_36 = F_12 ( V_278 , V_142 ) ;
V_1 -> V_280 . V_67 = F_12 ( V_278 , V_88 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_138 -> V_169 ; ++ V_14 ) {
struct V_29 * V_30 ;
V_30 = & V_1 -> V_39 [ V_14 ] ;
if ( ! V_30 )
continue;
V_279 = V_30 -> V_38 ;
if ( ! V_279 )
continue;
F_13 ( V_278 , V_142 , V_14 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_288 =
F_26 ( V_279 , V_289 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_290 =
F_26 ( V_279 , V_291 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_292 =
F_26 ( V_279 , V_293 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_294 =
F_26 ( V_279 , V_295 ) ;
if ( V_1 -> V_179 ) {
V_1 -> V_280 . V_287 [ V_14 ] . V_296 =
F_159 ( V_278 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_297 =
F_160 ( V_278 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_298 =
F_161 ( V_278 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_299 =
F_162 ( V_278 ) ;
}
V_1 -> V_280 . V_287 [ V_14 ] . V_300 =
F_12 ( V_279 , V_301 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_302 =
F_12 ( V_279 , V_303 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_304 =
F_12 ( V_279 , V_305 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_306 =
F_12 ( V_279 , V_307 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_308 =
F_163 ( V_278 , V_14 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_309 =
F_164 ( V_278 , V_14 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_310 =
F_165 ( V_278 , V_14 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_311 =
F_166 ( V_278 , V_14 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_312 =
F_167 ( V_278 , V_14 ) ;
V_1 -> V_280 . V_287 [ V_14 ] . V_313 =
F_168 ( V_278 , V_14 ) ;
}
}
static void F_169 ( struct V_1 * V_1 )
{
int V_14 ;
void T_3 * V_278 = V_1 -> V_40 ;
void T_3 * V_314 ;
void T_3 * V_279 ;
F_21 ( V_278 , V_282 , V_1 -> V_280 . V_281 ) ;
F_13 ( V_278 , V_121 , V_1 -> V_280 . V_283 ) ;
F_144 ( V_1 -> V_40 , V_1 -> V_280 . V_268 ) ;
F_13 ( V_278 , V_18 , V_1 -> V_280 . V_16 ) ;
F_21 ( V_278 , V_107 , V_1 -> V_280 . V_284 ) ;
F_21 ( V_278 , V_109 , V_1 -> V_280 . V_285 ) ;
F_13 ( V_278 , V_110 , V_1 -> V_280 . V_286 ) ;
F_13 ( V_278 , V_88 , V_1 -> V_280 . V_67 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_138 -> V_169 ; ++ V_14 ) {
struct V_29 * V_30 ;
V_30 = & V_1 -> V_39 [ V_14 ] ;
if ( ! V_30 )
continue;
V_279 = V_30 -> V_38 ;
if ( ! V_279 )
continue;
F_13 ( V_278 , V_142 , V_14 ) ;
F_21 ( V_279 , V_289 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_288 ) ;
F_21 ( V_279 , V_291 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_290 ) ;
F_21 ( V_279 , V_293 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_292 ) ;
F_21 ( V_279 , V_295 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_294 ) ;
if ( V_1 -> V_179 ) {
F_69 ( V_278 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_298 ) ;
F_71 ( V_278 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_299 ) ;
F_70 ( V_278 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_296 ) ;
F_72 ( V_278 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_297 ) ;
}
F_13 ( V_279 , V_301 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_300 ) ;
F_13 ( V_279 , V_303 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_302 ) ;
F_13 ( V_279 , V_305 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_304 ) ;
F_13 ( V_279 , V_307 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_306 ) ;
F_170 ( V_278 , V_14 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_308 ) ;
F_171 ( V_278 , V_14 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_309 ) ;
F_172 ( V_278 , V_14 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_310 ) ;
V_314 =
F_89 ( V_14 , V_278 ) ;
F_173 ( V_314 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_311 ) ;
F_174 ( V_314 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_312 ) ;
F_175 ( V_314 ,
V_1 -> V_280 . V_287 [ V_14 ] . V_313 ) ;
}
F_13 ( V_278 , V_142 , V_1 -> V_280 . V_36 ) ;
}
static int F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_45 ;
F_32 ( & V_1 -> V_46 , V_45 ) ;
if ( F_50 ( V_1 ) ) {
} else if ( F_177 ( V_1 ) ) {
}
F_36 ( & V_1 -> V_46 , V_45 ) ;
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
static int V_315 = 1 ;
if ( ! V_315 )
F_169 ( V_1 ) ;
V_315 = 0 ;
return 0 ;
}
static int T_11 F_181 ( void )
{
if ( F_182 () )
return 0 ;
F_183 ( L_85 V_316 L_86
L_87
L_86
L_88 ,
V_165 ) ;
return F_184 ( & V_317 ) ;
}
static void T_12 F_185 ( void )
{
F_186 ( & V_317 ) ;
}
