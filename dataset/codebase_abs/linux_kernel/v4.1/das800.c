static void F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_2 ( V_3 , V_2 -> V_5 + 2 ) ;
}
static unsigned F_3 ( struct V_1 * V_2 , unsigned V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_6 ) ;
return F_4 ( V_2 -> V_5 + 7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
if ( V_8 -> V_15 == 16 )
F_2 ( V_16 , V_2 -> V_5 + V_6 ) ;
F_1 ( V_2 , V_17 , V_18 ) ;
F_1 ( V_2 , V_19 | V_11 -> V_20 , V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , 0x0 , V_18 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_8 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_24 * V_25 )
{
unsigned int V_26 = F_11 ( V_25 -> V_27 [ 0 ] ) ;
unsigned int V_28 = F_12 ( V_25 -> V_27 [ 0 ] ) ;
int V_29 ;
for ( V_29 = 1 ; V_29 < V_25 -> V_30 ; V_29 ++ ) {
unsigned int V_31 = F_11 ( V_25 -> V_27 [ V_29 ] ) ;
unsigned int V_32 = F_12 ( V_25 -> V_27 [ V_29 ] ) ;
if ( V_31 != ( V_26 + V_29 ) % V_23 -> V_33 ) {
F_13 ( V_2 -> V_34 ,
L_1 ) ;
return - V_35 ;
}
if ( V_32 != V_28 ) {
F_13 ( V_2 -> V_34 ,
L_2 ) ;
return - V_35 ;
}
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_24 * V_25 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
int V_36 = 0 ;
V_36 |= F_15 ( & V_25 -> V_37 , V_38 | V_39 ) ;
V_36 |= F_15 ( & V_25 -> V_40 , V_41 ) ;
V_36 |= F_15 ( & V_25 -> V_42 ,
V_43 | V_39 ) ;
V_36 |= F_15 ( & V_25 -> V_44 , V_45 ) ;
V_36 |= F_15 ( & V_25 -> V_46 , V_45 | V_47 ) ;
if ( V_36 )
return 1 ;
V_36 |= F_16 ( V_25 -> V_37 ) ;
V_36 |= F_16 ( V_25 -> V_42 ) ;
V_36 |= F_16 ( V_25 -> V_46 ) ;
if ( V_36 )
return 2 ;
V_36 |= F_17 ( & V_25 -> V_48 , 0 ) ;
if ( V_25 -> V_42 == V_43 ) {
V_36 |= F_18 ( & V_25 -> V_49 ,
V_8 -> V_50 ) ;
}
V_36 |= F_18 ( & V_25 -> V_30 , 1 ) ;
V_36 |= F_17 ( & V_25 -> V_51 ,
V_25 -> V_30 ) ;
if ( V_25 -> V_46 == V_45 )
V_36 |= F_18 ( & V_25 -> V_52 , 1 ) ;
else
V_36 |= F_17 ( & V_25 -> V_52 , 0 ) ;
if ( V_36 )
return 3 ;
if ( V_25 -> V_42 == V_43 ) {
unsigned int V_53 = V_25 -> V_49 ;
F_19 ( V_2 -> V_54 , & V_53 , V_25 -> V_55 ) ;
V_36 |= F_17 ( & V_25 -> V_49 , V_53 ) ;
}
if ( V_36 )
return 4 ;
if ( V_25 -> V_27 && V_25 -> V_30 > 0 )
V_36 |= F_10 ( V_2 , V_23 , V_25 ) ;
if ( V_36 )
return 5 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
struct V_56 * V_57 = V_23 -> V_57 ;
struct V_24 * V_25 = & V_57 -> V_25 ;
unsigned int V_58 = F_12 ( V_25 -> V_27 [ 0 ] ) ;
unsigned int V_59 = F_11 ( V_25 -> V_27 [ 0 ] ) ;
unsigned int V_60 = ( V_59 + V_25 -> V_30 - 1 ) % 8 ;
unsigned int V_61 = ( V_60 << 3 ) | V_59 ;
int V_62 ;
unsigned long V_13 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_61 , V_63 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
if ( V_8 -> V_15 == 12 && V_58 > 0 )
V_58 += 0x7 ;
V_58 &= 0xf ;
F_2 ( V_58 , V_2 -> V_5 + V_6 ) ;
V_62 = 0 ;
V_62 |= V_64 | V_65 ;
if ( V_25 -> V_37 == V_39 )
V_62 |= V_66 ;
if ( V_25 -> V_42 == V_43 ) {
V_62 |= V_67 | V_68 ;
F_21 ( V_2 -> V_54 ) ;
F_22 ( V_2 -> V_54 , 1 , 2 , true ) ;
}
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_62 , V_18 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_23 ( struct V_1 * V_2 )
{
unsigned int V_69 = F_4 ( V_2 -> V_5 + V_70 ) ;
unsigned int V_71 = F_4 ( V_2 -> V_5 + V_72 ) ;
return ( V_71 << 8 ) | V_69 ;
}
static T_1 F_24 ( int V_73 , void * V_74 )
{
struct V_1 * V_2 = V_74 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_22 * V_23 = V_2 -> V_75 ;
struct V_56 * V_57 ;
struct V_24 * V_25 ;
unsigned long V_13 ;
unsigned int V_76 ;
unsigned int V_3 ;
bool V_77 ;
bool V_78 ;
int V_29 ;
V_76 = F_4 ( V_2 -> V_5 + V_79 ) ;
if ( ! ( V_76 & V_80 ) )
return V_81 ;
if ( ! V_2 -> V_82 )
return V_83 ;
V_57 = V_23 -> V_57 ;
V_25 = & V_57 -> V_25 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
V_76 = F_3 ( V_2 , V_21 ) & V_84 ;
if ( V_76 == 0 ) {
F_7 ( & V_2 -> V_14 , V_13 ) ;
return V_83 ;
}
for ( V_29 = 0 ; V_29 < V_85 ; V_29 ++ ) {
V_3 = F_23 ( V_2 ) ;
if ( V_23 -> V_86 == 0x0fff ) {
V_77 = ! ! ( V_3 & V_87 ) ;
V_78 = ! ! ( V_3 & V_88 ) ;
} else {
V_77 = false ;
V_78 = ! ! ( F_4 ( V_2 -> V_5 + V_6 ) &
V_89 ) ;
}
if ( V_77 || V_78 )
break;
if ( V_23 -> V_86 == 0x0fff )
V_3 >>= 4 ;
V_3 &= V_23 -> V_86 ;
F_25 ( V_23 , & V_3 , 1 ) ;
if ( V_25 -> V_46 == V_45 &&
V_57 -> V_90 >= V_25 -> V_52 ) {
V_57 -> V_91 |= V_92 ;
break;
}
}
if ( V_78 ) {
F_7 ( & V_2 -> V_14 , V_13 ) ;
V_57 -> V_91 |= V_93 ;
F_26 ( V_2 , V_23 ) ;
return V_83 ;
}
if ( ! ( V_57 -> V_91 & V_94 ) ) {
F_1 ( V_2 , V_19 | V_11 -> V_20 ,
V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
} else {
F_7 ( & V_2 -> V_14 , V_13 ) ;
F_8 ( V_2 ) ;
}
F_26 ( V_2 , V_23 ) ;
return V_83 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_95 * V_96 ,
unsigned long V_97 )
{
unsigned int V_76 ;
V_76 = F_4 ( V_2 -> V_5 + V_79 ) ;
if ( ( V_76 & V_98 ) == 0 )
return 0 ;
return - V_99 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_95 * V_96 ,
unsigned int * V_100 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_31 = F_11 ( V_96 -> V_101 ) ;
unsigned int V_32 = F_12 ( V_96 -> V_101 ) ;
unsigned long V_13 ;
unsigned int V_3 ;
int V_102 ;
int V_29 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_31 | V_11 -> V_20 , V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
if ( V_23 -> V_86 == 0x0fff && V_32 )
V_32 += 0x7 ;
V_32 &= 0xf ;
F_2 ( V_32 , V_2 -> V_5 + V_6 ) ;
F_29 ( 5 ) ;
for ( V_29 = 0 ; V_29 < V_96 -> V_103 ; V_29 ++ ) {
F_30 ( 0 , V_2 -> V_5 + V_72 ) ;
V_102 = F_31 ( V_2 , V_23 , V_96 , F_27 , 0 ) ;
if ( V_102 )
return V_102 ;
V_3 = F_23 ( V_2 ) ;
if ( V_23 -> V_86 == 0x0fff )
V_3 >>= 4 ;
V_100 [ V_29 ] = V_3 & V_23 -> V_86 ;
}
return V_96 -> V_103 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_95 * V_96 ,
unsigned int * V_100 )
{
V_100 [ 1 ] = ( F_4 ( V_2 -> V_5 + V_79 ) >> 4 ) & 0x7 ;
return V_96 -> V_103 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_95 * V_96 ,
unsigned int * V_100 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned long V_13 ;
if ( F_34 ( V_23 , V_100 ) ) {
V_11 -> V_20 = V_23 -> V_104 << 4 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_19 | V_11 -> V_20 ,
V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
}
V_100 [ 1 ] = V_23 -> V_104 ;
return V_96 -> V_103 ;
}
static int F_35 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
int V_105 = V_8 ? V_8 - V_106 : - V_35 ;
int V_107 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
V_107 = F_3 ( V_2 , V_108 ) & 0x3 ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
switch ( V_107 ) {
case 0x0 :
if ( V_105 == V_109 || V_105 == V_110 )
break;
F_13 ( V_2 -> V_34 , L_3 ) ;
V_105 = V_109 ;
break;
case 0x2 :
if ( V_105 == V_111 || V_105 == V_112 )
break;
F_13 ( V_2 -> V_34 , L_4 ) ;
V_105 = V_111 ;
break;
case 0x3 :
if ( V_105 == V_113 || V_105 == V_114 ||
V_105 == V_115 )
break;
F_13 ( V_2 -> V_34 , L_5 ) ;
V_105 = V_113 ;
break;
default:
F_13 ( V_2 -> V_34 , L_6 ,
V_107 ) ;
V_105 = - V_35 ;
break;
}
return V_105 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
const struct V_7 * V_8 ;
struct V_10 * V_11 ;
struct V_22 * V_23 ;
unsigned int V_73 = V_117 -> V_118 [ 1 ] ;
unsigned long V_13 ;
int V_105 ;
int V_102 ;
V_11 = F_37 ( V_2 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_119 ;
V_102 = F_38 ( V_2 , V_117 -> V_118 [ 0 ] , 0x8 ) ;
if ( V_102 )
return V_102 ;
V_105 = F_35 ( V_2 ) ;
if ( V_105 < 0 ) {
F_13 ( V_2 -> V_34 , L_7 ) ;
return - V_120 ;
}
V_2 -> V_9 = V_106 + V_105 ;
V_8 = V_2 -> V_9 ;
V_2 -> V_121 = V_8 -> V_122 ;
if ( V_73 > 1 && V_73 <= 7 ) {
V_102 = F_39 ( V_73 , F_24 , 0 , V_2 -> V_121 ,
V_2 ) ;
if ( V_102 == 0 )
V_2 -> V_73 = V_73 ;
}
V_2 -> V_54 = F_40 ( V_2 -> V_5 + V_123 ,
V_124 , V_125 , 0 ) ;
if ( ! V_2 -> V_54 )
return - V_119 ;
V_102 = F_41 ( V_2 , 3 ) ;
if ( V_102 )
return V_102 ;
V_23 = & V_2 -> V_126 [ 0 ] ;
V_2 -> V_75 = V_23 ;
V_23 -> type = V_127 ;
V_23 -> V_128 = V_129 | V_130 ;
V_23 -> V_33 = 8 ;
V_23 -> V_86 = ( 1 << V_8 -> V_15 ) - 1 ;
V_23 -> V_131 = V_8 -> V_132 ;
V_23 -> V_133 = F_28 ;
if ( V_2 -> V_73 ) {
V_23 -> V_128 |= V_134 ;
V_23 -> V_135 = 8 ;
V_23 -> V_136 = F_14 ;
V_23 -> V_137 = F_20 ;
V_23 -> V_138 = F_9 ;
}
V_23 = & V_2 -> V_126 [ 1 ] ;
V_23 -> type = V_139 ;
V_23 -> V_128 = V_129 ;
V_23 -> V_33 = 3 ;
V_23 -> V_86 = 1 ;
V_23 -> V_131 = & V_140 ;
V_23 -> V_141 = F_32 ;
V_23 = & V_2 -> V_126 [ 2 ] ;
V_23 -> type = V_142 ;
V_23 -> V_128 = V_143 ;
V_23 -> V_33 = 4 ;
V_23 -> V_86 = 1 ;
V_23 -> V_131 = & V_140 ;
V_23 -> V_141 = F_33 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_19 | V_11 -> V_20 , V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
return 0 ;
}
