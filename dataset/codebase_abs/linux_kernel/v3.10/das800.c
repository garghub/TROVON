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
& V_30 -> V_43 ,
V_30 -> V_50 & V_51 ) ;
if ( V_48 != V_30 -> V_43 )
V_21 ++ ;
}
if ( V_21 )
return 4 ;
if ( V_30 -> V_52 ) {
unsigned int V_53 = F_19 ( V_30 -> V_52 [ 0 ] ) ;
unsigned int V_54 = F_20 ( V_30 -> V_52 [ 0 ] ) ;
unsigned int V_55 ;
int V_56 ;
for ( V_56 = 1 ; V_56 < V_30 -> V_45 ; V_56 ++ ) {
V_55 = V_30 -> V_52 [ V_56 ] ;
if ( F_19 ( V_55 ) != ( V_53 + V_56 ) % V_57 ) {
F_21 ( V_2 -> V_58 ,
L_1 ) ;
V_21 ++ ;
}
if ( F_20 ( V_55 ) != V_54 ) {
F_21 ( V_2 -> V_58 ,
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
struct V_59 * V_60 = V_26 -> V_60 ;
unsigned int V_61 = F_20 ( V_60 -> V_30 . V_52 [ 0 ] ) ;
unsigned int V_62 = F_19 ( V_60 -> V_30 . V_52 [ 0 ] ) ;
unsigned int V_63 = ( V_62 + V_60 -> V_30 . V_45 - 1 ) % 8 ;
unsigned int V_64 = ( V_63 << 3 ) | V_62 ;
int V_65 ;
unsigned long V_12 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_64 , V_66 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_8 -> V_14 == 12 && V_61 > 0 )
V_61 += 0x7 ;
V_61 &= 0xf ;
F_2 ( V_61 , V_2 -> V_5 + V_6 ) ;
switch ( V_60 -> V_30 . V_40 ) {
case V_39 :
V_10 -> V_28 = V_60 -> V_30 . V_47 * V_60 -> V_30 . V_45 ;
V_10 -> V_27 = false ;
break;
case V_41 :
V_10 -> V_27 = true ;
V_10 -> V_28 = 0 ;
break;
default:
break;
}
V_65 = 0 ;
V_65 |= V_67 | V_68 ;
if ( V_60 -> V_30 . V_31 == V_33 )
V_65 |= V_69 ;
switch ( V_60 -> V_30 . V_36 ) {
case V_37 :
V_65 |= V_70 | V_71 ;
if ( F_10 ( V_2 ) < 0 ) {
F_23 ( V_2 , L_3 ) ;
return - 1 ;
}
break;
case V_33 :
break;
default:
break;
}
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_65 , V_17 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
V_60 -> V_72 = 0 ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_73 = F_4 ( V_2 -> V_5 + V_74 ) ;
unsigned int V_75 = F_4 ( V_2 -> V_5 + V_76 ) ;
return ( V_75 << 8 ) | V_73 ;
}
static T_1 F_25 ( int V_77 , void * V_78 )
{
struct V_1 * V_2 = V_78 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_25 * V_26 = V_2 -> V_79 ;
struct V_59 * V_60 = V_26 ? V_26 -> V_60 : NULL ;
unsigned long V_12 ;
unsigned int V_80 ;
unsigned int V_3 ;
bool V_81 ;
bool V_82 ;
int V_56 ;
V_80 = F_4 ( V_2 -> V_5 + V_83 ) ;
if ( ! ( V_80 & V_84 ) )
return V_85 ;
if ( ! V_2 -> V_86 )
return V_87 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_80 = F_3 ( V_2 , V_20 ) & V_88 ;
if ( V_80 == 0 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
return V_87 ;
}
for ( V_56 = 0 ; V_56 < V_89 ; V_56 ++ ) {
V_3 = F_24 ( V_2 ) ;
if ( V_26 -> V_90 == 0x0fff ) {
V_81 = ! ! ( V_3 & V_91 ) ;
V_82 = ! ! ( V_3 & V_92 ) ;
} else {
V_81 = false ;
V_82 = ! ! ( F_4 ( V_2 -> V_5 + V_6 ) &
V_93 ) ;
}
if ( V_81 || V_82 )
break;
if ( V_26 -> V_90 == 0x0fff )
V_3 >>= 4 ;
if ( V_10 -> V_28 > 0 || V_10 -> V_27 ) {
F_26 ( V_26 , V_3 & V_26 -> V_90 ) ;
V_10 -> V_28 -- ;
}
}
V_60 -> V_72 |= V_94 ;
if ( V_82 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_12 ( V_2 , V_26 ) ;
V_60 -> V_72 |= V_95 | V_96 ;
F_27 ( V_2 , V_26 ) ;
V_60 -> V_72 = 0 ;
return V_87 ;
}
if ( V_10 -> V_28 > 0 || V_10 -> V_27 ) {
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
} else {
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_9 ( V_2 ) ;
V_60 -> V_72 |= V_96 ;
}
F_27 ( V_2 , V_26 ) ;
V_60 -> V_72 = 0 ;
return V_87 ;
}
static int F_28 ( struct V_1 * V_2 , int V_97 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_97 ; V_56 ++ ) {
if ( ! ( F_4 ( V_2 -> V_5 + V_83 ) & V_98 ) )
return 0 ;
}
return - V_99 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_100 * V_101 ,
unsigned int * V_102 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_53 = F_19 ( V_101 -> V_103 ) ;
unsigned int V_54 = F_20 ( V_101 -> V_103 ) ;
unsigned long V_12 ;
unsigned int V_3 ;
int V_104 ;
int V_56 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_53 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_26 -> V_90 == 0x0fff && V_54 )
V_54 += 0x7 ;
V_54 &= 0xf ;
F_2 ( V_54 , V_2 -> V_5 + V_6 ) ;
F_30 ( 5 ) ;
for ( V_56 = 0 ; V_56 < V_101 -> V_105 ; V_56 ++ ) {
F_31 ( 0 , V_2 -> V_5 + V_76 ) ;
V_104 = F_28 ( V_2 , 1000 ) ;
if ( V_104 )
return V_104 ;
V_3 = F_24 ( V_2 ) ;
if ( V_26 -> V_90 == 0x0fff )
V_3 >>= 4 ;
V_102 [ V_56 ] = V_3 & V_26 -> V_90 ;
}
return V_101 -> V_105 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_100 * V_101 ,
unsigned int * V_102 )
{
V_102 [ 1 ] = ( F_4 ( V_2 -> V_5 + V_83 ) >> 4 ) & 0x7 ;
return V_101 -> V_105 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_100 * V_101 ,
unsigned int * V_102 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_106 = V_102 [ 0 ] ;
unsigned int V_107 = V_102 [ 1 ] ;
unsigned long V_12 ;
if ( V_106 ) {
V_26 -> V_108 &= ~ V_106 ;
V_26 -> V_108 |= ( V_107 & V_106 ) ;
V_10 -> V_19 = V_26 -> V_108 << 4 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
}
V_102 [ 1 ] = V_26 -> V_108 ;
return V_101 -> V_105 ;
}
static int F_34 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
int V_109 = V_8 ? V_8 - V_110 : - V_111 ;
int V_112 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_112 = F_3 ( V_2 , V_113 ) & 0x3 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
switch ( V_112 ) {
case 0x0 :
if ( V_109 == V_114 || V_109 == V_115 )
break;
F_35 ( V_2 -> V_58 , L_4 ) ;
V_109 = V_114 ;
break;
case 0x2 :
if ( V_109 == V_116 || V_109 == V_117 )
break;
F_35 ( V_2 -> V_58 , L_5 ) ;
V_109 = V_116 ;
break;
case 0x3 :
if ( V_109 == V_118 || V_109 == V_119 ||
V_109 == V_120 )
break;
F_35 ( V_2 -> V_58 , L_6 ) ;
V_109 = V_118 ;
break;
default:
F_35 ( V_2 -> V_58 , L_7 ,
V_112 ) ;
V_109 = - V_111 ;
break;
}
return V_109 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
unsigned int V_77 = V_122 -> V_123 [ 1 ] ;
unsigned long V_12 ;
int V_109 ;
int V_104 ;
V_10 = F_37 ( sizeof( * V_10 ) , V_124 ) ;
if ( ! V_10 )
return - V_125 ;
V_2 -> V_11 = V_10 ;
V_104 = F_38 ( V_2 , V_122 -> V_123 [ 0 ] , V_126 ) ;
if ( V_104 )
return V_104 ;
V_109 = F_34 ( V_2 ) ;
if ( V_109 < 0 ) {
F_35 ( V_2 -> V_58 , L_8 ) ;
return - V_127 ;
}
V_2 -> V_128 = V_110 + V_109 ;
V_8 = F_6 ( V_2 ) ;
V_2 -> V_129 = V_8 -> V_130 ;
if ( V_77 > 1 && V_77 <= 7 ) {
V_104 = F_39 ( V_77 , F_25 , 0 , V_2 -> V_129 ,
V_2 ) ;
if ( V_104 == 0 )
V_2 -> V_77 = V_77 ;
}
V_104 = F_40 ( V_2 , 3 ) ;
if ( V_104 )
return V_104 ;
V_26 = & V_2 -> V_131 [ 0 ] ;
V_2 -> V_79 = V_26 ;
V_26 -> type = V_132 ;
V_26 -> V_133 = V_134 | V_135 ;
V_26 -> V_136 = 8 ;
V_26 -> V_90 = ( 1 << V_8 -> V_14 ) - 1 ;
V_26 -> V_137 = V_8 -> V_138 ;
V_26 -> V_139 = F_29 ;
if ( V_2 -> V_77 ) {
V_26 -> V_133 |= V_140 ;
V_26 -> V_141 = 8 ;
V_26 -> V_142 = F_13 ;
V_26 -> V_143 = F_22 ;
V_26 -> V_144 = F_12 ;
}
V_26 = & V_2 -> V_131 [ 1 ] ;
V_26 -> type = V_145 ;
V_26 -> V_133 = V_134 ;
V_26 -> V_136 = 3 ;
V_26 -> V_90 = 1 ;
V_26 -> V_137 = & V_146 ;
V_26 -> V_147 = F_32 ;
V_26 = & V_2 -> V_131 [ 2 ] ;
V_26 -> type = V_148 ;
V_26 -> V_133 = V_149 | V_134 ;
V_26 -> V_136 = 4 ;
V_26 -> V_90 = 1 ;
V_26 -> V_137 = & V_146 ;
V_26 -> V_147 = F_33 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
