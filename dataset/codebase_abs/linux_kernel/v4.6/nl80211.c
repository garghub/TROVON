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
V_137 . V_740 = F_152 ( V_30 -> V_5 [ V_741 ] ) ;
if ( V_137 . V_740 && ! V_7 -> V_18 . V_363 [ V_742 ] )
return - V_540 ;
F_113 ( V_17 ) ;
V_35 = F_153 ( V_7 , V_539 , & V_137 ) ;
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
static int F_154 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_679 V_137 ;
int V_35 ;
if ( V_539 -> V_28 -> V_141 != V_142 &&
V_539 -> V_28 -> V_141 != V_144 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_743 )
return - V_540 ;
if ( ! V_17 -> V_541 )
return - V_16 ;
V_35 = F_146 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
V_35 = F_155 ( V_7 , V_539 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_156 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
return F_157 ( V_7 , V_539 , false ) ;
}
static int F_158 ( struct V_29 * V_30 ,
enum V_272 V_141 ,
struct V_744 * V_137 )
{
struct V_4 * V_51 [ V_745 + 1 ] ;
struct V_4 * V_601 ;
int V_604 ;
V_601 = V_30 -> V_5 [ V_746 ] ;
if ( V_601 ) {
struct V_747 * V_748 ;
V_748 = F_23 ( V_601 ) ;
V_137 -> V_749 = V_748 -> V_750 ;
V_137 -> V_751 = V_748 -> V_752 ;
V_137 -> V_751 &= V_137 -> V_749 ;
if ( ( V_137 -> V_749 |
V_137 -> V_751 ) & F_159 ( V_753 ) )
return - V_16 ;
return 0 ;
}
V_601 = V_30 -> V_5 [ V_754 ] ;
if ( ! V_601 )
return 0 ;
if ( F_33 ( V_51 , V_745 ,
V_601 , V_755 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_749 = F_159 ( V_756 ) |
F_159 ( V_757 ) |
F_159 ( V_758 ) |
F_159 ( V_759 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_749 = F_159 ( V_756 ) |
F_159 ( V_760 ) ;
break;
case V_145 :
V_137 -> V_749 = F_159 ( V_761 ) |
F_159 ( V_759 ) |
F_159 ( V_756 ) ;
default:
return - V_16 ;
}
for ( V_604 = 1 ; V_604 <= V_745 ; V_604 ++ ) {
if ( V_51 [ V_604 ] ) {
V_137 -> V_751 |= ( 1 << V_604 ) ;
if ( V_604 > V_762 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_160 ( struct V_31 * V_53 , struct V_763 * V_30 ,
int V_45 )
{
struct V_4 * V_244 ;
V_22 V_264 ;
T_3 V_764 ;
enum V_765 V_766 ;
V_244 = F_47 ( V_53 , V_45 ) ;
if ( ! V_244 )
return false ;
V_264 = F_161 ( V_30 ) ;
V_764 = V_264 < ( 1UL << 16 ) ? V_264 : 0 ;
if ( V_264 > 0 &&
F_28 ( V_53 , V_767 , V_264 ) )
return false ;
if ( V_764 > 0 &&
F_55 ( V_53 , V_768 , V_764 ) )
return false ;
switch ( V_30 -> V_769 ) {
case V_770 :
V_766 = V_771 ;
break;
case V_772 :
V_766 = V_773 ;
break;
default:
F_59 ( 1 ) ;
case V_774 :
V_766 = 0 ;
break;
case V_775 :
V_766 = V_776 ;
break;
case V_777 :
V_766 = V_778 ;
break;
case V_779 :
V_766 = V_780 ;
break;
}
if ( V_766 && F_29 ( V_53 , V_766 ) )
return false ;
if ( V_30 -> V_51 & V_781 ) {
if ( F_56 ( V_53 , V_782 , V_30 -> V_248 ) )
return false ;
if ( V_30 -> V_51 & V_783 &&
F_29 ( V_53 , V_784 ) )
return false ;
} else if ( V_30 -> V_51 & V_785 ) {
if ( F_56 ( V_53 , V_786 , V_30 -> V_248 ) )
return false ;
if ( F_56 ( V_53 , V_787 , V_30 -> V_788 ) )
return false ;
if ( V_30 -> V_51 & V_783 &&
F_29 ( V_53 , V_784 ) )
return false ;
}
F_48 ( V_53 , V_244 ) ;
return true ;
}
static bool F_162 ( struct V_31 * V_53 , T_2 V_750 , T_6 * signal ,
int V_789 )
{
void * V_45 ;
int V_159 = 0 ;
if ( ! V_750 )
return true ;
V_45 = F_47 ( V_53 , V_789 ) ;
if ( ! V_45 )
return false ;
for ( V_159 = 0 ; V_159 < V_790 ; V_159 ++ ) {
if ( ! ( V_750 & F_159 ( V_159 ) ) )
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
struct V_25 * V_539 ,
const T_2 * V_649 , struct V_791 * V_792 )
{
void * V_283 ;
struct V_4 * V_793 , * V_794 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_649 ) ||
F_28 ( V_53 , V_293 , V_792 -> V_795 ) )
goto V_61;
V_793 = F_47 ( V_53 , V_796 ) ;
if ( ! V_793 )
goto V_61;
#define F_164 ( V_45 , T_7 , type ) do { \
if (sinfo->filled & BIT(NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
F_164 ( V_797 , V_798 , V_22 ) ;
F_164 ( V_799 , V_800 , V_22 ) ;
if ( V_792 -> V_801 & ( F_159 ( V_802 ) |
F_159 ( V_803 ) ) &&
F_28 ( V_53 , V_802 ,
( V_22 ) V_792 -> V_804 ) )
goto V_61;
if ( V_792 -> V_801 & ( F_159 ( V_805 ) |
F_159 ( V_806 ) ) &&
F_28 ( V_53 , V_805 ,
( V_22 ) V_792 -> V_807 ) )
goto V_61;
F_164 ( V_808 , V_804 , T_1 ) ;
F_164 ( V_809 , V_807 , T_1 ) ;
F_164 ( V_810 , V_811 , T_3 ) ;
F_164 ( V_812 , V_813 , T_3 ) ;
F_164 ( V_814 , V_815 , T_2 ) ;
switch ( V_7 -> V_18 . V_816 ) {
case V_817 :
F_164 ( SIGNAL , signal , T_2 ) ;
F_164 ( V_818 , V_819 , T_2 ) ;
break;
default:
break;
}
if ( V_792 -> V_801 & F_159 ( V_820 ) ) {
if ( ! F_162 ( V_53 , V_792 -> V_821 ,
V_792 -> V_822 ,
V_820 ) )
goto V_61;
}
if ( V_792 -> V_801 & F_159 ( V_823 ) ) {
if ( ! F_162 ( V_53 , V_792 -> V_821 ,
V_792 -> V_824 ,
V_823 ) )
goto V_61;
}
if ( V_792 -> V_801 & F_159 ( V_825 ) ) {
if ( ! F_160 ( V_53 , & V_792 -> V_826 ,
V_825 ) )
goto V_61;
}
if ( V_792 -> V_801 & F_159 ( V_827 ) ) {
if ( ! F_160 ( V_53 , & V_792 -> V_828 ,
V_827 ) )
goto V_61;
}
F_164 ( V_829 , V_830 , V_22 ) ;
F_164 ( V_831 , V_832 , V_22 ) ;
F_164 ( V_833 , V_834 , V_22 ) ;
F_164 ( V_835 , V_836 , V_22 ) ;
F_164 ( V_837 , V_838 , V_22 ) ;
F_164 ( V_839 , V_840 , V_22 ) ;
F_164 ( V_841 , V_842 , V_22 ) ;
F_164 ( V_843 , V_844 , V_22 ) ;
F_164 ( V_845 , V_846 , V_22 ) ;
if ( V_792 -> V_801 & F_159 ( V_847 ) ) {
V_794 = F_47 ( V_53 , V_847 ) ;
if ( ! V_794 )
goto V_61;
if ( ( ( V_792 -> V_794 . V_51 & V_848 ) &&
F_29 ( V_53 , V_849 ) ) ||
( ( V_792 -> V_794 . V_51 & V_850 ) &&
F_29 ( V_53 , V_851 ) ) ||
( ( V_792 -> V_794 . V_51 & V_852 ) &&
F_29 ( V_53 , V_853 ) ) ||
F_56 ( V_53 , V_854 ,
V_792 -> V_794 . V_712 ) ||
F_55 ( V_53 , V_855 ,
V_792 -> V_794 . V_541 ) )
goto V_61;
F_48 ( V_53 , V_794 ) ;
}
if ( ( V_792 -> V_801 & F_159 ( V_856 ) ) &&
F_51 ( V_53 , V_856 ,
sizeof( struct V_747 ) ,
& V_792 -> V_748 ) )
goto V_61;
F_164 ( V_857 , V_858 , T_1 ) ;
F_164 ( V_859 , V_860 , T_1 ) ;
F_164 ( V_861 , V_862 , T_1 ) ;
F_164 ( V_863 , V_864 , T_2 ) ;
#undef F_164
if ( V_792 -> V_801 & F_159 ( V_865 ) ) {
struct V_4 * V_866 ;
int V_867 ;
V_866 = F_47 ( V_53 , V_865 ) ;
if ( ! V_866 )
goto V_61;
for ( V_867 = 0 ; V_867 < V_868 + 1 ; V_867 ++ ) {
struct V_869 * V_870 ;
struct V_4 * V_871 ;
V_870 = & V_792 -> V_872 [ V_867 ] ;
if ( ! V_870 -> V_801 )
continue;
V_871 = F_47 ( V_53 , V_867 + 1 ) ;
if ( ! V_871 )
goto V_61;
#define F_165 ( V_45 , T_7 , type ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_ ## type(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb)) \
goto nla_put_failure; \
} while (0)
F_165 ( V_873 , V_874 , T_1 ) ;
F_165 ( V_875 , V_876 , T_1 ) ;
F_165 ( V_877 , V_878 , T_1 ) ;
F_165 ( V_879 , V_880 , T_1 ) ;
#undef F_165
F_48 ( V_53 , V_871 ) ;
}
F_48 ( V_53 , V_866 ) ;
}
F_48 ( V_53 , V_793 ) ;
if ( V_792 -> V_881 &&
F_51 ( V_53 , V_683 , V_792 -> V_881 ,
V_792 -> V_882 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_166 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_791 V_792 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_649 [ V_587 ] ;
int V_883 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_884;
}
if ( ! V_7 -> V_351 -> V_885 ) {
V_35 = - V_540 ;
goto V_884;
}
while ( 1 ) {
memset ( & V_792 , 0 , sizeof( V_792 ) ) ;
V_35 = F_167 ( V_7 , V_17 -> V_19 , V_883 ,
V_649 , & V_792 ) ;
if ( V_35 == - V_655 )
break;
if ( V_35 )
goto V_884;
if ( F_163 ( V_32 , V_886 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_7 , V_17 -> V_19 , V_649 ,
& V_792 ) < 0 )
goto V_599;
V_883 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_883 ;
V_35 = V_32 -> V_47 ;
V_884:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_168 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_791 V_792 ;
struct V_31 * V_53 ;
T_2 * V_649 = NULL ;
int V_35 ;
memset ( & V_792 , 0 , sizeof( V_792 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_887 )
return - V_540 ;
V_35 = F_169 ( V_7 , V_539 , V_649 , & V_792 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_163 ( V_53 , V_886 ,
V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_7 , V_539 , V_649 , & V_792 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_170 ( struct V_18 * V_18 ,
struct V_744 * V_137 ,
enum V_888 V_889 )
{
if ( V_137 -> V_890 != - 1 &&
V_889 != V_891 )
return - V_16 ;
if ( V_137 -> V_892 &&
! ( V_137 -> V_751 & F_159 ( V_760 ) ) &&
V_889 != V_891 )
return - V_16 ;
F_114 ( V_745 != 7 ) ;
switch ( V_889 ) {
case V_893 :
case V_894 :
if ( V_137 -> V_749 &
~ ( F_159 ( V_761 ) |
F_159 ( V_759 ) |
F_159 ( V_756 ) ) )
return - V_16 ;
break;
case V_895 :
case V_896 :
if ( ! ( V_137 -> V_751 & F_159 ( V_760 ) ) )
return - V_16 ;
V_137 -> V_749 &= ~ F_159 ( V_760 ) ;
break;
default:
if ( V_137 -> V_897 != V_898 )
return - V_16 ;
if ( V_137 -> V_842 )
return - V_16 ;
if ( V_137 -> V_899 & V_900 )
return - V_16 ;
}
if ( V_889 != V_895 &&
V_889 != V_896 ) {
if ( V_137 -> V_751 & F_159 ( V_760 ) )
return - V_16 ;
V_137 -> V_749 &= ~ F_159 ( V_760 ) ;
}
if ( V_889 != V_895 &&
V_889 != V_891 ) {
if ( V_137 -> V_899 & V_901 )
return - V_16 ;
if ( V_137 -> V_899 & V_902 )
return - V_16 ;
if ( V_137 -> V_903 )
return - V_16 ;
if ( V_137 -> V_904 || V_137 -> V_905 || V_137 -> V_906 )
return - V_16 ;
}
if ( V_889 != V_907 &&
V_889 != V_891 ) {
if ( V_137 -> V_908 )
return - V_16 ;
}
switch ( V_889 ) {
case V_909 :
if ( ! ( V_137 -> V_749 & F_159 ( V_756 ) ) )
return - V_540 ;
break;
case V_907 :
case V_891 :
if ( V_137 -> V_749 &
~ ( F_159 ( V_756 ) |
F_159 ( V_761 ) |
F_159 ( V_910 ) |
F_159 ( V_757 ) |
F_159 ( V_758 ) |
F_159 ( V_759 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_291 & V_911 ) &&
V_137 -> V_749 &
( F_159 ( V_761 ) |
F_159 ( V_910 ) ) )
return - V_16 ;
break;
case V_912 :
case V_913 :
if ( V_137 -> V_749 & ~ F_159 ( V_756 ) )
return - V_16 ;
break;
case V_895 :
if ( V_137 -> V_749 & ~ ( F_159 ( V_756 ) |
F_159 ( V_758 ) ) )
return - V_16 ;
if ( V_137 -> V_751 & F_159 ( V_756 ) &&
! V_137 -> V_903 )
return - V_16 ;
break;
case V_896 :
return - V_16 ;
case V_893 :
if ( V_137 -> V_899 & V_900 )
return - V_16 ;
break;
case V_894 :
if ( V_137 -> V_897 != V_898 &&
V_137 -> V_897 != V_914 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_171 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_915 = V_30 -> V_5 [ V_916 ] ;
struct V_25 * V_917 ;
int V_496 ;
if ( ! V_915 )
return NULL ;
V_917 = F_172 ( F_94 ( V_30 ) , F_4 ( V_915 ) ) ;
if ( ! V_917 )
return F_3 ( - V_23 ) ;
if ( ! V_917 -> V_28 || V_917 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_496 = - V_16 ;
goto error;
}
if ( V_917 -> V_28 -> V_141 != V_143 &&
V_917 -> V_28 -> V_141 != V_142 &&
V_917 -> V_28 -> V_141 != V_144 ) {
V_496 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_917 ) ) {
V_496 = - V_554 ;
goto error;
}
return V_917 ;
error:
F_173 ( V_917 ) ;
return F_3 ( V_496 ) ;
}
static int F_174 ( struct V_29 * V_30 ,
struct V_744 * V_137 )
{
struct V_4 * V_95 [ V_918 + 1 ] ;
struct V_4 * V_601 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_919 ] )
return 0 ;
V_601 = V_30 -> V_5 [ V_919 ] ;
V_35 = F_33 ( V_95 , V_918 , V_601 ,
V_920 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_921 ] )
V_137 -> V_922 = F_34 (
V_95 [ V_921 ] ) ;
if ( V_137 -> V_922 & ~ V_923 )
return - V_16 ;
if ( V_95 [ V_924 ] )
V_137 -> V_925 = F_34 ( V_95 [ V_924 ] ) ;
if ( V_137 -> V_925 & ~ V_926 )
return - V_16 ;
V_137 -> V_899 |= V_901 ;
return 0 ;
}
static int F_175 ( struct V_29 * V_30 ,
struct V_744 * V_137 )
{
if ( V_30 -> V_5 [ V_927 ] ) {
V_137 -> V_928 =
F_23 ( V_30 -> V_5 [ V_927 ] ) ;
V_137 -> V_929 =
F_24 ( V_30 -> V_5 [ V_927 ] ) ;
if ( V_137 -> V_929 < 2 )
return - V_16 ;
if ( V_137 -> V_929 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_930 ] ) {
V_137 -> V_931 =
F_23 ( V_30 -> V_5 [ V_930 ] ) ;
V_137 -> V_932 =
F_24 ( V_30 -> V_5 [ V_930 ] ) ;
if ( V_137 -> V_932 < 2 ||
V_137 -> V_932 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_176 ( struct V_29 * V_30 ,
struct V_744 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_933 ] )
V_137 -> V_892 = F_78 ( V_30 -> V_5 [ V_933 ] ) ;
if ( V_30 -> V_5 [ V_934 ] )
V_137 -> V_905 =
F_23 ( V_30 -> V_5 [ V_934 ] ) ;
if ( V_30 -> V_5 [ V_935 ] )
V_137 -> V_906 =
F_23 ( V_30 -> V_5 [ V_935 ] ) ;
V_35 = F_175 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_174 ( V_30 , V_137 ) ;
}
static int F_177 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_744 V_137 ;
T_2 * V_649 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_936 )
return - V_540 ;
if ( V_30 -> V_5 [ V_937 ] )
V_137 . V_892 = F_78 ( V_30 -> V_5 [ V_937 ] ) ;
if ( V_30 -> V_5 [ V_938 ] )
V_137 . V_890 =
F_78 ( V_30 -> V_5 [ V_938 ] ) ;
else
V_137 . V_890 = - 1 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_30 -> V_5 [ V_939 ] ) {
V_137 . V_903 =
F_23 ( V_30 -> V_5 [ V_939 ] ) ;
V_137 . V_940 =
F_24 ( V_30 -> V_5 [ V_939 ] ) ;
}
if ( V_30 -> V_5 [ V_941 ] ) {
V_137 . V_942 =
F_78 ( V_30 -> V_5 [ V_941 ] ) ;
V_137 . V_899 |= V_902 ;
}
if ( V_30 -> V_5 [ V_943 ] ) {
V_137 . V_904 =
F_23 ( V_30 -> V_5 [ V_943 ] ) ;
V_137 . V_944 =
F_24 ( V_30 -> V_5 [ V_943 ] ) ;
}
if ( F_158 ( V_30 , V_539 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_945 ] ) {
V_137 . V_897 =
F_34 ( V_30 -> V_5 [ V_945 ] ) ;
if ( V_137 . V_897 >= V_946 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_947 ] ) {
V_137 . V_815 =
F_34 ( V_30 -> V_5 [ V_947 ] ) ;
if ( V_137 . V_815 >= V_948 )
return - V_16 ;
V_137 . V_899 |= V_900 ;
}
if ( V_30 -> V_5 [ V_949 ] ) {
enum V_950 V_951 = F_4 (
V_30 -> V_5 [ V_949 ] ) ;
if ( V_951 <= V_952 ||
V_951 > V_953 )
return - V_16 ;
V_137 . V_842 = V_951 ;
}
V_35 = F_176 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_908 = F_171 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_908 ) )
return F_18 ( V_137 . V_908 ) ;
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
goto V_954;
}
V_35 = F_178 ( V_7 , V_539 , V_649 , & V_137 ) ;
V_954:
if ( V_137 . V_908 )
F_173 ( V_137 . V_908 ) ;
return V_35 ;
}
static int F_179 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_744 V_137 ;
T_2 * V_649 = NULL ;
V_22 V_955 = F_159 ( V_761 ) |
F_159 ( V_910 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_351 -> V_377 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_938 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_939 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_937 ] &&
! V_30 -> V_5 [ V_933 ] )
return - V_16 ;
V_649 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_137 . V_903 =
F_23 ( V_30 -> V_5 [ V_939 ] ) ;
V_137 . V_940 =
F_24 ( V_30 -> V_5 [ V_939 ] ) ;
V_137 . V_890 =
F_78 ( V_30 -> V_5 [ V_938 ] ) ;
if ( V_30 -> V_5 [ V_933 ] )
V_137 . V_892 = F_78 ( V_30 -> V_5 [ V_933 ] ) ;
else
V_137 . V_892 = F_78 ( V_30 -> V_5 [ V_937 ] ) ;
if ( ! V_137 . V_892 || V_137 . V_892 > V_956 )
return - V_16 ;
if ( V_30 -> V_5 [ V_941 ] ) {
V_137 . V_942 =
F_78 ( V_30 -> V_5 [ V_941 ] ) ;
V_137 . V_899 |= V_902 ;
}
if ( V_30 -> V_5 [ V_943 ] ) {
V_137 . V_904 =
F_23 ( V_30 -> V_5 [ V_943 ] ) ;
V_137 . V_944 =
F_24 ( V_30 -> V_5 [ V_943 ] ) ;
}
if ( V_30 -> V_5 [ V_934 ] )
V_137 . V_905 =
F_23 ( V_30 -> V_5 [ V_934 ] ) ;
if ( V_30 -> V_5 [ V_935 ] )
V_137 . V_906 =
F_23 ( V_30 -> V_5 [ V_935 ] ) ;
if ( V_30 -> V_5 [ V_957 ] ) {
V_137 . V_958 = true ;
V_137 . V_959 =
F_34 ( V_30 -> V_5 [ V_957 ] ) ;
}
if ( V_30 -> V_5 [ V_945 ] ) {
V_137 . V_897 =
F_34 ( V_30 -> V_5 [ V_945 ] ) ;
if ( V_137 . V_897 >= V_946 )
return - V_16 ;
}
V_35 = F_175 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_174 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_158 ( V_30 , V_539 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( ! ( V_137 . V_751 & F_159 ( V_758 ) ) ) {
V_137 . V_905 = NULL ;
V_137 . V_906 = NULL ;
}
F_114 ( V_745 != 7 ) ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) ||
! ( V_137 . V_751 & F_159 ( V_758 ) ) )
V_137 . V_899 &= ~ V_901 ;
if ( ( V_137 . V_751 & F_159 ( V_760 ) ) ||
V_30 -> V_5 [ V_933 ] )
return - V_16 ;
V_137 . V_749 &= ~ F_159 ( V_760 ) ;
if ( ! ( V_7 -> V_18 . V_291 &
V_911 ) &&
V_137 . V_749 & V_955 )
return - V_16 ;
if ( ! ( V_137 . V_749 & V_955 ) ) {
V_137 . V_749 |= V_955 ;
V_137 . V_751 |= V_955 ;
}
V_137 . V_908 = F_171 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_908 ) )
return F_18 ( V_137 . V_908 ) ;
break;
case V_145 :
V_137 . V_899 &= ~ V_901 ;
if ( V_137 . V_749 & F_159 ( V_910 ) )
return - V_16 ;
if ( ( V_137 . V_751 & F_159 ( V_760 ) ) ||
V_30 -> V_5 [ V_933 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_899 &= ~ V_901 ;
if ( V_137 . V_749 &
( F_159 ( V_910 ) |
F_159 ( V_761 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_751 & F_159 ( V_760 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) )
return - V_540 ;
if ( ! ( V_7 -> V_18 . V_51 & V_334 ) )
return - V_540 ;
V_137 . V_749 &= ~ F_159 ( V_756 ) ;
break;
default:
return - V_540 ;
}
V_35 = F_180 ( V_7 , V_539 , V_649 , & V_137 ) ;
if ( V_137 . V_908 )
F_173 ( V_137 . V_908 ) ;
return V_35 ;
}
static int F_181 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_960 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_30 -> V_5 [ V_547 ] )
V_137 . V_961 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_539 -> V_28 -> V_141 != V_142 &&
V_539 -> V_28 -> V_141 != V_143 &&
V_539 -> V_28 -> V_141 != V_145 &&
V_539 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_962 )
return - V_540 ;
if ( V_30 -> V_5 [ V_963 ] ) {
V_137 . V_964 =
F_34 ( V_30 -> V_5 [ V_963 ] ) ;
if ( V_137 . V_964 != V_965 >> 4 &&
V_137 . V_964 != V_966 >> 4 )
return - V_16 ;
} else {
V_137 . V_964 = V_966 >> 4 ;
}
if ( V_30 -> V_5 [ V_967 ] ) {
V_137 . V_968 =
F_78 ( V_30 -> V_5 [ V_967 ] ) ;
if ( V_137 . V_968 == 0 )
return - V_16 ;
} else {
V_137 . V_968 = V_969 ;
}
return F_182 ( V_7 , V_539 , & V_137 ) ;
}
static int F_183 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_539 ,
T_2 * V_970 , T_2 * V_971 ,
struct V_972 * V_973 )
{
void * V_283 ;
struct V_4 * V_974 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_975 ) ;
if ( ! V_283 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_970 ) ||
F_51 ( V_53 , V_976 , V_587 , V_971 ) ||
F_28 ( V_53 , V_293 , V_973 -> V_795 ) )
goto V_61;
V_974 = F_47 ( V_53 , V_977 ) ;
if ( ! V_974 )
goto V_61;
if ( ( V_973 -> V_801 & V_978 ) &&
F_28 ( V_53 , V_979 ,
V_973 -> V_980 ) )
goto V_61;
if ( ( ( V_973 -> V_801 & V_981 ) &&
F_28 ( V_53 , V_982 , V_973 -> V_983 ) ) ||
( ( V_973 -> V_801 & V_984 ) &&
F_28 ( V_53 , V_985 ,
V_973 -> V_986 ) ) ||
( ( V_973 -> V_801 & V_987 ) &&
F_28 ( V_53 , V_988 ,
V_973 -> V_989 ) ) ||
( ( V_973 -> V_801 & V_990 ) &&
F_56 ( V_53 , V_991 ,
V_973 -> V_51 ) ) ||
( ( V_973 -> V_801 & V_992 ) &&
F_28 ( V_53 , V_993 ,
V_973 -> V_994 ) ) ||
( ( V_973 -> V_801 & V_995 ) &&
F_56 ( V_53 , V_996 ,
V_973 -> V_997 ) ) )
goto V_61;
F_48 ( V_53 , V_974 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_184 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_972 V_973 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_970 [ V_587 ] ;
T_2 V_971 [ V_587 ] ;
int V_998 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_999 ) {
V_35 = - V_540 ;
goto V_884;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_540 ;
goto V_884;
}
while ( 1 ) {
V_35 = F_185 ( V_7 , V_17 -> V_19 , V_998 , V_970 ,
V_971 , & V_973 ) ;
if ( V_35 == - V_655 )
break;
if ( V_35 )
goto V_884;
if ( F_183 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_17 -> V_19 , V_970 , V_971 ,
& V_973 ) < 0 )
goto V_599;
V_998 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_998 ;
V_35 = V_32 -> V_47 ;
V_884:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_186 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_972 V_973 ;
struct V_31 * V_53 ;
T_2 * V_970 = NULL ;
T_2 V_971 [ V_587 ] ;
memset ( & V_973 , 0 , sizeof( V_973 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_970 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_1000 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
V_35 = F_187 ( V_7 , V_539 , V_970 , V_971 , & V_973 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_183 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_539 , V_970 , V_971 , & V_973 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_188 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_970 = NULL ;
T_2 * V_971 = NULL ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_976 ] )
return - V_16 ;
V_970 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_971 = F_23 ( V_30 -> V_5 [ V_976 ] ) ;
if ( ! V_7 -> V_351 -> V_1001 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
return F_189 ( V_7 , V_539 , V_970 , V_971 ) ;
}
static int F_190 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_970 = NULL ;
T_2 * V_971 = NULL ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_976 ] )
return - V_16 ;
V_970 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_971 = F_23 ( V_30 -> V_5 [ V_976 ] ) ;
if ( ! V_7 -> V_351 -> V_379 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
return F_191 ( V_7 , V_539 , V_970 , V_971 ) ;
}
static int F_192 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_970 = NULL ;
if ( V_30 -> V_5 [ V_547 ] )
V_970 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_1002 )
return - V_540 ;
return F_193 ( V_7 , V_539 , V_970 ) ;
}
static int F_194 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
int V_35 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_972 V_973 ;
struct V_31 * V_53 ;
T_2 * V_970 = NULL ;
T_2 V_1003 [ V_587 ] ;
memset ( & V_973 , 0 , sizeof( V_973 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_970 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! V_7 -> V_351 -> V_1004 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_145 )
return - V_540 ;
V_35 = F_195 ( V_7 , V_539 , V_970 , V_1003 , & V_973 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_183 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_539 , V_970 , V_1003 , & V_973 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_196 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_972 V_973 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_970 [ V_587 ] ;
T_2 V_1003 [ V_587 ] ;
int V_998 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_351 -> V_1005 ) {
V_35 = - V_540 ;
goto V_884;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_540 ;
goto V_884;
}
while ( 1 ) {
V_35 = F_197 ( V_7 , V_17 -> V_19 , V_998 , V_970 ,
V_1003 , & V_973 ) ;
if ( V_35 == - V_655 )
break;
if ( V_35 )
goto V_884;
if ( F_183 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_17 -> V_19 , V_970 , V_1003 ,
& V_973 ) < 0 )
goto V_599;
V_998 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_998 ;
V_35 = V_32 -> V_47 ;
V_884:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_198 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1006 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_1007 = - 1 ;
V_137 . V_1008 = - 1 ;
V_137 . V_1009 = - 1 ;
V_137 . V_1010 = - 1 ;
V_137 . V_1011 = - 1 ;
V_137 . V_728 = - 1 ;
V_137 . V_731 = - 1 ;
if ( V_30 -> V_5 [ V_1012 ] )
V_137 . V_1007 =
F_34 ( V_30 -> V_5 [ V_1012 ] ) ;
if ( V_30 -> V_5 [ V_1013 ] )
V_137 . V_1008 =
F_34 ( V_30 -> V_5 [ V_1013 ] ) ;
if ( V_30 -> V_5 [ V_1014 ] )
V_137 . V_1009 =
F_34 ( V_30 -> V_5 [ V_1014 ] ) ;
if ( V_30 -> V_5 [ V_1015 ] ) {
V_137 . V_1016 =
F_23 ( V_30 -> V_5 [ V_1015 ] ) ;
V_137 . V_1017 =
F_24 ( V_30 -> V_5 [ V_1015 ] ) ;
}
if ( V_30 -> V_5 [ V_1018 ] )
V_137 . V_1010 = ! ! F_34 ( V_30 -> V_5 [ V_1018 ] ) ;
if ( V_30 -> V_5 [ V_1019 ] )
V_137 . V_1011 =
F_78 ( V_30 -> V_5 [ V_1019 ] ) ;
if ( V_30 -> V_5 [ V_727 ] ) {
if ( V_539 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_728 =
F_199 ( V_30 -> V_5 [ V_727 ] ) ;
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
V_35 = F_200 ( V_7 , V_539 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_201 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
bool V_1020 ;
enum V_1021 V_1022 ;
V_22 V_632 ;
if ( F_202 ( ! F_203 ( V_1023 ) ) )
return - V_1024 ;
if ( V_30 -> V_5 [ V_1025 ] )
V_1022 =
F_4 ( V_30 -> V_5 [ V_1025 ] ) ;
else
V_1022 = V_1026 ;
switch ( V_1022 ) {
case V_1026 :
case V_1027 :
if ( ! V_30 -> V_5 [ V_1028 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1028 ] ) ;
return F_204 ( V_138 , V_1022 ) ;
case V_1029 :
if ( V_30 -> V_5 [ V_631 ] ) {
V_632 = V_30 -> V_504 ;
V_1020 = ! ! V_30 -> V_5 [ V_1030 ] ;
} else {
V_632 = 0 ;
V_1020 = true ;
}
return F_205 ( V_1020 , V_632 ) ;
default:
return - V_16 ;
}
}
static int F_206 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1031 V_1032 ;
int V_35 = 0 ;
void * V_283 ;
struct V_4 * V_974 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_1033 )
return - V_540 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1034 )
memcpy ( & V_1032 , & V_1035 , sizeof( V_1032 ) ) ;
else
V_35 = F_207 ( V_7 , V_539 , & V_1032 ) ;
F_115 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1036 ) ;
if ( ! V_283 )
goto V_599;
V_974 = F_47 ( V_53 , V_1037 ) ;
if ( ! V_974 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_55 ( V_53 , V_1038 ,
V_1032 . V_1039 ) ||
F_55 ( V_53 , V_1040 ,
V_1032 . V_1041 ) ||
F_55 ( V_53 , V_1042 ,
V_1032 . V_1043 ) ||
F_55 ( V_53 , V_1044 ,
V_1032 . V_1045 ) ||
F_56 ( V_53 , V_1046 ,
V_1032 . V_1047 ) ||
F_56 ( V_53 , V_1048 ,
V_1032 . V_1049 ) ||
F_56 ( V_53 , V_1050 ,
V_1032 . V_1051 ) ||
F_56 ( V_53 , V_1052 ,
V_1032 . V_1053 ) ||
F_28 ( V_53 , V_1054 ,
V_1032 . V_1055 ) ||
F_56 ( V_53 , V_1056 ,
V_1032 . V_1057 ) ||
F_28 ( V_53 , V_1058 ,
V_1032 . V_1059 ) ||
F_55 ( V_53 , V_1060 ,
V_1032 . V_1061 ) ||
F_28 ( V_53 , V_1062 ,
V_1032 . V_1063 ) ||
F_55 ( V_53 , V_1064 ,
V_1032 . V_1065 ) ||
F_55 ( V_53 , V_1066 ,
V_1032 . V_1067 ) ||
F_55 ( V_53 , V_1068 ,
V_1032 . V_1069 ) ||
F_56 ( V_53 , V_1070 ,
V_1032 . V_1071 ) ||
F_55 ( V_53 , V_1072 ,
V_1032 . V_1073 ) ||
F_56 ( V_53 , V_1074 ,
V_1032 . V_1075 ) ||
F_56 ( V_53 , V_1076 ,
V_1032 . V_1077 ) ||
F_28 ( V_53 , V_1078 ,
V_1032 . V_1079 ) ||
F_28 ( V_53 , V_1080 ,
V_1032 . V_1011 ) ||
F_28 ( V_53 , V_1081 ,
V_1032 . V_1082 ) ||
F_55 ( V_53 , V_1083 ,
V_1032 . V_1084 ) ||
F_55 ( V_53 , V_1085 ,
V_1032 . V_1086 ) ||
F_28 ( V_53 , V_1087 ,
V_1032 . V_1088 ) ||
F_55 ( V_53 , V_1089 ,
V_1032 . V_1090 ) ||
F_28 ( V_53 , V_1091 ,
V_1032 . V_1092 ) )
goto V_61;
F_48 ( V_53 , V_974 ) ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_599:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_208 ( struct V_29 * V_30 ,
struct V_1031 * V_1093 ,
V_22 * V_1094 )
{
struct V_4 * V_95 [ V_1095 + 1 ] ;
V_22 V_750 = 0 ;
#define F_209 ( V_95 , V_1093 , T_8 , T_9 , V_174 , V_750 , V_45 , T_10 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1037 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1095 ,
V_30 -> V_5 [ V_1037 ] ,
V_1096 ) )
return - V_16 ;
F_114 ( V_1095 > 32 ) ;
F_209 ( V_95 , V_1093 , V_1039 , 1 , 255 ,
V_750 , V_1038 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1041 , 1 , 255 ,
V_750 , V_1040 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1043 , 1 , 255 ,
V_750 , V_1042 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1045 , 0 , 255 ,
V_750 , V_1044 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1047 , 0 , 16 ,
V_750 , V_1046 ,
F_34 ) ;
F_209 ( V_95 , V_1093 , V_1049 , 1 , 255 ,
V_750 , V_1048 , F_34 ) ;
F_209 ( V_95 , V_1093 , V_1051 , 1 , 255 ,
V_750 , V_1050 ,
F_34 ) ;
F_209 ( V_95 , V_1093 , V_1053 , 0 , 1 ,
V_750 , V_1052 ,
F_34 ) ;
F_209 ( V_95 , V_1093 , V_1055 ,
1 , 255 , V_750 ,
V_1054 ,
F_4 ) ;
F_209 ( V_95 , V_1093 , V_1057 , 0 , 255 ,
V_750 , V_1056 ,
F_34 ) ;
F_209 ( V_95 , V_1093 , V_1059 , 1 , 65535 ,
V_750 , V_1058 ,
F_4 ) ;
F_209 ( V_95 , V_1093 , V_1061 , 1 , 65535 ,
V_750 , V_1060 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1063 ,
1 , 65535 , V_750 ,
V_1062 ,
F_4 ) ;
F_209 ( V_95 , V_1093 , V_1065 ,
1 , 65535 , V_750 ,
V_1064 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1067 ,
1 , 65535 , V_750 ,
V_1066 ,
F_78 ) ;
F_209 ( V_95 , V_1093 ,
V_1069 ,
1 , 65535 , V_750 ,
V_1068 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1071 , 0 , 4 ,
V_750 , V_1070 ,
F_34 ) ;
F_209 ( V_95 , V_1093 , V_1073 , 1 , 65535 ,
V_750 , V_1072 ,
F_78 ) ;
F_209 ( V_95 , V_1093 ,
V_1075 , 0 , 1 ,
V_750 , V_1074 ,
F_34 ) ;
F_209 ( V_95 , V_1093 , V_1077 , 0 , 1 ,
V_750 , V_1076 ,
F_34 ) ;
F_209 ( V_95 , V_1093 , V_1079 , - 255 , 0 ,
V_750 , V_1078 ,
V_1097 ) ;
F_209 ( V_95 , V_1093 , V_1011 , 0 , 16 ,
V_750 , V_1080 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1082 ,
1 , 65535 , V_750 ,
V_1081 ,
F_4 ) ;
F_209 ( V_95 , V_1093 , V_1084 , 1 , 65535 ,
V_750 , V_1083 ,
F_78 ) ;
F_209 ( V_95 , V_1093 ,
V_1086 ,
1 , 65535 , V_750 ,
V_1085 ,
F_78 ) ;
F_209 ( V_95 , V_1093 , V_1088 ,
V_1098 ,
V_953 ,
V_750 , V_1087 ,
F_4 ) ;
F_209 ( V_95 , V_1093 , V_1090 ,
0 , 65535 , V_750 ,
V_1089 , F_78 ) ;
F_209 ( V_95 , V_1093 , V_1092 , 0 , 0xffffffff ,
V_750 , V_1091 ,
F_4 ) ;
if ( V_1094 )
* V_1094 = V_750 ;
return 0 ;
#undef F_209
}
static int F_210 ( struct V_29 * V_30 ,
struct V_1099 * V_1100 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_4 * V_95 [ V_1101 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1102 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1101 ,
V_30 -> V_5 [ V_1102 ] ,
V_1103 ) )
return - V_16 ;
if ( V_95 [ V_1104 ] )
V_1100 -> V_1105 =
( F_34 ( V_95 [ V_1104 ] ) ) ?
V_1106 :
V_1107 ;
if ( V_95 [ V_1108 ] )
V_1100 -> V_1109 =
( F_34 ( V_95 [ V_1108 ] ) ) ?
V_1110 :
V_1111 ;
if ( V_95 [ V_1112 ] )
V_1100 -> V_1113 =
( F_34 ( V_95 [ V_1112 ] ) ) ?
V_1114 :
V_1115 ;
if ( V_95 [ V_1116 ] ) {
struct V_4 * V_1117 =
V_95 [ V_1116 ] ;
if ( ! F_22 ( V_1117 ) )
return - V_16 ;
V_1100 -> V_1118 = F_23 ( V_1117 ) ;
V_1100 -> V_1119 = F_24 ( V_1117 ) ;
}
if ( V_95 [ V_1120 ] &&
! ( V_7 -> V_18 . V_291 & V_1121 ) )
return - V_16 ;
V_1100 -> V_1122 = F_152 ( V_95 [ V_1120 ] ) ;
V_1100 -> V_1123 = F_152 ( V_95 [ V_1124 ] ) ;
V_1100 -> V_1125 = F_152 ( V_95 [ V_1126 ] ) ;
if ( V_1100 -> V_1125 )
V_1100 -> V_1122 = true ;
if ( V_95 [ V_1127 ] ) {
if ( ! V_1100 -> V_1122 )
return - V_16 ;
V_1100 -> V_1128 =
F_34 ( V_95 [ V_1127 ] ) ;
}
return 0 ;
}
static int F_211 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1031 V_1093 ;
V_22 V_750 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_381 )
return - V_540 ;
V_35 = F_208 ( V_30 , & V_1093 , & V_750 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1034 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_212 ( V_7 , V_539 , V_750 , & V_1093 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_213 ( const struct V_1129 * V_1130 ,
struct V_31 * V_53 )
{
struct V_4 * V_1131 ;
unsigned int V_159 ;
if ( F_60 ( V_53 , V_1028 , V_1130 -> V_1132 ) ||
( V_1130 -> V_1133 &&
F_56 ( V_53 , V_1134 , V_1130 -> V_1133 ) ) )
goto V_61;
V_1131 = F_47 ( V_53 , V_1135 ) ;
if ( ! V_1131 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1130 -> V_1136 ; V_159 ++ ) {
struct V_4 * V_1137 ;
const struct V_1138 * V_1139 ;
const struct V_1140 * V_1141 ;
const struct V_1142 * V_1143 ;
unsigned int V_1144 ;
V_1139 = & V_1130 -> V_1145 [ V_159 ] ;
V_1141 = & V_1139 -> V_1141 ;
V_1143 = & V_1139 -> V_1143 ;
V_1137 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1137 )
goto V_61;
V_1144 = V_1141 -> V_1144 ;
if ( ! V_1144 )
V_1144 = F_214 ( V_1130 ,
V_1139 ) ;
if ( F_28 ( V_53 , V_1146 ,
V_1139 -> V_51 ) ||
F_28 ( V_53 , V_1147 ,
V_1141 -> V_1148 ) ||
F_28 ( V_53 , V_1149 ,
V_1141 -> V_1150 ) ||
F_28 ( V_53 , V_1151 ,
V_1144 ) ||
F_28 ( V_53 , V_1152 ,
V_1143 -> V_1153 ) ||
F_28 ( V_53 , V_1154 ,
V_1143 -> V_1155 ) ||
F_28 ( V_53 , V_1156 ,
V_1139 -> V_74 ) )
goto V_61;
F_48 ( V_53 , V_1137 ) ;
}
F_48 ( V_53 , V_1131 ) ;
return 0 ;
V_61:
return - V_495 ;
}
static int F_215 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1129 * V_1130 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1157 ) ;
if ( ! V_283 )
goto V_1158;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1159 ;
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1159 = V_18 -> V_490 &
V_491 ;
V_1130 = F_216 ( V_18 ) ;
if ( F_59 ( ! V_1130 && V_1159 ) ) {
F_75 ( V_53 ) ;
return - V_16 ;
}
if ( V_1130 &&
F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
}
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1025 ,
V_1027 ) )
goto V_61;
F_219 () ;
if ( ! V_1130 )
V_1130 = F_220 ( V_1023 ) ;
if ( F_213 ( V_1130 , V_53 ) )
goto V_1160;
F_221 () ;
F_66 ( V_53 , V_283 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1160:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
V_1158:
F_75 ( V_53 ) ;
return - V_495 ;
}
static int F_222 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 , struct V_18 * V_18 ,
const struct V_1129 * V_1130 )
{
void * V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1157 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_213 ( V_1130 , V_53 ) )
goto V_61;
if ( ! V_18 && F_218 () &&
F_28 ( V_53 , V_1025 ,
V_1027 ) )
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
const struct V_1129 * V_1130 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1161 , V_499 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1023 && V_499 == 0 ) {
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_500 ,
V_501 , NULL ,
F_225 ( V_1023 ) ) ;
if ( V_35 < 0 )
goto V_884;
}
V_1161 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1130 = F_216 ( & V_7 -> V_18 ) ;
if ( ! V_1130 )
continue;
if ( ++ V_1161 <= V_499 )
continue;
V_35 = F_222 ( V_32 , V_34 , V_34 -> V_36 -> V_500 ,
V_501 , & V_7 -> V_18 , V_1130 ) ;
if ( V_35 < 0 ) {
V_1161 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1161 ;
V_35 = V_32 -> V_47 ;
V_884:
F_20 () ;
return V_35 ;
}
static int F_226 ( struct V_4 * V_95 [] ,
struct V_1138 * V_1139 )
{
struct V_1140 * V_1141 = & V_1139 -> V_1141 ;
struct V_1142 * V_1143 = & V_1139 -> V_1143 ;
if ( ! V_95 [ V_1146 ] )
return - V_16 ;
if ( ! V_95 [ V_1147 ] )
return - V_16 ;
if ( ! V_95 [ V_1149 ] )
return - V_16 ;
if ( ! V_95 [ V_1151 ] )
return - V_16 ;
if ( ! V_95 [ V_1154 ] )
return - V_16 ;
V_1139 -> V_51 = F_4 ( V_95 [ V_1146 ] ) ;
V_1141 -> V_1148 =
F_4 ( V_95 [ V_1147 ] ) ;
V_1141 -> V_1150 =
F_4 ( V_95 [ V_1149 ] ) ;
V_1141 -> V_1144 =
F_4 ( V_95 [ V_1151 ] ) ;
V_1143 -> V_1155 =
F_4 ( V_95 [ V_1154 ] ) ;
if ( V_95 [ V_1152 ] )
V_1143 -> V_1153 =
F_4 ( V_95 [ V_1152 ] ) ;
if ( V_95 [ V_1156 ] )
V_1139 -> V_74 =
F_4 ( V_95 [ V_1156 ] ) ;
return 0 ;
}
static int F_227 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1162 + 1 ] ;
struct V_4 * V_1137 ;
char * V_1132 ;
int V_1163 , V_1164 ;
V_22 V_1165 = 0 , V_1166 = 0 , V_1167 ;
enum V_1168 V_1133 = V_1169 ;
struct V_1129 * V_1170 ;
if ( ! V_30 -> V_5 [ V_1028 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1135 ] )
return - V_16 ;
V_1132 = F_23 ( V_30 -> V_5 [ V_1028 ] ) ;
if ( V_30 -> V_5 [ V_1134 ] )
V_1133 = F_34 ( V_30 -> V_5 [ V_1134 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1165 ++ ;
if ( V_1165 > V_1171 )
return - V_16 ;
}
if ( ! F_228 ( V_1132 ) )
return - V_16 ;
V_1167 = sizeof( struct V_1129 ) +
V_1165 * sizeof( struct V_1138 ) ;
V_1170 = F_38 ( V_1167 , V_135 ) ;
if ( ! V_1170 )
return - V_136 ;
V_1170 -> V_1136 = V_1165 ;
V_1170 -> V_1132 [ 0 ] = V_1132 [ 0 ] ;
V_1170 -> V_1132 [ 1 ] = V_1132 [ 1 ] ;
if ( F_229 ( V_1133 ) )
V_1170 -> V_1133 = V_1133 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1164 = F_96 ( V_95 , V_1162 ,
F_23 ( V_1137 ) , F_24 ( V_1137 ) ,
V_1172 ) ;
if ( V_1164 )
goto V_1173;
V_1164 = F_226 ( V_95 , & V_1170 -> V_1145 [ V_1166 ] ) ;
if ( V_1164 )
goto V_1173;
V_1166 ++ ;
if ( V_1166 > V_1171 ) {
V_1164 = - V_16 ;
goto V_1173;
}
}
V_1164 = F_230 ( V_1170 , V_1174 ) ;
V_1170 = NULL ;
V_1173:
F_41 ( V_1170 ) ;
return V_1164 ;
}
static int F_231 ( struct V_4 * V_1175 )
{
struct V_4 * V_1176 , * V_1177 ;
int V_366 = 0 , V_1178 , V_1179 ;
F_39 (attr1, freqs, tmp1) {
V_366 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1176 != V_1177 &&
F_4 ( V_1176 ) == F_4 ( V_1177 ) )
return 0 ;
}
return V_366 ;
}
static int F_232 ( struct V_4 * * V_5 ,
T_2 * V_649 , T_2 * V_1180 )
{
int V_159 ;
if ( ! V_5 [ V_547 ] && ! V_5 [ V_1181 ] ) {
F_233 ( V_649 ) ;
F_233 ( V_1180 ) ;
V_649 [ 0 ] = 0x2 ;
V_1180 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_547 ] || ! V_5 [ V_1181 ] )
return - V_16 ;
memcpy ( V_649 , F_23 ( V_5 [ V_547 ] ) , V_587 ) ;
memcpy ( V_1180 , F_23 ( V_5 [ V_1181 ] ) , V_587 ) ;
if ( ! F_234 ( V_1180 ) ||
F_234 ( V_649 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_587 ; V_159 ++ )
V_649 [ V_159 ] &= V_1180 [ V_159 ] ;
return 0 ;
}
static int F_235 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
struct V_1182 * V_1183 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1184 = 0 , V_366 , V_159 ;
T_11 V_1119 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_351 -> V_1185 )
return - V_540 ;
if ( V_7 -> V_1186 || V_7 -> V_1187 ) {
V_35 = - V_544 ;
goto V_1188;
}
if ( V_30 -> V_5 [ V_1189 ] ) {
V_366 = F_231 (
V_30 -> V_5 [ V_1189 ] ) ;
if ( ! V_366 ) {
V_35 = - V_16 ;
goto V_1188;
}
} else {
V_366 = F_236 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1190 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1184 ++ ;
if ( V_1184 > V_18 -> V_309 ) {
V_35 = - V_16 ;
goto V_1188;
}
if ( V_30 -> V_5 [ V_683 ] )
V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
else
V_1119 = 0 ;
if ( V_1119 > V_18 -> V_313 ) {
V_35 = - V_16 ;
goto V_1188;
}
V_1183 = F_38 ( sizeof( * V_1183 )
+ sizeof( * V_1183 -> V_1191 ) * V_1184
+ sizeof( * V_1183 -> V_367 ) * V_366
+ V_1119 , V_135 ) ;
if ( ! V_1183 ) {
V_35 = - V_136 ;
goto V_1188;
}
if ( V_1184 )
V_1183 -> V_1191 = ( void * ) & V_1183 -> V_367 [ V_366 ] ;
V_1183 -> V_1184 = V_1184 ;
if ( V_1119 ) {
if ( V_1184 )
V_1183 -> V_1118 = ( void * ) ( V_1183 -> V_1191 + V_1184 ) ;
else
V_1183 -> V_1118 = ( void * ) ( V_1183 -> V_367 + V_366 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1189 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1192;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1183 -> V_367 [ V_159 ] = V_55 ;
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
V_1183 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1192;
}
V_1183 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1184 ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_618 ) {
V_35 = - V_16 ;
goto V_1192;
}
V_1183 -> V_1191 [ V_159 ] . V_592 = F_24 ( V_45 ) ;
memcpy ( V_1183 -> V_1191 [ V_159 ] . V_594 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_683 ] ) {
V_1183 -> V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
memcpy ( ( void * ) V_1183 -> V_1118 ,
F_23 ( V_30 -> V_5 [ V_683 ] ) ,
V_1183 -> V_1119 ) ;
}
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ )
if ( V_18 -> V_363 [ V_159 ] )
V_1183 -> V_1193 [ V_159 ] =
( 1 << V_18 -> V_363 [ V_159 ] -> V_261 ) - 1 ;
if ( V_30 -> V_5 [ V_1194 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_289 V_290 = F_237 ( V_45 ) ;
if ( V_290 < 0 || V_290 >= V_362 ) {
V_35 = - V_16 ;
goto V_1192;
}
if ( ! V_18 -> V_363 [ V_290 ] )
continue;
V_35 = F_238 ( V_18 -> V_363 [ V_290 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1183 -> V_1193 [ V_290 ] ) ;
if ( V_35 )
goto V_1192;
}
}
if ( V_30 -> V_5 [ V_1195 ] ) {
V_1183 -> V_51 = F_4 (
V_30 -> V_5 [ V_1195 ] ) ;
if ( ( V_1183 -> V_51 & V_1196 ) &&
! ( V_18 -> V_291 & V_1197 ) ) {
V_35 = - V_540 ;
goto V_1192;
}
if ( V_1183 -> V_51 & V_1198 ) {
if ( ! ( V_18 -> V_291 &
V_1199 ) ) {
V_35 = - V_540 ;
goto V_1192;
}
if ( V_17 -> V_149 ) {
V_35 = - V_540 ;
goto V_1192;
}
V_35 = F_232 ( V_30 -> V_5 ,
V_1183 -> V_649 ,
V_1183 -> V_1180 ) ;
if ( V_35 )
goto V_1192;
}
}
V_1183 -> V_1200 =
F_152 ( V_30 -> V_5 [ V_1201 ] ) ;
V_1183 -> V_17 = V_17 ;
V_1183 -> V_18 = & V_7 -> V_18 ;
V_1183 -> V_1202 = V_1203 ;
V_7 -> V_1186 = V_1183 ;
V_35 = F_239 ( V_7 , V_1183 ) ;
if ( ! V_35 ) {
F_240 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_241 ( V_17 -> V_19 ) ;
} else {
V_1192:
V_7 -> V_1186 = NULL ;
F_41 ( V_1183 ) ;
}
V_1188:
return V_35 ;
}
static int F_242 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1204 )
return - V_540 ;
if ( V_7 -> V_1187 )
return 0 ;
if ( ! V_7 -> V_1186 )
return - V_655 ;
F_243 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_244 ( struct V_18 * V_18 , int V_1205 ,
struct V_1206 * V_1183 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_159 = 0 ;
struct V_4 * V_45 ;
if ( ! V_5 [ V_1207 ] ) {
V_22 V_1208 ;
if ( ! V_5 [ V_1209 ] )
return - V_16 ;
V_1208 = F_4 ( V_5 [ V_1209 ] ) ;
if ( ! V_1208 )
return - V_16 ;
V_1183 -> V_1210 [ 0 ] . V_1208 =
F_245 ( V_1208 , V_1211 ) ;
if ( ! V_1183 -> V_1210 [ 0 ] . V_1208 )
return - V_16 ;
if ( V_1183 -> V_1210 [ 0 ] . V_1208 >
V_18 -> V_321 )
V_1183 -> V_1210 [ 0 ] . V_1208 =
V_18 -> V_321 ;
return 0 ;
}
F_39 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1212 [ V_1213 + 1 ] ;
if ( F_59 ( V_159 >= V_1205 ) )
return - V_16 ;
V_35 = F_96 ( V_1212 , V_1213 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1214 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1212 [ V_1215 ] )
return - V_16 ;
V_1183 -> V_1210 [ V_159 ] . V_1208 =
F_4 ( V_1212 [ V_1215 ] ) ;
if ( ! V_1183 -> V_1210 [ V_159 ] . V_1208 ||
V_1183 -> V_1210 [ V_159 ] . V_1208 >
V_18 -> V_321 )
return - V_16 ;
if ( V_1212 [ V_1216 ] ) {
V_1183 -> V_1210 [ V_159 ] . V_1217 =
F_4 ( V_1212 [ V_1216 ] ) ;
if ( ! V_1183 -> V_1210 [ V_159 ] . V_1217 ||
( V_1183 -> V_1210 [ V_159 ] . V_1217 >
V_18 -> V_323 ) )
return - V_16 ;
} else if ( V_159 < V_1205 - 1 ) {
return - V_16 ;
}
V_159 ++ ;
}
if ( V_1183 -> V_1210 [ V_1205 - 1 ] . V_1217 )
return - V_16 ;
return 0 ;
}
static struct V_1206 *
F_246 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1206 * V_1183 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1184 = 0 , V_1218 = 0 , V_366 , V_159 , V_1205 = 0 ;
enum V_289 V_290 ;
T_11 V_1119 ;
struct V_4 * V_95 [ V_1219 + 1 ] ;
T_12 V_1220 = V_1221 ;
if ( ! F_22 ( V_5 [ V_683 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1189 ] ) {
V_366 = F_231 (
V_5 [ V_1189 ] ) ;
if ( ! V_366 )
return F_3 ( - V_16 ) ;
} else {
V_366 = F_236 ( V_18 ) ;
}
if ( V_5 [ V_1190 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1184 ++ ;
if ( V_1184 > V_18 -> V_311 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1222 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1223 ;
V_35 = F_96 ( V_95 , V_1219 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1224 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1225 ] ) {
V_1218 ++ ;
continue;
}
V_1223 = V_95 [ V_1226 ] ;
if ( V_1223 )
V_1220 = V_1097 ( V_1223 ) ;
}
}
if ( ! V_1218 && V_1220 != V_1221 )
V_1218 = 1 ;
if ( V_1218 > V_18 -> V_317 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_683 ] )
V_1119 = F_24 ( V_5 [ V_683 ] ) ;
else
V_1119 = 0 ;
if ( V_1119 > V_18 -> V_315 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1207 ] ) {
if ( V_5 [ V_1209 ] )
return F_3 ( - V_16 ) ;
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1205 ++ ;
} else {
if ( ! V_5 [ V_1209 ] )
return F_3 ( - V_16 ) ;
V_1205 = 1 ;
}
if ( ! V_1205 || V_1205 > V_18 -> V_319 )
return F_3 ( - V_16 ) ;
V_1183 = F_38 ( sizeof( * V_1183 )
+ sizeof( * V_1183 -> V_1191 ) * V_1184
+ sizeof( * V_1183 -> V_1227 ) * V_1218
+ sizeof( * V_1183 -> V_1210 ) * V_1205
+ sizeof( * V_1183 -> V_367 ) * V_366
+ V_1119 , V_135 ) ;
if ( ! V_1183 )
return F_3 ( - V_136 ) ;
if ( V_1184 )
V_1183 -> V_1191 = ( void * ) & V_1183 -> V_367 [ V_366 ] ;
V_1183 -> V_1184 = V_1184 ;
if ( V_1119 ) {
if ( V_1184 )
V_1183 -> V_1118 = ( void * ) ( V_1183 -> V_1191 + V_1184 ) ;
else
V_1183 -> V_1118 = ( void * ) ( V_1183 -> V_367 + V_366 ) ;
}
if ( V_1218 ) {
if ( V_1183 -> V_1118 )
V_1183 -> V_1227 = ( void * ) ( V_1183 -> V_1118 + V_1119 ) ;
else if ( V_1184 )
V_1183 -> V_1227 =
( void * ) ( V_1183 -> V_1191 + V_1184 ) ;
else
V_1183 -> V_1227 =
( void * ) ( V_1183 -> V_367 + V_366 ) ;
}
V_1183 -> V_1218 = V_1218 ;
if ( V_1218 )
V_1183 -> V_1210 = ( void * ) ( V_1183 -> V_1227 +
V_1218 ) ;
else if ( V_1183 -> V_1118 )
V_1183 -> V_1210 = ( void * ) ( V_1183 -> V_1118 + V_1119 ) ;
else if ( V_1184 )
V_1183 -> V_1210 = ( void * ) ( V_1183 -> V_1191 + V_1184 ) ;
else
V_1183 -> V_1210 = ( void * ) ( V_1183 -> V_367 + V_366 ) ;
V_1183 -> V_1228 = V_1205 ;
V_159 = 0 ;
if ( V_5 [ V_1189 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1192;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1183 -> V_367 [ V_159 ] = V_55 ;
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
V_1183 -> V_367 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1192;
}
V_1183 -> V_366 = V_159 ;
V_159 = 0 ;
if ( V_1184 ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_618 ) {
V_35 = - V_16 ;
goto V_1192;
}
V_1183 -> V_1191 [ V_159 ] . V_592 = F_24 ( V_45 ) ;
memcpy ( V_1183 -> V_1191 [ V_159 ] . V_594 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1222 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_594 , * V_1223 ;
V_35 = F_96 ( V_95 , V_1219 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1224 ) ;
if ( V_35 )
goto V_1192;
V_594 = V_95 [ V_1225 ] ;
if ( V_594 ) {
if ( F_59 ( V_159 >= V_1218 ) ) {
V_35 = - V_16 ;
goto V_1192;
}
if ( F_24 ( V_594 ) > V_618 ) {
V_35 = - V_16 ;
goto V_1192;
}
memcpy ( V_1183 -> V_1227 [ V_159 ] . V_594 . V_594 ,
F_23 ( V_594 ) , F_24 ( V_594 ) ) ;
V_1183 -> V_1227 [ V_159 ] . V_594 . V_592 =
F_24 ( V_594 ) ;
V_1183 -> V_1227 [ V_159 ] . V_1229 =
V_1220 ;
V_1223 = V_95 [ V_1226 ] ;
if ( V_1223 )
V_1183 -> V_1227 [ V_159 ] . V_1229 =
V_1097 ( V_1223 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1218 )
V_1183 -> V_1227 [ 0 ] . V_1229 = V_1220 ;
V_1183 -> V_1230 = V_1231 ;
for ( V_159 = 0 ; V_159 < V_1218 ; V_159 ++ )
V_1183 -> V_1230 =
T_9 ( V_1183 -> V_1227 [ V_159 ] . V_1229 ,
V_1183 -> V_1230 ) ;
} else {
V_1183 -> V_1230 = V_1221 ;
}
if ( V_1119 ) {
V_1183 -> V_1119 = V_1119 ;
memcpy ( ( void * ) V_1183 -> V_1118 ,
F_23 ( V_5 [ V_683 ] ) ,
V_1183 -> V_1119 ) ;
}
if ( V_5 [ V_1195 ] ) {
V_1183 -> V_51 = F_4 (
V_5 [ V_1195 ] ) ;
if ( ( V_1183 -> V_51 & V_1196 ) &&
! ( V_18 -> V_291 & V_1197 ) ) {
V_35 = - V_540 ;
goto V_1192;
}
if ( V_1183 -> V_51 & V_1198 ) {
V_22 V_1232 = V_1233 ;
if ( ! V_17 )
V_1232 = V_1234 ;
if ( ! ( V_18 -> V_291 & V_1232 ) ) {
V_35 = - V_540 ;
goto V_1192;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_540 ;
goto V_1192;
}
V_35 = F_232 ( V_5 , V_1183 -> V_649 ,
V_1183 -> V_1180 ) ;
if ( V_35 )
goto V_1192;
}
}
if ( V_5 [ V_1235 ] )
V_1183 -> V_1236 =
F_4 ( V_5 [ V_1235 ] ) ;
V_35 = F_244 ( V_18 , V_1205 , V_1183 , V_5 ) ;
if ( V_35 )
goto V_1192;
V_1183 -> V_1202 = V_1203 ;
return V_1183 ;
V_1192:
F_41 ( V_1183 ) ;
return F_3 ( V_35 ) ;
}
static int F_247 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1206 * V_1237 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_423 )
return - V_540 ;
if ( V_7 -> V_1237 )
return - V_1024 ;
V_1237 = F_246 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_248 ( V_1237 ) ;
if ( V_35 )
goto V_884;
V_35 = F_249 ( V_7 , V_539 , V_1237 ) ;
if ( V_35 )
goto V_1192;
V_1237 -> V_539 = V_539 ;
V_1237 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_631 ] )
V_1237 -> V_632 = V_30 -> V_504 ;
F_250 ( V_7 -> V_1237 , V_1237 ) ;
F_251 ( V_7 , V_539 ,
V_1238 ) ;
return 0 ;
V_1192:
F_41 ( V_1237 ) ;
V_884:
return V_35 ;
}
static int F_252 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_422 ) ||
! V_7 -> V_351 -> V_1239 )
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
enum V_1168 V_1133 ;
unsigned int V_1240 ;
int V_35 ;
V_1133 = F_255 ( V_17 -> V_18 ) ;
if ( V_1133 == V_1169 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
if ( F_256 ( V_539 ) )
return - V_544 ;
if ( V_17 -> V_1241 )
return - V_544 ;
V_35 = F_257 ( V_17 -> V_18 , & V_520 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_258 ( V_17 -> V_18 , & V_520 ) )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1242 )
return - V_540 ;
V_1240 = F_259 ( & V_7 -> V_18 , & V_520 ) ;
if ( F_59 ( ! V_1240 ) )
V_1240 = V_1243 ;
V_35 = F_260 ( V_7 , V_539 , & V_520 , V_1240 ) ;
if ( ! V_35 ) {
V_17 -> V_520 = V_520 ;
V_17 -> V_1241 = true ;
V_17 -> V_1244 = V_1203 ;
V_17 -> V_1240 = V_1240 ;
}
return V_35 ;
}
static int F_261 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_1245 V_137 ;
static struct V_4 * V_1246 [ V_1247 + 1 ] ;
int V_35 ;
bool V_1248 = false ;
int V_47 , V_159 ;
V_22 V_1249 ;
if ( ! V_7 -> V_351 -> V_442 ||
! ( V_7 -> V_18 . V_51 & V_441 ) )
return - V_540 ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1248 = true ;
if ( ! V_17 -> V_541 )
return - V_1250 ;
break;
case V_146 :
if ( ! V_17 -> V_592 )
return - V_1250 ;
break;
case V_145 :
if ( ! V_17 -> V_1034 )
return - V_1250 ;
break;
default:
return - V_540 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_522 ] ||
! V_30 -> V_5 [ V_1251 ] )
return - V_16 ;
if ( V_1248 && ! V_30 -> V_5 [ V_1252 ] )
return - V_16 ;
V_1249 = F_4 ( V_30 -> V_5 [ V_1251 ] ) ;
if ( V_1249 > 255 )
return - V_16 ;
V_137 . V_1253 = V_1249 ;
if ( ! V_1248 )
goto V_1254;
V_35 = F_146 ( V_30 -> V_5 , & V_137 . V_1255 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1246 , V_1247 ,
V_30 -> V_5 [ V_1252 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_146 ( V_1246 , & V_137 . V_1256 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1246 [ V_1257 ] )
return - V_16 ;
V_47 = F_24 ( V_1246 [ V_1257 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1258 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1258 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1259 =
F_23 ( V_1246 [ V_1257 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1258 ; V_159 ++ ) {
T_3 V_1260 = V_137 . V_1259 [ V_159 ] ;
if ( V_1260 >= V_137 . V_1256 . V_690 )
return - V_16 ;
if ( V_137 . V_1256 . V_689 [ V_1260 ] != V_137 . V_1253 )
return - V_16 ;
}
if ( V_1246 [ V_1261 ] ) {
V_47 = F_24 ( V_1246 [ V_1261 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1262 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_489 &&
( V_137 . V_1258 >
V_7 -> V_18 . V_489 ) )
return - V_16 ;
V_137 . V_1263 =
F_23 ( V_1246 [ V_1261 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1262 ; V_159 ++ ) {
T_3 V_1260 = V_137 . V_1263 [ V_159 ] ;
if ( V_1260 >= V_137 . V_1256 . V_699 )
return - V_16 ;
if ( V_137 . V_1256 . V_698 [ V_1260 ] !=
V_137 . V_1253 )
return - V_16 ;
}
}
V_1254:
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
V_137 . V_1264 = true ;
if ( V_30 -> V_5 [ V_1265 ] )
V_137 . V_1266 = true ;
F_113 ( V_17 ) ;
V_35 = F_262 ( V_7 , V_539 , & V_137 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_263 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1267 * V_1268 )
{
struct V_1269 * V_355 = & V_1268 -> V_1270 ;
const struct V_1271 * V_1272 ;
void * V_283 ;
struct V_4 * V_1273 ;
F_43 ( V_17 ) ;
V_283 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1274 ) ;
if ( ! V_283 )
return - 1 ;
F_223 ( V_34 , V_283 , & V_38 ) ;
if ( F_28 ( V_53 , V_293 , V_7 -> V_1275 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
V_1273 = F_47 ( V_53 , V_1276 ) ;
if ( ! V_1273 )
goto V_61;
if ( ( ! F_264 ( V_355 -> V_546 ) &&
F_51 ( V_53 , V_1277 , V_587 , V_355 -> V_546 ) ) )
goto V_61;
F_219 () ;
if ( F_203 ( V_355 -> V_693 ) &&
F_29 ( V_53 , V_1278 ) )
goto V_1279;
V_1272 = F_220 ( V_355 -> V_1272 ) ;
if ( V_1272 ) {
if ( F_104 ( V_53 , V_1280 , V_1272 -> V_1281 ) )
goto V_1279;
if ( V_1272 -> V_47 && F_51 ( V_53 , V_1282 ,
V_1272 -> V_47 , V_1272 -> V_138 ) )
goto V_1279;
}
V_1272 = F_220 ( V_355 -> V_691 ) ;
if ( V_1272 && V_1272 -> V_1283 ) {
if ( F_104 ( V_53 , V_1284 , V_1272 -> V_1281 ) )
goto V_1279;
if ( V_1272 -> V_47 && F_51 ( V_53 , V_1285 ,
V_1272 -> V_47 , V_1272 -> V_138 ) )
goto V_1279;
}
F_221 () ;
if ( V_355 -> V_541 &&
F_55 ( V_53 , V_1286 , V_355 -> V_541 ) )
goto V_61;
if ( F_55 ( V_53 , V_1287 , V_355 -> V_942 ) ||
F_28 ( V_53 , V_1288 , V_355 -> V_1289 -> V_60 ) ||
F_28 ( V_53 , V_1290 , V_355 -> V_1291 ) ||
F_28 ( V_53 , V_1292 ,
F_265 ( V_1203 - V_1268 -> V_1293 ) ) )
goto V_61;
if ( V_1268 -> V_1294 &&
F_104 ( V_53 , V_1295 ,
V_1268 -> V_1294 ) )
goto V_61;
switch ( V_7 -> V_18 . V_816 ) {
case V_817 :
if ( F_28 ( V_53 , V_1296 , V_355 -> signal ) )
goto V_61;
break;
case V_1297 :
if ( F_56 ( V_53 , V_1298 , V_355 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1268 == V_17 -> V_149 &&
F_28 ( V_53 , V_1299 ,
V_1300 ) )
goto V_61;
break;
case V_146 :
if ( V_1268 == V_17 -> V_149 &&
F_28 ( V_53 , V_1299 ,
V_1301 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1273 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_1279:
F_221 () ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_266 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1267 * V_1185 ;
struct V_1 * V_17 ;
int V_499 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
F_267 ( & V_7 -> V_1302 ) ;
F_268 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1275 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_499 )
continue;
if ( F_263 ( V_32 , V_34 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_7 , V_17 , V_1185 ) < 0 ) {
V_105 -- ;
break;
}
}
F_269 ( & V_7 -> V_1302 ) ;
F_115 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_270 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_539 ,
bool V_1303 ,
struct V_1304 * V_1305 )
{
void * V_283 ;
struct V_4 * V_1306 ;
if ( ! V_1305 -> V_1289 && ! V_1303 )
return 0 ;
V_283 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1307 ) ;
if ( ! V_283 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) )
goto V_61;
V_1306 = F_47 ( V_53 , V_1308 ) ;
if ( ! V_1306 )
goto V_61;
if ( V_1305 -> V_1289 &&
F_28 ( V_53 , V_1309 ,
V_1305 -> V_1289 -> V_60 ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1310 ) &&
F_56 ( V_53 , V_1311 , V_1305 -> V_1312 ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1313 ) &&
F_29 ( V_53 , V_1314 ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1315 ) &&
F_104 ( V_53 , V_1316 ,
V_1305 -> time ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1317 ) &&
F_104 ( V_53 , V_1318 ,
V_1305 -> V_1319 ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1320 ) &&
F_104 ( V_53 , V_1321 ,
V_1305 -> V_1322 ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1323 ) &&
F_104 ( V_53 , V_1324 ,
V_1305 -> V_1325 ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1326 ) &&
F_104 ( V_53 , V_1327 ,
V_1305 -> V_1328 ) )
goto V_61;
if ( ( V_1305 -> V_801 & V_1329 ) &&
F_104 ( V_53 , V_1330 ,
V_1305 -> V_1331 ) )
goto V_61;
F_48 ( V_53 , V_1306 ) ;
F_66 ( V_53 , V_283 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_283 ) ;
return - V_495 ;
}
static int F_271 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1304 V_1305 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1332 = V_34 -> args [ 2 ] ;
int V_355 ;
bool V_1333 ;
V_355 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_355 )
return V_355 ;
V_1333 = V_38 . V_40 [ V_1334 ] ;
if ( ! V_17 -> V_19 ) {
V_355 = - V_16 ;
goto V_884;
}
if ( ! V_7 -> V_351 -> V_1335 ) {
V_355 = - V_540 ;
goto V_884;
}
while ( 1 ) {
V_355 = F_272 ( V_7 , V_17 -> V_19 , V_1332 , & V_1305 ) ;
if ( V_355 == - V_655 )
break;
if ( V_355 )
goto V_884;
if ( V_1305 . V_1289 &&
V_1305 . V_1289 -> V_51 & V_62 ) {
V_1332 ++ ;
continue;
}
if ( F_270 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_17 -> V_19 , V_1333 , & V_1305 ) < 0 )
goto V_599;
V_1332 ++ ;
}
V_599:
V_34 -> args [ 2 ] = V_1332 ;
V_355 = V_32 -> V_47 ;
V_884:
F_21 ( V_7 ) ;
return V_355 ;
}
static bool F_273 ( V_22 V_1336 )
{
return ! ( V_1336 & ~ ( V_1337 |
V_1338 ) ) ;
}
static int F_274 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_546 , * V_594 , * V_1118 = NULL , * V_1339 = NULL ;
int V_35 , V_592 , V_1119 = 0 , V_1340 = 0 ;
enum V_701 V_702 ;
struct V_93 V_92 ;
bool V_1341 ;
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
V_92 . V_107 . V_108 != V_1342 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1343 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_159 ;
bool V_1344 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_338 ; V_159 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_339 [ V_159 ] ) {
V_1344 = true ;
break;
}
}
if ( ! V_1344 )
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
V_1118 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_702 = F_4 ( V_30 -> V_5 [ V_720 ] ) ;
if ( ! F_148 ( V_7 , V_702 , V_704 ) )
return - V_16 ;
if ( V_702 == V_706 &&
! V_30 -> V_5 [ V_1345 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1345 ] ) {
if ( V_702 != V_706 )
return - V_16 ;
V_1339 = F_23 ( V_30 -> V_5 [ V_1345 ] ) ;
V_1340 = F_24 ( V_30 -> V_5 [ V_1345 ] ) ;
if ( V_1340 < 4 )
return - V_16 ;
}
V_1341 = ! ! V_30 -> V_5 [ V_1346 ] ;
if ( V_1341 )
return 0 ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_275 ( V_7 , V_539 , V_55 , V_702 , V_546 ,
V_594 , V_592 , V_1118 , V_1119 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1339 , V_1340 ) ;
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static int F_151 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1347 * V_1348 ,
int V_1349 )
{
memset ( V_1348 , 0 , sizeof( * V_1348 ) ) ;
V_1348 -> V_1350 = V_30 -> V_5 [ V_1351 ] ;
if ( V_30 -> V_5 [ V_343 ] ) {
T_3 V_1352 ;
V_1352 = F_78 (
V_30 -> V_5 [ V_343 ] ) ;
V_1348 -> V_1353 = F_276 ( V_1352 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_342 ) &&
V_1352 != V_1354 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1355 ] )
V_1348 -> V_1356 = true ;
} else
V_1348 -> V_1353 = F_276 ( V_1354 ) ;
if ( V_30 -> V_5 [ V_1357 ] ) {
void * V_138 ;
int V_47 , V_159 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1357 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1357 ] ) ;
V_1348 -> V_1358 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1348 -> V_1358 > V_1349 )
return - V_16 ;
memcpy ( V_1348 -> V_1359 , V_138 , V_47 ) ;
for ( V_159 = 0 ; V_159 < V_1348 -> V_1358 ; V_159 ++ )
if ( ! F_277 (
& V_7 -> V_18 ,
V_1348 -> V_1359 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1360 ] ) {
V_1348 -> V_1361 =
F_4 ( V_30 -> V_5 [ V_1360 ] ) ;
if ( ! F_277 ( & V_7 -> V_18 ,
V_1348 -> V_1361 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1362 ] ) {
V_1348 -> V_1336 =
F_4 ( V_30 -> V_5 [ V_1362 ] ) ;
if ( ! F_273 ( V_1348 -> V_1336 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1363 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1363 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1363 ] ) ;
V_1348 -> V_1364 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1348 -> V_1364 > V_1365 )
return - V_16 ;
memcpy ( V_1348 -> V_1366 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_278 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1367 V_1368 = {} ;
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
V_1368 . V_1118 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1368 . V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
if ( V_30 -> V_5 [ V_1369 ] ) {
enum V_1370 V_1371 =
F_4 ( V_30 -> V_5 [ V_1369 ] ) ;
if ( V_1371 == V_1372 )
V_1368 . V_1373 = true ;
else if ( V_1371 != V_1374 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1375 ] )
V_1368 . V_1376 = F_23 ( V_30 -> V_5 [ V_1375 ] ) ;
if ( F_152 ( V_30 -> V_5 [ V_1377 ] ) )
V_1368 . V_51 |= V_1378 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1368 . V_1379 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1368 . V_1379 ) ) ;
if ( V_30 -> V_5 [ V_934 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1368 . V_905 ,
F_23 ( V_30 -> V_5 [ V_934 ] ) ,
sizeof( V_1368 . V_905 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1380 ] ) )
V_1368 . V_51 |= V_1381 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_1368 . V_1382 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_1368 . V_1382 ) ) ;
if ( V_30 -> V_5 [ V_935 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] )
return - V_16 ;
memcpy ( & V_1368 . V_906 ,
F_23 ( V_30 -> V_5 [ V_935 ] ) ,
sizeof( V_1368 . V_906 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1383 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_291 &
V_1384 ) &&
( V_7 -> V_18 . V_291 & V_1385 ) ) &&
! F_279 ( & V_7 -> V_18 ,
V_1386 ) )
return - V_16 ;
V_1368 . V_51 |= V_1387 ;
}
V_35 = F_151 ( V_7 , V_30 , & V_1368 . V_722 , 1 ) ;
if ( ! V_35 ) {
F_113 ( V_539 -> V_28 ) ;
V_35 = F_280 ( V_7 , V_539 , V_55 , V_546 ,
V_594 , V_592 , & V_1368 ) ;
F_115 ( V_539 -> V_28 ) ;
}
return V_35 ;
}
static int F_281 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
const T_2 * V_1118 = NULL , * V_546 ;
int V_1119 = 0 , V_35 ;
T_3 V_968 ;
bool V_1341 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_967 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_389 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_968 = F_78 ( V_30 -> V_5 [ V_967 ] ) ;
if ( V_968 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_683 ] ) {
V_1118 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_1341 = ! ! V_30 -> V_5 [ V_1346 ] ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_282 ( V_7 , V_539 , V_546 , V_1118 , V_1119 , V_968 ,
V_1341 ) ;
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static int F_283 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
const T_2 * V_1118 = NULL , * V_546 ;
int V_1119 = 0 , V_35 ;
T_3 V_968 ;
bool V_1341 ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_967 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_391 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_968 = F_78 ( V_30 -> V_5 [ V_967 ] ) ;
if ( V_968 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_683 ] ) {
V_1118 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_1341 = ! ! V_30 -> V_5 [ V_1346 ] ;
F_113 ( V_539 -> V_28 ) ;
V_35 = F_284 ( V_7 , V_539 , V_546 , V_1118 , V_1119 , V_968 ,
V_1341 ) ;
F_115 ( V_539 -> V_28 ) ;
return V_35 ;
}
static bool
F_285 ( struct V_6 * V_7 ,
int V_1388 [ V_362 ] ,
int V_1389 )
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
if ( V_240 -> V_262 [ V_159 ] . V_264 == V_1389 ) {
V_1388 [ V_290 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_286 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1390 V_1391 ;
struct V_18 * V_18 ;
struct V_130 * V_1392 = NULL ;
int V_35 ;
memset ( & V_1391 , 0 , sizeof( V_1391 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_593 ] ||
! F_24 ( V_30 -> V_5 [ V_593 ] ) )
return - V_16 ;
V_1391 . V_541 = 100 ;
if ( V_30 -> V_5 [ V_709 ] ) {
V_1391 . V_541 =
F_4 ( V_30 -> V_5 [ V_709 ] ) ;
if ( V_1391 . V_541 < 1 || V_1391 . V_541 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_351 -> V_393 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_146 )
return - V_540 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_547 ] ) {
V_1391 . V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( ! F_120 ( V_1391 . V_546 ) )
return - V_16 ;
}
V_1391 . V_594 = F_23 ( V_30 -> V_5 [ V_593 ] ) ;
V_1391 . V_592 = F_24 ( V_30 -> V_5 [ V_593 ] ) ;
if ( V_30 -> V_5 [ V_683 ] ) {
V_1391 . V_1118 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1391 . V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1391 . V_520 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_287 ( & V_7 -> V_18 , & V_1391 . V_520 ,
V_146 ) )
return - V_16 ;
switch ( V_1391 . V_520 . V_523 ) {
case V_537 :
case V_538 :
case V_524 :
break;
case V_579 :
case V_580 :
if ( ! ( V_7 -> V_18 . V_291 & V_1393 ) )
return - V_16 ;
break;
case V_1394 :
case V_1395 :
case V_1396 :
if ( ! ( V_7 -> V_18 . V_291 & V_1393 ) )
return - V_16 ;
if ( ! F_279 ( & V_7 -> V_18 ,
V_1397 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1391 . V_1398 = ! ! V_30 -> V_5 [ V_1399 ] ;
V_1391 . V_718 = ! ! V_30 -> V_5 [ V_719 ] ;
if ( V_30 -> V_5 [ V_1015 ] ) {
T_2 * V_1193 =
F_23 ( V_30 -> V_5 [ V_1015 ] ) ;
int V_1400 =
F_24 ( V_30 -> V_5 [ V_1015 ] ) ;
struct V_239 * V_240 =
V_18 -> V_363 [ V_1391 . V_520 . V_55 -> V_290 ] ;
V_35 = F_238 ( V_240 , V_1193 , V_1400 ,
& V_1391 . V_1016 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1391 . V_1379 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1391 . V_1379 ) ) ;
if ( V_30 -> V_5 [ V_934 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1391 . V_905 ,
F_23 ( V_30 -> V_5 [ V_934 ] ) ,
sizeof( V_1391 . V_905 ) ) ;
}
if ( V_30 -> V_5 [ V_1401 ] &&
! F_285 ( V_7 , V_1391 . V_1388 ,
F_4 ( V_30 -> V_5 [ V_1401 ] ) ) )
return - V_16 ;
if ( V_1391 . V_718 && V_30 -> V_5 [ V_1402 ] ) {
bool V_132 = false ;
V_1392 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1402 ] ,
& V_132 ) ;
if ( F_17 ( V_1392 ) )
return F_18 ( V_1392 ) ;
if ( ( V_1391 . V_520 . V_523 != V_524 ) &&
V_132 ) {
F_288 ( V_1392 ) ;
return - V_16 ;
}
}
V_1391 . V_1350 =
F_152 ( V_30 -> V_5 [ V_1351 ] ) ;
V_1391 . V_1403 =
F_152 ( V_30 -> V_5 [ V_1404 ] ) ;
V_35 = F_289 ( V_7 , V_539 , & V_1391 , V_1392 ) ;
if ( V_35 )
F_288 ( V_1392 ) ;
return V_35 ;
}
static int F_290 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1405 )
return - V_540 ;
if ( V_539 -> V_28 -> V_141 != V_146 )
return - V_540 ;
return F_291 ( V_7 , V_539 , false ) ;
}
static int F_292 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
int V_1388 [ V_362 ] ;
V_22 V_1406 ;
int V_35 ;
if ( V_539 -> V_28 -> V_141 != V_146 &&
V_539 -> V_28 -> V_141 != V_145 &&
V_539 -> V_28 -> V_141 != V_152 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_433 )
return - V_540 ;
memset ( V_1388 , 0 , sizeof( V_1388 ) ) ;
if ( ! V_30 -> V_5 [ V_1401 ] )
return - V_16 ;
V_1406 = F_4 ( V_30 -> V_5 [ V_1401 ] ) ;
if ( ! F_285 ( V_7 , V_1388 , V_1406 ) )
return - V_16 ;
V_35 = F_293 ( V_7 , V_539 , V_1388 ) ;
return V_35 ;
}
static struct V_31 *
F_294 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1407 ,
V_22 V_49 , V_22 V_50 , enum V_280 V_52 ,
enum V_765 V_45 ,
const struct V_481 * V_30 ,
T_13 V_1408 )
{
struct V_31 * V_32 ;
void * V_283 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1407 + 100 , V_1408 ) ;
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
if ( F_28 ( V_32 , V_1409 ,
V_30 -> V_1410 ) )
goto V_61;
if ( F_28 ( V_32 , V_1411 ,
V_30 -> V_1412 ) )
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
enum V_765 V_45 ,
int V_1413 ,
int V_1407 , T_13 V_1408 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_481 * V_30 ;
switch ( V_52 ) {
case V_1414 :
if ( F_59 ( V_1413 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1415 :
if ( F_59 ( V_1413 < 0 ||
V_1413 >= V_18 -> V_485 ) )
return NULL ;
V_30 = & V_18 -> V_487 [ V_1413 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_294 ( V_7 , V_17 , V_1407 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1408 ) ;
}
void F_297 ( struct V_31 * V_32 , T_13 V_1408 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1416 V_1417 = V_1418 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
if ( V_138 -> F_237 == V_483 )
V_1417 = V_1419 ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1417 , V_1408 ) ;
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
if ( ! V_30 -> V_5 [ V_1420 ] )
return - V_16 ;
V_7 -> V_1421 = V_30 ;
V_35 = F_299 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1420 ] ) ,
F_24 ( V_30 -> V_5 [ V_1420 ] ) ) ;
V_7 -> V_1421 = NULL ;
return V_35 ;
}
static int F_300 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1422 ;
void * V_138 = NULL ;
int V_1423 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1422 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_884;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_884;
}
V_1422 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1420 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1420 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1423 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1422 ) ;
if ( ! V_7 ) {
V_35 = - V_655 ;
goto V_884;
}
if ( ! V_7 -> V_351 -> V_1424 ) {
V_35 = - V_540 ;
goto V_884;
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_1414 ) ;
struct V_4 * V_1425 ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_1422 ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1425 = F_47 ( V_32 , V_1420 ) ;
if ( ! V_1425 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = F_301 ( V_7 , V_32 , V_34 , V_138 , V_1423 ) ;
F_48 ( V_32 , V_1425 ) ;
if ( V_35 == - V_91 || V_35 == - V_655 ) {
F_67 ( V_32 , V_283 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_283 ) ;
goto V_884;
}
F_66 ( V_32 , V_283 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1422 + 1 ;
V_884:
F_20 () ;
return V_35 ;
}
static int F_302 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1426 V_449 ;
struct V_18 * V_18 ;
struct V_130 * V_1392 = NULL ;
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
V_449 . V_1427 = - 1 ;
if ( V_30 -> V_5 [ V_1428 ] &&
( V_18 -> V_51 & V_330 ) ) {
V_449 . V_1427 =
F_78 ( V_30 -> V_5 [ V_1428 ] ) ;
}
if ( V_30 -> V_5 [ V_547 ] )
V_449 . V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
else if ( V_30 -> V_5 [ V_1429 ] )
V_449 . V_1430 =
F_23 ( V_30 -> V_5 [ V_1429 ] ) ;
V_449 . V_594 = F_23 ( V_30 -> V_5 [ V_593 ] ) ;
V_449 . V_592 = F_24 ( V_30 -> V_5 [ V_593 ] ) ;
if ( V_30 -> V_5 [ V_683 ] ) {
V_449 . V_1118 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_449 . V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
}
if ( V_30 -> V_5 [ V_1369 ] ) {
V_449 . V_1371 = F_4 ( V_30 -> V_5 [ V_1369 ] ) ;
if ( V_449 . V_1371 != V_1372 &&
V_449 . V_1371 != V_1374 )
return - V_16 ;
} else {
V_449 . V_1371 = V_1374 ;
}
if ( V_30 -> V_5 [ V_522 ] ) {
V_449 . V_1289 = F_44 (
V_18 , V_30 -> V_5 [ V_522 ] ) ;
if ( ! V_449 . V_1289 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1431 ] ) {
V_449 . V_1432 = F_44 (
V_18 , V_30 -> V_5 [ V_1431 ] ) ;
if ( ! V_449 . V_1432 )
return - V_16 ;
}
if ( V_449 . V_718 && V_30 -> V_5 [ V_1402 ] ) {
V_1392 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1402 ] , NULL ) ;
if ( F_17 ( V_1392 ) )
return F_18 ( V_1392 ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1377 ] ) )
V_449 . V_51 |= V_1378 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_449 . V_1379 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_449 . V_1379 ) ) ;
if ( V_30 -> V_5 [ V_934 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] ) {
F_288 ( V_1392 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_905 ,
F_23 ( V_30 -> V_5 [ V_934 ] ) ,
sizeof( V_449 . V_905 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1380 ] ) )
V_449 . V_51 |= V_1381 ;
if ( V_30 -> V_5 [ V_474 ] )
memcpy ( & V_449 . V_1382 ,
F_23 ( V_30 -> V_5 [ V_474 ] ) ,
sizeof( V_449 . V_1382 ) ) ;
if ( V_30 -> V_5 [ V_935 ] ) {
if ( ! V_30 -> V_5 [ V_474 ] ) {
F_288 ( V_1392 ) ;
return - V_16 ;
}
memcpy ( & V_449 . V_906 ,
F_23 ( V_30 -> V_5 [ V_935 ] ) ,
sizeof( V_449 . V_906 ) ) ;
}
if ( F_152 ( V_30 -> V_5 [ V_1383 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_291 &
V_1384 ) &&
( V_7 -> V_18 . V_291 & V_1385 ) ) &&
! F_279 ( & V_7 -> V_18 ,
V_1386 ) ) {
F_288 ( V_1392 ) ;
return - V_16 ;
}
V_449 . V_51 |= V_1387 ;
}
V_449 . V_740 = F_152 ( V_30 -> V_5 [ V_741 ] ) ;
if ( V_449 . V_740 && ! V_7 -> V_18 . V_363 [ V_742 ] ) {
F_288 ( V_1392 ) ;
return - V_540 ;
}
F_113 ( V_539 -> V_28 ) ;
V_35 = F_303 ( V_7 , V_539 , & V_449 , V_1392 , NULL ) ;
F_115 ( V_539 -> V_28 ) ;
if ( V_35 )
F_288 ( V_1392 ) ;
return V_35 ;
}
static int F_304 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_3 V_1433 ;
int V_496 ;
if ( ! V_30 -> V_5 [ V_967 ] )
V_1433 = V_1434 ;
else
V_1433 = F_78 ( V_30 -> V_5 [ V_967 ] ) ;
if ( V_1433 == 0 )
return - V_16 ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
F_113 ( V_539 -> V_28 ) ;
V_496 = F_305 ( V_7 , V_539 , V_1433 , true ) ;
F_115 ( V_539 -> V_28 ) ;
return V_496 ;
}
static int F_306 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1435 ] ) {
V_22 V_1436 = F_4 ( V_30 -> V_5 [ V_1435 ] ) ;
V_2 = F_307 ( V_1436 ) ;
} else if ( V_30 -> V_5 [ V_1437 ] ) {
V_22 V_1438 = F_4 ( V_30 -> V_5 [ V_1437 ] ) ;
V_2 = F_308 ( V_1438 ) ;
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
struct V_1439 * V_1440 ) = NULL ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1439 V_1440 ;
memset ( & V_1440 , 0 , sizeof( struct V_1439 ) ) ;
if ( ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1441 ] )
return - V_16 ;
V_1440 . V_1442 = F_23 ( V_30 -> V_5 [ V_1441 ] ) ;
V_1440 . V_546 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_539 -> V_28 -> V_141 != V_147 &&
V_539 -> V_28 -> V_141 != V_148 )
return - V_540 ;
switch ( V_30 -> V_1443 -> V_52 ) {
case V_1444 :
F_312 = V_7 -> V_351 -> V_397 ;
break;
case V_1445 :
F_312 = V_7 -> V_351 -> V_399 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_312 )
return - V_540 ;
return F_312 ( & V_7 -> V_18 , V_539 , & V_1440 ) ;
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
T_2 V_1446 , V_1447 ;
V_22 V_1448 = 0 ;
T_3 V_1449 ;
T_2 * V_1450 ;
bool V_1451 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_418 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1452 ] ||
! V_30 -> V_5 [ V_1453 ] ||
! V_30 -> V_5 [ V_1454 ] ||
! V_30 -> V_5 [ V_683 ] ||
! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_1450 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_1446 = F_34 ( V_30 -> V_5 [ V_1452 ] ) ;
V_1449 = F_78 ( V_30 -> V_5 [ V_1453 ] ) ;
V_1447 = F_34 ( V_30 -> V_5 [ V_1454 ] ) ;
V_1451 = F_152 ( V_30 -> V_5 [ V_1455 ] ) ;
if ( V_30 -> V_5 [ V_1456 ] )
V_1448 =
F_4 ( V_30 -> V_5 [ V_1456 ] ) ;
return F_316 ( V_7 , V_539 , V_1450 , V_1446 ,
V_1447 , V_1449 , V_1448 ,
V_1451 ,
F_23 ( V_30 -> V_5 [ V_683 ] ) ,
F_24 ( V_30 -> V_5 [ V_683 ] ) ) ;
}
static int F_317 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
enum V_1457 V_1458 ;
T_2 * V_1450 ;
if ( ! ( V_7 -> V_18 . V_51 & V_332 ) ||
! V_7 -> V_351 -> V_420 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1459 ] ||
! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_1458 = F_34 ( V_30 -> V_5 [ V_1459 ] ) ;
V_1450 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
return F_318 ( V_7 , V_539 , V_1450 , V_1458 ) ;
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
V_22 V_1460 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_522 ] ||
! V_30 -> V_5 [ V_1461 ] )
return - V_16 ;
V_1460 = F_4 ( V_30 -> V_5 [ V_1461 ] ) ;
if ( ! V_7 -> V_351 -> V_404 ||
! ( V_7 -> V_18 . V_51 & V_403 ) )
return - V_540 ;
if ( V_1460 < V_1462 ||
V_1460 > V_7 -> V_18 . V_454 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1463 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_657;
}
V_35 = F_320 ( V_7 , V_17 , V_520 . V_55 ,
V_1460 , & V_647 ) ;
if ( V_35 )
goto V_657;
if ( F_104 ( V_53 , V_1464 , V_647 ) )
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
if ( ! V_30 -> V_5 [ V_1464 ] )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1465 )
return - V_540 ;
V_647 = F_5 ( V_30 -> V_5 [ V_1464 ] ) ;
return F_322 ( V_7 , V_17 , V_647 ) ;
}
static V_22 F_323 ( struct V_239 * V_240 ,
T_2 * V_1193 , T_2 V_1466 )
{
T_2 V_159 ;
V_22 V_750 = 0 ;
for ( V_159 = 0 ; V_159 < V_1466 ; V_159 ++ ) {
int V_244 = ( V_1193 [ V_159 ] & 0x7f ) * 5 ;
int V_1467 ;
for ( V_1467 = 0 ; V_1467 < V_240 -> V_261 ; V_1467 ++ ) {
struct V_243 * V_1468 =
& V_240 -> V_262 [ V_1467 ] ;
if ( V_244 == V_1468 -> V_264 ) {
V_750 |= 1 << V_1467 ;
break;
}
}
if ( V_1467 == V_240 -> V_261 )
return 0 ;
}
return V_750 ;
}
static bool F_324 ( struct V_239 * V_240 ,
T_2 * V_1193 , T_2 V_1466 ,
T_2 V_248 [ V_1469 ] )
{
T_2 V_159 ;
memset ( V_248 , 0 , V_1469 ) ;
for ( V_159 = 0 ; V_159 < V_1466 ; V_159 ++ ) {
int V_1467 , V_1470 ;
V_1467 = V_1193 [ V_159 ] / 8 ;
V_1470 = F_159 ( V_1193 [ V_159 ] % 8 ) ;
if ( ( V_1467 < 0 ) || ( V_1467 >= V_1469 ) )
return false ;
if ( V_240 -> V_245 . V_248 . V_1471 [ V_1467 ] & V_1470 )
V_248 [ V_1467 ] |= V_1470 ;
else
return false ;
}
return true ;
}
static T_3 F_325 ( T_2 V_1472 )
{
T_3 V_1473 = 0 ;
switch ( V_1472 ) {
case V_1474 :
break;
case V_1475 :
V_1473 = 0x00FF ;
break;
case V_1476 :
V_1473 = 0x01FF ;
break;
case V_1477 :
V_1473 = 0x03FF ;
break;
default:
break;
}
return V_1473 ;
}
static void F_326 ( T_3 V_1472 ,
T_3 V_1478 [ V_1479 ] )
{
T_2 V_788 ;
for ( V_788 = 0 ; V_788 < V_1479 ; V_788 ++ ) {
V_1478 [ V_788 ] = F_325 ( V_1472 & 0x03 ) ;
V_1472 >>= 2 ;
}
}
static bool F_327 ( struct V_239 * V_240 ,
struct V_1480 * V_826 ,
T_3 V_248 [ V_1479 ] )
{
T_3 V_1481 = F_328 ( V_240 -> V_255 . V_258 . V_1481 ) ;
T_3 V_1482 [ V_1479 ] = {} ;
T_2 V_159 ;
if ( ! V_240 -> V_255 . V_256 )
return false ;
memset ( V_248 , 0 , sizeof( T_3 ) * V_1479 ) ;
F_326 ( V_1481 , V_1482 ) ;
for ( V_159 = 0 ; V_159 < V_1479 ; V_159 ++ ) {
if ( ( V_1482 [ V_159 ] & V_826 -> V_248 [ V_159 ] ) == V_826 -> V_248 [ V_159 ] )
V_248 [ V_159 ] = V_826 -> V_248 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_329 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1483 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1484 V_750 ;
int V_134 , V_159 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_4 * V_1485 ;
struct V_239 * V_240 ;
T_3 V_1486 ;
if ( ! V_7 -> V_351 -> V_406 )
return - V_540 ;
memset ( & V_750 , 0 , sizeof( V_750 ) ) ;
for ( V_159 = 0 ; V_159 < V_362 ; V_159 ++ ) {
V_240 = V_7 -> V_18 . V_363 [ V_159 ] ;
if ( ! V_240 )
continue;
V_750 . V_1487 [ V_159 ] . V_1488 = ( 1 << V_240 -> V_261 ) - 1 ;
memcpy ( V_750 . V_1487 [ V_159 ] . V_1489 ,
V_240 -> V_245 . V_248 . V_1471 ,
sizeof( V_750 . V_1487 [ V_159 ] . V_1489 ) ) ;
if ( ! V_240 -> V_255 . V_256 )
continue;
V_1486 = F_328 ( V_240 -> V_255 . V_258 . V_1481 ) ;
F_326 ( V_1486 , V_750 . V_1487 [ V_159 ] . V_258 ) ;
}
if ( ! V_30 -> V_5 [ V_1490 ] )
goto V_599;
F_114 ( V_1491 > V_1469 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_289 V_290 = F_237 ( V_1485 ) ;
int V_35 ;
if ( V_290 < 0 || V_290 >= V_362 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_290 ] ;
if ( V_240 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1483 , F_23 ( V_1485 ) ,
F_24 ( V_1485 ) , V_1492 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1493 ] ) {
V_750 . V_1487 [ V_290 ] . V_1488 = F_323 (
V_240 ,
F_23 ( V_95 [ V_1493 ] ) ,
F_24 ( V_95 [ V_1493 ] ) ) ;
if ( ( V_750 . V_1487 [ V_290 ] . V_1488 == 0 ) &&
F_24 ( V_95 [ V_1493 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1494 ] ) {
if ( ! F_324 (
V_240 ,
F_23 ( V_95 [ V_1494 ] ) ,
F_24 ( V_95 [ V_1494 ] ) ,
V_750 . V_1487 [ V_290 ] . V_1489 ) )
return - V_16 ;
}
if ( V_95 [ V_1495 ] ) {
if ( ! F_327 (
V_240 ,
F_23 ( V_95 [ V_1495 ] ) ,
V_750 . V_1487 [ V_290 ] . V_258 ) )
return - V_16 ;
}
if ( V_95 [ V_1496 ] ) {
V_750 . V_1487 [ V_290 ] . V_1497 =
F_34 ( V_95 [ V_1496 ] ) ;
if ( V_750 . V_1487 [ V_290 ] . V_1497 > V_1498 )
return - V_16 ;
}
if ( V_750 . V_1487 [ V_290 ] . V_1488 == 0 ) {
if ( ! ( V_7 -> V_18 . V_363 [ V_290 ] -> V_245 . V_246 ||
V_7 -> V_18 . V_363 [ V_290 ] -> V_255 . V_256 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_1469 ; V_159 ++ )
if ( V_750 . V_1487 [ V_290 ] . V_1489 [ V_159 ] )
goto V_599;
for ( V_159 = 0 ; V_159 < V_1479 ; V_159 ++ )
if ( V_750 . V_1487 [ V_290 ] . V_258 [ V_159 ] )
goto V_599;
return - V_16 ;
}
}
V_599:
return F_330 ( V_7 , V_539 , NULL , & V_750 ) ;
}
static int F_331 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
T_3 V_1499 = V_277 | V_1500 ;
if ( ! V_30 -> V_5 [ V_1501 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_276 ] )
V_1499 = F_78 ( V_30 -> V_5 [ V_276 ] ) ;
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
return F_332 ( V_17 , V_30 -> V_504 , V_1499 ,
F_23 ( V_30 -> V_5 [ V_1501 ] ) ,
F_24 ( V_30 -> V_5 [ V_1501 ] ) ) ;
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
struct V_1502 V_137 = {
. V_1503 =
V_30 -> V_5 [ V_1504 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1505 ] )
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
if ( V_30 -> V_5 [ V_1461 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1506 = F_4 ( V_30 -> V_5 [ V_1461 ] ) ;
if ( V_137 . V_1506 < V_1462 ||
V_137 . V_1506 > V_7 -> V_18 . V_454 )
return - V_16 ;
}
V_137 . V_1507 = V_30 -> V_5 [ V_456 ] ;
if ( V_137 . V_1507 && ! ( V_7 -> V_18 . V_51 & V_455 ) )
return - V_16 ;
V_137 . V_1200 = F_152 ( V_30 -> V_5 [ V_1201 ] ) ;
V_520 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_522 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_520 . V_55 && V_137 . V_1507 )
return - V_16 ;
V_137 . V_1508 = F_23 ( V_30 -> V_5 [ V_1505 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1505 ] ) ;
if ( V_30 -> V_5 [ V_1509 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1509 ] ) ;
int V_159 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1510 = V_47 / sizeof( T_3 ) ;
V_137 . V_1511 =
F_23 ( V_30 -> V_5 [ V_1509 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1510 ; V_159 ++ ) {
if ( V_137 . V_1511 [ V_159 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1503 ) {
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1512 ) ;
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
if ( F_104 ( V_53 , V_1464 , V_647 ) )
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
if ( ! V_30 -> V_5 [ V_1464 ] )
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
V_647 = F_5 ( V_30 -> V_5 [ V_1464 ] ) ;
return F_336 ( V_7 , V_17 , V_647 ) ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 V_1513 ;
bool V_282 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1514 ] )
return - V_16 ;
V_1513 = F_4 ( V_30 -> V_5 [ V_1514 ] ) ;
if ( V_1513 != V_1515 && V_1513 != V_1516 )
return - V_16 ;
V_17 = V_539 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1517 )
return - V_540 ;
V_282 = ( V_1513 == V_1516 ) ? true : false ;
if ( V_282 == V_17 -> V_1518 )
return 0 ;
V_35 = F_338 ( V_7 , V_539 , V_282 , V_17 -> V_1519 ) ;
if ( ! V_35 )
V_17 -> V_1518 = V_282 ;
return V_35 ;
}
static int F_339 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
enum V_1520 V_1513 ;
struct V_1 * V_17 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_31 * V_53 ;
void * V_283 ;
int V_35 ;
V_17 = V_539 -> V_28 ;
if ( ! V_7 -> V_351 -> V_1517 )
return - V_540 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1521 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_657;
}
if ( V_17 -> V_1518 )
V_1513 = V_1516 ;
else
V_1513 = V_1515 ;
if ( F_28 ( V_53 , V_1514 , V_1513 ) )
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
V_22 V_244 , V_22 V_1522 , V_22 V_1523 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
if ( V_244 > 100 || V_1523 > V_1524 )
return - V_16 ;
if ( ! V_7 -> V_351 -> V_1525 )
return - V_540 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_540 ;
return F_341 ( V_7 , V_539 , V_244 , V_1522 , V_1523 ) ;
}
static int F_342 ( struct V_29 * V_30 ,
T_12 V_1526 , V_22 V_1527 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
if ( V_1526 > 0 )
return - V_16 ;
if ( V_1526 == 0 )
V_1527 = 0 ;
if ( ! V_7 -> V_351 -> V_1528 )
return - V_540 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_540 ;
return F_343 ( V_7 , V_539 , V_1526 , V_1527 ) ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1529 + 1 ] ;
struct V_4 * V_1530 ;
int V_35 ;
V_1530 = V_30 -> V_5 [ V_1531 ] ;
if ( ! V_1530 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1529 , V_1530 ,
V_1532 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1533 ] &&
V_5 [ V_1534 ] ) {
T_12 V_1526 = V_1097 ( V_5 [ V_1533 ] ) ;
V_22 V_1527 = F_4 ( V_5 [ V_1534 ] ) ;
return F_342 ( V_30 , V_1526 , V_1527 ) ;
}
if ( V_5 [ V_1535 ] &&
V_5 [ V_1536 ] &&
V_5 [ V_1537 ] ) {
V_22 V_244 = F_4 ( V_5 [ V_1535 ] ) ;
V_22 V_1522 = F_4 ( V_5 [ V_1536 ] ) ;
V_22 V_1523 = F_4 ( V_5 [ V_1537 ] ) ;
return F_340 ( V_30 , V_244 , V_1522 , V_1523 ) ;
}
return - V_16 ;
}
static int F_345 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1538 V_1100 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1100 . V_520 ) ;
if ( V_35 )
return V_35 ;
return F_346 ( V_7 , V_539 , & V_1100 ) ;
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
struct V_1031 V_1093 ;
struct V_1099 V_1100 ;
int V_35 ;
memcpy ( & V_1093 , & V_1035 , sizeof( V_1093 ) ) ;
memcpy ( & V_1100 , & V_1539 , sizeof( V_1100 ) ) ;
if ( V_30 -> V_5 [ V_1037 ] ) {
V_35 = F_208 ( V_30 , & V_1093 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_617 ] ||
! F_24 ( V_30 -> V_5 [ V_617 ] ) )
return - V_16 ;
V_1100 . V_1540 = F_23 ( V_30 -> V_5 [ V_617 ] ) ;
V_1100 . V_1034 = F_24 ( V_30 -> V_5 [ V_617 ] ) ;
if ( V_30 -> V_5 [ V_1401 ] &&
! F_285 ( V_7 , V_1100 . V_1388 ,
F_4 ( V_30 -> V_5 [ V_1401 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_709 ] ) {
V_1100 . V_541 =
F_4 ( V_30 -> V_5 [ V_709 ] ) ;
if ( V_1100 . V_541 < 10 ||
V_1100 . V_541 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_710 ] ) {
V_1100 . V_712 =
F_4 ( V_30 -> V_5 [ V_710 ] ) ;
if ( V_1100 . V_712 < 1 || V_1100 . V_712 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1102 ] ) {
V_35 = F_210 ( V_30 , & V_1100 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1100 . V_1122 )
V_1093 . V_1053 = false ;
if ( V_30 -> V_5 [ V_522 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1100 . V_520 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1100 . V_520 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_1015 ] ) {
T_2 * V_1193 = F_23 ( V_30 -> V_5 [ V_1015 ] ) ;
int V_1400 =
F_24 ( V_30 -> V_5 [ V_1015 ] ) ;
struct V_239 * V_240 ;
if ( ! V_1100 . V_520 . V_55 )
return - V_16 ;
V_240 = V_7 -> V_18 . V_363 [ V_1100 . V_520 . V_55 -> V_290 ] ;
V_35 = F_238 ( V_240 , V_1193 , V_1400 ,
& V_1100 . V_1016 ) ;
if ( V_35 )
return V_35 ;
}
return F_350 ( V_7 , V_539 , & V_1100 , & V_1093 ) ;
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
struct V_1541 * V_189 = V_7 -> V_18 . V_1542 ;
struct V_4 * V_1543 , * V_1544 ;
int V_159 , V_1545 ;
if ( ! V_189 -> V_219 )
return 0 ;
V_1543 = F_47 ( V_53 , V_228 ) ;
if ( ! V_1543 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_189 -> V_219 ; V_159 ++ ) {
V_1544 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1544 )
return - V_91 ;
V_1545 = V_189 -> V_1546 [ V_159 ] . V_1547 ;
if ( F_51 ( V_53 , V_1548 , F_245 ( V_1545 , 8 ) ,
V_189 -> V_1546 [ V_159 ] . V_750 ) ||
F_51 ( V_53 , V_1549 , V_1545 ,
V_189 -> V_1546 [ V_159 ] . V_1550 ) ||
F_28 ( V_53 , V_1551 ,
V_189 -> V_1546 [ V_159 ] . V_1552 ) )
return - V_91 ;
F_48 ( V_53 , V_1544 ) ;
}
F_48 ( V_53 , V_1543 ) ;
return 0 ;
}
static int F_354 ( struct V_31 * V_53 ,
struct V_1553 * V_188 )
{
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_355 ( V_53 , V_1554 , V_188 -> V_1555 ) ||
F_355 ( V_53 , V_1556 , V_188 -> V_970 ) ||
F_51 ( V_53 , V_1557 , V_587 , V_188 -> V_1558 ) ||
F_55 ( V_53 , V_1559 , V_188 -> V_1560 ) ||
F_55 ( V_53 , V_1561 , V_188 -> V_1562 ) ||
F_51 ( V_53 , V_192 ,
V_188 -> V_1563 , V_188 -> V_1564 ) ||
F_28 ( V_53 , V_197 ,
V_188 -> V_1565 ) ||
F_51 ( V_53 , V_199 ,
V_188 -> V_1566 , V_188 -> V_1567 ) ||
F_51 ( V_53 , V_1568 ,
F_245 ( V_188 -> V_1566 , 8 ) , V_188 -> V_1569 ) )
return - V_91 ;
if ( V_188 -> V_1570 . V_47 &&
F_51 ( V_53 , V_194 ,
sizeof( V_188 -> V_1570 ) , & V_188 -> V_1570 ) )
return - V_91 ;
if ( V_188 -> V_1571 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_188 -> V_1571 ) + V_188 -> V_1572 ,
& V_188 -> V_1571 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_356 ( struct V_31 * V_53 ,
struct V_1206 * V_1368 )
{
struct V_4 * V_1573 , * V_1175 , * V_1574 , * V_1575 , * V_1210 , * V_1576 ;
int V_159 ;
if ( ! V_1368 )
return 0 ;
V_1573 = F_47 ( V_53 , V_230 ) ;
if ( ! V_1573 )
return - V_91 ;
if ( V_1368 -> V_1228 == 1 &&
F_28 ( V_53 , V_1209 ,
V_1368 -> V_1210 [ 0 ] . V_1208 * 1000 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1235 , V_1368 -> V_1236 ) )
return - V_91 ;
V_1175 = F_47 ( V_53 , V_1189 ) ;
if ( ! V_1175 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1368 -> V_366 ; V_159 ++ )
F_28 ( V_53 , V_159 , V_1368 -> V_367 [ V_159 ] -> V_60 ) ;
F_48 ( V_53 , V_1175 ) ;
if ( V_1368 -> V_1218 ) {
V_1574 = F_47 ( V_53 , V_1222 ) ;
for ( V_159 = 0 ; V_159 < V_1368 -> V_1218 ; V_159 ++ ) {
V_1575 = F_47 ( V_53 , V_159 ) ;
F_51 ( V_53 , V_1225 ,
V_1368 -> V_1227 [ V_159 ] . V_594 . V_592 ,
V_1368 -> V_1227 [ V_159 ] . V_594 . V_594 ) ;
F_48 ( V_53 , V_1575 ) ;
}
F_48 ( V_53 , V_1574 ) ;
}
V_1210 = F_47 ( V_53 , V_1207 ) ;
if ( ! V_1210 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_1368 -> V_1228 ; V_159 ++ ) {
V_1576 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1576 ||
F_28 ( V_53 , V_1215 ,
V_1368 -> V_1210 [ V_159 ] . V_1208 ) ||
( V_1368 -> V_1210 [ V_159 ] . V_1217 &&
F_28 ( V_53 , V_1216 ,
V_1368 -> V_1210 [ V_159 ] . V_1217 ) ) )
return - V_91 ;
F_48 ( V_53 , V_1576 ) ;
}
F_48 ( V_53 , V_1210 ) ;
F_48 ( V_53 , V_1573 ) ;
return 0 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1577 = V_600 ;
if ( ! V_7 -> V_18 . V_189 )
return - V_540 ;
if ( V_7 -> V_18 . V_1542 && V_7 -> V_18 . V_1542 -> V_188 ) {
V_1577 += V_7 -> V_18 . V_1542 -> V_188 -> V_1572 +
V_7 -> V_18 . V_1542 -> V_188 -> V_1563 +
V_7 -> V_18 . V_1542 -> V_188 -> V_1566 +
V_7 -> V_18 . V_1542 -> V_188 -> V_1566 / 8 ;
}
V_53 = F_74 ( V_1577 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , V_30 -> V_504 , V_30 -> V_505 , 0 ,
V_1578 ) ;
if ( ! V_283 )
goto V_61;
if ( V_7 -> V_18 . V_1542 ) {
struct V_4 * V_201 ;
V_201 = F_47 ( V_53 , V_1579 ) ;
if ( ! V_201 )
goto V_61;
if ( ( V_7 -> V_18 . V_1542 -> V_1580 &&
F_29 ( V_53 , V_204 ) ) ||
( V_7 -> V_18 . V_1542 -> V_451 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1542 -> V_1581 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1542 -> V_1582 &&
F_29 ( V_53 , V_212 ) ) ||
( V_7 -> V_18 . V_1542 -> V_1583 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1542 -> V_1584 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1542 -> V_1585 &&
F_29 ( V_53 , V_218 ) ) )
goto V_61;
if ( F_353 ( V_53 , V_7 ) )
goto V_61;
if ( F_354 ( V_53 ,
V_7 -> V_18 . V_1542 -> V_188 ) )
goto V_61;
if ( F_356 (
V_53 ,
V_7 -> V_18 . V_1542 -> V_1586 ) )
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
struct V_1541 * V_1587 )
{
struct V_4 * V_95 [ V_1588 ] ;
struct V_1553 * V_1093 ;
struct V_1589 * V_195 = NULL ;
struct V_1590 * V_50 = NULL ;
V_22 V_1577 ;
V_22 V_1591 , V_1592 , V_1572 = 0 , V_1593 ;
int V_35 , V_1594 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1595 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1596 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1554 ] ||
! V_95 [ V_1556 ] ||
! V_95 [ V_1557 ] ||
! V_95 [ V_1561 ] ||
! V_95 [ V_192 ] ||
! V_95 [ V_197 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_1568 ] )
return - V_16 ;
V_1591 = F_24 ( V_95 [ V_192 ] ) ;
if ( V_1591 > V_7 -> V_18 . V_189 -> V_188 -> V_193 )
return - V_16 ;
if ( F_4 ( V_95 [ V_197 ] ) >
V_7 -> V_18 . V_189 -> V_188 -> V_198 ||
F_4 ( V_95 [ V_197 ] ) == 0 )
return - V_16 ;
V_1592 = F_24 ( V_95 [ V_199 ] ) ;
if ( V_1592 > V_7 -> V_18 . V_189 -> V_188 -> V_200 )
return - V_16 ;
V_1593 = F_24 ( V_95 [ V_1568 ] ) ;
if ( V_1593 != F_245 ( V_1592 , 8 ) )
return - V_16 ;
if ( V_95 [ V_196 ] ) {
V_22 V_1597 = F_24 ( V_95 [ V_196 ] ) ;
V_195 = F_23 ( V_95 [ V_196 ] ) ;
V_1572 = V_1597 - sizeof( * V_195 ) ;
if ( ! V_195 -> V_47 || V_1572 % V_195 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_195 )
return - V_16 ;
if ( V_195 -> V_47 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1598 )
return - V_16 ;
if ( V_195 -> V_47 < V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1599 )
return - V_16 ;
if ( V_1572 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1600 )
return - V_16 ;
if ( V_195 -> V_1260 + V_195 -> V_47 > V_1591 )
return - V_16 ;
}
if ( V_95 [ V_194 ] ) {
V_50 = F_23 ( V_95 [ V_194 ] ) ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1260 > V_1591 )
return - V_16 ;
}
V_1577 = sizeof( * V_1093 ) ;
V_1577 += V_1591 ;
V_1577 += V_1592 + V_1593 ;
V_1577 += V_1572 ;
V_1093 = F_38 ( V_1577 , V_135 ) ;
if ( ! V_1093 )
return - V_136 ;
V_1093 -> V_1555 = F_359 ( V_95 [ V_1554 ] ) ;
V_1093 -> V_970 = F_359 ( V_95 [ V_1556 ] ) ;
memcpy ( V_1093 -> V_1558 , F_23 ( V_95 [ V_1557 ] ) ,
V_587 ) ;
if ( V_95 [ V_1559 ] )
V_1594 = F_78 ( V_95 [ V_1559 ] ) ;
else
V_1594 = 0 ;
#ifdef F_360
V_35 = F_361 ( F_7 ( & V_7 -> V_18 ) , V_1601 , V_1602 ,
V_1603 , & V_1093 -> V_1604 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1093 ) ;
return V_35 ;
}
if ( F_362 ( V_1093 -> V_1604 -> V_44 , V_1594 ) ) {
F_363 ( V_1093 -> V_1604 ) ;
F_41 ( V_1093 ) ;
return - V_1605 ;
}
V_1093 -> V_1560 = F_364 ( V_1093 -> V_1604 -> V_44 ) -> V_1606 ;
#else
if ( ! V_1594 ) {
F_41 ( V_1093 ) ;
return - V_16 ;
}
V_1093 -> V_1560 = V_1594 ;
#endif
V_1093 -> V_1562 = F_78 ( V_95 [ V_1561 ] ) ;
V_1093 -> V_1563 = V_1591 ;
V_1093 -> V_1564 = ( T_2 * ) V_1093 + sizeof( * V_1093 ) + V_1572 ;
memcpy ( ( void * ) V_1093 -> V_1564 ,
F_23 ( V_95 [ V_192 ] ) ,
V_1591 ) ;
if ( V_50 )
V_1093 -> V_1570 = * V_50 ;
V_1093 -> V_1565 = F_4 ( V_95 [ V_197 ] ) ;
V_1093 -> V_1566 = V_1592 ;
V_1093 -> V_1567 = ( T_2 * ) V_1093 + sizeof( * V_1093 ) + V_1572 + V_1591 ;
memcpy ( ( void * ) V_1093 -> V_1567 ,
F_23 ( V_95 [ V_199 ] ) ,
V_1592 ) ;
V_1093 -> V_1569 = ( T_2 * ) V_1093 + sizeof( * V_1093 ) + V_1572 +
V_1591 + V_1592 ;
memcpy ( ( void * ) V_1093 -> V_1569 ,
F_23 ( V_95 [ V_1568 ] ) ,
V_1593 ) ;
if ( V_195 ) {
V_1093 -> V_1572 = V_1572 ;
memcpy ( & V_1093 -> V_1571 , V_195 , sizeof( * V_195 ) + V_1572 ) ;
}
V_1587 -> V_188 = V_1093 ;
return 0 ;
}
static int F_365 ( struct V_6 * V_7 ,
const struct V_1607 * V_189 ,
struct V_4 * V_45 ,
struct V_1541 * V_1587 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_38 ( V_1608 * sizeof( * V_95 ) , V_135 ) ;
if ( ! V_95 )
return - V_136 ;
if ( ! ( V_189 -> V_51 & V_229 ) ) {
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_96 ( V_95 , V_1247 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_599;
V_1587 -> V_1586 = F_246 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_248 ( V_1587 -> V_1586 ) ;
if ( V_35 )
V_1587 -> V_1586 = NULL ;
V_599:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_366 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_4 * V_95 [ V_1609 ] ;
struct V_1541 V_1610 = {} ;
struct V_1541 * V_1611 ;
const struct V_1607 * V_189 = V_7 -> V_18 . V_189 ;
int V_35 , V_159 ;
bool V_1612 = V_7 -> V_18 . V_1542 ;
bool V_1613 = false ;
if ( ! V_189 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1579 ] ) {
F_367 ( V_7 ) ;
V_7 -> V_18 . V_1542 = NULL ;
goto V_1614;
}
V_35 = F_96 ( V_95 , V_1615 ,
F_23 ( V_30 -> V_5 [ V_1579 ] ) ,
F_24 ( V_30 -> V_5 [ V_1579 ] ) ,
V_1616 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_204 ] ) {
if ( ! ( V_189 -> V_51 & V_203 ) )
return - V_16 ;
V_1610 . V_1580 = true ;
}
if ( V_95 [ V_206 ] ) {
if ( ! ( V_189 -> V_51 & V_205 ) )
return - V_16 ;
V_1610 . V_451 = true ;
V_1613 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_189 -> V_51 & V_207 ) )
return - V_16 ;
V_1610 . V_1581 = true ;
V_1613 = true ;
}
if ( V_95 [ V_210 ] )
return - V_16 ;
if ( V_95 [ V_212 ] ) {
if ( ! ( V_189 -> V_51 & V_211 ) )
return - V_16 ;
V_1610 . V_1582 = true ;
V_1613 = true ;
}
if ( V_95 [ V_214 ] ) {
if ( ! ( V_189 -> V_51 & V_213 ) )
return - V_16 ;
V_1610 . V_1583 = true ;
V_1613 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_189 -> V_51 & V_215 ) )
return - V_16 ;
V_1610 . V_1584 = true ;
V_1613 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_189 -> V_51 & V_217 ) )
return - V_16 ;
V_1610 . V_1585 = true ;
V_1613 = true ;
}
if ( V_95 [ V_228 ] ) {
struct V_4 * V_221 ;
int V_219 = 0 ;
int V_134 , V_1545 , V_1617 , V_1552 ;
struct V_4 * V_1618 [ V_1619 ] ;
V_1613 = true ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_189 -> V_219 )
return - V_16 ;
V_1610 . V_1546 = F_368 ( V_219 ,
sizeof( V_1610 . V_1546 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1610 . V_1546 )
return - V_136 ;
V_1610 . V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1620 ;
F_96 ( V_1618 , V_1621 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1618 [ V_1548 ] ||
! V_1618 [ V_1549 ] )
goto error;
V_1545 = F_24 ( V_1618 [ V_1549 ] ) ;
V_1617 = F_245 ( V_1545 , 8 ) ;
if ( F_24 ( V_1618 [ V_1548 ] ) != V_1617 )
goto error;
if ( V_1545 > V_189 -> V_226 ||
V_1545 < V_189 -> V_224 )
goto error;
if ( ! V_1618 [ V_1551 ] )
V_1552 = 0 ;
else
V_1552 = F_4 (
V_1618 [ V_1551 ] ) ;
if ( V_1552 > V_189 -> V_227 )
goto error;
V_1610 . V_1546 [ V_159 ] . V_1552 = V_1552 ;
V_1620 = F_369 ( V_1617 + V_1545 , V_135 ) ;
if ( ! V_1620 ) {
V_35 = - V_136 ;
goto error;
}
V_1610 . V_1546 [ V_159 ] . V_750 = V_1620 ;
memcpy ( V_1620 , F_23 ( V_1618 [ V_1548 ] ) ,
V_1617 ) ;
V_1620 += V_1617 ;
V_1610 . V_1546 [ V_159 ] . V_1550 = V_1620 ;
V_1610 . V_1546 [ V_159 ] . V_1547 = V_1545 ;
memcpy ( V_1620 ,
F_23 ( V_1618 [ V_1549 ] ) ,
V_1545 ) ;
V_159 ++ ;
}
}
if ( V_95 [ V_191 ] ) {
V_1613 = true ;
V_35 = F_358 (
V_7 , V_95 [ V_191 ] ,
& V_1610 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_230 ] ) {
V_1613 = true ;
V_35 = F_365 (
V_7 , V_189 , V_95 [ V_230 ] ,
& V_1610 ) ;
if ( V_35 )
goto error;
}
if ( V_1610 . V_1580 && V_1613 ) {
V_35 = - V_16 ;
goto error;
}
V_1611 = F_370 ( & V_1610 , sizeof( V_1610 ) , V_135 ) ;
if ( ! V_1611 ) {
V_35 = - V_136 ;
goto error;
}
F_367 ( V_7 ) ;
V_7 -> V_18 . V_1542 = V_1611 ;
V_1614:
if ( V_7 -> V_351 -> V_1614 &&
V_1612 != ! ! V_7 -> V_18 . V_1542 )
F_371 ( V_7 , V_7 -> V_18 . V_1542 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1610 . V_219 ; V_159 ++ )
F_41 ( V_1610 . V_1546 [ V_159 ] . V_750 ) ;
F_41 ( V_1610 . V_1546 ) ;
if ( V_1610 . V_188 && V_1610 . V_188 -> V_1604 )
F_363 ( V_1610 . V_188 -> V_1604 ) ;
F_41 ( V_1610 . V_188 ) ;
F_41 ( V_1610 . V_1586 ) ;
return V_35 ;
}
static int F_372 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1543 , * V_1544 , * V_1622 , * V_1623 ;
int V_159 , V_161 , V_1545 ;
struct V_1624 * V_233 ;
if ( ! V_7 -> V_234 -> V_236 )
return 0 ;
V_1623 = F_47 ( V_53 , V_238 ) ;
if ( ! V_1623 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_234 -> V_236 ; V_159 ++ ) {
V_1622 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1622 )
return - V_91 ;
V_233 = & V_7 -> V_234 -> V_1625 [ V_159 ] ;
if ( F_28 ( V_53 , V_1626 ,
V_233 -> V_1236 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1627 ,
V_233 -> V_1628 ) )
return - V_91 ;
V_1543 = F_47 ( V_53 ,
V_1629 ) ;
if ( ! V_1543 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ ) {
V_1544 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1544 )
return - V_91 ;
V_1545 = V_233 -> V_1546 [ V_161 ] . V_1547 ;
if ( F_51 ( V_53 , V_1548 ,
F_245 ( V_1545 , 8 ) ,
V_233 -> V_1546 [ V_161 ] . V_750 ) ||
F_51 ( V_53 , V_1549 , V_1545 ,
V_233 -> V_1546 [ V_161 ] . V_1550 ) ||
F_28 ( V_53 , V_1551 ,
V_233 -> V_1546 [ V_161 ] . V_1552 ) )
return - V_91 ;
F_48 ( V_53 , V_1544 ) ;
}
F_48 ( V_53 , V_1543 ) ;
F_48 ( V_53 , V_1622 ) ;
}
F_48 ( V_53 , V_1623 ) ;
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
V_1630 ) ;
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
struct V_1631 * V_234 = V_7 -> V_234 ;
int V_159 , V_161 ;
struct V_1624 * V_233 ;
if ( ! V_234 )
return;
for ( V_159 = 0 ; V_159 < V_234 -> V_236 ; V_159 ++ ) {
V_233 = & V_234 -> V_1625 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_233 -> V_219 ; V_161 ++ )
F_41 ( V_233 -> V_1546 [ V_161 ] . V_750 ) ;
F_41 ( V_233 -> V_1546 ) ;
}
F_41 ( V_234 -> V_1625 ) ;
F_41 ( V_234 ) ;
V_7 -> V_234 = NULL ;
}
static int F_375 ( struct V_6 * V_7 ,
struct V_4 * V_233 ,
struct V_1624 * V_1632 )
{
int V_35 , V_159 ;
const struct V_1633 * V_234 = V_7 -> V_18 . V_234 ;
struct V_4 * V_95 [ V_1634 ] , * V_221 ;
int V_134 , V_1545 , V_1617 , V_1552 , V_219 = 0 ;
struct V_4 * V_1618 [ V_1619 ] ;
V_35 = F_96 ( V_95 , V_1635 , F_23 ( V_233 ) ,
F_24 ( V_233 ) , V_1636 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1626 ] )
V_1632 -> V_1236 =
F_4 ( V_95 [ V_1626 ] ) ;
if ( V_1632 -> V_1236 > V_234 -> V_237 )
return - V_16 ;
if ( V_95 [ V_1627 ] )
V_1632 -> V_1628 =
F_4 ( V_95 [ V_1627 ] ) ;
if ( V_1632 -> V_1628 != V_1637 &&
V_1632 -> V_1628 != V_1638 )
return - V_16 ;
if ( ! V_95 [ V_1629 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_234 -> V_219 )
return - V_16 ;
V_1632 -> V_1546 = F_368 ( V_219 , sizeof( V_1632 -> V_1546 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1632 -> V_1546 )
return - V_136 ;
V_1632 -> V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1620 ;
F_96 ( V_1618 , V_1621 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
if ( ! V_1618 [ V_1548 ] ||
! V_1618 [ V_1549 ] )
return - V_16 ;
V_1545 = F_24 ( V_1618 [ V_1549 ] ) ;
V_1617 = F_245 ( V_1545 , 8 ) ;
if ( F_24 ( V_1618 [ V_1548 ] ) != V_1617 )
return - V_16 ;
if ( V_1545 > V_234 -> V_226 ||
V_1545 < V_234 -> V_224 )
return - V_16 ;
if ( ! V_1618 [ V_1551 ] )
V_1552 = 0 ;
else
V_1552 = F_4 ( V_1618 [ V_1551 ] ) ;
if ( V_1552 > V_234 -> V_227 )
return - V_16 ;
V_1632 -> V_1546 [ V_159 ] . V_1552 = V_1552 ;
V_1620 = F_369 ( V_1617 + V_1545 , V_135 ) ;
if ( ! V_1620 )
return - V_136 ;
V_1632 -> V_1546 [ V_159 ] . V_750 = V_1620 ;
memcpy ( V_1620 , F_23 ( V_1618 [ V_1548 ] ) ,
V_1617 ) ;
V_1620 += V_1617 ;
V_1632 -> V_1546 [ V_159 ] . V_1550 = V_1620 ;
V_1632 -> V_1546 [ V_159 ] . V_1547 = V_1545 ;
memcpy ( V_1620 , F_23 ( V_1618 [ V_1549 ] ) ,
V_1545 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_376 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
const struct V_1633 * V_234 = V_7 -> V_18 . V_234 ;
struct V_1631 V_1639 = {} ;
struct V_1631 * V_1640 ;
int V_35 , V_1641 , V_236 = 0 , V_159 , V_161 ;
struct V_4 * V_233 ;
struct V_1624 * V_1642 ;
if ( ! V_7 -> V_18 . V_234 || ! V_7 -> V_351 -> V_1643 )
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
V_1639 . V_1625 = F_368 ( V_236 , sizeof( V_1639 . V_1625 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1639 . V_1625 )
return - V_136 ;
V_1639 . V_236 = V_236 ;
V_159 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_375 ( V_7 , V_233 ,
& V_1639 . V_1625 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = F_377 ( V_7 , & V_1639 ) ;
if ( V_35 )
goto error;
V_1640 = F_370 ( & V_1639 , sizeof( V_1639 ) , V_135 ) ;
if ( ! V_1640 ) {
V_35 = - V_136 ;
goto error;
}
F_374 ( V_7 ) ;
V_7 -> V_234 = V_1640 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1639 . V_236 ; V_159 ++ ) {
V_1642 = & V_1639 . V_1625 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1642 -> V_219 ; V_161 ++ )
F_41 ( V_1642 -> V_1546 [ V_161 ] . V_750 ) ;
F_41 ( V_1642 -> V_1546 ) ;
}
F_41 ( V_1639 . V_1625 ) ;
return V_35 ;
}
static int F_378 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_4 * V_95 [ V_1644 ] ;
struct V_1645 V_1646 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1647 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1648 ,
F_23 ( V_30 -> V_5 [ V_1647 ] ) ,
F_24 ( V_30 -> V_5 [ V_1647 ] ) ,
V_1649 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1650 ] ) != V_1651 )
return - V_1652 ;
if ( F_24 ( V_95 [ V_1653 ] ) != V_1654 )
return - V_1652 ;
if ( F_24 ( V_95 [ V_1655 ] ) != V_1656 )
return - V_1652 ;
V_1646 . V_1657 = F_23 ( V_95 [ V_1653 ] ) ;
V_1646 . V_1658 = F_23 ( V_95 [ V_1655 ] ) ;
V_1646 . V_1659 = F_23 ( V_95 [ V_1650 ] ) ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1250 ;
goto V_599;
}
if ( ! V_7 -> V_351 -> V_1660 ) {
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_379 ( V_7 , V_539 , & V_1646 ) ;
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
if ( V_17 -> V_1661 )
return - V_544 ;
V_17 -> V_1661 = V_30 -> V_504 ;
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
V_1662 ) ;
if ( ! V_283 ) {
V_35 = - V_91 ;
goto V_657;
}
V_677 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_35 = F_382 ( V_7 , V_539 , V_677 , & V_647 ) ;
if ( V_35 )
goto V_657;
if ( F_104 ( V_53 , V_1464 , V_647 ) )
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
struct V_1663 * V_1664 , * V_1665 ;
int V_1666 ;
if ( ! ( V_7 -> V_18 . V_51 & V_429 ) )
return - V_540 ;
V_1665 = F_38 ( sizeof( * V_1665 ) , V_135 ) ;
if ( ! V_1665 )
return - V_136 ;
F_267 ( & V_7 -> V_1667 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1664 -> V_1668 == V_30 -> V_504 ) {
V_1666 = - V_708 ;
goto V_884;
}
}
V_1665 -> V_1668 = V_30 -> V_504 ;
F_384 ( & V_1665 -> V_638 , & V_7 -> V_1669 ) ;
F_269 ( & V_7 -> V_1667 ) ;
return 0 ;
V_884:
F_269 ( & V_7 -> V_1667 ) ;
F_41 ( V_1665 ) ;
return V_1666 ;
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
if ( V_17 -> V_1670 )
return 0 ;
if ( F_386 ( V_7 -> V_1671 ) )
return - V_1672 ;
V_35 = F_387 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1670 = true ;
V_7 -> V_1673 ++ ;
return 0 ;
}
static int F_388 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_540 ;
if ( ! V_7 -> V_351 -> V_1674 )
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
V_1675 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_1676 ,
V_1677 ) )
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
struct V_1678 V_1679 ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_1680 )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1681 ] ||
! F_22 ( V_30 -> V_5 [ V_683 ] ) )
return - V_16 ;
memset ( & V_1679 , 0 , sizeof( V_1679 ) ) ;
V_1679 . V_1682 = F_78 ( V_30 -> V_5 [ V_1681 ] ) ;
V_1679 . V_1118 = F_23 ( V_30 -> V_5 [ V_683 ] ) ;
V_1679 . V_1119 = F_24 ( V_30 -> V_5 [ V_683 ] ) ;
return F_392 ( V_7 , V_539 , & V_1679 ) ;
}
static int F_393 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
enum V_1683 V_1352 = V_1684 ;
T_3 V_1460 ;
int V_496 ;
if ( ! V_7 -> V_351 -> V_437 )
return - V_540 ;
if ( F_59 ( ! V_7 -> V_351 -> V_439 ) )
return - V_16 ;
if ( V_7 -> V_1685 )
return - V_544 ;
if ( V_30 -> V_5 [ V_1686 ] )
V_1352 = F_78 ( V_30 -> V_5 [ V_1686 ] ) ;
if ( V_1352 >= V_1687 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1688 ] )
return - V_16 ;
V_1460 =
F_78 ( V_30 -> V_5 [ V_1688 ] ) ;
if ( V_1460 > V_1689 )
return - V_1652 ;
V_496 = F_394 ( V_7 , V_17 , V_1352 , V_1460 ) ;
if ( ! V_496 )
V_7 -> V_1685 = V_30 -> V_504 ;
return V_496 ;
}
static int F_395 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( ! V_7 -> V_351 -> V_439 )
return - V_540 ;
if ( V_7 -> V_1685 ) {
V_7 -> V_1685 = 0 ;
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
V_22 V_1690 , V_1412 ;
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
if ( ! V_30 -> V_5 [ V_1409 ] ||
! V_30 -> V_5 [ V_1411 ] )
return - V_16 ;
V_1690 = F_4 ( V_30 -> V_5 [ V_1409 ] ) ;
V_1412 = F_4 ( V_30 -> V_5 [ V_1411 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1691 * V_1692 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1692 = & V_7 -> V_18 . V_484 [ V_159 ] ;
if ( V_1692 -> V_30 . V_1410 != V_1690 || V_1692 -> V_30 . V_1412 != V_1412 )
continue;
if ( V_1692 -> V_51 & ( V_1693 |
V_1694 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1692 -> V_51 & V_1694 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1692 -> V_51 & V_1695 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_554 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1670 )
return - V_554 ;
}
if ( ! V_1692 -> V_1696 )
return - V_540 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_483 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_483 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_483 ] ) ;
}
V_7 -> V_1421 = V_30 ;
V_35 = V_7 -> V_18 . V_484 [ V_159 ] . V_1696 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1421 = NULL ;
return V_35 ;
}
return - V_540 ;
}
static int F_398 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
V_22 V_1690 , V_1412 ;
unsigned int V_159 ;
int V_1697 = - 1 ;
int V_35 ;
void * V_138 = NULL ;
unsigned int V_1423 = 0 ;
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
if ( ! V_38 . V_40 [ V_1409 ] ||
! V_38 . V_40 [ V_1411 ] ) {
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
V_1690 = F_4 ( V_38 . V_40 [ V_1409 ] ) ;
V_1412 = F_4 ( V_38 . V_40 [ V_1411 ] ) ;
for ( V_159 = 0 ; V_159 < ( * V_7 ) -> V_18 . V_480 ; V_159 ++ ) {
const struct V_1691 * V_1692 ;
V_1692 = & ( * V_7 ) -> V_18 . V_484 [ V_159 ] ;
if ( V_1692 -> V_30 . V_1410 != V_1690 || V_1692 -> V_30 . V_1412 != V_1412 )
continue;
if ( ! V_1692 -> V_1698 ) {
V_35 = - V_540 ;
goto V_43;
}
V_1697 = V_159 ;
break;
}
if ( V_1697 < 0 ) {
V_35 = - V_540 ;
goto V_43;
}
if ( V_38 . V_40 [ V_483 ] ) {
V_138 = F_23 ( V_38 . V_40 [ V_483 ] ) ;
V_1423 = F_24 ( V_38 . V_40 [ V_483 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1697 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_138 ;
V_34 -> args [ 4 ] = V_1423 ;
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
unsigned int V_1697 ;
const struct V_1691 * V_1692 ;
void * V_138 ;
int V_1423 ;
int V_35 ;
struct V_4 * V_1699 ;
V_35 = F_398 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
V_1697 = V_34 -> args [ 2 ] ;
V_138 = ( void * ) V_34 -> args [ 3 ] ;
V_1423 = V_34 -> args [ 4 ] ;
V_1692 = & V_7 -> V_18 . V_484 [ V_1697 ] ;
if ( V_1692 -> V_51 & ( V_1693 |
V_1694 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1692 -> V_51 & V_1694 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1692 -> V_51 & V_1695 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_554 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1670 )
return - V_554 ;
}
}
while ( 1 ) {
void * V_283 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_500 , V_501 ,
V_1415 ) ;
if ( ! V_283 )
break;
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ) ) ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_1699 = F_47 ( V_32 , V_483 ) ;
if ( ! V_1699 ) {
F_67 ( V_32 , V_283 ) ;
break;
}
V_35 = V_1692 -> V_1698 ( & V_7 -> V_18 , V_17 , V_32 , V_138 , V_1423 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_48 ( V_32 , V_1699 ) ;
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
enum V_765 V_45 ,
int V_1407 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1421 ) )
return NULL ;
return F_294 ( V_7 , NULL , V_1407 ,
V_7 -> V_1421 -> V_504 ,
V_7 -> V_1421 -> V_505 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_401 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_283 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1421 ) ) {
F_295 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_283 ) ;
return F_76 ( V_32 , V_7 -> V_1421 ) ;
}
static int F_402 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_1700 * V_1701 = NULL ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
T_2 * V_46 , V_47 , V_1702 , V_1703 , V_1704 ;
int V_496 ;
if ( ! V_7 -> V_351 -> V_444 )
return - V_540 ;
if ( V_30 -> V_5 [ V_1705 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1705 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1705 ] ) ;
if ( V_47 % 2 || V_47 < V_1706 ||
V_47 > V_1707 )
return - V_16 ;
V_1701 = F_38 ( sizeof( struct V_1700 ) , V_135 ) ;
if ( ! V_1701 )
return - V_136 ;
V_1702 = ( V_47 - V_1706 ) >> 1 ;
if ( V_1702 ) {
V_1703 = V_1702 *
sizeof( struct V_1708 ) ;
memcpy ( V_1701 -> V_1709 , V_46 , V_1703 ) ;
V_1701 -> V_1702 = V_1702 ;
for ( V_1704 = 0 ; V_1704 < V_1702 ; V_1704 ++ ) {
if ( V_1701 -> V_1709 [ V_1704 ] . V_1710 > 7 ) {
F_41 ( V_1701 ) ;
return - V_16 ;
}
}
V_46 += V_1703 ;
}
memcpy ( V_1701 -> V_1710 , V_46 , V_1706 ) ;
}
F_113 ( V_539 -> V_28 ) ;
V_496 = F_42 ( V_539 -> V_28 ) ;
if ( ! V_496 )
V_496 = F_403 ( V_7 , V_539 , V_1701 ) ;
F_115 ( V_539 -> V_28 ) ;
F_41 ( V_1701 ) ;
return V_496 ;
}
static int F_404 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
const T_2 * V_1450 ;
T_2 V_1711 , V_1710 ;
T_3 V_1712 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_291 & V_446 ) )
return - V_540 ;
if ( ! V_30 -> V_5 [ V_1713 ] || ! V_30 -> V_5 [ V_547 ] ||
! V_30 -> V_5 [ V_1714 ] )
return - V_16 ;
V_1711 = F_34 ( V_30 -> V_5 [ V_1713 ] ) ;
if ( V_1711 >= V_868 )
return - V_16 ;
V_1710 = F_34 ( V_30 -> V_5 [ V_1714 ] ) ;
if ( V_1710 >= V_1715 )
return - V_16 ;
if ( V_1711 >= V_1716 ) {
return - V_16 ;
}
V_1450 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
if ( V_30 -> V_5 [ V_1717 ] ) {
V_1712 =
F_78 ( V_30 -> V_5 [ V_1717 ] ) ;
if ( ! V_1712 )
return - V_16 ;
}
F_113 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1250 ;
goto V_599;
default:
V_35 = - V_540 ;
goto V_599;
}
V_35 = F_405 ( V_7 , V_539 , V_1711 , V_1450 , V_1710 , V_1712 ) ;
V_599:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_406 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_503 [ 0 ] ;
struct V_25 * V_539 = V_30 -> V_503 [ 1 ] ;
struct V_1 * V_17 = V_539 -> V_28 ;
const T_2 * V_1450 ;
T_2 V_1711 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1713 ] || ! V_30 -> V_5 [ V_547 ] )
return - V_16 ;
V_1711 = F_34 ( V_30 -> V_5 [ V_1713 ] ) ;
V_1450 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_407 ( V_7 , V_539 , V_1711 , V_1450 ) ;
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
T_2 V_1718 ;
int V_35 ;
if ( ! V_7 -> V_351 -> V_1719 ||
! ( V_7 -> V_18 . V_291 & V_1720 ) )
return - V_540 ;
switch ( V_539 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_540 ;
}
if ( ! V_30 -> V_5 [ V_547 ] ||
! V_30 -> V_5 [ V_1721 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_520 ) ;
if ( V_35 )
return V_35 ;
if ( V_520 . V_55 -> V_290 == V_1722 &&
V_520 . V_523 != V_524 &&
V_520 . V_523 != V_579 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_520 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( F_257 ( V_17 -> V_18 , & V_520 , V_17 -> V_141 ) )
return - V_16 ;
V_677 = F_23 ( V_30 -> V_5 [ V_547 ] ) ;
V_1718 = F_34 ( V_30 -> V_5 [ V_1721 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_409 ( V_7 , V_539 , V_677 , V_1718 , & V_520 ) ;
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
if ( ! V_7 -> V_351 -> V_1719 ||
! V_7 -> V_351 -> V_1723 ||
! ( V_7 -> V_18 . V_291 & V_1720 ) )
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
static int F_412 ( const struct V_1724 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_539 ;
bool V_1725 = V_351 -> V_1726 & V_1727 ;
if ( V_1725 )
F_14 () ;
if ( V_351 -> V_1726 & V_1728 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1725 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_503 [ 0 ] = V_7 ;
} else if ( V_351 -> V_1726 & V_1729 ||
V_351 -> V_1726 & V_1730 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1725 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_539 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_351 -> V_1726 & V_1729 ) {
if ( ! V_539 ) {
if ( V_1725 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_503 [ 1 ] = V_539 ;
} else {
V_30 -> V_503 [ 1 ] = V_17 ;
}
if ( V_539 ) {
if ( V_351 -> V_1726 & V_1731 &&
! F_91 ( V_539 ) ) {
if ( V_1725 )
F_20 () ;
return - V_554 ;
}
F_241 ( V_539 ) ;
} else if ( V_351 -> V_1726 & V_1731 ) {
if ( ! V_17 -> V_1670 ) {
if ( V_1725 )
F_20 () ;
return - V_554 ;
}
}
V_30 -> V_503 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_413 ( const struct V_1724 * V_351 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_503 [ 1 ] ) {
if ( V_351 -> V_1726 & V_1730 ) {
struct V_1 * V_17 = V_30 -> V_503 [ 1 ] ;
if ( V_17 -> V_19 )
F_173 ( V_17 -> V_19 ) ;
} else {
F_173 ( V_30 -> V_503 [ 1 ] ) ;
}
}
if ( V_351 -> V_1726 & V_1727 )
F_20 () ;
if ( V_351 -> V_1726 & V_1732 ) {
struct V_1733 * V_36 = F_414 ( V_32 ) ;
memset ( F_415 ( V_36 ) , 0 , F_416 ( V_36 ) ) ;
}
}
void F_417 ( struct V_6 * V_7 ,
enum V_280 V_52 )
{
struct V_31 * V_53 ;
struct V_281 V_282 = {} ;
F_59 ( V_52 != V_295 &&
V_52 != V_1734 ) ;
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
struct V_1182 * V_1368 = V_7 -> V_1186 ;
struct V_4 * V_1735 ;
int V_159 ;
if ( F_59 ( ! V_1368 ) )
return 0 ;
V_1735 = F_47 ( V_53 , V_1190 ) ;
if ( ! V_1735 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1368 -> V_1184 ; V_159 ++ ) {
if ( F_51 ( V_53 , V_159 , V_1368 -> V_1191 [ V_159 ] . V_592 , V_1368 -> V_1191 [ V_159 ] . V_594 ) )
goto V_61;
}
F_48 ( V_53 , V_1735 ) ;
V_1735 = F_47 ( V_53 , V_1189 ) ;
if ( ! V_1735 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1368 -> V_366 ; V_159 ++ ) {
if ( F_28 ( V_53 , V_159 , V_1368 -> V_367 [ V_159 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1735 ) ;
if ( V_1368 -> V_1118 &&
F_51 ( V_53 , V_683 , V_1368 -> V_1119 , V_1368 -> V_1118 ) )
goto V_61;
if ( V_1368 -> V_51 &&
F_28 ( V_53 , V_1195 , V_1368 -> V_51 ) )
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
V_1736 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1737 , V_135 ) ;
}
struct V_31 * F_421 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1738 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_419 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1738 ? V_1739 :
V_1274 ) < 0 ) {
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
V_1737 , V_135 ) ;
}
void F_423 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_420 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1740 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1737 , V_135 ) ;
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
V_1737 , V_135 ) ;
}
static bool F_424 ( struct V_31 * V_53 ,
struct V_1741 * V_1183 )
{
if ( F_56 ( V_53 , V_1742 , V_1183 -> V_1451 ) )
goto V_61;
if ( V_1183 -> V_1132 [ 0 ] == '0' && V_1183 -> V_1132 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1743 ,
V_1744 ) )
goto V_61;
} else if ( V_1183 -> V_1132 [ 0 ] == '9' && V_1183 -> V_1132 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1743 ,
V_1745 ) )
goto V_61;
} else if ( ( V_1183 -> V_1132 [ 0 ] == '9' && V_1183 -> V_1132 [ 1 ] == '8' ) ||
V_1183 -> V_1746 ) {
if ( F_56 ( V_53 , V_1743 ,
V_1747 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1743 ,
V_1748 ) ||
F_60 ( V_53 , V_1028 ,
V_1183 -> V_1132 ) )
goto V_61;
}
if ( V_1183 -> V_14 != V_1749 ) {
struct V_18 * V_18 = F_19 ( V_1183 -> V_14 ) ;
if ( V_18 &&
F_28 ( V_53 , V_26 , V_1183 -> V_14 ) )
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
void F_425 ( enum V_280 V_1750 ,
struct V_1741 * V_1183 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1750 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_424 ( V_53 , V_1183 ) == false )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_426 ( & V_38 , V_53 , 0 ,
V_1751 , V_1752 ) ;
F_221 () ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static void F_427 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1508 , T_11 V_47 ,
enum V_280 V_52 , T_13 V_1408 ,
int V_922 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1505 , V_47 , V_1508 ) )
goto V_61;
if ( V_922 >= 0 ) {
struct V_4 * V_1753 =
F_47 ( V_53 , V_919 ) ;
if ( ! V_1753 )
goto V_61;
if ( F_56 ( V_53 , V_921 ,
V_922 ) )
goto V_61;
F_48 ( V_53 , V_1753 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_428 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1508 ,
T_11 V_47 , T_13 V_1408 )
{
F_427 ( V_7 , V_19 , V_1508 , V_47 ,
V_704 , V_1408 , - 1 ) ;
}
void F_429 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1508 ,
T_11 V_47 , T_13 V_1408 , int V_922 )
{
F_427 ( V_7 , V_19 , V_1508 , V_47 ,
V_1755 , V_1408 , V_922 ) ;
}
void F_430 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1508 ,
T_11 V_47 , T_13 V_1408 )
{
F_427 ( V_7 , V_19 , V_1508 , V_47 ,
V_1756 , V_1408 , - 1 ) ;
}
void F_431 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1508 ,
T_11 V_47 , T_13 V_1408 )
{
F_427 ( V_7 , V_19 , V_1508 , V_47 ,
V_1757 , V_1408 , - 1 ) ;
}
void F_432 ( struct V_25 * V_539 , const T_2 * V_1508 ,
T_11 V_47 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1758 * V_1759 = ( void * ) V_1508 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_433 ( V_1759 -> V_1760 ) )
V_52 = V_1761 ;
else
V_52 = V_1762 ;
F_434 ( V_539 , V_1508 , V_47 ) ;
F_427 ( V_7 , V_539 , V_1508 , V_47 , V_52 , V_1752 , - 1 ) ;
}
static void F_435 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_677 , T_13 V_1408 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1763 ) ||
F_51 ( V_53 , V_547 , V_587 , V_677 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_436 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_677 ,
T_13 V_1408 )
{
F_435 ( V_7 , V_19 , V_704 ,
V_677 , V_1408 ) ;
}
void F_437 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_677 ,
T_13 V_1408 )
{
F_435 ( V_7 , V_19 , V_1755 ,
V_677 , V_1408 ) ;
}
void F_438 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
const T_2 * V_1764 , T_11 V_1765 ,
const T_2 * V_1766 , T_11 V_1767 ,
T_3 V_641 , T_13 V_1408 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
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
F_55 ( V_53 , V_1453 , V_641 ) ||
( V_1764 &&
F_51 ( V_53 , V_1768 , V_1765 , V_1764 ) ) ||
( V_1766 &&
F_51 ( V_53 , V_1769 , V_1767 , V_1766 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_439 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
const T_2 * V_1764 , T_11 V_1765 ,
const T_2 * V_1766 , T_11 V_1767 , T_13 V_1408 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1770 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_546 ) ||
( V_1764 &&
F_51 ( V_53 , V_1768 , V_1765 , V_1764 ) ) ||
( V_1766 &&
F_51 ( V_53 , V_1769 , V_1767 , V_1766 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_440 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1433 ,
const T_2 * V_1118 , T_11 V_1119 , bool V_1771 )
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
( V_1771 && V_1433 &&
F_55 ( V_53 , V_967 , V_1433 ) ) ||
( V_1771 &&
F_29 ( V_53 , V_1772 ) ) ||
( V_1118 && F_51 ( V_53 , V_683 , V_1119 , V_1118 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_441 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
T_13 V_1408 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1773 ) ;
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
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_442 ( struct V_25 * V_539 , const T_2 * V_677 ,
const T_2 * V_1118 , T_2 V_1119 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_443 ( V_539 , V_677 ) ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1774 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_677 ) ||
( V_1119 && V_1118 &&
F_51 ( V_53 , V_683 , V_1119 , V_1118 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_444 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_677 ,
enum V_1775 V_1776 , int V_1777 ,
const T_2 * V_1778 , T_13 V_1408 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1779 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_677 && F_51 ( V_53 , V_547 , V_587 , V_677 ) ) ||
F_28 ( V_53 , V_127 , V_1776 ) ||
( V_1777 != - 1 &&
F_56 ( V_53 , V_123 , V_1777 ) ) ||
( V_1778 && F_51 ( V_53 , V_122 , 6 , V_1778 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_445 ( struct V_18 * V_18 ,
struct V_54 * V_1780 ,
struct V_54 * V_1781 )
{
struct V_31 * V_53 ;
void * V_283 ;
struct V_4 * V_287 ;
V_53 = F_74 ( V_600 , V_1752 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1782 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_217 ( V_18 ) ) )
goto V_61;
V_287 = F_47 ( V_53 , V_1783 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1780 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
V_287 = F_47 ( V_53 , V_1784 ) ;
if ( ! V_287 )
goto V_61;
if ( F_27 ( V_53 , V_1781 , false ) )
goto V_61;
F_48 ( V_53 , V_287 ) ;
F_66 ( V_53 , V_283 ) ;
F_219 () ;
F_426 ( & V_38 , V_53 , 0 ,
V_1751 , V_1752 ) ;
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
unsigned int V_1460 , T_13 V_1408 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
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
F_104 ( V_53 , V_1464 , V_647 ) )
goto V_61;
if ( V_52 == V_1463 &&
F_28 ( V_53 , V_1461 , V_1460 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_447 ( struct V_1 * V_17 , T_1 V_647 ,
struct V_54 * V_55 ,
unsigned int V_1460 , T_13 V_1408 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_448 ( V_17 , V_647 , V_55 , V_1460 ) ;
F_446 ( V_1463 ,
V_7 , V_17 , V_647 , V_55 ,
V_1460 , V_1408 ) ;
}
void F_449 ( struct V_1 * V_17 , T_1 V_647 ,
struct V_54 * V_55 ,
T_13 V_1408 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_450 ( V_17 , V_647 , V_55 ) ;
F_446 ( V_1785 ,
V_7 , V_17 , V_647 , V_55 , 0 , V_1408 ) ;
}
void F_451 ( struct V_25 * V_539 , const T_2 * V_649 ,
struct V_791 * V_792 , T_13 V_1408 )
{
struct V_18 * V_18 = V_539 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_452 ( V_539 , V_649 , V_792 ) ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
if ( F_163 ( V_53 , V_886 , 0 , 0 , 0 ,
V_7 , V_539 , V_649 , V_792 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
}
void F_453 ( struct V_25 * V_539 , const T_2 * V_649 ,
struct V_791 * V_792 , T_13 V_1408 )
{
struct V_18 * V_18 = V_539 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_791 V_1786 = {} ;
if ( ! V_792 )
V_792 = & V_1786 ;
F_454 ( V_539 , V_649 ) ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
if ( F_163 ( V_53 , V_1787 , 0 , 0 , 0 ,
V_7 , V_539 , V_649 , V_792 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
}
void F_455 ( struct V_25 * V_539 , const T_2 * V_649 ,
enum V_1788 V_1433 ,
T_13 V_1408 )
{
struct V_18 * V_18 = V_539 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_1789 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1790 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_649 ) ||
F_28 ( V_53 , V_1791 , V_1433 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static bool F_456 ( struct V_25 * V_539 , T_2 V_52 ,
const T_2 * V_677 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1668 = F_457 ( V_17 -> V_1661 ) ;
if ( ! V_1668 )
return false ;
V_53 = F_74 ( 100 , V_1408 ) ;
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
F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1668 ) ;
return true ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_459 ( struct V_25 * V_539 ,
const T_2 * V_677 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
bool V_496 ;
F_460 ( V_539 , V_677 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_461 ( false ) ;
return false ;
}
V_496 = F_456 ( V_539 , V_1792 ,
V_677 , V_1408 ) ;
F_461 ( V_496 ) ;
return V_496 ;
}
bool F_462 ( struct V_25 * V_539 ,
const T_2 * V_677 , T_13 V_1408 )
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
V_1793 ,
V_677 , V_1408 ) ;
F_461 ( V_496 ) ;
return V_496 ;
}
int F_464 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1668 ,
int V_1794 , int V_1795 ,
const T_2 * V_1508 , T_11 V_47 , V_22 V_51 , T_13 V_1408 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return - V_136 ;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1512 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_522 , V_1794 ) ||
( V_1795 &&
F_28 ( V_53 , V_1796 , V_1795 ) ) ||
F_51 ( V_53 , V_1505 , V_47 , V_1508 ) ||
( V_51 &&
F_28 ( V_53 , V_1797 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
return F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1668 ) ;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_465 ( struct V_1 * V_17 , T_1 V_647 ,
const T_2 * V_1508 , T_11 V_47 , bool V_1798 , T_13 V_1408 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_283 ;
F_466 ( V_17 , V_647 , V_1798 ) ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1799 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1505 , V_47 , V_1508 ) ||
F_104 ( V_53 , V_1464 , V_647 ) ||
( V_1798 && F_29 ( V_53 , V_1800 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_467 ( struct V_25 * V_539 ,
const char * V_961 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_600 , V_1408 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1801 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) )
goto V_61;
if ( V_961 && F_51 ( V_53 , V_547 , V_587 , V_961 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1531 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_468 ( struct V_31 * V_53 , T_13 V_1408 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
}
void F_469 ( struct V_25 * V_539 ,
enum V_1802 V_1803 ,
T_13 V_1408 )
{
struct V_31 * V_53 ;
F_470 ( V_539 , V_1803 ) ;
if ( F_59 ( V_1803 != V_1804 &&
V_1803 != V_1805 ) )
return;
V_53 = F_467 ( V_539 , NULL , V_1408 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1806 ,
V_1803 ) )
goto V_61;
F_468 ( V_53 , V_1408 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_471 ( struct V_25 * V_539 ,
const T_2 * V_1450 , V_22 V_1807 ,
V_22 V_244 , V_22 V_1523 , T_13 V_1408 )
{
struct V_31 * V_53 ;
V_53 = F_467 ( V_539 , V_1450 , V_1408 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1536 , V_1807 ) )
goto V_61;
if ( F_28 ( V_53 , V_1535 , V_244 ) )
goto V_61;
if ( F_28 ( V_53 , V_1537 , V_1523 ) )
goto V_61;
F_468 ( V_53 , V_1408 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_472 ( struct V_25 * V_539 ,
const T_2 * V_1450 , V_22 V_1807 , T_13 V_1408 )
{
struct V_31 * V_53 ;
F_473 ( V_539 , V_1450 , V_1807 ) ;
V_53 = F_467 ( V_539 , V_1450 , V_1408 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1808 , V_1807 ) )
goto V_61;
F_468 ( V_53 , V_1408 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_474 ( struct V_25 * V_539 , T_13 V_1408 )
{
struct V_31 * V_53 ;
V_53 = F_467 ( V_539 , NULL , V_1408 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1809 ) )
goto V_61;
F_468 ( V_53 , V_1408 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_475 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_546 ,
const T_2 * V_1659 , T_13 V_1408 )
{
struct V_31 * V_53 ;
struct V_4 * V_1810 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1811 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_546 ) )
goto V_61;
V_1810 = F_47 ( V_53 , V_1647 ) ;
if ( ! V_1810 )
goto V_61;
if ( F_51 ( V_53 , V_1650 ,
V_1651 , V_1659 ) )
goto V_61;
F_48 ( V_53 , V_1810 ) ;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_476 ( struct V_25 * V_539 , const T_2 * V_546 ,
const T_2 * V_1659 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_477 ( V_539 , V_546 ) ;
F_475 ( V_7 , V_539 , V_546 , V_1659 , V_1408 ) ;
}
static void
F_478 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1812 ,
const T_2 * V_546 , bool V_1813 , T_13 V_1408 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1814 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1815 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1816 , V_1812 ) ||
F_51 ( V_53 , V_1817 , V_587 , V_546 ) ||
( V_1813 &&
F_29 ( V_53 , V_1818 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_479 ( struct V_25 * V_539 , int V_1812 ,
const T_2 * V_546 , bool V_1813 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_480 ( V_539 , V_1812 , V_546 , V_1813 ) ;
F_478 ( V_7 , V_539 , V_1812 , V_546 , V_1813 , V_1408 ) ;
}
static void F_481 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_519 * V_520 ,
T_13 V_1408 ,
enum V_280 V_1819 ,
T_2 V_1253 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1819 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_520 ) )
goto V_61;
if ( ( V_1819 == V_1820 ) &&
( F_28 ( V_53 , V_1251 , V_1253 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
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
V_1821 , 0 ) ;
}
void F_484 ( struct V_25 * V_539 ,
struct V_519 * V_520 ,
T_2 V_1253 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_485 ( V_539 , V_520 ) ;
F_481 ( V_7 , V_539 , V_520 , V_135 ,
V_1820 , V_1253 ) ;
}
void
F_486 ( struct V_6 * V_7 ,
const struct V_519 * V_520 ,
enum V_1822 V_625 ,
struct V_25 * V_19 , T_13 V_1408 )
{
struct V_31 * V_53 ;
void * V_283 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1823 ) ;
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
if ( F_28 ( V_53 , V_1824 , V_625 ) )
goto V_61;
if ( F_101 ( V_53 , V_520 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_487 ( struct V_25 * V_539 , const T_2 * V_677 ,
T_1 V_647 , bool V_1825 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_488 ( V_539 , V_677 , V_647 , V_1825 ) ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1662 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_677 ) ||
F_104 ( V_53 , V_1464 , V_647 ) ||
( V_1825 && F_29 ( V_53 , V_1800 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
void F_489 ( struct V_18 * V_18 ,
const T_2 * V_1826 , T_11 V_47 ,
int V_1794 , int V_1795 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
struct V_1663 * V_1664 ;
F_490 ( V_18 , V_1826 , V_47 , V_1794 , V_1795 ) ;
F_267 ( & V_7 -> V_1667 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1752 ) ;
if ( ! V_53 ) {
F_269 ( & V_7 -> V_1667 ) ;
return;
}
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1512 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1794 &&
F_28 ( V_53 , V_522 , V_1794 ) ) ||
( V_1795 &&
F_28 ( V_53 , V_1796 , V_1795 ) ) ||
F_51 ( V_53 , V_1505 , V_47 , V_1826 ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1664 -> V_1668 ) ;
}
F_269 ( & V_7 -> V_1667 ) ;
return;
V_61:
F_269 ( & V_7 -> V_1667 ) ;
if ( V_283 )
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_491 ( struct V_31 * V_53 ,
struct V_1827 * V_1828 )
{
struct V_1829 * V_1573 = V_1828 -> V_1830 ;
struct V_4 * V_1831 , * V_1832 , * V_286 ;
int V_159 , V_161 ;
V_1831 = F_47 (
V_53 , V_1833 ) ;
if ( ! V_1831 )
return - V_495 ;
for ( V_159 = 0 ; V_159 < V_1573 -> V_1834 ; V_159 ++ ) {
struct V_1835 * V_1575 = V_1573 -> V_1574 [ V_159 ] ;
V_1832 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1832 )
break;
if ( F_51 ( V_53 , V_593 , V_1575 -> V_594 . V_592 ,
V_1575 -> V_594 . V_594 ) ) {
F_492 ( V_53 , V_1832 ) ;
goto V_599;
}
if ( V_1575 -> V_366 ) {
V_286 = F_47 (
V_53 , V_1189 ) ;
if ( ! V_286 ) {
F_492 ( V_53 , V_1832 ) ;
goto V_599;
}
for ( V_161 = 0 ; V_161 < V_1575 -> V_366 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1575 -> V_367 [ V_161 ] ) ) {
F_492 ( V_53 , V_286 ) ;
F_492 ( V_53 , V_1832 ) ;
goto V_599;
}
}
F_48 ( V_53 , V_286 ) ;
}
F_48 ( V_53 , V_1832 ) ;
}
V_599:
F_48 ( V_53 , V_1831 ) ;
return 0 ;
}
void F_493 ( struct V_1 * V_17 ,
struct V_1827 * V_1828 ,
T_13 V_1408 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
int V_1577 = 200 ;
F_494 ( V_17 -> V_18 , V_17 , V_1828 ) ;
if ( V_1828 )
V_1577 += V_1828 -> V_1836 ;
V_53 = F_74 ( V_1577 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1837 ) ;
if ( ! V_283 )
goto V_657;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_657;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_657;
if ( V_1828 ) {
struct V_4 * V_1838 ;
V_1838 = F_47 ( V_53 , V_1579 ) ;
if ( ! V_1838 )
goto V_657;
if ( V_1828 -> V_451 &&
F_29 ( V_53 , V_206 ) )
goto V_657;
if ( V_1828 -> V_1581 &&
F_29 ( V_53 , V_208 ) )
goto V_657;
if ( V_1828 -> V_1582 &&
F_29 ( V_53 , V_212 ) )
goto V_657;
if ( V_1828 -> V_1583 &&
F_29 ( V_53 , V_214 ) )
goto V_657;
if ( V_1828 -> V_1584 &&
F_29 ( V_53 , V_216 ) )
goto V_657;
if ( V_1828 -> V_1585 &&
F_29 ( V_53 , V_218 ) )
goto V_657;
if ( V_1828 -> V_1839 >= 0 &&
F_28 ( V_53 , V_228 ,
V_1828 -> V_1839 ) )
goto V_657;
if ( V_1828 -> V_1840 &&
F_29 ( V_53 , V_1841 ) )
goto V_657;
if ( V_1828 -> V_1842 &&
F_29 ( V_53 , V_1843 ) )
goto V_657;
if ( V_1828 -> V_1844 &&
F_29 ( V_53 ,
V_1845 ) )
goto V_657;
if ( V_1828 -> V_1846 ) {
V_22 V_1847 = V_1848 ;
V_22 V_1849 = V_1850 ;
if ( ! V_1828 -> V_1851 ) {
V_1847 =
V_1852 ;
V_1849 =
V_1853 ;
}
if ( V_1828 -> V_1854 &&
F_28 ( V_53 , V_1849 , V_1828 -> V_1854 ) )
goto V_657;
if ( F_51 ( V_53 , V_1847 , V_1828 -> V_1836 ,
V_1828 -> V_1846 ) )
goto V_657;
}
if ( V_1828 -> V_1830 &&
F_491 ( V_53 , V_1828 ) )
goto V_657;
F_48 ( V_53 , V_1838 ) ;
}
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_657:
F_75 ( V_53 ) ;
}
void F_495 ( struct V_25 * V_539 , const T_2 * V_1450 ,
enum V_1457 V_1855 ,
T_3 V_968 , T_13 V_1408 )
{
struct V_1 * V_17 = V_539 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_496 ( V_17 -> V_18 , V_539 , V_1450 , V_1855 ,
V_968 ) ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1856 ) ;
if ( ! V_283 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_539 -> V_20 ) ||
F_56 ( V_53 , V_1459 , V_1855 ) ||
F_51 ( V_53 , V_547 , V_587 , V_1450 ) ||
( V_968 > 0 &&
F_55 ( V_53 , V_967 , V_968 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_1408 ) ;
return;
V_61:
F_67 ( V_53 , V_283 ) ;
F_75 ( V_53 ) ;
}
static int F_497 ( struct V_1857 * V_1858 ,
unsigned long V_282 ,
void * V_1859 )
{
struct V_1860 * V_1861 = V_1859 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1663 * V_1664 , * V_24 ;
if ( V_282 != V_1862 || V_1861 -> V_1863 != V_1864 )
return V_1865 ;
F_219 () ;
F_498 (rdev, &cfg80211_rdev_list, list) {
bool V_1866 = false ;
bool V_1867 = false ;
struct V_1206 * V_1237 =
F_220 ( V_7 -> V_1237 ) ;
if ( V_1237 && V_1861 -> V_49 &&
V_1237 -> V_632 == V_1861 -> V_49 )
V_1867 = true ;
F_498 (wdev, &rdev->wdev_list, list) {
F_499 ( V_17 , V_1861 -> V_49 ) ;
if ( V_17 -> V_632 == V_1861 -> V_49 )
V_1866 = true ;
}
F_267 ( & V_7 -> V_1667 ) ;
F_500 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1664 -> V_1668 == V_1861 -> V_49 ) {
F_501 ( & V_1664 -> V_638 ) ;
F_41 ( V_1664 ) ;
break;
}
}
F_269 ( & V_7 -> V_1667 ) ;
if ( V_1866 ) {
struct V_1868 * V_1869 ;
V_1869 = F_38 ( sizeof( * V_1869 ) , V_1752 ) ;
if ( V_1869 ) {
V_1869 -> V_1668 = V_1861 -> V_49 ;
F_502 ( & V_7 -> V_1870 ) ;
F_384 ( & V_1869 -> V_638 , & V_7 -> V_1871 ) ;
F_503 ( & V_7 -> V_1870 ) ;
F_504 ( & V_7 -> V_1872 ) ;
}
} else if ( V_1867 ) {
V_1237 -> V_632 = 0 ;
if ( V_7 -> V_351 -> V_1239 &&
V_7 -> V_18 . V_51 & V_422 )
F_504 ( & V_7 -> V_1873 ) ;
}
}
F_221 () ;
F_505 ( V_1861 -> V_49 ) ;
return V_1874 ;
}
void F_506 ( struct V_25 * V_19 ,
struct V_1875 * V_1876 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_283 ;
F_507 ( V_18 , V_19 , V_1876 ) ;
if ( ! V_1876 -> V_1877 )
return;
V_53 = F_74 ( V_600 , V_135 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1878 ) ;
if ( ! V_283 )
goto V_599;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_547 , V_587 , V_1876 -> V_1877 ) )
goto V_599;
if ( V_1876 -> V_1272 &&
F_51 ( V_53 , V_683 , V_1876 -> V_1879 , V_1876 -> V_1272 ) )
goto V_599;
if ( V_1876 -> V_1880 &&
F_51 ( V_53 , V_1881 , V_1876 -> V_1882 ,
V_1876 -> V_1880 ) )
goto V_599;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1754 , V_135 ) ;
return;
V_599:
F_75 ( V_53 ) ;
}
void F_508 ( struct V_1 * V_17 , T_13 V_1408 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_283 ;
V_22 V_1668 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1685 )
return;
V_1668 = V_7 -> V_1685 ;
V_7 -> V_1685 = 0 ;
V_53 = F_74 ( V_600 , V_1408 ) ;
if ( ! V_53 )
return;
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1883 ) ;
if ( ! V_283 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_66 ( V_53 , V_283 ) ;
F_458 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1668 ) ;
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
V_283 = F_25 ( V_53 , 0 , 0 , 0 , V_1884 ) ;
if ( ! V_283 )
goto V_599;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_599;
F_66 ( V_53 , V_283 ) ;
F_126 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1754 , V_135 ) ;
return;
V_599:
F_75 ( V_53 ) ;
}
int F_510 ( void )
{
int V_35 ;
V_35 = F_511 ( & V_38 , V_1885 ,
V_1886 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_512 ( & V_1887 ) ;
if ( V_35 )
goto V_1888;
return 0 ;
V_1888:
F_513 ( & V_38 ) ;
return V_35 ;
}
void F_514 ( void )
{
F_515 ( & V_1887 ) ;
F_513 ( & V_38 ) ;
}
