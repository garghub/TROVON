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
enum V_27 V_28 ,
enum V_29 V_30 )
{
int V_7 ;
V_7 = F_8 ( V_15 -> V_20 + V_31 ) ;
V_7 >>= 4 ;
V_7 &= 0xc0 ;
if ( V_28 == V_32 )
V_7 |= V_33 ;
if ( V_30 == V_34 )
V_7 |= V_35 ;
F_2 ( V_7 , V_15 -> V_20 + V_36 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
unsigned long V_37 = V_15 -> V_20 + V_36 ;
F_2 ( 0 , V_37 ) ;
F_2 ( V_38 , V_37 ) ;
F_2 ( 0 , V_37 ) ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_39 * V_40 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_41 , true , true , true ,
true , false ) ;
F_2 ( 0 , V_15 -> V_20 + V_31 ) ;
F_9 ( V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_42 * V_43 )
{
unsigned int V_44 = F_12 ( V_43 -> V_45 [ 0 ] ) ;
unsigned int V_46 = F_13 ( V_43 -> V_45 [ 0 ] ) ;
int V_47 ;
for ( V_47 = 1 ; V_47 < V_43 -> V_48 ; V_47 ++ ) {
unsigned int V_49 = F_14 ( V_43 -> V_45 [ V_47 ] ) ;
unsigned int V_50 = F_12 ( V_43 -> V_45 [ V_47 ] ) ;
unsigned int V_51 = F_13 ( V_43 -> V_45 [ V_47 ] ) ;
if ( V_49 != V_47 ) {
F_15 ( V_15 -> V_52 ,
L_1 ) ;
return - V_53 ;
}
if ( V_50 != V_44 ) {
F_15 ( V_15 -> V_52 ,
L_2 ) ;
return - V_53 ;
}
if ( V_51 != V_46 ) {
F_15 ( V_15 -> V_52 ,
L_3 ) ;
return - V_53 ;
}
}
return 0 ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_42 * V_43 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_54 = 0 ;
unsigned int V_55 ;
V_54 |= F_17 ( & V_43 -> V_56 , V_57 ) ;
V_54 |= F_17 ( & V_43 -> V_58 ,
V_59 | V_60 | V_61 ) ;
V_54 |= F_17 ( & V_43 -> V_62 ,
V_59 | V_61 ) ;
V_54 |= F_17 ( & V_43 -> V_63 , V_64 ) ;
V_54 |= F_17 ( & V_43 -> V_65 ,
V_64 | V_66 ) ;
if ( V_54 )
return 1 ;
V_54 |= F_18 ( V_43 -> V_58 ) ;
V_54 |= F_18 ( V_43 -> V_62 ) ;
V_54 |= F_18 ( V_43 -> V_65 ) ;
if ( V_43 -> V_58 != V_60 ) {
if ( V_43 -> V_58 != V_43 -> V_62 )
V_54 |= - V_53 ;
}
if ( V_54 )
return 2 ;
V_54 |= F_19 ( & V_43 -> V_67 , 0 ) ;
if ( V_43 -> V_62 == V_59 )
V_54 |= F_20 ( & V_43 -> V_68 ,
V_69 ) ;
else
V_54 |= F_19 ( & V_43 -> V_68 , 0 ) ;
if ( V_43 -> V_58 == V_59 )
V_54 |= F_20 ( & V_43 -> V_70 ,
V_69 ) ;
else
V_54 |= F_19 ( & V_43 -> V_70 , 0 ) ;
V_54 |= F_19 ( & V_43 -> V_71 , V_43 -> V_48 ) ;
if ( V_43 -> V_65 == V_64 )
V_54 |= F_20 ( & V_43 -> V_72 , 1 ) ;
else
V_54 |= F_19 ( & V_43 -> V_72 , 0 ) ;
if ( V_54 )
return 3 ;
if ( V_43 -> V_62 == V_59 ) {
V_55 = V_43 -> V_68 ;
F_21 ( V_73 ,
& V_17 -> V_26 ,
& V_17 -> V_25 ,
& V_55 , V_43 -> V_7 ) ;
V_54 |= F_19 ( & V_43 -> V_68 , V_55 ) ;
}
if ( V_43 -> V_58 == V_59 ) {
V_55 = V_43 -> V_48 * V_43 -> V_68 ;
if ( V_55 < V_43 -> V_70 )
V_55 *= ( V_43 -> V_70 / V_55 ) ;
V_54 |= F_19 ( & V_43 -> V_70 , V_55 ) ;
}
if ( V_54 )
return 4 ;
if ( V_43 -> V_45 && V_43 -> V_48 > 0 )
V_54 |= F_11 ( V_15 , V_40 , V_43 ) ;
if ( V_54 )
return 5 ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_39 * V_40 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_42 * V_43 = & V_40 -> V_74 -> V_43 ;
unsigned int V_75 = F_14 ( V_43 -> V_45 [ V_43 -> V_48 - 1 ] ) ;
unsigned int V_76 = 0 ;
if ( V_43 -> V_48 > 1 )
V_76 |= V_77 ;
F_2 ( V_75 , V_15 -> V_20 + V_78 ) ;
F_2 ( F_12 ( V_43 -> V_45 [ 0 ] ) & V_79 ,
V_15 -> V_20 + V_80 ) ;
if ( V_43 -> V_65 == V_64 )
V_17 -> V_81 = V_43 -> V_72 * V_43 -> V_48 ;
else
V_17 -> V_81 = 0 ;
V_17 -> V_82 = 0 ;
if ( V_43 -> V_62 == V_59 ) {
V_76 |= V_83 ;
F_3 ( V_15 ) ;
F_9 ( V_15 ) ;
F_7 ( V_15 , V_32 ,
V_84 ) ;
F_1 ( V_17 -> V_41 , true , true ,
false , true , true ) ;
if ( V_43 -> V_58 == V_59 ) {
V_17 -> V_82 = ( V_43 -> V_70 /
( V_43 -> V_68 * V_43 -> V_48 ) ) - 1 ;
}
} else {
V_76 |= V_85 ;
F_9 ( V_15 ) ;
F_7 ( V_15 , V_32 ,
V_84 ) ;
F_1 ( V_17 -> V_41 , true , true ,
false , true , true ) ;
}
F_2 ( V_76 , V_15 -> V_20 + V_31 ) ;
V_17 -> V_81 *= ( 1 + V_17 -> V_82 ) ;
V_17 -> V_86 = 0 ;
V_17 -> V_87 = V_43 -> V_48 *
( 1 + V_17 -> V_82 ) ;
return 0 ;
}
static void F_23 ( struct V_14 * V_15 ,
struct V_39 * V_40 , void * V_88 ,
unsigned int V_89 ,
unsigned int V_90 )
{
unsigned short * V_91 = V_88 ;
unsigned int V_92 = V_40 -> V_92 ;
unsigned int V_93 = ( V_92 + 1 ) >> 1 ;
unsigned int V_94 = ( V_92 == 0xffff ) ? 0 : 4 ;
unsigned int V_95 = V_89 / sizeof( short ) ;
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < V_95 ; V_47 ++ )
V_91 [ V_47 ] = ( ( V_91 [ V_47 ] >> V_94 ) & V_92 ) ^ V_93 ;
}
static void F_24 ( struct V_14 * V_15 ,
struct V_39 * V_40 )
{
struct V_16 * V_96 = V_15 -> V_18 ;
struct V_42 * V_43 = & V_40 -> V_74 -> V_43 ;
unsigned int V_97 = 0 ;
unsigned int V_98 ;
if ( V_43 -> V_65 == V_64 &&
V_99 > V_96 -> V_81 )
V_98 = V_96 -> V_81 ;
else
V_98 = V_99 ;
F_25 ( V_15 -> V_20 + V_100 ,
V_96 -> V_101 , V_98 ) ;
if ( V_96 -> V_82 < 1 ) {
V_97 = F_26 ( V_40 ,
V_96 -> V_101 ,
V_98 * sizeof( short ) ) ;
} else {
unsigned int V_102 = 0 ;
unsigned int V_103 ;
while ( V_102 < V_98 ) {
if ( V_96 -> V_86 < V_43 -> V_48 ) {
V_103 = V_43 -> V_48 -
V_96 -> V_86 ;
if ( V_103 > V_98 - V_102 )
V_103 = V_98 - V_102 ;
V_97 += F_26 ( V_40 ,
V_96 -> V_101 + V_102 ,
V_103 * sizeof( short ) ) ;
} else {
V_103 = V_96 -> V_87 -
V_96 -> V_86 ;
if ( V_103 > V_98 - V_102 )
V_103 = V_98 - V_102 ;
V_97 += V_103 * sizeof( short ) ;
}
V_102 += V_103 ;
V_96 -> V_86 += V_103 ;
if ( V_96 -> V_86 >=
V_96 -> V_87 )
V_96 -> V_86 = 0 ;
}
}
V_96 -> V_81 -= V_97 / sizeof( short ) ;
}
static T_1 F_27 ( int V_104 , void * V_105 )
{
struct V_14 * V_15 = V_105 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_39 * V_40 = V_15 -> V_106 ;
struct V_107 * V_74 ;
struct V_42 * V_43 ;
unsigned int V_108 ;
unsigned long V_109 ;
unsigned char V_110 ;
if ( ! V_15 -> V_111 ) {
return V_112 ;
}
V_74 = V_40 -> V_74 ;
V_43 = & V_74 -> V_43 ;
F_28 ( & V_15 -> V_113 , V_109 ) ;
V_110 = F_8 ( V_17 -> V_41 + V_13 ) ;
if ( ! ( ( ( V_110 & V_12 ) != 0 ) &&
( ( ( V_110 & V_114 ) == V_114 ) ||
( ( V_110 & V_115 ) == V_115 ) ) ) ) {
F_29 ( & V_15 -> V_113 , V_109 ) ;
return V_112 ;
}
if ( ( V_110 & V_114 ) == V_114 ) {
V_108 = F_8 ( V_15 -> V_20 + V_80 ) ;
if ( ! ( V_108 & V_116 ) ) {
F_29 ( & V_15 -> V_113 , V_109 ) ;
F_15 ( V_15 -> V_52 , L_4 ) ;
F_2 ( 0 , V_15 -> V_20 + V_117 ) ;
V_74 -> V_118 |= V_119 | V_120 ;
F_30 ( V_15 , V_40 ) ;
return V_121 ;
}
if ( ! ( V_108 & V_122 ) )
F_24 ( V_15 , V_40 ) ;
}
if ( V_43 -> V_65 == V_64 && V_17 -> V_81 == 0 )
V_74 -> V_118 |= V_120 ;
F_2 ( 0 , V_15 -> V_20 + V_117 ) ;
F_29 ( & V_15 -> V_113 , V_109 ) ;
F_30 ( V_15 , V_40 ) ;
return V_121 ;
}
static int F_31 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_123 * V_124 ,
unsigned long V_125 )
{
unsigned int V_108 ;
V_108 = F_8 ( V_15 -> V_20 + V_80 ) ;
if ( V_108 & V_126 )
return 0 ;
return - V_127 ;
}
static int F_32 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_123 * V_124 , unsigned int * V_88 )
{
unsigned int V_49 = F_14 ( V_124 -> V_128 ) ;
unsigned int V_50 = F_12 ( V_124 -> V_128 ) ;
unsigned int V_92 = V_40 -> V_92 ;
unsigned int V_93 = ( V_92 + 1 ) >> 1 ;
unsigned int V_94 = ( V_92 == 0xffff ) ? 0 : 4 ;
unsigned int V_108 ;
int V_129 ;
int V_47 ;
F_2 ( V_49 , V_15 -> V_20 + V_78 ) ;
V_108 = F_8 ( V_15 -> V_20 + V_80 ) ;
if ( ( V_108 & V_79 ) != V_50 ) {
F_2 ( V_50 & V_79 ,
V_15 -> V_20 + V_80 ) ;
}
F_9 ( V_15 ) ;
for ( V_47 = 0 ; V_47 < V_124 -> V_130 ; V_47 ++ ) {
F_2 ( 0 , V_15 -> V_20 + V_131 ) ;
V_129 = F_33 ( V_15 , V_40 , V_124 , F_31 , 0 ) ;
if ( V_129 ) {
F_9 ( V_15 ) ;
return V_129 ;
}
V_88 [ V_47 ] = F_34 ( V_15 -> V_20 + V_100 ) ;
V_88 [ V_47 ] = ( ( V_88 [ V_47 ] >> V_94 ) & V_92 ) ^ V_93 ;
}
return V_47 ;
}
static int F_35 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_123 * V_124 ,
unsigned int * V_88 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_132 = 0 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_124 -> V_130 ; V_47 ++ ) {
V_132 = V_88 [ V_47 ] ;
F_36 ( V_132 , V_15 -> V_20 + V_133 ) ;
}
V_17 -> V_134 = V_132 ;
return V_124 -> V_130 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_123 * V_124 ,
unsigned int * V_88 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_124 -> V_130 ; V_47 ++ )
V_88 [ V_47 ] = V_17 -> V_134 ;
return V_124 -> V_130 ;
}
static int F_38 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_123 * V_124 ,
unsigned int * V_88 )
{
V_88 [ 1 ] = F_34 ( V_15 -> V_20 + V_135 ) ;
return V_124 -> V_130 ;
}
static int F_39 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_123 * V_124 ,
unsigned int * V_88 )
{
if ( F_40 ( V_40 , V_88 ) )
F_36 ( V_40 -> V_136 , V_15 -> V_20 + V_135 ) ;
V_88 [ 1 ] = V_40 -> V_136 ;
return V_124 -> V_130 ;
}
static int F_41 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_1 ( V_17 -> V_41 , true , true , true ,
true , false ) ;
F_2 ( 0 , V_15 -> V_20 + V_31 ) ;
V_17 -> V_26 = 0 ;
V_17 -> V_25 = 0 ;
F_3 ( V_15 ) ;
return 0 ;
}
static int F_42 ( struct V_14 * V_15 ,
unsigned long V_137 )
{
struct V_138 * V_139 = F_43 ( V_15 ) ;
struct V_16 * V_17 ;
struct V_39 * V_40 ;
int V_129 ;
V_17 = F_44 ( V_15 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_140 ;
V_129 = F_45 ( V_15 ) ;
if ( V_129 )
return V_129 ;
V_17 -> V_41 = F_46 ( V_139 , 1 ) ;
V_15 -> V_20 = F_46 ( V_139 , 2 ) ;
F_41 ( V_15 ) ;
if ( V_139 -> V_104 ) {
V_129 = F_47 ( V_139 -> V_104 , F_27 ,
V_141 , V_15 -> V_142 , V_15 ) ;
if ( V_129 == 0 )
V_15 -> V_104 = V_139 -> V_104 ;
}
V_129 = F_48 ( V_15 , 4 ) ;
if ( V_129 )
return V_129 ;
V_40 = & V_15 -> V_143 [ 0 ] ;
V_40 -> type = V_144 ;
V_40 -> V_145 = V_146 | V_147 ;
V_40 -> V_148 = 16 ;
V_40 -> V_92 = 0xffff ;
V_40 -> V_149 = & V_150 ;
V_40 -> V_151 = F_32 ;
if ( V_15 -> V_104 ) {
V_15 -> V_106 = V_40 ;
V_40 -> V_145 |= V_152 ;
V_40 -> V_153 = V_40 -> V_148 ;
V_40 -> V_154 = F_16 ;
V_40 -> V_155 = F_22 ;
V_40 -> V_156 = F_10 ;
V_40 -> V_157 = F_23 ;
}
V_40 = & V_15 -> V_143 [ 1 ] ;
V_40 -> type = V_158 ;
V_40 -> V_145 = V_159 | V_147 ;
V_40 -> V_148 = 1 ;
V_40 -> V_92 = 0x0fff ;
V_40 -> V_153 = 1 ;
V_40 -> V_149 = & V_160 ;
V_40 -> V_161 = F_35 ;
V_40 -> V_151 = F_37 ;
V_40 = & V_15 -> V_143 [ 2 ] ;
V_40 -> type = V_162 ;
V_40 -> V_145 = V_146 ;
V_40 -> V_148 = 16 ;
V_40 -> V_92 = 1 ;
V_40 -> V_149 = & V_163 ;
V_40 -> V_164 = F_38 ;
V_40 = & V_15 -> V_143 [ 3 ] ;
V_40 -> type = V_165 ;
V_40 -> V_145 = V_146 | V_159 ;
V_40 -> V_148 = 16 ;
V_40 -> V_92 = 1 ;
V_40 -> V_149 = & V_163 ;
V_40 -> V_164 = F_39 ;
return 0 ;
}
static void F_49 ( struct V_14 * V_15 )
{
if ( V_15 -> V_20 )
F_41 ( V_15 ) ;
if ( V_15 -> V_104 != 0 )
F_50 ( V_15 -> V_104 , V_15 ) ;
F_51 ( V_15 ) ;
}
static int F_52 ( struct V_138 * V_15 ,
const struct V_166 * V_167 )
{
return F_53 ( V_15 , & V_168 ,
V_167 -> V_169 ) ;
}
