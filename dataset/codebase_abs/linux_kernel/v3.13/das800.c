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
switch ( V_59 -> V_30 . V_40 ) {
case V_39 :
V_10 -> V_28 = V_59 -> V_30 . V_47 * V_59 -> V_30 . V_45 ;
V_10 -> V_27 = false ;
break;
case V_41 :
V_10 -> V_27 = true ;
V_10 -> V_28 = 0 ;
break;
default:
break;
}
V_64 = 0 ;
V_64 |= V_66 | V_67 ;
if ( V_59 -> V_30 . V_31 == V_33 )
V_64 |= V_68 ;
switch ( V_59 -> V_30 . V_36 ) {
case V_37 :
V_64 |= V_69 | V_70 ;
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
F_1 ( V_2 , V_64 , V_17 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
V_59 -> V_71 = 0 ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_72 = F_4 ( V_2 -> V_5 + V_73 ) ;
unsigned int V_74 = F_4 ( V_2 -> V_5 + V_75 ) ;
return ( V_74 << 8 ) | V_72 ;
}
static T_1 F_25 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_25 * V_26 = V_2 -> V_78 ;
struct V_58 * V_59 = V_26 ? V_26 -> V_59 : NULL ;
unsigned long V_12 ;
unsigned int V_79 ;
unsigned int V_3 ;
bool V_80 ;
bool V_81 ;
int V_55 ;
V_79 = F_4 ( V_2 -> V_5 + V_82 ) ;
if ( ! ( V_79 & V_83 ) )
return V_84 ;
if ( ! V_2 -> V_85 )
return V_86 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_79 = F_3 ( V_2 , V_20 ) & V_87 ;
if ( V_79 == 0 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
return V_86 ;
}
for ( V_55 = 0 ; V_55 < V_88 ; V_55 ++ ) {
V_3 = F_24 ( V_2 ) ;
if ( V_26 -> V_89 == 0x0fff ) {
V_80 = ! ! ( V_3 & V_90 ) ;
V_81 = ! ! ( V_3 & V_91 ) ;
} else {
V_80 = false ;
V_81 = ! ! ( F_4 ( V_2 -> V_5 + V_6 ) &
V_92 ) ;
}
if ( V_80 || V_81 )
break;
if ( V_26 -> V_89 == 0x0fff )
V_3 >>= 4 ;
if ( V_10 -> V_28 > 0 || V_10 -> V_27 ) {
F_26 ( V_26 , V_3 & V_26 -> V_89 ) ;
V_10 -> V_28 -- ;
}
}
V_59 -> V_71 |= V_93 ;
if ( V_81 ) {
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_12 ( V_2 , V_26 ) ;
V_59 -> V_71 |= V_94 | V_95 ;
F_27 ( V_2 , V_26 ) ;
V_59 -> V_71 = 0 ;
return V_86 ;
}
if ( V_10 -> V_28 > 0 || V_10 -> V_27 ) {
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
} else {
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_9 ( V_2 ) ;
V_59 -> V_71 |= V_95 ;
}
F_27 ( V_2 , V_26 ) ;
V_59 -> V_71 = 0 ;
return V_86 ;
}
static int F_28 ( struct V_1 * V_2 , int V_96 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_96 ; V_55 ++ ) {
if ( ! ( F_4 ( V_2 -> V_5 + V_82 ) & V_97 ) )
return 0 ;
}
return - V_98 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_99 * V_100 ,
unsigned int * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_52 = F_19 ( V_100 -> V_102 ) ;
unsigned int V_53 = F_20 ( V_100 -> V_102 ) ;
unsigned long V_12 ;
unsigned int V_3 ;
int V_103 ;
int V_55 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_52 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
if ( V_26 -> V_89 == 0x0fff && V_53 )
V_53 += 0x7 ;
V_53 &= 0xf ;
F_2 ( V_53 , V_2 -> V_5 + V_6 ) ;
F_30 ( 5 ) ;
for ( V_55 = 0 ; V_55 < V_100 -> V_104 ; V_55 ++ ) {
F_31 ( 0 , V_2 -> V_5 + V_75 ) ;
V_103 = F_28 ( V_2 , 1000 ) ;
if ( V_103 )
return V_103 ;
V_3 = F_24 ( V_2 ) ;
if ( V_26 -> V_89 == 0x0fff )
V_3 >>= 4 ;
V_101 [ V_55 ] = V_3 & V_26 -> V_89 ;
}
return V_100 -> V_104 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_99 * V_100 ,
unsigned int * V_101 )
{
V_101 [ 1 ] = ( F_4 ( V_2 -> V_5 + V_82 ) >> 4 ) & 0x7 ;
return V_100 -> V_104 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_99 * V_100 ,
unsigned int * V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_12 ;
if ( F_34 ( V_26 , V_101 ) ) {
V_10 -> V_19 = V_26 -> V_105 << 4 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 ,
V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
}
V_101 [ 1 ] = V_26 -> V_105 ;
return V_100 -> V_104 ;
}
static int F_35 ( struct V_1 * V_2 )
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
F_36 ( V_2 -> V_57 , L_4 ) ;
V_106 = V_111 ;
break;
case 0x2 :
if ( V_106 == V_113 || V_106 == V_114 )
break;
F_36 ( V_2 -> V_57 , L_5 ) ;
V_106 = V_113 ;
break;
case 0x3 :
if ( V_106 == V_115 || V_106 == V_116 ||
V_106 == V_117 )
break;
F_36 ( V_2 -> V_57 , L_6 ) ;
V_106 = V_115 ;
break;
default:
F_36 ( V_2 -> V_57 , L_7 ,
V_109 ) ;
V_106 = - V_108 ;
break;
}
return V_106 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
const struct V_7 * V_8 = F_6 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
unsigned int V_76 = V_119 -> V_120 [ 1 ] ;
unsigned long V_12 ;
int V_106 ;
int V_103 ;
V_10 = F_38 ( V_2 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_121 ;
V_103 = F_39 ( V_2 , V_119 -> V_120 [ 0 ] , V_122 ) ;
if ( V_103 )
return V_103 ;
V_106 = F_35 ( V_2 ) ;
if ( V_106 < 0 ) {
F_36 ( V_2 -> V_57 , L_8 ) ;
return - V_123 ;
}
V_2 -> V_124 = V_107 + V_106 ;
V_8 = F_6 ( V_2 ) ;
V_2 -> V_125 = V_8 -> V_126 ;
if ( V_76 > 1 && V_76 <= 7 ) {
V_103 = F_40 ( V_76 , F_25 , 0 , V_2 -> V_125 ,
V_2 ) ;
if ( V_103 == 0 )
V_2 -> V_76 = V_76 ;
}
V_103 = F_41 ( V_2 , 3 ) ;
if ( V_103 )
return V_103 ;
V_26 = & V_2 -> V_127 [ 0 ] ;
V_2 -> V_78 = V_26 ;
V_26 -> type = V_128 ;
V_26 -> V_129 = V_130 | V_131 ;
V_26 -> V_132 = 8 ;
V_26 -> V_89 = ( 1 << V_8 -> V_14 ) - 1 ;
V_26 -> V_133 = V_8 -> V_134 ;
V_26 -> V_135 = F_29 ;
if ( V_2 -> V_76 ) {
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
V_26 -> V_89 = 1 ;
V_26 -> V_133 = & V_142 ;
V_26 -> V_143 = F_32 ;
V_26 = & V_2 -> V_127 [ 2 ] ;
V_26 -> type = V_144 ;
V_26 -> V_129 = V_145 | V_130 ;
V_26 -> V_132 = 4 ;
V_26 -> V_89 = 1 ;
V_26 -> V_133 = & V_142 ;
V_26 -> V_143 = F_33 ;
F_9 ( V_2 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 , V_18 | V_10 -> V_19 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
