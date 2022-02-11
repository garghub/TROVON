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
F_4 ( V_18 ) ;
if ( ! V_16 -> V_19 -> V_20 ) {
F_5 ( V_21 L_2 ) ;
return;
}
V_5 = V_11 -> V_22 ;
V_13 = V_11 -> V_23 [ V_5 ] . V_3 ;
F_6 ( V_11 -> V_23 [ V_5 ] . V_24 ) ;
V_11 -> V_22 = 1 - V_5 ;
V_14 = F_7 ( V_16 , V_13 , V_11 -> V_25 ) ;
if ( V_14 == 0 ) {
F_5 ( V_21 L_3 ) ;
F_8 ( V_2 , V_16 ) ;
V_16 -> V_19 -> V_26 |= V_27 ;
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
int V_28 ;
struct V_15 * V_16 = V_2 -> V_17 ;
F_4 ( V_18 ) ;
if ( ! V_16 -> V_19 -> V_20 ) {
F_5 ( V_21 L_2 ) ;
return;
}
V_5 = V_11 -> V_22 ;
V_13 = V_11 -> V_23 [ V_5 ] . V_3 ;
V_14 = V_11 -> V_23 [ V_5 ] . V_14 ;
F_6 ( V_11 -> V_23 [ V_5 ] . V_24 ) ;
V_11 -> V_22 = 1 - V_5 ;
F_1 ( V_2 , V_13 , V_14 ) ;
V_28 = F_11 ( V_16 , V_13 , V_14 ) ;
if ( V_28 != V_14 ) {
F_12 ( V_2 , V_16 ) ;
return;
}
V_11 -> V_29 -= V_14 / 2 ;
if ( V_11 -> V_29 < 0 ) {
F_5 ( V_30 L_4 ) ;
V_11 -> V_29 = 0 ;
}
if ( ! V_11 -> V_29 ) {
F_12 ( V_2 , V_16 ) ;
V_16 -> V_19 -> V_26 |= V_31 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
update_supcsr(0);
}
#endif
F_13 ( V_2 , V_5 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_32 , int V_10 )
{
int V_33 ;
unsigned long V_34 ;
unsigned long V_35 ;
if ( ! V_11 -> V_36 )
return 0 ;
if ( V_10 == 0 )
V_10 = V_11 -> V_25 ;
if ( V_10 > V_11 -> V_36 * 2 )
V_10 = V_11 -> V_36 * 2 ;
V_11 -> V_36 -= V_10 / 2 ;
V_11 -> V_23 [ V_32 ] . V_14 = V_10 ;
V_33 = V_11 -> V_23 [ V_32 ] . V_24 ;
V_34 = F_14 ( V_11 -> V_23 [ V_32 ] . V_3 ) ;
F_15 ( V_33 , V_37 ) ;
V_35 = F_16 () ;
F_17 ( V_33 ) ;
F_18 ( V_33 , V_34 ) ;
F_19 ( V_33 , V_10 ) ;
F_20 ( V_35 ) ;
F_21 ( V_33 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 , int V_32 , int V_10 )
{
int V_33 ;
unsigned long V_34 ;
unsigned long V_35 ;
V_11 -> V_23 [ V_32 ] . V_14 = V_10 ;
V_33 = V_11 -> V_23 [ V_32 ] . V_24 ;
V_34 = F_14 ( V_11 -> V_23 [ V_32 ] . V_3 ) ;
F_15 ( V_33 , V_38 ) ;
V_35 = F_16 () ;
F_17 ( V_33 ) ;
F_18 ( V_33 , V_34 ) ;
F_19 ( V_33 , V_10 ) ;
F_20 ( V_35 ) ;
F_21 ( V_33 ) ;
return V_10 ;
}
static T_1 F_22 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
struct V_15 * V_16 ;
struct V_15 * V_41 ;
unsigned int V_42 , V_43 , V_44 ;
int V_45 = 0 ;
if ( ! V_2 -> V_46 ) {
F_2 ( V_2 , L_5 ) ;
return V_47 ;
}
V_16 = V_2 -> V_17 + 0 ;
V_41 = V_2 -> V_17 + 1 ;
V_43 = F_23 ( V_2 -> V_48 + V_49 ) ;
V_44 = F_23 ( V_2 -> V_48 + V_50 ) ;
V_42 = F_23 ( V_2 -> V_48 + V_51 ) ;
if ( V_42 & V_52 ) {
if ( V_11 -> V_53 == V_37 )
F_10 ( V_2 ) ;
else
F_3 ( V_2 ) ;
V_45 = 1 ;
}
if ( V_43 & V_54 ) {
if ( V_11 -> V_29 != 0 ) {
F_2 ( V_2 , L_6 ) ;
F_12 ( V_2 , V_16 ) ;
V_16 -> V_19 -> V_26 |= V_55 ;
}
V_45 = 1 ;
}
if ( V_44 & V_56 ) {
#if 0
static int warn = 5;
if (--warn <= 0) {
disable_irq(dev->irq);
printk(KERN_INFO "disabling irq\n");
}
#endif
F_2 ( V_2 , L_7 ) ;
F_8 ( V_2 , V_41 ) ;
V_16 -> V_19 -> V_26 |= V_55 ;
V_45 = 1 ;
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
update_supcsr(DT2821_STRIG);
}
handled = 1;
}
#endif
F_24 ( V_2 , V_16 ) ;
return F_25 ( V_45 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_10 ,
unsigned int * V_57 )
{
unsigned int V_5 ;
unsigned int V_24 , V_58 ;
F_27 ( V_59 | ( V_10 - 1 ) , V_2 -> V_48 + V_60 ) ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
V_24 = F_28 ( V_57 [ V_5 ] ) ;
V_58 = F_29 ( V_57 [ V_5 ] ) ;
F_30 ( ( V_58 << 4 ) | ( V_24 ) ) ;
}
F_27 ( V_10 - 1 , V_2 -> V_48 + V_60 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
int V_5 ;
V_11 -> V_43 = V_64 ;
F_30 ( 0 ) ;
F_26 ( V_2 , 1 , & V_62 -> V_65 ) ;
F_4 ( V_66 ) ;
F_32 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
for ( V_5 = 0 ; V_5 < V_62 -> V_10 ; V_5 ++ ) {
F_4 ( V_67 ) ;
F_32 (ad_done(), comedi_error(dev, L_8);
return -ETIME;) ;
V_63 [ V_5 ] =
F_23 ( V_2 -> V_48 +
V_68 ) & ( ( 1 << V_7 . V_8 ) - 1 ) ;
if ( V_11 -> V_12 )
V_63 [ V_5 ] ^= ( 1 << ( V_7 . V_8 - 1 ) ) ;
}
return V_5 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_69 * V_70 )
{
int V_71 = 0 ;
int V_72 ;
V_72 = V_70 -> V_73 ;
V_70 -> V_73 &= V_74 ;
if ( ! V_70 -> V_73 || V_72 != V_70 -> V_73 )
V_71 ++ ;
V_72 = V_70 -> V_75 ;
V_70 -> V_75 &= V_76 | V_77 ;
if ( ! V_70 -> V_75 || V_72 != V_70 -> V_75 )
V_71 ++ ;
V_72 = V_70 -> V_78 ;
V_70 -> V_78 &= V_79 ;
if ( ! V_70 -> V_78 || V_72 != V_70 -> V_78 )
V_71 ++ ;
V_72 = V_70 -> V_80 ;
V_70 -> V_80 &= V_81 ;
if ( ! V_70 -> V_80 || V_72 != V_70 -> V_80 )
V_71 ++ ;
V_72 = V_70 -> V_82 ;
V_70 -> V_82 &= V_81 | V_83 ;
if ( ! V_70 -> V_82 || V_72 != V_70 -> V_82 )
V_71 ++ ;
if ( V_71 )
return 1 ;
if ( V_70 -> V_75 != V_76 &&
V_70 -> V_75 != V_77 )
V_71 ++ ;
if ( V_70 -> V_82 != V_81 && V_70 -> V_82 != V_83 )
V_71 ++ ;
if ( V_71 )
return 2 ;
if ( V_70 -> V_84 != 0 ) {
V_70 -> V_84 = 0 ;
V_71 ++ ;
}
if ( V_70 -> V_75 == V_76 ) {
if ( V_70 -> V_85 != 0 ) {
V_70 -> V_85 = 0 ;
V_71 ++ ;
}
} else {
if ( V_70 -> V_85 != 0 ) {
V_70 -> V_85 = 0 ;
V_71 ++ ;
}
}
if ( V_70 -> V_86 < 4000 ) {
V_70 -> V_86 = 4000 ;
V_71 ++ ;
}
#define F_34 (250*(1<<15)*255)
if ( V_70 -> V_86 > F_34 ) {
V_70 -> V_86 = F_34 ;
V_71 ++ ;
}
if ( V_70 -> V_86 < V_87 -> V_88 ) {
V_70 -> V_86 = V_87 -> V_88 ;
V_71 ++ ;
}
if ( V_70 -> V_89 != V_70 -> V_90 ) {
V_70 -> V_89 = V_70 -> V_90 ;
V_71 ++ ;
}
if ( V_70 -> V_82 == V_81 ) {
} else {
if ( V_70 -> V_91 != 0 ) {
V_70 -> V_91 = 0 ;
V_71 ++ ;
}
}
if ( V_71 )
return 3 ;
V_72 = V_70 -> V_86 ;
F_35 ( & V_70 -> V_86 , V_70 -> V_35 & V_92 ) ;
if ( V_72 != V_70 -> V_86 )
V_71 ++ ;
if ( V_71 )
return 4 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_69 * V_70 = & V_16 -> V_19 -> V_70 ;
int V_93 ;
if ( V_11 -> V_94 == 0 ) {
F_2 ( V_2 ,
L_9
L_10 ) ;
return - V_95 ;
}
F_37 ( V_2 ) ;
if ( V_70 -> V_86 < V_87 -> V_88 )
V_70 -> V_86 = V_87 -> V_88 ;
V_93 = F_35 ( & V_70 -> V_86 , V_96 ) ;
F_27 ( V_93 , V_2 -> V_48 + V_97 ) ;
if ( V_70 -> V_75 == V_76 ) {
V_11 -> V_42 = V_98 | V_99 ;
} else {
V_11 -> V_42 = V_98 | V_99 | V_100 ;
}
F_4 ( V_18 | V_101 | V_102 ) ;
V_11 -> V_36 = V_70 -> V_91 * V_70 -> V_89 ;
V_11 -> V_29 = V_11 -> V_36 ;
V_11 -> V_53 = V_37 ;
V_11 -> V_22 = 0 ;
F_13 ( V_2 , 0 , 0 ) ;
if ( V_11 -> V_36 ) {
F_13 ( V_2 , 1 , 0 ) ;
V_11 -> V_42 |= V_103 ;
F_4 ( 0 ) ;
}
V_11 -> V_43 = 0 ;
F_26 ( V_2 , V_70 -> V_90 , V_70 -> V_57 ) ;
V_11 -> V_43 = V_64 | V_104 ;
F_30 ( 0 ) ;
F_4 ( V_66 ) ;
F_32 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
if ( V_70 -> V_75 == V_76 ) {
F_4 ( V_67 ) ;
} else {
V_11 -> V_42 |= V_105 ;
F_4 ( 0 ) ;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_11 -> V_94 ) {
F_6 ( V_11 -> V_23 [ 0 ] . V_24 ) ;
F_6 ( V_11 -> V_23 [ 1 ] . V_24 ) ;
}
}
static int F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_37 ( V_2 ) ;
V_11 -> V_43 = 0 ;
F_30 ( 0 ) ;
V_11 -> V_42 = 0 ;
F_4 ( V_102 ) ;
return 0 ;
}
static int F_35 ( int * V_106 , int V_107 )
{
int V_108 , V_109 , V_110 ;
for ( V_108 = 0 ; V_108 < 16 ; V_108 ++ ) {
if ( V_108 == 1 )
continue;
V_109 = 250 * ( 1 << V_108 ) ;
switch ( V_107 ) {
case V_96 :
default:
V_110 = ( * V_106 + V_109 / 2 ) / V_109 ;
break;
case V_111 :
V_110 = ( * V_106 ) / V_109 ;
break;
case V_112 :
V_110 = ( * V_106 + V_109 - 1 ) / V_109 ;
break;
}
if ( V_110 < 256 ) {
* V_106 = V_110 * V_109 ;
return ( V_108 << 8 ) | ( 255 - V_110 ) ;
}
}
V_109 = 250 * ( 1 << 15 ) ;
V_110 = 255 ;
* V_106 = V_110 * V_109 ;
return ( 15 << 8 ) | ( 255 - V_110 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
V_63 [ 0 ] = V_11 -> V_113 [ F_28 ( V_62 -> V_65 ) ] ;
return 1 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
short V_40 ;
unsigned int V_24 ;
V_24 = F_28 ( V_62 -> V_65 ) ;
V_40 = V_63 [ 0 ] ;
V_40 &= ( 1 << V_7 . V_114 ) - 1 ;
V_11 -> V_113 [ V_24 ] = V_40 ;
V_11 -> V_44 |= V_115 ;
if ( V_24 ) {
V_11 -> V_44 |= V_116 ;
if ( V_11 -> V_117 )
V_40 ^= ( 1 << ( V_7 . V_114 - 1 ) ) ;
} else {
V_11 -> V_44 &= ~ V_116 ;
if ( V_11 -> V_118 )
V_40 ^= ( 1 << ( V_7 . V_114 - 1 ) ) ;
}
F_40 ( 0 ) ;
F_27 ( V_40 , V_2 -> V_48 + V_119 ) ;
F_4 ( V_120 ) ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_69 * V_70 )
{
int V_71 = 0 ;
int V_72 ;
V_72 = V_70 -> V_73 ;
V_70 -> V_73 &= V_121 ;
if ( ! V_70 -> V_73 || V_72 != V_70 -> V_73 )
V_71 ++ ;
V_72 = V_70 -> V_75 ;
V_70 -> V_75 &= V_79 ;
if ( ! V_70 -> V_75 || V_72 != V_70 -> V_75 )
V_71 ++ ;
V_72 = V_70 -> V_78 ;
V_70 -> V_78 &= V_74 ;
if ( ! V_70 -> V_78 || V_72 != V_70 -> V_78 )
V_71 ++ ;
V_72 = V_70 -> V_80 ;
V_70 -> V_80 &= V_81 ;
if ( ! V_70 -> V_80 || V_72 != V_70 -> V_80 )
V_71 ++ ;
V_72 = V_70 -> V_82 ;
V_70 -> V_82 &= V_83 ;
if ( ! V_70 -> V_82 || V_72 != V_70 -> V_82 )
V_71 ++ ;
if ( V_71 )
return 1 ;
if ( V_70 -> V_82 != V_81 && V_70 -> V_82 != V_83 )
V_71 ++ ;
if ( V_71 )
return 2 ;
if ( V_70 -> V_84 != 0 ) {
V_70 -> V_84 = 0 ;
V_71 ++ ;
}
if ( V_70 -> V_85 < 5000 ) {
V_70 -> V_85 = 5000 ;
V_71 ++ ;
}
if ( V_70 -> V_86 != 0 ) {
V_70 -> V_86 = 0 ;
V_71 ++ ;
}
if ( V_70 -> V_89 > 2 ) {
V_70 -> V_89 = 2 ;
V_71 ++ ;
}
if ( V_70 -> V_82 == V_81 ) {
} else {
if ( V_70 -> V_91 != 0 ) {
V_70 -> V_91 = 0 ;
V_71 ++ ;
}
}
if ( V_71 )
return 3 ;
V_72 = V_70 -> V_85 ;
F_35 ( & V_70 -> V_85 , V_70 -> V_35 & V_92 ) ;
if ( V_72 != V_70 -> V_85 )
V_71 ++ ;
if ( V_71 )
return 4 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned int V_122 )
{
int V_14 ;
if ( V_122 != 0 )
return - V_123 ;
V_14 = F_7 ( V_16 , V_11 -> V_23 [ 0 ] . V_3 ,
V_11 -> V_25 ) ;
if ( V_14 == 0 ) {
F_5 ( V_21 L_3 ) ;
return - V_124 ;
}
F_9 ( V_2 , 0 , V_14 ) ;
V_14 = F_7 ( V_16 , V_11 -> V_23 [ 1 ] . V_3 ,
V_11 -> V_25 ) ;
if ( V_14 == 0 ) {
F_5 ( V_21 L_3 ) ;
return - V_124 ;
}
F_9 ( V_2 , 1 , V_14 ) ;
F_4 ( V_67 ) ;
V_16 -> V_19 -> V_125 = NULL ;
return 1 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_93 ;
struct V_69 * V_70 = & V_16 -> V_19 -> V_70 ;
if ( V_11 -> V_94 == 0 ) {
F_2 ( V_2 ,
L_9
L_10 ) ;
return - V_95 ;
}
F_37 ( V_2 ) ;
V_11 -> V_42 = V_98 | V_100 | V_103 ;
F_4 ( V_18 | V_101 | V_126 ) ;
V_11 -> V_36 = V_70 -> V_91 * V_70 -> V_90 ;
V_11 -> V_29 = V_11 -> V_36 ;
V_11 -> V_53 = V_38 ;
V_11 -> V_22 = 0 ;
V_93 = F_35 ( & V_70 -> V_85 , V_96 ) ;
F_27 ( V_93 , V_2 -> V_48 + V_97 ) ;
V_11 -> V_44 = V_115 | V_127 | V_128 ;
F_40 ( 0 ) ;
V_16 -> V_19 -> V_125 = F_42 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
F_37 ( V_2 ) ;
V_11 -> V_44 = 0 ;
F_40 ( 0 ) ;
V_11 -> V_42 = 0 ;
F_4 ( V_126 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
if ( V_63 [ 0 ] ) {
V_16 -> V_129 &= ~ V_63 [ 0 ] ;
V_16 -> V_129 |= ( V_63 [ 0 ] & V_63 [ 1 ] ) ;
F_27 ( V_16 -> V_129 , V_2 -> V_48 + V_130 ) ;
}
V_63 [ 1 ] = F_23 ( V_2 -> V_48 + V_130 ) ;
return 2 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_61 * V_62 , unsigned int * V_63 )
{
int V_6 ;
V_6 = ( F_28 ( V_62 -> V_65 ) < 8 ) ? 0x00ff : 0xff00 ;
if ( V_63 [ 0 ] )
V_16 -> V_131 |= V_6 ;
else
V_16 -> V_131 &= ~ V_6 ;
if ( V_16 -> V_131 & 0x00ff )
V_11 -> V_44 |= V_132 ;
else
V_11 -> V_44 &= ~ V_132 ;
if ( V_16 -> V_131 & 0xff00 )
V_11 -> V_44 |= V_133 ;
else
V_11 -> V_44 &= ~ V_133 ;
F_27 ( V_11 -> V_44 , V_2 -> V_48 + V_50 ) ;
return 1 ;
}
static const struct V_134 * F_46 ( int V_135 , int V_122 )
{
if ( V_135 ) {
if ( V_122 < 0 || V_122 >= 2 )
V_122 = 0 ;
return V_136 [ V_122 ] ;
} else {
if ( V_122 < 0 || V_122 >= 4 )
V_122 = 0 ;
return V_137 [ V_122 ] ;
}
}
static const struct V_134 * F_47 ( int V_122 )
{
if ( V_122 < 0 || V_122 >= 5 )
V_122 = 0 ;
return V_138 [ V_122 ] ;
}
static int F_48 ( struct V_1 * V_2 , int V_139 , int V_140 )
{
int V_28 ;
V_11 -> V_94 = 0 ;
if ( ! V_139 && ! V_140 ) {
F_5 ( V_21 L_11 ) ;
return 0 ;
}
if ( V_139 == V_140 || V_139 < 5 || V_140 < 5 || V_139 > 7 || V_140 > 7 )
return - V_123 ;
if ( V_140 < V_139 ) {
int V_5 ;
V_5 = V_139 ;
V_139 = V_140 ;
V_140 = V_5 ;
}
V_28 = F_49 ( V_139 , L_12 ) ;
if ( V_28 )
return - V_141 ;
V_11 -> V_23 [ 0 ] . V_24 = V_139 ;
V_28 = F_49 ( V_140 , L_13 ) ;
if ( V_28 )
return - V_141 ;
V_11 -> V_23 [ 1 ] . V_24 = V_140 ;
V_11 -> V_25 = V_142 ;
V_11 -> V_23 [ 0 ] . V_3 = ( void * ) F_50 ( V_143 | V_144 ) ;
V_11 -> V_23 [ 1 ] . V_3 = ( void * ) F_50 ( V_143 | V_144 ) ;
if ( ! V_11 -> V_23 [ 0 ] . V_3 || ! V_11 -> V_23 [ 1 ] . V_3 ) {
F_5 ( V_21 L_14 ) ;
return - V_145 ;
}
F_5 ( V_30 L_15 , V_139 , V_140 ) ;
V_11 -> V_94 = 1 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
int V_5 , V_39 ;
int V_28 ;
struct V_15 * V_16 ;
unsigned long V_48 ;
V_2 -> V_148 = V_87 -> V_149 ;
V_48 = V_147 -> V_150 [ V_151 ] ;
if ( ! V_48 )
V_48 = 0x240 ;
F_5 ( V_30 L_16 , V_2 -> V_152 , V_48 ) ;
if ( ! F_52 ( V_48 , V_153 , L_17 ) ) {
F_5 ( V_30 L_18 ) ;
return - V_141 ;
}
V_2 -> V_48 = V_48 ;
F_27 ( V_154 , V_2 -> V_48 + V_51 ) ;
V_5 = F_23 ( V_2 -> V_48 + V_49 ) ;
#ifdef F_53
F_5 ( V_155 L_19 ,
F_23 ( V_2 -> V_48 + V_49 ) ,
F_23 ( V_2 -> V_48 + V_60 ) ,
F_23 ( V_2 -> V_48 + V_50 ) ,
F_23 ( V_2 -> V_48 + V_51 ) ,
F_23 ( V_2 -> V_48 + V_97 ) ) ;
#endif
if ( ( ( F_23 ( V_2 -> V_48 + V_49 ) & V_156 )
!= V_157 ) ||
( ( F_23 ( V_2 -> V_48 + V_60 ) & V_158 )
!= V_159 ) ||
( ( F_23 ( V_2 -> V_48 + V_50 ) & V_160 )
!= V_161 ) ||
( ( F_23 ( V_2 -> V_48 + V_51 ) & V_162 )
!= V_163 ) ||
( ( F_23 ( V_2 -> V_48 + V_97 ) & V_164 )
!= V_165 ) ) {
F_5 ( V_21 L_20 ) ;
return - V_95 ;
}
V_39 = V_147 -> V_150 [ V_166 ] ;
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
if ( V_39 > 0 ) {
F_5 ( V_30 L_21 , V_39 ) ;
V_28 = F_54 ( V_39 , F_22 , 0 , L_17 , V_2 ) ;
if ( V_28 < 0 ) {
F_5 ( V_21 L_22 ) ;
return - V_95 ;
}
V_2 -> V_39 = V_39 ;
} else if ( V_39 == 0 ) {
F_5 ( V_30 L_23 ) ;
} else {
#if 0
printk(KERN_INFO " (probe returned multiple irqs--bad)");
#else
F_5 ( V_30 L_24 ) ;
#endif
}
V_28 = F_55 ( V_2 , sizeof( struct V_167 ) ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_48 ( V_2 , V_147 -> V_150 [ V_168 ] ,
V_147 -> V_150 [ V_169 ] ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_56 ( V_2 , 3 ) ;
if ( V_28 < 0 )
return V_28 ;
V_16 = V_2 -> V_17 + 0 ;
V_2 -> V_170 = V_16 ;
V_16 -> type = V_171 ;
V_16 -> V_172 = V_173 | V_174 |
( ( V_147 -> V_150 [ V_175 ] ) ? V_176 : V_177 ) ;
V_16 -> V_178 =
( V_147 -> V_150 [ V_175 ] ) ? V_7 . V_179 : V_7 . V_180 ;
V_16 -> V_181 = F_31 ;
V_16 -> V_182 = F_33 ;
V_16 -> V_183 = F_36 ;
V_16 -> V_184 = F_12 ;
V_16 -> V_185 = ( 1 << V_7 . V_8 ) - 1 ;
V_16 -> V_186 = 16 ;
V_16 -> V_187 =
F_46 ( V_7 . V_135 , V_147 -> V_150 [ V_188 ] ) ;
V_11 -> V_12 = V_147 -> V_150 [ V_189 ] ;
V_16 ++ ;
V_16 -> V_178 = V_7 . V_190 ;
if ( V_16 -> V_178 ) {
V_16 -> type = V_191 ;
V_2 -> V_192 = V_16 ;
V_16 -> V_172 = V_193 | V_194 ;
V_16 -> V_181 = F_38 ;
V_16 -> V_195 = F_39 ;
V_16 -> V_182 = F_41 ;
V_16 -> V_183 = F_43 ;
V_16 -> V_184 = F_8 ;
V_16 -> V_185 = ( 1 << V_7 . V_114 ) - 1 ;
V_16 -> V_186 = 2 ;
V_16 -> V_196 = V_11 -> V_197 ;
V_11 -> V_197 [ 0 ] =
F_47 ( V_147 -> V_150 [ V_198 ] ) ;
V_11 -> V_197 [ 1 ] =
F_47 ( V_147 -> V_150 [ V_199 ] ) ;
V_11 -> V_117 = V_147 -> V_150 [ V_200 ] ;
V_11 -> V_118 = V_147 -> V_150 [ V_201 ] ;
} else {
V_16 -> type = V_202 ;
}
V_16 ++ ;
V_16 -> type = V_203 ;
V_16 -> V_172 = V_173 | V_193 ;
V_16 -> V_178 = 16 ;
V_16 -> V_204 = F_44 ;
V_16 -> V_205 = F_45 ;
V_16 -> V_185 = 1 ;
V_16 -> V_187 = & V_206 ;
F_5 ( V_30 L_25 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 )
F_58 ( V_2 -> V_39 , V_2 ) ;
if ( V_2 -> V_48 )
F_59 ( V_2 -> V_48 , V_153 ) ;
if ( V_2 -> V_207 ) {
if ( V_11 -> V_23 [ 0 ] . V_24 )
F_60 ( V_11 -> V_23 [ 0 ] . V_24 ) ;
if ( V_11 -> V_23 [ 1 ] . V_24 )
F_60 ( V_11 -> V_23 [ 1 ] . V_24 ) ;
if ( V_11 -> V_23 [ 0 ] . V_3 )
F_61 ( ( unsigned long ) V_11 -> V_23 [ 0 ] . V_3 ) ;
if ( V_11 -> V_23 [ 1 ] . V_3 )
F_61 ( ( unsigned long ) V_11 -> V_23 [ 1 ] . V_3 ) ;
}
}
