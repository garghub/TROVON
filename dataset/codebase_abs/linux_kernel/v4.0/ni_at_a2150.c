static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ 0 ] ;
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_16 ;
struct V_17 * V_18 = & V_16 -> V_18 ;
unsigned short * V_19 = V_11 -> V_20 ;
unsigned int V_21 , V_22 , V_23 , V_24 ;
unsigned short V_25 ;
int V_26 ;
int V_27 ;
if ( ! V_4 -> V_28 )
return V_29 ;
V_26 = F_2 ( V_4 -> V_30 + V_31 ) ;
if ( ( V_26 & V_32 ) == 0 )
return V_33 ;
if ( V_26 & V_34 ) {
V_16 -> V_35 |= V_36 ;
F_3 ( V_4 , V_13 ) ;
}
if ( ( V_26 & V_37 ) == 0 ) {
V_16 -> V_35 |= V_36 ;
F_3 ( V_4 , V_13 ) ;
return V_29 ;
}
V_23 = F_4 ( V_11 -> V_38 ) ;
V_21 = F_5 ( V_13 , V_11 -> V_39 ) ;
V_22 = V_21 - F_5 ( V_13 , V_23 ) ;
if ( V_6 -> V_40 < V_22 && V_18 -> V_41 == V_42 )
V_22 = V_6 -> V_40 ;
V_24 = 0 ;
if ( V_18 -> V_41 == V_43 ) {
V_24 = F_5 ( V_13 , V_11 -> V_39 ) ;
} else if ( V_6 -> V_40 > V_21 ) {
V_24 = V_6 -> V_40 - V_21 ;
if ( V_24 > V_21 )
V_24 = V_21 ;
}
if ( V_23 )
V_24 = 0 ;
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ ) {
V_25 = V_19 [ V_27 ] ;
V_25 ^= 0x8000 ;
F_6 ( V_13 , & V_25 , 1 ) ;
if ( V_18 -> V_41 == V_42 ) {
if ( -- V_6 -> V_40 == 0 ) {
V_16 -> V_35 |= V_44 ;
break;
}
}
}
if ( V_24 ) {
V_11 -> V_39 = F_7 ( V_13 , V_24 ) ;
F_8 ( V_11 ) ;
}
F_3 ( V_4 , V_13 ) ;
F_9 ( 0x00 , V_4 -> V_30 + V_45 ) ;
return V_29 ;
}
static int F_10 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ 0 ] ;
V_6 -> V_46 &= ~ V_47 & ~ V_48 ;
F_9 ( V_6 -> V_46 , V_4 -> V_30 + V_49 ) ;
F_4 ( V_11 -> V_38 ) ;
F_9 ( 0 , V_4 -> V_30 + V_50 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 , unsigned int * V_51 ,
unsigned int V_52 )
{
const struct V_53 * V_54 = V_4 -> V_55 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_56 , V_57 , V_58 ;
int V_59 , V_60 , V_61 , V_62 ;
int V_27 , V_63 ;
V_59 = 3 ;
V_60 = 0 ;
V_56 = V_54 -> clock [ V_60 ] * ( 1 << V_59 ) ;
V_61 = 0 ;
V_62 = V_54 -> V_64 - 1 ;
V_57 = V_54 -> clock [ V_62 ] * ( 1 << V_61 ) ;
if ( * V_51 < V_57 )
* V_51 = V_57 ;
if ( * V_51 > V_56 )
* V_51 = V_56 ;
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ ) {
for ( V_63 = 0 ; V_63 < V_54 -> V_64 ; V_63 ++ ) {
V_58 = V_54 -> clock [ V_63 ] * ( 1 << V_27 ) ;
if ( V_58 < V_56 && V_58 >= * V_51 ) {
V_59 = V_27 ;
V_60 = V_63 ;
V_56 = V_58 ;
}
if ( V_58 > V_57 && V_58 <= * V_51 ) {
V_61 = V_27 ;
V_62 = V_63 ;
V_57 = V_58 ;
}
}
}
switch ( V_52 & V_65 ) {
case V_66 :
default:
if ( V_56 - * V_51 < * V_51 - V_57 )
* V_51 = V_56 ;
else
* V_51 = V_57 ;
break;
case V_67 :
* V_51 = V_56 ;
break;
case V_68 :
* V_51 = V_57 ;
break;
}
V_6 -> V_69 &= ~ V_70 ;
if ( * V_51 == V_56 ) {
V_6 -> V_69 |=
F_12 ( V_60 ) |
F_13 ( V_59 ) ;
} else {
V_6 -> V_69 |=
F_12 ( V_62 ) |
F_13 ( V_61 ) ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
unsigned int V_71 ,
unsigned int V_72 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_71 + V_72 > 4 )
return - 1 ;
V_6 -> V_69 &= ~ V_73 ;
switch ( V_72 ) {
case 1 :
V_6 -> V_69 |= F_15 ( 0x4 | V_71 ) ;
break;
case 2 :
if ( V_71 == 0 )
V_6 -> V_69 |= F_15 ( 0x2 ) ;
else if ( V_71 == 2 )
V_6 -> V_69 |= F_15 ( 0x3 ) ;
else
return - 1 ;
break;
case 4 :
V_6 -> V_69 |= F_15 ( 0x1 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_16 ( struct V_3 * V_4 ,
struct V_12 * V_13 ,
struct V_17 * V_18 )
{
unsigned int V_74 = F_17 ( V_18 -> V_75 [ 0 ] ) ;
unsigned int V_76 = F_18 ( V_18 -> V_75 [ 0 ] ) ;
int V_27 ;
if ( V_18 -> V_77 == 2 && ( V_74 == 1 || V_74 == 3 ) ) {
F_19 ( V_4 -> V_78 ,
L_1 ) ;
return - V_79 ;
}
if ( V_18 -> V_77 == 3 ) {
F_19 ( V_4 -> V_78 ,
L_2 ) ;
return - V_79 ;
}
for ( V_27 = 1 ; V_27 < V_18 -> V_77 ; V_27 ++ ) {
unsigned int V_38 = F_17 ( V_18 -> V_75 [ V_27 ] ) ;
unsigned int V_80 = F_18 ( V_18 -> V_75 [ V_27 ] ) ;
if ( V_38 != ( V_74 + V_27 ) ) {
F_19 ( V_4 -> V_78 ,
L_3 ) ;
return - V_79 ;
}
if ( V_38 == 2 )
V_76 = V_80 ;
if ( V_80 != V_76 ) {
F_19 ( V_4 -> V_78 ,
L_4 ) ;
return - V_79 ;
}
}
return 0 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_12 * V_13 , struct V_17 * V_18 )
{
const struct V_53 * V_54 = V_4 -> V_55 ;
int V_81 = 0 ;
unsigned int V_82 ;
V_81 |= F_21 ( & V_18 -> V_83 , V_84 | V_85 ) ;
V_81 |= F_21 ( & V_18 -> V_86 , V_87 ) ;
V_81 |= F_21 ( & V_18 -> V_88 , V_84 ) ;
V_81 |= F_21 ( & V_18 -> V_89 , V_42 ) ;
V_81 |= F_21 ( & V_18 -> V_41 , V_42 | V_43 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_22 ( V_18 -> V_83 ) ;
V_81 |= F_22 ( V_18 -> V_41 ) ;
if ( V_81 )
return 2 ;
V_81 |= F_23 ( & V_18 -> V_90 , 0 ) ;
if ( V_18 -> V_88 == V_87 )
V_81 |= F_24 ( & V_18 -> V_91 ,
V_54 -> V_92 ) ;
V_81 |= F_24 ( & V_18 -> V_77 , 1 ) ;
V_81 |= F_23 ( & V_18 -> V_93 , V_18 -> V_77 ) ;
if ( V_18 -> V_41 == V_42 )
V_81 |= F_24 ( & V_18 -> V_94 , 1 ) ;
else
V_81 |= F_23 ( & V_18 -> V_94 , 0 ) ;
if ( V_81 )
return 3 ;
if ( V_18 -> V_86 == V_87 ) {
V_82 = V_18 -> V_95 ;
F_11 ( V_4 , & V_82 , V_18 -> V_52 ) ;
V_81 |= F_23 ( & V_18 -> V_95 , V_82 ) ;
}
if ( V_81 )
return 4 ;
if ( V_18 -> V_75 && V_18 -> V_77 > 0 )
V_81 |= F_16 ( V_4 , V_13 , V_18 ) ;
if ( V_81 )
return 5 ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 [ 0 ] ;
struct V_15 * V_16 = V_13 -> V_16 ;
struct V_17 * V_18 = & V_16 -> V_18 ;
unsigned long V_96 = V_4 -> V_30 + V_97 ;
unsigned int V_98 = V_6 -> V_69 ;
unsigned int V_99 ;
if ( V_18 -> V_52 & V_100 ) {
F_26 ( V_4 -> V_78 ,
L_5 ) ;
return - 1 ;
}
F_9 ( 0 , V_4 -> V_30 + V_50 ) ;
if ( F_14 ( V_4 , F_17 ( V_18 -> V_75 [ 0 ] ) ,
V_18 -> V_77 ) < 0 )
return - 1 ;
if ( F_18 ( V_18 -> V_75 [ 0 ] ) == V_101 )
V_6 -> V_69 |= V_102 ;
else
V_6 -> V_69 &= ~ V_102 ;
if ( F_18 ( V_18 -> V_75 [ 2 ] ) == V_101 )
V_6 -> V_69 |= V_103 ;
else
V_6 -> V_69 &= ~ V_103 ;
F_11 ( V_4 , & V_18 -> V_95 , V_18 -> V_52 ) ;
F_9 ( V_6 -> V_69 , V_4 -> V_30 + V_104 ) ;
V_6 -> V_40 = V_18 -> V_94 * V_18 -> V_77 ;
F_4 ( V_11 -> V_38 ) ;
#define F_27 333333333
V_11 -> V_39 = F_28 ( V_13 ) * V_18 -> V_77 *
F_27 / V_18 -> V_95 ;
if ( V_11 -> V_39 > V_11 -> V_105 )
V_11 -> V_39 = V_11 -> V_105 ;
if ( V_11 -> V_39 < F_28 ( V_13 ) )
V_11 -> V_39 = F_28 ( V_13 ) ;
V_11 -> V_39 -= V_11 -> V_39 % F_28 ( V_13 ) ;
F_8 ( V_11 ) ;
F_9 ( 0x00 , V_4 -> V_30 + V_45 ) ;
V_6 -> V_46 |= V_47 | V_48 ;
F_9 ( V_6 -> V_46 , V_4 -> V_30 + V_49 ) ;
F_29 ( V_96 , 0 , 2 , V_106 | V_107 ) ;
F_30 ( V_96 , 0 , 2 , 72 ) ;
V_99 = 0 ;
if ( V_18 -> V_83 == V_84 &&
( V_98 & V_70 ) !=
( V_6 -> V_69 & V_70 ) ) {
V_99 |= V_108 ;
} else {
V_99 |= V_109 ;
}
if ( V_18 -> V_83 == V_85 ) {
V_99 |= V_110 ;
} else if ( V_18 -> V_83 == V_111 ) {
F_26 ( V_4 -> V_78 , L_6 ) ;
}
F_9 ( V_99 , V_4 -> V_30 + V_112 ) ;
if ( V_18 -> V_83 == V_84 )
F_9 ( 0 , V_4 -> V_30 + V_113 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
struct V_12 * V_13 ,
struct V_114 * V_115 ,
unsigned long V_116 )
{
unsigned int V_26 ;
V_26 = F_2 ( V_4 -> V_30 + V_31 ) ;
if ( V_26 & V_117 )
return 0 ;
return - V_118 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_12 * V_13 ,
struct V_114 * V_115 , unsigned int * V_119 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_120 ;
int V_121 ;
F_9 ( 0 , V_4 -> V_30 + V_50 ) ;
if ( F_14 ( V_4 , F_17 ( V_115 -> V_122 ) , 1 ) < 0 )
return - 1 ;
V_6 -> V_69 &= ~ V_102 ;
V_6 -> V_69 &= ~ V_103 ;
F_9 ( V_6 -> V_69 , V_4 -> V_30 + V_104 ) ;
V_6 -> V_46 &= ~ V_47 & ~ V_48 ;
F_9 ( V_6 -> V_46 , V_4 -> V_30 + V_49 ) ;
F_9 ( 0 , V_4 -> V_30 + V_112 ) ;
F_9 ( 0 , V_4 -> V_30 + V_113 ) ;
for ( V_120 = 0 ; V_120 < 36 ; V_120 ++ ) {
V_121 = F_33 ( V_4 , V_13 , V_115 , F_31 , 0 ) ;
if ( V_121 )
return V_121 ;
F_2 ( V_4 -> V_30 + V_123 ) ;
}
for ( V_120 = 0 ; V_120 < V_115 -> V_120 ; V_120 ++ ) {
V_121 = F_33 ( V_4 , V_13 , V_115 , F_31 , 0 ) ;
if ( V_121 )
return V_121 ;
V_119 [ V_120 ] = F_2 ( V_4 -> V_30 + V_123 ) ;
V_119 [ V_120 ] ^= 0x8000 ;
}
F_9 ( 0 , V_4 -> V_30 + V_50 ) ;
return V_120 ;
}
static void F_34 ( struct V_3 * V_4 ,
struct V_124 * V_125 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_126 = V_125 -> V_127 [ 1 ] ;
unsigned int V_128 = V_125 -> V_127 [ 2 ] ;
if ( V_126 > 15 || V_128 > 7 ||
! ( ( 1 << V_126 ) & 0xdef8 ) || ! ( ( 1 << V_128 ) & 0xef ) )
return;
if ( F_35 ( V_126 , F_1 , 0 , V_4 -> V_129 , V_4 ) )
return;
V_6 -> V_9 = F_36 ( V_4 , 1 , V_128 , V_128 ,
V_130 ,
V_131 ) ;
if ( ! V_6 -> V_9 ) {
F_37 ( V_126 , V_4 ) ;
} else {
V_4 -> V_1 = V_126 ;
V_6 -> V_46 = F_38 ( V_126 ) |
F_39 ( V_128 ) ;
}
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 )
F_41 ( V_6 -> V_9 ) ;
}
static int F_42 ( struct V_3 * V_4 )
{
int V_26 = F_2 ( V_4 -> V_30 + V_31 ) ;
return F_43 ( V_26 ) ;
}
static int F_44 ( struct V_3 * V_4 , struct V_124 * V_125 )
{
const struct V_53 * V_54 ;
struct V_5 * V_6 ;
struct V_12 * V_13 ;
static const int V_132 = 2000 ;
int V_27 ;
int V_121 ;
V_6 = F_45 ( V_4 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_133 ;
V_121 = F_46 ( V_4 , V_125 -> V_127 [ 0 ] , 0x1c ) ;
if ( V_121 )
return V_121 ;
V_27 = F_42 ( V_4 ) ;
if ( V_27 >= F_47 ( V_134 ) )
return - V_135 ;
V_4 -> V_55 = V_134 + V_27 ;
V_54 = V_4 -> V_55 ;
V_4 -> V_129 = V_54 -> V_136 ;
F_34 ( V_4 , V_125 ) ;
V_121 = F_48 ( V_4 , 1 ) ;
if ( V_121 )
return V_121 ;
V_13 = & V_4 -> V_137 [ 0 ] ;
V_13 -> type = V_138 ;
V_13 -> V_139 = V_140 | V_141 | V_142 ;
V_13 -> V_143 = 4 ;
V_13 -> V_144 = 0xffff ;
V_13 -> V_145 = & V_146 ;
V_13 -> V_147 = F_32 ;
if ( V_4 -> V_1 ) {
V_4 -> V_14 = V_13 ;
V_13 -> V_139 |= V_148 ;
V_13 -> V_149 = V_13 -> V_143 ;
V_13 -> V_150 = F_25 ;
V_13 -> V_151 = F_20 ;
V_13 -> V_152 = F_10 ;
}
F_9 ( V_153 , V_4 -> V_30 + V_154 ) ;
F_9 ( V_6 -> V_46 , V_4 -> V_30 + V_49 ) ;
F_49 ( V_155 | V_156 , V_4 -> V_30 + V_104 ) ;
F_49 ( V_155 , V_4 -> V_30 + V_104 ) ;
V_6 -> V_69 = 0 ;
F_9 ( V_6 -> V_69 , V_4 -> V_30 + V_104 ) ;
for ( V_27 = 0 ; V_27 < V_132 ; V_27 ++ ) {
if ( ( V_157 & F_2 ( V_4 -> V_30 + V_31 ) ) == 0 )
break;
F_50 ( 1000 ) ;
}
if ( V_27 == V_132 ) {
F_26 ( V_4 -> V_78 ,
L_7 ) ;
return - V_158 ;
}
V_6 -> V_69 |= V_159 | V_160 ;
F_9 ( V_6 -> V_69 , V_4 -> V_30 + V_104 ) ;
return 0 ;
}
static void F_51 ( struct V_3 * V_4 )
{
if ( V_4 -> V_30 )
F_9 ( V_156 | V_155 , V_4 -> V_30 + V_104 ) ;
F_40 ( V_4 ) ;
F_52 ( V_4 ) ;
}
