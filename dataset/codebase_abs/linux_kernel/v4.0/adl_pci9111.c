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
V_17 -> V_81 = 0 ;
if ( V_43 -> V_62 == V_59 ) {
V_76 |= V_82 ;
F_3 ( V_15 ) ;
F_9 ( V_15 ) ;
F_7 ( V_15 , V_32 ,
V_83 ) ;
F_1 ( V_17 -> V_41 , true , true ,
false , true , true ) ;
if ( V_43 -> V_58 == V_59 ) {
V_17 -> V_81 = ( V_43 -> V_70 /
( V_43 -> V_68 * V_43 -> V_48 ) ) - 1 ;
}
} else {
V_76 |= V_84 ;
F_9 ( V_15 ) ;
F_7 ( V_15 , V_32 ,
V_83 ) ;
F_1 ( V_17 -> V_41 , true , true ,
false , true , true ) ;
}
F_2 ( V_76 , V_15 -> V_20 + V_31 ) ;
V_17 -> V_85 = 0 ;
V_17 -> V_86 = V_43 -> V_48 *
( 1 + V_17 -> V_81 ) ;
return 0 ;
}
static void F_23 ( struct V_14 * V_15 ,
struct V_39 * V_40 , void * V_87 ,
unsigned int V_88 ,
unsigned int V_89 )
{
unsigned short * V_90 = V_87 ;
unsigned int V_91 = V_40 -> V_91 ;
unsigned int V_92 = ( V_91 + 1 ) >> 1 ;
unsigned int V_93 = ( V_91 == 0xffff ) ? 0 : 4 ;
unsigned int V_94 = F_24 ( V_40 , V_88 ) ;
unsigned int V_47 ;
for ( V_47 = 0 ; V_47 < V_94 ; V_47 ++ )
V_90 [ V_47 ] = ( ( V_90 [ V_47 ] >> V_93 ) & V_91 ) ^ V_92 ;
}
static void F_25 ( struct V_14 * V_15 ,
struct V_39 * V_40 )
{
struct V_16 * V_95 = V_15 -> V_18 ;
struct V_42 * V_43 = & V_40 -> V_74 -> V_43 ;
unsigned int V_96 ;
V_96 = F_26 ( V_40 , V_97 ) ;
F_27 ( V_15 -> V_20 + V_98 ,
V_95 -> V_99 , V_96 ) ;
if ( V_95 -> V_81 < 1 ) {
F_28 ( V_40 , V_95 -> V_99 , V_96 ) ;
} else {
unsigned int V_100 = 0 ;
unsigned int V_101 ;
while ( V_100 < V_96 ) {
if ( V_95 -> V_85 < V_43 -> V_48 ) {
V_101 = V_43 -> V_48 -
V_95 -> V_85 ;
if ( V_101 > V_96 - V_100 )
V_101 = V_96 - V_100 ;
F_28 ( V_40 ,
V_95 -> V_99 + V_100 ,
V_101 ) ;
} else {
V_101 = V_95 -> V_86 -
V_95 -> V_85 ;
if ( V_101 > V_96 - V_100 )
V_101 = V_96 - V_100 ;
}
V_100 += V_101 ;
V_95 -> V_85 += V_101 ;
if ( V_95 -> V_85 >=
V_95 -> V_86 )
V_95 -> V_85 = 0 ;
}
}
}
static T_1 F_29 ( int V_102 , void * V_103 )
{
struct V_14 * V_15 = V_103 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_39 * V_40 = V_15 -> V_104 ;
struct V_105 * V_74 ;
struct V_42 * V_43 ;
unsigned int V_106 ;
unsigned long V_107 ;
unsigned char V_108 ;
if ( ! V_15 -> V_109 ) {
return V_110 ;
}
V_74 = V_40 -> V_74 ;
V_43 = & V_74 -> V_43 ;
F_30 ( & V_15 -> V_111 , V_107 ) ;
V_108 = F_8 ( V_17 -> V_41 + V_13 ) ;
if ( ! ( ( ( V_108 & V_12 ) != 0 ) &&
( ( ( V_108 & V_112 ) == V_112 ) ||
( ( V_108 & V_113 ) == V_113 ) ) ) ) {
F_31 ( & V_15 -> V_111 , V_107 ) ;
return V_110 ;
}
if ( ( V_108 & V_112 ) == V_112 ) {
V_106 = F_8 ( V_15 -> V_20 + V_80 ) ;
if ( ! ( V_106 & V_114 ) ) {
F_31 ( & V_15 -> V_111 , V_107 ) ;
F_15 ( V_15 -> V_52 , L_4 ) ;
F_2 ( 0 , V_15 -> V_20 + V_115 ) ;
V_74 -> V_116 |= V_117 ;
F_32 ( V_15 , V_40 ) ;
return V_118 ;
}
if ( ! ( V_106 & V_119 ) )
F_25 ( V_15 , V_40 ) ;
}
if ( V_43 -> V_65 == V_64 && V_74 -> V_120 >= V_43 -> V_72 )
V_74 -> V_116 |= V_121 ;
F_2 ( 0 , V_15 -> V_20 + V_115 ) ;
F_31 ( & V_15 -> V_111 , V_107 ) ;
F_32 ( V_15 , V_40 ) ;
return V_118 ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_122 * V_123 ,
unsigned long V_124 )
{
unsigned int V_106 ;
V_106 = F_8 ( V_15 -> V_20 + V_80 ) ;
if ( V_106 & V_125 )
return 0 ;
return - V_126 ;
}
static int F_34 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_122 * V_123 , unsigned int * V_87 )
{
unsigned int V_49 = F_14 ( V_123 -> V_127 ) ;
unsigned int V_50 = F_12 ( V_123 -> V_127 ) ;
unsigned int V_91 = V_40 -> V_91 ;
unsigned int V_92 = ( V_91 + 1 ) >> 1 ;
unsigned int V_93 = ( V_91 == 0xffff ) ? 0 : 4 ;
unsigned int V_106 ;
int V_128 ;
int V_47 ;
F_2 ( V_49 , V_15 -> V_20 + V_78 ) ;
V_106 = F_8 ( V_15 -> V_20 + V_80 ) ;
if ( ( V_106 & V_79 ) != V_50 ) {
F_2 ( V_50 & V_79 ,
V_15 -> V_20 + V_80 ) ;
}
F_9 ( V_15 ) ;
for ( V_47 = 0 ; V_47 < V_123 -> V_129 ; V_47 ++ ) {
F_2 ( 0 , V_15 -> V_20 + V_130 ) ;
V_128 = F_35 ( V_15 , V_40 , V_123 , F_33 , 0 ) ;
if ( V_128 ) {
F_9 ( V_15 ) ;
return V_128 ;
}
V_87 [ V_47 ] = F_36 ( V_15 -> V_20 + V_98 ) ;
V_87 [ V_47 ] = ( ( V_87 [ V_47 ] >> V_93 ) & V_91 ) ^ V_92 ;
}
return V_47 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_122 * V_123 ,
unsigned int * V_87 )
{
unsigned int V_49 = F_14 ( V_123 -> V_127 ) ;
unsigned int V_131 = V_40 -> V_132 [ V_49 ] ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_123 -> V_129 ; V_47 ++ ) {
V_131 = V_87 [ V_47 ] ;
F_38 ( V_131 , V_15 -> V_20 + V_133 ) ;
}
V_40 -> V_132 [ V_49 ] = V_131 ;
return V_123 -> V_129 ;
}
static int F_39 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_122 * V_123 ,
unsigned int * V_87 )
{
V_87 [ 1 ] = F_36 ( V_15 -> V_20 + V_134 ) ;
return V_123 -> V_129 ;
}
static int F_40 ( struct V_14 * V_15 ,
struct V_39 * V_40 ,
struct V_122 * V_123 ,
unsigned int * V_87 )
{
if ( F_41 ( V_40 , V_87 ) )
F_38 ( V_40 -> V_135 , V_15 -> V_20 + V_134 ) ;
V_87 [ 1 ] = V_40 -> V_135 ;
return V_123 -> V_129 ;
}
static int F_42 ( struct V_14 * V_15 )
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
static int F_43 ( struct V_14 * V_15 ,
unsigned long V_136 )
{
struct V_137 * V_138 = F_44 ( V_15 ) ;
struct V_16 * V_17 ;
struct V_39 * V_40 ;
int V_128 ;
V_17 = F_45 ( V_15 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_139 ;
V_128 = F_46 ( V_15 ) ;
if ( V_128 )
return V_128 ;
V_17 -> V_41 = F_47 ( V_138 , 1 ) ;
V_15 -> V_20 = F_47 ( V_138 , 2 ) ;
F_42 ( V_15 ) ;
if ( V_138 -> V_102 ) {
V_128 = F_48 ( V_138 -> V_102 , F_29 ,
V_140 , V_15 -> V_141 , V_15 ) ;
if ( V_128 == 0 )
V_15 -> V_102 = V_138 -> V_102 ;
}
V_128 = F_49 ( V_15 , 4 ) ;
if ( V_128 )
return V_128 ;
V_40 = & V_15 -> V_142 [ 0 ] ;
V_40 -> type = V_143 ;
V_40 -> V_144 = V_145 | V_146 ;
V_40 -> V_147 = 16 ;
V_40 -> V_91 = 0xffff ;
V_40 -> V_148 = & V_149 ;
V_40 -> V_150 = F_34 ;
if ( V_15 -> V_102 ) {
V_15 -> V_104 = V_40 ;
V_40 -> V_144 |= V_151 ;
V_40 -> V_152 = V_40 -> V_147 ;
V_40 -> V_153 = F_16 ;
V_40 -> V_154 = F_22 ;
V_40 -> V_155 = F_10 ;
V_40 -> V_156 = F_23 ;
}
V_40 = & V_15 -> V_142 [ 1 ] ;
V_40 -> type = V_157 ;
V_40 -> V_144 = V_158 | V_146 ;
V_40 -> V_147 = 1 ;
V_40 -> V_91 = 0x0fff ;
V_40 -> V_152 = 1 ;
V_40 -> V_148 = & V_159 ;
V_40 -> V_160 = F_37 ;
V_128 = F_50 ( V_40 ) ;
if ( V_128 )
return V_128 ;
V_40 = & V_15 -> V_142 [ 2 ] ;
V_40 -> type = V_161 ;
V_40 -> V_144 = V_145 ;
V_40 -> V_147 = 16 ;
V_40 -> V_91 = 1 ;
V_40 -> V_148 = & V_162 ;
V_40 -> V_163 = F_39 ;
V_40 = & V_15 -> V_142 [ 3 ] ;
V_40 -> type = V_164 ;
V_40 -> V_144 = V_158 ;
V_40 -> V_147 = 16 ;
V_40 -> V_91 = 1 ;
V_40 -> V_148 = & V_162 ;
V_40 -> V_163 = F_40 ;
return 0 ;
}
static void F_51 ( struct V_14 * V_15 )
{
if ( V_15 -> V_20 )
F_42 ( V_15 ) ;
F_52 ( V_15 ) ;
}
static int F_53 ( struct V_137 * V_15 ,
const struct V_165 * V_166 )
{
return F_54 ( V_15 , & V_167 ,
V_166 -> V_168 ) ;
}
