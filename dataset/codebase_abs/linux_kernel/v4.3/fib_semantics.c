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
struct V_125 * V_125 = V_124 -> V_126 . V_104 ;
int V_127 ;
F_12 (fi) {
int V_128 ;
if ( ! F_52 ( V_120 , V_121 ) )
return - V_129 ;
V_25 -> V_51 =
( V_124 -> V_130 & ~ 0xFF ) | V_120 -> V_131 ;
V_25 -> V_47 = V_120 -> V_132 ;
V_25 -> V_50 = V_120 -> V_133 + 1 ;
V_128 = F_55 ( V_120 ) ;
if ( V_128 > 0 ) {
struct V_134 * V_135 , * V_136 = F_56 ( V_120 ) ;
V_135 = F_57 ( V_136 , V_128 , V_137 ) ;
V_25 -> V_48 = V_135 ? F_58 ( V_135 ) : 0 ;
#ifdef F_18
V_135 = F_57 ( V_136 , V_128 , V_138 ) ;
V_25 -> V_35 = V_135 ? F_59 ( V_135 ) : 0 ;
if ( V_25 -> V_35 )
V_23 -> V_36 -> V_37 . V_38 ++ ;
#endif
V_135 = F_57 ( V_136 , V_128 , V_139 ) ;
if ( V_135 ) {
struct V_140 * V_141 ;
struct V_70 * V_71 = NULL ;
struct V_134 * V_142 ;
V_142 = F_57 ( V_136 , V_128 ,
V_143 ) ;
if ( ! V_142 )
goto V_144;
if ( V_124 -> V_145 )
V_71 = F_60 ( V_125 , V_124 -> V_145 ) ;
V_127 = F_61 ( V_71 , F_62 (
V_142 ) ,
V_135 , V_146 , V_124 ,
& V_141 ) ;
if ( V_127 )
goto V_99;
V_25 -> V_27 =
F_63 ( V_141 ) ;
}
}
V_120 = F_53 ( V_120 , & V_121 ) ;
} F_15 ( V_23 ) ;
return 0 ;
V_144:
V_127 = - V_129 ;
V_99:
return V_127 ;
}
static int F_64 ( struct V_125 * V_125 , T_5 V_147 ,
struct V_134 * V_148 ,
int V_149 , const struct V_5 * V_6 ,
const struct V_123 * V_124 )
{
struct V_140 * V_141 ;
struct V_70 * V_71 = NULL ;
int V_127 , V_150 = 0 ;
if ( V_147 == V_151 )
return 0 ;
if ( V_149 )
V_71 = F_60 ( V_125 , V_149 ) ;
V_127 = F_61 ( V_71 , V_147 , V_148 ,
V_146 , V_124 , & V_141 ) ;
if ( ! V_127 ) {
V_150 = F_28 ( V_141 , V_6 -> V_27 ) ;
F_65 ( V_141 ) ;
}
return V_150 ;
}
int F_66 ( struct V_123 * V_124 , struct V_22 * V_23 )
{
struct V_125 * V_125 = V_124 -> V_126 . V_104 ;
#ifdef F_27
struct V_80 * V_120 ;
int V_121 ;
#endif
if ( V_124 -> V_152 && V_124 -> V_152 != V_23 -> V_62 )
return 1 ;
if ( V_124 -> V_145 || V_124 -> V_153 ) {
if ( V_124 -> V_154 ) {
if ( F_64 ( V_125 , V_124 -> V_155 ,
V_124 -> V_154 , V_124 -> V_145 ,
V_23 -> V_5 , V_124 ) )
return 1 ;
}
if ( ( ! V_124 -> V_145 || V_124 -> V_145 == V_23 -> V_5 -> V_47 ) &&
( ! V_124 -> V_153 || V_124 -> V_153 == V_23 -> V_5 -> V_48 ) )
return 0 ;
return 1 ;
}
#ifdef F_27
if ( ! V_124 -> V_156 )
return 0 ;
V_120 = V_124 -> V_156 ;
V_121 = V_124 -> V_157 ;
F_26 (fi) {
int V_128 ;
if ( ! F_52 ( V_120 , V_121 ) )
return - V_129 ;
if ( V_120 -> V_132 && V_120 -> V_132 != V_6 -> V_47 )
return 1 ;
V_128 = F_55 ( V_120 ) ;
if ( V_128 > 0 ) {
struct V_134 * V_135 , * V_136 = F_56 ( V_120 ) ;
V_135 = F_57 ( V_136 , V_128 , V_137 ) ;
if ( V_135 && F_58 ( V_135 ) != V_6 -> V_48 )
return 1 ;
#ifdef F_18
V_135 = F_57 ( V_136 , V_128 , V_138 ) ;
if ( V_135 && F_59 ( V_135 ) != V_6 -> V_35 )
return 1 ;
#endif
}
V_120 = F_53 ( V_120 , & V_121 ) ;
} F_15 ( V_23 ) ;
#endif
return 0 ;
}
static int F_67 ( struct V_123 * V_124 , struct V_22 * V_23 ,
struct V_5 * V_6 )
{
int V_95 = 0 ;
struct V_125 * V_125 ;
struct V_70 * V_71 ;
V_125 = V_124 -> V_126 . V_104 ;
if ( V_6 -> V_48 ) {
struct V_158 V_159 ;
if ( V_6 -> V_51 & V_160 ) {
unsigned int V_161 ;
if ( V_124 -> V_162 >= V_163 )
return - V_129 ;
V_71 = F_60 ( V_125 , V_6 -> V_47 ) ;
if ( ! V_71 )
return - V_164 ;
if ( ! ( V_71 -> V_165 & V_166 ) )
return - V_167 ;
V_161 = F_68 ( V_125 , V_71 , V_6 -> V_48 ) ;
if ( V_161 != V_168 )
return - V_129 ;
if ( ! F_69 ( V_71 ) )
V_6 -> V_51 |= V_169 ;
V_6 -> V_26 = V_71 ;
F_70 ( V_71 ) ;
V_6 -> V_49 = V_163 ;
return 0 ;
}
F_71 () ;
{
struct V_170 * V_171 = NULL ;
struct V_172 V_173 = {
. V_174 = V_6 -> V_48 ,
. V_175 = V_124 -> V_162 + 1 ,
. V_176 = V_6 -> V_47 ,
. V_177 = V_178 ,
} ;
if ( V_173 . V_175 < V_163 )
V_173 . V_175 = V_163 ;
if ( V_124 -> V_179 )
V_171 = F_72 ( V_125 , V_124 -> V_179 ) ;
if ( V_171 )
V_95 = F_73 ( V_171 , & V_173 , & V_159 ,
V_180 |
V_181 ) ;
if ( ! V_171 || V_95 ) {
V_95 = F_74 ( V_125 , & V_173 , & V_159 ,
V_180 ) ;
}
if ( V_95 ) {
F_75 () ;
return V_95 ;
}
}
V_95 = - V_129 ;
if ( V_159 . type != V_168 && V_159 . type != V_182 )
goto V_183;
V_6 -> V_49 = V_159 . V_184 ;
V_6 -> V_47 = F_76 ( V_159 ) ;
V_6 -> V_26 = V_71 = F_77 ( V_159 ) ;
if ( ! V_71 )
goto V_183;
F_70 ( V_71 ) ;
if ( ! F_69 ( V_71 ) )
V_6 -> V_51 |= V_169 ;
V_95 = ( V_71 -> V_165 & V_166 ) ? 0 : - V_167 ;
} else {
struct V_185 * V_186 ;
if ( V_6 -> V_51 & ( V_187 | V_160 ) )
return - V_129 ;
F_71 () ;
V_95 = - V_164 ;
V_186 = F_78 ( V_125 , V_6 -> V_47 ) ;
if ( ! V_186 )
goto V_183;
V_95 = - V_167 ;
if ( ! ( V_186 -> V_71 -> V_165 & V_166 ) )
goto V_183;
V_6 -> V_26 = V_186 -> V_71 ;
F_70 ( V_6 -> V_26 ) ;
V_6 -> V_49 = V_188 ;
if ( ! F_69 ( V_6 -> V_26 ) )
V_6 -> V_51 |= V_169 ;
V_95 = 0 ;
}
V_183:
F_75 () ;
return V_95 ;
}
static inline unsigned int F_79 ( T_3 V_53 )
{
unsigned int V_54 = ( V_57 - 1 ) ;
return ( ( V_61 V_31 ) V_53 ^
( ( V_61 V_31 ) V_53 >> 7 ) ^
( ( V_61 V_31 ) V_53 >> 14 ) ) & V_54 ;
}
static struct V_64 * F_80 ( int V_189 )
{
if ( V_189 <= V_190 )
return F_81 ( V_189 , V_98 ) ;
else
return (struct V_64 * )
F_82 ( V_98 | V_191 ,
F_83 ( V_189 ) ) ;
}
static void F_84 ( struct V_64 * V_8 , int V_189 )
{
if ( ! V_8 )
return;
if ( V_189 <= V_190 )
F_5 ( V_8 ) ;
else
F_85 ( ( unsigned long ) V_8 , F_83 ( V_189 ) ) ;
}
static void F_86 ( struct V_64 * V_192 ,
struct V_64 * V_193 ,
unsigned int V_194 )
{
struct V_64 * V_195 , * V_196 ;
unsigned int V_197 = V_57 ;
unsigned int V_9 , V_189 ;
F_21 ( & V_39 ) ;
V_195 = V_65 ;
V_196 = V_198 ;
V_57 = V_194 ;
for ( V_9 = 0 ; V_9 < V_197 ; V_9 ++ ) {
struct V_64 * V_21 = & V_65 [ V_9 ] ;
struct V_199 * V_111 ;
struct V_22 * V_23 ;
F_87 (fi, n, head, fib_hash) {
struct V_64 * V_200 ;
unsigned int V_201 ;
V_201 = F_30 ( V_23 ) ;
V_200 = & V_192 [ V_201 ] ;
F_88 ( & V_23 -> V_41 , V_200 ) ;
}
}
V_65 = V_192 ;
for ( V_9 = 0 ; V_9 < V_197 ; V_9 ++ ) {
struct V_64 * V_202 = & V_198 [ V_9 ] ;
struct V_199 * V_111 ;
struct V_22 * V_23 ;
F_87 (fi, n, lhead, fib_lhash) {
struct V_64 * V_203 ;
unsigned int V_201 ;
V_201 = F_79 ( V_23 -> V_42 ) ;
V_203 = & V_193 [ V_201 ] ;
F_88 ( & V_23 -> V_43 , V_203 ) ;
}
}
V_198 = V_193 ;
F_24 ( & V_39 ) ;
V_189 = V_197 * sizeof( struct V_64 * ) ;
F_84 ( V_195 , V_189 ) ;
F_84 ( V_196 , V_189 ) ;
}
T_3 F_89 ( struct V_125 * V_125 , struct V_5 * V_6 )
{
V_6 -> V_204 = F_90 ( V_6 -> V_26 ,
V_6 -> V_48 ,
V_6 -> V_205 -> V_60 ) ;
V_6 -> V_206 = F_91 ( & V_125 -> V_37 . V_207 ) ;
return V_6 -> V_204 ;
}
static bool F_92 ( struct V_123 * V_124 , T_3 V_42 )
{
if ( V_124 -> V_208 != V_182 || ! V_124 -> V_209 ||
V_42 != V_124 -> V_209 ) {
V_31 V_86 = V_124 -> V_179 ;
if ( V_86 == V_210 )
V_86 = V_211 ;
if ( F_93 ( V_124 -> V_126 . V_104 ,
V_42 , V_86 ) != V_182 ) {
return false ;
}
}
return true ;
}
static int
F_94 ( struct V_22 * V_23 , const struct V_123 * V_124 )
{
bool V_212 = false ;
struct V_134 * V_135 ;
int V_121 ;
if ( ! V_124 -> V_213 )
return 0 ;
F_95 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_96 ( V_135 ) ;
V_31 V_53 ;
if ( ! type )
continue;
if ( type > V_67 )
return - V_129 ;
if ( type == V_214 ) {
char V_215 [ V_77 ] ;
F_97 ( V_215 , V_135 , sizeof( V_215 ) ) ;
V_53 = F_98 ( V_215 , & V_212 ) ;
if ( V_53 == V_216 )
return - V_129 ;
} else {
V_53 = F_59 ( V_135 ) ;
}
if ( type == V_217 && V_53 > 65535 - 40 )
V_53 = 65535 - 40 ;
if ( type == V_218 && V_53 > 65535 - 15 )
V_53 = 65535 - 15 ;
if ( type == V_219 && ( V_53 & ~ V_220 ) )
return - V_129 ;
V_23 -> V_30 [ type - 1 ] = V_53 ;
}
if ( V_212 )
V_23 -> V_30 [ V_219 - 1 ] |= V_221 ;
return 0 ;
}
struct V_22 * F_99 ( struct V_123 * V_124 )
{
int V_95 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_45 ;
int V_122 = 1 ;
struct V_125 * V_125 = V_124 -> V_126 . V_104 ;
if ( V_124 -> V_208 > V_222 )
goto V_144;
if ( V_223 [ V_124 -> V_208 ] . V_184 > V_124 -> V_162 )
goto V_144;
#ifdef F_27
if ( V_124 -> V_156 ) {
V_122 = F_51 ( V_124 -> V_156 , V_124 -> V_157 ) ;
if ( V_122 == 0 )
goto V_144;
}
#endif
V_95 = - V_96 ;
if ( V_34 >= V_57 ) {
unsigned int V_194 = V_57 << 1 ;
struct V_64 * V_192 ;
struct V_64 * V_193 ;
unsigned int V_189 ;
if ( ! V_194 )
V_194 = 16 ;
V_189 = V_194 * sizeof( struct V_64 * ) ;
V_192 = F_80 ( V_189 ) ;
V_193 = F_80 ( V_189 ) ;
if ( ! V_192 || ! V_193 ) {
F_84 ( V_192 , V_189 ) ;
F_84 ( V_193 , V_189 ) ;
} else
F_86 ( V_192 , V_193 , V_194 ) ;
if ( ! V_57 )
goto V_224;
}
V_23 = F_81 ( sizeof( * V_23 ) + V_122 * sizeof( struct V_5 ) , V_98 ) ;
if ( ! V_23 )
goto V_224;
V_34 ++ ;
if ( V_124 -> V_213 ) {
V_23 -> V_30 = F_81 ( sizeof( V_31 ) * V_67 , V_98 ) ;
if ( ! V_23 -> V_30 )
goto V_224;
} else
V_23 -> V_30 = ( V_31 * ) V_32 ;
V_23 -> V_36 = V_125 ;
V_23 -> V_59 = V_124 -> V_225 ;
V_23 -> V_60 = V_124 -> V_162 ;
V_23 -> V_68 = V_124 -> V_130 ;
V_23 -> V_62 = V_124 -> V_152 ;
V_23 -> V_42 = V_124 -> V_226 ;
V_23 -> V_66 = V_124 -> V_208 ;
V_23 -> V_58 = V_122 ;
F_12 (fi) {
V_25 -> V_205 = V_23 ;
V_25 -> V_28 = F_100 (struct rtable __rcu *) ;
if ( ! V_25 -> V_28 )
goto V_224;
} F_15 (fi)
V_95 = F_94 ( V_23 , V_124 ) ;
if ( V_95 )
goto V_224;
if ( V_124 -> V_156 ) {
#ifdef F_27
V_95 = F_54 ( V_23 , V_124 -> V_156 , V_124 -> V_157 , V_124 ) ;
if ( V_95 != 0 )
goto V_224;
if ( V_124 -> V_145 && V_23 -> V_5 -> V_47 != V_124 -> V_145 )
goto V_144;
if ( V_124 -> V_153 && V_23 -> V_5 -> V_48 != V_124 -> V_153 )
goto V_144;
#ifdef F_18
if ( V_124 -> V_227 && V_23 -> V_5 -> V_35 != V_124 -> V_227 )
goto V_144;
#endif
#else
goto V_144;
#endif
} else {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_124 -> V_154 ) {
struct V_140 * V_141 ;
struct V_70 * V_71 = NULL ;
if ( V_124 -> V_155 == V_151 )
goto V_144;
if ( V_124 -> V_145 )
V_71 = F_60 ( V_125 , V_124 -> V_145 ) ;
V_95 = F_61 ( V_71 , V_124 -> V_155 ,
V_124 -> V_154 , V_146 , V_124 ,
& V_141 ) ;
if ( V_95 )
goto V_224;
V_6 -> V_27 = F_63 ( V_141 ) ;
}
V_6 -> V_47 = V_124 -> V_145 ;
V_6 -> V_48 = V_124 -> V_153 ;
V_6 -> V_51 = V_124 -> V_130 ;
#ifdef F_18
V_6 -> V_35 = V_124 -> V_227 ;
if ( V_6 -> V_35 )
V_23 -> V_36 -> V_37 . V_38 ++ ;
#endif
#ifdef F_27
V_6 -> V_50 = 1 ;
#endif
}
if ( V_223 [ V_124 -> V_208 ] . error ) {
if ( V_124 -> V_153 || V_124 -> V_145 || V_124 -> V_156 )
goto V_144;
goto V_228;
} else {
switch ( V_124 -> V_208 ) {
case V_168 :
case V_182 :
case V_229 :
case V_230 :
case V_231 :
break;
default:
goto V_144;
}
}
if ( V_124 -> V_162 > V_188 )
goto V_144;
if ( V_124 -> V_162 == V_188 ) {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_122 != 1 || V_6 -> V_48 )
goto V_144;
V_6 -> V_49 = V_232 ;
V_6 -> V_26 = F_101 ( V_125 , V_23 -> V_5 -> V_47 ) ;
V_95 = - V_164 ;
if ( ! V_6 -> V_26 )
goto V_224;
} else {
int V_233 = 0 ;
F_12 (fi) {
V_95 = F_67 ( V_124 , V_23 , V_25 ) ;
if ( V_95 != 0 )
goto V_224;
if ( V_25 -> V_51 & V_169 )
V_233 ++ ;
} F_15 (fi)
if ( V_233 == V_23 -> V_58 )
V_23 -> V_68 |= V_169 ;
}
if ( V_23 -> V_42 && ! F_92 ( V_124 , V_23 -> V_42 ) )
goto V_144;
F_12 (fi) {
F_89 ( V_125 , V_25 ) ;
} F_15 (fi)
V_228:
V_45 = F_31 ( V_23 ) ;
if ( V_45 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
V_45 -> V_40 ++ ;
return V_45 ;
}
V_23 -> V_40 ++ ;
F_102 ( & V_23 -> V_234 ) ;
F_21 ( & V_39 ) ;
F_88 ( & V_23 -> V_41 ,
& V_65 [ F_30 ( V_23 ) ] ) ;
if ( V_23 -> V_42 ) {
struct V_64 * V_21 ;
V_21 = & V_198 [ F_79 ( V_23 -> V_42 ) ] ;
F_88 ( & V_23 -> V_43 , V_21 ) ;
}
F_12 (fi) {
struct V_64 * V_21 ;
unsigned int V_8 ;
if ( ! V_25 -> V_26 )
continue;
V_8 = F_29 ( V_25 -> V_26 -> V_72 ) ;
V_21 = & V_73 [ V_8 ] ;
F_88 ( & V_25 -> V_44 , V_21 ) ;
} F_15 (fi)
F_24 ( & V_39 ) ;
return V_23 ;
V_144:
V_95 = - V_129 ;
V_224:
if ( V_23 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
}
return F_103 ( V_95 ) ;
}
int F_43 ( struct V_90 * V_91 , V_31 V_100 , V_31 V_92 , int V_81 ,
V_31 V_86 , T_6 type , T_3 V_4 , int V_85 , T_6 V_235 ,
struct V_22 * V_23 , unsigned int V_165 )
{
struct V_236 * V_93 ;
struct V_76 * V_237 ;
V_93 = F_104 ( V_91 , V_100 , V_92 , V_81 , sizeof( * V_237 ) , V_165 ) ;
if ( ! V_93 )
return - V_103 ;
V_237 = F_105 ( V_93 ) ;
V_237 -> V_238 = V_146 ;
V_237 -> V_239 = V_85 ;
V_237 -> V_240 = 0 ;
V_237 -> V_241 = V_235 ;
if ( V_86 < 256 )
V_237 -> V_242 = V_86 ;
else
V_237 -> V_242 = V_243 ;
if ( F_106 ( V_91 , V_244 , V_86 ) )
goto V_245;
V_237 -> V_246 = type ;
V_237 -> V_247 = V_23 -> V_68 ;
V_237 -> V_248 = V_23 -> V_60 ;
V_237 -> V_249 = V_23 -> V_59 ;
if ( V_237 -> V_239 &&
F_107 ( V_91 , V_250 , V_4 ) )
goto V_245;
if ( V_23 -> V_62 &&
F_106 ( V_91 , V_251 , V_23 -> V_62 ) )
goto V_245;
if ( F_108 ( V_91 , V_23 -> V_30 ) < 0 )
goto V_245;
if ( V_23 -> V_42 &&
F_107 ( V_91 , V_252 , V_23 -> V_42 ) )
goto V_245;
if ( V_23 -> V_58 == 1 ) {
struct V_185 * V_186 ;
if ( V_23 -> V_5 -> V_48 &&
F_107 ( V_91 , V_137 , V_23 -> V_5 -> V_48 ) )
goto V_245;
if ( V_23 -> V_5 -> V_47 &&
F_106 ( V_91 , V_253 , V_23 -> V_5 -> V_47 ) )
goto V_245;
if ( V_23 -> V_5 -> V_51 & V_169 ) {
V_186 = F_109 ( V_23 -> V_5 -> V_26 ) ;
if ( V_186 &&
F_110 ( V_186 ) )
V_237 -> V_247 |= V_74 ;
}
#ifdef F_18
if ( V_23 -> V_5 [ 0 ] . V_35 &&
F_106 ( V_91 , V_138 , V_23 -> V_5 [ 0 ] . V_35 ) )
goto V_245;
#endif
if ( V_23 -> V_5 -> V_27 )
F_111 ( V_91 , V_23 -> V_5 -> V_27 ) ;
}
#ifdef F_27
if ( V_23 -> V_58 > 1 ) {
struct V_80 * V_120 ;
struct V_134 * V_254 ;
V_254 = F_112 ( V_91 , V_255 ) ;
if ( ! V_254 )
goto V_245;
F_26 (fi) {
struct V_185 * V_186 ;
V_120 = F_113 ( V_91 , sizeof( * V_120 ) ) ;
if ( ! V_120 )
goto V_245;
V_120 -> V_131 = V_6 -> V_51 & 0xFF ;
if ( V_6 -> V_51 & V_169 ) {
V_186 = F_109 ( V_6 -> V_26 ) ;
if ( V_186 &&
F_110 ( V_186 ) )
V_120 -> V_131 |= V_74 ;
}
V_120 -> V_133 = V_6 -> V_50 - 1 ;
V_120 -> V_132 = V_6 -> V_47 ;
if ( V_6 -> V_48 &&
F_107 ( V_91 , V_137 , V_6 -> V_48 ) )
goto V_245;
#ifdef F_18
if ( V_6 -> V_35 &&
F_106 ( V_91 , V_138 , V_6 -> V_35 ) )
goto V_245;
#endif
if ( V_6 -> V_27 )
F_111 ( V_91 , V_6 -> V_27 ) ;
V_120 -> V_256 = F_114 ( V_91 ) - ( void * ) V_120 ;
} F_15 ( V_23 ) ;
F_115 ( V_91 , V_254 ) ;
}
#endif
F_116 ( V_91 , V_93 ) ;
return 0 ;
V_245:
F_117 ( V_91 , V_93 ) ;
return - V_103 ;
}
int F_118 ( struct V_125 * V_125 , T_3 V_257 )
{
int V_127 = 0 ;
unsigned int V_8 = F_79 ( V_257 ) ;
struct V_64 * V_21 = & V_198 [ V_8 ] ;
struct V_22 * V_23 ;
if ( ! V_198 || V_257 == 0 )
return 0 ;
F_32 (fi, head, fib_lhash) {
if ( ! F_33 ( V_23 -> V_36 , V_125 ) )
continue;
if ( V_23 -> V_42 == V_257 ) {
V_23 -> V_68 |= V_74 ;
V_127 ++ ;
}
}
return V_127 ;
}
int F_119 ( struct V_70 * V_71 , unsigned long V_81 )
{
int V_127 = 0 ;
int V_184 = V_232 ;
struct V_22 * V_258 = NULL ;
unsigned int V_8 = F_29 ( V_71 -> V_72 ) ;
struct V_64 * V_21 = & V_73 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_81 == V_259 ||
V_81 == V_260 )
V_184 = - 1 ;
F_32 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_205 ;
int V_261 ;
F_120 ( ! V_23 -> V_58 ) ;
if ( V_6 -> V_26 != V_71 || V_23 == V_258 )
continue;
V_258 = V_23 ;
V_261 = 0 ;
F_12 (fi) {
if ( V_25 -> V_51 & V_74 )
V_261 ++ ;
else if ( V_25 -> V_26 == V_71 &&
V_25 -> V_49 != V_184 ) {
switch ( V_81 ) {
case V_260 :
case V_259 :
V_25 -> V_51 |= V_74 ;
case V_262 :
V_25 -> V_51 |= V_169 ;
break;
}
#ifdef F_27
F_21 ( & V_263 ) ;
V_23 -> V_264 -= V_25 -> V_265 ;
V_25 -> V_265 = 0 ;
F_24 ( & V_263 ) ;
#endif
V_261 ++ ;
}
#ifdef F_27
if ( V_81 == V_259 &&
V_25 -> V_26 == V_71 ) {
V_261 = V_23 -> V_58 ;
break;
}
#endif
} F_15 (fi)
if ( V_261 == V_23 -> V_58 ) {
switch ( V_81 ) {
case V_260 :
case V_259 :
V_23 -> V_68 |= V_74 ;
case V_262 :
V_23 -> V_68 |= V_169 ;
break;
}
V_127 ++ ;
}
}
return V_127 ;
}
void F_121 ( const struct V_172 * V_266 , struct V_158 * V_159 )
{
struct V_22 * V_23 = NULL , * V_107 = NULL ;
struct V_64 * V_267 = V_159 -> V_267 ;
struct V_170 * V_268 = V_159 -> V_269 ;
T_6 V_270 = 32 - V_159 -> V_271 ;
int V_106 = - 1 , V_108 = - 1 ;
struct V_83 * V_84 , * V_272 = NULL ;
V_31 V_273 = V_159 -> V_23 -> V_62 ;
T_6 V_274 = 0 ;
F_122 (fa, fa_head, fa_list) {
struct V_22 * V_275 = V_84 -> V_97 ;
if ( V_84 -> V_276 != V_270 )
continue;
if ( V_84 -> V_102 && V_84 -> V_102 != V_266 -> V_277 )
continue;
if ( V_84 -> V_86 != V_268 -> V_86 )
continue;
if ( V_275 -> V_62 > V_273 &&
V_84 -> V_102 == V_274 ) {
if ( V_274 )
continue;
break;
}
if ( V_275 -> V_68 & V_74 )
continue;
V_274 = V_84 -> V_102 ;
V_273 = V_275 -> V_62 ;
if ( V_275 -> V_60 != V_159 -> V_184 ||
V_84 -> V_101 != V_168 )
continue;
if ( ! V_275 -> V_5 [ 0 ] . V_48 ||
V_275 -> V_5 [ 0 ] . V_49 != V_163 )
continue;
F_123 ( V_84 ) ;
if ( ! V_23 ) {
if ( V_275 != V_159 -> V_23 )
break;
V_272 = V_84 ;
} else if ( ! F_48 ( V_23 , V_106 , & V_107 ,
& V_108 , V_272 -> V_278 ) ) {
F_124 ( V_159 , V_23 ) ;
V_272 -> V_278 = V_106 ;
goto V_183;
}
V_23 = V_275 ;
V_106 ++ ;
}
if ( V_106 <= 0 || ! V_23 ) {
if ( V_272 )
V_272 -> V_278 = - 1 ;
goto V_183;
}
if ( ! F_48 ( V_23 , V_106 , & V_107 , & V_108 ,
V_272 -> V_278 ) ) {
F_124 ( V_159 , V_23 ) ;
V_272 -> V_278 = V_106 ;
goto V_183;
}
if ( V_108 >= 0 )
F_124 ( V_159 , V_107 ) ;
V_272 -> V_278 = V_108 ;
V_183:
return;
}
int F_125 ( struct V_70 * V_71 , unsigned int V_51 )
{
struct V_22 * V_258 ;
unsigned int V_8 ;
struct V_64 * V_21 ;
struct V_5 * V_6 ;
int V_127 ;
if ( ! ( V_71 -> V_165 & V_166 ) )
return 0 ;
V_258 = NULL ;
V_8 = F_29 ( V_71 -> V_72 ) ;
V_21 = & V_73 [ V_8 ] ;
V_127 = 0 ;
F_32 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_205 ;
int V_279 ;
F_120 ( ! V_23 -> V_58 ) ;
if ( V_6 -> V_26 != V_71 || V_23 == V_258 )
continue;
V_258 = V_23 ;
V_279 = 0 ;
F_12 (fi) {
if ( ! ( V_25 -> V_51 & V_51 ) ) {
V_279 ++ ;
continue;
}
if ( ! V_25 -> V_26 ||
! ( V_25 -> V_26 -> V_165 & V_166 ) )
continue;
if ( V_25 -> V_26 != V_71 ||
! F_109 ( V_71 ) )
continue;
V_279 ++ ;
#ifdef F_27
F_21 ( & V_263 ) ;
V_25 -> V_265 = 0 ;
V_25 -> V_51 &= ~ V_51 ;
F_24 ( & V_263 ) ;
#else
V_25 -> V_51 &= ~ V_51 ;
#endif
} F_15 (fi)
if ( V_279 > 0 ) {
V_23 -> V_68 &= ~ V_51 ;
V_127 ++ ;
}
}
return V_127 ;
}
void F_126 ( struct V_158 * V_159 )
{
struct V_22 * V_23 = V_159 -> V_23 ;
struct V_185 * V_186 ;
int V_280 ;
F_21 ( & V_263 ) ;
if ( V_23 -> V_264 <= 0 ) {
int V_281 = 0 ;
F_12 (fi) {
V_186 = F_127 ( V_25 -> V_26 ) ;
if ( V_25 -> V_51 & V_74 )
continue;
if ( V_186 &&
F_110 ( V_186 ) &&
V_25 -> V_51 & V_169 )
continue;
V_281 += V_25 -> V_50 ;
V_25 -> V_265 = V_25 -> V_50 ;
} F_15 ( V_23 ) ;
V_23 -> V_264 = V_281 ;
if ( V_281 <= 0 ) {
F_24 ( & V_263 ) ;
V_159 -> V_282 = 0 ;
return;
}
}
V_280 = V_283 % V_23 -> V_264 ;
F_12 (fi) {
if ( ! ( V_25 -> V_51 & V_74 ) &&
V_25 -> V_265 ) {
V_280 -= V_25 -> V_265 ;
if ( V_280 <= 0 ) {
V_25 -> V_265 -- ;
V_23 -> V_264 -- ;
V_159 -> V_282 = V_284 ;
F_24 ( & V_263 ) ;
return;
}
}
} F_15 ( V_23 ) ;
V_159 -> V_282 = 0 ;
F_24 ( & V_263 ) ;
}
