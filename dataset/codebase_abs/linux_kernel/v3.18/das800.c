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
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_30 = 0 ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_31 * V_32 )
{
unsigned int V_33 = F_14 ( V_32 -> V_34 [ 0 ] ) ;
unsigned int V_35 = F_15 ( V_32 -> V_34 [ 0 ] ) ;
int V_36 ;
for ( V_36 = 1 ; V_36 < V_32 -> V_37 ; V_36 ++ ) {
unsigned int V_38 = F_14 ( V_32 -> V_34 [ V_36 ] ) ;
unsigned int V_39 = F_15 ( V_32 -> V_34 [ V_36 ] ) ;
if ( V_38 != ( V_33 + V_36 ) % V_29 -> V_40 ) {
F_16 ( V_2 -> V_41 ,
L_1 ) ;
return - V_42 ;
}
if ( V_39 != V_35 ) {
F_16 ( V_2 -> V_41 ,
L_2 ) ;
return - V_42 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_31 * V_32 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_43 = 0 ;
unsigned int V_44 ;
V_43 |= F_18 ( & V_32 -> V_45 , V_46 | V_47 ) ;
V_43 |= F_18 ( & V_32 -> V_48 , V_49 ) ;
V_43 |= F_18 ( & V_32 -> V_50 , V_51 | V_47 ) ;
V_43 |= F_18 ( & V_32 -> V_52 , V_53 ) ;
V_43 |= F_18 ( & V_32 -> V_54 , V_53 | V_55 ) ;
if ( V_43 )
return 1 ;
V_43 |= F_19 ( V_32 -> V_45 ) ;
V_43 |= F_19 ( V_32 -> V_50 ) ;
V_43 |= F_19 ( V_32 -> V_54 ) ;
if ( V_43 )
return 2 ;
V_43 |= F_20 ( & V_32 -> V_56 , 0 ) ;
if ( V_32 -> V_50 == V_51 )
V_43 |= F_21 ( & V_32 -> V_57 ,
V_8 -> V_58 ) ;
V_43 |= F_21 ( & V_32 -> V_37 , 1 ) ;
V_43 |= F_20 ( & V_32 -> V_59 , V_32 -> V_37 ) ;
if ( V_32 -> V_54 == V_53 )
V_43 |= F_21 ( & V_32 -> V_60 , 1 ) ;
else
V_43 |= F_20 ( & V_32 -> V_60 , 0 ) ;
if ( V_43 )
return 3 ;
if ( V_32 -> V_50 == V_51 ) {
V_44 = V_32 -> V_57 ;
F_22 ( V_61 ,
& V_11 -> V_26 ,
& V_11 -> V_27 ,
& V_44 , V_32 -> V_62 ) ;
V_43 |= F_20 ( & V_32 -> V_57 , V_44 ) ;
}
if ( V_43 )
return 4 ;
if ( V_32 -> V_34 && V_32 -> V_37 > 0 )
V_43 |= F_13 ( V_2 , V_29 , V_32 ) ;
if ( V_43 )
return 5 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
const struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_63 * V_64 = V_29 -> V_64 ;
struct V_31 * V_32 = & V_64 -> V_32 ;
unsigned int V_65 = F_15 ( V_32 -> V_34 [ 0 ] ) ;
unsigned int V_66 = F_14 ( V_32 -> V_34 [ 0 ] ) ;
unsigned int V_67 = ( V_66 + V_32 -> V_37 - 1 ) % 8 ;
unsigned int V_68 = ( V_67 << 3 ) | V_66 ;
int V_69 ;
unsigned long V_13 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_68 , V_70 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
if ( V_8 -> V_15 == 12 && V_65 > 0 )
V_65 += 0x7 ;
V_65 &= 0xf ;
F_2 ( V_65 , V_2 -> V_5 + V_6 ) ;
if ( V_32 -> V_54 == V_53 )
V_11 -> V_30 = V_32 -> V_60 * V_32 -> V_37 ;
else
V_11 -> V_30 = 0 ;
V_69 = 0 ;
V_69 |= V_71 | V_72 ;
if ( V_32 -> V_45 == V_47 )
V_69 |= V_73 ;
if ( V_32 -> V_50 == V_51 ) {
V_69 |= V_74 | V_75 ;
F_9 ( V_2 ) ;
}
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_69 , V_18 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_76 = F_4 ( V_2 -> V_5 + V_77 ) ;
unsigned int V_78 = F_4 ( V_2 -> V_5 + V_79 ) ;
return ( V_78 << 8 ) | V_76 ;
}
static T_1 F_25 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_28 * V_29 = V_2 -> V_82 ;
struct V_63 * V_64 ;
struct V_31 * V_32 ;
unsigned long V_13 ;
unsigned int V_83 ;
unsigned int V_3 ;
bool V_84 ;
bool V_85 ;
int V_36 ;
V_83 = F_4 ( V_2 -> V_5 + V_86 ) ;
if ( ! ( V_83 & V_87 ) )
return V_88 ;
if ( ! V_2 -> V_89 )
return V_90 ;
V_64 = V_29 -> V_64 ;
V_32 = & V_64 -> V_32 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
V_83 = F_3 ( V_2 , V_21 ) & V_91 ;
if ( V_83 == 0 ) {
F_7 ( & V_2 -> V_14 , V_13 ) ;
return V_90 ;
}
for ( V_36 = 0 ; V_36 < V_92 ; V_36 ++ ) {
V_3 = F_24 ( V_2 ) ;
if ( V_29 -> V_93 == 0x0fff ) {
V_84 = ! ! ( V_3 & V_94 ) ;
V_85 = ! ! ( V_3 & V_95 ) ;
} else {
V_84 = false ;
V_85 = ! ! ( F_4 ( V_2 -> V_5 + V_6 ) &
V_96 ) ;
}
if ( V_84 || V_85 )
break;
if ( V_29 -> V_93 == 0x0fff )
V_3 >>= 4 ;
if ( V_32 -> V_54 == V_55 || V_11 -> V_30 > 0 ) {
F_26 ( V_29 , V_3 & V_29 -> V_93 ) ;
V_11 -> V_30 -- ;
}
}
V_64 -> V_97 |= V_98 ;
if ( V_85 ) {
F_7 ( & V_2 -> V_14 , V_13 ) ;
V_64 -> V_97 |= V_99 | V_100 ;
F_27 ( V_2 , V_29 ) ;
return V_90 ;
}
if ( V_32 -> V_54 == V_55 || V_11 -> V_30 > 0 ) {
F_1 ( V_2 , V_19 | V_11 -> V_20 ,
V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
} else {
F_7 ( & V_2 -> V_14 , V_13 ) ;
F_8 ( V_2 ) ;
V_64 -> V_97 |= V_100 ;
}
F_27 ( V_2 , V_29 ) ;
return V_90 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_101 * V_102 ,
unsigned long V_103 )
{
unsigned int V_83 ;
V_83 = F_4 ( V_2 -> V_5 + V_86 ) ;
if ( ( V_83 & V_104 ) == 0 )
return 0 ;
return - V_105 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_101 * V_102 ,
unsigned int * V_106 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_38 = F_14 ( V_102 -> V_107 ) ;
unsigned int V_39 = F_15 ( V_102 -> V_107 ) ;
unsigned long V_13 ;
unsigned int V_3 ;
int V_108 ;
int V_36 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_38 | V_11 -> V_20 , V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
if ( V_29 -> V_93 == 0x0fff && V_39 )
V_39 += 0x7 ;
V_39 &= 0xf ;
F_2 ( V_39 , V_2 -> V_5 + V_6 ) ;
F_30 ( 5 ) ;
for ( V_36 = 0 ; V_36 < V_102 -> V_109 ; V_36 ++ ) {
F_31 ( 0 , V_2 -> V_5 + V_79 ) ;
V_108 = F_32 ( V_2 , V_29 , V_102 , F_28 , 0 ) ;
if ( V_108 )
return V_108 ;
V_3 = F_24 ( V_2 ) ;
if ( V_29 -> V_93 == 0x0fff )
V_3 >>= 4 ;
V_106 [ V_36 ] = V_3 & V_29 -> V_93 ;
}
return V_102 -> V_109 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_101 * V_102 ,
unsigned int * V_106 )
{
V_106 [ 1 ] = ( F_4 ( V_2 -> V_5 + V_86 ) >> 4 ) & 0x7 ;
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
int V_111 = V_8 ? V_8 - V_112 : - V_42 ;
int V_113 ;
unsigned long V_13 ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
V_113 = F_3 ( V_2 , V_114 ) & 0x3 ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
switch ( V_113 ) {
case 0x0 :
if ( V_111 == V_115 || V_111 == V_116 )
break;
F_16 ( V_2 -> V_41 , L_3 ) ;
V_111 = V_115 ;
break;
case 0x2 :
if ( V_111 == V_117 || V_111 == V_118 )
break;
F_16 ( V_2 -> V_41 , L_4 ) ;
V_111 = V_117 ;
break;
case 0x3 :
if ( V_111 == V_119 || V_111 == V_120 ||
V_111 == V_121 )
break;
F_16 ( V_2 -> V_41 , L_5 ) ;
V_111 = V_119 ;
break;
default:
F_16 ( V_2 -> V_41 , L_6 ,
V_113 ) ;
V_111 = - V_42 ;
break;
}
return V_111 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
const struct V_7 * V_8 ;
struct V_10 * V_11 ;
struct V_28 * V_29 ;
unsigned int V_80 = V_123 -> V_124 [ 1 ] ;
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
F_16 ( V_2 -> V_41 , L_7 ) ;
return - V_126 ;
}
V_2 -> V_9 = V_112 + V_111 ;
V_8 = V_2 -> V_9 ;
V_2 -> V_127 = V_8 -> V_128 ;
if ( V_80 > 1 && V_80 <= 7 ) {
V_108 = F_40 ( V_80 , F_25 , 0 , V_2 -> V_127 ,
V_2 ) ;
if ( V_108 == 0 )
V_2 -> V_80 = V_80 ;
}
V_108 = F_41 ( V_2 , 3 ) ;
if ( V_108 )
return V_108 ;
V_29 = & V_2 -> V_129 [ 0 ] ;
V_2 -> V_82 = V_29 ;
V_29 -> type = V_130 ;
V_29 -> V_131 = V_132 | V_133 ;
V_29 -> V_40 = 8 ;
V_29 -> V_93 = ( 1 << V_8 -> V_15 ) - 1 ;
V_29 -> V_134 = V_8 -> V_135 ;
V_29 -> V_136 = F_29 ;
if ( V_2 -> V_80 ) {
V_29 -> V_131 |= V_137 ;
V_29 -> V_138 = 8 ;
V_29 -> V_139 = F_17 ;
V_29 -> V_140 = F_23 ;
V_29 -> V_141 = F_12 ;
}
V_29 = & V_2 -> V_129 [ 1 ] ;
V_29 -> type = V_142 ;
V_29 -> V_131 = V_132 ;
V_29 -> V_40 = 3 ;
V_29 -> V_93 = 1 ;
V_29 -> V_134 = & V_143 ;
V_29 -> V_144 = F_33 ;
V_29 = & V_2 -> V_129 [ 2 ] ;
V_29 -> type = V_145 ;
V_29 -> V_131 = V_146 | V_132 ;
V_29 -> V_40 = 4 ;
V_29 -> V_93 = 1 ;
V_29 -> V_134 = & V_143 ;
V_29 -> V_144 = F_34 ;
F_8 ( V_2 ) ;
F_6 ( & V_2 -> V_14 , V_13 ) ;
F_1 ( V_2 , V_19 | V_11 -> V_20 , V_21 ) ;
F_7 ( & V_2 -> V_14 , V_13 ) ;
return 0 ;
}
