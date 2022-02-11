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
if ( V_56 && F_50 ( V_7 , V_53 ) )
return - V_91 ;
F_48 ( V_53 , V_201 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_229 V_230 ;
if ( ! V_7 -> V_18 . V_231 )
return 0 ;
V_230 . V_232 = V_7 -> V_18 . V_231 -> V_233 ;
V_230 . V_234 = V_7 -> V_18 . V_231 -> V_234 ;
V_230 . V_221 . V_222 = V_7 -> V_18 . V_231 -> V_219 ;
V_230 . V_221 . V_223 = V_7 -> V_18 . V_231 -> V_224 ;
V_230 . V_221 . V_225 = V_7 -> V_18 . V_231 -> V_226 ;
V_230 . V_221 . V_227 = V_7 -> V_18 . V_231 -> V_227 ;
if ( F_51 ( V_53 , V_235 , sizeof( V_230 ) , & V_230 ) )
return - V_91 ;
return 0 ;
}
static int F_54 ( struct V_31 * V_53 ,
struct V_236 * V_237 )
{
struct V_4 * V_238 , * V_239 ;
struct V_240 * V_241 ;
int V_159 ;
if ( V_237 -> V_242 . V_243 &&
( F_51 ( V_53 , V_244 ,
sizeof( V_237 -> V_242 . V_245 ) ,
& V_237 -> V_242 . V_245 ) ||
F_55 ( V_53 , V_246 ,
V_237 -> V_242 . V_247 ) ||
F_56 ( V_53 , V_248 ,
V_237 -> V_242 . V_249 ) ||
F_56 ( V_53 , V_250 ,
V_237 -> V_242 . V_251 ) ) )
return - V_91 ;
if ( V_237 -> V_252 . V_253 &&
( F_51 ( V_53 , V_254 ,
sizeof( V_237 -> V_252 . V_255 ) ,
& V_237 -> V_252 . V_255 ) ||
F_28 ( V_53 , V_256 ,
V_237 -> V_252 . V_247 ) ) )
return - V_91 ;
V_238 = F_47 ( V_53 , V_257 ) ;
if ( ! V_238 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_237 -> V_258 ; V_159 ++ ) {
V_239 = F_47 ( V_53 , V_159 ) ;
if ( ! V_239 )
return - V_91 ;
V_241 = & V_237 -> V_259 [ V_159 ] ;
if ( F_28 ( V_53 , V_260 ,
V_241 -> V_261 ) )
return - V_91 ;
if ( ( V_241 -> V_51 & V_262 ) &&
F_29 ( V_53 ,
V_263 ) )
return - V_91 ;
F_48 ( V_53 , V_239 ) ;
}
F_48 ( V_53 , V_238 ) ;
return 0 ;
}
static int
F_57 ( struct V_31 * V_53 ,
const struct V_264 * V_265 )
{
T_3 V_266 ;
struct V_4 * V_267 , * V_268 ;
enum V_269 V_270 ;
int V_159 ;
if ( ! V_265 )
return 0 ;
V_268 = F_47 ( V_53 , V_271 ) ;
if ( ! V_268 )
return - V_91 ;
for ( V_270 = 0 ; V_270 < V_156 ; V_270 ++ ) {
V_267 = F_47 ( V_53 , V_270 ) ;
if ( ! V_267 )
return - V_91 ;
V_159 = 0 ;
V_266 = V_265 [ V_270 ] . V_272 ;
while ( V_266 ) {
if ( ( V_266 & 1 ) &&
F_55 ( V_53 , V_273 ,
( V_159 << 4 ) | V_274 ) )
return - V_91 ;
V_266 >>= 1 ;
V_159 ++ ;
}
F_48 ( V_53 , V_267 ) ;
}
F_48 ( V_53 , V_268 ) ;
V_268 = F_47 ( V_53 , V_275 ) ;
if ( ! V_268 )
return - V_91 ;
for ( V_270 = 0 ; V_270 < V_156 ; V_270 ++ ) {
V_267 = F_47 ( V_53 , V_270 ) ;
if ( ! V_267 )
return - V_91 ;
V_159 = 0 ;
V_266 = V_265 [ V_270 ] . V_276 ;
while ( V_266 ) {
if ( ( V_266 & 1 ) &&
F_55 ( V_53 , V_273 ,
( V_159 << 4 ) | V_274 ) )
return - V_91 ;
V_266 >>= 1 ;
V_159 ++ ;
}
F_48 ( V_53 , V_267 ) ;
}
F_48 ( V_53 , V_268 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
enum V_277 V_52 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_278 * V_279 )
{
void * V_280 ;
struct V_4 * V_281 , * V_282 ;
struct V_4 * V_283 , * V_284 ;
struct V_4 * V_285 ;
enum V_286 V_287 ;
struct V_54 * V_55 ;
int V_159 ;
const struct V_264 * V_265 =
V_7 -> V_18 . V_265 ;
V_22 V_288 ;
V_280 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_280 )
return - V_91 ;
if ( F_59 ( ! V_279 ) )
return - V_16 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_60 ( V_53 , V_289 ,
F_61 ( & V_7 -> V_18 ) ) ||
F_28 ( V_53 , V_290 ,
V_291 ) )
goto V_61;
if ( V_52 != V_292 )
goto V_293;
switch ( V_279 -> V_294 ) {
case 0 :
if ( F_56 ( V_53 , V_295 ,
V_7 -> V_18 . V_296 ) ||
F_56 ( V_53 , V_297 ,
V_7 -> V_18 . V_298 ) ||
F_28 ( V_53 , V_299 ,
V_7 -> V_18 . V_300 ) ||
F_28 ( V_53 , V_301 ,
V_7 -> V_18 . V_302 ) ||
F_56 ( V_53 , V_303 ,
V_7 -> V_18 . V_304 ) ||
F_56 ( V_53 , V_305 ,
V_7 -> V_18 . V_306 ) ||
F_56 ( V_53 , V_307 ,
V_7 -> V_18 . V_308 ) ||
F_55 ( V_53 , V_309 ,
V_7 -> V_18 . V_310 ) ||
F_55 ( V_53 , V_311 ,
V_7 -> V_18 . V_312 ) ||
F_56 ( V_53 , V_313 ,
V_7 -> V_18 . V_314 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_315 ) &&
F_29 ( V_53 , V_316 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_317 ) &&
F_29 ( V_53 , V_318 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_319 ) &&
F_29 ( V_53 , V_320 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_321 ) &&
F_29 ( V_53 , V_322 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_323 ) &&
F_29 ( V_53 , V_324 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_325 ) &&
F_29 ( V_53 , V_326 ) )
goto V_61;
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
case 1 :
if ( F_51 ( V_53 , V_328 ,
sizeof( V_22 ) * V_7 -> V_18 . V_329 ,
V_7 -> V_18 . V_330 ) )
goto V_61;
if ( F_56 ( V_53 , V_331 ,
V_7 -> V_18 . V_332 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_333 ) &&
F_29 ( V_53 , V_334 ) )
goto V_61;
if ( F_28 ( V_53 , V_335 ,
V_7 -> V_18 . V_336 ) ||
F_28 ( V_53 , V_337 ,
V_7 -> V_18 . V_338 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_339 ) &&
F_28 ( V_53 , V_340 ,
V_7 -> V_18 . V_341 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_336 ||
V_7 -> V_18 . V_338 ) &&
V_7 -> V_342 -> V_343 ) {
V_22 V_344 = 0 , V_345 = 0 ;
int V_346 ;
V_346 = F_62 ( V_7 , & V_344 , & V_345 ) ;
if ( ! V_346 ) {
if ( F_28 ( V_53 ,
V_347 ,
V_344 ) ||
F_28 ( V_53 ,
V_348 ,
V_345 ) )
goto V_61;
}
}
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
case 2 :
if ( F_46 ( V_53 , V_349 ,
V_7 -> V_18 . V_350 ) )
goto V_61;
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
case 3 :
V_281 = F_47 ( V_53 , V_351 ) ;
if ( ! V_281 )
goto V_61;
for ( V_287 = V_279 -> V_352 ;
V_287 < V_353 ; V_287 ++ ) {
struct V_236 * V_237 ;
V_237 = V_7 -> V_18 . V_354 [ V_287 ] ;
if ( ! V_237 )
continue;
V_282 = F_47 ( V_53 , V_287 ) ;
if ( ! V_282 )
goto V_61;
switch ( V_279 -> V_355 ) {
case 0 :
if ( F_54 ( V_53 , V_237 ) )
goto V_61;
V_279 -> V_355 ++ ;
if ( V_279 -> V_327 )
break;
default:
V_283 = F_47 (
V_53 , V_356 ) ;
if ( ! V_283 )
goto V_61;
for ( V_159 = V_279 -> V_355 - 1 ;
V_159 < V_237 -> V_357 ;
V_159 ++ ) {
V_284 = F_47 ( V_53 , V_159 ) ;
if ( ! V_284 )
goto V_61;
V_55 = & V_237 -> V_358 [ V_159 ] ;
if ( F_27 (
V_53 , V_55 ,
V_279 -> V_327 ) )
goto V_61;
F_48 ( V_53 , V_284 ) ;
if ( V_279 -> V_327 )
break;
}
if ( V_159 < V_237 -> V_357 )
V_279 -> V_355 = V_159 + 2 ;
else
V_279 -> V_355 = 0 ;
F_48 ( V_53 , V_283 ) ;
}
F_48 ( V_53 , V_282 ) ;
if ( V_279 -> V_327 ) {
if ( V_279 -> V_355 )
V_287 -- ;
break;
}
}
F_48 ( V_53 , V_281 ) ;
if ( V_287 < V_353 )
V_279 -> V_352 = V_287 + 1 ;
else
V_279 -> V_352 = 0 ;
if ( V_279 -> V_352 == 0 && V_279 -> V_355 == 0 )
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
case 4 :
V_285 = F_47 ( V_53 , V_359 ) ;
if ( ! V_285 )
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
F_63 ( V_360 , V_361 ) ;
F_63 ( V_362 , V_363 ) ;
F_63 ( V_364 , V_365 ) ;
F_63 ( V_366 , V_367 ) ;
F_63 ( V_368 , V_369 ) ;
F_63 ( V_370 , V_371 ) ;
F_63 ( V_372 , V_373 ) ;
F_63 ( V_374 , V_375 ) ;
F_63 ( V_376 , V_377 ) ;
F_63 ( V_378 , V_379 ) ;
F_63 ( V_380 , V_381 ) ;
F_63 ( V_382 , V_383 ) ;
F_63 ( V_384 , V_385 ) ;
F_63 ( V_386 , V_387 ) ;
F_63 ( V_388 , V_389 ) ;
F_63 ( V_390 , V_391 ) ;
F_63 ( V_392 , V_393 ) ;
if ( V_7 -> V_18 . V_51 & V_394 )
F_63 ( V_395 , V_396 ) ;
F_63 ( V_397 , V_398 ) ;
F_63 ( V_399 , V_400 ) ;
F_63 ( V_401 , V_402 ) ;
if ( V_7 -> V_18 . V_51 & V_403 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_404 ) )
goto V_61;
}
if ( V_7 -> V_342 -> V_405 || V_7 -> V_342 -> V_366 ||
V_7 -> V_342 -> V_386 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_406 ) )
goto V_61;
}
F_63 ( V_407 , V_408 ) ;
if ( V_7 -> V_18 . V_51 & V_323 ) {
F_63 ( V_409 , V_410 ) ;
F_63 ( V_411 , V_412 ) ;
}
if ( V_7 -> V_18 . V_51 & V_413 )
F_63 ( V_414 , V_415 ) ;
F_63 ( V_416 , V_417 ) ;
F_63 ( V_418 , V_419 ) ;
if ( V_7 -> V_18 . V_51 & V_420 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_421 ) )
goto V_61;
}
F_63 ( V_422 , V_423 ) ;
F_63 ( V_424 , V_425 ) ;
#ifdef F_64
F_63 ( V_426 , V_427 ) ;
#endif
if ( V_279 -> V_327 ) {
F_63 ( V_428 , V_429 ) ;
F_63 ( V_430 , V_431 ) ;
if ( V_7 -> V_18 . V_51 & V_432 )
F_63 ( V_433 , V_434 ) ;
F_63 ( V_435 , V_436 ) ;
if ( V_7 -> V_18 . V_288 &
V_437 )
F_63 ( V_438 , V_439 ) ;
}
#undef F_63
if ( V_7 -> V_342 -> V_440 || V_7 -> V_342 -> V_376 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_441 ) )
goto V_61;
}
if ( V_7 -> V_342 -> V_442 || V_7 -> V_342 -> V_380 ) {
V_159 ++ ;
if ( F_28 ( V_53 , V_159 , V_443 ) )
goto V_61;
}
F_48 ( V_53 , V_285 ) ;
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
case 5 :
if ( V_7 -> V_342 -> V_395 &&
( V_7 -> V_18 . V_51 & V_394 ) &&
F_28 ( V_53 ,
V_444 ,
V_7 -> V_18 . V_445 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_446 ) &&
F_29 ( V_53 , V_447 ) )
goto V_61;
if ( F_57 ( V_53 , V_265 ) )
goto V_61;
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
case 6 :
#ifdef F_65
if ( F_52 ( V_53 , V_7 , V_279 -> V_327 ) )
goto V_61;
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
#else
V_279 -> V_294 ++ ;
#endif
case 7 :
if ( F_46 ( V_53 , V_448 ,
V_7 -> V_18 . V_449 ) )
goto V_61;
if ( F_49 ( & V_7 -> V_18 , V_53 ,
V_279 -> V_327 ) )
goto V_61;
V_279 -> V_294 ++ ;
if ( V_279 -> V_327 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_51 & V_450 ) &&
F_28 ( V_53 , V_451 ,
V_7 -> V_18 . V_452 ) )
goto V_61;
V_288 = V_7 -> V_18 . V_288 ;
if ( V_279 -> V_327 )
V_288 |= V_453 ;
if ( F_28 ( V_53 , V_454 , V_288 ) )
goto V_61;
if ( V_7 -> V_18 . V_455 &&
F_51 ( V_53 , V_456 ,
sizeof( * V_7 -> V_18 . V_455 ) ,
V_7 -> V_18 . V_455 ) )
goto V_61;
if ( V_7 -> V_18 . V_51 & V_450 &&
V_7 -> V_18 . V_457 &&
F_28 ( V_53 , V_458 ,
V_7 -> V_18 . V_457 ) )
goto V_61;
V_279 -> V_294 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_459 &&
( F_51 ( V_53 , V_460 ,
V_7 -> V_18 . V_461 ,
V_7 -> V_18 . V_459 ) ||
F_51 ( V_53 , V_462 ,
V_7 -> V_18 . V_461 ,
V_7 -> V_18 . V_463 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_464 &&
F_51 ( V_53 , V_465 ,
sizeof( * V_7 -> V_18 . V_464 ) ,
V_7 -> V_18 . V_464 ) )
goto V_61;
V_279 -> V_294 ++ ;
break;
case 10 :
if ( F_53 ( V_53 , V_7 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_466 ) &&
( F_29 ( V_53 , V_467 ) ||
F_29 ( V_53 , V_468 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_469 &&
F_28 ( V_53 , V_470 ,
V_7 -> V_18 . V_469 ) )
goto V_61;
V_279 -> V_294 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_471 ) {
const struct V_472 * V_30 ;
struct V_4 * V_473 ;
V_473 = F_47 ( V_53 , V_474 ) ;
if ( ! V_473 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_471 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_475 [ V_159 ] . V_30 ;
if ( F_51 ( V_53 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_473 ) ;
}
if ( V_7 -> V_18 . V_476 ) {
const struct V_472 * V_30 ;
struct V_4 * V_473 ;
V_473 = F_47 ( V_53 ,
V_477 ) ;
if ( ! V_473 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_476 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_478 [ V_159 ] ;
if ( F_51 ( V_53 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_473 ) ;
}
V_279 -> V_294 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_51 & V_432 &&
F_56 ( V_53 , V_479 ,
V_7 -> V_18 . V_480 ) )
goto V_61;
V_279 -> V_294 = 0 ;
break;
}
V_293:
return F_66 ( V_53 , V_280 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_278 * V_279 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_482 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_482 )
return 0 ;
V_279 -> V_327 = V_95 [ V_483 ] ;
if ( V_95 [ V_26 ] )
V_279 -> V_484 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_279 -> V_484 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
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
V_279 -> V_484 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_482 ;
struct V_278 * V_279 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_279 ) {
V_279 = F_38 ( sizeof( * V_279 ) , V_135 ) ;
if ( ! V_279 ) {
F_20 () ;
return - V_136 ;
}
V_279 -> V_484 = - 1 ;
V_482 = F_68 ( V_32 , V_34 , V_279 ) ;
if ( V_482 ) {
F_41 ( V_279 ) ;
F_20 () ;
return V_482 ;
}
V_34 -> args [ 0 ] = ( long ) V_279 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_279 -> V_485 )
continue;
if ( V_279 -> V_484 != - 1 &&
V_279 -> V_484 != V_7 -> V_14 )
continue;
do {
V_482 = F_58 ( V_7 , V_292 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_486 ,
V_487 , V_279 ) ;
if ( V_482 < 0 ) {
if ( ( V_482 == - V_91 || V_482 == - V_481 ) &&
! V_32 -> V_47 && ! V_279 -> V_327 &&
V_34 -> V_488 < 4096 ) {
V_34 -> V_488 = 4096 ;
V_279 -> V_294 = 0 ;
F_20 () ;
return 1 ;
}
V_105 -- ;
break;
}
} while ( V_279 -> V_294 > 0 );
break;
}
F_20 () ;
V_279 -> V_485 = V_105 ;
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
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_278 V_279 = {} ;
V_53 = F_74 ( 4096 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_58 ( V_7 , V_292 , V_53 ,
V_30 -> V_490 , V_30 -> V_491 , 0 ,
& V_279 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_492 * V_493 )
{
if ( ! V_95 [ V_494 ] || ! V_95 [ V_495 ] ||
! V_95 [ V_496 ] || ! V_95 [ V_497 ] ||
! V_95 [ V_498 ] )
return - V_16 ;
V_493 -> V_499 = F_34 ( V_95 [ V_494 ] ) ;
V_493 -> V_500 = F_78 ( V_95 [ V_495 ] ) ;
V_493 -> V_501 = F_78 ( V_95 [ V_496 ] ) ;
V_493 -> V_502 = F_78 ( V_95 [ V_497 ] ) ;
V_493 -> V_503 = F_34 ( V_95 [ V_498 ] ) ;
if ( V_493 -> V_499 >= V_504 )
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
struct V_505 * V_506 )
{
V_22 V_507 ;
if ( ! V_30 -> V_5 [ V_508 ] )
return - V_16 ;
V_507 = F_4 ( V_30 -> V_5 [ V_508 ] ) ;
V_506 -> V_55 = F_45 ( & V_7 -> V_18 , V_507 ) ;
V_506 -> V_509 = V_510 ;
V_506 -> V_511 = V_507 ;
V_506 -> V_512 = 0 ;
if ( ! V_506 -> V_55 || V_506 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_513 ] ) {
enum V_514 V_515 ;
V_515 = F_4 (
V_30 -> V_5 [ V_513 ] ) ;
switch ( V_515 ) {
case V_516 :
case V_517 :
case V_518 :
case V_519 :
F_81 ( V_506 , V_506 -> V_55 ,
V_515 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_520 ] ) {
V_506 -> V_509 =
F_4 ( V_30 -> V_5 [ V_520 ] ) ;
if ( V_30 -> V_5 [ V_521 ] )
V_506 -> V_511 =
F_4 (
V_30 -> V_5 [ V_521 ] ) ;
if ( V_30 -> V_5 [ V_522 ] )
V_506 -> V_512 =
F_4 (
V_30 -> V_5 [ V_522 ] ) ;
}
if ( ! F_82 ( V_506 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_506 ,
V_62 ) )
return - V_16 ;
if ( ( V_506 -> V_509 == V_523 ||
V_506 -> V_509 == V_524 ) &&
! ( V_7 -> V_18 . V_51 & V_466 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_525 ,
struct V_29 * V_30 )
{
struct V_505 V_506 ;
int V_8 ;
enum V_269 V_141 = V_153 ;
struct V_1 * V_17 = NULL ;
if ( V_525 )
V_17 = V_525 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_526 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_80 ( V_7 , V_30 , & V_506 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_85 ( & V_7 -> V_18 , & V_506 , V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_527 ) {
if ( ! V_525 || ! V_7 -> V_342 -> V_528 ||
! ( V_7 -> V_18 . V_288 &
V_529 ) ) {
V_8 = - V_530 ;
break;
}
if ( V_506 . V_55 != V_17 -> V_531 . V_55 ) {
V_8 = - V_530 ;
break;
}
V_8 = F_86 ( V_7 , V_525 , & V_506 ) ;
if ( V_8 )
break;
}
V_17 -> V_531 = V_506 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_87 ( V_7 , V_17 , & V_506 ) ;
break;
case V_153 :
V_8 = F_88 ( V_7 , & V_506 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_489 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
const T_2 * V_532 ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( F_91 ( V_525 ) )
return - V_530 ;
if ( ! V_7 -> V_342 -> V_407 )
return - V_526 ;
if ( V_17 -> V_141 != V_155 )
return - V_526 ;
V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
return F_92 ( V_7 , V_525 , V_532 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_534 = 0 ;
struct V_4 * V_535 ;
V_22 V_536 ;
T_2 V_296 = 0 , V_298 = 0 ;
V_22 V_300 = 0 , V_302 = 0 ;
T_2 V_304 = 0 ;
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
if ( V_30 -> V_5 [ V_289 ] )
V_8 = F_95 (
V_7 , F_23 ( V_30 -> V_5 [ V_289 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_537 ] ) {
struct V_492 V_493 ;
struct V_4 * V_95 [ V_538 + 1 ] ;
if ( ! V_7 -> V_342 -> V_539 )
return - V_526 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_540 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_538 ,
F_23 ( V_535 ) ,
F_24 ( V_535 ) ,
V_541 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_493 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_493 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_508 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_542 ] ) {
struct V_1 * V_543 = V_17 ;
enum V_544 type ;
int V_105 , V_545 = 0 ;
if ( ! ( V_7 -> V_18 . V_288 & V_546 ) )
V_543 = NULL ;
if ( ! V_7 -> V_342 -> V_547 )
return - V_526 ;
V_105 = V_542 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_548 ] &&
( type != V_549 ) )
return - V_16 ;
if ( type != V_549 ) {
V_105 = V_548 ;
V_545 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_543 , type , V_545 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_347 ] &&
V_30 -> V_5 [ V_348 ] ) {
V_22 V_344 , V_345 ;
if ( ( ! V_7 -> V_18 . V_336 &&
! V_7 -> V_18 . V_338 ) ||
! V_7 -> V_342 -> V_550 )
return - V_526 ;
V_344 = F_4 ( V_30 -> V_5 [ V_347 ] ) ;
V_345 = F_4 ( V_30 -> V_5 [ V_348 ] ) ;
if ( ( ~ V_344 && ( V_344 & ~ V_7 -> V_18 . V_336 ) ) ||
( ~ V_345 && ( V_345 & ~ V_7 -> V_18 . V_338 ) ) )
return - V_16 ;
V_344 = V_344 & V_7 -> V_18 . V_336 ;
V_345 = V_345 & V_7 -> V_18 . V_338 ;
V_8 = F_99 ( V_7 , V_344 , V_345 ) ;
if ( V_8 )
return V_8 ;
}
V_536 = 0 ;
if ( V_30 -> V_5 [ V_295 ] ) {
V_296 = F_34 (
V_30 -> V_5 [ V_295 ] ) ;
if ( V_296 == 0 )
return - V_16 ;
V_536 |= V_551 ;
}
if ( V_30 -> V_5 [ V_297 ] ) {
V_298 = F_34 (
V_30 -> V_5 [ V_297 ] ) ;
if ( V_298 == 0 )
return - V_16 ;
V_536 |= V_552 ;
}
if ( V_30 -> V_5 [ V_299 ] ) {
V_300 = F_4 (
V_30 -> V_5 [ V_299 ] ) ;
if ( V_300 < 256 )
return - V_16 ;
if ( V_300 != ( V_22 ) - 1 ) {
V_300 &= ~ 0x1 ;
}
V_536 |= V_553 ;
}
if ( V_30 -> V_5 [ V_301 ] ) {
V_302 = F_4 (
V_30 -> V_5 [ V_301 ] ) ;
V_536 |= V_554 ;
}
if ( V_30 -> V_5 [ V_303 ] ) {
if ( V_30 -> V_5 [ V_555 ] )
return - V_16 ;
V_304 = F_34 (
V_30 -> V_5 [ V_303 ] ) ;
V_536 |= V_556 ;
}
if ( V_30 -> V_5 [ V_555 ] ) {
if ( ! ( V_7 -> V_18 . V_288 & V_557 ) )
return - V_526 ;
V_536 |= V_558 ;
}
if ( V_536 ) {
T_2 V_559 , V_560 ;
V_22 V_561 , V_562 ;
T_2 V_563 ;
if ( ! V_7 -> V_342 -> V_564 )
return - V_526 ;
V_559 = V_7 -> V_18 . V_296 ;
V_560 = V_7 -> V_18 . V_298 ;
V_561 = V_7 -> V_18 . V_300 ;
V_562 = V_7 -> V_18 . V_302 ;
V_563 = V_7 -> V_18 . V_304 ;
if ( V_536 & V_551 )
V_7 -> V_18 . V_296 = V_296 ;
if ( V_536 & V_552 )
V_7 -> V_18 . V_298 = V_298 ;
if ( V_536 & V_553 )
V_7 -> V_18 . V_300 = V_300 ;
if ( V_536 & V_554 )
V_7 -> V_18 . V_302 = V_302 ;
if ( V_536 & V_556 )
V_7 -> V_18 . V_304 = V_304 ;
V_8 = F_100 ( V_7 , V_536 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_296 = V_559 ;
V_7 -> V_18 . V_298 = V_560 ;
V_7 -> V_18 . V_300 = V_561 ;
V_7 -> V_18 . V_302 = V_562 ;
V_7 -> V_18 . V_304 = V_563 ;
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
const struct V_505 * V_506 )
{
if ( F_59 ( ! F_82 ( V_506 ) ) )
return - V_16 ;
if ( F_28 ( V_53 , V_508 ,
V_506 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_506 -> V_509 ) {
case V_510 :
case V_565 :
case V_566 :
if ( F_28 ( V_53 , V_513 ,
F_102 ( V_506 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_520 , V_506 -> V_509 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_521 , V_506 -> V_511 ) )
return - V_91 ;
if ( V_506 -> V_512 &&
F_28 ( V_53 , V_522 , V_506 -> V_512 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_567 )
{
struct V_25 * V_525 = V_17 -> V_19 ;
T_2 V_52 = V_568 ;
void * V_280 ;
if ( V_567 )
V_52 = V_569 ;
V_280 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_280 )
return - 1 ;
if ( V_525 &&
( F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_60 ( V_53 , V_570 , V_525 -> V_571 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_572 , V_17 -> V_141 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_533 , V_573 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_290 ,
V_7 -> V_574 ^
( V_291 << 2 ) ) )
goto V_61;
if ( V_7 -> V_342 -> V_575 ) {
int V_482 ;
struct V_505 V_506 ;
V_482 = F_106 ( V_7 , V_17 , & V_506 ) ;
if ( V_482 == 0 ) {
if ( F_101 ( V_53 , & V_506 ) )
goto V_61;
}
}
if ( V_17 -> V_576 ) {
if ( F_51 ( V_53 , V_577 , V_17 -> V_576 , V_17 -> V_578 ) )
goto V_61;
}
return F_66 ( V_53 , V_280 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
static int F_107 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_579 = 0 ;
int V_580 = 0 ;
int V_581 = V_34 -> args [ 0 ] ;
int V_582 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_579 < V_581 ) {
V_579 ++ ;
continue;
}
V_580 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_580 < V_582 ) {
V_580 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_486 , V_487 ,
V_7 , V_17 , false ) < 0 ) {
goto V_583;
}
V_580 ++ ;
}
V_579 ++ ;
}
V_583:
F_20 () ;
V_34 -> args [ 0 ] = V_579 ;
V_34 -> args [ 1 ] = V_580 ;
return V_32 -> V_47 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_103 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_109 ( struct V_4 * V_585 , V_22 * V_586 )
{
struct V_4 * V_51 [ V_587 + 1 ] ;
int V_588 ;
* V_586 = 0 ;
if ( ! V_585 )
return - V_16 ;
if ( F_33 ( V_51 , V_587 ,
V_585 , V_589 ) )
return - V_16 ;
for ( V_588 = 1 ; V_588 <= V_587 ; V_588 ++ )
if ( V_51 [ V_588 ] )
* V_586 |= ( 1 << V_588 ) ;
return 0 ;
}
static int F_110 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_590 ,
enum V_269 V_141 )
{
if ( ! V_590 ) {
if ( V_19 && ( V_19 -> V_591 & V_592 ) )
return - V_530 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_51 & V_593 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_51 & V_594 )
return 0 ;
break;
default:
break;
}
return - V_526 ;
}
static int F_111 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_595 V_137 ;
int V_35 ;
enum V_269 V_596 , V_597 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
V_22 V_598 , * V_51 = NULL ;
bool V_599 = false ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_596 = V_597 = V_525 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_572 ] ) {
V_597 = F_4 ( V_30 -> V_5 [ V_572 ] ) ;
if ( V_596 != V_597 )
V_599 = true ;
if ( V_597 > V_600 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_601 ] ) {
struct V_1 * V_17 = V_525 -> V_28 ;
if ( V_597 != V_145 )
return - V_16 ;
if ( F_91 ( V_525 ) )
return - V_530 ;
F_112 ( V_17 ) ;
F_113 ( V_602 !=
V_603 ) ;
V_17 -> V_604 =
F_24 ( V_30 -> V_5 [ V_601 ] ) ;
memcpy ( V_17 -> V_578 , F_23 ( V_30 -> V_5 [ V_601 ] ) ,
V_17 -> V_604 ) ;
F_114 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_605 ] ) {
V_137 . V_590 = ! ! F_34 ( V_30 -> V_5 [ V_605 ] ) ;
V_599 = true ;
V_35 = F_110 ( V_7 , V_525 , V_137 . V_590 , V_597 ) ;
if ( V_35 )
return V_35 ;
} else {
V_137 . V_590 = - 1 ;
}
if ( V_30 -> V_5 [ V_606 ] ) {
if ( V_597 != V_153 )
return - V_16 ;
V_35 = F_109 ( V_30 -> V_5 [ V_606 ] ,
& V_598 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_598 ;
V_599 = true ;
}
if ( V_51 && ( * V_51 & V_607 ) &&
! ( V_7 -> V_18 . V_288 & V_608 ) )
return - V_526 ;
if ( V_599 )
V_35 = F_115 ( V_7 , V_525 , V_597 , V_51 , & V_137 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_137 . V_590 != - 1 )
V_525 -> V_28 -> V_590 = V_137 . V_590 ;
return V_35 ;
}
static int F_116 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_595 V_137 ;
struct V_1 * V_17 ;
struct V_31 * V_53 , * V_609 ;
int V_35 ;
enum V_269 type = V_151 ;
V_22 V_51 ;
F_117 ( V_7 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_570 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_572 ] ) {
type = F_4 ( V_30 -> V_5 [ V_572 ] ) ;
if ( type > V_600 )
return - V_16 ;
}
if ( ! V_7 -> V_342 -> V_360 ||
! ( V_7 -> V_18 . V_350 & ( 1 << type ) ) )
return - V_526 ;
if ( ( type == V_154 ||
V_7 -> V_18 . V_288 & V_610 ) &&
V_30 -> V_5 [ V_533 ] ) {
F_118 ( V_137 . V_611 , V_30 -> V_5 [ V_533 ] ,
V_573 ) ;
if ( ! F_119 ( V_137 . V_611 ) )
return - V_612 ;
}
if ( V_30 -> V_5 [ V_605 ] ) {
V_137 . V_590 = ! ! F_34 ( V_30 -> V_5 [ V_605 ] ) ;
V_35 = F_110 ( V_7 , NULL , V_137 . V_590 , type ) ;
if ( V_35 )
return V_35 ;
}
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_35 = F_109 ( type == V_153 ?
V_30 -> V_5 [ V_606 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_607 ) &&
! ( V_7 -> V_18 . V_288 & V_608 ) )
return - V_526 ;
V_17 = F_120 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_570 ] ) ,
type , V_35 ? NULL : & V_51 , & V_137 ) ;
if ( F_59 ( ! V_17 ) ) {
F_75 ( V_53 ) ;
return - V_613 ;
} else if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_614 ] )
V_17 -> V_615 = V_30 -> V_490 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_601 ] )
break;
F_112 ( V_17 ) ;
F_113 ( V_602 !=
V_603 ) ;
V_17 -> V_604 =
F_24 ( V_30 -> V_5 [ V_601 ] ) ;
memcpy ( V_17 -> V_578 , F_23 ( V_30 -> V_5 [ V_601 ] ) ,
V_17 -> V_604 ) ;
F_114 ( V_17 ) ;
break;
case V_154 :
F_121 ( & V_17 -> V_616 ) ;
F_122 ( & V_17 -> V_617 ) ;
F_123 ( & V_17 -> V_618 ) ;
F_122 ( & V_17 -> V_619 ) ;
F_123 ( & V_17 -> V_620 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_124 ( & V_17 -> V_621 , & V_7 -> V_622 ) ;
V_7 -> V_574 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
V_609 = F_74 ( V_584 , V_135 ) ;
if ( V_609 ) {
if ( F_103 ( V_609 , 0 , 0 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_609 ) ;
goto V_583;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_609 , 0 , V_623 ,
V_135 ) ;
}
V_583:
return F_76 ( V_53 , V_30 ) ;
}
static int F_126 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
struct V_31 * V_53 ;
int V_624 ;
if ( ! V_7 -> V_342 -> V_625 )
return - V_526 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( V_53 && F_103 ( V_53 , 0 , 0 , 0 , V_7 , V_17 , true ) < 0 ) {
F_75 ( V_53 ) ;
V_53 = NULL ;
}
if ( ! V_17 -> V_19 )
V_30 -> V_489 [ 1 ] = NULL ;
V_624 = F_127 ( V_7 , V_17 ) ;
if ( V_624 >= 0 && V_53 )
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_623 ,
V_135 ) ;
else
F_75 ( V_53 ) ;
return V_624 ;
}
static int F_128 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_3 V_626 ;
if ( ! V_30 -> V_5 [ V_627 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_418 )
return - V_526 ;
V_626 = F_78 ( V_30 -> V_5 [ V_627 ] ) ;
return F_129 ( V_7 , V_525 , V_626 ) ;
}
static void F_130 ( void * V_165 , struct V_628 * V_137 )
{
struct V_4 * V_92 ;
struct V_629 * V_630 = V_165 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_630 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_630 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_630 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_630 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_630 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_630 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_630 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_630 -> V_53 , V_123 , V_630 -> V_105 ) )
goto V_61;
F_48 ( V_630 -> V_53 , V_92 ) ;
return;
V_61:
V_630 -> error = 1 ;
}
static int F_131 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
int V_35 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 V_631 = 0 ;
const T_2 * V_632 = NULL ;
bool V_633 ;
struct V_629 V_630 = {
. error = 0 ,
} ;
void * V_280 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_631 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_631 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_533 ] )
V_632 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_633 = ! ! V_632 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_634 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_634 >= V_114 )
return - V_16 ;
if ( V_634 != V_635 &&
V_634 != V_636 )
return - V_16 ;
V_633 = V_634 == V_636 ;
}
if ( ! V_7 -> V_342 -> V_637 )
return - V_526 ;
if ( ! V_633 && V_632 && ! ( V_7 -> V_18 . V_51 & V_315 ) )
return - V_638 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_639 ) ;
if ( ! V_280 )
goto V_61;
V_630 . V_53 = V_53 ;
V_630 . V_105 = V_631 ;
if ( F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_631 ) )
goto V_61;
if ( V_632 &&
F_51 ( V_53 , V_533 , V_573 , V_632 ) )
goto V_61;
V_35 = F_132 ( V_7 , V_525 , V_631 , V_633 , V_632 , & V_630 ,
F_130 ) ;
if ( V_35 )
goto V_640;
if ( V_630 . error )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_640:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_133 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_112 ( V_525 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_342 -> V_641 ) {
V_35 = - V_526 ;
goto V_583;
}
V_35 = F_42 ( V_525 -> V_28 ) ;
if ( V_35 )
goto V_583;
V_35 = F_134 ( V_7 , V_525 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_583;
#ifdef F_135
V_525 -> V_28 -> V_642 . V_643 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_583;
}
if ( ! V_7 -> V_342 -> V_644 ) {
V_35 = - V_526 ;
goto V_583;
}
V_35 = F_42 ( V_525 -> V_28 ) ;
if ( V_35 )
goto V_583;
V_35 = F_136 ( V_7 , V_525 , V_92 . V_105 ) ;
if ( V_35 )
goto V_583;
#ifdef F_135
V_525 -> V_28 -> V_642 . V_645 = V_92 . V_105 ;
#endif
}
V_583:
F_114 ( V_525 -> V_28 ) ;
return V_35 ;
}
static int F_137 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
int V_35 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_632 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_533 ] )
V_632 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_632 )
V_92 . type = V_636 ;
else
V_92 . type = V_635 ;
}
if ( V_92 . type != V_636 &&
V_92 . type != V_635 )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_364 )
return - V_526 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_636 ,
V_632 ) )
return - V_16 ;
F_112 ( V_525 -> V_28 ) ;
V_35 = F_42 ( V_525 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_138 ( V_7 , V_525 , V_92 . V_105 ,
V_92 . type == V_636 ,
V_632 , & V_92 . V_107 ) ;
F_114 ( V_525 -> V_28 ) ;
return V_35 ;
}
static int F_139 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
int V_35 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 * V_632 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_533 ] )
V_632 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_632 )
V_92 . type = V_636 ;
else
V_92 . type = V_635 ;
}
if ( V_92 . type != V_636 &&
V_92 . type != V_635 )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_646 )
return - V_526 ;
F_112 ( V_525 -> V_28 ) ;
V_35 = F_42 ( V_525 -> V_28 ) ;
if ( V_92 . type == V_635 && V_632 &&
! ( V_7 -> V_18 . V_51 & V_315 ) )
V_35 = - V_638 ;
if ( ! V_35 )
V_35 = F_140 ( V_7 , V_525 , V_92 . V_105 ,
V_92 . type == V_636 ,
V_632 ) ;
#ifdef F_135
if ( ! V_35 ) {
if ( V_92 . V_105 == V_525 -> V_28 -> V_642 . V_643 )
V_525 -> V_28 -> V_642 . V_643 = - 1 ;
else if ( V_92 . V_105 == V_525 -> V_28 -> V_642 . V_645 )
V_525 -> V_28 -> V_642 . V_645 = - 1 ;
}
#endif
F_114 ( V_525 -> V_28 ) ;
return V_35 ;
}
static int F_141 ( struct V_4 * V_647 )
{
struct V_4 * V_45 ;
int V_648 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_573 )
return - V_16 ;
V_648 ++ ;
}
return V_648 ;
}
static struct V_649 * F_142 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_650 V_651 ;
struct V_4 * V_45 ;
struct V_649 * V_652 ;
int V_159 = 0 , V_648 , V_24 ;
if ( ! V_18 -> V_457 )
return F_3 ( - V_526 ) ;
if ( ! V_30 -> V_5 [ V_653 ] )
return F_3 ( - V_16 ) ;
V_651 = F_4 ( V_30 -> V_5 [ V_653 ] ) ;
if ( V_651 != V_654 &&
V_651 != V_655 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_656 ] )
return F_3 ( - V_16 ) ;
V_648 = F_141 ( V_30 -> V_5 [ V_656 ] ) ;
if ( V_648 < 0 )
return F_3 ( V_648 ) ;
if ( V_648 > V_18 -> V_457 )
return F_3 ( - V_657 ) ;
V_652 = F_38 ( sizeof( * V_652 ) + ( sizeof( struct V_658 ) * V_648 ) ,
V_135 ) ;
if ( ! V_652 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_652 -> V_659 [ V_159 ] . V_660 , F_23 ( V_45 ) , V_573 ) ;
V_159 ++ ;
}
V_652 -> V_661 = V_648 ;
V_652 -> V_651 = V_651 ;
return V_652 ;
}
static int F_143 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_649 * V_652 ;
int V_35 ;
if ( V_525 -> V_28 -> V_141 != V_142 &&
V_525 -> V_28 -> V_141 != V_144 )
return - V_526 ;
if ( ! V_525 -> V_28 -> V_527 )
return - V_16 ;
V_652 = F_142 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_652 ) )
return F_18 ( V_652 ) ;
V_35 = F_144 ( V_7 , V_525 , V_652 ) ;
F_41 ( V_652 ) ;
return V_35 ;
}
static int F_145 ( struct V_4 * V_5 [] ,
struct V_662 * V_663 )
{
bool V_664 = false ;
if ( ! F_22 ( V_5 [ V_665 ] ) ||
! F_22 ( V_5 [ V_666 ] ) ||
! F_22 ( V_5 [ V_667 ] ) ||
! F_22 ( V_5 [ V_668 ] ) )
return - V_16 ;
memset ( V_663 , 0 , sizeof( * V_663 ) ) ;
if ( V_5 [ V_669 ] ) {
V_663 -> V_670 = F_23 ( V_5 [ V_669 ] ) ;
V_663 -> V_671 = F_24 ( V_5 [ V_669 ] ) ;
if ( ! V_663 -> V_671 )
return - V_16 ;
V_664 = true ;
}
if ( V_5 [ V_665 ] ) {
V_663 -> V_672 = F_23 ( V_5 [ V_665 ] ) ;
V_663 -> V_673 = F_24 ( V_5 [ V_665 ] ) ;
V_664 = true ;
}
if ( ! V_664 )
return - V_16 ;
if ( V_5 [ V_666 ] ) {
V_663 -> V_674 = F_23 ( V_5 [ V_666 ] ) ;
V_663 -> V_675 = F_24 ( V_5 [ V_666 ] ) ;
}
if ( V_5 [ V_667 ] ) {
V_663 -> V_676 =
F_23 ( V_5 [ V_667 ] ) ;
V_663 -> V_677 =
F_24 ( V_5 [ V_667 ] ) ;
}
if ( V_5 [ V_668 ] ) {
V_663 -> V_678 =
F_23 ( V_5 [ V_668 ] ) ;
V_663 -> V_679 =
F_24 ( V_5 [ V_668 ] ) ;
}
if ( V_5 [ V_680 ] ) {
V_663 -> V_681 = F_23 ( V_5 [ V_680 ] ) ;
V_663 -> V_682 = F_24 ( V_5 [ V_680 ] ) ;
}
return 0 ;
}
static bool F_146 ( struct V_6 * V_7 ,
struct V_683 * V_137 )
{
struct V_1 * V_17 ;
bool V_482 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_531 . V_55 )
continue;
V_137 -> V_506 = V_17 -> V_531 ;
V_482 = true ;
break;
}
return V_482 ;
}
static bool F_147 ( struct V_6 * V_7 ,
enum V_684 V_685 ,
enum V_277 V_52 )
{
if ( V_685 > V_686 )
return false ;
switch ( V_52 ) {
case V_687 :
if ( ! ( V_7 -> V_18 . V_288 & V_688 ) &&
V_685 == V_689 )
return false ;
return true ;
case V_441 :
case V_690 :
if ( V_685 == V_689 )
return false ;
return true ;
default:
return false ;
}
}
static int F_148 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_683 V_137 ;
int V_35 ;
if ( V_525 -> V_28 -> V_141 != V_142 &&
V_525 -> V_28 -> V_141 != V_144 )
return - V_526 ;
if ( ! V_7 -> V_342 -> V_366 )
return - V_526 ;
if ( V_17 -> V_527 )
return - V_691 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_692 ] ||
! V_30 -> V_5 [ V_693 ] ||
! V_30 -> V_5 [ V_669 ] )
return - V_16 ;
V_35 = F_145 ( V_30 -> V_5 , & V_137 . V_694 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_527 =
F_4 ( V_30 -> V_5 [ V_692 ] ) ;
V_137 . V_695 =
F_4 ( V_30 -> V_5 [ V_693 ] ) ;
V_35 = F_149 ( V_7 , V_137 . V_527 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_577 ] ) {
V_137 . V_578 = F_23 ( V_30 -> V_5 [ V_577 ] ) ;
V_137 . V_576 =
F_24 ( V_30 -> V_5 [ V_577 ] ) ;
if ( V_137 . V_576 == 0 ||
V_137 . V_576 > V_602 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_696 ] ) {
V_137 . V_697 = F_4 (
V_30 -> V_5 [ V_696 ] ) ;
if ( V_137 . V_697 != V_698 &&
V_137 . V_697 != V_699 &&
V_137 . V_697 != V_700 )
return - V_16 ;
}
V_137 . V_701 = ! ! V_30 -> V_5 [ V_702 ] ;
if ( V_30 -> V_5 [ V_703 ] ) {
V_137 . V_685 = F_4 (
V_30 -> V_5 [ V_703 ] ) ;
if ( ! F_147 ( V_7 , V_137 . V_685 ,
V_690 ) )
return - V_16 ;
} else
V_137 . V_685 = V_704 ;
V_35 = F_150 ( V_7 , V_30 , & V_137 . V_705 ,
V_706 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_707 ] ) {
if ( ! ( V_7 -> V_18 . V_288 & V_708 ) )
return - V_526 ;
V_137 . V_709 = F_78 (
V_30 -> V_5 [ V_707 ] ) ;
}
if ( V_30 -> V_5 [ V_710 ] ) {
if ( V_525 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_711 =
F_34 ( V_30 -> V_5 [ V_710 ] ) ;
if ( V_137 . V_711 > 127 )
return - V_16 ;
if ( V_137 . V_711 != 0 &&
! ( V_7 -> V_18 . V_288 & V_712 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_713 ] ) {
T_2 V_24 ;
if ( V_525 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_713 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_714 = V_24 ;
if ( V_137 . V_714 != 0 &&
! ( V_7 -> V_18 . V_288 & V_715 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_508 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_506 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_531 . V_55 ) {
V_137 . V_506 = V_17 -> V_531 ;
} else if ( ! F_146 ( V_7 , & V_137 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_506 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_653 ] ) {
V_137 . V_652 = F_142 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_652 ) )
return F_18 ( V_137 . V_652 ) ;
}
if ( V_30 -> V_5 [ V_716 ] ) {
V_137 . V_717 =
F_34 ( V_30 -> V_5 [ V_716 ] ) ;
switch ( V_137 . V_717 ) {
case V_718 :
break;
case V_719 :
if ( ! ( V_7 -> V_18 . V_288 &
V_720 ) )
return - V_16 ;
break;
case V_721 :
if ( ! ( V_7 -> V_18 . V_288 &
V_722 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_137 . V_717 = V_718 ;
}
F_112 ( V_17 ) ;
V_35 = F_151 ( V_7 , V_525 , & V_137 ) ;
if ( ! V_35 ) {
V_17 -> V_531 = V_137 . V_506 ;
V_17 -> V_527 = V_137 . V_527 ;
V_17 -> V_506 = V_137 . V_506 ;
V_17 -> V_576 = V_137 . V_576 ;
memcpy ( V_17 -> V_578 , V_137 . V_578 , V_17 -> V_576 ) ;
}
F_114 ( V_17 ) ;
F_41 ( V_137 . V_652 ) ;
return V_35 ;
}
static int F_152 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_662 V_137 ;
int V_35 ;
if ( V_525 -> V_28 -> V_141 != V_142 &&
V_525 -> V_28 -> V_141 != V_144 )
return - V_526 ;
if ( ! V_7 -> V_342 -> V_723 )
return - V_526 ;
if ( ! V_17 -> V_527 )
return - V_16 ;
V_35 = F_145 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
V_35 = F_153 ( V_7 , V_525 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_154 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
return F_155 ( V_7 , V_525 , false ) ;
}
static int F_156 ( struct V_29 * V_30 ,
enum V_269 V_141 ,
struct V_724 * V_137 )
{
struct V_4 * V_51 [ V_725 + 1 ] ;
struct V_4 * V_585 ;
int V_588 ;
V_585 = V_30 -> V_5 [ V_726 ] ;
if ( V_585 ) {
struct V_727 * V_728 ;
V_728 = F_23 ( V_585 ) ;
V_137 -> V_729 = V_728 -> V_730 ;
V_137 -> V_731 = V_728 -> V_732 ;
V_137 -> V_731 &= V_137 -> V_729 ;
if ( ( V_137 -> V_729 |
V_137 -> V_731 ) & F_157 ( V_733 ) )
return - V_16 ;
return 0 ;
}
V_585 = V_30 -> V_5 [ V_734 ] ;
if ( ! V_585 )
return 0 ;
if ( F_33 ( V_51 , V_725 ,
V_585 , V_735 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_729 = F_157 ( V_736 ) |
F_157 ( V_737 ) |
F_157 ( V_738 ) |
F_157 ( V_739 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_729 = F_157 ( V_736 ) |
F_157 ( V_740 ) ;
break;
case V_145 :
V_137 -> V_729 = F_157 ( V_741 ) |
F_157 ( V_739 ) |
F_157 ( V_736 ) ;
default:
return - V_16 ;
}
for ( V_588 = 1 ; V_588 <= V_725 ; V_588 ++ ) {
if ( V_51 [ V_588 ] ) {
V_137 -> V_731 |= ( 1 << V_588 ) ;
if ( V_588 > V_742 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_158 ( struct V_31 * V_53 , struct V_743 * V_30 ,
int V_45 )
{
struct V_4 * V_241 ;
V_22 V_261 ;
T_3 V_744 ;
V_241 = F_47 ( V_53 , V_45 ) ;
if ( ! V_241 )
return false ;
V_261 = F_159 ( V_30 ) ;
V_744 = V_261 < ( 1UL << 16 ) ? V_261 : 0 ;
if ( V_261 > 0 &&
F_28 ( V_53 , V_745 , V_261 ) )
return false ;
if ( V_744 > 0 &&
F_55 ( V_53 , V_746 , V_744 ) )
return false ;
if ( V_30 -> V_51 & V_747 ) {
if ( F_56 ( V_53 , V_748 , V_30 -> V_245 ) )
return false ;
if ( V_30 -> V_51 & V_749 &&
F_29 ( V_53 , V_750 ) )
return false ;
if ( V_30 -> V_51 & V_751 &&
F_29 ( V_53 , V_752 ) )
return false ;
} else if ( V_30 -> V_51 & V_753 ) {
if ( F_56 ( V_53 , V_754 , V_30 -> V_245 ) )
return false ;
if ( F_56 ( V_53 , V_755 , V_30 -> V_756 ) )
return false ;
if ( V_30 -> V_51 & V_749 &&
F_29 ( V_53 , V_750 ) )
return false ;
if ( V_30 -> V_51 & V_757 &&
F_29 ( V_53 , V_758 ) )
return false ;
if ( V_30 -> V_51 & V_759 &&
F_29 ( V_53 , V_760 ) )
return false ;
if ( V_30 -> V_51 & V_761 &&
F_29 ( V_53 , V_762 ) )
return false ;
if ( V_30 -> V_51 & V_751 &&
F_29 ( V_53 , V_752 ) )
return false ;
}
F_48 ( V_53 , V_241 ) ;
return true ;
}
static bool F_160 ( struct V_31 * V_53 , T_2 V_730 , T_6 * signal ,
int V_763 )
{
void * V_45 ;
int V_159 = 0 ;
if ( ! V_730 )
return true ;
V_45 = F_47 ( V_53 , V_763 ) ;
if ( ! V_45 )
return false ;
for ( V_159 = 0 ; V_159 < V_764 ; V_159 ++ ) {
if ( ! ( V_730 & F_157 ( V_159 ) ) )
continue;
if ( F_56 ( V_53 , V_159 , signal [ V_159 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_161 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_525 ,
const T_2 * V_632 , struct V_765 * V_766 )
{
void * V_280 ;
struct V_4 * V_767 , * V_768 ;
V_280 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_769 ) ;
if ( ! V_280 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_632 ) ||
F_28 ( V_53 , V_290 , V_766 -> V_770 ) )
goto V_61;
V_767 = F_47 ( V_53 , V_771 ) ;
if ( ! V_767 )
goto V_61;
if ( ( V_766 -> V_772 & V_773 ) &&
F_28 ( V_53 , V_774 ,
V_766 -> V_775 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_776 ) &&
F_28 ( V_53 , V_777 ,
V_766 -> V_778 ) )
goto V_61;
if ( ( V_766 -> V_772 & ( V_779 |
V_780 ) ) &&
F_28 ( V_53 , V_781 ,
( V_22 ) V_766 -> V_782 ) )
goto V_61;
if ( ( V_766 -> V_772 & ( V_783 |
V_784 ) ) &&
F_28 ( V_53 , V_785 ,
( V_22 ) V_766 -> V_786 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_780 ) &&
F_104 ( V_53 , V_787 ,
V_766 -> V_782 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_784 ) &&
F_104 ( V_53 , V_788 ,
V_766 -> V_786 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_789 ) &&
F_55 ( V_53 , V_790 , V_766 -> V_791 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_792 ) &&
F_55 ( V_53 , V_793 , V_766 -> V_794 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_795 ) &&
F_56 ( V_53 , V_796 ,
V_766 -> V_797 ) )
goto V_61;
switch ( V_7 -> V_18 . V_798 ) {
case V_799 :
if ( ( V_766 -> V_772 & V_800 ) &&
F_56 ( V_53 , V_801 ,
V_766 -> signal ) )
goto V_61;
if ( ( V_766 -> V_772 & V_802 ) &&
F_56 ( V_53 , V_803 ,
V_766 -> V_804 ) )
goto V_61;
break;
default:
break;
}
if ( V_766 -> V_772 & V_805 ) {
if ( ! F_160 ( V_53 , V_766 -> V_806 ,
V_766 -> V_807 ,
V_808 ) )
goto V_61;
}
if ( V_766 -> V_772 & V_809 ) {
if ( ! F_160 ( V_53 , V_766 -> V_806 ,
V_766 -> V_810 ,
V_811 ) )
goto V_61;
}
if ( V_766 -> V_772 & V_812 ) {
if ( ! F_158 ( V_53 , & V_766 -> V_813 ,
V_814 ) )
goto V_61;
}
if ( V_766 -> V_772 & V_815 ) {
if ( ! F_158 ( V_53 , & V_766 -> V_816 ,
V_817 ) )
goto V_61;
}
if ( ( V_766 -> V_772 & V_818 ) &&
F_28 ( V_53 , V_819 ,
V_766 -> V_820 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_821 ) &&
F_28 ( V_53 , V_822 ,
V_766 -> V_823 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_824 ) &&
F_28 ( V_53 , V_825 ,
V_766 -> V_826 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_827 ) &&
F_28 ( V_53 , V_828 ,
V_766 -> V_829 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_830 ) &&
F_28 ( V_53 , V_831 ,
V_766 -> V_832 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_833 ) &&
F_28 ( V_53 , V_834 ,
V_766 -> V_835 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_836 ) &&
F_28 ( V_53 , V_837 ,
V_766 -> V_838 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_839 ) &&
F_28 ( V_53 , V_840 ,
V_766 -> V_841 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_842 ) &&
F_28 ( V_53 , V_843 ,
V_766 -> V_844 ) )
goto V_61;
if ( V_766 -> V_772 & V_845 ) {
V_768 = F_47 ( V_53 , V_846 ) ;
if ( ! V_768 )
goto V_61;
if ( ( ( V_766 -> V_768 . V_51 & V_847 ) &&
F_29 ( V_53 , V_848 ) ) ||
( ( V_766 -> V_768 . V_51 & V_849 ) &&
F_29 ( V_53 , V_850 ) ) ||
( ( V_766 -> V_768 . V_51 & V_851 ) &&
F_29 ( V_53 , V_852 ) ) ||
F_56 ( V_53 , V_853 ,
V_766 -> V_768 . V_695 ) ||
F_55 ( V_53 , V_854 ,
V_766 -> V_768 . V_527 ) )
goto V_61;
F_48 ( V_53 , V_768 ) ;
}
if ( ( V_766 -> V_772 & V_855 ) &&
F_51 ( V_53 , V_856 ,
sizeof( struct V_727 ) ,
& V_766 -> V_728 ) )
goto V_61;
if ( ( V_766 -> V_772 & V_857 ) &&
F_104 ( V_53 , V_858 ,
V_766 -> V_859 ) )
goto V_61;
F_48 ( V_53 , V_767 ) ;
if ( ( V_766 -> V_772 & V_860 ) &&
F_51 ( V_53 , V_666 , V_766 -> V_861 ,
V_766 -> V_862 ) )
goto V_61;
return F_66 ( V_53 , V_280 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
static int F_162 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_765 V_766 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_632 [ V_573 ] ;
int V_863 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_864;
}
if ( ! V_7 -> V_342 -> V_865 ) {
V_35 = - V_526 ;
goto V_864;
}
while ( 1 ) {
memset ( & V_766 , 0 , sizeof( V_766 ) ) ;
V_35 = F_163 ( V_7 , V_17 -> V_19 , V_863 ,
V_632 , & V_766 ) ;
if ( V_35 == - V_638 )
break;
if ( V_35 )
goto V_864;
if ( F_161 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_486 , V_487 ,
V_7 , V_17 -> V_19 , V_632 ,
& V_766 ) < 0 )
goto V_583;
V_863 ++ ;
}
V_583:
V_34 -> args [ 2 ] = V_863 ;
V_35 = V_32 -> V_47 ;
V_864:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_164 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_765 V_766 ;
struct V_31 * V_53 ;
T_2 * V_632 = NULL ;
int V_35 ;
memset ( & V_766 , 0 , sizeof( V_766 ) ) ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_632 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( ! V_7 -> V_342 -> V_866 )
return - V_526 ;
V_35 = F_165 ( V_7 , V_525 , V_632 , & V_766 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_161 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_7 , V_525 , V_632 , & V_766 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_166 ( struct V_18 * V_18 ,
struct V_724 * V_137 ,
enum V_867 V_868 )
{
if ( V_137 -> V_869 != - 1 )
return - V_16 ;
if ( V_137 -> V_870 &&
! ( V_137 -> V_731 & F_157 ( V_740 ) ) )
return - V_16 ;
F_113 ( V_725 != 7 ) ;
switch ( V_868 ) {
case V_871 :
case V_872 :
if ( V_137 -> V_729 &
~ ( F_157 ( V_741 ) |
F_157 ( V_739 ) |
F_157 ( V_736 ) ) )
return - V_16 ;
break;
case V_873 :
case V_874 :
if ( ! ( V_137 -> V_731 & F_157 ( V_740 ) ) )
return - V_16 ;
V_137 -> V_729 &= ~ F_157 ( V_740 ) ;
break;
default:
if ( V_137 -> V_875 != V_876 )
return - V_16 ;
if ( V_137 -> V_838 )
return - V_16 ;
if ( V_137 -> V_877 & V_878 )
return - V_16 ;
}
if ( V_868 != V_873 &&
V_868 != V_874 ) {
if ( V_137 -> V_731 & F_157 ( V_740 ) )
return - V_16 ;
V_137 -> V_729 &= ~ F_157 ( V_740 ) ;
}
if ( V_868 != V_873 ) {
if ( V_137 -> V_877 & V_879 )
return - V_16 ;
if ( V_137 -> V_877 & V_880 )
return - V_16 ;
if ( V_137 -> V_881 )
return - V_16 ;
if ( V_137 -> V_882 || V_137 -> V_883 || V_137 -> V_884 )
return - V_16 ;
}
if ( V_868 != V_885 ) {
if ( V_137 -> V_886 )
return - V_16 ;
}
switch ( V_868 ) {
case V_887 :
if ( ! ( V_137 -> V_729 & F_157 ( V_736 ) ) )
return - V_526 ;
break;
case V_885 :
if ( V_137 -> V_729 &
~ ( F_157 ( V_736 ) |
F_157 ( V_741 ) |
F_157 ( V_888 ) |
F_157 ( V_737 ) |
F_157 ( V_738 ) |
F_157 ( V_739 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_288 & V_889 ) &&
V_137 -> V_729 &
( F_157 ( V_741 ) |
F_157 ( V_888 ) ) )
return - V_16 ;
break;
case V_890 :
case V_891 :
if ( V_137 -> V_729 & ~ F_157 ( V_736 ) )
return - V_16 ;
break;
case V_873 :
if ( V_137 -> V_729 & ~ ( F_157 ( V_736 ) |
F_157 ( V_738 ) ) )
return - V_16 ;
if ( V_137 -> V_731 & F_157 ( V_736 ) &&
! V_137 -> V_881 )
return - V_16 ;
break;
case V_874 :
return - V_16 ;
case V_871 :
if ( V_137 -> V_877 & V_878 )
return - V_16 ;
break;
case V_872 :
if ( V_137 -> V_875 != V_876 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_167 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_892 = V_30 -> V_5 [ V_893 ] ;
struct V_25 * V_894 ;
int V_482 ;
if ( ! V_892 )
return NULL ;
V_894 = F_168 ( F_94 ( V_30 ) , F_4 ( V_892 ) ) ;
if ( ! V_894 )
return F_3 ( - V_23 ) ;
if ( ! V_894 -> V_28 || V_894 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_482 = - V_16 ;
goto error;
}
if ( V_894 -> V_28 -> V_141 != V_143 &&
V_894 -> V_28 -> V_141 != V_142 &&
V_894 -> V_28 -> V_141 != V_144 ) {
V_482 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_894 ) ) {
V_482 = - V_540 ;
goto error;
}
return V_894 ;
error:
F_169 ( V_894 ) ;
return F_3 ( V_482 ) ;
}
static int F_170 ( struct V_29 * V_30 ,
struct V_724 * V_137 )
{
struct V_4 * V_95 [ V_895 + 1 ] ;
struct V_4 * V_585 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_896 ] )
return 0 ;
V_585 = V_30 -> V_5 [ V_896 ] ;
V_35 = F_33 ( V_95 , V_895 , V_585 ,
V_897 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_898 ] )
V_137 -> V_899 = F_34 (
V_95 [ V_898 ] ) ;
if ( V_137 -> V_899 & ~ V_900 )
return - V_16 ;
if ( V_95 [ V_901 ] )
V_137 -> V_902 = F_34 ( V_95 [ V_901 ] ) ;
if ( V_137 -> V_902 & ~ V_903 )
return - V_16 ;
V_137 -> V_877 |= V_879 ;
return 0 ;
}
static int F_171 ( struct V_29 * V_30 ,
struct V_724 * V_137 )
{
if ( V_30 -> V_5 [ V_904 ] ) {
V_137 -> V_905 =
F_23 ( V_30 -> V_5 [ V_904 ] ) ;
V_137 -> V_906 =
F_24 ( V_30 -> V_5 [ V_904 ] ) ;
if ( V_137 -> V_906 < 2 )
return - V_16 ;
if ( V_137 -> V_906 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_907 ] ) {
V_137 -> V_908 =
F_23 ( V_30 -> V_5 [ V_907 ] ) ;
V_137 -> V_909 =
F_24 ( V_30 -> V_5 [ V_907 ] ) ;
if ( V_137 -> V_909 < 2 ||
V_137 -> V_909 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_172 ( struct V_29 * V_30 ,
struct V_724 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_910 ] )
V_137 -> V_870 = F_78 ( V_30 -> V_5 [ V_910 ] ) ;
if ( V_30 -> V_5 [ V_911 ] )
V_137 -> V_883 =
F_23 ( V_30 -> V_5 [ V_911 ] ) ;
if ( V_30 -> V_5 [ V_912 ] )
V_137 -> V_884 =
F_23 ( V_30 -> V_5 [ V_912 ] ) ;
V_35 = F_171 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_170 ( V_30 , V_137 ) ;
}
static int F_173 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_724 V_137 ;
T_2 * V_632 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_869 = - 1 ;
if ( ! V_7 -> V_342 -> V_913 )
return - V_526 ;
if ( V_30 -> V_5 [ V_914 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_632 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( V_30 -> V_5 [ V_915 ] ) {
V_137 . V_881 =
F_23 ( V_30 -> V_5 [ V_915 ] ) ;
V_137 . V_916 =
F_24 ( V_30 -> V_5 [ V_915 ] ) ;
}
if ( V_30 -> V_5 [ V_917 ] ) {
V_137 . V_918 =
F_78 ( V_30 -> V_5 [ V_917 ] ) ;
V_137 . V_877 |= V_880 ;
}
if ( V_30 -> V_5 [ V_919 ] ) {
V_137 . V_882 =
F_23 ( V_30 -> V_5 [ V_919 ] ) ;
V_137 . V_920 =
F_24 ( V_30 -> V_5 [ V_919 ] ) ;
}
if ( V_30 -> V_5 [ V_921 ] )
return - V_16 ;
if ( F_156 ( V_30 , V_525 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_922 ] ) {
V_137 . V_875 =
F_34 ( V_30 -> V_5 [ V_922 ] ) ;
if ( V_137 . V_875 >= V_923 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_924 ] ) {
V_137 . V_797 =
F_34 ( V_30 -> V_5 [ V_924 ] ) ;
if ( V_137 . V_797 >= V_925 )
return - V_16 ;
V_137 . V_877 |= V_878 ;
}
if ( V_30 -> V_5 [ V_926 ] ) {
enum V_927 V_928 = F_4 (
V_30 -> V_5 [ V_926 ] ) ;
if ( V_928 <= V_929 ||
V_928 > V_930 )
return - V_16 ;
V_137 . V_838 = V_928 ;
}
V_35 = F_172 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_886 = F_167 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_886 ) )
return F_18 ( V_137 . V_886 ) ;
switch ( V_525 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_526 ;
goto V_931;
}
V_35 = F_174 ( V_7 , V_525 , V_632 , & V_137 ) ;
V_931:
if ( V_137 . V_886 )
F_169 ( V_137 . V_886 ) ;
return V_35 ;
}
static int F_175 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
int V_35 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_724 V_137 ;
T_2 * V_632 = NULL ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_342 -> V_368 )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_921 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_915 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_914 ] &&
! V_30 -> V_5 [ V_910 ] )
return - V_16 ;
V_632 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_137 . V_881 =
F_23 ( V_30 -> V_5 [ V_915 ] ) ;
V_137 . V_916 =
F_24 ( V_30 -> V_5 [ V_915 ] ) ;
V_137 . V_869 =
F_78 ( V_30 -> V_5 [ V_921 ] ) ;
if ( V_30 -> V_5 [ V_910 ] )
V_137 . V_870 = F_78 ( V_30 -> V_5 [ V_910 ] ) ;
else
V_137 . V_870 = F_78 ( V_30 -> V_5 [ V_914 ] ) ;
if ( ! V_137 . V_870 || V_137 . V_870 > V_932 )
return - V_16 ;
if ( V_30 -> V_5 [ V_917 ] ) {
V_137 . V_918 =
F_78 ( V_30 -> V_5 [ V_917 ] ) ;
V_137 . V_877 |= V_880 ;
}
if ( V_30 -> V_5 [ V_919 ] ) {
V_137 . V_882 =
F_23 ( V_30 -> V_5 [ V_919 ] ) ;
V_137 . V_920 =
F_24 ( V_30 -> V_5 [ V_919 ] ) ;
}
if ( V_30 -> V_5 [ V_911 ] )
V_137 . V_883 =
F_23 ( V_30 -> V_5 [ V_911 ] ) ;
if ( V_30 -> V_5 [ V_912 ] )
V_137 . V_884 =
F_23 ( V_30 -> V_5 [ V_912 ] ) ;
if ( V_30 -> V_5 [ V_933 ] ) {
V_137 . V_934 = true ;
V_137 . V_935 =
F_34 ( V_30 -> V_5 [ V_933 ] ) ;
}
if ( V_30 -> V_5 [ V_922 ] ) {
V_137 . V_875 =
F_34 ( V_30 -> V_5 [ V_922 ] ) ;
if ( V_137 . V_875 >= V_923 )
return - V_16 ;
}
V_35 = F_171 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_170 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_156 ( V_30 , V_525 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
F_113 ( V_725 != 7 ) ;
switch ( V_525 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_319 ) ||
! ( V_137 . V_731 & F_157 ( V_738 ) ) )
V_137 . V_877 &= ~ V_879 ;
if ( ( V_137 . V_731 & F_157 ( V_740 ) ) ||
V_30 -> V_5 [ V_910 ] )
return - V_16 ;
V_137 . V_729 &= ~ F_157 ( V_740 ) ;
if ( ! ( V_7 -> V_18 . V_288 &
V_889 ) &&
V_137 . V_729 &
( F_157 ( V_741 ) |
F_157 ( V_888 ) ) )
return - V_16 ;
V_137 . V_886 = F_167 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_886 ) )
return F_18 ( V_137 . V_886 ) ;
break;
case V_145 :
V_137 . V_877 &= ~ V_879 ;
if ( V_137 . V_729 & F_157 ( V_888 ) )
return - V_16 ;
if ( ( V_137 . V_731 & F_157 ( V_740 ) ) ||
V_30 -> V_5 [ V_910 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_877 &= ~ V_879 ;
if ( V_137 . V_729 &
( F_157 ( V_888 ) |
F_157 ( V_741 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_731 & F_157 ( V_740 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_323 ) )
return - V_526 ;
if ( ! ( V_7 -> V_18 . V_51 & V_325 ) )
return - V_526 ;
V_137 . V_729 &= ~ F_157 ( V_736 ) ;
break;
default:
return - V_526 ;
}
V_35 = F_176 ( V_7 , V_525 , V_632 , & V_137 ) ;
if ( V_137 . V_886 )
F_169 ( V_137 . V_886 ) ;
return V_35 ;
}
static int F_177 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_936 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( V_30 -> V_5 [ V_533 ] )
V_137 . V_937 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( V_525 -> V_28 -> V_141 != V_142 &&
V_525 -> V_28 -> V_141 != V_143 &&
V_525 -> V_28 -> V_141 != V_145 &&
V_525 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_938 )
return - V_526 ;
if ( V_30 -> V_5 [ V_939 ] ) {
V_137 . V_940 =
F_34 ( V_30 -> V_5 [ V_939 ] ) ;
if ( V_137 . V_940 != V_941 >> 4 &&
V_137 . V_940 != V_942 >> 4 )
return - V_16 ;
} else {
V_137 . V_940 = V_942 >> 4 ;
}
if ( V_30 -> V_5 [ V_943 ] ) {
V_137 . V_944 =
F_78 ( V_30 -> V_5 [ V_943 ] ) ;
if ( V_137 . V_944 == 0 )
return - V_16 ;
} else {
V_137 . V_944 = V_945 ;
}
return F_178 ( V_7 , V_525 , & V_137 ) ;
}
static int F_179 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_525 ,
T_2 * V_946 , T_2 * V_947 ,
struct V_948 * V_949 )
{
void * V_280 ;
struct V_4 * V_950 ;
V_280 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_951 ) ;
if ( ! V_280 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_946 ) ||
F_51 ( V_53 , V_952 , V_573 , V_947 ) ||
F_28 ( V_53 , V_290 , V_949 -> V_770 ) )
goto V_61;
V_950 = F_47 ( V_53 , V_953 ) ;
if ( ! V_950 )
goto V_61;
if ( ( V_949 -> V_772 & V_954 ) &&
F_28 ( V_53 , V_955 ,
V_949 -> V_956 ) )
goto V_61;
if ( ( ( V_949 -> V_772 & V_957 ) &&
F_28 ( V_53 , V_958 , V_949 -> V_959 ) ) ||
( ( V_949 -> V_772 & V_960 ) &&
F_28 ( V_53 , V_961 ,
V_949 -> V_962 ) ) ||
( ( V_949 -> V_772 & V_963 ) &&
F_28 ( V_53 , V_964 ,
V_949 -> V_965 ) ) ||
( ( V_949 -> V_772 & V_966 ) &&
F_56 ( V_53 , V_967 ,
V_949 -> V_51 ) ) ||
( ( V_949 -> V_772 & V_968 ) &&
F_28 ( V_53 , V_969 ,
V_949 -> V_970 ) ) ||
( ( V_949 -> V_772 & V_971 ) &&
F_56 ( V_53 , V_972 ,
V_949 -> V_973 ) ) )
goto V_61;
F_48 ( V_53 , V_950 ) ;
return F_66 ( V_53 , V_280 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
static int F_180 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_948 V_949 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_946 [ V_573 ] ;
T_2 V_947 [ V_573 ] ;
int V_974 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_342 -> V_975 ) {
V_35 = - V_526 ;
goto V_864;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_526 ;
goto V_864;
}
while ( 1 ) {
V_35 = F_181 ( V_7 , V_17 -> V_19 , V_974 , V_946 ,
V_947 , & V_949 ) ;
if ( V_35 == - V_638 )
break;
if ( V_35 )
goto V_864;
if ( F_179 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_486 , V_487 ,
V_17 -> V_19 , V_946 , V_947 ,
& V_949 ) < 0 )
goto V_583;
V_974 ++ ;
}
V_583:
V_34 -> args [ 2 ] = V_974 ;
V_35 = V_32 -> V_47 ;
V_864:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_182 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
int V_35 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_948 V_949 ;
struct V_31 * V_53 ;
T_2 * V_946 = NULL ;
T_2 V_947 [ V_573 ] ;
memset ( & V_949 , 0 , sizeof( V_949 ) ) ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_946 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( ! V_7 -> V_342 -> V_976 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_145 )
return - V_526 ;
V_35 = F_183 ( V_7 , V_525 , V_946 , V_947 , & V_949 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_179 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_525 , V_946 , V_947 , & V_949 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_184 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 * V_946 = NULL ;
T_2 * V_947 = NULL ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_952 ] )
return - V_16 ;
V_946 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_947 = F_23 ( V_30 -> V_5 [ V_952 ] ) ;
if ( ! V_7 -> V_342 -> V_977 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_145 )
return - V_526 ;
return F_185 ( V_7 , V_525 , V_946 , V_947 ) ;
}
static int F_186 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 * V_946 = NULL ;
T_2 * V_947 = NULL ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_952 ] )
return - V_16 ;
V_946 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_947 = F_23 ( V_30 -> V_5 [ V_952 ] ) ;
if ( ! V_7 -> V_342 -> V_370 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_145 )
return - V_526 ;
return F_187 ( V_7 , V_525 , V_946 , V_947 ) ;
}
static int F_188 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 * V_946 = NULL ;
if ( V_30 -> V_5 [ V_533 ] )
V_946 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( ! V_7 -> V_342 -> V_978 )
return - V_526 ;
return F_189 ( V_7 , V_525 , V_946 ) ;
}
static int F_190 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
int V_35 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_948 V_949 ;
struct V_31 * V_53 ;
T_2 * V_946 = NULL ;
T_2 V_979 [ V_573 ] ;
memset ( & V_949 , 0 , sizeof( V_949 ) ) ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_946 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( ! V_7 -> V_342 -> V_980 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_145 )
return - V_526 ;
V_35 = F_191 ( V_7 , V_525 , V_946 , V_979 , & V_949 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_179 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_525 , V_946 , V_979 , & V_949 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_192 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_948 V_949 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_946 [ V_573 ] ;
T_2 V_979 [ V_573 ] ;
int V_974 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_342 -> V_981 ) {
V_35 = - V_526 ;
goto V_864;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_526 ;
goto V_864;
}
while ( 1 ) {
V_35 = F_193 ( V_7 , V_17 -> V_19 , V_974 , V_946 ,
V_979 , & V_949 ) ;
if ( V_35 == - V_638 )
break;
if ( V_35 )
goto V_864;
if ( F_179 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_486 , V_487 ,
V_17 -> V_19 , V_946 , V_979 ,
& V_949 ) < 0 )
goto V_583;
V_974 ++ ;
}
V_583:
V_34 -> args [ 2 ] = V_974 ;
V_35 = V_32 -> V_47 ;
V_864:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_194 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_982 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_983 = - 1 ;
V_137 . V_984 = - 1 ;
V_137 . V_985 = - 1 ;
V_137 . V_986 = - 1 ;
V_137 . V_987 = - 1 ;
V_137 . V_711 = - 1 ;
V_137 . V_714 = - 1 ;
if ( V_30 -> V_5 [ V_988 ] )
V_137 . V_983 =
F_34 ( V_30 -> V_5 [ V_988 ] ) ;
if ( V_30 -> V_5 [ V_989 ] )
V_137 . V_984 =
F_34 ( V_30 -> V_5 [ V_989 ] ) ;
if ( V_30 -> V_5 [ V_990 ] )
V_137 . V_985 =
F_34 ( V_30 -> V_5 [ V_990 ] ) ;
if ( V_30 -> V_5 [ V_991 ] ) {
V_137 . V_992 =
F_23 ( V_30 -> V_5 [ V_991 ] ) ;
V_137 . V_993 =
F_24 ( V_30 -> V_5 [ V_991 ] ) ;
}
if ( V_30 -> V_5 [ V_994 ] )
V_137 . V_986 = ! ! F_34 ( V_30 -> V_5 [ V_994 ] ) ;
if ( V_30 -> V_5 [ V_995 ] )
V_137 . V_987 =
F_78 ( V_30 -> V_5 [ V_995 ] ) ;
if ( V_30 -> V_5 [ V_710 ] ) {
if ( V_525 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_711 =
F_195 ( V_30 -> V_5 [ V_710 ] ) ;
if ( V_137 . V_711 < 0 )
return - V_16 ;
if ( V_137 . V_711 != 0 &&
! ( V_7 -> V_18 . V_288 & V_712 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_713 ] ) {
T_2 V_24 ;
if ( V_525 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_713 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_714 = V_24 ;
if ( V_137 . V_714 &&
! ( V_7 -> V_18 . V_288 & V_715 ) )
return - V_16 ;
}
if ( ! V_7 -> V_342 -> V_374 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_142 &&
V_525 -> V_28 -> V_141 != V_144 )
return - V_526 ;
F_112 ( V_17 ) ;
V_35 = F_196 ( V_7 , V_525 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_197 ( struct V_4 * V_95 [] ,
struct V_996 * V_997 )
{
struct V_998 * V_999 = & V_997 -> V_999 ;
struct V_1000 * V_1001 = & V_997 -> V_1001 ;
if ( ! V_95 [ V_1002 ] )
return - V_16 ;
if ( ! V_95 [ V_1003 ] )
return - V_16 ;
if ( ! V_95 [ V_1004 ] )
return - V_16 ;
if ( ! V_95 [ V_1005 ] )
return - V_16 ;
if ( ! V_95 [ V_1006 ] )
return - V_16 ;
V_997 -> V_51 = F_4 ( V_95 [ V_1002 ] ) ;
V_999 -> V_1007 =
F_4 ( V_95 [ V_1003 ] ) ;
V_999 -> V_1008 =
F_4 ( V_95 [ V_1004 ] ) ;
V_999 -> V_1009 =
F_4 ( V_95 [ V_1005 ] ) ;
V_1001 -> V_1010 =
F_4 ( V_95 [ V_1006 ] ) ;
if ( V_95 [ V_1011 ] )
V_1001 -> V_1012 =
F_4 ( V_95 [ V_1011 ] ) ;
if ( V_95 [ V_1013 ] )
V_997 -> V_74 =
F_4 ( V_95 [ V_1013 ] ) ;
return 0 ;
}
static int F_198 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
enum V_1014 V_1015 ;
if ( F_199 ( ! F_200 ( V_1016 ) ) )
return - V_1017 ;
if ( V_30 -> V_5 [ V_1018 ] )
V_1015 =
F_4 ( V_30 -> V_5 [ V_1018 ] ) ;
else
V_1015 = V_1019 ;
switch ( V_1015 ) {
case V_1019 :
case V_1020 :
if ( ! V_30 -> V_5 [ V_1021 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1021 ] ) ;
return F_201 ( V_138 , V_1015 ) ;
case V_1022 :
return F_202 () ;
default:
return - V_16 ;
}
}
static int F_203 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_1023 V_1024 ;
int V_35 = 0 ;
void * V_280 ;
struct V_4 * V_950 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_526 ;
if ( ! V_7 -> V_342 -> V_1025 )
return - V_526 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1026 )
memcpy ( & V_1024 , & V_1027 , sizeof( V_1024 ) ) ;
else
V_35 = F_204 ( V_7 , V_525 , & V_1024 ) ;
F_114 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1028 ) ;
if ( ! V_280 )
goto V_583;
V_950 = F_47 ( V_53 , V_1029 ) ;
if ( ! V_950 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_55 ( V_53 , V_1030 ,
V_1024 . V_1031 ) ||
F_55 ( V_53 , V_1032 ,
V_1024 . V_1033 ) ||
F_55 ( V_53 , V_1034 ,
V_1024 . V_1035 ) ||
F_55 ( V_53 , V_1036 ,
V_1024 . V_1037 ) ||
F_56 ( V_53 , V_1038 ,
V_1024 . V_1039 ) ||
F_56 ( V_53 , V_1040 ,
V_1024 . V_1041 ) ||
F_56 ( V_53 , V_1042 ,
V_1024 . V_1043 ) ||
F_56 ( V_53 , V_1044 ,
V_1024 . V_1045 ) ||
F_28 ( V_53 , V_1046 ,
V_1024 . V_1047 ) ||
F_56 ( V_53 , V_1048 ,
V_1024 . V_1049 ) ||
F_28 ( V_53 , V_1050 ,
V_1024 . V_1051 ) ||
F_55 ( V_53 , V_1052 ,
V_1024 . V_1053 ) ||
F_28 ( V_53 , V_1054 ,
V_1024 . V_1055 ) ||
F_55 ( V_53 , V_1056 ,
V_1024 . V_1057 ) ||
F_55 ( V_53 , V_1058 ,
V_1024 . V_1059 ) ||
F_55 ( V_53 , V_1060 ,
V_1024 . V_1061 ) ||
F_56 ( V_53 , V_1062 ,
V_1024 . V_1063 ) ||
F_55 ( V_53 , V_1064 ,
V_1024 . V_1065 ) ||
F_56 ( V_53 , V_1066 ,
V_1024 . V_1067 ) ||
F_56 ( V_53 , V_1068 ,
V_1024 . V_1069 ) ||
F_28 ( V_53 , V_1070 ,
V_1024 . V_1071 ) ||
F_28 ( V_53 , V_1072 ,
V_1024 . V_987 ) ||
F_28 ( V_53 , V_1073 ,
V_1024 . V_1074 ) ||
F_55 ( V_53 , V_1075 ,
V_1024 . V_1076 ) ||
F_55 ( V_53 , V_1077 ,
V_1024 . V_1078 ) ||
F_28 ( V_53 , V_1079 ,
V_1024 . V_1080 ) ||
F_55 ( V_53 , V_1081 ,
V_1024 . V_1082 ) ||
F_28 ( V_53 , V_1083 ,
V_1024 . V_1084 ) )
goto V_61;
F_48 ( V_53 , V_950 ) ;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
V_583:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_205 ( struct V_29 * V_30 ,
struct V_1023 * V_1085 ,
V_22 * V_1086 )
{
struct V_4 * V_95 [ V_1087 + 1 ] ;
V_22 V_730 = 0 ;
#define F_206 ( V_95 , V_1085 , T_7 , T_8 , V_174 , V_730 , V_45 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1029 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1087 ,
V_30 -> V_5 [ V_1029 ] ,
V_1088 ) )
return - V_16 ;
F_113 ( V_1087 > 32 ) ;
F_206 ( V_95 , V_1085 , V_1031 , 1 , 255 ,
V_730 , V_1030 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1033 , 1 , 255 ,
V_730 , V_1032 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1035 , 1 , 255 ,
V_730 , V_1034 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1037 , 0 , 255 ,
V_730 , V_1036 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1039 , 0 , 16 ,
V_730 , V_1038 ,
F_34 ) ;
F_206 ( V_95 , V_1085 , V_1041 , 1 , 255 ,
V_730 , V_1040 , F_34 ) ;
F_206 ( V_95 , V_1085 , V_1043 , 1 , 255 ,
V_730 , V_1042 ,
F_34 ) ;
F_206 ( V_95 , V_1085 , V_1045 , 0 , 1 ,
V_730 , V_1044 ,
F_34 ) ;
F_206 ( V_95 , V_1085 , V_1047 ,
1 , 255 , V_730 ,
V_1046 ,
F_4 ) ;
F_206 ( V_95 , V_1085 , V_1049 , 0 , 255 ,
V_730 , V_1048 ,
F_34 ) ;
F_206 ( V_95 , V_1085 , V_1051 , 1 , 65535 ,
V_730 , V_1050 ,
F_4 ) ;
F_206 ( V_95 , V_1085 , V_1053 , 1 , 65535 ,
V_730 , V_1052 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1055 ,
1 , 65535 , V_730 ,
V_1054 ,
F_4 ) ;
F_206 ( V_95 , V_1085 , V_1057 ,
1 , 65535 , V_730 ,
V_1056 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1059 ,
1 , 65535 , V_730 ,
V_1058 ,
F_78 ) ;
F_206 ( V_95 , V_1085 ,
V_1061 ,
1 , 65535 , V_730 ,
V_1060 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1063 , 0 , 4 ,
V_730 , V_1062 ,
F_34 ) ;
F_206 ( V_95 , V_1085 , V_1065 , 1 , 65535 ,
V_730 , V_1064 ,
F_78 ) ;
F_206 ( V_95 , V_1085 ,
V_1067 , 0 , 1 ,
V_730 , V_1066 ,
F_34 ) ;
F_206 ( V_95 , V_1085 , V_1069 , 0 , 1 ,
V_730 , V_1068 ,
F_34 ) ;
F_206 ( V_95 , V_1085 , V_1071 , - 255 , 0 ,
V_730 , V_1070 ,
V_1089 ) ;
F_206 ( V_95 , V_1085 , V_987 , 0 , 16 ,
V_730 , V_1072 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1074 ,
1 , 65535 , V_730 ,
V_1073 ,
F_4 ) ;
F_206 ( V_95 , V_1085 , V_1076 , 1 , 65535 ,
V_730 , V_1075 ,
F_78 ) ;
F_206 ( V_95 , V_1085 ,
V_1078 ,
1 , 65535 , V_730 ,
V_1077 ,
F_78 ) ;
F_206 ( V_95 , V_1085 , V_1080 ,
V_1090 ,
V_930 ,
V_730 , V_1079 ,
F_4 ) ;
F_206 ( V_95 , V_1085 , V_1082 ,
0 , 65535 , V_730 ,
V_1081 , F_78 ) ;
F_206 ( V_95 , V_1085 , V_1084 , 1 , 0xffffffff ,
V_730 , V_1083 ,
F_4 ) ;
if ( V_1086 )
* V_1086 = V_730 ;
return 0 ;
#undef F_206
}
static int F_207 ( struct V_29 * V_30 ,
struct V_1091 * V_1092 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_4 * V_95 [ V_1093 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1094 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1093 ,
V_30 -> V_5 [ V_1094 ] ,
V_1095 ) )
return - V_16 ;
if ( V_95 [ V_1096 ] )
V_1092 -> V_1097 =
( F_34 ( V_95 [ V_1096 ] ) ) ?
V_1098 :
V_1099 ;
if ( V_95 [ V_1100 ] )
V_1092 -> V_1101 =
( F_34 ( V_95 [ V_1100 ] ) ) ?
V_1102 :
V_1103 ;
if ( V_95 [ V_1104 ] )
V_1092 -> V_1105 =
( F_34 ( V_95 [ V_1104 ] ) ) ?
V_1106 :
V_1107 ;
if ( V_95 [ V_1108 ] ) {
struct V_4 * V_1109 =
V_95 [ V_1108 ] ;
if ( ! F_22 ( V_1109 ) )
return - V_16 ;
V_1092 -> V_1110 = F_23 ( V_1109 ) ;
V_1092 -> V_1111 = F_24 ( V_1109 ) ;
}
if ( V_95 [ V_1112 ] &&
! ( V_7 -> V_18 . V_288 & V_1113 ) )
return - V_16 ;
V_1092 -> V_1114 = F_208 ( V_95 [ V_1112 ] ) ;
V_1092 -> V_1115 = F_208 ( V_95 [ V_1116 ] ) ;
V_1092 -> V_1117 = F_208 ( V_95 [ V_1118 ] ) ;
if ( V_1092 -> V_1117 )
V_1092 -> V_1114 = true ;
if ( V_95 [ V_1119 ] ) {
if ( ! V_1092 -> V_1114 )
return - V_16 ;
V_1092 -> V_1120 =
F_34 ( V_95 [ V_1119 ] ) ;
}
return 0 ;
}
static int F_209 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_1023 V_1085 ;
V_22 V_730 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_526 ;
if ( ! V_7 -> V_342 -> V_372 )
return - V_526 ;
V_35 = F_205 ( V_30 , & V_1085 , & V_730 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1026 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_210 ( V_7 , V_525 , V_730 , & V_1085 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_211 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1121 * V_1122 ;
struct V_31 * V_53 ;
void * V_280 = NULL ;
struct V_4 * V_1123 ;
unsigned int V_159 ;
if ( ! V_1016 )
return - V_16 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1124 ) ;
if ( ! V_280 )
goto V_1125;
if ( F_212 () &&
F_28 ( V_53 , V_1018 ,
V_1020 ) )
goto V_61;
F_213 () ;
V_1122 = F_214 ( V_1016 ) ;
if ( F_60 ( V_53 , V_1021 , V_1122 -> V_1126 ) ||
( V_1122 -> V_1127 &&
F_56 ( V_53 , V_1128 , V_1122 -> V_1127 ) ) )
goto V_1129;
V_1123 = F_47 ( V_53 , V_1130 ) ;
if ( ! V_1123 )
goto V_1129;
for ( V_159 = 0 ; V_159 < V_1122 -> V_1131 ; V_159 ++ ) {
struct V_4 * V_1132 ;
const struct V_996 * V_997 ;
const struct V_998 * V_999 ;
const struct V_1000 * V_1001 ;
unsigned int V_1009 ;
V_997 = & V_1122 -> V_1133 [ V_159 ] ;
V_999 = & V_997 -> V_999 ;
V_1001 = & V_997 -> V_1001 ;
V_1132 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1132 )
goto V_1129;
V_1009 = V_999 -> V_1009 ;
if ( ! V_1009 )
V_1009 = F_215 ( V_1122 ,
V_997 ) ;
if ( F_28 ( V_53 , V_1002 ,
V_997 -> V_51 ) ||
F_28 ( V_53 , V_1003 ,
V_999 -> V_1007 ) ||
F_28 ( V_53 , V_1004 ,
V_999 -> V_1008 ) ||
F_28 ( V_53 , V_1005 ,
V_1009 ) ||
F_28 ( V_53 , V_1011 ,
V_1001 -> V_1012 ) ||
F_28 ( V_53 , V_1006 ,
V_1001 -> V_1010 ) ||
F_28 ( V_53 , V_1013 ,
V_997 -> V_74 ) )
goto V_1129;
F_48 ( V_53 , V_1132 ) ;
}
F_216 () ;
F_48 ( V_53 , V_1123 ) ;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1129:
F_216 () ;
V_61:
F_67 ( V_53 , V_280 ) ;
V_1125:
F_75 ( V_53 ) ;
return - V_481 ;
}
static int F_217 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1134 + 1 ] ;
struct V_4 * V_1132 ;
char * V_1126 ;
int V_1135 , V_1136 ;
V_22 V_1137 = 0 , V_1138 = 0 , V_1139 ;
enum V_1140 V_1127 = V_1141 ;
struct V_1121 * V_1142 ;
if ( ! V_30 -> V_5 [ V_1021 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1130 ] )
return - V_16 ;
V_1126 = F_23 ( V_30 -> V_5 [ V_1021 ] ) ;
if ( V_30 -> V_5 [ V_1128 ] )
V_1127 = F_34 ( V_30 -> V_5 [ V_1128 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1137 ++ ;
if ( V_1137 > V_1143 )
return - V_16 ;
}
if ( ! F_218 ( V_1126 ) )
return - V_16 ;
V_1139 = sizeof( struct V_1121 ) +
V_1137 * sizeof( struct V_996 ) ;
V_1142 = F_38 ( V_1139 , V_135 ) ;
if ( ! V_1142 )
return - V_136 ;
V_1142 -> V_1131 = V_1137 ;
V_1142 -> V_1126 [ 0 ] = V_1126 [ 0 ] ;
V_1142 -> V_1126 [ 1 ] = V_1126 [ 1 ] ;
if ( F_219 ( V_1127 ) )
V_1142 -> V_1127 = V_1127 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1136 = F_96 ( V_95 , V_1134 ,
F_23 ( V_1132 ) , F_24 ( V_1132 ) ,
V_1144 ) ;
if ( V_1136 )
goto V_1145;
V_1136 = F_197 ( V_95 , & V_1142 -> V_1133 [ V_1138 ] ) ;
if ( V_1136 )
goto V_1145;
V_1138 ++ ;
if ( V_1138 > V_1143 ) {
V_1136 = - V_16 ;
goto V_1145;
}
}
V_1136 = F_220 ( V_1142 ) ;
V_1142 = NULL ;
V_1145:
F_41 ( V_1142 ) ;
return V_1136 ;
}
static int F_221 ( struct V_4 * V_1146 )
{
struct V_4 * V_1147 , * V_1148 ;
int V_357 = 0 , V_1149 , V_1150 ;
F_39 (attr1, freqs, tmp1) {
V_357 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1147 != V_1148 &&
F_4 ( V_1147 ) == F_4 ( V_1148 ) )
return 0 ;
}
return V_357 ;
}
static int F_222 ( struct V_4 * * V_5 ,
T_2 * V_632 , T_2 * V_1151 )
{
int V_159 ;
if ( ! V_5 [ V_533 ] && ! V_5 [ V_1152 ] ) {
memset ( V_632 , 0 , V_573 ) ;
memset ( V_1151 , 0 , V_573 ) ;
V_632 [ 0 ] = 0x2 ;
V_1151 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_533 ] || ! V_5 [ V_1152 ] )
return - V_16 ;
memcpy ( V_632 , F_23 ( V_5 [ V_533 ] ) , V_573 ) ;
memcpy ( V_1151 , F_23 ( V_5 [ V_1152 ] ) , V_573 ) ;
if ( ! F_223 ( V_1151 ) ||
F_223 ( V_632 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_573 ; V_159 ++ )
V_632 [ V_159 ] &= V_1151 [ V_159 ] ;
return 0 ;
}
static int F_224 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
struct V_1153 * V_1154 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1155 = 0 , V_357 , V_159 ;
T_10 V_1111 ;
if ( ! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_342 -> V_1156 )
return - V_526 ;
if ( V_7 -> V_1157 || V_7 -> V_1158 ) {
V_35 = - V_530 ;
goto V_1159;
}
if ( V_30 -> V_5 [ V_1160 ] ) {
V_357 = F_221 (
V_30 -> V_5 [ V_1160 ] ) ;
if ( ! V_357 ) {
V_35 = - V_16 ;
goto V_1159;
}
} else {
V_357 = F_225 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1161 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1155 ++ ;
if ( V_1155 > V_18 -> V_306 ) {
V_35 = - V_16 ;
goto V_1159;
}
if ( V_30 -> V_5 [ V_666 ] )
V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
else
V_1111 = 0 ;
if ( V_1111 > V_18 -> V_310 ) {
V_35 = - V_16 ;
goto V_1159;
}
V_1154 = F_38 ( sizeof( * V_1154 )
+ sizeof( * V_1154 -> V_1162 ) * V_1155
+ sizeof( * V_1154 -> V_358 ) * V_357
+ V_1111 , V_135 ) ;
if ( ! V_1154 ) {
V_35 = - V_136 ;
goto V_1159;
}
if ( V_1155 )
V_1154 -> V_1162 = ( void * ) & V_1154 -> V_358 [ V_357 ] ;
V_1154 -> V_1155 = V_1155 ;
if ( V_1111 ) {
if ( V_1154 -> V_1162 )
V_1154 -> V_1110 = ( void * ) ( V_1154 -> V_1162 + V_1155 ) ;
else
V_1154 -> V_1110 = ( void * ) ( V_1154 -> V_358 + V_357 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1160 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1163;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1154 -> V_358 [ V_159 ] = V_55 ;
V_159 ++ ;
}
} else {
enum V_286 V_287 ;
for ( V_287 = 0 ; V_287 < V_353 ; V_287 ++ ) {
int V_161 ;
if ( ! V_18 -> V_354 [ V_287 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_354 [ V_287 ] -> V_357 ; V_161 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_354 [ V_287 ] -> V_358 [ V_161 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1154 -> V_358 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1163;
}
V_1154 -> V_357 = V_159 ;
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1161 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_602 ) {
V_35 = - V_16 ;
goto V_1163;
}
V_1154 -> V_1162 [ V_159 ] . V_576 = F_24 ( V_45 ) ;
memcpy ( V_1154 -> V_1162 [ V_159 ] . V_578 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_666 ] ) {
V_1154 -> V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
memcpy ( ( void * ) V_1154 -> V_1110 ,
F_23 ( V_30 -> V_5 [ V_666 ] ) ,
V_1154 -> V_1111 ) ;
}
for ( V_159 = 0 ; V_159 < V_353 ; V_159 ++ )
if ( V_18 -> V_354 [ V_159 ] )
V_1154 -> V_1164 [ V_159 ] =
( 1 << V_18 -> V_354 [ V_159 ] -> V_258 ) - 1 ;
if ( V_30 -> V_5 [ V_1165 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_286 V_287 = F_226 ( V_45 ) ;
if ( V_287 < 0 || V_287 >= V_353 ) {
V_35 = - V_16 ;
goto V_1163;
}
if ( ! V_18 -> V_354 [ V_287 ] )
continue;
V_35 = F_227 ( V_18 -> V_354 [ V_287 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1154 -> V_1164 [ V_287 ] ) ;
if ( V_35 )
goto V_1163;
}
}
if ( V_30 -> V_5 [ V_1166 ] ) {
V_1154 -> V_51 = F_4 (
V_30 -> V_5 [ V_1166 ] ) ;
if ( ( V_1154 -> V_51 & V_1167 ) &&
! ( V_18 -> V_288 & V_1168 ) ) {
V_35 = - V_526 ;
goto V_1163;
}
if ( V_1154 -> V_51 & V_1169 ) {
if ( ! ( V_18 -> V_288 &
V_1170 ) ) {
V_35 = - V_526 ;
goto V_1163;
}
if ( V_17 -> V_149 ) {
V_35 = - V_526 ;
goto V_1163;
}
V_35 = F_222 ( V_30 -> V_5 ,
V_1154 -> V_632 ,
V_1154 -> V_1151 ) ;
if ( V_35 )
goto V_1163;
}
}
V_1154 -> V_1171 =
F_208 ( V_30 -> V_5 [ V_1172 ] ) ;
V_1154 -> V_17 = V_17 ;
V_1154 -> V_18 = & V_7 -> V_18 ;
V_1154 -> V_1173 = V_1174 ;
V_7 -> V_1157 = V_1154 ;
V_35 = F_228 ( V_7 , V_1154 ) ;
if ( ! V_35 ) {
F_229 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_230 ( V_17 -> V_19 ) ;
} else {
V_1163:
V_7 -> V_1157 = NULL ;
F_41 ( V_1154 ) ;
}
V_1159:
return V_35 ;
}
static struct V_1175 *
F_231 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1175 * V_1154 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1155 = 0 , V_1176 = 0 , V_357 , V_159 ;
V_22 V_1177 ;
enum V_286 V_287 ;
T_10 V_1111 ;
struct V_4 * V_95 [ V_1178 + 1 ] ;
T_11 V_1179 = V_1180 ;
if ( ! F_22 ( V_5 [ V_666 ] ) )
return F_3 ( - V_16 ) ;
if ( ! V_5 [ V_1181 ] )
return F_3 ( - V_16 ) ;
V_1177 = F_4 ( V_5 [ V_1181 ] ) ;
if ( V_1177 == 0 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1160 ] ) {
V_357 = F_221 (
V_5 [ V_1160 ] ) ;
if ( ! V_357 )
return F_3 ( - V_16 ) ;
} else {
V_357 = F_225 ( V_18 ) ;
}
if ( V_5 [ V_1161 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1155 ++ ;
if ( V_1155 > V_18 -> V_308 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1182 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1183 ;
V_35 = F_96 ( V_95 , V_1178 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1184 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1185 ] ) {
V_1176 ++ ;
continue;
}
V_1183 = V_95 [ V_1186 ] ;
if ( V_1183 )
V_1179 = V_1089 ( V_1183 ) ;
}
}
if ( ! V_1176 && V_1179 != V_1180 )
V_1176 = 1 ;
if ( V_1176 > V_18 -> V_314 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_666 ] )
V_1111 = F_24 ( V_5 [ V_666 ] ) ;
else
V_1111 = 0 ;
if ( V_1111 > V_18 -> V_312 )
return F_3 ( - V_16 ) ;
V_1154 = F_38 ( sizeof( * V_1154 )
+ sizeof( * V_1154 -> V_1162 ) * V_1155
+ sizeof( * V_1154 -> V_1187 ) * V_1176
+ sizeof( * V_1154 -> V_358 ) * V_357
+ V_1111 , V_135 ) ;
if ( ! V_1154 )
return F_3 ( - V_136 ) ;
if ( V_1155 )
V_1154 -> V_1162 = ( void * ) & V_1154 -> V_358 [ V_357 ] ;
V_1154 -> V_1155 = V_1155 ;
if ( V_1111 ) {
if ( V_1154 -> V_1162 )
V_1154 -> V_1110 = ( void * ) ( V_1154 -> V_1162 + V_1155 ) ;
else
V_1154 -> V_1110 = ( void * ) ( V_1154 -> V_358 + V_357 ) ;
}
if ( V_1176 ) {
if ( V_1154 -> V_1110 )
V_1154 -> V_1187 = ( void * ) ( V_1154 -> V_1110 + V_1111 ) ;
else if ( V_1154 -> V_1162 )
V_1154 -> V_1187 =
( void * ) ( V_1154 -> V_1162 + V_1155 ) ;
else
V_1154 -> V_1187 =
( void * ) ( V_1154 -> V_358 + V_357 ) ;
}
V_1154 -> V_1176 = V_1176 ;
V_159 = 0 ;
if ( V_5 [ V_1160 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1163;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1154 -> V_358 [ V_159 ] = V_55 ;
V_159 ++ ;
}
} else {
for ( V_287 = 0 ; V_287 < V_353 ; V_287 ++ ) {
int V_161 ;
if ( ! V_18 -> V_354 [ V_287 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_354 [ V_287 ] -> V_357 ; V_161 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_354 [ V_287 ] -> V_358 [ V_161 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1154 -> V_358 [ V_159 ] = V_55 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1163;
}
V_1154 -> V_357 = V_159 ;
V_159 = 0 ;
if ( V_5 [ V_1161 ] ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_602 ) {
V_35 = - V_16 ;
goto V_1163;
}
V_1154 -> V_1162 [ V_159 ] . V_576 = F_24 ( V_45 ) ;
memcpy ( V_1154 -> V_1162 [ V_159 ] . V_578 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1182 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_578 , * V_1183 ;
V_35 = F_96 ( V_95 , V_1178 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1184 ) ;
if ( V_35 )
goto V_1163;
V_578 = V_95 [ V_1185 ] ;
if ( V_578 ) {
if ( F_59 ( V_159 >= V_1176 ) ) {
V_35 = - V_16 ;
goto V_1163;
}
if ( F_24 ( V_578 ) > V_602 ) {
V_35 = - V_16 ;
goto V_1163;
}
memcpy ( V_1154 -> V_1187 [ V_159 ] . V_578 . V_578 ,
F_23 ( V_578 ) , F_24 ( V_578 ) ) ;
V_1154 -> V_1187 [ V_159 ] . V_578 . V_576 =
F_24 ( V_578 ) ;
V_1154 -> V_1187 [ V_159 ] . V_1188 =
V_1179 ;
V_1183 = V_95 [ V_1186 ] ;
if ( V_1183 )
V_1154 -> V_1187 [ V_159 ] . V_1188 =
V_1089 ( V_1183 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1176 )
V_1154 -> V_1187 [ 0 ] . V_1188 = V_1179 ;
V_1154 -> V_1189 = V_1190 ;
for ( V_159 = 0 ; V_159 < V_1176 ; V_159 ++ )
V_1154 -> V_1189 =
T_8 ( V_1154 -> V_1187 [ V_159 ] . V_1188 ,
V_1154 -> V_1189 ) ;
} else {
V_1154 -> V_1189 = V_1180 ;
}
if ( V_1111 ) {
V_1154 -> V_1111 = V_1111 ;
memcpy ( ( void * ) V_1154 -> V_1110 ,
F_23 ( V_5 [ V_666 ] ) ,
V_1154 -> V_1111 ) ;
}
if ( V_5 [ V_1166 ] ) {
V_1154 -> V_51 = F_4 (
V_5 [ V_1166 ] ) ;
if ( ( V_1154 -> V_51 & V_1167 ) &&
! ( V_18 -> V_288 & V_1168 ) ) {
V_35 = - V_526 ;
goto V_1163;
}
if ( V_1154 -> V_51 & V_1169 ) {
V_22 V_1191 = V_1192 ;
if ( ! V_17 )
V_1191 = V_1193 ;
if ( ! ( V_18 -> V_288 & V_1191 ) ) {
V_35 = - V_526 ;
goto V_1163;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_526 ;
goto V_1163;
}
V_35 = F_222 ( V_5 , V_1154 -> V_632 ,
V_1154 -> V_1151 ) ;
if ( V_35 )
goto V_1163;
}
}
V_1154 -> V_1177 = V_1177 ;
V_1154 -> V_1173 = V_1174 ;
return V_1154 ;
V_1163:
F_41 ( V_1154 ) ;
return F_3 ( V_35 ) ;
}
static int F_232 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_413 ) ||
! V_7 -> V_342 -> V_414 )
return - V_526 ;
if ( V_7 -> V_1194 )
return - V_1017 ;
V_7 -> V_1194 = F_231 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_233 ( V_7 -> V_1194 ) ;
if ( V_35 )
goto V_864;
V_35 = F_234 ( V_7 , V_525 , V_7 -> V_1194 ) ;
if ( V_35 )
goto V_1163;
V_7 -> V_1194 -> V_525 = V_525 ;
V_7 -> V_1194 -> V_18 = & V_7 -> V_18 ;
F_235 ( V_7 , V_525 ,
V_1195 ) ;
return 0 ;
V_1163:
F_41 ( V_7 -> V_1194 ) ;
V_864:
V_7 -> V_1194 = NULL ;
return V_35 ;
}
static int F_236 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_413 ) ||
! V_7 -> V_342 -> V_1196 )
return - V_526 ;
return F_237 ( V_7 , false ) ;
}
static int F_238 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_505 V_506 ;
enum V_1140 V_1127 ;
unsigned int V_1197 ;
int V_35 ;
V_1127 = F_239 ( V_17 -> V_18 ) ;
if ( V_1127 == V_1141 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_506 ) ;
if ( V_35 )
return V_35 ;
if ( F_240 ( V_525 ) )
return - V_530 ;
if ( V_17 -> V_1198 )
return - V_530 ;
V_35 = F_241 ( V_17 -> V_18 , & V_506 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_242 ( V_17 -> V_18 , & V_506 ) )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_1199 )
return - V_526 ;
V_1197 = F_243 ( & V_7 -> V_18 , & V_506 ) ;
if ( F_59 ( ! V_1197 ) )
V_1197 = V_1200 ;
V_35 = V_7 -> V_342 -> V_1199 ( & V_7 -> V_18 , V_525 , & V_506 ,
V_1197 ) ;
if ( ! V_35 ) {
V_17 -> V_506 = V_506 ;
V_17 -> V_1198 = true ;
V_17 -> V_1201 = V_1174 ;
V_17 -> V_1197 = V_1197 ;
}
return V_35 ;
}
static int F_244 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_1202 V_137 ;
static struct V_4 * V_1203 [ V_1204 + 1 ] ;
int V_35 ;
bool V_1205 = false ;
int V_47 , V_159 ;
V_22 V_1206 ;
if ( ! V_7 -> V_342 -> V_433 ||
! ( V_7 -> V_18 . V_51 & V_432 ) )
return - V_526 ;
switch ( V_525 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1205 = true ;
if ( ! V_17 -> V_527 )
return - V_1207 ;
break;
case V_146 :
if ( ! V_17 -> V_576 )
return - V_1207 ;
break;
case V_145 :
if ( ! V_17 -> V_1026 )
return - V_1207 ;
break;
default:
return - V_526 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_508 ] ||
! V_30 -> V_5 [ V_1208 ] )
return - V_16 ;
if ( V_1205 && ! V_30 -> V_5 [ V_1209 ] )
return - V_16 ;
V_1206 = F_4 ( V_30 -> V_5 [ V_1208 ] ) ;
if ( V_1206 > 255 )
return - V_16 ;
V_137 . V_1210 = V_1206 ;
if ( ! V_1205 )
goto V_1211;
V_35 = F_145 ( V_30 -> V_5 , & V_137 . V_1212 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1203 , V_1204 ,
V_30 -> V_5 [ V_1209 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_145 ( V_1203 , & V_137 . V_1213 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1203 [ V_1214 ] )
return - V_16 ;
V_47 = F_24 ( V_1203 [ V_1214 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1215 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_480 &&
( V_137 . V_1215 >
V_7 -> V_18 . V_480 ) )
return - V_16 ;
V_137 . V_1216 =
F_23 ( V_1203 [ V_1214 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1215 ; V_159 ++ ) {
T_3 V_1217 = V_137 . V_1216 [ V_159 ] ;
if ( V_1217 >= V_137 . V_1213 . V_673 )
return - V_16 ;
if ( V_137 . V_1213 . V_672 [ V_1217 ] != V_137 . V_1210 )
return - V_16 ;
}
if ( V_1203 [ V_1218 ] ) {
V_47 = F_24 ( V_1203 [ V_1218 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1219 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_480 &&
( V_137 . V_1215 >
V_7 -> V_18 . V_480 ) )
return - V_16 ;
V_137 . V_1220 =
F_23 ( V_1203 [ V_1218 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1219 ; V_159 ++ ) {
T_3 V_1217 = V_137 . V_1220 [ V_159 ] ;
if ( V_1217 >= V_137 . V_1213 . V_682 )
return - V_16 ;
if ( V_137 . V_1213 . V_681 [ V_1217 ] !=
V_137 . V_1210 )
return - V_16 ;
}
}
V_1211:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_506 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_506 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_241 ( V_17 -> V_18 ,
& V_137 . V_506 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_137 . V_1221 = true ;
if ( V_30 -> V_5 [ V_1222 ] )
V_137 . V_1223 = true ;
F_112 ( V_17 ) ;
V_35 = F_245 ( V_7 , V_525 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_246 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1224 * V_1225 )
{
struct V_1226 * V_346 = & V_1225 -> V_1227 ;
const struct V_1228 * V_1229 ;
void * V_280 ;
struct V_4 * V_1230 ;
F_43 ( V_17 ) ;
V_280 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1231 ) ;
if ( ! V_280 )
return - 1 ;
F_247 ( V_34 , V_280 , & V_38 ) ;
if ( F_28 ( V_53 , V_290 , V_7 -> V_1232 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
V_1230 = F_47 ( V_53 , V_1233 ) ;
if ( ! V_1230 )
goto V_61;
if ( ( ! F_248 ( V_346 -> V_532 ) &&
F_51 ( V_53 , V_1234 , V_573 , V_346 -> V_532 ) ) )
goto V_61;
F_213 () ;
if ( F_200 ( V_346 -> V_676 ) &&
F_29 ( V_53 , V_1235 ) )
goto V_1236;
V_1229 = F_214 ( V_346 -> V_1229 ) ;
if ( V_1229 ) {
if ( F_104 ( V_53 , V_1237 , V_1229 -> V_1238 ) )
goto V_1236;
if ( V_1229 -> V_47 && F_51 ( V_53 , V_1239 ,
V_1229 -> V_47 , V_1229 -> V_138 ) )
goto V_1236;
}
V_1229 = F_214 ( V_346 -> V_674 ) ;
if ( V_1229 && V_1229 -> V_1240 ) {
if ( F_104 ( V_53 , V_1241 , V_1229 -> V_1238 ) )
goto V_1236;
if ( V_1229 -> V_47 && F_51 ( V_53 , V_1242 ,
V_1229 -> V_47 , V_1229 -> V_138 ) )
goto V_1236;
}
F_216 () ;
if ( V_346 -> V_527 &&
F_55 ( V_53 , V_1243 , V_346 -> V_527 ) )
goto V_61;
if ( F_55 ( V_53 , V_1244 , V_346 -> V_918 ) ||
F_28 ( V_53 , V_1245 , V_346 -> V_1246 -> V_60 ) ||
F_28 ( V_53 , V_1247 , V_346 -> V_1248 ) ||
F_28 ( V_53 , V_1249 ,
F_249 ( V_1174 - V_1225 -> V_1250 ) ) )
goto V_61;
switch ( V_7 -> V_18 . V_798 ) {
case V_799 :
if ( F_28 ( V_53 , V_1251 , V_346 -> signal ) )
goto V_61;
break;
case V_1252 :
if ( F_56 ( V_53 , V_1253 , V_346 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1225 == V_17 -> V_149 &&
F_28 ( V_53 , V_1254 ,
V_1255 ) )
goto V_61;
break;
case V_146 :
if ( V_1225 == V_17 -> V_149 &&
F_28 ( V_53 , V_1254 ,
V_1256 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1230 ) ;
return F_66 ( V_53 , V_280 ) ;
V_1236:
F_216 () ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
static int F_250 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1224 * V_1156 ;
struct V_1 * V_17 ;
int V_485 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
F_251 ( & V_7 -> V_1257 ) ;
F_252 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1232 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_485 )
continue;
if ( F_246 ( V_32 , V_34 ,
V_34 -> V_36 -> V_486 , V_487 ,
V_7 , V_17 , V_1156 ) < 0 ) {
V_105 -- ;
break;
}
}
F_253 ( & V_7 -> V_1257 ) ;
F_114 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_254 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_525 ,
struct V_1258 * V_1259 )
{
void * V_280 ;
struct V_4 * V_1260 ;
V_280 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1261 ) ;
if ( ! V_280 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_525 -> V_20 ) )
goto V_61;
V_1260 = F_47 ( V_53 , V_1262 ) ;
if ( ! V_1260 )
goto V_61;
if ( F_28 ( V_53 , V_1263 ,
V_1259 -> V_1246 -> V_60 ) )
goto V_61;
if ( ( V_1259 -> V_772 & V_1264 ) &&
F_56 ( V_53 , V_1265 , V_1259 -> V_1266 ) )
goto V_61;
if ( ( V_1259 -> V_772 & V_1267 ) &&
F_29 ( V_53 , V_1268 ) )
goto V_61;
if ( ( V_1259 -> V_772 & V_1269 ) &&
F_104 ( V_53 , V_1270 ,
V_1259 -> V_1271 ) )
goto V_61;
if ( ( V_1259 -> V_772 & V_1272 ) &&
F_104 ( V_53 , V_1273 ,
V_1259 -> V_1274 ) )
goto V_61;
if ( ( V_1259 -> V_772 & V_1275 ) &&
F_104 ( V_53 , V_1276 ,
V_1259 -> V_1277 ) )
goto V_61;
if ( ( V_1259 -> V_772 & V_1278 ) &&
F_104 ( V_53 , V_1279 ,
V_1259 -> V_1280 ) )
goto V_61;
if ( ( V_1259 -> V_772 & V_1281 ) &&
F_104 ( V_53 , V_1282 ,
V_1259 -> V_1283 ) )
goto V_61;
F_48 ( V_53 , V_1260 ) ;
return F_66 ( V_53 , V_280 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
static int F_255 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1258 V_1259 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1284 = V_34 -> args [ 2 ] ;
int V_346 ;
V_346 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_346 )
return V_346 ;
if ( ! V_17 -> V_19 ) {
V_346 = - V_16 ;
goto V_864;
}
if ( ! V_7 -> V_342 -> V_1285 ) {
V_346 = - V_526 ;
goto V_864;
}
while ( 1 ) {
V_346 = F_256 ( V_7 , V_17 -> V_19 , V_1284 , & V_1259 ) ;
if ( V_346 == - V_638 )
break;
if ( V_346 )
goto V_864;
if ( ! V_1259 . V_1246 ) {
V_346 = - V_16 ;
goto V_583;
}
if ( V_1259 . V_1246 -> V_51 & V_62 ) {
V_1284 ++ ;
continue;
}
if ( F_254 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_486 , V_487 ,
V_17 -> V_19 , & V_1259 ) < 0 )
goto V_583;
V_1284 ++ ;
}
V_583:
V_34 -> args [ 2 ] = V_1284 ;
V_346 = V_32 -> V_47 ;
V_864:
F_21 ( V_7 ) ;
return V_346 ;
}
static bool F_257 ( V_22 V_1286 )
{
return ! ( V_1286 & ~ ( V_1287 |
V_1288 ) ) ;
}
static int F_258 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_532 , * V_578 , * V_1110 = NULL , * V_1289 = NULL ;
int V_35 , V_576 , V_1111 = 0 , V_1290 = 0 ;
enum V_684 V_685 ;
struct V_93 V_92 ;
bool V_1291 ;
if ( ! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_703 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_577 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_508 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_635 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1292 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1293 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_159 ;
bool V_1294 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_329 ; V_159 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_330 [ V_159 ] ) {
V_1294 = true ;
break;
}
}
if ( ! V_1294 )
return - V_16 ;
}
if ( ! V_7 -> V_342 -> V_376 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_508 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_578 = F_23 ( V_30 -> V_5 [ V_577 ] ) ;
V_576 = F_24 ( V_30 -> V_5 [ V_577 ] ) ;
if ( V_30 -> V_5 [ V_666 ] ) {
V_1110 = F_23 ( V_30 -> V_5 [ V_666 ] ) ;
V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
}
V_685 = F_4 ( V_30 -> V_5 [ V_703 ] ) ;
if ( ! F_147 ( V_7 , V_685 , V_687 ) )
return - V_16 ;
if ( V_685 == V_689 &&
! V_30 -> V_5 [ V_1295 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1295 ] ) {
if ( V_685 != V_689 )
return - V_16 ;
V_1289 = F_23 ( V_30 -> V_5 [ V_1295 ] ) ;
V_1290 = F_24 ( V_30 -> V_5 [ V_1295 ] ) ;
if ( V_1290 < 4 )
return - V_16 ;
}
V_1291 = ! ! V_30 -> V_5 [ V_1296 ] ;
if ( V_1291 )
return 0 ;
F_112 ( V_525 -> V_28 ) ;
V_35 = F_259 ( V_7 , V_525 , V_55 , V_685 , V_532 ,
V_578 , V_576 , V_1110 , V_1111 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1289 , V_1290 ) ;
F_114 ( V_525 -> V_28 ) ;
return V_35 ;
}
static int F_150 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1297 * V_1298 ,
int V_1299 )
{
memset ( V_1298 , 0 , sizeof( * V_1298 ) ) ;
V_1298 -> V_1300 = V_30 -> V_5 [ V_1301 ] ;
if ( V_30 -> V_5 [ V_334 ] ) {
T_3 V_1302 ;
V_1302 = F_78 (
V_30 -> V_5 [ V_334 ] ) ;
V_1298 -> V_1303 = F_260 ( V_1302 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_333 ) &&
V_1302 != V_1304 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1305 ] )
V_1298 -> V_1306 = true ;
} else
V_1298 -> V_1303 = F_260 ( V_1304 ) ;
if ( V_30 -> V_5 [ V_1307 ] ) {
void * V_138 ;
int V_47 , V_159 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1307 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1307 ] ) ;
V_1298 -> V_1308 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1298 -> V_1308 > V_1299 )
return - V_16 ;
memcpy ( V_1298 -> V_1309 , V_138 , V_47 ) ;
for ( V_159 = 0 ; V_159 < V_1298 -> V_1308 ; V_159 ++ )
if ( ! F_261 (
& V_7 -> V_18 ,
V_1298 -> V_1309 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1310 ] ) {
V_1298 -> V_1311 =
F_4 ( V_30 -> V_5 [ V_1310 ] ) ;
if ( ! F_261 ( & V_7 -> V_18 ,
V_1298 -> V_1311 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1312 ] ) {
V_1298 -> V_1286 =
F_4 ( V_30 -> V_5 [ V_1312 ] ) ;
if ( ! F_257 ( V_1298 -> V_1286 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1313 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1313 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1313 ] ) ;
V_1298 -> V_1314 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1298 -> V_1314 > V_1315 )
return - V_16 ;
memcpy ( V_1298 -> V_1316 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_262 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1317 V_1318 = {} ;
const T_2 * V_532 , * V_578 ;
int V_35 , V_576 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_533 ] ||
! V_30 -> V_5 [ V_577 ] ||
! V_30 -> V_5 [ V_508 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_378 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_508 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_578 = F_23 ( V_30 -> V_5 [ V_577 ] ) ;
V_576 = F_24 ( V_30 -> V_5 [ V_577 ] ) ;
if ( V_30 -> V_5 [ V_666 ] ) {
V_1318 . V_1110 = F_23 ( V_30 -> V_5 [ V_666 ] ) ;
V_1318 . V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
}
if ( V_30 -> V_5 [ V_1319 ] ) {
enum V_1320 V_1321 =
F_4 ( V_30 -> V_5 [ V_1319 ] ) ;
if ( V_1321 == V_1322 )
V_1318 . V_1323 = true ;
else if ( V_1321 != V_1324 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1325 ] )
V_1318 . V_1326 = F_23 ( V_30 -> V_5 [ V_1325 ] ) ;
if ( F_208 ( V_30 -> V_5 [ V_1327 ] ) )
V_1318 . V_51 |= V_1328 ;
if ( V_30 -> V_5 [ V_456 ] )
memcpy ( & V_1318 . V_1329 ,
F_23 ( V_30 -> V_5 [ V_456 ] ) ,
sizeof( V_1318 . V_1329 ) ) ;
if ( V_30 -> V_5 [ V_911 ] ) {
if ( ! V_30 -> V_5 [ V_456 ] )
return - V_16 ;
memcpy ( & V_1318 . V_883 ,
F_23 ( V_30 -> V_5 [ V_911 ] ) ,
sizeof( V_1318 . V_883 ) ) ;
}
if ( F_208 ( V_30 -> V_5 [ V_1330 ] ) )
V_1318 . V_51 |= V_1331 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_1318 . V_1332 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_1318 . V_1332 ) ) ;
if ( V_30 -> V_5 [ V_912 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] )
return - V_16 ;
memcpy ( & V_1318 . V_884 ,
F_23 ( V_30 -> V_5 [ V_912 ] ) ,
sizeof( V_1318 . V_884 ) ) ;
}
if ( F_208 ( V_30 -> V_5 [ V_1333 ] ) ) {
if ( ! ( V_7 -> V_18 . V_288 &
V_1334 ) ||
! ( V_7 -> V_18 . V_288 & V_1335 ) )
return - V_16 ;
V_1318 . V_51 |= V_1336 ;
}
V_35 = F_150 ( V_7 , V_30 , & V_1318 . V_705 , 1 ) ;
if ( ! V_35 ) {
F_112 ( V_525 -> V_28 ) ;
V_35 = F_263 ( V_7 , V_525 , V_55 , V_532 ,
V_578 , V_576 , & V_1318 ) ;
F_114 ( V_525 -> V_28 ) ;
}
return V_35 ;
}
static int F_264 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
const T_2 * V_1110 = NULL , * V_532 ;
int V_1111 = 0 , V_35 ;
T_3 V_944 ;
bool V_1291 ;
if ( ! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_943 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_380 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_944 = F_78 ( V_30 -> V_5 [ V_943 ] ) ;
if ( V_944 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_666 ] ) {
V_1110 = F_23 ( V_30 -> V_5 [ V_666 ] ) ;
V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
}
V_1291 = ! ! V_30 -> V_5 [ V_1296 ] ;
F_112 ( V_525 -> V_28 ) ;
V_35 = F_265 ( V_7 , V_525 , V_532 , V_1110 , V_1111 , V_944 ,
V_1291 ) ;
F_114 ( V_525 -> V_28 ) ;
return V_35 ;
}
static int F_266 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
const T_2 * V_1110 = NULL , * V_532 ;
int V_1111 = 0 , V_35 ;
T_3 V_944 ;
bool V_1291 ;
if ( ! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_943 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_382 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_944 = F_78 ( V_30 -> V_5 [ V_943 ] ) ;
if ( V_944 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_666 ] ) {
V_1110 = F_23 ( V_30 -> V_5 [ V_666 ] ) ;
V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
}
V_1291 = ! ! V_30 -> V_5 [ V_1296 ] ;
F_112 ( V_525 -> V_28 ) ;
V_35 = F_267 ( V_7 , V_525 , V_532 , V_1110 , V_1111 , V_944 ,
V_1291 ) ;
F_114 ( V_525 -> V_28 ) ;
return V_35 ;
}
static bool
F_268 ( struct V_6 * V_7 ,
int V_1337 [ V_353 ] ,
int V_1338 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_287 , V_159 ;
for ( V_287 = 0 ; V_287 < V_353 ; V_287 ++ ) {
struct V_236 * V_237 ;
V_237 = V_18 -> V_354 [ V_287 ] ;
if ( ! V_237 )
continue;
for ( V_159 = 0 ; V_159 < V_237 -> V_258 ; V_159 ++ ) {
if ( V_237 -> V_259 [ V_159 ] . V_261 == V_1338 ) {
V_1337 [ V_287 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_269 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1339 V_1340 ;
struct V_18 * V_18 ;
struct V_130 * V_1341 = NULL ;
int V_35 ;
memset ( & V_1340 , 0 , sizeof( V_1340 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_577 ] ||
! F_24 ( V_30 -> V_5 [ V_577 ] ) )
return - V_16 ;
V_1340 . V_527 = 100 ;
if ( V_30 -> V_5 [ V_692 ] ) {
V_1340 . V_527 =
F_4 ( V_30 -> V_5 [ V_692 ] ) ;
if ( V_1340 . V_527 < 1 || V_1340 . V_527 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_342 -> V_384 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_146 )
return - V_526 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_533 ] ) {
V_1340 . V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( ! F_119 ( V_1340 . V_532 ) )
return - V_16 ;
}
V_1340 . V_578 = F_23 ( V_30 -> V_5 [ V_577 ] ) ;
V_1340 . V_576 = F_24 ( V_30 -> V_5 [ V_577 ] ) ;
if ( V_30 -> V_5 [ V_666 ] ) {
V_1340 . V_1110 = F_23 ( V_30 -> V_5 [ V_666 ] ) ;
V_1340 . V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1340 . V_506 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_1340 . V_506 ,
V_146 ) )
return - V_16 ;
switch ( V_1340 . V_506 . V_509 ) {
case V_523 :
case V_524 :
case V_510 :
break;
case V_565 :
case V_566 :
if ( V_7 -> V_18 . V_288 & V_1342 )
break;
default:
return - V_16 ;
}
V_1340 . V_1343 = ! ! V_30 -> V_5 [ V_1344 ] ;
V_1340 . V_701 = ! ! V_30 -> V_5 [ V_702 ] ;
if ( V_30 -> V_5 [ V_991 ] ) {
T_2 * V_1164 =
F_23 ( V_30 -> V_5 [ V_991 ] ) ;
int V_1345 =
F_24 ( V_30 -> V_5 [ V_991 ] ) ;
struct V_236 * V_237 =
V_18 -> V_354 [ V_1340 . V_506 . V_55 -> V_287 ] ;
V_35 = F_227 ( V_237 , V_1164 , V_1345 ,
& V_1340 . V_992 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_456 ] )
memcpy ( & V_1340 . V_1329 ,
F_23 ( V_30 -> V_5 [ V_456 ] ) ,
sizeof( V_1340 . V_1329 ) ) ;
if ( V_30 -> V_5 [ V_911 ] ) {
if ( ! V_30 -> V_5 [ V_456 ] )
return - V_16 ;
memcpy ( & V_1340 . V_883 ,
F_23 ( V_30 -> V_5 [ V_911 ] ) ,
sizeof( V_1340 . V_883 ) ) ;
}
if ( V_30 -> V_5 [ V_1346 ] &&
! F_268 ( V_7 , V_1340 . V_1337 ,
F_4 ( V_30 -> V_5 [ V_1346 ] ) ) )
return - V_16 ;
if ( V_1340 . V_701 && V_30 -> V_5 [ V_1347 ] ) {
bool V_132 = false ;
V_1341 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1347 ] ,
& V_132 ) ;
if ( F_17 ( V_1341 ) )
return F_18 ( V_1341 ) ;
if ( ( V_1340 . V_506 . V_509 != V_510 ) &&
V_132 ) {
F_41 ( V_1341 ) ;
return - V_16 ;
}
}
V_1340 . V_1300 =
F_208 ( V_30 -> V_5 [ V_1301 ] ) ;
V_1340 . V_1348 =
F_208 ( V_30 -> V_5 [ V_1349 ] ) ;
V_35 = F_270 ( V_7 , V_525 , & V_1340 , V_1341 ) ;
if ( V_35 )
F_271 ( V_1341 ) ;
return V_35 ;
}
static int F_272 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
if ( ! V_7 -> V_342 -> V_1350 )
return - V_526 ;
if ( V_525 -> V_28 -> V_141 != V_146 )
return - V_526 ;
return F_273 ( V_7 , V_525 , false ) ;
}
static int F_274 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
int V_1337 [ V_353 ] ;
V_22 V_1351 ;
int V_35 ;
if ( V_525 -> V_28 -> V_141 != V_146 &&
V_525 -> V_28 -> V_141 != V_145 )
return - V_526 ;
if ( ! V_7 -> V_342 -> V_424 )
return - V_526 ;
memset ( V_1337 , 0 , sizeof( V_1337 ) ) ;
if ( ! V_30 -> V_5 [ V_1346 ] )
return - V_16 ;
V_1351 = F_4 ( V_30 -> V_5 [ V_1346 ] ) ;
if ( ! F_268 ( V_7 , V_1337 , V_1351 ) )
return - V_16 ;
V_35 = V_7 -> V_342 -> V_424 ( & V_7 -> V_18 , V_525 , V_1337 ) ;
return V_35 ;
}
static struct V_31 *
F_275 ( struct V_6 * V_7 ,
int V_1352 , V_22 V_49 , V_22 V_50 ,
enum V_277 V_52 ,
enum V_1353 V_45 ,
const struct V_472 * V_30 ,
T_12 V_1354 )
{
struct V_31 * V_32 ;
void * V_280 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1352 + 100 , V_1354 ) ;
if ( ! V_32 )
return NULL ;
V_280 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_280 ) {
F_276 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1355 ,
V_30 -> V_1356 ) )
goto V_61;
if ( F_28 ( V_32 , V_1357 ,
V_30 -> V_1358 ) )
goto V_61;
}
V_138 = F_47 ( V_32 , V_45 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_280 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_138 ;
return V_32 ;
V_61:
F_276 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_277 ( struct V_18 * V_18 ,
enum V_277 V_52 ,
enum V_1353 V_45 ,
int V_1359 ,
int V_1352 , T_12 V_1354 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_472 * V_30 ;
switch ( V_52 ) {
case V_1360 :
if ( F_59 ( V_1359 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1361 :
if ( F_59 ( V_1359 < 0 ||
V_1359 >= V_18 -> V_476 ) )
return NULL ;
V_30 = & V_18 -> V_478 [ V_1359 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_275 ( V_7 , V_1352 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1354 ) ;
}
void F_278 ( struct V_31 * V_32 , T_12 V_1354 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_280 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1362 V_1363 = V_1364 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_280 ) ;
if ( V_138 -> F_226 == V_474 )
V_1363 = V_1365 ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1363 , V_1354 ) ;
}
static int F_279 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_342 -> V_426 )
return - V_526 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1366 ] )
return - V_16 ;
V_7 -> V_1367 = V_30 ;
V_35 = F_280 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1366 ] ) ,
F_24 ( V_30 -> V_5 [ V_1366 ] ) ) ;
V_7 -> V_1367 = NULL ;
return V_35 ;
}
static int F_281 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1368 ;
void * V_138 = NULL ;
int V_1369 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1368 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_864;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_864;
}
V_1368 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1366 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1366 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1369 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1368 ) ;
if ( ! V_7 ) {
V_35 = - V_638 ;
goto V_864;
}
if ( ! V_7 -> V_342 -> V_1370 ) {
V_35 = - V_526 ;
goto V_864;
}
while ( 1 ) {
void * V_280 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_486 , V_487 ,
V_1360 ) ;
struct V_4 * V_1371 ;
if ( ! V_280 )
break;
if ( F_28 ( V_32 , V_26 , V_1368 ) ) {
F_67 ( V_32 , V_280 ) ;
break;
}
V_1371 = F_47 ( V_32 , V_1366 ) ;
if ( ! V_1371 ) {
F_67 ( V_32 , V_280 ) ;
break;
}
V_35 = F_282 ( V_7 , V_32 , V_34 , V_138 , V_1369 ) ;
F_48 ( V_32 , V_1371 ) ;
if ( V_35 == - V_91 || V_35 == - V_638 ) {
F_67 ( V_32 , V_280 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_280 ) ;
goto V_864;
}
F_66 ( V_32 , V_280 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1368 + 1 ;
V_864:
F_20 () ;
return V_35 ;
}
static int F_283 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1372 V_440 ;
struct V_18 * V_18 ;
struct V_130 * V_1341 = NULL ;
int V_35 ;
memset ( & V_440 , 0 , sizeof( V_440 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_577 ] ||
! F_24 ( V_30 -> V_5 [ V_577 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_703 ] ) {
V_440 . V_685 =
F_4 ( V_30 -> V_5 [ V_703 ] ) ;
if ( ! F_147 ( V_7 , V_440 . V_685 ,
V_441 ) )
return - V_16 ;
} else
V_440 . V_685 = V_704 ;
V_440 . V_701 = V_30 -> V_5 [ V_702 ] ;
V_35 = F_150 ( V_7 , V_30 , & V_440 . V_705 ,
V_706 ) ;
if ( V_35 )
return V_35 ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
V_18 = & V_7 -> V_18 ;
V_440 . V_1373 = - 1 ;
if ( V_30 -> V_5 [ V_1374 ] &&
( V_18 -> V_51 & V_321 ) ) {
V_440 . V_1373 =
F_78 ( V_30 -> V_5 [ V_1374 ] ) ;
}
if ( V_30 -> V_5 [ V_533 ] )
V_440 . V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
else if ( V_30 -> V_5 [ V_1375 ] )
V_440 . V_1376 =
F_23 ( V_30 -> V_5 [ V_1375 ] ) ;
V_440 . V_578 = F_23 ( V_30 -> V_5 [ V_577 ] ) ;
V_440 . V_576 = F_24 ( V_30 -> V_5 [ V_577 ] ) ;
if ( V_30 -> V_5 [ V_666 ] ) {
V_440 . V_1110 = F_23 ( V_30 -> V_5 [ V_666 ] ) ;
V_440 . V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
}
if ( V_30 -> V_5 [ V_1319 ] ) {
V_440 . V_1321 = F_4 ( V_30 -> V_5 [ V_1319 ] ) ;
if ( V_440 . V_1321 != V_1322 &&
V_440 . V_1321 != V_1324 )
return - V_16 ;
} else {
V_440 . V_1321 = V_1324 ;
}
if ( V_30 -> V_5 [ V_508 ] ) {
V_440 . V_1246 = F_44 (
V_18 , V_30 -> V_5 [ V_508 ] ) ;
if ( ! V_440 . V_1246 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1377 ] ) {
V_440 . V_1378 = F_44 (
V_18 , V_30 -> V_5 [ V_1377 ] ) ;
if ( ! V_440 . V_1378 )
return - V_16 ;
}
if ( V_440 . V_701 && V_30 -> V_5 [ V_1347 ] ) {
V_1341 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1347 ] , NULL ) ;
if ( F_17 ( V_1341 ) )
return F_18 ( V_1341 ) ;
}
if ( F_208 ( V_30 -> V_5 [ V_1327 ] ) )
V_440 . V_51 |= V_1328 ;
if ( V_30 -> V_5 [ V_456 ] )
memcpy ( & V_440 . V_1329 ,
F_23 ( V_30 -> V_5 [ V_456 ] ) ,
sizeof( V_440 . V_1329 ) ) ;
if ( V_30 -> V_5 [ V_911 ] ) {
if ( ! V_30 -> V_5 [ V_456 ] ) {
F_271 ( V_1341 ) ;
return - V_16 ;
}
memcpy ( & V_440 . V_883 ,
F_23 ( V_30 -> V_5 [ V_911 ] ) ,
sizeof( V_440 . V_883 ) ) ;
}
if ( F_208 ( V_30 -> V_5 [ V_1330 ] ) )
V_440 . V_51 |= V_1331 ;
if ( V_30 -> V_5 [ V_465 ] )
memcpy ( & V_440 . V_1332 ,
F_23 ( V_30 -> V_5 [ V_465 ] ) ,
sizeof( V_440 . V_1332 ) ) ;
if ( V_30 -> V_5 [ V_912 ] ) {
if ( ! V_30 -> V_5 [ V_465 ] ) {
F_271 ( V_1341 ) ;
return - V_16 ;
}
memcpy ( & V_440 . V_884 ,
F_23 ( V_30 -> V_5 [ V_912 ] ) ,
sizeof( V_440 . V_884 ) ) ;
}
if ( F_208 ( V_30 -> V_5 [ V_1333 ] ) ) {
if ( ! ( V_7 -> V_18 . V_288 &
V_1334 ) ||
! ( V_7 -> V_18 . V_288 & V_1335 ) )
return - V_16 ;
V_440 . V_51 |= V_1336 ;
}
F_112 ( V_525 -> V_28 ) ;
V_35 = F_284 ( V_7 , V_525 , & V_440 , V_1341 , NULL ) ;
F_114 ( V_525 -> V_28 ) ;
if ( V_35 )
F_271 ( V_1341 ) ;
return V_35 ;
}
static int F_285 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_3 V_1379 ;
int V_482 ;
if ( ! V_30 -> V_5 [ V_943 ] )
V_1379 = V_1380 ;
else
V_1379 = F_78 ( V_30 -> V_5 [ V_943 ] ) ;
if ( V_1379 == 0 )
return - V_16 ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
F_112 ( V_525 -> V_28 ) ;
V_482 = F_286 ( V_7 , V_525 , V_1379 , true ) ;
F_114 ( V_525 -> V_28 ) ;
return V_482 ;
}
static int F_287 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
V_22 V_1381 ;
if ( ! V_30 -> V_5 [ V_1382 ] )
return - V_16 ;
V_1381 = F_4 ( V_30 -> V_5 [ V_1382 ] ) ;
V_2 = F_288 ( V_1381 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_289 ( V_7 , V_2 ) ;
F_290 ( V_2 ) ;
return V_35 ;
}
static int F_291 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
int (* F_292)( struct V_18 * V_18 , struct V_25 * V_525 ,
struct V_1383 * V_1384 ) = NULL ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1383 V_1384 ;
memset ( & V_1384 , 0 , sizeof( struct V_1383 ) ) ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1385 ] )
return - V_16 ;
V_1384 . V_1386 = F_23 ( V_30 -> V_5 [ V_1385 ] ) ;
V_1384 . V_532 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
switch ( V_30 -> V_1387 -> V_52 ) {
case V_1388 :
F_292 = V_7 -> V_342 -> V_388 ;
break;
case V_1389 :
F_292 = V_7 -> V_342 -> V_390 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_292 )
return - V_526 ;
return F_292 ( & V_7 -> V_18 , V_525 , & V_1384 ) ;
}
static int F_293 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
if ( V_525 -> V_28 -> V_141 != V_147 &&
V_525 -> V_28 -> V_141 != V_148 )
return - V_526 ;
if ( ! V_7 -> V_342 -> V_392 )
return - V_526 ;
return F_294 ( V_7 , V_525 ) ;
}
static int F_295 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 V_1390 , V_1391 ;
V_22 V_1392 = 0 ;
T_3 V_1393 ;
T_2 * V_1394 ;
bool V_1395 ;
if ( ! ( V_7 -> V_18 . V_51 & V_323 ) ||
! V_7 -> V_342 -> V_409 )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_1396 ] ||
! V_30 -> V_5 [ V_1397 ] ||
! V_30 -> V_5 [ V_1398 ] ||
! V_30 -> V_5 [ V_666 ] ||
! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_1394 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_1390 = F_34 ( V_30 -> V_5 [ V_1396 ] ) ;
V_1393 = F_78 ( V_30 -> V_5 [ V_1397 ] ) ;
V_1391 = F_34 ( V_30 -> V_5 [ V_1398 ] ) ;
V_1395 = F_208 ( V_30 -> V_5 [ V_1399 ] ) ;
if ( V_30 -> V_5 [ V_1400 ] )
V_1392 =
F_4 ( V_30 -> V_5 [ V_1400 ] ) ;
return F_296 ( V_7 , V_525 , V_1394 , V_1390 ,
V_1391 , V_1393 , V_1392 ,
V_1395 ,
F_23 ( V_30 -> V_5 [ V_666 ] ) ,
F_24 ( V_30 -> V_5 [ V_666 ] ) ) ;
}
static int F_297 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
enum V_1401 V_1402 ;
T_2 * V_1394 ;
if ( ! ( V_7 -> V_18 . V_51 & V_323 ) ||
! V_7 -> V_342 -> V_411 )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_1403 ] ||
! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_1402 = F_34 ( V_30 -> V_5 [ V_1403 ] ) ;
V_1394 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
return F_298 ( V_7 , V_525 , V_1394 , V_1402 ) ;
}
static int F_299 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
struct V_505 V_506 ;
struct V_31 * V_53 ;
void * V_280 ;
T_1 V_630 ;
V_22 V_1404 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_508 ] ||
! V_30 -> V_5 [ V_1405 ] )
return - V_16 ;
V_1404 = F_4 ( V_30 -> V_5 [ V_1405 ] ) ;
if ( ! V_7 -> V_342 -> V_395 ||
! ( V_7 -> V_18 . V_51 & V_394 ) )
return - V_526 ;
if ( V_1404 < V_1406 ||
V_1404 > V_7 -> V_18 . V_445 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_506 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1407 ) ;
if ( ! V_280 ) {
V_35 = - V_91 ;
goto V_640;
}
V_35 = F_300 ( V_7 , V_17 , V_506 . V_55 ,
V_1404 , & V_630 ) ;
if ( V_35 )
goto V_640;
if ( F_104 ( V_53 , V_1408 , V_630 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_640:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_301 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
T_1 V_630 ;
if ( ! V_30 -> V_5 [ V_1408 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_1409 )
return - V_526 ;
V_630 = F_5 ( V_30 -> V_5 [ V_1408 ] ) ;
return F_302 ( V_7 , V_17 , V_630 ) ;
}
static V_22 F_303 ( struct V_236 * V_237 ,
T_2 * V_1164 , T_2 V_1410 )
{
T_2 V_159 ;
V_22 V_730 = 0 ;
for ( V_159 = 0 ; V_159 < V_1410 ; V_159 ++ ) {
int V_241 = ( V_1164 [ V_159 ] & 0x7f ) * 5 ;
int V_1411 ;
for ( V_1411 = 0 ; V_1411 < V_237 -> V_258 ; V_1411 ++ ) {
struct V_240 * V_1412 =
& V_237 -> V_259 [ V_1411 ] ;
if ( V_241 == V_1412 -> V_261 ) {
V_730 |= 1 << V_1411 ;
break;
}
}
if ( V_1411 == V_237 -> V_258 )
return 0 ;
}
return V_730 ;
}
static bool F_304 ( struct V_236 * V_237 ,
T_2 * V_1164 , T_2 V_1410 ,
T_2 V_245 [ V_1413 ] )
{
T_2 V_159 ;
memset ( V_245 , 0 , V_1413 ) ;
for ( V_159 = 0 ; V_159 < V_1410 ; V_159 ++ ) {
int V_1411 , V_1414 ;
V_1411 = V_1164 [ V_159 ] / 8 ;
V_1414 = F_157 ( V_1164 [ V_159 ] % 8 ) ;
if ( ( V_1411 < 0 ) || ( V_1411 >= V_1413 ) )
return false ;
if ( V_237 -> V_242 . V_245 . V_1415 [ V_1411 ] & V_1414 )
V_245 [ V_1411 ] |= V_1414 ;
else
return false ;
}
return true ;
}
static T_3 F_305 ( T_2 V_1416 )
{
T_3 V_1417 = 0 ;
switch ( V_1416 ) {
case V_1418 :
break;
case V_1419 :
V_1417 = 0x00FF ;
break;
case V_1420 :
V_1417 = 0x01FF ;
break;
case V_1421 :
V_1417 = 0x03FF ;
break;
default:
break;
}
return V_1417 ;
}
static void F_306 ( T_3 V_1416 ,
T_3 V_1422 [ V_1423 ] )
{
T_2 V_756 ;
for ( V_756 = 0 ; V_756 < V_1423 ; V_756 ++ ) {
V_1422 [ V_756 ] = F_305 ( V_1416 & 0x03 ) ;
V_1416 >>= 2 ;
}
}
static bool F_307 ( struct V_236 * V_237 ,
struct V_1424 * V_813 ,
T_3 V_245 [ V_1423 ] )
{
T_3 V_1425 = F_308 ( V_237 -> V_252 . V_255 . V_1425 ) ;
T_3 V_1426 [ V_1423 ] = {} ;
T_2 V_159 ;
if ( ! V_237 -> V_252 . V_253 )
return false ;
memset ( V_245 , 0 , sizeof( T_3 ) * V_1423 ) ;
F_306 ( V_1425 , V_1426 ) ;
for ( V_159 = 0 ; V_159 < V_1423 ; V_159 ++ ) {
if ( ( V_1426 [ V_159 ] & V_813 -> V_245 [ V_159 ] ) == V_813 -> V_245 [ V_159 ] )
V_245 [ V_159 ] = V_813 -> V_245 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_309 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1427 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1428 V_730 ;
int V_134 , V_159 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_4 * V_1429 ;
struct V_236 * V_237 ;
T_3 V_1430 ;
if ( ! V_7 -> V_342 -> V_397 )
return - V_526 ;
memset ( & V_730 , 0 , sizeof( V_730 ) ) ;
for ( V_159 = 0 ; V_159 < V_353 ; V_159 ++ ) {
V_237 = V_7 -> V_18 . V_354 [ V_159 ] ;
if ( ! V_237 )
continue;
V_730 . V_1431 [ V_159 ] . V_1432 = ( 1 << V_237 -> V_258 ) - 1 ;
memcpy ( V_730 . V_1431 [ V_159 ] . V_1433 ,
V_237 -> V_242 . V_245 . V_1415 ,
sizeof( V_730 . V_1431 [ V_159 ] . V_1433 ) ) ;
if ( ! V_237 -> V_252 . V_253 )
continue;
V_1430 = F_308 ( V_237 -> V_252 . V_255 . V_1425 ) ;
F_306 ( V_1430 , V_730 . V_1431 [ V_159 ] . V_255 ) ;
}
if ( ! V_30 -> V_5 [ V_1434 ] )
goto V_583;
F_113 ( V_1435 > V_1413 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_286 V_287 = F_226 ( V_1429 ) ;
int V_35 ;
if ( V_287 < 0 || V_287 >= V_353 )
return - V_16 ;
V_237 = V_7 -> V_18 . V_354 [ V_287 ] ;
if ( V_237 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1427 , F_23 ( V_1429 ) ,
F_24 ( V_1429 ) , V_1436 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1437 ] ) {
V_730 . V_1431 [ V_287 ] . V_1432 = F_303 (
V_237 ,
F_23 ( V_95 [ V_1437 ] ) ,
F_24 ( V_95 [ V_1437 ] ) ) ;
if ( ( V_730 . V_1431 [ V_287 ] . V_1432 == 0 ) &&
F_24 ( V_95 [ V_1437 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1438 ] ) {
if ( ! F_304 (
V_237 ,
F_23 ( V_95 [ V_1438 ] ) ,
F_24 ( V_95 [ V_1438 ] ) ,
V_730 . V_1431 [ V_287 ] . V_1433 ) )
return - V_16 ;
}
if ( V_95 [ V_1439 ] ) {
if ( ! F_307 (
V_237 ,
F_23 ( V_95 [ V_1439 ] ) ,
V_730 . V_1431 [ V_287 ] . V_255 ) )
return - V_16 ;
}
if ( V_95 [ V_1440 ] ) {
V_730 . V_1431 [ V_287 ] . V_1441 =
F_34 ( V_95 [ V_1440 ] ) ;
if ( V_730 . V_1431 [ V_287 ] . V_1441 > V_1442 )
return - V_16 ;
}
if ( V_730 . V_1431 [ V_287 ] . V_1432 == 0 ) {
if ( ! ( V_7 -> V_18 . V_354 [ V_287 ] -> V_242 . V_243 ||
V_7 -> V_18 . V_354 [ V_287 ] -> V_252 . V_253 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_1413 ; V_159 ++ )
if ( V_730 . V_1431 [ V_287 ] . V_1433 [ V_159 ] )
goto V_583;
for ( V_159 = 0 ; V_159 < V_1423 ; V_159 ++ )
if ( V_730 . V_1431 [ V_287 ] . V_255 [ V_159 ] )
goto V_583;
return - V_16 ;
}
}
V_583:
return F_310 ( V_7 , V_525 , NULL , & V_730 ) ;
}
static int F_311 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
T_3 V_1443 = V_274 | V_1444 ;
if ( ! V_30 -> V_5 [ V_1445 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_273 ] )
V_1443 = F_78 ( V_30 -> V_5 [ V_273 ] ) ;
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
return - V_526 ;
}
if ( ! V_7 -> V_342 -> V_399 )
return - V_526 ;
return F_312 ( V_17 , V_30 -> V_490 , V_1443 ,
F_23 ( V_30 -> V_5 [ V_1445 ] ) ,
F_24 ( V_30 -> V_5 [ V_1445 ] ) ) ;
}
static int F_313 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
struct V_505 V_506 ;
int V_35 ;
void * V_280 = NULL ;
T_1 V_630 ;
struct V_31 * V_53 = NULL ;
struct V_1446 V_137 = {
. V_1447 =
V_30 -> V_5 [ V_1448 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1449 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_399 )
return - V_526 ;
switch ( V_17 -> V_141 ) {
case V_154 :
if ( ! V_30 -> V_5 [ V_508 ] )
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
return - V_526 ;
}
if ( V_30 -> V_5 [ V_1405 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_446 ) )
return - V_16 ;
V_137 . V_1450 = F_4 ( V_30 -> V_5 [ V_1405 ] ) ;
if ( V_137 . V_1450 < V_1406 ||
V_137 . V_1450 > V_7 -> V_18 . V_445 )
return - V_16 ;
}
V_137 . V_1451 = V_30 -> V_5 [ V_447 ] ;
if ( V_137 . V_1451 && ! ( V_7 -> V_18 . V_51 & V_446 ) )
return - V_16 ;
V_137 . V_1171 = F_208 ( V_30 -> V_5 [ V_1172 ] ) ;
V_506 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_508 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_506 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_506 . V_55 && V_137 . V_1451 )
return - V_16 ;
V_137 . V_1452 = F_23 ( V_30 -> V_5 [ V_1449 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1449 ] ) ;
if ( V_30 -> V_5 [ V_1453 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1453 ] ) ;
int V_159 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1454 = V_47 / sizeof( T_3 ) ;
V_137 . V_1455 =
F_23 ( V_30 -> V_5 [ V_1453 ] ) ;
for ( V_159 = 0 ; V_159 < V_137 . V_1454 ; V_159 ++ ) {
if ( V_137 . V_1455 [ V_159 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1447 ) {
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1456 ) ;
if ( ! V_280 ) {
V_35 = - V_91 ;
goto V_640;
}
}
V_137 . V_55 = V_506 . V_55 ;
V_35 = F_314 ( V_7 , V_17 , & V_137 , & V_630 ) ;
if ( V_35 )
goto V_640;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1408 , V_630 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_640:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_315 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
T_1 V_630 ;
if ( ! V_30 -> V_5 [ V_1408 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_401 )
return - V_526 ;
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
return - V_526 ;
}
V_630 = F_5 ( V_30 -> V_5 [ V_1408 ] ) ;
return F_316 ( V_7 , V_17 , V_630 ) ;
}
static int F_317 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 V_1457 ;
bool V_279 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1458 ] )
return - V_16 ;
V_1457 = F_4 ( V_30 -> V_5 [ V_1458 ] ) ;
if ( V_1457 != V_1459 && V_1457 != V_1460 )
return - V_16 ;
V_17 = V_525 -> V_28 ;
if ( ! V_7 -> V_342 -> V_1461 )
return - V_526 ;
V_279 = ( V_1457 == V_1460 ) ? true : false ;
if ( V_279 == V_17 -> V_1462 )
return 0 ;
V_35 = F_318 ( V_7 , V_525 , V_279 , V_17 -> V_1463 ) ;
if ( ! V_35 )
V_17 -> V_1462 = V_279 ;
return V_35 ;
}
static int F_319 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
enum V_1464 V_1457 ;
struct V_1 * V_17 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_31 * V_53 ;
void * V_280 ;
int V_35 ;
V_17 = V_525 -> V_28 ;
if ( ! V_7 -> V_342 -> V_1461 )
return - V_526 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1465 ) ;
if ( ! V_280 ) {
V_35 = - V_91 ;
goto V_640;
}
if ( V_17 -> V_1462 )
V_1457 = V_1460 ;
else
V_1457 = V_1459 ;
if ( F_28 ( V_53 , V_1458 , V_1457 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_640:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_320 ( struct V_29 * V_30 ,
V_22 V_241 , V_22 V_1466 , V_22 V_1467 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
if ( V_241 > 100 || V_1467 > V_1468 )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_1469 )
return - V_526 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_526 ;
return F_321 ( V_7 , V_525 , V_241 , V_1466 , V_1467 ) ;
}
static int F_322 ( struct V_29 * V_30 ,
T_11 V_1470 , V_22 V_1471 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
if ( V_1470 > 0 )
return - V_16 ;
if ( V_1470 == 0 )
V_1471 = 0 ;
if ( ! V_7 -> V_342 -> V_1472 )
return - V_526 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_526 ;
return F_323 ( V_7 , V_525 , V_1470 , V_1471 ) ;
}
static int F_324 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1473 + 1 ] ;
struct V_4 * V_1474 ;
int V_35 ;
V_1474 = V_30 -> V_5 [ V_1475 ] ;
if ( ! V_1474 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1473 , V_1474 ,
V_1476 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1477 ] &&
V_5 [ V_1478 ] ) {
T_11 V_1470 = V_1089 ( V_5 [ V_1477 ] ) ;
V_22 V_1471 = F_4 ( V_5 [ V_1478 ] ) ;
return F_322 ( V_30 , V_1470 , V_1471 ) ;
}
if ( V_5 [ V_1479 ] &&
V_5 [ V_1480 ] &&
V_5 [ V_1481 ] ) {
V_22 V_241 = F_4 ( V_5 [ V_1479 ] ) ;
V_22 V_1466 = F_4 ( V_5 [ V_1480 ] ) ;
V_22 V_1467 = F_4 ( V_5 [ V_1481 ] ) ;
return F_320 ( V_30 , V_241 , V_1466 , V_1467 ) ;
}
return - V_16 ;
}
static int F_325 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1482 V_1092 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1092 . V_506 ) ;
if ( V_35 )
return V_35 ;
return F_326 ( V_7 , V_525 , & V_1092 ) ;
}
static int F_327 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
return F_328 ( V_7 , V_525 ) ;
}
static int F_329 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1023 V_1085 ;
struct V_1091 V_1092 ;
int V_35 ;
memcpy ( & V_1085 , & V_1027 , sizeof( V_1085 ) ) ;
memcpy ( & V_1092 , & V_1483 , sizeof( V_1092 ) ) ;
if ( V_30 -> V_5 [ V_1029 ] ) {
V_35 = F_205 ( V_30 , & V_1085 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_601 ] ||
! F_24 ( V_30 -> V_5 [ V_601 ] ) )
return - V_16 ;
V_1092 . V_1484 = F_23 ( V_30 -> V_5 [ V_601 ] ) ;
V_1092 . V_1026 = F_24 ( V_30 -> V_5 [ V_601 ] ) ;
if ( V_30 -> V_5 [ V_1346 ] &&
! F_268 ( V_7 , V_1092 . V_1337 ,
F_4 ( V_30 -> V_5 [ V_1346 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_692 ] ) {
V_1092 . V_527 =
F_4 ( V_30 -> V_5 [ V_692 ] ) ;
if ( V_1092 . V_527 < 10 ||
V_1092 . V_527 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_693 ] ) {
V_1092 . V_695 =
F_4 ( V_30 -> V_5 [ V_693 ] ) ;
if ( V_1092 . V_695 < 1 || V_1092 . V_695 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1094 ] ) {
V_35 = F_207 ( V_30 , & V_1092 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1092 . V_1114 )
V_1085 . V_1045 = false ;
if ( V_30 -> V_5 [ V_508 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1092 . V_506 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1092 . V_506 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_991 ] ) {
T_2 * V_1164 = F_23 ( V_30 -> V_5 [ V_991 ] ) ;
int V_1345 =
F_24 ( V_30 -> V_5 [ V_991 ] ) ;
struct V_236 * V_237 ;
if ( ! V_1092 . V_506 . V_55 )
return - V_16 ;
V_237 = V_7 -> V_18 . V_354 [ V_1092 . V_506 . V_55 -> V_287 ] ;
V_35 = F_227 ( V_237 , V_1164 , V_1345 ,
& V_1092 . V_992 ) ;
if ( V_35 )
return V_35 ;
}
return F_330 ( V_7 , V_525 , & V_1092 , & V_1085 ) ;
}
static int F_331 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
return F_332 ( V_7 , V_525 ) ;
}
static int F_333 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1485 * V_189 = V_7 -> V_18 . V_1486 ;
struct V_4 * V_1487 , * V_1488 ;
int V_159 , V_1489 ;
if ( ! V_189 -> V_219 )
return 0 ;
V_1487 = F_47 ( V_53 , V_228 ) ;
if ( ! V_1487 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_189 -> V_219 ; V_159 ++ ) {
V_1488 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1488 )
return - V_91 ;
V_1489 = V_189 -> V_1490 [ V_159 ] . V_1491 ;
if ( F_51 ( V_53 , V_1492 , F_334 ( V_1489 , 8 ) ,
V_189 -> V_1490 [ V_159 ] . V_730 ) ||
F_51 ( V_53 , V_1493 , V_1489 ,
V_189 -> V_1490 [ V_159 ] . V_1494 ) ||
F_28 ( V_53 , V_1495 ,
V_189 -> V_1490 [ V_159 ] . V_1496 ) )
return - V_91 ;
F_48 ( V_53 , V_1488 ) ;
}
F_48 ( V_53 , V_1487 ) ;
return 0 ;
}
static int F_335 ( struct V_31 * V_53 ,
struct V_1497 * V_188 )
{
struct V_4 * V_190 ;
if ( ! V_188 )
return 0 ;
V_190 = F_47 ( V_53 , V_191 ) ;
if ( ! V_190 )
return - V_91 ;
if ( F_336 ( V_53 , V_1498 , V_188 -> V_1499 ) ||
F_336 ( V_53 , V_1500 , V_188 -> V_946 ) ||
F_51 ( V_53 , V_1501 , V_573 , V_188 -> V_1502 ) ||
F_55 ( V_53 , V_1503 , V_188 -> V_1504 ) ||
F_55 ( V_53 , V_1505 , V_188 -> V_1506 ) ||
F_51 ( V_53 , V_192 ,
V_188 -> V_1507 , V_188 -> V_1508 ) ||
F_28 ( V_53 , V_197 ,
V_188 -> V_1509 ) ||
F_51 ( V_53 , V_199 ,
V_188 -> V_1510 , V_188 -> V_1511 ) ||
F_51 ( V_53 , V_1512 ,
F_334 ( V_188 -> V_1510 , 8 ) , V_188 -> V_1513 ) )
return - V_91 ;
if ( V_188 -> V_1514 . V_47 &&
F_51 ( V_53 , V_194 ,
sizeof( V_188 -> V_1514 ) , & V_188 -> V_1514 ) )
return - V_91 ;
if ( V_188 -> V_1515 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_188 -> V_1515 ) + V_188 -> V_1516 ,
& V_188 -> V_1515 ) )
return - V_91 ;
F_48 ( V_53 , V_190 ) ;
return 0 ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_31 * V_53 ;
void * V_280 ;
V_22 V_1517 = V_584 ;
if ( ! V_7 -> V_18 . V_189 )
return - V_526 ;
if ( V_7 -> V_18 . V_1486 && V_7 -> V_18 . V_1486 -> V_188 ) {
V_1517 += V_7 -> V_18 . V_1486 -> V_188 -> V_1516 +
V_7 -> V_18 . V_1486 -> V_188 -> V_1507 +
V_7 -> V_18 . V_1486 -> V_188 -> V_1510 +
V_7 -> V_18 . V_1486 -> V_188 -> V_1510 / 8 ;
}
V_53 = F_74 ( V_1517 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1518 ) ;
if ( ! V_280 )
goto V_61;
if ( V_7 -> V_18 . V_1486 ) {
struct V_4 * V_201 ;
V_201 = F_47 ( V_53 , V_1519 ) ;
if ( ! V_201 )
goto V_61;
if ( ( V_7 -> V_18 . V_1486 -> V_1520 &&
F_29 ( V_53 , V_204 ) ) ||
( V_7 -> V_18 . V_1486 -> V_442 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1486 -> V_1521 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1486 -> V_1522 &&
F_29 ( V_53 , V_212 ) ) ||
( V_7 -> V_18 . V_1486 -> V_1523 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1486 -> V_1524 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1486 -> V_1525 &&
F_29 ( V_53 , V_218 ) ) )
goto V_61;
if ( F_333 ( V_53 , V_7 ) )
goto V_61;
if ( F_335 ( V_53 ,
V_7 -> V_18 . V_1486 -> V_188 ) )
goto V_61;
F_48 ( V_53 , V_201 ) ;
}
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_338 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1485 * V_1526 )
{
struct V_4 * V_95 [ V_1527 ] ;
struct V_1497 * V_1085 ;
struct V_1528 * V_195 = NULL ;
struct V_1529 * V_50 = NULL ;
V_22 V_1517 ;
V_22 V_1530 , V_1531 , V_1516 = 0 , V_1532 ;
int V_35 , V_1533 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1534 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1535 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1498 ] ||
! V_95 [ V_1500 ] ||
! V_95 [ V_1501 ] ||
! V_95 [ V_1505 ] ||
! V_95 [ V_192 ] ||
! V_95 [ V_197 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_1512 ] )
return - V_16 ;
V_1530 = F_24 ( V_95 [ V_192 ] ) ;
if ( V_1530 > V_7 -> V_18 . V_189 -> V_188 -> V_193 )
return - V_16 ;
if ( F_4 ( V_95 [ V_197 ] ) >
V_7 -> V_18 . V_189 -> V_188 -> V_198 ||
F_4 ( V_95 [ V_197 ] ) == 0 )
return - V_16 ;
V_1531 = F_24 ( V_95 [ V_199 ] ) ;
if ( V_1531 > V_7 -> V_18 . V_189 -> V_188 -> V_200 )
return - V_16 ;
V_1532 = F_24 ( V_95 [ V_1512 ] ) ;
if ( V_1532 != F_334 ( V_1531 , 8 ) )
return - V_16 ;
if ( V_95 [ V_196 ] ) {
V_22 V_1536 = F_24 ( V_95 [ V_196 ] ) ;
V_195 = F_23 ( V_95 [ V_196 ] ) ;
V_1516 = V_1536 - sizeof( * V_195 ) ;
if ( ! V_195 -> V_47 || V_1516 % V_195 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_195 )
return - V_16 ;
if ( V_195 -> V_47 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1537 )
return - V_16 ;
if ( V_195 -> V_47 < V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1538 )
return - V_16 ;
if ( V_1516 > V_7 -> V_18 . V_189 -> V_188 -> V_195 -> V_1539 )
return - V_16 ;
if ( V_195 -> V_1217 + V_195 -> V_47 > V_1530 )
return - V_16 ;
}
if ( V_95 [ V_194 ] ) {
V_50 = F_23 ( V_95 [ V_194 ] ) ;
if ( ! V_7 -> V_18 . V_189 -> V_188 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1217 > V_1530 )
return - V_16 ;
}
V_1517 = sizeof( * V_1085 ) ;
V_1517 += V_1530 ;
V_1517 += V_1531 + V_1532 ;
V_1517 += V_1516 ;
V_1085 = F_38 ( V_1517 , V_135 ) ;
if ( ! V_1085 )
return - V_136 ;
V_1085 -> V_1499 = F_339 ( V_95 [ V_1498 ] ) ;
V_1085 -> V_946 = F_339 ( V_95 [ V_1500 ] ) ;
memcpy ( V_1085 -> V_1502 , F_23 ( V_95 [ V_1501 ] ) ,
V_573 ) ;
if ( V_95 [ V_1503 ] )
V_1533 = F_78 ( V_95 [ V_1503 ] ) ;
else
V_1533 = 0 ;
#ifdef F_340
V_35 = F_341 ( F_7 ( & V_7 -> V_18 ) , V_1540 , V_1541 ,
V_1542 , & V_1085 -> V_1543 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1085 ) ;
return V_35 ;
}
if ( F_342 ( V_1085 -> V_1543 -> V_44 , V_1533 ) ) {
F_343 ( V_1085 -> V_1543 ) ;
F_41 ( V_1085 ) ;
return - V_1544 ;
}
V_1085 -> V_1504 = F_344 ( V_1085 -> V_1543 -> V_44 ) -> V_1545 ;
#else
if ( ! V_1533 ) {
F_41 ( V_1085 ) ;
return - V_16 ;
}
V_1085 -> V_1504 = V_1533 ;
#endif
V_1085 -> V_1506 = F_78 ( V_95 [ V_1505 ] ) ;
V_1085 -> V_1507 = V_1530 ;
V_1085 -> V_1508 = ( T_2 * ) V_1085 + sizeof( * V_1085 ) + V_1516 ;
memcpy ( ( void * ) V_1085 -> V_1508 ,
F_23 ( V_95 [ V_192 ] ) ,
V_1530 ) ;
if ( V_50 )
V_1085 -> V_1514 = * V_50 ;
V_1085 -> V_1509 = F_4 ( V_95 [ V_197 ] ) ;
V_1085 -> V_1510 = V_1531 ;
V_1085 -> V_1511 = ( T_2 * ) V_1085 + sizeof( * V_1085 ) + V_1516 + V_1530 ;
memcpy ( ( void * ) V_1085 -> V_1511 ,
F_23 ( V_95 [ V_199 ] ) ,
V_1531 ) ;
V_1085 -> V_1513 = ( T_2 * ) V_1085 + sizeof( * V_1085 ) + V_1516 +
V_1530 + V_1531 ;
memcpy ( ( void * ) V_1085 -> V_1513 ,
F_23 ( V_95 [ V_1512 ] ) ,
V_1532 ) ;
if ( V_195 ) {
V_1085 -> V_1516 = V_1516 ;
memcpy ( & V_1085 -> V_1515 , V_195 , sizeof( * V_195 ) + V_1516 ) ;
}
V_1526 -> V_188 = V_1085 ;
return 0 ;
}
static int F_345 ( struct V_6 * V_7 ,
const struct V_1546 * V_189 ,
struct V_4 * V_45 ,
struct V_1485 * V_1526 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_38 ( V_1547 * sizeof( * V_95 ) , V_135 ) ;
if ( ! V_95 )
return - V_136 ;
if ( ! ( V_189 -> V_51 & V_1548 ) ) {
V_35 = - V_526 ;
goto V_583;
}
V_35 = F_96 ( V_95 , V_1204 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_583;
V_1526 -> V_1549 = F_231 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_233 ( V_1526 -> V_1549 ) ;
if ( V_35 )
V_1526 -> V_1549 = NULL ;
V_583:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_346 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_4 * V_95 [ V_1550 ] ;
struct V_1485 V_1551 = {} ;
struct V_1485 * V_1552 ;
const struct V_1546 * V_189 = V_7 -> V_18 . V_189 ;
int V_35 , V_159 ;
bool V_1553 = V_7 -> V_18 . V_1486 ;
if ( ! V_189 )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_1519 ] ) {
F_347 ( V_7 ) ;
V_7 -> V_18 . V_1486 = NULL ;
goto V_1554;
}
V_35 = F_96 ( V_95 , V_1555 ,
F_23 ( V_30 -> V_5 [ V_1519 ] ) ,
F_24 ( V_30 -> V_5 [ V_1519 ] ) ,
V_1556 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_204 ] ) {
if ( ! ( V_189 -> V_51 & V_203 ) )
return - V_16 ;
V_1551 . V_1520 = true ;
}
if ( V_95 [ V_206 ] ) {
if ( ! ( V_189 -> V_51 & V_205 ) )
return - V_16 ;
V_1551 . V_442 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_189 -> V_51 & V_207 ) )
return - V_16 ;
V_1551 . V_1521 = true ;
}
if ( V_95 [ V_210 ] )
return - V_16 ;
if ( V_95 [ V_212 ] ) {
if ( ! ( V_189 -> V_51 & V_211 ) )
return - V_16 ;
V_1551 . V_1522 = true ;
}
if ( V_95 [ V_214 ] ) {
if ( ! ( V_189 -> V_51 & V_213 ) )
return - V_16 ;
V_1551 . V_1523 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_189 -> V_51 & V_215 ) )
return - V_16 ;
V_1551 . V_1524 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_189 -> V_51 & V_217 ) )
return - V_16 ;
V_1551 . V_1525 = true ;
}
if ( V_95 [ V_228 ] ) {
struct V_4 * V_221 ;
int V_219 = 0 ;
int V_134 , V_1489 , V_1557 , V_1496 ;
struct V_4 * V_1558 [ V_1559 ] ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_189 -> V_219 )
return - V_16 ;
V_1551 . V_1490 = F_348 ( V_219 ,
sizeof( V_1551 . V_1490 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1551 . V_1490 )
return - V_136 ;
V_1551 . V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1560 ;
F_96 ( V_1558 , V_1561 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1558 [ V_1492 ] ||
! V_1558 [ V_1493 ] )
goto error;
V_1489 = F_24 ( V_1558 [ V_1493 ] ) ;
V_1557 = F_334 ( V_1489 , 8 ) ;
if ( F_24 ( V_1558 [ V_1492 ] ) != V_1557 )
goto error;
if ( V_1489 > V_189 -> V_226 ||
V_1489 < V_189 -> V_224 )
goto error;
if ( ! V_1558 [ V_1495 ] )
V_1496 = 0 ;
else
V_1496 = F_4 (
V_1558 [ V_1495 ] ) ;
if ( V_1496 > V_189 -> V_227 )
goto error;
V_1551 . V_1490 [ V_159 ] . V_1496 = V_1496 ;
V_1560 = F_349 ( V_1557 + V_1489 , V_135 ) ;
if ( ! V_1560 ) {
V_35 = - V_136 ;
goto error;
}
V_1551 . V_1490 [ V_159 ] . V_730 = V_1560 ;
memcpy ( V_1560 , F_23 ( V_1558 [ V_1492 ] ) ,
V_1557 ) ;
V_1560 += V_1557 ;
V_1551 . V_1490 [ V_159 ] . V_1494 = V_1560 ;
V_1551 . V_1490 [ V_159 ] . V_1491 = V_1489 ;
memcpy ( V_1560 ,
F_23 ( V_1558 [ V_1493 ] ) ,
V_1489 ) ;
V_159 ++ ;
}
}
if ( V_95 [ V_191 ] ) {
V_35 = F_338 (
V_7 , V_95 [ V_191 ] ,
& V_1551 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_1562 ] ) {
V_35 = F_345 (
V_7 , V_189 , V_95 [ V_1562 ] ,
& V_1551 ) ;
if ( V_35 )
goto error;
}
V_1552 = F_350 ( & V_1551 , sizeof( V_1551 ) , V_135 ) ;
if ( ! V_1552 ) {
V_35 = - V_136 ;
goto error;
}
F_347 ( V_7 ) ;
V_7 -> V_18 . V_1486 = V_1552 ;
V_1554:
if ( V_7 -> V_342 -> V_1554 &&
V_1553 != ! ! V_7 -> V_18 . V_1486 )
F_351 ( V_7 , V_7 -> V_18 . V_1486 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1551 . V_219 ; V_159 ++ )
F_41 ( V_1551 . V_1490 [ V_159 ] . V_730 ) ;
F_41 ( V_1551 . V_1490 ) ;
if ( V_1551 . V_188 && V_1551 . V_188 -> V_1543 )
F_343 ( V_1551 . V_188 -> V_1543 ) ;
F_41 ( V_1551 . V_188 ) ;
return V_35 ;
}
static int F_352 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1487 , * V_1488 , * V_1563 , * V_1564 ;
int V_159 , V_161 , V_1489 ;
struct V_1565 * V_230 ;
if ( ! V_7 -> V_231 -> V_233 )
return 0 ;
V_1564 = F_47 ( V_53 , V_235 ) ;
if ( ! V_1564 )
return - V_91 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_231 -> V_233 ; V_159 ++ ) {
V_1563 = F_47 ( V_53 , V_159 + 1 ) ;
if ( ! V_1563 )
return - V_91 ;
V_230 = & V_7 -> V_231 -> V_1566 [ V_159 ] ;
if ( F_28 ( V_53 , V_1567 ,
V_230 -> V_1568 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1569 ,
V_230 -> V_1570 ) )
return - V_91 ;
V_1487 = F_47 ( V_53 ,
V_1571 ) ;
if ( ! V_1487 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_230 -> V_219 ; V_161 ++ ) {
V_1488 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1488 )
return - V_91 ;
V_1489 = V_230 -> V_1490 [ V_161 ] . V_1491 ;
if ( F_51 ( V_53 , V_1492 ,
F_334 ( V_1489 , 8 ) ,
V_230 -> V_1490 [ V_161 ] . V_730 ) ||
F_51 ( V_53 , V_1493 , V_1489 ,
V_230 -> V_1490 [ V_161 ] . V_1494 ) ||
F_28 ( V_53 , V_1495 ,
V_230 -> V_1490 [ V_161 ] . V_1496 ) )
return - V_91 ;
F_48 ( V_53 , V_1488 ) ;
}
F_48 ( V_53 , V_1487 ) ;
F_48 ( V_53 , V_1563 ) ;
}
F_48 ( V_53 , V_1564 ) ;
return 0 ;
}
static int F_353 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_31 * V_53 ;
void * V_280 ;
if ( ! V_7 -> V_18 . V_231 )
return - V_526 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1572 ) ;
if ( ! V_280 )
goto V_61;
if ( V_7 -> V_231 && F_352 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_354 ( struct V_6 * V_7 )
{
struct V_1573 * V_231 = V_7 -> V_231 ;
int V_159 , V_161 ;
struct V_1565 * V_230 ;
if ( ! V_231 )
return;
for ( V_159 = 0 ; V_159 < V_231 -> V_233 ; V_159 ++ ) {
V_230 = & V_231 -> V_1566 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_230 -> V_219 ; V_161 ++ )
F_41 ( V_230 -> V_1490 [ V_161 ] . V_730 ) ;
F_41 ( V_230 -> V_1490 ) ;
}
F_41 ( V_231 -> V_1566 ) ;
F_41 ( V_231 ) ;
V_7 -> V_231 = NULL ;
}
static int F_355 ( struct V_6 * V_7 ,
struct V_4 * V_230 ,
struct V_1565 * V_1574 )
{
int V_35 , V_159 ;
const struct V_1575 * V_231 = V_7 -> V_18 . V_231 ;
struct V_4 * V_95 [ V_1576 ] , * V_221 ;
int V_134 , V_1489 , V_1557 , V_1496 , V_219 = 0 ;
struct V_4 * V_1558 [ V_1559 ] ;
V_35 = F_96 ( V_95 , V_1577 , F_23 ( V_230 ) ,
F_24 ( V_230 ) , V_1578 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1567 ] )
V_1574 -> V_1568 =
F_4 ( V_95 [ V_1567 ] ) ;
if ( V_1574 -> V_1568 > V_231 -> V_234 )
return - V_16 ;
if ( V_95 [ V_1569 ] )
V_1574 -> V_1570 =
F_4 ( V_95 [ V_1569 ] ) ;
if ( V_1574 -> V_1570 != V_1579 &&
V_1574 -> V_1570 != V_1580 )
return - V_16 ;
if ( ! V_95 [ V_1571 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_219 ++ ;
if ( V_219 > V_231 -> V_219 )
return - V_16 ;
V_1574 -> V_1490 = F_348 ( V_219 , sizeof( V_1574 -> V_1490 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1574 -> V_1490 )
return - V_136 ;
V_1574 -> V_219 = V_219 ;
V_159 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1560 ;
F_96 ( V_1558 , V_1561 , F_23 ( V_221 ) ,
F_24 ( V_221 ) , NULL ) ;
if ( ! V_1558 [ V_1492 ] ||
! V_1558 [ V_1493 ] )
return - V_16 ;
V_1489 = F_24 ( V_1558 [ V_1493 ] ) ;
V_1557 = F_334 ( V_1489 , 8 ) ;
if ( F_24 ( V_1558 [ V_1492 ] ) != V_1557 )
return - V_16 ;
if ( V_1489 > V_231 -> V_226 ||
V_1489 < V_231 -> V_224 )
return - V_16 ;
if ( ! V_1558 [ V_1495 ] )
V_1496 = 0 ;
else
V_1496 = F_4 ( V_1558 [ V_1495 ] ) ;
if ( V_1496 > V_231 -> V_227 )
return - V_16 ;
V_1574 -> V_1490 [ V_159 ] . V_1496 = V_1496 ;
V_1560 = F_349 ( V_1557 + V_1489 , V_135 ) ;
if ( ! V_1560 )
return - V_136 ;
V_1574 -> V_1490 [ V_159 ] . V_730 = V_1560 ;
memcpy ( V_1560 , F_23 ( V_1558 [ V_1492 ] ) ,
V_1557 ) ;
V_1560 += V_1557 ;
V_1574 -> V_1490 [ V_159 ] . V_1494 = V_1560 ;
V_1574 -> V_1490 [ V_159 ] . V_1491 = V_1489 ;
memcpy ( V_1560 , F_23 ( V_1558 [ V_1493 ] ) ,
V_1489 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_356 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
const struct V_1575 * V_231 = V_7 -> V_18 . V_231 ;
struct V_1573 V_1581 = {} ;
struct V_1573 * V_1582 ;
int V_35 , V_1583 , V_233 = 0 , V_159 , V_161 ;
struct V_4 * V_230 ;
struct V_1565 * V_1584 ;
if ( ! V_7 -> V_18 . V_231 || ! V_7 -> V_342 -> V_1585 )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_235 ] ) {
F_354 ( V_7 ) ;
V_7 -> V_342 -> V_1585 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_233 ++ ;
if ( V_233 > V_231 -> V_233 )
return - V_16 ;
V_1581 . V_1566 = F_348 ( V_233 , sizeof( V_1581 . V_1566 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1581 . V_1566 )
return - V_136 ;
V_1581 . V_233 = V_233 ;
V_159 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_355 ( V_7 , V_230 ,
& V_1581 . V_1566 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = V_7 -> V_342 -> V_1585 ( & V_7 -> V_18 , & V_1581 ) ;
if ( V_35 )
goto error;
V_1582 = F_350 ( & V_1581 , sizeof( V_1581 ) , V_135 ) ;
if ( ! V_1582 ) {
V_35 = - V_136 ;
goto error;
}
F_354 ( V_7 ) ;
V_7 -> V_231 = V_1582 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1581 . V_233 ; V_159 ++ ) {
V_1584 = & V_1581 . V_1566 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1584 -> V_219 ; V_161 ++ )
F_41 ( V_1584 -> V_1490 [ V_161 ] . V_730 ) ;
F_41 ( V_1584 -> V_1490 ) ;
}
F_41 ( V_1581 . V_1566 ) ;
return V_35 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_4 * V_95 [ V_1586 ] ;
struct V_1587 V_1588 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1589 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1590 ,
F_23 ( V_30 -> V_5 [ V_1589 ] ) ,
F_24 ( V_30 -> V_5 [ V_1589 ] ) ,
V_1591 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1592 ] ) != V_1593 )
return - V_1594 ;
if ( F_24 ( V_95 [ V_1595 ] ) != V_1596 )
return - V_1594 ;
if ( F_24 ( V_95 [ V_1597 ] ) != V_1598 )
return - V_1594 ;
V_1588 . V_1599 = F_23 ( V_95 [ V_1595 ] ) ;
V_1588 . V_1600 = F_23 ( V_95 [ V_1597 ] ) ;
V_1588 . V_1601 = F_23 ( V_95 [ V_1592 ] ) ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1207 ;
goto V_583;
}
if ( ! V_7 -> V_342 -> V_1602 ) {
V_35 = - V_526 ;
goto V_583;
}
V_35 = F_358 ( V_7 , V_525 , & V_1588 ) ;
V_583:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_359 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1603 )
return - V_530 ;
V_17 -> V_1603 = V_30 -> V_490 ;
return 0 ;
}
static int F_360 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_31 * V_53 ;
void * V_280 ;
const T_2 * V_660 ;
T_1 V_630 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
if ( ! V_7 -> V_342 -> V_416 )
return - V_526 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1604 ) ;
if ( ! V_280 ) {
V_35 = - V_91 ;
goto V_640;
}
V_660 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_35 = F_361 ( V_7 , V_525 , V_660 , & V_630 ) ;
if ( V_35 )
goto V_640;
if ( F_104 ( V_53 , V_1408 , V_630 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_640:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_362 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1605 * V_1606 , * V_1607 ;
int V_1608 ;
if ( ! ( V_7 -> V_18 . V_51 & V_420 ) )
return - V_526 ;
V_1607 = F_38 ( sizeof( * V_1607 ) , V_135 ) ;
if ( ! V_1607 )
return - V_136 ;
F_251 ( & V_7 -> V_1609 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1606 -> V_1610 == V_30 -> V_490 ) {
V_1608 = - V_691 ;
goto V_864;
}
}
V_1607 -> V_1610 = V_30 -> V_490 ;
F_363 ( & V_1607 -> V_621 , & V_7 -> V_1611 ) ;
F_253 ( & V_7 -> V_1609 ) ;
return 0 ;
V_864:
F_253 ( & V_7 -> V_1609 ) ;
F_41 ( V_1607 ) ;
return V_1608 ;
}
static int F_364 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_342 -> V_422 )
return - V_526 ;
if ( V_17 -> V_141 != V_154 )
return - V_526 ;
if ( V_17 -> V_1612 )
return 0 ;
if ( F_365 ( V_7 -> V_1613 ) )
return - V_1614 ;
V_35 = F_366 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1612 = true ;
V_7 -> V_1615 ++ ;
return 0 ;
}
static int F_367 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_526 ;
if ( ! V_7 -> V_342 -> V_1616 )
return - V_526 ;
F_368 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_369 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_280 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , V_30 -> V_490 , V_30 -> V_491 , 0 ,
V_1617 ) ;
if ( ! V_280 )
goto V_61;
if ( F_28 ( V_53 , V_1618 ,
V_1619 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_276 ( V_53 ) ;
return - V_91 ;
}
static int F_370 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1620 V_1621 ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
if ( ! V_7 -> V_342 -> V_1622 )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_1623 ] ||
! F_22 ( V_30 -> V_5 [ V_666 ] ) )
return - V_16 ;
memset ( & V_1621 , 0 , sizeof( V_1621 ) ) ;
V_1621 . V_1624 = F_78 ( V_30 -> V_5 [ V_1623 ] ) ;
V_1621 . V_1110 = F_23 ( V_30 -> V_5 [ V_666 ] ) ;
V_1621 . V_1111 = F_24 ( V_30 -> V_5 [ V_666 ] ) ;
return F_371 ( V_7 , V_525 , & V_1621 ) ;
}
static int F_372 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
enum V_1625 V_1302 = V_1626 ;
T_3 V_1404 ;
int V_482 ;
if ( ! V_7 -> V_342 -> V_428 )
return - V_526 ;
if ( F_59 ( ! V_7 -> V_342 -> V_430 ) )
return - V_16 ;
if ( V_7 -> V_1627 )
return - V_530 ;
if ( V_30 -> V_5 [ V_1628 ] )
V_1302 = F_78 ( V_30 -> V_5 [ V_1628 ] ) ;
if ( V_1302 >= V_1629 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1630 ] )
return - V_16 ;
V_1404 =
F_78 ( V_30 -> V_5 [ V_1630 ] ) ;
if ( V_1404 > V_1631 )
return - V_1594 ;
V_482 = F_373 ( V_7 , V_17 , V_1302 , V_1404 ) ;
if ( ! V_482 )
V_7 -> V_1627 = V_30 -> V_490 ;
return V_482 ;
}
static int F_374 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
if ( ! V_7 -> V_342 -> V_430 )
return - V_526 ;
if ( V_7 -> V_1627 ) {
V_7 -> V_1627 = 0 ;
F_375 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_376 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_159 , V_35 ;
V_22 V_1632 , V_1358 ;
if ( ! V_7 -> V_18 . V_475 )
return - V_526 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1355 ] ||
! V_30 -> V_5 [ V_1357 ] )
return - V_16 ;
V_1632 = F_4 ( V_30 -> V_5 [ V_1355 ] ) ;
V_1358 = F_4 ( V_30 -> V_5 [ V_1357 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_471 ; V_159 ++ ) {
const struct V_1633 * V_1634 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1634 = & V_7 -> V_18 . V_475 [ V_159 ] ;
if ( V_1634 -> V_30 . V_1356 != V_1632 || V_1634 -> V_30 . V_1358 != V_1358 )
continue;
if ( V_1634 -> V_51 & ( V_1635 |
V_1636 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1634 -> V_51 & V_1636 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1634 -> V_51 & V_1637 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_540 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1612 )
return - V_540 ;
}
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_474 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_474 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_474 ] ) ;
}
V_7 -> V_1367 = V_30 ;
V_35 = V_7 -> V_18 . V_475 [ V_159 ] . F_377 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1367 = NULL ;
return V_35 ;
}
return - V_526 ;
}
struct V_31 * F_378 ( struct V_18 * V_18 ,
enum V_277 V_52 ,
enum V_1353 V_45 ,
int V_1352 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1367 ) )
return NULL ;
return F_275 ( V_7 , V_1352 ,
V_7 -> V_1367 -> V_490 ,
V_7 -> V_1367 -> V_491 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_379 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_280 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1367 ) ) {
F_276 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_280 ) ;
return F_76 ( V_32 , V_7 -> V_1367 ) ;
}
static int F_380 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_1638 * V_1639 = NULL ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
T_2 * V_46 , V_47 , V_1640 , V_1641 , V_1642 ;
int V_482 ;
if ( ! V_7 -> V_342 -> V_435 )
return - V_526 ;
if ( V_30 -> V_5 [ V_1643 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1643 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1643 ] ) ;
if ( V_47 % 2 || V_47 < V_1644 ||
V_47 > V_1645 )
return - V_16 ;
V_1639 = F_38 ( sizeof( struct V_1638 ) , V_135 ) ;
if ( ! V_1639 )
return - V_136 ;
V_1640 = ( V_47 - V_1644 ) >> 1 ;
if ( V_1640 ) {
V_1641 = V_1640 *
sizeof( struct V_1646 ) ;
memcpy ( V_1639 -> V_1647 , V_46 , V_1641 ) ;
V_1639 -> V_1640 = V_1640 ;
for ( V_1642 = 0 ; V_1642 < V_1640 ; V_1642 ++ ) {
if ( V_1639 -> V_1647 [ V_1642 ] . V_1648 > 7 ) {
F_41 ( V_1639 ) ;
return - V_16 ;
}
}
V_46 += V_1641 ;
}
memcpy ( V_1639 -> V_1648 , V_46 , V_1644 ) ;
}
F_112 ( V_525 -> V_28 ) ;
V_482 = F_42 ( V_525 -> V_28 ) ;
if ( ! V_482 )
V_482 = F_381 ( V_7 , V_525 , V_1639 ) ;
F_114 ( V_525 -> V_28 ) ;
F_41 ( V_1639 ) ;
return V_482 ;
}
static int F_382 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
const T_2 * V_1394 ;
T_2 V_1649 , V_1648 ;
T_3 V_1650 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_288 & V_437 ) )
return - V_526 ;
if ( ! V_30 -> V_5 [ V_1651 ] || ! V_30 -> V_5 [ V_533 ] ||
! V_30 -> V_5 [ V_1652 ] )
return - V_16 ;
V_1649 = F_34 ( V_30 -> V_5 [ V_1651 ] ) ;
if ( V_1649 >= V_1653 )
return - V_16 ;
V_1648 = F_34 ( V_30 -> V_5 [ V_1652 ] ) ;
if ( V_1648 >= V_1654 )
return - V_16 ;
if ( V_1649 >= V_1655 ) {
return - V_16 ;
}
V_1394 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
if ( V_30 -> V_5 [ V_1656 ] ) {
V_1650 =
F_78 ( V_30 -> V_5 [ V_1656 ] ) ;
if ( ! V_1650 )
return - V_16 ;
}
F_112 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1207 ;
goto V_583;
default:
V_35 = - V_526 ;
goto V_583;
}
V_35 = F_383 ( V_7 , V_525 , V_1649 , V_1394 , V_1648 , V_1650 ) ;
V_583:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_384 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
const T_2 * V_1394 ;
T_2 V_1649 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1651 ] || ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_1649 = F_34 ( V_30 -> V_5 [ V_1651 ] ) ;
V_1394 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
F_112 ( V_17 ) ;
V_35 = F_385 ( V_7 , V_525 , V_1649 , V_1394 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_386 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_505 V_506 = {} ;
const T_2 * V_660 ;
T_2 V_1657 ;
int V_35 ;
if ( ! V_7 -> V_342 -> V_1658 ||
! ( V_7 -> V_18 . V_288 & V_1659 ) )
return - V_526 ;
switch ( V_525 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_526 ;
}
if ( ! V_30 -> V_5 [ V_533 ] ||
! V_30 -> V_5 [ V_1660 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_506 ) ;
if ( V_35 )
return V_35 ;
if ( V_506 . V_55 -> V_287 == V_1661 &&
V_506 . V_509 != V_510 &&
V_506 . V_509 != V_565 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_506 , V_17 -> V_141 ) )
return - V_16 ;
if ( F_241 ( V_17 -> V_18 , & V_506 , V_17 -> V_141 ) )
return - V_16 ;
V_660 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
V_1657 = F_34 ( V_30 -> V_5 [ V_1660 ] ) ;
F_112 ( V_17 ) ;
V_35 = F_387 ( V_7 , V_525 , V_660 , V_1657 , & V_506 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_388 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_489 [ 0 ] ;
struct V_25 * V_525 = V_30 -> V_489 [ 1 ] ;
struct V_1 * V_17 = V_525 -> V_28 ;
const T_2 * V_660 ;
if ( ! V_7 -> V_342 -> V_1658 ||
! V_7 -> V_342 -> V_1662 ||
! ( V_7 -> V_18 . V_288 & V_1659 ) )
return - V_526 ;
switch ( V_525 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_526 ;
}
if ( ! V_30 -> V_5 [ V_533 ] )
return - V_16 ;
V_660 = F_23 ( V_30 -> V_5 [ V_533 ] ) ;
F_112 ( V_17 ) ;
F_389 ( V_7 , V_525 , V_660 ) ;
F_114 ( V_17 ) ;
return 0 ;
}
static int F_390 ( const struct V_1663 * V_342 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_525 ;
bool V_1664 = V_342 -> V_1665 & V_1666 ;
if ( V_1664 )
F_14 () ;
if ( V_342 -> V_1665 & V_1667 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1664 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_489 [ 0 ] = V_7 ;
} else if ( V_342 -> V_1665 & V_1668 ||
V_342 -> V_1665 & V_1669 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1664 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_525 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_342 -> V_1665 & V_1668 ) {
if ( ! V_525 ) {
if ( V_1664 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_489 [ 1 ] = V_525 ;
} else {
V_30 -> V_489 [ 1 ] = V_17 ;
}
if ( V_525 ) {
if ( V_342 -> V_1665 & V_1670 &&
! F_91 ( V_525 ) ) {
if ( V_1664 )
F_20 () ;
return - V_540 ;
}
F_230 ( V_525 ) ;
} else if ( V_342 -> V_1665 & V_1670 ) {
if ( ! V_17 -> V_1612 ) {
if ( V_1664 )
F_20 () ;
return - V_540 ;
}
}
V_30 -> V_489 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_391 ( const struct V_1663 * V_342 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_489 [ 1 ] ) {
if ( V_342 -> V_1665 & V_1669 ) {
struct V_1 * V_17 = V_30 -> V_489 [ 1 ] ;
if ( V_17 -> V_19 )
F_169 ( V_17 -> V_19 ) ;
} else {
F_169 ( V_30 -> V_489 [ 1 ] ) ;
}
}
if ( V_342 -> V_1665 & V_1666 )
F_20 () ;
if ( V_342 -> V_1665 & V_1671 ) {
struct V_1672 * V_36 = F_392 ( V_32 ) ;
memset ( F_393 ( V_36 ) , 0 , F_394 ( V_36 ) ) ;
}
}
void F_395 ( struct V_6 * V_7 ,
enum V_277 V_52 )
{
struct V_31 * V_53 ;
struct V_278 V_279 = {} ;
F_59 ( V_52 != V_292 &&
V_52 != V_1673 ) ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_279 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_623 , V_135 ) ;
}
static int F_396 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1153 * V_1318 = V_7 -> V_1157 ;
struct V_4 * V_1674 ;
int V_159 ;
if ( F_59 ( ! V_1318 ) )
return 0 ;
V_1674 = F_47 ( V_53 , V_1161 ) ;
if ( ! V_1674 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1318 -> V_1155 ; V_159 ++ ) {
if ( F_51 ( V_53 , V_159 , V_1318 -> V_1162 [ V_159 ] . V_576 , V_1318 -> V_1162 [ V_159 ] . V_578 ) )
goto V_61;
}
F_48 ( V_53 , V_1674 ) ;
V_1674 = F_47 ( V_53 , V_1160 ) ;
if ( ! V_1674 )
goto V_61;
for ( V_159 = 0 ; V_159 < V_1318 -> V_357 ; V_159 ++ ) {
if ( F_28 ( V_53 , V_159 , V_1318 -> V_358 [ V_159 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1674 ) ;
if ( V_1318 -> V_1110 &&
F_51 ( V_53 , V_666 , V_1318 -> V_1111 , V_1318 -> V_1110 ) )
goto V_61;
if ( V_1318 -> V_51 &&
F_28 ( V_53 , V_1166 , V_1318 -> V_51 ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_397 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_280 ;
V_280 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_280 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_396 ( V_53 , V_7 ) ;
return F_66 ( V_53 , V_280 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
static int
F_398 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_280 ;
V_280 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_280 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
return F_66 ( V_53 , V_280 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
return - V_481 ;
}
void F_229 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_397 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1675 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1676 , V_135 ) ;
}
struct V_31 * F_399 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1677 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_397 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1677 ? V_1678 :
V_1231 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_400 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1676 , V_135 ) ;
}
void F_401 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_398 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1679 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1676 , V_135 ) ;
}
void F_235 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_398 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1676 , V_135 ) ;
}
void F_402 ( struct V_1680 * V_1154 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1681 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_56 ( V_53 , V_1682 , V_1154 -> V_1395 ) )
goto V_61;
if ( V_1154 -> V_1126 [ 0 ] == '0' && V_1154 -> V_1126 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1683 ,
V_1684 ) )
goto V_61;
} else if ( V_1154 -> V_1126 [ 0 ] == '9' && V_1154 -> V_1126 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1683 ,
V_1685 ) )
goto V_61;
} else if ( ( V_1154 -> V_1126 [ 0 ] == '9' && V_1154 -> V_1126 [ 1 ] == '8' ) ||
V_1154 -> V_1686 ) {
if ( F_56 ( V_53 , V_1683 ,
V_1687 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1683 ,
V_1688 ) ||
F_60 ( V_53 , V_1021 ,
V_1154 -> V_1126 ) )
goto V_61;
}
if ( V_1154 -> V_14 != V_1689 &&
F_28 ( V_53 , V_26 , V_1154 -> V_14 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_213 () ;
F_403 ( & V_38 , V_53 , 0 ,
V_1690 , V_1691 ) ;
F_216 () ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
static void F_404 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1452 , T_10 V_47 ,
enum V_277 V_52 , T_12 V_1354 ,
int V_899 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1449 , V_47 , V_1452 ) )
goto V_61;
if ( V_899 >= 0 ) {
struct V_4 * V_1692 =
F_47 ( V_53 , V_896 ) ;
if ( ! V_1692 )
goto V_61;
if ( F_56 ( V_53 , V_898 ,
V_899 ) )
goto V_61;
F_48 ( V_53 , V_1692 ) ;
}
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_405 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1452 ,
T_10 V_47 , T_12 V_1354 )
{
F_404 ( V_7 , V_19 , V_1452 , V_47 ,
V_687 , V_1354 , - 1 ) ;
}
void F_406 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1452 ,
T_10 V_47 , T_12 V_1354 , int V_899 )
{
F_404 ( V_7 , V_19 , V_1452 , V_47 ,
V_1694 , V_1354 , V_899 ) ;
}
void F_407 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1452 ,
T_10 V_47 , T_12 V_1354 )
{
F_404 ( V_7 , V_19 , V_1452 , V_47 ,
V_1695 , V_1354 , - 1 ) ;
}
void F_408 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1452 ,
T_10 V_47 , T_12 V_1354 )
{
F_404 ( V_7 , V_19 , V_1452 , V_47 ,
V_1696 , V_1354 , - 1 ) ;
}
void F_409 ( struct V_25 * V_525 , const T_2 * V_1452 ,
T_10 V_47 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1697 * V_1698 = ( void * ) V_1452 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_410 ( V_1698 -> V_1699 ) )
V_52 = V_1700 ;
else
V_52 = V_1701 ;
F_411 ( V_525 , V_1452 , V_47 ) ;
F_404 ( V_7 , V_525 , V_1452 , V_47 , V_52 , V_1691 , - 1 ) ;
}
static void F_412 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_660 , T_12 V_1354 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1702 ) ||
F_51 ( V_53 , V_533 , V_573 , V_660 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_413 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_660 ,
T_12 V_1354 )
{
F_412 ( V_7 , V_19 , V_687 ,
V_660 , V_1354 ) ;
}
void F_414 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_660 ,
T_12 V_1354 )
{
F_412 ( V_7 , V_19 , V_1694 ,
V_660 , V_1354 ) ;
}
void F_415 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_532 ,
const T_2 * V_1703 , T_10 V_1704 ,
const T_2 * V_1705 , T_10 V_1706 ,
T_3 V_624 , T_12 V_1354 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_441 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_532 && F_51 ( V_53 , V_533 , V_573 , V_532 ) ) ||
F_55 ( V_53 , V_1397 , V_624 ) ||
( V_1703 &&
F_51 ( V_53 , V_1707 , V_1704 , V_1703 ) ) ||
( V_1705 &&
F_51 ( V_53 , V_1708 , V_1706 , V_1705 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_416 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_532 ,
const T_2 * V_1703 , T_10 V_1704 ,
const T_2 * V_1705 , T_10 V_1706 , T_12 V_1354 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1709 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_532 ) ||
( V_1703 &&
F_51 ( V_53 , V_1707 , V_1704 , V_1703 ) ) ||
( V_1705 &&
F_51 ( V_53 , V_1708 , V_1706 , V_1705 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_417 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1379 ,
const T_2 * V_1110 , T_10 V_1111 , bool V_1710 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_443 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1710 && V_1379 &&
F_55 ( V_53 , V_943 , V_1379 ) ) ||
( V_1710 &&
F_29 ( V_53 , V_1711 ) ) ||
( V_1110 && F_51 ( V_53 , V_666 , V_1111 , V_1110 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_418 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_532 ,
T_12 V_1354 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1712 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_532 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_419 ( struct V_25 * V_525 , const T_2 * V_660 ,
const T_2 * V_1110 , T_2 V_1111 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_420 ( V_525 , V_660 ) ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1713 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_660 ) ||
( V_1111 && V_1110 &&
F_51 ( V_53 , V_666 , V_1111 , V_1110 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_421 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_660 ,
enum V_1714 V_1715 , int V_1716 ,
const T_2 * V_1717 , T_12 V_1354 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1718 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_660 && F_51 ( V_53 , V_533 , V_573 , V_660 ) ) ||
F_28 ( V_53 , V_127 , V_1715 ) ||
( V_1716 != - 1 &&
F_56 ( V_53 , V_123 , V_1716 ) ) ||
( V_1717 && F_51 ( V_53 , V_122 , 6 , V_1717 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_422 ( struct V_18 * V_18 ,
struct V_54 * V_1719 ,
struct V_54 * V_1720 )
{
struct V_31 * V_53 ;
void * V_280 ;
struct V_4 * V_284 ;
V_53 = F_74 ( V_584 , V_1691 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1721 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_423 ( V_18 ) ) )
goto V_61;
V_284 = F_47 ( V_53 , V_1722 ) ;
if ( ! V_284 )
goto V_61;
if ( F_27 ( V_53 , V_1719 , false ) )
goto V_61;
F_48 ( V_53 , V_284 ) ;
V_284 = F_47 ( V_53 , V_1723 ) ;
if ( ! V_284 )
goto V_61;
if ( F_27 ( V_53 , V_1720 , false ) )
goto V_61;
F_48 ( V_53 , V_284 ) ;
F_66 ( V_53 , V_280 ) ;
F_213 () ;
F_403 ( & V_38 , V_53 , 0 ,
V_1690 , V_1691 ) ;
F_216 () ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
static void F_424 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_630 ,
struct V_54 * V_55 ,
unsigned int V_1404 , T_12 V_1354 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_508 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_513 ,
V_516 ) ||
F_104 ( V_53 , V_1408 , V_630 ) )
goto V_61;
if ( V_52 == V_1407 &&
F_28 ( V_53 , V_1405 , V_1404 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_425 ( struct V_1 * V_17 , T_1 V_630 ,
struct V_54 * V_55 ,
unsigned int V_1404 , T_12 V_1354 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_426 ( V_17 , V_630 , V_55 , V_1404 ) ;
F_424 ( V_1407 ,
V_7 , V_17 , V_630 , V_55 ,
V_1404 , V_1354 ) ;
}
void F_427 ( struct V_1 * V_17 , T_1 V_630 ,
struct V_54 * V_55 ,
T_12 V_1354 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_428 ( V_17 , V_630 , V_55 ) ;
F_424 ( V_1724 ,
V_7 , V_17 , V_630 , V_55 , 0 , V_1354 ) ;
}
void F_429 ( struct V_25 * V_525 , const T_2 * V_632 ,
struct V_765 * V_766 , T_12 V_1354 )
{
struct V_18 * V_18 = V_525 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_430 ( V_525 , V_632 , V_766 ) ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
if ( F_161 ( V_53 , 0 , 0 , 0 ,
V_7 , V_525 , V_632 , V_766 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
}
void F_431 ( struct V_25 * V_525 , const T_2 * V_632 , T_12 V_1354 )
{
struct V_18 * V_18 = V_525 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
F_432 ( V_525 , V_632 ) ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1725 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_632 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_433 ( struct V_25 * V_525 , const T_2 * V_632 ,
enum V_1726 V_1379 ,
T_12 V_1354 )
{
struct V_18 * V_18 = V_525 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_1727 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1728 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_632 ) ||
F_28 ( V_53 , V_1729 , V_1379 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
static bool F_434 ( struct V_25 * V_525 , T_2 V_52 ,
const T_2 * V_660 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
V_22 V_1610 = F_435 ( V_17 -> V_1603 ) ;
if ( ! V_1610 )
return false ;
V_53 = F_74 ( 100 , V_1354 ) ;
if ( ! V_53 )
return true ;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_660 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_436 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1610 ) ;
return true ;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_437 ( struct V_25 * V_525 ,
const T_2 * V_660 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
bool V_482 ;
F_438 ( V_525 , V_660 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_439 ( false ) ;
return false ;
}
V_482 = F_434 ( V_525 , V_1730 ,
V_660 , V_1354 ) ;
F_439 ( V_482 ) ;
return V_482 ;
}
bool F_440 ( struct V_25 * V_525 ,
const T_2 * V_660 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
bool V_482 ;
F_441 ( V_525 , V_660 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_439 ( false ) ;
return false ;
}
V_482 = F_434 ( V_525 ,
V_1731 ,
V_660 , V_1354 ) ;
F_439 ( V_482 ) ;
return V_482 ;
}
int F_442 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1610 ,
int V_1732 , int V_1733 ,
const T_2 * V_1452 , T_10 V_47 , V_22 V_51 , T_12 V_1354 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return - V_136 ;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1456 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_508 , V_1732 ) ||
( V_1733 &&
F_28 ( V_53 , V_1734 , V_1733 ) ) ||
F_51 ( V_53 , V_1449 , V_47 , V_1452 ) ||
( V_51 &&
F_28 ( V_53 , V_1735 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
return F_436 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1610 ) ;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_443 ( struct V_1 * V_17 , T_1 V_630 ,
const T_2 * V_1452 , T_10 V_47 , bool V_1736 , T_12 V_1354 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_280 ;
F_444 ( V_17 , V_630 , V_1736 ) ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1737 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1449 , V_47 , V_1452 ) ||
F_104 ( V_53 , V_1408 , V_630 ) ||
( V_1736 && F_29 ( V_53 , V_1738 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_445 ( struct V_25 * V_525 ,
const char * V_937 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_584 , V_1354 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1739 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_525 -> V_20 ) )
goto V_61;
if ( V_937 && F_51 ( V_53 , V_533 , V_573 , V_937 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1475 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_446 ( struct V_31 * V_53 , T_12 V_1354 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
}
void F_447 ( struct V_25 * V_525 ,
enum V_1740 V_1741 ,
T_12 V_1354 )
{
struct V_31 * V_53 ;
F_448 ( V_525 , V_1741 ) ;
if ( F_59 ( V_1741 != V_1742 &&
V_1741 != V_1743 ) )
return;
V_53 = F_445 ( V_525 , NULL , V_1354 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1744 ,
V_1741 ) )
goto V_61;
F_446 ( V_53 , V_1354 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_449 ( struct V_25 * V_525 ,
const T_2 * V_1394 , V_22 V_1745 ,
V_22 V_241 , V_22 V_1467 , T_12 V_1354 )
{
struct V_31 * V_53 ;
V_53 = F_445 ( V_525 , V_1394 , V_1354 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1480 , V_1745 ) )
goto V_61;
if ( F_28 ( V_53 , V_1479 , V_241 ) )
goto V_61;
if ( F_28 ( V_53 , V_1481 , V_1467 ) )
goto V_61;
F_446 ( V_53 , V_1354 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_450 ( struct V_25 * V_525 ,
const T_2 * V_1394 , V_22 V_1745 , T_12 V_1354 )
{
struct V_31 * V_53 ;
F_451 ( V_525 , V_1394 , V_1745 ) ;
V_53 = F_445 ( V_525 , V_1394 , V_1354 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1746 , V_1745 ) )
goto V_61;
F_446 ( V_53 , V_1354 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_452 ( struct V_25 * V_525 , T_12 V_1354 )
{
struct V_31 * V_53 ;
V_53 = F_445 ( V_525 , NULL , V_1354 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1747 ) )
goto V_61;
F_446 ( V_53 , V_1354 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_453 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_532 ,
const T_2 * V_1601 , T_12 V_1354 )
{
struct V_31 * V_53 ;
struct V_4 * V_1748 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1749 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_532 ) )
goto V_61;
V_1748 = F_47 ( V_53 , V_1589 ) ;
if ( ! V_1748 )
goto V_61;
if ( F_51 ( V_53 , V_1592 ,
V_1593 , V_1601 ) )
goto V_61;
F_48 ( V_53 , V_1748 ) ;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_454 ( struct V_25 * V_525 , const T_2 * V_532 ,
const T_2 * V_1601 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_455 ( V_525 , V_532 ) ;
F_453 ( V_7 , V_525 , V_532 , V_1601 , V_1354 ) ;
}
static void
F_456 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1750 ,
const T_2 * V_532 , bool V_1751 , T_12 V_1354 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1752 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1753 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1754 , V_1750 ) ||
F_51 ( V_53 , V_1755 , V_573 , V_532 ) ||
( V_1751 &&
F_29 ( V_53 , V_1756 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_457 ( struct V_25 * V_525 , int V_1750 ,
const T_2 * V_532 , bool V_1751 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_458 ( V_525 , V_1750 , V_532 , V_1751 ) ;
F_456 ( V_7 , V_525 , V_1750 , V_532 , V_1751 , V_1354 ) ;
}
static void F_459 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_505 * V_506 ,
T_12 V_1354 ,
enum V_277 V_1757 ,
T_2 V_1210 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1757 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_506 ) )
goto V_61;
if ( ( V_1757 == V_1758 ) &&
( F_28 ( V_53 , V_1208 , V_1210 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_460 ( struct V_25 * V_525 ,
struct V_505 * V_506 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_461 ( V_525 , V_506 ) ;
V_17 -> V_506 = * V_506 ;
V_17 -> V_531 = * V_506 ;
F_459 ( V_7 , V_525 , V_506 , V_135 ,
V_1759 , 0 ) ;
}
void F_462 ( struct V_25 * V_525 ,
struct V_505 * V_506 ,
T_2 V_1210 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_463 ( V_525 , V_506 ) ;
F_459 ( V_7 , V_525 , V_506 , V_135 ,
V_1758 , V_1210 ) ;
}
void
F_464 ( struct V_6 * V_7 ,
const struct V_505 * V_506 ,
enum V_1760 V_609 ,
struct V_25 * V_19 , T_12 V_1354 )
{
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1761 ) ;
if ( ! V_280 ) {
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
if ( F_28 ( V_53 , V_1762 , V_609 ) )
goto V_61;
if ( F_101 ( V_53 , V_506 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_465 ( struct V_25 * V_525 , const T_2 * V_660 ,
T_1 V_630 , bool V_1763 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
F_466 ( V_525 , V_660 , V_630 , V_1763 ) ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1604 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_660 ) ||
F_104 ( V_53 , V_1408 , V_630 ) ||
( V_1763 && F_29 ( V_53 , V_1738 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_467 ( struct V_18 * V_18 ,
const T_2 * V_1764 , T_10 V_47 ,
int V_1732 , int V_1733 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
struct V_1605 * V_1606 ;
F_468 ( V_18 , V_1764 , V_47 , V_1732 , V_1733 ) ;
F_251 ( & V_7 -> V_1609 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1691 ) ;
if ( ! V_53 ) {
F_253 ( & V_7 -> V_1609 ) ;
return;
}
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1456 ) ;
if ( ! V_280 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1732 &&
F_28 ( V_53 , V_508 , V_1732 ) ) ||
( V_1733 &&
F_28 ( V_53 , V_1734 , V_1733 ) ) ||
F_51 ( V_53 , V_1449 , V_47 , V_1764 ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_436 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1606 -> V_1610 ) ;
}
F_253 ( & V_7 -> V_1609 ) ;
return;
V_61:
F_253 ( & V_7 -> V_1609 ) ;
if ( V_280 )
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
static int F_469 ( struct V_31 * V_53 ,
struct V_1765 * V_1766 )
{
struct V_1767 * V_1768 = V_1766 -> V_1769 ;
struct V_4 * V_1770 , * V_1771 , * V_283 ;
int V_159 , V_161 ;
V_1770 = F_47 (
V_53 , V_1772 ) ;
if ( ! V_1770 )
return - V_481 ;
for ( V_159 = 0 ; V_159 < V_1768 -> V_1773 ; V_159 ++ ) {
struct V_1774 * V_1775 = V_1768 -> V_1776 [ V_159 ] ;
V_1771 = F_47 ( V_53 , V_159 ) ;
if ( ! V_1771 )
break;
if ( F_51 ( V_53 , V_577 , V_1775 -> V_578 . V_576 ,
V_1775 -> V_578 . V_578 ) ) {
F_470 ( V_53 , V_1771 ) ;
goto V_583;
}
if ( V_1775 -> V_357 ) {
V_283 = F_47 (
V_53 , V_1160 ) ;
if ( ! V_283 ) {
F_470 ( V_53 , V_1771 ) ;
goto V_583;
}
for ( V_161 = 0 ; V_161 < V_1775 -> V_357 ; V_161 ++ ) {
if ( F_28 ( V_53 ,
V_508 ,
V_1775 -> V_358 [ V_161 ] ) ) {
F_470 ( V_53 , V_283 ) ;
F_470 ( V_53 , V_1771 ) ;
goto V_583;
}
}
F_48 ( V_53 , V_283 ) ;
}
F_48 ( V_53 , V_1771 ) ;
}
V_583:
F_48 ( V_53 , V_1770 ) ;
return 0 ;
}
void F_471 ( struct V_1 * V_17 ,
struct V_1765 * V_1766 ,
T_12 V_1354 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
int V_1517 = 200 ;
F_472 ( V_17 -> V_18 , V_17 , V_1766 ) ;
if ( V_1766 )
V_1517 += V_1766 -> V_1777 ;
V_53 = F_74 ( V_1517 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1778 ) ;
if ( ! V_280 )
goto V_640;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_640;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_640;
if ( V_1766 ) {
struct V_4 * V_1779 ;
V_1779 = F_47 ( V_53 , V_1519 ) ;
if ( ! V_1779 )
goto V_640;
if ( V_1766 -> V_442 &&
F_29 ( V_53 , V_206 ) )
goto V_640;
if ( V_1766 -> V_1521 &&
F_29 ( V_53 , V_208 ) )
goto V_640;
if ( V_1766 -> V_1522 &&
F_29 ( V_53 , V_212 ) )
goto V_640;
if ( V_1766 -> V_1523 &&
F_29 ( V_53 , V_214 ) )
goto V_640;
if ( V_1766 -> V_1524 &&
F_29 ( V_53 , V_216 ) )
goto V_640;
if ( V_1766 -> V_1525 &&
F_29 ( V_53 , V_218 ) )
goto V_640;
if ( V_1766 -> V_1780 >= 0 &&
F_28 ( V_53 , V_228 ,
V_1766 -> V_1780 ) )
goto V_640;
if ( V_1766 -> V_1781 &&
F_29 ( V_53 , V_1782 ) )
goto V_640;
if ( V_1766 -> V_1783 &&
F_29 ( V_53 , V_1784 ) )
goto V_640;
if ( V_1766 -> V_1785 &&
F_29 ( V_53 ,
V_1786 ) )
goto V_640;
if ( V_1766 -> V_1787 ) {
V_22 V_1788 = V_1789 ;
V_22 V_1790 = V_1791 ;
if ( ! V_1766 -> V_1792 ) {
V_1788 =
V_1793 ;
V_1790 =
V_1794 ;
}
if ( V_1766 -> V_1795 &&
F_28 ( V_53 , V_1790 , V_1766 -> V_1795 ) )
goto V_640;
if ( F_51 ( V_53 , V_1788 , V_1766 -> V_1777 ,
V_1766 -> V_1787 ) )
goto V_640;
}
if ( V_1766 -> V_1769 &&
F_469 ( V_53 , V_1766 ) )
goto V_640;
F_48 ( V_53 , V_1779 ) ;
}
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_640:
F_75 ( V_53 ) ;
}
void F_473 ( struct V_25 * V_525 , const T_2 * V_1394 ,
enum V_1401 V_1796 ,
T_3 V_944 , T_12 V_1354 )
{
struct V_1 * V_17 = V_525 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
F_474 ( V_17 -> V_18 , V_525 , V_1394 , V_1796 ,
V_944 ) ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1797 ) ;
if ( ! V_280 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_525 -> V_20 ) ||
F_56 ( V_53 , V_1403 , V_1796 ) ||
F_51 ( V_53 , V_533 , V_573 , V_1394 ) ||
( V_944 > 0 &&
F_55 ( V_53 , V_943 , V_944 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_1354 ) ;
return;
V_61:
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
static int F_475 ( struct V_1798 * V_1799 ,
unsigned long V_279 ,
void * V_1800 )
{
struct V_1801 * V_1802 = V_1800 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1605 * V_1606 , * V_24 ;
if ( V_279 != V_1803 )
return V_1804 ;
F_213 () ;
F_476 (rdev, &cfg80211_rdev_list, list) {
bool V_1805 = false ;
F_476 (wdev, &rdev->wdev_list, list) {
F_477 ( V_17 , V_1802 -> V_49 ) ;
if ( V_17 -> V_615 == V_1802 -> V_49 )
V_1805 = true ;
}
F_251 ( & V_7 -> V_1609 ) ;
F_478 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1606 -> V_1610 == V_1802 -> V_49 ) {
F_479 ( & V_1606 -> V_621 ) ;
F_41 ( V_1606 ) ;
break;
}
}
F_253 ( & V_7 -> V_1609 ) ;
if ( V_1805 ) {
struct V_1806 * V_1807 ;
V_1807 = F_38 ( sizeof( * V_1807 ) , V_1691 ) ;
if ( V_1807 ) {
V_1807 -> V_1610 = V_1802 -> V_49 ;
F_480 ( & V_7 -> V_1808 ) ;
F_363 ( & V_1807 -> V_621 , & V_7 -> V_1809 ) ;
F_481 ( & V_7 -> V_1808 ) ;
F_482 ( & V_7 -> V_1810 ) ;
}
}
}
F_216 () ;
return V_1811 ;
}
void F_483 ( struct V_25 * V_19 ,
struct V_1812 * V_1813 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
F_484 ( V_18 , V_19 , V_1813 ) ;
if ( ! V_1813 -> V_1814 )
return;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1815 ) ;
if ( ! V_280 )
goto V_583;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_533 , V_573 , V_1813 -> V_1814 ) )
goto V_583;
if ( V_1813 -> V_1229 &&
F_51 ( V_53 , V_666 , V_1813 -> V_1816 , V_1813 -> V_1229 ) )
goto V_583;
if ( V_1813 -> V_1817 &&
F_51 ( V_53 , V_1818 , V_1813 -> V_1819 ,
V_1813 -> V_1817 ) )
goto V_583;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1693 , V_135 ) ;
return;
V_583:
F_75 ( V_53 ) ;
}
void F_485 ( struct V_1 * V_17 , T_12 V_1354 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_280 ;
V_22 V_1610 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1627 )
return;
V_1610 = V_7 -> V_1627 ;
V_7 -> V_1627 = 0 ;
V_53 = F_74 ( V_584 , V_1354 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1820 ) ;
if ( ! V_280 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_66 ( V_53 , V_280 ) ;
F_436 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1610 ) ;
return;
V_61:
if ( V_280 )
F_67 ( V_53 , V_280 ) ;
F_75 ( V_53 ) ;
}
void F_486 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_280 ;
V_53 = F_74 ( V_584 , V_135 ) ;
if ( ! V_53 )
return;
V_280 = F_25 ( V_53 , 0 , 0 , 0 , V_1821 ) ;
if ( ! V_280 )
goto V_583;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_583;
F_66 ( V_53 , V_280 ) ;
F_125 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1693 , V_135 ) ;
return;
V_583:
F_75 ( V_53 ) ;
}
int F_487 ( void )
{
int V_35 ;
V_35 = F_488 ( & V_38 , V_1822 ,
V_1823 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_489 ( & V_1824 ) ;
if ( V_35 )
goto V_1825;
return 0 ;
V_1825:
F_490 ( & V_38 ) ;
return V_35 ;
}
void F_491 ( void )
{
F_492 ( & V_1824 ) ;
F_490 ( & V_38 ) ;
}
