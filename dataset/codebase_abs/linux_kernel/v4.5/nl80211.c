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
V_282 -> V_297 = 0 ;
break;
}
V_296:
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_281 * V_282 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_496 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_496 )
return 0 ;
V_282 -> V_336 = V_95 [ V_497 ] ;
if ( V_95 [ V_26 ] )
V_282 -> V_498 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_282 -> V_498 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
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
V_282 -> V_498 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_496 ;
struct V_281 * V_282 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_282 ) {
V_282 = F_38 ( sizeof( * V_282 ) , V_135 ) ;
if ( ! V_282 ) {
F_20 () ;
return - V_136 ;
}
V_282 -> V_498 = - 1 ;
V_496 = F_68 ( V_32 , V_34 , V_282 ) ;
if ( V_496 ) {
F_41 ( V_282 ) ;
F_20 () ;
return V_496 ;
}
V_34 -> args [ 0 ] = ( long ) V_282 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_282 -> V_499 )
continue;
if ( V_282 -> V_498 != - 1 &&
V_282 -> V_498 != V_7 -> V_14 )
continue;
do {
V_496 = F_58 ( V_7 , V_295 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 ,
V_501 , V_282 ) ;
if ( V_496 < 0 ) {
if ( ( V_496 == - V_91 || V_496 == - V_495 ) &&
! V_32 -> V_47 && ! V_282 -> V_336 &&
V_34 -> V_502 < 4096 ) {
V_34 -> V_502 = 4096 ;
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
V_282 -> V_499 = V_105 ;
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
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_281 V_282 = {} ;
V_53 = F_74 ( 4096 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_58 ( V_7 , V_295 , V_53 ,
V_30 -> V_504 , V_30 -> V_505 , 0 ,
& V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_506 * V_507 )
{
if ( ! V_95 [ V_508 ] || ! V_95 [ V_509 ] ||
! V_95 [ V_510 ] || ! V_95 [ V_511 ] ||
! V_95 [ V_512 ] )
return - V_16 ;
V_507 -> V_513 = F_34 ( V_95 [ V_508 ] ) ;
V_507 -> V_514 = F_78 ( V_95 [ V_509 ] ) ;
V_507 -> V_515 = F_78 ( V_95 [ V_510 ] ) ;
V_507 -> V_516 = F_78 ( V_95 [ V_511 ] ) ;
V_507 -> V_517 = F_34 ( V_95 [ V_512 ] ) ;
if ( V_507 -> V_513 >= V_518 )
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
struct V_519 * V_520 )
{
V_22 V_521 ;
if ( ! V_30 -> V_5 [ V_522 ] )
return - V_16 ;
V_521 = F_4 ( V_30 -> V_5 [ V_522 ] ) ;
V_520 -> V_55 = F_45 ( & V_7 -> V_18 , V_521 ) ;
V_520 -> V_523 = V_524 ;
V_520 -> V_525 = V_521 ;
V_520 -> V_526 = 0 ;
if ( ! V_520 -> V_55 || V_520 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_527 ] ) {
enum V_528 V_529 ;
V_529 = F_4 (
V_30 -> V_5 [ V_527 ] ) ;
switch ( V_529 ) {
case V_530 :
case V_531 :
case V_532 :
case V_533 :
F_81 ( V_520 , V_520 -> V_55 ,
V_529 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_534 ] ) {
V_520 -> V_523 =
F_4 ( V_30 -> V_5 [ V_534 ] ) ;
if ( V_30 -> V_5 [ V_535 ] )
V_520 -> V_525 =
F_4 (
V_30 -> V_5 [ V_535 ] ) ;
if ( V_30 -> V_5 [ V_536 ] )
V_520 -> V_526 =
F_4 (
V_30 -> V_5 [ V_536 ] ) ;
}
if ( ! F_82 ( V_520 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_520 ,
V_62 ) )
return - V_16 ;
if ( ( V_520 -> V_523 == V_537 ||
V_520 -> V_523 == V_538 ) &&
! ( V_7 -> V_18 . V_51 & V_475 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_539 ,
struct V_29 * V_30 )
{
struct V_519 V_520 ;
int V_8 ;
enum V_272 V_141 = V_153 ;
struct V_1 * V_17 = NULL ;
if ( V_539 )
V_17 = V_539 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_540 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_85 ( & V_7 -> V_18 , & V_520 ,
V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_541 ) {
if ( ! V_539 || ! V_7 -> V_351 -> V_542 ||
! ( V_7 -> V_18 . V_291 &
V_543 ) ) {
V_8 = - V_544 ;
break;
}
if ( V_520 . V_55 != V_17 -> V_545 . V_55 ) {
V_8 = - V_544 ;
break;
}
V_8 = F_86 ( V_7 , V_539 , & V_520 ) ;
if ( V_8 )
break;
}
V_17 -> V_545 = V_520 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_87 ( V_7 , V_17 , & V_520 ) ;
break;
case V_153 :
V_8 = F_88 ( V_7 , & V_520 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_503 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
const T_2 * V_546 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( F_91 ( V_539 ) )
return - V_544 ;
if ( ! V_7 -> V_351 -> V_416 )
return - V_540 ;
if ( V_17 -> V_141 != V_155 )
return - V_540 ;
V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
return F_92 ( V_7 , V_539 , V_546 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_548 = 0 ;
struct V_4 * V_549 ;
V_22 V_550 ;
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
if ( V_30 -> V_5 [ V_551 ] ) {
struct V_506 V_507 ;
struct V_4 * V_95 [ V_552 + 1 ] ;
if ( ! V_7 -> V_351 -> V_553 )
return - V_540 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_554 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_552 ,
F_23 ( V_549 ) ,
F_24 ( V_549 ) ,
V_555 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_507 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_507 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_522 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_556 ] ) {
struct V_1 * V_557 = V_17 ;
enum V_558 type ;
int V_105 , V_559 = 0 ;
if ( ! ( V_7 -> V_18 . V_291 & V_560 ) )
V_557 = NULL ;
if ( ! V_7 -> V_351 -> V_561 )
return - V_540 ;
V_105 = V_556 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_562 ] &&
( type != V_563 ) )
return - V_16 ;
if ( type != V_563 ) {
V_105 = V_562 ;
V_559 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_557 , type , V_559 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_356 ] &&
V_30 -> V_5 [ V_357 ] ) {
V_22 V_353 , V_354 ;
if ( ( ! V_7 -> V_18 . V_345 &&
! V_7 -> V_18 . V_347 ) ||
! V_7 -> V_351 -> V_564 )
return - V_540 ;
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
V_550 = 0 ;
if ( V_30 -> V_5 [ V_298 ] ) {
V_299 = F_34 (
V_30 -> V_5 [ V_298 ] ) ;
if ( V_299 == 0 )
return - V_16 ;
V_550 |= V_565 ;
}
if ( V_30 -> V_5 [ V_300 ] ) {
V_301 = F_34 (
V_30 -> V_5 [ V_300 ] ) ;
if ( V_301 == 0 )
return - V_16 ;
V_550 |= V_566 ;
}
if ( V_30 -> V_5 [ V_302 ] ) {
V_303 = F_4 (
V_30 -> V_5 [ V_302 ] ) ;
if ( V_303 < 256 )
return - V_16 ;
if ( V_303 != ( V_22 ) - 1 ) {
V_303 &= ~ 0x1 ;
}
V_550 |= V_567 ;
}
if ( V_30 -> V_5 [ V_304 ] ) {
V_305 = F_4 (
V_30 -> V_5 [ V_304 ] ) ;
V_550 |= V_568 ;
}
if ( V_30 -> V_5 [ V_306 ] ) {
if ( V_30 -> V_5 [ V_569 ] )
return - V_16 ;
V_307 = F_34 (
V_30 -> V_5 [ V_306 ] ) ;
V_550 |= V_570 ;
}
if ( V_30 -> V_5 [ V_569 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_571 ) )
return - V_540 ;
V_550 |= V_572 ;
}
if ( V_550 ) {
T_2 V_573 , V_574 ;
V_22 V_575 , V_576 ;
T_2 V_577 ;
if ( ! V_7 -> V_351 -> V_578 )
return - V_540 ;
V_573 = V_7 -> V_18 . V_299 ;
V_574 = V_7 -> V_18 . V_301 ;
V_575 = V_7 -> V_18 . V_303 ;
V_576 = V_7 -> V_18 . V_305 ;
V_577 = V_7 -> V_18 . V_307 ;
if ( V_550 & V_565 )
V_7 -> V_18 . V_299 = V_299 ;
if ( V_550 & V_566 )
V_7 -> V_18 . V_301 = V_301 ;
if ( V_550 & V_567 )
V_7 -> V_18 . V_303 = V_303 ;
if ( V_550 & V_568 )
V_7 -> V_18 . V_305 = V_305 ;
if ( V_550 & V_570 )
V_7 -> V_18 . V_307 = V_307 ;
V_8 = F_100 ( V_7 , V_550 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_299 = V_573 ;
V_7 -> V_18 . V_301 = V_574 ;
V_7 -> V_18 . V_303 = V_575 ;
V_7 -> V_18 . V_305 = V_576 ;
V_7 -> V_18 . V_307 = V_577 ;
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
const struct V_519 * V_520 )
{
if ( F_59 ( ! F_82 ( V_520 ) ) )
return - V_16 ;
if ( F_28 ( V_53 , V_522 ,
V_520 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_520 -> V_523 ) {
case V_524 :
case V_579 :
case V_580 :
if ( F_28 ( V_53 , V_527 ,
F_102 ( V_520 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_534 , V_520 -> V_523 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_535 , V_520 -> V_525 ) )
return - V_91 ;
if ( V_520 -> V_526 &&
F_28 ( V_53 , V_536 , V_520 -> V_526 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_581 )
{
struct V_25 * V_539 = V_17 -> V_19 ;
T_2 V_52 = V_582 ;
void * V_283 ;
if ( V_581 )
V_52 = V_583 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( V_539 &&
( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_60 ( V_53 , V_584 , V_539 -> V_585 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_586 , V_17 -> V_141 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_547 , V_587 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_293 ,
V_7 -> V_588 ^
( V_294 << 2 ) ) )
goto V_61;
if ( V_7 -> V_351 -> V_589 ) {
int V_496 ;
struct V_519 V_520 ;
V_496 = F_106 ( V_7 , V_17 , & V_520 ) ;
if ( V_496 == 0 ) {
if ( F_101 ( V_53 , & V_520 ) )
goto V_61;
}
}
if ( V_7 -> V_351 -> V_590 ) {
int V_591 , V_496 ;
V_496 = F_107 ( V_7 , V_17 , & V_591 ) ;
if ( V_496 == 0 &&
F_28 ( V_53 , V_562 ,
F_31 ( V_591 ) ) )
goto V_61;
}
if ( V_17 -> V_592 ) {
if ( F_51 ( V_53 , V_593 , V_17 -> V_592 , V_17 -> V_594 ) )
goto V_61;
}
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_595 = 0 ;
int V_596 = 0 ;
int V_597 = V_34 -> args [ 0 ] ;
int V_598 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_595 < V_597 ) {
V_595 ++ ;
continue;
}
V_596 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_596 < V_598 ) {
V_596 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_7 , V_17 , false ) < 0 ) {
goto V_599;
}
V_596 ++ ;
}
V_595 ++ ;
}
V_599:
F_20 () ;
V_34 -> args [ 0 ] = V_595 ;
V_34 -> args [ 1 ] = V_596 ;
return V_32 -> V_47 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_103 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_110 ( struct V_4 * V_601 , V_22 * V_602 )
{
struct V_4 * V_51 [ V_603 + 1 ] ;
int V_604 ;
* V_602 = 0 ;
if ( ! V_601 )
return - V_16 ;
if ( F_33 ( V_51 , V_603 ,
V_601 , V_605 ) )
return - V_16 ;
for ( V_604 = 1 ; V_604 <= V_603 ; V_604 ++ )
if ( V_51 [ V_604 ] )
* V_602 |= ( 1 << V_604 ) ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_606 ,
enum V_272 V_141 )
{
if ( ! V_606 ) {
if ( V_19 && ( V_19 -> V_607 & V_608 ) )
return - V_544 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_51 & V_609 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_51 & V_610 )
return 0 ;
break;
default:
break;
}
return - V_540 ;
}
static int F_112 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_611 V_137 ;
int V_35 ;
enum V_272 V_612 , V_613 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
V_22 V_614 , * V_51 = NULL ;
bool V_615 = false ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_612 = V_613 = V_539 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_586 ] ) {
V_613 = F_4 ( V_30 -> V_5 [ V_586 ] ) ;
if ( V_612 != V_613 )
V_615 = true ;
if ( V_613 > V_616 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_617 ] ) {
struct V_1 * V_17 = V_539 -> V_28 ;
if ( V_613 != V_145 )
return - V_16 ;
if ( F_91 ( V_539 ) )
return - V_544 ;
F_113 ( V_17 ) ;
F_114 ( V_618 !=
V_619 ) ;
V_17 -> V_620 =
F_24 ( V_30 -> V_5 [ V_617 ] ) ;
memcpy ( V_17 -> V_594 , F_23 ( V_30 -> V_5 [ V_617 ] ) ,
V_17 -> V_620 ) ;
F_115 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_621 ] ) {
V_137 . V_606 = ! ! F_34 ( V_30 -> V_5 [ V_621 ] ) ;
V_615 = true ;
V_35 = F_111 ( V_7 , V_539 , V_137 . V_606 , V_613 ) ;
if ( V_35 )
return V_35 ;
} else {
V_137 . V_606 = - 1 ;
}
if ( V_30 -> V_5 [ V_622 ] ) {
if ( V_613 != V_153 )
return - V_16 ;
V_35 = F_110 ( V_30 -> V_5 [ V_622 ] ,
& V_614 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_614 ;
V_615 = true ;
}
if ( V_51 && ( * V_51 & V_623 ) &&
! ( V_7 -> V_18 . V_291 & V_624 ) )
return - V_540 ;
if ( V_615 )
V_35 = F_116 ( V_7 , V_539 , V_613 , V_51 , & V_137 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_137 . V_606 != - 1 )
V_539 -> V_28 -> V_606 = V_137 . V_606 ;
return V_35 ;
}
static int F_117 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_611 V_137 ;
struct V_1 * V_17 ;
struct V_31 * V_53 , * V_625 ;
int V_35 ;
enum V_272 type = V_151 ;
V_22 V_51 ;
F_118 ( V_7 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_584 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_586 ] ) {
type = F_4 ( V_30 -> V_5 [ V_586 ] ) ;
if ( type > V_616 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_369 ||
! ( V_7 -> V_18 . V_359 & ( 1 << type ) ) )
return - V_540 ;
if ( ( type == V_154 ||
V_7 -> V_18 . V_291 & V_626 ) &&
V_30 -> V_5 [ V_547 ] ) {
F_119 ( V_137 . V_627 , V_30 -> V_5 [ V_547 ] ,
V_587 ) ;
if ( ! F_120 ( V_137 . V_627 ) )
return - V_628 ;
}
if ( V_30 -> V_5 [ V_621 ] ) {
V_137 . V_606 = ! ! F_34 ( V_30 -> V_5 [ V_621 ] ) ;
V_35 = F_111 ( V_7 , NULL , V_137 . V_606 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_110 ( type == V_153 ?
V_30 -> V_5 [ V_622 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_623 ) &&
! ( V_7 -> V_18 . V_291 & V_624 ) )
return - V_540 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_17 = F_121 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_584 ] ) ,
V_629 , type , V_35 ? NULL : & V_51 ,
& V_137 ) ;
if ( F_59 ( ! V_17 ) ) {
F_75 ( V_53 ) ;
return - V_630 ;
} else if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_631 ] )
V_17 -> V_632 = V_30 -> V_504 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_617 ] )
break;
F_113 ( V_17 ) ;
F_114 ( V_618 !=
V_619 ) ;
V_17 -> V_620 =
F_24 ( V_30 -> V_5 [ V_617 ] ) ;
memcpy ( V_17 -> V_594 , F_23 ( V_30 -> V_5 [ V_617 ] ) ,
V_17 -> V_620 ) ;
F_115 ( V_17 ) ;
break;
case V_154 :
F_122 ( & V_17 -> V_633 ) ;
F_123 ( & V_17 -> V_634 ) ;
F_124 ( & V_17 -> V_635 ) ;
F_123 ( & V_17 -> V_636 ) ;
F_124 ( & V_17 -> V_637 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_125 ( & V_17 -> V_638 , & V_7 -> V_639 ) ;
V_7 -> V_588 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
V_625 = F_74 ( V_600 , V_135 ) ;
if ( V_625 ) {
if ( F_103 ( V_625 , 0 , 0 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_625 ) ;
goto V_599;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_625 , 0 , V_640 ,
V_135 ) ;
}
V_599:
return F_76 ( V_53 , V_30 ) ;
}
static int F_127 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
struct V_31 * V_53 ;
int V_641 ;
if ( ! V_7 -> V_351 -> V_642 )
return - V_540 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( V_53 && F_103 ( V_53 , 0 , 0 , 0 , V_7 , V_17 , true ) < 0 ) {
F_75 ( V_53 ) ;
V_53 = NULL ;
}
if ( ! V_17 -> V_19 )
V_30 -> V_503 [ 1 ] = NULL ;
V_641 = F_128 ( V_7 , V_17 ) ;
if ( V_641 >= 0 && V_53 )
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_640 ,
V_135 ) ;
else
F_75 ( V_53 ) ;
return V_641 ;
}
static int F_129 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_3 V_643 ;
if ( ! V_30 -> V_5 [ V_644 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_427 )
return - V_540 ;
V_643 = F_78 ( V_30 -> V_5 [ V_644 ] ) ;
return F_130 ( V_7 , V_539 , V_643 ) ;
}
static void F_131 ( void * V_165 , struct V_645 * V_137 )
{
struct V_4 * V_92 ;
struct V_646 * V_647 = V_165 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_647 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_647 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_647 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_647 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_647 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_647 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_647 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_647 -> V_53 , V_123 , V_647 -> V_105 ) )
goto V_61;
F_48 ( V_647 -> V_53 , V_92 ) ;
return;
V_61:
V_647 -> error = 1 ;
}
static int F_132 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 V_648 = 0 ;
const T_2 * V_649 = NULL ;
bool V_650 ;
struct V_646 V_647 = {
. error = 0 ,
} ;
void * V_283 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_648 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_648 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_547 ] )
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_650 = ! ! V_649 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_651 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_651 >= V_114 )
return - V_16 ;
if ( V_651 != V_652 &&
V_651 != V_653 )
return - V_16 ;
V_650 = V_651 == V_653 ;
}
if ( ! V_7 -> V_351 -> V_654 )
return - V_540 ;
if ( ! V_650 && V_649 && ! ( V_7 -> V_18 . V_51 & V_324 ) )
return - V_655 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_656 ) ;
if ( ! V_283 )
goto V_61;
V_647 . V_53 = V_53 ;
V_647 . V_105 = V_648 ;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_648 ) )
goto V_61;
if ( V_649 &&
F_51 ( V_53 , V_547 , V_587 , V_649 ) )
goto V_61;
V_35 = F_133 ( V_7 , V_539 , V_648 , V_650 , V_649 , & V_647 ,
F_131 ) ;
if ( V_35 )
goto V_657;
if ( V_647 . error )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_657:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_134 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_113 ( V_539 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_351 -> V_658 ) {
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_42 ( V_539 -> V_28 ) ;
if ( V_35 )
goto V_599;
V_35 = F_135 ( V_7 , V_539 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_599;
#ifdef F_136
V_539 -> V_28 -> V_659 . V_660 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_599;
}
if ( ! V_7 -> V_351 -> V_661 ) {
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_42 ( V_539 -> V_28 ) ;
if ( V_35 )
goto V_599;
V_35 = F_137 ( V_7 , V_539 , V_92 . V_105 ) ;
if ( V_35 )
goto V_599;
#ifdef F_136
V_539 -> V_28 -> V_659 . V_662 = V_92 . V_105 ;
#endif
}
V_599:
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static int F_138 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_649 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_547 ] )
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_649 )
V_92 . type = V_653 ;
else
V_92 . type = V_652 ;
}
if ( V_92 . type != V_653 &&
V_92 . type != V_652 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_373 )
return - V_540 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_653 ,
V_649 ) )
return - V_16 ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_42 ( V_539 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_139 ( V_7 , V_539 , V_92 . V_105 ,
V_92 . type == V_653 ,
V_649 , & V_92 . V_107 ) ;
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static int F_140 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_649 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_547 ] )
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_649 )
V_92 . type = V_653 ;
else
V_92 . type = V_652 ;
}
if ( V_92 . type != V_653 &&
V_92 . type != V_652 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_663 )
return - V_540 ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_42 ( V_539 -> V_28 ) ;
if ( V_92 . type == V_652 && V_649 &&
! ( V_7 -> V_18 . V_51 & V_324 ) )
V_35 = - V_655 ;
if ( ! V_35 )
V_35 = F_141 ( V_7 , V_539 , V_92 . V_105 ,
V_92 . type == V_653 ,
V_649 ) ;
#ifdef F_136
if ( ! V_35 ) {
if ( V_92 . V_105 == V_539 -> V_28 -> V_659 . V_660 )
V_539 -> V_28 -> V_659 . V_660 = - 1 ;
else if ( V_92 . V_105 == V_539 -> V_28 -> V_659 . V_662 )
V_539 -> V_28 -> V_659 . V_662 = - 1 ;
}
#endif
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static int F_142 ( struct V_4 * V_664 )
{
struct V_4 * V_45 ;
int V_665 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_587 )
return - V_16 ;
V_665 ++ ;
}
return V_665 ;
}
static struct V_666 * F_143 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_667 V_668 ;
struct V_4 * V_45 ;
struct V_666 * V_669 ;
int V_159 = 0 , V_665 , V_24 ;
if ( ! V_18 -> V_466 )
return F_3 ( - V_540 ) ;
if ( ! V_30 -> V_5 [ V_670 ] )
return F_3 ( - V_16 ) ;
V_668 = F_4 ( V_30 -> V_5 [ V_670 ] ) ;
if ( V_668 != V_671 &&
V_668 != V_672 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_673 ] )
return F_3 ( - V_16 ) ;
V_665 = F_142 ( V_30 -> V_5 [ V_673 ] ) ;
if ( V_665 < 0 )
return F_3 ( V_665 ) ;
if ( V_665 > V_18 -> V_466 )
return F_3 ( - V_674 ) ;
V_669 = F_38 ( sizeof( * V_669 ) + ( sizeof( struct V_675 ) * V_665 ) ,
V_135 ) ;
if ( ! V_669 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_669 -> V_676 [ V_159 ] . V_677 , F_23 ( V_45 ) , V_587 ) ;
V_159 ++ ;
}
V_669 -> V_678 = V_665 ;
V_669 -> V_668 = V_668 ;
return V_669 ;
}
static int F_144 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_666 * V_669 ;
int V_35 ;
if ( V_539 -> V_28 -> V_141 != V_142 &&
V_539 -> V_28 -> V_141 != V_144 )
return - V_540 ;
if ( ! V_539 -> V_28 -> V_541 )
return - V_16 ;
V_669 = F_143 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_669 ) )
return F_18 ( V_669 ) ;
V_35 = F_145 ( V_7 , V_539 , V_669 ) ;
F_41 ( V_669 ) ;
return V_35 ;
}
static int F_146 ( struct V_4 * V_5 [] ,
struct V_679 * V_680 )
{
bool V_681 = false ;
if ( ! F_22 ( V_5 [ V_682 ] ) ||
! F_22 ( V_5 [ V_683 ] ) ||
! F_22 ( V_5 [ V_684 ] ) ||
! F_22 ( V_5 [ V_685 ] ) )
return - V_16 ;
memset ( V_680 , 0 , sizeof( * V_680 ) ) ;
if ( V_5 [ V_686 ] ) {
V_680 -> V_687 = F_23 ( V_5 [ V_686 ] ) ;
V_680 -> V_688 = F_24 ( V_5 [ V_686 ] ) ;
if ( ! V_680 -> V_688 )
return - V_16 ;
V_681 = true ;
}
if ( V_5 [ V_682 ] ) {
V_680 -> V_689 = F_23 ( V_5 [ V_682 ] ) ;
V_680 -> V_690 = F_24 ( V_5 [ V_682 ] ) ;
V_681 = true ;
}
if ( ! V_681 )
return - V_16 ;
if ( V_5 [ V_683 ] ) {
V_680 -> V_691 = F_23 ( V_5 [ V_683 ] ) ;
V_680 -> V_692 = F_24 ( V_5 [ V_683 ] ) ;
}
if ( V_5 [ V_684 ] ) {
V_680 -> V_693 =
F_23 ( V_5 [ V_684 ] ) ;
V_680 -> V_694 =
F_24 ( V_5 [ V_684 ] ) ;
}
if ( V_5 [ V_685 ] ) {
V_680 -> V_695 =
F_23 ( V_5 [ V_685 ] ) ;
V_680 -> V_696 =
F_24 ( V_5 [ V_685 ] ) ;
}
if ( V_5 [ V_697 ] ) {
V_680 -> V_698 = F_23 ( V_5 [ V_697 ] ) ;
V_680 -> V_699 = F_24 ( V_5 [ V_697 ] ) ;
}
return 0 ;
}
static bool F_147 ( struct V_6 * V_7 ,
struct V_700 * V_137 )
{
struct V_1 * V_17 ;
bool V_496 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_545 . V_55 )
continue;
V_137 -> V_520 = V_17 -> V_545 ;
V_496 = true ;
break;
}
return V_496 ;
}
static bool F_148 ( struct V_6 * V_7 ,
enum V_701 V_702 ,
enum V_280 V_52 )
{
if ( V_702 > V_703 )
return false ;
switch ( V_52 ) {
case V_704 :
if ( ! ( V_7 -> V_18 . V_291 & V_705 ) &&
V_702 == V_706 )
return false ;
return true ;
case V_450 :
case V_707 :
if ( V_702 == V_706 )
return false ;
return true ;
default:
return false ;
}
}
static int F_149 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_700 V_137 ;
int V_35 ;
if ( V_539 -> V_28 -> V_141 != V_142 &&
V_539 -> V_28 -> V_141 != V_144 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_375 )
return - V_540 ;
if ( V_17 -> V_541 )
return - V_708 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_709 ] ||
! V_30 -> V_5 [ V_710 ] ||
! V_30 -> V_5 [ V_686 ] )
return - V_16 ;
V_35 = F_146 ( V_30 -> V_5 , & V_137 . V_711 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_541 =
F_4 ( V_30 -> V_5 [ V_709 ] ) ;
V_137 . V_712 =
F_4 ( V_30 -> V_5 [ V_710 ] ) ;
V_35 = F_150 ( V_7 , V_137 . V_541 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_593 ] ) {
V_137 . V_594 = F_23 ( V_30 -> V_5 [ V_593 ] ) ;
V_137 . V_592 =
F_24 ( V_30 -> V_5 [ V_593 ] ) ;
if ( V_137 . V_592 == 0 ||
V_137 . V_592 > V_618 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_713 ] ) {
V_137 . V_714 = F_4 (
V_30 -> V_5 [ V_713 ] ) ;
if ( V_137 . V_714 != V_715 &&
V_137 . V_714 != V_716 &&
V_137 . V_714 != V_717 )
return - V_16 ;
}
V_137 . V_718 = ! ! V_30 -> V_5 [ V_719 ] ;
if ( V_30 -> V_5 [ V_720 ] ) {
V_137 . V_702 = F_4 (
V_30 -> V_5 [ V_720 ] ) ;
if ( ! F_148 ( V_7 , V_137 . V_702 ,
V_707 ) )
return - V_16 ;
} else
V_137 . V_702 = V_721 ;
V_35 = F_151 ( V_7 , V_30 , & V_137 . V_722 ,
V_723 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_724 ] ) {
if ( ! ( V_7 -> V_18 . V_291 & V_725 ) )
return - V_540 ;
V_137 . V_726 = F_78 (
V_30 -> V_5 [ V_724 ] ) ;
}
if ( V_30 -> V_5 [ V_727 ] ) {
if ( V_539 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_728 =
F_34 ( V_30 -> V_5 [ V_727 ] ) ;
if ( V_137 . V_728 > 127 )
return - V_16 ;
if ( V_137 . V_728 != 0 &&
! ( V_7 -> V_18 . V_291 & V_729 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_730 ] ) {
T_2 V_24 ;
if ( V_539 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_730 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_731 = V_24 ;
if ( V_137 . V_731 != 0 &&
! ( V_7 -> V_18 . V_291 & V_732 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_522 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_520 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_545 . V_55 ) {
V_137 . V_520 = V_17 -> V_545 ;
} else if ( ! F_147 ( V_7 , & V_137 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_520 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_733 ] ) {
V_137 . V_734 =
F_34 ( V_30 -> V_5 [ V_733 ] ) ;
switch ( V_137 . V_734 ) {
case V_735 :
break;
case V_736 :
if ( ! ( V_7 -> V_18 . V_291 &
V_737 ) )
return - V_16 ;
break;
case V_738 :
if ( ! ( V_7 -> V_18 . V_291 &
V_739 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_137 . V_734 = V_735 ;
}
if ( V_30 -> V_5 [ V_670 ] ) {
V_137 . V_669 = F_143 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_669 ) )
return F_18 ( V_137 . V_669 ) ;
}
F_113 ( V_17 ) ;
V_35 = F_152 ( V_7 , V_539 , & V_137 ) ;
if ( ! V_35 ) {
V_17 -> V_545 = V_137 . V_520 ;
V_17 -> V_541 = V_137 . V_541 ;
V_17 -> V_520 = V_137 . V_520 ;
V_17 -> V_592 = V_137 . V_592 ;
memcpy ( V_17 -> V_594 , V_137 . V_594 , V_17 -> V_592 ) ;
}
F_115 ( V_17 ) ;
F_41 ( V_137 . V_669 ) ;
return V_35 ;
}
static int F_153 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_679 V_137 ;
int V_35 ;
if ( V_539 -> V_28 -> V_141 != V_142 &&
V_539 -> V_28 -> V_141 != V_144 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_740 )
return - V_540 ;
if ( ! V_17 -> V_541 )
return - V_16 ;
V_35 = F_146 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
V_35 = F_154 ( V_7 , V_539 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_155 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
return F_156 ( V_7 , V_539 , false ) ;
}
static int F_157 ( struct V_29 * V_30 ,
enum V_272 V_141 ,
struct V_741 * V_137 )
{
struct V_4 * V_51 [ V_742 + 1 ] ;
struct V_4 * V_601 ;
int V_604 ;
V_601 = V_30 -> V_5 [ V_743 ] ;
if ( V_601 ) {
struct V_744 * V_745 ;
V_745 = F_23 ( V_601 ) ;
V_137 -> V_746 = V_745 -> V_747 ;
V_137 -> V_748 = V_745 -> V_749 ;
V_137 -> V_748 &= V_137 -> V_746 ;
if ( ( V_137 -> V_746 |
V_137 -> V_748 ) & F_158 ( V_750 ) )
return - V_16 ;
return 0 ;
}
V_601 = V_30 -> V_5 [ V_751 ] ;
if ( ! V_601 )
return 0 ;
if ( F_33 ( V_51 , V_742 ,
V_601 , V_752 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_746 = F_158 ( V_753 ) |
F_158 ( V_754 ) |
F_158 ( V_755 ) |
F_158 ( V_756 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_746 = F_158 ( V_753 ) |
F_158 ( V_757 ) ;
break;
case V_145 :
V_137 -> V_746 = F_158 ( V_758 ) |
F_158 ( V_756 ) |
F_158 ( V_753 ) ;
default:
return - V_16 ;
}
for ( V_604 = 1 ; V_604 <= V_742 ; V_604 ++ ) {
if ( V_51 [ V_604 ] ) {
V_137 -> V_748 |= ( 1 << V_604 ) ;
if ( V_604 > V_759 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_159 ( struct V_31 * V_53 , struct V_760 * V_30 ,
int V_45 )
{
struct V_4 * V_244 ;
V_22 V_264 ;
T_3 V_761 ;
enum V_762 V_763 ;
V_244 = F_47 ( V_53 , V_45 ) ;
if ( ! V_244 )
return false ;
V_264 = F_160 ( V_30 ) ;
V_761 = V_264 < ( 1UL << 16 ) ? V_264 : 0 ;
if ( V_264 > 0 &&
F_28 ( V_53 , V_764 , V_264 ) )
return false ;
if ( V_761 > 0 &&
F_55 ( V_53 , V_765 , V_761 ) )
return false ;
switch ( V_30 -> V_766 ) {
case V_767 :
V_763 = V_768 ;
break;
case V_769 :
V_763 = V_770 ;
break;
default:
F_59 ( 1 ) ;
case V_771 :
V_763 = 0 ;
break;
case V_772 :
V_763 = V_773 ;
break;
case V_774 :
V_763 = V_775 ;
break;
case V_776 :
V_763 = V_777 ;
break;
}
if ( V_763 && F_29 ( V_53 , V_763 ) )
return false ;
if ( V_30 -> V_51 & V_778 ) {
if ( F_56 ( V_53 , V_779 , V_30 -> V_248 ) )
return false ;
if ( V_30 -> V_51 & V_780 &&
F_29 ( V_53 , V_781 ) )
return false ;
} else if ( V_30 -> V_51 & V_782 ) {
if ( F_56 ( V_53 , V_783 , V_30 -> V_248 ) )
return false ;
if ( F_56 ( V_53 , V_784 , V_30 -> V_785 ) )
return false ;
if ( V_30 -> V_51 & V_780 &&
F_29 ( V_53 , V_781 ) )
return false ;
}
F_48 ( V_53 , V_244 ) ;
return true ;
}
static bool F_161 ( struct V_31 * V_53 , T_2 V_747 , T_6 * signal ,
int V_786 )
{
void * V_45 ;
int V_159 = 0 ;
if ( ! V_747 )
return true ;
V_45 = F_47 ( V_53 , V_786 ) ;
if ( ! V_45 )
return false ;
for ( V_159 = 0 ; V_159 < V_787 ; V_159 ++ ) {
if ( ! ( V_747 & F_158 ( V_159 ) ) )
continue;
if ( F_56 ( V_53 , V_159 , signal [ V_159 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_162 ( struct V_31 * V_53 , V_22 V_52 , V_22 V_49 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_539 ,
const T_2 * V_649 , struct V_788 * V_789 )
{
void * V_283 ;
struct V_4 * V_790 , * V_791 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_649 ) ||
F_28 ( V_53 , V_293 , V_789 -> V_792 ) )
goto V_61;
V_790 = F_47 ( V_53 , V_793 ) ;
if ( ! V_790 )
goto V_61;
#define F_163 ( V_45 , T_7 , type ) do { \
if (sinfo->filled & BIT(NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
F_163 ( V_794 , V_795 , V_22 ) ;
F_163 ( V_796 , V_797 , V_22 ) ;
if ( V_789 -> V_798 & ( F_158 ( V_799 ) |
F_158 ( V_800 ) ) &&
F_28 ( V_53 , V_799 ,
( V_22 ) V_789 -> V_801 ) )
goto V_61;
if ( V_789 -> V_798 & ( F_158 ( V_802 ) |
F_158 ( V_803 ) ) &&
F_28 ( V_53 , V_802 ,
( V_22 ) V_789 -> V_804 ) )
goto V_61;
F_163 ( V_805 , V_801 , T_1 ) ;
F_163 ( V_806 , V_804 , T_1 ) ;
F_163 ( V_807 , V_808 , T_3 ) ;
F_163 ( V_809 , V_810 , T_3 ) ;
F_163 ( V_811 , V_812 , T_2 ) ;
switch ( V_7 -> V_18 . V_813 ) {
case V_814 :
F_163 ( SIGNAL , signal , T_2 ) ;
F_163 ( V_815 , V_816 , T_2 ) ;
break;
default:
break;
}
if ( V_789 -> V_798 & F_158 ( V_817 ) ) {
if ( ! F_161 ( V_53 , V_789 -> V_818 ,
V_789 -> V_819 ,
V_817 ) )
goto V_61;
}
if ( V_789 -> V_798 & F_158 ( V_820 ) ) {
if ( ! F_161 ( V_53 , V_789 -> V_818 ,
V_789 -> V_821 ,
V_820 ) )
goto V_61;
}
if ( V_789 -> V_798 & F_158 ( V_822 ) ) {
if ( ! F_159 ( V_53 , & V_789 -> V_823 ,
V_822 ) )
goto V_61;
}
if ( V_789 -> V_798 & F_158 ( V_824 ) ) {
if ( ! F_159 ( V_53 , & V_789 -> V_825 ,
V_824 ) )
goto V_61;
}
F_163 ( V_826 , V_827 , V_22 ) ;
F_163 ( V_828 , V_829 , V_22 ) ;
F_163 ( V_830 , V_831 , V_22 ) ;
F_163 ( V_832 , V_833 , V_22 ) ;
F_163 ( V_834 , V_835 , V_22 ) ;
F_163 ( V_836 , V_837 , V_22 ) ;
F_163 ( V_838 , V_839 , V_22 ) ;
F_163 ( V_840 , V_841 , V_22 ) ;
F_163 ( V_842 , V_843 , V_22 ) ;
if ( V_789 -> V_798 & F_158 ( V_844 ) ) {
V_791 = F_47 ( V_53 , V_844 ) ;
if ( ! V_791 )
goto V_61;
if ( ( ( V_789 -> V_791 . V_51 & V_845 ) &&
F_29 ( V_53 , V_846 ) ) ||
( ( V_789 -> V_791 . V_51 & V_847 ) &&
F_29 ( V_53 , V_848 ) ) ||
( ( V_789 -> V_791 . V_51 & V_849 ) &&
F_29 ( V_53 , V_850 ) ) ||
F_56 ( V_53 , V_851 ,
V_789 -> V_791 . V_712 ) ||
F_55 ( V_53 , V_852 ,
V_789 -> V_791 . V_541 ) )
goto V_61;
F_48 ( V_53 , V_791 ) ;
}
if ( ( V_789 -> V_798 & F_158 ( V_853 ) ) &&
F_51 ( V_53 , V_853 ,
sizeof( struct V_744 ) ,
& V_789 -> V_745 ) )
goto V_61;
F_163 ( V_854 , V_855 , T_1 ) ;
F_163 ( V_856 , V_857 , T_1 ) ;
F_163 ( V_858 , V_859 , T_1 ) ;
F_163 ( V_860 , V_861 , T_2 ) ;
#undef F_163
if ( V_789 -> V_798 & F_158 ( V_862 ) ) {
struct V_4 * V_863 ;
int V_864 ;
V_863 = F_47 ( V_53 , V_862 ) ;
if ( ! V_863 )
goto V_61;
for ( V_864 = 0 ; V_864 < V_865 + 1 ; V_864 ++ ) {
struct V_866 * V_867 ;
struct V_4 * V_868 ;
V_867 = & V_789 -> V_869 [ V_864 ] ;
if ( ! V_867 -> V_798 )
continue;
V_868 = F_47 ( V_53 , V_864 + 1 ) ;
if ( ! V_868 )
goto V_61;
#define F_164 ( V_45 , T_7 , type ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_ ## type(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb)) \
goto nla_put_failure; \
} while (0)
F_164 ( V_870 , V_871 , T_1 ) ;
F_164 ( V_872 , V_873 , T_1 ) ;
F_164 ( V_874 , V_875 , T_1 ) ;
F_164 ( V_876 , V_877 , T_1 ) ;
#undef F_164
F_48 ( V_53 , V_868 ) ;
}
F_48 ( V_53 , V_863 ) ;
}
F_48 ( V_53 , V_790 ) ;
if ( V_789 -> V_878 &&
F_51 ( V_53 , V_683 , V_789 -> V_878 ,
V_789 -> V_879 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_165 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_788 V_789 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_649 [ V_587 ] ;
int V_880 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_881;
}
if ( ! V_7 -> V_351 -> V_882 ) {
V_35 = - V_540 ;
goto V_881;
}
while ( 1 ) {
memset ( & V_789 , 0 , sizeof( V_789 ) ) ;
V_35 = F_166 ( V_7 , V_17 -> V_19 , V_880 ,
V_649 , & V_789 ) ;
if ( V_35 == - V_655 )
break;
if ( V_35 )
goto V_881;
if ( F_162 ( V_32 , V_883 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_7 , V_17 -> V_19 , V_649 ,
& V_789 ) < 0 )
goto V_599;
V_880 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_880 ;
V_35 = V_32 -> V_47 ;
V_881:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_167 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_788 V_789 ;
struct V_31 * V_53 ;
T_2 * V_649 = NULL ;
int V_35 ;
memset ( & V_789 , 0 , sizeof( V_789 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_884 )
return - V_540 ;
V_35 = F_168 ( V_7 , V_539 , V_649 , & V_789 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_162 ( V_53 , V_883 ,
V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_7 , V_539 , V_649 , & V_789 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_169 ( struct V_18 * V_18 ,
struct V_741 * V_137 ,
enum V_885 V_886 )
{
if ( V_137 -> V_887 != - 1 &&
V_886 != V_888 )
return - V_16 ;
if ( V_137 -> V_889 &&
! ( V_137 -> V_748 & F_158 ( V_757 ) ) &&
V_886 != V_888 )
return - V_16 ;
F_114 ( V_742 != 7 ) ;
switch ( V_886 ) {
case V_890 :
case V_891 :
if ( V_137 -> V_746 &
~ ( F_158 ( V_758 ) |
F_158 ( V_756 ) |
F_158 ( V_753 ) ) )
return - V_16 ;
break;
case V_892 :
case V_893 :
if ( ! ( V_137 -> V_748 & F_158 ( V_757 ) ) )
return - V_16 ;
V_137 -> V_746 &= ~ F_158 ( V_757 ) ;
break;
default:
if ( V_137 -> V_894 != V_895 )
return - V_16 ;
if ( V_137 -> V_839 )
return - V_16 ;
if ( V_137 -> V_896 & V_897 )
return - V_16 ;
}
if ( V_886 != V_892 &&
V_886 != V_893 ) {
if ( V_137 -> V_748 & F_158 ( V_757 ) )
return - V_16 ;
V_137 -> V_746 &= ~ F_158 ( V_757 ) ;
}
if ( V_886 != V_892 &&
V_886 != V_888 ) {
if ( V_137 -> V_896 & V_898 )
return - V_16 ;
if ( V_137 -> V_896 & V_899 )
return - V_16 ;
if ( V_137 -> V_900 )
return - V_16 ;
if ( V_137 -> V_901 || V_137 -> V_902 || V_137 -> V_903 )
return - V_16 ;
}
if ( V_886 != V_904 &&
V_886 != V_888 ) {
if ( V_137 -> V_905 )
return - V_16 ;
}
switch ( V_886 ) {
case V_906 :
if ( ! ( V_137 -> V_746 & F_158 ( V_753 ) ) )
return - V_540 ;
break;
case V_904 :
case V_888 :
if ( V_137 -> V_746 &
~ ( F_158 ( V_753 ) |
F_158 ( V_758 ) |
F_158 ( V_907 ) |
F_158 ( V_754 ) |
F_158 ( V_755 ) |
F_158 ( V_756 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_291 & V_908 ) &&
V_137 -> V_746 &
( F_158 ( V_758 ) |
F_158 ( V_907 ) ) )
return - V_16 ;
break;
case V_909 :
case V_910 :
if ( V_137 -> V_746 & ~ F_158 ( V_753 ) )
return - V_16 ;
break;
case V_892 :
if ( V_137 -> V_746 & ~ ( F_158 ( V_753 ) |
F_158 ( V_755 ) ) )
return - V_16 ;
if ( V_137 -> V_748 & F_158 ( V_753 ) &&
! V_137 -> V_900 )
return - V_16 ;
break;
case V_893 :
return - V_16 ;
case V_890 :
if ( V_137 -> V_896 & V_897 )
return - V_16 ;
break;
case V_891 :
if ( V_137 -> V_894 != V_895 &&
V_137 -> V_894 != V_911 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_170 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_912 = V_30 -> V_5 [ V_913 ] ;
struct V_25 * V_914 ;
int V_496 ;
if ( ! V_912 )
return NULL ;
V_914 = F_171 ( F_94 ( V_30 ) , F_4 ( V_912 ) ) ;
if ( ! V_914 )
return F_3 ( - V_23 ) ;
if ( ! V_914 -> V_28 || V_914 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_496 = - V_16 ;
goto error;
}
if ( V_914 -> V_28 -> V_141 != V_143 &&
V_914 -> V_28 -> V_141 != V_142 &&
V_914 -> V_28 -> V_141 != V_144 ) {
V_496 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_914 ) ) {
V_496 = - V_554 ;
goto error;
}
return V_914 ;
error:
F_172 ( V_914 ) ;
return F_3 ( V_496 ) ;
}
static int F_173 ( struct V_29 * V_30 ,
struct V_741 * V_137 )
{
struct V_4 * V_95 [ V_915 + 1 ] ;
struct V_4 * V_601 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_916 ] )
return 0 ;
V_601 = V_30 -> V_5 [ V_916 ] ;
V_35 = F_33 ( V_95 , V_915 , V_601 ,
V_917 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_918 ] )
V_137 -> V_919 = F_34 (
V_95 [ V_918 ] ) ;
if ( V_137 -> V_919 & ~ V_920 )
return - V_16 ;
if ( V_95 [ V_921 ] )
V_137 -> V_922 = F_34 ( V_95 [ V_921 ] ) ;
if ( V_137 -> V_922 & ~ V_923 )
return - V_16 ;
V_137 -> V_896 |= V_898 ;
return 0 ;
}
static int F_174 ( struct V_29 * V_30 ,
struct V_741 * V_137 )
{
if ( V_30 -> V_5 [ V_924 ] ) {
V_137 -> V_925 =
F_23 ( V_30 -> V_5 [ V_924 ] ) ;
V_137 -> V_926 =
F_24 ( V_30 -> V_5 [ V_924 ] ) ;
if ( V_137 -> V_926 < 2 )
return - V_16 ;
if ( V_137 -> V_926 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_927 ] ) {
V_137 -> V_928 =
F_23 ( V_30 -> V_5 [ V_927 ] ) ;
V_137 -> V_929 =
F_24 ( V_30 -> V_5 [ V_927 ] ) ;
if ( V_137 -> V_929 < 2 ||
V_137 -> V_929 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_175 ( struct V_29 * V_30 ,
struct V_741 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_930 ] )
V_137 -> V_889 = F_78 ( V_30 -> V_5 [ V_930 ] ) ;
if ( V_30 -> V_5 [ V_931 ] )
V_137 -> V_902 =
F_23 ( V_30 -> V_5 [ V_931 ] ) ;
if ( V_30 -> V_5 [ V_932 ] )
V_137 -> V_903 =
F_23 ( V_30 -> V_5 [ V_932 ] ) ;
V_35 = F_174 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_173 ( V_30 , V_137 ) ;
}
static int F_176 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_741 V_137 ;
T_2 * V_649 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_933 )
return - V_540 ;
if ( V_30 -> V_5 [ V_934 ] )
V_137 . V_889 = F_78 ( V_30 -> V_5 [ V_934 ] ) ;
if ( V_30 -> V_5 [ V_935 ] )
V_137 . V_887 =
F_78 ( V_30 -> V_5 [ V_935 ] ) ;
else
V_137 . V_887 = - 1 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_30 -> V_5 [ V_936 ] ) {
V_137 . V_900 =
F_23 ( V_30 -> V_5 [ V_936 ] ) ;
V_137 . V_937 =
F_24 ( V_30 -> V_5 [ V_936 ] ) ;
}
if ( V_30 -> V_5 [ V_938 ] ) {
V_137 . V_939 =
F_78 ( V_30 -> V_5 [ V_938 ] ) ;
V_137 . V_896 |= V_899 ;
}
if ( V_30 -> V_5 [ V_940 ] ) {
V_137 . V_901 =
F_23 ( V_30 -> V_5 [ V_940 ] ) ;
V_137 . V_941 =
F_24 ( V_30 -> V_5 [ V_940 ] ) ;
}
if ( F_157 ( V_30 , V_539 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_942 ] ) {
V_137 . V_894 =
F_34 ( V_30 -> V_5 [ V_942 ] ) ;
if ( V_137 . V_894 >= V_943 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_944 ] ) {
V_137 . V_812 =
F_34 ( V_30 -> V_5 [ V_944 ] ) ;
if ( V_137 . V_812 >= V_945 )
return - V_16 ;
V_137 . V_896 |= V_897 ;
}
if ( V_30 -> V_5 [ V_946 ] ) {
enum V_947 V_948 = F_4 (
V_30 -> V_5 [ V_946 ] ) ;
if ( V_948 <= V_949 ||
V_948 > V_950 )
return - V_16 ;
V_137 . V_839 = V_948 ;
}
V_35 = F_175 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_905 = F_170 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_905 ) )
return F_18 ( V_137 . V_905 ) ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_540 ;
goto V_951;
}
V_35 = F_177 ( V_7 , V_539 , V_649 , & V_137 ) ;
V_951:
if ( V_137 . V_905 )
F_172 ( V_137 . V_905 ) ;
return V_35 ;
}
static int F_178 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_741 V_137 ;
T_2 * V_649 = NULL ;
V_22 V_952 = F_158 ( V_758 ) |
F_158 ( V_907 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_377 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_935 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_936 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_934 ] &&
! V_30 -> V_5 [ V_930 ] )
return - V_16 ;
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_137 . V_900 =
F_23 ( V_30 -> V_5 [ V_936 ] ) ;
V_137 . V_937 =
F_24 ( V_30 -> V_5 [ V_936 ] ) ;
V_137 . V_887 =
F_78 ( V_30 -> V_5 [ V_935 ] ) ;
if ( V_30 -> V_5 [ V_930 ] )
V_137 . V_889 = F_78 ( V_30 -> V_5 [ V_930 ] ) ;
else
V_137 . V_889 = F_78 ( V_30 -> V_5 [ V_934 ] ) ;
if ( ! V_137 . V_889 || V_137 . V_889 > V_953 )
return - V_16 ;
if ( V_30 -> V_5 [ V_938 ] ) {
V_137 . V_939 =
F_78 ( V_30 -> V_5 [ V_938 ] ) ;
V_137 . V_896 |= V_899 ;
}
if ( V_30 -> V_5 [ V_940 ] ) {
V_137 . V_901 =
F_23 ( V_30 -> V_5 [ V_940 ] ) ;
V_137 . V_941 =
F_24 ( V_30 -> V_5 [ V_940 ] ) ;
}
if ( V_30 -> V_5 [ V_931 ] )
V_137 . V_902 =
F_23 ( V_30 -> V_5 [ V_931 ] ) ;
if ( V_30 -> V_5 [ V_932 ] )
V_137 . V_903 =
F_23 ( V_30 -> V_5 [ V_932 ] ) ;
if ( V_30 -> V_5 [ V_954 ] ) {
V_137 . V_955 = true ;
V_137 . V_956 =
F_34 ( V_30 -> V_5 [ V_954 ] ) ;
}
if ( V_30 -> V_5 [ V_942 ] ) {
V_137 . V_894 =
F_34 ( V_30 -> V_5 [ V_942 ] ) ;
if ( V_137 . V_894 >= V_943 )
return - V_16 ;
}
V_35 = F_174 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_173 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_157 ( V_30 , V_539 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( ! ( V_137 . V_748 & F_158 ( V_755 ) ) ) {
V_137 . V_902 = NULL ;
V_137 . V_903 = NULL ;
}
F_114 ( V_742 != 7 ) ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) ||
! ( V_137 . V_748 & F_158 ( V_755 ) ) )
V_137 . V_896 &= ~ V_898 ;
if ( ( V_137 . V_748 & F_158 ( V_757 ) ) ||
V_30 -> V_5 [ V_930 ] )
return - V_16 ;
V_137 . V_746 &= ~ F_158 ( V_757 ) ;
if ( ! ( V_7 -> V_18 . V_291 &
V_908 ) &&
V_137 . V_746 & V_952 )
return - V_16 ;
if ( ! ( V_137 . V_746 & V_952 ) ) {
V_137 . V_746 |= V_952 ;
V_137 . V_748 |= V_952 ;
}
V_137 . V_905 = F_170 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_905 ) )
return F_18 ( V_137 . V_905 ) ;
break;
case V_145 :
V_137 . V_896 &= ~ V_898 ;
if ( V_137 . V_746 & F_158 ( V_907 ) )
return - V_16 ;
if ( ( V_137 . V_748 & F_158 ( V_757 ) ) ||
V_30 -> V_5 [ V_930 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_896 &= ~ V_898 ;
if ( V_137 . V_746 &
( F_158 ( V_907 ) |
F_158 ( V_758 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_748 & F_158 ( V_757 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) )
return - V_540 ;
if ( ! ( V_7 -> V_18 . V_51 & V_334 ) )
return - V_540 ;
V_137 . V_746 &= ~ F_158 ( V_753 ) ;
break;
default:
return - V_540 ;
}
V_35 = F_179 ( V_7 , V_539 , V_649 , & V_137 ) ;
if ( V_137 . V_905 )
F_172 ( V_137 . V_905 ) ;
return V_35 ;
}
static int F_180 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_957 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_30 -> V_5 [ V_547 ] )
V_137 . V_958 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_539 -> V_28 -> V_141 != V_142 &&
V_539 -> V_28 -> V_141 != V_143 &&
V_539 -> V_28 -> V_141 != V_145 &&
V_539 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_959 )
return - V_540 ;
if ( V_30 -> V_5 [ V_960 ] ) {
V_137 . V_961 =
F_34 ( V_30 -> V_5 [ V_960 ] ) ;
if ( V_137 . V_961 != V_962 >> 4 &&
V_137 . V_961 != V_963 >> 4 )
return - V_16 ;
} else {
V_137 . V_961 = V_963 >> 4 ;
}
if ( V_30 -> V_5 [ V_964 ] ) {
V_137 . V_965 =
F_78 ( V_30 -> V_5 [ V_964 ] ) ;
if ( V_137 . V_965 == 0 )
return - V_16 ;
} else {
V_137 . V_965 = V_966 ;
}
return F_181 ( V_7 , V_539 , & V_137 ) ;
}
static int F_182 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_539 ,
T_2 * V_967 , T_2 * V_968 ,
struct V_969 * V_970 )
{
void * V_283 ;
struct V_4 * V_971 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_972 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_967 ) ||
F_51 ( V_53 , V_973 , V_587 , V_968 ) ||
F_28 ( V_53 , V_293 , V_970 -> V_792 ) )
goto V_61;
V_971 = F_47 ( V_53 , V_974 ) ;
if ( ! V_971 )
goto V_61;
if ( ( V_970 -> V_798 & V_975 ) &&
F_28 ( V_53 , V_976 ,
V_970 -> V_977 ) )
goto V_61;
if ( ( ( V_970 -> V_798 & V_978 ) &&
F_28 ( V_53 , V_979 , V_970 -> V_980 ) ) ||
( ( V_970 -> V_798 & V_981 ) &&
F_28 ( V_53 , V_982 ,
V_970 -> V_983 ) ) ||
( ( V_970 -> V_798 & V_984 ) &&
F_28 ( V_53 , V_985 ,
V_970 -> V_986 ) ) ||
( ( V_970 -> V_798 & V_987 ) &&
F_56 ( V_53 , V_988 ,
V_970 -> V_51 ) ) ||
( ( V_970 -> V_798 & V_989 ) &&
F_28 ( V_53 , V_990 ,
V_970 -> V_991 ) ) ||
( ( V_970 -> V_798 & V_992 ) &&
F_56 ( V_53 , V_993 ,
V_970 -> V_994 ) ) )
goto V_61;
F_48 ( V_53 , V_971 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_183 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_969 V_970 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_967 [ V_587 ] ;
T_2 V_968 [ V_587 ] ;
int V_995 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_996 ) {
V_35 = - V_540 ;
goto V_881;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_540 ;
goto V_881;
}
while ( 1 ) {
V_35 = F_184 ( V_7 , V_17 -> V_19 , V_995 , V_967 ,
V_968 , & V_970 ) ;
if ( V_35 == - V_655 )
break;
if ( V_35 )
goto V_881;
if ( F_182 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_17 -> V_19 , V_967 , V_968 ,
& V_970 ) < 0 )
goto V_599;
V_995 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_995 ;
V_35 = V_32 -> V_47 ;
V_881:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_185 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_969 V_970 ;
struct V_31 * V_53 ;
T_2 * V_967 = NULL ;
T_2 V_968 [ V_587 ] ;
memset ( & V_970 , 0 , sizeof( V_970 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_967 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_997 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
V_35 = F_186 ( V_7 , V_539 , V_967 , V_968 , & V_970 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_182 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_539 , V_967 , V_968 , & V_970 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_187 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_967 = NULL ;
T_2 * V_968 = NULL ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_973 ] )
return - V_16 ;
V_967 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_968 = F_23 ( V_30 -> V_5 [ V_973 ] ) ;
if ( ! V_7 -> V_351 -> V_998 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
return F_188 ( V_7 , V_539 , V_967 , V_968 ) ;
}
static int F_189 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_967 = NULL ;
T_2 * V_968 = NULL ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_973 ] )
return - V_16 ;
V_967 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_968 = F_23 ( V_30 -> V_5 [ V_973 ] ) ;
if ( ! V_7 -> V_351 -> V_379 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
return F_190 ( V_7 , V_539 , V_967 , V_968 ) ;
}
static int F_191 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_967 = NULL ;
if ( V_30 -> V_5 [ V_547 ] )
V_967 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_999 )
return - V_540 ;
return F_192 ( V_7 , V_539 , V_967 ) ;
}
static int F_193 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_969 V_970 ;
struct V_31 * V_53 ;
T_2 * V_967 = NULL ;
T_2 V_1000 [ V_587 ] ;
memset ( & V_970 , 0 , sizeof( V_970 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_967 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_1001 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
V_35 = F_194 ( V_7 , V_539 , V_967 , V_1000 , & V_970 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_182 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_539 , V_967 , V_1000 , & V_970 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_195 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_969 V_970 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_967 [ V_587 ] ;
T_2 V_1000 [ V_587 ] ;
int V_995 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_1002 ) {
V_35 = - V_540 ;
goto V_881;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_540 ;
goto V_881;
}
while ( 1 ) {
V_35 = F_196 ( V_7 , V_17 -> V_19 , V_995 , V_967 ,
V_1000 , & V_970 ) ;
if ( V_35 == - V_655 )
break;
if ( V_35 )
goto V_881;
if ( F_182 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_17 -> V_19 , V_967 , V_1000 ,
& V_970 ) < 0 )
goto V_599;
V_995 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_995 ;
V_35 = V_32 -> V_47 ;
V_881:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_197 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1003 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_1004 = - 1 ;
V_137 . V_1005 = - 1 ;
V_137 . V_1006 = - 1 ;
V_137 . V_1007 = - 1 ;
V_137 . V_1008 = - 1 ;
V_137 . V_728 = - 1 ;
V_137 . V_731 = - 1 ;
if ( V_30 -> V_5 [ V_1009 ] )
V_137 . V_1004 =
F_34 ( V_30 -> V_5 [ V_1009 ] ) ;
if ( V_30 -> V_5 [ V_1010 ] )
V_137 . V_1005 =
F_34 ( V_30 -> V_5 [ V_1010 ] ) ;
if ( V_30 -> V_5 [ V_1011 ] )
V_137 . V_1006 =
F_34 ( V_30 -> V_5 [ V_1011 ] ) ;
if ( V_30 -> V_5 [ V_1012 ] ) {
V_137 . V_1013 =
F_23 ( V_30 -> V_5 [ V_1012 ] ) ;
V_137 . V_1014 =
F_24 ( V_30 -> V_5 [ V_1012 ] ) ;
}
if ( V_30 -> V_5 [ V_1015 ] )
V_137 . V_1007 = ! ! F_34 ( V_30 -> V_5 [ V_1015 ] ) ;
if ( V_30 -> V_5 [ V_1016 ] )
V_137 . V_1008 =
F_78 ( V_30 -> V_5 [ V_1016 ] ) ;
if ( V_30 -> V_5 [ V_727 ] ) {
if ( V_539 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_728 =
F_198 ( V_30 -> V_5 [ V_727 ] ) ;
if ( V_137 . V_728 < 0 )
return - V_16 ;
if ( V_137 . V_728 != 0 &&
! ( V_7 -> V_18 . V_291 & V_729 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_730 ] ) {
T_2 V_24 ;
if ( V_539 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_730 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_731 = V_24 ;
if ( V_137 . V_731 &&
! ( V_7 -> V_18 . V_291 & V_732 ) )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_383 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_142 &&
V_539 -> V_28 -> V_141 != V_144 )
return - V_540 ;
F_113 ( V_17 ) ;
V_35 = F_199 ( V_7 , V_539 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_200 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
bool V_1017 ;
enum V_1018 V_1019 ;
V_22 V_632 ;
if ( F_201 ( ! F_202 ( V_1020 ) ) )
return - V_1021 ;
if ( V_30 -> V_5 [ V_1022 ] )
V_1019 =
F_4 ( V_30 -> V_5 [ V_1022 ] ) ;
else
V_1019 = V_1023 ;
switch ( V_1019 ) {
case V_1023 :
case V_1024 :
if ( ! V_30 -> V_5 [ V_1025 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1025 ] ) ;
return F_203 ( V_138 , V_1019 ) ;
case V_1026 :
if ( V_30 -> V_5 [ V_631 ] ) {
V_632 = V_30 -> V_504 ;
V_1017 = ! ! V_30 -> V_5 [ V_1027 ] ;
} else {
V_632 = 0 ;
V_1017 = true ;
}
return F_204 ( V_1017 , V_632 ) ;
default:
return - V_16 ;
}
}
static int F_205 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1028 V_1029 ;
int V_35 = 0 ;
void * V_283 ;
struct V_4 * V_971 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_1030 )
return - V_540 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1031 )
memcpy ( & V_1029 , & V_1032 , sizeof( V_1029 ) ) ;
else
V_35 = F_206 ( V_7 , V_539 , & V_1029 ) ;
F_115 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1033 ) ;
if ( ! V_283 )
goto V_599;
V_971 = F_47 ( V_53 , V_1034 ) ;
if ( ! V_971 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_55 ( V_53 , V_1035 ,
V_1029 . V_1036 ) ||
F_55 ( V_53 , V_1037 ,
V_1029 . V_1038 ) ||
F_55 ( V_53 , V_1039 ,
V_1029 . V_1040 ) ||
F_55 ( V_53 , V_1041 ,
V_1029 . V_1042 ) ||
F_56 ( V_53 , V_1043 ,
V_1029 . V_1044 ) ||
F_56 ( V_53 , V_1045 ,
V_1029 . V_1046 ) ||
F_56 ( V_53 , V_1047 ,
V_1029 . V_1048 ) ||
F_56 ( V_53 , V_1049 ,
V_1029 . V_1050 ) ||
F_28 ( V_53 , V_1051 ,
V_1029 . V_1052 ) ||
F_56 ( V_53 , V_1053 ,
V_1029 . V_1054 ) ||
F_28 ( V_53 , V_1055 ,
V_1029 . V_1056 ) ||
F_55 ( V_53 , V_1057 ,
V_1029 . V_1058 ) ||
F_28 ( V_53 , V_1059 ,
V_1029 . V_1060 ) ||
F_55 ( V_53 , V_1061 ,
V_1029 . V_1062 ) ||
F_55 ( V_53 , V_1063 ,
V_1029 . V_1064 ) ||
F_55 ( V_53 , V_1065 ,
V_1029 . V_1066 ) ||
F_56 ( V_53 , V_1067 ,
V_1029 . V_1068 ) ||
F_55 ( V_53 , V_1069 ,
V_1029 . V_1070 ) ||
F_56 ( V_53 , V_1071 ,
V_1029 . V_1072 ) ||
F_56 ( V_53 , V_1073 ,
V_1029 . V_1074 ) ||
F_28 ( V_53 , V_1075 ,
V_1029 . V_1076 ) ||
F_28 ( V_53 , V_1077 ,
V_1029 . V_1008 ) ||
F_28 ( V_53 , V_1078 ,
V_1029 . V_1079 ) ||
F_55 ( V_53 , V_1080 ,
V_1029 . V_1081 ) ||
F_55 ( V_53 , V_1082 ,
V_1029 . V_1083 ) ||
F_28 ( V_53 , V_1084 ,
V_1029 . V_1085 ) ||
F_55 ( V_53 , V_1086 ,
V_1029 . V_1087 ) ||
F_28 ( V_53 , V_1088 ,
V_1029 . V_1089 ) )
goto V_61;
F_48 ( V_53 , V_971 ) ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_599:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_207 ( struct V_29 * V_30 ,
struct V_1028 * V_1090 ,
V_22 * V_1091 )
{
struct V_4 * V_95 [ V_1092 + 1 ] ;
V_22 V_747 = 0 ;
#define F_208 ( V_95 , V_1090 , T_8 , T_9 , V_174 , V_747 , V_45 , T_10 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1034 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1092 ,
V_30 -> V_5 [ V_1034 ] ,
V_1093 ) )
return - V_16 ;
F_114 ( V_1092 > 32 ) ;
F_208 ( V_95 , V_1090 , V_1036 , 1 , 255 ,
V_747 , V_1035 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1038 , 1 , 255 ,
V_747 , V_1037 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1040 , 1 , 255 ,
V_747 , V_1039 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1042 , 0 , 255 ,
V_747 , V_1041 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1044 , 0 , 16 ,
V_747 , V_1043 ,
F_34 ) ;
F_208 ( V_95 , V_1090 , V_1046 , 1 , 255 ,
V_747 , V_1045 , F_34 ) ;
F_208 ( V_95 , V_1090 , V_1048 , 1 , 255 ,
V_747 , V_1047 ,
F_34 ) ;
F_208 ( V_95 , V_1090 , V_1050 , 0 , 1 ,
V_747 , V_1049 ,
F_34 ) ;
F_208 ( V_95 , V_1090 , V_1052 ,
1 , 255 , V_747 ,
V_1051 ,
F_4 ) ;
F_208 ( V_95 , V_1090 , V_1054 , 0 , 255 ,
V_747 , V_1053 ,
F_34 ) ;
F_208 ( V_95 , V_1090 , V_1056 , 1 , 65535 ,
V_747 , V_1055 ,
F_4 ) ;
F_208 ( V_95 , V_1090 , V_1058 , 1 , 65535 ,
V_747 , V_1057 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1060 ,
1 , 65535 , V_747 ,
V_1059 ,
F_4 ) ;
F_208 ( V_95 , V_1090 , V_1062 ,
1 , 65535 , V_747 ,
V_1061 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1064 ,
1 , 65535 , V_747 ,
V_1063 ,
F_78 ) ;
F_208 ( V_95 , V_1090 ,
V_1066 ,
1 , 65535 , V_747 ,
V_1065 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1068 , 0 , 4 ,
V_747 , V_1067 ,
F_34 ) ;
F_208 ( V_95 , V_1090 , V_1070 , 1 , 65535 ,
V_747 , V_1069 ,
F_78 ) ;
F_208 ( V_95 , V_1090 ,
V_1072 , 0 , 1 ,
V_747 , V_1071 ,
F_34 ) ;
F_208 ( V_95 , V_1090 , V_1074 , 0 , 1 ,
V_747 , V_1073 ,
F_34 ) ;
F_208 ( V_95 , V_1090 , V_1076 , - 255 , 0 ,
V_747 , V_1075 ,
V_1094 ) ;
F_208 ( V_95 , V_1090 , V_1008 , 0 , 16 ,
V_747 , V_1077 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1079 ,
1 , 65535 , V_747 ,
V_1078 ,
F_4 ) ;
F_208 ( V_95 , V_1090 , V_1081 , 1 , 65535 ,
V_747 , V_1080 ,
F_78 ) ;
F_208 ( V_95 , V_1090 ,
V_1083 ,
1 , 65535 , V_747 ,
V_1082 ,
F_78 ) ;
F_208 ( V_95 , V_1090 , V_1085 ,
V_1095 ,
V_950 ,
V_747 , V_1084 ,
F_4 ) ;
F_208 ( V_95 , V_1090 , V_1087 ,
0 , 65535 , V_747 ,
V_1086 , F_78 ) ;
F_208 ( V_95 , V_1090 , V_1089 , 0 , 0xffffffff ,
V_747 , V_1088 ,
F_4 ) ;
if ( V_1091 )
* V_1091 = V_747 ;
return 0 ;
#undef F_208
}
static int F_209 ( struct V_29 * V_30 ,
struct V_1096 * V_1097 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_4 * V_95 [ V_1098 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1099 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1098 ,
V_30 -> V_5 [ V_1099 ] ,
V_1100 ) )
return - V_16 ;
if ( V_95 [ V_1101 ] )
V_1097 -> V_1102 =
( F_34 ( V_95 [ V_1101 ] ) ) ?
V_1103 :
V_1104 ;
if ( V_95 [ V_1105 ] )
V_1097 -> V_1106 =
( F_34 ( V_95 [ V_1105 ] ) ) ?
V_1107 :
V_1108 ;
if ( V_95 [ V_1109 ] )
V_1097 -> V_1110 =
( F_34 ( V_95 [ V_1109 ] ) ) ?
V_1111 :
V_1112 ;
if ( V_95 [ V_1113 ] ) {
struct V_4 * V_1114 =
V_95 [ V_1113 ] ;
if ( ! F_22 ( V_1114 ) )
return - V_16 ;
V_1097 -> V_1115 = F_23 ( V_1114 ) ;
V_1097 -> V_1116 = F_24 ( V_1114 ) ;
}
if ( V_95 [ V_1117 ] &&
! ( V_7 -> V_18 . V_291 & V_1118 ) )
return - V_16 ;
V_1097 -> V_1119 = F_210 ( V_95 [ V_1117 ] ) ;
V_1097 -> V_1120 = F_210 ( V_95 [ V_1121 ] ) ;
V_1097 -> V_1122 = F_210 ( V_95 [ V_1123 ] ) ;
if ( V_1097 -> V_1122 )
V_1097 -> V_1119 = true ;
if ( V_95 [ V_1124 ] ) {
if ( ! V_1097 -> V_1119 )
return - V_16 ;
V_1097 -> V_1125 =
F_34 ( V_95 [ V_1124 ] ) ;
}
return 0 ;
}
static int F_211 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1028 V_1090 ;
V_22 V_747 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_381 )
return - V_540 ;
V_35 = F_207 ( V_30 , & V_1090 , & V_747 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1031 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_212 ( V_7 , V_539 , V_747 , & V_1090 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_213 ( const struct V_1126 * V_1127 ,
struct V_31 * V_53 )
{
struct V_4 * V_1128 ;
unsigned int V_159 ;
if ( F_60 ( V_53 , V_1025 , V_1127 -> V_1129 ) ||
( V_1127 -> V_1130 &&
F_56 ( V_53 , V_1131 , V_1127 -> V_1130 ) ) )
goto V_61;
V_1128 = F_47 ( V_53 , V_1132 ) ;
if ( ! V_1128 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1127 -> V_1133 ; V_159 ++ ) {
struct V_4 * V_1134 ;
const struct V_1135 * V_1136 ;
const struct V_1137 * V_1138 ;
const struct V_1139 * V_1140 ;
unsigned int V_1141 ;
V_1136 = & V_1127 -> V_1142 [ V_159 ] ;
V_1138 = & V_1136 -> V_1138 ;
V_1140 = & V_1136 -> V_1140 ;
V_1134 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1134 )
goto V_61;
V_1141 = V_1138 -> V_1141 ;
if ( ! V_1141 )
V_1141 = F_214 ( V_1127 ,
V_1136 ) ;
if ( F_28 ( V_53 , V_1143 ,
V_1136 -> V_51 ) ||
F_28 ( V_53 , V_1144 ,
V_1138 -> V_1145 ) ||
F_28 ( V_53 , V_1146 ,
V_1138 -> V_1147 ) ||
F_28 ( V_53 , V_1148 ,
V_1141 ) ||
F_28 ( V_53 , V_1149 ,
V_1140 -> V_1150 ) ||
F_28 ( V_53 , V_1151 ,
V_1140 -> V_1152 ) ||
F_28 ( V_53 , V_1153 ,
V_1136 -> V_74 ) )
goto V_61;
F_48 ( V_53 , V_1134 ) ;
}
F_48 ( V_53 , V_1128 ) ;
return 0 ;
V_61:
return - V_495 ;
}
static int F_215 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1126 * V_1127 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1154 ) ;
if ( ! V_283 )
goto V_1155;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1156 ;
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1156 = V_18 -> V_490 &
V_491 ;
V_1127 = F_216 ( V_18 ) ;
if ( F_59 ( ! V_1127 && V_1156 ) ) {
F_75 ( V_53 ) ;
return - V_16 ;
}
if ( V_1127 &&
F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
}
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1022 ,
V_1024 ) )
goto V_61;
F_219 () ;
if ( ! V_1127 )
V_1127 = F_220 ( V_1020 ) ;
if ( F_213 ( V_1127 , V_53 ) )
goto V_1157;
F_221 () ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1157:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_1155:
F_75 ( V_53 ) ;
return - V_495 ;
}
static int F_222 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 , struct V_18 * V_18 ,
const struct V_1126 * V_1127 )
{
void * V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1154 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_213 ( V_1127 , V_53 ) )
goto V_61;
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1022 ,
V_1024 ) )
goto V_61;
if ( V_18 &&
F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
if ( V_18 && V_18 -> V_490 & V_491 &&
F_29 ( V_53 , V_492 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_224 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1126 * V_1127 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1158 , V_499 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1020 && V_499 == 0 ) {
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_500 ,
V_501 , NULL ,
F_225 ( V_1020 ) ) ;
if ( V_35 < 0 )
goto V_881;
}
V_1158 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1127 = F_216 ( & V_7 -> V_18 ) ;
if ( ! V_1127 )
continue;
if ( ++ V_1158 <= V_499 )
continue;
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_500 ,
V_501 , & V_7 -> V_18 , V_1127 ) ;
if ( V_35 < 0 ) {
V_1158 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1158 ;
V_35 = V_32 -> V_47 ;
V_881:
F_20 () ;
return V_35 ;
}
static int F_226 ( struct V_4 * V_95 [] ,
struct V_1135 * V_1136 )
{
struct V_1137 * V_1138 = & V_1136 -> V_1138 ;
struct V_1139 * V_1140 = & V_1136 -> V_1140 ;
if ( ! V_95 [ V_1143 ] )
return - V_16 ;
if ( ! V_95 [ V_1144 ] )
return - V_16 ;
if ( ! V_95 [ V_1146 ] )
return - V_16 ;
if ( ! V_95 [ V_1148 ] )
return - V_16 ;
if ( ! V_95 [ V_1151 ] )
return - V_16 ;
V_1136 -> V_51 = F_4 ( V_95 [ V_1143 ] ) ;
V_1138 -> V_1145 =
F_4 ( V_95 [ V_1144 ] ) ;
V_1138 -> V_1147 =
F_4 ( V_95 [ V_1146 ] ) ;
V_1138 -> V_1141 =
F_4 ( V_95 [ V_1148 ] ) ;
V_1140 -> V_1152 =
F_4 ( V_95 [ V_1151 ] ) ;
if ( V_95 [ V_1149 ] )
V_1140 -> V_1150 =
F_4 ( V_95 [ V_1149 ] ) ;
if ( V_95 [ V_1153 ] )
V_1136 -> V_74 =
F_4 ( V_95 [ V_1153 ] ) ;
return 0 ;
}
static int F_227 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1159 + 1 ] ;
struct V_4 * V_1134 ;
char * V_1129 ;
int V_1160 , V_1161 ;
V_22 V_1162 = 0 , V_1163 = 0 , V_1164 ;
enum V_1165 V_1130 = V_1166 ;
struct V_1126 * V_1167 ;
if ( ! V_30 -> V_5 [ V_1025 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1132 ] )
return - V_16 ;
V_1129 = F_23 ( V_30 -> V_5 [ V_1025 ] ) ;
if ( V_30 -> V_5 [ V_1131 ] )
V_1130 = F_34 ( V_30 -> V_5 [ V_1131 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1162 ++ ;
if ( V_1162 > V_1168 )
return - V_16 ;
}
if ( ! F_228 ( V_1129 ) )
return - V_16 ;
V_1164 = sizeof( struct V_1126 ) +
V_1162 * sizeof( struct V_1135 ) ;
V_1167 = F_38 ( V_1164 , V_135 ) ;
if ( ! V_1167 )
return - V_136 ;
V_1167 -> V_1133 = V_1162 ;
V_1167 -> V_1129 [ 0 ] = V_1129 [ 0 ] ;
V_1167 -> V_1129 [ 1 ] = V_1129 [ 1 ] ;
if ( F_229 ( V_1130 ) )
V_1167 -> V_1130 = V_1130 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1161 = F_96 ( V_95 , V_1159 ,
F_23 ( V_1134 ) , F_24 ( V_1134 ) ,
V_1169 ) ;
if ( V_1161 )
goto V_1170;
V_1161 = F_226 ( V_95 , & V_1167 -> V_1142 [ V_1163 ] ) ;
if ( V_1161 )
goto V_1170;
V_1163 ++ ;
if ( V_1163 > V_1168 ) {
V_1161 = - V_16 ;
goto V_1170;
}
}
V_1161 = F_230 ( V_1167 , V_1171 ) ;
V_1167 = NULL ;
V_1170:
F_41 ( V_1167 ) ;
return V_1161 ;
}
static int F_231 ( struct V_4 * V_1172 )
{
struct V_4 * V_1173 , * V_1174 ;
int V_366 = 0 , V_1175 , V_1176 ;
F_39 (attr1, freqs, tmp1) {
V_366 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1173 != V_1174 &&
F_4 ( V_1173 ) == F_4 ( V_1174 ) )
return 0 ;
}
return V_366 ;
}
static int F_232 ( struct V_4 * * V_5 ,
T_2 * V_649 , T_2 * V_1177 )
{
int V_159 ;
if ( ! V_5 [ V_547 ] && ! V_5 [ V_1178 ] ) {
F_233 ( V_649 ) ;
F_233 ( V_1177 ) ;
V_649 [ 0 ] = 0x2 ;
V_1177 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_547 ] || ! V_5 [ V_1178 ] )
return - V_16 ;
memcpy ( V_649 , F_23 ( V_5 [ V_547 ] ) , V_587 ) ;
memcpy ( V_1177 , F_23 ( V_5 [ V_1178 ] ) , V_587 ) ;
if ( ! F_234 ( V_1177 ) ||
F_234 ( V_649 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_587 ; V_159 ++ )
V_649 [ V_159 ] &= V_1177 [ V_159 ] ;
return 0 ;
}
static int F_235 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
struct V_1179 * V_1180 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1181 = 0 , V_366 , V_159 ;
T_11 V_1116 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_351 -> V_1182 )
return - V_540 ;
if ( V_7 -> V_1183 || V_7 -> V_1184 ) {
V_35 = - V_544 ;
goto V_1185;
}
if ( V_30 -> V_5 [ V_1186 ] ) {
V_366 = F_231 (
V_30 -> V_5 [ V_1186 ] ) ;
if ( ! V_366 ) {
V_35 = - V_16 ;
goto V_1185;
}
} else {
V_366 = F_236 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1187 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1181 ++ ;
if ( V_1181 > V_18 -> V_309 ) {
V_35 = - V_16 ;
goto V_1185;
}
if ( V_30 -> V_5 [ V_683 ] )
V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
else
V_1116 = 0 ;
if ( V_1116 > V_18 -> V_313 ) {
V_35 = - V_16 ;
goto V_1185;
}
V_1180 = F_38 ( sizeof( * V_1180 )
+ sizeof( * V_1180 -> V_1188 ) * V_1181
+ sizeof( * V_1180 -> V_367 ) * V_366
+ V_1116 , V_135 ) ;
if ( ! V_1180 ) {
V_35 = - V_136 ;
goto V_1185;
}
if ( V_1181 )
V_1180 -> V_1188 = ( void * ) & V_1180 -> V_367 [ V_366 ] ;
V_1180 -> V_1181 = V_1181 ;
if ( V_1116 ) {
if ( V_1181 )
V_1180 -> V_1115 = ( void * ) ( V_1180 -> V_1188 + V_1181 ) ;
else
V_1180 -> V_1115 = ( void * ) ( V_1180 -> V_367 + V_366 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1186 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1189;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1180 -> V_367 [ V_159 ] = V_55 ;
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
V_1180 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1189;
}
V_1180 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1181 ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_618 ) {
V_35 = - V_16 ;
goto V_1189;
}
V_1180 -> V_1188 [ V_159 ] . V_592 = F_24 ( V_45 ) ;
memcpy ( V_1180 -> V_1188 [ V_159 ] . V_594 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_683 ] ) {
V_1180 -> V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
memcpy ( ( void * ) V_1180 -> V_1115 ,
F_23 ( V_30 -> V_5 [ V_683 ] ) ,
V_1180 -> V_1116 ) ;
}
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ )
if ( V_18 -> V_363 [ V_159 ] )
V_1180 -> V_1190 [ V_159 ] =
( 1 << V_18 -> V_363 [ V_159 ] -> V_261 ) - 1 ;
if ( V_30 -> V_5 [ V_1191 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_289 V_290 = F_237 ( V_45 ) ;
if ( V_290 < 0 || V_290 >= V_362 ) {
V_35 = - V_16 ;
goto V_1189;
}
if ( ! V_18 -> V_363 [ V_290 ] )
continue;
V_35 = F_238 ( V_18 -> V_363 [ V_290 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1180 -> V_1190 [ V_290 ] ) ;
if ( V_35 )
goto V_1189;
}
}
if ( V_30 -> V_5 [ V_1192 ] ) {
V_1180 -> V_51 = F_4 (
V_30 -> V_5 [ V_1192 ] ) ;
if ( ( V_1180 -> V_51 & V_1193 ) &&
! ( V_18 -> V_291 & V_1194 ) ) {
V_35 = - V_540 ;
goto V_1189;
}
if ( V_1180 -> V_51 & V_1195 ) {
if ( ! ( V_18 -> V_291 &
V_1196 ) ) {
V_35 = - V_540 ;
goto V_1189;
}
if ( V_17 -> V_149 ) {
V_35 = - V_540 ;
goto V_1189;
}
V_35 = F_232 ( V_30 -> V_5 ,
V_1180 -> V_649 ,
V_1180 -> V_1177 ) ;
if ( V_35 )
goto V_1189;
}
}
V_1180 -> V_1197 =
F_210 ( V_30 -> V_5 [ V_1198 ] ) ;
V_1180 -> V_17 = V_17 ;
V_1180 -> V_18 = & V_7 -> V_18 ;
V_1180 -> V_1199 = V_1200 ;
V_7 -> V_1183 = V_1180 ;
V_35 = F_239 ( V_7 , V_1180 ) ;
if ( ! V_35 ) {
F_240 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_241 ( V_17 -> V_19 ) ;
} else {
V_1189:
V_7 -> V_1183 = NULL ;
F_41 ( V_1180 ) ;
}
V_1185:
return V_35 ;
}
static int F_242 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1201 )
return - V_540 ;
if ( V_7 -> V_1184 )
return 0 ;
if ( ! V_7 -> V_1183 )
return - V_655 ;
F_243 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_244 ( struct V_18 * V_18 , int V_1202 ,
struct V_1203 * V_1180 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_159 = 0 ;
struct V_4 * V_45 ;
if ( ! V_5 [ V_1204 ] ) {
V_22 V_1205 ;
if ( ! V_5 [ V_1206 ] )
return - V_16 ;
V_1205 = F_4 ( V_5 [ V_1206 ] ) ;
if ( ! V_1205 )
return - V_16 ;
V_1180 -> V_1207 [ 0 ] . V_1205 =
F_245 ( V_1205 , V_1208 ) ;
if ( ! V_1180 -> V_1207 [ 0 ] . V_1205 )
return - V_16 ;
if ( V_1180 -> V_1207 [ 0 ] . V_1205 >
V_18 -> V_321 )
V_1180 -> V_1207 [ 0 ] . V_1205 =
V_18 -> V_321 ;
return 0 ;
}
F_39 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1209 [ V_1210 + 1 ] ;
if ( F_59 ( V_159 >= V_1202 ) )
return - V_16 ;
V_35 = F_96 ( V_1209 , V_1210 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1211 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1209 [ V_1212 ] )
return - V_16 ;
V_1180 -> V_1207 [ V_159 ] . V_1205 =
F_4 ( V_1209 [ V_1212 ] ) ;
if ( ! V_1180 -> V_1207 [ V_159 ] . V_1205 ||
V_1180 -> V_1207 [ V_159 ] . V_1205 >
V_18 -> V_321 )
return - V_16 ;
if ( V_1209 [ V_1213 ] ) {
V_1180 -> V_1207 [ V_159 ] . V_1214 =
F_4 ( V_1209 [ V_1213 ] ) ;
if ( ! V_1180 -> V_1207 [ V_159 ] . V_1214 ||
( V_1180 -> V_1207 [ V_159 ] . V_1214 >
V_18 -> V_323 ) )
return - V_16 ;
} else if ( V_159 < V_1202 - 1 ) {
return - V_16 ;
}
V_159 ++ ;
}
if ( V_1180 -> V_1207 [ V_1202 - 1 ] . V_1214 )
return - V_16 ;
return 0 ;
}
static struct V_1203 *
F_246 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1203 * V_1180 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1181 = 0 , V_1215 = 0 , V_366 , V_159 , V_1202 = 0 ;
enum V_289 V_290 ;
T_11 V_1116 ;
struct V_4 * V_95 [ V_1216 + 1 ] ;
T_12 V_1217 = V_1218 ;
if ( ! F_22 ( V_5 [ V_683 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1186 ] ) {
V_366 = F_231 (
V_5 [ V_1186 ] ) ;
if ( ! V_366 )
return F_3 ( - V_16 ) ;
} else {
V_366 = F_236 ( V_18 ) ;
}
if ( V_5 [ V_1187 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1181 ++ ;
if ( V_1181 > V_18 -> V_311 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1219 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1220 ;
V_35 = F_96 ( V_95 , V_1216 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1221 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1222 ] ) {
V_1215 ++ ;
continue;
}
V_1220 = V_95 [ V_1223 ] ;
if ( V_1220 )
V_1217 = V_1094 ( V_1220 ) ;
}
}
if ( ! V_1215 && V_1217 != V_1218 )
V_1215 = 1 ;
if ( V_1215 > V_18 -> V_317 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_683 ] )
V_1116 = F_24 ( V_5 [ V_683 ] ) ;
else
V_1116 = 0 ;
if ( V_1116 > V_18 -> V_315 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1204 ] ) {
if ( V_5 [ V_1206 ] )
return F_3 ( - V_16 ) ;
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1202 ++ ;
} else {
if ( ! V_5 [ V_1206 ] )
return F_3 ( - V_16 ) ;
V_1202 = 1 ;
}
if ( ! V_1202 || V_1202 > V_18 -> V_319 )
return F_3 ( - V_16 ) ;
V_1180 = F_38 ( sizeof( * V_1180 )
+ sizeof( * V_1180 -> V_1188 ) * V_1181
+ sizeof( * V_1180 -> V_1224 ) * V_1215
+ sizeof( * V_1180 -> V_1207 ) * V_1202
+ sizeof( * V_1180 -> V_367 ) * V_366
+ V_1116 , V_135 ) ;
if ( ! V_1180 )
return F_3 ( - V_136 ) ;
if ( V_1181 )
V_1180 -> V_1188 = ( void * ) & V_1180 -> V_367 [ V_366 ] ;
V_1180 -> V_1181 = V_1181 ;
if ( V_1116 ) {
if ( V_1181 )
V_1180 -> V_1115 = ( void * ) ( V_1180 -> V_1188 + V_1181 ) ;
else
V_1180 -> V_1115 = ( void * ) ( V_1180 -> V_367 + V_366 ) ;
}
if ( V_1215 ) {
if ( V_1180 -> V_1115 )
V_1180 -> V_1224 = ( void * ) ( V_1180 -> V_1115 + V_1116 ) ;
else if ( V_1181 )
V_1180 -> V_1224 =
( void * ) ( V_1180 -> V_1188 + V_1181 ) ;
else
V_1180 -> V_1224 =
( void * ) ( V_1180 -> V_367 + V_366 ) ;
}
V_1180 -> V_1215 = V_1215 ;
if ( V_1215 )
V_1180 -> V_1207 = ( void * ) ( V_1180 -> V_1224 +
V_1215 ) ;
else if ( V_1180 -> V_1115 )
V_1180 -> V_1207 = ( void * ) ( V_1180 -> V_1115 + V_1116 ) ;
else if ( V_1181 )
V_1180 -> V_1207 = ( void * ) ( V_1180 -> V_1188 + V_1181 ) ;
else
V_1180 -> V_1207 = ( void * ) ( V_1180 -> V_367 + V_366 ) ;
V_1180 -> V_1225 = V_1202 ;
V_159 = 0 ;
if ( V_5 [ V_1186 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1189;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1180 -> V_367 [ V_159 ] = V_55 ;
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
V_1180 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1189;
}
V_1180 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1181 ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_618 ) {
V_35 = - V_16 ;
goto V_1189;
}
V_1180 -> V_1188 [ V_159 ] . V_592 = F_24 ( V_45 ) ;
memcpy ( V_1180 -> V_1188 [ V_159 ] . V_594 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1219 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_594 , * V_1220 ;
V_35 = F_96 ( V_95 , V_1216 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1221 ) ;
if ( V_35 )
goto V_1189;
V_594 = V_95 [ V_1222 ] ;
if ( V_594 ) {
if ( F_59 ( V_159 >= V_1215 ) ) {
V_35 = - V_16 ;
goto V_1189;
}
if ( F_24 ( V_594 ) > V_618 ) {
V_35 = - V_16 ;
goto V_1189;
}
memcpy ( V_1180 -> V_1224 [ V_159 ] . V_594 . V_594 ,
F_23 ( V_594 ) , F_24 ( V_594 ) ) ;
V_1180 -> V_1224 [ V_159 ] . V_594 . V_592 =
F_24 ( V_594 ) ;
V_1180 -> V_1224 [ V_159 ] . V_1226 =
V_1217 ;
V_1220 = V_95 [ V_1223 ] ;
if ( V_1220 )
V_1180 -> V_1224 [ V_159 ] . V_1226 =
V_1094 ( V_1220 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1215 )
V_1180 -> V_1224 [ 0 ] . V_1226 = V_1217 ;
V_1180 -> V_1227 = V_1228 ;
for ( V_159 = 0 ; V_159 < V_1215 ; V_159 ++ )
V_1180 -> V_1227 =
T_9 ( V_1180 -> V_1224 [ V_159 ] . V_1226 ,
V_1180 -> V_1227 ) ;
} else {
V_1180 -> V_1227 = V_1218 ;
}
if ( V_1116 ) {
V_1180 -> V_1116 = V_1116 ;
memcpy ( ( void * ) V_1180 -> V_1115 ,
F_23 ( V_5 [ V_683 ] ) ,
V_1180 -> V_1116 ) ;
}
if ( V_5 [ V_1192 ] ) {
V_1180 -> V_51 = F_4 (
V_5 [ V_1192 ] ) ;
if ( ( V_1180 -> V_51 & V_1193 ) &&
! ( V_18 -> V_291 & V_1194 ) ) {
V_35 = - V_540 ;
goto V_1189;
}
if ( V_1180 -> V_51 & V_1195 ) {
V_22 V_1229 = V_1230 ;
if ( ! V_17 )
V_1229 = V_1231 ;
if ( ! ( V_18 -> V_291 & V_1229 ) ) {
V_35 = - V_540 ;
goto V_1189;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_540 ;
goto V_1189;
}
V_35 = F_232 ( V_5 , V_1180 -> V_649 ,
V_1180 -> V_1177 ) ;
if ( V_35 )
goto V_1189;
}
}
if ( V_5 [ V_1232 ] )
V_1180 -> V_1233 =
F_4 ( V_5 [ V_1232 ] ) ;
V_35 = F_244 ( V_18 , V_1202 , V_1180 , V_5 ) ;
if ( V_35 )
goto V_1189;
V_1180 -> V_1199 = V_1200 ;
return V_1180 ;
V_1189:
F_41 ( V_1180 ) ;
return F_3 ( V_35 ) ;
}
static int F_247 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1203 * V_1234 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_423 )
return - V_540 ;
if ( V_7 -> V_1234 )
return - V_1021 ;
V_1234 = F_246 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_248 ( V_1234 ) ;
if ( V_35 )
goto V_881;
V_35 = F_249 ( V_7 , V_539 , V_1234 ) ;
if ( V_35 )
goto V_1189;
V_1234 -> V_539 = V_539 ;
V_1234 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_631 ] )
V_1234 -> V_632 = V_30 -> V_504 ;
F_250 ( V_7 -> V_1234 , V_1234 ) ;
F_251 ( V_7 , V_539 ,
V_1235 ) ;
return 0 ;
V_1189:
F_41 ( V_1234 ) ;
V_881:
return V_35 ;
}
static int F_252 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_1236 )
return - V_540 ;
return F_253 ( V_7 , false ) ;
}
static int F_254 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_519 V_520 ;
enum V_1165 V_1130 ;
unsigned int V_1237 ;
int V_35 ;
V_1130 = F_255 ( V_17 -> V_18 ) ;
if ( V_1130 == V_1166 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
if ( F_256 ( V_539 ) )
return - V_544 ;
if ( V_17 -> V_1238 )
return - V_544 ;
V_35 = F_257 ( V_17 -> V_18 , & V_520 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_258 ( V_17 -> V_18 , & V_520 ) )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1239 )
return - V_540 ;
V_1237 = F_259 ( & V_7 -> V_18 , & V_520 ) ;
if ( F_59 ( ! V_1237 ) )
V_1237 = V_1240 ;
V_35 = F_260 ( V_7 , V_539 , & V_520 , V_1237 ) ;
if ( ! V_35 ) {
V_17 -> V_520 = V_520 ;
V_17 -> V_1238 = true ;
V_17 -> V_1241 = V_1200 ;
V_17 -> V_1237 = V_1237 ;
}
return V_35 ;
}
static int F_261 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1242 V_137 ;
static struct V_4 * V_1243 [ V_1244 + 1 ] ;
int V_35 ;
bool V_1245 = false ;
int V_47 , V_159 ;
V_22 V_1246 ;
if ( ! V_7 -> V_351 -> V_442 ||
! ( V_7 -> V_18 . V_51 & V_441 ) )
return - V_540 ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1245 = true ;
if ( ! V_17 -> V_541 )
return - V_1247 ;
break;
case V_146 :
if ( ! V_17 -> V_592 )
return - V_1247 ;
break;
case V_145 :
if ( ! V_17 -> V_1031 )
return - V_1247 ;
break;
default:
return - V_540 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_522 ] ||
! V_30 -> V_5 [ V_1248 ] )
return - V_16 ;
if ( V_1245 && ! V_30 -> V_5 [ V_1249 ] )
return - V_16 ;
V_1246 = F_4 ( V_30 -> V_5 [ V_1248 ] ) ;
if ( V_1246 > 255 )
return - V_16 ;
V_137 . V_1250 = V_1246 ;
if ( ! V_1245 )
goto V_1251;
V_35 = F_146 ( V_30 -> V_5 , & V_137 . V_1252 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1243 , V_1244 ,
V_30 -> V_5 [ V_1249 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_146 ( V_1243 , & V_137 . V_1253 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1243 [ V_1254 ] )
return - V_16 ;
V_47 = F_24 ( V_1243 [ V_1254 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1255 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1255 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1256 =
F_23 ( V_1243 [ V_1254 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1255 ; V_159 ++ ) {
T_3 V_1257 = V_137 . V_1256 [ V_159 ] ;
if ( V_1257 >= V_137 . V_1253 . V_690 )
return - V_16 ;
if ( V_137 . V_1253 . V_689 [ V_1257 ] != V_137 . V_1250 )
return - V_16 ;
}
if ( V_1243 [ V_1258 ] ) {
V_47 = F_24 ( V_1243 [ V_1258 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1259 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1255 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1260 =
F_23 ( V_1243 [ V_1258 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1259 ; V_159 ++ ) {
T_3 V_1257 = V_137 . V_1260 [ V_159 ] ;
if ( V_1257 >= V_137 . V_1253 . V_699 )
return - V_16 ;
if ( V_137 . V_1253 . V_698 [ V_1257 ] !=
V_137 . V_1250 )
return - V_16 ;
}
}
V_1251:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_520 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_520 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_257 ( V_17 -> V_18 ,
& V_137 . V_520 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_137 . V_1261 = true ;
if ( V_30 -> V_5 [ V_1262 ] )
V_137 . V_1263 = true ;
F_113 ( V_17 ) ;
V_35 = F_262 ( V_7 , V_539 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_263 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1264 * V_1265 )
{
struct V_1266 * V_355 = & V_1265 -> V_1267 ;
const struct V_1268 * V_1269 ;
void * V_283 ;
struct V_4 * V_1270 ;
F_43 ( V_17 ) ;
V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1271 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_28 ( V_53 , V_293 , V_7 -> V_1272 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
V_1270 = F_47 ( V_53 , V_1273 ) ;
if ( ! V_1270 )
goto V_61;
if ( ( ! F_264 ( V_355 -> V_546 ) &&
F_51 ( V_53 , V_1274 , V_587 , V_355 -> V_546 ) ) )
goto V_61;
F_219 () ;
if ( F_202 ( V_355 -> V_693 ) &&
F_29 ( V_53 , V_1275 ) )
goto V_1276;
V_1269 = F_220 ( V_355 -> V_1269 ) ;
if ( V_1269 ) {
if ( F_104 ( V_53 , V_1277 , V_1269 -> V_1278 ) )
goto V_1276;
if ( V_1269 -> V_47 && F_51 ( V_53 , V_1279 ,
V_1269 -> V_47 , V_1269 -> V_138 ) )
goto V_1276;
}
V_1269 = F_220 ( V_355 -> V_691 ) ;
if ( V_1269 && V_1269 -> V_1280 ) {
if ( F_104 ( V_53 , V_1281 , V_1269 -> V_1278 ) )
goto V_1276;
if ( V_1269 -> V_47 && F_51 ( V_53 , V_1282 ,
V_1269 -> V_47 , V_1269 -> V_138 ) )
goto V_1276;
}
F_221 () ;
if ( V_355 -> V_541 &&
F_55 ( V_53 , V_1283 , V_355 -> V_541 ) )
goto V_61;
if ( F_55 ( V_53 , V_1284 , V_355 -> V_939 ) ||
F_28 ( V_53 , V_1285 , V_355 -> V_1286 -> V_60 ) ||
F_28 ( V_53 , V_1287 , V_355 -> V_1288 ) ||
F_28 ( V_53 , V_1289 ,
F_265 ( V_1200 - V_1265 -> V_1290 ) ) )
goto V_61;
if ( V_1265 -> V_1291 &&
F_104 ( V_53 , V_1292 ,
V_1265 -> V_1291 ) )
goto V_61;
switch ( V_7 -> V_18 . V_813 ) {
case V_814 :
if ( F_28 ( V_53 , V_1293 , V_355 -> signal ) )
goto V_61;
break;
case V_1294 :
if ( F_56 ( V_53 , V_1295 , V_355 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1265 == V_17 -> V_149 &&
F_28 ( V_53 , V_1296 ,
V_1297 ) )
goto V_61;
break;
case V_146 :
if ( V_1265 == V_17 -> V_149 &&
F_28 ( V_53 , V_1296 ,
V_1298 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1270 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_1276:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_266 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1264 * V_1182 ;
struct V_1 * V_17 ;
int V_499 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
F_267 ( & V_7 -> V_1299 ) ;
F_268 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1272 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_499 )
continue;
if ( F_263 ( V_32 , V_34 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_7 , V_17 , V_1182 ) < 0 ) {
V_105 -- ;
break;
}
}
F_269 ( & V_7 -> V_1299 ) ;
F_115 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_270 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_539 ,
bool V_1300 ,
struct V_1301 * V_1302 )
{
void * V_283 ;
struct V_4 * V_1303 ;
if ( ! V_1302 -> V_1286 && ! V_1300 )
return 0 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1304 ) ;
if ( ! V_283 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) )
goto V_61;
V_1303 = F_47 ( V_53 , V_1305 ) ;
if ( ! V_1303 )
goto V_61;
if ( V_1302 -> V_1286 &&
F_28 ( V_53 , V_1306 ,
V_1302 -> V_1286 -> V_60 ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1307 ) &&
F_56 ( V_53 , V_1308 , V_1302 -> V_1309 ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1310 ) &&
F_29 ( V_53 , V_1311 ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1312 ) &&
F_104 ( V_53 , V_1313 ,
V_1302 -> time ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1314 ) &&
F_104 ( V_53 , V_1315 ,
V_1302 -> V_1316 ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1317 ) &&
F_104 ( V_53 , V_1318 ,
V_1302 -> V_1319 ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1320 ) &&
F_104 ( V_53 , V_1321 ,
V_1302 -> V_1322 ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1323 ) &&
F_104 ( V_53 , V_1324 ,
V_1302 -> V_1325 ) )
goto V_61;
if ( ( V_1302 -> V_798 & V_1326 ) &&
F_104 ( V_53 , V_1327 ,
V_1302 -> V_1328 ) )
goto V_61;
F_48 ( V_53 , V_1303 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_271 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1301 V_1302 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1329 = V_34 -> args [ 2 ] ;
int V_355 ;
bool V_1330 ;
V_355 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_355 )
return V_355 ;
V_1330 = V_38 . V_40 [ V_1331 ] ;
if ( ! V_17 -> V_19 ) {
V_355 = - V_16 ;
goto V_881;
}
if ( ! V_7 -> V_351 -> V_1332 ) {
V_355 = - V_540 ;
goto V_881;
}
while ( 1 ) {
V_355 = F_272 ( V_7 , V_17 -> V_19 , V_1329 , & V_1302 ) ;
if ( V_355 == - V_655 )
break;
if ( V_355 )
goto V_881;
if ( V_1302 . V_1286 &&
V_1302 . V_1286 -> V_51 & V_62 ) {
V_1329 ++ ;
continue;
}
if ( F_270 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_17 -> V_19 , V_1330 , & V_1302 ) < 0 )
goto V_599;
V_1329 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_1329 ;
V_355 = V_32 -> V_47 ;
V_881:
F_21 ( V_7 ) ;
return V_355 ;
}
static bool F_273 ( V_22 V_1333 )
{
return ! ( V_1333 & ~ ( V_1334 |
V_1335 ) ) ;
}
static int F_274 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_546 , * V_594 , * V_1115 = NULL , * V_1336 = NULL ;
int V_35 , V_592 , V_1116 = 0 , V_1337 = 0 ;
enum V_701 V_702 ;
struct V_93 V_92 ;
bool V_1338 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_720 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_593 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_522 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_652 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1339 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1340 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_159 ;
bool V_1341 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_338 ; V_159 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_339 [ V_159 ] ) {
V_1341 = true ;
break;
}
}
if ( ! V_1341 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_385 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_522 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_594 = F_23 ( V_30 -> V_5 [ V_593 ] ) ;
V_592 = F_24 ( V_30 -> V_5 [ V_593 ] ) ;
if ( V_30 -> V_5 [ V_683 ] ) {
V_1115 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_702 = F_4 ( V_30 -> V_5 [ V_720 ] ) ;
if ( ! F_148 ( V_7 , V_702 , V_704 ) )
return - V_16 ;
if ( V_702 == V_706 &&
! V_30 -> V_5 [ V_1342 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1342 ] ) {
if ( V_702 != V_706 )
return - V_16 ;
V_1336 = F_23 ( V_30 -> V_5 [ V_1342 ] ) ;
V_1337 = F_24 ( V_30 -> V_5 [ V_1342 ] ) ;
if ( V_1337 < 4 )
return - V_16 ;
}
V_1338 = ! ! V_30 -> V_5 [ V_1343 ] ;
if ( V_1338 )
return 0 ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_275 ( V_7 , V_539 , V_55 , V_702 , V_546 ,
V_594 , V_592 , V_1115 , V_1116 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1336 , V_1337 ) ;
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static int F_151 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1344 * V_1345 ,
int V_1346 )
{
memset ( V_1345 , 0 , sizeof( * V_1345 ) ) ;
V_1345 -> V_1347 = V_30 -> V_5 [ V_1348 ] ;
if ( V_30 -> V_5 [ V_343 ] ) {
T_3 V_1349 ;
V_1349 = F_78 (
V_30 -> V_5 [ V_343 ] ) ;
V_1345 -> V_1350 = F_276 ( V_1349 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_342 ) &&
V_1349 != V_1351 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1352 ] )
V_1345 -> V_1353 = true ;
} else
V_1345 -> V_1350 = F_276 ( V_1351 ) ;
if ( V_30 -> V_5 [ V_1354 ] ) {
void * V_138 ;
int V_47 , V_159 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1354 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1354 ] ) ;
V_1345 -> V_1355 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1345 -> V_1355 > V_1346 )
return - V_16 ;
memcpy ( V_1345 -> V_1356 , V_138 , V_47 ) ;
for ( V_159 = 0 ; V_159 < V_1345 -> V_1355 ; V_159 ++ )
if ( ! F_277 (
& V_7 -> V_18 ,
V_1345 -> V_1356 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1357 ] ) {
V_1345 -> V_1358 =
F_4 ( V_30 -> V_5 [ V_1357 ] ) ;
if ( ! F_277 ( & V_7 -> V_18 ,
V_1345 -> V_1358 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1359 ] ) {
V_1345 -> V_1333 =
F_4 ( V_30 -> V_5 [ V_1359 ] ) ;
if ( ! F_273 ( V_1345 -> V_1333 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1360 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1360 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1360 ] ) ;
V_1345 -> V_1361 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1345 -> V_1361 > V_1362 )
return - V_16 ;
memcpy ( V_1345 -> V_1363 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_278 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1364 V_1365 = {} ;
const T_2 * V_546 , * V_594 ;
int V_35 , V_592 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_547 ] ||
! V_30 -> V_5 [ V_593 ] ||
! V_30 -> V_5 [ V_522 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_387 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_522 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_594 = F_23 ( V_30 -> V_5 [ V_593 ] ) ;
V_592 = F_24 ( V_30 -> V_5 [ V_593 ] ) ;
if ( V_30 -> V_5 [ V_683 ] ) {
V_1365 . V_1115 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1365 . V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
if ( V_30 -> V_5 [ V_1366 ] ) {
enum V_1367 V_1368 =
F_4 ( V_30 -> V_5 [ V_1366 ] ) ;
if ( V_1368 == V_1369 )
V_1365 . V_1370 = true ;
else if ( V_1368 != V_1371 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1372 ] )
V_1365 . V_1373 = F_23 ( V_30 -> V_5 [ V_1372 ] ) ;
if ( F_210 ( V_30 -> V_5 [ V_1374 ] ) )
V_1365 . V_51 |= V_1375 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1365 . V_1376 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1365 . V_1376 ) ) ;
if ( V_30 -> V_5 [ V_931 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1365 . V_902 ,
F_23 ( V_30 -> V_5 [ V_931 ] ) ,
sizeof( V_1365 . V_902 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1377 ] ) )
V_1365 . V_51 |= V_1378 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_1365 . V_1379 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_1365 . V_1379 ) ) ;
if ( V_30 -> V_5 [ V_932 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] )
return - V_16 ;
memcpy ( & V_1365 . V_903 ,
F_23 ( V_30 -> V_5 [ V_932 ] ) ,
sizeof( V_1365 . V_903 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1380 ] ) ) {
if ( ! ( V_7 -> V_18 . V_291 &
V_1381 ) ||
! ( V_7 -> V_18 . V_291 & V_1382 ) )
return - V_16 ;
V_1365 . V_51 |= V_1383 ;
}
V_35 = F_151 ( V_7 , V_30 , & V_1365 . V_722 , 1 ) ;
if ( ! V_35 ) {
F_113 ( V_539 -> V_28 ) ;
V_35 = F_279 ( V_7 , V_539 , V_55 , V_546 ,
V_594 , V_592 , & V_1365 ) ;
F_115 ( V_539 -> V_28 ) ;
}
return V_35 ;
}
static int F_280 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
const T_2 * V_1115 = NULL , * V_546 ;
int V_1116 = 0 , V_35 ;
T_3 V_965 ;
bool V_1338 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_964 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_389 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_965 = F_78 ( V_30 -> V_5 [ V_964 ] ) ;
if ( V_965 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_683 ] ) {
V_1115 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_1338 = ! ! V_30 -> V_5 [ V_1343 ] ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_281 ( V_7 , V_539 , V_546 , V_1115 , V_1116 , V_965 ,
V_1338 ) ;
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static int F_282 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
const T_2 * V_1115 = NULL , * V_546 ;
int V_1116 = 0 , V_35 ;
T_3 V_965 ;
bool V_1338 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_964 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_391 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_965 = F_78 ( V_30 -> V_5 [ V_964 ] ) ;
if ( V_965 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_683 ] ) {
V_1115 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_1338 = ! ! V_30 -> V_5 [ V_1343 ] ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_283 ( V_7 , V_539 , V_546 , V_1115 , V_1116 , V_965 ,
V_1338 ) ;
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static bool
F_284 ( struct V_6 * V_7 ,
int V_1384 [ V_362 ] ,
int V_1385 )
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
if ( V_240 -> V_262 [ V_159 ] . V_264 == V_1385 ) {
V_1384 [ V_290 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_285 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1386 V_1387 ;
struct V_18 * V_18 ;
struct V_130 * V_1388 = NULL ;
int V_35 ;
memset ( & V_1387 , 0 , sizeof( V_1387 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_593 ] ||
! F_24 ( V_30 -> V_5 [ V_593 ] ) )
return - V_16 ;
V_1387 . V_541 = 100 ;
if ( V_30 -> V_5 [ V_709 ] ) {
V_1387 . V_541 =
F_4 ( V_30 -> V_5 [ V_709 ] ) ;
if ( V_1387 . V_541 < 1 || V_1387 . V_541 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_393 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_146 )
return - V_540 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_547 ] ) {
V_1387 . V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! F_120 ( V_1387 . V_546 ) )
return - V_16 ;
}
V_1387 . V_594 = F_23 ( V_30 -> V_5 [ V_593 ] ) ;
V_1387 . V_592 = F_24 ( V_30 -> V_5 [ V_593 ] ) ;
if ( V_30 -> V_5 [ V_683 ] ) {
V_1387 . V_1115 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1387 . V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1387 . V_520 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_286 ( & V_7 -> V_18 , & V_1387 . V_520 ,
V_146 ) )
return - V_16 ;
switch ( V_1387 . V_520 . V_523 ) {
case V_537 :
case V_538 :
case V_524 :
break;
case V_579 :
case V_580 :
if ( ! ( V_7 -> V_18 . V_291 & V_1389 ) )
return - V_16 ;
break;
case V_1390 :
case V_1391 :
case V_1392 :
if ( ! ( V_7 -> V_18 . V_291 & V_1389 ) )
return - V_16 ;
if ( ! F_287 ( & V_7 -> V_18 ,
V_1393 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1387 . V_1394 = ! ! V_30 -> V_5 [ V_1395 ] ;
V_1387 . V_718 = ! ! V_30 -> V_5 [ V_719 ] ;
if ( V_30 -> V_5 [ V_1012 ] ) {
T_2 * V_1190 =
F_23 ( V_30 -> V_5 [ V_1012 ] ) ;
int V_1396 =
F_24 ( V_30 -> V_5 [ V_1012 ] ) ;
struct V_239 * V_240 =
V_18 -> V_363 [ V_1387 . V_520 . V_55 -> V_290 ] ;
V_35 = F_238 ( V_240 , V_1190 , V_1396 ,
& V_1387 . V_1013 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1387 . V_1376 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1387 . V_1376 ) ) ;
if ( V_30 -> V_5 [ V_931 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1387 . V_902 ,
F_23 ( V_30 -> V_5 [ V_931 ] ) ,
sizeof( V_1387 . V_902 ) ) ;
}
if ( V_30 -> V_5 [ V_1397 ] &&
! F_284 ( V_7 , V_1387 . V_1384 ,
F_4 ( V_30 -> V_5 [ V_1397 ] ) ) )
return - V_16 ;
if ( V_1387 . V_718 && V_30 -> V_5 [ V_1398 ] ) {
bool V_132 = false ;
V_1388 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1398 ] ,
& V_132 ) ;
if ( F_17 ( V_1388 ) )
return F_18 ( V_1388 ) ;
if ( ( V_1387 . V_520 . V_523 != V_524 ) &&
V_132 ) {
F_288 ( V_1388 ) ;
return - V_16 ;
}
}
V_1387 . V_1347 =
F_210 ( V_30 -> V_5 [ V_1348 ] ) ;
V_1387 . V_1399 =
F_210 ( V_30 -> V_5 [ V_1400 ] ) ;
V_35 = F_289 ( V_7 , V_539 , & V_1387 , V_1388 ) ;
if ( V_35 )
F_288 ( V_1388 ) ;
return V_35 ;
}
static int F_290 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1401 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_146 )
return - V_540 ;
return F_291 ( V_7 , V_539 , false ) ;
}
static int F_292 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
int V_1384 [ V_362 ] ;
V_22 V_1402 ;
int V_35 ;
if ( V_539 -> V_28 -> V_141 != V_146 &&
V_539 -> V_28 -> V_141 != V_145 &&
V_539 -> V_28 -> V_141 != V_152 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_433 )
return - V_540 ;
memset ( V_1384 , 0 , sizeof( V_1384 ) ) ;
if ( ! V_30 -> V_5 [ V_1397 ] )
return - V_16 ;
V_1402 = F_4 ( V_30 -> V_5 [ V_1397 ] ) ;
if ( ! F_284 ( V_7 , V_1384 , V_1402 ) )
return - V_16 ;
V_35 = F_293 ( V_7 , V_539 , V_1384 ) ;
return V_35 ;
}
static struct V_31 *
F_294 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1403 ,
V_22 V_49 , V_22 V_50 , enum V_280 V_52 ,
enum V_762 V_45 ,
const struct V_481 * V_30 ,
T_13 V_1404 )
{
struct V_31 * V_32 ;
void * V_283 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1403 + 100 , V_1404 ) ;
if ( ! V_32 )
return NULL ;
V_283 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_295 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1405 ,
V_30 -> V_1406 ) )
goto V_61;
if ( F_28 ( V_32 , V_1407 ,
V_30 -> V_1408 ) )
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
F_295 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_296 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_280 V_52 ,
enum V_762 V_45 ,
int V_1409 ,
int V_1403 , T_13 V_1404 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_481 * V_30 ;
switch ( V_52 ) {
case V_1410 :
if ( F_59 ( V_1409 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1411 :
if ( F_59 ( V_1409 < 0 ||
V_1409 >= V_18 -> V_485 ) )
return NULL ;
V_30 = & V_18 -> V_487 [ V_1409 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_294 ( V_7 , V_17 , V_1403 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1404 ) ;
}
void F_297 ( struct V_31 * V_32 , T_13 V_1404 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1412 V_1413 = V_1414 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
if ( V_138 -> F_237 == V_483 )
V_1413 = V_1415 ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1413 , V_1404 ) ;
}
static int F_298 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_435 )
return - V_540 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1416 ] )
return - V_16 ;
V_7 -> V_1417 = V_30 ;
V_35 = F_299 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1416 ] ) ,
F_24 ( V_30 -> V_5 [ V_1416 ] ) ) ;
V_7 -> V_1417 = NULL ;
return V_35 ;
}
static int F_300 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1418 ;
void * V_138 = NULL ;
int V_1419 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1418 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_881;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_881;
}
V_1418 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1416 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1416 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1419 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1418 ) ;
if ( ! V_7 ) {
V_35 = - V_655 ;
goto V_881;
}
if ( ! V_7 -> V_351 -> V_1420 ) {
V_35 = - V_540 ;
goto V_881;
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_1410 ) ;
struct V_4 * V_1421 ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_1418 ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1421 = F_47 ( V_32 , V_1416 ) ;
if ( ! V_1421 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = F_301 ( V_7 , V_32 , V_34 , V_138 , V_1419 ) ;
F_48 ( V_32 , V_1421 ) ;
if ( V_35 == - V_91 || V_35 == - V_655 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_881;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1418 + 1 ;
V_881:
F_20 () ;
return V_35 ;
}
static int F_302 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1422 V_449 ;
struct V_18 * V_18 ;
struct V_130 * V_1388 = NULL ;
int V_35 ;
memset ( & V_449 , 0 , sizeof( V_449 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_593 ] ||
! F_24 ( V_30 -> V_5 [ V_593 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_720 ] ) {
V_449 . V_702 =
F_4 ( V_30 -> V_5 [ V_720 ] ) ;
if ( ! F_148 ( V_7 , V_449 . V_702 ,
V_450 ) )
return - V_16 ;
} else
V_449 . V_702 = V_721 ;
V_449 . V_718 = V_30 -> V_5 [ V_719 ] ;
V_35 = F_151 ( V_7 , V_30 , & V_449 . V_722 ,
V_723 ) ;
if ( V_35 )
return V_35 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
V_18 = & V_7 -> V_18 ;
V_449 . V_1423 = - 1 ;
if ( V_30 -> V_5 [ V_1424 ] &&
( V_18 -> V_51 & V_330 ) ) {
V_449 . V_1423 =
F_78 ( V_30 -> V_5 [ V_1424 ] ) ;
}
if ( V_30 -> V_5 [ V_547 ] )
V_449 . V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
else if ( V_30 -> V_5 [ V_1425 ] )
V_449 . V_1426 =
F_23 ( V_30 -> V_5 [ V_1425 ] ) ;
V_449 . V_594 = F_23 ( V_30 -> V_5 [ V_593 ] ) ;
V_449 . V_592 = F_24 ( V_30 -> V_5 [ V_593 ] ) ;
if ( V_30 -> V_5 [ V_683 ] ) {
V_449 . V_1115 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_449 . V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
if ( V_30 -> V_5 [ V_1366 ] ) {
V_449 . V_1368 = F_4 ( V_30 -> V_5 [ V_1366 ] ) ;
if ( V_449 . V_1368 != V_1369 &&
V_449 . V_1368 != V_1371 )
return - V_16 ;
} else {
V_449 . V_1368 = V_1371 ;
}
if ( V_30 -> V_5 [ V_522 ] ) {
V_449 . V_1286 = F_44 (
V_18 , V_30 -> V_5 [ V_522 ] ) ;
if ( ! V_449 . V_1286 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1427 ] ) {
V_449 . V_1428 = F_44 (
V_18 , V_30 -> V_5 [ V_1427 ] ) ;
if ( ! V_449 . V_1428 )
return - V_16 ;
}
if ( V_449 . V_718 && V_30 -> V_5 [ V_1398 ] ) {
V_1388 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1398 ] , NULL ) ;
if ( F_17 ( V_1388 ) )
return F_18 ( V_1388 ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1374 ] ) )
V_449 . V_51 |= V_1375 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_449 . V_1376 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_449 . V_1376 ) ) ;
if ( V_30 -> V_5 [ V_931 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] ) {
F_288 ( V_1388 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_902 ,
F_23 ( V_30 -> V_5 [ V_931 ] ) ,
sizeof( V_449 . V_902 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1377 ] ) )
V_449 . V_51 |= V_1378 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_449 . V_1379 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_449 . V_1379 ) ) ;
if ( V_30 -> V_5 [ V_932 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] ) {
F_288 ( V_1388 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_903 ,
F_23 ( V_30 -> V_5 [ V_932 ] ) ,
sizeof( V_449 . V_903 ) ) ;
}
if ( F_210 ( V_30 -> V_5 [ V_1380 ] ) ) {
if ( ! ( V_7 -> V_18 . V_291 &
V_1381 ) ||
! ( V_7 -> V_18 . V_291 & V_1382 ) ) {
F_288 ( V_1388 ) ;
return - V_16 ;
}
V_449 . V_51 |= V_1383 ;
}
F_113 ( V_539 -> V_28 ) ;
V_35 = F_303 ( V_7 , V_539 , & V_449 , V_1388 , NULL ) ;
F_115 ( V_539 -> V_28 ) ;
if ( V_35 )
F_288 ( V_1388 ) ;
return V_35 ;
}
static int F_304 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_3 V_1429 ;
int V_496 ;
if ( ! V_30 -> V_5 [ V_964 ] )
V_1429 = V_1430 ;
else
V_1429 = F_78 ( V_30 -> V_5 [ V_964 ] ) ;
if ( V_1429 == 0 )
return - V_16 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
F_113 ( V_539 -> V_28 ) ;
V_496 = F_305 ( V_7 , V_539 , V_1429 , true ) ;
F_115 ( V_539 -> V_28 ) ;
return V_496 ;
}
static int F_306 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1431 ] ) {
V_22 V_1432 = F_4 ( V_30 -> V_5 [ V_1431 ] ) ;
V_2 = F_307 ( V_1432 ) ;
} else if ( V_30 -> V_5 [ V_1433 ] ) {
V_22 V_1434 = F_4 ( V_30 -> V_5 [ V_1433 ] ) ;
V_2 = F_308 ( V_1434 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_309 ( V_7 , V_2 ) ;
F_310 ( V_2 ) ;
return V_35 ;
}
static int F_311 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int (* F_312)( struct V_18 * V_18 , struct V_25 * V_539 ,
struct V_1435 * V_1436 ) = NULL ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1435 V_1436 ;
memset ( & V_1436 , 0 , sizeof( struct V_1435 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1437 ] )
return - V_16 ;
V_1436 . V_1438 = F_23 ( V_30 -> V_5 [ V_1437 ] ) ;
V_1436 . V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
switch ( V_30 -> V_1439 -> V_52 ) {
case V_1440 :
F_312 = V_7 -> V_351 -> V_397 ;
break;
case V_1441 :
F_312 = V_7 -> V_351 -> V_399 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_312 )
return - V_540 ;
return F_312 ( & V_7 -> V_18 , V_539 , & V_1436 ) ;
}
static int F_313 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_401 )
return - V_540 ;
return F_314 ( V_7 , V_539 ) ;
}
static int F_315 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 V_1442 , V_1443 ;
V_22 V_1444 = 0 ;
T_3 V_1445 ;
T_2 * V_1446 ;
bool V_1447 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_418 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1448 ] ||
! V_30 -> V_5 [ V_1449 ] ||
! V_30 -> V_5 [ V_1450 ] ||
! V_30 -> V_5 [ V_683 ] ||
! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_1446 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_1442 = F_34 ( V_30 -> V_5 [ V_1448 ] ) ;
V_1445 = F_78 ( V_30 -> V_5 [ V_1449 ] ) ;
V_1443 = F_34 ( V_30 -> V_5 [ V_1450 ] ) ;
V_1447 = F_210 ( V_30 -> V_5 [ V_1451 ] ) ;
if ( V_30 -> V_5 [ V_1452 ] )
V_1444 =
F_4 ( V_30 -> V_5 [ V_1452 ] ) ;
return F_316 ( V_7 , V_539 , V_1446 , V_1442 ,
V_1443 , V_1445 , V_1444 ,
V_1447 ,
F_23 ( V_30 -> V_5 [ V_683 ] ) ,
F_24 ( V_30 -> V_5 [ V_683 ] ) ) ;
}
static int F_317 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
enum V_1453 V_1454 ;
T_2 * V_1446 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_420 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1455 ] ||
! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_1454 = F_34 ( V_30 -> V_5 [ V_1455 ] ) ;
V_1446 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
return F_318 ( V_7 , V_539 , V_1446 , V_1454 ) ;
}
static int F_319 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
struct V_519 V_520 ;
struct V_31 * V_53 ;
void * V_283 ;
T_1 V_647 ;
V_22 V_1456 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_522 ] ||
! V_30 -> V_5 [ V_1457 ] )
return - V_16 ;
V_1456 = F_4 ( V_30 -> V_5 [ V_1457 ] ) ;
if ( ! V_7 -> V_351 -> V_404 ||
! ( V_7 -> V_18 . V_51 & V_403 ) )
return - V_540 ;
if ( V_1456 < V_1458 ||
V_1456 > V_7 -> V_18 . V_454 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1459 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_657;
}
V_35 = F_320 ( V_7 , V_17 , V_520 . V_55 ,
V_1456 , & V_647 ) ;
if ( V_35 )
goto V_657;
if ( F_104 ( V_53 , V_1460 , V_647 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_657:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_321 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
T_1 V_647 ;
if ( ! V_30 -> V_5 [ V_1460 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1461 )
return - V_540 ;
V_647 = F_5 ( V_30 -> V_5 [ V_1460 ] ) ;
return F_322 ( V_7 , V_17 , V_647 ) ;
}
static V_22 F_323 ( struct V_239 * V_240 ,
T_2 * V_1190 , T_2 V_1462 )
{
T_2 V_159 ;
V_22 V_747 = 0 ;
for ( V_159 = 0 ; V_159 < V_1462 ; V_159 ++ ) {
int V_244 = ( V_1190 [ V_159 ] & 0x7f ) * 5 ;
int V_1463 ;
for ( V_1463 = 0 ; V_1463 < V_240 -> V_261 ; V_1463 ++ ) {
struct V_243 * V_1464 =
& V_240 -> V_262 [ V_1463 ] ;
if ( V_244 == V_1464 -> V_264 ) {
V_747 |= 1 << V_1463 ;
break;
}
}
if ( V_1463 == V_240 -> V_261 )
return 0 ;
}
return V_747 ;
}
static bool F_324 ( struct V_239 * V_240 ,
T_2 * V_1190 , T_2 V_1462 ,
T_2 V_248 [ V_1465 ] )
{
T_2 V_159 ;
memset ( V_248 , 0 , V_1465 ) ;
for ( V_159 = 0 ; V_159 < V_1462 ; V_159 ++ ) {
int V_1463 , V_1466 ;
V_1463 = V_1190 [ V_159 ] / 8 ;
V_1466 = F_158 ( V_1190 [ V_159 ] % 8 ) ;
if ( ( V_1463 < 0 ) || ( V_1463 >= V_1465 ) )
return false ;
if ( V_240 -> V_245 . V_248 . V_1467 [ V_1463 ] & V_1466 )
V_248 [ V_1463 ] |= V_1466 ;
else
return false ;
}
return true ;
}
static T_3 F_325 ( T_2 V_1468 )
{
T_3 V_1469 = 0 ;
switch ( V_1468 ) {
case V_1470 :
break;
case V_1471 :
V_1469 = 0x00FF ;
break;
case V_1472 :
V_1469 = 0x01FF ;
break;
case V_1473 :
V_1469 = 0x03FF ;
break;
default:
break;
}
return V_1469 ;
}
static void F_326 ( T_3 V_1468 ,
T_3 V_1474 [ V_1475 ] )
{
T_2 V_785 ;
for ( V_785 = 0 ; V_785 < V_1475 ; V_785 ++ ) {
V_1474 [ V_785 ] = F_325 ( V_1468 & 0x03 ) ;
V_1468 >>= 2 ;
}
}
static bool F_327 ( struct V_239 * V_240 ,
struct V_1476 * V_823 ,
T_3 V_248 [ V_1475 ] )
{
T_3 V_1477 = F_328 ( V_240 -> V_255 . V_258 . V_1477 ) ;
T_3 V_1478 [ V_1475 ] = {} ;
T_2 V_159 ;
if ( ! V_240 -> V_255 . V_256 )
return false ;
memset ( V_248 , 0 , sizeof( T_3 ) * V_1475 ) ;
F_326 ( V_1477 , V_1478 ) ;
for ( V_159 = 0 ; V_159 < V_1475 ; V_159 ++ ) {
if ( ( V_1478 [ V_159 ] & V_823 -> V_248 [ V_159 ] ) == V_823 -> V_248 [ V_159 ] )
V_248 [ V_159 ] = V_823 -> V_248 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_329 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1479 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1480 V_747 ;
int V_134 , V_159 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_4 * V_1481 ;
struct V_239 * V_240 ;
T_3 V_1482 ;
if ( ! V_7 -> V_351 -> V_406 )
return - V_540 ;
memset ( & V_747 , 0 , sizeof( V_747 ) ) ;
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ ) {
V_240 = V_7 -> V_18 . V_363 [ V_159 ] ;
if ( ! V_240 )
continue;
V_747 . V_1483 [ V_159 ] . V_1484 = ( 1 << V_240 -> V_261 ) - 1 ;
memcpy ( V_747 . V_1483 [ V_159 ] . V_1485 ,
V_240 -> V_245 . V_248 . V_1467 ,
sizeof( V_747 . V_1483 [ V_159 ] . V_1485 ) ) ;
if ( ! V_240 -> V_255 . V_256 )
continue;
V_1482 = F_328 ( V_240 -> V_255 . V_258 . V_1477 ) ;
F_326 ( V_1482 , V_747 . V_1483 [ V_159 ] . V_258 ) ;
}
if ( ! V_30 -> V_5 [ V_1486 ] )
goto V_599;
F_114 ( V_1487 > V_1465 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_289 V_290 = F_237 ( V_1481 ) ;
int V_35 ;
if ( V_290 < 0 || V_290 >= V_362 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_290 ] ;
if ( V_240 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1479 , F_23 ( V_1481 ) ,
F_24 ( V_1481 ) , V_1488 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1489 ] ) {
V_747 . V_1483 [ V_290 ] . V_1484 = F_323 (
V_240 ,
F_23 ( V_95 [ V_1489 ] ) ,
F_24 ( V_95 [ V_1489 ] ) ) ;
if ( ( V_747 . V_1483 [ V_290 ] . V_1484 == 0 ) &&
F_24 ( V_95 [ V_1489 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1490 ] ) {
if ( ! F_324 (
V_240 ,
F_23 ( V_95 [ V_1490 ] ) ,
F_24 ( V_95 [ V_1490 ] ) ,
V_747 . V_1483 [ V_290 ] . V_1485 ) )
return - V_16 ;
}
if ( V_95 [ V_1491 ] ) {
if ( ! F_327 (
V_240 ,
F_23 ( V_95 [ V_1491 ] ) ,
V_747 . V_1483 [ V_290 ] . V_258 ) )
return - V_16 ;
}
if ( V_95 [ V_1492 ] ) {
V_747 . V_1483 [ V_290 ] . V_1493 =
F_34 ( V_95 [ V_1492 ] ) ;
if ( V_747 . V_1483 [ V_290 ] . V_1493 > V_1494 )
return - V_16 ;
}
if ( V_747 . V_1483 [ V_290 ] . V_1484 == 0 ) {
if ( ! ( V_7 -> V_18 . V_363 [ V_290 ] -> V_245 . V_246 ||
V_7 -> V_18 . V_363 [ V_290 ] -> V_255 . V_256 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_1465 ; V_159 ++ )
if ( V_747 . V_1483 [ V_290 ] . V_1485 [ V_159 ] )
goto V_599;
for ( V_159 = 0 ; V_159 < V_1475 ; V_159 ++ )
if ( V_747 . V_1483 [ V_290 ] . V_258 [ V_159 ] )
goto V_599;
return - V_16 ;
}
}
V_599:
return F_330 ( V_7 , V_539 , NULL , & V_747 ) ;
}
static int F_331 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
T_3 V_1495 = V_277 | V_1496 ;
if ( ! V_30 -> V_5 [ V_1497 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_276 ] )
V_1495 = F_78 ( V_30 -> V_5 [ V_276 ] ) ;
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
return - V_540 ;
}
if ( ! V_7 -> V_351 -> V_408 )
return - V_540 ;
return F_332 ( V_17 , V_30 -> V_504 , V_1495 ,
F_23 ( V_30 -> V_5 [ V_1497 ] ) ,
F_24 ( V_30 -> V_5 [ V_1497 ] ) ) ;
}
static int F_333 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
struct V_519 V_520 ;
int V_35 ;
void * V_283 = NULL ;
T_1 V_647 ;
struct V_31 * V_53 = NULL ;
struct V_1498 V_137 = {
. V_1499 =
V_30 -> V_5 [ V_1500 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1501 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_408 )
return - V_540 ;
switch ( V_17 -> V_141 ) {
case V_154 :
if ( ! V_30 -> V_5 [ V_522 ] )
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
return - V_540 ;
}
if ( V_30 -> V_5 [ V_1457 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1502 = F_4 ( V_30 -> V_5 [ V_1457 ] ) ;
if ( V_137 . V_1502 < V_1458 ||
V_137 . V_1502 > V_7 -> V_18 . V_454 )
return - V_16 ;
}
V_137 . V_1503 = V_30 -> V_5 [ V_456 ] ;
if ( V_137 . V_1503 && ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1197 = F_210 ( V_30 -> V_5 [ V_1198 ] ) ;
V_520 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_522 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_520 . V_55 && V_137 . V_1503 )
return - V_16 ;
V_137 . V_1504 = F_23 ( V_30 -> V_5 [ V_1501 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1501 ] ) ;
if ( V_30 -> V_5 [ V_1505 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1505 ] ) ;
int V_159 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1506 = V_47 / sizeof( T_3 ) ;
V_137 . V_1507 =
F_23 ( V_30 -> V_5 [ V_1505 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1506 ; V_159 ++ ) {
if ( V_137 . V_1507 [ V_159 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1499 ) {
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1508 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_657;
}
}
V_137 . V_55 = V_520 . V_55 ;
V_35 = F_334 ( V_7 , V_17 , & V_137 , & V_647 ) ;
if ( V_35 )
goto V_657;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1460 , V_647 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_657:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_335 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
T_1 V_647 ;
if ( ! V_30 -> V_5 [ V_1460 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_410 )
return - V_540 ;
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
return - V_540 ;
}
V_647 = F_5 ( V_30 -> V_5 [ V_1460 ] ) ;
return F_336 ( V_7 , V_17 , V_647 ) ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 V_1509 ;
bool V_282 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1510 ] )
return - V_16 ;
V_1509 = F_4 ( V_30 -> V_5 [ V_1510 ] ) ;
if ( V_1509 != V_1511 && V_1509 != V_1512 )
return - V_16 ;
V_17 = V_539 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1513 )
return - V_540 ;
V_282 = ( V_1509 == V_1512 ) ? true : false ;
if ( V_282 == V_17 -> V_1514 )
return 0 ;
V_35 = F_338 ( V_7 , V_539 , V_282 , V_17 -> V_1515 ) ;
if ( ! V_35 )
V_17 -> V_1514 = V_282 ;
return V_35 ;
}
static int F_339 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
enum V_1516 V_1509 ;
struct V_1 * V_17 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_31 * V_53 ;
void * V_283 ;
int V_35 ;
V_17 = V_539 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1513 )
return - V_540 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1517 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_657;
}
if ( V_17 -> V_1514 )
V_1509 = V_1512 ;
else
V_1509 = V_1511 ;
if ( F_28 ( V_53 , V_1510 , V_1509 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_657:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_340 ( struct V_29 * V_30 ,
V_22 V_244 , V_22 V_1518 , V_22 V_1519 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
if ( V_244 > 100 || V_1519 > V_1520 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1521 )
return - V_540 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_540 ;
return F_341 ( V_7 , V_539 , V_244 , V_1518 , V_1519 ) ;
}
static int F_342 ( struct V_29 * V_30 ,
T_12 V_1522 , V_22 V_1523 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
if ( V_1522 > 0 )
return - V_16 ;
if ( V_1522 == 0 )
V_1523 = 0 ;
if ( ! V_7 -> V_351 -> V_1524 )
return - V_540 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_540 ;
return F_343 ( V_7 , V_539 , V_1522 , V_1523 ) ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1525 + 1 ] ;
struct V_4 * V_1526 ;
int V_35 ;
V_1526 = V_30 -> V_5 [ V_1527 ] ;
if ( ! V_1526 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1525 , V_1526 ,
V_1528 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1529 ] &&
V_5 [ V_1530 ] ) {
T_12 V_1522 = V_1094 ( V_5 [ V_1529 ] ) ;
V_22 V_1523 = F_4 ( V_5 [ V_1530 ] ) ;
return F_342 ( V_30 , V_1522 , V_1523 ) ;
}
if ( V_5 [ V_1531 ] &&
V_5 [ V_1532 ] &&
V_5 [ V_1533 ] ) {
V_22 V_244 = F_4 ( V_5 [ V_1531 ] ) ;
V_22 V_1518 = F_4 ( V_5 [ V_1532 ] ) ;
V_22 V_1519 = F_4 ( V_5 [ V_1533 ] ) ;
return F_340 ( V_30 , V_244 , V_1518 , V_1519 ) ;
}
return - V_16 ;
}
static int F_345 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1534 V_1097 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1097 . V_520 ) ;
if ( V_35 )
return V_35 ;
return F_346 ( V_7 , V_539 , & V_1097 ) ;
}
static int F_347 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
return F_348 ( V_7 , V_539 ) ;
}
static int F_349 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1028 V_1090 ;
struct V_1096 V_1097 ;
int V_35 ;
memcpy ( & V_1090 , & V_1032 , sizeof( V_1090 ) ) ;
memcpy ( & V_1097 , & V_1535 , sizeof( V_1097 ) ) ;
if ( V_30 -> V_5 [ V_1034 ] ) {
V_35 = F_207 ( V_30 , & V_1090 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_617 ] ||
! F_24 ( V_30 -> V_5 [ V_617 ] ) )
return - V_16 ;
V_1097 . V_1536 = F_23 ( V_30 -> V_5 [ V_617 ] ) ;
V_1097 . V_1031 = F_24 ( V_30 -> V_5 [ V_617 ] ) ;
if ( V_30 -> V_5 [ V_1397 ] &&
! F_284 ( V_7 , V_1097 . V_1384 ,
F_4 ( V_30 -> V_5 [ V_1397 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_709 ] ) {
V_1097 . V_541 =
F_4 ( V_30 -> V_5 [ V_709 ] ) ;
if ( V_1097 . V_541 < 10 ||
V_1097 . V_541 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_710 ] ) {
V_1097 . V_712 =
F_4 ( V_30 -> V_5 [ V_710 ] ) ;
if ( V_1097 . V_712 < 1 || V_1097 . V_712 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1099 ] ) {
V_35 = F_209 ( V_30 , & V_1097 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1097 . V_1119 )
V_1090 . V_1050 = false ;
if ( V_30 -> V_5 [ V_522 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1097 . V_520 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1097 . V_520 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_1012 ] ) {
T_2 * V_1190 = F_23 ( V_30 -> V_5 [ V_1012 ] ) ;
int V_1396 =
F_24 ( V_30 -> V_5 [ V_1012 ] ) ;
struct V_239 * V_240 ;
if ( ! V_1097 . V_520 . V_55 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_1097 . V_520 . V_55 -> V_290 ] ;
V_35 = F_238 ( V_240 , V_1190 , V_1396 ,
& V_1097 . V_1013 ) ;
if ( V_35 )
return V_35 ;
}
return F_350 ( V_7 , V_539 , & V_1097 , & V_1090 ) ;
}
static int F_351 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
return F_352 ( V_7 , V_539 ) ;
}
static int F_353 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1537 * V_189 = V_7 -> V_18 . V_1538 ;
struct V_4 * V_1539 , * V_1540 ;
int V_159 , V_1541 ;
if ( ! V_189 -> V_219 )
return 0 ;
V_1539 = F_47 ( V_53 , V_228 ) ;
if ( ! V_1539 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_189 -> V_219 ; V_159 ++ ) {
V_1540 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1540 )
return - V_91 ;
V_1541 = V_189 -> V_1542 [ V_159 ] . V_1543 ;
if ( F_51 ( V_53 , V_1544 , F_245 ( V_1541 , 8 ) ,
V_189 -> V_1542 [ V_159 ] . V_747 ) ||
F_51 ( V_53 , V_1545 , V_1541 ,
V_189 -> V_1542 [ V_159 ] . V_1546 ) ||
F_28 ( V_53 , V_1547 ,
V_189 -> V_1542 [ V_159 ] . V_1548 ) )
return - V_91 ;
F_48 ( V_53 , V_1540 ) ;
}
F_48 ( V_53 , V_1539 ) ;
return 0 ;
}
static int F_354 ( struct V_31 * V_53 ,
struct V_1549 * V_188 )
{
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_355 ( V_53 , V_1550 , V_188 -> V_1551 ) ||
F_355 ( V_53 , V_1552 , V_188 -> V_967 ) ||
F_51 ( V_53 , V_1553 , V_587 , V_188 -> V_1554 ) ||
F_55 ( V_53 , V_1555 , V_188 -> V_1556 ) ||
F_55 ( V_53 , V_1557 , V_188 -> V_1558 ) ||
F_51 ( V_53 , V_192 ,
V_188 -> V_1559 , V_188 -> V_1560 ) ||
F_28 ( V_53 , V_197 ,
V_188 -> V_1561 ) ||
F_51 ( V_53 , V_199 ,
V_188 -> V_1562 , V_188 -> V_1563 ) ||
F_51 ( V_53 , V_1564 ,
F_245 ( V_188 -> V_1562 , 8 ) , V_188 -> V_1565 ) )
return - V_91 ;
if ( V_188 -> V_1566 . V_47 &&
F_51 ( V_53 , V_194 ,
sizeof( V_188 -> V_1566 ) , & V_188 -> V_1566 ) )
return - V_91 ;
if ( V_188 -> V_1567 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_188 -> V_1567 ) + V_188 -> V_1568 ,
& V_188 -> V_1567 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_356 ( struct V_31 * V_53 ,
struct V_1203 * V_1365 )
{
struct V_4 * V_1569 , * V_1172 , * V_1570 , * V_1571 , * V_1207 , * V_1572 ;
int V_159 ;
if ( ! V_1365 )
return 0 ;
V_1569 = F_47 ( V_53 , V_230 ) ;
if ( ! V_1569 )
return - V_91 ;
if ( V_1365 -> V_1225 == 1 &&
F_28 ( V_53 , V_1206 ,
V_1365 -> V_1207 [ 0 ] . V_1205 * 1000 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1232 , V_1365 -> V_1233 ) )
return - V_91 ;
V_1172 = F_47 ( V_53 , V_1186 ) ;
if ( ! V_1172 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1365 -> V_366 ; V_159 ++ )
F_28 ( V_53 , V_159 , V_1365 -> V_367 [ V_159 ] -> V_60 ) ;
F_48 ( V_53 , V_1172 ) ;
if ( V_1365 -> V_1215 ) {
V_1570 = F_47 ( V_53 , V_1219 ) ;
for ( V_159 = 0 ; V_159 < V_1365 -> V_1215 ; V_159 ++ ) {
V_1571 = F_47 ( V_53 , V_159 ) ;
F_51 ( V_53 , V_1222 ,
V_1365 -> V_1224 [ V_159 ] . V_594 . V_592 ,
V_1365 -> V_1224 [ V_159 ] . V_594 . V_594 ) ;
F_48 ( V_53 , V_1571 ) ;
}
F_48 ( V_53 , V_1570 ) ;
}
V_1207 = F_47 ( V_53 , V_1204 ) ;
if ( ! V_1207 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1365 -> V_1225 ; V_159 ++ ) {
V_1572 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1572 ||
F_28 ( V_53 , V_1212 ,
V_1365 -> V_1207 [ V_159 ] . V_1205 ) ||
( V_1365 -> V_1207 [ V_159 ] . V_1214 &&
F_28 ( V_53 , V_1213 ,
V_1365 -> V_1207 [ V_159 ] . V_1214 ) ) )
return - V_91 ;
F_48 ( V_53 , V_1572 ) ;
}
F_48 ( V_53 , V_1207 ) ;
F_48 ( V_53 , V_1569 ) ;
return 0 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1573 = V_600 ;
if ( ! V_7 -> V_18 . V_189 )
return - V_540 ;
if ( V_7 -> V_18 . V_1538 && V_7 -> V_18 . V_1538 -> V_188 ) {
V_1573 += V_7 -> V_18 . V_1538 -> V_188 -> V_1568 +
V_7 -> V_18 . V_1538 -> V_188 -> V_1559 +
V_7 -> V_18 . V_1538 -> V_188 -> V_1562 +
V_7 -> V_18 . V_1538 -> V_188 -> V_1562 / 8 ;
}
V_53 = F_74 ( V_1573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1574 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_18 . V_1538 ) {
struct V_4 * V_201 ;
V_201 = F_47 ( V_53 , V_1575 ) ;
if ( ! V_201 )
goto V_61;
if ( ( V_7 -> V_18 . V_1538 -> V_1576 &&
F_29 ( V_53 , V_204 ) ) ||
( V_7 -> V_18 . V_1538 -> V_451 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1538 -> V_1577 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1538 -> V_1578 &&
F_29 ( V_53 , V_212 ) ) ||
( V_7 -> V_18 . V_1538 -> V_1579 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1538 -> V_1580 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1538 -> V_1581 &&
F_29 ( V_53 , V_218 ) ) )
goto V_61;
if ( F_353 ( V_53 , V_7 ) )
goto V_61;
if ( F_354 ( V_53 ,
V_7 -> V_18 . V_1538 -> V_188 ) )
goto V_61;
if ( F_356 (
V_53 ,
V_7 -> V_18 . V_1538 -> V_1582 ) )
goto V_61;
F_48 ( V_53 , V_201 ) ;
}
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_358 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1537 * V_1583 )
{
struct V_4 * V_95 [ V_1584 ] ;
struct V_1549 * V_1090 ;
struct V_1585 * V_195 = NULL ;
struct V_1586 * V_50 = NULL ;
V_22 V_1573 ;
V_22 V_1587 , V_1588 , V_1568 = 0 , V_1589 ;
int V_35 , V_1590 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1591 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1592 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1550 ] ||
! V_95 [ V_1552 ] ||
! V_95 [ V_1553 ] ||
! V_95 [ V_1557 ] ||
! V_95 [ V_192 ] ||
! V_95 [ V_197 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_1564 ] )
return - V_16 ;
V_1587 = F_24 ( V_95 [ V_192 ] ) ;
if ( V_1587 > V_7 -> V_18 . V_189 -> V_188 -> V_193 )
return - V_16 ;
if ( F_4 ( V_95 [ V_197 ] ) >
V_7 -> V_18 . V_189 -> V_188 -> V_198 ||
F_4 ( V_95 [ V_197 ] ) == 0 )
return - V_16 ;
V_1588 = F_24 ( V_95 [ V_199 ] ) ;
if ( V_1588 > V_7 -> V_18 . V_189 -> V_188 -> V_200 )
return - V_16 ;
V_1589 = F_24 ( V_95 [ V_1564 ] ) ;
if ( V_1589 != F_245 ( V_1588 , 8 ) )
return - V_16 ;
if ( V_95 [ V_196 ] ) {
V_22 V_1593 = F_24 ( V_95 [ V_196 ] ) ;
V_195 = F_23 ( V_95 [ V_196 ] ) ;
V_1568 = V_1593 - sizeof( * V_195 ) ;
if ( ! V_195 -> V_47 || V_1568 % V_195 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_195 )
return - V_16 ;
if ( V_195 -> V_47 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1594 )
return - V_16 ;
if ( V_195 -> V_47 < V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1595 )
return - V_16 ;
if ( V_1568 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1596 )
return - V_16 ;
if ( V_195 -> V_1257 + V_195 -> V_47 > V_1587 )
return - V_16 ;
}
if ( V_95 [ V_194 ] ) {
V_50 = F_23 ( V_95 [ V_194 ] ) ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1257 > V_1587 )
return - V_16 ;
}
V_1573 = sizeof( * V_1090 ) ;
V_1573 += V_1587 ;
V_1573 += V_1588 + V_1589 ;
V_1573 += V_1568 ;
V_1090 = F_38 ( V_1573 , V_135 ) ;
if ( ! V_1090 )
return - V_136 ;
V_1090 -> V_1551 = F_359 ( V_95 [ V_1550 ] ) ;
V_1090 -> V_967 = F_359 ( V_95 [ V_1552 ] ) ;
memcpy ( V_1090 -> V_1554 , F_23 ( V_95 [ V_1553 ] ) ,
V_587 ) ;
if ( V_95 [ V_1555 ] )
V_1590 = F_78 ( V_95 [ V_1555 ] ) ;
else
V_1590 = 0 ;
#ifdef F_360
V_35 = F_361 ( F_7 ( & V_7 -> V_18 ) , V_1597 , V_1598 ,
V_1599 , & V_1090 -> V_1600 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1090 ) ;
return V_35 ;
}
if ( F_362 ( V_1090 -> V_1600 -> V_44 , V_1590 ) ) {
F_363 ( V_1090 -> V_1600 ) ;
F_41 ( V_1090 ) ;
return - V_1601 ;
}
V_1090 -> V_1556 = F_364 ( V_1090 -> V_1600 -> V_44 ) -> V_1602 ;
#else
if ( ! V_1590 ) {
F_41 ( V_1090 ) ;
return - V_16 ;
}
V_1090 -> V_1556 = V_1590 ;
#endif
V_1090 -> V_1558 = F_78 ( V_95 [ V_1557 ] ) ;
V_1090 -> V_1559 = V_1587 ;
V_1090 -> V_1560 = ( T_2 * ) V_1090 + sizeof( * V_1090 ) + V_1568 ;
memcpy ( ( void * ) V_1090 -> V_1560 ,
F_23 ( V_95 [ V_192 ] ) ,
V_1587 ) ;
if ( V_50 )
V_1090 -> V_1566 = * V_50 ;
V_1090 -> V_1561 = F_4 ( V_95 [ V_197 ] ) ;
V_1090 -> V_1562 = V_1588 ;
V_1090 -> V_1563 = ( T_2 * ) V_1090 + sizeof( * V_1090 ) + V_1568 + V_1587 ;
memcpy ( ( void * ) V_1090 -> V_1563 ,
F_23 ( V_95 [ V_199 ] ) ,
V_1588 ) ;
V_1090 -> V_1565 = ( T_2 * ) V_1090 + sizeof( * V_1090 ) + V_1568 +
V_1587 + V_1588 ;
memcpy ( ( void * ) V_1090 -> V_1565 ,
F_23 ( V_95 [ V_1564 ] ) ,
V_1589 ) ;
if ( V_195 ) {
V_1090 -> V_1568 = V_1568 ;
memcpy ( & V_1090 -> V_1567 , V_195 , sizeof( * V_195 ) + V_1568 ) ;
}
V_1583 -> V_188 = V_1090 ;
return 0 ;
}
static int F_365 ( struct V_6 * V_7 ,
const struct V_1603 * V_189 ,
struct V_4 * V_45 ,
struct V_1537 * V_1583 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_38 ( V_1604 * sizeof( * V_95 ) , V_135 ) ;
if ( ! V_95 )
return - V_136 ;
if ( ! ( V_189 -> V_51 & V_229 ) ) {
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_96 ( V_95 , V_1244 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_599;
V_1583 -> V_1582 = F_246 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_248 ( V_1583 -> V_1582 ) ;
if ( V_35 )
V_1583 -> V_1582 = NULL ;
V_599:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_366 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_4 * V_95 [ V_1605 ] ;
struct V_1537 V_1606 = {} ;
struct V_1537 * V_1607 ;
const struct V_1603 * V_189 = V_7 -> V_18 . V_189 ;
int V_35 , V_159 ;
bool V_1608 = V_7 -> V_18 . V_1538 ;
bool V_1609 = false ;
if ( ! V_189 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1575 ] ) {
F_367 ( V_7 ) ;
V_7 -> V_18 . V_1538 = NULL ;
goto V_1610;
}
V_35 = F_96 ( V_95 , V_1611 ,
F_23 ( V_30 -> V_5 [ V_1575 ] ) ,
F_24 ( V_30 -> V_5 [ V_1575 ] ) ,
V_1612 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_204 ] ) {
if ( ! ( V_189 -> V_51 & V_203 ) )
return - V_16 ;
V_1606 . V_1576 = true ;
}
if ( V_95 [ V_206 ] ) {
if ( ! ( V_189 -> V_51 & V_205 ) )
return - V_16 ;
V_1606 . V_451 = true ;
V_1609 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_189 -> V_51 & V_207 ) )
return - V_16 ;
V_1606 . V_1577 = true ;
V_1609 = true ;
}
if ( V_95 [ V_210 ] )
return - V_16 ;
if ( V_95 [ V_212 ] ) {
if ( ! ( V_189 -> V_51 & V_211 ) )
return - V_16 ;
V_1606 . V_1578 = true ;
V_1609 = true ;
}
if ( V_95 [ V_214 ] ) {
if ( ! ( V_189 -> V_51 & V_213 ) )
return - V_16 ;
V_1606 . V_1579 = true ;
V_1609 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_189 -> V_51 & V_215 ) )
return - V_16 ;
V_1606 . V_1580 = true ;
V_1609 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_189 -> V_51 & V_217 ) )
return - V_16 ;
V_1606 . V_1581 = true ;
V_1609 = true ;
}
if ( V_95 [ V_228 ] ) {
struct V_4 * V_221 ;
int V_219 = 0 ;
int V_134 , V_1541 , V_1613 , V_1548 ;
struct V_4 * V_1614 [ V_1615 ] ;
V_1609 = true ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_189 -> V_219 )
return - V_16 ;
V_1606 . V_1542 = F_368 ( V_219 ,
sizeof( V_1606 . V_1542 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1606 . V_1542 )
return - V_136 ;
V_1606 . V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1616 ;
F_96 ( V_1614 , V_1617 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1614 [ V_1544 ] ||
! V_1614 [ V_1545 ] )
goto error;
V_1541 = F_24 ( V_1614 [ V_1545 ] ) ;
V_1613 = F_245 ( V_1541 , 8 ) ;
if ( F_24 ( V_1614 [ V_1544 ] ) != V_1613 )
goto error;
if ( V_1541 > V_189 -> V_226 ||
V_1541 < V_189 -> V_224 )
goto error;
if ( ! V_1614 [ V_1547 ] )
V_1548 = 0 ;
else
V_1548 = F_4 (
V_1614 [ V_1547 ] ) ;
if ( V_1548 > V_189 -> V_227 )
goto error;
V_1606 . V_1542 [ V_159 ] . V_1548 = V_1548 ;
V_1616 = F_369 ( V_1613 + V_1541 , V_135 ) ;
if ( ! V_1616 ) {
V_35 = - V_136 ;
goto error;
}
V_1606 . V_1542 [ V_159 ] . V_747 = V_1616 ;
memcpy ( V_1616 , F_23 ( V_1614 [ V_1544 ] ) ,
V_1613 ) ;
V_1616 += V_1613 ;
V_1606 . V_1542 [ V_159 ] . V_1546 = V_1616 ;
V_1606 . V_1542 [ V_159 ] . V_1543 = V_1541 ;
memcpy ( V_1616 ,
F_23 ( V_1614 [ V_1545 ] ) ,
V_1541 ) ;
V_159 ++ ;
}
}
if ( V_95 [ V_191 ] ) {
V_1609 = true ;
V_35 = F_358 (
V_7 , V_95 [ V_191 ] ,
& V_1606 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_230 ] ) {
V_1609 = true ;
V_35 = F_365 (
V_7 , V_189 , V_95 [ V_230 ] ,
& V_1606 ) ;
if ( V_35 )
goto error;
}
if ( V_1606 . V_1576 && V_1609 ) {
V_35 = - V_16 ;
goto error;
}
V_1607 = F_370 ( & V_1606 , sizeof( V_1606 ) , V_135 ) ;
if ( ! V_1607 ) {
V_35 = - V_136 ;
goto error;
}
F_367 ( V_7 ) ;
V_7 -> V_18 . V_1538 = V_1607 ;
V_1610:
if ( V_7 -> V_351 -> V_1610 &&
V_1608 != ! ! V_7 -> V_18 . V_1538 )
F_371 ( V_7 , V_7 -> V_18 . V_1538 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1606 . V_219 ; V_159 ++ )
F_41 ( V_1606 . V_1542 [ V_159 ] . V_747 ) ;
F_41 ( V_1606 . V_1542 ) ;
if ( V_1606 . V_188 && V_1606 . V_188 -> V_1600 )
F_363 ( V_1606 . V_188 -> V_1600 ) ;
F_41 ( V_1606 . V_188 ) ;
F_41 ( V_1606 . V_1582 ) ;
return V_35 ;
}
static int F_372 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1539 , * V_1540 , * V_1618 , * V_1619 ;
int V_159 , V_161 , V_1541 ;
struct V_1620 * V_233 ;
if ( ! V_7 -> V_234 -> V_236 )
return 0 ;
V_1619 = F_47 ( V_53 , V_238 ) ;
if ( ! V_1619 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_234 -> V_236 ; V_159 ++ ) {
V_1618 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1618 )
return - V_91 ;
V_233 = & V_7 -> V_234 -> V_1621 [ V_159 ] ;
if ( F_28 ( V_53 , V_1622 ,
V_233 -> V_1233 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1623 ,
V_233 -> V_1624 ) )
return - V_91 ;
V_1539 = F_47 ( V_53 ,
V_1625 ) ;
if ( ! V_1539 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ ) {
V_1540 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1540 )
return - V_91 ;
V_1541 = V_233 -> V_1542 [ V_161 ] . V_1543 ;
if ( F_51 ( V_53 , V_1544 ,
F_245 ( V_1541 , 8 ) ,
V_233 -> V_1542 [ V_161 ] . V_747 ) ||
F_51 ( V_53 , V_1545 , V_1541 ,
V_233 -> V_1542 [ V_161 ] . V_1546 ) ||
F_28 ( V_53 , V_1547 ,
V_233 -> V_1542 [ V_161 ] . V_1548 ) )
return - V_91 ;
F_48 ( V_53 , V_1540 ) ;
}
F_48 ( V_53 , V_1539 ) ;
F_48 ( V_53 , V_1618 ) ;
}
F_48 ( V_53 , V_1619 ) ;
return 0 ;
}
static int F_373 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
if ( ! V_7 -> V_18 . V_234 )
return - V_540 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1626 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_234 && F_372 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_374 ( struct V_6 * V_7 )
{
struct V_1627 * V_234 = V_7 -> V_234 ;
int V_159 , V_161 ;
struct V_1620 * V_233 ;
if ( ! V_234 )
return;
for ( V_159 = 0 ; V_159 < V_234 -> V_236 ; V_159 ++ ) {
V_233 = & V_234 -> V_1621 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ )
F_41 ( V_233 -> V_1542 [ V_161 ] . V_747 ) ;
F_41 ( V_233 -> V_1542 ) ;
}
F_41 ( V_234 -> V_1621 ) ;
F_41 ( V_234 ) ;
V_7 -> V_234 = NULL ;
}
static int F_375 ( struct V_6 * V_7 ,
struct V_4 * V_233 ,
struct V_1620 * V_1628 )
{
int V_35 , V_159 ;
const struct V_1629 * V_234 = V_7 -> V_18 . V_234 ;
struct V_4 * V_95 [ V_1630 ] , * V_221 ;
int V_134 , V_1541 , V_1613 , V_1548 , V_219 = 0 ;
struct V_4 * V_1614 [ V_1615 ] ;
V_35 = F_96 ( V_95 , V_1631 , F_23 ( V_233 ) ,
F_24 ( V_233 ) , V_1632 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1622 ] )
V_1628 -> V_1233 =
F_4 ( V_95 [ V_1622 ] ) ;
if ( V_1628 -> V_1233 > V_234 -> V_237 )
return - V_16 ;
if ( V_95 [ V_1623 ] )
V_1628 -> V_1624 =
F_4 ( V_95 [ V_1623 ] ) ;
if ( V_1628 -> V_1624 != V_1633 &&
V_1628 -> V_1624 != V_1634 )
return - V_16 ;
if ( ! V_95 [ V_1625 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_234 -> V_219 )
return - V_16 ;
V_1628 -> V_1542 = F_368 ( V_219 , sizeof( V_1628 -> V_1542 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1628 -> V_1542 )
return - V_136 ;
V_1628 -> V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1616 ;
F_96 ( V_1614 , V_1617 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
if ( ! V_1614 [ V_1544 ] ||
! V_1614 [ V_1545 ] )
return - V_16 ;
V_1541 = F_24 ( V_1614 [ V_1545 ] ) ;
V_1613 = F_245 ( V_1541 , 8 ) ;
if ( F_24 ( V_1614 [ V_1544 ] ) != V_1613 )
return - V_16 ;
if ( V_1541 > V_234 -> V_226 ||
V_1541 < V_234 -> V_224 )
return - V_16 ;
if ( ! V_1614 [ V_1547 ] )
V_1548 = 0 ;
else
V_1548 = F_4 ( V_1614 [ V_1547 ] ) ;
if ( V_1548 > V_234 -> V_227 )
return - V_16 ;
V_1628 -> V_1542 [ V_159 ] . V_1548 = V_1548 ;
V_1616 = F_369 ( V_1613 + V_1541 , V_135 ) ;
if ( ! V_1616 )
return - V_136 ;
V_1628 -> V_1542 [ V_159 ] . V_747 = V_1616 ;
memcpy ( V_1616 , F_23 ( V_1614 [ V_1544 ] ) ,
V_1613 ) ;
V_1616 += V_1613 ;
V_1628 -> V_1542 [ V_159 ] . V_1546 = V_1616 ;
V_1628 -> V_1542 [ V_159 ] . V_1543 = V_1541 ;
memcpy ( V_1616 , F_23 ( V_1614 [ V_1545 ] ) ,
V_1541 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_376 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
const struct V_1629 * V_234 = V_7 -> V_18 . V_234 ;
struct V_1627 V_1635 = {} ;
struct V_1627 * V_1636 ;
int V_35 , V_1637 , V_236 = 0 , V_159 , V_161 ;
struct V_4 * V_233 ;
struct V_1620 * V_1638 ;
if ( ! V_7 -> V_18 . V_234 || ! V_7 -> V_351 -> V_1639 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_238 ] ) {
F_374 ( V_7 ) ;
F_377 ( V_7 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_236 ++ ;
if ( V_236 > V_234 -> V_236 )
return - V_16 ;
V_1635 . V_1621 = F_368 ( V_236 , sizeof( V_1635 . V_1621 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1635 . V_1621 )
return - V_136 ;
V_1635 . V_236 = V_236 ;
V_159 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_375 ( V_7 , V_233 ,
& V_1635 . V_1621 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = F_377 ( V_7 , & V_1635 ) ;
if ( V_35 )
goto error;
V_1636 = F_370 ( & V_1635 , sizeof( V_1635 ) , V_135 ) ;
if ( ! V_1636 ) {
V_35 = - V_136 ;
goto error;
}
F_374 ( V_7 ) ;
V_7 -> V_234 = V_1636 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1635 . V_236 ; V_159 ++ ) {
V_1638 = & V_1635 . V_1621 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1638 -> V_219 ; V_161 ++ )
F_41 ( V_1638 -> V_1542 [ V_161 ] . V_747 ) ;
F_41 ( V_1638 -> V_1542 ) ;
}
F_41 ( V_1635 . V_1621 ) ;
return V_35 ;
}
static int F_378 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_4 * V_95 [ V_1640 ] ;
struct V_1641 V_1642 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1643 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1644 ,
F_23 ( V_30 -> V_5 [ V_1643 ] ) ,
F_24 ( V_30 -> V_5 [ V_1643 ] ) ,
V_1645 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1646 ] ) != V_1647 )
return - V_1648 ;
if ( F_24 ( V_95 [ V_1649 ] ) != V_1650 )
return - V_1648 ;
if ( F_24 ( V_95 [ V_1651 ] ) != V_1652 )
return - V_1648 ;
V_1642 . V_1653 = F_23 ( V_95 [ V_1649 ] ) ;
V_1642 . V_1654 = F_23 ( V_95 [ V_1651 ] ) ;
V_1642 . V_1655 = F_23 ( V_95 [ V_1646 ] ) ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1247 ;
goto V_599;
}
if ( ! V_7 -> V_351 -> V_1656 ) {
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_379 ( V_7 , V_539 , & V_1642 ) ;
V_599:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_380 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1657 )
return - V_544 ;
V_17 -> V_1657 = V_30 -> V_504 ;
return 0 ;
}
static int F_381 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_31 * V_53 ;
void * V_283 ;
const T_2 * V_677 ;
T_1 V_647 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_425 )
return - V_540 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1658 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_657;
}
V_677 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_35 = F_382 ( V_7 , V_539 , V_677 , & V_647 ) ;
if ( V_35 )
goto V_657;
if ( F_104 ( V_53 , V_1460 , V_647 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_657:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_383 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1659 * V_1660 , * V_1661 ;
int V_1662 ;
if ( ! ( V_7 -> V_18 . V_51 & V_429 ) )
return - V_540 ;
V_1661 = F_38 ( sizeof( * V_1661 ) , V_135 ) ;
if ( ! V_1661 )
return - V_136 ;
F_267 ( & V_7 -> V_1663 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1660 -> V_1664 == V_30 -> V_504 ) {
V_1662 = - V_708 ;
goto V_881;
}
}
V_1661 -> V_1664 = V_30 -> V_504 ;
F_384 ( & V_1661 -> V_638 , & V_7 -> V_1665 ) ;
F_269 ( & V_7 -> V_1663 ) ;
return 0 ;
V_881:
F_269 ( & V_7 -> V_1663 ) ;
F_41 ( V_1661 ) ;
return V_1662 ;
}
static int F_385 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_431 )
return - V_540 ;
if ( V_17 -> V_141 != V_154 )
return - V_540 ;
if ( V_17 -> V_1666 )
return 0 ;
if ( F_386 ( V_7 -> V_1667 ) )
return - V_1668 ;
V_35 = F_387 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1666 = true ;
V_7 -> V_1669 ++ ;
return 0 ;
}
static int F_388 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_1670 )
return - V_540 ;
F_389 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_390 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_283 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1671 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_1672 ,
V_1673 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_295 ( V_53 ) ;
return - V_91 ;
}
static int F_391 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1674 V_1675 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1676 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1677 ] ||
! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
memset ( & V_1675 , 0 , sizeof( V_1675 ) ) ;
V_1675 . V_1678 = F_78 ( V_30 -> V_5 [ V_1677 ] ) ;
V_1675 . V_1115 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1675 . V_1116 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
return F_392 ( V_7 , V_539 , & V_1675 ) ;
}
static int F_393 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
enum V_1679 V_1349 = V_1680 ;
T_3 V_1456 ;
int V_496 ;
if ( ! V_7 -> V_351 -> V_437 )
return - V_540 ;
if ( F_59 ( ! V_7 -> V_351 -> V_439 ) )
return - V_16 ;
if ( V_7 -> V_1681 )
return - V_544 ;
if ( V_30 -> V_5 [ V_1682 ] )
V_1349 = F_78 ( V_30 -> V_5 [ V_1682 ] ) ;
if ( V_1349 >= V_1683 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1684 ] )
return - V_16 ;
V_1456 =
F_78 ( V_30 -> V_5 [ V_1684 ] ) ;
if ( V_1456 > V_1685 )
return - V_1648 ;
V_496 = F_394 ( V_7 , V_17 , V_1349 , V_1456 ) ;
if ( ! V_496 )
V_7 -> V_1681 = V_30 -> V_504 ;
return V_496 ;
}
static int F_395 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_439 )
return - V_540 ;
if ( V_7 -> V_1681 ) {
V_7 -> V_1681 = 0 ;
F_396 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_397 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_159 , V_35 ;
V_22 V_1686 , V_1408 ;
if ( ! V_7 -> V_18 . V_484 )
return - V_540 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1405 ] ||
! V_30 -> V_5 [ V_1407 ] )
return - V_16 ;
V_1686 = F_4 ( V_30 -> V_5 [ V_1405 ] ) ;
V_1408 = F_4 ( V_30 -> V_5 [ V_1407 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1687 * V_1688 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1688 = & V_7 -> V_18 . V_484 [ V_159 ] ;
if ( V_1688 -> V_30 . V_1406 != V_1686 || V_1688 -> V_30 . V_1408 != V_1408 )
continue;
if ( V_1688 -> V_51 & ( V_1689 |
V_1690 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1688 -> V_51 & V_1690 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1688 -> V_51 & V_1691 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_554 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1666 )
return - V_554 ;
}
if ( ! V_1688 -> V_1692 )
return - V_540 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_483 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_483 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_483 ] ) ;
}
V_7 -> V_1417 = V_30 ;
V_35 = V_7 -> V_18 . V_484 [ V_159 ] . V_1692 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1417 = NULL ;
return V_35 ;
}
return - V_540 ;
}
static int F_398 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
V_22 V_1686 , V_1408 ;
unsigned int V_159 ;
int V_1693 = - 1 ;
int V_35 ;
void * V_138 = NULL ;
unsigned int V_1419 = 0 ;
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
F_6 (tmp, &(*rdev)->wdev_list, list) {
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
if ( ! V_38 . V_40 [ V_1405 ] ||
! V_38 . V_40 [ V_1407 ] ) {
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
V_1686 = F_4 ( V_38 . V_40 [ V_1405 ] ) ;
V_1408 = F_4 ( V_38 . V_40 [ V_1407 ] ) ;
for ( V_159 = 0 ; V_159 < ( * V_7 ) -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1687 * V_1688 ;
V_1688 = & ( * V_7 ) -> V_18 . V_484 [ V_159 ] ;
if ( V_1688 -> V_30 . V_1406 != V_1686 || V_1688 -> V_30 . V_1408 != V_1408 )
continue;
if ( ! V_1688 -> V_1694 ) {
V_35 = - V_540 ;
goto V_43;
}
V_1693 = V_159 ;
break;
}
if ( V_1693 < 0 ) {
V_35 = - V_540 ;
goto V_43;
}
if ( V_38 . V_40 [ V_483 ] ) {
V_138 = F_23 ( V_38 . V_40 [ V_483 ] ) ;
V_1419 = F_24 ( V_38 . V_40 [ V_483 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1693 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_138 ;
V_34 -> args [ 4 ] = V_1419 ;
return 0 ;
V_43:
F_20 () ;
return V_35 ;
}
static int F_399 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
unsigned int V_1693 ;
const struct V_1687 * V_1688 ;
void * V_138 ;
int V_1419 ;
int V_35 ;
struct V_4 * V_1695 ;
V_35 = F_398 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
V_1693 = V_34 -> args [ 2 ] ;
V_138 = ( void * ) V_34 -> args [ 3 ] ;
V_1419 = V_34 -> args [ 4 ] ;
V_1688 = & V_7 -> V_18 . V_484 [ V_1693 ] ;
if ( V_1688 -> V_51 & ( V_1689 |
V_1690 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1688 -> V_51 & V_1690 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1688 -> V_51 & V_1691 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_554 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1666 )
return - V_554 ;
}
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_1411 ) ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ) ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1695 = F_47 ( V_32 , V_483 ) ;
if ( ! V_1695 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = V_1688 -> V_1694 ( & V_7 -> V_18 , V_17 , V_32 , V_138 , V_1419 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_48 ( V_32 , V_1695 ) ;
if ( V_35 == - V_91 || V_35 == - V_655 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_599;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_599:
F_20 () ;
return V_35 ;
}
struct V_31 * F_400 ( struct V_18 * V_18 ,
enum V_280 V_52 ,
enum V_762 V_45 ,
int V_1403 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1417 ) )
return NULL ;
return F_294 ( V_7 , NULL , V_1403 ,
V_7 -> V_1417 -> V_504 ,
V_7 -> V_1417 -> V_505 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_401 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1417 ) ) {
F_295 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
return F_76 ( V_32 , V_7 -> V_1417 ) ;
}
static int F_402 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1696 * V_1697 = NULL ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_46 , V_47 , V_1698 , V_1699 , V_1700 ;
int V_496 ;
if ( ! V_7 -> V_351 -> V_444 )
return - V_540 ;
if ( V_30 -> V_5 [ V_1701 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1701 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1701 ] ) ;
if ( V_47 % 2 || V_47 < V_1702 ||
V_47 > V_1703 )
return - V_16 ;
V_1697 = F_38 ( sizeof( struct V_1696 ) , V_135 ) ;
if ( ! V_1697 )
return - V_136 ;
V_1698 = ( V_47 - V_1702 ) >> 1 ;
if ( V_1698 ) {
V_1699 = V_1698 *
sizeof( struct V_1704 ) ;
memcpy ( V_1697 -> V_1705 , V_46 , V_1699 ) ;
V_1697 -> V_1698 = V_1698 ;
for ( V_1700 = 0 ; V_1700 < V_1698 ; V_1700 ++ ) {
if ( V_1697 -> V_1705 [ V_1700 ] . V_1706 > 7 ) {
F_41 ( V_1697 ) ;
return - V_16 ;
}
}
V_46 += V_1699 ;
}
memcpy ( V_1697 -> V_1706 , V_46 , V_1702 ) ;
}
F_113 ( V_539 -> V_28 ) ;
V_496 = F_42 ( V_539 -> V_28 ) ;
if ( ! V_496 )
V_496 = F_403 ( V_7 , V_539 , V_1697 ) ;
F_115 ( V_539 -> V_28 ) ;
F_41 ( V_1697 ) ;
return V_496 ;
}
static int F_404 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
const T_2 * V_1446 ;
T_2 V_1707 , V_1706 ;
T_3 V_1708 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_291 & V_446 ) )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1709 ] || ! V_30 -> V_5 [ V_547 ] ||
! V_30 -> V_5 [ V_1710 ] )
return - V_16 ;
V_1707 = F_34 ( V_30 -> V_5 [ V_1709 ] ) ;
if ( V_1707 >= V_865 )
return - V_16 ;
V_1706 = F_34 ( V_30 -> V_5 [ V_1710 ] ) ;
if ( V_1706 >= V_1711 )
return - V_16 ;
if ( V_1707 >= V_1712 ) {
return - V_16 ;
}
V_1446 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_30 -> V_5 [ V_1713 ] ) {
V_1708 =
F_78 ( V_30 -> V_5 [ V_1713 ] ) ;
if ( ! V_1708 )
return - V_16 ;
}
F_113 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1247 ;
goto V_599;
default:
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_405 ( V_7 , V_539 , V_1707 , V_1446 , V_1706 , V_1708 ) ;
V_599:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_406 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
const T_2 * V_1446 ;
T_2 V_1707 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1709 ] || ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_1707 = F_34 ( V_30 -> V_5 [ V_1709 ] ) ;
V_1446 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_407 ( V_7 , V_539 , V_1707 , V_1446 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_408 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_519 V_520 = {} ;
const T_2 * V_677 ;
T_2 V_1714 ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_1715 ||
! ( V_7 -> V_18 . V_291 & V_1716 ) )
return - V_540 ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_540 ;
}
if ( ! V_30 -> V_5 [ V_547 ] ||
! V_30 -> V_5 [ V_1717 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
if ( V_520 . V_55 -> V_290 == V_1718 &&
V_520 . V_523 != V_524 &&
V_520 . V_523 != V_579 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_520 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( F_257 ( V_17 -> V_18 , & V_520 , V_17 -> V_141 ) )
return - V_16 ;
V_677 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_1714 = F_34 ( V_30 -> V_5 [ V_1717 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_409 ( V_7 , V_539 , V_677 , V_1714 , & V_520 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_410 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
const T_2 * V_677 ;
if ( ! V_7 -> V_351 -> V_1715 ||
! V_7 -> V_351 -> V_1719 ||
! ( V_7 -> V_18 . V_291 & V_1716 ) )
return - V_540 ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_540 ;
}
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_677 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
F_113 ( V_17 ) ;
F_411 ( V_7 , V_539 , V_677 ) ;
F_115 ( V_17 ) ;
return 0 ;
}
static int F_412 ( const struct V_1720 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_539 ;
bool V_1721 = V_351 -> V_1722 & V_1723 ;
if ( V_1721 )
F_14 () ;
if ( V_351 -> V_1722 & V_1724 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1721 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_503 [ 0 ] = V_7 ;
} else if ( V_351 -> V_1722 & V_1725 ||
V_351 -> V_1722 & V_1726 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1721 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_539 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_351 -> V_1722 & V_1725 ) {
if ( ! V_539 ) {
if ( V_1721 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_503 [ 1 ] = V_539 ;
} else {
V_30 -> V_503 [ 1 ] = V_17 ;
}
if ( V_539 ) {
if ( V_351 -> V_1722 & V_1727 &&
! F_91 ( V_539 ) ) {
if ( V_1721 )
F_20 () ;
return - V_554 ;
}
F_241 ( V_539 ) ;
} else if ( V_351 -> V_1722 & V_1727 ) {
if ( ! V_17 -> V_1666 ) {
if ( V_1721 )
F_20 () ;
return - V_554 ;
}
}
V_30 -> V_503 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_413 ( const struct V_1720 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_503 [ 1 ] ) {
if ( V_351 -> V_1722 & V_1726 ) {
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( V_17 -> V_19 )
F_172 ( V_17 -> V_19 ) ;
} else {
F_172 ( V_30 -> V_503 [ 1 ] ) ;
}
}
if ( V_351 -> V_1722 & V_1723 )
F_20 () ;
if ( V_351 -> V_1722 & V_1728 ) {
struct V_1729 * V_36 = F_414 ( V_32 ) ;
memset ( F_415 ( V_36 ) , 0 , F_416 ( V_36 ) ) ;
}
}
void F_417 ( struct V_6 * V_7 ,
enum V_280 V_52 )
{
struct V_31 * V_53 ;
struct V_281 V_282 = {} ;
F_59 ( V_52 != V_295 &&
V_52 != V_1730 ) ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_282 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_640 , V_135 ) ;
}
static int F_418 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1179 * V_1365 = V_7 -> V_1183 ;
struct V_4 * V_1731 ;
int V_159 ;
if ( F_59 ( ! V_1365 ) )
return 0 ;
V_1731 = F_47 ( V_53 , V_1187 ) ;
if ( ! V_1731 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1365 -> V_1181 ; V_159 ++ ) {
if ( F_51 ( V_53 , V_159 , V_1365 -> V_1188 [ V_159 ] . V_592 , V_1365 -> V_1188 [ V_159 ] . V_594 ) )
goto V_61;
}
F_48 ( V_53 , V_1731 ) ;
V_1731 = F_47 ( V_53 , V_1186 ) ;
if ( ! V_1731 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1365 -> V_366 ; V_159 ++ ) {
if ( F_28 ( V_53 , V_159 , V_1365 -> V_367 [ V_159 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1731 ) ;
if ( V_1365 -> V_1115 &&
F_51 ( V_53 , V_683 , V_1365 -> V_1116 , V_1365 -> V_1115 ) )
goto V_61;
if ( V_1365 -> V_51 &&
F_28 ( V_53 , V_1192 , V_1365 -> V_51 ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_419 ( struct V_31 * V_53 ,
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
F_418 ( V_53 , V_7 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int
F_420 ( struct V_31 * V_53 ,
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
return - V_495 ;
}
void F_240 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_419 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1732 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1733 , V_135 ) ;
}
struct V_31 * F_421 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1734 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_419 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1734 ? V_1735 :
V_1271 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_422 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1733 , V_135 ) ;
}
void F_423 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_420 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1736 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1733 , V_135 ) ;
}
void F_251 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_420 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1733 , V_135 ) ;
}
static bool F_424 ( struct V_31 * V_53 ,
struct V_1737 * V_1180 )
{
if ( F_56 ( V_53 , V_1738 , V_1180 -> V_1447 ) )
goto V_61;
if ( V_1180 -> V_1129 [ 0 ] == '0' && V_1180 -> V_1129 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1739 ,
V_1740 ) )
goto V_61;
} else if ( V_1180 -> V_1129 [ 0 ] == '9' && V_1180 -> V_1129 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1739 ,
V_1741 ) )
goto V_61;
} else if ( ( V_1180 -> V_1129 [ 0 ] == '9' && V_1180 -> V_1129 [ 1 ] == '8' ) ||
V_1180 -> V_1742 ) {
if ( F_56 ( V_53 , V_1739 ,
V_1743 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1739 ,
V_1744 ) ||
F_60 ( V_53 , V_1025 ,
V_1180 -> V_1129 ) )
goto V_61;
}
if ( V_1180 -> V_14 != V_1745 ) {
struct V_18 * V_18 = F_19 ( V_1180 -> V_14 ) ;
if ( V_18 &&
F_28 ( V_53 , V_26 , V_1180 -> V_14 ) )
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
void F_425 ( enum V_280 V_1746 ,
struct V_1737 * V_1180 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1746 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_424 ( V_53 , V_1180 ) == false )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_426 ( & V_38 , V_53 , 0 ,
V_1747 , V_1748 ) ;
F_221 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_427 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1504 , T_11 V_47 ,
enum V_280 V_52 , T_13 V_1404 ,
int V_919 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1501 , V_47 , V_1504 ) )
goto V_61;
if ( V_919 >= 0 ) {
struct V_4 * V_1749 =
F_47 ( V_53 , V_916 ) ;
if ( ! V_1749 )
goto V_61;
if ( F_56 ( V_53 , V_918 ,
V_919 ) )
goto V_61;
F_48 ( V_53 , V_1749 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_428 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1504 ,
T_11 V_47 , T_13 V_1404 )
{
F_427 ( V_7 , V_19 , V_1504 , V_47 ,
V_704 , V_1404 , - 1 ) ;
}
void F_429 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1504 ,
T_11 V_47 , T_13 V_1404 , int V_919 )
{
F_427 ( V_7 , V_19 , V_1504 , V_47 ,
V_1751 , V_1404 , V_919 ) ;
}
void F_430 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1504 ,
T_11 V_47 , T_13 V_1404 )
{
F_427 ( V_7 , V_19 , V_1504 , V_47 ,
V_1752 , V_1404 , - 1 ) ;
}
void F_431 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1504 ,
T_11 V_47 , T_13 V_1404 )
{
F_427 ( V_7 , V_19 , V_1504 , V_47 ,
V_1753 , V_1404 , - 1 ) ;
}
void F_432 ( struct V_25 * V_539 , const T_2 * V_1504 ,
T_11 V_47 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1754 * V_1755 = ( void * ) V_1504 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_433 ( V_1755 -> V_1756 ) )
V_52 = V_1757 ;
else
V_52 = V_1758 ;
F_434 ( V_539 , V_1504 , V_47 ) ;
F_427 ( V_7 , V_539 , V_1504 , V_47 , V_52 , V_1748 , - 1 ) ;
}
static void F_435 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_677 , T_13 V_1404 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1759 ) ||
F_51 ( V_53 , V_547 , V_587 , V_677 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_436 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_677 ,
T_13 V_1404 )
{
F_435 ( V_7 , V_19 , V_704 ,
V_677 , V_1404 ) ;
}
void F_437 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_677 ,
T_13 V_1404 )
{
F_435 ( V_7 , V_19 , V_1751 ,
V_677 , V_1404 ) ;
}
void F_438 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
const T_2 * V_1760 , T_11 V_1761 ,
const T_2 * V_1762 , T_11 V_1763 ,
T_3 V_641 , T_13 V_1404 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_450 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_546 && F_51 ( V_53 , V_547 , V_587 , V_546 ) ) ||
F_55 ( V_53 , V_1449 , V_641 ) ||
( V_1760 &&
F_51 ( V_53 , V_1764 , V_1761 , V_1760 ) ) ||
( V_1762 &&
F_51 ( V_53 , V_1765 , V_1763 , V_1762 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_439 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
const T_2 * V_1760 , T_11 V_1761 ,
const T_2 * V_1762 , T_11 V_1763 , T_13 V_1404 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1766 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_546 ) ||
( V_1760 &&
F_51 ( V_53 , V_1764 , V_1761 , V_1760 ) ) ||
( V_1762 &&
F_51 ( V_53 , V_1765 , V_1763 , V_1762 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_440 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1429 ,
const T_2 * V_1115 , T_11 V_1116 , bool V_1767 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_452 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1767 && V_1429 &&
F_55 ( V_53 , V_964 , V_1429 ) ) ||
( V_1767 &&
F_29 ( V_53 , V_1768 ) ) ||
( V_1115 && F_51 ( V_53 , V_683 , V_1116 , V_1115 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_441 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
T_13 V_1404 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1769 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_546 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_442 ( struct V_25 * V_539 , const T_2 * V_677 ,
const T_2 * V_1115 , T_2 V_1116 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_443 ( V_539 , V_677 ) ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1770 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_677 ) ||
( V_1116 && V_1115 &&
F_51 ( V_53 , V_683 , V_1116 , V_1115 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_444 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_677 ,
enum V_1771 V_1772 , int V_1773 ,
const T_2 * V_1774 , T_13 V_1404 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1775 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_677 && F_51 ( V_53 , V_547 , V_587 , V_677 ) ) ||
F_28 ( V_53 , V_127 , V_1772 ) ||
( V_1773 != - 1 &&
F_56 ( V_53 , V_123 , V_1773 ) ) ||
( V_1774 && F_51 ( V_53 , V_122 , 6 , V_1774 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_445 ( struct V_18 * V_18 ,
struct V_54 * V_1776 ,
struct V_54 * V_1777 )
{
struct V_31 * V_53 ;
void * V_283 ;
struct V_4 * V_287 ;
V_53 = F_74 ( V_600 , V_1748 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1778 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
V_287 = F_47 ( V_53 , V_1779 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1776 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
V_287 = F_47 ( V_53 , V_1780 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1777 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_426 ( & V_38 , V_53 , 0 ,
V_1747 , V_1748 ) ;
F_221 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_446 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_647 ,
struct V_54 * V_55 ,
unsigned int V_1456 , T_13 V_1404 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
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
F_28 ( V_53 , V_522 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_527 ,
V_530 ) ||
F_104 ( V_53 , V_1460 , V_647 ) )
goto V_61;
if ( V_52 == V_1459 &&
F_28 ( V_53 , V_1457 , V_1456 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_447 ( struct V_1 * V_17 , T_1 V_647 ,
struct V_54 * V_55 ,
unsigned int V_1456 , T_13 V_1404 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_448 ( V_17 , V_647 , V_55 , V_1456 ) ;
F_446 ( V_1459 ,
V_7 , V_17 , V_647 , V_55 ,
V_1456 , V_1404 ) ;
}
void F_449 ( struct V_1 * V_17 , T_1 V_647 ,
struct V_54 * V_55 ,
T_13 V_1404 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_450 ( V_17 , V_647 , V_55 ) ;
F_446 ( V_1781 ,
V_7 , V_17 , V_647 , V_55 , 0 , V_1404 ) ;
}
void F_451 ( struct V_25 * V_539 , const T_2 * V_649 ,
struct V_788 * V_789 , T_13 V_1404 )
{
struct V_18 * V_18 = V_539 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_452 ( V_539 , V_649 , V_789 ) ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
if ( F_162 ( V_53 , V_883 , 0 , 0 , 0 ,
V_7 , V_539 , V_649 , V_789 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
}
void F_453 ( struct V_25 * V_539 , const T_2 * V_649 ,
struct V_788 * V_789 , T_13 V_1404 )
{
struct V_18 * V_18 = V_539 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_788 V_1782 = {} ;
if ( ! V_789 )
V_789 = & V_1782 ;
F_454 ( V_539 , V_649 ) ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
if ( F_162 ( V_53 , V_1783 , 0 , 0 , 0 ,
V_7 , V_539 , V_649 , V_789 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
}
void F_455 ( struct V_25 * V_539 , const T_2 * V_649 ,
enum V_1784 V_1429 ,
T_13 V_1404 )
{
struct V_18 * V_18 = V_539 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_1785 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1786 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_649 ) ||
F_28 ( V_53 , V_1787 , V_1429 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static bool F_456 ( struct V_25 * V_539 , T_2 V_52 ,
const T_2 * V_677 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1664 = F_457 ( V_17 -> V_1657 ) ;
if ( ! V_1664 )
return false ;
V_53 = F_74 ( 100 , V_1404 ) ;
if ( ! V_53 )
return true ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_677 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1664 ) ;
return true ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_459 ( struct V_25 * V_539 ,
const T_2 * V_677 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
bool V_496 ;
F_460 ( V_539 , V_677 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_461 ( false ) ;
return false ;
}
V_496 = F_456 ( V_539 , V_1788 ,
V_677 , V_1404 ) ;
F_461 ( V_496 ) ;
return V_496 ;
}
bool F_462 ( struct V_25 * V_539 ,
const T_2 * V_677 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
bool V_496 ;
F_463 ( V_539 , V_677 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_461 ( false ) ;
return false ;
}
V_496 = F_456 ( V_539 ,
V_1789 ,
V_677 , V_1404 ) ;
F_461 ( V_496 ) ;
return V_496 ;
}
int F_464 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1664 ,
int V_1790 , int V_1791 ,
const T_2 * V_1504 , T_11 V_47 , V_22 V_51 , T_13 V_1404 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1508 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_522 , V_1790 ) ||
( V_1791 &&
F_28 ( V_53 , V_1792 , V_1791 ) ) ||
F_51 ( V_53 , V_1501 , V_47 , V_1504 ) ||
( V_51 &&
F_28 ( V_53 , V_1793 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1664 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_465 ( struct V_1 * V_17 , T_1 V_647 ,
const T_2 * V_1504 , T_11 V_47 , bool V_1794 , T_13 V_1404 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
F_466 ( V_17 , V_647 , V_1794 ) ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1795 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1501 , V_47 , V_1504 ) ||
F_104 ( V_53 , V_1460 , V_647 ) ||
( V_1794 && F_29 ( V_53 , V_1796 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_467 ( struct V_25 * V_539 ,
const char * V_958 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_600 , V_1404 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1797 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) )
goto V_61;
if ( V_958 && F_51 ( V_53 , V_547 , V_587 , V_958 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1527 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_468 ( struct V_31 * V_53 , T_13 V_1404 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
}
void F_469 ( struct V_25 * V_539 ,
enum V_1798 V_1799 ,
T_13 V_1404 )
{
struct V_31 * V_53 ;
F_470 ( V_539 , V_1799 ) ;
if ( F_59 ( V_1799 != V_1800 &&
V_1799 != V_1801 ) )
return;
V_53 = F_467 ( V_539 , NULL , V_1404 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1802 ,
V_1799 ) )
goto V_61;
F_468 ( V_53 , V_1404 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_471 ( struct V_25 * V_539 ,
const T_2 * V_1446 , V_22 V_1803 ,
V_22 V_244 , V_22 V_1519 , T_13 V_1404 )
{
struct V_31 * V_53 ;
V_53 = F_467 ( V_539 , V_1446 , V_1404 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1532 , V_1803 ) )
goto V_61;
if ( F_28 ( V_53 , V_1531 , V_244 ) )
goto V_61;
if ( F_28 ( V_53 , V_1533 , V_1519 ) )
goto V_61;
F_468 ( V_53 , V_1404 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_472 ( struct V_25 * V_539 ,
const T_2 * V_1446 , V_22 V_1803 , T_13 V_1404 )
{
struct V_31 * V_53 ;
F_473 ( V_539 , V_1446 , V_1803 ) ;
V_53 = F_467 ( V_539 , V_1446 , V_1404 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1804 , V_1803 ) )
goto V_61;
F_468 ( V_53 , V_1404 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_474 ( struct V_25 * V_539 , T_13 V_1404 )
{
struct V_31 * V_53 ;
V_53 = F_467 ( V_539 , NULL , V_1404 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1805 ) )
goto V_61;
F_468 ( V_53 , V_1404 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_475 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
const T_2 * V_1655 , T_13 V_1404 )
{
struct V_31 * V_53 ;
struct V_4 * V_1806 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1807 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_546 ) )
goto V_61;
V_1806 = F_47 ( V_53 , V_1643 ) ;
if ( ! V_1806 )
goto V_61;
if ( F_51 ( V_53 , V_1646 ,
V_1647 , V_1655 ) )
goto V_61;
F_48 ( V_53 , V_1806 ) ;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_476 ( struct V_25 * V_539 , const T_2 * V_546 ,
const T_2 * V_1655 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_477 ( V_539 , V_546 ) ;
F_475 ( V_7 , V_539 , V_546 , V_1655 , V_1404 ) ;
}
static void
F_478 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1808 ,
const T_2 * V_546 , bool V_1809 , T_13 V_1404 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1810 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1811 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1812 , V_1808 ) ||
F_51 ( V_53 , V_1813 , V_587 , V_546 ) ||
( V_1809 &&
F_29 ( V_53 , V_1814 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_479 ( struct V_25 * V_539 , int V_1808 ,
const T_2 * V_546 , bool V_1809 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_480 ( V_539 , V_1808 , V_546 , V_1809 ) ;
F_478 ( V_7 , V_539 , V_1808 , V_546 , V_1809 , V_1404 ) ;
}
static void F_481 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_519 * V_520 ,
T_13 V_1404 ,
enum V_280 V_1815 ,
T_2 V_1250 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1815 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_520 ) )
goto V_61;
if ( ( V_1815 == V_1816 ) &&
( F_28 ( V_53 , V_1248 , V_1250 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_482 ( struct V_25 * V_539 ,
struct V_519 * V_520 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_483 ( V_539 , V_520 ) ;
V_17 -> V_520 = * V_520 ;
V_17 -> V_545 = * V_520 ;
F_481 ( V_7 , V_539 , V_520 , V_135 ,
V_1817 , 0 ) ;
}
void F_484 ( struct V_25 * V_539 ,
struct V_519 * V_520 ,
T_2 V_1250 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_485 ( V_539 , V_520 ) ;
F_481 ( V_7 , V_539 , V_520 , V_135 ,
V_1816 , V_1250 ) ;
}
void
F_486 ( struct V_6 * V_7 ,
const struct V_519 * V_520 ,
enum V_1818 V_625 ,
struct V_25 * V_19 , T_13 V_1404 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1819 ) ;
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
if ( F_28 ( V_53 , V_1820 , V_625 ) )
goto V_61;
if ( F_101 ( V_53 , V_520 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_487 ( struct V_25 * V_539 , const T_2 * V_677 ,
T_1 V_647 , bool V_1821 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_488 ( V_539 , V_677 , V_647 , V_1821 ) ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1658 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_677 ) ||
F_104 ( V_53 , V_1460 , V_647 ) ||
( V_1821 && F_29 ( V_53 , V_1796 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_489 ( struct V_18 * V_18 ,
const T_2 * V_1822 , T_11 V_47 ,
int V_1790 , int V_1791 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
struct V_1659 * V_1660 ;
F_490 ( V_18 , V_1822 , V_47 , V_1790 , V_1791 ) ;
F_267 ( & V_7 -> V_1663 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1748 ) ;
if ( ! V_53 ) {
F_269 ( & V_7 -> V_1663 ) ;
return;
}
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1508 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1790 &&
F_28 ( V_53 , V_522 , V_1790 ) ) ||
( V_1791 &&
F_28 ( V_53 , V_1792 , V_1791 ) ) ||
F_51 ( V_53 , V_1501 , V_47 , V_1822 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1660 -> V_1664 ) ;
}
F_269 ( & V_7 -> V_1663 ) ;
return;
V_61:
F_269 ( & V_7 -> V_1663 ) ;
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_491 ( struct V_31 * V_53 ,
struct V_1823 * V_1824 )
{
struct V_1825 * V_1569 = V_1824 -> V_1826 ;
struct V_4 * V_1827 , * V_1828 , * V_286 ;
int V_159 , V_161 ;
V_1827 = F_47 (
V_53 , V_1829 ) ;
if ( ! V_1827 )
return - V_495 ;
for ( V_159 = 0 ; V_159 < V_1569 -> V_1830 ; V_159 ++ ) {
struct V_1831 * V_1571 = V_1569 -> V_1570 [ V_159 ] ;
V_1828 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1828 )
break;
if ( F_51 ( V_53 , V_593 , V_1571 -> V_594 . V_592 ,
V_1571 -> V_594 . V_594 ) ) {
F_492 ( V_53 , V_1828 ) ;
goto V_599;
}
if ( V_1571 -> V_366 ) {
V_286 = F_47 (
V_53 , V_1186 ) ;
if ( ! V_286 ) {
F_492 ( V_53 , V_1828 ) ;
goto V_599;
}
for ( V_161 = 0 ; V_161 < V_1571 -> V_366 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1571 -> V_367 [ V_161 ] ) ) {
F_492 ( V_53 , V_286 ) ;
F_492 ( V_53 , V_1828 ) ;
goto V_599;
}
}
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_1828 ) ;
}
V_599:
F_48 ( V_53 , V_1827 ) ;
return 0 ;
}
void F_493 ( struct V_1 * V_17 ,
struct V_1823 * V_1824 ,
T_13 V_1404 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
int V_1573 = 200 ;
F_494 ( V_17 -> V_18 , V_17 , V_1824 ) ;
if ( V_1824 )
V_1573 += V_1824 -> V_1832 ;
V_53 = F_74 ( V_1573 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1833 ) ;
if ( ! V_283 )
goto V_657;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_657;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_657;
if ( V_1824 ) {
struct V_4 * V_1834 ;
V_1834 = F_47 ( V_53 , V_1575 ) ;
if ( ! V_1834 )
goto V_657;
if ( V_1824 -> V_451 &&
F_29 ( V_53 , V_206 ) )
goto V_657;
if ( V_1824 -> V_1577 &&
F_29 ( V_53 , V_208 ) )
goto V_657;
if ( V_1824 -> V_1578 &&
F_29 ( V_53 , V_212 ) )
goto V_657;
if ( V_1824 -> V_1579 &&
F_29 ( V_53 , V_214 ) )
goto V_657;
if ( V_1824 -> V_1580 &&
F_29 ( V_53 , V_216 ) )
goto V_657;
if ( V_1824 -> V_1581 &&
F_29 ( V_53 , V_218 ) )
goto V_657;
if ( V_1824 -> V_1835 >= 0 &&
F_28 ( V_53 , V_228 ,
V_1824 -> V_1835 ) )
goto V_657;
if ( V_1824 -> V_1836 &&
F_29 ( V_53 , V_1837 ) )
goto V_657;
if ( V_1824 -> V_1838 &&
F_29 ( V_53 , V_1839 ) )
goto V_657;
if ( V_1824 -> V_1840 &&
F_29 ( V_53 ,
V_1841 ) )
goto V_657;
if ( V_1824 -> V_1842 ) {
V_22 V_1843 = V_1844 ;
V_22 V_1845 = V_1846 ;
if ( ! V_1824 -> V_1847 ) {
V_1843 =
V_1848 ;
V_1845 =
V_1849 ;
}
if ( V_1824 -> V_1850 &&
F_28 ( V_53 , V_1845 , V_1824 -> V_1850 ) )
goto V_657;
if ( F_51 ( V_53 , V_1843 , V_1824 -> V_1832 ,
V_1824 -> V_1842 ) )
goto V_657;
}
if ( V_1824 -> V_1826 &&
F_491 ( V_53 , V_1824 ) )
goto V_657;
F_48 ( V_53 , V_1834 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_657:
F_75 ( V_53 ) ;
}
void F_495 ( struct V_25 * V_539 , const T_2 * V_1446 ,
enum V_1453 V_1851 ,
T_3 V_965 , T_13 V_1404 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_496 ( V_17 -> V_18 , V_539 , V_1446 , V_1851 ,
V_965 ) ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1852 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_56 ( V_53 , V_1455 , V_1851 ) ||
F_51 ( V_53 , V_547 , V_587 , V_1446 ) ||
( V_965 > 0 &&
F_55 ( V_53 , V_964 , V_965 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_1404 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_497 ( struct V_1853 * V_1854 ,
unsigned long V_282 ,
void * V_1855 )
{
struct V_1856 * V_1857 = V_1855 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1659 * V_1660 , * V_24 ;
if ( V_282 != V_1858 )
return V_1859 ;
F_219 () ;
F_498 (rdev, &cfg80211_rdev_list, list) {
bool V_1860 = false ;
bool V_1861 = false ;
struct V_1203 * V_1234 =
F_220 ( V_7 -> V_1234 ) ;
if ( V_1234 && V_1857 -> V_49 &&
V_1234 -> V_632 == V_1857 -> V_49 )
V_1861 = true ;
F_498 (wdev, &rdev->wdev_list, list) {
F_499 ( V_17 , V_1857 -> V_49 ) ;
if ( V_17 -> V_632 == V_1857 -> V_49 )
V_1860 = true ;
}
F_267 ( & V_7 -> V_1663 ) ;
F_500 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1660 -> V_1664 == V_1857 -> V_49 ) {
F_501 ( & V_1660 -> V_638 ) ;
F_41 ( V_1660 ) ;
break;
}
}
F_269 ( & V_7 -> V_1663 ) ;
if ( V_1860 ) {
struct V_1862 * V_1863 ;
V_1863 = F_38 ( sizeof( * V_1863 ) , V_1748 ) ;
if ( V_1863 ) {
V_1863 -> V_1664 = V_1857 -> V_49 ;
F_502 ( & V_7 -> V_1864 ) ;
F_384 ( & V_1863 -> V_638 , & V_7 -> V_1865 ) ;
F_503 ( & V_7 -> V_1864 ) ;
F_504 ( & V_7 -> V_1866 ) ;
}
} else if ( V_1861 ) {
V_1234 -> V_632 = 0 ;
if ( V_7 -> V_351 -> V_1236 &&
V_7 -> V_18 . V_51 & V_422 )
F_504 ( & V_7 -> V_1867 ) ;
}
}
F_221 () ;
F_505 ( V_1857 -> V_49 ) ;
return V_1868 ;
}
void F_506 ( struct V_25 * V_19 ,
struct V_1869 * V_1870 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_507 ( V_18 , V_19 , V_1870 ) ;
if ( ! V_1870 -> V_1871 )
return;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1872 ) ;
if ( ! V_283 )
goto V_599;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_1870 -> V_1871 ) )
goto V_599;
if ( V_1870 -> V_1269 &&
F_51 ( V_53 , V_683 , V_1870 -> V_1873 , V_1870 -> V_1269 ) )
goto V_599;
if ( V_1870 -> V_1874 &&
F_51 ( V_53 , V_1875 , V_1870 -> V_1876 ,
V_1870 -> V_1874 ) )
goto V_599;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1750 , V_135 ) ;
return;
V_599:
F_75 ( V_53 ) ;
}
void F_508 ( struct V_1 * V_17 , T_13 V_1404 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1664 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1681 )
return;
V_1664 = V_7 -> V_1681 ;
V_7 -> V_1681 = 0 ;
V_53 = F_74 ( V_600 , V_1404 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1877 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1664 ) ;
return;
V_61:
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_509 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1878 ) ;
if ( ! V_283 )
goto V_599;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_599;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1750 , V_135 ) ;
return;
V_599:
F_75 ( V_53 ) ;
}
int F_510 ( void )
{
int V_35 ;
V_35 = F_511 ( & V_38 , V_1879 ,
V_1880 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_512 ( & V_1881 ) ;
if ( V_35 )
goto V_1882;
return 0 ;
V_1882:
F_513 ( & V_38 ) ;
return V_35 ;
}
void F_514 ( void )
{
F_515 ( & V_1881 ) ;
F_513 ( & V_38 ) ;
}
