static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 -> V_11 ;
unsigned int V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
if ( V_3 )
V_17 = F_2 ( V_5 -> V_18 + V_19 ) ;
else
V_17 = F_2 ( V_5 -> V_18 + V_20 ) ;
V_13 = V_5 -> V_21 ;
V_14 = F_3 ( V_5 -> V_22 [ V_13 ] . V_23 ) ;
for ( V_15 = 0 ; ( V_17 < V_14 || V_17 >= V_14 + V_5 -> V_24 ) &&
V_15 < V_5 -> V_25 ; V_15 ++ ) {
V_16 = V_5 -> V_24 / sizeof( V_26 ) ;
if ( V_11 -> V_27 == V_28 ) {
if ( V_16 > V_5 -> V_29 )
V_16 = V_5 -> V_29 ;
V_5 -> V_29 -= V_16 ;
}
F_4 ( V_8 , V_5 -> V_30 [ V_13 ] ,
V_16 * sizeof( V_26 ) ) ;
V_13 ++ ;
V_13 %= V_5 -> V_25 ;
V_14 = F_3 ( V_5 -> V_22 [ V_13 ] . V_23 ) ;
V_5 -> V_21 = V_13 ;
}
}
static T_1 F_5 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_33 * V_12 = V_8 -> V_12 ;
V_26 V_34 , V_35 ;
V_26 V_36 ;
V_26 V_37 ;
T_2 V_38 , V_39 ;
unsigned long V_40 ;
if ( ! V_2 -> V_41 )
return V_42 ;
V_36 = F_2 ( V_5 -> V_18 + V_43 ) ;
if ( ( V_36 & ( V_44 | V_45 | V_46 ) ) == 0 )
return V_42 ;
V_34 = F_2 ( V_5 -> V_47 + V_48 ) ;
V_35 = F_2 ( V_5 -> V_47 + V_49 ) ;
if ( V_34 )
F_6 ( V_34 , V_5 -> V_47 + V_48 ) ;
F_7 ( & V_2 -> V_50 , V_40 ) ;
V_38 = F_8 ( V_5 -> V_18 + V_51 ) ;
if ( V_36 & V_44 ) {
F_9 ( ( V_38 & V_52 ) | V_53 ,
V_5 -> V_18 + V_51 ) ;
if ( V_38 & V_52 )
F_1 ( V_2 , 0 ) ;
}
F_10 ( & V_2 -> V_50 , V_40 ) ;
F_7 ( & V_2 -> V_50 , V_40 ) ;
V_39 = F_8 ( V_5 -> V_18 + V_54 ) ;
if ( V_36 & V_45 ) {
F_9 ( ( V_39 & V_52 ) | V_53 ,
V_5 -> V_18 + V_54 ) ;
}
F_10 ( & V_2 -> V_50 , V_40 ) ;
if ( V_36 & V_55 ) {
V_37 = F_2 ( V_5 -> V_18 + V_56 ) ;
F_6 ( V_37 , V_5 -> V_18 + V_56 ) ;
}
if ( V_35 & V_57 ) {
F_11 ( V_2 -> V_58 , L_1 ) ;
V_12 -> V_59 |= V_60 | V_61 ;
}
if ( V_35 & V_62 ) {
F_11 ( V_2 -> V_58 , L_2 ) ;
V_12 -> V_59 |= V_60 | V_61 ;
}
if ( V_5 -> V_29 == 0 )
V_12 -> V_59 |= V_60 ;
F_12 ( V_2 , V_8 ) ;
return V_63 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_40 ;
F_7 ( & V_2 -> V_50 , V_40 ) ;
F_14 ( V_5 -> V_18 , V_3 ) ;
F_10 ( & V_2 -> V_50 , V_40 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_6 ( 0 , V_5 -> V_47 + V_64 ) ;
F_6 ( 0 , V_5 -> V_47 + V_65 ) ;
F_13 ( V_2 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_33 * V_12 = V_8 -> V_12 ;
struct V_10 * V_11 = & V_12 -> V_11 ;
unsigned long V_40 ;
V_26 V_66 ;
if ( V_8 -> V_67 )
return - V_68 ;
F_6 ( V_69 , V_5 -> V_47 + V_64 ) ;
F_13 ( V_2 , 0 ) ;
V_5 -> V_21 = 0 ;
F_6 ( 0 , V_5 -> V_18 + V_70 ) ;
F_6 ( 0 , V_5 -> V_18 + V_20 ) ;
F_6 ( 0 , V_5 -> V_18 + V_71 ) ;
V_66 = V_5 -> V_72 | V_73 |
V_74 | V_75 ;
F_6 ( V_66 , V_5 -> V_18 + V_76 ) ;
F_7 ( & V_2 -> V_50 , V_40 ) ;
F_9 ( V_52 | V_77 | V_53 ,
V_5 -> V_18 + V_51 ) ;
F_10 ( & V_2 -> V_50 , V_40 ) ;
if ( V_11 -> V_27 == V_28 )
V_5 -> V_29 = V_11 -> V_78 ;
else
V_5 -> V_29 = 1 ;
F_6 ( V_62 | V_57 ,
V_5 -> V_47 + V_49 ) ;
F_6 ( V_79 , V_5 -> V_47 + V_65 ) ;
F_6 ( V_80 , V_5 -> V_47 + V_64 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_10 * V_11 )
{
int V_81 = 0 ;
int V_82 ;
if ( V_8 -> V_67 )
return - V_68 ;
V_81 |= F_18 ( & V_11 -> V_83 , V_84 ) ;
V_81 |= F_18 ( & V_11 -> V_85 , V_86 ) ;
V_81 |= F_18 ( & V_11 -> V_87 , V_84 ) ;
V_81 |= F_18 ( & V_11 -> V_88 , V_28 ) ;
V_81 |= F_18 ( & V_11 -> V_27 , V_28 | V_89 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_19 ( V_11 -> V_27 ) ;
if ( V_81 )
return 2 ;
if ( ! V_11 -> V_90 || ! V_11 -> V_91 ) {
V_11 -> V_90 = 32 ;
V_81 |= - V_68 ;
}
V_81 |= F_20 ( & V_11 -> V_92 , V_11 -> V_90 ) ;
if ( V_11 -> V_27 == V_28 )
V_81 |= F_21 ( & V_11 -> V_78 , 1 ) ;
else
V_81 |= F_20 ( & V_11 -> V_78 , 0 ) ;
if ( V_81 )
return 3 ;
if ( V_81 )
return 4 ;
for ( V_82 = 0 ; V_82 < V_11 -> V_90 ; V_82 ++ ) {
if ( F_22 ( V_11 -> V_91 [ V_82 ] ) != V_82 ) {
F_11 ( V_2 -> V_58 ,
L_3 ) ;
V_81 |= - V_68 ;
break;
}
}
if ( V_81 )
return 5 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_93 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_3 V_94 = V_5 -> V_72 ;
V_26 V_95 = V_73 | V_74 |
V_75 ;
unsigned int V_96 = 0 ;
unsigned int V_13 = 0 ;
unsigned int V_82 ;
if ( V_93 > V_97 )
V_93 = V_97 ;
V_93 -= V_93 % sizeof( V_26 ) ;
if ( V_93 == 0 )
return - V_68 ;
for ( V_82 = 0 ; V_82 < V_98 && V_13 < V_99 ; V_82 ++ ) {
V_5 -> V_22 [ V_82 ] . V_23 =
F_24 ( V_5 -> V_100 [ V_13 ] + V_96 ) ;
V_5 -> V_22 [ V_82 ] . V_101 = F_24 ( V_102 ) ;
V_5 -> V_22 [ V_82 ] . V_103 = F_24 ( V_93 ) ;
V_5 -> V_22 [ V_82 ] . V_17 = F_24 ( ( V_94 +
( V_82 + 1 ) * sizeof( V_5 -> V_22 [ 0 ] ) ) | V_95 ) ;
V_5 -> V_30 [ V_82 ] = V_5 -> V_104 [ V_13 ] +
( V_96 / sizeof( V_26 ) ) ;
V_96 += V_93 ;
if ( V_93 + V_96 > V_97 ) {
V_96 = 0 ;
V_13 ++ ;
}
}
V_5 -> V_25 = V_82 ;
V_5 -> V_22 [ V_82 - 1 ] . V_17 = F_24 ( V_94 | V_95 ) ;
V_5 -> V_24 = V_93 ;
return V_93 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_105 * V_106 ,
unsigned int * V_107 )
{
int V_108 ;
switch ( V_107 [ 0 ] ) {
case V_109 :
V_108 = F_23 ( V_2 , V_107 [ 1 ] ) ;
if ( V_108 )
return V_108 ;
V_107 [ 1 ] = V_108 ;
break;
default:
V_108 = F_26 ( V_2 , V_8 , V_106 , V_107 , 0xffffffff ) ;
if ( V_108 )
return V_108 ;
break;
}
return V_106 -> V_110 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_26 V_111 ;
F_6 ( V_112 , V_5 -> V_47 + V_64 ) ;
F_28 ( 10 ) ;
F_6 ( F_29 ( 32 ) | F_30 ( 32 ) ,
V_5 -> V_47 + V_113 ) ;
F_6 ( F_29 ( 32 ) | F_30 ( 32 ) ,
V_5 -> V_47 + V_114 ) ;
V_5 -> V_115 = F_2 ( V_5 -> V_47 + V_116 ) &
V_117 ;
V_5 -> V_118 = F_2 ( V_5 -> V_47 + V_119 ) &
V_117 ;
F_6 ( 0 , V_5 -> V_47 + V_65 ) ;
V_111 =
V_120 | V_121 | V_122 | V_123 | V_124 | V_125 |
V_126 ;
F_6 ( V_111 , V_5 -> V_18 + V_43 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_26 V_66 ;
void T_4 * V_127 = V_5 -> V_18 ;
#ifdef F_32
V_66 = V_128 | V_129 ;
#else
V_66 = 0 ;
#endif
F_6 ( V_66 , V_5 -> V_18 + V_130 ) ;
F_6 ( 0 , V_5 -> V_18 + V_43 ) ;
F_13 ( V_2 , 0 ) ;
F_13 ( V_2 , 1 ) ;
V_66 = 0 ;
V_66 |= V_131 ;
V_66 |= V_132 ;
V_66 |= V_133 ;
V_66 |= V_134 ;
V_66 |= V_135 ;
V_66 |= V_136 ;
V_66 |= V_137 ;
V_66 |= V_138 ;
F_6 ( V_66 , V_127 + V_139 ) ;
}
static const struct V_140 * F_33 ( struct V_141 * V_142 )
{
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < F_34 ( V_143 ) ; V_82 ++ )
if ( V_142 -> V_144 == V_143 [ V_82 ] . V_145 &&
V_142 -> V_146 == V_143 [ V_82 ] . V_147 )
return & V_143 [ V_82 ] ;
return NULL ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned long V_148 )
{
struct V_141 * V_142 = F_36 ( V_2 ) ;
const struct V_140 * V_149 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_82 ;
int V_150 ;
V_149 = F_33 ( V_142 ) ;
if ( ! V_149 ) {
F_11 ( V_2 -> V_58 , L_4 ,
F_37 ( V_142 ) ) ;
return - V_68 ;
}
V_2 -> V_151 = V_149 ;
V_2 -> V_152 = V_149 -> V_153 ;
V_5 = F_38 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_154 ;
V_150 = F_39 ( V_2 ) ;
if ( V_150 )
return V_150 ;
F_40 ( V_142 ) ;
V_5 -> V_18 = F_41 ( V_142 , 0 ) ;
V_5 -> V_47 = F_41 ( V_142 , 2 ) ;
if ( ! V_5 -> V_18 || ! V_5 -> V_47 ) {
F_42 ( V_2 -> V_58 , L_5 ) ;
return - V_154 ;
}
F_31 ( V_2 ) ;
if ( F_43 ( V_142 -> V_31 , F_5 , V_155 ,
V_2 -> V_152 , V_2 ) ) {
F_42 ( V_2 -> V_58 ,
L_6 , V_142 -> V_31 ) ;
return - V_68 ;
}
V_2 -> V_31 = V_142 -> V_31 ;
F_44 ( V_2 -> V_58 , L_7 , V_2 -> V_31 ) ;
for ( V_82 = 0 ; V_82 < V_99 ; V_82 ++ ) {
V_5 -> V_104 [ V_82 ] =
F_45 ( V_142 , V_97 ,
& V_5 -> V_100 [ V_82 ] ) ;
}
V_5 -> V_22 = F_45 ( V_142 ,
sizeof( struct V_156 ) *
V_98 ,
& V_5 -> V_72 ) ;
if ( V_5 -> V_72 & 0xf ) {
F_42 ( V_2 -> V_58 ,
L_8 ) ;
return - V_157 ;
}
V_150 = F_23 ( V_2 , 0x1000 ) ;
if ( V_150 < 0 )
return V_150 ;
V_150 = F_46 ( V_2 , 1 ) ;
if ( V_150 )
return V_150 ;
V_8 = & V_2 -> V_158 [ 0 ] ;
V_2 -> V_9 = V_8 ;
V_8 -> type = V_159 ;
V_8 -> V_160 = V_161 | V_162 | V_163 |
V_164 ;
V_8 -> V_165 = 32 ;
V_8 -> V_166 = 32 ;
V_8 -> V_167 = 1 ;
V_8 -> V_168 = & V_169 ;
V_8 -> V_170 = F_25 ;
V_8 -> V_171 = F_16 ;
V_8 -> V_172 = F_17 ;
V_8 -> V_173 = F_15 ;
return F_27 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_141 * V_142 = F_36 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_82 ;
if ( V_2 -> V_31 )
F_48 ( V_2 -> V_31 , V_2 ) ;
if ( V_5 ) {
if ( V_5 -> V_18 ) {
F_6 ( 0 , V_5 -> V_18 + V_43 ) ;
F_49 ( V_5 -> V_18 ) ;
}
if ( V_5 -> V_47 )
F_49 ( V_5 -> V_47 ) ;
for ( V_82 = 0 ; V_82 < V_99 ; V_82 ++ ) {
if ( V_5 -> V_104 [ V_82 ] )
F_50 ( V_142 ,
V_97 ,
V_5 -> V_104 [ V_82 ] ,
V_5 ->
V_100 [ V_82 ] ) ;
}
if ( V_5 -> V_22 )
F_50 ( V_142 ,
sizeof( struct V_156 ) *
V_98 ,
V_5 -> V_22 ,
V_5 -> V_72 ) ;
}
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_141 * V_2 ,
const struct V_174 * V_175 )
{
return F_53 ( V_2 , & V_176 , V_175 -> V_177 ) ;
}
