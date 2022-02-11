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
static void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned long V_22 = V_2 -> V_5 + V_23 ;
F_10 ( V_22 , 0 , 1 , V_24 | V_25 ) ;
F_10 ( V_22 , 0 , 2 , V_24 | V_25 ) ;
F_11 ( V_22 , 0 , 1 , V_11 -> V_26 ) ;
F_11 ( V_22 , 0 , 2 , V_11 -> V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
F_8 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
unsigned int V_32 = F_14 ( V_31 -> V_33 [ 0 ] ) ;
unsigned int V_34 = F_15 ( V_31 -> V_33 [ 0 ] ) ;
int V_35 ;
for ( V_35 = 1 ; V_35 < V_31 -> V_36 ; V_35 ++ ) {
unsigned int V_37 = F_14 ( V_31 -> V_33 [ V_35 ] ) ;
unsigned int V_38 = F_15 ( V_31 -> V_33 [ V_35 ] ) ;
if ( V_37 != ( V_32 + V_35 ) % V_29 -> V_39 ) {
F_16 ( V_2 -> V_40 ,
L_1 ) ;
return - V_41 ;
}
if ( V_38 != V_34 ) {
F_16 ( V_2 -> V_40 ,
L_2 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_42 = 0 ;
unsigned int V_43 ;
V_42 |= F_18 ( & V_31 -> V_44 , V_45 | V_46 ) ;
V_42 |= F_18 ( & V_31 -> V_47 , V_48 ) ;
V_42 |= F_18 ( & V_31 -> V_49 , V_50 | V_46 ) ;
V_42 |= F_18 ( & V_31 -> V_51 , V_52 ) ;
V_42 |= F_18 ( & V_31 -> V_53 , V_52 | V_54 ) ;
if ( V_42 )
return 1 ;
V_42 |= F_19 ( V_31 -> V_44 ) ;
V_42 |= F_19 ( V_31 -> V_49 ) ;
V_42 |= F_19 ( V_31 -> V_53 ) ;
if ( V_42 )
return 2 ;
V_42 |= F_20 ( & V_31 -> V_55 , 0 ) ;
if ( V_31 -> V_49 == V_50 )
V_42 |= F_21 ( & V_31 -> V_56 ,
V_8 -> V_57 ) ;
V_42 |= F_21 ( & V_31 -> V_36 , 1 ) ;
V_42 |= F_20 ( & V_31 -> V_58 , V_31 -> V_36 ) ;
if ( V_31 -> V_53 == V_52 )
V_42 |= F_21 ( & V_31 -> V_59 , 1 ) ;
else
V_42 |= F_20 ( & V_31 -> V_59 , 0 ) ;
if ( V_42 )
return 3 ;
if ( V_31 -> V_49 == V_50 ) {
V_43 = V_31 -> V_56 ;
F_22 ( V_60 ,
& V_11 -> V_26 ,
& V_11 -> V_27 ,
& V_43 , V_31 -> V_61 ) ;
V_42 |= F_20 ( & V_31 -> V_56 , V_43 ) ;
}
if ( V_42 )
return 4 ;
if ( V_31 -> V_33 && V_31 -> V_36 > 0 )
V_42 |= F_13 ( V_2 , V_29 , V_31 ) ;
if ( V_42 )
return 5 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
struct V_62 * V_63 = V_29 -> V_63 ;
struct V_30 * V_31 = & V_63 -> V_31 ;
unsigned int V_64 = F_15 ( V_31 -> V_33 [ 0 ] ) ;
unsigned int V_65 = F_14 ( V_31 -> V_33 [ 0 ] ) ;
unsigned int V_66 = ( V_65 + V_31 -> V_36 - 1 ) % 8 ;
unsigned int V_67 = ( V_66 << 3 ) | V_65 ;
int V_68 ;
unsigned long V_13 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_67 , V_69 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
if ( V_8 -> V_15 == 12 && V_64 > 0 )
V_64 += 0x7 ;
V_64 &= 0xf ;
F_2 ( V_64 , V_2 -> V_5 + V_6 ) ;
V_68 = 0 ;
V_68 |= V_70 | V_71 ;
if ( V_31 -> V_44 == V_46 )
V_68 |= V_72 ;
if ( V_31 -> V_49 == V_50 ) {
V_68 |= V_73 | V_74 ;
F_9 ( V_2 ) ;
}
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_68 , V_18 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_75 = F_4 ( V_2 -> V_5 + V_76 ) ;
unsigned int V_77 = F_4 ( V_2 -> V_5 + V_78 ) ;
return ( V_77 << 8 ) | V_75 ;
}
static T_1 F_25 ( int V_79 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_28 * V_29 = V_2 -> V_81 ;
struct V_62 * V_63 ;
struct V_30 * V_31 ;
unsigned long V_13 ;
unsigned int V_82 ;
unsigned int V_3 ;
bool V_83 ;
bool V_84 ;
int V_35 ;
V_82 = F_4 ( V_2 -> V_5 + V_85 ) ;
if ( ! ( V_82 & V_86 ) )
return V_87 ;
if ( ! V_2 -> V_88 )
return V_89 ;
V_63 = V_29 -> V_63 ;
V_31 = & V_63 -> V_31 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
V_82 = F_3 ( V_2 , V_21 ) & V_90 ;
if ( V_82 == 0 ) {
F_7 ( & V_2 -> V_14 , V_13 ) ;
return V_89 ;
}
for ( V_35 = 0 ; V_35 < V_91 ; V_35 ++ ) {
V_3 = F_24 ( V_2 ) ;
if ( V_29 -> V_92 == 0x0fff ) {
V_83 = ! ! ( V_3 & V_93 ) ;
V_84 = ! ! ( V_3 & V_94 ) ;
} else {
V_83 = false ;
V_84 = ! ! ( F_4 ( V_2 -> V_5 + V_6 ) &
V_95 ) ;
}
if ( V_83 || V_84 )
break;
if ( V_29 -> V_92 == 0x0fff )
V_3 >>= 4 ;
V_3 &= V_29 -> V_92 ;
F_26 ( V_29 , & V_3 , 1 ) ;
if ( V_31 -> V_53 == V_52 &&
V_63 -> V_96 >= V_31 -> V_59 ) {
V_63 -> V_97 |= V_98 ;
break;
}
}
if ( V_84 ) {
F_7 ( & V_2 -> V_14 , V_13 ) ;
V_63 -> V_97 |= V_99 | V_98 ;
F_27 ( V_2 , V_29 ) ;
return V_89 ;
}
if ( ! ( V_63 -> V_97 & V_100 ) ) {
F_1 ( V_2 , V_19 | V_11 -> V_20 ,
V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
} else {
F_7 ( & V_2 -> V_14 , V_13 ) ;
F_8 ( V_2 ) ;
}
F_27 ( V_2 , V_29 ) ;
return V_89 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_101 * V_102 ,
unsigned long V_103 )
{
unsigned int V_82 ;
V_82 = F_4 ( V_2 -> V_5 + V_85 ) ;
if ( ( V_82 & V_104 ) == 0 )
return 0 ;
return - V_105 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_101 * V_102 ,
unsigned int * V_106 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_37 = F_14 ( V_102 -> V_107 ) ;
unsigned int V_38 = F_15 ( V_102 -> V_107 ) ;
unsigned long V_13 ;
unsigned int V_3 ;
int V_108 ;
int V_35 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_37 | V_11 -> V_20 , V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
if ( V_29 -> V_92 == 0x0fff && V_38 )
V_38 += 0x7 ;
V_38 &= 0xf ;
F_2 ( V_38 , V_2 -> V_5 + V_6 ) ;
F_30 ( 5 ) ;
for ( V_35 = 0 ; V_35 < V_102 -> V_109 ; V_35 ++ ) {
F_31 ( 0 , V_2 -> V_5 + V_78 ) ;
V_108 = F_32 ( V_2 , V_29 , V_102 , F_28 , 0 ) ;
if ( V_108 )
return V_108 ;
V_3 = F_24 ( V_2 ) ;
if ( V_29 -> V_92 == 0x0fff )
V_3 >>= 4 ;
V_106 [ V_35 ] = V_3 & V_29 -> V_92 ;
}
return V_102 -> V_109 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_101 * V_102 ,
unsigned int * V_106 )
{
V_106 [ 1 ] = ( F_4 ( V_2 -> V_5 + V_85 ) >> 4 ) & 0x7 ;
return V_102 -> V_109 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_101 * V_102 ,
unsigned int * V_106 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned long V_13 ;
if ( F_35 ( V_29 , V_106 ) ) {
V_11 -> V_20 = V_29 -> V_110 << 4 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_19 | V_11 -> V_20 ,
V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
}
V_106 [ 1 ] = V_29 -> V_110 ;
return V_102 -> V_109 ;
}
static int F_36 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
int V_111 = V_8 ? V_8 - V_112 : - V_41 ;
int V_113 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
V_113 = F_3 ( V_2 , V_114 ) & 0x3 ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
switch ( V_113 ) {
case 0x0 :
if ( V_111 == V_115 || V_111 == V_116 )
break;
F_16 ( V_2 -> V_40 , L_3 ) ;
V_111 = V_115 ;
break;
case 0x2 :
if ( V_111 == V_117 || V_111 == V_118 )
break;
F_16 ( V_2 -> V_40 , L_4 ) ;
V_111 = V_117 ;
break;
case 0x3 :
if ( V_111 == V_119 || V_111 == V_120 ||
V_111 == V_121 )
break;
F_16 ( V_2 -> V_40 , L_5 ) ;
V_111 = V_119 ;
break;
default:
F_16 ( V_2 -> V_40 , L_6 ,
V_113 ) ;
V_111 = - V_41 ;
break;
}
return V_111 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
const struct V_7 * V_8 ;
struct V_10 * V_11 ;
struct V_28 * V_29 ;
unsigned int V_79 = V_123 -> V_124 [ 1 ] ;
unsigned long V_13 ;
int V_111 ;
int V_108 ;
V_11 = F_38 ( V_2 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_125 ;
V_108 = F_39 ( V_2 , V_123 -> V_124 [ 0 ] , 0x8 ) ;
if ( V_108 )
return V_108 ;
V_111 = F_36 ( V_2 ) ;
if ( V_111 < 0 ) {
F_16 ( V_2 -> V_40 , L_7 ) ;
return - V_126 ;
}
V_2 -> V_9 = V_112 + V_111 ;
V_8 = V_2 -> V_9 ;
V_2 -> V_127 = V_8 -> V_128 ;
if ( V_79 > 1 && V_79 <= 7 ) {
V_108 = F_40 ( V_79 , F_25 , 0 , V_2 -> V_127 ,
V_2 ) ;
if ( V_108 == 0 )
V_2 -> V_79 = V_79 ;
}
V_108 = F_41 ( V_2 , 3 ) ;
if ( V_108 )
return V_108 ;
V_29 = & V_2 -> V_129 [ 0 ] ;
V_2 -> V_81 = V_29 ;
V_29 -> type = V_130 ;
V_29 -> V_131 = V_132 | V_133 ;
V_29 -> V_39 = 8 ;
V_29 -> V_92 = ( 1 << V_8 -> V_15 ) - 1 ;
V_29 -> V_134 = V_8 -> V_135 ;
V_29 -> V_136 = F_29 ;
if ( V_2 -> V_79 ) {
V_29 -> V_131 |= V_137 ;
V_29 -> V_138 = 8 ;
V_29 -> V_139 = F_17 ;
V_29 -> V_140 = F_23 ;
V_29 -> V_141 = F_12 ;
}
V_29 = & V_2 -> V_129 [ 1 ] ;
V_29 -> type = V_142 ;
V_29 -> V_131 = V_132 ;
V_29 -> V_39 = 3 ;
V_29 -> V_92 = 1 ;
V_29 -> V_134 = & V_143 ;
V_29 -> V_144 = F_33 ;
V_29 = & V_2 -> V_129 [ 2 ] ;
V_29 -> type = V_145 ;
V_29 -> V_131 = V_146 ;
V_29 -> V_39 = 4 ;
V_29 -> V_92 = 1 ;
V_29 -> V_134 = & V_143 ;
V_29 -> V_144 = F_34 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_19 | V_11 -> V_20 , V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
return 0 ;
}
