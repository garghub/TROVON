static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
if ( ! V_6 -> V_12 )
return 0 ;
if ( V_4 == 0 )
V_4 = V_11 -> V_13 ;
if ( V_4 > V_6 -> V_12 * 2 )
V_4 = V_6 -> V_12 * 2 ;
V_6 -> V_12 -= V_4 / 2 ;
V_11 -> V_14 = V_4 ;
F_2 ( V_11 , V_6 -> V_15 ) ;
F_3 ( V_11 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_3 ] ;
V_11 -> V_14 = V_4 ;
F_2 ( V_11 , V_6 -> V_15 ) ;
F_3 ( V_11 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_11 = & V_9 -> V_11 [ V_16 ] ;
F_6 ( V_11 -> V_17 ) ;
}
}
static unsigned int F_7 ( unsigned int * V_18 , unsigned int V_19 )
{
unsigned int V_20 , V_21 , V_22 ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ ) {
if ( V_20 == 1 )
continue;
V_21 = 250 * ( 1 << V_20 ) ;
switch ( V_19 & V_23 ) {
case V_24 :
default:
V_22 = ( * V_18 + V_21 / 2 ) / V_21 ;
break;
case V_25 :
V_22 = ( * V_18 ) / V_21 ;
break;
case V_26 :
V_22 = ( * V_18 + V_21 - 1 ) / V_21 ;
break;
}
if ( V_22 < 256 ) {
* V_18 = V_22 * V_21 ;
return ( V_20 << 8 ) | ( 255 - V_22 ) ;
}
}
V_21 = 250 * ( 1 << 15 ) ;
V_22 = 255 ;
* V_18 = V_22 * V_21 ;
return ( 15 << 8 ) | ( 255 - V_22 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned short * V_29 ,
unsigned int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_31 ;
int V_16 ;
if ( V_30 % 2 )
F_9 ( V_2 -> V_32 ,
L_1 ) ;
for ( V_16 = 0 ; V_16 < V_30 / 2 ; V_16 ++ ) {
V_31 = V_29 [ V_16 ] ;
V_31 &= V_28 -> V_33 ;
if ( V_6 -> V_34 )
V_31 = F_10 ( V_28 , V_31 ) ;
V_29 [ V_16 ] = V_31 ;
}
}
static unsigned int F_11 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
int V_35 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_35 ] ;
unsigned int V_36 = F_12 ( V_28 , V_11 -> V_13 ) ;
unsigned int V_30 ;
V_30 = F_13 ( V_28 , V_11 -> V_37 , V_36 ) ;
if ( V_30 )
F_4 ( V_2 , V_35 , V_30 ) ;
else
F_9 ( V_2 -> V_32 , L_2 ) ;
return V_30 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_9 -> V_35 ] ;
F_15 ( V_6 -> V_38 | V_39 ,
V_2 -> V_40 + V_41 ) ;
F_6 ( V_11 -> V_17 ) ;
if ( ! F_11 ( V_2 , V_28 , V_9 -> V_35 ) )
V_28 -> V_42 -> V_43 |= V_44 ;
V_9 -> V_35 = 1 - V_9 -> V_35 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_9 -> V_35 ] ;
unsigned int V_36 = F_12 ( V_28 , V_11 -> V_14 ) ;
int V_45 ;
F_15 ( V_6 -> V_38 | V_39 ,
V_2 -> V_40 + V_41 ) ;
F_6 ( V_11 -> V_17 ) ;
F_8 ( V_2 , V_28 , V_11 -> V_37 , V_11 -> V_14 ) ;
V_45 = F_17 ( V_28 , V_11 -> V_37 , V_36 ) ;
if ( V_45 != V_11 -> V_14 )
return;
V_6 -> V_46 -= V_36 ;
if ( V_6 -> V_46 < 0 ) {
F_18 ( V_2 -> V_32 , L_3 ) ;
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
F_1 ( V_2 , V_9 -> V_35 , 0 ) ;
V_9 -> V_35 = 1 - V_9 -> V_35 ;
}
static T_1 F_19 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_27 * V_28 = V_2 -> V_50 ;
struct V_27 * V_51 = V_2 -> V_52 ;
unsigned int V_38 , V_53 , V_54 ;
int V_55 = 0 ;
if ( ! V_2 -> V_56 ) {
F_9 ( V_2 -> V_32 , L_4 ) ;
return V_57 ;
}
V_53 = F_20 ( V_2 -> V_40 + V_58 ) ;
V_54 = F_20 ( V_2 -> V_40 + V_59 ) ;
V_38 = F_20 ( V_2 -> V_40 + V_41 ) ;
if ( V_38 & V_60 ) {
if ( V_6 -> V_15 == V_61 )
F_16 ( V_2 , V_28 ) ;
else
F_14 ( V_2 , V_51 ) ;
V_55 = 1 ;
}
if ( V_53 & V_62 ) {
if ( V_6 -> V_46 != 0 ) {
F_9 ( V_2 -> V_32 , L_5 ) ;
V_28 -> V_42 -> V_43 |= V_63 ;
}
V_55 = 1 ;
}
if ( V_54 & V_64 ) {
F_9 ( V_2 -> V_32 , L_6 ) ;
V_51 -> V_42 -> V_43 |= V_63 ;
V_55 = 1 ;
}
#if 0
if (adcsr & DT2821_ADCSR_ADDONE) {
unsigned short data;
data = inw(dev->iobase + DT2821_ADDAT_REG);
data &= s->maxdata;
if (devpriv->ad_2scomp)
data = comedi_offset_munge(s, data);
comedi_buf_write_samples(s, &data, 1);
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
F_21 ( V_2 , V_28 ) ;
F_21 ( V_2 , V_51 ) ;
return F_22 ( V_55 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_4 ,
unsigned int * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 ;
F_15 ( V_66 | F_24 ( V_4 ) ,
V_2 -> V_40 + V_67 ) ;
for ( V_16 = 0 ; V_16 < V_4 ; V_16 ++ ) {
unsigned int V_17 = F_25 ( V_65 [ V_16 ] ) ;
unsigned int V_68 = F_26 ( V_65 [ V_16 ] ) ;
F_15 ( V_6 -> V_53 |
F_27 ( V_68 ) |
F_28 ( V_17 ) ,
V_2 -> V_40 + V_58 ) ;
}
F_15 ( F_24 ( V_4 ) , V_2 -> V_40 + V_67 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned long V_71 )
{
unsigned int V_72 ;
V_72 = F_20 ( V_2 -> V_40 + V_58 ) ;
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
static int F_30 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_31 ;
int V_45 ;
int V_16 ;
V_6 -> V_53 = V_78 ;
F_15 ( V_6 -> V_53 , V_2 -> V_40 + V_58 ) ;
F_23 ( V_2 , 1 , & V_70 -> V_79 ) ;
F_15 ( V_6 -> V_38 | V_80 ,
V_2 -> V_40 + V_41 ) ;
V_45 = F_31 ( V_2 , V_28 , V_70 ,
F_29 , V_73 ) ;
if ( V_45 )
return V_45 ;
for ( V_16 = 0 ; V_16 < V_70 -> V_4 ; V_16 ++ ) {
F_15 ( V_6 -> V_38 | V_81 ,
V_2 -> V_40 + V_41 ) ;
V_45 = F_31 ( V_2 , V_28 , V_70 ,
F_29 , V_74 ) ;
if ( V_45 )
return V_45 ;
V_31 = F_20 ( V_2 -> V_40 + V_82 ) ;
V_31 &= V_28 -> V_33 ;
if ( V_6 -> V_34 )
V_31 = F_10 ( V_28 , V_31 ) ;
V_77 [ V_16 ] = V_31 ;
}
return V_16 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_83 * V_84 )
{
const struct V_85 * V_86 = V_2 -> V_87 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_88 = 0 ;
unsigned int V_89 ;
V_88 |= F_33 ( & V_84 -> V_90 , V_91 ) ;
V_88 |= F_33 ( & V_84 -> V_92 ,
V_93 | V_94 ) ;
V_88 |= F_33 ( & V_84 -> V_95 , V_96 ) ;
V_88 |= F_33 ( & V_84 -> V_97 , V_98 ) ;
V_88 |= F_33 ( & V_84 -> V_99 , V_98 | V_100 ) ;
if ( V_88 )
return 1 ;
V_88 |= F_34 ( V_84 -> V_92 ) ;
V_88 |= F_34 ( V_84 -> V_99 ) ;
if ( V_88 )
return 2 ;
V_88 |= F_35 ( & V_84 -> V_101 , 0 ) ;
V_88 |= F_35 ( & V_84 -> V_102 , 0 ) ;
V_88 |= F_36 ( & V_84 -> V_103 , 4000 ) ;
#define F_37 (250*(1<<15)*255)
V_88 |= F_38 ( & V_84 -> V_103 , F_37 ) ;
V_88 |= F_36 ( & V_84 -> V_103 , V_86 -> V_104 ) ;
V_88 |= F_35 ( & V_84 -> V_105 ,
V_84 -> V_106 ) ;
if ( V_84 -> V_99 == V_98 )
V_88 |= F_36 ( & V_84 -> V_107 , 1 ) ;
else
V_88 |= F_35 ( & V_84 -> V_107 , 0 ) ;
if ( V_88 )
return 3 ;
V_89 = V_84 -> V_103 ;
V_6 -> V_108 = F_7 ( & V_89 , V_84 -> V_19 ) ;
V_88 |= F_35 ( & V_84 -> V_103 , V_89 ) ;
if ( V_88 )
return 4 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_83 * V_84 = & V_28 -> V_42 -> V_84 ;
int V_45 ;
F_5 ( V_2 ) ;
F_15 ( V_6 -> V_108 , V_2 -> V_40 + V_109 ) ;
V_6 -> V_38 = V_110 ;
if ( V_84 -> V_92 == V_93 )
V_6 -> V_38 = V_111 ;
else
V_6 -> V_38 = V_112 ;
F_15 ( V_6 -> V_38 |
V_39 |
V_113 |
V_114 ,
V_2 -> V_40 + V_41 ) ;
V_6 -> V_12 = V_84 -> V_107 * V_84 -> V_105 ;
V_6 -> V_46 = V_6 -> V_12 ;
V_6 -> V_15 = V_61 ;
V_9 -> V_35 = 0 ;
F_1 ( V_2 , 0 , 0 ) ;
if ( V_6 -> V_12 ) {
F_1 ( V_2 , 1 , 0 ) ;
V_6 -> V_38 |= V_115 ;
F_15 ( V_6 -> V_38 , V_2 -> V_40 + V_41 ) ;
}
V_6 -> V_53 = 0 ;
F_23 ( V_2 , V_84 -> V_106 , V_84 -> V_65 ) ;
V_6 -> V_53 = V_78 | V_116 ;
F_15 ( V_6 -> V_53 , V_2 -> V_40 + V_58 ) ;
F_15 ( V_6 -> V_38 | V_80 ,
V_2 -> V_40 + V_41 ) ;
V_45 = F_31 ( V_2 , V_28 , NULL ,
F_29 , V_73 ) ;
if ( V_45 )
return V_45 ;
if ( V_84 -> V_92 == V_93 ) {
F_15 ( V_6 -> V_38 | V_81 ,
V_2 -> V_40 + V_41 ) ;
} else {
V_6 -> V_38 |= V_117 ;
F_15 ( V_6 -> V_38 , V_2 -> V_40 + V_41 ) ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( V_2 ) ;
V_6 -> V_53 = 0 ;
F_15 ( V_6 -> V_53 , V_2 -> V_40 + V_58 ) ;
V_6 -> V_38 = 0 ;
F_15 ( V_6 -> V_38 | V_114 ,
V_2 -> V_40 + V_41 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_17 = F_25 ( V_70 -> V_79 ) ;
unsigned int V_68 = F_26 ( V_70 -> V_79 ) ;
int V_16 ;
V_6 -> V_54 |= V_118 | F_42 ( V_17 ) ;
for ( V_16 = 0 ; V_16 < V_70 -> V_4 ; V_16 ++ ) {
unsigned int V_31 = V_77 [ V_16 ] ;
V_28 -> V_119 [ V_17 ] = V_31 ;
if ( F_43 ( V_28 , V_68 ) )
V_31 = F_10 ( V_28 , V_31 ) ;
F_15 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
F_15 ( V_31 , V_2 -> V_40 + V_120 ) ;
F_15 ( V_6 -> V_38 | V_121 ,
V_2 -> V_40 + V_41 ) ;
}
return V_70 -> V_4 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_88 = 0 ;
unsigned int V_89 ;
V_88 |= F_33 ( & V_84 -> V_90 , V_122 ) ;
V_88 |= F_33 ( & V_84 -> V_92 , V_96 ) ;
V_88 |= F_33 ( & V_84 -> V_95 , V_91 ) ;
V_88 |= F_33 ( & V_84 -> V_97 , V_98 ) ;
V_88 |= F_33 ( & V_84 -> V_99 , V_98 | V_100 ) ;
if ( V_88 )
return 1 ;
V_88 |= F_34 ( V_84 -> V_99 ) ;
if ( V_88 )
return 2 ;
V_88 |= F_35 ( & V_84 -> V_101 , 0 ) ;
V_88 |= F_36 ( & V_84 -> V_102 , 5000 ) ;
V_88 |= F_35 ( & V_84 -> V_103 , 0 ) ;
V_88 |= F_35 ( & V_84 -> V_105 ,
V_84 -> V_106 ) ;
if ( V_84 -> V_99 == V_98 )
V_88 |= F_36 ( & V_84 -> V_107 , 1 ) ;
else
V_88 |= F_35 ( & V_84 -> V_107 , 0 ) ;
if ( V_88 )
return 3 ;
V_89 = V_84 -> V_102 ;
V_6 -> V_108 = F_7 ( & V_89 , V_84 -> V_19 ) ;
V_88 |= F_35 ( & V_84 -> V_102 , V_89 ) ;
if ( V_88 )
return 4 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned int V_123 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_83 * V_84 = & V_28 -> V_42 -> V_84 ;
if ( V_123 != V_84 -> V_90 )
return - V_75 ;
if ( ! F_11 ( V_2 , V_28 , 0 ) )
return - V_124 ;
if ( ! F_11 ( V_2 , V_28 , 1 ) )
return - V_124 ;
F_15 ( V_6 -> V_38 | V_81 ,
V_2 -> V_40 + V_41 ) ;
V_28 -> V_42 -> V_125 = NULL ;
return 1 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_83 * V_84 = & V_28 -> V_42 -> V_84 ;
F_5 ( V_2 ) ;
V_6 -> V_38 = V_110 |
V_126 |
V_115 ;
F_15 ( V_6 -> V_38 |
V_39 |
V_113 |
V_127 ,
V_2 -> V_40 + V_41 ) ;
V_6 -> V_12 = V_84 -> V_107 * V_84 -> V_106 ;
V_6 -> V_46 = V_6 -> V_12 ;
V_6 -> V_15 = V_128 ;
V_9 -> V_35 = 0 ;
F_15 ( V_6 -> V_108 , V_2 -> V_40 + V_109 ) ;
V_6 -> V_54 &= ( V_129 | V_130 ) ;
V_6 -> V_54 |= ( V_118 |
V_131 |
V_132 ) ;
F_15 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
V_28 -> V_42 -> V_125 = F_45 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( V_2 ) ;
V_6 -> V_54 &= ( V_129 | V_130 ) ;
F_15 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
V_6 -> V_38 = 0 ;
F_15 ( V_6 -> V_38 | V_127 ,
V_2 -> V_40 + V_41 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
if ( F_49 ( V_28 , V_77 ) )
F_15 ( V_28 -> V_133 , V_2 -> V_40 + V_134 ) ;
V_77 [ 1 ] = F_20 ( V_2 -> V_40 + V_134 ) ;
return V_70 -> V_4 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_69 * V_70 ,
unsigned int * V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_17 = F_25 ( V_70 -> V_79 ) ;
unsigned int V_135 ;
int V_45 ;
if ( V_17 < 8 )
V_135 = 0x00ff ;
else
V_135 = 0xff00 ;
V_45 = F_51 ( V_2 , V_28 , V_70 , V_77 , V_135 ) ;
if ( V_45 )
return V_45 ;
V_6 -> V_54 &= ~ ( V_129 | V_130 ) ;
if ( V_28 -> V_136 & 0x00ff )
V_6 -> V_54 |= V_129 ;
if ( V_28 -> V_136 & 0xff00 )
V_6 -> V_54 |= V_130 ;
F_15 ( V_6 -> V_54 , V_2 -> V_40 + V_59 ) ;
return V_70 -> V_4 ;
}
static const struct V_137 * F_52 ( int V_138 , int V_139 )
{
if ( V_138 ) {
if ( V_139 < 0 || V_139 >= 2 )
V_139 = 0 ;
return V_140 [ V_139 ] ;
}
if ( V_139 < 0 || V_139 >= 4 )
V_139 = 0 ;
return V_141 [ V_139 ] ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_142 * V_143 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_144 = V_143 -> V_145 [ 1 ] ;
unsigned int V_146 [ 2 ] ;
if ( V_143 -> V_145 [ 2 ] < V_143 -> V_145 [ 3 ] ) {
V_146 [ 0 ] = V_143 -> V_145 [ 2 ] ;
V_146 [ 1 ] = V_143 -> V_145 [ 3 ] ;
} else {
V_146 [ 0 ] = V_143 -> V_145 [ 3 ] ;
V_146 [ 1 ] = V_143 -> V_145 [ 2 ] ;
}
if ( ! V_144 || V_146 [ 0 ] == V_146 [ 1 ] ||
V_146 [ 0 ] < 5 || V_146 [ 0 ] > 7 ||
V_146 [ 1 ] < 5 || V_146 [ 1 ] > 7 )
return;
if ( F_54 ( V_144 , F_19 , 0 , V_2 -> V_147 , V_2 ) )
return;
V_6 -> V_9 = F_55 ( V_2 , 2 , V_146 [ 0 ] , V_146 [ 1 ] ,
V_148 , 0 ) ;
if ( ! V_6 -> V_9 )
F_56 ( V_144 , V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 )
F_58 ( V_6 -> V_9 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
F_15 ( V_149 , V_2 -> V_40 + V_41 ) ;
F_20 ( V_2 -> V_40 + V_58 ) ;
if ( ( ( F_20 ( V_2 -> V_40 + V_58 ) & 0xfff0 ) != 0x7c00 ) ||
( ( F_20 ( V_2 -> V_40 + V_67 ) & 0xf0f0 ) != 0x70f0 ) ||
( ( F_20 ( V_2 -> V_40 + V_59 ) & 0x7c93 ) != 0x7c90 ) ||
( ( F_20 ( V_2 -> V_40 + V_41 ) & 0xf8ff ) != 0x0000 ) ||
( ( F_20 ( V_2 -> V_40 + V_109 ) & 0xff00 ) != 0xf000 ) ) {
F_9 ( V_2 -> V_32 , L_7 ) ;
return - V_150 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
const struct V_85 * V_86 = V_2 -> V_87 ;
struct V_5 * V_6 ;
struct V_27 * V_28 ;
int V_45 ;
V_45 = F_61 ( V_2 , V_143 -> V_145 [ 0 ] , 0x10 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_59 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_6 = F_62 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_151 ;
F_53 ( V_2 , V_143 ) ;
V_45 = F_63 ( V_2 , 3 ) ;
if ( V_45 )
return V_45 ;
V_28 = & V_2 -> V_152 [ 0 ] ;
V_28 -> type = V_153 ;
V_28 -> V_154 = V_155 ;
if ( ( V_143 -> V_145 [ 4 ] && V_86 -> V_156 ) || V_86 -> V_157 == 0 ) {
V_28 -> V_154 |= V_158 ;
V_28 -> V_159 = V_86 -> V_156 ;
} else {
V_28 -> V_154 |= V_160 ;
V_28 -> V_159 = V_86 -> V_157 ;
}
V_28 -> V_33 = V_86 -> V_161 ;
V_28 -> V_162 = F_52 ( V_86 -> V_138 , V_143 -> V_145 [ 8 ] ) ;
V_6 -> V_34 = V_143 -> V_145 [ 5 ] ? 1 : 0 ;
V_28 -> V_163 = F_30 ;
if ( V_2 -> V_48 ) {
V_2 -> V_50 = V_28 ;
V_28 -> V_154 |= V_164 ;
V_28 -> V_165 = V_28 -> V_159 ;
V_28 -> V_166 = F_32 ;
V_28 -> V_167 = F_39 ;
V_28 -> V_168 = F_40 ;
}
V_28 = & V_2 -> V_152 [ 1 ] ;
if ( V_86 -> V_169 ) {
V_28 -> type = V_170 ;
V_28 -> V_154 = V_171 ;
V_28 -> V_159 = V_86 -> V_169 ;
V_28 -> V_33 = V_86 -> V_172 ;
V_28 -> V_162 = & V_173 ;
V_28 -> V_174 = F_41 ;
if ( V_2 -> V_48 ) {
V_2 -> V_52 = V_28 ;
V_28 -> V_154 |= V_175 ;
V_28 -> V_165 = V_28 -> V_159 ;
V_28 -> V_166 = F_44 ;
V_28 -> V_167 = F_46 ;
V_28 -> V_168 = F_47 ;
}
V_45 = F_64 ( V_28 ) ;
if ( V_45 )
return V_45 ;
} else {
V_28 -> type = V_176 ;
}
V_28 = & V_2 -> V_152 [ 2 ] ;
V_28 -> type = V_177 ;
V_28 -> V_154 = V_155 | V_171 ;
V_28 -> V_159 = 16 ;
V_28 -> V_33 = 1 ;
V_28 -> V_162 = & V_178 ;
V_28 -> V_179 = F_48 ;
V_28 -> V_180 = F_50 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_66 ( V_2 ) ;
}
