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
F_11 ( L_1 ,
F_12 ( V_20 + V_18 ) ) ;
F_11 ( L_2 , F_12 ( V_20 + V_21 ) ) ;
F_11 ( L_3 ,
F_12 ( V_15 -> V_17 + V_22 ) ) ;
F_11 ( L_4 ,
F_12 ( V_20 + V_23 ) ) ;
F_11 ( L_5 ,
F_12 ( V_20 + V_24 ) ) ;
F_11 ( L_6 ,
F_12 ( V_20 + V_25 ) ) ;
F_11 ( L_7 ,
F_12 ( V_20 + V_26 ) ) ;
F_11 ( L_8 ,
F_12 ( V_20 + V_27 ) ) ;
F_11 ( L_9 ,
F_12 ( V_20 + V_28 ) ) ;
F_11 ( L_10 ,
F_12 ( V_20 + V_29 ) ) ;
F_11 ( L_11 ,
F_13 ( V_20 + V_30 ) ) ;
F_11 ( L_12 ,
F_12 ( V_20 + V_31 ) ) ;
F_11 ( L_13 , F_12 ( V_20 + V_32 ) ) ;
#ifdef F_14
V_19 = V_33 | V_34 ;
#else
V_19 = 0 ;
#endif
F_9 ( V_19 , V_15 -> V_17 + V_32 ) ;
F_8 ( V_5 ) ;
F_15 ( V_5 , 0 ) ;
F_15 ( V_5 , 1 ) ;
V_19 = 0 ;
V_19 |= V_35 ;
V_19 |= V_36 ;
V_19 |= V_37 ;
V_19 |= V_38 ;
V_19 |= V_39 ;
V_19 |= V_40 ;
V_19 |= V_41 ;
V_19 |= V_42 ;
F_9 ( V_19 , V_20 + V_24 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_11 ;
V_11 = F_17 ( V_5 , 1 ) ;
if ( V_11 )
return V_11 ;
V_7 = & V_5 -> V_43 [ 0 ] ;
V_5 -> V_44 = V_7 ;
V_7 -> type = V_45 ;
V_7 -> V_46 =
V_47 | V_48 | V_49 | V_50 ;
V_7 -> V_51 = 32 ;
V_7 -> V_52 = 32 ;
V_7 -> V_53 = 1 ;
V_7 -> V_54 = & V_55 ;
V_7 -> V_56 = F_5 ;
V_7 -> V_57 = V_58 ;
V_7 -> V_59 = V_60 ;
V_7 -> V_61 = V_62 ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
T_1 V_63 ;
F_9 ( V_64 , V_15 -> V_65 + V_66 ) ;
F_19 ( 10 ) ;
F_9 ( F_2 ( 32 ) | F_1 ( 32 ) ,
V_15 -> V_65 + V_67 ) ;
F_9 ( F_2 ( 32 ) | F_1 ( 32 ) ,
V_15 -> V_65 + V_68 ) ;
V_15 -> V_69 = F_4 ( F_12 ( V_15 -> V_65 +
V_70 ) ) ;
V_15 -> V_71 = F_4 ( F_12 ( V_15 -> V_65 +
V_72 ) ) ;
F_9 ( 0 , V_15 -> V_65 + V_73 ) ;
V_63 =
V_74 | V_75 | V_76 | V_77 | V_78 | V_79 |
V_80 ;
F_9 ( V_63 , V_15 -> V_17 + V_18 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 ,
unsigned int V_81 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
unsigned int V_82 , V_83 ;
T_1 V_84 = V_85 | V_86 |
V_87 ;
unsigned int V_88 ;
if ( V_81 > V_89 )
V_81 = V_89 ;
V_81 -= V_81 % sizeof( T_1 ) ;
if ( V_81 == 0 )
return - 1 ;
F_11 ( L_14 , V_81 ) ;
F_11 ( L_15 ,
( unsigned long ) V_15 -> V_90 ) ;
V_83 = 0 ;
V_82 = 0 ;
for ( V_88 = 0 ; V_88 < V_91 &&
V_82 < V_92 ; V_88 ++ ) {
V_15 -> V_93 [ V_88 ] . V_94 =
F_21 ( V_15 -> V_95 [ V_82 ] +
V_83 ) ;
V_15 -> V_93 [ V_88 ] . V_96 = F_21 ( V_97 ) ;
V_15 -> V_93 [ V_88 ] . V_81 =
F_21 ( V_81 ) ;
V_15 -> V_93 [ V_88 ] . V_98 =
F_21 ( ( V_15 -> V_90 + ( V_88 +
1 ) *
sizeof( V_15 -> V_93 [ 0 ] ) ) | V_84 ) ;
V_15 -> V_99 [ V_88 ] =
V_15 -> V_100 [ V_82 ] +
( V_83 / sizeof( T_1 ) ) ;
V_83 += V_81 ;
if ( V_81 + V_83 > V_89 ) {
V_83 = 0 ;
V_82 ++ ;
}
F_11 ( L_16 , V_88 ) ;
F_11 ( L_17 ,
V_15 -> V_99 [ V_88 ] ,
( unsigned long ) V_15 -> V_93 [ V_88 ] .
V_94 ) ;
F_11 ( L_18 ,
( unsigned long ) V_15 -> V_93 [ V_88 ] . V_98 ) ;
}
V_15 -> V_101 = V_88 ;
V_15 -> V_93 [ V_88 - 1 ] . V_98 =
F_21 ( V_15 -> V_90 | V_84 ) ;
F_11 ( L_19 , V_88 - 1 ,
( unsigned long ) V_15 -> V_93 [ V_88 - 1 ] . V_98 ) ;
V_15 -> V_102 = V_81 ;
return V_81 ;
}
static const struct V_103 * F_22 ( struct V_104 * V_105 )
{
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < F_23 ( V_106 ) ; V_88 ++ )
if ( V_105 -> V_107 == V_106 [ V_88 ] . V_108 &&
V_105 -> V_109 == V_106 [ V_88 ] . V_110 )
return & V_106 [ V_88 ] ;
return NULL ;
}
static int F_24 ( struct V_4 * V_5 ,
unsigned long V_111 )
{
struct V_104 * V_105 = F_25 ( V_5 ) ;
const struct V_103 * V_112 ;
struct V_14 * V_15 ;
int V_88 ;
int V_113 ;
V_112 = F_22 ( V_105 ) ;
if ( ! V_112 ) {
F_26 ( V_5 -> V_114 , L_20 ,
F_27 ( V_105 ) ) ;
return - V_115 ;
}
V_5 -> V_116 = V_112 ;
V_5 -> V_117 = V_112 -> V_118 ;
V_15 = F_28 ( V_5 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_119 ;
V_113 = F_29 ( V_5 ) ;
if ( V_113 )
return V_113 ;
F_30 ( V_105 ) ;
V_15 -> V_17 = F_31 ( V_105 , 0 ) ;
V_15 -> V_65 = F_31 ( V_105 , 2 ) ;
if ( ! V_15 -> V_17 || ! V_15 -> V_65 ) {
F_32 ( V_5 -> V_114 , L_21 ) ;
return - V_119 ;
}
F_11 ( L_22 , V_15 -> V_17 ) ;
F_11 ( L_23 , V_15 -> V_65 ) ;
F_10 ( V_5 ) ;
if ( F_33 ( V_105 -> V_120 , V_121 , V_122 ,
V_5 -> V_117 , V_5 ) ) {
F_32 ( V_5 -> V_114 ,
L_24 , V_105 -> V_120 ) ;
return - V_115 ;
}
V_5 -> V_120 = V_105 -> V_120 ;
F_34 ( V_5 -> V_114 , L_25 , V_5 -> V_120 ) ;
for ( V_88 = 0 ; V_88 < V_92 ; V_88 ++ ) {
V_15 -> V_100 [ V_88 ] =
F_35 ( V_105 , V_89 ,
& V_15 -> V_95 [ V_88 ] ) ;
F_11 ( L_26 ,
V_15 -> V_100 [ V_88 ] ,
( unsigned long ) V_15 -> V_95 [ V_88 ] ) ;
}
V_15 -> V_93 = F_35 ( V_105 ,
sizeof( struct V_123 ) *
V_91 ,
& V_15 -> V_90 ) ;
if ( V_15 -> V_90 & 0xf ) {
F_32 ( V_5 -> V_114 ,
L_27 ) ;
return - V_124 ;
}
V_113 = F_20 ( V_5 , 0x1000 ) ;
if ( V_113 < 0 )
return V_113 ;
V_113 = F_16 ( V_5 ) ;
if ( V_113 < 0 )
return V_113 ;
return F_18 ( V_5 ) ;
}
static void F_36 ( struct V_4 * V_5 )
{
struct V_104 * V_105 = F_25 ( V_5 ) ;
struct V_14 * V_15 = V_5 -> V_16 ;
unsigned int V_88 ;
if ( V_5 -> V_120 )
F_37 ( V_5 -> V_120 , V_5 ) ;
if ( V_15 ) {
if ( V_15 -> V_17 ) {
F_8 ( V_5 ) ;
F_38 ( V_15 -> V_17 ) ;
}
if ( V_15 -> V_65 )
F_38 ( V_15 -> V_65 ) ;
for ( V_88 = 0 ; V_88 < V_92 ; V_88 ++ ) {
if ( V_15 -> V_100 [ V_88 ] )
F_39 ( V_105 ,
V_89 ,
V_15 -> V_100 [ V_88 ] ,
V_15 ->
V_95 [ V_88 ] ) ;
}
if ( V_15 -> V_93 )
F_39 ( V_105 ,
sizeof( struct V_123 ) *
V_91 ,
V_15 -> V_93 ,
V_15 -> V_90 ) ;
}
F_40 ( V_5 ) ;
}
static int F_6 ( struct V_4 * V_5 , unsigned int * V_10 )
{
unsigned int V_125 ;
int V_113 ;
V_125 = V_10 [ 1 ] ;
V_113 = F_20 ( V_5 , V_125 ) ;
if ( V_113 < 0 )
return V_113 ;
V_10 [ 1 ] = V_113 ;
return 2 ;
}
static int F_41 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_126 * V_127 )
{
int V_128 = 0 ;
int V_88 ;
V_128 |= F_42 ( & V_127 -> V_129 , V_130 ) ;
V_128 |= F_42 ( & V_127 -> V_131 , V_132 ) ;
V_128 |= F_42 ( & V_127 -> V_133 , V_130 ) ;
V_128 |= F_42 ( & V_127 -> V_134 , V_135 ) ;
V_128 |= F_42 ( & V_127 -> V_136 , V_135 | V_137 ) ;
if ( V_128 )
return 1 ;
V_128 |= F_43 ( V_127 -> V_136 ) ;
if ( V_128 )
return 2 ;
if ( ! V_127 -> V_138 ) {
V_127 -> V_138 = 32 ;
V_128 |= - V_115 ;
}
V_128 |= F_44 ( & V_127 -> V_139 , V_127 -> V_138 ) ;
switch ( V_127 -> V_136 ) {
case V_135 :
V_128 |= F_45 ( & V_127 -> V_140 , 1 ) ;
break;
case V_137 :
V_128 |= F_44 ( & V_127 -> V_140 , 0 ) ;
break;
default:
break;
}
if ( V_128 )
return 3 ;
if ( V_128 )
return 4 ;
if ( ! V_127 -> V_141 )
return 0 ;
for ( V_88 = 1 ; V_88 < V_127 -> V_138 ; V_88 ++ ) {
if ( F_46 ( V_127 -> V_141 [ V_88 ] ) != V_88 ) {
F_47 ( V_5 ,
L_28 ) ;
V_128 ++ ;
break;
}
}
if ( V_128 )
return 5 ;
return 0 ;
}
static int V_60 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_126 * V_127 )
{
if ( V_7 -> V_142 )
return - V_115 ;
else
return F_41 ( V_5 , V_7 , V_127 ) ;
}
static inline void F_48 ( struct V_4 * V_5 , T_1 V_19 ,
unsigned int V_143 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
F_9 ( V_19 | V_15 -> V_19 [ V_143 / sizeof( T_1 ) ] ,
V_15 -> V_65 + V_143 ) ;
}
static int F_49 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
T_1 V_19 ;
unsigned long V_144 ;
struct V_145 * V_146 = V_7 -> V_146 ;
struct V_126 * V_127 = & V_146 -> V_127 ;
F_48 ( V_5 , V_147 , V_66 ) ;
F_11 ( L_29 ) ;
F_15 ( V_5 , 0 ) ;
V_15 -> V_148 = 0 ;
F_9 ( 0 , V_15 -> V_17 + V_28 ) ;
F_9 ( 0 , V_15 -> V_17 + V_26 ) ;
F_9 ( 0 , V_15 -> V_17 + V_27 ) ;
V_19 =
V_15 -> V_90 | V_85 |
V_86 | V_87 ;
F_9 ( V_19 , V_15 -> V_17 + V_29 ) ;
F_50 ( & V_5 -> V_149 , V_144 ) ;
F_51 ( V_150 | V_151 | V_152 ,
V_15 -> V_17 + V_30 ) ;
F_52 ( & V_5 -> V_149 , V_144 ) ;
if ( V_127 -> V_136 == V_135 )
V_15 -> V_153 = V_127 -> V_140 ;
else
V_15 -> V_153 = 1 ;
F_9 ( V_154 | V_155 ,
V_15 -> V_65 + V_156 ) ;
F_9 ( F_3 ( V_157 ) ,
V_15 -> V_65 + V_73 ) ;
F_11 ( L_30 ) ;
F_48 ( V_5 , V_158 , V_66 ) ;
return 0 ;
}
static int V_58 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
if ( V_7 -> V_142 )
return - V_115 ;
else
return F_49 ( V_5 , V_7 ) ;
}
static void F_53 ( struct V_4 * V_5 , unsigned int V_159 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_145 * V_146 = V_5 -> V_44 -> V_146 ;
T_1 V_160 ;
int V_161 ;
int V_162 = 0 ;
void T_2 * V_163 ;
if ( V_159 )
V_163 =
V_15 -> V_17 + V_164 ;
else
V_163 =
V_15 -> V_17 + V_26 ;
V_161 = 0 ;
for ( V_160 = F_12 ( V_163 ) ;
( V_160 <
F_54 ( V_15 -> V_93 [ V_15 -> V_148 ] .
V_94 )
|| V_160 >=
F_54 ( V_15 -> V_93 [ V_15 -> V_148 ] .
V_94 ) + V_15 -> V_102 )
&& V_161 < V_15 -> V_101 ; V_161 ++ ) {
V_162 = V_15 -> V_102 / sizeof( T_1 ) ;
if ( V_146 -> V_127 . V_136 == V_135 ) {
if ( V_162 > V_15 -> V_153 )
V_162 = V_15 -> V_153 ;
V_15 -> V_153 -= V_162 ;
}
F_55 ( V_5 -> V_44 ,
V_15 -> V_99 [ V_15 ->
V_148 ] ,
V_162 * sizeof( T_1 ) ) ;
V_15 -> V_148 ++ ;
V_15 -> V_148 %= V_15 -> V_101 ;
F_11 ( L_31 , ( unsigned long )
V_15 -> V_93 [ V_15 -> V_148 ] .
V_98 ) ;
F_11 ( L_32 , V_160 ) ;
}
}
static T_3 V_121 ( int V_120 , void * V_165 )
{
struct V_4 * V_5 = V_165 ;
struct V_14 * V_15 = V_5 -> V_16 ;
struct V_6 * V_7 = V_5 -> V_44 ;
struct V_145 * V_146 = V_7 -> V_146 ;
T_1 V_166 , V_167 ;
T_1 V_168 ;
T_1 V_169 ;
T_4 V_170 , V_171 ;
unsigned long V_144 ;
if ( ! V_5 -> V_172 )
return V_173 ;
V_168 = F_12 ( V_15 -> V_17 + V_18 ) ;
if ( ( V_168 & ( V_174 | V_175 | V_176 ) ) == 0 )
return V_173 ;
V_166 = F_12 ( V_15 -> V_65 + V_177 ) ;
V_167 = F_12 ( V_15 -> V_65 + V_156 ) ;
V_146 -> V_178 = 0 ;
if ( V_166 ) {
F_11 ( L_33 , V_166 ) ;
F_9 ( V_166 ,
V_15 -> V_65 + V_177 ) ;
}
F_50 ( & V_5 -> V_149 , V_144 ) ;
V_170 = F_13 ( V_15 -> V_17 + V_30 ) ;
if ( V_168 & V_174 ) {
F_51 ( ( V_170 & V_150 ) | V_152 ,
V_15 -> V_17 + V_30 ) ;
F_11 ( L_34 , V_170 ) ;
if ( V_170 & V_150 )
F_53 ( V_5 , 0 ) ;
F_11 ( L_35 ) ;
}
F_52 ( & V_5 -> V_149 , V_144 ) ;
F_50 ( & V_5 -> V_149 , V_144 ) ;
V_171 = F_13 ( V_15 -> V_17 + V_179 ) ;
if ( V_168 & V_175 ) {
F_51 ( ( V_171 & V_150 ) | V_152 ,
V_15 -> V_17 + V_179 ) ;
F_11 ( L_36 , V_171 ) ;
F_11 ( L_37 ) ;
}
F_52 ( & V_5 -> V_149 , V_144 ) ;
if ( V_168 & V_180 ) {
V_169 = F_12 ( V_15 -> V_17 + V_181 ) ;
F_9 ( V_169 , V_15 -> V_17 + V_181 ) ;
F_11 ( L_38 , V_169 ) ;
}
if ( V_167 & V_155 ) {
F_47 ( V_5 , L_39 ) ;
V_146 -> V_178 |= V_182 | V_183 ;
F_11 ( L_40 ,
( int ) F_13 ( V_15 -> V_17 +
V_30 ) ) ;
}
if ( V_167 & V_154 ) {
F_47 ( V_5 , L_41 ) ;
V_146 -> V_178 |= V_182 | V_183 ;
}
if ( V_15 -> V_153 == 0 )
V_146 -> V_178 |= V_182 ;
F_11 ( L_42 , V_167 ) ;
F_11 ( L_43 , V_168 ) ;
if ( V_146 -> V_178 )
F_11 ( L_44 , V_146 -> V_178 ) ;
F_56 ( V_5 , V_7 ) ;
return V_184 ;
}
static void F_15 ( struct V_4 * V_5 , unsigned int V_159 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
unsigned long V_144 ;
F_50 ( & V_5 -> V_149 , V_144 ) ;
F_57 ( V_15 -> V_17 , V_159 ) ;
F_52 ( & V_5 -> V_149 , V_144 ) ;
}
static int V_62 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_14 * V_15 = V_5 -> V_16 ;
F_48 ( V_5 , 0 , V_66 ) ;
F_9 ( 0 , V_15 -> V_65 + V_73 ) ;
F_15 ( V_5 , 0 ) ;
return 0 ;
}
static int F_58 ( struct V_104 * V_5 ,
const struct V_185 * V_186 )
{
return F_59 ( V_5 , & V_187 , V_186 -> V_188 ) ;
}
