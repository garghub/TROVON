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
for ( V_20 = 0 ; V_20 <= V_23 ; V_20 ++ ) {
if ( V_20 == 1 )
continue;
V_21 = V_24 * F_8 ( V_20 ) ;
switch ( V_19 & V_25 ) {
case V_26 :
default:
V_22 = F_9 ( * V_18 , V_21 ) ;
break;
case V_27 :
V_22 = ( * V_18 ) / V_21 ;
break;
case V_28 :
V_22 = F_10 ( * V_18 , V_21 ) ;
break;
}
if ( V_22 <= V_29 )
break;
}
if ( V_22 > V_29 ) {
V_20 = V_23 ;
V_22 = V_29 ;
V_21 = V_24 * F_8 ( V_20 ) ;
}
* V_18 = V_22 * V_21 ;
return F_11 ( V_20 ) |
F_12 ( V_22 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
unsigned short * V_32 ,
unsigned int V_33 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_34 ;
int V_16 ;
if ( V_33 % 2 )
F_14 ( V_2 -> V_35 ,
L_1 ) ;
for ( V_16 = 0 ; V_16 < V_33 / 2 ; V_16 ++ ) {
V_34 = V_32 [ V_16 ] ;
V_34 &= V_31 -> V_36 ;
if ( V_6 -> V_37 )
V_34 = F_15 ( V_31 , V_34 ) ;
V_32 [ V_16 ] = V_34 ;
}
}
static unsigned int F_16 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
int V_38 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_38 ] ;
unsigned int V_39 = F_17 ( V_31 , V_11 -> V_13 ) ;
unsigned int V_33 ;
V_33 = F_18 ( V_31 , V_11 -> V_40 , V_39 ) ;
if ( V_33 )
F_4 ( V_2 , V_38 , V_33 ) ;
else
F_14 ( V_2 -> V_35 , L_2 ) ;
return V_33 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_9 -> V_38 ] ;
F_20 ( V_6 -> V_41 | V_42 ,
V_2 -> V_43 + V_44 ) ;
F_6 ( V_11 -> V_17 ) ;
if ( ! F_16 ( V_2 , V_31 , V_9 -> V_38 ) )
V_31 -> V_45 -> V_46 |= V_47 ;
V_9 -> V_38 = 1 - V_9 -> V_38 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_9 -> V_38 ] ;
unsigned int V_39 = F_17 ( V_31 , V_11 -> V_14 ) ;
int V_48 ;
F_20 ( V_6 -> V_41 | V_42 ,
V_2 -> V_43 + V_44 ) ;
F_6 ( V_11 -> V_17 ) ;
F_13 ( V_2 , V_31 , V_11 -> V_40 , V_11 -> V_14 ) ;
V_48 = F_22 ( V_31 , V_11 -> V_40 , V_39 ) ;
if ( V_48 != V_11 -> V_14 )
return;
V_6 -> V_49 -= V_39 ;
if ( V_6 -> V_49 < 0 ) {
F_23 ( V_2 -> V_35 , L_3 ) ;
V_6 -> V_49 = 0 ;
}
if ( ! V_6 -> V_49 ) {
V_31 -> V_45 -> V_46 |= V_50 ;
return;
}
#if 0
if (!devpriv->ntrig) {
devpriv->supcsr &= ~DT2821_SUPCSR_DDMA;
outw(devpriv->supcsr, dev->iobase + DT2821_SUPCSR_REG);
}
#endif
F_1 ( V_2 , V_9 -> V_38 , 0 ) ;
V_9 -> V_38 = 1 - V_9 -> V_38 ;
}
static T_1 F_24 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_30 * V_31 = V_2 -> V_53 ;
struct V_30 * V_54 = V_2 -> V_55 ;
unsigned int V_41 , V_56 , V_57 ;
int V_58 = 0 ;
if ( ! V_2 -> V_59 ) {
F_14 ( V_2 -> V_35 , L_4 ) ;
return V_60 ;
}
V_56 = F_25 ( V_2 -> V_43 + V_61 ) ;
V_57 = F_25 ( V_2 -> V_43 + V_62 ) ;
V_41 = F_25 ( V_2 -> V_43 + V_44 ) ;
if ( V_41 & V_63 ) {
if ( V_6 -> V_15 == V_64 )
F_21 ( V_2 , V_31 ) ;
else
F_19 ( V_2 , V_54 ) ;
V_58 = 1 ;
}
if ( V_56 & V_65 ) {
if ( V_6 -> V_49 != 0 ) {
F_14 ( V_2 -> V_35 , L_5 ) ;
V_31 -> V_45 -> V_46 |= V_66 ;
}
V_58 = 1 ;
}
if ( V_57 & V_67 ) {
F_14 ( V_2 -> V_35 , L_6 ) ;
V_54 -> V_45 -> V_46 |= V_66 ;
V_58 = 1 ;
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
F_26 ( V_2 , V_31 ) ;
F_26 ( V_2 , V_54 ) ;
return F_27 ( V_58 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_4 ,
unsigned int * V_68 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 ;
F_20 ( V_69 | F_29 ( V_4 ) ,
V_2 -> V_43 + V_70 ) ;
for ( V_16 = 0 ; V_16 < V_4 ; V_16 ++ ) {
unsigned int V_17 = F_30 ( V_68 [ V_16 ] ) ;
unsigned int V_71 = F_31 ( V_68 [ V_16 ] ) ;
F_20 ( V_6 -> V_56 |
F_32 ( V_71 ) |
F_33 ( V_17 ) ,
V_2 -> V_43 + V_61 ) ;
}
F_20 ( F_29 ( V_4 ) , V_2 -> V_43 + V_70 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_72 * V_73 ,
unsigned long V_74 )
{
unsigned int V_75 ;
V_75 = F_25 ( V_2 -> V_43 + V_61 ) ;
switch ( V_74 ) {
case V_76 :
if ( ( V_75 & V_76 ) == 0 )
return 0 ;
break;
case V_77 :
if ( V_75 & V_77 )
return 0 ;
break;
default:
return - V_78 ;
}
return - V_79 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_72 * V_73 ,
unsigned int * V_80 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_34 ;
int V_48 ;
int V_16 ;
V_6 -> V_56 = V_81 ;
F_20 ( V_6 -> V_56 , V_2 -> V_43 + V_61 ) ;
F_28 ( V_2 , 1 , & V_73 -> V_82 ) ;
F_20 ( V_6 -> V_41 | V_83 ,
V_2 -> V_43 + V_44 ) ;
V_48 = F_36 ( V_2 , V_31 , V_73 ,
F_34 , V_76 ) ;
if ( V_48 )
return V_48 ;
for ( V_16 = 0 ; V_16 < V_73 -> V_4 ; V_16 ++ ) {
F_20 ( V_6 -> V_41 | V_84 ,
V_2 -> V_43 + V_44 ) ;
V_48 = F_36 ( V_2 , V_31 , V_73 ,
F_34 , V_77 ) ;
if ( V_48 )
return V_48 ;
V_34 = F_25 ( V_2 -> V_43 + V_85 ) ;
V_34 &= V_31 -> V_36 ;
if ( V_6 -> V_37 )
V_34 = F_15 ( V_31 , V_34 ) ;
V_80 [ V_16 ] = V_34 ;
}
return V_16 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_86 * V_87 )
{
const struct V_88 * V_89 = V_2 -> V_90 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_91 = 0 ;
unsigned int V_92 ;
V_91 |= F_38 ( & V_87 -> V_93 , V_94 ) ;
V_91 |= F_38 ( & V_87 -> V_95 ,
V_96 | V_97 ) ;
V_91 |= F_38 ( & V_87 -> V_98 , V_99 ) ;
V_91 |= F_38 ( & V_87 -> V_100 , V_101 ) ;
V_91 |= F_38 ( & V_87 -> V_102 , V_101 | V_103 ) ;
if ( V_91 )
return 1 ;
V_91 |= F_39 ( V_87 -> V_95 ) ;
V_91 |= F_39 ( V_87 -> V_102 ) ;
if ( V_91 )
return 2 ;
V_91 |= F_40 ( & V_87 -> V_104 , 0 ) ;
V_91 |= F_40 ( & V_87 -> V_105 , 0 ) ;
V_91 |= F_41 ( & V_87 -> V_106 , V_107 ) ;
V_91 |= F_42 ( & V_87 -> V_106 , V_89 -> V_108 ) ;
V_91 |= F_40 ( & V_87 -> V_109 ,
V_87 -> V_110 ) ;
if ( V_87 -> V_102 == V_101 )
V_91 |= F_42 ( & V_87 -> V_111 , 1 ) ;
else
V_91 |= F_40 ( & V_87 -> V_111 , 0 ) ;
if ( V_91 )
return 3 ;
V_92 = V_87 -> V_106 ;
V_6 -> V_112 = F_7 ( & V_92 , V_87 -> V_19 ) ;
V_91 |= F_40 ( & V_87 -> V_106 , V_92 ) ;
if ( V_91 )
return 4 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_86 * V_87 = & V_31 -> V_45 -> V_87 ;
int V_48 ;
F_5 ( V_2 ) ;
F_20 ( V_6 -> V_112 , V_2 -> V_43 + V_113 ) ;
V_6 -> V_41 = V_114 ;
if ( V_87 -> V_95 == V_96 )
V_6 -> V_41 = V_115 ;
else
V_6 -> V_41 = V_116 ;
F_20 ( V_6 -> V_41 |
V_42 |
V_117 |
V_118 ,
V_2 -> V_43 + V_44 ) ;
V_6 -> V_12 = V_87 -> V_111 * V_87 -> V_109 ;
V_6 -> V_49 = V_6 -> V_12 ;
V_6 -> V_15 = V_64 ;
V_9 -> V_38 = 0 ;
F_1 ( V_2 , 0 , 0 ) ;
if ( V_6 -> V_12 ) {
F_1 ( V_2 , 1 , 0 ) ;
V_6 -> V_41 |= V_119 ;
F_20 ( V_6 -> V_41 , V_2 -> V_43 + V_44 ) ;
}
V_6 -> V_56 = 0 ;
F_28 ( V_2 , V_87 -> V_110 , V_87 -> V_68 ) ;
V_6 -> V_56 = V_81 | V_120 ;
F_20 ( V_6 -> V_56 , V_2 -> V_43 + V_61 ) ;
F_20 ( V_6 -> V_41 | V_83 ,
V_2 -> V_43 + V_44 ) ;
V_48 = F_36 ( V_2 , V_31 , NULL ,
F_34 , V_76 ) ;
if ( V_48 )
return V_48 ;
if ( V_87 -> V_95 == V_96 ) {
F_20 ( V_6 -> V_41 | V_84 ,
V_2 -> V_43 + V_44 ) ;
} else {
V_6 -> V_41 |= V_121 ;
F_20 ( V_6 -> V_41 , V_2 -> V_43 + V_44 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( V_2 ) ;
V_6 -> V_56 = 0 ;
F_20 ( V_6 -> V_56 , V_2 -> V_43 + V_61 ) ;
V_6 -> V_41 = 0 ;
F_20 ( V_6 -> V_41 | V_118 ,
V_2 -> V_43 + V_44 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_72 * V_73 ,
unsigned int * V_80 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_17 = F_30 ( V_73 -> V_82 ) ;
unsigned int V_71 = F_31 ( V_73 -> V_82 ) ;
int V_16 ;
V_6 -> V_57 |= V_122 | F_46 ( V_17 ) ;
for ( V_16 = 0 ; V_16 < V_73 -> V_4 ; V_16 ++ ) {
unsigned int V_34 = V_80 [ V_16 ] ;
V_31 -> V_123 [ V_17 ] = V_34 ;
if ( F_47 ( V_31 , V_71 ) )
V_34 = F_15 ( V_31 , V_34 ) ;
F_20 ( V_6 -> V_57 , V_2 -> V_43 + V_62 ) ;
F_20 ( V_34 , V_2 -> V_43 + V_124 ) ;
F_20 ( V_6 -> V_41 | V_125 ,
V_2 -> V_43 + V_44 ) ;
}
return V_73 -> V_4 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_86 * V_87 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_91 = 0 ;
unsigned int V_92 ;
V_91 |= F_38 ( & V_87 -> V_93 , V_126 ) ;
V_91 |= F_38 ( & V_87 -> V_95 , V_99 ) ;
V_91 |= F_38 ( & V_87 -> V_98 , V_94 ) ;
V_91 |= F_38 ( & V_87 -> V_100 , V_101 ) ;
V_91 |= F_38 ( & V_87 -> V_102 , V_101 | V_103 ) ;
if ( V_91 )
return 1 ;
V_91 |= F_39 ( V_87 -> V_102 ) ;
if ( V_91 )
return 2 ;
V_91 |= F_40 ( & V_87 -> V_104 , 0 ) ;
V_91 |= F_42 ( & V_87 -> V_105 , 5000 ) ;
V_91 |= F_40 ( & V_87 -> V_106 , 0 ) ;
V_91 |= F_40 ( & V_87 -> V_109 ,
V_87 -> V_110 ) ;
if ( V_87 -> V_102 == V_101 )
V_91 |= F_42 ( & V_87 -> V_111 , 1 ) ;
else
V_91 |= F_40 ( & V_87 -> V_111 , 0 ) ;
if ( V_91 )
return 3 ;
V_92 = V_87 -> V_105 ;
V_6 -> V_112 = F_7 ( & V_92 , V_87 -> V_19 ) ;
V_91 |= F_40 ( & V_87 -> V_105 , V_92 ) ;
if ( V_91 )
return 4 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
unsigned int V_127 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_86 * V_87 = & V_31 -> V_45 -> V_87 ;
if ( V_127 != V_87 -> V_93 )
return - V_78 ;
if ( ! F_16 ( V_2 , V_31 , 0 ) )
return - V_128 ;
if ( ! F_16 ( V_2 , V_31 , 1 ) )
return - V_128 ;
F_20 ( V_6 -> V_41 | V_84 ,
V_2 -> V_43 + V_44 ) ;
V_31 -> V_45 -> V_129 = NULL ;
return 1 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_86 * V_87 = & V_31 -> V_45 -> V_87 ;
F_5 ( V_2 ) ;
V_6 -> V_41 = V_114 |
V_130 |
V_119 ;
F_20 ( V_6 -> V_41 |
V_42 |
V_117 |
V_131 ,
V_2 -> V_43 + V_44 ) ;
V_6 -> V_12 = V_87 -> V_111 * V_87 -> V_110 ;
V_6 -> V_49 = V_6 -> V_12 ;
V_6 -> V_15 = V_132 ;
V_9 -> V_38 = 0 ;
F_20 ( V_6 -> V_112 , V_2 -> V_43 + V_113 ) ;
V_6 -> V_57 &= ( V_133 | V_134 ) ;
V_6 -> V_57 |= ( V_122 |
V_135 |
V_136 ) ;
F_20 ( V_6 -> V_57 , V_2 -> V_43 + V_62 ) ;
V_31 -> V_45 -> V_129 = F_49 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( V_2 ) ;
V_6 -> V_57 &= ( V_133 | V_134 ) ;
F_20 ( V_6 -> V_57 , V_2 -> V_43 + V_62 ) ;
V_6 -> V_41 = 0 ;
F_20 ( V_6 -> V_41 | V_131 ,
V_2 -> V_43 + V_44 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_72 * V_73 ,
unsigned int * V_80 )
{
if ( F_53 ( V_31 , V_80 ) )
F_20 ( V_31 -> V_137 , V_2 -> V_43 + V_138 ) ;
V_80 [ 1 ] = F_25 ( V_2 -> V_43 + V_138 ) ;
return V_73 -> V_4 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_72 * V_73 ,
unsigned int * V_80 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_17 = F_30 ( V_73 -> V_82 ) ;
unsigned int V_139 ;
int V_48 ;
if ( V_17 < 8 )
V_139 = 0x00ff ;
else
V_139 = 0xff00 ;
V_48 = F_55 ( V_2 , V_31 , V_73 , V_80 , V_139 ) ;
if ( V_48 )
return V_48 ;
V_6 -> V_57 &= ~ ( V_133 | V_134 ) ;
if ( V_31 -> V_140 & 0x00ff )
V_6 -> V_57 |= V_133 ;
if ( V_31 -> V_140 & 0xff00 )
V_6 -> V_57 |= V_134 ;
F_20 ( V_6 -> V_57 , V_2 -> V_43 + V_62 ) ;
return V_73 -> V_4 ;
}
static const struct V_141 * F_56 ( int V_142 , int V_143 )
{
if ( V_142 ) {
if ( V_143 < 0 || V_143 >= 2 )
V_143 = 0 ;
return V_144 [ V_143 ] ;
}
if ( V_143 < 0 || V_143 >= 4 )
V_143 = 0 ;
return V_145 [ V_143 ] ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_148 = V_147 -> V_149 [ 1 ] ;
unsigned int V_150 [ 2 ] ;
if ( V_147 -> V_149 [ 2 ] < V_147 -> V_149 [ 3 ] ) {
V_150 [ 0 ] = V_147 -> V_149 [ 2 ] ;
V_150 [ 1 ] = V_147 -> V_149 [ 3 ] ;
} else {
V_150 [ 0 ] = V_147 -> V_149 [ 3 ] ;
V_150 [ 1 ] = V_147 -> V_149 [ 2 ] ;
}
if ( ! V_148 || V_150 [ 0 ] == V_150 [ 1 ] ||
V_150 [ 0 ] < 5 || V_150 [ 0 ] > 7 ||
V_150 [ 1 ] < 5 || V_150 [ 1 ] > 7 )
return;
if ( F_58 ( V_148 , F_24 , 0 , V_2 -> V_151 , V_2 ) )
return;
V_6 -> V_9 = F_59 ( V_2 , 2 , V_150 [ 0 ] , V_150 [ 1 ] ,
V_152 , 0 ) ;
if ( ! V_6 -> V_9 )
F_60 ( V_148 , V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 )
F_62 ( V_6 -> V_9 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
F_20 ( V_153 , V_2 -> V_43 + V_44 ) ;
F_25 ( V_2 -> V_43 + V_61 ) ;
if ( ( ( F_25 ( V_2 -> V_43 + V_61 ) & 0xfff0 ) != 0x7c00 ) ||
( ( F_25 ( V_2 -> V_43 + V_70 ) & 0xf0f0 ) != 0x70f0 ) ||
( ( F_25 ( V_2 -> V_43 + V_62 ) & 0x7c93 ) != 0x7c90 ) ||
( ( F_25 ( V_2 -> V_43 + V_44 ) & 0xf8ff ) != 0x0000 ) ||
( ( F_25 ( V_2 -> V_43 + V_113 ) & 0xff00 ) != 0xf000 ) ) {
F_14 ( V_2 -> V_35 , L_7 ) ;
return - V_154 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
const struct V_88 * V_89 = V_2 -> V_90 ;
struct V_5 * V_6 ;
struct V_30 * V_31 ;
int V_48 ;
V_48 = F_65 ( V_2 , V_147 -> V_149 [ 0 ] , 0x10 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_63 ( V_2 ) ;
if ( V_48 )
return V_48 ;
V_6 = F_66 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_155 ;
F_57 ( V_2 , V_147 ) ;
V_48 = F_67 ( V_2 , 3 ) ;
if ( V_48 )
return V_48 ;
V_31 = & V_2 -> V_156 [ 0 ] ;
V_31 -> type = V_157 ;
V_31 -> V_158 = V_159 ;
if ( ( V_147 -> V_149 [ 4 ] && V_89 -> V_160 ) || V_89 -> V_161 == 0 ) {
V_31 -> V_158 |= V_162 ;
V_31 -> V_163 = V_89 -> V_160 ;
} else {
V_31 -> V_158 |= V_164 ;
V_31 -> V_163 = V_89 -> V_161 ;
}
V_31 -> V_36 = V_89 -> V_165 ;
V_31 -> V_166 = F_56 ( V_89 -> V_142 , V_147 -> V_149 [ 8 ] ) ;
V_6 -> V_37 = V_147 -> V_149 [ 5 ] ? 1 : 0 ;
V_31 -> V_167 = F_35 ;
if ( V_2 -> V_51 ) {
V_2 -> V_53 = V_31 ;
V_31 -> V_158 |= V_168 ;
V_31 -> V_169 = V_31 -> V_163 ;
V_31 -> V_170 = F_37 ;
V_31 -> V_171 = F_43 ;
V_31 -> V_172 = F_44 ;
}
V_31 = & V_2 -> V_156 [ 1 ] ;
if ( V_89 -> V_173 ) {
V_31 -> type = V_174 ;
V_31 -> V_158 = V_175 ;
V_31 -> V_163 = V_89 -> V_173 ;
V_31 -> V_36 = V_89 -> V_176 ;
V_31 -> V_166 = & V_177 ;
V_31 -> V_178 = F_45 ;
if ( V_2 -> V_51 ) {
V_2 -> V_55 = V_31 ;
V_31 -> V_158 |= V_179 ;
V_31 -> V_169 = V_31 -> V_163 ;
V_31 -> V_170 = F_48 ;
V_31 -> V_171 = F_50 ;
V_31 -> V_172 = F_51 ;
}
V_48 = F_68 ( V_31 ) ;
if ( V_48 )
return V_48 ;
} else {
V_31 -> type = V_180 ;
}
V_31 = & V_2 -> V_156 [ 2 ] ;
V_31 -> type = V_181 ;
V_31 -> V_158 = V_159 | V_175 ;
V_31 -> V_163 = 16 ;
V_31 -> V_36 = 1 ;
V_31 -> V_166 = & V_182 ;
V_31 -> V_183 = F_52 ;
V_31 -> V_184 = F_54 ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_61 ( V_2 ) ;
F_70 ( V_2 ) ;
}
