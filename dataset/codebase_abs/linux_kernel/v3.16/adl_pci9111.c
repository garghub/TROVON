static void F_1 ( unsigned long V_1 ,
bool V_2 ,
bool V_3 ,
bool V_4 ,
bool V_5 ,
bool V_6 )
{
int V_7 = 0 ;
if ( V_2 )
V_7 |= V_8 ;
if ( V_3 )
V_7 |= V_9 ;
if ( V_4 )
V_7 |= V_10 ;
if ( V_5 )
V_7 |= V_11 ;
if ( V_6 )
V_7 |= V_12 ;
F_2 ( V_7 , V_1 + V_13 ) ;
}
static void F_3 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned long V_19 = V_15 -> V_20 + V_21 ;
F_4 ( V_19 , 1 , 0 , V_22 | V_23 ) ;
F_4 ( V_19 , 1 , 1 , V_24 | V_23 ) ;
F_4 ( V_19 , 1 , 2 , V_24 | V_23 ) ;
F_5 ( 1 ) ;
F_6 ( V_19 , 1 , 2 , V_17 -> V_25 ) ;
F_6 ( V_19 , 1 , 1 , V_17 -> V_26 ) ;
}
static void F_7 ( struct V_14 * V_15 ,
enum V_27 V_28 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0x9 ;
switch ( V_28 ) {
case V_30 :
break;
case V_31 :
V_7 |= V_32 ;
break;
case V_33 :
V_7 |= V_34 ;
break;
}
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_9 ( struct V_14 * V_15 , bool V_35 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0x7 ;
if ( V_35 )
V_7 |= V_36 ;
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_10 ( struct V_14 * V_15 , bool V_37 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 &= 0xe ;
if ( V_37 )
V_7 |= V_38 ;
F_2 ( V_7 , V_15 -> V_20 + V_29 ) ;
}
static void F_11 ( struct V_14 * V_15 ,
enum V_39 V_40 ,
enum V_41 V_42 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_29 ) ;
V_7 >>= 4 ;
V_7 &= 0xc0 ;
if ( V_40 == V_43 )
V_7 |= V_44 ;
if ( V_42 == V_45 )
V_7 |= V_46 ;
F_2 ( V_7 , V_15 -> V_20 + V_47 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
unsigned long V_48 = V_15 -> V_20 + V_47 ;
F_2 ( 0 , V_48 ) ;
F_2 ( V_49 , V_48 ) ;
F_2 ( 0 , V_48 ) ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_52 , true , true , true ,
true , false ) ;
F_7 ( V_15 , V_30 ) ;
F_10 ( V_15 , false ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_53 * V_54 )
{
unsigned int V_55 = F_15 ( V_54 -> V_56 [ 0 ] ) ;
unsigned int V_57 = F_16 ( V_54 -> V_56 [ 0 ] ) ;
int V_58 ;
for ( V_58 = 1 ; V_58 < V_54 -> V_59 ; V_58 ++ ) {
unsigned int V_60 = F_17 ( V_54 -> V_56 [ V_58 ] ) ;
unsigned int V_61 = F_15 ( V_54 -> V_56 [ V_58 ] ) ;
unsigned int V_62 = F_16 ( V_54 -> V_56 [ V_58 ] ) ;
if ( V_60 != V_58 ) {
F_18 ( V_15 -> V_63 ,
L_1 ) ;
return - V_64 ;
}
if ( V_61 != V_55 ) {
F_18 ( V_15 -> V_63 ,
L_2 ) ;
return - V_64 ;
}
if ( V_62 != V_57 ) {
F_18 ( V_15 -> V_63 ,
L_3 ) ;
return - V_64 ;
}
}
return 0 ;
}
static int F_19 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_53 * V_54 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_65 = 0 ;
unsigned int V_66 ;
V_65 |= F_20 ( & V_54 -> V_67 , V_68 ) ;
V_65 |= F_20 ( & V_54 -> V_69 ,
V_70 | V_71 | V_72 ) ;
V_65 |= F_20 ( & V_54 -> V_73 ,
V_70 | V_72 ) ;
V_65 |= F_20 ( & V_54 -> V_74 , V_75 ) ;
V_65 |= F_20 ( & V_54 -> V_76 ,
V_75 | V_77 ) ;
if ( V_65 )
return 1 ;
V_65 |= F_21 ( V_54 -> V_69 ) ;
V_65 |= F_21 ( V_54 -> V_73 ) ;
V_65 |= F_21 ( V_54 -> V_76 ) ;
if ( V_54 -> V_69 != V_71 ) {
if ( V_54 -> V_69 != V_54 -> V_73 )
V_65 |= - V_64 ;
}
if ( V_65 )
return 2 ;
V_65 |= F_22 ( & V_54 -> V_78 , 0 ) ;
if ( V_54 -> V_73 == V_70 )
V_65 |= F_23 ( & V_54 -> V_79 ,
V_80 ) ;
else
V_65 |= F_22 ( & V_54 -> V_79 , 0 ) ;
if ( V_54 -> V_69 == V_70 )
V_65 |= F_23 ( & V_54 -> V_81 ,
V_80 ) ;
else
V_65 |= F_22 ( & V_54 -> V_81 , 0 ) ;
V_65 |= F_22 ( & V_54 -> V_82 , V_54 -> V_59 ) ;
if ( V_54 -> V_76 == V_75 )
V_65 |= F_23 ( & V_54 -> V_83 , 1 ) ;
else
V_65 |= F_22 ( & V_54 -> V_83 , 0 ) ;
if ( V_65 )
return 3 ;
if ( V_54 -> V_73 == V_70 ) {
V_66 = V_54 -> V_79 ;
F_24 ( V_84 ,
& V_17 -> V_26 ,
& V_17 -> V_25 ,
& V_66 , V_54 -> V_7 ) ;
V_65 |= F_22 ( & V_54 -> V_79 , V_66 ) ;
}
if ( V_54 -> V_69 == V_70 ) {
V_66 = V_54 -> V_59 * V_54 -> V_79 ;
if ( V_66 < V_54 -> V_81 )
V_66 *= ( V_54 -> V_81 / V_66 ) ;
V_65 |= F_22 ( & V_54 -> V_81 , V_66 ) ;
}
if ( V_65 )
return 4 ;
if ( V_54 -> V_56 && V_54 -> V_59 > 0 )
V_65 |= F_14 ( V_15 , V_51 , V_54 ) ;
if ( V_65 )
return 5 ;
return 0 ;
}
static int F_25 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_53 * V_54 = & V_51 -> V_85 -> V_54 ;
if ( V_54 -> V_59 > 1 ) {
F_2 ( V_54 -> V_59 - 1 ,
V_15 -> V_20 + V_86 ) ;
F_10 ( V_15 , true ) ;
} else {
F_2 ( F_17 ( V_54 -> V_56 [ 0 ] ) ,
V_15 -> V_20 + V_86 ) ;
F_10 ( V_15 , false ) ;
}
F_2 ( F_15 ( V_54 -> V_56 [ 0 ] ) & V_87 ,
V_15 -> V_20 + V_88 ) ;
if ( V_54 -> V_76 == V_75 )
V_17 -> V_89 = V_54 -> V_83 * V_54 -> V_59 ;
else
V_17 -> V_89 = 0 ;
V_17 -> V_90 = 0 ;
if ( V_54 -> V_73 == V_70 ) {
F_7 ( V_15 , V_30 ) ;
F_3 ( V_15 ) ;
F_12 ( V_15 ) ;
F_11 ( V_15 , V_43 ,
V_91 ) ;
F_7 ( V_15 , V_31 ) ;
F_1 ( V_17 -> V_52 , true , true ,
false , true , true ) ;
if ( V_54 -> V_69 == V_70 ) {
V_17 -> V_90 = ( V_54 -> V_81 /
( V_54 -> V_79 * V_54 -> V_59 ) ) - 1 ;
}
} else {
F_7 ( V_15 , V_33 ) ;
F_12 ( V_15 ) ;
F_11 ( V_15 , V_43 ,
V_91 ) ;
F_1 ( V_17 -> V_52 , true , true ,
false , true , true ) ;
}
V_17 -> V_89 *= ( 1 + V_17 -> V_90 ) ;
V_17 -> V_92 = 0 ;
V_17 -> V_93 = V_54 -> V_59 *
( 1 + V_17 -> V_90 ) ;
return 0 ;
}
static void F_26 ( struct V_14 * V_15 ,
struct V_50 * V_51 , void * V_94 ,
unsigned int V_95 ,
unsigned int V_96 )
{
unsigned short * V_97 = V_94 ;
unsigned int V_98 = V_51 -> V_98 ;
unsigned int V_99 = ( V_98 + 1 ) >> 1 ;
unsigned int V_100 = ( V_98 == 0xffff ) ? 0 : 4 ;
unsigned int V_101 = V_95 / sizeof( short ) ;
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < V_101 ; V_58 ++ )
V_97 [ V_58 ] = ( ( V_97 [ V_58 ] >> V_100 ) & V_98 ) ^ V_99 ;
}
static void F_27 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_16 * V_102 = V_15 -> V_18 ;
struct V_53 * V_54 = & V_51 -> V_85 -> V_54 ;
unsigned int V_103 = 0 ;
unsigned int V_104 ;
if ( V_54 -> V_76 == V_75 &&
V_105 > V_102 -> V_89 )
V_104 = V_102 -> V_89 ;
else
V_104 = V_105 ;
F_28 ( V_15 -> V_20 + V_106 ,
V_102 -> V_107 , V_104 ) ;
if ( V_102 -> V_90 < 1 ) {
V_103 = F_29 ( V_51 ,
V_102 -> V_107 ,
V_104 * sizeof( short ) ) ;
} else {
unsigned int V_108 = 0 ;
unsigned int V_109 ;
while ( V_108 < V_104 ) {
if ( V_102 -> V_92 < V_54 -> V_59 ) {
V_109 = V_54 -> V_59 -
V_102 -> V_92 ;
if ( V_109 > V_104 - V_108 )
V_109 = V_104 - V_108 ;
V_103 += F_29 ( V_51 ,
V_102 -> V_107 + V_108 ,
V_109 * sizeof( short ) ) ;
} else {
V_109 = V_102 -> V_93 -
V_102 -> V_92 ;
if ( V_109 > V_104 - V_108 )
V_109 = V_104 - V_108 ;
V_103 += V_109 * sizeof( short ) ;
}
V_108 += V_109 ;
V_102 -> V_92 += V_109 ;
if ( V_102 -> V_92 >=
V_102 -> V_93 )
V_102 -> V_92 = 0 ;
}
}
V_102 -> V_89 -= V_103 / sizeof( short ) ;
}
static T_1 F_30 ( int V_110 , void * V_111 )
{
struct V_14 * V_15 = V_111 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_50 * V_51 = V_15 -> V_112 ;
struct V_113 * V_85 ;
struct V_53 * V_54 ;
unsigned int V_114 ;
unsigned long V_115 ;
unsigned char V_116 ;
if ( ! V_15 -> V_117 ) {
return V_118 ;
}
V_85 = V_51 -> V_85 ;
V_54 = & V_85 -> V_54 ;
F_31 ( & V_15 -> V_119 , V_115 ) ;
V_116 = F_8 ( V_17 -> V_52 + V_13 ) ;
if ( ! ( ( ( V_116 & V_12 ) != 0 ) &&
( ( ( V_116 & V_120 ) == V_120 ) ||
( ( V_116 & V_121 ) == V_121 ) ) ) ) {
F_32 ( & V_15 -> V_119 , V_115 ) ;
return V_118 ;
}
if ( ( V_116 & V_120 ) == V_120 ) {
V_114 = F_8 ( V_15 -> V_20 + V_88 ) ;
if ( ! ( V_114 & V_122 ) ) {
F_32 ( & V_15 -> V_119 , V_115 ) ;
F_33 ( V_15 , V_123 L_4 ) ;
F_2 ( 0 , V_15 -> V_20 + V_124 ) ;
V_85 -> V_125 |= V_126 | V_127 ;
F_34 ( V_15 , V_51 ) ;
return V_128 ;
}
if ( ! ( V_114 & V_129 ) )
F_27 ( V_15 , V_51 ) ;
}
if ( V_54 -> V_76 == V_75 && V_17 -> V_89 == 0 )
V_85 -> V_125 |= V_127 ;
F_2 ( 0 , V_15 -> V_20 + V_124 ) ;
F_32 ( & V_15 -> V_119 , V_115 ) ;
F_34 ( V_15 , V_51 ) ;
return V_128 ;
}
static int F_35 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_130 * V_131 ,
unsigned long V_132 )
{
unsigned int V_114 ;
V_114 = F_8 ( V_15 -> V_20 + V_88 ) ;
if ( V_114 & V_133 )
return 0 ;
return - V_134 ;
}
static int F_36 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_130 * V_131 , unsigned int * V_94 )
{
unsigned int V_60 = F_17 ( V_131 -> V_135 ) ;
unsigned int V_61 = F_15 ( V_131 -> V_135 ) ;
unsigned int V_98 = V_51 -> V_98 ;
unsigned int V_99 = ( V_98 + 1 ) >> 1 ;
unsigned int V_100 = ( V_98 == 0xffff ) ? 0 : 4 ;
unsigned int V_114 ;
int V_136 ;
int V_58 ;
F_2 ( V_60 , V_15 -> V_20 + V_86 ) ;
V_114 = F_8 ( V_15 -> V_20 + V_88 ) ;
if ( ( V_114 & V_87 ) != V_61 ) {
F_2 ( V_61 & V_87 ,
V_15 -> V_20 + V_88 ) ;
}
F_12 ( V_15 ) ;
for ( V_58 = 0 ; V_58 < V_131 -> V_137 ; V_58 ++ ) {
F_2 ( 0 , V_15 -> V_20 + V_138 ) ;
V_136 = F_37 ( V_15 , V_51 , V_131 , F_35 , 0 ) ;
if ( V_136 ) {
F_12 ( V_15 ) ;
return V_136 ;
}
V_94 [ V_58 ] = F_38 ( V_15 -> V_20 + V_106 ) ;
V_94 [ V_58 ] = ( ( V_94 [ V_58 ] >> V_100 ) & V_98 ) ^ V_99 ;
}
return V_58 ;
}
static int F_39 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_130 * V_131 ,
unsigned int * V_94 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_139 = 0 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_131 -> V_137 ; V_58 ++ ) {
V_139 = V_94 [ V_58 ] ;
F_40 ( V_139 , V_15 -> V_20 + V_140 ) ;
}
V_17 -> V_141 = V_139 ;
return V_131 -> V_137 ;
}
static int F_41 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_130 * V_131 ,
unsigned int * V_94 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_131 -> V_137 ; V_58 ++ )
V_94 [ V_58 ] = V_17 -> V_141 ;
return V_131 -> V_137 ;
}
static int F_42 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_130 * V_131 ,
unsigned int * V_94 )
{
V_94 [ 1 ] = F_38 ( V_15 -> V_20 + V_142 ) ;
return V_131 -> V_137 ;
}
static int F_43 ( struct V_14 * V_15 ,
struct V_50 * V_51 ,
struct V_130 * V_131 ,
unsigned int * V_94 )
{
if ( F_44 ( V_51 , V_94 ) )
F_40 ( V_51 -> V_143 , V_15 -> V_20 + V_142 ) ;
V_94 [ 1 ] = V_51 -> V_143 ;
return V_131 -> V_137 ;
}
static int F_45 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_52 , true , true , true ,
true , false ) ;
F_7 ( V_15 , V_30 ) ;
F_9 ( V_15 , false ) ;
F_10 ( V_15 , false ) ;
V_17 -> V_26 = 0 ;
V_17 -> V_25 = 0 ;
F_3 ( V_15 ) ;
return 0 ;
}
static int F_46 ( struct V_14 * V_15 ,
unsigned long V_144 )
{
struct V_145 * V_146 = F_47 ( V_15 ) ;
struct V_16 * V_17 ;
struct V_50 * V_51 ;
int V_136 ;
V_17 = F_48 ( V_15 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_147 ;
V_136 = F_49 ( V_15 ) ;
if ( V_136 )
return V_136 ;
V_17 -> V_52 = F_50 ( V_146 , 1 ) ;
V_15 -> V_20 = F_50 ( V_146 , 2 ) ;
F_45 ( V_15 ) ;
if ( V_146 -> V_110 ) {
V_136 = F_51 ( V_146 -> V_110 , F_30 ,
V_148 , V_15 -> V_149 , V_15 ) ;
if ( V_136 == 0 )
V_15 -> V_110 = V_146 -> V_110 ;
}
V_136 = F_52 ( V_15 , 4 ) ;
if ( V_136 )
return V_136 ;
V_51 = & V_15 -> V_150 [ 0 ] ;
V_51 -> type = V_151 ;
V_51 -> V_152 = V_153 | V_154 ;
V_51 -> V_155 = 16 ;
V_51 -> V_98 = 0xffff ;
V_51 -> V_156 = & V_157 ;
V_51 -> V_158 = F_36 ;
if ( V_15 -> V_110 ) {
V_15 -> V_112 = V_51 ;
V_51 -> V_152 |= V_159 ;
V_51 -> V_160 = V_51 -> V_155 ;
V_51 -> V_161 = F_19 ;
V_51 -> V_162 = F_25 ;
V_51 -> V_163 = F_13 ;
V_51 -> V_164 = F_26 ;
}
V_51 = & V_15 -> V_150 [ 1 ] ;
V_51 -> type = V_165 ;
V_51 -> V_152 = V_166 | V_154 ;
V_51 -> V_155 = 1 ;
V_51 -> V_98 = 0x0fff ;
V_51 -> V_160 = 1 ;
V_51 -> V_156 = & V_167 ;
V_51 -> V_168 = F_39 ;
V_51 -> V_158 = F_41 ;
V_51 = & V_15 -> V_150 [ 2 ] ;
V_51 -> type = V_169 ;
V_51 -> V_152 = V_153 ;
V_51 -> V_155 = 16 ;
V_51 -> V_98 = 1 ;
V_51 -> V_156 = & V_170 ;
V_51 -> V_171 = F_42 ;
V_51 = & V_15 -> V_150 [ 3 ] ;
V_51 -> type = V_172 ;
V_51 -> V_152 = V_153 | V_166 ;
V_51 -> V_155 = 16 ;
V_51 -> V_98 = 1 ;
V_51 -> V_156 = & V_170 ;
V_51 -> V_171 = F_43 ;
return 0 ;
}
static void F_53 ( struct V_14 * V_15 )
{
if ( V_15 -> V_20 )
F_45 ( V_15 ) ;
if ( V_15 -> V_110 != 0 )
F_54 ( V_15 -> V_110 , V_15 ) ;
F_55 ( V_15 ) ;
}
static int F_56 ( struct V_145 * V_15 ,
const struct V_173 * V_174 )
{
return F_57 ( V_15 , & V_175 ,
V_174 -> V_176 ) ;
}
