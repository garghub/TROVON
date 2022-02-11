static void F_1 ( struct V_1 * V_2 , unsigned short * V_3 ,
unsigned int V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
unsigned short V_11 = ( 1 << V_6 -> V_12 ) - 1 ;
unsigned short V_13 = 1 << ( V_6 -> V_12 - 1 ) ;
int V_14 ;
if ( V_8 -> V_15 )
V_13 = 1 << ( V_6 -> V_12 - 1 ) ;
else
V_13 = 0 ;
if ( V_4 % 2 )
F_3 ( V_2 , L_1 ) ;
V_14 = V_4 / 2 ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ )
V_3 [ V_10 ] = ( V_3 [ V_10 ] & V_11 ) ^ V_13 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
void * V_16 ;
int V_17 ;
int V_10 ;
struct V_18 * V_19 = & V_2 -> V_20 [ 1 ] ;
F_5 ( V_8 -> V_21 | V_22 , V_2 -> V_23 + V_24 ) ;
if ( ! V_19 -> V_25 -> V_26 ) {
F_6 ( V_27 L_2 ) ;
return;
}
V_10 = V_8 -> V_28 ;
V_16 = V_8 -> V_29 [ V_10 ] . V_3 ;
F_7 ( V_8 -> V_29 [ V_10 ] . V_30 ) ;
V_8 -> V_28 = 1 - V_10 ;
V_17 = F_8 ( V_19 , V_16 , V_8 -> V_31 ) ;
if ( V_17 == 0 ) {
F_6 ( V_27 L_3 ) ;
F_9 ( V_2 , V_19 ) ;
V_19 -> V_25 -> V_32 |= V_33 ;
return;
}
F_10 ( V_2 , V_10 , V_17 ) ;
return;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
void * V_16 ;
int V_17 ;
int V_10 ;
int V_34 ;
struct V_18 * V_19 = & V_2 -> V_20 [ 0 ] ;
F_5 ( V_8 -> V_21 | V_22 , V_2 -> V_23 + V_24 ) ;
if ( ! V_19 -> V_25 -> V_26 ) {
F_6 ( V_27 L_2 ) ;
return;
}
V_10 = V_8 -> V_28 ;
V_16 = V_8 -> V_29 [ V_10 ] . V_3 ;
V_17 = V_8 -> V_29 [ V_10 ] . V_17 ;
F_7 ( V_8 -> V_29 [ V_10 ] . V_30 ) ;
V_8 -> V_28 = 1 - V_10 ;
F_1 ( V_2 , V_16 , V_17 ) ;
V_34 = F_12 ( V_19 , V_16 , V_17 ) ;
if ( V_34 != V_17 ) {
F_13 ( V_2 , V_19 ) ;
return;
}
V_8 -> V_35 -= V_17 / 2 ;
if ( V_8 -> V_35 < 0 ) {
F_6 ( V_36 L_4 ) ;
V_8 -> V_35 = 0 ;
}
if ( ! V_8 -> V_35 ) {
F_13 ( V_2 , V_19 ) ;
V_19 -> V_25 -> V_32 |= V_37 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR);
}
#endif
F_14 ( V_2 , V_10 , 0 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_38 , int V_14 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
if ( ! V_8 -> V_42 )
return 0 ;
if ( V_14 == 0 )
V_14 = V_8 -> V_31 ;
if ( V_14 > V_8 -> V_42 * 2 )
V_14 = V_8 -> V_42 * 2 ;
V_8 -> V_42 -= V_14 / 2 ;
V_8 -> V_29 [ V_38 ] . V_17 = V_14 ;
V_39 = V_8 -> V_29 [ V_38 ] . V_30 ;
V_40 = F_15 ( V_8 -> V_29 [ V_38 ] . V_3 ) ;
F_16 ( V_39 , V_43 ) ;
V_41 = F_17 () ;
F_18 ( V_39 ) ;
F_19 ( V_39 , V_40 ) ;
F_20 ( V_39 , V_14 ) ;
F_21 ( V_41 ) ;
F_22 ( V_39 ) ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 , int V_38 , int V_14 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
V_8 -> V_29 [ V_38 ] . V_17 = V_14 ;
V_39 = V_8 -> V_29 [ V_38 ] . V_30 ;
V_40 = F_15 ( V_8 -> V_29 [ V_38 ] . V_3 ) ;
F_16 ( V_39 , V_44 ) ;
V_41 = F_17 () ;
F_18 ( V_39 ) ;
F_19 ( V_39 , V_40 ) ;
F_20 ( V_39 , V_14 ) ;
F_21 ( V_41 ) ;
F_22 ( V_39 ) ;
return V_14 ;
}
static T_1 F_23 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_18 * V_19 ;
struct V_18 * V_47 ;
unsigned int V_21 , V_48 , V_49 ;
int V_50 = 0 ;
if ( ! V_2 -> V_51 ) {
F_3 ( V_2 , L_5 ) ;
return V_52 ;
}
V_19 = & V_2 -> V_20 [ 0 ] ;
V_47 = & V_2 -> V_20 [ 1 ] ;
V_48 = F_24 ( V_2 -> V_23 + V_53 ) ;
V_49 = F_24 ( V_2 -> V_23 + V_54 ) ;
V_21 = F_24 ( V_2 -> V_23 + V_24 ) ;
if ( V_21 & V_55 ) {
if ( V_8 -> V_56 == V_43 )
F_11 ( V_2 ) ;
else
F_4 ( V_2 ) ;
V_50 = 1 ;
}
if ( V_48 & V_57 ) {
if ( V_8 -> V_35 != 0 ) {
F_3 ( V_2 , L_6 ) ;
F_13 ( V_2 , V_19 ) ;
V_19 -> V_25 -> V_32 |= V_58 ;
}
V_50 = 1 ;
}
if ( V_49 & V_59 ) {
#if 0
static int warn = 5;
if (--warn <= 0) {
disable_irq(dev->irq);
printk(KERN_INFO "disabling irq\n");
}
#endif
F_3 ( V_2 , L_7 ) ;
F_9 ( V_2 , V_47 ) ;
V_19 -> V_25 -> V_32 |= V_58 ;
V_50 = 1 ;
}
#if 0
if (adcsr & DT2821_ADDONE) {
int ret;
unsigned short data;
data = inw(dev->iobase + DT2821_ADDAT);
data &= (1 << board->adbits) - 1;
if (devpriv->ad_2scomp)
data ^= 1 << (board->adbits - 1);
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
F_25 ( V_2 , V_19 ) ;
return F_26 ( V_50 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_14 ,
unsigned int * V_60 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
unsigned int V_30 , V_61 ;
F_5 ( V_62 | ( V_14 - 1 ) , V_2 -> V_23 + V_63 ) ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
V_30 = F_28 ( V_60 [ V_10 ] ) ;
V_61 = F_29 ( V_60 [ V_10 ] ) ;
F_5 ( V_8 -> V_48 | ( V_61 << 4 ) | V_30 ,
V_2 -> V_23 + V_53 ) ;
}
F_5 ( V_14 - 1 , V_2 -> V_23 + V_63 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_64 * V_65 , unsigned int * V_66 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
V_8 -> V_48 = V_67 ;
F_5 ( V_8 -> V_48 , V_2 -> V_23 + V_53 ) ;
F_27 ( V_2 , 1 , & V_65 -> V_68 ) ;
F_5 ( V_8 -> V_21 | V_69 , V_2 -> V_23 + V_24 ) ;
F_31 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
for ( V_10 = 0 ; V_10 < V_65 -> V_14 ; V_10 ++ ) {
F_5 ( V_8 -> V_21 | V_70 ,
V_2 -> V_23 + V_24 ) ;
F_31 (ad_done(), comedi_error(dev, L_8);
return -ETIME;) ;
V_66 [ V_10 ] =
F_24 ( V_2 -> V_23 +
V_71 ) & ( ( 1 << V_6 -> V_12 ) - 1 ) ;
if ( V_8 -> V_15 )
V_66 [ V_10 ] ^= ( 1 << ( V_6 -> V_12 - 1 ) ) ;
}
return V_10 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_72 * V_73 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_74 = 0 ;
int V_75 ;
V_74 |= F_33 ( & V_73 -> V_76 , V_77 ) ;
V_74 |= F_33 ( & V_73 -> V_78 ,
V_79 | V_80 ) ;
V_74 |= F_33 ( & V_73 -> V_81 , V_82 ) ;
V_74 |= F_33 ( & V_73 -> V_83 , V_84 ) ;
V_74 |= F_33 ( & V_73 -> V_85 , V_84 | V_86 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_34 ( V_73 -> V_78 ) ;
V_74 |= F_34 ( V_73 -> V_85 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_35 ( & V_73 -> V_87 , 0 ) ;
if ( V_73 -> V_78 == V_79 ) {
V_74 |= F_35 ( & V_73 -> V_88 , 0 ) ;
} else {
V_74 |= F_35 ( & V_73 -> V_88 , 0 ) ;
}
V_74 |= F_36 ( & V_73 -> V_89 , 4000 ) ;
#define F_37 (250*(1<<15)*255)
V_74 |= F_38 ( & V_73 -> V_89 , F_37 ) ;
V_74 |= F_36 ( & V_73 -> V_89 , V_6 -> V_90 ) ;
V_74 |= F_35 ( & V_73 -> V_91 , V_73 -> V_92 ) ;
if ( V_73 -> V_85 == V_84 ) {
} else {
V_74 |= F_35 ( & V_73 -> V_93 , 0 ) ;
}
if ( V_74 )
return 3 ;
V_75 = V_73 -> V_89 ;
F_39 ( & V_73 -> V_89 , V_73 -> V_41 & V_94 ) ;
if ( V_75 != V_73 -> V_89 )
V_74 ++ ;
if ( V_74 )
return 4 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_72 * V_73 = & V_19 -> V_25 -> V_73 ;
int V_95 ;
if ( V_8 -> V_96 == 0 ) {
F_3 ( V_2 ,
L_9
L_10 ) ;
return - V_97 ;
}
F_41 ( V_2 ) ;
if ( V_73 -> V_89 < V_6 -> V_90 )
V_73 -> V_89 = V_6 -> V_90 ;
V_95 = F_39 ( & V_73 -> V_89 , V_98 ) ;
F_5 ( V_95 , V_2 -> V_23 + V_99 ) ;
if ( V_73 -> V_78 == V_79 ) {
V_8 -> V_21 = V_100 | V_101 ;
} else {
V_8 -> V_21 = V_100 | V_101 | V_102 ;
}
F_5 ( V_8 -> V_21 | V_22 | V_103 | V_104 ,
V_2 -> V_23 + V_24 ) ;
V_8 -> V_42 = V_73 -> V_93 * V_73 -> V_91 ;
V_8 -> V_35 = V_8 -> V_42 ;
V_8 -> V_56 = V_43 ;
V_8 -> V_28 = 0 ;
F_14 ( V_2 , 0 , 0 ) ;
if ( V_8 -> V_42 ) {
F_14 ( V_2 , 1 , 0 ) ;
V_8 -> V_21 |= V_105 ;
F_5 ( V_8 -> V_21 , V_2 -> V_23 + V_24 ) ;
}
V_8 -> V_48 = 0 ;
F_27 ( V_2 , V_73 -> V_92 , V_73 -> V_60 ) ;
V_8 -> V_48 = V_67 | V_106 ;
F_5 ( V_8 -> V_48 , V_2 -> V_23 + V_53 ) ;
F_5 ( V_8 -> V_21 | V_69 , V_2 -> V_23 + V_24 ) ;
F_31 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
if ( V_73 -> V_78 == V_79 ) {
F_5 ( V_8 -> V_21 | V_70 ,
V_2 -> V_23 + V_24 ) ;
} else {
V_8 -> V_21 |= V_107 ;
F_5 ( V_8 -> V_21 , V_2 -> V_23 + V_24 ) ;
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_96 ) {
F_7 ( V_8 -> V_29 [ 0 ] . V_30 ) ;
F_7 ( V_8 -> V_29 [ 1 ] . V_30 ) ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_41 ( V_2 ) ;
V_8 -> V_48 = 0 ;
F_5 ( V_8 -> V_48 , V_2 -> V_23 + V_53 ) ;
V_8 -> V_21 = 0 ;
F_5 ( V_8 -> V_21 | V_104 , V_2 -> V_23 + V_24 ) ;
return 0 ;
}
static int F_39 ( int * V_108 , int V_109 )
{
int V_110 , V_111 , V_112 ;
for ( V_110 = 0 ; V_110 < 16 ; V_110 ++ ) {
if ( V_110 == 1 )
continue;
V_111 = 250 * ( 1 << V_110 ) ;
switch ( V_109 ) {
case V_98 :
default:
V_112 = ( * V_108 + V_111 / 2 ) / V_111 ;
break;
case V_113 :
V_112 = ( * V_108 ) / V_111 ;
break;
case V_114 :
V_112 = ( * V_108 + V_111 - 1 ) / V_111 ;
break;
}
if ( V_112 < 256 ) {
* V_108 = V_112 * V_111 ;
return ( V_110 << 8 ) | ( 255 - V_112 ) ;
}
}
V_111 = 250 * ( 1 << 15 ) ;
V_112 = 255 ;
* V_108 = V_112 * V_111 ;
return ( 15 << 8 ) | ( 255 - V_112 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_64 * V_65 , unsigned int * V_66 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_66 [ 0 ] = V_8 -> V_115 [ F_28 ( V_65 -> V_68 ) ] ;
return 1 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_64 * V_65 , unsigned int * V_66 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned short V_46 ;
unsigned int V_30 ;
V_30 = F_28 ( V_65 -> V_68 ) ;
V_46 = V_66 [ 0 ] ;
V_46 &= ( 1 << V_6 -> V_116 ) - 1 ;
V_8 -> V_115 [ V_30 ] = V_46 ;
V_8 -> V_49 |= V_117 ;
if ( V_30 ) {
V_8 -> V_49 |= V_118 ;
if ( V_8 -> V_119 )
V_46 ^= ( 1 << ( V_6 -> V_116 - 1 ) ) ;
} else {
V_8 -> V_49 &= ~ V_118 ;
if ( V_8 -> V_120 )
V_46 ^= ( 1 << ( V_6 -> V_116 - 1 ) ) ;
}
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
F_5 ( V_46 , V_2 -> V_23 + V_121 ) ;
F_5 ( V_8 -> V_21 | V_122 , V_2 -> V_23 + V_24 ) ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_72 * V_73 )
{
int V_74 = 0 ;
int V_75 ;
V_74 |= F_33 ( & V_73 -> V_76 , V_123 ) ;
V_74 |= F_33 ( & V_73 -> V_78 , V_82 ) ;
V_74 |= F_33 ( & V_73 -> V_81 , V_77 ) ;
V_74 |= F_33 ( & V_73 -> V_83 , V_84 ) ;
V_74 |= F_33 ( & V_73 -> V_85 , V_84 | V_86 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_34 ( V_73 -> V_85 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_35 ( & V_73 -> V_87 , 0 ) ;
V_74 |= F_36 ( & V_73 -> V_88 , 5000 ) ;
V_74 |= F_35 ( & V_73 -> V_89 , 0 ) ;
V_74 |= F_38 ( & V_73 -> V_91 , 2 ) ;
if ( V_73 -> V_85 == V_84 ) {
} else {
V_74 |= F_35 ( & V_73 -> V_93 , 0 ) ;
}
if ( V_74 )
return 3 ;
V_75 = V_73 -> V_88 ;
F_39 ( & V_73 -> V_88 , V_73 -> V_41 & V_94 ) ;
if ( V_75 != V_73 -> V_88 )
V_74 ++ ;
if ( V_74 )
return 4 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_18 * V_19 , unsigned int V_124 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_17 ;
if ( V_124 != 0 )
return - V_125 ;
V_17 = F_8 ( V_19 , V_8 -> V_29 [ 0 ] . V_3 ,
V_8 -> V_31 ) ;
if ( V_17 == 0 ) {
F_6 ( V_27 L_3 ) ;
return - V_126 ;
}
F_10 ( V_2 , 0 , V_17 ) ;
V_17 = F_8 ( V_19 , V_8 -> V_29 [ 1 ] . V_3 ,
V_8 -> V_31 ) ;
if ( V_17 == 0 ) {
F_6 ( V_27 L_3 ) ;
return - V_126 ;
}
F_10 ( V_2 , 1 , V_17 ) ;
F_5 ( V_8 -> V_21 | V_70 , V_2 -> V_23 + V_24 ) ;
V_19 -> V_25 -> V_127 = NULL ;
return 1 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_95 ;
struct V_72 * V_73 = & V_19 -> V_25 -> V_73 ;
if ( V_8 -> V_96 == 0 ) {
F_3 ( V_2 ,
L_9
L_10 ) ;
return - V_97 ;
}
F_41 ( V_2 ) ;
V_8 -> V_21 = V_100 | V_102 | V_105 ;
F_5 ( V_8 -> V_21 | V_22 | V_103 | V_128 ,
V_2 -> V_23 + V_24 ) ;
V_8 -> V_42 = V_73 -> V_93 * V_73 -> V_92 ;
V_8 -> V_35 = V_8 -> V_42 ;
V_8 -> V_56 = V_44 ;
V_8 -> V_28 = 0 ;
V_95 = F_39 ( & V_73 -> V_88 , V_98 ) ;
F_5 ( V_95 , V_2 -> V_23 + V_99 ) ;
V_8 -> V_49 = V_117 | V_129 | V_130 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
V_19 -> V_25 -> V_127 = F_45 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_41 ( V_2 ) ;
V_8 -> V_49 = 0 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
V_8 -> V_21 = 0 ;
F_5 ( V_8 -> V_21 | V_128 , V_2 -> V_23 + V_24 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_64 * V_65 ,
unsigned int * V_66 )
{
if ( F_48 ( V_19 , V_66 ) )
F_5 ( V_19 -> V_131 , V_2 -> V_23 + V_132 ) ;
V_66 [ 1 ] = F_24 ( V_2 -> V_23 + V_132 ) ;
return V_65 -> V_14 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_64 * V_65 ,
unsigned int * V_66 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_30 = F_28 ( V_65 -> V_68 ) ;
unsigned int V_11 ;
int V_34 ;
if ( V_30 < 8 )
V_11 = 0x00ff ;
else
V_11 = 0xff00 ;
V_34 = F_50 ( V_2 , V_19 , V_65 , V_66 , V_11 ) ;
if ( V_34 )
return V_34 ;
V_8 -> V_49 &= ~ ( V_133 | V_134 ) ;
if ( V_19 -> V_135 & 0x00ff )
V_8 -> V_49 |= V_133 ;
if ( V_19 -> V_135 & 0xff00 )
V_8 -> V_49 |= V_134 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
return V_65 -> V_14 ;
}
static const struct V_136 * F_51 ( int V_137 , int V_124 )
{
if ( V_137 ) {
if ( V_124 < 0 || V_124 >= 2 )
V_124 = 0 ;
return V_138 [ V_124 ] ;
} else {
if ( V_124 < 0 || V_124 >= 4 )
V_124 = 0 ;
return V_139 [ V_124 ] ;
}
}
static const struct V_136 * F_52 ( int V_124 )
{
if ( V_124 < 0 || V_124 >= 5 )
V_124 = 0 ;
return V_140 [ V_124 ] ;
}
static int F_53 ( struct V_1 * V_2 , int V_141 , int V_142 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_34 ;
V_8 -> V_96 = 0 ;
if ( ! V_141 && ! V_142 ) {
F_6 ( V_27 L_11 ) ;
return 0 ;
}
if ( V_141 == V_142 || V_141 < 5 || V_142 < 5 || V_141 > 7 || V_142 > 7 )
return - V_125 ;
if ( V_142 < V_141 ) {
int V_10 ;
V_10 = V_141 ;
V_141 = V_142 ;
V_142 = V_10 ;
}
V_34 = F_54 ( V_141 , L_12 ) ;
if ( V_34 )
return - V_143 ;
V_8 -> V_29 [ 0 ] . V_30 = V_141 ;
V_34 = F_54 ( V_142 , L_13 ) ;
if ( V_34 )
return - V_143 ;
V_8 -> V_29 [ 1 ] . V_30 = V_142 ;
V_8 -> V_31 = V_144 ;
V_8 -> V_29 [ 0 ] . V_3 = ( void * ) F_55 ( V_145 | V_146 ) ;
V_8 -> V_29 [ 1 ] . V_3 = ( void * ) F_55 ( V_145 | V_146 ) ;
if ( ! V_8 -> V_29 [ 0 ] . V_3 || ! V_8 -> V_29 [ 1 ] . V_3 ) {
F_6 ( V_27 L_14 ) ;
return - V_147 ;
}
F_6 ( V_36 L_15 , V_141 , V_142 ) ;
V_8 -> V_96 = 1 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
int V_10 , V_45 ;
int V_34 ;
struct V_18 * V_19 ;
V_34 = F_57 ( V_2 , V_149 -> V_150 [ 0 ] , V_151 ) ;
if ( V_34 )
return V_34 ;
F_5 ( V_152 , V_2 -> V_23 + V_24 ) ;
V_10 = F_24 ( V_2 -> V_23 + V_53 ) ;
#ifdef F_58
F_6 ( V_153 L_16 ,
F_24 ( V_2 -> V_23 + V_53 ) ,
F_24 ( V_2 -> V_23 + V_63 ) ,
F_24 ( V_2 -> V_23 + V_54 ) ,
F_24 ( V_2 -> V_23 + V_24 ) ,
F_24 ( V_2 -> V_23 + V_99 ) ) ;
#endif
if ( ( ( F_24 ( V_2 -> V_23 + V_53 ) & V_154 )
!= V_155 ) ||
( ( F_24 ( V_2 -> V_23 + V_63 ) & V_156 )
!= V_157 ) ||
( ( F_24 ( V_2 -> V_23 + V_54 ) & V_158 )
!= V_159 ) ||
( ( F_24 ( V_2 -> V_23 + V_24 ) & V_160 )
!= V_161 ) ||
( ( F_24 ( V_2 -> V_23 + V_99 ) & V_162 )
!= V_163 ) ) {
F_6 ( V_27 L_17 ) ;
return - V_97 ;
}
V_45 = V_149 -> V_150 [ V_164 ] ;
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
if ( V_45 > 0 ) {
F_6 ( V_36 L_18 , V_45 ) ;
V_34 = F_59 ( V_45 , F_23 , 0 ,
V_2 -> V_165 , V_2 ) ;
if ( V_34 < 0 ) {
F_6 ( V_27 L_19 ) ;
return - V_97 ;
}
V_2 -> V_45 = V_45 ;
} else if ( V_45 == 0 ) {
F_6 ( V_36 L_20 ) ;
} else {
#if 0
printk(KERN_INFO " (probe returned multiple irqs--bad)");
#else
F_6 ( V_36 L_21 ) ;
#endif
}
V_8 = F_60 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_147 ;
V_34 = F_53 ( V_2 , V_149 -> V_150 [ V_166 ] ,
V_149 -> V_150 [ V_167 ] ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_61 ( V_2 , 3 ) ;
if ( V_34 )
return V_34 ;
V_19 = & V_2 -> V_20 [ 0 ] ;
V_2 -> V_168 = V_19 ;
V_19 -> type = V_169 ;
V_19 -> V_170 = V_171 | V_172 |
( ( V_149 -> V_150 [ V_173 ] ) ? V_174 : V_175 ) ;
V_19 -> V_176 =
( V_149 -> V_150 [ V_173 ] ) ? V_6 -> V_177 : V_6 -> V_178 ;
V_19 -> V_179 = F_30 ;
V_19 -> V_180 = F_32 ;
V_19 -> V_181 = F_40 ;
V_19 -> V_182 = F_13 ;
V_19 -> V_183 = ( 1 << V_6 -> V_12 ) - 1 ;
V_19 -> V_184 = 16 ;
V_19 -> V_185 =
F_51 ( V_6 -> V_137 , V_149 -> V_150 [ V_186 ] ) ;
V_8 -> V_15 = V_149 -> V_150 [ V_187 ] ;
V_19 = & V_2 -> V_20 [ 1 ] ;
V_19 -> V_176 = V_6 -> V_188 ;
if ( V_19 -> V_176 ) {
V_19 -> type = V_189 ;
V_2 -> V_190 = V_19 ;
V_19 -> V_170 = V_191 | V_192 ;
V_19 -> V_179 = F_42 ;
V_19 -> V_193 = F_43 ;
V_19 -> V_180 = F_44 ;
V_19 -> V_181 = F_46 ;
V_19 -> V_182 = F_9 ;
V_19 -> V_183 = ( 1 << V_6 -> V_116 ) - 1 ;
V_19 -> V_184 = 2 ;
V_19 -> V_194 = V_8 -> V_195 ;
V_8 -> V_195 [ 0 ] =
F_52 ( V_149 -> V_150 [ V_196 ] ) ;
V_8 -> V_195 [ 1 ] =
F_52 ( V_149 -> V_150 [ V_197 ] ) ;
V_8 -> V_119 = V_149 -> V_150 [ V_198 ] ;
V_8 -> V_120 = V_149 -> V_150 [ V_199 ] ;
} else {
V_19 -> type = V_200 ;
}
V_19 = & V_2 -> V_20 [ 2 ] ;
V_19 -> type = V_201 ;
V_19 -> V_170 = V_171 | V_191 ;
V_19 -> V_176 = 16 ;
V_19 -> V_202 = F_47 ;
V_19 -> V_203 = F_49 ;
V_19 -> V_183 = 1 ;
V_19 -> V_185 = & V_204 ;
F_6 ( V_36 L_22 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_2 -> V_9 ) {
if ( V_8 -> V_29 [ 0 ] . V_30 )
F_63 ( V_8 -> V_29 [ 0 ] . V_30 ) ;
if ( V_8 -> V_29 [ 1 ] . V_30 )
F_63 ( V_8 -> V_29 [ 1 ] . V_30 ) ;
if ( V_8 -> V_29 [ 0 ] . V_3 )
F_64 ( ( unsigned long ) V_8 -> V_29 [ 0 ] . V_3 ) ;
if ( V_8 -> V_29 [ 1 ] . V_3 )
F_64 ( ( unsigned long ) V_8 -> V_29 [ 1 ] . V_3 ) ;
}
F_65 ( V_2 ) ;
}
