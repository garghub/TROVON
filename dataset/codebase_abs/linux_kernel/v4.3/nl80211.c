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
if ( ! F_85 ( & V_7 -> V_18 , & V_514 ,
V_141 ) ) {
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
V_621 , type , V_35 ? NULL : & V_51 ,
& V_137 ) ;
if ( F_59 ( ! V_17 ) ) {
F_75 ( V_53 ) ;
return - V_622 ;
} else if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_623 ] )
V_17 -> V_624 = V_30 -> V_498 ;
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
F_121 ( & V_17 -> V_625 ) ;
F_122 ( & V_17 -> V_626 ) ;
F_123 ( & V_17 -> V_627 ) ;
F_122 ( & V_17 -> V_628 ) ;
F_123 ( & V_17 -> V_629 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_124 ( & V_17 -> V_630 , & V_7 -> V_631 ) ;
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
V_617 , 0 , V_632 ,
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
int V_633 ;
if ( ! V_7 -> V_345 -> V_634 )
return - V_534 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( V_53 && F_103 ( V_53 , 0 , 0 , 0 , V_7 , V_17 , true ) < 0 ) {
F_75 ( V_53 ) ;
V_53 = NULL ;
}
if ( ! V_17 -> V_19 )
V_30 -> V_497 [ 1 ] = NULL ;
V_633 = F_127 ( V_7 , V_17 ) ;
if ( V_633 >= 0 && V_53 )
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_632 ,
V_135 ) ;
else
F_75 ( V_53 ) ;
return V_633 ;
}
static int F_128 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_3 V_635 ;
if ( ! V_30 -> V_5 [ V_636 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_421 )
return - V_534 ;
V_635 = F_78 ( V_30 -> V_5 [ V_636 ] ) ;
return F_129 ( V_7 , V_533 , V_635 ) ;
}
static void F_130 ( void * V_165 , struct V_637 * V_137 )
{
struct V_4 * V_92 ;
struct V_638 * V_639 = V_165 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_639 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_639 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_639 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_639 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_639 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_639 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_639 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_639 -> V_53 , V_123 , V_639 -> V_105 ) )
goto V_61;
F_48 ( V_639 -> V_53 , V_92 ) ;
return;
V_61:
V_639 -> error = 1 ;
}
static int F_131 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 V_640 = 0 ;
const T_2 * V_641 = NULL ;
bool V_642 ;
struct V_638 V_639 = {
. error = 0 ,
} ;
void * V_283 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_640 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_640 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_541 ] )
V_641 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_642 = ! ! V_641 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_643 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_643 >= V_114 )
return - V_16 ;
if ( V_643 != V_644 &&
V_643 != V_645 )
return - V_16 ;
V_642 = V_643 == V_645 ;
}
if ( ! V_7 -> V_345 -> V_646 )
return - V_534 ;
if ( ! V_642 && V_641 && ! ( V_7 -> V_18 . V_51 & V_318 ) )
return - V_647 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_648 ) ;
if ( ! V_283 )
goto V_61;
V_639 . V_53 = V_53 ;
V_639 . V_105 = V_640 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_640 ) )
goto V_61;
if ( V_641 &&
F_51 ( V_53 , V_541 , V_581 , V_641 ) )
goto V_61;
V_35 = F_132 ( V_7 , V_533 , V_640 , V_642 , V_641 , & V_639 ,
F_130 ) ;
if ( V_35 )
goto V_649;
if ( V_639 . error )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_649:
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
if ( ! V_7 -> V_345 -> V_650 ) {
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
V_533 -> V_28 -> V_651 . V_652 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_591;
}
if ( ! V_7 -> V_345 -> V_653 ) {
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
V_533 -> V_28 -> V_651 . V_654 = V_92 . V_105 ;
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
const T_2 * V_641 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_541 ] )
V_641 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_641 )
V_92 . type = V_645 ;
else
V_92 . type = V_644 ;
}
if ( V_92 . type != V_645 &&
V_92 . type != V_644 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_367 )
return - V_534 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_645 ,
V_641 ) )
return - V_16 ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_42 ( V_533 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_138 ( V_7 , V_533 , V_92 . V_105 ,
V_92 . type == V_645 ,
V_641 , & V_92 . V_107 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_139 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_641 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_541 ] )
V_641 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_641 )
V_92 . type = V_645 ;
else
V_92 . type = V_644 ;
}
if ( V_92 . type != V_645 &&
V_92 . type != V_644 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_655 )
return - V_534 ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_42 ( V_533 -> V_28 ) ;
if ( V_92 . type == V_644 && V_641 &&
! ( V_7 -> V_18 . V_51 & V_318 ) )
V_35 = - V_647 ;
if ( ! V_35 )
V_35 = F_140 ( V_7 , V_533 , V_92 . V_105 ,
V_92 . type == V_645 ,
V_641 ) ;
#ifdef F_135
if ( ! V_35 ) {
if ( V_92 . V_105 == V_533 -> V_28 -> V_651 . V_652 )
V_533 -> V_28 -> V_651 . V_652 = - 1 ;
else if ( V_92 . V_105 == V_533 -> V_28 -> V_651 . V_654 )
V_533 -> V_28 -> V_651 . V_654 = - 1 ;
}
#endif
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_141 ( struct V_4 * V_656 )
{
struct V_4 * V_45 ;
int V_657 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_581 )
return - V_16 ;
V_657 ++ ;
}
return V_657 ;
}
static struct V_658 * F_142 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_659 V_660 ;
struct V_4 * V_45 ;
struct V_658 * V_661 ;
int V_159 = 0 , V_657 , V_24 ;
if ( ! V_18 -> V_460 )
return F_3 ( - V_534 ) ;
if ( ! V_30 -> V_5 [ V_662 ] )
return F_3 ( - V_16 ) ;
V_660 = F_4 ( V_30 -> V_5 [ V_662 ] ) ;
if ( V_660 != V_663 &&
V_660 != V_664 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_665 ] )
return F_3 ( - V_16 ) ;
V_657 = F_141 ( V_30 -> V_5 [ V_665 ] ) ;
if ( V_657 < 0 )
return F_3 ( V_657 ) ;
if ( V_657 > V_18 -> V_460 )
return F_3 ( - V_666 ) ;
V_661 = F_38 ( sizeof( * V_661 ) + ( sizeof( struct V_667 ) * V_657 ) ,
V_135 ) ;
if ( ! V_661 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_661 -> V_668 [ V_159 ] . V_669 , F_23 ( V_45 ) , V_581 ) ;
V_159 ++ ;
}
V_661 -> V_670 = V_657 ;
V_661 -> V_660 = V_660 ;
return V_661 ;
}
static int F_143 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_658 * V_661 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_534 ;
if ( ! V_533 -> V_28 -> V_535 )
return - V_16 ;
V_661 = F_142 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_661 ) )
return F_18 ( V_661 ) ;
V_35 = F_144 ( V_7 , V_533 , V_661 ) ;
F_41 ( V_661 ) ;
return V_35 ;
}
static int F_145 ( struct V_4 * V_5 [] ,
struct V_671 * V_672 )
{
bool V_673 = false ;
if ( ! F_22 ( V_5 [ V_674 ] ) ||
! F_22 ( V_5 [ V_675 ] ) ||
! F_22 ( V_5 [ V_676 ] ) ||
! F_22 ( V_5 [ V_677 ] ) )
return - V_16 ;
memset ( V_672 , 0 , sizeof( * V_672 ) ) ;
if ( V_5 [ V_678 ] ) {
V_672 -> V_679 = F_23 ( V_5 [ V_678 ] ) ;
V_672 -> V_680 = F_24 ( V_5 [ V_678 ] ) ;
if ( ! V_672 -> V_680 )
return - V_16 ;
V_673 = true ;
}
if ( V_5 [ V_674 ] ) {
V_672 -> V_681 = F_23 ( V_5 [ V_674 ] ) ;
V_672 -> V_682 = F_24 ( V_5 [ V_674 ] ) ;
V_673 = true ;
}
if ( ! V_673 )
return - V_16 ;
if ( V_5 [ V_675 ] ) {
V_672 -> V_683 = F_23 ( V_5 [ V_675 ] ) ;
V_672 -> V_684 = F_24 ( V_5 [ V_675 ] ) ;
}
if ( V_5 [ V_676 ] ) {
V_672 -> V_685 =
F_23 ( V_5 [ V_676 ] ) ;
V_672 -> V_686 =
F_24 ( V_5 [ V_676 ] ) ;
}
if ( V_5 [ V_677 ] ) {
V_672 -> V_687 =
F_23 ( V_5 [ V_677 ] ) ;
V_672 -> V_688 =
F_24 ( V_5 [ V_677 ] ) ;
}
if ( V_5 [ V_689 ] ) {
V_672 -> V_690 = F_23 ( V_5 [ V_689 ] ) ;
V_672 -> V_691 = F_24 ( V_5 [ V_689 ] ) ;
}
return 0 ;
}
static bool F_146 ( struct V_6 * V_7 ,
struct V_692 * V_137 )
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
enum V_693 V_694 ,
enum V_280 V_52 )
{
if ( V_694 > V_695 )
return false ;
switch ( V_52 ) {
case V_696 :
if ( ! ( V_7 -> V_18 . V_291 & V_697 ) &&
V_694 == V_698 )
return false ;
return true ;
case V_444 :
case V_699 :
if ( V_694 == V_698 )
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
struct V_692 V_137 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_369 )
return - V_534 ;
if ( V_17 -> V_535 )
return - V_700 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_701 ] ||
! V_30 -> V_5 [ V_702 ] ||
! V_30 -> V_5 [ V_678 ] )
return - V_16 ;
V_35 = F_145 ( V_30 -> V_5 , & V_137 . V_703 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_535 =
F_4 ( V_30 -> V_5 [ V_701 ] ) ;
V_137 . V_704 =
F_4 ( V_30 -> V_5 [ V_702 ] ) ;
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
if ( V_30 -> V_5 [ V_705 ] ) {
V_137 . V_706 = F_4 (
V_30 -> V_5 [ V_705 ] ) ;
if ( V_137 . V_706 != V_707 &&
V_137 . V_706 != V_708 &&
V_137 . V_706 != V_709 )
return - V_16 ;
}
V_137 . V_710 = ! ! V_30 -> V_5 [ V_711 ] ;
if ( V_30 -> V_5 [ V_712 ] ) {
V_137 . V_694 = F_4 (
V_30 -> V_5 [ V_712 ] ) ;
if ( ! F_147 ( V_7 , V_137 . V_694 ,
V_699 ) )
return - V_16 ;
} else
V_137 . V_694 = V_713 ;
V_35 = F_150 ( V_7 , V_30 , & V_137 . V_714 ,
V_715 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_716 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_717 ) )
return - V_534 ;
V_137 . V_718 = F_78 (
V_30 -> V_5 [ V_716 ] ) ;
}
if ( V_30 -> V_5 [ V_719 ] ) {
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_720 =
F_34 ( V_30 -> V_5 [ V_719 ] ) ;
if ( V_137 . V_720 > 127 )
return - V_16 ;
if ( V_137 . V_720 != 0 &&
! ( V_7 -> V_18 . V_291 & V_721 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_722 ] ) {
T_2 V_24 ;
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_722 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_723 = V_24 ;
if ( V_137 . V_723 != 0 &&
! ( V_7 -> V_18 . V_291 & V_724 ) )
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
if ( V_30 -> V_5 [ V_662 ] ) {
V_137 . V_661 = F_142 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_661 ) )
return F_18 ( V_137 . V_661 ) ;
}
if ( V_30 -> V_5 [ V_725 ] ) {
V_137 . V_726 =
F_34 ( V_30 -> V_5 [ V_725 ] ) ;
switch ( V_137 . V_726 ) {
case V_727 :
break;
case V_728 :
if ( ! ( V_7 -> V_18 . V_291 &
V_729 ) )
return - V_16 ;
break;
case V_730 :
if ( ! ( V_7 -> V_18 . V_291 &
V_731 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_137 . V_726 = V_727 ;
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
F_41 ( V_137 . V_661 ) ;
return V_35 ;
}
static int F_152 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_671 V_137 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_732 )
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
struct V_733 * V_137 )
{
struct V_4 * V_51 [ V_734 + 1 ] ;
struct V_4 * V_593 ;
int V_596 ;
V_593 = V_30 -> V_5 [ V_735 ] ;
if ( V_593 ) {
struct V_736 * V_737 ;
V_737 = F_23 ( V_593 ) ;
V_137 -> V_738 = V_737 -> V_739 ;
V_137 -> V_740 = V_737 -> V_741 ;
V_137 -> V_740 &= V_137 -> V_738 ;
if ( ( V_137 -> V_738 |
V_137 -> V_740 ) & F_157 ( V_742 ) )
return - V_16 ;
return 0 ;
}
V_593 = V_30 -> V_5 [ V_743 ] ;
if ( ! V_593 )
return 0 ;
if ( F_33 ( V_51 , V_734 ,
V_593 , V_744 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_738 = F_157 ( V_745 ) |
F_157 ( V_746 ) |
F_157 ( V_747 ) |
F_157 ( V_748 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_738 = F_157 ( V_745 ) |
F_157 ( V_749 ) ;
break;
case V_145 :
V_137 -> V_738 = F_157 ( V_750 ) |
F_157 ( V_748 ) |
F_157 ( V_745 ) ;
default:
return - V_16 ;
}
for ( V_596 = 1 ; V_596 <= V_734 ; V_596 ++ ) {
if ( V_51 [ V_596 ] ) {
V_137 -> V_740 |= ( 1 << V_596 ) ;
if ( V_596 > V_751 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_158 ( struct V_31 * V_53 , struct V_752 * V_30 ,
int V_45 )
{
struct V_4 * V_244 ;
V_22 V_264 ;
T_3 V_753 ;
enum V_754 V_755 ;
V_244 = F_47 ( V_53 , V_45 ) ;
if ( ! V_244 )
return false ;
V_264 = F_159 ( V_30 ) ;
V_753 = V_264 < ( 1UL << 16 ) ? V_264 : 0 ;
if ( V_264 > 0 &&
F_28 ( V_53 , V_756 , V_264 ) )
return false ;
if ( V_753 > 0 &&
F_55 ( V_53 , V_757 , V_753 ) )
return false ;
switch ( V_30 -> V_758 ) {
case V_759 :
V_755 = V_760 ;
break;
case V_761 :
V_755 = V_762 ;
break;
default:
F_59 ( 1 ) ;
case V_763 :
V_755 = 0 ;
break;
case V_764 :
V_755 = V_765 ;
break;
case V_766 :
V_755 = V_767 ;
break;
case V_768 :
V_755 = V_769 ;
break;
}
if ( V_755 && F_29 ( V_53 , V_755 ) )
return false ;
if ( V_30 -> V_51 & V_770 ) {
if ( F_56 ( V_53 , V_771 , V_30 -> V_248 ) )
return false ;
if ( V_30 -> V_51 & V_772 &&
F_29 ( V_53 , V_773 ) )
return false ;
} else if ( V_30 -> V_51 & V_774 ) {
if ( F_56 ( V_53 , V_775 , V_30 -> V_248 ) )
return false ;
if ( F_56 ( V_53 , V_776 , V_30 -> V_777 ) )
return false ;
if ( V_30 -> V_51 & V_772 &&
F_29 ( V_53 , V_773 ) )
return false ;
}
F_48 ( V_53 , V_244 ) ;
return true ;
}
static bool F_160 ( struct V_31 * V_53 , T_2 V_739 , T_6 * signal ,
int V_778 )
{
void * V_45 ;
int V_159 = 0 ;
if ( ! V_739 )
return true ;
V_45 = F_47 ( V_53 , V_778 ) ;
if ( ! V_45 )
return false ;
for ( V_159 = 0 ; V_159 < V_779 ; V_159 ++ ) {
if ( ! ( V_739 & F_157 ( V_159 ) ) )
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
const T_2 * V_641 , struct V_780 * V_781 )
{
void * V_283 ;
struct V_4 * V_782 , * V_783 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_641 ) ||
F_28 ( V_53 , V_293 , V_781 -> V_784 ) )
goto V_61;
V_782 = F_47 ( V_53 , V_785 ) ;
if ( ! V_782 )
goto V_61;
#define F_162 ( V_45 , T_7 , type ) do { \
if (sinfo->filled & BIT(NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
F_162 ( V_786 , V_787 , V_22 ) ;
F_162 ( V_788 , V_789 , V_22 ) ;
if ( V_781 -> V_790 & ( F_157 ( V_791 ) |
F_157 ( V_792 ) ) &&
F_28 ( V_53 , V_791 ,
( V_22 ) V_781 -> V_793 ) )
goto V_61;
if ( V_781 -> V_790 & ( F_157 ( V_794 ) |
F_157 ( V_795 ) ) &&
F_28 ( V_53 , V_794 ,
( V_22 ) V_781 -> V_796 ) )
goto V_61;
F_162 ( V_797 , V_793 , T_1 ) ;
F_162 ( V_798 , V_796 , T_1 ) ;
F_162 ( V_799 , V_800 , T_3 ) ;
F_162 ( V_801 , V_802 , T_3 ) ;
F_162 ( V_803 , V_804 , T_2 ) ;
switch ( V_7 -> V_18 . V_805 ) {
case V_806 :
F_162 ( SIGNAL , signal , T_2 ) ;
F_162 ( V_807 , V_808 , T_2 ) ;
break;
default:
break;
}
if ( V_781 -> V_790 & F_157 ( V_809 ) ) {
if ( ! F_160 ( V_53 , V_781 -> V_810 ,
V_781 -> V_811 ,
V_809 ) )
goto V_61;
}
if ( V_781 -> V_790 & F_157 ( V_812 ) ) {
if ( ! F_160 ( V_53 , V_781 -> V_810 ,
V_781 -> V_813 ,
V_812 ) )
goto V_61;
}
if ( V_781 -> V_790 & F_157 ( V_814 ) ) {
if ( ! F_158 ( V_53 , & V_781 -> V_815 ,
V_814 ) )
goto V_61;
}
if ( V_781 -> V_790 & F_157 ( V_816 ) ) {
if ( ! F_158 ( V_53 , & V_781 -> V_817 ,
V_816 ) )
goto V_61;
}
F_162 ( V_818 , V_819 , V_22 ) ;
F_162 ( V_820 , V_821 , V_22 ) ;
F_162 ( V_822 , V_823 , V_22 ) ;
F_162 ( V_824 , V_825 , V_22 ) ;
F_162 ( V_826 , V_827 , V_22 ) ;
F_162 ( V_828 , V_829 , V_22 ) ;
F_162 ( V_830 , V_831 , V_22 ) ;
F_162 ( V_832 , V_833 , V_22 ) ;
F_162 ( V_834 , V_835 , V_22 ) ;
if ( V_781 -> V_790 & F_157 ( V_836 ) ) {
V_783 = F_47 ( V_53 , V_836 ) ;
if ( ! V_783 )
goto V_61;
if ( ( ( V_781 -> V_783 . V_51 & V_837 ) &&
F_29 ( V_53 , V_838 ) ) ||
( ( V_781 -> V_783 . V_51 & V_839 ) &&
F_29 ( V_53 , V_840 ) ) ||
( ( V_781 -> V_783 . V_51 & V_841 ) &&
F_29 ( V_53 , V_842 ) ) ||
F_56 ( V_53 , V_843 ,
V_781 -> V_783 . V_704 ) ||
F_55 ( V_53 , V_844 ,
V_781 -> V_783 . V_535 ) )
goto V_61;
F_48 ( V_53 , V_783 ) ;
}
if ( ( V_781 -> V_790 & F_157 ( V_845 ) ) &&
F_51 ( V_53 , V_845 ,
sizeof( struct V_736 ) ,
& V_781 -> V_737 ) )
goto V_61;
F_162 ( V_846 , V_847 , T_1 ) ;
F_162 ( V_848 , V_849 , T_1 ) ;
F_162 ( V_850 , V_851 , T_1 ) ;
F_162 ( V_852 , V_853 , T_2 ) ;
#undef F_162
if ( V_781 -> V_790 & F_157 ( V_854 ) ) {
struct V_4 * V_855 ;
int V_856 ;
V_855 = F_47 ( V_53 , V_854 ) ;
if ( ! V_855 )
goto V_61;
for ( V_856 = 0 ; V_856 < V_857 + 1 ; V_856 ++ ) {
struct V_858 * V_859 ;
struct V_4 * V_860 ;
V_859 = & V_781 -> V_861 [ V_856 ] ;
if ( ! V_859 -> V_790 )
continue;
V_860 = F_47 ( V_53 , V_856 + 1 ) ;
if ( ! V_860 )
goto V_61;
#define F_163 ( V_45 , T_7 , type ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_ ## type(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb)) \
goto nla_put_failure; \
} while (0)
F_163 ( V_862 , V_863 , T_1 ) ;
F_163 ( V_864 , V_865 , T_1 ) ;
F_163 ( V_866 , V_867 , T_1 ) ;
F_163 ( V_868 , V_869 , T_1 ) ;
#undef F_163
F_48 ( V_53 , V_860 ) ;
}
F_48 ( V_53 , V_855 ) ;
}
F_48 ( V_53 , V_782 ) ;
if ( V_781 -> V_870 &&
F_51 ( V_53 , V_675 , V_781 -> V_870 ,
V_781 -> V_871 ) )
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
struct V_780 V_781 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_641 [ V_581 ] ;
int V_872 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_873;
}
if ( ! V_7 -> V_345 -> V_874 ) {
V_35 = - V_534 ;
goto V_873;
}
while ( 1 ) {
memset ( & V_781 , 0 , sizeof( V_781 ) ) ;
V_35 = F_165 ( V_7 , V_17 -> V_19 , V_872 ,
V_641 , & V_781 ) ;
if ( V_35 == - V_647 )
break;
if ( V_35 )
goto V_873;
if ( F_161 ( V_32 , V_875 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_7 , V_17 -> V_19 , V_641 ,
& V_781 ) < 0 )
goto V_591;
V_872 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_872 ;
V_35 = V_32 -> V_47 ;
V_873:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_166 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_780 V_781 ;
struct V_31 * V_53 ;
T_2 * V_641 = NULL ;
int V_35 ;
memset ( & V_781 , 0 , sizeof( V_781 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_641 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_876 )
return - V_534 ;
V_35 = F_167 ( V_7 , V_533 , V_641 , & V_781 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_161 ( V_53 , V_875 ,
V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_7 , V_533 , V_641 , & V_781 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_168 ( struct V_18 * V_18 ,
struct V_733 * V_137 ,
enum V_877 V_878 )
{
if ( V_137 -> V_879 != - 1 )
return - V_16 ;
if ( V_137 -> V_880 &&
! ( V_137 -> V_740 & F_157 ( V_749 ) ) )
return - V_16 ;
F_113 ( V_734 != 7 ) ;
switch ( V_878 ) {
case V_881 :
case V_882 :
if ( V_137 -> V_738 &
~ ( F_157 ( V_750 ) |
F_157 ( V_748 ) |
F_157 ( V_745 ) ) )
return - V_16 ;
break;
case V_883 :
case V_884 :
if ( ! ( V_137 -> V_740 & F_157 ( V_749 ) ) )
return - V_16 ;
V_137 -> V_738 &= ~ F_157 ( V_749 ) ;
break;
default:
if ( V_137 -> V_885 != V_886 )
return - V_16 ;
if ( V_137 -> V_831 )
return - V_16 ;
if ( V_137 -> V_887 & V_888 )
return - V_16 ;
}
if ( V_878 != V_883 &&
V_878 != V_884 ) {
if ( V_137 -> V_740 & F_157 ( V_749 ) )
return - V_16 ;
V_137 -> V_738 &= ~ F_157 ( V_749 ) ;
}
if ( V_878 != V_883 ) {
if ( V_137 -> V_887 & V_889 )
return - V_16 ;
if ( V_137 -> V_887 & V_890 )
return - V_16 ;
if ( V_137 -> V_891 )
return - V_16 ;
if ( V_137 -> V_892 || V_137 -> V_893 || V_137 -> V_894 )
return - V_16 ;
}
if ( V_878 != V_895 ) {
if ( V_137 -> V_896 )
return - V_16 ;
}
switch ( V_878 ) {
case V_897 :
if ( ! ( V_137 -> V_738 & F_157 ( V_745 ) ) )
return - V_534 ;
break;
case V_895 :
if ( V_137 -> V_738 &
~ ( F_157 ( V_745 ) |
F_157 ( V_750 ) |
F_157 ( V_898 ) |
F_157 ( V_746 ) |
F_157 ( V_747 ) |
F_157 ( V_748 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_291 & V_899 ) &&
V_137 -> V_738 &
( F_157 ( V_750 ) |
F_157 ( V_898 ) ) )
return - V_16 ;
break;
case V_900 :
case V_901 :
if ( V_137 -> V_738 & ~ F_157 ( V_745 ) )
return - V_16 ;
break;
case V_883 :
if ( V_137 -> V_738 & ~ ( F_157 ( V_745 ) |
F_157 ( V_747 ) ) )
return - V_16 ;
if ( V_137 -> V_740 & F_157 ( V_745 ) &&
! V_137 -> V_891 )
return - V_16 ;
break;
case V_884 :
return - V_16 ;
case V_881 :
if ( V_137 -> V_887 & V_888 )
return - V_16 ;
break;
case V_882 :
if ( V_137 -> V_885 != V_886 &&
V_137 -> V_885 != V_902 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_169 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_903 = V_30 -> V_5 [ V_904 ] ;
struct V_25 * V_905 ;
int V_490 ;
if ( ! V_903 )
return NULL ;
V_905 = F_170 ( F_94 ( V_30 ) , F_4 ( V_903 ) ) ;
if ( ! V_905 )
return F_3 ( - V_23 ) ;
if ( ! V_905 -> V_28 || V_905 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_490 = - V_16 ;
goto error;
}
if ( V_905 -> V_28 -> V_141 != V_143 &&
V_905 -> V_28 -> V_141 != V_142 &&
V_905 -> V_28 -> V_141 != V_144 ) {
V_490 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_905 ) ) {
V_490 = - V_548 ;
goto error;
}
return V_905 ;
error:
F_171 ( V_905 ) ;
return F_3 ( V_490 ) ;
}
static int F_172 ( struct V_29 * V_30 ,
struct V_733 * V_137 )
{
struct V_4 * V_95 [ V_906 + 1 ] ;
struct V_4 * V_593 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_907 ] )
return 0 ;
V_593 = V_30 -> V_5 [ V_907 ] ;
V_35 = F_33 ( V_95 , V_906 , V_593 ,
V_908 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_909 ] )
V_137 -> V_910 = F_34 (
V_95 [ V_909 ] ) ;
if ( V_137 -> V_910 & ~ V_911 )
return - V_16 ;
if ( V_95 [ V_912 ] )
V_137 -> V_913 = F_34 ( V_95 [ V_912 ] ) ;
if ( V_137 -> V_913 & ~ V_914 )
return - V_16 ;
V_137 -> V_887 |= V_889 ;
return 0 ;
}
static int F_173 ( struct V_29 * V_30 ,
struct V_733 * V_137 )
{
if ( V_30 -> V_5 [ V_915 ] ) {
V_137 -> V_916 =
F_23 ( V_30 -> V_5 [ V_915 ] ) ;
V_137 -> V_917 =
F_24 ( V_30 -> V_5 [ V_915 ] ) ;
if ( V_137 -> V_917 < 2 )
return - V_16 ;
if ( V_137 -> V_917 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_918 ] ) {
V_137 -> V_919 =
F_23 ( V_30 -> V_5 [ V_918 ] ) ;
V_137 -> V_920 =
F_24 ( V_30 -> V_5 [ V_918 ] ) ;
if ( V_137 -> V_920 < 2 ||
V_137 -> V_920 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_174 ( struct V_29 * V_30 ,
struct V_733 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_921 ] )
V_137 -> V_880 = F_78 ( V_30 -> V_5 [ V_921 ] ) ;
if ( V_30 -> V_5 [ V_922 ] )
V_137 -> V_893 =
F_23 ( V_30 -> V_5 [ V_922 ] ) ;
if ( V_30 -> V_5 [ V_923 ] )
V_137 -> V_894 =
F_23 ( V_30 -> V_5 [ V_923 ] ) ;
V_35 = F_173 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_172 ( V_30 , V_137 ) ;
}
static int F_175 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_733 V_137 ;
T_2 * V_641 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_879 = - 1 ;
if ( ! V_7 -> V_345 -> V_924 )
return - V_534 ;
if ( V_30 -> V_5 [ V_925 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_641 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_30 -> V_5 [ V_926 ] ) {
V_137 . V_891 =
F_23 ( V_30 -> V_5 [ V_926 ] ) ;
V_137 . V_927 =
F_24 ( V_30 -> V_5 [ V_926 ] ) ;
}
if ( V_30 -> V_5 [ V_928 ] ) {
V_137 . V_929 =
F_78 ( V_30 -> V_5 [ V_928 ] ) ;
V_137 . V_887 |= V_890 ;
}
if ( V_30 -> V_5 [ V_930 ] ) {
V_137 . V_892 =
F_23 ( V_30 -> V_5 [ V_930 ] ) ;
V_137 . V_931 =
F_24 ( V_30 -> V_5 [ V_930 ] ) ;
}
if ( V_30 -> V_5 [ V_932 ] )
return - V_16 ;
if ( F_156 ( V_30 , V_533 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_933 ] ) {
V_137 . V_885 =
F_34 ( V_30 -> V_5 [ V_933 ] ) ;
if ( V_137 . V_885 >= V_934 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_935 ] ) {
V_137 . V_804 =
F_34 ( V_30 -> V_5 [ V_935 ] ) ;
if ( V_137 . V_804 >= V_936 )
return - V_16 ;
V_137 . V_887 |= V_888 ;
}
if ( V_30 -> V_5 [ V_937 ] ) {
enum V_938 V_939 = F_4 (
V_30 -> V_5 [ V_937 ] ) ;
if ( V_939 <= V_940 ||
V_939 > V_941 )
return - V_16 ;
V_137 . V_831 = V_939 ;
}
V_35 = F_174 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_896 = F_169 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_896 ) )
return F_18 ( V_137 . V_896 ) ;
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
goto V_942;
}
V_35 = F_176 ( V_7 , V_533 , V_641 , & V_137 ) ;
V_942:
if ( V_137 . V_896 )
F_171 ( V_137 . V_896 ) ;
return V_35 ;
}
static int F_177 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_733 V_137 ;
T_2 * V_641 = NULL ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_345 -> V_371 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_932 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_926 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_925 ] &&
! V_30 -> V_5 [ V_921 ] )
return - V_16 ;
V_641 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_137 . V_891 =
F_23 ( V_30 -> V_5 [ V_926 ] ) ;
V_137 . V_927 =
F_24 ( V_30 -> V_5 [ V_926 ] ) ;
V_137 . V_879 =
F_78 ( V_30 -> V_5 [ V_932 ] ) ;
if ( V_30 -> V_5 [ V_921 ] )
V_137 . V_880 = F_78 ( V_30 -> V_5 [ V_921 ] ) ;
else
V_137 . V_880 = F_78 ( V_30 -> V_5 [ V_925 ] ) ;
if ( ! V_137 . V_880 || V_137 . V_880 > V_943 )
return - V_16 ;
if ( V_30 -> V_5 [ V_928 ] ) {
V_137 . V_929 =
F_78 ( V_30 -> V_5 [ V_928 ] ) ;
V_137 . V_887 |= V_890 ;
}
if ( V_30 -> V_5 [ V_930 ] ) {
V_137 . V_892 =
F_23 ( V_30 -> V_5 [ V_930 ] ) ;
V_137 . V_931 =
F_24 ( V_30 -> V_5 [ V_930 ] ) ;
}
if ( V_30 -> V_5 [ V_922 ] )
V_137 . V_893 =
F_23 ( V_30 -> V_5 [ V_922 ] ) ;
if ( V_30 -> V_5 [ V_923 ] )
V_137 . V_894 =
F_23 ( V_30 -> V_5 [ V_923 ] ) ;
if ( V_30 -> V_5 [ V_944 ] ) {
V_137 . V_945 = true ;
V_137 . V_946 =
F_34 ( V_30 -> V_5 [ V_944 ] ) ;
}
if ( V_30 -> V_5 [ V_933 ] ) {
V_137 . V_885 =
F_34 ( V_30 -> V_5 [ V_933 ] ) ;
if ( V_137 . V_885 >= V_934 )
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
if ( ! ( V_137 . V_740 & F_157 ( V_747 ) ) ) {
V_137 . V_893 = NULL ;
V_137 . V_894 = NULL ;
}
F_113 ( V_734 != 7 ) ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_322 ) ||
! ( V_137 . V_740 & F_157 ( V_747 ) ) )
V_137 . V_887 &= ~ V_889 ;
if ( ( V_137 . V_740 & F_157 ( V_749 ) ) ||
V_30 -> V_5 [ V_921 ] )
return - V_16 ;
V_137 . V_738 &= ~ F_157 ( V_749 ) ;
if ( ! ( V_7 -> V_18 . V_291 &
V_899 ) &&
V_137 . V_738 &
( F_157 ( V_750 ) |
F_157 ( V_898 ) ) )
return - V_16 ;
V_137 . V_896 = F_169 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_896 ) )
return F_18 ( V_137 . V_896 ) ;
break;
case V_145 :
V_137 . V_887 &= ~ V_889 ;
if ( V_137 . V_738 & F_157 ( V_898 ) )
return - V_16 ;
if ( ( V_137 . V_740 & F_157 ( V_749 ) ) ||
V_30 -> V_5 [ V_921 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_887 &= ~ V_889 ;
if ( V_137 . V_738 &
( F_157 ( V_898 ) |
F_157 ( V_750 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_740 & F_157 ( V_749 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_326 ) )
return - V_534 ;
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) )
return - V_534 ;
V_137 . V_738 &= ~ F_157 ( V_745 ) ;
break;
default:
return - V_534 ;
}
V_35 = F_178 ( V_7 , V_533 , V_641 , & V_137 ) ;
if ( V_137 . V_896 )
F_171 ( V_137 . V_896 ) ;
return V_35 ;
}
static int F_179 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_947 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_30 -> V_5 [ V_541 ] )
V_137 . V_948 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_533 -> V_28 -> V_141 != V_142 &&
V_533 -> V_28 -> V_141 != V_143 &&
V_533 -> V_28 -> V_141 != V_145 &&
V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_949 )
return - V_534 ;
if ( V_30 -> V_5 [ V_950 ] ) {
V_137 . V_951 =
F_34 ( V_30 -> V_5 [ V_950 ] ) ;
if ( V_137 . V_951 != V_952 >> 4 &&
V_137 . V_951 != V_953 >> 4 )
return - V_16 ;
} else {
V_137 . V_951 = V_953 >> 4 ;
}
if ( V_30 -> V_5 [ V_954 ] ) {
V_137 . V_955 =
F_78 ( V_30 -> V_5 [ V_954 ] ) ;
if ( V_137 . V_955 == 0 )
return - V_16 ;
} else {
V_137 . V_955 = V_956 ;
}
return F_180 ( V_7 , V_533 , & V_137 ) ;
}
static int F_181 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_533 ,
T_2 * V_957 , T_2 * V_958 ,
struct V_959 * V_960 )
{
void * V_283 ;
struct V_4 * V_961 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_962 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_957 ) ||
F_51 ( V_53 , V_963 , V_581 , V_958 ) ||
F_28 ( V_53 , V_293 , V_960 -> V_784 ) )
goto V_61;
V_961 = F_47 ( V_53 , V_964 ) ;
if ( ! V_961 )
goto V_61;
if ( ( V_960 -> V_790 & V_965 ) &&
F_28 ( V_53 , V_966 ,
V_960 -> V_967 ) )
goto V_61;
if ( ( ( V_960 -> V_790 & V_968 ) &&
F_28 ( V_53 , V_969 , V_960 -> V_970 ) ) ||
( ( V_960 -> V_790 & V_971 ) &&
F_28 ( V_53 , V_972 ,
V_960 -> V_973 ) ) ||
( ( V_960 -> V_790 & V_974 ) &&
F_28 ( V_53 , V_975 ,
V_960 -> V_976 ) ) ||
( ( V_960 -> V_790 & V_977 ) &&
F_56 ( V_53 , V_978 ,
V_960 -> V_51 ) ) ||
( ( V_960 -> V_790 & V_979 ) &&
F_28 ( V_53 , V_980 ,
V_960 -> V_981 ) ) ||
( ( V_960 -> V_790 & V_982 ) &&
F_56 ( V_53 , V_983 ,
V_960 -> V_984 ) ) )
goto V_61;
F_48 ( V_53 , V_961 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_182 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_959 V_960 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_957 [ V_581 ] ;
T_2 V_958 [ V_581 ] ;
int V_985 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_345 -> V_986 ) {
V_35 = - V_534 ;
goto V_873;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_534 ;
goto V_873;
}
while ( 1 ) {
V_35 = F_183 ( V_7 , V_17 -> V_19 , V_985 , V_957 ,
V_958 , & V_960 ) ;
if ( V_35 == - V_647 )
break;
if ( V_35 )
goto V_873;
if ( F_181 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_17 -> V_19 , V_957 , V_958 ,
& V_960 ) < 0 )
goto V_591;
V_985 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_985 ;
V_35 = V_32 -> V_47 ;
V_873:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_184 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_959 V_960 ;
struct V_31 * V_53 ;
T_2 * V_957 = NULL ;
T_2 V_958 [ V_581 ] ;
memset ( & V_960 , 0 , sizeof( V_960 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_957 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_987 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
V_35 = F_185 ( V_7 , V_533 , V_957 , V_958 , & V_960 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_181 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_533 , V_957 , V_958 , & V_960 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_186 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_957 = NULL ;
T_2 * V_958 = NULL ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_963 ] )
return - V_16 ;
V_957 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_958 = F_23 ( V_30 -> V_5 [ V_963 ] ) ;
if ( ! V_7 -> V_345 -> V_988 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
return F_187 ( V_7 , V_533 , V_957 , V_958 ) ;
}
static int F_188 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_957 = NULL ;
T_2 * V_958 = NULL ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_963 ] )
return - V_16 ;
V_957 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_958 = F_23 ( V_30 -> V_5 [ V_963 ] ) ;
if ( ! V_7 -> V_345 -> V_373 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
return F_189 ( V_7 , V_533 , V_957 , V_958 ) ;
}
static int F_190 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_957 = NULL ;
if ( V_30 -> V_5 [ V_541 ] )
V_957 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_989 )
return - V_534 ;
return F_191 ( V_7 , V_533 , V_957 ) ;
}
static int F_192 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int V_35 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_959 V_960 ;
struct V_31 * V_53 ;
T_2 * V_957 = NULL ;
T_2 V_990 [ V_581 ] ;
memset ( & V_960 , 0 , sizeof( V_960 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_957 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! V_7 -> V_345 -> V_991 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_145 )
return - V_534 ;
V_35 = F_193 ( V_7 , V_533 , V_957 , V_990 , & V_960 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_181 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_533 , V_957 , V_990 , & V_960 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_194 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_959 V_960 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_957 [ V_581 ] ;
T_2 V_990 [ V_581 ] ;
int V_985 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_345 -> V_992 ) {
V_35 = - V_534 ;
goto V_873;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_534 ;
goto V_873;
}
while ( 1 ) {
V_35 = F_195 ( V_7 , V_17 -> V_19 , V_985 , V_957 ,
V_990 , & V_960 ) ;
if ( V_35 == - V_647 )
break;
if ( V_35 )
goto V_873;
if ( F_181 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_17 -> V_19 , V_957 , V_990 ,
& V_960 ) < 0 )
goto V_591;
V_985 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_985 ;
V_35 = V_32 -> V_47 ;
V_873:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_196 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_993 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_994 = - 1 ;
V_137 . V_995 = - 1 ;
V_137 . V_996 = - 1 ;
V_137 . V_997 = - 1 ;
V_137 . V_998 = - 1 ;
V_137 . V_720 = - 1 ;
V_137 . V_723 = - 1 ;
if ( V_30 -> V_5 [ V_999 ] )
V_137 . V_994 =
F_34 ( V_30 -> V_5 [ V_999 ] ) ;
if ( V_30 -> V_5 [ V_1000 ] )
V_137 . V_995 =
F_34 ( V_30 -> V_5 [ V_1000 ] ) ;
if ( V_30 -> V_5 [ V_1001 ] )
V_137 . V_996 =
F_34 ( V_30 -> V_5 [ V_1001 ] ) ;
if ( V_30 -> V_5 [ V_1002 ] ) {
V_137 . V_1003 =
F_23 ( V_30 -> V_5 [ V_1002 ] ) ;
V_137 . V_1004 =
F_24 ( V_30 -> V_5 [ V_1002 ] ) ;
}
if ( V_30 -> V_5 [ V_1005 ] )
V_137 . V_997 = ! ! F_34 ( V_30 -> V_5 [ V_1005 ] ) ;
if ( V_30 -> V_5 [ V_1006 ] )
V_137 . V_998 =
F_78 ( V_30 -> V_5 [ V_1006 ] ) ;
if ( V_30 -> V_5 [ V_719 ] ) {
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_720 =
F_197 ( V_30 -> V_5 [ V_719 ] ) ;
if ( V_137 . V_720 < 0 )
return - V_16 ;
if ( V_137 . V_720 != 0 &&
! ( V_7 -> V_18 . V_291 & V_721 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_722 ] ) {
T_2 V_24 ;
if ( V_533 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_722 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_723 = V_24 ;
if ( V_137 . V_723 &&
! ( V_7 -> V_18 . V_291 & V_724 ) )
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
struct V_1007 * V_1008 )
{
struct V_1009 * V_1010 = & V_1008 -> V_1010 ;
struct V_1011 * V_1012 = & V_1008 -> V_1012 ;
if ( ! V_95 [ V_1013 ] )
return - V_16 ;
if ( ! V_95 [ V_1014 ] )
return - V_16 ;
if ( ! V_95 [ V_1015 ] )
return - V_16 ;
if ( ! V_95 [ V_1016 ] )
return - V_16 ;
if ( ! V_95 [ V_1017 ] )
return - V_16 ;
V_1008 -> V_51 = F_4 ( V_95 [ V_1013 ] ) ;
V_1010 -> V_1018 =
F_4 ( V_95 [ V_1014 ] ) ;
V_1010 -> V_1019 =
F_4 ( V_95 [ V_1015 ] ) ;
V_1010 -> V_1020 =
F_4 ( V_95 [ V_1016 ] ) ;
V_1012 -> V_1021 =
F_4 ( V_95 [ V_1017 ] ) ;
if ( V_95 [ V_1022 ] )
V_1012 -> V_1023 =
F_4 ( V_95 [ V_1022 ] ) ;
if ( V_95 [ V_1024 ] )
V_1008 -> V_74 =
F_4 ( V_95 [ V_1024 ] ) ;
return 0 ;
}
static int F_200 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
bool V_1025 ;
enum V_1026 V_1027 ;
V_22 V_624 ;
if ( F_201 ( ! F_202 ( V_1028 ) ) )
return - V_1029 ;
if ( V_30 -> V_5 [ V_1030 ] )
V_1027 =
F_4 ( V_30 -> V_5 [ V_1030 ] ) ;
else
V_1027 = V_1031 ;
switch ( V_1027 ) {
case V_1031 :
case V_1032 :
if ( ! V_30 -> V_5 [ V_1033 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1033 ] ) ;
return F_203 ( V_138 , V_1027 ) ;
case V_1034 :
if ( V_30 -> V_5 [ V_623 ] ) {
V_624 = V_30 -> V_498 ;
V_1025 = ! ! V_30 -> V_5 [ V_1035 ] ;
} else {
V_624 = 0 ;
V_1025 = true ;
}
return F_204 ( V_1025 , V_624 ) ;
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
struct V_1036 V_1037 ;
int V_35 = 0 ;
void * V_283 ;
struct V_4 * V_961 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_1038 )
return - V_534 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1039 )
memcpy ( & V_1037 , & V_1040 , sizeof( V_1037 ) ) ;
else
V_35 = F_206 ( V_7 , V_533 , & V_1037 ) ;
F_114 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1041 ) ;
if ( ! V_283 )
goto V_591;
V_961 = F_47 ( V_53 , V_1042 ) ;
if ( ! V_961 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_55 ( V_53 , V_1043 ,
V_1037 . V_1044 ) ||
F_55 ( V_53 , V_1045 ,
V_1037 . V_1046 ) ||
F_55 ( V_53 , V_1047 ,
V_1037 . V_1048 ) ||
F_55 ( V_53 , V_1049 ,
V_1037 . V_1050 ) ||
F_56 ( V_53 , V_1051 ,
V_1037 . V_1052 ) ||
F_56 ( V_53 , V_1053 ,
V_1037 . V_1054 ) ||
F_56 ( V_53 , V_1055 ,
V_1037 . V_1056 ) ||
F_56 ( V_53 , V_1057 ,
V_1037 . V_1058 ) ||
F_28 ( V_53 , V_1059 ,
V_1037 . V_1060 ) ||
F_56 ( V_53 , V_1061 ,
V_1037 . V_1062 ) ||
F_28 ( V_53 , V_1063 ,
V_1037 . V_1064 ) ||
F_55 ( V_53 , V_1065 ,
V_1037 . V_1066 ) ||
F_28 ( V_53 , V_1067 ,
V_1037 . V_1068 ) ||
F_55 ( V_53 , V_1069 ,
V_1037 . V_1070 ) ||
F_55 ( V_53 , V_1071 ,
V_1037 . V_1072 ) ||
F_55 ( V_53 , V_1073 ,
V_1037 . V_1074 ) ||
F_56 ( V_53 , V_1075 ,
V_1037 . V_1076 ) ||
F_55 ( V_53 , V_1077 ,
V_1037 . V_1078 ) ||
F_56 ( V_53 , V_1079 ,
V_1037 . V_1080 ) ||
F_56 ( V_53 , V_1081 ,
V_1037 . V_1082 ) ||
F_28 ( V_53 , V_1083 ,
V_1037 . V_1084 ) ||
F_28 ( V_53 , V_1085 ,
V_1037 . V_998 ) ||
F_28 ( V_53 , V_1086 ,
V_1037 . V_1087 ) ||
F_55 ( V_53 , V_1088 ,
V_1037 . V_1089 ) ||
F_55 ( V_53 , V_1090 ,
V_1037 . V_1091 ) ||
F_28 ( V_53 , V_1092 ,
V_1037 . V_1093 ) ||
F_55 ( V_53 , V_1094 ,
V_1037 . V_1095 ) ||
F_28 ( V_53 , V_1096 ,
V_1037 . V_1097 ) )
goto V_61;
F_48 ( V_53 , V_961 ) ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_591:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_207 ( struct V_29 * V_30 ,
struct V_1036 * V_1098 ,
V_22 * V_1099 )
{
struct V_4 * V_95 [ V_1100 + 1 ] ;
V_22 V_739 = 0 ;
#define F_208 ( V_95 , V_1098 , T_8 , T_9 , V_174 , V_739 , V_45 , T_10 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1042 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1100 ,
V_30 -> V_5 [ V_1042 ] ,
V_1101 ) )
return - V_16 ;
F_113 ( V_1100 > 32 ) ;
F_208 ( V_95 , V_1098 , V_1044 , 1 , 255 ,
V_739 , V_1043 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1046 , 1 , 255 ,
V_739 , V_1045 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1048 , 1 , 255 ,
V_739 , V_1047 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1050 , 0 , 255 ,
V_739 , V_1049 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1052 , 0 , 16 ,
V_739 , V_1051 ,
F_34 ) ;
F_208 ( V_95 , V_1098 , V_1054 , 1 , 255 ,
V_739 , V_1053 , F_34 ) ;
F_208 ( V_95 , V_1098 , V_1056 , 1 , 255 ,
V_739 , V_1055 ,
F_34 ) ;
F_208 ( V_95 , V_1098 , V_1058 , 0 , 1 ,
V_739 , V_1057 ,
F_34 ) ;
F_208 ( V_95 , V_1098 , V_1060 ,
1 , 255 , V_739 ,
V_1059 ,
F_4 ) ;
F_208 ( V_95 , V_1098 , V_1062 , 0 , 255 ,
V_739 , V_1061 ,
F_34 ) ;
F_208 ( V_95 , V_1098 , V_1064 , 1 , 65535 ,
V_739 , V_1063 ,
F_4 ) ;
F_208 ( V_95 , V_1098 , V_1066 , 1 , 65535 ,
V_739 , V_1065 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1068 ,
1 , 65535 , V_739 ,
V_1067 ,
F_4 ) ;
F_208 ( V_95 , V_1098 , V_1070 ,
1 , 65535 , V_739 ,
V_1069 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1072 ,
1 , 65535 , V_739 ,
V_1071 ,
F_78 ) ;
F_208 ( V_95 , V_1098 ,
V_1074 ,
1 , 65535 , V_739 ,
V_1073 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1076 , 0 , 4 ,
V_739 , V_1075 ,
F_34 ) ;
F_208 ( V_95 , V_1098 , V_1078 , 1 , 65535 ,
V_739 , V_1077 ,
F_78 ) ;
F_208 ( V_95 , V_1098 ,
V_1080 , 0 , 1 ,
V_739 , V_1079 ,
F_34 ) ;
F_208 ( V_95 , V_1098 , V_1082 , 0 , 1 ,
V_739 , V_1081 ,
F_34 ) ;
F_208 ( V_95 , V_1098 , V_1084 , - 255 , 0 ,
V_739 , V_1083 ,
V_1102 ) ;
F_208 ( V_95 , V_1098 , V_998 , 0 , 16 ,
V_739 , V_1085 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1087 ,
1 , 65535 , V_739 ,
V_1086 ,
F_4 ) ;
F_208 ( V_95 , V_1098 , V_1089 , 1 , 65535 ,
V_739 , V_1088 ,
F_78 ) ;
F_208 ( V_95 , V_1098 ,
V_1091 ,
1 , 65535 , V_739 ,
V_1090 ,
F_78 ) ;
F_208 ( V_95 , V_1098 , V_1093 ,
V_1103 ,
V_941 ,
V_739 , V_1092 ,
F_4 ) ;
F_208 ( V_95 , V_1098 , V_1095 ,
0 , 65535 , V_739 ,
V_1094 , F_78 ) ;
F_208 ( V_95 , V_1098 , V_1097 , 0 , 0xffffffff ,
V_739 , V_1096 ,
F_4 ) ;
if ( V_1099 )
* V_1099 = V_739 ;
return 0 ;
#undef F_208
}
static int F_209 ( struct V_29 * V_30 ,
struct V_1104 * V_1105 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_4 * V_95 [ V_1106 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1107 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1106 ,
V_30 -> V_5 [ V_1107 ] ,
V_1108 ) )
return - V_16 ;
if ( V_95 [ V_1109 ] )
V_1105 -> V_1110 =
( F_34 ( V_95 [ V_1109 ] ) ) ?
V_1111 :
V_1112 ;
if ( V_95 [ V_1113 ] )
V_1105 -> V_1114 =
( F_34 ( V_95 [ V_1113 ] ) ) ?
V_1115 :
V_1116 ;
if ( V_95 [ V_1117 ] )
V_1105 -> V_1118 =
( F_34 ( V_95 [ V_1117 ] ) ) ?
V_1119 :
V_1120 ;
if ( V_95 [ V_1121 ] ) {
struct V_4 * V_1122 =
V_95 [ V_1121 ] ;
if ( ! F_22 ( V_1122 ) )
return - V_16 ;
V_1105 -> V_1123 = F_23 ( V_1122 ) ;
V_1105 -> V_1124 = F_24 ( V_1122 ) ;
}
if ( V_95 [ V_1125 ] &&
! ( V_7 -> V_18 . V_291 & V_1126 ) )
return - V_16 ;
V_1105 -> V_1127 = F_210 ( V_95 [ V_1125 ] ) ;
V_1105 -> V_1128 = F_210 ( V_95 [ V_1129 ] ) ;
V_1105 -> V_1130 = F_210 ( V_95 [ V_1131 ] ) ;
if ( V_1105 -> V_1130 )
V_1105 -> V_1127 = true ;
if ( V_95 [ V_1132 ] ) {
if ( ! V_1105 -> V_1127 )
return - V_16 ;
V_1105 -> V_1133 =
F_34 ( V_95 [ V_1132 ] ) ;
}
return 0 ;
}
static int F_211 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_1036 V_1098 ;
V_22 V_739 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_375 )
return - V_534 ;
V_35 = F_207 ( V_30 , & V_1098 , & V_739 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1039 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_212 ( V_7 , V_533 , V_739 , & V_1098 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_213 ( const struct V_1134 * V_1135 ,
struct V_31 * V_53 )
{
struct V_4 * V_1136 ;
unsigned int V_159 ;
if ( F_60 ( V_53 , V_1033 , V_1135 -> V_1137 ) ||
( V_1135 -> V_1138 &&
F_56 ( V_53 , V_1139 , V_1135 -> V_1138 ) ) )
goto V_61;
V_1136 = F_47 ( V_53 , V_1140 ) ;
if ( ! V_1136 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1135 -> V_1141 ; V_159 ++ ) {
struct V_4 * V_1142 ;
const struct V_1007 * V_1008 ;
const struct V_1009 * V_1010 ;
const struct V_1011 * V_1012 ;
unsigned int V_1020 ;
V_1008 = & V_1135 -> V_1143 [ V_159 ] ;
V_1010 = & V_1008 -> V_1010 ;
V_1012 = & V_1008 -> V_1012 ;
V_1142 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1142 )
goto V_61;
V_1020 = V_1010 -> V_1020 ;
if ( ! V_1020 )
V_1020 = F_214 ( V_1135 ,
V_1008 ) ;
if ( F_28 ( V_53 , V_1013 ,
V_1008 -> V_51 ) ||
F_28 ( V_53 , V_1014 ,
V_1010 -> V_1018 ) ||
F_28 ( V_53 , V_1015 ,
V_1010 -> V_1019 ) ||
F_28 ( V_53 , V_1016 ,
V_1020 ) ||
F_28 ( V_53 , V_1022 ,
V_1012 -> V_1023 ) ||
F_28 ( V_53 , V_1017 ,
V_1012 -> V_1021 ) ||
F_28 ( V_53 , V_1024 ,
V_1008 -> V_74 ) )
goto V_61;
F_48 ( V_53 , V_1142 ) ;
}
F_48 ( V_53 , V_1136 ) ;
return 0 ;
V_61:
return - V_489 ;
}
static int F_215 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1134 * V_1135 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1144 ) ;
if ( ! V_283 )
goto V_1145;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1146 ;
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1146 = V_18 -> V_484 &
V_485 ;
V_1135 = F_216 ( V_18 ) ;
if ( F_59 ( ! V_1135 && V_1146 ) ) {
F_75 ( V_53 ) ;
return - V_16 ;
}
if ( V_1135 &&
F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
}
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1030 ,
V_1032 ) )
goto V_61;
F_219 () ;
if ( ! V_1135 )
V_1135 = F_220 ( V_1028 ) ;
if ( F_213 ( V_1135 , V_53 ) )
goto V_1147;
F_221 () ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1147:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_1145:
F_75 ( V_53 ) ;
return - V_489 ;
}
static int F_222 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 , struct V_18 * V_18 ,
const struct V_1134 * V_1135 )
{
void * V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1144 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_213 ( V_1135 , V_53 ) )
goto V_61;
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1030 ,
V_1032 ) )
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
const struct V_1134 * V_1135 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1148 , V_493 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1028 && V_493 == 0 ) {
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_494 ,
V_495 , NULL ,
F_225 ( V_1028 ) ) ;
if ( V_35 < 0 )
goto V_873;
}
V_1148 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1135 = F_216 ( & V_7 -> V_18 ) ;
if ( ! V_1135 )
continue;
if ( ++ V_1148 <= V_493 )
continue;
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_494 ,
V_495 , & V_7 -> V_18 , V_1135 ) ;
if ( V_35 < 0 ) {
V_1148 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1148 ;
V_35 = V_32 -> V_47 ;
V_873:
F_20 () ;
return V_35 ;
}
static int F_226 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1149 + 1 ] ;
struct V_4 * V_1142 ;
char * V_1137 ;
int V_1150 , V_1151 ;
V_22 V_1152 = 0 , V_1153 = 0 , V_1154 ;
enum V_1155 V_1138 = V_1156 ;
struct V_1134 * V_1157 ;
if ( ! V_30 -> V_5 [ V_1033 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1140 ] )
return - V_16 ;
V_1137 = F_23 ( V_30 -> V_5 [ V_1033 ] ) ;
if ( V_30 -> V_5 [ V_1139 ] )
V_1138 = F_34 ( V_30 -> V_5 [ V_1139 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1152 ++ ;
if ( V_1152 > V_1158 )
return - V_16 ;
}
if ( ! F_227 ( V_1137 ) )
return - V_16 ;
V_1154 = sizeof( struct V_1134 ) +
V_1152 * sizeof( struct V_1007 ) ;
V_1157 = F_38 ( V_1154 , V_135 ) ;
if ( ! V_1157 )
return - V_136 ;
V_1157 -> V_1141 = V_1152 ;
V_1157 -> V_1137 [ 0 ] = V_1137 [ 0 ] ;
V_1157 -> V_1137 [ 1 ] = V_1137 [ 1 ] ;
if ( F_228 ( V_1138 ) )
V_1157 -> V_1138 = V_1138 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1151 = F_96 ( V_95 , V_1149 ,
F_23 ( V_1142 ) , F_24 ( V_1142 ) ,
V_1159 ) ;
if ( V_1151 )
goto V_1160;
V_1151 = F_199 ( V_95 , & V_1157 -> V_1143 [ V_1153 ] ) ;
if ( V_1151 )
goto V_1160;
V_1153 ++ ;
if ( V_1153 > V_1158 ) {
V_1151 = - V_16 ;
goto V_1160;
}
}
V_1151 = F_229 ( V_1157 , V_1161 ) ;
V_1157 = NULL ;
V_1160:
F_41 ( V_1157 ) ;
return V_1151 ;
}
static int F_230 ( struct V_4 * V_1162 )
{
struct V_4 * V_1163 , * V_1164 ;
int V_360 = 0 , V_1165 , V_1166 ;
F_39 (attr1, freqs, tmp1) {
V_360 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1163 != V_1164 &&
F_4 ( V_1163 ) == F_4 ( V_1164 ) )
return 0 ;
}
return V_360 ;
}
static int F_231 ( struct V_4 * * V_5 ,
T_2 * V_641 , T_2 * V_1167 )
{
int V_159 ;
if ( ! V_5 [ V_541 ] && ! V_5 [ V_1168 ] ) {
F_232 ( V_641 ) ;
F_232 ( V_1167 ) ;
V_641 [ 0 ] = 0x2 ;
V_1167 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_541 ] || ! V_5 [ V_1168 ] )
return - V_16 ;
memcpy ( V_641 , F_23 ( V_5 [ V_541 ] ) , V_581 ) ;
memcpy ( V_1167 , F_23 ( V_5 [ V_1168 ] ) , V_581 ) ;
if ( ! F_233 ( V_1167 ) ||
F_233 ( V_641 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_581 ; V_159 ++ )
V_641 [ V_159 ] &= V_1167 [ V_159 ] ;
return 0 ;
}
static int F_234 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
struct V_1169 * V_1170 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1171 = 0 , V_360 , V_159 ;
T_11 V_1124 ;
if ( ! F_22 ( V_30 -> V_5 [ V_675 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_345 -> V_1172 )
return - V_534 ;
if ( V_7 -> V_1173 || V_7 -> V_1174 ) {
V_35 = - V_538 ;
goto V_1175;
}
if ( V_30 -> V_5 [ V_1176 ] ) {
V_360 = F_230 (
V_30 -> V_5 [ V_1176 ] ) ;
if ( ! V_360 ) {
V_35 = - V_16 ;
goto V_1175;
}
} else {
V_360 = F_235 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1177 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1171 ++ ;
if ( V_1171 > V_18 -> V_309 ) {
V_35 = - V_16 ;
goto V_1175;
}
if ( V_30 -> V_5 [ V_675 ] )
V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
else
V_1124 = 0 ;
if ( V_1124 > V_18 -> V_313 ) {
V_35 = - V_16 ;
goto V_1175;
}
V_1170 = F_38 ( sizeof( * V_1170 )
+ sizeof( * V_1170 -> V_1178 ) * V_1171
+ sizeof( * V_1170 -> V_361 ) * V_360
+ V_1124 , V_135 ) ;
if ( ! V_1170 ) {
V_35 = - V_136 ;
goto V_1175;
}
if ( V_1171 )
V_1170 -> V_1178 = ( void * ) & V_1170 -> V_361 [ V_360 ] ;
V_1170 -> V_1171 = V_1171 ;
if ( V_1124 ) {
if ( V_1171 )
V_1170 -> V_1123 = ( void * ) ( V_1170 -> V_1178 + V_1171 ) ;
else
V_1170 -> V_1123 = ( void * ) ( V_1170 -> V_361 + V_360 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1176 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1179;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1170 -> V_361 [ V_159 ] = V_55 ;
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
V_1170 -> V_361 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1179;
}
V_1170 -> V_360 = V_159 ;
V_159 = 0 ;
if ( V_1171 ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_610 ) {
V_35 = - V_16 ;
goto V_1179;
}
V_1170 -> V_1178 [ V_159 ] . V_584 = F_24 ( V_45 ) ;
memcpy ( V_1170 -> V_1178 [ V_159 ] . V_586 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_675 ] ) {
V_1170 -> V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
memcpy ( ( void * ) V_1170 -> V_1123 ,
F_23 ( V_30 -> V_5 [ V_675 ] ) ,
V_1170 -> V_1124 ) ;
}
for ( V_159 = 0 ; V_159 < V_356 ; V_159 ++ )
if ( V_18 -> V_357 [ V_159 ] )
V_1170 -> V_1180 [ V_159 ] =
( 1 << V_18 -> V_357 [ V_159 ] -> V_261 ) - 1 ;
if ( V_30 -> V_5 [ V_1181 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_289 V_290 = F_236 ( V_45 ) ;
if ( V_290 < 0 || V_290 >= V_356 ) {
V_35 = - V_16 ;
goto V_1179;
}
if ( ! V_18 -> V_357 [ V_290 ] )
continue;
V_35 = F_237 ( V_18 -> V_357 [ V_290 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1170 -> V_1180 [ V_290 ] ) ;
if ( V_35 )
goto V_1179;
}
}
if ( V_30 -> V_5 [ V_1182 ] ) {
V_1170 -> V_51 = F_4 (
V_30 -> V_5 [ V_1182 ] ) ;
if ( ( V_1170 -> V_51 & V_1183 ) &&
! ( V_18 -> V_291 & V_1184 ) ) {
V_35 = - V_534 ;
goto V_1179;
}
if ( V_1170 -> V_51 & V_1185 ) {
if ( ! ( V_18 -> V_291 &
V_1186 ) ) {
V_35 = - V_534 ;
goto V_1179;
}
if ( V_17 -> V_149 ) {
V_35 = - V_534 ;
goto V_1179;
}
V_35 = F_231 ( V_30 -> V_5 ,
V_1170 -> V_641 ,
V_1170 -> V_1167 ) ;
if ( V_35 )
goto V_1179;
}
}
V_1170 -> V_1187 =
F_210 ( V_30 -> V_5 [ V_1188 ] ) ;
V_1170 -> V_17 = V_17 ;
V_1170 -> V_18 = & V_7 -> V_18 ;
V_1170 -> V_1189 = V_1190 ;
V_7 -> V_1173 = V_1170 ;
V_35 = F_238 ( V_7 , V_1170 ) ;
if ( ! V_35 ) {
F_239 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_240 ( V_17 -> V_19 ) ;
} else {
V_1179:
V_7 -> V_1173 = NULL ;
F_41 ( V_1170 ) ;
}
V_1175:
return V_35 ;
}
static struct V_1191 *
F_241 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1191 * V_1170 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1171 = 0 , V_1192 = 0 , V_360 , V_159 ;
V_22 V_1193 ;
enum V_289 V_290 ;
T_11 V_1124 ;
struct V_4 * V_95 [ V_1194 + 1 ] ;
T_12 V_1195 = V_1196 ;
if ( ! F_22 ( V_5 [ V_675 ] ) )
return F_3 ( - V_16 ) ;
if ( ! V_5 [ V_1197 ] )
return F_3 ( - V_16 ) ;
V_1193 = F_4 ( V_5 [ V_1197 ] ) ;
if ( V_1193 == 0 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1176 ] ) {
V_360 = F_230 (
V_5 [ V_1176 ] ) ;
if ( ! V_360 )
return F_3 ( - V_16 ) ;
} else {
V_360 = F_235 ( V_18 ) ;
}
if ( V_5 [ V_1177 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1171 ++ ;
if ( V_1171 > V_18 -> V_311 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1198 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1199 ;
V_35 = F_96 ( V_95 , V_1194 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1200 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1201 ] ) {
V_1192 ++ ;
continue;
}
V_1199 = V_95 [ V_1202 ] ;
if ( V_1199 )
V_1195 = V_1102 ( V_1199 ) ;
}
}
if ( ! V_1192 && V_1195 != V_1196 )
V_1192 = 1 ;
if ( V_1192 > V_18 -> V_317 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_675 ] )
V_1124 = F_24 ( V_5 [ V_675 ] ) ;
else
V_1124 = 0 ;
if ( V_1124 > V_18 -> V_315 )
return F_3 ( - V_16 ) ;
V_1170 = F_38 ( sizeof( * V_1170 )
+ sizeof( * V_1170 -> V_1178 ) * V_1171
+ sizeof( * V_1170 -> V_1203 ) * V_1192
+ sizeof( * V_1170 -> V_361 ) * V_360
+ V_1124 , V_135 ) ;
if ( ! V_1170 )
return F_3 ( - V_136 ) ;
if ( V_1171 )
V_1170 -> V_1178 = ( void * ) & V_1170 -> V_361 [ V_360 ] ;
V_1170 -> V_1171 = V_1171 ;
if ( V_1124 ) {
if ( V_1171 )
V_1170 -> V_1123 = ( void * ) ( V_1170 -> V_1178 + V_1171 ) ;
else
V_1170 -> V_1123 = ( void * ) ( V_1170 -> V_361 + V_360 ) ;
}
if ( V_1192 ) {
if ( V_1170 -> V_1123 )
V_1170 -> V_1203 = ( void * ) ( V_1170 -> V_1123 + V_1124 ) ;
else if ( V_1171 )
V_1170 -> V_1203 =
( void * ) ( V_1170 -> V_1178 + V_1171 ) ;
else
V_1170 -> V_1203 =
( void * ) ( V_1170 -> V_361 + V_360 ) ;
}
V_1170 -> V_1192 = V_1192 ;
V_159 = 0 ;
if ( V_5 [ V_1176 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1179;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1170 -> V_361 [ V_159 ] = V_55 ;
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
V_1170 -> V_361 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1179;
}
V_1170 -> V_360 = V_159 ;
V_159 = 0 ;
if ( V_1171 ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_610 ) {
V_35 = - V_16 ;
goto V_1179;
}
V_1170 -> V_1178 [ V_159 ] . V_584 = F_24 ( V_45 ) ;
memcpy ( V_1170 -> V_1178 [ V_159 ] . V_586 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1198 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_586 , * V_1199 ;
V_35 = F_96 ( V_95 , V_1194 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1200 ) ;
if ( V_35 )
goto V_1179;
V_586 = V_95 [ V_1201 ] ;
if ( V_586 ) {
if ( F_59 ( V_159 >= V_1192 ) ) {
V_35 = - V_16 ;
goto V_1179;
}
if ( F_24 ( V_586 ) > V_610 ) {
V_35 = - V_16 ;
goto V_1179;
}
memcpy ( V_1170 -> V_1203 [ V_159 ] . V_586 . V_586 ,
F_23 ( V_586 ) , F_24 ( V_586 ) ) ;
V_1170 -> V_1203 [ V_159 ] . V_586 . V_584 =
F_24 ( V_586 ) ;
V_1170 -> V_1203 [ V_159 ] . V_1204 =
V_1195 ;
V_1199 = V_95 [ V_1202 ] ;
if ( V_1199 )
V_1170 -> V_1203 [ V_159 ] . V_1204 =
V_1102 ( V_1199 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1192 )
V_1170 -> V_1203 [ 0 ] . V_1204 = V_1195 ;
V_1170 -> V_1205 = V_1206 ;
for ( V_159 = 0 ; V_159 < V_1192 ; V_159 ++ )
V_1170 -> V_1205 =
T_9 ( V_1170 -> V_1203 [ V_159 ] . V_1204 ,
V_1170 -> V_1205 ) ;
} else {
V_1170 -> V_1205 = V_1196 ;
}
if ( V_1124 ) {
V_1170 -> V_1124 = V_1124 ;
memcpy ( ( void * ) V_1170 -> V_1123 ,
F_23 ( V_5 [ V_675 ] ) ,
V_1170 -> V_1124 ) ;
}
if ( V_5 [ V_1182 ] ) {
V_1170 -> V_51 = F_4 (
V_5 [ V_1182 ] ) ;
if ( ( V_1170 -> V_51 & V_1183 ) &&
! ( V_18 -> V_291 & V_1184 ) ) {
V_35 = - V_534 ;
goto V_1179;
}
if ( V_1170 -> V_51 & V_1185 ) {
V_22 V_1207 = V_1208 ;
if ( ! V_17 )
V_1207 = V_1209 ;
if ( ! ( V_18 -> V_291 & V_1207 ) ) {
V_35 = - V_534 ;
goto V_1179;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_534 ;
goto V_1179;
}
V_35 = F_231 ( V_5 , V_1170 -> V_641 ,
V_1170 -> V_1167 ) ;
if ( V_35 )
goto V_1179;
}
}
if ( V_5 [ V_1210 ] )
V_1170 -> V_1211 =
F_4 ( V_5 [ V_1210 ] ) ;
V_1170 -> V_1193 = V_1193 ;
V_1170 -> V_1189 = V_1190 ;
return V_1170 ;
V_1179:
F_41 ( V_1170 ) ;
return F_3 ( V_35 ) ;
}
static int F_242 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_1191 * V_1212 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_416 ) ||
! V_7 -> V_345 -> V_417 )
return - V_534 ;
if ( V_7 -> V_1212 )
return - V_1029 ;
V_1212 = F_241 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_243 ( V_1212 ) ;
if ( V_35 )
goto V_873;
V_35 = F_244 ( V_7 , V_533 , V_1212 ) ;
if ( V_35 )
goto V_1179;
V_1212 -> V_533 = V_533 ;
V_1212 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_623 ] )
V_1212 -> V_624 = V_30 -> V_498 ;
F_245 ( V_7 -> V_1212 , V_1212 ) ;
F_246 ( V_7 , V_533 ,
V_1213 ) ;
return 0 ;
V_1179:
F_41 ( V_1212 ) ;
V_873:
return V_35 ;
}
static int F_247 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_416 ) ||
! V_7 -> V_345 -> V_1214 )
return - V_534 ;
return F_248 ( V_7 , false ) ;
}
static int F_249 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_513 V_514 ;
enum V_1155 V_1138 ;
unsigned int V_1215 ;
int V_35 ;
V_1138 = F_250 ( V_17 -> V_18 ) ;
if ( V_1138 == V_1156 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
if ( F_251 ( V_533 ) )
return - V_538 ;
if ( V_17 -> V_1216 )
return - V_538 ;
V_35 = F_252 ( V_17 -> V_18 , & V_514 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_253 ( V_17 -> V_18 , & V_514 ) )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_1217 )
return - V_534 ;
V_1215 = F_254 ( & V_7 -> V_18 , & V_514 ) ;
if ( F_59 ( ! V_1215 ) )
V_1215 = V_1218 ;
V_35 = V_7 -> V_345 -> V_1217 ( & V_7 -> V_18 , V_533 , & V_514 ,
V_1215 ) ;
if ( ! V_35 ) {
V_17 -> V_514 = V_514 ;
V_17 -> V_1216 = true ;
V_17 -> V_1219 = V_1190 ;
V_17 -> V_1215 = V_1215 ;
}
return V_35 ;
}
static int F_255 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_1220 V_137 ;
static struct V_4 * V_1221 [ V_1222 + 1 ] ;
int V_35 ;
bool V_1223 = false ;
int V_47 , V_159 ;
V_22 V_1224 ;
if ( ! V_7 -> V_345 -> V_436 ||
! ( V_7 -> V_18 . V_51 & V_435 ) )
return - V_534 ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1223 = true ;
if ( ! V_17 -> V_535 )
return - V_1225 ;
break;
case V_146 :
if ( ! V_17 -> V_584 )
return - V_1225 ;
break;
case V_145 :
if ( ! V_17 -> V_1039 )
return - V_1225 ;
break;
default:
return - V_534 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_516 ] ||
! V_30 -> V_5 [ V_1226 ] )
return - V_16 ;
if ( V_1223 && ! V_30 -> V_5 [ V_1227 ] )
return - V_16 ;
V_1224 = F_4 ( V_30 -> V_5 [ V_1226 ] ) ;
if ( V_1224 > 255 )
return - V_16 ;
V_137 . V_1228 = V_1224 ;
if ( ! V_1223 )
goto V_1229;
V_35 = F_145 ( V_30 -> V_5 , & V_137 . V_1230 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1221 , V_1222 ,
V_30 -> V_5 [ V_1227 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_145 ( V_1221 , & V_137 . V_1231 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1221 [ V_1232 ] )
return - V_16 ;
V_47 = F_24 ( V_1221 [ V_1232 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1233 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_483 &&
( V_137 . V_1233 >
V_7 -> V_18 . V_483 ) )
return - V_16 ;
V_137 . V_1234 =
F_23 ( V_1221 [ V_1232 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1233 ; V_159 ++ ) {
T_3 V_1235 = V_137 . V_1234 [ V_159 ] ;
if ( V_1235 >= V_137 . V_1231 . V_682 )
return - V_16 ;
if ( V_137 . V_1231 . V_681 [ V_1235 ] != V_137 . V_1228 )
return - V_16 ;
}
if ( V_1221 [ V_1236 ] ) {
V_47 = F_24 ( V_1221 [ V_1236 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1237 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_483 &&
( V_137 . V_1233 >
V_7 -> V_18 . V_483 ) )
return - V_16 ;
V_137 . V_1238 =
F_23 ( V_1221 [ V_1236 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1237 ; V_159 ++ ) {
T_3 V_1235 = V_137 . V_1238 [ V_159 ] ;
if ( V_1235 >= V_137 . V_1231 . V_691 )
return - V_16 ;
if ( V_137 . V_1231 . V_690 [ V_1235 ] !=
V_137 . V_1228 )
return - V_16 ;
}
}
V_1229:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_514 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_514 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_252 ( V_17 -> V_18 ,
& V_137 . V_514 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_137 . V_1239 = true ;
if ( V_30 -> V_5 [ V_1240 ] )
V_137 . V_1241 = true ;
F_112 ( V_17 ) ;
V_35 = F_256 ( V_7 , V_533 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_257 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1242 * V_1243 )
{
struct V_1244 * V_349 = & V_1243 -> V_1245 ;
const struct V_1246 * V_1247 ;
void * V_283 ;
struct V_4 * V_1248 ;
F_43 ( V_17 ) ;
V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1249 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_28 ( V_53 , V_293 , V_7 -> V_1250 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
V_1248 = F_47 ( V_53 , V_1251 ) ;
if ( ! V_1248 )
goto V_61;
if ( ( ! F_258 ( V_349 -> V_540 ) &&
F_51 ( V_53 , V_1252 , V_581 , V_349 -> V_540 ) ) )
goto V_61;
F_219 () ;
if ( F_202 ( V_349 -> V_685 ) &&
F_29 ( V_53 , V_1253 ) )
goto V_1254;
V_1247 = F_220 ( V_349 -> V_1247 ) ;
if ( V_1247 ) {
if ( F_104 ( V_53 , V_1255 , V_1247 -> V_1256 ) )
goto V_1254;
if ( V_1247 -> V_47 && F_51 ( V_53 , V_1257 ,
V_1247 -> V_47 , V_1247 -> V_138 ) )
goto V_1254;
}
V_1247 = F_220 ( V_349 -> V_683 ) ;
if ( V_1247 && V_1247 -> V_1258 ) {
if ( F_104 ( V_53 , V_1259 , V_1247 -> V_1256 ) )
goto V_1254;
if ( V_1247 -> V_47 && F_51 ( V_53 , V_1260 ,
V_1247 -> V_47 , V_1247 -> V_138 ) )
goto V_1254;
}
F_221 () ;
if ( V_349 -> V_535 &&
F_55 ( V_53 , V_1261 , V_349 -> V_535 ) )
goto V_61;
if ( F_55 ( V_53 , V_1262 , V_349 -> V_929 ) ||
F_28 ( V_53 , V_1263 , V_349 -> V_1264 -> V_60 ) ||
F_28 ( V_53 , V_1265 , V_349 -> V_1266 ) ||
F_28 ( V_53 , V_1267 ,
F_259 ( V_1190 - V_1243 -> V_1268 ) ) )
goto V_61;
switch ( V_7 -> V_18 . V_805 ) {
case V_806 :
if ( F_28 ( V_53 , V_1269 , V_349 -> signal ) )
goto V_61;
break;
case V_1270 :
if ( F_56 ( V_53 , V_1271 , V_349 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1243 == V_17 -> V_149 &&
F_28 ( V_53 , V_1272 ,
V_1273 ) )
goto V_61;
break;
case V_146 :
if ( V_1243 == V_17 -> V_149 &&
F_28 ( V_53 , V_1272 ,
V_1274 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1248 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_1254:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_260 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1242 * V_1172 ;
struct V_1 * V_17 ;
int V_493 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
F_261 ( & V_7 -> V_1275 ) ;
F_262 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1250 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_493 )
continue;
if ( F_257 ( V_32 , V_34 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_7 , V_17 , V_1172 ) < 0 ) {
V_105 -- ;
break;
}
}
F_263 ( & V_7 -> V_1275 ) ;
F_114 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_264 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_533 ,
bool V_1276 ,
struct V_1277 * V_1278 )
{
void * V_283 ;
struct V_4 * V_1279 ;
if ( ! V_1278 -> V_1264 && ! V_1276 )
return 0 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1280 ) ;
if ( ! V_283 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) )
goto V_61;
V_1279 = F_47 ( V_53 , V_1281 ) ;
if ( ! V_1279 )
goto V_61;
if ( V_1278 -> V_1264 &&
F_28 ( V_53 , V_1282 ,
V_1278 -> V_1264 -> V_60 ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1283 ) &&
F_56 ( V_53 , V_1284 , V_1278 -> V_1285 ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1286 ) &&
F_29 ( V_53 , V_1287 ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1288 ) &&
F_104 ( V_53 , V_1289 ,
V_1278 -> time ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1290 ) &&
F_104 ( V_53 , V_1291 ,
V_1278 -> V_1292 ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1293 ) &&
F_104 ( V_53 , V_1294 ,
V_1278 -> V_1295 ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1296 ) &&
F_104 ( V_53 , V_1297 ,
V_1278 -> V_1298 ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1299 ) &&
F_104 ( V_53 , V_1300 ,
V_1278 -> V_1301 ) )
goto V_61;
if ( ( V_1278 -> V_790 & V_1302 ) &&
F_104 ( V_53 , V_1303 ,
V_1278 -> V_1304 ) )
goto V_61;
F_48 ( V_53 , V_1279 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int F_265 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1277 V_1278 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1305 = V_34 -> args [ 2 ] ;
int V_349 ;
bool V_1306 ;
V_349 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_349 )
return V_349 ;
V_1306 = V_38 . V_40 [ V_1307 ] ;
if ( ! V_17 -> V_19 ) {
V_349 = - V_16 ;
goto V_873;
}
if ( ! V_7 -> V_345 -> V_1308 ) {
V_349 = - V_534 ;
goto V_873;
}
while ( 1 ) {
V_349 = F_266 ( V_7 , V_17 -> V_19 , V_1305 , & V_1278 ) ;
if ( V_349 == - V_647 )
break;
if ( V_349 )
goto V_873;
if ( V_1278 . V_1264 &&
V_1278 . V_1264 -> V_51 & V_62 ) {
V_1305 ++ ;
continue;
}
if ( F_264 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_17 -> V_19 , V_1306 , & V_1278 ) < 0 )
goto V_591;
V_1305 ++ ;
}
V_591:
V_34 -> args [ 2 ] = V_1305 ;
V_349 = V_32 -> V_47 ;
V_873:
F_21 ( V_7 ) ;
return V_349 ;
}
static bool F_267 ( V_22 V_1309 )
{
return ! ( V_1309 & ~ ( V_1310 |
V_1311 ) ) ;
}
static int F_268 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_540 , * V_586 , * V_1123 = NULL , * V_1312 = NULL ;
int V_35 , V_584 , V_1124 = 0 , V_1313 = 0 ;
enum V_693 V_694 ;
struct V_93 V_92 ;
bool V_1314 ;
if ( ! F_22 ( V_30 -> V_5 [ V_675 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_712 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_585 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_516 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_644 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1315 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1316 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_159 ;
bool V_1317 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_332 ; V_159 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_333 [ V_159 ] ) {
V_1317 = true ;
break;
}
}
if ( ! V_1317 )
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
if ( V_30 -> V_5 [ V_675 ] ) {
V_1123 = F_23 ( V_30 -> V_5 [ V_675 ] ) ;
V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
}
V_694 = F_4 ( V_30 -> V_5 [ V_712 ] ) ;
if ( ! F_147 ( V_7 , V_694 , V_696 ) )
return - V_16 ;
if ( V_694 == V_698 &&
! V_30 -> V_5 [ V_1318 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1318 ] ) {
if ( V_694 != V_698 )
return - V_16 ;
V_1312 = F_23 ( V_30 -> V_5 [ V_1318 ] ) ;
V_1313 = F_24 ( V_30 -> V_5 [ V_1318 ] ) ;
if ( V_1313 < 4 )
return - V_16 ;
}
V_1314 = ! ! V_30 -> V_5 [ V_1319 ] ;
if ( V_1314 )
return 0 ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_269 ( V_7 , V_533 , V_55 , V_694 , V_540 ,
V_586 , V_584 , V_1123 , V_1124 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1312 , V_1313 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_150 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1320 * V_1321 ,
int V_1322 )
{
memset ( V_1321 , 0 , sizeof( * V_1321 ) ) ;
V_1321 -> V_1323 = V_30 -> V_5 [ V_1324 ] ;
if ( V_30 -> V_5 [ V_337 ] ) {
T_3 V_1325 ;
V_1325 = F_78 (
V_30 -> V_5 [ V_337 ] ) ;
V_1321 -> V_1326 = F_270 ( V_1325 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_336 ) &&
V_1325 != V_1327 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1328 ] )
V_1321 -> V_1329 = true ;
} else
V_1321 -> V_1326 = F_270 ( V_1327 ) ;
if ( V_30 -> V_5 [ V_1330 ] ) {
void * V_138 ;
int V_47 , V_159 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1330 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1330 ] ) ;
V_1321 -> V_1331 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1321 -> V_1331 > V_1322 )
return - V_16 ;
memcpy ( V_1321 -> V_1332 , V_138 , V_47 ) ;
for ( V_159 = 0 ; V_159 < V_1321 -> V_1331 ; V_159 ++ )
if ( ! F_271 (
& V_7 -> V_18 ,
V_1321 -> V_1332 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1333 ] ) {
V_1321 -> V_1334 =
F_4 ( V_30 -> V_5 [ V_1333 ] ) ;
if ( ! F_271 ( & V_7 -> V_18 ,
V_1321 -> V_1334 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1335 ] ) {
V_1321 -> V_1309 =
F_4 ( V_30 -> V_5 [ V_1335 ] ) ;
if ( ! F_267 ( V_1321 -> V_1309 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1336 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1336 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1336 ] ) ;
V_1321 -> V_1337 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1321 -> V_1337 > V_1338 )
return - V_16 ;
memcpy ( V_1321 -> V_1339 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_272 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1340 V_1341 = {} ;
const T_2 * V_540 , * V_586 ;
int V_35 , V_584 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_675 ] ) )
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
if ( V_30 -> V_5 [ V_675 ] ) {
V_1341 . V_1123 = F_23 ( V_30 -> V_5 [ V_675 ] ) ;
V_1341 . V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
}
if ( V_30 -> V_5 [ V_1342 ] ) {
enum V_1343 V_1344 =
F_4 ( V_30 -> V_5 [ V_1342 ] ) ;
if ( V_1344 == V_1345 )
V_1341 . V_1346 = true ;
else if ( V_1344 != V_1347 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1348 ] )
V_1341 . V_1349 = F_23 ( V_30 -> V_5 [ V_1348 ] ) ;
if ( F_210 ( V_30 -> V_5 [ V_1350 ] ) )
V_1341 . V_51 |= V_1351 ;
if ( V_30 -> V_5 [ V_459 ] )
memcpy ( & V_1341 . V_1352 ,
F_23 ( V_30 -> V_5 [ V_459 ] ) ,
sizeof( V_1341 . V_1352 ) ) ;
if ( V_30 -> V_5 [ V_922 ] ) {
if ( ! V_30 -> V_5 [ V_459 ] )
return - V_16 ;
memcpy ( & V_1341 . V_893 ,
F_23 ( V_30 -> V_5 [ V_922 ] ) ,
sizeof( V_1341 . V_893 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1353 ] ) )
V_1341 . V_51 |= V_1354 ;
if ( V_30 -> V_5 [ V_468 ] )
memcpy ( & V_1341 . V_1355 ,
F_23 ( V_30 -> V_5 [ V_468 ] ) ,
sizeof( V_1341 . V_1355 ) ) ;
if ( V_30 -> V_5 [ V_923 ] ) {
if ( ! V_30 -> V_5 [ V_468 ] )
return - V_16 ;
memcpy ( & V_1341 . V_894 ,
F_23 ( V_30 -> V_5 [ V_923 ] ) ,
sizeof( V_1341 . V_894 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1356 ] ) ) {
if ( ! ( V_7 -> V_18 . V_291 &
V_1357 ) ||
! ( V_7 -> V_18 . V_291 & V_1358 ) )
return - V_16 ;
V_1341 . V_51 |= V_1359 ;
}
V_35 = F_150 ( V_7 , V_30 , & V_1341 . V_714 , 1 ) ;
if ( ! V_35 ) {
F_112 ( V_533 -> V_28 ) ;
V_35 = F_273 ( V_7 , V_533 , V_55 , V_540 ,
V_586 , V_584 , & V_1341 ) ;
F_114 ( V_533 -> V_28 ) ;
}
return V_35 ;
}
static int F_274 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
const T_2 * V_1123 = NULL , * V_540 ;
int V_1124 = 0 , V_35 ;
T_3 V_955 ;
bool V_1314 ;
if ( ! F_22 ( V_30 -> V_5 [ V_675 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_954 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_383 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_955 = F_78 ( V_30 -> V_5 [ V_954 ] ) ;
if ( V_955 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_675 ] ) {
V_1123 = F_23 ( V_30 -> V_5 [ V_675 ] ) ;
V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
}
V_1314 = ! ! V_30 -> V_5 [ V_1319 ] ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_275 ( V_7 , V_533 , V_540 , V_1123 , V_1124 , V_955 ,
V_1314 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static int F_276 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
const T_2 * V_1123 = NULL , * V_540 ;
int V_1124 = 0 , V_35 ;
T_3 V_955 ;
bool V_1314 ;
if ( ! F_22 ( V_30 -> V_5 [ V_675 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_954 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_385 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_955 = F_78 ( V_30 -> V_5 [ V_954 ] ) ;
if ( V_955 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_675 ] ) {
V_1123 = F_23 ( V_30 -> V_5 [ V_675 ] ) ;
V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
}
V_1314 = ! ! V_30 -> V_5 [ V_1319 ] ;
F_112 ( V_533 -> V_28 ) ;
V_35 = F_277 ( V_7 , V_533 , V_540 , V_1123 , V_1124 , V_955 ,
V_1314 ) ;
F_114 ( V_533 -> V_28 ) ;
return V_35 ;
}
static bool
F_278 ( struct V_6 * V_7 ,
int V_1360 [ V_356 ] ,
int V_1361 )
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
if ( V_240 -> V_262 [ V_159 ] . V_264 == V_1361 ) {
V_1360 [ V_290 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_279 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1362 V_1363 ;
struct V_18 * V_18 ;
struct V_130 * V_1364 = NULL ;
int V_35 ;
memset ( & V_1363 , 0 , sizeof( V_1363 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_675 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_585 ] ||
! F_24 ( V_30 -> V_5 [ V_585 ] ) )
return - V_16 ;
V_1363 . V_535 = 100 ;
if ( V_30 -> V_5 [ V_701 ] ) {
V_1363 . V_535 =
F_4 ( V_30 -> V_5 [ V_701 ] ) ;
if ( V_1363 . V_535 < 1 || V_1363 . V_535 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_345 -> V_387 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_146 )
return - V_534 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_541 ] ) {
V_1363 . V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( ! F_119 ( V_1363 . V_540 ) )
return - V_16 ;
}
V_1363 . V_586 = F_23 ( V_30 -> V_5 [ V_585 ] ) ;
V_1363 . V_584 = F_24 ( V_30 -> V_5 [ V_585 ] ) ;
if ( V_30 -> V_5 [ V_675 ] ) {
V_1363 . V_1123 = F_23 ( V_30 -> V_5 [ V_675 ] ) ;
V_1363 . V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1363 . V_514 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_280 ( & V_7 -> V_18 , & V_1363 . V_514 ,
V_146 ) )
return - V_16 ;
switch ( V_1363 . V_514 . V_517 ) {
case V_531 :
case V_532 :
case V_518 :
break;
case V_573 :
case V_574 :
if ( ! ( V_7 -> V_18 . V_291 & V_1365 ) )
return - V_16 ;
break;
case V_1366 :
case V_1367 :
case V_1368 :
if ( ! ( V_7 -> V_18 . V_291 & V_1365 ) )
return - V_16 ;
if ( ! F_281 ( & V_7 -> V_18 ,
V_1369 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1363 . V_1370 = ! ! V_30 -> V_5 [ V_1371 ] ;
V_1363 . V_710 = ! ! V_30 -> V_5 [ V_711 ] ;
if ( V_30 -> V_5 [ V_1002 ] ) {
T_2 * V_1180 =
F_23 ( V_30 -> V_5 [ V_1002 ] ) ;
int V_1372 =
F_24 ( V_30 -> V_5 [ V_1002 ] ) ;
struct V_239 * V_240 =
V_18 -> V_357 [ V_1363 . V_514 . V_55 -> V_290 ] ;
V_35 = F_237 ( V_240 , V_1180 , V_1372 ,
& V_1363 . V_1003 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_459 ] )
memcpy ( & V_1363 . V_1352 ,
F_23 ( V_30 -> V_5 [ V_459 ] ) ,
sizeof( V_1363 . V_1352 ) ) ;
if ( V_30 -> V_5 [ V_922 ] ) {
if ( ! V_30 -> V_5 [ V_459 ] )
return - V_16 ;
memcpy ( & V_1363 . V_893 ,
F_23 ( V_30 -> V_5 [ V_922 ] ) ,
sizeof( V_1363 . V_893 ) ) ;
}
if ( V_30 -> V_5 [ V_1373 ] &&
! F_278 ( V_7 , V_1363 . V_1360 ,
F_4 ( V_30 -> V_5 [ V_1373 ] ) ) )
return - V_16 ;
if ( V_1363 . V_710 && V_30 -> V_5 [ V_1374 ] ) {
bool V_132 = false ;
V_1364 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1374 ] ,
& V_132 ) ;
if ( F_17 ( V_1364 ) )
return F_18 ( V_1364 ) ;
if ( ( V_1363 . V_514 . V_517 != V_518 ) &&
V_132 ) {
F_41 ( V_1364 ) ;
return - V_16 ;
}
}
V_1363 . V_1323 =
F_210 ( V_30 -> V_5 [ V_1324 ] ) ;
V_1363 . V_1375 =
F_210 ( V_30 -> V_5 [ V_1376 ] ) ;
V_35 = F_282 ( V_7 , V_533 , & V_1363 , V_1364 ) ;
if ( V_35 )
F_283 ( V_1364 ) ;
return V_35 ;
}
static int F_284 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
if ( ! V_7 -> V_345 -> V_1377 )
return - V_534 ;
if ( V_533 -> V_28 -> V_141 != V_146 )
return - V_534 ;
return F_285 ( V_7 , V_533 , false ) ;
}
static int F_286 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
int V_1360 [ V_356 ] ;
V_22 V_1378 ;
int V_35 ;
if ( V_533 -> V_28 -> V_141 != V_146 &&
V_533 -> V_28 -> V_141 != V_145 &&
V_533 -> V_28 -> V_141 != V_152 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_427 )
return - V_534 ;
memset ( V_1360 , 0 , sizeof( V_1360 ) ) ;
if ( ! V_30 -> V_5 [ V_1373 ] )
return - V_16 ;
V_1378 = F_4 ( V_30 -> V_5 [ V_1373 ] ) ;
if ( ! F_278 ( V_7 , V_1360 , V_1378 ) )
return - V_16 ;
V_35 = V_7 -> V_345 -> V_427 ( & V_7 -> V_18 , V_533 , V_1360 ) ;
return V_35 ;
}
static struct V_31 *
F_287 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1379 ,
V_22 V_49 , V_22 V_50 , enum V_280 V_52 ,
enum V_754 V_45 ,
const struct V_475 * V_30 ,
T_13 V_1380 )
{
struct V_31 * V_32 ;
void * V_283 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1379 + 100 , V_1380 ) ;
if ( ! V_32 )
return NULL ;
V_283 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_288 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1381 ,
V_30 -> V_1382 ) )
goto V_61;
if ( F_28 ( V_32 , V_1383 ,
V_30 -> V_1384 ) )
goto V_61;
}
if ( V_17 ) {
if ( F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ) )
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
F_288 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_289 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_280 V_52 ,
enum V_754 V_45 ,
int V_1385 ,
int V_1379 , T_13 V_1380 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_475 * V_30 ;
switch ( V_52 ) {
case V_1386 :
if ( F_59 ( V_1385 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1387 :
if ( F_59 ( V_1385 < 0 ||
V_1385 >= V_18 -> V_479 ) )
return NULL ;
V_30 = & V_18 -> V_481 [ V_1385 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_287 ( V_7 , V_17 , V_1379 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1380 ) ;
}
void F_290 ( struct V_31 * V_32 , T_13 V_1380 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1388 V_1389 = V_1390 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
if ( V_138 -> F_236 == V_477 )
V_1389 = V_1391 ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1389 , V_1380 ) ;
}
static int F_291 ( struct V_31 * V_32 , struct V_29 * V_30 )
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
if ( ! V_30 -> V_5 [ V_1392 ] )
return - V_16 ;
V_7 -> V_1393 = V_30 ;
V_35 = F_292 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1392 ] ) ,
F_24 ( V_30 -> V_5 [ V_1392 ] ) ) ;
V_7 -> V_1393 = NULL ;
return V_35 ;
}
static int F_293 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1394 ;
void * V_138 = NULL ;
int V_1395 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1394 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_873;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_873;
}
V_1394 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1392 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1392 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1395 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1394 ) ;
if ( ! V_7 ) {
V_35 = - V_647 ;
goto V_873;
}
if ( ! V_7 -> V_345 -> V_1396 ) {
V_35 = - V_534 ;
goto V_873;
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_494 , V_495 ,
V_1386 ) ;
struct V_4 * V_1397 ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_1394 ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1397 = F_47 ( V_32 , V_1392 ) ;
if ( ! V_1397 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = F_294 ( V_7 , V_32 , V_34 , V_138 , V_1395 ) ;
F_48 ( V_32 , V_1397 ) ;
if ( V_35 == - V_91 || V_35 == - V_647 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_873;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1394 + 1 ;
V_873:
F_20 () ;
return V_35 ;
}
static int F_295 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1398 V_443 ;
struct V_18 * V_18 ;
struct V_130 * V_1364 = NULL ;
int V_35 ;
memset ( & V_443 , 0 , sizeof( V_443 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_675 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_585 ] ||
! F_24 ( V_30 -> V_5 [ V_585 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_712 ] ) {
V_443 . V_694 =
F_4 ( V_30 -> V_5 [ V_712 ] ) ;
if ( ! F_147 ( V_7 , V_443 . V_694 ,
V_444 ) )
return - V_16 ;
} else
V_443 . V_694 = V_713 ;
V_443 . V_710 = V_30 -> V_5 [ V_711 ] ;
V_35 = F_150 ( V_7 , V_30 , & V_443 . V_714 ,
V_715 ) ;
if ( V_35 )
return V_35 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
V_18 = & V_7 -> V_18 ;
V_443 . V_1399 = - 1 ;
if ( V_30 -> V_5 [ V_1400 ] &&
( V_18 -> V_51 & V_324 ) ) {
V_443 . V_1399 =
F_78 ( V_30 -> V_5 [ V_1400 ] ) ;
}
if ( V_30 -> V_5 [ V_541 ] )
V_443 . V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
else if ( V_30 -> V_5 [ V_1401 ] )
V_443 . V_1402 =
F_23 ( V_30 -> V_5 [ V_1401 ] ) ;
V_443 . V_586 = F_23 ( V_30 -> V_5 [ V_585 ] ) ;
V_443 . V_584 = F_24 ( V_30 -> V_5 [ V_585 ] ) ;
if ( V_30 -> V_5 [ V_675 ] ) {
V_443 . V_1123 = F_23 ( V_30 -> V_5 [ V_675 ] ) ;
V_443 . V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
}
if ( V_30 -> V_5 [ V_1342 ] ) {
V_443 . V_1344 = F_4 ( V_30 -> V_5 [ V_1342 ] ) ;
if ( V_443 . V_1344 != V_1345 &&
V_443 . V_1344 != V_1347 )
return - V_16 ;
} else {
V_443 . V_1344 = V_1347 ;
}
if ( V_30 -> V_5 [ V_516 ] ) {
V_443 . V_1264 = F_44 (
V_18 , V_30 -> V_5 [ V_516 ] ) ;
if ( ! V_443 . V_1264 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1403 ] ) {
V_443 . V_1404 = F_44 (
V_18 , V_30 -> V_5 [ V_1403 ] ) ;
if ( ! V_443 . V_1404 )
return - V_16 ;
}
if ( V_443 . V_710 && V_30 -> V_5 [ V_1374 ] ) {
V_1364 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1374 ] , NULL ) ;
if ( F_17 ( V_1364 ) )
return F_18 ( V_1364 ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1350 ] ) )
V_443 . V_51 |= V_1351 ;
if ( V_30 -> V_5 [ V_459 ] )
memcpy ( & V_443 . V_1352 ,
F_23 ( V_30 -> V_5 [ V_459 ] ) ,
sizeof( V_443 . V_1352 ) ) ;
if ( V_30 -> V_5 [ V_922 ] ) {
if ( ! V_30 -> V_5 [ V_459 ] ) {
F_283 ( V_1364 ) ;
return - V_16 ;
}
memcpy ( & V_443 . V_893 ,
F_23 ( V_30 -> V_5 [ V_922 ] ) ,
sizeof( V_443 . V_893 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1353 ] ) )
V_443 . V_51 |= V_1354 ;
if ( V_30 -> V_5 [ V_468 ] )
memcpy ( & V_443 . V_1355 ,
F_23 ( V_30 -> V_5 [ V_468 ] ) ,
sizeof( V_443 . V_1355 ) ) ;
if ( V_30 -> V_5 [ V_923 ] ) {
if ( ! V_30 -> V_5 [ V_468 ] ) {
F_283 ( V_1364 ) ;
return - V_16 ;
}
memcpy ( & V_443 . V_894 ,
F_23 ( V_30 -> V_5 [ V_923 ] ) ,
sizeof( V_443 . V_894 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1356 ] ) ) {
if ( ! ( V_7 -> V_18 . V_291 &
V_1357 ) ||
! ( V_7 -> V_18 . V_291 & V_1358 ) )
return - V_16 ;
V_443 . V_51 |= V_1359 ;
}
F_112 ( V_533 -> V_28 ) ;
V_35 = F_296 ( V_7 , V_533 , & V_443 , V_1364 , NULL ) ;
F_114 ( V_533 -> V_28 ) ;
if ( V_35 )
F_283 ( V_1364 ) ;
return V_35 ;
}
static int F_297 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_3 V_1405 ;
int V_490 ;
if ( ! V_30 -> V_5 [ V_954 ] )
V_1405 = V_1406 ;
else
V_1405 = F_78 ( V_30 -> V_5 [ V_954 ] ) ;
if ( V_1405 == 0 )
return - V_16 ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
F_112 ( V_533 -> V_28 ) ;
V_490 = F_298 ( V_7 , V_533 , V_1405 , true ) ;
F_114 ( V_533 -> V_28 ) ;
return V_490 ;
}
static int F_299 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1407 ] ) {
V_22 V_1408 = F_4 ( V_30 -> V_5 [ V_1407 ] ) ;
V_2 = F_300 ( V_1408 ) ;
} else if ( V_30 -> V_5 [ V_1409 ] ) {
V_22 V_1410 = F_4 ( V_30 -> V_5 [ V_1409 ] ) ;
V_2 = F_301 ( V_1410 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_302 ( V_7 , V_2 ) ;
F_303 ( V_2 ) ;
return V_35 ;
}
static int F_304 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
int (* F_305)( struct V_18 * V_18 , struct V_25 * V_533 ,
struct V_1411 * V_1412 ) = NULL ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1411 V_1412 ;
memset ( & V_1412 , 0 , sizeof( struct V_1411 ) ) ;
if ( ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1413 ] )
return - V_16 ;
V_1412 . V_1414 = F_23 ( V_30 -> V_5 [ V_1413 ] ) ;
V_1412 . V_540 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
switch ( V_30 -> V_1415 -> V_52 ) {
case V_1416 :
F_305 = V_7 -> V_345 -> V_391 ;
break;
case V_1417 :
F_305 = V_7 -> V_345 -> V_393 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_305 )
return - V_534 ;
return F_305 ( & V_7 -> V_18 , V_533 , & V_1412 ) ;
}
static int F_306 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
if ( V_533 -> V_28 -> V_141 != V_147 &&
V_533 -> V_28 -> V_141 != V_148 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_395 )
return - V_534 ;
return F_307 ( V_7 , V_533 ) ;
}
static int F_308 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 V_1418 , V_1419 ;
V_22 V_1420 = 0 ;
T_3 V_1421 ;
T_2 * V_1422 ;
bool V_1423 ;
if ( ! ( V_7 -> V_18 . V_51 & V_326 ) ||
! V_7 -> V_345 -> V_412 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1424 ] ||
! V_30 -> V_5 [ V_1425 ] ||
! V_30 -> V_5 [ V_1426 ] ||
! V_30 -> V_5 [ V_675 ] ||
! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_1422 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_1418 = F_34 ( V_30 -> V_5 [ V_1424 ] ) ;
V_1421 = F_78 ( V_30 -> V_5 [ V_1425 ] ) ;
V_1419 = F_34 ( V_30 -> V_5 [ V_1426 ] ) ;
V_1423 = F_210 ( V_30 -> V_5 [ V_1427 ] ) ;
if ( V_30 -> V_5 [ V_1428 ] )
V_1420 =
F_4 ( V_30 -> V_5 [ V_1428 ] ) ;
return F_309 ( V_7 , V_533 , V_1422 , V_1418 ,
V_1419 , V_1421 , V_1420 ,
V_1423 ,
F_23 ( V_30 -> V_5 [ V_675 ] ) ,
F_24 ( V_30 -> V_5 [ V_675 ] ) ) ;
}
static int F_310 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
enum V_1429 V_1430 ;
T_2 * V_1422 ;
if ( ! ( V_7 -> V_18 . V_51 & V_326 ) ||
! V_7 -> V_345 -> V_414 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1431 ] ||
! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_1430 = F_34 ( V_30 -> V_5 [ V_1431 ] ) ;
V_1422 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
return F_311 ( V_7 , V_533 , V_1422 , V_1430 ) ;
}
static int F_312 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
struct V_513 V_514 ;
struct V_31 * V_53 ;
void * V_283 ;
T_1 V_639 ;
V_22 V_1432 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_516 ] ||
! V_30 -> V_5 [ V_1433 ] )
return - V_16 ;
V_1432 = F_4 ( V_30 -> V_5 [ V_1433 ] ) ;
if ( ! V_7 -> V_345 -> V_398 ||
! ( V_7 -> V_18 . V_51 & V_397 ) )
return - V_534 ;
if ( V_1432 < V_1434 ||
V_1432 > V_7 -> V_18 . V_448 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1435 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_649;
}
V_35 = F_313 ( V_7 , V_17 , V_514 . V_55 ,
V_1432 , & V_639 ) ;
if ( V_35 )
goto V_649;
if ( F_104 ( V_53 , V_1436 , V_639 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_649:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_314 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
T_1 V_639 ;
if ( ! V_30 -> V_5 [ V_1436 ] )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_1437 )
return - V_534 ;
V_639 = F_5 ( V_30 -> V_5 [ V_1436 ] ) ;
return F_315 ( V_7 , V_17 , V_639 ) ;
}
static V_22 F_316 ( struct V_239 * V_240 ,
T_2 * V_1180 , T_2 V_1438 )
{
T_2 V_159 ;
V_22 V_739 = 0 ;
for ( V_159 = 0 ; V_159 < V_1438 ; V_159 ++ ) {
int V_244 = ( V_1180 [ V_159 ] & 0x7f ) * 5 ;
int V_1439 ;
for ( V_1439 = 0 ; V_1439 < V_240 -> V_261 ; V_1439 ++ ) {
struct V_243 * V_1440 =
& V_240 -> V_262 [ V_1439 ] ;
if ( V_244 == V_1440 -> V_264 ) {
V_739 |= 1 << V_1439 ;
break;
}
}
if ( V_1439 == V_240 -> V_261 )
return 0 ;
}
return V_739 ;
}
static bool F_317 ( struct V_239 * V_240 ,
T_2 * V_1180 , T_2 V_1438 ,
T_2 V_248 [ V_1441 ] )
{
T_2 V_159 ;
memset ( V_248 , 0 , V_1441 ) ;
for ( V_159 = 0 ; V_159 < V_1438 ; V_159 ++ ) {
int V_1439 , V_1442 ;
V_1439 = V_1180 [ V_159 ] / 8 ;
V_1442 = F_157 ( V_1180 [ V_159 ] % 8 ) ;
if ( ( V_1439 < 0 ) || ( V_1439 >= V_1441 ) )
return false ;
if ( V_240 -> V_245 . V_248 . V_1443 [ V_1439 ] & V_1442 )
V_248 [ V_1439 ] |= V_1442 ;
else
return false ;
}
return true ;
}
static T_3 F_318 ( T_2 V_1444 )
{
T_3 V_1445 = 0 ;
switch ( V_1444 ) {
case V_1446 :
break;
case V_1447 :
V_1445 = 0x00FF ;
break;
case V_1448 :
V_1445 = 0x01FF ;
break;
case V_1449 :
V_1445 = 0x03FF ;
break;
default:
break;
}
return V_1445 ;
}
static void F_319 ( T_3 V_1444 ,
T_3 V_1450 [ V_1451 ] )
{
T_2 V_777 ;
for ( V_777 = 0 ; V_777 < V_1451 ; V_777 ++ ) {
V_1450 [ V_777 ] = F_318 ( V_1444 & 0x03 ) ;
V_1444 >>= 2 ;
}
}
static bool F_320 ( struct V_239 * V_240 ,
struct V_1452 * V_815 ,
T_3 V_248 [ V_1451 ] )
{
T_3 V_1453 = F_321 ( V_240 -> V_255 . V_258 . V_1453 ) ;
T_3 V_1454 [ V_1451 ] = {} ;
T_2 V_159 ;
if ( ! V_240 -> V_255 . V_256 )
return false ;
memset ( V_248 , 0 , sizeof( T_3 ) * V_1451 ) ;
F_319 ( V_1453 , V_1454 ) ;
for ( V_159 = 0 ; V_159 < V_1451 ; V_159 ++ ) {
if ( ( V_1454 [ V_159 ] & V_815 -> V_248 [ V_159 ] ) == V_815 -> V_248 [ V_159 ] )
V_248 [ V_159 ] = V_815 -> V_248 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_322 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1455 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1456 V_739 ;
int V_134 , V_159 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_4 * V_1457 ;
struct V_239 * V_240 ;
T_3 V_1458 ;
if ( ! V_7 -> V_345 -> V_400 )
return - V_534 ;
memset ( & V_739 , 0 , sizeof( V_739 ) ) ;
for ( V_159 = 0 ; V_159 < V_356 ; V_159 ++ ) {
V_240 = V_7 -> V_18 . V_357 [ V_159 ] ;
if ( ! V_240 )
continue;
V_739 . V_1459 [ V_159 ] . V_1460 = ( 1 << V_240 -> V_261 ) - 1 ;
memcpy ( V_739 . V_1459 [ V_159 ] . V_1461 ,
V_240 -> V_245 . V_248 . V_1443 ,
sizeof( V_739 . V_1459 [ V_159 ] . V_1461 ) ) ;
if ( ! V_240 -> V_255 . V_256 )
continue;
V_1458 = F_321 ( V_240 -> V_255 . V_258 . V_1453 ) ;
F_319 ( V_1458 , V_739 . V_1459 [ V_159 ] . V_258 ) ;
}
if ( ! V_30 -> V_5 [ V_1462 ] )
goto V_591;
F_113 ( V_1463 > V_1441 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_289 V_290 = F_236 ( V_1457 ) ;
int V_35 ;
if ( V_290 < 0 || V_290 >= V_356 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_357 [ V_290 ] ;
if ( V_240 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1455 , F_23 ( V_1457 ) ,
F_24 ( V_1457 ) , V_1464 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1465 ] ) {
V_739 . V_1459 [ V_290 ] . V_1460 = F_316 (
V_240 ,
F_23 ( V_95 [ V_1465 ] ) ,
F_24 ( V_95 [ V_1465 ] ) ) ;
if ( ( V_739 . V_1459 [ V_290 ] . V_1460 == 0 ) &&
F_24 ( V_95 [ V_1465 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1466 ] ) {
if ( ! F_317 (
V_240 ,
F_23 ( V_95 [ V_1466 ] ) ,
F_24 ( V_95 [ V_1466 ] ) ,
V_739 . V_1459 [ V_290 ] . V_1461 ) )
return - V_16 ;
}
if ( V_95 [ V_1467 ] ) {
if ( ! F_320 (
V_240 ,
F_23 ( V_95 [ V_1467 ] ) ,
V_739 . V_1459 [ V_290 ] . V_258 ) )
return - V_16 ;
}
if ( V_95 [ V_1468 ] ) {
V_739 . V_1459 [ V_290 ] . V_1469 =
F_34 ( V_95 [ V_1468 ] ) ;
if ( V_739 . V_1459 [ V_290 ] . V_1469 > V_1470 )
return - V_16 ;
}
if ( V_739 . V_1459 [ V_290 ] . V_1460 == 0 ) {
if ( ! ( V_7 -> V_18 . V_357 [ V_290 ] -> V_245 . V_246 ||
V_7 -> V_18 . V_357 [ V_290 ] -> V_255 . V_256 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_1441 ; V_159 ++ )
if ( V_739 . V_1459 [ V_290 ] . V_1461 [ V_159 ] )
goto V_591;
for ( V_159 = 0 ; V_159 < V_1451 ; V_159 ++ )
if ( V_739 . V_1459 [ V_290 ] . V_258 [ V_159 ] )
goto V_591;
return - V_16 ;
}
}
V_591:
return F_323 ( V_7 , V_533 , NULL , & V_739 ) ;
}
static int F_324 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
T_3 V_1471 = V_277 | V_1472 ;
if ( ! V_30 -> V_5 [ V_1473 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_276 ] )
V_1471 = F_78 ( V_30 -> V_5 [ V_276 ] ) ;
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
return F_325 ( V_17 , V_30 -> V_498 , V_1471 ,
F_23 ( V_30 -> V_5 [ V_1473 ] ) ,
F_24 ( V_30 -> V_5 [ V_1473 ] ) ) ;
}
static int F_326 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
struct V_513 V_514 ;
int V_35 ;
void * V_283 = NULL ;
T_1 V_639 ;
struct V_31 * V_53 = NULL ;
struct V_1474 V_137 = {
. V_1475 =
V_30 -> V_5 [ V_1476 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1477 ] )
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
if ( V_30 -> V_5 [ V_1433 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_449 ) )
return - V_16 ;
V_137 . V_1478 = F_4 ( V_30 -> V_5 [ V_1433 ] ) ;
if ( V_137 . V_1478 < V_1434 ||
V_137 . V_1478 > V_7 -> V_18 . V_448 )
return - V_16 ;
}
V_137 . V_1479 = V_30 -> V_5 [ V_450 ] ;
if ( V_137 . V_1479 && ! ( V_7 -> V_18 . V_51 & V_449 ) )
return - V_16 ;
V_137 . V_1187 = F_210 ( V_30 -> V_5 [ V_1188 ] ) ;
V_514 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_516 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_514 . V_55 && V_137 . V_1479 )
return - V_16 ;
V_137 . V_1480 = F_23 ( V_30 -> V_5 [ V_1477 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1477 ] ) ;
if ( V_30 -> V_5 [ V_1481 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1481 ] ) ;
int V_159 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1482 = V_47 / sizeof( T_3 ) ;
V_137 . V_1483 =
F_23 ( V_30 -> V_5 [ V_1481 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1482 ; V_159 ++ ) {
if ( V_137 . V_1483 [ V_159 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1475 ) {
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1484 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_649;
}
}
V_137 . V_55 = V_514 . V_55 ;
V_35 = F_327 ( V_7 , V_17 , & V_137 , & V_639 ) ;
if ( V_35 )
goto V_649;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1436 , V_639 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_649:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_328 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
T_1 V_639 ;
if ( ! V_30 -> V_5 [ V_1436 ] )
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
V_639 = F_5 ( V_30 -> V_5 [ V_1436 ] ) ;
return F_329 ( V_7 , V_17 , V_639 ) ;
}
static int F_330 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 V_1485 ;
bool V_282 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1486 ] )
return - V_16 ;
V_1485 = F_4 ( V_30 -> V_5 [ V_1486 ] ) ;
if ( V_1485 != V_1487 && V_1485 != V_1488 )
return - V_16 ;
V_17 = V_533 -> V_28 ;
if ( ! V_7 -> V_345 -> V_1489 )
return - V_534 ;
V_282 = ( V_1485 == V_1488 ) ? true : false ;
if ( V_282 == V_17 -> V_1490 )
return 0 ;
V_35 = F_331 ( V_7 , V_533 , V_282 , V_17 -> V_1491 ) ;
if ( ! V_35 )
V_17 -> V_1490 = V_282 ;
return V_35 ;
}
static int F_332 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
enum V_1492 V_1485 ;
struct V_1 * V_17 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_31 * V_53 ;
void * V_283 ;
int V_35 ;
V_17 = V_533 -> V_28 ;
if ( ! V_7 -> V_345 -> V_1489 )
return - V_534 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1493 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_649;
}
if ( V_17 -> V_1490 )
V_1485 = V_1488 ;
else
V_1485 = V_1487 ;
if ( F_28 ( V_53 , V_1486 , V_1485 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_649:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_333 ( struct V_29 * V_30 ,
V_22 V_244 , V_22 V_1494 , V_22 V_1495 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
if ( V_244 > 100 || V_1495 > V_1496 )
return - V_16 ;
if ( ! V_7 -> V_345 -> V_1497 )
return - V_534 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_534 ;
return F_334 ( V_7 , V_533 , V_244 , V_1494 , V_1495 ) ;
}
static int F_335 ( struct V_29 * V_30 ,
T_12 V_1498 , V_22 V_1499 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
if ( V_1498 > 0 )
return - V_16 ;
if ( V_1498 == 0 )
V_1499 = 0 ;
if ( ! V_7 -> V_345 -> V_1500 )
return - V_534 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_534 ;
return F_336 ( V_7 , V_533 , V_1498 , V_1499 ) ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1501 + 1 ] ;
struct V_4 * V_1502 ;
int V_35 ;
V_1502 = V_30 -> V_5 [ V_1503 ] ;
if ( ! V_1502 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1501 , V_1502 ,
V_1504 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1505 ] &&
V_5 [ V_1506 ] ) {
T_12 V_1498 = V_1102 ( V_5 [ V_1505 ] ) ;
V_22 V_1499 = F_4 ( V_5 [ V_1506 ] ) ;
return F_335 ( V_30 , V_1498 , V_1499 ) ;
}
if ( V_5 [ V_1507 ] &&
V_5 [ V_1508 ] &&
V_5 [ V_1509 ] ) {
V_22 V_244 = F_4 ( V_5 [ V_1507 ] ) ;
V_22 V_1494 = F_4 ( V_5 [ V_1508 ] ) ;
V_22 V_1495 = F_4 ( V_5 [ V_1509 ] ) ;
return F_333 ( V_30 , V_244 , V_1494 , V_1495 ) ;
}
return - V_16 ;
}
static int F_338 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1510 V_1105 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1105 . V_514 ) ;
if ( V_35 )
return V_35 ;
return F_339 ( V_7 , V_533 , & V_1105 ) ;
}
static int F_340 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
return F_341 ( V_7 , V_533 ) ;
}
static int F_342 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1036 V_1098 ;
struct V_1104 V_1105 ;
int V_35 ;
memcpy ( & V_1098 , & V_1040 , sizeof( V_1098 ) ) ;
memcpy ( & V_1105 , & V_1511 , sizeof( V_1105 ) ) ;
if ( V_30 -> V_5 [ V_1042 ] ) {
V_35 = F_207 ( V_30 , & V_1098 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_609 ] ||
! F_24 ( V_30 -> V_5 [ V_609 ] ) )
return - V_16 ;
V_1105 . V_1512 = F_23 ( V_30 -> V_5 [ V_609 ] ) ;
V_1105 . V_1039 = F_24 ( V_30 -> V_5 [ V_609 ] ) ;
if ( V_30 -> V_5 [ V_1373 ] &&
! F_278 ( V_7 , V_1105 . V_1360 ,
F_4 ( V_30 -> V_5 [ V_1373 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_701 ] ) {
V_1105 . V_535 =
F_4 ( V_30 -> V_5 [ V_701 ] ) ;
if ( V_1105 . V_535 < 10 ||
V_1105 . V_535 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_702 ] ) {
V_1105 . V_704 =
F_4 ( V_30 -> V_5 [ V_702 ] ) ;
if ( V_1105 . V_704 < 1 || V_1105 . V_704 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1107 ] ) {
V_35 = F_209 ( V_30 , & V_1105 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1105 . V_1127 )
V_1098 . V_1058 = false ;
if ( V_30 -> V_5 [ V_516 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1105 . V_514 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1105 . V_514 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_1002 ] ) {
T_2 * V_1180 = F_23 ( V_30 -> V_5 [ V_1002 ] ) ;
int V_1372 =
F_24 ( V_30 -> V_5 [ V_1002 ] ) ;
struct V_239 * V_240 ;
if ( ! V_1105 . V_514 . V_55 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_357 [ V_1105 . V_514 . V_55 -> V_290 ] ;
V_35 = F_237 ( V_240 , V_1180 , V_1372 ,
& V_1105 . V_1003 ) ;
if ( V_35 )
return V_35 ;
}
return F_343 ( V_7 , V_533 , & V_1105 , & V_1098 ) ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
return F_345 ( V_7 , V_533 ) ;
}
static int F_346 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1513 * V_189 = V_7 -> V_18 . V_1514 ;
struct V_4 * V_1515 , * V_1516 ;
int V_159 , V_1517 ;
if ( ! V_189 -> V_219 )
return 0 ;
V_1515 = F_47 ( V_53 , V_228 ) ;
if ( ! V_1515 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_189 -> V_219 ; V_159 ++ ) {
V_1516 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1516 )
return - V_91 ;
V_1517 = V_189 -> V_1518 [ V_159 ] . V_1519 ;
if ( F_51 ( V_53 , V_1520 , F_347 ( V_1517 , 8 ) ,
V_189 -> V_1518 [ V_159 ] . V_739 ) ||
F_51 ( V_53 , V_1521 , V_1517 ,
V_189 -> V_1518 [ V_159 ] . V_1522 ) ||
F_28 ( V_53 , V_1523 ,
V_189 -> V_1518 [ V_159 ] . V_1524 ) )
return - V_91 ;
F_48 ( V_53 , V_1516 ) ;
}
F_48 ( V_53 , V_1515 ) ;
return 0 ;
}
static int F_348 ( struct V_31 * V_53 ,
struct V_1525 * V_188 )
{
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_349 ( V_53 , V_1526 , V_188 -> V_1527 ) ||
F_349 ( V_53 , V_1528 , V_188 -> V_957 ) ||
F_51 ( V_53 , V_1529 , V_581 , V_188 -> V_1530 ) ||
F_55 ( V_53 , V_1531 , V_188 -> V_1532 ) ||
F_55 ( V_53 , V_1533 , V_188 -> V_1534 ) ||
F_51 ( V_53 , V_192 ,
V_188 -> V_1535 , V_188 -> V_1536 ) ||
F_28 ( V_53 , V_197 ,
V_188 -> V_1537 ) ||
F_51 ( V_53 , V_199 ,
V_188 -> V_1538 , V_188 -> V_1539 ) ||
F_51 ( V_53 , V_1540 ,
F_347 ( V_188 -> V_1538 , 8 ) , V_188 -> V_1541 ) )
return - V_91 ;
if ( V_188 -> V_1542 . V_47 &&
F_51 ( V_53 , V_194 ,
sizeof( V_188 -> V_1542 ) , & V_188 -> V_1542 ) )
return - V_91 ;
if ( V_188 -> V_1543 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_188 -> V_1543 ) + V_188 -> V_1544 ,
& V_188 -> V_1543 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_350 ( struct V_31 * V_53 ,
struct V_1191 * V_1341 )
{
struct V_4 * V_1545 , * V_1162 , * V_1546 , * V_1547 ;
int V_159 ;
if ( ! V_1341 )
return 0 ;
V_1545 = F_47 ( V_53 , V_230 ) ;
if ( ! V_1545 )
return - V_91 ;
if ( F_28 ( V_53 , V_1197 , V_1341 -> V_1193 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1210 , V_1341 -> V_1211 ) )
return - V_91 ;
V_1162 = F_47 ( V_53 , V_1176 ) ;
if ( ! V_1162 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1341 -> V_360 ; V_159 ++ )
F_28 ( V_53 , V_159 , V_1341 -> V_361 [ V_159 ] -> V_60 ) ;
F_48 ( V_53 , V_1162 ) ;
if ( V_1341 -> V_1192 ) {
V_1546 = F_47 ( V_53 , V_1198 ) ;
for ( V_159 = 0 ; V_159 < V_1341 -> V_1192 ; V_159 ++ ) {
V_1547 = F_47 ( V_53 , V_159 ) ;
F_51 ( V_53 , V_1201 ,
V_1341 -> V_1203 [ V_159 ] . V_586 . V_584 ,
V_1341 -> V_1203 [ V_159 ] . V_586 . V_586 ) ;
F_48 ( V_53 , V_1547 ) ;
}
F_48 ( V_53 , V_1546 ) ;
}
F_48 ( V_53 , V_1545 ) ;
return 0 ;
}
static int F_351 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1548 = V_592 ;
if ( ! V_7 -> V_18 . V_189 )
return - V_534 ;
if ( V_7 -> V_18 . V_1514 && V_7 -> V_18 . V_1514 -> V_188 ) {
V_1548 += V_7 -> V_18 . V_1514 -> V_188 -> V_1544 +
V_7 -> V_18 . V_1514 -> V_188 -> V_1535 +
V_7 -> V_18 . V_1514 -> V_188 -> V_1538 +
V_7 -> V_18 . V_1514 -> V_188 -> V_1538 / 8 ;
}
V_53 = F_74 ( V_1548 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1549 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_18 . V_1514 ) {
struct V_4 * V_201 ;
V_201 = F_47 ( V_53 , V_1550 ) ;
if ( ! V_201 )
goto V_61;
if ( ( V_7 -> V_18 . V_1514 -> V_1551 &&
F_29 ( V_53 , V_204 ) ) ||
( V_7 -> V_18 . V_1514 -> V_445 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1514 -> V_1552 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1514 -> V_1553 &&
F_29 ( V_53 , V_212 ) ) ||
( V_7 -> V_18 . V_1514 -> V_1554 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1514 -> V_1555 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1514 -> V_1556 &&
F_29 ( V_53 , V_218 ) ) )
goto V_61;
if ( F_346 ( V_53 , V_7 ) )
goto V_61;
if ( F_348 ( V_53 ,
V_7 -> V_18 . V_1514 -> V_188 ) )
goto V_61;
if ( F_350 (
V_53 ,
V_7 -> V_18 . V_1514 -> V_1557 ) )
goto V_61;
F_48 ( V_53 , V_201 ) ;
}
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_352 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1513 * V_1558 )
{
struct V_4 * V_95 [ V_1559 ] ;
struct V_1525 * V_1098 ;
struct V_1560 * V_195 = NULL ;
struct V_1561 * V_50 = NULL ;
V_22 V_1548 ;
V_22 V_1562 , V_1563 , V_1544 = 0 , V_1564 ;
int V_35 , V_1565 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1566 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1567 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1526 ] ||
! V_95 [ V_1528 ] ||
! V_95 [ V_1529 ] ||
! V_95 [ V_1533 ] ||
! V_95 [ V_192 ] ||
! V_95 [ V_197 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_1540 ] )
return - V_16 ;
V_1562 = F_24 ( V_95 [ V_192 ] ) ;
if ( V_1562 > V_7 -> V_18 . V_189 -> V_188 -> V_193 )
return - V_16 ;
if ( F_4 ( V_95 [ V_197 ] ) >
V_7 -> V_18 . V_189 -> V_188 -> V_198 ||
F_4 ( V_95 [ V_197 ] ) == 0 )
return - V_16 ;
V_1563 = F_24 ( V_95 [ V_199 ] ) ;
if ( V_1563 > V_7 -> V_18 . V_189 -> V_188 -> V_200 )
return - V_16 ;
V_1564 = F_24 ( V_95 [ V_1540 ] ) ;
if ( V_1564 != F_347 ( V_1563 , 8 ) )
return - V_16 ;
if ( V_95 [ V_196 ] ) {
V_22 V_1568 = F_24 ( V_95 [ V_196 ] ) ;
V_195 = F_23 ( V_95 [ V_196 ] ) ;
V_1544 = V_1568 - sizeof( * V_195 ) ;
if ( ! V_195 -> V_47 || V_1544 % V_195 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_195 )
return - V_16 ;
if ( V_195 -> V_47 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1569 )
return - V_16 ;
if ( V_195 -> V_47 < V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1570 )
return - V_16 ;
if ( V_1544 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1571 )
return - V_16 ;
if ( V_195 -> V_1235 + V_195 -> V_47 > V_1562 )
return - V_16 ;
}
if ( V_95 [ V_194 ] ) {
V_50 = F_23 ( V_95 [ V_194 ] ) ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1235 > V_1562 )
return - V_16 ;
}
V_1548 = sizeof( * V_1098 ) ;
V_1548 += V_1562 ;
V_1548 += V_1563 + V_1564 ;
V_1548 += V_1544 ;
V_1098 = F_38 ( V_1548 , V_135 ) ;
if ( ! V_1098 )
return - V_136 ;
V_1098 -> V_1527 = F_353 ( V_95 [ V_1526 ] ) ;
V_1098 -> V_957 = F_353 ( V_95 [ V_1528 ] ) ;
memcpy ( V_1098 -> V_1530 , F_23 ( V_95 [ V_1529 ] ) ,
V_581 ) ;
if ( V_95 [ V_1531 ] )
V_1565 = F_78 ( V_95 [ V_1531 ] ) ;
else
V_1565 = 0 ;
#ifdef F_354
V_35 = F_355 ( F_7 ( & V_7 -> V_18 ) , V_1572 , V_1573 ,
V_1574 , & V_1098 -> V_1575 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1098 ) ;
return V_35 ;
}
if ( F_356 ( V_1098 -> V_1575 -> V_44 , V_1565 ) ) {
F_357 ( V_1098 -> V_1575 ) ;
F_41 ( V_1098 ) ;
return - V_1576 ;
}
V_1098 -> V_1532 = F_358 ( V_1098 -> V_1575 -> V_44 ) -> V_1577 ;
#else
if ( ! V_1565 ) {
F_41 ( V_1098 ) ;
return - V_16 ;
}
V_1098 -> V_1532 = V_1565 ;
#endif
V_1098 -> V_1534 = F_78 ( V_95 [ V_1533 ] ) ;
V_1098 -> V_1535 = V_1562 ;
V_1098 -> V_1536 = ( T_2 * ) V_1098 + sizeof( * V_1098 ) + V_1544 ;
memcpy ( ( void * ) V_1098 -> V_1536 ,
F_23 ( V_95 [ V_192 ] ) ,
V_1562 ) ;
if ( V_50 )
V_1098 -> V_1542 = * V_50 ;
V_1098 -> V_1537 = F_4 ( V_95 [ V_197 ] ) ;
V_1098 -> V_1538 = V_1563 ;
V_1098 -> V_1539 = ( T_2 * ) V_1098 + sizeof( * V_1098 ) + V_1544 + V_1562 ;
memcpy ( ( void * ) V_1098 -> V_1539 ,
F_23 ( V_95 [ V_199 ] ) ,
V_1563 ) ;
V_1098 -> V_1541 = ( T_2 * ) V_1098 + sizeof( * V_1098 ) + V_1544 +
V_1562 + V_1563 ;
memcpy ( ( void * ) V_1098 -> V_1541 ,
F_23 ( V_95 [ V_1540 ] ) ,
V_1564 ) ;
if ( V_195 ) {
V_1098 -> V_1544 = V_1544 ;
memcpy ( & V_1098 -> V_1543 , V_195 , sizeof( * V_195 ) + V_1544 ) ;
}
V_1558 -> V_188 = V_1098 ;
return 0 ;
}
static int F_359 ( struct V_6 * V_7 ,
const struct V_1578 * V_189 ,
struct V_4 * V_45 ,
struct V_1513 * V_1558 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_38 ( V_1579 * sizeof( * V_95 ) , V_135 ) ;
if ( ! V_95 )
return - V_136 ;
if ( ! ( V_189 -> V_51 & V_229 ) ) {
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_96 ( V_95 , V_1222 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_591;
V_1558 -> V_1557 = F_241 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_243 ( V_1558 -> V_1557 ) ;
if ( V_35 )
V_1558 -> V_1557 = NULL ;
V_591:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_360 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_4 * V_95 [ V_1580 ] ;
struct V_1513 V_1581 = {} ;
struct V_1513 * V_1582 ;
const struct V_1578 * V_189 = V_7 -> V_18 . V_189 ;
int V_35 , V_159 ;
bool V_1583 = V_7 -> V_18 . V_1514 ;
bool V_1584 = false ;
if ( ! V_189 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1550 ] ) {
F_361 ( V_7 ) ;
V_7 -> V_18 . V_1514 = NULL ;
goto V_1585;
}
V_35 = F_96 ( V_95 , V_1586 ,
F_23 ( V_30 -> V_5 [ V_1550 ] ) ,
F_24 ( V_30 -> V_5 [ V_1550 ] ) ,
V_1587 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_204 ] ) {
if ( ! ( V_189 -> V_51 & V_203 ) )
return - V_16 ;
V_1581 . V_1551 = true ;
}
if ( V_95 [ V_206 ] ) {
if ( ! ( V_189 -> V_51 & V_205 ) )
return - V_16 ;
V_1581 . V_445 = true ;
V_1584 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_189 -> V_51 & V_207 ) )
return - V_16 ;
V_1581 . V_1552 = true ;
V_1584 = true ;
}
if ( V_95 [ V_210 ] )
return - V_16 ;
if ( V_95 [ V_212 ] ) {
if ( ! ( V_189 -> V_51 & V_211 ) )
return - V_16 ;
V_1581 . V_1553 = true ;
V_1584 = true ;
}
if ( V_95 [ V_214 ] ) {
if ( ! ( V_189 -> V_51 & V_213 ) )
return - V_16 ;
V_1581 . V_1554 = true ;
V_1584 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_189 -> V_51 & V_215 ) )
return - V_16 ;
V_1581 . V_1555 = true ;
V_1584 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_189 -> V_51 & V_217 ) )
return - V_16 ;
V_1581 . V_1556 = true ;
V_1584 = true ;
}
if ( V_95 [ V_228 ] ) {
struct V_4 * V_221 ;
int V_219 = 0 ;
int V_134 , V_1517 , V_1588 , V_1524 ;
struct V_4 * V_1589 [ V_1590 ] ;
V_1584 = true ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_189 -> V_219 )
return - V_16 ;
V_1581 . V_1518 = F_362 ( V_219 ,
sizeof( V_1581 . V_1518 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1581 . V_1518 )
return - V_136 ;
V_1581 . V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1591 ;
F_96 ( V_1589 , V_1592 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1589 [ V_1520 ] ||
! V_1589 [ V_1521 ] )
goto error;
V_1517 = F_24 ( V_1589 [ V_1521 ] ) ;
V_1588 = F_347 ( V_1517 , 8 ) ;
if ( F_24 ( V_1589 [ V_1520 ] ) != V_1588 )
goto error;
if ( V_1517 > V_189 -> V_226 ||
V_1517 < V_189 -> V_224 )
goto error;
if ( ! V_1589 [ V_1523 ] )
V_1524 = 0 ;
else
V_1524 = F_4 (
V_1589 [ V_1523 ] ) ;
if ( V_1524 > V_189 -> V_227 )
goto error;
V_1581 . V_1518 [ V_159 ] . V_1524 = V_1524 ;
V_1591 = F_363 ( V_1588 + V_1517 , V_135 ) ;
if ( ! V_1591 ) {
V_35 = - V_136 ;
goto error;
}
V_1581 . V_1518 [ V_159 ] . V_739 = V_1591 ;
memcpy ( V_1591 , F_23 ( V_1589 [ V_1520 ] ) ,
V_1588 ) ;
V_1591 += V_1588 ;
V_1581 . V_1518 [ V_159 ] . V_1522 = V_1591 ;
V_1581 . V_1518 [ V_159 ] . V_1519 = V_1517 ;
memcpy ( V_1591 ,
F_23 ( V_1589 [ V_1521 ] ) ,
V_1517 ) ;
V_159 ++ ;
}
}
if ( V_95 [ V_191 ] ) {
V_1584 = true ;
V_35 = F_352 (
V_7 , V_95 [ V_191 ] ,
& V_1581 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_230 ] ) {
V_1584 = true ;
V_35 = F_359 (
V_7 , V_189 , V_95 [ V_230 ] ,
& V_1581 ) ;
if ( V_35 )
goto error;
}
if ( V_1581 . V_1551 && V_1584 ) {
V_35 = - V_16 ;
goto error;
}
V_1582 = F_364 ( & V_1581 , sizeof( V_1581 ) , V_135 ) ;
if ( ! V_1582 ) {
V_35 = - V_136 ;
goto error;
}
F_361 ( V_7 ) ;
V_7 -> V_18 . V_1514 = V_1582 ;
V_1585:
if ( V_7 -> V_345 -> V_1585 &&
V_1583 != ! ! V_7 -> V_18 . V_1514 )
F_365 ( V_7 , V_7 -> V_18 . V_1514 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1581 . V_219 ; V_159 ++ )
F_41 ( V_1581 . V_1518 [ V_159 ] . V_739 ) ;
F_41 ( V_1581 . V_1518 ) ;
if ( V_1581 . V_188 && V_1581 . V_188 -> V_1575 )
F_357 ( V_1581 . V_188 -> V_1575 ) ;
F_41 ( V_1581 . V_188 ) ;
return V_35 ;
}
static int F_366 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1515 , * V_1516 , * V_1593 , * V_1594 ;
int V_159 , V_161 , V_1517 ;
struct V_1595 * V_233 ;
if ( ! V_7 -> V_234 -> V_236 )
return 0 ;
V_1594 = F_47 ( V_53 , V_238 ) ;
if ( ! V_1594 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_234 -> V_236 ; V_159 ++ ) {
V_1593 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1593 )
return - V_91 ;
V_233 = & V_7 -> V_234 -> V_1596 [ V_159 ] ;
if ( F_28 ( V_53 , V_1597 ,
V_233 -> V_1211 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1598 ,
V_233 -> V_1599 ) )
return - V_91 ;
V_1515 = F_47 ( V_53 ,
V_1600 ) ;
if ( ! V_1515 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ ) {
V_1516 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1516 )
return - V_91 ;
V_1517 = V_233 -> V_1518 [ V_161 ] . V_1519 ;
if ( F_51 ( V_53 , V_1520 ,
F_347 ( V_1517 , 8 ) ,
V_233 -> V_1518 [ V_161 ] . V_739 ) ||
F_51 ( V_53 , V_1521 , V_1517 ,
V_233 -> V_1518 [ V_161 ] . V_1522 ) ||
F_28 ( V_53 , V_1523 ,
V_233 -> V_1518 [ V_161 ] . V_1524 ) )
return - V_91 ;
F_48 ( V_53 , V_1516 ) ;
}
F_48 ( V_53 , V_1515 ) ;
F_48 ( V_53 , V_1593 ) ;
}
F_48 ( V_53 , V_1594 ) ;
return 0 ;
}
static int F_367 ( struct V_31 * V_32 , struct V_29 * V_30 )
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
V_1601 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_234 && F_366 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_368 ( struct V_6 * V_7 )
{
struct V_1602 * V_234 = V_7 -> V_234 ;
int V_159 , V_161 ;
struct V_1595 * V_233 ;
if ( ! V_234 )
return;
for ( V_159 = 0 ; V_159 < V_234 -> V_236 ; V_159 ++ ) {
V_233 = & V_234 -> V_1596 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ )
F_41 ( V_233 -> V_1518 [ V_161 ] . V_739 ) ;
F_41 ( V_233 -> V_1518 ) ;
}
F_41 ( V_234 -> V_1596 ) ;
F_41 ( V_234 ) ;
V_7 -> V_234 = NULL ;
}
static int F_369 ( struct V_6 * V_7 ,
struct V_4 * V_233 ,
struct V_1595 * V_1603 )
{
int V_35 , V_159 ;
const struct V_1604 * V_234 = V_7 -> V_18 . V_234 ;
struct V_4 * V_95 [ V_1605 ] , * V_221 ;
int V_134 , V_1517 , V_1588 , V_1524 , V_219 = 0 ;
struct V_4 * V_1589 [ V_1590 ] ;
V_35 = F_96 ( V_95 , V_1606 , F_23 ( V_233 ) ,
F_24 ( V_233 ) , V_1607 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1597 ] )
V_1603 -> V_1211 =
F_4 ( V_95 [ V_1597 ] ) ;
if ( V_1603 -> V_1211 > V_234 -> V_237 )
return - V_16 ;
if ( V_95 [ V_1598 ] )
V_1603 -> V_1599 =
F_4 ( V_95 [ V_1598 ] ) ;
if ( V_1603 -> V_1599 != V_1608 &&
V_1603 -> V_1599 != V_1609 )
return - V_16 ;
if ( ! V_95 [ V_1600 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_234 -> V_219 )
return - V_16 ;
V_1603 -> V_1518 = F_362 ( V_219 , sizeof( V_1603 -> V_1518 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1603 -> V_1518 )
return - V_136 ;
V_1603 -> V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1591 ;
F_96 ( V_1589 , V_1592 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
if ( ! V_1589 [ V_1520 ] ||
! V_1589 [ V_1521 ] )
return - V_16 ;
V_1517 = F_24 ( V_1589 [ V_1521 ] ) ;
V_1588 = F_347 ( V_1517 , 8 ) ;
if ( F_24 ( V_1589 [ V_1520 ] ) != V_1588 )
return - V_16 ;
if ( V_1517 > V_234 -> V_226 ||
V_1517 < V_234 -> V_224 )
return - V_16 ;
if ( ! V_1589 [ V_1523 ] )
V_1524 = 0 ;
else
V_1524 = F_4 ( V_1589 [ V_1523 ] ) ;
if ( V_1524 > V_234 -> V_227 )
return - V_16 ;
V_1603 -> V_1518 [ V_159 ] . V_1524 = V_1524 ;
V_1591 = F_363 ( V_1588 + V_1517 , V_135 ) ;
if ( ! V_1591 )
return - V_136 ;
V_1603 -> V_1518 [ V_159 ] . V_739 = V_1591 ;
memcpy ( V_1591 , F_23 ( V_1589 [ V_1520 ] ) ,
V_1588 ) ;
V_1591 += V_1588 ;
V_1603 -> V_1518 [ V_159 ] . V_1522 = V_1591 ;
V_1603 -> V_1518 [ V_159 ] . V_1519 = V_1517 ;
memcpy ( V_1591 , F_23 ( V_1589 [ V_1521 ] ) ,
V_1517 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_370 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
const struct V_1604 * V_234 = V_7 -> V_18 . V_234 ;
struct V_1602 V_1610 = {} ;
struct V_1602 * V_1611 ;
int V_35 , V_1612 , V_236 = 0 , V_159 , V_161 ;
struct V_4 * V_233 ;
struct V_1595 * V_1613 ;
if ( ! V_7 -> V_18 . V_234 || ! V_7 -> V_345 -> V_1614 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_238 ] ) {
F_368 ( V_7 ) ;
V_7 -> V_345 -> V_1614 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_236 ++ ;
if ( V_236 > V_234 -> V_236 )
return - V_16 ;
V_1610 . V_1596 = F_362 ( V_236 , sizeof( V_1610 . V_1596 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1610 . V_1596 )
return - V_136 ;
V_1610 . V_236 = V_236 ;
V_159 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_369 ( V_7 , V_233 ,
& V_1610 . V_1596 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = V_7 -> V_345 -> V_1614 ( & V_7 -> V_18 , & V_1610 ) ;
if ( V_35 )
goto error;
V_1611 = F_364 ( & V_1610 , sizeof( V_1610 ) , V_135 ) ;
if ( ! V_1611 ) {
V_35 = - V_136 ;
goto error;
}
F_368 ( V_7 ) ;
V_7 -> V_234 = V_1611 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1610 . V_236 ; V_159 ++ ) {
V_1613 = & V_1610 . V_1596 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1613 -> V_219 ; V_161 ++ )
F_41 ( V_1613 -> V_1518 [ V_161 ] . V_739 ) ;
F_41 ( V_1613 -> V_1518 ) ;
}
F_41 ( V_1610 . V_1596 ) ;
return V_35 ;
}
static int F_371 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_4 * V_95 [ V_1615 ] ;
struct V_1616 V_1617 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1618 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1619 ,
F_23 ( V_30 -> V_5 [ V_1618 ] ) ,
F_24 ( V_30 -> V_5 [ V_1618 ] ) ,
V_1620 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1621 ] ) != V_1622 )
return - V_1623 ;
if ( F_24 ( V_95 [ V_1624 ] ) != V_1625 )
return - V_1623 ;
if ( F_24 ( V_95 [ V_1626 ] ) != V_1627 )
return - V_1623 ;
V_1617 . V_1628 = F_23 ( V_95 [ V_1624 ] ) ;
V_1617 . V_1629 = F_23 ( V_95 [ V_1626 ] ) ;
V_1617 . V_1630 = F_23 ( V_95 [ V_1621 ] ) ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1225 ;
goto V_591;
}
if ( ! V_7 -> V_345 -> V_1631 ) {
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_372 ( V_7 , V_533 , & V_1617 ) ;
V_591:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_373 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1632 )
return - V_538 ;
V_17 -> V_1632 = V_30 -> V_498 ;
return 0 ;
}
static int F_374 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_31 * V_53 ;
void * V_283 ;
const T_2 * V_669 ;
T_1 V_639 ;
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
V_1633 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_649;
}
V_669 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_35 = F_375 ( V_7 , V_533 , V_669 , & V_639 ) ;
if ( V_35 )
goto V_649;
if ( F_104 ( V_53 , V_1436 , V_639 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_649:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_376 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1634 * V_1635 , * V_1636 ;
int V_1637 ;
if ( ! ( V_7 -> V_18 . V_51 & V_423 ) )
return - V_534 ;
V_1636 = F_38 ( sizeof( * V_1636 ) , V_135 ) ;
if ( ! V_1636 )
return - V_136 ;
F_261 ( & V_7 -> V_1638 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1635 -> V_1639 == V_30 -> V_498 ) {
V_1637 = - V_700 ;
goto V_873;
}
}
V_1636 -> V_1639 = V_30 -> V_498 ;
F_377 ( & V_1636 -> V_630 , & V_7 -> V_1640 ) ;
F_263 ( & V_7 -> V_1638 ) ;
return 0 ;
V_873:
F_263 ( & V_7 -> V_1638 ) ;
F_41 ( V_1636 ) ;
return V_1637 ;
}
static int F_378 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_345 -> V_425 )
return - V_534 ;
if ( V_17 -> V_141 != V_154 )
return - V_534 ;
if ( V_17 -> V_1641 )
return 0 ;
if ( F_379 ( V_7 -> V_1642 ) )
return - V_1643 ;
V_35 = F_380 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1641 = true ;
V_7 -> V_1644 ++ ;
return 0 ;
}
static int F_381 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_534 ;
if ( ! V_7 -> V_345 -> V_1645 )
return - V_534 ;
F_382 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_383 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_283 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_498 , V_30 -> V_499 , 0 ,
V_1646 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_1647 ,
V_1648 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_288 ( V_53 ) ;
return - V_91 ;
}
static int F_384 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1649 V_1650 ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
if ( ! V_7 -> V_345 -> V_1651 )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1652 ] ||
! F_22 ( V_30 -> V_5 [ V_675 ] ) )
return - V_16 ;
memset ( & V_1650 , 0 , sizeof( V_1650 ) ) ;
V_1650 . V_1653 = F_78 ( V_30 -> V_5 [ V_1652 ] ) ;
V_1650 . V_1123 = F_23 ( V_30 -> V_5 [ V_675 ] ) ;
V_1650 . V_1124 = F_24 ( V_30 -> V_5 [ V_675 ] ) ;
return F_385 ( V_7 , V_533 , & V_1650 ) ;
}
static int F_386 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
enum V_1654 V_1325 = V_1655 ;
T_3 V_1432 ;
int V_490 ;
if ( ! V_7 -> V_345 -> V_431 )
return - V_534 ;
if ( F_59 ( ! V_7 -> V_345 -> V_433 ) )
return - V_16 ;
if ( V_7 -> V_1656 )
return - V_538 ;
if ( V_30 -> V_5 [ V_1657 ] )
V_1325 = F_78 ( V_30 -> V_5 [ V_1657 ] ) ;
if ( V_1325 >= V_1658 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1659 ] )
return - V_16 ;
V_1432 =
F_78 ( V_30 -> V_5 [ V_1659 ] ) ;
if ( V_1432 > V_1660 )
return - V_1623 ;
V_490 = F_387 ( V_7 , V_17 , V_1325 , V_1432 ) ;
if ( ! V_490 )
V_7 -> V_1656 = V_30 -> V_498 ;
return V_490 ;
}
static int F_388 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
if ( ! V_7 -> V_345 -> V_433 )
return - V_534 ;
if ( V_7 -> V_1656 ) {
V_7 -> V_1656 = 0 ;
F_389 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_390 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_159 , V_35 ;
V_22 V_1661 , V_1384 ;
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
if ( ! V_30 -> V_5 [ V_1381 ] ||
! V_30 -> V_5 [ V_1383 ] )
return - V_16 ;
V_1661 = F_4 ( V_30 -> V_5 [ V_1381 ] ) ;
V_1384 = F_4 ( V_30 -> V_5 [ V_1383 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_474 ; V_159 ++ ) {
const struct V_1662 * V_1663 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1663 = & V_7 -> V_18 . V_478 [ V_159 ] ;
if ( V_1663 -> V_30 . V_1382 != V_1661 || V_1663 -> V_30 . V_1384 != V_1384 )
continue;
if ( V_1663 -> V_51 & ( V_1664 |
V_1665 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1663 -> V_51 & V_1665 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1663 -> V_51 & V_1666 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_548 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1641 )
return - V_548 ;
}
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_477 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_477 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_477 ] ) ;
}
V_7 -> V_1393 = V_30 ;
V_35 = V_7 -> V_18 . V_478 [ V_159 ] . F_391 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1393 = NULL ;
return V_35 ;
}
return - V_534 ;
}
struct V_31 * F_392 ( struct V_18 * V_18 ,
enum V_280 V_52 ,
enum V_754 V_45 ,
int V_1379 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1393 ) )
return NULL ;
return F_287 ( V_7 , NULL , V_1379 ,
V_7 -> V_1393 -> V_498 ,
V_7 -> V_1393 -> V_499 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_393 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1393 ) ) {
F_288 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
return F_76 ( V_32 , V_7 -> V_1393 ) ;
}
static int F_394 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_1667 * V_1668 = NULL ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
T_2 * V_46 , V_47 , V_1669 , V_1670 , V_1671 ;
int V_490 ;
if ( ! V_7 -> V_345 -> V_438 )
return - V_534 ;
if ( V_30 -> V_5 [ V_1672 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1672 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1672 ] ) ;
if ( V_47 % 2 || V_47 < V_1673 ||
V_47 > V_1674 )
return - V_16 ;
V_1668 = F_38 ( sizeof( struct V_1667 ) , V_135 ) ;
if ( ! V_1668 )
return - V_136 ;
V_1669 = ( V_47 - V_1673 ) >> 1 ;
if ( V_1669 ) {
V_1670 = V_1669 *
sizeof( struct V_1675 ) ;
memcpy ( V_1668 -> V_1676 , V_46 , V_1670 ) ;
V_1668 -> V_1669 = V_1669 ;
for ( V_1671 = 0 ; V_1671 < V_1669 ; V_1671 ++ ) {
if ( V_1668 -> V_1676 [ V_1671 ] . V_1677 > 7 ) {
F_41 ( V_1668 ) ;
return - V_16 ;
}
}
V_46 += V_1670 ;
}
memcpy ( V_1668 -> V_1677 , V_46 , V_1673 ) ;
}
F_112 ( V_533 -> V_28 ) ;
V_490 = F_42 ( V_533 -> V_28 ) ;
if ( ! V_490 )
V_490 = F_395 ( V_7 , V_533 , V_1668 ) ;
F_114 ( V_533 -> V_28 ) ;
F_41 ( V_1668 ) ;
return V_490 ;
}
static int F_396 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
const T_2 * V_1422 ;
T_2 V_1678 , V_1677 ;
T_3 V_1679 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_291 & V_440 ) )
return - V_534 ;
if ( ! V_30 -> V_5 [ V_1680 ] || ! V_30 -> V_5 [ V_541 ] ||
! V_30 -> V_5 [ V_1681 ] )
return - V_16 ;
V_1678 = F_34 ( V_30 -> V_5 [ V_1680 ] ) ;
if ( V_1678 >= V_857 )
return - V_16 ;
V_1677 = F_34 ( V_30 -> V_5 [ V_1681 ] ) ;
if ( V_1677 >= V_1682 )
return - V_16 ;
if ( V_1678 >= V_1683 ) {
return - V_16 ;
}
V_1422 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_30 -> V_5 [ V_1684 ] ) {
V_1679 =
F_78 ( V_30 -> V_5 [ V_1684 ] ) ;
if ( ! V_1679 )
return - V_16 ;
}
F_112 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1225 ;
goto V_591;
default:
V_35 = - V_534 ;
goto V_591;
}
V_35 = F_397 ( V_7 , V_533 , V_1678 , V_1422 , V_1677 , V_1679 ) ;
V_591:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_398 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
const T_2 * V_1422 ;
T_2 V_1678 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1680 ] || ! V_30 -> V_5 [ V_541 ] )
return - V_16 ;
V_1678 = F_34 ( V_30 -> V_5 [ V_1680 ] ) ;
V_1422 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
F_112 ( V_17 ) ;
V_35 = F_399 ( V_7 , V_533 , V_1678 , V_1422 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_400 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_513 V_514 = {} ;
const T_2 * V_669 ;
T_2 V_1685 ;
int V_35 ;
if ( ! V_7 -> V_345 -> V_1686 ||
! ( V_7 -> V_18 . V_291 & V_1687 ) )
return - V_534 ;
switch ( V_533 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_534 ;
}
if ( ! V_30 -> V_5 [ V_541 ] ||
! V_30 -> V_5 [ V_1688 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_514 ) ;
if ( V_35 )
return V_35 ;
if ( V_514 . V_55 -> V_290 == V_1689 &&
V_514 . V_517 != V_518 &&
V_514 . V_517 != V_573 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_514 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( F_252 ( V_17 -> V_18 , & V_514 , V_17 -> V_141 ) )
return - V_16 ;
V_669 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
V_1685 = F_34 ( V_30 -> V_5 [ V_1688 ] ) ;
F_112 ( V_17 ) ;
V_35 = F_401 ( V_7 , V_533 , V_669 , V_1685 , & V_514 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_402 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_497 [ 0 ] ;
struct V_25 * V_533 = V_30 -> V_497 [ 1 ] ;
struct V_1 * V_17 = V_533 -> V_28 ;
const T_2 * V_669 ;
if ( ! V_7 -> V_345 -> V_1686 ||
! V_7 -> V_345 -> V_1690 ||
! ( V_7 -> V_18 . V_291 & V_1687 ) )
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
V_669 = F_23 ( V_30 -> V_5 [ V_541 ] ) ;
F_112 ( V_17 ) ;
F_403 ( V_7 , V_533 , V_669 ) ;
F_114 ( V_17 ) ;
return 0 ;
}
static int F_404 ( const struct V_1691 * V_345 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_533 ;
bool V_1692 = V_345 -> V_1693 & V_1694 ;
if ( V_1692 )
F_14 () ;
if ( V_345 -> V_1693 & V_1695 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1692 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_497 [ 0 ] = V_7 ;
} else if ( V_345 -> V_1693 & V_1696 ||
V_345 -> V_1693 & V_1697 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1692 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_533 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_345 -> V_1693 & V_1696 ) {
if ( ! V_533 ) {
if ( V_1692 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_497 [ 1 ] = V_533 ;
} else {
V_30 -> V_497 [ 1 ] = V_17 ;
}
if ( V_533 ) {
if ( V_345 -> V_1693 & V_1698 &&
! F_91 ( V_533 ) ) {
if ( V_1692 )
F_20 () ;
return - V_548 ;
}
F_240 ( V_533 ) ;
} else if ( V_345 -> V_1693 & V_1698 ) {
if ( ! V_17 -> V_1641 ) {
if ( V_1692 )
F_20 () ;
return - V_548 ;
}
}
V_30 -> V_497 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_405 ( const struct V_1691 * V_345 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_497 [ 1 ] ) {
if ( V_345 -> V_1693 & V_1697 ) {
struct V_1 * V_17 = V_30 -> V_497 [ 1 ] ;
if ( V_17 -> V_19 )
F_171 ( V_17 -> V_19 ) ;
} else {
F_171 ( V_30 -> V_497 [ 1 ] ) ;
}
}
if ( V_345 -> V_1693 & V_1694 )
F_20 () ;
if ( V_345 -> V_1693 & V_1699 ) {
struct V_1700 * V_36 = F_406 ( V_32 ) ;
memset ( F_407 ( V_36 ) , 0 , F_408 ( V_36 ) ) ;
}
}
void F_409 ( struct V_6 * V_7 ,
enum V_280 V_52 )
{
struct V_31 * V_53 ;
struct V_281 V_282 = {} ;
F_59 ( V_52 != V_295 &&
V_52 != V_1701 ) ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_632 , V_135 ) ;
}
static int F_410 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1169 * V_1341 = V_7 -> V_1173 ;
struct V_4 * V_1702 ;
int V_159 ;
if ( F_59 ( ! V_1341 ) )
return 0 ;
V_1702 = F_47 ( V_53 , V_1177 ) ;
if ( ! V_1702 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1341 -> V_1171 ; V_159 ++ ) {
if ( F_51 ( V_53 , V_159 , V_1341 -> V_1178 [ V_159 ] . V_584 , V_1341 -> V_1178 [ V_159 ] . V_586 ) )
goto V_61;
}
F_48 ( V_53 , V_1702 ) ;
V_1702 = F_47 ( V_53 , V_1176 ) ;
if ( ! V_1702 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1341 -> V_360 ; V_159 ++ ) {
if ( F_28 ( V_53 , V_159 , V_1341 -> V_361 [ V_159 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1702 ) ;
if ( V_1341 -> V_1123 &&
F_51 ( V_53 , V_675 , V_1341 -> V_1124 , V_1341 -> V_1123 ) )
goto V_61;
if ( V_1341 -> V_51 &&
F_28 ( V_53 , V_1182 , V_1341 -> V_51 ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_411 ( struct V_31 * V_53 ,
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
F_410 ( V_53 , V_7 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_489 ;
}
static int
F_412 ( struct V_31 * V_53 ,
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
void F_239 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_411 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1703 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1704 , V_135 ) ;
}
struct V_31 * F_413 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1705 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_411 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1705 ? V_1706 :
V_1249 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_414 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1704 , V_135 ) ;
}
void F_415 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_412 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1707 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1704 , V_135 ) ;
}
void F_246 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_412 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1704 , V_135 ) ;
}
static bool F_416 ( struct V_31 * V_53 ,
struct V_1708 * V_1170 )
{
if ( F_56 ( V_53 , V_1709 , V_1170 -> V_1423 ) )
goto V_61;
if ( V_1170 -> V_1137 [ 0 ] == '0' && V_1170 -> V_1137 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1710 ,
V_1711 ) )
goto V_61;
} else if ( V_1170 -> V_1137 [ 0 ] == '9' && V_1170 -> V_1137 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1710 ,
V_1712 ) )
goto V_61;
} else if ( ( V_1170 -> V_1137 [ 0 ] == '9' && V_1170 -> V_1137 [ 1 ] == '8' ) ||
V_1170 -> V_1713 ) {
if ( F_56 ( V_53 , V_1710 ,
V_1714 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1710 ,
V_1715 ) ||
F_60 ( V_53 , V_1033 ,
V_1170 -> V_1137 ) )
goto V_61;
}
if ( V_1170 -> V_14 != V_1716 ) {
struct V_18 * V_18 = F_19 ( V_1170 -> V_14 ) ;
if ( V_18 &&
F_28 ( V_53 , V_26 , V_1170 -> V_14 ) )
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
void F_417 ( enum V_280 V_1717 ,
struct V_1708 * V_1170 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1717 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_416 ( V_53 , V_1170 ) == false )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_418 ( & V_38 , V_53 , 0 ,
V_1718 , V_1719 ) ;
F_221 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_419 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1480 , T_11 V_47 ,
enum V_280 V_52 , T_13 V_1380 ,
int V_910 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1477 , V_47 , V_1480 ) )
goto V_61;
if ( V_910 >= 0 ) {
struct V_4 * V_1720 =
F_47 ( V_53 , V_907 ) ;
if ( ! V_1720 )
goto V_61;
if ( F_56 ( V_53 , V_909 ,
V_910 ) )
goto V_61;
F_48 ( V_53 , V_1720 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_420 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1480 ,
T_11 V_47 , T_13 V_1380 )
{
F_419 ( V_7 , V_19 , V_1480 , V_47 ,
V_696 , V_1380 , - 1 ) ;
}
void F_421 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1480 ,
T_11 V_47 , T_13 V_1380 , int V_910 )
{
F_419 ( V_7 , V_19 , V_1480 , V_47 ,
V_1722 , V_1380 , V_910 ) ;
}
void F_422 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1480 ,
T_11 V_47 , T_13 V_1380 )
{
F_419 ( V_7 , V_19 , V_1480 , V_47 ,
V_1723 , V_1380 , - 1 ) ;
}
void F_423 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1480 ,
T_11 V_47 , T_13 V_1380 )
{
F_419 ( V_7 , V_19 , V_1480 , V_47 ,
V_1724 , V_1380 , - 1 ) ;
}
void F_424 ( struct V_25 * V_533 , const T_2 * V_1480 ,
T_11 V_47 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1725 * V_1726 = ( void * ) V_1480 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_425 ( V_1726 -> V_1727 ) )
V_52 = V_1728 ;
else
V_52 = V_1729 ;
F_426 ( V_533 , V_1480 , V_47 ) ;
F_419 ( V_7 , V_533 , V_1480 , V_47 , V_52 , V_1719 , - 1 ) ;
}
static void F_427 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_669 , T_13 V_1380 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1730 ) ||
F_51 ( V_53 , V_541 , V_581 , V_669 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_428 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_669 ,
T_13 V_1380 )
{
F_427 ( V_7 , V_19 , V_696 ,
V_669 , V_1380 ) ;
}
void F_429 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_669 ,
T_13 V_1380 )
{
F_427 ( V_7 , V_19 , V_1722 ,
V_669 , V_1380 ) ;
}
void F_430 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
const T_2 * V_1731 , T_11 V_1732 ,
const T_2 * V_1733 , T_11 V_1734 ,
T_3 V_633 , T_13 V_1380 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
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
F_55 ( V_53 , V_1425 , V_633 ) ||
( V_1731 &&
F_51 ( V_53 , V_1735 , V_1732 , V_1731 ) ) ||
( V_1733 &&
F_51 ( V_53 , V_1736 , V_1734 , V_1733 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_431 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
const T_2 * V_1731 , T_11 V_1732 ,
const T_2 * V_1733 , T_11 V_1734 , T_13 V_1380 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1737 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_540 ) ||
( V_1731 &&
F_51 ( V_53 , V_1735 , V_1732 , V_1731 ) ) ||
( V_1733 &&
F_51 ( V_53 , V_1736 , V_1734 , V_1733 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_432 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1405 ,
const T_2 * V_1123 , T_11 V_1124 , bool V_1738 )
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
( V_1738 && V_1405 &&
F_55 ( V_53 , V_954 , V_1405 ) ) ||
( V_1738 &&
F_29 ( V_53 , V_1739 ) ) ||
( V_1123 && F_51 ( V_53 , V_675 , V_1124 , V_1123 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_433 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
T_13 V_1380 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1740 ) ;
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
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_434 ( struct V_25 * V_533 , const T_2 * V_669 ,
const T_2 * V_1123 , T_2 V_1124 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_435 ( V_533 , V_669 ) ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1741 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_669 ) ||
( V_1124 && V_1123 &&
F_51 ( V_53 , V_675 , V_1124 , V_1123 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_436 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_669 ,
enum V_1742 V_1743 , int V_1744 ,
const T_2 * V_1745 , T_13 V_1380 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1746 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_669 && F_51 ( V_53 , V_541 , V_581 , V_669 ) ) ||
F_28 ( V_53 , V_127 , V_1743 ) ||
( V_1744 != - 1 &&
F_56 ( V_53 , V_123 , V_1744 ) ) ||
( V_1745 && F_51 ( V_53 , V_122 , 6 , V_1745 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_437 ( struct V_18 * V_18 ,
struct V_54 * V_1747 ,
struct V_54 * V_1748 )
{
struct V_31 * V_53 ;
void * V_283 ;
struct V_4 * V_287 ;
V_53 = F_74 ( V_592 , V_1719 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1749 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
V_287 = F_47 ( V_53 , V_1750 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1747 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
V_287 = F_47 ( V_53 , V_1751 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1748 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_418 ( & V_38 , V_53 , 0 ,
V_1718 , V_1719 ) ;
F_221 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_438 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_639 ,
struct V_54 * V_55 ,
unsigned int V_1432 , T_13 V_1380 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
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
F_104 ( V_53 , V_1436 , V_639 ) )
goto V_61;
if ( V_52 == V_1435 &&
F_28 ( V_53 , V_1433 , V_1432 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_439 ( struct V_1 * V_17 , T_1 V_639 ,
struct V_54 * V_55 ,
unsigned int V_1432 , T_13 V_1380 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_440 ( V_17 , V_639 , V_55 , V_1432 ) ;
F_438 ( V_1435 ,
V_7 , V_17 , V_639 , V_55 ,
V_1432 , V_1380 ) ;
}
void F_441 ( struct V_1 * V_17 , T_1 V_639 ,
struct V_54 * V_55 ,
T_13 V_1380 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_442 ( V_17 , V_639 , V_55 ) ;
F_438 ( V_1752 ,
V_7 , V_17 , V_639 , V_55 , 0 , V_1380 ) ;
}
void F_443 ( struct V_25 * V_533 , const T_2 * V_641 ,
struct V_780 * V_781 , T_13 V_1380 )
{
struct V_18 * V_18 = V_533 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_444 ( V_533 , V_641 , V_781 ) ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
if ( F_161 ( V_53 , V_875 , 0 , 0 , 0 ,
V_7 , V_533 , V_641 , V_781 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
}
void F_445 ( struct V_25 * V_533 , const T_2 * V_641 ,
struct V_780 * V_781 , T_13 V_1380 )
{
struct V_18 * V_18 = V_533 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_780 V_1753 = {} ;
if ( ! V_781 )
V_781 = & V_1753 ;
F_446 ( V_533 , V_641 ) ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
if ( F_161 ( V_53 , V_1754 , 0 , 0 , 0 ,
V_7 , V_533 , V_641 , V_781 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
}
void F_447 ( struct V_25 * V_533 , const T_2 * V_641 ,
enum V_1755 V_1405 ,
T_13 V_1380 )
{
struct V_18 * V_18 = V_533 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_1756 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1757 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_641 ) ||
F_28 ( V_53 , V_1758 , V_1405 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static bool F_448 ( struct V_25 * V_533 , T_2 V_52 ,
const T_2 * V_669 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1639 = F_449 ( V_17 -> V_1632 ) ;
if ( ! V_1639 )
return false ;
V_53 = F_74 ( 100 , V_1380 ) ;
if ( ! V_53 )
return true ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_669 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_450 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1639 ) ;
return true ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_451 ( struct V_25 * V_533 ,
const T_2 * V_669 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
bool V_490 ;
F_452 ( V_533 , V_669 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_453 ( false ) ;
return false ;
}
V_490 = F_448 ( V_533 , V_1759 ,
V_669 , V_1380 ) ;
F_453 ( V_490 ) ;
return V_490 ;
}
bool F_454 ( struct V_25 * V_533 ,
const T_2 * V_669 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
bool V_490 ;
F_455 ( V_533 , V_669 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_453 ( false ) ;
return false ;
}
V_490 = F_448 ( V_533 ,
V_1760 ,
V_669 , V_1380 ) ;
F_453 ( V_490 ) ;
return V_490 ;
}
int F_456 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1639 ,
int V_1761 , int V_1762 ,
const T_2 * V_1480 , T_11 V_47 , V_22 V_51 , T_13 V_1380 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1484 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_516 , V_1761 ) ||
( V_1762 &&
F_28 ( V_53 , V_1763 , V_1762 ) ) ||
F_51 ( V_53 , V_1477 , V_47 , V_1480 ) ||
( V_51 &&
F_28 ( V_53 , V_1764 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_450 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1639 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_457 ( struct V_1 * V_17 , T_1 V_639 ,
const T_2 * V_1480 , T_11 V_47 , bool V_1765 , T_13 V_1380 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
F_458 ( V_17 , V_639 , V_1765 ) ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1766 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1477 , V_47 , V_1480 ) ||
F_104 ( V_53 , V_1436 , V_639 ) ||
( V_1765 && F_29 ( V_53 , V_1767 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_459 ( struct V_25 * V_533 ,
const char * V_948 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_592 , V_1380 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1768 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) )
goto V_61;
if ( V_948 && F_51 ( V_53 , V_541 , V_581 , V_948 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1503 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_460 ( struct V_31 * V_53 , T_13 V_1380 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
}
void F_461 ( struct V_25 * V_533 ,
enum V_1769 V_1770 ,
T_13 V_1380 )
{
struct V_31 * V_53 ;
F_462 ( V_533 , V_1770 ) ;
if ( F_59 ( V_1770 != V_1771 &&
V_1770 != V_1772 ) )
return;
V_53 = F_459 ( V_533 , NULL , V_1380 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1773 ,
V_1770 ) )
goto V_61;
F_460 ( V_53 , V_1380 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_463 ( struct V_25 * V_533 ,
const T_2 * V_1422 , V_22 V_1774 ,
V_22 V_244 , V_22 V_1495 , T_13 V_1380 )
{
struct V_31 * V_53 ;
V_53 = F_459 ( V_533 , V_1422 , V_1380 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1508 , V_1774 ) )
goto V_61;
if ( F_28 ( V_53 , V_1507 , V_244 ) )
goto V_61;
if ( F_28 ( V_53 , V_1509 , V_1495 ) )
goto V_61;
F_460 ( V_53 , V_1380 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_464 ( struct V_25 * V_533 ,
const T_2 * V_1422 , V_22 V_1774 , T_13 V_1380 )
{
struct V_31 * V_53 ;
F_465 ( V_533 , V_1422 , V_1774 ) ;
V_53 = F_459 ( V_533 , V_1422 , V_1380 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1775 , V_1774 ) )
goto V_61;
F_460 ( V_53 , V_1380 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_466 ( struct V_25 * V_533 , T_13 V_1380 )
{
struct V_31 * V_53 ;
V_53 = F_459 ( V_533 , NULL , V_1380 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1776 ) )
goto V_61;
F_460 ( V_53 , V_1380 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_467 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_540 ,
const T_2 * V_1630 , T_13 V_1380 )
{
struct V_31 * V_53 ;
struct V_4 * V_1777 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1778 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_540 ) )
goto V_61;
V_1777 = F_47 ( V_53 , V_1618 ) ;
if ( ! V_1777 )
goto V_61;
if ( F_51 ( V_53 , V_1621 ,
V_1622 , V_1630 ) )
goto V_61;
F_48 ( V_53 , V_1777 ) ;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_468 ( struct V_25 * V_533 , const T_2 * V_540 ,
const T_2 * V_1630 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_469 ( V_533 , V_540 ) ;
F_467 ( V_7 , V_533 , V_540 , V_1630 , V_1380 ) ;
}
static void
F_470 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1779 ,
const T_2 * V_540 , bool V_1780 , T_13 V_1380 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1781 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1782 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1783 , V_1779 ) ||
F_51 ( V_53 , V_1784 , V_581 , V_540 ) ||
( V_1780 &&
F_29 ( V_53 , V_1785 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_471 ( struct V_25 * V_533 , int V_1779 ,
const T_2 * V_540 , bool V_1780 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_472 ( V_533 , V_1779 , V_540 , V_1780 ) ;
F_470 ( V_7 , V_533 , V_1779 , V_540 , V_1780 , V_1380 ) ;
}
static void F_473 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_513 * V_514 ,
T_13 V_1380 ,
enum V_280 V_1786 ,
T_2 V_1228 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1786 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_514 ) )
goto V_61;
if ( ( V_1786 == V_1787 ) &&
( F_28 ( V_53 , V_1226 , V_1228 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_474 ( struct V_25 * V_533 ,
struct V_513 * V_514 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_475 ( V_533 , V_514 ) ;
V_17 -> V_514 = * V_514 ;
V_17 -> V_539 = * V_514 ;
F_473 ( V_7 , V_533 , V_514 , V_135 ,
V_1788 , 0 ) ;
}
void F_476 ( struct V_25 * V_533 ,
struct V_513 * V_514 ,
T_2 V_1228 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_477 ( V_533 , V_514 ) ;
F_473 ( V_7 , V_533 , V_514 , V_135 ,
V_1787 , V_1228 ) ;
}
void
F_478 ( struct V_6 * V_7 ,
const struct V_513 * V_514 ,
enum V_1789 V_617 ,
struct V_25 * V_19 , T_13 V_1380 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1790 ) ;
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
if ( F_28 ( V_53 , V_1791 , V_617 ) )
goto V_61;
if ( F_101 ( V_53 , V_514 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_479 ( struct V_25 * V_533 , const T_2 * V_669 ,
T_1 V_639 , bool V_1792 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_480 ( V_533 , V_669 , V_639 , V_1792 ) ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1633 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_669 ) ||
F_104 ( V_53 , V_1436 , V_639 ) ||
( V_1792 && F_29 ( V_53 , V_1767 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_481 ( struct V_18 * V_18 ,
const T_2 * V_1793 , T_11 V_47 ,
int V_1761 , int V_1762 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
struct V_1634 * V_1635 ;
F_482 ( V_18 , V_1793 , V_47 , V_1761 , V_1762 ) ;
F_261 ( & V_7 -> V_1638 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1719 ) ;
if ( ! V_53 ) {
F_263 ( & V_7 -> V_1638 ) ;
return;
}
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1484 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1761 &&
F_28 ( V_53 , V_516 , V_1761 ) ) ||
( V_1762 &&
F_28 ( V_53 , V_1763 , V_1762 ) ) ||
F_51 ( V_53 , V_1477 , V_47 , V_1793 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_450 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1635 -> V_1639 ) ;
}
F_263 ( & V_7 -> V_1638 ) ;
return;
V_61:
F_263 ( & V_7 -> V_1638 ) ;
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_483 ( struct V_31 * V_53 ,
struct V_1794 * V_1795 )
{
struct V_1796 * V_1545 = V_1795 -> V_1797 ;
struct V_4 * V_1798 , * V_1799 , * V_286 ;
int V_159 , V_161 ;
V_1798 = F_47 (
V_53 , V_1800 ) ;
if ( ! V_1798 )
return - V_489 ;
for ( V_159 = 0 ; V_159 < V_1545 -> V_1801 ; V_159 ++ ) {
struct V_1802 * V_1547 = V_1545 -> V_1546 [ V_159 ] ;
V_1799 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1799 )
break;
if ( F_51 ( V_53 , V_585 , V_1547 -> V_586 . V_584 ,
V_1547 -> V_586 . V_586 ) ) {
F_484 ( V_53 , V_1799 ) ;
goto V_591;
}
if ( V_1547 -> V_360 ) {
V_286 = F_47 (
V_53 , V_1176 ) ;
if ( ! V_286 ) {
F_484 ( V_53 , V_1799 ) ;
goto V_591;
}
for ( V_161 = 0 ; V_161 < V_1547 -> V_360 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1547 -> V_361 [ V_161 ] ) ) {
F_484 ( V_53 , V_286 ) ;
F_484 ( V_53 , V_1799 ) ;
goto V_591;
}
}
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_1799 ) ;
}
V_591:
F_48 ( V_53 , V_1798 ) ;
return 0 ;
}
void F_485 ( struct V_1 * V_17 ,
struct V_1794 * V_1795 ,
T_13 V_1380 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
int V_1548 = 200 ;
F_486 ( V_17 -> V_18 , V_17 , V_1795 ) ;
if ( V_1795 )
V_1548 += V_1795 -> V_1803 ;
V_53 = F_74 ( V_1548 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1804 ) ;
if ( ! V_283 )
goto V_649;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_649;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_649;
if ( V_1795 ) {
struct V_4 * V_1805 ;
V_1805 = F_47 ( V_53 , V_1550 ) ;
if ( ! V_1805 )
goto V_649;
if ( V_1795 -> V_445 &&
F_29 ( V_53 , V_206 ) )
goto V_649;
if ( V_1795 -> V_1552 &&
F_29 ( V_53 , V_208 ) )
goto V_649;
if ( V_1795 -> V_1553 &&
F_29 ( V_53 , V_212 ) )
goto V_649;
if ( V_1795 -> V_1554 &&
F_29 ( V_53 , V_214 ) )
goto V_649;
if ( V_1795 -> V_1555 &&
F_29 ( V_53 , V_216 ) )
goto V_649;
if ( V_1795 -> V_1556 &&
F_29 ( V_53 , V_218 ) )
goto V_649;
if ( V_1795 -> V_1806 >= 0 &&
F_28 ( V_53 , V_228 ,
V_1795 -> V_1806 ) )
goto V_649;
if ( V_1795 -> V_1807 &&
F_29 ( V_53 , V_1808 ) )
goto V_649;
if ( V_1795 -> V_1809 &&
F_29 ( V_53 , V_1810 ) )
goto V_649;
if ( V_1795 -> V_1811 &&
F_29 ( V_53 ,
V_1812 ) )
goto V_649;
if ( V_1795 -> V_1813 ) {
V_22 V_1814 = V_1815 ;
V_22 V_1816 = V_1817 ;
if ( ! V_1795 -> V_1818 ) {
V_1814 =
V_1819 ;
V_1816 =
V_1820 ;
}
if ( V_1795 -> V_1821 &&
F_28 ( V_53 , V_1816 , V_1795 -> V_1821 ) )
goto V_649;
if ( F_51 ( V_53 , V_1814 , V_1795 -> V_1803 ,
V_1795 -> V_1813 ) )
goto V_649;
}
if ( V_1795 -> V_1797 &&
F_483 ( V_53 , V_1795 ) )
goto V_649;
F_48 ( V_53 , V_1805 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_649:
F_75 ( V_53 ) ;
}
void F_487 ( struct V_25 * V_533 , const T_2 * V_1422 ,
enum V_1429 V_1822 ,
T_3 V_955 , T_13 V_1380 )
{
struct V_1 * V_17 = V_533 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_488 ( V_17 -> V_18 , V_533 , V_1422 , V_1822 ,
V_955 ) ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1823 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_533 -> V_20 ) ||
F_56 ( V_53 , V_1431 , V_1822 ) ||
F_51 ( V_53 , V_541 , V_581 , V_1422 ) ||
( V_955 > 0 &&
F_55 ( V_53 , V_954 , V_955 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_1380 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_489 ( struct V_1824 * V_1825 ,
unsigned long V_282 ,
void * V_1826 )
{
struct V_1827 * V_1828 = V_1826 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1634 * V_1635 , * V_24 ;
if ( V_282 != V_1829 )
return V_1830 ;
F_219 () ;
F_490 (rdev, &cfg80211_rdev_list, list) {
bool V_1831 = false ;
bool V_1832 = false ;
struct V_1191 * V_1212 =
F_220 ( V_7 -> V_1212 ) ;
if ( V_1212 && V_1828 -> V_49 &&
V_1212 -> V_624 == V_1828 -> V_49 )
V_1832 = true ;
F_490 (wdev, &rdev->wdev_list, list) {
F_491 ( V_17 , V_1828 -> V_49 ) ;
if ( V_17 -> V_624 == V_1828 -> V_49 )
V_1831 = true ;
}
F_261 ( & V_7 -> V_1638 ) ;
F_492 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1635 -> V_1639 == V_1828 -> V_49 ) {
F_493 ( & V_1635 -> V_630 ) ;
F_41 ( V_1635 ) ;
break;
}
}
F_263 ( & V_7 -> V_1638 ) ;
if ( V_1831 ) {
struct V_1833 * V_1834 ;
V_1834 = F_38 ( sizeof( * V_1834 ) , V_1719 ) ;
if ( V_1834 ) {
V_1834 -> V_1639 = V_1828 -> V_49 ;
F_494 ( & V_7 -> V_1835 ) ;
F_377 ( & V_1834 -> V_630 , & V_7 -> V_1836 ) ;
F_495 ( & V_7 -> V_1835 ) ;
F_496 ( & V_7 -> V_1837 ) ;
}
} else if ( V_1832 ) {
V_1212 -> V_624 = 0 ;
if ( V_7 -> V_345 -> V_1214 &&
V_7 -> V_18 . V_51 & V_416 )
F_496 ( & V_7 -> V_1838 ) ;
}
}
F_221 () ;
F_497 ( V_1828 -> V_49 ) ;
return V_1839 ;
}
void F_498 ( struct V_25 * V_19 ,
struct V_1840 * V_1841 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_499 ( V_18 , V_19 , V_1841 ) ;
if ( ! V_1841 -> V_1842 )
return;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1843 ) ;
if ( ! V_283 )
goto V_591;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_541 , V_581 , V_1841 -> V_1842 ) )
goto V_591;
if ( V_1841 -> V_1247 &&
F_51 ( V_53 , V_675 , V_1841 -> V_1844 , V_1841 -> V_1247 ) )
goto V_591;
if ( V_1841 -> V_1845 &&
F_51 ( V_53 , V_1846 , V_1841 -> V_1847 ,
V_1841 -> V_1845 ) )
goto V_591;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1721 , V_135 ) ;
return;
V_591:
F_75 ( V_53 ) ;
}
void F_500 ( struct V_1 * V_17 , T_13 V_1380 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1639 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1656 )
return;
V_1639 = V_7 -> V_1656 ;
V_7 -> V_1656 = 0 ;
V_53 = F_74 ( V_592 , V_1380 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1848 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_450 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1639 ) ;
return;
V_61:
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_501 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_592 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1849 ) ;
if ( ! V_283 )
goto V_591;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_591;
F_66 ( V_53 , V_283 ) ;
F_125 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1721 , V_135 ) ;
return;
V_591:
F_75 ( V_53 ) ;
}
int F_502 ( void )
{
int V_35 ;
V_35 = F_503 ( & V_38 , V_1850 ,
V_1851 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_504 ( & V_1852 ) ;
if ( V_35 )
goto V_1853;
return 0 ;
V_1853:
F_505 ( & V_38 ) ;
return V_35 ;
}
void F_506 ( void )
{
F_507 ( & V_1852 ) ;
F_505 ( & V_38 ) ;
}
