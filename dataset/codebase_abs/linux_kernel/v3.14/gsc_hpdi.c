static T_1 F_1 ( unsigned int V_1 )
{
return ( V_1 << 16 ) & 0xff0000 ;
}
static T_1 F_2 ( unsigned int V_1 )
{
return V_1 & 0xffff ;
}
static T_1 F_3 ( int V_2 )
{
return 0x1 << V_2 ;
}
static unsigned int F_4 ( T_1 V_3 )
{
return V_3 & 0xfffff ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
int V_11 ;
switch ( V_10 [ 0 ] ) {
case V_12 :
return F_6 ( V_5 , V_10 ) ;
default:
V_11 = F_7 ( V_5 , V_7 , V_9 , V_10 , 0xffffffff ) ;
if ( V_11 )
return V_11 ;
break;
}
return V_9 -> V_13 ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
F_9 ( 0 , V_15 -> V_17 + V_18 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
T_1 V_19 ;
void T_2 * V_20 = V_15 -> V_17 ;
#ifdef F_11
V_19 = V_21 | V_22 ;
#else
V_19 = 0 ;
#endif
F_9 ( V_19 , V_15 -> V_17 + V_23 ) ;
F_8 ( V_5 ) ;
F_12 ( V_5 , 0 ) ;
F_12 ( V_5 , 1 ) ;
V_19 = 0 ;
V_19 |= V_24 ;
V_19 |= V_25 ;
V_19 |= V_26 ;
V_19 |= V_27 ;
V_19 |= V_28 ;
V_19 |= V_29 ;
V_19 |= V_30 ;
V_19 |= V_31 ;
F_9 ( V_19 , V_20 + V_32 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_11 ;
V_11 = F_14 ( V_5 , 1 ) ;
if ( V_11 )
return V_11 ;
V_7 = & V_5 -> V_33 [ 0 ] ;
V_5 -> V_34 = V_7 ;
V_7 -> type = V_35 ;
V_7 -> V_36 =
V_37 | V_38 | V_39 | V_40 ;
V_7 -> V_41 = 32 ;
V_7 -> V_42 = 32 ;
V_7 -> V_43 = 1 ;
V_7 -> V_44 = & V_45 ;
V_7 -> V_46 = F_5 ;
V_7 -> V_47 = V_48 ;
V_7 -> V_49 = V_50 ;
V_7 -> V_51 = V_52 ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
T_1 V_53 ;
F_9 ( V_54 , V_15 -> V_55 + V_56 ) ;
F_16 ( 10 ) ;
F_9 ( F_2 ( 32 ) | F_1 ( 32 ) ,
V_15 -> V_55 + V_57 ) ;
F_9 ( F_2 ( 32 ) | F_1 ( 32 ) ,
V_15 -> V_55 + V_58 ) ;
V_15 -> V_59 = F_4 ( F_17 ( V_15 -> V_55 +
V_60 ) ) ;
V_15 -> V_61 = F_4 ( F_17 ( V_15 -> V_55 +
V_62 ) ) ;
F_9 ( 0 , V_15 -> V_55 + V_63 ) ;
V_53 =
V_64 | V_65 | V_66 | V_67 | V_68 | V_69 |
V_70 ;
F_9 ( V_53 , V_15 -> V_17 + V_18 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
unsigned int V_71 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
unsigned int V_72 , V_73 ;
T_1 V_74 = V_75 | V_76 |
V_77 ;
unsigned int V_78 ;
if ( V_71 > V_79 )
V_71 = V_79 ;
V_71 -= V_71 % sizeof( T_1 ) ;
if ( V_71 == 0 )
return - 1 ;
V_73 = 0 ;
V_72 = 0 ;
for ( V_78 = 0 ; V_78 < V_80 &&
V_72 < V_81 ; V_78 ++ ) {
V_15 -> V_82 [ V_78 ] . V_83 =
F_19 ( V_15 -> V_84 [ V_72 ] +
V_73 ) ;
V_15 -> V_82 [ V_78 ] . V_85 = F_19 ( V_86 ) ;
V_15 -> V_82 [ V_78 ] . V_71 =
F_19 ( V_71 ) ;
V_15 -> V_82 [ V_78 ] . V_87 =
F_19 ( ( V_15 -> V_88 + ( V_78 +
1 ) *
sizeof( V_15 -> V_82 [ 0 ] ) ) | V_74 ) ;
V_15 -> V_89 [ V_78 ] =
V_15 -> V_90 [ V_72 ] +
( V_73 / sizeof( T_1 ) ) ;
V_73 += V_71 ;
if ( V_71 + V_73 > V_79 ) {
V_73 = 0 ;
V_72 ++ ;
}
}
V_15 -> V_91 = V_78 ;
V_15 -> V_82 [ V_78 - 1 ] . V_87 =
F_19 ( V_15 -> V_88 | V_74 ) ;
V_15 -> V_92 = V_71 ;
return V_71 ;
}
static const struct V_93 * F_20 ( struct V_94 * V_95 )
{
unsigned int V_78 ;
for ( V_78 = 0 ; V_78 < F_21 ( V_96 ) ; V_78 ++ )
if ( V_95 -> V_97 == V_96 [ V_78 ] . V_98 &&
V_95 -> V_99 == V_96 [ V_78 ] . V_100 )
return & V_96 [ V_78 ] ;
return NULL ;
}
static int F_22 ( struct V_4 * V_5 ,
unsigned long V_101 )
{
struct V_94 * V_95 = F_23 ( V_5 ) ;
const struct V_93 * V_102 ;
struct V_14 * V_15 ;
int V_78 ;
int V_103 ;
V_102 = F_20 ( V_95 ) ;
if ( ! V_102 ) {
F_24 ( V_5 -> V_104 , L_1 ,
F_25 ( V_95 ) ) ;
return - V_105 ;
}
V_5 -> V_106 = V_102 ;
V_5 -> V_107 = V_102 -> V_108 ;
V_15 = F_26 ( V_5 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_109 ;
V_103 = F_27 ( V_5 ) ;
if ( V_103 )
return V_103 ;
F_28 ( V_95 ) ;
V_15 -> V_17 = F_29 ( V_95 , 0 ) ;
V_15 -> V_55 = F_29 ( V_95 , 2 ) ;
if ( ! V_15 -> V_17 || ! V_15 -> V_55 ) {
F_30 ( V_5 -> V_104 , L_2 ) ;
return - V_109 ;
}
F_10 ( V_5 ) ;
if ( F_31 ( V_95 -> V_110 , V_111 , V_112 ,
V_5 -> V_107 , V_5 ) ) {
F_30 ( V_5 -> V_104 ,
L_3 , V_95 -> V_110 ) ;
return - V_105 ;
}
V_5 -> V_110 = V_95 -> V_110 ;
F_32 ( V_5 -> V_104 , L_4 , V_5 -> V_110 ) ;
for ( V_78 = 0 ; V_78 < V_81 ; V_78 ++ ) {
V_15 -> V_90 [ V_78 ] =
F_33 ( V_95 , V_79 ,
& V_15 -> V_84 [ V_78 ] ) ;
}
V_15 -> V_82 = F_33 ( V_95 ,
sizeof( struct V_113 ) *
V_80 ,
& V_15 -> V_88 ) ;
if ( V_15 -> V_88 & 0xf ) {
F_30 ( V_5 -> V_104 ,
L_5 ) ;
return - V_114 ;
}
V_103 = F_18 ( V_5 , 0x1000 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_13 ( V_5 ) ;
if ( V_103 < 0 )
return V_103 ;
return F_15 ( V_5 ) ;
}
static void F_34 ( struct V_4 * V_5 )
{
struct V_94 * V_95 = F_23 ( V_5 ) ;
struct V_14 * V_15 = V_5 -> V_16 ;
unsigned int V_78 ;
if ( V_5 -> V_110 )
F_35 ( V_5 -> V_110 , V_5 ) ;
if ( V_15 ) {
if ( V_15 -> V_17 ) {
F_8 ( V_5 ) ;
F_36 ( V_15 -> V_17 ) ;
}
if ( V_15 -> V_55 )
F_36 ( V_15 -> V_55 ) ;
for ( V_78 = 0 ; V_78 < V_81 ; V_78 ++ ) {
if ( V_15 -> V_90 [ V_78 ] )
F_37 ( V_95 ,
V_79 ,
V_15 -> V_90 [ V_78 ] ,
V_15 ->
V_84 [ V_78 ] ) ;
}
if ( V_15 -> V_82 )
F_37 ( V_95 ,
sizeof( struct V_113 ) *
V_80 ,
V_15 -> V_82 ,
V_15 -> V_88 ) ;
}
F_38 ( V_5 ) ;
}
static int F_6 ( struct V_4 * V_5 , unsigned int * V_10 )
{
unsigned int V_115 ;
int V_103 ;
V_115 = V_10 [ 1 ] ;
V_103 = F_18 ( V_5 , V_115 ) ;
if ( V_103 < 0 )
return V_103 ;
V_10 [ 1 ] = V_103 ;
return 2 ;
}
static int F_39 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_116 * V_117 )
{
int V_118 = 0 ;
int V_78 ;
V_118 |= F_40 ( & V_117 -> V_119 , V_120 ) ;
V_118 |= F_40 ( & V_117 -> V_121 , V_122 ) ;
V_118 |= F_40 ( & V_117 -> V_123 , V_120 ) ;
V_118 |= F_40 ( & V_117 -> V_124 , V_125 ) ;
V_118 |= F_40 ( & V_117 -> V_126 , V_125 | V_127 ) ;
if ( V_118 )
return 1 ;
V_118 |= F_41 ( V_117 -> V_126 ) ;
if ( V_118 )
return 2 ;
if ( ! V_117 -> V_128 ) {
V_117 -> V_128 = 32 ;
V_118 |= - V_105 ;
}
V_118 |= F_42 ( & V_117 -> V_129 , V_117 -> V_128 ) ;
switch ( V_117 -> V_126 ) {
case V_125 :
V_118 |= F_43 ( & V_117 -> V_130 , 1 ) ;
break;
case V_127 :
V_118 |= F_42 ( & V_117 -> V_130 , 0 ) ;
break;
default:
break;
}
if ( V_118 )
return 3 ;
if ( V_118 )
return 4 ;
if ( ! V_117 -> V_131 )
return 0 ;
for ( V_78 = 1 ; V_78 < V_117 -> V_128 ; V_78 ++ ) {
if ( F_44 ( V_117 -> V_131 [ V_78 ] ) != V_78 ) {
F_45 ( V_5 ,
L_6 ) ;
V_118 ++ ;
break;
}
}
if ( V_118 )
return 5 ;
return 0 ;
}
static int V_50 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_116 * V_117 )
{
if ( V_7 -> V_132 )
return - V_105 ;
else
return F_39 ( V_5 , V_7 , V_117 ) ;
}
static inline void F_46 ( struct V_4 * V_5 , T_1 V_19 ,
unsigned int V_133 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
F_9 ( V_19 | V_15 -> V_19 [ V_133 / sizeof( T_1 ) ] ,
V_15 -> V_55 + V_133 ) ;
}
static int F_47 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
T_1 V_19 ;
unsigned long V_134 ;
struct V_135 * V_136 = V_7 -> V_136 ;
struct V_116 * V_117 = & V_136 -> V_117 ;
F_46 ( V_5 , V_137 , V_56 ) ;
F_12 ( V_5 , 0 ) ;
V_15 -> V_138 = 0 ;
F_9 ( 0 , V_15 -> V_17 + V_139 ) ;
F_9 ( 0 , V_15 -> V_17 + V_140 ) ;
F_9 ( 0 , V_15 -> V_17 + V_141 ) ;
V_19 =
V_15 -> V_88 | V_75 |
V_76 | V_77 ;
F_9 ( V_19 , V_15 -> V_17 + V_142 ) ;
F_48 ( & V_5 -> V_143 , V_134 ) ;
F_49 ( V_144 | V_145 | V_146 ,
V_15 -> V_17 + V_147 ) ;
F_50 ( & V_5 -> V_143 , V_134 ) ;
if ( V_117 -> V_126 == V_125 )
V_15 -> V_148 = V_117 -> V_130 ;
else
V_15 -> V_148 = 1 ;
F_9 ( V_149 | V_150 ,
V_15 -> V_55 + V_151 ) ;
F_9 ( F_3 ( V_152 ) ,
V_15 -> V_55 + V_63 ) ;
F_46 ( V_5 , V_153 , V_56 ) ;
return 0 ;
}
static int V_48 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
if ( V_7 -> V_132 )
return - V_105 ;
else
return F_47 ( V_5 , V_7 ) ;
}
static void F_51 ( struct V_4 * V_5 , unsigned int V_154 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_135 * V_136 = V_5 -> V_34 -> V_136 ;
T_1 V_155 ;
int V_156 ;
int V_157 = 0 ;
void T_2 * V_158 ;
if ( V_154 )
V_158 =
V_15 -> V_17 + V_159 ;
else
V_158 =
V_15 -> V_17 + V_140 ;
V_156 = 0 ;
for ( V_155 = F_17 ( V_158 ) ;
( V_155 <
F_52 ( V_15 -> V_82 [ V_15 -> V_138 ] .
V_83 )
|| V_155 >=
F_52 ( V_15 -> V_82 [ V_15 -> V_138 ] .
V_83 ) + V_15 -> V_92 )
&& V_156 < V_15 -> V_91 ; V_156 ++ ) {
V_157 = V_15 -> V_92 / sizeof( T_1 ) ;
if ( V_136 -> V_117 . V_126 == V_125 ) {
if ( V_157 > V_15 -> V_148 )
V_157 = V_15 -> V_148 ;
V_15 -> V_148 -= V_157 ;
}
F_53 ( V_5 -> V_34 ,
V_15 -> V_89 [ V_15 ->
V_138 ] ,
V_157 * sizeof( T_1 ) ) ;
V_15 -> V_138 ++ ;
V_15 -> V_138 %= V_15 -> V_91 ;
}
}
static T_3 V_111 ( int V_110 , void * V_160 )
{
struct V_4 * V_5 = V_160 ;
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_6 * V_7 = V_5 -> V_34 ;
struct V_135 * V_136 = V_7 -> V_136 ;
T_1 V_161 , V_162 ;
T_1 V_163 ;
T_1 V_164 ;
T_4 V_165 , V_166 ;
unsigned long V_134 ;
if ( ! V_5 -> V_167 )
return V_168 ;
V_163 = F_17 ( V_15 -> V_17 + V_18 ) ;
if ( ( V_163 & ( V_169 | V_170 | V_171 ) ) == 0 )
return V_168 ;
V_161 = F_17 ( V_15 -> V_55 + V_172 ) ;
V_162 = F_17 ( V_15 -> V_55 + V_151 ) ;
V_136 -> V_173 = 0 ;
if ( V_161 ) {
F_9 ( V_161 ,
V_15 -> V_55 + V_172 ) ;
}
F_48 ( & V_5 -> V_143 , V_134 ) ;
V_165 = F_54 ( V_15 -> V_17 + V_147 ) ;
if ( V_163 & V_169 ) {
F_49 ( ( V_165 & V_144 ) | V_146 ,
V_15 -> V_17 + V_147 ) ;
if ( V_165 & V_144 )
F_51 ( V_5 , 0 ) ;
}
F_50 ( & V_5 -> V_143 , V_134 ) ;
F_48 ( & V_5 -> V_143 , V_134 ) ;
V_166 = F_54 ( V_15 -> V_17 + V_174 ) ;
if ( V_163 & V_170 ) {
F_49 ( ( V_166 & V_144 ) | V_146 ,
V_15 -> V_17 + V_174 ) ;
}
F_50 ( & V_5 -> V_143 , V_134 ) ;
if ( V_163 & V_175 ) {
V_164 = F_17 ( V_15 -> V_17 + V_176 ) ;
F_9 ( V_164 , V_15 -> V_17 + V_176 ) ;
}
if ( V_162 & V_150 ) {
F_45 ( V_5 , L_7 ) ;
V_136 -> V_173 |= V_177 | V_178 ;
}
if ( V_162 & V_149 ) {
F_45 ( V_5 , L_8 ) ;
V_136 -> V_173 |= V_177 | V_178 ;
}
if ( V_15 -> V_148 == 0 )
V_136 -> V_173 |= V_177 ;
F_55 ( V_5 , V_7 ) ;
return V_179 ;
}
static void F_12 ( struct V_4 * V_5 , unsigned int V_154 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
unsigned long V_134 ;
F_48 ( & V_5 -> V_143 , V_134 ) ;
F_56 ( V_15 -> V_17 , V_154 ) ;
F_50 ( & V_5 -> V_143 , V_134 ) ;
}
static int V_52 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
F_46 ( V_5 , 0 , V_56 ) ;
F_9 ( 0 , V_15 -> V_55 + V_63 ) ;
F_12 ( V_5 , 0 ) ;
return 0 ;
}
static int F_57 ( struct V_94 * V_5 ,
const struct V_180 * V_181 )
{
return F_58 ( V_5 , & V_182 , V_181 -> V_183 ) ;
}
