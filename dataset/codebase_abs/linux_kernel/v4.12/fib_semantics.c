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
struct V_25 * V_26 ;
F_12 (fi) {
if ( V_27 -> V_28 )
F_13 ( V_27 -> V_28 ) ;
F_14 ( V_27 -> V_29 ) ;
F_4 ( V_27 ) ;
F_6 ( V_27 -> V_30 ) ;
F_1 ( & V_27 -> V_31 ) ;
} F_15 ( V_23 ) ;
V_26 = V_23 -> V_32 ;
if ( V_26 != & V_33 && F_16 ( & V_26 -> V_34 ) )
F_5 ( V_26 ) ;
F_5 ( V_23 ) ;
}
void F_17 ( struct V_22 * V_23 )
{
if ( V_23 -> V_35 == 0 ) {
F_18 ( L_1 , V_23 ) ;
return;
}
V_36 -- ;
#ifdef F_19
F_12 (fi) {
if ( V_27 -> V_37 )
V_23 -> V_38 -> V_39 . V_40 -- ;
} F_15 ( V_23 ) ;
#endif
F_20 ( & V_23 -> V_24 , F_10 ) ;
}
void F_21 ( struct V_22 * V_23 )
{
F_22 ( & V_41 ) ;
if ( V_23 && -- V_23 -> V_42 == 0 ) {
F_23 ( & V_23 -> V_43 ) ;
if ( V_23 -> V_44 )
F_23 ( & V_23 -> V_45 ) ;
F_12 (fi) {
if ( ! V_27 -> V_28 )
continue;
F_23 ( & V_27 -> V_46 ) ;
} F_15 (fi)
V_23 -> V_35 = 1 ;
F_24 ( V_23 ) ;
}
F_25 ( & V_41 ) ;
}
static inline int F_26 ( const struct V_22 * V_23 , const struct V_22 * V_47 )
{
const struct V_5 * V_48 = V_47 -> V_5 ;
F_27 (fi) {
if ( V_6 -> V_49 != V_48 -> V_49 ||
V_6 -> V_50 != V_48 -> V_50 ||
V_6 -> V_51 != V_48 -> V_51 ||
#ifdef F_28
V_6 -> V_52 != V_48 -> V_52 ||
#endif
#ifdef F_19
V_6 -> V_37 != V_48 -> V_37 ||
#endif
F_29 ( V_6 -> V_29 , V_48 -> V_29 ) ||
( ( V_6 -> V_53 ^ V_48 -> V_53 ) & ~ V_54 ) )
return - 1 ;
V_48 ++ ;
} F_15 ( V_23 ) ;
return 0 ;
}
static inline unsigned int F_30 ( unsigned int V_55 )
{
unsigned int V_56 = V_57 - 1 ;
return ( V_55 ^
( V_55 >> V_58 ) ^
( V_55 >> ( V_58 * 2 ) ) ) & V_56 ;
}
static inline unsigned int F_31 ( const struct V_22 * V_23 )
{
unsigned int V_56 = ( V_59 - 1 ) ;
unsigned int V_55 = V_23 -> V_60 ;
V_55 ^= ( V_23 -> V_61 << 8 ) | V_23 -> V_62 ;
V_55 ^= ( V_63 V_64 ) V_23 -> V_44 ;
V_55 ^= V_23 -> V_65 ;
F_27 (fi) {
V_55 ^= F_30 ( V_6 -> V_49 ) ;
} F_15 (fi)
return ( V_55 ^ ( V_55 >> 7 ) ^ ( V_55 >> 12 ) ) & V_56 ;
}
static struct V_22 * F_32 ( const struct V_22 * V_66 )
{
struct V_67 * V_21 ;
struct V_22 * V_23 ;
unsigned int V_8 ;
V_8 = F_31 ( V_66 ) ;
V_21 = & V_68 [ V_8 ] ;
F_33 (fi, head, fib_hash) {
if ( ! F_34 ( V_23 -> V_38 , V_66 -> V_38 ) )
continue;
if ( V_23 -> V_60 != V_66 -> V_60 )
continue;
if ( V_66 -> V_61 == V_23 -> V_61 &&
V_66 -> V_62 == V_23 -> V_62 &&
V_66 -> V_44 == V_23 -> V_44 &&
V_66 -> V_65 == V_23 -> V_65 &&
V_66 -> V_69 == V_23 -> V_69 &&
memcmp ( V_66 -> V_32 , V_23 -> V_32 ,
sizeof( V_64 ) * V_70 ) == 0 &&
! ( ( V_66 -> V_71 ^ V_23 -> V_71 ) & ~ V_54 ) &&
( V_66 -> V_60 == 0 || F_26 ( V_23 , V_66 ) == 0 ) )
return V_23 ;
}
return NULL ;
}
int F_35 ( T_3 V_72 , struct V_73 * V_74 )
{
struct V_67 * V_21 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_36 ( & V_41 ) ;
V_8 = F_30 ( V_74 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
F_33 (nh, head, nh_hash) {
if ( V_6 -> V_28 == V_74 &&
V_6 -> V_50 == V_72 &&
! ( V_6 -> V_53 & V_77 ) ) {
F_37 ( & V_41 ) ;
return 0 ;
}
}
F_37 ( & V_41 ) ;
return - 1 ;
}
static inline T_4 F_38 ( struct V_22 * V_23 )
{
T_4 V_78 = F_39 ( sizeof( struct V_79 ) )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( V_80 ) ;
V_78 += F_40 ( ( V_70 * F_40 ( 4 ) ) ) ;
if ( V_23 -> V_60 ) {
T_4 V_81 = 0 ;
T_4 V_82 = F_40 ( sizeof( struct V_83 ) ) ;
V_82 += 2 * F_40 ( 4 ) ;
F_27 (fi) {
if ( V_6 -> V_29 ) {
V_81 += F_41 (
V_6 -> V_29 ) ;
V_81 += F_40 ( 2 ) ;
}
} F_15 ( V_23 ) ;
V_78 += F_40 ( ( V_23 -> V_60 * V_82 ) +
V_81 ) ;
}
return V_78 ;
}
void F_42 ( int V_84 , T_3 V_85 , struct V_86 * V_87 ,
int V_88 , V_64 V_89 , const struct V_90 * V_91 ,
unsigned int V_92 )
{
struct V_93 * V_94 ;
V_64 V_95 = V_91 -> V_96 ? V_91 -> V_96 -> V_97 : 0 ;
int V_98 = - V_99 ;
V_94 = F_43 ( F_38 ( V_87 -> V_100 ) , V_101 ) ;
if ( ! V_94 )
goto V_102;
V_98 = F_44 ( V_94 , V_91 -> V_103 , V_95 , V_84 , V_89 ,
V_87 -> V_104 , V_85 , V_88 ,
V_87 -> V_105 , V_87 -> V_100 , V_92 ) ;
if ( V_98 < 0 ) {
F_45 ( V_98 == - V_106 ) ;
F_46 ( V_94 ) ;
goto V_102;
}
F_47 ( V_94 , V_91 -> V_107 , V_91 -> V_103 , V_108 ,
V_91 -> V_96 , V_101 ) ;
return;
V_102:
if ( V_98 < 0 )
F_48 ( V_91 -> V_107 , V_108 , V_98 ) ;
}
static int F_49 ( struct V_22 * V_23 , int V_109 ,
struct V_22 * * V_110 , int * V_111 ,
int V_112 )
{
struct V_113 * V_114 ;
int V_115 = V_116 ;
V_114 = F_50 ( & V_117 , & V_23 -> V_5 [ 0 ] . V_50 , V_23 -> V_118 ) ;
if ( V_114 ) {
V_115 = V_114 -> V_119 ;
F_51 ( V_114 ) ;
} else {
return 0 ;
}
if ( V_115 == V_120 )
return 0 ;
if ( ( V_115 & V_121 ) && V_109 != V_112 )
return 0 ;
if ( ( V_115 & V_121 ) ||
( * V_111 < 0 && V_109 > V_112 && V_115 != V_122 ) ) {
* V_110 = V_23 ;
* V_111 = V_109 ;
}
return 1 ;
}
static int F_52 ( struct V_83 * V_123 , int V_124 )
{
int V_125 = 0 ;
while ( F_53 ( V_123 , V_124 ) ) {
V_125 ++ ;
V_123 = F_54 ( V_123 , & V_124 ) ;
}
return V_124 > 0 ? 0 : V_125 ;
}
static int F_55 ( struct V_22 * V_23 , struct V_83 * V_123 ,
int V_124 , struct V_126 * V_127 )
{
int V_128 ;
F_12 (fi) {
int V_129 ;
if ( ! F_53 ( V_123 , V_124 ) )
return - V_130 ;
if ( V_123 -> V_131 & ( V_77 | V_132 ) )
return - V_130 ;
V_27 -> V_53 =
( V_127 -> V_133 & ~ 0xFF ) | V_123 -> V_131 ;
V_27 -> V_49 = V_123 -> V_134 ;
V_27 -> V_52 = V_123 -> V_135 + 1 ;
V_129 = F_56 ( V_123 ) ;
if ( V_129 > 0 ) {
struct V_136 * V_137 , * V_138 = F_57 ( V_123 ) ;
V_137 = F_58 ( V_138 , V_129 , V_139 ) ;
V_27 -> V_50 = V_137 ? F_59 ( V_137 ) : 0 ;
#ifdef F_19
V_137 = F_58 ( V_138 , V_129 , V_140 ) ;
V_27 -> V_37 = V_137 ? F_60 ( V_137 ) : 0 ;
if ( V_27 -> V_37 )
V_23 -> V_38 -> V_39 . V_40 ++ ;
#endif
V_137 = F_58 ( V_138 , V_129 , V_141 ) ;
if ( V_137 ) {
struct V_142 * V_143 ;
struct V_136 * V_144 ;
V_144 = F_58 ( V_138 , V_129 ,
V_145 ) ;
if ( ! V_144 )
goto V_146;
V_128 = F_61 ( F_62 (
V_144 ) ,
V_137 , V_147 , V_127 ,
& V_143 ) ;
if ( V_128 )
goto V_102;
V_27 -> V_29 =
F_63 ( V_143 ) ;
}
}
V_123 = F_54 ( V_123 , & V_124 ) ;
} F_15 ( V_23 ) ;
return 0 ;
V_146:
V_128 = - V_130 ;
V_102:
return V_128 ;
}
static void F_64 ( struct V_22 * V_23 )
{
int V_148 ;
int V_149 ;
struct V_150 * V_151 ;
if ( V_23 -> V_60 < 2 )
return;
V_148 = 0 ;
F_27 (fi) {
if ( V_6 -> V_53 & V_77 )
continue;
V_151 = F_65 ( V_6 -> V_28 ) ;
if ( V_151 &&
F_66 ( V_151 ) &&
V_6 -> V_53 & V_132 )
continue;
V_148 += V_6 -> V_52 ;
} F_15 ( V_23 ) ;
V_149 = 0 ;
F_12 (fi) {
int V_152 ;
V_151 = F_65 ( V_27 -> V_28 ) ;
if ( V_27 -> V_53 & V_77 ) {
V_152 = - 1 ;
} else if ( V_151 &&
F_66 ( V_151 ) &&
V_27 -> V_53 & V_132 ) {
V_152 = - 1 ;
} else {
V_149 += V_27 -> V_52 ;
V_152 = F_67 ( ( V_153 ) V_149 << 31 ,
V_148 ) - 1 ;
}
F_68 ( & V_27 -> V_154 , V_152 ) ;
} F_15 ( V_23 ) ;
}
static inline void F_69 ( struct V_22 * V_23 ,
const struct V_5 * V_6 )
{
V_23 -> V_155 += V_6 -> V_52 ;
}
static int F_70 ( T_5 V_156 ,
struct V_136 * V_157 ,
const struct V_5 * V_6 ,
const struct V_126 * V_127 )
{
struct V_142 * V_143 ;
int V_128 , V_158 = 0 ;
if ( V_156 == V_159 )
return 0 ;
V_128 = F_61 ( V_156 , V_157 ,
V_147 , V_127 , & V_143 ) ;
if ( ! V_128 ) {
V_158 = F_29 ( V_143 , V_6 -> V_29 ) ;
F_71 ( V_143 ) ;
}
return V_158 ;
}
int F_72 ( struct V_126 * V_127 , struct V_22 * V_23 )
{
#ifdef F_28
struct V_83 * V_123 ;
int V_124 ;
#endif
if ( V_127 -> V_160 && V_127 -> V_160 != V_23 -> V_65 )
return 1 ;
if ( V_127 -> V_161 || V_127 -> V_162 ) {
if ( V_127 -> V_163 ) {
if ( F_70 ( V_127 -> V_164 ,
V_127 -> V_163 , V_23 -> V_5 , V_127 ) )
return 1 ;
}
if ( ( ! V_127 -> V_161 || V_127 -> V_161 == V_23 -> V_5 -> V_49 ) &&
( ! V_127 -> V_162 || V_127 -> V_162 == V_23 -> V_5 -> V_50 ) )
return 0 ;
return 1 ;
}
#ifdef F_28
if ( ! V_127 -> V_165 )
return 0 ;
V_123 = V_127 -> V_165 ;
V_124 = V_127 -> V_166 ;
F_27 (fi) {
int V_129 ;
if ( ! F_53 ( V_123 , V_124 ) )
return - V_130 ;
if ( V_123 -> V_134 && V_123 -> V_134 != V_6 -> V_49 )
return 1 ;
V_129 = F_56 ( V_123 ) ;
if ( V_129 > 0 ) {
struct V_136 * V_137 , * V_138 = F_57 ( V_123 ) ;
V_137 = F_58 ( V_138 , V_129 , V_139 ) ;
if ( V_137 && F_59 ( V_137 ) != V_6 -> V_50 )
return 1 ;
#ifdef F_19
V_137 = F_58 ( V_138 , V_129 , V_140 ) ;
if ( V_137 && F_60 ( V_137 ) != V_6 -> V_37 )
return 1 ;
#endif
}
V_123 = F_54 ( V_123 , & V_124 ) ;
} F_15 ( V_23 ) ;
#endif
return 0 ;
}
static int F_73 ( struct V_126 * V_127 , struct V_22 * V_23 ,
struct V_5 * V_6 )
{
int V_98 = 0 ;
struct V_167 * V_167 ;
struct V_73 * V_74 ;
V_167 = V_127 -> V_168 . V_107 ;
if ( V_6 -> V_50 ) {
struct V_169 V_170 ;
if ( V_6 -> V_53 & V_171 ) {
unsigned int V_172 ;
if ( V_127 -> V_173 >= V_174 )
return - V_130 ;
V_74 = F_74 ( V_167 , V_6 -> V_49 ) ;
if ( ! V_74 )
return - V_175 ;
if ( ! ( V_74 -> V_176 & V_177 ) )
return - V_178 ;
V_172 = F_75 ( V_167 , V_74 , V_6 -> V_50 ) ;
if ( V_172 != V_179 )
return - V_130 ;
if ( ! F_76 ( V_74 ) )
V_6 -> V_53 |= V_132 ;
V_6 -> V_28 = V_74 ;
F_77 ( V_74 ) ;
V_6 -> V_51 = V_174 ;
return 0 ;
}
F_78 () ;
{
struct V_180 * V_181 = NULL ;
struct V_182 V_183 = {
. V_184 = V_6 -> V_50 ,
. V_185 = V_127 -> V_173 + 1 ,
. V_186 = V_6 -> V_49 ,
. V_187 = V_188 ,
} ;
if ( V_183 . V_185 < V_174 )
V_183 . V_185 = V_174 ;
if ( V_127 -> V_189 )
V_181 = F_79 ( V_167 , V_127 -> V_189 ) ;
if ( V_181 )
V_98 = F_80 ( V_181 , & V_183 , & V_170 ,
V_190 |
V_191 ) ;
if ( ! V_181 || V_98 ) {
V_98 = F_81 ( V_167 , & V_183 , & V_170 ,
V_190 ) ;
}
if ( V_98 ) {
F_82 () ;
return V_98 ;
}
}
V_98 = - V_130 ;
if ( V_170 . type != V_179 && V_170 . type != V_192 )
goto V_193;
V_6 -> V_51 = V_170 . V_194 ;
V_6 -> V_49 = F_83 ( V_170 ) ;
V_6 -> V_28 = V_74 = F_84 ( V_170 ) ;
if ( ! V_74 )
goto V_193;
F_77 ( V_74 ) ;
if ( ! F_76 ( V_74 ) )
V_6 -> V_53 |= V_132 ;
V_98 = ( V_74 -> V_176 & V_177 ) ? 0 : - V_178 ;
} else {
struct V_150 * V_151 ;
if ( V_6 -> V_53 & ( V_195 | V_171 ) )
return - V_130 ;
F_78 () ;
V_98 = - V_175 ;
V_151 = F_85 ( V_167 , V_6 -> V_49 ) ;
if ( ! V_151 )
goto V_193;
V_98 = - V_178 ;
if ( ! ( V_151 -> V_74 -> V_176 & V_177 ) )
goto V_193;
V_6 -> V_28 = V_151 -> V_74 ;
F_77 ( V_6 -> V_28 ) ;
V_6 -> V_51 = V_196 ;
if ( ! F_76 ( V_6 -> V_28 ) )
V_6 -> V_53 |= V_132 ;
V_98 = 0 ;
}
V_193:
F_82 () ;
return V_98 ;
}
static inline unsigned int F_86 ( T_3 V_55 )
{
unsigned int V_56 = ( V_59 - 1 ) ;
return ( ( V_63 V_64 ) V_55 ^
( ( V_63 V_64 ) V_55 >> 7 ) ^
( ( V_63 V_64 ) V_55 >> 14 ) ) & V_56 ;
}
static struct V_67 * F_87 ( int V_197 )
{
if ( V_197 <= V_198 )
return F_88 ( V_197 , V_101 ) ;
else
return (struct V_67 * )
F_89 ( V_101 | V_199 ,
F_90 ( V_197 ) ) ;
}
static void F_91 ( struct V_67 * V_8 , int V_197 )
{
if ( ! V_8 )
return;
if ( V_197 <= V_198 )
F_5 ( V_8 ) ;
else
F_92 ( ( unsigned long ) V_8 , F_90 ( V_197 ) ) ;
}
static void F_93 ( struct V_67 * V_200 ,
struct V_67 * V_201 ,
unsigned int V_202 )
{
struct V_67 * V_203 , * V_204 ;
unsigned int V_205 = V_59 ;
unsigned int V_9 , V_197 ;
F_22 ( & V_41 ) ;
V_203 = V_68 ;
V_204 = V_206 ;
V_59 = V_202 ;
for ( V_9 = 0 ; V_9 < V_205 ; V_9 ++ ) {
struct V_67 * V_21 = & V_68 [ V_9 ] ;
struct V_207 * V_114 ;
struct V_22 * V_23 ;
F_94 (fi, n, head, fib_hash) {
struct V_67 * V_208 ;
unsigned int V_209 ;
V_209 = F_31 ( V_23 ) ;
V_208 = & V_200 [ V_209 ] ;
F_95 ( & V_23 -> V_43 , V_208 ) ;
}
}
V_68 = V_200 ;
for ( V_9 = 0 ; V_9 < V_205 ; V_9 ++ ) {
struct V_67 * V_210 = & V_206 [ V_9 ] ;
struct V_207 * V_114 ;
struct V_22 * V_23 ;
F_94 (fi, n, lhead, fib_lhash) {
struct V_67 * V_211 ;
unsigned int V_209 ;
V_209 = F_86 ( V_23 -> V_44 ) ;
V_211 = & V_201 [ V_209 ] ;
F_95 ( & V_23 -> V_45 , V_211 ) ;
}
}
V_206 = V_201 ;
F_25 ( & V_41 ) ;
V_197 = V_205 * sizeof( struct V_67 * ) ;
F_91 ( V_203 , V_197 ) ;
F_91 ( V_204 , V_197 ) ;
}
T_3 F_96 ( struct V_167 * V_167 , struct V_5 * V_6 )
{
V_6 -> V_212 = F_97 ( V_6 -> V_28 ,
V_6 -> V_50 ,
V_6 -> V_213 -> V_62 ) ;
V_6 -> V_214 = F_98 ( & V_167 -> V_39 . V_215 ) ;
return V_6 -> V_212 ;
}
static bool F_99 ( struct V_126 * V_127 , T_3 V_44 )
{
if ( V_127 -> V_216 != V_192 || ! V_127 -> V_217 ||
V_44 != V_127 -> V_217 ) {
V_64 V_89 = V_127 -> V_189 ;
int V_218 ;
if ( V_89 == V_219 )
V_89 = V_220 ;
V_218 = F_100 ( V_127 -> V_168 . V_107 ,
V_44 , V_89 ) ;
if ( V_218 != V_192 && V_89 != V_220 ) {
V_218 = F_100 ( V_127 -> V_168 . V_107 ,
V_44 , V_220 ) ;
}
if ( V_218 != V_192 )
return false ;
}
return true ;
}
static int
F_101 ( struct V_22 * V_23 , const struct V_126 * V_127 )
{
bool V_221 = false ;
struct V_136 * V_137 ;
int V_124 ;
if ( ! V_127 -> V_222 )
return 0 ;
F_102 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_103 ( V_137 ) ;
V_64 V_55 ;
if ( ! type )
continue;
if ( type > V_70 )
return - V_130 ;
if ( type == V_223 ) {
char V_224 [ V_80 ] ;
F_104 ( V_224 , V_137 , sizeof( V_224 ) ) ;
V_55 = F_105 ( V_224 , & V_221 ) ;
if ( V_55 == V_225 )
return - V_130 ;
} else {
V_55 = F_60 ( V_137 ) ;
}
if ( type == V_226 && V_55 > 65535 - 40 )
V_55 = 65535 - 40 ;
if ( type == V_227 && V_55 > 65535 - 15 )
V_55 = 65535 - 15 ;
if ( type == V_228 && V_55 > 255 )
V_55 = 255 ;
if ( type == V_229 && ( V_55 & ~ V_230 ) )
return - V_130 ;
V_23 -> V_32 -> V_231 [ type - 1 ] = V_55 ;
}
if ( V_221 )
V_23 -> V_32 -> V_231 [ V_229 - 1 ] |= V_232 ;
return 0 ;
}
struct V_22 * F_106 ( struct V_126 * V_127 )
{
int V_98 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_47 ;
int V_125 = 1 ;
struct V_167 * V_167 = V_127 -> V_168 . V_107 ;
if ( V_127 -> V_216 > V_233 )
goto V_146;
if ( V_234 [ V_127 -> V_216 ] . V_194 > V_127 -> V_173 )
goto V_146;
if ( V_127 -> V_133 & ( V_77 | V_132 ) )
goto V_146;
#ifdef F_28
if ( V_127 -> V_165 ) {
V_125 = F_52 ( V_127 -> V_165 , V_127 -> V_166 ) ;
if ( V_125 == 0 )
goto V_146;
}
#endif
V_98 = - V_99 ;
if ( V_36 >= V_59 ) {
unsigned int V_202 = V_59 << 1 ;
struct V_67 * V_200 ;
struct V_67 * V_201 ;
unsigned int V_197 ;
if ( ! V_202 )
V_202 = 16 ;
V_197 = V_202 * sizeof( struct V_67 * ) ;
V_200 = F_87 ( V_197 ) ;
V_201 = F_87 ( V_197 ) ;
if ( ! V_200 || ! V_201 ) {
F_91 ( V_200 , V_197 ) ;
F_91 ( V_201 , V_197 ) ;
} else
F_93 ( V_200 , V_201 , V_202 ) ;
if ( ! V_59 )
goto V_235;
}
V_23 = F_88 ( sizeof( * V_23 ) + V_125 * sizeof( struct V_5 ) , V_101 ) ;
if ( ! V_23 )
goto V_235;
V_36 ++ ;
if ( V_127 -> V_222 ) {
V_23 -> V_32 = F_88 ( sizeof( * V_23 -> V_32 ) , V_101 ) ;
if ( ! V_23 -> V_32 )
goto V_235;
F_68 ( & V_23 -> V_32 -> V_34 , 1 ) ;
} else
V_23 -> V_32 = (struct V_25 * ) & V_33 ;
V_23 -> V_38 = V_167 ;
V_23 -> V_61 = V_127 -> V_236 ;
V_23 -> V_62 = V_127 -> V_173 ;
V_23 -> V_71 = V_127 -> V_133 ;
V_23 -> V_65 = V_127 -> V_160 ;
V_23 -> V_44 = V_127 -> V_237 ;
V_23 -> V_69 = V_127 -> V_216 ;
V_23 -> V_238 = V_127 -> V_189 ;
V_23 -> V_60 = V_125 ;
F_12 (fi) {
V_27 -> V_213 = V_23 ;
V_27 -> V_30 = F_107 (struct rtable __rcu *) ;
if ( ! V_27 -> V_30 )
goto V_235;
} F_15 (fi)
V_98 = F_101 ( V_23 , V_127 ) ;
if ( V_98 )
goto V_235;
if ( V_127 -> V_165 ) {
#ifdef F_28
V_98 = F_55 ( V_23 , V_127 -> V_165 , V_127 -> V_166 , V_127 ) ;
if ( V_98 != 0 )
goto V_235;
if ( V_127 -> V_161 && V_23 -> V_5 -> V_49 != V_127 -> V_161 )
goto V_146;
if ( V_127 -> V_162 && V_23 -> V_5 -> V_50 != V_127 -> V_162 )
goto V_146;
#ifdef F_19
if ( V_127 -> V_239 && V_23 -> V_5 -> V_37 != V_127 -> V_239 )
goto V_146;
#endif
#else
goto V_146;
#endif
} else {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_127 -> V_163 ) {
struct V_142 * V_143 ;
if ( V_127 -> V_164 == V_159 )
goto V_146;
V_98 = F_61 ( V_127 -> V_164 ,
V_127 -> V_163 , V_147 , V_127 ,
& V_143 ) ;
if ( V_98 )
goto V_235;
V_6 -> V_29 = F_63 ( V_143 ) ;
}
V_6 -> V_49 = V_127 -> V_161 ;
V_6 -> V_50 = V_127 -> V_162 ;
V_6 -> V_53 = V_127 -> V_133 ;
#ifdef F_19
V_6 -> V_37 = V_127 -> V_239 ;
if ( V_6 -> V_37 )
V_23 -> V_38 -> V_39 . V_40 ++ ;
#endif
#ifdef F_28
V_6 -> V_52 = 1 ;
#endif
}
if ( V_234 [ V_127 -> V_216 ] . error ) {
if ( V_127 -> V_162 || V_127 -> V_161 || V_127 -> V_165 )
goto V_146;
goto V_240;
} else {
switch ( V_127 -> V_216 ) {
case V_179 :
case V_192 :
case V_241 :
case V_242 :
case V_243 :
break;
default:
goto V_146;
}
}
if ( V_127 -> V_173 > V_196 )
goto V_146;
if ( V_127 -> V_173 == V_196 ) {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_125 != 1 || V_6 -> V_50 )
goto V_146;
V_6 -> V_51 = V_244 ;
V_6 -> V_28 = F_108 ( V_167 , V_23 -> V_5 -> V_49 ) ;
V_98 = - V_175 ;
if ( ! V_6 -> V_28 )
goto V_235;
} else {
int V_245 = 0 ;
F_12 (fi) {
V_98 = F_73 ( V_127 , V_23 , V_27 ) ;
if ( V_98 != 0 )
goto V_235;
if ( V_27 -> V_53 & V_132 )
V_245 ++ ;
} F_15 (fi)
if ( V_245 == V_23 -> V_60 )
V_23 -> V_71 |= V_132 ;
}
if ( V_23 -> V_44 && ! F_99 ( V_127 , V_23 -> V_44 ) )
goto V_146;
F_12 (fi) {
F_96 ( V_167 , V_27 ) ;
F_69 ( V_23 , V_27 ) ;
} F_15 (fi)
F_64 ( V_23 ) ;
V_240:
V_47 = F_32 ( V_23 ) ;
if ( V_47 ) {
V_23 -> V_35 = 1 ;
F_17 ( V_23 ) ;
V_47 -> V_42 ++ ;
return V_47 ;
}
V_23 -> V_42 ++ ;
F_109 ( & V_23 -> V_246 ) ;
F_22 ( & V_41 ) ;
F_95 ( & V_23 -> V_43 ,
& V_68 [ F_31 ( V_23 ) ] ) ;
if ( V_23 -> V_44 ) {
struct V_67 * V_21 ;
V_21 = & V_206 [ F_86 ( V_23 -> V_44 ) ] ;
F_95 ( & V_23 -> V_45 , V_21 ) ;
}
F_12 (fi) {
struct V_67 * V_21 ;
unsigned int V_8 ;
if ( ! V_27 -> V_28 )
continue;
V_8 = F_30 ( V_27 -> V_28 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
F_95 ( & V_27 -> V_46 , V_21 ) ;
} F_15 (fi)
F_25 ( & V_41 ) ;
return V_23 ;
V_146:
V_98 = - V_130 ;
V_235:
if ( V_23 ) {
V_23 -> V_35 = 1 ;
F_17 ( V_23 ) ;
}
return F_110 ( V_98 ) ;
}
int F_44 ( struct V_93 * V_94 , V_64 V_103 , V_64 V_95 , int V_84 ,
V_64 V_89 , T_6 type , T_3 V_4 , int V_88 , T_6 V_247 ,
struct V_22 * V_23 , unsigned int V_176 )
{
struct V_248 * V_96 ;
struct V_79 * V_249 ;
V_96 = F_111 ( V_94 , V_103 , V_95 , V_84 , sizeof( * V_249 ) , V_176 ) ;
if ( ! V_96 )
return - V_106 ;
V_249 = F_112 ( V_96 ) ;
V_249 -> V_250 = V_147 ;
V_249 -> V_251 = V_88 ;
V_249 -> V_252 = 0 ;
V_249 -> V_253 = V_247 ;
if ( V_89 < 256 )
V_249 -> V_254 = V_89 ;
else
V_249 -> V_254 = V_255 ;
if ( F_113 ( V_94 , V_256 , V_89 ) )
goto V_257;
V_249 -> V_258 = type ;
V_249 -> V_259 = V_23 -> V_71 ;
V_249 -> V_260 = V_23 -> V_62 ;
V_249 -> V_261 = V_23 -> V_61 ;
if ( V_249 -> V_251 &&
F_114 ( V_94 , V_262 , V_4 ) )
goto V_257;
if ( V_23 -> V_65 &&
F_113 ( V_94 , V_263 , V_23 -> V_65 ) )
goto V_257;
if ( F_115 ( V_94 , V_23 -> V_32 -> V_231 ) < 0 )
goto V_257;
if ( V_23 -> V_44 &&
F_114 ( V_94 , V_264 , V_23 -> V_44 ) )
goto V_257;
if ( V_23 -> V_60 == 1 ) {
struct V_150 * V_151 ;
if ( V_23 -> V_5 -> V_50 &&
F_114 ( V_94 , V_139 , V_23 -> V_5 -> V_50 ) )
goto V_257;
if ( V_23 -> V_5 -> V_49 &&
F_113 ( V_94 , V_265 , V_23 -> V_5 -> V_49 ) )
goto V_257;
if ( V_23 -> V_5 -> V_53 & V_132 ) {
V_151 = F_65 ( V_23 -> V_5 -> V_28 ) ;
if ( V_151 &&
F_66 ( V_151 ) )
V_249 -> V_259 |= V_77 ;
}
#ifdef F_19
if ( V_23 -> V_5 [ 0 ] . V_37 &&
F_113 ( V_94 , V_140 , V_23 -> V_5 [ 0 ] . V_37 ) )
goto V_257;
#endif
if ( V_23 -> V_5 -> V_29 &&
F_116 ( V_94 , V_23 -> V_5 -> V_29 ) < 0 )
goto V_257;
}
#ifdef F_28
if ( V_23 -> V_60 > 1 ) {
struct V_83 * V_123 ;
struct V_136 * V_266 ;
V_266 = F_117 ( V_94 , V_267 ) ;
if ( ! V_266 )
goto V_257;
F_27 (fi) {
struct V_150 * V_151 ;
V_123 = F_118 ( V_94 , sizeof( * V_123 ) ) ;
if ( ! V_123 )
goto V_257;
V_123 -> V_131 = V_6 -> V_53 & 0xFF ;
if ( V_6 -> V_53 & V_132 ) {
V_151 = F_65 ( V_6 -> V_28 ) ;
if ( V_151 &&
F_66 ( V_151 ) )
V_123 -> V_131 |= V_77 ;
}
V_123 -> V_135 = V_6 -> V_52 - 1 ;
V_123 -> V_134 = V_6 -> V_49 ;
if ( V_6 -> V_50 &&
F_114 ( V_94 , V_139 , V_6 -> V_50 ) )
goto V_257;
#ifdef F_19
if ( V_6 -> V_37 &&
F_113 ( V_94 , V_140 , V_6 -> V_37 ) )
goto V_257;
#endif
if ( V_6 -> V_29 &&
F_116 ( V_94 , V_6 -> V_29 ) < 0 )
goto V_257;
V_123 -> V_268 = F_119 ( V_94 ) - ( void * ) V_123 ;
} F_15 ( V_23 ) ;
F_120 ( V_94 , V_266 ) ;
}
#endif
F_121 ( V_94 , V_96 ) ;
return 0 ;
V_257:
F_122 ( V_94 , V_96 ) ;
return - V_106 ;
}
int F_123 ( struct V_73 * V_74 , T_3 V_269 )
{
int V_128 = 0 ;
unsigned int V_8 = F_86 ( V_269 ) ;
struct V_67 * V_21 = & V_206 [ V_8 ] ;
struct V_167 * V_167 = F_124 ( V_74 ) ;
int V_89 = F_125 ( V_74 ) ;
struct V_22 * V_23 ;
if ( ! V_206 || V_269 == 0 )
return 0 ;
F_33 (fi, head, fib_lhash) {
if ( ! F_34 ( V_23 -> V_38 , V_167 ) ||
V_23 -> V_238 != V_89 )
continue;
if ( V_23 -> V_44 == V_269 ) {
V_23 -> V_71 |= V_77 ;
V_128 ++ ;
}
}
return V_128 ;
}
static int F_126 ( struct V_5 * V_5 ,
enum V_270 V_271 )
{
struct V_150 * V_151 = F_65 ( V_5 -> V_28 ) ;
struct V_272 V_91 = {
. V_5 = V_5 ,
} ;
switch ( V_271 ) {
case V_273 :
if ( V_5 -> V_53 & V_77 )
break;
if ( F_66 ( V_151 ) &&
V_5 -> V_53 & V_132 )
break;
return F_127 ( F_124 ( V_5 -> V_28 ) , V_271 ,
& V_91 . V_91 ) ;
case V_274 :
if ( ( F_66 ( V_151 ) &&
V_5 -> V_53 & V_132 ) ||
( V_5 -> V_53 & V_77 ) )
return F_127 ( F_124 ( V_5 -> V_28 ) ,
V_271 , & V_91 . V_91 ) ;
default:
break;
}
return V_275 ;
}
int F_128 ( struct V_73 * V_74 , unsigned long V_84 , bool V_276 )
{
int V_128 = 0 ;
int V_194 = V_244 ;
struct V_22 * V_277 = NULL ;
unsigned int V_8 = F_30 ( V_74 -> V_75 ) ;
struct V_67 * V_21 = & V_76 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_276 )
V_194 = - 1 ;
F_33 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_213 ;
int V_278 ;
F_129 ( ! V_23 -> V_60 ) ;
if ( V_6 -> V_28 != V_74 || V_23 == V_277 )
continue;
V_277 = V_23 ;
V_278 = 0 ;
F_12 (fi) {
if ( V_27 -> V_53 & V_77 )
V_278 ++ ;
else if ( V_27 -> V_28 == V_74 &&
V_27 -> V_51 != V_194 ) {
switch ( V_84 ) {
case V_279 :
case V_280 :
V_27 -> V_53 |= V_77 ;
case V_281 :
V_27 -> V_53 |= V_132 ;
break;
}
F_126 ( V_27 ,
V_274 ) ;
V_278 ++ ;
}
#ifdef F_28
if ( V_84 == V_280 &&
V_27 -> V_28 == V_74 ) {
V_278 = V_23 -> V_60 ;
break;
}
#endif
} F_15 (fi)
if ( V_278 == V_23 -> V_60 ) {
switch ( V_84 ) {
case V_279 :
case V_280 :
V_23 -> V_71 |= V_77 ;
case V_281 :
V_23 -> V_71 |= V_132 ;
break;
}
V_128 ++ ;
}
F_64 ( V_23 ) ;
}
return V_128 ;
}
static void F_130 ( const struct V_182 * V_282 , struct V_169 * V_170 )
{
struct V_22 * V_23 = NULL , * V_110 = NULL ;
struct V_67 * V_283 = V_170 -> V_283 ;
struct V_180 * V_284 = V_170 -> V_285 ;
T_6 V_286 = 32 - V_170 -> V_287 ;
int V_109 = - 1 , V_111 = - 1 ;
struct V_86 * V_87 , * V_288 = NULL ;
V_64 V_289 = V_170 -> V_23 -> V_65 ;
T_6 V_290 = 0 ;
F_131 (fa, fa_head, fa_list) {
struct V_22 * V_291 = V_87 -> V_100 ;
if ( V_87 -> V_292 != V_286 )
continue;
if ( V_87 -> V_105 && V_87 -> V_105 != V_282 -> V_293 )
continue;
if ( V_87 -> V_89 != V_284 -> V_89 )
continue;
if ( V_291 -> V_65 > V_289 &&
V_87 -> V_105 == V_290 ) {
if ( V_290 )
continue;
break;
}
if ( V_291 -> V_71 & V_77 )
continue;
V_290 = V_87 -> V_105 ;
V_289 = V_291 -> V_65 ;
if ( V_291 -> V_62 != V_170 -> V_194 ||
V_87 -> V_104 != V_179 )
continue;
if ( ! V_291 -> V_5 [ 0 ] . V_50 ||
V_291 -> V_5 [ 0 ] . V_51 != V_174 )
continue;
F_132 ( V_87 ) ;
if ( ! V_23 ) {
if ( V_291 != V_170 -> V_23 )
break;
V_288 = V_87 ;
} else if ( ! F_49 ( V_23 , V_109 , & V_110 ,
& V_111 , V_288 -> V_294 ) ) {
F_133 ( V_170 , V_23 ) ;
V_288 -> V_294 = V_109 ;
goto V_193;
}
V_23 = V_291 ;
V_109 ++ ;
}
if ( V_109 <= 0 || ! V_23 ) {
if ( V_288 )
V_288 -> V_294 = - 1 ;
goto V_193;
}
if ( ! F_49 ( V_23 , V_109 , & V_110 , & V_111 ,
V_288 -> V_294 ) ) {
F_133 ( V_170 , V_23 ) ;
V_288 -> V_294 = V_109 ;
goto V_193;
}
if ( V_111 >= 0 )
F_133 ( V_170 , V_110 ) ;
V_288 -> V_294 = V_111 ;
V_193:
return;
}
int F_134 ( struct V_73 * V_74 , unsigned int V_53 )
{
struct V_22 * V_277 ;
unsigned int V_8 ;
struct V_67 * V_21 ;
struct V_5 * V_6 ;
int V_128 ;
if ( ! ( V_74 -> V_176 & V_177 ) )
return 0 ;
if ( V_53 & V_77 ) {
unsigned int V_176 = F_135 ( V_74 ) ;
if ( V_176 & ( V_295 | V_296 ) )
V_53 |= V_132 ;
}
V_277 = NULL ;
V_8 = F_30 ( V_74 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
V_128 = 0 ;
F_33 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_213 ;
int V_297 ;
F_129 ( ! V_23 -> V_60 ) ;
if ( V_6 -> V_28 != V_74 || V_23 == V_277 )
continue;
V_277 = V_23 ;
V_297 = 0 ;
F_12 (fi) {
if ( ! ( V_27 -> V_53 & V_53 ) ) {
V_297 ++ ;
continue;
}
if ( ! V_27 -> V_28 ||
! ( V_27 -> V_28 -> V_176 & V_177 ) )
continue;
if ( V_27 -> V_28 != V_74 ||
! F_65 ( V_74 ) )
continue;
V_297 ++ ;
V_27 -> V_53 &= ~ V_53 ;
F_126 ( V_27 , V_273 ) ;
} F_15 (fi)
if ( V_297 > 0 ) {
V_23 -> V_71 &= ~ V_53 ;
V_128 ++ ;
}
F_64 ( V_23 ) ;
}
return V_128 ;
}
static bool F_136 ( const struct V_5 * V_6 )
{
int V_115 = V_120 ;
if ( V_6 -> V_51 == V_174 ) {
struct V_113 * V_114 ;
F_137 () ;
V_114 = F_138 ( V_6 -> V_28 ,
( V_63 V_64 ) V_6 -> V_50 ) ;
if ( V_114 )
V_115 = V_114 -> V_119 ;
F_139 () ;
}
return ! ! ( V_115 & V_121 ) ;
}
void F_140 ( struct V_169 * V_170 , int V_8 )
{
struct V_22 * V_23 = V_170 -> V_23 ;
struct V_167 * V_167 = V_23 -> V_38 ;
bool V_298 = false ;
F_27 (fi) {
if ( V_8 > F_98 ( & V_6 -> V_154 ) )
continue;
if ( ! V_167 -> V_39 . V_299 ||
F_136 ( V_6 ) ) {
V_170 -> V_300 = V_301 ;
return;
}
if ( ! V_298 ) {
V_170 -> V_300 = V_301 ;
V_298 = true ;
}
} F_15 ( V_23 ) ;
}
void F_141 ( struct V_167 * V_167 , struct V_169 * V_170 ,
struct V_182 * V_183 , const struct V_93 * V_94 )
{
bool V_302 ;
V_302 = ( V_183 -> V_186 == 0 ||
V_183 -> V_303 & V_304 ) ;
#ifdef F_28
if ( V_170 -> V_23 -> V_60 > 1 && V_302 ) {
int V_305 = F_142 ( V_170 -> V_23 , V_183 , V_94 ) ;
F_140 ( V_170 , V_305 ) ;
}
else
#endif
if ( ! V_170 -> V_287 &&
V_170 -> V_285 -> V_306 > 1 &&
V_170 -> type == V_179 && V_302 )
F_130 ( V_183 , V_170 ) ;
if ( ! V_183 -> V_307 )
V_183 -> V_307 = F_143 ( V_167 , * V_170 ) ;
}
