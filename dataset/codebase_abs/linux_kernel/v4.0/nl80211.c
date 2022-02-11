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
F_6 (wdev, &rdev->wdev_list, list) {
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
F_6 (wdev, &tmp->wdev_list, list) {
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
F_6 (tmp, &(*rdev)->wdev_list, list) {
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
V_7 -> V_18 . V_317 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_318 ) &&
F_29 ( V_53 , V_319 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_320 ) &&
F_29 ( V_53 , V_321 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_322 ) &&
F_29 ( V_53 , V_323 ) )
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
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
case 1 :
if ( F_51 ( V_53 , V_331 ,
sizeof( V_22 ) * V_7 -> V_18 . V_332 ,
V_7 -> V_18 . V_333 ) )
goto V_61;
if ( F_56 ( V_53 , V_334 ,
V_7 -> V_18 . V_335 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_336 ) &&
F_29 ( V_53 , V_337 ) )
goto V_61;
if ( F_28 ( V_53 , V_338 ,
V_7 -> V_18 . V_339 ) ||
F_28 ( V_53 , V_340 ,
V_7 -> V_18 . V_341 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_342 ) &&
F_28 ( V_53 , V_343 ,
V_7 -> V_18 . V_344 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_339 ||
V_7 -> V_18 . V_341 ) &&
V_7 -> V_345 -> V_346 ) {
V_22 V_347 = 0 , V_348 = 0 ;
int V_349 ;
V_349 = F_62 ( V_7 , & V_347 , & V_348 ) ;
if ( ! V_349 ) {
if ( F_28 ( V_53 ,
V_350 ,
V_347 ) ||
F_28 ( V_53 ,
V_351 ,
V_348 ) )
goto V_61;
}
}
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
case 2 :
if ( F_46 ( V_53 , V_352 ,
V_7 -> V_18 . V_353 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
case 3 :
V_284 = F_47 ( V_53 , V_354 ) ;
if ( ! V_284 )
goto V_61;
for ( V_290 = V_282 -> V_355 ;
V_290 < V_356 ; V_290 ++ ) {
struct V_239 * V_240 ;
V_240 = V_7 -> V_18 . V_357 [ V_290 ] ;
if ( ! V_240 )
continue;
V_285 = F_47 ( V_53 , V_290 ) ;
if ( ! V_285 )
goto V_61;
switch ( V_282 -> V_358 ) {
case 0 :
if ( F_54 ( V_53 , V_240 ) )
goto V_61;
V_282 -> V_358 ++ ;
if ( V_282 -> V_330 )
break;
default:
V_286 = F_47 (
V_53 , V_359 ) ;
if ( ! V_286 )
goto V_61;
for ( V_159 = V_282 -> V_358 - 1 ;
V_159 < V_240 -> V_360 ;
V_159 ++ ) {
V_287 = F_47 ( V_53 , V_159 ) ;
if ( ! V_287 )
goto V_61;
V_55 = & V_240 -> V_361 [ V_159 ] ;
if ( F_27 (
V_53 , V_55 ,
V_282 -> V_330 ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
if ( V_282 -> V_330 )
break;
}
if ( V_159 < V_240 -> V_360 )
V_282 -> V_358 = V_159 + 2 ;
else
V_282 -> V_358 = 0 ;
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_285 ) ;
if ( V_282 -> V_330 ) {
if ( V_282 -> V_358 )
V_290 -- ;
break;
}
}
F_48 ( V_53 , V_284 ) ;
if ( V_290 < V_356 )
V_282 -> V_355 = V_290 + 1 ;
else
V_282 -> V_355 = 0 ;
if ( V_282 -> V_355 == 0 && V_282 -> V_358 == 0 )
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
case 4 :
V_288 = F_47 ( V_53 , V_362 ) ;
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
F_63 ( V_363 , V_364 ) ;
F_63 ( V_365 , V_366 ) ;
F_63 ( V_367 , V_368 ) ;
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
if ( V_7 -> V_18 . V_51 & V_397 )
F_63 ( V_398 , V_399 ) ;
F_63 ( V_400 , V_401 ) ;
F_63 ( V_402 , V_403 ) ;
F_63 ( V_404 , V_405 ) ;
if ( V_7 -> V_18 . V_51 & V_406 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_407 ) )
goto V_61;
}
if ( V_7 -> V_345 -> V_408 || V_7 -> V_345 -> V_369 ||
V_7 -> V_345 -> V_389 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_409 ) )
goto V_61;
}
F_63 ( V_410 , V_411 ) ;
if ( V_7 -> V_18 . V_51 & V_326 ) {
F_63 ( V_412 , V_413 ) ;
F_63 ( V_414 , V_415 ) ;
}
if ( V_7 -> V_18 . V_51 & V_416 )
F_63 ( V_417 , V_418 ) ;
F_63 ( V_419 , V_420 ) ;
F_63 ( V_421 , V_422 ) ;
if ( V_7 -> V_18 . V_51 & V_423 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_424 ) )
goto V_61;
}
F_63 ( V_425 , V_426 ) ;
F_63 ( V_427 , V_428 ) ;
#ifdef F_64
F_63 ( V_429 , V_430 ) ;
#endif
if ( V_282 -> V_330 ) {
F_63 ( V_431 , V_432 ) ;
F_63 ( V_433 , V_434 ) ;
if ( V_7 -> V_18 . V_51 & V_435 )
F_63 ( V_436 , V_437 ) ;
F_63 ( V_438 , V_439 ) ;
if ( V_7 -> V_18 . V_291 &
V_440 )
F_63 ( V_441 , V_442 ) ;
}
#undef F_63
if ( V_7 -> V_345 -> V_443 || V_7 -> V_345 -> V_379 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_444 ) )
goto V_61;
}
if ( V_7 -> V_345 -> V_445 || V_7 -> V_345 -> V_383 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_446 ) )
goto V_61;
}
F_48 ( V_53 , V_288 ) ;
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
case 5 :
if ( V_7 -> V_345 -> V_398 &&
( V_7 -> V_18 . V_51 & V_397 ) &&
F_28 ( V_53 ,
V_447 ,
V_7 -> V_18 . V_448 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_449 ) &&
F_29 ( V_53 , V_450 ) )
goto V_61;
if ( F_57 ( V_53 , V_268 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
case 6 :
#ifdef F_65
if ( F_52 ( V_53 , V_7 , V_282 -> V_330 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
#else
V_282 -> V_297 ++ ;
#endif
case 7 :
if ( F_46 ( V_53 , V_451 ,
V_7 -> V_18 . V_452 ) )
goto V_61;
if ( F_49 ( & V_7 -> V_18 , V_53 ,
V_282 -> V_330 ) )
goto V_61;
V_282 -> V_297 ++ ;
if ( V_282 -> V_330 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_51 & V_453 ) &&
F_28 ( V_53 , V_454 ,
V_7 -> V_18 . V_455 ) )
goto V_61;
V_291 = V_7 -> V_18 . V_291 ;
if ( V_282 -> V_330 )
V_291 |= V_456 ;
if ( F_28 ( V_53 , V_457 , V_291 ) )
goto V_61;
if ( V_7 -> V_18 . V_458 &&
F_51 ( V_53 , V_459 ,
sizeof( * V_7 -> V_18 . V_458 ) ,
V_7 -> V_18 . V_458 ) )
goto V_61;
if ( V_7 -> V_18 . V_51 & V_453 &&
V_7 -> V_18 . V_460 &&
F_28 ( V_53 , V_461 ,
V_7 -> V_18 . V_460 ) )
goto V_61;
V_282 -> V_297 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_462 &&
( F_51 ( V_53 , V_463 ,
V_7 -> V_18 . V_464 ,
V_7 -> V_18 . V_462 ) ||
F_51 ( V_53 , V_465 ,
V_7 -> V_18 . V_464 ,
V_7 -> V_18 . V_466 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_467 &&
F_51 ( V_53 , V_468 ,
sizeof( * V_7 -> V_18 . V_467 ) ,
V_7 -> V_18 . V_467 ) )
goto V_61;
V_282 -> V_297 ++ ;
break;
case 10 :
if ( F_53 ( V_53 , V_7 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_469 ) &&
( F_29 ( V_53 , V_470 ) ||
F_29 ( V_53 , V_471 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_472 &&
F_28 ( V_53 , V_473 ,
V_7 -> V_18 . V_472 ) )
goto V_61;
V_282 -> V_297 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_474 ) {
const struct V_475 * V_30 ;
struct V_4 * V_476 ;
V_476 = F_47 ( V_53 , V_477 ) ;
if ( ! V_476 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_474 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_478 [ V_159 ] . V_30 ;
if ( F_51 ( V_53 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_476 ) ;
}
if ( V_7 -> V_18 . V_479 ) {
const struct V_475 * V_30 ;
struct V_4 * V_476 ;
V_476 = F_47 ( V_53 ,
V_480 ) ;
if ( ! V_476 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_479 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_481 [ V_159 ] ;
if ( F_51 ( V_53 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_476 ) ;
}
V_282 -> V_297 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_51 & V_435 &&
F_56 ( V_53 , V_482 ,
V_7 -> V_18 . V_483 ) )
goto V_61;
if ( V_7 -> V_18 . V_484 & V_485 &&
F_29 ( V_53 , V_486 ) )
goto V_61;
if ( F_51 ( V_53 , V_487 ,
sizeof( V_7 -> V_18 . V_488 ) ,
V_7 -> V_18 . V_488 ) )
goto V_61;
V_282 -> V_297 = 0 ;
break;
}
V_296:
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_281 * V_282 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_490 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_490 )
return 0 ;
V_282 -> V_330 = V_95 [ V_491 ] ;
if ( V_95 [ V_26 ] )
V_282 -> V_492 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_282 -> V_492 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
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
V_282 -> V_492 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_490 ;
struct V_281 * V_282 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_282 ) {
V_282 = F_38 ( sizeof( * V_282 ) , V_135 ) ;
if ( ! V_282 ) {
F_20 () ;
return - V_136 ;
}
V_282 -> V_492 = - 1 ;
V_490 = F_68 ( V_32 , V_34 , V_282 ) ;
if ( V_490 ) {
F_41 ( V_282 ) ;
F_20 () ;
return V_490 ;
}
V_34 -> args [ 0 ] = ( long ) V_282 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_282 -> V_493 )
continue;
if ( V_282 -> V_492 != - 1 &&
V_282 -> V_492 != V_7 -> V_14 )
continue;
do {
V_490 = F_58 ( V_7 , V_295 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 ,
V_495 , V_282 ) ;
if ( V_490 < 0 ) {
if ( ( V_490 == - V_91 || V_490 == - V_489 ) &&
! V_32 -> V_47 && ! V_282 -> V_330 &&
V_34 -> V_496 < 4096 ) {
V_34 -> V_496 = 4096 ;
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
V_282 -> V_493 = V_105 ;
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
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_281 V_282 = {} ;
V_53 = F_74 ( 4096 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_58 ( V_7 , V_295 , V_53 ,
V_30 -> V_498 , V_30 -> V_499 , 0 ,
& V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_500 * V_501 )
{
if ( ! V_95 [ V_502 ] || ! V_95 [ V_503 ] ||
! V_95 [ V_504 ] || ! V_95 [ V_505 ] ||
! V_95 [ V_506 ] )
return - V_16 ;
V_501 -> V_507 = F_34 ( V_95 [ V_502 ] ) ;
V_501 -> V_508 = F_78 ( V_95 [ V_503 ] ) ;
V_501 -> V_509 = F_78 ( V_95 [ V_504 ] ) ;
V_501 -> V_510 = F_78 ( V_95 [ V_505 ] ) ;
V_501 -> V_511 = F_34 ( V_95 [ V_506 ] ) ;
if ( V_501 -> V_507 >= V_512 )
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
struct V_513 * V_514 )
{
V_22 V_515 ;
if ( ! V_30 -> V_5 [ V_516 ] )
return - V_16 ;
V_515 = F_4 ( V_30 -> V_5 [ V_516 ] ) ;
V_514 -> V_55 = F_45 ( & V_7 -> V_18 , V_515 ) ;
V_514 -> V_517 = V_518 ;
V_514 -> V_519 = V_515 ;
V_514 -> V_520 = 0 ;
if ( ! V_514 -> V_55 || V_514 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_521 ] ) {
enum V_522 V_523 ;
V_523 = F_4 (
V_30 -> V_5 [ V_521 ] ) ;
switch ( V_523 ) {
case V_524 :
case V_525 :
case V_526 :
case V_527 :
F_81 ( V_514 , V_514 -> V_55 ,
V_523 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_528 ] ) {
V_514 -> V_517 =
F_4 ( V_30 -> V_5 [ V_528 ] ) ;
if ( V_30 -> V_5 [ V_529 ] )
V_514 -> V_519 =
F_4 (
V_30 -> V_5 [ V_529 ] ) ;
if ( V_30 -> V_5 [ V_530 ] )
V_514 -> V_520 =
F_4 (
V_30 -> V_5 [ V_530 ] ) ;
}
if ( ! F_82 ( V_514 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_514 ,
V_62 ) )
return - V_16 ;
if ( ( V_514 -> V_517 == V_531 ||
V_514 -> V_517 == V_532 ) &&
! ( V_7 -> V_18 . V_51 & V_469 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_533 ,
struct V_29 * V_30 )
{
struct V_513 V_514 ;
int V_8 ;
enum V_272 V_141 = V_153 ;
struct V_1 * V_17 = NULL ;
if ( V_533 )
V_17 = V_533 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_534 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_85 ( & V_7 -> V_18 , & V_514 , V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_535 ) {
if ( ! V_533 || ! V_7 -> V_345 -> V_536 ||
! ( V_7 -> V_18 . V_291 &
V_537 ) ) {
V_8 = - V_538 ;
break;
}
if ( V_514 . V_55 != V_17 -> V_539 . V_55 ) {
V_8 = - V_538 ;
break;
}
V_8 = F_86 ( V_7 , V_533 , & V_514 ) ;
if ( V_8 )
break;
}
V_17 -> V_539 = V_514 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_87 ( V_7 , V_17 , & V_514 ) ;
break;
case V_153 :
V_8 = F_88 ( V_7 , & V_514 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_497 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
const T_2 * V_540 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( F_91 ( V_533 ) )
return - V_538 ;
if ( ! V_7 -> V_345 -> V_410 )
return - V_534 ;
if ( V_17 -> V_141 != V_155 )
return - V_534 ;
V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
return F_92 ( V_7 , V_533 , V_540 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_542 = 0 ;
struct V_4 * V_543 ;
V_22 V_544 ;
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
if ( V_30 -> V_5 [ V_545 ] ) {
struct V_500 V_501 ;
struct V_4 * V_95 [ V_546 + 1 ] ;
if ( ! V_7 -> V_345 -> V_547 )
return - V_534 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_548 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_546 ,
F_23 ( V_543 ) ,
F_24 ( V_543 ) ,
V_549 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_501 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_501 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_516 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_550 ] ) {
struct V_1 * V_551 = V_17 ;
enum V_552 type ;
int V_105 , V_553 = 0 ;
if ( ! ( V_7 -> V_18 . V_291 & V_554 ) )
V_551 = NULL ;
if ( ! V_7 -> V_345 -> V_555 )
return - V_534 ;
V_105 = V_550 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_556 ] &&
( type != V_557 ) )
return - V_16 ;
if ( type != V_557 ) {
V_105 = V_556 ;
V_553 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_551 , type , V_553 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_350 ] &&
V_30 -> V_5 [ V_351 ] ) {
V_22 V_347 , V_348 ;
if ( ( ! V_7 -> V_18 . V_339 &&
! V_7 -> V_18 . V_341 ) ||
! V_7 -> V_345 -> V_558 )
return - V_534 ;
V_347 = F_4 ( V_30 -> V_5 [ V_350 ] ) ;
V_348 = F_4 ( V_30 -> V_5 [ V_351 ] ) ;
if ( ( ~ V_347 && ( V_347 & ~ V_7 -> V_18 . V_339 ) ) ||
( ~ V_348 && ( V_348 & ~ V_7 -> V_18 . V_341 ) ) )
return - V_16 ;
V_347 = V_347 & V_7 -> V_18 . V_339 ;
V_348 = V_348 & V_7 -> V_18 . V_341 ;
V_8 = F_99 ( V_7 , V_347 , V_348 ) ;
if ( V_8 )
return V_8 ;
}
V_544 = 0 ;
if ( V_30 -> V_5 [ V_298 ] ) {
V_299 = F_34 (
V_30 -> V_5 [ V_298 ] ) ;
if ( V_299 == 0 )
return - V_16 ;
V_544 |= V_559 ;
}
if ( V_30 -> V_5 [ V_300 ] ) {
V_301 = F_34 (
V_30 -> V_5 [ V_300 ] ) ;
if ( V_301 == 0 )
return - V_16 ;
V_544 |= V_560 ;
}
if ( V_30 -> V_5 [ V_302 ] ) {
V_303 = F_4 (
V_30 -> V_5 [ V_302 ] ) ;
if ( V_303 < 256 )
return - V_16 ;
if ( V_303 != ( V_22 ) - 1 ) {
V_303 &= ~ 0x1 ;
}
V_544 |= V_561 ;
}
if ( V_30 -> V_5 [ V_304 ] ) {
V_305 = F_4 (
V_30 -> V_5 [ V_304 ] ) ;
V_544 |= V_562 ;
}
if ( V_30 -> V_5 [ V_306 ] ) {
if ( V_30 -> V_5 [ V_563 ] )
return - V_16 ;
V_307 = F_34 (
V_30 -> V_5 [ V_306 ] ) ;
V_544 |= V_564 ;
}
if ( V_30 -> V_5 [ V_563 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_565 ) )
return - V_534 ;
V_544 |= V_566 ;
}
if ( V_544 ) {
T_2 V_567 , V_568 ;
V_22 V_569 , V_570 ;
T_2 V_571 ;
if ( ! V_7 -> V_345 -> V_572 )
return - V_534 ;
V_567 = V_7 -> V_18 . V_299 ;
V_568 = V_7 -> V_18 . V_301 ;
V_569 = V_7 -> V_18 . V_303 ;
V_570 = V_7 -> V_18 . V_305 ;
V_571 = V_7 -> V_18 . V_307 ;
if ( V_544 & V_559 )
V_7 -> V_18 . V_299 = V_299 ;
if ( V_544 & V_560 )
V_7 -> V_18 . V_301 = V_301 ;
if ( V_544 & V_561 )
V_7 -> V_18 . V_303 = V_303 ;
if ( V_544 & V_562 )
V_7 -> V_18 . V_305 = V_305 ;
if ( V_544 & V_564 )
V_7 -> V_18 . V_307 = V_307 ;
V_8 = F_100 ( V_7 , V_544 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_299 = V_567 ;
V_7 -> V_18 . V_301 = V_568 ;
V_7 -> V_18 . V_303 = V_569 ;
V_7 -> V_18 . V_305 = V_570 ;
V_7 -> V_18 . V_307 = V_571 ;
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
const struct V_513 * V_514 )
{
if ( F_59 ( ! F_82 ( V_514 ) ) )
return - V_16 ;
if ( F_28 ( V_53 , V_516 ,
V_514 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_514 -> V_517 ) {
case V_518 :
case V_573 :
case V_574 :
if ( F_28 ( V_53 , V_521 ,
F_102 ( V_514 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_528 , V_514 -> V_517 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_529 , V_514 -> V_519 ) )
return - V_91 ;
if ( V_514 -> V_520 &&
F_28 ( V_53 , V_530 , V_514 -> V_520 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_575 )
{
struct V_25 * V_533 = V_17 -> V_19 ;
T_2 V_52 = V_576 ;
void * V_283 ;
if ( V_575 )
V_52 = V_577 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( V_533 &&
( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_60 ( V_53 , V_578 , V_533 -> V_579 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_580 , V_17 -> V_141 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_541 , V_581 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_293 ,
V_7 -> V_582 ^
( V_294 << 2 ) ) )
goto V_61;
if ( V_7 -> V_345 -> V_583 ) {
int V_490 ;
struct V_513 V_514 ;
V_490 = F_106 ( V_7 , V_17 , & V_514 ) ;
if ( V_490 == 0 ) {
if ( F_101 ( V_53 , & V_514 ) )
goto V_61;
}
}
if ( V_17 -> V_584 ) {
if ( F_51 ( V_53 , V_585 , V_17 -> V_584 , V_17 -> V_586 ) )
goto V_61;
}
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_107 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_587 = 0 ;
int V_588 = 0 ;
int V_589 = V_34 -> args [ 0 ] ;
int V_590 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_587 < V_589 ) {
V_587 ++ ;
continue;
}
V_588 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_588 < V_590 ) {
V_588 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_7 , V_17 , false ) < 0 ) {
goto V_591;
}
V_588 ++ ;
}
V_587 ++ ;
}
V_591:
F_20 () ;
V_34 -> args [ 0 ] = V_587 ;
V_34 -> args [ 1 ] = V_588 ;
return V_32 -> V_47 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_103 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_109 ( struct V_4 * V_593 , V_22 * V_594 )
{
struct V_4 * V_51 [ V_595 + 1 ] ;
int V_596 ;
* V_594 = 0 ;
if ( ! V_593 )
return - V_16 ;
if ( F_33 ( V_51 , V_595 ,
V_593 , V_597 ) )
return - V_16 ;
for ( V_596 = 1 ; V_596 <= V_595 ; V_596 ++ )
if ( V_51 [ V_596 ] )
* V_594 |= ( 1 << V_596 ) ;
return 0 ;
}
static int F_110 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_598 ,
enum V_272 V_141 )
{
if ( ! V_598 ) {
if ( V_19 && ( V_19 -> V_599 & V_600 ) )
return - V_538 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_51 & V_601 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_51 & V_602 )
return 0 ;
break;
default:
break;
}
return - V_534 ;
}
static int F_111 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_603 V_137 ;
int V_35 ;
enum V_272 V_604 , V_605 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
V_22 V_606 , * V_51 = NULL ;
bool V_607 = false ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_604 = V_605 = V_533 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_580 ] ) {
V_605 = F_4 ( V_30 -> V_5 [ V_580 ] ) ;
if ( V_604 != V_605 )
V_607 = true ;
if ( V_605 > V_608 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_609 ] ) {
struct V_1 * V_17 = V_533 -> V_28 ;
if ( V_605 != V_145 )
return - V_16 ;
if ( F_91 ( V_533 ) )
return - V_538 ;
F_112 ( V_17 ) ;
F_113 ( V_610 !=
V_611 ) ;
V_17 -> V_612 =
F_24 ( V_30 -> V_5 [ V_609 ] ) ;
memcpy ( V_17 -> V_586 , F_23 ( V_30 -> V_5 [ V_609 ] ) ,
V_17 -> V_612 ) ;
F_114 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_613 ] ) {
V_137 . V_598 = ! ! F_34 ( V_30 -> V_5 [ V_613 ] ) ;
V_607 = true ;
V_35 = F_110 ( V_7 , V_533 , V_137 . V_598 , V_605 ) ;
if ( V_35 )
return V_35 ;
} else {
V_137 . V_598 = - 1 ;
}
if ( V_30 -> V_5 [ V_614 ] ) {
if ( V_605 != V_153 )
return - V_16 ;
V_35 = F_109 ( V_30 -> V_5 [ V_614 ] ,
& V_606 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_606 ;
V_607 = true ;
}
if ( V_51 && ( * V_51 & V_615 ) &&
! ( V_7 -> V_18 . V_291 & V_616 ) )
return - V_534 ;
if ( V_607 )
V_35 = F_115 ( V_7 , V_533 , V_605 , V_51 , & V_137 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_137 . V_598 != - 1 )
V_533 -> V_28 -> V_598 = V_137 . V_598 ;
return V_35 ;
}
static int F_116 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_603 V_137 ;
struct V_1 * V_17 ;
struct V_31 * V_53 , * V_617 ;
int V_35 ;
enum V_272 type = V_151 ;
V_22 V_51 ;
F_117 ( V_7 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_578 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_580 ] ) {
type = F_4 ( V_30 -> V_5 [ V_580 ] ) ;
if ( type > V_608 )
return - V_16 ;
}
if ( ! V_7 -> V_345 -> V_363 ||
! ( V_7 -> V_18 . V_353 & ( 1 << type ) ) )
return - V_534 ;
if ( ( type == V_154 ||
V_7 -> V_18 . V_291 & V_618 ) &&
V_30 -> V_5 [ V_541 ] ) {
F_118 ( V_137 . V_619 , V_30 -> V_5 [ V_541 ] ,
V_581 ) ;
if ( ! F_119 ( V_137 . V_619 ) )
return - V_620 ;
}
if ( V_30 -> V_5 [ V_613 ] ) {
V_137 . V_598 = ! ! F_34 ( V_30 -> V_5 [ V_613 ] ) ;
V_35 = F_110 ( V_7 , NULL , V_137 . V_598 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_109 ( type == V_153 ?
V_30 -> V_5 [ V_614 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_615 ) &&
! ( V_7 -> V_18 . V_291 & V_616 ) )
return - V_534 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_17 = F_120 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_578 ] ) ,
type , V_35 ? NULL : & V_51 , & V_137 ) ;
if ( F_59 ( ! V_17 ) ) {
F_75 ( V_53 ) ;
return - V_621 ;
} else if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_622 ] )
V_17 -> V_623 = V_30 -> V_498 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_609 ] )
break;
F_112 ( V_17 ) ;
F_113 ( V_610 !=
V_611 ) ;
V_17 -> V_612 =
F_24 ( V_30 -> V_5 [ V_609 ] ) ;
memcpy ( V_17 -> V_586 , F_23 ( V_30 -> V_5 [ V_609 ] ) ,
V_17 -> V_612 ) ;
F_114 ( V_17 ) ;
break;
case V_154 :
F_121 ( & V_17 -> V_624 ) ;
F_122 ( & V_17 -> V_625 ) ;
F_123 ( & V_17 -> V_626 ) ;
F_122 ( & V_17 -> V_627 ) ;
F_123 ( & V_17 -> V_628 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_124 ( & V_17 -> V_629 , & V_7 -> V_630 ) ;
V_7 -> V_582 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
V_617 = F_74 ( V_592 , V_135 ) ;
if ( V_617 ) {
if ( F_103 ( V_617 , 0 , 0 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_617 ) ;
goto V_591;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_617 , 0 , V_631 ,
V_135 ) ;
}
V_591:
return F_76 ( V_53 , V_30 ) ;
}
static int F_126 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
struct V_31 * V_53 ;
int V_632 ;
if ( ! V_7 -> V_345 -> V_633 )
return - V_534 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( V_53 && F_103 ( V_53 , 0 , 0 , 0 , V_7 , V_17 , true ) < 0 ) {
F_75 ( V_53 ) ;
V_53 = NULL ;
}
if ( ! V_17 -> V_19 )
V_30 -> V_497 [ 1 ] = NULL ;
V_632 = F_127 ( V_7 , V_17 ) ;
if ( V_632 >= 0 && V_53 )
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_631 ,
V_135 ) ;
else
F_75 ( V_53 ) ;
return V_632 ;
}
static int F_128 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_3 V_634 ;
if ( ! V_30 -> V_5 [ V_635 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_421 )
return - V_534 ;
V_634 = F_78 ( V_30 -> V_5 [ V_635 ] ) ;
return F_129 ( V_7 , V_533 , V_634 ) ;
}
static void F_130 ( void * V_165 , struct V_636 * V_137 )
{
struct V_4 * V_92 ;
struct V_637 * V_638 = V_165 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_638 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_638 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_638 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_638 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_638 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_638 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_638 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_638 -> V_53 , V_123 , V_638 -> V_105 ) )
goto V_61;
F_48 ( V_638 -> V_53 , V_92 ) ;
return;
V_61:
V_638 -> error = 1 ;
}
static int F_131 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 V_639 = 0 ;
const T_2 * V_640 = NULL ;
bool V_641 ;
struct V_637 V_638 = {
. error = 0 ,
} ;
void * V_283 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_639 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_639 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_541 ] )
V_640 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_641 = ! ! V_640 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_642 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_642 >= V_114 )
return - V_16 ;
if ( V_642 != V_643 &&
V_642 != V_644 )
return - V_16 ;
V_641 = V_642 == V_644 ;
}
if ( ! V_7 -> V_345 -> V_645 )
return - V_534 ;
if ( ! V_641 && V_640 && ! ( V_7 -> V_18 . V_51 & V_318 ) )
return - V_646 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_647 ) ;
if ( ! V_283 )
goto V_61;
V_638 . V_53 = V_53 ;
V_638 . V_105 = V_639 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_639 ) )
goto V_61;
if ( V_640 &&
F_51 ( V_53 , V_541 , V_581 , V_640 ) )
goto V_61;
V_35 = F_132 ( V_7 , V_533 , V_639 , V_641 , V_640 , & V_638 ,
F_130 ) ;
if ( V_35 )
goto V_648;
if ( V_638 . error )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_648:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_133 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_112 ( V_533 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_345 -> V_649 ) {
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_42 ( V_533 -> V_28 ) ;
if ( V_35 )
goto V_591;
V_35 = F_134 ( V_7 , V_533 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_591;
#ifdef F_135
V_533 -> V_28 -> V_650 . V_651 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_591;
}
if ( ! V_7 -> V_345 -> V_652 ) {
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_42 ( V_533 -> V_28 ) ;
if ( V_35 )
goto V_591;
V_35 = F_136 ( V_7 , V_533 , V_92 . V_105 ) ;
if ( V_35 )
goto V_591;
#ifdef F_135
V_533 -> V_28 -> V_650 . V_653 = V_92 . V_105 ;
#endif
}
V_591:
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_137 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_640 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_541 ] )
V_640 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_640 )
V_92 . type = V_644 ;
else
V_92 . type = V_643 ;
}
if ( V_92 . type != V_644 &&
V_92 . type != V_643 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_367 )
return - V_534 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_644 ,
V_640 ) )
return - V_16 ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_42 ( V_533 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_138 ( V_7 , V_533 , V_92 . V_105 ,
V_92 . type == V_644 ,
V_640 , & V_92 . V_107 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_139 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_640 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_541 ] )
V_640 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_640 )
V_92 . type = V_644 ;
else
V_92 . type = V_643 ;
}
if ( V_92 . type != V_644 &&
V_92 . type != V_643 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_654 )
return - V_534 ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_42 ( V_533 -> V_28 ) ;
if ( V_92 . type == V_643 && V_640 &&
! ( V_7 -> V_18 . V_51 & V_318 ) )
V_35 = - V_646 ;
if ( ! V_35 )
V_35 = F_140 ( V_7 , V_533 , V_92 . V_105 ,
V_92 . type == V_644 ,
V_640 ) ;
#ifdef F_135
if ( ! V_35 ) {
if ( V_92 . V_105 == V_533 -> V_28 -> V_650 . V_651 )
V_533 -> V_28 -> V_650 . V_651 = - 1 ;
else if ( V_92 . V_105 == V_533 -> V_28 -> V_650 . V_653 )
V_533 -> V_28 -> V_650 . V_653 = - 1 ;
}
#endif
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_141 ( struct V_4 * V_655 )
{
struct V_4 * V_45 ;
int V_656 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_581 )
return - V_16 ;
V_656 ++ ;
}
return V_656 ;
}
static struct V_657 * F_142 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_658 V_659 ;
struct V_4 * V_45 ;
struct V_657 * V_660 ;
int V_159 = 0 , V_656 , V_24 ;
if ( ! V_18 -> V_460 )
return F_3 ( - V_534 ) ;
if ( ! V_30 -> V_5 [ V_661 ] )
return F_3 ( - V_16 ) ;
V_659 = F_4 ( V_30 -> V_5 [ V_661 ] ) ;
if ( V_659 != V_662 &&
V_659 != V_663 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_664 ] )
return F_3 ( - V_16 ) ;
V_656 = F_141 ( V_30 -> V_5 [ V_664 ] ) ;
if ( V_656 < 0 )
return F_3 ( V_656 ) ;
if ( V_656 > V_18 -> V_460 )
return F_3 ( - V_665 ) ;
V_660 = F_38 ( sizeof( * V_660 ) + ( sizeof( struct V_666 ) * V_656 ) ,
V_135 ) ;
if ( ! V_660 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_660 -> V_667 [ V_159 ] . V_668 , F_23 ( V_45 ) , V_581 ) ;
V_159 ++ ;
}
V_660 -> V_669 = V_656 ;
V_660 -> V_659 = V_659 ;
return V_660 ;
}
static int F_143 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_657 * V_660 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_534 ;
if ( ! V_533 -> V_28 -> V_535 )
return - V_16 ;
V_660 = F_142 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_660 ) )
return F_18 ( V_660 ) ;
V_35 = F_144 ( V_7 , V_533 , V_660 ) ;
F_41 ( V_660 ) ;
return V_35 ;
}
static int F_145 ( struct V_4 * V_5 [] ,
struct V_670 * V_671 )
{
bool V_672 = false ;
if ( ! F_22 ( V_5 [ V_673 ] ) ||
! F_22 ( V_5 [ V_674 ] ) ||
! F_22 ( V_5 [ V_675 ] ) ||
! F_22 ( V_5 [ V_676 ] ) )
return - V_16 ;
memset ( V_671 , 0 , sizeof( * V_671 ) ) ;
if ( V_5 [ V_677 ] ) {
V_671 -> V_678 = F_23 ( V_5 [ V_677 ] ) ;
V_671 -> V_679 = F_24 ( V_5 [ V_677 ] ) ;
if ( ! V_671 -> V_679 )
return - V_16 ;
V_672 = true ;
}
if ( V_5 [ V_673 ] ) {
V_671 -> V_680 = F_23 ( V_5 [ V_673 ] ) ;
V_671 -> V_681 = F_24 ( V_5 [ V_673 ] ) ;
V_672 = true ;
}
if ( ! V_672 )
return - V_16 ;
if ( V_5 [ V_674 ] ) {
V_671 -> V_682 = F_23 ( V_5 [ V_674 ] ) ;
V_671 -> V_683 = F_24 ( V_5 [ V_674 ] ) ;
}
if ( V_5 [ V_675 ] ) {
V_671 -> V_684 =
F_23 ( V_5 [ V_675 ] ) ;
V_671 -> V_685 =
F_24 ( V_5 [ V_675 ] ) ;
}
if ( V_5 [ V_676 ] ) {
V_671 -> V_686 =
F_23 ( V_5 [ V_676 ] ) ;
V_671 -> V_687 =
F_24 ( V_5 [ V_676 ] ) ;
}
if ( V_5 [ V_688 ] ) {
V_671 -> V_689 = F_23 ( V_5 [ V_688 ] ) ;
V_671 -> V_690 = F_24 ( V_5 [ V_688 ] ) ;
}
return 0 ;
}
static bool F_146 ( struct V_6 * V_7 ,
struct V_691 * V_137 )
{
struct V_1 * V_17 ;
bool V_490 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_539 . V_55 )
continue;
V_137 -> V_514 = V_17 -> V_539 ;
V_490 = true ;
break;
}
return V_490 ;
}
static bool F_147 ( struct V_6 * V_7 ,
enum V_692 V_693 ,
enum V_280 V_52 )
{
if ( V_693 > V_694 )
return false ;
switch ( V_52 ) {
case V_695 :
if ( ! ( V_7 -> V_18 . V_291 & V_696 ) &&
V_693 == V_697 )
return false ;
return true ;
case V_444 :
case V_698 :
if ( V_693 == V_697 )
return false ;
return true ;
default:
return false ;
}
}
static int F_148 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_691 V_137 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_369 )
return - V_534 ;
if ( V_17 -> V_535 )
return - V_699 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_700 ] ||
! V_30 -> V_5 [ V_701 ] ||
! V_30 -> V_5 [ V_677 ] )
return - V_16 ;
V_35 = F_145 ( V_30 -> V_5 , & V_137 . V_702 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_535 =
F_4 ( V_30 -> V_5 [ V_700 ] ) ;
V_137 . V_703 =
F_4 ( V_30 -> V_5 [ V_701 ] ) ;
V_35 = F_149 ( V_7 , V_137 . V_535 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_585 ] ) {
V_137 . V_586 = F_23 ( V_30 -> V_5 [ V_585 ] ) ;
V_137 . V_584 =
F_24 ( V_30 -> V_5 [ V_585 ] ) ;
if ( V_137 . V_584 == 0 ||
V_137 . V_584 > V_610 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_704 ] ) {
V_137 . V_705 = F_4 (
V_30 -> V_5 [ V_704 ] ) ;
if ( V_137 . V_705 != V_706 &&
V_137 . V_705 != V_707 &&
V_137 . V_705 != V_708 )
return - V_16 ;
}
V_137 . V_709 = ! ! V_30 -> V_5 [ V_710 ] ;
if ( V_30 -> V_5 [ V_711 ] ) {
V_137 . V_693 = F_4 (
V_30 -> V_5 [ V_711 ] ) ;
if ( ! F_147 ( V_7 , V_137 . V_693 ,
V_698 ) )
return - V_16 ;
} else
V_137 . V_693 = V_712 ;
V_35 = F_150 ( V_7 , V_30 , & V_137 . V_713 ,
V_714 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_715 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_716 ) )
return - V_534 ;
V_137 . V_717 = F_78 (
V_30 -> V_5 [ V_715 ] ) ;
}
if ( V_30 -> V_5 [ V_718 ] ) {
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_719 =
F_34 ( V_30 -> V_5 [ V_718 ] ) ;
if ( V_137 . V_719 > 127 )
return - V_16 ;
if ( V_137 . V_719 != 0 &&
! ( V_7 -> V_18 . V_291 & V_720 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_721 ] ) {
T_2 V_24 ;
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_721 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_722 = V_24 ;
if ( V_137 . V_722 != 0 &&
! ( V_7 -> V_18 . V_291 & V_723 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_516 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_514 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_539 . V_55 ) {
V_137 . V_514 = V_17 -> V_539 ;
} else if ( ! F_146 ( V_7 , & V_137 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_514 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_661 ] ) {
V_137 . V_660 = F_142 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_660 ) )
return F_18 ( V_137 . V_660 ) ;
}
if ( V_30 -> V_5 [ V_724 ] ) {
V_137 . V_725 =
F_34 ( V_30 -> V_5 [ V_724 ] ) ;
switch ( V_137 . V_725 ) {
case V_726 :
break;
case V_727 :
if ( ! ( V_7 -> V_18 . V_291 &
V_728 ) )
return - V_16 ;
break;
case V_729 :
if ( ! ( V_7 -> V_18 . V_291 &
V_730 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_137 . V_725 = V_726 ;
}
F_112 ( V_17 ) ;
V_35 = F_151 ( V_7 , V_533 , & V_137 ) ;
if ( ! V_35 ) {
V_17 -> V_539 = V_137 . V_514 ;
V_17 -> V_535 = V_137 . V_535 ;
V_17 -> V_514 = V_137 . V_514 ;
V_17 -> V_584 = V_137 . V_584 ;
memcpy ( V_17 -> V_586 , V_137 . V_586 , V_17 -> V_584 ) ;
}
F_114 ( V_17 ) ;
F_41 ( V_137 . V_660 ) ;
return V_35 ;
}
static int F_152 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_670 V_137 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_731 )
return - V_534 ;
if ( ! V_17 -> V_535 )
return - V_16 ;
V_35 = F_145 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
V_35 = F_153 ( V_7 , V_533 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_154 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
return F_155 ( V_7 , V_533 , false ) ;
}
static int F_156 ( struct V_29 * V_30 ,
enum V_272 V_141 ,
struct V_732 * V_137 )
{
struct V_4 * V_51 [ V_733 + 1 ] ;
struct V_4 * V_593 ;
int V_596 ;
V_593 = V_30 -> V_5 [ V_734 ] ;
if ( V_593 ) {
struct V_735 * V_736 ;
V_736 = F_23 ( V_593 ) ;
V_137 -> V_737 = V_736 -> V_738 ;
V_137 -> V_739 = V_736 -> V_740 ;
V_137 -> V_739 &= V_137 -> V_737 ;
if ( ( V_137 -> V_737 |
V_137 -> V_739 ) & F_157 ( V_741 ) )
return - V_16 ;
return 0 ;
}
V_593 = V_30 -> V_5 [ V_742 ] ;
if ( ! V_593 )
return 0 ;
if ( F_33 ( V_51 , V_733 ,
V_593 , V_743 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_737 = F_157 ( V_744 ) |
F_157 ( V_745 ) |
F_157 ( V_746 ) |
F_157 ( V_747 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_737 = F_157 ( V_744 ) |
F_157 ( V_748 ) ;
break;
case V_145 :
V_137 -> V_737 = F_157 ( V_749 ) |
F_157 ( V_747 ) |
F_157 ( V_744 ) ;
default:
return - V_16 ;
}
for ( V_596 = 1 ; V_596 <= V_733 ; V_596 ++ ) {
if ( V_51 [ V_596 ] ) {
V_137 -> V_739 |= ( 1 << V_596 ) ;
if ( V_596 > V_750 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_158 ( struct V_31 * V_53 , struct V_751 * V_30 ,
int V_45 )
{
struct V_4 * V_244 ;
V_22 V_264 ;
T_3 V_752 ;
enum V_753 V_754 ;
V_244 = F_47 ( V_53 , V_45 ) ;
if ( ! V_244 )
return false ;
V_264 = F_159 ( V_30 ) ;
V_752 = V_264 < ( 1UL << 16 ) ? V_264 : 0 ;
if ( V_264 > 0 &&
F_28 ( V_53 , V_755 , V_264 ) )
return false ;
if ( V_752 > 0 &&
F_55 ( V_53 , V_756 , V_752 ) )
return false ;
switch ( V_30 -> V_757 ) {
case V_758 :
V_754 = V_759 ;
break;
case V_760 :
V_754 = V_761 ;
break;
default:
F_59 ( 1 ) ;
case V_762 :
V_754 = 0 ;
break;
case V_763 :
V_754 = V_764 ;
break;
case V_765 :
V_754 = V_766 ;
break;
case V_767 :
V_754 = V_768 ;
break;
}
if ( V_754 && F_29 ( V_53 , V_754 ) )
return false ;
if ( V_30 -> V_51 & V_769 ) {
if ( F_56 ( V_53 , V_770 , V_30 -> V_248 ) )
return false ;
if ( V_30 -> V_51 & V_771 &&
F_29 ( V_53 , V_772 ) )
return false ;
} else if ( V_30 -> V_51 & V_773 ) {
if ( F_56 ( V_53 , V_774 , V_30 -> V_248 ) )
return false ;
if ( F_56 ( V_53 , V_775 , V_30 -> V_776 ) )
return false ;
if ( V_30 -> V_51 & V_771 &&
F_29 ( V_53 , V_772 ) )
return false ;
}
F_48 ( V_53 , V_244 ) ;
return true ;
}
static bool F_160 ( struct V_31 * V_53 , T_2 V_738 , T_6 * signal ,
int V_777 )
{
void * V_45 ;
int V_159 = 0 ;
if ( ! V_738 )
return true ;
V_45 = F_47 ( V_53 , V_777 ) ;
if ( ! V_45 )
return false ;
for ( V_159 = 0 ; V_159 < V_778 ; V_159 ++ ) {
if ( ! ( V_738 & F_157 ( V_159 ) ) )
continue;
if ( F_56 ( V_53 , V_159 , signal [ V_159 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_161 ( struct V_31 * V_53 , V_22 V_52 , V_22 V_49 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_533 ,
const T_2 * V_640 , struct V_779 * V_780 )
{
void * V_283 ;
struct V_4 * V_781 , * V_782 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_640 ) ||
F_28 ( V_53 , V_293 , V_780 -> V_783 ) )
goto V_61;
V_781 = F_47 ( V_53 , V_784 ) ;
if ( ! V_781 )
goto V_61;
#define F_162 ( V_45 , T_7 , type ) do { \
if (sinfo->filled & BIT(NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
F_162 ( V_785 , V_786 , V_22 ) ;
F_162 ( V_787 , V_788 , V_22 ) ;
if ( V_780 -> V_789 & ( F_157 ( V_790 ) |
F_157 ( V_791 ) ) &&
F_28 ( V_53 , V_790 ,
( V_22 ) V_780 -> V_792 ) )
goto V_61;
if ( V_780 -> V_789 & ( F_157 ( V_793 ) |
F_157 ( V_794 ) ) &&
F_28 ( V_53 , V_793 ,
( V_22 ) V_780 -> V_795 ) )
goto V_61;
F_162 ( V_796 , V_792 , T_1 ) ;
F_162 ( V_797 , V_795 , T_1 ) ;
F_162 ( V_798 , V_799 , T_3 ) ;
F_162 ( V_800 , V_801 , T_3 ) ;
F_162 ( V_802 , V_803 , T_2 ) ;
switch ( V_7 -> V_18 . V_804 ) {
case V_805 :
F_162 ( SIGNAL , signal , T_2 ) ;
F_162 ( V_806 , V_807 , T_2 ) ;
break;
default:
break;
}
if ( V_780 -> V_789 & F_157 ( V_808 ) ) {
if ( ! F_160 ( V_53 , V_780 -> V_809 ,
V_780 -> V_810 ,
V_808 ) )
goto V_61;
}
if ( V_780 -> V_789 & F_157 ( V_811 ) ) {
if ( ! F_160 ( V_53 , V_780 -> V_809 ,
V_780 -> V_812 ,
V_811 ) )
goto V_61;
}
if ( V_780 -> V_789 & F_157 ( V_813 ) ) {
if ( ! F_158 ( V_53 , & V_780 -> V_814 ,
V_813 ) )
goto V_61;
}
if ( V_780 -> V_789 & F_157 ( V_815 ) ) {
if ( ! F_158 ( V_53 , & V_780 -> V_816 ,
V_815 ) )
goto V_61;
}
F_162 ( V_817 , V_818 , V_22 ) ;
F_162 ( V_819 , V_820 , V_22 ) ;
F_162 ( V_821 , V_822 , V_22 ) ;
F_162 ( V_823 , V_824 , V_22 ) ;
F_162 ( V_825 , V_826 , V_22 ) ;
F_162 ( V_827 , V_828 , V_22 ) ;
F_162 ( V_829 , V_830 , V_22 ) ;
F_162 ( V_831 , V_832 , V_22 ) ;
F_162 ( V_833 , V_834 , V_22 ) ;
if ( V_780 -> V_789 & F_157 ( V_835 ) ) {
V_782 = F_47 ( V_53 , V_835 ) ;
if ( ! V_782 )
goto V_61;
if ( ( ( V_780 -> V_782 . V_51 & V_836 ) &&
F_29 ( V_53 , V_837 ) ) ||
( ( V_780 -> V_782 . V_51 & V_838 ) &&
F_29 ( V_53 , V_839 ) ) ||
( ( V_780 -> V_782 . V_51 & V_840 ) &&
F_29 ( V_53 , V_841 ) ) ||
F_56 ( V_53 , V_842 ,
V_780 -> V_782 . V_703 ) ||
F_55 ( V_53 , V_843 ,
V_780 -> V_782 . V_535 ) )
goto V_61;
F_48 ( V_53 , V_782 ) ;
}
if ( ( V_780 -> V_789 & F_157 ( V_844 ) ) &&
F_51 ( V_53 , V_844 ,
sizeof( struct V_735 ) ,
& V_780 -> V_736 ) )
goto V_61;
F_162 ( V_845 , V_846 , T_1 ) ;
F_162 ( V_847 , V_848 , T_1 ) ;
F_162 ( V_849 , V_850 , T_1 ) ;
F_162 ( V_851 , V_852 , T_2 ) ;
#undef F_162
if ( V_780 -> V_789 & F_157 ( V_853 ) ) {
struct V_4 * V_854 ;
int V_855 ;
V_854 = F_47 ( V_53 , V_853 ) ;
if ( ! V_854 )
goto V_61;
for ( V_855 = 0 ; V_855 < V_856 + 1 ; V_855 ++ ) {
struct V_857 * V_858 ;
struct V_4 * V_859 ;
V_858 = & V_780 -> V_860 [ V_855 ] ;
if ( ! V_858 -> V_789 )
continue;
V_859 = F_47 ( V_53 , V_855 + 1 ) ;
if ( ! V_859 )
goto V_61;
#define F_163 ( V_45 , T_7 , type ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_ ## type(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb)) \
goto nla_put_failure; \
} while (0)
F_163 ( V_861 , V_862 , T_1 ) ;
F_163 ( V_863 , V_864 , T_1 ) ;
F_163 ( V_865 , V_866 , T_1 ) ;
F_163 ( V_867 , V_868 , T_1 ) ;
#undef F_163
F_48 ( V_53 , V_859 ) ;
}
F_48 ( V_53 , V_854 ) ;
}
F_48 ( V_53 , V_781 ) ;
if ( V_780 -> V_869 &&
F_51 ( V_53 , V_674 , V_780 -> V_869 ,
V_780 -> V_870 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_164 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_779 V_780 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_640 [ V_581 ] ;
int V_871 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_872;
}
if ( ! V_7 -> V_345 -> V_873 ) {
V_35 = - V_534 ;
goto V_872;
}
while ( 1 ) {
memset ( & V_780 , 0 , sizeof( V_780 ) ) ;
V_35 = F_165 ( V_7 , V_17 -> V_19 , V_871 ,
V_640 , & V_780 ) ;
if ( V_35 == - V_646 )
break;
if ( V_35 )
goto V_872;
if ( F_161 ( V_32 , V_874 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_7 , V_17 -> V_19 , V_640 ,
& V_780 ) < 0 )
goto V_591;
V_871 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_871 ;
V_35 = V_32 -> V_47 ;
V_872:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_166 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_779 V_780 ;
struct V_31 * V_53 ;
T_2 * V_640 = NULL ;
int V_35 ;
memset ( & V_780 , 0 , sizeof( V_780 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_640 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_875 )
return - V_534 ;
V_35 = F_167 ( V_7 , V_533 , V_640 , & V_780 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_161 ( V_53 , V_874 ,
V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_7 , V_533 , V_640 , & V_780 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_168 ( struct V_18 * V_18 ,
struct V_732 * V_137 ,
enum V_876 V_877 )
{
if ( V_137 -> V_878 != - 1 )
return - V_16 ;
if ( V_137 -> V_879 &&
! ( V_137 -> V_739 & F_157 ( V_748 ) ) )
return - V_16 ;
F_113 ( V_733 != 7 ) ;
switch ( V_877 ) {
case V_880 :
case V_881 :
if ( V_137 -> V_737 &
~ ( F_157 ( V_749 ) |
F_157 ( V_747 ) |
F_157 ( V_744 ) ) )
return - V_16 ;
break;
case V_882 :
case V_883 :
if ( ! ( V_137 -> V_739 & F_157 ( V_748 ) ) )
return - V_16 ;
V_137 -> V_737 &= ~ F_157 ( V_748 ) ;
break;
default:
if ( V_137 -> V_884 != V_885 )
return - V_16 ;
if ( V_137 -> V_830 )
return - V_16 ;
if ( V_137 -> V_886 & V_887 )
return - V_16 ;
}
if ( V_877 != V_882 &&
V_877 != V_883 ) {
if ( V_137 -> V_739 & F_157 ( V_748 ) )
return - V_16 ;
V_137 -> V_737 &= ~ F_157 ( V_748 ) ;
}
if ( V_877 != V_882 ) {
if ( V_137 -> V_886 & V_888 )
return - V_16 ;
if ( V_137 -> V_886 & V_889 )
return - V_16 ;
if ( V_137 -> V_890 )
return - V_16 ;
if ( V_137 -> V_891 || V_137 -> V_892 || V_137 -> V_893 )
return - V_16 ;
}
if ( V_877 != V_894 ) {
if ( V_137 -> V_895 )
return - V_16 ;
}
switch ( V_877 ) {
case V_896 :
if ( ! ( V_137 -> V_737 & F_157 ( V_744 ) ) )
return - V_534 ;
break;
case V_894 :
if ( V_137 -> V_737 &
~ ( F_157 ( V_744 ) |
F_157 ( V_749 ) |
F_157 ( V_897 ) |
F_157 ( V_745 ) |
F_157 ( V_746 ) |
F_157 ( V_747 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_291 & V_898 ) &&
V_137 -> V_737 &
( F_157 ( V_749 ) |
F_157 ( V_897 ) ) )
return - V_16 ;
break;
case V_899 :
case V_900 :
if ( V_137 -> V_737 & ~ F_157 ( V_744 ) )
return - V_16 ;
break;
case V_882 :
if ( V_137 -> V_737 & ~ ( F_157 ( V_744 ) |
F_157 ( V_746 ) ) )
return - V_16 ;
if ( V_137 -> V_739 & F_157 ( V_744 ) &&
! V_137 -> V_890 )
return - V_16 ;
break;
case V_883 :
return - V_16 ;
case V_880 :
if ( V_137 -> V_886 & V_887 )
return - V_16 ;
break;
case V_881 :
if ( V_137 -> V_884 != V_885 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_169 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_901 = V_30 -> V_5 [ V_902 ] ;
struct V_25 * V_903 ;
int V_490 ;
if ( ! V_901 )
return NULL ;
V_903 = F_170 ( F_94 ( V_30 ) , F_4 ( V_901 ) ) ;
if ( ! V_903 )
return F_3 ( - V_23 ) ;
if ( ! V_903 -> V_28 || V_903 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_490 = - V_16 ;
goto error;
}
if ( V_903 -> V_28 -> V_141 != V_143 &&
V_903 -> V_28 -> V_141 != V_142 &&
V_903 -> V_28 -> V_141 != V_144 ) {
V_490 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_903 ) ) {
V_490 = - V_548 ;
goto error;
}
return V_903 ;
error:
F_171 ( V_903 ) ;
return F_3 ( V_490 ) ;
}
static int F_172 ( struct V_29 * V_30 ,
struct V_732 * V_137 )
{
struct V_4 * V_95 [ V_904 + 1 ] ;
struct V_4 * V_593 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_905 ] )
return 0 ;
V_593 = V_30 -> V_5 [ V_905 ] ;
V_35 = F_33 ( V_95 , V_904 , V_593 ,
V_906 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_907 ] )
V_137 -> V_908 = F_34 (
V_95 [ V_907 ] ) ;
if ( V_137 -> V_908 & ~ V_909 )
return - V_16 ;
if ( V_95 [ V_910 ] )
V_137 -> V_911 = F_34 ( V_95 [ V_910 ] ) ;
if ( V_137 -> V_911 & ~ V_912 )
return - V_16 ;
V_137 -> V_886 |= V_888 ;
return 0 ;
}
static int F_173 ( struct V_29 * V_30 ,
struct V_732 * V_137 )
{
if ( V_30 -> V_5 [ V_913 ] ) {
V_137 -> V_914 =
F_23 ( V_30 -> V_5 [ V_913 ] ) ;
V_137 -> V_915 =
F_24 ( V_30 -> V_5 [ V_913 ] ) ;
if ( V_137 -> V_915 < 2 )
return - V_16 ;
if ( V_137 -> V_915 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_916 ] ) {
V_137 -> V_917 =
F_23 ( V_30 -> V_5 [ V_916 ] ) ;
V_137 -> V_918 =
F_24 ( V_30 -> V_5 [ V_916 ] ) ;
if ( V_137 -> V_918 < 2 ||
V_137 -> V_918 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_174 ( struct V_29 * V_30 ,
struct V_732 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_919 ] )
V_137 -> V_879 = F_78 ( V_30 -> V_5 [ V_919 ] ) ;
if ( V_30 -> V_5 [ V_920 ] )
V_137 -> V_892 =
F_23 ( V_30 -> V_5 [ V_920 ] ) ;
if ( V_30 -> V_5 [ V_921 ] )
V_137 -> V_893 =
F_23 ( V_30 -> V_5 [ V_921 ] ) ;
V_35 = F_173 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_172 ( V_30 , V_137 ) ;
}
static int F_175 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_732 V_137 ;
T_2 * V_640 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_878 = - 1 ;
if ( ! V_7 -> V_345 -> V_922 )
return - V_534 ;
if ( V_30 -> V_5 [ V_923 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_640 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_30 -> V_5 [ V_924 ] ) {
V_137 . V_890 =
F_23 ( V_30 -> V_5 [ V_924 ] ) ;
V_137 . V_925 =
F_24 ( V_30 -> V_5 [ V_924 ] ) ;
}
if ( V_30 -> V_5 [ V_926 ] ) {
V_137 . V_927 =
F_78 ( V_30 -> V_5 [ V_926 ] ) ;
V_137 . V_886 |= V_889 ;
}
if ( V_30 -> V_5 [ V_928 ] ) {
V_137 . V_891 =
F_23 ( V_30 -> V_5 [ V_928 ] ) ;
V_137 . V_929 =
F_24 ( V_30 -> V_5 [ V_928 ] ) ;
}
if ( V_30 -> V_5 [ V_930 ] )
return - V_16 ;
if ( F_156 ( V_30 , V_533 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_931 ] ) {
V_137 . V_884 =
F_34 ( V_30 -> V_5 [ V_931 ] ) ;
if ( V_137 . V_884 >= V_932 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_933 ] ) {
V_137 . V_803 =
F_34 ( V_30 -> V_5 [ V_933 ] ) ;
if ( V_137 . V_803 >= V_934 )
return - V_16 ;
V_137 . V_886 |= V_887 ;
}
if ( V_30 -> V_5 [ V_935 ] ) {
enum V_936 V_937 = F_4 (
V_30 -> V_5 [ V_935 ] ) ;
if ( V_937 <= V_938 ||
V_937 > V_939 )
return - V_16 ;
V_137 . V_830 = V_937 ;
}
V_35 = F_174 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_895 = F_169 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_895 ) )
return F_18 ( V_137 . V_895 ) ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_534 ;
goto V_940;
}
V_35 = F_176 ( V_7 , V_533 , V_640 , & V_137 ) ;
V_940:
if ( V_137 . V_895 )
F_171 ( V_137 . V_895 ) ;
return V_35 ;
}
static int F_177 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_732 V_137 ;
T_2 * V_640 = NULL ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_345 -> V_371 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_930 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_924 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_923 ] &&
! V_30 -> V_5 [ V_919 ] )
return - V_16 ;
V_640 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_137 . V_890 =
F_23 ( V_30 -> V_5 [ V_924 ] ) ;
V_137 . V_925 =
F_24 ( V_30 -> V_5 [ V_924 ] ) ;
V_137 . V_878 =
F_78 ( V_30 -> V_5 [ V_930 ] ) ;
if ( V_30 -> V_5 [ V_919 ] )
V_137 . V_879 = F_78 ( V_30 -> V_5 [ V_919 ] ) ;
else
V_137 . V_879 = F_78 ( V_30 -> V_5 [ V_923 ] ) ;
if ( ! V_137 . V_879 || V_137 . V_879 > V_941 )
return - V_16 ;
if ( V_30 -> V_5 [ V_926 ] ) {
V_137 . V_927 =
F_78 ( V_30 -> V_5 [ V_926 ] ) ;
V_137 . V_886 |= V_889 ;
}
if ( V_30 -> V_5 [ V_928 ] ) {
V_137 . V_891 =
F_23 ( V_30 -> V_5 [ V_928 ] ) ;
V_137 . V_929 =
F_24 ( V_30 -> V_5 [ V_928 ] ) ;
}
if ( V_30 -> V_5 [ V_920 ] )
V_137 . V_892 =
F_23 ( V_30 -> V_5 [ V_920 ] ) ;
if ( V_30 -> V_5 [ V_921 ] )
V_137 . V_893 =
F_23 ( V_30 -> V_5 [ V_921 ] ) ;
if ( V_30 -> V_5 [ V_942 ] ) {
V_137 . V_943 = true ;
V_137 . V_944 =
F_34 ( V_30 -> V_5 [ V_942 ] ) ;
}
if ( V_30 -> V_5 [ V_931 ] ) {
V_137 . V_884 =
F_34 ( V_30 -> V_5 [ V_931 ] ) ;
if ( V_137 . V_884 >= V_932 )
return - V_16 ;
}
V_35 = F_173 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_172 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_156 ( V_30 , V_533 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( ! ( V_137 . V_739 & F_157 ( V_746 ) ) ) {
V_137 . V_892 = NULL ;
V_137 . V_893 = NULL ;
}
F_113 ( V_733 != 7 ) ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_322 ) ||
! ( V_137 . V_739 & F_157 ( V_746 ) ) )
V_137 . V_886 &= ~ V_888 ;
if ( ( V_137 . V_739 & F_157 ( V_748 ) ) ||
V_30 -> V_5 [ V_919 ] )
return - V_16 ;
V_137 . V_737 &= ~ F_157 ( V_748 ) ;
if ( ! ( V_7 -> V_18 . V_291 &
V_898 ) &&
V_137 . V_737 &
( F_157 ( V_749 ) |
F_157 ( V_897 ) ) )
return - V_16 ;
V_137 . V_895 = F_169 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_895 ) )
return F_18 ( V_137 . V_895 ) ;
break;
case V_145 :
V_137 . V_886 &= ~ V_888 ;
if ( V_137 . V_737 & F_157 ( V_897 ) )
return - V_16 ;
if ( ( V_137 . V_739 & F_157 ( V_748 ) ) ||
V_30 -> V_5 [ V_919 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_886 &= ~ V_888 ;
if ( V_137 . V_737 &
( F_157 ( V_897 ) |
F_157 ( V_749 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_739 & F_157 ( V_748 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_326 ) )
return - V_534 ;
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) )
return - V_534 ;
V_137 . V_737 &= ~ F_157 ( V_744 ) ;
break;
default:
return - V_534 ;
}
V_35 = F_178 ( V_7 , V_533 , V_640 , & V_137 ) ;
if ( V_137 . V_895 )
F_171 ( V_137 . V_895 ) ;
return V_35 ;
}
static int F_179 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_945 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_30 -> V_5 [ V_541 ] )
V_137 . V_946 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_143 &&
V_533 -> V_28 -> V_141 != V_145 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_947 )
return - V_534 ;
if ( V_30 -> V_5 [ V_948 ] ) {
V_137 . V_949 =
F_34 ( V_30 -> V_5 [ V_948 ] ) ;
if ( V_137 . V_949 != V_950 >> 4 &&
V_137 . V_949 != V_951 >> 4 )
return - V_16 ;
} else {
V_137 . V_949 = V_951 >> 4 ;
}
if ( V_30 -> V_5 [ V_952 ] ) {
V_137 . V_953 =
F_78 ( V_30 -> V_5 [ V_952 ] ) ;
if ( V_137 . V_953 == 0 )
return - V_16 ;
} else {
V_137 . V_953 = V_954 ;
}
return F_180 ( V_7 , V_533 , & V_137 ) ;
}
static int F_181 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_533 ,
T_2 * V_955 , T_2 * V_956 ,
struct V_957 * V_958 )
{
void * V_283 ;
struct V_4 * V_959 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_960 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_955 ) ||
F_51 ( V_53 , V_961 , V_581 , V_956 ) ||
F_28 ( V_53 , V_293 , V_958 -> V_783 ) )
goto V_61;
V_959 = F_47 ( V_53 , V_962 ) ;
if ( ! V_959 )
goto V_61;
if ( ( V_958 -> V_789 & V_963 ) &&
F_28 ( V_53 , V_964 ,
V_958 -> V_965 ) )
goto V_61;
if ( ( ( V_958 -> V_789 & V_966 ) &&
F_28 ( V_53 , V_967 , V_958 -> V_968 ) ) ||
( ( V_958 -> V_789 & V_969 ) &&
F_28 ( V_53 , V_970 ,
V_958 -> V_971 ) ) ||
( ( V_958 -> V_789 & V_972 ) &&
F_28 ( V_53 , V_973 ,
V_958 -> V_974 ) ) ||
( ( V_958 -> V_789 & V_975 ) &&
F_56 ( V_53 , V_976 ,
V_958 -> V_51 ) ) ||
( ( V_958 -> V_789 & V_977 ) &&
F_28 ( V_53 , V_978 ,
V_958 -> V_979 ) ) ||
( ( V_958 -> V_789 & V_980 ) &&
F_56 ( V_53 , V_981 ,
V_958 -> V_982 ) ) )
goto V_61;
F_48 ( V_53 , V_959 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_182 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_957 V_958 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_955 [ V_581 ] ;
T_2 V_956 [ V_581 ] ;
int V_983 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_345 -> V_984 ) {
V_35 = - V_534 ;
goto V_872;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_534 ;
goto V_872;
}
while ( 1 ) {
V_35 = F_183 ( V_7 , V_17 -> V_19 , V_983 , V_955 ,
V_956 , & V_958 ) ;
if ( V_35 == - V_646 )
break;
if ( V_35 )
goto V_872;
if ( F_181 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_17 -> V_19 , V_955 , V_956 ,
& V_958 ) < 0 )
goto V_591;
V_983 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_983 ;
V_35 = V_32 -> V_47 ;
V_872:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_184 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_957 V_958 ;
struct V_31 * V_53 ;
T_2 * V_955 = NULL ;
T_2 V_956 [ V_581 ] ;
memset ( & V_958 , 0 , sizeof( V_958 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_955 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_985 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
V_35 = F_185 ( V_7 , V_533 , V_955 , V_956 , & V_958 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_181 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_533 , V_955 , V_956 , & V_958 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_186 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_955 = NULL ;
T_2 * V_956 = NULL ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_961 ] )
return - V_16 ;
V_955 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_956 = F_23 ( V_30 -> V_5 [ V_961 ] ) ;
if ( ! V_7 -> V_345 -> V_986 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
return F_187 ( V_7 , V_533 , V_955 , V_956 ) ;
}
static int F_188 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_955 = NULL ;
T_2 * V_956 = NULL ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_961 ] )
return - V_16 ;
V_955 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_956 = F_23 ( V_30 -> V_5 [ V_961 ] ) ;
if ( ! V_7 -> V_345 -> V_373 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
return F_189 ( V_7 , V_533 , V_955 , V_956 ) ;
}
static int F_190 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_955 = NULL ;
if ( V_30 -> V_5 [ V_541 ] )
V_955 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_987 )
return - V_534 ;
return F_191 ( V_7 , V_533 , V_955 ) ;
}
static int F_192 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_957 V_958 ;
struct V_31 * V_53 ;
T_2 * V_955 = NULL ;
T_2 V_988 [ V_581 ] ;
memset ( & V_958 , 0 , sizeof( V_958 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_955 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_989 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
V_35 = F_193 ( V_7 , V_533 , V_955 , V_988 , & V_958 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_181 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_533 , V_955 , V_988 , & V_958 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_194 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_957 V_958 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_955 [ V_581 ] ;
T_2 V_988 [ V_581 ] ;
int V_983 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_345 -> V_990 ) {
V_35 = - V_534 ;
goto V_872;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_534 ;
goto V_872;
}
while ( 1 ) {
V_35 = F_195 ( V_7 , V_17 -> V_19 , V_983 , V_955 ,
V_988 , & V_958 ) ;
if ( V_35 == - V_646 )
break;
if ( V_35 )
goto V_872;
if ( F_181 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_17 -> V_19 , V_955 , V_988 ,
& V_958 ) < 0 )
goto V_591;
V_983 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_983 ;
V_35 = V_32 -> V_47 ;
V_872:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_196 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_991 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_992 = - 1 ;
V_137 . V_993 = - 1 ;
V_137 . V_994 = - 1 ;
V_137 . V_995 = - 1 ;
V_137 . V_996 = - 1 ;
V_137 . V_719 = - 1 ;
V_137 . V_722 = - 1 ;
if ( V_30 -> V_5 [ V_997 ] )
V_137 . V_992 =
F_34 ( V_30 -> V_5 [ V_997 ] ) ;
if ( V_30 -> V_5 [ V_998 ] )
V_137 . V_993 =
F_34 ( V_30 -> V_5 [ V_998 ] ) ;
if ( V_30 -> V_5 [ V_999 ] )
V_137 . V_994 =
F_34 ( V_30 -> V_5 [ V_999 ] ) ;
if ( V_30 -> V_5 [ V_1000 ] ) {
V_137 . V_1001 =
F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
V_137 . V_1002 =
F_24 ( V_30 -> V_5 [ V_1000 ] ) ;
}
if ( V_30 -> V_5 [ V_1003 ] )
V_137 . V_995 = ! ! F_34 ( V_30 -> V_5 [ V_1003 ] ) ;
if ( V_30 -> V_5 [ V_1004 ] )
V_137 . V_996 =
F_78 ( V_30 -> V_5 [ V_1004 ] ) ;
if ( V_30 -> V_5 [ V_718 ] ) {
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_719 =
F_197 ( V_30 -> V_5 [ V_718 ] ) ;
if ( V_137 . V_719 < 0 )
return - V_16 ;
if ( V_137 . V_719 != 0 &&
! ( V_7 -> V_18 . V_291 & V_720 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_721 ] ) {
T_2 V_24 ;
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_721 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_722 = V_24 ;
if ( V_137 . V_722 &&
! ( V_7 -> V_18 . V_291 & V_723 ) )
return - V_16 ;
}
if ( ! V_7 -> V_345 -> V_377 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_534 ;
F_112 ( V_17 ) ;
V_35 = F_198 ( V_7 , V_533 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_199 ( struct V_4 * V_95 [] ,
struct V_1005 * V_1006 )
{
struct V_1007 * V_1008 = & V_1006 -> V_1008 ;
struct V_1009 * V_1010 = & V_1006 -> V_1010 ;
if ( ! V_95 [ V_1011 ] )
return - V_16 ;
if ( ! V_95 [ V_1012 ] )
return - V_16 ;
if ( ! V_95 [ V_1013 ] )
return - V_16 ;
if ( ! V_95 [ V_1014 ] )
return - V_16 ;
if ( ! V_95 [ V_1015 ] )
return - V_16 ;
V_1006 -> V_51 = F_4 ( V_95 [ V_1011 ] ) ;
V_1008 -> V_1016 =
F_4 ( V_95 [ V_1012 ] ) ;
V_1008 -> V_1017 =
F_4 ( V_95 [ V_1013 ] ) ;
V_1008 -> V_1018 =
F_4 ( V_95 [ V_1014 ] ) ;
V_1010 -> V_1019 =
F_4 ( V_95 [ V_1015 ] ) ;
if ( V_95 [ V_1020 ] )
V_1010 -> V_1021 =
F_4 ( V_95 [ V_1020 ] ) ;
if ( V_95 [ V_1022 ] )
V_1006 -> V_74 =
F_4 ( V_95 [ V_1022 ] ) ;
return 0 ;
}
static int F_200 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
enum V_1023 V_1024 ;
if ( F_201 ( ! F_202 ( V_1025 ) ) )
return - V_1026 ;
if ( V_30 -> V_5 [ V_1027 ] )
V_1024 =
F_4 ( V_30 -> V_5 [ V_1027 ] ) ;
else
V_1024 = V_1028 ;
switch ( V_1024 ) {
case V_1028 :
case V_1029 :
if ( ! V_30 -> V_5 [ V_1030 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1030 ] ) ;
return F_203 ( V_138 , V_1024 ) ;
case V_1031 :
return F_204 () ;
default:
return - V_16 ;
}
}
static int F_205 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_1032 V_1033 ;
int V_35 = 0 ;
void * V_283 ;
struct V_4 * V_959 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_1034 )
return - V_534 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1035 )
memcpy ( & V_1033 , & V_1036 , sizeof( V_1033 ) ) ;
else
V_35 = F_206 ( V_7 , V_533 , & V_1033 ) ;
F_114 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1037 ) ;
if ( ! V_283 )
goto V_591;
V_959 = F_47 ( V_53 , V_1038 ) ;
if ( ! V_959 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_55 ( V_53 , V_1039 ,
V_1033 . V_1040 ) ||
F_55 ( V_53 , V_1041 ,
V_1033 . V_1042 ) ||
F_55 ( V_53 , V_1043 ,
V_1033 . V_1044 ) ||
F_55 ( V_53 , V_1045 ,
V_1033 . V_1046 ) ||
F_56 ( V_53 , V_1047 ,
V_1033 . V_1048 ) ||
F_56 ( V_53 , V_1049 ,
V_1033 . V_1050 ) ||
F_56 ( V_53 , V_1051 ,
V_1033 . V_1052 ) ||
F_56 ( V_53 , V_1053 ,
V_1033 . V_1054 ) ||
F_28 ( V_53 , V_1055 ,
V_1033 . V_1056 ) ||
F_56 ( V_53 , V_1057 ,
V_1033 . V_1058 ) ||
F_28 ( V_53 , V_1059 ,
V_1033 . V_1060 ) ||
F_55 ( V_53 , V_1061 ,
V_1033 . V_1062 ) ||
F_28 ( V_53 , V_1063 ,
V_1033 . V_1064 ) ||
F_55 ( V_53 , V_1065 ,
V_1033 . V_1066 ) ||
F_55 ( V_53 , V_1067 ,
V_1033 . V_1068 ) ||
F_55 ( V_53 , V_1069 ,
V_1033 . V_1070 ) ||
F_56 ( V_53 , V_1071 ,
V_1033 . V_1072 ) ||
F_55 ( V_53 , V_1073 ,
V_1033 . V_1074 ) ||
F_56 ( V_53 , V_1075 ,
V_1033 . V_1076 ) ||
F_56 ( V_53 , V_1077 ,
V_1033 . V_1078 ) ||
F_28 ( V_53 , V_1079 ,
V_1033 . V_1080 ) ||
F_28 ( V_53 , V_1081 ,
V_1033 . V_996 ) ||
F_28 ( V_53 , V_1082 ,
V_1033 . V_1083 ) ||
F_55 ( V_53 , V_1084 ,
V_1033 . V_1085 ) ||
F_55 ( V_53 , V_1086 ,
V_1033 . V_1087 ) ||
F_28 ( V_53 , V_1088 ,
V_1033 . V_1089 ) ||
F_55 ( V_53 , V_1090 ,
V_1033 . V_1091 ) ||
F_28 ( V_53 , V_1092 ,
V_1033 . V_1093 ) )
goto V_61;
F_48 ( V_53 , V_959 ) ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_591:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_207 ( struct V_29 * V_30 ,
struct V_1032 * V_1094 ,
V_22 * V_1095 )
{
struct V_4 * V_95 [ V_1096 + 1 ] ;
V_22 V_738 = 0 ;
#define F_208 ( V_95 , V_1094 , T_8 , T_9 , V_174 , V_738 , V_45 , T_10 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1038 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1096 ,
V_30 -> V_5 [ V_1038 ] ,
V_1097 ) )
return - V_16 ;
F_113 ( V_1096 > 32 ) ;
F_208 ( V_95 , V_1094 , V_1040 , 1 , 255 ,
V_738 , V_1039 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1042 , 1 , 255 ,
V_738 , V_1041 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1044 , 1 , 255 ,
V_738 , V_1043 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1046 , 0 , 255 ,
V_738 , V_1045 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1048 , 0 , 16 ,
V_738 , V_1047 ,
F_34 ) ;
F_208 ( V_95 , V_1094 , V_1050 , 1 , 255 ,
V_738 , V_1049 , F_34 ) ;
F_208 ( V_95 , V_1094 , V_1052 , 1 , 255 ,
V_738 , V_1051 ,
F_34 ) ;
F_208 ( V_95 , V_1094 , V_1054 , 0 , 1 ,
V_738 , V_1053 ,
F_34 ) ;
F_208 ( V_95 , V_1094 , V_1056 ,
1 , 255 , V_738 ,
V_1055 ,
F_4 ) ;
F_208 ( V_95 , V_1094 , V_1058 , 0 , 255 ,
V_738 , V_1057 ,
F_34 ) ;
F_208 ( V_95 , V_1094 , V_1060 , 1 , 65535 ,
V_738 , V_1059 ,
F_4 ) ;
F_208 ( V_95 , V_1094 , V_1062 , 1 , 65535 ,
V_738 , V_1061 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1064 ,
1 , 65535 , V_738 ,
V_1063 ,
F_4 ) ;
F_208 ( V_95 , V_1094 , V_1066 ,
1 , 65535 , V_738 ,
V_1065 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1068 ,
1 , 65535 , V_738 ,
V_1067 ,
F_78 ) ;
F_208 ( V_95 , V_1094 ,
V_1070 ,
1 , 65535 , V_738 ,
V_1069 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1072 , 0 , 4 ,
V_738 , V_1071 ,
F_34 ) ;
F_208 ( V_95 , V_1094 , V_1074 , 1 , 65535 ,
V_738 , V_1073 ,
F_78 ) ;
F_208 ( V_95 , V_1094 ,
V_1076 , 0 , 1 ,
V_738 , V_1075 ,
F_34 ) ;
F_208 ( V_95 , V_1094 , V_1078 , 0 , 1 ,
V_738 , V_1077 ,
F_34 ) ;
F_208 ( V_95 , V_1094 , V_1080 , - 255 , 0 ,
V_738 , V_1079 ,
V_1098 ) ;
F_208 ( V_95 , V_1094 , V_996 , 0 , 16 ,
V_738 , V_1081 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1083 ,
1 , 65535 , V_738 ,
V_1082 ,
F_4 ) ;
F_208 ( V_95 , V_1094 , V_1085 , 1 , 65535 ,
V_738 , V_1084 ,
F_78 ) ;
F_208 ( V_95 , V_1094 ,
V_1087 ,
1 , 65535 , V_738 ,
V_1086 ,
F_78 ) ;
F_208 ( V_95 , V_1094 , V_1089 ,
V_1099 ,
V_939 ,
V_738 , V_1088 ,
F_4 ) ;
F_208 ( V_95 , V_1094 , V_1091 ,
0 , 65535 , V_738 ,
V_1090 , F_78 ) ;
F_208 ( V_95 , V_1094 , V_1093 , 1 , 0xffffffff ,
V_738 , V_1092 ,
F_4 ) ;
if ( V_1095 )
* V_1095 = V_738 ;
return 0 ;
#undef F_208
}
static int F_209 ( struct V_29 * V_30 ,
struct V_1100 * V_1101 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_4 * V_95 [ V_1102 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1103 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1102 ,
V_30 -> V_5 [ V_1103 ] ,
V_1104 ) )
return - V_16 ;
if ( V_95 [ V_1105 ] )
V_1101 -> V_1106 =
( F_34 ( V_95 [ V_1105 ] ) ) ?
V_1107 :
V_1108 ;
if ( V_95 [ V_1109 ] )
V_1101 -> V_1110 =
( F_34 ( V_95 [ V_1109 ] ) ) ?
V_1111 :
V_1112 ;
if ( V_95 [ V_1113 ] )
V_1101 -> V_1114 =
( F_34 ( V_95 [ V_1113 ] ) ) ?
V_1115 :
V_1116 ;
if ( V_95 [ V_1117 ] ) {
struct V_4 * V_1118 =
V_95 [ V_1117 ] ;
if ( ! F_22 ( V_1118 ) )
return - V_16 ;
V_1101 -> V_1119 = F_23 ( V_1118 ) ;
V_1101 -> V_1120 = F_24 ( V_1118 ) ;
}
if ( V_95 [ V_1121 ] &&
! ( V_7 -> V_18 . V_291 & V_1122 ) )
return - V_16 ;
V_1101 -> V_1123 = F_210 ( V_95 [ V_1121 ] ) ;
V_1101 -> V_1124 = F_210 ( V_95 [ V_1125 ] ) ;
V_1101 -> V_1126 = F_210 ( V_95 [ V_1127 ] ) ;
if ( V_1101 -> V_1126 )
V_1101 -> V_1123 = true ;
if ( V_95 [ V_1128 ] ) {
if ( ! V_1101 -> V_1123 )
return - V_16 ;
V_1101 -> V_1129 =
F_34 ( V_95 [ V_1128 ] ) ;
}
return 0 ;
}
static int F_211 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_1032 V_1094 ;
V_22 V_738 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_375 )
return - V_534 ;
V_35 = F_207 ( V_30 , & V_1094 , & V_738 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1035 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_212 ( V_7 , V_533 , V_738 , & V_1094 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_213 ( const struct V_1130 * V_1131 ,
struct V_31 * V_53 )
{
struct V_4 * V_1132 ;
unsigned int V_159 ;
if ( F_60 ( V_53 , V_1030 , V_1131 -> V_1133 ) ||
( V_1131 -> V_1134 &&
F_56 ( V_53 , V_1135 , V_1131 -> V_1134 ) ) )
goto V_61;
V_1132 = F_47 ( V_53 , V_1136 ) ;
if ( ! V_1132 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1131 -> V_1137 ; V_159 ++ ) {
struct V_4 * V_1138 ;
const struct V_1005 * V_1006 ;
const struct V_1007 * V_1008 ;
const struct V_1009 * V_1010 ;
unsigned int V_1018 ;
V_1006 = & V_1131 -> V_1139 [ V_159 ] ;
V_1008 = & V_1006 -> V_1008 ;
V_1010 = & V_1006 -> V_1010 ;
V_1138 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1138 )
goto V_61;
V_1018 = V_1008 -> V_1018 ;
if ( ! V_1018 )
V_1018 = F_214 ( V_1131 ,
V_1006 ) ;
if ( F_28 ( V_53 , V_1011 ,
V_1006 -> V_51 ) ||
F_28 ( V_53 , V_1012 ,
V_1008 -> V_1016 ) ||
F_28 ( V_53 , V_1013 ,
V_1008 -> V_1017 ) ||
F_28 ( V_53 , V_1014 ,
V_1018 ) ||
F_28 ( V_53 , V_1020 ,
V_1010 -> V_1021 ) ||
F_28 ( V_53 , V_1015 ,
V_1010 -> V_1019 ) ||
F_28 ( V_53 , V_1022 ,
V_1006 -> V_74 ) )
goto V_61;
F_48 ( V_53 , V_1138 ) ;
}
F_48 ( V_53 , V_1132 ) ;
return 0 ;
V_61:
return - V_489 ;
}
static int F_215 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1130 * V_1131 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1140 ) ;
if ( ! V_283 )
goto V_1141;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1142 ;
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1142 = V_18 -> V_484 &
V_485 ;
V_1131 = F_216 ( V_18 ) ;
if ( F_59 ( ! V_1131 && V_1142 ) ) {
F_75 ( V_53 ) ;
return - V_16 ;
}
if ( V_1131 &&
F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
}
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1027 ,
V_1029 ) )
goto V_61;
F_219 () ;
if ( ! V_1131 )
V_1131 = F_220 ( V_1025 ) ;
if ( F_213 ( V_1131 , V_53 ) )
goto V_1143;
F_221 () ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1143:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_1141:
F_75 ( V_53 ) ;
return - V_489 ;
}
static int F_222 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 , struct V_18 * V_18 ,
const struct V_1130 * V_1131 )
{
void * V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1140 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_213 ( V_1131 , V_53 ) )
goto V_61;
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1027 ,
V_1029 ) )
goto V_61;
if ( V_18 &&
F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
if ( V_18 && V_18 -> V_484 & V_485 &&
F_29 ( V_53 , V_486 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_224 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1130 * V_1131 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1144 , V_493 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1025 && V_493 == 0 ) {
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_494 ,
V_495 , NULL ,
F_225 ( V_1025 ) ) ;
if ( V_35 < 0 )
goto V_872;
}
V_1144 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1131 = F_216 ( & V_7 -> V_18 ) ;
if ( ! V_1131 )
continue;
if ( ++ V_1144 <= V_493 )
continue;
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_494 ,
V_495 , & V_7 -> V_18 , V_1131 ) ;
if ( V_35 < 0 ) {
V_1144 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1144 ;
V_35 = V_32 -> V_47 ;
V_872:
F_20 () ;
return V_35 ;
}
static int F_226 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1145 + 1 ] ;
struct V_4 * V_1138 ;
char * V_1133 ;
int V_1146 , V_1147 ;
V_22 V_1148 = 0 , V_1149 = 0 , V_1150 ;
enum V_1151 V_1134 = V_1152 ;
struct V_1130 * V_1153 ;
if ( ! V_30 -> V_5 [ V_1030 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1136 ] )
return - V_16 ;
V_1133 = F_23 ( V_30 -> V_5 [ V_1030 ] ) ;
if ( V_30 -> V_5 [ V_1135 ] )
V_1134 = F_34 ( V_30 -> V_5 [ V_1135 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1148 ++ ;
if ( V_1148 > V_1154 )
return - V_16 ;
}
if ( ! F_227 ( V_1133 ) )
return - V_16 ;
V_1150 = sizeof( struct V_1130 ) +
V_1148 * sizeof( struct V_1005 ) ;
V_1153 = F_38 ( V_1150 , V_135 ) ;
if ( ! V_1153 )
return - V_136 ;
V_1153 -> V_1137 = V_1148 ;
V_1153 -> V_1133 [ 0 ] = V_1133 [ 0 ] ;
V_1153 -> V_1133 [ 1 ] = V_1133 [ 1 ] ;
if ( F_228 ( V_1134 ) )
V_1153 -> V_1134 = V_1134 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1147 = F_96 ( V_95 , V_1145 ,
F_23 ( V_1138 ) , F_24 ( V_1138 ) ,
V_1155 ) ;
if ( V_1147 )
goto V_1156;
V_1147 = F_199 ( V_95 , & V_1153 -> V_1139 [ V_1149 ] ) ;
if ( V_1147 )
goto V_1156;
V_1149 ++ ;
if ( V_1149 > V_1154 ) {
V_1147 = - V_16 ;
goto V_1156;
}
}
V_1147 = F_229 ( V_1153 ) ;
V_1153 = NULL ;
V_1156:
F_41 ( V_1153 ) ;
return V_1147 ;
}
static int F_230 ( struct V_4 * V_1157 )
{
struct V_4 * V_1158 , * V_1159 ;
int V_360 = 0 , V_1160 , V_1161 ;
F_39 (attr1, freqs, tmp1) {
V_360 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1158 != V_1159 &&
F_4 ( V_1158 ) == F_4 ( V_1159 ) )
return 0 ;
}
return V_360 ;
}
static int F_231 ( struct V_4 * * V_5 ,
T_2 * V_640 , T_2 * V_1162 )
{
int V_159 ;
if ( ! V_5 [ V_541 ] && ! V_5 [ V_1163 ] ) {
memset ( V_640 , 0 , V_581 ) ;
memset ( V_1162 , 0 , V_581 ) ;
V_640 [ 0 ] = 0x2 ;
V_1162 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_541 ] || ! V_5 [ V_1163 ] )
return - V_16 ;
memcpy ( V_640 , F_23 ( V_5 [ V_541 ] ) , V_581 ) ;
memcpy ( V_1162 , F_23 ( V_5 [ V_1163 ] ) , V_581 ) ;
if ( ! F_232 ( V_1162 ) ||
F_232 ( V_640 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_581 ; V_159 ++ )
V_640 [ V_159 ] &= V_1162 [ V_159 ] ;
return 0 ;
}
static int F_233 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
struct V_1164 * V_1165 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1166 = 0 , V_360 , V_159 ;
T_11 V_1120 ;
if ( ! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_345 -> V_1167 )
return - V_534 ;
if ( V_7 -> V_1168 || V_7 -> V_1169 ) {
V_35 = - V_538 ;
goto V_1170;
}
if ( V_30 -> V_5 [ V_1171 ] ) {
V_360 = F_230 (
V_30 -> V_5 [ V_1171 ] ) ;
if ( ! V_360 ) {
V_35 = - V_16 ;
goto V_1170;
}
} else {
V_360 = F_234 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1172 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1166 ++ ;
if ( V_1166 > V_18 -> V_309 ) {
V_35 = - V_16 ;
goto V_1170;
}
if ( V_30 -> V_5 [ V_674 ] )
V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
else
V_1120 = 0 ;
if ( V_1120 > V_18 -> V_313 ) {
V_35 = - V_16 ;
goto V_1170;
}
V_1165 = F_38 ( sizeof( * V_1165 )
+ sizeof( * V_1165 -> V_1173 ) * V_1166
+ sizeof( * V_1165 -> V_361 ) * V_360
+ V_1120 , V_135 ) ;
if ( ! V_1165 ) {
V_35 = - V_136 ;
goto V_1170;
}
if ( V_1166 )
V_1165 -> V_1173 = ( void * ) & V_1165 -> V_361 [ V_360 ] ;
V_1165 -> V_1166 = V_1166 ;
if ( V_1120 ) {
if ( V_1166 )
V_1165 -> V_1119 = ( void * ) ( V_1165 -> V_1173 + V_1166 ) ;
else
V_1165 -> V_1119 = ( void * ) ( V_1165 -> V_361 + V_360 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1171 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1174;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1165 -> V_361 [ V_159 ] = V_55 ;
V_159 ++ ;
}
} else {
enum V_289 V_290 ;
for ( V_290 = 0 ; V_290 < V_356 ; V_290 ++ ) {
int V_161 ;
if ( ! V_18 -> V_357 [ V_290 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_357 [ V_290 ] -> V_360 ; V_161 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_357 [ V_290 ] -> V_361 [ V_161 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1165 -> V_361 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1174;
}
V_1165 -> V_360 = V_159 ;
V_159 = 0 ;
if ( V_1166 ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_610 ) {
V_35 = - V_16 ;
goto V_1174;
}
V_1165 -> V_1173 [ V_159 ] . V_584 = F_24 ( V_45 ) ;
memcpy ( V_1165 -> V_1173 [ V_159 ] . V_586 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_674 ] ) {
V_1165 -> V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
memcpy ( ( void * ) V_1165 -> V_1119 ,
F_23 ( V_30 -> V_5 [ V_674 ] ) ,
V_1165 -> V_1120 ) ;
}
for ( V_159 = 0 ; V_159 < V_356 ; V_159 ++ )
if ( V_18 -> V_357 [ V_159 ] )
V_1165 -> V_1175 [ V_159 ] =
( 1 << V_18 -> V_357 [ V_159 ] -> V_261 ) - 1 ;
if ( V_30 -> V_5 [ V_1176 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_289 V_290 = F_235 ( V_45 ) ;
if ( V_290 < 0 || V_290 >= V_356 ) {
V_35 = - V_16 ;
goto V_1174;
}
if ( ! V_18 -> V_357 [ V_290 ] )
continue;
V_35 = F_236 ( V_18 -> V_357 [ V_290 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1165 -> V_1175 [ V_290 ] ) ;
if ( V_35 )
goto V_1174;
}
}
if ( V_30 -> V_5 [ V_1177 ] ) {
V_1165 -> V_51 = F_4 (
V_30 -> V_5 [ V_1177 ] ) ;
if ( ( V_1165 -> V_51 & V_1178 ) &&
! ( V_18 -> V_291 & V_1179 ) ) {
V_35 = - V_534 ;
goto V_1174;
}
if ( V_1165 -> V_51 & V_1180 ) {
if ( ! ( V_18 -> V_291 &
V_1181 ) ) {
V_35 = - V_534 ;
goto V_1174;
}
if ( V_17 -> V_149 ) {
V_35 = - V_534 ;
goto V_1174;
}
V_35 = F_231 ( V_30 -> V_5 ,
V_1165 -> V_640 ,
V_1165 -> V_1162 ) ;
if ( V_35 )
goto V_1174;
}
}
V_1165 -> V_1182 =
F_210 ( V_30 -> V_5 [ V_1183 ] ) ;
V_1165 -> V_17 = V_17 ;
V_1165 -> V_18 = & V_7 -> V_18 ;
V_1165 -> V_1184 = V_1185 ;
V_7 -> V_1168 = V_1165 ;
V_35 = F_237 ( V_7 , V_1165 ) ;
if ( ! V_35 ) {
F_238 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_239 ( V_17 -> V_19 ) ;
} else {
V_1174:
V_7 -> V_1168 = NULL ;
F_41 ( V_1165 ) ;
}
V_1170:
return V_35 ;
}
static struct V_1186 *
F_240 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1186 * V_1165 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1166 = 0 , V_1187 = 0 , V_360 , V_159 ;
V_22 V_1188 ;
enum V_289 V_290 ;
T_11 V_1120 ;
struct V_4 * V_95 [ V_1189 + 1 ] ;
T_12 V_1190 = V_1191 ;
if ( ! F_22 ( V_5 [ V_674 ] ) )
return F_3 ( - V_16 ) ;
if ( ! V_5 [ V_1192 ] )
return F_3 ( - V_16 ) ;
V_1188 = F_4 ( V_5 [ V_1192 ] ) ;
if ( V_1188 == 0 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1171 ] ) {
V_360 = F_230 (
V_5 [ V_1171 ] ) ;
if ( ! V_360 )
return F_3 ( - V_16 ) ;
} else {
V_360 = F_234 ( V_18 ) ;
}
if ( V_5 [ V_1172 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1166 ++ ;
if ( V_1166 > V_18 -> V_311 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1193 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1194 ;
V_35 = F_96 ( V_95 , V_1189 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1195 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1196 ] ) {
V_1187 ++ ;
continue;
}
V_1194 = V_95 [ V_1197 ] ;
if ( V_1194 )
V_1190 = V_1098 ( V_1194 ) ;
}
}
if ( ! V_1187 && V_1190 != V_1191 )
V_1187 = 1 ;
if ( V_1187 > V_18 -> V_317 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_674 ] )
V_1120 = F_24 ( V_5 [ V_674 ] ) ;
else
V_1120 = 0 ;
if ( V_1120 > V_18 -> V_315 )
return F_3 ( - V_16 ) ;
V_1165 = F_38 ( sizeof( * V_1165 )
+ sizeof( * V_1165 -> V_1173 ) * V_1166
+ sizeof( * V_1165 -> V_1198 ) * V_1187
+ sizeof( * V_1165 -> V_361 ) * V_360
+ V_1120 , V_135 ) ;
if ( ! V_1165 )
return F_3 ( - V_136 ) ;
if ( V_1166 )
V_1165 -> V_1173 = ( void * ) & V_1165 -> V_361 [ V_360 ] ;
V_1165 -> V_1166 = V_1166 ;
if ( V_1120 ) {
if ( V_1166 )
V_1165 -> V_1119 = ( void * ) ( V_1165 -> V_1173 + V_1166 ) ;
else
V_1165 -> V_1119 = ( void * ) ( V_1165 -> V_361 + V_360 ) ;
}
if ( V_1187 ) {
if ( V_1165 -> V_1119 )
V_1165 -> V_1198 = ( void * ) ( V_1165 -> V_1119 + V_1120 ) ;
else if ( V_1166 )
V_1165 -> V_1198 =
( void * ) ( V_1165 -> V_1173 + V_1166 ) ;
else
V_1165 -> V_1198 =
( void * ) ( V_1165 -> V_361 + V_360 ) ;
}
V_1165 -> V_1187 = V_1187 ;
V_159 = 0 ;
if ( V_5 [ V_1171 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1174;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1165 -> V_361 [ V_159 ] = V_55 ;
V_159 ++ ;
}
} else {
for ( V_290 = 0 ; V_290 < V_356 ; V_290 ++ ) {
int V_161 ;
if ( ! V_18 -> V_357 [ V_290 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_357 [ V_290 ] -> V_360 ; V_161 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_357 [ V_290 ] -> V_361 [ V_161 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1165 -> V_361 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1174;
}
V_1165 -> V_360 = V_159 ;
V_159 = 0 ;
if ( V_1166 ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_610 ) {
V_35 = - V_16 ;
goto V_1174;
}
V_1165 -> V_1173 [ V_159 ] . V_584 = F_24 ( V_45 ) ;
memcpy ( V_1165 -> V_1173 [ V_159 ] . V_586 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1193 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_586 , * V_1194 ;
V_35 = F_96 ( V_95 , V_1189 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1195 ) ;
if ( V_35 )
goto V_1174;
V_586 = V_95 [ V_1196 ] ;
if ( V_586 ) {
if ( F_59 ( V_159 >= V_1187 ) ) {
V_35 = - V_16 ;
goto V_1174;
}
if ( F_24 ( V_586 ) > V_610 ) {
V_35 = - V_16 ;
goto V_1174;
}
memcpy ( V_1165 -> V_1198 [ V_159 ] . V_586 . V_586 ,
F_23 ( V_586 ) , F_24 ( V_586 ) ) ;
V_1165 -> V_1198 [ V_159 ] . V_586 . V_584 =
F_24 ( V_586 ) ;
V_1165 -> V_1198 [ V_159 ] . V_1199 =
V_1190 ;
V_1194 = V_95 [ V_1197 ] ;
if ( V_1194 )
V_1165 -> V_1198 [ V_159 ] . V_1199 =
V_1098 ( V_1194 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1187 )
V_1165 -> V_1198 [ 0 ] . V_1199 = V_1190 ;
V_1165 -> V_1200 = V_1201 ;
for ( V_159 = 0 ; V_159 < V_1187 ; V_159 ++ )
V_1165 -> V_1200 =
T_9 ( V_1165 -> V_1198 [ V_159 ] . V_1199 ,
V_1165 -> V_1200 ) ;
} else {
V_1165 -> V_1200 = V_1191 ;
}
if ( V_1120 ) {
V_1165 -> V_1120 = V_1120 ;
memcpy ( ( void * ) V_1165 -> V_1119 ,
F_23 ( V_5 [ V_674 ] ) ,
V_1165 -> V_1120 ) ;
}
if ( V_5 [ V_1177 ] ) {
V_1165 -> V_51 = F_4 (
V_5 [ V_1177 ] ) ;
if ( ( V_1165 -> V_51 & V_1178 ) &&
! ( V_18 -> V_291 & V_1179 ) ) {
V_35 = - V_534 ;
goto V_1174;
}
if ( V_1165 -> V_51 & V_1180 ) {
V_22 V_1202 = V_1203 ;
if ( ! V_17 )
V_1202 = V_1204 ;
if ( ! ( V_18 -> V_291 & V_1202 ) ) {
V_35 = - V_534 ;
goto V_1174;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_534 ;
goto V_1174;
}
V_35 = F_231 ( V_5 , V_1165 -> V_640 ,
V_1165 -> V_1162 ) ;
if ( V_35 )
goto V_1174;
}
}
if ( V_5 [ V_1205 ] )
V_1165 -> V_1206 =
F_4 ( V_5 [ V_1205 ] ) ;
V_1165 -> V_1188 = V_1188 ;
V_1165 -> V_1184 = V_1185 ;
return V_1165 ;
V_1174:
F_41 ( V_1165 ) ;
return F_3 ( V_35 ) ;
}
static int F_241 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_1186 * V_1207 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_416 ) ||
! V_7 -> V_345 -> V_417 )
return - V_534 ;
if ( V_7 -> V_1207 )
return - V_1026 ;
V_1207 = F_240 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_242 ( V_1207 ) ;
if ( V_35 )
goto V_872;
V_35 = F_243 ( V_7 , V_533 , V_1207 ) ;
if ( V_35 )
goto V_1174;
V_1207 -> V_533 = V_533 ;
V_1207 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_622 ] )
V_1207 -> V_623 = V_30 -> V_498 ;
F_244 ( V_7 -> V_1207 , V_1207 ) ;
F_245 ( V_7 , V_533 ,
V_1208 ) ;
return 0 ;
V_1174:
F_41 ( V_1207 ) ;
V_872:
return V_35 ;
}
static int F_246 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_416 ) ||
! V_7 -> V_345 -> V_1209 )
return - V_534 ;
return F_247 ( V_7 , false ) ;
}
static int F_248 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_513 V_514 ;
enum V_1151 V_1134 ;
unsigned int V_1210 ;
int V_35 ;
V_1134 = F_249 ( V_17 -> V_18 ) ;
if ( V_1134 == V_1152 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
if ( F_250 ( V_533 ) )
return - V_538 ;
if ( V_17 -> V_1211 )
return - V_538 ;
V_35 = F_251 ( V_17 -> V_18 , & V_514 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_252 ( V_17 -> V_18 , & V_514 ) )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_1212 )
return - V_534 ;
V_1210 = F_253 ( & V_7 -> V_18 , & V_514 ) ;
if ( F_59 ( ! V_1210 ) )
V_1210 = V_1213 ;
V_35 = V_7 -> V_345 -> V_1212 ( & V_7 -> V_18 , V_533 , & V_514 ,
V_1210 ) ;
if ( ! V_35 ) {
V_17 -> V_514 = V_514 ;
V_17 -> V_1211 = true ;
V_17 -> V_1214 = V_1185 ;
V_17 -> V_1210 = V_1210 ;
}
return V_35 ;
}
static int F_254 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_1215 V_137 ;
static struct V_4 * V_1216 [ V_1217 + 1 ] ;
int V_35 ;
bool V_1218 = false ;
int V_47 , V_159 ;
V_22 V_1219 ;
if ( ! V_7 -> V_345 -> V_436 ||
! ( V_7 -> V_18 . V_51 & V_435 ) )
return - V_534 ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1218 = true ;
if ( ! V_17 -> V_535 )
return - V_1220 ;
break;
case V_146 :
if ( ! V_17 -> V_584 )
return - V_1220 ;
break;
case V_145 :
if ( ! V_17 -> V_1035 )
return - V_1220 ;
break;
default:
return - V_534 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_516 ] ||
! V_30 -> V_5 [ V_1221 ] )
return - V_16 ;
if ( V_1218 && ! V_30 -> V_5 [ V_1222 ] )
return - V_16 ;
V_1219 = F_4 ( V_30 -> V_5 [ V_1221 ] ) ;
if ( V_1219 > 255 )
return - V_16 ;
V_137 . V_1223 = V_1219 ;
if ( ! V_1218 )
goto V_1224;
V_35 = F_145 ( V_30 -> V_5 , & V_137 . V_1225 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1216 , V_1217 ,
V_30 -> V_5 [ V_1222 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_145 ( V_1216 , & V_137 . V_1226 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1216 [ V_1227 ] )
return - V_16 ;
V_47 = F_24 ( V_1216 [ V_1227 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1228 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_483 &&
( V_137 . V_1228 >
V_7 -> V_18 . V_483 ) )
return - V_16 ;
V_137 . V_1229 =
F_23 ( V_1216 [ V_1227 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1228 ; V_159 ++ ) {
T_3 V_1230 = V_137 . V_1229 [ V_159 ] ;
if ( V_1230 >= V_137 . V_1226 . V_681 )
return - V_16 ;
if ( V_137 . V_1226 . V_680 [ V_1230 ] != V_137 . V_1223 )
return - V_16 ;
}
if ( V_1216 [ V_1231 ] ) {
V_47 = F_24 ( V_1216 [ V_1231 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1232 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_483 &&
( V_137 . V_1228 >
V_7 -> V_18 . V_483 ) )
return - V_16 ;
V_137 . V_1233 =
F_23 ( V_1216 [ V_1231 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1232 ; V_159 ++ ) {
T_3 V_1230 = V_137 . V_1233 [ V_159 ] ;
if ( V_1230 >= V_137 . V_1226 . V_690 )
return - V_16 ;
if ( V_137 . V_1226 . V_689 [ V_1230 ] !=
V_137 . V_1223 )
return - V_16 ;
}
}
V_1224:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_514 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_514 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_251 ( V_17 -> V_18 ,
& V_137 . V_514 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_137 . V_1234 = true ;
if ( V_30 -> V_5 [ V_1235 ] )
V_137 . V_1236 = true ;
F_112 ( V_17 ) ;
V_35 = F_255 ( V_7 , V_533 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_256 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1237 * V_1238 )
{
struct V_1239 * V_349 = & V_1238 -> V_1240 ;
const struct V_1241 * V_1242 ;
void * V_283 ;
struct V_4 * V_1243 ;
F_43 ( V_17 ) ;
V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1244 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_28 ( V_53 , V_293 , V_7 -> V_1245 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
V_1243 = F_47 ( V_53 , V_1246 ) ;
if ( ! V_1243 )
goto V_61;
if ( ( ! F_257 ( V_349 -> V_540 ) &&
F_51 ( V_53 , V_1247 , V_581 , V_349 -> V_540 ) ) )
goto V_61;
F_219 () ;
if ( F_202 ( V_349 -> V_684 ) &&
F_29 ( V_53 , V_1248 ) )
goto V_1249;
V_1242 = F_220 ( V_349 -> V_1242 ) ;
if ( V_1242 ) {
if ( F_104 ( V_53 , V_1250 , V_1242 -> V_1251 ) )
goto V_1249;
if ( V_1242 -> V_47 && F_51 ( V_53 , V_1252 ,
V_1242 -> V_47 , V_1242 -> V_138 ) )
goto V_1249;
}
V_1242 = F_220 ( V_349 -> V_682 ) ;
if ( V_1242 && V_1242 -> V_1253 ) {
if ( F_104 ( V_53 , V_1254 , V_1242 -> V_1251 ) )
goto V_1249;
if ( V_1242 -> V_47 && F_51 ( V_53 , V_1255 ,
V_1242 -> V_47 , V_1242 -> V_138 ) )
goto V_1249;
}
F_221 () ;
if ( V_349 -> V_535 &&
F_55 ( V_53 , V_1256 , V_349 -> V_535 ) )
goto V_61;
if ( F_55 ( V_53 , V_1257 , V_349 -> V_927 ) ||
F_28 ( V_53 , V_1258 , V_349 -> V_1259 -> V_60 ) ||
F_28 ( V_53 , V_1260 , V_349 -> V_1261 ) ||
F_28 ( V_53 , V_1262 ,
F_258 ( V_1185 - V_1238 -> V_1263 ) ) )
goto V_61;
switch ( V_7 -> V_18 . V_804 ) {
case V_805 :
if ( F_28 ( V_53 , V_1264 , V_349 -> signal ) )
goto V_61;
break;
case V_1265 :
if ( F_56 ( V_53 , V_1266 , V_349 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1238 == V_17 -> V_149 &&
F_28 ( V_53 , V_1267 ,
V_1268 ) )
goto V_61;
break;
case V_146 :
if ( V_1238 == V_17 -> V_149 &&
F_28 ( V_53 , V_1267 ,
V_1269 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1243 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_1249:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_259 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1237 * V_1167 ;
struct V_1 * V_17 ;
int V_493 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
F_260 ( & V_7 -> V_1270 ) ;
F_261 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1245 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_493 )
continue;
if ( F_256 ( V_32 , V_34 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_7 , V_17 , V_1167 ) < 0 ) {
V_105 -- ;
break;
}
}
F_262 ( & V_7 -> V_1270 ) ;
F_114 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_263 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_533 ,
bool V_1271 ,
struct V_1272 * V_1273 )
{
void * V_283 ;
struct V_4 * V_1274 ;
if ( ! V_1273 -> V_1259 && ! V_1271 )
return 0 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1275 ) ;
if ( ! V_283 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) )
goto V_61;
V_1274 = F_47 ( V_53 , V_1276 ) ;
if ( ! V_1274 )
goto V_61;
if ( V_1273 -> V_1259 &&
F_28 ( V_53 , V_1277 ,
V_1273 -> V_1259 -> V_60 ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1278 ) &&
F_56 ( V_53 , V_1279 , V_1273 -> V_1280 ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1281 ) &&
F_29 ( V_53 , V_1282 ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1283 ) &&
F_104 ( V_53 , V_1284 ,
V_1273 -> time ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1285 ) &&
F_104 ( V_53 , V_1286 ,
V_1273 -> V_1287 ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1288 ) &&
F_104 ( V_53 , V_1289 ,
V_1273 -> V_1290 ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1291 ) &&
F_104 ( V_53 , V_1292 ,
V_1273 -> V_1293 ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1294 ) &&
F_104 ( V_53 , V_1295 ,
V_1273 -> V_1296 ) )
goto V_61;
if ( ( V_1273 -> V_789 & V_1297 ) &&
F_104 ( V_53 , V_1298 ,
V_1273 -> V_1299 ) )
goto V_61;
F_48 ( V_53 , V_1274 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_264 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1272 V_1273 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1300 = V_34 -> args [ 2 ] ;
int V_349 ;
bool V_1301 ;
V_349 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_349 )
return V_349 ;
V_1301 = V_38 . V_40 [ V_1302 ] ;
if ( ! V_17 -> V_19 ) {
V_349 = - V_16 ;
goto V_872;
}
if ( ! V_7 -> V_345 -> V_1303 ) {
V_349 = - V_534 ;
goto V_872;
}
while ( 1 ) {
V_349 = F_265 ( V_7 , V_17 -> V_19 , V_1300 , & V_1273 ) ;
if ( V_349 == - V_646 )
break;
if ( V_349 )
goto V_872;
if ( V_1273 . V_1259 &&
V_1273 . V_1259 -> V_51 & V_62 ) {
V_1300 ++ ;
continue;
}
if ( F_263 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_17 -> V_19 , V_1301 , & V_1273 ) < 0 )
goto V_591;
V_1300 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_1300 ;
V_349 = V_32 -> V_47 ;
V_872:
F_21 ( V_7 ) ;
return V_349 ;
}
static bool F_266 ( V_22 V_1304 )
{
return ! ( V_1304 & ~ ( V_1305 |
V_1306 ) ) ;
}
static int F_267 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_540 , * V_586 , * V_1119 = NULL , * V_1307 = NULL ;
int V_35 , V_584 , V_1120 = 0 , V_1308 = 0 ;
enum V_692 V_693 ;
struct V_93 V_92 ;
bool V_1309 ;
if ( ! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_711 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_585 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_516 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_643 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1310 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1311 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_159 ;
bool V_1312 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_332 ; V_159 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_333 [ V_159 ] ) {
V_1312 = true ;
break;
}
}
if ( ! V_1312 )
return - V_16 ;
}
if ( ! V_7 -> V_345 -> V_379 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_516 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_586 = F_23 ( V_30 -> V_5 [ V_585 ] ) ;
V_584 = F_24 ( V_30 -> V_5 [ V_585 ] ) ;
if ( V_30 -> V_5 [ V_674 ] ) {
V_1119 = F_23 ( V_30 -> V_5 [ V_674 ] ) ;
V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
}
V_693 = F_4 ( V_30 -> V_5 [ V_711 ] ) ;
if ( ! F_147 ( V_7 , V_693 , V_695 ) )
return - V_16 ;
if ( V_693 == V_697 &&
! V_30 -> V_5 [ V_1313 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1313 ] ) {
if ( V_693 != V_697 )
return - V_16 ;
V_1307 = F_23 ( V_30 -> V_5 [ V_1313 ] ) ;
V_1308 = F_24 ( V_30 -> V_5 [ V_1313 ] ) ;
if ( V_1308 < 4 )
return - V_16 ;
}
V_1309 = ! ! V_30 -> V_5 [ V_1314 ] ;
if ( V_1309 )
return 0 ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_268 ( V_7 , V_533 , V_55 , V_693 , V_540 ,
V_586 , V_584 , V_1119 , V_1120 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1307 , V_1308 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_150 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1315 * V_1316 ,
int V_1317 )
{
memset ( V_1316 , 0 , sizeof( * V_1316 ) ) ;
V_1316 -> V_1318 = V_30 -> V_5 [ V_1319 ] ;
if ( V_30 -> V_5 [ V_337 ] ) {
T_3 V_1320 ;
V_1320 = F_78 (
V_30 -> V_5 [ V_337 ] ) ;
V_1316 -> V_1321 = F_269 ( V_1320 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_336 ) &&
V_1320 != V_1322 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1323 ] )
V_1316 -> V_1324 = true ;
} else
V_1316 -> V_1321 = F_269 ( V_1322 ) ;
if ( V_30 -> V_5 [ V_1325 ] ) {
void * V_138 ;
int V_47 , V_159 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1325 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1325 ] ) ;
V_1316 -> V_1326 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1316 -> V_1326 > V_1317 )
return - V_16 ;
memcpy ( V_1316 -> V_1327 , V_138 , V_47 ) ;
for ( V_159 = 0 ; V_159 < V_1316 -> V_1326 ; V_159 ++ )
if ( ! F_270 (
& V_7 -> V_18 ,
V_1316 -> V_1327 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1328 ] ) {
V_1316 -> V_1329 =
F_4 ( V_30 -> V_5 [ V_1328 ] ) ;
if ( ! F_270 ( & V_7 -> V_18 ,
V_1316 -> V_1329 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1330 ] ) {
V_1316 -> V_1304 =
F_4 ( V_30 -> V_5 [ V_1330 ] ) ;
if ( ! F_266 ( V_1316 -> V_1304 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1331 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1331 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1331 ] ) ;
V_1316 -> V_1332 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1316 -> V_1332 > V_1333 )
return - V_16 ;
memcpy ( V_1316 -> V_1334 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_271 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1335 V_1336 = {} ;
const T_2 * V_540 , * V_586 ;
int V_35 , V_584 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] ||
! V_30 -> V_5 [ V_585 ] ||
! V_30 -> V_5 [ V_516 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_381 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_516 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_586 = F_23 ( V_30 -> V_5 [ V_585 ] ) ;
V_584 = F_24 ( V_30 -> V_5 [ V_585 ] ) ;
if ( V_30 -> V_5 [ V_674 ] ) {
V_1336 . V_1119 = F_23 ( V_30 -> V_5 [ V_674 ] ) ;
V_1336 . V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
}
if ( V_30 -> V_5 [ V_1337 ] ) {
enum V_1338 V_1339 =
F_4 ( V_30 -> V_5 [ V_1337 ] ) ;
if ( V_1339 == V_1340 )
V_1336 . V_1341 = true ;
else if ( V_1339 != V_1342 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1343 ] )
V_1336 . V_1344 = F_23 ( V_30 -> V_5 [ V_1343 ] ) ;
if ( F_210 ( V_30 -> V_5 [ V_1345 ] ) )
V_1336 . V_51 |= V_1346 ;
if ( V_30 -> V_5 [ V_459 ] )
memcpy ( & V_1336 . V_1347 ,
F_23 ( V_30 -> V_5 [ V_459 ] ) ,
sizeof( V_1336 . V_1347 ) ) ;
if ( V_30 -> V_5 [ V_920 ] ) {
if ( ! V_30 -> V_5 [ V_459 ] )
return - V_16 ;
memcpy ( & V_1336 . V_892 ,
F_23 ( V_30 -> V_5 [ V_920 ] ) ,
sizeof( V_1336 . V_892 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1348 ] ) )
V_1336 . V_51 |= V_1349 ;
if ( V_30 -> V_5 [ V_468 ] )
memcpy ( & V_1336 . V_1350 ,
F_23 ( V_30 -> V_5 [ V_468 ] ) ,
sizeof( V_1336 . V_1350 ) ) ;
if ( V_30 -> V_5 [ V_921 ] ) {
if ( ! V_30 -> V_5 [ V_468 ] )
return - V_16 ;
memcpy ( & V_1336 . V_893 ,
F_23 ( V_30 -> V_5 [ V_921 ] ) ,
sizeof( V_1336 . V_893 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1351 ] ) ) {
if ( ! ( V_7 -> V_18 . V_291 &
V_1352 ) ||
! ( V_7 -> V_18 . V_291 & V_1353 ) )
return - V_16 ;
V_1336 . V_51 |= V_1354 ;
}
V_35 = F_150 ( V_7 , V_30 , & V_1336 . V_713 , 1 ) ;
if ( ! V_35 ) {
F_112 ( V_533 -> V_28 ) ;
V_35 = F_272 ( V_7 , V_533 , V_55 , V_540 ,
V_586 , V_584 , & V_1336 ) ;
F_114 ( V_533 -> V_28 ) ;
}
return V_35 ;
}
static int F_273 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
const T_2 * V_1119 = NULL , * V_540 ;
int V_1120 = 0 , V_35 ;
T_3 V_953 ;
bool V_1309 ;
if ( ! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_952 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_383 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_953 = F_78 ( V_30 -> V_5 [ V_952 ] ) ;
if ( V_953 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_674 ] ) {
V_1119 = F_23 ( V_30 -> V_5 [ V_674 ] ) ;
V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
}
V_1309 = ! ! V_30 -> V_5 [ V_1314 ] ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_274 ( V_7 , V_533 , V_540 , V_1119 , V_1120 , V_953 ,
V_1309 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_275 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
const T_2 * V_1119 = NULL , * V_540 ;
int V_1120 = 0 , V_35 ;
T_3 V_953 ;
bool V_1309 ;
if ( ! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_952 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_385 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_953 = F_78 ( V_30 -> V_5 [ V_952 ] ) ;
if ( V_953 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_674 ] ) {
V_1119 = F_23 ( V_30 -> V_5 [ V_674 ] ) ;
V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
}
V_1309 = ! ! V_30 -> V_5 [ V_1314 ] ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_276 ( V_7 , V_533 , V_540 , V_1119 , V_1120 , V_953 ,
V_1309 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static bool
F_277 ( struct V_6 * V_7 ,
int V_1355 [ V_356 ] ,
int V_1356 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_290 , V_159 ;
for ( V_290 = 0 ; V_290 < V_356 ; V_290 ++ ) {
struct V_239 * V_240 ;
V_240 = V_18 -> V_357 [ V_290 ] ;
if ( ! V_240 )
continue;
for ( V_159 = 0 ; V_159 < V_240 -> V_261 ; V_159 ++ ) {
if ( V_240 -> V_262 [ V_159 ] . V_264 == V_1356 ) {
V_1355 [ V_290 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_278 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1357 V_1358 ;
struct V_18 * V_18 ;
struct V_130 * V_1359 = NULL ;
int V_35 ;
memset ( & V_1358 , 0 , sizeof( V_1358 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_585 ] ||
! F_24 ( V_30 -> V_5 [ V_585 ] ) )
return - V_16 ;
V_1358 . V_535 = 100 ;
if ( V_30 -> V_5 [ V_700 ] ) {
V_1358 . V_535 =
F_4 ( V_30 -> V_5 [ V_700 ] ) ;
if ( V_1358 . V_535 < 1 || V_1358 . V_535 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_345 -> V_387 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_146 )
return - V_534 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_541 ] ) {
V_1358 . V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! F_119 ( V_1358 . V_540 ) )
return - V_16 ;
}
V_1358 . V_586 = F_23 ( V_30 -> V_5 [ V_585 ] ) ;
V_1358 . V_584 = F_24 ( V_30 -> V_5 [ V_585 ] ) ;
if ( V_30 -> V_5 [ V_674 ] ) {
V_1358 . V_1119 = F_23 ( V_30 -> V_5 [ V_674 ] ) ;
V_1358 . V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1358 . V_514 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_1358 . V_514 ,
V_146 ) )
return - V_16 ;
switch ( V_1358 . V_514 . V_517 ) {
case V_531 :
case V_532 :
case V_518 :
break;
case V_573 :
case V_574 :
if ( V_7 -> V_18 . V_291 & V_1360 )
break;
default:
return - V_16 ;
}
V_1358 . V_1361 = ! ! V_30 -> V_5 [ V_1362 ] ;
V_1358 . V_709 = ! ! V_30 -> V_5 [ V_710 ] ;
if ( V_30 -> V_5 [ V_1000 ] ) {
T_2 * V_1175 =
F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
int V_1363 =
F_24 ( V_30 -> V_5 [ V_1000 ] ) ;
struct V_239 * V_240 =
V_18 -> V_357 [ V_1358 . V_514 . V_55 -> V_290 ] ;
V_35 = F_236 ( V_240 , V_1175 , V_1363 ,
& V_1358 . V_1001 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_459 ] )
memcpy ( & V_1358 . V_1347 ,
F_23 ( V_30 -> V_5 [ V_459 ] ) ,
sizeof( V_1358 . V_1347 ) ) ;
if ( V_30 -> V_5 [ V_920 ] ) {
if ( ! V_30 -> V_5 [ V_459 ] )
return - V_16 ;
memcpy ( & V_1358 . V_892 ,
F_23 ( V_30 -> V_5 [ V_920 ] ) ,
sizeof( V_1358 . V_892 ) ) ;
}
if ( V_30 -> V_5 [ V_1364 ] &&
! F_277 ( V_7 , V_1358 . V_1355 ,
F_4 ( V_30 -> V_5 [ V_1364 ] ) ) )
return - V_16 ;
if ( V_1358 . V_709 && V_30 -> V_5 [ V_1365 ] ) {
bool V_132 = false ;
V_1359 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1365 ] ,
& V_132 ) ;
if ( F_17 ( V_1359 ) )
return F_18 ( V_1359 ) ;
if ( ( V_1358 . V_514 . V_517 != V_518 ) &&
V_132 ) {
F_41 ( V_1359 ) ;
return - V_16 ;
}
}
V_1358 . V_1318 =
F_210 ( V_30 -> V_5 [ V_1319 ] ) ;
V_1358 . V_1366 =
F_210 ( V_30 -> V_5 [ V_1367 ] ) ;
V_35 = F_279 ( V_7 , V_533 , & V_1358 , V_1359 ) ;
if ( V_35 )
F_280 ( V_1359 ) ;
return V_35 ;
}
static int F_281 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
if ( ! V_7 -> V_345 -> V_1368 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_146 )
return - V_534 ;
return F_282 ( V_7 , V_533 , false ) ;
}
static int F_283 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
int V_1355 [ V_356 ] ;
V_22 V_1369 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_146 &&
V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_427 )
return - V_534 ;
memset ( V_1355 , 0 , sizeof( V_1355 ) ) ;
if ( ! V_30 -> V_5 [ V_1364 ] )
return - V_16 ;
V_1369 = F_4 ( V_30 -> V_5 [ V_1364 ] ) ;
if ( ! F_277 ( V_7 , V_1355 , V_1369 ) )
return - V_16 ;
V_35 = V_7 -> V_345 -> V_427 ( & V_7 -> V_18 , V_533 , V_1355 ) ;
return V_35 ;
}
static struct V_31 *
F_284 ( struct V_6 * V_7 ,
int V_1370 , V_22 V_49 , V_22 V_50 ,
enum V_280 V_52 ,
enum V_753 V_45 ,
const struct V_475 * V_30 ,
T_13 V_1371 )
{
struct V_31 * V_32 ;
void * V_283 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1370 + 100 , V_1371 ) ;
if ( ! V_32 )
return NULL ;
V_283 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_285 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1372 ,
V_30 -> V_1373 ) )
goto V_61;
if ( F_28 ( V_32 , V_1374 ,
V_30 -> V_1375 ) )
goto V_61;
}
V_138 = F_47 ( V_32 , V_45 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_283 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_138 ;
return V_32 ;
V_61:
F_285 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_286 ( struct V_18 * V_18 ,
enum V_280 V_52 ,
enum V_753 V_45 ,
int V_1376 ,
int V_1370 , T_13 V_1371 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_475 * V_30 ;
switch ( V_52 ) {
case V_1377 :
if ( F_59 ( V_1376 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1378 :
if ( F_59 ( V_1376 < 0 ||
V_1376 >= V_18 -> V_479 ) )
return NULL ;
V_30 = & V_18 -> V_481 [ V_1376 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_284 ( V_7 , V_1370 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1371 ) ;
}
void F_287 ( struct V_31 * V_32 , T_13 V_1371 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1379 V_1380 = V_1381 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
if ( V_138 -> F_235 == V_477 )
V_1380 = V_1382 ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1380 , V_1371 ) ;
}
static int F_288 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_345 -> V_429 )
return - V_534 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1383 ] )
return - V_16 ;
V_7 -> V_1384 = V_30 ;
V_35 = F_289 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1383 ] ) ,
F_24 ( V_30 -> V_5 [ V_1383 ] ) ) ;
V_7 -> V_1384 = NULL ;
return V_35 ;
}
static int F_290 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1385 ;
void * V_138 = NULL ;
int V_1386 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1385 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_872;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_872;
}
V_1385 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1383 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1383 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1386 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1385 ) ;
if ( ! V_7 ) {
V_35 = - V_646 ;
goto V_872;
}
if ( ! V_7 -> V_345 -> V_1387 ) {
V_35 = - V_534 ;
goto V_872;
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_1377 ) ;
struct V_4 * V_1388 ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_1385 ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1388 = F_47 ( V_32 , V_1383 ) ;
if ( ! V_1388 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = F_291 ( V_7 , V_32 , V_34 , V_138 , V_1386 ) ;
F_48 ( V_32 , V_1388 ) ;
if ( V_35 == - V_91 || V_35 == - V_646 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_872;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1385 + 1 ;
V_872:
F_20 () ;
return V_35 ;
}
static int F_292 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1389 V_443 ;
struct V_18 * V_18 ;
struct V_130 * V_1359 = NULL ;
int V_35 ;
memset ( & V_443 , 0 , sizeof( V_443 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_585 ] ||
! F_24 ( V_30 -> V_5 [ V_585 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_711 ] ) {
V_443 . V_693 =
F_4 ( V_30 -> V_5 [ V_711 ] ) ;
if ( ! F_147 ( V_7 , V_443 . V_693 ,
V_444 ) )
return - V_16 ;
} else
V_443 . V_693 = V_712 ;
V_443 . V_709 = V_30 -> V_5 [ V_710 ] ;
V_35 = F_150 ( V_7 , V_30 , & V_443 . V_713 ,
V_714 ) ;
if ( V_35 )
return V_35 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_18 = & V_7 -> V_18 ;
V_443 . V_1390 = - 1 ;
if ( V_30 -> V_5 [ V_1391 ] &&
( V_18 -> V_51 & V_324 ) ) {
V_443 . V_1390 =
F_78 ( V_30 -> V_5 [ V_1391 ] ) ;
}
if ( V_30 -> V_5 [ V_541 ] )
V_443 . V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
else if ( V_30 -> V_5 [ V_1392 ] )
V_443 . V_1393 =
F_23 ( V_30 -> V_5 [ V_1392 ] ) ;
V_443 . V_586 = F_23 ( V_30 -> V_5 [ V_585 ] ) ;
V_443 . V_584 = F_24 ( V_30 -> V_5 [ V_585 ] ) ;
if ( V_30 -> V_5 [ V_674 ] ) {
V_443 . V_1119 = F_23 ( V_30 -> V_5 [ V_674 ] ) ;
V_443 . V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
}
if ( V_30 -> V_5 [ V_1337 ] ) {
V_443 . V_1339 = F_4 ( V_30 -> V_5 [ V_1337 ] ) ;
if ( V_443 . V_1339 != V_1340 &&
V_443 . V_1339 != V_1342 )
return - V_16 ;
} else {
V_443 . V_1339 = V_1342 ;
}
if ( V_30 -> V_5 [ V_516 ] ) {
V_443 . V_1259 = F_44 (
V_18 , V_30 -> V_5 [ V_516 ] ) ;
if ( ! V_443 . V_1259 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1394 ] ) {
V_443 . V_1395 = F_44 (
V_18 , V_30 -> V_5 [ V_1394 ] ) ;
if ( ! V_443 . V_1395 )
return - V_16 ;
}
if ( V_443 . V_709 && V_30 -> V_5 [ V_1365 ] ) {
V_1359 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1365 ] , NULL ) ;
if ( F_17 ( V_1359 ) )
return F_18 ( V_1359 ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1345 ] ) )
V_443 . V_51 |= V_1346 ;
if ( V_30 -> V_5 [ V_459 ] )
memcpy ( & V_443 . V_1347 ,
F_23 ( V_30 -> V_5 [ V_459 ] ) ,
sizeof( V_443 . V_1347 ) ) ;
if ( V_30 -> V_5 [ V_920 ] ) {
if ( ! V_30 -> V_5 [ V_459 ] ) {
F_280 ( V_1359 ) ;
return - V_16 ;
}
memcpy ( & V_443 . V_892 ,
F_23 ( V_30 -> V_5 [ V_920 ] ) ,
sizeof( V_443 . V_892 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1348 ] ) )
V_443 . V_51 |= V_1349 ;
if ( V_30 -> V_5 [ V_468 ] )
memcpy ( & V_443 . V_1350 ,
F_23 ( V_30 -> V_5 [ V_468 ] ) ,
sizeof( V_443 . V_1350 ) ) ;
if ( V_30 -> V_5 [ V_921 ] ) {
if ( ! V_30 -> V_5 [ V_468 ] ) {
F_280 ( V_1359 ) ;
return - V_16 ;
}
memcpy ( & V_443 . V_893 ,
F_23 ( V_30 -> V_5 [ V_921 ] ) ,
sizeof( V_443 . V_893 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1351 ] ) ) {
if ( ! ( V_7 -> V_18 . V_291 &
V_1352 ) ||
! ( V_7 -> V_18 . V_291 & V_1353 ) )
return - V_16 ;
V_443 . V_51 |= V_1354 ;
}
F_112 ( V_533 -> V_28 ) ;
V_35 = F_293 ( V_7 , V_533 , & V_443 , V_1359 , NULL ) ;
F_114 ( V_533 -> V_28 ) ;
if ( V_35 )
F_280 ( V_1359 ) ;
return V_35 ;
}
static int F_294 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_3 V_1396 ;
int V_490 ;
if ( ! V_30 -> V_5 [ V_952 ] )
V_1396 = V_1397 ;
else
V_1396 = F_78 ( V_30 -> V_5 [ V_952 ] ) ;
if ( V_1396 == 0 )
return - V_16 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
F_112 ( V_533 -> V_28 ) ;
V_490 = F_295 ( V_7 , V_533 , V_1396 , true ) ;
F_114 ( V_533 -> V_28 ) ;
return V_490 ;
}
static int F_296 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1398 ] ) {
V_22 V_1399 = F_4 ( V_30 -> V_5 [ V_1398 ] ) ;
V_2 = F_297 ( V_1399 ) ;
} else if ( V_30 -> V_5 [ V_1400 ] ) {
V_22 V_1401 = F_4 ( V_30 -> V_5 [ V_1400 ] ) ;
V_2 = F_298 ( V_1401 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_299 ( V_7 , V_2 ) ;
F_300 ( V_2 ) ;
return V_35 ;
}
static int F_301 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int (* F_302)( struct V_18 * V_18 , struct V_25 * V_533 ,
struct V_1402 * V_1403 ) = NULL ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1402 V_1403 ;
memset ( & V_1403 , 0 , sizeof( struct V_1402 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1404 ] )
return - V_16 ;
V_1403 . V_1405 = F_23 ( V_30 -> V_5 [ V_1404 ] ) ;
V_1403 . V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
switch ( V_30 -> V_1406 -> V_52 ) {
case V_1407 :
F_302 = V_7 -> V_345 -> V_391 ;
break;
case V_1408 :
F_302 = V_7 -> V_345 -> V_393 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_302 )
return - V_534 ;
return F_302 ( & V_7 -> V_18 , V_533 , & V_1403 ) ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_395 )
return - V_534 ;
return F_304 ( V_7 , V_533 ) ;
}
static int F_305 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 V_1409 , V_1410 ;
V_22 V_1411 = 0 ;
T_3 V_1412 ;
T_2 * V_1413 ;
bool V_1414 ;
if ( ! ( V_7 -> V_18 . V_51 & V_326 ) ||
! V_7 -> V_345 -> V_412 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1415 ] ||
! V_30 -> V_5 [ V_1416 ] ||
! V_30 -> V_5 [ V_1417 ] ||
! V_30 -> V_5 [ V_674 ] ||
! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_1413 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_1409 = F_34 ( V_30 -> V_5 [ V_1415 ] ) ;
V_1412 = F_78 ( V_30 -> V_5 [ V_1416 ] ) ;
V_1410 = F_34 ( V_30 -> V_5 [ V_1417 ] ) ;
V_1414 = F_210 ( V_30 -> V_5 [ V_1418 ] ) ;
if ( V_30 -> V_5 [ V_1419 ] )
V_1411 =
F_4 ( V_30 -> V_5 [ V_1419 ] ) ;
return F_306 ( V_7 , V_533 , V_1413 , V_1409 ,
V_1410 , V_1412 , V_1411 ,
V_1414 ,
F_23 ( V_30 -> V_5 [ V_674 ] ) ,
F_24 ( V_30 -> V_5 [ V_674 ] ) ) ;
}
static int F_307 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
enum V_1420 V_1421 ;
T_2 * V_1413 ;
if ( ! ( V_7 -> V_18 . V_51 & V_326 ) ||
! V_7 -> V_345 -> V_414 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1422 ] ||
! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_1421 = F_34 ( V_30 -> V_5 [ V_1422 ] ) ;
V_1413 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
return F_308 ( V_7 , V_533 , V_1413 , V_1421 ) ;
}
static int F_309 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
struct V_513 V_514 ;
struct V_31 * V_53 ;
void * V_283 ;
T_1 V_638 ;
V_22 V_1423 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_516 ] ||
! V_30 -> V_5 [ V_1424 ] )
return - V_16 ;
V_1423 = F_4 ( V_30 -> V_5 [ V_1424 ] ) ;
if ( ! V_7 -> V_345 -> V_398 ||
! ( V_7 -> V_18 . V_51 & V_397 ) )
return - V_534 ;
if ( V_1423 < V_1425 ||
V_1423 > V_7 -> V_18 . V_448 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1426 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_648;
}
V_35 = F_310 ( V_7 , V_17 , V_514 . V_55 ,
V_1423 , & V_638 ) ;
if ( V_35 )
goto V_648;
if ( F_104 ( V_53 , V_1427 , V_638 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_648:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_311 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
T_1 V_638 ;
if ( ! V_30 -> V_5 [ V_1427 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_1428 )
return - V_534 ;
V_638 = F_5 ( V_30 -> V_5 [ V_1427 ] ) ;
return F_312 ( V_7 , V_17 , V_638 ) ;
}
static V_22 F_313 ( struct V_239 * V_240 ,
T_2 * V_1175 , T_2 V_1429 )
{
T_2 V_159 ;
V_22 V_738 = 0 ;
for ( V_159 = 0 ; V_159 < V_1429 ; V_159 ++ ) {
int V_244 = ( V_1175 [ V_159 ] & 0x7f ) * 5 ;
int V_1430 ;
for ( V_1430 = 0 ; V_1430 < V_240 -> V_261 ; V_1430 ++ ) {
struct V_243 * V_1431 =
& V_240 -> V_262 [ V_1430 ] ;
if ( V_244 == V_1431 -> V_264 ) {
V_738 |= 1 << V_1430 ;
break;
}
}
if ( V_1430 == V_240 -> V_261 )
return 0 ;
}
return V_738 ;
}
static bool F_314 ( struct V_239 * V_240 ,
T_2 * V_1175 , T_2 V_1429 ,
T_2 V_248 [ V_1432 ] )
{
T_2 V_159 ;
memset ( V_248 , 0 , V_1432 ) ;
for ( V_159 = 0 ; V_159 < V_1429 ; V_159 ++ ) {
int V_1430 , V_1433 ;
V_1430 = V_1175 [ V_159 ] / 8 ;
V_1433 = F_157 ( V_1175 [ V_159 ] % 8 ) ;
if ( ( V_1430 < 0 ) || ( V_1430 >= V_1432 ) )
return false ;
if ( V_240 -> V_245 . V_248 . V_1434 [ V_1430 ] & V_1433 )
V_248 [ V_1430 ] |= V_1433 ;
else
return false ;
}
return true ;
}
static T_3 F_315 ( T_2 V_1435 )
{
T_3 V_1436 = 0 ;
switch ( V_1435 ) {
case V_1437 :
break;
case V_1438 :
V_1436 = 0x00FF ;
break;
case V_1439 :
V_1436 = 0x01FF ;
break;
case V_1440 :
V_1436 = 0x03FF ;
break;
default:
break;
}
return V_1436 ;
}
static void F_316 ( T_3 V_1435 ,
T_3 V_1441 [ V_1442 ] )
{
T_2 V_776 ;
for ( V_776 = 0 ; V_776 < V_1442 ; V_776 ++ ) {
V_1441 [ V_776 ] = F_315 ( V_1435 & 0x03 ) ;
V_1435 >>= 2 ;
}
}
static bool F_317 ( struct V_239 * V_240 ,
struct V_1443 * V_814 ,
T_3 V_248 [ V_1442 ] )
{
T_3 V_1444 = F_318 ( V_240 -> V_255 . V_258 . V_1444 ) ;
T_3 V_1445 [ V_1442 ] = {} ;
T_2 V_159 ;
if ( ! V_240 -> V_255 . V_256 )
return false ;
memset ( V_248 , 0 , sizeof( T_3 ) * V_1442 ) ;
F_316 ( V_1444 , V_1445 ) ;
for ( V_159 = 0 ; V_159 < V_1442 ; V_159 ++ ) {
if ( ( V_1445 [ V_159 ] & V_814 -> V_248 [ V_159 ] ) == V_814 -> V_248 [ V_159 ] )
V_248 [ V_159 ] = V_814 -> V_248 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_319 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1446 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1447 V_738 ;
int V_134 , V_159 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_4 * V_1448 ;
struct V_239 * V_240 ;
T_3 V_1449 ;
if ( ! V_7 -> V_345 -> V_400 )
return - V_534 ;
memset ( & V_738 , 0 , sizeof( V_738 ) ) ;
for ( V_159 = 0 ; V_159 < V_356 ; V_159 ++ ) {
V_240 = V_7 -> V_18 . V_357 [ V_159 ] ;
if ( ! V_240 )
continue;
V_738 . V_1450 [ V_159 ] . V_1451 = ( 1 << V_240 -> V_261 ) - 1 ;
memcpy ( V_738 . V_1450 [ V_159 ] . V_1452 ,
V_240 -> V_245 . V_248 . V_1434 ,
sizeof( V_738 . V_1450 [ V_159 ] . V_1452 ) ) ;
if ( ! V_240 -> V_255 . V_256 )
continue;
V_1449 = F_318 ( V_240 -> V_255 . V_258 . V_1444 ) ;
F_316 ( V_1449 , V_738 . V_1450 [ V_159 ] . V_258 ) ;
}
if ( ! V_30 -> V_5 [ V_1453 ] )
goto V_591;
F_113 ( V_1454 > V_1432 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_289 V_290 = F_235 ( V_1448 ) ;
int V_35 ;
if ( V_290 < 0 || V_290 >= V_356 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_357 [ V_290 ] ;
if ( V_240 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1446 , F_23 ( V_1448 ) ,
F_24 ( V_1448 ) , V_1455 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1456 ] ) {
V_738 . V_1450 [ V_290 ] . V_1451 = F_313 (
V_240 ,
F_23 ( V_95 [ V_1456 ] ) ,
F_24 ( V_95 [ V_1456 ] ) ) ;
if ( ( V_738 . V_1450 [ V_290 ] . V_1451 == 0 ) &&
F_24 ( V_95 [ V_1456 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1457 ] ) {
if ( ! F_314 (
V_240 ,
F_23 ( V_95 [ V_1457 ] ) ,
F_24 ( V_95 [ V_1457 ] ) ,
V_738 . V_1450 [ V_290 ] . V_1452 ) )
return - V_16 ;
}
if ( V_95 [ V_1458 ] ) {
if ( ! F_317 (
V_240 ,
F_23 ( V_95 [ V_1458 ] ) ,
V_738 . V_1450 [ V_290 ] . V_258 ) )
return - V_16 ;
}
if ( V_95 [ V_1459 ] ) {
V_738 . V_1450 [ V_290 ] . V_1460 =
F_34 ( V_95 [ V_1459 ] ) ;
if ( V_738 . V_1450 [ V_290 ] . V_1460 > V_1461 )
return - V_16 ;
}
if ( V_738 . V_1450 [ V_290 ] . V_1451 == 0 ) {
if ( ! ( V_7 -> V_18 . V_357 [ V_290 ] -> V_245 . V_246 ||
V_7 -> V_18 . V_357 [ V_290 ] -> V_255 . V_256 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_1432 ; V_159 ++ )
if ( V_738 . V_1450 [ V_290 ] . V_1452 [ V_159 ] )
goto V_591;
for ( V_159 = 0 ; V_159 < V_1442 ; V_159 ++ )
if ( V_738 . V_1450 [ V_290 ] . V_258 [ V_159 ] )
goto V_591;
return - V_16 ;
}
}
V_591:
return F_320 ( V_7 , V_533 , NULL , & V_738 ) ;
}
static int F_321 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
T_3 V_1462 = V_277 | V_1463 ;
if ( ! V_30 -> V_5 [ V_1464 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_276 ] )
V_1462 = F_78 ( V_30 -> V_5 [ V_276 ] ) ;
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
return - V_534 ;
}
if ( ! V_7 -> V_345 -> V_402 )
return - V_534 ;
return F_322 ( V_17 , V_30 -> V_498 , V_1462 ,
F_23 ( V_30 -> V_5 [ V_1464 ] ) ,
F_24 ( V_30 -> V_5 [ V_1464 ] ) ) ;
}
static int F_323 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
struct V_513 V_514 ;
int V_35 ;
void * V_283 = NULL ;
T_1 V_638 ;
struct V_31 * V_53 = NULL ;
struct V_1465 V_137 = {
. V_1466 =
V_30 -> V_5 [ V_1467 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1468 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_402 )
return - V_534 ;
switch ( V_17 -> V_141 ) {
case V_154 :
if ( ! V_30 -> V_5 [ V_516 ] )
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
return - V_534 ;
}
if ( V_30 -> V_5 [ V_1424 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_449 ) )
return - V_16 ;
V_137 . V_1469 = F_4 ( V_30 -> V_5 [ V_1424 ] ) ;
if ( V_137 . V_1469 < V_1425 ||
V_137 . V_1469 > V_7 -> V_18 . V_448 )
return - V_16 ;
}
V_137 . V_1470 = V_30 -> V_5 [ V_450 ] ;
if ( V_137 . V_1470 && ! ( V_7 -> V_18 . V_51 & V_449 ) )
return - V_16 ;
V_137 . V_1182 = F_210 ( V_30 -> V_5 [ V_1183 ] ) ;
V_514 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_516 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_514 . V_55 && V_137 . V_1470 )
return - V_16 ;
V_137 . V_1471 = F_23 ( V_30 -> V_5 [ V_1468 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1468 ] ) ;
if ( V_30 -> V_5 [ V_1472 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1472 ] ) ;
int V_159 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1473 = V_47 / sizeof( T_3 ) ;
V_137 . V_1474 =
F_23 ( V_30 -> V_5 [ V_1472 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1473 ; V_159 ++ ) {
if ( V_137 . V_1474 [ V_159 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1466 ) {
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1475 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_648;
}
}
V_137 . V_55 = V_514 . V_55 ;
V_35 = F_324 ( V_7 , V_17 , & V_137 , & V_638 ) ;
if ( V_35 )
goto V_648;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1427 , V_638 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_648:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_325 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
T_1 V_638 ;
if ( ! V_30 -> V_5 [ V_1427 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_404 )
return - V_534 ;
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
return - V_534 ;
}
V_638 = F_5 ( V_30 -> V_5 [ V_1427 ] ) ;
return F_326 ( V_7 , V_17 , V_638 ) ;
}
static int F_327 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 V_1476 ;
bool V_282 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1477 ] )
return - V_16 ;
V_1476 = F_4 ( V_30 -> V_5 [ V_1477 ] ) ;
if ( V_1476 != V_1478 && V_1476 != V_1479 )
return - V_16 ;
V_17 = V_533 -> V_28 ;
if ( ! V_7 -> V_345 -> V_1480 )
return - V_534 ;
V_282 = ( V_1476 == V_1479 ) ? true : false ;
if ( V_282 == V_17 -> V_1481 )
return 0 ;
V_35 = F_328 ( V_7 , V_533 , V_282 , V_17 -> V_1482 ) ;
if ( ! V_35 )
V_17 -> V_1481 = V_282 ;
return V_35 ;
}
static int F_329 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
enum V_1483 V_1476 ;
struct V_1 * V_17 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_31 * V_53 ;
void * V_283 ;
int V_35 ;
V_17 = V_533 -> V_28 ;
if ( ! V_7 -> V_345 -> V_1480 )
return - V_534 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1484 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_648;
}
if ( V_17 -> V_1481 )
V_1476 = V_1479 ;
else
V_1476 = V_1478 ;
if ( F_28 ( V_53 , V_1477 , V_1476 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_648:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_330 ( struct V_29 * V_30 ,
V_22 V_244 , V_22 V_1485 , V_22 V_1486 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
if ( V_244 > 100 || V_1486 > V_1487 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_1488 )
return - V_534 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_534 ;
return F_331 ( V_7 , V_533 , V_244 , V_1485 , V_1486 ) ;
}
static int F_332 ( struct V_29 * V_30 ,
T_12 V_1489 , V_22 V_1490 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
if ( V_1489 > 0 )
return - V_16 ;
if ( V_1489 == 0 )
V_1490 = 0 ;
if ( ! V_7 -> V_345 -> V_1491 )
return - V_534 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_534 ;
return F_333 ( V_7 , V_533 , V_1489 , V_1490 ) ;
}
static int F_334 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1492 + 1 ] ;
struct V_4 * V_1493 ;
int V_35 ;
V_1493 = V_30 -> V_5 [ V_1494 ] ;
if ( ! V_1493 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1492 , V_1493 ,
V_1495 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1496 ] &&
V_5 [ V_1497 ] ) {
T_12 V_1489 = V_1098 ( V_5 [ V_1496 ] ) ;
V_22 V_1490 = F_4 ( V_5 [ V_1497 ] ) ;
return F_332 ( V_30 , V_1489 , V_1490 ) ;
}
if ( V_5 [ V_1498 ] &&
V_5 [ V_1499 ] &&
V_5 [ V_1500 ] ) {
V_22 V_244 = F_4 ( V_5 [ V_1498 ] ) ;
V_22 V_1485 = F_4 ( V_5 [ V_1499 ] ) ;
V_22 V_1486 = F_4 ( V_5 [ V_1500 ] ) ;
return F_330 ( V_30 , V_244 , V_1485 , V_1486 ) ;
}
return - V_16 ;
}
static int F_335 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1501 V_1101 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1101 . V_514 ) ;
if ( V_35 )
return V_35 ;
return F_336 ( V_7 , V_533 , & V_1101 ) ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
return F_338 ( V_7 , V_533 ) ;
}
static int F_339 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1032 V_1094 ;
struct V_1100 V_1101 ;
int V_35 ;
memcpy ( & V_1094 , & V_1036 , sizeof( V_1094 ) ) ;
memcpy ( & V_1101 , & V_1502 , sizeof( V_1101 ) ) ;
if ( V_30 -> V_5 [ V_1038 ] ) {
V_35 = F_207 ( V_30 , & V_1094 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_609 ] ||
! F_24 ( V_30 -> V_5 [ V_609 ] ) )
return - V_16 ;
V_1101 . V_1503 = F_23 ( V_30 -> V_5 [ V_609 ] ) ;
V_1101 . V_1035 = F_24 ( V_30 -> V_5 [ V_609 ] ) ;
if ( V_30 -> V_5 [ V_1364 ] &&
! F_277 ( V_7 , V_1101 . V_1355 ,
F_4 ( V_30 -> V_5 [ V_1364 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_700 ] ) {
V_1101 . V_535 =
F_4 ( V_30 -> V_5 [ V_700 ] ) ;
if ( V_1101 . V_535 < 10 ||
V_1101 . V_535 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_701 ] ) {
V_1101 . V_703 =
F_4 ( V_30 -> V_5 [ V_701 ] ) ;
if ( V_1101 . V_703 < 1 || V_1101 . V_703 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1103 ] ) {
V_35 = F_209 ( V_30 , & V_1101 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1101 . V_1123 )
V_1094 . V_1054 = false ;
if ( V_30 -> V_5 [ V_516 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1101 . V_514 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1101 . V_514 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_1000 ] ) {
T_2 * V_1175 = F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
int V_1363 =
F_24 ( V_30 -> V_5 [ V_1000 ] ) ;
struct V_239 * V_240 ;
if ( ! V_1101 . V_514 . V_55 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_357 [ V_1101 . V_514 . V_55 -> V_290 ] ;
V_35 = F_236 ( V_240 , V_1175 , V_1363 ,
& V_1101 . V_1001 ) ;
if ( V_35 )
return V_35 ;
}
return F_340 ( V_7 , V_533 , & V_1101 , & V_1094 ) ;
}
static int F_341 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
return F_342 ( V_7 , V_533 ) ;
}
static int F_343 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1504 * V_189 = V_7 -> V_18 . V_1505 ;
struct V_4 * V_1506 , * V_1507 ;
int V_159 , V_1508 ;
if ( ! V_189 -> V_219 )
return 0 ;
V_1506 = F_47 ( V_53 , V_228 ) ;
if ( ! V_1506 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_189 -> V_219 ; V_159 ++ ) {
V_1507 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1507 )
return - V_91 ;
V_1508 = V_189 -> V_1509 [ V_159 ] . V_1510 ;
if ( F_51 ( V_53 , V_1511 , F_344 ( V_1508 , 8 ) ,
V_189 -> V_1509 [ V_159 ] . V_738 ) ||
F_51 ( V_53 , V_1512 , V_1508 ,
V_189 -> V_1509 [ V_159 ] . V_1513 ) ||
F_28 ( V_53 , V_1514 ,
V_189 -> V_1509 [ V_159 ] . V_1515 ) )
return - V_91 ;
F_48 ( V_53 , V_1507 ) ;
}
F_48 ( V_53 , V_1506 ) ;
return 0 ;
}
static int F_345 ( struct V_31 * V_53 ,
struct V_1516 * V_188 )
{
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_346 ( V_53 , V_1517 , V_188 -> V_1518 ) ||
F_346 ( V_53 , V_1519 , V_188 -> V_955 ) ||
F_51 ( V_53 , V_1520 , V_581 , V_188 -> V_1521 ) ||
F_55 ( V_53 , V_1522 , V_188 -> V_1523 ) ||
F_55 ( V_53 , V_1524 , V_188 -> V_1525 ) ||
F_51 ( V_53 , V_192 ,
V_188 -> V_1526 , V_188 -> V_1527 ) ||
F_28 ( V_53 , V_197 ,
V_188 -> V_1528 ) ||
F_51 ( V_53 , V_199 ,
V_188 -> V_1529 , V_188 -> V_1530 ) ||
F_51 ( V_53 , V_1531 ,
F_344 ( V_188 -> V_1529 , 8 ) , V_188 -> V_1532 ) )
return - V_91 ;
if ( V_188 -> V_1533 . V_47 &&
F_51 ( V_53 , V_194 ,
sizeof( V_188 -> V_1533 ) , & V_188 -> V_1533 ) )
return - V_91 ;
if ( V_188 -> V_1534 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_188 -> V_1534 ) + V_188 -> V_1535 ,
& V_188 -> V_1534 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_347 ( struct V_31 * V_53 ,
struct V_1186 * V_1336 )
{
struct V_4 * V_1536 , * V_1157 , * V_1537 , * V_1538 ;
int V_159 ;
if ( ! V_1336 )
return 0 ;
V_1536 = F_47 ( V_53 , V_230 ) ;
if ( ! V_1536 )
return - V_91 ;
if ( F_28 ( V_53 , V_1192 , V_1336 -> V_1188 ) )
return - V_91 ;
V_1157 = F_47 ( V_53 , V_1171 ) ;
if ( ! V_1157 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1336 -> V_360 ; V_159 ++ )
F_28 ( V_53 , V_159 , V_1336 -> V_361 [ V_159 ] -> V_60 ) ;
F_48 ( V_53 , V_1157 ) ;
if ( V_1336 -> V_1187 ) {
V_1537 = F_47 ( V_53 , V_1193 ) ;
for ( V_159 = 0 ; V_159 < V_1336 -> V_1187 ; V_159 ++ ) {
V_1538 = F_47 ( V_53 , V_159 ) ;
F_51 ( V_53 , V_1196 ,
V_1336 -> V_1198 [ V_159 ] . V_586 . V_584 ,
V_1336 -> V_1198 [ V_159 ] . V_586 . V_586 ) ;
F_48 ( V_53 , V_1538 ) ;
}
F_48 ( V_53 , V_1537 ) ;
}
F_48 ( V_53 , V_1536 ) ;
return 0 ;
}
static int F_348 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1539 = V_592 ;
if ( ! V_7 -> V_18 . V_189 )
return - V_534 ;
if ( V_7 -> V_18 . V_1505 && V_7 -> V_18 . V_1505 -> V_188 ) {
V_1539 += V_7 -> V_18 . V_1505 -> V_188 -> V_1535 +
V_7 -> V_18 . V_1505 -> V_188 -> V_1526 +
V_7 -> V_18 . V_1505 -> V_188 -> V_1529 +
V_7 -> V_18 . V_1505 -> V_188 -> V_1529 / 8 ;
}
V_53 = F_74 ( V_1539 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1540 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_18 . V_1505 ) {
struct V_4 * V_201 ;
V_201 = F_47 ( V_53 , V_1541 ) ;
if ( ! V_201 )
goto V_61;
if ( ( V_7 -> V_18 . V_1505 -> V_1542 &&
F_29 ( V_53 , V_204 ) ) ||
( V_7 -> V_18 . V_1505 -> V_445 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1505 -> V_1543 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1505 -> V_1544 &&
F_29 ( V_53 , V_212 ) ) ||
( V_7 -> V_18 . V_1505 -> V_1545 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1505 -> V_1546 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1505 -> V_1547 &&
F_29 ( V_53 , V_218 ) ) )
goto V_61;
if ( F_343 ( V_53 , V_7 ) )
goto V_61;
if ( F_345 ( V_53 ,
V_7 -> V_18 . V_1505 -> V_188 ) )
goto V_61;
if ( F_347 (
V_53 ,
V_7 -> V_18 . V_1505 -> V_1548 ) )
goto V_61;
F_48 ( V_53 , V_201 ) ;
}
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_349 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1504 * V_1549 )
{
struct V_4 * V_95 [ V_1550 ] ;
struct V_1516 * V_1094 ;
struct V_1551 * V_195 = NULL ;
struct V_1552 * V_50 = NULL ;
V_22 V_1539 ;
V_22 V_1553 , V_1554 , V_1535 = 0 , V_1555 ;
int V_35 , V_1556 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1557 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1558 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1517 ] ||
! V_95 [ V_1519 ] ||
! V_95 [ V_1520 ] ||
! V_95 [ V_1524 ] ||
! V_95 [ V_192 ] ||
! V_95 [ V_197 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_1531 ] )
return - V_16 ;
V_1553 = F_24 ( V_95 [ V_192 ] ) ;
if ( V_1553 > V_7 -> V_18 . V_189 -> V_188 -> V_193 )
return - V_16 ;
if ( F_4 ( V_95 [ V_197 ] ) >
V_7 -> V_18 . V_189 -> V_188 -> V_198 ||
F_4 ( V_95 [ V_197 ] ) == 0 )
return - V_16 ;
V_1554 = F_24 ( V_95 [ V_199 ] ) ;
if ( V_1554 > V_7 -> V_18 . V_189 -> V_188 -> V_200 )
return - V_16 ;
V_1555 = F_24 ( V_95 [ V_1531 ] ) ;
if ( V_1555 != F_344 ( V_1554 , 8 ) )
return - V_16 ;
if ( V_95 [ V_196 ] ) {
V_22 V_1559 = F_24 ( V_95 [ V_196 ] ) ;
V_195 = F_23 ( V_95 [ V_196 ] ) ;
V_1535 = V_1559 - sizeof( * V_195 ) ;
if ( ! V_195 -> V_47 || V_1535 % V_195 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_195 )
return - V_16 ;
if ( V_195 -> V_47 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1560 )
return - V_16 ;
if ( V_195 -> V_47 < V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1561 )
return - V_16 ;
if ( V_1535 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1562 )
return - V_16 ;
if ( V_195 -> V_1230 + V_195 -> V_47 > V_1553 )
return - V_16 ;
}
if ( V_95 [ V_194 ] ) {
V_50 = F_23 ( V_95 [ V_194 ] ) ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1230 > V_1553 )
return - V_16 ;
}
V_1539 = sizeof( * V_1094 ) ;
V_1539 += V_1553 ;
V_1539 += V_1554 + V_1555 ;
V_1539 += V_1535 ;
V_1094 = F_38 ( V_1539 , V_135 ) ;
if ( ! V_1094 )
return - V_136 ;
V_1094 -> V_1518 = F_350 ( V_95 [ V_1517 ] ) ;
V_1094 -> V_955 = F_350 ( V_95 [ V_1519 ] ) ;
memcpy ( V_1094 -> V_1521 , F_23 ( V_95 [ V_1520 ] ) ,
V_581 ) ;
if ( V_95 [ V_1522 ] )
V_1556 = F_78 ( V_95 [ V_1522 ] ) ;
else
V_1556 = 0 ;
#ifdef F_351
V_35 = F_352 ( F_7 ( & V_7 -> V_18 ) , V_1563 , V_1564 ,
V_1565 , & V_1094 -> V_1566 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1094 ) ;
return V_35 ;
}
if ( F_353 ( V_1094 -> V_1566 -> V_44 , V_1556 ) ) {
F_354 ( V_1094 -> V_1566 ) ;
F_41 ( V_1094 ) ;
return - V_1567 ;
}
V_1094 -> V_1523 = F_355 ( V_1094 -> V_1566 -> V_44 ) -> V_1568 ;
#else
if ( ! V_1556 ) {
F_41 ( V_1094 ) ;
return - V_16 ;
}
V_1094 -> V_1523 = V_1556 ;
#endif
V_1094 -> V_1525 = F_78 ( V_95 [ V_1524 ] ) ;
V_1094 -> V_1526 = V_1553 ;
V_1094 -> V_1527 = ( T_2 * ) V_1094 + sizeof( * V_1094 ) + V_1535 ;
memcpy ( ( void * ) V_1094 -> V_1527 ,
F_23 ( V_95 [ V_192 ] ) ,
V_1553 ) ;
if ( V_50 )
V_1094 -> V_1533 = * V_50 ;
V_1094 -> V_1528 = F_4 ( V_95 [ V_197 ] ) ;
V_1094 -> V_1529 = V_1554 ;
V_1094 -> V_1530 = ( T_2 * ) V_1094 + sizeof( * V_1094 ) + V_1535 + V_1553 ;
memcpy ( ( void * ) V_1094 -> V_1530 ,
F_23 ( V_95 [ V_199 ] ) ,
V_1554 ) ;
V_1094 -> V_1532 = ( T_2 * ) V_1094 + sizeof( * V_1094 ) + V_1535 +
V_1553 + V_1554 ;
memcpy ( ( void * ) V_1094 -> V_1532 ,
F_23 ( V_95 [ V_1531 ] ) ,
V_1555 ) ;
if ( V_195 ) {
V_1094 -> V_1535 = V_1535 ;
memcpy ( & V_1094 -> V_1534 , V_195 , sizeof( * V_195 ) + V_1535 ) ;
}
V_1549 -> V_188 = V_1094 ;
return 0 ;
}
static int F_356 ( struct V_6 * V_7 ,
const struct V_1569 * V_189 ,
struct V_4 * V_45 ,
struct V_1504 * V_1549 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_38 ( V_1570 * sizeof( * V_95 ) , V_135 ) ;
if ( ! V_95 )
return - V_136 ;
if ( ! ( V_189 -> V_51 & V_229 ) ) {
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_96 ( V_95 , V_1217 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_591;
V_1549 -> V_1548 = F_240 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_242 ( V_1549 -> V_1548 ) ;
if ( V_35 )
V_1549 -> V_1548 = NULL ;
V_591:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_4 * V_95 [ V_1571 ] ;
struct V_1504 V_1572 = {} ;
struct V_1504 * V_1573 ;
const struct V_1569 * V_189 = V_7 -> V_18 . V_189 ;
int V_35 , V_159 ;
bool V_1574 = V_7 -> V_18 . V_1505 ;
if ( ! V_189 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1541 ] ) {
F_358 ( V_7 ) ;
V_7 -> V_18 . V_1505 = NULL ;
goto V_1575;
}
V_35 = F_96 ( V_95 , V_1576 ,
F_23 ( V_30 -> V_5 [ V_1541 ] ) ,
F_24 ( V_30 -> V_5 [ V_1541 ] ) ,
V_1577 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_204 ] ) {
if ( ! ( V_189 -> V_51 & V_203 ) )
return - V_16 ;
V_1572 . V_1542 = true ;
}
if ( V_95 [ V_206 ] ) {
if ( ! ( V_189 -> V_51 & V_205 ) )
return - V_16 ;
V_1572 . V_445 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_189 -> V_51 & V_207 ) )
return - V_16 ;
V_1572 . V_1543 = true ;
}
if ( V_95 [ V_210 ] )
return - V_16 ;
if ( V_95 [ V_212 ] ) {
if ( ! ( V_189 -> V_51 & V_211 ) )
return - V_16 ;
V_1572 . V_1544 = true ;
}
if ( V_95 [ V_214 ] ) {
if ( ! ( V_189 -> V_51 & V_213 ) )
return - V_16 ;
V_1572 . V_1545 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_189 -> V_51 & V_215 ) )
return - V_16 ;
V_1572 . V_1546 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_189 -> V_51 & V_217 ) )
return - V_16 ;
V_1572 . V_1547 = true ;
}
if ( V_95 [ V_228 ] ) {
struct V_4 * V_221 ;
int V_219 = 0 ;
int V_134 , V_1508 , V_1578 , V_1515 ;
struct V_4 * V_1579 [ V_1580 ] ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_189 -> V_219 )
return - V_16 ;
V_1572 . V_1509 = F_359 ( V_219 ,
sizeof( V_1572 . V_1509 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1572 . V_1509 )
return - V_136 ;
V_1572 . V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1581 ;
F_96 ( V_1579 , V_1582 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1579 [ V_1511 ] ||
! V_1579 [ V_1512 ] )
goto error;
V_1508 = F_24 ( V_1579 [ V_1512 ] ) ;
V_1578 = F_344 ( V_1508 , 8 ) ;
if ( F_24 ( V_1579 [ V_1511 ] ) != V_1578 )
goto error;
if ( V_1508 > V_189 -> V_226 ||
V_1508 < V_189 -> V_224 )
goto error;
if ( ! V_1579 [ V_1514 ] )
V_1515 = 0 ;
else
V_1515 = F_4 (
V_1579 [ V_1514 ] ) ;
if ( V_1515 > V_189 -> V_227 )
goto error;
V_1572 . V_1509 [ V_159 ] . V_1515 = V_1515 ;
V_1581 = F_360 ( V_1578 + V_1508 , V_135 ) ;
if ( ! V_1581 ) {
V_35 = - V_136 ;
goto error;
}
V_1572 . V_1509 [ V_159 ] . V_738 = V_1581 ;
memcpy ( V_1581 , F_23 ( V_1579 [ V_1511 ] ) ,
V_1578 ) ;
V_1581 += V_1578 ;
V_1572 . V_1509 [ V_159 ] . V_1513 = V_1581 ;
V_1572 . V_1509 [ V_159 ] . V_1510 = V_1508 ;
memcpy ( V_1581 ,
F_23 ( V_1579 [ V_1512 ] ) ,
V_1508 ) ;
V_159 ++ ;
}
}
if ( V_95 [ V_191 ] ) {
V_35 = F_349 (
V_7 , V_95 [ V_191 ] ,
& V_1572 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_230 ] ) {
V_35 = F_356 (
V_7 , V_189 , V_95 [ V_230 ] ,
& V_1572 ) ;
if ( V_35 )
goto error;
}
V_1573 = F_361 ( & V_1572 , sizeof( V_1572 ) , V_135 ) ;
if ( ! V_1573 ) {
V_35 = - V_136 ;
goto error;
}
F_358 ( V_7 ) ;
V_7 -> V_18 . V_1505 = V_1573 ;
V_1575:
if ( V_7 -> V_345 -> V_1575 &&
V_1574 != ! ! V_7 -> V_18 . V_1505 )
F_362 ( V_7 , V_7 -> V_18 . V_1505 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1572 . V_219 ; V_159 ++ )
F_41 ( V_1572 . V_1509 [ V_159 ] . V_738 ) ;
F_41 ( V_1572 . V_1509 ) ;
if ( V_1572 . V_188 && V_1572 . V_188 -> V_1566 )
F_354 ( V_1572 . V_188 -> V_1566 ) ;
F_41 ( V_1572 . V_188 ) ;
return V_35 ;
}
static int F_363 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1506 , * V_1507 , * V_1583 , * V_1584 ;
int V_159 , V_161 , V_1508 ;
struct V_1585 * V_233 ;
if ( ! V_7 -> V_234 -> V_236 )
return 0 ;
V_1584 = F_47 ( V_53 , V_238 ) ;
if ( ! V_1584 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_234 -> V_236 ; V_159 ++ ) {
V_1583 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1583 )
return - V_91 ;
V_233 = & V_7 -> V_234 -> V_1586 [ V_159 ] ;
if ( F_28 ( V_53 , V_1587 ,
V_233 -> V_1206 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1588 ,
V_233 -> V_1589 ) )
return - V_91 ;
V_1506 = F_47 ( V_53 ,
V_1590 ) ;
if ( ! V_1506 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ ) {
V_1507 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1507 )
return - V_91 ;
V_1508 = V_233 -> V_1509 [ V_161 ] . V_1510 ;
if ( F_51 ( V_53 , V_1511 ,
F_344 ( V_1508 , 8 ) ,
V_233 -> V_1509 [ V_161 ] . V_738 ) ||
F_51 ( V_53 , V_1512 , V_1508 ,
V_233 -> V_1509 [ V_161 ] . V_1513 ) ||
F_28 ( V_53 , V_1514 ,
V_233 -> V_1509 [ V_161 ] . V_1515 ) )
return - V_91 ;
F_48 ( V_53 , V_1507 ) ;
}
F_48 ( V_53 , V_1506 ) ;
F_48 ( V_53 , V_1583 ) ;
}
F_48 ( V_53 , V_1584 ) ;
return 0 ;
}
static int F_364 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
if ( ! V_7 -> V_18 . V_234 )
return - V_534 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1591 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_234 && F_363 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_365 ( struct V_6 * V_7 )
{
struct V_1592 * V_234 = V_7 -> V_234 ;
int V_159 , V_161 ;
struct V_1585 * V_233 ;
if ( ! V_234 )
return;
for ( V_159 = 0 ; V_159 < V_234 -> V_236 ; V_159 ++ ) {
V_233 = & V_234 -> V_1586 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ )
F_41 ( V_233 -> V_1509 [ V_161 ] . V_738 ) ;
F_41 ( V_233 -> V_1509 ) ;
}
F_41 ( V_234 -> V_1586 ) ;
F_41 ( V_234 ) ;
V_7 -> V_234 = NULL ;
}
static int F_366 ( struct V_6 * V_7 ,
struct V_4 * V_233 ,
struct V_1585 * V_1593 )
{
int V_35 , V_159 ;
const struct V_1594 * V_234 = V_7 -> V_18 . V_234 ;
struct V_4 * V_95 [ V_1595 ] , * V_221 ;
int V_134 , V_1508 , V_1578 , V_1515 , V_219 = 0 ;
struct V_4 * V_1579 [ V_1580 ] ;
V_35 = F_96 ( V_95 , V_1596 , F_23 ( V_233 ) ,
F_24 ( V_233 ) , V_1597 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1587 ] )
V_1593 -> V_1206 =
F_4 ( V_95 [ V_1587 ] ) ;
if ( V_1593 -> V_1206 > V_234 -> V_237 )
return - V_16 ;
if ( V_95 [ V_1588 ] )
V_1593 -> V_1589 =
F_4 ( V_95 [ V_1588 ] ) ;
if ( V_1593 -> V_1589 != V_1598 &&
V_1593 -> V_1589 != V_1599 )
return - V_16 ;
if ( ! V_95 [ V_1590 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_234 -> V_219 )
return - V_16 ;
V_1593 -> V_1509 = F_359 ( V_219 , sizeof( V_1593 -> V_1509 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1593 -> V_1509 )
return - V_136 ;
V_1593 -> V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1581 ;
F_96 ( V_1579 , V_1582 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
if ( ! V_1579 [ V_1511 ] ||
! V_1579 [ V_1512 ] )
return - V_16 ;
V_1508 = F_24 ( V_1579 [ V_1512 ] ) ;
V_1578 = F_344 ( V_1508 , 8 ) ;
if ( F_24 ( V_1579 [ V_1511 ] ) != V_1578 )
return - V_16 ;
if ( V_1508 > V_234 -> V_226 ||
V_1508 < V_234 -> V_224 )
return - V_16 ;
if ( ! V_1579 [ V_1514 ] )
V_1515 = 0 ;
else
V_1515 = F_4 ( V_1579 [ V_1514 ] ) ;
if ( V_1515 > V_234 -> V_227 )
return - V_16 ;
V_1593 -> V_1509 [ V_159 ] . V_1515 = V_1515 ;
V_1581 = F_360 ( V_1578 + V_1508 , V_135 ) ;
if ( ! V_1581 )
return - V_136 ;
V_1593 -> V_1509 [ V_159 ] . V_738 = V_1581 ;
memcpy ( V_1581 , F_23 ( V_1579 [ V_1511 ] ) ,
V_1578 ) ;
V_1581 += V_1578 ;
V_1593 -> V_1509 [ V_159 ] . V_1513 = V_1581 ;
V_1593 -> V_1509 [ V_159 ] . V_1510 = V_1508 ;
memcpy ( V_1581 , F_23 ( V_1579 [ V_1512 ] ) ,
V_1508 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_367 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
const struct V_1594 * V_234 = V_7 -> V_18 . V_234 ;
struct V_1592 V_1600 = {} ;
struct V_1592 * V_1601 ;
int V_35 , V_1602 , V_236 = 0 , V_159 , V_161 ;
struct V_4 * V_233 ;
struct V_1585 * V_1603 ;
if ( ! V_7 -> V_18 . V_234 || ! V_7 -> V_345 -> V_1604 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_238 ] ) {
F_365 ( V_7 ) ;
V_7 -> V_345 -> V_1604 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_236 ++ ;
if ( V_236 > V_234 -> V_236 )
return - V_16 ;
V_1600 . V_1586 = F_359 ( V_236 , sizeof( V_1600 . V_1586 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1600 . V_1586 )
return - V_136 ;
V_1600 . V_236 = V_236 ;
V_159 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_366 ( V_7 , V_233 ,
& V_1600 . V_1586 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = V_7 -> V_345 -> V_1604 ( & V_7 -> V_18 , & V_1600 ) ;
if ( V_35 )
goto error;
V_1601 = F_361 ( & V_1600 , sizeof( V_1600 ) , V_135 ) ;
if ( ! V_1601 ) {
V_35 = - V_136 ;
goto error;
}
F_365 ( V_7 ) ;
V_7 -> V_234 = V_1601 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1600 . V_236 ; V_159 ++ ) {
V_1603 = & V_1600 . V_1586 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1603 -> V_219 ; V_161 ++ )
F_41 ( V_1603 -> V_1509 [ V_161 ] . V_738 ) ;
F_41 ( V_1603 -> V_1509 ) ;
}
F_41 ( V_1600 . V_1586 ) ;
return V_35 ;
}
static int F_368 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_4 * V_95 [ V_1605 ] ;
struct V_1606 V_1607 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1608 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1609 ,
F_23 ( V_30 -> V_5 [ V_1608 ] ) ,
F_24 ( V_30 -> V_5 [ V_1608 ] ) ,
V_1610 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1611 ] ) != V_1612 )
return - V_1613 ;
if ( F_24 ( V_95 [ V_1614 ] ) != V_1615 )
return - V_1613 ;
if ( F_24 ( V_95 [ V_1616 ] ) != V_1617 )
return - V_1613 ;
V_1607 . V_1618 = F_23 ( V_95 [ V_1614 ] ) ;
V_1607 . V_1619 = F_23 ( V_95 [ V_1616 ] ) ;
V_1607 . V_1620 = F_23 ( V_95 [ V_1611 ] ) ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1220 ;
goto V_591;
}
if ( ! V_7 -> V_345 -> V_1621 ) {
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_369 ( V_7 , V_533 , & V_1607 ) ;
V_591:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_370 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1622 )
return - V_538 ;
V_17 -> V_1622 = V_30 -> V_498 ;
return 0 ;
}
static int F_371 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_31 * V_53 ;
void * V_283 ;
const T_2 * V_668 ;
T_1 V_638 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_419 )
return - V_534 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1623 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_648;
}
V_668 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_35 = F_372 ( V_7 , V_533 , V_668 , & V_638 ) ;
if ( V_35 )
goto V_648;
if ( F_104 ( V_53 , V_1427 , V_638 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_648:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_373 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1624 * V_1625 , * V_1626 ;
int V_1627 ;
if ( ! ( V_7 -> V_18 . V_51 & V_423 ) )
return - V_534 ;
V_1626 = F_38 ( sizeof( * V_1626 ) , V_135 ) ;
if ( ! V_1626 )
return - V_136 ;
F_260 ( & V_7 -> V_1628 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1625 -> V_1629 == V_30 -> V_498 ) {
V_1627 = - V_699 ;
goto V_872;
}
}
V_1626 -> V_1629 = V_30 -> V_498 ;
F_374 ( & V_1626 -> V_629 , & V_7 -> V_1630 ) ;
F_262 ( & V_7 -> V_1628 ) ;
return 0 ;
V_872:
F_262 ( & V_7 -> V_1628 ) ;
F_41 ( V_1626 ) ;
return V_1627 ;
}
static int F_375 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_345 -> V_425 )
return - V_534 ;
if ( V_17 -> V_141 != V_154 )
return - V_534 ;
if ( V_17 -> V_1631 )
return 0 ;
if ( F_376 ( V_7 -> V_1632 ) )
return - V_1633 ;
V_35 = F_377 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1631 = true ;
V_7 -> V_1634 ++ ;
return 0 ;
}
static int F_378 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_1635 )
return - V_534 ;
F_379 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_380 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_283 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1636 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_1637 ,
V_1638 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_285 ( V_53 ) ;
return - V_91 ;
}
static int F_381 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1639 V_1640 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
if ( ! V_7 -> V_345 -> V_1641 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1642 ] ||
! F_22 ( V_30 -> V_5 [ V_674 ] ) )
return - V_16 ;
memset ( & V_1640 , 0 , sizeof( V_1640 ) ) ;
V_1640 . V_1643 = F_78 ( V_30 -> V_5 [ V_1642 ] ) ;
V_1640 . V_1119 = F_23 ( V_30 -> V_5 [ V_674 ] ) ;
V_1640 . V_1120 = F_24 ( V_30 -> V_5 [ V_674 ] ) ;
return F_382 ( V_7 , V_533 , & V_1640 ) ;
}
static int F_383 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
enum V_1644 V_1320 = V_1645 ;
T_3 V_1423 ;
int V_490 ;
if ( ! V_7 -> V_345 -> V_431 )
return - V_534 ;
if ( F_59 ( ! V_7 -> V_345 -> V_433 ) )
return - V_16 ;
if ( V_7 -> V_1646 )
return - V_538 ;
if ( V_30 -> V_5 [ V_1647 ] )
V_1320 = F_78 ( V_30 -> V_5 [ V_1647 ] ) ;
if ( V_1320 >= V_1648 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1649 ] )
return - V_16 ;
V_1423 =
F_78 ( V_30 -> V_5 [ V_1649 ] ) ;
if ( V_1423 > V_1650 )
return - V_1613 ;
V_490 = F_384 ( V_7 , V_17 , V_1320 , V_1423 ) ;
if ( ! V_490 )
V_7 -> V_1646 = V_30 -> V_498 ;
return V_490 ;
}
static int F_385 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
if ( ! V_7 -> V_345 -> V_433 )
return - V_534 ;
if ( V_7 -> V_1646 ) {
V_7 -> V_1646 = 0 ;
F_386 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_387 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_159 , V_35 ;
V_22 V_1651 , V_1375 ;
if ( ! V_7 -> V_18 . V_478 )
return - V_534 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1372 ] ||
! V_30 -> V_5 [ V_1374 ] )
return - V_16 ;
V_1651 = F_4 ( V_30 -> V_5 [ V_1372 ] ) ;
V_1375 = F_4 ( V_30 -> V_5 [ V_1374 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_474 ; V_159 ++ ) {
const struct V_1652 * V_1653 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1653 = & V_7 -> V_18 . V_478 [ V_159 ] ;
if ( V_1653 -> V_30 . V_1373 != V_1651 || V_1653 -> V_30 . V_1375 != V_1375 )
continue;
if ( V_1653 -> V_51 & ( V_1654 |
V_1655 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1653 -> V_51 & V_1655 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1653 -> V_51 & V_1656 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_548 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1631 )
return - V_548 ;
}
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_477 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_477 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_477 ] ) ;
}
V_7 -> V_1384 = V_30 ;
V_35 = V_7 -> V_18 . V_478 [ V_159 ] . F_388 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1384 = NULL ;
return V_35 ;
}
return - V_534 ;
}
struct V_31 * F_389 ( struct V_18 * V_18 ,
enum V_280 V_52 ,
enum V_753 V_45 ,
int V_1370 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1384 ) )
return NULL ;
return F_284 ( V_7 , V_1370 ,
V_7 -> V_1384 -> V_498 ,
V_7 -> V_1384 -> V_499 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_390 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1384 ) ) {
F_285 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
return F_76 ( V_32 , V_7 -> V_1384 ) ;
}
static int F_391 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1657 * V_1658 = NULL ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_46 , V_47 , V_1659 , V_1660 , V_1661 ;
int V_490 ;
if ( ! V_7 -> V_345 -> V_438 )
return - V_534 ;
if ( V_30 -> V_5 [ V_1662 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1662 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1662 ] ) ;
if ( V_47 % 2 || V_47 < V_1663 ||
V_47 > V_1664 )
return - V_16 ;
V_1658 = F_38 ( sizeof( struct V_1657 ) , V_135 ) ;
if ( ! V_1658 )
return - V_136 ;
V_1659 = ( V_47 - V_1663 ) >> 1 ;
if ( V_1659 ) {
V_1660 = V_1659 *
sizeof( struct V_1665 ) ;
memcpy ( V_1658 -> V_1666 , V_46 , V_1660 ) ;
V_1658 -> V_1659 = V_1659 ;
for ( V_1661 = 0 ; V_1661 < V_1659 ; V_1661 ++ ) {
if ( V_1658 -> V_1666 [ V_1661 ] . V_1667 > 7 ) {
F_41 ( V_1658 ) ;
return - V_16 ;
}
}
V_46 += V_1660 ;
}
memcpy ( V_1658 -> V_1667 , V_46 , V_1663 ) ;
}
F_112 ( V_533 -> V_28 ) ;
V_490 = F_42 ( V_533 -> V_28 ) ;
if ( ! V_490 )
V_490 = F_392 ( V_7 , V_533 , V_1658 ) ;
F_114 ( V_533 -> V_28 ) ;
F_41 ( V_1658 ) ;
return V_490 ;
}
static int F_393 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
const T_2 * V_1413 ;
T_2 V_1668 , V_1667 ;
T_3 V_1669 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_291 & V_440 ) )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1670 ] || ! V_30 -> V_5 [ V_541 ] ||
! V_30 -> V_5 [ V_1671 ] )
return - V_16 ;
V_1668 = F_34 ( V_30 -> V_5 [ V_1670 ] ) ;
if ( V_1668 >= V_856 )
return - V_16 ;
V_1667 = F_34 ( V_30 -> V_5 [ V_1671 ] ) ;
if ( V_1667 >= V_1672 )
return - V_16 ;
if ( V_1668 >= V_1673 ) {
return - V_16 ;
}
V_1413 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_30 -> V_5 [ V_1674 ] ) {
V_1669 =
F_78 ( V_30 -> V_5 [ V_1674 ] ) ;
if ( ! V_1669 )
return - V_16 ;
}
F_112 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1220 ;
goto V_591;
default:
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_394 ( V_7 , V_533 , V_1668 , V_1413 , V_1667 , V_1669 ) ;
V_591:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_395 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
const T_2 * V_1413 ;
T_2 V_1668 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1670 ] || ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_1668 = F_34 ( V_30 -> V_5 [ V_1670 ] ) ;
V_1413 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
F_112 ( V_17 ) ;
V_35 = F_396 ( V_7 , V_533 , V_1668 , V_1413 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_397 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_513 V_514 = {} ;
const T_2 * V_668 ;
T_2 V_1675 ;
int V_35 ;
if ( ! V_7 -> V_345 -> V_1676 ||
! ( V_7 -> V_18 . V_291 & V_1677 ) )
return - V_534 ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_534 ;
}
if ( ! V_30 -> V_5 [ V_541 ] ||
! V_30 -> V_5 [ V_1678 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
if ( V_514 . V_55 -> V_290 == V_1679 &&
V_514 . V_517 != V_518 &&
V_514 . V_517 != V_573 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_514 , V_17 -> V_141 ) )
return - V_16 ;
if ( F_251 ( V_17 -> V_18 , & V_514 , V_17 -> V_141 ) )
return - V_16 ;
V_668 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_1675 = F_34 ( V_30 -> V_5 [ V_1678 ] ) ;
F_112 ( V_17 ) ;
V_35 = F_398 ( V_7 , V_533 , V_668 , V_1675 , & V_514 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_399 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
const T_2 * V_668 ;
if ( ! V_7 -> V_345 -> V_1676 ||
! V_7 -> V_345 -> V_1680 ||
! ( V_7 -> V_18 . V_291 & V_1677 ) )
return - V_534 ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_534 ;
}
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_668 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
F_112 ( V_17 ) ;
F_400 ( V_7 , V_533 , V_668 ) ;
F_114 ( V_17 ) ;
return 0 ;
}
static int F_401 ( const struct V_1681 * V_345 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_533 ;
bool V_1682 = V_345 -> V_1683 & V_1684 ;
if ( V_1682 )
F_14 () ;
if ( V_345 -> V_1683 & V_1685 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1682 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_497 [ 0 ] = V_7 ;
} else if ( V_345 -> V_1683 & V_1686 ||
V_345 -> V_1683 & V_1687 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1682 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_533 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_345 -> V_1683 & V_1686 ) {
if ( ! V_533 ) {
if ( V_1682 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_497 [ 1 ] = V_533 ;
} else {
V_30 -> V_497 [ 1 ] = V_17 ;
}
if ( V_533 ) {
if ( V_345 -> V_1683 & V_1688 &&
! F_91 ( V_533 ) ) {
if ( V_1682 )
F_20 () ;
return - V_548 ;
}
F_239 ( V_533 ) ;
} else if ( V_345 -> V_1683 & V_1688 ) {
if ( ! V_17 -> V_1631 ) {
if ( V_1682 )
F_20 () ;
return - V_548 ;
}
}
V_30 -> V_497 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_402 ( const struct V_1681 * V_345 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_497 [ 1 ] ) {
if ( V_345 -> V_1683 & V_1687 ) {
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
if ( V_17 -> V_19 )
F_171 ( V_17 -> V_19 ) ;
} else {
F_171 ( V_30 -> V_497 [ 1 ] ) ;
}
}
if ( V_345 -> V_1683 & V_1684 )
F_20 () ;
if ( V_345 -> V_1683 & V_1689 ) {
struct V_1690 * V_36 = F_403 ( V_32 ) ;
memset ( F_404 ( V_36 ) , 0 , F_405 ( V_36 ) ) ;
}
}
void F_406 ( struct V_6 * V_7 ,
enum V_280 V_52 )
{
struct V_31 * V_53 ;
struct V_281 V_282 = {} ;
F_59 ( V_52 != V_295 &&
V_52 != V_1691 ) ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_631 , V_135 ) ;
}
static int F_407 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1164 * V_1336 = V_7 -> V_1168 ;
struct V_4 * V_1692 ;
int V_159 ;
if ( F_59 ( ! V_1336 ) )
return 0 ;
V_1692 = F_47 ( V_53 , V_1172 ) ;
if ( ! V_1692 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1336 -> V_1166 ; V_159 ++ ) {
if ( F_51 ( V_53 , V_159 , V_1336 -> V_1173 [ V_159 ] . V_584 , V_1336 -> V_1173 [ V_159 ] . V_586 ) )
goto V_61;
}
F_48 ( V_53 , V_1692 ) ;
V_1692 = F_47 ( V_53 , V_1171 ) ;
if ( ! V_1692 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1336 -> V_360 ; V_159 ++ ) {
if ( F_28 ( V_53 , V_159 , V_1336 -> V_361 [ V_159 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1692 ) ;
if ( V_1336 -> V_1119 &&
F_51 ( V_53 , V_674 , V_1336 -> V_1120 , V_1336 -> V_1119 ) )
goto V_61;
if ( V_1336 -> V_51 &&
F_28 ( V_53 , V_1177 , V_1336 -> V_51 ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_408 ( struct V_31 * V_53 ,
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
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_407 ( V_53 , V_7 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int
F_409 ( struct V_31 * V_53 ,
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
return - V_489 ;
}
void F_238 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_408 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1693 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1694 , V_135 ) ;
}
struct V_31 * F_410 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1695 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_408 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1695 ? V_1696 :
V_1244 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_411 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1694 , V_135 ) ;
}
void F_412 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_409 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1697 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1694 , V_135 ) ;
}
void F_245 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_409 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1694 , V_135 ) ;
}
static bool F_413 ( struct V_31 * V_53 ,
struct V_1698 * V_1165 )
{
if ( F_56 ( V_53 , V_1699 , V_1165 -> V_1414 ) )
goto V_61;
if ( V_1165 -> V_1133 [ 0 ] == '0' && V_1165 -> V_1133 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1700 ,
V_1701 ) )
goto V_61;
} else if ( V_1165 -> V_1133 [ 0 ] == '9' && V_1165 -> V_1133 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1700 ,
V_1702 ) )
goto V_61;
} else if ( ( V_1165 -> V_1133 [ 0 ] == '9' && V_1165 -> V_1133 [ 1 ] == '8' ) ||
V_1165 -> V_1703 ) {
if ( F_56 ( V_53 , V_1700 ,
V_1704 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1700 ,
V_1705 ) ||
F_60 ( V_53 , V_1030 ,
V_1165 -> V_1133 ) )
goto V_61;
}
if ( V_1165 -> V_14 != V_1706 ) {
struct V_18 * V_18 = F_19 ( V_1165 -> V_14 ) ;
if ( V_18 &&
F_28 ( V_53 , V_26 , V_1165 -> V_14 ) )
goto V_61;
if ( V_18 &&
V_18 -> V_484 & V_485 &&
F_29 ( V_53 , V_486 ) )
goto V_61;
}
return true ;
V_61:
return false ;
}
void F_414 ( enum V_280 V_1707 ,
struct V_1698 * V_1165 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1707 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_413 ( V_53 , V_1165 ) == false )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_415 ( & V_38 , V_53 , 0 ,
V_1708 , V_1709 ) ;
F_221 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_416 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1471 , T_11 V_47 ,
enum V_280 V_52 , T_13 V_1371 ,
int V_908 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1468 , V_47 , V_1471 ) )
goto V_61;
if ( V_908 >= 0 ) {
struct V_4 * V_1710 =
F_47 ( V_53 , V_905 ) ;
if ( ! V_1710 )
goto V_61;
if ( F_56 ( V_53 , V_907 ,
V_908 ) )
goto V_61;
F_48 ( V_53 , V_1710 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_417 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1471 ,
T_11 V_47 , T_13 V_1371 )
{
F_416 ( V_7 , V_19 , V_1471 , V_47 ,
V_695 , V_1371 , - 1 ) ;
}
void F_418 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1471 ,
T_11 V_47 , T_13 V_1371 , int V_908 )
{
F_416 ( V_7 , V_19 , V_1471 , V_47 ,
V_1712 , V_1371 , V_908 ) ;
}
void F_419 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1471 ,
T_11 V_47 , T_13 V_1371 )
{
F_416 ( V_7 , V_19 , V_1471 , V_47 ,
V_1713 , V_1371 , - 1 ) ;
}
void F_420 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1471 ,
T_11 V_47 , T_13 V_1371 )
{
F_416 ( V_7 , V_19 , V_1471 , V_47 ,
V_1714 , V_1371 , - 1 ) ;
}
void F_421 ( struct V_25 * V_533 , const T_2 * V_1471 ,
T_11 V_47 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1715 * V_1716 = ( void * ) V_1471 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_422 ( V_1716 -> V_1717 ) )
V_52 = V_1718 ;
else
V_52 = V_1719 ;
F_423 ( V_533 , V_1471 , V_47 ) ;
F_416 ( V_7 , V_533 , V_1471 , V_47 , V_52 , V_1709 , - 1 ) ;
}
static void F_424 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_668 , T_13 V_1371 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1720 ) ||
F_51 ( V_53 , V_541 , V_581 , V_668 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_425 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_668 ,
T_13 V_1371 )
{
F_424 ( V_7 , V_19 , V_695 ,
V_668 , V_1371 ) ;
}
void F_426 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_668 ,
T_13 V_1371 )
{
F_424 ( V_7 , V_19 , V_1712 ,
V_668 , V_1371 ) ;
}
void F_427 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
const T_2 * V_1721 , T_11 V_1722 ,
const T_2 * V_1723 , T_11 V_1724 ,
T_3 V_632 , T_13 V_1371 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_444 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_540 && F_51 ( V_53 , V_541 , V_581 , V_540 ) ) ||
F_55 ( V_53 , V_1416 , V_632 ) ||
( V_1721 &&
F_51 ( V_53 , V_1725 , V_1722 , V_1721 ) ) ||
( V_1723 &&
F_51 ( V_53 , V_1726 , V_1724 , V_1723 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_428 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
const T_2 * V_1721 , T_11 V_1722 ,
const T_2 * V_1723 , T_11 V_1724 , T_13 V_1371 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1727 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_540 ) ||
( V_1721 &&
F_51 ( V_53 , V_1725 , V_1722 , V_1721 ) ) ||
( V_1723 &&
F_51 ( V_53 , V_1726 , V_1724 , V_1723 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_429 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1396 ,
const T_2 * V_1119 , T_11 V_1120 , bool V_1728 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_446 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1728 && V_1396 &&
F_55 ( V_53 , V_952 , V_1396 ) ) ||
( V_1728 &&
F_29 ( V_53 , V_1729 ) ) ||
( V_1119 && F_51 ( V_53 , V_674 , V_1120 , V_1119 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_430 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
T_13 V_1371 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1730 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_540 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_431 ( struct V_25 * V_533 , const T_2 * V_668 ,
const T_2 * V_1119 , T_2 V_1120 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_432 ( V_533 , V_668 ) ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1731 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_668 ) ||
( V_1120 && V_1119 &&
F_51 ( V_53 , V_674 , V_1120 , V_1119 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_433 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_668 ,
enum V_1732 V_1733 , int V_1734 ,
const T_2 * V_1735 , T_13 V_1371 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1736 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_668 && F_51 ( V_53 , V_541 , V_581 , V_668 ) ) ||
F_28 ( V_53 , V_127 , V_1733 ) ||
( V_1734 != - 1 &&
F_56 ( V_53 , V_123 , V_1734 ) ) ||
( V_1735 && F_51 ( V_53 , V_122 , 6 , V_1735 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_434 ( struct V_18 * V_18 ,
struct V_54 * V_1737 ,
struct V_54 * V_1738 )
{
struct V_31 * V_53 ;
void * V_283 ;
struct V_4 * V_287 ;
V_53 = F_74 ( V_592 , V_1709 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1739 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
V_287 = F_47 ( V_53 , V_1740 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1737 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
V_287 = F_47 ( V_53 , V_1741 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1738 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_415 ( & V_38 , V_53 , 0 ,
V_1708 , V_1709 ) ;
F_221 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_435 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_638 ,
struct V_54 * V_55 ,
unsigned int V_1423 , T_13 V_1371 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
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
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_516 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_521 ,
V_524 ) ||
F_104 ( V_53 , V_1427 , V_638 ) )
goto V_61;
if ( V_52 == V_1426 &&
F_28 ( V_53 , V_1424 , V_1423 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_436 ( struct V_1 * V_17 , T_1 V_638 ,
struct V_54 * V_55 ,
unsigned int V_1423 , T_13 V_1371 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_437 ( V_17 , V_638 , V_55 , V_1423 ) ;
F_435 ( V_1426 ,
V_7 , V_17 , V_638 , V_55 ,
V_1423 , V_1371 ) ;
}
void F_438 ( struct V_1 * V_17 , T_1 V_638 ,
struct V_54 * V_55 ,
T_13 V_1371 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_439 ( V_17 , V_638 , V_55 ) ;
F_435 ( V_1742 ,
V_7 , V_17 , V_638 , V_55 , 0 , V_1371 ) ;
}
void F_440 ( struct V_25 * V_533 , const T_2 * V_640 ,
struct V_779 * V_780 , T_13 V_1371 )
{
struct V_18 * V_18 = V_533 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_441 ( V_533 , V_640 , V_780 ) ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
if ( F_161 ( V_53 , V_874 , 0 , 0 , 0 ,
V_7 , V_533 , V_640 , V_780 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
}
void F_442 ( struct V_25 * V_533 , const T_2 * V_640 ,
struct V_779 * V_780 , T_13 V_1371 )
{
struct V_18 * V_18 = V_533 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_779 V_1743 = {} ;
if ( ! V_780 )
V_780 = & V_1743 ;
F_443 ( V_533 , V_640 ) ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
if ( F_161 ( V_53 , V_1744 , 0 , 0 , 0 ,
V_7 , V_533 , V_640 , V_780 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
}
void F_444 ( struct V_25 * V_533 , const T_2 * V_640 ,
enum V_1745 V_1396 ,
T_13 V_1371 )
{
struct V_18 * V_18 = V_533 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_1746 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1747 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_640 ) ||
F_28 ( V_53 , V_1748 , V_1396 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static bool F_445 ( struct V_25 * V_533 , T_2 V_52 ,
const T_2 * V_668 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1629 = F_446 ( V_17 -> V_1622 ) ;
if ( ! V_1629 )
return false ;
V_53 = F_74 ( 100 , V_1371 ) ;
if ( ! V_53 )
return true ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_668 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_447 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1629 ) ;
return true ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_448 ( struct V_25 * V_533 ,
const T_2 * V_668 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
bool V_490 ;
F_449 ( V_533 , V_668 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_450 ( false ) ;
return false ;
}
V_490 = F_445 ( V_533 , V_1749 ,
V_668 , V_1371 ) ;
F_450 ( V_490 ) ;
return V_490 ;
}
bool F_451 ( struct V_25 * V_533 ,
const T_2 * V_668 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
bool V_490 ;
F_452 ( V_533 , V_668 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_450 ( false ) ;
return false ;
}
V_490 = F_445 ( V_533 ,
V_1750 ,
V_668 , V_1371 ) ;
F_450 ( V_490 ) ;
return V_490 ;
}
int F_453 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1629 ,
int V_1751 , int V_1752 ,
const T_2 * V_1471 , T_11 V_47 , V_22 V_51 , T_13 V_1371 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1475 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_516 , V_1751 ) ||
( V_1752 &&
F_28 ( V_53 , V_1753 , V_1752 ) ) ||
F_51 ( V_53 , V_1468 , V_47 , V_1471 ) ||
( V_51 &&
F_28 ( V_53 , V_1754 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_447 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1629 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_454 ( struct V_1 * V_17 , T_1 V_638 ,
const T_2 * V_1471 , T_11 V_47 , bool V_1755 , T_13 V_1371 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
F_455 ( V_17 , V_638 , V_1755 ) ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1756 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1468 , V_47 , V_1471 ) ||
F_104 ( V_53 , V_1427 , V_638 ) ||
( V_1755 && F_29 ( V_53 , V_1757 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_456 ( struct V_25 * V_533 ,
const char * V_946 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_592 , V_1371 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1758 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) )
goto V_61;
if ( V_946 && F_51 ( V_53 , V_541 , V_581 , V_946 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1494 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_457 ( struct V_31 * V_53 , T_13 V_1371 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
}
void F_458 ( struct V_25 * V_533 ,
enum V_1759 V_1760 ,
T_13 V_1371 )
{
struct V_31 * V_53 ;
F_459 ( V_533 , V_1760 ) ;
if ( F_59 ( V_1760 != V_1761 &&
V_1760 != V_1762 ) )
return;
V_53 = F_456 ( V_533 , NULL , V_1371 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1763 ,
V_1760 ) )
goto V_61;
F_457 ( V_53 , V_1371 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_460 ( struct V_25 * V_533 ,
const T_2 * V_1413 , V_22 V_1764 ,
V_22 V_244 , V_22 V_1486 , T_13 V_1371 )
{
struct V_31 * V_53 ;
V_53 = F_456 ( V_533 , V_1413 , V_1371 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1499 , V_1764 ) )
goto V_61;
if ( F_28 ( V_53 , V_1498 , V_244 ) )
goto V_61;
if ( F_28 ( V_53 , V_1500 , V_1486 ) )
goto V_61;
F_457 ( V_53 , V_1371 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_461 ( struct V_25 * V_533 ,
const T_2 * V_1413 , V_22 V_1764 , T_13 V_1371 )
{
struct V_31 * V_53 ;
F_462 ( V_533 , V_1413 , V_1764 ) ;
V_53 = F_456 ( V_533 , V_1413 , V_1371 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1765 , V_1764 ) )
goto V_61;
F_457 ( V_53 , V_1371 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_463 ( struct V_25 * V_533 , T_13 V_1371 )
{
struct V_31 * V_53 ;
V_53 = F_456 ( V_533 , NULL , V_1371 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1766 ) )
goto V_61;
F_457 ( V_53 , V_1371 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_464 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
const T_2 * V_1620 , T_13 V_1371 )
{
struct V_31 * V_53 ;
struct V_4 * V_1767 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1768 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_540 ) )
goto V_61;
V_1767 = F_47 ( V_53 , V_1608 ) ;
if ( ! V_1767 )
goto V_61;
if ( F_51 ( V_53 , V_1611 ,
V_1612 , V_1620 ) )
goto V_61;
F_48 ( V_53 , V_1767 ) ;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_465 ( struct V_25 * V_533 , const T_2 * V_540 ,
const T_2 * V_1620 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_466 ( V_533 , V_540 ) ;
F_464 ( V_7 , V_533 , V_540 , V_1620 , V_1371 ) ;
}
static void
F_467 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1769 ,
const T_2 * V_540 , bool V_1770 , T_13 V_1371 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1771 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1772 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1773 , V_1769 ) ||
F_51 ( V_53 , V_1774 , V_581 , V_540 ) ||
( V_1770 &&
F_29 ( V_53 , V_1775 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_468 ( struct V_25 * V_533 , int V_1769 ,
const T_2 * V_540 , bool V_1770 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_469 ( V_533 , V_1769 , V_540 , V_1770 ) ;
F_467 ( V_7 , V_533 , V_1769 , V_540 , V_1770 , V_1371 ) ;
}
static void F_470 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_513 * V_514 ,
T_13 V_1371 ,
enum V_280 V_1776 ,
T_2 V_1223 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1776 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_514 ) )
goto V_61;
if ( ( V_1776 == V_1777 ) &&
( F_28 ( V_53 , V_1221 , V_1223 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_471 ( struct V_25 * V_533 ,
struct V_513 * V_514 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_472 ( V_533 , V_514 ) ;
V_17 -> V_514 = * V_514 ;
V_17 -> V_539 = * V_514 ;
F_470 ( V_7 , V_533 , V_514 , V_135 ,
V_1778 , 0 ) ;
}
void F_473 ( struct V_25 * V_533 ,
struct V_513 * V_514 ,
T_2 V_1223 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_474 ( V_533 , V_514 ) ;
F_470 ( V_7 , V_533 , V_514 , V_135 ,
V_1777 , V_1223 ) ;
}
void
F_475 ( struct V_6 * V_7 ,
const struct V_513 * V_514 ,
enum V_1779 V_617 ,
struct V_25 * V_19 , T_13 V_1371 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1780 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
}
if ( F_28 ( V_53 , V_1781 , V_617 ) )
goto V_61;
if ( F_101 ( V_53 , V_514 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_476 ( struct V_25 * V_533 , const T_2 * V_668 ,
T_1 V_638 , bool V_1782 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_477 ( V_533 , V_668 , V_638 , V_1782 ) ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1623 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_668 ) ||
F_104 ( V_53 , V_1427 , V_638 ) ||
( V_1782 && F_29 ( V_53 , V_1757 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_478 ( struct V_18 * V_18 ,
const T_2 * V_1783 , T_11 V_47 ,
int V_1751 , int V_1752 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
struct V_1624 * V_1625 ;
F_479 ( V_18 , V_1783 , V_47 , V_1751 , V_1752 ) ;
F_260 ( & V_7 -> V_1628 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1709 ) ;
if ( ! V_53 ) {
F_262 ( & V_7 -> V_1628 ) ;
return;
}
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1475 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1751 &&
F_28 ( V_53 , V_516 , V_1751 ) ) ||
( V_1752 &&
F_28 ( V_53 , V_1753 , V_1752 ) ) ||
F_51 ( V_53 , V_1468 , V_47 , V_1783 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_447 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1625 -> V_1629 ) ;
}
F_262 ( & V_7 -> V_1628 ) ;
return;
V_61:
F_262 ( & V_7 -> V_1628 ) ;
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_480 ( struct V_31 * V_53 ,
struct V_1784 * V_1785 )
{
struct V_1786 * V_1536 = V_1785 -> V_1787 ;
struct V_4 * V_1788 , * V_1789 , * V_286 ;
int V_159 , V_161 ;
V_1788 = F_47 (
V_53 , V_1790 ) ;
if ( ! V_1788 )
return - V_489 ;
for ( V_159 = 0 ; V_159 < V_1536 -> V_1791 ; V_159 ++ ) {
struct V_1792 * V_1538 = V_1536 -> V_1537 [ V_159 ] ;
V_1789 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1789 )
break;
if ( F_51 ( V_53 , V_585 , V_1538 -> V_586 . V_584 ,
V_1538 -> V_586 . V_586 ) ) {
F_481 ( V_53 , V_1789 ) ;
goto V_591;
}
if ( V_1538 -> V_360 ) {
V_286 = F_47 (
V_53 , V_1171 ) ;
if ( ! V_286 ) {
F_481 ( V_53 , V_1789 ) ;
goto V_591;
}
for ( V_161 = 0 ; V_161 < V_1538 -> V_360 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1538 -> V_361 [ V_161 ] ) ) {
F_481 ( V_53 , V_286 ) ;
F_481 ( V_53 , V_1789 ) ;
goto V_591;
}
}
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_1789 ) ;
}
V_591:
F_48 ( V_53 , V_1788 ) ;
return 0 ;
}
void F_482 ( struct V_1 * V_17 ,
struct V_1784 * V_1785 ,
T_13 V_1371 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
int V_1539 = 200 ;
F_483 ( V_17 -> V_18 , V_17 , V_1785 ) ;
if ( V_1785 )
V_1539 += V_1785 -> V_1793 ;
V_53 = F_74 ( V_1539 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1794 ) ;
if ( ! V_283 )
goto V_648;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_648;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_648;
if ( V_1785 ) {
struct V_4 * V_1795 ;
V_1795 = F_47 ( V_53 , V_1541 ) ;
if ( ! V_1795 )
goto V_648;
if ( V_1785 -> V_445 &&
F_29 ( V_53 , V_206 ) )
goto V_648;
if ( V_1785 -> V_1543 &&
F_29 ( V_53 , V_208 ) )
goto V_648;
if ( V_1785 -> V_1544 &&
F_29 ( V_53 , V_212 ) )
goto V_648;
if ( V_1785 -> V_1545 &&
F_29 ( V_53 , V_214 ) )
goto V_648;
if ( V_1785 -> V_1546 &&
F_29 ( V_53 , V_216 ) )
goto V_648;
if ( V_1785 -> V_1547 &&
F_29 ( V_53 , V_218 ) )
goto V_648;
if ( V_1785 -> V_1796 >= 0 &&
F_28 ( V_53 , V_228 ,
V_1785 -> V_1796 ) )
goto V_648;
if ( V_1785 -> V_1797 &&
F_29 ( V_53 , V_1798 ) )
goto V_648;
if ( V_1785 -> V_1799 &&
F_29 ( V_53 , V_1800 ) )
goto V_648;
if ( V_1785 -> V_1801 &&
F_29 ( V_53 ,
V_1802 ) )
goto V_648;
if ( V_1785 -> V_1803 ) {
V_22 V_1804 = V_1805 ;
V_22 V_1806 = V_1807 ;
if ( ! V_1785 -> V_1808 ) {
V_1804 =
V_1809 ;
V_1806 =
V_1810 ;
}
if ( V_1785 -> V_1811 &&
F_28 ( V_53 , V_1806 , V_1785 -> V_1811 ) )
goto V_648;
if ( F_51 ( V_53 , V_1804 , V_1785 -> V_1793 ,
V_1785 -> V_1803 ) )
goto V_648;
}
if ( V_1785 -> V_1787 &&
F_480 ( V_53 , V_1785 ) )
goto V_648;
F_48 ( V_53 , V_1795 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_648:
F_75 ( V_53 ) ;
}
void F_484 ( struct V_25 * V_533 , const T_2 * V_1413 ,
enum V_1420 V_1812 ,
T_3 V_953 , T_13 V_1371 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_485 ( V_17 -> V_18 , V_533 , V_1413 , V_1812 ,
V_953 ) ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1813 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_56 ( V_53 , V_1422 , V_1812 ) ||
F_51 ( V_53 , V_541 , V_581 , V_1413 ) ||
( V_953 > 0 &&
F_55 ( V_53 , V_952 , V_953 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_1371 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_486 ( struct V_1814 * V_1815 ,
unsigned long V_282 ,
void * V_1816 )
{
struct V_1817 * V_1818 = V_1816 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1624 * V_1625 , * V_24 ;
if ( V_282 != V_1819 )
return V_1820 ;
F_219 () ;
F_487 (rdev, &cfg80211_rdev_list, list) {
bool V_1821 = false ;
bool V_1822 = false ;
struct V_1186 * V_1207 =
F_220 ( V_7 -> V_1207 ) ;
if ( V_1207 && V_1818 -> V_49 &&
V_1207 -> V_623 == V_1818 -> V_49 )
V_1822 = true ;
F_487 (wdev, &rdev->wdev_list, list) {
F_488 ( V_17 , V_1818 -> V_49 ) ;
if ( V_17 -> V_623 == V_1818 -> V_49 )
V_1821 = true ;
}
F_260 ( & V_7 -> V_1628 ) ;
F_489 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1625 -> V_1629 == V_1818 -> V_49 ) {
F_490 ( & V_1625 -> V_629 ) ;
F_41 ( V_1625 ) ;
break;
}
}
F_262 ( & V_7 -> V_1628 ) ;
if ( V_1821 ) {
struct V_1823 * V_1824 ;
V_1824 = F_38 ( sizeof( * V_1824 ) , V_1709 ) ;
if ( V_1824 ) {
V_1824 -> V_1629 = V_1818 -> V_49 ;
F_491 ( & V_7 -> V_1825 ) ;
F_374 ( & V_1824 -> V_629 , & V_7 -> V_1826 ) ;
F_492 ( & V_7 -> V_1825 ) ;
F_493 ( & V_7 -> V_1827 ) ;
}
} else if ( V_1822 ) {
V_1207 -> V_623 = 0 ;
if ( V_7 -> V_345 -> V_1209 &&
V_7 -> V_18 . V_51 & V_416 )
F_493 ( & V_7 -> V_1828 ) ;
}
}
F_221 () ;
return V_1829 ;
}
void F_494 ( struct V_25 * V_19 ,
struct V_1830 * V_1831 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_495 ( V_18 , V_19 , V_1831 ) ;
if ( ! V_1831 -> V_1832 )
return;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1833 ) ;
if ( ! V_283 )
goto V_591;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_1831 -> V_1832 ) )
goto V_591;
if ( V_1831 -> V_1242 &&
F_51 ( V_53 , V_674 , V_1831 -> V_1834 , V_1831 -> V_1242 ) )
goto V_591;
if ( V_1831 -> V_1835 &&
F_51 ( V_53 , V_1836 , V_1831 -> V_1837 ,
V_1831 -> V_1835 ) )
goto V_591;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1711 , V_135 ) ;
return;
V_591:
F_75 ( V_53 ) ;
}
void F_496 ( struct V_1 * V_17 , T_13 V_1371 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1629 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1646 )
return;
V_1629 = V_7 -> V_1646 ;
V_7 -> V_1646 = 0 ;
V_53 = F_74 ( V_592 , V_1371 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1838 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_447 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1629 ) ;
return;
V_61:
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_497 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1839 ) ;
if ( ! V_283 )
goto V_591;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_591;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1711 , V_135 ) ;
return;
V_591:
F_75 ( V_53 ) ;
}
int F_498 ( void )
{
int V_35 ;
V_35 = F_499 ( & V_38 , V_1840 ,
V_1841 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_500 ( & V_1842 ) ;
if ( V_35 )
goto V_1843;
return 0 ;
V_1843:
F_501 ( & V_38 ) ;
return V_35 ;
}
void F_502 ( void )
{
F_503 ( & V_1842 ) ;
F_501 ( & V_38 ) ;
}
