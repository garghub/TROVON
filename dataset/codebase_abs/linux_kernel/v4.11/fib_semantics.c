static void F_1 ( struct V_1 T_1 * * V_2 )
{
struct V_1 * V_3 = F_2 ( * V_2 , 1 ) ;
if ( ! V_3 )
return;
F_3 ( & V_3 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( V_6 -> V_10 , 1 ) ;
if ( ! V_8 )
return;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_12 * V_13 ;
V_13 = F_2 ( V_8 [ V_9 ] . V_14 , 1 ) ;
while ( V_13 ) {
struct V_12 * V_15 ;
V_15 = F_2 ( V_13 -> V_16 , 1 ) ;
F_1 ( & V_13 -> V_17 ) ;
F_1 ( & V_13 -> V_18 ) ;
F_5 ( V_13 ) ;
V_13 = V_15 ;
}
}
F_5 ( V_8 ) ;
}
static void F_6 ( struct V_1 T_1 * T_2 * V_2 )
{
int V_19 ;
if ( ! V_2 )
return;
F_7 (cpu) {
struct V_1 * V_3 ;
V_3 = F_2 ( * F_8 ( V_2 , V_19 ) , 1 ) ;
if ( V_3 )
F_3 ( & V_3 -> V_4 ) ;
}
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 , struct V_22 , V_24 ) ;
F_12 (fi) {
if ( V_25 -> V_26 )
F_13 ( V_25 -> V_26 ) ;
F_14 ( V_25 -> V_27 ) ;
F_4 ( V_25 ) ;
F_6 ( V_25 -> V_28 ) ;
F_1 ( & V_25 -> V_29 ) ;
} F_15 ( V_23 ) ;
if ( V_23 -> V_30 != ( V_31 * ) V_32 )
F_5 ( V_23 -> V_30 ) ;
F_5 ( V_23 ) ;
}
void F_16 ( struct V_22 * V_23 )
{
if ( V_23 -> V_33 == 0 ) {
F_17 ( L_1 , V_23 ) ;
return;
}
V_34 -- ;
#ifdef F_18
F_12 (fi) {
if ( V_25 -> V_35 )
V_23 -> V_36 -> V_37 . V_38 -- ;
} F_15 ( V_23 ) ;
#endif
F_19 ( & V_23 -> V_24 , F_10 ) ;
}
void F_20 ( struct V_22 * V_23 )
{
F_21 ( & V_39 ) ;
if ( V_23 && -- V_23 -> V_40 == 0 ) {
F_22 ( & V_23 -> V_41 ) ;
if ( V_23 -> V_42 )
F_22 ( & V_23 -> V_43 ) ;
F_12 (fi) {
if ( ! V_25 -> V_26 )
continue;
F_22 ( & V_25 -> V_44 ) ;
} F_15 (fi)
V_23 -> V_33 = 1 ;
F_23 ( V_23 ) ;
}
F_24 ( & V_39 ) ;
}
static inline int F_25 ( const struct V_22 * V_23 , const struct V_22 * V_45 )
{
const struct V_5 * V_46 = V_45 -> V_5 ;
F_26 (fi) {
if ( V_6 -> V_47 != V_46 -> V_47 ||
V_6 -> V_48 != V_46 -> V_48 ||
V_6 -> V_49 != V_46 -> V_49 ||
#ifdef F_27
V_6 -> V_50 != V_46 -> V_50 ||
#endif
#ifdef F_18
V_6 -> V_35 != V_46 -> V_35 ||
#endif
F_28 ( V_6 -> V_27 , V_46 -> V_27 ) ||
( ( V_6 -> V_51 ^ V_46 -> V_51 ) & ~ V_52 ) )
return - 1 ;
V_46 ++ ;
} F_15 ( V_23 ) ;
return 0 ;
}
static inline unsigned int F_29 ( unsigned int V_53 )
{
unsigned int V_54 = V_55 - 1 ;
return ( V_53 ^
( V_53 >> V_56 ) ^
( V_53 >> ( V_56 * 2 ) ) ) & V_54 ;
}
static inline unsigned int F_30 ( const struct V_22 * V_23 )
{
unsigned int V_54 = ( V_57 - 1 ) ;
unsigned int V_53 = V_23 -> V_58 ;
V_53 ^= ( V_23 -> V_59 << 8 ) | V_23 -> V_60 ;
V_53 ^= ( V_61 V_31 ) V_23 -> V_42 ;
V_53 ^= V_23 -> V_62 ;
F_26 (fi) {
V_53 ^= F_29 ( V_6 -> V_47 ) ;
} F_15 (fi)
return ( V_53 ^ ( V_53 >> 7 ) ^ ( V_53 >> 12 ) ) & V_54 ;
}
static struct V_22 * F_31 ( const struct V_22 * V_63 )
{
struct V_64 * V_21 ;
struct V_22 * V_23 ;
unsigned int V_8 ;
V_8 = F_30 ( V_63 ) ;
V_21 = & V_65 [ V_8 ] ;
F_32 (fi, head, fib_hash) {
if ( ! F_33 ( V_23 -> V_36 , V_63 -> V_36 ) )
continue;
if ( V_23 -> V_58 != V_63 -> V_58 )
continue;
if ( V_63 -> V_59 == V_23 -> V_59 &&
V_63 -> V_60 == V_23 -> V_60 &&
V_63 -> V_42 == V_23 -> V_42 &&
V_63 -> V_62 == V_23 -> V_62 &&
V_63 -> V_66 == V_23 -> V_66 &&
memcmp ( V_63 -> V_30 , V_23 -> V_30 ,
sizeof( V_31 ) * V_67 ) == 0 &&
! ( ( V_63 -> V_68 ^ V_23 -> V_68 ) & ~ V_52 ) &&
( V_63 -> V_58 == 0 || F_25 ( V_23 , V_63 ) == 0 ) )
return V_23 ;
}
return NULL ;
}
int F_34 ( T_3 V_69 , struct V_70 * V_71 )
{
struct V_64 * V_21 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_35 ( & V_39 ) ;
V_8 = F_29 ( V_71 -> V_72 ) ;
V_21 = & V_73 [ V_8 ] ;
F_32 (nh, head, nh_hash) {
if ( V_6 -> V_26 == V_71 &&
V_6 -> V_48 == V_69 &&
! ( V_6 -> V_51 & V_74 ) ) {
F_36 ( & V_39 ) ;
return 0 ;
}
}
F_36 ( & V_39 ) ;
return - 1 ;
}
static inline T_4 F_37 ( struct V_22 * V_23 )
{
T_4 V_75 = F_38 ( sizeof( struct V_76 ) )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( 4 )
+ F_39 ( V_77 ) ;
V_75 += F_39 ( ( V_67 * F_39 ( 4 ) ) ) ;
if ( V_23 -> V_58 ) {
T_4 V_78 = 0 ;
T_4 V_79 = F_39 ( sizeof( struct V_80 ) ) ;
V_79 += 2 * F_39 ( 4 ) ;
F_26 (fi) {
if ( V_6 -> V_27 ) {
V_78 += F_40 (
V_6 -> V_27 ) ;
V_78 += F_39 ( 2 ) ;
}
} F_15 ( V_23 ) ;
V_75 += F_39 ( ( V_23 -> V_58 * V_79 ) +
V_78 ) ;
}
return V_75 ;
}
void F_41 ( int V_81 , T_3 V_82 , struct V_83 * V_84 ,
int V_85 , V_31 V_86 , const struct V_87 * V_88 ,
unsigned int V_89 )
{
struct V_90 * V_91 ;
V_31 V_92 = V_88 -> V_93 ? V_88 -> V_93 -> V_94 : 0 ;
int V_95 = - V_96 ;
V_91 = F_42 ( F_37 ( V_84 -> V_97 ) , V_98 ) ;
if ( ! V_91 )
goto V_99;
V_95 = F_43 ( V_91 , V_88 -> V_100 , V_92 , V_81 , V_86 ,
V_84 -> V_101 , V_82 , V_85 ,
V_84 -> V_102 , V_84 -> V_97 , V_89 ) ;
if ( V_95 < 0 ) {
F_44 ( V_95 == - V_103 ) ;
F_45 ( V_91 ) ;
goto V_99;
}
F_46 ( V_91 , V_88 -> V_104 , V_88 -> V_100 , V_105 ,
V_88 -> V_93 , V_98 ) ;
return;
V_99:
if ( V_95 < 0 )
F_47 ( V_88 -> V_104 , V_105 , V_95 ) ;
}
static int F_48 ( struct V_22 * V_23 , int V_106 ,
struct V_22 * * V_107 , int * V_108 ,
int V_109 )
{
struct V_110 * V_111 ;
int V_112 = V_113 ;
V_111 = F_49 ( & V_114 , & V_23 -> V_5 [ 0 ] . V_48 , V_23 -> V_115 ) ;
if ( V_111 ) {
V_112 = V_111 -> V_116 ;
F_50 ( V_111 ) ;
} else {
return 0 ;
}
if ( V_112 == V_117 )
return 0 ;
if ( ( V_112 & V_118 ) && V_106 != V_109 )
return 0 ;
if ( ( V_112 & V_118 ) ||
( * V_108 < 0 && V_106 > V_109 && V_112 != V_119 ) ) {
* V_107 = V_23 ;
* V_108 = V_106 ;
}
return 1 ;
}
static int F_51 ( struct V_80 * V_120 , int V_121 )
{
int V_122 = 0 ;
while ( F_52 ( V_120 , V_121 ) ) {
V_122 ++ ;
V_120 = F_53 ( V_120 , & V_121 ) ;
}
return V_121 > 0 ? 0 : V_122 ;
}
static int F_54 ( struct V_22 * V_23 , struct V_80 * V_120 ,
int V_121 , struct V_123 * V_124 )
{
int V_125 ;
F_12 (fi) {
int V_126 ;
if ( ! F_52 ( V_120 , V_121 ) )
return - V_127 ;
if ( V_120 -> V_128 & ( V_74 | V_129 ) )
return - V_127 ;
V_25 -> V_51 =
( V_124 -> V_130 & ~ 0xFF ) | V_120 -> V_128 ;
V_25 -> V_47 = V_120 -> V_131 ;
V_25 -> V_50 = V_120 -> V_132 + 1 ;
V_126 = F_55 ( V_120 ) ;
if ( V_126 > 0 ) {
struct V_133 * V_134 , * V_135 = F_56 ( V_120 ) ;
V_134 = F_57 ( V_135 , V_126 , V_136 ) ;
V_25 -> V_48 = V_134 ? F_58 ( V_134 ) : 0 ;
#ifdef F_18
V_134 = F_57 ( V_135 , V_126 , V_137 ) ;
V_25 -> V_35 = V_134 ? F_59 ( V_134 ) : 0 ;
if ( V_25 -> V_35 )
V_23 -> V_36 -> V_37 . V_38 ++ ;
#endif
V_134 = F_57 ( V_135 , V_126 , V_138 ) ;
if ( V_134 ) {
struct V_139 * V_140 ;
struct V_133 * V_141 ;
V_141 = F_57 ( V_135 , V_126 ,
V_142 ) ;
if ( ! V_141 )
goto V_143;
V_125 = F_60 ( F_61 (
V_141 ) ,
V_134 , V_144 , V_124 ,
& V_140 ) ;
if ( V_125 )
goto V_99;
V_25 -> V_27 =
F_62 ( V_140 ) ;
}
}
V_120 = F_53 ( V_120 , & V_121 ) ;
} F_15 ( V_23 ) ;
return 0 ;
V_143:
V_125 = - V_127 ;
V_99:
return V_125 ;
}
static void F_63 ( struct V_22 * V_23 )
{
int V_145 ;
int V_146 ;
struct V_147 * V_148 ;
if ( V_23 -> V_58 < 2 )
return;
V_145 = 0 ;
F_26 (fi) {
if ( V_6 -> V_51 & V_74 )
continue;
V_148 = F_64 ( V_6 -> V_26 ) ;
if ( V_148 &&
F_65 ( V_148 ) &&
V_6 -> V_51 & V_129 )
continue;
V_145 += V_6 -> V_50 ;
} F_15 ( V_23 ) ;
V_146 = 0 ;
F_12 (fi) {
int V_149 ;
V_148 = F_64 ( V_25 -> V_26 ) ;
if ( V_25 -> V_51 & V_74 ) {
V_149 = - 1 ;
} else if ( V_148 &&
F_65 ( V_148 ) &&
V_25 -> V_51 & V_129 ) {
V_149 = - 1 ;
} else {
V_146 += V_25 -> V_50 ;
V_149 = F_66 ( ( V_150 ) V_146 << 31 ,
V_145 ) - 1 ;
}
F_67 ( & V_25 -> V_151 , V_149 ) ;
} F_15 ( V_23 ) ;
F_68 ( & V_152 ,
sizeof( V_152 ) ) ;
}
static inline void F_69 ( struct V_22 * V_23 ,
const struct V_5 * V_6 )
{
V_23 -> V_153 += V_6 -> V_50 ;
}
static int F_70 ( T_5 V_154 ,
struct V_133 * V_155 ,
const struct V_5 * V_6 ,
const struct V_123 * V_124 )
{
struct V_139 * V_140 ;
int V_125 , V_156 = 0 ;
if ( V_154 == V_157 )
return 0 ;
V_125 = F_60 ( V_154 , V_155 ,
V_144 , V_124 , & V_140 ) ;
if ( ! V_125 ) {
V_156 = F_28 ( V_140 , V_6 -> V_27 ) ;
F_71 ( V_140 ) ;
}
return V_156 ;
}
int F_72 ( struct V_123 * V_124 , struct V_22 * V_23 )
{
#ifdef F_27
struct V_80 * V_120 ;
int V_121 ;
#endif
if ( V_124 -> V_158 && V_124 -> V_158 != V_23 -> V_62 )
return 1 ;
if ( V_124 -> V_159 || V_124 -> V_160 ) {
if ( V_124 -> V_161 ) {
if ( F_70 ( V_124 -> V_162 ,
V_124 -> V_161 , V_23 -> V_5 , V_124 ) )
return 1 ;
}
if ( ( ! V_124 -> V_159 || V_124 -> V_159 == V_23 -> V_5 -> V_47 ) &&
( ! V_124 -> V_160 || V_124 -> V_160 == V_23 -> V_5 -> V_48 ) )
return 0 ;
return 1 ;
}
#ifdef F_27
if ( ! V_124 -> V_163 )
return 0 ;
V_120 = V_124 -> V_163 ;
V_121 = V_124 -> V_164 ;
F_26 (fi) {
int V_126 ;
if ( ! F_52 ( V_120 , V_121 ) )
return - V_127 ;
if ( V_120 -> V_131 && V_120 -> V_131 != V_6 -> V_47 )
return 1 ;
V_126 = F_55 ( V_120 ) ;
if ( V_126 > 0 ) {
struct V_133 * V_134 , * V_135 = F_56 ( V_120 ) ;
V_134 = F_57 ( V_135 , V_126 , V_136 ) ;
if ( V_134 && F_58 ( V_134 ) != V_6 -> V_48 )
return 1 ;
#ifdef F_18
V_134 = F_57 ( V_135 , V_126 , V_137 ) ;
if ( V_134 && F_59 ( V_134 ) != V_6 -> V_35 )
return 1 ;
#endif
}
V_120 = F_53 ( V_120 , & V_121 ) ;
} F_15 ( V_23 ) ;
#endif
return 0 ;
}
static int F_73 ( struct V_123 * V_124 , struct V_22 * V_23 ,
struct V_5 * V_6 )
{
int V_95 = 0 ;
struct V_165 * V_165 ;
struct V_70 * V_71 ;
V_165 = V_124 -> V_166 . V_104 ;
if ( V_6 -> V_48 ) {
struct V_167 V_168 ;
if ( V_6 -> V_51 & V_169 ) {
unsigned int V_170 ;
if ( V_124 -> V_171 >= V_172 )
return - V_127 ;
V_71 = F_74 ( V_165 , V_6 -> V_47 ) ;
if ( ! V_71 )
return - V_173 ;
if ( ! ( V_71 -> V_174 & V_175 ) )
return - V_176 ;
V_170 = F_75 ( V_165 , V_71 , V_6 -> V_48 ) ;
if ( V_170 != V_177 )
return - V_127 ;
if ( ! F_76 ( V_71 ) )
V_6 -> V_51 |= V_129 ;
V_6 -> V_26 = V_71 ;
F_77 ( V_71 ) ;
V_6 -> V_49 = V_172 ;
return 0 ;
}
F_78 () ;
{
struct V_178 * V_179 = NULL ;
struct V_180 V_181 = {
. V_182 = V_6 -> V_48 ,
. V_183 = V_124 -> V_171 + 1 ,
. V_184 = V_6 -> V_47 ,
. V_185 = V_186 ,
} ;
if ( V_181 . V_183 < V_172 )
V_181 . V_183 = V_172 ;
if ( V_124 -> V_187 )
V_179 = F_79 ( V_165 , V_124 -> V_187 ) ;
if ( V_179 )
V_95 = F_80 ( V_179 , & V_181 , & V_168 ,
V_188 |
V_189 ) ;
if ( ! V_179 || V_95 ) {
V_95 = F_81 ( V_165 , & V_181 , & V_168 ,
V_188 ) ;
}
if ( V_95 ) {
F_82 () ;
return V_95 ;
}
}
V_95 = - V_127 ;
if ( V_168 . type != V_177 && V_168 . type != V_190 )
goto V_191;
V_6 -> V_49 = V_168 . V_192 ;
V_6 -> V_47 = F_83 ( V_168 ) ;
V_6 -> V_26 = V_71 = F_84 ( V_168 ) ;
if ( ! V_71 )
goto V_191;
F_77 ( V_71 ) ;
if ( ! F_76 ( V_71 ) )
V_6 -> V_51 |= V_129 ;
V_95 = ( V_71 -> V_174 & V_175 ) ? 0 : - V_176 ;
} else {
struct V_147 * V_148 ;
if ( V_6 -> V_51 & ( V_193 | V_169 ) )
return - V_127 ;
F_78 () ;
V_95 = - V_173 ;
V_148 = F_85 ( V_165 , V_6 -> V_47 ) ;
if ( ! V_148 )
goto V_191;
V_95 = - V_176 ;
if ( ! ( V_148 -> V_71 -> V_174 & V_175 ) )
goto V_191;
V_6 -> V_26 = V_148 -> V_71 ;
F_77 ( V_6 -> V_26 ) ;
V_6 -> V_49 = V_194 ;
if ( ! F_76 ( V_6 -> V_26 ) )
V_6 -> V_51 |= V_129 ;
V_95 = 0 ;
}
V_191:
F_82 () ;
return V_95 ;
}
static inline unsigned int F_86 ( T_3 V_53 )
{
unsigned int V_54 = ( V_57 - 1 ) ;
return ( ( V_61 V_31 ) V_53 ^
( ( V_61 V_31 ) V_53 >> 7 ) ^
( ( V_61 V_31 ) V_53 >> 14 ) ) & V_54 ;
}
static struct V_64 * F_87 ( int V_195 )
{
if ( V_195 <= V_196 )
return F_88 ( V_195 , V_98 ) ;
else
return (struct V_64 * )
F_89 ( V_98 | V_197 ,
F_90 ( V_195 ) ) ;
}
static void F_91 ( struct V_64 * V_8 , int V_195 )
{
if ( ! V_8 )
return;
if ( V_195 <= V_196 )
F_5 ( V_8 ) ;
else
F_92 ( ( unsigned long ) V_8 , F_90 ( V_195 ) ) ;
}
static void F_93 ( struct V_64 * V_198 ,
struct V_64 * V_199 ,
unsigned int V_200 )
{
struct V_64 * V_201 , * V_202 ;
unsigned int V_203 = V_57 ;
unsigned int V_9 , V_195 ;
F_21 ( & V_39 ) ;
V_201 = V_65 ;
V_202 = V_204 ;
V_57 = V_200 ;
for ( V_9 = 0 ; V_9 < V_203 ; V_9 ++ ) {
struct V_64 * V_21 = & V_65 [ V_9 ] ;
struct V_205 * V_111 ;
struct V_22 * V_23 ;
F_94 (fi, n, head, fib_hash) {
struct V_64 * V_206 ;
unsigned int V_207 ;
V_207 = F_30 ( V_23 ) ;
V_206 = & V_198 [ V_207 ] ;
F_95 ( & V_23 -> V_41 , V_206 ) ;
}
}
V_65 = V_198 ;
for ( V_9 = 0 ; V_9 < V_203 ; V_9 ++ ) {
struct V_64 * V_208 = & V_204 [ V_9 ] ;
struct V_205 * V_111 ;
struct V_22 * V_23 ;
F_94 (fi, n, lhead, fib_lhash) {
struct V_64 * V_209 ;
unsigned int V_207 ;
V_207 = F_86 ( V_23 -> V_42 ) ;
V_209 = & V_199 [ V_207 ] ;
F_95 ( & V_23 -> V_43 , V_209 ) ;
}
}
V_204 = V_199 ;
F_24 ( & V_39 ) ;
V_195 = V_203 * sizeof( struct V_64 * ) ;
F_91 ( V_201 , V_195 ) ;
F_91 ( V_202 , V_195 ) ;
}
T_3 F_96 ( struct V_165 * V_165 , struct V_5 * V_6 )
{
V_6 -> V_210 = F_97 ( V_6 -> V_26 ,
V_6 -> V_48 ,
V_6 -> V_211 -> V_60 ) ;
V_6 -> V_212 = F_98 ( & V_165 -> V_37 . V_213 ) ;
return V_6 -> V_210 ;
}
static bool F_99 ( struct V_123 * V_124 , T_3 V_42 )
{
if ( V_124 -> V_214 != V_190 || ! V_124 -> V_215 ||
V_42 != V_124 -> V_215 ) {
V_31 V_86 = V_124 -> V_187 ;
int V_216 ;
if ( V_86 == V_217 )
V_86 = V_218 ;
V_216 = F_100 ( V_124 -> V_166 . V_104 ,
V_42 , V_86 ) ;
if ( V_216 != V_190 && V_86 != V_218 ) {
V_216 = F_100 ( V_124 -> V_166 . V_104 ,
V_42 , V_218 ) ;
}
if ( V_216 != V_190 )
return false ;
}
return true ;
}
static int
F_101 ( struct V_22 * V_23 , const struct V_123 * V_124 )
{
bool V_219 = false ;
struct V_133 * V_134 ;
int V_121 ;
if ( ! V_124 -> V_220 )
return 0 ;
F_102 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_103 ( V_134 ) ;
V_31 V_53 ;
if ( ! type )
continue;
if ( type > V_67 )
return - V_127 ;
if ( type == V_221 ) {
char V_222 [ V_77 ] ;
F_104 ( V_222 , V_134 , sizeof( V_222 ) ) ;
V_53 = F_105 ( V_222 , & V_219 ) ;
if ( V_53 == V_223 )
return - V_127 ;
} else {
V_53 = F_59 ( V_134 ) ;
}
if ( type == V_224 && V_53 > 65535 - 40 )
V_53 = 65535 - 40 ;
if ( type == V_225 && V_53 > 65535 - 15 )
V_53 = 65535 - 15 ;
if ( type == V_226 && V_53 > 255 )
V_53 = 255 ;
if ( type == V_227 && ( V_53 & ~ V_228 ) )
return - V_127 ;
V_23 -> V_30 [ type - 1 ] = V_53 ;
}
if ( V_219 )
V_23 -> V_30 [ V_227 - 1 ] |= V_229 ;
return 0 ;
}
struct V_22 * F_106 ( struct V_123 * V_124 )
{
int V_95 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_45 ;
int V_122 = 1 ;
struct V_165 * V_165 = V_124 -> V_166 . V_104 ;
if ( V_124 -> V_214 > V_230 )
goto V_143;
if ( V_231 [ V_124 -> V_214 ] . V_192 > V_124 -> V_171 )
goto V_143;
if ( V_124 -> V_130 & ( V_74 | V_129 ) )
goto V_143;
#ifdef F_27
if ( V_124 -> V_163 ) {
V_122 = F_51 ( V_124 -> V_163 , V_124 -> V_164 ) ;
if ( V_122 == 0 )
goto V_143;
}
#endif
V_95 = - V_96 ;
if ( V_34 >= V_57 ) {
unsigned int V_200 = V_57 << 1 ;
struct V_64 * V_198 ;
struct V_64 * V_199 ;
unsigned int V_195 ;
if ( ! V_200 )
V_200 = 16 ;
V_195 = V_200 * sizeof( struct V_64 * ) ;
V_198 = F_87 ( V_195 ) ;
V_199 = F_87 ( V_195 ) ;
if ( ! V_198 || ! V_199 ) {
F_91 ( V_198 , V_195 ) ;
F_91 ( V_199 , V_195 ) ;
} else
F_93 ( V_198 , V_199 , V_200 ) ;
if ( ! V_57 )
goto V_232;
}
V_23 = F_88 ( sizeof( * V_23 ) + V_122 * sizeof( struct V_5 ) , V_98 ) ;
if ( ! V_23 )
goto V_232;
V_34 ++ ;
if ( V_124 -> V_220 ) {
V_23 -> V_30 = F_88 ( sizeof( V_31 ) * V_67 , V_98 ) ;
if ( ! V_23 -> V_30 )
goto V_232;
} else
V_23 -> V_30 = ( V_31 * ) V_32 ;
V_23 -> V_36 = V_165 ;
V_23 -> V_59 = V_124 -> V_233 ;
V_23 -> V_60 = V_124 -> V_171 ;
V_23 -> V_68 = V_124 -> V_130 ;
V_23 -> V_62 = V_124 -> V_158 ;
V_23 -> V_42 = V_124 -> V_234 ;
V_23 -> V_66 = V_124 -> V_214 ;
V_23 -> V_235 = V_124 -> V_187 ;
V_23 -> V_58 = V_122 ;
F_12 (fi) {
V_25 -> V_211 = V_23 ;
V_25 -> V_28 = F_107 (struct rtable __rcu *) ;
if ( ! V_25 -> V_28 )
goto V_232;
} F_15 (fi)
V_95 = F_101 ( V_23 , V_124 ) ;
if ( V_95 )
goto V_232;
if ( V_124 -> V_163 ) {
#ifdef F_27
V_95 = F_54 ( V_23 , V_124 -> V_163 , V_124 -> V_164 , V_124 ) ;
if ( V_95 != 0 )
goto V_232;
if ( V_124 -> V_159 && V_23 -> V_5 -> V_47 != V_124 -> V_159 )
goto V_143;
if ( V_124 -> V_160 && V_23 -> V_5 -> V_48 != V_124 -> V_160 )
goto V_143;
#ifdef F_18
if ( V_124 -> V_236 && V_23 -> V_5 -> V_35 != V_124 -> V_236 )
goto V_143;
#endif
#else
goto V_143;
#endif
} else {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_124 -> V_161 ) {
struct V_139 * V_140 ;
if ( V_124 -> V_162 == V_157 )
goto V_143;
V_95 = F_60 ( V_124 -> V_162 ,
V_124 -> V_161 , V_144 , V_124 ,
& V_140 ) ;
if ( V_95 )
goto V_232;
V_6 -> V_27 = F_62 ( V_140 ) ;
}
V_6 -> V_47 = V_124 -> V_159 ;
V_6 -> V_48 = V_124 -> V_160 ;
V_6 -> V_51 = V_124 -> V_130 ;
#ifdef F_18
V_6 -> V_35 = V_124 -> V_236 ;
if ( V_6 -> V_35 )
V_23 -> V_36 -> V_37 . V_38 ++ ;
#endif
#ifdef F_27
V_6 -> V_50 = 1 ;
#endif
}
if ( V_231 [ V_124 -> V_214 ] . error ) {
if ( V_124 -> V_160 || V_124 -> V_159 || V_124 -> V_163 )
goto V_143;
goto V_237;
} else {
switch ( V_124 -> V_214 ) {
case V_177 :
case V_190 :
case V_238 :
case V_239 :
case V_240 :
break;
default:
goto V_143;
}
}
if ( V_124 -> V_171 > V_194 )
goto V_143;
if ( V_124 -> V_171 == V_194 ) {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_122 != 1 || V_6 -> V_48 )
goto V_143;
V_6 -> V_49 = V_241 ;
V_6 -> V_26 = F_108 ( V_165 , V_23 -> V_5 -> V_47 ) ;
V_95 = - V_173 ;
if ( ! V_6 -> V_26 )
goto V_232;
} else {
int V_242 = 0 ;
F_12 (fi) {
V_95 = F_73 ( V_124 , V_23 , V_25 ) ;
if ( V_95 != 0 )
goto V_232;
if ( V_25 -> V_51 & V_129 )
V_242 ++ ;
} F_15 (fi)
if ( V_242 == V_23 -> V_58 )
V_23 -> V_68 |= V_129 ;
}
if ( V_23 -> V_42 && ! F_99 ( V_124 , V_23 -> V_42 ) )
goto V_143;
F_12 (fi) {
F_96 ( V_165 , V_25 ) ;
F_69 ( V_23 , V_25 ) ;
} F_15 (fi)
F_63 ( V_23 ) ;
V_237:
V_45 = F_31 ( V_23 ) ;
if ( V_45 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
V_45 -> V_40 ++ ;
return V_45 ;
}
V_23 -> V_40 ++ ;
F_109 ( & V_23 -> V_243 ) ;
F_21 ( & V_39 ) ;
F_95 ( & V_23 -> V_41 ,
& V_65 [ F_30 ( V_23 ) ] ) ;
if ( V_23 -> V_42 ) {
struct V_64 * V_21 ;
V_21 = & V_204 [ F_86 ( V_23 -> V_42 ) ] ;
F_95 ( & V_23 -> V_43 , V_21 ) ;
}
F_12 (fi) {
struct V_64 * V_21 ;
unsigned int V_8 ;
if ( ! V_25 -> V_26 )
continue;
V_8 = F_29 ( V_25 -> V_26 -> V_72 ) ;
V_21 = & V_73 [ V_8 ] ;
F_95 ( & V_25 -> V_44 , V_21 ) ;
} F_15 (fi)
F_24 ( & V_39 ) ;
return V_23 ;
V_143:
V_95 = - V_127 ;
V_232:
if ( V_23 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
}
return F_110 ( V_95 ) ;
}
int F_43 ( struct V_90 * V_91 , V_31 V_100 , V_31 V_92 , int V_81 ,
V_31 V_86 , T_6 type , T_3 V_4 , int V_85 , T_6 V_244 ,
struct V_22 * V_23 , unsigned int V_174 )
{
struct V_245 * V_93 ;
struct V_76 * V_246 ;
V_93 = F_111 ( V_91 , V_100 , V_92 , V_81 , sizeof( * V_246 ) , V_174 ) ;
if ( ! V_93 )
return - V_103 ;
V_246 = F_112 ( V_93 ) ;
V_246 -> V_247 = V_144 ;
V_246 -> V_248 = V_85 ;
V_246 -> V_249 = 0 ;
V_246 -> V_250 = V_244 ;
if ( V_86 < 256 )
V_246 -> V_251 = V_86 ;
else
V_246 -> V_251 = V_252 ;
if ( F_113 ( V_91 , V_253 , V_86 ) )
goto V_254;
V_246 -> V_255 = type ;
V_246 -> V_256 = V_23 -> V_68 ;
V_246 -> V_257 = V_23 -> V_60 ;
V_246 -> V_258 = V_23 -> V_59 ;
if ( V_246 -> V_248 &&
F_114 ( V_91 , V_259 , V_4 ) )
goto V_254;
if ( V_23 -> V_62 &&
F_113 ( V_91 , V_260 , V_23 -> V_62 ) )
goto V_254;
if ( F_115 ( V_91 , V_23 -> V_30 ) < 0 )
goto V_254;
if ( V_23 -> V_42 &&
F_114 ( V_91 , V_261 , V_23 -> V_42 ) )
goto V_254;
if ( V_23 -> V_58 == 1 ) {
struct V_147 * V_148 ;
if ( V_23 -> V_5 -> V_48 &&
F_114 ( V_91 , V_136 , V_23 -> V_5 -> V_48 ) )
goto V_254;
if ( V_23 -> V_5 -> V_47 &&
F_113 ( V_91 , V_262 , V_23 -> V_5 -> V_47 ) )
goto V_254;
if ( V_23 -> V_5 -> V_51 & V_129 ) {
V_148 = F_64 ( V_23 -> V_5 -> V_26 ) ;
if ( V_148 &&
F_65 ( V_148 ) )
V_246 -> V_256 |= V_74 ;
}
#ifdef F_18
if ( V_23 -> V_5 [ 0 ] . V_35 &&
F_113 ( V_91 , V_137 , V_23 -> V_5 [ 0 ] . V_35 ) )
goto V_254;
#endif
if ( V_23 -> V_5 -> V_27 &&
F_116 ( V_91 , V_23 -> V_5 -> V_27 ) < 0 )
goto V_254;
}
#ifdef F_27
if ( V_23 -> V_58 > 1 ) {
struct V_80 * V_120 ;
struct V_133 * V_263 ;
V_263 = F_117 ( V_91 , V_264 ) ;
if ( ! V_263 )
goto V_254;
F_26 (fi) {
struct V_147 * V_148 ;
V_120 = F_118 ( V_91 , sizeof( * V_120 ) ) ;
if ( ! V_120 )
goto V_254;
V_120 -> V_128 = V_6 -> V_51 & 0xFF ;
if ( V_6 -> V_51 & V_129 ) {
V_148 = F_64 ( V_6 -> V_26 ) ;
if ( V_148 &&
F_65 ( V_148 ) )
V_120 -> V_128 |= V_74 ;
}
V_120 -> V_132 = V_6 -> V_50 - 1 ;
V_120 -> V_131 = V_6 -> V_47 ;
if ( V_6 -> V_48 &&
F_114 ( V_91 , V_136 , V_6 -> V_48 ) )
goto V_254;
#ifdef F_18
if ( V_6 -> V_35 &&
F_113 ( V_91 , V_137 , V_6 -> V_35 ) )
goto V_254;
#endif
if ( V_6 -> V_27 &&
F_116 ( V_91 , V_6 -> V_27 ) < 0 )
goto V_254;
V_120 -> V_265 = F_119 ( V_91 ) - ( void * ) V_120 ;
} F_15 ( V_23 ) ;
F_120 ( V_91 , V_263 ) ;
}
#endif
F_121 ( V_91 , V_93 ) ;
return 0 ;
V_254:
F_122 ( V_91 , V_93 ) ;
return - V_103 ;
}
int F_123 ( struct V_70 * V_71 , T_3 V_266 )
{
int V_125 = 0 ;
unsigned int V_8 = F_86 ( V_266 ) ;
struct V_64 * V_21 = & V_204 [ V_8 ] ;
struct V_165 * V_165 = F_124 ( V_71 ) ;
int V_86 = F_125 ( V_71 ) ;
struct V_22 * V_23 ;
if ( ! V_204 || V_266 == 0 )
return 0 ;
F_32 (fi, head, fib_lhash) {
if ( ! F_33 ( V_23 -> V_36 , V_165 ) ||
V_23 -> V_235 != V_86 )
continue;
if ( V_23 -> V_42 == V_266 ) {
V_23 -> V_68 |= V_74 ;
V_125 ++ ;
}
}
return V_125 ;
}
static int F_126 ( struct V_5 * V_5 ,
enum V_267 V_268 )
{
struct V_147 * V_148 = F_64 ( V_5 -> V_26 ) ;
struct V_269 V_88 = {
. V_5 = V_5 ,
} ;
switch ( V_268 ) {
case V_270 :
if ( V_5 -> V_51 & V_74 )
break;
if ( F_65 ( V_148 ) &&
V_5 -> V_51 & V_129 )
break;
return F_127 ( F_124 ( V_5 -> V_26 ) , V_268 ,
& V_88 . V_88 ) ;
case V_271 :
if ( ( F_65 ( V_148 ) &&
V_5 -> V_51 & V_129 ) ||
( V_5 -> V_51 & V_74 ) )
return F_127 ( F_124 ( V_5 -> V_26 ) ,
V_268 , & V_88 . V_88 ) ;
default:
break;
}
return V_272 ;
}
int F_128 ( struct V_70 * V_71 , unsigned long V_81 , bool V_273 )
{
int V_125 = 0 ;
int V_192 = V_241 ;
struct V_22 * V_274 = NULL ;
unsigned int V_8 = F_29 ( V_71 -> V_72 ) ;
struct V_64 * V_21 = & V_73 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_273 )
V_192 = - 1 ;
F_32 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_211 ;
int V_275 ;
F_129 ( ! V_23 -> V_58 ) ;
if ( V_6 -> V_26 != V_71 || V_23 == V_274 )
continue;
V_274 = V_23 ;
V_275 = 0 ;
F_12 (fi) {
if ( V_25 -> V_51 & V_74 )
V_275 ++ ;
else if ( V_25 -> V_26 == V_71 &&
V_25 -> V_49 != V_192 ) {
switch ( V_81 ) {
case V_276 :
case V_277 :
V_25 -> V_51 |= V_74 ;
case V_278 :
V_25 -> V_51 |= V_129 ;
break;
}
F_126 ( V_25 ,
V_271 ) ;
V_275 ++ ;
}
#ifdef F_27
if ( V_81 == V_277 &&
V_25 -> V_26 == V_71 ) {
V_275 = V_23 -> V_58 ;
break;
}
#endif
} F_15 (fi)
if ( V_275 == V_23 -> V_58 ) {
switch ( V_81 ) {
case V_276 :
case V_277 :
V_23 -> V_68 |= V_74 ;
case V_278 :
V_23 -> V_68 |= V_129 ;
break;
}
V_125 ++ ;
}
F_63 ( V_23 ) ;
}
return V_125 ;
}
static void F_130 ( const struct V_180 * V_279 , struct V_167 * V_168 )
{
struct V_22 * V_23 = NULL , * V_107 = NULL ;
struct V_64 * V_280 = V_168 -> V_280 ;
struct V_178 * V_281 = V_168 -> V_282 ;
T_6 V_283 = 32 - V_168 -> V_284 ;
int V_106 = - 1 , V_108 = - 1 ;
struct V_83 * V_84 , * V_285 = NULL ;
V_31 V_286 = V_168 -> V_23 -> V_62 ;
T_6 V_287 = 0 ;
F_131 (fa, fa_head, fa_list) {
struct V_22 * V_288 = V_84 -> V_97 ;
if ( V_84 -> V_289 != V_283 )
continue;
if ( V_84 -> V_102 && V_84 -> V_102 != V_279 -> V_290 )
continue;
if ( V_84 -> V_86 != V_281 -> V_86 )
continue;
if ( V_288 -> V_62 > V_286 &&
V_84 -> V_102 == V_287 ) {
if ( V_287 )
continue;
break;
}
if ( V_288 -> V_68 & V_74 )
continue;
V_287 = V_84 -> V_102 ;
V_286 = V_288 -> V_62 ;
if ( V_288 -> V_60 != V_168 -> V_192 ||
V_84 -> V_101 != V_177 )
continue;
if ( ! V_288 -> V_5 [ 0 ] . V_48 ||
V_288 -> V_5 [ 0 ] . V_49 != V_172 )
continue;
F_132 ( V_84 ) ;
if ( ! V_23 ) {
if ( V_288 != V_168 -> V_23 )
break;
V_285 = V_84 ;
} else if ( ! F_48 ( V_23 , V_106 , & V_107 ,
& V_108 , V_285 -> V_291 ) ) {
F_133 ( V_168 , V_23 ) ;
V_285 -> V_291 = V_106 ;
goto V_191;
}
V_23 = V_288 ;
V_106 ++ ;
}
if ( V_106 <= 0 || ! V_23 ) {
if ( V_285 )
V_285 -> V_291 = - 1 ;
goto V_191;
}
if ( ! F_48 ( V_23 , V_106 , & V_107 , & V_108 ,
V_285 -> V_291 ) ) {
F_133 ( V_168 , V_23 ) ;
V_285 -> V_291 = V_106 ;
goto V_191;
}
if ( V_108 >= 0 )
F_133 ( V_168 , V_107 ) ;
V_285 -> V_291 = V_108 ;
V_191:
return;
}
int F_134 ( struct V_70 * V_71 , unsigned int V_51 )
{
struct V_22 * V_274 ;
unsigned int V_8 ;
struct V_64 * V_21 ;
struct V_5 * V_6 ;
int V_125 ;
if ( ! ( V_71 -> V_174 & V_175 ) )
return 0 ;
if ( V_51 & V_74 ) {
unsigned int V_174 = F_135 ( V_71 ) ;
if ( V_174 & ( V_292 | V_293 ) )
V_51 |= V_129 ;
}
V_274 = NULL ;
V_8 = F_29 ( V_71 -> V_72 ) ;
V_21 = & V_73 [ V_8 ] ;
V_125 = 0 ;
F_32 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_211 ;
int V_294 ;
F_129 ( ! V_23 -> V_58 ) ;
if ( V_6 -> V_26 != V_71 || V_23 == V_274 )
continue;
V_274 = V_23 ;
V_294 = 0 ;
F_12 (fi) {
if ( ! ( V_25 -> V_51 & V_51 ) ) {
V_294 ++ ;
continue;
}
if ( ! V_25 -> V_26 ||
! ( V_25 -> V_26 -> V_174 & V_175 ) )
continue;
if ( V_25 -> V_26 != V_71 ||
! F_64 ( V_71 ) )
continue;
V_294 ++ ;
V_25 -> V_51 &= ~ V_51 ;
F_126 ( V_25 , V_270 ) ;
} F_15 (fi)
if ( V_294 > 0 ) {
V_23 -> V_68 &= ~ V_51 ;
V_125 ++ ;
}
F_63 ( V_23 ) ;
}
return V_125 ;
}
static bool F_136 ( const struct V_5 * V_6 )
{
int V_112 = V_117 ;
if ( V_6 -> V_49 == V_172 ) {
struct V_110 * V_111 ;
F_137 () ;
V_111 = F_138 ( V_6 -> V_26 ,
( V_61 V_31 ) V_6 -> V_48 ) ;
if ( V_111 )
V_112 = V_111 -> V_116 ;
F_139 () ;
}
return ! ! ( V_112 & V_118 ) ;
}
void F_140 ( struct V_167 * V_168 , int V_8 )
{
struct V_22 * V_23 = V_168 -> V_23 ;
struct V_165 * V_165 = V_23 -> V_36 ;
bool V_295 = false ;
F_26 (fi) {
if ( V_8 > F_98 ( & V_6 -> V_151 ) )
continue;
if ( ! V_165 -> V_37 . V_296 ||
F_136 ( V_6 ) ) {
V_168 -> V_297 = V_298 ;
return;
}
if ( ! V_295 ) {
V_168 -> V_297 = V_298 ;
V_295 = true ;
}
} F_15 ( V_23 ) ;
}
void F_141 ( struct V_165 * V_165 , struct V_167 * V_168 ,
struct V_180 * V_181 , int V_299 )
{
bool V_300 ;
V_300 = ( V_181 -> V_184 == 0 ||
V_181 -> V_301 & V_302 ) ;
#ifdef F_27
if ( V_168 -> V_23 -> V_58 > 1 && V_300 ) {
if ( V_299 < 0 )
V_299 = F_142 ( V_181 ) >> 1 ;
F_140 ( V_168 , V_299 ) ;
}
else
#endif
if ( ! V_168 -> V_284 &&
V_168 -> V_282 -> V_303 > 1 &&
V_168 -> type == V_177 && V_300 )
F_130 ( V_181 , V_168 ) ;
if ( ! V_181 -> V_304 )
V_181 -> V_304 = F_143 ( V_165 , * V_168 ) ;
}
