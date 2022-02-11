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
if ( ! V_7 -> V_23 ) {
F_2 ( V_7 -> V_24 , L_1 ) ;
return V_25 ;
}
V_15 = V_12 -> V_15 ;
V_17 = & V_15 -> V_17 ;
V_4 = F_3 ( V_7 -> V_26 + V_27 ) ;
if ( ( V_4 & V_28 ) == 0 ) {
F_2 ( V_7 -> V_24 , L_2 ) ;
return V_29 ;
}
if ( V_4 & V_30 ) {
F_2 ( V_7 -> V_24 , L_3 ) ;
V_15 -> V_31 |= V_32 | V_33 ;
F_4 ( V_7 , V_12 ) ;
}
if ( ( V_4 & V_34 ) == 0 ) {
F_2 ( V_7 -> V_24 ,
L_4 ) ;
V_15 -> V_31 |= V_32 | V_33 ;
F_4 ( V_7 , V_12 ) ;
return V_25 ;
}
V_5 = F_5 () ;
F_6 ( V_9 -> V_35 ) ;
F_7 ( V_9 -> V_35 ) ;
V_18 = F_8 ( V_12 , V_9 -> V_36 ) ;
V_20 = F_8 ( V_12 , F_9 ( V_9 -> V_35 ) ) ;
V_19 = V_18 - V_20 ;
if ( V_9 -> V_37 < V_19 && V_17 -> V_38 == V_39 )
V_19 = V_9 -> V_37 ;
V_21 = 0 ;
if ( V_17 -> V_38 == V_40 ) {
V_21 = F_8 ( V_12 ,
V_9 -> V_36 ) ;
} else if ( V_9 -> V_37 > V_18 ) {
V_21 = V_9 -> V_37 - V_18 ;
if ( V_21 > V_18 )
V_21 = V_18 ;
}
if ( V_20 )
V_21 = 0 ;
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
V_22 = V_9 -> V_41 [ V_3 ] ;
V_22 ^= 0x8000 ;
F_10 ( V_12 , & V_22 , 1 ) ;
if ( V_17 -> V_38 == V_39 ) {
if ( -- V_9 -> V_37 == 0 ) {
V_15 -> V_31 |= V_33 ;
break;
}
}
}
if ( V_21 ) {
F_11 ( V_9 -> V_35 , F_12 ( V_9 -> V_41 ) ) ;
F_13 ( V_9 -> V_35 ,
F_14 ( V_12 , V_21 ) ) ;
F_15 ( V_9 -> V_35 ) ;
}
F_16 ( V_5 ) ;
F_4 ( V_7 , V_12 ) ;
F_17 ( 0x00 , V_7 -> V_26 + V_42 ) ;
return V_25 ;
}
static int F_18 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
V_9 -> V_43 &= ~ V_44 & ~ V_45 ;
F_17 ( V_9 -> V_43 , V_7 -> V_26 + V_46 ) ;
F_6 ( V_9 -> V_35 ) ;
F_17 ( 0 , V_7 -> V_26 + V_47 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , unsigned int * V_48 ,
unsigned int V_5 )
{
const struct V_49 * V_50 = V_7 -> V_51 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_52 , V_53 , V_54 ;
int V_55 , V_56 , V_57 , V_58 ;
int V_3 , V_59 ;
V_55 = 3 ;
V_56 = 0 ;
V_52 = V_50 -> clock [ V_56 ] * ( 1 << V_55 ) ;
V_57 = 0 ;
V_58 = V_50 -> V_60 - 1 ;
V_53 = V_50 -> clock [ V_58 ] * ( 1 << V_57 ) ;
if ( * V_48 < V_53 )
* V_48 = V_53 ;
if ( * V_48 > V_52 )
* V_48 = V_52 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_59 = 0 ; V_59 < V_50 -> V_60 ; V_59 ++ ) {
V_54 = V_50 -> clock [ V_59 ] * ( 1 << V_3 ) ;
if ( V_54 < V_52 && V_54 >= * V_48 ) {
V_55 = V_3 ;
V_56 = V_59 ;
V_52 = V_54 ;
}
if ( V_54 > V_53 && V_54 <= * V_48 ) {
V_57 = V_3 ;
V_58 = V_59 ;
V_53 = V_54 ;
}
}
}
switch ( V_5 & V_61 ) {
case V_62 :
default:
if ( V_52 - * V_48 < * V_48 - V_53 )
* V_48 = V_52 ;
else
* V_48 = V_53 ;
break;
case V_63 :
* V_48 = V_52 ;
break;
case V_64 :
* V_48 = V_53 ;
break;
}
V_9 -> V_65 &= ~ V_66 ;
if ( * V_48 == V_52 ) {
V_9 -> V_65 |=
F_20 ( V_56 ) |
F_21 ( V_55 ) ;
} else {
V_9 -> V_65 |=
F_20 ( V_58 ) |
F_21 ( V_57 ) ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_7 ,
unsigned int V_67 ,
unsigned int V_68 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_67 + V_68 > 4 )
return - 1 ;
V_9 -> V_65 &= ~ V_69 ;
switch ( V_68 ) {
case 1 :
V_9 -> V_65 |= F_23 ( 0x4 | V_67 ) ;
break;
case 2 :
if ( V_67 == 0 )
V_9 -> V_65 |= F_23 ( 0x2 ) ;
else if ( V_67 == 2 )
V_9 -> V_65 |= F_23 ( 0x3 ) ;
else
return - 1 ;
break;
case 4 :
V_9 -> V_65 |= F_23 ( 0x1 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_16 * V_17 )
{
unsigned int V_70 = F_25 ( V_17 -> V_71 [ 0 ] ) ;
unsigned int V_72 = F_26 ( V_17 -> V_71 [ 0 ] ) ;
int V_3 ;
if ( V_17 -> V_73 == 2 && ( V_70 == 1 || V_70 == 3 ) ) {
F_27 ( V_7 -> V_24 ,
L_5 ) ;
return - V_74 ;
}
if ( V_17 -> V_73 == 3 ) {
F_27 ( V_7 -> V_24 ,
L_6 ) ;
return - V_74 ;
}
for ( V_3 = 1 ; V_3 < V_17 -> V_73 ; V_3 ++ ) {
unsigned int V_75 = F_25 ( V_17 -> V_71 [ V_3 ] ) ;
unsigned int V_76 = F_26 ( V_17 -> V_71 [ V_3 ] ) ;
if ( V_75 != ( V_70 + V_3 ) ) {
F_27 ( V_7 -> V_24 ,
L_7 ) ;
return - V_74 ;
}
if ( V_75 == 2 )
V_72 = V_76 ;
if ( V_76 != V_72 ) {
F_27 ( V_7 -> V_24 ,
L_8 ) ;
return - V_74 ;
}
}
return 0 ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_11 * V_12 , struct V_16 * V_17 )
{
const struct V_49 * V_50 = V_7 -> V_51 ;
int V_77 = 0 ;
unsigned int V_78 ;
V_77 |= F_29 ( & V_17 -> V_79 , V_80 | V_81 ) ;
V_77 |= F_29 ( & V_17 -> V_82 , V_83 ) ;
V_77 |= F_29 ( & V_17 -> V_84 , V_80 ) ;
V_77 |= F_29 ( & V_17 -> V_85 , V_39 ) ;
V_77 |= F_29 ( & V_17 -> V_38 , V_39 | V_40 ) ;
if ( V_77 )
return 1 ;
V_77 |= F_30 ( V_17 -> V_79 ) ;
V_77 |= F_30 ( V_17 -> V_38 ) ;
if ( V_77 )
return 2 ;
V_77 |= F_31 ( & V_17 -> V_86 , 0 ) ;
if ( V_17 -> V_84 == V_83 )
V_77 |= F_32 ( & V_17 -> V_87 ,
V_50 -> V_88 ) ;
V_77 |= F_32 ( & V_17 -> V_73 , 1 ) ;
V_77 |= F_31 ( & V_17 -> V_89 , V_17 -> V_73 ) ;
if ( V_17 -> V_38 == V_39 )
V_77 |= F_32 ( & V_17 -> V_90 , 1 ) ;
else
V_77 |= F_31 ( & V_17 -> V_90 , 0 ) ;
if ( V_77 )
return 3 ;
if ( V_17 -> V_82 == V_83 ) {
V_78 = V_17 -> V_91 ;
F_19 ( V_7 , & V_78 , V_17 -> V_5 ) ;
V_77 |= F_31 ( & V_17 -> V_91 , V_78 ) ;
}
if ( V_77 )
return 4 ;
if ( V_17 -> V_71 && V_17 -> V_73 > 0 )
V_77 |= F_24 ( V_7 , V_12 , V_17 ) ;
if ( V_77 )
return 5 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
unsigned long V_92 = V_7 -> V_26 + V_93 ;
unsigned long V_94 ;
unsigned int V_95 = V_9 -> V_65 ;
unsigned int V_96 ;
if ( V_17 -> V_5 & V_97 ) {
F_2 ( V_7 -> V_24 ,
L_9 ) ;
return - 1 ;
}
F_17 ( 0 , V_7 -> V_26 + V_47 ) ;
if ( F_22 ( V_7 , F_25 ( V_17 -> V_71 [ 0 ] ) ,
V_17 -> V_73 ) < 0 )
return - 1 ;
if ( F_26 ( V_17 -> V_71 [ 0 ] ) == V_98 )
V_9 -> V_65 |= V_99 ;
else
V_9 -> V_65 &= ~ V_99 ;
if ( F_26 ( V_17 -> V_71 [ 2 ] ) == V_98 )
V_9 -> V_65 |= V_100 ;
else
V_9 -> V_65 &= ~ V_100 ;
F_19 ( V_7 , & V_17 -> V_91 , V_17 -> V_5 ) ;
F_17 ( V_9 -> V_65 , V_7 -> V_26 + V_101 ) ;
V_9 -> V_37 = V_17 -> V_90 * V_17 -> V_73 ;
V_94 = F_5 () ;
F_6 ( V_9 -> V_35 ) ;
F_7 ( V_9 -> V_35 ) ;
F_11 ( V_9 -> V_35 , F_12 ( V_9 -> V_41 ) ) ;
#define F_34 333333333
V_9 -> V_36 =
sizeof( V_9 -> V_41 [ 0 ] ) * V_17 -> V_73 *
F_34 / V_17 -> V_91 ;
if ( V_9 -> V_36 > V_102 )
V_9 -> V_36 = V_102 ;
if ( V_9 -> V_36 < sizeof( V_9 -> V_41 [ 0 ] ) )
V_9 -> V_36 = sizeof( V_9 -> V_41 [ 0 ] ) ;
V_9 -> V_36 -=
V_9 -> V_36 % sizeof( V_9 -> V_41 [ 0 ] ) ;
F_13 ( V_9 -> V_35 , V_9 -> V_36 ) ;
F_15 ( V_9 -> V_35 ) ;
F_16 ( V_94 ) ;
F_17 ( 0x00 , V_7 -> V_26 + V_42 ) ;
V_9 -> V_43 |= V_44 | V_45 ;
F_17 ( V_9 -> V_43 , V_7 -> V_26 + V_46 ) ;
F_35 ( V_92 , 0 , 2 , V_103 | V_104 ) ;
F_36 ( V_92 , 0 , 2 , 72 ) ;
V_96 = 0 ;
if ( V_17 -> V_79 == V_80 &&
( V_95 & V_66 ) !=
( V_9 -> V_65 & V_66 ) ) {
V_96 |= V_105 ;
} else {
V_96 |= V_106 ;
}
if ( V_17 -> V_79 == V_81 ) {
V_96 |= V_107 ;
} else if ( V_17 -> V_79 == V_108 ) {
F_2 ( V_7 -> V_24 , L_10 ) ;
}
F_17 ( V_96 , V_7 -> V_26 + V_109 ) ;
if ( V_17 -> V_79 == V_80 )
F_17 ( 0 , V_7 -> V_26 + V_110 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_111 * V_112 ,
unsigned long V_113 )
{
unsigned int V_4 ;
V_4 = F_3 ( V_7 -> V_26 + V_27 ) ;
if ( V_4 & V_114 )
return 0 ;
return - V_115 ;
}
static int F_38 ( struct V_6 * V_7 , struct V_11 * V_12 ,
struct V_111 * V_112 , unsigned int * V_116 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned int V_117 ;
int V_118 ;
F_17 ( 0 , V_7 -> V_26 + V_47 ) ;
if ( F_22 ( V_7 , F_25 ( V_112 -> V_119 ) , 1 ) < 0 )
return - 1 ;
V_9 -> V_65 &= ~ V_99 ;
V_9 -> V_65 &= ~ V_100 ;
F_17 ( V_9 -> V_65 , V_7 -> V_26 + V_101 ) ;
V_9 -> V_43 &= ~ V_44 & ~ V_45 ;
F_17 ( V_9 -> V_43 , V_7 -> V_26 + V_46 ) ;
F_17 ( 0 , V_7 -> V_26 + V_109 ) ;
F_17 ( 0 , V_7 -> V_26 + V_110 ) ;
for ( V_117 = 0 ; V_117 < 36 ; V_117 ++ ) {
V_118 = F_39 ( V_7 , V_12 , V_112 , F_37 , 0 ) ;
if ( V_118 )
return V_118 ;
F_3 ( V_7 -> V_26 + V_120 ) ;
}
for ( V_117 = 0 ; V_117 < V_112 -> V_117 ; V_117 ++ ) {
V_118 = F_39 ( V_7 , V_12 , V_112 , F_37 , 0 ) ;
if ( V_118 )
return V_118 ;
V_116 [ V_117 ] = F_3 ( V_7 -> V_26 + V_120 ) ;
V_116 [ V_117 ] ^= 0x8000 ;
}
F_17 ( 0 , V_7 -> V_26 + V_47 ) ;
return V_117 ;
}
static int F_40 ( struct V_6 * V_7 )
{
int V_4 = F_3 ( V_7 -> V_26 + V_27 ) ;
return F_41 ( V_4 ) ;
}
static int F_42 ( struct V_6 * V_7 , struct V_121 * V_122 )
{
const struct V_49 * V_50 ;
struct V_8 * V_9 ;
struct V_11 * V_12 ;
unsigned int V_1 = V_122 -> V_123 [ 1 ] ;
unsigned int V_35 = V_122 -> V_123 [ 2 ] ;
static const int V_124 = 2000 ;
int V_3 ;
int V_118 ;
V_9 = F_43 ( V_7 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_125 ;
V_118 = F_44 ( V_7 , V_122 -> V_123 [ 0 ] , 0x1c ) ;
if ( V_118 )
return V_118 ;
V_3 = F_40 ( V_7 ) ;
if ( V_3 >= F_45 ( V_126 ) )
return - V_127 ;
V_7 -> V_51 = V_126 + V_3 ;
V_50 = V_7 -> V_51 ;
V_7 -> V_128 = V_50 -> V_129 ;
if ( ( V_1 >= 3 && V_1 <= 7 ) || ( V_1 >= 9 && V_1 <= 12 ) ||
V_1 == 14 || V_1 == 15 ) {
V_118 = F_46 ( V_1 , F_1 , 0 ,
V_7 -> V_128 , V_7 ) ;
if ( V_118 == 0 ) {
V_9 -> V_43 |= F_47 ( V_1 ) ;
V_7 -> V_1 = V_1 ;
}
}
if ( V_7 -> V_1 && V_35 <= 7 && V_35 != 4 ) {
V_118 = F_48 ( V_35 , V_7 -> V_128 ) ;
if ( V_118 == 0 ) {
V_9 -> V_35 = V_35 ;
V_9 -> V_41 = F_49 ( V_102 ,
V_130 | V_131 ) ;
if ( ! V_9 -> V_41 )
return - V_125 ;
F_6 ( V_35 ) ;
F_50 ( V_35 , V_132 ) ;
V_9 -> V_43 |= F_51 ( V_35 ) ;
}
}
V_118 = F_52 ( V_7 , 1 ) ;
if ( V_118 )
return V_118 ;
V_12 = & V_7 -> V_133 [ 0 ] ;
V_12 -> type = V_134 ;
V_12 -> V_135 = V_136 | V_137 | V_138 ;
V_12 -> V_139 = 4 ;
V_12 -> V_140 = 0xffff ;
V_12 -> V_141 = & V_142 ;
V_12 -> V_143 = F_38 ;
if ( V_7 -> V_1 && V_9 -> V_35 ) {
V_7 -> V_13 = V_12 ;
V_12 -> V_135 |= V_144 ;
V_12 -> V_145 = V_12 -> V_139 ;
V_12 -> V_146 = F_33 ;
V_12 -> V_147 = F_28 ;
V_12 -> V_148 = F_18 ;
}
F_17 ( V_149 , V_7 -> V_26 + V_150 ) ;
F_17 ( V_9 -> V_43 , V_7 -> V_26 + V_46 ) ;
F_53 ( V_151 | V_152 , V_7 -> V_26 + V_101 ) ;
F_53 ( V_151 , V_7 -> V_26 + V_101 ) ;
V_9 -> V_65 = 0 ;
F_17 ( V_9 -> V_65 , V_7 -> V_26 + V_101 ) ;
for ( V_3 = 0 ; V_3 < V_124 ; V_3 ++ ) {
if ( ( V_153 & F_3 ( V_7 -> V_26 + V_27 ) ) == 0 )
break;
F_54 ( 1000 ) ;
}
if ( V_3 == V_124 ) {
F_2 ( V_7 -> V_24 ,
L_11 ) ;
return - V_154 ;
}
V_9 -> V_65 |= V_155 | V_156 ;
F_17 ( V_9 -> V_65 , V_7 -> V_26 + V_101 ) ;
return 0 ;
}
static void F_55 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_7 -> V_26 )
F_17 ( V_152 | V_151 , V_7 -> V_26 + V_101 ) ;
if ( V_9 ) {
if ( V_9 -> V_35 )
F_56 ( V_9 -> V_35 ) ;
F_57 ( V_9 -> V_41 ) ;
}
F_58 ( V_7 ) ;
}
