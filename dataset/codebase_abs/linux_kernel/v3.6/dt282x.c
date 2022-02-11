static void F_1 ( struct V_1 * V_2 , short * V_3 ,
unsigned int V_4 )
{
unsigned int V_5 ;
unsigned short V_6 = ( 1 << V_7 . V_8 ) - 1 ;
unsigned short V_9 = 1 << ( V_7 . V_8 - 1 ) ;
int V_10 ;
if ( V_11 -> V_12 )
V_9 = 1 << ( V_7 . V_8 - 1 ) ;
else
V_9 = 0 ;
if ( V_4 % 2 )
F_2 ( V_2 , L_1 ) ;
V_10 = V_4 / 2 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ )
V_3 [ V_5 ] = ( V_3 [ V_5 ] & V_6 ) ^ V_9 ;
}
static void F_3 ( struct V_1 * V_2 )
{
void * V_13 ;
int V_14 ;
int V_5 ;
struct V_15 * V_16 = V_2 -> V_17 + 1 ;
F_4 ( V_11 -> V_18 | V_19 , V_2 -> V_20 + V_21 ) ;
if ( ! V_16 -> V_22 -> V_23 ) {
F_5 ( V_24 L_2 ) ;
return;
}
V_5 = V_11 -> V_25 ;
V_13 = V_11 -> V_26 [ V_5 ] . V_3 ;
F_6 ( V_11 -> V_26 [ V_5 ] . V_27 ) ;
V_11 -> V_25 = 1 - V_5 ;
V_14 = F_7 ( V_16 , V_13 , V_11 -> V_28 ) ;
if ( V_14 == 0 ) {
F_5 ( V_24 L_3 ) ;
F_8 ( V_2 , V_16 ) ;
V_16 -> V_22 -> V_29 |= V_30 ;
return;
}
F_9 ( V_2 , V_5 , V_14 ) ;
return;
}
static void F_10 ( struct V_1 * V_2 )
{
void * V_13 ;
int V_14 ;
int V_5 ;
int V_31 ;
struct V_15 * V_16 = V_2 -> V_17 ;
F_4 ( V_11 -> V_18 | V_19 , V_2 -> V_20 + V_21 ) ;
if ( ! V_16 -> V_22 -> V_23 ) {
F_5 ( V_24 L_2 ) ;
return;
}
V_5 = V_11 -> V_25 ;
V_13 = V_11 -> V_26 [ V_5 ] . V_3 ;
V_14 = V_11 -> V_26 [ V_5 ] . V_14 ;
F_6 ( V_11 -> V_26 [ V_5 ] . V_27 ) ;
V_11 -> V_25 = 1 - V_5 ;
F_1 ( V_2 , V_13 , V_14 ) ;
V_31 = F_11 ( V_16 , V_13 , V_14 ) ;
if ( V_31 != V_14 ) {
F_12 ( V_2 , V_16 ) ;
return;
}
V_11 -> V_32 -= V_14 / 2 ;
if ( V_11 -> V_32 < 0 ) {
F_5 ( V_33 L_4 ) ;
V_11 -> V_32 = 0 ;
}
if ( ! V_11 -> V_32 ) {
F_12 ( V_2 , V_16 ) ;
V_16 -> V_22 -> V_29 |= V_34 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR);
}
#endif
F_13 ( V_2 , V_5 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_35 , int V_10 )
{
int V_36 ;
unsigned long V_37 ;
unsigned long V_38 ;
if ( ! V_11 -> V_39 )
return 0 ;
if ( V_10 == 0 )
V_10 = V_11 -> V_28 ;
if ( V_10 > V_11 -> V_39 * 2 )
V_10 = V_11 -> V_39 * 2 ;
V_11 -> V_39 -= V_10 / 2 ;
V_11 -> V_26 [ V_35 ] . V_14 = V_10 ;
V_36 = V_11 -> V_26 [ V_35 ] . V_27 ;
V_37 = F_14 ( V_11 -> V_26 [ V_35 ] . V_3 ) ;
F_15 ( V_36 , V_40 ) ;
V_38 = F_16 () ;
F_17 ( V_36 ) ;
F_18 ( V_36 , V_37 ) ;
F_19 ( V_36 , V_10 ) ;
F_20 ( V_38 ) ;
F_21 ( V_36 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , int V_35 , int V_10 )
{
int V_36 ;
unsigned long V_37 ;
unsigned long V_38 ;
V_11 -> V_26 [ V_35 ] . V_14 = V_10 ;
V_36 = V_11 -> V_26 [ V_35 ] . V_27 ;
V_37 = F_14 ( V_11 -> V_26 [ V_35 ] . V_3 ) ;
F_15 ( V_36 , V_41 ) ;
V_38 = F_16 () ;
F_17 ( V_36 ) ;
F_18 ( V_36 , V_37 ) ;
F_19 ( V_36 , V_10 ) ;
F_20 ( V_38 ) ;
F_21 ( V_36 ) ;
return V_10 ;
}
static T_1 F_22 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_15 * V_16 ;
struct V_15 * V_44 ;
unsigned int V_18 , V_45 , V_46 ;
int V_47 = 0 ;
if ( ! V_2 -> V_48 ) {
F_2 ( V_2 , L_5 ) ;
return V_49 ;
}
V_16 = V_2 -> V_17 + 0 ;
V_44 = V_2 -> V_17 + 1 ;
V_45 = F_23 ( V_2 -> V_20 + V_50 ) ;
V_46 = F_23 ( V_2 -> V_20 + V_51 ) ;
V_18 = F_23 ( V_2 -> V_20 + V_21 ) ;
if ( V_18 & V_52 ) {
if ( V_11 -> V_53 == V_40 )
F_10 ( V_2 ) ;
else
F_3 ( V_2 ) ;
V_47 = 1 ;
}
if ( V_45 & V_54 ) {
if ( V_11 -> V_32 != 0 ) {
F_2 ( V_2 , L_6 ) ;
F_12 ( V_2 , V_16 ) ;
V_16 -> V_22 -> V_29 |= V_55 ;
}
V_47 = 1 ;
}
if ( V_46 & V_56 ) {
#if 0
static int warn = 5;
if (--warn <= 0) {
disable_irq(dev->irq);
printk(KERN_INFO "disabling irq\n");
}
#endif
F_2 ( V_2 , L_7 ) ;
F_8 ( V_2 , V_44 ) ;
V_16 -> V_22 -> V_29 |= V_55 ;
V_47 = 1 ;
}
#if 0
if (adcsr & DT2821_ADDONE) {
int ret;
short data;
data = (short)inw(dev->iobase + DT2821_ADDAT);
data &= (1 << boardtype.adbits) - 1;
if (devpriv->ad_2scomp)
data ^= 1 << (boardtype.adbits - 1);
ret = comedi_buf_put(s->async, data);
if (ret == 0)
s->async->events |= COMEDI_CB_OVERFLOW;
devpriv->nread--;
if (!devpriv->nread) {
s->async->events |= COMEDI_CB_EOA;
} else {
if (supcsr & DT2821_SCDN)
outw(devpriv->supcsr | DT2821_STRIG,
dev->iobase + DT2821_SUPCSR);
}
handled = 1;
}
#endif
F_24 ( V_2 , V_16 ) ;
return F_25 ( V_47 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_10 ,
unsigned int * V_57 )
{
unsigned int V_5 ;
unsigned int V_27 , V_58 ;
F_4 ( V_59 | ( V_10 - 1 ) , V_2 -> V_20 + V_60 ) ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
V_27 = F_27 ( V_57 [ V_5 ] ) ;
V_58 = F_28 ( V_57 [ V_5 ] ) ;
F_4 ( V_11 -> V_45 | ( V_58 << 4 ) | V_27 ,
V_2 -> V_20 + V_50 ) ;
}
F_4 ( V_10 - 1 , V_2 -> V_20 + V_60 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
int V_5 ;
V_11 -> V_45 = V_64 ;
F_4 ( V_11 -> V_45 , V_2 -> V_20 + V_50 ) ;
F_26 ( V_2 , 1 , & V_62 -> V_65 ) ;
F_4 ( V_11 -> V_18 | V_66 , V_2 -> V_20 + V_21 ) ;
F_30 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
for ( V_5 = 0 ; V_5 < V_62 -> V_10 ; V_5 ++ ) {
F_4 ( V_11 -> V_18 | V_67 ,
V_2 -> V_20 + V_21 ) ;
F_30 (ad_done(), comedi_error(dev, L_8);
return -ETIME;) ;
V_63 [ V_5 ] =
F_23 ( V_2 -> V_20 +
V_68 ) & ( ( 1 << V_7 . V_8 ) - 1 ) ;
if ( V_11 -> V_12 )
V_63 [ V_5 ] ^= ( 1 << ( V_7 . V_8 - 1 ) ) ;
}
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_69 * V_70 )
{
const struct V_71 * V_72 = F_32 ( V_2 ) ;
int V_73 = 0 ;
int V_74 ;
V_74 = V_70 -> V_75 ;
V_70 -> V_75 &= V_76 ;
if ( ! V_70 -> V_75 || V_74 != V_70 -> V_75 )
V_73 ++ ;
V_74 = V_70 -> V_77 ;
V_70 -> V_77 &= V_78 | V_79 ;
if ( ! V_70 -> V_77 || V_74 != V_70 -> V_77 )
V_73 ++ ;
V_74 = V_70 -> V_80 ;
V_70 -> V_80 &= V_81 ;
if ( ! V_70 -> V_80 || V_74 != V_70 -> V_80 )
V_73 ++ ;
V_74 = V_70 -> V_82 ;
V_70 -> V_82 &= V_83 ;
if ( ! V_70 -> V_82 || V_74 != V_70 -> V_82 )
V_73 ++ ;
V_74 = V_70 -> V_84 ;
V_70 -> V_84 &= V_83 | V_85 ;
if ( ! V_70 -> V_84 || V_74 != V_70 -> V_84 )
V_73 ++ ;
if ( V_73 )
return 1 ;
if ( V_70 -> V_77 != V_78 &&
V_70 -> V_77 != V_79 )
V_73 ++ ;
if ( V_70 -> V_84 != V_83 && V_70 -> V_84 != V_85 )
V_73 ++ ;
if ( V_73 )
return 2 ;
if ( V_70 -> V_86 != 0 ) {
V_70 -> V_86 = 0 ;
V_73 ++ ;
}
if ( V_70 -> V_77 == V_78 ) {
if ( V_70 -> V_87 != 0 ) {
V_70 -> V_87 = 0 ;
V_73 ++ ;
}
} else {
if ( V_70 -> V_87 != 0 ) {
V_70 -> V_87 = 0 ;
V_73 ++ ;
}
}
if ( V_70 -> V_88 < 4000 ) {
V_70 -> V_88 = 4000 ;
V_73 ++ ;
}
#define F_33 (250*(1<<15)*255)
if ( V_70 -> V_88 > F_33 ) {
V_70 -> V_88 = F_33 ;
V_73 ++ ;
}
if ( V_70 -> V_88 < V_72 -> V_89 ) {
V_70 -> V_88 = V_72 -> V_89 ;
V_73 ++ ;
}
if ( V_70 -> V_90 != V_70 -> V_91 ) {
V_70 -> V_90 = V_70 -> V_91 ;
V_73 ++ ;
}
if ( V_70 -> V_84 == V_83 ) {
} else {
if ( V_70 -> V_92 != 0 ) {
V_70 -> V_92 = 0 ;
V_73 ++ ;
}
}
if ( V_73 )
return 3 ;
V_74 = V_70 -> V_88 ;
F_34 ( & V_70 -> V_88 , V_70 -> V_38 & V_93 ) ;
if ( V_74 != V_70 -> V_88 )
V_73 ++ ;
if ( V_73 )
return 4 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
const struct V_71 * V_72 = F_32 ( V_2 ) ;
struct V_69 * V_70 = & V_16 -> V_22 -> V_70 ;
int V_94 ;
if ( V_11 -> V_95 == 0 ) {
F_2 ( V_2 ,
L_9
L_10 ) ;
return - V_96 ;
}
F_36 ( V_2 ) ;
if ( V_70 -> V_88 < V_72 -> V_89 )
V_70 -> V_88 = V_72 -> V_89 ;
V_94 = F_34 ( & V_70 -> V_88 , V_97 ) ;
F_4 ( V_94 , V_2 -> V_20 + V_98 ) ;
if ( V_70 -> V_77 == V_78 ) {
V_11 -> V_18 = V_99 | V_100 ;
} else {
V_11 -> V_18 = V_99 | V_100 | V_101 ;
}
F_4 ( V_11 -> V_18 | V_19 | V_102 | V_103 ,
V_2 -> V_20 + V_21 ) ;
V_11 -> V_39 = V_70 -> V_92 * V_70 -> V_90 ;
V_11 -> V_32 = V_11 -> V_39 ;
V_11 -> V_53 = V_40 ;
V_11 -> V_25 = 0 ;
F_13 ( V_2 , 0 , 0 ) ;
if ( V_11 -> V_39 ) {
F_13 ( V_2 , 1 , 0 ) ;
V_11 -> V_18 |= V_104 ;
F_4 ( V_11 -> V_18 , V_2 -> V_20 + V_21 ) ;
}
V_11 -> V_45 = 0 ;
F_26 ( V_2 , V_70 -> V_91 , V_70 -> V_57 ) ;
V_11 -> V_45 = V_64 | V_105 ;
F_4 ( V_11 -> V_45 , V_2 -> V_20 + V_50 ) ;
F_4 ( V_11 -> V_18 | V_66 , V_2 -> V_20 + V_21 ) ;
F_30 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
if ( V_70 -> V_77 == V_78 ) {
F_4 ( V_11 -> V_18 | V_67 ,
V_2 -> V_20 + V_21 ) ;
} else {
V_11 -> V_18 |= V_106 ;
F_4 ( V_11 -> V_18 , V_2 -> V_20 + V_21 ) ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_11 -> V_95 ) {
F_6 ( V_11 -> V_26 [ 0 ] . V_27 ) ;
F_6 ( V_11 -> V_26 [ 1 ] . V_27 ) ;
}
}
static int F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_36 ( V_2 ) ;
V_11 -> V_45 = 0 ;
F_4 ( V_11 -> V_45 , V_2 -> V_20 + V_50 ) ;
V_11 -> V_18 = 0 ;
F_4 ( V_11 -> V_18 | V_103 , V_2 -> V_20 + V_21 ) ;
return 0 ;
}
static int F_34 ( int * V_107 , int V_108 )
{
int V_109 , V_110 , V_111 ;
for ( V_109 = 0 ; V_109 < 16 ; V_109 ++ ) {
if ( V_109 == 1 )
continue;
V_110 = 250 * ( 1 << V_109 ) ;
switch ( V_108 ) {
case V_97 :
default:
V_111 = ( * V_107 + V_110 / 2 ) / V_110 ;
break;
case V_112 :
V_111 = ( * V_107 ) / V_110 ;
break;
case V_113 :
V_111 = ( * V_107 + V_110 - 1 ) / V_110 ;
break;
}
if ( V_111 < 256 ) {
* V_107 = V_111 * V_110 ;
return ( V_109 << 8 ) | ( 255 - V_111 ) ;
}
}
V_110 = 250 * ( 1 << 15 ) ;
V_111 = 255 ;
* V_107 = V_111 * V_110 ;
return ( 15 << 8 ) | ( 255 - V_111 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
V_63 [ 0 ] = V_11 -> V_114 [ F_27 ( V_62 -> V_65 ) ] ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
short V_43 ;
unsigned int V_27 ;
V_27 = F_27 ( V_62 -> V_65 ) ;
V_43 = V_63 [ 0 ] ;
V_43 &= ( 1 << V_7 . V_115 ) - 1 ;
V_11 -> V_114 [ V_27 ] = V_43 ;
V_11 -> V_46 |= V_116 ;
if ( V_27 ) {
V_11 -> V_46 |= V_117 ;
if ( V_11 -> V_118 )
V_43 ^= ( 1 << ( V_7 . V_115 - 1 ) ) ;
} else {
V_11 -> V_46 &= ~ V_117 ;
if ( V_11 -> V_119 )
V_43 ^= ( 1 << ( V_7 . V_115 - 1 ) ) ;
}
F_4 ( V_11 -> V_46 , V_2 -> V_20 + V_51 ) ;
F_4 ( V_43 , V_2 -> V_20 + V_120 ) ;
F_4 ( V_11 -> V_18 | V_121 , V_2 -> V_20 + V_21 ) ;
return 1 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_69 * V_70 )
{
int V_73 = 0 ;
int V_74 ;
V_74 = V_70 -> V_75 ;
V_70 -> V_75 &= V_122 ;
if ( ! V_70 -> V_75 || V_74 != V_70 -> V_75 )
V_73 ++ ;
V_74 = V_70 -> V_77 ;
V_70 -> V_77 &= V_81 ;
if ( ! V_70 -> V_77 || V_74 != V_70 -> V_77 )
V_73 ++ ;
V_74 = V_70 -> V_80 ;
V_70 -> V_80 &= V_76 ;
if ( ! V_70 -> V_80 || V_74 != V_70 -> V_80 )
V_73 ++ ;
V_74 = V_70 -> V_82 ;
V_70 -> V_82 &= V_83 ;
if ( ! V_70 -> V_82 || V_74 != V_70 -> V_82 )
V_73 ++ ;
V_74 = V_70 -> V_84 ;
V_70 -> V_84 &= V_85 ;
if ( ! V_70 -> V_84 || V_74 != V_70 -> V_84 )
V_73 ++ ;
if ( V_73 )
return 1 ;
if ( V_70 -> V_84 != V_83 && V_70 -> V_84 != V_85 )
V_73 ++ ;
if ( V_73 )
return 2 ;
if ( V_70 -> V_86 != 0 ) {
V_70 -> V_86 = 0 ;
V_73 ++ ;
}
if ( V_70 -> V_87 < 5000 ) {
V_70 -> V_87 = 5000 ;
V_73 ++ ;
}
if ( V_70 -> V_88 != 0 ) {
V_70 -> V_88 = 0 ;
V_73 ++ ;
}
if ( V_70 -> V_90 > 2 ) {
V_70 -> V_90 = 2 ;
V_73 ++ ;
}
if ( V_70 -> V_84 == V_83 ) {
} else {
if ( V_70 -> V_92 != 0 ) {
V_70 -> V_92 = 0 ;
V_73 ++ ;
}
}
if ( V_73 )
return 3 ;
V_74 = V_70 -> V_87 ;
F_34 ( & V_70 -> V_87 , V_70 -> V_38 & V_93 ) ;
if ( V_74 != V_70 -> V_87 )
V_73 ++ ;
if ( V_73 )
return 4 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned int V_123 )
{
int V_14 ;
if ( V_123 != 0 )
return - V_124 ;
V_14 = F_7 ( V_16 , V_11 -> V_26 [ 0 ] . V_3 ,
V_11 -> V_28 ) ;
if ( V_14 == 0 ) {
F_5 ( V_24 L_3 ) ;
return - V_125 ;
}
F_9 ( V_2 , 0 , V_14 ) ;
V_14 = F_7 ( V_16 , V_11 -> V_26 [ 1 ] . V_3 ,
V_11 -> V_28 ) ;
if ( V_14 == 0 ) {
F_5 ( V_24 L_3 ) ;
return - V_125 ;
}
F_9 ( V_2 , 1 , V_14 ) ;
F_4 ( V_11 -> V_18 | V_67 , V_2 -> V_20 + V_21 ) ;
V_16 -> V_22 -> V_126 = NULL ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_94 ;
struct V_69 * V_70 = & V_16 -> V_22 -> V_70 ;
if ( V_11 -> V_95 == 0 ) {
F_2 ( V_2 ,
L_9
L_10 ) ;
return - V_96 ;
}
F_36 ( V_2 ) ;
V_11 -> V_18 = V_99 | V_101 | V_104 ;
F_4 ( V_11 -> V_18 | V_19 | V_102 | V_127 ,
V_2 -> V_20 + V_21 ) ;
V_11 -> V_39 = V_70 -> V_92 * V_70 -> V_91 ;
V_11 -> V_32 = V_11 -> V_39 ;
V_11 -> V_53 = V_41 ;
V_11 -> V_25 = 0 ;
V_94 = F_34 ( & V_70 -> V_87 , V_97 ) ;
F_4 ( V_94 , V_2 -> V_20 + V_98 ) ;
V_11 -> V_46 = V_116 | V_128 | V_129 ;
F_4 ( V_11 -> V_46 , V_2 -> V_20 + V_51 ) ;
V_16 -> V_22 -> V_126 = F_40 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_36 ( V_2 ) ;
V_11 -> V_46 = 0 ;
F_4 ( V_11 -> V_46 , V_2 -> V_20 + V_51 ) ;
V_11 -> V_18 = 0 ;
F_4 ( V_11 -> V_18 | V_127 , V_2 -> V_20 + V_21 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
if ( V_63 [ 0 ] ) {
V_16 -> V_130 &= ~ V_63 [ 0 ] ;
V_16 -> V_130 |= ( V_63 [ 0 ] & V_63 [ 1 ] ) ;
F_4 ( V_16 -> V_130 , V_2 -> V_20 + V_131 ) ;
}
V_63 [ 1 ] = F_23 ( V_2 -> V_20 + V_131 ) ;
return V_62 -> V_10 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
int V_6 ;
V_6 = ( F_27 ( V_62 -> V_65 ) < 8 ) ? 0x00ff : 0xff00 ;
if ( V_63 [ 0 ] )
V_16 -> V_132 |= V_6 ;
else
V_16 -> V_132 &= ~ V_6 ;
if ( V_16 -> V_132 & 0x00ff )
V_11 -> V_46 |= V_133 ;
else
V_11 -> V_46 &= ~ V_133 ;
if ( V_16 -> V_132 & 0xff00 )
V_11 -> V_46 |= V_134 ;
else
V_11 -> V_46 &= ~ V_134 ;
F_4 ( V_11 -> V_46 , V_2 -> V_20 + V_51 ) ;
return 1 ;
}
static const struct V_135 * F_44 ( int V_136 , int V_123 )
{
if ( V_136 ) {
if ( V_123 < 0 || V_123 >= 2 )
V_123 = 0 ;
return V_137 [ V_123 ] ;
} else {
if ( V_123 < 0 || V_123 >= 4 )
V_123 = 0 ;
return V_138 [ V_123 ] ;
}
}
static const struct V_135 * F_45 ( int V_123 )
{
if ( V_123 < 0 || V_123 >= 5 )
V_123 = 0 ;
return V_139 [ V_123 ] ;
}
static int F_46 ( struct V_1 * V_2 , int V_140 , int V_141 )
{
int V_31 ;
V_11 -> V_95 = 0 ;
if ( ! V_140 && ! V_141 ) {
F_5 ( V_24 L_11 ) ;
return 0 ;
}
if ( V_140 == V_141 || V_140 < 5 || V_141 < 5 || V_140 > 7 || V_141 > 7 )
return - V_124 ;
if ( V_141 < V_140 ) {
int V_5 ;
V_5 = V_140 ;
V_140 = V_141 ;
V_141 = V_5 ;
}
V_31 = F_47 ( V_140 , L_12 ) ;
if ( V_31 )
return - V_142 ;
V_11 -> V_26 [ 0 ] . V_27 = V_140 ;
V_31 = F_47 ( V_141 , L_13 ) ;
if ( V_31 )
return - V_142 ;
V_11 -> V_26 [ 1 ] . V_27 = V_141 ;
V_11 -> V_28 = V_143 ;
V_11 -> V_26 [ 0 ] . V_3 = ( void * ) F_48 ( V_144 | V_145 ) ;
V_11 -> V_26 [ 1 ] . V_3 = ( void * ) F_48 ( V_144 | V_145 ) ;
if ( ! V_11 -> V_26 [ 0 ] . V_3 || ! V_11 -> V_26 [ 1 ] . V_3 ) {
F_5 ( V_24 L_14 ) ;
return - V_146 ;
}
F_5 ( V_33 L_15 , V_140 , V_141 ) ;
V_11 -> V_95 = 1 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
const struct V_71 * V_72 = F_32 ( V_2 ) ;
int V_5 , V_42 ;
int V_31 ;
struct V_15 * V_16 ;
unsigned long V_20 ;
V_2 -> V_149 = V_72 -> V_150 ;
V_20 = V_148 -> V_151 [ V_152 ] ;
if ( ! V_20 )
V_20 = 0x240 ;
F_5 ( V_33 L_16 , V_2 -> V_153 , V_20 ) ;
if ( ! F_50 ( V_20 , V_154 , L_17 ) ) {
F_5 ( V_33 L_18 ) ;
return - V_142 ;
}
V_2 -> V_20 = V_20 ;
F_4 ( V_155 , V_2 -> V_20 + V_21 ) ;
V_5 = F_23 ( V_2 -> V_20 + V_50 ) ;
#ifdef F_51
F_5 ( V_156 L_19 ,
F_23 ( V_2 -> V_20 + V_50 ) ,
F_23 ( V_2 -> V_20 + V_60 ) ,
F_23 ( V_2 -> V_20 + V_51 ) ,
F_23 ( V_2 -> V_20 + V_21 ) ,
F_23 ( V_2 -> V_20 + V_98 ) ) ;
#endif
if ( ( ( F_23 ( V_2 -> V_20 + V_50 ) & V_157 )
!= V_158 ) ||
( ( F_23 ( V_2 -> V_20 + V_60 ) & V_159 )
!= V_160 ) ||
( ( F_23 ( V_2 -> V_20 + V_51 ) & V_161 )
!= V_162 ) ||
( ( F_23 ( V_2 -> V_20 + V_21 ) & V_163 )
!= V_164 ) ||
( ( F_23 ( V_2 -> V_20 + V_98 ) & V_165 )
!= V_166 ) ) {
F_5 ( V_24 L_20 ) ;
return - V_96 ;
}
V_42 = V_148 -> V_151 [ V_167 ] ;
#if 0
if (irq < 0) {
unsigned long flags;
int irqs;
save_flags(flags);
sti();
irqs = probe_irq_on();
udelay(100);
irq = probe_irq_off(irqs);
restore_flags(flags);
if (0 )
printk(KERN_ERR " error probing irq (bad)");
}
#endif
if ( V_42 > 0 ) {
F_5 ( V_33 L_21 , V_42 ) ;
V_31 = F_52 ( V_42 , F_22 , 0 , L_17 , V_2 ) ;
if ( V_31 < 0 ) {
F_5 ( V_24 L_22 ) ;
return - V_96 ;
}
V_2 -> V_42 = V_42 ;
} else if ( V_42 == 0 ) {
F_5 ( V_33 L_23 ) ;
} else {
#if 0
printk(KERN_INFO " (probe returned multiple irqs--bad)");
#else
F_5 ( V_33 L_24 ) ;
#endif
}
V_31 = F_53 ( V_2 , sizeof( struct V_168 ) ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_46 ( V_2 , V_148 -> V_151 [ V_169 ] ,
V_148 -> V_151 [ V_170 ] ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_54 ( V_2 , 3 ) ;
if ( V_31 )
return V_31 ;
V_16 = V_2 -> V_17 + 0 ;
V_2 -> V_171 = V_16 ;
V_16 -> type = V_172 ;
V_16 -> V_173 = V_174 | V_175 |
( ( V_148 -> V_151 [ V_176 ] ) ? V_177 : V_178 ) ;
V_16 -> V_179 =
( V_148 -> V_151 [ V_176 ] ) ? V_7 . V_180 : V_7 . V_181 ;
V_16 -> V_182 = F_29 ;
V_16 -> V_183 = F_31 ;
V_16 -> V_184 = F_35 ;
V_16 -> V_185 = F_12 ;
V_16 -> V_186 = ( 1 << V_7 . V_8 ) - 1 ;
V_16 -> V_187 = 16 ;
V_16 -> V_188 =
F_44 ( V_7 . V_136 , V_148 -> V_151 [ V_189 ] ) ;
V_11 -> V_12 = V_148 -> V_151 [ V_190 ] ;
V_16 ++ ;
V_16 -> V_179 = V_7 . V_191 ;
if ( V_16 -> V_179 ) {
V_16 -> type = V_192 ;
V_2 -> V_193 = V_16 ;
V_16 -> V_173 = V_194 | V_195 ;
V_16 -> V_182 = F_37 ;
V_16 -> V_196 = F_38 ;
V_16 -> V_183 = F_39 ;
V_16 -> V_184 = F_41 ;
V_16 -> V_185 = F_8 ;
V_16 -> V_186 = ( 1 << V_7 . V_115 ) - 1 ;
V_16 -> V_187 = 2 ;
V_16 -> V_197 = V_11 -> V_198 ;
V_11 -> V_198 [ 0 ] =
F_45 ( V_148 -> V_151 [ V_199 ] ) ;
V_11 -> V_198 [ 1 ] =
F_45 ( V_148 -> V_151 [ V_200 ] ) ;
V_11 -> V_118 = V_148 -> V_151 [ V_201 ] ;
V_11 -> V_119 = V_148 -> V_151 [ V_202 ] ;
} else {
V_16 -> type = V_203 ;
}
V_16 ++ ;
V_16 -> type = V_204 ;
V_16 -> V_173 = V_174 | V_194 ;
V_16 -> V_179 = 16 ;
V_16 -> V_205 = F_42 ;
V_16 -> V_206 = F_43 ;
V_16 -> V_186 = 1 ;
V_16 -> V_188 = & V_207 ;
F_5 ( V_33 L_25 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 )
F_56 ( V_2 -> V_42 , V_2 ) ;
if ( V_2 -> V_20 )
F_57 ( V_2 -> V_20 , V_154 ) ;
if ( V_2 -> V_208 ) {
if ( V_11 -> V_26 [ 0 ] . V_27 )
F_58 ( V_11 -> V_26 [ 0 ] . V_27 ) ;
if ( V_11 -> V_26 [ 1 ] . V_27 )
F_58 ( V_11 -> V_26 [ 1 ] . V_27 ) ;
if ( V_11 -> V_26 [ 0 ] . V_3 )
F_59 ( ( unsigned long ) V_11 -> V_26 [ 0 ] . V_3 ) ;
if ( V_11 -> V_26 [ 1 ] . V_3 )
F_59 ( ( unsigned long ) V_11 -> V_26 [ 1 ] . V_3 ) ;
}
}
