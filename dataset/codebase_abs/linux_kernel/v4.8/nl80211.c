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
V_282 -> V_297 ++ ;
break;
case 13 :
if ( V_7 -> V_18 . V_497 &&
V_7 -> V_18 . V_498 ) {
struct V_4 * V_499 , * V_482 ;
V_482 = F_47 ( V_53 ,
V_500 ) ;
if ( ! V_482 )
goto V_61;
for ( V_159 = V_282 -> V_501 ;
V_159 < V_7 -> V_18 . V_497 ; V_159 ++ ) {
const struct V_502 * V_503 ;
V_503 = & V_7 -> V_18 . V_498 [ V_159 ] ;
V_499 = F_47 ( V_53 , V_159 ) ;
if ( ! V_499 ||
F_28 ( V_53 , V_504 ,
V_503 -> V_141 ) ||
F_51 ( V_53 , V_469 ,
V_503 -> V_470 ,
V_503 -> V_468 ) ||
F_51 ( V_53 , V_471 ,
V_503 -> V_470 ,
V_503 -> V_472 ) )
goto V_61;
F_48 ( V_53 , V_499 ) ;
if ( V_282 -> V_336 )
break;
}
F_48 ( V_53 , V_482 ) ;
if ( V_159 < V_7 -> V_18 . V_497 ) {
V_282 -> V_501 = V_159 + 1 ;
break;
}
}
V_282 -> V_297 = 0 ;
break;
}
V_296:
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_281 * V_282 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_506 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_506 )
return 0 ;
V_282 -> V_336 = V_95 [ V_507 ] ;
if ( V_95 [ V_26 ] )
V_282 -> V_508 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_282 -> V_508 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
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
V_282 -> V_508 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_506 ;
struct V_281 * V_282 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_282 ) {
V_282 = F_38 ( sizeof( * V_282 ) , V_135 ) ;
if ( ! V_282 ) {
F_20 () ;
return - V_136 ;
}
V_282 -> V_508 = - 1 ;
V_506 = F_68 ( V_32 , V_34 , V_282 ) ;
if ( V_506 ) {
F_41 ( V_282 ) ;
F_20 () ;
return V_506 ;
}
V_34 -> args [ 0 ] = ( long ) V_282 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_282 -> V_509 )
continue;
if ( V_282 -> V_508 != - 1 &&
V_282 -> V_508 != V_7 -> V_14 )
continue;
do {
V_506 = F_58 ( V_7 , V_295 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 ,
V_511 , V_282 ) ;
if ( V_506 < 0 ) {
if ( ( V_506 == - V_91 || V_506 == - V_505 ) &&
! V_32 -> V_47 && ! V_282 -> V_336 &&
V_34 -> V_512 < 4096 ) {
V_34 -> V_512 = 4096 ;
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
V_282 -> V_509 = V_105 ;
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
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_281 V_282 = {} ;
V_53 = F_74 ( 4096 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_58 ( V_7 , V_295 , V_53 ,
V_30 -> V_514 , V_30 -> V_515 , 0 ,
& V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_516 * V_517 )
{
if ( ! V_95 [ V_518 ] || ! V_95 [ V_519 ] ||
! V_95 [ V_520 ] || ! V_95 [ V_521 ] ||
! V_95 [ V_522 ] )
return - V_16 ;
V_517 -> V_523 = F_34 ( V_95 [ V_518 ] ) ;
V_517 -> V_524 = F_78 ( V_95 [ V_519 ] ) ;
V_517 -> V_525 = F_78 ( V_95 [ V_520 ] ) ;
V_517 -> V_526 = F_78 ( V_95 [ V_521 ] ) ;
V_517 -> V_527 = F_34 ( V_95 [ V_522 ] ) ;
if ( V_517 -> V_523 >= V_528 )
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
struct V_529 * V_530 )
{
V_22 V_531 ;
if ( ! V_30 -> V_5 [ V_532 ] )
return - V_16 ;
V_531 = F_4 ( V_30 -> V_5 [ V_532 ] ) ;
V_530 -> V_55 = F_45 ( & V_7 -> V_18 , V_531 ) ;
V_530 -> V_533 = V_534 ;
V_530 -> V_535 = V_531 ;
V_530 -> V_536 = 0 ;
if ( ! V_530 -> V_55 || V_530 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_537 ] ) {
enum V_538 V_539 ;
V_539 = F_4 (
V_30 -> V_5 [ V_537 ] ) ;
switch ( V_539 ) {
case V_540 :
case V_541 :
case V_542 :
case V_543 :
F_81 ( V_530 , V_530 -> V_55 ,
V_539 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_544 ] ) {
V_530 -> V_533 =
F_4 ( V_30 -> V_5 [ V_544 ] ) ;
if ( V_30 -> V_5 [ V_545 ] )
V_530 -> V_535 =
F_4 (
V_30 -> V_5 [ V_545 ] ) ;
if ( V_30 -> V_5 [ V_546 ] )
V_530 -> V_536 =
F_4 (
V_30 -> V_5 [ V_546 ] ) ;
}
if ( ! F_82 ( V_530 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_530 ,
V_62 ) )
return - V_16 ;
if ( ( V_530 -> V_533 == V_547 ||
V_530 -> V_533 == V_548 ) &&
! ( V_7 -> V_18 . V_51 & V_475 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_549 ,
struct V_29 * V_30 )
{
struct V_529 V_530 ;
int V_8 ;
enum V_272 V_141 = V_153 ;
struct V_1 * V_17 = NULL ;
if ( V_549 )
V_17 = V_549 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_550 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_80 ( V_7 , V_30 , & V_530 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_85 ( & V_7 -> V_18 , & V_530 ,
V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_551 ) {
if ( ! V_549 || ! V_7 -> V_351 -> V_552 ||
! ( V_7 -> V_18 . V_291 &
V_553 ) ) {
V_8 = - V_554 ;
break;
}
if ( V_530 . V_55 != V_17 -> V_555 . V_55 ) {
V_8 = - V_554 ;
break;
}
V_8 = F_86 ( V_7 , V_549 , & V_530 ) ;
if ( V_8 )
break;
}
V_17 -> V_555 = V_530 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_87 ( V_7 , V_17 , & V_530 ) ;
break;
case V_153 :
V_8 = F_88 ( V_7 , & V_530 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_513 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
const T_2 * V_556 ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( F_91 ( V_549 ) )
return - V_554 ;
if ( ! V_7 -> V_351 -> V_416 )
return - V_550 ;
if ( V_17 -> V_141 != V_155 )
return - V_550 ;
V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
return F_92 ( V_7 , V_549 , V_556 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_558 = 0 ;
struct V_4 * V_559 ;
V_22 V_560 ;
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
if ( V_30 -> V_5 [ V_561 ] ) {
struct V_516 V_517 ;
struct V_4 * V_95 [ V_562 + 1 ] ;
if ( ! V_7 -> V_351 -> V_563 )
return - V_550 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_564 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_562 ,
F_23 ( V_559 ) ,
F_24 ( V_559 ) ,
V_565 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_517 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_517 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_532 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_566 ] ) {
struct V_1 * V_567 = V_17 ;
enum V_568 type ;
int V_105 , V_569 = 0 ;
if ( ! ( V_7 -> V_18 . V_291 & V_570 ) )
V_567 = NULL ;
if ( ! V_7 -> V_351 -> V_571 )
return - V_550 ;
V_105 = V_566 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_572 ] &&
( type != V_573 ) )
return - V_16 ;
if ( type != V_573 ) {
V_105 = V_572 ;
V_569 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_567 , type , V_569 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_356 ] &&
V_30 -> V_5 [ V_357 ] ) {
V_22 V_353 , V_354 ;
if ( ( ! V_7 -> V_18 . V_345 &&
! V_7 -> V_18 . V_347 ) ||
! V_7 -> V_351 -> V_574 )
return - V_550 ;
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
V_560 = 0 ;
if ( V_30 -> V_5 [ V_298 ] ) {
V_299 = F_34 (
V_30 -> V_5 [ V_298 ] ) ;
if ( V_299 == 0 )
return - V_16 ;
V_560 |= V_575 ;
}
if ( V_30 -> V_5 [ V_300 ] ) {
V_301 = F_34 (
V_30 -> V_5 [ V_300 ] ) ;
if ( V_301 == 0 )
return - V_16 ;
V_560 |= V_576 ;
}
if ( V_30 -> V_5 [ V_302 ] ) {
V_303 = F_4 (
V_30 -> V_5 [ V_302 ] ) ;
if ( V_303 < 256 )
return - V_16 ;
if ( V_303 != ( V_22 ) - 1 ) {
V_303 &= ~ 0x1 ;
}
V_560 |= V_577 ;
}
if ( V_30 -> V_5 [ V_304 ] ) {
V_305 = F_4 (
V_30 -> V_5 [ V_304 ] ) ;
V_560 |= V_578 ;
}
if ( V_30 -> V_5 [ V_306 ] ) {
if ( V_30 -> V_5 [ V_579 ] )
return - V_16 ;
V_307 = F_34 (
V_30 -> V_5 [ V_306 ] ) ;
V_560 |= V_580 ;
}
if ( V_30 -> V_5 [ V_579 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_581 ) )
return - V_550 ;
V_560 |= V_582 ;
}
if ( V_560 ) {
T_2 V_583 , V_584 ;
V_22 V_585 , V_586 ;
T_2 V_587 ;
if ( ! V_7 -> V_351 -> V_588 )
return - V_550 ;
V_583 = V_7 -> V_18 . V_299 ;
V_584 = V_7 -> V_18 . V_301 ;
V_585 = V_7 -> V_18 . V_303 ;
V_586 = V_7 -> V_18 . V_305 ;
V_587 = V_7 -> V_18 . V_307 ;
if ( V_560 & V_575 )
V_7 -> V_18 . V_299 = V_299 ;
if ( V_560 & V_576 )
V_7 -> V_18 . V_301 = V_301 ;
if ( V_560 & V_577 )
V_7 -> V_18 . V_303 = V_303 ;
if ( V_560 & V_578 )
V_7 -> V_18 . V_305 = V_305 ;
if ( V_560 & V_580 )
V_7 -> V_18 . V_307 = V_307 ;
V_8 = F_100 ( V_7 , V_560 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_299 = V_583 ;
V_7 -> V_18 . V_301 = V_584 ;
V_7 -> V_18 . V_303 = V_585 ;
V_7 -> V_18 . V_305 = V_586 ;
V_7 -> V_18 . V_307 = V_587 ;
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
const struct V_529 * V_530 )
{
if ( F_59 ( ! F_82 ( V_530 ) ) )
return - V_16 ;
if ( F_28 ( V_53 , V_532 ,
V_530 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_530 -> V_533 ) {
case V_534 :
case V_589 :
case V_590 :
if ( F_28 ( V_53 , V_537 ,
F_102 ( V_530 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_544 , V_530 -> V_533 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_545 , V_530 -> V_535 ) )
return - V_91 ;
if ( V_530 -> V_536 &&
F_28 ( V_53 , V_546 , V_530 -> V_536 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_591 )
{
struct V_25 * V_549 = V_17 -> V_19 ;
T_2 V_52 = V_592 ;
void * V_283 ;
if ( V_591 )
V_52 = V_593 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( V_549 &&
( F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_60 ( V_53 , V_594 , V_549 -> V_595 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_504 , V_17 -> V_141 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_596 ) ||
F_51 ( V_53 , V_557 , V_597 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_293 ,
V_7 -> V_598 ^
( V_294 << 2 ) ) )
goto V_61;
if ( V_7 -> V_351 -> V_599 ) {
int V_506 ;
struct V_529 V_530 ;
V_506 = F_106 ( V_7 , V_17 , & V_530 ) ;
if ( V_506 == 0 ) {
if ( F_101 ( V_53 , & V_530 ) )
goto V_61;
}
}
if ( V_7 -> V_351 -> V_600 ) {
int V_601 , V_506 ;
V_506 = F_107 ( V_7 , V_17 , & V_601 ) ;
if ( V_506 == 0 &&
F_28 ( V_53 , V_572 ,
F_31 ( V_601 ) ) )
goto V_61;
}
if ( V_17 -> V_602 ) {
if ( F_51 ( V_53 , V_603 , V_17 -> V_602 , V_17 -> V_604 ) )
goto V_61;
}
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_605 = 0 ;
int V_606 = 0 ;
int V_607 = V_34 -> args [ 0 ] ;
int V_608 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_605 < V_607 ) {
V_605 ++ ;
continue;
}
V_606 = 0 ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_606 < V_608 ) {
V_606 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_7 , V_17 , false ) < 0 ) {
goto V_609;
}
V_606 ++ ;
}
V_605 ++ ;
}
V_609:
F_20 () ;
V_34 -> args [ 0 ] = V_605 ;
V_34 -> args [ 1 ] = V_606 ;
return V_32 -> V_47 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_103 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_110 ( struct V_4 * V_611 , V_22 * V_612 )
{
struct V_4 * V_51 [ V_613 + 1 ] ;
int V_614 ;
* V_612 = 0 ;
if ( ! V_611 )
return - V_16 ;
if ( F_33 ( V_51 , V_613 ,
V_611 , V_615 ) )
return - V_16 ;
for ( V_614 = 1 ; V_614 <= V_613 ; V_614 ++ )
if ( V_51 [ V_614 ] )
* V_612 |= ( 1 << V_614 ) ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_616 ,
enum V_272 V_141 )
{
if ( ! V_616 ) {
if ( V_19 && ( V_19 -> V_617 & V_618 ) )
return - V_554 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_51 & V_619 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_51 & V_620 )
return 0 ;
break;
default:
break;
}
return - V_550 ;
}
static int F_112 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_621 V_137 ;
int V_35 ;
enum V_272 V_622 , V_623 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
V_22 V_624 , * V_51 = NULL ;
bool V_625 = false ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_622 = V_623 = V_549 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_504 ] ) {
V_623 = F_4 ( V_30 -> V_5 [ V_504 ] ) ;
if ( V_622 != V_623 )
V_625 = true ;
if ( V_623 > V_626 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_627 ] ) {
struct V_1 * V_17 = V_549 -> V_28 ;
if ( V_623 != V_145 )
return - V_16 ;
if ( F_91 ( V_549 ) )
return - V_554 ;
F_113 ( V_17 ) ;
F_114 ( V_628 !=
V_629 ) ;
V_17 -> V_630 =
F_24 ( V_30 -> V_5 [ V_627 ] ) ;
memcpy ( V_17 -> V_604 , F_23 ( V_30 -> V_5 [ V_627 ] ) ,
V_17 -> V_630 ) ;
F_115 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_631 ] ) {
V_137 . V_616 = ! ! F_34 ( V_30 -> V_5 [ V_631 ] ) ;
V_625 = true ;
V_35 = F_111 ( V_7 , V_549 , V_137 . V_616 , V_623 ) ;
if ( V_35 )
return V_35 ;
} else {
V_137 . V_616 = - 1 ;
}
if ( V_30 -> V_5 [ V_632 ] ) {
if ( V_623 != V_153 )
return - V_16 ;
V_35 = F_110 ( V_30 -> V_5 [ V_632 ] ,
& V_624 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_624 ;
V_625 = true ;
}
if ( V_30 -> V_5 [ V_633 ] ) {
const T_2 * V_634 ;
V_22 V_635 = V_636 ;
if ( ! F_116 ( & V_7 -> V_18 , V_635 ) )
return - V_550 ;
V_634 =
F_23 ( V_30 -> V_5 [ V_633 ] ) ;
if ( ( V_634 [ 0 ] & F_117 ( 7 ) ) ||
( V_634 [ V_637 - 1 ] & F_117 ( 0 ) ) )
return - V_16 ;
memcpy ( V_137 . V_638 , V_634 ,
V_637 ) ;
V_625 = true ;
}
if ( V_30 -> V_5 [ V_639 ] ) {
V_22 V_635 = V_636 ;
if ( ! F_116 ( & V_7 -> V_18 , V_635 ) )
return - V_550 ;
F_118 ( V_137 . V_640 ,
V_30 -> V_5 [ V_639 ] ,
V_597 ) ;
V_625 = true ;
}
if ( V_51 && ( * V_51 & V_641 ) &&
! ( V_7 -> V_18 . V_291 & V_642 ) )
return - V_550 ;
if ( V_625 )
V_35 = F_119 ( V_7 , V_549 , V_623 , V_51 , & V_137 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_137 . V_616 != - 1 )
V_549 -> V_28 -> V_616 = V_137 . V_616 ;
return V_35 ;
}
static int F_120 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_621 V_137 ;
struct V_1 * V_17 ;
struct V_31 * V_53 , * V_643 ;
int V_35 ;
enum V_272 type = V_151 ;
V_22 V_51 ;
F_121 ( V_7 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_594 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_504 ] ) {
type = F_4 ( V_30 -> V_5 [ V_504 ] ) ;
if ( type > V_626 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_369 ||
! ( V_7 -> V_18 . V_359 & ( 1 << type ) ) )
return - V_550 ;
if ( ( type == V_154 ||
V_7 -> V_18 . V_291 & V_644 ) &&
V_30 -> V_5 [ V_557 ] ) {
F_118 ( V_137 . V_640 , V_30 -> V_5 [ V_557 ] ,
V_597 ) ;
if ( ! F_122 ( V_137 . V_640 ) )
return - V_645 ;
}
if ( V_30 -> V_5 [ V_631 ] ) {
V_137 . V_616 = ! ! F_34 ( V_30 -> V_5 [ V_631 ] ) ;
V_35 = F_111 ( V_7 , NULL , V_137 . V_616 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_110 ( type == V_153 ?
V_30 -> V_5 [ V_632 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_641 ) &&
! ( V_7 -> V_18 . V_291 & V_642 ) )
return - V_550 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_17 = F_123 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_594 ] ) ,
V_646 , type , V_35 ? NULL : & V_51 ,
& V_137 ) ;
if ( F_59 ( ! V_17 ) ) {
F_75 ( V_53 ) ;
return - V_647 ;
} else if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_648 ] )
V_17 -> V_649 = V_30 -> V_514 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_627 ] )
break;
F_113 ( V_17 ) ;
F_114 ( V_628 !=
V_629 ) ;
V_17 -> V_630 =
F_24 ( V_30 -> V_5 [ V_627 ] ) ;
memcpy ( V_17 -> V_604 , F_23 ( V_30 -> V_5 [ V_627 ] ) ,
V_17 -> V_630 ) ;
F_115 ( V_17 ) ;
break;
case V_154 :
F_124 ( & V_17 -> V_650 ) ;
F_125 ( & V_17 -> V_651 ) ;
F_126 ( & V_17 -> V_652 ) ;
F_125 ( & V_17 -> V_653 ) ;
F_126 ( & V_17 -> V_654 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_127 ( & V_17 -> V_655 , & V_7 -> V_18 . V_656 ) ;
V_7 -> V_598 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
V_643 = F_74 ( V_610 , V_135 ) ;
if ( V_643 ) {
if ( F_103 ( V_643 , 0 , 0 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_643 ) ;
goto V_609;
}
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_643 , 0 , V_657 ,
V_135 ) ;
}
V_609:
return F_76 ( V_53 , V_30 ) ;
}
static int F_129 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
struct V_31 * V_53 ;
int V_658 ;
if ( ! V_7 -> V_351 -> V_659 )
return - V_550 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( V_53 && F_103 ( V_53 , 0 , 0 , 0 , V_7 , V_17 , true ) < 0 ) {
F_75 ( V_53 ) ;
V_53 = NULL ;
}
if ( ! V_17 -> V_19 )
V_30 -> V_513 [ 1 ] = NULL ;
V_658 = F_130 ( V_7 , V_17 ) ;
if ( V_658 >= 0 && V_53 )
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_657 ,
V_135 ) ;
else
F_75 ( V_53 ) ;
return V_658 ;
}
static int F_131 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_3 V_660 ;
if ( ! V_30 -> V_5 [ V_661 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_427 )
return - V_550 ;
V_660 = F_78 ( V_30 -> V_5 [ V_661 ] ) ;
return F_132 ( V_7 , V_549 , V_660 ) ;
}
static void F_133 ( void * V_165 , struct V_662 * V_137 )
{
struct V_4 * V_92 ;
struct V_663 * V_664 = V_165 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_664 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_664 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_664 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_664 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_664 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_664 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_664 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_664 -> V_53 , V_123 , V_664 -> V_105 ) )
goto V_61;
F_48 ( V_664 -> V_53 , V_92 ) ;
return;
V_61:
V_664 -> error = 1 ;
}
static int F_134 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
int V_35 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 V_665 = 0 ;
const T_2 * V_666 = NULL ;
bool V_667 ;
struct V_663 V_664 = {
. error = 0 ,
} ;
void * V_283 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_665 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_665 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_557 ] )
V_666 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_667 = ! ! V_666 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_668 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_668 >= V_114 )
return - V_16 ;
if ( V_668 != V_669 &&
V_668 != V_670 )
return - V_16 ;
V_667 = V_668 == V_670 ;
}
if ( ! V_7 -> V_351 -> V_671 )
return - V_550 ;
if ( ! V_667 && V_666 && ! ( V_7 -> V_18 . V_51 & V_324 ) )
return - V_672 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_673 ) ;
if ( ! V_283 )
goto V_61;
V_664 . V_53 = V_53 ;
V_664 . V_105 = V_665 ;
if ( F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_665 ) )
goto V_61;
if ( V_666 &&
F_51 ( V_53 , V_557 , V_597 , V_666 ) )
goto V_61;
V_35 = F_135 ( V_7 , V_549 , V_665 , V_667 , V_666 , & V_664 ,
F_133 ) ;
if ( V_35 )
goto V_674;
if ( V_664 . error )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_674:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_136 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_113 ( V_549 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_351 -> V_675 ) {
V_35 = - V_550 ;
goto V_609;
}
V_35 = F_42 ( V_549 -> V_28 ) ;
if ( V_35 )
goto V_609;
V_35 = F_137 ( V_7 , V_549 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_609;
#ifdef F_138
V_549 -> V_28 -> V_676 . V_677 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_609;
}
if ( ! V_7 -> V_351 -> V_678 ) {
V_35 = - V_550 ;
goto V_609;
}
V_35 = F_42 ( V_549 -> V_28 ) ;
if ( V_35 )
goto V_609;
V_35 = F_139 ( V_7 , V_549 , V_92 . V_105 ) ;
if ( V_35 )
goto V_609;
#ifdef F_138
V_549 -> V_28 -> V_676 . V_679 = V_92 . V_105 ;
#endif
}
V_609:
F_115 ( V_549 -> V_28 ) ;
return V_35 ;
}
static int F_140 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
int V_35 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_666 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_557 ] )
V_666 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_666 )
V_92 . type = V_670 ;
else
V_92 . type = V_669 ;
}
if ( V_92 . type != V_670 &&
V_92 . type != V_669 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_373 )
return - V_550 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_670 ,
V_666 ) )
return - V_16 ;
F_113 ( V_549 -> V_28 ) ;
V_35 = F_42 ( V_549 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_141 ( V_7 , V_549 , V_92 . V_105 ,
V_92 . type == V_670 ,
V_666 , & V_92 . V_107 ) ;
F_115 ( V_549 -> V_28 ) ;
return V_35 ;
}
static int F_142 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
int V_35 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 * V_666 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_557 ] )
V_666 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_666 )
V_92 . type = V_670 ;
else
V_92 . type = V_669 ;
}
if ( V_92 . type != V_670 &&
V_92 . type != V_669 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_680 )
return - V_550 ;
F_113 ( V_549 -> V_28 ) ;
V_35 = F_42 ( V_549 -> V_28 ) ;
if ( V_92 . type == V_669 && V_666 &&
! ( V_7 -> V_18 . V_51 & V_324 ) )
V_35 = - V_672 ;
if ( ! V_35 )
V_35 = F_143 ( V_7 , V_549 , V_92 . V_105 ,
V_92 . type == V_670 ,
V_666 ) ;
#ifdef F_138
if ( ! V_35 ) {
if ( V_92 . V_105 == V_549 -> V_28 -> V_676 . V_677 )
V_549 -> V_28 -> V_676 . V_677 = - 1 ;
else if ( V_92 . V_105 == V_549 -> V_28 -> V_676 . V_679 )
V_549 -> V_28 -> V_676 . V_679 = - 1 ;
}
#endif
F_115 ( V_549 -> V_28 ) ;
return V_35 ;
}
static int F_144 ( struct V_4 * V_681 )
{
struct V_4 * V_45 ;
int V_682 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_597 )
return - V_16 ;
V_682 ++ ;
}
return V_682 ;
}
static struct V_683 * F_145 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_684 V_685 ;
struct V_4 * V_45 ;
struct V_683 * V_686 ;
int V_159 = 0 , V_682 , V_24 ;
if ( ! V_18 -> V_466 )
return F_3 ( - V_550 ) ;
if ( ! V_30 -> V_5 [ V_687 ] )
return F_3 ( - V_16 ) ;
V_685 = F_4 ( V_30 -> V_5 [ V_687 ] ) ;
if ( V_685 != V_688 &&
V_685 != V_689 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_690 ] )
return F_3 ( - V_16 ) ;
V_682 = F_144 ( V_30 -> V_5 [ V_690 ] ) ;
if ( V_682 < 0 )
return F_3 ( V_682 ) ;
if ( V_682 > V_18 -> V_466 )
return F_3 ( - V_691 ) ;
V_686 = F_38 ( sizeof( * V_686 ) + ( sizeof( struct V_692 ) * V_682 ) ,
V_135 ) ;
if ( ! V_686 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_686 -> V_693 [ V_159 ] . V_694 , F_23 ( V_45 ) , V_597 ) ;
V_159 ++ ;
}
V_686 -> V_695 = V_682 ;
V_686 -> V_685 = V_685 ;
return V_686 ;
}
static int F_146 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_683 * V_686 ;
int V_35 ;
if ( V_549 -> V_28 -> V_141 != V_142 &&
V_549 -> V_28 -> V_141 != V_144 )
return - V_550 ;
if ( ! V_549 -> V_28 -> V_551 )
return - V_16 ;
V_686 = F_145 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_686 ) )
return F_18 ( V_686 ) ;
V_35 = F_147 ( V_7 , V_549 , V_686 ) ;
F_41 ( V_686 ) ;
return V_35 ;
}
static int F_148 ( struct V_4 * V_5 [] ,
struct V_696 * V_697 )
{
bool V_698 = false ;
if ( ! F_22 ( V_5 [ V_699 ] ) ||
! F_22 ( V_5 [ V_700 ] ) ||
! F_22 ( V_5 [ V_701 ] ) ||
! F_22 ( V_5 [ V_702 ] ) )
return - V_16 ;
memset ( V_697 , 0 , sizeof( * V_697 ) ) ;
if ( V_5 [ V_703 ] ) {
V_697 -> V_704 = F_23 ( V_5 [ V_703 ] ) ;
V_697 -> V_705 = F_24 ( V_5 [ V_703 ] ) ;
if ( ! V_697 -> V_705 )
return - V_16 ;
V_698 = true ;
}
if ( V_5 [ V_699 ] ) {
V_697 -> V_706 = F_23 ( V_5 [ V_699 ] ) ;
V_697 -> V_707 = F_24 ( V_5 [ V_699 ] ) ;
V_698 = true ;
}
if ( ! V_698 )
return - V_16 ;
if ( V_5 [ V_700 ] ) {
V_697 -> V_708 = F_23 ( V_5 [ V_700 ] ) ;
V_697 -> V_709 = F_24 ( V_5 [ V_700 ] ) ;
}
if ( V_5 [ V_701 ] ) {
V_697 -> V_710 =
F_23 ( V_5 [ V_701 ] ) ;
V_697 -> V_711 =
F_24 ( V_5 [ V_701 ] ) ;
}
if ( V_5 [ V_702 ] ) {
V_697 -> V_712 =
F_23 ( V_5 [ V_702 ] ) ;
V_697 -> V_713 =
F_24 ( V_5 [ V_702 ] ) ;
}
if ( V_5 [ V_714 ] ) {
V_697 -> V_715 = F_23 ( V_5 [ V_714 ] ) ;
V_697 -> V_716 = F_24 ( V_5 [ V_714 ] ) ;
}
return 0 ;
}
static bool F_149 ( struct V_6 * V_7 ,
struct V_717 * V_137 )
{
struct V_1 * V_17 ;
bool V_506 = false ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_555 . V_55 )
continue;
V_137 -> V_530 = V_17 -> V_555 ;
V_506 = true ;
break;
}
return V_506 ;
}
static bool F_150 ( struct V_6 * V_7 ,
enum V_718 V_719 ,
enum V_280 V_52 )
{
if ( V_719 > V_720 )
return false ;
switch ( V_52 ) {
case V_721 :
if ( ! ( V_7 -> V_18 . V_291 & V_722 ) &&
V_719 == V_723 )
return false ;
return true ;
case V_450 :
case V_724 :
if ( V_719 == V_723 )
return false ;
return true ;
default:
return false ;
}
}
static int F_151 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_717 V_137 ;
int V_35 ;
if ( V_549 -> V_28 -> V_141 != V_142 &&
V_549 -> V_28 -> V_141 != V_144 )
return - V_550 ;
if ( ! V_7 -> V_351 -> V_375 )
return - V_550 ;
if ( V_17 -> V_551 )
return - V_725 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_726 ] ||
! V_30 -> V_5 [ V_727 ] ||
! V_30 -> V_5 [ V_703 ] )
return - V_16 ;
V_35 = F_148 ( V_30 -> V_5 , & V_137 . V_728 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_551 =
F_4 ( V_30 -> V_5 [ V_726 ] ) ;
V_137 . V_729 =
F_4 ( V_30 -> V_5 [ V_727 ] ) ;
V_35 = F_152 ( V_7 , V_137 . V_551 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_603 ] ) {
V_137 . V_604 = F_23 ( V_30 -> V_5 [ V_603 ] ) ;
V_137 . V_602 =
F_24 ( V_30 -> V_5 [ V_603 ] ) ;
if ( V_137 . V_602 == 0 ||
V_137 . V_602 > V_628 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_730 ] ) {
V_137 . V_731 = F_4 (
V_30 -> V_5 [ V_730 ] ) ;
if ( V_137 . V_731 != V_732 &&
V_137 . V_731 != V_733 &&
V_137 . V_731 != V_734 )
return - V_16 ;
}
V_137 . V_735 = ! ! V_30 -> V_5 [ V_736 ] ;
if ( V_30 -> V_5 [ V_737 ] ) {
V_137 . V_719 = F_4 (
V_30 -> V_5 [ V_737 ] ) ;
if ( ! F_150 ( V_7 , V_137 . V_719 ,
V_724 ) )
return - V_16 ;
} else
V_137 . V_719 = V_738 ;
V_35 = F_153 ( V_7 , V_30 , & V_137 . V_739 ,
V_740 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_741 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_742 ) )
return - V_550 ;
V_137 . V_743 = F_78 (
V_30 -> V_5 [ V_741 ] ) ;
}
if ( V_30 -> V_5 [ V_744 ] ) {
if ( V_549 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_745 =
F_34 ( V_30 -> V_5 [ V_744 ] ) ;
if ( V_137 . V_745 > 127 )
return - V_16 ;
if ( V_137 . V_745 != 0 &&
! ( V_7 -> V_18 . V_291 & V_746 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_747 ] ) {
T_2 V_24 ;
if ( V_549 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_747 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_748 = V_24 ;
if ( V_137 . V_748 != 0 &&
! ( V_7 -> V_18 . V_291 & V_749 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_532 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_530 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_555 . V_55 ) {
V_137 . V_530 = V_17 -> V_555 ;
} else if ( ! F_149 ( V_7 , & V_137 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_530 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_750 ] ) {
V_137 . V_751 =
F_34 ( V_30 -> V_5 [ V_750 ] ) ;
switch ( V_137 . V_751 ) {
case V_752 :
break;
case V_753 :
if ( ! ( V_7 -> V_18 . V_291 &
V_754 ) )
return - V_16 ;
break;
case V_755 :
if ( ! ( V_7 -> V_18 . V_291 &
V_756 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_137 . V_751 = V_752 ;
}
V_137 . V_757 = F_154 ( V_30 -> V_5 [ V_758 ] ) ;
if ( V_137 . V_757 && ! V_7 -> V_18 . V_363 [ V_759 ] )
return - V_550 ;
if ( V_30 -> V_5 [ V_687 ] ) {
V_137 . V_686 = F_145 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_686 ) )
return F_18 ( V_137 . V_686 ) ;
}
F_113 ( V_17 ) ;
V_35 = F_155 ( V_7 , V_549 , & V_137 ) ;
if ( ! V_35 ) {
V_17 -> V_555 = V_137 . V_530 ;
V_17 -> V_551 = V_137 . V_551 ;
V_17 -> V_530 = V_137 . V_530 ;
V_17 -> V_602 = V_137 . V_602 ;
memcpy ( V_17 -> V_604 , V_137 . V_604 , V_17 -> V_602 ) ;
}
F_115 ( V_17 ) ;
F_41 ( V_137 . V_686 ) ;
return V_35 ;
}
static int F_156 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_696 V_137 ;
int V_35 ;
if ( V_549 -> V_28 -> V_141 != V_142 &&
V_549 -> V_28 -> V_141 != V_144 )
return - V_550 ;
if ( ! V_7 -> V_351 -> V_760 )
return - V_550 ;
if ( ! V_17 -> V_551 )
return - V_16 ;
V_35 = F_148 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
V_35 = F_157 ( V_7 , V_549 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_158 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
return F_159 ( V_7 , V_549 , false ) ;
}
static int F_160 ( struct V_29 * V_30 ,
enum V_272 V_141 ,
struct V_761 * V_137 )
{
struct V_4 * V_51 [ V_762 + 1 ] ;
struct V_4 * V_611 ;
int V_614 ;
V_611 = V_30 -> V_5 [ V_763 ] ;
if ( V_611 ) {
struct V_764 * V_765 ;
V_765 = F_23 ( V_611 ) ;
V_137 -> V_766 = V_765 -> V_767 ;
V_137 -> V_768 = V_765 -> V_769 ;
V_137 -> V_768 &= V_137 -> V_766 ;
if ( ( V_137 -> V_766 |
V_137 -> V_768 ) & F_117 ( V_770 ) )
return - V_16 ;
return 0 ;
}
V_611 = V_30 -> V_5 [ V_771 ] ;
if ( ! V_611 )
return 0 ;
if ( F_33 ( V_51 , V_762 ,
V_611 , V_772 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_766 = F_117 ( V_773 ) |
F_117 ( V_774 ) |
F_117 ( V_775 ) |
F_117 ( V_776 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_766 = F_117 ( V_773 ) |
F_117 ( V_777 ) ;
break;
case V_145 :
V_137 -> V_766 = F_117 ( V_778 ) |
F_117 ( V_776 ) |
F_117 ( V_773 ) ;
default:
return - V_16 ;
}
for ( V_614 = 1 ; V_614 <= V_762 ; V_614 ++ ) {
if ( V_51 [ V_614 ] ) {
V_137 -> V_768 |= ( 1 << V_614 ) ;
if ( V_614 > V_779 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_161 ( struct V_31 * V_53 , struct V_780 * V_30 ,
int V_45 )
{
struct V_4 * V_244 ;
V_22 V_264 ;
T_3 V_781 ;
enum V_782 V_783 ;
V_244 = F_47 ( V_53 , V_45 ) ;
if ( ! V_244 )
return false ;
V_264 = F_162 ( V_30 ) ;
V_781 = V_264 < ( 1UL << 16 ) ? V_264 : 0 ;
if ( V_264 > 0 &&
F_28 ( V_53 , V_784 , V_264 ) )
return false ;
if ( V_781 > 0 &&
F_55 ( V_53 , V_785 , V_781 ) )
return false ;
switch ( V_30 -> V_786 ) {
case V_787 :
V_783 = V_788 ;
break;
case V_789 :
V_783 = V_790 ;
break;
default:
F_59 ( 1 ) ;
case V_791 :
V_783 = 0 ;
break;
case V_792 :
V_783 = V_793 ;
break;
case V_794 :
V_783 = V_795 ;
break;
case V_796 :
V_783 = V_797 ;
break;
}
if ( V_783 && F_29 ( V_53 , V_783 ) )
return false ;
if ( V_30 -> V_51 & V_798 ) {
if ( F_56 ( V_53 , V_799 , V_30 -> V_248 ) )
return false ;
if ( V_30 -> V_51 & V_800 &&
F_29 ( V_53 , V_801 ) )
return false ;
} else if ( V_30 -> V_51 & V_802 ) {
if ( F_56 ( V_53 , V_803 , V_30 -> V_248 ) )
return false ;
if ( F_56 ( V_53 , V_804 , V_30 -> V_805 ) )
return false ;
if ( V_30 -> V_51 & V_800 &&
F_29 ( V_53 , V_801 ) )
return false ;
}
F_48 ( V_53 , V_244 ) ;
return true ;
}
static bool F_163 ( struct V_31 * V_53 , T_2 V_767 , T_6 * signal ,
int V_806 )
{
void * V_45 ;
int V_159 = 0 ;
if ( ! V_767 )
return true ;
V_45 = F_47 ( V_53 , V_806 ) ;
if ( ! V_45 )
return false ;
for ( V_159 = 0 ; V_159 < V_807 ; V_159 ++ ) {
if ( ! ( V_767 & F_117 ( V_159 ) ) )
continue;
if ( F_56 ( V_53 , V_159 , signal [ V_159 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_164 ( struct V_31 * V_53 , V_22 V_52 , V_22 V_49 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_549 ,
const T_2 * V_666 , struct V_808 * V_809 )
{
void * V_283 ;
struct V_4 * V_810 , * V_811 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_666 ) ||
F_28 ( V_53 , V_293 , V_809 -> V_812 ) )
goto V_61;
V_810 = F_47 ( V_53 , V_813 ) ;
if ( ! V_810 )
goto V_61;
#define F_165 ( V_45 , T_7 , type ) do { \
BUILD_BUG_ON(sizeof(type) == sizeof(u64)); \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
#define F_166 ( V_45 , T_7 ) do { \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb, NL80211_STA_INFO_PAD)) \
goto nla_put_failure; \
} while (0)
F_165 ( V_814 , V_815 , V_22 ) ;
F_165 ( V_816 , V_817 , V_22 ) ;
if ( V_809 -> V_818 & ( F_117 ( V_819 ) |
F_117 ( V_820 ) ) &&
F_28 ( V_53 , V_819 ,
( V_22 ) V_809 -> V_821 ) )
goto V_61;
if ( V_809 -> V_818 & ( F_117 ( V_822 ) |
F_117 ( V_823 ) ) &&
F_28 ( V_53 , V_822 ,
( V_22 ) V_809 -> V_824 ) )
goto V_61;
F_166 ( V_825 , V_821 ) ;
F_166 ( V_826 , V_824 ) ;
F_165 ( V_827 , V_828 , T_3 ) ;
F_165 ( V_829 , V_830 , T_3 ) ;
F_165 ( V_831 , V_832 , T_2 ) ;
F_166 ( V_833 , V_834 ) ;
switch ( V_7 -> V_18 . V_835 ) {
case V_836 :
F_165 ( SIGNAL , signal , T_2 ) ;
F_165 ( V_837 , V_838 , T_2 ) ;
break;
default:
break;
}
if ( V_809 -> V_818 & F_117 ( V_839 ) ) {
if ( ! F_163 ( V_53 , V_809 -> V_840 ,
V_809 -> V_841 ,
V_839 ) )
goto V_61;
}
if ( V_809 -> V_818 & F_117 ( V_842 ) ) {
if ( ! F_163 ( V_53 , V_809 -> V_840 ,
V_809 -> V_843 ,
V_842 ) )
goto V_61;
}
if ( V_809 -> V_818 & F_117 ( V_844 ) ) {
if ( ! F_161 ( V_53 , & V_809 -> V_845 ,
V_844 ) )
goto V_61;
}
if ( V_809 -> V_818 & F_117 ( V_846 ) ) {
if ( ! F_161 ( V_53 , & V_809 -> V_847 ,
V_846 ) )
goto V_61;
}
F_165 ( V_848 , V_849 , V_22 ) ;
F_165 ( V_850 , V_851 , V_22 ) ;
F_165 ( V_852 , V_853 , V_22 ) ;
F_165 ( V_854 , V_855 , V_22 ) ;
F_165 ( V_856 , V_857 , V_22 ) ;
F_165 ( V_858 , V_859 , V_22 ) ;
F_165 ( V_860 , V_861 , V_22 ) ;
F_165 ( V_862 , V_863 , V_22 ) ;
F_165 ( V_864 , V_865 , V_22 ) ;
if ( V_809 -> V_818 & F_117 ( V_866 ) ) {
V_811 = F_47 ( V_53 , V_866 ) ;
if ( ! V_811 )
goto V_61;
if ( ( ( V_809 -> V_811 . V_51 & V_867 ) &&
F_29 ( V_53 , V_868 ) ) ||
( ( V_809 -> V_811 . V_51 & V_869 ) &&
F_29 ( V_53 , V_870 ) ) ||
( ( V_809 -> V_811 . V_51 & V_871 ) &&
F_29 ( V_53 , V_872 ) ) ||
F_56 ( V_53 , V_873 ,
V_809 -> V_811 . V_729 ) ||
F_55 ( V_53 , V_874 ,
V_809 -> V_811 . V_551 ) )
goto V_61;
F_48 ( V_53 , V_811 ) ;
}
if ( ( V_809 -> V_818 & F_117 ( V_875 ) ) &&
F_51 ( V_53 , V_875 ,
sizeof( struct V_764 ) ,
& V_809 -> V_765 ) )
goto V_61;
F_166 ( V_876 , V_877 ) ;
F_166 ( V_878 , V_879 ) ;
F_166 ( V_880 , V_881 ) ;
F_165 ( V_882 , V_883 , T_2 ) ;
#undef F_165
#undef F_166
if ( V_809 -> V_818 & F_117 ( V_884 ) ) {
struct V_4 * V_885 ;
int V_886 ;
V_885 = F_47 ( V_53 , V_884 ) ;
if ( ! V_885 )
goto V_61;
for ( V_886 = 0 ; V_886 < V_887 + 1 ; V_886 ++ ) {
struct V_888 * V_889 ;
struct V_4 * V_890 ;
V_889 = & V_809 -> V_891 [ V_886 ] ;
if ( ! V_889 -> V_818 )
continue;
V_890 = F_47 ( V_53 , V_886 + 1 ) ;
if ( ! V_890 )
goto V_61;
#define F_167 ( V_45 , T_7 ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb, NL80211_TID_STATS_PAD)) \
goto nla_put_failure; \
} while (0)
F_167 ( V_892 , V_893 ) ;
F_167 ( V_894 , V_895 ) ;
F_167 ( V_896 , V_897 ) ;
F_167 ( V_898 , V_899 ) ;
#undef F_167
F_48 ( V_53 , V_890 ) ;
}
F_48 ( V_53 , V_885 ) ;
}
F_48 ( V_53 , V_810 ) ;
if ( V_809 -> V_900 &&
F_51 ( V_53 , V_700 , V_809 -> V_900 ,
V_809 -> V_901 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int F_168 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_808 V_809 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_666 [ V_597 ] ;
int V_902 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_903;
}
if ( ! V_7 -> V_351 -> V_904 ) {
V_35 = - V_550 ;
goto V_903;
}
while ( 1 ) {
memset ( & V_809 , 0 , sizeof( V_809 ) ) ;
V_35 = F_169 ( V_7 , V_17 -> V_19 , V_902 ,
V_666 , & V_809 ) ;
if ( V_35 == - V_672 )
break;
if ( V_35 )
goto V_903;
if ( F_164 ( V_32 , V_905 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_7 , V_17 -> V_19 , V_666 ,
& V_809 ) < 0 )
goto V_609;
V_902 ++ ;
}
V_609:
V_34 -> args [ 2 ] = V_902 ;
V_35 = V_32 -> V_47 ;
V_903:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_170 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_808 V_809 ;
struct V_31 * V_53 ;
T_2 * V_666 = NULL ;
int V_35 ;
memset ( & V_809 , 0 , sizeof( V_809 ) ) ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_666 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( ! V_7 -> V_351 -> V_906 )
return - V_550 ;
V_35 = F_171 ( V_7 , V_549 , V_666 , & V_809 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_164 ( V_53 , V_905 ,
V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_7 , V_549 , V_666 , & V_809 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_172 ( struct V_18 * V_18 ,
struct V_761 * V_137 ,
enum V_907 V_908 )
{
if ( V_137 -> V_909 != - 1 &&
V_908 != V_910 )
return - V_16 ;
if ( V_137 -> V_911 != - 1 &&
V_908 != V_910 )
return - V_16 ;
if ( V_137 -> V_912 &&
! ( V_137 -> V_768 & F_117 ( V_777 ) ) &&
V_908 != V_910 )
return - V_16 ;
F_114 ( V_762 != 7 ) ;
switch ( V_908 ) {
case V_913 :
case V_914 :
if ( V_137 -> V_766 &
~ ( F_117 ( V_778 ) |
F_117 ( V_776 ) |
F_117 ( V_773 ) ) )
return - V_16 ;
break;
case V_915 :
case V_916 :
if ( ! ( V_137 -> V_768 & F_117 ( V_777 ) ) )
return - V_16 ;
V_137 -> V_766 &= ~ F_117 ( V_777 ) ;
break;
default:
if ( V_137 -> V_917 != V_918 )
return - V_16 ;
if ( V_137 -> V_861 )
return - V_16 ;
if ( V_137 -> V_919 & V_920 )
return - V_16 ;
}
if ( V_908 != V_915 &&
V_908 != V_916 ) {
if ( V_137 -> V_768 & F_117 ( V_777 ) )
return - V_16 ;
V_137 -> V_766 &= ~ F_117 ( V_777 ) ;
}
if ( V_908 != V_915 &&
V_908 != V_910 ) {
if ( V_137 -> V_919 & V_921 )
return - V_16 ;
if ( V_137 -> V_919 & V_922 )
return - V_16 ;
if ( V_137 -> V_923 )
return - V_16 ;
if ( V_137 -> V_924 || V_137 -> V_925 || V_137 -> V_926 )
return - V_16 ;
}
if ( V_908 != V_927 &&
V_908 != V_910 ) {
if ( V_137 -> V_928 )
return - V_16 ;
}
switch ( V_908 ) {
case V_929 :
if ( ! ( V_137 -> V_766 & F_117 ( V_773 ) ) )
return - V_550 ;
break;
case V_927 :
case V_910 :
if ( V_137 -> V_766 &
~ ( F_117 ( V_773 ) |
F_117 ( V_778 ) |
F_117 ( V_930 ) |
F_117 ( V_774 ) |
F_117 ( V_775 ) |
F_117 ( V_776 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_291 & V_931 ) &&
V_137 -> V_766 &
( F_117 ( V_778 ) |
F_117 ( V_930 ) ) )
return - V_16 ;
break;
case V_932 :
case V_933 :
if ( V_137 -> V_766 & ~ F_117 ( V_773 ) )
return - V_16 ;
break;
case V_915 :
if ( V_137 -> V_766 & ~ ( F_117 ( V_773 ) |
F_117 ( V_775 ) ) )
return - V_16 ;
if ( V_137 -> V_768 & F_117 ( V_773 ) &&
! V_137 -> V_923 )
return - V_16 ;
break;
case V_916 :
return - V_16 ;
case V_913 :
if ( V_137 -> V_919 & V_920 )
return - V_16 ;
break;
case V_914 :
if ( V_137 -> V_917 != V_918 &&
V_137 -> V_917 != V_934 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_173 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_935 = V_30 -> V_5 [ V_936 ] ;
struct V_25 * V_937 ;
int V_506 ;
if ( ! V_935 )
return NULL ;
V_937 = F_174 ( F_94 ( V_30 ) , F_4 ( V_935 ) ) ;
if ( ! V_937 )
return F_3 ( - V_23 ) ;
if ( ! V_937 -> V_28 || V_937 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_506 = - V_16 ;
goto error;
}
if ( V_937 -> V_28 -> V_141 != V_143 &&
V_937 -> V_28 -> V_141 != V_142 &&
V_937 -> V_28 -> V_141 != V_144 ) {
V_506 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_937 ) ) {
V_506 = - V_564 ;
goto error;
}
return V_937 ;
error:
F_175 ( V_937 ) ;
return F_3 ( V_506 ) ;
}
static int F_176 ( struct V_29 * V_30 ,
struct V_761 * V_137 )
{
struct V_4 * V_95 [ V_938 + 1 ] ;
struct V_4 * V_611 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_939 ] )
return 0 ;
V_611 = V_30 -> V_5 [ V_939 ] ;
V_35 = F_33 ( V_95 , V_938 , V_611 ,
V_940 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_941 ] )
V_137 -> V_942 = F_34 (
V_95 [ V_941 ] ) ;
if ( V_137 -> V_942 & ~ V_943 )
return - V_16 ;
if ( V_95 [ V_944 ] )
V_137 -> V_945 = F_34 ( V_95 [ V_944 ] ) ;
if ( V_137 -> V_945 & ~ V_946 )
return - V_16 ;
V_137 -> V_919 |= V_921 ;
return 0 ;
}
static int F_177 ( struct V_29 * V_30 ,
struct V_761 * V_137 )
{
if ( V_30 -> V_5 [ V_947 ] ) {
V_137 -> V_948 =
F_23 ( V_30 -> V_5 [ V_947 ] ) ;
V_137 -> V_949 =
F_24 ( V_30 -> V_5 [ V_947 ] ) ;
if ( V_137 -> V_949 < 2 )
return - V_16 ;
if ( V_137 -> V_949 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_950 ] ) {
V_137 -> V_951 =
F_23 ( V_30 -> V_5 [ V_950 ] ) ;
V_137 -> V_952 =
F_24 ( V_30 -> V_5 [ V_950 ] ) ;
if ( V_137 -> V_952 < 2 ||
V_137 -> V_952 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_178 ( struct V_29 * V_30 ,
struct V_761 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_953 ] )
V_137 -> V_912 = F_78 ( V_30 -> V_5 [ V_953 ] ) ;
if ( V_30 -> V_5 [ V_954 ] )
V_137 -> V_925 =
F_23 ( V_30 -> V_5 [ V_954 ] ) ;
if ( V_30 -> V_5 [ V_955 ] )
V_137 -> V_926 =
F_23 ( V_30 -> V_5 [ V_955 ] ) ;
V_35 = F_177 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_176 ( V_30 , V_137 ) ;
}
static int F_179 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_761 V_137 ;
T_2 * V_666 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_956 )
return - V_550 ;
if ( V_30 -> V_5 [ V_957 ] )
V_137 . V_912 = F_78 ( V_30 -> V_5 [ V_957 ] ) ;
if ( V_30 -> V_5 [ V_958 ] )
V_137 . V_909 =
F_78 ( V_30 -> V_5 [ V_958 ] ) ;
else
V_137 . V_909 = - 1 ;
if ( V_30 -> V_5 [ V_959 ] ) {
T_2 V_24 ;
V_24 = F_34 ( V_30 -> V_5 [ V_959 ] ) ;
if ( V_24 >= V_960 )
return - V_16 ;
V_137 . V_911 = V_24 ;
} else {
V_137 . V_911 = - 1 ;
}
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_666 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( V_30 -> V_5 [ V_961 ] ) {
V_137 . V_923 =
F_23 ( V_30 -> V_5 [ V_961 ] ) ;
V_137 . V_962 =
F_24 ( V_30 -> V_5 [ V_961 ] ) ;
}
if ( V_30 -> V_5 [ V_963 ] ) {
V_137 . V_964 =
F_78 ( V_30 -> V_5 [ V_963 ] ) ;
V_137 . V_919 |= V_922 ;
}
if ( V_30 -> V_5 [ V_965 ] ) {
V_137 . V_924 =
F_23 ( V_30 -> V_5 [ V_965 ] ) ;
V_137 . V_966 =
F_24 ( V_30 -> V_5 [ V_965 ] ) ;
}
if ( F_160 ( V_30 , V_549 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_967 ] ) {
V_137 . V_917 =
F_34 ( V_30 -> V_5 [ V_967 ] ) ;
if ( V_137 . V_917 >= V_968 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_969 ] ) {
V_137 . V_832 =
F_34 ( V_30 -> V_5 [ V_969 ] ) ;
if ( V_137 . V_832 >= V_970 )
return - V_16 ;
if ( V_30 -> V_5 [ V_971 ] ) {
V_137 . V_972 = F_78 (
V_30 -> V_5 [ V_971 ] ) ;
if ( V_137 . V_972 > V_973 )
return - V_16 ;
}
V_137 . V_919 |= V_920 ;
}
if ( V_30 -> V_5 [ V_974 ] ) {
enum V_975 V_976 = F_4 (
V_30 -> V_5 [ V_974 ] ) ;
if ( V_976 <= V_977 ||
V_976 > V_978 )
return - V_16 ;
V_137 . V_861 = V_976 ;
}
V_35 = F_178 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_928 = F_173 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_928 ) )
return F_18 ( V_137 . V_928 ) ;
switch ( V_549 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_550 ;
goto V_979;
}
V_35 = F_180 ( V_7 , V_549 , V_666 , & V_137 ) ;
V_979:
if ( V_137 . V_928 )
F_175 ( V_137 . V_928 ) ;
return V_35 ;
}
static int F_181 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
int V_35 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_761 V_137 ;
T_2 * V_666 = NULL ;
V_22 V_980 = F_117 ( V_778 ) |
F_117 ( V_930 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_377 )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_958 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_961 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_957 ] &&
! V_30 -> V_5 [ V_953 ] )
return - V_16 ;
V_666 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_137 . V_923 =
F_23 ( V_30 -> V_5 [ V_961 ] ) ;
V_137 . V_962 =
F_24 ( V_30 -> V_5 [ V_961 ] ) ;
V_137 . V_909 =
F_78 ( V_30 -> V_5 [ V_958 ] ) ;
if ( V_30 -> V_5 [ V_959 ] ) {
T_2 V_24 ;
V_24 = F_34 ( V_30 -> V_5 [ V_959 ] ) ;
if ( V_24 >= V_960 )
return - V_16 ;
V_137 . V_911 = V_24 ;
} else {
V_137 . V_911 =
V_549 -> V_28 -> V_141 == V_144 ;
}
if ( V_30 -> V_5 [ V_953 ] )
V_137 . V_912 = F_78 ( V_30 -> V_5 [ V_953 ] ) ;
else
V_137 . V_912 = F_78 ( V_30 -> V_5 [ V_957 ] ) ;
if ( ! V_137 . V_912 || V_137 . V_912 > V_973 )
return - V_16 ;
if ( V_30 -> V_5 [ V_963 ] ) {
V_137 . V_964 =
F_78 ( V_30 -> V_5 [ V_963 ] ) ;
V_137 . V_919 |= V_922 ;
}
if ( V_30 -> V_5 [ V_965 ] ) {
V_137 . V_924 =
F_23 ( V_30 -> V_5 [ V_965 ] ) ;
V_137 . V_966 =
F_24 ( V_30 -> V_5 [ V_965 ] ) ;
}
if ( V_30 -> V_5 [ V_954 ] )
V_137 . V_925 =
F_23 ( V_30 -> V_5 [ V_954 ] ) ;
if ( V_30 -> V_5 [ V_955 ] )
V_137 . V_926 =
F_23 ( V_30 -> V_5 [ V_955 ] ) ;
if ( V_30 -> V_5 [ V_981 ] ) {
V_137 . V_982 = true ;
V_137 . V_983 =
F_34 ( V_30 -> V_5 [ V_981 ] ) ;
}
if ( V_30 -> V_5 [ V_967 ] ) {
V_137 . V_917 =
F_34 ( V_30 -> V_5 [ V_967 ] ) ;
if ( V_137 . V_917 >= V_968 )
return - V_16 ;
}
V_35 = F_177 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_176 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_160 ( V_30 , V_549 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( ! ( V_137 . V_768 & F_117 ( V_775 ) ) ) {
V_137 . V_925 = NULL ;
V_137 . V_926 = NULL ;
}
F_114 ( V_762 != 7 ) ;
switch ( V_549 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) ||
! ( V_137 . V_768 & F_117 ( V_775 ) ) )
V_137 . V_919 &= ~ V_921 ;
if ( ( V_137 . V_768 & F_117 ( V_777 ) ) ||
V_30 -> V_5 [ V_953 ] )
return - V_16 ;
V_137 . V_766 &= ~ F_117 ( V_777 ) ;
if ( ! ( V_7 -> V_18 . V_291 &
V_931 ) &&
V_137 . V_766 & V_980 )
return - V_16 ;
if ( ! ( V_137 . V_766 & V_980 ) ) {
V_137 . V_766 |= V_980 ;
V_137 . V_768 |= V_980 ;
}
V_137 . V_928 = F_173 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_928 ) )
return F_18 ( V_137 . V_928 ) ;
break;
case V_145 :
V_137 . V_919 &= ~ V_921 ;
if ( V_137 . V_766 & F_117 ( V_930 ) )
return - V_16 ;
if ( ( V_137 . V_768 & F_117 ( V_777 ) ) ||
V_30 -> V_5 [ V_953 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_919 &= ~ V_921 ;
if ( V_137 . V_766 &
( F_117 ( V_930 ) |
F_117 ( V_778 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_768 & F_117 ( V_777 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) )
return - V_550 ;
if ( ! ( V_7 -> V_18 . V_51 & V_334 ) )
return - V_550 ;
V_137 . V_766 &= ~ F_117 ( V_773 ) ;
break;
default:
return - V_550 ;
}
V_35 = F_182 ( V_7 , V_549 , V_666 , & V_137 ) ;
if ( V_137 . V_928 )
F_175 ( V_137 . V_928 ) ;
return V_35 ;
}
static int F_183 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_984 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_30 -> V_5 [ V_557 ] )
V_137 . V_985 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( V_549 -> V_28 -> V_141 != V_142 &&
V_549 -> V_28 -> V_141 != V_143 &&
V_549 -> V_28 -> V_141 != V_145 &&
V_549 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_986 )
return - V_550 ;
if ( V_30 -> V_5 [ V_987 ] ) {
V_137 . V_988 =
F_34 ( V_30 -> V_5 [ V_987 ] ) ;
if ( V_137 . V_988 != V_989 >> 4 &&
V_137 . V_988 != V_990 >> 4 )
return - V_16 ;
} else {
V_137 . V_988 = V_990 >> 4 ;
}
if ( V_30 -> V_5 [ V_991 ] ) {
V_137 . V_992 =
F_78 ( V_30 -> V_5 [ V_991 ] ) ;
if ( V_137 . V_992 == 0 )
return - V_16 ;
} else {
V_137 . V_992 = V_993 ;
}
return F_184 ( V_7 , V_549 , & V_137 ) ;
}
static int F_185 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_549 ,
T_2 * V_994 , T_2 * V_995 ,
struct V_996 * V_997 )
{
void * V_283 ;
struct V_4 * V_998 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_999 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_994 ) ||
F_51 ( V_53 , V_1000 , V_597 , V_995 ) ||
F_28 ( V_53 , V_293 , V_997 -> V_812 ) )
goto V_61;
V_998 = F_47 ( V_53 , V_1001 ) ;
if ( ! V_998 )
goto V_61;
if ( ( V_997 -> V_818 & V_1002 ) &&
F_28 ( V_53 , V_1003 ,
V_997 -> V_1004 ) )
goto V_61;
if ( ( ( V_997 -> V_818 & V_1005 ) &&
F_28 ( V_53 , V_1006 , V_997 -> V_1007 ) ) ||
( ( V_997 -> V_818 & V_1008 ) &&
F_28 ( V_53 , V_1009 ,
V_997 -> V_1010 ) ) ||
( ( V_997 -> V_818 & V_1011 ) &&
F_28 ( V_53 , V_1012 ,
V_997 -> V_1013 ) ) ||
( ( V_997 -> V_818 & V_1014 ) &&
F_56 ( V_53 , V_1015 ,
V_997 -> V_51 ) ) ||
( ( V_997 -> V_818 & V_1016 ) &&
F_28 ( V_53 , V_1017 ,
V_997 -> V_1018 ) ) ||
( ( V_997 -> V_818 & V_1019 ) &&
F_56 ( V_53 , V_1020 ,
V_997 -> V_1021 ) ) )
goto V_61;
F_48 ( V_53 , V_998 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int F_186 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_996 V_997 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_994 [ V_597 ] ;
T_2 V_995 [ V_597 ] ;
int V_1022 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_1023 ) {
V_35 = - V_550 ;
goto V_903;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_550 ;
goto V_903;
}
while ( 1 ) {
V_35 = F_187 ( V_7 , V_17 -> V_19 , V_1022 , V_994 ,
V_995 , & V_997 ) ;
if ( V_35 == - V_672 )
break;
if ( V_35 )
goto V_903;
if ( F_185 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_17 -> V_19 , V_994 , V_995 ,
& V_997 ) < 0 )
goto V_609;
V_1022 ++ ;
}
V_609:
V_34 -> args [ 2 ] = V_1022 ;
V_35 = V_32 -> V_47 ;
V_903:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_188 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
int V_35 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_996 V_997 ;
struct V_31 * V_53 ;
T_2 * V_994 = NULL ;
T_2 V_995 [ V_597 ] ;
memset ( & V_997 , 0 , sizeof( V_997 ) ) ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_994 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( ! V_7 -> V_351 -> V_1024 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_145 )
return - V_550 ;
V_35 = F_189 ( V_7 , V_549 , V_994 , V_995 , & V_997 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_185 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_549 , V_994 , V_995 , & V_997 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_190 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 * V_994 = NULL ;
T_2 * V_995 = NULL ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1000 ] )
return - V_16 ;
V_994 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_995 = F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
if ( ! V_7 -> V_351 -> V_1025 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_145 )
return - V_550 ;
return F_191 ( V_7 , V_549 , V_994 , V_995 ) ;
}
static int F_192 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 * V_994 = NULL ;
T_2 * V_995 = NULL ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1000 ] )
return - V_16 ;
V_994 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_995 = F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
if ( ! V_7 -> V_351 -> V_379 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_145 )
return - V_550 ;
return F_193 ( V_7 , V_549 , V_994 , V_995 ) ;
}
static int F_194 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 * V_994 = NULL ;
if ( V_30 -> V_5 [ V_557 ] )
V_994 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( ! V_7 -> V_351 -> V_1026 )
return - V_550 ;
return F_195 ( V_7 , V_549 , V_994 ) ;
}
static int F_196 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
int V_35 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_996 V_997 ;
struct V_31 * V_53 ;
T_2 * V_994 = NULL ;
T_2 V_1027 [ V_597 ] ;
memset ( & V_997 , 0 , sizeof( V_997 ) ) ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_994 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( ! V_7 -> V_351 -> V_1028 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_145 )
return - V_550 ;
V_35 = F_197 ( V_7 , V_549 , V_994 , V_1027 , & V_997 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_185 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_549 , V_994 , V_1027 , & V_997 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_198 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_996 V_997 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_994 [ V_597 ] ;
T_2 V_1027 [ V_597 ] ;
int V_1022 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_1029 ) {
V_35 = - V_550 ;
goto V_903;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_550 ;
goto V_903;
}
while ( 1 ) {
V_35 = F_199 ( V_7 , V_17 -> V_19 , V_1022 , V_994 ,
V_1027 , & V_997 ) ;
if ( V_35 == - V_672 )
break;
if ( V_35 )
goto V_903;
if ( F_185 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_17 -> V_19 , V_994 , V_1027 ,
& V_997 ) < 0 )
goto V_609;
V_1022 ++ ;
}
V_609:
V_34 -> args [ 2 ] = V_1022 ;
V_35 = V_32 -> V_47 ;
V_903:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_200 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_1030 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_1031 = - 1 ;
V_137 . V_1032 = - 1 ;
V_137 . V_1033 = - 1 ;
V_137 . V_1034 = - 1 ;
V_137 . V_1035 = - 1 ;
V_137 . V_745 = - 1 ;
V_137 . V_748 = - 1 ;
if ( V_30 -> V_5 [ V_1036 ] )
V_137 . V_1031 =
F_34 ( V_30 -> V_5 [ V_1036 ] ) ;
if ( V_30 -> V_5 [ V_1037 ] )
V_137 . V_1032 =
F_34 ( V_30 -> V_5 [ V_1037 ] ) ;
if ( V_30 -> V_5 [ V_1038 ] )
V_137 . V_1033 =
F_34 ( V_30 -> V_5 [ V_1038 ] ) ;
if ( V_30 -> V_5 [ V_1039 ] ) {
V_137 . V_1040 =
F_23 ( V_30 -> V_5 [ V_1039 ] ) ;
V_137 . V_1041 =
F_24 ( V_30 -> V_5 [ V_1039 ] ) ;
}
if ( V_30 -> V_5 [ V_1042 ] )
V_137 . V_1034 = ! ! F_34 ( V_30 -> V_5 [ V_1042 ] ) ;
if ( V_30 -> V_5 [ V_1043 ] )
V_137 . V_1035 =
F_78 ( V_30 -> V_5 [ V_1043 ] ) ;
if ( V_30 -> V_5 [ V_744 ] ) {
if ( V_549 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_745 =
F_201 ( V_30 -> V_5 [ V_744 ] ) ;
if ( V_137 . V_745 < 0 )
return - V_16 ;
if ( V_137 . V_745 != 0 &&
! ( V_7 -> V_18 . V_291 & V_746 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_747 ] ) {
T_2 V_24 ;
if ( V_549 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_747 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_748 = V_24 ;
if ( V_137 . V_748 &&
! ( V_7 -> V_18 . V_291 & V_749 ) )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_383 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_142 &&
V_549 -> V_28 -> V_141 != V_144 )
return - V_550 ;
F_113 ( V_17 ) ;
V_35 = F_202 ( V_7 , V_549 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_203 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
bool V_1044 ;
enum V_1045 V_1046 ;
V_22 V_649 ;
if ( F_204 ( ! F_205 ( V_1047 ) ) )
return - V_1048 ;
if ( V_30 -> V_5 [ V_1049 ] )
V_1046 =
F_4 ( V_30 -> V_5 [ V_1049 ] ) ;
else
V_1046 = V_1050 ;
switch ( V_1046 ) {
case V_1050 :
case V_1051 :
if ( ! V_30 -> V_5 [ V_1052 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1052 ] ) ;
return F_206 ( V_138 , V_1046 ) ;
case V_1053 :
if ( V_30 -> V_5 [ V_648 ] ) {
V_649 = V_30 -> V_514 ;
V_1044 = ! ! V_30 -> V_5 [ V_1054 ] ;
} else {
V_649 = 0 ;
V_1044 = true ;
}
return F_207 ( V_1044 , V_649 ) ;
default:
return - V_16 ;
}
}
static int F_208 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_1055 V_1056 ;
int V_35 = 0 ;
void * V_283 ;
struct V_4 * V_998 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_550 ;
if ( ! V_7 -> V_351 -> V_1057 )
return - V_550 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1058 )
memcpy ( & V_1056 , & V_1059 , sizeof( V_1056 ) ) ;
else
V_35 = F_209 ( V_7 , V_549 , & V_1056 ) ;
F_115 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1060 ) ;
if ( ! V_283 )
goto V_609;
V_998 = F_47 ( V_53 , V_1061 ) ;
if ( ! V_998 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_55 ( V_53 , V_1062 ,
V_1056 . V_1063 ) ||
F_55 ( V_53 , V_1064 ,
V_1056 . V_1065 ) ||
F_55 ( V_53 , V_1066 ,
V_1056 . V_1067 ) ||
F_55 ( V_53 , V_1068 ,
V_1056 . V_1069 ) ||
F_56 ( V_53 , V_1070 ,
V_1056 . V_1071 ) ||
F_56 ( V_53 , V_1072 ,
V_1056 . V_1073 ) ||
F_56 ( V_53 , V_1074 ,
V_1056 . V_1075 ) ||
F_56 ( V_53 , V_1076 ,
V_1056 . V_1077 ) ||
F_28 ( V_53 , V_1078 ,
V_1056 . V_1079 ) ||
F_56 ( V_53 , V_1080 ,
V_1056 . V_1081 ) ||
F_28 ( V_53 , V_1082 ,
V_1056 . V_1083 ) ||
F_55 ( V_53 , V_1084 ,
V_1056 . V_1085 ) ||
F_28 ( V_53 , V_1086 ,
V_1056 . V_1087 ) ||
F_55 ( V_53 , V_1088 ,
V_1056 . V_1089 ) ||
F_55 ( V_53 , V_1090 ,
V_1056 . V_1091 ) ||
F_55 ( V_53 , V_1092 ,
V_1056 . V_1093 ) ||
F_56 ( V_53 , V_1094 ,
V_1056 . V_1095 ) ||
F_55 ( V_53 , V_1096 ,
V_1056 . V_1097 ) ||
F_56 ( V_53 , V_1098 ,
V_1056 . V_1099 ) ||
F_56 ( V_53 , V_1100 ,
V_1056 . V_1101 ) ||
F_28 ( V_53 , V_1102 ,
V_1056 . V_1103 ) ||
F_28 ( V_53 , V_1104 ,
V_1056 . V_1035 ) ||
F_28 ( V_53 , V_1105 ,
V_1056 . V_1106 ) ||
F_55 ( V_53 , V_1107 ,
V_1056 . V_1108 ) ||
F_55 ( V_53 , V_1109 ,
V_1056 . V_1110 ) ||
F_28 ( V_53 , V_1111 ,
V_1056 . V_1112 ) ||
F_55 ( V_53 , V_1113 ,
V_1056 . V_1114 ) ||
F_28 ( V_53 , V_1115 ,
V_1056 . V_1116 ) )
goto V_61;
F_48 ( V_53 , V_998 ) ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_609:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_210 ( const struct V_4 * V_611 , T_2 V_1117 , T_2 V_174 , bool * V_609 )
{
T_2 V_1118 = F_34 ( V_611 ) ;
if ( V_1118 < V_1117 || V_1118 > V_174 )
return - V_16 ;
* V_609 = V_1118 ;
return 0 ;
}
static int F_211 ( const struct V_4 * V_611 , T_2 V_1117 , T_2 V_174 , T_2 * V_609 )
{
T_2 V_1118 = F_34 ( V_611 ) ;
if ( V_1118 < V_1117 || V_1118 > V_174 )
return - V_16 ;
* V_609 = V_1118 ;
return 0 ;
}
static int F_212 ( const struct V_4 * V_611 , T_3 V_1117 , T_3 V_174 , T_3 * V_609 )
{
T_3 V_1118 = F_78 ( V_611 ) ;
if ( V_1118 < V_1117 || V_1118 > V_174 )
return - V_16 ;
* V_609 = V_1118 ;
return 0 ;
}
static int F_213 ( const struct V_4 * V_611 , V_22 V_1117 , V_22 V_174 , V_22 * V_609 )
{
V_22 V_1118 = F_4 ( V_611 ) ;
if ( V_1118 < V_1117 || V_1118 > V_174 )
return - V_16 ;
* V_609 = V_1118 ;
return 0 ;
}
static int F_214 ( const struct V_4 * V_611 , T_8 V_1117 , T_8 V_174 , T_8 * V_609 )
{
T_8 V_1118 = F_215 ( V_611 ) ;
if ( V_1118 < V_1117 || V_1118 > V_174 )
return - V_16 ;
* V_609 = V_1118 ;
return 0 ;
}
static int F_216 ( struct V_29 * V_30 ,
struct V_1055 * V_1119 ,
V_22 * V_1120 )
{
struct V_4 * V_95 [ V_1121 + 1 ] ;
V_22 V_767 = 0 ;
T_3 V_1035 ;
#define F_217 ( V_95 , V_1119 , T_9 , V_1117 , V_174 , V_767 , V_45 , T_10 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr], min, max, &cfg->param)) \
return -EINVAL; \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1061 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1121 ,
V_30 -> V_5 [ V_1061 ] ,
V_1122 ) )
return - V_16 ;
F_114 ( V_1121 > 32 ) ;
F_217 ( V_95 , V_1119 , V_1063 , 1 , 255 ,
V_767 , V_1062 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1065 , 1 , 255 ,
V_767 , V_1064 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1067 , 1 , 255 ,
V_767 , V_1066 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1069 , 0 , 255 ,
V_767 , V_1068 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1071 , 0 , 16 ,
V_767 , V_1070 ,
F_211 ) ;
F_217 ( V_95 , V_1119 , V_1073 , 1 , 255 ,
V_767 , V_1072 , F_211 ) ;
F_217 ( V_95 , V_1119 , V_1075 , 1 , 255 ,
V_767 , V_1074 ,
F_211 ) ;
F_217 ( V_95 , V_1119 , V_1077 , 0 , 1 ,
V_767 , V_1076 ,
F_210 ) ;
F_217 ( V_95 , V_1119 , V_1079 ,
1 , 255 , V_767 ,
V_1078 ,
F_213 ) ;
F_217 ( V_95 , V_1119 , V_1081 , 0 , 255 ,
V_767 , V_1080 ,
F_211 ) ;
F_217 ( V_95 , V_1119 , V_1083 , 1 , 65535 ,
V_767 , V_1082 ,
F_213 ) ;
F_217 ( V_95 , V_1119 , V_1085 , 1 , 65535 ,
V_767 , V_1084 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1087 ,
1 , 65535 , V_767 ,
V_1086 ,
F_213 ) ;
F_217 ( V_95 , V_1119 , V_1089 ,
1 , 65535 , V_767 ,
V_1088 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1091 ,
1 , 65535 , V_767 ,
V_1090 ,
F_212 ) ;
F_217 ( V_95 , V_1119 ,
V_1093 ,
1 , 65535 , V_767 ,
V_1092 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1095 , 0 , 4 ,
V_767 , V_1094 ,
F_211 ) ;
F_217 ( V_95 , V_1119 , V_1097 , 1 , 65535 ,
V_767 , V_1096 ,
F_212 ) ;
F_217 ( V_95 , V_1119 ,
V_1099 , 0 , 1 ,
V_767 , V_1098 ,
F_210 ) ;
F_217 ( V_95 , V_1119 , V_1101 , 0 , 1 ,
V_767 , V_1100 ,
F_210 ) ;
F_217 ( V_95 , V_1119 , V_1103 , - 255 , 0 ,
V_767 , V_1102 ,
F_214 ) ;
if ( V_95 [ V_1104 ] ) {
V_1035 = F_78 ( V_95 [ V_1104 ] ) ;
if ( V_1035 & ~ ( V_1123 |
V_1124 |
V_1125 ) )
return - V_16 ;
if ( ( V_1035 & V_1124 ) &&
( V_1035 & V_1125 ) )
return - V_16 ;
switch ( V_1035 & V_1123 ) {
case V_1126 :
case V_1127 :
if ( V_1035 & V_1125 )
return - V_16 ;
break;
case V_1128 :
case V_1129 :
if ( ! ( V_1035 & V_1125 ) )
return - V_16 ;
break;
}
V_1119 -> V_1035 = V_1035 ;
}
F_217 ( V_95 , V_1119 , V_1106 ,
1 , 65535 , V_767 ,
V_1105 ,
F_213 ) ;
F_217 ( V_95 , V_1119 , V_1108 , 1 , 65535 ,
V_767 , V_1107 ,
F_212 ) ;
F_217 ( V_95 , V_1119 ,
V_1110 ,
1 , 65535 , V_767 ,
V_1109 ,
F_212 ) ;
F_217 ( V_95 , V_1119 , V_1112 ,
V_1130 ,
V_978 ,
V_767 , V_1111 ,
F_213 ) ;
F_217 ( V_95 , V_1119 , V_1114 ,
0 , 65535 , V_767 ,
V_1113 , F_212 ) ;
F_217 ( V_95 , V_1119 , V_1116 , 0 , 0xffffffff ,
V_767 , V_1115 ,
F_213 ) ;
if ( V_1120 )
* V_1120 = V_767 ;
return 0 ;
#undef F_217
}
static int F_218 ( struct V_29 * V_30 ,
struct V_1131 * V_1132 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_4 * V_95 [ V_1133 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1134 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1133 ,
V_30 -> V_5 [ V_1134 ] ,
V_1135 ) )
return - V_16 ;
if ( V_95 [ V_1136 ] )
V_1132 -> V_1137 =
( F_34 ( V_95 [ V_1136 ] ) ) ?
V_1138 :
V_1139 ;
if ( V_95 [ V_1140 ] )
V_1132 -> V_1141 =
( F_34 ( V_95 [ V_1140 ] ) ) ?
V_1142 :
V_1143 ;
if ( V_95 [ V_1144 ] )
V_1132 -> V_1145 =
( F_34 ( V_95 [ V_1144 ] ) ) ?
V_1146 :
V_1147 ;
if ( V_95 [ V_1148 ] ) {
struct V_4 * V_1149 =
V_95 [ V_1148 ] ;
if ( ! F_22 ( V_1149 ) )
return - V_16 ;
V_1132 -> V_1150 = F_23 ( V_1149 ) ;
V_1132 -> V_1151 = F_24 ( V_1149 ) ;
}
if ( V_95 [ V_1152 ] &&
! ( V_7 -> V_18 . V_291 & V_1153 ) )
return - V_16 ;
V_1132 -> V_1154 = F_154 ( V_95 [ V_1152 ] ) ;
V_1132 -> V_1155 = F_154 ( V_95 [ V_1156 ] ) ;
V_1132 -> V_1157 = F_154 ( V_95 [ V_1158 ] ) ;
if ( V_1132 -> V_1157 )
V_1132 -> V_1154 = true ;
if ( V_95 [ V_1159 ] ) {
if ( ! V_1132 -> V_1154 )
return - V_16 ;
V_1132 -> V_1160 =
F_34 ( V_95 [ V_1159 ] ) ;
}
return 0 ;
}
static int F_219 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_1055 V_1119 ;
V_22 V_767 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_550 ;
if ( ! V_7 -> V_351 -> V_381 )
return - V_550 ;
V_35 = F_216 ( V_30 , & V_1119 , & V_767 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1058 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_220 ( V_7 , V_549 , V_767 , & V_1119 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_221 ( const struct V_1161 * V_1162 ,
struct V_31 * V_53 )
{
struct V_4 * V_1163 ;
unsigned int V_159 ;
if ( F_60 ( V_53 , V_1052 , V_1162 -> V_1164 ) ||
( V_1162 -> V_1165 &&
F_56 ( V_53 , V_1166 , V_1162 -> V_1165 ) ) )
goto V_61;
V_1163 = F_47 ( V_53 , V_1167 ) ;
if ( ! V_1163 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1162 -> V_1168 ; V_159 ++ ) {
struct V_4 * V_1169 ;
const struct V_1170 * V_1171 ;
const struct V_1172 * V_1173 ;
const struct V_1174 * V_1175 ;
unsigned int V_1176 ;
V_1171 = & V_1162 -> V_1177 [ V_159 ] ;
V_1173 = & V_1171 -> V_1173 ;
V_1175 = & V_1171 -> V_1175 ;
V_1169 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1169 )
goto V_61;
V_1176 = V_1173 -> V_1176 ;
if ( ! V_1176 )
V_1176 = F_222 ( V_1162 ,
V_1171 ) ;
if ( F_28 ( V_53 , V_1178 ,
V_1171 -> V_51 ) ||
F_28 ( V_53 , V_1179 ,
V_1173 -> V_1180 ) ||
F_28 ( V_53 , V_1181 ,
V_1173 -> V_1182 ) ||
F_28 ( V_53 , V_1183 ,
V_1176 ) ||
F_28 ( V_53 , V_1184 ,
V_1175 -> V_1185 ) ||
F_28 ( V_53 , V_1186 ,
V_1175 -> V_1187 ) ||
F_28 ( V_53 , V_1188 ,
V_1171 -> V_74 ) )
goto V_61;
F_48 ( V_53 , V_1169 ) ;
}
F_48 ( V_53 , V_1163 ) ;
return 0 ;
V_61:
return - V_505 ;
}
static int F_223 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1161 * V_1162 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1189 ) ;
if ( ! V_283 )
goto V_1190;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1191 ;
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1191 = V_18 -> V_490 &
V_491 ;
V_1162 = F_224 ( V_18 ) ;
if ( F_59 ( ! V_1162 && V_1191 ) ) {
F_75 ( V_53 ) ;
return - V_16 ;
}
if ( V_1162 &&
F_28 ( V_53 , V_26 , F_225 ( V_18 ) ) )
goto V_61;
}
if ( ! V_18 && F_226 () &&
F_28 ( V_53 , V_1049 ,
V_1051 ) )
goto V_61;
F_227 () ;
if ( ! V_1162 )
V_1162 = F_228 ( V_1047 ) ;
if ( F_221 ( V_1162 , V_53 ) )
goto V_1192;
F_229 () ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1192:
F_229 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_1190:
F_75 ( V_53 ) ;
return - V_505 ;
}
static int F_230 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 , struct V_18 * V_18 ,
const struct V_1161 * V_1162 )
{
void * V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1189 ) ;
if ( ! V_283 )
return - 1 ;
F_231 ( V_34 , V_283 , & V_38 ) ;
if ( F_221 ( V_1162 , V_53 ) )
goto V_61;
if ( ! V_18 && F_226 () &&
F_28 ( V_53 , V_1049 ,
V_1051 ) )
goto V_61;
if ( V_18 &&
F_28 ( V_53 , V_26 , F_225 ( V_18 ) ) )
goto V_61;
if ( V_18 && V_18 -> V_490 & V_491 &&
F_29 ( V_53 , V_492 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int F_232 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1161 * V_1162 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1193 , V_509 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1047 && V_509 == 0 ) {
V_35 = F_230 ( V_32 , V_34 , V_34 -> V_36 -> V_510 ,
V_511 , NULL ,
F_233 ( V_1047 ) ) ;
if ( V_35 < 0 )
goto V_903;
}
V_1193 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1162 = F_224 ( & V_7 -> V_18 ) ;
if ( ! V_1162 )
continue;
if ( ++ V_1193 <= V_509 )
continue;
V_35 = F_230 ( V_32 , V_34 , V_34 -> V_36 -> V_510 ,
V_511 , & V_7 -> V_18 , V_1162 ) ;
if ( V_35 < 0 ) {
V_1193 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1193 ;
V_35 = V_32 -> V_47 ;
V_903:
F_20 () ;
return V_35 ;
}
static int F_234 ( struct V_4 * V_95 [] ,
struct V_1170 * V_1171 )
{
struct V_1172 * V_1173 = & V_1171 -> V_1173 ;
struct V_1174 * V_1175 = & V_1171 -> V_1175 ;
if ( ! V_95 [ V_1178 ] )
return - V_16 ;
if ( ! V_95 [ V_1179 ] )
return - V_16 ;
if ( ! V_95 [ V_1181 ] )
return - V_16 ;
if ( ! V_95 [ V_1183 ] )
return - V_16 ;
if ( ! V_95 [ V_1186 ] )
return - V_16 ;
V_1171 -> V_51 = F_4 ( V_95 [ V_1178 ] ) ;
V_1173 -> V_1180 =
F_4 ( V_95 [ V_1179 ] ) ;
V_1173 -> V_1182 =
F_4 ( V_95 [ V_1181 ] ) ;
V_1173 -> V_1176 =
F_4 ( V_95 [ V_1183 ] ) ;
V_1175 -> V_1187 =
F_4 ( V_95 [ V_1186 ] ) ;
if ( V_95 [ V_1184 ] )
V_1175 -> V_1185 =
F_4 ( V_95 [ V_1184 ] ) ;
if ( V_95 [ V_1188 ] )
V_1171 -> V_74 =
F_4 ( V_95 [ V_1188 ] ) ;
return 0 ;
}
static int F_235 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1194 + 1 ] ;
struct V_4 * V_1169 ;
char * V_1164 ;
int V_1195 , V_1196 ;
V_22 V_1197 = 0 , V_1198 = 0 , V_1199 ;
enum V_1200 V_1165 = V_1201 ;
struct V_1161 * V_1202 ;
if ( ! V_30 -> V_5 [ V_1052 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1167 ] )
return - V_16 ;
V_1164 = F_23 ( V_30 -> V_5 [ V_1052 ] ) ;
if ( V_30 -> V_5 [ V_1166 ] )
V_1165 = F_34 ( V_30 -> V_5 [ V_1166 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1197 ++ ;
if ( V_1197 > V_1203 )
return - V_16 ;
}
if ( ! F_236 ( V_1164 ) )
return - V_16 ;
V_1199 = sizeof( struct V_1161 ) +
V_1197 * sizeof( struct V_1170 ) ;
V_1202 = F_38 ( V_1199 , V_135 ) ;
if ( ! V_1202 )
return - V_136 ;
V_1202 -> V_1168 = V_1197 ;
V_1202 -> V_1164 [ 0 ] = V_1164 [ 0 ] ;
V_1202 -> V_1164 [ 1 ] = V_1164 [ 1 ] ;
if ( F_237 ( V_1165 ) )
V_1202 -> V_1165 = V_1165 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1196 = F_96 ( V_95 , V_1194 ,
F_23 ( V_1169 ) , F_24 ( V_1169 ) ,
V_1204 ) ;
if ( V_1196 )
goto V_1205;
V_1196 = F_234 ( V_95 , & V_1202 -> V_1177 [ V_1198 ] ) ;
if ( V_1196 )
goto V_1205;
V_1198 ++ ;
if ( V_1198 > V_1203 ) {
V_1196 = - V_16 ;
goto V_1205;
}
}
return F_238 ( V_1202 , V_1206 ) ;
V_1205:
F_41 ( V_1202 ) ;
return V_1196 ;
}
static int F_239 ( struct V_4 * V_1207 )
{
struct V_4 * V_1208 , * V_1209 ;
int V_366 = 0 , V_1210 , V_1211 ;
F_39 (attr1, freqs, tmp1) {
V_366 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1208 != V_1209 &&
F_4 ( V_1208 ) == F_4 ( V_1209 ) )
return 0 ;
}
return V_366 ;
}
static bool F_240 ( struct V_18 * V_18 , enum V_289 V_1212 )
{
return V_1212 < V_362 && V_18 -> V_363 [ V_1212 ] ;
}
static int F_241 ( struct V_4 * V_611 , struct V_18 * V_18 ,
struct V_1213 * V_1214 )
{
struct V_4 * V_45 [ V_1215 + 1 ] ;
struct V_4 * V_1216 ;
int V_35 ;
bool V_27 = false ;
int V_159 ;
V_1216 = F_23 ( V_611 ) ;
if ( ! F_242 ( V_1216 , F_24 ( V_1216 ) ) )
return - V_16 ;
V_35 = F_96 ( V_45 , V_1215 , F_23 ( V_1216 ) ,
F_24 ( V_1216 ) , V_1217 ) ;
if ( V_35 )
return V_35 ;
for ( V_159 = 0 ; V_159 <= V_1215 ; V_159 ++ ) {
if ( V_45 [ V_159 ] ) {
if ( V_27 )
return - V_16 ;
V_27 = true ;
}
}
V_1214 -> V_1218 = V_1219 ;
if ( V_45 [ V_1220 ] )
V_1214 -> V_1218 = V_1220 ;
if ( V_45 [ V_1221 ] ) {
V_1214 -> V_1218 = V_1221 ;
V_1214 -> T_9 . V_1222 =
F_4 ( V_45 [ V_1221 ] ) ;
if ( ! F_240 ( V_18 , V_1214 -> T_9 . V_1222 ) )
return - V_16 ;
}
if ( V_45 [ V_1223 ] ) {
struct V_1224 * V_1225 ;
V_1225 = F_23 ( V_45 [ V_1223 ] ) ;
V_1214 -> V_1218 = V_1223 ;
V_1214 -> T_9 . V_1226 . V_290 = V_1225 -> V_290 ;
V_1214 -> T_9 . V_1226 . V_1227 = V_1225 -> V_1227 ;
if ( ! F_240 ( V_18 , V_1214 -> T_9 . V_1226 . V_290 ) )
return - V_16 ;
}
if ( V_1214 -> V_1218 == V_1219 )
return - V_16 ;
if ( ! ( V_18 -> V_495 & F_117 ( V_1214 -> V_1218 ) ) )
return - V_16 ;
return 0 ;
}
static int F_243 ( struct V_4 * * V_5 ,
T_2 * V_666 , T_2 * V_1228 )
{
int V_159 ;
if ( ! V_5 [ V_557 ] && ! V_5 [ V_1229 ] ) {
F_244 ( V_666 ) ;
F_244 ( V_1228 ) ;
V_666 [ 0 ] = 0x2 ;
V_1228 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_557 ] || ! V_5 [ V_1229 ] )
return - V_16 ;
memcpy ( V_666 , F_23 ( V_5 [ V_557 ] ) , V_597 ) ;
memcpy ( V_1228 , F_23 ( V_5 [ V_1229 ] ) , V_597 ) ;
if ( ! F_245 ( V_1228 ) ||
F_245 ( V_666 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_597 ; V_159 ++ )
V_666 [ V_159 ] &= V_1228 [ V_159 ] ;
return 0 ;
}
static int F_246 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
struct V_1230 * V_1231 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1232 = 0 , V_366 , V_159 ;
T_11 V_1151 ;
if ( ! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_351 -> V_1233 )
return - V_550 ;
if ( V_7 -> V_1234 || V_7 -> V_1235 ) {
V_35 = - V_554 ;
goto V_1236;
}
if ( V_30 -> V_5 [ V_1237 ] ) {
V_366 = F_239 (
V_30 -> V_5 [ V_1237 ] ) ;
if ( ! V_366 ) {
V_35 = - V_16 ;
goto V_1236;
}
} else {
V_366 = F_247 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1238 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1232 ++ ;
if ( V_1232 > V_18 -> V_309 ) {
V_35 = - V_16 ;
goto V_1236;
}
if ( V_30 -> V_5 [ V_700 ] )
V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
else
V_1151 = 0 ;
if ( V_1151 > V_18 -> V_313 ) {
V_35 = - V_16 ;
goto V_1236;
}
V_1231 = F_38 ( sizeof( * V_1231 )
+ sizeof( * V_1231 -> V_1239 ) * V_1232
+ sizeof( * V_1231 -> V_367 ) * V_366
+ V_1151 , V_135 ) ;
if ( ! V_1231 ) {
V_35 = - V_136 ;
goto V_1236;
}
if ( V_1232 )
V_1231 -> V_1239 = ( void * ) & V_1231 -> V_367 [ V_366 ] ;
V_1231 -> V_1232 = V_1232 ;
if ( V_1151 ) {
if ( V_1232 )
V_1231 -> V_1150 = ( void * ) ( V_1231 -> V_1239 + V_1232 ) ;
else
V_1231 -> V_1150 = ( void * ) ( V_1231 -> V_367 + V_366 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1237 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1240;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1231 -> V_367 [ V_159 ] = V_55 ;
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
V_1231 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1240;
}
V_1231 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1232 ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_628 ) {
V_35 = - V_16 ;
goto V_1240;
}
V_1231 -> V_1239 [ V_159 ] . V_602 = F_24 ( V_45 ) ;
memcpy ( V_1231 -> V_1239 [ V_159 ] . V_604 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_700 ] ) {
V_1231 -> V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
memcpy ( ( void * ) V_1231 -> V_1150 ,
F_23 ( V_30 -> V_5 [ V_700 ] ) ,
V_1231 -> V_1151 ) ;
}
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ )
if ( V_18 -> V_363 [ V_159 ] )
V_1231 -> V_1241 [ V_159 ] =
( 1 << V_18 -> V_363 [ V_159 ] -> V_261 ) - 1 ;
if ( V_30 -> V_5 [ V_1242 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_289 V_290 = F_248 ( V_45 ) ;
if ( V_290 < 0 || V_290 >= V_362 ) {
V_35 = - V_16 ;
goto V_1240;
}
if ( ! V_18 -> V_363 [ V_290 ] )
continue;
V_35 = F_249 ( V_18 -> V_363 [ V_290 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1231 -> V_1241 [ V_290 ] ) ;
if ( V_35 )
goto V_1240;
}
}
if ( V_30 -> V_5 [ V_1243 ] ) {
if ( ! F_116 ( V_18 ,
V_1244 ) ) {
V_35 = - V_550 ;
goto V_1240;
}
V_1231 -> V_1245 =
F_78 ( V_30 -> V_5 [ V_1243 ] ) ;
V_1231 -> V_1246 =
F_154 ( V_30 -> V_5 [ V_1247 ] ) ;
}
if ( V_30 -> V_5 [ V_1248 ] ) {
V_1231 -> V_51 = F_4 (
V_30 -> V_5 [ V_1248 ] ) ;
if ( ( V_1231 -> V_51 & V_1249 ) &&
! ( V_18 -> V_291 & V_1250 ) ) {
V_35 = - V_550 ;
goto V_1240;
}
if ( V_1231 -> V_51 & V_1251 ) {
if ( ! ( V_18 -> V_291 &
V_1252 ) ) {
V_35 = - V_550 ;
goto V_1240;
}
if ( V_17 -> V_149 ) {
V_35 = - V_550 ;
goto V_1240;
}
V_35 = F_243 ( V_30 -> V_5 ,
V_1231 -> V_666 ,
V_1231 -> V_1228 ) ;
if ( V_35 )
goto V_1240;
}
}
V_1231 -> V_1253 =
F_154 ( V_30 -> V_5 [ V_1254 ] ) ;
if ( V_30 -> V_5 [ V_557 ] )
memcpy ( V_1231 -> V_556 , F_23 ( V_30 -> V_5 [ V_557 ] ) ,
V_597 ) ;
else
F_250 ( V_1231 -> V_556 ) ;
V_1231 -> V_17 = V_17 ;
V_1231 -> V_18 = & V_7 -> V_18 ;
V_1231 -> V_1255 = V_1256 ;
V_7 -> V_1234 = V_1231 ;
V_35 = F_251 ( V_7 , V_1231 ) ;
if ( ! V_35 ) {
F_252 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_253 ( V_17 -> V_19 ) ;
} else {
V_1240:
V_7 -> V_1234 = NULL ;
F_41 ( V_1231 ) ;
}
V_1236:
return V_35 ;
}
static int F_254 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1257 )
return - V_550 ;
if ( V_7 -> V_1235 )
return 0 ;
if ( ! V_7 -> V_1234 )
return - V_672 ;
F_255 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_256 ( struct V_18 * V_18 , int V_1258 ,
struct V_1259 * V_1231 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_159 = 0 ;
struct V_4 * V_45 ;
if ( ! V_5 [ V_1260 ] ) {
V_22 V_1261 ;
if ( ! V_5 [ V_1262 ] )
return - V_16 ;
V_1261 = F_4 ( V_5 [ V_1262 ] ) ;
if ( ! V_1261 )
return - V_16 ;
V_1231 -> V_1263 [ 0 ] . V_1261 =
F_257 ( V_1261 , V_1264 ) ;
if ( ! V_1231 -> V_1263 [ 0 ] . V_1261 )
return - V_16 ;
if ( V_1231 -> V_1263 [ 0 ] . V_1261 >
V_18 -> V_321 )
V_1231 -> V_1263 [ 0 ] . V_1261 =
V_18 -> V_321 ;
return 0 ;
}
F_39 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1265 [ V_1266 + 1 ] ;
if ( F_59 ( V_159 >= V_1258 ) )
return - V_16 ;
V_35 = F_96 ( V_1265 , V_1266 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1267 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1265 [ V_1268 ] )
return - V_16 ;
V_1231 -> V_1263 [ V_159 ] . V_1261 =
F_4 ( V_1265 [ V_1268 ] ) ;
if ( ! V_1231 -> V_1263 [ V_159 ] . V_1261 ||
V_1231 -> V_1263 [ V_159 ] . V_1261 >
V_18 -> V_321 )
return - V_16 ;
if ( V_1265 [ V_1269 ] ) {
V_1231 -> V_1263 [ V_159 ] . V_1270 =
F_4 ( V_1265 [ V_1269 ] ) ;
if ( ! V_1231 -> V_1263 [ V_159 ] . V_1270 ||
( V_1231 -> V_1263 [ V_159 ] . V_1270 >
V_18 -> V_323 ) )
return - V_16 ;
} else if ( V_159 < V_1258 - 1 ) {
return - V_16 ;
}
V_159 ++ ;
}
if ( V_1231 -> V_1263 [ V_1258 - 1 ] . V_1270 )
return - V_16 ;
return 0 ;
}
static struct V_1259 *
F_258 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1259 * V_1231 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1232 = 0 , V_1271 = 0 , V_366 , V_159 , V_1258 = 0 ;
enum V_289 V_290 ;
T_11 V_1151 ;
struct V_4 * V_95 [ V_1272 + 1 ] ;
T_8 V_1273 = V_1274 ;
if ( ! F_22 ( V_5 [ V_700 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1237 ] ) {
V_366 = F_239 (
V_5 [ V_1237 ] ) ;
if ( ! V_366 )
return F_3 ( - V_16 ) ;
} else {
V_366 = F_247 ( V_18 ) ;
}
if ( V_5 [ V_1238 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1232 ++ ;
if ( V_1232 > V_18 -> V_311 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1275 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1276 ;
V_35 = F_96 ( V_95 , V_1272 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1277 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1278 ] ) {
V_1271 ++ ;
continue;
}
V_1276 = V_95 [ V_1279 ] ;
if ( V_1276 )
V_1273 = F_215 ( V_1276 ) ;
}
}
if ( ! V_1271 && V_1273 != V_1274 )
V_1271 = 1 ;
if ( V_1271 > V_18 -> V_317 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_700 ] )
V_1151 = F_24 ( V_5 [ V_700 ] ) ;
else
V_1151 = 0 ;
if ( V_1151 > V_18 -> V_315 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1260 ] ) {
if ( V_5 [ V_1262 ] )
return F_3 ( - V_16 ) ;
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1258 ++ ;
} else {
if ( ! V_5 [ V_1262 ] )
return F_3 ( - V_16 ) ;
V_1258 = 1 ;
}
if ( ! V_1258 || V_1258 > V_18 -> V_319 )
return F_3 ( - V_16 ) ;
V_1231 = F_38 ( sizeof( * V_1231 )
+ sizeof( * V_1231 -> V_1239 ) * V_1232
+ sizeof( * V_1231 -> V_1280 ) * V_1271
+ sizeof( * V_1231 -> V_1263 ) * V_1258
+ sizeof( * V_1231 -> V_367 ) * V_366
+ V_1151 , V_135 ) ;
if ( ! V_1231 )
return F_3 ( - V_136 ) ;
if ( V_1232 )
V_1231 -> V_1239 = ( void * ) & V_1231 -> V_367 [ V_366 ] ;
V_1231 -> V_1232 = V_1232 ;
if ( V_1151 ) {
if ( V_1232 )
V_1231 -> V_1150 = ( void * ) ( V_1231 -> V_1239 + V_1232 ) ;
else
V_1231 -> V_1150 = ( void * ) ( V_1231 -> V_367 + V_366 ) ;
}
if ( V_1271 ) {
if ( V_1231 -> V_1150 )
V_1231 -> V_1280 = ( void * ) ( V_1231 -> V_1150 + V_1151 ) ;
else if ( V_1232 )
V_1231 -> V_1280 =
( void * ) ( V_1231 -> V_1239 + V_1232 ) ;
else
V_1231 -> V_1280 =
( void * ) ( V_1231 -> V_367 + V_366 ) ;
}
V_1231 -> V_1271 = V_1271 ;
if ( V_1271 )
V_1231 -> V_1263 = ( void * ) ( V_1231 -> V_1280 +
V_1271 ) ;
else if ( V_1231 -> V_1150 )
V_1231 -> V_1263 = ( void * ) ( V_1231 -> V_1150 + V_1151 ) ;
else if ( V_1232 )
V_1231 -> V_1263 = ( void * ) ( V_1231 -> V_1239 + V_1232 ) ;
else
V_1231 -> V_1263 = ( void * ) ( V_1231 -> V_367 + V_366 ) ;
V_1231 -> V_1281 = V_1258 ;
V_159 = 0 ;
if ( V_5 [ V_1237 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1240;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1231 -> V_367 [ V_159 ] = V_55 ;
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
V_1231 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1240;
}
V_1231 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1232 ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_628 ) {
V_35 = - V_16 ;
goto V_1240;
}
V_1231 -> V_1239 [ V_159 ] . V_602 = F_24 ( V_45 ) ;
memcpy ( V_1231 -> V_1239 [ V_159 ] . V_604 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1275 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_604 , * V_1276 ;
V_35 = F_96 ( V_95 , V_1272 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1277 ) ;
if ( V_35 )
goto V_1240;
V_604 = V_95 [ V_1278 ] ;
if ( V_604 ) {
if ( F_59 ( V_159 >= V_1271 ) ) {
V_35 = - V_16 ;
goto V_1240;
}
if ( F_24 ( V_604 ) > V_628 ) {
V_35 = - V_16 ;
goto V_1240;
}
memcpy ( V_1231 -> V_1280 [ V_159 ] . V_604 . V_604 ,
F_23 ( V_604 ) , F_24 ( V_604 ) ) ;
V_1231 -> V_1280 [ V_159 ] . V_604 . V_602 =
F_24 ( V_604 ) ;
V_1231 -> V_1280 [ V_159 ] . V_1282 =
V_1273 ;
V_1276 = V_95 [ V_1279 ] ;
if ( V_1276 )
V_1231 -> V_1280 [ V_159 ] . V_1282 =
F_215 ( V_1276 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1271 )
V_1231 -> V_1280 [ 0 ] . V_1282 = V_1273 ;
V_1231 -> V_1283 = V_1284 ;
for ( V_159 = 0 ; V_159 < V_1271 ; V_159 ++ )
V_1231 -> V_1283 =
V_1117 ( V_1231 -> V_1280 [ V_159 ] . V_1282 ,
V_1231 -> V_1283 ) ;
} else {
V_1231 -> V_1283 = V_1274 ;
}
if ( V_1151 ) {
V_1231 -> V_1151 = V_1151 ;
memcpy ( ( void * ) V_1231 -> V_1150 ,
F_23 ( V_5 [ V_700 ] ) ,
V_1231 -> V_1151 ) ;
}
if ( V_5 [ V_1248 ] ) {
V_1231 -> V_51 = F_4 (
V_5 [ V_1248 ] ) ;
if ( ( V_1231 -> V_51 & V_1249 ) &&
! ( V_18 -> V_291 & V_1250 ) ) {
V_35 = - V_550 ;
goto V_1240;
}
if ( V_1231 -> V_51 & V_1251 ) {
V_22 V_1285 = V_1286 ;
if ( ! V_17 )
V_1285 = V_1287 ;
if ( ! ( V_18 -> V_291 & V_1285 ) ) {
V_35 = - V_550 ;
goto V_1240;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_550 ;
goto V_1240;
}
V_35 = F_243 ( V_5 , V_1231 -> V_666 ,
V_1231 -> V_1228 ) ;
if ( V_35 )
goto V_1240;
}
}
if ( V_5 [ V_1288 ] )
V_1231 -> V_1289 =
F_4 ( V_5 [ V_1288 ] ) ;
V_35 = F_256 ( V_18 , V_1258 , V_1231 , V_5 ) ;
if ( V_35 )
goto V_1240;
V_1231 -> V_1255 = V_1256 ;
return V_1231 ;
V_1240:
F_41 ( V_1231 ) ;
return F_3 ( V_35 ) ;
}
static int F_259 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_1259 * V_1290 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_423 )
return - V_550 ;
if ( V_7 -> V_1290 )
return - V_1048 ;
V_1290 = F_258 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_260 ( V_1290 ) ;
if ( V_35 )
goto V_903;
V_35 = F_261 ( V_7 , V_549 , V_1290 ) ;
if ( V_35 )
goto V_1240;
V_1290 -> V_549 = V_549 ;
V_1290 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_648 ] )
V_1290 -> V_649 = V_30 -> V_514 ;
F_262 ( V_7 -> V_1290 , V_1290 ) ;
F_263 ( V_7 , V_549 ,
V_1291 ) ;
return 0 ;
V_1240:
F_41 ( V_1290 ) ;
V_903:
return V_35 ;
}
static int F_264 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_1292 )
return - V_550 ;
return F_265 ( V_7 , false ) ;
}
static int F_266 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_529 V_530 ;
enum V_1200 V_1165 ;
unsigned int V_1293 ;
int V_35 ;
V_1165 = F_267 ( V_17 -> V_18 ) ;
if ( V_1165 == V_1201 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_530 ) ;
if ( V_35 )
return V_35 ;
if ( F_268 ( V_549 ) )
return - V_554 ;
if ( V_17 -> V_1294 )
return - V_554 ;
V_35 = F_269 ( V_17 -> V_18 , & V_530 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_270 ( V_17 -> V_18 , & V_530 ) )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1295 )
return - V_550 ;
V_1293 = F_271 ( & V_7 -> V_18 , & V_530 ) ;
if ( F_59 ( ! V_1293 ) )
V_1293 = V_1296 ;
V_35 = F_272 ( V_7 , V_549 , & V_530 , V_1293 ) ;
if ( ! V_35 ) {
V_17 -> V_530 = V_530 ;
V_17 -> V_1294 = true ;
V_17 -> V_1297 = V_1256 ;
V_17 -> V_1293 = V_1293 ;
}
return V_35 ;
}
static int F_273 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_1298 V_137 ;
static struct V_4 * V_1299 [ V_1300 + 1 ] ;
int V_35 ;
bool V_1301 = false ;
int V_47 , V_159 ;
V_22 V_1302 ;
if ( ! V_7 -> V_351 -> V_442 ||
! ( V_7 -> V_18 . V_51 & V_441 ) )
return - V_550 ;
switch ( V_549 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1301 = true ;
if ( ! V_17 -> V_551 )
return - V_1303 ;
break;
case V_146 :
if ( ! V_17 -> V_602 )
return - V_1303 ;
break;
case V_145 :
if ( ! V_17 -> V_1058 )
return - V_1303 ;
break;
default:
return - V_550 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_532 ] ||
! V_30 -> V_5 [ V_1304 ] )
return - V_16 ;
if ( V_1301 && ! V_30 -> V_5 [ V_1305 ] )
return - V_16 ;
V_1302 = F_4 ( V_30 -> V_5 [ V_1304 ] ) ;
if ( V_1302 > 255 )
return - V_16 ;
V_137 . V_1306 = V_1302 ;
if ( ! V_1301 )
goto V_1307;
V_35 = F_148 ( V_30 -> V_5 , & V_137 . V_1308 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1299 , V_1300 ,
V_30 -> V_5 [ V_1305 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_148 ( V_1299 , & V_137 . V_1309 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1299 [ V_1310 ] )
return - V_16 ;
V_47 = F_24 ( V_1299 [ V_1310 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1311 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1311 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1312 =
F_23 ( V_1299 [ V_1310 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1311 ; V_159 ++ ) {
T_3 V_1313 = V_137 . V_1312 [ V_159 ] ;
if ( V_1313 >= V_137 . V_1309 . V_707 )
return - V_16 ;
if ( V_137 . V_1309 . V_706 [ V_1313 ] != V_137 . V_1306 )
return - V_16 ;
}
if ( V_1299 [ V_1314 ] ) {
V_47 = F_24 ( V_1299 [ V_1314 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1315 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1315 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1316 =
F_23 ( V_1299 [ V_1314 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1315 ; V_159 ++ ) {
T_3 V_1313 = V_137 . V_1316 [ V_159 ] ;
if ( V_1313 >= V_137 . V_1309 . V_716 )
return - V_16 ;
if ( V_137 . V_1309 . V_715 [ V_1313 ] !=
V_137 . V_1306 )
return - V_16 ;
}
}
V_1307:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_530 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_530 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_269 ( V_17 -> V_18 ,
& V_137 . V_530 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_137 . V_1317 = true ;
if ( V_30 -> V_5 [ V_1318 ] )
V_137 . V_1319 = true ;
F_113 ( V_17 ) ;
V_35 = F_274 ( V_7 , V_549 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_275 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1320 * V_1321 )
{
struct V_1322 * V_355 = & V_1321 -> V_1323 ;
const struct V_1324 * V_1325 ;
void * V_283 ;
struct V_4 * V_1326 ;
F_43 ( V_17 ) ;
V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1327 ) ;
if ( ! V_283 )
return - 1 ;
F_231 ( V_34 , V_283 , & V_38 ) ;
if ( F_28 ( V_53 , V_293 , V_7 -> V_1328 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_596 ) )
goto V_61;
V_1326 = F_47 ( V_53 , V_1329 ) ;
if ( ! V_1326 )
goto V_61;
if ( ( ! F_276 ( V_355 -> V_556 ) &&
F_51 ( V_53 , V_1330 , V_597 , V_355 -> V_556 ) ) )
goto V_61;
F_227 () ;
if ( F_205 ( V_355 -> V_710 ) &&
F_29 ( V_53 , V_1331 ) )
goto V_1332;
V_1325 = F_228 ( V_355 -> V_1325 ) ;
if ( V_1325 ) {
if ( F_104 ( V_53 , V_1333 , V_1325 -> V_1334 ,
V_1335 ) )
goto V_1332;
if ( V_1325 -> V_47 && F_51 ( V_53 , V_1336 ,
V_1325 -> V_47 , V_1325 -> V_138 ) )
goto V_1332;
}
V_1325 = F_228 ( V_355 -> V_708 ) ;
if ( V_1325 && V_1325 -> V_1337 ) {
if ( F_104 ( V_53 , V_1338 , V_1325 -> V_1334 ,
V_1335 ) )
goto V_1332;
if ( V_1325 -> V_47 && F_51 ( V_53 , V_1339 ,
V_1325 -> V_47 , V_1325 -> V_138 ) )
goto V_1332;
}
F_229 () ;
if ( V_355 -> V_551 &&
F_55 ( V_53 , V_1340 , V_355 -> V_551 ) )
goto V_61;
if ( F_55 ( V_53 , V_1341 , V_355 -> V_964 ) ||
F_28 ( V_53 , V_1342 , V_355 -> V_1343 -> V_60 ) ||
F_28 ( V_53 , V_1344 , V_355 -> V_1345 ) ||
F_28 ( V_53 , V_1346 ,
F_277 ( V_1256 - V_1321 -> V_1347 ) ) )
goto V_61;
if ( V_1321 -> V_1348 &&
( F_104 ( V_53 , V_1349 ,
V_1321 -> V_1348 , V_1335 ) ||
F_51 ( V_53 , V_1350 , V_597 ,
V_1321 -> V_1351 ) ) )
goto V_61;
if ( V_1321 -> V_1352 &&
F_104 ( V_53 , V_1353 ,
V_1321 -> V_1352 , V_1335 ) )
goto V_61;
switch ( V_7 -> V_18 . V_835 ) {
case V_836 :
if ( F_28 ( V_53 , V_1354 , V_355 -> signal ) )
goto V_61;
break;
case V_1355 :
if ( F_56 ( V_53 , V_1356 , V_355 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1321 == V_17 -> V_149 &&
F_28 ( V_53 , V_1357 ,
V_1358 ) )
goto V_61;
break;
case V_146 :
if ( V_1321 == V_17 -> V_149 &&
F_28 ( V_53 , V_1357 ,
V_1359 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1326 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_1332:
F_229 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int F_278 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1320 * V_1233 ;
struct V_1 * V_17 ;
int V_509 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
F_279 ( & V_7 -> V_1360 ) ;
F_280 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1328 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_509 )
continue;
if ( F_275 ( V_32 , V_34 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_7 , V_17 , V_1233 ) < 0 ) {
V_105 -- ;
break;
}
}
F_281 ( & V_7 -> V_1360 ) ;
F_115 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_282 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_549 ,
bool V_1361 ,
struct V_1362 * V_1363 )
{
void * V_283 ;
struct V_4 * V_1364 ;
if ( ! V_1363 -> V_1343 && ! V_1361 )
return 0 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1365 ) ;
if ( ! V_283 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_549 -> V_20 ) )
goto V_61;
V_1364 = F_47 ( V_53 , V_1366 ) ;
if ( ! V_1364 )
goto V_61;
if ( V_1363 -> V_1343 &&
F_28 ( V_53 , V_1367 ,
V_1363 -> V_1343 -> V_60 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1368 ) &&
F_56 ( V_53 , V_1369 , V_1363 -> V_1370 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1371 ) &&
F_29 ( V_53 , V_1372 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1373 ) &&
F_104 ( V_53 , V_1374 ,
V_1363 -> time , V_1375 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1376 ) &&
F_104 ( V_53 , V_1377 ,
V_1363 -> V_1378 , V_1375 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1379 ) &&
F_104 ( V_53 , V_1380 ,
V_1363 -> V_1381 , V_1375 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1382 ) &&
F_104 ( V_53 , V_1383 ,
V_1363 -> V_1384 , V_1375 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1385 ) &&
F_104 ( V_53 , V_1386 ,
V_1363 -> V_1387 , V_1375 ) )
goto V_61;
if ( ( V_1363 -> V_818 & V_1388 ) &&
F_104 ( V_53 , V_1389 ,
V_1363 -> V_1390 , V_1375 ) )
goto V_61;
F_48 ( V_53 , V_1364 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int F_283 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1362 V_1363 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1391 = V_34 -> args [ 2 ] ;
int V_355 ;
bool V_1392 ;
V_355 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_355 )
return V_355 ;
V_1392 = V_38 . V_40 [ V_1393 ] ;
if ( ! V_17 -> V_19 ) {
V_355 = - V_16 ;
goto V_903;
}
if ( ! V_7 -> V_351 -> V_1394 ) {
V_355 = - V_550 ;
goto V_903;
}
while ( 1 ) {
V_355 = F_284 ( V_7 , V_17 -> V_19 , V_1391 , & V_1363 ) ;
if ( V_355 == - V_672 )
break;
if ( V_355 )
goto V_903;
if ( V_1363 . V_1343 &&
V_1363 . V_1343 -> V_51 & V_62 ) {
V_1391 ++ ;
continue;
}
if ( F_282 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_17 -> V_19 , V_1392 , & V_1363 ) < 0 )
goto V_609;
V_1391 ++ ;
}
V_609:
V_34 -> args [ 2 ] = V_1391 ;
V_355 = V_32 -> V_47 ;
V_903:
F_21 ( V_7 ) ;
return V_355 ;
}
static bool F_285 ( V_22 V_1395 )
{
return ! ( V_1395 & ~ ( V_1396 |
V_1397 ) ) ;
}
static int F_286 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_556 , * V_604 , * V_1150 = NULL , * V_1398 = NULL ;
int V_35 , V_602 , V_1151 = 0 , V_1399 = 0 ;
enum V_718 V_719 ;
struct V_93 V_92 ;
bool V_1400 ;
if ( ! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_737 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_603 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_532 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_669 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1401 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1402 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_159 ;
bool V_1403 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_338 ; V_159 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_339 [ V_159 ] ) {
V_1403 = true ;
break;
}
}
if ( ! V_1403 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_385 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_532 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_604 = F_23 ( V_30 -> V_5 [ V_603 ] ) ;
V_602 = F_24 ( V_30 -> V_5 [ V_603 ] ) ;
if ( V_30 -> V_5 [ V_700 ] ) {
V_1150 = F_23 ( V_30 -> V_5 [ V_700 ] ) ;
V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
}
V_719 = F_4 ( V_30 -> V_5 [ V_737 ] ) ;
if ( ! F_150 ( V_7 , V_719 , V_721 ) )
return - V_16 ;
if ( V_719 == V_723 &&
! V_30 -> V_5 [ V_1404 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1404 ] ) {
if ( V_719 != V_723 )
return - V_16 ;
V_1398 = F_23 ( V_30 -> V_5 [ V_1404 ] ) ;
V_1399 = F_24 ( V_30 -> V_5 [ V_1404 ] ) ;
if ( V_1399 < 4 )
return - V_16 ;
}
V_1400 = ! ! V_30 -> V_5 [ V_1405 ] ;
if ( V_1400 )
return 0 ;
F_113 ( V_549 -> V_28 ) ;
V_35 = F_287 ( V_7 , V_549 , V_55 , V_719 , V_556 ,
V_604 , V_602 , V_1150 , V_1151 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1398 , V_1399 ) ;
F_115 ( V_549 -> V_28 ) ;
return V_35 ;
}
static int F_153 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1406 * V_1407 ,
int V_1408 )
{
memset ( V_1407 , 0 , sizeof( * V_1407 ) ) ;
V_1407 -> V_1409 = V_30 -> V_5 [ V_1410 ] ;
if ( V_30 -> V_5 [ V_343 ] ) {
T_3 V_1411 ;
V_1411 = F_78 (
V_30 -> V_5 [ V_343 ] ) ;
V_1407 -> V_1412 = F_288 ( V_1411 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_342 ) &&
V_1411 != V_1413 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1414 ] )
V_1407 -> V_1415 = true ;
} else
V_1407 -> V_1412 = F_288 ( V_1413 ) ;
if ( V_30 -> V_5 [ V_1416 ] ) {
void * V_138 ;
int V_47 , V_159 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1416 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1416 ] ) ;
V_1407 -> V_1417 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1407 -> V_1417 > V_1408 )
return - V_16 ;
memcpy ( V_1407 -> V_1418 , V_138 , V_47 ) ;
for ( V_159 = 0 ; V_159 < V_1407 -> V_1417 ; V_159 ++ )
if ( ! F_289 (
& V_7 -> V_18 ,
V_1407 -> V_1418 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1419 ] ) {
V_1407 -> V_1420 =
F_4 ( V_30 -> V_5 [ V_1419 ] ) ;
if ( ! F_289 ( & V_7 -> V_18 ,
V_1407 -> V_1420 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1421 ] ) {
V_1407 -> V_1395 =
F_4 ( V_30 -> V_5 [ V_1421 ] ) ;
if ( ! F_285 ( V_1407 -> V_1395 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1422 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1422 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1422 ] ) ;
V_1407 -> V_1423 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1407 -> V_1423 > V_1424 )
return - V_16 ;
memcpy ( V_1407 -> V_1425 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_290 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1426 V_1427 = {} ;
const T_2 * V_556 , * V_604 ;
int V_35 , V_602 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_557 ] ||
! V_30 -> V_5 [ V_603 ] ||
! V_30 -> V_5 [ V_532 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_387 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_532 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_604 = F_23 ( V_30 -> V_5 [ V_603 ] ) ;
V_602 = F_24 ( V_30 -> V_5 [ V_603 ] ) ;
if ( V_30 -> V_5 [ V_700 ] ) {
V_1427 . V_1150 = F_23 ( V_30 -> V_5 [ V_700 ] ) ;
V_1427 . V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
}
if ( V_30 -> V_5 [ V_1428 ] ) {
enum V_1429 V_1430 =
F_4 ( V_30 -> V_5 [ V_1428 ] ) ;
if ( V_1430 == V_1431 )
V_1427 . V_1432 = true ;
else if ( V_1430 != V_1433 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1434 ] )
V_1427 . V_1435 = F_23 ( V_30 -> V_5 [ V_1434 ] ) ;
if ( F_154 ( V_30 -> V_5 [ V_1436 ] ) )
V_1427 . V_51 |= V_1437 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1427 . V_1438 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1427 . V_1438 ) ) ;
if ( V_30 -> V_5 [ V_954 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1427 . V_925 ,
F_23 ( V_30 -> V_5 [ V_954 ] ) ,
sizeof( V_1427 . V_925 ) ) ;
}
if ( F_154 ( V_30 -> V_5 [ V_1439 ] ) )
V_1427 . V_51 |= V_1440 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_1427 . V_1441 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_1427 . V_1441 ) ) ;
if ( V_30 -> V_5 [ V_955 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] )
return - V_16 ;
memcpy ( & V_1427 . V_926 ,
F_23 ( V_30 -> V_5 [ V_955 ] ) ,
sizeof( V_1427 . V_926 ) ) ;
}
if ( F_154 ( V_30 -> V_5 [ V_1442 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_291 &
V_1443 ) &&
( V_7 -> V_18 . V_291 & V_1444 ) ) &&
! F_116 ( & V_7 -> V_18 ,
V_1445 ) )
return - V_16 ;
V_1427 . V_51 |= V_1446 ;
}
V_35 = F_153 ( V_7 , V_30 , & V_1427 . V_739 , 1 ) ;
if ( ! V_35 ) {
F_113 ( V_549 -> V_28 ) ;
V_35 = F_291 ( V_7 , V_549 , V_55 , V_556 ,
V_604 , V_602 , & V_1427 ) ;
F_115 ( V_549 -> V_28 ) ;
}
return V_35 ;
}
static int F_292 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
const T_2 * V_1150 = NULL , * V_556 ;
int V_1151 = 0 , V_35 ;
T_3 V_992 ;
bool V_1400 ;
if ( ! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_991 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_389 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_992 = F_78 ( V_30 -> V_5 [ V_991 ] ) ;
if ( V_992 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_700 ] ) {
V_1150 = F_23 ( V_30 -> V_5 [ V_700 ] ) ;
V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
}
V_1400 = ! ! V_30 -> V_5 [ V_1405 ] ;
F_113 ( V_549 -> V_28 ) ;
V_35 = F_293 ( V_7 , V_549 , V_556 , V_1150 , V_1151 , V_992 ,
V_1400 ) ;
F_115 ( V_549 -> V_28 ) ;
return V_35 ;
}
static int F_294 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
const T_2 * V_1150 = NULL , * V_556 ;
int V_1151 = 0 , V_35 ;
T_3 V_992 ;
bool V_1400 ;
if ( ! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_991 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_391 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_992 = F_78 ( V_30 -> V_5 [ V_991 ] ) ;
if ( V_992 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_700 ] ) {
V_1150 = F_23 ( V_30 -> V_5 [ V_700 ] ) ;
V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
}
V_1400 = ! ! V_30 -> V_5 [ V_1405 ] ;
F_113 ( V_549 -> V_28 ) ;
V_35 = F_295 ( V_7 , V_549 , V_556 , V_1150 , V_1151 , V_992 ,
V_1400 ) ;
F_115 ( V_549 -> V_28 ) ;
return V_35 ;
}
static bool
F_296 ( struct V_6 * V_7 ,
int V_1447 [ V_362 ] ,
int V_1448 )
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
if ( V_240 -> V_262 [ V_159 ] . V_264 == V_1448 ) {
V_1447 [ V_290 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_297 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1449 V_1450 ;
struct V_18 * V_18 ;
struct V_130 * V_1451 = NULL ;
int V_35 ;
memset ( & V_1450 , 0 , sizeof( V_1450 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_603 ] ||
! F_24 ( V_30 -> V_5 [ V_603 ] ) )
return - V_16 ;
V_1450 . V_551 = 100 ;
if ( V_30 -> V_5 [ V_726 ] ) {
V_1450 . V_551 =
F_4 ( V_30 -> V_5 [ V_726 ] ) ;
if ( V_1450 . V_551 < 1 || V_1450 . V_551 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_393 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_146 )
return - V_550 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_557 ] ) {
V_1450 . V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( ! F_122 ( V_1450 . V_556 ) )
return - V_16 ;
}
V_1450 . V_604 = F_23 ( V_30 -> V_5 [ V_603 ] ) ;
V_1450 . V_602 = F_24 ( V_30 -> V_5 [ V_603 ] ) ;
if ( V_30 -> V_5 [ V_700 ] ) {
V_1450 . V_1150 = F_23 ( V_30 -> V_5 [ V_700 ] ) ;
V_1450 . V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1450 . V_530 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_298 ( & V_7 -> V_18 , & V_1450 . V_530 ,
V_146 ) )
return - V_16 ;
switch ( V_1450 . V_530 . V_533 ) {
case V_547 :
case V_548 :
case V_534 :
break;
case V_589 :
case V_590 :
if ( ! ( V_7 -> V_18 . V_291 & V_1452 ) )
return - V_16 ;
break;
case V_1453 :
case V_1454 :
case V_1455 :
if ( ! ( V_7 -> V_18 . V_291 & V_1452 ) )
return - V_16 ;
if ( ! F_116 ( & V_7 -> V_18 ,
V_1456 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1450 . V_1457 = ! ! V_30 -> V_5 [ V_1458 ] ;
V_1450 . V_735 = ! ! V_30 -> V_5 [ V_736 ] ;
if ( V_30 -> V_5 [ V_1039 ] ) {
T_2 * V_1241 =
F_23 ( V_30 -> V_5 [ V_1039 ] ) ;
int V_1459 =
F_24 ( V_30 -> V_5 [ V_1039 ] ) ;
struct V_239 * V_240 =
V_18 -> V_363 [ V_1450 . V_530 . V_55 -> V_290 ] ;
V_35 = F_249 ( V_240 , V_1241 , V_1459 ,
& V_1450 . V_1040 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1450 . V_1438 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1450 . V_1438 ) ) ;
if ( V_30 -> V_5 [ V_954 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1450 . V_925 ,
F_23 ( V_30 -> V_5 [ V_954 ] ) ,
sizeof( V_1450 . V_925 ) ) ;
}
if ( V_30 -> V_5 [ V_1460 ] &&
! F_296 ( V_7 , V_1450 . V_1447 ,
F_4 ( V_30 -> V_5 [ V_1460 ] ) ) )
return - V_16 ;
if ( V_1450 . V_735 && V_30 -> V_5 [ V_1461 ] ) {
bool V_132 = false ;
V_1451 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1461 ] ,
& V_132 ) ;
if ( F_17 ( V_1451 ) )
return F_18 ( V_1451 ) ;
if ( ( V_1450 . V_530 . V_533 != V_534 ) &&
V_132 ) {
F_299 ( V_1451 ) ;
return - V_16 ;
}
}
V_1450 . V_1409 =
F_154 ( V_30 -> V_5 [ V_1410 ] ) ;
V_1450 . V_1462 =
F_154 ( V_30 -> V_5 [ V_1463 ] ) ;
V_35 = F_300 ( V_7 , V_549 , & V_1450 , V_1451 ) ;
if ( V_35 )
F_299 ( V_1451 ) ;
return V_35 ;
}
static int F_301 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1464 )
return - V_550 ;
if ( V_549 -> V_28 -> V_141 != V_146 )
return - V_550 ;
return F_302 ( V_7 , V_549 , false ) ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
int V_1447 [ V_362 ] ;
V_22 V_1465 ;
int V_35 ;
if ( V_549 -> V_28 -> V_141 != V_146 &&
V_549 -> V_28 -> V_141 != V_145 &&
V_549 -> V_28 -> V_141 != V_152 )
return - V_550 ;
if ( ! V_7 -> V_351 -> V_433 )
return - V_550 ;
memset ( V_1447 , 0 , sizeof( V_1447 ) ) ;
if ( ! V_30 -> V_5 [ V_1460 ] )
return - V_16 ;
V_1465 = F_4 ( V_30 -> V_5 [ V_1460 ] ) ;
if ( ! F_296 ( V_7 , V_1447 , V_1465 ) )
return - V_16 ;
V_35 = F_304 ( V_7 , V_549 , V_1447 ) ;
return V_35 ;
}
static struct V_31 *
F_305 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1466 ,
V_22 V_49 , V_22 V_50 , enum V_280 V_52 ,
enum V_782 V_45 ,
const struct V_481 * V_30 ,
T_12 V_1467 )
{
struct V_31 * V_32 ;
void * V_283 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1466 + 100 , V_1467 ) ;
if ( ! V_32 )
return NULL ;
V_283 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_306 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1468 ,
V_30 -> V_1469 ) )
goto V_61;
if ( F_28 ( V_32 , V_1470 ,
V_30 -> V_1471 ) )
goto V_61;
}
if ( V_17 ) {
if ( F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) , V_596 ) )
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
F_306 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_307 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_280 V_52 ,
enum V_782 V_45 ,
int V_1472 ,
int V_1466 , T_12 V_1467 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_481 * V_30 ;
switch ( V_52 ) {
case V_1473 :
if ( F_59 ( V_1472 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1474 :
if ( F_59 ( V_1472 < 0 ||
V_1472 >= V_18 -> V_485 ) )
return NULL ;
V_30 = & V_18 -> V_487 [ V_1472 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_305 ( V_7 , V_17 , V_1466 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1467 ) ;
}
void F_308 ( struct V_31 * V_32 , T_12 V_1467 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1475 V_1476 = V_1477 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
if ( V_138 -> F_248 == V_483 )
V_1476 = V_1478 ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1476 , V_1467 ) ;
}
static int F_309 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_435 )
return - V_550 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1479 ] )
return - V_16 ;
V_7 -> V_1480 = V_30 ;
V_35 = F_310 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1479 ] ) ,
F_24 ( V_30 -> V_5 [ V_1479 ] ) ) ;
V_7 -> V_1480 = NULL ;
return V_35 ;
}
static int F_311 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1481 ;
void * V_138 = NULL ;
int V_1482 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1481 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_903;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_903;
}
V_1481 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1479 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1479 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1482 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1481 ) ;
if ( ! V_7 ) {
V_35 = - V_672 ;
goto V_903;
}
if ( ! V_7 -> V_351 -> V_1483 ) {
V_35 = - V_550 ;
goto V_903;
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_1473 ) ;
struct V_4 * V_1484 ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_1481 ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1484 = F_47 ( V_32 , V_1479 ) ;
if ( ! V_1484 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = F_312 ( V_7 , V_32 , V_34 , V_138 , V_1482 ) ;
F_48 ( V_32 , V_1484 ) ;
if ( V_35 == - V_91 || V_35 == - V_672 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_903;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1481 + 1 ;
V_903:
F_20 () ;
return V_35 ;
}
static int F_313 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1485 V_449 ;
struct V_18 * V_18 ;
struct V_130 * V_1451 = NULL ;
int V_35 ;
memset ( & V_449 , 0 , sizeof( V_449 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_603 ] ||
! F_24 ( V_30 -> V_5 [ V_603 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_737 ] ) {
V_449 . V_719 =
F_4 ( V_30 -> V_5 [ V_737 ] ) ;
if ( ! F_150 ( V_7 , V_449 . V_719 ,
V_450 ) )
return - V_16 ;
} else
V_449 . V_719 = V_738 ;
V_449 . V_735 = V_30 -> V_5 [ V_736 ] ;
V_35 = F_153 ( V_7 , V_30 , & V_449 . V_739 ,
V_740 ) ;
if ( V_35 )
return V_35 ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
V_18 = & V_7 -> V_18 ;
V_449 . V_1486 = - 1 ;
if ( V_30 -> V_5 [ V_1487 ] &&
( V_18 -> V_51 & V_330 ) ) {
V_449 . V_1486 =
F_78 ( V_30 -> V_5 [ V_1487 ] ) ;
}
if ( V_30 -> V_5 [ V_557 ] )
V_449 . V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
else if ( V_30 -> V_5 [ V_1488 ] )
V_449 . V_1489 =
F_23 ( V_30 -> V_5 [ V_1488 ] ) ;
V_449 . V_604 = F_23 ( V_30 -> V_5 [ V_603 ] ) ;
V_449 . V_602 = F_24 ( V_30 -> V_5 [ V_603 ] ) ;
if ( V_30 -> V_5 [ V_700 ] ) {
V_449 . V_1150 = F_23 ( V_30 -> V_5 [ V_700 ] ) ;
V_449 . V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
}
if ( V_30 -> V_5 [ V_1428 ] ) {
V_449 . V_1430 = F_4 ( V_30 -> V_5 [ V_1428 ] ) ;
if ( V_449 . V_1430 != V_1431 &&
V_449 . V_1430 != V_1433 )
return - V_16 ;
} else {
V_449 . V_1430 = V_1433 ;
}
if ( V_30 -> V_5 [ V_1434 ] )
V_449 . V_1435 =
F_23 ( V_30 -> V_5 [ V_1434 ] ) ;
if ( V_30 -> V_5 [ V_532 ] ) {
V_449 . V_1343 = F_44 (
V_18 , V_30 -> V_5 [ V_532 ] ) ;
if ( ! V_449 . V_1343 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1490 ] ) {
V_449 . V_1491 = F_44 (
V_18 , V_30 -> V_5 [ V_1490 ] ) ;
if ( ! V_449 . V_1491 )
return - V_16 ;
}
if ( V_449 . V_735 && V_30 -> V_5 [ V_1461 ] ) {
V_1451 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1461 ] , NULL ) ;
if ( F_17 ( V_1451 ) )
return F_18 ( V_1451 ) ;
}
if ( F_154 ( V_30 -> V_5 [ V_1436 ] ) )
V_449 . V_51 |= V_1437 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_449 . V_1438 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_449 . V_1438 ) ) ;
if ( V_30 -> V_5 [ V_954 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] ) {
F_299 ( V_1451 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_925 ,
F_23 ( V_30 -> V_5 [ V_954 ] ) ,
sizeof( V_449 . V_925 ) ) ;
}
if ( F_154 ( V_30 -> V_5 [ V_1439 ] ) )
V_449 . V_51 |= V_1440 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_449 . V_1441 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_449 . V_1441 ) ) ;
if ( V_30 -> V_5 [ V_955 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] ) {
F_299 ( V_1451 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_926 ,
F_23 ( V_30 -> V_5 [ V_955 ] ) ,
sizeof( V_449 . V_926 ) ) ;
}
if ( F_154 ( V_30 -> V_5 [ V_1442 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_291 &
V_1443 ) &&
( V_7 -> V_18 . V_291 & V_1444 ) ) &&
! F_116 ( & V_7 -> V_18 ,
V_1445 ) ) {
F_299 ( V_1451 ) ;
return - V_16 ;
}
V_449 . V_51 |= V_1446 ;
}
V_449 . V_757 = F_154 ( V_30 -> V_5 [ V_758 ] ) ;
if ( V_449 . V_757 && ! V_7 -> V_18 . V_363 [ V_759 ] ) {
F_299 ( V_1451 ) ;
return - V_550 ;
}
if ( V_30 -> V_5 [ V_496 ] ) {
if ( V_449 . V_556 ) {
F_299 ( V_1451 ) ;
return - V_16 ;
}
V_35 = F_241 ( V_30 -> V_5 [ V_496 ] ,
V_18 , & V_449 . V_1214 ) ;
if ( V_35 ) {
F_299 ( V_1451 ) ;
return V_35 ;
}
}
F_113 ( V_549 -> V_28 ) ;
V_35 = F_314 ( V_7 , V_549 , & V_449 , V_1451 ,
V_449 . V_1435 ) ;
F_115 ( V_549 -> V_28 ) ;
if ( V_35 )
F_299 ( V_1451 ) ;
return V_35 ;
}
static int F_315 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_3 V_1492 ;
int V_506 ;
if ( ! V_30 -> V_5 [ V_991 ] )
V_1492 = V_1493 ;
else
V_1492 = F_78 ( V_30 -> V_5 [ V_991 ] ) ;
if ( V_1492 == 0 )
return - V_16 ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
F_113 ( V_549 -> V_28 ) ;
V_506 = F_316 ( V_7 , V_549 , V_1492 , true ) ;
F_115 ( V_549 -> V_28 ) ;
return V_506 ;
}
static int F_317 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1494 ] ) {
V_22 V_1495 = F_4 ( V_30 -> V_5 [ V_1494 ] ) ;
V_2 = F_318 ( V_1495 ) ;
} else if ( V_30 -> V_5 [ V_1496 ] ) {
V_22 V_1497 = F_4 ( V_30 -> V_5 [ V_1496 ] ) ;
V_2 = F_319 ( V_1497 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_320 ( V_7 , V_2 ) ;
F_321 ( V_2 ) ;
return V_35 ;
}
static int F_322 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
int (* F_323)( struct V_18 * V_18 , struct V_25 * V_549 ,
struct V_1498 * V_1499 ) = NULL ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1498 V_1499 ;
memset ( & V_1499 , 0 , sizeof( struct V_1498 ) ) ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1500 ] )
return - V_16 ;
V_1499 . V_1501 = F_23 ( V_30 -> V_5 [ V_1500 ] ) ;
V_1499 . V_556 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
switch ( V_30 -> V_1502 -> V_52 ) {
case V_1503 :
F_323 = V_7 -> V_351 -> V_397 ;
break;
case V_1504 :
F_323 = V_7 -> V_351 -> V_399 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_323 )
return - V_550 ;
return F_323 ( & V_7 -> V_18 , V_549 , & V_1499 ) ;
}
static int F_324 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
if ( V_549 -> V_28 -> V_141 != V_147 &&
V_549 -> V_28 -> V_141 != V_148 )
return - V_550 ;
if ( ! V_7 -> V_351 -> V_401 )
return - V_550 ;
return F_325 ( V_7 , V_549 ) ;
}
static int F_326 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 V_1505 , V_1506 ;
V_22 V_1507 = 0 ;
T_3 V_1508 ;
T_2 * V_1509 ;
bool V_1510 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_418 )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_1511 ] ||
! V_30 -> V_5 [ V_1512 ] ||
! V_30 -> V_5 [ V_1513 ] ||
! V_30 -> V_5 [ V_700 ] ||
! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_1509 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_1505 = F_34 ( V_30 -> V_5 [ V_1511 ] ) ;
V_1508 = F_78 ( V_30 -> V_5 [ V_1512 ] ) ;
V_1506 = F_34 ( V_30 -> V_5 [ V_1513 ] ) ;
V_1510 = F_154 ( V_30 -> V_5 [ V_1514 ] ) ;
if ( V_30 -> V_5 [ V_1515 ] )
V_1507 =
F_4 ( V_30 -> V_5 [ V_1515 ] ) ;
return F_327 ( V_7 , V_549 , V_1509 , V_1505 ,
V_1506 , V_1508 , V_1507 ,
V_1510 ,
F_23 ( V_30 -> V_5 [ V_700 ] ) ,
F_24 ( V_30 -> V_5 [ V_700 ] ) ) ;
}
static int F_328 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
enum V_1516 V_1517 ;
T_2 * V_1509 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_420 )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_1518 ] ||
! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_1517 = F_34 ( V_30 -> V_5 [ V_1518 ] ) ;
V_1509 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
return F_329 ( V_7 , V_549 , V_1509 , V_1517 ) ;
}
static int F_330 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
struct V_529 V_530 ;
struct V_31 * V_53 ;
void * V_283 ;
T_1 V_664 ;
V_22 V_1245 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_532 ] ||
! V_30 -> V_5 [ V_1519 ] )
return - V_16 ;
V_1245 = F_4 ( V_30 -> V_5 [ V_1519 ] ) ;
if ( ! V_7 -> V_351 -> V_404 ||
! ( V_7 -> V_18 . V_51 & V_403 ) )
return - V_550 ;
if ( V_1245 < V_1520 ||
V_1245 > V_7 -> V_18 . V_454 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_530 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1521 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_674;
}
V_35 = F_331 ( V_7 , V_17 , V_530 . V_55 ,
V_1245 , & V_664 ) ;
if ( V_35 )
goto V_674;
if ( F_104 ( V_53 , V_1522 , V_664 ,
V_596 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_674:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_332 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
T_1 V_664 ;
if ( ! V_30 -> V_5 [ V_1522 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1523 )
return - V_550 ;
V_664 = F_5 ( V_30 -> V_5 [ V_1522 ] ) ;
return F_333 ( V_7 , V_17 , V_664 ) ;
}
static V_22 F_334 ( struct V_239 * V_240 ,
T_2 * V_1241 , T_2 V_1524 )
{
T_2 V_159 ;
V_22 V_767 = 0 ;
for ( V_159 = 0 ; V_159 < V_1524 ; V_159 ++ ) {
int V_244 = ( V_1241 [ V_159 ] & 0x7f ) * 5 ;
int V_1525 ;
for ( V_1525 = 0 ; V_1525 < V_240 -> V_261 ; V_1525 ++ ) {
struct V_243 * V_1526 =
& V_240 -> V_262 [ V_1525 ] ;
if ( V_244 == V_1526 -> V_264 ) {
V_767 |= 1 << V_1525 ;
break;
}
}
if ( V_1525 == V_240 -> V_261 )
return 0 ;
}
return V_767 ;
}
static bool F_335 ( struct V_239 * V_240 ,
T_2 * V_1241 , T_2 V_1524 ,
T_2 V_248 [ V_1527 ] )
{
T_2 V_159 ;
memset ( V_248 , 0 , V_1527 ) ;
for ( V_159 = 0 ; V_159 < V_1524 ; V_159 ++ ) {
int V_1525 , V_1528 ;
V_1525 = V_1241 [ V_159 ] / 8 ;
V_1528 = F_117 ( V_1241 [ V_159 ] % 8 ) ;
if ( ( V_1525 < 0 ) || ( V_1525 >= V_1527 ) )
return false ;
if ( V_240 -> V_245 . V_248 . V_1529 [ V_1525 ] & V_1528 )
V_248 [ V_1525 ] |= V_1528 ;
else
return false ;
}
return true ;
}
static T_3 F_336 ( T_2 V_1530 )
{
T_3 V_1531 = 0 ;
switch ( V_1530 ) {
case V_1532 :
break;
case V_1533 :
V_1531 = 0x00FF ;
break;
case V_1534 :
V_1531 = 0x01FF ;
break;
case V_1535 :
V_1531 = 0x03FF ;
break;
default:
break;
}
return V_1531 ;
}
static void F_337 ( T_3 V_1530 ,
T_3 V_1536 [ V_1537 ] )
{
T_2 V_805 ;
for ( V_805 = 0 ; V_805 < V_1537 ; V_805 ++ ) {
V_1536 [ V_805 ] = F_336 ( V_1530 & 0x03 ) ;
V_1530 >>= 2 ;
}
}
static bool F_338 ( struct V_239 * V_240 ,
struct V_1538 * V_845 ,
T_3 V_248 [ V_1537 ] )
{
T_3 V_1539 = F_339 ( V_240 -> V_255 . V_258 . V_1539 ) ;
T_3 V_1540 [ V_1537 ] = {} ;
T_2 V_159 ;
if ( ! V_240 -> V_255 . V_256 )
return false ;
memset ( V_248 , 0 , sizeof( T_3 ) * V_1537 ) ;
F_337 ( V_1539 , V_1540 ) ;
for ( V_159 = 0 ; V_159 < V_1537 ; V_159 ++ ) {
if ( ( V_1540 [ V_159 ] & V_845 -> V_248 [ V_159 ] ) == V_845 -> V_248 [ V_159 ] )
V_248 [ V_159 ] = V_845 -> V_248 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_340 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1541 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1542 V_767 ;
int V_134 , V_159 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_4 * V_1543 ;
struct V_239 * V_240 ;
T_3 V_1544 ;
if ( ! V_7 -> V_351 -> V_406 )
return - V_550 ;
memset ( & V_767 , 0 , sizeof( V_767 ) ) ;
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ ) {
V_240 = V_7 -> V_18 . V_363 [ V_159 ] ;
if ( ! V_240 )
continue;
V_767 . V_1545 [ V_159 ] . V_1546 = ( 1 << V_240 -> V_261 ) - 1 ;
memcpy ( V_767 . V_1545 [ V_159 ] . V_1547 ,
V_240 -> V_245 . V_248 . V_1529 ,
sizeof( V_767 . V_1545 [ V_159 ] . V_1547 ) ) ;
if ( ! V_240 -> V_255 . V_256 )
continue;
V_1544 = F_339 ( V_240 -> V_255 . V_258 . V_1539 ) ;
F_337 ( V_1544 , V_767 . V_1545 [ V_159 ] . V_258 ) ;
}
if ( ! V_30 -> V_5 [ V_1548 ] )
goto V_609;
F_114 ( V_1549 > V_1527 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_289 V_290 = F_248 ( V_1543 ) ;
int V_35 ;
if ( V_290 < 0 || V_290 >= V_362 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_290 ] ;
if ( V_240 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1541 , F_23 ( V_1543 ) ,
F_24 ( V_1543 ) , V_1550 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1551 ] ) {
V_767 . V_1545 [ V_290 ] . V_1546 = F_334 (
V_240 ,
F_23 ( V_95 [ V_1551 ] ) ,
F_24 ( V_95 [ V_1551 ] ) ) ;
if ( ( V_767 . V_1545 [ V_290 ] . V_1546 == 0 ) &&
F_24 ( V_95 [ V_1551 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1552 ] ) {
if ( ! F_335 (
V_240 ,
F_23 ( V_95 [ V_1552 ] ) ,
F_24 ( V_95 [ V_1552 ] ) ,
V_767 . V_1545 [ V_290 ] . V_1547 ) )
return - V_16 ;
}
if ( V_95 [ V_1553 ] ) {
if ( ! F_338 (
V_240 ,
F_23 ( V_95 [ V_1553 ] ) ,
V_767 . V_1545 [ V_290 ] . V_258 ) )
return - V_16 ;
}
if ( V_95 [ V_1554 ] ) {
V_767 . V_1545 [ V_290 ] . V_1555 =
F_34 ( V_95 [ V_1554 ] ) ;
if ( V_767 . V_1545 [ V_290 ] . V_1555 > V_1556 )
return - V_16 ;
}
if ( V_767 . V_1545 [ V_290 ] . V_1546 == 0 ) {
if ( ! ( V_7 -> V_18 . V_363 [ V_290 ] -> V_245 . V_246 ||
V_7 -> V_18 . V_363 [ V_290 ] -> V_255 . V_256 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_1527 ; V_159 ++ )
if ( V_767 . V_1545 [ V_290 ] . V_1547 [ V_159 ] )
goto V_609;
for ( V_159 = 0 ; V_159 < V_1537 ; V_159 ++ )
if ( V_767 . V_1545 [ V_290 ] . V_258 [ V_159 ] )
goto V_609;
return - V_16 ;
}
}
V_609:
return F_341 ( V_7 , V_549 , NULL , & V_767 ) ;
}
static int F_342 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
T_3 V_1557 = V_277 | V_1558 ;
if ( ! V_30 -> V_5 [ V_1559 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_276 ] )
V_1557 = F_78 ( V_30 -> V_5 [ V_276 ] ) ;
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
return - V_550 ;
}
if ( ! V_7 -> V_351 -> V_408 )
return - V_550 ;
return F_343 ( V_17 , V_30 -> V_514 , V_1557 ,
F_23 ( V_30 -> V_5 [ V_1559 ] ) ,
F_24 ( V_30 -> V_5 [ V_1559 ] ) ) ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
struct V_529 V_530 ;
int V_35 ;
void * V_283 = NULL ;
T_1 V_664 ;
struct V_31 * V_53 = NULL ;
struct V_1560 V_137 = {
. V_1561 =
V_30 -> V_5 [ V_1562 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1563 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_408 )
return - V_550 ;
switch ( V_17 -> V_141 ) {
case V_154 :
if ( ! V_30 -> V_5 [ V_532 ] )
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
return - V_550 ;
}
if ( V_30 -> V_5 [ V_1519 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1564 = F_4 ( V_30 -> V_5 [ V_1519 ] ) ;
if ( V_137 . V_1564 < V_1520 ||
V_137 . V_1564 > V_7 -> V_18 . V_454 )
return - V_16 ;
}
V_137 . V_1565 = V_30 -> V_5 [ V_456 ] ;
if ( V_137 . V_1565 && ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1253 = F_154 ( V_30 -> V_5 [ V_1254 ] ) ;
V_530 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_532 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_530 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_530 . V_55 && V_137 . V_1565 )
return - V_16 ;
V_137 . V_1566 = F_23 ( V_30 -> V_5 [ V_1563 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1563 ] ) ;
if ( V_30 -> V_5 [ V_1567 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1567 ] ) ;
int V_159 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1568 = V_47 / sizeof( T_3 ) ;
V_137 . V_1569 =
F_23 ( V_30 -> V_5 [ V_1567 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1568 ; V_159 ++ ) {
if ( V_137 . V_1569 [ V_159 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1561 ) {
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1570 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_674;
}
}
V_137 . V_55 = V_530 . V_55 ;
V_35 = F_345 ( V_7 , V_17 , & V_137 , & V_664 ) ;
if ( V_35 )
goto V_674;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1522 , V_664 ,
V_596 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_674:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_346 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
T_1 V_664 ;
if ( ! V_30 -> V_5 [ V_1522 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_410 )
return - V_550 ;
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
return - V_550 ;
}
V_664 = F_5 ( V_30 -> V_5 [ V_1522 ] ) ;
return F_347 ( V_7 , V_17 , V_664 ) ;
}
static int F_348 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 V_1571 ;
bool V_282 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1572 ] )
return - V_16 ;
V_1571 = F_4 ( V_30 -> V_5 [ V_1572 ] ) ;
if ( V_1571 != V_1573 && V_1571 != V_1574 )
return - V_16 ;
V_17 = V_549 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1575 )
return - V_550 ;
V_282 = ( V_1571 == V_1574 ) ? true : false ;
if ( V_282 == V_17 -> V_1576 )
return 0 ;
V_35 = F_349 ( V_7 , V_549 , V_282 , V_17 -> V_1577 ) ;
if ( ! V_35 )
V_17 -> V_1576 = V_282 ;
return V_35 ;
}
static int F_350 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
enum V_1578 V_1571 ;
struct V_1 * V_17 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_31 * V_53 ;
void * V_283 ;
int V_35 ;
V_17 = V_549 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1575 )
return - V_550 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1579 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_674;
}
if ( V_17 -> V_1576 )
V_1571 = V_1574 ;
else
V_1571 = V_1573 ;
if ( F_28 ( V_53 , V_1572 , V_1571 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_674:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_351 ( struct V_29 * V_30 ,
V_22 V_244 , V_22 V_1580 , V_22 V_1581 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
if ( V_244 > 100 || V_1581 > V_1582 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1583 )
return - V_550 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_550 ;
return F_352 ( V_7 , V_549 , V_244 , V_1580 , V_1581 ) ;
}
static int F_353 ( struct V_29 * V_30 ,
T_8 V_1584 , V_22 V_1585 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
if ( V_1584 > 0 )
return - V_16 ;
if ( V_1584 == 0 )
V_1585 = 0 ;
if ( ! V_7 -> V_351 -> V_1586 )
return - V_550 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_550 ;
return F_354 ( V_7 , V_549 , V_1584 , V_1585 ) ;
}
static int F_355 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1587 + 1 ] ;
struct V_4 * V_1588 ;
int V_35 ;
V_1588 = V_30 -> V_5 [ V_1589 ] ;
if ( ! V_1588 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1587 , V_1588 ,
V_1590 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1591 ] &&
V_5 [ V_1592 ] ) {
T_8 V_1584 = F_215 ( V_5 [ V_1591 ] ) ;
V_22 V_1585 = F_4 ( V_5 [ V_1592 ] ) ;
return F_353 ( V_30 , V_1584 , V_1585 ) ;
}
if ( V_5 [ V_1593 ] &&
V_5 [ V_1594 ] &&
V_5 [ V_1595 ] ) {
V_22 V_244 = F_4 ( V_5 [ V_1593 ] ) ;
V_22 V_1580 = F_4 ( V_5 [ V_1594 ] ) ;
V_22 V_1581 = F_4 ( V_5 [ V_1595 ] ) ;
return F_351 ( V_30 , V_244 , V_1580 , V_1581 ) ;
}
return - V_16 ;
}
static int F_356 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1596 V_1132 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1132 . V_530 ) ;
if ( V_35 )
return V_35 ;
return F_357 ( V_7 , V_549 , & V_1132 ) ;
}
static int F_358 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
return F_359 ( V_7 , V_549 ) ;
}
static int F_360 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1055 V_1119 ;
struct V_1131 V_1132 ;
int V_35 ;
memcpy ( & V_1119 , & V_1059 , sizeof( V_1119 ) ) ;
memcpy ( & V_1132 , & V_1597 , sizeof( V_1132 ) ) ;
if ( V_30 -> V_5 [ V_1061 ] ) {
V_35 = F_216 ( V_30 , & V_1119 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_627 ] ||
! F_24 ( V_30 -> V_5 [ V_627 ] ) )
return - V_16 ;
V_1132 . V_1598 = F_23 ( V_30 -> V_5 [ V_627 ] ) ;
V_1132 . V_1058 = F_24 ( V_30 -> V_5 [ V_627 ] ) ;
if ( V_30 -> V_5 [ V_1460 ] &&
! F_296 ( V_7 , V_1132 . V_1447 ,
F_4 ( V_30 -> V_5 [ V_1460 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_726 ] ) {
V_1132 . V_551 =
F_4 ( V_30 -> V_5 [ V_726 ] ) ;
if ( V_1132 . V_551 < 10 ||
V_1132 . V_551 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_727 ] ) {
V_1132 . V_729 =
F_4 ( V_30 -> V_5 [ V_727 ] ) ;
if ( V_1132 . V_729 < 1 || V_1132 . V_729 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1134 ] ) {
V_35 = F_218 ( V_30 , & V_1132 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1132 . V_1154 )
V_1119 . V_1077 = false ;
if ( V_30 -> V_5 [ V_532 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1132 . V_530 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1132 . V_530 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_1039 ] ) {
T_2 * V_1241 = F_23 ( V_30 -> V_5 [ V_1039 ] ) ;
int V_1459 =
F_24 ( V_30 -> V_5 [ V_1039 ] ) ;
struct V_239 * V_240 ;
if ( ! V_1132 . V_530 . V_55 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_1132 . V_530 . V_55 -> V_290 ] ;
V_35 = F_249 ( V_240 , V_1241 , V_1459 ,
& V_1132 . V_1040 ) ;
if ( V_35 )
return V_35 ;
}
return F_361 ( V_7 , V_549 , & V_1132 , & V_1119 ) ;
}
static int F_362 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
return F_363 ( V_7 , V_549 ) ;
}
static int F_364 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1599 * V_189 = V_7 -> V_18 . V_1600 ;
struct V_4 * V_1601 , * V_1602 ;
int V_159 , V_1603 ;
if ( ! V_189 -> V_219 )
return 0 ;
V_1601 = F_47 ( V_53 , V_228 ) ;
if ( ! V_1601 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_189 -> V_219 ; V_159 ++ ) {
V_1602 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1602 )
return - V_91 ;
V_1603 = V_189 -> V_1604 [ V_159 ] . V_1605 ;
if ( F_51 ( V_53 , V_1606 , F_257 ( V_1603 , 8 ) ,
V_189 -> V_1604 [ V_159 ] . V_767 ) ||
F_51 ( V_53 , V_1607 , V_1603 ,
V_189 -> V_1604 [ V_159 ] . V_1608 ) ||
F_28 ( V_53 , V_1609 ,
V_189 -> V_1604 [ V_159 ] . V_1610 ) )
return - V_91 ;
F_48 ( V_53 , V_1602 ) ;
}
F_48 ( V_53 , V_1601 ) ;
return 0 ;
}
static int F_365 ( struct V_31 * V_53 ,
struct V_1611 * V_188 )
{
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_366 ( V_53 , V_1612 , V_188 -> V_1613 ) ||
F_366 ( V_53 , V_1614 , V_188 -> V_994 ) ||
F_51 ( V_53 , V_1615 , V_597 , V_188 -> V_1616 ) ||
F_55 ( V_53 , V_1617 , V_188 -> V_1618 ) ||
F_55 ( V_53 , V_1619 , V_188 -> V_1620 ) ||
F_51 ( V_53 , V_192 ,
V_188 -> V_1621 , V_188 -> V_1622 ) ||
F_28 ( V_53 , V_197 ,
V_188 -> V_1623 ) ||
F_51 ( V_53 , V_199 ,
V_188 -> V_1624 , V_188 -> V_1625 ) ||
F_51 ( V_53 , V_1626 ,
F_257 ( V_188 -> V_1624 , 8 ) , V_188 -> V_1627 ) )
return - V_91 ;
if ( V_188 -> V_1628 . V_47 &&
F_51 ( V_53 , V_194 ,
sizeof( V_188 -> V_1628 ) , & V_188 -> V_1628 ) )
return - V_91 ;
if ( V_188 -> V_1629 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_188 -> V_1629 ) + V_188 -> V_1630 ,
& V_188 -> V_1629 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_367 ( struct V_31 * V_53 ,
struct V_1259 * V_1427 )
{
struct V_4 * V_1631 , * V_1207 , * V_1632 , * V_1633 , * V_1263 , * V_1634 ;
int V_159 ;
if ( ! V_1427 )
return 0 ;
V_1631 = F_47 ( V_53 , V_230 ) ;
if ( ! V_1631 )
return - V_91 ;
if ( V_1427 -> V_1281 == 1 &&
F_28 ( V_53 , V_1262 ,
V_1427 -> V_1263 [ 0 ] . V_1261 * 1000 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1288 , V_1427 -> V_1289 ) )
return - V_91 ;
V_1207 = F_47 ( V_53 , V_1237 ) ;
if ( ! V_1207 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1427 -> V_366 ; V_159 ++ )
F_28 ( V_53 , V_159 , V_1427 -> V_367 [ V_159 ] -> V_60 ) ;
F_48 ( V_53 , V_1207 ) ;
if ( V_1427 -> V_1271 ) {
V_1632 = F_47 ( V_53 , V_1275 ) ;
for ( V_159 = 0 ; V_159 < V_1427 -> V_1271 ; V_159 ++ ) {
V_1633 = F_47 ( V_53 , V_159 ) ;
F_51 ( V_53 , V_1278 ,
V_1427 -> V_1280 [ V_159 ] . V_604 . V_602 ,
V_1427 -> V_1280 [ V_159 ] . V_604 . V_604 ) ;
F_48 ( V_53 , V_1633 ) ;
}
F_48 ( V_53 , V_1632 ) ;
}
V_1263 = F_47 ( V_53 , V_1260 ) ;
if ( ! V_1263 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1427 -> V_1281 ; V_159 ++ ) {
V_1634 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1634 ||
F_28 ( V_53 , V_1268 ,
V_1427 -> V_1263 [ V_159 ] . V_1261 ) ||
( V_1427 -> V_1263 [ V_159 ] . V_1270 &&
F_28 ( V_53 , V_1269 ,
V_1427 -> V_1263 [ V_159 ] . V_1270 ) ) )
return - V_91 ;
F_48 ( V_53 , V_1634 ) ;
}
F_48 ( V_53 , V_1263 ) ;
F_48 ( V_53 , V_1631 ) ;
return 0 ;
}
static int F_368 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1635 = V_610 ;
if ( ! V_7 -> V_18 . V_189 )
return - V_550 ;
if ( V_7 -> V_18 . V_1600 && V_7 -> V_18 . V_1600 -> V_188 ) {
V_1635 += V_7 -> V_18 . V_1600 -> V_188 -> V_1630 +
V_7 -> V_18 . V_1600 -> V_188 -> V_1621 +
V_7 -> V_18 . V_1600 -> V_188 -> V_1624 +
V_7 -> V_18 . V_1600 -> V_188 -> V_1624 / 8 ;
}
V_53 = F_74 ( V_1635 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1636 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_18 . V_1600 ) {
struct V_4 * V_201 ;
V_201 = F_47 ( V_53 , V_1637 ) ;
if ( ! V_201 )
goto V_61;
if ( ( V_7 -> V_18 . V_1600 -> V_1638 &&
F_29 ( V_53 , V_204 ) ) ||
( V_7 -> V_18 . V_1600 -> V_451 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1600 -> V_1639 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1600 -> V_1640 &&
F_29 ( V_53 , V_212 ) ) ||
( V_7 -> V_18 . V_1600 -> V_1641 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1600 -> V_1642 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1600 -> V_1643 &&
F_29 ( V_53 , V_218 ) ) )
goto V_61;
if ( F_364 ( V_53 , V_7 ) )
goto V_61;
if ( F_365 ( V_53 ,
V_7 -> V_18 . V_1600 -> V_188 ) )
goto V_61;
if ( F_367 (
V_53 ,
V_7 -> V_18 . V_1600 -> V_1644 ) )
goto V_61;
F_48 ( V_53 , V_201 ) ;
}
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_369 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1599 * V_1645 )
{
struct V_4 * V_95 [ V_1646 ] ;
struct V_1611 * V_1119 ;
struct V_1647 * V_195 = NULL ;
struct V_1648 * V_50 = NULL ;
V_22 V_1635 ;
V_22 V_1649 , V_1650 , V_1630 = 0 , V_1651 ;
int V_35 , V_1652 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1653 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1654 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1612 ] ||
! V_95 [ V_1614 ] ||
! V_95 [ V_1615 ] ||
! V_95 [ V_1619 ] ||
! V_95 [ V_192 ] ||
! V_95 [ V_197 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_1626 ] )
return - V_16 ;
V_1649 = F_24 ( V_95 [ V_192 ] ) ;
if ( V_1649 > V_7 -> V_18 . V_189 -> V_188 -> V_193 )
return - V_16 ;
if ( F_4 ( V_95 [ V_197 ] ) >
V_7 -> V_18 . V_189 -> V_188 -> V_198 ||
F_4 ( V_95 [ V_197 ] ) == 0 )
return - V_16 ;
V_1650 = F_24 ( V_95 [ V_199 ] ) ;
if ( V_1650 > V_7 -> V_18 . V_189 -> V_188 -> V_200 )
return - V_16 ;
V_1651 = F_24 ( V_95 [ V_1626 ] ) ;
if ( V_1651 != F_257 ( V_1650 , 8 ) )
return - V_16 ;
if ( V_95 [ V_196 ] ) {
V_22 V_1655 = F_24 ( V_95 [ V_196 ] ) ;
V_195 = F_23 ( V_95 [ V_196 ] ) ;
V_1630 = V_1655 - sizeof( * V_195 ) ;
if ( ! V_195 -> V_47 || V_1630 % V_195 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_195 )
return - V_16 ;
if ( V_195 -> V_47 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1656 )
return - V_16 ;
if ( V_195 -> V_47 < V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1657 )
return - V_16 ;
if ( V_1630 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1658 )
return - V_16 ;
if ( V_195 -> V_1313 + V_195 -> V_47 > V_1649 )
return - V_16 ;
}
if ( V_95 [ V_194 ] ) {
V_50 = F_23 ( V_95 [ V_194 ] ) ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1313 > V_1649 )
return - V_16 ;
}
V_1635 = sizeof( * V_1119 ) ;
V_1635 += V_1649 ;
V_1635 += V_1650 + V_1651 ;
V_1635 += V_1630 ;
V_1119 = F_38 ( V_1635 , V_135 ) ;
if ( ! V_1119 )
return - V_136 ;
V_1119 -> V_1613 = F_370 ( V_95 [ V_1612 ] ) ;
V_1119 -> V_994 = F_370 ( V_95 [ V_1614 ] ) ;
memcpy ( V_1119 -> V_1616 , F_23 ( V_95 [ V_1615 ] ) ,
V_597 ) ;
if ( V_95 [ V_1617 ] )
V_1652 = F_78 ( V_95 [ V_1617 ] ) ;
else
V_1652 = 0 ;
#ifdef F_371
V_35 = F_372 ( F_7 ( & V_7 -> V_18 ) , V_1659 , V_1660 ,
V_1661 , & V_1119 -> V_1662 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1119 ) ;
return V_35 ;
}
if ( F_373 ( V_1119 -> V_1662 -> V_44 , V_1652 ) ) {
F_374 ( V_1119 -> V_1662 ) ;
F_41 ( V_1119 ) ;
return - V_1663 ;
}
V_1119 -> V_1618 = F_375 ( V_1119 -> V_1662 -> V_44 ) -> V_1664 ;
#else
if ( ! V_1652 ) {
F_41 ( V_1119 ) ;
return - V_16 ;
}
V_1119 -> V_1618 = V_1652 ;
#endif
V_1119 -> V_1620 = F_78 ( V_95 [ V_1619 ] ) ;
V_1119 -> V_1621 = V_1649 ;
V_1119 -> V_1622 = ( T_2 * ) V_1119 + sizeof( * V_1119 ) + V_1630 ;
memcpy ( ( void * ) V_1119 -> V_1622 ,
F_23 ( V_95 [ V_192 ] ) ,
V_1649 ) ;
if ( V_50 )
V_1119 -> V_1628 = * V_50 ;
V_1119 -> V_1623 = F_4 ( V_95 [ V_197 ] ) ;
V_1119 -> V_1624 = V_1650 ;
V_1119 -> V_1625 = ( T_2 * ) V_1119 + sizeof( * V_1119 ) + V_1630 + V_1649 ;
memcpy ( ( void * ) V_1119 -> V_1625 ,
F_23 ( V_95 [ V_199 ] ) ,
V_1650 ) ;
V_1119 -> V_1627 = ( T_2 * ) V_1119 + sizeof( * V_1119 ) + V_1630 +
V_1649 + V_1650 ;
memcpy ( ( void * ) V_1119 -> V_1627 ,
F_23 ( V_95 [ V_1626 ] ) ,
V_1651 ) ;
if ( V_195 ) {
V_1119 -> V_1630 = V_1630 ;
memcpy ( & V_1119 -> V_1629 , V_195 , sizeof( * V_195 ) + V_1630 ) ;
}
V_1645 -> V_188 = V_1119 ;
return 0 ;
}
static int F_376 ( struct V_6 * V_7 ,
const struct V_1665 * V_189 ,
struct V_4 * V_45 ,
struct V_1599 * V_1645 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_38 ( V_1666 * sizeof( * V_95 ) , V_135 ) ;
if ( ! V_95 )
return - V_136 ;
if ( ! ( V_189 -> V_51 & V_229 ) ) {
V_35 = - V_550 ;
goto V_609;
}
V_35 = F_96 ( V_95 , V_1300 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_609;
V_1645 -> V_1644 = F_258 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_260 ( V_1645 -> V_1644 ) ;
if ( V_35 )
V_1645 -> V_1644 = NULL ;
V_609:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_377 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_4 * V_95 [ V_1667 ] ;
struct V_1599 V_1668 = {} ;
struct V_1599 * V_1669 ;
const struct V_1665 * V_189 = V_7 -> V_18 . V_189 ;
int V_35 , V_159 ;
bool V_1670 = V_7 -> V_18 . V_1600 ;
bool V_1671 = false ;
if ( ! V_189 )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_1637 ] ) {
F_378 ( V_7 ) ;
V_7 -> V_18 . V_1600 = NULL ;
goto V_1672;
}
V_35 = F_96 ( V_95 , V_1673 ,
F_23 ( V_30 -> V_5 [ V_1637 ] ) ,
F_24 ( V_30 -> V_5 [ V_1637 ] ) ,
V_1674 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_204 ] ) {
if ( ! ( V_189 -> V_51 & V_203 ) )
return - V_16 ;
V_1668 . V_1638 = true ;
}
if ( V_95 [ V_206 ] ) {
if ( ! ( V_189 -> V_51 & V_205 ) )
return - V_16 ;
V_1668 . V_451 = true ;
V_1671 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_189 -> V_51 & V_207 ) )
return - V_16 ;
V_1668 . V_1639 = true ;
V_1671 = true ;
}
if ( V_95 [ V_210 ] )
return - V_16 ;
if ( V_95 [ V_212 ] ) {
if ( ! ( V_189 -> V_51 & V_211 ) )
return - V_16 ;
V_1668 . V_1640 = true ;
V_1671 = true ;
}
if ( V_95 [ V_214 ] ) {
if ( ! ( V_189 -> V_51 & V_213 ) )
return - V_16 ;
V_1668 . V_1641 = true ;
V_1671 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_189 -> V_51 & V_215 ) )
return - V_16 ;
V_1668 . V_1642 = true ;
V_1671 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_189 -> V_51 & V_217 ) )
return - V_16 ;
V_1668 . V_1643 = true ;
V_1671 = true ;
}
if ( V_95 [ V_228 ] ) {
struct V_4 * V_221 ;
int V_219 = 0 ;
int V_134 , V_1603 , V_1675 , V_1610 ;
struct V_4 * V_1676 [ V_1677 ] ;
V_1671 = true ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_189 -> V_219 )
return - V_16 ;
V_1668 . V_1604 = F_379 ( V_219 ,
sizeof( V_1668 . V_1604 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1668 . V_1604 )
return - V_136 ;
V_1668 . V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1678 ;
F_96 ( V_1676 , V_1679 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1676 [ V_1606 ] ||
! V_1676 [ V_1607 ] )
goto error;
V_1603 = F_24 ( V_1676 [ V_1607 ] ) ;
V_1675 = F_257 ( V_1603 , 8 ) ;
if ( F_24 ( V_1676 [ V_1606 ] ) != V_1675 )
goto error;
if ( V_1603 > V_189 -> V_226 ||
V_1603 < V_189 -> V_224 )
goto error;
if ( ! V_1676 [ V_1609 ] )
V_1610 = 0 ;
else
V_1610 = F_4 (
V_1676 [ V_1609 ] ) ;
if ( V_1610 > V_189 -> V_227 )
goto error;
V_1668 . V_1604 [ V_159 ] . V_1610 = V_1610 ;
V_1678 = F_380 ( V_1675 + V_1603 , V_135 ) ;
if ( ! V_1678 ) {
V_35 = - V_136 ;
goto error;
}
V_1668 . V_1604 [ V_159 ] . V_767 = V_1678 ;
memcpy ( V_1678 , F_23 ( V_1676 [ V_1606 ] ) ,
V_1675 ) ;
V_1678 += V_1675 ;
V_1668 . V_1604 [ V_159 ] . V_1608 = V_1678 ;
V_1668 . V_1604 [ V_159 ] . V_1605 = V_1603 ;
memcpy ( V_1678 ,
F_23 ( V_1676 [ V_1607 ] ) ,
V_1603 ) ;
V_159 ++ ;
}
}
if ( V_95 [ V_191 ] ) {
V_1671 = true ;
V_35 = F_369 (
V_7 , V_95 [ V_191 ] ,
& V_1668 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_230 ] ) {
V_1671 = true ;
V_35 = F_376 (
V_7 , V_189 , V_95 [ V_230 ] ,
& V_1668 ) ;
if ( V_35 )
goto error;
}
if ( V_1668 . V_1638 && V_1671 ) {
V_35 = - V_16 ;
goto error;
}
V_1669 = F_381 ( & V_1668 , sizeof( V_1668 ) , V_135 ) ;
if ( ! V_1669 ) {
V_35 = - V_136 ;
goto error;
}
F_378 ( V_7 ) ;
V_7 -> V_18 . V_1600 = V_1669 ;
V_1672:
if ( V_7 -> V_351 -> V_1672 &&
V_1670 != ! ! V_7 -> V_18 . V_1600 )
F_382 ( V_7 , V_7 -> V_18 . V_1600 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1668 . V_219 ; V_159 ++ )
F_41 ( V_1668 . V_1604 [ V_159 ] . V_767 ) ;
F_41 ( V_1668 . V_1604 ) ;
if ( V_1668 . V_188 && V_1668 . V_188 -> V_1662 )
F_374 ( V_1668 . V_188 -> V_1662 ) ;
F_41 ( V_1668 . V_188 ) ;
F_41 ( V_1668 . V_1644 ) ;
return V_35 ;
}
static int F_383 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1601 , * V_1602 , * V_1680 , * V_1681 ;
int V_159 , V_161 , V_1603 ;
struct V_1682 * V_233 ;
if ( ! V_7 -> V_234 -> V_236 )
return 0 ;
V_1681 = F_47 ( V_53 , V_238 ) ;
if ( ! V_1681 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_234 -> V_236 ; V_159 ++ ) {
V_1680 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1680 )
return - V_91 ;
V_233 = & V_7 -> V_234 -> V_1683 [ V_159 ] ;
if ( F_28 ( V_53 , V_1684 ,
V_233 -> V_1289 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1685 ,
V_233 -> V_1686 ) )
return - V_91 ;
V_1601 = F_47 ( V_53 ,
V_1687 ) ;
if ( ! V_1601 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ ) {
V_1602 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1602 )
return - V_91 ;
V_1603 = V_233 -> V_1604 [ V_161 ] . V_1605 ;
if ( F_51 ( V_53 , V_1606 ,
F_257 ( V_1603 , 8 ) ,
V_233 -> V_1604 [ V_161 ] . V_767 ) ||
F_51 ( V_53 , V_1607 , V_1603 ,
V_233 -> V_1604 [ V_161 ] . V_1608 ) ||
F_28 ( V_53 , V_1609 ,
V_233 -> V_1604 [ V_161 ] . V_1610 ) )
return - V_91 ;
F_48 ( V_53 , V_1602 ) ;
}
F_48 ( V_53 , V_1601 ) ;
F_48 ( V_53 , V_1680 ) ;
}
F_48 ( V_53 , V_1681 ) ;
return 0 ;
}
static int F_384 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
if ( ! V_7 -> V_18 . V_234 )
return - V_550 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1688 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_234 && F_383 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_385 ( struct V_6 * V_7 )
{
struct V_1689 * V_234 = V_7 -> V_234 ;
int V_159 , V_161 ;
struct V_1682 * V_233 ;
if ( ! V_234 )
return;
for ( V_159 = 0 ; V_159 < V_234 -> V_236 ; V_159 ++ ) {
V_233 = & V_234 -> V_1683 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ )
F_41 ( V_233 -> V_1604 [ V_161 ] . V_767 ) ;
F_41 ( V_233 -> V_1604 ) ;
}
F_41 ( V_234 -> V_1683 ) ;
F_41 ( V_234 ) ;
V_7 -> V_234 = NULL ;
}
static int F_386 ( struct V_6 * V_7 ,
struct V_4 * V_233 ,
struct V_1682 * V_1690 )
{
int V_35 , V_159 ;
const struct V_1691 * V_234 = V_7 -> V_18 . V_234 ;
struct V_4 * V_95 [ V_1692 ] , * V_221 ;
int V_134 , V_1603 , V_1675 , V_1610 , V_219 = 0 ;
struct V_4 * V_1676 [ V_1677 ] ;
V_35 = F_96 ( V_95 , V_1693 , F_23 ( V_233 ) ,
F_24 ( V_233 ) , V_1694 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1684 ] )
V_1690 -> V_1289 =
F_4 ( V_95 [ V_1684 ] ) ;
if ( V_1690 -> V_1289 > V_234 -> V_237 )
return - V_16 ;
if ( V_95 [ V_1685 ] )
V_1690 -> V_1686 =
F_4 ( V_95 [ V_1685 ] ) ;
if ( V_1690 -> V_1686 != V_1695 &&
V_1690 -> V_1686 != V_1696 )
return - V_16 ;
if ( ! V_95 [ V_1687 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_234 -> V_219 )
return - V_16 ;
V_1690 -> V_1604 = F_379 ( V_219 , sizeof( V_1690 -> V_1604 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1690 -> V_1604 )
return - V_136 ;
V_1690 -> V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1678 ;
F_96 ( V_1676 , V_1679 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
if ( ! V_1676 [ V_1606 ] ||
! V_1676 [ V_1607 ] )
return - V_16 ;
V_1603 = F_24 ( V_1676 [ V_1607 ] ) ;
V_1675 = F_257 ( V_1603 , 8 ) ;
if ( F_24 ( V_1676 [ V_1606 ] ) != V_1675 )
return - V_16 ;
if ( V_1603 > V_234 -> V_226 ||
V_1603 < V_234 -> V_224 )
return - V_16 ;
if ( ! V_1676 [ V_1609 ] )
V_1610 = 0 ;
else
V_1610 = F_4 ( V_1676 [ V_1609 ] ) ;
if ( V_1610 > V_234 -> V_227 )
return - V_16 ;
V_1690 -> V_1604 [ V_159 ] . V_1610 = V_1610 ;
V_1678 = F_380 ( V_1675 + V_1603 , V_135 ) ;
if ( ! V_1678 )
return - V_136 ;
V_1690 -> V_1604 [ V_159 ] . V_767 = V_1678 ;
memcpy ( V_1678 , F_23 ( V_1676 [ V_1606 ] ) ,
V_1675 ) ;
V_1678 += V_1675 ;
V_1690 -> V_1604 [ V_159 ] . V_1608 = V_1678 ;
V_1690 -> V_1604 [ V_159 ] . V_1605 = V_1603 ;
memcpy ( V_1678 , F_23 ( V_1676 [ V_1607 ] ) ,
V_1603 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_387 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
const struct V_1691 * V_234 = V_7 -> V_18 . V_234 ;
struct V_1689 V_1697 = {} ;
struct V_1689 * V_1698 ;
int V_35 , V_1699 , V_236 = 0 , V_159 , V_161 ;
struct V_4 * V_233 ;
struct V_1682 * V_1700 ;
if ( ! V_7 -> V_18 . V_234 || ! V_7 -> V_351 -> V_1701 )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_238 ] ) {
F_385 ( V_7 ) ;
F_388 ( V_7 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_236 ++ ;
if ( V_236 > V_234 -> V_236 )
return - V_16 ;
V_1697 . V_1683 = F_379 ( V_236 , sizeof( V_1697 . V_1683 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1697 . V_1683 )
return - V_136 ;
V_1697 . V_236 = V_236 ;
V_159 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_386 ( V_7 , V_233 ,
& V_1697 . V_1683 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = F_388 ( V_7 , & V_1697 ) ;
if ( V_35 )
goto error;
V_1698 = F_381 ( & V_1697 , sizeof( V_1697 ) , V_135 ) ;
if ( ! V_1698 ) {
V_35 = - V_136 ;
goto error;
}
F_385 ( V_7 ) ;
V_7 -> V_234 = V_1698 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1697 . V_236 ; V_159 ++ ) {
V_1700 = & V_1697 . V_1683 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1700 -> V_219 ; V_161 ++ )
F_41 ( V_1700 -> V_1604 [ V_161 ] . V_767 ) ;
F_41 ( V_1700 -> V_1604 ) ;
}
F_41 ( V_1697 . V_1683 ) ;
return V_35 ;
}
static int F_389 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_4 * V_95 [ V_1702 ] ;
struct V_1703 V_1704 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1705 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1706 ,
F_23 ( V_30 -> V_5 [ V_1705 ] ) ,
F_24 ( V_30 -> V_5 [ V_1705 ] ) ,
V_1707 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1708 ] ) != V_1709 )
return - V_1710 ;
if ( F_24 ( V_95 [ V_1711 ] ) != V_1712 )
return - V_1710 ;
if ( F_24 ( V_95 [ V_1713 ] ) != V_1714 )
return - V_1710 ;
V_1704 . V_1715 = F_23 ( V_95 [ V_1711 ] ) ;
V_1704 . V_1716 = F_23 ( V_95 [ V_1713 ] ) ;
V_1704 . V_1717 = F_23 ( V_95 [ V_1708 ] ) ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1303 ;
goto V_609;
}
if ( ! V_7 -> V_351 -> V_1718 ) {
V_35 = - V_550 ;
goto V_609;
}
V_35 = F_390 ( V_7 , V_549 , & V_1704 ) ;
V_609:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_391 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1719 )
return - V_554 ;
V_17 -> V_1719 = V_30 -> V_514 ;
return 0 ;
}
static int F_392 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_31 * V_53 ;
void * V_283 ;
const T_2 * V_694 ;
T_1 V_664 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_425 )
return - V_550 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1720 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_674;
}
V_694 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_35 = F_393 ( V_7 , V_549 , V_694 , & V_664 ) ;
if ( V_35 )
goto V_674;
if ( F_104 ( V_53 , V_1522 , V_664 ,
V_596 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_674:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_394 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1721 * V_1722 , * V_1723 ;
int V_1724 ;
if ( ! ( V_7 -> V_18 . V_51 & V_429 ) )
return - V_550 ;
V_1723 = F_38 ( sizeof( * V_1723 ) , V_135 ) ;
if ( ! V_1723 )
return - V_136 ;
F_279 ( & V_7 -> V_1725 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1722 -> V_1726 == V_30 -> V_514 ) {
V_1724 = - V_725 ;
goto V_903;
}
}
V_1723 -> V_1726 = V_30 -> V_514 ;
F_395 ( & V_1723 -> V_655 , & V_7 -> V_1727 ) ;
F_281 ( & V_7 -> V_1725 ) ;
return 0 ;
V_903:
F_281 ( & V_7 -> V_1725 ) ;
F_41 ( V_1723 ) ;
return V_1724 ;
}
static int F_396 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_431 )
return - V_550 ;
if ( V_17 -> V_141 != V_154 )
return - V_550 ;
if ( V_17 -> V_1728 )
return 0 ;
if ( F_397 ( V_7 -> V_1729 ) )
return - V_1730 ;
V_35 = F_398 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1728 = true ;
V_7 -> V_1731 ++ ;
return 0 ;
}
static int F_399 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_550 ;
if ( ! V_7 -> V_351 -> V_1732 )
return - V_550 ;
F_400 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_401 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_283 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_514 , V_30 -> V_515 , 0 ,
V_1733 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_1734 ,
V_1735 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_306 ( V_53 ) ;
return - V_91 ;
}
static int F_402 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1736 V_1737 ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1738 )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_1739 ] ||
! F_22 ( V_30 -> V_5 [ V_700 ] ) )
return - V_16 ;
memset ( & V_1737 , 0 , sizeof( V_1737 ) ) ;
V_1737 . V_1740 = F_78 ( V_30 -> V_5 [ V_1739 ] ) ;
V_1737 . V_1150 = F_23 ( V_30 -> V_5 [ V_700 ] ) ;
V_1737 . V_1151 = F_24 ( V_30 -> V_5 [ V_700 ] ) ;
return F_403 ( V_7 , V_549 , & V_1737 ) ;
}
static int F_404 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
enum V_1741 V_1411 = V_1742 ;
T_3 V_1245 ;
int V_506 ;
if ( ! V_7 -> V_351 -> V_437 )
return - V_550 ;
if ( F_59 ( ! V_7 -> V_351 -> V_439 ) )
return - V_16 ;
if ( V_7 -> V_1743 )
return - V_554 ;
if ( V_30 -> V_5 [ V_1744 ] )
V_1411 = F_78 ( V_30 -> V_5 [ V_1744 ] ) ;
if ( V_1411 >= V_1745 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1746 ] )
return - V_16 ;
V_1245 =
F_78 ( V_30 -> V_5 [ V_1746 ] ) ;
if ( V_1245 > V_1747 )
return - V_1710 ;
V_506 = F_405 ( V_7 , V_17 , V_1411 , V_1245 ) ;
if ( ! V_506 )
V_7 -> V_1743 = V_30 -> V_514 ;
return V_506 ;
}
static int F_406 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_439 )
return - V_550 ;
if ( V_7 -> V_1743 ) {
V_7 -> V_1743 = 0 ;
F_407 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_408 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_159 , V_35 ;
V_22 V_1748 , V_1471 ;
if ( ! V_7 -> V_18 . V_484 )
return - V_550 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1468 ] ||
! V_30 -> V_5 [ V_1470 ] )
return - V_16 ;
V_1748 = F_4 ( V_30 -> V_5 [ V_1468 ] ) ;
V_1471 = F_4 ( V_30 -> V_5 [ V_1470 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1749 * V_1750 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1750 = & V_7 -> V_18 . V_484 [ V_159 ] ;
if ( V_1750 -> V_30 . V_1469 != V_1748 || V_1750 -> V_30 . V_1471 != V_1471 )
continue;
if ( V_1750 -> V_51 & ( V_1751 |
V_1752 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1750 -> V_51 & V_1752 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1750 -> V_51 & V_1753 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_564 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1728 )
return - V_564 ;
}
if ( ! V_1750 -> V_1754 )
return - V_550 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_483 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_483 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_483 ] ) ;
}
V_7 -> V_1480 = V_30 ;
V_35 = V_7 -> V_18 . V_484 [ V_159 ] . V_1754 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1480 = NULL ;
return V_35 ;
}
return - V_550 ;
}
static int F_409 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
V_22 V_1748 , V_1471 ;
unsigned int V_159 ;
int V_1755 = - 1 ;
int V_35 ;
void * V_138 = NULL ;
unsigned int V_1482 = 0 ;
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
if ( ! V_38 . V_40 [ V_1468 ] ||
! V_38 . V_40 [ V_1470 ] ) {
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
V_1748 = F_4 ( V_38 . V_40 [ V_1468 ] ) ;
V_1471 = F_4 ( V_38 . V_40 [ V_1470 ] ) ;
for ( V_159 = 0 ; V_159 < ( * V_7 ) -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1749 * V_1750 ;
V_1750 = & ( * V_7 ) -> V_18 . V_484 [ V_159 ] ;
if ( V_1750 -> V_30 . V_1469 != V_1748 || V_1750 -> V_30 . V_1471 != V_1471 )
continue;
if ( ! V_1750 -> V_1756 ) {
V_35 = - V_550 ;
goto V_43;
}
V_1755 = V_159 ;
break;
}
if ( V_1755 < 0 ) {
V_35 = - V_550 ;
goto V_43;
}
if ( V_38 . V_40 [ V_483 ] ) {
V_138 = F_23 ( V_38 . V_40 [ V_483 ] ) ;
V_1482 = F_24 ( V_38 . V_40 [ V_483 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1755 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_138 ;
V_34 -> args [ 4 ] = V_1482 ;
return 0 ;
V_43:
F_20 () ;
return V_35 ;
}
static int F_410 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
unsigned int V_1755 ;
const struct V_1749 * V_1750 ;
void * V_138 ;
int V_1482 ;
int V_35 ;
struct V_4 * V_1757 ;
V_35 = F_409 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
V_1755 = V_34 -> args [ 2 ] ;
V_138 = ( void * ) V_34 -> args [ 3 ] ;
V_1482 = V_34 -> args [ 4 ] ;
V_1750 = & V_7 -> V_18 . V_484 [ V_1755 ] ;
if ( V_1750 -> V_51 & ( V_1751 |
V_1752 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1750 -> V_51 & V_1752 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1750 -> V_51 & V_1753 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_564 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1728 )
return - V_564 ;
}
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_510 , V_511 ,
V_1474 ) ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ,
V_596 ) ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1757 = F_47 ( V_32 , V_483 ) ;
if ( ! V_1757 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = V_1750 -> V_1756 ( & V_7 -> V_18 , V_17 , V_32 , V_138 , V_1482 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_48 ( V_32 , V_1757 ) ;
if ( V_35 == - V_91 || V_35 == - V_672 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_609;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_609:
F_20 () ;
return V_35 ;
}
struct V_31 * F_411 ( struct V_18 * V_18 ,
enum V_280 V_52 ,
enum V_782 V_45 ,
int V_1466 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1480 ) )
return NULL ;
return F_305 ( V_7 , NULL , V_1466 ,
V_7 -> V_1480 -> V_514 ,
V_7 -> V_1480 -> V_515 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_412 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1480 ) ) {
F_306 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
return F_76 ( V_32 , V_7 -> V_1480 ) ;
}
static int F_413 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_1758 * V_1759 = NULL ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
T_2 * V_46 , V_47 , V_1760 , V_1761 , V_1762 ;
int V_506 ;
if ( ! V_7 -> V_351 -> V_444 )
return - V_550 ;
if ( V_30 -> V_5 [ V_1763 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1763 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1763 ] ) ;
if ( V_47 % 2 || V_47 < V_1764 ||
V_47 > V_1765 )
return - V_16 ;
V_1759 = F_38 ( sizeof( struct V_1758 ) , V_135 ) ;
if ( ! V_1759 )
return - V_136 ;
V_1760 = ( V_47 - V_1764 ) >> 1 ;
if ( V_1760 ) {
V_1761 = V_1760 *
sizeof( struct V_1766 ) ;
memcpy ( V_1759 -> V_1767 , V_46 , V_1761 ) ;
V_1759 -> V_1760 = V_1760 ;
for ( V_1762 = 0 ; V_1762 < V_1760 ; V_1762 ++ ) {
if ( V_1759 -> V_1767 [ V_1762 ] . V_1768 > 7 ) {
F_41 ( V_1759 ) ;
return - V_16 ;
}
}
V_46 += V_1761 ;
}
memcpy ( V_1759 -> V_1768 , V_46 , V_1764 ) ;
}
F_113 ( V_549 -> V_28 ) ;
V_506 = F_42 ( V_549 -> V_28 ) ;
if ( ! V_506 )
V_506 = F_414 ( V_7 , V_549 , V_1759 ) ;
F_115 ( V_549 -> V_28 ) ;
F_41 ( V_1759 ) ;
return V_506 ;
}
static int F_415 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
const T_2 * V_1509 ;
T_2 V_1769 , V_1768 ;
T_3 V_1770 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_291 & V_446 ) )
return - V_550 ;
if ( ! V_30 -> V_5 [ V_1771 ] || ! V_30 -> V_5 [ V_557 ] ||
! V_30 -> V_5 [ V_1772 ] )
return - V_16 ;
V_1769 = F_34 ( V_30 -> V_5 [ V_1771 ] ) ;
if ( V_1769 >= V_887 )
return - V_16 ;
V_1768 = F_34 ( V_30 -> V_5 [ V_1772 ] ) ;
if ( V_1768 >= V_1773 )
return - V_16 ;
if ( V_1769 >= V_1774 ) {
return - V_16 ;
}
V_1509 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
if ( V_30 -> V_5 [ V_1775 ] ) {
V_1770 =
F_78 ( V_30 -> V_5 [ V_1775 ] ) ;
if ( ! V_1770 )
return - V_16 ;
}
F_113 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1303 ;
goto V_609;
default:
V_35 = - V_550 ;
goto V_609;
}
V_35 = F_416 ( V_7 , V_549 , V_1769 , V_1509 , V_1768 , V_1770 ) ;
V_609:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_417 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
const T_2 * V_1509 ;
T_2 V_1769 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1771 ] || ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_1769 = F_34 ( V_30 -> V_5 [ V_1771 ] ) ;
V_1509 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_418 ( V_7 , V_549 , V_1769 , V_1509 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_419 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_529 V_530 = {} ;
const T_2 * V_694 ;
T_2 V_1776 ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_1777 ||
! ( V_7 -> V_18 . V_291 & V_1778 ) )
return - V_550 ;
switch ( V_549 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_550 ;
}
if ( ! V_30 -> V_5 [ V_557 ] ||
! V_30 -> V_5 [ V_1779 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_530 ) ;
if ( V_35 )
return V_35 ;
if ( V_530 . V_55 -> V_290 == V_1780 &&
V_530 . V_533 != V_534 &&
V_530 . V_533 != V_589 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_530 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( F_269 ( V_17 -> V_18 , & V_530 , V_17 -> V_141 ) )
return - V_16 ;
V_694 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
V_1776 = F_34 ( V_30 -> V_5 [ V_1779 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_420 ( V_7 , V_549 , V_694 , V_1776 , & V_530 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_421 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_513 [ 0 ] ;
struct V_25 * V_549 = V_30 -> V_513 [ 1 ] ;
struct V_1 * V_17 = V_549 -> V_28 ;
const T_2 * V_694 ;
if ( ! V_7 -> V_351 -> V_1777 ||
! V_7 -> V_351 -> V_1781 ||
! ( V_7 -> V_18 . V_291 & V_1778 ) )
return - V_550 ;
switch ( V_549 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_550 ;
}
if ( ! V_30 -> V_5 [ V_557 ] )
return - V_16 ;
V_694 = F_23 ( V_30 -> V_5 [ V_557 ] ) ;
F_113 ( V_17 ) ;
F_422 ( V_7 , V_549 , V_694 ) ;
F_115 ( V_17 ) ;
return 0 ;
}
static int F_423 ( const struct V_1782 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_549 ;
bool V_1783 = V_351 -> V_1784 & V_1785 ;
if ( V_1783 )
F_14 () ;
if ( V_351 -> V_1784 & V_1786 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1783 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_513 [ 0 ] = V_7 ;
} else if ( V_351 -> V_1784 & V_1787 ||
V_351 -> V_1784 & V_1788 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1783 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_549 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_351 -> V_1784 & V_1787 ) {
if ( ! V_549 ) {
if ( V_1783 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_513 [ 1 ] = V_549 ;
} else {
V_30 -> V_513 [ 1 ] = V_17 ;
}
if ( V_549 ) {
if ( V_351 -> V_1784 & V_1789 &&
! F_91 ( V_549 ) ) {
if ( V_1783 )
F_20 () ;
return - V_564 ;
}
F_253 ( V_549 ) ;
} else if ( V_351 -> V_1784 & V_1789 ) {
if ( ! V_17 -> V_1728 ) {
if ( V_1783 )
F_20 () ;
return - V_564 ;
}
}
V_30 -> V_513 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_424 ( const struct V_1782 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_513 [ 1 ] ) {
if ( V_351 -> V_1784 & V_1788 ) {
struct V_1 * V_17 = V_30 -> V_513 [ 1 ] ;
if ( V_17 -> V_19 )
F_175 ( V_17 -> V_19 ) ;
} else {
F_175 ( V_30 -> V_513 [ 1 ] ) ;
}
}
if ( V_351 -> V_1784 & V_1785 )
F_20 () ;
if ( V_351 -> V_1784 & V_1790 ) {
struct V_1791 * V_36 = F_425 ( V_32 ) ;
memset ( F_426 ( V_36 ) , 0 , F_427 ( V_36 ) ) ;
}
}
void F_428 ( struct V_6 * V_7 ,
enum V_280 V_52 )
{
struct V_31 * V_53 ;
struct V_281 V_282 = {} ;
F_59 ( V_52 != V_295 &&
V_52 != V_1792 ) ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_657 , V_135 ) ;
}
static int F_429 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1230 * V_1427 = V_7 -> V_1234 ;
struct V_4 * V_1216 ;
int V_159 ;
if ( F_59 ( ! V_1427 ) )
return 0 ;
V_1216 = F_47 ( V_53 , V_1238 ) ;
if ( ! V_1216 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1427 -> V_1232 ; V_159 ++ ) {
if ( F_51 ( V_53 , V_159 , V_1427 -> V_1239 [ V_159 ] . V_602 , V_1427 -> V_1239 [ V_159 ] . V_604 ) )
goto V_61;
}
F_48 ( V_53 , V_1216 ) ;
V_1216 = F_47 ( V_53 , V_1237 ) ;
if ( ! V_1216 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1427 -> V_366 ; V_159 ++ ) {
if ( F_28 ( V_53 , V_159 , V_1427 -> V_367 [ V_159 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1216 ) ;
if ( V_1427 -> V_1150 &&
F_51 ( V_53 , V_700 , V_1427 -> V_1151 , V_1427 -> V_1150 ) )
goto V_61;
if ( V_1427 -> V_51 &&
F_28 ( V_53 , V_1248 , V_1427 -> V_51 ) )
goto V_61;
if ( V_1427 -> V_30 . V_1793 &&
( F_104 ( V_53 , V_1794 ,
V_1427 -> V_30 . V_1793 , V_1335 ) ||
F_51 ( V_53 , V_1795 , V_597 ,
V_1427 -> V_30 . V_1796 ) ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_430 ( struct V_31 * V_53 ,
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
V_596 ) )
goto V_61;
F_429 ( V_53 , V_7 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_505 ;
}
static int
F_431 ( struct V_31 * V_53 ,
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
return - V_505 ;
}
void F_252 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_430 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1797 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1798 , V_135 ) ;
}
struct V_31 * F_432 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1799 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_430 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1799 ? V_1800 :
V_1327 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_433 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1798 , V_135 ) ;
}
void F_434 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_431 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1801 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1798 , V_135 ) ;
}
void F_263 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_431 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1798 , V_135 ) ;
}
static bool F_435 ( struct V_31 * V_53 ,
struct V_1802 * V_1231 )
{
if ( F_56 ( V_53 , V_1803 , V_1231 -> V_1510 ) )
goto V_61;
if ( V_1231 -> V_1164 [ 0 ] == '0' && V_1231 -> V_1164 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1804 ,
V_1805 ) )
goto V_61;
} else if ( V_1231 -> V_1164 [ 0 ] == '9' && V_1231 -> V_1164 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1804 ,
V_1806 ) )
goto V_61;
} else if ( ( V_1231 -> V_1164 [ 0 ] == '9' && V_1231 -> V_1164 [ 1 ] == '8' ) ||
V_1231 -> V_1807 ) {
if ( F_56 ( V_53 , V_1804 ,
V_1808 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1804 ,
V_1809 ) ||
F_60 ( V_53 , V_1052 ,
V_1231 -> V_1164 ) )
goto V_61;
}
if ( V_1231 -> V_14 != V_1810 ) {
struct V_18 * V_18 = F_19 ( V_1231 -> V_14 ) ;
if ( V_18 &&
F_28 ( V_53 , V_26 , V_1231 -> V_14 ) )
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
void F_436 ( enum V_280 V_1811 ,
struct V_1802 * V_1231 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1811 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_435 ( V_53 , V_1231 ) == false )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_227 () ;
F_437 ( & V_38 , V_53 , 0 ,
V_1812 , V_1813 ) ;
F_229 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_438 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1566 , T_11 V_47 ,
enum V_280 V_52 , T_12 V_1467 ,
int V_942 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1563 , V_47 , V_1566 ) )
goto V_61;
if ( V_942 >= 0 ) {
struct V_4 * V_1814 =
F_47 ( V_53 , V_939 ) ;
if ( ! V_1814 )
goto V_61;
if ( F_56 ( V_53 , V_941 ,
V_942 ) )
goto V_61;
F_48 ( V_53 , V_1814 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_439 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1566 ,
T_11 V_47 , T_12 V_1467 )
{
F_438 ( V_7 , V_19 , V_1566 , V_47 ,
V_721 , V_1467 , - 1 ) ;
}
void F_440 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1566 ,
T_11 V_47 , T_12 V_1467 , int V_942 )
{
F_438 ( V_7 , V_19 , V_1566 , V_47 ,
V_1816 , V_1467 , V_942 ) ;
}
void F_441 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1566 ,
T_11 V_47 , T_12 V_1467 )
{
F_438 ( V_7 , V_19 , V_1566 , V_47 ,
V_1817 , V_1467 , - 1 ) ;
}
void F_442 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1566 ,
T_11 V_47 , T_12 V_1467 )
{
F_438 ( V_7 , V_19 , V_1566 , V_47 ,
V_1818 , V_1467 , - 1 ) ;
}
void F_443 ( struct V_25 * V_549 , const T_2 * V_1566 ,
T_11 V_47 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1819 * V_1820 = ( void * ) V_1566 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_444 ( V_1820 -> V_1821 ) )
V_52 = V_1822 ;
else
V_52 = V_1823 ;
F_445 ( V_549 , V_1566 , V_47 ) ;
F_438 ( V_7 , V_549 , V_1566 , V_47 , V_52 , V_1813 , - 1 ) ;
}
static void F_446 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_694 , T_12 V_1467 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1824 ) ||
F_51 ( V_53 , V_557 , V_597 , V_694 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_447 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_694 ,
T_12 V_1467 )
{
F_446 ( V_7 , V_19 , V_721 ,
V_694 , V_1467 ) ;
}
void F_448 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_694 ,
T_12 V_1467 )
{
F_446 ( V_7 , V_19 , V_1816 ,
V_694 , V_1467 ) ;
}
void F_449 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_556 ,
const T_2 * V_1825 , T_11 V_1826 ,
const T_2 * V_1827 , T_11 V_1828 ,
int V_658 , T_12 V_1467 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_450 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_556 && F_51 ( V_53 , V_557 , V_597 , V_556 ) ) ||
F_55 ( V_53 , V_1512 ,
V_658 < 0 ? V_1829 :
V_658 ) ||
( V_658 < 0 && F_29 ( V_53 , V_1824 ) ) ||
( V_1825 &&
F_51 ( V_53 , V_1830 , V_1826 , V_1825 ) ) ||
( V_1827 &&
F_51 ( V_53 , V_1831 , V_1828 , V_1827 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_450 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_556 ,
const T_2 * V_1825 , T_11 V_1826 ,
const T_2 * V_1827 , T_11 V_1828 , T_12 V_1467 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1832 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_556 ) ||
( V_1825 &&
F_51 ( V_53 , V_1830 , V_1826 , V_1825 ) ) ||
( V_1827 &&
F_51 ( V_53 , V_1831 , V_1828 , V_1827 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_451 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1492 ,
const T_2 * V_1150 , T_11 V_1151 , bool V_1833 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_452 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1833 && V_1492 &&
F_55 ( V_53 , V_991 , V_1492 ) ) ||
( V_1833 &&
F_29 ( V_53 , V_1834 ) ) ||
( V_1150 && F_51 ( V_53 , V_700 , V_1151 , V_1150 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_452 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_556 ,
T_12 V_1467 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1835 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_556 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_453 ( struct V_25 * V_549 , const T_2 * V_694 ,
const T_2 * V_1150 , T_2 V_1151 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_454 ( V_549 , V_694 ) ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1836 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_694 ) ||
( V_1151 && V_1150 &&
F_51 ( V_53 , V_700 , V_1151 , V_1150 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_455 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_694 ,
enum V_1837 V_1838 , int V_1839 ,
const T_2 * V_1840 , T_12 V_1467 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1841 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_694 && F_51 ( V_53 , V_557 , V_597 , V_694 ) ) ||
F_28 ( V_53 , V_127 , V_1838 ) ||
( V_1839 != - 1 &&
F_56 ( V_53 , V_123 , V_1839 ) ) ||
( V_1840 && F_51 ( V_53 , V_122 , 6 , V_1840 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_456 ( struct V_18 * V_18 ,
struct V_54 * V_1842 ,
struct V_54 * V_1843 )
{
struct V_31 * V_53 ;
void * V_283 ;
struct V_4 * V_287 ;
V_53 = F_74 ( V_610 , V_1813 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1844 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_225 ( V_18 ) ) )
goto V_61;
V_287 = F_47 ( V_53 , V_1845 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1842 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
V_287 = F_47 ( V_53 , V_1846 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1843 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
F_66 ( V_53 , V_283 ) ;
F_227 () ;
F_437 ( & V_38 , V_53 , 0 ,
V_1812 , V_1813 ) ;
F_229 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_457 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_664 ,
struct V_54 * V_55 ,
unsigned int V_1245 , T_12 V_1467 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
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
V_596 ) ||
F_28 ( V_53 , V_532 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_537 ,
V_540 ) ||
F_104 ( V_53 , V_1522 , V_664 ,
V_596 ) )
goto V_61;
if ( V_52 == V_1521 &&
F_28 ( V_53 , V_1519 , V_1245 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_458 ( struct V_1 * V_17 , T_1 V_664 ,
struct V_54 * V_55 ,
unsigned int V_1245 , T_12 V_1467 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_459 ( V_17 , V_664 , V_55 , V_1245 ) ;
F_457 ( V_1521 ,
V_7 , V_17 , V_664 , V_55 ,
V_1245 , V_1467 ) ;
}
void F_460 ( struct V_1 * V_17 , T_1 V_664 ,
struct V_54 * V_55 ,
T_12 V_1467 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_461 ( V_17 , V_664 , V_55 ) ;
F_457 ( V_1847 ,
V_7 , V_17 , V_664 , V_55 , 0 , V_1467 ) ;
}
void F_462 ( struct V_25 * V_549 , const T_2 * V_666 ,
struct V_808 * V_809 , T_12 V_1467 )
{
struct V_18 * V_18 = V_549 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_463 ( V_549 , V_666 , V_809 ) ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
if ( F_164 ( V_53 , V_905 , 0 , 0 , 0 ,
V_7 , V_549 , V_666 , V_809 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
}
void F_464 ( struct V_25 * V_549 , const T_2 * V_666 ,
struct V_808 * V_809 , T_12 V_1467 )
{
struct V_18 * V_18 = V_549 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_808 V_1848 = {} ;
if ( ! V_809 )
V_809 = & V_1848 ;
F_465 ( V_549 , V_666 ) ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
if ( F_164 ( V_53 , V_1849 , 0 , 0 , 0 ,
V_7 , V_549 , V_666 , V_809 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
}
void F_466 ( struct V_25 * V_549 , const T_2 * V_666 ,
enum V_1850 V_1492 ,
T_12 V_1467 )
{
struct V_18 * V_18 = V_549 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_1851 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1852 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_666 ) ||
F_28 ( V_53 , V_1853 , V_1492 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static bool F_467 ( struct V_25 * V_549 , T_2 V_52 ,
const T_2 * V_694 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1726 = F_468 ( V_17 -> V_1719 ) ;
if ( ! V_1726 )
return false ;
V_53 = F_74 ( 100 , V_1467 ) ;
if ( ! V_53 )
return true ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_694 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_469 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1726 ) ;
return true ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_470 ( struct V_25 * V_549 ,
const T_2 * V_694 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
bool V_506 ;
F_471 ( V_549 , V_694 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_472 ( false ) ;
return false ;
}
V_506 = F_467 ( V_549 , V_1854 ,
V_694 , V_1467 ) ;
F_472 ( V_506 ) ;
return V_506 ;
}
bool F_473 ( struct V_25 * V_549 ,
const T_2 * V_694 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
bool V_506 ;
F_474 ( V_549 , V_694 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_472 ( false ) ;
return false ;
}
V_506 = F_467 ( V_549 ,
V_1855 ,
V_694 , V_1467 ) ;
F_472 ( V_506 ) ;
return V_506 ;
}
int F_475 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1726 ,
int V_1856 , int V_1857 ,
const T_2 * V_1566 , T_11 V_47 , V_22 V_51 , T_12 V_1467 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1570 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_596 ) ||
F_28 ( V_53 , V_532 , V_1856 ) ||
( V_1857 &&
F_28 ( V_53 , V_1858 , V_1857 ) ) ||
F_51 ( V_53 , V_1563 , V_47 , V_1566 ) ||
( V_51 &&
F_28 ( V_53 , V_1859 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_469 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1726 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_476 ( struct V_1 * V_17 , T_1 V_664 ,
const T_2 * V_1566 , T_11 V_47 , bool V_1860 , T_12 V_1467 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
F_477 ( V_17 , V_664 , V_1860 ) ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1861 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_596 ) ||
F_51 ( V_53 , V_1563 , V_47 , V_1566 ) ||
F_104 ( V_53 , V_1522 , V_664 ,
V_596 ) ||
( V_1860 && F_29 ( V_53 , V_1862 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_478 ( struct V_25 * V_549 ,
const char * V_985 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_610 , V_1467 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1863 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_549 -> V_20 ) )
goto V_61;
if ( V_985 && F_51 ( V_53 , V_557 , V_597 , V_985 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1589 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_479 ( struct V_31 * V_53 , T_12 V_1467 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
}
void F_480 ( struct V_25 * V_549 ,
enum V_1864 V_1865 ,
T_12 V_1467 )
{
struct V_31 * V_53 ;
F_481 ( V_549 , V_1865 ) ;
if ( F_59 ( V_1865 != V_1866 &&
V_1865 != V_1867 ) )
return;
V_53 = F_478 ( V_549 , NULL , V_1467 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1868 ,
V_1865 ) )
goto V_61;
F_479 ( V_53 , V_1467 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_482 ( struct V_25 * V_549 ,
const T_2 * V_1509 , V_22 V_1869 ,
V_22 V_244 , V_22 V_1581 , T_12 V_1467 )
{
struct V_31 * V_53 ;
V_53 = F_478 ( V_549 , V_1509 , V_1467 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1594 , V_1869 ) )
goto V_61;
if ( F_28 ( V_53 , V_1593 , V_244 ) )
goto V_61;
if ( F_28 ( V_53 , V_1595 , V_1581 ) )
goto V_61;
F_479 ( V_53 , V_1467 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_483 ( struct V_25 * V_549 ,
const T_2 * V_1509 , V_22 V_1869 , T_12 V_1467 )
{
struct V_31 * V_53 ;
F_484 ( V_549 , V_1509 , V_1869 ) ;
V_53 = F_478 ( V_549 , V_1509 , V_1467 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1870 , V_1869 ) )
goto V_61;
F_479 ( V_53 , V_1467 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_485 ( struct V_25 * V_549 , T_12 V_1467 )
{
struct V_31 * V_53 ;
V_53 = F_478 ( V_549 , NULL , V_1467 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1871 ) )
goto V_61;
F_479 ( V_53 , V_1467 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_486 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_556 ,
const T_2 * V_1717 , T_12 V_1467 )
{
struct V_31 * V_53 ;
struct V_4 * V_1872 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1873 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_556 ) )
goto V_61;
V_1872 = F_47 ( V_53 , V_1705 ) ;
if ( ! V_1872 )
goto V_61;
if ( F_51 ( V_53 , V_1708 ,
V_1709 , V_1717 ) )
goto V_61;
F_48 ( V_53 , V_1872 ) ;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_487 ( struct V_25 * V_549 , const T_2 * V_556 ,
const T_2 * V_1717 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_488 ( V_549 , V_556 ) ;
F_486 ( V_7 , V_549 , V_556 , V_1717 , V_1467 ) ;
}
static void
F_489 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1874 ,
const T_2 * V_556 , bool V_1875 , T_12 V_1467 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1876 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1877 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1878 , V_1874 ) ||
F_51 ( V_53 , V_1879 , V_597 , V_556 ) ||
( V_1875 &&
F_29 ( V_53 , V_1880 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_490 ( struct V_25 * V_549 , int V_1874 ,
const T_2 * V_556 , bool V_1875 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_491 ( V_549 , V_1874 , V_556 , V_1875 ) ;
F_489 ( V_7 , V_549 , V_1874 , V_556 , V_1875 , V_1467 ) ;
}
static void F_492 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_529 * V_530 ,
T_12 V_1467 ,
enum V_280 V_1881 ,
T_2 V_1306 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1881 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_530 ) )
goto V_61;
if ( ( V_1881 == V_1882 ) &&
( F_28 ( V_53 , V_1304 , V_1306 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_493 ( struct V_25 * V_549 ,
struct V_529 * V_530 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_494 ( V_549 , V_530 ) ;
V_17 -> V_530 = * V_530 ;
V_17 -> V_555 = * V_530 ;
F_492 ( V_7 , V_549 , V_530 , V_135 ,
V_1883 , 0 ) ;
}
void F_495 ( struct V_25 * V_549 ,
struct V_529 * V_530 ,
T_2 V_1306 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_496 ( V_549 , V_530 ) ;
F_492 ( V_7 , V_549 , V_530 , V_135 ,
V_1882 , V_1306 ) ;
}
void
F_497 ( struct V_6 * V_7 ,
const struct V_529 * V_530 ,
enum V_1884 V_643 ,
struct V_25 * V_19 , T_12 V_1467 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1885 ) ;
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
V_596 ) )
goto V_61;
}
if ( F_28 ( V_53 , V_1886 , V_643 ) )
goto V_61;
if ( F_101 ( V_53 , V_530 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_498 ( struct V_25 * V_549 , const T_2 * V_694 ,
T_1 V_664 , bool V_1887 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_499 ( V_549 , V_694 , V_664 , V_1887 ) ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1720 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_694 ) ||
F_104 ( V_53 , V_1522 , V_664 ,
V_596 ) ||
( V_1887 && F_29 ( V_53 , V_1862 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_500 ( struct V_18 * V_18 ,
const T_2 * V_1888 , T_11 V_47 ,
int V_1856 , int V_1857 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
struct V_1721 * V_1722 ;
F_501 ( V_18 , V_1888 , V_47 , V_1856 , V_1857 ) ;
F_279 ( & V_7 -> V_1725 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1813 ) ;
if ( ! V_53 ) {
F_281 ( & V_7 -> V_1725 ) ;
return;
}
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1570 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1856 &&
F_28 ( V_53 , V_532 , V_1856 ) ) ||
( V_1857 &&
F_28 ( V_53 , V_1858 , V_1857 ) ) ||
F_51 ( V_53 , V_1563 , V_47 , V_1888 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_469 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1722 -> V_1726 ) ;
}
F_281 ( & V_7 -> V_1725 ) ;
return;
V_61:
F_281 ( & V_7 -> V_1725 ) ;
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_502 ( struct V_31 * V_53 ,
struct V_1889 * V_1890 )
{
struct V_1891 * V_1631 = V_1890 -> V_1892 ;
struct V_4 * V_1893 , * V_1894 , * V_286 ;
int V_159 , V_161 ;
V_1893 = F_47 (
V_53 , V_1895 ) ;
if ( ! V_1893 )
return - V_505 ;
for ( V_159 = 0 ; V_159 < V_1631 -> V_1896 ; V_159 ++ ) {
struct V_1897 * V_1633 = V_1631 -> V_1632 [ V_159 ] ;
V_1894 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1894 )
break;
if ( F_51 ( V_53 , V_603 , V_1633 -> V_604 . V_602 ,
V_1633 -> V_604 . V_604 ) ) {
F_503 ( V_53 , V_1894 ) ;
goto V_609;
}
if ( V_1633 -> V_366 ) {
V_286 = F_47 (
V_53 , V_1237 ) ;
if ( ! V_286 ) {
F_503 ( V_53 , V_1894 ) ;
goto V_609;
}
for ( V_161 = 0 ; V_161 < V_1633 -> V_366 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1633 -> V_367 [ V_161 ] ) ) {
F_503 ( V_53 , V_286 ) ;
F_503 ( V_53 , V_1894 ) ;
goto V_609;
}
}
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_1894 ) ;
}
V_609:
F_48 ( V_53 , V_1893 ) ;
return 0 ;
}
void F_504 ( struct V_1 * V_17 ,
struct V_1889 * V_1890 ,
T_12 V_1467 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
int V_1635 = 200 ;
F_505 ( V_17 -> V_18 , V_17 , V_1890 ) ;
if ( V_1890 )
V_1635 += V_1890 -> V_1898 ;
V_53 = F_74 ( V_1635 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1899 ) ;
if ( ! V_283 )
goto V_674;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_596 ) )
goto V_674;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_674;
if ( V_1890 ) {
struct V_4 * V_1900 ;
V_1900 = F_47 ( V_53 , V_1637 ) ;
if ( ! V_1900 )
goto V_674;
if ( V_1890 -> V_451 &&
F_29 ( V_53 , V_206 ) )
goto V_674;
if ( V_1890 -> V_1639 &&
F_29 ( V_53 , V_208 ) )
goto V_674;
if ( V_1890 -> V_1640 &&
F_29 ( V_53 , V_212 ) )
goto V_674;
if ( V_1890 -> V_1641 &&
F_29 ( V_53 , V_214 ) )
goto V_674;
if ( V_1890 -> V_1642 &&
F_29 ( V_53 , V_216 ) )
goto V_674;
if ( V_1890 -> V_1643 &&
F_29 ( V_53 , V_218 ) )
goto V_674;
if ( V_1890 -> V_1901 >= 0 &&
F_28 ( V_53 , V_228 ,
V_1890 -> V_1901 ) )
goto V_674;
if ( V_1890 -> V_1902 &&
F_29 ( V_53 , V_1903 ) )
goto V_674;
if ( V_1890 -> V_1904 &&
F_29 ( V_53 , V_1905 ) )
goto V_674;
if ( V_1890 -> V_1906 &&
F_29 ( V_53 ,
V_1907 ) )
goto V_674;
if ( V_1890 -> V_1908 ) {
V_22 V_1909 = V_1910 ;
V_22 V_1911 = V_1912 ;
if ( ! V_1890 -> V_1913 ) {
V_1909 =
V_1914 ;
V_1911 =
V_1915 ;
}
if ( V_1890 -> V_1916 &&
F_28 ( V_53 , V_1911 , V_1890 -> V_1916 ) )
goto V_674;
if ( F_51 ( V_53 , V_1909 , V_1890 -> V_1898 ,
V_1890 -> V_1908 ) )
goto V_674;
}
if ( V_1890 -> V_1892 &&
F_502 ( V_53 , V_1890 ) )
goto V_674;
F_48 ( V_53 , V_1900 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_674:
F_75 ( V_53 ) ;
}
void F_506 ( struct V_25 * V_549 , const T_2 * V_1509 ,
enum V_1516 V_1917 ,
T_3 V_992 , T_12 V_1467 )
{
struct V_1 * V_17 = V_549 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_507 ( V_17 -> V_18 , V_549 , V_1509 , V_1917 ,
V_992 ) ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1918 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_549 -> V_20 ) ||
F_56 ( V_53 , V_1518 , V_1917 ) ||
F_51 ( V_53 , V_557 , V_597 , V_1509 ) ||
( V_992 > 0 &&
F_55 ( V_53 , V_991 , V_992 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_1467 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_508 ( struct V_1919 * V_1920 ,
unsigned long V_282 ,
void * V_1921 )
{
struct V_1922 * V_1923 = V_1921 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1721 * V_1722 , * V_24 ;
if ( V_282 != V_1924 || V_1923 -> V_1925 != V_1926 )
return V_1927 ;
F_227 () ;
F_509 (rdev, &cfg80211_rdev_list, list) {
bool V_1928 = false ;
bool V_1929 = false ;
struct V_1259 * V_1290 =
F_228 ( V_7 -> V_1290 ) ;
if ( V_1290 && V_1923 -> V_49 &&
V_1290 -> V_649 == V_1923 -> V_49 )
V_1929 = true ;
F_509 (wdev, &rdev->wiphy.wdev_list, list) {
F_510 ( V_17 , V_1923 -> V_49 ) ;
if ( V_17 -> V_649 == V_1923 -> V_49 )
V_1928 = true ;
}
F_279 ( & V_7 -> V_1725 ) ;
F_511 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1722 -> V_1726 == V_1923 -> V_49 ) {
F_512 ( & V_1722 -> V_655 ) ;
F_41 ( V_1722 ) ;
break;
}
}
F_281 ( & V_7 -> V_1725 ) ;
if ( V_1928 ) {
struct V_1930 * V_1931 ;
V_1931 = F_38 ( sizeof( * V_1931 ) , V_1813 ) ;
if ( V_1931 ) {
V_1931 -> V_1726 = V_1923 -> V_49 ;
F_513 ( & V_7 -> V_1932 ) ;
F_395 ( & V_1931 -> V_655 , & V_7 -> V_1933 ) ;
F_514 ( & V_7 -> V_1932 ) ;
F_515 ( & V_7 -> V_1934 ) ;
}
} else if ( V_1929 ) {
V_1290 -> V_649 = 0 ;
if ( V_7 -> V_351 -> V_1292 &&
V_7 -> V_18 . V_51 & V_422 )
F_515 ( & V_7 -> V_1935 ) ;
}
}
F_229 () ;
F_516 ( V_1923 -> V_49 ) ;
return V_1936 ;
}
void F_517 ( struct V_25 * V_19 ,
struct V_1937 * V_1938 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_518 ( V_18 , V_19 , V_1938 ) ;
if ( ! V_1938 -> V_1939 )
return;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1940 ) ;
if ( ! V_283 )
goto V_609;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_557 , V_597 , V_1938 -> V_1939 ) )
goto V_609;
if ( V_1938 -> V_1325 &&
F_51 ( V_53 , V_700 , V_1938 -> V_1941 , V_1938 -> V_1325 ) )
goto V_609;
if ( V_1938 -> V_1942 &&
F_51 ( V_53 , V_1943 , V_1938 -> V_1944 ,
V_1938 -> V_1942 ) )
goto V_609;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1815 , V_135 ) ;
return;
V_609:
F_75 ( V_53 ) ;
}
void F_519 ( struct V_1 * V_17 , T_12 V_1467 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1726 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1743 )
return;
V_1726 = V_7 -> V_1743 ;
V_7 -> V_1743 = 0 ;
V_53 = F_74 ( V_610 , V_1467 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1945 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_596 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_469 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1726 ) ;
return;
V_61:
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_520 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_610 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1946 ) ;
if ( ! V_283 )
goto V_609;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_596 ) )
goto V_609;
F_66 ( V_53 , V_283 ) ;
F_128 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1815 , V_135 ) ;
return;
V_609:
F_75 ( V_53 ) ;
}
int F_521 ( void )
{
int V_35 ;
V_35 = F_522 ( & V_38 , V_1947 ,
V_1948 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_523 ( & V_1949 ) ;
if ( V_35 )
goto V_1950;
return 0 ;
V_1950:
F_524 ( & V_38 ) ;
return V_35 ;
}
void F_525 ( void )
{
F_526 ( & V_1949 ) ;
F_524 ( & V_38 ) ;
}
