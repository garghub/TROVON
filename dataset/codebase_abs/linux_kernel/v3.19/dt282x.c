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
static unsigned int F_17 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
int V_35 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void * V_36 = V_6 -> V_13 [ V_35 ] . V_16 ;
unsigned int V_37 = F_18 ( V_28 , V_6 -> V_12 ) ;
unsigned int V_29 ;
V_29 = F_19 ( V_28 , V_36 , V_37 ) ;
if ( V_29 )
F_10 ( V_2 , V_35 , V_29 ) ;
else
F_15 ( V_2 -> V_32 , L_2 ) ;
return V_29 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_35 = V_6 -> V_38 ;
F_21 ( V_6 -> V_39 | V_40 ,
V_2 -> V_41 + V_42 ) ;
F_12 ( V_6 -> V_13 [ V_35 ] . V_15 ) ;
V_6 -> V_38 = 1 - V_35 ;
if ( ! F_17 ( V_2 , V_28 , V_35 ) )
V_28 -> V_43 -> V_44 |= V_45 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_35 = V_6 -> V_38 ;
void * V_36 = V_6 -> V_13 [ V_35 ] . V_16 ;
int V_14 = V_6 -> V_13 [ V_35 ] . V_14 ;
unsigned int V_37 = F_18 ( V_28 , V_14 ) ;
int V_46 ;
F_21 ( V_6 -> V_39 | V_40 ,
V_2 -> V_41 + V_42 ) ;
F_12 ( V_6 -> V_13 [ V_35 ] . V_15 ) ;
V_6 -> V_38 = 1 - V_35 ;
F_14 ( V_2 , V_28 , V_36 , V_14 ) ;
V_46 = F_23 ( V_28 , V_36 , V_37 ) ;
if ( V_46 != V_14 )
return;
V_6 -> V_47 -= V_37 ;
if ( V_6 -> V_47 < 0 ) {
F_24 ( V_2 -> V_32 , L_3 ) ;
V_6 -> V_47 = 0 ;
}
if ( ! V_6 -> V_47 ) {
V_28 -> V_43 -> V_44 |= V_48 ;
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
static T_1 F_25 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_27 * V_28 = V_2 -> V_51 ;
struct V_27 * V_52 = V_2 -> V_53 ;
unsigned int V_39 , V_54 , V_55 ;
int V_56 = 0 ;
if ( ! V_2 -> V_57 ) {
F_15 ( V_2 -> V_32 , L_4 ) ;
return V_58 ;
}
V_54 = F_26 ( V_2 -> V_41 + V_59 ) ;
V_55 = F_26 ( V_2 -> V_41 + V_60 ) ;
V_39 = F_26 ( V_2 -> V_41 + V_42 ) ;
if ( V_39 & V_61 ) {
if ( V_6 -> V_62 == V_17 )
F_22 ( V_2 , V_28 ) ;
else
F_20 ( V_2 , V_52 ) ;
V_56 = 1 ;
}
if ( V_54 & V_63 ) {
if ( V_6 -> V_47 != 0 ) {
F_15 ( V_2 -> V_32 , L_5 ) ;
V_28 -> V_43 -> V_44 |= V_64 ;
}
V_56 = 1 ;
}
if ( V_55 & V_65 ) {
F_15 ( V_2 -> V_32 , L_6 ) ;
V_52 -> V_43 -> V_44 |= V_64 ;
V_56 = 1 ;
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
F_27 ( V_2 , V_28 ) ;
F_27 ( V_2 , V_52 ) ;
return F_28 ( V_56 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_4 ,
unsigned int * V_66 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_31 ;
F_21 ( V_67 | F_30 ( V_4 ) ,
V_2 -> V_41 + V_68 ) ;
for ( V_31 = 0 ; V_31 < V_4 ; V_31 ++ ) {
unsigned int V_15 = F_31 ( V_66 [ V_31 ] ) ;
unsigned int V_69 = F_32 ( V_66 [ V_31 ] ) ;
F_21 ( V_6 -> V_54 |
F_33 ( V_69 ) |
F_34 ( V_15 ) ,
V_2 -> V_41 + V_59 ) ;
}
F_21 ( F_30 ( V_4 ) , V_2 -> V_41 + V_68 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_70 * V_71 ,
unsigned long V_72 )
{
unsigned int V_73 ;
V_73 = F_26 ( V_2 -> V_41 + V_59 ) ;
switch ( V_72 ) {
case V_74 :
if ( ( V_73 & V_74 ) == 0 )
return 0 ;
break;
case V_75 :
if ( V_73 & V_75 )
return 0 ;
break;
default:
return - V_76 ;
}
return - V_77 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_70 * V_71 ,
unsigned int * V_78 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_30 ;
int V_46 ;
int V_31 ;
V_6 -> V_54 = V_79 ;
F_21 ( V_6 -> V_54 , V_2 -> V_41 + V_59 ) ;
F_29 ( V_2 , 1 , & V_71 -> V_80 ) ;
F_21 ( V_6 -> V_39 | V_81 ,
V_2 -> V_41 + V_42 ) ;
V_46 = F_37 ( V_2 , V_28 , V_71 ,
F_35 , V_74 ) ;
if ( V_46 )
return V_46 ;
for ( V_31 = 0 ; V_31 < V_71 -> V_4 ; V_31 ++ ) {
F_21 ( V_6 -> V_39 | V_82 ,
V_2 -> V_41 + V_42 ) ;
V_46 = F_37 ( V_2 , V_28 , V_71 ,
F_35 , V_75 ) ;
if ( V_46 )
return V_46 ;
V_30 = F_26 ( V_2 -> V_41 + V_83 ) ;
V_30 &= V_28 -> V_33 ;
if ( V_6 -> V_34 )
V_30 = F_16 ( V_28 , V_30 ) ;
V_78 [ V_31 ] = V_30 ;
}
return V_31 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_84 * V_85 )
{
const struct V_86 * V_87 = V_2 -> V_88 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_89 = 0 ;
unsigned int V_90 ;
V_89 |= F_39 ( & V_85 -> V_91 , V_92 ) ;
V_89 |= F_39 ( & V_85 -> V_93 ,
V_94 | V_95 ) ;
V_89 |= F_39 ( & V_85 -> V_96 , V_97 ) ;
V_89 |= F_39 ( & V_85 -> V_98 , V_99 ) ;
V_89 |= F_39 ( & V_85 -> V_100 , V_99 | V_101 ) ;
if ( V_89 )
return 1 ;
V_89 |= F_40 ( V_85 -> V_93 ) ;
V_89 |= F_40 ( V_85 -> V_100 ) ;
if ( V_89 )
return 2 ;
V_89 |= F_41 ( & V_85 -> V_102 , 0 ) ;
if ( V_85 -> V_93 == V_94 ) {
V_89 |= F_41 ( & V_85 -> V_103 , 0 ) ;
} else {
V_89 |= F_41 ( & V_85 -> V_103 , 0 ) ;
}
V_89 |= F_42 ( & V_85 -> V_104 , 4000 ) ;
#define F_43 (250*(1<<15)*255)
V_89 |= F_44 ( & V_85 -> V_104 , F_43 ) ;
V_89 |= F_42 ( & V_85 -> V_104 , V_87 -> V_105 ) ;
V_89 |= F_41 ( & V_85 -> V_106 , V_85 -> V_107 ) ;
if ( V_85 -> V_100 == V_99 )
V_89 |= F_42 ( & V_85 -> V_108 , 1 ) ;
else
V_89 |= F_41 ( & V_85 -> V_108 , 0 ) ;
if ( V_89 )
return 3 ;
V_90 = V_85 -> V_104 ;
V_6 -> V_109 = F_13 ( & V_90 , V_85 -> V_10 ) ;
V_89 |= F_41 ( & V_85 -> V_104 , V_90 ) ;
if ( V_89 )
return 4 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_84 * V_85 = & V_28 -> V_43 -> V_85 ;
int V_46 ;
F_11 ( V_2 ) ;
F_21 ( V_6 -> V_109 , V_2 -> V_41 + V_110 ) ;
V_6 -> V_39 = V_111 ;
if ( V_85 -> V_93 == V_94 )
V_6 -> V_39 = V_112 ;
else
V_6 -> V_39 = V_113 ;
F_21 ( V_6 -> V_39 |
V_40 |
V_114 |
V_115 ,
V_2 -> V_41 + V_42 ) ;
V_6 -> V_11 = V_85 -> V_108 * V_85 -> V_106 ;
V_6 -> V_47 = V_6 -> V_11 ;
V_6 -> V_62 = V_17 ;
V_6 -> V_38 = 0 ;
F_1 ( V_2 , 0 , 0 ) ;
if ( V_6 -> V_11 ) {
F_1 ( V_2 , 1 , 0 ) ;
V_6 -> V_39 |= V_116 ;
F_21 ( V_6 -> V_39 , V_2 -> V_41 + V_42 ) ;
}
V_6 -> V_54 = 0 ;
F_29 ( V_2 , V_85 -> V_107 , V_85 -> V_66 ) ;
V_6 -> V_54 = V_79 | V_117 ;
F_21 ( V_6 -> V_54 , V_2 -> V_41 + V_59 ) ;
F_21 ( V_6 -> V_39 | V_81 ,
V_2 -> V_41 + V_42 ) ;
V_46 = F_37 ( V_2 , V_28 , NULL ,
F_35 , V_74 ) ;
if ( V_46 )
return V_46 ;
if ( V_85 -> V_93 == V_94 ) {
F_21 ( V_6 -> V_39 | V_82 ,
V_2 -> V_41 + V_42 ) ;
} else {
V_6 -> V_39 |= V_118 ;
F_21 ( V_6 -> V_39 , V_2 -> V_41 + V_42 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_11 ( V_2 ) ;
V_6 -> V_54 = 0 ;
F_21 ( V_6 -> V_54 , V_2 -> V_41 + V_59 ) ;
V_6 -> V_39 = 0 ;
F_21 ( V_6 -> V_39 | V_115 ,
V_2 -> V_41 + V_42 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_70 * V_71 ,
unsigned int * V_78 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_15 = F_31 ( V_71 -> V_80 ) ;
unsigned int V_69 = F_32 ( V_71 -> V_80 ) ;
int V_31 ;
V_6 -> V_55 |= V_119 | F_48 ( V_15 ) ;
for ( V_31 = 0 ; V_31 < V_71 -> V_4 ; V_31 ++ ) {
unsigned int V_30 = V_78 [ V_31 ] ;
V_28 -> V_120 [ V_15 ] = V_30 ;
if ( F_49 ( V_28 , V_69 ) )
V_30 = F_16 ( V_28 , V_30 ) ;
F_21 ( V_6 -> V_55 , V_2 -> V_41 + V_60 ) ;
F_21 ( V_30 , V_2 -> V_41 + V_121 ) ;
F_21 ( V_6 -> V_39 | V_122 ,
V_2 -> V_41 + V_42 ) ;
}
return V_71 -> V_4 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_84 * V_85 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_89 = 0 ;
unsigned int V_90 ;
V_89 |= F_39 ( & V_85 -> V_91 , V_123 ) ;
V_89 |= F_39 ( & V_85 -> V_93 , V_97 ) ;
V_89 |= F_39 ( & V_85 -> V_96 , V_92 ) ;
V_89 |= F_39 ( & V_85 -> V_98 , V_99 ) ;
V_89 |= F_39 ( & V_85 -> V_100 , V_99 | V_101 ) ;
if ( V_89 )
return 1 ;
V_89 |= F_40 ( V_85 -> V_100 ) ;
if ( V_89 )
return 2 ;
V_89 |= F_41 ( & V_85 -> V_102 , 0 ) ;
V_89 |= F_42 ( & V_85 -> V_103 , 5000 ) ;
V_89 |= F_41 ( & V_85 -> V_104 , 0 ) ;
V_89 |= F_41 ( & V_85 -> V_106 , V_85 -> V_107 ) ;
if ( V_85 -> V_100 == V_99 )
V_89 |= F_42 ( & V_85 -> V_108 , 1 ) ;
else
V_89 |= F_41 ( & V_85 -> V_108 , 0 ) ;
if ( V_89 )
return 3 ;
V_90 = V_85 -> V_103 ;
V_6 -> V_109 = F_13 ( & V_90 , V_85 -> V_10 ) ;
V_89 |= F_41 ( & V_85 -> V_103 , V_90 ) ;
if ( V_89 )
return 4 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned int V_124 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_84 * V_85 = & V_28 -> V_43 -> V_85 ;
if ( V_124 != V_85 -> V_91 )
return - V_76 ;
if ( ! F_17 ( V_2 , V_28 , 0 ) )
return - V_125 ;
if ( ! F_17 ( V_2 , V_28 , 1 ) )
return - V_125 ;
F_21 ( V_6 -> V_39 | V_82 ,
V_2 -> V_41 + V_42 ) ;
V_28 -> V_43 -> V_126 = NULL ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_84 * V_85 = & V_28 -> V_43 -> V_85 ;
F_11 ( V_2 ) ;
V_6 -> V_39 = V_111 |
V_127 |
V_116 ;
F_21 ( V_6 -> V_39 |
V_40 |
V_114 |
V_128 ,
V_2 -> V_41 + V_42 ) ;
V_6 -> V_11 = V_85 -> V_108 * V_85 -> V_107 ;
V_6 -> V_47 = V_6 -> V_11 ;
V_6 -> V_62 = V_18 ;
V_6 -> V_38 = 0 ;
F_21 ( V_6 -> V_109 , V_2 -> V_41 + V_110 ) ;
V_6 -> V_55 &= ( V_129 | V_130 ) ;
V_6 -> V_55 |= ( V_119 |
V_131 |
V_132 ) ;
F_21 ( V_6 -> V_55 , V_2 -> V_41 + V_60 ) ;
V_28 -> V_43 -> V_126 = F_51 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_11 ( V_2 ) ;
V_6 -> V_55 &= ( V_129 | V_130 ) ;
F_21 ( V_6 -> V_55 , V_2 -> V_41 + V_60 ) ;
V_6 -> V_39 = 0 ;
F_21 ( V_6 -> V_39 | V_128 ,
V_2 -> V_41 + V_42 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_70 * V_71 ,
unsigned int * V_78 )
{
if ( F_55 ( V_28 , V_78 ) )
F_21 ( V_28 -> V_133 , V_2 -> V_41 + V_134 ) ;
V_78 [ 1 ] = F_26 ( V_2 -> V_41 + V_134 ) ;
return V_71 -> V_4 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_70 * V_71 ,
unsigned int * V_78 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_15 = F_31 ( V_71 -> V_80 ) ;
unsigned int V_135 ;
int V_46 ;
if ( V_15 < 8 )
V_135 = 0x00ff ;
else
V_135 = 0xff00 ;
V_46 = F_57 ( V_2 , V_28 , V_71 , V_78 , V_135 ) ;
if ( V_46 )
return V_46 ;
V_6 -> V_55 &= ~ ( V_129 | V_130 ) ;
if ( V_28 -> V_136 & 0x00ff )
V_6 -> V_55 |= V_129 ;
if ( V_28 -> V_136 & 0xff00 )
V_6 -> V_55 |= V_130 ;
F_21 ( V_6 -> V_55 , V_2 -> V_41 + V_60 ) ;
return V_71 -> V_4 ;
}
static const struct V_137 * F_58 ( int V_138 , int V_139 )
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
static int F_59 ( struct V_1 * V_2 , int V_142 , int V_143 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_46 ;
V_46 = F_60 ( V_142 , L_7 ) ;
if ( V_46 )
return - V_77 ;
V_6 -> V_13 [ 0 ] . V_15 = V_142 ;
V_46 = F_60 ( V_143 , L_8 ) ;
if ( V_46 )
return - V_77 ;
V_6 -> V_13 [ 1 ] . V_15 = V_143 ;
V_6 -> V_12 = V_144 ;
V_6 -> V_13 [ 0 ] . V_16 = ( void * ) F_61 ( V_145 | V_146 ) ;
V_6 -> V_13 [ 1 ] . V_16 = ( void * ) F_61 ( V_145 | V_146 ) ;
if ( ! V_6 -> V_13 [ 0 ] . V_16 || ! V_6 -> V_13 [ 1 ] . V_16 )
return - V_147 ;
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
F_21 ( V_148 , V_2 -> V_41 + V_42 ) ;
F_26 ( V_2 -> V_41 + V_59 ) ;
if ( ( ( F_26 ( V_2 -> V_41 + V_59 ) & 0xfff0 ) != 0x7c00 ) ||
( ( F_26 ( V_2 -> V_41 + V_68 ) & 0xf0f0 ) != 0x70f0 ) ||
( ( F_26 ( V_2 -> V_41 + V_60 ) & 0x7c93 ) != 0x7c90 ) ||
( ( F_26 ( V_2 -> V_41 + V_42 ) & 0xf8ff ) != 0x0000 ) ||
( ( F_26 ( V_2 -> V_41 + V_110 ) & 0xff00 ) != 0xf000 ) ) {
F_15 ( V_2 -> V_32 , L_9 ) ;
return - V_149 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
const struct V_86 * V_87 = V_2 -> V_88 ;
struct V_5 * V_6 ;
struct V_27 * V_28 ;
int V_46 ;
V_46 = F_67 ( V_2 , V_151 -> V_152 [ 0 ] , 0x10 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_65 ( V_2 ) ;
if ( V_46 )
return V_46 ;
V_6 = F_68 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_147 ;
if ( V_151 -> V_152 [ 1 ] && V_151 -> V_152 [ 2 ] && V_151 -> V_152 [ 3 ] ) {
unsigned int V_49 = V_151 -> V_152 [ 1 ] ;
unsigned int V_142 = V_151 -> V_152 [ 2 ] ;
unsigned int V_143 = V_151 -> V_152 [ 3 ] ;
if ( V_143 < V_142 ) {
unsigned int V_153 ;
V_153 = V_142 ;
V_142 = V_143 ;
V_143 = V_153 ;
}
if ( V_142 != V_143 &&
V_142 >= 5 && V_142 <= 7 &&
V_143 >= 5 && V_143 <= 7 ) {
V_46 = F_69 ( V_49 , F_25 , 0 ,
V_2 -> V_154 , V_2 ) ;
if ( V_46 == 0 ) {
V_2 -> V_49 = V_49 ;
V_46 = F_59 ( V_2 , V_142 , V_143 ) ;
if ( V_46 < 0 ) {
F_62 ( V_2 ) ;
F_70 ( V_2 -> V_49 , V_2 ) ;
V_2 -> V_49 = 0 ;
}
}
}
}
V_46 = F_71 ( V_2 , 3 ) ;
if ( V_46 )
return V_46 ;
V_28 = & V_2 -> V_155 [ 0 ] ;
V_28 -> type = V_156 ;
V_28 -> V_157 = V_158 ;
if ( ( V_151 -> V_152 [ 4 ] && V_87 -> V_159 ) || V_87 -> V_160 == 0 ) {
V_28 -> V_157 |= V_161 ;
V_28 -> V_162 = V_87 -> V_159 ;
} else {
V_28 -> V_157 |= V_163 ;
V_28 -> V_162 = V_87 -> V_160 ;
}
V_28 -> V_33 = V_87 -> V_164 ;
V_28 -> V_165 = F_58 ( V_87 -> V_138 , V_151 -> V_152 [ 8 ] ) ;
V_6 -> V_34 = V_151 -> V_152 [ 5 ] ? 1 : 0 ;
V_28 -> V_166 = F_36 ;
if ( V_2 -> V_49 ) {
V_2 -> V_51 = V_28 ;
V_28 -> V_157 |= V_167 ;
V_28 -> V_168 = V_28 -> V_162 ;
V_28 -> V_169 = F_38 ;
V_28 -> V_170 = F_45 ;
V_28 -> V_171 = F_46 ;
}
V_28 = & V_2 -> V_155 [ 1 ] ;
if ( V_87 -> V_172 ) {
V_28 -> type = V_173 ;
V_28 -> V_157 = V_174 ;
V_28 -> V_162 = V_87 -> V_172 ;
V_28 -> V_33 = V_87 -> V_175 ;
V_28 -> V_165 = & V_176 ;
V_28 -> V_177 = F_47 ;
if ( V_2 -> V_49 ) {
V_2 -> V_53 = V_28 ;
V_28 -> V_157 |= V_178 ;
V_28 -> V_168 = V_28 -> V_162 ;
V_28 -> V_169 = F_50 ;
V_28 -> V_170 = F_52 ;
V_28 -> V_171 = F_53 ;
}
V_46 = F_72 ( V_28 ) ;
if ( V_46 )
return V_46 ;
} else {
V_28 -> type = V_179 ;
}
V_28 = & V_2 -> V_155 [ 2 ] ;
V_28 -> type = V_180 ;
V_28 -> V_157 = V_158 | V_174 ;
V_28 -> V_162 = 16 ;
V_28 -> V_33 = 1 ;
V_28 -> V_165 = & V_181 ;
V_28 -> V_182 = F_54 ;
V_28 -> V_183 = F_56 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_62 ( V_2 ) ;
F_74 ( V_2 ) ;
}
