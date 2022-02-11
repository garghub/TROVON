static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_12 + V_13 ) ;
if ( V_11 & V_14 )
return 0 ;
return - V_15 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_19 = F_5 ( V_6 -> V_18 ) ;
unsigned int V_20 = F_6 ( V_6 -> V_18 ) ;
unsigned int V_21 ;
int V_22 ;
int V_23 ;
if ( V_6 -> V_18 & V_24 ) {
F_7 ( V_25 | F_8 ( V_9 -> V_26 ) ,
V_9 -> V_12 + V_27 ) ;
V_17 = 0 ;
} else {
F_7 ( 0 , V_9 -> V_12 + V_27 ) ;
}
V_21 = F_9 ( V_17 ) | F_10 ( V_19 ) ;
if ( F_11 ( V_4 , V_19 ) )
V_21 |= V_28 ;
if ( V_20 != V_29 )
V_21 |= V_30 ;
F_7 ( V_21 , V_9 -> V_12 + V_13 ) ;
F_7 ( 0 , V_9 -> V_31 + V_32 ) ;
for ( V_23 = 0 ; V_23 < V_6 -> V_23 ; V_23 ++ ) {
F_7 ( 0 , V_9 -> V_31 + V_33 ) ;
V_22 = F_12 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_22 )
return V_22 ;
V_16 [ V_23 ] = F_2 ( V_9 -> V_31 + V_33 ) ;
}
return V_23 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_34 = V_16 [ 0 ] ;
unsigned int V_35 = V_16 [ 1 ] ;
switch ( V_34 ) {
case V_36 :
if ( V_35 >= 8 ) {
F_14 ( V_2 -> V_37 ,
L_1 ,
V_35 ) ;
return - V_38 ;
}
V_9 -> V_26 = V_35 ;
break;
default:
return - V_38 ;
}
return V_6 -> V_23 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_19 = F_5 ( V_6 -> V_18 ) ;
unsigned int V_39 = V_4 -> V_40 [ V_17 ] ;
unsigned long V_41 ;
int V_42 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
V_9 -> V_44 &= ~ ( V_45 |
F_17 ( V_17 ) ) ;
V_9 -> V_44 |= V_46 | F_18 ( V_17 , V_19 ) ;
F_7 ( V_9 -> V_44 , V_9 -> V_12 + V_47 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
for ( V_42 = 0 ; V_42 < V_6 -> V_23 ; V_42 ++ ) {
V_39 = V_16 [ V_42 ] ;
F_7 ( V_39 , V_9 -> V_48 + F_20 ( V_17 ) ) ;
}
V_4 -> V_40 [ V_17 ] = V_39 ;
return V_6 -> V_23 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_19 = F_5 ( V_6 -> V_18 ) ;
unsigned int V_39 = V_4 -> V_40 [ V_17 ] ;
unsigned long V_41 ;
int V_42 ;
F_7 ( 0 , V_9 -> V_48 + V_49 ) ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
V_9 -> V_44 &= ~ ( V_50 | F_17 ( V_17 ) |
V_51 ) ;
V_9 -> V_44 |= V_46 | F_18 ( V_17 , V_19 ) |
F_22 ( V_17 ) | V_52 ;
F_7 ( V_9 -> V_44 , V_9 -> V_12 + V_47 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
for ( V_42 = 0 ; V_42 < V_6 -> V_23 ; V_42 ++ ) {
V_39 = V_16 [ V_42 ] ;
F_7 ( V_39 , V_9 -> V_48 + V_53 ) ;
}
V_4 -> V_40 [ V_17 ] = V_39 ;
return V_6 -> V_23 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_24 ( V_9 -> V_54 + V_55 ) ;
if ( ( V_11 & V_56 ) == 0 )
return 0 ;
return - V_15 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
int V_22 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_6 -> V_23 ; V_42 ++ ) {
V_22 = F_12 ( V_2 , V_4 , V_6 , F_23 , 0 ) ;
if ( V_22 )
return V_22 ;
F_26 ( V_57 | V_58 ,
V_9 -> V_54 + V_55 ) ;
F_26 ( V_17 & 0xff , V_9 -> V_54 + V_59 ) ;
F_26 ( V_57 | V_60 ,
V_9 -> V_54 + V_55 ) ;
F_26 ( ( V_17 >> 8 ) & 0xff ,
V_9 -> V_54 + V_59 ) ;
F_26 ( V_57 | V_61 ,
V_9 -> V_54 + V_55 ) ;
V_22 = F_12 ( V_2 , V_4 , V_6 , F_23 , 0 ) ;
if ( V_22 )
return V_22 ;
V_16 [ V_42 ] = F_24 ( V_9 -> V_54 + V_59 ) ;
}
return V_6 -> V_23 ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned int V_39 , unsigned int V_62 ,
bool V_63 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_64 ;
unsigned int V_65 ;
V_64 = V_25 | F_8 ( V_9 -> V_26 ) ;
if ( V_63 ) {
V_64 |= V_66 ;
F_7 ( V_64 , V_9 -> V_12 + V_27 ) ;
}
for ( V_65 = 1 << ( V_62 - 1 ) ; V_65 ; V_65 >>= 1 ) {
if ( V_39 & V_65 )
V_64 |= V_67 ;
else
V_64 &= ~ V_67 ;
F_28 ( 1 ) ;
F_7 ( V_64 , V_9 -> V_12 + V_27 ) ;
}
F_28 ( 1 ) ;
V_64 = V_25 | F_8 ( V_9 -> V_26 ) ;
if ( ! V_63 ) {
F_7 ( V_64 | V_68 ,
V_9 -> V_12 + V_27 ) ;
F_28 ( 1 ) ;
}
F_7 ( V_64 , V_9 -> V_12 + V_27 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
if ( V_6 -> V_23 ) {
unsigned int V_39 = V_16 [ V_6 -> V_23 - 1 ] ;
if ( V_4 -> V_40 [ V_17 ] != V_39 ) {
F_27 ( V_2 , ( V_17 << 8 ) | V_39 , 11 ,
false ) ;
V_4 -> V_40 [ V_17 ] = V_39 ;
}
}
return V_6 -> V_23 ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_39 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_39 |= V_25 | F_8 ( V_9 -> V_26 ) ;
F_7 ( V_39 , V_9 -> V_12 + V_27 ) ;
F_28 ( 1 ) ;
F_7 ( V_39 | V_69 ,
V_9 -> V_12 + V_27 ) ;
F_28 ( 1 ) ;
F_7 ( V_39 , V_9 -> V_12 + V_27 ) ;
F_28 ( 1 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
if ( V_6 -> V_23 ) {
unsigned int V_39 = V_16 [ V_6 -> V_23 - 1 ] ;
if ( V_4 -> V_40 [ V_17 ] != V_39 ) {
F_30 ( V_2 , V_39 ) ;
V_4 -> V_40 [ V_17 ] = V_39 ;
}
}
return V_6 -> V_23 ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned int V_17 , unsigned int V_39 )
{
const struct V_70 * V_71 = V_2 -> V_72 ;
if ( V_71 -> V_73 ) {
F_27 ( V_2 , ( V_17 << 8 ) | V_39 , 10 , true ) ;
} else {
F_27 ( V_2 , V_39 , 7 , true ) ;
}
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_16 )
{
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
if ( V_6 -> V_23 ) {
unsigned int V_39 = V_16 [ V_6 -> V_23 - 1 ] ;
if ( V_4 -> V_40 [ V_17 ] != V_39 ) {
F_32 ( V_2 , V_17 , V_39 ) ;
V_4 -> V_40 [ V_17 ] = V_39 ;
}
}
return V_6 -> V_23 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_74 * V_75 )
{
unsigned int V_76 = F_4 ( V_75 -> V_77 [ 0 ] ) ;
unsigned int V_78 = F_5 ( V_75 -> V_77 [ 0 ] ) ;
int V_42 ;
for ( V_42 = 1 ; V_42 < V_75 -> V_79 ; V_42 ++ ) {
unsigned int V_17 = F_4 ( V_75 -> V_77 [ V_42 ] ) ;
unsigned int V_19 = F_5 ( V_75 -> V_77 [ V_42 ] ) ;
if ( V_17 != ( V_76 + V_42 ) % V_4 -> V_80 ) {
F_35 ( V_2 -> V_37 ,
L_2 ) ;
return - V_38 ;
}
if ( V_19 != V_78 ) {
F_35 ( V_2 -> V_37 ,
L_3 ) ;
return - V_38 ;
}
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_74 * V_75 )
{
const struct V_70 * V_71 = V_2 -> V_72 ;
int V_81 = 0 ;
unsigned int V_82 ;
V_81 |= F_37 ( & V_75 -> V_83 , V_84 | V_85 ) ;
V_81 |= F_37 ( & V_75 -> V_86 ,
V_87 | V_88 | V_85 ) ;
V_81 |= F_37 ( & V_75 -> V_89 ,
V_88 | V_84 | V_85 ) ;
V_81 |= F_37 ( & V_75 -> V_90 , V_91 ) ;
V_81 |= F_37 ( & V_75 -> V_92 , V_91 | V_93 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_38 ( V_75 -> V_83 ) ;
V_81 |= F_38 ( V_75 -> V_86 ) ;
V_81 |= F_38 ( V_75 -> V_89 ) ;
V_81 |= F_38 ( V_75 -> V_92 ) ;
if ( V_75 -> V_86 == V_87 && V_75 -> V_89 == V_84 )
V_81 |= - V_38 ;
if ( V_75 -> V_86 != V_87 && V_75 -> V_89 != V_84 )
V_81 |= - V_38 ;
if ( V_75 -> V_83 == V_85 &&
( V_75 -> V_89 == V_85 || V_75 -> V_86 == V_85 ) )
V_81 |= - V_38 ;
if ( V_81 )
return 2 ;
switch ( V_75 -> V_83 ) {
case V_84 :
V_81 |= F_39 ( & V_75 -> V_94 , 0 ) ;
break;
case V_85 :
if ( ( V_75 -> V_94
& ( V_95 & ~ ( V_96 | V_97 ) ) ) != 0 ) {
V_75 -> V_94 &= ~ ( V_95 &
~ ( V_96 | V_97 ) ) ;
V_81 |= - V_38 ;
}
if ( ! V_71 -> V_98 && ( V_75 -> V_94 & V_97 ) ) {
V_75 -> V_94 &= ( V_95 & ~ V_97 ) ;
V_81 |= - V_38 ;
}
break;
}
if ( V_75 -> V_86 == V_88 ) {
V_81 |= F_40 ( & V_75 -> V_99 ,
V_71 -> V_100 *
V_75 -> V_79 ) ;
}
if ( V_75 -> V_89 == V_88 ) {
V_81 |= F_40 ( & V_75 -> V_101 ,
V_71 -> V_100 ) ;
}
V_81 |= F_39 ( & V_75 -> V_102 ,
V_75 -> V_79 ) ;
if ( V_75 -> V_92 == V_91 )
V_81 |= F_40 ( & V_75 -> V_103 , 1 ) ;
else
V_81 |= F_39 ( & V_75 -> V_103 , 0 ) ;
if ( V_81 )
return 3 ;
if ( V_75 -> V_86 == V_88 ) {
V_82 = V_75 -> V_99 ;
F_41 ( V_2 -> V_104 , & V_82 , V_75 -> V_41 ) ;
V_81 |= F_39 ( & V_75 -> V_99 , V_82 ) ;
}
if ( V_75 -> V_89 == V_88 ) {
V_82 = V_75 -> V_101 ;
F_41 ( V_2 -> V_104 , & V_82 , V_75 -> V_41 ) ;
V_81 |= F_39 ( & V_75 -> V_101 , V_82 ) ;
}
if ( V_81 )
return 4 ;
if ( V_75 -> V_77 && V_75 -> V_79 > 0 )
V_81 |= F_34 ( V_2 , V_4 , V_75 ) ;
if ( V_81 )
return 5 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_70 * V_71 = V_2 -> V_72 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_105 * V_106 = V_4 -> V_106 ;
struct V_74 * V_75 = & V_106 -> V_75 ;
unsigned int V_78 = F_5 ( V_75 -> V_77 [ 0 ] ) ;
unsigned int V_21 ;
unsigned long V_41 ;
F_7 ( 0 , V_9 -> V_12 + V_27 ) ;
F_7 ( V_107 , V_9 -> V_12 + V_108 ) ;
F_7 ( 0 , V_9 -> V_31 + V_32 ) ;
V_21 = F_43 ( F_4 ( V_75 -> V_77 [ 0 ] ) ) |
F_44 ( F_4 ( V_75 -> V_77 [ V_75 -> V_79 - 1 ] ) ) |
F_10 ( V_78 ) ;
if ( F_11 ( V_4 , V_78 ) )
V_21 |= V_28 ;
if ( F_6 ( V_75 -> V_77 [ 0 ] ) != V_29 )
V_21 |= V_30 ;
if ( V_75 -> V_89 == V_85 || V_75 -> V_86 == V_85 )
V_21 |= V_109 ;
else
V_21 |= V_110 ;
F_7 ( V_21 , V_9 -> V_12 + V_13 ) ;
if ( V_75 -> V_86 == V_88 ||
V_75 -> V_89 == V_88 ) {
F_45 ( V_2 -> V_104 ) ;
F_46 ( V_2 -> V_104 , 1 , 2 , true ) ;
}
F_16 ( & V_2 -> V_43 , V_41 ) ;
V_9 -> V_111 |= V_112 ;
V_9 -> V_111 &= ~ V_113 ;
if ( V_75 -> V_41 & V_114 ) {
if ( V_75 -> V_89 == V_84 && V_75 -> V_79 > 1 ) {
V_9 -> V_111 |= V_115 ;
} else {
V_9 -> V_111 |= V_116 ;
}
} else {
V_9 -> V_111 |= V_117 ;
}
F_7 ( V_9 -> V_111 |
V_118 | V_119 | V_120 ,
V_9 -> V_12 + V_121 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
V_21 = 0 ;
if ( V_75 -> V_83 == V_84 ) {
V_21 |= V_122 ;
} else {
V_21 |= V_123 | V_124 | V_125 ;
if ( V_71 -> V_98 ) {
if ( V_75 -> V_94 & V_97 )
V_21 |= V_126 ;
if ( V_75 -> V_94 & V_96 )
V_21 |= V_127 ;
}
}
if ( V_75 -> V_89 == V_84 && V_75 -> V_79 > 1 )
V_21 |= V_128 ;
F_7 ( V_21 , V_9 -> V_12 + V_108 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_74 * V_75 )
{
unsigned int V_76 = F_4 ( V_75 -> V_77 [ 0 ] ) ;
if ( V_75 -> V_79 > 1 ) {
unsigned int V_129 = F_4 ( V_75 -> V_77 [ 1 ] ) ;
if ( V_76 != 0 || V_129 != 1 ) {
F_35 ( V_2 -> V_37 ,
L_4 ) ;
return - V_38 ;
}
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_74 * V_75 )
{
const struct V_70 * V_71 = V_2 -> V_72 ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_81 = 0 ;
V_81 |= F_37 ( & V_75 -> V_83 , V_130 ) ;
V_81 |= F_37 ( & V_75 -> V_86 ,
V_88 | V_85 ) ;
V_81 |= F_37 ( & V_75 -> V_89 , V_84 ) ;
V_81 |= F_37 ( & V_75 -> V_90 , V_91 ) ;
V_81 |= F_37 ( & V_75 -> V_92 , V_91 | V_93 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_38 ( V_75 -> V_86 ) ;
V_81 |= F_38 ( V_75 -> V_92 ) ;
if ( V_81 )
return 2 ;
V_81 |= F_39 ( & V_75 -> V_94 , 0 ) ;
if ( V_75 -> V_86 == V_88 ) {
V_81 |= F_40 ( & V_75 -> V_99 ,
V_71 -> V_131 ) ;
}
V_81 |= F_39 ( & V_75 -> V_102 ,
V_75 -> V_79 ) ;
if ( V_75 -> V_92 == V_91 )
V_81 |= F_40 ( & V_75 -> V_103 , 1 ) ;
else
V_81 |= F_39 ( & V_75 -> V_103 , 0 ) ;
if ( V_81 )
return 3 ;
if ( V_75 -> V_86 == V_88 ) {
unsigned int V_82 = V_75 -> V_99 ;
F_41 ( V_9 -> V_132 ,
& V_82 , V_75 -> V_41 ) ;
V_81 |= F_39 ( & V_75 -> V_99 , V_82 ) ;
}
if ( V_81 )
return 4 ;
if ( V_75 -> V_77 && V_75 -> V_79 > 0 )
V_81 |= F_47 ( V_2 , V_4 , V_75 ) ;
if ( V_81 )
return 5 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_41 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
V_9 -> V_111 &= ~ ( V_112 | V_133 ) ;
F_7 ( V_9 -> V_111 , V_9 -> V_12 + V_121 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
F_7 ( V_107 , V_9 -> V_12 + V_108 ) ;
F_7 ( V_134 , V_9 -> V_12 + V_13 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_135 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_136 ;
V_135 = F_51 ( V_4 , V_135 ) ;
V_136 = F_52 ( V_4 , V_9 -> V_137 , V_135 ) ;
V_135 = F_53 ( V_4 , V_136 ) ;
F_54 ( V_9 -> V_48 + V_53 ,
V_9 -> V_137 , V_135 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_138 )
{
const struct V_70 * V_71 = V_2 -> V_72 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_105 * V_106 = V_4 -> V_106 ;
struct V_74 * V_75 = & V_106 -> V_75 ;
unsigned long V_41 ;
if ( V_138 != V_75 -> V_94 )
return - V_38 ;
F_50 ( V_2 , V_4 , V_71 -> V_139 ) ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
V_9 -> V_111 |= V_140 | V_141 ;
F_7 ( V_9 -> V_111 | V_142 | V_143 ,
V_9 -> V_12 + V_121 ) ;
V_9 -> V_44 |= V_52 | V_46 | V_144 ;
F_7 ( V_9 -> V_44 , V_9 -> V_12 + V_47 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
V_106 -> V_145 = NULL ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_105 * V_106 = V_4 -> V_106 ;
struct V_74 * V_75 = & V_106 -> V_75 ;
unsigned int V_42 ;
unsigned long V_41 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
for ( V_42 = 0 ; V_42 < V_75 -> V_79 ; V_42 ++ ) {
unsigned int V_17 = F_4 ( V_75 -> V_77 [ V_42 ] ) ;
unsigned int V_19 = F_5 ( V_75 -> V_77 [ V_42 ] ) ;
V_9 -> V_44 |= F_22 ( V_17 ) ;
V_9 -> V_44 |= F_18 ( V_17 , V_19 ) ;
}
F_7 ( V_9 -> V_44 , V_9 -> V_12 + V_47 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
F_7 ( 0 , V_9 -> V_48 + V_49 ) ;
if ( V_75 -> V_86 == V_88 ) {
F_45 ( V_9 -> V_132 ) ;
F_46 ( V_9 -> V_132 , 1 , 2 , true ) ;
}
F_16 ( & V_2 -> V_43 , V_41 ) ;
switch ( V_75 -> V_86 ) {
case V_88 :
V_9 -> V_44 |= V_146 ;
break;
case V_85 :
V_9 -> V_44 |= V_147 ;
break;
default:
F_19 ( & V_2 -> V_43 , V_41 ) ;
F_14 ( V_2 -> V_37 , L_5 ) ;
return - 1 ;
}
F_19 ( & V_2 -> V_43 , V_41 ) ;
V_106 -> V_145 = F_55 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_41 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
V_9 -> V_111 &= ~ ( V_141 | V_140 ) ;
F_7 ( V_9 -> V_111 , V_9 -> V_12 + V_121 ) ;
V_9 -> V_44 &= ~ ( V_46 | V_51 ) ;
F_7 ( V_9 -> V_44 , V_9 -> V_12 + V_47 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
return 0 ;
}
static unsigned int F_58 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
const struct V_70 * V_71 = V_2 -> V_72 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = V_2 -> V_148 ;
struct V_105 * V_106 = V_4 -> V_106 ;
struct V_74 * V_75 = & V_106 -> V_75 ;
unsigned int V_149 = 0 ;
if ( V_11 & V_142 ) {
V_149 |= V_142 ;
if ( F_2 ( V_9 -> V_48 + V_47 ) & V_144 ) {
if ( V_75 -> V_92 == V_91 &&
V_106 -> V_150 >= V_75 -> V_103 ) {
V_106 -> V_151 |= V_152 ;
} else {
F_14 ( V_2 -> V_37 , L_6 ) ;
V_106 -> V_151 |= V_153 ;
}
}
} else if ( V_11 & V_143 ) {
V_149 |= V_143 ;
F_50 ( V_2 , V_4 , V_71 -> V_139 / 2 ) ;
}
F_59 ( V_2 , V_4 ) ;
return V_149 ;
}
static unsigned int F_60 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
const struct V_70 * V_71 = V_2 -> V_72 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = V_2 -> V_154 ;
struct V_105 * V_106 = V_4 -> V_106 ;
struct V_74 * V_75 = & V_106 -> V_75 ;
unsigned int V_149 = 0 ;
if ( V_11 & V_155 ) {
unsigned int V_156 ;
V_149 |= V_119 ;
V_156 = F_51 ( V_4 , V_71 -> V_139 / 2 ) ;
F_61 ( V_9 -> V_31 + V_33 ,
V_9 -> V_157 , V_156 ) ;
F_62 ( V_4 , V_9 -> V_157 , V_156 ) ;
if ( V_75 -> V_92 == V_91 &&
V_106 -> V_150 >= V_75 -> V_103 )
V_106 -> V_151 |= V_152 ;
} else if ( V_11 & ( V_158 | V_159 ) ) {
unsigned int V_42 ;
V_149 |= V_119 ;
for ( V_42 = 0 ; V_42 < 10000 ; V_42 ++ ) {
unsigned short V_39 ;
if ( ( F_2 ( V_9 -> V_12 + V_121 ) &
V_160 ) == 0 )
break;
V_39 = F_2 ( V_9 -> V_31 + V_33 ) ;
F_62 ( V_4 , & V_39 , 1 ) ;
if ( V_75 -> V_92 == V_91 &&
V_106 -> V_150 >= V_75 -> V_103 ) {
V_106 -> V_151 |= V_152 ;
break;
}
}
} else if ( V_11 & V_118 ) {
V_149 |= V_118 ;
F_14 ( V_2 -> V_37 ,
L_7 ) ;
}
if ( V_11 & V_120 ) {
V_149 |= V_120 ;
F_14 ( V_2 -> V_37 , L_8 ) ;
V_106 -> V_151 |= V_153 ;
}
F_59 ( V_2 , V_4 ) ;
return V_149 ;
}
static T_1 F_63 ( int V_161 , void * V_162 )
{
struct V_1 * V_2 = V_162 ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_149 = 0 ;
unsigned int V_163 ;
unsigned int V_11 ;
if ( ! V_2 -> V_164 )
return V_165 ;
V_163 = F_64 ( V_9 -> V_54 + V_166 ) ;
if ( ( V_167 & V_163 ) == 0 )
return V_165 ;
F_65 ( V_9 -> V_54 + V_168 ) ;
F_66 ( V_9 -> V_169 | V_170 ,
V_9 -> V_54 + V_166 ) ;
V_11 = F_2 ( V_9 -> V_12 + V_121 ) ;
if ( V_11 & V_171 )
V_149 |= F_58 ( V_2 , V_11 ) ;
if ( V_11 & V_172 )
V_149 |= F_60 ( V_2 , V_11 ) ;
if ( V_149 ) {
unsigned long V_41 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
F_7 ( V_9 -> V_111 | V_149 ,
V_9 -> V_12 + V_121 ) ;
F_19 ( & V_2 -> V_43 , V_41 ) ;
}
return V_173 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_174 * V_175 = F_68 ( V_2 ) ;
const struct V_70 * V_71 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_42 ;
int V_22 ;
if ( V_7 < F_69 ( V_176 ) )
V_71 = & V_176 [ V_7 ] ;
if ( ! V_71 )
return - V_177 ;
V_2 -> V_72 = V_71 ;
V_2 -> V_178 = V_71 -> V_179 ;
V_9 = F_70 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_180 ;
V_22 = F_71 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_9 -> V_54 = F_72 ( V_175 , 0 ) ;
V_9 -> V_12 = F_72 ( V_175 , 1 ) ;
V_9 -> V_31 = F_72 ( V_175 , 2 ) ;
V_2 -> V_181 = F_72 ( V_175 , 3 ) ;
if ( V_71 -> V_182 )
V_9 -> V_48 = F_72 ( V_175 , 4 ) ;
F_66 ( V_170 ,
V_9 -> V_54 + V_166 ) ;
V_22 = F_73 ( V_175 -> V_161 , F_63 , V_183 ,
V_2 -> V_178 , V_2 ) ;
if ( V_22 ) {
F_35 ( V_2 -> V_37 , L_9 ,
V_175 -> V_161 ) ;
return V_22 ;
}
V_2 -> V_161 = V_175 -> V_161 ;
V_2 -> V_104 = F_74 ( V_2 -> V_181 + V_184 ,
V_185 , V_186 , 0 ) ;
if ( ! V_2 -> V_104 )
return - V_180 ;
V_9 -> V_132 = F_74 ( V_2 -> V_181 + V_187 ,
V_185 ,
V_186 , 0 ) ;
if ( ! V_9 -> V_132 )
return - V_180 ;
V_22 = F_75 ( V_2 , 7 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_188 [ 0 ] ;
V_4 -> type = V_189 ;
V_4 -> V_190 = V_191 | V_192 | V_193 ;
V_4 -> V_80 = 16 ;
V_4 -> V_194 = V_71 -> V_195 ? 0xffff : 0x0fff ;
V_4 -> V_196 = V_71 -> V_197 ? & V_198
: & V_199 ;
V_4 -> V_200 = F_3 ;
V_4 -> V_201 = F_13 ;
if ( V_2 -> V_161 ) {
V_2 -> V_154 = V_4 ;
V_4 -> V_190 |= V_202 ;
V_4 -> V_203 = V_4 -> V_80 ;
V_4 -> V_204 = F_42 ;
V_4 -> V_205 = F_36 ;
V_4 -> V_206 = F_49 ;
}
V_4 = & V_2 -> V_188 [ 1 ] ;
if ( V_71 -> V_182 ) {
V_4 -> type = V_207 ;
V_4 -> V_190 = V_208 | V_192 ;
V_4 -> V_80 = 2 ;
V_4 -> V_194 = V_71 -> V_195 ? 0xffff : 0x0fff ;
V_4 -> V_196 = & V_209 ;
V_4 -> V_210 = ( V_71 -> V_211 )
? F_21
: F_15 ;
V_22 = F_76 ( V_4 ) ;
if ( V_22 )
return V_22 ;
if ( V_2 -> V_161 && V_71 -> V_211 ) {
V_2 -> V_148 = V_4 ;
V_4 -> V_190 |= V_212 ;
V_4 -> V_205 = F_48 ;
V_4 -> V_204 = F_56 ;
V_4 -> V_206 = F_57 ;
}
} else {
V_4 -> type = V_213 ;
}
V_4 = & V_2 -> V_188 [ 2 ] ;
V_22 = F_77 ( V_2 , V_4 , NULL , V_214 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_188 [ 3 ] ;
V_4 -> type = V_215 ;
V_4 -> V_190 = V_191 | V_216 ;
V_4 -> V_80 = 256 ;
V_4 -> V_194 = 0xff ;
V_4 -> V_200 = F_25 ;
V_4 = & V_2 -> V_188 [ 4 ] ;
V_4 -> type = V_217 ;
V_4 -> V_190 = V_208 | V_216 ;
V_4 -> V_80 = 8 ;
V_4 -> V_194 = 0xff ;
V_4 -> V_210 = F_29 ;
V_22 = F_76 ( V_4 ) ;
if ( V_22 )
return V_22 ;
for ( V_42 = 0 ; V_42 < V_4 -> V_80 ; V_42 ++ ) {
unsigned int V_39 = V_4 -> V_194 / 2 ;
F_27 ( V_2 , ( V_42 << 8 ) | V_39 , 11 , false ) ;
V_4 -> V_40 [ V_42 ] = V_39 ;
}
V_4 = & V_2 -> V_188 [ 5 ] ;
V_4 -> type = V_217 ;
V_4 -> V_190 = V_208 | V_216 ;
if ( V_71 -> V_73 ) {
V_4 -> V_80 = 2 ;
V_4 -> V_194 = 0xff ;
} else {
V_4 -> V_80 = 1 ;
V_4 -> V_194 = 0x7f ;
}
V_4 -> V_210 = F_33 ;
V_22 = F_76 ( V_4 ) ;
if ( V_22 )
return V_22 ;
for ( V_42 = 0 ; V_42 < V_4 -> V_80 ; V_42 ++ ) {
F_32 ( V_2 , V_42 , V_4 -> V_194 / 2 ) ;
V_4 -> V_40 [ V_42 ] = V_4 -> V_194 / 2 ;
}
V_4 = & V_2 -> V_188 [ 6 ] ;
if ( V_71 -> V_218 ) {
V_4 -> type = V_217 ;
V_4 -> V_190 = V_208 | V_216 ;
V_4 -> V_80 = 1 ;
V_4 -> V_194 = 0xff ;
V_4 -> V_210 = F_31 ;
V_22 = F_76 ( V_4 ) ;
if ( V_22 )
return V_22 ;
for ( V_42 = 0 ; V_42 < V_4 -> V_80 ; V_42 ++ ) {
F_30 ( V_2 , V_4 -> V_194 / 2 ) ;
V_4 -> V_40 [ V_42 ] = V_4 -> V_194 / 2 ;
}
} else {
V_4 -> type = V_213 ;
}
F_64 ( V_9 -> V_54 + V_168 ) ;
V_9 -> V_169 = F_78 ( 3 ) | F_79 ( 3 ) |
V_219 ;
F_66 ( V_9 -> V_169 | V_170 ,
V_9 -> V_54 + V_166 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 ) {
if ( V_9 -> V_54 )
F_66 ( V_170 ,
V_9 -> V_54 + V_166 ) ;
F_81 ( V_9 -> V_132 ) ;
}
F_82 ( V_2 ) ;
}
static int F_83 ( struct V_174 * V_2 ,
const struct V_220 * V_34 )
{
return F_84 ( V_2 , & V_221 ,
V_34 -> V_222 ) ;
}
