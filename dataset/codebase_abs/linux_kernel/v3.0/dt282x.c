static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void F_5 ( struct V_2 * V_3 , short * V_4 ,
unsigned int V_5 )
{
unsigned int V_6 ;
unsigned short V_7 = ( 1 << V_8 . V_9 ) - 1 ;
unsigned short V_10 = 1 << ( V_8 . V_9 - 1 ) ;
int V_11 ;
if ( V_12 -> V_13 )
V_10 = 1 << ( V_8 . V_9 - 1 ) ;
else
V_10 = 0 ;
if ( V_5 % 2 )
F_6 ( V_3 , L_1 ) ;
V_11 = V_5 / 2 ;
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ )
V_4 [ V_6 ] = ( V_4 [ V_6 ] & V_7 ) ^ V_10 ;
}
static void F_7 ( struct V_2 * V_3 )
{
void * V_14 ;
int V_15 ;
int V_6 ;
struct V_16 * V_17 = V_3 -> V_18 + 1 ;
F_8 ( V_19 ) ;
if ( ! V_17 -> V_20 -> V_21 ) {
F_9 ( V_22 L_2 ) ;
return;
}
V_6 = V_12 -> V_23 ;
V_14 = V_12 -> V_24 [ V_6 ] . V_4 ;
F_10 ( V_12 -> V_24 [ V_6 ] . V_25 ) ;
V_12 -> V_23 = 1 - V_6 ;
V_15 = F_11 ( V_17 , V_14 , V_12 -> V_26 ) ;
if ( V_15 == 0 ) {
F_9 ( V_22 L_3 ) ;
F_12 ( V_3 , V_17 ) ;
V_17 -> V_20 -> V_27 |= V_28 ;
return;
}
F_13 ( V_3 , V_6 , V_15 ) ;
return;
}
static void F_14 ( struct V_2 * V_3 )
{
void * V_14 ;
int V_15 ;
int V_6 ;
int V_29 ;
struct V_16 * V_17 = V_3 -> V_18 ;
F_8 ( V_19 ) ;
if ( ! V_17 -> V_20 -> V_21 ) {
F_9 ( V_22 L_2 ) ;
return;
}
V_6 = V_12 -> V_23 ;
V_14 = V_12 -> V_24 [ V_6 ] . V_4 ;
V_15 = V_12 -> V_24 [ V_6 ] . V_15 ;
F_10 ( V_12 -> V_24 [ V_6 ] . V_25 ) ;
V_12 -> V_23 = 1 - V_6 ;
F_5 ( V_3 , V_14 , V_15 ) ;
V_29 = F_15 ( V_17 , V_14 , V_15 ) ;
if ( V_29 != V_15 ) {
F_16 ( V_3 , V_17 ) ;
return;
}
V_12 -> V_30 -= V_15 / 2 ;
if ( V_12 -> V_30 < 0 ) {
F_9 ( V_31 L_4 ) ;
V_12 -> V_30 = 0 ;
}
if ( ! V_12 -> V_30 ) {
F_16 ( V_3 , V_17 ) ;
V_17 -> V_20 -> V_27 |= V_32 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
update_supcsr(0);
}
#endif
F_17 ( V_3 , V_6 , 0 ) ;
}
static int F_17 ( struct V_2 * V_3 , int V_33 , int V_11 )
{
int V_34 ;
unsigned long V_35 ;
unsigned long V_36 ;
if ( ! V_12 -> V_37 )
return 0 ;
if ( V_11 == 0 )
V_11 = V_12 -> V_26 ;
if ( V_11 > V_12 -> V_37 * 2 )
V_11 = V_12 -> V_37 * 2 ;
V_12 -> V_37 -= V_11 / 2 ;
V_12 -> V_24 [ V_33 ] . V_15 = V_11 ;
V_34 = V_12 -> V_24 [ V_33 ] . V_25 ;
V_35 = F_18 ( V_12 -> V_24 [ V_33 ] . V_4 ) ;
F_19 ( V_34 , V_38 ) ;
V_36 = F_20 () ;
F_21 ( V_34 ) ;
F_22 ( V_34 , V_35 ) ;
F_23 ( V_34 , V_11 ) ;
F_24 ( V_36 ) ;
F_25 ( V_34 ) ;
return V_11 ;
}
static int F_13 ( struct V_2 * V_3 , int V_33 , int V_11 )
{
int V_34 ;
unsigned long V_35 ;
unsigned long V_36 ;
V_12 -> V_24 [ V_33 ] . V_15 = V_11 ;
V_34 = V_12 -> V_24 [ V_33 ] . V_25 ;
V_35 = F_18 ( V_12 -> V_24 [ V_33 ] . V_4 ) ;
F_19 ( V_34 , V_39 ) ;
V_36 = F_20 () ;
F_21 ( V_34 ) ;
F_22 ( V_34 , V_35 ) ;
F_23 ( V_34 , V_11 ) ;
F_24 ( V_36 ) ;
F_25 ( V_34 ) ;
return V_11 ;
}
static T_3 F_26 ( int V_40 , void * V_41 )
{
struct V_2 * V_3 = V_41 ;
struct V_16 * V_17 ;
struct V_16 * V_42 ;
unsigned int V_43 , V_44 , V_45 ;
int V_46 = 0 ;
if ( ! V_3 -> V_47 ) {
F_6 ( V_3 , L_5 ) ;
return V_48 ;
}
V_17 = V_3 -> V_18 + 0 ;
V_42 = V_3 -> V_18 + 1 ;
V_44 = F_27 ( V_3 -> V_49 + V_50 ) ;
V_45 = F_27 ( V_3 -> V_49 + V_51 ) ;
V_43 = F_27 ( V_3 -> V_49 + V_52 ) ;
if ( V_43 & V_53 ) {
if ( V_12 -> V_54 == V_38 )
F_14 ( V_3 ) ;
else
F_7 ( V_3 ) ;
V_46 = 1 ;
}
if ( V_44 & V_55 ) {
if ( V_12 -> V_30 != 0 ) {
F_6 ( V_3 , L_6 ) ;
F_16 ( V_3 , V_17 ) ;
V_17 -> V_20 -> V_27 |= V_56 ;
}
V_46 = 1 ;
}
if ( V_45 & V_57 ) {
#if 0
static int warn = 5;
if (--warn <= 0) {
disable_irq(dev->irq);
printk(KERN_INFO "disabling irq\n");
}
#endif
F_6 ( V_3 , L_7 ) ;
F_12 ( V_3 , V_42 ) ;
V_17 -> V_20 -> V_27 |= V_56 ;
V_46 = 1 ;
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
F_28 ( V_3 , V_17 ) ;
return F_29 ( V_46 ) ;
}
static void F_30 ( struct V_2 * V_3 , int V_11 ,
unsigned int * V_58 )
{
unsigned int V_6 ;
unsigned int V_25 , V_59 ;
F_31 ( V_60 | ( V_11 - 1 ) , V_3 -> V_49 + V_61 ) ;
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
V_25 = F_32 ( V_58 [ V_6 ] ) ;
V_59 = F_33 ( V_58 [ V_6 ] ) ;
F_34 ( ( V_59 << 4 ) | ( V_25 ) ) ;
}
F_31 ( V_11 - 1 , V_3 -> V_49 + V_61 ) ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_62 * V_63 , unsigned int * V_64 )
{
int V_6 ;
V_12 -> V_44 = V_65 ;
F_34 ( 0 ) ;
F_30 ( V_3 , 1 , & V_63 -> V_66 ) ;
F_8 ( V_67 ) ;
F_36 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
for ( V_6 = 0 ; V_6 < V_63 -> V_11 ; V_6 ++ ) {
F_8 ( V_68 ) ;
F_36 (ad_done(), comedi_error(dev, L_8);
return -ETIME;) ;
V_64 [ V_6 ] =
F_27 ( V_3 -> V_49 +
V_69 ) & ( ( 1 << V_8 . V_9 ) - 1 ) ;
if ( V_12 -> V_13 )
V_64 [ V_6 ] ^= ( 1 << ( V_8 . V_9 - 1 ) ) ;
}
return V_6 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_16 * V_17 , struct V_70 * V_71 )
{
int V_72 = 0 ;
int V_73 ;
V_73 = V_71 -> V_74 ;
V_71 -> V_74 &= V_75 ;
if ( ! V_71 -> V_74 || V_73 != V_71 -> V_74 )
V_72 ++ ;
V_73 = V_71 -> V_76 ;
V_71 -> V_76 &= V_77 | V_78 ;
if ( ! V_71 -> V_76 || V_73 != V_71 -> V_76 )
V_72 ++ ;
V_73 = V_71 -> V_79 ;
V_71 -> V_79 &= V_80 ;
if ( ! V_71 -> V_79 || V_73 != V_71 -> V_79 )
V_72 ++ ;
V_73 = V_71 -> V_81 ;
V_71 -> V_81 &= V_82 ;
if ( ! V_71 -> V_81 || V_73 != V_71 -> V_81 )
V_72 ++ ;
V_73 = V_71 -> V_83 ;
V_71 -> V_83 &= V_82 | V_84 ;
if ( ! V_71 -> V_83 || V_73 != V_71 -> V_83 )
V_72 ++ ;
if ( V_72 )
return 1 ;
if ( V_71 -> V_76 != V_77 &&
V_71 -> V_76 != V_78 )
V_72 ++ ;
if ( V_71 -> V_83 != V_82 && V_71 -> V_83 != V_84 )
V_72 ++ ;
if ( V_72 )
return 2 ;
if ( V_71 -> V_85 != 0 ) {
V_71 -> V_85 = 0 ;
V_72 ++ ;
}
if ( V_71 -> V_76 == V_77 ) {
if ( V_71 -> V_86 != 0 ) {
V_71 -> V_86 = 0 ;
V_72 ++ ;
}
} else {
if ( V_71 -> V_86 != 0 ) {
V_71 -> V_86 = 0 ;
V_72 ++ ;
}
}
if ( V_71 -> V_87 < 4000 ) {
V_71 -> V_87 = 4000 ;
V_72 ++ ;
}
#define F_38 (250*(1<<15)*255)
if ( V_71 -> V_87 > F_38 ) {
V_71 -> V_87 = F_38 ;
V_72 ++ ;
}
if ( V_71 -> V_87 < V_88 -> V_89 ) {
V_71 -> V_87 = V_88 -> V_89 ;
V_72 ++ ;
}
if ( V_71 -> V_90 != V_71 -> V_91 ) {
V_71 -> V_90 = V_71 -> V_91 ;
V_72 ++ ;
}
if ( V_71 -> V_83 == V_82 ) {
} else {
if ( V_71 -> V_92 != 0 ) {
V_71 -> V_92 = 0 ;
V_72 ++ ;
}
}
if ( V_72 )
return 3 ;
V_73 = V_71 -> V_87 ;
F_39 ( & V_71 -> V_87 , V_71 -> V_36 & V_93 ) ;
if ( V_73 != V_71 -> V_87 )
V_72 ++ ;
if ( V_72 )
return 4 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_70 * V_71 = & V_17 -> V_20 -> V_71 ;
int V_94 ;
if ( V_12 -> V_95 == 0 ) {
F_6 ( V_3 ,
L_9
L_10 ) ;
return - V_96 ;
}
F_41 ( V_3 ) ;
if ( V_71 -> V_87 < V_88 -> V_89 )
V_71 -> V_87 = V_88 -> V_89 ;
V_94 = F_39 ( & V_71 -> V_87 , V_97 ) ;
F_31 ( V_94 , V_3 -> V_49 + V_98 ) ;
if ( V_71 -> V_76 == V_77 ) {
V_12 -> V_43 = V_99 | V_100 ;
} else {
V_12 -> V_43 = V_99 | V_100 | V_101 ;
}
F_8 ( V_19 | V_102 | V_103 ) ;
V_12 -> V_37 = V_71 -> V_92 * V_71 -> V_90 ;
V_12 -> V_30 = V_12 -> V_37 ;
V_12 -> V_54 = V_38 ;
V_12 -> V_23 = 0 ;
F_17 ( V_3 , 0 , 0 ) ;
if ( V_12 -> V_37 ) {
F_17 ( V_3 , 1 , 0 ) ;
V_12 -> V_43 |= V_104 ;
F_8 ( 0 ) ;
}
V_12 -> V_44 = 0 ;
F_30 ( V_3 , V_71 -> V_91 , V_71 -> V_58 ) ;
V_12 -> V_44 = V_65 | V_105 ;
F_34 ( 0 ) ;
F_8 ( V_67 ) ;
F_36 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
if ( V_71 -> V_76 == V_77 ) {
F_8 ( V_68 ) ;
} else {
V_12 -> V_43 |= V_106 ;
F_8 ( 0 ) ;
}
return 0 ;
}
static void F_41 ( struct V_2 * V_3 )
{
if ( V_12 -> V_95 ) {
F_10 ( V_12 -> V_24 [ 0 ] . V_25 ) ;
F_10 ( V_12 -> V_24 [ 1 ] . V_25 ) ;
}
}
static int F_16 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
F_41 ( V_3 ) ;
V_12 -> V_44 = 0 ;
F_34 ( 0 ) ;
V_12 -> V_43 = 0 ;
F_8 ( V_103 ) ;
return 0 ;
}
static int F_39 ( int * V_107 , int V_108 )
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
static int F_42 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_62 * V_63 , unsigned int * V_64 )
{
V_64 [ 0 ] = V_12 -> V_114 [ F_32 ( V_63 -> V_66 ) ] ;
return 1 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_62 * V_63 , unsigned int * V_64 )
{
short V_41 ;
unsigned int V_25 ;
V_25 = F_32 ( V_63 -> V_66 ) ;
V_41 = V_64 [ 0 ] ;
V_41 &= ( 1 << V_8 . V_115 ) - 1 ;
V_12 -> V_114 [ V_25 ] = V_41 ;
V_12 -> V_45 |= V_116 ;
if ( V_25 ) {
V_12 -> V_45 |= V_117 ;
if ( V_12 -> V_118 )
V_41 ^= ( 1 << ( V_8 . V_115 - 1 ) ) ;
} else {
V_12 -> V_45 &= ~ V_117 ;
if ( V_12 -> V_119 )
V_41 ^= ( 1 << ( V_8 . V_115 - 1 ) ) ;
}
F_44 ( 0 ) ;
F_31 ( V_41 , V_3 -> V_49 + V_120 ) ;
F_8 ( V_121 ) ;
return 1 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_16 * V_17 , struct V_70 * V_71 )
{
int V_72 = 0 ;
int V_73 ;
V_73 = V_71 -> V_74 ;
V_71 -> V_74 &= V_122 ;
if ( ! V_71 -> V_74 || V_73 != V_71 -> V_74 )
V_72 ++ ;
V_73 = V_71 -> V_76 ;
V_71 -> V_76 &= V_80 ;
if ( ! V_71 -> V_76 || V_73 != V_71 -> V_76 )
V_72 ++ ;
V_73 = V_71 -> V_79 ;
V_71 -> V_79 &= V_75 ;
if ( ! V_71 -> V_79 || V_73 != V_71 -> V_79 )
V_72 ++ ;
V_73 = V_71 -> V_81 ;
V_71 -> V_81 &= V_82 ;
if ( ! V_71 -> V_81 || V_73 != V_71 -> V_81 )
V_72 ++ ;
V_73 = V_71 -> V_83 ;
V_71 -> V_83 &= V_84 ;
if ( ! V_71 -> V_83 || V_73 != V_71 -> V_83 )
V_72 ++ ;
if ( V_72 )
return 1 ;
if ( V_71 -> V_83 != V_82 && V_71 -> V_83 != V_84 )
V_72 ++ ;
if ( V_72 )
return 2 ;
if ( V_71 -> V_85 != 0 ) {
V_71 -> V_85 = 0 ;
V_72 ++ ;
}
if ( V_71 -> V_86 < 5000 ) {
V_71 -> V_86 = 5000 ;
V_72 ++ ;
}
if ( V_71 -> V_87 != 0 ) {
V_71 -> V_87 = 0 ;
V_72 ++ ;
}
if ( V_71 -> V_90 > 2 ) {
V_71 -> V_90 = 2 ;
V_72 ++ ;
}
if ( V_71 -> V_83 == V_82 ) {
} else {
if ( V_71 -> V_92 != 0 ) {
V_71 -> V_92 = 0 ;
V_72 ++ ;
}
}
if ( V_72 )
return 3 ;
V_73 = V_71 -> V_86 ;
F_39 ( & V_71 -> V_86 , V_71 -> V_36 & V_93 ) ;
if ( V_73 != V_71 -> V_86 )
V_72 ++ ;
if ( V_72 )
return 4 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_16 * V_17 , unsigned int V_123 )
{
int V_15 ;
if ( V_123 != 0 )
return - V_124 ;
V_15 = F_11 ( V_17 , V_12 -> V_24 [ 0 ] . V_4 ,
V_12 -> V_26 ) ;
if ( V_15 == 0 ) {
F_9 ( V_22 L_3 ) ;
return - V_125 ;
}
F_13 ( V_3 , 0 , V_15 ) ;
V_15 = F_11 ( V_17 , V_12 -> V_24 [ 1 ] . V_4 ,
V_12 -> V_26 ) ;
if ( V_15 == 0 ) {
F_9 ( V_22 L_3 ) ;
return - V_125 ;
}
F_13 ( V_3 , 1 , V_15 ) ;
F_8 ( V_68 ) ;
V_17 -> V_20 -> V_126 = NULL ;
return 1 ;
}
static int F_47 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
int V_94 ;
struct V_70 * V_71 = & V_17 -> V_20 -> V_71 ;
if ( V_12 -> V_95 == 0 ) {
F_6 ( V_3 ,
L_9
L_10 ) ;
return - V_96 ;
}
F_41 ( V_3 ) ;
V_12 -> V_43 = V_99 | V_101 | V_104 ;
F_8 ( V_19 | V_102 | V_127 ) ;
V_12 -> V_37 = V_71 -> V_92 * V_71 -> V_91 ;
V_12 -> V_30 = V_12 -> V_37 ;
V_12 -> V_54 = V_39 ;
V_12 -> V_23 = 0 ;
V_94 = F_39 ( & V_71 -> V_86 , V_97 ) ;
F_31 ( V_94 , V_3 -> V_49 + V_98 ) ;
V_12 -> V_45 = V_116 | V_128 | V_129 ;
F_44 ( 0 ) ;
V_17 -> V_20 -> V_126 = F_46 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
F_41 ( V_3 ) ;
V_12 -> V_45 = 0 ;
F_44 ( 0 ) ;
V_12 -> V_43 = 0 ;
F_8 ( V_127 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_62 * V_63 , unsigned int * V_64 )
{
if ( V_64 [ 0 ] ) {
V_17 -> V_130 &= ~ V_64 [ 0 ] ;
V_17 -> V_130 |= ( V_64 [ 0 ] & V_64 [ 1 ] ) ;
F_31 ( V_17 -> V_130 , V_3 -> V_49 + V_131 ) ;
}
V_64 [ 1 ] = F_27 ( V_3 -> V_49 + V_131 ) ;
return 2 ;
}
static int F_49 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
struct V_62 * V_63 , unsigned int * V_64 )
{
int V_7 ;
V_7 = ( F_32 ( V_63 -> V_66 ) < 8 ) ? 0x00ff : 0xff00 ;
if ( V_64 [ 0 ] )
V_17 -> V_132 |= V_7 ;
else
V_17 -> V_132 &= ~ V_7 ;
if ( V_17 -> V_132 & 0x00ff )
V_12 -> V_45 |= V_133 ;
else
V_12 -> V_45 &= ~ V_133 ;
if ( V_17 -> V_132 & 0xff00 )
V_12 -> V_45 |= V_134 ;
else
V_12 -> V_45 &= ~ V_134 ;
F_31 ( V_12 -> V_45 , V_3 -> V_49 + V_51 ) ;
return 1 ;
}
static const struct V_135 * F_50 ( int V_136 , int V_123 )
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
static const struct V_135 * F_51 ( int V_123 )
{
if ( V_123 < 0 || V_123 >= 5 )
V_123 = 0 ;
return V_139 [ V_123 ] ;
}
static int F_52 ( struct V_2 * V_3 , struct V_140 * V_141 )
{
int V_6 , V_40 ;
int V_29 ;
struct V_16 * V_17 ;
unsigned long V_49 ;
V_3 -> V_142 = V_88 -> V_143 ;
V_49 = V_141 -> V_144 [ V_145 ] ;
if ( ! V_49 )
V_49 = 0x240 ;
F_9 ( V_31 L_11 , V_3 -> V_146 , V_49 ) ;
if ( ! F_53 ( V_49 , V_147 , L_12 ) ) {
F_9 ( V_31 L_13 ) ;
return - V_148 ;
}
V_3 -> V_49 = V_49 ;
F_31 ( V_149 , V_3 -> V_49 + V_52 ) ;
V_6 = F_27 ( V_3 -> V_49 + V_50 ) ;
#ifdef F_54
F_9 ( V_150 L_14 ,
F_27 ( V_3 -> V_49 + V_50 ) ,
F_27 ( V_3 -> V_49 + V_61 ) ,
F_27 ( V_3 -> V_49 + V_51 ) ,
F_27 ( V_3 -> V_49 + V_52 ) ,
F_27 ( V_3 -> V_49 + V_98 ) ) ;
#endif
if ( ( ( F_27 ( V_3 -> V_49 + V_50 ) & V_151 )
!= V_152 ) ||
( ( F_27 ( V_3 -> V_49 + V_61 ) & V_153 )
!= V_154 ) ||
( ( F_27 ( V_3 -> V_49 + V_51 ) & V_155 )
!= V_156 ) ||
( ( F_27 ( V_3 -> V_49 + V_52 ) & V_157 )
!= V_158 ) ||
( ( F_27 ( V_3 -> V_49 + V_98 ) & V_159 )
!= V_160 ) ) {
F_9 ( V_22 L_15 ) ;
return - V_96 ;
}
V_40 = V_141 -> V_144 [ V_161 ] ;
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
if ( V_40 > 0 ) {
F_9 ( V_31 L_16 , V_40 ) ;
V_29 = F_55 ( V_40 , F_26 , 0 , L_12 , V_3 ) ;
if ( V_29 < 0 ) {
F_9 ( V_22 L_17 ) ;
return - V_96 ;
}
V_3 -> V_40 = V_40 ;
} else if ( V_40 == 0 ) {
F_9 ( V_31 L_18 ) ;
} else {
#if 0
printk(KERN_INFO " (probe returned multiple irqs--bad)");
#else
F_9 ( V_31 L_19 ) ;
#endif
}
V_29 = F_56 ( V_3 , sizeof( struct V_162 ) ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_57 ( V_3 , V_141 -> V_144 [ V_163 ] ,
V_141 -> V_144 [ V_164 ] ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_58 ( V_3 , 3 ) ;
if ( V_29 < 0 )
return V_29 ;
V_17 = V_3 -> V_18 + 0 ;
V_3 -> V_165 = V_17 ;
V_17 -> type = V_166 ;
V_17 -> V_167 = V_168 | V_169 |
( ( V_141 -> V_144 [ V_170 ] ) ? V_171 : V_172 ) ;
V_17 -> V_173 =
( V_141 -> V_144 [ V_170 ] ) ? V_8 . V_174 : V_8 . V_175 ;
V_17 -> V_176 = F_35 ;
V_17 -> V_177 = F_37 ;
V_17 -> V_178 = F_40 ;
V_17 -> V_179 = F_16 ;
V_17 -> V_180 = ( 1 << V_8 . V_9 ) - 1 ;
V_17 -> V_181 = 16 ;
V_17 -> V_182 =
F_50 ( V_8 . V_136 , V_141 -> V_144 [ V_183 ] ) ;
V_12 -> V_13 = V_141 -> V_144 [ V_184 ] ;
V_17 ++ ;
V_17 -> V_173 = V_8 . V_185 ;
if ( V_17 -> V_173 ) {
V_17 -> type = V_186 ;
V_3 -> V_187 = V_17 ;
V_17 -> V_167 = V_188 | V_189 ;
V_17 -> V_176 = F_42 ;
V_17 -> V_190 = F_43 ;
V_17 -> V_177 = F_45 ;
V_17 -> V_178 = F_47 ;
V_17 -> V_179 = F_12 ;
V_17 -> V_180 = ( 1 << V_8 . V_115 ) - 1 ;
V_17 -> V_181 = 2 ;
V_17 -> V_191 = V_12 -> V_192 ;
V_12 -> V_192 [ 0 ] =
F_51 ( V_141 -> V_144 [ V_193 ] ) ;
V_12 -> V_192 [ 1 ] =
F_51 ( V_141 -> V_144 [ V_194 ] ) ;
V_12 -> V_118 = V_141 -> V_144 [ V_195 ] ;
V_12 -> V_119 = V_141 -> V_144 [ V_196 ] ;
} else {
V_17 -> type = V_197 ;
}
V_17 ++ ;
V_17 -> type = V_198 ;
V_17 -> V_167 = V_168 | V_188 ;
V_17 -> V_173 = 16 ;
V_17 -> V_199 = F_48 ;
V_17 -> V_200 = F_49 ;
V_17 -> V_180 = 1 ;
V_17 -> V_182 = & V_201 ;
F_9 ( V_31 L_20 ) ;
return 0 ;
}
static void F_59 ( struct V_2 * V_3 )
{
if ( V_3 -> V_40 )
F_60 ( V_3 -> V_40 , V_3 ) ;
if ( V_3 -> V_49 )
F_61 ( V_3 -> V_49 , V_147 ) ;
if ( V_3 -> V_202 ) {
if ( V_12 -> V_24 [ 0 ] . V_25 )
F_62 ( V_12 -> V_24 [ 0 ] . V_25 ) ;
if ( V_12 -> V_24 [ 1 ] . V_25 )
F_62 ( V_12 -> V_24 [ 1 ] . V_25 ) ;
if ( V_12 -> V_24 [ 0 ] . V_4 )
F_63 ( ( unsigned long ) V_12 -> V_24 [ 0 ] . V_4 ) ;
if ( V_12 -> V_24 [ 1 ] . V_4 )
F_63 ( ( unsigned long ) V_12 -> V_24 [ 1 ] . V_4 ) ;
}
}
static int F_64 ( struct V_2 * V_3 )
{
F_9 ( V_31 L_21 , V_3 -> V_146 ) ;
F_59 ( V_3 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 , int V_203 , int V_204 )
{
int V_29 ;
V_12 -> V_95 = 0 ;
if ( ! V_203 && ! V_204 ) {
F_9 ( V_22 L_22 ) ;
return 0 ;
}
if ( V_203 == V_204 || V_203 < 5 || V_204 < 5 || V_203 > 7 || V_204 > 7 )
return - V_124 ;
if ( V_204 < V_203 ) {
int V_6 ;
V_6 = V_203 ;
V_203 = V_204 ;
V_204 = V_6 ;
}
V_29 = F_65 ( V_203 , L_23 ) ;
if ( V_29 )
return - V_148 ;
V_12 -> V_24 [ 0 ] . V_25 = V_203 ;
V_29 = F_65 ( V_204 , L_24 ) ;
if ( V_29 )
return - V_148 ;
V_12 -> V_24 [ 1 ] . V_25 = V_204 ;
V_12 -> V_26 = V_205 ;
V_12 -> V_24 [ 0 ] . V_4 = ( void * ) F_66 ( V_206 | V_207 ) ;
V_12 -> V_24 [ 1 ] . V_4 = ( void * ) F_66 ( V_206 | V_207 ) ;
if ( ! V_12 -> V_24 [ 0 ] . V_4 || ! V_12 -> V_24 [ 1 ] . V_4 ) {
F_9 ( V_22 L_25 ) ;
return - V_208 ;
}
F_9 ( V_31 L_26 , V_203 , V_204 ) ;
V_12 -> V_95 = 1 ;
return 0 ;
}
