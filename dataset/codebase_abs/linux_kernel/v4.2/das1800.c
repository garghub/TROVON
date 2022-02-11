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
int V_82 = 0 ;
unsigned int V_83 ;
V_82 |= F_33 ( & V_25 -> V_84 , V_85 | V_86 ) ;
V_82 |= F_33 ( & V_25 -> V_87 ,
V_88 | V_89 | V_86 ) ;
V_82 |= F_33 ( & V_25 -> V_90 ,
V_89 | V_86 ) ;
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
if ( V_25 -> V_90 == V_89 ) {
V_82 |= F_36 ( & V_25 -> V_71 ,
V_5 -> V_94 ) ;
}
V_82 |= F_36 ( & V_25 -> V_80 , 1 ) ;
V_82 |= F_35 ( & V_25 -> V_95 ,
V_25 -> V_80 ) ;
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
F_37 ( V_2 -> V_96 , & V_83 , V_25 -> V_64 ) ;
V_82 |= F_35 ( & V_25 -> V_71 , V_83 ) ;
} else if ( V_25 -> V_90 == V_89 ) {
V_83 = F_28 ( V_25 -> V_71 , V_25 -> V_64 ) ;
V_82 |= F_35 ( & V_25 -> V_71 , V_83 ) ;
if ( V_25 -> V_87 == V_89 ) {
V_83 = V_25 -> V_71 * V_25 -> V_80 ;
V_82 |= F_38 ( & V_25 ->
V_97 ,
V_83 ) ;
V_83 = V_25 -> V_97 ;
F_37 ( V_2 -> V_96 , & V_83 ,
V_25 -> V_64 ) ;
V_82 |= F_35 ( & V_25 -> V_97 ,
V_83 ) ;
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
static int F_39 ( const struct V_24 * V_25 )
{
int V_98 ;
V_98 = V_99 ;
if ( V_25 -> V_30 == V_86 )
V_98 |= V_100 ;
switch ( V_25 -> V_84 ) {
case V_86 :
V_98 |= V_101 | V_102 ;
break;
case V_85 :
V_98 |= V_103 ;
break;
default:
break;
}
return V_98 ;
}
static int F_40 ( const struct V_24 * V_25 )
{
int V_104 ;
int V_105 ;
V_105 = F_41 ( V_25 -> V_78 [ 0 ] ) ;
V_104 = V_106 ;
if ( V_105 != V_107 )
V_104 |= V_108 ;
if ( V_105 == V_109 )
V_104 |= V_110 ;
if ( F_30 ( V_25 -> V_78 [ 0 ] ) & V_79 )
V_104 |= V_14 ;
switch ( V_25 -> V_87 ) {
case V_88 :
switch ( V_25 -> V_90 ) {
case V_89 :
V_104 |= V_111 ;
break;
case V_86 :
V_104 |= V_112 ;
break;
default:
break;
}
break;
case V_89 :
V_104 |= V_113 | V_111 ;
break;
case V_86 :
V_104 |= V_113 | V_112 ;
break;
default:
break;
}
return V_104 ;
}
static unsigned int F_42 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int V_114 ,
unsigned int V_115 )
{
struct V_24 * V_25 = & V_16 -> V_26 -> V_25 ;
unsigned int V_116 = F_12 ( V_16 , V_114 ) ;
unsigned int V_117 ;
V_117 = V_116 ;
switch ( V_25 -> V_87 ) {
case V_88 :
if ( V_25 -> V_90 == V_89 )
V_117 = V_115 / V_25 -> V_71 ;
break;
case V_89 :
V_117 = V_115 / ( V_25 -> V_97 * V_25 -> V_80 ) ;
break;
}
V_117 = F_5 ( V_16 , V_117 ) ;
if ( V_117 > V_116 )
V_117 = V_116 ;
if ( V_117 < 1 )
V_117 = 1 ;
return F_43 ( V_16 , V_117 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_41 * V_42 = V_18 -> V_42 ;
struct V_34 * V_35 = & V_42 -> V_35 [ 0 ] ;
unsigned int V_118 ;
if ( ( V_18 -> V_45 & V_56 ) == 0 )
return;
V_42 -> V_43 = 0 ;
V_118 = F_42 ( V_2 , V_16 , V_35 -> V_119 , 300000000 ) ;
V_35 -> V_39 = V_118 ;
F_15 ( V_35 ) ;
if ( V_18 -> V_45 & V_46 ) {
V_35 = & V_42 -> V_35 [ 1 ] ;
V_35 -> V_39 = V_118 ;
F_15 ( V_35 ) ;
}
}
static void F_45 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
int V_10 , V_120 , V_121 ;
unsigned long V_122 ;
const int V_123 = 0x3 ;
const int V_124 = 8 ;
V_120 = V_25 -> V_80 ;
F_22 ( & V_2 -> V_65 , V_122 ) ;
F_16 ( V_125 , V_2 -> V_12 + V_55 ) ;
F_16 ( V_120 - 1 , V_2 -> V_12 + V_126 ) ;
for ( V_10 = 0 ; V_10 < V_120 ; V_10 ++ ) {
V_121 =
F_46 ( V_25 -> V_78 [ V_10 ] ) |
( ( F_30 ( V_25 -> V_78 [ V_10 ] ) & V_123 ) <<
V_124 ) ;
F_47 ( V_121 , V_2 -> V_12 + V_127 ) ;
}
F_16 ( V_120 - 1 , V_2 -> V_12 + V_126 ) ;
F_23 ( & V_2 -> V_65 , V_122 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
int V_98 , V_104 ;
struct V_53 * V_26 = V_16 -> V_26 ;
const struct V_24 * V_25 = & V_26 -> V_25 ;
if ( V_25 -> V_64 & ( V_128 | V_129 ) )
V_18 -> V_45 &= ~ V_56 ;
else
V_18 -> V_45 |= V_18 -> V_130 ;
if ( V_25 -> V_64 & V_128 ) {
V_18 -> V_45 &= ~ V_131 ;
} else {
V_18 -> V_45 |= V_131 ;
}
F_17 ( V_2 , V_16 ) ;
V_98 = F_39 ( V_25 ) ;
V_104 = F_40 ( V_25 ) ;
F_45 ( V_2 , V_25 ) ;
if ( ( V_25 -> V_87 == V_88 ||
V_25 -> V_87 == V_89 ) &&
V_25 -> V_90 == V_89 ) {
F_49 ( V_2 -> V_96 ) ;
F_50 ( V_2 -> V_96 , 1 , 2 , true ) ;
}
if ( V_25 -> V_30 == V_86 )
F_51 ( V_2 -> V_96 , 0 , 1 , V_132 | V_133 ) ;
F_44 ( V_2 , V_16 ) ;
F_16 ( V_104 , V_2 -> V_12 + V_13 ) ;
if ( V_104 & V_113 ) {
F_16 ( V_25 -> V_71 / 1000 - 1 ,
V_2 -> V_12 + V_134 ) ;
F_16 ( V_25 -> V_80 - 1 , V_2 -> V_12 + V_135 ) ;
}
F_16 ( V_18 -> V_45 , V_2 -> V_12 + V_50 ) ;
F_16 ( V_98 , V_2 -> V_12 + V_51 ) ;
F_16 ( V_136 , V_2 -> V_12 + V_28 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_137 * V_138 , unsigned int * V_139 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 , V_120 ;
int V_37 , V_140 , V_105 , V_121 ;
int V_141 = 1000 ;
unsigned short V_27 ;
int V_142 = 0 ;
unsigned long V_122 ;
V_105 = F_41 ( V_138 -> V_143 ) ;
V_142 |= V_106 ;
if ( V_105 != V_107 )
V_142 |= V_108 ;
if ( V_105 == V_109 )
V_142 |= V_110 ;
if ( F_30 ( V_138 -> V_143 ) & V_79 )
V_142 |= V_14 ;
F_16 ( V_142 , V_2 -> V_12 + V_13 ) ;
F_16 ( V_136 , V_2 -> V_12 + V_28 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_51 ) ;
F_16 ( V_99 , V_2 -> V_12 + V_51 ) ;
V_37 = F_46 ( V_138 -> V_143 ) ;
V_140 = F_30 ( V_138 -> V_143 ) & 0x3 ;
V_121 = V_37 | ( V_140 << 8 ) ;
F_22 ( & V_2 -> V_65 , V_122 ) ;
F_16 ( V_125 , V_2 -> V_12 + V_55 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_126 ) ;
F_47 ( V_121 , V_2 -> V_12 + V_127 ) ;
F_16 ( 0x0 , V_2 -> V_12 + V_126 ) ;
F_16 ( V_54 , V_2 -> V_12 + V_55 ) ;
for ( V_120 = 0 ; V_120 < V_138 -> V_120 ; V_120 ++ ) {
F_16 ( 0 , V_2 -> V_12 + V_22 ) ;
for ( V_10 = 0 ; V_10 < V_141 ; V_10 ++ ) {
if ( F_3 ( V_2 -> V_12 + V_28 ) & V_29 )
break;
}
if ( V_10 == V_141 ) {
F_19 ( V_2 -> V_59 , L_4 ) ;
V_120 = - V_144 ;
goto exit;
}
V_27 = F_9 ( V_2 -> V_12 + V_22 ) ;
if ( ( V_142 & V_14 ) == 0 )
V_27 += 1 << ( V_5 -> V_7 - 1 ) ;
V_139 [ V_120 ] = V_27 ;
}
exit:
F_23 ( & V_2 -> V_65 , V_122 ) ;
return V_120 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_137 * V_138 , unsigned int * V_139 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_37 = F_46 ( V_138 -> V_143 ) ;
int V_145 = V_5 -> V_146 - 1 ;
unsigned short V_147 ;
unsigned long V_122 ;
V_147 = V_139 [ 0 ] - ( 1 << ( V_5 -> V_7 - 1 ) ) ;
if ( V_37 == V_145 )
V_18 -> V_148 = V_147 ;
F_22 ( & V_2 -> V_65 , V_122 ) ;
F_16 ( F_54 ( V_37 ) , V_2 -> V_12 + V_55 ) ;
F_47 ( V_147 , V_2 -> V_12 + V_149 ) ;
if ( V_37 != V_145 ) {
F_16 ( F_54 ( V_145 ) , V_2 -> V_12 + V_55 ) ;
F_47 ( V_18 -> V_148 , V_2 -> V_12 + V_149 ) ;
}
F_23 ( & V_2 -> V_65 , V_122 ) ;
return 1 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_137 * V_138 , unsigned int * V_139 )
{
V_139 [ 1 ] = F_3 ( V_2 -> V_12 + V_150 ) & 0xf ;
V_139 [ 0 ] = 0 ;
return V_138 -> V_120 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_137 * V_138 ,
unsigned int * V_139 )
{
if ( F_57 ( V_16 , V_139 ) )
F_16 ( V_16 -> V_151 , V_2 -> V_12 + V_150 ) ;
V_139 [ 1 ] = V_16 -> V_151 ;
return V_138 -> V_120 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int * V_154 ;
V_154 = & V_153 -> V_155 [ 2 ] ;
switch ( ( V_154 [ 0 ] & 0x7 ) | ( V_154 [ 1 ] << 4 ) ) {
case 0x5 :
V_18 -> V_130 = V_156 ;
break;
case 0x6 :
V_18 -> V_130 = V_157 ;
break;
case 0x7 :
V_18 -> V_130 = V_158 ;
break;
case 0x65 :
V_18 -> V_130 = V_159 ;
break;
case 0x76 :
V_18 -> V_130 = V_160 ;
break;
case 0x57 :
V_18 -> V_130 = V_161 ;
break;
default:
return;
}
V_18 -> V_42 = F_59 ( V_2 , V_154 [ 1 ] ? 2 : 1 ,
V_154 [ 0 ] , V_154 [ 1 ] ,
V_162 , V_163 ) ;
if ( ! V_18 -> V_42 )
V_18 -> V_130 = 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_18 )
F_61 ( V_18 -> V_42 ) ;
}
static const struct V_4 * F_62 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
int V_164 = V_5 ? V_5 - V_165 : - V_81 ;
int V_166 ;
V_166 = ( F_3 ( V_2 -> V_12 + V_150 ) >> 4 ) & 0xf ;
switch ( V_166 ) {
case 0x3 :
if ( V_164 == V_167 || V_164 == V_168 ||
V_164 == V_169 || V_164 == V_170 )
return V_5 ;
V_164 = V_171 ;
break;
case 0x4 :
if ( V_164 == V_172 || V_164 == V_173 )
return V_5 ;
V_164 = V_174 ;
break;
case 0x5 :
if ( V_164 == V_175 || V_164 == V_176 ||
V_164 == V_177 || V_164 == V_178 )
return V_5 ;
V_164 = V_175 ;
break;
case 0x6 :
if ( V_164 == V_174 || V_164 == V_179 )
return V_5 ;
V_164 = V_174 ;
break;
case 0x7 :
if ( V_164 == V_171 || V_164 == V_180 ||
V_164 == V_181 || V_164 == V_182 )
return V_5 ;
V_164 = V_171 ;
break;
case 0x8 :
if ( V_164 == V_183 || V_164 == V_184 )
return V_5 ;
V_164 = V_183 ;
break;
default:
F_19 ( V_2 -> V_59 ,
L_5 ,
V_166 ) ;
return NULL ;
}
F_19 ( V_2 -> V_59 ,
L_6 ,
V_165 [ V_164 ] . V_185 ) ;
return & V_165 [ V_164 ] ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
const struct V_4 * V_5 ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
unsigned int V_66 = V_153 -> V_155 [ 1 ] ;
int V_186 ;
V_18 = F_64 ( V_2 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_187 ;
V_186 = F_65 ( V_2 , V_153 -> V_155 [ 0 ] , V_188 ) ;
if ( V_186 )
return V_186 ;
V_5 = F_62 ( V_2 ) ;
if ( ! V_5 ) {
F_19 ( V_2 -> V_59 , L_7 ) ;
return - V_189 ;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_190 = V_5 -> V_185 ;
if ( V_5 -> V_191 == 2 ) {
unsigned long V_192 = V_2 -> V_12 + V_193 ;
V_186 = F_66 ( V_2 , V_192 , V_188 ) ;
if ( V_186 )
return V_186 ;
V_18 -> V_192 = V_192 ;
}
if ( V_66 == 3 || V_66 == 5 || V_66 == 7 || V_66 == 10 || V_66 == 11 ||
V_66 == 15 ) {
V_186 = F_67 ( V_66 , F_25 , 0 ,
V_2 -> V_190 , V_2 ) ;
if ( V_186 == 0 ) {
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
if ( V_2 -> V_66 & V_153 -> V_155 [ 2 ] )
F_58 ( V_2 , V_153 ) ;
V_18 -> V_23 = F_68 ( V_21 , sizeof( T_1 ) , V_194 ) ;
if ( ! V_18 -> V_23 )
return - V_187 ;
V_2 -> V_96 = F_69 ( V_2 -> V_12 + V_195 ,
V_196 , V_197 , 0 ) ;
if ( ! V_2 -> V_96 )
return - V_187 ;
V_186 = F_70 ( V_2 , 4 ) ;
if ( V_186 )
return V_186 ;
V_16 = & V_2 -> V_198 [ 0 ] ;
V_16 -> type = V_199 ;
V_16 -> V_200 = V_201 | V_202 | V_203 ;
if ( V_5 -> V_204 )
V_16 -> V_200 |= V_205 ;
V_16 -> V_206 = V_5 -> V_207 ;
V_16 -> V_208 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_209 = V_5 -> V_210 ;
V_16 -> V_211 = F_52 ;
if ( V_2 -> V_66 ) {
V_2 -> V_52 = V_16 ;
V_16 -> V_200 |= V_212 ;
V_16 -> V_213 = V_16 -> V_206 ;
V_16 -> V_214 = F_48 ;
V_16 -> V_215 = F_32 ;
V_16 -> V_216 = F_21 ;
V_16 -> V_217 = F_17 ;
}
V_16 = & V_2 -> V_198 [ 1 ] ;
if ( V_5 -> V_191 == 1 ) {
V_16 -> type = V_218 ;
V_16 -> V_200 = V_219 ;
V_16 -> V_206 = V_5 -> V_146 ;
V_16 -> V_208 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_209 = & V_220 ;
V_16 -> V_221 = F_53 ;
} else {
V_16 -> type = V_222 ;
}
V_16 = & V_2 -> V_198 [ 2 ] ;
V_16 -> type = V_223 ;
V_16 -> V_200 = V_201 ;
V_16 -> V_206 = 4 ;
V_16 -> V_208 = 1 ;
V_16 -> V_209 = & V_224 ;
V_16 -> V_225 = F_55 ;
V_16 = & V_2 -> V_198 [ 3 ] ;
V_16 -> type = V_226 ;
V_16 -> V_200 = V_219 ;
V_16 -> V_206 = V_5 -> V_227 ;
V_16 -> V_208 = 1 ;
V_16 -> V_209 = & V_224 ;
V_16 -> V_225 = F_56 ;
F_17 ( V_2 , V_2 -> V_52 ) ;
F_16 ( 0 , V_2 -> V_12 + V_150 ) ;
if ( V_5 -> V_191 == 1 ) {
F_16 ( F_54 ( V_5 -> V_146 - 1 ) ,
V_2 -> V_12 + V_55 ) ;
F_47 ( V_18 -> V_148 , V_2 -> V_12 + V_149 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
F_60 ( V_2 ) ;
if ( V_18 ) {
F_72 ( V_18 -> V_23 ) ;
if ( V_18 -> V_192 )
F_73 ( V_18 -> V_192 , V_188 ) ;
}
F_74 ( V_2 ) ;
}
