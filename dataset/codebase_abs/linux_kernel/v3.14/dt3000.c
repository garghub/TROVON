static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_8 = 0 ;
F_2 ( V_3 , V_5 -> V_9 + V_10 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
V_8 = F_3 ( V_5 -> V_9 + V_10 ) ;
if ( ( V_8 & V_12 ) != V_13 )
break;
F_4 ( 1 ) ;
}
if ( ( V_8 & V_12 ) != V_14 )
F_5 ( V_2 -> V_15 , L_1 ,
V_16 , V_8 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_17 , unsigned int V_18 ,
unsigned int V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_17 , V_5 -> V_9 + V_20 ) ;
F_2 ( V_18 , V_5 -> V_9 + F_7 ( 0 ) ) ;
F_2 ( V_19 , V_5 -> V_9 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_21 ) ;
return F_3 ( V_5 -> V_9 + F_7 ( 2 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_17 ,
unsigned int V_18 , unsigned int V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_17 , V_5 -> V_9 + V_20 ) ;
F_2 ( V_18 , V_5 -> V_9 + F_7 ( 0 ) ) ;
F_2 ( 0 , V_5 -> V_9 + F_7 ( 1 ) ) ;
F_2 ( V_22 , V_5 -> V_9 + F_7 ( 2 ) ) ;
F_1 ( V_2 , V_23 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_7 ;
unsigned short V_22 ;
V_26 = F_3 ( V_5 -> V_9 + V_29 ) ;
V_28 = V_26 - V_5 -> V_30 ;
if ( V_28 < 0 )
V_28 += V_31 ;
V_27 = V_5 -> V_32 ;
for ( V_7 = 0 ; V_7 < V_28 ; V_7 ++ ) {
V_22 = F_3 ( V_5 -> V_9 + V_33 + V_27 ) ;
F_10 ( V_25 -> V_34 , V_22 ) ;
V_27 ++ ;
if ( V_27 >= V_31 )
V_27 = 0 ;
}
V_5 -> V_32 = V_27 ;
F_2 ( V_27 , V_5 -> V_9 + V_35 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_36 , V_5 -> V_9 + V_20 ) ;
F_1 ( V_2 , V_37 ) ;
F_2 ( 0 , V_5 -> V_9 + V_38 ) ;
return 0 ;
}
static T_1 F_12 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_24 * V_25 = V_2 -> V_41 ;
unsigned int V_8 ;
if ( ! V_2 -> V_42 )
return V_43 ;
V_8 = F_3 ( V_5 -> V_9 + V_44 ) ;
if ( V_8 & V_45 ) {
F_9 ( V_2 , V_25 ) ;
V_25 -> V_34 -> V_46 |= V_47 ;
}
if ( V_8 & ( V_48 | V_49 ) )
V_25 -> V_34 -> V_46 |= V_50 | V_51 ;
V_52 ++ ;
if ( V_52 >= 10 ) {
F_11 ( V_2 , V_25 ) ;
V_25 -> V_34 -> V_46 |= V_51 ;
}
F_13 ( V_2 , V_25 ) ;
return V_53 ;
}
static int F_14 ( unsigned int V_54 , unsigned int * V_55 ,
unsigned int V_56 )
{
int V_57 , V_58 , V_59 ;
for ( V_59 = 0 ; V_59 < 16 ; V_59 ++ ) {
V_58 = V_54 * ( V_59 + 1 ) ;
switch ( V_56 ) {
case V_60 :
default:
V_57 = ( * V_55 + V_58 / 2 ) / V_58 ;
break;
case V_61 :
V_57 = ( * V_55 ) / V_58 ;
break;
case V_62 :
V_57 = ( * V_55 ) / V_58 ;
break;
}
if ( V_57 < 65536 ) {
* V_55 = V_57 * V_58 ;
return ( V_59 << 16 ) | ( V_57 ) ;
}
}
V_59 = 15 ;
V_58 = V_54 * ( 1 << V_59 ) ;
V_57 = 65535 ;
* V_55 = V_57 * V_58 ;
return ( V_59 << 16 ) | ( V_57 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_63 * V_3 )
{
const struct V_64 * V_65 = F_16 ( V_2 ) ;
int V_66 = 0 ;
int V_67 ;
V_66 |= F_17 ( & V_3 -> V_68 , V_69 ) ;
V_66 |= F_17 ( & V_3 -> V_70 , V_71 ) ;
V_66 |= F_17 ( & V_3 -> V_72 , V_71 ) ;
V_66 |= F_17 ( & V_3 -> V_73 , V_74 ) ;
V_66 |= F_17 ( & V_3 -> V_75 , V_74 ) ;
if ( V_66 )
return 1 ;
if ( V_66 )
return 2 ;
V_66 |= F_18 ( & V_3 -> V_76 , 0 ) ;
if ( V_3 -> V_70 == V_71 ) {
V_66 |= F_19 ( & V_3 -> V_77 ,
V_65 -> V_78 ) ;
V_66 |= F_20 ( & V_3 -> V_77 ,
100 * 16 * 65535 ) ;
}
if ( V_3 -> V_72 == V_71 ) {
V_66 |= F_19 ( & V_3 -> V_79 ,
V_65 -> V_78 ) ;
V_66 |= F_20 ( & V_3 -> V_79 ,
50 * 16 * 65535 ) ;
}
V_66 |= F_18 ( & V_3 -> V_80 , V_3 -> V_81 ) ;
if ( V_3 -> V_75 == V_74 )
V_66 |= F_20 ( & V_3 -> V_82 , 0x00ffffff ) ;
else
V_66 |= F_18 ( & V_3 -> V_82 , 0 ) ;
if ( V_66 )
return 3 ;
if ( V_3 -> V_70 == V_71 ) {
V_67 = V_3 -> V_77 ;
F_14 ( 100 , & V_3 -> V_77 ,
V_3 -> V_83 & V_84 ) ;
if ( V_67 != V_3 -> V_77 )
V_66 ++ ;
}
if ( V_3 -> V_72 == V_71 ) {
V_67 = V_3 -> V_79 ;
F_14 ( 50 , & V_3 -> V_79 ,
V_3 -> V_83 & V_84 ) ;
if ( V_67 != V_3 -> V_79 )
V_66 ++ ;
if ( V_3 -> V_70 == V_71 &&
V_3 -> V_77 <
V_3 -> V_79 * V_3 -> V_80 ) {
V_3 -> V_77 =
V_3 -> V_79 * V_3 -> V_80 ;
V_66 ++ ;
}
}
if ( V_66 )
return 4 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_63 * V_3 = & V_25 -> V_34 -> V_3 ;
int V_7 ;
unsigned int V_18 , V_85 , V_86 ;
unsigned int V_57 ;
unsigned int V_87 ;
unsigned int V_88 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_81 ; V_7 ++ ) {
V_18 = F_22 ( V_3 -> V_89 [ V_7 ] ) ;
V_85 = F_23 ( V_3 -> V_89 [ V_7 ] ) ;
F_2 ( ( V_85 << 6 ) | V_18 ,
V_5 -> V_9 + V_33 + V_7 ) ;
}
V_86 = F_24 ( V_3 -> V_89 [ 0 ] ) ;
F_2 ( V_3 -> V_80 , V_5 -> V_9 + F_7 ( 0 ) ) ;
if ( V_3 -> V_72 == V_71 ) {
V_57 = F_14 ( 50 , & V_3 -> V_79 ,
V_3 -> V_83 & V_84 ) ;
F_2 ( ( V_57 >> 16 ) , V_5 -> V_9 + F_7 ( 1 ) ) ;
F_2 ( ( V_57 & 0xffff ) , V_5 -> V_9 + F_7 ( 2 ) ) ;
}
if ( V_3 -> V_70 == V_71 ) {
V_87 = F_14 ( 100 , & V_3 -> V_77 ,
V_3 -> V_83 & V_84 ) ;
F_2 ( ( V_87 >> 16 ) , V_5 -> V_9 + F_7 ( 3 ) ) ;
F_2 ( ( V_87 & 0xffff ) , V_5 -> V_9 + F_7 ( 4 ) ) ;
}
V_88 = V_90 | 0 | 0 ;
F_2 ( V_88 , V_5 -> V_9 + F_7 ( 5 ) ) ;
F_2 ( V_86 == V_91 , V_5 -> V_9 + F_7 ( 6 ) ) ;
F_2 ( V_31 / 2 , V_5 -> V_9 + F_7 ( 7 ) ) ;
F_2 ( V_36 , V_5 -> V_9 + V_20 ) ;
F_1 ( V_2 , V_92 ) ;
F_2 ( V_45 | V_48 | V_49 ,
V_5 -> V_9 + V_38 ) ;
V_52 = 0 ;
F_2 ( V_36 , V_5 -> V_9 + V_20 ) ;
F_1 ( V_2 , V_93 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_94 * V_95 , unsigned int * V_22 )
{
int V_7 ;
unsigned int V_18 , V_19 , V_86 ;
V_18 = F_22 ( V_95 -> V_96 ) ;
V_19 = F_23 ( V_95 -> V_96 ) ;
V_86 = F_24 ( V_95 -> V_96 ) ;
for ( V_7 = 0 ; V_7 < V_95 -> V_97 ; V_7 ++ )
V_22 [ V_7 ] = F_6 ( V_2 , V_36 , V_18 , V_19 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_94 * V_95 , unsigned int * V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_18 ;
V_18 = F_22 ( V_95 -> V_96 ) ;
for ( V_7 = 0 ; V_7 < V_95 -> V_97 ; V_7 ++ ) {
F_8 ( V_2 , V_98 , V_18 , V_22 [ V_7 ] ) ;
V_5 -> V_99 [ V_18 ] = V_22 [ V_7 ] ;
}
return V_7 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_94 * V_95 , unsigned int * V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_18 ;
V_18 = F_22 ( V_95 -> V_96 ) ;
for ( V_7 = 0 ; V_7 < V_95 -> V_97 ; V_7 ++ )
V_22 [ V_7 ] = V_5 -> V_99 [ V_18 ] ;
return V_7 ;
}
static void F_28 ( struct V_1 * V_2 , int V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_101 , V_5 -> V_9 + V_20 ) ;
F_2 ( V_100 , V_5 -> V_9 + F_7 ( 0 ) ) ;
#if 0
writew(0, devpriv->io_addr + DPR_Params(1));
writew(0, devpriv->io_addr + DPR_Params(2));
#endif
F_1 ( V_2 , V_92 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_94 * V_95 ,
unsigned int * V_22 )
{
unsigned int V_18 = F_22 ( V_95 -> V_96 ) ;
unsigned int V_102 ;
int V_103 ;
if ( V_18 < 4 )
V_102 = 0x0f ;
else
V_102 = 0xf0 ;
V_103 = F_30 ( V_2 , V_25 , V_95 , V_22 , V_102 ) ;
if ( V_103 )
return V_103 ;
F_28 ( V_2 , ( V_25 -> V_104 & 0x01 ) | ( ( V_25 -> V_104 & 0x10 ) >> 3 ) ) ;
return V_95 -> V_97 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_94 * V_95 ,
unsigned int * V_22 )
{
if ( F_32 ( V_25 , V_22 ) )
F_8 ( V_2 , V_101 , 0 , V_25 -> V_105 ) ;
V_22 [ 1 ] = F_6 ( V_2 , V_106 , 0 , 0 ) ;
return V_95 -> V_97 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_94 * V_95 , unsigned int * V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_107 = F_22 ( V_95 -> V_96 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_95 -> V_97 ; V_7 ++ ) {
F_2 ( V_108 , V_5 -> V_9 + V_20 ) ;
F_2 ( V_107 , V_5 -> V_9 + F_7 ( 0 ) ) ;
F_2 ( 1 , V_5 -> V_9 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_109 ) ;
V_22 [ V_7 ] = F_3 ( V_5 -> V_9 + F_7 ( 2 ) ) ;
}
return V_7 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned long V_110 )
{
struct V_111 * V_112 = F_35 ( V_2 ) ;
const struct V_64 * V_65 = NULL ;
struct V_4 * V_5 ;
struct V_24 * V_25 ;
int V_103 = 0 ;
if ( V_110 < F_36 ( V_113 ) )
V_65 = & V_113 [ V_110 ] ;
if ( ! V_65 )
return - V_114 ;
V_2 -> V_115 = V_65 ;
V_2 -> V_116 = V_65 -> V_117 ;
V_5 = F_37 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_118 ;
V_103 = F_38 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_5 -> V_9 = F_39 ( V_112 , 0 ) ;
if ( ! V_5 -> V_9 )
return - V_118 ;
if ( V_112 -> V_39 ) {
V_103 = F_40 ( V_112 -> V_39 , F_12 , V_119 ,
V_2 -> V_116 , V_2 ) ;
if ( V_103 == 0 )
V_2 -> V_39 = V_112 -> V_39 ;
}
V_103 = F_41 ( V_2 , 4 ) ;
if ( V_103 )
return V_103 ;
V_25 = & V_2 -> V_120 [ 0 ] ;
V_25 -> type = V_121 ;
V_25 -> V_122 = V_123 | V_124 | V_125 ;
V_25 -> V_126 = V_65 -> V_127 ;
V_25 -> V_128 = F_25 ;
V_25 -> V_129 = ( 1 << V_65 -> V_130 ) - 1 ;
V_25 -> V_131 = & V_132 ;
if ( V_2 -> V_39 ) {
V_2 -> V_41 = V_25 ;
V_25 -> V_122 |= V_133 ;
V_25 -> V_134 = 512 ;
V_25 -> V_135 = F_21 ;
V_25 -> V_136 = F_15 ;
V_25 -> V_137 = F_11 ;
}
V_25 = & V_2 -> V_120 [ 1 ] ;
V_25 -> type = V_138 ;
V_25 -> V_122 = V_139 ;
V_25 -> V_126 = 2 ;
V_25 -> V_128 = F_27 ;
V_25 -> V_140 = F_26 ;
V_25 -> V_129 = ( 1 << V_65 -> V_141 ) - 1 ;
V_25 -> V_134 = 1 ;
V_25 -> V_131 = & V_142 ;
V_25 = & V_2 -> V_120 [ 2 ] ;
V_25 -> type = V_143 ;
V_25 -> V_122 = V_123 | V_139 ;
V_25 -> V_126 = 8 ;
V_25 -> V_144 = F_29 ;
V_25 -> V_145 = F_31 ;
V_25 -> V_129 = 1 ;
V_25 -> V_134 = 8 ;
V_25 -> V_131 = & V_146 ;
V_25 = & V_2 -> V_120 [ 3 ] ;
V_25 -> type = V_147 ;
V_25 -> V_122 = V_123 ;
V_25 -> V_126 = 0x1000 ;
V_25 -> V_128 = F_33 ;
V_25 -> V_129 = 0xff ;
V_25 -> V_134 = 1 ;
V_25 -> V_131 = & V_148 ;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_PROC;
#endif
F_42 ( V_2 -> V_15 , L_2 , V_2 -> V_116 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_2 -> V_39 )
F_44 ( V_2 -> V_39 , V_2 ) ;
if ( V_5 ) {
if ( V_5 -> V_9 )
F_45 ( V_5 -> V_9 ) ;
}
F_46 ( V_2 ) ;
}
static int F_47 ( struct V_111 * V_2 ,
const struct V_149 * V_150 )
{
return F_48 ( V_2 , & V_151 , V_150 -> V_152 ) ;
}
