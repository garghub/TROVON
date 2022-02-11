static void F_1 ( struct V_1 T_1 * * V_2 )
{
struct V_1 * V_3 = F_2 ( * V_2 , 1 ) ;
if ( ! V_3 )
return;
F_3 ( & V_3 -> V_4 ) ;
F_4 ( & V_3 -> V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 )
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
F_6 ( V_13 ) ;
V_13 = V_15 ;
}
}
F_6 ( V_8 ) ;
}
static void F_7 ( struct V_1 T_1 * T_2 * V_2 )
{
int V_19 ;
if ( ! V_2 )
return;
F_8 (cpu) {
struct V_1 * V_3 ;
V_3 = F_2 ( * F_9 ( V_2 , V_19 ) , 1 ) ;
if ( V_3 ) {
F_3 ( & V_3 -> V_4 ) ;
F_4 ( & V_3 -> V_4 ) ;
}
}
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_12 ( V_21 , struct V_22 , V_24 ) ;
struct V_25 * V_26 ;
F_13 (fi) {
if ( V_27 -> V_28 )
F_14 ( V_27 -> V_28 ) ;
F_15 ( V_27 -> V_29 ) ;
F_5 ( V_27 ) ;
F_7 ( V_27 -> V_30 ) ;
F_1 ( & V_27 -> V_31 ) ;
} F_16 ( V_23 ) ;
V_26 = V_23 -> V_32 ;
if ( V_26 != & V_33 && F_17 ( & V_26 -> V_34 ) )
F_6 ( V_26 ) ;
F_6 ( V_23 ) ;
}
void F_18 ( struct V_22 * V_23 )
{
if ( V_23 -> V_35 == 0 ) {
F_19 ( L_1 , V_23 ) ;
return;
}
V_36 -- ;
#ifdef F_20
F_13 (fi) {
if ( V_27 -> V_37 )
V_23 -> V_38 -> V_39 . V_40 -- ;
} F_16 ( V_23 ) ;
#endif
F_21 ( & V_23 -> V_24 , F_11 ) ;
}
void F_22 ( struct V_22 * V_23 )
{
F_23 ( & V_41 ) ;
if ( V_23 && -- V_23 -> V_42 == 0 ) {
F_24 ( & V_23 -> V_43 ) ;
if ( V_23 -> V_44 )
F_24 ( & V_23 -> V_45 ) ;
F_13 (fi) {
if ( ! V_27 -> V_28 )
continue;
F_24 ( & V_27 -> V_46 ) ;
} F_16 (fi)
V_23 -> V_35 = 1 ;
F_25 ( V_23 ) ;
}
F_26 ( & V_41 ) ;
}
static inline int F_27 ( const struct V_22 * V_23 , const struct V_22 * V_47 )
{
const struct V_5 * V_48 = V_47 -> V_5 ;
F_28 (fi) {
if ( V_6 -> V_49 != V_48 -> V_49 ||
V_6 -> V_50 != V_48 -> V_50 ||
V_6 -> V_51 != V_48 -> V_51 ||
#ifdef F_29
V_6 -> V_52 != V_48 -> V_52 ||
#endif
#ifdef F_20
V_6 -> V_37 != V_48 -> V_37 ||
#endif
F_30 ( V_6 -> V_29 , V_48 -> V_29 ) ||
( ( V_6 -> V_53 ^ V_48 -> V_53 ) & ~ V_54 ) )
return - 1 ;
V_48 ++ ;
} F_16 ( V_23 ) ;
return 0 ;
}
static inline unsigned int F_31 ( unsigned int V_55 )
{
unsigned int V_56 = V_57 - 1 ;
return ( V_55 ^
( V_55 >> V_58 ) ^
( V_55 >> ( V_58 * 2 ) ) ) & V_56 ;
}
static inline unsigned int F_32 ( const struct V_22 * V_23 )
{
unsigned int V_56 = ( V_59 - 1 ) ;
unsigned int V_55 = V_23 -> V_60 ;
V_55 ^= ( V_23 -> V_61 << 8 ) | V_23 -> V_62 ;
V_55 ^= ( V_63 V_64 ) V_23 -> V_44 ;
V_55 ^= V_23 -> V_65 ;
F_28 (fi) {
V_55 ^= F_31 ( V_6 -> V_49 ) ;
} F_16 (fi)
return ( V_55 ^ ( V_55 >> 7 ) ^ ( V_55 >> 12 ) ) & V_56 ;
}
static struct V_22 * F_33 ( const struct V_22 * V_66 )
{
struct V_67 * V_21 ;
struct V_22 * V_23 ;
unsigned int V_8 ;
V_8 = F_32 ( V_66 ) ;
V_21 = & V_68 [ V_8 ] ;
F_34 (fi, head, fib_hash) {
if ( ! F_35 ( V_23 -> V_38 , V_66 -> V_38 ) )
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
( V_66 -> V_60 == 0 || F_27 ( V_23 , V_66 ) == 0 ) )
return V_23 ;
}
return NULL ;
}
int F_36 ( T_3 V_72 , struct V_73 * V_74 )
{
struct V_67 * V_21 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_37 ( & V_41 ) ;
V_8 = F_31 ( V_74 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
F_34 (nh, head, nh_hash) {
if ( V_6 -> V_28 == V_74 &&
V_6 -> V_50 == V_72 &&
! ( V_6 -> V_53 & V_77 ) ) {
F_38 ( & V_41 ) ;
return 0 ;
}
}
F_38 ( & V_41 ) ;
return - 1 ;
}
static inline T_4 F_39 ( struct V_22 * V_23 )
{
T_4 V_78 = F_40 ( sizeof( struct V_79 ) )
+ F_41 ( 4 )
+ F_41 ( 4 )
+ F_41 ( 4 )
+ F_41 ( 4 )
+ F_41 ( V_80 ) ;
V_78 += F_41 ( ( V_70 * F_41 ( 4 ) ) ) ;
if ( V_23 -> V_60 ) {
T_4 V_81 = 0 ;
T_4 V_82 = F_41 ( sizeof( struct V_83 ) ) ;
V_82 += 2 * F_41 ( 4 ) ;
F_28 (fi) {
if ( V_6 -> V_29 ) {
V_81 += F_42 (
V_6 -> V_29 ) ;
V_81 += F_41 ( 2 ) ;
}
} F_16 ( V_23 ) ;
V_78 += F_41 ( ( V_23 -> V_60 * V_82 ) +
V_81 ) ;
}
return V_78 ;
}
void F_43 ( int V_84 , T_3 V_85 , struct V_86 * V_87 ,
int V_88 , V_64 V_89 , const struct V_90 * V_91 ,
unsigned int V_92 )
{
struct V_93 * V_94 ;
V_64 V_95 = V_91 -> V_96 ? V_91 -> V_96 -> V_97 : 0 ;
int V_98 = - V_99 ;
V_94 = F_44 ( F_39 ( V_87 -> V_100 ) , V_101 ) ;
if ( ! V_94 )
goto V_102;
V_98 = F_45 ( V_94 , V_91 -> V_103 , V_95 , V_84 , V_89 ,
V_87 -> V_104 , V_85 , V_88 ,
V_87 -> V_105 , V_87 -> V_100 , V_92 ) ;
if ( V_98 < 0 ) {
F_46 ( V_98 == - V_106 ) ;
F_47 ( V_94 ) ;
goto V_102;
}
F_48 ( V_94 , V_91 -> V_107 , V_91 -> V_103 , V_108 ,
V_91 -> V_96 , V_101 ) ;
return;
V_102:
if ( V_98 < 0 )
F_49 ( V_91 -> V_107 , V_108 , V_98 ) ;
}
static int F_50 ( struct V_22 * V_23 , int V_109 ,
struct V_22 * * V_110 , int * V_111 ,
int V_112 )
{
struct V_113 * V_114 ;
int V_115 = V_116 ;
V_114 = F_51 ( & V_117 , & V_23 -> V_5 [ 0 ] . V_50 , V_23 -> V_118 ) ;
if ( V_114 ) {
V_115 = V_114 -> V_119 ;
F_52 ( V_114 ) ;
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
static int F_53 ( struct V_83 * V_123 , int V_124 ,
struct V_125 * V_126 )
{
int V_127 = 0 ;
while ( F_54 ( V_123 , V_124 ) ) {
V_127 ++ ;
V_123 = F_55 ( V_123 , & V_124 ) ;
}
if ( V_124 > 0 ) {
F_56 ( V_126 ,
L_2 ) ;
V_127 = 0 ;
}
return V_127 ;
}
static int F_57 ( struct V_22 * V_23 , struct V_83 * V_123 ,
int V_124 , struct V_128 * V_129 ,
struct V_125 * V_126 )
{
int V_130 ;
F_13 (fi) {
int V_131 ;
if ( ! F_54 ( V_123 , V_124 ) ) {
F_56 ( V_126 ,
L_3 ) ;
return - V_132 ;
}
if ( V_123 -> V_133 & ( V_77 | V_134 ) ) {
F_56 ( V_126 ,
L_4 ) ;
return - V_132 ;
}
V_27 -> V_53 =
( V_129 -> V_135 & ~ 0xFF ) | V_123 -> V_133 ;
V_27 -> V_49 = V_123 -> V_136 ;
V_27 -> V_52 = V_123 -> V_137 + 1 ;
V_131 = F_58 ( V_123 ) ;
if ( V_131 > 0 ) {
struct V_138 * V_139 , * V_140 = F_59 ( V_123 ) ;
V_139 = F_60 ( V_140 , V_131 , V_141 ) ;
V_27 -> V_50 = V_139 ? F_61 ( V_139 ) : 0 ;
#ifdef F_20
V_139 = F_60 ( V_140 , V_131 , V_142 ) ;
V_27 -> V_37 = V_139 ? F_62 ( V_139 ) : 0 ;
if ( V_27 -> V_37 )
V_23 -> V_38 -> V_39 . V_40 ++ ;
#endif
V_139 = F_60 ( V_140 , V_131 , V_143 ) ;
if ( V_139 ) {
struct V_144 * V_145 ;
struct V_138 * V_146 ;
V_146 = F_60 ( V_140 , V_131 ,
V_147 ) ;
if ( ! V_146 ) {
F_63 ( V_126 , V_139 ) ;
F_56 ( V_126 ,
L_5 ) ;
goto V_148;
}
V_130 = F_64 ( F_65 (
V_146 ) ,
V_139 , V_149 , V_129 ,
& V_145 , V_126 ) ;
if ( V_130 )
goto V_102;
V_27 -> V_29 =
F_66 ( V_145 ) ;
}
}
V_123 = F_55 ( V_123 , & V_124 ) ;
} F_16 ( V_23 ) ;
return 0 ;
V_148:
V_130 = - V_132 ;
V_102:
return V_130 ;
}
static void F_67 ( struct V_22 * V_23 )
{
int V_150 ;
int V_151 ;
struct V_152 * V_153 ;
if ( V_23 -> V_60 < 2 )
return;
V_150 = 0 ;
F_28 (fi) {
if ( V_6 -> V_53 & V_77 )
continue;
V_153 = F_68 ( V_6 -> V_28 ) ;
if ( V_153 &&
F_69 ( V_153 ) &&
V_6 -> V_53 & V_134 )
continue;
V_150 += V_6 -> V_52 ;
} F_16 ( V_23 ) ;
V_151 = 0 ;
F_13 (fi) {
int V_154 ;
V_153 = F_68 ( V_27 -> V_28 ) ;
if ( V_27 -> V_53 & V_77 ) {
V_154 = - 1 ;
} else if ( V_153 &&
F_69 ( V_153 ) &&
V_27 -> V_53 & V_134 ) {
V_154 = - 1 ;
} else {
V_151 += V_27 -> V_52 ;
V_154 = F_70 ( ( V_155 ) V_151 << 31 ,
V_150 ) - 1 ;
}
F_71 ( & V_27 -> V_156 , V_154 ) ;
} F_16 ( V_23 ) ;
}
static inline void F_72 ( struct V_22 * V_23 ,
const struct V_5 * V_6 )
{
V_23 -> V_157 += V_6 -> V_52 ;
}
static int F_73 ( T_5 V_158 ,
struct V_138 * V_159 ,
const struct V_5 * V_6 ,
const struct V_128 * V_129 ,
struct V_125 * V_126 )
{
struct V_144 * V_145 ;
int V_130 , V_160 = 0 ;
if ( V_158 == V_161 )
return 0 ;
V_130 = F_64 ( V_158 , V_159 , V_149 ,
V_129 , & V_145 , V_126 ) ;
if ( ! V_130 ) {
V_160 = F_30 ( V_145 , V_6 -> V_29 ) ;
F_74 ( V_145 ) ;
}
return V_160 ;
}
int F_75 ( struct V_128 * V_129 , struct V_22 * V_23 ,
struct V_125 * V_126 )
{
#ifdef F_29
struct V_83 * V_123 ;
int V_124 ;
#endif
if ( V_129 -> V_162 && V_129 -> V_162 != V_23 -> V_65 )
return 1 ;
if ( V_129 -> V_163 || V_129 -> V_164 ) {
if ( V_129 -> V_165 ) {
if ( F_73 ( V_129 -> V_166 , V_129 -> V_165 ,
V_23 -> V_5 , V_129 , V_126 ) )
return 1 ;
}
if ( ( ! V_129 -> V_163 || V_129 -> V_163 == V_23 -> V_5 -> V_49 ) &&
( ! V_129 -> V_164 || V_129 -> V_164 == V_23 -> V_5 -> V_50 ) )
return 0 ;
return 1 ;
}
#ifdef F_29
if ( ! V_129 -> V_167 )
return 0 ;
V_123 = V_129 -> V_167 ;
V_124 = V_129 -> V_168 ;
F_28 (fi) {
int V_131 ;
if ( ! F_54 ( V_123 , V_124 ) )
return - V_132 ;
if ( V_123 -> V_136 && V_123 -> V_136 != V_6 -> V_49 )
return 1 ;
V_131 = F_58 ( V_123 ) ;
if ( V_131 > 0 ) {
struct V_138 * V_139 , * V_140 = F_59 ( V_123 ) ;
V_139 = F_60 ( V_140 , V_131 , V_141 ) ;
if ( V_139 && F_61 ( V_139 ) != V_6 -> V_50 )
return 1 ;
#ifdef F_20
V_139 = F_60 ( V_140 , V_131 , V_142 ) ;
if ( V_139 && F_62 ( V_139 ) != V_6 -> V_37 )
return 1 ;
#endif
}
V_123 = F_55 ( V_123 , & V_124 ) ;
} F_16 ( V_23 ) ;
#endif
return 0 ;
}
bool F_76 ( struct V_128 * V_129 , struct V_22 * V_23 )
{
struct V_138 * V_139 ;
int V_124 ;
if ( ! V_129 -> V_169 )
return true ;
F_77 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_78 ( V_139 ) ;
V_64 V_55 ;
if ( ! type )
continue;
if ( type > V_70 )
return false ;
if ( type == V_170 ) {
char V_171 [ V_80 ] ;
bool V_172 = false ;
F_79 ( V_171 , V_139 , sizeof( V_171 ) ) ;
V_55 = F_80 ( V_171 , & V_172 ) ;
} else {
V_55 = F_62 ( V_139 ) ;
}
if ( V_23 -> V_32 -> V_173 [ type - 1 ] != V_55 )
return false ;
}
return true ;
}
static int F_81 ( struct V_128 * V_129 , struct V_22 * V_23 ,
struct V_5 * V_6 , struct V_125 * V_126 )
{
int V_98 = 0 ;
struct V_174 * V_174 ;
struct V_73 * V_74 ;
V_174 = V_129 -> V_175 . V_107 ;
if ( V_6 -> V_50 ) {
struct V_176 V_177 ;
if ( V_6 -> V_53 & V_178 ) {
unsigned int V_179 ;
if ( V_129 -> V_180 >= V_181 ) {
F_56 ( V_126 ,
L_6 ) ;
return - V_132 ;
}
V_74 = F_82 ( V_174 , V_6 -> V_49 ) ;
if ( ! V_74 )
return - V_182 ;
if ( ! ( V_74 -> V_183 & V_184 ) ) {
F_56 ( V_126 ,
L_7 ) ;
return - V_185 ;
}
V_179 = F_83 ( V_174 , V_74 , V_6 -> V_50 ) ;
if ( V_179 != V_186 ) {
F_56 ( V_126 ,
L_8 ) ;
return - V_132 ;
}
if ( ! F_84 ( V_74 ) )
V_6 -> V_53 |= V_134 ;
V_6 -> V_28 = V_74 ;
F_85 ( V_74 ) ;
V_6 -> V_51 = V_181 ;
return 0 ;
}
F_86 () ;
{
struct V_187 * V_188 = NULL ;
struct V_189 V_190 = {
. V_191 = V_6 -> V_50 ,
. V_192 = V_129 -> V_180 + 1 ,
. V_193 = V_6 -> V_49 ,
. V_194 = V_195 ,
} ;
if ( V_190 . V_192 < V_181 )
V_190 . V_192 = V_181 ;
if ( V_129 -> V_196 )
V_188 = F_87 ( V_174 , V_129 -> V_196 ) ;
if ( V_188 )
V_98 = F_88 ( V_188 , & V_190 , & V_177 ,
V_197 |
V_198 ) ;
if ( ! V_188 || V_98 ) {
V_98 = F_89 ( V_174 , & V_190 , & V_177 ,
V_197 ) ;
}
if ( V_98 ) {
F_56 ( V_126 ,
L_8 ) ;
F_90 () ;
return V_98 ;
}
}
V_98 = - V_132 ;
if ( V_177 . type != V_186 && V_177 . type != V_199 ) {
F_56 ( V_126 , L_8 ) ;
goto V_200;
}
V_6 -> V_51 = V_177 . V_201 ;
V_6 -> V_49 = F_91 ( V_177 ) ;
V_6 -> V_28 = V_74 = F_92 ( V_177 ) ;
if ( ! V_74 ) {
F_56 ( V_126 ,
L_9 ) ;
goto V_200;
}
F_85 ( V_74 ) ;
if ( ! F_84 ( V_74 ) )
V_6 -> V_53 |= V_134 ;
V_98 = ( V_74 -> V_183 & V_184 ) ? 0 : - V_185 ;
} else {
struct V_152 * V_153 ;
if ( V_6 -> V_53 & ( V_202 | V_178 ) ) {
F_56 ( V_126 ,
L_10 ) ;
return - V_132 ;
}
F_86 () ;
V_98 = - V_182 ;
V_153 = F_93 ( V_174 , V_6 -> V_49 ) ;
if ( ! V_153 )
goto V_200;
V_98 = - V_185 ;
if ( ! ( V_153 -> V_74 -> V_183 & V_184 ) ) {
F_56 ( V_126 , L_11 ) ;
goto V_200;
}
V_6 -> V_28 = V_153 -> V_74 ;
F_85 ( V_6 -> V_28 ) ;
V_6 -> V_51 = V_203 ;
if ( ! F_84 ( V_6 -> V_28 ) )
V_6 -> V_53 |= V_134 ;
V_98 = 0 ;
}
V_200:
F_90 () ;
return V_98 ;
}
static inline unsigned int F_94 ( T_3 V_55 )
{
unsigned int V_56 = ( V_59 - 1 ) ;
return ( ( V_63 V_64 ) V_55 ^
( ( V_63 V_64 ) V_55 >> 7 ) ^
( ( V_63 V_64 ) V_55 >> 14 ) ) & V_56 ;
}
static struct V_67 * F_95 ( int V_204 )
{
if ( V_204 <= V_205 )
return F_96 ( V_204 , V_101 ) ;
else
return (struct V_67 * )
F_97 ( V_101 | V_206 ,
F_98 ( V_204 ) ) ;
}
static void F_99 ( struct V_67 * V_8 , int V_204 )
{
if ( ! V_8 )
return;
if ( V_204 <= V_205 )
F_6 ( V_8 ) ;
else
F_100 ( ( unsigned long ) V_8 , F_98 ( V_204 ) ) ;
}
static void F_101 ( struct V_67 * V_207 ,
struct V_67 * V_208 ,
unsigned int V_209 )
{
struct V_67 * V_210 , * V_211 ;
unsigned int V_212 = V_59 ;
unsigned int V_9 , V_204 ;
F_23 ( & V_41 ) ;
V_210 = V_68 ;
V_211 = V_213 ;
V_59 = V_209 ;
for ( V_9 = 0 ; V_9 < V_212 ; V_9 ++ ) {
struct V_67 * V_21 = & V_68 [ V_9 ] ;
struct V_214 * V_114 ;
struct V_22 * V_23 ;
F_102 (fi, n, head, fib_hash) {
struct V_67 * V_215 ;
unsigned int V_216 ;
V_216 = F_32 ( V_23 ) ;
V_215 = & V_207 [ V_216 ] ;
F_103 ( & V_23 -> V_43 , V_215 ) ;
}
}
V_68 = V_207 ;
for ( V_9 = 0 ; V_9 < V_212 ; V_9 ++ ) {
struct V_67 * V_217 = & V_213 [ V_9 ] ;
struct V_214 * V_114 ;
struct V_22 * V_23 ;
F_102 (fi, n, lhead, fib_lhash) {
struct V_67 * V_218 ;
unsigned int V_216 ;
V_216 = F_94 ( V_23 -> V_44 ) ;
V_218 = & V_208 [ V_216 ] ;
F_103 ( & V_23 -> V_45 , V_218 ) ;
}
}
V_213 = V_208 ;
F_26 ( & V_41 ) ;
V_204 = V_212 * sizeof( struct V_67 * ) ;
F_99 ( V_210 , V_204 ) ;
F_99 ( V_211 , V_204 ) ;
}
T_3 F_104 ( struct V_174 * V_174 , struct V_5 * V_6 )
{
V_6 -> V_219 = F_105 ( V_6 -> V_28 ,
V_6 -> V_50 ,
V_6 -> V_220 -> V_62 ) ;
V_6 -> V_221 = F_106 ( & V_174 -> V_39 . V_222 ) ;
return V_6 -> V_219 ;
}
static bool F_107 ( struct V_128 * V_129 , T_3 V_44 )
{
if ( V_129 -> V_223 != V_199 || ! V_129 -> V_224 ||
V_44 != V_129 -> V_224 ) {
V_64 V_89 = V_129 -> V_196 ;
int V_225 ;
if ( V_89 == V_226 )
V_89 = V_227 ;
V_225 = F_108 ( V_129 -> V_175 . V_107 ,
V_44 , V_89 ) ;
if ( V_225 != V_199 && V_89 != V_227 ) {
V_225 = F_108 ( V_129 -> V_175 . V_107 ,
V_44 , V_227 ) ;
}
if ( V_225 != V_199 )
return false ;
}
return true ;
}
static int
F_109 ( struct V_22 * V_23 , const struct V_128 * V_129 )
{
bool V_172 = false ;
struct V_138 * V_139 ;
int V_124 ;
if ( ! V_129 -> V_169 )
return 0 ;
F_77 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_78 ( V_139 ) ;
V_64 V_55 ;
if ( ! type )
continue;
if ( type > V_70 )
return - V_132 ;
if ( type == V_170 ) {
char V_171 [ V_80 ] ;
F_79 ( V_171 , V_139 , sizeof( V_171 ) ) ;
V_55 = F_80 ( V_171 , & V_172 ) ;
if ( V_55 == V_228 )
return - V_132 ;
} else {
V_55 = F_62 ( V_139 ) ;
}
if ( type == V_229 && V_55 > 65535 - 40 )
V_55 = 65535 - 40 ;
if ( type == V_230 && V_55 > 65535 - 15 )
V_55 = 65535 - 15 ;
if ( type == V_231 && V_55 > 255 )
V_55 = 255 ;
if ( type == V_232 && ( V_55 & ~ V_233 ) )
return - V_132 ;
V_23 -> V_32 -> V_173 [ type - 1 ] = V_55 ;
}
if ( V_172 )
V_23 -> V_32 -> V_173 [ V_232 - 1 ] |= V_234 ;
return 0 ;
}
struct V_22 * F_110 ( struct V_128 * V_129 ,
struct V_125 * V_126 )
{
int V_98 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_47 ;
int V_127 = 1 ;
struct V_174 * V_174 = V_129 -> V_175 . V_107 ;
if ( V_129 -> V_223 > V_235 )
goto V_148;
if ( V_236 [ V_129 -> V_223 ] . V_201 > V_129 -> V_180 ) {
F_56 ( V_126 , L_12 ) ;
goto V_148;
}
if ( V_129 -> V_135 & ( V_77 | V_134 ) ) {
F_56 ( V_126 ,
L_13 ) ;
goto V_148;
}
#ifdef F_29
if ( V_129 -> V_167 ) {
V_127 = F_53 ( V_129 -> V_167 , V_129 -> V_168 , V_126 ) ;
if ( V_127 == 0 )
goto V_148;
}
#endif
V_98 = - V_99 ;
if ( V_36 >= V_59 ) {
unsigned int V_209 = V_59 << 1 ;
struct V_67 * V_207 ;
struct V_67 * V_208 ;
unsigned int V_204 ;
if ( ! V_209 )
V_209 = 16 ;
V_204 = V_209 * sizeof( struct V_67 * ) ;
V_207 = F_95 ( V_204 ) ;
V_208 = F_95 ( V_204 ) ;
if ( ! V_207 || ! V_208 ) {
F_99 ( V_207 , V_204 ) ;
F_99 ( V_208 , V_204 ) ;
} else
F_101 ( V_207 , V_208 , V_209 ) ;
if ( ! V_59 )
goto V_237;
}
V_23 = F_96 ( sizeof( * V_23 ) + V_127 * sizeof( struct V_5 ) , V_101 ) ;
if ( ! V_23 )
goto V_237;
if ( V_129 -> V_169 ) {
V_23 -> V_32 = F_96 ( sizeof( * V_23 -> V_32 ) , V_101 ) ;
if ( F_111 ( ! V_23 -> V_32 ) ) {
F_6 ( V_23 ) ;
return F_112 ( V_98 ) ;
}
F_113 ( & V_23 -> V_32 -> V_34 , 1 ) ;
} else {
V_23 -> V_32 = (struct V_25 * ) & V_33 ;
}
V_36 ++ ;
V_23 -> V_38 = V_174 ;
V_23 -> V_61 = V_129 -> V_238 ;
V_23 -> V_62 = V_129 -> V_180 ;
V_23 -> V_71 = V_129 -> V_135 ;
V_23 -> V_65 = V_129 -> V_162 ;
V_23 -> V_44 = V_129 -> V_239 ;
V_23 -> V_69 = V_129 -> V_223 ;
V_23 -> V_240 = V_129 -> V_196 ;
V_23 -> V_60 = V_127 ;
F_13 (fi) {
V_27 -> V_220 = V_23 ;
V_27 -> V_30 = F_114 (struct rtable __rcu *) ;
if ( ! V_27 -> V_30 )
goto V_237;
} F_16 (fi)
V_98 = F_109 ( V_23 , V_129 ) ;
if ( V_98 )
goto V_237;
if ( V_129 -> V_167 ) {
#ifdef F_29
V_98 = F_57 ( V_23 , V_129 -> V_167 , V_129 -> V_168 , V_129 , V_126 ) ;
if ( V_98 != 0 )
goto V_237;
if ( V_129 -> V_163 && V_23 -> V_5 -> V_49 != V_129 -> V_163 ) {
F_56 ( V_126 ,
L_14 ) ;
goto V_148;
}
if ( V_129 -> V_164 && V_23 -> V_5 -> V_50 != V_129 -> V_164 ) {
F_56 ( V_126 ,
L_15 ) ;
goto V_148;
}
#ifdef F_20
if ( V_129 -> V_241 && V_23 -> V_5 -> V_37 != V_129 -> V_241 ) {
F_56 ( V_126 ,
L_16 ) ;
goto V_148;
}
#endif
#else
F_56 ( V_126 ,
L_17 ) ;
goto V_148;
#endif
} else {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_129 -> V_165 ) {
struct V_144 * V_145 ;
if ( V_129 -> V_166 == V_161 ) {
F_56 ( V_126 ,
L_18 ) ;
goto V_148;
}
V_98 = F_64 ( V_129 -> V_166 ,
V_129 -> V_165 , V_149 , V_129 ,
& V_145 , V_126 ) ;
if ( V_98 )
goto V_237;
V_6 -> V_29 = F_66 ( V_145 ) ;
}
V_6 -> V_49 = V_129 -> V_163 ;
V_6 -> V_50 = V_129 -> V_164 ;
V_6 -> V_53 = V_129 -> V_135 ;
#ifdef F_20
V_6 -> V_37 = V_129 -> V_241 ;
if ( V_6 -> V_37 )
V_23 -> V_38 -> V_39 . V_40 ++ ;
#endif
#ifdef F_29
V_6 -> V_52 = 1 ;
#endif
}
if ( V_236 [ V_129 -> V_223 ] . error ) {
if ( V_129 -> V_164 || V_129 -> V_163 || V_129 -> V_167 ) {
F_56 ( V_126 ,
L_19 ) ;
goto V_148;
}
goto V_242;
} else {
switch ( V_129 -> V_223 ) {
case V_186 :
case V_199 :
case V_243 :
case V_244 :
case V_245 :
break;
default:
F_56 ( V_126 , L_20 ) ;
goto V_148;
}
}
if ( V_129 -> V_180 > V_203 ) {
F_56 ( V_126 , L_12 ) ;
goto V_148;
}
if ( V_129 -> V_180 == V_203 ) {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_127 != 1 ) {
F_56 ( V_126 ,
L_21 ) ;
goto V_148;
}
if ( V_6 -> V_50 ) {
F_56 ( V_126 ,
L_22 ) ;
goto V_148;
}
V_6 -> V_51 = V_246 ;
V_6 -> V_28 = F_115 ( V_174 , V_23 -> V_5 -> V_49 ) ;
V_98 = - V_182 ;
if ( ! V_6 -> V_28 )
goto V_237;
} else {
int V_247 = 0 ;
F_13 (fi) {
V_98 = F_81 ( V_129 , V_23 , V_27 , V_126 ) ;
if ( V_98 != 0 )
goto V_237;
if ( V_27 -> V_53 & V_134 )
V_247 ++ ;
} F_16 (fi)
if ( V_247 == V_23 -> V_60 )
V_23 -> V_71 |= V_134 ;
}
if ( V_23 -> V_44 && ! F_107 ( V_129 , V_23 -> V_44 ) ) {
F_56 ( V_126 , L_23 ) ;
goto V_148;
}
F_13 (fi) {
F_104 ( V_174 , V_27 ) ;
F_72 ( V_23 , V_27 ) ;
} F_16 (fi)
F_67 ( V_23 ) ;
V_242:
V_47 = F_33 ( V_23 ) ;
if ( V_47 ) {
V_23 -> V_35 = 1 ;
F_18 ( V_23 ) ;
V_47 -> V_42 ++ ;
return V_47 ;
}
V_23 -> V_42 ++ ;
F_113 ( & V_23 -> V_248 , 1 ) ;
F_23 ( & V_41 ) ;
F_103 ( & V_23 -> V_43 ,
& V_68 [ F_32 ( V_23 ) ] ) ;
if ( V_23 -> V_44 ) {
struct V_67 * V_21 ;
V_21 = & V_213 [ F_94 ( V_23 -> V_44 ) ] ;
F_103 ( & V_23 -> V_45 , V_21 ) ;
}
F_13 (fi) {
struct V_67 * V_21 ;
unsigned int V_8 ;
if ( ! V_27 -> V_28 )
continue;
V_8 = F_31 ( V_27 -> V_28 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
F_103 ( & V_27 -> V_46 , V_21 ) ;
} F_16 (fi)
F_26 ( & V_41 ) ;
return V_23 ;
V_148:
V_98 = - V_132 ;
V_237:
if ( V_23 ) {
V_23 -> V_35 = 1 ;
F_18 ( V_23 ) ;
}
return F_112 ( V_98 ) ;
}
int F_45 ( struct V_93 * V_94 , V_64 V_103 , V_64 V_95 , int V_84 ,
V_64 V_89 , T_6 type , T_3 V_4 , int V_88 , T_6 V_249 ,
struct V_22 * V_23 , unsigned int V_183 )
{
struct V_250 * V_96 ;
struct V_79 * V_251 ;
V_96 = F_116 ( V_94 , V_103 , V_95 , V_84 , sizeof( * V_251 ) , V_183 ) ;
if ( ! V_96 )
return - V_106 ;
V_251 = F_117 ( V_96 ) ;
V_251 -> V_252 = V_149 ;
V_251 -> V_253 = V_88 ;
V_251 -> V_254 = 0 ;
V_251 -> V_255 = V_249 ;
if ( V_89 < 256 )
V_251 -> V_256 = V_89 ;
else
V_251 -> V_256 = V_257 ;
if ( F_118 ( V_94 , V_258 , V_89 ) )
goto V_259;
V_251 -> V_260 = type ;
V_251 -> V_261 = V_23 -> V_71 ;
V_251 -> V_262 = V_23 -> V_62 ;
V_251 -> V_263 = V_23 -> V_61 ;
if ( V_251 -> V_253 &&
F_119 ( V_94 , V_264 , V_4 ) )
goto V_259;
if ( V_23 -> V_65 &&
F_118 ( V_94 , V_265 , V_23 -> V_65 ) )
goto V_259;
if ( F_120 ( V_94 , V_23 -> V_32 -> V_173 ) < 0 )
goto V_259;
if ( V_23 -> V_44 &&
F_119 ( V_94 , V_266 , V_23 -> V_44 ) )
goto V_259;
if ( V_23 -> V_60 == 1 ) {
if ( V_23 -> V_5 -> V_50 &&
F_119 ( V_94 , V_141 , V_23 -> V_5 -> V_50 ) )
goto V_259;
if ( V_23 -> V_5 -> V_49 &&
F_118 ( V_94 , V_267 , V_23 -> V_5 -> V_49 ) )
goto V_259;
if ( V_23 -> V_5 -> V_53 & V_134 ) {
struct V_152 * V_153 ;
F_86 () ;
V_153 = F_121 ( V_23 -> V_5 -> V_28 ) ;
if ( V_153 &&
F_69 ( V_153 ) )
V_251 -> V_261 |= V_77 ;
F_90 () ;
}
if ( V_23 -> V_5 -> V_53 & V_268 )
V_251 -> V_261 |= V_268 ;
#ifdef F_20
if ( V_23 -> V_5 [ 0 ] . V_37 &&
F_118 ( V_94 , V_142 , V_23 -> V_5 [ 0 ] . V_37 ) )
goto V_259;
#endif
if ( V_23 -> V_5 -> V_29 &&
F_122 ( V_94 , V_23 -> V_5 -> V_29 ) < 0 )
goto V_259;
}
#ifdef F_29
if ( V_23 -> V_60 > 1 ) {
struct V_83 * V_123 ;
struct V_138 * V_269 ;
V_269 = F_123 ( V_94 , V_270 ) ;
if ( ! V_269 )
goto V_259;
F_28 (fi) {
V_123 = F_124 ( V_94 , sizeof( * V_123 ) ) ;
if ( ! V_123 )
goto V_259;
V_123 -> V_133 = V_6 -> V_53 & 0xFF ;
if ( V_6 -> V_53 & V_134 ) {
struct V_152 * V_153 ;
F_86 () ;
V_153 = F_121 ( V_6 -> V_28 ) ;
if ( V_153 &&
F_69 ( V_153 ) )
V_123 -> V_133 |= V_77 ;
F_90 () ;
}
V_123 -> V_137 = V_6 -> V_52 - 1 ;
V_123 -> V_136 = V_6 -> V_49 ;
if ( V_6 -> V_50 &&
F_119 ( V_94 , V_141 , V_6 -> V_50 ) )
goto V_259;
#ifdef F_20
if ( V_6 -> V_37 &&
F_118 ( V_94 , V_142 , V_6 -> V_37 ) )
goto V_259;
#endif
if ( V_6 -> V_29 &&
F_122 ( V_94 , V_6 -> V_29 ) < 0 )
goto V_259;
V_123 -> V_271 = F_125 ( V_94 ) - ( void * ) V_123 ;
} F_16 ( V_23 ) ;
F_126 ( V_94 , V_269 ) ;
}
#endif
F_127 ( V_94 , V_96 ) ;
return 0 ;
V_259:
F_128 ( V_94 , V_96 ) ;
return - V_106 ;
}
int F_129 ( struct V_73 * V_74 , T_3 V_272 )
{
int V_130 = 0 ;
unsigned int V_8 = F_94 ( V_272 ) ;
struct V_67 * V_21 = & V_213 [ V_8 ] ;
struct V_174 * V_174 = F_130 ( V_74 ) ;
int V_89 = F_131 ( V_74 ) ;
struct V_22 * V_23 ;
if ( ! V_213 || V_272 == 0 )
return 0 ;
F_34 (fi, head, fib_lhash) {
if ( ! F_35 ( V_23 -> V_38 , V_174 ) ||
V_23 -> V_240 != V_89 )
continue;
if ( V_23 -> V_44 == V_272 ) {
V_23 -> V_71 |= V_77 ;
V_130 ++ ;
}
}
return V_130 ;
}
static int F_132 ( struct V_5 * V_5 ,
enum V_273 V_274 )
{
struct V_152 * V_153 = F_68 ( V_5 -> V_28 ) ;
struct V_275 V_91 = {
. V_5 = V_5 ,
} ;
switch ( V_274 ) {
case V_276 :
if ( V_5 -> V_53 & V_77 )
break;
if ( F_69 ( V_153 ) &&
V_5 -> V_53 & V_134 )
break;
return F_133 ( F_130 ( V_5 -> V_28 ) , V_274 ,
& V_91 . V_91 ) ;
case V_277 :
if ( ( V_153 && F_69 ( V_153 ) &&
V_5 -> V_53 & V_134 ) ||
( V_5 -> V_53 & V_77 ) )
return F_133 ( F_130 ( V_5 -> V_28 ) ,
V_274 , & V_91 . V_91 ) ;
default:
break;
}
return V_278 ;
}
int F_134 ( struct V_73 * V_74 , unsigned long V_84 , bool V_279 )
{
int V_130 = 0 ;
int V_201 = V_246 ;
struct V_22 * V_280 = NULL ;
unsigned int V_8 = F_31 ( V_74 -> V_75 ) ;
struct V_67 * V_21 = & V_76 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_279 )
V_201 = - 1 ;
F_34 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_220 ;
int V_281 ;
F_135 ( ! V_23 -> V_60 ) ;
if ( V_6 -> V_28 != V_74 || V_23 == V_280 )
continue;
V_280 = V_23 ;
V_281 = 0 ;
F_13 (fi) {
if ( V_27 -> V_53 & V_77 )
V_281 ++ ;
else if ( V_27 -> V_28 == V_74 &&
V_27 -> V_51 != V_201 ) {
switch ( V_84 ) {
case V_282 :
case V_283 :
V_27 -> V_53 |= V_77 ;
case V_284 :
V_27 -> V_53 |= V_134 ;
break;
}
F_132 ( V_27 ,
V_277 ) ;
V_281 ++ ;
}
#ifdef F_29
if ( V_84 == V_283 &&
V_27 -> V_28 == V_74 ) {
V_281 = V_23 -> V_60 ;
break;
}
#endif
} F_16 (fi)
if ( V_281 == V_23 -> V_60 ) {
switch ( V_84 ) {
case V_282 :
case V_283 :
V_23 -> V_71 |= V_77 ;
case V_284 :
V_23 -> V_71 |= V_134 ;
break;
}
V_130 ++ ;
}
F_67 ( V_23 ) ;
}
return V_130 ;
}
static void F_136 ( const struct V_189 * V_285 , struct V_176 * V_177 )
{
struct V_22 * V_23 = NULL , * V_110 = NULL ;
struct V_67 * V_286 = V_177 -> V_286 ;
struct V_187 * V_287 = V_177 -> V_288 ;
T_6 V_289 = 32 - V_177 -> V_290 ;
int V_109 = - 1 , V_111 = - 1 ;
struct V_86 * V_87 , * V_291 = NULL ;
V_64 V_292 = V_177 -> V_23 -> V_65 ;
T_6 V_293 = 0 ;
F_137 (fa, fa_head, fa_list) {
struct V_22 * V_294 = V_87 -> V_100 ;
if ( V_87 -> V_295 != V_289 )
continue;
if ( V_87 -> V_105 && V_87 -> V_105 != V_285 -> V_296 )
continue;
if ( V_87 -> V_89 != V_287 -> V_89 )
continue;
if ( V_294 -> V_65 > V_292 &&
V_87 -> V_105 == V_293 ) {
if ( V_293 )
continue;
break;
}
if ( V_294 -> V_71 & V_77 )
continue;
V_293 = V_87 -> V_105 ;
V_292 = V_294 -> V_65 ;
if ( V_294 -> V_62 != V_177 -> V_201 ||
V_87 -> V_104 != V_186 )
continue;
if ( ! V_294 -> V_5 [ 0 ] . V_50 ||
V_294 -> V_5 [ 0 ] . V_51 != V_181 )
continue;
F_138 ( V_87 ) ;
if ( ! V_23 ) {
if ( V_294 != V_177 -> V_23 )
break;
V_291 = V_87 ;
} else if ( ! F_50 ( V_23 , V_109 , & V_110 ,
& V_111 , V_291 -> V_297 ) ) {
F_139 ( V_177 , V_23 ) ;
V_291 -> V_297 = V_109 ;
goto V_200;
}
V_23 = V_294 ;
V_109 ++ ;
}
if ( V_109 <= 0 || ! V_23 ) {
if ( V_291 )
V_291 -> V_297 = - 1 ;
goto V_200;
}
if ( ! F_50 ( V_23 , V_109 , & V_110 , & V_111 ,
V_291 -> V_297 ) ) {
F_139 ( V_177 , V_23 ) ;
V_291 -> V_297 = V_109 ;
goto V_200;
}
if ( V_111 >= 0 )
F_139 ( V_177 , V_110 ) ;
V_291 -> V_297 = V_111 ;
V_200:
return;
}
int F_140 ( struct V_73 * V_74 , unsigned int V_53 )
{
struct V_22 * V_280 ;
unsigned int V_8 ;
struct V_67 * V_21 ;
struct V_5 * V_6 ;
int V_130 ;
if ( ! ( V_74 -> V_183 & V_184 ) )
return 0 ;
if ( V_53 & V_77 ) {
unsigned int V_183 = F_141 ( V_74 ) ;
if ( V_183 & ( V_298 | V_299 ) )
V_53 |= V_134 ;
}
V_280 = NULL ;
V_8 = F_31 ( V_74 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
V_130 = 0 ;
F_34 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_220 ;
int V_300 ;
F_135 ( ! V_23 -> V_60 ) ;
if ( V_6 -> V_28 != V_74 || V_23 == V_280 )
continue;
V_280 = V_23 ;
V_300 = 0 ;
F_13 (fi) {
if ( ! ( V_27 -> V_53 & V_53 ) ) {
V_300 ++ ;
continue;
}
if ( ! V_27 -> V_28 ||
! ( V_27 -> V_28 -> V_183 & V_184 ) )
continue;
if ( V_27 -> V_28 != V_74 ||
! F_68 ( V_74 ) )
continue;
V_300 ++ ;
V_27 -> V_53 &= ~ V_53 ;
F_132 ( V_27 , V_276 ) ;
} F_16 (fi)
if ( V_300 > 0 ) {
V_23 -> V_71 &= ~ V_53 ;
V_130 ++ ;
}
F_67 ( V_23 ) ;
}
return V_130 ;
}
static bool F_142 ( const struct V_5 * V_6 )
{
int V_115 = V_120 ;
if ( V_6 -> V_51 == V_181 ) {
struct V_113 * V_114 ;
F_143 () ;
V_114 = F_144 ( V_6 -> V_28 ,
( V_63 V_64 ) V_6 -> V_50 ) ;
if ( V_114 )
V_115 = V_114 -> V_119 ;
F_145 () ;
}
return ! ! ( V_115 & V_121 ) ;
}
void F_146 ( struct V_176 * V_177 , int V_8 )
{
struct V_22 * V_23 = V_177 -> V_23 ;
struct V_174 * V_174 = V_23 -> V_38 ;
bool V_301 = false ;
F_28 (fi) {
if ( V_8 > F_106 ( & V_6 -> V_156 ) )
continue;
if ( ! V_174 -> V_39 . V_302 ||
F_142 ( V_6 ) ) {
V_177 -> V_303 = V_304 ;
return;
}
if ( ! V_301 ) {
V_177 -> V_303 = V_304 ;
V_301 = true ;
}
} F_16 ( V_23 ) ;
}
void F_147 ( struct V_174 * V_174 , struct V_176 * V_177 ,
struct V_189 * V_190 , const struct V_93 * V_94 )
{
bool V_305 ;
V_305 = ( V_190 -> V_193 == 0 ||
V_190 -> V_306 & V_307 ) ;
#ifdef F_29
if ( V_177 -> V_23 -> V_60 > 1 && V_305 ) {
int V_308 = F_148 ( V_177 -> V_23 , V_190 , V_94 ) ;
F_146 ( V_177 , V_308 ) ;
}
else
#endif
if ( ! V_177 -> V_290 &&
V_177 -> V_288 -> V_309 > 1 &&
V_177 -> type == V_186 && V_305 )
F_136 ( V_190 , V_177 ) ;
if ( ! V_190 -> V_310 )
V_190 -> V_310 = F_149 ( V_174 , * V_177 ) ;
}
