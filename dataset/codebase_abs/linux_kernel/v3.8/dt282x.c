static void F_1 ( struct V_1 * V_2 , short * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
unsigned short V_9 = ( 1 << V_10 . V_11 ) - 1 ;
unsigned short V_12 = 1 << ( V_10 . V_11 - 1 ) ;
int V_13 ;
if ( V_6 -> V_14 )
V_12 = 1 << ( V_10 . V_11 - 1 ) ;
else
V_12 = 0 ;
if ( V_4 % 2 )
F_2 ( V_2 , L_1 ) ;
V_13 = V_4 / 2 ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
V_3 [ V_8 ] = ( V_3 [ V_8 ] & V_9 ) ^ V_12 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void * V_15 ;
int V_16 ;
int V_8 ;
struct V_17 * V_18 = & V_2 -> V_19 [ 1 ] ;
F_4 ( V_6 -> V_20 | V_21 , V_2 -> V_22 + V_23 ) ;
if ( ! V_18 -> V_24 -> V_25 ) {
F_5 ( V_26 L_2 ) ;
return;
}
V_8 = V_6 -> V_27 ;
V_15 = V_6 -> V_28 [ V_8 ] . V_3 ;
F_6 ( V_6 -> V_28 [ V_8 ] . V_29 ) ;
V_6 -> V_27 = 1 - V_8 ;
V_16 = F_7 ( V_18 , V_15 , V_6 -> V_30 ) ;
if ( V_16 == 0 ) {
F_5 ( V_26 L_3 ) ;
F_8 ( V_2 , V_18 ) ;
V_18 -> V_24 -> V_31 |= V_32 ;
return;
}
F_9 ( V_2 , V_8 , V_16 ) ;
return;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void * V_15 ;
int V_16 ;
int V_8 ;
int V_33 ;
struct V_17 * V_18 = & V_2 -> V_19 [ 0 ] ;
F_4 ( V_6 -> V_20 | V_21 , V_2 -> V_22 + V_23 ) ;
if ( ! V_18 -> V_24 -> V_25 ) {
F_5 ( V_26 L_2 ) ;
return;
}
V_8 = V_6 -> V_27 ;
V_15 = V_6 -> V_28 [ V_8 ] . V_3 ;
V_16 = V_6 -> V_28 [ V_8 ] . V_16 ;
F_6 ( V_6 -> V_28 [ V_8 ] . V_29 ) ;
V_6 -> V_27 = 1 - V_8 ;
F_1 ( V_2 , V_15 , V_16 ) ;
V_33 = F_11 ( V_18 , V_15 , V_16 ) ;
if ( V_33 != V_16 ) {
F_12 ( V_2 , V_18 ) ;
return;
}
V_6 -> V_34 -= V_16 / 2 ;
if ( V_6 -> V_34 < 0 ) {
F_5 ( V_35 L_4 ) ;
V_6 -> V_34 = 0 ;
}
if ( ! V_6 -> V_34 ) {
F_12 ( V_2 , V_18 ) ;
V_18 -> V_24 -> V_31 |= V_36 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR);
}
#endif
F_13 ( V_2 , V_8 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_37 , int V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_38 ;
unsigned long V_39 ;
unsigned long V_40 ;
if ( ! V_6 -> V_41 )
return 0 ;
if ( V_13 == 0 )
V_13 = V_6 -> V_30 ;
if ( V_13 > V_6 -> V_41 * 2 )
V_13 = V_6 -> V_41 * 2 ;
V_6 -> V_41 -= V_13 / 2 ;
V_6 -> V_28 [ V_37 ] . V_16 = V_13 ;
V_38 = V_6 -> V_28 [ V_37 ] . V_29 ;
V_39 = F_14 ( V_6 -> V_28 [ V_37 ] . V_3 ) ;
F_15 ( V_38 , V_42 ) ;
V_40 = F_16 () ;
F_17 ( V_38 ) ;
F_18 ( V_38 , V_39 ) ;
F_19 ( V_38 , V_13 ) ;
F_20 ( V_40 ) ;
F_21 ( V_38 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 , int V_37 , int V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_38 ;
unsigned long V_39 ;
unsigned long V_40 ;
V_6 -> V_28 [ V_37 ] . V_16 = V_13 ;
V_38 = V_6 -> V_28 [ V_37 ] . V_29 ;
V_39 = F_14 ( V_6 -> V_28 [ V_37 ] . V_3 ) ;
F_15 ( V_38 , V_43 ) ;
V_40 = F_16 () ;
F_17 ( V_38 ) ;
F_18 ( V_38 , V_39 ) ;
F_19 ( V_38 , V_13 ) ;
F_20 ( V_40 ) ;
F_21 ( V_38 ) ;
return V_13 ;
}
static T_1 F_22 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 ;
struct V_17 * V_46 ;
unsigned int V_20 , V_47 , V_48 ;
int V_49 = 0 ;
if ( ! V_2 -> V_50 ) {
F_2 ( V_2 , L_5 ) ;
return V_51 ;
}
V_18 = & V_2 -> V_19 [ 0 ] ;
V_46 = & V_2 -> V_19 [ 1 ] ;
V_47 = F_23 ( V_2 -> V_22 + V_52 ) ;
V_48 = F_23 ( V_2 -> V_22 + V_53 ) ;
V_20 = F_23 ( V_2 -> V_22 + V_23 ) ;
if ( V_20 & V_54 ) {
if ( V_6 -> V_55 == V_42 )
F_10 ( V_2 ) ;
else
F_3 ( V_2 ) ;
V_49 = 1 ;
}
if ( V_47 & V_56 ) {
if ( V_6 -> V_34 != 0 ) {
F_2 ( V_2 , L_6 ) ;
F_12 ( V_2 , V_18 ) ;
V_18 -> V_24 -> V_31 |= V_57 ;
}
V_49 = 1 ;
}
if ( V_48 & V_58 ) {
#if 0
static int warn = 5;
if (--warn <= 0) {
disable_irq(dev->irq);
printk(KERN_INFO "disabling irq\n");
}
#endif
F_2 ( V_2 , L_7 ) ;
F_8 ( V_2 , V_46 ) ;
V_18 -> V_24 -> V_31 |= V_57 ;
V_49 = 1 ;
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
F_24 ( V_2 , V_18 ) ;
return F_25 ( V_49 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_13 ,
unsigned int * V_59 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
unsigned int V_29 , V_60 ;
F_4 ( V_61 | ( V_13 - 1 ) , V_2 -> V_22 + V_62 ) ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ ) {
V_29 = F_27 ( V_59 [ V_8 ] ) ;
V_60 = F_28 ( V_59 [ V_8 ] ) ;
F_4 ( V_6 -> V_47 | ( V_60 << 4 ) | V_29 ,
V_2 -> V_22 + V_52 ) ;
}
F_4 ( V_13 - 1 , V_2 -> V_22 + V_62 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_6 -> V_47 = V_66 ;
F_4 ( V_6 -> V_47 , V_2 -> V_22 + V_52 ) ;
F_26 ( V_2 , 1 , & V_64 -> V_67 ) ;
F_4 ( V_6 -> V_20 | V_68 , V_2 -> V_22 + V_23 ) ;
F_30 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
for ( V_8 = 0 ; V_8 < V_64 -> V_13 ; V_8 ++ ) {
F_4 ( V_6 -> V_20 | V_69 ,
V_2 -> V_22 + V_23 ) ;
F_30 (ad_done(), comedi_error(dev, L_8);
return -ETIME;) ;
V_65 [ V_8 ] =
F_23 ( V_2 -> V_22 +
V_70 ) & ( ( 1 << V_10 . V_11 ) - 1 ) ;
if ( V_6 -> V_14 )
V_65 [ V_8 ] ^= ( 1 << ( V_10 . V_11 - 1 ) ) ;
}
return V_8 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_17 * V_18 , struct V_71 * V_72 )
{
const struct V_73 * V_74 = F_32 ( V_2 ) ;
int V_75 = 0 ;
int V_76 ;
V_75 |= F_33 ( & V_72 -> V_77 , V_78 ) ;
V_75 |= F_33 ( & V_72 -> V_79 ,
V_80 | V_81 ) ;
V_75 |= F_33 ( & V_72 -> V_82 , V_83 ) ;
V_75 |= F_33 ( & V_72 -> V_84 , V_85 ) ;
V_75 |= F_33 ( & V_72 -> V_86 , V_85 | V_87 ) ;
if ( V_75 )
return 1 ;
V_75 |= F_34 ( V_72 -> V_79 ) ;
V_75 |= F_34 ( V_72 -> V_86 ) ;
if ( V_75 )
return 2 ;
V_75 |= F_35 ( & V_72 -> V_88 , 0 ) ;
if ( V_72 -> V_79 == V_80 ) {
V_75 |= F_35 ( & V_72 -> V_89 , 0 ) ;
} else {
V_75 |= F_35 ( & V_72 -> V_89 , 0 ) ;
}
V_75 |= F_36 ( & V_72 -> V_90 , 4000 ) ;
#define F_37 (250*(1<<15)*255)
V_75 |= F_38 ( & V_72 -> V_90 , F_37 ) ;
V_75 |= F_36 ( & V_72 -> V_90 , V_74 -> V_91 ) ;
V_75 |= F_35 ( & V_72 -> V_92 , V_72 -> V_93 ) ;
if ( V_72 -> V_86 == V_85 ) {
} else {
V_75 |= F_35 ( & V_72 -> V_94 , 0 ) ;
}
if ( V_75 )
return 3 ;
V_76 = V_72 -> V_90 ;
F_39 ( & V_72 -> V_90 , V_72 -> V_40 & V_95 ) ;
if ( V_76 != V_72 -> V_90 )
V_75 ++ ;
if ( V_75 )
return 4 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
const struct V_73 * V_74 = F_32 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_71 * V_72 = & V_18 -> V_24 -> V_72 ;
int V_96 ;
if ( V_6 -> V_97 == 0 ) {
F_2 ( V_2 ,
L_9
L_10 ) ;
return - V_98 ;
}
F_41 ( V_2 ) ;
if ( V_72 -> V_90 < V_74 -> V_91 )
V_72 -> V_90 = V_74 -> V_91 ;
V_96 = F_39 ( & V_72 -> V_90 , V_99 ) ;
F_4 ( V_96 , V_2 -> V_22 + V_100 ) ;
if ( V_72 -> V_79 == V_80 ) {
V_6 -> V_20 = V_101 | V_102 ;
} else {
V_6 -> V_20 = V_101 | V_102 | V_103 ;
}
F_4 ( V_6 -> V_20 | V_21 | V_104 | V_105 ,
V_2 -> V_22 + V_23 ) ;
V_6 -> V_41 = V_72 -> V_94 * V_72 -> V_92 ;
V_6 -> V_34 = V_6 -> V_41 ;
V_6 -> V_55 = V_42 ;
V_6 -> V_27 = 0 ;
F_13 ( V_2 , 0 , 0 ) ;
if ( V_6 -> V_41 ) {
F_13 ( V_2 , 1 , 0 ) ;
V_6 -> V_20 |= V_106 ;
F_4 ( V_6 -> V_20 , V_2 -> V_22 + V_23 ) ;
}
V_6 -> V_47 = 0 ;
F_26 ( V_2 , V_72 -> V_93 , V_72 -> V_59 ) ;
V_6 -> V_47 = V_66 | V_107 ;
F_4 ( V_6 -> V_47 , V_2 -> V_22 + V_52 ) ;
F_4 ( V_6 -> V_20 | V_68 , V_2 -> V_22 + V_23 ) ;
F_30 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
if ( V_72 -> V_79 == V_80 ) {
F_4 ( V_6 -> V_20 | V_69 ,
V_2 -> V_22 + V_23 ) ;
} else {
V_6 -> V_20 |= V_108 ;
F_4 ( V_6 -> V_20 , V_2 -> V_22 + V_23 ) ;
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_97 ) {
F_6 ( V_6 -> V_28 [ 0 ] . V_29 ) ;
F_6 ( V_6 -> V_28 [ 1 ] . V_29 ) ;
}
}
static int F_12 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_41 ( V_2 ) ;
V_6 -> V_47 = 0 ;
F_4 ( V_6 -> V_47 , V_2 -> V_22 + V_52 ) ;
V_6 -> V_20 = 0 ;
F_4 ( V_6 -> V_20 | V_105 , V_2 -> V_22 + V_23 ) ;
return 0 ;
}
static int F_39 ( int * V_109 , int V_110 )
{
int V_111 , V_112 , V_113 ;
for ( V_111 = 0 ; V_111 < 16 ; V_111 ++ ) {
if ( V_111 == 1 )
continue;
V_112 = 250 * ( 1 << V_111 ) ;
switch ( V_110 ) {
case V_99 :
default:
V_113 = ( * V_109 + V_112 / 2 ) / V_112 ;
break;
case V_114 :
V_113 = ( * V_109 ) / V_112 ;
break;
case V_115 :
V_113 = ( * V_109 + V_112 - 1 ) / V_112 ;
break;
}
if ( V_113 < 256 ) {
* V_109 = V_113 * V_112 ;
return ( V_111 << 8 ) | ( 255 - V_113 ) ;
}
}
V_112 = 250 * ( 1 << 15 ) ;
V_113 = 255 ;
* V_109 = V_113 * V_112 ;
return ( 15 << 8 ) | ( 255 - V_113 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_65 [ 0 ] = V_6 -> V_116 [ F_27 ( V_64 -> V_67 ) ] ;
return 1 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
short V_45 ;
unsigned int V_29 ;
V_29 = F_27 ( V_64 -> V_67 ) ;
V_45 = V_65 [ 0 ] ;
V_45 &= ( 1 << V_10 . V_117 ) - 1 ;
V_6 -> V_116 [ V_29 ] = V_45 ;
V_6 -> V_48 |= V_118 ;
if ( V_29 ) {
V_6 -> V_48 |= V_119 ;
if ( V_6 -> V_120 )
V_45 ^= ( 1 << ( V_10 . V_117 - 1 ) ) ;
} else {
V_6 -> V_48 &= ~ V_119 ;
if ( V_6 -> V_121 )
V_45 ^= ( 1 << ( V_10 . V_117 - 1 ) ) ;
}
F_4 ( V_6 -> V_48 , V_2 -> V_22 + V_53 ) ;
F_4 ( V_45 , V_2 -> V_22 + V_122 ) ;
F_4 ( V_6 -> V_20 | V_123 , V_2 -> V_22 + V_23 ) ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_17 * V_18 , struct V_71 * V_72 )
{
int V_75 = 0 ;
int V_76 ;
V_75 |= F_33 ( & V_72 -> V_77 , V_124 ) ;
V_75 |= F_33 ( & V_72 -> V_79 , V_83 ) ;
V_75 |= F_33 ( & V_72 -> V_82 , V_78 ) ;
V_75 |= F_33 ( & V_72 -> V_84 , V_85 ) ;
V_75 |= F_33 ( & V_72 -> V_86 , V_85 | V_87 ) ;
if ( V_75 )
return 1 ;
V_75 |= F_34 ( V_72 -> V_86 ) ;
if ( V_75 )
return 2 ;
V_75 |= F_35 ( & V_72 -> V_88 , 0 ) ;
V_75 |= F_36 ( & V_72 -> V_89 , 5000 ) ;
V_75 |= F_35 ( & V_72 -> V_90 , 0 ) ;
V_75 |= F_38 ( & V_72 -> V_92 , 2 ) ;
if ( V_72 -> V_86 == V_85 ) {
} else {
V_75 |= F_35 ( & V_72 -> V_94 , 0 ) ;
}
if ( V_75 )
return 3 ;
V_76 = V_72 -> V_89 ;
F_39 ( & V_72 -> V_89 , V_72 -> V_40 & V_95 ) ;
if ( V_76 != V_72 -> V_89 )
V_75 ++ ;
if ( V_75 )
return 4 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_17 * V_18 , unsigned int V_125 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 ;
if ( V_125 != 0 )
return - V_126 ;
V_16 = F_7 ( V_18 , V_6 -> V_28 [ 0 ] . V_3 ,
V_6 -> V_30 ) ;
if ( V_16 == 0 ) {
F_5 ( V_26 L_3 ) ;
return - V_127 ;
}
F_9 ( V_2 , 0 , V_16 ) ;
V_16 = F_7 ( V_18 , V_6 -> V_28 [ 1 ] . V_3 ,
V_6 -> V_30 ) ;
if ( V_16 == 0 ) {
F_5 ( V_26 L_3 ) ;
return - V_127 ;
}
F_9 ( V_2 , 1 , V_16 ) ;
F_4 ( V_6 -> V_20 | V_69 , V_2 -> V_22 + V_23 ) ;
V_18 -> V_24 -> V_128 = NULL ;
return 1 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_96 ;
struct V_71 * V_72 = & V_18 -> V_24 -> V_72 ;
if ( V_6 -> V_97 == 0 ) {
F_2 ( V_2 ,
L_9
L_10 ) ;
return - V_98 ;
}
F_41 ( V_2 ) ;
V_6 -> V_20 = V_101 | V_103 | V_106 ;
F_4 ( V_6 -> V_20 | V_21 | V_104 | V_129 ,
V_2 -> V_22 + V_23 ) ;
V_6 -> V_41 = V_72 -> V_94 * V_72 -> V_93 ;
V_6 -> V_34 = V_6 -> V_41 ;
V_6 -> V_55 = V_43 ;
V_6 -> V_27 = 0 ;
V_96 = F_39 ( & V_72 -> V_89 , V_99 ) ;
F_4 ( V_96 , V_2 -> V_22 + V_100 ) ;
V_6 -> V_48 = V_118 | V_130 | V_131 ;
F_4 ( V_6 -> V_48 , V_2 -> V_22 + V_53 ) ;
V_18 -> V_24 -> V_128 = F_45 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_41 ( V_2 ) ;
V_6 -> V_48 = 0 ;
F_4 ( V_6 -> V_48 , V_2 -> V_22 + V_53 ) ;
V_6 -> V_20 = 0 ;
F_4 ( V_6 -> V_20 | V_129 , V_2 -> V_22 + V_23 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
if ( V_65 [ 0 ] ) {
V_18 -> V_132 &= ~ V_65 [ 0 ] ;
V_18 -> V_132 |= ( V_65 [ 0 ] & V_65 [ 1 ] ) ;
F_4 ( V_18 -> V_132 , V_2 -> V_22 + V_133 ) ;
}
V_65 [ 1 ] = F_23 ( V_2 -> V_22 + V_133 ) ;
return V_64 -> V_13 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_63 * V_64 , unsigned int * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_9 ;
V_9 = ( F_27 ( V_64 -> V_67 ) < 8 ) ? 0x00ff : 0xff00 ;
if ( V_65 [ 0 ] )
V_18 -> V_134 |= V_9 ;
else
V_18 -> V_134 &= ~ V_9 ;
if ( V_18 -> V_134 & 0x00ff )
V_6 -> V_48 |= V_135 ;
else
V_6 -> V_48 &= ~ V_135 ;
if ( V_18 -> V_134 & 0xff00 )
V_6 -> V_48 |= V_136 ;
else
V_6 -> V_48 &= ~ V_136 ;
F_4 ( V_6 -> V_48 , V_2 -> V_22 + V_53 ) ;
return 1 ;
}
static const struct V_137 * F_49 ( int V_138 , int V_125 )
{
if ( V_138 ) {
if ( V_125 < 0 || V_125 >= 2 )
V_125 = 0 ;
return V_139 [ V_125 ] ;
} else {
if ( V_125 < 0 || V_125 >= 4 )
V_125 = 0 ;
return V_140 [ V_125 ] ;
}
}
static const struct V_137 * F_50 ( int V_125 )
{
if ( V_125 < 0 || V_125 >= 5 )
V_125 = 0 ;
return V_141 [ V_125 ] ;
}
static int F_51 ( struct V_1 * V_2 , int V_142 , int V_143 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_33 ;
V_6 -> V_97 = 0 ;
if ( ! V_142 && ! V_143 ) {
F_5 ( V_26 L_11 ) ;
return 0 ;
}
if ( V_142 == V_143 || V_142 < 5 || V_143 < 5 || V_142 > 7 || V_143 > 7 )
return - V_126 ;
if ( V_143 < V_142 ) {
int V_8 ;
V_8 = V_142 ;
V_142 = V_143 ;
V_143 = V_8 ;
}
V_33 = F_52 ( V_142 , L_12 ) ;
if ( V_33 )
return - V_144 ;
V_6 -> V_28 [ 0 ] . V_29 = V_142 ;
V_33 = F_52 ( V_143 , L_13 ) ;
if ( V_33 )
return - V_144 ;
V_6 -> V_28 [ 1 ] . V_29 = V_143 ;
V_6 -> V_30 = V_145 ;
V_6 -> V_28 [ 0 ] . V_3 = ( void * ) F_53 ( V_146 | V_147 ) ;
V_6 -> V_28 [ 1 ] . V_3 = ( void * ) F_53 ( V_146 | V_147 ) ;
if ( ! V_6 -> V_28 [ 0 ] . V_3 || ! V_6 -> V_28 [ 1 ] . V_3 ) {
F_5 ( V_26 L_14 ) ;
return - V_148 ;
}
F_5 ( V_35 L_15 , V_142 , V_143 ) ;
V_6 -> V_97 = 1 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_149 * V_150 )
{
const struct V_73 * V_74 = F_32 ( V_2 ) ;
struct V_5 * V_6 ;
int V_8 , V_44 ;
int V_33 ;
struct V_17 * V_18 ;
unsigned long V_22 ;
V_2 -> V_151 = V_74 -> V_152 ;
V_22 = V_150 -> V_153 [ V_154 ] ;
if ( ! V_22 )
V_22 = 0x240 ;
F_5 ( V_35 L_16 , V_2 -> V_155 , V_22 ) ;
if ( ! F_55 ( V_22 , V_156 , L_17 ) ) {
F_5 ( V_35 L_18 ) ;
return - V_144 ;
}
V_2 -> V_22 = V_22 ;
F_4 ( V_157 , V_2 -> V_22 + V_23 ) ;
V_8 = F_23 ( V_2 -> V_22 + V_52 ) ;
#ifdef F_56
F_5 ( V_158 L_19 ,
F_23 ( V_2 -> V_22 + V_52 ) ,
F_23 ( V_2 -> V_22 + V_62 ) ,
F_23 ( V_2 -> V_22 + V_53 ) ,
F_23 ( V_2 -> V_22 + V_23 ) ,
F_23 ( V_2 -> V_22 + V_100 ) ) ;
#endif
if ( ( ( F_23 ( V_2 -> V_22 + V_52 ) & V_159 )
!= V_160 ) ||
( ( F_23 ( V_2 -> V_22 + V_62 ) & V_161 )
!= V_162 ) ||
( ( F_23 ( V_2 -> V_22 + V_53 ) & V_163 )
!= V_164 ) ||
( ( F_23 ( V_2 -> V_22 + V_23 ) & V_165 )
!= V_166 ) ||
( ( F_23 ( V_2 -> V_22 + V_100 ) & V_167 )
!= V_168 ) ) {
F_5 ( V_26 L_20 ) ;
return - V_98 ;
}
V_44 = V_150 -> V_153 [ V_169 ] ;
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
if ( V_44 > 0 ) {
F_5 ( V_35 L_21 , V_44 ) ;
V_33 = F_57 ( V_44 , F_22 , 0 , L_17 , V_2 ) ;
if ( V_33 < 0 ) {
F_5 ( V_26 L_22 ) ;
return - V_98 ;
}
V_2 -> V_44 = V_44 ;
} else if ( V_44 == 0 ) {
F_5 ( V_35 L_23 ) ;
} else {
#if 0
printk(KERN_INFO " (probe returned multiple irqs--bad)");
#else
F_5 ( V_35 L_24 ) ;
#endif
}
V_6 = F_58 ( sizeof( * V_6 ) , V_146 ) ;
if ( ! V_6 )
return - V_148 ;
V_2 -> V_7 = V_6 ;
V_33 = F_51 ( V_2 , V_150 -> V_153 [ V_170 ] ,
V_150 -> V_153 [ V_171 ] ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_59 ( V_2 , 3 ) ;
if ( V_33 )
return V_33 ;
V_18 = & V_2 -> V_19 [ 0 ] ;
V_2 -> V_172 = V_18 ;
V_18 -> type = V_173 ;
V_18 -> V_174 = V_175 | V_176 |
( ( V_150 -> V_153 [ V_177 ] ) ? V_178 : V_179 ) ;
V_18 -> V_180 =
( V_150 -> V_153 [ V_177 ] ) ? V_10 . V_181 : V_10 . V_182 ;
V_18 -> V_183 = F_29 ;
V_18 -> V_184 = F_31 ;
V_18 -> V_185 = F_40 ;
V_18 -> V_186 = F_12 ;
V_18 -> V_187 = ( 1 << V_10 . V_11 ) - 1 ;
V_18 -> V_188 = 16 ;
V_18 -> V_189 =
F_49 ( V_10 . V_138 , V_150 -> V_153 [ V_190 ] ) ;
V_6 -> V_14 = V_150 -> V_153 [ V_191 ] ;
V_18 = & V_2 -> V_19 [ 1 ] ;
V_18 -> V_180 = V_10 . V_192 ;
if ( V_18 -> V_180 ) {
V_18 -> type = V_193 ;
V_2 -> V_194 = V_18 ;
V_18 -> V_174 = V_195 | V_196 ;
V_18 -> V_183 = F_42 ;
V_18 -> V_197 = F_43 ;
V_18 -> V_184 = F_44 ;
V_18 -> V_185 = F_46 ;
V_18 -> V_186 = F_8 ;
V_18 -> V_187 = ( 1 << V_10 . V_117 ) - 1 ;
V_18 -> V_188 = 2 ;
V_18 -> V_198 = V_6 -> V_199 ;
V_6 -> V_199 [ 0 ] =
F_50 ( V_150 -> V_153 [ V_200 ] ) ;
V_6 -> V_199 [ 1 ] =
F_50 ( V_150 -> V_153 [ V_201 ] ) ;
V_6 -> V_120 = V_150 -> V_153 [ V_202 ] ;
V_6 -> V_121 = V_150 -> V_153 [ V_203 ] ;
} else {
V_18 -> type = V_204 ;
}
V_18 = & V_2 -> V_19 [ 2 ] ;
V_18 -> type = V_205 ;
V_18 -> V_174 = V_175 | V_195 ;
V_18 -> V_180 = 16 ;
V_18 -> V_206 = F_47 ;
V_18 -> V_207 = F_48 ;
V_18 -> V_187 = 1 ;
V_18 -> V_189 = & V_208 ;
F_5 ( V_35 L_25 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_2 -> V_44 )
F_61 ( V_2 -> V_44 , V_2 ) ;
if ( V_2 -> V_22 )
F_62 ( V_2 -> V_22 , V_156 ) ;
if ( V_2 -> V_7 ) {
if ( V_6 -> V_28 [ 0 ] . V_29 )
F_63 ( V_6 -> V_28 [ 0 ] . V_29 ) ;
if ( V_6 -> V_28 [ 1 ] . V_29 )
F_63 ( V_6 -> V_28 [ 1 ] . V_29 ) ;
if ( V_6 -> V_28 [ 0 ] . V_3 )
F_64 ( ( unsigned long ) V_6 -> V_28 [ 0 ] . V_3 ) ;
if ( V_6 -> V_28 [ 1 ] . V_3 )
F_64 ( ( unsigned long ) V_6 -> V_28 [ 1 ] . V_3 ) ;
}
}
