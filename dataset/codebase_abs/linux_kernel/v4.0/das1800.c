static inline T_1 F_1 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
V_3 += 1 << ( V_5 -> V_7 - 1 ) ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 * V_8 ,
unsigned int V_9 )
{
unsigned int V_10 ;
int V_11 ;
V_11 = F_3 ( V_2 -> V_12 + V_13 ) & V_14 ;
if ( ! V_11 ) {
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
V_8 [ V_10 ] = F_1 ( V_2 , V_8 [ V_10 ] ) ;
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_20 = F_5 ( V_16 , V_21 / 2 ) ;
F_6 ( V_2 -> V_12 + V_22 , V_18 -> V_23 , V_20 ) ;
F_2 ( V_2 , V_18 -> V_23 , V_20 ) ;
F_7 ( V_16 , V_18 -> V_23 , V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_24 * V_25 = & V_16 -> V_26 -> V_25 ;
unsigned short V_27 ;
int V_11 ;
V_11 = F_3 ( V_2 -> V_12 + V_13 ) & V_14 ;
while ( F_3 ( V_2 -> V_12 + V_28 ) & V_29 ) {
V_27 = F_9 ( V_2 -> V_12 + V_22 ) ;
if ( ! V_11 )
;
V_27 = F_1 ( V_2 , V_27 ) ;
F_7 ( V_16 , & V_27 , 1 ) ;
if ( V_25 -> V_30 == V_31 &&
V_16 -> V_26 -> V_32 >= V_25 -> V_33 )
break;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_34 * V_35 )
{
unsigned int V_36 = F_11 ( V_35 -> V_37 ) ;
unsigned int V_38 = V_35 -> V_39 - V_36 ;
unsigned int V_20 ;
V_20 = F_12 ( V_16 , V_38 ) ;
V_20 = F_5 ( V_16 , V_20 ) ;
F_2 ( V_2 , V_35 -> V_40 , V_20 ) ;
F_7 ( V_16 , V_35 -> V_40 , V_20 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_41 * V_42 = V_18 -> V_42 ;
struct V_34 * V_35 = & V_42 -> V_35 [ V_42 -> V_43 ] ;
const int V_44 = V_18 -> V_45 & V_46 ;
F_10 ( V_2 , V_16 , V_35 ) ;
if ( V_44 ) {
V_42 -> V_43 = 1 - V_42 -> V_43 ;
V_35 = & V_42 -> V_35 [ V_42 -> V_43 ] ;
F_10 ( V_2 , V_16 , V_35 ) ;
}
F_8 ( V_2 , V_16 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned int V_47 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_41 * V_42 = V_18 -> V_42 ;
struct V_34 * V_35 = & V_42 -> V_35 [ V_42 -> V_43 ] ;
const int V_44 = V_18 -> V_45 & V_46 ;
F_10 ( V_2 , V_16 , V_35 ) ;
F_15 ( V_35 ) ;
if ( V_47 & V_48 ) {
F_16 ( V_49 & ~ V_48 , V_2 -> V_12 + V_28 ) ;
if ( V_44 )
V_42 -> V_43 = 1 - V_42 -> V_43 ;
}
}
static int F_17 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_41 * V_42 = V_18 -> V_42 ;
struct V_34 * V_35 ;
int V_10 ;
F_16 ( 0x0 , V_2 -> V_12 + V_28 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_50 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_51 ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
V_35 = & V_42 -> V_35 [ V_10 ] ;
if ( V_35 -> V_37 )
F_11 ( V_35 -> V_37 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_15 * V_16 = V_2 -> V_52 ;
struct V_53 * V_26 = V_16 -> V_26 ;
struct V_24 * V_25 = & V_26 -> V_25 ;
unsigned int V_47 = F_3 ( V_2 -> V_12 + V_28 ) ;
F_16 ( V_54 , V_2 -> V_12 + V_55 ) ;
if ( V_18 -> V_45 & V_56 ) {
F_14 ( V_2 , V_16 , V_47 ) ;
} else if ( V_47 & V_57 ) {
F_4 ( V_2 , V_16 ) ;
} else if ( V_47 & V_29 ) {
F_8 ( V_2 , V_16 ) ;
}
if ( V_47 & V_58 ) {
F_16 ( V_49 & ~ V_58 , V_2 -> V_12 + V_28 ) ;
F_19 ( V_2 -> V_59 , L_1 ) ;
V_26 -> V_60 |= V_61 ;
F_20 ( V_2 , V_16 ) ;
return;
}
if ( V_47 & V_62 ) {
F_16 ( V_49 & ~ V_62 , V_2 -> V_12 + V_28 ) ;
if ( V_18 -> V_45 & V_56 )
F_13 ( V_2 , V_16 ) ;
else
F_8 ( V_2 , V_16 ) ;
V_26 -> V_60 |= V_63 ;
} else if ( V_25 -> V_30 == V_31 &&
V_26 -> V_32 >= V_25 -> V_33 ) {
V_26 -> V_60 |= V_63 ;
}
F_20 ( V_2 , V_16 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_64 ;
F_22 ( & V_2 -> V_65 , V_64 ) ;
F_18 ( V_2 ) ;
F_23 ( & V_2 -> V_65 , V_64 ) ;
return F_24 ( V_16 ) ;
}
static T_2 F_25 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned int V_47 ;
if ( ! V_2 -> V_68 ) {
F_19 ( V_2 -> V_59 , L_2 ) ;
return V_69 ;
}
F_26 ( & V_2 -> V_65 ) ;
V_47 = F_3 ( V_2 -> V_12 + V_28 ) ;
if ( ! ( V_47 & INT ) ) {
F_27 ( & V_2 -> V_65 ) ;
return V_70 ;
}
F_16 ( V_49 & ~ INT , V_2 -> V_12 + V_28 ) ;
F_18 ( V_2 ) ;
F_27 ( & V_2 -> V_65 ) ;
return V_69 ;
}
static unsigned int F_28 ( unsigned int V_71 , int V_64 )
{
unsigned int V_72 ;
if ( V_71 > 64000 )
V_71 = 64000 ;
switch ( V_64 & V_73 ) {
case V_74 :
default:
V_72 = ( V_71 + 500 ) / 1000 ;
break;
case V_75 :
V_72 = V_71 / 1000 ;
break;
case V_76 :
V_72 = ( V_71 - 1 ) / 1000 + 1 ;
break;
}
return V_72 * 1000 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_24 * V_25 )
{
unsigned int V_77 = F_30 ( V_25 -> V_78 [ 0 ] ) & V_79 ;
int V_10 ;
for ( V_10 = 1 ; V_10 < V_25 -> V_80 ; V_10 ++ ) {
unsigned int V_11 = F_30 ( V_25 -> V_78 [ V_10 ] ) & V_79 ;
if ( V_11 != V_77 ) {
F_31 ( V_2 -> V_59 ,
L_3 ) ;
return - V_81 ;
}
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_24 * V_25 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_82 = 0 ;
unsigned int V_83 ;
V_82 |= F_33 ( & V_25 -> V_84 , V_85 | V_86 ) ;
V_82 |= F_33 ( & V_25 -> V_87 ,
V_88 | V_89 | V_86 ) ;
V_82 |= F_33 ( & V_25 -> V_90 , V_89 | V_86 ) ;
V_82 |= F_33 ( & V_25 -> V_91 , V_31 ) ;
V_82 |= F_33 ( & V_25 -> V_30 ,
V_31 | V_86 | V_92 ) ;
if ( V_82 )
return 1 ;
V_82 |= F_34 ( V_25 -> V_84 ) ;
V_82 |= F_34 ( V_25 -> V_87 ) ;
V_82 |= F_34 ( V_25 -> V_90 ) ;
V_82 |= F_34 ( V_25 -> V_30 ) ;
if ( V_25 -> V_87 != V_88 &&
V_25 -> V_90 != V_89 )
V_82 |= - V_81 ;
if ( V_82 )
return 2 ;
V_82 |= F_35 ( & V_25 -> V_93 , 0 ) ;
if ( V_25 -> V_90 == V_89 )
V_82 |= F_36 ( & V_25 -> V_71 ,
V_5 -> V_94 ) ;
V_82 |= F_36 ( & V_25 -> V_80 , 1 ) ;
V_82 |= F_35 ( & V_25 -> V_95 , V_25 -> V_80 ) ;
switch ( V_25 -> V_30 ) {
case V_31 :
V_82 |= F_36 ( & V_25 -> V_33 , 1 ) ;
break;
case V_92 :
V_82 |= F_35 ( & V_25 -> V_33 , 0 ) ;
break;
default:
break;
}
if ( V_82 )
return 3 ;
if ( V_25 -> V_87 == V_88 &&
V_25 -> V_90 == V_89 ) {
V_83 = V_25 -> V_71 ;
F_37 ( V_96 ,
& V_18 -> V_97 ,
& V_18 -> V_98 ,
& V_25 -> V_71 , V_25 -> V_64 ) ;
if ( V_83 != V_25 -> V_71 )
V_82 ++ ;
} else if ( V_25 -> V_90 == V_89 ) {
V_83 = V_25 -> V_71 ;
V_25 -> V_71 = F_28 ( V_25 -> V_71 ,
V_25 -> V_64 ) ;
if ( V_83 != V_25 -> V_71 )
V_82 ++ ;
if ( V_25 -> V_87 == V_89 ) {
V_83 = V_25 -> V_71 * V_25 -> V_80 ;
if ( V_83 > V_25 -> V_99 ) {
V_25 -> V_99 = V_83 ;
V_82 ++ ;
}
V_83 = V_25 -> V_99 ;
F_37 ( V_96 ,
& V_18 -> V_97 ,
& V_18 -> V_98 ,
& V_25 -> V_99 ,
V_25 -> V_64 ) ;
if ( V_83 != V_25 -> V_99 )
V_82 ++ ;
}
}
if ( V_82 )
return 4 ;
if ( V_25 -> V_78 && V_25 -> V_80 > 0 )
V_82 |= F_29 ( V_2 , V_16 , V_25 ) ;
if ( V_82 )
return 5 ;
return 0 ;
}
static int F_38 ( const struct V_24 * V_25 )
{
int V_100 ;
V_100 = V_101 ;
if ( V_25 -> V_30 == V_86 )
V_100 |= V_102 ;
switch ( V_25 -> V_84 ) {
case V_86 :
V_100 |= V_103 | V_104 ;
break;
case V_85 :
V_100 |= V_105 ;
break;
default:
break;
}
return V_100 ;
}
static int F_39 ( const struct V_24 * V_25 )
{
int V_106 ;
int V_107 ;
V_107 = F_40 ( V_25 -> V_78 [ 0 ] ) ;
V_106 = V_108 ;
if ( V_107 != V_109 )
V_106 |= V_110 ;
if ( V_107 == V_111 )
V_106 |= V_112 ;
if ( F_30 ( V_25 -> V_78 [ 0 ] ) & V_79 )
V_106 |= V_14 ;
switch ( V_25 -> V_87 ) {
case V_88 :
switch ( V_25 -> V_90 ) {
case V_89 :
V_106 |= V_113 ;
break;
case V_86 :
V_106 |= V_114 ;
break;
default:
break;
}
break;
case V_89 :
V_106 |= V_115 | V_113 ;
break;
case V_86 :
V_106 |= V_115 | V_114 ;
break;
default:
break;
}
return V_106 ;
}
static void F_41 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_116 = V_2 -> V_12 + V_117 ;
if ( ( V_25 -> V_87 == V_88 ||
V_25 -> V_87 == V_89 ) &&
V_25 -> V_90 == V_89 ) {
F_42 ( V_116 , 0 , 1 , V_118 | V_119 ) ;
F_42 ( V_116 , 0 , 2 , V_118 | V_119 ) ;
F_43 ( V_116 , 0 , 1 , V_18 -> V_97 ) ;
F_43 ( V_116 , 0 , 2 , V_18 -> V_98 ) ;
}
if ( V_25 -> V_30 == V_86 ) {
F_42 ( V_116 , 0 , 0 , V_120 | V_119 ) ;
F_43 ( V_116 , 0 , 0 , 1 ) ;
}
}
static unsigned int F_44 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int V_121 ,
unsigned int V_122 )
{
struct V_24 * V_25 = & V_16 -> V_26 -> V_25 ;
unsigned int V_123 = F_12 ( V_16 , V_121 ) ;
unsigned int V_124 ;
V_124 = V_123 ;
switch ( V_25 -> V_87 ) {
case V_88 :
if ( V_25 -> V_90 == V_89 )
V_124 = V_122 / V_25 -> V_71 ;
break;
case V_89 :
V_124 = V_122 / ( V_25 -> V_99 * V_25 -> V_80 ) ;
break;
}
V_124 = F_5 ( V_16 , V_124 ) ;
if ( V_124 > V_123 )
V_124 = V_123 ;
if ( V_124 < 1 )
V_124 = 1 ;
return F_45 ( V_16 , V_124 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_41 * V_42 = V_18 -> V_42 ;
struct V_34 * V_35 = & V_42 -> V_35 [ 0 ] ;
unsigned int V_125 ;
if ( ( V_18 -> V_45 & V_56 ) == 0 )
return;
V_42 -> V_43 = 0 ;
V_125 = F_44 ( V_2 , V_16 , V_35 -> V_126 , 300000000 ) ;
V_35 -> V_39 = V_125 ;
F_15 ( V_35 ) ;
if ( V_18 -> V_45 & V_46 ) {
V_35 = & V_42 -> V_35 [ 1 ] ;
V_35 -> V_39 = V_125 ;
F_15 ( V_35 ) ;
}
}
static void F_47 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
int V_10 , V_127 , V_128 ;
unsigned long V_129 ;
const int V_130 = 0x3 ;
const int V_131 = 8 ;
V_127 = V_25 -> V_80 ;
F_22 ( & V_2 -> V_65 , V_129 ) ;
F_16 ( V_132 , V_2 -> V_12 + V_55 ) ;
F_16 ( V_127 - 1 , V_2 -> V_12 + V_133 ) ;
for ( V_10 = 0 ; V_10 < V_127 ; V_10 ++ ) {
V_128 =
F_48 ( V_25 -> V_78 [ V_10 ] ) |
( ( F_30 ( V_25 -> V_78 [ V_10 ] ) & V_130 ) <<
V_131 ) ;
F_49 ( V_128 , V_2 -> V_12 + V_134 ) ;
}
F_16 ( V_127 - 1 , V_2 -> V_12 + V_133 ) ;
F_23 ( & V_2 -> V_65 , V_129 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
int V_100 , V_106 ;
struct V_53 * V_26 = V_16 -> V_26 ;
const struct V_24 * V_25 = & V_26 -> V_25 ;
if ( V_25 -> V_64 & ( V_135 | V_136 ) )
V_18 -> V_45 &= ~ V_56 ;
else
V_18 -> V_45 |= V_18 -> V_137 ;
if ( V_25 -> V_64 & V_135 ) {
V_18 -> V_45 &= ~ V_138 ;
} else {
V_18 -> V_45 |= V_138 ;
}
F_17 ( V_2 , V_16 ) ;
V_100 = F_38 ( V_25 ) ;
V_106 = F_39 ( V_25 ) ;
F_47 ( V_2 , V_25 ) ;
F_41 ( V_2 , V_25 ) ;
F_46 ( V_2 , V_16 ) ;
F_16 ( V_106 , V_2 -> V_12 + V_13 ) ;
if ( V_106 & V_115 ) {
F_16 ( V_25 -> V_71 / 1000 - 1 ,
V_2 -> V_12 + V_139 ) ;
F_16 ( V_25 -> V_80 - 1 , V_2 -> V_12 + V_140 ) ;
}
F_16 ( V_18 -> V_45 , V_2 -> V_12 + V_50 ) ;
F_16 ( V_100 , V_2 -> V_12 + V_51 ) ;
F_16 ( V_141 , V_2 -> V_12 + V_28 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_142 * V_143 , unsigned int * V_144 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 , V_127 ;
int V_37 , V_145 , V_107 , V_128 ;
int V_146 = 1000 ;
unsigned short V_27 ;
int V_147 = 0 ;
unsigned long V_129 ;
V_107 = F_40 ( V_143 -> V_148 ) ;
V_147 |= V_108 ;
if ( V_107 != V_109 )
V_147 |= V_110 ;
if ( V_107 == V_111 )
V_147 |= V_112 ;
if ( F_30 ( V_143 -> V_148 ) & V_79 )
V_147 |= V_14 ;
F_16 ( V_147 , V_2 -> V_12 + V_13 ) ;
F_16 ( V_141 , V_2 -> V_12 + V_28 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_51 ) ;
F_16 ( V_101 , V_2 -> V_12 + V_51 ) ;
V_37 = F_48 ( V_143 -> V_148 ) ;
V_145 = F_30 ( V_143 -> V_148 ) & 0x3 ;
V_128 = V_37 | ( V_145 << 8 ) ;
F_22 ( & V_2 -> V_65 , V_129 ) ;
F_16 ( V_132 , V_2 -> V_12 + V_55 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_133 ) ;
F_49 ( V_128 , V_2 -> V_12 + V_134 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_133 ) ;
F_16 ( V_54 , V_2 -> V_12 + V_55 ) ;
for ( V_127 = 0 ; V_127 < V_143 -> V_127 ; V_127 ++ ) {
F_16 ( 0 , V_2 -> V_12 + V_22 ) ;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ ) {
if ( F_3 ( V_2 -> V_12 + V_28 ) & V_29 )
break;
}
if ( V_10 == V_146 ) {
F_19 ( V_2 -> V_59 , L_4 ) ;
V_127 = - V_149 ;
goto exit;
}
V_27 = F_9 ( V_2 -> V_12 + V_22 ) ;
if ( ( V_147 & V_14 ) == 0 )
V_27 += 1 << ( V_5 -> V_7 - 1 ) ;
V_144 [ V_127 ] = V_27 ;
}
exit:
F_23 ( & V_2 -> V_65 , V_129 ) ;
return V_127 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_142 * V_143 , unsigned int * V_144 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_37 = F_48 ( V_143 -> V_148 ) ;
int V_150 = V_5 -> V_151 - 1 ;
unsigned short V_152 ;
unsigned long V_129 ;
V_152 = V_144 [ 0 ] - ( 1 << ( V_5 -> V_7 - 1 ) ) ;
if ( V_37 == V_150 )
V_18 -> V_153 = V_152 ;
F_22 ( & V_2 -> V_65 , V_129 ) ;
F_16 ( F_53 ( V_37 ) , V_2 -> V_12 + V_55 ) ;
F_49 ( V_152 , V_2 -> V_12 + V_154 ) ;
if ( V_37 != V_150 ) {
F_16 ( F_53 ( V_150 ) , V_2 -> V_12 + V_55 ) ;
F_49 ( V_18 -> V_153 , V_2 -> V_12 + V_154 ) ;
}
F_23 ( & V_2 -> V_65 , V_129 ) ;
return 1 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_142 * V_143 , unsigned int * V_144 )
{
V_144 [ 1 ] = F_3 ( V_2 -> V_12 + V_155 ) & 0xf ;
V_144 [ 0 ] = 0 ;
return V_143 -> V_127 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_142 * V_143 ,
unsigned int * V_144 )
{
if ( F_56 ( V_16 , V_144 ) )
F_16 ( V_16 -> V_156 , V_2 -> V_12 + V_155 ) ;
V_144 [ 1 ] = V_16 -> V_156 ;
return V_143 -> V_127 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int * V_159 ;
V_159 = & V_158 -> V_160 [ 2 ] ;
switch ( ( V_159 [ 0 ] & 0x7 ) | ( V_159 [ 1 ] << 4 ) ) {
case 0x5 :
V_18 -> V_137 = V_161 ;
break;
case 0x6 :
V_18 -> V_137 = V_162 ;
break;
case 0x7 :
V_18 -> V_137 = V_163 ;
break;
case 0x65 :
V_18 -> V_137 = V_164 ;
break;
case 0x76 :
V_18 -> V_137 = V_165 ;
break;
case 0x57 :
V_18 -> V_137 = V_166 ;
break;
default:
return;
}
V_18 -> V_42 = F_58 ( V_2 , V_159 [ 1 ] ? 2 : 1 ,
V_159 [ 0 ] , V_159 [ 1 ] ,
V_167 , V_168 ) ;
if ( ! V_18 -> V_42 )
V_18 -> V_137 = 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_18 )
F_60 ( V_18 -> V_42 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
const struct V_4 * V_169 = V_2 -> V_6 ;
int V_170 ;
int V_171 ;
V_170 = V_169 - V_172 ;
V_171 = ( F_3 ( V_2 -> V_12 + V_155 ) >> 4 ) & 0xf ;
switch ( V_171 ) {
case 0x3 :
if ( V_170 == V_173 || V_170 == V_174 ||
V_170 == V_175 || V_170 == V_176 )
return V_170 ;
V_170 = V_177 ;
break;
case 0x4 :
if ( V_170 == V_178 || V_170 == V_179 )
return V_170 ;
V_170 = V_180 ;
break;
case 0x5 :
if ( V_170 == V_181 || V_170 == V_182 ||
V_170 == V_183 || V_170 == V_184 )
return V_170 ;
V_170 = V_181 ;
break;
case 0x6 :
if ( V_170 == V_180 || V_170 == V_185 )
return V_170 ;
V_170 = V_180 ;
break;
case 0x7 :
if ( V_170 == V_177 || V_170 == V_186 ||
V_170 == V_187 || V_170 == V_188 )
return V_170 ;
V_170 = V_177 ;
break;
case 0x8 :
if ( V_170 == V_189 || V_170 == V_190 )
return V_170 ;
V_170 = V_189 ;
break;
default:
F_19 ( V_2 -> V_59 ,
L_5 ,
V_171 ) ;
break;
}
F_19 ( V_2 -> V_59 ,
L_6 ,
V_172 [ V_170 ] . V_191 ) ;
return V_170 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
const struct V_4 * V_5 ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
unsigned int V_66 = V_158 -> V_160 [ 1 ] ;
int V_169 ;
int V_192 ;
V_18 = F_63 ( V_2 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_193 ;
V_192 = F_64 ( V_2 , V_158 -> V_160 [ 0 ] , V_194 ) ;
if ( V_192 )
return V_192 ;
V_169 = F_61 ( V_2 ) ;
if ( V_169 < 0 ) {
F_19 ( V_2 -> V_59 , L_7 ) ;
return - V_195 ;
}
V_2 -> V_6 = V_172 + V_169 ;
V_5 = V_2 -> V_6 ;
V_2 -> V_196 = V_5 -> V_191 ;
if ( V_5 -> V_197 == 2 ) {
unsigned long V_198 = V_2 -> V_12 + V_199 ;
V_192 = F_65 ( V_2 , V_198 , V_194 ) ;
if ( V_192 )
return V_192 ;
V_18 -> V_198 = V_198 ;
}
if ( V_66 == 3 || V_66 == 5 || V_66 == 7 || V_66 == 10 || V_66 == 11 ||
V_66 == 15 ) {
V_192 = F_66 ( V_66 , F_25 , 0 ,
V_2 -> V_196 , V_2 ) ;
if ( V_192 == 0 ) {
V_2 -> V_66 = V_66 ;
switch ( V_66 ) {
case 3 :
V_18 -> V_45 |= 0x8 ;
break;
case 5 :
V_18 -> V_45 |= 0x10 ;
break;
case 7 :
V_18 -> V_45 |= 0x18 ;
break;
case 10 :
V_18 -> V_45 |= 0x28 ;
break;
case 11 :
V_18 -> V_45 |= 0x30 ;
break;
case 15 :
V_18 -> V_45 |= 0x38 ;
break;
}
}
}
if ( V_2 -> V_66 & V_158 -> V_160 [ 2 ] )
F_57 ( V_2 , V_158 ) ;
V_18 -> V_23 = F_67 ( V_21 , sizeof( T_1 ) , V_200 ) ;
if ( ! V_18 -> V_23 )
return - V_193 ;
V_192 = F_68 ( V_2 , 4 ) ;
if ( V_192 )
return V_192 ;
V_16 = & V_2 -> V_201 [ 0 ] ;
V_16 -> type = V_202 ;
V_16 -> V_203 = V_204 | V_205 | V_206 ;
if ( V_5 -> V_207 )
V_16 -> V_203 |= V_208 ;
V_16 -> V_209 = V_5 -> V_210 ;
V_16 -> V_211 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_212 = V_5 -> V_213 ;
V_16 -> V_214 = F_51 ;
if ( V_2 -> V_66 ) {
V_2 -> V_52 = V_16 ;
V_16 -> V_203 |= V_215 ;
V_16 -> V_216 = V_16 -> V_209 ;
V_16 -> V_217 = F_50 ;
V_16 -> V_218 = F_32 ;
V_16 -> V_219 = F_21 ;
V_16 -> V_220 = F_17 ;
}
V_16 = & V_2 -> V_201 [ 1 ] ;
if ( V_5 -> V_197 == 1 ) {
V_16 -> type = V_221 ;
V_16 -> V_203 = V_222 ;
V_16 -> V_209 = V_5 -> V_151 ;
V_16 -> V_211 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_212 = & V_223 ;
V_16 -> V_224 = F_52 ;
} else {
V_16 -> type = V_225 ;
}
V_16 = & V_2 -> V_201 [ 2 ] ;
V_16 -> type = V_226 ;
V_16 -> V_203 = V_204 ;
V_16 -> V_209 = 4 ;
V_16 -> V_211 = 1 ;
V_16 -> V_212 = & V_227 ;
V_16 -> V_228 = F_54 ;
V_16 = & V_2 -> V_201 [ 3 ] ;
V_16 -> type = V_229 ;
V_16 -> V_203 = V_222 ;
V_16 -> V_209 = V_5 -> V_230 ;
V_16 -> V_211 = 1 ;
V_16 -> V_212 = & V_227 ;
V_16 -> V_228 = F_55 ;
F_17 ( V_2 , V_2 -> V_52 ) ;
F_16 ( 0 , V_2 -> V_12 + V_155 ) ;
if ( V_5 -> V_197 == 1 ) {
F_16 ( F_53 ( V_5 -> V_151 - 1 ) ,
V_2 -> V_12 + V_55 ) ;
F_49 ( V_18 -> V_153 , V_2 -> V_12 + V_154 ) ;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
F_59 ( V_2 ) ;
if ( V_18 ) {
F_70 ( V_18 -> V_23 ) ;
if ( V_18 -> V_198 )
F_71 ( V_18 -> V_198 , V_194 ) ;
}
F_72 ( V_2 ) ;
}
