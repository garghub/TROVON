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
F_2 ( V_7 , L_1 ) ;
return V_26 ;
}
V_15 = V_12 -> V_15 ;
V_17 = & V_15 -> V_17 ;
V_4 = F_3 ( V_7 -> V_27 + V_28 ) ;
if ( ( V_4 & V_29 ) == 0 ) {
F_2 ( V_7 , L_2 ) ;
return V_30 ;
}
if ( V_4 & V_31 ) {
F_2 ( V_7 , L_3 ) ;
V_15 -> V_32 |= V_33 | V_34 ;
F_4 ( V_7 , V_12 ) ;
}
if ( ( V_4 & V_35 ) == 0 ) {
F_2 ( V_7 , L_4 ) ;
V_15 -> V_32 |= V_33 | V_34 ;
F_4 ( V_7 , V_12 ) ;
return V_26 ;
}
V_5 = F_5 () ;
F_6 ( V_9 -> V_36 ) ;
F_7 ( V_9 -> V_36 ) ;
V_18 = V_9 -> V_37 / V_23 ;
V_20 = F_8 ( V_9 -> V_36 ) / V_23 ;
V_19 = V_18 - V_20 ;
if ( V_9 -> V_38 < V_19 && V_17 -> V_39 == V_40 )
V_19 = V_9 -> V_38 ;
V_21 = 0 ;
if ( V_17 -> V_39 == V_41 ) {
V_21 = V_9 -> V_37 / V_23 ;
} else if ( V_9 -> V_38 > V_18 ) {
V_21 = V_9 -> V_38 - V_18 ;
if ( V_21 > V_18 )
V_21 = V_18 ;
}
if ( V_20 )
V_21 = 0 ;
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
V_22 = V_9 -> V_24 [ V_3 ] ;
V_22 ^= 0x8000 ;
F_9 ( V_12 , V_22 ) ;
if ( V_17 -> V_39 == V_40 ) {
if ( -- V_9 -> V_38 == 0 ) {
V_15 -> V_32 |= V_34 ;
break;
}
}
}
if ( V_21 ) {
F_10 ( V_9 -> V_36 , F_11 ( V_9 -> V_24 ) ) ;
F_12 ( V_9 -> V_36 , V_21 * V_23 ) ;
F_13 ( V_9 -> V_36 ) ;
}
F_14 ( V_5 ) ;
V_15 -> V_32 |= V_42 ;
F_4 ( V_7 , V_12 ) ;
F_15 ( 0x00 , V_7 -> V_27 + V_43 ) ;
return V_26 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
V_9 -> V_44 &= ~ V_45 & ~ V_46 ;
F_15 ( V_9 -> V_44 , V_7 -> V_27 + V_47 ) ;
F_6 ( V_9 -> V_36 ) ;
F_15 ( 0 , V_7 -> V_27 + V_48 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_16 * V_17 )
{
unsigned int V_49 = F_18 ( V_17 -> V_50 [ 0 ] ) ;
unsigned int V_51 = F_19 ( V_17 -> V_50 [ 0 ] ) ;
int V_3 ;
if ( V_17 -> V_52 == 2 && ( V_49 == 1 || V_49 == 3 ) ) {
F_20 ( V_7 -> V_53 ,
L_5 ) ;
return - V_54 ;
}
if ( V_17 -> V_52 == 3 ) {
F_20 ( V_7 -> V_53 ,
L_6 ) ;
return - V_54 ;
}
for ( V_3 = 1 ; V_3 < V_17 -> V_52 ; V_3 ++ ) {
unsigned int V_55 = F_18 ( V_17 -> V_50 [ V_3 ] ) ;
unsigned int V_56 = F_19 ( V_17 -> V_50 [ V_3 ] ) ;
if ( V_55 != ( V_49 + V_3 ) ) {
F_20 ( V_7 -> V_53 ,
L_7 ) ;
return - V_54 ;
}
if ( V_55 == 2 )
V_51 = V_56 ;
if ( V_56 != V_51 ) {
F_20 ( V_7 -> V_53 ,
L_8 ) ;
return - V_54 ;
}
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_11 * V_12 , struct V_16 * V_17 )
{
const struct V_57 * V_58 = F_22 ( V_7 ) ;
int V_59 = 0 ;
unsigned int V_60 ;
V_59 |= F_23 ( & V_17 -> V_61 , V_62 | V_63 ) ;
V_59 |= F_23 ( & V_17 -> V_64 , V_65 ) ;
V_59 |= F_23 ( & V_17 -> V_66 , V_62 ) ;
V_59 |= F_23 ( & V_17 -> V_67 , V_40 ) ;
V_59 |= F_23 ( & V_17 -> V_39 , V_40 | V_41 ) ;
if ( V_59 )
return 1 ;
V_59 |= F_24 ( V_17 -> V_61 ) ;
V_59 |= F_24 ( V_17 -> V_39 ) ;
if ( V_59 )
return 2 ;
V_59 |= F_25 ( & V_17 -> V_68 , 0 ) ;
if ( V_17 -> V_66 == V_65 )
V_59 |= F_26 ( & V_17 -> V_69 ,
V_58 -> V_70 ) ;
V_59 |= F_26 ( & V_17 -> V_52 , 1 ) ;
V_59 |= F_25 ( & V_17 -> V_71 , V_17 -> V_52 ) ;
if ( V_17 -> V_39 == V_40 )
V_59 |= F_26 ( & V_17 -> V_72 , 1 ) ;
else
V_59 |= F_25 ( & V_17 -> V_72 , 0 ) ;
if ( V_59 )
return 3 ;
if ( V_17 -> V_64 == V_65 ) {
V_60 = V_17 -> V_73 ;
F_27 ( V_7 , & V_60 , V_17 -> V_5 ) ;
V_59 |= F_25 ( & V_17 -> V_73 , V_60 ) ;
}
if ( V_59 )
return 4 ;
if ( V_17 -> V_50 && V_17 -> V_52 > 0 )
V_59 |= F_17 ( V_7 , V_12 , V_17 ) ;
if ( V_59 )
return 5 ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
unsigned long V_74 = V_7 -> V_27 + V_75 ;
unsigned long V_76 ;
unsigned int V_77 = V_9 -> V_78 ;
unsigned int V_79 ;
if ( V_17 -> V_5 & V_80 ) {
F_2 ( V_7 ,
L_9 ) ;
return - 1 ;
}
F_15 ( 0 , V_7 -> V_27 + V_48 ) ;
if ( F_29 ( V_7 , F_18 ( V_17 -> V_50 [ 0 ] ) ,
V_17 -> V_52 ) < 0 )
return - 1 ;
if ( F_19 ( V_17 -> V_50 [ 0 ] ) == V_81 )
V_9 -> V_78 |= V_82 ;
else
V_9 -> V_78 &= ~ V_82 ;
if ( F_19 ( V_17 -> V_50 [ 2 ] ) == V_81 )
V_9 -> V_78 |= V_83 ;
else
V_9 -> V_78 &= ~ V_83 ;
F_27 ( V_7 , & V_17 -> V_73 , V_17 -> V_5 ) ;
F_15 ( V_9 -> V_78 , V_7 -> V_27 + V_84 ) ;
V_9 -> V_38 = V_17 -> V_72 * V_17 -> V_52 ;
V_76 = F_5 () ;
F_6 ( V_9 -> V_36 ) ;
F_7 ( V_9 -> V_36 ) ;
F_10 ( V_9 -> V_36 , F_11 ( V_9 -> V_24 ) ) ;
#define F_30 333333333
V_9 -> V_37 =
sizeof( V_9 -> V_24 [ 0 ] ) * V_17 -> V_52 *
F_30 / V_17 -> V_73 ;
if ( V_9 -> V_37 > V_85 )
V_9 -> V_37 = V_85 ;
if ( V_9 -> V_37 < sizeof( V_9 -> V_24 [ 0 ] ) )
V_9 -> V_37 = sizeof( V_9 -> V_24 [ 0 ] ) ;
V_9 -> V_37 -=
V_9 -> V_37 % sizeof( V_9 -> V_24 [ 0 ] ) ;
F_12 ( V_9 -> V_36 , V_9 -> V_37 ) ;
F_13 ( V_9 -> V_36 ) ;
F_14 ( V_76 ) ;
F_15 ( 0x00 , V_7 -> V_27 + V_43 ) ;
V_9 -> V_44 |= V_45 | V_46 ;
F_15 ( V_9 -> V_44 , V_7 -> V_27 + V_47 ) ;
F_31 ( V_74 , 0 , 2 , V_86 | V_87 ) ;
F_32 ( V_74 , 0 , 2 , 72 ) ;
V_79 = 0 ;
if ( V_17 -> V_61 == V_62 &&
( V_77 & V_88 ) !=
( V_9 -> V_78 & V_88 ) ) {
V_79 |= V_89 ;
} else {
V_79 |= V_90 ;
}
if ( V_17 -> V_61 == V_63 ) {
V_79 |= V_91 ;
} else if ( V_17 -> V_61 == V_92 ) {
F_2 ( V_7 , L_10 ) ;
}
F_15 ( V_79 , V_7 -> V_27 + V_93 ) ;
if ( V_17 -> V_61 == V_62 )
F_15 ( 0 , V_7 -> V_27 + V_94 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_95 * V_96 ,
unsigned long V_97 )
{
unsigned int V_4 ;
V_4 = F_3 ( V_7 -> V_27 + V_28 ) ;
if ( V_4 & V_98 )
return 0 ;
return - V_99 ;
}
static int F_34 ( struct V_6 * V_7 , struct V_11 * V_12 ,
struct V_95 * V_96 , unsigned int * V_100 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned int V_101 ;
int V_102 ;
F_15 ( 0 , V_7 -> V_27 + V_48 ) ;
if ( F_29 ( V_7 , F_18 ( V_96 -> V_103 ) , 1 ) < 0 )
return - 1 ;
V_9 -> V_78 &= ~ V_82 ;
V_9 -> V_78 &= ~ V_83 ;
F_15 ( V_9 -> V_78 , V_7 -> V_27 + V_84 ) ;
V_9 -> V_44 &= ~ V_45 & ~ V_46 ;
F_15 ( V_9 -> V_44 , V_7 -> V_27 + V_47 ) ;
F_15 ( 0 , V_7 -> V_27 + V_93 ) ;
F_15 ( 0 , V_7 -> V_27 + V_94 ) ;
for ( V_101 = 0 ; V_101 < 36 ; V_101 ++ ) {
V_102 = F_35 ( V_7 , V_12 , V_96 , F_33 , 0 ) ;
if ( V_102 )
return V_102 ;
F_3 ( V_7 -> V_27 + V_104 ) ;
}
for ( V_101 = 0 ; V_101 < V_96 -> V_101 ; V_101 ++ ) {
V_102 = F_35 ( V_7 , V_12 , V_96 , F_33 , 0 ) ;
if ( V_102 )
return V_102 ;
V_100 [ V_101 ] = F_3 ( V_7 -> V_27 + V_104 ) ;
V_100 [ V_101 ] ^= 0x8000 ;
}
F_15 ( 0 , V_7 -> V_27 + V_48 ) ;
return V_101 ;
}
static int F_27 ( struct V_6 * V_7 , unsigned int * V_105 ,
int V_5 )
{
const struct V_57 * V_58 = F_22 ( V_7 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_106 , V_107 , V_108 ;
int V_109 , V_110 , V_111 , V_112 ;
int V_3 , V_113 ;
V_109 = 3 ;
V_110 = 0 ;
V_106 = V_58 -> clock [ V_110 ] * ( 1 << V_109 ) ;
V_111 = 0 ;
V_112 = V_58 -> V_114 - 1 ;
V_107 = V_58 -> clock [ V_112 ] * ( 1 << V_111 ) ;
if ( * V_105 < V_107 )
* V_105 = V_107 ;
if ( * V_105 > V_106 )
* V_105 = V_106 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_113 = 0 ; V_113 < V_58 -> V_114 ; V_113 ++ ) {
V_108 = V_58 -> clock [ V_113 ] * ( 1 << V_3 ) ;
if ( V_108 < V_106 && V_108 >= * V_105 ) {
V_109 = V_3 ;
V_110 = V_113 ;
V_106 = V_108 ;
}
if ( V_108 > V_107 && V_108 <= * V_105 ) {
V_111 = V_3 ;
V_112 = V_113 ;
V_107 = V_108 ;
}
}
}
V_5 &= V_115 ;
switch ( V_5 ) {
case V_116 :
default:
if ( V_106 - * V_105 < * V_105 - V_107 )
* V_105 = V_106 ;
else
* V_105 = V_107 ;
break;
case V_117 :
* V_105 = V_106 ;
break;
case V_118 :
* V_105 = V_107 ;
break;
}
V_9 -> V_78 &= ~ V_88 ;
if ( * V_105 == V_106 ) {
V_9 -> V_78 |=
F_36 ( V_110 ) |
F_37 ( V_109 ) ;
} else {
V_9 -> V_78 |=
F_36 ( V_112 ) |
F_37 ( V_111 ) ;
}
return 0 ;
}
static int F_29 ( struct V_6 * V_7 ,
unsigned int V_119 ,
unsigned int V_120 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_119 + V_120 > 4 )
return - 1 ;
V_9 -> V_78 &= ~ V_121 ;
switch ( V_120 ) {
case 1 :
V_9 -> V_78 |= F_38 ( 0x4 | V_119 ) ;
break;
case 2 :
if ( V_119 == 0 )
V_9 -> V_78 |= F_38 ( 0x2 ) ;
else if ( V_119 == 2 )
V_9 -> V_78 |= F_38 ( 0x3 ) ;
else
return - 1 ;
break;
case 4 :
V_9 -> V_78 |= F_38 ( 0x1 ) ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
int V_4 = F_3 ( V_7 -> V_27 + V_28 ) ;
return F_40 ( V_4 ) ;
}
static int F_41 ( struct V_6 * V_7 , struct V_122 * V_123 )
{
const struct V_57 * V_58 ;
struct V_8 * V_9 ;
struct V_11 * V_12 ;
unsigned int V_1 = V_123 -> V_124 [ 1 ] ;
unsigned int V_36 = V_123 -> V_124 [ 2 ] ;
static const int V_125 = 2000 ;
int V_3 ;
int V_102 ;
V_9 = F_42 ( V_7 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_126 ;
V_102 = F_43 ( V_7 , V_123 -> V_124 [ 0 ] , V_127 ) ;
if ( V_102 )
return V_102 ;
V_7 -> V_128 = V_129 + F_39 ( V_7 ) ;
V_58 = F_22 ( V_7 ) ;
V_7 -> V_130 = V_58 -> V_131 ;
if ( ( V_1 >= 3 && V_1 <= 7 ) || ( V_1 >= 9 && V_1 <= 12 ) ||
V_1 == 14 || V_1 == 15 ) {
V_102 = F_44 ( V_1 , F_1 , 0 ,
V_7 -> V_130 , V_7 ) ;
if ( V_102 == 0 ) {
V_9 -> V_44 |= F_45 ( V_1 ) ;
V_7 -> V_1 = V_1 ;
}
}
if ( V_7 -> V_1 && V_36 <= 7 && V_36 != 4 ) {
V_102 = F_46 ( V_36 , V_7 -> V_130 ) ;
if ( V_102 == 0 ) {
V_9 -> V_36 = V_36 ;
V_9 -> V_24 = F_47 ( V_85 ,
V_132 | V_133 ) ;
if ( ! V_9 -> V_24 )
return - V_126 ;
F_6 ( V_36 ) ;
F_48 ( V_36 , V_134 ) ;
V_9 -> V_44 |= F_49 ( V_36 ) ;
}
}
V_102 = F_50 ( V_7 , 1 ) ;
if ( V_102 )
return V_102 ;
V_12 = & V_7 -> V_135 [ 0 ] ;
V_12 -> type = V_136 ;
V_12 -> V_137 = V_138 | V_139 | V_140 ;
V_12 -> V_141 = 4 ;
V_12 -> V_142 = 0xffff ;
V_12 -> V_143 = & V_144 ;
V_12 -> V_145 = F_34 ;
if ( V_7 -> V_1 && V_9 -> V_36 ) {
V_7 -> V_13 = V_12 ;
V_12 -> V_137 |= V_146 ;
V_12 -> V_147 = V_12 -> V_141 ;
V_12 -> V_148 = F_28 ;
V_12 -> V_149 = F_21 ;
V_12 -> V_150 = F_16 ;
}
F_15 ( V_151 , V_7 -> V_27 + V_152 ) ;
F_15 ( V_9 -> V_44 , V_7 -> V_27 + V_47 ) ;
F_51 ( V_153 | V_154 , V_7 -> V_27 + V_84 ) ;
F_51 ( V_153 , V_7 -> V_27 + V_84 ) ;
V_9 -> V_78 = 0 ;
F_15 ( V_9 -> V_78 , V_7 -> V_27 + V_84 ) ;
for ( V_3 = 0 ; V_3 < V_125 ; V_3 ++ ) {
if ( ( V_155 & F_3 ( V_7 -> V_27 + V_28 ) ) == 0 )
break;
F_52 ( 1000 ) ;
}
if ( V_3 == V_125 ) {
F_53
( L_11 ) ;
return - V_156 ;
}
V_9 -> V_78 |= V_157 | V_158 ;
F_15 ( V_9 -> V_78 , V_7 -> V_27 + V_84 ) ;
return 0 ;
}
static void F_54 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_7 -> V_27 )
F_15 ( V_154 | V_153 , V_7 -> V_27 + V_84 ) ;
if ( V_9 ) {
if ( V_9 -> V_36 )
F_55 ( V_9 -> V_36 ) ;
F_56 ( V_9 -> V_24 ) ;
}
F_57 ( V_7 ) ;
}
