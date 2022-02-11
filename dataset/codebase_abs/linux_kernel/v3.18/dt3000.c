static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
unsigned int V_5 = 0 ;
F_2 ( V_3 , V_2 -> V_6 + V_7 ) ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ ) {
V_5 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( ( V_5 & V_9 ) != V_10 )
break;
F_4 ( 1 ) ;
}
if ( ( V_5 & V_9 ) != V_11 )
F_5 ( V_2 -> V_12 , L_1 ,
V_13 , V_5 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_15 ,
unsigned int V_16 )
{
F_2 ( V_14 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_15 , V_2 -> V_6 + F_7 ( 0 ) ) ;
F_2 ( V_16 , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_18 ) ;
return F_3 ( V_2 -> V_6 + F_7 ( 2 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_19 )
{
F_2 ( V_14 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_15 , V_2 -> V_6 + F_7 ( 0 ) ) ;
F_2 ( 0 , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_2 ( V_19 , V_2 -> V_6 + F_7 ( 2 ) ) ;
F_1 ( V_2 , V_20 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_2 -> V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_4 ;
unsigned short V_19 ;
V_26 = F_3 ( V_2 -> V_6 + V_29 ) ;
V_28 = V_26 - V_24 -> V_30 ;
if ( V_28 < 0 )
V_28 += V_31 ;
V_27 = V_24 -> V_32 ;
for ( V_4 = 0 ; V_4 < V_28 ; V_4 ++ ) {
V_19 = F_3 ( V_2 -> V_6 + V_33 + V_27 ) ;
F_10 ( V_22 , V_19 ) ;
V_27 ++ ;
if ( V_27 >= V_31 )
V_27 = 0 ;
}
V_24 -> V_32 = V_27 ;
F_2 ( V_27 , V_2 -> V_6 + V_34 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_2 ( V_35 , V_2 -> V_6 + V_17 ) ;
F_1 ( V_2 , V_36 ) ;
F_2 ( 0 , V_2 -> V_6 + V_37 ) ;
return 0 ;
}
static T_1 F_12 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
struct V_21 * V_22 = V_2 -> V_40 ;
unsigned int V_5 ;
if ( ! V_2 -> V_41 )
return V_42 ;
V_5 = F_3 ( V_2 -> V_6 + V_43 ) ;
if ( V_5 & V_44 ) {
F_9 ( V_2 , V_22 ) ;
V_22 -> V_45 -> V_46 |= V_47 ;
}
if ( V_5 & ( V_48 | V_49 ) )
V_22 -> V_45 -> V_46 |= V_50 | V_51 ;
V_52 ++ ;
if ( V_52 >= 10 )
V_22 -> V_45 -> V_46 |= V_51 ;
F_13 ( V_2 , V_22 ) ;
return V_53 ;
}
static int F_14 ( unsigned int V_54 , unsigned int * V_55 ,
unsigned int V_56 )
{
int V_57 , V_58 , V_59 ;
for ( V_59 = 0 ; V_59 < 16 ; V_59 ++ ) {
V_58 = V_54 * ( V_59 + 1 ) ;
switch ( V_56 & V_60 ) {
case V_61 :
default:
V_57 = ( * V_55 + V_58 / 2 ) / V_58 ;
break;
case V_62 :
V_57 = ( * V_55 ) / V_58 ;
break;
case V_63 :
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
struct V_21 * V_22 , struct V_64 * V_3 )
{
const struct V_65 * V_66 = V_2 -> V_67 ;
int V_68 = 0 ;
unsigned int V_69 ;
V_68 |= F_16 ( & V_3 -> V_70 , V_71 ) ;
V_68 |= F_16 ( & V_3 -> V_72 , V_73 ) ;
V_68 |= F_16 ( & V_3 -> V_74 , V_73 ) ;
V_68 |= F_16 ( & V_3 -> V_75 , V_76 ) ;
V_68 |= F_16 ( & V_3 -> V_77 , V_76 ) ;
if ( V_68 )
return 1 ;
V_68 |= F_17 ( & V_3 -> V_78 , 0 ) ;
if ( V_3 -> V_72 == V_73 ) {
V_68 |= F_18 ( & V_3 -> V_79 ,
V_66 -> V_80 ) ;
V_68 |= F_19 ( & V_3 -> V_79 ,
100 * 16 * 65535 ) ;
}
if ( V_3 -> V_74 == V_73 ) {
V_68 |= F_18 ( & V_3 -> V_81 ,
V_66 -> V_80 ) ;
V_68 |= F_19 ( & V_3 -> V_81 ,
50 * 16 * 65535 ) ;
}
V_68 |= F_17 ( & V_3 -> V_82 , V_3 -> V_83 ) ;
if ( V_3 -> V_77 == V_76 )
V_68 |= F_19 ( & V_3 -> V_84 , 0x00ffffff ) ;
else
V_68 |= F_17 ( & V_3 -> V_84 , 0 ) ;
if ( V_68 )
return 3 ;
if ( V_3 -> V_72 == V_73 ) {
V_69 = V_3 -> V_79 ;
F_14 ( 100 , & V_69 , V_3 -> V_56 ) ;
V_68 |= F_17 ( & V_3 -> V_79 , V_69 ) ;
}
if ( V_3 -> V_74 == V_73 ) {
V_69 = V_3 -> V_81 ;
F_14 ( 50 , & V_69 , V_3 -> V_56 ) ;
V_68 |= F_17 ( & V_3 -> V_81 , V_69 ) ;
if ( V_3 -> V_72 == V_73 ) {
V_69 = V_3 -> V_81 * V_3 -> V_82 ;
V_68 |= F_18 ( & V_3 -> V_79 ,
V_69 ) ;
}
}
if ( V_68 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_64 * V_3 = & V_22 -> V_45 -> V_3 ;
int V_4 ;
unsigned int V_15 , V_85 , V_86 ;
unsigned int V_57 ;
unsigned int V_87 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_83 ; V_4 ++ ) {
V_15 = F_21 ( V_3 -> V_88 [ V_4 ] ) ;
V_85 = F_22 ( V_3 -> V_88 [ V_4 ] ) ;
F_2 ( ( V_85 << 6 ) | V_15 , V_2 -> V_6 + V_33 + V_4 ) ;
}
V_86 = F_23 ( V_3 -> V_88 [ 0 ] ) ;
F_2 ( V_3 -> V_82 , V_2 -> V_6 + F_7 ( 0 ) ) ;
if ( V_3 -> V_74 == V_73 ) {
V_57 = F_14 ( 50 , & V_3 -> V_81 , V_3 -> V_56 ) ;
F_2 ( ( V_57 >> 16 ) , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_2 ( ( V_57 & 0xffff ) , V_2 -> V_6 + F_7 ( 2 ) ) ;
}
if ( V_3 -> V_72 == V_73 ) {
V_87 = F_14 ( 100 , & V_3 -> V_79 ,
V_3 -> V_56 ) ;
F_2 ( ( V_87 >> 16 ) , V_2 -> V_6 + F_7 ( 3 ) ) ;
F_2 ( ( V_87 & 0xffff ) , V_2 -> V_6 + F_7 ( 4 ) ) ;
}
F_2 ( V_89 , V_2 -> V_6 + F_7 ( 5 ) ) ;
F_2 ( V_86 == V_90 , V_2 -> V_6 + F_7 ( 6 ) ) ;
F_2 ( V_31 / 2 , V_2 -> V_6 + F_7 ( 7 ) ) ;
F_2 ( V_35 , V_2 -> V_6 + V_17 ) ;
F_1 ( V_2 , V_91 ) ;
F_2 ( V_44 | V_48 | V_49 ,
V_2 -> V_6 + V_37 ) ;
V_52 = 0 ;
F_2 ( V_35 , V_2 -> V_6 + V_17 ) ;
F_1 ( V_2 , V_92 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_93 * V_94 , unsigned int * V_19 )
{
int V_4 ;
unsigned int V_15 , V_16 , V_86 ;
V_15 = F_21 ( V_94 -> V_95 ) ;
V_16 = F_22 ( V_94 -> V_95 ) ;
V_86 = F_23 ( V_94 -> V_95 ) ;
for ( V_4 = 0 ; V_4 < V_94 -> V_96 ; V_4 ++ )
V_19 [ V_4 ] = F_6 ( V_2 , V_35 , V_15 , V_16 ) ;
return V_4 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
unsigned int V_15 = F_21 ( V_94 -> V_95 ) ;
unsigned int V_97 = V_22 -> V_98 [ V_15 ] ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_94 -> V_96 ; V_4 ++ ) {
V_97 = V_19 [ V_4 ] ;
F_8 ( V_2 , V_99 , V_15 , V_97 ) ;
}
V_22 -> V_98 [ V_15 ] = V_97 ;
return V_94 -> V_96 ;
}
static void F_26 ( struct V_1 * V_2 , int V_100 )
{
F_2 ( V_101 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_100 , V_2 -> V_6 + F_7 ( 0 ) ) ;
#if 0
writew(0, dev->mmio + DPR_Params(1));
writew(0, dev->mmio + DPR_Params(2));
#endif
F_1 ( V_2 , V_91 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
unsigned int V_15 = F_21 ( V_94 -> V_95 ) ;
unsigned int V_102 ;
int V_103 ;
if ( V_15 < 4 )
V_102 = 0x0f ;
else
V_102 = 0xf0 ;
V_103 = F_28 ( V_2 , V_22 , V_94 , V_19 , V_102 ) ;
if ( V_103 )
return V_103 ;
F_26 ( V_2 , ( V_22 -> V_104 & 0x01 ) | ( ( V_22 -> V_104 & 0x10 ) >> 3 ) ) ;
return V_94 -> V_96 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
if ( F_30 ( V_22 , V_19 ) )
F_8 ( V_2 , V_101 , 0 , V_22 -> V_105 ) ;
V_19 [ 1 ] = F_6 ( V_2 , V_106 , 0 , 0 ) ;
return V_94 -> V_96 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_93 * V_94 ,
unsigned int * V_19 )
{
unsigned int V_107 = F_21 ( V_94 -> V_95 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_94 -> V_96 ; V_4 ++ ) {
F_2 ( V_108 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_107 , V_2 -> V_6 + F_7 ( 0 ) ) ;
F_2 ( 1 , V_2 -> V_6 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_109 ) ;
V_19 [ V_4 ] = F_3 ( V_2 -> V_6 + F_7 ( 2 ) ) ;
}
return V_4 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned long V_110 )
{
struct V_111 * V_112 = F_33 ( V_2 ) ;
const struct V_65 * V_66 = NULL ;
struct V_23 * V_24 ;
struct V_21 * V_22 ;
int V_103 = 0 ;
if ( V_110 < F_34 ( V_113 ) )
V_66 = & V_113 [ V_110 ] ;
if ( ! V_66 )
return - V_114 ;
V_2 -> V_67 = V_66 ;
V_2 -> V_115 = V_66 -> V_116 ;
V_24 = F_35 ( V_2 , sizeof( * V_24 ) ) ;
if ( ! V_24 )
return - V_117 ;
V_103 = F_36 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_2 -> V_6 = F_37 ( V_112 , 0 ) ;
if ( ! V_2 -> V_6 )
return - V_117 ;
if ( V_112 -> V_38 ) {
V_103 = F_38 ( V_112 -> V_38 , F_12 , V_118 ,
V_2 -> V_115 , V_2 ) ;
if ( V_103 == 0 )
V_2 -> V_38 = V_112 -> V_38 ;
}
V_103 = F_39 ( V_2 , 4 ) ;
if ( V_103 )
return V_103 ;
V_22 = & V_2 -> V_119 [ 0 ] ;
V_22 -> type = V_120 ;
V_22 -> V_121 = V_122 | V_123 | V_124 ;
V_22 -> V_125 = V_66 -> V_126 ;
V_22 -> V_127 = F_24 ;
V_22 -> V_128 = ( 1 << V_66 -> V_129 ) - 1 ;
V_22 -> V_130 = & V_131 ;
if ( V_2 -> V_38 ) {
V_2 -> V_40 = V_22 ;
V_22 -> V_121 |= V_132 ;
V_22 -> V_133 = 512 ;
V_22 -> V_134 = F_20 ;
V_22 -> V_135 = F_15 ;
V_22 -> V_136 = F_11 ;
}
V_22 = & V_2 -> V_119 [ 1 ] ;
V_22 -> type = V_137 ;
V_22 -> V_121 = V_138 ;
V_22 -> V_125 = 2 ;
V_22 -> V_128 = ( 1 << V_66 -> V_139 ) - 1 ;
V_22 -> V_133 = 1 ;
V_22 -> V_130 = & V_140 ;
V_22 -> V_141 = F_25 ;
V_22 -> V_127 = V_142 ;
V_103 = F_40 ( V_22 ) ;
if ( V_103 )
return V_103 ;
V_22 = & V_2 -> V_119 [ 2 ] ;
V_22 -> type = V_143 ;
V_22 -> V_121 = V_122 | V_138 ;
V_22 -> V_125 = 8 ;
V_22 -> V_144 = F_27 ;
V_22 -> V_145 = F_29 ;
V_22 -> V_128 = 1 ;
V_22 -> V_133 = 8 ;
V_22 -> V_130 = & V_146 ;
V_22 = & V_2 -> V_119 [ 3 ] ;
V_22 -> type = V_147 ;
V_22 -> V_121 = V_122 ;
V_22 -> V_125 = 0x1000 ;
V_22 -> V_127 = F_31 ;
V_22 -> V_128 = 0xff ;
V_22 -> V_133 = 1 ;
V_22 -> V_130 = & V_148 ;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_PROC;
#endif
return 0 ;
}
static int F_41 ( struct V_111 * V_2 ,
const struct V_149 * V_150 )
{
return F_42 ( V_2 , & V_151 , V_150 -> V_152 ) ;
}
