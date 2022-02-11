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
V_27 -> V_7 . V_164 = V_165 [ V_37 ] . V_164 ;
V_27 -> V_7 . V_166 = V_165 [ V_37 ] . V_166 ;
V_27 -> V_31 = V_37 ;
V_27 -> V_7 . V_167 = & V_168 ;
F_54 ( & V_27 -> V_7 . V_162 , & V_11 -> V_4 . V_162 ) ;
V_27 -> V_169 = 0 ;
F_26 ( & V_27 -> V_7 , V_161 ) ;
V_27 -> V_11 = V_11 ;
V_27 -> V_7 . V_170 = NULL ;
F_37 ( & V_27 -> V_128 ) ;
}
V_11 -> V_4 . V_171 = & V_11 -> V_27 [ 0 ] . V_7 ;
F_55 ( & V_11 -> V_27 [ 0 ] . V_7 . V_162 ) ;
V_11 -> V_4 . V_35 = V_172 ;
V_11 -> V_173 = V_174 ;
V_11 -> V_21 = F_56 ( V_11 -> V_119 , L_3 ) ;
if ( F_57 ( V_11 -> V_21 ) )
return - V_175 ;
V_11 -> V_22 = F_56 ( V_11 -> V_119 , L_4 ) ;
if ( F_57 ( V_11 -> V_22 ) ) {
F_51 ( V_11 -> V_21 ) ;
return - V_175 ;
}
F_15 ( V_11 , true ) ;
V_14 = V_176 |
V_177 |
( V_86 ? V_178 : 0 ) ;
F_7 ( V_11 , V_14 , V_24 ) ;
V_14 = V_179 |
V_180 |
V_181 |
V_182 |
V_183 ;
if ( V_11 -> V_4 . V_184 == V_36 )
V_14 |= ( V_185 << V_186 ) ;
else
V_14 |= ( V_187 << V_186 ) ;
F_7 ( V_11 , V_14 , V_188 ) ;
F_42 ( V_11 , false ) ;
F_7 ( V_11 , 0 , V_189 ) ;
V_14 = F_58 ( V_190 ) |
F_58 ( V_191 ) ;
F_7 ( V_11 , V_14 , V_192 ) ;
V_132 = F_39 ( V_11 ) ;
F_15 ( V_11 , false ) ;
if ( V_132 )
F_50 ( V_11 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 ,
const struct V_193 * V_170 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_77 * V_66 = V_27 -> V_66 ;
unsigned long V_194 ;
if ( ! V_7 || ! V_170 || V_7 -> V_164 == V_195 )
return - V_114 ;
if ( ! V_11 -> V_196 )
return - V_197 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
if ( V_66 -> V_129 ) {
F_61 ( & V_11 -> V_198 , V_194 ) ;
return - V_114 ;
}
V_66 -> V_129 = true ;
F_62 ( ! F_63 ( & V_27 -> V_128 ) ) ;
F_32 ( V_11 , V_66 ) ;
V_27 -> V_169 = 0 ;
F_20 ( V_11 , V_27 , false ) ;
F_64 ( V_27 -> V_31 , & V_11 -> V_199 ) ;
V_7 -> V_170 = V_170 ;
V_7 -> V_200 = F_65 ( V_170 ) ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_77 * V_66 = V_27 -> V_66 ;
struct V_201 * V_202 , * V_203 ;
unsigned long V_194 ;
if ( ! V_7 || ! V_7 -> V_170 )
return - V_114 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
if ( ! V_66 -> V_129 ) {
F_61 ( & V_11 -> V_198 , V_194 ) ;
return - V_114 ;
}
V_66 -> V_129 = false ;
F_32 ( V_11 , V_66 ) ;
if ( ! F_63 ( & V_27 -> V_128 ) ) {
F_67 (pos, n, &bep->queue) {
struct V_8 * V_78 =
F_68 ( V_202 , struct V_8 , V_128 ) ;
F_69 ( & V_11 -> V_4 , & V_78 -> V_10 ,
V_66 -> V_87 ) ;
F_55 ( & V_78 -> V_128 ) ;
V_78 -> V_10 . V_204 = - V_197 ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
F_70 ( & V_66 -> V_27 -> V_7 , & V_78 -> V_10 ) ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
}
}
V_7 -> V_170 = NULL ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
return 0 ;
}
static struct V_9 * F_71 ( struct V_6 * V_7 ,
T_2 V_205 )
{
struct V_8 * V_78 ;
V_78 = F_72 ( sizeof( * V_78 ) , V_205 ) ;
if ( ! V_78 )
return NULL ;
return & V_78 -> V_10 ;
}
static void F_73 ( struct V_6 * V_7 ,
struct V_9 * V_10 )
{
struct V_8 * V_78 = F_4 ( V_10 ) ;
F_74 ( V_78 ) ;
}
static int F_75 ( struct V_6 * V_7 , struct V_9 * V_10 ,
T_2 V_205 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_8 * V_78 = F_4 ( V_10 ) ;
unsigned long V_194 ;
int V_132 = 0 ;
if ( F_76 ( ! V_10 || ! V_10 -> V_206 || ! V_10 -> V_207 || ! V_7 ) )
return - V_114 ;
V_10 -> V_208 = 0 ;
V_10 -> V_204 = 0 ;
V_78 -> V_84 = 0 ;
if ( V_27 == & V_11 -> V_27 [ 0 ] ) {
if ( V_11 -> V_209 )
return - V_114 ;
V_11 -> V_209 = V_10 ;
F_77 ( & V_11 -> V_210 ) ;
return 0 ;
}
F_60 ( & V_11 -> V_198 , V_194 ) ;
if ( ! V_27 -> V_66 -> V_129 ) {
V_132 = - V_197 ;
goto V_211;
}
V_132 = F_78 ( & V_11 -> V_4 , V_10 , V_27 -> V_66 -> V_87 ) ;
if ( V_132 == 0 ) {
F_54 ( & V_78 -> V_128 , & V_27 -> V_128 ) ;
if ( F_79 ( & V_27 -> V_128 ) )
F_28 ( V_11 , V_27 -> V_66 , V_78 ) ;
}
V_211:
F_61 ( & V_11 -> V_198 , V_194 ) ;
return V_132 ;
}
static int F_80 ( struct V_6 * V_7 , struct V_9 * V_10 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
struct V_8 * V_78 = F_4 ( V_10 ) , * V_212 ;
unsigned long V_194 ;
int V_132 = 0 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
if ( F_63 ( & V_27 -> V_128 ) ) {
V_132 = - V_114 ;
goto V_211;
}
V_212 = F_81 ( & V_27 -> V_128 , struct V_8 , V_128 ) ;
F_69 ( & V_11 -> V_4 , & V_78 -> V_10 , V_27 -> V_66 -> V_87 ) ;
if ( V_78 == V_212 ) {
F_32 ( V_11 , V_27 -> V_66 ) ;
F_55 ( & V_78 -> V_128 ) ;
if ( ! F_63 ( & V_27 -> V_128 ) ) {
struct V_8 * V_213 ;
V_213 = F_81 ( & V_27 -> V_128 ,
struct V_8 , V_128 ) ;
F_28 ( V_11 , V_27 -> V_66 , V_213 ) ;
}
} else {
F_55 ( & V_78 -> V_128 ) ;
}
V_211:
F_61 ( & V_11 -> V_198 , V_194 ) ;
V_10 -> V_204 = - V_197 ;
V_10 -> V_206 ( V_7 , V_10 ) ;
return V_132 ;
}
static int F_82 ( struct V_6 * V_7 , int V_214 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
unsigned long V_194 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
F_20 ( V_11 , V_27 , ! ! V_214 ) ;
V_27 -> V_169 = V_214 ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 )
{
struct V_5 * V_27 = F_3 ( V_7 ) ;
struct V_1 * V_11 = V_27 -> V_11 ;
unsigned long V_194 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
F_84 ( V_27 -> V_31 , & V_11 -> V_199 ) ;
F_20 ( V_11 , V_27 , true ) ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_11 ,
struct V_215 * V_216 )
{
int V_132 ;
F_86 ( & V_11 -> V_198 ) ;
V_132 = V_11 -> V_196 -> V_217 ( & V_11 -> V_4 , V_216 ) ;
F_87 ( & V_11 -> V_198 ) ;
return V_132 ;
}
static int F_88 ( struct V_1 * V_11 )
{
struct V_215 V_216 ;
int V_132 ;
V_216 . V_218 = V_219 | V_220 ;
V_216 . V_221 = V_222 ;
V_216 . V_223 = F_89 ( V_11 -> V_58 ) ;
V_216 . V_224 = 0 ;
V_216 . V_225 = 0 ;
V_132 = F_85 ( V_11 , & V_216 ) ;
if ( V_132 < 0 ) {
F_90 ( V_11 -> V_119 ,
L_5 ,
V_11 -> V_58 ) ;
}
return V_132 ;
}
static int F_91 ( struct V_1 * V_11 )
{
struct V_215 V_216 ;
int V_132 ;
V_216 . V_218 = V_219 | V_226 ;
V_216 . V_221 = V_227 ;
V_216 . V_223 = F_89 ( V_11 -> V_74 ) ;
V_216 . V_224 = F_89 ( V_11 -> V_72 ) ;
V_216 . V_225 = 0 ;
V_132 = F_85 ( V_11 , & V_216 ) ;
if ( V_132 < 0 ) {
F_90 ( V_11 -> V_119 ,
L_6 ,
V_11 -> V_72 , V_11 -> V_74 ) ;
}
return V_132 ;
}
static void F_92 ( struct V_1 * V_11 , int V_111 ,
struct V_9 * V_10 )
{
struct V_8 * V_78 = F_4 ( V_10 ) ;
struct V_77 * V_66 = & V_11 -> V_66 [ V_111 ] ;
F_62 ( V_11 -> V_228 ) ;
V_11 -> V_228 = V_10 ;
V_10 -> V_208 = 0 ;
V_78 -> V_84 = 0 ;
F_78 ( & V_11 -> V_4 , V_10 , V_66 -> V_87 ) ;
F_28 ( V_11 , V_66 , V_78 ) ;
}
static void F_93 ( struct V_1 * V_11 ,
struct V_9 * V_10 , int V_204 )
{
V_10 -> V_204 = V_204 ;
if ( V_204 )
V_10 -> V_208 = 0 ;
if ( V_10 -> V_206 ) {
F_86 ( & V_11 -> V_198 ) ;
V_10 -> V_206 ( & V_11 -> V_27 [ 0 ] . V_7 , V_10 ) ;
F_87 ( & V_11 -> V_198 ) ;
}
}
static void F_94 ( struct V_1 * V_11 , int V_87 )
{
struct V_9 * V_10 = V_11 -> V_209 ;
V_11 -> V_209 = NULL ;
F_69 ( & V_11 -> V_4 , V_10 , V_87 ) ;
if ( V_11 -> V_228 == V_10 ) {
V_11 -> V_229 = 0 ;
V_11 -> V_228 = NULL ;
}
F_93 ( V_11 , V_10 , - V_197 ) ;
}
static int F_95 ( struct V_1 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_228 ;
V_11 -> V_229 = 0 ;
V_11 -> V_228 = NULL ;
return V_10 -> V_208 ;
}
static void F_96 ( struct V_1 * V_11 , int V_111 ,
int V_83 )
{
struct V_9 * V_10 = & V_11 -> V_230 . V_10 ;
V_10 -> V_207 = V_11 -> V_160 ;
V_10 -> V_83 = V_83 ;
V_10 -> V_206 = NULL ;
F_92 ( V_11 , V_111 , V_10 ) ;
}
static enum V_231 F_97 ( struct V_1 * V_11 )
{
int V_132 ;
struct V_215 * V_216 = ( void * ) V_11 -> V_160 ;
V_132 = F_95 ( V_11 ) ;
if ( V_132 < 0 ) {
F_34 ( V_11 -> V_119 , L_7 ) ;
return V_232 ;
}
if ( V_132 == 0 )
return V_233 ;
if ( V_132 != sizeof( * V_216 ) ) {
F_90 ( V_11 -> V_119 ,
L_8 , V_132 ) ;
return V_233 ;
}
V_132 = F_85 ( V_11 , V_216 ) ;
if ( V_132 < 0 ) {
F_20 ( V_11 , & V_11 -> V_27 [ 0 ] , true ) ;
return V_233 ;
}
if ( ! V_216 -> V_225 )
return V_233 ;
else if ( V_216 -> V_218 & V_234 )
return V_235 ;
else
return V_236 ;
}
static int F_98 ( struct V_1 * V_11 )
{
if ( V_11 -> V_237 ) {
V_11 -> V_237 = 0 ;
} else if ( V_11 -> V_238 ) {
V_11 -> V_238 = 0 ;
if ( F_88 ( V_11 ) >= 0 )
V_11 -> V_173 = V_239 ;
} else if ( V_11 -> V_240 ) {
V_11 -> V_240 = 0 ;
if ( F_91 ( V_11 ) >= 0 )
V_11 -> V_173 = V_239 ;
} else if ( V_11 -> V_229 ) {
V_11 -> V_173 = F_97 ( V_11 ) ;
return V_11 -> V_173 == V_232 ? - V_241 : 0 ;
} else if ( V_11 -> V_242 ) {
V_11 -> V_242 = 0 ;
V_11 -> V_229 = 0 ;
V_11 -> V_228 = NULL ;
F_32 ( V_11 , & V_11 -> V_66 [ V_243 ] ) ;
F_69 ( & V_11 -> V_4 ,
& V_11 -> V_230 . V_10 , 0 ) ;
F_30 () ;
V_11 -> V_173 = V_174 ;
} else if ( V_11 -> V_209 ) {
F_35 ( V_11 -> V_119 , L_9 ) ;
F_94 ( V_11 , 0 ) ;
} else {
return - V_241 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_11 )
{
enum V_231 V_173 = V_11 -> V_173 ;
bool V_244 = V_11 -> V_237 || V_11 -> V_242 ;
switch ( V_11 -> V_173 ) {
case V_233 :
F_96 ( V_11 , V_243 ,
V_161 ) ;
V_173 = V_232 ;
break;
case V_232 :
return F_98 ( V_11 ) ;
case V_235 :
if ( V_11 -> V_209 ) {
F_92 ( V_11 , V_245 ,
V_11 -> V_209 ) ;
V_173 = V_246 ;
} else if ( V_244 ) {
V_173 = V_233 ;
}
break;
case V_246 : {
if ( V_11 -> V_229 ) {
V_11 -> V_209 = NULL ;
F_95 ( V_11 ) ;
V_173 = V_233 ;
} else if ( V_244 ) {
F_32 ( V_11 , & V_11 -> V_66 [ V_245 ] ) ;
F_94 ( V_11 , 1 ) ;
V_173 = V_233 ;
}
break;
}
case V_236 :
if ( V_11 -> V_209 ) {
F_92 ( V_11 , V_243 ,
V_11 -> V_209 ) ;
V_173 = V_247 ;
} else if ( V_244 ) {
V_173 = V_233 ;
}
break;
case V_247 : {
if ( V_11 -> V_229 ) {
V_11 -> V_209 = NULL ;
F_95 ( V_11 ) ;
F_96 ( V_11 , V_245 , 0 ) ;
V_173 = V_248 ;
} else if ( V_244 ) {
F_32 ( V_11 , & V_11 -> V_66 [ V_243 ] ) ;
F_94 ( V_11 , 0 ) ;
V_173 = V_233 ;
}
break;
}
case V_248 :
if ( V_11 -> V_229 ) {
F_95 ( V_11 ) ;
V_173 = V_233 ;
} else if ( V_244 ) {
F_32 ( V_11 , & V_11 -> V_66 [ V_245 ] ) ;
V_11 -> V_228 = NULL ;
V_173 = V_233 ;
}
break;
case V_239 : {
struct V_9 * V_249 = V_11 -> V_209 ;
if ( ! V_249 ) {
if ( V_244 )
V_173 = V_232 ;
break;
}
F_93 ( V_11 , V_249 , 0 ) ;
V_11 -> V_209 = NULL ;
V_173 = V_232 ;
break;
}
case V_174 :
break;
}
if ( V_11 -> V_173 == V_173 )
return - V_241 ;
V_11 -> V_173 = V_173 ;
return 0 ;
}
static void F_100 ( struct V_250 * V_251 )
{
struct V_1 * V_11 = F_2 ( V_251 , struct V_1 , V_210 ) ;
F_87 ( & V_11 -> V_198 ) ;
while ( F_99 ( V_11 ) == 0 )
;
F_86 ( & V_11 -> V_198 ) ;
}
static int F_101 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
return ( F_5 ( V_11 , V_137 ) &
V_252 ) >> V_253 ;
}
static int F_102 ( struct V_2 * V_4 , int V_159 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_194 ;
int V_37 , V_132 = - V_114 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
if ( V_159 && V_11 -> V_173 == V_174 ) {
V_11 -> V_4 . V_35 = V_172 ;
V_11 -> V_173 = V_233 ;
F_21 ( V_11 ) ;
F_23 ( V_11 ) ;
F_25 ( V_11 ) ;
F_103 ( & V_11 -> V_199 , V_163 ) ;
for ( V_37 = 0 ; V_37 < V_163 ; V_37 ++ )
F_20 ( V_11 , & V_11 -> V_27 [ V_37 ] , false ) ;
F_42 ( V_11 , true ) ;
F_49 ( F_1 ( V_4 ) , true ) ;
V_132 = 0 ;
} else if ( ! V_159 && V_11 -> V_173 != V_174 ) {
F_49 ( F_1 ( V_4 ) , false ) ;
V_11 -> V_242 = 1 ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
while ( 1 ) {
F_77 ( & V_11 -> V_210 ) ;
if ( V_11 -> V_173 == V_174 )
break;
F_104 ( 50 ) ;
}
F_42 ( V_11 , false ) ;
F_105 ( & V_11 -> V_210 ) ;
return 0 ;
}
F_61 ( & V_11 -> V_198 , V_194 ) ;
return V_132 ;
}
static int F_106 ( struct V_2 * V_4 ,
struct V_254 * V_196 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_194 ;
if ( ! V_196 || V_196 -> V_184 < V_36 ||
! V_196 -> V_217 )
return - V_114 ;
if ( ! V_11 )
return - V_255 ;
if ( V_11 -> V_196 )
return - V_115 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
F_15 ( V_11 , true ) ;
F_21 ( V_11 ) ;
F_24 ( V_11 ) ;
F_25 ( V_11 ) ;
F_23 ( V_11 ) ;
F_43 ( V_11 , true ) ;
V_11 -> V_196 = V_196 ;
V_196 -> V_196 . V_256 = NULL ;
V_11 -> V_4 . V_119 . V_257 = V_11 -> V_119 -> V_257 ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_194 ;
F_60 ( & V_11 -> V_198 , V_194 ) ;
V_11 -> V_196 = NULL ;
F_104 ( 100 ) ;
F_43 ( V_11 , false ) ;
F_15 ( V_11 , false ) ;
F_61 ( & V_11 -> V_198 , V_194 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_11 )
{
T_1 V_258 = F_5 ( V_11 , V_137 ) ;
V_11 -> V_58 = ( V_258 & V_259 ) >> V_260 ;
V_11 -> V_72 = ( V_258 & V_261 ) >> V_262 ;
V_11 -> V_74 = ( V_258 & V_263 ) >>
V_264 ;
F_25 ( V_11 ) ;
}
static int F_109 ( struct V_1 * V_11 )
{
T_1 V_258 = F_5 ( V_11 , V_137 ) ;
enum V_265 V_266 = V_11 -> V_4 . V_35 ;
switch ( ( V_258 & V_267 ) >> V_268 ) {
case V_185 :
V_11 -> V_4 . V_35 = V_36 ;
break;
case V_187 :
V_11 -> V_4 . V_35 = V_269 ;
break;
default:
V_11 -> V_4 . V_35 = V_172 ;
F_34 ( V_11 -> V_119 ,
L_10 ) ;
return 0 ;
}
if ( V_11 -> V_4 . V_35 != V_266 ) {
F_110 ( V_11 -> V_119 , L_11 ,
V_11 -> V_4 . V_35 == V_36 ? L_12 : L_13 ) ;
return 1 ;
} else {
return 0 ;
}
}
static void F_111 ( struct V_1 * V_11 , bool V_270 )
{
int V_37 ;
F_112 (i, &udc->wedgemap, BCM63XX_NUM_EP) {
F_20 ( V_11 , & V_11 -> V_27 [ V_37 ] , V_270 ) ;
if ( ! V_270 )
F_64 ( V_37 , & V_11 -> V_199 ) ;
}
}
static T_3 F_113 ( int V_271 , void * V_272 )
{
struct V_1 * V_11 = V_272 ;
T_1 V_273 ;
bool V_274 = false , V_275 = false ;
V_273 = F_5 ( V_11 , V_144 ) &
F_5 ( V_11 , V_143 ) ;
F_7 ( V_11 , V_273 , V_144 ) ;
F_114 ( & V_11 -> V_198 ) ;
if ( V_273 & F_40 ( V_142 ) ) {
if ( ! ( F_5 ( V_11 , V_276 ) &
V_277 ) &&
V_11 -> V_4 . V_35 != V_172 )
F_110 ( V_11 -> V_119 , L_14 ) ;
V_11 -> V_4 . V_35 = V_172 ;
V_274 = true ;
}
if ( V_273 & F_40 ( V_138 ) ) {
F_21 ( V_11 ) ;
F_23 ( V_11 ) ;
F_25 ( V_11 ) ;
F_111 ( V_11 , false ) ;
V_11 -> V_237 = 1 ;
F_77 ( & V_11 -> V_210 ) ;
V_275 = true ;
}
if ( V_273 & F_40 ( V_139 ) ) {
if ( F_109 ( V_11 ) ) {
F_21 ( V_11 ) ;
F_25 ( V_11 ) ;
}
F_111 ( V_11 , true ) ;
}
if ( V_273 & F_40 ( V_140 ) ) {
F_108 ( V_11 ) ;
V_11 -> V_238 = 1 ;
F_77 ( & V_11 -> V_210 ) ;
}
if ( V_273 & F_40 ( V_141 ) ) {
F_108 ( V_11 ) ;
V_11 -> V_240 = 1 ;
F_77 ( & V_11 -> V_210 ) ;
}
F_115 ( & V_11 -> V_198 ) ;
if ( V_274 && V_11 -> V_196 )
V_11 -> V_196 -> V_278 ( & V_11 -> V_4 ) ;
else if ( V_275 && V_11 -> V_196 )
F_116 ( & V_11 -> V_4 , V_11 -> V_196 ) ;
return V_279 ;
}
static T_3 F_117 ( int V_271 , void * V_272 )
{
struct V_77 * V_66 = V_272 ;
struct V_1 * V_11 = V_66 -> V_11 ;
struct V_5 * V_27 ;
struct V_9 * V_10 = NULL ;
struct V_8 * V_78 = NULL ;
int V_132 ;
bool V_280 = false ;
F_114 ( & V_11 -> V_198 ) ;
F_12 ( V_11 , V_122 ,
V_121 , V_66 -> V_111 ) ;
V_27 = V_66 -> V_27 ;
V_132 = F_31 ( V_11 , V_66 ) ;
if ( V_66 -> V_111 == V_243 ||
V_66 -> V_111 == V_245 ) {
V_10 = V_11 -> V_228 ;
V_78 = F_4 ( V_10 ) ;
if ( V_132 >= 0 ) {
V_10 -> V_208 += V_132 ;
if ( V_10 -> V_208 >= V_10 -> V_83 || V_78 -> V_90 > V_132 ) {
V_11 -> V_229 = 1 ;
V_280 = true ;
F_77 ( & V_11 -> V_210 ) ;
V_10 -> V_208 = F_118 ( V_10 -> V_208 , V_10 -> V_83 ) ;
} else {
F_28 ( V_11 , V_66 , V_78 ) ;
}
}
} else if ( ! F_63 ( & V_27 -> V_128 ) ) {
V_78 = F_81 ( & V_27 -> V_128 , struct V_8 , V_128 ) ;
V_10 = & V_78 -> V_10 ;
if ( V_132 >= 0 ) {
V_10 -> V_208 += V_132 ;
if ( V_10 -> V_208 >= V_10 -> V_83 || V_78 -> V_90 > V_132 ) {
V_280 = true ;
F_55 ( & V_78 -> V_128 ) ;
V_10 -> V_208 = F_118 ( V_10 -> V_208 , V_10 -> V_83 ) ;
if ( ! F_63 ( & V_27 -> V_128 ) ) {
struct V_8 * V_213 ;
V_213 = F_81 ( & V_27 -> V_128 ,
struct V_8 , V_128 ) ;
F_28 ( V_11 , V_66 , V_213 ) ;
}
} else {
F_28 ( V_11 , V_66 , V_78 ) ;
}
}
}
F_115 ( & V_11 -> V_198 ) ;
if ( V_280 ) {
F_69 ( & V_11 -> V_4 , V_10 , V_66 -> V_87 ) ;
if ( V_10 -> V_206 )
V_10 -> V_206 ( & V_27 -> V_7 , V_10 ) ;
}
return V_279 ;
}
static int F_119 ( struct V_281 * V_282 , void * V_283 )
{
struct V_1 * V_11 = V_282 -> V_284 ;
if ( ! V_11 -> V_196 )
return - V_255 ;
F_120 ( V_282 , L_15 ,
V_285 [ V_11 -> V_173 ] ) ;
F_120 ( V_282 , L_16 ,
V_11 -> V_237 ? L_17 : L_18 ,
V_11 -> V_238 ? L_19 : L_18 ,
V_11 -> V_240 ? L_20 : L_18 ,
V_11 -> V_242 ? L_21 : L_18 ,
V_11 -> V_228 ? L_22 : L_18 ,
V_11 -> V_229 ? L_23 : L_18 ,
V_11 -> V_209 ? L_24 : L_18 ) ;
F_120 ( V_282 , L_25 ,
V_11 -> V_58 , V_11 -> V_72 , V_11 -> V_74 ) ;
F_120 ( V_282 , L_26 ) ;
F_120 ( V_282 , L_27 ,
F_5 ( V_11 , V_24 ) ,
F_5 ( V_11 , V_188 ) ,
F_5 ( V_11 , V_137 ) ) ;
F_120 ( V_282 , L_28 ,
F_5 ( V_11 , V_276 ) ,
F_5 ( V_11 , V_33 ) ) ;
return 0 ;
}
static int F_121 ( struct V_281 * V_282 , void * V_283 )
{
struct V_1 * V_11 = V_282 -> V_284 ;
int V_111 , V_37 ;
T_1 V_286 , V_287 ;
if ( ! V_11 -> V_196 )
return - V_255 ;
for ( V_111 = 0 ; V_111 < V_40 ; V_111 ++ ) {
struct V_77 * V_66 = & V_11 -> V_66 [ V_111 ] ;
struct V_201 * V_202 ;
F_120 ( V_282 , L_29 , V_111 ) ;
switch ( V_43 [ V_111 ] . V_59 ) {
case V_288 :
F_120 ( V_282 , L_30 ) ;
break;
case V_289 :
F_120 ( V_282 , L_31 ) ;
break;
case V_290 :
F_120 ( V_282 , L_32 ) ;
break;
}
F_120 ( V_282 , V_111 & 0x01 ? L_33 : L_34 ) ;
F_120 ( V_282 , L_35 ,
F_122 ( int , V_43 [ V_111 ] . V_31 , 0 ) ) ;
F_120 ( V_282 , L_36 ,
F_11 ( V_11 , V_110 , V_111 ) ,
F_11 ( V_11 , V_121 , V_111 ) ,
F_11 ( V_11 , V_123 , V_111 ) ,
F_11 ( V_11 , V_124 , V_111 ) ) ;
V_286 = F_13 ( V_11 , V_127 , V_111 ) ;
V_287 = F_13 ( V_11 , V_291 , V_111 ) ;
F_120 ( V_282 , L_37 ,
F_13 ( V_11 , V_126 , V_111 ) ,
V_286 >> 16 , V_286 & 0xffff ,
V_287 >> 16 , V_287 & 0xffff ,
F_13 ( V_11 , V_292 , V_111 ) ) ;
F_120 ( V_282 , L_38 , V_66 -> V_89 ,
V_66 -> V_104 ) ;
if ( V_66 -> V_27 ) {
V_37 = 0 ;
F_123 (pos, &iudma->bep->queue)
V_37 ++ ;
F_120 ( V_282 , L_39 , V_37 ) ;
} else {
F_120 ( V_282 , L_40 ) ;
}
for ( V_37 = 0 ; V_37 < V_66 -> V_104 ; V_37 ++ ) {
struct V_92 * V_93 = & V_66 -> V_99 [ V_37 ] ;
F_120 ( V_282 , L_41 ,
V_37 * sizeof( * V_93 ) , V_37 ,
V_93 -> V_108 >> 16 , V_93 -> V_108 & 0xffff ,
V_93 -> V_106 ) ;
if ( V_93 == V_66 -> V_113 )
F_120 ( V_282 , L_42 ) ;
if ( V_93 == V_66 -> V_94 )
F_120 ( V_282 , L_43 ) ;
F_120 ( V_282 , L_40 ) ;
}
F_120 ( V_282 , L_40 ) ;
}
return 0 ;
}
static int F_124 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_125 ( V_294 , F_119 , V_293 -> V_295 ) ;
}
static int F_126 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_125 ( V_294 , F_121 , V_293 -> V_295 ) ;
}
static void F_127 ( struct V_1 * V_11 )
{
struct V_296 * V_297 , * V_298 , * V_66 ;
if ( ! F_128 ( V_299 ) )
return;
V_297 = F_129 ( V_11 -> V_4 . V_164 , NULL ) ;
if ( F_57 ( V_297 ) || ! V_297 )
goto V_300;
V_298 = F_130 ( L_4 , 0400 , V_297 , V_11 ,
& V_301 ) ;
if ( ! V_298 )
goto V_302;
V_66 = F_130 ( L_44 , 0400 , V_297 , V_11 ,
& V_303 ) ;
if ( ! V_66 )
goto V_304;
V_11 -> V_305 = V_297 ;
V_11 -> V_306 = V_298 ;
V_11 -> V_307 = V_66 ;
return;
V_304:
F_131 ( V_298 ) ;
V_302:
F_131 ( V_297 ) ;
V_300:
F_34 ( V_11 -> V_119 , L_45 ) ;
}
static void F_132 ( struct V_1 * V_11 )
{
F_131 ( V_11 -> V_307 ) ;
F_131 ( V_11 -> V_306 ) ;
F_131 ( V_11 -> V_305 ) ;
V_11 -> V_307 = NULL ;
V_11 -> V_306 = NULL ;
V_11 -> V_305 = NULL ;
}
static int F_133 ( struct V_308 * V_309 )
{
struct V_310 * V_119 = & V_309 -> V_119 ;
struct V_311 * V_147 = F_134 ( V_119 ) ;
struct V_1 * V_11 ;
struct V_312 * V_313 ;
int V_132 = - V_131 , V_37 , V_271 ;
V_11 = F_53 ( V_119 , sizeof( * V_11 ) , V_130 ) ;
if ( ! V_11 )
return - V_131 ;
F_135 ( V_309 , V_11 ) ;
V_11 -> V_119 = V_119 ;
V_11 -> V_147 = V_147 ;
if ( ! V_147 ) {
F_34 ( V_119 , L_46 ) ;
return - V_114 ;
}
V_313 = F_136 ( V_309 , V_314 , 0 ) ;
V_11 -> V_13 = F_137 ( V_119 , V_313 ) ;
if ( F_57 ( V_11 -> V_13 ) )
return F_138 ( V_11 -> V_13 ) ;
V_313 = F_136 ( V_309 , V_314 , 1 ) ;
V_11 -> V_15 = F_137 ( V_119 , V_313 ) ;
if ( F_57 ( V_11 -> V_15 ) )
return F_138 ( V_11 -> V_15 ) ;
F_139 ( & V_11 -> V_198 ) ;
F_140 ( & V_11 -> V_210 , F_100 ) ;
V_11 -> V_4 . V_167 = & V_315 ;
V_11 -> V_4 . V_164 = F_141 ( V_119 ) ;
if ( ! V_147 -> V_316 && ! V_316 )
V_11 -> V_4 . V_184 = V_36 ;
else
V_11 -> V_4 . V_184 = V_269 ;
V_132 = F_52 ( V_11 ) ;
if ( V_132 )
return V_132 ;
V_132 = - V_317 ;
V_271 = F_142 ( V_309 , 0 ) ;
if ( V_271 < 0 ) {
F_34 ( V_119 , L_47 ) ;
goto V_318;
}
if ( F_143 ( V_119 , V_271 , & F_113 , 0 ,
F_141 ( V_119 ) , V_11 ) < 0 ) {
F_34 ( V_119 , L_48 , V_271 ) ;
goto V_318;
}
for ( V_37 = 0 ; V_37 < V_40 ; V_37 ++ ) {
V_271 = F_142 ( V_309 , V_37 + 1 ) ;
if ( V_271 < 0 ) {
F_34 ( V_119 , L_49 , V_37 + 1 ) ;
goto V_318;
}
if ( F_143 ( V_119 , V_271 , & F_117 , 0 ,
F_141 ( V_119 ) , & V_11 -> V_66 [ V_37 ] ) < 0 ) {
F_34 ( V_119 , L_48 , V_271 ) ;
goto V_318;
}
}
F_127 ( V_11 ) ;
V_132 = F_144 ( V_119 , & V_11 -> V_4 ) ;
if ( ! V_132 )
return 0 ;
F_132 ( V_11 ) ;
V_318:
F_50 ( V_11 ) ;
return V_132 ;
}
static int F_145 ( struct V_308 * V_309 )
{
struct V_1 * V_11 = F_146 ( V_309 ) ;
F_132 ( V_11 ) ;
F_147 ( & V_11 -> V_4 ) ;
F_62 ( V_11 -> V_196 ) ;
F_50 ( V_11 ) ;
return 0 ;
}
