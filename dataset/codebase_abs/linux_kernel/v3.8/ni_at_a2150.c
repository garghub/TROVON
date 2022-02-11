static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_1 , V_4 -> V_6 ) ;
F_2 ( L_2 , V_4 -> V_7 ) ;
F_2 ( L_3 , F_3 ( V_2 -> V_8 + V_9 ) ) ;
}
static T_1 F_4 ( int V_10 , void * V_11 )
{
int V_12 ;
int V_13 ;
unsigned long V_14 ;
struct V_1 * V_2 = V_11 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
unsigned int V_22 , V_23 , V_24 , V_25 ;
short V_26 ;
static const int V_27 = sizeof( V_4 -> V_28 [ 0 ] ) ;
if ( V_2 -> V_29 == 0 ) {
F_5 ( V_2 , L_4 ) ;
return V_30 ;
}
V_19 = V_16 -> V_19 ;
V_19 -> V_31 = 0 ;
V_21 = & V_19 -> V_21 ;
V_13 = F_3 ( V_2 -> V_8 + V_9 ) ;
if ( ( V_13 & V_32 ) == 0 ) {
F_5 ( V_2 , L_5 ) ;
return V_33 ;
}
if ( V_13 & V_34 ) {
F_5 ( V_2 , L_6 ) ;
F_6 ( V_2 , V_16 ) ;
V_19 -> V_31 |= V_35 | V_36 ;
}
if ( ( V_13 & V_37 ) == 0 ) {
F_5 ( V_2 , L_7 ) ;
F_6 ( V_2 , V_16 ) ;
V_19 -> V_31 |= V_35 | V_36 ;
F_7 ( V_2 , V_16 ) ;
return V_30 ;
}
V_14 = F_8 () ;
F_9 ( V_4 -> V_38 ) ;
F_10 ( V_4 -> V_38 ) ;
V_22 = V_4 -> V_39 / V_27 ;
V_24 = F_11 ( V_4 -> V_38 ) / V_27 ;
V_23 = V_22 - V_24 ;
if ( V_4 -> V_40 < V_23 && V_21 -> V_41 == V_42 )
V_23 = V_4 -> V_40 ;
V_25 = 0 ;
if ( V_21 -> V_41 == V_43 ) {
V_25 = V_4 -> V_39 / V_27 ;
} else if ( V_4 -> V_40 > V_22 ) {
V_25 = V_4 -> V_40 - V_22 ;
if ( V_25 > V_22 )
V_25 = V_22 ;
}
if ( V_24 )
V_25 = 0 ;
for ( V_12 = 0 ; V_12 < V_23 ; V_12 ++ ) {
V_26 = V_4 -> V_28 [ V_12 ] ;
V_26 ^= 0x8000 ;
F_12 ( V_16 , V_26 ) ;
if ( V_21 -> V_41 == V_42 ) {
if ( -- V_4 -> V_40 == 0 ) {
F_6 ( V_2 , V_16 ) ;
V_19 -> V_31 |= V_36 ;
break;
}
}
}
if ( V_25 ) {
F_13 ( V_4 -> V_38 , F_14 ( V_4 -> V_28 ) ) ;
F_15 ( V_4 -> V_38 , V_25 * V_27 ) ;
F_16 ( V_4 -> V_38 ) ;
}
F_17 ( V_14 ) ;
V_19 -> V_31 |= V_44 ;
F_7 ( V_2 , V_16 ) ;
F_18 ( 0x00 , V_2 -> V_8 + V_45 ) ;
return V_30 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_7 &= ~ V_46 & ~ V_47 ;
F_18 ( V_4 -> V_7 , V_2 -> V_8 + V_48 ) ;
F_9 ( V_4 -> V_38 ) ;
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_20 * V_21 )
{
int V_50 = 0 ;
int V_51 ;
int V_52 ;
int V_12 ;
V_50 |= F_20 ( & V_21 -> V_53 , V_54 | V_55 ) ;
V_50 |= F_20 ( & V_21 -> V_56 , V_57 ) ;
V_50 |= F_20 ( & V_21 -> V_58 , V_54 ) ;
V_50 |= F_20 ( & V_21 -> V_59 , V_42 ) ;
V_50 |= F_20 ( & V_21 -> V_41 , V_42 | V_43 ) ;
if ( V_50 )
return 1 ;
V_50 |= F_21 ( V_21 -> V_53 ) ;
V_50 |= F_21 ( V_21 -> V_41 ) ;
if ( V_50 )
return 2 ;
V_50 |= F_22 ( & V_21 -> V_60 , 0 ) ;
if ( V_21 -> V_58 == V_57 )
V_50 |= F_23 ( & V_21 -> V_61 ,
V_62 -> V_63 ) ;
V_50 |= F_23 ( & V_21 -> V_64 , 1 ) ;
V_50 |= F_22 ( & V_21 -> V_65 , V_21 -> V_64 ) ;
if ( V_21 -> V_41 == V_42 )
V_50 |= F_23 ( & V_21 -> V_66 , 1 ) ;
else
V_50 |= F_22 ( & V_21 -> V_66 , 0 ) ;
if ( V_50 )
return 3 ;
if ( V_21 -> V_56 == V_57 ) {
V_51 = V_21 -> V_67 ;
F_24 ( V_2 , & V_21 -> V_67 , V_21 -> V_14 ) ;
if ( V_51 != V_21 -> V_67 )
V_50 ++ ;
}
if ( V_50 )
return 4 ;
if ( V_21 -> V_68 ) {
V_52 = F_25 ( V_21 -> V_68 [ 0 ] ) ;
for ( V_12 = 1 ; V_12 < V_21 -> V_64 ; V_12 ++ ) {
if ( F_25 ( V_21 -> V_68 [ V_12 ] ) != ( V_52 + V_12 ) ) {
F_5 ( V_2 ,
L_8 ) ;
V_50 ++ ;
}
}
if ( V_21 -> V_64 == 2 && F_25 ( V_21 -> V_68 [ 0 ] ) == 1 ) {
F_5 ( V_2 ,
L_9 ) ;
V_50 ++ ;
}
if ( V_21 -> V_64 == 3 ) {
F_5 ( V_2 ,
L_10 ) ;
V_50 ++ ;
}
if ( F_26 ( V_21 -> V_68 [ 0 ] ) != F_26 ( V_21 -> V_68 [ 1 ] ) ||
F_26 ( V_21 -> V_68 [ 2 ] ) != F_26 ( V_21 -> V_68 [ 3 ] ) ) {
F_5 ( V_2 ,
L_11 ) ;
V_50 ++ ;
}
}
if ( V_50 )
return 5 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
unsigned long V_69 ;
unsigned int V_70 = V_4 -> V_6 ;
unsigned int V_71 ;
if ( ! V_2 -> V_10 || ! V_4 -> V_38 ) {
F_5 ( V_2 ,
L_12 ) ;
return - 1 ;
}
if ( V_21 -> V_14 & V_72 ) {
F_5 ( V_2 ,
L_13 ) ;
return - 1 ;
}
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
if ( F_28 ( V_2 , F_25 ( V_21 -> V_68 [ 0 ] ) ,
V_21 -> V_64 ) < 0 )
return - 1 ;
if ( F_26 ( V_21 -> V_68 [ 0 ] ) == V_73 )
V_4 -> V_6 |= V_74 ;
else
V_4 -> V_6 &= ~ V_74 ;
if ( F_26 ( V_21 -> V_68 [ 2 ] ) == V_73 )
V_4 -> V_6 |= V_75 ;
else
V_4 -> V_6 &= ~ V_75 ;
F_24 ( V_2 , & V_21 -> V_67 , V_21 -> V_14 ) ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_76 ) ;
V_4 -> V_40 = V_21 -> V_66 * V_21 -> V_64 ;
V_69 = F_8 () ;
F_9 ( V_4 -> V_38 ) ;
F_10 ( V_4 -> V_38 ) ;
F_13 ( V_4 -> V_38 , F_14 ( V_4 -> V_28 ) ) ;
#define F_29 333333333
V_4 -> V_39 =
sizeof( V_4 -> V_28 [ 0 ] ) * V_21 -> V_64 *
F_29 / V_21 -> V_67 ;
if ( V_4 -> V_39 > V_77 )
V_4 -> V_39 = V_77 ;
if ( V_4 -> V_39 < sizeof( V_4 -> V_28 [ 0 ] ) )
V_4 -> V_39 = sizeof( V_4 -> V_28 [ 0 ] ) ;
V_4 -> V_39 -=
V_4 -> V_39 % sizeof( V_4 -> V_28 [ 0 ] ) ;
F_15 ( V_4 -> V_38 , V_4 -> V_39 ) ;
F_16 ( V_4 -> V_38 ) ;
F_17 ( V_69 ) ;
F_18 ( 0x00 , V_2 -> V_8 + V_45 ) ;
V_4 -> V_7 |= V_46 | V_47 ;
F_18 ( V_4 -> V_7 , V_2 -> V_8 + V_48 ) ;
F_30 ( V_2 -> V_8 + V_78 , 0 , 2 , 72 , 0 ) ;
V_71 = 0 ;
if ( V_21 -> V_53 == V_54 &&
( V_70 & V_79 ) !=
( V_4 -> V_6 & V_79 ) ) {
V_71 |= V_80 ;
} else {
V_71 |= V_81 ;
}
if ( V_21 -> V_53 == V_55 ) {
V_71 |= V_82 ;
} else if ( V_21 -> V_53 == V_83 ) {
F_5 ( V_2 , L_14 ) ;
}
F_18 ( V_71 , V_2 -> V_8 + V_84 ) ;
if ( V_21 -> V_53 == V_54 )
F_18 ( 0 , V_2 -> V_8 + V_85 ) ;
#ifdef F_31
F_1 ( V_2 ) ;
#endif
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_86 * V_87 , unsigned int * V_88 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_12 , V_89 ;
static const int V_90 = 100000 ;
static const int V_91 = 36 ;
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
if ( F_28 ( V_2 , F_25 ( V_87 -> V_92 ) , 1 ) < 0 )
return - 1 ;
V_4 -> V_6 &= ~ V_74 ;
V_4 -> V_6 &= ~ V_75 ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_76 ) ;
V_4 -> V_7 &= ~ V_46 & ~ V_47 ;
F_18 ( V_4 -> V_7 , V_2 -> V_8 + V_48 ) ;
F_18 ( 0 , V_2 -> V_8 + V_84 ) ;
F_18 ( 0 , V_2 -> V_8 + V_85 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
for ( V_12 = 0 ; V_12 < V_90 ; V_12 ++ ) {
if ( F_3 ( V_2 -> V_8 + V_9 ) & V_93 )
break;
F_33 ( 1 ) ;
}
if ( V_12 == V_90 ) {
F_5 ( V_2 , L_15 ) ;
return - V_94 ;
}
F_3 ( V_2 -> V_8 + V_95 ) ;
}
for ( V_89 = 0 ; V_89 < V_87 -> V_89 ; V_89 ++ ) {
for ( V_12 = 0 ; V_12 < V_90 ; V_12 ++ ) {
if ( F_3 ( V_2 -> V_8 + V_9 ) & V_93 )
break;
F_33 ( 1 ) ;
}
if ( V_12 == V_90 ) {
F_5 ( V_2 , L_15 ) ;
return - V_94 ;
}
#ifdef F_31
F_1 ( V_2 ) ;
#endif
V_88 [ V_89 ] = F_3 ( V_2 -> V_8 + V_95 ) ;
#ifdef F_31
F_2 ( L_16 , V_88 [ V_89 ] ) ;
#endif
V_88 [ V_89 ] ^= 0x8000 ;
}
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
return V_89 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int * V_96 ,
int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_97 , V_98 , V_99 ;
int V_100 , V_101 , V_102 , V_103 ;
int V_12 , V_104 ;
V_100 = 3 ;
V_101 = 0 ;
V_97 = V_62 -> clock [ V_101 ] * ( 1 << V_100 ) ;
V_102 = 0 ;
V_103 = V_62 -> V_105 - 1 ;
V_98 = V_62 -> clock [ V_103 ] * ( 1 << V_102 ) ;
if ( * V_96 < V_98 )
* V_96 = V_98 ;
if ( * V_96 > V_97 )
* V_96 = V_97 ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
for ( V_104 = 0 ; V_104 < V_62 -> V_105 ; V_104 ++ ) {
V_99 = V_62 -> clock [ V_104 ] * ( 1 << V_12 ) ;
if ( V_99 < V_97 && V_99 >= * V_96 ) {
V_100 = V_12 ;
V_101 = V_104 ;
V_97 = V_99 ;
}
if ( V_99 > V_98 && V_99 <= * V_96 ) {
V_102 = V_12 ;
V_103 = V_104 ;
V_98 = V_99 ;
}
}
}
V_14 &= V_106 ;
switch ( V_14 ) {
case V_107 :
default:
if ( V_97 - * V_96 < * V_96 - V_98 )
* V_96 = V_97 ;
else
* V_96 = V_98 ;
break;
case V_108 :
* V_96 = V_97 ;
break;
case V_109 :
* V_96 = V_98 ;
break;
}
V_4 -> V_6 &= ~ V_79 ;
if ( * V_96 == V_97 ) {
V_4 -> V_6 |=
F_34 ( V_101 ) |
F_35 ( V_100 ) ;
} else {
V_4 -> V_6 |=
F_34 ( V_103 ) |
F_35 ( V_102 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned int V_110 ,
unsigned int V_111 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_110 + V_111 > 4 )
return - 1 ;
V_4 -> V_6 &= ~ V_112 ;
switch ( V_111 ) {
case 1 :
V_4 -> V_6 |= F_36 ( 0x4 | V_110 ) ;
break;
case 2 :
if ( V_110 == 0 ) {
V_4 -> V_6 |= F_36 ( 0x2 ) ;
} else if ( V_110 == 2 ) {
V_4 -> V_6 |= F_36 ( 0x3 ) ;
} else {
return - 1 ;
}
break;
case 4 :
V_4 -> V_6 |= F_36 ( 0x1 ) ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_13 = F_3 ( V_2 -> V_8 + V_9 ) ;
return F_38 ( V_13 ) ;
}
static int F_39 ( struct V_1 * V_2 , struct V_113 * V_114 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
unsigned long V_8 = V_114 -> V_115 [ 0 ] ;
unsigned int V_10 = V_114 -> V_115 [ 1 ] ;
unsigned int V_38 = V_114 -> V_115 [ 2 ] ;
static const int V_90 = 2000 ;
int V_12 ;
int V_116 ;
F_2 ( L_17 , V_2 -> V_117 , V_2 -> V_118 -> V_119 ,
V_8 ) ;
if ( V_10 ) {
F_2 ( L_18 , V_10 ) ;
} else {
F_2 ( L_19 ) ;
}
if ( V_38 ) {
F_2 ( L_20 , V_38 ) ;
} else {
F_2 ( L_21 ) ;
}
F_2 ( L_22 ) ;
V_4 = F_40 ( sizeof( * V_4 ) , V_120 ) ;
if ( ! V_4 )
return - V_121 ;
V_2 -> V_5 = V_4 ;
if ( V_8 == 0 ) {
F_2 ( L_23 ) ;
return - V_122 ;
}
if ( ! F_41 ( V_8 , V_123 , V_2 -> V_118 -> V_119 ) ) {
F_2 ( L_24 ) ;
return - V_124 ;
}
V_2 -> V_8 = V_8 ;
if ( V_10 ) {
if ( V_10 < 3 || V_10 == 8 || V_10 == 13 || V_10 > 15 ) {
F_2 ( L_25 , V_10 ) ;
return - V_122 ;
}
if ( F_42 ( V_10 , F_4 , 0 ,
V_2 -> V_118 -> V_119 , V_2 ) ) {
F_2 ( L_26 , V_10 ) ;
return - V_122 ;
}
V_4 -> V_7 |= F_43 ( V_10 ) ;
V_2 -> V_10 = V_10 ;
}
if ( V_38 ) {
if ( V_38 == 4 || V_38 > 7 ) {
F_2 ( L_27 , V_38 ) ;
return - V_122 ;
}
if ( F_44 ( V_38 , V_2 -> V_118 -> V_119 ) ) {
F_2 ( L_28 , V_38 ) ;
return - V_122 ;
}
V_4 -> V_38 = V_38 ;
V_4 -> V_28 =
F_45 ( V_77 , V_120 | V_125 ) ;
if ( V_4 -> V_28 == NULL )
return - V_121 ;
F_9 ( V_38 ) ;
F_46 ( V_38 , V_126 ) ;
V_4 -> V_7 |= F_47 ( V_38 ) ;
}
V_2 -> V_127 = V_128 + F_37 ( V_2 ) ;
V_2 -> V_129 = V_62 -> V_130 ;
V_116 = F_48 ( V_2 , 1 ) ;
if ( V_116 )
return V_116 ;
V_16 = & V_2 -> V_131 [ 0 ] ;
V_2 -> V_17 = V_16 ;
V_16 -> type = V_132 ;
V_16 -> V_133 = V_134 | V_135 | V_136 | V_137 ;
V_16 -> V_138 = 4 ;
V_16 -> V_139 = 4 ;
V_16 -> V_140 = 0xffff ;
V_16 -> V_141 = & V_142 ;
V_16 -> V_143 = F_27 ;
V_16 -> V_144 = F_19 ;
V_16 -> V_145 = F_32 ;
V_16 -> V_146 = F_6 ;
F_18 ( V_147 , V_2 -> V_8 + V_148 ) ;
F_18 ( V_4 -> V_7 , V_2 -> V_8 + V_48 ) ;
F_49 ( V_149 | V_150 , V_2 -> V_8 + V_76 ) ;
F_49 ( V_149 , V_2 -> V_8 + V_76 ) ;
V_4 -> V_6 = 0 ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_76 ) ;
for ( V_12 = 0 ; V_12 < V_90 ; V_12 ++ ) {
if ( ( V_151 & F_3 ( V_2 -> V_8 + V_9 ) ) == 0 )
break;
F_33 ( 1000 ) ;
}
if ( V_12 == V_90 ) {
F_2
( L_29 ) ;
return - V_94 ;
}
V_4 -> V_6 |= V_152 | V_153 ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_76 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_8 ) {
F_18 ( V_150 | V_149 , V_2 -> V_8 + V_76 ) ;
F_51 ( V_2 -> V_8 , V_123 ) ;
}
if ( V_2 -> V_10 )
F_52 ( V_2 -> V_10 , V_2 ) ;
if ( V_4 ) {
if ( V_4 -> V_38 )
F_53 ( V_4 -> V_38 ) ;
F_54 ( V_4 -> V_28 ) ;
}
}
