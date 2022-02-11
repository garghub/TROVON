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
int F_10 ( struct V_17 * V_18 , unsigned int V_24 ,
unsigned int V_25 , int * V_26 , int * V_27 ,
T_1 * V_28 , T_1 * V_29 ,
const struct V_30 * V_31 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_2 * V_3 = F_12 ( V_18 , V_24 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_34 ;
int V_35 ;
int V_36 ;
int V_37 = 0 ;
if ( V_28 )
* V_28 = F_13 () ;
V_34 = F_14 ( F_15 ( V_1 -> V_38 ) ) ;
if ( V_29 )
* V_29 = F_13 () ;
* V_26 = F_16 ( V_34 , V_39 ) ;
* V_27 = 0 ;
if ( V_31 -> V_25 & V_40 ) {
* V_26 /= 2 ;
if ( F_16 ( V_34 , V_41 ) % 2 )
* V_27 += V_31 -> V_42 / 2 ;
}
V_35 = V_1 -> V_43 / V_31 -> V_44 ;
if ( V_35 > 0 )
V_37 |= V_45 ;
if ( * V_26 > V_35 ) {
* V_26 -= V_35 + 1 ;
V_37 |= V_46 ;
return V_37 ;
}
V_37 |= V_47 ;
V_36 = V_31 -> V_48 - V_31 -> V_49 ;
if ( V_25 & V_50 ) {
* V_26 = - V_36 ;
if ( V_28 )
* V_28 = V_1 -> V_51 ;
if ( V_29 )
* V_29 = V_1 -> V_51 ;
if ( ( V_34 & V_52 ) != V_52 )
V_37 |= V_46 ;
} else {
* V_26 = 0 ;
}
return V_37 ;
}
int F_17 ( struct V_17 * V_18 , unsigned int V_24 ,
int * V_53 , struct V_54 * V_55 ,
unsigned V_25 )
{
struct V_2 * V_3 = F_12 ( V_18 , V_24 ) ;
struct V_5 * V_56 = V_3 -> V_56 ;
return F_18 ( V_18 , V_24 , V_53 ,
V_55 , V_25 ,
& V_56 -> V_57 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
F_20 ( V_3 ) ;
}
static void
F_21 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_7 ;
F_22 ( V_58 ,
V_59 |
( V_1 -> V_38 * 3 * V_3 -> V_60 ) ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_60 ; V_7 ++ )
F_22 ( V_61 , V_1 -> V_62 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_60 ; V_7 ++ )
F_22 ( V_61 , V_1 -> V_63 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_60 ; V_7 ++ )
F_22 ( V_61 , V_1 -> V_64 [ V_7 ] ) ;
}
static int
F_23 ( struct V_2 * V_3 , T_3 * V_65 , T_3 * V_66 , T_3 * V_67 ,
T_4 V_68 ,
struct V_69 * V_70 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_7 ;
for ( V_7 = 0 ; V_7 < V_68 ; V_7 ++ ) {
V_1 -> V_62 [ V_7 ] = V_65 [ V_7 ] >> 8 ;
V_1 -> V_63 [ V_7 ] = V_66 [ V_7 ] >> 8 ;
V_1 -> V_64 [ V_7 ] = V_67 [ V_7 ] >> 8 ;
}
F_21 ( V_3 ) ;
return 0 ;
}
static T_2 F_24 ( T_2 V_71 )
{
static const T_2 V_72 = 64 ;
static const T_2 V_73 = 6 ;
switch ( V_71 ) {
case V_74 :
case V_75 :
return V_72 - 2 * V_73 ;
case V_76 :
return V_72 - 14 ;
case V_77 :
case V_78 :
default:
return V_72 - 3 * V_73 ;
}
}
static struct V_79 * F_25 ( struct V_2 * V_3 )
{
struct V_80 * V_81 ;
F_26 (connector, crtc->dev) {
if ( V_81 -> V_56 -> V_3 == V_3 ) {
return V_81 -> V_82 ;
}
}
return NULL ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_79 * V_82 = F_25 ( V_3 ) ;
struct V_83 * V_83 = F_28 ( V_82 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_56 = V_3 -> V_56 ;
struct V_30 * V_31 = & V_56 -> V_57 ;
bool V_84 = V_31 -> V_25 & V_40 ;
T_2 V_85 = ( V_31 -> V_25 & V_86 ) ? 2 : 1 ;
bool V_87 = ( V_83 -> type == V_88 ||
V_83 -> type == V_89 ) ;
T_2 V_71 = V_87 ? V_78 : V_77 ;
bool V_90 = false ;
if ( V_90 ) {
F_5 ( L_3 , F_29 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
F_30 ( V_91 , 0 ) ;
F_30 ( V_91 , V_92 | V_93 ) ;
F_30 ( V_91 , 0 ) ;
F_30 ( V_94 ,
F_31 ( ( V_31 -> V_95 -
V_31 -> V_96 ) * V_85 ,
V_97 ) |
F_31 ( ( V_31 -> V_96 -
V_31 -> V_98 ) * V_85 ,
V_99 ) ) ;
F_30 ( V_100 ,
F_31 ( ( V_31 -> V_98 -
V_31 -> V_101 ) * V_85 ,
V_102 ) |
F_31 ( V_31 -> V_101 * V_85 , V_103 ) ) ;
F_30 ( V_104 ,
F_31 ( V_31 -> V_105 - V_31 -> V_106 ,
V_107 ) |
F_31 ( V_31 -> V_106 - V_31 -> V_108 ,
V_109 ) ) ;
F_30 ( V_110 ,
F_31 ( V_31 -> V_108 - V_31 -> V_111 ,
V_112 ) |
F_31 ( V_31 -> V_111 , V_113 ) ) ;
if ( V_84 ) {
F_30 ( V_114 ,
F_31 ( V_31 -> V_105 -
V_31 -> V_106 - 1 ,
V_107 ) |
F_31 ( V_31 -> V_106 -
V_31 -> V_108 ,
V_109 ) ) ;
F_30 ( V_115 ,
F_31 ( V_31 -> V_108 -
V_31 -> V_111 ,
V_112 ) |
F_31 ( V_31 -> V_111 , V_113 ) ) ;
F_30 ( V_116 ,
V_117 |
( V_87 ? V_118 : 0 ) |
V_119 |
F_31 ( V_31 -> V_95 * V_85 / 2 ,
V_120 ) ) ;
F_30 ( V_121 , 0 ) ;
} else {
F_30 ( V_116 ,
V_117 |
( V_87 ? V_118 : 0 ) ) ;
}
F_30 ( V_122 , V_31 -> V_101 * V_85 ) ;
F_30 ( V_91 ,
F_31 ( V_71 , V_123 ) |
F_31 ( F_24 ( V_71 ) ,
V_124 ) |
F_31 ( V_85 - 1 , V_125 ) |
V_126 |
V_127 |
V_128 |
F_31 ( V_83 -> V_129 ,
V_130 ) |
V_92 |
V_93 ) ;
F_22 ( F_32 ( V_1 -> V_38 ) ,
V_131 |
V_132 |
( V_84 ? V_133 : 0 ) ) ;
F_21 ( V_3 ) ;
if ( V_90 ) {
F_5 ( L_4 , F_29 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
}
static void F_33 ( struct V_17 * V_18 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
F_34 ( ( F_14 ( V_134 ) & V_135 ) !=
V_135 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_136 = V_1 -> V_38 ;
int V_37 ;
F_33 ( V_18 ) ;
F_36 ( V_3 ) ;
F_30 ( V_116 ,
F_6 ( V_116 ) & ~ V_137 ) ;
V_37 = F_37 ( ! ( F_6 ( V_116 ) & V_137 ) , 1 ) ;
F_38 ( V_37 , L_5 ) ;
if ( F_14 ( F_39 ( V_136 ) ) &
V_138 ) {
F_22 ( F_39 ( V_136 ) ,
V_139 ) ;
F_22 ( F_39 ( V_136 ) , 0 ) ;
}
F_34 ( F_14 ( F_39 ( V_136 ) ) & V_139 ) ;
F_34 ( F_16 ( F_14 ( F_15 ( V_136 ) ) ,
V_140 ) !=
V_141 ) ;
F_34 ( ( F_14 ( F_15 ( V_136 ) ) &
( V_52 | V_142 ) ) !=
V_142 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_56 = V_3 -> V_56 ;
struct V_30 * V_31 = & V_56 -> V_57 ;
F_33 ( V_18 ) ;
F_22 ( F_39 ( V_1 -> V_38 ) ,
F_31 ( V_31 -> V_101 , V_143 ) |
F_31 ( V_31 -> V_49 , V_144 ) |
V_138 ) ;
F_30 ( V_116 ,
F_6 ( V_116 ) | V_137 ) ;
F_41 ( V_3 ) ;
}
static bool F_42 ( struct V_2 * V_3 ,
const struct V_30 * V_31 ,
struct V_30 * V_57 )
{
if ( V_57 -> V_25 & V_145 ) {
F_43 ( L_6 ,
V_3 -> V_146 . V_147 ) ;
return false ;
}
return true ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_5 * V_56 )
{
struct V_4 * V_148 = F_2 ( V_56 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_149 * V_150 ;
unsigned long V_25 ;
const struct V_151 * V_152 ;
T_2 V_153 = 0 ;
int V_37 ;
if ( F_45 ( V_56 -> V_154 ) > 1 )
return - V_155 ;
F_46 (plane, plane_state, state)
V_153 += F_47 ( V_152 ) ;
V_153 ++ ;
F_48 ( & V_33 -> V_156 -> V_157 , V_25 ) ;
V_37 = F_49 ( & V_33 -> V_156 -> V_158 , & V_148 -> V_159 ,
V_153 ) ;
F_50 ( & V_33 -> V_156 -> V_157 , V_25 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_5 * V_160 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_148 = F_2 ( V_3 -> V_56 ) ;
struct V_149 * V_150 ;
bool V_90 = false ;
T_2 T_5 * V_161 = V_33 -> V_156 -> V_162 + V_148 -> V_159 . V_163 ;
T_2 T_5 * V_164 = V_161 ;
if ( V_90 ) {
F_5 ( L_7 , F_29 ( V_3 ) ) ;
F_52 ( V_18 ) ;
}
F_53 (plane, crtc) {
V_164 += F_54 ( V_150 , V_164 ) ;
}
F_55 ( V_165 , V_164 ) ;
V_164 ++ ;
F_34 ( V_164 - V_161 != V_148 -> V_159 . V_68 ) ;
if ( V_3 -> V_56 -> V_166 ) {
unsigned long V_25 ;
V_3 -> V_56 -> V_166 -> V_167 = F_29 ( V_3 ) ;
F_56 ( F_57 ( V_3 ) != 0 ) ;
F_48 ( & V_18 -> V_168 , V_25 ) ;
V_1 -> V_166 = V_3 -> V_56 -> V_166 ;
V_3 -> V_56 -> V_166 = NULL ;
F_22 ( F_58 ( V_1 -> V_38 ) ,
V_148 -> V_159 . V_163 ) ;
F_50 ( & V_18 -> V_168 , V_25 ) ;
} else {
F_22 ( F_58 ( V_1 -> V_38 ) ,
V_148 -> V_159 . V_163 ) ;
}
if ( V_90 ) {
F_5 ( L_8 , F_29 ( V_3 ) ) ;
F_52 ( V_18 ) ;
}
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_30 ( V_169 , V_170 ) ;
return 0 ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_30 ( V_169 , 0 ) ;
}
bool F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ! ! V_1 -> V_166 ;
}
static void F_62 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_146 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_4 * V_148 = F_2 ( V_3 -> V_56 ) ;
T_2 V_136 = V_1 -> V_38 ;
unsigned long V_25 ;
F_48 ( & V_18 -> V_168 , V_25 ) ;
if ( V_1 -> V_166 &&
( V_148 -> V_159 . V_163 == F_14 ( F_63 ( V_136 ) ) ) ) {
F_64 ( V_3 , V_1 -> V_166 ) ;
V_1 -> V_166 = NULL ;
F_65 ( V_3 ) ;
}
F_50 ( & V_18 -> V_168 , V_25 ) ;
}
static T_6 F_66 ( int V_171 , void * V_23 )
{
struct V_1 * V_1 = V_23 ;
T_2 V_172 = F_6 ( V_173 ) ;
T_6 V_37 = V_174 ;
if ( V_172 & V_170 ) {
V_1 -> V_51 = F_13 () ;
F_30 ( V_173 , V_170 ) ;
F_67 ( & V_1 -> V_146 ) ;
F_62 ( V_1 ) ;
V_37 = V_175 ;
}
return V_37 ;
}
static void
F_68 ( struct V_176 * V_177 )
{
struct V_178 * V_179 =
F_69 ( V_177 , struct V_178 , V_177 ) ;
struct V_2 * V_3 = V_179 -> V_3 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_149 * V_150 = V_3 -> V_180 ;
F_70 ( V_150 , V_179 -> V_181 ) ;
if ( V_179 -> V_166 ) {
unsigned long V_25 ;
F_48 ( & V_18 -> V_168 , V_25 ) ;
F_64 ( V_3 , V_179 -> V_166 ) ;
F_50 ( & V_18 -> V_168 , V_25 ) ;
}
F_65 ( V_3 ) ;
F_71 ( V_179 -> V_181 ) ;
F_72 ( V_179 ) ;
F_73 ( & V_33 -> V_182 ) ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_183 * V_181 ,
struct V_184 * V_166 ,
T_4 V_25 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_149 * V_150 = V_3 -> V_180 ;
int V_37 = 0 ;
struct V_178 * V_179 ;
struct V_185 * V_186 = F_75 ( V_181 , 0 ) ;
struct V_187 * V_188 = F_76 ( & V_186 -> V_146 ) ;
V_179 = F_77 ( sizeof( * V_179 ) , V_189 ) ;
if ( ! V_179 )
return - V_190 ;
F_78 ( V_181 ) ;
V_179 -> V_181 = V_181 ;
V_179 -> V_3 = V_3 ;
V_179 -> V_166 = V_166 ;
V_37 = F_79 ( & V_33 -> V_182 ) ;
if ( V_37 ) {
F_71 ( V_181 ) ;
F_72 ( V_179 ) ;
return V_37 ;
}
F_56 ( F_57 ( V_3 ) != 0 ) ;
F_80 ( V_150 -> V_56 , V_181 ) ;
V_150 -> V_181 = V_181 ;
F_81 ( V_18 , & V_179 -> V_177 , V_188 -> V_191 ,
F_68 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_183 * V_181 ,
struct V_184 * V_166 ,
T_4 V_25 ,
struct V_69 * V_70 )
{
if ( V_25 & V_192 )
return F_74 ( V_3 , V_181 , V_166 , V_25 ) ;
else
return F_83 ( V_3 , V_181 , V_166 , V_25 , V_70 ) ;
}
static struct V_5 * F_84 ( struct V_2 * V_3 )
{
struct V_4 * V_148 ;
V_148 = F_77 ( sizeof( * V_148 ) , V_189 ) ;
if ( ! V_148 )
return NULL ;
F_85 ( V_3 , & V_148 -> V_146 ) ;
return & V_148 -> V_146 ;
}
static void F_86 ( struct V_2 * V_3 ,
struct V_5 * V_56 )
{
struct V_32 * V_33 = F_11 ( V_3 -> V_18 ) ;
struct V_4 * V_148 = F_2 ( V_56 ) ;
if ( V_148 -> V_159 . V_193 ) {
unsigned long V_25 ;
F_48 ( & V_33 -> V_156 -> V_157 , V_25 ) ;
F_87 ( & V_148 -> V_159 ) ;
F_50 ( & V_33 -> V_156 -> V_157 , V_25 ) ;
}
F_88 ( V_3 , V_56 ) ;
}
static void
F_89 ( struct V_2 * V_3 )
{
if ( V_3 -> V_56 )
F_90 ( V_3 -> V_56 ) ;
V_3 -> V_56 = F_77 ( sizeof( struct V_4 ) , V_189 ) ;
if ( V_3 -> V_56 )
V_3 -> V_56 -> V_3 = V_3 ;
}
static void F_91 ( struct V_17 * V_194 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_195 * V_196 = V_1 -> V_23 ;
const enum V_197 * V_198 = V_196 -> V_198 ;
struct V_79 * V_82 ;
F_92 (encoder, drm) {
struct V_83 * V_83 = F_28 ( V_82 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_196 -> V_198 ) ; V_7 ++ ) {
if ( V_83 -> type == V_198 [ V_7 ] ) {
V_83 -> V_129 = V_7 ;
V_82 -> V_199 |= F_93 ( V_3 ) ;
break;
}
}
}
}
static void
F_94 ( struct V_1 * V_1 )
{
struct V_17 * V_194 = V_1 -> V_146 . V_18 ;
struct V_32 * V_33 = F_11 ( V_194 ) ;
T_2 V_200 = F_14 ( F_95 ( V_1 -> V_38 ) ) ;
T_2 V_201 = F_16 ( V_200 , V_202 ) & ~ 3 ;
T_2 V_146 = F_16 ( V_200 , V_203 ) & ~ 3 ;
V_1 -> V_43 = V_201 - V_146 + 4 ;
}
static int F_96 ( struct V_204 * V_18 , struct V_204 * V_205 , void * V_23 )
{
struct V_206 * V_207 = F_97 ( V_18 ) ;
struct V_17 * V_194 = F_98 ( V_205 ) ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_149 * V_208 , * V_209 , * V_210 , * V_211 ;
const struct V_212 * V_213 ;
int V_37 , V_7 ;
V_1 = F_99 ( V_18 , sizeof( * V_1 ) , V_189 ) ;
if ( ! V_1 )
return - V_190 ;
V_3 = & V_1 -> V_146 ;
V_213 = F_100 ( V_214 , V_18 ) ;
if ( ! V_213 )
return - V_215 ;
V_1 -> V_23 = V_213 -> V_23 ;
V_1 -> V_216 = F_101 ( V_207 , 0 ) ;
if ( F_102 ( V_1 -> V_216 ) )
return F_103 ( V_1 -> V_216 ) ;
V_208 = F_104 ( V_194 , V_217 ) ;
if ( F_102 ( V_208 ) ) {
F_105 ( V_18 , L_9 ) ;
V_37 = F_103 ( V_208 ) ;
goto V_218;
}
F_106 ( V_194 , V_3 , V_208 , NULL ,
& V_219 , NULL ) ;
F_107 ( V_3 , & V_220 ) ;
V_208 -> V_3 = V_3 ;
V_1 -> V_38 = V_1 -> V_23 -> V_221 ;
F_108 ( V_3 , F_4 ( V_1 -> V_62 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
struct V_149 * V_150 =
F_104 ( V_194 , V_222 ) ;
if ( F_102 ( V_150 ) )
continue;
V_150 -> V_199 = 1 << F_29 ( V_3 ) ;
}
V_209 = F_104 ( V_194 , V_223 ) ;
if ( ! F_102 ( V_209 ) ) {
V_209 -> V_199 = 1 << F_29 ( V_3 ) ;
V_209 -> V_3 = V_3 ;
V_3 -> V_224 = V_209 ;
}
F_94 ( V_1 ) ;
F_30 ( V_169 , 0 ) ;
F_30 ( V_173 , V_170 ) ;
V_37 = F_109 ( V_18 , F_110 ( V_207 , 0 ) ,
F_66 , 0 , L_10 , V_1 ) ;
if ( V_37 )
goto V_225;
F_91 ( V_194 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_60 ; V_7 ++ ) {
V_1 -> V_62 [ V_7 ] = V_7 ;
V_1 -> V_63 [ V_7 ] = V_7 ;
V_1 -> V_64 [ V_7 ] = V_7 ;
}
F_111 ( V_207 , V_1 ) ;
return 0 ;
V_225:
F_112 (destroy_plane, temp,
&drm->mode_config.plane_list, head) {
if ( V_210 -> V_199 == 1 << F_29 ( V_3 ) )
V_210 -> V_226 -> V_227 ( V_210 ) ;
}
V_218:
return V_37 ;
}
static void F_113 ( struct V_204 * V_18 , struct V_204 * V_205 ,
void * V_23 )
{
struct V_206 * V_207 = F_97 ( V_18 ) ;
struct V_1 * V_1 = F_98 ( V_18 ) ;
F_19 ( & V_1 -> V_146 ) ;
F_30 ( V_169 , 0 ) ;
F_111 ( V_207 , NULL ) ;
}
static int F_114 ( struct V_206 * V_207 )
{
return F_115 ( & V_207 -> V_18 , & V_228 ) ;
}
static int F_116 ( struct V_206 * V_207 )
{
F_117 ( & V_207 -> V_18 , & V_228 ) ;
return 0 ;
}
