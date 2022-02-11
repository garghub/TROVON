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
unsigned short V_26 ;
static const int V_27 = sizeof( V_4 -> V_28 [ 0 ] ) ;
if ( ! V_2 -> V_29 ) {
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
const struct V_50 * V_51 = F_20 ( V_2 ) ;
int V_52 = 0 ;
int V_53 ;
int V_54 ;
int V_12 ;
V_52 |= F_21 ( & V_21 -> V_55 , V_56 | V_57 ) ;
V_52 |= F_21 ( & V_21 -> V_58 , V_59 ) ;
V_52 |= F_21 ( & V_21 -> V_60 , V_56 ) ;
V_52 |= F_21 ( & V_21 -> V_61 , V_42 ) ;
V_52 |= F_21 ( & V_21 -> V_41 , V_42 | V_43 ) ;
if ( V_52 )
return 1 ;
V_52 |= F_22 ( V_21 -> V_55 ) ;
V_52 |= F_22 ( V_21 -> V_41 ) ;
if ( V_52 )
return 2 ;
V_52 |= F_23 ( & V_21 -> V_62 , 0 ) ;
if ( V_21 -> V_60 == V_59 )
V_52 |= F_24 ( & V_21 -> V_63 ,
V_51 -> V_64 ) ;
V_52 |= F_24 ( & V_21 -> V_65 , 1 ) ;
V_52 |= F_23 ( & V_21 -> V_66 , V_21 -> V_65 ) ;
if ( V_21 -> V_41 == V_42 )
V_52 |= F_24 ( & V_21 -> V_67 , 1 ) ;
else
V_52 |= F_23 ( & V_21 -> V_67 , 0 ) ;
if ( V_52 )
return 3 ;
if ( V_21 -> V_58 == V_59 ) {
V_53 = V_21 -> V_68 ;
F_25 ( V_2 , & V_21 -> V_68 , V_21 -> V_14 ) ;
if ( V_53 != V_21 -> V_68 )
V_52 ++ ;
}
if ( V_52 )
return 4 ;
if ( V_21 -> V_69 ) {
V_54 = F_26 ( V_21 -> V_69 [ 0 ] ) ;
for ( V_12 = 1 ; V_12 < V_21 -> V_65 ; V_12 ++ ) {
if ( F_26 ( V_21 -> V_69 [ V_12 ] ) != ( V_54 + V_12 ) ) {
F_5 ( V_2 ,
L_8 ) ;
V_52 ++ ;
}
}
if ( V_21 -> V_65 == 2 && F_26 ( V_21 -> V_69 [ 0 ] ) == 1 ) {
F_5 ( V_2 ,
L_9 ) ;
V_52 ++ ;
}
if ( V_21 -> V_65 == 3 ) {
F_5 ( V_2 ,
L_10 ) ;
V_52 ++ ;
}
if ( F_27 ( V_21 -> V_69 [ 0 ] ) != F_27 ( V_21 -> V_69 [ 1 ] ) ||
F_27 ( V_21 -> V_69 [ 2 ] ) != F_27 ( V_21 -> V_69 [ 3 ] ) ) {
F_5 ( V_2 ,
L_11 ) ;
V_52 ++ ;
}
}
if ( V_52 )
return 5 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
unsigned long V_70 ;
unsigned int V_71 = V_4 -> V_6 ;
unsigned int V_72 ;
if ( ! V_2 -> V_10 || ! V_4 -> V_38 ) {
F_5 ( V_2 ,
L_12 ) ;
return - 1 ;
}
if ( V_21 -> V_14 & V_73 ) {
F_5 ( V_2 ,
L_13 ) ;
return - 1 ;
}
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
if ( F_29 ( V_2 , F_26 ( V_21 -> V_69 [ 0 ] ) ,
V_21 -> V_65 ) < 0 )
return - 1 ;
if ( F_27 ( V_21 -> V_69 [ 0 ] ) == V_74 )
V_4 -> V_6 |= V_75 ;
else
V_4 -> V_6 &= ~ V_75 ;
if ( F_27 ( V_21 -> V_69 [ 2 ] ) == V_74 )
V_4 -> V_6 |= V_76 ;
else
V_4 -> V_6 &= ~ V_76 ;
F_25 ( V_2 , & V_21 -> V_68 , V_21 -> V_14 ) ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_77 ) ;
V_4 -> V_40 = V_21 -> V_67 * V_21 -> V_65 ;
V_70 = F_8 () ;
F_9 ( V_4 -> V_38 ) ;
F_10 ( V_4 -> V_38 ) ;
F_13 ( V_4 -> V_38 , F_14 ( V_4 -> V_28 ) ) ;
#define F_30 333333333
V_4 -> V_39 =
sizeof( V_4 -> V_28 [ 0 ] ) * V_21 -> V_65 *
F_30 / V_21 -> V_68 ;
if ( V_4 -> V_39 > V_78 )
V_4 -> V_39 = V_78 ;
if ( V_4 -> V_39 < sizeof( V_4 -> V_28 [ 0 ] ) )
V_4 -> V_39 = sizeof( V_4 -> V_28 [ 0 ] ) ;
V_4 -> V_39 -=
V_4 -> V_39 % sizeof( V_4 -> V_28 [ 0 ] ) ;
F_15 ( V_4 -> V_38 , V_4 -> V_39 ) ;
F_16 ( V_4 -> V_38 ) ;
F_17 ( V_70 ) ;
F_18 ( 0x00 , V_2 -> V_8 + V_45 ) ;
V_4 -> V_7 |= V_46 | V_47 ;
F_18 ( V_4 -> V_7 , V_2 -> V_8 + V_48 ) ;
F_31 ( V_2 -> V_8 + V_79 , 0 , 2 , 72 , 0 ) ;
V_72 = 0 ;
if ( V_21 -> V_55 == V_56 &&
( V_71 & V_80 ) !=
( V_4 -> V_6 & V_80 ) ) {
V_72 |= V_81 ;
} else {
V_72 |= V_82 ;
}
if ( V_21 -> V_55 == V_57 ) {
V_72 |= V_83 ;
} else if ( V_21 -> V_55 == V_84 ) {
F_5 ( V_2 , L_14 ) ;
}
F_18 ( V_72 , V_2 -> V_8 + V_85 ) ;
if ( V_21 -> V_55 == V_56 )
F_18 ( 0 , V_2 -> V_8 + V_86 ) ;
#ifdef F_32
F_1 ( V_2 ) ;
#endif
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_87 * V_88 , unsigned int * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_12 , V_90 ;
static const int V_91 = 100000 ;
static const int V_92 = 36 ;
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
if ( F_29 ( V_2 , F_26 ( V_88 -> V_93 ) , 1 ) < 0 )
return - 1 ;
V_4 -> V_6 &= ~ V_75 ;
V_4 -> V_6 &= ~ V_76 ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_77 ) ;
V_4 -> V_7 &= ~ V_46 & ~ V_47 ;
F_18 ( V_4 -> V_7 , V_2 -> V_8 + V_48 ) ;
F_18 ( 0 , V_2 -> V_8 + V_85 ) ;
F_18 ( 0 , V_2 -> V_8 + V_86 ) ;
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
for ( V_12 = 0 ; V_12 < V_91 ; V_12 ++ ) {
if ( F_3 ( V_2 -> V_8 + V_9 ) & V_94 )
break;
F_34 ( 1 ) ;
}
if ( V_12 == V_91 ) {
F_5 ( V_2 , L_15 ) ;
return - V_95 ;
}
F_3 ( V_2 -> V_8 + V_96 ) ;
}
for ( V_90 = 0 ; V_90 < V_88 -> V_90 ; V_90 ++ ) {
for ( V_12 = 0 ; V_12 < V_91 ; V_12 ++ ) {
if ( F_3 ( V_2 -> V_8 + V_9 ) & V_94 )
break;
F_34 ( 1 ) ;
}
if ( V_12 == V_91 ) {
F_5 ( V_2 , L_15 ) ;
return - V_95 ;
}
#ifdef F_32
F_1 ( V_2 ) ;
#endif
V_89 [ V_90 ] = F_3 ( V_2 -> V_8 + V_96 ) ;
#ifdef F_32
F_2 ( L_16 , V_89 [ V_90 ] ) ;
#endif
V_89 [ V_90 ] ^= 0x8000 ;
}
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
return V_90 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int * V_97 ,
int V_14 )
{
const struct V_50 * V_51 = F_20 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_98 , V_99 , V_100 ;
int V_101 , V_102 , V_103 , V_104 ;
int V_12 , V_105 ;
V_101 = 3 ;
V_102 = 0 ;
V_98 = V_51 -> clock [ V_102 ] * ( 1 << V_101 ) ;
V_103 = 0 ;
V_104 = V_51 -> V_106 - 1 ;
V_99 = V_51 -> clock [ V_104 ] * ( 1 << V_103 ) ;
if ( * V_97 < V_99 )
* V_97 = V_99 ;
if ( * V_97 > V_98 )
* V_97 = V_98 ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
for ( V_105 = 0 ; V_105 < V_51 -> V_106 ; V_105 ++ ) {
V_100 = V_51 -> clock [ V_105 ] * ( 1 << V_12 ) ;
if ( V_100 < V_98 && V_100 >= * V_97 ) {
V_101 = V_12 ;
V_102 = V_105 ;
V_98 = V_100 ;
}
if ( V_100 > V_99 && V_100 <= * V_97 ) {
V_103 = V_12 ;
V_104 = V_105 ;
V_99 = V_100 ;
}
}
}
V_14 &= V_107 ;
switch ( V_14 ) {
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
V_4 -> V_6 &= ~ V_80 ;
if ( * V_97 == V_98 ) {
V_4 -> V_6 |=
F_35 ( V_102 ) |
F_36 ( V_101 ) ;
} else {
V_4 -> V_6 |=
F_35 ( V_104 ) |
F_36 ( V_103 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_111 ,
unsigned int V_112 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_111 + V_112 > 4 )
return - 1 ;
V_4 -> V_6 &= ~ V_113 ;
switch ( V_112 ) {
case 1 :
V_4 -> V_6 |= F_37 ( 0x4 | V_111 ) ;
break;
case 2 :
if ( V_111 == 0 )
V_4 -> V_6 |= F_37 ( 0x2 ) ;
else if ( V_111 == 2 )
V_4 -> V_6 |= F_37 ( 0x3 ) ;
else
return - 1 ;
break;
case 4 :
V_4 -> V_6 |= F_37 ( 0x1 ) ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_13 = F_3 ( V_2 -> V_8 + V_9 ) ;
return F_39 ( V_13 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
const struct V_50 * V_51 = F_20 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
unsigned int V_10 = V_115 -> V_116 [ 1 ] ;
unsigned int V_38 = V_115 -> V_116 [ 2 ] ;
static const int V_91 = 2000 ;
int V_12 ;
int V_117 ;
V_4 = F_41 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_118 ;
V_117 = F_42 ( V_2 , V_115 -> V_116 [ 0 ] , V_119 ) ;
if ( V_117 )
return V_117 ;
if ( V_10 ) {
if ( V_10 < 3 || V_10 == 8 || V_10 == 13 || V_10 > 15 ) {
F_2 ( L_17 , V_10 ) ;
return - V_120 ;
}
if ( F_43 ( V_10 , F_4 , 0 ,
V_2 -> V_121 -> V_122 , V_2 ) ) {
F_2 ( L_18 , V_10 ) ;
return - V_120 ;
}
V_4 -> V_7 |= F_44 ( V_10 ) ;
V_2 -> V_10 = V_10 ;
}
if ( V_38 ) {
if ( V_38 == 4 || V_38 > 7 ) {
F_2 ( L_19 , V_38 ) ;
return - V_120 ;
}
if ( F_45 ( V_38 , V_2 -> V_121 -> V_122 ) ) {
F_2 ( L_20 , V_38 ) ;
return - V_120 ;
}
V_4 -> V_38 = V_38 ;
V_4 -> V_28 =
F_46 ( V_78 , V_123 | V_124 ) ;
if ( V_4 -> V_28 == NULL )
return - V_118 ;
F_9 ( V_38 ) ;
F_47 ( V_38 , V_125 ) ;
V_4 -> V_7 |= F_48 ( V_38 ) ;
}
V_2 -> V_126 = V_127 + F_38 ( V_2 ) ;
V_51 = F_20 ( V_2 ) ;
V_2 -> V_128 = V_51 -> V_129 ;
V_117 = F_49 ( V_2 , 1 ) ;
if ( V_117 )
return V_117 ;
V_16 = & V_2 -> V_130 [ 0 ] ;
V_2 -> V_17 = V_16 ;
V_16 -> type = V_131 ;
V_16 -> V_132 = V_133 | V_134 | V_135 | V_136 ;
V_16 -> V_137 = 4 ;
V_16 -> V_138 = 4 ;
V_16 -> V_139 = 0xffff ;
V_16 -> V_140 = & V_141 ;
V_16 -> V_142 = F_28 ;
V_16 -> V_143 = F_19 ;
V_16 -> V_144 = F_33 ;
V_16 -> V_145 = F_6 ;
F_18 ( V_146 , V_2 -> V_8 + V_147 ) ;
F_18 ( V_4 -> V_7 , V_2 -> V_8 + V_48 ) ;
F_50 ( V_148 | V_149 , V_2 -> V_8 + V_77 ) ;
F_50 ( V_148 , V_2 -> V_8 + V_77 ) ;
V_4 -> V_6 = 0 ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_77 ) ;
for ( V_12 = 0 ; V_12 < V_91 ; V_12 ++ ) {
if ( ( V_150 & F_3 ( V_2 -> V_8 + V_9 ) ) == 0 )
break;
F_34 ( 1000 ) ;
}
if ( V_12 == V_91 ) {
F_2
( L_21 ) ;
return - V_95 ;
}
V_4 -> V_6 |= V_151 | V_152 ;
F_18 ( V_4 -> V_6 , V_2 -> V_8 + V_77 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_8 )
F_18 ( V_149 | V_148 , V_2 -> V_8 + V_77 ) ;
if ( V_4 ) {
if ( V_4 -> V_38 )
F_52 ( V_4 -> V_38 ) ;
F_53 ( V_4 -> V_28 ) ;
}
F_54 ( V_2 ) ;
}
