static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
unsigned int V_5 = 0 ;
F_2 ( V_3 , V_6 -> V_7 + V_8 ) ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ ) {
V_5 = F_3 ( V_6 -> V_7 + V_8 ) ;
if ( ( V_5 & V_10 ) != V_11 )
break;
F_4 ( 1 ) ;
}
if ( ( V_5 & V_10 ) == V_12 )
return 0 ;
F_5 ( V_2 -> V_13 , L_1 ,
V_5 ) ;
return - V_14 ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_17 )
{
F_2 ( V_15 , V_6 -> V_7 + V_18 ) ;
F_2 ( V_16 , V_6 -> V_7 + F_7 ( 0 ) ) ;
F_2 ( V_17 , V_6 -> V_7 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_19 ) ;
return F_3 ( V_6 -> V_7 + F_7 ( 2 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 , unsigned int V_20 )
{
F_2 ( V_15 , V_6 -> V_7 + V_18 ) ;
F_2 ( V_16 , V_6 -> V_7 + F_7 ( 0 ) ) ;
F_2 ( 0 , V_6 -> V_7 + F_7 ( 1 ) ) ;
F_2 ( V_20 , V_6 -> V_7 + F_7 ( 2 ) ) ;
F_1 ( V_2 , V_21 ) ;
}
static T_1 F_9 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
struct V_24 * V_25 ;
unsigned int V_5 ;
if ( ! V_2 -> V_26 )
return V_27 ;
V_25 = & V_2 -> V_28 [ 0 ] ;
V_5 = F_3 ( V_6 -> V_7 + V_29 ) ;
#ifdef F_10
F_11 ( V_5 ) ;
#endif
if ( V_5 & V_30 ) {
F_12 ( V_2 , V_25 ) ;
V_25 -> V_31 -> V_32 |= V_33 ;
}
if ( V_5 & ( V_34 | V_35 ) )
V_25 -> V_31 -> V_32 |= V_36 | V_37 ;
V_38 ++ ;
if ( V_38 >= 10 ) {
F_13 ( V_2 , V_25 ) ;
V_25 -> V_31 -> V_32 |= V_37 ;
}
F_14 ( V_2 , V_25 ) ;
return V_39 ;
}
static void F_11 ( unsigned int V_40 )
{
int V_4 ;
F_15 ( V_41 L_2 ) ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
if ( V_40 & ( 1 << V_4 ) )
F_15 ( V_42 L_3 , V_43 [ V_4 ] ) ;
}
F_15 ( V_42 L_4 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_44 ;
int V_45 ;
int V_46 ;
int V_4 ;
short V_20 ;
V_44 = F_3 ( V_6 -> V_7 + V_47 ) ;
V_46 = V_44 - V_6 -> V_48 ;
if ( V_46 < 0 )
V_46 += V_49 ;
F_5 ( V_2 -> V_13 , L_5 , V_46 ) ;
V_45 = V_6 -> V_50 ;
for ( V_4 = 0 ; V_4 < V_46 ; V_4 ++ ) {
V_20 = F_3 ( V_6 -> V_7 + V_51 + V_45 ) ;
F_16 ( V_25 -> V_31 , V_20 ) ;
V_45 ++ ;
if ( V_45 >= V_49 )
V_45 = 0 ;
}
V_6 -> V_50 = V_45 ;
F_2 ( V_45 , V_6 -> V_7 + V_52 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_24 * V_25 , struct V_53 * V_3 )
{
int V_54 = 0 ;
int V_55 ;
V_54 |= F_18 ( & V_3 -> V_56 , V_57 ) ;
V_54 |= F_18 ( & V_3 -> V_58 , V_59 ) ;
V_54 |= F_18 ( & V_3 -> V_60 , V_59 ) ;
V_54 |= F_18 ( & V_3 -> V_61 , V_62 ) ;
V_54 |= F_18 ( & V_3 -> V_63 , V_62 ) ;
if ( V_54 )
return 1 ;
if ( V_54 )
return 2 ;
if ( V_3 -> V_64 != 0 ) {
V_3 -> V_64 = 0 ;
V_54 ++ ;
}
if ( V_3 -> V_58 == V_59 ) {
if ( V_3 -> V_65 < V_66 -> V_67 ) {
V_3 -> V_65 = V_66 -> V_67 ;
V_54 ++ ;
}
if ( V_3 -> V_65 > 100 * 16 * 65535 ) {
V_3 -> V_65 = 100 * 16 * 65535 ;
V_54 ++ ;
}
} else {
}
if ( V_3 -> V_60 == V_59 ) {
if ( V_3 -> V_68 < V_66 -> V_67 ) {
V_3 -> V_68 = V_66 -> V_67 ;
V_54 ++ ;
}
if ( V_3 -> V_68 > 50 * 16 * 65535 ) {
V_3 -> V_68 = 50 * 16 * 65535 ;
V_54 ++ ;
}
} else {
}
if ( V_3 -> V_69 != V_3 -> V_70 ) {
V_3 -> V_69 = V_3 -> V_70 ;
V_54 ++ ;
}
if ( V_3 -> V_63 == V_62 ) {
if ( V_3 -> V_71 > 0x00ffffff ) {
V_3 -> V_71 = 0x00ffffff ;
V_54 ++ ;
}
} else {
if ( V_3 -> V_71 != 0 ) {
V_3 -> V_71 = 0 ;
V_54 ++ ;
}
}
if ( V_54 )
return 3 ;
if ( V_3 -> V_58 == V_59 ) {
V_55 = V_3 -> V_65 ;
F_19 ( 100 , & V_3 -> V_65 ,
V_3 -> V_40 & V_72 ) ;
if ( V_55 != V_3 -> V_65 )
V_54 ++ ;
} else {
}
if ( V_3 -> V_60 == V_59 ) {
V_55 = V_3 -> V_68 ;
F_19 ( 50 , & V_3 -> V_68 ,
V_3 -> V_40 & V_72 ) ;
if ( V_55 != V_3 -> V_68 )
V_54 ++ ;
if ( V_3 -> V_58 == V_59 &&
V_3 -> V_65 <
V_3 -> V_68 * V_3 -> V_69 ) {
V_3 -> V_65 =
V_3 -> V_68 * V_3 -> V_69 ;
V_54 ++ ;
}
} else {
}
if ( V_54 )
return 4 ;
return 0 ;
}
static int F_19 ( unsigned int V_73 , unsigned int * V_74 ,
unsigned int V_75 )
{
int V_76 , V_77 , V_78 ;
for ( V_78 = 0 ; V_78 < 16 ; V_78 ++ ) {
V_77 = V_73 * ( V_78 + 1 ) ;
switch ( V_75 ) {
case V_79 :
default:
V_76 = ( * V_74 + V_77 / 2 ) / V_77 ;
break;
case V_80 :
V_76 = ( * V_74 ) / V_77 ;
break;
case V_81 :
V_76 = ( * V_74 ) / V_77 ;
break;
}
if ( V_76 < 65536 ) {
* V_74 = V_76 * V_77 ;
return ( V_78 << 16 ) | ( V_76 ) ;
}
}
V_78 = 15 ;
V_77 = V_73 * ( 1 << V_78 ) ;
V_76 = 65535 ;
* V_74 = V_76 * V_77 ;
return ( V_78 << 16 ) | ( V_76 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_53 * V_3 = & V_25 -> V_31 -> V_3 ;
int V_4 ;
unsigned int V_16 , V_82 , V_83 ;
unsigned int V_76 ;
unsigned int V_84 ;
int V_85 ;
unsigned int V_86 ;
F_5 ( V_2 -> V_13 , L_6 ) ;
for ( V_4 = 0 ; V_4 < V_3 -> V_70 ; V_4 ++ ) {
V_16 = F_21 ( V_3 -> V_87 [ V_4 ] ) ;
V_82 = F_22 ( V_3 -> V_87 [ V_4 ] ) ;
F_2 ( ( V_82 << 6 ) | V_16 ,
V_6 -> V_7 + V_51 + V_4 ) ;
}
V_83 = F_23 ( V_3 -> V_87 [ 0 ] ) ;
F_2 ( V_3 -> V_69 , V_6 -> V_7 + F_7 ( 0 ) ) ;
F_5 ( V_2 -> V_13 , L_7 , V_3 -> V_69 ) ;
if ( V_3 -> V_60 == V_59 ) {
V_76 = F_19 ( 50 , & V_3 -> V_68 ,
V_3 -> V_40 & V_72 ) ;
F_2 ( ( V_76 >> 16 ) , V_6 -> V_7 + F_7 ( 1 ) ) ;
F_5 ( V_2 -> V_13 , L_8 , V_76 >> 16 ) ;
F_2 ( ( V_76 & 0xffff ) , V_6 -> V_7 + F_7 ( 2 ) ) ;
F_5 ( V_2 -> V_13 , L_9 , V_76 & 0xffff ) ;
} else {
}
if ( V_3 -> V_58 == V_59 ) {
V_84 = F_19 ( 100 , & V_3 -> V_65 ,
V_3 -> V_40 & V_72 ) ;
F_2 ( ( V_84 >> 16 ) , V_6 -> V_7 + F_7 ( 3 ) ) ;
F_5 ( V_2 -> V_13 , L_10 , V_84 >> 16 ) ;
F_2 ( ( V_84 & 0xffff ) , V_6 -> V_7 + F_7 ( 4 ) ) ;
F_5 ( V_2 -> V_13 , L_11 , V_84 & 0xffff ) ;
} else {
}
V_86 = V_88 | 0 | 0 ;
F_2 ( V_86 , V_6 -> V_7 + F_7 ( 5 ) ) ;
F_5 ( V_2 -> V_13 , L_12 , V_86 ) ;
F_2 ( V_83 == V_89 , V_6 -> V_7 + F_7 ( 6 ) ) ;
F_5 ( V_2 -> V_13 , L_13 , V_83 == V_89 ) ;
F_2 ( V_49 / 2 , V_6 -> V_7 + F_7 ( 7 ) ) ;
F_5 ( V_2 -> V_13 , L_14 , V_49 / 2 ) ;
F_2 ( V_90 , V_6 -> V_7 + V_18 ) ;
V_85 = F_1 ( V_2 , V_91 ) ;
F_2 ( V_30 | V_34 | V_35 ,
V_6 -> V_7 + V_92 ) ;
V_38 = 0 ;
F_2 ( V_90 , V_6 -> V_7 + V_18 ) ;
V_85 = F_1 ( V_2 , V_93 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_85 ;
F_2 ( V_90 , V_6 -> V_7 + V_18 ) ;
V_85 = F_1 ( V_2 , V_94 ) ;
F_2 ( 0 , V_6 -> V_7 + V_92 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_95 * V_96 , unsigned int * V_20 )
{
int V_4 ;
unsigned int V_16 , V_17 , V_83 ;
V_16 = F_21 ( V_96 -> V_97 ) ;
V_17 = F_22 ( V_96 -> V_97 ) ;
V_83 = F_23 ( V_96 -> V_97 ) ;
for ( V_4 = 0 ; V_4 < V_96 -> V_98 ; V_4 ++ )
V_20 [ V_4 ] = F_6 ( V_2 , V_90 , V_16 , V_17 ) ;
return V_4 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_95 * V_96 , unsigned int * V_20 )
{
int V_4 ;
unsigned int V_16 ;
V_16 = F_21 ( V_96 -> V_97 ) ;
for ( V_4 = 0 ; V_4 < V_96 -> V_98 ; V_4 ++ ) {
F_8 ( V_2 , V_99 , V_16 , V_20 [ V_4 ] ) ;
V_6 -> V_100 [ V_16 ] = V_20 [ V_4 ] ;
}
return V_4 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_95 * V_96 , unsigned int * V_20 )
{
int V_4 ;
unsigned int V_16 ;
V_16 = F_21 ( V_96 -> V_97 ) ;
for ( V_4 = 0 ; V_4 < V_96 -> V_98 ; V_4 ++ )
V_20 [ V_4 ] = V_6 -> V_100 [ V_16 ] ;
return V_4 ;
}
static void F_27 ( struct V_1 * V_2 , int V_101 )
{
F_2 ( V_102 , V_6 -> V_7 + V_18 ) ;
F_2 ( V_101 , V_6 -> V_7 + F_7 ( 0 ) ) ;
#if 0
writew(0, devpriv->io_addr + DPR_Params(1));
writew(0, devpriv->io_addr + DPR_Params(2));
#endif
F_1 ( V_2 , V_91 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_95 * V_96 , unsigned int * V_20 )
{
int V_103 ;
V_103 = ( F_21 ( V_96 -> V_97 ) < 4 ) ? 0x0f : 0xf0 ;
switch ( V_20 [ 0 ] ) {
case V_104 :
V_25 -> V_105 |= V_103 ;
break;
case V_106 :
V_25 -> V_105 &= ~ V_103 ;
break;
case V_107 :
V_20 [ 1 ] =
( V_25 ->
V_105 & ( 1 << F_21 ( V_96 -> V_97 ) ) ) ? V_108 :
V_109 ;
return V_96 -> V_98 ;
break;
default:
return - V_110 ;
break;
}
V_103 = ( V_25 -> V_105 & 0x01 ) | ( ( V_25 -> V_105 & 0x10 ) >> 3 ) ;
F_27 ( V_2 , V_103 ) ;
return V_96 -> V_98 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_95 * V_96 , unsigned int * V_20 )
{
if ( V_20 [ 0 ] ) {
V_25 -> V_111 &= ~ V_20 [ 0 ] ;
V_25 -> V_111 |= V_20 [ 1 ] & V_20 [ 0 ] ;
F_8 ( V_2 , V_102 , 0 , V_25 -> V_111 ) ;
}
V_20 [ 1 ] = F_6 ( V_2 , V_112 , 0 , 0 ) ;
return V_96 -> V_98 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_95 * V_96 , unsigned int * V_20 )
{
unsigned int V_113 = F_21 ( V_96 -> V_97 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_96 -> V_98 ; V_4 ++ ) {
F_2 ( V_114 , V_6 -> V_7 + V_18 ) ;
F_2 ( V_113 , V_6 -> V_7 + F_7 ( 0 ) ) ;
F_2 ( 1 , V_6 -> V_7 + F_7 ( 1 ) ) ;
F_1 ( V_2 , V_115 ) ;
V_20 [ V_4 ] = F_3 ( V_6 -> V_7 + F_7 ( 2 ) ) ;
}
return V_4 ;
}
static struct V_116 * F_31 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
struct V_116 * V_119 = NULL ;
int V_120 = V_118 -> V_121 [ 0 ] ;
int V_122 = V_118 -> V_121 [ 1 ] ;
int V_4 ;
F_32 (pcidev) {
if ( V_120 || V_122 ) {
if ( V_120 != V_119 -> V_120 -> V_123 ||
V_122 != F_33 ( V_119 -> V_124 ) )
continue;
}
if ( V_119 -> V_125 != V_126 )
continue;
for ( V_4 = 0 ; V_4 < F_34 ( V_127 ) ; V_4 ++ ) {
if ( V_127 [ V_4 ] . V_128 != V_119 -> V_129 )
continue;
V_2 -> V_130 = V_127 + V_4 ;
return V_119 ;
}
}
F_35 ( V_2 -> V_13 ,
L_15 ,
V_120 , V_122 ) ;
return NULL ;
}
static int F_36 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
struct V_116 * V_119 ;
struct V_24 * V_25 ;
T_2 V_131 ;
int V_85 = 0 ;
F_5 ( V_2 -> V_13 , L_16 ) ;
V_85 = F_37 ( V_2 , sizeof( struct V_132 ) ) ;
if ( V_85 < 0 )
return V_85 ;
V_119 = F_31 ( V_2 , V_118 ) ;
if ( ! V_119 )
return - V_133 ;
F_38 ( V_2 , & V_119 -> V_2 ) ;
V_85 = F_39 ( V_119 , L_17 ) ;
if ( V_85 < 0 )
return V_85 ;
V_2 -> V_134 = 1 ;
V_131 = F_40 ( V_119 , 0 ) ;
V_6 -> V_7 = F_41 ( V_131 , V_135 ) ;
if ( ! V_6 -> V_7 )
return - V_136 ;
V_2 -> V_137 = V_66 -> V_138 ;
if ( F_42 ( V_119 -> V_22 , F_9 , V_139 ,
L_17 , V_2 ) ) {
F_35 ( V_2 -> V_13 , L_18 ,
V_119 -> V_22 ) ;
return - V_110 ;
}
V_2 -> V_22 = V_119 -> V_22 ;
V_85 = F_43 ( V_2 , 4 ) ;
if ( V_85 )
return V_85 ;
V_25 = & V_2 -> V_28 [ 0 ] ;
V_2 -> V_140 = V_25 ;
V_25 -> type = V_141 ;
V_25 -> V_142 = V_143 | V_144 | V_145 | V_146 ;
V_25 -> V_147 = V_66 -> V_148 ;
V_25 -> V_149 = F_24 ;
V_25 -> V_150 = ( 1 << V_66 -> V_151 ) - 1 ;
V_25 -> V_152 = 512 ;
V_25 -> V_153 = & V_154 ;
V_25 -> V_155 = F_20 ;
V_25 -> V_156 = F_17 ;
V_25 -> V_157 = F_13 ;
V_25 = & V_2 -> V_28 [ 1 ] ;
V_25 -> type = V_158 ;
V_25 -> V_142 = V_159 ;
V_25 -> V_147 = 2 ;
V_25 -> V_149 = F_26 ;
V_25 -> V_160 = F_25 ;
V_25 -> V_150 = ( 1 << V_66 -> V_161 ) - 1 ;
V_25 -> V_152 = 1 ;
V_25 -> V_153 = & V_162 ;
V_25 = & V_2 -> V_28 [ 2 ] ;
V_25 -> type = V_163 ;
V_25 -> V_142 = V_143 | V_159 ;
V_25 -> V_147 = 8 ;
V_25 -> V_164 = F_28 ;
V_25 -> V_165 = F_29 ;
V_25 -> V_150 = 1 ;
V_25 -> V_152 = 8 ;
V_25 -> V_153 = & V_166 ;
V_25 = & V_2 -> V_28 [ 3 ] ;
V_25 -> type = V_167 ;
V_25 -> V_142 = V_143 ;
V_25 -> V_147 = 0x1000 ;
V_25 -> V_149 = F_30 ;
V_25 -> V_150 = 0xff ;
V_25 -> V_152 = 1 ;
V_25 -> V_153 = & V_168 ;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_PROC;
#endif
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_116 * V_119 = F_45 ( V_2 ) ;
if ( V_2 -> V_22 )
F_46 ( V_2 -> V_22 , V_2 ) ;
if ( V_6 ) {
if ( V_6 -> V_7 )
F_47 ( V_6 -> V_7 ) ;
}
if ( V_119 ) {
if ( V_2 -> V_134 )
F_48 ( V_119 ) ;
F_49 ( V_119 ) ;
}
}
static int T_3 F_50 ( struct V_116 * V_2 ,
const struct V_169 * V_170 )
{
return F_51 ( V_2 , & V_171 ) ;
}
static void T_4 F_52 ( struct V_116 * V_2 )
{
F_53 ( V_2 ) ;
}
