static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_7 ) ;
}
static inline struct V_8 * F_4 ( struct V_9 * V_10 )
{
return F_2 ( V_10 , struct V_8 , V_10 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_11 , T_1 V_12 )
{
return F_6 ( V_11 -> V_13 + V_12 ) ;
}
static inline void F_7 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 )
{
F_8 ( V_14 , V_11 -> V_13 + V_12 ) ;
}
static inline T_1 F_9 ( struct V_1 * V_11 , T_1 V_12 )
{
return F_6 ( V_11 -> V_15 + V_12 ) ;
}
static inline void F_10 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 )
{
F_8 ( V_14 , V_11 -> V_15 + V_12 ) ;
}
static inline T_1 F_11 ( struct V_1 * V_11 , T_1 V_12 , int V_16 )
{
return F_6 ( V_11 -> V_15 + V_17 + V_12 +
( V_18 * V_16 ) ) ;
}
static inline void F_12 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 ,
int V_16 )
{
F_8 ( V_14 , V_11 -> V_15 + V_17 + V_12 +
( V_18 * V_16 ) ) ;
}
static inline T_1 F_13 ( struct V_1 * V_11 , T_1 V_12 , int V_16 )
{
return F_6 ( V_11 -> V_15 + V_19 + V_12 +
( V_18 * V_16 ) ) ;
}
static inline void F_14 ( struct V_1 * V_11 , T_1 V_14 , T_1 V_12 ,
int V_16 )
{
F_8 ( V_14 , V_11 -> V_15 + V_19 + V_12 +
( V_18 * V_16 ) ) ;
}
static inline void F_15 ( struct V_1 * V_11 , bool V_20 )
{
if ( V_20 ) {
F_16 ( V_11 -> V_21 ) ;
F_16 ( V_11 -> V_22 ) ;
F_17 ( 10 ) ;
} else {
F_18 ( V_11 -> V_22 ) ;
F_18 ( V_11 -> V_21 ) ;
}
}
static void F_19 ( struct V_1 * V_11 , int V_23 )
{
T_1 V_14 = F_5 ( V_11 , V_24 ) ;
V_14 &= ~ V_25 ;
V_14 |= V_23 << V_26 ;
F_7 ( V_11 , V_14 , V_24 ) ;
}
static void F_20 ( struct V_1 * V_11 , struct V_5 * V_27 ,
bool V_28 )
{
T_1 V_14 ;
V_14 = V_29 |
( V_28 ? V_30 : 0 ) |
( V_27 -> V_31 << V_32 ) ;
F_7 ( V_11 , V_14 , V_33 ) ;
}
static void F_21 ( struct V_1 * V_11 )
{
int V_34 = V_11 -> V_4 . V_35 == V_36 ;
T_1 V_37 , V_14 , V_38 , V_39 ;
V_38 = V_39 = 0 ;
for ( V_37 = 0 ; V_37 < V_40 ; V_37 += 2 ) {
const struct V_41 * V_42 = & V_43 [ V_37 ] ;
const struct V_41 * V_44 = & V_43 [ V_37 + 1 ] ;
F_19 ( V_11 , V_37 >> 1 ) ;
V_14 = ( V_38 << V_45 ) |
( ( V_38 + V_42 -> V_46 - 1 ) <<
V_47 ) ;
V_38 += V_42 -> V_46 ;
F_7 ( V_11 , V_14 , V_48 ) ;
F_7 ( V_11 ,
V_34 ? V_42 -> V_49 : V_42 -> V_50 ,
V_51 ) ;
V_14 = ( V_39 << V_52 ) |
( ( V_39 + V_44 -> V_46 - 1 ) <<
V_53 ) ;
V_39 += V_44 -> V_46 ;
F_7 ( V_11 , V_14 , V_54 ) ;
F_7 ( V_11 ,
V_34 ? V_44 -> V_49 : V_44 -> V_50 ,
V_55 ) ;
F_5 ( V_11 , V_55 ) ;
}
}
static void F_22 ( struct V_1 * V_11 , int V_31 )
{
T_1 V_14 ;
F_19 ( V_11 , V_31 ) ;
V_14 = F_5 ( V_11 , V_24 ) ;
V_14 |= V_56 ;
F_7 ( V_11 , V_14 , V_24 ) ;
F_5 ( V_11 , V_24 ) ;
}
static void F_23 ( struct V_1 * V_11 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_57 ; V_37 ++ )
F_22 ( V_11 , V_37 ) ;
}
static void F_24 ( struct V_1 * V_11 )
{
T_1 V_37 , V_14 ;
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ ) {
const struct V_41 * V_58 = & V_43 [ V_37 ] ;
if ( V_58 -> V_31 < 0 )
continue;
F_19 ( V_11 , V_58 -> V_31 ) ;
V_14 = ( V_58 -> V_59 << V_60 ) |
( ( V_37 >> 1 ) << V_61 ) ;
F_7 ( V_11 , V_14 , V_62 ) ;
}
}
static void F_25 ( struct V_1 * V_11 )
{
T_1 V_14 , V_37 ;
F_7 ( V_11 , V_63 , V_64 ) ;
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ ) {
const struct V_41 * V_58 = & V_43 [ V_37 ] ;
int V_65 = V_11 -> V_4 . V_35 == V_36 ?
V_58 -> V_49 : V_58 -> V_50 ;
int V_23 = V_58 -> V_31 ;
V_11 -> V_66 [ V_37 ] . V_65 = V_65 ;
if ( V_23 < 0 )
continue;
F_26 ( & V_11 -> V_27 [ V_23 ] . V_7 , V_65 ) ;
V_14 = ( V_23 << V_67 ) |
( V_58 -> V_68 << V_69 ) |
( V_58 -> V_59 << V_70 ) |
( V_11 -> V_58 << V_71 ) |
( V_11 -> V_72 << V_73 ) |
( V_11 -> V_74 << V_75 ) |
( V_65 << V_76 ) ;
F_7 ( V_11 , V_14 , F_27 ( V_23 ) ) ;
}
}
static void F_28 ( struct V_1 * V_11 , struct V_77 * V_66 ,
struct V_8 * V_78 )
{
int V_79 = 1 , V_80 = 0 , V_81 = 0 ;
unsigned int V_82 = V_78 -> V_10 . V_83 - V_78 -> V_84 ;
const int V_85 = ! V_86 && ! V_66 -> V_87 ?
V_66 -> V_65 : V_88 ;
V_66 -> V_89 = 0 ;
V_78 -> V_90 = 0 ;
V_78 -> V_66 = V_66 ;
if ( ( V_82 % V_66 -> V_65 == 0 ) && V_82 && V_78 -> V_10 . V_91 )
V_81 = 1 ;
do {
struct V_92 * V_93 = V_66 -> V_94 ;
T_1 V_95 = 0 ;
unsigned int V_96 ;
if ( V_93 == V_66 -> V_97 ) {
V_95 |= V_98 ;
V_66 -> V_94 = V_66 -> V_99 ;
} else {
V_66 -> V_94 ++ ;
}
V_66 -> V_89 ++ ;
V_96 = F_29 ( int , V_82 , V_85 ) ;
if ( V_96 )
V_95 |= V_96 << V_100 ;
else
V_95 |= ( 1 << V_100 ) |
V_101 ;
V_95 |= V_102 ;
if ( V_79 ) {
V_95 |= V_103 ;
V_79 = 0 ;
}
if ( V_81 && ! V_82 )
V_81 = 0 ;
if ( ! V_66 -> V_87 || V_66 -> V_89 == V_66 -> V_104 ||
( V_96 == V_82 && ! V_81 ) ) {
V_80 = 1 ;
V_95 |= V_105 ;
}
V_93 -> V_106 = V_78 -> V_10 . V_107 + V_78 -> V_84 ;
F_30 () ;
V_93 -> V_108 = V_95 ;
V_78 -> V_84 += V_96 ;
V_78 -> V_90 += V_96 ;
V_82 -= V_96 ;
} while ( ! V_80 );
F_12 ( V_11 , V_109 ,
V_110 , V_66 -> V_111 ) ;
}
static int F_31 ( struct V_1 * V_11 , struct V_77 * V_66 )
{
int V_37 , V_112 = 0 ;
struct V_92 * V_93 = V_66 -> V_113 ;
if ( ! V_66 -> V_89 )
return - V_114 ;
for ( V_37 = 0 ; V_37 < V_66 -> V_89 ; V_37 ++ ) {
T_1 V_95 ;
V_95 = V_93 -> V_108 ;
if ( V_95 & V_102 )
return - V_115 ;
V_112 += ( V_95 & V_116 ) >>
V_100 ;
if ( V_93 == V_66 -> V_97 )
V_93 = V_66 -> V_99 ;
else
V_93 ++ ;
}
V_66 -> V_113 = V_93 ;
V_66 -> V_89 = 0 ;
return V_112 ;
}
static void F_32 ( struct V_1 * V_11 , struct V_77 * V_66 )
{
int V_117 = V_118 ;
struct V_92 * V_93 ;
int V_111 = V_66 -> V_111 ;
if ( ! V_66 -> V_87 )
F_22 ( V_11 , F_33 ( 0 , V_66 -> V_31 ) ) ;
F_12 ( V_11 , 0 , V_110 , V_111 ) ;
while ( F_11 ( V_11 , V_110 , V_111 ) &
V_109 ) {
F_17 ( 1 ) ;
if ( V_66 -> V_87 && V_66 -> V_31 >= 0 )
F_22 ( V_11 , V_66 -> V_31 ) ;
if ( ! V_117 -- ) {
F_34 ( V_11 -> V_119 , L_1 ,
V_111 ) ;
break;
}
if ( V_117 == V_118 / 2 ) {
F_35 ( V_11 -> V_119 , L_2 ,
V_111 ) ;
F_12 ( V_11 , V_120 ,
V_110 , V_111 ) ;
}
}
F_12 ( V_11 , ~ 0 , V_121 , V_111 ) ;
for ( V_93 = V_66 -> V_99 ; V_93 <= V_66 -> V_97 ; V_93 ++ )
V_93 -> V_108 = 0 ;
F_30 () ;
V_66 -> V_113 = V_66 -> V_94 = V_66 -> V_99 ;
V_66 -> V_89 = 0 ;
F_12 ( V_11 , V_122 ,
V_123 , V_111 ) ;
F_12 ( V_11 , 8 , V_124 , V_111 ) ;
F_14 ( V_11 , V_66 -> V_125 , V_126 , V_111 ) ;
F_14 ( V_11 , 0 , V_127 , V_111 ) ;
}
static int F_36 ( struct V_1 * V_11 , unsigned int V_111 )
{
struct V_77 * V_66 = & V_11 -> V_66 [ V_111 ] ;
const struct V_41 * V_58 = & V_43 [ V_111 ] ;
unsigned int V_104 = V_58 -> V_104 ;
struct V_5 * V_27 = NULL ;
V_66 -> V_31 = V_58 -> V_31 ;
V_66 -> V_111 = V_111 ;
V_66 -> V_87 = ! ! ( V_111 & 0x01 ) ;
if ( V_66 -> V_31 >= 0 ) {
V_27 = & V_11 -> V_27 [ V_66 -> V_31 ] ;
V_27 -> V_66 = V_66 ;
F_37 ( & V_27 -> V_128 ) ;
}
V_66 -> V_27 = V_27 ;
V_66 -> V_11 = V_11 ;
if ( V_66 -> V_31 <= 0 )
V_66 -> V_129 = true ;
V_66 -> V_104 = V_104 ;
V_66 -> V_99 = F_38 ( V_11 -> V_119 ,
V_104 * sizeof( struct V_92 ) ,
& V_66 -> V_125 , V_130 ) ;
if ( ! V_66 -> V_99 )
return - V_131 ;
V_66 -> V_97 = & V_66 -> V_99 [ V_104 - 1 ] ;
return 0 ;
}
static int F_39 ( struct V_1 * V_11 )
{
int V_37 , V_132 ;
F_10 ( V_11 , V_133 , V_134 ) ;
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ ) {
V_132 = F_36 ( V_11 , V_37 ) ;
if ( V_132 )
return V_132 ;
F_32 ( V_11 , & V_11 -> V_66 [ V_37 ] ) ;
}
F_10 ( V_11 , F_40 ( V_40 ) - 1 , V_135 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_11 )
{
int V_37 ;
F_10 ( V_11 , 0 , V_135 ) ;
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ )
F_32 ( V_11 , & V_11 -> V_66 [ V_37 ] ) ;
F_10 ( V_11 , 0 , V_134 ) ;
}
static void F_42 ( struct V_1 * V_11 , bool V_136 )
{
T_1 V_14 ;
F_7 ( V_11 , 0 , V_137 ) ;
V_14 = F_40 ( V_138 ) |
F_40 ( V_139 ) |
F_40 ( V_140 ) |
F_40 ( V_141 ) |
F_40 ( V_142 ) ;
F_7 ( V_11 , V_136 ? V_14 : 0 , V_143 ) ;
F_7 ( V_11 , V_14 , V_144 ) ;
}
static void F_43 ( struct V_1 * V_11 , bool V_145 )
{
T_1 V_14 , V_146 = F_40 ( V_11 -> V_147 -> V_148 ) ;
if ( F_44 () ) {
V_14 = F_45 ( V_149 ) ;
V_14 &= ~ V_150 ;
V_14 |= V_145 ? V_151 :
V_152 ;
F_46 ( V_14 , V_149 ) ;
}
V_14 = F_47 ( V_153 , V_154 ) ;
if ( V_145 ) {
V_14 |= ( V_146 << V_155 ) ;
V_14 |= ( V_146 << V_156 ) ;
} else {
V_14 &= ~ ( V_146 << V_155 ) ;
V_14 &= ~ ( V_146 << V_156 ) ;
}
F_48 ( V_153 , V_14 , V_154 ) ;
V_14 = F_47 ( V_153 , V_157 ) ;
if ( V_145 )
V_14 |= V_158 ;
else
V_14 &= ~ V_158 ;
F_48 ( V_153 , V_14 , V_157 ) ;
}
static void F_49 ( struct V_1 * V_11 , bool V_159 )
{
T_1 V_14 , V_146 = F_40 ( V_11 -> V_147 -> V_148 ) ;
V_14 = F_47 ( V_153 , V_154 ) ;
if ( V_159 )
V_14 &= ~ ( V_146 << V_156 ) ;
else
V_14 |= ( V_146 << V_156 ) ;
F_48 ( V_153 , V_14 , V_154 ) ;
}
static void F_50 ( struct V_1 * V_11 )
{
F_15 ( V_11 , true ) ;
F_41 ( V_11 ) ;
F_15 ( V_11 , false ) ;
F_51 ( V_11 -> V_22 ) ;
F_51 ( V_11 -> V_21 ) ;
}
static int F_52 ( struct V_1 * V_11 )
{
int V_37 , V_132 = 0 ;
T_1 V_14 ;
V_11 -> V_160 = F_53 ( V_11 -> V_119 , V_161 ,
V_130 ) ;
if ( ! V_11 -> V_160 )
return - V_131 ;
F_37 ( & V_11 -> V_4 . V_162 ) ;
for ( V_37 = 0 ; V_37 < V_163 ; V_37 ++ ) {
struct V_5 * V_27 = & V_11 -> V_27 [ V_37 ] ;
V_27 -> V_7 . V_164 = V_165 [ V_37 ] ;
V_27 -> V_31 = V_37 ;
V_27 -> V_7 . V_166 = & V_167 ;
F_54 ( & V_27 -> V_7 . V_162 , & V_11 -> V_4 . V_162 ) ;
V_27 -> V_168 = 0 ;
F_26 ( & V_27 -> V_7 , V_161 ) ;
V_27 -> V_11 = V_11 ;
V_27 -> V_7 . V_169 = NULL ;
F_37 ( & V_27 -> V_128 ) ;
}
V_11 -> V_4 . V_170 = & V_11 -> V_27 [ 0 ] . V_7 ;
F_55 ( & V_11 -> V_27 [ 0 ] . V_7 . V_162 ) ;
V_11 -> V_4 . V_35 = V_171 ;
V_11 -> V_172 = V_173 ;
V_11 -> V_21 = F_56 ( V_11 -> V_119 , L_3 ) ;
if ( F_57 ( V_11 -> V_21 ) )
return - V_174 ;
V_11 -> V_22 = F_56 ( V_11 -> V_119 , L_4 ) ;
if ( F_57 ( V_11 -> V_22 ) ) {
F_51 ( V_11 -> V_21 ) ;
return - V_174 ;
}
F_15 ( V_11 , true ) ;
V_14 = V_175 |
V_176 |
( V_86 ? V_177 : 0 ) ;
F_7 ( V_11 , V_14 , V_24 ) ;
V_14 = V_178 |
V_179 |
V_180 |
V_181 |
V_182 ;
if ( V_11 -> V_4 . V_183 == V_36 )
V_14 |= ( V_184 << V_185 ) ;
else
V_14 |= ( V_186 << V_185 ) ;
F_7 ( V_11 , V_14 , V_187 ) ;
F_42 ( V_11 , false ) ;
F_7 ( V_11 , 0 , V_188 ) ;
V_14 = F_58 ( V_189 ) |
F_58 ( V_190 ) ;
F_7 ( V_11 , V_14 , V_191 ) ;
V_132 = F_39 ( V_11 ) ;
F_15 ( V_11 , false ) ;
if ( V_132 )
F_50 ( V_11 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 ,
const struct V_192 * V_169 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_77 * V_66 = V_27 -> V_66 ;
unsigned long V_193 ;
if ( ! V_7 || ! V_169 || V_7 -> V_164 == V_194 )
return - V_114 ;
if ( ! V_11 -> V_195 )
return - V_196 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
if ( V_66 -> V_129 ) {
F_61 ( & V_11 -> V_197 , V_193 ) ;
return - V_114 ;
}
V_66 -> V_129 = true ;
F_62 ( ! F_63 ( & V_27 -> V_128 ) ) ;
F_32 ( V_11 , V_66 ) ;
V_27 -> V_168 = 0 ;
F_20 ( V_11 , V_27 , false ) ;
F_64 ( V_27 -> V_31 , & V_11 -> V_198 ) ;
V_7 -> V_169 = V_169 ;
V_7 -> V_199 = F_65 ( V_169 ) ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_77 * V_66 = V_27 -> V_66 ;
struct V_200 * V_201 , * V_202 ;
unsigned long V_193 ;
if ( ! V_7 || ! V_7 -> V_169 )
return - V_114 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
if ( ! V_66 -> V_129 ) {
F_61 ( & V_11 -> V_197 , V_193 ) ;
return - V_114 ;
}
V_66 -> V_129 = false ;
F_32 ( V_11 , V_66 ) ;
if ( ! F_63 ( & V_27 -> V_128 ) ) {
F_67 (pos, n, &bep->queue) {
struct V_8 * V_78 =
F_68 ( V_201 , struct V_8 , V_128 ) ;
F_69 ( & V_11 -> V_4 , & V_78 -> V_10 ,
V_66 -> V_87 ) ;
F_55 ( & V_78 -> V_128 ) ;
V_78 -> V_10 . V_203 = - V_196 ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
V_78 -> V_10 . V_204 ( & V_66 -> V_27 -> V_7 , & V_78 -> V_10 ) ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
}
}
V_7 -> V_169 = NULL ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
return 0 ;
}
static struct V_9 * F_70 ( struct V_6 * V_7 ,
T_2 V_205 )
{
struct V_8 * V_78 ;
V_78 = F_71 ( sizeof( * V_78 ) , V_205 ) ;
if ( ! V_78 )
return NULL ;
return & V_78 -> V_10 ;
}
static void F_72 ( struct V_6 * V_7 ,
struct V_9 * V_10 )
{
struct V_8 * V_78 = F_4 ( V_10 ) ;
F_73 ( V_78 ) ;
}
static int F_74 ( struct V_6 * V_7 , struct V_9 * V_10 ,
T_2 V_205 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_8 * V_78 = F_4 ( V_10 ) ;
unsigned long V_193 ;
int V_132 = 0 ;
if ( F_75 ( ! V_10 || ! V_10 -> V_204 || ! V_10 -> V_206 || ! V_7 ) )
return - V_114 ;
V_10 -> V_207 = 0 ;
V_10 -> V_203 = 0 ;
V_78 -> V_84 = 0 ;
if ( V_27 == & V_11 -> V_27 [ 0 ] ) {
if ( V_11 -> V_208 )
return - V_114 ;
V_11 -> V_208 = V_10 ;
F_76 ( & V_11 -> V_209 ) ;
return 0 ;
}
F_60 ( & V_11 -> V_197 , V_193 ) ;
if ( ! V_27 -> V_66 -> V_129 ) {
V_132 = - V_196 ;
goto V_210;
}
V_132 = F_77 ( & V_11 -> V_4 , V_10 , V_27 -> V_66 -> V_87 ) ;
if ( V_132 == 0 ) {
F_54 ( & V_78 -> V_128 , & V_27 -> V_128 ) ;
if ( F_78 ( & V_27 -> V_128 ) )
F_28 ( V_11 , V_27 -> V_66 , V_78 ) ;
}
V_210:
F_61 ( & V_11 -> V_197 , V_193 ) ;
return V_132 ;
}
static int F_79 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_8 * V_78 = F_4 ( V_10 ) , * V_211 ;
unsigned long V_193 ;
int V_132 = 0 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
if ( F_63 ( & V_27 -> V_128 ) ) {
V_132 = - V_114 ;
goto V_210;
}
V_211 = F_80 ( & V_27 -> V_128 , struct V_8 , V_128 ) ;
F_69 ( & V_11 -> V_4 , & V_78 -> V_10 , V_27 -> V_66 -> V_87 ) ;
if ( V_78 == V_211 ) {
F_32 ( V_11 , V_27 -> V_66 ) ;
F_55 ( & V_78 -> V_128 ) ;
if ( ! F_63 ( & V_27 -> V_128 ) ) {
struct V_8 * V_212 ;
V_212 = F_80 ( & V_27 -> V_128 ,
struct V_8 , V_128 ) ;
F_28 ( V_11 , V_27 -> V_66 , V_212 ) ;
}
} else {
F_55 ( & V_78 -> V_128 ) ;
}
V_210:
F_61 ( & V_11 -> V_197 , V_193 ) ;
V_10 -> V_203 = - V_196 ;
V_10 -> V_204 ( V_7 , V_10 ) ;
return V_132 ;
}
static int F_81 ( struct V_6 * V_7 , int V_213 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
unsigned long V_193 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
F_20 ( V_11 , V_27 , ! ! V_213 ) ;
V_27 -> V_168 = V_213 ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
unsigned long V_193 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
F_83 ( V_27 -> V_31 , & V_11 -> V_198 ) ;
F_20 ( V_11 , V_27 , true ) ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_11 ,
struct V_214 * V_215 )
{
int V_132 ;
F_85 ( & V_11 -> V_197 ) ;
V_132 = V_11 -> V_195 -> V_216 ( & V_11 -> V_4 , V_215 ) ;
F_86 ( & V_11 -> V_197 ) ;
return V_132 ;
}
static int F_87 ( struct V_1 * V_11 )
{
struct V_214 V_215 ;
int V_132 ;
V_215 . V_217 = V_218 | V_219 ;
V_215 . V_220 = V_221 ;
V_215 . V_222 = F_88 ( V_11 -> V_58 ) ;
V_215 . V_223 = 0 ;
V_215 . V_224 = 0 ;
V_132 = F_84 ( V_11 , & V_215 ) ;
if ( V_132 < 0 ) {
F_89 ( V_11 -> V_119 ,
L_5 ,
V_11 -> V_58 ) ;
}
return V_132 ;
}
static int F_90 ( struct V_1 * V_11 )
{
struct V_214 V_215 ;
int V_132 ;
V_215 . V_217 = V_218 | V_225 ;
V_215 . V_220 = V_226 ;
V_215 . V_222 = F_88 ( V_11 -> V_74 ) ;
V_215 . V_223 = F_88 ( V_11 -> V_72 ) ;
V_215 . V_224 = 0 ;
V_132 = F_84 ( V_11 , & V_215 ) ;
if ( V_132 < 0 ) {
F_89 ( V_11 -> V_119 ,
L_6 ,
V_11 -> V_72 , V_11 -> V_74 ) ;
}
return V_132 ;
}
static void F_91 ( struct V_1 * V_11 , int V_111 ,
struct V_9 * V_10 )
{
struct V_8 * V_78 = F_4 ( V_10 ) ;
struct V_77 * V_66 = & V_11 -> V_66 [ V_111 ] ;
F_62 ( V_11 -> V_227 ) ;
V_11 -> V_227 = V_10 ;
V_10 -> V_207 = 0 ;
V_78 -> V_84 = 0 ;
F_77 ( & V_11 -> V_4 , V_10 , V_66 -> V_87 ) ;
F_28 ( V_11 , V_66 , V_78 ) ;
}
static void F_92 ( struct V_1 * V_11 ,
struct V_9 * V_10 , int V_203 )
{
V_10 -> V_203 = V_203 ;
if ( V_203 )
V_10 -> V_207 = 0 ;
if ( V_10 -> V_204 ) {
F_85 ( & V_11 -> V_197 ) ;
V_10 -> V_204 ( & V_11 -> V_27 [ 0 ] . V_7 , V_10 ) ;
F_86 ( & V_11 -> V_197 ) ;
}
}
static void F_93 ( struct V_1 * V_11 , int V_87 )
{
struct V_9 * V_10 = V_11 -> V_208 ;
V_11 -> V_208 = NULL ;
F_69 ( & V_11 -> V_4 , V_10 , V_87 ) ;
if ( V_11 -> V_227 == V_10 ) {
V_11 -> V_228 = 0 ;
V_11 -> V_227 = NULL ;
}
F_92 ( V_11 , V_10 , - V_196 ) ;
}
static int F_94 ( struct V_1 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_227 ;
V_11 -> V_228 = 0 ;
V_11 -> V_227 = NULL ;
return V_10 -> V_207 ;
}
static void F_95 ( struct V_1 * V_11 , int V_111 ,
int V_83 )
{
struct V_9 * V_10 = & V_11 -> V_229 . V_10 ;
V_10 -> V_206 = V_11 -> V_160 ;
V_10 -> V_83 = V_83 ;
V_10 -> V_204 = NULL ;
F_91 ( V_11 , V_111 , V_10 ) ;
}
static enum V_230 F_96 ( struct V_1 * V_11 )
{
int V_132 ;
struct V_214 * V_215 = ( void * ) V_11 -> V_160 ;
V_132 = F_94 ( V_11 ) ;
if ( V_132 < 0 ) {
F_34 ( V_11 -> V_119 , L_7 ) ;
return V_231 ;
}
if ( V_132 == 0 )
return V_232 ;
if ( V_132 != sizeof( * V_215 ) ) {
F_89 ( V_11 -> V_119 ,
L_8 , V_132 ) ;
return V_232 ;
}
V_132 = F_84 ( V_11 , V_215 ) ;
if ( V_132 < 0 ) {
F_20 ( V_11 , & V_11 -> V_27 [ 0 ] , true ) ;
return V_232 ;
}
if ( ! V_215 -> V_224 )
return V_232 ;
else if ( V_215 -> V_217 & V_233 )
return V_234 ;
else
return V_235 ;
}
static int F_97 ( struct V_1 * V_11 )
{
if ( V_11 -> V_236 ) {
V_11 -> V_236 = 0 ;
} else if ( V_11 -> V_237 ) {
V_11 -> V_237 = 0 ;
if ( F_87 ( V_11 ) >= 0 )
V_11 -> V_172 = V_238 ;
} else if ( V_11 -> V_239 ) {
V_11 -> V_239 = 0 ;
if ( F_90 ( V_11 ) >= 0 )
V_11 -> V_172 = V_238 ;
} else if ( V_11 -> V_228 ) {
V_11 -> V_172 = F_96 ( V_11 ) ;
return V_11 -> V_172 == V_231 ? - V_240 : 0 ;
} else if ( V_11 -> V_241 ) {
V_11 -> V_241 = 0 ;
V_11 -> V_228 = 0 ;
V_11 -> V_227 = NULL ;
F_32 ( V_11 , & V_11 -> V_66 [ V_242 ] ) ;
F_69 ( & V_11 -> V_4 ,
& V_11 -> V_229 . V_10 , 0 ) ;
F_30 () ;
V_11 -> V_172 = V_173 ;
} else if ( V_11 -> V_208 ) {
F_35 ( V_11 -> V_119 , L_9 ) ;
F_93 ( V_11 , 0 ) ;
} else {
return - V_240 ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_11 )
{
enum V_230 V_172 = V_11 -> V_172 ;
bool V_243 = V_11 -> V_236 || V_11 -> V_241 ;
switch ( V_11 -> V_172 ) {
case V_232 :
F_95 ( V_11 , V_242 ,
V_161 ) ;
V_172 = V_231 ;
break;
case V_231 :
return F_97 ( V_11 ) ;
case V_234 :
if ( V_11 -> V_208 ) {
F_91 ( V_11 , V_244 ,
V_11 -> V_208 ) ;
V_172 = V_245 ;
} else if ( V_243 ) {
V_172 = V_232 ;
}
break;
case V_245 : {
if ( V_11 -> V_228 ) {
V_11 -> V_208 = NULL ;
F_94 ( V_11 ) ;
V_172 = V_232 ;
} else if ( V_243 ) {
F_32 ( V_11 , & V_11 -> V_66 [ V_244 ] ) ;
F_93 ( V_11 , 1 ) ;
V_172 = V_232 ;
}
break;
}
case V_235 :
if ( V_11 -> V_208 ) {
F_91 ( V_11 , V_242 ,
V_11 -> V_208 ) ;
V_172 = V_246 ;
} else if ( V_243 ) {
V_172 = V_232 ;
}
break;
case V_246 : {
if ( V_11 -> V_228 ) {
V_11 -> V_208 = NULL ;
F_94 ( V_11 ) ;
F_95 ( V_11 , V_244 , 0 ) ;
V_172 = V_247 ;
} else if ( V_243 ) {
F_32 ( V_11 , & V_11 -> V_66 [ V_242 ] ) ;
F_93 ( V_11 , 0 ) ;
V_172 = V_232 ;
}
break;
}
case V_247 :
if ( V_11 -> V_228 ) {
F_94 ( V_11 ) ;
V_172 = V_232 ;
} else if ( V_243 ) {
F_32 ( V_11 , & V_11 -> V_66 [ V_244 ] ) ;
V_11 -> V_227 = NULL ;
V_172 = V_232 ;
}
break;
case V_238 : {
struct V_9 * V_248 = V_11 -> V_208 ;
if ( ! V_248 ) {
if ( V_243 )
V_172 = V_231 ;
break;
}
F_92 ( V_11 , V_248 , 0 ) ;
V_11 -> V_208 = NULL ;
V_172 = V_231 ;
break;
}
case V_173 :
break;
}
if ( V_11 -> V_172 == V_172 )
return - V_240 ;
V_11 -> V_172 = V_172 ;
return 0 ;
}
static void F_99 ( struct V_249 * V_250 )
{
struct V_1 * V_11 = F_2 ( V_250 , struct V_1 , V_209 ) ;
F_86 ( & V_11 -> V_197 ) ;
while ( F_98 ( V_11 ) == 0 )
;
F_85 ( & V_11 -> V_197 ) ;
}
static int F_100 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
return ( F_5 ( V_11 , V_137 ) &
V_251 ) >> V_252 ;
}
static int F_101 ( struct V_2 * V_4 , int V_159 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_193 ;
int V_37 , V_132 = - V_114 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
if ( V_159 && V_11 -> V_172 == V_173 ) {
V_11 -> V_4 . V_35 = V_171 ;
V_11 -> V_172 = V_232 ;
F_21 ( V_11 ) ;
F_23 ( V_11 ) ;
F_25 ( V_11 ) ;
F_102 ( & V_11 -> V_198 , V_163 ) ;
for ( V_37 = 0 ; V_37 < V_163 ; V_37 ++ )
F_20 ( V_11 , & V_11 -> V_27 [ V_37 ] , false ) ;
F_42 ( V_11 , true ) ;
F_49 ( F_1 ( V_4 ) , true ) ;
V_132 = 0 ;
} else if ( ! V_159 && V_11 -> V_172 != V_173 ) {
F_49 ( F_1 ( V_4 ) , false ) ;
V_11 -> V_241 = 1 ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
while ( 1 ) {
F_76 ( & V_11 -> V_209 ) ;
if ( V_11 -> V_172 == V_173 )
break;
F_103 ( 50 ) ;
}
F_42 ( V_11 , false ) ;
F_104 ( & V_11 -> V_209 ) ;
return 0 ;
}
F_61 ( & V_11 -> V_197 , V_193 ) ;
return V_132 ;
}
static int F_105 ( struct V_2 * V_4 ,
struct V_253 * V_195 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_193 ;
if ( ! V_195 || V_195 -> V_183 < V_36 ||
! V_195 -> V_216 )
return - V_114 ;
if ( ! V_11 )
return - V_254 ;
if ( V_11 -> V_195 )
return - V_115 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
F_15 ( V_11 , true ) ;
F_21 ( V_11 ) ;
F_24 ( V_11 ) ;
F_25 ( V_11 ) ;
F_23 ( V_11 ) ;
F_43 ( V_11 , true ) ;
V_11 -> V_195 = V_195 ;
V_195 -> V_195 . V_255 = NULL ;
V_11 -> V_4 . V_119 . V_256 = V_11 -> V_119 -> V_256 ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_4 ,
struct V_253 * V_195 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_193 ;
F_60 ( & V_11 -> V_197 , V_193 ) ;
V_11 -> V_195 = NULL ;
F_103 ( 100 ) ;
F_43 ( V_11 , false ) ;
F_15 ( V_11 , false ) ;
F_61 ( & V_11 -> V_197 , V_193 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_11 )
{
T_1 V_257 = F_5 ( V_11 , V_137 ) ;
V_11 -> V_58 = ( V_257 & V_258 ) >> V_259 ;
V_11 -> V_72 = ( V_257 & V_260 ) >> V_261 ;
V_11 -> V_74 = ( V_257 & V_262 ) >>
V_263 ;
F_25 ( V_11 ) ;
}
static int F_108 ( struct V_1 * V_11 )
{
T_1 V_257 = F_5 ( V_11 , V_137 ) ;
enum V_264 V_265 = V_11 -> V_4 . V_35 ;
switch ( ( V_257 & V_266 ) >> V_267 ) {
case V_184 :
V_11 -> V_4 . V_35 = V_36 ;
break;
case V_186 :
V_11 -> V_4 . V_35 = V_268 ;
break;
default:
V_11 -> V_4 . V_35 = V_171 ;
F_34 ( V_11 -> V_119 ,
L_10 ) ;
return 0 ;
}
if ( V_11 -> V_4 . V_35 != V_265 ) {
F_109 ( V_11 -> V_119 , L_11 ,
V_11 -> V_4 . V_35 == V_36 ? L_12 : L_13 ) ;
return 1 ;
} else {
return 0 ;
}
}
static void F_110 ( struct V_1 * V_11 , bool V_269 )
{
int V_37 ;
F_111 (i, &udc->wedgemap, BCM63XX_NUM_EP) {
F_20 ( V_11 , & V_11 -> V_27 [ V_37 ] , V_269 ) ;
if ( ! V_269 )
F_64 ( V_37 , & V_11 -> V_198 ) ;
}
}
static T_3 F_112 ( int V_270 , void * V_271 )
{
struct V_1 * V_11 = V_271 ;
T_1 V_272 ;
bool V_273 = false ;
V_272 = F_5 ( V_11 , V_144 ) &
F_5 ( V_11 , V_143 ) ;
F_7 ( V_11 , V_272 , V_144 ) ;
F_113 ( & V_11 -> V_197 ) ;
if ( V_272 & F_40 ( V_142 ) ) {
if ( ! ( F_5 ( V_11 , V_274 ) &
V_275 ) &&
V_11 -> V_4 . V_35 != V_171 )
F_109 ( V_11 -> V_119 , L_14 ) ;
V_11 -> V_4 . V_35 = V_171 ;
V_273 = true ;
}
if ( V_272 & F_40 ( V_138 ) ) {
F_21 ( V_11 ) ;
F_23 ( V_11 ) ;
F_25 ( V_11 ) ;
F_110 ( V_11 , false ) ;
V_11 -> V_236 = 1 ;
F_76 ( & V_11 -> V_209 ) ;
V_273 = true ;
}
if ( V_272 & F_40 ( V_139 ) ) {
if ( F_108 ( V_11 ) ) {
F_21 ( V_11 ) ;
F_25 ( V_11 ) ;
}
F_110 ( V_11 , true ) ;
}
if ( V_272 & F_40 ( V_140 ) ) {
F_107 ( V_11 ) ;
V_11 -> V_237 = 1 ;
F_76 ( & V_11 -> V_209 ) ;
}
if ( V_272 & F_40 ( V_141 ) ) {
F_107 ( V_11 ) ;
V_11 -> V_239 = 1 ;
F_76 ( & V_11 -> V_209 ) ;
}
F_114 ( & V_11 -> V_197 ) ;
if ( V_273 && V_11 -> V_195 )
V_11 -> V_195 -> V_276 ( & V_11 -> V_4 ) ;
return V_277 ;
}
static T_3 F_115 ( int V_270 , void * V_271 )
{
struct V_77 * V_66 = V_271 ;
struct V_1 * V_11 = V_66 -> V_11 ;
struct V_5 * V_27 ;
struct V_9 * V_10 = NULL ;
struct V_8 * V_78 = NULL ;
int V_132 ;
bool V_278 = false ;
F_113 ( & V_11 -> V_197 ) ;
F_12 ( V_11 , V_122 ,
V_121 , V_66 -> V_111 ) ;
V_27 = V_66 -> V_27 ;
V_132 = F_31 ( V_11 , V_66 ) ;
if ( V_66 -> V_111 == V_242 ||
V_66 -> V_111 == V_244 ) {
V_10 = V_11 -> V_227 ;
V_78 = F_4 ( V_10 ) ;
if ( V_132 >= 0 ) {
V_10 -> V_207 += V_132 ;
if ( V_10 -> V_207 >= V_10 -> V_83 || V_78 -> V_90 > V_132 ) {
V_11 -> V_228 = 1 ;
V_278 = true ;
F_76 ( & V_11 -> V_209 ) ;
V_10 -> V_207 = F_116 ( V_10 -> V_207 , V_10 -> V_83 ) ;
} else {
F_28 ( V_11 , V_66 , V_78 ) ;
}
}
} else if ( ! F_63 ( & V_27 -> V_128 ) ) {
V_78 = F_80 ( & V_27 -> V_128 , struct V_8 , V_128 ) ;
V_10 = & V_78 -> V_10 ;
if ( V_132 >= 0 ) {
V_10 -> V_207 += V_132 ;
if ( V_10 -> V_207 >= V_10 -> V_83 || V_78 -> V_90 > V_132 ) {
V_278 = true ;
F_55 ( & V_78 -> V_128 ) ;
V_10 -> V_207 = F_116 ( V_10 -> V_207 , V_10 -> V_83 ) ;
if ( ! F_63 ( & V_27 -> V_128 ) ) {
struct V_8 * V_212 ;
V_212 = F_80 ( & V_27 -> V_128 ,
struct V_8 , V_128 ) ;
F_28 ( V_11 , V_66 , V_212 ) ;
}
} else {
F_28 ( V_11 , V_66 , V_78 ) ;
}
}
}
F_114 ( & V_11 -> V_197 ) ;
if ( V_278 ) {
F_69 ( & V_11 -> V_4 , V_10 , V_66 -> V_87 ) ;
if ( V_10 -> V_204 )
V_10 -> V_204 ( & V_27 -> V_7 , V_10 ) ;
}
return V_277 ;
}
static int F_117 ( struct V_279 * V_280 , void * V_281 )
{
struct V_1 * V_11 = V_280 -> V_282 ;
if ( ! V_11 -> V_195 )
return - V_254 ;
F_118 ( V_280 , L_15 ,
V_283 [ V_11 -> V_172 ] ) ;
F_118 ( V_280 , L_16 ,
V_11 -> V_236 ? L_17 : L_18 ,
V_11 -> V_237 ? L_19 : L_18 ,
V_11 -> V_239 ? L_20 : L_18 ,
V_11 -> V_241 ? L_21 : L_18 ,
V_11 -> V_227 ? L_22 : L_18 ,
V_11 -> V_228 ? L_23 : L_18 ,
V_11 -> V_208 ? L_24 : L_18 ) ;
F_118 ( V_280 , L_25 ,
V_11 -> V_58 , V_11 -> V_72 , V_11 -> V_74 ) ;
F_118 ( V_280 , L_26 ) ;
F_118 ( V_280 , L_27 ,
F_5 ( V_11 , V_24 ) ,
F_5 ( V_11 , V_187 ) ,
F_5 ( V_11 , V_137 ) ) ;
F_118 ( V_280 , L_28 ,
F_5 ( V_11 , V_274 ) ,
F_5 ( V_11 , V_33 ) ) ;
return 0 ;
}
static int F_119 ( struct V_279 * V_280 , void * V_281 )
{
struct V_1 * V_11 = V_280 -> V_282 ;
int V_111 , V_37 ;
T_1 V_284 , V_285 ;
if ( ! V_11 -> V_195 )
return - V_254 ;
for ( V_111 = 0 ; V_111 < V_40 ; V_111 ++ ) {
struct V_77 * V_66 = & V_11 -> V_66 [ V_111 ] ;
struct V_200 * V_201 ;
F_118 ( V_280 , L_29 , V_111 ) ;
switch ( V_43 [ V_111 ] . V_59 ) {
case V_286 :
F_118 ( V_280 , L_30 ) ;
break;
case V_287 :
F_118 ( V_280 , L_31 ) ;
break;
case V_288 :
F_118 ( V_280 , L_32 ) ;
break;
}
F_118 ( V_280 , V_111 & 0x01 ? L_33 : L_34 ) ;
F_118 ( V_280 , L_35 ,
F_120 ( int , V_43 [ V_111 ] . V_31 , 0 ) ) ;
F_118 ( V_280 , L_36 ,
F_11 ( V_11 , V_110 , V_111 ) ,
F_11 ( V_11 , V_121 , V_111 ) ,
F_11 ( V_11 , V_123 , V_111 ) ,
F_11 ( V_11 , V_124 , V_111 ) ) ;
V_284 = F_13 ( V_11 , V_127 , V_111 ) ;
V_285 = F_13 ( V_11 , V_289 , V_111 ) ;
F_118 ( V_280 , L_37 ,
F_13 ( V_11 , V_126 , V_111 ) ,
V_284 >> 16 , V_284 & 0xffff ,
V_285 >> 16 , V_285 & 0xffff ,
F_13 ( V_11 , V_290 , V_111 ) ) ;
F_118 ( V_280 , L_38 , V_66 -> V_89 ,
V_66 -> V_104 ) ;
if ( V_66 -> V_27 ) {
V_37 = 0 ;
F_121 (pos, &iudma->bep->queue)
V_37 ++ ;
F_118 ( V_280 , L_39 , V_37 ) ;
} else {
F_118 ( V_280 , L_40 ) ;
}
for ( V_37 = 0 ; V_37 < V_66 -> V_104 ; V_37 ++ ) {
struct V_92 * V_93 = & V_66 -> V_99 [ V_37 ] ;
F_118 ( V_280 , L_41 ,
V_37 * sizeof( * V_93 ) , V_37 ,
V_93 -> V_108 >> 16 , V_93 -> V_108 & 0xffff ,
V_93 -> V_106 ) ;
if ( V_93 == V_66 -> V_113 )
F_118 ( V_280 , L_42 ) ;
if ( V_93 == V_66 -> V_94 )
F_118 ( V_280 , L_43 ) ;
F_118 ( V_280 , L_40 ) ;
}
F_118 ( V_280 , L_40 ) ;
}
return 0 ;
}
static int F_122 ( struct V_291 * V_291 , struct V_292 * V_292 )
{
return F_123 ( V_292 , F_117 , V_291 -> V_293 ) ;
}
static int F_124 ( struct V_291 * V_291 , struct V_292 * V_292 )
{
return F_123 ( V_292 , F_119 , V_291 -> V_293 ) ;
}
static void F_125 ( struct V_1 * V_11 )
{
struct V_294 * V_295 , * V_296 , * V_66 ;
if ( ! F_126 ( V_297 ) )
return;
V_295 = F_127 ( V_11 -> V_4 . V_164 , NULL ) ;
if ( F_57 ( V_295 ) || ! V_295 )
goto V_298;
V_296 = F_128 ( L_4 , 0400 , V_295 , V_11 ,
& V_299 ) ;
if ( ! V_296 )
goto V_300;
V_66 = F_128 ( L_44 , 0400 , V_295 , V_11 ,
& V_301 ) ;
if ( ! V_66 )
goto V_302;
V_11 -> V_303 = V_295 ;
V_11 -> V_304 = V_296 ;
V_11 -> V_305 = V_66 ;
return;
V_302:
F_129 ( V_296 ) ;
V_300:
F_129 ( V_295 ) ;
V_298:
F_34 ( V_11 -> V_119 , L_45 ) ;
}
static void F_130 ( struct V_1 * V_11 )
{
F_129 ( V_11 -> V_305 ) ;
F_129 ( V_11 -> V_304 ) ;
F_129 ( V_11 -> V_303 ) ;
V_11 -> V_305 = NULL ;
V_11 -> V_304 = NULL ;
V_11 -> V_303 = NULL ;
}
static int F_131 ( struct V_306 * V_307 )
{
struct V_308 * V_119 = & V_307 -> V_119 ;
struct V_309 * V_147 = F_132 ( V_119 ) ;
struct V_1 * V_11 ;
struct V_310 * V_311 ;
int V_132 = - V_131 , V_37 , V_270 ;
V_11 = F_53 ( V_119 , sizeof( * V_11 ) , V_130 ) ;
if ( ! V_11 ) {
F_34 ( V_119 , L_46 ) ;
return - V_131 ;
}
F_133 ( V_307 , V_11 ) ;
V_11 -> V_119 = V_119 ;
V_11 -> V_147 = V_147 ;
if ( ! V_147 ) {
F_34 ( V_119 , L_47 ) ;
return - V_114 ;
}
V_311 = F_134 ( V_307 , V_312 , 0 ) ;
V_11 -> V_13 = F_135 ( V_119 , V_311 ) ;
if ( F_57 ( V_11 -> V_13 ) )
return F_136 ( V_11 -> V_13 ) ;
V_311 = F_134 ( V_307 , V_312 , 1 ) ;
V_11 -> V_15 = F_135 ( V_119 , V_311 ) ;
if ( F_57 ( V_11 -> V_15 ) )
return F_136 ( V_11 -> V_15 ) ;
F_137 ( & V_11 -> V_197 ) ;
F_138 ( & V_11 -> V_209 , F_99 ) ;
V_11 -> V_4 . V_166 = & V_313 ;
V_11 -> V_4 . V_164 = F_139 ( V_119 ) ;
if ( ! V_147 -> V_314 && ! V_314 )
V_11 -> V_4 . V_183 = V_36 ;
else
V_11 -> V_4 . V_183 = V_268 ;
V_132 = F_52 ( V_11 ) ;
if ( V_132 )
return V_132 ;
V_132 = - V_315 ;
V_270 = F_140 ( V_307 , 0 ) ;
if ( V_270 < 0 ) {
F_34 ( V_119 , L_48 ) ;
goto V_316;
}
if ( F_141 ( V_119 , V_270 , & F_112 , 0 ,
F_139 ( V_119 ) , V_11 ) < 0 ) {
F_34 ( V_119 , L_49 , V_270 ) ;
goto V_316;
}
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ ) {
V_270 = F_140 ( V_307 , V_37 + 1 ) ;
if ( V_270 < 0 ) {
F_34 ( V_119 , L_50 , V_37 + 1 ) ;
goto V_316;
}
if ( F_141 ( V_119 , V_270 , & F_115 , 0 ,
F_139 ( V_119 ) , & V_11 -> V_66 [ V_37 ] ) < 0 ) {
F_34 ( V_119 , L_49 , V_270 ) ;
goto V_316;
}
}
F_125 ( V_11 ) ;
V_132 = F_142 ( V_119 , & V_11 -> V_4 ) ;
if ( ! V_132 )
return 0 ;
F_130 ( V_11 ) ;
V_316:
F_50 ( V_11 ) ;
return V_132 ;
}
static int F_143 ( struct V_306 * V_307 )
{
struct V_1 * V_11 = F_144 ( V_307 ) ;
F_130 ( V_11 ) ;
F_145 ( & V_11 -> V_4 ) ;
F_62 ( V_11 -> V_195 ) ;
F_50 ( V_11 ) ;
return 0 ;
}
