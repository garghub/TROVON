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
struct V_16 * V_17 = V_2 -> V_18 ;
void * V_19 ;
int V_20 ;
int V_10 ;
F_5 ( V_8 -> V_21 | V_22 , V_2 -> V_23 + V_24 ) ;
if ( ! V_17 -> V_25 -> V_26 ) {
F_6 ( V_2 -> V_27 , L_2 , V_28 ) ;
return;
}
V_10 = V_8 -> V_29 ;
V_19 = V_8 -> V_30 [ V_10 ] . V_3 ;
F_7 ( V_8 -> V_30 [ V_10 ] . V_31 ) ;
V_8 -> V_29 = 1 - V_10 ;
V_20 = F_8 ( V_17 , V_19 , V_8 -> V_32 ) ;
if ( V_20 == 0 ) {
F_6 ( V_2 -> V_27 , L_3 ) ;
F_9 ( V_2 , V_17 ) ;
V_17 -> V_25 -> V_33 |= V_34 ;
return;
}
F_10 ( V_2 , V_10 , V_20 ) ;
return;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_16 * V_17 = V_2 -> V_35 ;
void * V_19 ;
int V_20 ;
int V_10 ;
int V_36 ;
F_5 ( V_8 -> V_21 | V_22 , V_2 -> V_23 + V_24 ) ;
if ( ! V_17 -> V_25 -> V_26 ) {
F_6 ( V_2 -> V_27 , L_2 , V_28 ) ;
return;
}
V_10 = V_8 -> V_29 ;
V_19 = V_8 -> V_30 [ V_10 ] . V_3 ;
V_20 = V_8 -> V_30 [ V_10 ] . V_20 ;
F_7 ( V_8 -> V_30 [ V_10 ] . V_31 ) ;
V_8 -> V_29 = 1 - V_10 ;
F_1 ( V_2 , V_19 , V_20 ) ;
V_36 = F_12 ( V_17 , V_19 , V_20 ) ;
if ( V_36 != V_20 ) {
F_13 ( V_2 , V_17 ) ;
return;
}
V_8 -> V_37 -= V_20 / 2 ;
if ( V_8 -> V_37 < 0 ) {
F_14 ( V_2 -> V_27 , L_4 ) ;
V_8 -> V_37 = 0 ;
}
if ( ! V_8 -> V_37 ) {
F_13 ( V_2 , V_17 ) ;
V_17 -> V_25 -> V_33 |= V_38 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR);
}
#endif
F_15 ( V_2 , V_10 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_39 , int V_14 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
if ( ! V_8 -> V_43 )
return 0 ;
if ( V_14 == 0 )
V_14 = V_8 -> V_32 ;
if ( V_14 > V_8 -> V_43 * 2 )
V_14 = V_8 -> V_43 * 2 ;
V_8 -> V_43 -= V_14 / 2 ;
V_8 -> V_30 [ V_39 ] . V_20 = V_14 ;
V_40 = V_8 -> V_30 [ V_39 ] . V_31 ;
V_41 = F_16 ( V_8 -> V_30 [ V_39 ] . V_3 ) ;
F_17 ( V_40 , V_44 ) ;
V_42 = F_18 () ;
F_19 ( V_40 ) ;
F_20 ( V_40 , V_41 ) ;
F_21 ( V_40 , V_14 ) ;
F_22 ( V_42 ) ;
F_23 ( V_40 ) ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 , int V_39 , int V_14 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
V_8 -> V_30 [ V_39 ] . V_20 = V_14 ;
V_40 = V_8 -> V_30 [ V_39 ] . V_31 ;
V_41 = F_16 ( V_8 -> V_30 [ V_39 ] . V_3 ) ;
F_17 ( V_40 , V_45 ) ;
V_42 = F_18 () ;
F_19 ( V_40 ) ;
F_20 ( V_40 , V_41 ) ;
F_21 ( V_40 , V_14 ) ;
F_22 ( V_42 ) ;
F_23 ( V_40 ) ;
return V_14 ;
}
static T_1 F_24 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_16 * V_17 = V_2 -> V_35 ;
struct V_16 * V_48 = V_2 -> V_18 ;
unsigned int V_21 , V_49 , V_50 ;
int V_51 = 0 ;
if ( ! V_2 -> V_52 ) {
F_3 ( V_2 , L_5 ) ;
return V_53 ;
}
V_49 = F_25 ( V_2 -> V_23 + V_54 ) ;
V_50 = F_25 ( V_2 -> V_23 + V_55 ) ;
V_21 = F_25 ( V_2 -> V_23 + V_24 ) ;
if ( V_21 & V_56 ) {
if ( V_8 -> V_57 == V_44 )
F_11 ( V_2 ) ;
else
F_4 ( V_2 ) ;
V_51 = 1 ;
}
if ( V_49 & V_58 ) {
if ( V_8 -> V_37 != 0 ) {
F_3 ( V_2 , L_6 ) ;
F_13 ( V_2 , V_17 ) ;
V_17 -> V_25 -> V_33 |= V_59 ;
}
V_51 = 1 ;
}
if ( V_50 & V_60 ) {
F_3 ( V_2 , L_7 ) ;
F_9 ( V_2 , V_48 ) ;
V_17 -> V_25 -> V_33 |= V_59 ;
V_51 = 1 ;
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
F_26 ( V_2 , V_17 ) ;
return F_27 ( V_51 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_14 ,
unsigned int * V_61 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
unsigned int V_31 , V_62 ;
F_5 ( V_63 | ( V_14 - 1 ) , V_2 -> V_23 + V_64 ) ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
V_31 = F_29 ( V_61 [ V_10 ] ) ;
V_62 = F_30 ( V_61 [ V_10 ] ) ;
F_5 ( V_8 -> V_49 | ( V_62 << 4 ) | V_31 ,
V_2 -> V_23 + V_54 ) ;
}
F_5 ( V_14 - 1 , V_2 -> V_23 + V_64 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 , unsigned int * V_67 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 ;
V_8 -> V_49 = V_68 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
F_28 ( V_2 , 1 , & V_66 -> V_69 ) ;
F_5 ( V_8 -> V_21 | V_70 , V_2 -> V_23 + V_24 ) ;
F_32 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
for ( V_10 = 0 ; V_10 < V_66 -> V_14 ; V_10 ++ ) {
F_5 ( V_8 -> V_21 | V_71 ,
V_2 -> V_23 + V_24 ) ;
F_32 (ad_done(), comedi_error(dev, L_8);
return -ETIME;) ;
V_67 [ V_10 ] =
F_25 ( V_2 -> V_23 +
V_72 ) & ( ( 1 << V_6 -> V_12 ) - 1 ) ;
if ( V_8 -> V_15 )
V_67 [ V_10 ] ^= ( 1 << ( V_6 -> V_12 - 1 ) ) ;
}
return V_10 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_73 * V_74 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_75 = 0 ;
int V_76 ;
V_75 |= F_34 ( & V_74 -> V_77 , V_78 ) ;
V_75 |= F_34 ( & V_74 -> V_79 ,
V_80 | V_81 ) ;
V_75 |= F_34 ( & V_74 -> V_82 , V_83 ) ;
V_75 |= F_34 ( & V_74 -> V_84 , V_85 ) ;
V_75 |= F_34 ( & V_74 -> V_86 , V_85 | V_87 ) ;
if ( V_75 )
return 1 ;
V_75 |= F_35 ( V_74 -> V_79 ) ;
V_75 |= F_35 ( V_74 -> V_86 ) ;
if ( V_75 )
return 2 ;
V_75 |= F_36 ( & V_74 -> V_88 , 0 ) ;
if ( V_74 -> V_79 == V_80 ) {
V_75 |= F_36 ( & V_74 -> V_89 , 0 ) ;
} else {
V_75 |= F_36 ( & V_74 -> V_89 , 0 ) ;
}
V_75 |= F_37 ( & V_74 -> V_90 , 4000 ) ;
#define F_38 (250*(1<<15)*255)
V_75 |= F_39 ( & V_74 -> V_90 , F_38 ) ;
V_75 |= F_37 ( & V_74 -> V_90 , V_6 -> V_91 ) ;
V_75 |= F_36 ( & V_74 -> V_92 , V_74 -> V_93 ) ;
if ( V_74 -> V_86 == V_85 ) {
} else {
V_75 |= F_36 ( & V_74 -> V_94 , 0 ) ;
}
if ( V_75 )
return 3 ;
V_76 = V_74 -> V_90 ;
F_40 ( & V_74 -> V_90 , V_74 -> V_42 & V_95 ) ;
if ( V_76 != V_74 -> V_90 )
V_75 ++ ;
if ( V_75 )
return 4 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_73 * V_74 = & V_17 -> V_25 -> V_74 ;
int V_96 ;
if ( V_8 -> V_97 == 0 ) {
F_3 ( V_2 ,
L_9
L_10 ) ;
return - V_98 ;
}
F_42 ( V_2 ) ;
if ( V_74 -> V_90 < V_6 -> V_91 )
V_74 -> V_90 = V_6 -> V_91 ;
V_96 = F_40 ( & V_74 -> V_90 , V_99 ) ;
F_5 ( V_96 , V_2 -> V_23 + V_100 ) ;
if ( V_74 -> V_79 == V_80 ) {
V_8 -> V_21 = V_101 | V_102 ;
} else {
V_8 -> V_21 = V_101 | V_102 | V_103 ;
}
F_5 ( V_8 -> V_21 | V_22 | V_104 | V_105 ,
V_2 -> V_23 + V_24 ) ;
V_8 -> V_43 = V_74 -> V_94 * V_74 -> V_92 ;
V_8 -> V_37 = V_8 -> V_43 ;
V_8 -> V_57 = V_44 ;
V_8 -> V_29 = 0 ;
F_15 ( V_2 , 0 , 0 ) ;
if ( V_8 -> V_43 ) {
F_15 ( V_2 , 1 , 0 ) ;
V_8 -> V_21 |= V_106 ;
F_5 ( V_8 -> V_21 , V_2 -> V_23 + V_24 ) ;
}
V_8 -> V_49 = 0 ;
F_28 ( V_2 , V_74 -> V_93 , V_74 -> V_61 ) ;
V_8 -> V_49 = V_68 | V_107 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
F_5 ( V_8 -> V_21 | V_70 , V_2 -> V_23 + V_24 ) ;
F_32 (!mux_busy(), comedi_error(dev, L_8); return -ETIME;) ;
if ( V_74 -> V_79 == V_80 ) {
F_5 ( V_8 -> V_21 | V_71 ,
V_2 -> V_23 + V_24 ) ;
} else {
V_8 -> V_21 |= V_108 ;
F_5 ( V_8 -> V_21 , V_2 -> V_23 + V_24 ) ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_97 ) {
F_7 ( V_8 -> V_30 [ 0 ] . V_31 ) ;
F_7 ( V_8 -> V_30 [ 1 ] . V_31 ) ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_42 ( V_2 ) ;
V_8 -> V_49 = 0 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
V_8 -> V_21 = 0 ;
F_5 ( V_8 -> V_21 | V_105 , V_2 -> V_23 + V_24 ) ;
return 0 ;
}
static int F_40 ( int * V_109 , int V_110 )
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
static int F_43 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 , unsigned int * V_67 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_67 [ 0 ] = V_8 -> V_116 [ F_29 ( V_66 -> V_69 ) ] ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 , unsigned int * V_67 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned short V_47 ;
unsigned int V_31 ;
V_31 = F_29 ( V_66 -> V_69 ) ;
V_47 = V_67 [ 0 ] ;
V_47 &= ( 1 << V_6 -> V_117 ) - 1 ;
V_8 -> V_116 [ V_31 ] = V_47 ;
V_8 -> V_50 |= V_118 ;
if ( V_31 ) {
V_8 -> V_50 |= V_119 ;
if ( V_8 -> V_120 )
V_47 ^= ( 1 << ( V_6 -> V_117 - 1 ) ) ;
} else {
V_8 -> V_50 &= ~ V_119 ;
if ( V_8 -> V_121 )
V_47 ^= ( 1 << ( V_6 -> V_117 - 1 ) ) ;
}
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
F_5 ( V_47 , V_2 -> V_23 + V_122 ) ;
F_5 ( V_8 -> V_21 | V_123 , V_2 -> V_23 + V_24 ) ;
return 1 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_73 * V_74 )
{
int V_75 = 0 ;
int V_76 ;
V_75 |= F_34 ( & V_74 -> V_77 , V_124 ) ;
V_75 |= F_34 ( & V_74 -> V_79 , V_83 ) ;
V_75 |= F_34 ( & V_74 -> V_82 , V_78 ) ;
V_75 |= F_34 ( & V_74 -> V_84 , V_85 ) ;
V_75 |= F_34 ( & V_74 -> V_86 , V_85 | V_87 ) ;
if ( V_75 )
return 1 ;
V_75 |= F_35 ( V_74 -> V_86 ) ;
if ( V_75 )
return 2 ;
V_75 |= F_36 ( & V_74 -> V_88 , 0 ) ;
V_75 |= F_37 ( & V_74 -> V_89 , 5000 ) ;
V_75 |= F_36 ( & V_74 -> V_90 , 0 ) ;
V_75 |= F_39 ( & V_74 -> V_92 , 2 ) ;
if ( V_74 -> V_86 == V_85 ) {
} else {
V_75 |= F_36 ( & V_74 -> V_94 , 0 ) ;
}
if ( V_75 )
return 3 ;
V_76 = V_74 -> V_89 ;
F_40 ( & V_74 -> V_89 , V_74 -> V_42 & V_95 ) ;
if ( V_76 != V_74 -> V_89 )
V_75 ++ ;
if ( V_75 )
return 4 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_16 * V_17 , unsigned int V_125 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_20 ;
if ( V_125 != 0 )
return - V_126 ;
V_20 = F_8 ( V_17 , V_8 -> V_30 [ 0 ] . V_3 ,
V_8 -> V_32 ) ;
if ( V_20 == 0 ) {
F_6 ( V_2 -> V_27 , L_3 ) ;
return - V_127 ;
}
F_10 ( V_2 , 0 , V_20 ) ;
V_20 = F_8 ( V_17 , V_8 -> V_30 [ 1 ] . V_3 ,
V_8 -> V_32 ) ;
if ( V_20 == 0 ) {
F_6 ( V_2 -> V_27 , L_3 ) ;
return - V_127 ;
}
F_10 ( V_2 , 1 , V_20 ) ;
F_5 ( V_8 -> V_21 | V_71 , V_2 -> V_23 + V_24 ) ;
V_17 -> V_25 -> V_128 = NULL ;
return 1 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_96 ;
struct V_73 * V_74 = & V_17 -> V_25 -> V_74 ;
if ( V_8 -> V_97 == 0 ) {
F_3 ( V_2 ,
L_9
L_10 ) ;
return - V_98 ;
}
F_42 ( V_2 ) ;
V_8 -> V_21 = V_101 | V_103 | V_106 ;
F_5 ( V_8 -> V_21 | V_22 | V_104 | V_129 ,
V_2 -> V_23 + V_24 ) ;
V_8 -> V_43 = V_74 -> V_94 * V_74 -> V_93 ;
V_8 -> V_37 = V_8 -> V_43 ;
V_8 -> V_57 = V_45 ;
V_8 -> V_29 = 0 ;
V_96 = F_40 ( & V_74 -> V_89 , V_99 ) ;
F_5 ( V_96 , V_2 -> V_23 + V_100 ) ;
V_8 -> V_50 = V_118 | V_130 | V_131 ;
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
V_17 -> V_25 -> V_128 = F_46 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_42 ( V_2 ) ;
V_8 -> V_50 = 0 ;
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
V_8 -> V_21 = 0 ;
F_5 ( V_8 -> V_21 | V_129 , V_2 -> V_23 + V_24 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
if ( F_49 ( V_17 , V_67 ) )
F_5 ( V_17 -> V_132 , V_2 -> V_23 + V_133 ) ;
V_67 [ 1 ] = F_25 ( V_2 -> V_23 + V_133 ) ;
return V_66 -> V_14 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_31 = F_29 ( V_66 -> V_69 ) ;
unsigned int V_11 ;
int V_36 ;
if ( V_31 < 8 )
V_11 = 0x00ff ;
else
V_11 = 0xff00 ;
V_36 = F_51 ( V_2 , V_17 , V_66 , V_67 , V_11 ) ;
if ( V_36 )
return V_36 ;
V_8 -> V_50 &= ~ ( V_134 | V_135 ) ;
if ( V_17 -> V_136 & 0x00ff )
V_8 -> V_50 |= V_134 ;
if ( V_17 -> V_136 & 0xff00 )
V_8 -> V_50 |= V_135 ;
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
return V_66 -> V_14 ;
}
static const struct V_137 * F_52 ( int V_138 , int V_125 )
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
static const struct V_137 * F_53 ( int V_125 )
{
if ( V_125 < 0 || V_125 >= 5 )
V_125 = 0 ;
return V_141 [ V_125 ] ;
}
static int F_54 ( struct V_1 * V_2 , int V_142 , int V_143 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_36 ;
V_8 -> V_97 = 0 ;
if ( ! V_142 && ! V_143 )
return 0 ;
if ( V_142 == V_143 || V_142 < 5 || V_143 < 5 || V_142 > 7 || V_143 > 7 )
return - V_126 ;
if ( V_143 < V_142 ) {
int V_10 ;
V_10 = V_142 ;
V_142 = V_143 ;
V_143 = V_10 ;
}
V_36 = F_55 ( V_142 , L_11 ) ;
if ( V_36 )
return - V_144 ;
V_8 -> V_30 [ 0 ] . V_31 = V_142 ;
V_36 = F_55 ( V_143 , L_12 ) ;
if ( V_36 )
return - V_144 ;
V_8 -> V_30 [ 1 ] . V_31 = V_143 ;
V_8 -> V_32 = V_145 ;
V_8 -> V_30 [ 0 ] . V_3 = ( void * ) F_56 ( V_146 | V_147 ) ;
V_8 -> V_30 [ 1 ] . V_3 = ( void * ) F_56 ( V_146 | V_147 ) ;
if ( ! V_8 -> V_30 [ 0 ] . V_3 || ! V_8 -> V_30 [ 1 ] . V_3 )
return - V_148 ;
V_8 -> V_97 = 1 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_149 * V_150 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_16 * V_17 ;
int V_36 ;
int V_10 ;
V_36 = F_58 ( V_2 , V_150 -> V_151 [ 0 ] , V_152 ) ;
if ( V_36 )
return V_36 ;
F_5 ( V_153 , V_2 -> V_23 + V_24 ) ;
V_10 = F_25 ( V_2 -> V_23 + V_54 ) ;
if ( ( ( F_25 ( V_2 -> V_23 + V_54 ) & V_154 )
!= V_155 ) ||
( ( F_25 ( V_2 -> V_23 + V_64 ) & V_156 )
!= V_157 ) ||
( ( F_25 ( V_2 -> V_23 + V_55 ) & V_158 )
!= V_159 ) ||
( ( F_25 ( V_2 -> V_23 + V_24 ) & V_160 )
!= V_161 ) ||
( ( F_25 ( V_2 -> V_23 + V_100 ) & V_162 )
!= V_163 ) ) {
F_6 ( V_2 -> V_27 , L_13 ) ;
return - V_98 ;
}
if ( V_150 -> V_151 [ V_164 ] > 0 ) {
V_36 = F_59 ( V_150 -> V_151 [ V_164 ] , F_24 , 0 ,
V_2 -> V_165 , V_2 ) ;
if ( V_36 == 0 )
V_2 -> V_46 = V_150 -> V_151 [ V_164 ] ;
}
V_8 = F_60 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_148 ;
if ( V_2 -> V_46 ) {
V_36 = F_54 ( V_2 , V_150 -> V_151 [ V_166 ] ,
V_150 -> V_151 [ V_167 ] ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_36 = F_61 ( V_2 , 3 ) ;
if ( V_36 )
return V_36 ;
V_17 = & V_2 -> V_168 [ 0 ] ;
V_17 -> type = V_169 ;
V_17 -> V_170 = V_171 |
( ( V_150 -> V_151 [ V_172 ] ) ? V_173 : V_174 ) ;
V_17 -> V_175 =
( V_150 -> V_151 [ V_172 ] ) ? V_6 -> V_176 : V_6 -> V_177 ;
V_17 -> V_178 = F_31 ;
V_17 -> V_179 = ( 1 << V_6 -> V_12 ) - 1 ;
V_17 -> V_180 =
F_52 ( V_6 -> V_138 , V_150 -> V_151 [ V_181 ] ) ;
V_8 -> V_15 = V_150 -> V_151 [ V_182 ] ;
if ( V_2 -> V_46 ) {
V_2 -> V_35 = V_17 ;
V_17 -> V_170 |= V_183 ;
V_17 -> V_184 = 16 ;
V_17 -> V_185 = F_33 ;
V_17 -> V_186 = F_41 ;
V_17 -> V_187 = F_13 ;
}
V_17 = & V_2 -> V_168 [ 1 ] ;
V_17 -> V_175 = V_6 -> V_188 ;
if ( V_17 -> V_175 ) {
V_17 -> type = V_189 ;
V_17 -> V_170 = V_190 ;
V_17 -> V_178 = F_43 ;
V_17 -> V_191 = F_44 ;
V_17 -> V_179 = ( 1 << V_6 -> V_117 ) - 1 ;
V_17 -> V_192 = V_8 -> V_193 ;
V_8 -> V_193 [ 0 ] =
F_53 ( V_150 -> V_151 [ V_194 ] ) ;
V_8 -> V_193 [ 1 ] =
F_53 ( V_150 -> V_151 [ V_195 ] ) ;
V_8 -> V_120 = V_150 -> V_151 [ V_196 ] ;
V_8 -> V_121 = V_150 -> V_151 [ V_197 ] ;
if ( V_2 -> V_46 ) {
V_2 -> V_18 = V_17 ;
V_17 -> V_170 |= V_198 ;
V_17 -> V_184 = 2 ;
V_17 -> V_185 = F_45 ;
V_17 -> V_186 = F_47 ;
V_17 -> V_187 = F_9 ;
}
} else {
V_17 -> type = V_199 ;
}
V_17 = & V_2 -> V_168 [ 2 ] ;
V_17 -> type = V_200 ;
V_17 -> V_170 = V_171 | V_190 ;
V_17 -> V_175 = 16 ;
V_17 -> V_201 = F_48 ;
V_17 -> V_202 = F_50 ;
V_17 -> V_179 = 1 ;
V_17 -> V_180 = & V_203 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_2 -> V_9 ) {
if ( V_8 -> V_30 [ 0 ] . V_31 )
F_63 ( V_8 -> V_30 [ 0 ] . V_31 ) ;
if ( V_8 -> V_30 [ 1 ] . V_31 )
F_63 ( V_8 -> V_30 [ 1 ] . V_31 ) ;
if ( V_8 -> V_30 [ 0 ] . V_3 )
F_64 ( ( unsigned long ) V_8 -> V_30 [ 0 ] . V_3 ) ;
if ( V_8 -> V_30 [ 1 ] . V_3 )
F_64 ( ( unsigned long ) V_8 -> V_30 [ 1 ] . V_3 ) ;
}
F_65 ( V_2 ) ;
}
