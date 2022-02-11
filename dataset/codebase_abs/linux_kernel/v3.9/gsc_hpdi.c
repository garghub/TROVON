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
struct V_6 * V_7 , struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
switch ( V_10 [ 0 ] ) {
case V_14 :
V_12 -> V_15 = 1 ;
return V_9 -> V_16 ;
break;
case V_17 :
V_12 -> V_15 = 0 ;
return V_9 -> V_16 ;
break;
case V_18 :
V_10 [ 1 ] =
V_12 -> V_15 ? V_19 : V_20 ;
return V_9 -> V_16 ;
break;
case V_21 :
return F_6 ( V_5 , V_10 ) ;
break;
default:
break;
}
return - V_22 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
F_8 ( 0 , V_12 -> V_23 + V_24 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
T_1 V_25 ;
void T_2 * V_26 = V_12 -> V_23 ;
F_10 ( L_1 ,
F_11 ( V_26 + V_24 ) ) ;
F_10 ( L_2 , F_11 ( V_26 + V_27 ) ) ;
F_10 ( L_3 ,
F_11 ( V_12 -> V_23 + V_28 ) ) ;
F_10 ( L_4 ,
F_11 ( V_26 + V_29 ) ) ;
F_10 ( L_5 ,
F_11 ( V_26 + V_30 ) ) ;
F_10 ( L_6 ,
F_11 ( V_26 + V_31 ) ) ;
F_10 ( L_7 ,
F_11 ( V_26 + V_32 ) ) ;
F_10 ( L_8 ,
F_11 ( V_26 + V_33 ) ) ;
F_10 ( L_9 ,
F_11 ( V_26 + V_34 ) ) ;
F_10 ( L_10 ,
F_11 ( V_26 + V_35 ) ) ;
F_10 ( L_11 ,
F_12 ( V_26 + V_36 ) ) ;
F_10 ( L_12 ,
F_11 ( V_26 + V_37 ) ) ;
F_10 ( L_13 , F_11 ( V_26 + V_38 ) ) ;
#ifdef F_13
V_25 = V_39 | V_40 ;
#else
V_25 = 0 ;
#endif
F_8 ( V_25 , V_12 -> V_23 + V_38 ) ;
F_7 ( V_5 ) ;
F_14 ( V_5 , 0 ) ;
F_14 ( V_5 , 1 ) ;
V_25 = 0 ;
V_25 |= V_41 ;
V_25 |= V_42 ;
V_25 |= V_43 ;
V_25 |= V_44 ;
V_25 |= V_45 ;
V_25 |= V_46 ;
V_25 |= V_47 ;
V_25 |= V_48 ;
F_8 ( V_25 , V_26 + V_30 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_49 ;
V_49 = F_16 ( V_5 , 1 ) ;
if ( V_49 )
return V_49 ;
V_7 = & V_5 -> V_50 [ 0 ] ;
V_5 -> V_51 = V_7 ;
V_7 -> type = V_52 ;
V_7 -> V_53 =
V_54 | V_55 | V_56 | V_57 ;
V_7 -> V_58 = 32 ;
V_7 -> V_59 = 32 ;
V_7 -> V_60 = 1 ;
V_7 -> V_61 = & V_62 ;
V_7 -> V_63 = F_5 ;
V_7 -> V_64 = V_65 ;
V_7 -> V_66 = V_67 ;
V_7 -> V_68 = V_69 ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
T_1 V_70 ;
F_8 ( V_71 , V_12 -> V_72 + V_73 ) ;
F_18 ( 10 ) ;
F_8 ( F_2 ( 32 ) | F_1 ( 32 ) ,
V_12 -> V_72 + V_74 ) ;
F_8 ( F_2 ( 32 ) | F_1 ( 32 ) ,
V_12 -> V_72 + V_75 ) ;
V_12 -> V_76 = F_4 ( F_11 ( V_12 -> V_72 +
V_77 ) ) ;
V_12 -> V_78 = F_4 ( F_11 ( V_12 -> V_72 +
V_79 ) ) ;
F_8 ( 0 , V_12 -> V_72 + V_80 ) ;
V_70 =
V_81 | V_82 | V_83 | V_84 | V_85 | V_86 |
V_87 ;
F_8 ( V_70 , V_12 -> V_23 + V_24 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 ,
unsigned int V_88 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
unsigned int V_89 , V_90 ;
T_1 V_91 = V_92 | V_93 |
V_94 ;
unsigned int V_95 ;
if ( V_88 > V_96 )
V_88 = V_96 ;
V_88 -= V_88 % sizeof( T_1 ) ;
if ( V_88 == 0 )
return - 1 ;
F_10 ( L_14 , V_88 ) ;
F_10 ( L_15 ,
( unsigned long ) V_12 -> V_97 ) ;
V_90 = 0 ;
V_89 = 0 ;
for ( V_95 = 0 ; V_95 < V_98 &&
V_89 < V_99 ; V_95 ++ ) {
V_12 -> V_100 [ V_95 ] . V_101 =
F_20 ( V_12 -> V_102 [ V_89 ] +
V_90 ) ;
V_12 -> V_100 [ V_95 ] . V_103 = F_20 ( V_104 ) ;
V_12 -> V_100 [ V_95 ] . V_88 =
F_20 ( V_88 ) ;
V_12 -> V_100 [ V_95 ] . V_105 =
F_20 ( ( V_12 -> V_97 + ( V_95 +
1 ) *
sizeof( V_12 -> V_100 [ 0 ] ) ) | V_91 ) ;
V_12 -> V_106 [ V_95 ] =
V_12 -> V_107 [ V_89 ] +
( V_90 / sizeof( T_1 ) ) ;
V_90 += V_88 ;
if ( V_88 + V_90 > V_96 ) {
V_90 = 0 ;
V_89 ++ ;
}
F_10 ( L_16 , V_95 ) ;
F_10 ( L_17 ,
V_12 -> V_106 [ V_95 ] ,
( unsigned long ) V_12 -> V_100 [ V_95 ] .
V_101 ) ;
F_10 ( L_18 ,
( unsigned long ) V_12 -> V_100 [ V_95 ] . V_105 ) ;
}
V_12 -> V_108 = V_95 ;
V_12 -> V_100 [ V_95 - 1 ] . V_105 =
F_20 ( V_12 -> V_97 | V_91 ) ;
F_10 ( L_19 , V_95 - 1 ,
( unsigned long ) V_12 -> V_100 [ V_95 - 1 ] . V_105 ) ;
V_12 -> V_109 = V_88 ;
return V_88 ;
}
static const struct V_110 * F_21 ( struct V_111 * V_112 )
{
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < F_22 ( V_113 ) ; V_95 ++ )
if ( V_112 -> V_114 == V_113 [ V_95 ] . V_115 &&
V_112 -> V_116 == V_113 [ V_95 ] . V_117 )
return & V_113 [ V_95 ] ;
return NULL ;
}
static int F_23 ( struct V_4 * V_5 ,
unsigned long V_118 )
{
struct V_111 * V_112 = F_24 ( V_5 ) ;
const struct V_110 * V_119 ;
struct V_11 * V_12 ;
int V_95 ;
int V_120 ;
V_119 = F_21 ( V_112 ) ;
if ( ! V_119 ) {
F_25 ( V_5 -> V_121 , L_20 ,
F_26 ( V_112 ) ) ;
return - V_22 ;
}
V_5 -> V_122 = V_119 ;
V_5 -> V_123 = V_119 -> V_124 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_125 ) ;
if ( ! V_12 )
return - V_126 ;
V_5 -> V_13 = V_12 ;
if ( F_28 ( V_112 , V_5 -> V_123 ) ) {
F_29 ( V_5 -> V_121 ,
L_21 ) ;
return - V_127 ;
}
V_5 -> V_128 = 1 ;
F_30 ( V_112 ) ;
V_12 -> V_23 =
F_31 ( F_32 ( V_112 , V_129 ) ,
F_33 ( V_112 , V_129 ) ) ;
V_12 -> V_72 =
F_31 ( F_32 ( V_112 , V_130 ) ,
F_33 ( V_112 , V_130 ) ) ;
if ( ! V_12 -> V_23 || ! V_12 -> V_72 ) {
F_29 ( V_5 -> V_121 , L_22 ) ;
return - V_126 ;
}
F_10 ( L_23 , V_12 -> V_23 ) ;
F_10 ( L_24 , V_12 -> V_72 ) ;
F_9 ( V_5 ) ;
if ( F_34 ( V_112 -> V_131 , V_132 , V_133 ,
V_5 -> V_123 , V_5 ) ) {
F_29 ( V_5 -> V_121 ,
L_25 , V_112 -> V_131 ) ;
return - V_22 ;
}
V_5 -> V_131 = V_112 -> V_131 ;
F_35 ( V_5 -> V_121 , L_26 , V_5 -> V_131 ) ;
for ( V_95 = 0 ; V_95 < V_99 ; V_95 ++ ) {
V_12 -> V_107 [ V_95 ] =
F_36 ( V_112 , V_96 ,
& V_12 -> V_102 [ V_95 ] ) ;
F_10 ( L_27 ,
V_12 -> V_107 [ V_95 ] ,
( unsigned long ) V_12 -> V_102 [ V_95 ] ) ;
}
V_12 -> V_100 = F_36 ( V_112 ,
sizeof( struct V_134 ) *
V_98 ,
& V_12 -> V_97 ) ;
if ( V_12 -> V_97 & 0xf ) {
F_29 ( V_5 -> V_121 ,
L_28 ) ;
return - V_127 ;
}
V_120 = F_19 ( V_5 , 0x1000 ) ;
if ( V_120 < 0 )
return V_120 ;
V_120 = F_15 ( V_5 ) ;
if ( V_120 < 0 )
return V_120 ;
return F_17 ( V_5 ) ;
}
static void F_37 ( struct V_4 * V_5 )
{
struct V_111 * V_112 = F_24 ( V_5 ) ;
struct V_11 * V_12 = V_5 -> V_13 ;
unsigned int V_95 ;
if ( V_5 -> V_131 )
F_38 ( V_5 -> V_131 , V_5 ) ;
if ( V_12 ) {
if ( V_12 -> V_23 ) {
F_7 ( V_5 ) ;
F_39 ( V_12 -> V_23 ) ;
}
if ( V_12 -> V_72 )
F_39 ( V_12 -> V_72 ) ;
for ( V_95 = 0 ; V_95 < V_99 ; V_95 ++ ) {
if ( V_12 -> V_107 [ V_95 ] )
F_40 ( V_112 ,
V_96 ,
V_12 -> V_107 [ V_95 ] ,
V_12 ->
V_102 [ V_95 ] ) ;
}
if ( V_12 -> V_100 )
F_40 ( V_112 ,
sizeof( struct V_134 ) *
V_98 ,
V_12 -> V_100 ,
V_12 -> V_97 ) ;
if ( V_5 -> V_128 )
F_41 ( V_112 ) ;
}
}
static int F_6 ( struct V_4 * V_5 , unsigned int * V_10 )
{
unsigned int V_135 ;
int V_120 ;
V_135 = V_10 [ 1 ] ;
V_120 = F_19 ( V_5 , V_135 ) ;
if ( V_120 < 0 )
return V_120 ;
V_10 [ 1 ] = V_120 ;
return 2 ;
}
static int F_42 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_136 * V_137 )
{
int V_138 = 0 ;
int V_95 ;
V_138 |= F_43 ( & V_137 -> V_139 , V_140 ) ;
V_138 |= F_43 ( & V_137 -> V_141 , V_142 ) ;
V_138 |= F_43 ( & V_137 -> V_143 , V_140 ) ;
V_138 |= F_43 ( & V_137 -> V_144 , V_145 ) ;
V_138 |= F_43 ( & V_137 -> V_146 , V_145 | V_147 ) ;
if ( V_138 )
return 1 ;
V_138 |= F_44 ( V_137 -> V_146 ) ;
if ( V_138 )
return 2 ;
if ( ! V_137 -> V_148 ) {
V_137 -> V_148 = 32 ;
V_138 |= - V_22 ;
}
V_138 |= F_45 ( & V_137 -> V_149 , V_137 -> V_148 ) ;
switch ( V_137 -> V_146 ) {
case V_145 :
V_138 |= F_46 ( & V_137 -> V_150 , 1 ) ;
break;
case V_147 :
V_138 |= F_45 ( & V_137 -> V_150 , 0 ) ;
break;
default:
break;
}
if ( V_138 )
return 3 ;
if ( V_138 )
return 4 ;
if ( ! V_137 -> V_151 )
return 0 ;
for ( V_95 = 1 ; V_95 < V_137 -> V_148 ; V_95 ++ ) {
if ( F_47 ( V_137 -> V_151 [ V_95 ] ) != V_95 ) {
F_48 ( V_5 ,
L_29 ) ;
V_138 ++ ;
break;
}
}
if ( V_138 )
return 5 ;
return 0 ;
}
static int V_67 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_136 * V_137 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
if ( V_12 -> V_15 )
return - V_22 ;
else
return F_42 ( V_5 , V_7 , V_137 ) ;
}
static inline void F_49 ( struct V_4 * V_5 , T_1 V_25 ,
unsigned int V_152 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
F_8 ( V_25 | V_12 -> V_25 [ V_152 / sizeof( T_1 ) ] ,
V_12 -> V_72 + V_152 ) ;
}
static int F_50 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
T_1 V_25 ;
unsigned long V_153 ;
struct V_154 * V_155 = V_7 -> V_155 ;
struct V_136 * V_137 = & V_155 -> V_137 ;
F_49 ( V_5 , V_156 , V_73 ) ;
F_10 ( L_30 ) ;
F_14 ( V_5 , 0 ) ;
V_12 -> V_157 = 0 ;
F_8 ( 0 , V_12 -> V_23 + V_34 ) ;
F_8 ( 0 , V_12 -> V_23 + V_32 ) ;
F_8 ( 0 , V_12 -> V_23 + V_33 ) ;
V_25 =
V_12 -> V_97 | V_92 |
V_93 | V_94 ;
F_8 ( V_25 , V_12 -> V_23 + V_35 ) ;
F_51 ( & V_5 -> V_158 , V_153 ) ;
F_52 ( V_159 | V_160 | V_161 ,
V_12 -> V_23 + V_36 ) ;
F_53 ( & V_5 -> V_158 , V_153 ) ;
if ( V_137 -> V_146 == V_145 )
V_12 -> V_162 = V_137 -> V_150 ;
else
V_12 -> V_162 = 1 ;
F_8 ( V_163 | V_164 ,
V_12 -> V_72 + V_165 ) ;
F_8 ( F_3 ( V_166 ) ,
V_12 -> V_72 + V_80 ) ;
F_10 ( L_31 ) ;
F_49 ( V_5 , V_167 , V_73 ) ;
return 0 ;
}
static int V_65 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
if ( V_12 -> V_15 )
return - V_22 ;
else
return F_50 ( V_5 , V_7 ) ;
}
static void F_54 ( struct V_4 * V_5 , unsigned int V_168 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
struct V_154 * V_155 = V_5 -> V_51 -> V_155 ;
T_1 V_169 ;
int V_170 ;
int V_171 = 0 ;
void T_2 * V_172 ;
if ( V_168 )
V_172 =
V_12 -> V_23 + V_173 ;
else
V_172 =
V_12 -> V_23 + V_32 ;
V_170 = 0 ;
for ( V_169 = F_11 ( V_172 ) ;
( V_169 <
F_55 ( V_12 -> V_100 [ V_12 -> V_157 ] .
V_101 )
|| V_169 >=
F_55 ( V_12 -> V_100 [ V_12 -> V_157 ] .
V_101 ) + V_12 -> V_109 )
&& V_170 < V_12 -> V_108 ; V_170 ++ ) {
V_171 = V_12 -> V_109 / sizeof( T_1 ) ;
if ( V_155 -> V_137 . V_146 == V_145 ) {
if ( V_171 > V_12 -> V_162 )
V_171 = V_12 -> V_162 ;
V_12 -> V_162 -= V_171 ;
}
F_56 ( V_5 -> V_51 ,
V_12 -> V_106 [ V_12 ->
V_157 ] ,
V_171 * sizeof( T_1 ) ) ;
V_12 -> V_157 ++ ;
V_12 -> V_157 %= V_12 -> V_108 ;
F_10 ( L_32 , ( unsigned long )
V_12 -> V_100 [ V_12 -> V_157 ] .
V_105 ) ;
F_10 ( L_33 , V_169 ) ;
}
}
static T_3 V_132 ( int V_131 , void * V_174 )
{
struct V_4 * V_5 = V_174 ;
struct V_11 * V_12 = V_5 -> V_13 ;
struct V_6 * V_7 = V_5 -> V_51 ;
struct V_154 * V_155 = V_7 -> V_155 ;
T_1 V_175 , V_176 ;
T_1 V_177 ;
T_1 V_178 ;
T_4 V_179 , V_180 ;
unsigned long V_153 ;
if ( ! V_5 -> V_181 )
return V_182 ;
V_177 = F_11 ( V_12 -> V_23 + V_24 ) ;
if ( ( V_177 & ( V_183 | V_184 | V_185 ) ) == 0 )
return V_182 ;
V_175 = F_11 ( V_12 -> V_72 + V_186 ) ;
V_176 = F_11 ( V_12 -> V_72 + V_165 ) ;
V_155 -> V_187 = 0 ;
if ( V_175 ) {
F_10 ( L_34 , V_175 ) ;
F_8 ( V_175 ,
V_12 -> V_72 + V_186 ) ;
}
F_51 ( & V_5 -> V_158 , V_153 ) ;
V_179 = F_12 ( V_12 -> V_23 + V_36 ) ;
if ( V_177 & V_183 ) {
F_52 ( ( V_179 & V_159 ) | V_161 ,
V_12 -> V_23 + V_36 ) ;
F_10 ( L_35 , V_179 ) ;
if ( V_179 & V_159 )
F_54 ( V_5 , 0 ) ;
F_10 ( L_36 ) ;
}
F_53 ( & V_5 -> V_158 , V_153 ) ;
F_51 ( & V_5 -> V_158 , V_153 ) ;
V_180 = F_12 ( V_12 -> V_23 + V_188 ) ;
if ( V_177 & V_184 ) {
F_52 ( ( V_180 & V_159 ) | V_161 ,
V_12 -> V_23 + V_188 ) ;
F_10 ( L_37 , V_180 ) ;
F_10 ( L_38 ) ;
}
F_53 ( & V_5 -> V_158 , V_153 ) ;
if ( V_177 & V_189 ) {
V_178 = F_11 ( V_12 -> V_23 + V_190 ) ;
F_8 ( V_178 , V_12 -> V_23 + V_190 ) ;
F_10 ( L_39 , V_178 ) ;
}
if ( V_176 & V_164 ) {
F_48 ( V_5 , L_40 ) ;
V_155 -> V_187 |= V_191 | V_192 ;
F_10 ( L_41 ,
( int ) F_12 ( V_12 -> V_23 +
V_36 ) ) ;
}
if ( V_176 & V_163 ) {
F_48 ( V_5 , L_42 ) ;
V_155 -> V_187 |= V_191 | V_192 ;
}
if ( V_12 -> V_162 == 0 )
V_155 -> V_187 |= V_191 ;
F_10 ( L_43 , V_176 ) ;
F_10 ( L_44 , V_177 ) ;
if ( V_155 -> V_187 )
F_10 ( L_45 , V_155 -> V_187 ) ;
F_57 ( V_5 , V_7 ) ;
return V_193 ;
}
static void F_14 ( struct V_4 * V_5 , unsigned int V_168 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
unsigned long V_153 ;
F_51 ( & V_5 -> V_158 , V_153 ) ;
F_58 ( V_12 -> V_23 , V_168 ) ;
F_53 ( & V_5 -> V_158 , V_153 ) ;
}
static int V_69 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_11 * V_12 = V_5 -> V_13 ;
F_49 ( V_5 , 0 , V_73 ) ;
F_8 ( 0 , V_12 -> V_72 + V_80 ) ;
F_14 ( V_5 , 0 ) ;
return 0 ;
}
static int F_59 ( struct V_111 * V_5 ,
const struct V_194 * V_195 )
{
return F_60 ( V_5 , & V_196 ) ;
}
