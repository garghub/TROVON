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
F_12 ( V_19 ) ;
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
F_13 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
return F_8 ( V_3 , V_30 -> V_5 ) ;
}
static int F_14 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
int V_35 ;
F_15 () ;
if ( ! V_34 -> args [ 0 ] ) {
V_35 = F_16 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_43;
* V_17 = F_1 ( F_17 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_18 ( * V_17 ) ) {
V_35 = F_19 ( * V_17 ) ;
goto V_43;
}
* V_7 = F_11 ( ( * V_17 ) -> V_18 ) ;
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = ( * V_17 ) -> V_21 ;
} else {
struct V_18 * V_18 = F_20 ( V_34 -> args [ 0 ] - 1 ) ;
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
F_21 () ;
return V_35 ;
}
static void F_22 ( struct V_6 * V_7 )
{
F_21 () ;
}
static bool F_23 ( const struct V_4 * V_45 )
{
const T_2 * V_46 ;
int V_47 ;
if ( ! V_45 )
return true ;
V_46 = F_24 ( V_45 ) ;
V_47 = F_25 ( V_45 ) ;
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
static inline void * F_26 ( struct V_31 * V_32 , V_22 V_49 , V_22 V_50 ,
int V_51 , T_2 V_52 )
{
return F_27 ( V_32 , V_49 , V_50 , & V_38 , V_51 , V_52 ) ;
}
static int F_28 ( struct V_31 * V_53 ,
struct V_54 * V_55 ,
bool V_56 )
{
if ( F_29 ( V_53 , V_57 ,
V_55 -> V_58 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_60 ) &&
F_30 ( V_53 , V_61 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_62 ) &&
F_30 ( V_53 , V_63 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_64 ) &&
F_30 ( V_53 , V_65 ) )
goto V_59;
if ( V_55 -> V_51 & V_66 ) {
if ( F_30 ( V_53 , V_67 ) )
goto V_59;
if ( V_56 ) {
V_22 time ;
time = F_31 ( V_55 -> V_68 ) ;
if ( F_29 ( V_53 , V_69 ,
V_55 -> V_70 ) )
goto V_59;
if ( F_29 ( V_53 , V_71 ,
time ) )
goto V_59;
}
}
if ( V_56 ) {
if ( ( V_55 -> V_51 & V_72 ) &&
F_30 ( V_53 , V_73 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_74 ) &&
F_30 ( V_53 , V_75 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_76 ) &&
F_30 ( V_53 , V_77 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_78 ) &&
F_30 ( V_53 , V_79 ) )
goto V_59;
}
if ( F_29 ( V_53 , V_80 ,
F_32 ( V_55 -> V_81 ) ) )
goto V_59;
return 0 ;
V_59:
return - V_82 ;
}
static int F_33 ( struct V_4 * V_83 , struct V_84 * V_85 )
{
struct V_4 * V_86 [ V_87 + 1 ] ;
int V_35 = F_34 ( V_86 , V_87 , V_83 ,
V_88 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_89 = ! ! V_86 [ V_90 ] ;
V_85 -> V_91 = ! ! V_86 [ V_92 ] ;
if ( V_85 -> V_89 ) {
V_85 -> V_93 = true ;
V_85 -> V_94 = true ;
}
if ( V_85 -> V_91 )
V_85 -> V_94 = true ;
if ( V_86 [ V_95 ] )
V_85 -> V_96 = F_35 ( V_86 [ V_95 ] ) ;
if ( V_86 [ V_97 ] ) {
V_85 -> V_98 . V_83 = F_24 ( V_86 [ V_97 ] ) ;
V_85 -> V_98 . V_99 = F_25 ( V_86 [ V_97 ] ) ;
}
if ( V_86 [ V_100 ] ) {
V_85 -> V_98 . V_50 = F_24 ( V_86 [ V_100 ] ) ;
V_85 -> V_98 . V_101 = F_25 ( V_86 [ V_100 ] ) ;
}
if ( V_86 [ V_102 ] )
V_85 -> V_98 . V_103 = F_4 ( V_86 [ V_102 ] ) ;
if ( V_86 [ V_104 ] ) {
V_85 -> type = F_4 ( V_86 [ V_104 ] ) ;
if ( V_85 -> type < 0 || V_85 -> type >= V_105 )
return - V_16 ;
}
if ( V_86 [ V_106 ] ) {
struct V_4 * V_107 [ V_108 ] ;
V_35 = F_34 ( V_107 , V_108 - 1 ,
V_86 [ V_106 ] ,
V_109 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_93 = V_107 [ V_110 ] ;
V_85 -> V_94 = V_107 [ V_111 ] ;
}
return 0 ;
}
static int F_36 ( struct V_29 * V_30 , struct V_84 * V_85 )
{
if ( V_30 -> V_5 [ V_112 ] ) {
V_85 -> V_98 . V_83 = F_24 ( V_30 -> V_5 [ V_112 ] ) ;
V_85 -> V_98 . V_99 = F_25 ( V_30 -> V_5 [ V_112 ] ) ;
}
if ( V_30 -> V_5 [ V_113 ] ) {
V_85 -> V_98 . V_50 = F_24 ( V_30 -> V_5 [ V_113 ] ) ;
V_85 -> V_98 . V_101 = F_25 ( V_30 -> V_5 [ V_113 ] ) ;
}
if ( V_30 -> V_5 [ V_114 ] )
V_85 -> V_96 = F_35 ( V_30 -> V_5 [ V_114 ] ) ;
if ( V_30 -> V_5 [ V_115 ] )
V_85 -> V_98 . V_103 = F_4 ( V_30 -> V_5 [ V_115 ] ) ;
V_85 -> V_89 = ! ! V_30 -> V_5 [ V_116 ] ;
V_85 -> V_91 = ! ! V_30 -> V_5 [ V_117 ] ;
if ( V_85 -> V_89 ) {
V_85 -> V_93 = true ;
V_85 -> V_94 = true ;
}
if ( V_85 -> V_91 )
V_85 -> V_94 = true ;
if ( V_30 -> V_5 [ V_118 ] ) {
V_85 -> type = F_4 ( V_30 -> V_5 [ V_118 ] ) ;
if ( V_85 -> type < 0 || V_85 -> type >= V_105 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_119 ] ) {
struct V_4 * V_107 [ V_108 ] ;
int V_35 = F_34 (
V_107 , V_108 - 1 ,
V_30 -> V_5 [ V_119 ] ,
V_109 ) ;
if ( V_35 )
return V_35 ;
V_85 -> V_93 = V_107 [ V_110 ] ;
V_85 -> V_94 = V_107 [ V_111 ] ;
}
return 0 ;
}
static int F_37 ( struct V_29 * V_30 , struct V_84 * V_85 )
{
int V_35 ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
V_85 -> V_96 = - 1 ;
V_85 -> type = - 1 ;
if ( V_30 -> V_5 [ V_120 ] )
V_35 = F_33 ( V_30 -> V_5 [ V_120 ] , V_85 ) ;
else
V_35 = F_36 ( V_30 , V_85 ) ;
if ( V_35 )
return V_35 ;
if ( V_85 -> V_89 && V_85 -> V_91 )
return - V_16 ;
if ( V_85 -> V_91 ) {
if ( V_85 -> V_93 || ! V_85 -> V_94 )
return - V_16 ;
}
if ( V_85 -> V_96 != - 1 ) {
if ( V_85 -> V_91 ) {
if ( V_85 -> V_96 < 4 || V_85 -> V_96 > 5 )
return - V_16 ;
} else if ( V_85 -> V_89 ) {
if ( V_85 -> V_96 < 0 || V_85 -> V_96 > 3 )
return - V_16 ;
} else {
if ( V_85 -> V_96 < 0 || V_85 -> V_96 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_121 *
F_38 ( struct V_6 * V_7 ,
struct V_4 * V_122 , bool * V_123 )
{
struct V_84 V_124 ;
struct V_4 * V_83 ;
struct V_121 * V_8 ;
int V_125 , V_35 , V_89 = 0 ;
V_8 = F_39 ( sizeof( * V_8 ) , V_126 ) ;
if ( ! V_8 )
return F_3 ( - V_127 ) ;
V_8 -> V_89 = - 1 ;
V_8 -> V_91 = - 1 ;
F_40 (key, keys, rem) {
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_96 = - 1 ;
V_35 = F_33 ( V_83 , & V_124 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_124 . V_98 . V_83 )
goto error;
if ( V_124 . V_96 < 0 || V_124 . V_96 > 4 )
goto error;
if ( V_124 . V_89 ) {
if ( V_89 )
goto error;
V_89 = 1 ;
V_8 -> V_89 = V_124 . V_96 ;
if ( ! V_124 . V_93 || ! V_124 . V_94 )
goto error;
} else if ( V_124 . V_91 )
goto error;
V_35 = F_41 ( V_7 , & V_124 . V_98 ,
V_124 . V_96 , false , NULL ) ;
if ( V_35 )
goto error;
V_8 -> V_128 [ V_124 . V_96 ] . V_103 = V_124 . V_98 . V_103 ;
V_8 -> V_128 [ V_124 . V_96 ] . V_99 = V_124 . V_98 . V_99 ;
V_8 -> V_128 [ V_124 . V_96 ] . V_83 = V_8 -> V_129 [ V_124 . V_96 ] ;
memcpy ( V_8 -> V_129 [ V_124 . V_96 ] , V_124 . V_98 . V_83 , V_124 . V_98 . V_99 ) ;
if ( V_124 . V_98 . V_103 == V_130 ||
V_124 . V_98 . V_103 == V_131 ) {
if ( V_123 )
* V_123 = true ;
}
}
return V_8 ;
error:
F_42 ( V_8 ) ;
return F_3 ( V_35 ) ;
}
static int F_43 ( struct V_1 * V_17 )
{
F_44 ( V_17 ) ;
switch ( V_17 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
break;
case V_137 :
case V_138 :
case V_139 :
if ( ! V_17 -> V_140 )
return - V_141 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_45 ( struct V_31 * V_53 , V_22 V_45 , T_3 V_142 )
{
struct V_4 * V_143 = F_46 ( V_53 , V_45 ) ;
int V_144 ;
if ( ! V_143 )
goto V_59;
V_144 = 0 ;
while ( V_142 ) {
if ( ( V_142 & 1 ) && F_30 ( V_53 , V_144 ) )
goto V_59;
V_142 >>= 1 ;
V_144 ++ ;
}
F_47 ( V_53 , V_143 ) ;
return 0 ;
V_59:
return - V_82 ;
}
static int F_48 ( struct V_18 * V_18 ,
struct V_31 * V_53 ,
bool V_56 )
{
struct V_4 * V_145 ;
int V_144 , V_146 ;
V_145 = F_46 ( V_53 ,
V_147 ) ;
if ( ! V_145 )
goto V_59;
for ( V_144 = 0 ; V_144 < V_18 -> V_148 ; V_144 ++ ) {
const struct V_149 * V_150 ;
struct V_4 * V_151 , * V_152 ;
V_150 = & V_18 -> V_153 [ V_144 ] ;
V_151 = F_46 ( V_53 , V_144 + 1 ) ;
if ( ! V_151 )
goto V_59;
V_152 = F_46 ( V_53 , V_154 ) ;
if ( ! V_152 )
goto V_59;
for ( V_146 = 0 ; V_146 < V_150 -> V_155 ; V_146 ++ ) {
struct V_4 * V_156 ;
V_156 = F_46 ( V_53 , V_146 + 1 ) ;
if ( ! V_156 )
goto V_59;
if ( F_29 ( V_53 , V_157 ,
V_150 -> V_158 [ V_146 ] . V_159 ) )
goto V_59;
if ( F_45 ( V_53 , V_160 ,
V_150 -> V_158 [ V_146 ] . V_161 ) )
goto V_59;
F_47 ( V_53 , V_156 ) ;
}
F_47 ( V_53 , V_152 ) ;
if ( V_150 -> V_162 &&
F_30 ( V_53 , V_163 ) )
goto V_59;
if ( F_29 ( V_53 , V_164 ,
V_150 -> V_165 ) ||
F_29 ( V_53 , V_166 ,
V_150 -> V_167 ) )
goto V_59;
if ( V_56 &&
F_29 ( V_53 , V_168 ,
V_150 -> V_169 ) )
goto V_59;
F_47 ( V_53 , V_151 ) ;
}
F_47 ( V_53 , V_145 ) ;
return 0 ;
V_59:
return - V_82 ;
}
static int F_49 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
const struct V_170 * V_171 = V_7 -> V_18 . V_172 -> V_171 ;
struct V_4 * V_173 ;
if ( ! V_171 )
return 0 ;
V_173 = F_46 ( V_53 , V_174 ) ;
if ( ! V_173 )
return - V_82 ;
if ( F_29 ( V_53 , V_175 ,
V_171 -> V_176 ) )
return - V_82 ;
if ( F_29 ( V_53 , V_175 ,
V_171 -> V_176 ) )
return - V_82 ;
if ( V_171 -> V_50 && F_30 ( V_53 , V_177 ) )
return - V_82 ;
if ( V_171 -> V_178 && F_50 ( V_53 , V_179 ,
sizeof( * V_171 -> V_178 ) , V_171 -> V_178 ) )
return - V_82 ;
if ( F_29 ( V_53 , V_180 ,
V_171 -> V_181 ) )
return - V_82 ;
if ( F_29 ( V_53 , V_182 ,
V_171 -> V_183 ) )
return - V_82 ;
F_47 ( V_53 , V_173 ) ;
return 0 ;
}
static int F_51 ( struct V_31 * V_53 ,
struct V_6 * V_184 ,
bool V_56 )
{
struct V_4 * V_185 ;
if ( ! V_184 -> V_18 . V_172 )
return 0 ;
V_185 = F_46 ( V_53 , V_186 ) ;
if ( ! V_185 )
return - V_82 ;
if ( ( ( V_184 -> V_18 . V_172 -> V_51 & V_187 ) &&
F_30 ( V_53 , V_188 ) ) ||
( ( V_184 -> V_18 . V_172 -> V_51 & V_189 ) &&
F_30 ( V_53 , V_190 ) ) ||
( ( V_184 -> V_18 . V_172 -> V_51 & V_191 ) &&
F_30 ( V_53 , V_192 ) ) ||
( ( V_184 -> V_18 . V_172 -> V_51 & V_193 ) &&
F_30 ( V_53 , V_194 ) ) ||
( ( V_184 -> V_18 . V_172 -> V_51 & V_195 ) &&
F_30 ( V_53 , V_196 ) ) ||
( ( V_184 -> V_18 . V_172 -> V_51 & V_197 ) &&
F_30 ( V_53 , V_198 ) ) ||
( ( V_184 -> V_18 . V_172 -> V_51 & V_199 ) &&
F_30 ( V_53 , V_200 ) ) ||
( ( V_184 -> V_18 . V_172 -> V_51 & V_201 ) &&
F_30 ( V_53 , V_202 ) ) )
return - V_82 ;
if ( V_184 -> V_18 . V_172 -> V_203 ) {
struct V_204 V_205 = {
. V_206 = V_184 -> V_18 . V_172 -> V_203 ,
. V_207 = V_184 -> V_18 . V_172 -> V_208 ,
. V_209 = V_184 -> V_18 . V_172 -> V_210 ,
. V_211 = V_184 -> V_18 . V_172 -> V_211 ,
} ;
if ( F_50 ( V_53 , V_212 ,
sizeof( V_205 ) , & V_205 ) )
return - V_82 ;
}
if ( V_56 && F_49 ( V_184 , V_53 ) )
return - V_82 ;
F_47 ( V_53 , V_185 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_53 ,
struct V_6 * V_184 )
{
struct V_213 V_214 ;
if ( ! V_184 -> V_18 . V_215 )
return 0 ;
V_214 . V_216 = V_184 -> V_18 . V_215 -> V_217 ;
V_214 . V_218 = V_184 -> V_18 . V_215 -> V_218 ;
V_214 . V_205 . V_206 = V_184 -> V_18 . V_215 -> V_203 ;
V_214 . V_205 . V_207 = V_184 -> V_18 . V_215 -> V_208 ;
V_214 . V_205 . V_209 = V_184 -> V_18 . V_215 -> V_210 ;
V_214 . V_205 . V_211 = V_184 -> V_18 . V_215 -> V_211 ;
if ( F_50 ( V_53 , V_219 , sizeof( V_214 ) , & V_214 ) )
return - V_82 ;
return 0 ;
}
static int F_53 ( struct V_31 * V_53 ,
struct V_220 * V_221 )
{
struct V_4 * V_222 , * V_223 ;
struct V_224 * V_225 ;
int V_144 ;
if ( V_221 -> V_226 . V_227 &&
( F_50 ( V_53 , V_228 ,
sizeof( V_221 -> V_226 . V_229 ) ,
& V_221 -> V_226 . V_229 ) ||
F_54 ( V_53 , V_230 ,
V_221 -> V_226 . V_231 ) ||
F_55 ( V_53 , V_232 ,
V_221 -> V_226 . V_233 ) ||
F_55 ( V_53 , V_234 ,
V_221 -> V_226 . V_235 ) ) )
return - V_82 ;
if ( V_221 -> V_236 . V_237 &&
( F_50 ( V_53 , V_238 ,
sizeof( V_221 -> V_236 . V_239 ) ,
& V_221 -> V_236 . V_239 ) ||
F_29 ( V_53 , V_240 ,
V_221 -> V_236 . V_231 ) ) )
return - V_82 ;
V_222 = F_46 ( V_53 , V_241 ) ;
if ( ! V_222 )
return - V_82 ;
for ( V_144 = 0 ; V_144 < V_221 -> V_242 ; V_144 ++ ) {
V_223 = F_46 ( V_53 , V_144 ) ;
if ( ! V_223 )
return - V_82 ;
V_225 = & V_221 -> V_243 [ V_144 ] ;
if ( F_29 ( V_53 , V_244 ,
V_225 -> V_245 ) )
return - V_82 ;
if ( ( V_225 -> V_51 & V_246 ) &&
F_30 ( V_53 ,
V_247 ) )
return - V_82 ;
F_47 ( V_53 , V_223 ) ;
}
F_47 ( V_53 , V_222 ) ;
return 0 ;
}
static int
F_56 ( struct V_31 * V_53 ,
const struct V_248 * V_249 )
{
T_3 V_250 ;
struct V_4 * V_251 , * V_252 ;
enum V_253 V_254 ;
int V_144 ;
if ( ! V_249 )
return 0 ;
V_252 = F_46 ( V_53 , V_255 ) ;
if ( ! V_252 )
return - V_82 ;
for ( V_254 = 0 ; V_254 < V_256 ; V_254 ++ ) {
V_251 = F_46 ( V_53 , V_254 ) ;
if ( ! V_251 )
return - V_82 ;
V_144 = 0 ;
V_250 = V_249 [ V_254 ] . V_257 ;
while ( V_250 ) {
if ( ( V_250 & 1 ) &&
F_54 ( V_53 , V_258 ,
( V_144 << 4 ) | V_259 ) )
return - V_82 ;
V_250 >>= 1 ;
V_144 ++ ;
}
F_47 ( V_53 , V_251 ) ;
}
F_47 ( V_53 , V_252 ) ;
V_252 = F_46 ( V_53 , V_260 ) ;
if ( ! V_252 )
return - V_82 ;
for ( V_254 = 0 ; V_254 < V_256 ; V_254 ++ ) {
V_251 = F_46 ( V_53 , V_254 ) ;
if ( ! V_251 )
return - V_82 ;
V_144 = 0 ;
V_250 = V_249 [ V_254 ] . V_261 ;
while ( V_250 ) {
if ( ( V_250 & 1 ) &&
F_54 ( V_53 , V_258 ,
( V_144 << 4 ) | V_259 ) )
return - V_82 ;
V_250 >>= 1 ;
V_144 ++ ;
}
F_47 ( V_53 , V_251 ) ;
}
F_47 ( V_53 , V_252 ) ;
return 0 ;
}
static int F_57 ( struct V_6 * V_184 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_262 * V_263 )
{
void * V_264 ;
struct V_4 * V_265 , * V_266 ;
struct V_4 * V_267 , * V_268 ;
struct V_4 * V_269 ;
enum V_270 V_271 ;
struct V_54 * V_55 ;
int V_144 ;
const struct V_248 * V_249 =
V_184 -> V_18 . V_249 ;
V_22 V_272 ;
V_264 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_273 ) ;
if ( ! V_264 )
return - V_82 ;
if ( F_58 ( ! V_263 ) )
return - V_16 ;
if ( F_29 ( V_53 , V_26 , V_184 -> V_14 ) ||
F_59 ( V_53 , V_274 ,
F_60 ( & V_184 -> V_18 ) ) ||
F_29 ( V_53 , V_275 ,
V_276 ) )
goto V_59;
switch ( V_263 -> V_277 ) {
case 0 :
if ( F_55 ( V_53 , V_278 ,
V_184 -> V_18 . V_279 ) ||
F_55 ( V_53 , V_280 ,
V_184 -> V_18 . V_281 ) ||
F_29 ( V_53 , V_282 ,
V_184 -> V_18 . V_283 ) ||
F_29 ( V_53 , V_284 ,
V_184 -> V_18 . V_285 ) ||
F_55 ( V_53 , V_286 ,
V_184 -> V_18 . V_287 ) ||
F_55 ( V_53 , V_288 ,
V_184 -> V_18 . V_289 ) ||
F_55 ( V_53 , V_290 ,
V_184 -> V_18 . V_291 ) ||
F_54 ( V_53 , V_292 ,
V_184 -> V_18 . V_293 ) ||
F_54 ( V_53 , V_294 ,
V_184 -> V_18 . V_295 ) ||
F_55 ( V_53 , V_296 ,
V_184 -> V_18 . V_297 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_298 ) &&
F_30 ( V_53 , V_299 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_300 ) &&
F_30 ( V_53 , V_301 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_302 ) &&
F_30 ( V_53 , V_303 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_304 ) &&
F_30 ( V_53 , V_305 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_306 ) &&
F_30 ( V_53 , V_307 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_308 ) &&
F_30 ( V_53 , V_309 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_310 ) &&
F_30 ( V_53 , V_310 ) )
goto V_59;
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
case 1 :
if ( F_50 ( V_53 , V_312 ,
sizeof( V_22 ) * V_184 -> V_18 . V_313 ,
V_184 -> V_18 . V_314 ) )
goto V_59;
if ( F_55 ( V_53 , V_315 ,
V_184 -> V_18 . V_316 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_317 ) &&
F_30 ( V_53 , V_318 ) )
goto V_59;
if ( F_29 ( V_53 , V_319 ,
V_184 -> V_18 . V_320 ) ||
F_29 ( V_53 , V_321 ,
V_184 -> V_18 . V_322 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_323 ) &&
F_29 ( V_53 , V_324 ,
V_184 -> V_18 . V_325 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_320 ||
V_184 -> V_18 . V_322 ) &&
V_184 -> V_326 -> V_327 ) {
V_22 V_328 = 0 , V_329 = 0 ;
int V_330 ;
V_330 = F_61 ( V_184 , & V_328 , & V_329 ) ;
if ( ! V_330 ) {
if ( F_29 ( V_53 ,
V_331 ,
V_328 ) ||
F_29 ( V_53 ,
V_332 ,
V_329 ) )
goto V_59;
}
}
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
case 2 :
if ( F_45 ( V_53 , V_333 ,
V_184 -> V_18 . V_334 ) )
goto V_59;
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
case 3 :
V_265 = F_46 ( V_53 , V_335 ) ;
if ( ! V_265 )
goto V_59;
for ( V_271 = V_263 -> V_336 ;
V_271 < V_337 ; V_271 ++ ) {
struct V_220 * V_221 ;
V_221 = V_184 -> V_18 . V_338 [ V_271 ] ;
if ( ! V_221 )
continue;
V_266 = F_46 ( V_53 , V_271 ) ;
if ( ! V_266 )
goto V_59;
switch ( V_263 -> V_339 ) {
case 0 :
if ( F_53 ( V_53 , V_221 ) )
goto V_59;
V_263 -> V_339 ++ ;
if ( V_263 -> V_311 )
break;
default:
V_267 = F_46 (
V_53 , V_340 ) ;
if ( ! V_267 )
goto V_59;
for ( V_144 = V_263 -> V_339 - 1 ;
V_144 < V_221 -> V_341 ;
V_144 ++ ) {
V_268 = F_46 ( V_53 , V_144 ) ;
if ( ! V_268 )
goto V_59;
V_55 = & V_221 -> V_342 [ V_144 ] ;
if ( F_28 (
V_53 , V_55 ,
V_263 -> V_311 ) )
goto V_59;
F_47 ( V_53 , V_268 ) ;
if ( V_263 -> V_311 )
break;
}
if ( V_144 < V_221 -> V_341 )
V_263 -> V_339 = V_144 + 2 ;
else
V_263 -> V_339 = 0 ;
F_47 ( V_53 , V_267 ) ;
}
F_47 ( V_53 , V_266 ) ;
if ( V_263 -> V_311 ) {
if ( V_263 -> V_339 )
V_271 -- ;
break;
}
}
F_47 ( V_53 , V_265 ) ;
if ( V_271 < V_337 )
V_263 -> V_336 = V_271 + 1 ;
else
V_263 -> V_336 = 0 ;
if ( V_263 -> V_336 == 0 && V_263 -> V_339 == 0 )
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
case 4 :
V_269 = F_46 ( V_53 , V_343 ) ;
if ( ! V_269 )
goto V_59;
V_144 = 0 ;
#define F_62 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_62 ( V_344 , V_345 ) ;
F_62 ( V_346 , V_347 ) ;
F_62 ( V_348 , V_349 ) ;
F_62 ( V_350 , V_351 ) ;
F_62 ( V_352 , V_353 ) ;
F_62 ( V_354 , V_355 ) ;
F_62 ( V_356 , V_357 ) ;
F_62 ( V_358 , V_359 ) ;
F_62 ( V_360 , V_361 ) ;
F_62 ( V_362 , V_363 ) ;
F_62 ( V_364 , V_365 ) ;
F_62 ( V_366 , V_367 ) ;
F_62 ( V_368 , V_369 ) ;
F_62 ( V_370 , V_371 ) ;
F_62 ( V_372 , V_373 ) ;
F_62 ( V_374 , V_375 ) ;
F_62 ( V_376 , V_377 ) ;
if ( V_184 -> V_18 . V_51 & V_378 )
F_62 ( V_379 , V_380 ) ;
F_62 ( V_381 , V_382 ) ;
F_62 ( V_383 , V_384 ) ;
F_62 ( V_385 , V_386 ) ;
if ( V_184 -> V_18 . V_51 & V_387 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_388 ) )
goto V_59;
}
if ( V_184 -> V_326 -> V_389 || V_184 -> V_326 -> V_350 ||
V_184 -> V_326 -> V_370 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_390 ) )
goto V_59;
}
F_62 ( V_391 , V_392 ) ;
if ( V_184 -> V_18 . V_51 & V_306 ) {
F_62 ( V_393 , V_394 ) ;
F_62 ( V_395 , V_396 ) ;
}
if ( V_184 -> V_18 . V_51 & V_397 )
F_62 ( V_398 , V_399 ) ;
F_62 ( V_400 , V_401 ) ;
F_62 ( V_402 , V_403 ) ;
if ( V_184 -> V_18 . V_51 & V_404 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_405 ) )
goto V_59;
}
F_62 ( V_406 , V_407 ) ;
F_62 ( V_408 , V_409 ) ;
if ( V_263 -> V_311 ) {
F_62 ( V_410 , V_411 ) ;
F_62 ( V_412 , V_413 ) ;
if ( V_184 -> V_18 . V_51 & V_414 )
F_62 ( V_415 , V_416 ) ;
}
#ifdef F_63
F_62 ( V_417 , V_418 ) ;
#endif
#undef F_62
if ( V_184 -> V_326 -> V_419 || V_184 -> V_326 -> V_360 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_420 ) )
goto V_59;
}
if ( V_184 -> V_326 -> V_421 || V_184 -> V_326 -> V_364 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_422 ) )
goto V_59;
}
F_47 ( V_53 , V_269 ) ;
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
case 5 :
if ( V_184 -> V_326 -> V_379 &&
( V_184 -> V_18 . V_51 & V_378 ) &&
F_29 ( V_53 ,
V_423 ,
V_184 -> V_18 . V_424 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_425 ) &&
F_30 ( V_53 , V_426 ) )
goto V_59;
if ( F_56 ( V_53 , V_249 ) )
goto V_59;
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
case 6 :
#ifdef F_64
if ( F_51 ( V_53 , V_184 , V_263 -> V_311 ) )
goto V_59;
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
#else
V_263 -> V_277 ++ ;
#endif
case 7 :
if ( F_45 ( V_53 , V_427 ,
V_184 -> V_18 . V_428 ) )
goto V_59;
if ( F_48 ( & V_184 -> V_18 , V_53 ,
V_263 -> V_311 ) )
goto V_59;
V_263 -> V_277 ++ ;
if ( V_263 -> V_311 )
break;
case 8 :
if ( ( V_184 -> V_18 . V_51 & V_429 ) &&
F_29 ( V_53 , V_430 ,
V_184 -> V_18 . V_431 ) )
goto V_59;
V_272 = V_184 -> V_18 . V_272 ;
if ( V_263 -> V_311 )
V_272 |= V_432 ;
if ( F_29 ( V_53 , V_433 , V_272 ) )
goto V_59;
if ( V_184 -> V_18 . V_434 &&
F_50 ( V_53 , V_435 ,
sizeof( * V_184 -> V_18 . V_434 ) ,
V_184 -> V_18 . V_434 ) )
goto V_59;
if ( V_184 -> V_18 . V_51 & V_429 &&
V_184 -> V_18 . V_436 &&
F_29 ( V_53 , V_437 ,
V_184 -> V_18 . V_436 ) )
goto V_59;
V_263 -> V_277 ++ ;
break;
case 9 :
if ( V_184 -> V_18 . V_438 &&
( F_50 ( V_53 , V_439 ,
V_184 -> V_18 . V_440 ,
V_184 -> V_18 . V_438 ) ||
F_50 ( V_53 , V_441 ,
V_184 -> V_18 . V_440 ,
V_184 -> V_18 . V_442 ) ) )
goto V_59;
if ( V_184 -> V_18 . V_443 &&
F_50 ( V_53 , V_444 ,
sizeof( * V_184 -> V_18 . V_443 ) ,
V_184 -> V_18 . V_443 ) )
goto V_59;
V_263 -> V_277 ++ ;
break;
case 10 :
if ( F_52 ( V_53 , V_184 ) )
goto V_59;
V_263 -> V_277 = 0 ;
break;
}
return F_65 ( V_53 , V_264 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
static int F_67 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_262 * V_263 )
{
struct V_4 * * V_86 = V_38 . V_40 ;
int V_446 = F_16 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_86 , V_38 . V_41 , V_42 ) ;
if ( V_446 )
return 0 ;
V_263 -> V_311 = V_86 [ V_447 ] ;
if ( V_86 [ V_26 ] )
V_263 -> V_448 = F_4 ( V_86 [ V_26 ] ) ;
if ( V_86 [ V_12 ] )
V_263 -> V_448 = F_5 ( V_86 [ V_12 ] ) >> 32 ;
if ( V_86 [ V_10 ] ) {
struct V_25 * V_19 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_86 [ V_10 ] ) ;
V_19 = F_10 ( F_17 ( V_32 -> V_44 ) , V_15 ) ;
if ( ! V_19 )
return - V_23 ;
if ( V_19 -> V_28 ) {
V_7 = F_11 (
V_19 -> V_28 -> V_18 ) ;
V_263 -> V_448 = V_7 -> V_14 ;
}
F_12 ( V_19 ) ;
}
return 0 ;
}
static int F_68 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_96 = 0 , V_446 ;
struct V_262 * V_263 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_184 ;
F_15 () ;
if ( ! V_263 ) {
V_263 = F_39 ( sizeof( * V_263 ) , V_126 ) ;
if ( ! V_263 ) {
F_21 () ;
return - V_127 ;
}
V_263 -> V_448 = - 1 ;
V_446 = F_67 ( V_32 , V_34 , V_263 ) ;
if ( V_446 ) {
F_42 ( V_263 ) ;
F_21 () ;
return V_446 ;
}
V_34 -> args [ 0 ] = ( long ) V_263 ;
}
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_69 ( F_7 ( & V_184 -> V_18 ) , F_17 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_96 <= V_263 -> V_449 )
continue;
if ( V_263 -> V_448 != - 1 &&
V_263 -> V_448 != V_184 -> V_14 )
continue;
do {
V_446 = F_57 ( V_184 , V_32 ,
F_70 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_450 ,
V_451 , V_263 ) ;
if ( V_446 < 0 ) {
if ( ( V_446 == - V_82 || V_446 == - V_445 ) &&
! V_32 -> V_47 &&
V_34 -> V_452 < 4096 ) {
V_34 -> V_452 = 4096 ;
F_21 () ;
return 1 ;
}
V_96 -- ;
break;
}
} while ( V_263 -> V_277 > 0 );
break;
}
F_21 () ;
V_263 -> V_449 = V_96 ;
return V_32 -> V_47 ;
}
static int F_71 ( struct V_33 * V_34 )
{
F_42 ( ( void * ) V_34 -> args [ 0 ] ) ;
return 0 ;
}
static int F_72 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_184 = V_30 -> V_453 [ 0 ] ;
struct V_262 V_263 = {} ;
V_53 = F_73 ( 4096 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_57 ( V_184 , V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
& V_263 ) < 0 ) {
F_74 ( V_53 ) ;
return - V_82 ;
}
return F_75 ( V_53 , V_30 ) ;
}
static int F_76 ( struct V_4 * V_86 [] ,
struct V_456 * V_457 )
{
if ( ! V_86 [ V_458 ] || ! V_86 [ V_459 ] ||
! V_86 [ V_460 ] || ! V_86 [ V_461 ] ||
! V_86 [ V_462 ] )
return - V_16 ;
V_457 -> V_463 = F_35 ( V_86 [ V_458 ] ) ;
V_457 -> V_464 = F_77 ( V_86 [ V_459 ] ) ;
V_457 -> V_465 = F_77 ( V_86 [ V_460 ] ) ;
V_457 -> V_466 = F_77 ( V_86 [ V_461 ] ) ;
V_457 -> V_467 = F_35 ( V_86 [ V_462 ] ) ;
if ( V_457 -> V_463 >= V_468 )
return - V_16 ;
return 0 ;
}
static bool F_78 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_132 == V_133 ||
V_17 -> V_132 == V_136 ||
V_17 -> V_132 == V_469 ||
V_17 -> V_132 == V_135 ;
}
static int F_79 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_470 * V_471 )
{
V_22 V_472 ;
if ( ! V_30 -> V_5 [ V_473 ] )
return - V_16 ;
V_472 = F_4 ( V_30 -> V_5 [ V_473 ] ) ;
V_471 -> V_55 = F_80 ( & V_7 -> V_18 , V_472 ) ;
V_471 -> V_474 = V_475 ;
V_471 -> V_476 = V_472 ;
V_471 -> V_477 = 0 ;
if ( ! V_471 -> V_55 || V_471 -> V_55 -> V_51 & V_60 )
return - V_16 ;
if ( V_30 -> V_5 [ V_478 ] ) {
enum V_479 V_480 ;
V_480 = F_4 (
V_30 -> V_5 [ V_478 ] ) ;
switch ( V_480 ) {
case V_481 :
case V_482 :
case V_483 :
case V_484 :
F_81 ( V_471 , V_471 -> V_55 ,
V_480 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_485 ] ) {
V_471 -> V_474 =
F_4 ( V_30 -> V_5 [ V_485 ] ) ;
if ( V_30 -> V_5 [ V_486 ] )
V_471 -> V_476 =
F_4 (
V_30 -> V_5 [ V_486 ] ) ;
if ( V_30 -> V_5 [ V_487 ] )
V_471 -> V_477 =
F_4 (
V_30 -> V_5 [ V_487 ] ) ;
}
if ( ! F_82 ( V_471 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_471 ,
V_60 ) )
return - V_16 ;
if ( ( V_471 -> V_474 == V_488 ||
V_471 -> V_474 == V_489 ) &&
! ( V_7 -> V_18 . V_51 & V_310 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_29 * V_30 )
{
struct V_470 V_471 ;
int V_8 ;
enum V_253 V_132 = V_469 ;
if ( V_17 )
V_132 = V_17 -> V_132 ;
if ( ! F_78 ( V_17 ) )
return - V_490 ;
V_8 = F_79 ( V_7 , V_30 , & V_471 ) ;
if ( V_8 )
return V_8 ;
switch ( V_132 ) {
case V_133 :
case V_135 :
if ( V_17 -> V_491 ) {
V_8 = - V_492 ;
break;
}
if ( ! F_85 ( & V_7 -> V_18 , & V_471 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_493 = V_471 ;
V_8 = 0 ;
break;
case V_136 :
V_8 = F_86 ( V_7 , V_17 , & V_471 ) ;
break;
case V_469 :
V_8 = F_87 ( V_7 , & V_471 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_88 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_453 [ 1 ] ;
return F_84 ( V_7 , V_19 -> V_28 , V_30 ) ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
const T_2 * V_494 ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( F_90 ( V_184 ) )
return - V_492 ;
if ( ! V_7 -> V_326 -> V_391 )
return - V_490 ;
if ( V_17 -> V_132 != V_496 )
return - V_490 ;
V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
return F_91 ( V_7 , V_184 , V_494 ) ;
}
static int F_92 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_497 = 0 ;
struct V_4 * V_498 ;
V_22 V_499 ;
T_2 V_279 = 0 , V_281 = 0 ;
V_22 V_283 = 0 , V_285 = 0 ;
T_2 V_287 = 0 ;
F_2 () ;
if ( V_30 -> V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_30 -> V_5 [ V_10 ] ) ;
V_19 = F_10 ( F_93 ( V_30 ) , V_20 ) ;
if ( V_19 && V_19 -> V_28 )
V_7 = F_11 ( V_19 -> V_28 -> V_18 ) ;
else
V_19 = NULL ;
}
if ( ! V_19 ) {
V_7 = F_8 ( F_93 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_274 ] )
V_8 = F_94 (
V_7 , F_24 ( V_30 -> V_5 [ V_274 ] ) ) ;
if ( V_8 )
goto V_500;
if ( V_30 -> V_5 [ V_501 ] ) {
struct V_456 V_457 ;
struct V_4 * V_86 [ V_502 + 1 ] ;
if ( ! V_7 -> V_326 -> V_503 ) {
V_8 = - V_490 ;
goto V_500;
}
if ( ! V_19 ) {
V_8 = - V_16 ;
goto V_500;
}
if ( V_19 -> V_28 -> V_132 != V_133 &&
V_19 -> V_28 -> V_132 != V_135 ) {
V_8 = - V_16 ;
goto V_500;
}
if ( ! F_90 ( V_19 ) ) {
V_8 = - V_504 ;
goto V_500;
}
F_40 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_95 ( V_86 , V_502 ,
F_24 ( V_498 ) ,
F_25 ( V_498 ) ,
V_505 ) ;
V_8 = F_76 ( V_86 , & V_457 ) ;
if ( V_8 )
goto V_500;
V_8 = F_96 ( V_7 , V_19 ,
& V_457 ) ;
if ( V_8 )
goto V_500;
}
}
if ( V_30 -> V_5 [ V_473 ] ) {
V_8 = F_84 ( V_7 ,
F_78 ( V_17 ) ? V_17 : NULL ,
V_30 ) ;
if ( V_8 )
goto V_500;
}
if ( V_30 -> V_5 [ V_506 ] ) {
struct V_1 * V_507 = V_17 ;
enum V_508 type ;
int V_96 , V_509 = 0 ;
if ( ! ( V_7 -> V_18 . V_272 & V_510 ) )
V_507 = NULL ;
if ( ! V_7 -> V_326 -> V_511 ) {
V_8 = - V_490 ;
goto V_500;
}
V_96 = V_506 ;
type = F_4 ( V_30 -> V_5 [ V_96 ] ) ;
if ( ! V_30 -> V_5 [ V_512 ] &&
( type != V_513 ) ) {
V_8 = - V_16 ;
goto V_500;
}
if ( type != V_513 ) {
V_96 = V_512 ;
V_509 = F_4 ( V_30 -> V_5 [ V_96 ] ) ;
}
V_8 = F_97 ( V_7 , V_507 , type , V_509 ) ;
if ( V_8 )
goto V_500;
}
if ( V_30 -> V_5 [ V_331 ] &&
V_30 -> V_5 [ V_332 ] ) {
V_22 V_328 , V_329 ;
if ( ( ! V_7 -> V_18 . V_320 &&
! V_7 -> V_18 . V_322 ) ||
! V_7 -> V_326 -> V_514 ) {
V_8 = - V_490 ;
goto V_500;
}
V_328 = F_4 ( V_30 -> V_5 [ V_331 ] ) ;
V_329 = F_4 ( V_30 -> V_5 [ V_332 ] ) ;
if ( ( ~ V_328 && ( V_328 & ~ V_7 -> V_18 . V_320 ) ) ||
( ~ V_329 && ( V_329 & ~ V_7 -> V_18 . V_322 ) ) ) {
V_8 = - V_16 ;
goto V_500;
}
V_328 = V_328 & V_7 -> V_18 . V_320 ;
V_329 = V_329 & V_7 -> V_18 . V_322 ;
V_8 = F_98 ( V_7 , V_328 , V_329 ) ;
if ( V_8 )
goto V_500;
}
V_499 = 0 ;
if ( V_30 -> V_5 [ V_278 ] ) {
V_279 = F_35 (
V_30 -> V_5 [ V_278 ] ) ;
if ( V_279 == 0 ) {
V_8 = - V_16 ;
goto V_500;
}
V_499 |= V_515 ;
}
if ( V_30 -> V_5 [ V_280 ] ) {
V_281 = F_35 (
V_30 -> V_5 [ V_280 ] ) ;
if ( V_281 == 0 ) {
V_8 = - V_16 ;
goto V_500;
}
V_499 |= V_516 ;
}
if ( V_30 -> V_5 [ V_282 ] ) {
V_283 = F_4 (
V_30 -> V_5 [ V_282 ] ) ;
if ( V_283 < 256 ) {
V_8 = - V_16 ;
goto V_500;
}
if ( V_283 != ( V_22 ) - 1 ) {
V_283 &= ~ 0x1 ;
}
V_499 |= V_517 ;
}
if ( V_30 -> V_5 [ V_284 ] ) {
V_285 = F_4 (
V_30 -> V_5 [ V_284 ] ) ;
V_499 |= V_518 ;
}
if ( V_30 -> V_5 [ V_286 ] ) {
V_287 = F_35 (
V_30 -> V_5 [ V_286 ] ) ;
V_499 |= V_519 ;
}
if ( V_499 ) {
T_2 V_520 , V_521 ;
V_22 V_522 , V_523 ;
T_2 V_524 ;
if ( ! V_7 -> V_326 -> V_525 ) {
V_8 = - V_490 ;
goto V_500;
}
V_520 = V_7 -> V_18 . V_279 ;
V_521 = V_7 -> V_18 . V_281 ;
V_522 = V_7 -> V_18 . V_283 ;
V_523 = V_7 -> V_18 . V_285 ;
V_524 = V_7 -> V_18 . V_287 ;
if ( V_499 & V_515 )
V_7 -> V_18 . V_279 = V_279 ;
if ( V_499 & V_516 )
V_7 -> V_18 . V_281 = V_281 ;
if ( V_499 & V_517 )
V_7 -> V_18 . V_283 = V_283 ;
if ( V_499 & V_518 )
V_7 -> V_18 . V_285 = V_285 ;
if ( V_499 & V_519 )
V_7 -> V_18 . V_287 = V_287 ;
V_8 = F_99 ( V_7 , V_499 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_279 = V_520 ;
V_7 -> V_18 . V_281 = V_521 ;
V_7 -> V_18 . V_283 = V_522 ;
V_7 -> V_18 . V_285 = V_523 ;
V_7 -> V_18 . V_287 = V_524 ;
}
}
V_500:
if ( V_19 )
F_12 ( V_19 ) ;
return V_8 ;
}
static inline T_1 V_13 ( struct V_1 * V_17 )
{
return ( T_1 ) V_17 -> V_21 |
( ( T_1 ) F_11 ( V_17 -> V_18 ) -> V_14 << 32 ) ;
}
static int F_100 ( struct V_31 * V_53 ,
struct V_470 * V_471 )
{
F_58 ( ! F_82 ( V_471 ) ) ;
if ( F_29 ( V_53 , V_473 ,
V_471 -> V_55 -> V_58 ) )
return - V_82 ;
switch ( V_471 -> V_474 ) {
case V_475 :
case V_526 :
case V_527 :
if ( F_29 ( V_53 , V_478 ,
F_101 ( V_471 ) ) )
return - V_82 ;
break;
default:
break;
}
if ( F_29 ( V_53 , V_485 , V_471 -> V_474 ) )
return - V_82 ;
if ( F_29 ( V_53 , V_486 , V_471 -> V_476 ) )
return - V_82 ;
if ( V_471 -> V_477 &&
F_29 ( V_53 , V_487 , V_471 -> V_477 ) )
return - V_82 ;
return 0 ;
}
static int F_102 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_25 * V_184 = V_17 -> V_19 ;
void * V_264 ;
V_264 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_528 ) ;
if ( ! V_264 )
return - 1 ;
if ( V_184 &&
( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_59 ( V_53 , V_529 , V_184 -> V_530 ) ) )
goto V_59;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_531 , V_17 -> V_132 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_50 ( V_53 , V_495 , V_532 , F_104 ( V_17 ) ) ||
F_29 ( V_53 , V_275 ,
V_7 -> V_533 ^
( V_276 << 2 ) ) )
goto V_59;
if ( V_7 -> V_326 -> V_534 ) {
int V_446 ;
struct V_470 V_471 ;
V_446 = F_105 ( V_7 , V_17 , & V_471 ) ;
if ( V_446 == 0 ) {
if ( F_100 ( V_53 , & V_471 ) )
goto V_59;
}
}
if ( V_17 -> V_535 ) {
if ( F_50 ( V_53 , V_536 , V_17 -> V_535 , V_17 -> V_537 ) )
goto V_59;
}
return F_65 ( V_53 , V_264 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
static int F_106 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_538 = 0 ;
int V_539 = 0 ;
int V_540 = V_34 -> args [ 0 ] ;
int V_541 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_15 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_69 ( F_7 ( & V_7 -> V_18 ) , F_17 ( V_32 -> V_44 ) ) )
continue;
if ( V_538 < V_540 ) {
V_538 ++ ;
continue;
}
V_539 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_539 < V_541 ) {
V_539 ++ ;
continue;
}
if ( F_102 ( V_32 , F_70 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_450 , V_451 ,
V_7 , V_17 ) < 0 ) {
goto V_542;
}
V_539 ++ ;
}
V_538 ++ ;
}
V_542:
F_21 () ;
V_34 -> args [ 0 ] = V_538 ;
V_34 -> args [ 1 ] = V_539 ;
return V_32 -> V_47 ;
}
static int F_107 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_184 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_102 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_184 , V_17 ) < 0 ) {
F_74 ( V_53 ) ;
return - V_82 ;
}
return F_75 ( V_53 , V_30 ) ;
}
static int F_108 ( struct V_4 * V_544 , V_22 * V_545 )
{
struct V_4 * V_51 [ V_546 + 1 ] ;
int V_547 ;
* V_545 = 0 ;
if ( ! V_544 )
return - V_16 ;
if ( F_34 ( V_51 , V_546 ,
V_544 , V_548 ) )
return - V_16 ;
for ( V_547 = 1 ; V_547 <= V_546 ; V_547 ++ )
if ( V_51 [ V_547 ] )
* V_545 |= ( 1 << V_547 ) ;
return 0 ;
}
static int F_109 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_549 ,
enum V_253 V_132 )
{
if ( ! V_549 ) {
if ( V_19 && ( V_19 -> V_550 & V_551 ) )
return - V_492 ;
return 0 ;
}
switch ( V_132 ) {
case V_134 :
if ( V_7 -> V_18 . V_51 & V_552 )
return 0 ;
break;
case V_138 :
if ( V_7 -> V_18 . V_51 & V_553 )
return 0 ;
break;
default:
break;
}
return - V_490 ;
}
static int F_110 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_554 V_128 ;
int V_35 ;
enum V_253 V_555 , V_556 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
V_22 V_557 , * V_51 = NULL ;
bool V_558 = false ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_555 = V_556 = V_184 -> V_28 -> V_132 ;
if ( V_30 -> V_5 [ V_531 ] ) {
V_556 = F_4 ( V_30 -> V_5 [ V_531 ] ) ;
if ( V_555 != V_556 )
V_558 = true ;
if ( V_556 > V_559 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_560 ] ) {
struct V_1 * V_17 = V_184 -> V_28 ;
if ( V_556 != V_136 )
return - V_16 ;
if ( F_90 ( V_184 ) )
return - V_492 ;
F_111 ( V_17 ) ;
F_112 ( V_561 !=
V_562 ) ;
V_17 -> V_563 =
F_25 ( V_30 -> V_5 [ V_560 ] ) ;
memcpy ( V_17 -> V_537 , F_24 ( V_30 -> V_5 [ V_560 ] ) ,
V_17 -> V_563 ) ;
F_113 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_564 ] ) {
V_128 . V_549 = ! ! F_35 ( V_30 -> V_5 [ V_564 ] ) ;
V_558 = true ;
V_35 = F_109 ( V_7 , V_184 , V_128 . V_549 , V_556 ) ;
if ( V_35 )
return V_35 ;
} else {
V_128 . V_549 = - 1 ;
}
if ( V_30 -> V_5 [ V_565 ] ) {
if ( V_556 != V_469 )
return - V_16 ;
V_35 = F_108 ( V_30 -> V_5 [ V_565 ] ,
& V_557 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_557 ;
V_558 = true ;
}
if ( V_51 && ( * V_51 & V_566 ) &&
! ( V_7 -> V_18 . V_272 & V_567 ) )
return - V_490 ;
if ( V_558 )
V_35 = F_114 ( V_7 , V_184 , V_556 , V_51 , & V_128 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_128 . V_549 != - 1 )
V_184 -> V_28 -> V_549 = V_128 . V_549 ;
return V_35 ;
}
static int F_115 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_554 V_128 ;
struct V_1 * V_17 ;
struct V_31 * V_53 ;
int V_35 ;
enum V_253 type = V_568 ;
V_22 V_51 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_531 ] ) {
type = F_4 ( V_30 -> V_5 [ V_531 ] ) ;
if ( type > V_559 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_344 ||
! ( V_7 -> V_18 . V_334 & ( 1 << type ) ) )
return - V_490 ;
if ( type == V_569 && V_30 -> V_5 [ V_495 ] ) {
F_116 ( V_128 . V_570 , V_30 -> V_5 [ V_495 ] ,
V_532 ) ;
if ( ! F_117 ( V_128 . V_570 ) )
return - V_571 ;
}
if ( V_30 -> V_5 [ V_564 ] ) {
V_128 . V_549 = ! ! F_35 ( V_30 -> V_5 [ V_564 ] ) ;
V_35 = F_109 ( V_7 , NULL , V_128 . V_549 , type ) ;
if ( V_35 )
return V_35 ;
}
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_35 = F_108 ( type == V_469 ?
V_30 -> V_5 [ V_565 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_566 ) &&
! ( V_7 -> V_18 . V_272 & V_567 ) )
return - V_490 ;
V_17 = F_118 ( V_7 ,
F_24 ( V_30 -> V_5 [ V_529 ] ) ,
type , V_35 ? NULL : & V_51 , & V_128 ) ;
if ( F_18 ( V_17 ) ) {
F_74 ( V_53 ) ;
return F_19 ( V_17 ) ;
}
switch ( type ) {
case V_136 :
if ( ! V_30 -> V_5 [ V_560 ] )
break;
F_111 ( V_17 ) ;
F_112 ( V_561 !=
V_562 ) ;
V_17 -> V_563 =
F_25 ( V_30 -> V_5 [ V_560 ] ) ;
memcpy ( V_17 -> V_537 , F_24 ( V_30 -> V_5 [ V_560 ] ) ,
V_17 -> V_563 ) ;
F_113 ( V_17 ) ;
break;
case V_569 :
F_119 ( & V_17 -> V_572 ) ;
F_120 ( & V_17 -> V_573 ) ;
F_121 ( & V_17 -> V_574 ) ;
F_120 ( & V_17 -> V_575 ) ;
F_121 ( & V_17 -> V_576 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_122 ( & V_17 -> V_577 , & V_7 -> V_578 ) ;
V_7 -> V_533 ++ ;
break;
default:
break;
}
if ( F_102 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_7 , V_17 ) < 0 ) {
F_74 ( V_53 ) ;
return - V_82 ;
}
return F_75 ( V_53 , V_30 ) ;
}
static int F_123 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_579 )
return - V_490 ;
if ( ! V_17 -> V_19 )
V_30 -> V_453 [ 1 ] = NULL ;
return F_124 ( V_7 , V_17 ) ;
}
static int F_125 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_3 V_580 ;
if ( ! V_30 -> V_5 [ V_581 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_402 )
return - V_490 ;
V_580 = F_77 ( V_30 -> V_5 [ V_581 ] ) ;
return F_126 ( V_7 , V_184 , V_580 ) ;
}
static void F_127 ( void * V_150 , struct V_582 * V_128 )
{
struct V_4 * V_83 ;
struct V_583 * V_584 = V_150 ;
if ( ( V_128 -> V_83 &&
F_50 ( V_584 -> V_53 , V_112 ,
V_128 -> V_99 , V_128 -> V_83 ) ) ||
( V_128 -> V_50 &&
F_50 ( V_584 -> V_53 , V_113 ,
V_128 -> V_101 , V_128 -> V_50 ) ) ||
( V_128 -> V_103 &&
F_29 ( V_584 -> V_53 , V_115 ,
V_128 -> V_103 ) ) )
goto V_59;
V_83 = F_46 ( V_584 -> V_53 , V_120 ) ;
if ( ! V_83 )
goto V_59;
if ( ( V_128 -> V_83 &&
F_50 ( V_584 -> V_53 , V_97 ,
V_128 -> V_99 , V_128 -> V_83 ) ) ||
( V_128 -> V_50 &&
F_50 ( V_584 -> V_53 , V_100 ,
V_128 -> V_101 , V_128 -> V_50 ) ) ||
( V_128 -> V_103 &&
F_29 ( V_584 -> V_53 , V_102 ,
V_128 -> V_103 ) ) )
goto V_59;
if ( F_55 ( V_584 -> V_53 , V_114 , V_584 -> V_96 ) )
goto V_59;
F_47 ( V_584 -> V_53 , V_83 ) ;
return;
V_59:
V_584 -> error = 1 ;
}
static int F_128 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 V_585 = 0 ;
const T_2 * V_586 = NULL ;
bool V_587 ;
struct V_583 V_584 = {
. error = 0 ,
} ;
void * V_264 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_114 ] )
V_585 = F_35 ( V_30 -> V_5 [ V_114 ] ) ;
if ( V_585 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_495 ] )
V_586 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_587 = ! ! V_586 ;
if ( V_30 -> V_5 [ V_118 ] ) {
V_22 V_588 = F_4 ( V_30 -> V_5 [ V_118 ] ) ;
if ( V_588 >= V_105 )
return - V_16 ;
if ( V_588 != V_589 &&
V_588 != V_590 )
return - V_16 ;
V_587 = V_588 == V_590 ;
}
if ( ! V_7 -> V_326 -> V_591 )
return - V_490 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_592 ) ;
if ( ! V_264 )
goto V_59;
V_584 . V_53 = V_53 ;
V_584 . V_96 = V_585 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_55 ( V_53 , V_114 , V_585 ) )
goto V_59;
if ( V_586 &&
F_50 ( V_53 , V_495 , V_532 , V_586 ) )
goto V_59;
if ( V_587 && V_586 &&
! ( V_7 -> V_18 . V_51 & V_298 ) )
return - V_593 ;
V_35 = F_129 ( V_7 , V_184 , V_585 , V_587 , V_586 , & V_584 ,
F_127 ) ;
if ( V_35 )
goto V_594;
if ( V_584 . error )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_594:
F_74 ( V_53 ) ;
return V_35 ;
}
static int F_130 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_84 V_83 ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( V_83 . V_96 < 0 )
return - V_16 ;
if ( ! V_83 . V_89 && ! V_83 . V_91 )
return - V_16 ;
F_111 ( V_184 -> V_28 ) ;
if ( V_83 . V_89 ) {
if ( ! V_7 -> V_326 -> V_595 ) {
V_35 = - V_490 ;
goto V_542;
}
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( V_35 )
goto V_542;
V_35 = F_131 ( V_7 , V_184 , V_83 . V_96 ,
V_83 . V_93 , V_83 . V_94 ) ;
if ( V_35 )
goto V_542;
#ifdef F_132
V_184 -> V_28 -> V_596 . V_597 = V_83 . V_96 ;
#endif
} else {
if ( V_83 . V_93 || ! V_83 . V_94 ) {
V_35 = - V_16 ;
goto V_542;
}
if ( ! V_7 -> V_326 -> V_598 ) {
V_35 = - V_490 ;
goto V_542;
}
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( V_35 )
goto V_542;
V_35 = F_133 ( V_7 , V_184 , V_83 . V_96 ) ;
if ( V_35 )
goto V_542;
#ifdef F_132
V_184 -> V_28 -> V_596 . V_599 = V_83 . V_96 ;
#endif
}
V_542:
F_113 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_134 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_84 V_83 ;
const T_2 * V_586 = NULL ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_83 . V_98 . V_83 )
return - V_16 ;
if ( V_30 -> V_5 [ V_495 ] )
V_586 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( V_83 . type == - 1 ) {
if ( V_586 )
V_83 . type = V_590 ;
else
V_83 . type = V_589 ;
}
if ( V_83 . type != V_590 &&
V_83 . type != V_589 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_348 )
return - V_490 ;
if ( F_41 ( V_7 , & V_83 . V_98 , V_83 . V_96 ,
V_83 . type == V_590 ,
V_586 ) )
return - V_16 ;
F_111 ( V_184 -> V_28 ) ;
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_135 ( V_7 , V_184 , V_83 . V_96 ,
V_83 . type == V_590 ,
V_586 , & V_83 . V_98 ) ;
F_113 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_136 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 * V_586 = NULL ;
struct V_84 V_83 ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_495 ] )
V_586 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( V_83 . type == - 1 ) {
if ( V_586 )
V_83 . type = V_590 ;
else
V_83 . type = V_589 ;
}
if ( V_83 . type != V_590 &&
V_83 . type != V_589 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_600 )
return - V_490 ;
F_111 ( V_184 -> V_28 ) ;
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( V_83 . type == V_590 && V_586 &&
! ( V_7 -> V_18 . V_51 & V_298 ) )
V_35 = - V_593 ;
if ( ! V_35 )
V_35 = F_137 ( V_7 , V_184 , V_83 . V_96 ,
V_83 . type == V_590 ,
V_586 ) ;
#ifdef F_132
if ( ! V_35 ) {
if ( V_83 . V_96 == V_184 -> V_28 -> V_596 . V_597 )
V_184 -> V_28 -> V_596 . V_597 = - 1 ;
else if ( V_83 . V_96 == V_184 -> V_28 -> V_596 . V_599 )
V_184 -> V_28 -> V_596 . V_599 = - 1 ;
}
#endif
F_113 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_138 ( struct V_4 * V_601 )
{
struct V_4 * V_45 ;
int V_602 = 0 , V_24 ;
F_40 (attr, nl_attr, tmp) {
if ( F_25 ( V_45 ) != V_532 )
return - V_16 ;
V_602 ++ ;
}
return V_602 ;
}
static struct V_603 * F_139 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_604 V_605 ;
struct V_4 * V_45 ;
struct V_603 * V_606 ;
int V_144 = 0 , V_602 , V_24 ;
if ( ! V_18 -> V_436 )
return F_3 ( - V_490 ) ;
if ( ! V_30 -> V_5 [ V_607 ] )
return F_3 ( - V_16 ) ;
V_605 = F_4 ( V_30 -> V_5 [ V_607 ] ) ;
if ( V_605 != V_608 &&
V_605 != V_609 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_610 ] )
return F_3 ( - V_16 ) ;
V_602 = F_138 ( V_30 -> V_5 [ V_610 ] ) ;
if ( V_602 < 0 )
return F_3 ( V_602 ) ;
if ( V_602 > V_18 -> V_436 )
return F_3 ( - V_611 ) ;
V_606 = F_39 ( sizeof( * V_606 ) + ( sizeof( struct V_612 ) * V_602 ) ,
V_126 ) ;
if ( ! V_606 )
return F_3 ( - V_127 ) ;
F_40 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_606 -> V_613 [ V_144 ] . V_614 , F_24 ( V_45 ) , V_532 ) ;
V_144 ++ ;
}
V_606 -> V_615 = V_602 ;
V_606 -> V_605 = V_605 ;
return V_606 ;
}
static int F_140 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_603 * V_606 ;
int V_35 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_490 ;
if ( ! V_184 -> V_28 -> V_491 )
return - V_16 ;
V_606 = F_139 ( & V_7 -> V_18 , V_30 ) ;
if ( F_18 ( V_606 ) )
return F_19 ( V_606 ) ;
V_35 = F_141 ( V_7 , V_184 , V_606 ) ;
F_42 ( V_606 ) ;
return V_35 ;
}
static int F_142 ( struct V_4 * V_5 [] ,
struct V_616 * V_617 )
{
bool V_618 = false ;
if ( ! F_23 ( V_5 [ V_619 ] ) ||
! F_23 ( V_5 [ V_620 ] ) ||
! F_23 ( V_5 [ V_621 ] ) ||
! F_23 ( V_5 [ V_622 ] ) )
return - V_16 ;
memset ( V_617 , 0 , sizeof( * V_617 ) ) ;
if ( V_5 [ V_623 ] ) {
V_617 -> V_624 = F_24 ( V_5 [ V_623 ] ) ;
V_617 -> V_625 = F_25 ( V_5 [ V_623 ] ) ;
if ( ! V_617 -> V_625 )
return - V_16 ;
V_618 = true ;
}
if ( V_5 [ V_619 ] ) {
V_617 -> V_626 = F_24 ( V_5 [ V_619 ] ) ;
V_617 -> V_627 = F_25 ( V_5 [ V_619 ] ) ;
V_618 = true ;
}
if ( ! V_618 )
return - V_16 ;
if ( V_5 [ V_620 ] ) {
V_617 -> V_628 = F_24 ( V_5 [ V_620 ] ) ;
V_617 -> V_629 = F_25 ( V_5 [ V_620 ] ) ;
}
if ( V_5 [ V_621 ] ) {
V_617 -> V_630 =
F_24 ( V_5 [ V_621 ] ) ;
V_617 -> V_631 =
F_25 ( V_5 [ V_621 ] ) ;
}
if ( V_5 [ V_622 ] ) {
V_617 -> V_632 =
F_24 ( V_5 [ V_622 ] ) ;
V_617 -> V_633 =
F_25 ( V_5 [ V_622 ] ) ;
}
if ( V_5 [ V_634 ] ) {
V_617 -> V_635 = F_24 ( V_5 [ V_634 ] ) ;
V_617 -> V_636 = F_25 ( V_5 [ V_634 ] ) ;
}
return 0 ;
}
static bool F_143 ( struct V_6 * V_7 ,
struct V_637 * V_128 )
{
struct V_1 * V_17 ;
bool V_446 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 )
continue;
if ( ! V_17 -> V_493 . V_55 )
continue;
V_128 -> V_471 = V_17 -> V_493 ;
V_446 = true ;
break;
}
return V_446 ;
}
static bool F_144 ( struct V_6 * V_7 ,
enum V_638 V_639 ,
enum V_640 V_52 )
{
if ( V_639 > V_641 )
return false ;
switch ( V_52 ) {
case V_642 :
if ( ! ( V_7 -> V_18 . V_272 & V_643 ) &&
V_639 == V_644 )
return false ;
return true ;
case V_420 :
case V_645 :
if ( V_639 == V_644 )
return false ;
return true ;
default:
return false ;
}
}
static int F_145 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_637 V_128 ;
int V_35 ;
T_2 V_646 = 0 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_490 ;
if ( ! V_7 -> V_326 -> V_350 )
return - V_490 ;
if ( V_17 -> V_491 )
return - V_647 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ! V_30 -> V_5 [ V_648 ] ||
! V_30 -> V_5 [ V_649 ] ||
! V_30 -> V_5 [ V_623 ] )
return - V_16 ;
V_35 = F_142 ( V_30 -> V_5 , & V_128 . V_650 ) ;
if ( V_35 )
return V_35 ;
V_128 . V_491 =
F_4 ( V_30 -> V_5 [ V_648 ] ) ;
V_128 . V_651 =
F_4 ( V_30 -> V_5 [ V_649 ] ) ;
V_35 = F_146 ( V_7 , V_128 . V_491 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_536 ] ) {
V_128 . V_537 = F_24 ( V_30 -> V_5 [ V_536 ] ) ;
V_128 . V_535 =
F_25 ( V_30 -> V_5 [ V_536 ] ) ;
if ( V_128 . V_535 == 0 ||
V_128 . V_535 > V_561 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_652 ] ) {
V_128 . V_653 = F_4 (
V_30 -> V_5 [ V_652 ] ) ;
if ( V_128 . V_653 != V_654 &&
V_128 . V_653 != V_655 &&
V_128 . V_653 != V_656 )
return - V_16 ;
}
V_128 . V_657 = ! ! V_30 -> V_5 [ V_658 ] ;
if ( V_30 -> V_5 [ V_659 ] ) {
V_128 . V_639 = F_4 (
V_30 -> V_5 [ V_659 ] ) ;
if ( ! F_144 ( V_7 , V_128 . V_639 ,
V_645 ) )
return - V_16 ;
} else
V_128 . V_639 = V_660 ;
V_35 = F_147 ( V_7 , V_30 , & V_128 . V_661 ,
V_662 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_663 ] ) {
if ( ! ( V_7 -> V_18 . V_272 & V_664 ) )
return - V_490 ;
V_128 . V_665 = F_77 (
V_30 -> V_5 [ V_663 ] ) ;
}
if ( V_30 -> V_5 [ V_666 ] ) {
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_128 . V_667 =
F_35 ( V_30 -> V_5 [ V_666 ] ) ;
if ( V_128 . V_667 > 127 )
return - V_16 ;
if ( V_128 . V_667 != 0 &&
! ( V_7 -> V_18 . V_272 & V_668 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_669 ] ) {
T_2 V_24 ;
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_24 = F_35 ( V_30 -> V_5 [ V_669 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_128 . V_670 = V_24 ;
if ( V_128 . V_670 != 0 &&
! ( V_7 -> V_18 . V_272 & V_671 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_473 ] ) {
V_35 = F_79 ( V_7 , V_30 , & V_128 . V_471 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_493 . V_55 ) {
V_128 . V_471 = V_17 -> V_493 ;
} else if ( ! F_143 ( V_7 , & V_128 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_128 . V_471 ) )
return - V_16 ;
V_35 = F_148 ( V_17 -> V_18 , & V_128 . V_471 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 ) {
V_646 = F_149 ( V_128 . V_471 . V_474 ) ;
V_128 . V_672 = true ;
}
V_35 = F_150 ( V_7 , V_17 , V_17 -> V_132 ,
V_128 . V_471 . V_55 ,
V_673 ,
V_646 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_607 ] ) {
V_128 . V_606 = F_139 ( & V_7 -> V_18 , V_30 ) ;
if ( F_18 ( V_128 . V_606 ) )
return F_19 ( V_128 . V_606 ) ;
}
V_35 = F_151 ( V_7 , V_184 , & V_128 ) ;
if ( ! V_35 ) {
V_17 -> V_493 = V_128 . V_471 ;
V_17 -> V_491 = V_128 . V_491 ;
V_17 -> V_674 = V_128 . V_471 . V_55 ;
V_17 -> V_535 = V_128 . V_535 ;
memcpy ( V_17 -> V_537 , V_128 . V_537 , V_17 -> V_535 ) ;
}
F_42 ( V_128 . V_606 ) ;
return V_35 ;
}
static int F_152 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_616 V_128 ;
int V_35 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_490 ;
if ( ! V_7 -> V_326 -> V_675 )
return - V_490 ;
if ( ! V_17 -> V_491 )
return - V_16 ;
V_35 = F_142 ( V_30 -> V_5 , & V_128 ) ;
if ( V_35 )
return V_35 ;
return F_153 ( V_7 , V_184 , & V_128 ) ;
}
static int F_154 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
return F_155 ( V_7 , V_184 ) ;
}
static int F_156 ( struct V_29 * V_30 ,
enum V_253 V_132 ,
struct V_676 * V_128 )
{
struct V_4 * V_51 [ V_677 + 1 ] ;
struct V_4 * V_544 ;
int V_547 ;
V_544 = V_30 -> V_5 [ V_678 ] ;
if ( V_544 ) {
struct V_679 * V_680 ;
V_680 = F_24 ( V_544 ) ;
V_128 -> V_681 = V_680 -> V_682 ;
V_128 -> V_683 = V_680 -> V_684 ;
V_128 -> V_683 &= V_128 -> V_681 ;
if ( ( V_128 -> V_681 |
V_128 -> V_683 ) & F_149 ( V_685 ) )
return - V_16 ;
return 0 ;
}
V_544 = V_30 -> V_5 [ V_686 ] ;
if ( ! V_544 )
return 0 ;
if ( F_34 ( V_51 , V_677 ,
V_544 , V_687 ) )
return - V_16 ;
switch ( V_132 ) {
case V_133 :
case V_134 :
case V_135 :
V_128 -> V_681 = F_149 ( V_688 ) |
F_149 ( V_689 ) |
F_149 ( V_690 ) |
F_149 ( V_691 ) ;
break;
case V_139 :
case V_138 :
V_128 -> V_681 = F_149 ( V_688 ) |
F_149 ( V_692 ) ;
break;
case V_136 :
V_128 -> V_681 = F_149 ( V_693 ) |
F_149 ( V_691 ) |
F_149 ( V_688 ) ;
default:
return - V_16 ;
}
for ( V_547 = 1 ; V_547 <= V_677 ; V_547 ++ ) {
if ( V_51 [ V_547 ] ) {
V_128 -> V_683 |= ( 1 << V_547 ) ;
if ( V_547 > V_694 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_157 ( struct V_31 * V_53 , struct V_695 * V_30 ,
int V_45 )
{
struct V_4 * V_225 ;
V_22 V_245 ;
T_3 V_696 ;
V_225 = F_46 ( V_53 , V_45 ) ;
if ( ! V_225 )
return false ;
V_245 = F_158 ( V_30 ) ;
V_696 = V_245 < ( 1UL << 16 ) ? V_245 : 0 ;
if ( V_245 > 0 &&
F_29 ( V_53 , V_697 , V_245 ) )
return false ;
if ( V_696 > 0 &&
F_54 ( V_53 , V_698 , V_696 ) )
return false ;
if ( V_30 -> V_51 & V_699 ) {
if ( F_55 ( V_53 , V_700 , V_30 -> V_229 ) )
return false ;
if ( V_30 -> V_51 & V_701 &&
F_30 ( V_53 , V_702 ) )
return false ;
if ( V_30 -> V_51 & V_703 &&
F_30 ( V_53 , V_704 ) )
return false ;
} else if ( V_30 -> V_51 & V_705 ) {
if ( F_55 ( V_53 , V_706 , V_30 -> V_229 ) )
return false ;
if ( F_55 ( V_53 , V_707 , V_30 -> V_708 ) )
return false ;
if ( V_30 -> V_51 & V_701 &&
F_30 ( V_53 , V_702 ) )
return false ;
if ( V_30 -> V_51 & V_709 &&
F_30 ( V_53 , V_710 ) )
return false ;
if ( V_30 -> V_51 & V_711 &&
F_30 ( V_53 , V_712 ) )
return false ;
if ( V_30 -> V_51 & V_713 &&
F_30 ( V_53 , V_714 ) )
return false ;
if ( V_30 -> V_51 & V_703 &&
F_30 ( V_53 , V_704 ) )
return false ;
}
F_47 ( V_53 , V_225 ) ;
return true ;
}
static bool F_159 ( struct V_31 * V_53 , T_2 V_682 , T_6 * signal ,
int V_715 )
{
void * V_45 ;
int V_144 = 0 ;
if ( ! V_682 )
return true ;
V_45 = F_46 ( V_53 , V_715 ) ;
if ( ! V_45 )
return false ;
for ( V_144 = 0 ; V_144 < V_716 ; V_144 ++ ) {
if ( ! ( V_682 & F_149 ( V_144 ) ) )
continue;
if ( F_55 ( V_53 , V_144 , signal [ V_144 ] ) )
return false ;
}
F_47 ( V_53 , V_45 ) ;
return true ;
}
static int F_160 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_184 ,
const T_2 * V_586 , struct V_717 * V_718 )
{
void * V_264 ;
struct V_4 * V_719 , * V_720 ;
V_264 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_721 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_586 ) ||
F_29 ( V_53 , V_275 , V_718 -> V_722 ) )
goto V_59;
V_719 = F_46 ( V_53 , V_723 ) ;
if ( ! V_719 )
goto V_59;
if ( ( V_718 -> V_724 & V_725 ) &&
F_29 ( V_53 , V_726 ,
V_718 -> V_727 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_728 ) &&
F_29 ( V_53 , V_729 ,
V_718 -> V_730 ) )
goto V_59;
if ( ( V_718 -> V_724 & ( V_731 |
V_732 ) ) &&
F_29 ( V_53 , V_733 ,
( V_22 ) V_718 -> V_734 ) )
goto V_59;
if ( ( V_718 -> V_724 & ( V_735 |
V_736 ) ) &&
F_29 ( V_53 , V_737 ,
( V_22 ) V_718 -> V_738 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_732 ) &&
F_103 ( V_53 , V_739 ,
V_718 -> V_734 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_736 ) &&
F_103 ( V_53 , V_740 ,
V_718 -> V_738 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_741 ) &&
F_54 ( V_53 , V_742 , V_718 -> V_743 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_744 ) &&
F_54 ( V_53 , V_745 , V_718 -> V_746 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_747 ) &&
F_55 ( V_53 , V_748 ,
V_718 -> V_749 ) )
goto V_59;
switch ( V_7 -> V_18 . V_750 ) {
case V_751 :
if ( ( V_718 -> V_724 & V_752 ) &&
F_55 ( V_53 , V_753 ,
V_718 -> signal ) )
goto V_59;
if ( ( V_718 -> V_724 & V_754 ) &&
F_55 ( V_53 , V_755 ,
V_718 -> V_756 ) )
goto V_59;
break;
default:
break;
}
if ( V_718 -> V_724 & V_757 ) {
if ( ! F_159 ( V_53 , V_718 -> V_758 ,
V_718 -> V_759 ,
V_760 ) )
goto V_59;
}
if ( V_718 -> V_724 & V_761 ) {
if ( ! F_159 ( V_53 , V_718 -> V_758 ,
V_718 -> V_762 ,
V_763 ) )
goto V_59;
}
if ( V_718 -> V_724 & V_764 ) {
if ( ! F_157 ( V_53 , & V_718 -> V_765 ,
V_766 ) )
goto V_59;
}
if ( V_718 -> V_724 & V_767 ) {
if ( ! F_157 ( V_53 , & V_718 -> V_768 ,
V_769 ) )
goto V_59;
}
if ( ( V_718 -> V_724 & V_770 ) &&
F_29 ( V_53 , V_771 ,
V_718 -> V_772 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_773 ) &&
F_29 ( V_53 , V_774 ,
V_718 -> V_775 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_776 ) &&
F_29 ( V_53 , V_777 ,
V_718 -> V_778 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_779 ) &&
F_29 ( V_53 , V_780 ,
V_718 -> V_781 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_782 ) &&
F_29 ( V_53 , V_783 ,
V_718 -> V_784 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_785 ) &&
F_29 ( V_53 , V_786 ,
V_718 -> V_787 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_788 ) &&
F_29 ( V_53 , V_789 ,
V_718 -> V_790 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_791 ) &&
F_29 ( V_53 , V_792 ,
V_718 -> V_793 ) )
goto V_59;
if ( V_718 -> V_724 & V_794 ) {
V_720 = F_46 ( V_53 , V_795 ) ;
if ( ! V_720 )
goto V_59;
if ( ( ( V_718 -> V_720 . V_51 & V_796 ) &&
F_30 ( V_53 , V_797 ) ) ||
( ( V_718 -> V_720 . V_51 & V_798 ) &&
F_30 ( V_53 , V_799 ) ) ||
( ( V_718 -> V_720 . V_51 & V_800 ) &&
F_30 ( V_53 , V_801 ) ) ||
F_55 ( V_53 , V_802 ,
V_718 -> V_720 . V_651 ) ||
F_54 ( V_53 , V_803 ,
V_718 -> V_720 . V_491 ) )
goto V_59;
F_47 ( V_53 , V_720 ) ;
}
if ( ( V_718 -> V_724 & V_804 ) &&
F_50 ( V_53 , V_805 ,
sizeof( struct V_679 ) ,
& V_718 -> V_680 ) )
goto V_59;
if ( ( V_718 -> V_724 & V_806 ) &&
F_103 ( V_53 , V_807 ,
V_718 -> V_808 ) )
goto V_59;
F_47 ( V_53 , V_719 ) ;
if ( ( V_718 -> V_724 & V_809 ) &&
F_50 ( V_53 , V_620 , V_718 -> V_810 ,
V_718 -> V_811 ) )
goto V_59;
return F_65 ( V_53 , V_264 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
static int F_161 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_717 V_718 ;
struct V_6 * V_184 ;
struct V_1 * V_17 ;
T_2 V_586 [ V_532 ] ;
int V_812 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_14 ( V_32 , V_34 , & V_184 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_813;
}
if ( ! V_184 -> V_326 -> V_814 ) {
V_35 = - V_490 ;
goto V_813;
}
while ( 1 ) {
memset ( & V_718 , 0 , sizeof( V_718 ) ) ;
V_35 = F_162 ( V_184 , V_17 -> V_19 , V_812 ,
V_586 , & V_718 ) ;
if ( V_35 == - V_593 )
break;
if ( V_35 )
goto V_813;
if ( F_160 ( V_32 ,
F_70 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_450 , V_451 ,
V_184 , V_17 -> V_19 , V_586 ,
& V_718 ) < 0 )
goto V_542;
V_812 ++ ;
}
V_542:
V_34 -> args [ 2 ] = V_812 ;
V_35 = V_32 -> V_47 ;
V_813:
F_22 ( V_184 ) ;
return V_35 ;
}
static int F_163 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_717 V_718 ;
struct V_31 * V_53 ;
T_2 * V_586 = NULL ;
int V_35 ;
memset ( & V_718 , 0 , sizeof( V_718 ) ) ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
V_586 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( ! V_7 -> V_326 -> V_815 )
return - V_490 ;
V_35 = F_164 ( V_7 , V_184 , V_586 , & V_718 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_160 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_7 , V_184 , V_586 , & V_718 ) < 0 ) {
F_74 ( V_53 ) ;
return - V_82 ;
}
return F_75 ( V_53 , V_30 ) ;
}
int F_165 ( struct V_18 * V_18 ,
struct V_676 * V_128 ,
enum V_816 V_817 )
{
if ( V_128 -> V_818 != - 1 )
return - V_16 ;
if ( V_128 -> V_819 )
return - V_16 ;
F_112 ( V_677 != 7 ) ;
switch ( V_817 ) {
case V_820 :
case V_821 :
if ( V_128 -> V_681 &
~ ( F_149 ( V_693 ) |
F_149 ( V_691 ) |
F_149 ( V_688 ) ) )
return - V_16 ;
break;
case V_822 :
case V_823 :
if ( ! ( V_128 -> V_683 & F_149 ( V_692 ) ) )
return - V_16 ;
V_128 -> V_681 &= ~ F_149 ( V_692 ) ;
break;
default:
if ( V_128 -> V_824 != V_825 )
return - V_16 ;
if ( V_128 -> V_787 )
return - V_16 ;
if ( V_128 -> V_826 & V_827 )
return - V_16 ;
}
if ( V_817 != V_822 &&
V_817 != V_823 ) {
if ( V_128 -> V_683 & F_149 ( V_692 ) )
return - V_16 ;
V_128 -> V_681 &= ~ F_149 ( V_692 ) ;
}
if ( V_817 != V_822 ) {
if ( V_128 -> V_826 & V_828 )
return - V_16 ;
if ( V_128 -> V_826 & V_829 )
return - V_16 ;
if ( V_128 -> V_830 )
return - V_16 ;
if ( V_128 -> V_831 || V_128 -> V_832 || V_128 -> V_833 )
return - V_16 ;
}
if ( V_817 != V_834 ) {
if ( V_128 -> V_835 )
return - V_16 ;
}
switch ( V_817 ) {
case V_836 :
if ( ! ( V_128 -> V_681 & F_149 ( V_688 ) ) )
return - V_490 ;
break;
case V_834 :
if ( V_128 -> V_681 &
~ ( F_149 ( V_688 ) |
F_149 ( V_693 ) |
F_149 ( V_837 ) |
F_149 ( V_689 ) |
F_149 ( V_690 ) |
F_149 ( V_691 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_272 & V_838 ) &&
V_128 -> V_681 &
( F_149 ( V_693 ) |
F_149 ( V_837 ) ) )
return - V_16 ;
break;
case V_839 :
case V_840 :
if ( V_128 -> V_681 & ~ F_149 ( V_688 ) )
return - V_16 ;
break;
case V_822 :
if ( V_128 -> V_681 & ~ ( F_149 ( V_688 ) |
F_149 ( V_690 ) ) )
return - V_16 ;
if ( V_128 -> V_683 & F_149 ( V_688 ) &&
! V_128 -> V_830 )
return - V_16 ;
break;
case V_823 :
return - V_16 ;
case V_820 :
if ( V_128 -> V_826 & V_827 )
return - V_16 ;
break;
case V_821 :
if ( V_128 -> V_824 != V_825 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_166 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_841 = V_30 -> V_5 [ V_842 ] ;
struct V_25 * V_843 ;
int V_446 ;
if ( ! V_841 )
return NULL ;
V_843 = F_10 ( F_93 ( V_30 ) , F_4 ( V_841 ) ) ;
if ( ! V_843 )
return F_3 ( - V_23 ) ;
if ( ! V_843 -> V_28 || V_843 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_446 = - V_16 ;
goto error;
}
if ( V_843 -> V_28 -> V_132 != V_134 &&
V_843 -> V_28 -> V_132 != V_133 &&
V_843 -> V_28 -> V_132 != V_135 ) {
V_446 = - V_16 ;
goto error;
}
if ( ! F_90 ( V_843 ) ) {
V_446 = - V_504 ;
goto error;
}
return V_843 ;
error:
F_12 ( V_843 ) ;
return F_3 ( V_446 ) ;
}
static int F_167 ( struct V_29 * V_30 ,
struct V_676 * V_128 )
{
struct V_4 * V_86 [ V_844 + 1 ] ;
struct V_4 * V_544 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_845 ] )
return 0 ;
V_544 = V_30 -> V_5 [ V_845 ] ;
V_35 = F_34 ( V_86 , V_844 , V_544 ,
V_846 ) ;
if ( V_35 )
return V_35 ;
if ( V_86 [ V_847 ] )
V_128 -> V_848 = F_35 (
V_86 [ V_847 ] ) ;
if ( V_128 -> V_848 & ~ V_849 )
return - V_16 ;
if ( V_86 [ V_850 ] )
V_128 -> V_851 = F_35 ( V_86 [ V_850 ] ) ;
if ( V_128 -> V_851 & ~ V_852 )
return - V_16 ;
V_128 -> V_826 |= V_828 ;
return 0 ;
}
static int F_168 ( struct V_29 * V_30 ,
struct V_676 * V_128 )
{
if ( V_30 -> V_5 [ V_853 ] ) {
V_128 -> V_854 =
F_24 ( V_30 -> V_5 [ V_853 ] ) ;
V_128 -> V_855 =
F_25 ( V_30 -> V_5 [ V_853 ] ) ;
if ( V_128 -> V_855 < 2 )
return - V_16 ;
if ( V_128 -> V_855 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_856 ] ) {
V_128 -> V_857 =
F_24 ( V_30 -> V_5 [ V_856 ] ) ;
V_128 -> V_858 =
F_25 ( V_30 -> V_5 [ V_856 ] ) ;
if ( V_128 -> V_858 < 2 ||
V_128 -> V_858 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_169 ( struct V_29 * V_30 ,
struct V_676 * V_128 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_859 ] )
V_128 -> V_819 = F_77 ( V_30 -> V_5 [ V_859 ] ) ;
if ( V_30 -> V_5 [ V_860 ] )
V_128 -> V_832 =
F_24 ( V_30 -> V_5 [ V_860 ] ) ;
if ( V_30 -> V_5 [ V_861 ] )
V_128 -> V_833 =
F_24 ( V_30 -> V_5 [ V_861 ] ) ;
V_35 = F_168 ( V_30 , V_128 ) ;
if ( V_35 )
return V_35 ;
return F_167 ( V_30 , V_128 ) ;
}
static int F_170 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_676 V_128 ;
T_2 * V_586 ;
int V_35 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_818 = - 1 ;
if ( ! V_7 -> V_326 -> V_862 )
return - V_490 ;
if ( V_30 -> V_5 [ V_863 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
V_586 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( V_30 -> V_5 [ V_864 ] ) {
V_128 . V_830 =
F_24 ( V_30 -> V_5 [ V_864 ] ) ;
V_128 . V_865 =
F_25 ( V_30 -> V_5 [ V_864 ] ) ;
}
if ( V_30 -> V_5 [ V_866 ] ) {
V_128 . V_867 =
F_77 ( V_30 -> V_5 [ V_866 ] ) ;
V_128 . V_826 |= V_829 ;
}
if ( V_30 -> V_5 [ V_868 ] ) {
V_128 . V_831 =
F_24 ( V_30 -> V_5 [ V_868 ] ) ;
V_128 . V_869 =
F_25 ( V_30 -> V_5 [ V_868 ] ) ;
}
if ( V_30 -> V_5 [ V_870 ] )
return - V_16 ;
if ( F_156 ( V_30 , V_184 -> V_28 -> V_132 , & V_128 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_871 ] ) {
V_128 . V_824 =
F_35 ( V_30 -> V_5 [ V_871 ] ) ;
if ( V_128 . V_824 >= V_872 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_873 ] ) {
V_128 . V_749 =
F_35 ( V_30 -> V_5 [ V_873 ] ) ;
if ( V_128 . V_749 >= V_874 )
return - V_16 ;
V_128 . V_826 |= V_827 ;
}
if ( V_30 -> V_5 [ V_875 ] ) {
enum V_876 V_877 = F_4 (
V_30 -> V_5 [ V_875 ] ) ;
if ( V_877 <= V_878 ||
V_877 > V_879 )
return - V_16 ;
V_128 . V_787 = V_877 ;
}
V_35 = F_169 ( V_30 , & V_128 ) ;
if ( V_35 )
return V_35 ;
V_128 . V_835 = F_166 ( V_30 , V_7 ) ;
if ( F_18 ( V_128 . V_835 ) )
return F_19 ( V_128 . V_835 ) ;
switch ( V_184 -> V_28 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
case V_139 :
case V_138 :
case V_137 :
case V_136 :
break;
default:
V_35 = - V_490 ;
goto V_880;
}
V_35 = F_171 ( V_7 , V_184 , V_586 , & V_128 ) ;
V_880:
if ( V_128 . V_835 )
F_12 ( V_128 . V_835 ) ;
return V_35 ;
}
static int F_172 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_676 V_128 ;
T_2 * V_586 = NULL ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ! V_7 -> V_326 -> V_352 )
return - V_490 ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_870 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_864 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_863 ] &&
! V_30 -> V_5 [ V_859 ] )
return - V_16 ;
V_586 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_128 . V_830 =
F_24 ( V_30 -> V_5 [ V_864 ] ) ;
V_128 . V_865 =
F_25 ( V_30 -> V_5 [ V_864 ] ) ;
V_128 . V_818 =
F_77 ( V_30 -> V_5 [ V_870 ] ) ;
if ( V_30 -> V_5 [ V_859 ] )
V_128 . V_819 = F_77 ( V_30 -> V_5 [ V_859 ] ) ;
else
V_128 . V_819 = F_77 ( V_30 -> V_5 [ V_863 ] ) ;
if ( ! V_128 . V_819 || V_128 . V_819 > V_881 )
return - V_16 ;
if ( V_30 -> V_5 [ V_866 ] ) {
V_128 . V_867 =
F_77 ( V_30 -> V_5 [ V_866 ] ) ;
V_128 . V_826 |= V_829 ;
}
if ( V_30 -> V_5 [ V_868 ] ) {
V_128 . V_831 =
F_24 ( V_30 -> V_5 [ V_868 ] ) ;
V_128 . V_869 =
F_25 ( V_30 -> V_5 [ V_868 ] ) ;
}
if ( V_30 -> V_5 [ V_860 ] )
V_128 . V_832 =
F_24 ( V_30 -> V_5 [ V_860 ] ) ;
if ( V_30 -> V_5 [ V_861 ] )
V_128 . V_833 =
F_24 ( V_30 -> V_5 [ V_861 ] ) ;
if ( V_30 -> V_5 [ V_871 ] ) {
V_128 . V_824 =
F_35 ( V_30 -> V_5 [ V_871 ] ) ;
if ( V_128 . V_824 >= V_872 )
return - V_16 ;
}
V_35 = F_168 ( V_30 , & V_128 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_167 ( V_30 , & V_128 ) ;
if ( V_35 )
return V_35 ;
if ( F_156 ( V_30 , V_184 -> V_28 -> V_132 , & V_128 ) )
return - V_16 ;
F_112 ( V_677 != 7 ) ;
switch ( V_184 -> V_28 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
if ( ! ( V_7 -> V_18 . V_51 & V_302 ) ||
! ( V_128 . V_683 & F_149 ( V_690 ) ) )
V_128 . V_826 &= ~ V_828 ;
if ( ( V_128 . V_683 & F_149 ( V_692 ) ) ||
V_30 -> V_5 [ V_859 ] )
return - V_16 ;
V_128 . V_681 &= ~ F_149 ( V_692 ) ;
if ( ! ( V_7 -> V_18 . V_272 &
V_838 ) &&
V_128 . V_681 &
( F_149 ( V_693 ) |
F_149 ( V_837 ) ) )
return - V_16 ;
V_128 . V_835 = F_166 ( V_30 , V_7 ) ;
if ( F_18 ( V_128 . V_835 ) )
return F_19 ( V_128 . V_835 ) ;
break;
case V_136 :
V_128 . V_826 &= ~ V_828 ;
if ( V_128 . V_681 & F_149 ( V_837 ) )
return - V_16 ;
if ( ( V_128 . V_683 & F_149 ( V_692 ) ) ||
V_30 -> V_5 [ V_859 ] )
return - V_16 ;
break;
case V_138 :
case V_139 :
V_128 . V_826 &= ~ V_828 ;
if ( V_128 . V_681 &
( F_149 ( V_837 ) |
F_149 ( V_693 ) ) )
return - V_16 ;
if ( ! ( V_128 . V_683 & F_149 ( V_692 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_306 ) )
return - V_490 ;
if ( ! ( V_7 -> V_18 . V_51 & V_308 ) )
return - V_490 ;
V_128 . V_681 &= ~ F_149 ( V_688 ) ;
break;
default:
return - V_490 ;
}
V_35 = F_173 ( V_7 , V_184 , V_586 , & V_128 ) ;
if ( V_128 . V_835 )
F_12 ( V_128 . V_835 ) ;
return V_35 ;
}
static int F_174 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 * V_586 = NULL ;
if ( V_30 -> V_5 [ V_495 ] )
V_586 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_134 &&
V_184 -> V_28 -> V_132 != V_136 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_882 )
return - V_490 ;
return F_175 ( V_7 , V_184 , V_586 ) ;
}
static int F_176 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_184 ,
T_2 * V_883 , T_2 * V_884 ,
struct V_885 * V_886 )
{
void * V_264 ;
struct V_4 * V_887 ;
V_264 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_721 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_883 ) ||
F_50 ( V_53 , V_888 , V_532 , V_884 ) ||
F_29 ( V_53 , V_275 , V_886 -> V_722 ) )
goto V_59;
V_887 = F_46 ( V_53 , V_889 ) ;
if ( ! V_887 )
goto V_59;
if ( ( V_886 -> V_724 & V_890 ) &&
F_29 ( V_53 , V_891 ,
V_886 -> V_892 ) )
goto V_59;
if ( ( ( V_886 -> V_724 & V_893 ) &&
F_29 ( V_53 , V_894 , V_886 -> V_895 ) ) ||
( ( V_886 -> V_724 & V_896 ) &&
F_29 ( V_53 , V_897 ,
V_886 -> V_898 ) ) ||
( ( V_886 -> V_724 & V_899 ) &&
F_29 ( V_53 , V_900 ,
V_886 -> V_901 ) ) ||
( ( V_886 -> V_724 & V_902 ) &&
F_55 ( V_53 , V_903 ,
V_886 -> V_51 ) ) ||
( ( V_886 -> V_724 & V_904 ) &&
F_29 ( V_53 , V_905 ,
V_886 -> V_906 ) ) ||
( ( V_886 -> V_724 & V_907 ) &&
F_55 ( V_53 , V_908 ,
V_886 -> V_909 ) ) )
goto V_59;
F_47 ( V_53 , V_887 ) ;
return F_65 ( V_53 , V_264 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
static int F_177 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_885 V_886 ;
struct V_6 * V_184 ;
struct V_1 * V_17 ;
T_2 V_883 [ V_532 ] ;
T_2 V_884 [ V_532 ] ;
int V_910 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_14 ( V_32 , V_34 , & V_184 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_184 -> V_326 -> V_911 ) {
V_35 = - V_490 ;
goto V_813;
}
if ( V_17 -> V_132 != V_136 ) {
V_35 = - V_490 ;
goto V_813;
}
while ( 1 ) {
V_35 = F_178 ( V_184 , V_17 -> V_19 , V_910 , V_883 ,
V_884 , & V_886 ) ;
if ( V_35 == - V_593 )
break;
if ( V_35 )
goto V_813;
if ( F_176 ( V_32 , F_70 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_450 , V_451 ,
V_17 -> V_19 , V_883 , V_884 ,
& V_886 ) < 0 )
goto V_542;
V_910 ++ ;
}
V_542:
V_34 -> args [ 2 ] = V_910 ;
V_35 = V_32 -> V_47 ;
V_813:
F_22 ( V_184 ) ;
return V_35 ;
}
static int F_179 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_885 V_886 ;
struct V_31 * V_53 ;
T_2 * V_883 = NULL ;
T_2 V_884 [ V_532 ] ;
memset ( & V_886 , 0 , sizeof( V_886 ) ) ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
V_883 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( ! V_7 -> V_326 -> V_912 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_136 )
return - V_490 ;
V_35 = F_180 ( V_7 , V_184 , V_883 , V_884 , & V_886 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_176 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_184 , V_883 , V_884 , & V_886 ) < 0 ) {
F_74 ( V_53 ) ;
return - V_82 ;
}
return F_75 ( V_53 , V_30 ) ;
}
static int F_181 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 * V_883 = NULL ;
T_2 * V_884 = NULL ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_888 ] )
return - V_16 ;
V_883 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_884 = F_24 ( V_30 -> V_5 [ V_888 ] ) ;
if ( ! V_7 -> V_326 -> V_913 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_136 )
return - V_490 ;
return F_182 ( V_7 , V_184 , V_883 , V_884 ) ;
}
static int F_183 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 * V_883 = NULL ;
T_2 * V_884 = NULL ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_888 ] )
return - V_16 ;
V_883 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_884 = F_24 ( V_30 -> V_5 [ V_888 ] ) ;
if ( ! V_7 -> V_326 -> V_354 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_136 )
return - V_490 ;
return F_184 ( V_7 , V_184 , V_883 , V_884 ) ;
}
static int F_185 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 * V_883 = NULL ;
if ( V_30 -> V_5 [ V_495 ] )
V_883 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( ! V_7 -> V_326 -> V_914 )
return - V_490 ;
return F_186 ( V_7 , V_184 , V_883 ) ;
}
static int F_187 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_915 V_128 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_916 = - 1 ;
V_128 . V_917 = - 1 ;
V_128 . V_918 = - 1 ;
V_128 . V_919 = - 1 ;
V_128 . V_920 = - 1 ;
V_128 . V_667 = - 1 ;
V_128 . V_670 = - 1 ;
if ( V_30 -> V_5 [ V_921 ] )
V_128 . V_916 =
F_35 ( V_30 -> V_5 [ V_921 ] ) ;
if ( V_30 -> V_5 [ V_922 ] )
V_128 . V_917 =
F_35 ( V_30 -> V_5 [ V_922 ] ) ;
if ( V_30 -> V_5 [ V_923 ] )
V_128 . V_918 =
F_35 ( V_30 -> V_5 [ V_923 ] ) ;
if ( V_30 -> V_5 [ V_924 ] ) {
V_128 . V_925 =
F_24 ( V_30 -> V_5 [ V_924 ] ) ;
V_128 . V_926 =
F_25 ( V_30 -> V_5 [ V_924 ] ) ;
}
if ( V_30 -> V_5 [ V_927 ] )
V_128 . V_919 = ! ! F_35 ( V_30 -> V_5 [ V_927 ] ) ;
if ( V_30 -> V_5 [ V_928 ] )
V_128 . V_920 =
F_77 ( V_30 -> V_5 [ V_928 ] ) ;
if ( V_30 -> V_5 [ V_666 ] ) {
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_128 . V_667 =
F_188 ( V_30 -> V_5 [ V_666 ] ) ;
if ( V_128 . V_667 < 0 )
return - V_16 ;
if ( V_128 . V_667 != 0 &&
! ( V_7 -> V_18 . V_272 & V_668 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_669 ] ) {
T_2 V_24 ;
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_24 = F_35 ( V_30 -> V_5 [ V_669 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_128 . V_670 = V_24 ;
if ( V_128 . V_670 &&
! ( V_7 -> V_18 . V_272 & V_671 ) )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_358 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_490 ;
return F_189 ( V_7 , V_184 , & V_128 ) ;
}
static int F_190 ( struct V_4 * V_86 [] ,
struct V_929 * V_930 )
{
struct V_931 * V_932 = & V_930 -> V_932 ;
struct V_933 * V_934 = & V_930 -> V_934 ;
if ( ! V_86 [ V_935 ] )
return - V_16 ;
if ( ! V_86 [ V_936 ] )
return - V_16 ;
if ( ! V_86 [ V_937 ] )
return - V_16 ;
if ( ! V_86 [ V_938 ] )
return - V_16 ;
if ( ! V_86 [ V_939 ] )
return - V_16 ;
V_930 -> V_51 = F_4 ( V_86 [ V_935 ] ) ;
V_932 -> V_940 =
F_4 ( V_86 [ V_936 ] ) ;
V_932 -> V_941 =
F_4 ( V_86 [ V_937 ] ) ;
V_932 -> V_942 =
F_4 ( V_86 [ V_938 ] ) ;
V_934 -> V_943 =
F_4 ( V_86 [ V_939 ] ) ;
if ( V_86 [ V_944 ] )
V_934 -> V_945 =
F_4 ( V_86 [ V_944 ] ) ;
return 0 ;
}
static int F_191 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
int V_946 ;
char * V_129 = NULL ;
enum V_947 V_948 ;
if ( F_192 ( ! F_193 ( V_949 ) ) )
return - V_950 ;
if ( ! V_30 -> V_5 [ V_951 ] )
return - V_16 ;
V_129 = F_24 ( V_30 -> V_5 [ V_951 ] ) ;
if ( V_30 -> V_5 [ V_952 ] )
V_948 =
F_4 ( V_30 -> V_5 [ V_952 ] ) ;
else
V_948 = V_953 ;
switch ( V_948 ) {
case V_953 :
case V_954 :
break;
default:
return - V_16 ;
}
V_946 = F_194 ( V_129 , V_948 ) ;
return V_946 ;
}
static int F_195 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_955 V_956 ;
int V_35 = 0 ;
void * V_264 ;
struct V_4 * V_887 ;
struct V_31 * V_53 ;
if ( V_17 -> V_132 != V_136 )
return - V_490 ;
if ( ! V_7 -> V_326 -> V_957 )
return - V_490 ;
F_111 ( V_17 ) ;
if ( ! V_17 -> V_958 )
memcpy ( & V_956 , & V_959 , sizeof( V_956 ) ) ;
else
V_35 = F_196 ( V_7 , V_184 , & V_956 ) ;
F_113 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_960 ) ;
if ( ! V_264 )
goto V_542;
V_887 = F_46 ( V_53 , V_961 ) ;
if ( ! V_887 )
goto V_59;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_54 ( V_53 , V_962 ,
V_956 . V_963 ) ||
F_54 ( V_53 , V_964 ,
V_956 . V_965 ) ||
F_54 ( V_53 , V_966 ,
V_956 . V_967 ) ||
F_54 ( V_53 , V_968 ,
V_956 . V_969 ) ||
F_55 ( V_53 , V_970 ,
V_956 . V_971 ) ||
F_55 ( V_53 , V_972 ,
V_956 . V_973 ) ||
F_55 ( V_53 , V_974 ,
V_956 . V_975 ) ||
F_55 ( V_53 , V_976 ,
V_956 . V_977 ) ||
F_29 ( V_53 , V_978 ,
V_956 . V_979 ) ||
F_55 ( V_53 , V_980 ,
V_956 . V_981 ) ||
F_29 ( V_53 , V_982 ,
V_956 . V_983 ) ||
F_54 ( V_53 , V_984 ,
V_956 . V_985 ) ||
F_29 ( V_53 , V_986 ,
V_956 . V_987 ) ||
F_54 ( V_53 , V_988 ,
V_956 . V_989 ) ||
F_54 ( V_53 , V_990 ,
V_956 . V_991 ) ||
F_54 ( V_53 , V_992 ,
V_956 . V_993 ) ||
F_55 ( V_53 , V_994 ,
V_956 . V_995 ) ||
F_54 ( V_53 , V_996 ,
V_956 . V_997 ) ||
F_55 ( V_53 , V_998 ,
V_956 . V_999 ) ||
F_55 ( V_53 , V_1000 ,
V_956 . V_1001 ) ||
F_29 ( V_53 , V_1002 ,
V_956 . V_1003 ) ||
F_29 ( V_53 , V_1004 ,
V_956 . V_920 ) ||
F_29 ( V_53 , V_1005 ,
V_956 . V_1006 ) ||
F_54 ( V_53 , V_1007 ,
V_956 . V_1008 ) ||
F_54 ( V_53 , V_1009 ,
V_956 . V_1010 ) ||
F_29 ( V_53 , V_1011 ,
V_956 . V_1012 ) ||
F_54 ( V_53 , V_1013 ,
V_956 . V_1014 ) ||
F_29 ( V_53 , V_1015 ,
V_956 . V_1016 ) )
goto V_59;
F_47 ( V_53 , V_887 ) ;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
V_542:
F_74 ( V_53 ) ;
return - V_82 ;
}
static int F_197 ( struct V_29 * V_30 ,
struct V_955 * V_1017 ,
V_22 * V_1018 )
{
struct V_4 * V_86 [ V_1019 + 1 ] ;
V_22 V_682 = 0 ;
#define F_198 ( V_86 , V_1017 , T_7 , T_8 , V_159 , V_682 , V_45 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_961 ] )
return - V_16 ;
if ( F_34 ( V_86 , V_1019 ,
V_30 -> V_5 [ V_961 ] ,
V_1020 ) )
return - V_16 ;
F_112 ( V_1019 > 32 ) ;
F_198 ( V_86 , V_1017 , V_963 , 1 , 255 ,
V_682 , V_962 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_965 , 1 , 255 ,
V_682 , V_964 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_967 , 1 , 255 ,
V_682 , V_966 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_969 , 0 , 255 ,
V_682 , V_968 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_971 , 0 , 16 ,
V_682 , V_970 ,
F_35 ) ;
F_198 ( V_86 , V_1017 , V_973 , 1 , 255 ,
V_682 , V_972 , F_35 ) ;
F_198 ( V_86 , V_1017 , V_975 , 1 , 255 ,
V_682 , V_974 ,
F_35 ) ;
F_198 ( V_86 , V_1017 , V_977 , 0 , 1 ,
V_682 , V_976 ,
F_35 ) ;
F_198 ( V_86 , V_1017 , V_979 ,
1 , 255 , V_682 ,
V_978 ,
F_4 ) ;
F_198 ( V_86 , V_1017 , V_981 , 0 , 255 ,
V_682 , V_980 ,
F_35 ) ;
F_198 ( V_86 , V_1017 , V_983 , 1 , 65535 ,
V_682 , V_982 ,
F_4 ) ;
F_198 ( V_86 , V_1017 , V_985 , 1 , 65535 ,
V_682 , V_984 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_987 ,
1 , 65535 , V_682 ,
V_986 ,
F_4 ) ;
F_198 ( V_86 , V_1017 , V_989 ,
1 , 65535 , V_682 ,
V_988 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_991 ,
1 , 65535 , V_682 ,
V_990 ,
F_77 ) ;
F_198 ( V_86 , V_1017 ,
V_993 ,
1 , 65535 , V_682 ,
V_992 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_995 , 0 , 4 ,
V_682 , V_994 ,
F_35 ) ;
F_198 ( V_86 , V_1017 , V_997 , 1 , 65535 ,
V_682 , V_996 ,
F_77 ) ;
F_198 ( V_86 , V_1017 ,
V_999 , 0 , 1 ,
V_682 , V_998 ,
F_35 ) ;
F_198 ( V_86 , V_1017 , V_1001 , 0 , 1 ,
V_682 , V_1000 ,
F_35 ) ;
F_198 ( V_86 , V_1017 , V_1003 , - 255 , 0 ,
V_682 , V_1002 ,
V_1021 ) ;
F_198 ( V_86 , V_1017 , V_920 , 0 , 16 ,
V_682 , V_1004 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_1006 ,
1 , 65535 , V_682 ,
V_1005 ,
F_4 ) ;
F_198 ( V_86 , V_1017 , V_1008 , 1 , 65535 ,
V_682 , V_1007 ,
F_77 ) ;
F_198 ( V_86 , V_1017 ,
V_1010 ,
1 , 65535 , V_682 ,
V_1009 ,
F_77 ) ;
F_198 ( V_86 , V_1017 , V_1012 ,
V_1022 ,
V_879 ,
V_682 , V_1011 ,
F_4 ) ;
F_198 ( V_86 , V_1017 , V_1014 ,
0 , 65535 , V_682 ,
V_1013 , F_77 ) ;
F_198 ( V_86 , V_1017 , V_1016 , 1 , 0xffffffff ,
V_682 , V_1015 ,
F_4 ) ;
if ( V_1018 )
* V_1018 = V_682 ;
return 0 ;
#undef F_198
}
static int F_199 ( struct V_29 * V_30 ,
struct V_1023 * V_1024 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_4 * V_86 [ V_1025 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1026 ] )
return - V_16 ;
if ( F_34 ( V_86 , V_1025 ,
V_30 -> V_5 [ V_1026 ] ,
V_1027 ) )
return - V_16 ;
if ( V_86 [ V_1028 ] )
V_1024 -> V_1029 =
( F_35 ( V_86 [ V_1028 ] ) ) ?
V_1030 :
V_1031 ;
if ( V_86 [ V_1032 ] )
V_1024 -> V_1033 =
( F_35 ( V_86 [ V_1032 ] ) ) ?
V_1034 :
V_1035 ;
if ( V_86 [ V_1036 ] )
V_1024 -> V_1037 =
( F_35 ( V_86 [ V_1036 ] ) ) ?
V_1038 :
V_1039 ;
if ( V_86 [ V_1040 ] ) {
struct V_4 * V_1041 =
V_86 [ V_1040 ] ;
if ( ! F_23 ( V_1041 ) )
return - V_16 ;
V_1024 -> V_1042 = F_24 ( V_1041 ) ;
V_1024 -> V_1043 = F_25 ( V_1041 ) ;
}
if ( V_86 [ V_1044 ] &&
! ( V_7 -> V_18 . V_272 & V_1045 ) )
return - V_16 ;
V_1024 -> V_1046 = F_200 ( V_86 [ V_1044 ] ) ;
V_1024 -> V_1047 = F_200 ( V_86 [ V_1048 ] ) ;
V_1024 -> V_1049 = F_200 ( V_86 [ V_1050 ] ) ;
if ( V_1024 -> V_1049 )
V_1024 -> V_1046 = true ;
if ( V_86 [ V_1051 ] ) {
if ( ! V_1024 -> V_1046 )
return - V_16 ;
V_1024 -> V_1052 =
F_35 ( V_86 [ V_1051 ] ) ;
}
return 0 ;
}
static int F_201 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_955 V_1017 ;
V_22 V_682 ;
int V_35 ;
if ( V_17 -> V_132 != V_136 )
return - V_490 ;
if ( ! V_7 -> V_326 -> V_356 )
return - V_490 ;
V_35 = F_197 ( V_30 , & V_1017 , & V_682 ) ;
if ( V_35 )
return V_35 ;
F_111 ( V_17 ) ;
if ( ! V_17 -> V_958 )
V_35 = - V_141 ;
if ( ! V_35 )
V_35 = F_202 ( V_7 , V_184 , V_682 , & V_1017 ) ;
F_113 ( V_17 ) ;
return V_35 ;
}
static int F_203 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1053 * V_1054 ;
struct V_31 * V_53 ;
void * V_264 = NULL ;
struct V_4 * V_1055 ;
unsigned int V_144 ;
if ( ! V_949 )
return - V_16 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_82 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1056 ) ;
if ( ! V_264 )
goto V_1057;
if ( F_204 () &&
F_29 ( V_53 , V_952 ,
V_954 ) )
goto V_59;
F_205 () ;
V_1054 = F_206 ( V_949 ) ;
if ( F_59 ( V_53 , V_951 , V_1054 -> V_1058 ) ||
( V_1054 -> V_1059 &&
F_55 ( V_53 , V_1060 , V_1054 -> V_1059 ) ) )
goto V_1061;
V_1055 = F_46 ( V_53 , V_1062 ) ;
if ( ! V_1055 )
goto V_1061;
for ( V_144 = 0 ; V_144 < V_1054 -> V_1063 ; V_144 ++ ) {
struct V_4 * V_1064 ;
const struct V_929 * V_930 ;
const struct V_931 * V_932 ;
const struct V_933 * V_934 ;
V_930 = & V_1054 -> V_1065 [ V_144 ] ;
V_932 = & V_930 -> V_932 ;
V_934 = & V_930 -> V_934 ;
V_1064 = F_46 ( V_53 , V_144 ) ;
if ( ! V_1064 )
goto V_1061;
if ( F_29 ( V_53 , V_935 ,
V_930 -> V_51 ) ||
F_29 ( V_53 , V_936 ,
V_932 -> V_940 ) ||
F_29 ( V_53 , V_937 ,
V_932 -> V_941 ) ||
F_29 ( V_53 , V_938 ,
V_932 -> V_942 ) ||
F_29 ( V_53 , V_944 ,
V_934 -> V_945 ) ||
F_29 ( V_53 , V_939 ,
V_934 -> V_943 ) )
goto V_1061;
F_47 ( V_53 , V_1064 ) ;
}
F_207 () ;
F_47 ( V_53 , V_1055 ) ;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_1061:
F_207 () ;
V_59:
F_66 ( V_53 , V_264 ) ;
V_1057:
F_74 ( V_53 ) ;
return - V_445 ;
}
static int F_208 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_86 [ V_1066 + 1 ] ;
struct V_4 * V_1064 ;
char * V_1058 = NULL ;
int V_1067 = 0 , V_946 = 0 ;
V_22 V_1068 = 0 , V_1069 = 0 , V_1070 ;
T_2 V_1059 = 0 ;
struct V_1053 * V_1071 = NULL ;
if ( ! V_30 -> V_5 [ V_951 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1062 ] )
return - V_16 ;
V_1058 = F_24 ( V_30 -> V_5 [ V_951 ] ) ;
if ( V_30 -> V_5 [ V_1060 ] )
V_1059 = F_35 ( V_30 -> V_5 [ V_1060 ] ) ;
F_40 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1068 ++ ;
if ( V_1068 > V_1072 )
return - V_16 ;
}
V_1070 = sizeof( struct V_1053 ) +
V_1068 * sizeof( struct V_929 ) ;
V_1071 = F_39 ( V_1070 , V_126 ) ;
if ( ! V_1071 )
return - V_127 ;
V_1071 -> V_1063 = V_1068 ;
V_1071 -> V_1058 [ 0 ] = V_1058 [ 0 ] ;
V_1071 -> V_1058 [ 1 ] = V_1058 [ 1 ] ;
if ( F_209 ( V_1059 ) )
V_1071 -> V_1059 = V_1059 ;
F_40 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_95 ( V_86 , V_1066 ,
F_24 ( V_1064 ) , F_25 ( V_1064 ) ,
V_1073 ) ;
V_946 = F_190 ( V_86 , & V_1071 -> V_1065 [ V_1069 ] ) ;
if ( V_946 )
goto V_1074;
V_1069 ++ ;
if ( V_1069 > V_1072 ) {
V_946 = - V_16 ;
goto V_1074;
}
}
V_946 = F_210 ( V_1071 ) ;
V_1071 = NULL ;
V_1074:
F_42 ( V_1071 ) ;
return V_946 ;
}
static int F_211 ( struct V_4 * V_1075 )
{
struct V_4 * V_1076 , * V_1077 ;
int V_341 = 0 , V_1078 , V_1079 ;
F_40 (attr1, freqs, tmp1) {
V_341 ++ ;
F_40 (attr2, freqs, tmp2)
if ( V_1076 != V_1077 &&
F_4 ( V_1076 ) == F_4 ( V_1077 ) )
return 0 ;
}
return V_341 ;
}
static int F_212 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
struct V_1080 * V_1081 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1082 = 0 , V_341 , V_144 ;
T_10 V_1043 ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_326 -> V_1083 )
return - V_490 ;
if ( V_7 -> V_1084 ) {
V_35 = - V_492 ;
goto V_1085;
}
if ( V_30 -> V_5 [ V_1086 ] ) {
V_341 = F_211 (
V_30 -> V_5 [ V_1086 ] ) ;
if ( ! V_341 ) {
V_35 = - V_16 ;
goto V_1085;
}
} else {
enum V_270 V_271 ;
V_341 = 0 ;
for ( V_271 = 0 ; V_271 < V_337 ; V_271 ++ )
if ( V_18 -> V_338 [ V_271 ] )
V_341 += V_18 -> V_338 [ V_271 ] -> V_341 ;
}
if ( V_30 -> V_5 [ V_1087 ] )
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1082 ++ ;
if ( V_1082 > V_18 -> V_289 ) {
V_35 = - V_16 ;
goto V_1085;
}
if ( V_30 -> V_5 [ V_620 ] )
V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
else
V_1043 = 0 ;
if ( V_1043 > V_18 -> V_293 ) {
V_35 = - V_16 ;
goto V_1085;
}
V_1081 = F_39 ( sizeof( * V_1081 )
+ sizeof( * V_1081 -> V_1088 ) * V_1082
+ sizeof( * V_1081 -> V_342 ) * V_341
+ V_1043 , V_126 ) ;
if ( ! V_1081 ) {
V_35 = - V_127 ;
goto V_1085;
}
if ( V_1082 )
V_1081 -> V_1088 = ( void * ) & V_1081 -> V_342 [ V_341 ] ;
V_1081 -> V_1082 = V_1082 ;
if ( V_1043 ) {
if ( V_1081 -> V_1088 )
V_1081 -> V_1042 = ( void * ) ( V_1081 -> V_1088 + V_1082 ) ;
else
V_1081 -> V_1042 = ( void * ) ( V_1081 -> V_342 + V_341 ) ;
}
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1086 ] ) {
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_80 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1089;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1081 -> V_342 [ V_144 ] = V_55 ;
V_144 ++ ;
}
} else {
enum V_270 V_271 ;
for ( V_271 = 0 ; V_271 < V_337 ; V_271 ++ ) {
int V_146 ;
if ( ! V_18 -> V_338 [ V_271 ] )
continue;
for ( V_146 = 0 ; V_146 < V_18 -> V_338 [ V_271 ] -> V_341 ; V_146 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_338 [ V_271 ] -> V_342 [ V_146 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1081 -> V_342 [ V_144 ] = V_55 ;
V_144 ++ ;
}
}
}
if ( ! V_144 ) {
V_35 = - V_16 ;
goto V_1089;
}
V_1081 -> V_341 = V_144 ;
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1087 ] ) {
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_25 ( V_45 ) > V_561 ) {
V_35 = - V_16 ;
goto V_1089;
}
V_1081 -> V_1088 [ V_144 ] . V_535 = F_25 ( V_45 ) ;
memcpy ( V_1081 -> V_1088 [ V_144 ] . V_537 , F_24 ( V_45 ) , F_25 ( V_45 ) ) ;
V_144 ++ ;
}
}
if ( V_30 -> V_5 [ V_620 ] ) {
V_1081 -> V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
memcpy ( ( void * ) V_1081 -> V_1042 ,
F_24 ( V_30 -> V_5 [ V_620 ] ) ,
V_1081 -> V_1043 ) ;
}
for ( V_144 = 0 ; V_144 < V_337 ; V_144 ++ )
if ( V_18 -> V_338 [ V_144 ] )
V_1081 -> V_1090 [ V_144 ] =
( 1 << V_18 -> V_338 [ V_144 ] -> V_242 ) - 1 ;
if ( V_30 -> V_5 [ V_1091 ] ) {
F_40 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_270 V_271 = F_213 ( V_45 ) ;
if ( V_271 < 0 || V_271 >= V_337 ) {
V_35 = - V_16 ;
goto V_1089;
}
if ( ! V_18 -> V_338 [ V_271 ] )
continue;
V_35 = F_214 ( V_18 -> V_338 [ V_271 ] ,
F_24 ( V_45 ) ,
F_25 ( V_45 ) ,
& V_1081 -> V_1090 [ V_271 ] ) ;
if ( V_35 )
goto V_1089;
}
}
if ( V_30 -> V_5 [ V_1092 ] ) {
V_1081 -> V_51 = F_4 (
V_30 -> V_5 [ V_1092 ] ) ;
if ( ( ( V_1081 -> V_51 & V_1093 ) &&
! ( V_18 -> V_272 & V_1094 ) ) ||
( ( V_1081 -> V_51 & V_1095 ) &&
! ( V_18 -> V_272 & V_1096 ) ) ) {
V_35 = - V_490 ;
goto V_1089;
}
}
V_1081 -> V_1097 =
F_200 ( V_30 -> V_5 [ V_1098 ] ) ;
V_1081 -> V_17 = V_17 ;
V_1081 -> V_18 = & V_7 -> V_18 ;
V_1081 -> V_1099 = V_1100 ;
V_7 -> V_1084 = V_1081 ;
V_35 = F_215 ( V_7 , V_1081 ) ;
if ( ! V_35 ) {
F_216 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_217 ( V_17 -> V_19 ) ;
} else {
V_1089:
V_7 -> V_1084 = NULL ;
F_42 ( V_1081 ) ;
}
V_1085:
return V_35 ;
}
static int F_218 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1101 * V_1081 ;
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1082 = 0 , V_1102 = 0 , V_341 , V_144 ;
V_22 V_1103 ;
enum V_270 V_271 ;
T_10 V_1043 ;
struct V_4 * V_86 [ V_1104 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_397 ) ||
! V_7 -> V_326 -> V_398 )
return - V_490 ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1105 ] )
return - V_16 ;
V_1103 = F_4 ( V_30 -> V_5 [ V_1105 ] ) ;
if ( V_1103 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_1086 ] ) {
V_341 = F_211 (
V_30 -> V_5 [ V_1086 ] ) ;
if ( ! V_341 )
return - V_16 ;
} else {
V_341 = 0 ;
for ( V_271 = 0 ; V_271 < V_337 ; V_271 ++ )
if ( V_18 -> V_338 [ V_271 ] )
V_341 += V_18 -> V_338 [ V_271 ] -> V_341 ;
}
if ( V_30 -> V_5 [ V_1087 ] )
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1082 ++ ;
if ( V_1082 > V_18 -> V_291 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1106 ] )
F_40 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_1102 ++ ;
if ( V_1102 > V_18 -> V_297 )
return - V_16 ;
if ( V_30 -> V_5 [ V_620 ] )
V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
else
V_1043 = 0 ;
if ( V_1043 > V_18 -> V_295 )
return - V_16 ;
if ( V_7 -> V_1107 ) {
V_35 = - V_950 ;
goto V_542;
}
V_1081 = F_39 ( sizeof( * V_1081 )
+ sizeof( * V_1081 -> V_1088 ) * V_1082
+ sizeof( * V_1081 -> V_1108 ) * V_1102
+ sizeof( * V_1081 -> V_342 ) * V_341
+ V_1043 , V_126 ) ;
if ( ! V_1081 ) {
V_35 = - V_127 ;
goto V_542;
}
if ( V_1082 )
V_1081 -> V_1088 = ( void * ) & V_1081 -> V_342 [ V_341 ] ;
V_1081 -> V_1082 = V_1082 ;
if ( V_1043 ) {
if ( V_1081 -> V_1088 )
V_1081 -> V_1042 = ( void * ) ( V_1081 -> V_1088 + V_1082 ) ;
else
V_1081 -> V_1042 = ( void * ) ( V_1081 -> V_342 + V_341 ) ;
}
if ( V_1102 ) {
if ( V_1081 -> V_1042 )
V_1081 -> V_1108 = ( void * ) ( V_1081 -> V_1042 + V_1043 ) ;
else if ( V_1081 -> V_1088 )
V_1081 -> V_1108 =
( void * ) ( V_1081 -> V_1088 + V_1082 ) ;
else
V_1081 -> V_1108 =
( void * ) ( V_1081 -> V_342 + V_341 ) ;
}
V_1081 -> V_1102 = V_1102 ;
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1086 ] ) {
F_40 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_80 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1089;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1081 -> V_342 [ V_144 ] = V_55 ;
V_144 ++ ;
}
} else {
for ( V_271 = 0 ; V_271 < V_337 ; V_271 ++ ) {
int V_146 ;
if ( ! V_18 -> V_338 [ V_271 ] )
continue;
for ( V_146 = 0 ; V_146 < V_18 -> V_338 [ V_271 ] -> V_341 ; V_146 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_338 [ V_271 ] -> V_342 [ V_146 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1081 -> V_342 [ V_144 ] = V_55 ;
V_144 ++ ;
}
}
}
if ( ! V_144 ) {
V_35 = - V_16 ;
goto V_1089;
}
V_1081 -> V_341 = V_144 ;
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1087 ] ) {
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_25 ( V_45 ) > V_561 ) {
V_35 = - V_16 ;
goto V_1089;
}
V_1081 -> V_1088 [ V_144 ] . V_535 = F_25 ( V_45 ) ;
memcpy ( V_1081 -> V_1088 [ V_144 ] . V_537 , F_24 ( V_45 ) ,
F_25 ( V_45 ) ) ;
V_144 ++ ;
}
}
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1106 ] ) {
F_40 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_537 , * V_1109 ;
F_95 ( V_86 , V_1104 ,
F_24 ( V_45 ) , F_25 ( V_45 ) ,
V_1110 ) ;
V_537 = V_86 [ V_1111 ] ;
if ( V_537 ) {
if ( F_25 ( V_537 ) > V_561 ) {
V_35 = - V_16 ;
goto V_1089;
}
memcpy ( V_1081 -> V_1108 [ V_144 ] . V_537 . V_537 ,
F_24 ( V_537 ) , F_25 ( V_537 ) ) ;
V_1081 -> V_1108 [ V_144 ] . V_537 . V_535 =
F_25 ( V_537 ) ;
}
V_1109 = V_86 [ V_1112 ] ;
if ( V_1109 )
V_1081 -> V_1113 = F_4 ( V_1109 ) ;
else
V_1081 -> V_1113 =
V_1114 ;
V_144 ++ ;
}
}
if ( V_30 -> V_5 [ V_620 ] ) {
V_1081 -> V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
memcpy ( ( void * ) V_1081 -> V_1042 ,
F_24 ( V_30 -> V_5 [ V_620 ] ) ,
V_1081 -> V_1043 ) ;
}
if ( V_30 -> V_5 [ V_1092 ] ) {
V_1081 -> V_51 = F_4 (
V_30 -> V_5 [ V_1092 ] ) ;
if ( ( ( V_1081 -> V_51 & V_1093 ) &&
! ( V_18 -> V_272 & V_1094 ) ) ||
( ( V_1081 -> V_51 & V_1095 ) &&
! ( V_18 -> V_272 & V_1096 ) ) ) {
V_35 = - V_490 ;
goto V_1089;
}
}
V_1081 -> V_184 = V_184 ;
V_1081 -> V_18 = & V_7 -> V_18 ;
V_1081 -> V_1103 = V_1103 ;
V_1081 -> V_1099 = V_1100 ;
V_35 = F_219 ( V_7 , V_184 , V_1081 ) ;
if ( ! V_35 ) {
V_7 -> V_1107 = V_1081 ;
F_220 ( V_7 , V_184 ,
V_1115 ) ;
goto V_542;
}
V_1089:
F_42 ( V_1081 ) ;
V_542:
return V_35 ;
}
static int F_221 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_397 ) ||
! V_7 -> V_326 -> V_1116 )
return - V_490 ;
return F_222 ( V_7 , false ) ;
}
static int F_223 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_470 V_471 ;
int V_35 ;
V_35 = F_79 ( V_7 , V_30 , & V_471 ) ;
if ( V_35 )
return V_35 ;
if ( F_224 ( V_184 ) )
return - V_492 ;
if ( V_17 -> V_1117 )
return - V_492 ;
V_35 = F_148 ( V_17 -> V_18 , & V_471 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( V_471 . V_55 -> V_70 != V_1118 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1119 )
return - V_490 ;
V_35 = F_150 ( V_7 , V_17 , V_17 -> V_132 ,
V_471 . V_55 , V_673 ,
F_149 ( V_471 . V_474 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = V_7 -> V_326 -> V_1119 ( & V_7 -> V_18 , V_184 , & V_471 ) ;
if ( ! V_35 ) {
V_17 -> V_674 = V_471 . V_55 ;
V_17 -> V_1117 = true ;
V_17 -> V_1120 = V_1100 ;
}
return V_35 ;
}
static int F_225 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_1121 V_128 ;
static struct V_4 * V_1122 [ V_1123 + 1 ] ;
T_2 V_646 = 0 ;
int V_35 ;
bool V_1124 = false ;
if ( ! V_7 -> V_326 -> V_415 ||
! ( V_7 -> V_18 . V_51 & V_414 ) )
return - V_490 ;
switch ( V_184 -> V_28 -> V_132 ) {
case V_133 :
case V_135 :
V_1124 = true ;
if ( ! V_17 -> V_491 )
return - V_16 ;
break;
case V_137 :
case V_136 :
break;
default:
return - V_490 ;
}
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ! V_30 -> V_5 [ V_473 ] ||
! V_30 -> V_5 [ V_1125 ] )
return - V_16 ;
if ( V_1124 && ! V_30 -> V_5 [ V_1126 ] )
return - V_16 ;
V_128 . V_1127 = F_4 ( V_30 -> V_5 [ V_1125 ] ) ;
if ( ! V_1124 )
goto V_1128;
V_35 = F_142 ( V_30 -> V_5 , & V_128 . V_1129 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_34 ( V_1122 , V_1123 ,
V_30 -> V_5 [ V_1126 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_142 ( V_1122 , & V_128 . V_1130 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1122 [ V_1131 ] )
return - V_16 ;
V_128 . V_1132 =
F_77 ( V_1122 [ V_1131 ] ) ;
if ( V_128 . V_1132 >= V_128 . V_1130 . V_627 )
return - V_16 ;
if ( V_128 . V_1130 . V_626 [ V_128 . V_1132 ] !=
V_128 . V_1127 )
return - V_16 ;
if ( V_1122 [ V_1133 ] ) {
V_128 . V_1134 =
F_77 ( V_1122 [ V_1133 ] ) ;
if ( V_128 . V_1134 >=
V_128 . V_1130 . V_636 )
return - V_16 ;
if ( V_128 . V_1130 . V_635 [ V_128 . V_1134 ] !=
V_128 . V_1127 )
return - V_16 ;
}
V_1128:
V_35 = F_79 ( V_7 , V_30 , & V_128 . V_471 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_128 . V_471 ) )
return - V_16 ;
if ( V_184 -> V_28 -> V_132 == V_133 ||
V_184 -> V_28 -> V_132 == V_135 ||
V_184 -> V_28 -> V_132 == V_137 ) {
V_35 = F_148 ( V_17 -> V_18 ,
& V_128 . V_471 ) ;
if ( V_35 < 0 ) {
return V_35 ;
} else if ( V_35 ) {
V_646 = F_149 ( V_128 . V_471 . V_474 ) ;
V_128 . V_672 = true ;
}
}
V_35 = F_150 ( V_7 , V_17 , V_17 -> V_132 ,
V_128 . V_471 . V_55 ,
V_673 ,
V_646 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_1135 ] )
V_128 . V_1136 = true ;
return F_226 ( V_7 , V_184 , & V_128 ) ;
}
static int F_227 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1137 * V_1138 )
{
struct V_1139 * V_330 = & V_1138 -> V_1140 ;
const struct V_1141 * V_1142 ;
void * V_264 ;
struct V_4 * V_1143 ;
bool V_1144 = false ;
F_44 ( V_17 ) ;
V_264 = F_26 ( V_53 , F_70 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1145 ) ;
if ( ! V_264 )
return - 1 ;
F_228 ( V_34 , V_264 , & V_38 ) ;
if ( F_29 ( V_53 , V_275 , V_7 -> V_1146 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_29 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_59;
if ( F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
V_1143 = F_46 ( V_53 , V_1147 ) ;
if ( ! V_1143 )
goto V_59;
if ( ( ! F_229 ( V_330 -> V_494 ) &&
F_50 ( V_53 , V_1148 , V_532 , V_330 -> V_494 ) ) )
goto V_59;
F_205 () ;
V_1142 = F_206 ( V_330 -> V_1142 ) ;
if ( V_1142 ) {
if ( F_103 ( V_53 , V_1149 , V_1142 -> V_1144 ) )
goto V_1150;
V_1144 = true ;
if ( V_1142 -> V_47 && F_50 ( V_53 , V_1151 ,
V_1142 -> V_47 , V_1142 -> V_129 ) )
goto V_1150;
}
V_1142 = F_206 ( V_330 -> V_628 ) ;
if ( V_1142 ) {
if ( ! V_1144 && F_103 ( V_53 , V_1149 , V_1142 -> V_1144 ) )
goto V_1150;
if ( V_1142 -> V_47 && F_50 ( V_53 , V_1152 ,
V_1142 -> V_47 , V_1142 -> V_129 ) )
goto V_1150;
}
F_207 () ;
if ( V_330 -> V_491 &&
F_54 ( V_53 , V_1153 , V_330 -> V_491 ) )
goto V_59;
if ( F_54 ( V_53 , V_1154 , V_330 -> V_867 ) ||
F_29 ( V_53 , V_1155 , V_330 -> V_674 -> V_58 ) ||
F_29 ( V_53 , V_1156 , V_330 -> V_1157 ) ||
F_29 ( V_53 , V_1158 ,
F_230 ( V_1100 - V_1138 -> V_1159 ) ) )
goto V_59;
switch ( V_7 -> V_18 . V_750 ) {
case V_751 :
if ( F_29 ( V_53 , V_1160 , V_330 -> signal ) )
goto V_59;
break;
case V_1161 :
if ( F_55 ( V_53 , V_1162 , V_330 -> signal ) )
goto V_59;
break;
default:
break;
}
switch ( V_17 -> V_132 ) {
case V_139 :
case V_138 :
if ( V_1138 == V_17 -> V_140 &&
F_29 ( V_53 , V_1163 ,
V_1164 ) )
goto V_59;
break;
case V_137 :
if ( V_1138 == V_17 -> V_140 &&
F_29 ( V_53 , V_1163 ,
V_1165 ) )
goto V_59;
break;
default:
break;
}
F_47 ( V_53 , V_1143 ) ;
return F_65 ( V_53 , V_264 ) ;
V_1150:
F_207 () ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
static int F_231 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1137 * V_1083 ;
struct V_1 * V_17 ;
int V_449 = V_34 -> args [ 2 ] , V_96 = 0 ;
int V_35 ;
V_35 = F_14 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_111 ( V_17 ) ;
F_232 ( & V_7 -> V_1166 ) ;
F_233 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1146 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_96 <= V_449 )
continue;
if ( F_227 ( V_32 , V_34 ,
V_34 -> V_36 -> V_450 , V_451 ,
V_7 , V_17 , V_1083 ) < 0 ) {
V_96 -- ;
break;
}
}
F_234 ( & V_7 -> V_1166 ) ;
F_113 ( V_17 ) ;
V_34 -> args [ 2 ] = V_96 ;
F_22 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_235 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_184 ,
struct V_1167 * V_1168 )
{
void * V_264 ;
struct V_4 * V_1169 ;
V_264 = F_26 ( V_53 , V_49 , V_50 , V_51 ,
V_1170 ) ;
if ( ! V_264 )
return - V_127 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) )
goto V_59;
V_1169 = F_46 ( V_53 , V_1171 ) ;
if ( ! V_1169 )
goto V_59;
if ( F_29 ( V_53 , V_1172 ,
V_1168 -> V_674 -> V_58 ) )
goto V_59;
if ( ( V_1168 -> V_724 & V_1173 ) &&
F_55 ( V_53 , V_1174 , V_1168 -> V_1175 ) )
goto V_59;
if ( ( V_1168 -> V_724 & V_1176 ) &&
F_30 ( V_53 , V_1177 ) )
goto V_59;
if ( ( V_1168 -> V_724 & V_1178 ) &&
F_103 ( V_53 , V_1179 ,
V_1168 -> V_1180 ) )
goto V_59;
if ( ( V_1168 -> V_724 & V_1181 ) &&
F_103 ( V_53 , V_1182 ,
V_1168 -> V_1183 ) )
goto V_59;
if ( ( V_1168 -> V_724 & V_1184 ) &&
F_103 ( V_53 , V_1185 ,
V_1168 -> V_1186 ) )
goto V_59;
if ( ( V_1168 -> V_724 & V_1187 ) &&
F_103 ( V_53 , V_1188 ,
V_1168 -> V_1189 ) )
goto V_59;
if ( ( V_1168 -> V_724 & V_1190 ) &&
F_103 ( V_53 , V_1191 ,
V_1168 -> V_1192 ) )
goto V_59;
F_47 ( V_53 , V_1169 ) ;
return F_65 ( V_53 , V_264 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
static int F_236 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1167 V_1168 ;
struct V_6 * V_184 ;
struct V_1 * V_17 ;
int V_1193 = V_34 -> args [ 2 ] ;
int V_330 ;
V_330 = F_14 ( V_32 , V_34 , & V_184 , & V_17 ) ;
if ( V_330 )
return V_330 ;
if ( ! V_17 -> V_19 ) {
V_330 = - V_16 ;
goto V_813;
}
if ( ! V_184 -> V_326 -> V_1194 ) {
V_330 = - V_490 ;
goto V_813;
}
while ( 1 ) {
struct V_54 * V_55 ;
V_330 = F_237 ( V_184 , V_17 -> V_19 , V_1193 , & V_1168 ) ;
if ( V_330 == - V_593 )
break;
if ( V_330 )
goto V_813;
if ( ! V_1168 . V_674 ) {
V_330 = - V_16 ;
goto V_542;
}
V_55 = F_80 ( & V_184 -> V_18 ,
V_1168 . V_674 -> V_58 ) ;
if ( ! V_55 || V_55 -> V_51 & V_60 ) {
V_1193 ++ ;
continue;
}
if ( F_235 ( V_32 ,
F_70 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_450 , V_451 ,
V_17 -> V_19 , & V_1168 ) < 0 )
goto V_542;
V_1193 ++ ;
}
V_542:
V_34 -> args [ 2 ] = V_1193 ;
V_330 = V_32 -> V_47 ;
V_813:
F_22 ( V_184 ) ;
return V_330 ;
}
static bool F_238 ( V_22 V_1195 )
{
return ! ( V_1195 & ~ ( V_1196 |
V_1197 ) ) ;
}
static int F_239 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_494 , * V_537 , * V_1042 = NULL , * V_1198 = NULL ;
int V_35 , V_535 , V_1043 = 0 , V_1199 = 0 ;
enum V_638 V_639 ;
struct V_84 V_83 ;
bool V_1200 ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_659 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_536 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_473 ] )
return - V_16 ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( V_83 . V_96 >= 0 ) {
if ( V_83 . type != - 1 && V_83 . type != V_589 )
return - V_16 ;
if ( ! V_83 . V_98 . V_83 || ! V_83 . V_98 . V_99 )
return - V_16 ;
if ( ( V_83 . V_98 . V_103 != V_130 ||
V_83 . V_98 . V_99 != V_1201 ) &&
( V_83 . V_98 . V_103 != V_131 ||
V_83 . V_98 . V_99 != V_1202 ) )
return - V_16 ;
if ( V_83 . V_96 > 4 )
return - V_16 ;
} else {
V_83 . V_98 . V_99 = 0 ;
V_83 . V_98 . V_83 = NULL ;
}
if ( V_83 . V_96 >= 0 ) {
int V_144 ;
bool V_1203 = false ;
for ( V_144 = 0 ; V_144 < V_7 -> V_18 . V_313 ; V_144 ++ ) {
if ( V_83 . V_98 . V_103 == V_7 -> V_18 . V_314 [ V_144 ] ) {
V_1203 = true ;
break;
}
}
if ( ! V_1203 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_360 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_55 = F_80 ( & V_7 -> V_18 ,
F_4 ( V_30 -> V_5 [ V_473 ] ) ) ;
if ( ! V_55 || ( V_55 -> V_51 & V_60 ) )
return - V_16 ;
V_537 = F_24 ( V_30 -> V_5 [ V_536 ] ) ;
V_535 = F_25 ( V_30 -> V_5 [ V_536 ] ) ;
if ( V_30 -> V_5 [ V_620 ] ) {
V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
}
V_639 = F_4 ( V_30 -> V_5 [ V_659 ] ) ;
if ( ! F_144 ( V_7 , V_639 , V_642 ) )
return - V_16 ;
if ( V_639 == V_644 &&
! V_30 -> V_5 [ V_1204 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1204 ] ) {
if ( V_639 != V_644 )
return - V_16 ;
V_1198 = F_24 ( V_30 -> V_5 [ V_1204 ] ) ;
V_1199 = F_25 ( V_30 -> V_5 [ V_1204 ] ) ;
if ( V_1199 < 4 )
return - V_16 ;
}
V_1200 = ! ! V_30 -> V_5 [ V_1205 ] ;
if ( V_1200 )
return 0 ;
F_111 ( V_184 -> V_28 ) ;
V_35 = F_240 ( V_7 , V_184 , V_55 , V_639 , V_494 ,
V_537 , V_535 , V_1042 , V_1043 ,
V_83 . V_98 . V_83 , V_83 . V_98 . V_99 , V_83 . V_96 ,
V_1198 , V_1199 ) ;
F_113 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_147 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1206 * V_1207 ,
int V_1208 )
{
memset ( V_1207 , 0 , sizeof( * V_1207 ) ) ;
V_1207 -> V_1209 = V_30 -> V_5 [ V_1210 ] ;
if ( V_30 -> V_5 [ V_318 ] ) {
T_3 V_1211 ;
V_1211 = F_77 (
V_30 -> V_5 [ V_318 ] ) ;
V_1207 -> V_1212 = F_241 ( V_1211 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_317 ) &&
V_1211 != V_1213 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1214 ] )
V_1207 -> V_1215 = true ;
} else
V_1207 -> V_1212 = F_241 ( V_1213 ) ;
if ( V_30 -> V_5 [ V_1216 ] ) {
void * V_129 ;
int V_47 , V_144 ;
V_129 = F_24 ( V_30 -> V_5 [ V_1216 ] ) ;
V_47 = F_25 ( V_30 -> V_5 [ V_1216 ] ) ;
V_1207 -> V_1217 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1207 -> V_1217 > V_1208 )
return - V_16 ;
memcpy ( V_1207 -> V_1218 , V_129 , V_47 ) ;
for ( V_144 = 0 ; V_144 < V_1207 -> V_1217 ; V_144 ++ )
if ( ! F_242 (
& V_7 -> V_18 ,
V_1207 -> V_1218 [ V_144 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1219 ] ) {
V_1207 -> V_1220 =
F_4 ( V_30 -> V_5 [ V_1219 ] ) ;
if ( ! F_242 ( & V_7 -> V_18 ,
V_1207 -> V_1220 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1221 ] ) {
V_1207 -> V_1195 =
F_4 ( V_30 -> V_5 [ V_1221 ] ) ;
if ( ! F_238 ( V_1207 -> V_1195 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1222 ] ) {
void * V_129 ;
int V_47 ;
V_129 = F_24 ( V_30 -> V_5 [ V_1222 ] ) ;
V_47 = F_25 ( V_30 -> V_5 [ V_1222 ] ) ;
V_1207 -> V_1223 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1207 -> V_1223 > V_1224 )
return - V_16 ;
memcpy ( V_1207 -> V_1225 , V_129 , V_47 ) ;
}
return 0 ;
}
static int F_243 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1226 V_1227 = {} ;
const T_2 * V_494 , * V_537 ;
int V_35 , V_535 = 0 ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_495 ] ||
! V_30 -> V_5 [ V_536 ] ||
! V_30 -> V_5 [ V_473 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_362 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_55 = F_80 ( & V_7 -> V_18 ,
F_4 ( V_30 -> V_5 [ V_473 ] ) ) ;
if ( ! V_55 || ( V_55 -> V_51 & V_60 ) )
return - V_16 ;
V_537 = F_24 ( V_30 -> V_5 [ V_536 ] ) ;
V_535 = F_25 ( V_30 -> V_5 [ V_536 ] ) ;
if ( V_30 -> V_5 [ V_620 ] ) {
V_1227 . V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
V_1227 . V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
}
if ( V_30 -> V_5 [ V_1228 ] ) {
enum V_1229 V_1230 =
F_4 ( V_30 -> V_5 [ V_1228 ] ) ;
if ( V_1230 == V_1231 )
V_1227 . V_1232 = true ;
else if ( V_1230 != V_1233 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1234 ] )
V_1227 . V_1235 = F_24 ( V_30 -> V_5 [ V_1234 ] ) ;
if ( F_200 ( V_30 -> V_5 [ V_1236 ] ) )
V_1227 . V_51 |= V_1237 ;
if ( V_30 -> V_5 [ V_435 ] )
memcpy ( & V_1227 . V_1238 ,
F_24 ( V_30 -> V_5 [ V_435 ] ) ,
sizeof( V_1227 . V_1238 ) ) ;
if ( V_30 -> V_5 [ V_860 ] ) {
if ( ! V_30 -> V_5 [ V_435 ] )
return - V_16 ;
memcpy ( & V_1227 . V_832 ,
F_24 ( V_30 -> V_5 [ V_860 ] ) ,
sizeof( V_1227 . V_832 ) ) ;
}
if ( F_200 ( V_30 -> V_5 [ V_1239 ] ) )
V_1227 . V_51 |= V_1240 ;
if ( V_30 -> V_5 [ V_444 ] )
memcpy ( & V_1227 . V_1241 ,
F_24 ( V_30 -> V_5 [ V_444 ] ) ,
sizeof( V_1227 . V_1241 ) ) ;
if ( V_30 -> V_5 [ V_861 ] ) {
if ( ! V_30 -> V_5 [ V_444 ] )
return - V_16 ;
memcpy ( & V_1227 . V_833 ,
F_24 ( V_30 -> V_5 [ V_861 ] ) ,
sizeof( V_1227 . V_833 ) ) ;
}
V_35 = F_147 ( V_7 , V_30 , & V_1227 . V_661 , 1 ) ;
if ( ! V_35 ) {
F_111 ( V_184 -> V_28 ) ;
V_35 = F_244 ( V_7 , V_184 , V_55 , V_494 ,
V_537 , V_535 , & V_1227 ) ;
F_113 ( V_184 -> V_28 ) ;
}
return V_35 ;
}
static int F_245 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
const T_2 * V_1042 = NULL , * V_494 ;
int V_1043 = 0 , V_35 ;
T_3 V_1242 ;
bool V_1200 ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1243 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_364 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_1242 = F_77 ( V_30 -> V_5 [ V_1243 ] ) ;
if ( V_1242 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_620 ] ) {
V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
}
V_1200 = ! ! V_30 -> V_5 [ V_1205 ] ;
F_111 ( V_184 -> V_28 ) ;
V_35 = F_246 ( V_7 , V_184 , V_494 , V_1042 , V_1043 , V_1242 ,
V_1200 ) ;
F_113 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_247 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
const T_2 * V_1042 = NULL , * V_494 ;
int V_1043 = 0 , V_35 ;
T_3 V_1242 ;
bool V_1200 ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1243 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_366 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_1242 = F_77 ( V_30 -> V_5 [ V_1243 ] ) ;
if ( V_1242 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_620 ] ) {
V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
}
V_1200 = ! ! V_30 -> V_5 [ V_1205 ] ;
F_111 ( V_184 -> V_28 ) ;
V_35 = F_248 ( V_7 , V_184 , V_494 , V_1042 , V_1043 , V_1242 ,
V_1200 ) ;
F_113 ( V_184 -> V_28 ) ;
return V_35 ;
}
static bool
F_249 ( struct V_6 * V_7 ,
int V_1244 [ V_337 ] ,
int V_1245 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_271 , V_144 ;
for ( V_271 = 0 ; V_271 < V_337 ; V_271 ++ ) {
struct V_220 * V_221 ;
V_221 = V_18 -> V_338 [ V_271 ] ;
if ( ! V_221 )
continue;
for ( V_144 = 0 ; V_144 < V_221 -> V_242 ; V_144 ++ ) {
if ( V_221 -> V_243 [ V_144 ] . V_245 == V_1245 ) {
V_1244 [ V_271 ] = V_144 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_250 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1246 V_1247 ;
struct V_18 * V_18 ;
struct V_121 * V_1248 = NULL ;
int V_35 ;
memset ( & V_1247 , 0 , sizeof( V_1247 ) ) ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_536 ] ||
! F_25 ( V_30 -> V_5 [ V_536 ] ) )
return - V_16 ;
V_1247 . V_491 = 100 ;
if ( V_30 -> V_5 [ V_648 ] ) {
V_1247 . V_491 =
F_4 ( V_30 -> V_5 [ V_648 ] ) ;
if ( V_1247 . V_491 < 1 || V_1247 . V_491 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_368 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_137 )
return - V_490 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_495 ] ) {
V_1247 . V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( ! F_117 ( V_1247 . V_494 ) )
return - V_16 ;
}
V_1247 . V_537 = F_24 ( V_30 -> V_5 [ V_536 ] ) ;
V_1247 . V_535 = F_25 ( V_30 -> V_5 [ V_536 ] ) ;
if ( V_30 -> V_5 [ V_620 ] ) {
V_1247 . V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
V_1247 . V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
}
V_35 = F_79 ( V_7 , V_30 , & V_1247 . V_471 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_1247 . V_471 ) )
return - V_16 ;
switch ( V_1247 . V_471 . V_474 ) {
case V_488 :
case V_489 :
case V_475 :
break;
case V_526 :
case V_527 :
if ( V_7 -> V_18 . V_272 & V_1249 )
break;
default:
return - V_16 ;
}
V_1247 . V_1250 = ! ! V_30 -> V_5 [ V_1251 ] ;
V_1247 . V_657 = ! ! V_30 -> V_5 [ V_658 ] ;
if ( V_30 -> V_5 [ V_924 ] ) {
T_2 * V_1090 =
F_24 ( V_30 -> V_5 [ V_924 ] ) ;
int V_1252 =
F_25 ( V_30 -> V_5 [ V_924 ] ) ;
struct V_220 * V_221 =
V_18 -> V_338 [ V_1247 . V_471 . V_55 -> V_271 ] ;
V_35 = F_214 ( V_221 , V_1090 , V_1252 ,
& V_1247 . V_925 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_435 ] )
memcpy ( & V_1247 . V_1238 ,
F_24 ( V_30 -> V_5 [ V_435 ] ) ,
sizeof( V_1247 . V_1238 ) ) ;
if ( V_30 -> V_5 [ V_860 ] ) {
if ( ! V_30 -> V_5 [ V_435 ] )
return - V_16 ;
memcpy ( & V_1247 . V_832 ,
F_24 ( V_30 -> V_5 [ V_860 ] ) ,
sizeof( V_1247 . V_832 ) ) ;
}
if ( V_30 -> V_5 [ V_1253 ] &&
! F_249 ( V_7 , V_1247 . V_1244 ,
F_4 ( V_30 -> V_5 [ V_1253 ] ) ) )
return - V_16 ;
if ( V_1247 . V_657 && V_30 -> V_5 [ V_1254 ] ) {
bool V_123 = false ;
V_1248 = F_38 ( V_7 ,
V_30 -> V_5 [ V_1254 ] ,
& V_123 ) ;
if ( F_18 ( V_1248 ) )
return F_19 ( V_1248 ) ;
if ( ( V_1247 . V_471 . V_474 != V_475 ) &&
V_123 ) {
F_42 ( V_1248 ) ;
return - V_16 ;
}
}
V_1247 . V_1209 =
F_200 ( V_30 -> V_5 [ V_1210 ] ) ;
V_1247 . V_1255 =
F_200 ( V_30 -> V_5 [ V_1256 ] ) ;
V_35 = F_251 ( V_7 , V_184 , & V_1247 , V_1248 ) ;
if ( V_35 )
F_42 ( V_1248 ) ;
return V_35 ;
}
static int F_252 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_1257 )
return - V_490 ;
if ( V_184 -> V_28 -> V_132 != V_137 )
return - V_490 ;
return F_253 ( V_7 , V_184 , false ) ;
}
static int F_254 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
int V_1244 [ V_337 ] ;
V_22 V_1258 ;
int V_35 ;
if ( V_184 -> V_28 -> V_132 != V_137 &&
V_184 -> V_28 -> V_132 != V_136 )
return - V_490 ;
if ( ! V_7 -> V_326 -> V_408 )
return - V_490 ;
memset ( V_1244 , 0 , sizeof( V_1244 ) ) ;
if ( ! V_30 -> V_5 [ V_1253 ] )
return - V_16 ;
V_1258 = F_4 ( V_30 -> V_5 [ V_1253 ] ) ;
if ( ! F_249 ( V_7 , V_1244 , V_1258 ) )
return - V_16 ;
V_35 = V_7 -> V_326 -> V_408 ( & V_7 -> V_18 , V_184 , V_1244 ) ;
return V_35 ;
}
static int F_255 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_93 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_326 -> V_417 )
return - V_490 ;
if ( F_18 ( V_17 ) ) {
V_35 = F_19 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1259 ] )
return - V_16 ;
V_7 -> V_1260 = V_30 ;
V_35 = F_256 ( V_7 , V_17 ,
F_24 ( V_30 -> V_5 [ V_1259 ] ) ,
F_25 ( V_30 -> V_5 [ V_1259 ] ) ) ;
V_7 -> V_1260 = NULL ;
return V_35 ;
}
static int F_257 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1261 ;
void * V_129 = NULL ;
int V_1262 = 0 ;
F_15 () ;
if ( V_34 -> args [ 0 ] ) {
V_1261 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_16 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_813;
V_7 = F_8 ( F_17 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_18 ( V_7 ) ) {
V_35 = F_19 ( V_7 ) ;
goto V_813;
}
V_1261 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1259 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1259 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_129 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1262 = F_25 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1261 ) ;
if ( ! V_7 ) {
V_35 = - V_593 ;
goto V_813;
}
if ( ! V_7 -> V_326 -> V_1263 ) {
V_35 = - V_490 ;
goto V_813;
}
while ( 1 ) {
void * V_264 = F_26 ( V_32 , F_70 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_450 , V_451 ,
V_1264 ) ;
struct V_4 * V_1265 ;
if ( ! V_264 )
break;
if ( F_29 ( V_32 , V_26 , V_1261 ) ) {
F_66 ( V_32 , V_264 ) ;
break;
}
V_1265 = F_46 ( V_32 , V_1259 ) ;
if ( ! V_1265 ) {
F_66 ( V_32 , V_264 ) ;
break;
}
V_35 = F_258 ( V_7 , V_32 , V_34 , V_129 , V_1262 ) ;
F_47 ( V_32 , V_1265 ) ;
if ( V_35 == - V_82 || V_35 == - V_593 ) {
F_66 ( V_32 , V_264 ) ;
break;
} else if ( V_35 ) {
F_66 ( V_32 , V_264 ) ;
goto V_813;
}
F_65 ( V_32 , V_264 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1261 + 1 ;
V_813:
F_21 () ;
return V_35 ;
}
static struct V_31 *
F_259 ( struct V_6 * V_7 ,
int V_1266 , V_22 V_49 , V_22 V_50 , T_11 V_1267 )
{
struct V_31 * V_32 ;
void * V_264 ;
struct V_4 * V_129 ;
V_32 = F_73 ( V_1266 + 100 , V_1267 ) ;
if ( ! V_32 )
return NULL ;
V_264 = F_26 ( V_32 , V_49 , V_50 , 0 , V_1264 ) ;
if ( ! V_264 ) {
F_260 ( V_32 ) ;
return NULL ;
}
if ( F_29 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_59;
V_129 = F_46 ( V_32 , V_1259 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_264 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_129 ;
return V_32 ;
V_59:
F_260 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_261 ( struct V_18 * V_18 ,
int V_1266 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_58 ( ! V_7 -> V_1260 ) )
return NULL ;
return F_259 ( V_7 , V_1266 ,
V_7 -> V_1260 -> V_454 ,
V_7 -> V_1260 -> V_455 ,
V_126 ) ;
}
int F_262 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_264 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_129 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
if ( F_58 ( ! V_7 -> V_1260 ) ) {
F_260 ( V_32 ) ;
return - V_16 ;
}
F_47 ( V_32 , V_129 ) ;
F_65 ( V_32 , V_264 ) ;
return F_75 ( V_32 , V_7 -> V_1260 ) ;
}
struct V_31 * F_263 ( struct V_18 * V_18 ,
int V_1266 , T_11 V_1267 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
return F_259 ( V_7 , V_1266 , 0 , 0 , V_1267 ) ;
}
void F_264 ( struct V_31 * V_32 , T_11 V_1267 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_264 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_129 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
F_47 ( V_32 , V_129 ) ;
F_65 ( V_32 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1268 , V_1267 ) ;
}
static int F_266 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1269 V_419 ;
struct V_18 * V_18 ;
struct V_121 * V_1248 = NULL ;
int V_35 ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
if ( ! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_536 ] ||
! F_25 ( V_30 -> V_5 [ V_536 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_659 ] ) {
V_419 . V_639 =
F_4 ( V_30 -> V_5 [ V_659 ] ) ;
if ( ! F_144 ( V_7 , V_419 . V_639 ,
V_420 ) )
return - V_16 ;
} else
V_419 . V_639 = V_660 ;
V_419 . V_657 = V_30 -> V_5 [ V_658 ] ;
V_35 = F_147 ( V_7 , V_30 , & V_419 . V_661 ,
V_662 ) ;
if ( V_35 )
return V_35 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
V_18 = & V_7 -> V_18 ;
V_419 . V_1270 = - 1 ;
if ( V_30 -> V_5 [ V_1271 ] &&
( V_18 -> V_51 & V_304 ) ) {
V_419 . V_1270 =
F_77 ( V_30 -> V_5 [ V_1271 ] ) ;
}
if ( V_30 -> V_5 [ V_495 ] )
V_419 . V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_419 . V_537 = F_24 ( V_30 -> V_5 [ V_536 ] ) ;
V_419 . V_535 = F_25 ( V_30 -> V_5 [ V_536 ] ) ;
if ( V_30 -> V_5 [ V_620 ] ) {
V_419 . V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
V_419 . V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
}
if ( V_30 -> V_5 [ V_1228 ] ) {
V_419 . V_1230 = F_4 ( V_30 -> V_5 [ V_1228 ] ) ;
if ( V_419 . V_1230 != V_1231 &&
V_419 . V_1230 != V_1233 )
return - V_16 ;
} else {
V_419 . V_1230 = V_1233 ;
}
if ( V_30 -> V_5 [ V_473 ] ) {
V_419 . V_674 =
F_80 ( V_18 ,
F_4 ( V_30 -> V_5 [ V_473 ] ) ) ;
if ( ! V_419 . V_674 ||
V_419 . V_674 -> V_51 & V_60 )
return - V_16 ;
}
if ( V_419 . V_657 && V_30 -> V_5 [ V_1254 ] ) {
V_1248 = F_38 ( V_7 ,
V_30 -> V_5 [ V_1254 ] , NULL ) ;
if ( F_18 ( V_1248 ) )
return F_19 ( V_1248 ) ;
}
if ( F_200 ( V_30 -> V_5 [ V_1236 ] ) )
V_419 . V_51 |= V_1237 ;
if ( V_30 -> V_5 [ V_435 ] )
memcpy ( & V_419 . V_1238 ,
F_24 ( V_30 -> V_5 [ V_435 ] ) ,
sizeof( V_419 . V_1238 ) ) ;
if ( V_30 -> V_5 [ V_860 ] ) {
if ( ! V_30 -> V_5 [ V_435 ] ) {
F_42 ( V_1248 ) ;
return - V_16 ;
}
memcpy ( & V_419 . V_832 ,
F_24 ( V_30 -> V_5 [ V_860 ] ) ,
sizeof( V_419 . V_832 ) ) ;
}
if ( F_200 ( V_30 -> V_5 [ V_1239 ] ) )
V_419 . V_51 |= V_1240 ;
if ( V_30 -> V_5 [ V_444 ] )
memcpy ( & V_419 . V_1241 ,
F_24 ( V_30 -> V_5 [ V_444 ] ) ,
sizeof( V_419 . V_1241 ) ) ;
if ( V_30 -> V_5 [ V_861 ] ) {
if ( ! V_30 -> V_5 [ V_444 ] ) {
F_42 ( V_1248 ) ;
return - V_16 ;
}
memcpy ( & V_419 . V_833 ,
F_24 ( V_30 -> V_5 [ V_861 ] ) ,
sizeof( V_419 . V_833 ) ) ;
}
F_111 ( V_184 -> V_28 ) ;
V_35 = F_267 ( V_7 , V_184 , & V_419 , V_1248 , NULL ) ;
F_113 ( V_184 -> V_28 ) ;
if ( V_35 )
F_42 ( V_1248 ) ;
return V_35 ;
}
static int F_268 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_3 V_1272 ;
int V_446 ;
if ( ! V_30 -> V_5 [ V_1243 ] )
V_1272 = V_1273 ;
else
V_1272 = F_77 ( V_30 -> V_5 [ V_1243 ] ) ;
if ( V_1272 == 0 )
return - V_16 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
F_111 ( V_184 -> V_28 ) ;
V_446 = F_269 ( V_7 , V_184 , V_1272 , true ) ;
F_113 ( V_184 -> V_28 ) ;
return V_446 ;
}
static int F_270 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
V_22 V_1274 ;
if ( ! V_30 -> V_5 [ V_1275 ] )
return - V_16 ;
V_1274 = F_4 ( V_30 -> V_5 [ V_1275 ] ) ;
V_2 = F_271 ( V_1274 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_69 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_272 ( V_7 , V_2 ) ;
F_273 ( V_2 ) ;
return V_35 ;
}
static int F_274 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
int (* F_275)( struct V_18 * V_18 , struct V_25 * V_184 ,
struct V_1276 * V_1277 ) = NULL ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1276 V_1277 ;
memset ( & V_1277 , 0 , sizeof( struct V_1276 ) ) ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1278 ] )
return - V_16 ;
V_1277 . V_1279 = F_24 ( V_30 -> V_5 [ V_1278 ] ) ;
V_1277 . V_494 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
switch ( V_30 -> V_1280 -> V_52 ) {
case V_1281 :
F_275 = V_7 -> V_326 -> V_372 ;
break;
case V_1282 :
F_275 = V_7 -> V_326 -> V_374 ;
break;
default:
F_58 ( 1 ) ;
break;
}
if ( ! F_275 )
return - V_490 ;
return F_275 ( & V_7 -> V_18 , V_184 , & V_1277 ) ;
}
static int F_276 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_490 ;
if ( ! V_7 -> V_326 -> V_376 )
return - V_490 ;
return F_277 ( V_7 , V_184 ) ;
}
static int F_278 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 V_1283 , V_1284 ;
T_3 V_1285 ;
T_2 * V_1286 ;
if ( ! ( V_7 -> V_18 . V_51 & V_306 ) ||
! V_7 -> V_326 -> V_393 )
return - V_490 ;
if ( ! V_30 -> V_5 [ V_1287 ] ||
! V_30 -> V_5 [ V_1288 ] ||
! V_30 -> V_5 [ V_1289 ] ||
! V_30 -> V_5 [ V_620 ] ||
! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
V_1286 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_1283 = F_35 ( V_30 -> V_5 [ V_1287 ] ) ;
V_1285 = F_77 ( V_30 -> V_5 [ V_1288 ] ) ;
V_1284 = F_35 ( V_30 -> V_5 [ V_1289 ] ) ;
return F_279 ( V_7 , V_184 , V_1286 , V_1283 ,
V_1284 , V_1285 ,
F_24 ( V_30 -> V_5 [ V_620 ] ) ,
F_25 ( V_30 -> V_5 [ V_620 ] ) ) ;
}
static int F_280 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
enum V_1290 V_1291 ;
T_2 * V_1286 ;
if ( ! ( V_7 -> V_18 . V_51 & V_306 ) ||
! V_7 -> V_326 -> V_395 )
return - V_490 ;
if ( ! V_30 -> V_5 [ V_1292 ] ||
! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
V_1291 = F_35 ( V_30 -> V_5 [ V_1292 ] ) ;
V_1286 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
return F_281 ( V_7 , V_184 , V_1286 , V_1291 ) ;
}
static int F_282 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
struct V_470 V_471 ;
struct V_31 * V_53 ;
void * V_264 ;
T_1 V_584 ;
V_22 V_1293 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_473 ] ||
! V_30 -> V_5 [ V_1294 ] )
return - V_16 ;
V_1293 = F_4 ( V_30 -> V_5 [ V_1294 ] ) ;
if ( ! V_7 -> V_326 -> V_379 ||
! ( V_7 -> V_18 . V_51 & V_378 ) )
return - V_490 ;
if ( V_1293 < V_1295 ||
V_1293 > V_7 -> V_18 . V_424 )
return - V_16 ;
V_35 = F_79 ( V_7 , V_30 , & V_471 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1296 ) ;
if ( ! V_264 ) {
V_35 = - V_82 ;
goto V_594;
}
V_35 = F_283 ( V_7 , V_17 , V_471 . V_55 ,
V_1293 , & V_584 ) ;
if ( V_35 )
goto V_594;
if ( F_103 ( V_53 , V_1297 , V_584 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_594:
F_74 ( V_53 ) ;
return V_35 ;
}
static int F_284 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
T_1 V_584 ;
if ( ! V_30 -> V_5 [ V_1297 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1298 )
return - V_490 ;
V_584 = F_5 ( V_30 -> V_5 [ V_1297 ] ) ;
return F_285 ( V_7 , V_17 , V_584 ) ;
}
static V_22 F_286 ( struct V_220 * V_221 ,
T_2 * V_1090 , T_2 V_1299 )
{
T_2 V_144 ;
V_22 V_682 = 0 ;
for ( V_144 = 0 ; V_144 < V_1299 ; V_144 ++ ) {
int V_225 = ( V_1090 [ V_144 ] & 0x7f ) * 5 ;
int V_1300 ;
for ( V_1300 = 0 ; V_1300 < V_221 -> V_242 ; V_1300 ++ ) {
struct V_224 * V_1301 =
& V_221 -> V_243 [ V_1300 ] ;
if ( V_225 == V_1301 -> V_245 ) {
V_682 |= 1 << V_1300 ;
break;
}
}
if ( V_1300 == V_221 -> V_242 )
return 0 ;
}
return V_682 ;
}
static bool F_287 ( struct V_220 * V_221 ,
T_2 * V_1090 , T_2 V_1299 ,
T_2 V_229 [ V_1302 ] )
{
T_2 V_144 ;
memset ( V_229 , 0 , V_1302 ) ;
for ( V_144 = 0 ; V_144 < V_1299 ; V_144 ++ ) {
int V_1300 , V_1303 ;
V_1300 = V_1090 [ V_144 ] / 8 ;
V_1303 = F_149 ( V_1090 [ V_144 ] % 8 ) ;
if ( ( V_1300 < 0 ) || ( V_1300 >= V_1302 ) )
return false ;
if ( V_221 -> V_226 . V_229 . V_1304 [ V_1300 ] & V_1303 )
V_229 [ V_1300 ] |= V_1303 ;
else
return false ;
}
return true ;
}
static int F_288 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_86 [ V_1305 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1306 V_682 ;
int V_125 , V_144 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_4 * V_1307 ;
struct V_220 * V_221 ;
if ( V_30 -> V_5 [ V_1308 ] == NULL )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_381 )
return - V_490 ;
memset ( & V_682 , 0 , sizeof( V_682 ) ) ;
for ( V_144 = 0 ; V_144 < V_337 ; V_144 ++ ) {
V_221 = V_7 -> V_18 . V_338 [ V_144 ] ;
V_682 . V_1309 [ V_144 ] . V_1310 =
V_221 ? ( 1 << V_221 -> V_242 ) - 1 : 0 ;
if ( V_221 )
memcpy ( V_682 . V_1309 [ V_144 ] . V_229 ,
V_221 -> V_226 . V_229 . V_1304 ,
sizeof( V_682 . V_1309 [ V_144 ] . V_229 ) ) ;
else
memset ( V_682 . V_1309 [ V_144 ] . V_229 , 0 ,
sizeof( V_682 . V_1309 [ V_144 ] . V_229 ) ) ;
}
F_112 ( V_1311 > V_1302 * 8 ) ;
F_40 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_270 V_271 = F_213 ( V_1307 ) ;
if ( V_271 < 0 || V_271 >= V_337 )
return - V_16 ;
V_221 = V_7 -> V_18 . V_338 [ V_271 ] ;
if ( V_221 == NULL )
return - V_16 ;
F_95 ( V_86 , V_1305 , F_24 ( V_1307 ) ,
F_25 ( V_1307 ) , V_1312 ) ;
if ( V_86 [ V_1313 ] ) {
V_682 . V_1309 [ V_271 ] . V_1310 = F_286 (
V_221 ,
F_24 ( V_86 [ V_1313 ] ) ,
F_25 ( V_86 [ V_1313 ] ) ) ;
if ( ( V_682 . V_1309 [ V_271 ] . V_1310 == 0 ) &&
F_25 ( V_86 [ V_1313 ] ) )
return - V_16 ;
}
if ( V_86 [ V_1314 ] ) {
if ( ! F_287 (
V_221 ,
F_24 ( V_86 [ V_1314 ] ) ,
F_25 ( V_86 [ V_1314 ] ) ,
V_682 . V_1309 [ V_271 ] . V_229 ) )
return - V_16 ;
}
if ( V_682 . V_1309 [ V_271 ] . V_1310 == 0 ) {
if ( ! V_7 -> V_18 . V_338 [ V_271 ] -> V_226 . V_227 )
return - V_16 ;
for ( V_144 = 0 ; V_144 < V_1302 ; V_144 ++ )
if ( V_682 . V_1309 [ V_271 ] . V_229 [ V_144 ] )
break;
if ( V_144 == V_1302 )
return - V_16 ;
}
}
return F_289 ( V_7 , V_184 , NULL , & V_682 ) ;
}
static int F_290 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
T_3 V_1315 = V_259 | V_1316 ;
if ( ! V_30 -> V_5 [ V_1317 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_258 ] )
V_1315 = F_77 ( V_30 -> V_5 [ V_258 ] ) ;
switch ( V_17 -> V_132 ) {
case V_138 :
case V_137 :
case V_139 :
case V_133 :
case V_134 :
case V_136 :
case V_135 :
case V_569 :
break;
default:
return - V_490 ;
}
if ( ! V_7 -> V_326 -> V_383 )
return - V_490 ;
return F_291 ( V_17 , V_30 -> V_454 , V_1315 ,
F_24 ( V_30 -> V_5 [ V_1317 ] ) ,
F_25 ( V_30 -> V_5 [ V_1317 ] ) ) ;
}
static int F_292 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
struct V_470 V_471 ;
int V_35 ;
void * V_264 = NULL ;
T_1 V_584 ;
struct V_31 * V_53 = NULL ;
unsigned int V_1318 = 0 ;
bool V_1319 , V_1097 , V_1320 ;
V_1320 = V_30 -> V_5 [ V_1321 ] ;
if ( ! V_30 -> V_5 [ V_1322 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_383 )
return - V_490 ;
switch ( V_17 -> V_132 ) {
case V_569 :
if ( ! V_30 -> V_5 [ V_473 ] )
return - V_16 ;
case V_138 :
case V_137 :
case V_139 :
case V_133 :
case V_134 :
case V_136 :
case V_135 :
break;
default:
return - V_490 ;
}
if ( V_30 -> V_5 [ V_1294 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_425 ) )
return - V_16 ;
V_1318 = F_4 ( V_30 -> V_5 [ V_1294 ] ) ;
if ( V_1318 < V_1295 ||
V_1318 > V_7 -> V_18 . V_424 )
return - V_16 ;
}
V_1319 = V_30 -> V_5 [ V_426 ] ;
if ( V_1319 && ! ( V_7 -> V_18 . V_51 & V_425 ) )
return - V_16 ;
V_1097 = F_200 ( V_30 -> V_5 [ V_1098 ] ) ;
V_471 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_473 ] ) {
V_35 = F_79 ( V_7 , V_30 , & V_471 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_471 . V_55 && V_1319 )
return - V_16 ;
if ( ! V_1320 ) {
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1323 ) ;
if ( ! V_264 ) {
V_35 = - V_82 ;
goto V_594;
}
}
V_35 = F_293 ( V_7 , V_17 , V_471 . V_55 , V_1319 , V_1318 ,
F_24 ( V_30 -> V_5 [ V_1322 ] ) ,
F_25 ( V_30 -> V_5 [ V_1322 ] ) ,
V_1097 , V_1320 , & V_584 ) ;
if ( V_35 )
goto V_594;
if ( V_53 ) {
if ( F_103 ( V_53 , V_1297 , V_584 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
}
return 0 ;
V_59:
V_35 = - V_82 ;
V_594:
F_74 ( V_53 ) ;
return V_35 ;
}
static int F_294 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
T_1 V_584 ;
if ( ! V_30 -> V_5 [ V_1297 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_385 )
return - V_490 ;
switch ( V_17 -> V_132 ) {
case V_138 :
case V_137 :
case V_139 :
case V_133 :
case V_134 :
case V_135 :
case V_569 :
break;
default:
return - V_490 ;
}
V_584 = F_5 ( V_30 -> V_5 [ V_1297 ] ) ;
return F_295 ( V_7 , V_17 , V_584 ) ;
}
static int F_296 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
T_2 V_1324 ;
bool V_263 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1325 ] )
return - V_16 ;
V_1324 = F_4 ( V_30 -> V_5 [ V_1325 ] ) ;
if ( V_1324 != V_1326 && V_1324 != V_1327 )
return - V_16 ;
V_17 = V_184 -> V_28 ;
if ( ! V_7 -> V_326 -> V_1328 )
return - V_490 ;
V_263 = ( V_1324 == V_1327 ) ? true : false ;
if ( V_263 == V_17 -> V_1329 )
return 0 ;
V_35 = F_297 ( V_7 , V_184 , V_263 , V_17 -> V_1330 ) ;
if ( ! V_35 )
V_17 -> V_1329 = V_263 ;
return V_35 ;
}
static int F_298 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
enum V_1331 V_1324 ;
struct V_1 * V_17 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_31 * V_53 ;
void * V_264 ;
int V_35 ;
V_17 = V_184 -> V_28 ;
if ( ! V_7 -> V_326 -> V_1328 )
return - V_490 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1332 ) ;
if ( ! V_264 ) {
V_35 = - V_82 ;
goto V_594;
}
if ( V_17 -> V_1329 )
V_1324 = V_1327 ;
else
V_1324 = V_1326 ;
if ( F_29 ( V_53 , V_1325 , V_1324 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_594:
F_74 ( V_53 ) ;
return V_35 ;
}
static int F_299 ( struct V_29 * V_30 ,
V_22 V_225 , V_22 V_1333 , V_22 V_1334 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
if ( V_225 > 100 || V_1334 > V_1335 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1336 )
return - V_490 ;
if ( V_17 -> V_132 != V_138 &&
V_17 -> V_132 != V_139 )
return - V_490 ;
return F_300 ( V_7 , V_184 , V_225 , V_1333 , V_1334 ) ;
}
static int F_301 ( struct V_29 * V_30 ,
T_12 V_1337 , V_22 V_1338 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
if ( V_1337 > 0 )
return - V_16 ;
if ( V_1337 == 0 )
V_1338 = 0 ;
if ( ! V_7 -> V_326 -> V_1339 )
return - V_490 ;
if ( V_17 -> V_132 != V_138 &&
V_17 -> V_132 != V_139 )
return - V_490 ;
return F_302 ( V_7 , V_184 , V_1337 , V_1338 ) ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1340 + 1 ] ;
struct V_4 * V_1341 ;
int V_35 ;
V_1341 = V_30 -> V_5 [ V_1342 ] ;
if ( ! V_1341 )
return - V_16 ;
V_35 = F_34 ( V_5 , V_1340 , V_1341 ,
V_1343 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1344 ] &&
V_5 [ V_1345 ] ) {
T_12 V_1337 = V_1021 ( V_5 [ V_1344 ] ) ;
V_22 V_1338 = F_4 ( V_5 [ V_1345 ] ) ;
return F_301 ( V_30 , V_1337 , V_1338 ) ;
}
if ( V_5 [ V_1346 ] &&
V_5 [ V_1347 ] &&
V_5 [ V_1348 ] ) {
V_22 V_225 = F_4 ( V_5 [ V_1346 ] ) ;
V_22 V_1333 = F_4 ( V_5 [ V_1347 ] ) ;
V_22 V_1334 = F_4 ( V_5 [ V_1348 ] ) ;
return F_299 ( V_30 , V_225 , V_1333 , V_1334 ) ;
}
return - V_16 ;
}
static int F_304 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_955 V_1017 ;
struct V_1023 V_1024 ;
int V_35 ;
memcpy ( & V_1017 , & V_959 , sizeof( V_1017 ) ) ;
memcpy ( & V_1024 , & V_1349 , sizeof( V_1024 ) ) ;
if ( V_30 -> V_5 [ V_961 ] ) {
V_35 = F_197 ( V_30 , & V_1017 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_560 ] ||
! F_25 ( V_30 -> V_5 [ V_560 ] ) )
return - V_16 ;
V_1024 . V_1350 = F_24 ( V_30 -> V_5 [ V_560 ] ) ;
V_1024 . V_958 = F_25 ( V_30 -> V_5 [ V_560 ] ) ;
if ( V_30 -> V_5 [ V_1253 ] &&
! F_249 ( V_7 , V_1024 . V_1244 ,
F_4 ( V_30 -> V_5 [ V_1253 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_648 ] ) {
V_1024 . V_491 =
F_4 ( V_30 -> V_5 [ V_648 ] ) ;
if ( V_1024 . V_491 < 10 ||
V_1024 . V_491 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_649 ] ) {
V_1024 . V_651 =
F_4 ( V_30 -> V_5 [ V_649 ] ) ;
if ( V_1024 . V_651 < 1 || V_1024 . V_651 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1026 ] ) {
V_35 = F_199 ( V_30 , & V_1024 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1024 . V_1046 )
V_1017 . V_977 = false ;
if ( V_30 -> V_5 [ V_473 ] ) {
V_35 = F_79 ( V_7 , V_30 , & V_1024 . V_471 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1024 . V_471 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_924 ] ) {
T_2 * V_1090 = F_24 ( V_30 -> V_5 [ V_924 ] ) ;
int V_1252 =
F_25 ( V_30 -> V_5 [ V_924 ] ) ;
struct V_220 * V_221 ;
if ( ! V_1024 . V_471 . V_55 )
return - V_16 ;
V_221 = V_7 -> V_18 . V_338 [ V_1024 . V_471 . V_55 -> V_271 ] ;
V_35 = F_214 ( V_221 , V_1090 , V_1252 ,
& V_1024 . V_925 ) ;
if ( V_35 )
return V_35 ;
}
return F_305 ( V_7 , V_184 , & V_1024 , & V_1017 ) ;
}
static int F_306 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
return F_307 ( V_7 , V_184 ) ;
}
static int F_308 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1351 * V_172 = V_7 -> V_18 . V_1352 ;
struct V_4 * V_1353 , * V_1354 ;
int V_144 , V_1355 ;
if ( ! V_172 -> V_203 )
return 0 ;
V_1353 = F_46 ( V_53 , V_212 ) ;
if ( ! V_1353 )
return - V_82 ;
for ( V_144 = 0 ; V_144 < V_172 -> V_203 ; V_144 ++ ) {
V_1354 = F_46 ( V_53 , V_144 + 1 ) ;
if ( ! V_1354 )
return - V_82 ;
V_1355 = V_172 -> V_1356 [ V_144 ] . V_1357 ;
if ( F_50 ( V_53 , V_1358 , F_309 ( V_1355 , 8 ) ,
V_172 -> V_1356 [ V_144 ] . V_682 ) ||
F_50 ( V_53 , V_1359 , V_1355 ,
V_172 -> V_1356 [ V_144 ] . V_1360 ) ||
F_29 ( V_53 , V_1361 ,
V_172 -> V_1356 [ V_144 ] . V_1362 ) )
return - V_82 ;
F_47 ( V_53 , V_1354 ) ;
}
F_47 ( V_53 , V_1353 ) ;
return 0 ;
}
static int F_310 ( struct V_31 * V_53 ,
struct V_1363 * V_171 )
{
struct V_4 * V_173 ;
if ( ! V_171 )
return 0 ;
V_173 = F_46 ( V_53 , V_174 ) ;
if ( ! V_173 )
return - V_82 ;
if ( F_311 ( V_53 , V_1364 , V_171 -> V_1365 ) ||
F_311 ( V_53 , V_1366 , V_171 -> V_883 ) ||
F_50 ( V_53 , V_1367 , V_532 , V_171 -> V_1368 ) ||
F_54 ( V_53 , V_1369 , V_171 -> V_1370 ) ||
F_54 ( V_53 , V_1371 , V_171 -> V_1372 ) ||
F_50 ( V_53 , V_175 ,
V_171 -> V_1373 , V_171 -> V_1374 ) ||
F_29 ( V_53 , V_180 ,
V_171 -> V_1375 ) ||
F_50 ( V_53 , V_182 ,
V_171 -> V_1376 , V_171 -> V_1377 ) ||
F_50 ( V_53 , V_1378 ,
F_309 ( V_171 -> V_1376 , 8 ) , V_171 -> V_1379 ) )
return - V_82 ;
if ( V_171 -> V_1380 . V_47 &&
F_50 ( V_53 , V_177 ,
sizeof( V_171 -> V_1380 ) , & V_171 -> V_1380 ) )
return - V_82 ;
if ( V_171 -> V_1381 . V_47 &&
F_50 ( V_53 , V_179 ,
sizeof( V_171 -> V_1381 ) + V_171 -> V_1382 ,
& V_171 -> V_1381 ) )
return - V_82 ;
F_47 ( V_53 , V_173 ) ;
return 0 ;
}
static int F_312 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_31 * V_53 ;
void * V_264 ;
V_22 V_1383 = V_543 ;
if ( ! V_7 -> V_18 . V_172 )
return - V_490 ;
if ( V_7 -> V_18 . V_1352 && V_7 -> V_18 . V_1352 -> V_171 ) {
V_1383 += V_7 -> V_18 . V_1352 -> V_171 -> V_1382 +
V_7 -> V_18 . V_1352 -> V_171 -> V_1373 +
V_7 -> V_18 . V_1352 -> V_171 -> V_1376 +
V_7 -> V_18 . V_1352 -> V_171 -> V_1376 / 8 ;
}
V_53 = F_73 ( V_1383 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1384 ) ;
if ( ! V_264 )
goto V_59;
if ( V_7 -> V_18 . V_1352 ) {
struct V_4 * V_185 ;
V_185 = F_46 ( V_53 , V_1385 ) ;
if ( ! V_185 )
goto V_59;
if ( ( V_7 -> V_18 . V_1352 -> V_1386 &&
F_30 ( V_53 , V_188 ) ) ||
( V_7 -> V_18 . V_1352 -> V_421 &&
F_30 ( V_53 , V_190 ) ) ||
( V_7 -> V_18 . V_1352 -> V_1387 &&
F_30 ( V_53 , V_192 ) ) ||
( V_7 -> V_18 . V_1352 -> V_1388 &&
F_30 ( V_53 , V_196 ) ) ||
( V_7 -> V_18 . V_1352 -> V_1389 &&
F_30 ( V_53 , V_198 ) ) ||
( V_7 -> V_18 . V_1352 -> V_1390 &&
F_30 ( V_53 , V_200 ) ) ||
( V_7 -> V_18 . V_1352 -> V_1391 &&
F_30 ( V_53 , V_202 ) ) )
goto V_59;
if ( F_308 ( V_53 , V_7 ) )
goto V_59;
if ( F_310 ( V_53 ,
V_7 -> V_18 . V_1352 -> V_171 ) )
goto V_59;
F_47 ( V_53 , V_185 ) ;
}
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
F_74 ( V_53 ) ;
return - V_82 ;
}
static int F_313 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1351 * V_1392 )
{
struct V_4 * V_86 [ V_1393 ] ;
struct V_1363 * V_1017 ;
struct V_1394 * V_178 = NULL ;
struct V_1395 * V_50 = NULL ;
V_22 V_1383 ;
V_22 V_1396 , V_1397 , V_1382 = 0 , V_1398 ;
int V_35 , V_1399 ;
if ( ! V_7 -> V_18 . V_172 -> V_171 )
return - V_16 ;
V_35 = F_95 ( V_86 , V_1400 ,
F_24 ( V_45 ) , F_25 ( V_45 ) ,
V_1401 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_86 [ V_1364 ] ||
! V_86 [ V_1366 ] ||
! V_86 [ V_1367 ] ||
! V_86 [ V_1371 ] ||
! V_86 [ V_175 ] ||
! V_86 [ V_180 ] ||
! V_86 [ V_182 ] ||
! V_86 [ V_1378 ] )
return - V_16 ;
V_1396 = F_25 ( V_86 [ V_175 ] ) ;
if ( V_1396 > V_7 -> V_18 . V_172 -> V_171 -> V_176 )
return - V_16 ;
if ( F_4 ( V_86 [ V_180 ] ) >
V_7 -> V_18 . V_172 -> V_171 -> V_181 ||
F_4 ( V_86 [ V_180 ] ) == 0 )
return - V_16 ;
V_1397 = F_25 ( V_86 [ V_182 ] ) ;
if ( V_1397 > V_7 -> V_18 . V_172 -> V_171 -> V_183 )
return - V_16 ;
V_1398 = F_25 ( V_86 [ V_1378 ] ) ;
if ( V_1398 != F_309 ( V_1397 , 8 ) )
return - V_16 ;
if ( V_86 [ V_179 ] ) {
V_22 V_1402 = F_25 ( V_86 [ V_179 ] ) ;
V_178 = F_24 ( V_86 [ V_179 ] ) ;
V_1382 = V_1402 - sizeof( * V_178 ) ;
if ( ! V_178 -> V_47 || V_1382 % V_178 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_172 -> V_171 -> V_178 )
return - V_16 ;
if ( V_178 -> V_47 > V_7 -> V_18 . V_172 -> V_171 -> V_178 -> V_1403 )
return - V_16 ;
if ( V_178 -> V_47 < V_7 -> V_18 . V_172 -> V_171 -> V_178 -> V_1404 )
return - V_16 ;
if ( V_1382 > V_7 -> V_18 . V_172 -> V_171 -> V_178 -> V_1405 )
return - V_16 ;
if ( V_178 -> V_1406 + V_178 -> V_47 > V_1396 )
return - V_16 ;
}
if ( V_86 [ V_177 ] ) {
V_50 = F_24 ( V_86 [ V_177 ] ) ;
if ( ! V_7 -> V_18 . V_172 -> V_171 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1406 > V_1396 )
return - V_16 ;
}
V_1383 = sizeof( * V_1017 ) ;
V_1383 += V_1396 ;
V_1383 += V_1397 + V_1398 ;
V_1383 += V_1382 ;
V_1017 = F_39 ( V_1383 , V_126 ) ;
if ( ! V_1017 )
return - V_127 ;
V_1017 -> V_1365 = F_314 ( V_86 [ V_1364 ] ) ;
V_1017 -> V_883 = F_314 ( V_86 [ V_1366 ] ) ;
memcpy ( V_1017 -> V_1368 , F_24 ( V_86 [ V_1367 ] ) ,
V_532 ) ;
if ( V_86 [ V_1369 ] )
V_1399 = F_77 ( V_86 [ V_1369 ] ) ;
else
V_1399 = 0 ;
#ifdef F_315
V_35 = F_316 ( F_7 ( & V_7 -> V_18 ) , V_1407 , V_1408 ,
V_1409 , & V_1017 -> V_1410 , 1 ) ;
if ( V_35 ) {
F_42 ( V_1017 ) ;
return V_35 ;
}
if ( F_317 ( V_1017 -> V_1410 -> V_44 , V_1399 ) ) {
F_318 ( V_1017 -> V_1410 ) ;
F_42 ( V_1017 ) ;
return - V_1411 ;
}
V_1017 -> V_1370 = F_319 ( V_1017 -> V_1410 -> V_44 ) -> V_1412 ;
#else
if ( ! V_1399 ) {
F_42 ( V_1017 ) ;
return - V_16 ;
}
V_1017 -> V_1370 = V_1399 ;
#endif
V_1017 -> V_1372 = F_77 ( V_86 [ V_1371 ] ) ;
V_1017 -> V_1373 = V_1396 ;
V_1017 -> V_1374 = ( T_2 * ) V_1017 + sizeof( * V_1017 ) + V_1382 ;
memcpy ( ( void * ) V_1017 -> V_1374 ,
F_24 ( V_86 [ V_175 ] ) ,
V_1396 ) ;
if ( V_50 )
V_1017 -> V_1380 = * V_50 ;
V_1017 -> V_1375 = F_4 ( V_86 [ V_180 ] ) ;
V_1017 -> V_1376 = V_1397 ;
V_1017 -> V_1377 = ( T_2 * ) V_1017 + sizeof( * V_1017 ) + V_1382 + V_1396 ;
memcpy ( ( void * ) V_1017 -> V_1377 ,
F_24 ( V_86 [ V_182 ] ) ,
V_1397 ) ;
V_1017 -> V_1379 = ( T_2 * ) V_1017 + sizeof( * V_1017 ) + V_1382 +
V_1396 + V_1397 ;
memcpy ( ( void * ) V_1017 -> V_1379 ,
F_24 ( V_86 [ V_1378 ] ) ,
V_1398 ) ;
if ( V_178 ) {
V_1017 -> V_1382 = V_1382 ;
memcpy ( & V_1017 -> V_1381 , V_178 , sizeof( * V_178 ) + V_1382 ) ;
}
V_1392 -> V_171 = V_1017 ;
return 0 ;
}
static int F_320 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_4 * V_86 [ V_1413 ] ;
struct V_1351 V_1414 = {} ;
struct V_1351 * V_1415 ;
const struct V_1416 * V_172 = V_7 -> V_18 . V_172 ;
int V_35 , V_144 ;
bool V_1417 = V_7 -> V_18 . V_1352 ;
if ( ! V_172 )
return - V_490 ;
if ( ! V_30 -> V_5 [ V_1385 ] ) {
F_321 ( V_7 ) ;
V_7 -> V_18 . V_1352 = NULL ;
goto V_1418;
}
V_35 = F_95 ( V_86 , V_1419 ,
F_24 ( V_30 -> V_5 [ V_1385 ] ) ,
F_25 ( V_30 -> V_5 [ V_1385 ] ) ,
V_1420 ) ;
if ( V_35 )
return V_35 ;
if ( V_86 [ V_188 ] ) {
if ( ! ( V_172 -> V_51 & V_187 ) )
return - V_16 ;
V_1414 . V_1386 = true ;
}
if ( V_86 [ V_190 ] ) {
if ( ! ( V_172 -> V_51 & V_189 ) )
return - V_16 ;
V_1414 . V_421 = true ;
}
if ( V_86 [ V_192 ] ) {
if ( ! ( V_172 -> V_51 & V_191 ) )
return - V_16 ;
V_1414 . V_1387 = true ;
}
if ( V_86 [ V_194 ] )
return - V_16 ;
if ( V_86 [ V_196 ] ) {
if ( ! ( V_172 -> V_51 & V_195 ) )
return - V_16 ;
V_1414 . V_1388 = true ;
}
if ( V_86 [ V_198 ] ) {
if ( ! ( V_172 -> V_51 & V_197 ) )
return - V_16 ;
V_1414 . V_1389 = true ;
}
if ( V_86 [ V_200 ] ) {
if ( ! ( V_172 -> V_51 & V_199 ) )
return - V_16 ;
V_1414 . V_1390 = true ;
}
if ( V_86 [ V_202 ] ) {
if ( ! ( V_172 -> V_51 & V_201 ) )
return - V_16 ;
V_1414 . V_1391 = true ;
}
if ( V_86 [ V_212 ] ) {
struct V_4 * V_205 ;
int V_203 = 0 ;
int V_125 , V_1355 , V_1421 , V_1362 ;
struct V_4 * V_1422 [ V_1423 ] ;
F_40 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_203 ++ ;
if ( V_203 > V_172 -> V_203 )
return - V_16 ;
V_1414 . V_1356 = F_322 ( V_203 ,
sizeof( V_1414 . V_1356 [ 0 ] ) ,
V_126 ) ;
if ( ! V_1414 . V_1356 )
return - V_127 ;
V_1414 . V_203 = V_203 ;
V_144 = 0 ;
F_40 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_95 ( V_1422 , V_1424 , F_24 ( V_205 ) ,
F_25 ( V_205 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1422 [ V_1358 ] ||
! V_1422 [ V_1359 ] )
goto error;
V_1355 = F_25 ( V_1422 [ V_1359 ] ) ;
V_1421 = F_309 ( V_1355 , 8 ) ;
if ( F_25 ( V_1422 [ V_1358 ] ) != V_1421 )
goto error;
if ( V_1355 > V_172 -> V_210 ||
V_1355 < V_172 -> V_208 )
goto error;
if ( ! V_1422 [ V_1361 ] )
V_1362 = 0 ;
else
V_1362 = F_4 (
V_1422 [ V_1361 ] ) ;
if ( V_1362 > V_172 -> V_211 )
goto error;
V_1414 . V_1356 [ V_144 ] . V_1362 = V_1362 ;
V_1414 . V_1356 [ V_144 ] . V_682 =
F_323 ( V_1421 + V_1355 , V_126 ) ;
if ( ! V_1414 . V_1356 [ V_144 ] . V_682 ) {
V_35 = - V_127 ;
goto error;
}
V_1414 . V_1356 [ V_144 ] . V_1360 =
V_1414 . V_1356 [ V_144 ] . V_682 + V_1421 ;
memcpy ( V_1414 . V_1356 [ V_144 ] . V_682 ,
F_24 ( V_1422 [ V_1358 ] ) ,
V_1421 ) ;
V_1414 . V_1356 [ V_144 ] . V_1357 = V_1355 ;
memcpy ( V_1414 . V_1356 [ V_144 ] . V_1360 ,
F_24 ( V_1422 [ V_1359 ] ) ,
V_1355 ) ;
V_144 ++ ;
}
}
if ( V_86 [ V_174 ] ) {
V_35 = F_313 (
V_7 , V_86 [ V_174 ] ,
& V_1414 ) ;
if ( V_35 )
goto error;
}
V_1415 = F_324 ( & V_1414 , sizeof( V_1414 ) , V_126 ) ;
if ( ! V_1415 ) {
V_35 = - V_127 ;
goto error;
}
F_321 ( V_7 ) ;
V_7 -> V_18 . V_1352 = V_1415 ;
V_1418:
if ( V_7 -> V_326 -> V_1418 &&
V_1417 != ! ! V_7 -> V_18 . V_1352 )
F_325 ( V_7 , V_7 -> V_18 . V_1352 ) ;
return 0 ;
error:
for ( V_144 = 0 ; V_144 < V_1414 . V_203 ; V_144 ++ )
F_42 ( V_1414 . V_1356 [ V_144 ] . V_682 ) ;
F_42 ( V_1414 . V_1356 ) ;
if ( V_1414 . V_171 && V_1414 . V_171 -> V_1410 )
F_318 ( V_1414 . V_171 -> V_1410 ) ;
F_42 ( V_1414 . V_171 ) ;
return V_35 ;
}
static int F_326 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1353 , * V_1354 , * V_1425 , * V_1426 ;
int V_144 , V_146 , V_1355 ;
struct V_1427 * V_214 ;
if ( ! V_7 -> V_215 -> V_217 )
return 0 ;
V_1426 = F_46 ( V_53 , V_219 ) ;
if ( ! V_1426 )
return - V_82 ;
for ( V_144 = 0 ; V_144 < V_7 -> V_215 -> V_217 ; V_144 ++ ) {
V_1425 = F_46 ( V_53 , V_144 + 1 ) ;
if ( ! V_1425 )
return - V_82 ;
V_214 = & V_7 -> V_215 -> V_1428 [ V_144 ] ;
if ( F_29 ( V_53 , V_1429 ,
V_214 -> V_1430 ) )
return - V_82 ;
if ( F_29 ( V_53 , V_1431 ,
V_214 -> V_1432 ) )
return - V_82 ;
V_1353 = F_46 ( V_53 ,
V_1433 ) ;
if ( ! V_1353 )
return - V_82 ;
for ( V_146 = 0 ; V_146 < V_214 -> V_203 ; V_146 ++ ) {
V_1354 = F_46 ( V_53 , V_146 + 1 ) ;
if ( ! V_1354 )
return - V_82 ;
V_1355 = V_214 -> V_1356 [ V_146 ] . V_1357 ;
if ( F_50 ( V_53 , V_1358 ,
F_309 ( V_1355 , 8 ) ,
V_214 -> V_1356 [ V_146 ] . V_682 ) ||
F_50 ( V_53 , V_1359 , V_1355 ,
V_214 -> V_1356 [ V_146 ] . V_1360 ) ||
F_29 ( V_53 , V_1361 ,
V_214 -> V_1356 [ V_146 ] . V_1362 ) )
return - V_82 ;
F_47 ( V_53 , V_1354 ) ;
}
F_47 ( V_53 , V_1353 ) ;
F_47 ( V_53 , V_1425 ) ;
}
F_47 ( V_53 , V_1426 ) ;
return 0 ;
}
static int F_327 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_31 * V_53 ;
void * V_264 ;
if ( ! V_7 -> V_18 . V_215 )
return - V_490 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1434 ) ;
if ( ! V_264 )
goto V_59;
if ( V_7 -> V_215 && F_326 ( V_53 , V_7 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
F_74 ( V_53 ) ;
return - V_82 ;
}
void F_328 ( struct V_6 * V_7 )
{
struct V_1435 * V_215 = V_7 -> V_215 ;
int V_144 , V_146 ;
struct V_1427 * V_214 ;
if ( ! V_215 )
return;
for ( V_144 = 0 ; V_144 < V_215 -> V_217 ; V_144 ++ ) {
V_214 = & V_215 -> V_1428 [ V_144 ] ;
for ( V_146 = 0 ; V_146 < V_214 -> V_203 ; V_146 ++ )
F_42 ( V_214 -> V_1356 [ V_146 ] . V_682 ) ;
F_42 ( V_214 -> V_1356 ) ;
}
F_42 ( V_215 -> V_1428 ) ;
F_42 ( V_215 ) ;
V_7 -> V_215 = NULL ;
}
static int F_329 ( struct V_6 * V_7 ,
struct V_4 * V_214 ,
struct V_1427 * V_1436 )
{
int V_35 , V_144 ;
const struct V_1437 * V_215 = V_7 -> V_18 . V_215 ;
struct V_4 * V_86 [ V_1438 ] , * V_205 ;
int V_125 , V_1355 , V_1421 , V_1362 , V_203 = 0 ;
struct V_4 * V_1422 [ V_1423 ] ;
V_35 = F_95 ( V_86 , V_1439 , F_24 ( V_214 ) ,
F_25 ( V_214 ) , V_1440 ) ;
if ( V_35 )
return V_35 ;
if ( V_86 [ V_1429 ] )
V_1436 -> V_1430 =
F_4 ( V_86 [ V_1429 ] ) ;
if ( V_1436 -> V_1430 > V_215 -> V_218 )
return - V_16 ;
if ( V_86 [ V_1431 ] )
V_1436 -> V_1432 =
F_4 ( V_86 [ V_1431 ] ) ;
if ( V_1436 -> V_1432 != V_1441 &&
V_1436 -> V_1432 != V_1442 )
return - V_16 ;
if ( ! V_86 [ V_1433 ] )
return - V_16 ;
F_40 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_203 ++ ;
if ( V_203 > V_215 -> V_203 )
return - V_16 ;
V_1436 -> V_1356 = F_322 ( V_203 , sizeof( V_1436 -> V_1356 [ 0 ] ) ,
V_126 ) ;
if ( ! V_1436 -> V_1356 )
return - V_127 ;
V_1436 -> V_203 = V_203 ;
V_144 = 0 ;
F_40 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
F_95 ( V_1422 , V_1424 , F_24 ( V_205 ) ,
F_25 ( V_205 ) , NULL ) ;
if ( ! V_1422 [ V_1358 ] ||
! V_1422 [ V_1359 ] )
return - V_16 ;
V_1355 = F_25 ( V_1422 [ V_1359 ] ) ;
V_1421 = F_309 ( V_1355 , 8 ) ;
if ( F_25 ( V_1422 [ V_1358 ] ) != V_1421 )
return - V_16 ;
if ( V_1355 > V_215 -> V_210 ||
V_1355 < V_215 -> V_208 )
return - V_16 ;
if ( ! V_1422 [ V_1361 ] )
V_1362 = 0 ;
else
V_1362 = F_4 ( V_1422 [ V_1361 ] ) ;
if ( V_1362 > V_215 -> V_211 )
return - V_16 ;
V_1436 -> V_1356 [ V_144 ] . V_1362 = V_1362 ;
V_1436 -> V_1356 [ V_144 ] . V_682 =
F_323 ( V_1421 + V_1355 , V_126 ) ;
if ( ! V_1436 -> V_1356 [ V_144 ] . V_682 )
return - V_127 ;
V_1436 -> V_1356 [ V_144 ] . V_1360 =
V_1436 -> V_1356 [ V_144 ] . V_682 + V_1421 ;
memcpy ( V_1436 -> V_1356 [ V_144 ] . V_682 ,
F_24 ( V_1422 [ V_1358 ] ) , V_1421 ) ;
V_1436 -> V_1356 [ V_144 ] . V_1357 = V_1355 ;
memcpy ( V_1436 -> V_1356 [ V_144 ] . V_1360 ,
F_24 ( V_1422 [ V_1359 ] ) , V_1355 ) ;
V_144 ++ ;
}
return 0 ;
}
static int F_330 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
const struct V_1437 * V_215 = V_7 -> V_18 . V_215 ;
struct V_1435 V_1443 = {} ;
struct V_1435 * V_1444 ;
int V_35 , V_1445 , V_217 = 0 , V_144 , V_146 ;
struct V_4 * V_214 ;
struct V_1427 * V_1446 ;
if ( ! V_7 -> V_18 . V_215 || ! V_7 -> V_326 -> V_1447 )
return - V_490 ;
if ( ! V_30 -> V_5 [ V_219 ] ) {
F_328 ( V_7 ) ;
V_7 -> V_326 -> V_1447 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_40 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_217 ++ ;
if ( V_217 > V_215 -> V_217 )
return - V_16 ;
V_1443 . V_1428 = F_322 ( V_217 , sizeof( V_1443 . V_1428 [ 0 ] ) ,
V_126 ) ;
if ( ! V_1443 . V_1428 )
return - V_127 ;
V_1443 . V_217 = V_217 ;
V_144 = 0 ;
F_40 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_329 ( V_7 , V_214 ,
& V_1443 . V_1428 [ V_144 ] ) ;
if ( V_35 )
goto error;
V_144 ++ ;
}
V_35 = V_7 -> V_326 -> V_1447 ( & V_7 -> V_18 , & V_1443 ) ;
if ( V_35 )
goto error;
V_1444 = F_324 ( & V_1443 , sizeof( V_1443 ) , V_126 ) ;
if ( ! V_1444 ) {
V_35 = - V_127 ;
goto error;
}
F_328 ( V_7 ) ;
V_7 -> V_215 = V_1444 ;
return 0 ;
error:
for ( V_144 = 0 ; V_144 < V_1443 . V_217 ; V_144 ++ ) {
V_1446 = & V_1443 . V_1428 [ V_144 ] ;
for ( V_146 = 0 ; V_146 < V_1446 -> V_203 ; V_146 ++ )
F_42 ( V_1446 -> V_1356 [ V_146 ] . V_682 ) ;
F_42 ( V_1446 -> V_1356 ) ;
}
F_42 ( V_1443 . V_1428 ) ;
return V_35 ;
}
static int F_331 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_4 * V_86 [ V_1448 ] ;
struct V_1449 V_1450 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1451 ] )
return - V_16 ;
V_35 = F_95 ( V_86 , V_1452 ,
F_24 ( V_30 -> V_5 [ V_1451 ] ) ,
F_25 ( V_30 -> V_5 [ V_1451 ] ) ,
V_1453 ) ;
if ( V_35 )
return V_35 ;
if ( F_25 ( V_86 [ V_1454 ] ) != V_1455 )
return - V_1456 ;
if ( F_25 ( V_86 [ V_1457 ] ) != V_1458 )
return - V_1456 ;
if ( F_25 ( V_86 [ V_1459 ] ) != V_1460 )
return - V_1456 ;
memcpy ( V_1450 . V_1461 , F_24 ( V_86 [ V_1457 ] ) ,
V_1458 ) ;
memcpy ( V_1450 . V_1462 , F_24 ( V_86 [ V_1459 ] ) ,
V_1460 ) ;
memcpy ( V_1450 . V_1463 ,
F_24 ( V_86 [ V_1454 ] ) ,
V_1455 ) ;
F_111 ( V_17 ) ;
if ( ! V_17 -> V_140 ) {
V_35 = - V_1464 ;
goto V_542;
}
if ( ! V_7 -> V_326 -> V_1465 ) {
V_35 = - V_490 ;
goto V_542;
}
V_35 = F_332 ( V_7 , V_184 , & V_1450 ) ;
V_542:
F_113 ( V_17 ) ;
return V_35 ;
}
static int F_333 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
if ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 )
return - V_16 ;
if ( V_17 -> V_1466 )
return - V_492 ;
V_17 -> V_1466 = V_30 -> V_454 ;
return 0 ;
}
static int F_334 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_31 * V_53 ;
void * V_264 ;
const T_2 * V_614 ;
T_1 V_584 ;
int V_35 ;
if ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 )
return - V_490 ;
if ( ! V_30 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_400 )
return - V_490 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1467 ) ;
if ( ! V_264 ) {
V_35 = - V_82 ;
goto V_594;
}
V_614 = F_24 ( V_30 -> V_5 [ V_495 ] ) ;
V_35 = F_335 ( V_7 , V_184 , V_614 , & V_584 ) ;
if ( V_35 )
goto V_594;
if ( F_103 ( V_53 , V_1297 , V_584 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_594:
F_74 ( V_53 ) ;
return V_35 ;
}
static int F_336 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1468 * V_1469 , * V_1470 ;
int V_1471 ;
if ( ! ( V_7 -> V_18 . V_51 & V_404 ) )
return - V_490 ;
V_1470 = F_39 ( sizeof( * V_1470 ) , V_126 ) ;
if ( ! V_1470 )
return - V_127 ;
F_232 ( & V_7 -> V_1472 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1469 -> V_1473 == V_30 -> V_454 ) {
V_1471 = - V_647 ;
goto V_813;
}
}
V_1470 -> V_1473 = V_30 -> V_454 ;
F_337 ( & V_1470 -> V_577 , & V_7 -> V_1474 ) ;
F_234 ( & V_7 -> V_1472 ) ;
return 0 ;
V_813:
F_234 ( & V_7 -> V_1472 ) ;
F_42 ( V_1470 ) ;
return V_1471 ;
}
static int F_338 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_326 -> V_406 )
return - V_490 ;
if ( V_17 -> V_132 != V_569 )
return - V_490 ;
if ( V_17 -> V_1475 )
return 0 ;
V_35 = F_339 ( V_7 , V_17 -> V_132 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_340 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1475 = true ;
V_7 -> V_1476 ++ ;
return 0 ;
}
static int F_341 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
if ( V_17 -> V_132 != V_569 )
return - V_490 ;
if ( ! V_7 -> V_326 -> V_1477 )
return - V_490 ;
F_342 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_343 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_264 ;
struct V_31 * V_53 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , V_30 -> V_454 , V_30 -> V_455 , 0 ,
V_1478 ) ;
if ( ! V_264 )
goto V_59;
if ( F_29 ( V_53 , V_1479 ,
V_1480 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_75 ( V_53 , V_30 ) ;
V_59:
F_260 ( V_53 ) ;
return - V_82 ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1481 V_1482 ;
struct V_25 * V_184 = V_30 -> V_453 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_1483 )
return - V_490 ;
if ( ! V_30 -> V_5 [ V_1484 ] ||
! F_23 ( V_30 -> V_5 [ V_620 ] ) )
return - V_16 ;
memset ( & V_1482 , 0 , sizeof( V_1482 ) ) ;
V_1482 . V_1485 = F_77 ( V_30 -> V_5 [ V_1484 ] ) ;
V_1482 . V_1042 = F_24 ( V_30 -> V_5 [ V_620 ] ) ;
V_1482 . V_1043 = F_25 ( V_30 -> V_5 [ V_620 ] ) ;
return F_345 ( V_7 , V_184 , & V_1482 ) ;
}
static int F_346 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
enum V_1486 V_1211 = V_1487 ;
T_3 V_1293 ;
int V_446 ;
if ( ! V_7 -> V_326 -> V_410 )
return - V_490 ;
if ( F_58 ( ! V_7 -> V_326 -> V_412 ) )
return - V_16 ;
if ( V_7 -> V_1488 )
return - V_492 ;
if ( V_30 -> V_5 [ V_1489 ] )
V_1211 = F_77 ( V_30 -> V_5 [ V_1489 ] ) ;
if ( V_1211 >= V_1490 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1491 ] )
return - V_16 ;
V_1293 =
F_77 ( V_30 -> V_5 [ V_1491 ] ) ;
if ( V_1293 > V_1492 )
return - V_1456 ;
V_446 = F_347 ( V_7 , V_17 , V_1211 , V_1293 ) ;
if ( ! V_446 )
V_7 -> V_1488 = V_30 -> V_454 ;
return V_446 ;
}
static int F_348 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_453 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_412 )
return - V_490 ;
if ( V_7 -> V_1488 ) {
V_7 -> V_1488 = 0 ;
F_349 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_350 ( const struct V_1493 * V_326 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_184 ;
bool V_1494 = V_326 -> V_1495 & V_1496 ;
if ( V_1494 )
F_15 () ;
if ( V_326 -> V_1495 & V_1497 ) {
V_7 = F_13 ( F_93 ( V_30 ) , V_30 ) ;
if ( F_18 ( V_7 ) ) {
if ( V_1494 )
F_21 () ;
return F_19 ( V_7 ) ;
}
V_30 -> V_453 [ 0 ] = V_7 ;
} else if ( V_326 -> V_1495 & V_1498 ||
V_326 -> V_1495 & V_1499 ) {
F_2 () ;
V_17 = F_1 ( F_93 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_18 ( V_17 ) ) {
if ( V_1494 )
F_21 () ;
return F_19 ( V_17 ) ;
}
V_184 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_326 -> V_1495 & V_1498 ) {
if ( ! V_184 ) {
if ( V_1494 )
F_21 () ;
return - V_16 ;
}
V_30 -> V_453 [ 1 ] = V_184 ;
} else {
V_30 -> V_453 [ 1 ] = V_17 ;
}
if ( V_184 ) {
if ( V_326 -> V_1495 & V_1500 &&
! F_90 ( V_184 ) ) {
if ( V_1494 )
F_21 () ;
return - V_504 ;
}
F_217 ( V_184 ) ;
} else if ( V_326 -> V_1495 & V_1500 ) {
if ( ! V_17 -> V_1475 ) {
if ( V_1494 )
F_21 () ;
return - V_504 ;
}
}
V_30 -> V_453 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_351 ( const struct V_1493 * V_326 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_453 [ 1 ] ) {
if ( V_326 -> V_1495 & V_1499 ) {
struct V_1 * V_17 = V_30 -> V_453 [ 1 ] ;
if ( V_17 -> V_19 )
F_12 ( V_17 -> V_19 ) ;
} else {
F_12 ( V_30 -> V_453 [ 1 ] ) ;
}
}
if ( V_326 -> V_1495 & V_1496 )
F_21 () ;
}
void F_352 ( struct V_6 * V_7 )
{
struct V_31 * V_53 ;
struct V_262 V_263 = {} ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_57 ( V_7 , V_53 , 0 , 0 , 0 , & V_263 ) < 0 ) {
F_74 ( V_53 ) ;
return;
}
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1501 , V_126 ) ;
}
static int F_353 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1080 * V_1227 = V_7 -> V_1084 ;
struct V_4 * V_1502 ;
int V_144 ;
if ( F_58 ( ! V_1227 ) )
return 0 ;
V_1502 = F_46 ( V_53 , V_1087 ) ;
if ( ! V_1502 )
goto V_59;
for ( V_144 = 0 ; V_144 < V_1227 -> V_1082 ; V_144 ++ ) {
if ( F_50 ( V_53 , V_144 , V_1227 -> V_1088 [ V_144 ] . V_535 , V_1227 -> V_1088 [ V_144 ] . V_537 ) )
goto V_59;
}
F_47 ( V_53 , V_1502 ) ;
V_1502 = F_46 ( V_53 , V_1086 ) ;
if ( ! V_1502 )
goto V_59;
for ( V_144 = 0 ; V_144 < V_1227 -> V_341 ; V_144 ++ ) {
if ( F_29 ( V_53 , V_144 , V_1227 -> V_342 [ V_144 ] -> V_58 ) )
goto V_59;
}
F_47 ( V_53 , V_1502 ) ;
if ( V_1227 -> V_1042 &&
F_50 ( V_53 , V_620 , V_1227 -> V_1043 , V_1227 -> V_1042 ) )
goto V_59;
if ( V_1227 -> V_51 &&
F_29 ( V_53 , V_1092 , V_1227 -> V_51 ) )
goto V_59;
return 0 ;
V_59:
return - V_82 ;
}
static int F_354 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_264 ;
V_264 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_353 ( V_53 , V_7 ) ;
return F_65 ( V_53 , V_264 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
static int
F_355 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_264 ;
V_264 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
return F_65 ( V_53 , V_264 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
return - V_445 ;
}
void F_216 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_354 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1503 ) < 0 ) {
F_74 ( V_53 ) ;
return;
}
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1504 , V_126 ) ;
}
void F_356 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_354 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1145 ) < 0 ) {
F_74 ( V_53 ) ;
return;
}
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1504 , V_126 ) ;
}
void F_357 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_354 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1505 ) < 0 ) {
F_74 ( V_53 ) ;
return;
}
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1504 , V_126 ) ;
}
void F_358 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_355 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1506 ) < 0 ) {
F_74 ( V_53 ) ;
return;
}
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1504 , V_126 ) ;
}
void F_220 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_355 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_74 ( V_53 ) ;
return;
}
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1504 , V_126 ) ;
}
void F_359 ( struct V_1507 * V_1081 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1508 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_55 ( V_53 , V_1509 , V_1081 -> V_1510 ) )
goto V_59;
if ( V_1081 -> V_1058 [ 0 ] == '0' && V_1081 -> V_1058 [ 1 ] == '0' ) {
if ( F_55 ( V_53 , V_1511 ,
V_1512 ) )
goto V_59;
} else if ( V_1081 -> V_1058 [ 0 ] == '9' && V_1081 -> V_1058 [ 1 ] == '9' ) {
if ( F_55 ( V_53 , V_1511 ,
V_1513 ) )
goto V_59;
} else if ( ( V_1081 -> V_1058 [ 0 ] == '9' && V_1081 -> V_1058 [ 1 ] == '8' ) ||
V_1081 -> V_1514 ) {
if ( F_55 ( V_53 , V_1511 ,
V_1515 ) )
goto V_59;
} else {
if ( F_55 ( V_53 , V_1511 ,
V_1516 ) ||
F_59 ( V_53 , V_951 ,
V_1081 -> V_1058 ) )
goto V_59;
}
if ( V_1081 -> V_14 != V_1517 &&
F_29 ( V_53 , V_26 , V_1081 -> V_14 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_205 () ;
F_360 ( & V_38 , V_53 , 0 ,
V_1518 , V_1519 ) ;
F_207 () ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
static void F_361 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1520 , T_10 V_47 ,
enum V_640 V_52 , T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_1322 , V_47 , V_1520 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_362 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1520 ,
T_10 V_47 , T_11 V_1267 )
{
F_361 ( V_7 , V_19 , V_1520 , V_47 ,
V_642 , V_1267 ) ;
}
void F_363 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1520 ,
T_10 V_47 , T_11 V_1267 )
{
F_361 ( V_7 , V_19 , V_1520 , V_47 ,
V_1522 , V_1267 ) ;
}
void F_364 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1520 ,
T_10 V_47 , T_11 V_1267 )
{
F_361 ( V_7 , V_19 , V_1520 , V_47 ,
V_1523 , V_1267 ) ;
}
void F_365 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1520 ,
T_10 V_47 , T_11 V_1267 )
{
F_361 ( V_7 , V_19 , V_1520 , V_47 ,
V_1524 , V_1267 ) ;
}
void F_366 ( struct V_25 * V_184 , const T_2 * V_1520 ,
T_10 V_47 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1525 * V_1526 = ( void * ) V_1520 ;
V_22 V_52 ;
if ( F_58 ( V_47 < 2 ) )
return;
if ( F_367 ( V_1526 -> V_1527 ) )
V_52 = V_1528 ;
else
V_52 = V_1529 ;
F_368 ( V_184 , V_1520 , V_47 ) ;
F_361 ( V_7 , V_184 , V_1520 , V_47 , V_52 , V_1519 ) ;
}
static void F_369 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_614 , T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_30 ( V_53 , V_1530 ) ||
F_50 ( V_53 , V_495 , V_532 , V_614 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_370 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_614 ,
T_11 V_1267 )
{
F_369 ( V_7 , V_19 , V_642 ,
V_614 , V_1267 ) ;
}
void F_371 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_614 ,
T_11 V_1267 )
{
F_369 ( V_7 , V_19 , V_1522 ,
V_614 , V_1267 ) ;
}
void F_372 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_494 ,
const T_2 * V_1531 , T_10 V_1532 ,
const T_2 * V_1533 , T_10 V_1534 ,
T_3 V_1535 , T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_420 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_494 && F_50 ( V_53 , V_495 , V_532 , V_494 ) ) ||
F_54 ( V_53 , V_1288 , V_1535 ) ||
( V_1531 &&
F_50 ( V_53 , V_1536 , V_1532 , V_1531 ) ) ||
( V_1533 &&
F_50 ( V_53 , V_1537 , V_1534 , V_1533 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_373 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_494 ,
const T_2 * V_1531 , T_10 V_1532 ,
const T_2 * V_1533 , T_10 V_1534 , T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1538 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_494 ) ||
( V_1531 &&
F_50 ( V_53 , V_1536 , V_1532 , V_1531 ) ) ||
( V_1533 &&
F_50 ( V_53 , V_1537 , V_1534 , V_1533 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_374 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1272 ,
const T_2 * V_1042 , T_10 V_1043 , bool V_1539 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_422 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1539 && V_1272 &&
F_54 ( V_53 , V_1243 , V_1272 ) ) ||
( V_1539 &&
F_30 ( V_53 , V_1540 ) ) ||
( V_1042 && F_50 ( V_53 , V_620 , V_1043 , V_1042 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_126 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_375 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_494 ,
T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1541 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_494 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_376 ( struct V_25 * V_184 , const T_2 * V_614 ,
const T_2 * V_1042 , T_2 V_1043 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
if ( F_58 ( V_17 -> V_132 != V_136 ) )
return;
F_377 ( V_184 , V_614 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1542 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_614 ) ||
( V_1043 && V_1042 &&
F_50 ( V_53 , V_620 , V_1043 , V_1042 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_378 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_614 ,
enum V_1543 V_1544 , int V_1545 ,
const T_2 * V_1546 , T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1547 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_614 && F_50 ( V_53 , V_495 , V_532 , V_614 ) ) ||
F_29 ( V_53 , V_118 , V_1544 ) ||
( V_1545 != - 1 &&
F_55 ( V_53 , V_114 , V_1545 ) ) ||
( V_1546 && F_50 ( V_53 , V_113 , 6 , V_1546 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_379 ( struct V_18 * V_18 ,
struct V_54 * V_1548 ,
struct V_54 * V_1549 )
{
struct V_31 * V_53 ;
void * V_264 ;
struct V_4 * V_268 ;
V_53 = F_73 ( V_543 , V_1519 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1550 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , F_380 ( V_18 ) ) )
goto V_59;
V_268 = F_46 ( V_53 , V_1551 ) ;
if ( ! V_268 )
goto V_59;
if ( F_28 ( V_53 , V_1548 , false ) )
goto V_59;
F_47 ( V_53 , V_268 ) ;
V_268 = F_46 ( V_53 , V_1552 ) ;
if ( ! V_268 )
goto V_59;
if ( F_28 ( V_53 , V_1549 , false ) )
goto V_59;
F_47 ( V_53 , V_268 ) ;
F_65 ( V_53 , V_264 ) ;
F_205 () ;
F_360 ( & V_38 , V_53 , 0 ,
V_1518 , V_1519 ) ;
F_207 () ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
static void F_381 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_584 ,
struct V_54 * V_55 ,
unsigned int V_1293 , T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_29 ( V_53 , V_473 , V_55 -> V_58 ) ||
F_29 ( V_53 , V_478 ,
V_481 ) ||
F_103 ( V_53 , V_1297 , V_584 ) )
goto V_59;
if ( V_52 == V_1296 &&
F_29 ( V_53 , V_1294 , V_1293 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_382 ( struct V_1 * V_17 , T_1 V_584 ,
struct V_54 * V_55 ,
unsigned int V_1293 , T_11 V_1267 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_383 ( V_17 , V_584 , V_55 , V_1293 ) ;
F_381 ( V_1296 ,
V_7 , V_17 , V_584 , V_55 ,
V_1293 , V_1267 ) ;
}
void F_384 ( struct V_1 * V_17 , T_1 V_584 ,
struct V_54 * V_55 ,
T_11 V_1267 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_385 ( V_17 , V_584 , V_55 ) ;
F_381 ( V_1553 ,
V_7 , V_17 , V_584 , V_55 , 0 , V_1267 ) ;
}
void F_386 ( struct V_25 * V_184 , const T_2 * V_586 ,
struct V_717 * V_718 , T_11 V_1267 )
{
struct V_18 * V_18 = V_184 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_387 ( V_184 , V_586 , V_718 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
if ( F_160 ( V_53 , 0 , 0 , 0 ,
V_7 , V_184 , V_586 , V_718 ) < 0 ) {
F_74 ( V_53 ) ;
return;
}
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
}
void F_388 ( struct V_25 * V_184 , const T_2 * V_586 , T_11 V_1267 )
{
struct V_18 * V_18 = V_184 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
F_389 ( V_184 , V_586 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1554 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_586 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_390 ( struct V_25 * V_184 , const T_2 * V_586 ,
enum V_1555 V_1272 ,
T_11 V_1267 )
{
struct V_18 * V_18 = V_184 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_1556 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1557 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_586 ) ||
F_29 ( V_53 , V_1558 , V_1272 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
static bool F_391 ( struct V_25 * V_184 , T_2 V_52 ,
const T_2 * V_614 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
V_22 V_1473 = F_392 ( V_17 -> V_1466 ) ;
if ( ! V_1473 )
return false ;
V_53 = F_73 ( 100 , V_1267 ) ;
if ( ! V_53 )
return true ;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return true ;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_614 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_393 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1473 ) ;
return true ;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
return true ;
}
bool F_394 ( struct V_25 * V_184 ,
const T_2 * V_614 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
bool V_446 ;
F_395 ( V_184 , V_614 ) ;
if ( F_58 ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 ) ) {
F_396 ( false ) ;
return false ;
}
V_446 = F_391 ( V_184 , V_1559 ,
V_614 , V_1267 ) ;
F_396 ( V_446 ) ;
return V_446 ;
}
bool F_397 ( struct V_25 * V_184 ,
const T_2 * V_614 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
bool V_446 ;
F_398 ( V_184 , V_614 ) ;
if ( F_58 ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 &&
V_17 -> V_132 != V_134 ) ) {
F_396 ( false ) ;
return false ;
}
V_446 = F_391 ( V_184 ,
V_1560 ,
V_614 , V_1267 ) ;
F_396 ( V_446 ) ;
return V_446 ;
}
int F_399 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1473 ,
int V_1561 , int V_1562 ,
const T_2 * V_1520 , T_10 V_47 , V_22 V_51 , T_11 V_1267 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return - V_127 ;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1323 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return - V_127 ;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_29 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_29 ( V_53 , V_473 , V_1561 ) ||
( V_1562 &&
F_29 ( V_53 , V_1563 , V_1562 ) ) ||
F_50 ( V_53 , V_1322 , V_47 , V_1520 ) ||
( V_51 &&
F_29 ( V_53 , V_1564 , V_51 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
return F_393 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1473 ) ;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
return - V_82 ;
}
void F_400 ( struct V_1 * V_17 , T_1 V_584 ,
const T_2 * V_1520 , T_10 V_47 , bool V_1565 , T_11 V_1267 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_264 ;
F_401 ( V_17 , V_584 , V_1565 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1566 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_29 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_50 ( V_53 , V_1322 , V_47 , V_1520 ) ||
F_103 ( V_53 , V_1297 , V_584 ) ||
( V_1565 && F_30 ( V_53 , V_1567 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_402 ( struct V_25 * V_184 ,
enum V_1568 V_1569 ,
T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_887 ;
void * V_264 ;
F_403 ( V_184 , V_1569 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1570 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) )
goto V_59;
V_887 = F_46 ( V_53 , V_1342 ) ;
if ( ! V_887 )
goto V_59;
if ( F_29 ( V_53 , V_1571 ,
V_1569 ) )
goto V_59;
F_47 ( V_53 , V_887 ) ;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
static void F_404 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_494 ,
const T_2 * V_1463 , T_11 V_1267 )
{
struct V_31 * V_53 ;
struct V_4 * V_1572 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1573 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_494 ) )
goto V_59;
V_1572 = F_46 ( V_53 , V_1451 ) ;
if ( ! V_1572 )
goto V_59;
if ( F_50 ( V_53 , V_1454 ,
V_1455 , V_1463 ) )
goto V_59;
F_47 ( V_53 , V_1572 ) ;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_405 ( struct V_25 * V_184 , const T_2 * V_494 ,
const T_2 * V_1463 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_406 ( V_184 , V_494 ) ;
F_404 ( V_7 , V_184 , V_494 , V_1463 , V_1267 ) ;
}
static void
F_407 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1574 ,
const T_2 * V_494 , bool V_1575 , T_11 V_1267 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1576 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
V_45 = F_46 ( V_53 , V_1577 ) ;
if ( ! V_45 )
goto V_59;
if ( F_29 ( V_53 , V_1578 , V_1574 ) ||
F_50 ( V_53 , V_1579 , V_532 , V_494 ) ||
( V_1575 &&
F_30 ( V_53 , V_1580 ) ) )
goto V_59;
F_47 ( V_53 , V_45 ) ;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_408 ( struct V_25 * V_184 , int V_1574 ,
const T_2 * V_494 , bool V_1575 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_409 ( V_184 , V_1574 , V_494 , V_1575 ) ;
F_407 ( V_7 , V_184 , V_1574 , V_494 , V_1575 , V_1267 ) ;
}
static void F_410 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_470 * V_471 ,
T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1581 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
if ( F_100 ( V_53 , V_471 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_411 ( struct V_25 * V_184 ,
struct V_470 * V_471 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_412 ( V_184 , V_471 ) ;
F_111 ( V_17 ) ;
if ( F_58 ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 &&
V_17 -> V_132 != V_137 &&
V_17 -> V_132 != V_136 ) )
goto V_542;
V_17 -> V_674 = V_471 -> V_55 ;
F_410 ( V_7 , V_184 , V_471 , V_126 ) ;
V_542:
F_113 ( V_17 ) ;
return;
}
void F_413 ( struct V_25 * V_184 ,
const T_2 * V_1286 , V_22 V_1582 ,
V_22 V_225 , V_22 V_1334 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_887 ;
void * V_264 ;
V_53 = F_73 ( V_1556 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1570 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_1286 ) )
goto V_59;
V_887 = F_46 ( V_53 , V_1342 ) ;
if ( ! V_887 )
goto V_59;
if ( F_29 ( V_53 , V_1347 , V_1582 ) )
goto V_59;
if ( F_29 ( V_53 , V_1346 , V_225 ) )
goto V_59;
if ( F_29 ( V_53 , V_1348 , V_1334 ) )
goto V_59;
F_47 ( V_53 , V_887 ) ;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void
F_414 ( struct V_6 * V_7 ,
struct V_470 * V_471 ,
enum V_1583 V_1584 ,
struct V_25 * V_19 , T_11 V_1267 )
{
struct V_31 * V_53 ;
void * V_264 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1585 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
}
if ( F_29 ( V_53 , V_1586 , V_1584 ) )
goto V_59;
if ( F_100 ( V_53 , V_471 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_415 ( struct V_25 * V_184 ,
const T_2 * V_1286 , V_22 V_1582 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_887 ;
void * V_264 ;
F_416 ( V_184 , V_1286 , V_1582 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1570 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_1286 ) )
goto V_59;
V_887 = F_46 ( V_53 , V_1342 ) ;
if ( ! V_887 )
goto V_59;
if ( F_29 ( V_53 , V_1587 , V_1582 ) )
goto V_59;
F_47 ( V_53 , V_887 ) ;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_417 ( struct V_25 * V_184 , const T_2 * V_614 ,
T_1 V_584 , bool V_1588 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
F_418 ( V_184 , V_614 , V_584 , V_1588 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1467 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_614 ) ||
F_103 ( V_53 , V_1297 , V_584 ) ||
( V_1588 && F_30 ( V_53 , V_1567 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_419 ( struct V_18 * V_18 ,
const T_2 * V_1589 , T_10 V_47 ,
int V_1561 , int V_1562 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
struct V_1468 * V_1469 ;
F_420 ( V_18 , V_1589 , V_47 , V_1561 , V_1562 ) ;
F_232 ( & V_7 -> V_1472 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_73 ( V_47 + 100 , V_1519 ) ;
if ( ! V_53 ) {
F_234 ( & V_7 -> V_1472 ) ;
return;
}
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1323 ) ;
if ( ! V_264 )
goto V_59;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1561 &&
F_29 ( V_53 , V_473 , V_1561 ) ) ||
( V_1562 &&
F_29 ( V_53 , V_1563 , V_1562 ) ) ||
F_50 ( V_53 , V_1322 , V_47 , V_1589 ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_393 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1469 -> V_1473 ) ;
}
F_234 ( & V_7 -> V_1472 ) ;
return;
V_59:
F_234 ( & V_7 -> V_1472 ) ;
if ( V_264 )
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
void F_421 ( struct V_1 * V_17 ,
struct V_1590 * V_1591 ,
T_11 V_1267 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
int V_1383 = 200 ;
F_422 ( V_17 -> V_18 , V_17 , V_1591 ) ;
if ( V_1591 )
V_1383 += V_1591 -> V_1592 ;
V_53 = F_73 ( V_1383 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1593 ) ;
if ( ! V_264 )
goto V_594;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_594;
if ( V_17 -> V_19 && F_29 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_594;
if ( V_1591 ) {
struct V_4 * V_1594 ;
V_1594 = F_46 ( V_53 , V_1385 ) ;
if ( ! V_1594 )
goto V_594;
if ( V_1591 -> V_421 &&
F_30 ( V_53 , V_190 ) )
goto V_594;
if ( V_1591 -> V_1387 &&
F_30 ( V_53 , V_192 ) )
goto V_594;
if ( V_1591 -> V_1388 &&
F_30 ( V_53 , V_196 ) )
goto V_594;
if ( V_1591 -> V_1389 &&
F_30 ( V_53 , V_198 ) )
goto V_594;
if ( V_1591 -> V_1390 &&
F_30 ( V_53 , V_200 ) )
goto V_594;
if ( V_1591 -> V_1391 &&
F_30 ( V_53 , V_202 ) )
goto V_594;
if ( V_1591 -> V_1595 >= 0 &&
F_29 ( V_53 , V_212 ,
V_1591 -> V_1595 ) )
goto V_594;
if ( V_1591 -> V_1596 &&
F_30 ( V_53 , V_1597 ) )
goto V_594;
if ( V_1591 -> V_1598 &&
F_30 ( V_53 , V_1599 ) )
goto V_594;
if ( V_1591 -> V_1600 &&
F_30 ( V_53 ,
V_1601 ) )
goto V_594;
if ( V_1591 -> V_1602 ) {
V_22 V_1603 = V_1604 ;
V_22 V_1605 = V_1606 ;
if ( ! V_1591 -> V_1607 ) {
V_1603 =
V_1608 ;
V_1605 =
V_1609 ;
}
if ( V_1591 -> V_1610 &&
F_29 ( V_53 , V_1605 , V_1591 -> V_1610 ) )
goto V_594;
if ( F_50 ( V_53 , V_1603 , V_1591 -> V_1592 ,
V_1591 -> V_1602 ) )
goto V_594;
}
F_47 ( V_53 , V_1594 ) ;
}
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_594:
F_74 ( V_53 ) ;
}
void F_423 ( struct V_25 * V_184 , const T_2 * V_1286 ,
enum V_1290 V_1611 ,
T_3 V_1242 , T_11 V_1267 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
F_424 ( V_17 -> V_18 , V_184 , V_1286 , V_1611 ,
V_1242 ) ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1612 ) ;
if ( ! V_264 ) {
F_74 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_55 ( V_53 , V_1292 , V_1611 ) ||
F_50 ( V_53 , V_495 , V_532 , V_1286 ) ||
( V_1242 > 0 &&
F_54 ( V_53 , V_1243 , V_1242 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_1267 ) ;
return;
V_59:
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
static int F_425 ( struct V_1613 * V_1614 ,
unsigned long V_263 ,
void * V_1615 )
{
struct V_1616 * V_1617 = V_1615 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1468 * V_1469 , * V_24 ;
if ( V_263 != V_1618 )
return V_1619 ;
F_205 () ;
F_426 (rdev, &cfg80211_rdev_list, list) {
F_426 (wdev, &rdev->wdev_list, list)
F_427 ( V_17 , V_1617 -> V_49 ) ;
F_232 ( & V_7 -> V_1472 ) ;
F_428 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1469 -> V_1473 == V_1617 -> V_49 ) {
F_429 ( & V_1469 -> V_577 ) ;
F_42 ( V_1469 ) ;
break;
}
}
F_234 ( & V_7 -> V_1472 ) ;
}
F_207 () ;
return V_1619 ;
}
void F_430 ( struct V_25 * V_19 ,
struct V_1620 * V_1621 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_264 ;
F_431 ( V_18 , V_19 , V_1621 ) ;
if ( ! V_1621 -> V_1622 )
return;
V_53 = F_73 ( V_543 , V_126 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1623 ) ;
if ( ! V_264 )
goto V_542;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_495 , V_532 , V_1621 -> V_1622 ) )
goto V_542;
if ( V_1621 -> V_1142 &&
F_50 ( V_53 , V_620 , V_1621 -> V_1624 , V_1621 -> V_1142 ) )
goto V_542;
if ( V_1621 -> V_1625 &&
F_50 ( V_53 , V_1626 , V_1621 -> V_1627 ,
V_1621 -> V_1625 ) )
goto V_542;
F_65 ( V_53 , V_264 ) ;
F_265 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1521 , V_126 ) ;
return;
V_542:
F_74 ( V_53 ) ;
}
void F_432 ( struct V_1 * V_17 , T_11 V_1267 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_264 ;
V_22 V_1473 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1488 )
return;
V_1473 = V_7 -> V_1488 ;
V_7 -> V_1488 = 0 ;
V_53 = F_73 ( V_543 , V_1267 ) ;
if ( ! V_53 )
return;
V_264 = F_26 ( V_53 , 0 , 0 , 0 , V_1628 ) ;
if ( ! V_264 )
goto V_59;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_65 ( V_53 , V_264 ) ;
F_393 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1473 ) ;
return;
V_59:
if ( V_264 )
F_66 ( V_53 , V_264 ) ;
F_74 ( V_53 ) ;
}
int F_433 ( void )
{
int V_35 ;
V_35 = F_434 ( & V_38 , V_1629 ,
V_1630 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_435 ( & V_1631 ) ;
if ( V_35 )
goto V_1632;
return 0 ;
V_1632:
F_436 ( & V_38 ) ;
return V_35 ;
}
void F_437 ( void )
{
F_438 ( & V_1631 ) ;
F_436 ( & V_38 ) ;
}
