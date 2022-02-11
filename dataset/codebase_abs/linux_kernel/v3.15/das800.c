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
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_21 = 0 ;
if ( F_11 ( V_2 -> V_5 + V_22 , 0 , 1 , V_10 -> V_23 , 2 ) )
V_21 ++ ;
if ( F_11 ( V_2 -> V_5 + V_22 , 0 , 2 , V_10 -> V_24 , 2 ) )
V_21 ++ ;
if ( V_21 )
return - 1 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_27 = false ;
V_10 -> V_28 = 0 ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_29 * V_30 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_21 = 0 ;
V_21 |= F_14 ( & V_30 -> V_31 , V_32 | V_33 ) ;
V_21 |= F_14 ( & V_30 -> V_34 , V_35 ) ;
V_21 |= F_14 ( & V_30 -> V_36 , V_37 | V_33 ) ;
V_21 |= F_14 ( & V_30 -> V_38 , V_39 ) ;
V_21 |= F_14 ( & V_30 -> V_40 , V_39 | V_41 ) ;
if ( V_21 )
return 1 ;
V_21 |= F_15 ( V_30 -> V_31 ) ;
V_21 |= F_15 ( V_30 -> V_36 ) ;
V_21 |= F_15 ( V_30 -> V_40 ) ;
if ( V_21 )
return 2 ;
V_21 |= F_16 ( & V_30 -> V_42 , 0 ) ;
if ( V_30 -> V_36 == V_37 )
V_21 |= F_17 ( & V_30 -> V_43 ,
V_8 -> V_44 ) ;
V_21 |= F_17 ( & V_30 -> V_45 , 1 ) ;
V_21 |= F_16 ( & V_30 -> V_46 , V_30 -> V_45 ) ;
if ( V_30 -> V_40 == V_39 )
V_21 |= F_17 ( & V_30 -> V_47 , 1 ) ;
else
V_21 |= F_16 ( & V_30 -> V_47 , 0 ) ;
if ( V_21 )
return 3 ;
if ( V_30 -> V_36 == V_37 ) {
int V_48 = V_30 -> V_43 ;
F_18 ( V_49 ,
& V_10 -> V_23 ,
& V_10 -> V_24 ,
& V_30 -> V_43 , V_30 -> V_50 ) ;
if ( V_48 != V_30 -> V_43 )
V_21 ++ ;
}
if ( V_21 )
return 4 ;
if ( V_30 -> V_51 ) {
unsigned int V_52 = F_19 ( V_30 -> V_51 [ 0 ] ) ;
unsigned int V_53 = F_20 ( V_30 -> V_51 [ 0 ] ) ;
unsigned int V_54 ;
int V_55 ;
for ( V_55 = 1 ; V_55 < V_30 -> V_45 ; V_55 ++ ) {
V_54 = V_30 -> V_51 [ V_55 ] ;
if ( F_19 ( V_54 ) != ( V_52 + V_55 ) % V_56 ) {
F_21 ( V_2 -> V_57 ,
L_1 ) ;
V_21 ++ ;
}
if ( F_20 ( V_54 ) != V_53 ) {
F_21 ( V_2 -> V_57 ,
L_2 ) ;
V_21 ++ ;
}
}
}
if ( V_21 )
return 5 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_58 * V_59 = V_26 -> V_59 ;
unsigned int V_60 = F_20 ( V_59 -> V_30 . V_51 [ 0 ] ) ;
unsigned int V_61 = F_19 ( V_59 -> V_30 . V_51 [ 0 ] ) ;
unsigned int V_62 = ( V_61 + V_59 -> V_30 . V_45 - 1 ) % 8 ;
unsigned int V_63 = ( V_62 << 3 ) | V_61 ;
int V_64 ;
unsigned long V_12 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_63 , V_65 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_8 -> V_14 == 12 && V_60 > 0 )
V_60 += 0x7 ;
V_60 &= 0xf ;
F_2 ( V_60 , V_2 -> V_5 + V_6 ) ;
if ( V_59 -> V_30 . V_40 == V_39 ) {
V_10 -> V_28 = V_59 -> V_30 . V_47 * V_59 -> V_30 . V_45 ;
V_10 -> V_27 = false ;
} else {
V_10 -> V_27 = true ;
V_10 -> V_28 = 0 ;
}
V_64 = 0 ;
V_64 |= V_66 | V_67 ;
if ( V_59 -> V_30 . V_31 == V_33 )
V_64 |= V_68 ;
if ( V_59 -> V_30 . V_36 == V_37 ) {
V_64 |= V_69 | V_70 ;
if ( F_10 ( V_2 ) < 0 ) {
F_23 ( V_2 , L_3 ) ;
return - 1 ;
}
}
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_64 , V_17 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_71 = F_4 ( V_2 -> V_5 + V_72 ) ;
unsigned int V_73 = F_4 ( V_2 -> V_5 + V_74 ) ;
return ( V_73 << 8 ) | V_71 ;
}
static T_1 F_25 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_25 * V_26 = V_2 -> V_77 ;
struct V_58 * V_59 = V_26 ? V_26 -> V_59 : NULL ;
unsigned long V_12 ;
unsigned int V_78 ;
unsigned int V_3 ;
bool V_79 ;
bool V_80 ;
int V_55 ;
V_78 = F_4 ( V_2 -> V_5 + V_81 ) ;
if ( ! ( V_78 & V_82 ) )
return V_83 ;
if ( ! V_2 -> V_84 )
return V_85 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_78 = F_3 ( V_2 , V_20 ) & V_86 ;
if ( V_78 == 0 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
return V_85 ;
}
for ( V_55 = 0 ; V_55 < V_87 ; V_55 ++ ) {
V_3 = F_24 ( V_2 ) ;
if ( V_26 -> V_88 == 0x0fff ) {
V_79 = ! ! ( V_3 & V_89 ) ;
V_80 = ! ! ( V_3 & V_90 ) ;
} else {
V_79 = false ;
V_80 = ! ! ( F_4 ( V_2 -> V_5 + V_6 ) &
V_91 ) ;
}
if ( V_79 || V_80 )
break;
if ( V_26 -> V_88 == 0x0fff )
V_3 >>= 4 ;
if ( V_10 -> V_28 > 0 || V_10 -> V_27 ) {
F_26 ( V_26 , V_3 & V_26 -> V_88 ) ;
V_10 -> V_28 -- ;
}
}
V_59 -> V_92 |= V_93 ;
if ( V_80 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
V_59 -> V_92 |= V_94 | V_95 ;
F_27 ( V_2 , V_26 ) ;
return V_85 ;
}
if ( V_10 -> V_28 > 0 || V_10 -> V_27 ) {
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
} else {
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_9 ( V_2 ) ;
V_59 -> V_92 |= V_95 ;
}
F_27 ( V_2 , V_26 ) ;
return V_85 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_96 * V_97 ,
unsigned long V_98 )
{
unsigned int V_78 ;
V_78 = F_4 ( V_2 -> V_5 + V_81 ) ;
if ( ( V_78 & V_99 ) == 0 )
return 0 ;
return - V_100 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_96 * V_97 ,
unsigned int * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_52 = F_19 ( V_97 -> V_102 ) ;
unsigned int V_53 = F_20 ( V_97 -> V_102 ) ;
unsigned long V_12 ;
unsigned int V_3 ;
int V_103 ;
int V_55 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_52 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_26 -> V_88 == 0x0fff && V_53 )
V_53 += 0x7 ;
V_53 &= 0xf ;
F_2 ( V_53 , V_2 -> V_5 + V_6 ) ;
F_30 ( 5 ) ;
for ( V_55 = 0 ; V_55 < V_97 -> V_104 ; V_55 ++ ) {
F_31 ( 0 , V_2 -> V_5 + V_74 ) ;
V_103 = F_32 ( V_2 , V_26 , V_97 , F_28 , 0 ) ;
if ( V_103 )
return V_103 ;
V_3 = F_24 ( V_2 ) ;
if ( V_26 -> V_88 == 0x0fff )
V_3 >>= 4 ;
V_101 [ V_55 ] = V_3 & V_26 -> V_88 ;
}
return V_97 -> V_104 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_96 * V_97 ,
unsigned int * V_101 )
{
V_101 [ 1 ] = ( F_4 ( V_2 -> V_5 + V_81 ) >> 4 ) & 0x7 ;
return V_97 -> V_104 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_96 * V_97 ,
unsigned int * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_12 ;
if ( F_35 ( V_26 , V_101 ) ) {
V_10 -> V_19 = V_26 -> V_105 << 4 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
}
V_101 [ 1 ] = V_26 -> V_105 ;
return V_97 -> V_104 ;
}
static int F_36 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_106 = V_8 ? V_8 - V_107 : - V_108 ;
int V_109 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_109 = F_3 ( V_2 , V_110 ) & 0x3 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
switch ( V_109 ) {
case 0x0 :
if ( V_106 == V_111 || V_106 == V_112 )
break;
F_37 ( V_2 -> V_57 , L_4 ) ;
V_106 = V_111 ;
break;
case 0x2 :
if ( V_106 == V_113 || V_106 == V_114 )
break;
F_37 ( V_2 -> V_57 , L_5 ) ;
V_106 = V_113 ;
break;
case 0x3 :
if ( V_106 == V_115 || V_106 == V_116 ||
V_106 == V_117 )
break;
F_37 ( V_2 -> V_57 , L_6 ) ;
V_106 = V_115 ;
break;
default:
F_37 ( V_2 -> V_57 , L_7 ,
V_109 ) ;
V_106 = - V_108 ;
break;
}
return V_106 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
unsigned int V_75 = V_119 -> V_120 [ 1 ] ;
unsigned long V_12 ;
int V_106 ;
int V_103 ;
V_10 = F_39 ( V_2 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_121 ;
V_103 = F_40 ( V_2 , V_119 -> V_120 [ 0 ] , V_122 ) ;
if ( V_103 )
return V_103 ;
V_106 = F_36 ( V_2 ) ;
if ( V_106 < 0 ) {
F_37 ( V_2 -> V_57 , L_8 ) ;
return - V_123 ;
}
V_2 -> V_124 = V_107 + V_106 ;
V_8 = F_6 ( V_2 ) ;
V_2 -> V_125 = V_8 -> V_126 ;
if ( V_75 > 1 && V_75 <= 7 ) {
V_103 = F_41 ( V_75 , F_25 , 0 , V_2 -> V_125 ,
V_2 ) ;
if ( V_103 == 0 )
V_2 -> V_75 = V_75 ;
}
V_103 = F_42 ( V_2 , 3 ) ;
if ( V_103 )
return V_103 ;
V_26 = & V_2 -> V_127 [ 0 ] ;
V_2 -> V_77 = V_26 ;
V_26 -> type = V_128 ;
V_26 -> V_129 = V_130 | V_131 ;
V_26 -> V_132 = 8 ;
V_26 -> V_88 = ( 1 << V_8 -> V_14 ) - 1 ;
V_26 -> V_133 = V_8 -> V_134 ;
V_26 -> V_135 = F_29 ;
if ( V_2 -> V_75 ) {
V_26 -> V_129 |= V_136 ;
V_26 -> V_137 = 8 ;
V_26 -> V_138 = F_13 ;
V_26 -> V_139 = F_22 ;
V_26 -> V_140 = F_12 ;
}
V_26 = & V_2 -> V_127 [ 1 ] ;
V_26 -> type = V_141 ;
V_26 -> V_129 = V_130 ;
V_26 -> V_132 = 3 ;
V_26 -> V_88 = 1 ;
V_26 -> V_133 = & V_142 ;
V_26 -> V_143 = F_33 ;
V_26 = & V_2 -> V_127 [ 2 ] ;
V_26 -> type = V_144 ;
V_26 -> V_129 = V_145 | V_130 ;
V_26 -> V_132 = 4 ;
V_26 -> V_88 = 1 ;
V_26 -> V_133 = & V_142 ;
V_26 -> V_143 = F_34 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
