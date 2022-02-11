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
V_17 -> V_25 -> V_33 |= V_34 ;
return;
}
F_9 ( V_2 , V_10 , V_20 ) ;
return;
}
static void F_10 ( struct V_1 * V_2 )
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
V_36 = F_11 ( V_17 , V_19 , V_20 ) ;
if ( V_36 != V_20 ) {
V_17 -> V_25 -> V_33 |= V_34 ;
return;
}
V_8 -> V_37 -= V_20 / 2 ;
if ( V_8 -> V_37 < 0 ) {
F_12 ( V_2 -> V_27 , L_4 ) ;
V_8 -> V_37 = 0 ;
}
if ( ! V_8 -> V_37 ) {
V_17 -> V_25 -> V_33 |= V_38 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~(DT2821_DDMA);
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR);
}
#endif
F_13 ( V_2 , V_10 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_39 , int V_14 )
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
V_41 = F_14 ( V_8 -> V_30 [ V_39 ] . V_3 ) ;
F_15 ( V_40 , V_44 ) ;
V_42 = F_16 () ;
F_17 ( V_40 ) ;
F_18 ( V_40 , V_41 ) ;
F_19 ( V_40 , V_14 ) ;
F_20 ( V_42 ) ;
F_21 ( V_40 ) ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 , int V_39 , int V_14 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
V_8 -> V_30 [ V_39 ] . V_20 = V_14 ;
V_40 = V_8 -> V_30 [ V_39 ] . V_31 ;
V_41 = F_14 ( V_8 -> V_30 [ V_39 ] . V_3 ) ;
F_15 ( V_40 , V_45 ) ;
V_42 = F_16 () ;
F_17 ( V_40 ) ;
F_18 ( V_40 , V_41 ) ;
F_19 ( V_40 , V_14 ) ;
F_20 ( V_42 ) ;
F_21 ( V_40 ) ;
return V_14 ;
}
static T_1 F_22 ( int V_46 , void * V_47 )
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
V_49 = F_23 ( V_2 -> V_23 + V_54 ) ;
V_50 = F_23 ( V_2 -> V_23 + V_55 ) ;
V_21 = F_23 ( V_2 -> V_23 + V_24 ) ;
if ( V_21 & V_56 ) {
if ( V_8 -> V_57 == V_44 )
F_10 ( V_2 ) ;
else
F_4 ( V_2 ) ;
V_51 = 1 ;
}
if ( V_49 & V_58 ) {
if ( V_8 -> V_37 != 0 ) {
F_3 ( V_2 , L_6 ) ;
V_17 -> V_25 -> V_33 |= V_59 ;
}
V_51 = 1 ;
}
if ( V_50 & V_60 ) {
F_3 ( V_2 , L_7 ) ;
V_48 -> V_25 -> V_33 |= V_59 ;
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
ret = comedi_buf_put(s, data);
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
F_24 ( V_2 , V_17 ) ;
F_24 ( V_2 , V_48 ) ;
return F_25 ( V_51 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_14 ,
unsigned int * V_61 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 ;
unsigned int V_31 , V_62 ;
F_5 ( V_63 | ( V_14 - 1 ) , V_2 -> V_23 + V_64 ) ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
V_31 = F_27 ( V_61 [ V_10 ] ) ;
V_62 = F_28 ( V_61 [ V_10 ] ) ;
F_5 ( V_8 -> V_49 | ( V_62 << 4 ) | V_31 ,
V_2 -> V_23 + V_54 ) ;
}
F_5 ( V_14 - 1 , V_2 -> V_23 + V_64 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 ,
unsigned long V_67 )
{
unsigned int V_68 ;
V_68 = F_23 ( V_2 -> V_23 + V_54 ) ;
switch ( V_67 ) {
case V_69 :
if ( ( V_68 & V_69 ) == 0 )
return 0 ;
break;
case V_70 :
if ( V_68 & V_70 )
return 0 ;
break;
default:
return - V_71 ;
}
return - V_72 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 , unsigned int * V_73 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_36 ;
int V_10 ;
V_8 -> V_49 = V_74 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
F_26 ( V_2 , 1 , & V_66 -> V_75 ) ;
F_5 ( V_8 -> V_21 | V_76 , V_2 -> V_23 + V_24 ) ;
V_36 = F_31 ( V_2 , V_17 , V_66 , F_29 , V_69 ) ;
if ( V_36 )
return V_36 ;
for ( V_10 = 0 ; V_10 < V_66 -> V_14 ; V_10 ++ ) {
F_5 ( V_8 -> V_21 | V_77 ,
V_2 -> V_23 + V_24 ) ;
V_36 = F_31 ( V_2 , V_17 , V_66 , F_29 ,
V_70 ) ;
if ( V_36 )
return V_36 ;
V_73 [ V_10 ] =
F_23 ( V_2 -> V_23 +
V_78 ) & ( ( 1 << V_6 -> V_12 ) - 1 ) ;
if ( V_8 -> V_15 )
V_73 [ V_10 ] ^= ( 1 << ( V_6 -> V_12 - 1 ) ) ;
}
return V_10 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_79 * V_80 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_81 = 0 ;
unsigned int V_82 ;
V_81 |= F_33 ( & V_80 -> V_83 , V_84 ) ;
V_81 |= F_33 ( & V_80 -> V_85 ,
V_86 | V_87 ) ;
V_81 |= F_33 ( & V_80 -> V_88 , V_89 ) ;
V_81 |= F_33 ( & V_80 -> V_90 , V_91 ) ;
V_81 |= F_33 ( & V_80 -> V_92 , V_91 | V_93 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_34 ( V_80 -> V_85 ) ;
V_81 |= F_34 ( V_80 -> V_92 ) ;
if ( V_81 )
return 2 ;
V_81 |= F_35 ( & V_80 -> V_94 , 0 ) ;
if ( V_80 -> V_85 == V_86 ) {
V_81 |= F_35 ( & V_80 -> V_95 , 0 ) ;
} else {
V_81 |= F_35 ( & V_80 -> V_95 , 0 ) ;
}
V_81 |= F_36 ( & V_80 -> V_96 , 4000 ) ;
#define F_37 (250*(1<<15)*255)
V_81 |= F_38 ( & V_80 -> V_96 , F_37 ) ;
V_81 |= F_36 ( & V_80 -> V_96 , V_6 -> V_97 ) ;
V_81 |= F_35 ( & V_80 -> V_98 , V_80 -> V_99 ) ;
if ( V_80 -> V_92 == V_91 ) {
} else {
V_81 |= F_35 ( & V_80 -> V_100 , 0 ) ;
}
if ( V_81 )
return 3 ;
V_82 = V_80 -> V_96 ;
F_39 ( & V_82 , V_80 -> V_42 & V_101 ) ;
V_81 |= F_35 ( & V_80 -> V_96 , V_82 ) ;
if ( V_81 )
return 4 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_79 * V_80 = & V_17 -> V_25 -> V_80 ;
int V_102 ;
int V_36 ;
if ( V_8 -> V_103 == 0 ) {
F_3 ( V_2 ,
L_8
L_9 ) ;
return - V_104 ;
}
F_41 ( V_2 ) ;
if ( V_80 -> V_96 < V_6 -> V_97 )
V_80 -> V_96 = V_6 -> V_97 ;
V_102 = F_39 ( & V_80 -> V_96 , V_105 ) ;
F_5 ( V_102 , V_2 -> V_23 + V_106 ) ;
if ( V_80 -> V_85 == V_86 ) {
V_8 -> V_21 = V_107 | V_108 ;
} else {
V_8 -> V_21 = V_107 | V_108 | V_109 ;
}
F_5 ( V_8 -> V_21 | V_22 | V_110 | V_111 ,
V_2 -> V_23 + V_24 ) ;
V_8 -> V_43 = V_80 -> V_100 * V_80 -> V_98 ;
V_8 -> V_37 = V_8 -> V_43 ;
V_8 -> V_57 = V_44 ;
V_8 -> V_29 = 0 ;
F_13 ( V_2 , 0 , 0 ) ;
if ( V_8 -> V_43 ) {
F_13 ( V_2 , 1 , 0 ) ;
V_8 -> V_21 |= V_112 ;
F_5 ( V_8 -> V_21 , V_2 -> V_23 + V_24 ) ;
}
V_8 -> V_49 = 0 ;
F_26 ( V_2 , V_80 -> V_99 , V_80 -> V_61 ) ;
V_8 -> V_49 = V_74 | V_113 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
F_5 ( V_8 -> V_21 | V_76 , V_2 -> V_23 + V_24 ) ;
V_36 = F_31 ( V_2 , V_17 , NULL , F_29 , V_69 ) ;
if ( V_36 )
return V_36 ;
if ( V_80 -> V_85 == V_86 ) {
F_5 ( V_8 -> V_21 | V_77 ,
V_2 -> V_23 + V_24 ) ;
} else {
V_8 -> V_21 |= V_114 ;
F_5 ( V_8 -> V_21 , V_2 -> V_23 + V_24 ) ;
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_8 -> V_103 ) {
F_7 ( V_8 -> V_30 [ 0 ] . V_31 ) ;
F_7 ( V_8 -> V_30 [ 1 ] . V_31 ) ;
}
}
static int F_42 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_41 ( V_2 ) ;
V_8 -> V_49 = 0 ;
F_5 ( V_8 -> V_49 , V_2 -> V_23 + V_54 ) ;
V_8 -> V_21 = 0 ;
F_5 ( V_8 -> V_21 | V_111 , V_2 -> V_23 + V_24 ) ;
return 0 ;
}
static int F_39 ( int * V_115 , int V_116 )
{
int V_117 , V_118 , V_119 ;
for ( V_117 = 0 ; V_117 < 16 ; V_117 ++ ) {
if ( V_117 == 1 )
continue;
V_118 = 250 * ( 1 << V_117 ) ;
switch ( V_116 ) {
case V_105 :
default:
V_119 = ( * V_115 + V_118 / 2 ) / V_118 ;
break;
case V_120 :
V_119 = ( * V_115 ) / V_118 ;
break;
case V_121 :
V_119 = ( * V_115 + V_118 - 1 ) / V_118 ;
break;
}
if ( V_119 < 256 ) {
* V_115 = V_119 * V_118 ;
return ( V_117 << 8 ) | ( 255 - V_119 ) ;
}
}
V_118 = 250 * ( 1 << 15 ) ;
V_119 = 255 ;
* V_115 = V_119 * V_118 ;
return ( 15 << 8 ) | ( 255 - V_119 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 , unsigned int * V_73 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_73 [ 0 ] = V_8 -> V_122 [ F_27 ( V_66 -> V_75 ) ] ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 , unsigned int * V_73 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned short V_47 ;
unsigned int V_31 ;
V_31 = F_27 ( V_66 -> V_75 ) ;
V_47 = V_73 [ 0 ] ;
V_47 &= ( 1 << V_6 -> V_123 ) - 1 ;
V_8 -> V_122 [ V_31 ] = V_47 ;
V_8 -> V_50 |= V_124 ;
if ( V_31 ) {
V_8 -> V_50 |= V_125 ;
if ( V_8 -> V_126 )
V_47 ^= ( 1 << ( V_6 -> V_123 - 1 ) ) ;
} else {
V_8 -> V_50 &= ~ V_125 ;
if ( V_8 -> V_127 )
V_47 ^= ( 1 << ( V_6 -> V_123 - 1 ) ) ;
}
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
F_5 ( V_47 , V_2 -> V_23 + V_128 ) ;
F_5 ( V_8 -> V_21 | V_129 , V_2 -> V_23 + V_24 ) ;
return 1 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_79 * V_80 )
{
int V_81 = 0 ;
unsigned int V_82 ;
V_81 |= F_33 ( & V_80 -> V_83 , V_130 ) ;
V_81 |= F_33 ( & V_80 -> V_85 , V_89 ) ;
V_81 |= F_33 ( & V_80 -> V_88 , V_84 ) ;
V_81 |= F_33 ( & V_80 -> V_90 , V_91 ) ;
V_81 |= F_33 ( & V_80 -> V_92 , V_91 | V_93 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_34 ( V_80 -> V_92 ) ;
if ( V_81 )
return 2 ;
V_81 |= F_35 ( & V_80 -> V_94 , 0 ) ;
V_81 |= F_36 ( & V_80 -> V_95 , 5000 ) ;
V_81 |= F_35 ( & V_80 -> V_96 , 0 ) ;
V_81 |= F_35 ( & V_80 -> V_98 , V_80 -> V_99 ) ;
if ( V_80 -> V_92 == V_91 ) {
} else {
V_81 |= F_35 ( & V_80 -> V_100 , 0 ) ;
}
if ( V_81 )
return 3 ;
V_82 = V_80 -> V_95 ;
F_39 ( & V_82 , V_80 -> V_42 & V_101 ) ;
V_81 |= F_35 ( & V_80 -> V_95 , V_82 ) ;
if ( V_81 )
return 4 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
unsigned int V_131 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_79 * V_80 = & V_17 -> V_25 -> V_80 ;
int V_20 ;
if ( V_131 != V_80 -> V_83 )
return - V_71 ;
V_20 = F_8 ( V_17 , V_8 -> V_30 [ 0 ] . V_3 ,
V_8 -> V_32 ) ;
if ( V_20 == 0 ) {
F_6 ( V_2 -> V_27 , L_3 ) ;
return - V_132 ;
}
F_9 ( V_2 , 0 , V_20 ) ;
V_20 = F_8 ( V_17 , V_8 -> V_30 [ 1 ] . V_3 ,
V_8 -> V_32 ) ;
if ( V_20 == 0 ) {
F_6 ( V_2 -> V_27 , L_3 ) ;
return - V_132 ;
}
F_9 ( V_2 , 1 , V_20 ) ;
F_5 ( V_8 -> V_21 | V_77 , V_2 -> V_23 + V_24 ) ;
V_17 -> V_25 -> V_133 = NULL ;
return 1 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_102 ;
struct V_79 * V_80 = & V_17 -> V_25 -> V_80 ;
if ( V_8 -> V_103 == 0 ) {
F_3 ( V_2 ,
L_8
L_9 ) ;
return - V_104 ;
}
F_41 ( V_2 ) ;
V_8 -> V_21 = V_107 | V_109 | V_112 ;
F_5 ( V_8 -> V_21 | V_22 | V_110 | V_134 ,
V_2 -> V_23 + V_24 ) ;
V_8 -> V_43 = V_80 -> V_100 * V_80 -> V_99 ;
V_8 -> V_37 = V_8 -> V_43 ;
V_8 -> V_57 = V_45 ;
V_8 -> V_29 = 0 ;
V_102 = F_39 ( & V_80 -> V_95 , V_105 ) ;
F_5 ( V_102 , V_2 -> V_23 + V_106 ) ;
V_8 -> V_50 = V_124 | V_135 | V_136 ;
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
V_17 -> V_25 -> V_133 = F_46 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_41 ( V_2 ) ;
V_8 -> V_50 = 0 ;
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
V_8 -> V_21 = 0 ;
F_5 ( V_8 -> V_21 | V_134 , V_2 -> V_23 + V_24 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 ,
unsigned int * V_73 )
{
if ( F_50 ( V_17 , V_73 ) )
F_5 ( V_17 -> V_137 , V_2 -> V_23 + V_138 ) ;
V_73 [ 1 ] = F_23 ( V_2 -> V_23 + V_138 ) ;
return V_66 -> V_14 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_65 * V_66 ,
unsigned int * V_73 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_31 = F_27 ( V_66 -> V_75 ) ;
unsigned int V_11 ;
int V_36 ;
if ( V_31 < 8 )
V_11 = 0x00ff ;
else
V_11 = 0xff00 ;
V_36 = F_52 ( V_2 , V_17 , V_66 , V_73 , V_11 ) ;
if ( V_36 )
return V_36 ;
V_8 -> V_50 &= ~ ( V_139 | V_140 ) ;
if ( V_17 -> V_141 & 0x00ff )
V_8 -> V_50 |= V_139 ;
if ( V_17 -> V_141 & 0xff00 )
V_8 -> V_50 |= V_140 ;
F_5 ( V_8 -> V_50 , V_2 -> V_23 + V_55 ) ;
return V_66 -> V_14 ;
}
static const struct V_142 * F_53 ( int V_143 , int V_144 )
{
if ( V_143 ) {
if ( V_144 < 0 || V_144 >= 2 )
V_144 = 0 ;
return V_145 [ V_144 ] ;
} else {
if ( V_144 < 0 || V_144 >= 4 )
V_144 = 0 ;
return V_146 [ V_144 ] ;
}
}
static const struct V_142 * F_54 ( int V_144 )
{
if ( V_144 < 0 || V_144 >= 5 )
V_144 = 0 ;
return V_147 [ V_144 ] ;
}
static int F_55 ( struct V_1 * V_2 , int V_148 , int V_149 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_36 ;
V_8 -> V_103 = 0 ;
if ( ! V_148 && ! V_149 )
return 0 ;
if ( V_148 == V_149 || V_148 < 5 || V_149 < 5 || V_148 > 7 || V_149 > 7 )
return - V_71 ;
if ( V_149 < V_148 ) {
int V_10 ;
V_10 = V_148 ;
V_148 = V_149 ;
V_149 = V_10 ;
}
V_36 = F_56 ( V_148 , L_10 ) ;
if ( V_36 )
return - V_72 ;
V_8 -> V_30 [ 0 ] . V_31 = V_148 ;
V_36 = F_56 ( V_149 , L_11 ) ;
if ( V_36 )
return - V_72 ;
V_8 -> V_30 [ 1 ] . V_31 = V_149 ;
V_8 -> V_32 = V_150 ;
V_8 -> V_30 [ 0 ] . V_3 = ( void * ) F_57 ( V_151 | V_152 ) ;
V_8 -> V_30 [ 1 ] . V_3 = ( void * ) F_57 ( V_151 | V_152 ) ;
if ( ! V_8 -> V_30 [ 0 ] . V_3 || ! V_8 -> V_30 [ 1 ] . V_3 )
return - V_153 ;
V_8 -> V_103 = 1 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_16 * V_17 ;
int V_36 ;
int V_10 ;
V_36 = F_59 ( V_2 , V_155 -> V_156 [ 0 ] , V_157 ) ;
if ( V_36 )
return V_36 ;
F_5 ( V_158 , V_2 -> V_23 + V_24 ) ;
V_10 = F_23 ( V_2 -> V_23 + V_54 ) ;
if ( ( ( F_23 ( V_2 -> V_23 + V_54 ) & V_159 )
!= V_160 ) ||
( ( F_23 ( V_2 -> V_23 + V_64 ) & V_161 )
!= V_162 ) ||
( ( F_23 ( V_2 -> V_23 + V_55 ) & V_163 )
!= V_164 ) ||
( ( F_23 ( V_2 -> V_23 + V_24 ) & V_165 )
!= V_166 ) ||
( ( F_23 ( V_2 -> V_23 + V_106 ) & V_167 )
!= V_168 ) ) {
F_6 ( V_2 -> V_27 , L_12 ) ;
return - V_104 ;
}
if ( V_155 -> V_156 [ V_169 ] > 0 ) {
V_36 = F_60 ( V_155 -> V_156 [ V_169 ] , F_22 , 0 ,
V_2 -> V_170 , V_2 ) ;
if ( V_36 == 0 )
V_2 -> V_46 = V_155 -> V_156 [ V_169 ] ;
}
V_8 = F_61 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_153 ;
if ( V_2 -> V_46 ) {
V_36 = F_55 ( V_2 , V_155 -> V_156 [ V_171 ] ,
V_155 -> V_156 [ V_172 ] ) ;
if ( V_36 < 0 )
return V_36 ;
}
V_36 = F_62 ( V_2 , 3 ) ;
if ( V_36 )
return V_36 ;
V_17 = & V_2 -> V_173 [ 0 ] ;
V_17 -> type = V_174 ;
V_17 -> V_175 = V_176 |
( ( V_155 -> V_156 [ V_177 ] ) ? V_178 : V_179 ) ;
V_17 -> V_180 =
( V_155 -> V_156 [ V_177 ] ) ? V_6 -> V_181 : V_6 -> V_182 ;
V_17 -> V_183 = F_30 ;
V_17 -> V_184 = ( 1 << V_6 -> V_12 ) - 1 ;
V_17 -> V_185 =
F_53 ( V_6 -> V_143 , V_155 -> V_156 [ V_186 ] ) ;
V_8 -> V_15 = V_155 -> V_156 [ V_187 ] ;
if ( V_2 -> V_46 ) {
V_2 -> V_35 = V_17 ;
V_17 -> V_175 |= V_188 ;
V_17 -> V_189 = 16 ;
V_17 -> V_190 = F_32 ;
V_17 -> V_191 = F_40 ;
V_17 -> V_192 = F_42 ;
}
V_17 = & V_2 -> V_173 [ 1 ] ;
V_17 -> V_180 = V_6 -> V_193 ;
if ( V_17 -> V_180 ) {
V_17 -> type = V_194 ;
V_17 -> V_175 = V_195 ;
V_17 -> V_183 = F_43 ;
V_17 -> V_196 = F_44 ;
V_17 -> V_184 = ( 1 << V_6 -> V_123 ) - 1 ;
V_17 -> V_197 = V_8 -> V_198 ;
V_8 -> V_198 [ 0 ] =
F_54 ( V_155 -> V_156 [ V_199 ] ) ;
V_8 -> V_198 [ 1 ] =
F_54 ( V_155 -> V_156 [ V_200 ] ) ;
V_8 -> V_126 = V_155 -> V_156 [ V_201 ] ;
V_8 -> V_127 = V_155 -> V_156 [ V_202 ] ;
if ( V_2 -> V_46 ) {
V_2 -> V_18 = V_17 ;
V_17 -> V_175 |= V_203 ;
V_17 -> V_189 = 2 ;
V_17 -> V_190 = F_45 ;
V_17 -> V_191 = F_47 ;
V_17 -> V_192 = F_48 ;
}
} else {
V_17 -> type = V_204 ;
}
V_17 = & V_2 -> V_173 [ 2 ] ;
V_17 -> type = V_205 ;
V_17 -> V_175 = V_176 | V_195 ;
V_17 -> V_180 = 16 ;
V_17 -> V_206 = F_49 ;
V_17 -> V_207 = F_51 ;
V_17 -> V_184 = 1 ;
V_17 -> V_185 = & V_208 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_2 -> V_9 ) {
if ( V_8 -> V_30 [ 0 ] . V_31 )
F_64 ( V_8 -> V_30 [ 0 ] . V_31 ) ;
if ( V_8 -> V_30 [ 1 ] . V_31 )
F_64 ( V_8 -> V_30 [ 1 ] . V_31 ) ;
if ( V_8 -> V_30 [ 0 ] . V_3 )
F_65 ( ( unsigned long ) V_8 -> V_30 [ 0 ] . V_3 ) ;
if ( V_8 -> V_30 [ 1 ] . V_3 )
F_65 ( ( unsigned long ) V_8 -> V_30 [ 1 ] . V_3 ) ;
}
F_66 ( V_2 ) ;
}
