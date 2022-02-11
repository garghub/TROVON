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
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
if ( V_8 -> V_14 == 16 )
F_2 ( V_15 , V_2 -> V_5 + V_6 ) ;
F_1 ( V_2 , V_16 , V_17 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , 0x0 , V_17 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_21 = V_2 -> V_5 + V_22 ;
F_11 ( V_21 , 0 , 1 , V_23 | V_24 ) ;
F_11 ( V_21 , 0 , 2 , V_23 | V_24 ) ;
F_12 ( V_21 , 0 , 1 , V_10 -> V_25 ) ;
F_12 ( V_21 , 0 , 2 , V_10 -> V_26 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_29 = 0 ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_30 * V_31 )
{
unsigned int V_32 = F_15 ( V_31 -> V_33 [ 0 ] ) ;
unsigned int V_34 = F_16 ( V_31 -> V_33 [ 0 ] ) ;
int V_35 ;
for ( V_35 = 1 ; V_35 < V_31 -> V_36 ; V_35 ++ ) {
unsigned int V_37 = F_15 ( V_31 -> V_33 [ V_35 ] ) ;
unsigned int V_38 = F_16 ( V_31 -> V_33 [ V_35 ] ) ;
if ( V_37 != ( V_32 + V_35 ) % V_28 -> V_39 ) {
F_17 ( V_2 -> V_40 ,
L_1 ) ;
return - V_41 ;
}
if ( V_38 != V_34 ) {
F_17 ( V_2 -> V_40 ,
L_2 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_30 * V_31 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_42 = 0 ;
unsigned int V_43 ;
V_42 |= F_19 ( & V_31 -> V_44 , V_45 | V_46 ) ;
V_42 |= F_19 ( & V_31 -> V_47 , V_48 ) ;
V_42 |= F_19 ( & V_31 -> V_49 , V_50 | V_46 ) ;
V_42 |= F_19 ( & V_31 -> V_51 , V_52 ) ;
V_42 |= F_19 ( & V_31 -> V_53 , V_52 | V_54 ) ;
if ( V_42 )
return 1 ;
V_42 |= F_20 ( V_31 -> V_44 ) ;
V_42 |= F_20 ( V_31 -> V_49 ) ;
V_42 |= F_20 ( V_31 -> V_53 ) ;
if ( V_42 )
return 2 ;
V_42 |= F_21 ( & V_31 -> V_55 , 0 ) ;
if ( V_31 -> V_49 == V_50 )
V_42 |= F_22 ( & V_31 -> V_56 ,
V_8 -> V_57 ) ;
V_42 |= F_22 ( & V_31 -> V_36 , 1 ) ;
V_42 |= F_21 ( & V_31 -> V_58 , V_31 -> V_36 ) ;
if ( V_31 -> V_53 == V_52 )
V_42 |= F_22 ( & V_31 -> V_59 , 1 ) ;
else
V_42 |= F_21 ( & V_31 -> V_59 , 0 ) ;
if ( V_42 )
return 3 ;
if ( V_31 -> V_49 == V_50 ) {
V_43 = V_31 -> V_56 ;
F_23 ( V_60 ,
& V_10 -> V_25 ,
& V_10 -> V_26 ,
& V_43 , V_31 -> V_61 ) ;
V_42 |= F_21 ( & V_31 -> V_56 , V_43 ) ;
}
if ( V_42 )
return 4 ;
if ( V_31 -> V_33 && V_31 -> V_36 > 0 )
V_42 |= F_14 ( V_2 , V_28 , V_31 ) ;
if ( V_42 )
return 5 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_62 * V_63 = V_28 -> V_63 ;
struct V_30 * V_31 = & V_63 -> V_31 ;
unsigned int V_64 = F_16 ( V_31 -> V_33 [ 0 ] ) ;
unsigned int V_65 = F_15 ( V_31 -> V_33 [ 0 ] ) ;
unsigned int V_66 = ( V_65 + V_31 -> V_36 - 1 ) % 8 ;
unsigned int V_67 = ( V_66 << 3 ) | V_65 ;
int V_68 ;
unsigned long V_12 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_67 , V_69 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_8 -> V_14 == 12 && V_64 > 0 )
V_64 += 0x7 ;
V_64 &= 0xf ;
F_2 ( V_64 , V_2 -> V_5 + V_6 ) ;
if ( V_31 -> V_53 == V_52 )
V_10 -> V_29 = V_31 -> V_59 * V_31 -> V_36 ;
else
V_10 -> V_29 = 0 ;
V_68 = 0 ;
V_68 |= V_70 | V_71 ;
if ( V_31 -> V_44 == V_46 )
V_68 |= V_72 ;
if ( V_31 -> V_49 == V_50 ) {
V_68 |= V_73 | V_74 ;
F_10 ( V_2 ) ;
}
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_68 , V_17 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
unsigned int V_75 = F_4 ( V_2 -> V_5 + V_76 ) ;
unsigned int V_77 = F_4 ( V_2 -> V_5 + V_78 ) ;
return ( V_77 << 8 ) | V_75 ;
}
static T_1 F_26 ( int V_79 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_27 * V_28 = V_2 -> V_81 ;
struct V_62 * V_63 ;
struct V_30 * V_31 ;
unsigned long V_12 ;
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
V_63 = V_28 -> V_63 ;
V_31 = & V_63 -> V_31 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_82 = F_3 ( V_2 , V_20 ) & V_90 ;
if ( V_82 == 0 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
return V_89 ;
}
for ( V_35 = 0 ; V_35 < V_91 ; V_35 ++ ) {
V_3 = F_25 ( V_2 ) ;
if ( V_28 -> V_92 == 0x0fff ) {
V_83 = ! ! ( V_3 & V_93 ) ;
V_84 = ! ! ( V_3 & V_94 ) ;
} else {
V_83 = false ;
V_84 = ! ! ( F_4 ( V_2 -> V_5 + V_6 ) &
V_95 ) ;
}
if ( V_83 || V_84 )
break;
if ( V_28 -> V_92 == 0x0fff )
V_3 >>= 4 ;
if ( V_31 -> V_53 == V_54 || V_10 -> V_29 > 0 ) {
F_27 ( V_28 , V_3 & V_28 -> V_92 ) ;
V_10 -> V_29 -- ;
}
}
V_63 -> V_96 |= V_97 ;
if ( V_84 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
V_63 -> V_96 |= V_98 | V_99 ;
F_28 ( V_2 , V_28 ) ;
return V_89 ;
}
if ( V_31 -> V_53 == V_54 || V_10 -> V_29 > 0 ) {
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
} else {
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_9 ( V_2 ) ;
V_63 -> V_96 |= V_99 ;
}
F_28 ( V_2 , V_28 ) ;
return V_89 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_100 * V_101 ,
unsigned long V_102 )
{
unsigned int V_82 ;
V_82 = F_4 ( V_2 -> V_5 + V_85 ) ;
if ( ( V_82 & V_103 ) == 0 )
return 0 ;
return - V_104 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_100 * V_101 ,
unsigned int * V_105 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_37 = F_15 ( V_101 -> V_106 ) ;
unsigned int V_38 = F_16 ( V_101 -> V_106 ) ;
unsigned long V_12 ;
unsigned int V_3 ;
int V_107 ;
int V_35 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_37 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_28 -> V_92 == 0x0fff && V_38 )
V_38 += 0x7 ;
V_38 &= 0xf ;
F_2 ( V_38 , V_2 -> V_5 + V_6 ) ;
F_31 ( 5 ) ;
for ( V_35 = 0 ; V_35 < V_101 -> V_108 ; V_35 ++ ) {
F_32 ( 0 , V_2 -> V_5 + V_78 ) ;
V_107 = F_33 ( V_2 , V_28 , V_101 , F_29 , 0 ) ;
if ( V_107 )
return V_107 ;
V_3 = F_25 ( V_2 ) ;
if ( V_28 -> V_92 == 0x0fff )
V_3 >>= 4 ;
V_105 [ V_35 ] = V_3 & V_28 -> V_92 ;
}
return V_101 -> V_108 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_100 * V_101 ,
unsigned int * V_105 )
{
V_105 [ 1 ] = ( F_4 ( V_2 -> V_5 + V_85 ) >> 4 ) & 0x7 ;
return V_101 -> V_108 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
struct V_100 * V_101 ,
unsigned int * V_105 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_12 ;
if ( F_36 ( V_28 , V_105 ) ) {
V_10 -> V_19 = V_28 -> V_109 << 4 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
}
V_105 [ 1 ] = V_28 -> V_109 ;
return V_101 -> V_108 ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_110 = V_8 ? V_8 - V_111 : - V_41 ;
int V_112 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_112 = F_3 ( V_2 , V_113 ) & 0x3 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
switch ( V_112 ) {
case 0x0 :
if ( V_110 == V_114 || V_110 == V_115 )
break;
F_17 ( V_2 -> V_40 , L_3 ) ;
V_110 = V_114 ;
break;
case 0x2 :
if ( V_110 == V_116 || V_110 == V_117 )
break;
F_17 ( V_2 -> V_40 , L_4 ) ;
V_110 = V_116 ;
break;
case 0x3 :
if ( V_110 == V_118 || V_110 == V_119 ||
V_110 == V_120 )
break;
F_17 ( V_2 -> V_40 , L_5 ) ;
V_110 = V_118 ;
break;
default:
F_17 ( V_2 -> V_40 , L_6 ,
V_112 ) ;
V_110 = - V_41 ;
break;
}
return V_110 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
const struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
unsigned int V_79 = V_122 -> V_123 [ 1 ] ;
unsigned long V_12 ;
int V_110 ;
int V_107 ;
V_10 = F_39 ( V_2 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_124 ;
V_107 = F_40 ( V_2 , V_122 -> V_123 [ 0 ] , V_125 ) ;
if ( V_107 )
return V_107 ;
V_110 = F_37 ( V_2 ) ;
if ( V_110 < 0 ) {
F_17 ( V_2 -> V_40 , L_7 ) ;
return - V_126 ;
}
V_2 -> V_127 = V_111 + V_110 ;
V_8 = F_6 ( V_2 ) ;
V_2 -> V_128 = V_8 -> V_129 ;
if ( V_79 > 1 && V_79 <= 7 ) {
V_107 = F_41 ( V_79 , F_26 , 0 , V_2 -> V_128 ,
V_2 ) ;
if ( V_107 == 0 )
V_2 -> V_79 = V_79 ;
}
V_107 = F_42 ( V_2 , 3 ) ;
if ( V_107 )
return V_107 ;
V_28 = & V_2 -> V_130 [ 0 ] ;
V_2 -> V_81 = V_28 ;
V_28 -> type = V_131 ;
V_28 -> V_132 = V_133 | V_134 ;
V_28 -> V_39 = 8 ;
V_28 -> V_92 = ( 1 << V_8 -> V_14 ) - 1 ;
V_28 -> V_135 = V_8 -> V_136 ;
V_28 -> V_137 = F_30 ;
if ( V_2 -> V_79 ) {
V_28 -> V_132 |= V_138 ;
V_28 -> V_139 = 8 ;
V_28 -> V_140 = F_18 ;
V_28 -> V_141 = F_24 ;
V_28 -> V_142 = F_13 ;
}
V_28 = & V_2 -> V_130 [ 1 ] ;
V_28 -> type = V_143 ;
V_28 -> V_132 = V_133 ;
V_28 -> V_39 = 3 ;
V_28 -> V_92 = 1 ;
V_28 -> V_135 = & V_144 ;
V_28 -> V_145 = F_34 ;
V_28 = & V_2 -> V_130 [ 2 ] ;
V_28 -> type = V_146 ;
V_28 -> V_132 = V_147 | V_133 ;
V_28 -> V_39 = 4 ;
V_28 -> V_92 = 1 ;
V_28 -> V_135 = & V_144 ;
V_28 -> V_145 = F_35 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
