static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_5 , unsigned int V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned short * V_11 = V_5 ;
unsigned int V_12 = F_2 ( V_4 , V_6 ) ;
unsigned int V_13 ;
if ( V_9 -> V_14 )
return;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_11 [ V_13 ] = F_3 ( V_4 , V_11 [ V_13 ] ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_15 = F_5 ( V_4 , V_16 / 2 ) ;
F_6 ( V_2 -> V_17 + V_18 , V_9 -> V_19 , V_15 ) ;
F_7 ( V_4 , V_9 -> V_19 , V_15 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_22 -> V_21 ;
unsigned short V_23 ;
while ( F_9 ( V_2 -> V_17 + V_24 ) & V_25 ) {
V_23 = F_10 ( V_2 -> V_17 + V_18 ) ;
F_7 ( V_4 , & V_23 , 1 ) ;
if ( V_21 -> V_26 == V_27 &&
V_4 -> V_22 -> V_28 >= V_21 -> V_29 )
break;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_30 * V_31 )
{
unsigned int V_32 = F_12 ( V_31 -> V_33 ) ;
unsigned int V_34 = V_31 -> V_35 - V_32 ;
unsigned int V_15 ;
V_15 = F_2 ( V_4 , V_34 ) ;
V_15 = F_5 ( V_4 , V_15 ) ;
F_7 ( V_4 , V_31 -> V_36 , V_15 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_37 * V_38 = V_9 -> V_38 ;
struct V_30 * V_31 = & V_38 -> V_31 [ V_38 -> V_39 ] ;
const int V_40 = V_9 -> V_41 & V_42 ;
F_11 ( V_2 , V_4 , V_31 ) ;
if ( V_40 ) {
V_38 -> V_39 = 1 - V_38 -> V_39 ;
V_31 = & V_38 -> V_31 [ V_38 -> V_39 ] ;
F_11 ( V_2 , V_4 , V_31 ) ;
}
F_8 ( V_2 , V_4 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_43 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_37 * V_38 = V_9 -> V_38 ;
struct V_30 * V_31 = & V_38 -> V_31 [ V_38 -> V_39 ] ;
const int V_40 = V_9 -> V_41 & V_42 ;
F_11 ( V_2 , V_4 , V_31 ) ;
F_15 ( V_31 ) ;
if ( V_43 & V_44 ) {
F_16 ( V_45 & ~ V_44 , V_2 -> V_17 + V_24 ) ;
if ( V_40 )
V_38 -> V_39 = 1 - V_38 -> V_39 ;
}
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_37 * V_38 = V_9 -> V_38 ;
struct V_30 * V_31 ;
int V_13 ;
F_16 ( 0x0 , V_2 -> V_17 + V_24 ) ;
F_16 ( 0x0 , V_2 -> V_17 + V_46 ) ;
F_16 ( 0x0 , V_2 -> V_17 + V_47 ) ;
if ( V_38 ) {
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
V_31 = & V_38 -> V_31 [ V_13 ] ;
if ( V_31 -> V_33 )
F_12 ( V_31 -> V_33 ) ;
}
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = V_2 -> V_48 ;
struct V_49 * V_22 = V_4 -> V_22 ;
struct V_20 * V_21 = & V_22 -> V_21 ;
unsigned int V_43 = F_9 ( V_2 -> V_17 + V_24 ) ;
F_16 ( V_50 , V_2 -> V_17 + V_51 ) ;
if ( V_9 -> V_41 & V_52 )
F_14 ( V_2 , V_4 , V_43 ) ;
else if ( V_43 & V_53 )
F_4 ( V_2 , V_4 ) ;
else if ( V_43 & V_25 )
F_8 ( V_2 , V_4 ) ;
if ( V_43 & V_54 ) {
F_16 ( V_45 & ~ V_54 , V_2 -> V_17 + V_24 ) ;
F_19 ( V_2 -> V_55 , L_1 ) ;
V_22 -> V_56 |= V_57 ;
F_20 ( V_2 , V_4 ) ;
return;
}
if ( V_43 & V_58 ) {
F_16 ( V_45 & ~ V_58 , V_2 -> V_17 + V_24 ) ;
if ( V_9 -> V_41 & V_52 )
F_13 ( V_2 , V_4 ) ;
else
F_8 ( V_2 , V_4 ) ;
V_22 -> V_56 |= V_59 ;
} else if ( V_21 -> V_26 == V_27 &&
V_22 -> V_28 >= V_21 -> V_29 ) {
V_22 -> V_56 |= V_59 ;
}
F_20 ( V_2 , V_4 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_60 ;
F_22 ( & V_2 -> V_61 , V_60 ) ;
F_18 ( V_2 ) ;
F_23 ( & V_2 -> V_61 , V_60 ) ;
return F_24 ( V_4 ) ;
}
static T_1 F_25 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
unsigned int V_43 ;
if ( ! V_2 -> V_64 ) {
F_19 ( V_2 -> V_55 , L_2 ) ;
return V_65 ;
}
F_26 ( & V_2 -> V_61 ) ;
V_43 = F_9 ( V_2 -> V_17 + V_24 ) ;
if ( ! ( V_43 & INT ) ) {
F_27 ( & V_2 -> V_61 ) ;
return V_66 ;
}
F_16 ( V_45 & ~ INT , V_2 -> V_17 + V_24 ) ;
F_18 ( V_2 ) ;
F_27 ( & V_2 -> V_61 ) ;
return V_65 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
unsigned int V_67 = V_21 -> V_68 ;
F_29 ( V_2 -> V_69 , & V_67 , V_21 -> V_60 ) ;
return F_30 ( & V_21 -> V_68 , V_67 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
unsigned int V_67 = V_21 -> V_68 ;
int V_70 = 0 ;
V_70 |= F_32 ( & V_67 , 64000 ) ;
switch ( V_21 -> V_60 & V_71 ) {
case V_72 :
default:
V_67 = F_33 ( V_67 , 1000 ) ;
break;
case V_73 :
V_67 = V_67 / 1000 ;
break;
case V_74 :
V_67 = F_34 ( V_67 , 1000 ) ;
break;
}
V_70 |= F_30 ( & V_21 -> V_68 , V_67 * 1000 ) ;
if ( V_21 -> V_75 == V_76 ) {
V_67 = V_21 -> V_68 * V_21 -> V_77 ;
V_70 |= F_35 ( & V_21 -> V_78 , V_67 ) ;
V_67 = V_21 -> V_78 ;
F_29 ( V_2 -> V_69 , & V_67 , V_21 -> V_60 ) ;
V_70 |= F_30 ( & V_21 -> V_78 , V_67 ) ;
}
return V_70 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_20 * V_21 )
{
unsigned int V_79 = F_37 ( V_21 -> V_80 [ 0 ] ) ;
bool V_81 = F_38 ( V_4 , V_79 ) ;
int V_13 ;
for ( V_13 = 1 ; V_13 < V_21 -> V_77 ; V_13 ++ ) {
V_79 = F_37 ( V_21 -> V_80 [ V_13 ] ) ;
if ( V_81 != F_38 ( V_4 , V_79 ) ) {
F_39 ( V_2 -> V_55 ,
L_3 ) ;
return - V_82 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_20 * V_21 )
{
const struct V_83 * V_84 = V_2 -> V_85 ;
int V_70 = 0 ;
V_70 |= F_41 ( & V_21 -> V_86 , V_87 | V_88 ) ;
V_70 |= F_41 ( & V_21 -> V_75 ,
V_89 | V_76 | V_88 ) ;
V_70 |= F_41 ( & V_21 -> V_90 ,
V_76 | V_88 ) ;
V_70 |= F_41 ( & V_21 -> V_91 , V_27 ) ;
V_70 |= F_41 ( & V_21 -> V_26 ,
V_27 | V_88 | V_92 ) ;
if ( V_70 )
return 1 ;
V_70 |= F_42 ( V_21 -> V_86 ) ;
V_70 |= F_42 ( V_21 -> V_75 ) ;
V_70 |= F_42 ( V_21 -> V_90 ) ;
V_70 |= F_42 ( V_21 -> V_26 ) ;
if ( V_21 -> V_75 != V_89 &&
V_21 -> V_90 != V_76 )
V_70 |= - V_82 ;
if ( V_21 -> V_86 == V_88 && V_21 -> V_26 == V_88 )
V_70 |= F_30 ( & V_21 -> V_93 ,
V_21 -> V_29 ) ;
if ( V_70 )
return 2 ;
if ( V_21 -> V_93 == V_87 )
V_70 |= F_30 ( & V_21 -> V_93 , 0 ) ;
if ( V_21 -> V_90 == V_76 ) {
V_70 |= F_35 ( & V_21 -> V_68 ,
V_84 -> V_94 ) ;
}
V_70 |= F_35 ( & V_21 -> V_77 , 1 ) ;
V_70 |= F_30 ( & V_21 -> V_95 ,
V_21 -> V_77 ) ;
switch ( V_21 -> V_26 ) {
case V_27 :
V_70 |= F_35 ( & V_21 -> V_29 , 1 ) ;
break;
case V_92 :
V_70 |= F_30 ( & V_21 -> V_29 , 0 ) ;
break;
default:
break;
}
if ( V_70 )
return 3 ;
if ( V_21 -> V_90 == V_76 ) {
if ( V_21 -> V_75 == V_89 )
V_70 |= F_28 ( V_2 , V_21 ) ;
else
V_70 |= F_31 ( V_2 , V_21 ) ;
}
if ( V_70 )
return 4 ;
if ( V_21 -> V_80 && V_21 -> V_77 > 0 )
V_70 |= F_36 ( V_2 , V_4 , V_21 ) ;
if ( V_70 )
return 5 ;
return 0 ;
}
static unsigned char F_43 ( struct V_3 * V_4 ,
unsigned int V_96 )
{
unsigned int V_79 = F_37 ( V_96 ) ;
unsigned int V_97 = F_44 ( V_96 ) ;
unsigned char V_98 ;
V_98 = V_99 ;
if ( V_97 != V_100 )
V_98 |= V_101 ;
if ( V_97 == V_102 )
V_98 |= V_103 ;
if ( F_38 ( V_4 , V_79 ) )
V_98 |= V_104 ;
return V_98 ;
}
static unsigned int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_105 ,
unsigned int V_106 )
{
struct V_20 * V_21 = & V_4 -> V_22 -> V_21 ;
unsigned int V_107 = F_2 ( V_4 , V_105 ) ;
unsigned int V_108 ;
V_108 = V_107 ;
switch ( V_21 -> V_75 ) {
case V_89 :
if ( V_21 -> V_90 == V_76 )
V_108 = V_106 / V_21 -> V_68 ;
break;
case V_76 :
V_108 = V_106 / ( V_21 -> V_78 * V_21 -> V_77 ) ;
break;
}
V_108 = F_5 ( V_4 , V_108 ) ;
if ( V_108 > V_107 )
V_108 = V_107 ;
if ( V_108 < 1 )
V_108 = 1 ;
return F_46 ( V_4 , V_108 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_37 * V_38 = V_9 -> V_38 ;
struct V_30 * V_31 ;
unsigned int V_109 ;
if ( ( V_9 -> V_41 & V_52 ) == 0 )
return;
V_38 -> V_39 = 0 ;
V_31 = & V_38 -> V_31 [ 0 ] ;
V_109 = F_45 ( V_2 , V_4 , V_31 -> V_110 , 300000000 ) ;
V_31 -> V_35 = V_109 ;
F_15 ( V_31 ) ;
if ( V_9 -> V_41 & V_42 ) {
V_31 = & V_38 -> V_31 [ 1 ] ;
V_31 -> V_35 = V_109 ;
F_15 ( V_31 ) ;
}
}
static void F_48 ( struct V_1 * V_2 ,
unsigned int * V_80 , unsigned int V_111 )
{
unsigned long V_60 ;
unsigned int V_13 ;
F_22 ( & V_2 -> V_61 , V_60 ) ;
F_16 ( V_112 , V_2 -> V_17 + V_51 ) ;
F_16 ( V_111 - 1 , V_2 -> V_17 + V_113 ) ;
for ( V_13 = 0 ; V_13 < V_111 ; V_13 ++ ) {
unsigned int V_33 = F_49 ( V_80 [ V_13 ] ) ;
unsigned int V_79 = F_37 ( V_80 [ V_13 ] ) ;
unsigned short V_114 ;
V_114 = V_33 | ( ( V_79 & 0x3 ) << 8 ) ;
F_50 ( V_114 , V_2 -> V_17 + V_115 ) ;
}
F_16 ( V_111 - 1 , V_2 -> V_17 + V_113 ) ;
F_23 ( & V_2 -> V_61 , V_60 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_116 , V_117 ;
struct V_49 * V_22 = V_4 -> V_22 ;
const struct V_20 * V_21 = & V_22 -> V_21 ;
unsigned int V_118 = F_37 ( V_21 -> V_80 [ 0 ] ) ;
if ( V_21 -> V_60 & ( V_119 | V_120 ) )
V_9 -> V_41 &= ~ V_52 ;
else
V_9 -> V_41 |= V_9 -> V_121 ;
if ( V_21 -> V_60 & V_119 ) {
V_9 -> V_41 &= ~ V_122 ;
} else {
V_9 -> V_41 |= V_122 ;
}
F_17 ( V_2 , V_4 ) ;
V_9 -> V_14 = F_38 ( V_4 , V_118 ) ;
V_116 = V_123 ;
if ( V_21 -> V_26 == V_88 )
V_116 |= V_124 ;
if ( V_21 -> V_86 == V_88 )
V_116 |= V_125 | V_126 ;
else
V_116 |= V_127 ;
if ( V_116 & ( V_124 | V_125 ) ) {
if ( ( V_21 -> V_93 & V_128 ) || ( V_21 -> V_29 & V_128 ) )
V_116 |= V_129 ;
}
V_117 = F_43 ( V_4 , V_21 -> V_80 [ 0 ] ) ;
if ( V_21 -> V_75 == V_89 ) {
if ( V_21 -> V_90 == V_76 ) {
V_117 |= V_130 ;
} else {
V_117 |= V_131 ;
}
} else if ( V_21 -> V_75 == V_76 ) {
V_117 |= V_132 | V_130 ;
} else {
V_117 |= V_132 | V_131 ;
}
F_48 ( V_2 , V_21 -> V_80 , V_21 -> V_77 ) ;
if ( ( V_21 -> V_75 == V_89 ||
V_21 -> V_75 == V_76 ) &&
V_21 -> V_90 == V_76 ) {
F_52 ( V_2 -> V_69 ) ;
F_53 ( V_2 -> V_69 , 1 , 2 , true ) ;
}
if ( V_21 -> V_26 == V_88 )
F_54 ( V_2 -> V_69 , 0 , 1 , V_133 | V_134 ) ;
F_47 ( V_2 , V_4 ) ;
F_16 ( V_117 , V_2 -> V_17 + V_135 ) ;
if ( V_117 & V_132 ) {
F_16 ( V_21 -> V_68 / 1000 - 1 ,
V_2 -> V_17 + V_136 ) ;
F_16 ( V_21 -> V_77 - 1 , V_2 -> V_17 + V_137 ) ;
}
F_16 ( V_9 -> V_41 , V_2 -> V_17 + V_46 ) ;
F_16 ( V_116 , V_2 -> V_17 + V_47 ) ;
F_16 ( V_138 , V_2 -> V_17 + V_24 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_139 * V_140 ,
unsigned long V_141 )
{
unsigned char V_43 ;
V_43 = F_9 ( V_2 -> V_17 + V_24 ) ;
if ( V_43 & V_25 )
return 0 ;
return - V_142 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_139 * V_140 ,
unsigned int * V_5 )
{
unsigned int V_79 = F_37 ( V_140 -> V_96 ) ;
bool V_143 = F_38 ( V_4 , V_79 ) ;
int V_144 = 0 ;
int V_145 ;
unsigned short V_23 ;
unsigned long V_60 ;
F_16 ( F_43 ( V_4 , V_140 -> V_96 ) ,
V_2 -> V_17 + V_135 ) ;
F_16 ( V_138 , V_2 -> V_17 + V_24 ) ;
F_16 ( 0x0 , V_2 -> V_17 + V_47 ) ;
F_16 ( V_123 , V_2 -> V_17 + V_47 ) ;
F_48 ( V_2 , & V_140 -> V_96 , 1 ) ;
F_22 ( & V_2 -> V_61 , V_60 ) ;
F_16 ( V_50 , V_2 -> V_17 + V_51 ) ;
for ( V_145 = 0 ; V_145 < V_140 -> V_145 ; V_145 ++ ) {
F_16 ( 0 , V_2 -> V_17 + V_18 ) ;
V_144 = F_57 ( V_2 , V_4 , V_140 , F_55 , 0 ) ;
if ( V_144 )
break;
V_23 = F_10 ( V_2 -> V_17 + V_18 ) ;
if ( ! V_143 )
V_23 = F_3 ( V_4 , V_23 ) ;
V_5 [ V_145 ] = V_23 ;
}
F_23 ( & V_2 -> V_61 , V_60 ) ;
return V_144 ? V_144 : V_140 -> V_145 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_139 * V_140 ,
unsigned int * V_5 )
{
unsigned int V_33 = F_49 ( V_140 -> V_96 ) ;
unsigned int V_146 = V_4 -> V_147 - 1 ;
unsigned long V_60 ;
int V_13 ;
F_22 ( & V_2 -> V_61 , V_60 ) ;
for ( V_13 = 0 ; V_13 < V_140 -> V_145 ; V_13 ++ ) {
unsigned int V_114 = V_5 [ V_13 ] ;
V_4 -> V_148 [ V_33 ] = V_114 ;
V_114 = F_3 ( V_4 , V_114 ) ;
F_16 ( F_59 ( V_33 ) , V_2 -> V_17 + V_51 ) ;
F_50 ( V_114 , V_2 -> V_17 + V_149 ) ;
if ( V_33 != V_146 ) {
V_114 = F_3 ( V_4 , V_4 -> V_148 [ V_146 ] ) ;
F_16 ( F_59 ( V_146 ) , V_2 -> V_17 + V_51 ) ;
F_50 ( V_114 , V_2 -> V_17 + V_149 ) ;
}
}
F_23 ( & V_2 -> V_61 , V_60 ) ;
return V_140 -> V_145 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_139 * V_140 ,
unsigned int * V_5 )
{
V_5 [ 1 ] = F_9 ( V_2 -> V_17 + V_150 ) & 0xf ;
V_5 [ 0 ] = 0 ;
return V_140 -> V_145 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_139 * V_140 ,
unsigned int * V_5 )
{
if ( F_62 ( V_4 , V_5 ) )
F_16 ( V_4 -> V_151 , V_2 -> V_17 + V_150 ) ;
V_5 [ 1 ] = V_4 -> V_151 ;
return V_140 -> V_145 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int * V_154 ;
V_154 = & V_153 -> V_155 [ 2 ] ;
switch ( ( V_154 [ 0 ] & 0x7 ) | ( V_154 [ 1 ] << 4 ) ) {
case 0x5 :
V_9 -> V_121 = V_156 ;
break;
case 0x6 :
V_9 -> V_121 = V_157 ;
break;
case 0x7 :
V_9 -> V_121 = V_158 ;
break;
case 0x65 :
V_9 -> V_121 = V_159 ;
break;
case 0x76 :
V_9 -> V_121 = V_160 ;
break;
case 0x57 :
V_9 -> V_121 = V_161 ;
break;
default:
return;
}
V_9 -> V_38 = F_64 ( V_2 , V_154 [ 1 ] ? 2 : 1 ,
V_154 [ 0 ] , V_154 [ 1 ] ,
V_162 , V_163 ) ;
if ( ! V_9 -> V_38 )
V_9 -> V_121 = 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 )
F_66 ( V_9 -> V_38 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
const struct V_83 * V_84 = V_2 -> V_85 ;
unsigned char V_164 ;
V_164 = ( F_9 ( V_2 -> V_17 + V_150 ) >> 4 ) & 0xf ;
if ( V_84 ) {
if ( V_84 -> V_164 == V_164 )
return 0 ;
F_19 ( V_2 -> V_55 ,
L_4 ,
V_164 , V_84 -> V_164 ) ;
return - V_165 ;
}
switch ( V_164 ) {
case V_166 :
V_84 = & V_167 [ V_168 ] ;
break;
case V_169 :
V_84 = & V_167 [ V_170 ] ;
break;
case V_171 :
V_84 = & V_167 [ V_172 ] ;
break;
case V_173 :
V_84 = & V_167 [ V_174 ] ;
break;
case V_175 :
V_84 = & V_167 [ V_176 ] ;
break;
case V_177 :
V_84 = & V_167 [ V_178 ] ;
break;
default:
F_19 ( V_2 -> V_55 , L_5 , V_164 ) ;
return - V_165 ;
}
V_2 -> V_85 = V_84 ;
V_2 -> V_179 = V_84 -> V_180 ;
F_68 ( V_2 -> V_55 ,
L_6 ,
V_164 , V_84 -> V_180 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
const struct V_83 * V_84 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned int V_62 = V_153 -> V_155 [ 1 ] ;
bool V_181 ;
int V_144 ;
int V_13 ;
V_9 = F_70 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_182 ;
V_144 = F_71 ( V_2 , V_153 -> V_155 [ 0 ] , V_183 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_67 ( V_2 ) ;
if ( V_144 )
return V_144 ;
V_84 = V_2 -> V_85 ;
V_181 = V_84 -> V_164 == V_173 || V_84 -> V_164 == V_169 ;
if ( V_84 -> V_164 == V_171 ) {
unsigned long V_184 = V_2 -> V_17 + V_185 ;
V_144 = F_72 ( V_2 , V_184 , V_183 ) ;
if ( V_144 )
return V_144 ;
V_9 -> V_184 = V_184 ;
}
if ( V_62 == 3 || V_62 == 5 || V_62 == 7 || V_62 == 10 || V_62 == 11 ||
V_62 == 15 ) {
V_144 = F_73 ( V_62 , F_25 , 0 ,
V_2 -> V_179 , V_2 ) ;
if ( V_144 == 0 ) {
V_2 -> V_62 = V_62 ;
switch ( V_62 ) {
case 3 :
V_9 -> V_41 |= 0x8 ;
break;
case 5 :
V_9 -> V_41 |= 0x10 ;
break;
case 7 :
V_9 -> V_41 |= 0x18 ;
break;
case 10 :
V_9 -> V_41 |= 0x28 ;
break;
case 11 :
V_9 -> V_41 |= 0x30 ;
break;
case 15 :
V_9 -> V_41 |= 0x38 ;
break;
}
}
}
if ( V_2 -> V_62 & V_153 -> V_155 [ 2 ] )
F_63 ( V_2 , V_153 ) ;
V_9 -> V_19 = F_74 ( V_16 ,
sizeof( * V_9 -> V_19 ) ,
V_186 ) ;
if ( ! V_9 -> V_19 )
return - V_182 ;
V_2 -> V_69 = F_75 ( V_2 -> V_17 + V_187 ,
V_188 , V_189 , 0 ) ;
if ( ! V_2 -> V_69 )
return - V_182 ;
V_144 = F_76 ( V_2 , 4 ) ;
if ( V_144 )
return V_144 ;
V_4 = & V_2 -> V_190 [ 0 ] ;
V_4 -> type = V_191 ;
V_4 -> V_192 = V_193 | V_194 | V_195 ;
if ( V_84 -> V_164 != V_177 )
V_4 -> V_192 |= V_196 ;
V_4 -> V_147 = ( V_84 -> V_164 == V_177 ) ? 64 : 256 ;
V_4 -> V_197 = V_181 ? 0xffff : 0x0fff ;
V_4 -> V_198 = V_84 -> V_199 ? & V_200
: & V_201 ;
V_4 -> V_202 = F_56 ;
if ( V_2 -> V_62 ) {
V_2 -> V_48 = V_4 ;
V_4 -> V_192 |= V_203 ;
V_4 -> V_204 = V_4 -> V_147 ;
V_4 -> V_205 = F_51 ;
V_4 -> V_206 = F_40 ;
V_4 -> V_207 = F_21 ;
V_4 -> V_208 = F_17 ;
V_4 -> V_209 = F_1 ;
}
V_4 = & V_2 -> V_190 [ 1 ] ;
if ( V_84 -> V_164 == V_166 || V_84 -> V_164 == V_169 ) {
V_4 -> type = V_210 ;
V_4 -> V_192 = V_211 ;
V_4 -> V_147 = ( V_84 -> V_164 == V_166 ) ? 4 : 2 ;
V_4 -> V_197 = V_181 ? 0xffff : 0x0fff ;
V_4 -> V_198 = & V_212 ;
V_4 -> V_213 = F_58 ;
V_144 = F_77 ( V_4 ) ;
if ( V_144 )
return V_144 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_147 ; V_13 ++ ) {
F_16 ( F_59 ( V_13 ) , V_2 -> V_17 + V_51 ) ;
F_50 ( 0 , V_2 -> V_17 + V_149 ) ;
}
} else if ( V_84 -> V_164 == V_171 ) {
V_4 -> type = V_214 ;
} else {
V_4 -> type = V_214 ;
}
V_4 = & V_2 -> V_190 [ 2 ] ;
V_4 -> type = V_215 ;
V_4 -> V_192 = V_193 ;
V_4 -> V_147 = 4 ;
V_4 -> V_197 = 1 ;
V_4 -> V_198 = & V_216 ;
V_4 -> V_217 = F_60 ;
V_4 = & V_2 -> V_190 [ 3 ] ;
V_4 -> type = V_218 ;
V_4 -> V_192 = V_211 ;
V_4 -> V_147 = ( V_84 -> V_164 == V_177 ) ? 8 : 4 ;
V_4 -> V_197 = 1 ;
V_4 -> V_198 = & V_216 ;
V_4 -> V_217 = F_61 ;
F_17 ( V_2 , V_2 -> V_48 ) ;
F_16 ( 0 , V_2 -> V_17 + V_150 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_65 ( V_2 ) ;
if ( V_9 ) {
F_79 ( V_9 -> V_19 ) ;
if ( V_9 -> V_184 )
F_80 ( V_9 -> V_184 , V_183 ) ;
}
F_81 ( V_2 ) ;
}
