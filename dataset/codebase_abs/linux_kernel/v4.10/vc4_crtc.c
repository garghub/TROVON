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
struct V_1 * V_1 = V_33 -> V_3 [ V_24 ] ;
T_2 V_34 ;
int V_35 ;
int V_36 ;
int V_37 = 0 ;
if ( V_28 )
* V_28 = F_12 () ;
V_34 = F_13 ( F_14 ( V_1 -> V_38 ) ) ;
if ( V_29 )
* V_29 = F_12 () ;
* V_26 = F_15 ( V_34 , V_39 ) ;
* V_27 = 0 ;
if ( V_31 -> V_25 & V_40 ) {
* V_26 /= 2 ;
if ( F_15 ( V_34 , V_41 ) % 2 )
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
int F_16 ( struct V_17 * V_18 , unsigned int V_24 ,
int * V_53 , struct V_54 * V_55 ,
unsigned V_25 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = V_33 -> V_3 [ V_24 ] ;
struct V_2 * V_3 = & V_1 -> V_56 ;
struct V_5 * V_57 = V_3 -> V_57 ;
return F_17 ( V_18 , V_24 , V_53 ,
V_55 , V_25 ,
& V_57 -> V_58 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
F_19 ( V_3 ) ;
}
static void
F_20 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_7 ;
F_21 ( V_59 ,
V_60 |
( V_1 -> V_38 * 3 * V_3 -> V_61 ) ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_61 ; V_7 ++ )
F_21 ( V_62 , V_1 -> V_63 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_61 ; V_7 ++ )
F_21 ( V_62 , V_1 -> V_64 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_61 ; V_7 ++ )
F_21 ( V_62 , V_1 -> V_65 [ V_7 ] ) ;
}
static int
F_22 ( struct V_2 * V_3 , T_3 * V_66 , T_3 * V_67 , T_3 * V_68 ,
T_4 V_69 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_7 ;
for ( V_7 = 0 ; V_7 < V_69 ; V_7 ++ ) {
V_1 -> V_63 [ V_7 ] = V_66 [ V_7 ] >> 8 ;
V_1 -> V_64 [ V_7 ] = V_67 [ V_7 ] >> 8 ;
V_1 -> V_65 [ V_7 ] = V_68 [ V_7 ] >> 8 ;
}
F_20 ( V_3 ) ;
return 0 ;
}
static T_2 F_23 ( T_2 V_70 )
{
static const T_2 V_71 = 64 ;
static const T_2 V_72 = 6 ;
switch ( V_70 ) {
case V_73 :
case V_74 :
return V_71 - 2 * V_72 ;
case V_75 :
return V_71 - 14 ;
case V_76 :
case V_77 :
default:
return V_71 - 3 * V_72 ;
}
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_78 * V_79 ;
F_25 (connector, crtc->dev) {
if ( V_79 -> V_57 -> V_3 == V_3 ) {
struct V_80 * V_81 = V_79 -> V_81 ;
struct V_82 * V_82 =
F_26 ( V_81 ) ;
return V_82 -> V_83 ;
}
}
return - 1 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_57 = V_3 -> V_57 ;
struct V_30 * V_31 = & V_57 -> V_58 ;
bool V_84 = V_31 -> V_25 & V_40 ;
T_2 V_85 = ( V_31 -> V_25 & V_86 ) ? 2 : 1 ;
T_2 V_70 = V_76 ;
bool V_87 = false ;
int V_83 = F_24 ( V_3 ) ;
if ( V_87 ) {
F_5 ( L_3 , F_28 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
F_29 ( V_88 , 0 ) ;
F_29 ( V_88 , V_89 | V_90 ) ;
F_29 ( V_88 , 0 ) ;
F_29 ( V_91 ,
F_30 ( ( V_31 -> V_92 -
V_31 -> V_93 ) * V_85 ,
V_94 ) |
F_30 ( ( V_31 -> V_93 -
V_31 -> V_95 ) * V_85 ,
V_96 ) ) ;
F_29 ( V_97 ,
F_30 ( ( V_31 -> V_95 -
V_31 -> V_98 ) * V_85 ,
V_99 ) |
F_30 ( V_31 -> V_98 * V_85 , V_100 ) ) ;
F_29 ( V_101 ,
F_30 ( V_31 -> V_102 - V_31 -> V_103 ,
V_104 ) |
F_30 ( V_31 -> V_103 - V_31 -> V_105 ,
V_106 ) ) ;
F_29 ( V_107 ,
F_30 ( V_31 -> V_105 - V_31 -> V_108 ,
V_109 ) |
F_30 ( V_31 -> V_108 , V_110 ) ) ;
if ( V_84 ) {
F_29 ( V_111 ,
F_30 ( V_31 -> V_102 -
V_31 -> V_103 - 1 ,
V_104 ) |
F_30 ( V_31 -> V_103 -
V_31 -> V_105 ,
V_106 ) ) ;
F_29 ( V_112 ,
F_30 ( V_31 -> V_105 -
V_31 -> V_108 ,
V_109 ) |
F_30 ( V_31 -> V_108 , V_110 ) ) ;
F_29 ( V_113 ,
V_114 |
V_115 |
F_30 ( V_31 -> V_92 * V_85 / 2 ,
V_116 ) ) ;
F_29 ( V_117 , 0 ) ;
} else {
F_29 ( V_113 , V_114 ) ;
}
F_29 ( V_118 , V_31 -> V_98 * V_85 ) ;
F_29 ( V_88 ,
F_30 ( V_70 , V_119 ) |
F_30 ( F_23 ( V_70 ) ,
V_120 ) |
F_30 ( V_85 - 1 , V_121 ) |
V_122 |
V_123 |
V_124 |
F_30 ( V_83 , V_125 ) |
V_89 |
V_90 ) ;
F_21 ( F_31 ( V_1 -> V_38 ) ,
V_126 |
V_127 |
( V_84 ? V_128 : 0 ) ) ;
F_20 ( V_3 ) ;
if ( V_87 ) {
F_5 ( L_4 , F_28 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
}
static void F_32 ( struct V_17 * V_18 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
F_33 ( ( F_13 ( V_129 ) & V_130 ) !=
V_130 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_131 = V_1 -> V_38 ;
int V_37 ;
F_32 ( V_18 ) ;
F_35 ( V_3 ) ;
F_29 ( V_113 ,
F_6 ( V_113 ) & ~ V_132 ) ;
V_37 = F_36 ( ! ( F_6 ( V_113 ) & V_132 ) , 1 ) ;
F_37 ( V_37 , L_5 ) ;
if ( F_13 ( F_38 ( V_131 ) ) &
V_133 ) {
F_21 ( F_38 ( V_131 ) ,
V_134 ) ;
F_21 ( F_38 ( V_131 ) , 0 ) ;
}
F_33 ( F_13 ( F_38 ( V_131 ) ) & V_134 ) ;
F_33 ( F_15 ( F_13 ( F_14 ( V_131 ) ) ,
V_135 ) !=
V_136 ) ;
F_33 ( ( F_13 ( F_14 ( V_131 ) ) &
( V_52 | V_137 ) ) !=
V_137 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_57 = V_3 -> V_57 ;
struct V_30 * V_31 = & V_57 -> V_58 ;
F_32 ( V_18 ) ;
F_21 ( F_38 ( V_1 -> V_38 ) ,
F_30 ( V_31 -> V_98 , V_138 ) |
F_30 ( V_31 -> V_49 , V_139 ) |
V_133 ) ;
F_29 ( V_113 ,
F_6 ( V_113 ) | V_132 ) ;
F_40 ( V_3 ) ;
}
static bool F_41 ( struct V_2 * V_3 ,
const struct V_30 * V_31 ,
struct V_30 * V_58 )
{
if ( V_58 -> V_25 & V_140 ) {
F_42 ( L_6 ,
V_3 -> V_56 . V_141 ) ;
return false ;
}
return true ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_5 * V_57 )
{
struct V_4 * V_142 = F_2 ( V_57 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_143 * V_144 ;
unsigned long V_25 ;
const struct V_145 * V_146 ;
T_2 V_147 = 0 ;
int V_37 ;
if ( F_44 ( V_57 -> V_148 ) > 1 )
return - V_149 ;
F_45 (plane, plane_state, state)
V_147 += F_46 ( V_146 ) ;
V_147 ++ ;
F_47 ( & V_33 -> V_150 -> V_151 , V_25 ) ;
V_37 = F_48 ( & V_33 -> V_150 -> V_152 , & V_142 -> V_153 ,
V_147 , 1 , 0 ) ;
F_49 ( & V_33 -> V_150 -> V_151 , V_25 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_5 * V_154 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_142 = F_2 ( V_3 -> V_57 ) ;
struct V_143 * V_144 ;
bool V_87 = false ;
T_2 T_5 * V_155 = V_33 -> V_150 -> V_156 + V_142 -> V_153 . V_157 ;
T_2 T_5 * V_158 = V_155 ;
if ( V_87 ) {
F_5 ( L_7 , F_28 ( V_3 ) ) ;
F_51 ( V_18 ) ;
}
F_52 (plane, crtc) {
V_158 += F_53 ( V_144 , V_158 ) ;
}
F_54 ( V_159 , V_158 ) ;
V_158 ++ ;
F_33 ( V_158 - V_155 != V_142 -> V_153 . V_69 ) ;
if ( V_3 -> V_57 -> V_160 ) {
unsigned long V_25 ;
V_3 -> V_57 -> V_160 -> V_161 = F_28 ( V_3 ) ;
F_55 ( F_56 ( V_3 ) != 0 ) ;
F_47 ( & V_18 -> V_162 , V_25 ) ;
V_1 -> V_160 = V_3 -> V_57 -> V_160 ;
V_3 -> V_57 -> V_160 = NULL ;
F_21 ( F_57 ( V_1 -> V_38 ) ,
V_142 -> V_153 . V_157 ) ;
F_49 ( & V_18 -> V_162 , V_25 ) ;
} else {
F_21 ( F_57 ( V_1 -> V_38 ) ,
V_142 -> V_153 . V_157 ) ;
}
if ( V_87 ) {
F_5 ( L_8 , F_28 ( V_3 ) ) ;
F_51 ( V_18 ) ;
}
}
int F_58 ( struct V_17 * V_18 , unsigned int V_24 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = V_33 -> V_3 [ V_24 ] ;
F_29 ( V_163 , V_164 ) ;
return 0 ;
}
void F_59 ( struct V_17 * V_18 , unsigned int V_24 )
{
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_1 * V_1 = V_33 -> V_3 [ V_24 ] ;
F_29 ( V_163 , 0 ) ;
}
bool F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return ! ! V_1 -> V_160 ;
}
static void F_61 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_56 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_4 * V_142 = F_2 ( V_3 -> V_57 ) ;
T_2 V_131 = V_1 -> V_38 ;
unsigned long V_25 ;
F_47 ( & V_18 -> V_162 , V_25 ) ;
if ( V_1 -> V_160 &&
( V_142 -> V_153 . V_157 == F_13 ( F_62 ( V_131 ) ) ) ) {
F_63 ( V_3 , V_1 -> V_160 ) ;
V_1 -> V_160 = NULL ;
F_64 ( V_3 ) ;
}
F_49 ( & V_18 -> V_162 , V_25 ) ;
}
static T_6 F_65 ( int V_165 , void * V_23 )
{
struct V_1 * V_1 = V_23 ;
T_2 V_166 = F_6 ( V_167 ) ;
T_6 V_37 = V_168 ;
if ( V_166 & V_164 ) {
V_1 -> V_51 = F_12 () ;
F_29 ( V_167 , V_164 ) ;
F_66 ( & V_1 -> V_56 ) ;
F_61 ( V_1 ) ;
V_37 = V_169 ;
}
return V_37 ;
}
static void
F_67 ( struct V_170 * V_171 )
{
struct V_172 * V_173 =
F_68 ( V_171 , struct V_172 , V_171 ) ;
struct V_2 * V_3 = V_173 -> V_3 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_143 * V_144 = V_3 -> V_174 ;
F_69 ( V_144 , V_173 -> V_175 ) ;
if ( V_173 -> V_160 ) {
unsigned long V_25 ;
F_47 ( & V_18 -> V_162 , V_25 ) ;
F_63 ( V_3 , V_173 -> V_160 ) ;
F_49 ( & V_18 -> V_162 , V_25 ) ;
}
F_64 ( V_3 ) ;
F_70 ( V_173 -> V_175 ) ;
F_71 ( V_173 ) ;
F_72 ( & V_33 -> V_176 ) ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_177 * V_175 ,
struct V_178 * V_160 ,
T_4 V_25 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_32 * V_33 = F_11 ( V_18 ) ;
struct V_143 * V_144 = V_3 -> V_174 ;
int V_37 = 0 ;
struct V_172 * V_173 ;
struct V_179 * V_180 = F_74 ( V_175 , 0 ) ;
struct V_181 * V_182 = F_75 ( & V_180 -> V_56 ) ;
V_173 = F_76 ( sizeof( * V_173 ) , V_183 ) ;
if ( ! V_173 )
return - V_184 ;
F_77 ( V_175 ) ;
V_173 -> V_175 = V_175 ;
V_173 -> V_3 = V_3 ;
V_173 -> V_160 = V_160 ;
V_37 = F_78 ( & V_33 -> V_176 ) ;
if ( V_37 ) {
F_70 ( V_175 ) ;
F_71 ( V_173 ) ;
return V_37 ;
}
F_55 ( F_56 ( V_3 ) != 0 ) ;
F_79 ( V_144 -> V_57 , V_175 ) ;
V_144 -> V_175 = V_175 ;
F_80 ( V_18 , & V_173 -> V_171 , V_182 -> V_185 ,
F_67 ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_3 ,
struct V_177 * V_175 ,
struct V_178 * V_160 ,
T_4 V_25 )
{
if ( V_25 & V_186 )
return F_73 ( V_3 , V_175 , V_160 , V_25 ) ;
else
return F_82 ( V_3 , V_175 , V_160 , V_25 ) ;
}
static struct V_5 * F_83 ( struct V_2 * V_3 )
{
struct V_4 * V_142 ;
V_142 = F_76 ( sizeof( * V_142 ) , V_183 ) ;
if ( ! V_142 )
return NULL ;
F_84 ( V_3 , & V_142 -> V_56 ) ;
return & V_142 -> V_56 ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_5 * V_57 )
{
struct V_32 * V_33 = F_11 ( V_3 -> V_18 ) ;
struct V_4 * V_142 = F_2 ( V_57 ) ;
if ( V_142 -> V_153 . V_187 ) {
unsigned long V_25 ;
F_47 ( & V_33 -> V_150 -> V_151 , V_25 ) ;
F_86 ( & V_142 -> V_153 ) ;
F_49 ( & V_33 -> V_150 -> V_151 , V_25 ) ;
}
F_87 ( V_3 , V_57 ) ;
}
static void F_88 ( struct V_17 * V_188 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_189 * V_190 = V_1 -> V_23 ;
const enum V_191 * V_192 = V_190 -> V_192 ;
struct V_80 * V_81 ;
F_89 (encoder, drm) {
struct V_82 * V_82 = F_26 ( V_81 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_190 -> V_192 ) ; V_7 ++ ) {
if ( V_82 -> type == V_192 [ V_7 ] ) {
V_82 -> V_83 = V_7 ;
V_81 -> V_193 |= F_90 ( V_3 ) ;
break;
}
}
}
}
static void
F_91 ( struct V_1 * V_1 )
{
struct V_17 * V_188 = V_1 -> V_56 . V_18 ;
struct V_32 * V_33 = F_11 ( V_188 ) ;
T_2 V_194 = F_13 ( F_92 ( V_1 -> V_38 ) ) ;
T_2 V_195 = F_15 ( V_194 , V_196 ) & ~ 3 ;
T_2 V_56 = F_15 ( V_194 , V_197 ) & ~ 3 ;
V_1 -> V_43 = V_195 - V_56 + 4 ;
}
static int F_93 ( struct V_198 * V_18 , struct V_198 * V_199 , void * V_23 )
{
struct V_200 * V_201 = F_94 ( V_18 ) ;
struct V_17 * V_188 = F_95 ( V_199 ) ;
struct V_32 * V_33 = F_11 ( V_188 ) ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_143 * V_202 , * V_203 , * V_204 , * V_205 ;
const struct V_206 * V_207 ;
int V_37 , V_7 ;
V_1 = F_96 ( V_18 , sizeof( * V_1 ) , V_183 ) ;
if ( ! V_1 )
return - V_184 ;
V_3 = & V_1 -> V_56 ;
V_207 = F_97 ( V_208 , V_18 ) ;
if ( ! V_207 )
return - V_209 ;
V_1 -> V_23 = V_207 -> V_23 ;
V_1 -> V_210 = F_98 ( V_201 , 0 ) ;
if ( F_99 ( V_1 -> V_210 ) )
return F_100 ( V_1 -> V_210 ) ;
V_202 = F_101 ( V_188 , V_211 ) ;
if ( F_99 ( V_202 ) ) {
F_102 ( V_18 , L_9 ) ;
V_37 = F_100 ( V_202 ) ;
goto V_212;
}
F_103 ( V_188 , V_3 , V_202 , NULL ,
& V_213 , NULL ) ;
F_104 ( V_3 , & V_214 ) ;
V_202 -> V_3 = V_3 ;
V_33 -> V_3 [ F_28 ( V_3 ) ] = V_1 ;
V_1 -> V_38 = V_1 -> V_23 -> V_215 ;
F_105 ( V_3 , F_4 ( V_1 -> V_63 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
struct V_143 * V_144 =
F_101 ( V_188 , V_216 ) ;
if ( F_99 ( V_144 ) )
continue;
V_144 -> V_193 = 1 << F_28 ( V_3 ) ;
}
V_203 = F_101 ( V_188 , V_217 ) ;
if ( ! F_99 ( V_203 ) ) {
V_203 -> V_193 = 1 << F_28 ( V_3 ) ;
V_203 -> V_3 = V_3 ;
V_3 -> V_218 = V_203 ;
}
F_91 ( V_1 ) ;
F_29 ( V_163 , 0 ) ;
F_29 ( V_167 , V_164 ) ;
V_37 = F_106 ( V_18 , F_107 ( V_201 , 0 ) ,
F_65 , 0 , L_10 , V_1 ) ;
if ( V_37 )
goto V_219;
F_88 ( V_188 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_61 ; V_7 ++ ) {
V_1 -> V_63 [ V_7 ] = V_7 ;
V_1 -> V_64 [ V_7 ] = V_7 ;
V_1 -> V_65 [ V_7 ] = V_7 ;
}
F_108 ( V_201 , V_1 ) ;
return 0 ;
V_219:
F_109 (destroy_plane, temp,
&drm->mode_config.plane_list, head) {
if ( V_204 -> V_193 == 1 << F_28 ( V_3 ) )
V_204 -> V_220 -> V_221 ( V_204 ) ;
}
V_212:
return V_37 ;
}
static void F_110 ( struct V_198 * V_18 , struct V_198 * V_199 ,
void * V_23 )
{
struct V_200 * V_201 = F_94 ( V_18 ) ;
struct V_1 * V_1 = F_95 ( V_18 ) ;
F_18 ( & V_1 -> V_56 ) ;
F_29 ( V_163 , 0 ) ;
F_108 ( V_201 , NULL ) ;
}
static int F_111 ( struct V_200 * V_201 )
{
return F_112 ( & V_201 -> V_18 , & V_222 ) ;
}
static int F_113 ( struct V_200 * V_201 )
{
F_114 ( & V_201 -> V_18 , & V_222 ) ;
return 0 ;
}
