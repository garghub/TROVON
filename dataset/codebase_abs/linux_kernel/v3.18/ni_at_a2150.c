static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 ;
int V_4 ;
unsigned long V_5 ;
struct V_6 * V_7 = V_2 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 = V_7 -> V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
unsigned int V_18 , V_19 , V_20 , V_21 ;
unsigned short V_22 ;
static const int V_23 = sizeof( V_9 -> V_24 [ 0 ] ) ;
if ( ! V_7 -> V_25 ) {
F_2 ( V_7 -> V_26 , L_1 ) ;
return V_27 ;
}
V_15 = V_12 -> V_15 ;
V_17 = & V_15 -> V_17 ;
V_4 = F_3 ( V_7 -> V_28 + V_29 ) ;
if ( ( V_4 & V_30 ) == 0 ) {
F_2 ( V_7 -> V_26 , L_2 ) ;
return V_31 ;
}
if ( V_4 & V_32 ) {
F_2 ( V_7 -> V_26 , L_3 ) ;
V_15 -> V_33 |= V_34 | V_35 ;
F_4 ( V_7 , V_12 ) ;
}
if ( ( V_4 & V_36 ) == 0 ) {
F_2 ( V_7 -> V_26 ,
L_4 ) ;
V_15 -> V_33 |= V_34 | V_35 ;
F_4 ( V_7 , V_12 ) ;
return V_27 ;
}
V_5 = F_5 () ;
F_6 ( V_9 -> V_37 ) ;
F_7 ( V_9 -> V_37 ) ;
V_18 = V_9 -> V_38 / V_23 ;
V_20 = F_8 ( V_9 -> V_37 ) / V_23 ;
V_19 = V_18 - V_20 ;
if ( V_9 -> V_39 < V_19 && V_17 -> V_40 == V_41 )
V_19 = V_9 -> V_39 ;
V_21 = 0 ;
if ( V_17 -> V_40 == V_42 ) {
V_21 = V_9 -> V_38 / V_23 ;
} else if ( V_9 -> V_39 > V_18 ) {
V_21 = V_9 -> V_39 - V_18 ;
if ( V_21 > V_18 )
V_21 = V_18 ;
}
if ( V_20 )
V_21 = 0 ;
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
V_22 = V_9 -> V_24 [ V_3 ] ;
V_22 ^= 0x8000 ;
F_9 ( V_12 , V_22 ) ;
if ( V_17 -> V_40 == V_41 ) {
if ( -- V_9 -> V_39 == 0 ) {
V_15 -> V_33 |= V_35 ;
break;
}
}
}
if ( V_21 ) {
F_10 ( V_9 -> V_37 , F_11 ( V_9 -> V_24 ) ) ;
F_12 ( V_9 -> V_37 , V_21 * V_23 ) ;
F_13 ( V_9 -> V_37 ) ;
}
F_14 ( V_5 ) ;
V_15 -> V_33 |= V_43 ;
F_4 ( V_7 , V_12 ) ;
F_15 ( 0x00 , V_7 -> V_28 + V_44 ) ;
return V_27 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
V_9 -> V_45 &= ~ V_46 & ~ V_47 ;
F_15 ( V_9 -> V_45 , V_7 -> V_28 + V_48 ) ;
F_6 ( V_9 -> V_37 ) ;
F_15 ( 0 , V_7 -> V_28 + V_49 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , unsigned int * V_50 ,
unsigned int V_5 )
{
const struct V_51 * V_52 = V_7 -> V_53 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_54 , V_55 , V_56 ;
int V_57 , V_58 , V_59 , V_60 ;
int V_3 , V_61 ;
V_57 = 3 ;
V_58 = 0 ;
V_54 = V_52 -> clock [ V_58 ] * ( 1 << V_57 ) ;
V_59 = 0 ;
V_60 = V_52 -> V_62 - 1 ;
V_55 = V_52 -> clock [ V_60 ] * ( 1 << V_59 ) ;
if ( * V_50 < V_55 )
* V_50 = V_55 ;
if ( * V_50 > V_54 )
* V_50 = V_54 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_61 = 0 ; V_61 < V_52 -> V_62 ; V_61 ++ ) {
V_56 = V_52 -> clock [ V_61 ] * ( 1 << V_3 ) ;
if ( V_56 < V_54 && V_56 >= * V_50 ) {
V_57 = V_3 ;
V_58 = V_61 ;
V_54 = V_56 ;
}
if ( V_56 > V_55 && V_56 <= * V_50 ) {
V_59 = V_3 ;
V_60 = V_61 ;
V_55 = V_56 ;
}
}
}
switch ( V_5 & V_63 ) {
case V_64 :
default:
if ( V_54 - * V_50 < * V_50 - V_55 )
* V_50 = V_54 ;
else
* V_50 = V_55 ;
break;
case V_65 :
* V_50 = V_54 ;
break;
case V_66 :
* V_50 = V_55 ;
break;
}
V_9 -> V_67 &= ~ V_68 ;
if ( * V_50 == V_54 ) {
V_9 -> V_67 |=
F_18 ( V_58 ) |
F_19 ( V_57 ) ;
} else {
V_9 -> V_67 |=
F_18 ( V_60 ) |
F_19 ( V_59 ) ;
}
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
unsigned int V_69 ,
unsigned int V_70 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_69 + V_70 > 4 )
return - 1 ;
V_9 -> V_67 &= ~ V_71 ;
switch ( V_70 ) {
case 1 :
V_9 -> V_67 |= F_21 ( 0x4 | V_69 ) ;
break;
case 2 :
if ( V_69 == 0 )
V_9 -> V_67 |= F_21 ( 0x2 ) ;
else if ( V_69 == 2 )
V_9 -> V_67 |= F_21 ( 0x3 ) ;
else
return - 1 ;
break;
case 4 :
V_9 -> V_67 |= F_21 ( 0x1 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_16 * V_17 )
{
unsigned int V_72 = F_23 ( V_17 -> V_73 [ 0 ] ) ;
unsigned int V_74 = F_24 ( V_17 -> V_73 [ 0 ] ) ;
int V_3 ;
if ( V_17 -> V_75 == 2 && ( V_72 == 1 || V_72 == 3 ) ) {
F_25 ( V_7 -> V_26 ,
L_5 ) ;
return - V_76 ;
}
if ( V_17 -> V_75 == 3 ) {
F_25 ( V_7 -> V_26 ,
L_6 ) ;
return - V_76 ;
}
for ( V_3 = 1 ; V_3 < V_17 -> V_75 ; V_3 ++ ) {
unsigned int V_77 = F_23 ( V_17 -> V_73 [ V_3 ] ) ;
unsigned int V_78 = F_24 ( V_17 -> V_73 [ V_3 ] ) ;
if ( V_77 != ( V_72 + V_3 ) ) {
F_25 ( V_7 -> V_26 ,
L_7 ) ;
return - V_76 ;
}
if ( V_77 == 2 )
V_74 = V_78 ;
if ( V_78 != V_74 ) {
F_25 ( V_7 -> V_26 ,
L_8 ) ;
return - V_76 ;
}
}
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
struct V_11 * V_12 , struct V_16 * V_17 )
{
const struct V_51 * V_52 = V_7 -> V_53 ;
int V_79 = 0 ;
unsigned int V_80 ;
V_79 |= F_27 ( & V_17 -> V_81 , V_82 | V_83 ) ;
V_79 |= F_27 ( & V_17 -> V_84 , V_85 ) ;
V_79 |= F_27 ( & V_17 -> V_86 , V_82 ) ;
V_79 |= F_27 ( & V_17 -> V_87 , V_41 ) ;
V_79 |= F_27 ( & V_17 -> V_40 , V_41 | V_42 ) ;
if ( V_79 )
return 1 ;
V_79 |= F_28 ( V_17 -> V_81 ) ;
V_79 |= F_28 ( V_17 -> V_40 ) ;
if ( V_79 )
return 2 ;
V_79 |= F_29 ( & V_17 -> V_88 , 0 ) ;
if ( V_17 -> V_86 == V_85 )
V_79 |= F_30 ( & V_17 -> V_89 ,
V_52 -> V_90 ) ;
V_79 |= F_30 ( & V_17 -> V_75 , 1 ) ;
V_79 |= F_29 ( & V_17 -> V_91 , V_17 -> V_75 ) ;
if ( V_17 -> V_40 == V_41 )
V_79 |= F_30 ( & V_17 -> V_92 , 1 ) ;
else
V_79 |= F_29 ( & V_17 -> V_92 , 0 ) ;
if ( V_79 )
return 3 ;
if ( V_17 -> V_84 == V_85 ) {
V_80 = V_17 -> V_93 ;
F_17 ( V_7 , & V_80 , V_17 -> V_5 ) ;
V_79 |= F_29 ( & V_17 -> V_93 , V_80 ) ;
}
if ( V_79 )
return 4 ;
if ( V_17 -> V_73 && V_17 -> V_75 > 0 )
V_79 |= F_22 ( V_7 , V_12 , V_17 ) ;
if ( V_79 )
return 5 ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
unsigned long V_94 = V_7 -> V_28 + V_95 ;
unsigned long V_96 ;
unsigned int V_97 = V_9 -> V_67 ;
unsigned int V_98 ;
if ( V_17 -> V_5 & V_99 ) {
F_2 ( V_7 -> V_26 ,
L_9 ) ;
return - 1 ;
}
F_15 ( 0 , V_7 -> V_28 + V_49 ) ;
if ( F_20 ( V_7 , F_23 ( V_17 -> V_73 [ 0 ] ) ,
V_17 -> V_75 ) < 0 )
return - 1 ;
if ( F_24 ( V_17 -> V_73 [ 0 ] ) == V_100 )
V_9 -> V_67 |= V_101 ;
else
V_9 -> V_67 &= ~ V_101 ;
if ( F_24 ( V_17 -> V_73 [ 2 ] ) == V_100 )
V_9 -> V_67 |= V_102 ;
else
V_9 -> V_67 &= ~ V_102 ;
F_17 ( V_7 , & V_17 -> V_93 , V_17 -> V_5 ) ;
F_15 ( V_9 -> V_67 , V_7 -> V_28 + V_103 ) ;
V_9 -> V_39 = V_17 -> V_92 * V_17 -> V_75 ;
V_96 = F_5 () ;
F_6 ( V_9 -> V_37 ) ;
F_7 ( V_9 -> V_37 ) ;
F_10 ( V_9 -> V_37 , F_11 ( V_9 -> V_24 ) ) ;
#define F_32 333333333
V_9 -> V_38 =
sizeof( V_9 -> V_24 [ 0 ] ) * V_17 -> V_75 *
F_32 / V_17 -> V_93 ;
if ( V_9 -> V_38 > V_104 )
V_9 -> V_38 = V_104 ;
if ( V_9 -> V_38 < sizeof( V_9 -> V_24 [ 0 ] ) )
V_9 -> V_38 = sizeof( V_9 -> V_24 [ 0 ] ) ;
V_9 -> V_38 -=
V_9 -> V_38 % sizeof( V_9 -> V_24 [ 0 ] ) ;
F_12 ( V_9 -> V_37 , V_9 -> V_38 ) ;
F_13 ( V_9 -> V_37 ) ;
F_14 ( V_96 ) ;
F_15 ( 0x00 , V_7 -> V_28 + V_44 ) ;
V_9 -> V_45 |= V_46 | V_47 ;
F_15 ( V_9 -> V_45 , V_7 -> V_28 + V_48 ) ;
F_33 ( V_94 , 0 , 2 , V_105 | V_106 ) ;
F_34 ( V_94 , 0 , 2 , 72 ) ;
V_98 = 0 ;
if ( V_17 -> V_81 == V_82 &&
( V_97 & V_68 ) !=
( V_9 -> V_67 & V_68 ) ) {
V_98 |= V_107 ;
} else {
V_98 |= V_108 ;
}
if ( V_17 -> V_81 == V_83 ) {
V_98 |= V_109 ;
} else if ( V_17 -> V_81 == V_110 ) {
F_2 ( V_7 -> V_26 , L_10 ) ;
}
F_15 ( V_98 , V_7 -> V_28 + V_111 ) ;
if ( V_17 -> V_81 == V_82 )
F_15 ( 0 , V_7 -> V_28 + V_112 ) ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_113 * V_114 ,
unsigned long V_115 )
{
unsigned int V_4 ;
V_4 = F_3 ( V_7 -> V_28 + V_29 ) ;
if ( V_4 & V_116 )
return 0 ;
return - V_117 ;
}
static int F_36 ( struct V_6 * V_7 , struct V_11 * V_12 ,
struct V_113 * V_114 , unsigned int * V_118 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned int V_119 ;
int V_120 ;
F_15 ( 0 , V_7 -> V_28 + V_49 ) ;
if ( F_20 ( V_7 , F_23 ( V_114 -> V_121 ) , 1 ) < 0 )
return - 1 ;
V_9 -> V_67 &= ~ V_101 ;
V_9 -> V_67 &= ~ V_102 ;
F_15 ( V_9 -> V_67 , V_7 -> V_28 + V_103 ) ;
V_9 -> V_45 &= ~ V_46 & ~ V_47 ;
F_15 ( V_9 -> V_45 , V_7 -> V_28 + V_48 ) ;
F_15 ( 0 , V_7 -> V_28 + V_111 ) ;
F_15 ( 0 , V_7 -> V_28 + V_112 ) ;
for ( V_119 = 0 ; V_119 < 36 ; V_119 ++ ) {
V_120 = F_37 ( V_7 , V_12 , V_114 , F_35 , 0 ) ;
if ( V_120 )
return V_120 ;
F_3 ( V_7 -> V_28 + V_122 ) ;
}
for ( V_119 = 0 ; V_119 < V_114 -> V_119 ; V_119 ++ ) {
V_120 = F_37 ( V_7 , V_12 , V_114 , F_35 , 0 ) ;
if ( V_120 )
return V_120 ;
V_118 [ V_119 ] = F_3 ( V_7 -> V_28 + V_122 ) ;
V_118 [ V_119 ] ^= 0x8000 ;
}
F_15 ( 0 , V_7 -> V_28 + V_49 ) ;
return V_119 ;
}
static int F_38 ( struct V_6 * V_7 )
{
int V_4 = F_3 ( V_7 -> V_28 + V_29 ) ;
return F_39 ( V_4 ) ;
}
static int F_40 ( struct V_6 * V_7 , struct V_123 * V_124 )
{
const struct V_51 * V_52 ;
struct V_8 * V_9 ;
struct V_11 * V_12 ;
unsigned int V_1 = V_124 -> V_125 [ 1 ] ;
unsigned int V_37 = V_124 -> V_125 [ 2 ] ;
static const int V_126 = 2000 ;
int V_3 ;
int V_120 ;
V_9 = F_41 ( V_7 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_127 ;
V_120 = F_42 ( V_7 , V_124 -> V_125 [ 0 ] , 0x1c ) ;
if ( V_120 )
return V_120 ;
V_3 = F_38 ( V_7 ) ;
if ( V_3 >= F_43 ( V_128 ) )
return - V_129 ;
V_7 -> V_53 = V_128 + V_3 ;
V_52 = V_7 -> V_53 ;
V_7 -> V_130 = V_52 -> V_131 ;
if ( ( V_1 >= 3 && V_1 <= 7 ) || ( V_1 >= 9 && V_1 <= 12 ) ||
V_1 == 14 || V_1 == 15 ) {
V_120 = F_44 ( V_1 , F_1 , 0 ,
V_7 -> V_130 , V_7 ) ;
if ( V_120 == 0 ) {
V_9 -> V_45 |= F_45 ( V_1 ) ;
V_7 -> V_1 = V_1 ;
}
}
if ( V_7 -> V_1 && V_37 <= 7 && V_37 != 4 ) {
V_120 = F_46 ( V_37 , V_7 -> V_130 ) ;
if ( V_120 == 0 ) {
V_9 -> V_37 = V_37 ;
V_9 -> V_24 = F_47 ( V_104 ,
V_132 | V_133 ) ;
if ( ! V_9 -> V_24 )
return - V_127 ;
F_6 ( V_37 ) ;
F_48 ( V_37 , V_134 ) ;
V_9 -> V_45 |= F_49 ( V_37 ) ;
}
}
V_120 = F_50 ( V_7 , 1 ) ;
if ( V_120 )
return V_120 ;
V_12 = & V_7 -> V_135 [ 0 ] ;
V_12 -> type = V_136 ;
V_12 -> V_137 = V_138 | V_139 | V_140 ;
V_12 -> V_141 = 4 ;
V_12 -> V_142 = 0xffff ;
V_12 -> V_143 = & V_144 ;
V_12 -> V_145 = F_36 ;
if ( V_7 -> V_1 && V_9 -> V_37 ) {
V_7 -> V_13 = V_12 ;
V_12 -> V_137 |= V_146 ;
V_12 -> V_147 = V_12 -> V_141 ;
V_12 -> V_148 = F_31 ;
V_12 -> V_149 = F_26 ;
V_12 -> V_150 = F_16 ;
}
F_15 ( V_151 , V_7 -> V_28 + V_152 ) ;
F_15 ( V_9 -> V_45 , V_7 -> V_28 + V_48 ) ;
F_51 ( V_153 | V_154 , V_7 -> V_28 + V_103 ) ;
F_51 ( V_153 , V_7 -> V_28 + V_103 ) ;
V_9 -> V_67 = 0 ;
F_15 ( V_9 -> V_67 , V_7 -> V_28 + V_103 ) ;
for ( V_3 = 0 ; V_3 < V_126 ; V_3 ++ ) {
if ( ( V_155 & F_3 ( V_7 -> V_28 + V_29 ) ) == 0 )
break;
F_52 ( 1000 ) ;
}
if ( V_3 == V_126 ) {
F_2 ( V_7 -> V_26 ,
L_11 ) ;
return - V_156 ;
}
V_9 -> V_67 |= V_157 | V_158 ;
F_15 ( V_9 -> V_67 , V_7 -> V_28 + V_103 ) ;
return 0 ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_7 -> V_28 )
F_15 ( V_154 | V_153 , V_7 -> V_28 + V_103 ) ;
if ( V_9 ) {
if ( V_9 -> V_37 )
F_54 ( V_9 -> V_37 ) ;
F_55 ( V_9 -> V_24 ) ;
}
F_56 ( V_7 ) ;
}
