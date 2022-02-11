static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
if ( ! V_6 -> V_11 )
return 0 ;
if ( V_4 == 0 )
V_4 = V_6 -> V_12 ;
if ( V_4 > V_6 -> V_11 * 2 )
V_4 = V_6 -> V_11 * 2 ;
V_6 -> V_11 -= V_4 / 2 ;
V_6 -> V_13 [ V_3 ] . V_14 = V_4 ;
V_8 = V_6 -> V_13 [ V_3 ] . V_15 ;
V_9 = F_2 ( V_6 -> V_13 [ V_3 ] . V_16 ) ;
F_3 ( V_8 , V_17 ) ;
V_10 = F_4 () ;
F_5 ( V_8 ) ;
F_6 ( V_8 , V_9 ) ;
F_7 ( V_8 , V_4 ) ;
F_8 ( V_10 ) ;
F_9 ( V_8 ) ;
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
V_6 -> V_13 [ V_3 ] . V_14 = V_4 ;
V_8 = V_6 -> V_13 [ V_3 ] . V_15 ;
V_9 = F_2 ( V_6 -> V_13 [ V_3 ] . V_16 ) ;
F_3 ( V_8 , V_18 ) ;
V_10 = F_4 () ;
F_5 ( V_8 ) ;
F_6 ( V_8 , V_9 ) ;
F_7 ( V_8 , V_4 ) ;
F_8 ( V_10 ) ;
F_9 ( V_8 ) ;
return V_4 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_12 ( V_6 -> V_13 [ 0 ] . V_15 ) ;
F_12 ( V_6 -> V_13 [ 1 ] . V_15 ) ;
}
static unsigned int F_13 ( unsigned int * V_19 , unsigned int V_10 )
{
unsigned int V_20 , V_21 , V_22 ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ ) {
if ( V_20 == 1 )
continue;
V_21 = 250 * ( 1 << V_20 ) ;
switch ( V_10 & V_23 ) {
case V_24 :
default:
V_22 = ( * V_19 + V_21 / 2 ) / V_21 ;
break;
case V_25 :
V_22 = ( * V_19 ) / V_21 ;
break;
case V_26 :
V_22 = ( * V_19 + V_21 - 1 ) / V_21 ;
break;
}
if ( V_22 < 256 ) {
* V_19 = V_22 * V_21 ;
return ( V_20 << 8 ) | ( 255 - V_22 ) ;
}
}
V_21 = 250 * ( 1 << 15 ) ;
V_22 = 255 ;
* V_19 = V_22 * V_21 ;
return ( 15 << 8 ) | ( 255 - V_22 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned short * V_16 ,
unsigned int V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_30 ;
int V_31 ;
if ( V_29 % 2 )
F_15 ( V_2 -> V_32 ,
L_1 ) ;
for ( V_31 = 0 ; V_31 < V_29 / 2 ; V_31 ++ ) {
V_30 = V_16 [ V_31 ] ;
V_30 &= V_28 -> V_33 ;
if ( V_6 -> V_34 )
V_30 = F_16 ( V_28 , V_30 ) ;
V_16 [ V_31 ] = V_30 ;
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_35 = V_6 -> V_36 ;
void * V_37 = V_6 -> V_13 [ V_35 ] . V_16 ;
int V_14 ;
F_18 ( V_6 -> V_38 | V_39 ,
V_2 -> V_40 + V_41 ) ;
F_12 ( V_6 -> V_13 [ V_35 ] . V_15 ) ;
V_6 -> V_36 = 1 - V_35 ;
V_14 = F_19 ( V_28 , V_37 , V_6 -> V_12 ) ;
if ( V_14 == 0 ) {
F_15 ( V_2 -> V_32 , L_2 ) ;
V_28 -> V_42 -> V_43 |= V_44 ;
} else {
F_10 ( V_2 , V_35 , V_14 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_35 = V_6 -> V_36 ;
void * V_37 = V_6 -> V_13 [ V_35 ] . V_16 ;
int V_14 = V_6 -> V_13 [ V_35 ] . V_14 ;
int V_45 ;
F_18 ( V_6 -> V_38 | V_39 ,
V_2 -> V_40 + V_41 ) ;
F_12 ( V_6 -> V_13 [ V_35 ] . V_15 ) ;
V_6 -> V_36 = 1 - V_35 ;
F_14 ( V_2 , V_28 , V_37 , V_14 ) ;
V_45 = F_21 ( V_28 , V_37 , V_14 ) ;
if ( V_45 != V_14 ) {
V_28 -> V_42 -> V_43 |= V_44 ;
return;
}
V_6 -> V_46 -= V_14 / 2 ;
if ( V_6 -> V_46 < 0 ) {
F_22 ( V_2 -> V_32 , L_3 ) ;
V_6 -> V_46 = 0 ;
}
if ( ! V_6 -> V_46 ) {
V_28 -> V_42 -> V_43 |= V_47 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~DT2821_SUPCSR_DDMA;
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR_REG);
}
#endif
F_1 ( V_2 , V_35 , 0 ) ;
}
static T_1 F_23 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_27 * V_28 = V_2 -> V_50 ;
struct V_27 * V_51 = V_2 -> V_52 ;
unsigned int V_38 , V_53 , V_54 ;
int V_55 = 0 ;
if ( ! V_2 -> V_56 ) {
F_15 ( V_2 -> V_32 , L_4 ) ;
return V_57 ;
}
V_53 = F_24 ( V_2 -> V_40 + V_58 ) ;
V_54 = F_24 ( V_2 -> V_40 + V_59 ) ;
V_38 = F_24 ( V_2 -> V_40 + V_41 ) ;
if ( V_38 & V_60 ) {
if ( V_6 -> V_61 == V_17 )
F_20 ( V_2 , V_28 ) ;
else
F_17 ( V_2 , V_51 ) ;
V_55 = 1 ;
}
if ( V_53 & V_62 ) {
if ( V_6 -> V_46 != 0 ) {
F_15 ( V_2 -> V_32 , L_5 ) ;
V_28 -> V_42 -> V_43 |= V_63 ;
}
V_55 = 1 ;
}
if ( V_54 & V_64 ) {
F_15 ( V_2 -> V_32 , L_6 ) ;
V_51 -> V_42 -> V_43 |= V_63 ;
V_55 = 1 ;
}
#if 0
if (adcsr & DT2821_ADCSR_ADDONE) {
int ret;
unsigned short data;
data = inw(dev->iobase + DT2821_ADDAT_REG);
data &= s->maxdata;
if (devpriv->ad_2scomp)
data = comedi_offset_munge(s, data);
ret = comedi_buf_put(s, data);
if (ret == 0)
s->async->events |= COMEDI_CB_OVERFLOW;
devpriv->nread--;
if (!devpriv->nread) {
s->async->events |= COMEDI_CB_EOA;
} else {
if (supcsr & DT2821_SUPCSR_SCDN)
outw(devpriv->supcsr | DT2821_SUPCSR_STRIG,
dev->iobase + DT2821_SUPCSR_REG);
}
handled = 1;
}
#endif
F_25 ( V_2 , V_28 ) ;
F_25 ( V_2 , V_51 ) ;
return F_26 ( V_55 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_4 ,
unsigned int * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_31 ;
F_18 ( V_66 | F_28 ( V_4 ) ,
V_2 -> V_40 + V_67 ) ;
for ( V_31 = 0 ; V_31 < V_4 ; V_31 ++ ) {
unsigned int V_15 = F_29 ( V_65 [ V_31 ] ) ;
unsigned int V_68 = F_30 ( V_65 [ V_31 ] ) ;
F_18 ( V_6 -> V_53 |
F_31 ( V_68 ) |
F_32 ( V_15 ) ,
V_2 -> V_40 + V_58 ) ;
}
F_18 ( F_28 ( V_4 ) , V_2 -> V_40 + V_67 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned long V_71 )
{
unsigned int V_72 ;
V_72 = F_24 ( V_2 -> V_40 + V_58 ) ;
switch ( V_71 ) {
case V_73 :
if ( ( V_72 & V_73 ) == 0 )
return 0 ;
break;
case V_74 :
if ( V_72 & V_74 )
return 0 ;
break;
default:
return - V_75 ;
}
return - V_76 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_30 ;
int V_45 ;
int V_31 ;
V_6 -> V_53 = V_78 ;
F_18 ( V_6 -> V_53 , V_2 -> V_40 + V_58 ) ;
F_27 ( V_2 , 1 , & V_70 -> V_79 ) ;
F_18 ( V_6 -> V_38 | V_80 ,
V_2 -> V_40 + V_41 ) ;
V_45 = F_35 ( V_2 , V_28 , V_70 ,
F_33 , V_73 ) ;
if ( V_45 )
return V_45 ;
for ( V_31 = 0 ; V_31 < V_70 -> V_4 ; V_31 ++ ) {
F_18 ( V_6 -> V_38 | V_81 ,
V_2 -> V_40 + V_41 ) ;
V_45 = F_35 ( V_2 , V_28 , V_70 ,
F_33 , V_74 ) ;
if ( V_45 )
return V_45 ;
V_30 = F_24 ( V_2 -> V_40 + V_82 ) ;
V_30 &= V_28 -> V_33 ;
if ( V_6 -> V_34 )
V_30 = F_16 ( V_28 , V_30 ) ;
V_77 [ V_31 ] = V_30 ;
}
return V_31 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_83 * V_84 )
{
const struct V_85 * V_86 = F_37 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_87 = 0 ;
unsigned int V_88 ;
V_87 |= F_38 ( & V_84 -> V_89 , V_90 ) ;
V_87 |= F_38 ( & V_84 -> V_91 ,
V_92 | V_93 ) ;
V_87 |= F_38 ( & V_84 -> V_94 , V_95 ) ;
V_87 |= F_38 ( & V_84 -> V_96 , V_97 ) ;
V_87 |= F_38 ( & V_84 -> V_98 , V_97 | V_99 ) ;
if ( V_87 )
return 1 ;
V_87 |= F_39 ( V_84 -> V_91 ) ;
V_87 |= F_39 ( V_84 -> V_98 ) ;
if ( V_87 )
return 2 ;
V_87 |= F_40 ( & V_84 -> V_100 , 0 ) ;
if ( V_84 -> V_91 == V_92 ) {
V_87 |= F_40 ( & V_84 -> V_101 , 0 ) ;
} else {
V_87 |= F_40 ( & V_84 -> V_101 , 0 ) ;
}
V_87 |= F_41 ( & V_84 -> V_102 , 4000 ) ;
#define F_42 (250*(1<<15)*255)
V_87 |= F_43 ( & V_84 -> V_102 , F_42 ) ;
V_87 |= F_41 ( & V_84 -> V_102 , V_86 -> V_103 ) ;
V_87 |= F_40 ( & V_84 -> V_104 , V_84 -> V_105 ) ;
if ( V_84 -> V_98 == V_97 ) {
} else {
V_87 |= F_40 ( & V_84 -> V_106 , 0 ) ;
}
if ( V_87 )
return 3 ;
V_88 = V_84 -> V_102 ;
V_6 -> V_107 = F_13 ( & V_88 , V_84 -> V_10 ) ;
V_87 |= F_40 ( & V_84 -> V_102 , V_88 ) ;
if ( V_87 )
return 4 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_83 * V_84 = & V_28 -> V_42 -> V_84 ;
int V_45 ;
F_11 ( V_2 ) ;
F_18 ( V_6 -> V_107 , V_2 -> V_40 + V_108 ) ;
V_6 -> V_38 = V_109 ;
if ( V_84 -> V_91 == V_92 )
V_6 -> V_38 = V_110 ;
else
V_6 -> V_38 = V_111 ;
F_18 ( V_6 -> V_38 |
V_39 |
V_112 |
V_113 ,
V_2 -> V_40 + V_41 ) ;
V_6 -> V_11 = V_84 -> V_106 * V_84 -> V_104 ;
V_6 -> V_46 = V_6 -> V_11 ;
V_6 -> V_61 = V_17 ;
V_6 -> V_36 = 0 ;
F_1 ( V_2 , 0 , 0 ) ;
if ( V_6 -> V_11 ) {
F_1 ( V_2 , 1 , 0 ) ;
V_6 -> V_38 |= V_114 ;
F_18 ( V_6 -> V_38 , V_2 -> V_40 + V_41 ) ;
}
V_6 -> V_53 = 0 ;
F_27 ( V_2 , V_84 -> V_105 , V_84 -> V_65 ) ;
V_6 -> V_53 = V_78 | V_115 ;
F_18 ( V_6 -> V_53 , V_2 -> V_40 + V_58 ) ;
F_18 ( V_6 -> V_38 | V_80 ,
V_2 -> V_40 + V_41 ) ;
V_45 = F_35 ( V_2 , V_28 , NULL ,
F_33 , V_73 ) ;
if ( V_45 )
return V_45 ;
if ( V_84 -> V_91 == V_92 ) {
F_18 ( V_6 -> V_38 | V_81 ,
V_2 -> V_40 + V_41 ) ;
} else {
V_6 -> V_38 |= V_116 ;
F_18 ( V_6 -> V_38 , V_2 -> V_40 + V_41 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_11 ( V_2 ) ;
V_6 -> V_53 = 0 ;
F_18 ( V_6 -> V_53 , V_2 -> V_40 + V_58 ) ;
V_6 -> V_38 = 0 ;
F_18 ( V_6 -> V_38 | V_113 ,
V_2 -> V_40 + V_41 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_15 = F_29 ( V_70 -> V_79 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_70 -> V_4 ; V_31 ++ )
V_77 [ V_31 ] = V_6 -> V_117 [ V_15 ] ;
return V_70 -> V_4 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_15 = F_29 ( V_70 -> V_79 ) ;
unsigned int V_68 = F_30 ( V_70 -> V_79 ) ;
unsigned int V_30 ;
int V_31 ;
V_6 -> V_54 |= V_118 | F_48 ( V_15 ) ;
for ( V_31 = 0 ; V_31 < V_70 -> V_4 ; V_31 ++ ) {
V_30 = V_77 [ V_31 ] ;
V_6 -> V_117 [ V_15 ] = V_30 ;
if ( F_49 ( V_28 , V_68 ) )
V_30 = F_16 ( V_28 , V_30 ) ;
F_18 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
F_18 ( V_30 , V_2 -> V_40 + V_119 ) ;
F_18 ( V_6 -> V_38 | V_120 ,
V_2 -> V_40 + V_41 ) ;
}
return V_70 -> V_4 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_87 = 0 ;
unsigned int V_88 ;
V_87 |= F_38 ( & V_84 -> V_89 , V_121 ) ;
V_87 |= F_38 ( & V_84 -> V_91 , V_95 ) ;
V_87 |= F_38 ( & V_84 -> V_94 , V_90 ) ;
V_87 |= F_38 ( & V_84 -> V_96 , V_97 ) ;
V_87 |= F_38 ( & V_84 -> V_98 , V_97 | V_99 ) ;
if ( V_87 )
return 1 ;
V_87 |= F_39 ( V_84 -> V_98 ) ;
if ( V_87 )
return 2 ;
V_87 |= F_40 ( & V_84 -> V_100 , 0 ) ;
V_87 |= F_41 ( & V_84 -> V_101 , 5000 ) ;
V_87 |= F_40 ( & V_84 -> V_102 , 0 ) ;
V_87 |= F_40 ( & V_84 -> V_104 , V_84 -> V_105 ) ;
if ( V_84 -> V_98 == V_97 ) {
} else {
V_87 |= F_40 ( & V_84 -> V_106 , 0 ) ;
}
if ( V_87 )
return 3 ;
V_88 = V_84 -> V_101 ;
V_6 -> V_107 = F_13 ( & V_88 , V_84 -> V_10 ) ;
V_87 |= F_40 ( & V_84 -> V_101 , V_88 ) ;
if ( V_87 )
return 4 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned int V_122 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_83 * V_84 = & V_28 -> V_42 -> V_84 ;
int V_14 ;
if ( V_122 != V_84 -> V_89 )
return - V_75 ;
V_14 = F_19 ( V_28 , V_6 -> V_13 [ 0 ] . V_16 ,
V_6 -> V_12 ) ;
if ( V_14 == 0 ) {
F_15 ( V_2 -> V_32 , L_2 ) ;
return - V_123 ;
}
F_10 ( V_2 , 0 , V_14 ) ;
V_14 = F_19 ( V_28 , V_6 -> V_13 [ 1 ] . V_16 ,
V_6 -> V_12 ) ;
if ( V_14 == 0 ) {
F_15 ( V_2 -> V_32 , L_2 ) ;
return - V_123 ;
}
F_10 ( V_2 , 1 , V_14 ) ;
F_18 ( V_6 -> V_38 | V_81 ,
V_2 -> V_40 + V_41 ) ;
V_28 -> V_42 -> V_124 = NULL ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_83 * V_84 = & V_28 -> V_42 -> V_84 ;
F_11 ( V_2 ) ;
V_6 -> V_38 = V_109 |
V_125 |
V_114 ;
F_18 ( V_6 -> V_38 |
V_39 |
V_112 |
V_126 ,
V_2 -> V_40 + V_41 ) ;
V_6 -> V_11 = V_84 -> V_106 * V_84 -> V_105 ;
V_6 -> V_46 = V_6 -> V_11 ;
V_6 -> V_61 = V_18 ;
V_6 -> V_36 = 0 ;
F_18 ( V_6 -> V_107 , V_2 -> V_40 + V_108 ) ;
V_6 -> V_54 &= ( V_127 | V_128 ) ;
V_6 -> V_54 |= ( V_118 |
V_129 |
V_130 ) ;
F_18 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
V_28 -> V_42 -> V_124 = F_51 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_11 ( V_2 ) ;
V_6 -> V_54 &= ( V_127 | V_128 ) ;
F_18 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
V_6 -> V_38 = 0 ;
F_18 ( V_6 -> V_38 | V_126 ,
V_2 -> V_40 + V_41 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
if ( F_55 ( V_28 , V_77 ) )
F_18 ( V_28 -> V_131 , V_2 -> V_40 + V_132 ) ;
V_77 [ 1 ] = F_24 ( V_2 -> V_40 + V_132 ) ;
return V_70 -> V_4 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_15 = F_29 ( V_70 -> V_79 ) ;
unsigned int V_133 ;
int V_45 ;
if ( V_15 < 8 )
V_133 = 0x00ff ;
else
V_133 = 0xff00 ;
V_45 = F_57 ( V_2 , V_28 , V_70 , V_77 , V_133 ) ;
if ( V_45 )
return V_45 ;
V_6 -> V_54 &= ~ ( V_127 | V_128 ) ;
if ( V_28 -> V_134 & 0x00ff )
V_6 -> V_54 |= V_127 ;
if ( V_28 -> V_134 & 0xff00 )
V_6 -> V_54 |= V_128 ;
F_18 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
return V_70 -> V_4 ;
}
static const struct V_135 * F_58 ( int V_136 , int V_137 )
{
if ( V_136 ) {
if ( V_137 < 0 || V_137 >= 2 )
V_137 = 0 ;
return V_138 [ V_137 ] ;
}
if ( V_137 < 0 || V_137 >= 4 )
V_137 = 0 ;
return V_139 [ V_137 ] ;
}
static int F_59 ( struct V_1 * V_2 , int V_140 , int V_141 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_45 ;
V_45 = F_60 ( V_140 , L_7 ) ;
if ( V_45 )
return - V_76 ;
V_6 -> V_13 [ 0 ] . V_15 = V_140 ;
V_45 = F_60 ( V_141 , L_8 ) ;
if ( V_45 )
return - V_76 ;
V_6 -> V_13 [ 1 ] . V_15 = V_141 ;
V_6 -> V_12 = V_142 ;
V_6 -> V_13 [ 0 ] . V_16 = ( void * ) F_61 ( V_143 | V_144 ) ;
V_6 -> V_13 [ 1 ] . V_16 = ( void * ) F_61 ( V_143 | V_144 ) ;
if ( ! V_6 -> V_13 [ 0 ] . V_16 || ! V_6 -> V_13 [ 1 ] . V_16 )
return - V_145 ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_31 ;
if ( ! V_6 )
return;
for ( V_31 = 0 ; V_31 < 2 ; V_31 ++ ) {
if ( V_6 -> V_13 [ V_31 ] . V_15 )
F_63 ( V_6 -> V_13 [ V_31 ] . V_15 ) ;
if ( V_6 -> V_13 [ V_31 ] . V_16 )
F_64 ( ( unsigned long ) V_6 -> V_13 [ V_31 ] . V_16 ) ;
V_6 -> V_13 [ V_31 ] . V_15 = 0 ;
V_6 -> V_13 [ V_31 ] . V_16 = NULL ;
}
}
static int F_65 ( struct V_1 * V_2 )
{
F_18 ( V_146 , V_2 -> V_40 + V_41 ) ;
F_24 ( V_2 -> V_40 + V_58 ) ;
if ( ( ( F_24 ( V_2 -> V_40 + V_58 ) & 0xfff0 ) != 0x7c00 ) ||
( ( F_24 ( V_2 -> V_40 + V_67 ) & 0xf0f0 ) != 0x70f0 ) ||
( ( F_24 ( V_2 -> V_40 + V_59 ) & 0x7c93 ) != 0x7c90 ) ||
( ( F_24 ( V_2 -> V_40 + V_41 ) & 0xf8ff ) != 0x0000 ) ||
( ( F_24 ( V_2 -> V_40 + V_108 ) & 0xff00 ) != 0xf000 ) ) {
F_15 ( V_2 -> V_32 , L_9 ) ;
return - V_147 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
const struct V_85 * V_86 = F_37 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_27 * V_28 ;
int V_45 ;
V_45 = F_67 ( V_2 , V_149 -> V_150 [ 0 ] , 0x10 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_65 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_6 = F_68 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_145 ;
if ( V_149 -> V_150 [ 1 ] && V_149 -> V_150 [ 2 ] && V_149 -> V_150 [ 3 ] ) {
unsigned int V_48 = V_149 -> V_150 [ 1 ] ;
unsigned int V_140 = V_149 -> V_150 [ 2 ] ;
unsigned int V_141 = V_149 -> V_150 [ 3 ] ;
if ( V_141 < V_140 ) {
unsigned int V_151 ;
V_151 = V_140 ;
V_140 = V_141 ;
V_141 = V_151 ;
}
if ( V_140 != V_141 &&
V_140 >= 5 && V_140 <= 7 &&
V_141 >= 5 && V_141 <= 7 ) {
V_45 = F_69 ( V_48 , F_23 , 0 ,
V_2 -> V_152 , V_2 ) ;
if ( V_45 == 0 ) {
V_2 -> V_48 = V_48 ;
V_45 = F_59 ( V_2 , V_140 , V_141 ) ;
if ( V_45 < 0 ) {
F_62 ( V_2 ) ;
F_70 ( V_2 -> V_48 , V_2 ) ;
V_2 -> V_48 = 0 ;
}
}
}
}
V_45 = F_71 ( V_2 , 3 ) ;
if ( V_45 )
return V_45 ;
V_28 = & V_2 -> V_153 [ 0 ] ;
V_28 -> type = V_154 ;
V_28 -> V_155 = V_156 ;
if ( ( V_149 -> V_150 [ 4 ] && V_86 -> V_157 ) || V_86 -> V_158 == 0 ) {
V_28 -> V_155 |= V_159 ;
V_28 -> V_160 = V_86 -> V_157 ;
} else {
V_28 -> V_155 |= V_161 ;
V_28 -> V_160 = V_86 -> V_158 ;
}
V_28 -> V_33 = V_86 -> V_162 ;
V_28 -> V_163 = F_58 ( V_86 -> V_136 , V_149 -> V_150 [ 8 ] ) ;
V_6 -> V_34 = V_149 -> V_150 [ 5 ] ? 1 : 0 ;
V_28 -> V_164 = F_34 ;
if ( V_2 -> V_48 ) {
V_2 -> V_50 = V_28 ;
V_28 -> V_155 |= V_165 ;
V_28 -> V_166 = V_28 -> V_160 ;
V_28 -> V_167 = F_36 ;
V_28 -> V_168 = F_44 ;
V_28 -> V_169 = F_45 ;
}
V_28 = & V_2 -> V_153 [ 1 ] ;
if ( V_86 -> V_170 ) {
V_28 -> type = V_171 ;
V_28 -> V_155 = V_172 ;
V_28 -> V_160 = V_86 -> V_170 ;
V_28 -> V_33 = V_86 -> V_173 ;
V_28 -> V_163 = & V_174 ;
V_28 -> V_164 = F_46 ;
V_28 -> V_175 = F_47 ;
if ( V_2 -> V_48 ) {
V_2 -> V_52 = V_28 ;
V_28 -> V_155 |= V_176 ;
V_28 -> V_166 = V_28 -> V_160 ;
V_28 -> V_167 = F_50 ;
V_28 -> V_168 = F_52 ;
V_28 -> V_169 = F_53 ;
}
} else {
V_28 -> type = V_177 ;
}
V_28 = & V_2 -> V_153 [ 2 ] ;
V_28 -> type = V_178 ;
V_28 -> V_155 = V_156 | V_172 ;
V_28 -> V_160 = 16 ;
V_28 -> V_33 = 1 ;
V_28 -> V_163 = & V_179 ;
V_28 -> V_180 = F_54 ;
V_28 -> V_181 = F_56 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_62 ( V_2 ) ;
F_73 ( V_2 ) ;
}
