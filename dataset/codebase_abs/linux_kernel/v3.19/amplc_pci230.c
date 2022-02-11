static unsigned short F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned short V_9 ;
V_9 = F_2 ( V_7 -> V_10 + V_11 ) ;
if ( V_7 -> V_12 )
V_9 ^= 0x8000 ;
V_9 >>= ( 16 - V_4 -> V_13 ) ;
return V_9 ;
}
static unsigned short F_3 ( struct V_1 * V_2 ,
unsigned short V_14 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
V_14 <<= ( 16 - V_4 -> V_15 ) ;
if ( V_7 -> V_16 )
V_14 ^= 0x8000 ;
return V_14 ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned short V_14 , unsigned int V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_5 ( F_3 ( V_2 , V_14 ) ,
V_7 -> V_10 + ( ( V_17 == 0 ) ? V_18 : V_19 ) ) ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned short V_14 , unsigned int V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_5 ( F_3 ( V_2 , V_14 ) ,
V_7 -> V_10 + V_20 ) ;
}
static bool F_7 ( struct V_1 * V_2 ,
unsigned char V_21 , unsigned int V_22 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_23 ;
unsigned long V_24 ;
F_8 ( & V_7 -> V_25 , V_24 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( V_23 == V_22 )
continue;
if ( V_7 -> V_27 [ V_23 ] & V_21 ) {
F_9 ( & V_7 -> V_25 ,
V_24 ) ;
return false ;
}
}
V_7 -> V_27 [ V_22 ] |= V_21 ;
F_9 ( & V_7 -> V_25 , V_24 ) ;
return true ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned char V_21 , unsigned int V_22 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_24 ;
F_8 ( & V_7 -> V_25 , V_24 ) ;
V_7 -> V_27 [ V_22 ] &= ~ V_21 ;
F_9 ( & V_7 -> V_25 , V_24 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_22 )
{
F_10 ( V_2 , ( unsigned char ) ~ 0 , V_22 ) ;
}
static unsigned int F_12 ( T_1 V_28 , unsigned int V_29 ,
unsigned int V_30 )
{
T_1 div ;
unsigned int V_31 ;
div = V_28 ;
V_31 = F_13 ( div , V_29 ) ;
switch ( V_30 & V_32 ) {
default:
case V_33 :
div += ( V_31 + ( V_29 / 2 ) ) / V_29 ;
break;
case V_34 :
break;
case V_35 :
div += ( V_31 + V_29 - 1 ) / V_29 ;
break;
}
return div > V_36 ? V_36 : ( unsigned int ) div ;
}
static unsigned int F_14 ( T_1 V_28 , unsigned int * V_37 ,
unsigned int V_30 )
{
unsigned int V_38 , V_39 ;
for ( V_38 = V_40 ; ; V_38 ++ ) {
V_39 = F_12 ( V_28 , V_41 [ V_38 ] , V_30 ) ;
if ( V_39 <= 65536 || V_38 == V_42 )
break;
}
* V_37 = V_39 ;
return V_38 ;
}
static void F_15 ( unsigned int * V_28 , unsigned int V_30 )
{
unsigned int V_37 ;
unsigned int V_38 ;
V_38 = F_14 ( * V_28 , & V_37 , V_30 ) ;
* V_28 = V_37 * V_41 [ V_38 ] ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 , T_1 V_28 ,
unsigned int V_30 )
{
unsigned int V_38 ;
unsigned int V_37 ;
F_17 ( V_2 -> V_45 + V_46 , 0 , V_43 , V_44 ) ;
V_38 = F_14 ( V_28 , & V_37 , V_30 ) ;
F_18 ( F_19 ( V_43 , V_38 ) , V_2 -> V_45 + V_47 ) ;
if ( V_37 >= 65536 )
V_37 = 0 ;
F_20 ( V_2 -> V_45 + V_46 , 0 , V_43 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_43 )
{
F_17 ( V_2 -> V_45 + V_46 , 0 , V_43 , V_48 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
unsigned long V_53 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_54 ;
V_54 = F_2 ( V_7 -> V_10 + V_55 ) ;
if ( ( V_54 & V_56 ) == 0 )
return 0 ;
return - V_57 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_51 * V_52 , unsigned int * V_9 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_58 ;
unsigned int V_17 , V_59 , V_60 ;
unsigned int V_61 ;
unsigned short V_62 , V_63 ;
int V_64 ;
V_17 = F_24 ( V_52 -> V_65 ) ;
V_59 = F_25 ( V_52 -> V_65 ) ;
V_60 = F_26 ( V_52 -> V_65 ) ;
if ( V_60 == V_66 ) {
if ( V_17 >= V_50 -> V_67 / 2 ) {
F_27 ( V_2 -> V_68 ,
L_1 ,
V_69 , ( V_50 -> V_67 / 2 ) - 1 ) ;
return - V_70 ;
}
}
V_62 = V_71 | V_72 ;
F_17 ( V_2 -> V_45 + V_46 , 0 , 2 , V_73 ) ;
V_7 -> V_12 = F_28 ( V_50 , V_59 ) ;
if ( V_60 == V_66 ) {
V_61 = V_17 * 2 ;
if ( V_7 -> V_74 == 0 ) {
V_63 = 3 << V_61 ;
} else {
V_63 = 1 << V_61 ;
}
V_62 |= V_75 ;
} else {
V_63 = 1 << V_17 ;
V_61 = V_17 & ~ 1 ;
V_62 |= V_76 ;
}
V_7 -> V_77 = ( V_7 -> V_77 & ~ ( 3 << V_61 ) ) |
( V_78 [ V_59 ] << V_61 ) ;
if ( V_7 -> V_12 )
V_62 |= V_79 ;
else
V_62 |= V_80 ;
F_5 ( V_63 , V_7 -> V_10 + V_81 ) ;
F_5 ( V_7 -> V_77 , V_7 -> V_10 + V_82 ) ;
V_7 -> V_62 = V_62 ;
F_5 ( V_62 | V_83 , V_7 -> V_10 + V_55 ) ;
for ( V_58 = 0 ; V_58 < V_52 -> V_58 ; V_58 ++ ) {
F_17 ( V_2 -> V_45 + V_46 , 0 ,
2 , V_73 ) ;
F_17 ( V_2 -> V_45 + V_46 , 0 ,
2 , V_48 ) ;
V_64 = F_29 ( V_2 , V_50 , V_52 , F_22 , 0 ) ;
if ( V_64 )
return V_64 ;
V_9 [ V_58 ] = F_1 ( V_2 ) ;
}
return V_58 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
unsigned int * V_9 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_17 = F_24 ( V_52 -> V_65 ) ;
unsigned int V_59 = F_25 ( V_52 -> V_65 ) ;
unsigned int V_84 = V_50 -> V_85 [ V_17 ] ;
int V_86 ;
V_7 -> V_16 = F_28 ( V_50 , V_59 ) ;
F_5 ( V_59 , V_7 -> V_10 + V_87 ) ;
for ( V_86 = 0 ; V_86 < V_52 -> V_58 ; V_86 ++ ) {
V_84 = V_9 [ V_86 ] ;
F_4 ( V_2 , V_84 , V_17 ) ;
}
V_50 -> V_85 [ V_17 ] = V_84 ;
return V_52 -> V_58 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_88 * V_89 )
{
unsigned int V_90 = F_24 ( V_89 -> V_91 [ 0 ] ) ;
unsigned int V_92 = F_25 ( V_89 -> V_91 [ 0 ] ) ;
int V_86 ;
for ( V_86 = 1 ; V_86 < V_89 -> V_93 ; V_86 ++ ) {
unsigned int V_17 = F_24 ( V_89 -> V_91 [ V_86 ] ) ;
unsigned int V_59 = F_25 ( V_89 -> V_91 [ V_86 ] ) ;
if ( V_17 < V_90 ) {
F_27 ( V_2 -> V_68 ,
L_2 ,
V_69 ) ;
return - V_70 ;
}
if ( V_59 != V_92 ) {
F_27 ( V_2 -> V_68 ,
L_3 ,
V_69 ) ;
return - V_70 ;
}
V_90 = V_17 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_49 * V_50 , struct V_88 * V_89 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_94 = 0 ;
unsigned int V_95 ;
V_94 |= F_33 ( & V_89 -> V_96 , V_97 ) ;
V_95 = V_98 | V_97 ;
if ( V_4 -> V_99 > 0 && V_7 -> V_74 >= 2 ) {
V_95 |= V_100 ;
}
V_94 |= F_33 ( & V_89 -> V_101 , V_95 ) ;
V_94 |= F_33 ( & V_89 -> V_102 , V_103 ) ;
V_94 |= F_33 ( & V_89 -> V_104 , V_105 ) ;
V_94 |= F_33 ( & V_89 -> V_106 , V_105 | V_107 ) ;
if ( V_94 )
return 1 ;
V_94 |= F_34 ( V_89 -> V_101 ) ;
V_94 |= F_34 ( V_89 -> V_106 ) ;
if ( V_94 )
return 2 ;
V_94 |= F_35 ( & V_89 -> V_108 , 0 ) ;
#define F_36 8000
#define F_37 4294967295u
switch ( V_89 -> V_101 ) {
case V_98 :
V_94 |= F_38 ( & V_89 -> V_109 ,
F_36 ) ;
V_94 |= F_39 ( & V_89 -> V_109 ,
F_37 ) ;
break;
case V_100 :
if ( V_89 -> V_109 & ~ V_110 ) {
V_89 -> V_109 = F_40 ( V_89 -> V_109 , 0 ,
~ V_110 ) ;
V_94 |= - V_70 ;
}
if ( V_89 -> V_109 & V_110 &
~ ( V_111 | V_112 ) ) {
V_89 -> V_109 =
F_40 ( V_89 -> V_109 , 0 ,
V_110 & ~ ( V_111 | V_112 ) ) ;
V_94 |= - V_70 ;
}
break;
default:
V_94 |= F_35 ( & V_89 -> V_109 , 0 ) ;
break;
}
V_94 |= F_35 ( & V_89 -> V_113 , V_89 -> V_93 ) ;
if ( V_89 -> V_106 == V_105 )
V_94 |= F_38 ( & V_89 -> V_114 , 1 ) ;
else
V_94 |= F_35 ( & V_89 -> V_114 , 0 ) ;
if ( V_94 )
return 3 ;
if ( V_89 -> V_101 == V_98 ) {
V_95 = V_89 -> V_109 ;
F_15 ( & V_89 -> V_109 , V_89 -> V_30 ) ;
if ( V_95 != V_89 -> V_109 )
V_94 ++ ;
}
if ( V_94 )
return 4 ;
if ( V_89 -> V_91 && V_89 -> V_93 > 0 )
V_94 |= F_31 ( V_2 , V_50 , V_89 ) ;
if ( V_94 )
return 5 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_24 ;
unsigned char V_115 ;
bool V_116 ;
struct V_88 * V_89 ;
F_8 ( & V_7 -> V_117 , V_24 ) ;
V_116 = V_7 -> V_118 ;
V_7 -> V_118 = false ;
F_9 ( & V_7 -> V_117 , V_24 ) ;
if ( ! V_116 )
return;
V_89 = & V_50 -> V_119 -> V_89 ;
if ( V_89 -> V_101 == V_98 ) {
F_21 ( V_2 , 1 ) ;
}
if ( V_7 -> V_74 < 2 ) {
V_115 = V_120 ;
} else {
V_115 = V_121 ;
}
F_8 ( & V_7 -> V_122 , V_24 ) ;
V_7 -> V_123 &= ~ V_115 ;
while ( V_7 -> V_124 && V_7 -> V_125 != V_126 ) {
F_9 ( & V_7 -> V_122 , V_24 ) ;
F_8 ( & V_7 -> V_122 , V_24 ) ;
}
F_18 ( V_7 -> V_123 , V_2 -> V_45 + V_127 ) ;
F_9 ( & V_7 -> V_122 , V_24 ) ;
if ( V_7 -> V_74 >= 2 ) {
V_7 -> V_128 &= V_129 ;
F_5 ( V_7 -> V_128 | V_130 |
V_131 ,
V_7 -> V_10 + V_87 ) ;
}
F_11 ( V_2 , V_132 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_133 * V_119 = V_50 -> V_119 ;
struct V_88 * V_89 = & V_119 -> V_89 ;
unsigned short V_9 ;
int V_86 ;
if ( V_89 -> V_106 == V_105 && V_119 -> V_134 >= V_89 -> V_114 )
return;
for ( V_86 = 0 ; V_86 < V_89 -> V_93 ; V_86 ++ ) {
unsigned int V_17 = F_24 ( V_89 -> V_91 [ V_86 ] ) ;
if ( ! F_43 ( V_50 , & V_9 , 1 ) ) {
V_119 -> V_135 |= V_136 ;
return;
}
F_4 ( V_2 , V_9 , V_17 ) ;
V_50 -> V_85 [ V_17 ] = V_9 ;
}
if ( V_89 -> V_106 == V_105 && V_119 -> V_134 >= V_89 -> V_114 )
V_119 -> V_135 |= V_137 ;
}
static bool F_44 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_133 * V_119 = V_50 -> V_119 ;
struct V_88 * V_89 = & V_119 -> V_89 ;
unsigned int V_138 = F_45 ( V_50 , 0 ) ;
unsigned int V_139 ;
unsigned short V_140 ;
unsigned int V_86 , V_58 ;
unsigned int V_135 = 0 ;
V_140 = F_2 ( V_7 -> V_10 + V_87 ) ;
if ( V_89 -> V_106 == V_105 && V_138 == 0 )
V_135 |= V_137 ;
if ( V_135 == 0 ) {
if ( V_140 & V_141 ) {
F_46 ( V_2 -> V_68 , L_4 ) ;
V_135 |= V_136 | V_142 ;
}
if ( V_138 == 0 &&
( V_140 & V_143 ) == 0 ) {
F_46 ( V_2 -> V_68 , L_5 ) ;
V_135 |= V_136 | V_142 ;
}
}
if ( V_135 == 0 ) {
if ( V_140 & V_144 )
V_139 = V_145 ;
else if ( V_140 & V_143 )
V_139 = V_146 ;
else if ( V_140 & V_147 )
V_139 = V_148 ;
else
V_139 = V_149 ;
V_139 /= V_89 -> V_93 ;
if ( V_138 > V_139 )
V_138 = V_139 ;
for ( V_58 = 0 ; V_58 < V_138 ; V_58 ++ ) {
for ( V_86 = 0 ; V_86 < V_89 -> V_93 ; V_86 ++ ) {
unsigned int V_17 = F_24 ( V_89 -> V_91 [ V_86 ] ) ;
unsigned short V_14 ;
F_43 ( V_50 , & V_14 , 1 ) ;
F_6 ( V_2 , V_14 , V_17 ) ;
V_50 -> V_85 [ V_17 ] = V_14 ;
}
}
if ( V_89 -> V_106 == V_105 &&
V_119 -> V_134 >= V_89 -> V_114 ) {
V_7 -> V_128 &= ~ V_150 ;
V_7 -> V_128 |= V_151 ;
F_5 ( V_7 -> V_128 , V_7 -> V_10 + V_87 ) ;
}
V_140 = F_2 ( V_7 -> V_10 + V_87 ) ;
if ( V_140 & V_141 ) {
F_46 ( V_2 -> V_68 , L_4 ) ;
V_135 |= V_136 | V_142 ;
}
}
V_119 -> V_135 |= V_135 ;
return ! ( V_119 -> V_135 & V_152 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
unsigned int V_153 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_24 ;
if ( V_153 )
return - V_70 ;
F_8 ( & V_7 -> V_117 , V_24 ) ;
if ( ! V_7 -> V_118 ) {
F_9 ( & V_7 -> V_117 , V_24 ) ;
return 1 ;
}
if ( V_7 -> V_74 < 2 ) {
F_9 ( & V_7 -> V_117 , V_24 ) ;
F_42 ( V_2 , V_50 ) ;
F_48 ( V_2 , V_50 ) ;
} else {
F_2 ( V_7 -> V_10 + V_154 ) ;
F_9 ( & V_7 -> V_117 , V_24 ) ;
}
F_49 ( 8 ) ;
return 1 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_133 * V_119 = V_50 -> V_119 ;
struct V_88 * V_89 = & V_119 -> V_89 ;
unsigned long V_24 ;
V_7 -> V_118 = true ;
if ( V_7 -> V_74 >= 2 ) {
unsigned short V_155 ;
bool V_156 ;
V_156 = F_44 ( V_2 , V_50 ) ;
F_48 ( V_2 , V_50 ) ;
if ( ! V_156 ) {
return;
}
switch ( V_89 -> V_101 ) {
case V_98 :
V_155 = V_157 ;
break;
case V_100 :
if ( ( V_89 -> V_109 & V_112 ) == 0 ) {
V_155 = V_158 ;
} else {
V_155 = V_159 ;
}
break;
case V_97 :
V_155 = V_160 ;
break;
default:
V_155 = V_161 ;
break;
}
V_7 -> V_128 =
( V_7 -> V_128 & ~ V_162 ) | V_155 ;
F_5 ( V_7 -> V_128 , V_7 -> V_10 + V_87 ) ;
}
switch ( V_89 -> V_101 ) {
case V_98 :
if ( V_7 -> V_74 < 2 ) {
F_8 ( & V_7 -> V_122 , V_24 ) ;
V_7 -> V_123 |= V_120 ;
F_18 ( V_7 -> V_123 , V_2 -> V_45 + V_127 ) ;
F_9 ( & V_7 -> V_122 ,
V_24 ) ;
}
F_18 ( F_51 ( 1 , V_163 ) , V_2 -> V_45 + V_164 ) ;
break;
case V_97 :
V_119 -> V_165 = F_47 ;
break;
}
if ( V_7 -> V_74 >= 2 ) {
F_8 ( & V_7 -> V_122 , V_24 ) ;
V_7 -> V_123 |= V_121 ;
F_18 ( V_7 -> V_123 , V_2 -> V_45 + V_127 ) ;
F_9 ( & V_7 -> V_122 , V_24 ) ;
}
}
static int F_52 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
unsigned int V_153 )
{
struct V_88 * V_89 = & V_50 -> V_119 -> V_89 ;
if ( V_153 != V_89 -> V_96 )
return - V_70 ;
V_50 -> V_119 -> V_165 = NULL ;
F_50 ( V_2 , V_50 ) ;
return 1 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned short V_128 ;
unsigned int V_59 ;
struct V_88 * V_89 = & V_50 -> V_119 -> V_89 ;
if ( V_89 -> V_101 == V_98 ) {
if ( ! F_7 ( V_2 , V_166 , V_132 ) )
return - V_57 ;
}
V_59 = F_25 ( V_89 -> V_91 [ 0 ] ) ;
V_7 -> V_16 = F_28 ( V_50 , V_59 ) ;
V_128 = V_7 -> V_16 ? V_167 : V_168 ;
if ( V_7 -> V_74 >= 2 ) {
unsigned short V_169 ;
unsigned int V_86 ;
V_169 = 0 ;
for ( V_86 = 0 ; V_86 < V_89 -> V_93 ; V_86 ++ )
V_169 |= 1 << F_24 ( V_89 -> V_91 [ V_86 ] ) ;
F_5 ( V_169 , V_7 -> V_10 + V_170 ) ;
V_128 |= V_171 | V_130 |
V_131 |
V_161 | V_172 ;
}
F_5 ( V_128 , V_7 -> V_10 + V_87 ) ;
V_7 -> V_128 = V_128 & ~ ( V_130 |
V_131 ) ;
if ( V_89 -> V_101 == V_98 ) {
F_18 ( F_51 ( 1 , V_173 ) , V_2 -> V_45 + V_164 ) ;
F_16 ( V_2 , 1 , V_174 ,
V_89 -> V_109 ,
V_89 -> V_30 ) ;
}
V_50 -> V_119 -> V_165 = F_52 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
F_41 ( V_2 , V_50 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_89 )
{
unsigned int V_175 , V_93 ;
int V_94 = 0 ;
V_93 = V_89 -> V_93 ;
if ( V_89 -> V_93 == 0 )
V_93 = 1 ;
V_175 = V_93 * V_89 -> V_176 ;
if ( V_175 < V_93 ||
V_175 < V_89 -> V_176 ) {
V_175 = V_36 ;
V_94 ++ ;
}
if ( V_89 -> V_109 < V_175 ) {
V_89 -> V_109 = V_175 ;
V_94 ++ ;
}
return ! V_94 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_88 * V_89 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_177 = ( V_50 -> V_67 / 2 ) - 1 ;
unsigned int V_90 = 0 ;
unsigned int V_178 = 0 ;
unsigned int V_179 = 0 ;
bool V_180 = false ;
unsigned int V_181 = 0 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_89 -> V_93 ; V_86 ++ ) {
unsigned int V_65 = V_89 -> V_91 [ V_86 ] ;
unsigned int V_17 = F_24 ( V_65 ) ;
unsigned int V_59 = F_25 ( V_65 ) ;
unsigned int V_60 = F_26 ( V_65 ) ;
bool V_182 = F_28 ( V_50 , V_59 ) ;
if ( V_60 == V_66 && V_17 >= V_177 ) {
F_27 ( V_2 -> V_68 ,
L_1 ,
V_69 , V_177 ) ;
return - V_70 ;
}
if ( V_86 > 0 ) {
if ( V_17 <= V_90 && V_181 == 0 )
V_181 = V_86 ;
if ( V_181 > 0 &&
V_89 -> V_91 [ V_86 % V_181 ] != V_65 ) {
F_27 ( V_2 -> V_68 ,
L_6 ,
V_69 ) ;
return - V_70 ;
}
if ( V_60 != V_179 ) {
F_27 ( V_2 -> V_68 ,
L_7 ,
V_69 ) ;
return - V_70 ;
}
if ( V_182 != V_180 ) {
F_27 ( V_2 -> V_68 ,
L_8 ,
V_69 ) ;
return - V_70 ;
}
if ( V_60 != V_66 && V_59 != V_178 &&
( ( V_17 ^ V_90 ) & ~ 1 ) == 0 ) {
F_27 ( V_2 -> V_68 ,
L_9 ,
V_69 ) ;
return - V_70 ;
}
}
V_90 = V_17 ;
V_178 = V_59 ;
V_179 = V_60 ;
V_180 = V_182 ;
}
if ( V_181 == 0 )
V_181 = V_89 -> V_93 ;
if ( V_89 -> V_93 % V_181 ) {
F_27 ( V_2 -> V_68 ,
L_10 , V_69 ) ;
return - V_70 ;
}
if ( V_7 -> V_74 > 0 && V_7 -> V_74 < 4 ) {
if ( V_181 > 1 && F_24 ( V_89 -> V_91 [ 0 ] ) ) {
F_57 ( V_2 -> V_68 ,
L_11 ,
V_7 -> V_74 ) ;
return - V_70 ;
}
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_49 * V_50 , struct V_88 * V_89 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_94 = 0 ;
unsigned int V_95 ;
V_94 |= F_33 ( & V_89 -> V_96 , V_103 | V_97 ) ;
V_95 = V_183 | V_98 | V_97 ;
if ( V_4 -> V_184 || V_4 -> V_99 > 0 ) {
V_95 |= V_100 ;
}
V_94 |= F_33 ( & V_89 -> V_101 , V_95 ) ;
V_94 |= F_33 ( & V_89 -> V_102 ,
V_98 | V_97 | V_100 ) ;
V_94 |= F_33 ( & V_89 -> V_104 , V_105 ) ;
V_94 |= F_33 ( & V_89 -> V_106 , V_105 | V_107 ) ;
if ( V_94 )
return 1 ;
V_94 |= F_34 ( V_89 -> V_96 ) ;
V_94 |= F_34 ( V_89 -> V_101 ) ;
V_94 |= F_34 ( V_89 -> V_102 ) ;
V_94 |= F_34 ( V_89 -> V_106 ) ;
if ( V_89 -> V_101 != V_183 &&
V_89 -> V_102 != V_98 )
V_94 |= - V_70 ;
if ( V_94 )
return 2 ;
V_94 |= F_35 ( & V_89 -> V_108 , 0 ) ;
#define F_59 3200
#define F_60 8000
#define F_61 4000
#define F_62 4294967295u
if ( V_89 -> V_102 == V_98 ) {
unsigned int V_185 ;
if ( V_7 -> V_74 == 0 ) {
if ( V_89 -> V_91 && V_89 -> V_93 > 0 ) {
if ( F_26 ( V_89 -> V_91 [ 0 ] ) == V_66 )
V_185 = F_60 ;
else
V_185 = F_59 ;
} else {
V_185 = F_59 ;
}
} else {
V_185 = F_61 ;
}
V_94 |= F_38 ( & V_89 -> V_176 ,
V_185 ) ;
V_94 |= F_39 ( & V_89 -> V_176 ,
F_62 ) ;
} else if ( V_89 -> V_102 == V_100 ) {
if ( V_89 -> V_176 & V_110 ) {
if ( V_89 -> V_176 & ~ V_110 ) {
V_89 -> V_176 = F_40 ( V_89 -> V_176 , 0 ,
~ V_110 ) ;
V_94 |= - V_70 ;
}
if ( ( V_89 -> V_176 & V_110 & ~ V_112 ) !=
V_111 ) {
V_89 -> V_176 =
F_40 ( V_89 -> V_108 , V_111 | 0 ,
V_110 & ~ V_112 ) ;
V_94 |= - V_70 ;
}
} else {
V_94 |= F_39 ( & V_89 -> V_176 , 1 ) ;
}
} else {
V_94 |= F_35 ( & V_89 -> V_176 , 0 ) ;
}
V_94 |= F_35 ( & V_89 -> V_113 , V_89 -> V_93 ) ;
if ( V_89 -> V_106 == V_105 )
V_94 |= F_38 ( & V_89 -> V_114 , 1 ) ;
else
V_94 |= F_35 ( & V_89 -> V_114 , 0 ) ;
if ( V_89 -> V_101 == V_100 ) {
if ( V_89 -> V_109 & ~ V_110 ) {
V_89 -> V_109 = F_40 ( V_89 -> V_109 , 0 ,
~ V_110 ) ;
V_94 |= - V_70 ;
}
if ( V_89 -> V_109 & V_110 & ~ V_111 ) {
V_89 -> V_109 = F_40 ( V_89 -> V_109 , 0 ,
V_110 & ~ V_111 ) ;
V_94 |= - V_70 ;
}
} else if ( V_89 -> V_101 == V_98 ) {
if ( ! F_55 ( V_89 ) )
V_94 |= - V_70 ;
} else {
V_94 |= F_35 ( & V_89 -> V_109 , 0 ) ;
}
if ( V_94 )
return 3 ;
if ( V_89 -> V_102 == V_98 ) {
V_95 = V_89 -> V_176 ;
F_15 ( & V_89 -> V_176 , V_89 -> V_30 ) ;
if ( V_95 != V_89 -> V_176 )
V_94 ++ ;
}
if ( V_89 -> V_101 == V_98 ) {
V_95 = V_89 -> V_109 ;
F_15 ( & V_89 -> V_109 , V_89 -> V_30 ) ;
if ( ! F_55 ( V_89 ) ) {
F_15 ( & V_89 -> V_109 ,
V_35 ) ;
F_55 ( V_89 ) ;
}
if ( V_95 != V_89 -> V_109 )
V_94 ++ ;
}
if ( V_94 )
return 4 ;
if ( V_89 -> V_91 && V_89 -> V_93 > 0 )
V_94 |= F_56 ( V_2 , V_50 , V_89 ) ;
if ( V_94 )
return 5 ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_88 * V_89 = & V_50 -> V_119 -> V_89 ;
unsigned int V_186 ;
unsigned short V_187 ;
unsigned short V_62 ;
if ( V_89 -> V_30 & V_188 )
V_186 = V_89 -> V_113 - V_50 -> V_119 -> V_189 ;
else
V_186 = F_64 ( V_50 , V_190 ) ;
if ( V_186 >= V_190 ) {
V_187 = V_191 ;
} else if ( V_186 > 1 && V_7 -> V_74 > 0 ) {
if ( V_7 -> V_192 != V_186 ) {
V_7 -> V_192 = V_186 ;
F_5 ( V_186 , V_7 -> V_10 + V_193 ) ;
}
V_187 = V_194 ;
} else {
V_187 = V_195 ;
}
V_62 = ( V_7 -> V_62 & ~ V_196 ) | V_187 ;
if ( V_62 != V_7 -> V_62 ) {
V_7 -> V_62 = V_62 ;
F_5 ( V_62 , V_7 -> V_10 + V_55 ) ;
}
}
static int F_65 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
unsigned int V_153 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_24 ;
unsigned int V_197 ;
if ( V_153 )
return - V_70 ;
F_8 ( & V_7 -> V_198 , V_24 ) ;
if ( ! V_7 -> V_199 ) {
F_9 ( & V_7 -> V_198 , V_24 ) ;
return 1 ;
}
F_17 ( V_2 -> V_45 + V_46 , 0 , 2 , V_73 ) ;
F_17 ( V_2 -> V_45 + V_46 , 0 , 2 , V_48 ) ;
if ( ( V_7 -> V_62 & V_200 ) == V_75 &&
V_7 -> V_74 == 0 ) {
V_197 = 8 ;
} else {
V_197 = 4 ;
}
F_9 ( & V_7 -> V_198 , V_24 ) ;
F_49 ( V_197 ) ;
return 1 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
unsigned int V_153 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_24 ;
unsigned char V_201 ;
if ( V_153 )
return - V_70 ;
F_8 ( & V_7 -> V_198 , V_24 ) ;
if ( V_7 -> V_199 ) {
V_201 = F_51 ( 0 , V_173 ) ;
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
V_201 = F_51 ( 0 , V_163 ) ;
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
}
F_9 ( & V_7 -> V_198 , V_24 ) ;
return 1 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_24 ;
struct V_88 * V_89 ;
bool V_116 ;
F_8 ( & V_7 -> V_198 , V_24 ) ;
V_116 = V_7 -> V_199 ;
V_7 -> V_199 = false ;
F_9 ( & V_7 -> V_198 , V_24 ) ;
if ( ! V_116 )
return;
V_89 = & V_50 -> V_119 -> V_89 ;
if ( V_89 -> V_102 == V_98 ) {
F_21 ( V_2 , 2 ) ;
}
if ( V_89 -> V_101 != V_183 ) {
F_21 ( V_2 , 0 ) ;
}
F_8 ( & V_7 -> V_122 , V_24 ) ;
V_7 -> V_123 &= ~ V_202 ;
while ( V_7 -> V_124 && V_7 -> V_125 != V_126 ) {
F_9 ( & V_7 -> V_122 , V_24 ) ;
F_8 ( & V_7 -> V_122 , V_24 ) ;
}
F_18 ( V_7 -> V_123 , V_2 -> V_45 + V_127 ) ;
F_9 ( & V_7 -> V_122 , V_24 ) ;
V_7 -> V_62 =
( V_7 -> V_62 & ( V_203 | V_200 ) ) |
V_204 ;
F_5 ( V_7 -> V_62 | V_83 ,
V_7 -> V_10 + V_55 ) ;
F_11 ( V_2 , V_205 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_24 ;
unsigned short V_206 ;
struct V_133 * V_119 = V_50 -> V_119 ;
struct V_88 * V_89 = & V_119 -> V_89 ;
V_7 -> V_199 = true ;
F_8 ( & V_7 -> V_122 , V_24 ) ;
V_7 -> V_123 |= V_202 ;
F_18 ( V_7 -> V_123 , V_2 -> V_45 + V_127 ) ;
F_9 ( & V_7 -> V_122 , V_24 ) ;
switch ( V_89 -> V_102 ) {
default:
V_206 = V_204 ;
break;
case V_98 :
V_206 = V_71 ;
break;
case V_100 :
if ( V_89 -> V_176 & V_111 ) {
if ( ( V_89 -> V_176 & V_112 ) == 0 ) {
V_206 = V_207 ;
} else {
V_206 = V_208 ;
}
} else {
if ( V_89 -> V_176 ) {
V_206 = V_207 ;
} else {
V_206 = V_208 ;
}
}
break;
case V_97 :
V_206 = V_71 ;
break;
}
V_7 -> V_62 = ( V_7 -> V_62 & ~ V_209 ) | V_206 ;
F_5 ( V_7 -> V_62 , V_7 -> V_10 + V_55 ) ;
if ( V_89 -> V_102 == V_97 )
V_119 -> V_165 = F_65 ;
F_63 ( V_2 , V_50 ) ;
if ( V_89 -> V_102 == V_98 ) {
unsigned char V_201 ;
if ( V_89 -> V_101 != V_183 ) {
V_201 = F_51 ( 2 , V_210 ) ;
} else {
V_201 = F_51 ( 2 , V_163 ) ;
}
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
if ( V_89 -> V_101 != V_183 ) {
switch ( V_89 -> V_101 ) {
default:
V_201 = F_51 ( 0 , V_163 ) ;
break;
case V_100 :
V_201 = F_51 ( 0 , V_211 ) ;
break;
case V_98 :
V_201 = F_51 ( 0 , V_210 ) ;
break;
case V_97 :
V_201 = F_51 ( 0 , V_163 ) ;
break;
}
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
switch ( V_89 -> V_101 ) {
case V_98 :
V_201 = F_51 ( 1 , V_163 ) ;
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
break;
case V_97 :
V_119 -> V_165 = F_66 ;
break;
}
}
} else if ( V_89 -> V_102 != V_97 ) {
F_10 ( V_2 , V_212 , V_205 ) ;
}
}
static int F_69 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
unsigned int V_153 )
{
struct V_88 * V_89 = & V_50 -> V_119 -> V_89 ;
if ( V_153 != V_89 -> V_108 )
return - V_70 ;
V_50 -> V_119 -> V_165 = NULL ;
F_68 ( V_2 , V_50 ) ;
return 1 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_133 * V_119 = V_50 -> V_119 ;
struct V_88 * V_89 = & V_119 -> V_89 ;
unsigned int V_213 ;
unsigned int V_86 ;
unsigned int V_214 ;
unsigned int V_215 ;
unsigned short V_84 ;
V_214 = F_64 ( V_50 , V_190 ) ;
if ( V_214 == 0 )
return;
V_215 = 0 ;
for ( V_86 = 0 ; V_86 < V_214 ; V_86 ++ ) {
if ( V_215 == 0 ) {
V_213 = F_2 ( V_7 -> V_10 + V_55 ) ;
if ( V_213 & V_216 ) {
F_46 ( V_2 -> V_68 , L_12 ) ;
V_119 -> V_135 |= V_142 ;
break;
} else if ( V_213 & V_56 ) {
break;
} else if ( V_213 & V_217 ) {
V_215 = V_190 ;
} else if ( V_7 -> V_74 > 0 ) {
V_215 = F_2 ( V_7 -> V_10 +
V_218 ) ;
if ( V_215 == 0 )
break;
} else {
V_215 = 1 ;
}
}
V_84 = F_1 ( V_2 ) ;
if ( ! F_71 ( V_50 , & V_84 , 1 ) )
break;
V_215 -- ;
if ( V_89 -> V_106 == V_105 &&
V_119 -> V_134 >= V_89 -> V_114 ) {
V_119 -> V_135 |= V_137 ;
break;
}
}
if ( ! ( V_119 -> V_135 & V_152 ) )
F_63 ( V_2 , V_50 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_86 , V_17 , V_59 , V_219 ;
unsigned int V_21 ;
unsigned short V_62 , V_63 ;
unsigned char V_201 ;
struct V_133 * V_119 = V_50 -> V_119 ;
struct V_88 * V_89 = & V_119 -> V_89 ;
V_21 = 0 ;
V_21 |= V_212 ;
if ( V_89 -> V_101 != V_183 ) {
V_21 |= V_220 ;
if ( V_89 -> V_101 == V_98 ) {
V_21 |= V_166 ;
}
}
if ( ! F_7 ( V_2 , V_21 , V_205 ) )
return - V_57 ;
V_62 = V_72 ;
V_63 = 0 ;
if ( F_26 ( V_89 -> V_91 [ 0 ] ) == V_66 ) {
V_219 = 1 ;
V_62 |= V_75 ;
} else {
V_219 = 0 ;
V_62 |= V_76 ;
}
V_59 = F_25 ( V_89 -> V_91 [ 0 ] ) ;
V_7 -> V_12 = F_28 ( V_50 , V_59 ) ;
if ( V_7 -> V_12 )
V_62 |= V_79 ;
else
V_62 |= V_80 ;
for ( V_86 = 0 ; V_86 < V_89 -> V_93 ; V_86 ++ ) {
unsigned int V_61 ;
V_17 = F_24 ( V_89 -> V_91 [ V_86 ] ) ;
V_59 = F_25 ( V_89 -> V_91 [ V_86 ] ) ;
if ( V_219 ) {
V_61 = 2 * V_17 ;
if ( V_7 -> V_74 == 0 ) {
V_63 |= 3 << V_61 ;
} else {
V_63 |= 1 << V_61 ;
}
} else {
V_61 = V_17 & ~ 1 ;
V_63 |= 1 << V_17 ;
}
V_7 -> V_77 = ( V_7 -> V_77 & ~ ( 3 << V_61 ) ) |
( V_78 [ V_59 ] << V_61 ) ;
}
F_5 ( V_63 , V_7 -> V_10 + V_81 ) ;
F_5 ( V_7 -> V_77 , V_7 -> V_10 + V_82 ) ;
F_17 ( V_2 -> V_45 + V_46 , 0 , 2 , V_48 ) ;
V_62 |= V_221 | V_71 ;
V_7 -> V_62 = V_62 ;
F_5 ( V_62 | V_83 , V_7 -> V_10 + V_55 ) ;
F_73 ( 25 , 100 ) ;
F_5 ( V_62 | V_83 , V_7 -> V_10 + V_55 ) ;
if ( V_89 -> V_102 == V_98 ) {
V_201 = F_51 ( 2 , V_173 ) ;
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
F_16 ( V_2 , 2 , V_174 , V_89 -> V_176 ,
V_89 -> V_30 ) ;
if ( V_89 -> V_101 != V_183 ) {
V_201 = F_51 ( 0 , V_163 ) ;
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
F_16 ( V_2 , 0 , V_48 ,
( ( T_1 ) V_89 -> V_176 *
V_89 -> V_113 ) ,
V_35 ) ;
if ( V_89 -> V_101 == V_98 ) {
V_201 = F_51 ( 1 , V_173 ) ;
F_18 ( V_201 , V_2 -> V_45 + V_164 ) ;
F_16 ( V_2 , 1 , V_174 ,
V_89 -> V_109 ,
V_89 -> V_30 ) ;
}
}
}
if ( V_89 -> V_96 == V_97 )
V_50 -> V_119 -> V_165 = F_69 ;
else
F_68 ( V_2 , V_50 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
F_67 ( V_2 , V_50 ) ;
return 0 ;
}
static T_2 F_75 ( int V_222 , void * V_223 )
{
unsigned char V_224 , V_225 , V_226 ;
struct V_1 * V_2 = (struct V_1 * ) V_223 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_49 * V_227 = V_2 -> V_228 ;
struct V_49 * V_229 = V_2 -> V_230 ;
unsigned long V_24 ;
V_224 = F_76 ( V_2 -> V_45 + V_231 ) ;
if ( V_224 == V_232 )
return V_233 ;
F_8 ( & V_7 -> V_122 , V_24 ) ;
V_225 = V_7 -> V_123 & V_224 ;
V_226 = V_7 -> V_123 & ~ V_224 ;
F_18 ( V_226 , V_2 -> V_45 + V_127 ) ;
V_7 -> V_124 = true ;
V_7 -> V_125 = V_126 ;
F_9 ( & V_7 -> V_122 , V_24 ) ;
if ( V_225 & V_120 )
F_42 ( V_2 , V_227 ) ;
if ( V_225 & V_121 )
F_44 ( V_2 , V_227 ) ;
if ( V_225 & V_202 )
F_70 ( V_2 , V_229 ) ;
F_8 ( & V_7 -> V_122 , V_24 ) ;
if ( V_7 -> V_123 != V_226 )
F_18 ( V_7 -> V_123 , V_2 -> V_45 + V_127 ) ;
V_7 -> V_124 = false ;
F_9 ( & V_7 -> V_122 , V_24 ) ;
F_48 ( V_2 , V_227 ) ;
F_48 ( V_2 , V_229 ) ;
return V_234 ;
}
static bool F_77 ( const struct V_3 * V_235 ,
struct V_236 * V_236 )
{
if ( V_235 -> V_237 != V_236 -> V_238 )
return false ;
if ( V_235 -> V_99 == 0 )
return true ;
if ( F_78 ( V_236 , 3 ) < 32 )
return false ;
return true ;
}
static const struct V_3 * F_79 ( struct V_236 * V_236 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < F_80 ( V_239 ) ; V_86 ++ )
if ( F_77 ( & V_239 [ V_86 ] , V_236 ) )
return & V_239 [ V_86 ] ;
return NULL ;
}
static int F_81 ( struct V_1 * V_2 ,
unsigned long V_240 )
{
struct V_236 * V_236 = F_82 ( V_2 ) ;
const struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_49 * V_50 ;
int V_241 ;
F_57 ( V_2 -> V_68 , L_13 ,
F_83 ( V_236 ) ) ;
V_7 = F_84 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_242 ;
F_85 ( & V_7 -> V_122 ) ;
F_85 ( & V_7 -> V_25 ) ;
F_85 ( & V_7 -> V_198 ) ;
F_85 ( & V_7 -> V_117 ) ;
V_2 -> V_5 = F_79 ( V_236 ) ;
if ( V_2 -> V_5 == NULL ) {
F_46 ( V_2 -> V_68 ,
L_14 ) ;
return - V_70 ;
}
V_4 = V_2 -> V_5 ;
V_2 -> V_243 = V_4 -> V_244 ;
V_241 = F_86 ( V_2 ) ;
if ( V_241 )
return V_241 ;
V_2 -> V_45 = F_87 ( V_236 , 2 ) ;
V_7 -> V_10 = F_87 ( V_236 , 3 ) ;
F_27 ( V_2 -> V_68 ,
L_15 ,
V_2 -> V_243 , V_2 -> V_45 , V_7 -> V_10 ) ;
V_7 -> V_128 = F_2 ( V_7 -> V_10 + V_87 ) &
V_129 ;
if ( F_78 ( V_236 , 3 ) >= 32 ) {
unsigned short V_245 = 0 ;
V_7 -> V_74 = F_2 ( V_7 -> V_10 + V_246 ) ;
if ( V_7 -> V_74 < V_4 -> V_99 ) {
F_46 ( V_2 -> V_68 ,
L_16 ,
V_2 -> V_243 , V_7 -> V_74 ,
V_4 -> V_99 ) ;
return - V_247 ;
}
if ( V_7 -> V_74 > 0 ) {
if ( ! V_4 -> V_184 ) {
V_245 |= V_248 ;
}
if ( V_4 -> V_15 && V_7 -> V_74 >= 2 ) {
V_245 |= V_249 ;
}
}
F_5 ( V_245 , V_7 -> V_10 + V_250 ) ;
if ( V_245 & V_249 ) {
F_5 ( V_7 -> V_128 | V_171 |
V_130 ,
V_7 -> V_10 + V_87 ) ;
F_5 ( 0 , V_7 -> V_10 + V_170 ) ;
F_5 ( V_7 -> V_128 , V_7 -> V_10 + V_87 ) ;
}
}
F_18 ( 0 , V_2 -> V_45 + V_127 ) ;
V_7 -> V_77 = 0 ;
V_7 -> V_62 = V_204 | V_76 |
V_79 ;
F_5 ( 1 << 0 , V_7 -> V_10 + V_81 ) ;
F_5 ( V_7 -> V_77 , V_7 -> V_10 + V_82 ) ;
F_5 ( V_7 -> V_62 | V_83 ,
V_7 -> V_10 + V_55 ) ;
if ( V_236 -> V_222 ) {
V_241 = F_88 ( V_236 -> V_222 , F_75 , V_251 ,
V_2 -> V_243 , V_2 ) ;
if ( V_241 == 0 )
V_2 -> V_222 = V_236 -> V_222 ;
}
V_241 = F_89 ( V_2 , 3 ) ;
if ( V_241 )
return V_241 ;
V_50 = & V_2 -> V_252 [ 0 ] ;
V_50 -> type = V_253 ;
V_50 -> V_254 = V_255 | V_256 | V_257 ;
V_50 -> V_67 = 16 ;
V_50 -> V_258 = ( 1 << V_4 -> V_13 ) - 1 ;
V_50 -> V_259 = & V_260 ;
V_50 -> V_261 = F_23 ;
V_50 -> V_262 = 256 ;
if ( V_2 -> V_222 ) {
V_2 -> V_230 = V_50 ;
V_50 -> V_254 |= V_263 ;
V_50 -> V_264 = F_72 ;
V_50 -> V_265 = F_58 ;
V_50 -> V_266 = F_74 ;
}
V_50 = & V_2 -> V_252 [ 1 ] ;
if ( V_4 -> V_15 ) {
V_50 -> type = V_267 ;
V_50 -> V_254 = V_268 | V_257 ;
V_50 -> V_67 = 2 ;
V_50 -> V_258 = ( 1 << V_4 -> V_15 ) - 1 ;
V_50 -> V_259 = & V_269 ;
V_50 -> V_270 = F_30 ;
V_50 -> V_262 = 2 ;
if ( V_2 -> V_222 ) {
V_2 -> V_228 = V_50 ;
V_50 -> V_254 |= V_271 ;
V_50 -> V_264 = F_53 ;
V_50 -> V_265 = F_32 ;
V_50 -> V_266 = F_54 ;
}
V_241 = F_90 ( V_50 ) ;
if ( V_241 )
return V_241 ;
} else {
V_50 -> type = V_272 ;
}
V_50 = & V_2 -> V_252 [ 2 ] ;
if ( V_4 -> V_184 ) {
V_241 = F_91 ( V_2 , V_50 , NULL , V_273 ) ;
if ( V_241 )
return V_241 ;
} else {
V_50 -> type = V_272 ;
}
return 0 ;
}
static int F_92 ( struct V_236 * V_2 ,
const struct V_274 * V_237 )
{
return F_93 ( V_2 , & V_275 ,
V_237 -> V_276 ) ;
}
