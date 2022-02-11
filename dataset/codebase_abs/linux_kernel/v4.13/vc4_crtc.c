static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static inline struct V_4 *
F_2 ( struct V_5 * V_6 )
{
return (struct V_4 * ) V_6 ;
}
static void F_3 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
F_5 ( L_1 ,
V_8 [ V_7 ] . V_9 , V_8 [ V_7 ] . V_10 ,
F_6 ( V_8 [ V_7 ] . V_9 ) ) ;
}
}
int F_7 ( struct V_11 * V_12 , void * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_12 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_19 -> V_18 ;
int V_20 = ( V_21 ) V_15 -> V_22 -> V_23 ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
int V_7 ;
V_7 = 0 ;
F_8 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_7 == V_20 )
break;
V_7 ++ ;
}
if ( ! V_3 )
return 0 ;
V_1 = F_1 ( V_3 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
F_9 ( V_12 , L_2 ,
V_8 [ V_7 ] . V_10 , V_8 [ V_7 ] . V_9 ,
F_6 ( V_8 [ V_7 ] . V_9 ) ) ;
}
return 0 ;
}
bool F_10 ( struct V_17 * V_18 , unsigned int V_24 ,
bool V_25 , int * V_26 , int * V_27 ,
T_1 * V_28 , T_1 * V_29 ,
const struct V_30 * V_31 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_2 * V_3 = F_12 ( V_18 , V_24 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_34 ;
int V_35 ;
int V_36 ;
bool V_37 = false ;
if ( V_28 )
* V_28 = F_13 () ;
V_34 = F_14 ( F_15 ( V_1 -> V_38 ) ) ;
if ( V_29 )
* V_29 = F_13 () ;
* V_26 = F_16 ( V_34 , V_39 ) ;
* V_27 = 0 ;
if ( V_31 -> V_40 & V_41 ) {
* V_26 /= 2 ;
if ( F_16 ( V_34 , V_42 ) % 2 )
* V_27 += V_31 -> V_43 / 2 ;
}
V_35 = V_1 -> V_44 / V_31 -> V_45 ;
if ( V_35 > 0 )
V_37 = true ;
if ( * V_26 > V_35 ) {
* V_26 -= V_35 + 1 ;
return V_37 ;
}
V_36 = V_31 -> V_46 - V_31 -> V_47 ;
if ( V_25 ) {
* V_26 = - V_36 ;
if ( V_28 )
* V_28 = V_1 -> V_48 ;
if ( V_29 )
* V_29 = V_1 -> V_48 ;
} else {
* V_26 = 0 ;
}
return V_37 ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_18 ( V_3 ) ;
}
static void
F_19 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_7 ;
F_20 ( V_49 ,
V_50 |
( V_1 -> V_38 * 3 * V_3 -> V_51 ) ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_51 ; V_7 ++ )
F_20 ( V_52 , V_1 -> V_53 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_51 ; V_7 ++ )
F_20 ( V_52 , V_1 -> V_54 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_51 ; V_7 ++ )
F_20 ( V_52 , V_1 -> V_55 [ V_7 ] ) ;
}
static int
F_21 ( struct V_2 * V_3 , T_3 * V_56 , T_3 * V_57 , T_3 * V_58 ,
T_4 V_59 ,
struct V_60 * V_61 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_7 ;
for ( V_7 = 0 ; V_7 < V_59 ; V_7 ++ ) {
V_1 -> V_53 [ V_7 ] = V_56 [ V_7 ] >> 8 ;
V_1 -> V_54 [ V_7 ] = V_57 [ V_7 ] >> 8 ;
V_1 -> V_55 [ V_7 ] = V_58 [ V_7 ] >> 8 ;
}
F_19 ( V_3 ) ;
return 0 ;
}
static T_2 F_22 ( T_2 V_62 )
{
static const T_2 V_63 = 64 ;
static const T_2 V_64 = 6 ;
switch ( V_62 ) {
case V_65 :
case V_66 :
return V_63 - 2 * V_64 ;
case V_67 :
return V_63 - 14 ;
case V_68 :
case V_69 :
default:
return V_63 - 3 * V_64 ;
}
}
static struct V_70 * F_23 ( struct V_2 * V_3 )
{
struct V_71 * V_72 ;
struct V_73 V_74 ;
F_24 ( V_3 -> V_18 , & V_74 ) ;
F_25 (connector, &conn_iter) {
if ( V_72 -> V_75 -> V_3 == V_3 ) {
F_26 ( & V_74 ) ;
return V_72 -> V_76 ;
}
}
F_26 ( & V_74 ) ;
return NULL ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_70 * V_76 = F_23 ( V_3 ) ;
struct V_77 * V_77 = F_28 ( V_76 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_75 = V_3 -> V_75 ;
struct V_30 * V_31 = & V_75 -> V_78 ;
bool V_79 = V_31 -> V_40 & V_41 ;
T_2 V_80 = ( V_31 -> V_40 & V_81 ) ? 2 : 1 ;
bool V_82 = ( V_77 -> type == V_83 ||
V_77 -> type == V_84 ) ;
T_2 V_62 = V_82 ? V_69 : V_68 ;
bool V_85 = false ;
if ( V_85 ) {
F_5 ( L_3 , F_29 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
F_30 ( V_86 , 0 ) ;
F_30 ( V_86 , V_87 | V_88 ) ;
F_30 ( V_86 , 0 ) ;
F_30 ( V_89 ,
F_31 ( ( V_31 -> V_90 -
V_31 -> V_91 ) * V_80 ,
V_92 ) |
F_31 ( ( V_31 -> V_91 -
V_31 -> V_93 ) * V_80 ,
V_94 ) ) ;
F_30 ( V_95 ,
F_31 ( ( V_31 -> V_93 -
V_31 -> V_96 ) * V_80 ,
V_97 ) |
F_31 ( V_31 -> V_96 * V_80 , V_98 ) ) ;
F_30 ( V_99 ,
F_31 ( V_31 -> V_100 - V_31 -> V_101 ,
V_102 ) |
F_31 ( V_31 -> V_101 - V_31 -> V_103 ,
V_104 ) ) ;
F_30 ( V_105 ,
F_31 ( V_31 -> V_103 - V_31 -> V_106 ,
V_107 ) |
F_31 ( V_31 -> V_106 , V_108 ) ) ;
if ( V_79 ) {
F_30 ( V_109 ,
F_31 ( V_31 -> V_100 -
V_31 -> V_101 - 1 ,
V_102 ) |
F_31 ( V_31 -> V_101 -
V_31 -> V_103 ,
V_104 ) ) ;
F_30 ( V_110 ,
F_31 ( V_31 -> V_103 -
V_31 -> V_106 ,
V_107 ) |
F_31 ( V_31 -> V_106 , V_108 ) ) ;
F_30 ( V_111 ,
V_112 |
( V_82 ? V_113 : 0 ) |
V_114 |
F_31 ( V_31 -> V_90 * V_80 / 2 ,
V_115 ) ) ;
F_30 ( V_116 , 0 ) ;
} else {
F_30 ( V_111 ,
V_112 |
( V_82 ? V_113 : 0 ) ) ;
}
F_30 ( V_117 , V_31 -> V_96 * V_80 ) ;
F_30 ( V_86 ,
F_31 ( V_62 , V_118 ) |
F_31 ( F_22 ( V_62 ) ,
V_119 ) |
F_31 ( V_80 - 1 , V_120 ) |
V_121 |
V_122 |
V_123 |
F_31 ( V_77 -> V_124 ,
V_125 ) |
V_87 |
V_88 ) ;
F_20 ( F_32 ( V_1 -> V_38 ) ,
V_126 |
V_127 |
( V_79 ? V_128 : 0 ) ) ;
F_19 ( V_3 ) ;
if ( V_85 ) {
F_5 ( L_4 , F_29 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
}
static void F_33 ( struct V_17 * V_18 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
F_34 ( ( F_14 ( V_129 ) & V_130 ) !=
V_130 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_131 = V_1 -> V_38 ;
int V_37 ;
F_33 ( V_18 ) ;
F_36 ( V_3 ) ;
F_30 ( V_111 ,
F_6 ( V_111 ) & ~ V_132 ) ;
V_37 = F_37 ( ! ( F_6 ( V_111 ) & V_132 ) , 1 ) ;
F_38 ( V_37 , L_5 ) ;
if ( F_14 ( F_39 ( V_131 ) ) &
V_133 ) {
F_20 ( F_39 ( V_131 ) ,
V_134 ) ;
F_20 ( F_39 ( V_131 ) , 0 ) ;
}
F_34 ( F_14 ( F_39 ( V_131 ) ) & V_134 ) ;
F_34 ( F_16 ( F_14 ( F_15 ( V_131 ) ) ,
V_135 ) !=
V_136 ) ;
F_34 ( ( F_14 ( F_15 ( V_131 ) ) &
( V_137 | V_138 ) ) !=
V_138 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_139 = F_2 ( V_3 -> V_75 ) ;
if ( V_3 -> V_75 -> V_140 ) {
unsigned long V_40 ;
V_3 -> V_75 -> V_140 -> V_141 = F_29 ( V_3 ) ;
F_41 ( F_42 ( V_3 ) != 0 ) ;
F_43 ( & V_18 -> V_142 , V_40 ) ;
V_1 -> V_140 = V_3 -> V_75 -> V_140 ;
V_3 -> V_75 -> V_140 = NULL ;
F_20 ( F_44 ( V_1 -> V_38 ) ,
V_139 -> V_143 . V_144 ) ;
F_45 ( & V_18 -> V_142 , V_40 ) ;
} else {
F_20 ( F_44 ( V_1 -> V_38 ) ,
V_139 -> V_143 . V_144 ) ;
}
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_75 = V_3 -> V_75 ;
struct V_30 * V_31 = & V_75 -> V_78 ;
F_33 ( V_18 ) ;
F_47 ( V_3 ) ;
F_40 ( V_3 ) ;
F_20 ( F_39 ( V_1 -> V_38 ) ,
F_31 ( V_31 -> V_96 , V_145 ) |
F_31 ( V_31 -> V_47 , V_146 ) |
V_133 ) ;
F_30 ( V_111 ,
F_6 ( V_111 ) | V_132 ) ;
}
static bool F_48 ( struct V_2 * V_3 ,
const struct V_30 * V_31 ,
struct V_30 * V_78 )
{
if ( V_78 -> V_40 & V_147 ) {
F_49 ( L_6 ,
V_3 -> V_148 . V_149 ) ;
return false ;
}
return true ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_5 * V_75 )
{
struct V_4 * V_139 = F_2 ( V_75 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_150 * V_151 ;
unsigned long V_40 ;
const struct V_152 * V_153 ;
T_2 V_154 = 0 ;
int V_37 ;
if ( F_51 ( V_75 -> V_155 ) > 1 )
return - V_156 ;
F_52 (plane, plane_state, state)
V_154 += F_53 ( V_153 ) ;
V_154 ++ ;
F_43 ( & V_33 -> V_157 -> V_158 , V_40 ) ;
V_37 = F_54 ( & V_33 -> V_157 -> V_159 , & V_139 -> V_143 ,
V_154 ) ;
F_45 ( & V_33 -> V_157 -> V_158 , V_40 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_5 * V_160 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_4 * V_139 = F_2 ( V_3 -> V_75 ) ;
struct V_150 * V_151 ;
bool V_85 = false ;
T_2 T_5 * V_161 = V_33 -> V_157 -> V_162 + V_139 -> V_143 . V_144 ;
T_2 T_5 * V_163 = V_161 ;
if ( V_85 ) {
F_5 ( L_7 , F_29 ( V_3 ) ) ;
F_56 ( V_18 ) ;
}
F_57 (plane, crtc) {
V_163 += F_58 ( V_151 , V_163 ) ;
}
F_59 ( V_164 , V_163 ) ;
V_163 ++ ;
F_34 ( V_163 - V_161 != V_139 -> V_143 . V_59 ) ;
if ( V_3 -> V_75 -> V_165 && V_160 -> V_165 )
F_40 ( V_3 ) ;
if ( V_85 ) {
F_5 ( L_8 , F_29 ( V_3 ) ) ;
F_56 ( V_18 ) ;
}
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_30 ( V_166 , V_167 ) ;
return 0 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_30 ( V_166 , 0 ) ;
}
bool F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ! ! V_1 -> V_140 ;
}
static void F_63 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_148 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_4 * V_139 = F_2 ( V_3 -> V_75 ) ;
T_2 V_131 = V_1 -> V_38 ;
unsigned long V_40 ;
F_43 ( & V_18 -> V_142 , V_40 ) ;
if ( V_1 -> V_140 &&
( V_139 -> V_143 . V_144 == F_14 ( F_64 ( V_131 ) ) ) ) {
F_65 ( V_3 , V_1 -> V_140 ) ;
V_1 -> V_140 = NULL ;
F_66 ( V_3 ) ;
}
F_45 ( & V_18 -> V_142 , V_40 ) ;
}
static T_6 F_67 ( int V_168 , void * V_23 )
{
struct V_1 * V_1 = V_23 ;
T_2 V_169 = F_6 ( V_170 ) ;
T_6 V_37 = V_171 ;
if ( V_169 & V_167 ) {
V_1 -> V_48 = F_13 () ;
F_30 ( V_170 , V_167 ) ;
F_68 ( & V_1 -> V_148 ) ;
F_63 ( V_1 ) ;
V_37 = V_172 ;
}
return V_37 ;
}
static void
F_69 ( struct V_173 * V_174 )
{
struct V_175 * V_176 =
F_70 ( V_174 , struct V_175 , V_174 ) ;
struct V_2 * V_3 = V_176 -> V_3 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_150 * V_151 = V_3 -> V_177 ;
F_71 ( V_151 , V_176 -> V_178 ) ;
if ( V_176 -> V_140 ) {
unsigned long V_40 ;
F_43 ( & V_18 -> V_142 , V_40 ) ;
F_65 ( V_3 , V_176 -> V_140 ) ;
F_45 ( & V_18 -> V_142 , V_40 ) ;
}
F_66 ( V_3 ) ;
F_72 ( V_176 -> V_178 ) ;
F_73 ( V_176 ) ;
F_74 ( & V_33 -> V_179 ) ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_180 * V_178 ,
struct V_181 * V_140 ,
T_4 V_40 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_150 * V_151 = V_3 -> V_177 ;
int V_37 = 0 ;
struct V_175 * V_176 ;
struct V_182 * V_183 = F_76 ( V_178 , 0 ) ;
struct V_184 * V_185 = F_77 ( & V_183 -> V_148 ) ;
V_176 = F_78 ( sizeof( * V_176 ) , V_186 ) ;
if ( ! V_176 )
return - V_187 ;
F_79 ( V_178 ) ;
V_176 -> V_178 = V_178 ;
V_176 -> V_3 = V_3 ;
V_176 -> V_140 = V_140 ;
V_37 = F_80 ( & V_33 -> V_179 ) ;
if ( V_37 ) {
F_72 ( V_178 ) ;
F_73 ( V_176 ) ;
return V_37 ;
}
F_41 ( F_42 ( V_3 ) != 0 ) ;
F_81 ( V_151 -> V_75 , V_178 ) ;
V_151 -> V_178 = V_178 ;
F_82 ( V_18 , & V_176 -> V_174 , V_185 -> V_188 ,
F_69 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 ,
struct V_180 * V_178 ,
struct V_181 * V_140 ,
T_4 V_40 ,
struct V_60 * V_61 )
{
if ( V_40 & V_189 )
return F_75 ( V_3 , V_178 , V_140 , V_40 ) ;
else
return F_84 ( V_3 , V_178 , V_140 , V_40 , V_61 ) ;
}
static struct V_5 * F_85 ( struct V_2 * V_3 )
{
struct V_4 * V_139 ;
V_139 = F_78 ( sizeof( * V_139 ) , V_186 ) ;
if ( ! V_139 )
return NULL ;
F_86 ( V_3 , & V_139 -> V_148 ) ;
return & V_139 -> V_148 ;
}
static void F_87 ( struct V_2 * V_3 ,
struct V_5 * V_75 )
{
struct V_32 * V_33 = F_11 ( V_3 -> V_18 ) ;
struct V_4 * V_139 = F_2 ( V_75 ) ;
if ( V_139 -> V_143 . V_190 ) {
unsigned long V_40 ;
F_43 ( & V_33 -> V_157 -> V_158 , V_40 ) ;
F_88 ( & V_139 -> V_143 ) ;
F_45 ( & V_33 -> V_157 -> V_158 , V_40 ) ;
}
F_89 ( V_3 , V_75 ) ;
}
static void
F_90 ( struct V_2 * V_3 )
{
if ( V_3 -> V_75 )
F_91 ( V_3 -> V_75 ) ;
V_3 -> V_75 = F_78 ( sizeof( struct V_4 ) , V_186 ) ;
if ( V_3 -> V_75 )
V_3 -> V_75 -> V_3 = V_3 ;
}
static void F_92 ( struct V_17 * V_191 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_192 * V_193 = V_1 -> V_23 ;
const enum V_194 * V_195 = V_193 -> V_195 ;
struct V_70 * V_76 ;
F_93 (encoder, drm) {
struct V_77 * V_77 = F_28 ( V_76 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_193 -> V_195 ) ; V_7 ++ ) {
if ( V_77 -> type == V_195 [ V_7 ] ) {
V_77 -> V_124 = V_7 ;
V_76 -> V_196 |= F_94 ( V_3 ) ;
break;
}
}
}
}
static void
F_95 ( struct V_1 * V_1 )
{
struct V_17 * V_191 = V_1 -> V_148 . V_18 ;
struct V_32 * V_33 = F_11 ( V_191 ) ;
T_2 V_197 = F_14 ( F_96 ( V_1 -> V_38 ) ) ;
T_2 V_198 = F_16 ( V_197 , V_199 ) & ~ 3 ;
T_2 V_148 = F_16 ( V_197 , V_200 ) & ~ 3 ;
V_1 -> V_44 = V_198 - V_148 + 4 ;
}
static int F_97 ( struct V_201 * V_18 , struct V_201 * V_202 , void * V_23 )
{
struct V_203 * V_204 = F_98 ( V_18 ) ;
struct V_17 * V_191 = F_99 ( V_202 ) ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_150 * V_205 , * V_206 , * V_207 , * V_208 ;
const struct V_209 * V_210 ;
int V_37 , V_7 ;
V_1 = F_100 ( V_18 , sizeof( * V_1 ) , V_186 ) ;
if ( ! V_1 )
return - V_187 ;
V_3 = & V_1 -> V_148 ;
V_210 = F_101 ( V_211 , V_18 ) ;
if ( ! V_210 )
return - V_212 ;
V_1 -> V_23 = V_210 -> V_23 ;
V_1 -> V_213 = F_102 ( V_204 , 0 ) ;
if ( F_103 ( V_1 -> V_213 ) )
return F_104 ( V_1 -> V_213 ) ;
V_205 = F_105 ( V_191 , V_214 ) ;
if ( F_103 ( V_205 ) ) {
F_106 ( V_18 , L_9 ) ;
V_37 = F_104 ( V_205 ) ;
goto V_215;
}
F_107 ( V_191 , V_3 , V_205 , NULL ,
& V_216 , NULL ) ;
F_108 ( V_3 , & V_217 ) ;
V_205 -> V_3 = V_3 ;
V_1 -> V_38 = V_1 -> V_23 -> V_218 ;
F_109 ( V_3 , F_4 ( V_1 -> V_53 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
struct V_150 * V_151 =
F_105 ( V_191 , V_219 ) ;
if ( F_103 ( V_151 ) )
continue;
V_151 -> V_196 = 1 << F_29 ( V_3 ) ;
}
V_206 = F_105 ( V_191 , V_220 ) ;
if ( ! F_103 ( V_206 ) ) {
V_206 -> V_196 = 1 << F_29 ( V_3 ) ;
V_206 -> V_3 = V_3 ;
V_3 -> V_221 = V_206 ;
}
F_95 ( V_1 ) ;
F_30 ( V_166 , 0 ) ;
F_30 ( V_170 , V_167 ) ;
V_37 = F_110 ( V_18 , F_111 ( V_204 , 0 ) ,
F_67 , 0 , L_10 , V_1 ) ;
if ( V_37 )
goto V_222;
F_92 ( V_191 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_51 ; V_7 ++ ) {
V_1 -> V_53 [ V_7 ] = V_7 ;
V_1 -> V_54 [ V_7 ] = V_7 ;
V_1 -> V_55 [ V_7 ] = V_7 ;
}
F_112 ( V_204 , V_1 ) ;
return 0 ;
V_222:
F_113 (destroy_plane, temp,
&drm->mode_config.plane_list, head) {
if ( V_207 -> V_196 == 1 << F_29 ( V_3 ) )
V_207 -> V_223 -> V_224 ( V_207 ) ;
}
V_215:
return V_37 ;
}
static void F_114 ( struct V_201 * V_18 , struct V_201 * V_202 ,
void * V_23 )
{
struct V_203 * V_204 = F_98 ( V_18 ) ;
struct V_1 * V_1 = F_99 ( V_18 ) ;
F_17 ( & V_1 -> V_148 ) ;
F_30 ( V_166 , 0 ) ;
F_112 ( V_204 , NULL ) ;
}
static int F_115 ( struct V_203 * V_204 )
{
return F_116 ( & V_204 -> V_18 , & V_225 ) ;
}
static int F_117 ( struct V_203 * V_204 )
{
F_118 ( & V_204 -> V_18 , & V_225 ) ;
return 0 ;
}
