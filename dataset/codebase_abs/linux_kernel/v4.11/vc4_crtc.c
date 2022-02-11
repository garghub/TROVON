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
T_4 V_68 )
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
static T_2 F_24 ( T_2 V_69 )
{
static const T_2 V_70 = 64 ;
static const T_2 V_71 = 6 ;
switch ( V_69 ) {
case V_72 :
case V_73 :
return V_70 - 2 * V_71 ;
case V_74 :
return V_70 - 14 ;
case V_75 :
case V_76 :
default:
return V_70 - 3 * V_71 ;
}
}
static struct V_77 * F_25 ( struct V_2 * V_3 )
{
struct V_78 * V_79 ;
F_26 (connector, crtc->dev) {
if ( V_79 -> V_56 -> V_3 == V_3 ) {
return V_79 -> V_80 ;
}
}
return NULL ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_77 * V_80 = F_25 ( V_3 ) ;
struct V_81 * V_81 = F_28 ( V_80 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_56 = V_3 -> V_56 ;
struct V_30 * V_31 = & V_56 -> V_57 ;
bool V_82 = V_31 -> V_25 & V_40 ;
T_2 V_83 = ( V_31 -> V_25 & V_84 ) ? 2 : 1 ;
bool V_85 = ( V_81 -> type == V_86 ||
V_81 -> type == V_87 ) ;
T_2 V_69 = V_85 ? V_76 : V_75 ;
bool V_88 = false ;
if ( V_88 ) {
F_5 ( L_3 , F_29 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
F_30 ( V_89 , 0 ) ;
F_30 ( V_89 , V_90 | V_91 ) ;
F_30 ( V_89 , 0 ) ;
F_30 ( V_92 ,
F_31 ( ( V_31 -> V_93 -
V_31 -> V_94 ) * V_83 ,
V_95 ) |
F_31 ( ( V_31 -> V_94 -
V_31 -> V_96 ) * V_83 ,
V_97 ) ) ;
F_30 ( V_98 ,
F_31 ( ( V_31 -> V_96 -
V_31 -> V_99 ) * V_83 ,
V_100 ) |
F_31 ( V_31 -> V_99 * V_83 , V_101 ) ) ;
F_30 ( V_102 ,
F_31 ( V_31 -> V_103 - V_31 -> V_104 ,
V_105 ) |
F_31 ( V_31 -> V_104 - V_31 -> V_106 ,
V_107 ) ) ;
F_30 ( V_108 ,
F_31 ( V_31 -> V_106 - V_31 -> V_109 ,
V_110 ) |
F_31 ( V_31 -> V_109 , V_111 ) ) ;
if ( V_82 ) {
F_30 ( V_112 ,
F_31 ( V_31 -> V_103 -
V_31 -> V_104 - 1 ,
V_105 ) |
F_31 ( V_31 -> V_104 -
V_31 -> V_106 ,
V_107 ) ) ;
F_30 ( V_113 ,
F_31 ( V_31 -> V_106 -
V_31 -> V_109 ,
V_110 ) |
F_31 ( V_31 -> V_109 , V_111 ) ) ;
F_30 ( V_114 ,
V_115 |
( V_85 ? V_116 : 0 ) |
V_117 |
F_31 ( V_31 -> V_93 * V_83 / 2 ,
V_118 ) ) ;
F_30 ( V_119 , 0 ) ;
} else {
F_30 ( V_114 ,
V_115 |
( V_85 ? V_116 : 0 ) ) ;
}
F_30 ( V_120 , V_31 -> V_99 * V_83 ) ;
F_30 ( V_89 ,
F_31 ( V_69 , V_121 ) |
F_31 ( F_24 ( V_69 ) ,
V_122 ) |
F_31 ( V_83 - 1 , V_123 ) |
V_124 |
V_125 |
V_126 |
F_31 ( V_81 -> V_127 ,
V_128 ) |
V_90 |
V_91 ) ;
F_22 ( F_32 ( V_1 -> V_38 ) ,
V_129 |
V_130 |
( V_82 ? V_131 : 0 ) ) ;
F_21 ( V_3 ) ;
if ( V_88 ) {
F_5 ( L_4 , F_29 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
}
static void F_33 ( struct V_17 * V_18 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
F_34 ( ( F_14 ( V_132 ) & V_133 ) !=
V_133 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_134 = V_1 -> V_38 ;
int V_37 ;
F_33 ( V_18 ) ;
F_36 ( V_3 ) ;
F_30 ( V_114 ,
F_6 ( V_114 ) & ~ V_135 ) ;
V_37 = F_37 ( ! ( F_6 ( V_114 ) & V_135 ) , 1 ) ;
F_38 ( V_37 , L_5 ) ;
if ( F_14 ( F_39 ( V_134 ) ) &
V_136 ) {
F_22 ( F_39 ( V_134 ) ,
V_137 ) ;
F_22 ( F_39 ( V_134 ) , 0 ) ;
}
F_34 ( F_14 ( F_39 ( V_134 ) ) & V_137 ) ;
F_34 ( F_16 ( F_14 ( F_15 ( V_134 ) ) ,
V_138 ) !=
V_139 ) ;
F_34 ( ( F_14 ( F_15 ( V_134 ) ) &
( V_52 | V_140 ) ) !=
V_140 ) ;
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
F_31 ( V_31 -> V_99 , V_141 ) |
F_31 ( V_31 -> V_49 , V_142 ) |
V_136 ) ;
F_30 ( V_114 ,
F_6 ( V_114 ) | V_135 ) ;
F_41 ( V_3 ) ;
}
static bool F_42 ( struct V_2 * V_3 ,
const struct V_30 * V_31 ,
struct V_30 * V_57 )
{
if ( V_57 -> V_25 & V_143 ) {
F_43 ( L_6 ,
V_3 -> V_144 . V_145 ) ;
return false ;
}
return true ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_5 * V_56 )
{
struct V_4 * V_146 = F_2 ( V_56 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_147 * V_148 ;
unsigned long V_25 ;
const struct V_149 * V_150 ;
T_2 V_151 = 0 ;
int V_37 ;
if ( F_45 ( V_56 -> V_152 ) > 1 )
return - V_153 ;
F_46 (plane, plane_state, state)
V_151 += F_47 ( V_150 ) ;
V_151 ++ ;
F_48 ( & V_33 -> V_154 -> V_155 , V_25 ) ;
V_37 = F_49 ( & V_33 -> V_154 -> V_156 , & V_146 -> V_157 ,
V_151 ) ;
F_50 ( & V_33 -> V_154 -> V_155 , V_25 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_5 * V_158 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_146 = F_2 ( V_3 -> V_56 ) ;
struct V_147 * V_148 ;
bool V_88 = false ;
T_2 T_5 * V_159 = V_33 -> V_154 -> V_160 + V_146 -> V_157 . V_161 ;
T_2 T_5 * V_162 = V_159 ;
if ( V_88 ) {
F_5 ( L_7 , F_29 ( V_3 ) ) ;
F_52 ( V_18 ) ;
}
F_53 (plane, crtc) {
V_162 += F_54 ( V_148 , V_162 ) ;
}
F_55 ( V_163 , V_162 ) ;
V_162 ++ ;
F_34 ( V_162 - V_159 != V_146 -> V_157 . V_68 ) ;
if ( V_3 -> V_56 -> V_164 ) {
unsigned long V_25 ;
V_3 -> V_56 -> V_164 -> V_165 = F_29 ( V_3 ) ;
F_56 ( F_57 ( V_3 ) != 0 ) ;
F_48 ( & V_18 -> V_166 , V_25 ) ;
V_1 -> V_164 = V_3 -> V_56 -> V_164 ;
V_3 -> V_56 -> V_164 = NULL ;
F_22 ( F_58 ( V_1 -> V_38 ) ,
V_146 -> V_157 . V_161 ) ;
F_50 ( & V_18 -> V_166 , V_25 ) ;
} else {
F_22 ( F_58 ( V_1 -> V_38 ) ,
V_146 -> V_157 . V_161 ) ;
}
if ( V_88 ) {
F_5 ( L_8 , F_29 ( V_3 ) ) ;
F_52 ( V_18 ) ;
}
}
int F_59 ( struct V_17 * V_18 , unsigned int V_24 )
{
struct V_2 * V_3 = F_12 ( V_18 , V_24 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_30 ( V_167 , V_168 ) ;
return 0 ;
}
void F_60 ( struct V_17 * V_18 , unsigned int V_24 )
{
struct V_2 * V_3 = F_12 ( V_18 , V_24 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_30 ( V_167 , 0 ) ;
}
bool F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ! ! V_1 -> V_164 ;
}
static void F_62 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_144 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_4 * V_146 = F_2 ( V_3 -> V_56 ) ;
T_2 V_134 = V_1 -> V_38 ;
unsigned long V_25 ;
F_48 ( & V_18 -> V_166 , V_25 ) ;
if ( V_1 -> V_164 &&
( V_146 -> V_157 . V_161 == F_14 ( F_63 ( V_134 ) ) ) ) {
F_64 ( V_3 , V_1 -> V_164 ) ;
V_1 -> V_164 = NULL ;
F_65 ( V_3 ) ;
}
F_50 ( & V_18 -> V_166 , V_25 ) ;
}
static T_6 F_66 ( int V_169 , void * V_23 )
{
struct V_1 * V_1 = V_23 ;
T_2 V_170 = F_6 ( V_171 ) ;
T_6 V_37 = V_172 ;
if ( V_170 & V_168 ) {
V_1 -> V_51 = F_13 () ;
F_30 ( V_171 , V_168 ) ;
F_67 ( & V_1 -> V_144 ) ;
F_62 ( V_1 ) ;
V_37 = V_173 ;
}
return V_37 ;
}
static void
F_68 ( struct V_174 * V_175 )
{
struct V_176 * V_177 =
F_69 ( V_175 , struct V_176 , V_175 ) ;
struct V_2 * V_3 = V_177 -> V_3 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_147 * V_148 = V_3 -> V_178 ;
F_70 ( V_148 , V_177 -> V_179 ) ;
if ( V_177 -> V_164 ) {
unsigned long V_25 ;
F_48 ( & V_18 -> V_166 , V_25 ) ;
F_64 ( V_3 , V_177 -> V_164 ) ;
F_50 ( & V_18 -> V_166 , V_25 ) ;
}
F_65 ( V_3 ) ;
F_71 ( V_177 -> V_179 ) ;
F_72 ( V_177 ) ;
F_73 ( & V_33 -> V_180 ) ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_181 * V_179 ,
struct V_182 * V_164 ,
T_4 V_25 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_147 * V_148 = V_3 -> V_178 ;
int V_37 = 0 ;
struct V_176 * V_177 ;
struct V_183 * V_184 = F_75 ( V_179 , 0 ) ;
struct V_185 * V_186 = F_76 ( & V_184 -> V_144 ) ;
V_177 = F_77 ( sizeof( * V_177 ) , V_187 ) ;
if ( ! V_177 )
return - V_188 ;
F_78 ( V_179 ) ;
V_177 -> V_179 = V_179 ;
V_177 -> V_3 = V_3 ;
V_177 -> V_164 = V_164 ;
V_37 = F_79 ( & V_33 -> V_180 ) ;
if ( V_37 ) {
F_71 ( V_179 ) ;
F_72 ( V_177 ) ;
return V_37 ;
}
F_56 ( F_57 ( V_3 ) != 0 ) ;
F_80 ( V_148 -> V_56 , V_179 ) ;
V_148 -> V_179 = V_179 ;
F_81 ( V_18 , & V_177 -> V_175 , V_186 -> V_189 ,
F_68 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_181 * V_179 ,
struct V_182 * V_164 ,
T_4 V_25 )
{
if ( V_25 & V_190 )
return F_74 ( V_3 , V_179 , V_164 , V_25 ) ;
else
return F_83 ( V_3 , V_179 , V_164 , V_25 ) ;
}
static struct V_5 * F_84 ( struct V_2 * V_3 )
{
struct V_4 * V_146 ;
V_146 = F_77 ( sizeof( * V_146 ) , V_187 ) ;
if ( ! V_146 )
return NULL ;
F_85 ( V_3 , & V_146 -> V_144 ) ;
return & V_146 -> V_144 ;
}
static void F_86 ( struct V_2 * V_3 ,
struct V_5 * V_56 )
{
struct V_32 * V_33 = F_11 ( V_3 -> V_18 ) ;
struct V_4 * V_146 = F_2 ( V_56 ) ;
if ( V_146 -> V_157 . V_191 ) {
unsigned long V_25 ;
F_48 ( & V_33 -> V_154 -> V_155 , V_25 ) ;
F_87 ( & V_146 -> V_157 ) ;
F_50 ( & V_33 -> V_154 -> V_155 , V_25 ) ;
}
F_88 ( V_3 , V_56 ) ;
}
static void
F_89 ( struct V_2 * V_3 )
{
if ( V_3 -> V_56 )
F_90 ( V_3 -> V_56 ) ;
V_3 -> V_56 = F_77 ( sizeof( struct V_4 ) , V_187 ) ;
if ( V_3 -> V_56 )
V_3 -> V_56 -> V_3 = V_3 ;
}
static void F_91 ( struct V_17 * V_192 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_193 * V_194 = V_1 -> V_23 ;
const enum V_195 * V_196 = V_194 -> V_196 ;
struct V_77 * V_80 ;
F_92 (encoder, drm) {
struct V_81 * V_81 = F_28 ( V_80 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_194 -> V_196 ) ; V_7 ++ ) {
if ( V_81 -> type == V_196 [ V_7 ] ) {
V_81 -> V_127 = V_7 ;
V_80 -> V_197 |= F_93 ( V_3 ) ;
break;
}
}
}
}
static void
F_94 ( struct V_1 * V_1 )
{
struct V_17 * V_192 = V_1 -> V_144 . V_18 ;
struct V_32 * V_33 = F_11 ( V_192 ) ;
T_2 V_198 = F_14 ( F_95 ( V_1 -> V_38 ) ) ;
T_2 V_199 = F_16 ( V_198 , V_200 ) & ~ 3 ;
T_2 V_144 = F_16 ( V_198 , V_201 ) & ~ 3 ;
V_1 -> V_43 = V_199 - V_144 + 4 ;
}
static int F_96 ( struct V_202 * V_18 , struct V_202 * V_203 , void * V_23 )
{
struct V_204 * V_205 = F_97 ( V_18 ) ;
struct V_17 * V_192 = F_98 ( V_203 ) ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_147 * V_206 , * V_207 , * V_208 , * V_209 ;
const struct V_210 * V_211 ;
int V_37 , V_7 ;
V_1 = F_99 ( V_18 , sizeof( * V_1 ) , V_187 ) ;
if ( ! V_1 )
return - V_188 ;
V_3 = & V_1 -> V_144 ;
V_211 = F_100 ( V_212 , V_18 ) ;
if ( ! V_211 )
return - V_213 ;
V_1 -> V_23 = V_211 -> V_23 ;
V_1 -> V_214 = F_101 ( V_205 , 0 ) ;
if ( F_102 ( V_1 -> V_214 ) )
return F_103 ( V_1 -> V_214 ) ;
V_206 = F_104 ( V_192 , V_215 ) ;
if ( F_102 ( V_206 ) ) {
F_105 ( V_18 , L_9 ) ;
V_37 = F_103 ( V_206 ) ;
goto V_216;
}
F_106 ( V_192 , V_3 , V_206 , NULL ,
& V_217 , NULL ) ;
F_107 ( V_3 , & V_218 ) ;
V_206 -> V_3 = V_3 ;
V_1 -> V_38 = V_1 -> V_23 -> V_219 ;
F_108 ( V_3 , F_4 ( V_1 -> V_62 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
struct V_147 * V_148 =
F_104 ( V_192 , V_220 ) ;
if ( F_102 ( V_148 ) )
continue;
V_148 -> V_197 = 1 << F_29 ( V_3 ) ;
}
V_207 = F_104 ( V_192 , V_221 ) ;
if ( ! F_102 ( V_207 ) ) {
V_207 -> V_197 = 1 << F_29 ( V_3 ) ;
V_207 -> V_3 = V_3 ;
V_3 -> V_222 = V_207 ;
}
F_94 ( V_1 ) ;
F_30 ( V_167 , 0 ) ;
F_30 ( V_171 , V_168 ) ;
V_37 = F_109 ( V_18 , F_110 ( V_205 , 0 ) ,
F_66 , 0 , L_10 , V_1 ) ;
if ( V_37 )
goto V_223;
F_91 ( V_192 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_60 ; V_7 ++ ) {
V_1 -> V_62 [ V_7 ] = V_7 ;
V_1 -> V_63 [ V_7 ] = V_7 ;
V_1 -> V_64 [ V_7 ] = V_7 ;
}
F_111 ( V_205 , V_1 ) ;
return 0 ;
V_223:
F_112 (destroy_plane, temp,
&drm->mode_config.plane_list, head) {
if ( V_208 -> V_197 == 1 << F_29 ( V_3 ) )
V_208 -> V_224 -> V_225 ( V_208 ) ;
}
V_216:
return V_37 ;
}
static void F_113 ( struct V_202 * V_18 , struct V_202 * V_203 ,
void * V_23 )
{
struct V_204 * V_205 = F_97 ( V_18 ) ;
struct V_1 * V_1 = F_98 ( V_18 ) ;
F_19 ( & V_1 -> V_144 ) ;
F_30 ( V_167 , 0 ) ;
F_111 ( V_205 , NULL ) ;
}
static int F_114 ( struct V_204 * V_205 )
{
return F_115 ( & V_205 -> V_18 , & V_226 ) ;
}
static int F_116 ( struct V_204 * V_205 )
{
F_117 ( & V_205 -> V_18 , & V_226 ) ;
return 0 ;
}
