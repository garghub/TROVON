static void F_1 ( unsigned int V_1 )
{
int V_2 ;
F_2 ( V_3 L_1 ) ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
if ( V_1 & ( 1 << V_2 ) )
F_2 ( V_4 L_2 , V_5 [ V_2 ] ) ;
}
F_2 ( V_4 L_3 ) ;
}
static void F_3 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
int V_2 ;
unsigned int V_12 = 0 ;
F_4 ( V_8 , V_10 -> V_13 + V_14 ) ;
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ ) {
V_12 = F_5 ( V_10 -> V_13 + V_14 ) ;
if ( ( V_12 & V_16 ) != V_17 )
break;
F_6 ( 1 ) ;
}
if ( ( V_12 & V_16 ) != V_18 )
F_7 ( V_7 -> V_19 , L_4 ,
V_20 , V_12 ) ;
}
static unsigned int F_8 ( struct V_6 * V_7 ,
unsigned int V_21 , unsigned int V_22 ,
unsigned int V_23 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_4 ( V_21 , V_10 -> V_13 + V_24 ) ;
F_4 ( V_22 , V_10 -> V_13 + F_9 ( 0 ) ) ;
F_4 ( V_23 , V_10 -> V_13 + F_9 ( 1 ) ) ;
F_3 ( V_7 , V_25 ) ;
return F_5 ( V_10 -> V_13 + F_9 ( 2 ) ) ;
}
static void F_10 ( struct V_6 * V_7 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_26 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_4 ( V_21 , V_10 -> V_13 + V_24 ) ;
F_4 ( V_22 , V_10 -> V_13 + F_9 ( 0 ) ) ;
F_4 ( 0 , V_10 -> V_13 + F_9 ( 1 ) ) ;
F_4 ( V_26 , V_10 -> V_13 + F_9 ( 2 ) ) ;
F_3 ( V_7 , V_27 ) ;
}
static void F_11 ( struct V_6 * V_7 ,
struct V_28 * V_29 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
int V_30 ;
int V_31 ;
int V_32 ;
int V_2 ;
unsigned short V_26 ;
V_30 = F_5 ( V_10 -> V_13 + V_33 ) ;
V_32 = V_30 - V_10 -> V_34 ;
if ( V_32 < 0 )
V_32 += V_35 ;
V_31 = V_10 -> V_36 ;
for ( V_2 = 0 ; V_2 < V_32 ; V_2 ++ ) {
V_26 = F_5 ( V_10 -> V_13 + V_37 + V_31 ) ;
F_12 ( V_29 -> V_38 , V_26 ) ;
V_31 ++ ;
if ( V_31 >= V_35 )
V_31 = 0 ;
}
V_10 -> V_36 = V_31 ;
F_4 ( V_31 , V_10 -> V_13 + V_39 ) ;
}
static int F_13 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_4 ( V_40 , V_10 -> V_13 + V_24 ) ;
F_3 ( V_7 , V_41 ) ;
F_4 ( 0 , V_10 -> V_13 + V_42 ) ;
return 0 ;
}
static T_1 F_14 ( int V_43 , void * V_44 )
{
struct V_6 * V_7 = V_44 ;
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_28 * V_29 ;
unsigned int V_12 ;
if ( ! V_7 -> V_45 )
return V_46 ;
V_29 = & V_7 -> V_47 [ 0 ] ;
V_12 = F_5 ( V_10 -> V_13 + V_48 ) ;
#ifdef F_15
F_1 ( V_12 ) ;
#endif
if ( V_12 & V_49 ) {
F_11 ( V_7 , V_29 ) ;
V_29 -> V_38 -> V_50 |= V_51 ;
}
if ( V_12 & ( V_52 | V_53 ) )
V_29 -> V_38 -> V_50 |= V_54 | V_55 ;
V_56 ++ ;
if ( V_56 >= 10 ) {
F_13 ( V_7 , V_29 ) ;
V_29 -> V_38 -> V_50 |= V_55 ;
}
F_16 ( V_7 , V_29 ) ;
return V_57 ;
}
static int F_17 ( unsigned int V_58 , unsigned int * V_59 ,
unsigned int V_60 )
{
int V_61 , V_62 , V_63 ;
for ( V_63 = 0 ; V_63 < 16 ; V_63 ++ ) {
V_62 = V_58 * ( V_63 + 1 ) ;
switch ( V_60 ) {
case V_64 :
default:
V_61 = ( * V_59 + V_62 / 2 ) / V_62 ;
break;
case V_65 :
V_61 = ( * V_59 ) / V_62 ;
break;
case V_66 :
V_61 = ( * V_59 ) / V_62 ;
break;
}
if ( V_61 < 65536 ) {
* V_59 = V_61 * V_62 ;
return ( V_63 << 16 ) | ( V_61 ) ;
}
}
V_63 = 15 ;
V_62 = V_58 * ( 1 << V_63 ) ;
V_61 = 65535 ;
* V_59 = V_61 * V_62 ;
return ( V_63 << 16 ) | ( V_61 ) ;
}
static int F_18 ( struct V_6 * V_7 ,
struct V_28 * V_29 , struct V_67 * V_8 )
{
const struct V_68 * V_69 = F_19 ( V_7 ) ;
int V_70 = 0 ;
int V_71 ;
V_70 |= F_20 ( & V_8 -> V_72 , V_73 ) ;
V_70 |= F_20 ( & V_8 -> V_74 , V_75 ) ;
V_70 |= F_20 ( & V_8 -> V_76 , V_75 ) ;
V_70 |= F_20 ( & V_8 -> V_77 , V_78 ) ;
V_70 |= F_20 ( & V_8 -> V_79 , V_78 ) ;
if ( V_70 )
return 1 ;
if ( V_70 )
return 2 ;
V_70 |= F_21 ( & V_8 -> V_80 , 0 ) ;
if ( V_8 -> V_74 == V_75 ) {
V_70 |= F_22 ( & V_8 -> V_81 ,
V_69 -> V_82 ) ;
V_70 |= F_23 ( & V_8 -> V_81 ,
100 * 16 * 65535 ) ;
}
if ( V_8 -> V_76 == V_75 ) {
V_70 |= F_22 ( & V_8 -> V_83 ,
V_69 -> V_82 ) ;
V_70 |= F_23 ( & V_8 -> V_83 ,
50 * 16 * 65535 ) ;
}
V_70 |= F_21 ( & V_8 -> V_84 , V_8 -> V_85 ) ;
if ( V_8 -> V_79 == V_78 )
V_70 |= F_23 ( & V_8 -> V_86 , 0x00ffffff ) ;
else
V_70 |= F_21 ( & V_8 -> V_86 , 0 ) ;
if ( V_70 )
return 3 ;
if ( V_8 -> V_74 == V_75 ) {
V_71 = V_8 -> V_81 ;
F_17 ( 100 , & V_8 -> V_81 ,
V_8 -> V_1 & V_87 ) ;
if ( V_71 != V_8 -> V_81 )
V_70 ++ ;
}
if ( V_8 -> V_76 == V_75 ) {
V_71 = V_8 -> V_83 ;
F_17 ( 50 , & V_8 -> V_83 ,
V_8 -> V_1 & V_87 ) ;
if ( V_71 != V_8 -> V_83 )
V_70 ++ ;
if ( V_8 -> V_74 == V_75 &&
V_8 -> V_81 <
V_8 -> V_83 * V_8 -> V_84 ) {
V_8 -> V_81 =
V_8 -> V_83 * V_8 -> V_84 ;
V_70 ++ ;
}
}
if ( V_70 )
return 4 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_67 * V_8 = & V_29 -> V_38 -> V_8 ;
int V_2 ;
unsigned int V_22 , V_88 , V_89 ;
unsigned int V_61 ;
unsigned int V_90 ;
unsigned int V_91 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_85 ; V_2 ++ ) {
V_22 = F_25 ( V_8 -> V_92 [ V_2 ] ) ;
V_88 = F_26 ( V_8 -> V_92 [ V_2 ] ) ;
F_4 ( ( V_88 << 6 ) | V_22 ,
V_10 -> V_13 + V_37 + V_2 ) ;
}
V_89 = F_27 ( V_8 -> V_92 [ 0 ] ) ;
F_4 ( V_8 -> V_84 , V_10 -> V_13 + F_9 ( 0 ) ) ;
if ( V_8 -> V_76 == V_75 ) {
V_61 = F_17 ( 50 , & V_8 -> V_83 ,
V_8 -> V_1 & V_87 ) ;
F_4 ( ( V_61 >> 16 ) , V_10 -> V_13 + F_9 ( 1 ) ) ;
F_4 ( ( V_61 & 0xffff ) , V_10 -> V_13 + F_9 ( 2 ) ) ;
}
if ( V_8 -> V_74 == V_75 ) {
V_90 = F_17 ( 100 , & V_8 -> V_81 ,
V_8 -> V_1 & V_87 ) ;
F_4 ( ( V_90 >> 16 ) , V_10 -> V_13 + F_9 ( 3 ) ) ;
F_4 ( ( V_90 & 0xffff ) , V_10 -> V_13 + F_9 ( 4 ) ) ;
}
V_91 = V_93 | 0 | 0 ;
F_4 ( V_91 , V_10 -> V_13 + F_9 ( 5 ) ) ;
F_4 ( V_89 == V_94 , V_10 -> V_13 + F_9 ( 6 ) ) ;
F_4 ( V_35 / 2 , V_10 -> V_13 + F_9 ( 7 ) ) ;
F_4 ( V_40 , V_10 -> V_13 + V_24 ) ;
F_3 ( V_7 , V_95 ) ;
F_4 ( V_49 | V_52 | V_53 ,
V_10 -> V_13 + V_42 ) ;
V_56 = 0 ;
F_4 ( V_40 , V_10 -> V_13 + V_24 ) ;
F_3 ( V_7 , V_96 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_97 * V_98 , unsigned int * V_26 )
{
int V_2 ;
unsigned int V_22 , V_23 , V_89 ;
V_22 = F_25 ( V_98 -> V_99 ) ;
V_23 = F_26 ( V_98 -> V_99 ) ;
V_89 = F_27 ( V_98 -> V_99 ) ;
for ( V_2 = 0 ; V_2 < V_98 -> V_100 ; V_2 ++ )
V_26 [ V_2 ] = F_8 ( V_7 , V_40 , V_22 , V_23 ) ;
return V_2 ;
}
static int F_29 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_97 * V_98 , unsigned int * V_26 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
int V_2 ;
unsigned int V_22 ;
V_22 = F_25 ( V_98 -> V_99 ) ;
for ( V_2 = 0 ; V_2 < V_98 -> V_100 ; V_2 ++ ) {
F_10 ( V_7 , V_101 , V_22 , V_26 [ V_2 ] ) ;
V_10 -> V_102 [ V_22 ] = V_26 [ V_2 ] ;
}
return V_2 ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_97 * V_98 , unsigned int * V_26 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
int V_2 ;
unsigned int V_22 ;
V_22 = F_25 ( V_98 -> V_99 ) ;
for ( V_2 = 0 ; V_2 < V_98 -> V_100 ; V_2 ++ )
V_26 [ V_2 ] = V_10 -> V_102 [ V_22 ] ;
return V_2 ;
}
static void F_31 ( struct V_6 * V_7 , int V_103 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_4 ( V_104 , V_10 -> V_13 + V_24 ) ;
F_4 ( V_103 , V_10 -> V_13 + F_9 ( 0 ) ) ;
#if 0
writew(0, devpriv->io_addr + DPR_Params(1));
writew(0, devpriv->io_addr + DPR_Params(2));
#endif
F_3 ( V_7 , V_95 ) ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_97 * V_98 ,
unsigned int * V_26 )
{
unsigned int V_22 = F_25 ( V_98 -> V_99 ) ;
unsigned int V_105 ;
int V_106 ;
if ( V_22 < 4 )
V_105 = 0x0f ;
else
V_105 = 0xf0 ;
V_106 = F_33 ( V_7 , V_29 , V_98 , V_26 , V_105 ) ;
if ( V_106 )
return V_106 ;
F_31 ( V_7 , ( V_29 -> V_107 & 0x01 ) | ( ( V_29 -> V_107 & 0x10 ) >> 3 ) ) ;
return V_98 -> V_100 ;
}
static int F_34 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_97 * V_98 ,
unsigned int * V_26 )
{
if ( F_35 ( V_29 , V_26 ) )
F_10 ( V_7 , V_104 , 0 , V_29 -> V_108 ) ;
V_26 [ 1 ] = F_8 ( V_7 , V_109 , 0 , 0 ) ;
return V_98 -> V_100 ;
}
static int F_36 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_97 * V_98 , unsigned int * V_26 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
unsigned int V_110 = F_25 ( V_98 -> V_99 ) ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_98 -> V_100 ; V_2 ++ ) {
F_4 ( V_111 , V_10 -> V_13 + V_24 ) ;
F_4 ( V_110 , V_10 -> V_13 + F_9 ( 0 ) ) ;
F_4 ( 1 , V_10 -> V_13 + F_9 ( 1 ) ) ;
F_3 ( V_7 , V_112 ) ;
V_26 [ V_2 ] = F_5 ( V_10 -> V_13 + F_9 ( 2 ) ) ;
}
return V_2 ;
}
static int F_37 ( struct V_6 * V_7 ,
unsigned long V_113 )
{
struct V_114 * V_115 = F_38 ( V_7 ) ;
const struct V_68 * V_69 = NULL ;
struct V_9 * V_10 ;
struct V_28 * V_29 ;
int V_106 = 0 ;
if ( V_113 < F_39 ( V_116 ) )
V_69 = & V_116 [ V_113 ] ;
if ( ! V_69 )
return - V_117 ;
V_7 -> V_118 = V_69 ;
V_7 -> V_119 = V_69 -> V_120 ;
V_10 = F_40 ( V_7 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_121 ;
V_106 = F_41 ( V_7 ) ;
if ( V_106 < 0 )
return V_106 ;
V_10 -> V_13 = F_42 ( V_115 , 0 ) ;
if ( ! V_10 -> V_13 )
return - V_121 ;
V_106 = F_43 ( V_115 -> V_43 , F_14 , V_122 ,
V_7 -> V_119 , V_7 ) ;
if ( V_106 )
return V_106 ;
V_7 -> V_43 = V_115 -> V_43 ;
V_106 = F_44 ( V_7 , 4 ) ;
if ( V_106 )
return V_106 ;
V_29 = & V_7 -> V_47 [ 0 ] ;
V_7 -> V_123 = V_29 ;
V_29 -> type = V_124 ;
V_29 -> V_125 = V_126 | V_127 | V_128 | V_129 ;
V_29 -> V_130 = V_69 -> V_131 ;
V_29 -> V_132 = F_28 ;
V_29 -> V_133 = ( 1 << V_69 -> V_134 ) - 1 ;
V_29 -> V_135 = 512 ;
V_29 -> V_136 = & V_137 ;
V_29 -> V_138 = F_24 ;
V_29 -> V_139 = F_18 ;
V_29 -> V_140 = F_13 ;
V_29 = & V_7 -> V_47 [ 1 ] ;
V_29 -> type = V_141 ;
V_29 -> V_125 = V_142 ;
V_29 -> V_130 = 2 ;
V_29 -> V_132 = F_30 ;
V_29 -> V_143 = F_29 ;
V_29 -> V_133 = ( 1 << V_69 -> V_144 ) - 1 ;
V_29 -> V_135 = 1 ;
V_29 -> V_136 = & V_145 ;
V_29 = & V_7 -> V_47 [ 2 ] ;
V_29 -> type = V_146 ;
V_29 -> V_125 = V_126 | V_142 ;
V_29 -> V_130 = 8 ;
V_29 -> V_147 = F_32 ;
V_29 -> V_148 = F_34 ;
V_29 -> V_133 = 1 ;
V_29 -> V_135 = 8 ;
V_29 -> V_136 = & V_149 ;
V_29 = & V_7 -> V_47 [ 3 ] ;
V_29 -> type = V_150 ;
V_29 -> V_125 = V_126 ;
V_29 -> V_130 = 0x1000 ;
V_29 -> V_132 = F_36 ;
V_29 -> V_133 = 0xff ;
V_29 -> V_135 = 1 ;
V_29 -> V_136 = & V_151 ;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_PROC;
#endif
F_45 ( V_7 -> V_19 , L_5 , V_7 -> V_119 ) ;
return 0 ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( V_7 -> V_43 )
F_47 ( V_7 -> V_43 , V_7 ) ;
if ( V_10 ) {
if ( V_10 -> V_13 )
F_48 ( V_10 -> V_13 ) ;
}
F_49 ( V_7 ) ;
}
static int F_50 ( struct V_114 * V_7 ,
const struct V_152 * V_153 )
{
return F_51 ( V_7 , & V_154 , V_153 -> V_155 ) ;
}
