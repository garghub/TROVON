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
static void F_3 ( struct V_14 * V_15 ,
enum V_16 V_17 ,
enum V_18 V_19 )
{
int V_7 ;
V_7 = F_4 ( V_15 -> V_20 + V_21 ) ;
V_7 >>= 4 ;
V_7 &= 0xc0 ;
if ( V_17 == V_22 )
V_7 |= V_23 ;
if ( V_19 == V_24 )
V_7 |= V_25 ;
F_2 ( V_7 , V_15 -> V_20 + V_26 ) ;
}
static void F_5 ( struct V_14 * V_15 )
{
unsigned long V_27 = V_15 -> V_20 + V_26 ;
F_2 ( 0 , V_27 ) ;
F_2 ( V_28 , V_27 ) ;
F_2 ( 0 , V_27 ) ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
F_1 ( V_32 -> V_34 , true , true , true ,
true , false ) ;
F_2 ( 0 , V_15 -> V_20 + V_21 ) ;
F_5 ( V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_35 * V_36 )
{
unsigned int V_37 = F_8 ( V_36 -> V_38 [ 0 ] ) ;
unsigned int V_39 = F_9 ( V_36 -> V_38 [ 0 ] ) ;
int V_40 ;
for ( V_40 = 1 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
unsigned int V_42 = F_10 ( V_36 -> V_38 [ V_40 ] ) ;
unsigned int V_43 = F_8 ( V_36 -> V_38 [ V_40 ] ) ;
unsigned int V_44 = F_9 ( V_36 -> V_38 [ V_40 ] ) ;
if ( V_42 != V_40 ) {
F_11 ( V_15 -> V_45 ,
L_1 ) ;
return - V_46 ;
}
if ( V_43 != V_37 ) {
F_11 ( V_15 -> V_45 ,
L_2 ) ;
return - V_46 ;
}
if ( V_44 != V_39 ) {
F_11 ( V_15 -> V_45 ,
L_3 ) ;
return - V_46 ;
}
}
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_35 * V_36 )
{
int V_47 = 0 ;
unsigned int V_48 ;
V_47 |= F_13 ( & V_36 -> V_49 , V_50 ) ;
V_47 |= F_13 ( & V_36 -> V_51 ,
V_52 | V_53 | V_54 ) ;
V_47 |= F_13 ( & V_36 -> V_55 ,
V_52 | V_54 ) ;
V_47 |= F_13 ( & V_36 -> V_56 , V_57 ) ;
V_47 |= F_13 ( & V_36 -> V_58 ,
V_57 | V_59 ) ;
if ( V_47 )
return 1 ;
V_47 |= F_14 ( V_36 -> V_51 ) ;
V_47 |= F_14 ( V_36 -> V_55 ) ;
V_47 |= F_14 ( V_36 -> V_58 ) ;
if ( V_36 -> V_51 != V_53 ) {
if ( V_36 -> V_51 != V_36 -> V_55 )
V_47 |= - V_46 ;
}
if ( V_47 )
return 2 ;
V_47 |= F_15 ( & V_36 -> V_60 , 0 ) ;
if ( V_36 -> V_55 == V_52 ) {
V_47 |= F_16 ( & V_36 -> V_61 ,
V_62 ) ;
} else {
V_47 |= F_15 ( & V_36 -> V_61 , 0 ) ;
}
if ( V_36 -> V_51 == V_52 ) {
V_47 |= F_16 ( & V_36 -> V_63 ,
V_62 ) ;
} else {
V_47 |= F_15 ( & V_36 -> V_63 , 0 ) ;
}
V_47 |= F_15 ( & V_36 -> V_64 ,
V_36 -> V_41 ) ;
if ( V_36 -> V_58 == V_57 )
V_47 |= F_16 ( & V_36 -> V_65 , 1 ) ;
else
V_47 |= F_15 ( & V_36 -> V_65 , 0 ) ;
if ( V_47 )
return 3 ;
if ( V_36 -> V_55 == V_52 ) {
V_48 = V_36 -> V_61 ;
F_17 ( V_15 -> V_66 , & V_48 , V_36 -> V_7 ) ;
V_47 |= F_15 ( & V_36 -> V_61 , V_48 ) ;
}
if ( V_36 -> V_51 == V_52 ) {
V_48 = V_36 -> V_41 * V_36 -> V_61 ;
if ( V_48 < V_36 -> V_63 )
V_48 *= ( V_36 -> V_63 / V_48 ) ;
V_47 |= F_15 ( & V_36 -> V_63 , V_48 ) ;
}
if ( V_47 )
return 4 ;
if ( V_36 -> V_38 && V_36 -> V_41 > 0 )
V_47 |= F_7 ( V_15 , V_30 , V_36 ) ;
if ( V_47 )
return 5 ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_35 * V_36 = & V_30 -> V_67 -> V_36 ;
unsigned int V_68 = F_10 ( V_36 -> V_38 [ V_36 -> V_41 - 1 ] ) ;
unsigned int V_69 = 0 ;
if ( V_36 -> V_41 > 1 )
V_69 |= V_70 ;
F_2 ( V_68 , V_15 -> V_20 + V_71 ) ;
F_2 ( F_8 ( V_36 -> V_38 [ 0 ] ) & V_72 ,
V_15 -> V_20 + V_73 ) ;
V_32 -> V_74 = 0 ;
if ( V_36 -> V_55 == V_52 ) {
V_69 |= V_75 ;
F_19 ( V_15 -> V_66 ) ;
F_20 ( V_15 -> V_66 , 1 , 2 , true ) ;
F_5 ( V_15 ) ;
F_3 ( V_15 , V_22 ,
V_76 ) ;
F_1 ( V_32 -> V_34 , true , true ,
false , true , true ) ;
if ( V_36 -> V_51 == V_52 ) {
V_32 -> V_74 = ( V_36 -> V_63 /
( V_36 -> V_61 * V_36 -> V_41 ) ) - 1 ;
}
} else {
V_69 |= V_77 ;
F_5 ( V_15 ) ;
F_3 ( V_15 , V_22 ,
V_76 ) ;
F_1 ( V_32 -> V_34 , true , true ,
false , true , true ) ;
}
F_2 ( V_69 , V_15 -> V_20 + V_21 ) ;
V_32 -> V_78 = 0 ;
V_32 -> V_79 = V_36 -> V_41 *
( 1 + V_32 -> V_74 ) ;
return 0 ;
}
static void F_21 ( struct V_14 * V_15 ,
struct V_29 * V_30 , void * V_80 ,
unsigned int V_81 ,
unsigned int V_82 )
{
unsigned short * V_83 = V_80 ;
unsigned int V_84 = V_30 -> V_84 ;
unsigned int V_85 = ( V_84 + 1 ) >> 1 ;
unsigned int V_86 = ( V_84 == 0xffff ) ? 0 : 4 ;
unsigned int V_87 = F_22 ( V_30 , V_81 ) ;
unsigned int V_40 ;
for ( V_40 = 0 ; V_40 < V_87 ; V_40 ++ )
V_83 [ V_40 ] = ( ( V_83 [ V_40 ] >> V_86 ) & V_84 ) ^ V_85 ;
}
static void F_23 ( struct V_14 * V_15 ,
struct V_29 * V_30 )
{
struct V_31 * V_88 = V_15 -> V_33 ;
struct V_35 * V_36 = & V_30 -> V_67 -> V_36 ;
unsigned int V_89 ;
V_89 = F_24 ( V_30 , V_90 ) ;
F_25 ( V_15 -> V_20 + V_91 ,
V_88 -> V_92 , V_89 ) ;
if ( V_88 -> V_74 < 1 ) {
F_26 ( V_30 , V_88 -> V_92 , V_89 ) ;
} else {
unsigned int V_93 = 0 ;
unsigned int V_94 ;
while ( V_93 < V_89 ) {
if ( V_88 -> V_78 < V_36 -> V_41 ) {
V_94 = V_36 -> V_41 -
V_88 -> V_78 ;
if ( V_94 > V_89 - V_93 )
V_94 = V_89 - V_93 ;
F_26 ( V_30 ,
V_88 -> V_92 + V_93 ,
V_94 ) ;
} else {
V_94 = V_88 -> V_79 -
V_88 -> V_78 ;
if ( V_94 > V_89 - V_93 )
V_94 = V_89 - V_93 ;
}
V_93 += V_94 ;
V_88 -> V_78 += V_94 ;
if ( V_88 -> V_78 >=
V_88 -> V_79 )
V_88 -> V_78 = 0 ;
}
}
}
static T_1 F_27 ( int V_95 , void * V_96 )
{
struct V_14 * V_15 = V_96 ;
struct V_31 * V_32 = V_15 -> V_33 ;
struct V_29 * V_30 = V_15 -> V_97 ;
struct V_98 * V_67 ;
struct V_35 * V_36 ;
unsigned int V_99 ;
unsigned long V_100 ;
unsigned char V_101 ;
if ( ! V_15 -> V_102 ) {
return V_103 ;
}
V_67 = V_30 -> V_67 ;
V_36 = & V_67 -> V_36 ;
F_28 ( & V_15 -> V_104 , V_100 ) ;
V_101 = F_4 ( V_32 -> V_34 + V_13 ) ;
if ( ! ( ( ( V_101 & V_12 ) != 0 ) &&
( ( ( V_101 & V_105 ) == V_105 ) ||
( ( V_101 & V_106 ) == V_106 ) ) ) ) {
F_29 ( & V_15 -> V_104 , V_100 ) ;
return V_103 ;
}
if ( ( V_101 & V_105 ) == V_105 ) {
V_99 = F_4 ( V_15 -> V_20 + V_73 ) ;
if ( ! ( V_99 & V_107 ) ) {
F_29 ( & V_15 -> V_104 , V_100 ) ;
F_11 ( V_15 -> V_45 , L_4 ) ;
F_2 ( 0 , V_15 -> V_20 + V_108 ) ;
V_67 -> V_109 |= V_110 ;
F_30 ( V_15 , V_30 ) ;
return V_111 ;
}
if ( ! ( V_99 & V_112 ) )
F_23 ( V_15 , V_30 ) ;
}
if ( V_36 -> V_58 == V_57 && V_67 -> V_113 >= V_36 -> V_65 )
V_67 -> V_109 |= V_114 ;
F_2 ( 0 , V_15 -> V_20 + V_108 ) ;
F_29 ( & V_15 -> V_104 , V_100 ) ;
F_30 ( V_15 , V_30 ) ;
return V_111 ;
}
static int F_31 ( struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_115 * V_116 ,
unsigned long V_117 )
{
unsigned int V_99 ;
V_99 = F_4 ( V_15 -> V_20 + V_73 ) ;
if ( V_99 & V_118 )
return 0 ;
return - V_119 ;
}
static int F_32 ( struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_115 * V_116 , unsigned int * V_80 )
{
unsigned int V_42 = F_10 ( V_116 -> V_120 ) ;
unsigned int V_43 = F_8 ( V_116 -> V_120 ) ;
unsigned int V_84 = V_30 -> V_84 ;
unsigned int V_85 = ( V_84 + 1 ) >> 1 ;
unsigned int V_86 = ( V_84 == 0xffff ) ? 0 : 4 ;
unsigned int V_99 ;
int V_121 ;
int V_40 ;
F_2 ( V_42 , V_15 -> V_20 + V_71 ) ;
V_99 = F_4 ( V_15 -> V_20 + V_73 ) ;
if ( ( V_99 & V_72 ) != V_43 ) {
F_2 ( V_43 & V_72 ,
V_15 -> V_20 + V_73 ) ;
}
F_5 ( V_15 ) ;
for ( V_40 = 0 ; V_40 < V_116 -> V_122 ; V_40 ++ ) {
F_2 ( 0 , V_15 -> V_20 + V_123 ) ;
V_121 = F_33 ( V_15 , V_30 , V_116 , F_31 , 0 ) ;
if ( V_121 ) {
F_5 ( V_15 ) ;
return V_121 ;
}
V_80 [ V_40 ] = F_34 ( V_15 -> V_20 + V_91 ) ;
V_80 [ V_40 ] = ( ( V_80 [ V_40 ] >> V_86 ) & V_84 ) ^ V_85 ;
}
return V_40 ;
}
static int F_35 ( struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_115 * V_116 ,
unsigned int * V_80 )
{
unsigned int V_42 = F_10 ( V_116 -> V_120 ) ;
unsigned int V_124 = V_30 -> V_125 [ V_42 ] ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_116 -> V_122 ; V_40 ++ ) {
V_124 = V_80 [ V_40 ] ;
F_36 ( V_124 , V_15 -> V_20 + V_126 ) ;
}
V_30 -> V_125 [ V_42 ] = V_124 ;
return V_116 -> V_122 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_115 * V_116 ,
unsigned int * V_80 )
{
V_80 [ 1 ] = F_34 ( V_15 -> V_20 + V_127 ) ;
return V_116 -> V_122 ;
}
static int F_38 ( struct V_14 * V_15 ,
struct V_29 * V_30 ,
struct V_115 * V_116 ,
unsigned int * V_80 )
{
if ( F_39 ( V_30 , V_80 ) )
F_36 ( V_30 -> V_128 , V_15 -> V_20 + V_127 ) ;
V_80 [ 1 ] = V_30 -> V_128 ;
return V_116 -> V_122 ;
}
static int F_40 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = V_15 -> V_33 ;
F_1 ( V_32 -> V_34 , true , true , true ,
true , false ) ;
F_2 ( 0 , V_15 -> V_20 + V_21 ) ;
return 0 ;
}
static int F_41 ( struct V_14 * V_15 ,
unsigned long V_129 )
{
struct V_130 * V_131 = F_42 ( V_15 ) ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
int V_121 ;
V_32 = F_43 ( V_15 , sizeof( * V_32 ) ) ;
if ( ! V_32 )
return - V_132 ;
V_121 = F_44 ( V_15 ) ;
if ( V_121 )
return V_121 ;
V_32 -> V_34 = F_45 ( V_131 , 1 ) ;
V_15 -> V_20 = F_45 ( V_131 , 2 ) ;
F_40 ( V_15 ) ;
if ( V_131 -> V_95 ) {
V_121 = F_46 ( V_131 -> V_95 , F_27 ,
V_133 , V_15 -> V_134 , V_15 ) ;
if ( V_121 == 0 )
V_15 -> V_95 = V_131 -> V_95 ;
}
V_15 -> V_66 = F_47 ( V_15 -> V_20 + V_135 ,
V_136 , V_137 , 0 ) ;
if ( ! V_15 -> V_66 )
return - V_132 ;
V_121 = F_48 ( V_15 , 4 ) ;
if ( V_121 )
return V_121 ;
V_30 = & V_15 -> V_138 [ 0 ] ;
V_30 -> type = V_139 ;
V_30 -> V_140 = V_141 | V_142 ;
V_30 -> V_143 = 16 ;
V_30 -> V_84 = 0xffff ;
V_30 -> V_144 = & V_145 ;
V_30 -> V_146 = F_32 ;
if ( V_15 -> V_95 ) {
V_15 -> V_97 = V_30 ;
V_30 -> V_140 |= V_147 ;
V_30 -> V_148 = V_30 -> V_143 ;
V_30 -> V_149 = F_12 ;
V_30 -> V_150 = F_18 ;
V_30 -> V_151 = F_6 ;
V_30 -> V_152 = F_21 ;
}
V_30 = & V_15 -> V_138 [ 1 ] ;
V_30 -> type = V_153 ;
V_30 -> V_140 = V_154 | V_142 ;
V_30 -> V_143 = 1 ;
V_30 -> V_84 = 0x0fff ;
V_30 -> V_148 = 1 ;
V_30 -> V_144 = & V_155 ;
V_30 -> V_156 = F_35 ;
V_121 = F_49 ( V_30 ) ;
if ( V_121 )
return V_121 ;
V_30 = & V_15 -> V_138 [ 2 ] ;
V_30 -> type = V_157 ;
V_30 -> V_140 = V_141 ;
V_30 -> V_143 = 16 ;
V_30 -> V_84 = 1 ;
V_30 -> V_144 = & V_158 ;
V_30 -> V_159 = F_37 ;
V_30 = & V_15 -> V_138 [ 3 ] ;
V_30 -> type = V_160 ;
V_30 -> V_140 = V_154 ;
V_30 -> V_143 = 16 ;
V_30 -> V_84 = 1 ;
V_30 -> V_144 = & V_158 ;
V_30 -> V_159 = F_38 ;
return 0 ;
}
static void F_50 ( struct V_14 * V_15 )
{
if ( V_15 -> V_20 )
F_40 ( V_15 ) ;
F_51 ( V_15 ) ;
}
static int F_52 ( struct V_130 * V_15 ,
const struct V_161 * V_162 )
{
return F_53 ( V_15 , & V_163 ,
V_162 -> V_164 ) ;
}
