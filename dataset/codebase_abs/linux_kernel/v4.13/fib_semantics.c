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
static int F_76 ( struct V_128 * V_129 , struct V_22 * V_23 ,
struct V_5 * V_6 , struct V_125 * V_126 )
{
int V_98 = 0 ;
struct V_169 * V_169 ;
struct V_73 * V_74 ;
V_169 = V_129 -> V_170 . V_107 ;
if ( V_6 -> V_50 ) {
struct V_171 V_172 ;
if ( V_6 -> V_53 & V_173 ) {
unsigned int V_174 ;
if ( V_129 -> V_175 >= V_176 ) {
F_56 ( V_126 ,
L_6 ) ;
return - V_132 ;
}
V_74 = F_77 ( V_169 , V_6 -> V_49 ) ;
if ( ! V_74 )
return - V_177 ;
if ( ! ( V_74 -> V_178 & V_179 ) ) {
F_56 ( V_126 ,
L_7 ) ;
return - V_180 ;
}
V_174 = F_78 ( V_169 , V_74 , V_6 -> V_50 ) ;
if ( V_174 != V_181 ) {
F_56 ( V_126 ,
L_8 ) ;
return - V_132 ;
}
if ( ! F_79 ( V_74 ) )
V_6 -> V_53 |= V_134 ;
V_6 -> V_28 = V_74 ;
F_80 ( V_74 ) ;
V_6 -> V_51 = V_176 ;
return 0 ;
}
F_81 () ;
{
struct V_182 * V_183 = NULL ;
struct V_184 V_185 = {
. V_186 = V_6 -> V_50 ,
. V_187 = V_129 -> V_175 + 1 ,
. V_188 = V_6 -> V_49 ,
. V_189 = V_190 ,
} ;
if ( V_185 . V_187 < V_176 )
V_185 . V_187 = V_176 ;
if ( V_129 -> V_191 )
V_183 = F_82 ( V_169 , V_129 -> V_191 ) ;
if ( V_183 )
V_98 = F_83 ( V_183 , & V_185 , & V_172 ,
V_192 |
V_193 ) ;
if ( ! V_183 || V_98 ) {
V_98 = F_84 ( V_169 , & V_185 , & V_172 ,
V_192 ) ;
}
if ( V_98 ) {
F_56 ( V_126 ,
L_8 ) ;
F_85 () ;
return V_98 ;
}
}
V_98 = - V_132 ;
if ( V_172 . type != V_181 && V_172 . type != V_194 ) {
F_56 ( V_126 , L_8 ) ;
goto V_195;
}
V_6 -> V_51 = V_172 . V_196 ;
V_6 -> V_49 = F_86 ( V_172 ) ;
V_6 -> V_28 = V_74 = F_87 ( V_172 ) ;
if ( ! V_74 ) {
F_56 ( V_126 ,
L_9 ) ;
goto V_195;
}
F_80 ( V_74 ) ;
if ( ! F_79 ( V_74 ) )
V_6 -> V_53 |= V_134 ;
V_98 = ( V_74 -> V_178 & V_179 ) ? 0 : - V_180 ;
} else {
struct V_152 * V_153 ;
if ( V_6 -> V_53 & ( V_197 | V_173 ) ) {
F_56 ( V_126 ,
L_10 ) ;
return - V_132 ;
}
F_81 () ;
V_98 = - V_177 ;
V_153 = F_88 ( V_169 , V_6 -> V_49 ) ;
if ( ! V_153 )
goto V_195;
V_98 = - V_180 ;
if ( ! ( V_153 -> V_74 -> V_178 & V_179 ) ) {
F_56 ( V_126 , L_11 ) ;
goto V_195;
}
V_6 -> V_28 = V_153 -> V_74 ;
F_80 ( V_6 -> V_28 ) ;
V_6 -> V_51 = V_198 ;
if ( ! F_79 ( V_6 -> V_28 ) )
V_6 -> V_53 |= V_134 ;
V_98 = 0 ;
}
V_195:
F_85 () ;
return V_98 ;
}
static inline unsigned int F_89 ( T_3 V_55 )
{
unsigned int V_56 = ( V_59 - 1 ) ;
return ( ( V_63 V_64 ) V_55 ^
( ( V_63 V_64 ) V_55 >> 7 ) ^
( ( V_63 V_64 ) V_55 >> 14 ) ) & V_56 ;
}
static struct V_67 * F_90 ( int V_199 )
{
if ( V_199 <= V_200 )
return F_91 ( V_199 , V_101 ) ;
else
return (struct V_67 * )
F_92 ( V_101 | V_201 ,
F_93 ( V_199 ) ) ;
}
static void F_94 ( struct V_67 * V_8 , int V_199 )
{
if ( ! V_8 )
return;
if ( V_199 <= V_200 )
F_6 ( V_8 ) ;
else
F_95 ( ( unsigned long ) V_8 , F_93 ( V_199 ) ) ;
}
static void F_96 ( struct V_67 * V_202 ,
struct V_67 * V_203 ,
unsigned int V_204 )
{
struct V_67 * V_205 , * V_206 ;
unsigned int V_207 = V_59 ;
unsigned int V_9 , V_199 ;
F_23 ( & V_41 ) ;
V_205 = V_68 ;
V_206 = V_208 ;
V_59 = V_204 ;
for ( V_9 = 0 ; V_9 < V_207 ; V_9 ++ ) {
struct V_67 * V_21 = & V_68 [ V_9 ] ;
struct V_209 * V_114 ;
struct V_22 * V_23 ;
F_97 (fi, n, head, fib_hash) {
struct V_67 * V_210 ;
unsigned int V_211 ;
V_211 = F_32 ( V_23 ) ;
V_210 = & V_202 [ V_211 ] ;
F_98 ( & V_23 -> V_43 , V_210 ) ;
}
}
V_68 = V_202 ;
for ( V_9 = 0 ; V_9 < V_207 ; V_9 ++ ) {
struct V_67 * V_212 = & V_208 [ V_9 ] ;
struct V_209 * V_114 ;
struct V_22 * V_23 ;
F_97 (fi, n, lhead, fib_lhash) {
struct V_67 * V_213 ;
unsigned int V_211 ;
V_211 = F_89 ( V_23 -> V_44 ) ;
V_213 = & V_203 [ V_211 ] ;
F_98 ( & V_23 -> V_45 , V_213 ) ;
}
}
V_208 = V_203 ;
F_26 ( & V_41 ) ;
V_199 = V_207 * sizeof( struct V_67 * ) ;
F_94 ( V_205 , V_199 ) ;
F_94 ( V_206 , V_199 ) ;
}
T_3 F_99 ( struct V_169 * V_169 , struct V_5 * V_6 )
{
V_6 -> V_214 = F_100 ( V_6 -> V_28 ,
V_6 -> V_50 ,
V_6 -> V_215 -> V_62 ) ;
V_6 -> V_216 = F_101 ( & V_169 -> V_39 . V_217 ) ;
return V_6 -> V_214 ;
}
static bool F_102 ( struct V_128 * V_129 , T_3 V_44 )
{
if ( V_129 -> V_218 != V_194 || ! V_129 -> V_219 ||
V_44 != V_129 -> V_219 ) {
V_64 V_89 = V_129 -> V_191 ;
int V_220 ;
if ( V_89 == V_221 )
V_89 = V_222 ;
V_220 = F_103 ( V_129 -> V_170 . V_107 ,
V_44 , V_89 ) ;
if ( V_220 != V_194 && V_89 != V_222 ) {
V_220 = F_103 ( V_129 -> V_170 . V_107 ,
V_44 , V_222 ) ;
}
if ( V_220 != V_194 )
return false ;
}
return true ;
}
static int
F_104 ( struct V_22 * V_23 , const struct V_128 * V_129 )
{
bool V_223 = false ;
struct V_138 * V_139 ;
int V_124 ;
if ( ! V_129 -> V_224 )
return 0 ;
F_105 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_106 ( V_139 ) ;
V_64 V_55 ;
if ( ! type )
continue;
if ( type > V_70 )
return - V_132 ;
if ( type == V_225 ) {
char V_226 [ V_80 ] ;
F_107 ( V_226 , V_139 , sizeof( V_226 ) ) ;
V_55 = F_108 ( V_226 , & V_223 ) ;
if ( V_55 == V_227 )
return - V_132 ;
} else {
V_55 = F_62 ( V_139 ) ;
}
if ( type == V_228 && V_55 > 65535 - 40 )
V_55 = 65535 - 40 ;
if ( type == V_229 && V_55 > 65535 - 15 )
V_55 = 65535 - 15 ;
if ( type == V_230 && V_55 > 255 )
V_55 = 255 ;
if ( type == V_231 && ( V_55 & ~ V_232 ) )
return - V_132 ;
V_23 -> V_32 -> V_233 [ type - 1 ] = V_55 ;
}
if ( V_223 )
V_23 -> V_32 -> V_233 [ V_231 - 1 ] |= V_234 ;
return 0 ;
}
struct V_22 * F_109 ( struct V_128 * V_129 ,
struct V_125 * V_126 )
{
int V_98 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_47 ;
int V_127 = 1 ;
struct V_169 * V_169 = V_129 -> V_170 . V_107 ;
if ( V_129 -> V_218 > V_235 )
goto V_148;
if ( V_236 [ V_129 -> V_218 ] . V_196 > V_129 -> V_175 ) {
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
unsigned int V_204 = V_59 << 1 ;
struct V_67 * V_202 ;
struct V_67 * V_203 ;
unsigned int V_199 ;
if ( ! V_204 )
V_204 = 16 ;
V_199 = V_204 * sizeof( struct V_67 * ) ;
V_202 = F_90 ( V_199 ) ;
V_203 = F_90 ( V_199 ) ;
if ( ! V_202 || ! V_203 ) {
F_94 ( V_202 , V_199 ) ;
F_94 ( V_203 , V_199 ) ;
} else
F_96 ( V_202 , V_203 , V_204 ) ;
if ( ! V_59 )
goto V_237;
}
V_23 = F_91 ( sizeof( * V_23 ) + V_127 * sizeof( struct V_5 ) , V_101 ) ;
if ( ! V_23 )
goto V_237;
if ( V_129 -> V_224 ) {
V_23 -> V_32 = F_91 ( sizeof( * V_23 -> V_32 ) , V_101 ) ;
if ( F_110 ( ! V_23 -> V_32 ) ) {
F_6 ( V_23 ) ;
return F_111 ( V_98 ) ;
}
F_71 ( & V_23 -> V_32 -> V_34 , 1 ) ;
} else {
V_23 -> V_32 = (struct V_25 * ) & V_33 ;
}
V_36 ++ ;
V_23 -> V_38 = V_169 ;
V_23 -> V_61 = V_129 -> V_238 ;
V_23 -> V_62 = V_129 -> V_175 ;
V_23 -> V_71 = V_129 -> V_135 ;
V_23 -> V_65 = V_129 -> V_162 ;
V_23 -> V_44 = V_129 -> V_239 ;
V_23 -> V_69 = V_129 -> V_218 ;
V_23 -> V_240 = V_129 -> V_191 ;
V_23 -> V_60 = V_127 ;
F_13 (fi) {
V_27 -> V_215 = V_23 ;
V_27 -> V_30 = F_112 (struct rtable __rcu *) ;
if ( ! V_27 -> V_30 )
goto V_237;
} F_16 (fi)
V_98 = F_104 ( V_23 , V_129 ) ;
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
if ( V_236 [ V_129 -> V_218 ] . error ) {
if ( V_129 -> V_164 || V_129 -> V_163 || V_129 -> V_167 ) {
F_56 ( V_126 ,
L_19 ) ;
goto V_148;
}
goto V_242;
} else {
switch ( V_129 -> V_218 ) {
case V_181 :
case V_194 :
case V_243 :
case V_244 :
case V_245 :
break;
default:
F_56 ( V_126 , L_20 ) ;
goto V_148;
}
}
if ( V_129 -> V_175 > V_198 ) {
F_56 ( V_126 , L_12 ) ;
goto V_148;
}
if ( V_129 -> V_175 == V_198 ) {
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
V_6 -> V_28 = F_113 ( V_169 , V_23 -> V_5 -> V_49 ) ;
V_98 = - V_177 ;
if ( ! V_6 -> V_28 )
goto V_237;
} else {
int V_247 = 0 ;
F_13 (fi) {
V_98 = F_76 ( V_129 , V_23 , V_27 , V_126 ) ;
if ( V_98 != 0 )
goto V_237;
if ( V_27 -> V_53 & V_134 )
V_247 ++ ;
} F_16 (fi)
if ( V_247 == V_23 -> V_60 )
V_23 -> V_71 |= V_134 ;
}
if ( V_23 -> V_44 && ! F_102 ( V_129 , V_23 -> V_44 ) ) {
F_56 ( V_126 , L_23 ) ;
goto V_148;
}
F_13 (fi) {
F_99 ( V_169 , V_27 ) ;
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
F_114 ( & V_23 -> V_248 , 1 ) ;
F_23 ( & V_41 ) ;
F_98 ( & V_23 -> V_43 ,
& V_68 [ F_32 ( V_23 ) ] ) ;
if ( V_23 -> V_44 ) {
struct V_67 * V_21 ;
V_21 = & V_208 [ F_89 ( V_23 -> V_44 ) ] ;
F_98 ( & V_23 -> V_45 , V_21 ) ;
}
F_13 (fi) {
struct V_67 * V_21 ;
unsigned int V_8 ;
if ( ! V_27 -> V_28 )
continue;
V_8 = F_31 ( V_27 -> V_28 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
F_98 ( & V_27 -> V_46 , V_21 ) ;
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
return F_111 ( V_98 ) ;
}
int F_45 ( struct V_93 * V_94 , V_64 V_103 , V_64 V_95 , int V_84 ,
V_64 V_89 , T_6 type , T_3 V_4 , int V_88 , T_6 V_249 ,
struct V_22 * V_23 , unsigned int V_178 )
{
struct V_250 * V_96 ;
struct V_79 * V_251 ;
V_96 = F_115 ( V_94 , V_103 , V_95 , V_84 , sizeof( * V_251 ) , V_178 ) ;
if ( ! V_96 )
return - V_106 ;
V_251 = F_116 ( V_96 ) ;
V_251 -> V_252 = V_149 ;
V_251 -> V_253 = V_88 ;
V_251 -> V_254 = 0 ;
V_251 -> V_255 = V_249 ;
if ( V_89 < 256 )
V_251 -> V_256 = V_89 ;
else
V_251 -> V_256 = V_257 ;
if ( F_117 ( V_94 , V_258 , V_89 ) )
goto V_259;
V_251 -> V_260 = type ;
V_251 -> V_261 = V_23 -> V_71 ;
V_251 -> V_262 = V_23 -> V_62 ;
V_251 -> V_263 = V_23 -> V_61 ;
if ( V_251 -> V_253 &&
F_118 ( V_94 , V_264 , V_4 ) )
goto V_259;
if ( V_23 -> V_65 &&
F_117 ( V_94 , V_265 , V_23 -> V_65 ) )
goto V_259;
if ( F_119 ( V_94 , V_23 -> V_32 -> V_233 ) < 0 )
goto V_259;
if ( V_23 -> V_44 &&
F_118 ( V_94 , V_266 , V_23 -> V_44 ) )
goto V_259;
if ( V_23 -> V_60 == 1 ) {
struct V_152 * V_153 ;
if ( V_23 -> V_5 -> V_50 &&
F_118 ( V_94 , V_141 , V_23 -> V_5 -> V_50 ) )
goto V_259;
if ( V_23 -> V_5 -> V_49 &&
F_117 ( V_94 , V_267 , V_23 -> V_5 -> V_49 ) )
goto V_259;
if ( V_23 -> V_5 -> V_53 & V_134 ) {
V_153 = F_68 ( V_23 -> V_5 -> V_28 ) ;
if ( V_153 &&
F_69 ( V_153 ) )
V_251 -> V_261 |= V_77 ;
}
#ifdef F_20
if ( V_23 -> V_5 [ 0 ] . V_37 &&
F_117 ( V_94 , V_142 , V_23 -> V_5 [ 0 ] . V_37 ) )
goto V_259;
#endif
if ( V_23 -> V_5 -> V_29 &&
F_120 ( V_94 , V_23 -> V_5 -> V_29 ) < 0 )
goto V_259;
}
#ifdef F_29
if ( V_23 -> V_60 > 1 ) {
struct V_83 * V_123 ;
struct V_138 * V_268 ;
V_268 = F_121 ( V_94 , V_269 ) ;
if ( ! V_268 )
goto V_259;
F_28 (fi) {
struct V_152 * V_153 ;
V_123 = F_122 ( V_94 , sizeof( * V_123 ) ) ;
if ( ! V_123 )
goto V_259;
V_123 -> V_133 = V_6 -> V_53 & 0xFF ;
if ( V_6 -> V_53 & V_134 ) {
V_153 = F_68 ( V_6 -> V_28 ) ;
if ( V_153 &&
F_69 ( V_153 ) )
V_123 -> V_133 |= V_77 ;
}
V_123 -> V_137 = V_6 -> V_52 - 1 ;
V_123 -> V_136 = V_6 -> V_49 ;
if ( V_6 -> V_50 &&
F_118 ( V_94 , V_141 , V_6 -> V_50 ) )
goto V_259;
#ifdef F_20
if ( V_6 -> V_37 &&
F_117 ( V_94 , V_142 , V_6 -> V_37 ) )
goto V_259;
#endif
if ( V_6 -> V_29 &&
F_120 ( V_94 , V_6 -> V_29 ) < 0 )
goto V_259;
V_123 -> V_270 = F_123 ( V_94 ) - ( void * ) V_123 ;
} F_16 ( V_23 ) ;
F_124 ( V_94 , V_268 ) ;
}
#endif
F_125 ( V_94 , V_96 ) ;
return 0 ;
V_259:
F_126 ( V_94 , V_96 ) ;
return - V_106 ;
}
int F_127 ( struct V_73 * V_74 , T_3 V_271 )
{
int V_130 = 0 ;
unsigned int V_8 = F_89 ( V_271 ) ;
struct V_67 * V_21 = & V_208 [ V_8 ] ;
struct V_169 * V_169 = F_128 ( V_74 ) ;
int V_89 = F_129 ( V_74 ) ;
struct V_22 * V_23 ;
if ( ! V_208 || V_271 == 0 )
return 0 ;
F_34 (fi, head, fib_lhash) {
if ( ! F_35 ( V_23 -> V_38 , V_169 ) ||
V_23 -> V_240 != V_89 )
continue;
if ( V_23 -> V_44 == V_271 ) {
V_23 -> V_71 |= V_77 ;
V_130 ++ ;
}
}
return V_130 ;
}
static int F_130 ( struct V_5 * V_5 ,
enum V_272 V_273 )
{
struct V_152 * V_153 = F_68 ( V_5 -> V_28 ) ;
struct V_274 V_91 = {
. V_5 = V_5 ,
} ;
switch ( V_273 ) {
case V_275 :
if ( V_5 -> V_53 & V_77 )
break;
if ( F_69 ( V_153 ) &&
V_5 -> V_53 & V_134 )
break;
return F_131 ( F_128 ( V_5 -> V_28 ) , V_273 ,
& V_91 . V_91 ) ;
case V_276 :
if ( ( V_153 && F_69 ( V_153 ) &&
V_5 -> V_53 & V_134 ) ||
( V_5 -> V_53 & V_77 ) )
return F_131 ( F_128 ( V_5 -> V_28 ) ,
V_273 , & V_91 . V_91 ) ;
default:
break;
}
return V_277 ;
}
int F_132 ( struct V_73 * V_74 , unsigned long V_84 , bool V_278 )
{
int V_130 = 0 ;
int V_196 = V_246 ;
struct V_22 * V_279 = NULL ;
unsigned int V_8 = F_31 ( V_74 -> V_75 ) ;
struct V_67 * V_21 = & V_76 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_278 )
V_196 = - 1 ;
F_34 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_215 ;
int V_280 ;
F_133 ( ! V_23 -> V_60 ) ;
if ( V_6 -> V_28 != V_74 || V_23 == V_279 )
continue;
V_279 = V_23 ;
V_280 = 0 ;
F_13 (fi) {
if ( V_27 -> V_53 & V_77 )
V_280 ++ ;
else if ( V_27 -> V_28 == V_74 &&
V_27 -> V_51 != V_196 ) {
switch ( V_84 ) {
case V_281 :
case V_282 :
V_27 -> V_53 |= V_77 ;
case V_283 :
V_27 -> V_53 |= V_134 ;
break;
}
F_130 ( V_27 ,
V_276 ) ;
V_280 ++ ;
}
#ifdef F_29
if ( V_84 == V_282 &&
V_27 -> V_28 == V_74 ) {
V_280 = V_23 -> V_60 ;
break;
}
#endif
} F_16 (fi)
if ( V_280 == V_23 -> V_60 ) {
switch ( V_84 ) {
case V_281 :
case V_282 :
V_23 -> V_71 |= V_77 ;
case V_283 :
V_23 -> V_71 |= V_134 ;
break;
}
V_130 ++ ;
}
F_67 ( V_23 ) ;
}
return V_130 ;
}
static void F_134 ( const struct V_184 * V_284 , struct V_171 * V_172 )
{
struct V_22 * V_23 = NULL , * V_110 = NULL ;
struct V_67 * V_285 = V_172 -> V_285 ;
struct V_182 * V_286 = V_172 -> V_287 ;
T_6 V_288 = 32 - V_172 -> V_289 ;
int V_109 = - 1 , V_111 = - 1 ;
struct V_86 * V_87 , * V_290 = NULL ;
V_64 V_291 = V_172 -> V_23 -> V_65 ;
T_6 V_292 = 0 ;
F_135 (fa, fa_head, fa_list) {
struct V_22 * V_293 = V_87 -> V_100 ;
if ( V_87 -> V_294 != V_288 )
continue;
if ( V_87 -> V_105 && V_87 -> V_105 != V_284 -> V_295 )
continue;
if ( V_87 -> V_89 != V_286 -> V_89 )
continue;
if ( V_293 -> V_65 > V_291 &&
V_87 -> V_105 == V_292 ) {
if ( V_292 )
continue;
break;
}
if ( V_293 -> V_71 & V_77 )
continue;
V_292 = V_87 -> V_105 ;
V_291 = V_293 -> V_65 ;
if ( V_293 -> V_62 != V_172 -> V_196 ||
V_87 -> V_104 != V_181 )
continue;
if ( ! V_293 -> V_5 [ 0 ] . V_50 ||
V_293 -> V_5 [ 0 ] . V_51 != V_176 )
continue;
F_136 ( V_87 ) ;
if ( ! V_23 ) {
if ( V_293 != V_172 -> V_23 )
break;
V_290 = V_87 ;
} else if ( ! F_50 ( V_23 , V_109 , & V_110 ,
& V_111 , V_290 -> V_296 ) ) {
F_137 ( V_172 , V_23 ) ;
V_290 -> V_296 = V_109 ;
goto V_195;
}
V_23 = V_293 ;
V_109 ++ ;
}
if ( V_109 <= 0 || ! V_23 ) {
if ( V_290 )
V_290 -> V_296 = - 1 ;
goto V_195;
}
if ( ! F_50 ( V_23 , V_109 , & V_110 , & V_111 ,
V_290 -> V_296 ) ) {
F_137 ( V_172 , V_23 ) ;
V_290 -> V_296 = V_109 ;
goto V_195;
}
if ( V_111 >= 0 )
F_137 ( V_172 , V_110 ) ;
V_290 -> V_296 = V_111 ;
V_195:
return;
}
int F_138 ( struct V_73 * V_74 , unsigned int V_53 )
{
struct V_22 * V_279 ;
unsigned int V_8 ;
struct V_67 * V_21 ;
struct V_5 * V_6 ;
int V_130 ;
if ( ! ( V_74 -> V_178 & V_179 ) )
return 0 ;
if ( V_53 & V_77 ) {
unsigned int V_178 = F_139 ( V_74 ) ;
if ( V_178 & ( V_297 | V_298 ) )
V_53 |= V_134 ;
}
V_279 = NULL ;
V_8 = F_31 ( V_74 -> V_75 ) ;
V_21 = & V_76 [ V_8 ] ;
V_130 = 0 ;
F_34 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_215 ;
int V_299 ;
F_133 ( ! V_23 -> V_60 ) ;
if ( V_6 -> V_28 != V_74 || V_23 == V_279 )
continue;
V_279 = V_23 ;
V_299 = 0 ;
F_13 (fi) {
if ( ! ( V_27 -> V_53 & V_53 ) ) {
V_299 ++ ;
continue;
}
if ( ! V_27 -> V_28 ||
! ( V_27 -> V_28 -> V_178 & V_179 ) )
continue;
if ( V_27 -> V_28 != V_74 ||
! F_68 ( V_74 ) )
continue;
V_299 ++ ;
V_27 -> V_53 &= ~ V_53 ;
F_130 ( V_27 , V_275 ) ;
} F_16 (fi)
if ( V_299 > 0 ) {
V_23 -> V_71 &= ~ V_53 ;
V_130 ++ ;
}
F_67 ( V_23 ) ;
}
return V_130 ;
}
static bool F_140 ( const struct V_5 * V_6 )
{
int V_115 = V_120 ;
if ( V_6 -> V_51 == V_176 ) {
struct V_113 * V_114 ;
F_141 () ;
V_114 = F_142 ( V_6 -> V_28 ,
( V_63 V_64 ) V_6 -> V_50 ) ;
if ( V_114 )
V_115 = V_114 -> V_119 ;
F_143 () ;
}
return ! ! ( V_115 & V_121 ) ;
}
void F_144 ( struct V_171 * V_172 , int V_8 )
{
struct V_22 * V_23 = V_172 -> V_23 ;
struct V_169 * V_169 = V_23 -> V_38 ;
bool V_300 = false ;
F_28 (fi) {
if ( V_8 > F_101 ( & V_6 -> V_156 ) )
continue;
if ( ! V_169 -> V_39 . V_301 ||
F_140 ( V_6 ) ) {
V_172 -> V_302 = V_303 ;
return;
}
if ( ! V_300 ) {
V_172 -> V_302 = V_303 ;
V_300 = true ;
}
} F_16 ( V_23 ) ;
}
void F_145 ( struct V_169 * V_169 , struct V_171 * V_172 ,
struct V_184 * V_185 , const struct V_93 * V_94 )
{
bool V_304 ;
V_304 = ( V_185 -> V_188 == 0 ||
V_185 -> V_305 & V_306 ) ;
#ifdef F_29
if ( V_172 -> V_23 -> V_60 > 1 && V_304 ) {
int V_307 = F_146 ( V_172 -> V_23 , V_185 , V_94 ) ;
F_144 ( V_172 , V_307 ) ;
}
else
#endif
if ( ! V_172 -> V_289 &&
V_172 -> V_287 -> V_308 > 1 &&
V_172 -> type == V_181 && V_304 )
F_134 ( V_185 , V_172 ) ;
if ( ! V_185 -> V_309 )
V_185 -> V_309 = F_147 ( V_169 , * V_172 ) ;
}
