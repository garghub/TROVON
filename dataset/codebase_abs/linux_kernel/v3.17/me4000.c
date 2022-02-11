static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_3 ( V_4 , 5 ) ;
T_1 V_9 = 0 ;
T_2 V_10 ;
int V_11 = 0 ;
int V_12 = 0 ;
unsigned int V_13 ;
if ( ! V_8 )
return - V_14 ;
F_4 ( & V_10 ) ;
F_5 ( V_15 , V_6 -> V_16 + V_17 ) ;
V_9 = F_6 ( V_6 -> V_16 + V_18 ) ;
V_9 |= V_19 ;
F_5 ( V_9 , V_6 -> V_16 + V_18 ) ;
F_7 ( V_8 + 0xC8 ) ;
F_8 ( 20 ) ;
V_13 = F_6 ( V_6 -> V_16 + V_17 ) ;
if ( ! ( V_13 & V_20 ) ) {
F_9 ( V_2 -> V_21 , L_1 ) ;
return - V_22 ;
}
V_9 = F_6 ( V_6 -> V_16 + V_18 ) ;
V_9 &= ~ V_19 ;
F_5 ( V_9 , V_6 -> V_16 + V_18 ) ;
if ( V_23 ) {
F_9 ( V_2 -> V_21 ,
L_2 ) ;
return - V_22 ;
} else {
V_12 = ( V_24 [ 0 ] << 24 ) + ( V_24 [ 1 ] << 16 ) +
( V_24 [ 2 ] << 8 ) + V_24 [ 3 ] ;
F_8 ( 10 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
F_10 ( V_24 [ 16 + V_11 ] , V_8 ) ;
F_8 ( 10 ) ;
if ( F_6 ( V_6 -> V_16 + V_18 ) & V_25 ) {
F_9 ( V_2 -> V_21 ,
L_3 ,
V_11 ) ;
return - V_22 ;
}
}
}
if ( F_6 ( V_6 -> V_16 + V_18 ) & V_26 ) {
} else {
F_9 ( V_2 -> V_21 , L_4 ) ;
F_9 ( V_2 -> V_21 , L_5 ) ;
return - V_22 ;
}
V_9 = F_6 ( V_6 -> V_16 + V_18 ) ;
V_9 |= V_19 ;
F_5 ( V_9 , V_6 -> V_16 + V_18 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_27 ;
int V_28 ;
V_27 = F_6 ( V_6 -> V_16 + V_18 ) ;
V_27 |= V_29 ;
F_5 ( V_27 , V_6 -> V_16 + V_18 ) ;
V_27 &= ~ V_29 ;
F_5 ( V_27 , V_6 -> V_16 + V_18 ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ )
F_5 ( 0x8000 , V_2 -> V_30 + F_12 ( V_28 ) ) ;
F_5 ( V_31 | V_32 ,
V_2 -> V_30 + V_33 ) ;
V_27 = V_34 | V_35 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ )
F_5 ( V_27 , V_2 -> V_30 + F_13 ( V_28 ) ) ;
F_5 ( V_36 |
V_37 |
V_38 , V_6 -> V_16 + V_17 ) ;
F_5 ( V_39 ,
V_2 -> V_30 + V_40 ) ;
if ( ! ( F_6 ( V_2 -> V_30 + V_41 ) & 0x1 ) )
F_5 ( 0x1 , V_2 -> V_30 + V_42 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
const struct V_48 * V_49 = F_15 ( V_2 ) ;
int V_28 = F_16 ( V_46 -> V_50 ) ;
int V_51 = F_17 ( V_46 -> V_50 ) ;
int V_52 = F_18 ( V_46 -> V_50 ) ;
unsigned int V_53 = 0 ;
unsigned int V_54 ;
unsigned int V_55 ;
if ( V_46 -> V_56 == 0 ) {
return 0 ;
} else if ( V_46 -> V_56 > 1 ) {
F_9 ( V_2 -> V_21 , L_6 ,
V_46 -> V_56 ) ;
return - V_57 ;
}
switch ( V_51 ) {
case 0 :
V_53 |= V_58 ;
break;
case 1 :
V_53 |= V_59 ;
break;
case 2 :
V_53 |= V_60 ;
break;
case 3 :
V_53 |= V_61 ;
break;
default:
F_9 ( V_2 -> V_21 , L_7 ) ;
return - V_57 ;
}
switch ( V_52 ) {
case V_62 :
case V_63 :
if ( V_28 >= V_49 -> V_64 ) {
F_9 ( V_2 -> V_21 ,
L_8 ) ;
return - V_57 ;
}
V_53 |= V_65 | V_28 ;
break;
case V_66 :
if ( V_51 == 0 || V_51 == 1 ) {
F_9 ( V_2 -> V_21 ,
L_9 ) ;
return - V_57 ;
}
if ( V_28 >= V_49 -> V_67 ) {
F_9 ( V_2 -> V_21 ,
L_8 ) ;
return - V_57 ;
}
V_53 |= V_68 | V_28 ;
break;
default:
F_9 ( V_2 -> V_21 , L_10 ) ;
return - V_57 ;
}
V_53 |= V_69 ;
V_54 = F_6 ( V_2 -> V_30 + V_33 ) ;
V_54 &= ~ ( V_70 |
V_71 |
V_32 | V_31 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
V_54 &= ~ ( V_72 | V_73 |
V_74 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
V_54 |= V_70 | V_71 ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
F_5 ( V_53 , V_2 -> V_30 + V_75 ) ;
F_5 ( V_76 , V_2 -> V_30 + V_77 ) ;
F_5 ( V_76 , V_2 -> V_30 + V_78 ) ;
F_6 ( V_2 -> V_30 + V_79 ) ;
F_8 ( 10 ) ;
if ( ! ( F_6 ( V_2 -> V_30 + V_80 ) &
V_81 ) ) {
F_9 ( V_2 -> V_21 , L_11 ) ;
return - V_22 ;
}
V_55 = F_6 ( V_2 -> V_30 + V_82 ) & 0xFFFF ;
V_47 [ 0 ] = V_55 ^ 0x8000 ;
return 1 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_43 * V_83 )
{
unsigned int V_54 ;
V_54 = F_6 ( V_2 -> V_30 + V_33 ) ;
V_54 &= ~ ( V_32 | V_31 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
F_5 ( 0x0 , V_2 -> V_30 + V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_84 * V_85 )
{
const struct V_48 * V_86 = F_15 ( V_2 ) ;
unsigned int V_87 = V_86 -> V_67 ;
unsigned int V_88 = F_18 ( V_85 -> V_89 [ 0 ] ) ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_85 -> V_91 ; V_90 ++ ) {
unsigned int V_28 = F_16 ( V_85 -> V_89 [ V_90 ] ) ;
unsigned int V_92 = F_17 ( V_85 -> V_89 [ V_90 ] ) ;
unsigned int V_52 = F_18 ( V_85 -> V_89 [ V_90 ] ) ;
if ( V_52 != V_88 ) {
F_21 ( V_2 -> V_21 ,
L_12 ) ;
return - V_57 ;
}
if ( V_52 == V_93 ) {
if ( V_28 >= V_87 ) {
F_21 ( V_2 -> V_21 ,
L_13 ) ;
return - V_57 ;
}
if ( ! F_22 ( V_83 , V_92 ) ) {
F_21 ( V_2 -> V_21 ,
L_14 ) ;
return - V_57 ;
}
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_84 * V_85 ,
unsigned int * V_94 ,
unsigned int * V_95 , unsigned int * V_96 )
{
int V_97 ;
* V_94 = 0 ;
* V_95 = 0 ;
* V_96 = 0 ;
if ( V_85 -> V_98 ) {
* V_94 = ( V_85 -> V_98 * 33 ) / 1000 ;
V_97 = ( V_85 -> V_98 * 33 ) % 1000 ;
if ( ( V_85 -> V_99 & V_100 ) == V_101 ) {
if ( V_97 > 33 )
( * V_94 ) ++ ;
} else if ( ( V_85 -> V_99 & V_100 ) == V_102 ) {
if ( V_97 )
( * V_94 ) ++ ;
}
}
if ( V_85 -> V_103 ) {
* V_95 = ( V_85 -> V_103 * 33 ) / 1000 ;
V_97 = ( V_85 -> V_103 * 33 ) % 1000 ;
if ( ( V_85 -> V_99 & V_100 ) == V_101 ) {
if ( V_97 > 33 )
( * V_95 ) ++ ;
} else if ( ( V_85 -> V_99 & V_100 ) == V_102 ) {
if ( V_97 )
( * V_95 ) ++ ;
}
}
if ( V_85 -> V_104 ) {
* V_96 = ( V_85 -> V_104 * 33 ) / 1000 ;
V_97 = ( V_85 -> V_104 * 33 ) % 1000 ;
if ( ( V_85 -> V_99 & V_100 ) == V_101 ) {
if ( V_97 > 33 )
( * V_96 ) ++ ;
} else if ( ( V_85 -> V_99 & V_100 ) == V_102 ) {
if ( V_97 )
( * V_96 ) ++ ;
}
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int V_94 ,
unsigned int V_95 , unsigned int V_96 )
{
F_5 ( V_94 - 1 , V_2 -> V_30 + V_105 ) ;
F_5 ( 0x0 , V_2 -> V_30 + V_106 ) ;
if ( V_95 ) {
F_5 ( V_95 - 1 , V_2 -> V_30 + V_107 ) ;
F_5 ( 0x0 , V_2 -> V_30 + V_108 ) ;
}
F_5 ( V_96 - 1 , V_2 -> V_30 + V_78 ) ;
F_5 ( V_96 - 1 , V_2 -> V_30 + V_77 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_43 * V_83 , struct V_84 * V_85 )
{
unsigned int V_53 ;
unsigned int V_28 ;
unsigned int V_51 ;
unsigned int V_52 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_85 -> V_91 ; V_90 ++ ) {
V_28 = F_16 ( V_85 -> V_89 [ V_90 ] ) ;
V_51 = F_17 ( V_85 -> V_89 [ V_90 ] ) ;
V_52 = F_18 ( V_85 -> V_89 [ V_90 ] ) ;
V_53 = V_28 ;
if ( V_51 == 0 )
V_53 |= V_58 ;
else if ( V_51 == 1 )
V_53 |= V_59 ;
else if ( V_51 == 2 )
V_53 |= V_60 ;
else
V_53 |= V_61 ;
if ( V_52 == V_93 )
V_53 |= V_68 ;
else
V_53 |= V_65 ;
F_5 ( V_53 , V_2 -> V_30 + V_75 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_84 * V_85 ,
unsigned int V_94 ,
unsigned int V_95 , unsigned int V_96 )
{
unsigned int V_54 = 0 ;
F_24 ( V_2 , V_94 , V_95 , V_96 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
if ( ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_112 &&
V_85 -> V_113 == V_112 ) ||
( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_114 &&
V_85 -> V_113 == V_112 ) ) {
V_54 = V_73 |
V_70 |
V_71 ;
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_110 &&
V_85 -> V_113 == V_112 ) {
V_54 = V_74 |
V_70 |
V_71 ;
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_110 &&
V_85 -> V_113 == V_110 ) {
V_54 = V_72 |
V_73 |
V_70 |
V_71 ;
} else {
V_54 = V_72 |
V_70 |
V_71 ;
}
if ( V_85 -> V_115 == V_116 ) {
F_5 ( V_85 -> V_91 * V_85 -> V_117 ,
V_2 -> V_30 + V_118 ) ;
V_54 |= V_119 | V_120 ;
} else if ( V_85 -> V_115 == V_121 &&
V_85 -> V_122 == V_116 ) {
F_5 ( V_85 -> V_123 ,
V_2 -> V_30 + V_118 ) ;
V_54 |= V_119 | V_120 ;
} else {
V_54 |= V_119 ;
}
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
F_25 ( V_2 , V_83 , V_85 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_43 * V_83 )
{
int V_124 ;
unsigned int V_94 = 0 ;
unsigned int V_95 = 0 ;
unsigned int V_96 = 0 ;
struct V_84 * V_85 = & V_83 -> V_125 -> V_85 ;
V_124 = F_19 ( V_2 , V_83 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_23 ( V_2 ,
V_83 , V_85 , & V_94 , & V_95 , & V_96 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_26 ( V_2 , V_83 , V_85 , V_94 , V_95 , V_96 ) ;
if ( V_124 )
return V_124 ;
F_6 ( V_2 -> V_30 + V_79 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_84 * V_85 )
{
unsigned int V_94 ;
unsigned int V_96 ;
unsigned int V_95 ;
int V_124 = 0 ;
V_85 -> V_99 &= V_101 | V_102 | V_126 ;
F_23 ( V_2 , V_83 , V_85 , & V_94 , & V_95 , & V_96 ) ;
V_124 |= F_29 ( & V_85 -> V_109 , V_127 | V_110 ) ;
V_124 |= F_29 ( & V_85 -> V_111 ,
V_114 | V_112 | V_110 ) ;
V_124 |= F_29 ( & V_85 -> V_113 , V_112 | V_110 ) ;
V_124 |= F_29 ( & V_85 -> V_122 ,
V_121 | V_116 ) ;
V_124 |= F_29 ( & V_85 -> V_115 , V_121 | V_116 ) ;
if ( V_124 )
return 1 ;
V_124 |= F_30 ( V_85 -> V_109 ) ;
V_124 |= F_30 ( V_85 -> V_111 ) ;
V_124 |= F_30 ( V_85 -> V_113 ) ;
V_124 |= F_30 ( V_85 -> V_122 ) ;
V_124 |= F_30 ( V_85 -> V_115 ) ;
if ( V_85 -> V_109 == V_127 &&
V_85 -> V_111 == V_112 &&
V_85 -> V_113 == V_112 ) {
} else if ( V_85 -> V_109 == V_127 &&
V_85 -> V_111 == V_114 &&
V_85 -> V_113 == V_112 ) {
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_112 &&
V_85 -> V_113 == V_112 ) {
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_114 &&
V_85 -> V_113 == V_112 ) {
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_110 &&
V_85 -> V_113 == V_112 ) {
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_110 &&
V_85 -> V_113 == V_110 ) {
} else {
V_124 |= - V_57 ;
}
if ( V_124 )
return 2 ;
V_124 |= F_31 ( & V_85 -> V_98 , 0 ) ;
if ( V_85 -> V_91 < 1 ) {
V_85 -> V_91 = 1 ;
V_124 |= - V_57 ;
}
if ( V_94 < 66 ) {
V_85 -> V_98 = 2000 ;
V_124 |= - V_57 ;
}
if ( V_95 && V_95 < 67 ) {
V_85 -> V_103 = 2031 ;
V_124 |= - V_57 ;
}
if ( V_96 < 66 ) {
V_85 -> V_104 = 2000 ;
V_124 |= - V_57 ;
}
if ( V_124 )
return 3 ;
if ( V_85 -> V_109 == V_127 &&
V_85 -> V_111 == V_112 &&
V_85 -> V_113 == V_112 ) {
if ( V_94 < V_76 ) {
F_9 ( V_2 -> V_21 , L_15 ) ;
V_85 -> V_98 = 2000 ;
V_124 ++ ;
}
if ( V_96 < V_76 ) {
F_9 ( V_2 -> V_21 , L_16 ) ;
V_85 -> V_104 = 2000 ;
V_124 ++ ;
}
if ( V_95 <= V_85 -> V_91 * V_96 ) {
F_9 ( V_2 -> V_21 , L_17 ) ;
V_85 -> V_123 = 2000 * V_85 -> V_91 + 31 ;
V_124 ++ ;
}
} else if ( V_85 -> V_109 == V_127 &&
V_85 -> V_111 == V_114 &&
V_85 -> V_113 == V_112 ) {
if ( V_94 < V_76 ) {
F_9 ( V_2 -> V_21 , L_15 ) ;
V_85 -> V_98 = 2000 ;
V_124 ++ ;
}
if ( V_96 < V_76 ) {
F_9 ( V_2 -> V_21 , L_16 ) ;
V_85 -> V_104 = 2000 ;
V_124 ++ ;
}
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_112 &&
V_85 -> V_113 == V_112 ) {
if ( V_94 < V_76 ) {
F_9 ( V_2 -> V_21 , L_15 ) ;
V_85 -> V_98 = 2000 ;
V_124 ++ ;
}
if ( V_96 < V_76 ) {
F_9 ( V_2 -> V_21 , L_16 ) ;
V_85 -> V_104 = 2000 ;
V_124 ++ ;
}
if ( V_95 <= V_85 -> V_91 * V_96 ) {
F_9 ( V_2 -> V_21 , L_17 ) ;
V_85 -> V_123 = 2000 * V_85 -> V_91 + 31 ;
V_124 ++ ;
}
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_114 &&
V_85 -> V_113 == V_112 ) {
if ( V_94 < V_76 ) {
F_9 ( V_2 -> V_21 , L_15 ) ;
V_85 -> V_98 = 2000 ;
V_124 ++ ;
}
if ( V_96 < V_76 ) {
F_9 ( V_2 -> V_21 , L_16 ) ;
V_85 -> V_104 = 2000 ;
V_124 ++ ;
}
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_110 &&
V_85 -> V_113 == V_112 ) {
if ( V_94 < V_76 ) {
F_9 ( V_2 -> V_21 , L_15 ) ;
V_85 -> V_98 = 2000 ;
V_124 ++ ;
}
if ( V_96 < V_76 ) {
F_9 ( V_2 -> V_21 , L_16 ) ;
V_85 -> V_104 = 2000 ;
V_124 ++ ;
}
} else if ( V_85 -> V_109 == V_110 &&
V_85 -> V_111 == V_110 &&
V_85 -> V_113 == V_110 ) {
if ( V_94 < V_76 ) {
F_9 ( V_2 -> V_21 , L_15 ) ;
V_85 -> V_98 = 2000 ;
V_124 ++ ;
}
}
if ( V_85 -> V_115 == V_116 ) {
if ( V_85 -> V_117 == 0 ) {
F_9 ( V_2 -> V_21 , L_18 ) ;
V_85 -> V_117 = 1 ;
V_124 ++ ;
}
}
if ( V_85 -> V_122 == V_116 ) {
if ( V_85 -> V_123 == 0 ) {
F_9 ( V_2 -> V_21 , L_17 ) ;
V_85 -> V_123 = 1 ;
V_124 ++ ;
}
}
if ( V_124 )
return 4 ;
if ( V_85 -> V_89 && V_85 -> V_91 > 0 )
V_124 |= F_20 ( V_2 , V_83 , V_85 ) ;
if ( V_124 )
return 5 ;
return 0 ;
}
static T_3 F_32 ( int V_128 , void * V_129 )
{
unsigned int V_54 ;
struct V_1 * V_2 = V_129 ;
struct V_43 * V_83 = V_2 -> V_130 ;
int V_90 ;
int V_131 = 0 ;
unsigned int V_55 ;
if ( ! V_2 -> V_132 )
return V_133 ;
if ( F_6 ( V_2 -> V_30 + V_134 ) &
V_135 ) {
V_54 = F_6 ( V_2 -> V_30 + V_33 ) ;
if ( ! ( V_54 & V_136 ) &&
! ( V_54 & V_137 ) &&
( V_54 & V_81 ) ) {
V_131 = V_138 ;
V_54 |= V_31 ;
V_54 &= ~ ( V_119 |
V_120 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
V_83 -> V_125 -> V_139 |= V_140 | V_141 ;
F_9 ( V_2 -> V_21 , L_19 ) ;
} else if ( ( V_54 & V_136 )
&& ! ( V_54 & V_137 )
&& ( V_54 & V_81 ) ) {
V_83 -> V_125 -> V_139 |= V_142 ;
V_131 = V_138 / 2 ;
} else {
F_9 ( V_2 -> V_21 ,
L_20 ) ;
V_131 = 0 ;
V_54 |= V_31 ;
V_54 &= ~ ( V_119 |
V_120 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
V_83 -> V_125 -> V_139 |= V_140 | V_141 ;
F_9 ( V_2 -> V_21 , L_21 ) ;
}
for ( V_90 = 0 ; V_90 < V_131 ; V_90 ++ ) {
V_55 = F_6 ( V_2 -> V_30 + V_82 ) & 0xFFFF ;
V_55 ^= 0x8000 ;
if ( ! F_33 ( V_83 , V_55 ) ) {
V_54 |= V_31 ;
V_54 &= ~ ( V_119 |
V_120 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
V_83 -> V_125 -> V_139 |= V_143 ;
F_9 ( V_2 -> V_21 , L_22 ) ;
break;
}
}
V_54 |= V_144 ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
V_54 &= ~ V_144 ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
}
if ( F_6 ( V_2 -> V_30 + V_134 ) &
V_145 ) {
V_83 -> V_125 -> V_139 |= V_142 | V_141 ;
V_54 = F_6 ( V_2 -> V_30 + V_33 ) ;
V_54 |= V_31 ;
V_54 &= ~ ( V_119 | V_120 ) ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
while ( F_6 ( V_2 -> V_30 + V_33 ) &
V_81 ) {
V_55 = F_6 ( V_2 -> V_30 + V_82 ) & 0xFFFF ;
V_55 ^= 0x8000 ;
if ( ! F_33 ( V_83 , V_55 ) ) {
F_9 ( V_2 -> V_21 , L_22 ) ;
V_83 -> V_125 -> V_139 |= V_143 ;
break;
}
}
V_54 |= V_146 ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
V_54 &= ~ V_146 ;
F_5 ( V_54 , V_2 -> V_30 + V_33 ) ;
}
if ( V_83 -> V_125 -> V_139 )
F_34 ( V_2 , V_83 ) ;
return V_147 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
const struct V_48 * V_49 = F_15 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_28 = F_16 ( V_46 -> V_50 ) ;
int V_51 = F_17 ( V_46 -> V_50 ) ;
int V_52 = F_18 ( V_46 -> V_50 ) ;
unsigned int V_54 ;
if ( V_46 -> V_56 == 0 ) {
return 0 ;
} else if ( V_46 -> V_56 > 1 ) {
F_9 ( V_2 -> V_21 , L_6 ,
V_46 -> V_56 ) ;
return - V_57 ;
}
if ( V_28 >= V_49 -> V_148 ) {
F_9 ( V_2 -> V_21 , L_23 , V_46 -> V_56 ) ;
return - V_57 ;
}
if ( V_51 != 0 ) {
F_9 ( V_2 -> V_21 , L_24 , V_46 -> V_56 ) ;
return - V_57 ;
}
if ( V_52 != V_62 && V_52 != V_63 ) {
F_9 ( V_2 -> V_21 , L_25 , V_46 -> V_56 ) ;
return - V_57 ;
}
V_54 = F_6 ( V_2 -> V_30 + F_13 ( V_28 ) ) ;
V_54 |= V_34 ;
F_5 ( V_54 , V_2 -> V_30 + F_13 ( V_28 ) ) ;
F_5 ( 0x0 , V_2 -> V_30 + F_13 ( V_28 ) ) ;
F_5 ( V_47 [ 0 ] , V_2 -> V_30 + F_12 ( V_28 ) ) ;
V_6 -> V_149 [ V_28 ] = V_47 [ 0 ] ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_28 = F_16 ( V_46 -> V_50 ) ;
if ( V_46 -> V_56 == 0 ) {
return 0 ;
} else if ( V_46 -> V_56 > 1 ) {
F_9 ( V_2 -> V_21 , L_26 ) ;
return - V_57 ;
}
V_47 [ 0 ] = V_6 -> V_149 [ V_28 ] ;
return 1 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
if ( F_38 ( V_83 , V_47 ) ) {
F_5 ( ( V_83 -> V_150 >> 0 ) & 0xFF ,
V_2 -> V_30 + V_151 ) ;
F_5 ( ( V_83 -> V_150 >> 8 ) & 0xFF ,
V_2 -> V_30 + V_152 ) ;
F_5 ( ( V_83 -> V_150 >> 16 ) & 0xFF ,
V_2 -> V_30 + V_153 ) ;
F_5 ( ( V_83 -> V_150 >> 24 ) & 0xFF ,
V_2 -> V_30 + V_154 ) ;
}
V_47 [ 1 ] = ( ( F_6 ( V_2 -> V_30 + V_151 ) & 0xFF ) << 0 ) |
( ( F_6 ( V_2 -> V_30 + V_152 ) & 0xFF ) << 8 ) |
( ( F_6 ( V_2 -> V_30 + V_153 ) & 0xFF ) << 16 ) |
( ( F_6 ( V_2 -> V_30 + V_154 ) & 0xFF ) << 24 ) ;
return V_46 -> V_56 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
unsigned int V_28 = F_16 ( V_46 -> V_50 ) ;
unsigned int V_155 ;
unsigned int V_54 ;
int V_156 ;
if ( V_28 < 8 )
V_155 = 0x000000ff ;
else if ( V_28 < 16 )
V_155 = 0x0000ff00 ;
else if ( V_28 < 24 )
V_155 = 0x00ff0000 ;
else
V_155 = 0xff000000 ;
V_156 = F_40 ( V_2 , V_83 , V_46 , V_47 , V_155 ) ;
if ( V_156 )
return V_156 ;
V_54 = F_6 ( V_2 -> V_30 + V_42 ) ;
V_54 &= ~ ( V_157 | V_158 |
V_159 | V_160 |
V_161 | V_162 |
V_163 | V_164 ) ;
if ( V_83 -> V_165 & 0x000000ff )
V_54 |= V_157 ;
if ( V_83 -> V_165 & 0x0000ff00 )
V_54 |= V_159 ;
if ( V_83 -> V_165 & 0x00ff0000 )
V_54 |= V_161 ;
if ( V_83 -> V_165 & 0xff000000 )
V_54 |= V_163 ;
if ( F_6 ( V_2 -> V_30 + V_41 ) ) {
V_83 -> V_165 |= 0x000000ff ;
V_83 -> V_165 &= ~ 0x0000ff00 ;
V_54 |= V_157 ;
V_54 &= ~ ( V_159 |
V_160 ) ;
}
F_5 ( V_54 , V_2 -> V_30 + V_42 ) ;
return V_46 -> V_56 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_28 = F_16 ( V_46 -> V_50 ) ;
int V_124 ;
switch ( V_47 [ 0 ] ) {
case V_166 :
if ( V_46 -> V_56 != 1 )
return - V_57 ;
V_124 = F_42 ( V_6 -> V_167 , 0 , V_28 ,
V_168 | V_169 ) ;
if ( V_124 )
return V_124 ;
F_43 ( V_6 -> V_167 , 0 , V_28 , 0 ) ;
break;
case V_170 :
if ( V_46 -> V_56 != 2 )
return - V_57 ;
V_124 = F_42 ( V_6 -> V_167 , 0 , V_28 ,
( V_47 [ 1 ] << 1 ) | V_169 ) ;
if ( V_124 )
return V_124 ;
break;
default:
return - V_57 ;
}
return V_46 -> V_56 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_46 -> V_56 == 0 )
return 0 ;
if ( V_46 -> V_56 > 1 ) {
F_9 ( V_2 -> V_21 , L_6 ,
V_46 -> V_56 ) ;
return - V_57 ;
}
V_47 [ 0 ] = F_45 ( V_6 -> V_167 , 0 , V_46 -> V_50 ) ;
return 1 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_43 * V_83 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_46 -> V_56 == 0 ) {
return 0 ;
} else if ( V_46 -> V_56 > 1 ) {
F_9 ( V_2 -> V_21 , L_6 ,
V_46 -> V_56 ) ;
return - V_57 ;
}
F_43 ( V_6 -> V_167 , 0 , V_46 -> V_50 , V_47 [ 0 ] ) ;
return 1 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned long V_171 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_48 * V_49 = NULL ;
struct V_5 * V_6 ;
struct V_43 * V_83 ;
int V_172 ;
if ( V_171 < F_48 ( V_173 ) )
V_49 = & V_173 [ V_171 ] ;
if ( ! V_49 )
return - V_14 ;
V_2 -> V_174 = V_49 ;
V_2 -> V_175 = V_49 -> V_176 ;
V_6 = F_49 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_177 ;
V_172 = F_50 ( V_2 ) ;
if ( V_172 )
return V_172 ;
V_6 -> V_16 = F_3 ( V_4 , 1 ) ;
V_2 -> V_30 = F_3 ( V_4 , 2 ) ;
V_6 -> V_167 = F_3 ( V_4 , 3 ) ;
if ( ! V_6 -> V_16 || ! V_2 -> V_30 || ! V_6 -> V_167 )
return - V_14 ;
V_172 = F_1 ( V_2 ) ;
if ( V_172 )
return V_172 ;
F_11 ( V_2 ) ;
if ( V_4 -> V_128 > 0 ) {
V_172 = F_51 ( V_4 -> V_128 , F_32 , V_178 ,
V_2 -> V_175 , V_2 ) ;
if ( V_172 == 0 )
V_2 -> V_128 = V_4 -> V_128 ;
}
V_172 = F_52 ( V_2 , 4 ) ;
if ( V_172 )
return V_172 ;
V_83 = & V_2 -> V_179 [ 0 ] ;
if ( V_49 -> V_64 ) {
V_83 -> type = V_180 ;
V_83 -> V_181 =
V_182 | V_183 | V_184 | V_93 ;
V_83 -> V_185 = V_49 -> V_64 ;
V_83 -> V_186 = 0xFFFF ;
V_83 -> V_187 = V_188 ;
V_83 -> V_189 = & V_190 ;
V_83 -> V_191 = F_14 ;
if ( V_2 -> V_128 ) {
V_2 -> V_130 = V_83 ;
V_83 -> V_181 |= V_192 ;
V_83 -> V_193 = F_19 ;
V_83 -> V_194 = F_28 ;
V_83 -> V_195 = F_27 ;
}
} else {
V_83 -> type = V_196 ;
}
V_83 = & V_2 -> V_179 [ 1 ] ;
if ( V_49 -> V_148 ) {
V_83 -> type = V_197 ;
V_83 -> V_181 = V_198 | V_183 | V_184 ;
V_83 -> V_185 = V_49 -> V_148 ;
V_83 -> V_186 = 0xFFFF ;
V_83 -> V_189 = & V_199 ;
V_83 -> V_200 = F_35 ;
V_83 -> V_191 = F_36 ;
} else {
V_83 -> type = V_196 ;
}
V_83 = & V_2 -> V_179 [ 2 ] ;
if ( V_49 -> V_201 ) {
V_83 -> type = V_202 ;
V_83 -> V_181 = V_182 | V_203 ;
V_83 -> V_185 = V_49 -> V_201 ;
V_83 -> V_186 = 1 ;
V_83 -> V_189 = & V_204 ;
V_83 -> V_205 = F_37 ;
V_83 -> V_206 = F_39 ;
} else {
V_83 -> type = V_196 ;
}
if ( ! F_6 ( V_2 -> V_30 + V_41 ) ) {
V_83 -> V_165 |= 0xFF ;
F_5 ( V_157 ,
V_2 -> V_30 + V_41 ) ;
}
V_83 = & V_2 -> V_179 [ 3 ] ;
if ( V_49 -> V_207 ) {
V_83 -> type = V_208 ;
V_83 -> V_181 = V_182 | V_203 ;
V_83 -> V_185 = 3 ;
V_83 -> V_186 = 0xFFFF ;
V_83 -> V_191 = F_44 ;
V_83 -> V_200 = F_46 ;
V_83 -> V_206 = F_41 ;
} else {
V_83 -> type = V_196 ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_128 )
F_54 ( V_2 -> V_128 , V_2 ) ;
if ( V_2 -> V_30 )
F_11 ( V_2 ) ;
F_55 ( V_2 ) ;
}
static int F_56 ( struct V_3 * V_2 ,
const struct V_209 * V_210 )
{
return F_57 ( V_2 , & V_211 , V_210 -> V_212 ) ;
}
