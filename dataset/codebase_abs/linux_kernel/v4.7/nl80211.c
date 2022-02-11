static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_8 = NULL ;
bool V_9 = V_5 [ V_10 ] ;
bool V_11 = V_5 [ V_12 ] ;
T_1 V_13 ;
int V_14 = - 1 ;
int V_15 = - 1 ;
F_2 () ;
if ( ! V_9 && ! V_11 )
return F_3 ( - V_16 ) ;
if ( V_9 )
V_15 = F_4 ( V_5 [ V_10 ] ) ;
if ( V_11 ) {
V_13 = F_5 ( V_5 [ V_12 ] ) ;
V_14 = V_13 >> 32 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
struct V_1 * V_17 ;
if ( F_7 ( & V_7 -> V_18 ) != V_3 )
continue;
if ( V_11 && V_7 -> V_14 != V_14 )
continue;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_9 && V_17 -> V_19 &&
V_17 -> V_19 -> V_20 == V_15 ) {
V_8 = V_17 ;
break;
}
if ( V_11 && V_17 -> V_21 == ( V_22 ) V_13 ) {
V_8 = V_17 ;
break;
}
}
if ( V_8 )
break;
}
if ( V_8 )
return V_8 ;
return F_3 ( - V_23 ) ;
}
static struct V_6 *
F_8 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = NULL , * V_24 ;
struct V_25 * V_19 ;
F_2 () ;
if ( ! V_5 [ V_26 ] &&
! V_5 [ V_10 ] &&
! V_5 [ V_12 ] )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_26 ] )
V_7 = F_9 (
F_4 ( V_5 [ V_26 ] ) ) ;
if ( V_5 [ V_12 ] ) {
T_1 V_13 = F_5 ( V_5 [ V_12 ] ) ;
struct V_1 * V_17 ;
bool V_27 = false ;
V_24 = F_9 ( V_13 >> 32 ) ;
if ( V_24 ) {
F_6 (wdev, &tmp->wiphy.wdev_list, list) {
if ( V_17 -> V_21 != ( V_22 ) V_13 )
continue;
V_27 = true ;
break;
}
if ( ! V_27 )
V_24 = NULL ;
if ( V_7 && V_24 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_24 ;
}
}
if ( V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_5 [ V_10 ] ) ;
V_19 = F_10 ( V_3 , V_20 ) ;
if ( V_19 ) {
if ( V_19 -> V_28 )
V_24 = F_11 (
V_19 -> V_28 -> V_18 ) ;
else
V_24 = NULL ;
if ( ! V_24 )
return F_3 ( - V_16 ) ;
if ( V_7 && V_24 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_24 ;
}
}
if ( ! V_7 )
return F_3 ( - V_23 ) ;
if ( V_3 != F_7 ( & V_7 -> V_18 ) )
return F_3 ( - V_23 ) ;
return V_7 ;
}
static struct V_6 *
F_12 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
return F_8 ( V_3 , V_30 -> V_5 ) ;
}
static int F_13 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
int V_35 ;
F_14 () ;
if ( ! V_34 -> args [ 0 ] ) {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_43;
* V_17 = F_1 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( * V_17 ) ) {
V_35 = F_18 ( * V_17 ) ;
goto V_43;
}
* V_7 = F_11 ( ( * V_17 ) -> V_18 ) ;
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = ( * V_17 ) -> V_21 ;
} else {
struct V_18 * V_18 = F_19 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 ) {
V_35 = - V_23 ;
goto V_43;
}
* V_7 = F_11 ( V_18 ) ;
* V_17 = NULL ;
F_6 (tmp, &(*rdev)->wiphy.wdev_list, list) {
if ( V_24 -> V_21 == V_34 -> args [ 1 ] ) {
* V_17 = V_24 ;
break;
}
}
if ( ! * V_17 ) {
V_35 = - V_23 ;
goto V_43;
}
}
return 0 ;
V_43:
F_20 () ;
return V_35 ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_20 () ;
}
static bool F_22 ( const struct V_4 * V_45 )
{
const T_2 * V_46 ;
int V_47 ;
if ( ! V_45 )
return true ;
V_46 = F_23 ( V_45 ) ;
V_47 = F_24 ( V_45 ) ;
while ( V_47 ) {
T_2 V_48 ;
if ( V_47 < 2 )
return false ;
V_47 -= 2 ;
V_48 = V_46 [ 1 ] ;
if ( V_48 > V_47 )
return false ;
V_47 -= V_48 ;
V_46 += 2 + V_48 ;
}
return true ;
}
static inline void * F_25 ( struct V_31 * V_32 , V_22 V_49 , V_22 V_50 ,
int V_51 , T_2 V_52 )
{
return F_26 ( V_32 , V_49 , V_50 , & V_38 , V_51 , V_52 ) ;
}
static int F_27 ( struct V_31 * V_53 ,
struct V_54 * V_55 ,
bool V_56 )
{
if ( ! V_56 && V_55 -> V_51 &
( V_57 | V_58 ) )
return 0 ;
if ( F_28 ( V_53 , V_59 ,
V_55 -> V_60 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_62 ) &&
F_29 ( V_53 , V_63 ) )
goto V_61;
if ( V_55 -> V_51 & V_64 ) {
if ( F_29 ( V_53 , V_65 ) )
goto V_61;
if ( F_29 ( V_53 , V_66 ) )
goto V_61;
}
if ( V_55 -> V_51 & V_67 ) {
if ( F_29 ( V_53 , V_68 ) )
goto V_61;
if ( V_56 ) {
V_22 time ;
time = F_30 ( V_55 -> V_69 ) ;
if ( F_28 ( V_53 , V_70 ,
V_55 -> V_71 ) )
goto V_61;
if ( F_28 ( V_53 , V_72 ,
time ) )
goto V_61;
if ( F_28 ( V_53 ,
V_73 ,
V_55 -> V_74 ) )
goto V_61;
}
}
if ( V_56 ) {
if ( ( V_55 -> V_51 & V_75 ) &&
F_29 ( V_53 , V_76 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_77 ) &&
F_29 ( V_53 , V_78 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_79 ) &&
F_29 ( V_53 , V_80 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_81 ) &&
F_29 ( V_53 , V_82 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_83 ) &&
F_29 ( V_53 , V_84 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_85 ) &&
F_29 ( V_53 , V_86 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_58 ) &&
F_29 ( V_53 , V_87 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_57 ) &&
F_29 ( V_53 , V_88 ) )
goto V_61;
}
if ( F_28 ( V_53 , V_89 ,
F_31 ( V_55 -> V_90 ) ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_32 ( struct V_4 * V_92 , struct V_93 * V_94 )
{
struct V_4 * V_95 [ V_96 + 1 ] ;
int V_35 = F_33 ( V_95 , V_96 , V_92 ,
V_97 ) ;
if ( V_35 )
return V_35 ;
V_94 -> V_98 = ! ! V_95 [ V_99 ] ;
V_94 -> V_100 = ! ! V_95 [ V_101 ] ;
if ( V_94 -> V_98 ) {
V_94 -> V_102 = true ;
V_94 -> V_103 = true ;
}
if ( V_94 -> V_100 )
V_94 -> V_103 = true ;
if ( V_95 [ V_104 ] )
V_94 -> V_105 = F_34 ( V_95 [ V_104 ] ) ;
if ( V_95 [ V_106 ] ) {
V_94 -> V_107 . V_92 = F_23 ( V_95 [ V_106 ] ) ;
V_94 -> V_107 . V_108 = F_24 ( V_95 [ V_106 ] ) ;
}
if ( V_95 [ V_109 ] ) {
V_94 -> V_107 . V_50 = F_23 ( V_95 [ V_109 ] ) ;
V_94 -> V_107 . V_110 = F_24 ( V_95 [ V_109 ] ) ;
}
if ( V_95 [ V_111 ] )
V_94 -> V_107 . V_112 = F_4 ( V_95 [ V_111 ] ) ;
if ( V_95 [ V_113 ] ) {
V_94 -> type = F_4 ( V_95 [ V_113 ] ) ;
if ( V_94 -> type < 0 || V_94 -> type >= V_114 )
return - V_16 ;
}
if ( V_95 [ V_115 ] ) {
struct V_4 * V_116 [ V_117 ] ;
V_35 = F_33 ( V_116 , V_117 - 1 ,
V_95 [ V_115 ] ,
V_118 ) ;
if ( V_35 )
return V_35 ;
V_94 -> V_102 = V_116 [ V_119 ] ;
V_94 -> V_103 = V_116 [ V_120 ] ;
}
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , struct V_93 * V_94 )
{
if ( V_30 -> V_5 [ V_121 ] ) {
V_94 -> V_107 . V_92 = F_23 ( V_30 -> V_5 [ V_121 ] ) ;
V_94 -> V_107 . V_108 = F_24 ( V_30 -> V_5 [ V_121 ] ) ;
}
if ( V_30 -> V_5 [ V_122 ] ) {
V_94 -> V_107 . V_50 = F_23 ( V_30 -> V_5 [ V_122 ] ) ;
V_94 -> V_107 . V_110 = F_24 ( V_30 -> V_5 [ V_122 ] ) ;
}
if ( V_30 -> V_5 [ V_123 ] )
V_94 -> V_105 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_30 -> V_5 [ V_124 ] )
V_94 -> V_107 . V_112 = F_4 ( V_30 -> V_5 [ V_124 ] ) ;
V_94 -> V_98 = ! ! V_30 -> V_5 [ V_125 ] ;
V_94 -> V_100 = ! ! V_30 -> V_5 [ V_126 ] ;
if ( V_94 -> V_98 ) {
V_94 -> V_102 = true ;
V_94 -> V_103 = true ;
}
if ( V_94 -> V_100 )
V_94 -> V_103 = true ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_94 -> type = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_94 -> type < 0 || V_94 -> type >= V_114 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_128 ] ) {
struct V_4 * V_116 [ V_117 ] ;
int V_35 = F_33 (
V_116 , V_117 - 1 ,
V_30 -> V_5 [ V_128 ] ,
V_118 ) ;
if ( V_35 )
return V_35 ;
V_94 -> V_102 = V_116 [ V_119 ] ;
V_94 -> V_103 = V_116 [ V_120 ] ;
}
return 0 ;
}
static int F_36 ( struct V_29 * V_30 , struct V_93 * V_94 )
{
int V_35 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_105 = - 1 ;
V_94 -> type = - 1 ;
if ( V_30 -> V_5 [ V_129 ] )
V_35 = F_32 ( V_30 -> V_5 [ V_129 ] , V_94 ) ;
else
V_35 = F_35 ( V_30 , V_94 ) ;
if ( V_35 )
return V_35 ;
if ( V_94 -> V_98 && V_94 -> V_100 )
return - V_16 ;
if ( V_94 -> V_100 ) {
if ( V_94 -> V_102 || ! V_94 -> V_103 )
return - V_16 ;
}
if ( V_94 -> V_105 != - 1 ) {
if ( V_94 -> V_100 ) {
if ( V_94 -> V_105 < 4 || V_94 -> V_105 > 5 )
return - V_16 ;
} else if ( V_94 -> V_98 ) {
if ( V_94 -> V_105 < 0 || V_94 -> V_105 > 3 )
return - V_16 ;
} else {
if ( V_94 -> V_105 < 0 || V_94 -> V_105 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_130 *
F_37 ( struct V_6 * V_7 ,
struct V_4 * V_131 , bool * V_132 )
{
struct V_93 V_133 ;
struct V_4 * V_92 ;
struct V_130 * V_8 ;
int V_134 , V_35 , V_98 = 0 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_135 ) ;
if ( ! V_8 )
return F_3 ( - V_136 ) ;
V_8 -> V_98 = - 1 ;
V_8 -> V_100 = - 1 ;
F_39 (key, keys, rem) {
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_105 = - 1 ;
V_35 = F_32 ( V_92 , & V_133 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_133 . V_107 . V_92 )
goto error;
if ( V_133 . V_105 < 0 || V_133 . V_105 > 4 )
goto error;
if ( V_133 . V_98 ) {
if ( V_98 )
goto error;
V_98 = 1 ;
V_8 -> V_98 = V_133 . V_105 ;
if ( ! V_133 . V_102 || ! V_133 . V_103 )
goto error;
} else if ( V_133 . V_100 )
goto error;
V_35 = F_40 ( V_7 , & V_133 . V_107 ,
V_133 . V_105 , false , NULL ) ;
if ( V_35 )
goto error;
V_8 -> V_137 [ V_133 . V_105 ] . V_112 = V_133 . V_107 . V_112 ;
V_8 -> V_137 [ V_133 . V_105 ] . V_108 = V_133 . V_107 . V_108 ;
V_8 -> V_137 [ V_133 . V_105 ] . V_92 = V_8 -> V_138 [ V_133 . V_105 ] ;
memcpy ( V_8 -> V_138 [ V_133 . V_105 ] , V_133 . V_107 . V_92 , V_133 . V_107 . V_108 ) ;
if ( V_133 . V_107 . V_112 == V_139 ||
V_133 . V_107 . V_112 == V_140 ) {
if ( V_132 )
* V_132 = true ;
}
}
return V_8 ;
error:
F_41 ( V_8 ) ;
return F_3 ( V_35 ) ;
}
static int F_42 ( struct V_1 * V_17 )
{
F_43 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_145 :
break;
case V_146 :
case V_147 :
case V_148 :
if ( ! V_17 -> V_149 )
return - V_150 ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
return - V_16 ;
}
return 0 ;
}
static struct V_54 * F_44 ( struct V_18 * V_18 ,
struct V_4 * V_95 )
{
struct V_54 * V_55 ;
if ( V_95 == NULL )
return NULL ;
V_55 = F_45 ( V_18 , F_4 ( V_95 ) ) ;
if ( ! V_55 || V_55 -> V_51 & V_62 )
return NULL ;
return V_55 ;
}
static int F_46 ( struct V_31 * V_53 , V_22 V_45 , T_3 V_157 )
{
struct V_4 * V_158 = F_47 ( V_53 , V_45 ) ;
int V_159 ;
if ( ! V_158 )
goto V_61;
V_159 = 0 ;
while ( V_157 ) {
if ( ( V_157 & 1 ) && F_29 ( V_53 , V_159 ) )
goto V_61;
V_157 >>= 1 ;
V_159 ++ ;
}
F_48 ( V_53 , V_158 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_49 ( struct V_18 * V_18 ,
struct V_31 * V_53 ,
bool V_56 )
{
struct V_4 * V_160 ;
int V_159 , V_161 ;
V_160 = F_47 ( V_53 ,
V_162 ) ;
if ( ! V_160 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_18 -> V_163 ; V_159 ++ ) {
const struct V_164 * V_165 ;
struct V_4 * V_166 , * V_167 ;
V_165 = & V_18 -> V_168 [ V_159 ] ;
V_166 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_166 )
goto V_61;
V_167 = F_47 ( V_53 , V_169 ) ;
if ( ! V_167 )
goto V_61;
for ( V_161 = 0 ; V_161 < V_165 -> V_170 ; V_161 ++ ) {
struct V_4 * V_171 ;
V_171 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_171 )
goto V_61;
if ( F_28 ( V_53 , V_172 ,
V_165 -> V_173 [ V_161 ] . V_174 ) )
goto V_61;
if ( F_46 ( V_53 , V_175 ,
V_165 -> V_173 [ V_161 ] . V_176 ) )
goto V_61;
F_48 ( V_53 , V_171 ) ;
}
F_48 ( V_53 , V_167 ) ;
if ( V_165 -> V_177 &&
F_29 ( V_53 , V_178 ) )
goto V_61;
if ( F_28 ( V_53 , V_179 ,
V_165 -> V_180 ) ||
F_28 ( V_53 , V_181 ,
V_165 -> V_182 ) )
goto V_61;
if ( V_56 &&
( F_28 ( V_53 , V_183 ,
V_165 -> V_184 ) ||
F_28 ( V_53 , V_185 ,
V_165 -> V_186 ) ) )
goto V_61;
F_48 ( V_53 , V_166 ) ;
}
F_48 ( V_53 , V_160 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
const struct V_187 * V_188 = V_7 -> V_18 . V_189 -> V_188 ;
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_28 ( V_53 , V_192 ,
V_188 -> V_193 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_192 ,
V_188 -> V_193 ) )
return - V_91 ;
if ( V_188 -> V_50 && F_29 ( V_53 , V_194 ) )
return - V_91 ;
if ( V_188 -> V_195 && F_51 ( V_53 , V_196 ,
sizeof( * V_188 -> V_195 ) , V_188 -> V_195 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_197 ,
V_188 -> V_198 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_199 ,
V_188 -> V_200 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
bool V_56 )
{
struct V_4 * V_201 ;
if ( ! V_7 -> V_18 . V_189 )
return 0 ;
V_201 = F_47 ( V_53 , V_202 ) ;
if ( ! V_201 )
return - V_91 ;
if ( ( ( V_7 -> V_18 . V_189 -> V_51 & V_203 ) &&
F_29 ( V_53 , V_204 ) ) ||
( ( V_7 -> V_18 . V_189 -> V_51 & V_205 ) &&
F_29 ( V_53 , V_206 ) ) ||
( ( V_7 -> V_18 . V_189 -> V_51 & V_207 ) &&
F_29 ( V_53 , V_208 ) ) ||
( ( V_7 -> V_18 . V_189 -> V_51 & V_209 ) &&
F_29 ( V_53 , V_210 ) ) ||
( ( V_7 -> V_18 . V_189 -> V_51 & V_211 ) &&
F_29 ( V_53 , V_212 ) ) ||
( ( V_7 -> V_18 . V_189 -> V_51 & V_213 ) &&
F_29 ( V_53 , V_214 ) ) ||
( ( V_7 -> V_18 . V_189 -> V_51 & V_215 ) &&
F_29 ( V_53 , V_216 ) ) ||
( ( V_7 -> V_18 . V_189 -> V_51 & V_217 ) &&
F_29 ( V_53 , V_218 ) ) )
return - V_91 ;
if ( V_7 -> V_18 . V_189 -> V_219 ) {
struct V_220 V_221 = {
. V_222 = V_7 -> V_18 . V_189 -> V_219 ,
. V_223 = V_7 -> V_18 . V_189 -> V_224 ,
. V_225 = V_7 -> V_18 . V_189 -> V_226 ,
. V_227 = V_7 -> V_18 . V_189 -> V_227 ,
} ;
if ( F_51 ( V_53 , V_228 ,
sizeof( V_221 ) , & V_221 ) )
return - V_91 ;
}
if ( ( V_7 -> V_18 . V_189 -> V_51 & V_229 ) &&
F_28 ( V_53 , V_230 ,
V_7 -> V_18 . V_189 -> V_231 ) )
return - V_91 ;
if ( V_56 && F_50 ( V_7 , V_53 ) )
return - V_91 ;
F_48 ( V_53 , V_201 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_232 V_233 ;
if ( ! V_7 -> V_18 . V_234 )
return 0 ;
V_233 . V_235 = V_7 -> V_18 . V_234 -> V_236 ;
V_233 . V_237 = V_7 -> V_18 . V_234 -> V_237 ;
V_233 . V_221 . V_222 = V_7 -> V_18 . V_234 -> V_219 ;
V_233 . V_221 . V_223 = V_7 -> V_18 . V_234 -> V_224 ;
V_233 . V_221 . V_225 = V_7 -> V_18 . V_234 -> V_226 ;
V_233 . V_221 . V_227 = V_7 -> V_18 . V_234 -> V_227 ;
if ( F_51 ( V_53 , V_238 , sizeof( V_233 ) , & V_233 ) )
return - V_91 ;
return 0 ;
}
static int F_54 ( struct V_31 * V_53 ,
struct V_239 * V_240 )
{
struct V_4 * V_241 , * V_242 ;
struct V_243 * V_244 ;
int V_159 ;
if ( V_240 -> V_245 . V_246 &&
( F_51 ( V_53 , V_247 ,
sizeof( V_240 -> V_245 . V_248 ) ,
& V_240 -> V_245 . V_248 ) ||
F_55 ( V_53 , V_249 ,
V_240 -> V_245 . V_250 ) ||
F_56 ( V_53 , V_251 ,
V_240 -> V_245 . V_252 ) ||
F_56 ( V_53 , V_253 ,
V_240 -> V_245 . V_254 ) ) )
return - V_91 ;
if ( V_240 -> V_255 . V_256 &&
( F_51 ( V_53 , V_257 ,
sizeof( V_240 -> V_255 . V_258 ) ,
& V_240 -> V_255 . V_258 ) ||
F_28 ( V_53 , V_259 ,
V_240 -> V_255 . V_250 ) ) )
return - V_91 ;
V_241 = F_47 ( V_53 , V_260 ) ;
if ( ! V_241 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_240 -> V_261 ; V_159 ++ ) {
V_242 = F_47 ( V_53 , V_159 ) ;
if ( ! V_242 )
return - V_91 ;
V_244 = & V_240 -> V_262 [ V_159 ] ;
if ( F_28 ( V_53 , V_263 ,
V_244 -> V_264 ) )
return - V_91 ;
if ( ( V_244 -> V_51 & V_265 ) &&
F_29 ( V_53 ,
V_266 ) )
return - V_91 ;
F_48 ( V_53 , V_242 ) ;
}
F_48 ( V_53 , V_241 ) ;
return 0 ;
}
static int
F_57 ( struct V_31 * V_53 ,
const struct V_267 * V_268 )
{
T_3 V_269 ;
struct V_4 * V_270 , * V_271 ;
enum V_272 V_273 ;
int V_159 ;
if ( ! V_268 )
return 0 ;
V_271 = F_47 ( V_53 , V_274 ) ;
if ( ! V_271 )
return - V_91 ;
for ( V_273 = 0 ; V_273 < V_156 ; V_273 ++ ) {
V_270 = F_47 ( V_53 , V_273 ) ;
if ( ! V_270 )
return - V_91 ;
V_159 = 0 ;
V_269 = V_268 [ V_273 ] . V_275 ;
while ( V_269 ) {
if ( ( V_269 & 1 ) &&
F_55 ( V_53 , V_276 ,
( V_159 << 4 ) | V_277 ) )
return - V_91 ;
V_269 >>= 1 ;
V_159 ++ ;
}
F_48 ( V_53 , V_270 ) ;
}
F_48 ( V_53 , V_271 ) ;
V_271 = F_47 ( V_53 , V_278 ) ;
if ( ! V_271 )
return - V_91 ;
for ( V_273 = 0 ; V_273 < V_156 ; V_273 ++ ) {
V_270 = F_47 ( V_53 , V_273 ) ;
if ( ! V_270 )
return - V_91 ;
V_159 = 0 ;
V_269 = V_268 [ V_273 ] . V_279 ;
while ( V_269 ) {
if ( ( V_269 & 1 ) &&
F_55 ( V_53 , V_276 ,
( V_159 << 4 ) | V_277 ) )
return - V_91 ;
V_269 >>= 1 ;
V_159 ++ ;
}
F_48 ( V_53 , V_270 ) ;
}
F_48 ( V_53 , V_271 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
enum V_280 V_52 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_281 * V_282 )
{
void * V_283 ;
struct V_4 * V_284 , * V_285 ;
struct V_4 * V_286 , * V_287 ;
struct V_4 * V_288 ;
enum V_289 V_290 ;
struct V_54 * V_55 ;
int V_159 ;
const struct V_267 * V_268 =
V_7 -> V_18 . V_268 ;
V_22 V_291 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - V_91 ;
if ( F_59 ( ! V_282 ) )
return - V_16 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_60 ( V_53 , V_292 ,
F_61 ( & V_7 -> V_18 ) ) ||
F_28 ( V_53 , V_293 ,
V_294 ) )
goto V_61;
if ( V_52 != V_295 )
goto V_296;
switch ( V_282 -> V_297 ) {
case 0 :
if ( F_56 ( V_53 , V_298 ,
V_7 -> V_18 . V_299 ) ||
F_56 ( V_53 , V_300 ,
V_7 -> V_18 . V_301 ) ||
F_28 ( V_53 , V_302 ,
V_7 -> V_18 . V_303 ) ||
F_28 ( V_53 , V_304 ,
V_7 -> V_18 . V_305 ) ||
F_56 ( V_53 , V_306 ,
V_7 -> V_18 . V_307 ) ||
F_56 ( V_53 , V_308 ,
V_7 -> V_18 . V_309 ) ||
F_56 ( V_53 , V_310 ,
V_7 -> V_18 . V_311 ) ||
F_55 ( V_53 , V_312 ,
V_7 -> V_18 . V_313 ) ||
F_55 ( V_53 , V_314 ,
V_7 -> V_18 . V_315 ) ||
F_56 ( V_53 , V_316 ,
V_7 -> V_18 . V_317 ) ||
F_28 ( V_53 , V_318 ,
V_7 -> V_18 . V_319 ) ||
F_28 ( V_53 , V_320 ,
V_7 -> V_18 . V_321 ) ||
F_28 ( V_53 , V_322 ,
V_7 -> V_18 . V_323 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_324 ) &&
F_29 ( V_53 , V_325 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_326 ) &&
F_29 ( V_53 , V_327 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_328 ) &&
F_29 ( V_53 , V_329 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_330 ) &&
F_29 ( V_53 , V_331 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_332 ) &&
F_29 ( V_53 , V_333 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_334 ) &&
F_29 ( V_53 , V_335 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
case 1 :
if ( F_51 ( V_53 , V_337 ,
sizeof( V_22 ) * V_7 -> V_18 . V_338 ,
V_7 -> V_18 . V_339 ) )
goto V_61;
if ( F_56 ( V_53 , V_340 ,
V_7 -> V_18 . V_341 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_342 ) &&
F_29 ( V_53 , V_343 ) )
goto V_61;
if ( F_28 ( V_53 , V_344 ,
V_7 -> V_18 . V_345 ) ||
F_28 ( V_53 , V_346 ,
V_7 -> V_18 . V_347 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_348 ) &&
F_28 ( V_53 , V_349 ,
V_7 -> V_18 . V_350 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_345 ||
V_7 -> V_18 . V_347 ) &&
V_7 -> V_351 -> V_352 ) {
V_22 V_353 = 0 , V_354 = 0 ;
int V_355 ;
V_355 = F_62 ( V_7 , & V_353 , & V_354 ) ;
if ( ! V_355 ) {
if ( F_28 ( V_53 ,
V_356 ,
V_353 ) ||
F_28 ( V_53 ,
V_357 ,
V_354 ) )
goto V_61;
}
}
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
case 2 :
if ( F_46 ( V_53 , V_358 ,
V_7 -> V_18 . V_359 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
case 3 :
V_284 = F_47 ( V_53 , V_360 ) ;
if ( ! V_284 )
goto V_61;
for ( V_290 = V_282 -> V_361 ;
V_290 < V_362 ; V_290 ++ ) {
struct V_239 * V_240 ;
V_240 = V_7 -> V_18 . V_363 [ V_290 ] ;
if ( ! V_240 )
continue;
V_285 = F_47 ( V_53 , V_290 ) ;
if ( ! V_285 )
goto V_61;
switch ( V_282 -> V_364 ) {
case 0 :
if ( F_54 ( V_53 , V_240 ) )
goto V_61;
V_282 -> V_364 ++ ;
if ( V_282 -> V_336 )
break;
default:
V_286 = F_47 (
V_53 , V_365 ) ;
if ( ! V_286 )
goto V_61;
for ( V_159 = V_282 -> V_364 - 1 ;
V_159 < V_240 -> V_366 ;
V_159 ++ ) {
V_287 = F_47 ( V_53 , V_159 ) ;
if ( ! V_287 )
goto V_61;
V_55 = & V_240 -> V_367 [ V_159 ] ;
if ( F_27 (
V_53 , V_55 ,
V_282 -> V_336 ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
if ( V_282 -> V_336 )
break;
}
if ( V_159 < V_240 -> V_366 )
V_282 -> V_364 = V_159 + 2 ;
else
V_282 -> V_364 = 0 ;
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_285 ) ;
if ( V_282 -> V_336 ) {
if ( V_282 -> V_364 )
V_290 -- ;
break;
}
}
F_48 ( V_53 , V_284 ) ;
if ( V_290 < V_362 )
V_282 -> V_361 = V_290 + 1 ;
else
V_282 -> V_361 = 0 ;
if ( V_282 -> V_361 == 0 && V_282 -> V_364 == 0 )
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
case 4 :
V_288 = F_47 ( V_53 , V_368 ) ;
if ( ! V_288 )
goto V_61;
V_159 = 0 ;
#define F_63 ( T_4 , T_5 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_63 ( V_369 , V_370 ) ;
F_63 ( V_371 , V_372 ) ;
F_63 ( V_373 , V_374 ) ;
F_63 ( V_375 , V_376 ) ;
F_63 ( V_377 , V_378 ) ;
F_63 ( V_379 , V_380 ) ;
F_63 ( V_381 , V_382 ) ;
F_63 ( V_383 , V_384 ) ;
F_63 ( V_385 , V_386 ) ;
F_63 ( V_387 , V_388 ) ;
F_63 ( V_389 , V_390 ) ;
F_63 ( V_391 , V_392 ) ;
F_63 ( V_393 , V_394 ) ;
F_63 ( V_395 , V_396 ) ;
F_63 ( V_397 , V_398 ) ;
F_63 ( V_399 , V_400 ) ;
F_63 ( V_401 , V_402 ) ;
if ( V_7 -> V_18 . V_51 & V_403 )
F_63 ( V_404 , V_405 ) ;
F_63 ( V_406 , V_407 ) ;
F_63 ( V_408 , V_409 ) ;
F_63 ( V_410 , V_411 ) ;
if ( V_7 -> V_18 . V_51 & V_412 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_413 ) )
goto V_61;
}
if ( V_7 -> V_351 -> V_414 || V_7 -> V_351 -> V_375 ||
V_7 -> V_351 -> V_395 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_415 ) )
goto V_61;
}
F_63 ( V_416 , V_417 ) ;
if ( V_7 -> V_18 . V_51 & V_332 ) {
F_63 ( V_418 , V_419 ) ;
F_63 ( V_420 , V_421 ) ;
}
if ( V_7 -> V_18 . V_51 & V_422 )
F_63 ( V_423 , V_424 ) ;
F_63 ( V_425 , V_426 ) ;
F_63 ( V_427 , V_428 ) ;
if ( V_7 -> V_18 . V_51 & V_429 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_430 ) )
goto V_61;
}
F_63 ( V_431 , V_432 ) ;
F_63 ( V_433 , V_434 ) ;
#ifdef F_64
F_63 ( V_435 , V_436 ) ;
#endif
if ( V_282 -> V_336 ) {
F_63 ( V_437 , V_438 ) ;
F_63 ( V_439 , V_440 ) ;
if ( V_7 -> V_18 . V_51 & V_441 )
F_63 ( V_442 , V_443 ) ;
F_63 ( V_444 , V_445 ) ;
if ( V_7 -> V_18 . V_291 &
V_446 )
F_63 ( V_447 , V_448 ) ;
}
#undef F_63
if ( V_7 -> V_351 -> V_449 || V_7 -> V_351 -> V_385 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_450 ) )
goto V_61;
}
if ( V_7 -> V_351 -> V_451 || V_7 -> V_351 -> V_389 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_452 ) )
goto V_61;
}
F_48 ( V_53 , V_288 ) ;
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
case 5 :
if ( V_7 -> V_351 -> V_404 &&
( V_7 -> V_18 . V_51 & V_403 ) &&
F_28 ( V_53 ,
V_453 ,
V_7 -> V_18 . V_454 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_455 ) &&
F_29 ( V_53 , V_456 ) )
goto V_61;
if ( F_57 ( V_53 , V_268 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
case 6 :
#ifdef F_65
if ( F_52 ( V_53 , V_7 , V_282 -> V_336 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
#else
V_282 -> V_297 ++ ;
#endif
case 7 :
if ( F_46 ( V_53 , V_457 ,
V_7 -> V_18 . V_458 ) )
goto V_61;
if ( F_49 ( & V_7 -> V_18 , V_53 ,
V_282 -> V_336 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_336 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_51 & V_459 ) &&
F_28 ( V_53 , V_460 ,
V_7 -> V_18 . V_461 ) )
goto V_61;
V_291 = V_7 -> V_18 . V_291 ;
if ( V_282 -> V_336 )
V_291 |= V_462 ;
if ( F_28 ( V_53 , V_463 , V_291 ) )
goto V_61;
if ( V_7 -> V_18 . V_464 &&
F_51 ( V_53 , V_465 ,
sizeof( * V_7 -> V_18 . V_464 ) ,
V_7 -> V_18 . V_464 ) )
goto V_61;
if ( V_7 -> V_18 . V_51 & V_459 &&
V_7 -> V_18 . V_466 &&
F_28 ( V_53 , V_467 ,
V_7 -> V_18 . V_466 ) )
goto V_61;
V_282 -> V_297 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_468 &&
( F_51 ( V_53 , V_469 ,
V_7 -> V_18 . V_470 ,
V_7 -> V_18 . V_468 ) ||
F_51 ( V_53 , V_471 ,
V_7 -> V_18 . V_470 ,
V_7 -> V_18 . V_472 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_473 &&
F_51 ( V_53 , V_474 ,
sizeof( * V_7 -> V_18 . V_473 ) ,
V_7 -> V_18 . V_473 ) )
goto V_61;
V_282 -> V_297 ++ ;
break;
case 10 :
if ( F_53 ( V_53 , V_7 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_475 ) &&
( F_29 ( V_53 , V_476 ) ||
F_29 ( V_53 , V_477 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_478 &&
F_28 ( V_53 , V_479 ,
V_7 -> V_18 . V_478 ) )
goto V_61;
V_282 -> V_297 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_480 ) {
const struct V_481 * V_30 ;
struct V_4 * V_482 ;
V_482 = F_47 ( V_53 , V_483 ) ;
if ( ! V_482 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_480 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_484 [ V_159 ] . V_30 ;
if ( F_51 ( V_53 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_482 ) ;
}
if ( V_7 -> V_18 . V_485 ) {
const struct V_481 * V_30 ;
struct V_4 * V_482 ;
V_482 = F_47 ( V_53 ,
V_486 ) ;
if ( ! V_482 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_485 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_487 [ V_159 ] ;
if ( F_51 ( V_53 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_482 ) ;
}
V_282 -> V_297 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_51 & V_441 &&
F_56 ( V_53 , V_488 ,
V_7 -> V_18 . V_489 ) )
goto V_61;
if ( V_7 -> V_18 . V_490 & V_491 &&
F_29 ( V_53 , V_492 ) )
goto V_61;
if ( F_51 ( V_53 , V_493 ,
sizeof( V_7 -> V_18 . V_494 ) ,
V_7 -> V_18 . V_494 ) )
goto V_61;
if ( V_7 -> V_18 . V_495 ) {
struct V_4 * V_482 ;
V_22 V_495 = V_7 -> V_18 . V_495 ;
V_482 = F_47 ( V_53 , V_496 ) ;
if ( ! V_482 )
goto V_61;
V_159 = 0 ;
while ( V_495 ) {
if ( ( V_495 & 1 ) &&
F_29 ( V_53 , V_159 ) )
goto V_61;
V_159 ++ ;
V_495 >>= 1 ;
}
F_48 ( V_53 , V_482 ) ;
}
V_282 -> V_297 = 0 ;
break;
}
V_296:
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_281 * V_282 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_498 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_498 )
return 0 ;
V_282 -> V_336 = V_95 [ V_499 ] ;
if ( V_95 [ V_26 ] )
V_282 -> V_500 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_282 -> V_500 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
if ( V_95 [ V_10 ] ) {
struct V_25 * V_19 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_95 [ V_10 ] ) ;
V_19 = F_10 ( F_16 ( V_32 -> V_44 ) , V_15 ) ;
if ( ! V_19 )
return - V_23 ;
if ( V_19 -> V_28 ) {
V_7 = F_11 (
V_19 -> V_28 -> V_18 ) ;
V_282 -> V_500 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_498 ;
struct V_281 * V_282 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_282 ) {
V_282 = F_38 ( sizeof( * V_282 ) , V_135 ) ;
if ( ! V_282 ) {
F_20 () ;
return - V_136 ;
}
V_282 -> V_500 = - 1 ;
V_498 = F_68 ( V_32 , V_34 , V_282 ) ;
if ( V_498 ) {
F_41 ( V_282 ) ;
F_20 () ;
return V_498 ;
}
V_34 -> args [ 0 ] = ( long ) V_282 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_282 -> V_501 )
continue;
if ( V_282 -> V_500 != - 1 &&
V_282 -> V_500 != V_7 -> V_14 )
continue;
do {
V_498 = F_58 ( V_7 , V_295 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 ,
V_503 , V_282 ) ;
if ( V_498 < 0 ) {
if ( ( V_498 == - V_91 || V_498 == - V_497 ) &&
! V_32 -> V_47 && ! V_282 -> V_336 &&
V_34 -> V_504 < 4096 ) {
V_34 -> V_504 = 4096 ;
V_282 -> V_297 = 0 ;
F_20 () ;
return 1 ;
}
V_105 -- ;
break;
}
} while ( V_282 -> V_297 > 0 );
break;
}
F_20 () ;
V_282 -> V_501 = V_105 ;
return V_32 -> V_47 ;
}
static int F_72 ( struct V_33 * V_34 )
{
F_41 ( ( void * ) V_34 -> args [ 0 ] ) ;
return 0 ;
}
static int F_73 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_281 V_282 = {} ;
V_53 = F_74 ( 4096 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_58 ( V_7 , V_295 , V_53 ,
V_30 -> V_506 , V_30 -> V_507 , 0 ,
& V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_508 * V_509 )
{
if ( ! V_95 [ V_510 ] || ! V_95 [ V_511 ] ||
! V_95 [ V_512 ] || ! V_95 [ V_513 ] ||
! V_95 [ V_514 ] )
return - V_16 ;
V_509 -> V_515 = F_34 ( V_95 [ V_510 ] ) ;
V_509 -> V_516 = F_78 ( V_95 [ V_511 ] ) ;
V_509 -> V_517 = F_78 ( V_95 [ V_512 ] ) ;
V_509 -> V_518 = F_78 ( V_95 [ V_513 ] ) ;
V_509 -> V_519 = F_34 ( V_95 [ V_514 ] ) ;
if ( V_509 -> V_515 >= V_520 )
return - V_16 ;
return 0 ;
}
static bool F_79 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_141 == V_142 ||
V_17 -> V_141 == V_145 ||
V_17 -> V_141 == V_153 ||
V_17 -> V_141 == V_144 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_521 * V_522 )
{
V_22 V_523 ;
if ( ! V_30 -> V_5 [ V_524 ] )
return - V_16 ;
V_523 = F_4 ( V_30 -> V_5 [ V_524 ] ) ;
V_522 -> V_55 = F_45 ( & V_7 -> V_18 , V_523 ) ;
V_522 -> V_525 = V_526 ;
V_522 -> V_527 = V_523 ;
V_522 -> V_528 = 0 ;
if ( ! V_522 -> V_55 || V_522 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_529 ] ) {
enum V_530 V_531 ;
V_531 = F_4 (
V_30 -> V_5 [ V_529 ] ) ;
switch ( V_531 ) {
case V_532 :
case V_533 :
case V_534 :
case V_535 :
F_81 ( V_522 , V_522 -> V_55 ,
V_531 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_536 ] ) {
V_522 -> V_525 =
F_4 ( V_30 -> V_5 [ V_536 ] ) ;
if ( V_30 -> V_5 [ V_537 ] )
V_522 -> V_527 =
F_4 (
V_30 -> V_5 [ V_537 ] ) ;
if ( V_30 -> V_5 [ V_538 ] )
V_522 -> V_528 =
F_4 (
V_30 -> V_5 [ V_538 ] ) ;
}
if ( ! F_82 ( V_522 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_522 ,
V_62 ) )
return - V_16 ;
if ( ( V_522 -> V_525 == V_539 ||
V_522 -> V_525 == V_540 ) &&
! ( V_7 -> V_18 . V_51 & V_475 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_541 ,
struct V_29 * V_30 )
{
struct V_521 V_522 ;
int V_8 ;
enum V_272 V_141 = V_153 ;
struct V_1 * V_17 = NULL ;
if ( V_541 )
V_17 = V_541 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_542 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_80 ( V_7 , V_30 , & V_522 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_85 ( & V_7 -> V_18 , & V_522 ,
V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_543 ) {
if ( ! V_541 || ! V_7 -> V_351 -> V_544 ||
! ( V_7 -> V_18 . V_291 &
V_545 ) ) {
V_8 = - V_546 ;
break;
}
if ( V_522 . V_55 != V_17 -> V_547 . V_55 ) {
V_8 = - V_546 ;
break;
}
V_8 = F_86 ( V_7 , V_541 , & V_522 ) ;
if ( V_8 )
break;
}
V_17 -> V_547 = V_522 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_87 ( V_7 , V_17 , & V_522 ) ;
break;
case V_153 :
V_8 = F_88 ( V_7 , & V_522 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_505 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
const T_2 * V_548 ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( F_91 ( V_541 ) )
return - V_546 ;
if ( ! V_7 -> V_351 -> V_416 )
return - V_542 ;
if ( V_17 -> V_141 != V_155 )
return - V_542 ;
V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
return F_92 ( V_7 , V_541 , V_548 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_550 = 0 ;
struct V_4 * V_551 ;
V_22 V_552 ;
T_2 V_299 = 0 , V_301 = 0 ;
V_22 V_303 = 0 , V_305 = 0 ;
T_2 V_307 = 0 ;
F_2 () ;
if ( V_30 -> V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_30 -> V_5 [ V_10 ] ) ;
V_19 = F_10 ( F_94 ( V_30 ) , V_20 ) ;
if ( V_19 && V_19 -> V_28 )
V_7 = F_11 ( V_19 -> V_28 -> V_18 ) ;
else
V_19 = NULL ;
}
if ( ! V_19 ) {
V_7 = F_8 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_7 ) )
return F_18 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_292 ] )
V_8 = F_95 (
V_7 , F_23 ( V_30 -> V_5 [ V_292 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_553 ] ) {
struct V_508 V_509 ;
struct V_4 * V_95 [ V_554 + 1 ] ;
if ( ! V_7 -> V_351 -> V_555 )
return - V_542 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_556 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_554 ,
F_23 ( V_551 ) ,
F_24 ( V_551 ) ,
V_557 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_509 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_509 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_524 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_558 ] ) {
struct V_1 * V_559 = V_17 ;
enum V_560 type ;
int V_105 , V_561 = 0 ;
if ( ! ( V_7 -> V_18 . V_291 & V_562 ) )
V_559 = NULL ;
if ( ! V_7 -> V_351 -> V_563 )
return - V_542 ;
V_105 = V_558 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_564 ] &&
( type != V_565 ) )
return - V_16 ;
if ( type != V_565 ) {
V_105 = V_564 ;
V_561 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_559 , type , V_561 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_356 ] &&
V_30 -> V_5 [ V_357 ] ) {
V_22 V_353 , V_354 ;
if ( ( ! V_7 -> V_18 . V_345 &&
! V_7 -> V_18 . V_347 ) ||
! V_7 -> V_351 -> V_566 )
return - V_542 ;
V_353 = F_4 ( V_30 -> V_5 [ V_356 ] ) ;
V_354 = F_4 ( V_30 -> V_5 [ V_357 ] ) ;
if ( ( ~ V_353 && ( V_353 & ~ V_7 -> V_18 . V_345 ) ) ||
( ~ V_354 && ( V_354 & ~ V_7 -> V_18 . V_347 ) ) )
return - V_16 ;
V_353 = V_353 & V_7 -> V_18 . V_345 ;
V_354 = V_354 & V_7 -> V_18 . V_347 ;
V_8 = F_99 ( V_7 , V_353 , V_354 ) ;
if ( V_8 )
return V_8 ;
}
V_552 = 0 ;
if ( V_30 -> V_5 [ V_298 ] ) {
V_299 = F_34 (
V_30 -> V_5 [ V_298 ] ) ;
if ( V_299 == 0 )
return - V_16 ;
V_552 |= V_567 ;
}
if ( V_30 -> V_5 [ V_300 ] ) {
V_301 = F_34 (
V_30 -> V_5 [ V_300 ] ) ;
if ( V_301 == 0 )
return - V_16 ;
V_552 |= V_568 ;
}
if ( V_30 -> V_5 [ V_302 ] ) {
V_303 = F_4 (
V_30 -> V_5 [ V_302 ] ) ;
if ( V_303 < 256 )
return - V_16 ;
if ( V_303 != ( V_22 ) - 1 ) {
V_303 &= ~ 0x1 ;
}
V_552 |= V_569 ;
}
if ( V_30 -> V_5 [ V_304 ] ) {
V_305 = F_4 (
V_30 -> V_5 [ V_304 ] ) ;
V_552 |= V_570 ;
}
if ( V_30 -> V_5 [ V_306 ] ) {
if ( V_30 -> V_5 [ V_571 ] )
return - V_16 ;
V_307 = F_34 (
V_30 -> V_5 [ V_306 ] ) ;
V_552 |= V_572 ;
}
if ( V_30 -> V_5 [ V_571 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_573 ) )
return - V_542 ;
V_552 |= V_574 ;
}
if ( V_552 ) {
T_2 V_575 , V_576 ;
V_22 V_577 , V_578 ;
T_2 V_579 ;
if ( ! V_7 -> V_351 -> V_580 )
return - V_542 ;
V_575 = V_7 -> V_18 . V_299 ;
V_576 = V_7 -> V_18 . V_301 ;
V_577 = V_7 -> V_18 . V_303 ;
V_578 = V_7 -> V_18 . V_305 ;
V_579 = V_7 -> V_18 . V_307 ;
if ( V_552 & V_567 )
V_7 -> V_18 . V_299 = V_299 ;
if ( V_552 & V_568 )
V_7 -> V_18 . V_301 = V_301 ;
if ( V_552 & V_569 )
V_7 -> V_18 . V_303 = V_303 ;
if ( V_552 & V_570 )
V_7 -> V_18 . V_305 = V_305 ;
if ( V_552 & V_572 )
V_7 -> V_18 . V_307 = V_307 ;
V_8 = F_100 ( V_7 , V_552 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_299 = V_575 ;
V_7 -> V_18 . V_301 = V_576 ;
V_7 -> V_18 . V_303 = V_577 ;
V_7 -> V_18 . V_305 = V_578 ;
V_7 -> V_18 . V_307 = V_579 ;
return V_8 ;
}
}
return 0 ;
}
static inline T_1 V_13 ( struct V_1 * V_17 )
{
return ( T_1 ) V_17 -> V_21 |
( ( T_1 ) F_11 ( V_17 -> V_18 ) -> V_14 << 32 ) ;
}
static int F_101 ( struct V_31 * V_53 ,
const struct V_521 * V_522 )
{
if ( F_59 ( ! F_82 ( V_522 ) ) )
return - V_16 ;
if ( F_28 ( V_53 , V_524 ,
V_522 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_522 -> V_525 ) {
case V_526 :
case V_581 :
case V_582 :
if ( F_28 ( V_53 , V_529 ,
F_102 ( V_522 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_536 , V_522 -> V_525 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_537 , V_522 -> V_527 ) )
return - V_91 ;
if ( V_522 -> V_528 &&
F_28 ( V_53 , V_538 , V_522 -> V_528 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_583 )
{
struct V_25 * V_541 = V_17 -> V_19 ;
T_2 V_52 = V_584 ;
void * V_283 ;
if ( V_583 )
V_52 = V_585 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( V_541 &&
( F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_60 ( V_53 , V_586 , V_541 -> V_587 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_588 , V_17 -> V_141 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) ||
F_51 ( V_53 , V_549 , V_590 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_293 ,
V_7 -> V_591 ^
( V_294 << 2 ) ) )
goto V_61;
if ( V_7 -> V_351 -> V_592 ) {
int V_498 ;
struct V_521 V_522 ;
V_498 = F_106 ( V_7 , V_17 , & V_522 ) ;
if ( V_498 == 0 ) {
if ( F_101 ( V_53 , & V_522 ) )
goto V_61;
}
}
if ( V_7 -> V_351 -> V_593 ) {
int V_594 , V_498 ;
V_498 = F_107 ( V_7 , V_17 , & V_594 ) ;
if ( V_498 == 0 &&
F_28 ( V_53 , V_564 ,
F_31 ( V_594 ) ) )
goto V_61;
}
if ( V_17 -> V_595 ) {
if ( F_51 ( V_53 , V_596 , V_17 -> V_595 , V_17 -> V_597 ) )
goto V_61;
}
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_598 = 0 ;
int V_599 = 0 ;
int V_600 = V_34 -> args [ 0 ] ;
int V_601 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_598 < V_600 ) {
V_598 ++ ;
continue;
}
V_599 = 0 ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_599 < V_601 ) {
V_599 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_7 , V_17 , false ) < 0 ) {
goto V_602;
}
V_599 ++ ;
}
V_598 ++ ;
}
V_602:
F_20 () ;
V_34 -> args [ 0 ] = V_598 ;
V_34 -> args [ 1 ] = V_599 ;
return V_32 -> V_47 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_103 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_110 ( struct V_4 * V_604 , V_22 * V_605 )
{
struct V_4 * V_51 [ V_606 + 1 ] ;
int V_607 ;
* V_605 = 0 ;
if ( ! V_604 )
return - V_16 ;
if ( F_33 ( V_51 , V_606 ,
V_604 , V_608 ) )
return - V_16 ;
for ( V_607 = 1 ; V_607 <= V_606 ; V_607 ++ )
if ( V_51 [ V_607 ] )
* V_605 |= ( 1 << V_607 ) ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_609 ,
enum V_272 V_141 )
{
if ( ! V_609 ) {
if ( V_19 && ( V_19 -> V_610 & V_611 ) )
return - V_546 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_51 & V_612 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_51 & V_613 )
return 0 ;
break;
default:
break;
}
return - V_542 ;
}
static int F_112 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_614 V_137 ;
int V_35 ;
enum V_272 V_615 , V_616 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
V_22 V_617 , * V_51 = NULL ;
bool V_618 = false ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_615 = V_616 = V_541 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_588 ] ) {
V_616 = F_4 ( V_30 -> V_5 [ V_588 ] ) ;
if ( V_615 != V_616 )
V_618 = true ;
if ( V_616 > V_619 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_620 ] ) {
struct V_1 * V_17 = V_541 -> V_28 ;
if ( V_616 != V_145 )
return - V_16 ;
if ( F_91 ( V_541 ) )
return - V_546 ;
F_113 ( V_17 ) ;
F_114 ( V_621 !=
V_622 ) ;
V_17 -> V_623 =
F_24 ( V_30 -> V_5 [ V_620 ] ) ;
memcpy ( V_17 -> V_597 , F_23 ( V_30 -> V_5 [ V_620 ] ) ,
V_17 -> V_623 ) ;
F_115 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_624 ] ) {
V_137 . V_609 = ! ! F_34 ( V_30 -> V_5 [ V_624 ] ) ;
V_618 = true ;
V_35 = F_111 ( V_7 , V_541 , V_137 . V_609 , V_616 ) ;
if ( V_35 )
return V_35 ;
} else {
V_137 . V_609 = - 1 ;
}
if ( V_30 -> V_5 [ V_625 ] ) {
if ( V_616 != V_153 )
return - V_16 ;
V_35 = F_110 ( V_30 -> V_5 [ V_625 ] ,
& V_617 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_617 ;
V_618 = true ;
}
if ( V_51 && ( * V_51 & V_626 ) &&
! ( V_7 -> V_18 . V_291 & V_627 ) )
return - V_542 ;
if ( V_618 )
V_35 = F_116 ( V_7 , V_541 , V_616 , V_51 , & V_137 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_137 . V_609 != - 1 )
V_541 -> V_28 -> V_609 = V_137 . V_609 ;
return V_35 ;
}
static int F_117 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_614 V_137 ;
struct V_1 * V_17 ;
struct V_31 * V_53 , * V_628 ;
int V_35 ;
enum V_272 type = V_151 ;
V_22 V_51 ;
F_118 ( V_7 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_586 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_588 ] ) {
type = F_4 ( V_30 -> V_5 [ V_588 ] ) ;
if ( type > V_619 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_369 ||
! ( V_7 -> V_18 . V_359 & ( 1 << type ) ) )
return - V_542 ;
if ( ( type == V_154 ||
V_7 -> V_18 . V_291 & V_629 ) &&
V_30 -> V_5 [ V_549 ] ) {
F_119 ( V_137 . V_630 , V_30 -> V_5 [ V_549 ] ,
V_590 ) ;
if ( ! F_120 ( V_137 . V_630 ) )
return - V_631 ;
}
if ( V_30 -> V_5 [ V_624 ] ) {
V_137 . V_609 = ! ! F_34 ( V_30 -> V_5 [ V_624 ] ) ;
V_35 = F_111 ( V_7 , NULL , V_137 . V_609 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_110 ( type == V_153 ?
V_30 -> V_5 [ V_625 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_626 ) &&
! ( V_7 -> V_18 . V_291 & V_627 ) )
return - V_542 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_17 = F_121 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_586 ] ) ,
V_632 , type , V_35 ? NULL : & V_51 ,
& V_137 ) ;
if ( F_59 ( ! V_17 ) ) {
F_75 ( V_53 ) ;
return - V_633 ;
} else if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_634 ] )
V_17 -> V_635 = V_30 -> V_506 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_620 ] )
break;
F_113 ( V_17 ) ;
F_114 ( V_621 !=
V_622 ) ;
V_17 -> V_623 =
F_24 ( V_30 -> V_5 [ V_620 ] ) ;
memcpy ( V_17 -> V_597 , F_23 ( V_30 -> V_5 [ V_620 ] ) ,
V_17 -> V_623 ) ;
F_115 ( V_17 ) ;
break;
case V_154 :
F_122 ( & V_17 -> V_636 ) ;
F_123 ( & V_17 -> V_637 ) ;
F_124 ( & V_17 -> V_638 ) ;
F_123 ( & V_17 -> V_639 ) ;
F_124 ( & V_17 -> V_640 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_125 ( & V_17 -> V_641 , & V_7 -> V_18 . V_642 ) ;
V_7 -> V_591 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
V_628 = F_74 ( V_603 , V_135 ) ;
if ( V_628 ) {
if ( F_103 ( V_628 , 0 , 0 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_628 ) ;
goto V_602;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_628 , 0 , V_643 ,
V_135 ) ;
}
V_602:
return F_76 ( V_53 , V_30 ) ;
}
static int F_127 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
struct V_31 * V_53 ;
int V_644 ;
if ( ! V_7 -> V_351 -> V_645 )
return - V_542 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( V_53 && F_103 ( V_53 , 0 , 0 , 0 , V_7 , V_17 , true ) < 0 ) {
F_75 ( V_53 ) ;
V_53 = NULL ;
}
if ( ! V_17 -> V_19 )
V_30 -> V_505 [ 1 ] = NULL ;
V_644 = F_128 ( V_7 , V_17 ) ;
if ( V_644 >= 0 && V_53 )
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_643 ,
V_135 ) ;
else
F_75 ( V_53 ) ;
return V_644 ;
}
static int F_129 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_3 V_646 ;
if ( ! V_30 -> V_5 [ V_647 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_427 )
return - V_542 ;
V_646 = F_78 ( V_30 -> V_5 [ V_647 ] ) ;
return F_130 ( V_7 , V_541 , V_646 ) ;
}
static void F_131 ( void * V_165 , struct V_648 * V_137 )
{
struct V_4 * V_92 ;
struct V_649 * V_650 = V_165 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_650 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_650 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_650 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_650 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_650 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_650 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_650 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_650 -> V_53 , V_123 , V_650 -> V_105 ) )
goto V_61;
F_48 ( V_650 -> V_53 , V_92 ) ;
return;
V_61:
V_650 -> error = 1 ;
}
static int F_132 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
int V_35 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 V_651 = 0 ;
const T_2 * V_652 = NULL ;
bool V_653 ;
struct V_649 V_650 = {
. error = 0 ,
} ;
void * V_283 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_651 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_651 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_549 ] )
V_652 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_653 = ! ! V_652 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_654 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_654 >= V_114 )
return - V_16 ;
if ( V_654 != V_655 &&
V_654 != V_656 )
return - V_16 ;
V_653 = V_654 == V_656 ;
}
if ( ! V_7 -> V_351 -> V_657 )
return - V_542 ;
if ( ! V_653 && V_652 && ! ( V_7 -> V_18 . V_51 & V_324 ) )
return - V_658 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_659 ) ;
if ( ! V_283 )
goto V_61;
V_650 . V_53 = V_53 ;
V_650 . V_105 = V_651 ;
if ( F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_651 ) )
goto V_61;
if ( V_652 &&
F_51 ( V_53 , V_549 , V_590 , V_652 ) )
goto V_61;
V_35 = F_133 ( V_7 , V_541 , V_651 , V_653 , V_652 , & V_650 ,
F_131 ) ;
if ( V_35 )
goto V_660;
if ( V_650 . error )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_660:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_134 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_113 ( V_541 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_351 -> V_661 ) {
V_35 = - V_542 ;
goto V_602;
}
V_35 = F_42 ( V_541 -> V_28 ) ;
if ( V_35 )
goto V_602;
V_35 = F_135 ( V_7 , V_541 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_602;
#ifdef F_136
V_541 -> V_28 -> V_662 . V_663 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_602;
}
if ( ! V_7 -> V_351 -> V_664 ) {
V_35 = - V_542 ;
goto V_602;
}
V_35 = F_42 ( V_541 -> V_28 ) ;
if ( V_35 )
goto V_602;
V_35 = F_137 ( V_7 , V_541 , V_92 . V_105 ) ;
if ( V_35 )
goto V_602;
#ifdef F_136
V_541 -> V_28 -> V_662 . V_665 = V_92 . V_105 ;
#endif
}
V_602:
F_115 ( V_541 -> V_28 ) ;
return V_35 ;
}
static int F_138 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
int V_35 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_652 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_549 ] )
V_652 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_652 )
V_92 . type = V_656 ;
else
V_92 . type = V_655 ;
}
if ( V_92 . type != V_656 &&
V_92 . type != V_655 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_373 )
return - V_542 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_656 ,
V_652 ) )
return - V_16 ;
F_113 ( V_541 -> V_28 ) ;
V_35 = F_42 ( V_541 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_139 ( V_7 , V_541 , V_92 . V_105 ,
V_92 . type == V_656 ,
V_652 , & V_92 . V_107 ) ;
F_115 ( V_541 -> V_28 ) ;
return V_35 ;
}
static int F_140 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
int V_35 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 * V_652 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_549 ] )
V_652 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_652 )
V_92 . type = V_656 ;
else
V_92 . type = V_655 ;
}
if ( V_92 . type != V_656 &&
V_92 . type != V_655 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_666 )
return - V_542 ;
F_113 ( V_541 -> V_28 ) ;
V_35 = F_42 ( V_541 -> V_28 ) ;
if ( V_92 . type == V_655 && V_652 &&
! ( V_7 -> V_18 . V_51 & V_324 ) )
V_35 = - V_658 ;
if ( ! V_35 )
V_35 = F_141 ( V_7 , V_541 , V_92 . V_105 ,
V_92 . type == V_656 ,
V_652 ) ;
#ifdef F_136
if ( ! V_35 ) {
if ( V_92 . V_105 == V_541 -> V_28 -> V_662 . V_663 )
V_541 -> V_28 -> V_662 . V_663 = - 1 ;
else if ( V_92 . V_105 == V_541 -> V_28 -> V_662 . V_665 )
V_541 -> V_28 -> V_662 . V_665 = - 1 ;
}
#endif
F_115 ( V_541 -> V_28 ) ;
return V_35 ;
}
static int F_142 ( struct V_4 * V_667 )
{
struct V_4 * V_45 ;
int V_668 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_590 )
return - V_16 ;
V_668 ++ ;
}
return V_668 ;
}
static struct V_669 * F_143 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_670 V_671 ;
struct V_4 * V_45 ;
struct V_669 * V_672 ;
int V_159 = 0 , V_668 , V_24 ;
if ( ! V_18 -> V_466 )
return F_3 ( - V_542 ) ;
if ( ! V_30 -> V_5 [ V_673 ] )
return F_3 ( - V_16 ) ;
V_671 = F_4 ( V_30 -> V_5 [ V_673 ] ) ;
if ( V_671 != V_674 &&
V_671 != V_675 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_676 ] )
return F_3 ( - V_16 ) ;
V_668 = F_142 ( V_30 -> V_5 [ V_676 ] ) ;
if ( V_668 < 0 )
return F_3 ( V_668 ) ;
if ( V_668 > V_18 -> V_466 )
return F_3 ( - V_677 ) ;
V_672 = F_38 ( sizeof( * V_672 ) + ( sizeof( struct V_678 ) * V_668 ) ,
V_135 ) ;
if ( ! V_672 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_672 -> V_679 [ V_159 ] . V_680 , F_23 ( V_45 ) , V_590 ) ;
V_159 ++ ;
}
V_672 -> V_681 = V_668 ;
V_672 -> V_671 = V_671 ;
return V_672 ;
}
static int F_144 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_669 * V_672 ;
int V_35 ;
if ( V_541 -> V_28 -> V_141 != V_142 &&
V_541 -> V_28 -> V_141 != V_144 )
return - V_542 ;
if ( ! V_541 -> V_28 -> V_543 )
return - V_16 ;
V_672 = F_143 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_672 ) )
return F_18 ( V_672 ) ;
V_35 = F_145 ( V_7 , V_541 , V_672 ) ;
F_41 ( V_672 ) ;
return V_35 ;
}
static int F_146 ( struct V_4 * V_5 [] ,
struct V_682 * V_683 )
{
bool V_684 = false ;
if ( ! F_22 ( V_5 [ V_685 ] ) ||
! F_22 ( V_5 [ V_686 ] ) ||
! F_22 ( V_5 [ V_687 ] ) ||
! F_22 ( V_5 [ V_688 ] ) )
return - V_16 ;
memset ( V_683 , 0 , sizeof( * V_683 ) ) ;
if ( V_5 [ V_689 ] ) {
V_683 -> V_690 = F_23 ( V_5 [ V_689 ] ) ;
V_683 -> V_691 = F_24 ( V_5 [ V_689 ] ) ;
if ( ! V_683 -> V_691 )
return - V_16 ;
V_684 = true ;
}
if ( V_5 [ V_685 ] ) {
V_683 -> V_692 = F_23 ( V_5 [ V_685 ] ) ;
V_683 -> V_693 = F_24 ( V_5 [ V_685 ] ) ;
V_684 = true ;
}
if ( ! V_684 )
return - V_16 ;
if ( V_5 [ V_686 ] ) {
V_683 -> V_694 = F_23 ( V_5 [ V_686 ] ) ;
V_683 -> V_695 = F_24 ( V_5 [ V_686 ] ) ;
}
if ( V_5 [ V_687 ] ) {
V_683 -> V_696 =
F_23 ( V_5 [ V_687 ] ) ;
V_683 -> V_697 =
F_24 ( V_5 [ V_687 ] ) ;
}
if ( V_5 [ V_688 ] ) {
V_683 -> V_698 =
F_23 ( V_5 [ V_688 ] ) ;
V_683 -> V_699 =
F_24 ( V_5 [ V_688 ] ) ;
}
if ( V_5 [ V_700 ] ) {
V_683 -> V_701 = F_23 ( V_5 [ V_700 ] ) ;
V_683 -> V_702 = F_24 ( V_5 [ V_700 ] ) ;
}
return 0 ;
}
static bool F_147 ( struct V_6 * V_7 ,
struct V_703 * V_137 )
{
struct V_1 * V_17 ;
bool V_498 = false ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_547 . V_55 )
continue;
V_137 -> V_522 = V_17 -> V_547 ;
V_498 = true ;
break;
}
return V_498 ;
}
static bool F_148 ( struct V_6 * V_7 ,
enum V_704 V_705 ,
enum V_280 V_52 )
{
if ( V_705 > V_706 )
return false ;
switch ( V_52 ) {
case V_707 :
if ( ! ( V_7 -> V_18 . V_291 & V_708 ) &&
V_705 == V_709 )
return false ;
return true ;
case V_450 :
case V_710 :
if ( V_705 == V_709 )
return false ;
return true ;
default:
return false ;
}
}
static int F_149 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_703 V_137 ;
int V_35 ;
if ( V_541 -> V_28 -> V_141 != V_142 &&
V_541 -> V_28 -> V_141 != V_144 )
return - V_542 ;
if ( ! V_7 -> V_351 -> V_375 )
return - V_542 ;
if ( V_17 -> V_543 )
return - V_711 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_712 ] ||
! V_30 -> V_5 [ V_713 ] ||
! V_30 -> V_5 [ V_689 ] )
return - V_16 ;
V_35 = F_146 ( V_30 -> V_5 , & V_137 . V_714 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_543 =
F_4 ( V_30 -> V_5 [ V_712 ] ) ;
V_137 . V_715 =
F_4 ( V_30 -> V_5 [ V_713 ] ) ;
V_35 = F_150 ( V_7 , V_137 . V_543 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_596 ] ) {
V_137 . V_597 = F_23 ( V_30 -> V_5 [ V_596 ] ) ;
V_137 . V_595 =
F_24 ( V_30 -> V_5 [ V_596 ] ) ;
if ( V_137 . V_595 == 0 ||
V_137 . V_595 > V_621 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_716 ] ) {
V_137 . V_717 = F_4 (
V_30 -> V_5 [ V_716 ] ) ;
if ( V_137 . V_717 != V_718 &&
V_137 . V_717 != V_719 &&
V_137 . V_717 != V_720 )
return - V_16 ;
}
V_137 . V_721 = ! ! V_30 -> V_5 [ V_722 ] ;
if ( V_30 -> V_5 [ V_723 ] ) {
V_137 . V_705 = F_4 (
V_30 -> V_5 [ V_723 ] ) ;
if ( ! F_148 ( V_7 , V_137 . V_705 ,
V_710 ) )
return - V_16 ;
} else
V_137 . V_705 = V_724 ;
V_35 = F_151 ( V_7 , V_30 , & V_137 . V_725 ,
V_726 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_727 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_728 ) )
return - V_542 ;
V_137 . V_729 = F_78 (
V_30 -> V_5 [ V_727 ] ) ;
}
if ( V_30 -> V_5 [ V_730 ] ) {
if ( V_541 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_731 =
F_34 ( V_30 -> V_5 [ V_730 ] ) ;
if ( V_137 . V_731 > 127 )
return - V_16 ;
if ( V_137 . V_731 != 0 &&
! ( V_7 -> V_18 . V_291 & V_732 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_733 ] ) {
T_2 V_24 ;
if ( V_541 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_733 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_734 = V_24 ;
if ( V_137 . V_734 != 0 &&
! ( V_7 -> V_18 . V_291 & V_735 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_524 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_522 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_547 . V_55 ) {
V_137 . V_522 = V_17 -> V_547 ;
} else if ( ! F_147 ( V_7 , & V_137 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_522 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_736 ] ) {
V_137 . V_737 =
F_34 ( V_30 -> V_5 [ V_736 ] ) ;
switch ( V_137 . V_737 ) {
case V_738 :
break;
case V_739 :
if ( ! ( V_7 -> V_18 . V_291 &
V_740 ) )
return - V_16 ;
break;
case V_741 :
if ( ! ( V_7 -> V_18 . V_291 &
V_742 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_137 . V_737 = V_738 ;
}
V_137 . V_743 = F_152 ( V_30 -> V_5 [ V_744 ] ) ;
if ( V_137 . V_743 && ! V_7 -> V_18 . V_363 [ V_745 ] )
return - V_542 ;
if ( V_30 -> V_5 [ V_673 ] ) {
V_137 . V_672 = F_143 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_672 ) )
return F_18 ( V_137 . V_672 ) ;
}
F_113 ( V_17 ) ;
V_35 = F_153 ( V_7 , V_541 , & V_137 ) ;
if ( ! V_35 ) {
V_17 -> V_547 = V_137 . V_522 ;
V_17 -> V_543 = V_137 . V_543 ;
V_17 -> V_522 = V_137 . V_522 ;
V_17 -> V_595 = V_137 . V_595 ;
memcpy ( V_17 -> V_597 , V_137 . V_597 , V_17 -> V_595 ) ;
}
F_115 ( V_17 ) ;
F_41 ( V_137 . V_672 ) ;
return V_35 ;
}
static int F_154 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_682 V_137 ;
int V_35 ;
if ( V_541 -> V_28 -> V_141 != V_142 &&
V_541 -> V_28 -> V_141 != V_144 )
return - V_542 ;
if ( ! V_7 -> V_351 -> V_746 )
return - V_542 ;
if ( ! V_17 -> V_543 )
return - V_16 ;
V_35 = F_146 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
V_35 = F_155 ( V_7 , V_541 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_156 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
return F_157 ( V_7 , V_541 , false ) ;
}
static int F_158 ( struct V_29 * V_30 ,
enum V_272 V_141 ,
struct V_747 * V_137 )
{
struct V_4 * V_51 [ V_748 + 1 ] ;
struct V_4 * V_604 ;
int V_607 ;
V_604 = V_30 -> V_5 [ V_749 ] ;
if ( V_604 ) {
struct V_750 * V_751 ;
V_751 = F_23 ( V_604 ) ;
V_137 -> V_752 = V_751 -> V_753 ;
V_137 -> V_754 = V_751 -> V_755 ;
V_137 -> V_754 &= V_137 -> V_752 ;
if ( ( V_137 -> V_752 |
V_137 -> V_754 ) & F_159 ( V_756 ) )
return - V_16 ;
return 0 ;
}
V_604 = V_30 -> V_5 [ V_757 ] ;
if ( ! V_604 )
return 0 ;
if ( F_33 ( V_51 , V_748 ,
V_604 , V_758 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_752 = F_159 ( V_759 ) |
F_159 ( V_760 ) |
F_159 ( V_761 ) |
F_159 ( V_762 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_752 = F_159 ( V_759 ) |
F_159 ( V_763 ) ;
break;
case V_145 :
V_137 -> V_752 = F_159 ( V_764 ) |
F_159 ( V_762 ) |
F_159 ( V_759 ) ;
default:
return - V_16 ;
}
for ( V_607 = 1 ; V_607 <= V_748 ; V_607 ++ ) {
if ( V_51 [ V_607 ] ) {
V_137 -> V_754 |= ( 1 << V_607 ) ;
if ( V_607 > V_765 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_160 ( struct V_31 * V_53 , struct V_766 * V_30 ,
int V_45 )
{
struct V_4 * V_244 ;
V_22 V_264 ;
T_3 V_767 ;
enum V_768 V_769 ;
V_244 = F_47 ( V_53 , V_45 ) ;
if ( ! V_244 )
return false ;
V_264 = F_161 ( V_30 ) ;
V_767 = V_264 < ( 1UL << 16 ) ? V_264 : 0 ;
if ( V_264 > 0 &&
F_28 ( V_53 , V_770 , V_264 ) )
return false ;
if ( V_767 > 0 &&
F_55 ( V_53 , V_771 , V_767 ) )
return false ;
switch ( V_30 -> V_772 ) {
case V_773 :
V_769 = V_774 ;
break;
case V_775 :
V_769 = V_776 ;
break;
default:
F_59 ( 1 ) ;
case V_777 :
V_769 = 0 ;
break;
case V_778 :
V_769 = V_779 ;
break;
case V_780 :
V_769 = V_781 ;
break;
case V_782 :
V_769 = V_783 ;
break;
}
if ( V_769 && F_29 ( V_53 , V_769 ) )
return false ;
if ( V_30 -> V_51 & V_784 ) {
if ( F_56 ( V_53 , V_785 , V_30 -> V_248 ) )
return false ;
if ( V_30 -> V_51 & V_786 &&
F_29 ( V_53 , V_787 ) )
return false ;
} else if ( V_30 -> V_51 & V_788 ) {
if ( F_56 ( V_53 , V_789 , V_30 -> V_248 ) )
return false ;
if ( F_56 ( V_53 , V_790 , V_30 -> V_791 ) )
return false ;
if ( V_30 -> V_51 & V_786 &&
F_29 ( V_53 , V_787 ) )
return false ;
}
F_48 ( V_53 , V_244 ) ;
return true ;
}
static bool F_162 ( struct V_31 * V_53 , T_2 V_753 , T_6 * signal ,
int V_792 )
{
void * V_45 ;
int V_159 = 0 ;
if ( ! V_753 )
return true ;
V_45 = F_47 ( V_53 , V_792 ) ;
if ( ! V_45 )
return false ;
for ( V_159 = 0 ; V_159 < V_793 ; V_159 ++ ) {
if ( ! ( V_753 & F_159 ( V_159 ) ) )
continue;
if ( F_56 ( V_53 , V_159 , signal [ V_159 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_163 ( struct V_31 * V_53 , V_22 V_52 , V_22 V_49 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_541 ,
const T_2 * V_652 , struct V_794 * V_795 )
{
void * V_283 ;
struct V_4 * V_796 , * V_797 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_652 ) ||
F_28 ( V_53 , V_293 , V_795 -> V_798 ) )
goto V_61;
V_796 = F_47 ( V_53 , V_799 ) ;
if ( ! V_796 )
goto V_61;
#define F_164 ( V_45 , T_7 , type ) do { \
BUILD_BUG_ON(sizeof(type) == sizeof(u64)); \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
#define F_165 ( V_45 , T_7 ) do { \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb, NL80211_STA_INFO_PAD)) \
goto nla_put_failure; \
} while (0)
F_164 ( V_800 , V_801 , V_22 ) ;
F_164 ( V_802 , V_803 , V_22 ) ;
if ( V_795 -> V_804 & ( F_159 ( V_805 ) |
F_159 ( V_806 ) ) &&
F_28 ( V_53 , V_805 ,
( V_22 ) V_795 -> V_807 ) )
goto V_61;
if ( V_795 -> V_804 & ( F_159 ( V_808 ) |
F_159 ( V_809 ) ) &&
F_28 ( V_53 , V_808 ,
( V_22 ) V_795 -> V_810 ) )
goto V_61;
F_165 ( V_811 , V_807 ) ;
F_165 ( V_812 , V_810 ) ;
F_164 ( V_813 , V_814 , T_3 ) ;
F_164 ( V_815 , V_816 , T_3 ) ;
F_164 ( V_817 , V_818 , T_2 ) ;
F_165 ( V_819 , V_820 ) ;
switch ( V_7 -> V_18 . V_821 ) {
case V_822 :
F_164 ( SIGNAL , signal , T_2 ) ;
F_164 ( V_823 , V_824 , T_2 ) ;
break;
default:
break;
}
if ( V_795 -> V_804 & F_159 ( V_825 ) ) {
if ( ! F_162 ( V_53 , V_795 -> V_826 ,
V_795 -> V_827 ,
V_825 ) )
goto V_61;
}
if ( V_795 -> V_804 & F_159 ( V_828 ) ) {
if ( ! F_162 ( V_53 , V_795 -> V_826 ,
V_795 -> V_829 ,
V_828 ) )
goto V_61;
}
if ( V_795 -> V_804 & F_159 ( V_830 ) ) {
if ( ! F_160 ( V_53 , & V_795 -> V_831 ,
V_830 ) )
goto V_61;
}
if ( V_795 -> V_804 & F_159 ( V_832 ) ) {
if ( ! F_160 ( V_53 , & V_795 -> V_833 ,
V_832 ) )
goto V_61;
}
F_164 ( V_834 , V_835 , V_22 ) ;
F_164 ( V_836 , V_837 , V_22 ) ;
F_164 ( V_838 , V_839 , V_22 ) ;
F_164 ( V_840 , V_841 , V_22 ) ;
F_164 ( V_842 , V_843 , V_22 ) ;
F_164 ( V_844 , V_845 , V_22 ) ;
F_164 ( V_846 , V_847 , V_22 ) ;
F_164 ( V_848 , V_849 , V_22 ) ;
F_164 ( V_850 , V_851 , V_22 ) ;
if ( V_795 -> V_804 & F_159 ( V_852 ) ) {
V_797 = F_47 ( V_53 , V_852 ) ;
if ( ! V_797 )
goto V_61;
if ( ( ( V_795 -> V_797 . V_51 & V_853 ) &&
F_29 ( V_53 , V_854 ) ) ||
( ( V_795 -> V_797 . V_51 & V_855 ) &&
F_29 ( V_53 , V_856 ) ) ||
( ( V_795 -> V_797 . V_51 & V_857 ) &&
F_29 ( V_53 , V_858 ) ) ||
F_56 ( V_53 , V_859 ,
V_795 -> V_797 . V_715 ) ||
F_55 ( V_53 , V_860 ,
V_795 -> V_797 . V_543 ) )
goto V_61;
F_48 ( V_53 , V_797 ) ;
}
if ( ( V_795 -> V_804 & F_159 ( V_861 ) ) &&
F_51 ( V_53 , V_861 ,
sizeof( struct V_750 ) ,
& V_795 -> V_751 ) )
goto V_61;
F_165 ( V_862 , V_863 ) ;
F_165 ( V_864 , V_865 ) ;
F_165 ( V_866 , V_867 ) ;
F_164 ( V_868 , V_869 , T_2 ) ;
#undef F_164
#undef F_165
if ( V_795 -> V_804 & F_159 ( V_870 ) ) {
struct V_4 * V_871 ;
int V_872 ;
V_871 = F_47 ( V_53 , V_870 ) ;
if ( ! V_871 )
goto V_61;
for ( V_872 = 0 ; V_872 < V_873 + 1 ; V_872 ++ ) {
struct V_874 * V_875 ;
struct V_4 * V_876 ;
V_875 = & V_795 -> V_877 [ V_872 ] ;
if ( ! V_875 -> V_804 )
continue;
V_876 = F_47 ( V_53 , V_872 + 1 ) ;
if ( ! V_876 )
goto V_61;
#define F_166 ( V_45 , T_7 ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb, NL80211_TID_STATS_PAD)) \
goto nla_put_failure; \
} while (0)
F_166 ( V_878 , V_879 ) ;
F_166 ( V_880 , V_881 ) ;
F_166 ( V_882 , V_883 ) ;
F_166 ( V_884 , V_885 ) ;
#undef F_166
F_48 ( V_53 , V_876 ) ;
}
F_48 ( V_53 , V_871 ) ;
}
F_48 ( V_53 , V_796 ) ;
if ( V_795 -> V_886 &&
F_51 ( V_53 , V_686 , V_795 -> V_886 ,
V_795 -> V_887 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int F_167 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_794 V_795 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_652 [ V_590 ] ;
int V_888 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_889;
}
if ( ! V_7 -> V_351 -> V_890 ) {
V_35 = - V_542 ;
goto V_889;
}
while ( 1 ) {
memset ( & V_795 , 0 , sizeof( V_795 ) ) ;
V_35 = F_168 ( V_7 , V_17 -> V_19 , V_888 ,
V_652 , & V_795 ) ;
if ( V_35 == - V_658 )
break;
if ( V_35 )
goto V_889;
if ( F_163 ( V_32 , V_891 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_7 , V_17 -> V_19 , V_652 ,
& V_795 ) < 0 )
goto V_602;
V_888 ++ ;
}
V_602:
V_34 -> args [ 2 ] = V_888 ;
V_35 = V_32 -> V_47 ;
V_889:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_169 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_794 V_795 ;
struct V_31 * V_53 ;
T_2 * V_652 = NULL ;
int V_35 ;
memset ( & V_795 , 0 , sizeof( V_795 ) ) ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_652 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( ! V_7 -> V_351 -> V_892 )
return - V_542 ;
V_35 = F_170 ( V_7 , V_541 , V_652 , & V_795 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_163 ( V_53 , V_891 ,
V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_7 , V_541 , V_652 , & V_795 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_171 ( struct V_18 * V_18 ,
struct V_747 * V_137 ,
enum V_893 V_894 )
{
if ( V_137 -> V_895 != - 1 &&
V_894 != V_896 )
return - V_16 ;
if ( V_137 -> V_897 != - 1 &&
V_894 != V_896 )
return - V_16 ;
if ( V_137 -> V_898 &&
! ( V_137 -> V_754 & F_159 ( V_763 ) ) &&
V_894 != V_896 )
return - V_16 ;
F_114 ( V_748 != 7 ) ;
switch ( V_894 ) {
case V_899 :
case V_900 :
if ( V_137 -> V_752 &
~ ( F_159 ( V_764 ) |
F_159 ( V_762 ) |
F_159 ( V_759 ) ) )
return - V_16 ;
break;
case V_901 :
case V_902 :
if ( ! ( V_137 -> V_754 & F_159 ( V_763 ) ) )
return - V_16 ;
V_137 -> V_752 &= ~ F_159 ( V_763 ) ;
break;
default:
if ( V_137 -> V_903 != V_904 )
return - V_16 ;
if ( V_137 -> V_847 )
return - V_16 ;
if ( V_137 -> V_905 & V_906 )
return - V_16 ;
}
if ( V_894 != V_901 &&
V_894 != V_902 ) {
if ( V_137 -> V_754 & F_159 ( V_763 ) )
return - V_16 ;
V_137 -> V_752 &= ~ F_159 ( V_763 ) ;
}
if ( V_894 != V_901 &&
V_894 != V_896 ) {
if ( V_137 -> V_905 & V_907 )
return - V_16 ;
if ( V_137 -> V_905 & V_908 )
return - V_16 ;
if ( V_137 -> V_909 )
return - V_16 ;
if ( V_137 -> V_910 || V_137 -> V_911 || V_137 -> V_912 )
return - V_16 ;
}
if ( V_894 != V_913 &&
V_894 != V_896 ) {
if ( V_137 -> V_914 )
return - V_16 ;
}
switch ( V_894 ) {
case V_915 :
if ( ! ( V_137 -> V_752 & F_159 ( V_759 ) ) )
return - V_542 ;
break;
case V_913 :
case V_896 :
if ( V_137 -> V_752 &
~ ( F_159 ( V_759 ) |
F_159 ( V_764 ) |
F_159 ( V_916 ) |
F_159 ( V_760 ) |
F_159 ( V_761 ) |
F_159 ( V_762 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_291 & V_917 ) &&
V_137 -> V_752 &
( F_159 ( V_764 ) |
F_159 ( V_916 ) ) )
return - V_16 ;
break;
case V_918 :
case V_919 :
if ( V_137 -> V_752 & ~ F_159 ( V_759 ) )
return - V_16 ;
break;
case V_901 :
if ( V_137 -> V_752 & ~ ( F_159 ( V_759 ) |
F_159 ( V_761 ) ) )
return - V_16 ;
if ( V_137 -> V_754 & F_159 ( V_759 ) &&
! V_137 -> V_909 )
return - V_16 ;
break;
case V_902 :
return - V_16 ;
case V_899 :
if ( V_137 -> V_905 & V_906 )
return - V_16 ;
break;
case V_900 :
if ( V_137 -> V_903 != V_904 &&
V_137 -> V_903 != V_920 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_172 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_921 = V_30 -> V_5 [ V_922 ] ;
struct V_25 * V_923 ;
int V_498 ;
if ( ! V_921 )
return NULL ;
V_923 = F_173 ( F_94 ( V_30 ) , F_4 ( V_921 ) ) ;
if ( ! V_923 )
return F_3 ( - V_23 ) ;
if ( ! V_923 -> V_28 || V_923 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_498 = - V_16 ;
goto error;
}
if ( V_923 -> V_28 -> V_141 != V_143 &&
V_923 -> V_28 -> V_141 != V_142 &&
V_923 -> V_28 -> V_141 != V_144 ) {
V_498 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_923 ) ) {
V_498 = - V_556 ;
goto error;
}
return V_923 ;
error:
F_174 ( V_923 ) ;
return F_3 ( V_498 ) ;
}
static int F_175 ( struct V_29 * V_30 ,
struct V_747 * V_137 )
{
struct V_4 * V_95 [ V_924 + 1 ] ;
struct V_4 * V_604 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_925 ] )
return 0 ;
V_604 = V_30 -> V_5 [ V_925 ] ;
V_35 = F_33 ( V_95 , V_924 , V_604 ,
V_926 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_927 ] )
V_137 -> V_928 = F_34 (
V_95 [ V_927 ] ) ;
if ( V_137 -> V_928 & ~ V_929 )
return - V_16 ;
if ( V_95 [ V_930 ] )
V_137 -> V_931 = F_34 ( V_95 [ V_930 ] ) ;
if ( V_137 -> V_931 & ~ V_932 )
return - V_16 ;
V_137 -> V_905 |= V_907 ;
return 0 ;
}
static int F_176 ( struct V_29 * V_30 ,
struct V_747 * V_137 )
{
if ( V_30 -> V_5 [ V_933 ] ) {
V_137 -> V_934 =
F_23 ( V_30 -> V_5 [ V_933 ] ) ;
V_137 -> V_935 =
F_24 ( V_30 -> V_5 [ V_933 ] ) ;
if ( V_137 -> V_935 < 2 )
return - V_16 ;
if ( V_137 -> V_935 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_936 ] ) {
V_137 -> V_937 =
F_23 ( V_30 -> V_5 [ V_936 ] ) ;
V_137 -> V_938 =
F_24 ( V_30 -> V_5 [ V_936 ] ) ;
if ( V_137 -> V_938 < 2 ||
V_137 -> V_938 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_177 ( struct V_29 * V_30 ,
struct V_747 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_939 ] )
V_137 -> V_898 = F_78 ( V_30 -> V_5 [ V_939 ] ) ;
if ( V_30 -> V_5 [ V_940 ] )
V_137 -> V_911 =
F_23 ( V_30 -> V_5 [ V_940 ] ) ;
if ( V_30 -> V_5 [ V_941 ] )
V_137 -> V_912 =
F_23 ( V_30 -> V_5 [ V_941 ] ) ;
V_35 = F_176 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_175 ( V_30 , V_137 ) ;
}
static int F_178 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_747 V_137 ;
T_2 * V_652 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_942 )
return - V_542 ;
if ( V_30 -> V_5 [ V_943 ] )
V_137 . V_898 = F_78 ( V_30 -> V_5 [ V_943 ] ) ;
if ( V_30 -> V_5 [ V_944 ] )
V_137 . V_895 =
F_78 ( V_30 -> V_5 [ V_944 ] ) ;
else
V_137 . V_895 = - 1 ;
if ( V_30 -> V_5 [ V_945 ] ) {
T_2 V_24 ;
V_24 = F_34 ( V_30 -> V_5 [ V_945 ] ) ;
if ( V_24 >= V_946 )
return - V_16 ;
V_137 . V_897 = V_24 ;
} else {
V_137 . V_897 = - 1 ;
}
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_652 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( V_30 -> V_5 [ V_947 ] ) {
V_137 . V_909 =
F_23 ( V_30 -> V_5 [ V_947 ] ) ;
V_137 . V_948 =
F_24 ( V_30 -> V_5 [ V_947 ] ) ;
}
if ( V_30 -> V_5 [ V_949 ] ) {
V_137 . V_950 =
F_78 ( V_30 -> V_5 [ V_949 ] ) ;
V_137 . V_905 |= V_908 ;
}
if ( V_30 -> V_5 [ V_951 ] ) {
V_137 . V_910 =
F_23 ( V_30 -> V_5 [ V_951 ] ) ;
V_137 . V_952 =
F_24 ( V_30 -> V_5 [ V_951 ] ) ;
}
if ( F_158 ( V_30 , V_541 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_953 ] ) {
V_137 . V_903 =
F_34 ( V_30 -> V_5 [ V_953 ] ) ;
if ( V_137 . V_903 >= V_954 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_955 ] ) {
V_137 . V_818 =
F_34 ( V_30 -> V_5 [ V_955 ] ) ;
if ( V_137 . V_818 >= V_956 )
return - V_16 ;
V_137 . V_905 |= V_906 ;
}
if ( V_30 -> V_5 [ V_957 ] ) {
enum V_958 V_959 = F_4 (
V_30 -> V_5 [ V_957 ] ) ;
if ( V_959 <= V_960 ||
V_959 > V_961 )
return - V_16 ;
V_137 . V_847 = V_959 ;
}
V_35 = F_177 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_914 = F_172 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_914 ) )
return F_18 ( V_137 . V_914 ) ;
switch ( V_541 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_542 ;
goto V_962;
}
V_35 = F_179 ( V_7 , V_541 , V_652 , & V_137 ) ;
V_962:
if ( V_137 . V_914 )
F_174 ( V_137 . V_914 ) ;
return V_35 ;
}
static int F_180 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
int V_35 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_747 V_137 ;
T_2 * V_652 = NULL ;
V_22 V_963 = F_159 ( V_764 ) |
F_159 ( V_916 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_377 )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_944 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_947 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_943 ] &&
! V_30 -> V_5 [ V_939 ] )
return - V_16 ;
V_652 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_137 . V_909 =
F_23 ( V_30 -> V_5 [ V_947 ] ) ;
V_137 . V_948 =
F_24 ( V_30 -> V_5 [ V_947 ] ) ;
V_137 . V_895 =
F_78 ( V_30 -> V_5 [ V_944 ] ) ;
if ( V_30 -> V_5 [ V_945 ] ) {
T_2 V_24 ;
V_24 = F_34 ( V_30 -> V_5 [ V_945 ] ) ;
if ( V_24 >= V_946 )
return - V_16 ;
V_137 . V_897 = V_24 ;
} else {
V_137 . V_897 =
V_541 -> V_28 -> V_141 == V_144 ;
}
if ( V_30 -> V_5 [ V_939 ] )
V_137 . V_898 = F_78 ( V_30 -> V_5 [ V_939 ] ) ;
else
V_137 . V_898 = F_78 ( V_30 -> V_5 [ V_943 ] ) ;
if ( ! V_137 . V_898 || V_137 . V_898 > V_964 )
return - V_16 ;
if ( V_30 -> V_5 [ V_949 ] ) {
V_137 . V_950 =
F_78 ( V_30 -> V_5 [ V_949 ] ) ;
V_137 . V_905 |= V_908 ;
}
if ( V_30 -> V_5 [ V_951 ] ) {
V_137 . V_910 =
F_23 ( V_30 -> V_5 [ V_951 ] ) ;
V_137 . V_952 =
F_24 ( V_30 -> V_5 [ V_951 ] ) ;
}
if ( V_30 -> V_5 [ V_940 ] )
V_137 . V_911 =
F_23 ( V_30 -> V_5 [ V_940 ] ) ;
if ( V_30 -> V_5 [ V_941 ] )
V_137 . V_912 =
F_23 ( V_30 -> V_5 [ V_941 ] ) ;
if ( V_30 -> V_5 [ V_965 ] ) {
V_137 . V_966 = true ;
V_137 . V_967 =
F_34 ( V_30 -> V_5 [ V_965 ] ) ;
}
if ( V_30 -> V_5 [ V_953 ] ) {
V_137 . V_903 =
F_34 ( V_30 -> V_5 [ V_953 ] ) ;
if ( V_137 . V_903 >= V_954 )
return - V_16 ;
}
V_35 = F_176 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_175 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_158 ( V_30 , V_541 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( ! ( V_137 . V_754 & F_159 ( V_761 ) ) ) {
V_137 . V_911 = NULL ;
V_137 . V_912 = NULL ;
}
F_114 ( V_748 != 7 ) ;
switch ( V_541 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) ||
! ( V_137 . V_754 & F_159 ( V_761 ) ) )
V_137 . V_905 &= ~ V_907 ;
if ( ( V_137 . V_754 & F_159 ( V_763 ) ) ||
V_30 -> V_5 [ V_939 ] )
return - V_16 ;
V_137 . V_752 &= ~ F_159 ( V_763 ) ;
if ( ! ( V_7 -> V_18 . V_291 &
V_917 ) &&
V_137 . V_752 & V_963 )
return - V_16 ;
if ( ! ( V_137 . V_752 & V_963 ) ) {
V_137 . V_752 |= V_963 ;
V_137 . V_754 |= V_963 ;
}
V_137 . V_914 = F_172 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_914 ) )
return F_18 ( V_137 . V_914 ) ;
break;
case V_145 :
V_137 . V_905 &= ~ V_907 ;
if ( V_137 . V_752 & F_159 ( V_916 ) )
return - V_16 ;
if ( ( V_137 . V_754 & F_159 ( V_763 ) ) ||
V_30 -> V_5 [ V_939 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_905 &= ~ V_907 ;
if ( V_137 . V_752 &
( F_159 ( V_916 ) |
F_159 ( V_764 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_754 & F_159 ( V_763 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) )
return - V_542 ;
if ( ! ( V_7 -> V_18 . V_51 & V_334 ) )
return - V_542 ;
V_137 . V_752 &= ~ F_159 ( V_759 ) ;
break;
default:
return - V_542 ;
}
V_35 = F_181 ( V_7 , V_541 , V_652 , & V_137 ) ;
if ( V_137 . V_914 )
F_174 ( V_137 . V_914 ) ;
return V_35 ;
}
static int F_182 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_968 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_30 -> V_5 [ V_549 ] )
V_137 . V_969 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( V_541 -> V_28 -> V_141 != V_142 &&
V_541 -> V_28 -> V_141 != V_143 &&
V_541 -> V_28 -> V_141 != V_145 &&
V_541 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_970 )
return - V_542 ;
if ( V_30 -> V_5 [ V_971 ] ) {
V_137 . V_972 =
F_34 ( V_30 -> V_5 [ V_971 ] ) ;
if ( V_137 . V_972 != V_973 >> 4 &&
V_137 . V_972 != V_974 >> 4 )
return - V_16 ;
} else {
V_137 . V_972 = V_974 >> 4 ;
}
if ( V_30 -> V_5 [ V_975 ] ) {
V_137 . V_976 =
F_78 ( V_30 -> V_5 [ V_975 ] ) ;
if ( V_137 . V_976 == 0 )
return - V_16 ;
} else {
V_137 . V_976 = V_977 ;
}
return F_183 ( V_7 , V_541 , & V_137 ) ;
}
static int F_184 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_541 ,
T_2 * V_978 , T_2 * V_979 ,
struct V_980 * V_981 )
{
void * V_283 ;
struct V_4 * V_982 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_983 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_978 ) ||
F_51 ( V_53 , V_984 , V_590 , V_979 ) ||
F_28 ( V_53 , V_293 , V_981 -> V_798 ) )
goto V_61;
V_982 = F_47 ( V_53 , V_985 ) ;
if ( ! V_982 )
goto V_61;
if ( ( V_981 -> V_804 & V_986 ) &&
F_28 ( V_53 , V_987 ,
V_981 -> V_988 ) )
goto V_61;
if ( ( ( V_981 -> V_804 & V_989 ) &&
F_28 ( V_53 , V_990 , V_981 -> V_991 ) ) ||
( ( V_981 -> V_804 & V_992 ) &&
F_28 ( V_53 , V_993 ,
V_981 -> V_994 ) ) ||
( ( V_981 -> V_804 & V_995 ) &&
F_28 ( V_53 , V_996 ,
V_981 -> V_997 ) ) ||
( ( V_981 -> V_804 & V_998 ) &&
F_56 ( V_53 , V_999 ,
V_981 -> V_51 ) ) ||
( ( V_981 -> V_804 & V_1000 ) &&
F_28 ( V_53 , V_1001 ,
V_981 -> V_1002 ) ) ||
( ( V_981 -> V_804 & V_1003 ) &&
F_56 ( V_53 , V_1004 ,
V_981 -> V_1005 ) ) )
goto V_61;
F_48 ( V_53 , V_982 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int F_185 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_980 V_981 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_978 [ V_590 ] ;
T_2 V_979 [ V_590 ] ;
int V_1006 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_1007 ) {
V_35 = - V_542 ;
goto V_889;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_542 ;
goto V_889;
}
while ( 1 ) {
V_35 = F_186 ( V_7 , V_17 -> V_19 , V_1006 , V_978 ,
V_979 , & V_981 ) ;
if ( V_35 == - V_658 )
break;
if ( V_35 )
goto V_889;
if ( F_184 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_17 -> V_19 , V_978 , V_979 ,
& V_981 ) < 0 )
goto V_602;
V_1006 ++ ;
}
V_602:
V_34 -> args [ 2 ] = V_1006 ;
V_35 = V_32 -> V_47 ;
V_889:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_187 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
int V_35 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_980 V_981 ;
struct V_31 * V_53 ;
T_2 * V_978 = NULL ;
T_2 V_979 [ V_590 ] ;
memset ( & V_981 , 0 , sizeof( V_981 ) ) ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_978 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( ! V_7 -> V_351 -> V_1008 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_145 )
return - V_542 ;
V_35 = F_188 ( V_7 , V_541 , V_978 , V_979 , & V_981 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_184 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_541 , V_978 , V_979 , & V_981 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_189 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 * V_978 = NULL ;
T_2 * V_979 = NULL ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_984 ] )
return - V_16 ;
V_978 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_979 = F_23 ( V_30 -> V_5 [ V_984 ] ) ;
if ( ! V_7 -> V_351 -> V_1009 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_145 )
return - V_542 ;
return F_190 ( V_7 , V_541 , V_978 , V_979 ) ;
}
static int F_191 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 * V_978 = NULL ;
T_2 * V_979 = NULL ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_984 ] )
return - V_16 ;
V_978 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_979 = F_23 ( V_30 -> V_5 [ V_984 ] ) ;
if ( ! V_7 -> V_351 -> V_379 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_145 )
return - V_542 ;
return F_192 ( V_7 , V_541 , V_978 , V_979 ) ;
}
static int F_193 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 * V_978 = NULL ;
if ( V_30 -> V_5 [ V_549 ] )
V_978 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( ! V_7 -> V_351 -> V_1010 )
return - V_542 ;
return F_194 ( V_7 , V_541 , V_978 ) ;
}
static int F_195 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
int V_35 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_980 V_981 ;
struct V_31 * V_53 ;
T_2 * V_978 = NULL ;
T_2 V_1011 [ V_590 ] ;
memset ( & V_981 , 0 , sizeof( V_981 ) ) ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_978 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( ! V_7 -> V_351 -> V_1012 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_145 )
return - V_542 ;
V_35 = F_196 ( V_7 , V_541 , V_978 , V_1011 , & V_981 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_184 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_541 , V_978 , V_1011 , & V_981 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_197 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_980 V_981 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_978 [ V_590 ] ;
T_2 V_1011 [ V_590 ] ;
int V_1006 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_1013 ) {
V_35 = - V_542 ;
goto V_889;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_542 ;
goto V_889;
}
while ( 1 ) {
V_35 = F_198 ( V_7 , V_17 -> V_19 , V_1006 , V_978 ,
V_1011 , & V_981 ) ;
if ( V_35 == - V_658 )
break;
if ( V_35 )
goto V_889;
if ( F_184 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_17 -> V_19 , V_978 , V_1011 ,
& V_981 ) < 0 )
goto V_602;
V_1006 ++ ;
}
V_602:
V_34 -> args [ 2 ] = V_1006 ;
V_35 = V_32 -> V_47 ;
V_889:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_199 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_1014 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_1015 = - 1 ;
V_137 . V_1016 = - 1 ;
V_137 . V_1017 = - 1 ;
V_137 . V_1018 = - 1 ;
V_137 . V_1019 = - 1 ;
V_137 . V_731 = - 1 ;
V_137 . V_734 = - 1 ;
if ( V_30 -> V_5 [ V_1020 ] )
V_137 . V_1015 =
F_34 ( V_30 -> V_5 [ V_1020 ] ) ;
if ( V_30 -> V_5 [ V_1021 ] )
V_137 . V_1016 =
F_34 ( V_30 -> V_5 [ V_1021 ] ) ;
if ( V_30 -> V_5 [ V_1022 ] )
V_137 . V_1017 =
F_34 ( V_30 -> V_5 [ V_1022 ] ) ;
if ( V_30 -> V_5 [ V_1023 ] ) {
V_137 . V_1024 =
F_23 ( V_30 -> V_5 [ V_1023 ] ) ;
V_137 . V_1025 =
F_24 ( V_30 -> V_5 [ V_1023 ] ) ;
}
if ( V_30 -> V_5 [ V_1026 ] )
V_137 . V_1018 = ! ! F_34 ( V_30 -> V_5 [ V_1026 ] ) ;
if ( V_30 -> V_5 [ V_1027 ] )
V_137 . V_1019 =
F_78 ( V_30 -> V_5 [ V_1027 ] ) ;
if ( V_30 -> V_5 [ V_730 ] ) {
if ( V_541 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_731 =
F_200 ( V_30 -> V_5 [ V_730 ] ) ;
if ( V_137 . V_731 < 0 )
return - V_16 ;
if ( V_137 . V_731 != 0 &&
! ( V_7 -> V_18 . V_291 & V_732 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_733 ] ) {
T_2 V_24 ;
if ( V_541 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_733 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_734 = V_24 ;
if ( V_137 . V_734 &&
! ( V_7 -> V_18 . V_291 & V_735 ) )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_383 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_142 &&
V_541 -> V_28 -> V_141 != V_144 )
return - V_542 ;
F_113 ( V_17 ) ;
V_35 = F_201 ( V_7 , V_541 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_202 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
bool V_1028 ;
enum V_1029 V_1030 ;
V_22 V_635 ;
if ( F_203 ( ! F_204 ( V_1031 ) ) )
return - V_1032 ;
if ( V_30 -> V_5 [ V_1033 ] )
V_1030 =
F_4 ( V_30 -> V_5 [ V_1033 ] ) ;
else
V_1030 = V_1034 ;
switch ( V_1030 ) {
case V_1034 :
case V_1035 :
if ( ! V_30 -> V_5 [ V_1036 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1036 ] ) ;
return F_205 ( V_138 , V_1030 ) ;
case V_1037 :
if ( V_30 -> V_5 [ V_634 ] ) {
V_635 = V_30 -> V_506 ;
V_1028 = ! ! V_30 -> V_5 [ V_1038 ] ;
} else {
V_635 = 0 ;
V_1028 = true ;
}
return F_206 ( V_1028 , V_635 ) ;
default:
return - V_16 ;
}
}
static int F_207 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_1039 V_1040 ;
int V_35 = 0 ;
void * V_283 ;
struct V_4 * V_982 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_542 ;
if ( ! V_7 -> V_351 -> V_1041 )
return - V_542 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1042 )
memcpy ( & V_1040 , & V_1043 , sizeof( V_1040 ) ) ;
else
V_35 = F_208 ( V_7 , V_541 , & V_1040 ) ;
F_115 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1044 ) ;
if ( ! V_283 )
goto V_602;
V_982 = F_47 ( V_53 , V_1045 ) ;
if ( ! V_982 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_55 ( V_53 , V_1046 ,
V_1040 . V_1047 ) ||
F_55 ( V_53 , V_1048 ,
V_1040 . V_1049 ) ||
F_55 ( V_53 , V_1050 ,
V_1040 . V_1051 ) ||
F_55 ( V_53 , V_1052 ,
V_1040 . V_1053 ) ||
F_56 ( V_53 , V_1054 ,
V_1040 . V_1055 ) ||
F_56 ( V_53 , V_1056 ,
V_1040 . V_1057 ) ||
F_56 ( V_53 , V_1058 ,
V_1040 . V_1059 ) ||
F_56 ( V_53 , V_1060 ,
V_1040 . V_1061 ) ||
F_28 ( V_53 , V_1062 ,
V_1040 . V_1063 ) ||
F_56 ( V_53 , V_1064 ,
V_1040 . V_1065 ) ||
F_28 ( V_53 , V_1066 ,
V_1040 . V_1067 ) ||
F_55 ( V_53 , V_1068 ,
V_1040 . V_1069 ) ||
F_28 ( V_53 , V_1070 ,
V_1040 . V_1071 ) ||
F_55 ( V_53 , V_1072 ,
V_1040 . V_1073 ) ||
F_55 ( V_53 , V_1074 ,
V_1040 . V_1075 ) ||
F_55 ( V_53 , V_1076 ,
V_1040 . V_1077 ) ||
F_56 ( V_53 , V_1078 ,
V_1040 . V_1079 ) ||
F_55 ( V_53 , V_1080 ,
V_1040 . V_1081 ) ||
F_56 ( V_53 , V_1082 ,
V_1040 . V_1083 ) ||
F_56 ( V_53 , V_1084 ,
V_1040 . V_1085 ) ||
F_28 ( V_53 , V_1086 ,
V_1040 . V_1087 ) ||
F_28 ( V_53 , V_1088 ,
V_1040 . V_1019 ) ||
F_28 ( V_53 , V_1089 ,
V_1040 . V_1090 ) ||
F_55 ( V_53 , V_1091 ,
V_1040 . V_1092 ) ||
F_55 ( V_53 , V_1093 ,
V_1040 . V_1094 ) ||
F_28 ( V_53 , V_1095 ,
V_1040 . V_1096 ) ||
F_55 ( V_53 , V_1097 ,
V_1040 . V_1098 ) ||
F_28 ( V_53 , V_1099 ,
V_1040 . V_1100 ) )
goto V_61;
F_48 ( V_53 , V_982 ) ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_602:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_209 ( struct V_29 * V_30 ,
struct V_1039 * V_1101 ,
V_22 * V_1102 )
{
struct V_4 * V_95 [ V_1103 + 1 ] ;
V_22 V_753 = 0 ;
#define F_210 ( V_95 , V_1101 , T_8 , T_9 , V_174 , V_753 , V_45 , T_10 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1045 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1103 ,
V_30 -> V_5 [ V_1045 ] ,
V_1104 ) )
return - V_16 ;
F_114 ( V_1103 > 32 ) ;
F_210 ( V_95 , V_1101 , V_1047 , 1 , 255 ,
V_753 , V_1046 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1049 , 1 , 255 ,
V_753 , V_1048 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1051 , 1 , 255 ,
V_753 , V_1050 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1053 , 0 , 255 ,
V_753 , V_1052 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1055 , 0 , 16 ,
V_753 , V_1054 ,
F_34 ) ;
F_210 ( V_95 , V_1101 , V_1057 , 1 , 255 ,
V_753 , V_1056 , F_34 ) ;
F_210 ( V_95 , V_1101 , V_1059 , 1 , 255 ,
V_753 , V_1058 ,
F_34 ) ;
F_210 ( V_95 , V_1101 , V_1061 , 0 , 1 ,
V_753 , V_1060 ,
F_34 ) ;
F_210 ( V_95 , V_1101 , V_1063 ,
1 , 255 , V_753 ,
V_1062 ,
F_4 ) ;
F_210 ( V_95 , V_1101 , V_1065 , 0 , 255 ,
V_753 , V_1064 ,
F_34 ) ;
F_210 ( V_95 , V_1101 , V_1067 , 1 , 65535 ,
V_753 , V_1066 ,
F_4 ) ;
F_210 ( V_95 , V_1101 , V_1069 , 1 , 65535 ,
V_753 , V_1068 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1071 ,
1 , 65535 , V_753 ,
V_1070 ,
F_4 ) ;
F_210 ( V_95 , V_1101 , V_1073 ,
1 , 65535 , V_753 ,
V_1072 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1075 ,
1 , 65535 , V_753 ,
V_1074 ,
F_78 ) ;
F_210 ( V_95 , V_1101 ,
V_1077 ,
1 , 65535 , V_753 ,
V_1076 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1079 , 0 , 4 ,
V_753 , V_1078 ,
F_34 ) ;
F_210 ( V_95 , V_1101 , V_1081 , 1 , 65535 ,
V_753 , V_1080 ,
F_78 ) ;
F_210 ( V_95 , V_1101 ,
V_1083 , 0 , 1 ,
V_753 , V_1082 ,
F_34 ) ;
F_210 ( V_95 , V_1101 , V_1085 , 0 , 1 ,
V_753 , V_1084 ,
F_34 ) ;
F_210 ( V_95 , V_1101 , V_1087 , - 255 , 0 ,
V_753 , V_1086 ,
V_1105 ) ;
F_210 ( V_95 , V_1101 , V_1019 , 0 , 16 ,
V_753 , V_1088 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1090 ,
1 , 65535 , V_753 ,
V_1089 ,
F_4 ) ;
F_210 ( V_95 , V_1101 , V_1092 , 1 , 65535 ,
V_753 , V_1091 ,
F_78 ) ;
F_210 ( V_95 , V_1101 ,
V_1094 ,
1 , 65535 , V_753 ,
V_1093 ,
F_78 ) ;
F_210 ( V_95 , V_1101 , V_1096 ,
V_1106 ,
V_961 ,
V_753 , V_1095 ,
F_4 ) ;
F_210 ( V_95 , V_1101 , V_1098 ,
0 , 65535 , V_753 ,
V_1097 , F_78 ) ;
F_210 ( V_95 , V_1101 , V_1100 , 0 , 0xffffffff ,
V_753 , V_1099 ,
F_4 ) ;
if ( V_1102 )
* V_1102 = V_753 ;
return 0 ;
#undef F_210
}
static int F_211 ( struct V_29 * V_30 ,
struct V_1107 * V_1108 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_4 * V_95 [ V_1109 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1110 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1109 ,
V_30 -> V_5 [ V_1110 ] ,
V_1111 ) )
return - V_16 ;
if ( V_95 [ V_1112 ] )
V_1108 -> V_1113 =
( F_34 ( V_95 [ V_1112 ] ) ) ?
V_1114 :
V_1115 ;
if ( V_95 [ V_1116 ] )
V_1108 -> V_1117 =
( F_34 ( V_95 [ V_1116 ] ) ) ?
V_1118 :
V_1119 ;
if ( V_95 [ V_1120 ] )
V_1108 -> V_1121 =
( F_34 ( V_95 [ V_1120 ] ) ) ?
V_1122 :
V_1123 ;
if ( V_95 [ V_1124 ] ) {
struct V_4 * V_1125 =
V_95 [ V_1124 ] ;
if ( ! F_22 ( V_1125 ) )
return - V_16 ;
V_1108 -> V_1126 = F_23 ( V_1125 ) ;
V_1108 -> V_1127 = F_24 ( V_1125 ) ;
}
if ( V_95 [ V_1128 ] &&
! ( V_7 -> V_18 . V_291 & V_1129 ) )
return - V_16 ;
V_1108 -> V_1130 = F_152 ( V_95 [ V_1128 ] ) ;
V_1108 -> V_1131 = F_152 ( V_95 [ V_1132 ] ) ;
V_1108 -> V_1133 = F_152 ( V_95 [ V_1134 ] ) ;
if ( V_1108 -> V_1133 )
V_1108 -> V_1130 = true ;
if ( V_95 [ V_1135 ] ) {
if ( ! V_1108 -> V_1130 )
return - V_16 ;
V_1108 -> V_1136 =
F_34 ( V_95 [ V_1135 ] ) ;
}
return 0 ;
}
static int F_212 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_1039 V_1101 ;
V_22 V_753 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_542 ;
if ( ! V_7 -> V_351 -> V_381 )
return - V_542 ;
V_35 = F_209 ( V_30 , & V_1101 , & V_753 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1042 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_213 ( V_7 , V_541 , V_753 , & V_1101 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_214 ( const struct V_1137 * V_1138 ,
struct V_31 * V_53 )
{
struct V_4 * V_1139 ;
unsigned int V_159 ;
if ( F_60 ( V_53 , V_1036 , V_1138 -> V_1140 ) ||
( V_1138 -> V_1141 &&
F_56 ( V_53 , V_1142 , V_1138 -> V_1141 ) ) )
goto V_61;
V_1139 = F_47 ( V_53 , V_1143 ) ;
if ( ! V_1139 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1138 -> V_1144 ; V_159 ++ ) {
struct V_4 * V_1145 ;
const struct V_1146 * V_1147 ;
const struct V_1148 * V_1149 ;
const struct V_1150 * V_1151 ;
unsigned int V_1152 ;
V_1147 = & V_1138 -> V_1153 [ V_159 ] ;
V_1149 = & V_1147 -> V_1149 ;
V_1151 = & V_1147 -> V_1151 ;
V_1145 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1145 )
goto V_61;
V_1152 = V_1149 -> V_1152 ;
if ( ! V_1152 )
V_1152 = F_215 ( V_1138 ,
V_1147 ) ;
if ( F_28 ( V_53 , V_1154 ,
V_1147 -> V_51 ) ||
F_28 ( V_53 , V_1155 ,
V_1149 -> V_1156 ) ||
F_28 ( V_53 , V_1157 ,
V_1149 -> V_1158 ) ||
F_28 ( V_53 , V_1159 ,
V_1152 ) ||
F_28 ( V_53 , V_1160 ,
V_1151 -> V_1161 ) ||
F_28 ( V_53 , V_1162 ,
V_1151 -> V_1163 ) ||
F_28 ( V_53 , V_1164 ,
V_1147 -> V_74 ) )
goto V_61;
F_48 ( V_53 , V_1145 ) ;
}
F_48 ( V_53 , V_1139 ) ;
return 0 ;
V_61:
return - V_497 ;
}
static int F_216 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1137 * V_1138 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1165 ) ;
if ( ! V_283 )
goto V_1166;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1167 ;
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1167 = V_18 -> V_490 &
V_491 ;
V_1138 = F_217 ( V_18 ) ;
if ( F_59 ( ! V_1138 && V_1167 ) ) {
F_75 ( V_53 ) ;
return - V_16 ;
}
if ( V_1138 &&
F_28 ( V_53 , V_26 , F_218 ( V_18 ) ) )
goto V_61;
}
if ( ! V_18 && F_219 () &&
F_28 ( V_53 , V_1033 ,
V_1035 ) )
goto V_61;
F_220 () ;
if ( ! V_1138 )
V_1138 = F_221 ( V_1031 ) ;
if ( F_214 ( V_1138 , V_53 ) )
goto V_1168;
F_222 () ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1168:
F_222 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_1166:
F_75 ( V_53 ) ;
return - V_497 ;
}
static int F_223 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 , struct V_18 * V_18 ,
const struct V_1137 * V_1138 )
{
void * V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1165 ) ;
if ( ! V_283 )
return - 1 ;
F_224 ( V_34 , V_283 , & V_38 ) ;
if ( F_214 ( V_1138 , V_53 ) )
goto V_61;
if ( ! V_18 && F_219 () &&
F_28 ( V_53 , V_1033 ,
V_1035 ) )
goto V_61;
if ( V_18 &&
F_28 ( V_53 , V_26 , F_218 ( V_18 ) ) )
goto V_61;
if ( V_18 && V_18 -> V_490 & V_491 &&
F_29 ( V_53 , V_492 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int F_225 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1137 * V_1138 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1169 , V_501 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1031 && V_501 == 0 ) {
V_35 = F_223 ( V_32 , V_34 , V_34 -> V_36 -> V_502 ,
V_503 , NULL ,
F_226 ( V_1031 ) ) ;
if ( V_35 < 0 )
goto V_889;
}
V_1169 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1138 = F_217 ( & V_7 -> V_18 ) ;
if ( ! V_1138 )
continue;
if ( ++ V_1169 <= V_501 )
continue;
V_35 = F_223 ( V_32 , V_34 , V_34 -> V_36 -> V_502 ,
V_503 , & V_7 -> V_18 , V_1138 ) ;
if ( V_35 < 0 ) {
V_1169 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1169 ;
V_35 = V_32 -> V_47 ;
V_889:
F_20 () ;
return V_35 ;
}
static int F_227 ( struct V_4 * V_95 [] ,
struct V_1146 * V_1147 )
{
struct V_1148 * V_1149 = & V_1147 -> V_1149 ;
struct V_1150 * V_1151 = & V_1147 -> V_1151 ;
if ( ! V_95 [ V_1154 ] )
return - V_16 ;
if ( ! V_95 [ V_1155 ] )
return - V_16 ;
if ( ! V_95 [ V_1157 ] )
return - V_16 ;
if ( ! V_95 [ V_1159 ] )
return - V_16 ;
if ( ! V_95 [ V_1162 ] )
return - V_16 ;
V_1147 -> V_51 = F_4 ( V_95 [ V_1154 ] ) ;
V_1149 -> V_1156 =
F_4 ( V_95 [ V_1155 ] ) ;
V_1149 -> V_1158 =
F_4 ( V_95 [ V_1157 ] ) ;
V_1149 -> V_1152 =
F_4 ( V_95 [ V_1159 ] ) ;
V_1151 -> V_1163 =
F_4 ( V_95 [ V_1162 ] ) ;
if ( V_95 [ V_1160 ] )
V_1151 -> V_1161 =
F_4 ( V_95 [ V_1160 ] ) ;
if ( V_95 [ V_1164 ] )
V_1147 -> V_74 =
F_4 ( V_95 [ V_1164 ] ) ;
return 0 ;
}
static int F_228 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1170 + 1 ] ;
struct V_4 * V_1145 ;
char * V_1140 ;
int V_1171 , V_1172 ;
V_22 V_1173 = 0 , V_1174 = 0 , V_1175 ;
enum V_1176 V_1141 = V_1177 ;
struct V_1137 * V_1178 ;
if ( ! V_30 -> V_5 [ V_1036 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1143 ] )
return - V_16 ;
V_1140 = F_23 ( V_30 -> V_5 [ V_1036 ] ) ;
if ( V_30 -> V_5 [ V_1142 ] )
V_1141 = F_34 ( V_30 -> V_5 [ V_1142 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1173 ++ ;
if ( V_1173 > V_1179 )
return - V_16 ;
}
if ( ! F_229 ( V_1140 ) )
return - V_16 ;
V_1175 = sizeof( struct V_1137 ) +
V_1173 * sizeof( struct V_1146 ) ;
V_1178 = F_38 ( V_1175 , V_135 ) ;
if ( ! V_1178 )
return - V_136 ;
V_1178 -> V_1144 = V_1173 ;
V_1178 -> V_1140 [ 0 ] = V_1140 [ 0 ] ;
V_1178 -> V_1140 [ 1 ] = V_1140 [ 1 ] ;
if ( F_230 ( V_1141 ) )
V_1178 -> V_1141 = V_1141 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1172 = F_96 ( V_95 , V_1170 ,
F_23 ( V_1145 ) , F_24 ( V_1145 ) ,
V_1180 ) ;
if ( V_1172 )
goto V_1181;
V_1172 = F_227 ( V_95 , & V_1178 -> V_1153 [ V_1174 ] ) ;
if ( V_1172 )
goto V_1181;
V_1174 ++ ;
if ( V_1174 > V_1179 ) {
V_1172 = - V_16 ;
goto V_1181;
}
}
V_1172 = F_231 ( V_1178 , V_1182 ) ;
V_1178 = NULL ;
V_1181:
F_41 ( V_1178 ) ;
return V_1172 ;
}
static int F_232 ( struct V_4 * V_1183 )
{
struct V_4 * V_1184 , * V_1185 ;
int V_366 = 0 , V_1186 , V_1187 ;
F_39 (attr1, freqs, tmp1) {
V_366 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1184 != V_1185 &&
F_4 ( V_1184 ) == F_4 ( V_1185 ) )
return 0 ;
}
return V_366 ;
}
static bool F_233 ( struct V_18 * V_18 , enum V_289 V_1188 )
{
return V_1188 < V_362 && V_18 -> V_363 [ V_1188 ] ;
}
static int F_234 ( struct V_4 * V_604 , struct V_18 * V_18 ,
struct V_1189 * V_1190 )
{
struct V_4 * V_45 [ V_1191 + 1 ] ;
struct V_4 * V_1192 ;
int V_35 ;
bool V_27 = false ;
int V_159 ;
V_1192 = F_23 ( V_604 ) ;
if ( ! F_235 ( V_1192 , F_24 ( V_1192 ) ) )
return - V_16 ;
V_35 = F_96 ( V_45 , V_1191 , F_23 ( V_1192 ) ,
F_24 ( V_1192 ) , V_1193 ) ;
if ( V_35 )
return V_35 ;
for ( V_159 = 0 ; V_159 <= V_1191 ; V_159 ++ ) {
if ( V_45 [ V_159 ] ) {
if ( V_27 )
return - V_16 ;
V_27 = true ;
}
}
V_1190 -> V_1194 = V_1195 ;
if ( V_45 [ V_1196 ] )
V_1190 -> V_1194 = V_1196 ;
if ( V_45 [ V_1197 ] ) {
V_1190 -> V_1194 = V_1197 ;
V_1190 -> T_8 . V_1198 =
F_4 ( V_45 [ V_1197 ] ) ;
if ( ! F_233 ( V_18 , V_1190 -> T_8 . V_1198 ) )
return - V_16 ;
}
if ( V_45 [ V_1199 ] ) {
struct V_1200 * V_1201 ;
V_1201 = F_23 ( V_45 [ V_1199 ] ) ;
V_1190 -> V_1194 = V_1199 ;
V_1190 -> T_8 . V_1202 . V_290 = V_1201 -> V_290 ;
V_1190 -> T_8 . V_1202 . V_1203 = V_1201 -> V_1203 ;
if ( ! F_233 ( V_18 , V_1190 -> T_8 . V_1202 . V_290 ) )
return - V_16 ;
}
if ( V_1190 -> V_1194 == V_1195 )
return - V_16 ;
if ( ! ( V_18 -> V_495 & F_159 ( V_1190 -> V_1194 ) ) )
return - V_16 ;
return 0 ;
}
static int F_236 ( struct V_4 * * V_5 ,
T_2 * V_652 , T_2 * V_1204 )
{
int V_159 ;
if ( ! V_5 [ V_549 ] && ! V_5 [ V_1205 ] ) {
F_237 ( V_652 ) ;
F_237 ( V_1204 ) ;
V_652 [ 0 ] = 0x2 ;
V_1204 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_549 ] || ! V_5 [ V_1205 ] )
return - V_16 ;
memcpy ( V_652 , F_23 ( V_5 [ V_549 ] ) , V_590 ) ;
memcpy ( V_1204 , F_23 ( V_5 [ V_1205 ] ) , V_590 ) ;
if ( ! F_238 ( V_1204 ) ||
F_238 ( V_652 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_590 ; V_159 ++ )
V_652 [ V_159 ] &= V_1204 [ V_159 ] ;
return 0 ;
}
static int F_239 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
struct V_1206 * V_1207 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1208 = 0 , V_366 , V_159 ;
T_11 V_1127 ;
if ( ! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_351 -> V_1209 )
return - V_542 ;
if ( V_7 -> V_1210 || V_7 -> V_1211 ) {
V_35 = - V_546 ;
goto V_1212;
}
if ( V_30 -> V_5 [ V_1213 ] ) {
V_366 = F_232 (
V_30 -> V_5 [ V_1213 ] ) ;
if ( ! V_366 ) {
V_35 = - V_16 ;
goto V_1212;
}
} else {
V_366 = F_240 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1214 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1208 ++ ;
if ( V_1208 > V_18 -> V_309 ) {
V_35 = - V_16 ;
goto V_1212;
}
if ( V_30 -> V_5 [ V_686 ] )
V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
else
V_1127 = 0 ;
if ( V_1127 > V_18 -> V_313 ) {
V_35 = - V_16 ;
goto V_1212;
}
V_1207 = F_38 ( sizeof( * V_1207 )
+ sizeof( * V_1207 -> V_1215 ) * V_1208
+ sizeof( * V_1207 -> V_367 ) * V_366
+ V_1127 , V_135 ) ;
if ( ! V_1207 ) {
V_35 = - V_136 ;
goto V_1212;
}
if ( V_1208 )
V_1207 -> V_1215 = ( void * ) & V_1207 -> V_367 [ V_366 ] ;
V_1207 -> V_1208 = V_1208 ;
if ( V_1127 ) {
if ( V_1208 )
V_1207 -> V_1126 = ( void * ) ( V_1207 -> V_1215 + V_1208 ) ;
else
V_1207 -> V_1126 = ( void * ) ( V_1207 -> V_367 + V_366 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1213 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1216;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1207 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
} else {
enum V_289 V_290 ;
for ( V_290 = 0 ; V_290 < V_362 ; V_290 ++ ) {
int V_161 ;
if ( ! V_18 -> V_363 [ V_290 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_363 [ V_290 ] -> V_366 ; V_161 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_363 [ V_290 ] -> V_367 [ V_161 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1207 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1216;
}
V_1207 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1208 ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_621 ) {
V_35 = - V_16 ;
goto V_1216;
}
V_1207 -> V_1215 [ V_159 ] . V_595 = F_24 ( V_45 ) ;
memcpy ( V_1207 -> V_1215 [ V_159 ] . V_597 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_686 ] ) {
V_1207 -> V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
memcpy ( ( void * ) V_1207 -> V_1126 ,
F_23 ( V_30 -> V_5 [ V_686 ] ) ,
V_1207 -> V_1127 ) ;
}
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ )
if ( V_18 -> V_363 [ V_159 ] )
V_1207 -> V_1217 [ V_159 ] =
( 1 << V_18 -> V_363 [ V_159 ] -> V_261 ) - 1 ;
if ( V_30 -> V_5 [ V_1218 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_289 V_290 = F_241 ( V_45 ) ;
if ( V_290 < 0 || V_290 >= V_362 ) {
V_35 = - V_16 ;
goto V_1216;
}
if ( ! V_18 -> V_363 [ V_290 ] )
continue;
V_35 = F_242 ( V_18 -> V_363 [ V_290 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1207 -> V_1217 [ V_290 ] ) ;
if ( V_35 )
goto V_1216;
}
}
if ( V_30 -> V_5 [ V_1219 ] ) {
V_1207 -> V_51 = F_4 (
V_30 -> V_5 [ V_1219 ] ) ;
if ( ( V_1207 -> V_51 & V_1220 ) &&
! ( V_18 -> V_291 & V_1221 ) ) {
V_35 = - V_542 ;
goto V_1216;
}
if ( V_1207 -> V_51 & V_1222 ) {
if ( ! ( V_18 -> V_291 &
V_1223 ) ) {
V_35 = - V_542 ;
goto V_1216;
}
if ( V_17 -> V_149 ) {
V_35 = - V_542 ;
goto V_1216;
}
V_35 = F_236 ( V_30 -> V_5 ,
V_1207 -> V_652 ,
V_1207 -> V_1204 ) ;
if ( V_35 )
goto V_1216;
}
}
V_1207 -> V_1224 =
F_152 ( V_30 -> V_5 [ V_1225 ] ) ;
if ( V_30 -> V_5 [ V_549 ] )
memcpy ( V_1207 -> V_548 , F_23 ( V_30 -> V_5 [ V_549 ] ) ,
V_590 ) ;
else
F_243 ( V_1207 -> V_548 ) ;
V_1207 -> V_17 = V_17 ;
V_1207 -> V_18 = & V_7 -> V_18 ;
V_1207 -> V_1226 = V_1227 ;
V_7 -> V_1210 = V_1207 ;
V_35 = F_244 ( V_7 , V_1207 ) ;
if ( ! V_35 ) {
F_245 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_246 ( V_17 -> V_19 ) ;
} else {
V_1216:
V_7 -> V_1210 = NULL ;
F_41 ( V_1207 ) ;
}
V_1212:
return V_35 ;
}
static int F_247 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1228 )
return - V_542 ;
if ( V_7 -> V_1211 )
return 0 ;
if ( ! V_7 -> V_1210 )
return - V_658 ;
F_248 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_249 ( struct V_18 * V_18 , int V_1229 ,
struct V_1230 * V_1207 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_159 = 0 ;
struct V_4 * V_45 ;
if ( ! V_5 [ V_1231 ] ) {
V_22 V_1232 ;
if ( ! V_5 [ V_1233 ] )
return - V_16 ;
V_1232 = F_4 ( V_5 [ V_1233 ] ) ;
if ( ! V_1232 )
return - V_16 ;
V_1207 -> V_1234 [ 0 ] . V_1232 =
F_250 ( V_1232 , V_1235 ) ;
if ( ! V_1207 -> V_1234 [ 0 ] . V_1232 )
return - V_16 ;
if ( V_1207 -> V_1234 [ 0 ] . V_1232 >
V_18 -> V_321 )
V_1207 -> V_1234 [ 0 ] . V_1232 =
V_18 -> V_321 ;
return 0 ;
}
F_39 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1236 [ V_1237 + 1 ] ;
if ( F_59 ( V_159 >= V_1229 ) )
return - V_16 ;
V_35 = F_96 ( V_1236 , V_1237 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1238 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1236 [ V_1239 ] )
return - V_16 ;
V_1207 -> V_1234 [ V_159 ] . V_1232 =
F_4 ( V_1236 [ V_1239 ] ) ;
if ( ! V_1207 -> V_1234 [ V_159 ] . V_1232 ||
V_1207 -> V_1234 [ V_159 ] . V_1232 >
V_18 -> V_321 )
return - V_16 ;
if ( V_1236 [ V_1240 ] ) {
V_1207 -> V_1234 [ V_159 ] . V_1241 =
F_4 ( V_1236 [ V_1240 ] ) ;
if ( ! V_1207 -> V_1234 [ V_159 ] . V_1241 ||
( V_1207 -> V_1234 [ V_159 ] . V_1241 >
V_18 -> V_323 ) )
return - V_16 ;
} else if ( V_159 < V_1229 - 1 ) {
return - V_16 ;
}
V_159 ++ ;
}
if ( V_1207 -> V_1234 [ V_1229 - 1 ] . V_1241 )
return - V_16 ;
return 0 ;
}
static struct V_1230 *
F_251 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1230 * V_1207 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1208 = 0 , V_1242 = 0 , V_366 , V_159 , V_1229 = 0 ;
enum V_289 V_290 ;
T_11 V_1127 ;
struct V_4 * V_95 [ V_1243 + 1 ] ;
T_12 V_1244 = V_1245 ;
if ( ! F_22 ( V_5 [ V_686 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1213 ] ) {
V_366 = F_232 (
V_5 [ V_1213 ] ) ;
if ( ! V_366 )
return F_3 ( - V_16 ) ;
} else {
V_366 = F_240 ( V_18 ) ;
}
if ( V_5 [ V_1214 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1208 ++ ;
if ( V_1208 > V_18 -> V_311 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1246 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1247 ;
V_35 = F_96 ( V_95 , V_1243 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1248 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1249 ] ) {
V_1242 ++ ;
continue;
}
V_1247 = V_95 [ V_1250 ] ;
if ( V_1247 )
V_1244 = V_1105 ( V_1247 ) ;
}
}
if ( ! V_1242 && V_1244 != V_1245 )
V_1242 = 1 ;
if ( V_1242 > V_18 -> V_317 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_686 ] )
V_1127 = F_24 ( V_5 [ V_686 ] ) ;
else
V_1127 = 0 ;
if ( V_1127 > V_18 -> V_315 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1231 ] ) {
if ( V_5 [ V_1233 ] )
return F_3 ( - V_16 ) ;
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1229 ++ ;
} else {
if ( ! V_5 [ V_1233 ] )
return F_3 ( - V_16 ) ;
V_1229 = 1 ;
}
if ( ! V_1229 || V_1229 > V_18 -> V_319 )
return F_3 ( - V_16 ) ;
V_1207 = F_38 ( sizeof( * V_1207 )
+ sizeof( * V_1207 -> V_1215 ) * V_1208
+ sizeof( * V_1207 -> V_1251 ) * V_1242
+ sizeof( * V_1207 -> V_1234 ) * V_1229
+ sizeof( * V_1207 -> V_367 ) * V_366
+ V_1127 , V_135 ) ;
if ( ! V_1207 )
return F_3 ( - V_136 ) ;
if ( V_1208 )
V_1207 -> V_1215 = ( void * ) & V_1207 -> V_367 [ V_366 ] ;
V_1207 -> V_1208 = V_1208 ;
if ( V_1127 ) {
if ( V_1208 )
V_1207 -> V_1126 = ( void * ) ( V_1207 -> V_1215 + V_1208 ) ;
else
V_1207 -> V_1126 = ( void * ) ( V_1207 -> V_367 + V_366 ) ;
}
if ( V_1242 ) {
if ( V_1207 -> V_1126 )
V_1207 -> V_1251 = ( void * ) ( V_1207 -> V_1126 + V_1127 ) ;
else if ( V_1208 )
V_1207 -> V_1251 =
( void * ) ( V_1207 -> V_1215 + V_1208 ) ;
else
V_1207 -> V_1251 =
( void * ) ( V_1207 -> V_367 + V_366 ) ;
}
V_1207 -> V_1242 = V_1242 ;
if ( V_1242 )
V_1207 -> V_1234 = ( void * ) ( V_1207 -> V_1251 +
V_1242 ) ;
else if ( V_1207 -> V_1126 )
V_1207 -> V_1234 = ( void * ) ( V_1207 -> V_1126 + V_1127 ) ;
else if ( V_1208 )
V_1207 -> V_1234 = ( void * ) ( V_1207 -> V_1215 + V_1208 ) ;
else
V_1207 -> V_1234 = ( void * ) ( V_1207 -> V_367 + V_366 ) ;
V_1207 -> V_1252 = V_1229 ;
V_159 = 0 ;
if ( V_5 [ V_1213 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1216;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1207 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
} else {
for ( V_290 = 0 ; V_290 < V_362 ; V_290 ++ ) {
int V_161 ;
if ( ! V_18 -> V_363 [ V_290 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_363 [ V_290 ] -> V_366 ; V_161 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_363 [ V_290 ] -> V_367 [ V_161 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1207 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1216;
}
V_1207 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1208 ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_621 ) {
V_35 = - V_16 ;
goto V_1216;
}
V_1207 -> V_1215 [ V_159 ] . V_595 = F_24 ( V_45 ) ;
memcpy ( V_1207 -> V_1215 [ V_159 ] . V_597 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1246 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_597 , * V_1247 ;
V_35 = F_96 ( V_95 , V_1243 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1248 ) ;
if ( V_35 )
goto V_1216;
V_597 = V_95 [ V_1249 ] ;
if ( V_597 ) {
if ( F_59 ( V_159 >= V_1242 ) ) {
V_35 = - V_16 ;
goto V_1216;
}
if ( F_24 ( V_597 ) > V_621 ) {
V_35 = - V_16 ;
goto V_1216;
}
memcpy ( V_1207 -> V_1251 [ V_159 ] . V_597 . V_597 ,
F_23 ( V_597 ) , F_24 ( V_597 ) ) ;
V_1207 -> V_1251 [ V_159 ] . V_597 . V_595 =
F_24 ( V_597 ) ;
V_1207 -> V_1251 [ V_159 ] . V_1253 =
V_1244 ;
V_1247 = V_95 [ V_1250 ] ;
if ( V_1247 )
V_1207 -> V_1251 [ V_159 ] . V_1253 =
V_1105 ( V_1247 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1242 )
V_1207 -> V_1251 [ 0 ] . V_1253 = V_1244 ;
V_1207 -> V_1254 = V_1255 ;
for ( V_159 = 0 ; V_159 < V_1242 ; V_159 ++ )
V_1207 -> V_1254 =
T_9 ( V_1207 -> V_1251 [ V_159 ] . V_1253 ,
V_1207 -> V_1254 ) ;
} else {
V_1207 -> V_1254 = V_1245 ;
}
if ( V_1127 ) {
V_1207 -> V_1127 = V_1127 ;
memcpy ( ( void * ) V_1207 -> V_1126 ,
F_23 ( V_5 [ V_686 ] ) ,
V_1207 -> V_1127 ) ;
}
if ( V_5 [ V_1219 ] ) {
V_1207 -> V_51 = F_4 (
V_5 [ V_1219 ] ) ;
if ( ( V_1207 -> V_51 & V_1220 ) &&
! ( V_18 -> V_291 & V_1221 ) ) {
V_35 = - V_542 ;
goto V_1216;
}
if ( V_1207 -> V_51 & V_1222 ) {
V_22 V_1256 = V_1257 ;
if ( ! V_17 )
V_1256 = V_1258 ;
if ( ! ( V_18 -> V_291 & V_1256 ) ) {
V_35 = - V_542 ;
goto V_1216;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_542 ;
goto V_1216;
}
V_35 = F_236 ( V_5 , V_1207 -> V_652 ,
V_1207 -> V_1204 ) ;
if ( V_35 )
goto V_1216;
}
}
if ( V_5 [ V_1259 ] )
V_1207 -> V_1260 =
F_4 ( V_5 [ V_1259 ] ) ;
V_35 = F_249 ( V_18 , V_1229 , V_1207 , V_5 ) ;
if ( V_35 )
goto V_1216;
V_1207 -> V_1226 = V_1227 ;
return V_1207 ;
V_1216:
F_41 ( V_1207 ) ;
return F_3 ( V_35 ) ;
}
static int F_252 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_1230 * V_1261 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_423 )
return - V_542 ;
if ( V_7 -> V_1261 )
return - V_1032 ;
V_1261 = F_251 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_253 ( V_1261 ) ;
if ( V_35 )
goto V_889;
V_35 = F_254 ( V_7 , V_541 , V_1261 ) ;
if ( V_35 )
goto V_1216;
V_1261 -> V_541 = V_541 ;
V_1261 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_634 ] )
V_1261 -> V_635 = V_30 -> V_506 ;
F_255 ( V_7 -> V_1261 , V_1261 ) ;
F_256 ( V_7 , V_541 ,
V_1262 ) ;
return 0 ;
V_1216:
F_41 ( V_1261 ) ;
V_889:
return V_35 ;
}
static int F_257 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_1263 )
return - V_542 ;
return F_258 ( V_7 , false ) ;
}
static int F_259 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_521 V_522 ;
enum V_1176 V_1141 ;
unsigned int V_1264 ;
int V_35 ;
V_1141 = F_260 ( V_17 -> V_18 ) ;
if ( V_1141 == V_1177 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_522 ) ;
if ( V_35 )
return V_35 ;
if ( F_261 ( V_541 ) )
return - V_546 ;
if ( V_17 -> V_1265 )
return - V_546 ;
V_35 = F_262 ( V_17 -> V_18 , & V_522 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_263 ( V_17 -> V_18 , & V_522 ) )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1266 )
return - V_542 ;
V_1264 = F_264 ( & V_7 -> V_18 , & V_522 ) ;
if ( F_59 ( ! V_1264 ) )
V_1264 = V_1267 ;
V_35 = F_265 ( V_7 , V_541 , & V_522 , V_1264 ) ;
if ( ! V_35 ) {
V_17 -> V_522 = V_522 ;
V_17 -> V_1265 = true ;
V_17 -> V_1268 = V_1227 ;
V_17 -> V_1264 = V_1264 ;
}
return V_35 ;
}
static int F_266 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_1269 V_137 ;
static struct V_4 * V_1270 [ V_1271 + 1 ] ;
int V_35 ;
bool V_1272 = false ;
int V_47 , V_159 ;
V_22 V_1273 ;
if ( ! V_7 -> V_351 -> V_442 ||
! ( V_7 -> V_18 . V_51 & V_441 ) )
return - V_542 ;
switch ( V_541 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1272 = true ;
if ( ! V_17 -> V_543 )
return - V_1274 ;
break;
case V_146 :
if ( ! V_17 -> V_595 )
return - V_1274 ;
break;
case V_145 :
if ( ! V_17 -> V_1042 )
return - V_1274 ;
break;
default:
return - V_542 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_524 ] ||
! V_30 -> V_5 [ V_1275 ] )
return - V_16 ;
if ( V_1272 && ! V_30 -> V_5 [ V_1276 ] )
return - V_16 ;
V_1273 = F_4 ( V_30 -> V_5 [ V_1275 ] ) ;
if ( V_1273 > 255 )
return - V_16 ;
V_137 . V_1277 = V_1273 ;
if ( ! V_1272 )
goto V_1278;
V_35 = F_146 ( V_30 -> V_5 , & V_137 . V_1279 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1270 , V_1271 ,
V_30 -> V_5 [ V_1276 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_146 ( V_1270 , & V_137 . V_1280 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1270 [ V_1281 ] )
return - V_16 ;
V_47 = F_24 ( V_1270 [ V_1281 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1282 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1282 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1283 =
F_23 ( V_1270 [ V_1281 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1282 ; V_159 ++ ) {
T_3 V_1284 = V_137 . V_1283 [ V_159 ] ;
if ( V_1284 >= V_137 . V_1280 . V_693 )
return - V_16 ;
if ( V_137 . V_1280 . V_692 [ V_1284 ] != V_137 . V_1277 )
return - V_16 ;
}
if ( V_1270 [ V_1285 ] ) {
V_47 = F_24 ( V_1270 [ V_1285 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1286 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1282 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1287 =
F_23 ( V_1270 [ V_1285 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1286 ; V_159 ++ ) {
T_3 V_1284 = V_137 . V_1287 [ V_159 ] ;
if ( V_1284 >= V_137 . V_1280 . V_702 )
return - V_16 ;
if ( V_137 . V_1280 . V_701 [ V_1284 ] !=
V_137 . V_1277 )
return - V_16 ;
}
}
V_1278:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_522 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_522 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_262 ( V_17 -> V_18 ,
& V_137 . V_522 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_137 . V_1288 = true ;
if ( V_30 -> V_5 [ V_1289 ] )
V_137 . V_1290 = true ;
F_113 ( V_17 ) ;
V_35 = F_267 ( V_7 , V_541 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_268 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1291 * V_1292 )
{
struct V_1293 * V_355 = & V_1292 -> V_1294 ;
const struct V_1295 * V_1296 ;
void * V_283 ;
struct V_4 * V_1297 ;
F_43 ( V_17 ) ;
V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1298 ) ;
if ( ! V_283 )
return - 1 ;
F_224 ( V_34 , V_283 , & V_38 ) ;
if ( F_28 ( V_53 , V_293 , V_7 -> V_1299 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) )
goto V_61;
V_1297 = F_47 ( V_53 , V_1300 ) ;
if ( ! V_1297 )
goto V_61;
if ( ( ! F_269 ( V_355 -> V_548 ) &&
F_51 ( V_53 , V_1301 , V_590 , V_355 -> V_548 ) ) )
goto V_61;
F_220 () ;
if ( F_204 ( V_355 -> V_696 ) &&
F_29 ( V_53 , V_1302 ) )
goto V_1303;
V_1296 = F_221 ( V_355 -> V_1296 ) ;
if ( V_1296 ) {
if ( F_104 ( V_53 , V_1304 , V_1296 -> V_1305 ,
V_1306 ) )
goto V_1303;
if ( V_1296 -> V_47 && F_51 ( V_53 , V_1307 ,
V_1296 -> V_47 , V_1296 -> V_138 ) )
goto V_1303;
}
V_1296 = F_221 ( V_355 -> V_694 ) ;
if ( V_1296 && V_1296 -> V_1308 ) {
if ( F_104 ( V_53 , V_1309 , V_1296 -> V_1305 ,
V_1306 ) )
goto V_1303;
if ( V_1296 -> V_47 && F_51 ( V_53 , V_1310 ,
V_1296 -> V_47 , V_1296 -> V_138 ) )
goto V_1303;
}
F_222 () ;
if ( V_355 -> V_543 &&
F_55 ( V_53 , V_1311 , V_355 -> V_543 ) )
goto V_61;
if ( F_55 ( V_53 , V_1312 , V_355 -> V_950 ) ||
F_28 ( V_53 , V_1313 , V_355 -> V_1314 -> V_60 ) ||
F_28 ( V_53 , V_1315 , V_355 -> V_1316 ) ||
F_28 ( V_53 , V_1317 ,
F_270 ( V_1227 - V_1292 -> V_1318 ) ) )
goto V_61;
if ( V_1292 -> V_1319 &&
F_104 ( V_53 , V_1320 ,
V_1292 -> V_1319 , V_1306 ) )
goto V_61;
switch ( V_7 -> V_18 . V_821 ) {
case V_822 :
if ( F_28 ( V_53 , V_1321 , V_355 -> signal ) )
goto V_61;
break;
case V_1322 :
if ( F_56 ( V_53 , V_1323 , V_355 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1292 == V_17 -> V_149 &&
F_28 ( V_53 , V_1324 ,
V_1325 ) )
goto V_61;
break;
case V_146 :
if ( V_1292 == V_17 -> V_149 &&
F_28 ( V_53 , V_1324 ,
V_1326 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1297 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_1303:
F_222 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int F_271 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1291 * V_1209 ;
struct V_1 * V_17 ;
int V_501 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
F_272 ( & V_7 -> V_1327 ) ;
F_273 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1299 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_501 )
continue;
if ( F_268 ( V_32 , V_34 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_7 , V_17 , V_1209 ) < 0 ) {
V_105 -- ;
break;
}
}
F_274 ( & V_7 -> V_1327 ) ;
F_115 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_275 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_541 ,
bool V_1328 ,
struct V_1329 * V_1330 )
{
void * V_283 ;
struct V_4 * V_1331 ;
if ( ! V_1330 -> V_1314 && ! V_1328 )
return 0 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1332 ) ;
if ( ! V_283 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_541 -> V_20 ) )
goto V_61;
V_1331 = F_47 ( V_53 , V_1333 ) ;
if ( ! V_1331 )
goto V_61;
if ( V_1330 -> V_1314 &&
F_28 ( V_53 , V_1334 ,
V_1330 -> V_1314 -> V_60 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1335 ) &&
F_56 ( V_53 , V_1336 , V_1330 -> V_1337 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1338 ) &&
F_29 ( V_53 , V_1339 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1340 ) &&
F_104 ( V_53 , V_1341 ,
V_1330 -> time , V_1342 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1343 ) &&
F_104 ( V_53 , V_1344 ,
V_1330 -> V_1345 , V_1342 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1346 ) &&
F_104 ( V_53 , V_1347 ,
V_1330 -> V_1348 , V_1342 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1349 ) &&
F_104 ( V_53 , V_1350 ,
V_1330 -> V_1351 , V_1342 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1352 ) &&
F_104 ( V_53 , V_1353 ,
V_1330 -> V_1354 , V_1342 ) )
goto V_61;
if ( ( V_1330 -> V_804 & V_1355 ) &&
F_104 ( V_53 , V_1356 ,
V_1330 -> V_1357 , V_1342 ) )
goto V_61;
F_48 ( V_53 , V_1331 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int F_276 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1329 V_1330 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1358 = V_34 -> args [ 2 ] ;
int V_355 ;
bool V_1359 ;
V_355 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_355 )
return V_355 ;
V_1359 = V_38 . V_40 [ V_1360 ] ;
if ( ! V_17 -> V_19 ) {
V_355 = - V_16 ;
goto V_889;
}
if ( ! V_7 -> V_351 -> V_1361 ) {
V_355 = - V_542 ;
goto V_889;
}
while ( 1 ) {
V_355 = F_277 ( V_7 , V_17 -> V_19 , V_1358 , & V_1330 ) ;
if ( V_355 == - V_658 )
break;
if ( V_355 )
goto V_889;
if ( V_1330 . V_1314 &&
V_1330 . V_1314 -> V_51 & V_62 ) {
V_1358 ++ ;
continue;
}
if ( F_275 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_17 -> V_19 , V_1359 , & V_1330 ) < 0 )
goto V_602;
V_1358 ++ ;
}
V_602:
V_34 -> args [ 2 ] = V_1358 ;
V_355 = V_32 -> V_47 ;
V_889:
F_21 ( V_7 ) ;
return V_355 ;
}
static bool F_278 ( V_22 V_1362 )
{
return ! ( V_1362 & ~ ( V_1363 |
V_1364 ) ) ;
}
static int F_279 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_548 , * V_597 , * V_1126 = NULL , * V_1365 = NULL ;
int V_35 , V_595 , V_1127 = 0 , V_1366 = 0 ;
enum V_704 V_705 ;
struct V_93 V_92 ;
bool V_1367 ;
if ( ! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_723 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_596 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_524 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_655 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1368 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1369 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_159 ;
bool V_1370 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_338 ; V_159 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_339 [ V_159 ] ) {
V_1370 = true ;
break;
}
}
if ( ! V_1370 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_385 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_524 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_597 = F_23 ( V_30 -> V_5 [ V_596 ] ) ;
V_595 = F_24 ( V_30 -> V_5 [ V_596 ] ) ;
if ( V_30 -> V_5 [ V_686 ] ) {
V_1126 = F_23 ( V_30 -> V_5 [ V_686 ] ) ;
V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
}
V_705 = F_4 ( V_30 -> V_5 [ V_723 ] ) ;
if ( ! F_148 ( V_7 , V_705 , V_707 ) )
return - V_16 ;
if ( V_705 == V_709 &&
! V_30 -> V_5 [ V_1371 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1371 ] ) {
if ( V_705 != V_709 )
return - V_16 ;
V_1365 = F_23 ( V_30 -> V_5 [ V_1371 ] ) ;
V_1366 = F_24 ( V_30 -> V_5 [ V_1371 ] ) ;
if ( V_1366 < 4 )
return - V_16 ;
}
V_1367 = ! ! V_30 -> V_5 [ V_1372 ] ;
if ( V_1367 )
return 0 ;
F_113 ( V_541 -> V_28 ) ;
V_35 = F_280 ( V_7 , V_541 , V_55 , V_705 , V_548 ,
V_597 , V_595 , V_1126 , V_1127 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1365 , V_1366 ) ;
F_115 ( V_541 -> V_28 ) ;
return V_35 ;
}
static int F_151 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1373 * V_1374 ,
int V_1375 )
{
memset ( V_1374 , 0 , sizeof( * V_1374 ) ) ;
V_1374 -> V_1376 = V_30 -> V_5 [ V_1377 ] ;
if ( V_30 -> V_5 [ V_343 ] ) {
T_3 V_1378 ;
V_1378 = F_78 (
V_30 -> V_5 [ V_343 ] ) ;
V_1374 -> V_1379 = F_281 ( V_1378 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_342 ) &&
V_1378 != V_1380 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1381 ] )
V_1374 -> V_1382 = true ;
} else
V_1374 -> V_1379 = F_281 ( V_1380 ) ;
if ( V_30 -> V_5 [ V_1383 ] ) {
void * V_138 ;
int V_47 , V_159 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1383 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1383 ] ) ;
V_1374 -> V_1384 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1374 -> V_1384 > V_1375 )
return - V_16 ;
memcpy ( V_1374 -> V_1385 , V_138 , V_47 ) ;
for ( V_159 = 0 ; V_159 < V_1374 -> V_1384 ; V_159 ++ )
if ( ! F_282 (
& V_7 -> V_18 ,
V_1374 -> V_1385 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1386 ] ) {
V_1374 -> V_1387 =
F_4 ( V_30 -> V_5 [ V_1386 ] ) ;
if ( ! F_282 ( & V_7 -> V_18 ,
V_1374 -> V_1387 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1388 ] ) {
V_1374 -> V_1362 =
F_4 ( V_30 -> V_5 [ V_1388 ] ) ;
if ( ! F_278 ( V_1374 -> V_1362 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1389 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1389 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1389 ] ) ;
V_1374 -> V_1390 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1374 -> V_1390 > V_1391 )
return - V_16 ;
memcpy ( V_1374 -> V_1392 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_283 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1393 V_1394 = {} ;
const T_2 * V_548 , * V_597 ;
int V_35 , V_595 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_549 ] ||
! V_30 -> V_5 [ V_596 ] ||
! V_30 -> V_5 [ V_524 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_387 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_524 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_597 = F_23 ( V_30 -> V_5 [ V_596 ] ) ;
V_595 = F_24 ( V_30 -> V_5 [ V_596 ] ) ;
if ( V_30 -> V_5 [ V_686 ] ) {
V_1394 . V_1126 = F_23 ( V_30 -> V_5 [ V_686 ] ) ;
V_1394 . V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
}
if ( V_30 -> V_5 [ V_1395 ] ) {
enum V_1396 V_1397 =
F_4 ( V_30 -> V_5 [ V_1395 ] ) ;
if ( V_1397 == V_1398 )
V_1394 . V_1399 = true ;
else if ( V_1397 != V_1400 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1401 ] )
V_1394 . V_1402 = F_23 ( V_30 -> V_5 [ V_1401 ] ) ;
if ( F_152 ( V_30 -> V_5 [ V_1403 ] ) )
V_1394 . V_51 |= V_1404 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1394 . V_1405 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1394 . V_1405 ) ) ;
if ( V_30 -> V_5 [ V_940 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1394 . V_911 ,
F_23 ( V_30 -> V_5 [ V_940 ] ) ,
sizeof( V_1394 . V_911 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1406 ] ) )
V_1394 . V_51 |= V_1407 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_1394 . V_1408 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_1394 . V_1408 ) ) ;
if ( V_30 -> V_5 [ V_941 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] )
return - V_16 ;
memcpy ( & V_1394 . V_912 ,
F_23 ( V_30 -> V_5 [ V_941 ] ) ,
sizeof( V_1394 . V_912 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1409 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_291 &
V_1410 ) &&
( V_7 -> V_18 . V_291 & V_1411 ) ) &&
! F_284 ( & V_7 -> V_18 ,
V_1412 ) )
return - V_16 ;
V_1394 . V_51 |= V_1413 ;
}
V_35 = F_151 ( V_7 , V_30 , & V_1394 . V_725 , 1 ) ;
if ( ! V_35 ) {
F_113 ( V_541 -> V_28 ) ;
V_35 = F_285 ( V_7 , V_541 , V_55 , V_548 ,
V_597 , V_595 , & V_1394 ) ;
F_115 ( V_541 -> V_28 ) ;
}
return V_35 ;
}
static int F_286 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
const T_2 * V_1126 = NULL , * V_548 ;
int V_1127 = 0 , V_35 ;
T_3 V_976 ;
bool V_1367 ;
if ( ! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_975 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_389 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_976 = F_78 ( V_30 -> V_5 [ V_975 ] ) ;
if ( V_976 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_686 ] ) {
V_1126 = F_23 ( V_30 -> V_5 [ V_686 ] ) ;
V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
}
V_1367 = ! ! V_30 -> V_5 [ V_1372 ] ;
F_113 ( V_541 -> V_28 ) ;
V_35 = F_287 ( V_7 , V_541 , V_548 , V_1126 , V_1127 , V_976 ,
V_1367 ) ;
F_115 ( V_541 -> V_28 ) ;
return V_35 ;
}
static int F_288 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
const T_2 * V_1126 = NULL , * V_548 ;
int V_1127 = 0 , V_35 ;
T_3 V_976 ;
bool V_1367 ;
if ( ! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_975 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_391 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_976 = F_78 ( V_30 -> V_5 [ V_975 ] ) ;
if ( V_976 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_686 ] ) {
V_1126 = F_23 ( V_30 -> V_5 [ V_686 ] ) ;
V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
}
V_1367 = ! ! V_30 -> V_5 [ V_1372 ] ;
F_113 ( V_541 -> V_28 ) ;
V_35 = F_289 ( V_7 , V_541 , V_548 , V_1126 , V_1127 , V_976 ,
V_1367 ) ;
F_115 ( V_541 -> V_28 ) ;
return V_35 ;
}
static bool
F_290 ( struct V_6 * V_7 ,
int V_1414 [ V_362 ] ,
int V_1415 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_290 , V_159 ;
for ( V_290 = 0 ; V_290 < V_362 ; V_290 ++ ) {
struct V_239 * V_240 ;
V_240 = V_18 -> V_363 [ V_290 ] ;
if ( ! V_240 )
continue;
for ( V_159 = 0 ; V_159 < V_240 -> V_261 ; V_159 ++ ) {
if ( V_240 -> V_262 [ V_159 ] . V_264 == V_1415 ) {
V_1414 [ V_290 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_291 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1416 V_1417 ;
struct V_18 * V_18 ;
struct V_130 * V_1418 = NULL ;
int V_35 ;
memset ( & V_1417 , 0 , sizeof( V_1417 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_596 ] ||
! F_24 ( V_30 -> V_5 [ V_596 ] ) )
return - V_16 ;
V_1417 . V_543 = 100 ;
if ( V_30 -> V_5 [ V_712 ] ) {
V_1417 . V_543 =
F_4 ( V_30 -> V_5 [ V_712 ] ) ;
if ( V_1417 . V_543 < 1 || V_1417 . V_543 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_393 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_146 )
return - V_542 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_549 ] ) {
V_1417 . V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( ! F_120 ( V_1417 . V_548 ) )
return - V_16 ;
}
V_1417 . V_597 = F_23 ( V_30 -> V_5 [ V_596 ] ) ;
V_1417 . V_595 = F_24 ( V_30 -> V_5 [ V_596 ] ) ;
if ( V_30 -> V_5 [ V_686 ] ) {
V_1417 . V_1126 = F_23 ( V_30 -> V_5 [ V_686 ] ) ;
V_1417 . V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1417 . V_522 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_292 ( & V_7 -> V_18 , & V_1417 . V_522 ,
V_146 ) )
return - V_16 ;
switch ( V_1417 . V_522 . V_525 ) {
case V_539 :
case V_540 :
case V_526 :
break;
case V_581 :
case V_582 :
if ( ! ( V_7 -> V_18 . V_291 & V_1419 ) )
return - V_16 ;
break;
case V_1420 :
case V_1421 :
case V_1422 :
if ( ! ( V_7 -> V_18 . V_291 & V_1419 ) )
return - V_16 ;
if ( ! F_284 ( & V_7 -> V_18 ,
V_1423 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1417 . V_1424 = ! ! V_30 -> V_5 [ V_1425 ] ;
V_1417 . V_721 = ! ! V_30 -> V_5 [ V_722 ] ;
if ( V_30 -> V_5 [ V_1023 ] ) {
T_2 * V_1217 =
F_23 ( V_30 -> V_5 [ V_1023 ] ) ;
int V_1426 =
F_24 ( V_30 -> V_5 [ V_1023 ] ) ;
struct V_239 * V_240 =
V_18 -> V_363 [ V_1417 . V_522 . V_55 -> V_290 ] ;
V_35 = F_242 ( V_240 , V_1217 , V_1426 ,
& V_1417 . V_1024 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1417 . V_1405 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1417 . V_1405 ) ) ;
if ( V_30 -> V_5 [ V_940 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1417 . V_911 ,
F_23 ( V_30 -> V_5 [ V_940 ] ) ,
sizeof( V_1417 . V_911 ) ) ;
}
if ( V_30 -> V_5 [ V_1427 ] &&
! F_290 ( V_7 , V_1417 . V_1414 ,
F_4 ( V_30 -> V_5 [ V_1427 ] ) ) )
return - V_16 ;
if ( V_1417 . V_721 && V_30 -> V_5 [ V_1428 ] ) {
bool V_132 = false ;
V_1418 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1428 ] ,
& V_132 ) ;
if ( F_17 ( V_1418 ) )
return F_18 ( V_1418 ) ;
if ( ( V_1417 . V_522 . V_525 != V_526 ) &&
V_132 ) {
F_293 ( V_1418 ) ;
return - V_16 ;
}
}
V_1417 . V_1376 =
F_152 ( V_30 -> V_5 [ V_1377 ] ) ;
V_1417 . V_1429 =
F_152 ( V_30 -> V_5 [ V_1430 ] ) ;
V_35 = F_294 ( V_7 , V_541 , & V_1417 , V_1418 ) ;
if ( V_35 )
F_293 ( V_1418 ) ;
return V_35 ;
}
static int F_295 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1431 )
return - V_542 ;
if ( V_541 -> V_28 -> V_141 != V_146 )
return - V_542 ;
return F_296 ( V_7 , V_541 , false ) ;
}
static int F_297 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
int V_1414 [ V_362 ] ;
V_22 V_1432 ;
int V_35 ;
if ( V_541 -> V_28 -> V_141 != V_146 &&
V_541 -> V_28 -> V_141 != V_145 &&
V_541 -> V_28 -> V_141 != V_152 )
return - V_542 ;
if ( ! V_7 -> V_351 -> V_433 )
return - V_542 ;
memset ( V_1414 , 0 , sizeof( V_1414 ) ) ;
if ( ! V_30 -> V_5 [ V_1427 ] )
return - V_16 ;
V_1432 = F_4 ( V_30 -> V_5 [ V_1427 ] ) ;
if ( ! F_290 ( V_7 , V_1414 , V_1432 ) )
return - V_16 ;
V_35 = F_298 ( V_7 , V_541 , V_1414 ) ;
return V_35 ;
}
static struct V_31 *
F_299 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1433 ,
V_22 V_49 , V_22 V_50 , enum V_280 V_52 ,
enum V_768 V_45 ,
const struct V_481 * V_30 ,
T_13 V_1434 )
{
struct V_31 * V_32 ;
void * V_283 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1433 + 100 , V_1434 ) ;
if ( ! V_32 )
return NULL ;
V_283 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_300 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1435 ,
V_30 -> V_1436 ) )
goto V_61;
if ( F_28 ( V_32 , V_1437 ,
V_30 -> V_1438 ) )
goto V_61;
}
if ( V_17 ) {
if ( F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) , V_589 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_32 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_61;
}
V_138 = F_47 ( V_32 , V_45 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_283 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_138 ;
return V_32 ;
V_61:
F_300 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_301 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_280 V_52 ,
enum V_768 V_45 ,
int V_1439 ,
int V_1433 , T_13 V_1434 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_481 * V_30 ;
switch ( V_52 ) {
case V_1440 :
if ( F_59 ( V_1439 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1441 :
if ( F_59 ( V_1439 < 0 ||
V_1439 >= V_18 -> V_485 ) )
return NULL ;
V_30 = & V_18 -> V_487 [ V_1439 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_299 ( V_7 , V_17 , V_1433 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1434 ) ;
}
void F_302 ( struct V_31 * V_32 , T_13 V_1434 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1442 V_1443 = V_1444 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
if ( V_138 -> F_241 == V_483 )
V_1443 = V_1445 ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1443 , V_1434 ) ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_435 )
return - V_542 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1446 ] )
return - V_16 ;
V_7 -> V_1447 = V_30 ;
V_35 = F_304 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1446 ] ) ,
F_24 ( V_30 -> V_5 [ V_1446 ] ) ) ;
V_7 -> V_1447 = NULL ;
return V_35 ;
}
static int F_305 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1448 ;
void * V_138 = NULL ;
int V_1449 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1448 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_889;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_889;
}
V_1448 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1446 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1446 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1449 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1448 ) ;
if ( ! V_7 ) {
V_35 = - V_658 ;
goto V_889;
}
if ( ! V_7 -> V_351 -> V_1450 ) {
V_35 = - V_542 ;
goto V_889;
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_1440 ) ;
struct V_4 * V_1451 ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_1448 ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1451 = F_47 ( V_32 , V_1446 ) ;
if ( ! V_1451 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = F_306 ( V_7 , V_32 , V_34 , V_138 , V_1449 ) ;
F_48 ( V_32 , V_1451 ) ;
if ( V_35 == - V_91 || V_35 == - V_658 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_889;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1448 + 1 ;
V_889:
F_20 () ;
return V_35 ;
}
static int F_307 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1452 V_449 ;
struct V_18 * V_18 ;
struct V_130 * V_1418 = NULL ;
int V_35 ;
memset ( & V_449 , 0 , sizeof( V_449 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_596 ] ||
! F_24 ( V_30 -> V_5 [ V_596 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_723 ] ) {
V_449 . V_705 =
F_4 ( V_30 -> V_5 [ V_723 ] ) ;
if ( ! F_148 ( V_7 , V_449 . V_705 ,
V_450 ) )
return - V_16 ;
} else
V_449 . V_705 = V_724 ;
V_449 . V_721 = V_30 -> V_5 [ V_722 ] ;
V_35 = F_151 ( V_7 , V_30 , & V_449 . V_725 ,
V_726 ) ;
if ( V_35 )
return V_35 ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
V_18 = & V_7 -> V_18 ;
V_449 . V_1453 = - 1 ;
if ( V_30 -> V_5 [ V_1454 ] &&
( V_18 -> V_51 & V_330 ) ) {
V_449 . V_1453 =
F_78 ( V_30 -> V_5 [ V_1454 ] ) ;
}
if ( V_30 -> V_5 [ V_549 ] )
V_449 . V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
else if ( V_30 -> V_5 [ V_1455 ] )
V_449 . V_1456 =
F_23 ( V_30 -> V_5 [ V_1455 ] ) ;
V_449 . V_597 = F_23 ( V_30 -> V_5 [ V_596 ] ) ;
V_449 . V_595 = F_24 ( V_30 -> V_5 [ V_596 ] ) ;
if ( V_30 -> V_5 [ V_686 ] ) {
V_449 . V_1126 = F_23 ( V_30 -> V_5 [ V_686 ] ) ;
V_449 . V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
}
if ( V_30 -> V_5 [ V_1395 ] ) {
V_449 . V_1397 = F_4 ( V_30 -> V_5 [ V_1395 ] ) ;
if ( V_449 . V_1397 != V_1398 &&
V_449 . V_1397 != V_1400 )
return - V_16 ;
} else {
V_449 . V_1397 = V_1400 ;
}
if ( V_30 -> V_5 [ V_1401 ] )
V_449 . V_1402 =
F_23 ( V_30 -> V_5 [ V_1401 ] ) ;
if ( V_30 -> V_5 [ V_524 ] ) {
V_449 . V_1314 = F_44 (
V_18 , V_30 -> V_5 [ V_524 ] ) ;
if ( ! V_449 . V_1314 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1457 ] ) {
V_449 . V_1458 = F_44 (
V_18 , V_30 -> V_5 [ V_1457 ] ) ;
if ( ! V_449 . V_1458 )
return - V_16 ;
}
if ( V_449 . V_721 && V_30 -> V_5 [ V_1428 ] ) {
V_1418 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1428 ] , NULL ) ;
if ( F_17 ( V_1418 ) )
return F_18 ( V_1418 ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1403 ] ) )
V_449 . V_51 |= V_1404 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_449 . V_1405 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_449 . V_1405 ) ) ;
if ( V_30 -> V_5 [ V_940 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] ) {
F_293 ( V_1418 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_911 ,
F_23 ( V_30 -> V_5 [ V_940 ] ) ,
sizeof( V_449 . V_911 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1406 ] ) )
V_449 . V_51 |= V_1407 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_449 . V_1408 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_449 . V_1408 ) ) ;
if ( V_30 -> V_5 [ V_941 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] ) {
F_293 ( V_1418 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_912 ,
F_23 ( V_30 -> V_5 [ V_941 ] ) ,
sizeof( V_449 . V_912 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1409 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_291 &
V_1410 ) &&
( V_7 -> V_18 . V_291 & V_1411 ) ) &&
! F_284 ( & V_7 -> V_18 ,
V_1412 ) ) {
F_293 ( V_1418 ) ;
return - V_16 ;
}
V_449 . V_51 |= V_1413 ;
}
V_449 . V_743 = F_152 ( V_30 -> V_5 [ V_744 ] ) ;
if ( V_449 . V_743 && ! V_7 -> V_18 . V_363 [ V_745 ] ) {
F_293 ( V_1418 ) ;
return - V_542 ;
}
if ( V_30 -> V_5 [ V_496 ] ) {
if ( V_449 . V_548 ) {
F_293 ( V_1418 ) ;
return - V_16 ;
}
V_35 = F_234 ( V_30 -> V_5 [ V_496 ] ,
V_18 , & V_449 . V_1190 ) ;
if ( V_35 ) {
F_293 ( V_1418 ) ;
return V_35 ;
}
}
F_113 ( V_541 -> V_28 ) ;
V_35 = F_308 ( V_7 , V_541 , & V_449 , V_1418 ,
V_449 . V_1402 ) ;
F_115 ( V_541 -> V_28 ) ;
if ( V_35 )
F_293 ( V_1418 ) ;
return V_35 ;
}
static int F_309 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_3 V_1459 ;
int V_498 ;
if ( ! V_30 -> V_5 [ V_975 ] )
V_1459 = V_1460 ;
else
V_1459 = F_78 ( V_30 -> V_5 [ V_975 ] ) ;
if ( V_1459 == 0 )
return - V_16 ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
F_113 ( V_541 -> V_28 ) ;
V_498 = F_310 ( V_7 , V_541 , V_1459 , true ) ;
F_115 ( V_541 -> V_28 ) ;
return V_498 ;
}
static int F_311 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1461 ] ) {
V_22 V_1462 = F_4 ( V_30 -> V_5 [ V_1461 ] ) ;
V_2 = F_312 ( V_1462 ) ;
} else if ( V_30 -> V_5 [ V_1463 ] ) {
V_22 V_1464 = F_4 ( V_30 -> V_5 [ V_1463 ] ) ;
V_2 = F_313 ( V_1464 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_314 ( V_7 , V_2 ) ;
F_315 ( V_2 ) ;
return V_35 ;
}
static int F_316 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
int (* F_317)( struct V_18 * V_18 , struct V_25 * V_541 ,
struct V_1465 * V_1466 ) = NULL ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1465 V_1466 ;
memset ( & V_1466 , 0 , sizeof( struct V_1465 ) ) ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1467 ] )
return - V_16 ;
V_1466 . V_1468 = F_23 ( V_30 -> V_5 [ V_1467 ] ) ;
V_1466 . V_548 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
switch ( V_30 -> V_1469 -> V_52 ) {
case V_1470 :
F_317 = V_7 -> V_351 -> V_397 ;
break;
case V_1471 :
F_317 = V_7 -> V_351 -> V_399 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_317 )
return - V_542 ;
return F_317 ( & V_7 -> V_18 , V_541 , & V_1466 ) ;
}
static int F_318 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
if ( V_541 -> V_28 -> V_141 != V_147 &&
V_541 -> V_28 -> V_141 != V_148 )
return - V_542 ;
if ( ! V_7 -> V_351 -> V_401 )
return - V_542 ;
return F_319 ( V_7 , V_541 ) ;
}
static int F_320 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 V_1472 , V_1473 ;
V_22 V_1474 = 0 ;
T_3 V_1475 ;
T_2 * V_1476 ;
bool V_1477 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_418 )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_1478 ] ||
! V_30 -> V_5 [ V_1479 ] ||
! V_30 -> V_5 [ V_1480 ] ||
! V_30 -> V_5 [ V_686 ] ||
! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_1476 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_1472 = F_34 ( V_30 -> V_5 [ V_1478 ] ) ;
V_1475 = F_78 ( V_30 -> V_5 [ V_1479 ] ) ;
V_1473 = F_34 ( V_30 -> V_5 [ V_1480 ] ) ;
V_1477 = F_152 ( V_30 -> V_5 [ V_1481 ] ) ;
if ( V_30 -> V_5 [ V_1482 ] )
V_1474 =
F_4 ( V_30 -> V_5 [ V_1482 ] ) ;
return F_321 ( V_7 , V_541 , V_1476 , V_1472 ,
V_1473 , V_1475 , V_1474 ,
V_1477 ,
F_23 ( V_30 -> V_5 [ V_686 ] ) ,
F_24 ( V_30 -> V_5 [ V_686 ] ) ) ;
}
static int F_322 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
enum V_1483 V_1484 ;
T_2 * V_1476 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_420 )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_1485 ] ||
! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_1484 = F_34 ( V_30 -> V_5 [ V_1485 ] ) ;
V_1476 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
return F_323 ( V_7 , V_541 , V_1476 , V_1484 ) ;
}
static int F_324 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
struct V_521 V_522 ;
struct V_31 * V_53 ;
void * V_283 ;
T_1 V_650 ;
V_22 V_1486 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_524 ] ||
! V_30 -> V_5 [ V_1487 ] )
return - V_16 ;
V_1486 = F_4 ( V_30 -> V_5 [ V_1487 ] ) ;
if ( ! V_7 -> V_351 -> V_404 ||
! ( V_7 -> V_18 . V_51 & V_403 ) )
return - V_542 ;
if ( V_1486 < V_1488 ||
V_1486 > V_7 -> V_18 . V_454 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_522 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1489 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_660;
}
V_35 = F_325 ( V_7 , V_17 , V_522 . V_55 ,
V_1486 , & V_650 ) ;
if ( V_35 )
goto V_660;
if ( F_104 ( V_53 , V_1490 , V_650 ,
V_589 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_660:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_326 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
T_1 V_650 ;
if ( ! V_30 -> V_5 [ V_1490 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1491 )
return - V_542 ;
V_650 = F_5 ( V_30 -> V_5 [ V_1490 ] ) ;
return F_327 ( V_7 , V_17 , V_650 ) ;
}
static V_22 F_328 ( struct V_239 * V_240 ,
T_2 * V_1217 , T_2 V_1492 )
{
T_2 V_159 ;
V_22 V_753 = 0 ;
for ( V_159 = 0 ; V_159 < V_1492 ; V_159 ++ ) {
int V_244 = ( V_1217 [ V_159 ] & 0x7f ) * 5 ;
int V_1493 ;
for ( V_1493 = 0 ; V_1493 < V_240 -> V_261 ; V_1493 ++ ) {
struct V_243 * V_1494 =
& V_240 -> V_262 [ V_1493 ] ;
if ( V_244 == V_1494 -> V_264 ) {
V_753 |= 1 << V_1493 ;
break;
}
}
if ( V_1493 == V_240 -> V_261 )
return 0 ;
}
return V_753 ;
}
static bool F_329 ( struct V_239 * V_240 ,
T_2 * V_1217 , T_2 V_1492 ,
T_2 V_248 [ V_1495 ] )
{
T_2 V_159 ;
memset ( V_248 , 0 , V_1495 ) ;
for ( V_159 = 0 ; V_159 < V_1492 ; V_159 ++ ) {
int V_1493 , V_1496 ;
V_1493 = V_1217 [ V_159 ] / 8 ;
V_1496 = F_159 ( V_1217 [ V_159 ] % 8 ) ;
if ( ( V_1493 < 0 ) || ( V_1493 >= V_1495 ) )
return false ;
if ( V_240 -> V_245 . V_248 . V_1497 [ V_1493 ] & V_1496 )
V_248 [ V_1493 ] |= V_1496 ;
else
return false ;
}
return true ;
}
static T_3 F_330 ( T_2 V_1498 )
{
T_3 V_1499 = 0 ;
switch ( V_1498 ) {
case V_1500 :
break;
case V_1501 :
V_1499 = 0x00FF ;
break;
case V_1502 :
V_1499 = 0x01FF ;
break;
case V_1503 :
V_1499 = 0x03FF ;
break;
default:
break;
}
return V_1499 ;
}
static void F_331 ( T_3 V_1498 ,
T_3 V_1504 [ V_1505 ] )
{
T_2 V_791 ;
for ( V_791 = 0 ; V_791 < V_1505 ; V_791 ++ ) {
V_1504 [ V_791 ] = F_330 ( V_1498 & 0x03 ) ;
V_1498 >>= 2 ;
}
}
static bool F_332 ( struct V_239 * V_240 ,
struct V_1506 * V_831 ,
T_3 V_248 [ V_1505 ] )
{
T_3 V_1507 = F_333 ( V_240 -> V_255 . V_258 . V_1507 ) ;
T_3 V_1508 [ V_1505 ] = {} ;
T_2 V_159 ;
if ( ! V_240 -> V_255 . V_256 )
return false ;
memset ( V_248 , 0 , sizeof( T_3 ) * V_1505 ) ;
F_331 ( V_1507 , V_1508 ) ;
for ( V_159 = 0 ; V_159 < V_1505 ; V_159 ++ ) {
if ( ( V_1508 [ V_159 ] & V_831 -> V_248 [ V_159 ] ) == V_831 -> V_248 [ V_159 ] )
V_248 [ V_159 ] = V_831 -> V_248 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_334 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1509 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1510 V_753 ;
int V_134 , V_159 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_4 * V_1511 ;
struct V_239 * V_240 ;
T_3 V_1512 ;
if ( ! V_7 -> V_351 -> V_406 )
return - V_542 ;
memset ( & V_753 , 0 , sizeof( V_753 ) ) ;
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ ) {
V_240 = V_7 -> V_18 . V_363 [ V_159 ] ;
if ( ! V_240 )
continue;
V_753 . V_1513 [ V_159 ] . V_1514 = ( 1 << V_240 -> V_261 ) - 1 ;
memcpy ( V_753 . V_1513 [ V_159 ] . V_1515 ,
V_240 -> V_245 . V_248 . V_1497 ,
sizeof( V_753 . V_1513 [ V_159 ] . V_1515 ) ) ;
if ( ! V_240 -> V_255 . V_256 )
continue;
V_1512 = F_333 ( V_240 -> V_255 . V_258 . V_1507 ) ;
F_331 ( V_1512 , V_753 . V_1513 [ V_159 ] . V_258 ) ;
}
if ( ! V_30 -> V_5 [ V_1516 ] )
goto V_602;
F_114 ( V_1517 > V_1495 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_289 V_290 = F_241 ( V_1511 ) ;
int V_35 ;
if ( V_290 < 0 || V_290 >= V_362 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_290 ] ;
if ( V_240 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1509 , F_23 ( V_1511 ) ,
F_24 ( V_1511 ) , V_1518 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1519 ] ) {
V_753 . V_1513 [ V_290 ] . V_1514 = F_328 (
V_240 ,
F_23 ( V_95 [ V_1519 ] ) ,
F_24 ( V_95 [ V_1519 ] ) ) ;
if ( ( V_753 . V_1513 [ V_290 ] . V_1514 == 0 ) &&
F_24 ( V_95 [ V_1519 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1520 ] ) {
if ( ! F_329 (
V_240 ,
F_23 ( V_95 [ V_1520 ] ) ,
F_24 ( V_95 [ V_1520 ] ) ,
V_753 . V_1513 [ V_290 ] . V_1515 ) )
return - V_16 ;
}
if ( V_95 [ V_1521 ] ) {
if ( ! F_332 (
V_240 ,
F_23 ( V_95 [ V_1521 ] ) ,
V_753 . V_1513 [ V_290 ] . V_258 ) )
return - V_16 ;
}
if ( V_95 [ V_1522 ] ) {
V_753 . V_1513 [ V_290 ] . V_1523 =
F_34 ( V_95 [ V_1522 ] ) ;
if ( V_753 . V_1513 [ V_290 ] . V_1523 > V_1524 )
return - V_16 ;
}
if ( V_753 . V_1513 [ V_290 ] . V_1514 == 0 ) {
if ( ! ( V_7 -> V_18 . V_363 [ V_290 ] -> V_245 . V_246 ||
V_7 -> V_18 . V_363 [ V_290 ] -> V_255 . V_256 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_1495 ; V_159 ++ )
if ( V_753 . V_1513 [ V_290 ] . V_1515 [ V_159 ] )
goto V_602;
for ( V_159 = 0 ; V_159 < V_1505 ; V_159 ++ )
if ( V_753 . V_1513 [ V_290 ] . V_258 [ V_159 ] )
goto V_602;
return - V_16 ;
}
}
V_602:
return F_335 ( V_7 , V_541 , NULL , & V_753 ) ;
}
static int F_336 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
T_3 V_1525 = V_277 | V_1526 ;
if ( ! V_30 -> V_5 [ V_1527 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_276 ] )
V_1525 = F_78 ( V_30 -> V_5 [ V_276 ] ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
case V_154 :
break;
default:
return - V_542 ;
}
if ( ! V_7 -> V_351 -> V_408 )
return - V_542 ;
return F_337 ( V_17 , V_30 -> V_506 , V_1525 ,
F_23 ( V_30 -> V_5 [ V_1527 ] ) ,
F_24 ( V_30 -> V_5 [ V_1527 ] ) ) ;
}
static int F_338 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
struct V_521 V_522 ;
int V_35 ;
void * V_283 = NULL ;
T_1 V_650 ;
struct V_31 * V_53 = NULL ;
struct V_1528 V_137 = {
. V_1529 =
V_30 -> V_5 [ V_1530 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1531 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_408 )
return - V_542 ;
switch ( V_17 -> V_141 ) {
case V_154 :
if ( ! V_30 -> V_5 [ V_524 ] )
return - V_16 ;
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
break;
default:
return - V_542 ;
}
if ( V_30 -> V_5 [ V_1487 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1532 = F_4 ( V_30 -> V_5 [ V_1487 ] ) ;
if ( V_137 . V_1532 < V_1488 ||
V_137 . V_1532 > V_7 -> V_18 . V_454 )
return - V_16 ;
}
V_137 . V_1533 = V_30 -> V_5 [ V_456 ] ;
if ( V_137 . V_1533 && ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1224 = F_152 ( V_30 -> V_5 [ V_1225 ] ) ;
V_522 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_524 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_522 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_522 . V_55 && V_137 . V_1533 )
return - V_16 ;
V_137 . V_1534 = F_23 ( V_30 -> V_5 [ V_1531 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1531 ] ) ;
if ( V_30 -> V_5 [ V_1535 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1535 ] ) ;
int V_159 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1536 = V_47 / sizeof( T_3 ) ;
V_137 . V_1537 =
F_23 ( V_30 -> V_5 [ V_1535 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1536 ; V_159 ++ ) {
if ( V_137 . V_1537 [ V_159 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1529 ) {
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1538 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_660;
}
}
V_137 . V_55 = V_522 . V_55 ;
V_35 = F_339 ( V_7 , V_17 , & V_137 , & V_650 ) ;
if ( V_35 )
goto V_660;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1490 , V_650 ,
V_589 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_660:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_340 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
T_1 V_650 ;
if ( ! V_30 -> V_5 [ V_1490 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_410 )
return - V_542 ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_144 :
case V_154 :
break;
default:
return - V_542 ;
}
V_650 = F_5 ( V_30 -> V_5 [ V_1490 ] ) ;
return F_341 ( V_7 , V_17 , V_650 ) ;
}
static int F_342 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 V_1539 ;
bool V_282 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1540 ] )
return - V_16 ;
V_1539 = F_4 ( V_30 -> V_5 [ V_1540 ] ) ;
if ( V_1539 != V_1541 && V_1539 != V_1542 )
return - V_16 ;
V_17 = V_541 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1543 )
return - V_542 ;
V_282 = ( V_1539 == V_1542 ) ? true : false ;
if ( V_282 == V_17 -> V_1544 )
return 0 ;
V_35 = F_343 ( V_7 , V_541 , V_282 , V_17 -> V_1545 ) ;
if ( ! V_35 )
V_17 -> V_1544 = V_282 ;
return V_35 ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
enum V_1546 V_1539 ;
struct V_1 * V_17 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_31 * V_53 ;
void * V_283 ;
int V_35 ;
V_17 = V_541 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1543 )
return - V_542 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1547 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_660;
}
if ( V_17 -> V_1544 )
V_1539 = V_1542 ;
else
V_1539 = V_1541 ;
if ( F_28 ( V_53 , V_1540 , V_1539 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_660:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_345 ( struct V_29 * V_30 ,
V_22 V_244 , V_22 V_1548 , V_22 V_1549 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
if ( V_244 > 100 || V_1549 > V_1550 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1551 )
return - V_542 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_542 ;
return F_346 ( V_7 , V_541 , V_244 , V_1548 , V_1549 ) ;
}
static int F_347 ( struct V_29 * V_30 ,
T_12 V_1552 , V_22 V_1553 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
if ( V_1552 > 0 )
return - V_16 ;
if ( V_1552 == 0 )
V_1553 = 0 ;
if ( ! V_7 -> V_351 -> V_1554 )
return - V_542 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_542 ;
return F_348 ( V_7 , V_541 , V_1552 , V_1553 ) ;
}
static int F_349 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1555 + 1 ] ;
struct V_4 * V_1556 ;
int V_35 ;
V_1556 = V_30 -> V_5 [ V_1557 ] ;
if ( ! V_1556 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1555 , V_1556 ,
V_1558 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1559 ] &&
V_5 [ V_1560 ] ) {
T_12 V_1552 = V_1105 ( V_5 [ V_1559 ] ) ;
V_22 V_1553 = F_4 ( V_5 [ V_1560 ] ) ;
return F_347 ( V_30 , V_1552 , V_1553 ) ;
}
if ( V_5 [ V_1561 ] &&
V_5 [ V_1562 ] &&
V_5 [ V_1563 ] ) {
V_22 V_244 = F_4 ( V_5 [ V_1561 ] ) ;
V_22 V_1548 = F_4 ( V_5 [ V_1562 ] ) ;
V_22 V_1549 = F_4 ( V_5 [ V_1563 ] ) ;
return F_345 ( V_30 , V_244 , V_1548 , V_1549 ) ;
}
return - V_16 ;
}
static int F_350 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1564 V_1108 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1108 . V_522 ) ;
if ( V_35 )
return V_35 ;
return F_351 ( V_7 , V_541 , & V_1108 ) ;
}
static int F_352 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
return F_353 ( V_7 , V_541 ) ;
}
static int F_354 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1039 V_1101 ;
struct V_1107 V_1108 ;
int V_35 ;
memcpy ( & V_1101 , & V_1043 , sizeof( V_1101 ) ) ;
memcpy ( & V_1108 , & V_1565 , sizeof( V_1108 ) ) ;
if ( V_30 -> V_5 [ V_1045 ] ) {
V_35 = F_209 ( V_30 , & V_1101 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_620 ] ||
! F_24 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
V_1108 . V_1566 = F_23 ( V_30 -> V_5 [ V_620 ] ) ;
V_1108 . V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
if ( V_30 -> V_5 [ V_1427 ] &&
! F_290 ( V_7 , V_1108 . V_1414 ,
F_4 ( V_30 -> V_5 [ V_1427 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_712 ] ) {
V_1108 . V_543 =
F_4 ( V_30 -> V_5 [ V_712 ] ) ;
if ( V_1108 . V_543 < 10 ||
V_1108 . V_543 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_713 ] ) {
V_1108 . V_715 =
F_4 ( V_30 -> V_5 [ V_713 ] ) ;
if ( V_1108 . V_715 < 1 || V_1108 . V_715 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1110 ] ) {
V_35 = F_211 ( V_30 , & V_1108 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1108 . V_1130 )
V_1101 . V_1061 = false ;
if ( V_30 -> V_5 [ V_524 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1108 . V_522 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1108 . V_522 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_1023 ] ) {
T_2 * V_1217 = F_23 ( V_30 -> V_5 [ V_1023 ] ) ;
int V_1426 =
F_24 ( V_30 -> V_5 [ V_1023 ] ) ;
struct V_239 * V_240 ;
if ( ! V_1108 . V_522 . V_55 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_1108 . V_522 . V_55 -> V_290 ] ;
V_35 = F_242 ( V_240 , V_1217 , V_1426 ,
& V_1108 . V_1024 ) ;
if ( V_35 )
return V_35 ;
}
return F_355 ( V_7 , V_541 , & V_1108 , & V_1101 ) ;
}
static int F_356 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
return F_357 ( V_7 , V_541 ) ;
}
static int F_358 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1567 * V_189 = V_7 -> V_18 . V_1568 ;
struct V_4 * V_1569 , * V_1570 ;
int V_159 , V_1571 ;
if ( ! V_189 -> V_219 )
return 0 ;
V_1569 = F_47 ( V_53 , V_228 ) ;
if ( ! V_1569 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_189 -> V_219 ; V_159 ++ ) {
V_1570 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1570 )
return - V_91 ;
V_1571 = V_189 -> V_1572 [ V_159 ] . V_1573 ;
if ( F_51 ( V_53 , V_1574 , F_250 ( V_1571 , 8 ) ,
V_189 -> V_1572 [ V_159 ] . V_753 ) ||
F_51 ( V_53 , V_1575 , V_1571 ,
V_189 -> V_1572 [ V_159 ] . V_1576 ) ||
F_28 ( V_53 , V_1577 ,
V_189 -> V_1572 [ V_159 ] . V_1578 ) )
return - V_91 ;
F_48 ( V_53 , V_1570 ) ;
}
F_48 ( V_53 , V_1569 ) ;
return 0 ;
}
static int F_359 ( struct V_31 * V_53 ,
struct V_1579 * V_188 )
{
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_360 ( V_53 , V_1580 , V_188 -> V_1581 ) ||
F_360 ( V_53 , V_1582 , V_188 -> V_978 ) ||
F_51 ( V_53 , V_1583 , V_590 , V_188 -> V_1584 ) ||
F_55 ( V_53 , V_1585 , V_188 -> V_1586 ) ||
F_55 ( V_53 , V_1587 , V_188 -> V_1588 ) ||
F_51 ( V_53 , V_192 ,
V_188 -> V_1589 , V_188 -> V_1590 ) ||
F_28 ( V_53 , V_197 ,
V_188 -> V_1591 ) ||
F_51 ( V_53 , V_199 ,
V_188 -> V_1592 , V_188 -> V_1593 ) ||
F_51 ( V_53 , V_1594 ,
F_250 ( V_188 -> V_1592 , 8 ) , V_188 -> V_1595 ) )
return - V_91 ;
if ( V_188 -> V_1596 . V_47 &&
F_51 ( V_53 , V_194 ,
sizeof( V_188 -> V_1596 ) , & V_188 -> V_1596 ) )
return - V_91 ;
if ( V_188 -> V_1597 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_188 -> V_1597 ) + V_188 -> V_1598 ,
& V_188 -> V_1597 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_361 ( struct V_31 * V_53 ,
struct V_1230 * V_1394 )
{
struct V_4 * V_1599 , * V_1183 , * V_1600 , * V_1601 , * V_1234 , * V_1602 ;
int V_159 ;
if ( ! V_1394 )
return 0 ;
V_1599 = F_47 ( V_53 , V_230 ) ;
if ( ! V_1599 )
return - V_91 ;
if ( V_1394 -> V_1252 == 1 &&
F_28 ( V_53 , V_1233 ,
V_1394 -> V_1234 [ 0 ] . V_1232 * 1000 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1259 , V_1394 -> V_1260 ) )
return - V_91 ;
V_1183 = F_47 ( V_53 , V_1213 ) ;
if ( ! V_1183 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1394 -> V_366 ; V_159 ++ )
F_28 ( V_53 , V_159 , V_1394 -> V_367 [ V_159 ] -> V_60 ) ;
F_48 ( V_53 , V_1183 ) ;
if ( V_1394 -> V_1242 ) {
V_1600 = F_47 ( V_53 , V_1246 ) ;
for ( V_159 = 0 ; V_159 < V_1394 -> V_1242 ; V_159 ++ ) {
V_1601 = F_47 ( V_53 , V_159 ) ;
F_51 ( V_53 , V_1249 ,
V_1394 -> V_1251 [ V_159 ] . V_597 . V_595 ,
V_1394 -> V_1251 [ V_159 ] . V_597 . V_597 ) ;
F_48 ( V_53 , V_1601 ) ;
}
F_48 ( V_53 , V_1600 ) ;
}
V_1234 = F_47 ( V_53 , V_1231 ) ;
if ( ! V_1234 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1394 -> V_1252 ; V_159 ++ ) {
V_1602 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1602 ||
F_28 ( V_53 , V_1239 ,
V_1394 -> V_1234 [ V_159 ] . V_1232 ) ||
( V_1394 -> V_1234 [ V_159 ] . V_1241 &&
F_28 ( V_53 , V_1240 ,
V_1394 -> V_1234 [ V_159 ] . V_1241 ) ) )
return - V_91 ;
F_48 ( V_53 , V_1602 ) ;
}
F_48 ( V_53 , V_1234 ) ;
F_48 ( V_53 , V_1599 ) ;
return 0 ;
}
static int F_362 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1603 = V_603 ;
if ( ! V_7 -> V_18 . V_189 )
return - V_542 ;
if ( V_7 -> V_18 . V_1568 && V_7 -> V_18 . V_1568 -> V_188 ) {
V_1603 += V_7 -> V_18 . V_1568 -> V_188 -> V_1598 +
V_7 -> V_18 . V_1568 -> V_188 -> V_1589 +
V_7 -> V_18 . V_1568 -> V_188 -> V_1592 +
V_7 -> V_18 . V_1568 -> V_188 -> V_1592 / 8 ;
}
V_53 = F_74 ( V_1603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1604 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_18 . V_1568 ) {
struct V_4 * V_201 ;
V_201 = F_47 ( V_53 , V_1605 ) ;
if ( ! V_201 )
goto V_61;
if ( ( V_7 -> V_18 . V_1568 -> V_1606 &&
F_29 ( V_53 , V_204 ) ) ||
( V_7 -> V_18 . V_1568 -> V_451 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1568 -> V_1607 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1568 -> V_1608 &&
F_29 ( V_53 , V_212 ) ) ||
( V_7 -> V_18 . V_1568 -> V_1609 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1568 -> V_1610 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1568 -> V_1611 &&
F_29 ( V_53 , V_218 ) ) )
goto V_61;
if ( F_358 ( V_53 , V_7 ) )
goto V_61;
if ( F_359 ( V_53 ,
V_7 -> V_18 . V_1568 -> V_188 ) )
goto V_61;
if ( F_361 (
V_53 ,
V_7 -> V_18 . V_1568 -> V_1612 ) )
goto V_61;
F_48 ( V_53 , V_201 ) ;
}
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_363 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1567 * V_1613 )
{
struct V_4 * V_95 [ V_1614 ] ;
struct V_1579 * V_1101 ;
struct V_1615 * V_195 = NULL ;
struct V_1616 * V_50 = NULL ;
V_22 V_1603 ;
V_22 V_1617 , V_1618 , V_1598 = 0 , V_1619 ;
int V_35 , V_1620 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1621 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1622 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1580 ] ||
! V_95 [ V_1582 ] ||
! V_95 [ V_1583 ] ||
! V_95 [ V_1587 ] ||
! V_95 [ V_192 ] ||
! V_95 [ V_197 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_1594 ] )
return - V_16 ;
V_1617 = F_24 ( V_95 [ V_192 ] ) ;
if ( V_1617 > V_7 -> V_18 . V_189 -> V_188 -> V_193 )
return - V_16 ;
if ( F_4 ( V_95 [ V_197 ] ) >
V_7 -> V_18 . V_189 -> V_188 -> V_198 ||
F_4 ( V_95 [ V_197 ] ) == 0 )
return - V_16 ;
V_1618 = F_24 ( V_95 [ V_199 ] ) ;
if ( V_1618 > V_7 -> V_18 . V_189 -> V_188 -> V_200 )
return - V_16 ;
V_1619 = F_24 ( V_95 [ V_1594 ] ) ;
if ( V_1619 != F_250 ( V_1618 , 8 ) )
return - V_16 ;
if ( V_95 [ V_196 ] ) {
V_22 V_1623 = F_24 ( V_95 [ V_196 ] ) ;
V_195 = F_23 ( V_95 [ V_196 ] ) ;
V_1598 = V_1623 - sizeof( * V_195 ) ;
if ( ! V_195 -> V_47 || V_1598 % V_195 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_195 )
return - V_16 ;
if ( V_195 -> V_47 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1624 )
return - V_16 ;
if ( V_195 -> V_47 < V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1625 )
return - V_16 ;
if ( V_1598 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1626 )
return - V_16 ;
if ( V_195 -> V_1284 + V_195 -> V_47 > V_1617 )
return - V_16 ;
}
if ( V_95 [ V_194 ] ) {
V_50 = F_23 ( V_95 [ V_194 ] ) ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1284 > V_1617 )
return - V_16 ;
}
V_1603 = sizeof( * V_1101 ) ;
V_1603 += V_1617 ;
V_1603 += V_1618 + V_1619 ;
V_1603 += V_1598 ;
V_1101 = F_38 ( V_1603 , V_135 ) ;
if ( ! V_1101 )
return - V_136 ;
V_1101 -> V_1581 = F_364 ( V_95 [ V_1580 ] ) ;
V_1101 -> V_978 = F_364 ( V_95 [ V_1582 ] ) ;
memcpy ( V_1101 -> V_1584 , F_23 ( V_95 [ V_1583 ] ) ,
V_590 ) ;
if ( V_95 [ V_1585 ] )
V_1620 = F_78 ( V_95 [ V_1585 ] ) ;
else
V_1620 = 0 ;
#ifdef F_365
V_35 = F_366 ( F_7 ( & V_7 -> V_18 ) , V_1627 , V_1628 ,
V_1629 , & V_1101 -> V_1630 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1101 ) ;
return V_35 ;
}
if ( F_367 ( V_1101 -> V_1630 -> V_44 , V_1620 ) ) {
F_368 ( V_1101 -> V_1630 ) ;
F_41 ( V_1101 ) ;
return - V_1631 ;
}
V_1101 -> V_1586 = F_369 ( V_1101 -> V_1630 -> V_44 ) -> V_1632 ;
#else
if ( ! V_1620 ) {
F_41 ( V_1101 ) ;
return - V_16 ;
}
V_1101 -> V_1586 = V_1620 ;
#endif
V_1101 -> V_1588 = F_78 ( V_95 [ V_1587 ] ) ;
V_1101 -> V_1589 = V_1617 ;
V_1101 -> V_1590 = ( T_2 * ) V_1101 + sizeof( * V_1101 ) + V_1598 ;
memcpy ( ( void * ) V_1101 -> V_1590 ,
F_23 ( V_95 [ V_192 ] ) ,
V_1617 ) ;
if ( V_50 )
V_1101 -> V_1596 = * V_50 ;
V_1101 -> V_1591 = F_4 ( V_95 [ V_197 ] ) ;
V_1101 -> V_1592 = V_1618 ;
V_1101 -> V_1593 = ( T_2 * ) V_1101 + sizeof( * V_1101 ) + V_1598 + V_1617 ;
memcpy ( ( void * ) V_1101 -> V_1593 ,
F_23 ( V_95 [ V_199 ] ) ,
V_1618 ) ;
V_1101 -> V_1595 = ( T_2 * ) V_1101 + sizeof( * V_1101 ) + V_1598 +
V_1617 + V_1618 ;
memcpy ( ( void * ) V_1101 -> V_1595 ,
F_23 ( V_95 [ V_1594 ] ) ,
V_1619 ) ;
if ( V_195 ) {
V_1101 -> V_1598 = V_1598 ;
memcpy ( & V_1101 -> V_1597 , V_195 , sizeof( * V_195 ) + V_1598 ) ;
}
V_1613 -> V_188 = V_1101 ;
return 0 ;
}
static int F_370 ( struct V_6 * V_7 ,
const struct V_1633 * V_189 ,
struct V_4 * V_45 ,
struct V_1567 * V_1613 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_38 ( V_1634 * sizeof( * V_95 ) , V_135 ) ;
if ( ! V_95 )
return - V_136 ;
if ( ! ( V_189 -> V_51 & V_229 ) ) {
V_35 = - V_542 ;
goto V_602;
}
V_35 = F_96 ( V_95 , V_1271 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_602;
V_1613 -> V_1612 = F_251 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_253 ( V_1613 -> V_1612 ) ;
if ( V_35 )
V_1613 -> V_1612 = NULL ;
V_602:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_371 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_4 * V_95 [ V_1635 ] ;
struct V_1567 V_1636 = {} ;
struct V_1567 * V_1637 ;
const struct V_1633 * V_189 = V_7 -> V_18 . V_189 ;
int V_35 , V_159 ;
bool V_1638 = V_7 -> V_18 . V_1568 ;
bool V_1639 = false ;
if ( ! V_189 )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_1605 ] ) {
F_372 ( V_7 ) ;
V_7 -> V_18 . V_1568 = NULL ;
goto V_1640;
}
V_35 = F_96 ( V_95 , V_1641 ,
F_23 ( V_30 -> V_5 [ V_1605 ] ) ,
F_24 ( V_30 -> V_5 [ V_1605 ] ) ,
V_1642 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_204 ] ) {
if ( ! ( V_189 -> V_51 & V_203 ) )
return - V_16 ;
V_1636 . V_1606 = true ;
}
if ( V_95 [ V_206 ] ) {
if ( ! ( V_189 -> V_51 & V_205 ) )
return - V_16 ;
V_1636 . V_451 = true ;
V_1639 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_189 -> V_51 & V_207 ) )
return - V_16 ;
V_1636 . V_1607 = true ;
V_1639 = true ;
}
if ( V_95 [ V_210 ] )
return - V_16 ;
if ( V_95 [ V_212 ] ) {
if ( ! ( V_189 -> V_51 & V_211 ) )
return - V_16 ;
V_1636 . V_1608 = true ;
V_1639 = true ;
}
if ( V_95 [ V_214 ] ) {
if ( ! ( V_189 -> V_51 & V_213 ) )
return - V_16 ;
V_1636 . V_1609 = true ;
V_1639 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_189 -> V_51 & V_215 ) )
return - V_16 ;
V_1636 . V_1610 = true ;
V_1639 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_189 -> V_51 & V_217 ) )
return - V_16 ;
V_1636 . V_1611 = true ;
V_1639 = true ;
}
if ( V_95 [ V_228 ] ) {
struct V_4 * V_221 ;
int V_219 = 0 ;
int V_134 , V_1571 , V_1643 , V_1578 ;
struct V_4 * V_1644 [ V_1645 ] ;
V_1639 = true ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_189 -> V_219 )
return - V_16 ;
V_1636 . V_1572 = F_373 ( V_219 ,
sizeof( V_1636 . V_1572 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1636 . V_1572 )
return - V_136 ;
V_1636 . V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1646 ;
F_96 ( V_1644 , V_1647 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1644 [ V_1574 ] ||
! V_1644 [ V_1575 ] )
goto error;
V_1571 = F_24 ( V_1644 [ V_1575 ] ) ;
V_1643 = F_250 ( V_1571 , 8 ) ;
if ( F_24 ( V_1644 [ V_1574 ] ) != V_1643 )
goto error;
if ( V_1571 > V_189 -> V_226 ||
V_1571 < V_189 -> V_224 )
goto error;
if ( ! V_1644 [ V_1577 ] )
V_1578 = 0 ;
else
V_1578 = F_4 (
V_1644 [ V_1577 ] ) ;
if ( V_1578 > V_189 -> V_227 )
goto error;
V_1636 . V_1572 [ V_159 ] . V_1578 = V_1578 ;
V_1646 = F_374 ( V_1643 + V_1571 , V_135 ) ;
if ( ! V_1646 ) {
V_35 = - V_136 ;
goto error;
}
V_1636 . V_1572 [ V_159 ] . V_753 = V_1646 ;
memcpy ( V_1646 , F_23 ( V_1644 [ V_1574 ] ) ,
V_1643 ) ;
V_1646 += V_1643 ;
V_1636 . V_1572 [ V_159 ] . V_1576 = V_1646 ;
V_1636 . V_1572 [ V_159 ] . V_1573 = V_1571 ;
memcpy ( V_1646 ,
F_23 ( V_1644 [ V_1575 ] ) ,
V_1571 ) ;
V_159 ++ ;
}
}
if ( V_95 [ V_191 ] ) {
V_1639 = true ;
V_35 = F_363 (
V_7 , V_95 [ V_191 ] ,
& V_1636 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_230 ] ) {
V_1639 = true ;
V_35 = F_370 (
V_7 , V_189 , V_95 [ V_230 ] ,
& V_1636 ) ;
if ( V_35 )
goto error;
}
if ( V_1636 . V_1606 && V_1639 ) {
V_35 = - V_16 ;
goto error;
}
V_1637 = F_375 ( & V_1636 , sizeof( V_1636 ) , V_135 ) ;
if ( ! V_1637 ) {
V_35 = - V_136 ;
goto error;
}
F_372 ( V_7 ) ;
V_7 -> V_18 . V_1568 = V_1637 ;
V_1640:
if ( V_7 -> V_351 -> V_1640 &&
V_1638 != ! ! V_7 -> V_18 . V_1568 )
F_376 ( V_7 , V_7 -> V_18 . V_1568 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1636 . V_219 ; V_159 ++ )
F_41 ( V_1636 . V_1572 [ V_159 ] . V_753 ) ;
F_41 ( V_1636 . V_1572 ) ;
if ( V_1636 . V_188 && V_1636 . V_188 -> V_1630 )
F_368 ( V_1636 . V_188 -> V_1630 ) ;
F_41 ( V_1636 . V_188 ) ;
F_41 ( V_1636 . V_1612 ) ;
return V_35 ;
}
static int F_377 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1569 , * V_1570 , * V_1648 , * V_1649 ;
int V_159 , V_161 , V_1571 ;
struct V_1650 * V_233 ;
if ( ! V_7 -> V_234 -> V_236 )
return 0 ;
V_1649 = F_47 ( V_53 , V_238 ) ;
if ( ! V_1649 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_234 -> V_236 ; V_159 ++ ) {
V_1648 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1648 )
return - V_91 ;
V_233 = & V_7 -> V_234 -> V_1651 [ V_159 ] ;
if ( F_28 ( V_53 , V_1652 ,
V_233 -> V_1260 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1653 ,
V_233 -> V_1654 ) )
return - V_91 ;
V_1569 = F_47 ( V_53 ,
V_1655 ) ;
if ( ! V_1569 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ ) {
V_1570 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1570 )
return - V_91 ;
V_1571 = V_233 -> V_1572 [ V_161 ] . V_1573 ;
if ( F_51 ( V_53 , V_1574 ,
F_250 ( V_1571 , 8 ) ,
V_233 -> V_1572 [ V_161 ] . V_753 ) ||
F_51 ( V_53 , V_1575 , V_1571 ,
V_233 -> V_1572 [ V_161 ] . V_1576 ) ||
F_28 ( V_53 , V_1577 ,
V_233 -> V_1572 [ V_161 ] . V_1578 ) )
return - V_91 ;
F_48 ( V_53 , V_1570 ) ;
}
F_48 ( V_53 , V_1569 ) ;
F_48 ( V_53 , V_1648 ) ;
}
F_48 ( V_53 , V_1649 ) ;
return 0 ;
}
static int F_378 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
if ( ! V_7 -> V_18 . V_234 )
return - V_542 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1656 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_234 && F_377 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_379 ( struct V_6 * V_7 )
{
struct V_1657 * V_234 = V_7 -> V_234 ;
int V_159 , V_161 ;
struct V_1650 * V_233 ;
if ( ! V_234 )
return;
for ( V_159 = 0 ; V_159 < V_234 -> V_236 ; V_159 ++ ) {
V_233 = & V_234 -> V_1651 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ )
F_41 ( V_233 -> V_1572 [ V_161 ] . V_753 ) ;
F_41 ( V_233 -> V_1572 ) ;
}
F_41 ( V_234 -> V_1651 ) ;
F_41 ( V_234 ) ;
V_7 -> V_234 = NULL ;
}
static int F_380 ( struct V_6 * V_7 ,
struct V_4 * V_233 ,
struct V_1650 * V_1658 )
{
int V_35 , V_159 ;
const struct V_1659 * V_234 = V_7 -> V_18 . V_234 ;
struct V_4 * V_95 [ V_1660 ] , * V_221 ;
int V_134 , V_1571 , V_1643 , V_1578 , V_219 = 0 ;
struct V_4 * V_1644 [ V_1645 ] ;
V_35 = F_96 ( V_95 , V_1661 , F_23 ( V_233 ) ,
F_24 ( V_233 ) , V_1662 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1652 ] )
V_1658 -> V_1260 =
F_4 ( V_95 [ V_1652 ] ) ;
if ( V_1658 -> V_1260 > V_234 -> V_237 )
return - V_16 ;
if ( V_95 [ V_1653 ] )
V_1658 -> V_1654 =
F_4 ( V_95 [ V_1653 ] ) ;
if ( V_1658 -> V_1654 != V_1663 &&
V_1658 -> V_1654 != V_1664 )
return - V_16 ;
if ( ! V_95 [ V_1655 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_234 -> V_219 )
return - V_16 ;
V_1658 -> V_1572 = F_373 ( V_219 , sizeof( V_1658 -> V_1572 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1658 -> V_1572 )
return - V_136 ;
V_1658 -> V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1646 ;
F_96 ( V_1644 , V_1647 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
if ( ! V_1644 [ V_1574 ] ||
! V_1644 [ V_1575 ] )
return - V_16 ;
V_1571 = F_24 ( V_1644 [ V_1575 ] ) ;
V_1643 = F_250 ( V_1571 , 8 ) ;
if ( F_24 ( V_1644 [ V_1574 ] ) != V_1643 )
return - V_16 ;
if ( V_1571 > V_234 -> V_226 ||
V_1571 < V_234 -> V_224 )
return - V_16 ;
if ( ! V_1644 [ V_1577 ] )
V_1578 = 0 ;
else
V_1578 = F_4 ( V_1644 [ V_1577 ] ) ;
if ( V_1578 > V_234 -> V_227 )
return - V_16 ;
V_1658 -> V_1572 [ V_159 ] . V_1578 = V_1578 ;
V_1646 = F_374 ( V_1643 + V_1571 , V_135 ) ;
if ( ! V_1646 )
return - V_136 ;
V_1658 -> V_1572 [ V_159 ] . V_753 = V_1646 ;
memcpy ( V_1646 , F_23 ( V_1644 [ V_1574 ] ) ,
V_1643 ) ;
V_1646 += V_1643 ;
V_1658 -> V_1572 [ V_159 ] . V_1576 = V_1646 ;
V_1658 -> V_1572 [ V_159 ] . V_1573 = V_1571 ;
memcpy ( V_1646 , F_23 ( V_1644 [ V_1575 ] ) ,
V_1571 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_381 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
const struct V_1659 * V_234 = V_7 -> V_18 . V_234 ;
struct V_1657 V_1665 = {} ;
struct V_1657 * V_1666 ;
int V_35 , V_1667 , V_236 = 0 , V_159 , V_161 ;
struct V_4 * V_233 ;
struct V_1650 * V_1668 ;
if ( ! V_7 -> V_18 . V_234 || ! V_7 -> V_351 -> V_1669 )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_238 ] ) {
F_379 ( V_7 ) ;
F_382 ( V_7 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_236 ++ ;
if ( V_236 > V_234 -> V_236 )
return - V_16 ;
V_1665 . V_1651 = F_373 ( V_236 , sizeof( V_1665 . V_1651 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1665 . V_1651 )
return - V_136 ;
V_1665 . V_236 = V_236 ;
V_159 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_380 ( V_7 , V_233 ,
& V_1665 . V_1651 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = F_382 ( V_7 , & V_1665 ) ;
if ( V_35 )
goto error;
V_1666 = F_375 ( & V_1665 , sizeof( V_1665 ) , V_135 ) ;
if ( ! V_1666 ) {
V_35 = - V_136 ;
goto error;
}
F_379 ( V_7 ) ;
V_7 -> V_234 = V_1666 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1665 . V_236 ; V_159 ++ ) {
V_1668 = & V_1665 . V_1651 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1668 -> V_219 ; V_161 ++ )
F_41 ( V_1668 -> V_1572 [ V_161 ] . V_753 ) ;
F_41 ( V_1668 -> V_1572 ) ;
}
F_41 ( V_1665 . V_1651 ) ;
return V_35 ;
}
static int F_383 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_4 * V_95 [ V_1670 ] ;
struct V_1671 V_1672 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1673 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1674 ,
F_23 ( V_30 -> V_5 [ V_1673 ] ) ,
F_24 ( V_30 -> V_5 [ V_1673 ] ) ,
V_1675 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1676 ] ) != V_1677 )
return - V_1678 ;
if ( F_24 ( V_95 [ V_1679 ] ) != V_1680 )
return - V_1678 ;
if ( F_24 ( V_95 [ V_1681 ] ) != V_1682 )
return - V_1678 ;
V_1672 . V_1683 = F_23 ( V_95 [ V_1679 ] ) ;
V_1672 . V_1684 = F_23 ( V_95 [ V_1681 ] ) ;
V_1672 . V_1685 = F_23 ( V_95 [ V_1676 ] ) ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1274 ;
goto V_602;
}
if ( ! V_7 -> V_351 -> V_1686 ) {
V_35 = - V_542 ;
goto V_602;
}
V_35 = F_384 ( V_7 , V_541 , & V_1672 ) ;
V_602:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_385 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1687 )
return - V_546 ;
V_17 -> V_1687 = V_30 -> V_506 ;
return 0 ;
}
static int F_386 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_31 * V_53 ;
void * V_283 ;
const T_2 * V_680 ;
T_1 V_650 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_425 )
return - V_542 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1688 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_660;
}
V_680 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_35 = F_387 ( V_7 , V_541 , V_680 , & V_650 ) ;
if ( V_35 )
goto V_660;
if ( F_104 ( V_53 , V_1490 , V_650 ,
V_589 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_660:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_388 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1689 * V_1690 , * V_1691 ;
int V_1692 ;
if ( ! ( V_7 -> V_18 . V_51 & V_429 ) )
return - V_542 ;
V_1691 = F_38 ( sizeof( * V_1691 ) , V_135 ) ;
if ( ! V_1691 )
return - V_136 ;
F_272 ( & V_7 -> V_1693 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1690 -> V_1694 == V_30 -> V_506 ) {
V_1692 = - V_711 ;
goto V_889;
}
}
V_1691 -> V_1694 = V_30 -> V_506 ;
F_389 ( & V_1691 -> V_641 , & V_7 -> V_1695 ) ;
F_274 ( & V_7 -> V_1693 ) ;
return 0 ;
V_889:
F_274 ( & V_7 -> V_1693 ) ;
F_41 ( V_1691 ) ;
return V_1692 ;
}
static int F_390 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_431 )
return - V_542 ;
if ( V_17 -> V_141 != V_154 )
return - V_542 ;
if ( V_17 -> V_1696 )
return 0 ;
if ( F_391 ( V_7 -> V_1697 ) )
return - V_1698 ;
V_35 = F_392 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1696 = true ;
V_7 -> V_1699 ++ ;
return 0 ;
}
static int F_393 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_542 ;
if ( ! V_7 -> V_351 -> V_1700 )
return - V_542 ;
F_394 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_395 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_283 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_506 , V_30 -> V_507 , 0 ,
V_1701 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_1702 ,
V_1703 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_300 ( V_53 ) ;
return - V_91 ;
}
static int F_396 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1704 V_1705 ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1706 )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_1707 ] ||
! F_22 ( V_30 -> V_5 [ V_686 ] ) )
return - V_16 ;
memset ( & V_1705 , 0 , sizeof( V_1705 ) ) ;
V_1705 . V_1708 = F_78 ( V_30 -> V_5 [ V_1707 ] ) ;
V_1705 . V_1126 = F_23 ( V_30 -> V_5 [ V_686 ] ) ;
V_1705 . V_1127 = F_24 ( V_30 -> V_5 [ V_686 ] ) ;
return F_397 ( V_7 , V_541 , & V_1705 ) ;
}
static int F_398 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
enum V_1709 V_1378 = V_1710 ;
T_3 V_1486 ;
int V_498 ;
if ( ! V_7 -> V_351 -> V_437 )
return - V_542 ;
if ( F_59 ( ! V_7 -> V_351 -> V_439 ) )
return - V_16 ;
if ( V_7 -> V_1711 )
return - V_546 ;
if ( V_30 -> V_5 [ V_1712 ] )
V_1378 = F_78 ( V_30 -> V_5 [ V_1712 ] ) ;
if ( V_1378 >= V_1713 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1714 ] )
return - V_16 ;
V_1486 =
F_78 ( V_30 -> V_5 [ V_1714 ] ) ;
if ( V_1486 > V_1715 )
return - V_1678 ;
V_498 = F_399 ( V_7 , V_17 , V_1378 , V_1486 ) ;
if ( ! V_498 )
V_7 -> V_1711 = V_30 -> V_506 ;
return V_498 ;
}
static int F_400 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_439 )
return - V_542 ;
if ( V_7 -> V_1711 ) {
V_7 -> V_1711 = 0 ;
F_401 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_402 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_159 , V_35 ;
V_22 V_1716 , V_1438 ;
if ( ! V_7 -> V_18 . V_484 )
return - V_542 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1435 ] ||
! V_30 -> V_5 [ V_1437 ] )
return - V_16 ;
V_1716 = F_4 ( V_30 -> V_5 [ V_1435 ] ) ;
V_1438 = F_4 ( V_30 -> V_5 [ V_1437 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1717 * V_1718 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1718 = & V_7 -> V_18 . V_484 [ V_159 ] ;
if ( V_1718 -> V_30 . V_1436 != V_1716 || V_1718 -> V_30 . V_1438 != V_1438 )
continue;
if ( V_1718 -> V_51 & ( V_1719 |
V_1720 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1718 -> V_51 & V_1720 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1718 -> V_51 & V_1721 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_556 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1696 )
return - V_556 ;
}
if ( ! V_1718 -> V_1722 )
return - V_542 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_483 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_483 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_483 ] ) ;
}
V_7 -> V_1447 = V_30 ;
V_35 = V_7 -> V_18 . V_484 [ V_159 ] . V_1722 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1447 = NULL ;
return V_35 ;
}
return - V_542 ;
}
static int F_403 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
V_22 V_1716 , V_1438 ;
unsigned int V_159 ;
int V_1723 = - 1 ;
int V_35 ;
void * V_138 = NULL ;
unsigned int V_1449 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
struct V_18 * V_18 = F_19 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 ) {
V_35 = - V_23 ;
goto V_43;
}
* V_7 = F_11 ( V_18 ) ;
* V_17 = NULL ;
if ( V_34 -> args [ 1 ] ) {
F_6 (tmp, &wiphy->wdev_list, list) {
if ( V_24 -> V_21 == V_34 -> args [ 1 ] - 1 ) {
* V_17 = V_24 ;
break;
}
}
}
return 0 ;
}
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_43;
if ( ! V_38 . V_40 [ V_1435 ] ||
! V_38 . V_40 [ V_1437 ] ) {
V_35 = - V_16 ;
goto V_43;
}
* V_17 = F_1 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( * V_17 ) )
* V_17 = NULL ;
* V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( * V_7 ) ) {
V_35 = F_18 ( * V_7 ) ;
goto V_43;
}
V_1716 = F_4 ( V_38 . V_40 [ V_1435 ] ) ;
V_1438 = F_4 ( V_38 . V_40 [ V_1437 ] ) ;
for ( V_159 = 0 ; V_159 < ( * V_7 ) -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1717 * V_1718 ;
V_1718 = & ( * V_7 ) -> V_18 . V_484 [ V_159 ] ;
if ( V_1718 -> V_30 . V_1436 != V_1716 || V_1718 -> V_30 . V_1438 != V_1438 )
continue;
if ( ! V_1718 -> V_1724 ) {
V_35 = - V_542 ;
goto V_43;
}
V_1723 = V_159 ;
break;
}
if ( V_1723 < 0 ) {
V_35 = - V_542 ;
goto V_43;
}
if ( V_38 . V_40 [ V_483 ] ) {
V_138 = F_23 ( V_38 . V_40 [ V_483 ] ) ;
V_1449 = F_24 ( V_38 . V_40 [ V_483 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1723 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_138 ;
V_34 -> args [ 4 ] = V_1449 ;
return 0 ;
V_43:
F_20 () ;
return V_35 ;
}
static int F_404 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
unsigned int V_1723 ;
const struct V_1717 * V_1718 ;
void * V_138 ;
int V_1449 ;
int V_35 ;
struct V_4 * V_1725 ;
V_35 = F_403 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
V_1723 = V_34 -> args [ 2 ] ;
V_138 = ( void * ) V_34 -> args [ 3 ] ;
V_1449 = V_34 -> args [ 4 ] ;
V_1718 = & V_7 -> V_18 . V_484 [ V_1723 ] ;
if ( V_1718 -> V_51 & ( V_1719 |
V_1720 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1718 -> V_51 & V_1720 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1718 -> V_51 & V_1721 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_556 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1696 )
return - V_556 ;
}
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_502 , V_503 ,
V_1441 ) ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ,
V_589 ) ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1725 = F_47 ( V_32 , V_483 ) ;
if ( ! V_1725 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = V_1718 -> V_1724 ( & V_7 -> V_18 , V_17 , V_32 , V_138 , V_1449 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_48 ( V_32 , V_1725 ) ;
if ( V_35 == - V_91 || V_35 == - V_658 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_602;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_602:
F_20 () ;
return V_35 ;
}
struct V_31 * F_405 ( struct V_18 * V_18 ,
enum V_280 V_52 ,
enum V_768 V_45 ,
int V_1433 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1447 ) )
return NULL ;
return F_299 ( V_7 , NULL , V_1433 ,
V_7 -> V_1447 -> V_506 ,
V_7 -> V_1447 -> V_507 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_406 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1447 ) ) {
F_300 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
return F_76 ( V_32 , V_7 -> V_1447 ) ;
}
static int F_407 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_1726 * V_1727 = NULL ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
T_2 * V_46 , V_47 , V_1728 , V_1729 , V_1730 ;
int V_498 ;
if ( ! V_7 -> V_351 -> V_444 )
return - V_542 ;
if ( V_30 -> V_5 [ V_1731 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1731 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1731 ] ) ;
if ( V_47 % 2 || V_47 < V_1732 ||
V_47 > V_1733 )
return - V_16 ;
V_1727 = F_38 ( sizeof( struct V_1726 ) , V_135 ) ;
if ( ! V_1727 )
return - V_136 ;
V_1728 = ( V_47 - V_1732 ) >> 1 ;
if ( V_1728 ) {
V_1729 = V_1728 *
sizeof( struct V_1734 ) ;
memcpy ( V_1727 -> V_1735 , V_46 , V_1729 ) ;
V_1727 -> V_1728 = V_1728 ;
for ( V_1730 = 0 ; V_1730 < V_1728 ; V_1730 ++ ) {
if ( V_1727 -> V_1735 [ V_1730 ] . V_1736 > 7 ) {
F_41 ( V_1727 ) ;
return - V_16 ;
}
}
V_46 += V_1729 ;
}
memcpy ( V_1727 -> V_1736 , V_46 , V_1732 ) ;
}
F_113 ( V_541 -> V_28 ) ;
V_498 = F_42 ( V_541 -> V_28 ) ;
if ( ! V_498 )
V_498 = F_408 ( V_7 , V_541 , V_1727 ) ;
F_115 ( V_541 -> V_28 ) ;
F_41 ( V_1727 ) ;
return V_498 ;
}
static int F_409 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
const T_2 * V_1476 ;
T_2 V_1737 , V_1736 ;
T_3 V_1738 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_291 & V_446 ) )
return - V_542 ;
if ( ! V_30 -> V_5 [ V_1739 ] || ! V_30 -> V_5 [ V_549 ] ||
! V_30 -> V_5 [ V_1740 ] )
return - V_16 ;
V_1737 = F_34 ( V_30 -> V_5 [ V_1739 ] ) ;
if ( V_1737 >= V_873 )
return - V_16 ;
V_1736 = F_34 ( V_30 -> V_5 [ V_1740 ] ) ;
if ( V_1736 >= V_1741 )
return - V_16 ;
if ( V_1737 >= V_1742 ) {
return - V_16 ;
}
V_1476 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
if ( V_30 -> V_5 [ V_1743 ] ) {
V_1738 =
F_78 ( V_30 -> V_5 [ V_1743 ] ) ;
if ( ! V_1738 )
return - V_16 ;
}
F_113 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1274 ;
goto V_602;
default:
V_35 = - V_542 ;
goto V_602;
}
V_35 = F_410 ( V_7 , V_541 , V_1737 , V_1476 , V_1736 , V_1738 ) ;
V_602:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_411 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
const T_2 * V_1476 ;
T_2 V_1737 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1739 ] || ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_1737 = F_34 ( V_30 -> V_5 [ V_1739 ] ) ;
V_1476 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_412 ( V_7 , V_541 , V_1737 , V_1476 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_413 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_521 V_522 = {} ;
const T_2 * V_680 ;
T_2 V_1744 ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_1745 ||
! ( V_7 -> V_18 . V_291 & V_1746 ) )
return - V_542 ;
switch ( V_541 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_542 ;
}
if ( ! V_30 -> V_5 [ V_549 ] ||
! V_30 -> V_5 [ V_1747 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_522 ) ;
if ( V_35 )
return V_35 ;
if ( V_522 . V_55 -> V_290 == V_1748 &&
V_522 . V_525 != V_526 &&
V_522 . V_525 != V_581 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_522 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( F_262 ( V_17 -> V_18 , & V_522 , V_17 -> V_141 ) )
return - V_16 ;
V_680 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
V_1744 = F_34 ( V_30 -> V_5 [ V_1747 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_414 ( V_7 , V_541 , V_680 , V_1744 , & V_522 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_415 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_505 [ 0 ] ;
struct V_25 * V_541 = V_30 -> V_505 [ 1 ] ;
struct V_1 * V_17 = V_541 -> V_28 ;
const T_2 * V_680 ;
if ( ! V_7 -> V_351 -> V_1745 ||
! V_7 -> V_351 -> V_1749 ||
! ( V_7 -> V_18 . V_291 & V_1746 ) )
return - V_542 ;
switch ( V_541 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_542 ;
}
if ( ! V_30 -> V_5 [ V_549 ] )
return - V_16 ;
V_680 = F_23 ( V_30 -> V_5 [ V_549 ] ) ;
F_113 ( V_17 ) ;
F_416 ( V_7 , V_541 , V_680 ) ;
F_115 ( V_17 ) ;
return 0 ;
}
static int F_417 ( const struct V_1750 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_541 ;
bool V_1751 = V_351 -> V_1752 & V_1753 ;
if ( V_1751 )
F_14 () ;
if ( V_351 -> V_1752 & V_1754 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1751 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_505 [ 0 ] = V_7 ;
} else if ( V_351 -> V_1752 & V_1755 ||
V_351 -> V_1752 & V_1756 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1751 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_541 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_351 -> V_1752 & V_1755 ) {
if ( ! V_541 ) {
if ( V_1751 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_505 [ 1 ] = V_541 ;
} else {
V_30 -> V_505 [ 1 ] = V_17 ;
}
if ( V_541 ) {
if ( V_351 -> V_1752 & V_1757 &&
! F_91 ( V_541 ) ) {
if ( V_1751 )
F_20 () ;
return - V_556 ;
}
F_246 ( V_541 ) ;
} else if ( V_351 -> V_1752 & V_1757 ) {
if ( ! V_17 -> V_1696 ) {
if ( V_1751 )
F_20 () ;
return - V_556 ;
}
}
V_30 -> V_505 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_418 ( const struct V_1750 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_505 [ 1 ] ) {
if ( V_351 -> V_1752 & V_1756 ) {
struct V_1 * V_17 = V_30 -> V_505 [ 1 ] ;
if ( V_17 -> V_19 )
F_174 ( V_17 -> V_19 ) ;
} else {
F_174 ( V_30 -> V_505 [ 1 ] ) ;
}
}
if ( V_351 -> V_1752 & V_1753 )
F_20 () ;
if ( V_351 -> V_1752 & V_1758 ) {
struct V_1759 * V_36 = F_419 ( V_32 ) ;
memset ( F_420 ( V_36 ) , 0 , F_421 ( V_36 ) ) ;
}
}
void F_422 ( struct V_6 * V_7 ,
enum V_280 V_52 )
{
struct V_31 * V_53 ;
struct V_281 V_282 = {} ;
F_59 ( V_52 != V_295 &&
V_52 != V_1760 ) ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_643 , V_135 ) ;
}
static int F_423 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1206 * V_1394 = V_7 -> V_1210 ;
struct V_4 * V_1192 ;
int V_159 ;
if ( F_59 ( ! V_1394 ) )
return 0 ;
V_1192 = F_47 ( V_53 , V_1214 ) ;
if ( ! V_1192 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1394 -> V_1208 ; V_159 ++ ) {
if ( F_51 ( V_53 , V_159 , V_1394 -> V_1215 [ V_159 ] . V_595 , V_1394 -> V_1215 [ V_159 ] . V_597 ) )
goto V_61;
}
F_48 ( V_53 , V_1192 ) ;
V_1192 = F_47 ( V_53 , V_1213 ) ;
if ( ! V_1192 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1394 -> V_366 ; V_159 ++ ) {
if ( F_28 ( V_53 , V_159 , V_1394 -> V_367 [ V_159 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1192 ) ;
if ( V_1394 -> V_1126 &&
F_51 ( V_53 , V_686 , V_1394 -> V_1127 , V_1394 -> V_1126 ) )
goto V_61;
if ( V_1394 -> V_51 &&
F_28 ( V_53 , V_1219 , V_1394 -> V_51 ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_424 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_283 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) )
goto V_61;
F_423 ( V_53 , V_7 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
static int
F_425 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_283 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_497 ;
}
void F_245 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_424 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1761 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1762 , V_135 ) ;
}
struct V_31 * F_426 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1763 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_424 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1763 ? V_1764 :
V_1298 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_427 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1762 , V_135 ) ;
}
void F_428 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_425 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1765 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1762 , V_135 ) ;
}
void F_256 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_425 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1762 , V_135 ) ;
}
static bool F_429 ( struct V_31 * V_53 ,
struct V_1766 * V_1207 )
{
if ( F_56 ( V_53 , V_1767 , V_1207 -> V_1477 ) )
goto V_61;
if ( V_1207 -> V_1140 [ 0 ] == '0' && V_1207 -> V_1140 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1768 ,
V_1769 ) )
goto V_61;
} else if ( V_1207 -> V_1140 [ 0 ] == '9' && V_1207 -> V_1140 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1768 ,
V_1770 ) )
goto V_61;
} else if ( ( V_1207 -> V_1140 [ 0 ] == '9' && V_1207 -> V_1140 [ 1 ] == '8' ) ||
V_1207 -> V_1771 ) {
if ( F_56 ( V_53 , V_1768 ,
V_1772 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1768 ,
V_1773 ) ||
F_60 ( V_53 , V_1036 ,
V_1207 -> V_1140 ) )
goto V_61;
}
if ( V_1207 -> V_14 != V_1774 ) {
struct V_18 * V_18 = F_19 ( V_1207 -> V_14 ) ;
if ( V_18 &&
F_28 ( V_53 , V_26 , V_1207 -> V_14 ) )
goto V_61;
if ( V_18 &&
V_18 -> V_490 & V_491 &&
F_29 ( V_53 , V_492 ) )
goto V_61;
}
return true ;
V_61:
return false ;
}
void F_430 ( enum V_280 V_1775 ,
struct V_1766 * V_1207 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1775 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_429 ( V_53 , V_1207 ) == false )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_220 () ;
F_431 ( & V_38 , V_53 , 0 ,
V_1776 , V_1777 ) ;
F_222 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_432 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1534 , T_11 V_47 ,
enum V_280 V_52 , T_13 V_1434 ,
int V_928 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1531 , V_47 , V_1534 ) )
goto V_61;
if ( V_928 >= 0 ) {
struct V_4 * V_1778 =
F_47 ( V_53 , V_925 ) ;
if ( ! V_1778 )
goto V_61;
if ( F_56 ( V_53 , V_927 ,
V_928 ) )
goto V_61;
F_48 ( V_53 , V_1778 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_433 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1534 ,
T_11 V_47 , T_13 V_1434 )
{
F_432 ( V_7 , V_19 , V_1534 , V_47 ,
V_707 , V_1434 , - 1 ) ;
}
void F_434 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1534 ,
T_11 V_47 , T_13 V_1434 , int V_928 )
{
F_432 ( V_7 , V_19 , V_1534 , V_47 ,
V_1780 , V_1434 , V_928 ) ;
}
void F_435 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1534 ,
T_11 V_47 , T_13 V_1434 )
{
F_432 ( V_7 , V_19 , V_1534 , V_47 ,
V_1781 , V_1434 , - 1 ) ;
}
void F_436 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1534 ,
T_11 V_47 , T_13 V_1434 )
{
F_432 ( V_7 , V_19 , V_1534 , V_47 ,
V_1782 , V_1434 , - 1 ) ;
}
void F_437 ( struct V_25 * V_541 , const T_2 * V_1534 ,
T_11 V_47 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1783 * V_1784 = ( void * ) V_1534 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_438 ( V_1784 -> V_1785 ) )
V_52 = V_1786 ;
else
V_52 = V_1787 ;
F_439 ( V_541 , V_1534 , V_47 ) ;
F_432 ( V_7 , V_541 , V_1534 , V_47 , V_52 , V_1777 , - 1 ) ;
}
static void F_440 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_680 , T_13 V_1434 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1788 ) ||
F_51 ( V_53 , V_549 , V_590 , V_680 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_441 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_680 ,
T_13 V_1434 )
{
F_440 ( V_7 , V_19 , V_707 ,
V_680 , V_1434 ) ;
}
void F_442 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_680 ,
T_13 V_1434 )
{
F_440 ( V_7 , V_19 , V_1780 ,
V_680 , V_1434 ) ;
}
void F_443 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_548 ,
const T_2 * V_1789 , T_11 V_1790 ,
const T_2 * V_1791 , T_11 V_1792 ,
T_3 V_644 , T_13 V_1434 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_450 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_548 && F_51 ( V_53 , V_549 , V_590 , V_548 ) ) ||
F_55 ( V_53 , V_1479 , V_644 ) ||
( V_1789 &&
F_51 ( V_53 , V_1793 , V_1790 , V_1789 ) ) ||
( V_1791 &&
F_51 ( V_53 , V_1794 , V_1792 , V_1791 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_444 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_548 ,
const T_2 * V_1789 , T_11 V_1790 ,
const T_2 * V_1791 , T_11 V_1792 , T_13 V_1434 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1795 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_548 ) ||
( V_1789 &&
F_51 ( V_53 , V_1793 , V_1790 , V_1789 ) ) ||
( V_1791 &&
F_51 ( V_53 , V_1794 , V_1792 , V_1791 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_445 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1459 ,
const T_2 * V_1126 , T_11 V_1127 , bool V_1796 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_452 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1796 && V_1459 &&
F_55 ( V_53 , V_975 , V_1459 ) ) ||
( V_1796 &&
F_29 ( V_53 , V_1797 ) ) ||
( V_1126 && F_51 ( V_53 , V_686 , V_1127 , V_1126 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_446 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_548 ,
T_13 V_1434 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1798 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_548 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_447 ( struct V_25 * V_541 , const T_2 * V_680 ,
const T_2 * V_1126 , T_2 V_1127 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_448 ( V_541 , V_680 ) ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1799 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_680 ) ||
( V_1127 && V_1126 &&
F_51 ( V_53 , V_686 , V_1127 , V_1126 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_449 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_680 ,
enum V_1800 V_1801 , int V_1802 ,
const T_2 * V_1803 , T_13 V_1434 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1804 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_680 && F_51 ( V_53 , V_549 , V_590 , V_680 ) ) ||
F_28 ( V_53 , V_127 , V_1801 ) ||
( V_1802 != - 1 &&
F_56 ( V_53 , V_123 , V_1802 ) ) ||
( V_1803 && F_51 ( V_53 , V_122 , 6 , V_1803 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_450 ( struct V_18 * V_18 ,
struct V_54 * V_1805 ,
struct V_54 * V_1806 )
{
struct V_31 * V_53 ;
void * V_283 ;
struct V_4 * V_287 ;
V_53 = F_74 ( V_603 , V_1777 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1807 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_218 ( V_18 ) ) )
goto V_61;
V_287 = F_47 ( V_53 , V_1808 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1805 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
V_287 = F_47 ( V_53 , V_1809 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1806 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
F_66 ( V_53 , V_283 ) ;
F_220 () ;
F_431 ( & V_38 , V_53 , 0 ,
V_1776 , V_1777 ) ;
F_222 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_451 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_650 ,
struct V_54 * V_55 ,
unsigned int V_1486 , T_13 V_1434 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) ||
F_28 ( V_53 , V_524 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_529 ,
V_532 ) ||
F_104 ( V_53 , V_1490 , V_650 ,
V_589 ) )
goto V_61;
if ( V_52 == V_1489 &&
F_28 ( V_53 , V_1487 , V_1486 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_452 ( struct V_1 * V_17 , T_1 V_650 ,
struct V_54 * V_55 ,
unsigned int V_1486 , T_13 V_1434 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_453 ( V_17 , V_650 , V_55 , V_1486 ) ;
F_451 ( V_1489 ,
V_7 , V_17 , V_650 , V_55 ,
V_1486 , V_1434 ) ;
}
void F_454 ( struct V_1 * V_17 , T_1 V_650 ,
struct V_54 * V_55 ,
T_13 V_1434 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_455 ( V_17 , V_650 , V_55 ) ;
F_451 ( V_1810 ,
V_7 , V_17 , V_650 , V_55 , 0 , V_1434 ) ;
}
void F_456 ( struct V_25 * V_541 , const T_2 * V_652 ,
struct V_794 * V_795 , T_13 V_1434 )
{
struct V_18 * V_18 = V_541 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_457 ( V_541 , V_652 , V_795 ) ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
if ( F_163 ( V_53 , V_891 , 0 , 0 , 0 ,
V_7 , V_541 , V_652 , V_795 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
}
void F_458 ( struct V_25 * V_541 , const T_2 * V_652 ,
struct V_794 * V_795 , T_13 V_1434 )
{
struct V_18 * V_18 = V_541 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_794 V_1811 = {} ;
if ( ! V_795 )
V_795 = & V_1811 ;
F_459 ( V_541 , V_652 ) ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
if ( F_163 ( V_53 , V_1812 , 0 , 0 , 0 ,
V_7 , V_541 , V_652 , V_795 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
}
void F_460 ( struct V_25 * V_541 , const T_2 * V_652 ,
enum V_1813 V_1459 ,
T_13 V_1434 )
{
struct V_18 * V_18 = V_541 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_1814 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1815 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_652 ) ||
F_28 ( V_53 , V_1816 , V_1459 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static bool F_461 ( struct V_25 * V_541 , T_2 V_52 ,
const T_2 * V_680 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1694 = F_462 ( V_17 -> V_1687 ) ;
if ( ! V_1694 )
return false ;
V_53 = F_74 ( 100 , V_1434 ) ;
if ( ! V_53 )
return true ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_680 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_463 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1694 ) ;
return true ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_464 ( struct V_25 * V_541 ,
const T_2 * V_680 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
bool V_498 ;
F_465 ( V_541 , V_680 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_466 ( false ) ;
return false ;
}
V_498 = F_461 ( V_541 , V_1817 ,
V_680 , V_1434 ) ;
F_466 ( V_498 ) ;
return V_498 ;
}
bool F_467 ( struct V_25 * V_541 ,
const T_2 * V_680 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
bool V_498 ;
F_468 ( V_541 , V_680 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_466 ( false ) ;
return false ;
}
V_498 = F_461 ( V_541 ,
V_1818 ,
V_680 , V_1434 ) ;
F_466 ( V_498 ) ;
return V_498 ;
}
int F_469 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1694 ,
int V_1819 , int V_1820 ,
const T_2 * V_1534 , T_11 V_47 , V_22 V_51 , T_13 V_1434 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1538 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) ||
F_28 ( V_53 , V_524 , V_1819 ) ||
( V_1820 &&
F_28 ( V_53 , V_1821 , V_1820 ) ) ||
F_51 ( V_53 , V_1531 , V_47 , V_1534 ) ||
( V_51 &&
F_28 ( V_53 , V_1822 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_463 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1694 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_470 ( struct V_1 * V_17 , T_1 V_650 ,
const T_2 * V_1534 , T_11 V_47 , bool V_1823 , T_13 V_1434 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
F_471 ( V_17 , V_650 , V_1823 ) ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1824 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) ||
F_51 ( V_53 , V_1531 , V_47 , V_1534 ) ||
F_104 ( V_53 , V_1490 , V_650 ,
V_589 ) ||
( V_1823 && F_29 ( V_53 , V_1825 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_472 ( struct V_25 * V_541 ,
const char * V_969 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_603 , V_1434 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1826 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_541 -> V_20 ) )
goto V_61;
if ( V_969 && F_51 ( V_53 , V_549 , V_590 , V_969 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1557 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_473 ( struct V_31 * V_53 , T_13 V_1434 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
}
void F_474 ( struct V_25 * V_541 ,
enum V_1827 V_1828 ,
T_13 V_1434 )
{
struct V_31 * V_53 ;
F_475 ( V_541 , V_1828 ) ;
if ( F_59 ( V_1828 != V_1829 &&
V_1828 != V_1830 ) )
return;
V_53 = F_472 ( V_541 , NULL , V_1434 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1831 ,
V_1828 ) )
goto V_61;
F_473 ( V_53 , V_1434 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_476 ( struct V_25 * V_541 ,
const T_2 * V_1476 , V_22 V_1832 ,
V_22 V_244 , V_22 V_1549 , T_13 V_1434 )
{
struct V_31 * V_53 ;
V_53 = F_472 ( V_541 , V_1476 , V_1434 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1562 , V_1832 ) )
goto V_61;
if ( F_28 ( V_53 , V_1561 , V_244 ) )
goto V_61;
if ( F_28 ( V_53 , V_1563 , V_1549 ) )
goto V_61;
F_473 ( V_53 , V_1434 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_477 ( struct V_25 * V_541 ,
const T_2 * V_1476 , V_22 V_1832 , T_13 V_1434 )
{
struct V_31 * V_53 ;
F_478 ( V_541 , V_1476 , V_1832 ) ;
V_53 = F_472 ( V_541 , V_1476 , V_1434 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1833 , V_1832 ) )
goto V_61;
F_473 ( V_53 , V_1434 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_479 ( struct V_25 * V_541 , T_13 V_1434 )
{
struct V_31 * V_53 ;
V_53 = F_472 ( V_541 , NULL , V_1434 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1834 ) )
goto V_61;
F_473 ( V_53 , V_1434 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_480 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_548 ,
const T_2 * V_1685 , T_13 V_1434 )
{
struct V_31 * V_53 ;
struct V_4 * V_1835 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1836 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_548 ) )
goto V_61;
V_1835 = F_47 ( V_53 , V_1673 ) ;
if ( ! V_1835 )
goto V_61;
if ( F_51 ( V_53 , V_1676 ,
V_1677 , V_1685 ) )
goto V_61;
F_48 ( V_53 , V_1835 ) ;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_481 ( struct V_25 * V_541 , const T_2 * V_548 ,
const T_2 * V_1685 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_482 ( V_541 , V_548 ) ;
F_480 ( V_7 , V_541 , V_548 , V_1685 , V_1434 ) ;
}
static void
F_483 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1837 ,
const T_2 * V_548 , bool V_1838 , T_13 V_1434 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1839 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1840 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1841 , V_1837 ) ||
F_51 ( V_53 , V_1842 , V_590 , V_548 ) ||
( V_1838 &&
F_29 ( V_53 , V_1843 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_484 ( struct V_25 * V_541 , int V_1837 ,
const T_2 * V_548 , bool V_1838 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_485 ( V_541 , V_1837 , V_548 , V_1838 ) ;
F_483 ( V_7 , V_541 , V_1837 , V_548 , V_1838 , V_1434 ) ;
}
static void F_486 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_521 * V_522 ,
T_13 V_1434 ,
enum V_280 V_1844 ,
T_2 V_1277 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1844 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_522 ) )
goto V_61;
if ( ( V_1844 == V_1845 ) &&
( F_28 ( V_53 , V_1275 , V_1277 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_487 ( struct V_25 * V_541 ,
struct V_521 * V_522 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_488 ( V_541 , V_522 ) ;
V_17 -> V_522 = * V_522 ;
V_17 -> V_547 = * V_522 ;
F_486 ( V_7 , V_541 , V_522 , V_135 ,
V_1846 , 0 ) ;
}
void F_489 ( struct V_25 * V_541 ,
struct V_521 * V_522 ,
T_2 V_1277 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_490 ( V_541 , V_522 ) ;
F_486 ( V_7 , V_541 , V_522 , V_135 ,
V_1845 , V_1277 ) ;
}
void
F_491 ( struct V_6 * V_7 ,
const struct V_521 * V_522 ,
enum V_1847 V_628 ,
struct V_25 * V_19 , T_13 V_1434 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1848 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) )
goto V_61;
}
if ( F_28 ( V_53 , V_1849 , V_628 ) )
goto V_61;
if ( F_101 ( V_53 , V_522 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_492 ( struct V_25 * V_541 , const T_2 * V_680 ,
T_1 V_650 , bool V_1850 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_493 ( V_541 , V_680 , V_650 , V_1850 ) ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1688 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_680 ) ||
F_104 ( V_53 , V_1490 , V_650 ,
V_589 ) ||
( V_1850 && F_29 ( V_53 , V_1825 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_494 ( struct V_18 * V_18 ,
const T_2 * V_1851 , T_11 V_47 ,
int V_1819 , int V_1820 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
struct V_1689 * V_1690 ;
F_495 ( V_18 , V_1851 , V_47 , V_1819 , V_1820 ) ;
F_272 ( & V_7 -> V_1693 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1777 ) ;
if ( ! V_53 ) {
F_274 ( & V_7 -> V_1693 ) ;
return;
}
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1538 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1819 &&
F_28 ( V_53 , V_524 , V_1819 ) ) ||
( V_1820 &&
F_28 ( V_53 , V_1821 , V_1820 ) ) ||
F_51 ( V_53 , V_1531 , V_47 , V_1851 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_463 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1690 -> V_1694 ) ;
}
F_274 ( & V_7 -> V_1693 ) ;
return;
V_61:
F_274 ( & V_7 -> V_1693 ) ;
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_496 ( struct V_31 * V_53 ,
struct V_1852 * V_1853 )
{
struct V_1854 * V_1599 = V_1853 -> V_1855 ;
struct V_4 * V_1856 , * V_1857 , * V_286 ;
int V_159 , V_161 ;
V_1856 = F_47 (
V_53 , V_1858 ) ;
if ( ! V_1856 )
return - V_497 ;
for ( V_159 = 0 ; V_159 < V_1599 -> V_1859 ; V_159 ++ ) {
struct V_1860 * V_1601 = V_1599 -> V_1600 [ V_159 ] ;
V_1857 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1857 )
break;
if ( F_51 ( V_53 , V_596 , V_1601 -> V_597 . V_595 ,
V_1601 -> V_597 . V_597 ) ) {
F_497 ( V_53 , V_1857 ) ;
goto V_602;
}
if ( V_1601 -> V_366 ) {
V_286 = F_47 (
V_53 , V_1213 ) ;
if ( ! V_286 ) {
F_497 ( V_53 , V_1857 ) ;
goto V_602;
}
for ( V_161 = 0 ; V_161 < V_1601 -> V_366 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1601 -> V_367 [ V_161 ] ) ) {
F_497 ( V_53 , V_286 ) ;
F_497 ( V_53 , V_1857 ) ;
goto V_602;
}
}
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_1857 ) ;
}
V_602:
F_48 ( V_53 , V_1856 ) ;
return 0 ;
}
void F_498 ( struct V_1 * V_17 ,
struct V_1852 * V_1853 ,
T_13 V_1434 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
int V_1603 = 200 ;
F_499 ( V_17 -> V_18 , V_17 , V_1853 ) ;
if ( V_1853 )
V_1603 += V_1853 -> V_1861 ;
V_53 = F_74 ( V_1603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1862 ) ;
if ( ! V_283 )
goto V_660;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) )
goto V_660;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_660;
if ( V_1853 ) {
struct V_4 * V_1863 ;
V_1863 = F_47 ( V_53 , V_1605 ) ;
if ( ! V_1863 )
goto V_660;
if ( V_1853 -> V_451 &&
F_29 ( V_53 , V_206 ) )
goto V_660;
if ( V_1853 -> V_1607 &&
F_29 ( V_53 , V_208 ) )
goto V_660;
if ( V_1853 -> V_1608 &&
F_29 ( V_53 , V_212 ) )
goto V_660;
if ( V_1853 -> V_1609 &&
F_29 ( V_53 , V_214 ) )
goto V_660;
if ( V_1853 -> V_1610 &&
F_29 ( V_53 , V_216 ) )
goto V_660;
if ( V_1853 -> V_1611 &&
F_29 ( V_53 , V_218 ) )
goto V_660;
if ( V_1853 -> V_1864 >= 0 &&
F_28 ( V_53 , V_228 ,
V_1853 -> V_1864 ) )
goto V_660;
if ( V_1853 -> V_1865 &&
F_29 ( V_53 , V_1866 ) )
goto V_660;
if ( V_1853 -> V_1867 &&
F_29 ( V_53 , V_1868 ) )
goto V_660;
if ( V_1853 -> V_1869 &&
F_29 ( V_53 ,
V_1870 ) )
goto V_660;
if ( V_1853 -> V_1871 ) {
V_22 V_1872 = V_1873 ;
V_22 V_1874 = V_1875 ;
if ( ! V_1853 -> V_1876 ) {
V_1872 =
V_1877 ;
V_1874 =
V_1878 ;
}
if ( V_1853 -> V_1879 &&
F_28 ( V_53 , V_1874 , V_1853 -> V_1879 ) )
goto V_660;
if ( F_51 ( V_53 , V_1872 , V_1853 -> V_1861 ,
V_1853 -> V_1871 ) )
goto V_660;
}
if ( V_1853 -> V_1855 &&
F_496 ( V_53 , V_1853 ) )
goto V_660;
F_48 ( V_53 , V_1863 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_660:
F_75 ( V_53 ) ;
}
void F_500 ( struct V_25 * V_541 , const T_2 * V_1476 ,
enum V_1483 V_1880 ,
T_3 V_976 , T_13 V_1434 )
{
struct V_1 * V_17 = V_541 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_501 ( V_17 -> V_18 , V_541 , V_1476 , V_1880 ,
V_976 ) ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1881 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_541 -> V_20 ) ||
F_56 ( V_53 , V_1485 , V_1880 ) ||
F_51 ( V_53 , V_549 , V_590 , V_1476 ) ||
( V_976 > 0 &&
F_55 ( V_53 , V_975 , V_976 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_1434 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_502 ( struct V_1882 * V_1883 ,
unsigned long V_282 ,
void * V_1884 )
{
struct V_1885 * V_1886 = V_1884 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1689 * V_1690 , * V_24 ;
if ( V_282 != V_1887 || V_1886 -> V_1888 != V_1889 )
return V_1890 ;
F_220 () ;
F_503 (rdev, &cfg80211_rdev_list, list) {
bool V_1891 = false ;
bool V_1892 = false ;
struct V_1230 * V_1261 =
F_221 ( V_7 -> V_1261 ) ;
if ( V_1261 && V_1886 -> V_49 &&
V_1261 -> V_635 == V_1886 -> V_49 )
V_1892 = true ;
F_503 (wdev, &rdev->wiphy.wdev_list, list) {
F_504 ( V_17 , V_1886 -> V_49 ) ;
if ( V_17 -> V_635 == V_1886 -> V_49 )
V_1891 = true ;
}
F_272 ( & V_7 -> V_1693 ) ;
F_505 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1690 -> V_1694 == V_1886 -> V_49 ) {
F_506 ( & V_1690 -> V_641 ) ;
F_41 ( V_1690 ) ;
break;
}
}
F_274 ( & V_7 -> V_1693 ) ;
if ( V_1891 ) {
struct V_1893 * V_1894 ;
V_1894 = F_38 ( sizeof( * V_1894 ) , V_1777 ) ;
if ( V_1894 ) {
V_1894 -> V_1694 = V_1886 -> V_49 ;
F_507 ( & V_7 -> V_1895 ) ;
F_389 ( & V_1894 -> V_641 , & V_7 -> V_1896 ) ;
F_508 ( & V_7 -> V_1895 ) ;
F_509 ( & V_7 -> V_1897 ) ;
}
} else if ( V_1892 ) {
V_1261 -> V_635 = 0 ;
if ( V_7 -> V_351 -> V_1263 &&
V_7 -> V_18 . V_51 & V_422 )
F_509 ( & V_7 -> V_1898 ) ;
}
}
F_222 () ;
F_510 ( V_1886 -> V_49 ) ;
return V_1899 ;
}
void F_511 ( struct V_25 * V_19 ,
struct V_1900 * V_1901 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_512 ( V_18 , V_19 , V_1901 ) ;
if ( ! V_1901 -> V_1902 )
return;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1903 ) ;
if ( ! V_283 )
goto V_602;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_549 , V_590 , V_1901 -> V_1902 ) )
goto V_602;
if ( V_1901 -> V_1296 &&
F_51 ( V_53 , V_686 , V_1901 -> V_1904 , V_1901 -> V_1296 ) )
goto V_602;
if ( V_1901 -> V_1905 &&
F_51 ( V_53 , V_1906 , V_1901 -> V_1907 ,
V_1901 -> V_1905 ) )
goto V_602;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1779 , V_135 ) ;
return;
V_602:
F_75 ( V_53 ) ;
}
void F_513 ( struct V_1 * V_17 , T_13 V_1434 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1694 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1711 )
return;
V_1694 = V_7 -> V_1711 ;
V_7 -> V_1711 = 0 ;
V_53 = F_74 ( V_603 , V_1434 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1908 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_463 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1694 ) ;
return;
V_61:
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_514 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_603 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1909 ) ;
if ( ! V_283 )
goto V_602;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_589 ) )
goto V_602;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1779 , V_135 ) ;
return;
V_602:
F_75 ( V_53 ) ;
}
int F_515 ( void )
{
int V_35 ;
V_35 = F_516 ( & V_38 , V_1910 ,
V_1911 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_517 ( & V_1912 ) ;
if ( V_35 )
goto V_1913;
return 0 ;
V_1913:
F_518 ( & V_38 ) ;
return V_35 ;
}
void F_519 ( void )
{
F_520 ( & V_1912 ) ;
F_518 ( & V_38 ) ;
}
