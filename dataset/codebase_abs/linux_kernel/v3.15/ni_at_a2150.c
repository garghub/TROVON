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
struct V_11 * V_12 , struct V_16 * V_17 )
{
const struct V_49 * V_50 = F_18 ( V_7 ) ;
int V_51 = 0 ;
int V_52 ;
int V_53 ;
int V_3 ;
V_51 |= F_19 ( & V_17 -> V_54 , V_55 | V_56 ) ;
V_51 |= F_19 ( & V_17 -> V_57 , V_58 ) ;
V_51 |= F_19 ( & V_17 -> V_59 , V_55 ) ;
V_51 |= F_19 ( & V_17 -> V_60 , V_40 ) ;
V_51 |= F_19 ( & V_17 -> V_39 , V_40 | V_41 ) ;
if ( V_51 )
return 1 ;
V_51 |= F_20 ( V_17 -> V_54 ) ;
V_51 |= F_20 ( V_17 -> V_39 ) ;
if ( V_51 )
return 2 ;
V_51 |= F_21 ( & V_17 -> V_61 , 0 ) ;
if ( V_17 -> V_59 == V_58 )
V_51 |= F_22 ( & V_17 -> V_62 ,
V_50 -> V_63 ) ;
V_51 |= F_22 ( & V_17 -> V_64 , 1 ) ;
V_51 |= F_21 ( & V_17 -> V_65 , V_17 -> V_64 ) ;
if ( V_17 -> V_39 == V_40 )
V_51 |= F_22 ( & V_17 -> V_66 , 1 ) ;
else
V_51 |= F_21 ( & V_17 -> V_66 , 0 ) ;
if ( V_51 )
return 3 ;
if ( V_17 -> V_57 == V_58 ) {
V_52 = V_17 -> V_67 ;
F_23 ( V_7 , & V_17 -> V_67 , V_17 -> V_5 ) ;
if ( V_52 != V_17 -> V_67 )
V_51 ++ ;
}
if ( V_51 )
return 4 ;
if ( V_17 -> V_68 ) {
V_53 = F_24 ( V_17 -> V_68 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < V_17 -> V_64 ; V_3 ++ ) {
if ( F_24 ( V_17 -> V_68 [ V_3 ] ) != ( V_53 + V_3 ) ) {
F_2 ( V_7 ,
L_5 ) ;
V_51 ++ ;
}
}
if ( V_17 -> V_64 == 2 && F_24 ( V_17 -> V_68 [ 0 ] ) == 1 ) {
F_2 ( V_7 ,
L_6 ) ;
V_51 ++ ;
}
if ( V_17 -> V_64 == 3 ) {
F_2 ( V_7 ,
L_7 ) ;
V_51 ++ ;
}
if ( F_25 ( V_17 -> V_68 [ 0 ] ) != F_25 ( V_17 -> V_68 [ 1 ] ) ||
F_25 ( V_17 -> V_68 [ 2 ] ) != F_25 ( V_17 -> V_68 [ 3 ] ) ) {
F_2 ( V_7 ,
L_8 ) ;
V_51 ++ ;
}
}
if ( V_51 )
return 5 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_14 * V_15 = V_12 -> V_15 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
unsigned long V_69 ;
unsigned int V_70 = V_9 -> V_71 ;
unsigned int V_72 ;
if ( V_17 -> V_5 & V_73 ) {
F_2 ( V_7 ,
L_9 ) ;
return - 1 ;
}
F_15 ( 0 , V_7 -> V_27 + V_48 ) ;
if ( F_27 ( V_7 , F_24 ( V_17 -> V_68 [ 0 ] ) ,
V_17 -> V_64 ) < 0 )
return - 1 ;
if ( F_25 ( V_17 -> V_68 [ 0 ] ) == V_74 )
V_9 -> V_71 |= V_75 ;
else
V_9 -> V_71 &= ~ V_75 ;
if ( F_25 ( V_17 -> V_68 [ 2 ] ) == V_74 )
V_9 -> V_71 |= V_76 ;
else
V_9 -> V_71 &= ~ V_76 ;
F_23 ( V_7 , & V_17 -> V_67 , V_17 -> V_5 ) ;
F_15 ( V_9 -> V_71 , V_7 -> V_27 + V_77 ) ;
V_9 -> V_38 = V_17 -> V_66 * V_17 -> V_64 ;
V_69 = F_5 () ;
F_6 ( V_9 -> V_36 ) ;
F_7 ( V_9 -> V_36 ) ;
F_10 ( V_9 -> V_36 , F_11 ( V_9 -> V_24 ) ) ;
#define F_28 333333333
V_9 -> V_37 =
sizeof( V_9 -> V_24 [ 0 ] ) * V_17 -> V_64 *
F_28 / V_17 -> V_67 ;
if ( V_9 -> V_37 > V_78 )
V_9 -> V_37 = V_78 ;
if ( V_9 -> V_37 < sizeof( V_9 -> V_24 [ 0 ] ) )
V_9 -> V_37 = sizeof( V_9 -> V_24 [ 0 ] ) ;
V_9 -> V_37 -=
V_9 -> V_37 % sizeof( V_9 -> V_24 [ 0 ] ) ;
F_12 ( V_9 -> V_36 , V_9 -> V_37 ) ;
F_13 ( V_9 -> V_36 ) ;
F_14 ( V_69 ) ;
F_15 ( 0x00 , V_7 -> V_27 + V_43 ) ;
V_9 -> V_44 |= V_45 | V_46 ;
F_15 ( V_9 -> V_44 , V_7 -> V_27 + V_47 ) ;
F_29 ( V_7 -> V_27 + V_79 , 0 , 2 , 72 , 0 ) ;
V_72 = 0 ;
if ( V_17 -> V_54 == V_55 &&
( V_70 & V_80 ) !=
( V_9 -> V_71 & V_80 ) ) {
V_72 |= V_81 ;
} else {
V_72 |= V_82 ;
}
if ( V_17 -> V_54 == V_56 ) {
V_72 |= V_83 ;
} else if ( V_17 -> V_54 == V_84 ) {
F_2 ( V_7 , L_10 ) ;
}
F_15 ( V_72 , V_7 -> V_27 + V_85 ) ;
if ( V_17 -> V_54 == V_55 )
F_15 ( 0 , V_7 -> V_27 + V_86 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_11 * V_12 ,
struct V_87 * V_88 ,
unsigned long V_89 )
{
unsigned int V_4 ;
V_4 = F_3 ( V_7 -> V_27 + V_28 ) ;
if ( V_4 & V_90 )
return 0 ;
return - V_91 ;
}
static int F_31 ( struct V_6 * V_7 , struct V_11 * V_12 ,
struct V_87 * V_88 , unsigned int * V_92 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned int V_93 ;
int V_94 ;
F_15 ( 0 , V_7 -> V_27 + V_48 ) ;
if ( F_27 ( V_7 , F_24 ( V_88 -> V_95 ) , 1 ) < 0 )
return - 1 ;
V_9 -> V_71 &= ~ V_75 ;
V_9 -> V_71 &= ~ V_76 ;
F_15 ( V_9 -> V_71 , V_7 -> V_27 + V_77 ) ;
V_9 -> V_44 &= ~ V_45 & ~ V_46 ;
F_15 ( V_9 -> V_44 , V_7 -> V_27 + V_47 ) ;
F_15 ( 0 , V_7 -> V_27 + V_85 ) ;
F_15 ( 0 , V_7 -> V_27 + V_86 ) ;
for ( V_93 = 0 ; V_93 < 36 ; V_93 ++ ) {
V_94 = F_32 ( V_7 , V_12 , V_88 , F_30 , 0 ) ;
if ( V_94 )
return V_94 ;
F_3 ( V_7 -> V_27 + V_96 ) ;
}
for ( V_93 = 0 ; V_93 < V_88 -> V_93 ; V_93 ++ ) {
V_94 = F_32 ( V_7 , V_12 , V_88 , F_30 , 0 ) ;
if ( V_94 )
return V_94 ;
V_92 [ V_93 ] = F_3 ( V_7 -> V_27 + V_96 ) ;
V_92 [ V_93 ] ^= 0x8000 ;
}
F_15 ( 0 , V_7 -> V_27 + V_48 ) ;
return V_93 ;
}
static int F_23 ( struct V_6 * V_7 , unsigned int * V_97 ,
int V_5 )
{
const struct V_49 * V_50 = F_18 ( V_7 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_98 , V_99 , V_100 ;
int V_101 , V_102 , V_103 , V_104 ;
int V_3 , V_105 ;
V_101 = 3 ;
V_102 = 0 ;
V_98 = V_50 -> clock [ V_102 ] * ( 1 << V_101 ) ;
V_103 = 0 ;
V_104 = V_50 -> V_106 - 1 ;
V_99 = V_50 -> clock [ V_104 ] * ( 1 << V_103 ) ;
if ( * V_97 < V_99 )
* V_97 = V_99 ;
if ( * V_97 > V_98 )
* V_97 = V_98 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
for ( V_105 = 0 ; V_105 < V_50 -> V_106 ; V_105 ++ ) {
V_100 = V_50 -> clock [ V_105 ] * ( 1 << V_3 ) ;
if ( V_100 < V_98 && V_100 >= * V_97 ) {
V_101 = V_3 ;
V_102 = V_105 ;
V_98 = V_100 ;
}
if ( V_100 > V_99 && V_100 <= * V_97 ) {
V_103 = V_3 ;
V_104 = V_105 ;
V_99 = V_100 ;
}
}
}
V_5 &= V_107 ;
switch ( V_5 ) {
case V_108 :
default:
if ( V_98 - * V_97 < * V_97 - V_99 )
* V_97 = V_98 ;
else
* V_97 = V_99 ;
break;
case V_109 :
* V_97 = V_98 ;
break;
case V_110 :
* V_97 = V_99 ;
break;
}
V_9 -> V_71 &= ~ V_80 ;
if ( * V_97 == V_98 ) {
V_9 -> V_71 |=
F_33 ( V_102 ) |
F_34 ( V_101 ) ;
} else {
V_9 -> V_71 |=
F_33 ( V_104 ) |
F_34 ( V_103 ) ;
}
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
unsigned int V_111 ,
unsigned int V_112 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_111 + V_112 > 4 )
return - 1 ;
V_9 -> V_71 &= ~ V_113 ;
switch ( V_112 ) {
case 1 :
V_9 -> V_71 |= F_35 ( 0x4 | V_111 ) ;
break;
case 2 :
if ( V_111 == 0 )
V_9 -> V_71 |= F_35 ( 0x2 ) ;
else if ( V_111 == 2 )
V_9 -> V_71 |= F_35 ( 0x3 ) ;
else
return - 1 ;
break;
case 4 :
V_9 -> V_71 |= F_35 ( 0x1 ) ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_6 * V_7 )
{
int V_4 = F_3 ( V_7 -> V_27 + V_28 ) ;
return F_37 ( V_4 ) ;
}
static int F_38 ( struct V_6 * V_7 , struct V_114 * V_115 )
{
const struct V_49 * V_50 = F_18 ( V_7 ) ;
struct V_8 * V_9 ;
struct V_11 * V_12 ;
unsigned int V_1 = V_115 -> V_116 [ 1 ] ;
unsigned int V_36 = V_115 -> V_116 [ 2 ] ;
static const int V_117 = 2000 ;
int V_3 ;
int V_94 ;
V_9 = F_39 ( V_7 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_118 ;
V_94 = F_40 ( V_7 , V_115 -> V_116 [ 0 ] , V_119 ) ;
if ( V_94 )
return V_94 ;
V_7 -> V_120 = V_121 + F_36 ( V_7 ) ;
V_50 = F_18 ( V_7 ) ;
V_7 -> V_122 = V_50 -> V_123 ;
if ( ( V_1 >= 3 && V_1 <= 7 ) || ( V_1 >= 9 && V_1 <= 12 ) ||
V_1 == 14 || V_1 == 15 ) {
V_94 = F_41 ( V_1 , F_1 , 0 ,
V_7 -> V_122 , V_7 ) ;
if ( V_94 == 0 ) {
V_9 -> V_44 |= F_42 ( V_1 ) ;
V_7 -> V_1 = V_1 ;
}
}
if ( V_7 -> V_1 && V_36 <= 7 && V_36 != 4 ) {
V_94 = F_43 ( V_36 , V_7 -> V_122 ) ;
if ( V_94 == 0 ) {
V_9 -> V_36 = V_36 ;
V_9 -> V_24 = F_44 ( V_78 ,
V_124 | V_125 ) ;
if ( ! V_9 -> V_24 )
return - V_118 ;
F_6 ( V_36 ) ;
F_45 ( V_36 , V_126 ) ;
V_9 -> V_44 |= F_46 ( V_36 ) ;
}
}
V_94 = F_47 ( V_7 , 1 ) ;
if ( V_94 )
return V_94 ;
V_12 = & V_7 -> V_127 [ 0 ] ;
V_12 -> type = V_128 ;
V_12 -> V_129 = V_130 | V_131 | V_132 ;
V_12 -> V_133 = 4 ;
V_12 -> V_134 = 0xffff ;
V_12 -> V_135 = & V_136 ;
V_12 -> V_137 = F_31 ;
if ( V_7 -> V_1 && V_9 -> V_36 ) {
V_7 -> V_13 = V_12 ;
V_12 -> V_129 |= V_138 ;
V_12 -> V_139 = V_12 -> V_133 ;
V_12 -> V_140 = F_26 ;
V_12 -> V_141 = F_17 ;
V_12 -> V_142 = F_16 ;
}
F_15 ( V_143 , V_7 -> V_27 + V_144 ) ;
F_15 ( V_9 -> V_44 , V_7 -> V_27 + V_47 ) ;
F_48 ( V_145 | V_146 , V_7 -> V_27 + V_77 ) ;
F_48 ( V_145 , V_7 -> V_27 + V_77 ) ;
V_9 -> V_71 = 0 ;
F_15 ( V_9 -> V_71 , V_7 -> V_27 + V_77 ) ;
for ( V_3 = 0 ; V_3 < V_117 ; V_3 ++ ) {
if ( ( V_147 & F_3 ( V_7 -> V_27 + V_28 ) ) == 0 )
break;
F_49 ( 1000 ) ;
}
if ( V_3 == V_117 ) {
F_50
( L_11 ) ;
return - V_148 ;
}
V_9 -> V_71 |= V_149 | V_150 ;
F_15 ( V_9 -> V_71 , V_7 -> V_27 + V_77 ) ;
return 0 ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_7 -> V_27 )
F_15 ( V_146 | V_145 , V_7 -> V_27 + V_77 ) ;
if ( V_9 ) {
if ( V_9 -> V_36 )
F_52 ( V_9 -> V_36 ) ;
F_53 ( V_9 -> V_24 ) ;
}
F_54 ( V_7 ) ;
}
