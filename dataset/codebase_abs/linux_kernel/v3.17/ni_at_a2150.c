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
const struct V_51 * V_52 = F_18 ( V_7 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_53 , V_54 , V_55 ;
int V_56 , V_57 , V_58 , V_59 ;
int V_3 , V_60 ;
V_56 = 3 ;
V_57 = 0 ;
V_53 = V_52 -> clock [ V_57 ] * ( 1 << V_56 ) ;
V_58 = 0 ;
V_59 = V_52 -> V_61 - 1 ;
V_54 = V_52 -> clock [ V_59 ] * ( 1 << V_58 ) ;
if ( * V_50 < V_54 )
* V_50 = V_54 ;
if ( * V_50 > V_53 )
* V_50 = V_53 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_60 = 0 ; V_60 < V_52 -> V_61 ; V_60 ++ ) {
V_55 = V_52 -> clock [ V_60 ] * ( 1 << V_3 ) ;
if ( V_55 < V_53 && V_55 >= * V_50 ) {
V_56 = V_3 ;
V_57 = V_60 ;
V_53 = V_55 ;
}
if ( V_55 > V_54 && V_55 <= * V_50 ) {
V_58 = V_3 ;
V_59 = V_60 ;
V_54 = V_55 ;
}
}
}
switch ( V_5 & V_62 ) {
case V_63 :
default:
if ( V_53 - * V_50 < * V_50 - V_54 )
* V_50 = V_53 ;
else
* V_50 = V_54 ;
break;
case V_64 :
* V_50 = V_53 ;
break;
case V_65 :
* V_50 = V_54 ;
break;
}
V_9 -> V_66 &= ~ V_67 ;
if ( * V_50 == V_53 ) {
V_9 -> V_66 |=
F_19 ( V_57 ) |
F_20 ( V_56 ) ;
} else {
V_9 -> V_66 |=
F_19 ( V_59 ) |
F_20 ( V_58 ) ;
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 ,
unsigned int V_68 ,
unsigned int V_69 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_68 + V_69 > 4 )
return - 1 ;
V_9 -> V_66 &= ~ V_70 ;
switch ( V_69 ) {
case 1 :
V_9 -> V_66 |= F_22 ( 0x4 | V_68 ) ;
break;
case 2 :
if ( V_68 == 0 )
V_9 -> V_66 |= F_22 ( 0x2 ) ;
else if ( V_68 == 2 )
V_9 -> V_66 |= F_22 ( 0x3 ) ;
else
return - 1 ;
break;
case 4 :
V_9 -> V_66 |= F_22 ( 0x1 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_16 * V_17 )
{
unsigned int V_71 = F_24 ( V_17 -> V_72 [ 0 ] ) ;
unsigned int V_73 = F_25 ( V_17 -> V_72 [ 0 ] ) ;
int V_3 ;
if ( V_17 -> V_74 == 2 && ( V_71 == 1 || V_71 == 3 ) ) {
F_26 ( V_7 -> V_26 ,
L_5 ) ;
return - V_75 ;
}
if ( V_17 -> V_74 == 3 ) {
F_26 ( V_7 -> V_26 ,
L_6 ) ;
return - V_75 ;
}
for ( V_3 = 1 ; V_3 < V_17 -> V_74 ; V_3 ++ ) {
unsigned int V_76 = F_24 ( V_17 -> V_72 [ V_3 ] ) ;
unsigned int V_77 = F_25 ( V_17 -> V_72 [ V_3 ] ) ;
if ( V_76 != ( V_71 + V_3 ) ) {
F_26 ( V_7 -> V_26 ,
L_7 ) ;
return - V_75 ;
}
if ( V_76 == 2 )
V_73 = V_77 ;
if ( V_77 != V_73 ) {
F_26 ( V_7 -> V_26 ,
L_8 ) ;
return - V_75 ;
}
}
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_11 * V_12 , struct V_16 * V_17 )
{
const struct V_51 * V_52 = F_18 ( V_7 ) ;
int V_78 = 0 ;
unsigned int V_79 ;
V_78 |= F_28 ( & V_17 -> V_80 , V_81 | V_82 ) ;
V_78 |= F_28 ( & V_17 -> V_83 , V_84 ) ;
V_78 |= F_28 ( & V_17 -> V_85 , V_81 ) ;
V_78 |= F_28 ( & V_17 -> V_86 , V_41 ) ;
V_78 |= F_28 ( & V_17 -> V_40 , V_41 | V_42 ) ;
if ( V_78 )
return 1 ;
V_78 |= F_29 ( V_17 -> V_80 ) ;
V_78 |= F_29 ( V_17 -> V_40 ) ;
if ( V_78 )
return 2 ;
V_78 |= F_30 ( & V_17 -> V_87 , 0 ) ;
if ( V_17 -> V_85 == V_84 )
V_78 |= F_31 ( & V_17 -> V_88 ,
V_52 -> V_89 ) ;
V_78 |= F_31 ( & V_17 -> V_74 , 1 ) ;
V_78 |= F_30 ( & V_17 -> V_90 , V_17 -> V_74 ) ;
if ( V_17 -> V_40 == V_41 )
V_78 |= F_31 ( & V_17 -> V_91 , 1 ) ;
else
V_78 |= F_30 ( & V_17 -> V_91 , 0 ) ;
if ( V_78 )
return 3 ;
if ( V_17 -> V_83 == V_84 ) {
V_79 = V_17 -> V_92 ;
F_17 ( V_7 , & V_79 , V_17 -> V_5 ) ;
V_78 |= F_30 ( & V_17 -> V_92 , V_79 ) ;
}
if ( V_78 )
return 4 ;
if ( V_17 -> V_72 && V_17 -> V_74 > 0 )
V_78 |= F_23 ( V_7 , V_12 , V_17 ) ;
if ( V_78 )
return 5 ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
unsigned long V_93 = V_7 -> V_28 + V_94 ;
unsigned long V_95 ;
unsigned int V_96 = V_9 -> V_66 ;
unsigned int V_97 ;
if ( V_17 -> V_5 & V_98 ) {
F_2 ( V_7 -> V_26 ,
L_9 ) ;
return - 1 ;
}
F_15 ( 0 , V_7 -> V_28 + V_49 ) ;
if ( F_21 ( V_7 , F_24 ( V_17 -> V_72 [ 0 ] ) ,
V_17 -> V_74 ) < 0 )
return - 1 ;
if ( F_25 ( V_17 -> V_72 [ 0 ] ) == V_99 )
V_9 -> V_66 |= V_100 ;
else
V_9 -> V_66 &= ~ V_100 ;
if ( F_25 ( V_17 -> V_72 [ 2 ] ) == V_99 )
V_9 -> V_66 |= V_101 ;
else
V_9 -> V_66 &= ~ V_101 ;
F_17 ( V_7 , & V_17 -> V_92 , V_17 -> V_5 ) ;
F_15 ( V_9 -> V_66 , V_7 -> V_28 + V_102 ) ;
V_9 -> V_39 = V_17 -> V_91 * V_17 -> V_74 ;
V_95 = F_5 () ;
F_6 ( V_9 -> V_37 ) ;
F_7 ( V_9 -> V_37 ) ;
F_10 ( V_9 -> V_37 , F_11 ( V_9 -> V_24 ) ) ;
#define F_33 333333333
V_9 -> V_38 =
sizeof( V_9 -> V_24 [ 0 ] ) * V_17 -> V_74 *
F_33 / V_17 -> V_92 ;
if ( V_9 -> V_38 > V_103 )
V_9 -> V_38 = V_103 ;
if ( V_9 -> V_38 < sizeof( V_9 -> V_24 [ 0 ] ) )
V_9 -> V_38 = sizeof( V_9 -> V_24 [ 0 ] ) ;
V_9 -> V_38 -=
V_9 -> V_38 % sizeof( V_9 -> V_24 [ 0 ] ) ;
F_12 ( V_9 -> V_37 , V_9 -> V_38 ) ;
F_13 ( V_9 -> V_37 ) ;
F_14 ( V_95 ) ;
F_15 ( 0x00 , V_7 -> V_28 + V_44 ) ;
V_9 -> V_45 |= V_46 | V_47 ;
F_15 ( V_9 -> V_45 , V_7 -> V_28 + V_48 ) ;
F_34 ( V_93 , 0 , 2 , V_104 | V_105 ) ;
F_35 ( V_93 , 0 , 2 , 72 ) ;
V_97 = 0 ;
if ( V_17 -> V_80 == V_81 &&
( V_96 & V_67 ) !=
( V_9 -> V_66 & V_67 ) ) {
V_97 |= V_106 ;
} else {
V_97 |= V_107 ;
}
if ( V_17 -> V_80 == V_82 ) {
V_97 |= V_108 ;
} else if ( V_17 -> V_80 == V_109 ) {
F_2 ( V_7 -> V_26 , L_10 ) ;
}
F_15 ( V_97 , V_7 -> V_28 + V_110 ) ;
if ( V_17 -> V_80 == V_81 )
F_15 ( 0 , V_7 -> V_28 + V_111 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_112 * V_113 ,
unsigned long V_114 )
{
unsigned int V_4 ;
V_4 = F_3 ( V_7 -> V_28 + V_29 ) ;
if ( V_4 & V_115 )
return 0 ;
return - V_116 ;
}
static int F_37 ( struct V_6 * V_7 , struct V_11 * V_12 ,
struct V_112 * V_113 , unsigned int * V_117 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned int V_118 ;
int V_119 ;
F_15 ( 0 , V_7 -> V_28 + V_49 ) ;
if ( F_21 ( V_7 , F_24 ( V_113 -> V_120 ) , 1 ) < 0 )
return - 1 ;
V_9 -> V_66 &= ~ V_100 ;
V_9 -> V_66 &= ~ V_101 ;
F_15 ( V_9 -> V_66 , V_7 -> V_28 + V_102 ) ;
V_9 -> V_45 &= ~ V_46 & ~ V_47 ;
F_15 ( V_9 -> V_45 , V_7 -> V_28 + V_48 ) ;
F_15 ( 0 , V_7 -> V_28 + V_110 ) ;
F_15 ( 0 , V_7 -> V_28 + V_111 ) ;
for ( V_118 = 0 ; V_118 < 36 ; V_118 ++ ) {
V_119 = F_38 ( V_7 , V_12 , V_113 , F_36 , 0 ) ;
if ( V_119 )
return V_119 ;
F_3 ( V_7 -> V_28 + V_121 ) ;
}
for ( V_118 = 0 ; V_118 < V_113 -> V_118 ; V_118 ++ ) {
V_119 = F_38 ( V_7 , V_12 , V_113 , F_36 , 0 ) ;
if ( V_119 )
return V_119 ;
V_117 [ V_118 ] = F_3 ( V_7 -> V_28 + V_121 ) ;
V_117 [ V_118 ] ^= 0x8000 ;
}
F_15 ( 0 , V_7 -> V_28 + V_49 ) ;
return V_118 ;
}
static int F_39 ( struct V_6 * V_7 )
{
int V_4 = F_3 ( V_7 -> V_28 + V_29 ) ;
return F_40 ( V_4 ) ;
}
static int F_41 ( struct V_6 * V_7 , struct V_122 * V_123 )
{
const struct V_51 * V_52 ;
struct V_8 * V_9 ;
struct V_11 * V_12 ;
unsigned int V_1 = V_123 -> V_124 [ 1 ] ;
unsigned int V_37 = V_123 -> V_124 [ 2 ] ;
static const int V_125 = 2000 ;
int V_3 ;
int V_119 ;
V_9 = F_42 ( V_7 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_126 ;
V_119 = F_43 ( V_7 , V_123 -> V_124 [ 0 ] , 0x1c ) ;
if ( V_119 )
return V_119 ;
V_7 -> V_127 = V_128 + F_39 ( V_7 ) ;
V_52 = F_18 ( V_7 ) ;
V_7 -> V_129 = V_52 -> V_130 ;
if ( ( V_1 >= 3 && V_1 <= 7 ) || ( V_1 >= 9 && V_1 <= 12 ) ||
V_1 == 14 || V_1 == 15 ) {
V_119 = F_44 ( V_1 , F_1 , 0 ,
V_7 -> V_129 , V_7 ) ;
if ( V_119 == 0 ) {
V_9 -> V_45 |= F_45 ( V_1 ) ;
V_7 -> V_1 = V_1 ;
}
}
if ( V_7 -> V_1 && V_37 <= 7 && V_37 != 4 ) {
V_119 = F_46 ( V_37 , V_7 -> V_129 ) ;
if ( V_119 == 0 ) {
V_9 -> V_37 = V_37 ;
V_9 -> V_24 = F_47 ( V_103 ,
V_131 | V_132 ) ;
if ( ! V_9 -> V_24 )
return - V_126 ;
F_6 ( V_37 ) ;
F_48 ( V_37 , V_133 ) ;
V_9 -> V_45 |= F_49 ( V_37 ) ;
}
}
V_119 = F_50 ( V_7 , 1 ) ;
if ( V_119 )
return V_119 ;
V_12 = & V_7 -> V_134 [ 0 ] ;
V_12 -> type = V_135 ;
V_12 -> V_136 = V_137 | V_138 | V_139 ;
V_12 -> V_140 = 4 ;
V_12 -> V_141 = 0xffff ;
V_12 -> V_142 = & V_143 ;
V_12 -> V_144 = F_37 ;
if ( V_7 -> V_1 && V_9 -> V_37 ) {
V_7 -> V_13 = V_12 ;
V_12 -> V_136 |= V_145 ;
V_12 -> V_146 = V_12 -> V_140 ;
V_12 -> V_147 = F_32 ;
V_12 -> V_148 = F_27 ;
V_12 -> V_149 = F_16 ;
}
F_15 ( V_150 , V_7 -> V_28 + V_151 ) ;
F_15 ( V_9 -> V_45 , V_7 -> V_28 + V_48 ) ;
F_51 ( V_152 | V_153 , V_7 -> V_28 + V_102 ) ;
F_51 ( V_152 , V_7 -> V_28 + V_102 ) ;
V_9 -> V_66 = 0 ;
F_15 ( V_9 -> V_66 , V_7 -> V_28 + V_102 ) ;
for ( V_3 = 0 ; V_3 < V_125 ; V_3 ++ ) {
if ( ( V_154 & F_3 ( V_7 -> V_28 + V_29 ) ) == 0 )
break;
F_52 ( 1000 ) ;
}
if ( V_3 == V_125 ) {
F_2 ( V_7 -> V_26 ,
L_11 ) ;
return - V_155 ;
}
V_9 -> V_66 |= V_156 | V_157 ;
F_15 ( V_9 -> V_66 , V_7 -> V_28 + V_102 ) ;
return 0 ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_7 -> V_28 )
F_15 ( V_153 | V_152 , V_7 -> V_28 + V_102 ) ;
if ( V_9 ) {
if ( V_9 -> V_37 )
F_54 ( V_9 -> V_37 ) ;
F_55 ( V_9 -> V_24 ) ;
}
F_56 ( V_7 ) ;
}
