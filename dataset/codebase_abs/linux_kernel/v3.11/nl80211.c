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
struct V_213 * V_214 )
{
struct V_4 * V_215 , * V_216 ;
struct V_217 * V_218 ;
int V_144 ;
if ( V_214 -> V_219 . V_220 &&
( F_50 ( V_53 , V_221 ,
sizeof( V_214 -> V_219 . V_222 ) ,
& V_214 -> V_219 . V_222 ) ||
F_53 ( V_53 , V_223 ,
V_214 -> V_219 . V_224 ) ||
F_54 ( V_53 , V_225 ,
V_214 -> V_219 . V_226 ) ||
F_54 ( V_53 , V_227 ,
V_214 -> V_219 . V_228 ) ) )
return - V_82 ;
if ( V_214 -> V_229 . V_230 &&
( F_50 ( V_53 , V_231 ,
sizeof( V_214 -> V_229 . V_232 ) ,
& V_214 -> V_229 . V_232 ) ||
F_29 ( V_53 , V_233 ,
V_214 -> V_229 . V_224 ) ) )
return - V_82 ;
V_215 = F_46 ( V_53 , V_234 ) ;
if ( ! V_215 )
return - V_82 ;
for ( V_144 = 0 ; V_144 < V_214 -> V_235 ; V_144 ++ ) {
V_216 = F_46 ( V_53 , V_144 ) ;
if ( ! V_216 )
return - V_82 ;
V_218 = & V_214 -> V_236 [ V_144 ] ;
if ( F_29 ( V_53 , V_237 ,
V_218 -> V_238 ) )
return - V_82 ;
if ( ( V_218 -> V_51 & V_239 ) &&
F_30 ( V_53 ,
V_240 ) )
return - V_82 ;
F_47 ( V_53 , V_216 ) ;
}
F_47 ( V_53 , V_215 ) ;
return 0 ;
}
static int
F_55 ( struct V_31 * V_53 ,
const struct V_241 * V_242 )
{
T_3 V_243 ;
struct V_4 * V_244 , * V_245 ;
enum V_246 V_247 ;
int V_144 ;
if ( ! V_242 )
return 0 ;
V_245 = F_46 ( V_53 , V_248 ) ;
if ( ! V_245 )
return - V_82 ;
for ( V_247 = 0 ; V_247 < V_249 ; V_247 ++ ) {
V_244 = F_46 ( V_53 , V_247 ) ;
if ( ! V_244 )
return - V_82 ;
V_144 = 0 ;
V_243 = V_242 [ V_247 ] . V_250 ;
while ( V_243 ) {
if ( ( V_243 & 1 ) &&
F_53 ( V_53 , V_251 ,
( V_144 << 4 ) | V_252 ) )
return - V_82 ;
V_243 >>= 1 ;
V_144 ++ ;
}
F_47 ( V_53 , V_244 ) ;
}
F_47 ( V_53 , V_245 ) ;
V_245 = F_46 ( V_53 , V_253 ) ;
if ( ! V_245 )
return - V_82 ;
for ( V_247 = 0 ; V_247 < V_249 ; V_247 ++ ) {
V_244 = F_46 ( V_53 , V_247 ) ;
if ( ! V_244 )
return - V_82 ;
V_144 = 0 ;
V_243 = V_242 [ V_247 ] . V_254 ;
while ( V_243 ) {
if ( ( V_243 & 1 ) &&
F_53 ( V_53 , V_251 ,
( V_144 << 4 ) | V_252 ) )
return - V_82 ;
V_243 >>= 1 ;
V_144 ++ ;
}
F_47 ( V_53 , V_244 ) ;
}
F_47 ( V_53 , V_245 ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_184 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_255 * V_256 )
{
void * V_257 ;
struct V_4 * V_258 , * V_259 ;
struct V_4 * V_260 , * V_261 ;
struct V_4 * V_262 ;
enum V_263 V_264 ;
struct V_54 * V_55 ;
int V_144 ;
const struct V_241 * V_242 =
V_184 -> V_18 . V_242 ;
V_22 V_265 ;
V_257 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_266 ) ;
if ( ! V_257 )
return - V_82 ;
if ( F_57 ( ! V_256 ) )
return - V_16 ;
if ( F_29 ( V_53 , V_26 , V_184 -> V_14 ) ||
F_58 ( V_53 , V_267 ,
F_59 ( & V_184 -> V_18 ) ) ||
F_29 ( V_53 , V_268 ,
V_269 ) )
goto V_59;
switch ( V_256 -> V_270 ) {
case 0 :
if ( F_54 ( V_53 , V_271 ,
V_184 -> V_18 . V_272 ) ||
F_54 ( V_53 , V_273 ,
V_184 -> V_18 . V_274 ) ||
F_29 ( V_53 , V_275 ,
V_184 -> V_18 . V_276 ) ||
F_29 ( V_53 , V_277 ,
V_184 -> V_18 . V_278 ) ||
F_54 ( V_53 , V_279 ,
V_184 -> V_18 . V_280 ) ||
F_54 ( V_53 , V_281 ,
V_184 -> V_18 . V_282 ) ||
F_54 ( V_53 , V_283 ,
V_184 -> V_18 . V_284 ) ||
F_53 ( V_53 , V_285 ,
V_184 -> V_18 . V_286 ) ||
F_53 ( V_53 , V_287 ,
V_184 -> V_18 . V_288 ) ||
F_54 ( V_53 , V_289 ,
V_184 -> V_18 . V_290 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_291 ) &&
F_30 ( V_53 , V_292 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_293 ) &&
F_30 ( V_53 , V_294 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_295 ) &&
F_30 ( V_53 , V_296 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_297 ) &&
F_30 ( V_53 , V_298 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_299 ) &&
F_30 ( V_53 , V_300 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_301 ) &&
F_30 ( V_53 , V_302 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_303 ) &&
F_30 ( V_53 , V_303 ) )
goto V_59;
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
case 1 :
if ( F_50 ( V_53 , V_305 ,
sizeof( V_22 ) * V_184 -> V_18 . V_306 ,
V_184 -> V_18 . V_307 ) )
goto V_59;
if ( F_54 ( V_53 , V_308 ,
V_184 -> V_18 . V_309 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_310 ) &&
F_30 ( V_53 , V_311 ) )
goto V_59;
if ( F_29 ( V_53 , V_312 ,
V_184 -> V_18 . V_313 ) ||
F_29 ( V_53 , V_314 ,
V_184 -> V_18 . V_315 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_316 ) &&
F_29 ( V_53 , V_317 ,
V_184 -> V_18 . V_318 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_313 ||
V_184 -> V_18 . V_315 ) &&
V_184 -> V_319 -> V_320 ) {
V_22 V_321 = 0 , V_322 = 0 ;
int V_323 ;
V_323 = F_60 ( V_184 , & V_321 , & V_322 ) ;
if ( ! V_323 ) {
if ( F_29 ( V_53 ,
V_324 ,
V_321 ) ||
F_29 ( V_53 ,
V_325 ,
V_322 ) )
goto V_59;
}
}
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
case 2 :
if ( F_45 ( V_53 , V_326 ,
V_184 -> V_18 . V_327 ) )
goto V_59;
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
case 3 :
V_258 = F_46 ( V_53 , V_328 ) ;
if ( ! V_258 )
goto V_59;
for ( V_264 = V_256 -> V_329 ;
V_264 < V_330 ; V_264 ++ ) {
struct V_213 * V_214 ;
V_214 = V_184 -> V_18 . V_331 [ V_264 ] ;
if ( ! V_214 )
continue;
V_259 = F_46 ( V_53 , V_264 ) ;
if ( ! V_259 )
goto V_59;
switch ( V_256 -> V_332 ) {
case 0 :
if ( F_52 ( V_53 , V_214 ) )
goto V_59;
V_256 -> V_332 ++ ;
if ( V_256 -> V_304 )
break;
default:
V_260 = F_46 (
V_53 , V_333 ) ;
if ( ! V_260 )
goto V_59;
for ( V_144 = V_256 -> V_332 - 1 ;
V_144 < V_214 -> V_334 ;
V_144 ++ ) {
V_261 = F_46 ( V_53 , V_144 ) ;
if ( ! V_261 )
goto V_59;
V_55 = & V_214 -> V_335 [ V_144 ] ;
if ( F_28 (
V_53 , V_55 ,
V_256 -> V_304 ) )
goto V_59;
F_47 ( V_53 , V_261 ) ;
if ( V_256 -> V_304 )
break;
}
if ( V_144 < V_214 -> V_334 )
V_256 -> V_332 = V_144 + 2 ;
else
V_256 -> V_332 = 0 ;
F_47 ( V_53 , V_260 ) ;
}
F_47 ( V_53 , V_259 ) ;
if ( V_256 -> V_304 ) {
if ( V_256 -> V_332 )
V_264 -- ;
break;
}
}
F_47 ( V_53 , V_258 ) ;
if ( V_264 < V_330 )
V_256 -> V_329 = V_264 + 1 ;
else
V_256 -> V_329 = 0 ;
if ( V_256 -> V_329 == 0 && V_256 -> V_332 == 0 )
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
case 4 :
V_262 = F_46 ( V_53 , V_336 ) ;
if ( ! V_262 )
goto V_59;
V_144 = 0 ;
#define F_61 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_61 ( V_337 , V_338 ) ;
F_61 ( V_339 , V_340 ) ;
F_61 ( V_341 , V_342 ) ;
F_61 ( V_343 , V_344 ) ;
F_61 ( V_345 , V_346 ) ;
F_61 ( V_347 , V_348 ) ;
F_61 ( V_349 , V_350 ) ;
F_61 ( V_351 , V_352 ) ;
F_61 ( V_353 , V_354 ) ;
F_61 ( V_355 , V_356 ) ;
F_61 ( V_357 , V_358 ) ;
F_61 ( V_359 , V_360 ) ;
F_61 ( V_361 , V_362 ) ;
F_61 ( V_363 , V_364 ) ;
F_61 ( V_365 , V_366 ) ;
F_61 ( V_367 , V_368 ) ;
F_61 ( V_369 , V_370 ) ;
if ( V_184 -> V_18 . V_51 & V_371 )
F_61 ( V_372 , V_373 ) ;
F_61 ( V_374 , V_375 ) ;
F_61 ( V_376 , V_377 ) ;
F_61 ( V_378 , V_379 ) ;
if ( V_184 -> V_18 . V_51 & V_380 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_381 ) )
goto V_59;
}
if ( V_184 -> V_319 -> V_382 || V_184 -> V_319 -> V_343 ||
V_184 -> V_319 -> V_363 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_383 ) )
goto V_59;
}
F_61 ( V_384 , V_385 ) ;
if ( V_184 -> V_18 . V_51 & V_299 ) {
F_61 ( V_386 , V_387 ) ;
F_61 ( V_388 , V_389 ) ;
}
if ( V_184 -> V_18 . V_51 & V_390 )
F_61 ( V_391 , V_392 ) ;
F_61 ( V_393 , V_394 ) ;
F_61 ( V_395 , V_396 ) ;
if ( V_184 -> V_18 . V_51 & V_397 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_398 ) )
goto V_59;
}
F_61 ( V_399 , V_400 ) ;
F_61 ( V_401 , V_402 ) ;
if ( V_256 -> V_304 ) {
F_61 ( V_403 , V_404 ) ;
F_61 ( V_405 , V_406 ) ;
}
#ifdef F_62
F_61 ( V_407 , V_408 ) ;
#endif
#undef F_61
if ( V_184 -> V_319 -> V_409 || V_184 -> V_319 -> V_353 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_410 ) )
goto V_59;
}
if ( V_184 -> V_319 -> V_411 || V_184 -> V_319 -> V_357 ) {
V_144 ++ ;
if ( F_29 ( V_53 , V_144 , V_412 ) )
goto V_59;
}
F_47 ( V_53 , V_262 ) ;
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
case 5 :
if ( V_184 -> V_319 -> V_372 &&
( V_184 -> V_18 . V_51 & V_371 ) &&
F_29 ( V_53 ,
V_413 ,
V_184 -> V_18 . V_414 ) )
goto V_59;
if ( ( V_184 -> V_18 . V_51 & V_415 ) &&
F_30 ( V_53 , V_416 ) )
goto V_59;
if ( F_55 ( V_53 , V_242 ) )
goto V_59;
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
case 6 :
#ifdef F_63
if ( F_51 ( V_53 , V_184 , V_256 -> V_304 ) )
goto V_59;
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
#else
V_256 -> V_270 ++ ;
#endif
case 7 :
if ( F_45 ( V_53 , V_417 ,
V_184 -> V_18 . V_418 ) )
goto V_59;
if ( F_48 ( & V_184 -> V_18 , V_53 ,
V_256 -> V_304 ) )
goto V_59;
V_256 -> V_270 ++ ;
if ( V_256 -> V_304 )
break;
case 8 :
if ( ( V_184 -> V_18 . V_51 & V_419 ) &&
F_29 ( V_53 , V_420 ,
V_184 -> V_18 . V_421 ) )
goto V_59;
V_265 = V_184 -> V_18 . V_265 ;
if ( V_256 -> V_304 )
V_265 |= V_422 ;
if ( F_29 ( V_53 , V_423 , V_265 ) )
goto V_59;
if ( V_184 -> V_18 . V_424 &&
F_50 ( V_53 , V_425 ,
sizeof( * V_184 -> V_18 . V_424 ) ,
V_184 -> V_18 . V_424 ) )
goto V_59;
if ( V_184 -> V_18 . V_51 & V_419 &&
V_184 -> V_18 . V_426 &&
F_29 ( V_53 , V_427 ,
V_184 -> V_18 . V_426 ) )
goto V_59;
V_256 -> V_270 ++ ;
break;
case 9 :
if ( V_184 -> V_18 . V_428 &&
( F_50 ( V_53 , V_429 ,
V_184 -> V_18 . V_430 ,
V_184 -> V_18 . V_428 ) ||
F_50 ( V_53 , V_431 ,
V_184 -> V_18 . V_430 ,
V_184 -> V_18 . V_432 ) ) )
goto V_59;
if ( V_184 -> V_18 . V_433 &&
F_50 ( V_53 , V_434 ,
sizeof( * V_184 -> V_18 . V_433 ) ,
V_184 -> V_18 . V_433 ) )
goto V_59;
V_256 -> V_270 = 0 ;
break;
}
return F_64 ( V_53 , V_257 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
static int F_66 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_255 * V_256 )
{
struct V_4 * * V_86 = V_38 . V_40 ;
int V_436 = F_16 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_86 , V_38 . V_41 , V_42 ) ;
if ( V_436 )
return 0 ;
V_256 -> V_304 = V_86 [ V_437 ] ;
if ( V_86 [ V_26 ] )
V_256 -> V_438 = F_4 ( V_86 [ V_26 ] ) ;
if ( V_86 [ V_12 ] )
V_256 -> V_438 = F_5 ( V_86 [ V_12 ] ) >> 32 ;
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
V_256 -> V_438 = V_7 -> V_14 ;
}
F_12 ( V_19 ) ;
}
return 0 ;
}
static int F_67 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_96 = 0 , V_436 ;
struct V_255 * V_256 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_184 ;
F_15 () ;
if ( ! V_256 ) {
V_256 = F_39 ( sizeof( * V_256 ) , V_126 ) ;
if ( ! V_256 ) {
F_21 () ;
return - V_127 ;
}
V_256 -> V_438 = - 1 ;
V_436 = F_66 ( V_32 , V_34 , V_256 ) ;
if ( V_436 ) {
F_42 ( V_256 ) ;
F_21 () ;
return V_436 ;
}
V_34 -> args [ 0 ] = ( long ) V_256 ;
}
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_68 ( F_7 ( & V_184 -> V_18 ) , F_17 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_96 <= V_256 -> V_439 )
continue;
if ( V_256 -> V_438 != - 1 &&
V_256 -> V_438 != V_184 -> V_14 )
continue;
do {
V_436 = F_56 ( V_184 , V_32 ,
F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_440 ,
V_441 , V_256 ) ;
if ( V_436 < 0 ) {
if ( ( V_436 == - V_82 || V_436 == - V_435 ) &&
! V_32 -> V_47 &&
V_34 -> V_442 < 4096 ) {
V_34 -> V_442 = 4096 ;
F_21 () ;
return 1 ;
}
V_96 -- ;
break;
}
} while ( V_256 -> V_270 > 0 );
break;
}
F_21 () ;
V_256 -> V_439 = V_96 ;
return V_32 -> V_47 ;
}
static int F_70 ( struct V_33 * V_34 )
{
F_42 ( ( void * ) V_34 -> args [ 0 ] ) ;
return 0 ;
}
static int F_71 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_184 = V_30 -> V_443 [ 0 ] ;
struct V_255 V_256 = {} ;
V_53 = F_72 ( 4096 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_56 ( V_184 , V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
& V_256 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_82 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_75 ( struct V_4 * V_86 [] ,
struct V_446 * V_447 )
{
if ( ! V_86 [ V_448 ] || ! V_86 [ V_449 ] ||
! V_86 [ V_450 ] || ! V_86 [ V_451 ] ||
! V_86 [ V_452 ] )
return - V_16 ;
V_447 -> V_453 = F_35 ( V_86 [ V_448 ] ) ;
V_447 -> V_454 = F_76 ( V_86 [ V_449 ] ) ;
V_447 -> V_455 = F_76 ( V_86 [ V_450 ] ) ;
V_447 -> V_456 = F_76 ( V_86 [ V_451 ] ) ;
V_447 -> V_457 = F_35 ( V_86 [ V_452 ] ) ;
if ( V_447 -> V_453 >= V_458 )
return - V_16 ;
return 0 ;
}
static bool F_77 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_132 == V_133 ||
V_17 -> V_132 == V_136 ||
V_17 -> V_132 == V_459 ||
V_17 -> V_132 == V_135 ;
}
static int F_78 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_460 * V_461 )
{
V_22 V_462 ;
if ( ! V_30 -> V_5 [ V_463 ] )
return - V_16 ;
V_462 = F_4 ( V_30 -> V_5 [ V_463 ] ) ;
V_461 -> V_55 = F_79 ( & V_7 -> V_18 , V_462 ) ;
V_461 -> V_464 = V_465 ;
V_461 -> V_466 = V_462 ;
V_461 -> V_467 = 0 ;
if ( ! V_461 -> V_55 || V_461 -> V_55 -> V_51 & V_60 )
return - V_16 ;
if ( V_30 -> V_5 [ V_468 ] ) {
enum V_469 V_470 ;
V_470 = F_4 (
V_30 -> V_5 [ V_468 ] ) ;
switch ( V_470 ) {
case V_471 :
case V_472 :
case V_473 :
case V_474 :
F_80 ( V_461 , V_461 -> V_55 ,
V_470 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_475 ] ) {
V_461 -> V_464 =
F_4 ( V_30 -> V_5 [ V_475 ] ) ;
if ( V_30 -> V_5 [ V_476 ] )
V_461 -> V_466 =
F_4 (
V_30 -> V_5 [ V_476 ] ) ;
if ( V_30 -> V_5 [ V_477 ] )
V_461 -> V_467 =
F_4 (
V_30 -> V_5 [ V_477 ] ) ;
}
if ( ! F_81 ( V_461 ) )
return - V_16 ;
if ( ! F_82 ( & V_7 -> V_18 , V_461 ,
V_60 ) )
return - V_16 ;
if ( ( V_461 -> V_464 == V_478 ||
V_461 -> V_464 == V_479 ) &&
! ( V_7 -> V_18 . V_51 & V_303 ) )
return - V_16 ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_29 * V_30 )
{
struct V_460 V_461 ;
int V_8 ;
enum V_246 V_132 = V_459 ;
if ( V_17 )
V_132 = V_17 -> V_132 ;
if ( ! F_77 ( V_17 ) )
return - V_480 ;
V_8 = F_78 ( V_7 , V_30 , & V_461 ) ;
if ( V_8 )
return V_8 ;
switch ( V_132 ) {
case V_133 :
case V_135 :
if ( V_17 -> V_481 ) {
V_8 = - V_482 ;
break;
}
if ( ! F_84 ( & V_7 -> V_18 , & V_461 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_483 = V_461 ;
V_8 = 0 ;
break;
case V_136 :
V_8 = F_85 ( V_7 , V_17 , & V_461 ) ;
break;
case V_459 :
V_8 = F_86 ( V_7 , & V_461 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_87 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_443 [ 1 ] ;
return F_83 ( V_7 , V_19 -> V_28 , V_30 ) ;
}
static int F_88 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
const T_2 * V_484 ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( F_89 ( V_184 ) )
return - V_482 ;
if ( ! V_7 -> V_319 -> V_384 )
return - V_480 ;
if ( V_17 -> V_132 != V_486 )
return - V_480 ;
V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
return F_90 ( V_7 , V_184 , V_484 ) ;
}
static int F_91 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_487 = 0 ;
struct V_4 * V_488 ;
V_22 V_489 ;
T_2 V_272 = 0 , V_274 = 0 ;
V_22 V_276 = 0 , V_278 = 0 ;
T_2 V_280 = 0 ;
F_2 () ;
if ( V_30 -> V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_30 -> V_5 [ V_10 ] ) ;
V_19 = F_10 ( F_92 ( V_30 ) , V_20 ) ;
if ( V_19 && V_19 -> V_28 )
V_7 = F_11 ( V_19 -> V_28 -> V_18 ) ;
else
V_19 = NULL ;
}
if ( ! V_19 ) {
V_7 = F_8 ( F_92 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_267 ] )
V_8 = F_93 (
V_7 , F_24 ( V_30 -> V_5 [ V_267 ] ) ) ;
if ( V_8 )
goto V_490;
if ( V_30 -> V_5 [ V_491 ] ) {
struct V_446 V_447 ;
struct V_4 * V_86 [ V_492 + 1 ] ;
if ( ! V_7 -> V_319 -> V_493 ) {
V_8 = - V_480 ;
goto V_490;
}
if ( ! V_19 ) {
V_8 = - V_16 ;
goto V_490;
}
if ( V_19 -> V_28 -> V_132 != V_133 &&
V_19 -> V_28 -> V_132 != V_135 ) {
V_8 = - V_16 ;
goto V_490;
}
if ( ! F_89 ( V_19 ) ) {
V_8 = - V_494 ;
goto V_490;
}
F_40 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_94 ( V_86 , V_492 ,
F_24 ( V_488 ) ,
F_25 ( V_488 ) ,
V_495 ) ;
V_8 = F_75 ( V_86 , & V_447 ) ;
if ( V_8 )
goto V_490;
V_8 = F_95 ( V_7 , V_19 ,
& V_447 ) ;
if ( V_8 )
goto V_490;
}
}
if ( V_30 -> V_5 [ V_463 ] ) {
V_8 = F_83 ( V_7 ,
F_77 ( V_17 ) ? V_17 : NULL ,
V_30 ) ;
if ( V_8 )
goto V_490;
}
if ( V_30 -> V_5 [ V_496 ] ) {
struct V_1 * V_497 = V_17 ;
enum V_498 type ;
int V_96 , V_499 = 0 ;
if ( ! ( V_7 -> V_18 . V_265 & V_500 ) )
V_497 = NULL ;
if ( ! V_7 -> V_319 -> V_501 ) {
V_8 = - V_480 ;
goto V_490;
}
V_96 = V_496 ;
type = F_4 ( V_30 -> V_5 [ V_96 ] ) ;
if ( ! V_30 -> V_5 [ V_502 ] &&
( type != V_503 ) ) {
V_8 = - V_16 ;
goto V_490;
}
if ( type != V_503 ) {
V_96 = V_502 ;
V_499 = F_4 ( V_30 -> V_5 [ V_96 ] ) ;
}
V_8 = F_96 ( V_7 , V_497 , type , V_499 ) ;
if ( V_8 )
goto V_490;
}
if ( V_30 -> V_5 [ V_324 ] &&
V_30 -> V_5 [ V_325 ] ) {
V_22 V_321 , V_322 ;
if ( ( ! V_7 -> V_18 . V_313 &&
! V_7 -> V_18 . V_315 ) ||
! V_7 -> V_319 -> V_504 ) {
V_8 = - V_480 ;
goto V_490;
}
V_321 = F_4 ( V_30 -> V_5 [ V_324 ] ) ;
V_322 = F_4 ( V_30 -> V_5 [ V_325 ] ) ;
if ( ( ~ V_321 && ( V_321 & ~ V_7 -> V_18 . V_313 ) ) ||
( ~ V_322 && ( V_322 & ~ V_7 -> V_18 . V_315 ) ) ) {
V_8 = - V_16 ;
goto V_490;
}
V_321 = V_321 & V_7 -> V_18 . V_313 ;
V_322 = V_322 & V_7 -> V_18 . V_315 ;
V_8 = F_97 ( V_7 , V_321 , V_322 ) ;
if ( V_8 )
goto V_490;
}
V_489 = 0 ;
if ( V_30 -> V_5 [ V_271 ] ) {
V_272 = F_35 (
V_30 -> V_5 [ V_271 ] ) ;
if ( V_272 == 0 ) {
V_8 = - V_16 ;
goto V_490;
}
V_489 |= V_505 ;
}
if ( V_30 -> V_5 [ V_273 ] ) {
V_274 = F_35 (
V_30 -> V_5 [ V_273 ] ) ;
if ( V_274 == 0 ) {
V_8 = - V_16 ;
goto V_490;
}
V_489 |= V_506 ;
}
if ( V_30 -> V_5 [ V_275 ] ) {
V_276 = F_4 (
V_30 -> V_5 [ V_275 ] ) ;
if ( V_276 < 256 ) {
V_8 = - V_16 ;
goto V_490;
}
if ( V_276 != ( V_22 ) - 1 ) {
V_276 &= ~ 0x1 ;
}
V_489 |= V_507 ;
}
if ( V_30 -> V_5 [ V_277 ] ) {
V_278 = F_4 (
V_30 -> V_5 [ V_277 ] ) ;
V_489 |= V_508 ;
}
if ( V_30 -> V_5 [ V_279 ] ) {
V_280 = F_35 (
V_30 -> V_5 [ V_279 ] ) ;
V_489 |= V_509 ;
}
if ( V_489 ) {
T_2 V_510 , V_511 ;
V_22 V_512 , V_513 ;
T_2 V_514 ;
if ( ! V_7 -> V_319 -> V_515 ) {
V_8 = - V_480 ;
goto V_490;
}
V_510 = V_7 -> V_18 . V_272 ;
V_511 = V_7 -> V_18 . V_274 ;
V_512 = V_7 -> V_18 . V_276 ;
V_513 = V_7 -> V_18 . V_278 ;
V_514 = V_7 -> V_18 . V_280 ;
if ( V_489 & V_505 )
V_7 -> V_18 . V_272 = V_272 ;
if ( V_489 & V_506 )
V_7 -> V_18 . V_274 = V_274 ;
if ( V_489 & V_507 )
V_7 -> V_18 . V_276 = V_276 ;
if ( V_489 & V_508 )
V_7 -> V_18 . V_278 = V_278 ;
if ( V_489 & V_509 )
V_7 -> V_18 . V_280 = V_280 ;
V_8 = F_98 ( V_7 , V_489 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_272 = V_510 ;
V_7 -> V_18 . V_274 = V_511 ;
V_7 -> V_18 . V_276 = V_512 ;
V_7 -> V_18 . V_278 = V_513 ;
V_7 -> V_18 . V_280 = V_514 ;
}
}
V_490:
if ( V_19 )
F_12 ( V_19 ) ;
return V_8 ;
}
static inline T_1 V_13 ( struct V_1 * V_17 )
{
return ( T_1 ) V_17 -> V_21 |
( ( T_1 ) F_11 ( V_17 -> V_18 ) -> V_14 << 32 ) ;
}
static int F_99 ( struct V_31 * V_53 ,
struct V_460 * V_461 )
{
F_57 ( ! F_81 ( V_461 ) ) ;
if ( F_29 ( V_53 , V_463 ,
V_461 -> V_55 -> V_58 ) )
return - V_82 ;
switch ( V_461 -> V_464 ) {
case V_465 :
case V_516 :
case V_517 :
if ( F_29 ( V_53 , V_468 ,
F_100 ( V_461 ) ) )
return - V_82 ;
break;
default:
break;
}
if ( F_29 ( V_53 , V_475 , V_461 -> V_464 ) )
return - V_82 ;
if ( F_29 ( V_53 , V_476 , V_461 -> V_466 ) )
return - V_82 ;
if ( V_461 -> V_467 &&
F_29 ( V_53 , V_477 , V_461 -> V_467 ) )
return - V_82 ;
return 0 ;
}
static int F_101 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_25 * V_184 = V_17 -> V_19 ;
void * V_257 ;
V_257 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_518 ) ;
if ( ! V_257 )
return - 1 ;
if ( V_184 &&
( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_58 ( V_53 , V_519 , V_184 -> V_520 ) ) )
goto V_59;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_521 , V_17 -> V_132 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_50 ( V_53 , V_485 , V_522 , F_103 ( V_17 ) ) ||
F_29 ( V_53 , V_268 ,
V_7 -> V_523 ^
( V_269 << 2 ) ) )
goto V_59;
if ( V_7 -> V_319 -> V_524 ) {
int V_436 ;
struct V_460 V_461 ;
V_436 = F_104 ( V_7 , V_17 , & V_461 ) ;
if ( V_436 == 0 ) {
if ( F_99 ( V_53 , & V_461 ) )
goto V_59;
}
}
if ( V_17 -> V_525 ) {
if ( F_50 ( V_53 , V_526 , V_17 -> V_525 , V_17 -> V_527 ) )
goto V_59;
}
return F_64 ( V_53 , V_257 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
static int F_105 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_528 = 0 ;
int V_529 = 0 ;
int V_530 = V_34 -> args [ 0 ] ;
int V_531 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_15 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_68 ( F_7 ( & V_7 -> V_18 ) , F_17 ( V_32 -> V_44 ) ) )
continue;
if ( V_528 < V_530 ) {
V_528 ++ ;
continue;
}
V_529 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_529 < V_531 ) {
V_529 ++ ;
continue;
}
if ( F_101 ( V_32 , F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_440 , V_441 ,
V_7 , V_17 ) < 0 ) {
goto V_532;
}
V_529 ++ ;
}
V_528 ++ ;
}
V_532:
F_21 () ;
V_34 -> args [ 0 ] = V_528 ;
V_34 -> args [ 1 ] = V_529 ;
return V_32 -> V_47 ;
}
static int F_106 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_184 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_101 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_184 , V_17 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_82 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_107 ( struct V_4 * V_534 , V_22 * V_535 )
{
struct V_4 * V_51 [ V_536 + 1 ] ;
int V_537 ;
* V_535 = 0 ;
if ( ! V_534 )
return - V_16 ;
if ( F_34 ( V_51 , V_536 ,
V_534 , V_538 ) )
return - V_16 ;
for ( V_537 = 1 ; V_537 <= V_536 ; V_537 ++ )
if ( V_51 [ V_537 ] )
* V_535 |= ( 1 << V_537 ) ;
return 0 ;
}
static int F_108 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_539 ,
enum V_246 V_132 )
{
if ( ! V_539 ) {
if ( V_19 && ( V_19 -> V_540 & V_541 ) )
return - V_482 ;
return 0 ;
}
switch ( V_132 ) {
case V_134 :
if ( V_7 -> V_18 . V_51 & V_542 )
return 0 ;
break;
case V_138 :
if ( V_7 -> V_18 . V_51 & V_543 )
return 0 ;
break;
default:
break;
}
return - V_480 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_544 V_128 ;
int V_35 ;
enum V_246 V_545 , V_546 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
V_22 V_547 , * V_51 = NULL ;
bool V_548 = false ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_545 = V_546 = V_184 -> V_28 -> V_132 ;
if ( V_30 -> V_5 [ V_521 ] ) {
V_546 = F_4 ( V_30 -> V_5 [ V_521 ] ) ;
if ( V_545 != V_546 )
V_548 = true ;
if ( V_546 > V_549 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_550 ] ) {
struct V_1 * V_17 = V_184 -> V_28 ;
if ( V_546 != V_136 )
return - V_16 ;
if ( F_89 ( V_184 ) )
return - V_482 ;
F_110 ( V_17 ) ;
F_111 ( V_551 !=
V_552 ) ;
V_17 -> V_553 =
F_25 ( V_30 -> V_5 [ V_550 ] ) ;
memcpy ( V_17 -> V_527 , F_24 ( V_30 -> V_5 [ V_550 ] ) ,
V_17 -> V_553 ) ;
F_112 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_554 ] ) {
V_128 . V_539 = ! ! F_35 ( V_30 -> V_5 [ V_554 ] ) ;
V_548 = true ;
V_35 = F_108 ( V_7 , V_184 , V_128 . V_539 , V_546 ) ;
if ( V_35 )
return V_35 ;
} else {
V_128 . V_539 = - 1 ;
}
if ( V_30 -> V_5 [ V_555 ] ) {
if ( V_546 != V_459 )
return - V_16 ;
V_35 = F_107 ( V_30 -> V_5 [ V_555 ] ,
& V_547 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_547 ;
V_548 = true ;
}
if ( V_51 && ( * V_51 & V_556 ) &&
! ( V_7 -> V_18 . V_265 & V_557 ) )
return - V_480 ;
if ( V_548 )
V_35 = F_113 ( V_7 , V_184 , V_546 , V_51 , & V_128 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_128 . V_539 != - 1 )
V_184 -> V_28 -> V_539 = V_128 . V_539 ;
return V_35 ;
}
static int F_114 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_544 V_128 ;
struct V_1 * V_17 ;
struct V_31 * V_53 ;
int V_35 ;
enum V_246 type = V_558 ;
V_22 V_51 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ! V_30 -> V_5 [ V_519 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_521 ] ) {
type = F_4 ( V_30 -> V_5 [ V_521 ] ) ;
if ( type > V_549 )
return - V_16 ;
}
if ( ! V_7 -> V_319 -> V_337 ||
! ( V_7 -> V_18 . V_327 & ( 1 << type ) ) )
return - V_480 ;
if ( type == V_559 && V_30 -> V_5 [ V_485 ] ) {
F_115 ( V_128 . V_560 , V_30 -> V_5 [ V_485 ] ,
V_522 ) ;
if ( ! F_116 ( V_128 . V_560 ) )
return - V_561 ;
}
if ( V_30 -> V_5 [ V_554 ] ) {
V_128 . V_539 = ! ! F_35 ( V_30 -> V_5 [ V_554 ] ) ;
V_35 = F_108 ( V_7 , NULL , V_128 . V_539 , type ) ;
if ( V_35 )
return V_35 ;
}
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_35 = F_107 ( type == V_459 ?
V_30 -> V_5 [ V_555 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_556 ) &&
! ( V_7 -> V_18 . V_265 & V_557 ) )
return - V_480 ;
V_17 = F_117 ( V_7 ,
F_24 ( V_30 -> V_5 [ V_519 ] ) ,
type , V_35 ? NULL : & V_51 , & V_128 ) ;
if ( F_18 ( V_17 ) ) {
F_73 ( V_53 ) ;
return F_19 ( V_17 ) ;
}
switch ( type ) {
case V_136 :
if ( ! V_30 -> V_5 [ V_550 ] )
break;
F_110 ( V_17 ) ;
F_111 ( V_551 !=
V_552 ) ;
V_17 -> V_553 =
F_25 ( V_30 -> V_5 [ V_550 ] ) ;
memcpy ( V_17 -> V_527 , F_24 ( V_30 -> V_5 [ V_550 ] ) ,
V_17 -> V_553 ) ;
F_112 ( V_17 ) ;
break;
case V_559 :
F_118 ( & V_17 -> V_562 ) ;
F_119 ( & V_17 -> V_563 ) ;
F_120 ( & V_17 -> V_564 ) ;
F_119 ( & V_17 -> V_565 ) ;
F_120 ( & V_17 -> V_566 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_121 ( & V_17 -> V_567 , & V_7 -> V_568 ) ;
V_7 -> V_523 ++ ;
break;
default:
break;
}
if ( F_101 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_7 , V_17 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_82 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_122 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
if ( ! V_7 -> V_319 -> V_569 )
return - V_480 ;
if ( ! V_17 -> V_19 )
V_30 -> V_443 [ 1 ] = NULL ;
return F_123 ( V_7 , V_17 ) ;
}
static int F_124 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_3 V_570 ;
if ( ! V_30 -> V_5 [ V_571 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_395 )
return - V_480 ;
V_570 = F_76 ( V_30 -> V_5 [ V_571 ] ) ;
return F_125 ( V_7 , V_184 , V_570 ) ;
}
static void F_126 ( void * V_150 , struct V_572 * V_128 )
{
struct V_4 * V_83 ;
struct V_573 * V_574 = V_150 ;
if ( ( V_128 -> V_83 &&
F_50 ( V_574 -> V_53 , V_112 ,
V_128 -> V_99 , V_128 -> V_83 ) ) ||
( V_128 -> V_50 &&
F_50 ( V_574 -> V_53 , V_113 ,
V_128 -> V_101 , V_128 -> V_50 ) ) ||
( V_128 -> V_103 &&
F_29 ( V_574 -> V_53 , V_115 ,
V_128 -> V_103 ) ) )
goto V_59;
V_83 = F_46 ( V_574 -> V_53 , V_120 ) ;
if ( ! V_83 )
goto V_59;
if ( ( V_128 -> V_83 &&
F_50 ( V_574 -> V_53 , V_97 ,
V_128 -> V_99 , V_128 -> V_83 ) ) ||
( V_128 -> V_50 &&
F_50 ( V_574 -> V_53 , V_100 ,
V_128 -> V_101 , V_128 -> V_50 ) ) ||
( V_128 -> V_103 &&
F_29 ( V_574 -> V_53 , V_102 ,
V_128 -> V_103 ) ) )
goto V_59;
if ( F_54 ( V_574 -> V_53 , V_114 , V_574 -> V_96 ) )
goto V_59;
F_47 ( V_574 -> V_53 , V_83 ) ;
return;
V_59:
V_574 -> error = 1 ;
}
static int F_127 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 V_575 = 0 ;
const T_2 * V_576 = NULL ;
bool V_577 ;
struct V_573 V_574 = {
. error = 0 ,
} ;
void * V_257 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_114 ] )
V_575 = F_35 ( V_30 -> V_5 [ V_114 ] ) ;
if ( V_575 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_485 ] )
V_576 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_577 = ! ! V_576 ;
if ( V_30 -> V_5 [ V_118 ] ) {
V_22 V_578 = F_4 ( V_30 -> V_5 [ V_118 ] ) ;
if ( V_578 >= V_105 )
return - V_16 ;
if ( V_578 != V_579 &&
V_578 != V_580 )
return - V_16 ;
V_577 = V_578 == V_580 ;
}
if ( ! V_7 -> V_319 -> V_581 )
return - V_480 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_582 ) ;
if ( ! V_257 )
return - V_82 ;
V_574 . V_53 = V_53 ;
V_574 . V_96 = V_575 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_54 ( V_53 , V_114 , V_575 ) )
goto V_59;
if ( V_576 &&
F_50 ( V_53 , V_485 , V_522 , V_576 ) )
goto V_59;
if ( V_577 && V_576 &&
! ( V_7 -> V_18 . V_51 & V_291 ) )
return - V_583 ;
V_35 = F_128 ( V_7 , V_184 , V_575 , V_577 , V_576 , & V_574 ,
F_126 ) ;
if ( V_35 )
goto V_584;
if ( V_574 . error )
goto V_59;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_584:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_129 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_84 V_83 ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( V_83 . V_96 < 0 )
return - V_16 ;
if ( ! V_83 . V_89 && ! V_83 . V_91 )
return - V_16 ;
F_110 ( V_184 -> V_28 ) ;
if ( V_83 . V_89 ) {
if ( ! V_7 -> V_319 -> V_585 ) {
V_35 = - V_480 ;
goto V_532;
}
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( V_35 )
goto V_532;
V_35 = F_130 ( V_7 , V_184 , V_83 . V_96 ,
V_83 . V_93 , V_83 . V_94 ) ;
if ( V_35 )
goto V_532;
#ifdef F_131
V_184 -> V_28 -> V_586 . V_587 = V_83 . V_96 ;
#endif
} else {
if ( V_83 . V_93 || ! V_83 . V_94 ) {
V_35 = - V_16 ;
goto V_532;
}
if ( ! V_7 -> V_319 -> V_588 ) {
V_35 = - V_480 ;
goto V_532;
}
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( V_35 )
goto V_532;
V_35 = F_132 ( V_7 , V_184 , V_83 . V_96 ) ;
if ( V_35 )
goto V_532;
#ifdef F_131
V_184 -> V_28 -> V_586 . V_589 = V_83 . V_96 ;
#endif
}
V_532:
F_112 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_133 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_84 V_83 ;
const T_2 * V_576 = NULL ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_83 . V_98 . V_83 )
return - V_16 ;
if ( V_30 -> V_5 [ V_485 ] )
V_576 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( V_83 . type == - 1 ) {
if ( V_576 )
V_83 . type = V_580 ;
else
V_83 . type = V_579 ;
}
if ( V_83 . type != V_580 &&
V_83 . type != V_579 )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_341 )
return - V_480 ;
if ( F_41 ( V_7 , & V_83 . V_98 , V_83 . V_96 ,
V_83 . type == V_580 ,
V_576 ) )
return - V_16 ;
F_110 ( V_184 -> V_28 ) ;
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_134 ( V_7 , V_184 , V_83 . V_96 ,
V_83 . type == V_580 ,
V_576 , & V_83 . V_98 ) ;
F_112 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_135 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 * V_576 = NULL ;
struct V_84 V_83 ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_485 ] )
V_576 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( V_83 . type == - 1 ) {
if ( V_576 )
V_83 . type = V_580 ;
else
V_83 . type = V_579 ;
}
if ( V_83 . type != V_580 &&
V_83 . type != V_579 )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_590 )
return - V_480 ;
F_110 ( V_184 -> V_28 ) ;
V_35 = F_43 ( V_184 -> V_28 ) ;
if ( V_83 . type == V_580 && V_576 &&
! ( V_7 -> V_18 . V_51 & V_291 ) )
V_35 = - V_583 ;
if ( ! V_35 )
V_35 = F_136 ( V_7 , V_184 , V_83 . V_96 ,
V_83 . type == V_580 ,
V_576 ) ;
#ifdef F_131
if ( ! V_35 ) {
if ( V_83 . V_96 == V_184 -> V_28 -> V_586 . V_587 )
V_184 -> V_28 -> V_586 . V_587 = - 1 ;
else if ( V_83 . V_96 == V_184 -> V_28 -> V_586 . V_589 )
V_184 -> V_28 -> V_586 . V_589 = - 1 ;
}
#endif
F_112 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_137 ( struct V_4 * V_591 )
{
struct V_4 * V_45 ;
int V_592 = 0 , V_24 ;
F_40 (attr, nl_attr, tmp) {
if ( F_25 ( V_45 ) != V_522 )
return - V_16 ;
V_592 ++ ;
}
return V_592 ;
}
static struct V_593 * F_138 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_594 V_595 ;
struct V_4 * V_45 ;
struct V_593 * V_596 ;
int V_144 = 0 , V_592 , V_24 ;
if ( ! V_18 -> V_426 )
return F_3 ( - V_480 ) ;
if ( ! V_30 -> V_5 [ V_597 ] )
return F_3 ( - V_16 ) ;
V_595 = F_4 ( V_30 -> V_5 [ V_597 ] ) ;
if ( V_595 != V_598 &&
V_595 != V_599 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_600 ] )
return F_3 ( - V_16 ) ;
V_592 = F_137 ( V_30 -> V_5 [ V_600 ] ) ;
if ( V_592 < 0 )
return F_3 ( V_592 ) ;
if ( V_592 > V_18 -> V_426 )
return F_3 ( - V_601 ) ;
V_596 = F_39 ( sizeof( * V_596 ) + ( sizeof( struct V_602 ) * V_592 ) ,
V_126 ) ;
if ( ! V_596 )
return F_3 ( - V_127 ) ;
F_40 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_596 -> V_603 [ V_144 ] . V_604 , F_24 ( V_45 ) , V_522 ) ;
V_144 ++ ;
}
V_596 -> V_605 = V_592 ;
V_596 -> V_595 = V_595 ;
return V_596 ;
}
static int F_139 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_593 * V_596 ;
int V_35 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_480 ;
if ( ! V_184 -> V_28 -> V_481 )
return - V_16 ;
V_596 = F_138 ( & V_7 -> V_18 , V_30 ) ;
if ( F_18 ( V_596 ) )
return F_19 ( V_596 ) ;
V_35 = F_140 ( V_7 , V_184 , V_596 ) ;
F_42 ( V_596 ) ;
return V_35 ;
}
static int F_141 ( struct V_4 * V_5 [] ,
struct V_606 * V_607 )
{
bool V_608 = false ;
if ( ! F_23 ( V_5 [ V_609 ] ) ||
! F_23 ( V_5 [ V_610 ] ) ||
! F_23 ( V_5 [ V_611 ] ) ||
! F_23 ( V_5 [ V_612 ] ) )
return - V_16 ;
memset ( V_607 , 0 , sizeof( * V_607 ) ) ;
if ( V_5 [ V_613 ] ) {
V_607 -> V_614 = F_24 ( V_5 [ V_613 ] ) ;
V_607 -> V_615 = F_25 ( V_5 [ V_613 ] ) ;
if ( ! V_607 -> V_615 )
return - V_16 ;
V_608 = true ;
}
if ( V_5 [ V_609 ] ) {
V_607 -> V_616 = F_24 ( V_5 [ V_609 ] ) ;
V_607 -> V_617 = F_25 ( V_5 [ V_609 ] ) ;
V_608 = true ;
}
if ( ! V_608 )
return - V_16 ;
if ( V_5 [ V_610 ] ) {
V_607 -> V_618 = F_24 ( V_5 [ V_610 ] ) ;
V_607 -> V_619 = F_25 ( V_5 [ V_610 ] ) ;
}
if ( V_5 [ V_611 ] ) {
V_607 -> V_620 =
F_24 ( V_5 [ V_611 ] ) ;
V_607 -> V_621 =
F_25 ( V_5 [ V_611 ] ) ;
}
if ( V_5 [ V_612 ] ) {
V_607 -> V_622 =
F_24 ( V_5 [ V_612 ] ) ;
V_607 -> V_623 =
F_25 ( V_5 [ V_612 ] ) ;
}
if ( V_5 [ V_624 ] ) {
V_607 -> V_625 = F_24 ( V_5 [ V_624 ] ) ;
V_607 -> V_626 = F_25 ( V_5 [ V_624 ] ) ;
}
return 0 ;
}
static bool F_142 ( struct V_6 * V_7 ,
struct V_627 * V_128 )
{
struct V_1 * V_17 ;
bool V_436 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 )
continue;
if ( ! V_17 -> V_483 . V_55 )
continue;
V_128 -> V_461 = V_17 -> V_483 ;
V_436 = true ;
break;
}
return V_436 ;
}
static bool F_143 ( struct V_6 * V_7 ,
enum V_628 V_629 ,
enum V_630 V_52 )
{
if ( V_629 > V_631 )
return false ;
switch ( V_52 ) {
case V_632 :
if ( ! ( V_7 -> V_18 . V_265 & V_633 ) &&
V_629 == V_634 )
return false ;
return true ;
case V_410 :
case V_635 :
if ( V_629 == V_634 )
return false ;
return true ;
default:
return false ;
}
}
static int F_144 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_627 V_128 ;
int V_35 ;
T_2 V_636 = 0 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_480 ;
if ( ! V_7 -> V_319 -> V_343 )
return - V_480 ;
if ( V_17 -> V_481 )
return - V_637 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ! V_30 -> V_5 [ V_638 ] ||
! V_30 -> V_5 [ V_639 ] ||
! V_30 -> V_5 [ V_613 ] )
return - V_16 ;
V_35 = F_141 ( V_30 -> V_5 , & V_128 . V_640 ) ;
if ( V_35 )
return V_35 ;
V_128 . V_481 =
F_4 ( V_30 -> V_5 [ V_638 ] ) ;
V_128 . V_641 =
F_4 ( V_30 -> V_5 [ V_639 ] ) ;
V_35 = F_145 ( V_7 , V_128 . V_481 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_526 ] ) {
V_128 . V_527 = F_24 ( V_30 -> V_5 [ V_526 ] ) ;
V_128 . V_525 =
F_25 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_128 . V_525 == 0 ||
V_128 . V_525 > V_551 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_642 ] ) {
V_128 . V_643 = F_4 (
V_30 -> V_5 [ V_642 ] ) ;
if ( V_128 . V_643 != V_644 &&
V_128 . V_643 != V_645 &&
V_128 . V_643 != V_646 )
return - V_16 ;
}
V_128 . V_647 = ! ! V_30 -> V_5 [ V_648 ] ;
if ( V_30 -> V_5 [ V_649 ] ) {
V_128 . V_629 = F_4 (
V_30 -> V_5 [ V_649 ] ) ;
if ( ! F_143 ( V_7 , V_128 . V_629 ,
V_635 ) )
return - V_16 ;
} else
V_128 . V_629 = V_650 ;
V_35 = F_146 ( V_7 , V_30 , & V_128 . V_651 ,
V_652 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_653 ] ) {
if ( ! ( V_7 -> V_18 . V_265 & V_654 ) )
return - V_480 ;
V_128 . V_655 = F_76 (
V_30 -> V_5 [ V_653 ] ) ;
}
if ( V_30 -> V_5 [ V_656 ] ) {
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_128 . V_657 =
F_35 ( V_30 -> V_5 [ V_656 ] ) ;
if ( V_128 . V_657 > 127 )
return - V_16 ;
if ( V_128 . V_657 != 0 &&
! ( V_7 -> V_18 . V_265 & V_658 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_659 ] ) {
T_2 V_24 ;
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_24 = F_35 ( V_30 -> V_5 [ V_659 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_128 . V_660 = V_24 ;
if ( V_128 . V_660 != 0 &&
! ( V_7 -> V_18 . V_265 & V_661 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_463 ] ) {
V_35 = F_78 ( V_7 , V_30 , & V_128 . V_461 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_483 . V_55 ) {
V_128 . V_461 = V_17 -> V_483 ;
} else if ( ! F_142 ( V_7 , & V_128 ) )
return - V_16 ;
if ( ! F_84 ( & V_7 -> V_18 , & V_128 . V_461 ) )
return - V_16 ;
V_35 = F_147 ( V_17 -> V_18 , & V_128 . V_461 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 ) {
V_636 = F_148 ( V_128 . V_461 . V_464 ) ;
V_128 . V_662 = true ;
}
V_35 = F_149 ( V_7 , V_17 , V_17 -> V_132 ,
V_128 . V_461 . V_55 ,
V_663 ,
V_636 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_597 ] ) {
V_128 . V_596 = F_138 ( & V_7 -> V_18 , V_30 ) ;
if ( F_18 ( V_128 . V_596 ) )
return F_19 ( V_128 . V_596 ) ;
}
V_35 = F_150 ( V_7 , V_184 , & V_128 ) ;
if ( ! V_35 ) {
V_17 -> V_483 = V_128 . V_461 ;
V_17 -> V_481 = V_128 . V_481 ;
V_17 -> V_664 = V_128 . V_461 . V_55 ;
V_17 -> V_525 = V_128 . V_525 ;
memcpy ( V_17 -> V_527 , V_128 . V_527 , V_17 -> V_525 ) ;
}
F_42 ( V_128 . V_596 ) ;
return V_35 ;
}
static int F_151 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_606 V_128 ;
int V_35 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_480 ;
if ( ! V_7 -> V_319 -> V_665 )
return - V_480 ;
if ( ! V_17 -> V_481 )
return - V_16 ;
V_35 = F_141 ( V_30 -> V_5 , & V_128 ) ;
if ( V_35 )
return V_35 ;
return F_152 ( V_7 , V_184 , & V_128 ) ;
}
static int F_153 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
return F_154 ( V_7 , V_184 ) ;
}
static int F_155 ( struct V_29 * V_30 ,
enum V_246 V_132 ,
struct V_666 * V_128 )
{
struct V_4 * V_51 [ V_667 + 1 ] ;
struct V_4 * V_534 ;
int V_537 ;
V_534 = V_30 -> V_5 [ V_668 ] ;
if ( V_534 ) {
struct V_669 * V_670 ;
V_670 = F_24 ( V_534 ) ;
V_128 -> V_671 = V_670 -> V_672 ;
V_128 -> V_673 = V_670 -> V_674 ;
V_128 -> V_673 &= V_128 -> V_671 ;
if ( ( V_128 -> V_671 |
V_128 -> V_673 ) & F_148 ( V_675 ) )
return - V_16 ;
return 0 ;
}
V_534 = V_30 -> V_5 [ V_676 ] ;
if ( ! V_534 )
return 0 ;
if ( F_34 ( V_51 , V_667 ,
V_534 , V_677 ) )
return - V_16 ;
switch ( V_132 ) {
case V_133 :
case V_134 :
case V_135 :
V_128 -> V_671 = F_148 ( V_678 ) |
F_148 ( V_679 ) |
F_148 ( V_680 ) |
F_148 ( V_681 ) ;
break;
case V_139 :
case V_138 :
V_128 -> V_671 = F_148 ( V_678 ) |
F_148 ( V_682 ) ;
break;
case V_136 :
V_128 -> V_671 = F_148 ( V_683 ) |
F_148 ( V_681 ) |
F_148 ( V_678 ) ;
default:
return - V_16 ;
}
for ( V_537 = 1 ; V_537 <= V_667 ; V_537 ++ ) {
if ( V_51 [ V_537 ] ) {
V_128 -> V_673 |= ( 1 << V_537 ) ;
if ( V_537 > V_684 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_156 ( struct V_31 * V_53 , struct V_685 * V_30 ,
int V_45 )
{
struct V_4 * V_218 ;
V_22 V_238 ;
T_3 V_686 ;
V_218 = F_46 ( V_53 , V_45 ) ;
if ( ! V_218 )
return false ;
V_238 = F_157 ( V_30 ) ;
V_686 = V_238 < ( 1UL << 16 ) ? V_238 : 0 ;
if ( V_238 > 0 &&
F_29 ( V_53 , V_687 , V_238 ) )
return false ;
if ( V_686 > 0 &&
F_53 ( V_53 , V_688 , V_686 ) )
return false ;
if ( V_30 -> V_51 & V_689 ) {
if ( F_54 ( V_53 , V_690 , V_30 -> V_222 ) )
return false ;
if ( V_30 -> V_51 & V_691 &&
F_30 ( V_53 , V_692 ) )
return false ;
if ( V_30 -> V_51 & V_693 &&
F_30 ( V_53 , V_694 ) )
return false ;
} else if ( V_30 -> V_51 & V_695 ) {
if ( F_54 ( V_53 , V_696 , V_30 -> V_222 ) )
return false ;
if ( F_54 ( V_53 , V_697 , V_30 -> V_698 ) )
return false ;
if ( V_30 -> V_51 & V_691 &&
F_30 ( V_53 , V_692 ) )
return false ;
if ( V_30 -> V_51 & V_699 &&
F_30 ( V_53 , V_700 ) )
return false ;
if ( V_30 -> V_51 & V_701 &&
F_30 ( V_53 , V_702 ) )
return false ;
if ( V_30 -> V_51 & V_703 &&
F_30 ( V_53 , V_704 ) )
return false ;
if ( V_30 -> V_51 & V_693 &&
F_30 ( V_53 , V_694 ) )
return false ;
}
F_47 ( V_53 , V_218 ) ;
return true ;
}
static bool F_158 ( struct V_31 * V_53 , T_2 V_672 , T_6 * signal ,
int V_705 )
{
void * V_45 ;
int V_144 = 0 ;
if ( ! V_672 )
return true ;
V_45 = F_46 ( V_53 , V_705 ) ;
if ( ! V_45 )
return false ;
for ( V_144 = 0 ; V_144 < V_706 ; V_144 ++ ) {
if ( ! ( V_672 & F_148 ( V_144 ) ) )
continue;
if ( F_54 ( V_53 , V_144 , signal [ V_144 ] ) )
return false ;
}
F_47 ( V_53 , V_45 ) ;
return true ;
}
static int F_159 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_184 ,
const T_2 * V_576 , struct V_707 * V_708 )
{
void * V_257 ;
struct V_4 * V_709 , * V_710 ;
V_257 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_711 ) ;
if ( ! V_257 )
return - 1 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_576 ) ||
F_29 ( V_53 , V_268 , V_708 -> V_712 ) )
goto V_59;
V_709 = F_46 ( V_53 , V_713 ) ;
if ( ! V_709 )
goto V_59;
if ( ( V_708 -> V_714 & V_715 ) &&
F_29 ( V_53 , V_716 ,
V_708 -> V_717 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_718 ) &&
F_29 ( V_53 , V_719 ,
V_708 -> V_720 ) )
goto V_59;
if ( ( V_708 -> V_714 & ( V_721 |
V_722 ) ) &&
F_29 ( V_53 , V_723 ,
( V_22 ) V_708 -> V_724 ) )
goto V_59;
if ( ( V_708 -> V_714 & ( V_725 |
V_726 ) ) &&
F_29 ( V_53 , V_727 ,
( V_22 ) V_708 -> V_728 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_722 ) &&
F_102 ( V_53 , V_729 ,
V_708 -> V_724 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_726 ) &&
F_102 ( V_53 , V_730 ,
V_708 -> V_728 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_731 ) &&
F_53 ( V_53 , V_732 , V_708 -> V_733 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_734 ) &&
F_53 ( V_53 , V_735 , V_708 -> V_736 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_737 ) &&
F_54 ( V_53 , V_738 ,
V_708 -> V_739 ) )
goto V_59;
switch ( V_7 -> V_18 . V_740 ) {
case V_741 :
if ( ( V_708 -> V_714 & V_742 ) &&
F_54 ( V_53 , V_743 ,
V_708 -> signal ) )
goto V_59;
if ( ( V_708 -> V_714 & V_744 ) &&
F_54 ( V_53 , V_745 ,
V_708 -> V_746 ) )
goto V_59;
break;
default:
break;
}
if ( V_708 -> V_714 & V_747 ) {
if ( ! F_158 ( V_53 , V_708 -> V_748 ,
V_708 -> V_749 ,
V_750 ) )
goto V_59;
}
if ( V_708 -> V_714 & V_751 ) {
if ( ! F_158 ( V_53 , V_708 -> V_748 ,
V_708 -> V_752 ,
V_753 ) )
goto V_59;
}
if ( V_708 -> V_714 & V_754 ) {
if ( ! F_156 ( V_53 , & V_708 -> V_755 ,
V_756 ) )
goto V_59;
}
if ( V_708 -> V_714 & V_757 ) {
if ( ! F_156 ( V_53 , & V_708 -> V_758 ,
V_759 ) )
goto V_59;
}
if ( ( V_708 -> V_714 & V_760 ) &&
F_29 ( V_53 , V_761 ,
V_708 -> V_762 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_763 ) &&
F_29 ( V_53 , V_764 ,
V_708 -> V_765 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_766 ) &&
F_29 ( V_53 , V_767 ,
V_708 -> V_768 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_769 ) &&
F_29 ( V_53 , V_770 ,
V_708 -> V_771 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_772 ) &&
F_29 ( V_53 , V_773 ,
V_708 -> V_774 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_775 ) &&
F_29 ( V_53 , V_776 ,
V_708 -> V_777 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_778 ) &&
F_29 ( V_53 , V_779 ,
V_708 -> V_780 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_781 ) &&
F_29 ( V_53 , V_782 ,
V_708 -> V_783 ) )
goto V_59;
if ( V_708 -> V_714 & V_784 ) {
V_710 = F_46 ( V_53 , V_785 ) ;
if ( ! V_710 )
goto V_59;
if ( ( ( V_708 -> V_710 . V_51 & V_786 ) &&
F_30 ( V_53 , V_787 ) ) ||
( ( V_708 -> V_710 . V_51 & V_788 ) &&
F_30 ( V_53 , V_789 ) ) ||
( ( V_708 -> V_710 . V_51 & V_790 ) &&
F_30 ( V_53 , V_791 ) ) ||
F_54 ( V_53 , V_792 ,
V_708 -> V_710 . V_641 ) ||
F_53 ( V_53 , V_793 ,
V_708 -> V_710 . V_481 ) )
goto V_59;
F_47 ( V_53 , V_710 ) ;
}
if ( ( V_708 -> V_714 & V_794 ) &&
F_50 ( V_53 , V_795 ,
sizeof( struct V_669 ) ,
& V_708 -> V_670 ) )
goto V_59;
if ( ( V_708 -> V_714 & V_796 ) &&
F_102 ( V_53 , V_797 ,
V_708 -> V_798 ) )
goto V_59;
F_47 ( V_53 , V_709 ) ;
if ( ( V_708 -> V_714 & V_799 ) &&
F_50 ( V_53 , V_610 , V_708 -> V_800 ,
V_708 -> V_801 ) )
goto V_59;
return F_64 ( V_53 , V_257 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
static int F_160 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_707 V_708 ;
struct V_6 * V_184 ;
struct V_1 * V_17 ;
T_2 V_576 [ V_522 ] ;
int V_802 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_14 ( V_32 , V_34 , & V_184 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_803;
}
if ( ! V_184 -> V_319 -> V_804 ) {
V_35 = - V_480 ;
goto V_803;
}
while ( 1 ) {
memset ( & V_708 , 0 , sizeof( V_708 ) ) ;
V_35 = F_161 ( V_184 , V_17 -> V_19 , V_802 ,
V_576 , & V_708 ) ;
if ( V_35 == - V_583 )
break;
if ( V_35 )
goto V_803;
if ( F_159 ( V_32 ,
F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_440 , V_441 ,
V_184 , V_17 -> V_19 , V_576 ,
& V_708 ) < 0 )
goto V_532;
V_802 ++ ;
}
V_532:
V_34 -> args [ 2 ] = V_802 ;
V_35 = V_32 -> V_47 ;
V_803:
F_22 ( V_184 ) ;
return V_35 ;
}
static int F_162 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_707 V_708 ;
struct V_31 * V_53 ;
T_2 * V_576 = NULL ;
int V_35 ;
memset ( & V_708 , 0 , sizeof( V_708 ) ) ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
V_576 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( ! V_7 -> V_319 -> V_805 )
return - V_480 ;
V_35 = F_163 ( V_7 , V_184 , V_576 , & V_708 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_159 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_7 , V_184 , V_576 , & V_708 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_82 ;
}
return F_74 ( V_53 , V_30 ) ;
}
int F_164 ( struct V_18 * V_18 ,
struct V_666 * V_128 ,
enum V_806 V_807 )
{
if ( V_128 -> V_808 != - 1 )
return - V_16 ;
if ( V_128 -> V_809 )
return - V_16 ;
F_111 ( V_667 != 7 ) ;
switch ( V_807 ) {
case V_810 :
case V_811 :
if ( V_128 -> V_671 &
~ ( F_148 ( V_683 ) |
F_148 ( V_681 ) |
F_148 ( V_678 ) ) )
return - V_16 ;
break;
case V_812 :
case V_813 :
if ( ! ( V_128 -> V_673 & F_148 ( V_682 ) ) )
return - V_16 ;
V_128 -> V_671 &= ~ F_148 ( V_682 ) ;
break;
default:
if ( V_128 -> V_814 != V_815 )
return - V_16 ;
if ( V_128 -> V_777 )
return - V_16 ;
if ( V_128 -> V_816 & V_817 )
return - V_16 ;
}
if ( V_807 != V_812 &&
V_807 != V_813 ) {
if ( V_128 -> V_673 & F_148 ( V_682 ) )
return - V_16 ;
V_128 -> V_671 &= ~ F_148 ( V_682 ) ;
}
if ( V_807 != V_812 ) {
if ( V_128 -> V_816 & V_818 )
return - V_16 ;
if ( V_128 -> V_816 & V_819 )
return - V_16 ;
if ( V_128 -> V_820 )
return - V_16 ;
if ( V_128 -> V_821 || V_128 -> V_822 || V_128 -> V_823 )
return - V_16 ;
}
if ( V_807 != V_824 ) {
if ( V_128 -> V_825 )
return - V_16 ;
}
switch ( V_807 ) {
case V_826 :
if ( ! ( V_128 -> V_671 & F_148 ( V_678 ) ) )
return - V_480 ;
break;
case V_824 :
if ( V_128 -> V_671 &
~ ( F_148 ( V_678 ) |
F_148 ( V_683 ) |
F_148 ( V_827 ) |
F_148 ( V_679 ) |
F_148 ( V_680 ) |
F_148 ( V_681 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_265 & V_828 ) &&
V_128 -> V_671 &
( F_148 ( V_683 ) |
F_148 ( V_827 ) ) )
return - V_16 ;
break;
case V_829 :
case V_830 :
if ( V_128 -> V_671 & ~ F_148 ( V_678 ) )
return - V_16 ;
break;
case V_812 :
if ( V_128 -> V_671 & ~ ( F_148 ( V_678 ) |
F_148 ( V_680 ) ) )
return - V_16 ;
if ( V_128 -> V_673 & F_148 ( V_678 ) &&
! V_128 -> V_820 )
return - V_16 ;
break;
case V_813 :
return - V_16 ;
case V_810 :
if ( V_128 -> V_816 & V_817 )
return - V_16 ;
break;
case V_811 :
if ( V_128 -> V_814 != V_815 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_165 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_831 = V_30 -> V_5 [ V_832 ] ;
struct V_25 * V_833 ;
int V_436 ;
if ( ! V_831 )
return NULL ;
V_833 = F_10 ( F_92 ( V_30 ) , F_4 ( V_831 ) ) ;
if ( ! V_833 )
return F_3 ( - V_23 ) ;
if ( ! V_833 -> V_28 || V_833 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_436 = - V_16 ;
goto error;
}
if ( V_833 -> V_28 -> V_132 != V_134 &&
V_833 -> V_28 -> V_132 != V_133 &&
V_833 -> V_28 -> V_132 != V_135 ) {
V_436 = - V_16 ;
goto error;
}
if ( ! F_89 ( V_833 ) ) {
V_436 = - V_494 ;
goto error;
}
return V_833 ;
error:
F_12 ( V_833 ) ;
return F_3 ( V_436 ) ;
}
static int F_166 ( struct V_29 * V_30 ,
struct V_666 * V_128 )
{
struct V_4 * V_86 [ V_834 + 1 ] ;
struct V_4 * V_534 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_835 ] )
return 0 ;
V_534 = V_30 -> V_5 [ V_835 ] ;
V_35 = F_34 ( V_86 , V_834 , V_534 ,
V_836 ) ;
if ( V_35 )
return V_35 ;
if ( V_86 [ V_837 ] )
V_128 -> V_838 = F_35 (
V_86 [ V_837 ] ) ;
if ( V_128 -> V_838 & ~ V_839 )
return - V_16 ;
if ( V_86 [ V_840 ] )
V_128 -> V_841 = F_35 ( V_86 [ V_840 ] ) ;
if ( V_128 -> V_841 & ~ V_842 )
return - V_16 ;
V_128 -> V_816 |= V_818 ;
return 0 ;
}
static int F_167 ( struct V_29 * V_30 ,
struct V_666 * V_128 )
{
if ( V_30 -> V_5 [ V_843 ] )
V_128 -> V_809 = F_76 ( V_30 -> V_5 [ V_843 ] ) ;
if ( V_30 -> V_5 [ V_844 ] )
V_128 -> V_822 =
F_24 ( V_30 -> V_5 [ V_844 ] ) ;
if ( V_30 -> V_5 [ V_845 ] )
V_128 -> V_823 =
F_24 ( V_30 -> V_5 [ V_845 ] ) ;
return F_166 ( V_30 , V_128 ) ;
}
static int F_168 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_666 V_128 ;
T_2 * V_576 ;
int V_35 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_808 = - 1 ;
if ( ! V_7 -> V_319 -> V_846 )
return - V_480 ;
if ( V_30 -> V_5 [ V_847 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
V_576 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( V_30 -> V_5 [ V_848 ] ) {
V_128 . V_820 =
F_24 ( V_30 -> V_5 [ V_848 ] ) ;
V_128 . V_849 =
F_25 ( V_30 -> V_5 [ V_848 ] ) ;
}
if ( V_30 -> V_5 [ V_850 ] ) {
V_128 . V_851 =
F_76 ( V_30 -> V_5 [ V_850 ] ) ;
V_128 . V_816 |= V_819 ;
}
if ( V_30 -> V_5 [ V_852 ] ) {
V_128 . V_821 =
F_24 ( V_30 -> V_5 [ V_852 ] ) ;
V_128 . V_853 =
F_25 ( V_30 -> V_5 [ V_852 ] ) ;
}
if ( V_30 -> V_5 [ V_854 ] )
return - V_16 ;
if ( F_155 ( V_30 , V_184 -> V_28 -> V_132 , & V_128 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_855 ] ) {
V_128 . V_814 =
F_35 ( V_30 -> V_5 [ V_855 ] ) ;
if ( V_128 . V_814 >= V_856 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_857 ] ) {
V_128 . V_739 =
F_35 ( V_30 -> V_5 [ V_857 ] ) ;
if ( V_128 . V_739 >= V_858 )
return - V_16 ;
V_128 . V_816 |= V_817 ;
}
if ( V_30 -> V_5 [ V_859 ] ) {
enum V_860 V_861 = F_4 (
V_30 -> V_5 [ V_859 ] ) ;
if ( V_861 <= V_862 ||
V_861 > V_863 )
return - V_16 ;
V_128 . V_777 = V_861 ;
}
V_35 = F_167 ( V_30 , & V_128 ) ;
if ( V_35 )
return V_35 ;
V_128 . V_825 = F_165 ( V_30 , V_7 ) ;
if ( F_18 ( V_128 . V_825 ) )
return F_19 ( V_128 . V_825 ) ;
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
V_35 = - V_480 ;
goto V_864;
}
V_35 = F_169 ( V_7 , V_184 , V_576 , & V_128 ) ;
V_864:
if ( V_128 . V_825 )
F_12 ( V_128 . V_825 ) ;
return V_35 ;
}
static int F_170 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_666 V_128 ;
T_2 * V_576 = NULL ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ! V_7 -> V_319 -> V_345 )
return - V_480 ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_854 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_848 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_847 ] &&
! V_30 -> V_5 [ V_843 ] )
return - V_16 ;
V_576 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_128 . V_820 =
F_24 ( V_30 -> V_5 [ V_848 ] ) ;
V_128 . V_849 =
F_25 ( V_30 -> V_5 [ V_848 ] ) ;
V_128 . V_808 =
F_76 ( V_30 -> V_5 [ V_854 ] ) ;
if ( V_30 -> V_5 [ V_843 ] )
V_128 . V_809 = F_76 ( V_30 -> V_5 [ V_843 ] ) ;
else
V_128 . V_809 = F_76 ( V_30 -> V_5 [ V_847 ] ) ;
if ( ! V_128 . V_809 || V_128 . V_809 > V_865 )
return - V_16 ;
if ( V_30 -> V_5 [ V_850 ] ) {
V_128 . V_851 =
F_76 ( V_30 -> V_5 [ V_850 ] ) ;
V_128 . V_816 |= V_819 ;
}
if ( V_30 -> V_5 [ V_852 ] ) {
V_128 . V_821 =
F_24 ( V_30 -> V_5 [ V_852 ] ) ;
V_128 . V_853 =
F_25 ( V_30 -> V_5 [ V_852 ] ) ;
}
if ( V_30 -> V_5 [ V_844 ] )
V_128 . V_822 =
F_24 ( V_30 -> V_5 [ V_844 ] ) ;
if ( V_30 -> V_5 [ V_845 ] )
V_128 . V_823 =
F_24 ( V_30 -> V_5 [ V_845 ] ) ;
if ( V_30 -> V_5 [ V_855 ] ) {
V_128 . V_814 =
F_35 ( V_30 -> V_5 [ V_855 ] ) ;
if ( V_128 . V_814 >= V_856 )
return - V_16 ;
}
V_35 = F_166 ( V_30 , & V_128 ) ;
if ( V_35 )
return V_35 ;
if ( F_155 ( V_30 , V_184 -> V_28 -> V_132 , & V_128 ) )
return - V_16 ;
F_111 ( V_667 != 7 ) ;
switch ( V_184 -> V_28 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
if ( ! ( V_7 -> V_18 . V_51 & V_295 ) ||
! ( V_128 . V_673 & F_148 ( V_680 ) ) )
V_128 . V_816 &= ~ V_818 ;
if ( ( V_128 . V_673 & F_148 ( V_682 ) ) ||
V_30 -> V_5 [ V_843 ] )
return - V_16 ;
V_128 . V_671 &= ~ F_148 ( V_682 ) ;
if ( ! ( V_7 -> V_18 . V_265 &
V_828 ) &&
V_128 . V_671 &
( F_148 ( V_683 ) |
F_148 ( V_827 ) ) )
return - V_16 ;
V_128 . V_825 = F_165 ( V_30 , V_7 ) ;
if ( F_18 ( V_128 . V_825 ) )
return F_19 ( V_128 . V_825 ) ;
break;
case V_136 :
V_128 . V_816 &= ~ V_818 ;
if ( V_128 . V_671 & F_148 ( V_827 ) )
return - V_16 ;
if ( ( V_128 . V_673 & F_148 ( V_682 ) ) ||
V_30 -> V_5 [ V_843 ] )
return - V_16 ;
break;
case V_138 :
case V_139 :
V_128 . V_816 &= ~ V_818 ;
if ( V_128 . V_671 &
( F_148 ( V_827 ) |
F_148 ( V_683 ) ) )
return - V_16 ;
if ( ! ( V_128 . V_673 & F_148 ( V_682 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_299 ) )
return - V_480 ;
if ( ! ( V_7 -> V_18 . V_51 & V_301 ) )
return - V_480 ;
V_128 . V_671 &= ~ F_148 ( V_678 ) ;
break;
default:
return - V_480 ;
}
V_35 = F_171 ( V_7 , V_184 , V_576 , & V_128 ) ;
if ( V_128 . V_825 )
F_12 ( V_128 . V_825 ) ;
return V_35 ;
}
static int F_172 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 * V_576 = NULL ;
if ( V_30 -> V_5 [ V_485 ] )
V_576 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_134 &&
V_184 -> V_28 -> V_132 != V_136 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_866 )
return - V_480 ;
return F_173 ( V_7 , V_184 , V_576 ) ;
}
static int F_174 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_184 ,
T_2 * V_867 , T_2 * V_868 ,
struct V_869 * V_870 )
{
void * V_257 ;
struct V_4 * V_871 ;
V_257 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_711 ) ;
if ( ! V_257 )
return - 1 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_867 ) ||
F_50 ( V_53 , V_872 , V_522 , V_868 ) ||
F_29 ( V_53 , V_268 , V_870 -> V_712 ) )
goto V_59;
V_871 = F_46 ( V_53 , V_873 ) ;
if ( ! V_871 )
goto V_59;
if ( ( V_870 -> V_714 & V_874 ) &&
F_29 ( V_53 , V_875 ,
V_870 -> V_876 ) )
goto V_59;
if ( ( ( V_870 -> V_714 & V_877 ) &&
F_29 ( V_53 , V_878 , V_870 -> V_879 ) ) ||
( ( V_870 -> V_714 & V_880 ) &&
F_29 ( V_53 , V_881 ,
V_870 -> V_882 ) ) ||
( ( V_870 -> V_714 & V_883 ) &&
F_29 ( V_53 , V_884 ,
V_870 -> V_885 ) ) ||
( ( V_870 -> V_714 & V_886 ) &&
F_54 ( V_53 , V_887 ,
V_870 -> V_51 ) ) ||
( ( V_870 -> V_714 & V_888 ) &&
F_29 ( V_53 , V_889 ,
V_870 -> V_890 ) ) ||
( ( V_870 -> V_714 & V_891 ) &&
F_54 ( V_53 , V_892 ,
V_870 -> V_893 ) ) )
goto V_59;
F_47 ( V_53 , V_871 ) ;
return F_64 ( V_53 , V_257 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
static int F_175 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_869 V_870 ;
struct V_6 * V_184 ;
struct V_1 * V_17 ;
T_2 V_867 [ V_522 ] ;
T_2 V_868 [ V_522 ] ;
int V_894 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_14 ( V_32 , V_34 , & V_184 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_184 -> V_319 -> V_895 ) {
V_35 = - V_480 ;
goto V_803;
}
if ( V_17 -> V_132 != V_136 ) {
V_35 = - V_480 ;
goto V_803;
}
while ( 1 ) {
V_35 = F_176 ( V_184 , V_17 -> V_19 , V_894 , V_867 ,
V_868 , & V_870 ) ;
if ( V_35 == - V_583 )
break;
if ( V_35 )
goto V_803;
if ( F_174 ( V_32 , F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_440 , V_441 ,
V_17 -> V_19 , V_867 , V_868 ,
& V_870 ) < 0 )
goto V_532;
V_894 ++ ;
}
V_532:
V_34 -> args [ 2 ] = V_894 ;
V_35 = V_32 -> V_47 ;
V_803:
F_22 ( V_184 ) ;
return V_35 ;
}
static int F_177 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
int V_35 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_869 V_870 ;
struct V_31 * V_53 ;
T_2 * V_867 = NULL ;
T_2 V_868 [ V_522 ] ;
memset ( & V_870 , 0 , sizeof( V_870 ) ) ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
V_867 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( ! V_7 -> V_319 -> V_896 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_136 )
return - V_480 ;
V_35 = F_178 ( V_7 , V_184 , V_867 , V_868 , & V_870 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
if ( F_174 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_184 , V_867 , V_868 , & V_870 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_82 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_179 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 * V_867 = NULL ;
T_2 * V_868 = NULL ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_872 ] )
return - V_16 ;
V_867 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_868 = F_24 ( V_30 -> V_5 [ V_872 ] ) ;
if ( ! V_7 -> V_319 -> V_897 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_136 )
return - V_480 ;
return F_180 ( V_7 , V_184 , V_867 , V_868 ) ;
}
static int F_181 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 * V_867 = NULL ;
T_2 * V_868 = NULL ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_872 ] )
return - V_16 ;
V_867 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_868 = F_24 ( V_30 -> V_5 [ V_872 ] ) ;
if ( ! V_7 -> V_319 -> V_347 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_136 )
return - V_480 ;
return F_182 ( V_7 , V_184 , V_867 , V_868 ) ;
}
static int F_183 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 * V_867 = NULL ;
if ( V_30 -> V_5 [ V_485 ] )
V_867 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( ! V_7 -> V_319 -> V_898 )
return - V_480 ;
return F_184 ( V_7 , V_184 , V_867 ) ;
}
static int F_185 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_899 V_128 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_900 = - 1 ;
V_128 . V_901 = - 1 ;
V_128 . V_902 = - 1 ;
V_128 . V_903 = - 1 ;
V_128 . V_904 = - 1 ;
V_128 . V_657 = - 1 ;
V_128 . V_660 = - 1 ;
if ( V_30 -> V_5 [ V_905 ] )
V_128 . V_900 =
F_35 ( V_30 -> V_5 [ V_905 ] ) ;
if ( V_30 -> V_5 [ V_906 ] )
V_128 . V_901 =
F_35 ( V_30 -> V_5 [ V_906 ] ) ;
if ( V_30 -> V_5 [ V_907 ] )
V_128 . V_902 =
F_35 ( V_30 -> V_5 [ V_907 ] ) ;
if ( V_30 -> V_5 [ V_908 ] ) {
V_128 . V_909 =
F_24 ( V_30 -> V_5 [ V_908 ] ) ;
V_128 . V_910 =
F_25 ( V_30 -> V_5 [ V_908 ] ) ;
}
if ( V_30 -> V_5 [ V_911 ] )
V_128 . V_903 = ! ! F_35 ( V_30 -> V_5 [ V_911 ] ) ;
if ( V_30 -> V_5 [ V_912 ] )
V_128 . V_904 =
F_76 ( V_30 -> V_5 [ V_912 ] ) ;
if ( V_30 -> V_5 [ V_656 ] ) {
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_128 . V_657 =
F_186 ( V_30 -> V_5 [ V_656 ] ) ;
if ( V_128 . V_657 < 0 )
return - V_16 ;
if ( V_128 . V_657 != 0 &&
! ( V_7 -> V_18 . V_265 & V_658 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_659 ] ) {
T_2 V_24 ;
if ( V_184 -> V_28 -> V_132 != V_135 )
return - V_16 ;
V_24 = F_35 ( V_30 -> V_5 [ V_659 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_128 . V_660 = V_24 ;
if ( V_128 . V_660 &&
! ( V_7 -> V_18 . V_265 & V_661 ) )
return - V_16 ;
}
if ( ! V_7 -> V_319 -> V_351 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_133 &&
V_184 -> V_28 -> V_132 != V_135 )
return - V_480 ;
return F_187 ( V_7 , V_184 , & V_128 ) ;
}
static int F_188 ( struct V_4 * V_86 [] ,
struct V_913 * V_914 )
{
struct V_915 * V_916 = & V_914 -> V_916 ;
struct V_917 * V_918 = & V_914 -> V_918 ;
if ( ! V_86 [ V_919 ] )
return - V_16 ;
if ( ! V_86 [ V_920 ] )
return - V_16 ;
if ( ! V_86 [ V_921 ] )
return - V_16 ;
if ( ! V_86 [ V_922 ] )
return - V_16 ;
if ( ! V_86 [ V_923 ] )
return - V_16 ;
V_914 -> V_51 = F_4 ( V_86 [ V_919 ] ) ;
V_916 -> V_924 =
F_4 ( V_86 [ V_920 ] ) ;
V_916 -> V_925 =
F_4 ( V_86 [ V_921 ] ) ;
V_916 -> V_926 =
F_4 ( V_86 [ V_922 ] ) ;
V_918 -> V_927 =
F_4 ( V_86 [ V_923 ] ) ;
if ( V_86 [ V_928 ] )
V_918 -> V_929 =
F_4 ( V_86 [ V_928 ] ) ;
return 0 ;
}
static int F_189 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
int V_930 ;
char * V_129 = NULL ;
enum V_931 V_932 ;
if ( F_190 ( ! F_191 ( V_933 ) ) )
return - V_934 ;
if ( ! V_30 -> V_5 [ V_935 ] )
return - V_16 ;
V_129 = F_24 ( V_30 -> V_5 [ V_935 ] ) ;
if ( V_30 -> V_5 [ V_936 ] )
V_932 =
F_4 ( V_30 -> V_5 [ V_936 ] ) ;
else
V_932 = V_937 ;
switch ( V_932 ) {
case V_937 :
case V_938 :
break;
default:
return - V_16 ;
}
V_930 = F_192 ( V_129 , V_932 ) ;
return V_930 ;
}
static int F_193 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_939 V_940 ;
int V_35 = 0 ;
void * V_257 ;
struct V_4 * V_871 ;
struct V_31 * V_53 ;
if ( V_17 -> V_132 != V_136 )
return - V_480 ;
if ( ! V_7 -> V_319 -> V_941 )
return - V_480 ;
F_110 ( V_17 ) ;
if ( ! V_17 -> V_942 )
memcpy ( & V_940 , & V_943 , sizeof( V_940 ) ) ;
else
V_35 = F_194 ( V_7 , V_184 , & V_940 ) ;
F_112 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_944 ) ;
if ( ! V_257 )
goto V_532;
V_871 = F_46 ( V_53 , V_945 ) ;
if ( ! V_871 )
goto V_59;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_53 ( V_53 , V_946 ,
V_940 . V_947 ) ||
F_53 ( V_53 , V_948 ,
V_940 . V_949 ) ||
F_53 ( V_53 , V_950 ,
V_940 . V_951 ) ||
F_53 ( V_53 , V_952 ,
V_940 . V_953 ) ||
F_54 ( V_53 , V_954 ,
V_940 . V_955 ) ||
F_54 ( V_53 , V_956 ,
V_940 . V_957 ) ||
F_54 ( V_53 , V_958 ,
V_940 . V_959 ) ||
F_54 ( V_53 , V_960 ,
V_940 . V_961 ) ||
F_29 ( V_53 , V_962 ,
V_940 . V_963 ) ||
F_54 ( V_53 , V_964 ,
V_940 . V_965 ) ||
F_29 ( V_53 , V_966 ,
V_940 . V_967 ) ||
F_53 ( V_53 , V_968 ,
V_940 . V_969 ) ||
F_29 ( V_53 , V_970 ,
V_940 . V_971 ) ||
F_53 ( V_53 , V_972 ,
V_940 . V_973 ) ||
F_53 ( V_53 , V_974 ,
V_940 . V_975 ) ||
F_53 ( V_53 , V_976 ,
V_940 . V_977 ) ||
F_54 ( V_53 , V_978 ,
V_940 . V_979 ) ||
F_53 ( V_53 , V_980 ,
V_940 . V_981 ) ||
F_54 ( V_53 , V_982 ,
V_940 . V_983 ) ||
F_54 ( V_53 , V_984 ,
V_940 . V_985 ) ||
F_29 ( V_53 , V_986 ,
V_940 . V_987 ) ||
F_29 ( V_53 , V_988 ,
V_940 . V_904 ) ||
F_29 ( V_53 , V_989 ,
V_940 . V_990 ) ||
F_53 ( V_53 , V_991 ,
V_940 . V_992 ) ||
F_53 ( V_53 , V_993 ,
V_940 . V_994 ) ||
F_29 ( V_53 , V_995 ,
V_940 . V_996 ) ||
F_53 ( V_53 , V_997 ,
V_940 . V_998 ) ||
F_29 ( V_53 , V_999 ,
V_940 . V_1000 ) )
goto V_59;
F_47 ( V_53 , V_871 ) ;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
V_532:
F_73 ( V_53 ) ;
return - V_82 ;
}
static int F_195 ( struct V_29 * V_30 ,
struct V_939 * V_1001 ,
V_22 * V_1002 )
{
struct V_4 * V_86 [ V_1003 + 1 ] ;
V_22 V_672 = 0 ;
#define F_196 ( V_86 , V_1001 , T_7 , T_8 , V_159 , V_672 , V_45 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_945 ] )
return - V_16 ;
if ( F_34 ( V_86 , V_1003 ,
V_30 -> V_5 [ V_945 ] ,
V_1004 ) )
return - V_16 ;
F_111 ( V_1003 > 32 ) ;
F_196 ( V_86 , V_1001 , V_947 , 1 , 255 ,
V_672 , V_946 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_949 , 1 , 255 ,
V_672 , V_948 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_951 , 1 , 255 ,
V_672 , V_950 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_953 , 0 , 255 ,
V_672 , V_952 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_955 , 0 , 16 ,
V_672 , V_954 ,
F_35 ) ;
F_196 ( V_86 , V_1001 , V_957 , 1 , 255 ,
V_672 , V_956 , F_35 ) ;
F_196 ( V_86 , V_1001 , V_959 , 1 , 255 ,
V_672 , V_958 ,
F_35 ) ;
F_196 ( V_86 , V_1001 , V_961 , 0 , 1 ,
V_672 , V_960 ,
F_35 ) ;
F_196 ( V_86 , V_1001 , V_963 ,
1 , 255 , V_672 ,
V_962 ,
F_4 ) ;
F_196 ( V_86 , V_1001 , V_965 , 0 , 255 ,
V_672 , V_964 ,
F_35 ) ;
F_196 ( V_86 , V_1001 , V_967 , 1 , 65535 ,
V_672 , V_966 ,
F_4 ) ;
F_196 ( V_86 , V_1001 , V_969 , 1 , 65535 ,
V_672 , V_968 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_971 ,
1 , 65535 , V_672 ,
V_970 ,
F_4 ) ;
F_196 ( V_86 , V_1001 , V_973 ,
1 , 65535 , V_672 ,
V_972 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_975 ,
1 , 65535 , V_672 ,
V_974 ,
F_76 ) ;
F_196 ( V_86 , V_1001 ,
V_977 ,
1 , 65535 , V_672 ,
V_976 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_979 , 0 , 4 ,
V_672 , V_978 ,
F_35 ) ;
F_196 ( V_86 , V_1001 , V_981 , 1 , 65535 ,
V_672 , V_980 ,
F_76 ) ;
F_196 ( V_86 , V_1001 ,
V_983 , 0 , 1 ,
V_672 , V_982 ,
F_35 ) ;
F_196 ( V_86 , V_1001 , V_985 , 0 , 1 ,
V_672 , V_984 ,
F_35 ) ;
F_196 ( V_86 , V_1001 , V_987 , - 255 , 0 ,
V_672 , V_986 ,
V_1005 ) ;
F_196 ( V_86 , V_1001 , V_904 , 0 , 16 ,
V_672 , V_988 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_990 ,
1 , 65535 , V_672 ,
V_989 ,
F_4 ) ;
F_196 ( V_86 , V_1001 , V_992 , 1 , 65535 ,
V_672 , V_991 ,
F_76 ) ;
F_196 ( V_86 , V_1001 ,
V_994 ,
1 , 65535 , V_672 ,
V_993 ,
F_76 ) ;
F_196 ( V_86 , V_1001 , V_996 ,
V_1006 ,
V_863 ,
V_672 , V_995 ,
F_4 ) ;
F_196 ( V_86 , V_1001 , V_998 ,
0 , 65535 , V_672 ,
V_997 , F_76 ) ;
F_196 ( V_86 , V_1001 , V_1000 , 1 , 0xffffffff ,
V_672 , V_999 ,
F_4 ) ;
if ( V_1002 )
* V_1002 = V_672 ;
return 0 ;
#undef F_196
}
static int F_197 ( struct V_29 * V_30 ,
struct V_1007 * V_1008 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_4 * V_86 [ V_1009 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1010 ] )
return - V_16 ;
if ( F_34 ( V_86 , V_1009 ,
V_30 -> V_5 [ V_1010 ] ,
V_1011 ) )
return - V_16 ;
if ( V_86 [ V_1012 ] )
V_1008 -> V_1013 =
( F_35 ( V_86 [ V_1012 ] ) ) ?
V_1014 :
V_1015 ;
if ( V_86 [ V_1016 ] )
V_1008 -> V_1017 =
( F_35 ( V_86 [ V_1016 ] ) ) ?
V_1018 :
V_1019 ;
if ( V_86 [ V_1020 ] )
V_1008 -> V_1021 =
( F_35 ( V_86 [ V_1020 ] ) ) ?
V_1022 :
V_1023 ;
if ( V_86 [ V_1024 ] ) {
struct V_4 * V_1025 =
V_86 [ V_1024 ] ;
if ( ! F_23 ( V_1025 ) )
return - V_16 ;
V_1008 -> V_1026 = F_24 ( V_1025 ) ;
V_1008 -> V_1027 = F_25 ( V_1025 ) ;
}
if ( V_86 [ V_1028 ] &&
! ( V_7 -> V_18 . V_265 & V_1029 ) )
return - V_16 ;
V_1008 -> V_1030 = F_198 ( V_86 [ V_1028 ] ) ;
V_1008 -> V_1031 = F_198 ( V_86 [ V_1032 ] ) ;
V_1008 -> V_1033 = F_198 ( V_86 [ V_1034 ] ) ;
if ( V_1008 -> V_1033 )
V_1008 -> V_1030 = true ;
if ( V_86 [ V_1035 ] ) {
if ( ! V_1008 -> V_1030 )
return - V_16 ;
V_1008 -> V_1036 =
F_35 ( V_86 [ V_1035 ] ) ;
}
return 0 ;
}
static int F_199 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_939 V_1001 ;
V_22 V_672 ;
int V_35 ;
if ( V_17 -> V_132 != V_136 )
return - V_480 ;
if ( ! V_7 -> V_319 -> V_349 )
return - V_480 ;
V_35 = F_195 ( V_30 , & V_1001 , & V_672 ) ;
if ( V_35 )
return V_35 ;
F_110 ( V_17 ) ;
if ( ! V_17 -> V_942 )
V_35 = - V_141 ;
if ( ! V_35 )
V_35 = F_200 ( V_7 , V_184 , V_672 , & V_1001 ) ;
F_112 ( V_17 ) ;
return V_35 ;
}
static int F_201 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1037 * V_1038 ;
struct V_31 * V_53 ;
void * V_257 = NULL ;
struct V_4 * V_1039 ;
unsigned int V_144 ;
if ( ! V_933 )
return - V_16 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_82 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_1040 ) ;
if ( ! V_257 )
goto V_1041;
if ( F_202 () &&
F_29 ( V_53 , V_936 ,
V_938 ) )
goto V_59;
F_203 () ;
V_1038 = F_204 ( V_933 ) ;
if ( F_58 ( V_53 , V_935 , V_1038 -> V_1042 ) ||
( V_1038 -> V_1043 &&
F_54 ( V_53 , V_1044 , V_1038 -> V_1043 ) ) )
goto V_1045;
V_1039 = F_46 ( V_53 , V_1046 ) ;
if ( ! V_1039 )
goto V_1045;
for ( V_144 = 0 ; V_144 < V_1038 -> V_1047 ; V_144 ++ ) {
struct V_4 * V_1048 ;
const struct V_913 * V_914 ;
const struct V_915 * V_916 ;
const struct V_917 * V_918 ;
V_914 = & V_1038 -> V_1049 [ V_144 ] ;
V_916 = & V_914 -> V_916 ;
V_918 = & V_914 -> V_918 ;
V_1048 = F_46 ( V_53 , V_144 ) ;
if ( ! V_1048 )
goto V_1045;
if ( F_29 ( V_53 , V_919 ,
V_914 -> V_51 ) ||
F_29 ( V_53 , V_920 ,
V_916 -> V_924 ) ||
F_29 ( V_53 , V_921 ,
V_916 -> V_925 ) ||
F_29 ( V_53 , V_922 ,
V_916 -> V_926 ) ||
F_29 ( V_53 , V_928 ,
V_918 -> V_929 ) ||
F_29 ( V_53 , V_923 ,
V_918 -> V_927 ) )
goto V_1045;
F_47 ( V_53 , V_1048 ) ;
}
F_205 () ;
F_47 ( V_53 , V_1039 ) ;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_1045:
F_205 () ;
V_59:
F_65 ( V_53 , V_257 ) ;
V_1041:
F_73 ( V_53 ) ;
return - V_435 ;
}
static int F_206 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_86 [ V_1050 + 1 ] ;
struct V_4 * V_1048 ;
char * V_1042 = NULL ;
int V_1051 = 0 , V_930 = 0 ;
V_22 V_1052 = 0 , V_1053 = 0 , V_1054 ;
T_2 V_1043 = 0 ;
struct V_1037 * V_1055 = NULL ;
if ( ! V_30 -> V_5 [ V_935 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1046 ] )
return - V_16 ;
V_1042 = F_24 ( V_30 -> V_5 [ V_935 ] ) ;
if ( V_30 -> V_5 [ V_1044 ] )
V_1043 = F_35 ( V_30 -> V_5 [ V_1044 ] ) ;
F_40 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1052 ++ ;
if ( V_1052 > V_1056 )
return - V_16 ;
}
V_1054 = sizeof( struct V_1037 ) +
V_1052 * sizeof( struct V_913 ) ;
V_1055 = F_39 ( V_1054 , V_126 ) ;
if ( ! V_1055 )
return - V_127 ;
V_1055 -> V_1047 = V_1052 ;
V_1055 -> V_1042 [ 0 ] = V_1042 [ 0 ] ;
V_1055 -> V_1042 [ 1 ] = V_1042 [ 1 ] ;
if ( F_207 ( V_1043 ) )
V_1055 -> V_1043 = V_1043 ;
F_40 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_94 ( V_86 , V_1050 ,
F_24 ( V_1048 ) , F_25 ( V_1048 ) ,
V_1057 ) ;
V_930 = F_188 ( V_86 , & V_1055 -> V_1049 [ V_1053 ] ) ;
if ( V_930 )
goto V_1058;
V_1053 ++ ;
if ( V_1053 > V_1056 ) {
V_930 = - V_16 ;
goto V_1058;
}
}
V_930 = F_208 ( V_1055 ) ;
V_1055 = NULL ;
V_1058:
F_42 ( V_1055 ) ;
return V_930 ;
}
static int F_209 ( struct V_4 * V_1059 )
{
struct V_4 * V_1060 , * V_1061 ;
int V_334 = 0 , V_1062 , V_1063 ;
F_40 (attr1, freqs, tmp1) {
V_334 ++ ;
F_40 (attr2, freqs, tmp2)
if ( V_1060 != V_1061 &&
F_4 ( V_1060 ) == F_4 ( V_1061 ) )
return 0 ;
}
return V_334 ;
}
static int F_210 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
struct V_1064 * V_1065 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1066 = 0 , V_334 , V_144 ;
T_10 V_1027 ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_319 -> V_1067 )
return - V_480 ;
if ( V_7 -> V_1068 ) {
V_35 = - V_482 ;
goto V_1069;
}
if ( V_30 -> V_5 [ V_1070 ] ) {
V_334 = F_209 (
V_30 -> V_5 [ V_1070 ] ) ;
if ( ! V_334 ) {
V_35 = - V_16 ;
goto V_1069;
}
} else {
enum V_263 V_264 ;
V_334 = 0 ;
for ( V_264 = 0 ; V_264 < V_330 ; V_264 ++ )
if ( V_18 -> V_331 [ V_264 ] )
V_334 += V_18 -> V_331 [ V_264 ] -> V_334 ;
}
if ( V_30 -> V_5 [ V_1071 ] )
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1066 ++ ;
if ( V_1066 > V_18 -> V_282 ) {
V_35 = - V_16 ;
goto V_1069;
}
if ( V_30 -> V_5 [ V_610 ] )
V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
else
V_1027 = 0 ;
if ( V_1027 > V_18 -> V_286 ) {
V_35 = - V_16 ;
goto V_1069;
}
V_1065 = F_39 ( sizeof( * V_1065 )
+ sizeof( * V_1065 -> V_1072 ) * V_1066
+ sizeof( * V_1065 -> V_335 ) * V_334
+ V_1027 , V_126 ) ;
if ( ! V_1065 ) {
V_35 = - V_127 ;
goto V_1069;
}
if ( V_1066 )
V_1065 -> V_1072 = ( void * ) & V_1065 -> V_335 [ V_334 ] ;
V_1065 -> V_1066 = V_1066 ;
if ( V_1027 ) {
if ( V_1065 -> V_1072 )
V_1065 -> V_1026 = ( void * ) ( V_1065 -> V_1072 + V_1066 ) ;
else
V_1065 -> V_1026 = ( void * ) ( V_1065 -> V_335 + V_334 ) ;
}
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1070 ] ) {
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_79 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1073;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1065 -> V_335 [ V_144 ] = V_55 ;
V_144 ++ ;
}
} else {
enum V_263 V_264 ;
for ( V_264 = 0 ; V_264 < V_330 ; V_264 ++ ) {
int V_146 ;
if ( ! V_18 -> V_331 [ V_264 ] )
continue;
for ( V_146 = 0 ; V_146 < V_18 -> V_331 [ V_264 ] -> V_334 ; V_146 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_331 [ V_264 ] -> V_335 [ V_146 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1065 -> V_335 [ V_144 ] = V_55 ;
V_144 ++ ;
}
}
}
if ( ! V_144 ) {
V_35 = - V_16 ;
goto V_1073;
}
V_1065 -> V_334 = V_144 ;
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1071 ] ) {
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_25 ( V_45 ) > V_551 ) {
V_35 = - V_16 ;
goto V_1073;
}
V_1065 -> V_1072 [ V_144 ] . V_525 = F_25 ( V_45 ) ;
memcpy ( V_1065 -> V_1072 [ V_144 ] . V_527 , F_24 ( V_45 ) , F_25 ( V_45 ) ) ;
V_144 ++ ;
}
}
if ( V_30 -> V_5 [ V_610 ] ) {
V_1065 -> V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
memcpy ( ( void * ) V_1065 -> V_1026 ,
F_24 ( V_30 -> V_5 [ V_610 ] ) ,
V_1065 -> V_1027 ) ;
}
for ( V_144 = 0 ; V_144 < V_330 ; V_144 ++ )
if ( V_18 -> V_331 [ V_144 ] )
V_1065 -> V_1074 [ V_144 ] =
( 1 << V_18 -> V_331 [ V_144 ] -> V_235 ) - 1 ;
if ( V_30 -> V_5 [ V_1075 ] ) {
F_40 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_263 V_264 = F_211 ( V_45 ) ;
if ( V_264 < 0 || V_264 >= V_330 ) {
V_35 = - V_16 ;
goto V_1073;
}
V_35 = F_212 ( V_18 -> V_331 [ V_264 ] ,
F_24 ( V_45 ) ,
F_25 ( V_45 ) ,
& V_1065 -> V_1074 [ V_264 ] ) ;
if ( V_35 )
goto V_1073;
}
}
if ( V_30 -> V_5 [ V_1076 ] ) {
V_1065 -> V_51 = F_4 (
V_30 -> V_5 [ V_1076 ] ) ;
if ( ( ( V_1065 -> V_51 & V_1077 ) &&
! ( V_18 -> V_265 & V_1078 ) ) ||
( ( V_1065 -> V_51 & V_1079 ) &&
! ( V_18 -> V_265 & V_1080 ) ) ) {
V_35 = - V_480 ;
goto V_1073;
}
}
V_1065 -> V_1081 =
F_198 ( V_30 -> V_5 [ V_1082 ] ) ;
V_1065 -> V_17 = V_17 ;
V_1065 -> V_18 = & V_7 -> V_18 ;
V_1065 -> V_1083 = V_1084 ;
V_7 -> V_1068 = V_1065 ;
V_35 = F_213 ( V_7 , V_1065 ) ;
if ( ! V_35 ) {
F_214 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_215 ( V_17 -> V_19 ) ;
} else {
V_1073:
V_7 -> V_1068 = NULL ;
F_42 ( V_1065 ) ;
}
V_1069:
return V_35 ;
}
static int F_216 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1085 * V_1065 ;
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1066 = 0 , V_1086 = 0 , V_334 , V_144 ;
V_22 V_1087 ;
enum V_263 V_264 ;
T_10 V_1027 ;
struct V_4 * V_86 [ V_1088 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_390 ) ||
! V_7 -> V_319 -> V_391 )
return - V_480 ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1089 ] )
return - V_16 ;
V_1087 = F_4 ( V_30 -> V_5 [ V_1089 ] ) ;
if ( V_1087 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_1070 ] ) {
V_334 = F_209 (
V_30 -> V_5 [ V_1070 ] ) ;
if ( ! V_334 )
return - V_16 ;
} else {
V_334 = 0 ;
for ( V_264 = 0 ; V_264 < V_330 ; V_264 ++ )
if ( V_18 -> V_331 [ V_264 ] )
V_334 += V_18 -> V_331 [ V_264 ] -> V_334 ;
}
if ( V_30 -> V_5 [ V_1071 ] )
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1066 ++ ;
if ( V_1066 > V_18 -> V_284 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1090 ] )
F_40 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_1086 ++ ;
if ( V_1086 > V_18 -> V_290 )
return - V_16 ;
if ( V_30 -> V_5 [ V_610 ] )
V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
else
V_1027 = 0 ;
if ( V_1027 > V_18 -> V_288 )
return - V_16 ;
if ( V_7 -> V_1091 ) {
V_35 = - V_934 ;
goto V_532;
}
V_1065 = F_39 ( sizeof( * V_1065 )
+ sizeof( * V_1065 -> V_1072 ) * V_1066
+ sizeof( * V_1065 -> V_1092 ) * V_1086
+ sizeof( * V_1065 -> V_335 ) * V_334
+ V_1027 , V_126 ) ;
if ( ! V_1065 ) {
V_35 = - V_127 ;
goto V_532;
}
if ( V_1066 )
V_1065 -> V_1072 = ( void * ) & V_1065 -> V_335 [ V_334 ] ;
V_1065 -> V_1066 = V_1066 ;
if ( V_1027 ) {
if ( V_1065 -> V_1072 )
V_1065 -> V_1026 = ( void * ) ( V_1065 -> V_1072 + V_1066 ) ;
else
V_1065 -> V_1026 = ( void * ) ( V_1065 -> V_335 + V_334 ) ;
}
if ( V_1086 ) {
if ( V_1065 -> V_1026 )
V_1065 -> V_1092 = ( void * ) ( V_1065 -> V_1026 + V_1027 ) ;
else if ( V_1065 -> V_1072 )
V_1065 -> V_1092 =
( void * ) ( V_1065 -> V_1072 + V_1066 ) ;
else
V_1065 -> V_1092 =
( void * ) ( V_1065 -> V_335 + V_334 ) ;
}
V_1065 -> V_1086 = V_1086 ;
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1070 ] ) {
F_40 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_79 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1073;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1065 -> V_335 [ V_144 ] = V_55 ;
V_144 ++ ;
}
} else {
for ( V_264 = 0 ; V_264 < V_330 ; V_264 ++ ) {
int V_146 ;
if ( ! V_18 -> V_331 [ V_264 ] )
continue;
for ( V_146 = 0 ; V_146 < V_18 -> V_331 [ V_264 ] -> V_334 ; V_146 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_331 [ V_264 ] -> V_335 [ V_146 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1065 -> V_335 [ V_144 ] = V_55 ;
V_144 ++ ;
}
}
}
if ( ! V_144 ) {
V_35 = - V_16 ;
goto V_1073;
}
V_1065 -> V_334 = V_144 ;
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1071 ] ) {
F_40 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_25 ( V_45 ) > V_551 ) {
V_35 = - V_16 ;
goto V_1073;
}
V_1065 -> V_1072 [ V_144 ] . V_525 = F_25 ( V_45 ) ;
memcpy ( V_1065 -> V_1072 [ V_144 ] . V_527 , F_24 ( V_45 ) ,
F_25 ( V_45 ) ) ;
V_144 ++ ;
}
}
V_144 = 0 ;
if ( V_30 -> V_5 [ V_1090 ] ) {
F_40 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_527 , * V_1093 ;
F_94 ( V_86 , V_1088 ,
F_24 ( V_45 ) , F_25 ( V_45 ) ,
V_1094 ) ;
V_527 = V_86 [ V_1095 ] ;
if ( V_527 ) {
if ( F_25 ( V_527 ) > V_551 ) {
V_35 = - V_16 ;
goto V_1073;
}
memcpy ( V_1065 -> V_1092 [ V_144 ] . V_527 . V_527 ,
F_24 ( V_527 ) , F_25 ( V_527 ) ) ;
V_1065 -> V_1092 [ V_144 ] . V_527 . V_525 =
F_25 ( V_527 ) ;
}
V_1093 = V_86 [ V_1096 ] ;
if ( V_1093 )
V_1065 -> V_1097 = F_4 ( V_1093 ) ;
else
V_1065 -> V_1097 =
V_1098 ;
V_144 ++ ;
}
}
if ( V_30 -> V_5 [ V_610 ] ) {
V_1065 -> V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
memcpy ( ( void * ) V_1065 -> V_1026 ,
F_24 ( V_30 -> V_5 [ V_610 ] ) ,
V_1065 -> V_1027 ) ;
}
if ( V_30 -> V_5 [ V_1076 ] ) {
V_1065 -> V_51 = F_4 (
V_30 -> V_5 [ V_1076 ] ) ;
if ( ( ( V_1065 -> V_51 & V_1077 ) &&
! ( V_18 -> V_265 & V_1078 ) ) ||
( ( V_1065 -> V_51 & V_1079 ) &&
! ( V_18 -> V_265 & V_1080 ) ) ) {
V_35 = - V_480 ;
goto V_1073;
}
}
V_1065 -> V_184 = V_184 ;
V_1065 -> V_18 = & V_7 -> V_18 ;
V_1065 -> V_1087 = V_1087 ;
V_1065 -> V_1083 = V_1084 ;
V_35 = F_217 ( V_7 , V_184 , V_1065 ) ;
if ( ! V_35 ) {
V_7 -> V_1091 = V_1065 ;
F_218 ( V_7 , V_184 ,
V_1099 ) ;
goto V_532;
}
V_1073:
F_42 ( V_1065 ) ;
V_532:
return V_35 ;
}
static int F_219 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_390 ) ||
! V_7 -> V_319 -> V_1100 )
return - V_480 ;
return F_220 ( V_7 , false ) ;
}
static int F_221 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_460 V_461 ;
int V_35 ;
V_35 = F_78 ( V_7 , V_30 , & V_461 ) ;
if ( V_35 )
return V_35 ;
if ( V_17 -> V_1101 )
return - V_482 ;
V_35 = F_147 ( V_17 -> V_18 , & V_461 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( V_461 . V_55 -> V_70 != V_1102 )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_1103 )
return - V_480 ;
V_35 = F_149 ( V_7 , V_17 , V_17 -> V_132 ,
V_461 . V_55 , V_663 ,
F_148 ( V_461 . V_464 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = V_7 -> V_319 -> V_1103 ( & V_7 -> V_18 , V_184 , & V_461 ) ;
if ( ! V_35 ) {
V_17 -> V_664 = V_461 . V_55 ;
V_17 -> V_1101 = true ;
V_17 -> V_1104 = V_1084 ;
}
return V_35 ;
}
static int F_222 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1105 * V_1106 )
{
struct V_1107 * V_323 = & V_1106 -> V_1108 ;
const struct V_1109 * V_1110 ;
void * V_257 ;
struct V_4 * V_1111 ;
bool V_1112 = false ;
F_44 ( V_17 ) ;
V_257 = F_26 ( V_53 , F_69 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1113 ) ;
if ( ! V_257 )
return - 1 ;
F_223 ( V_34 , V_257 , & V_38 ) ;
if ( F_29 ( V_53 , V_268 , V_7 -> V_1114 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_29 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_59;
if ( F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
V_1111 = F_46 ( V_53 , V_1115 ) ;
if ( ! V_1111 )
goto V_59;
if ( ( ! F_224 ( V_323 -> V_484 ) &&
F_50 ( V_53 , V_1116 , V_522 , V_323 -> V_484 ) ) )
goto V_59;
F_203 () ;
V_1110 = F_204 ( V_323 -> V_1110 ) ;
if ( V_1110 ) {
if ( F_102 ( V_53 , V_1117 , V_1110 -> V_1112 ) )
goto V_1118;
V_1112 = true ;
if ( V_1110 -> V_47 && F_50 ( V_53 , V_1119 ,
V_1110 -> V_47 , V_1110 -> V_129 ) )
goto V_1118;
}
V_1110 = F_204 ( V_323 -> V_618 ) ;
if ( V_1110 ) {
if ( ! V_1112 && F_102 ( V_53 , V_1117 , V_1110 -> V_1112 ) )
goto V_1118;
if ( V_1110 -> V_47 && F_50 ( V_53 , V_1120 ,
V_1110 -> V_47 , V_1110 -> V_129 ) )
goto V_1118;
}
F_205 () ;
if ( V_323 -> V_481 &&
F_53 ( V_53 , V_1121 , V_323 -> V_481 ) )
goto V_59;
if ( F_53 ( V_53 , V_1122 , V_323 -> V_851 ) ||
F_29 ( V_53 , V_1123 , V_323 -> V_664 -> V_58 ) ||
F_29 ( V_53 , V_1124 ,
F_225 ( V_1084 - V_1106 -> V_1125 ) ) )
goto V_59;
switch ( V_7 -> V_18 . V_740 ) {
case V_741 :
if ( F_29 ( V_53 , V_1126 , V_323 -> signal ) )
goto V_59;
break;
case V_1127 :
if ( F_54 ( V_53 , V_1128 , V_323 -> signal ) )
goto V_59;
break;
default:
break;
}
switch ( V_17 -> V_132 ) {
case V_139 :
case V_138 :
if ( V_1106 == V_17 -> V_140 &&
F_29 ( V_53 , V_1129 ,
V_1130 ) )
goto V_59;
break;
case V_137 :
if ( V_1106 == V_17 -> V_140 &&
F_29 ( V_53 , V_1129 ,
V_1131 ) )
goto V_59;
break;
default:
break;
}
F_47 ( V_53 , V_1111 ) ;
return F_64 ( V_53 , V_257 ) ;
V_1118:
F_205 () ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
static int F_226 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1105 * V_1067 ;
struct V_1 * V_17 ;
int V_439 = V_34 -> args [ 2 ] , V_96 = 0 ;
int V_35 ;
V_35 = F_14 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_110 ( V_17 ) ;
F_227 ( & V_7 -> V_1132 ) ;
F_228 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1114 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_96 <= V_439 )
continue;
if ( F_222 ( V_32 , V_34 ,
V_34 -> V_36 -> V_440 , V_441 ,
V_7 , V_17 , V_1067 ) < 0 ) {
V_96 -- ;
break;
}
}
F_229 ( & V_7 -> V_1132 ) ;
F_112 ( V_17 ) ;
V_34 -> args [ 2 ] = V_96 ;
F_22 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_230 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_184 ,
struct V_1133 * V_1134 )
{
void * V_257 ;
struct V_4 * V_1135 ;
V_257 = F_26 ( V_53 , V_49 , V_50 , V_51 ,
V_1136 ) ;
if ( ! V_257 )
return - V_127 ;
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) )
goto V_59;
V_1135 = F_46 ( V_53 , V_1137 ) ;
if ( ! V_1135 )
goto V_59;
if ( F_29 ( V_53 , V_1138 ,
V_1134 -> V_664 -> V_58 ) )
goto V_59;
if ( ( V_1134 -> V_714 & V_1139 ) &&
F_54 ( V_53 , V_1140 , V_1134 -> V_1141 ) )
goto V_59;
if ( ( V_1134 -> V_714 & V_1142 ) &&
F_30 ( V_53 , V_1143 ) )
goto V_59;
if ( ( V_1134 -> V_714 & V_1144 ) &&
F_102 ( V_53 , V_1145 ,
V_1134 -> V_1146 ) )
goto V_59;
if ( ( V_1134 -> V_714 & V_1147 ) &&
F_102 ( V_53 , V_1148 ,
V_1134 -> V_1149 ) )
goto V_59;
if ( ( V_1134 -> V_714 & V_1150 ) &&
F_102 ( V_53 , V_1151 ,
V_1134 -> V_1152 ) )
goto V_59;
if ( ( V_1134 -> V_714 & V_1153 ) &&
F_102 ( V_53 , V_1154 ,
V_1134 -> V_1155 ) )
goto V_59;
if ( ( V_1134 -> V_714 & V_1156 ) &&
F_102 ( V_53 , V_1157 ,
V_1134 -> V_1158 ) )
goto V_59;
F_47 ( V_53 , V_1135 ) ;
return F_64 ( V_53 , V_257 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
static int F_231 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1133 V_1134 ;
struct V_6 * V_184 ;
struct V_1 * V_17 ;
int V_1159 = V_34 -> args [ 2 ] ;
int V_323 ;
V_323 = F_14 ( V_32 , V_34 , & V_184 , & V_17 ) ;
if ( V_323 )
return V_323 ;
if ( ! V_17 -> V_19 ) {
V_323 = - V_16 ;
goto V_803;
}
if ( ! V_184 -> V_319 -> V_1160 ) {
V_323 = - V_480 ;
goto V_803;
}
while ( 1 ) {
struct V_54 * V_55 ;
V_323 = F_232 ( V_184 , V_17 -> V_19 , V_1159 , & V_1134 ) ;
if ( V_323 == - V_583 )
break;
if ( V_323 )
goto V_803;
if ( ! V_1134 . V_664 ) {
V_323 = - V_16 ;
goto V_532;
}
V_55 = F_79 ( & V_184 -> V_18 ,
V_1134 . V_664 -> V_58 ) ;
if ( ! V_55 || V_55 -> V_51 & V_60 ) {
V_1159 ++ ;
continue;
}
if ( F_230 ( V_32 ,
F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_440 , V_441 ,
V_17 -> V_19 , & V_1134 ) < 0 )
goto V_532;
V_1159 ++ ;
}
V_532:
V_34 -> args [ 2 ] = V_1159 ;
V_323 = V_32 -> V_47 ;
V_803:
F_22 ( V_184 ) ;
return V_323 ;
}
static bool F_233 ( V_22 V_1161 )
{
return ! ( V_1161 & ~ ( V_1162 |
V_1163 ) ) ;
}
static int F_234 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_484 , * V_527 , * V_1026 = NULL , * V_1164 = NULL ;
int V_35 , V_525 , V_1027 = 0 , V_1165 = 0 ;
enum V_628 V_629 ;
struct V_84 V_83 ;
bool V_1166 ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_649 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_463 ] )
return - V_16 ;
V_35 = F_37 ( V_30 , & V_83 ) ;
if ( V_35 )
return V_35 ;
if ( V_83 . V_96 >= 0 ) {
if ( V_83 . type != - 1 && V_83 . type != V_579 )
return - V_16 ;
if ( ! V_83 . V_98 . V_83 || ! V_83 . V_98 . V_99 )
return - V_16 ;
if ( ( V_83 . V_98 . V_103 != V_130 ||
V_83 . V_98 . V_99 != V_1167 ) &&
( V_83 . V_98 . V_103 != V_131 ||
V_83 . V_98 . V_99 != V_1168 ) )
return - V_16 ;
if ( V_83 . V_96 > 4 )
return - V_16 ;
} else {
V_83 . V_98 . V_99 = 0 ;
V_83 . V_98 . V_83 = NULL ;
}
if ( V_83 . V_96 >= 0 ) {
int V_144 ;
bool V_1169 = false ;
for ( V_144 = 0 ; V_144 < V_7 -> V_18 . V_306 ; V_144 ++ ) {
if ( V_83 . V_98 . V_103 == V_7 -> V_18 . V_307 [ V_144 ] ) {
V_1169 = true ;
break;
}
}
if ( ! V_1169 )
return - V_16 ;
}
if ( ! V_7 -> V_319 -> V_353 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_55 = F_79 ( & V_7 -> V_18 ,
F_4 ( V_30 -> V_5 [ V_463 ] ) ) ;
if ( ! V_55 || ( V_55 -> V_51 & V_60 ) )
return - V_16 ;
V_527 = F_24 ( V_30 -> V_5 [ V_526 ] ) ;
V_525 = F_25 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_30 -> V_5 [ V_610 ] ) {
V_1026 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
}
V_629 = F_4 ( V_30 -> V_5 [ V_649 ] ) ;
if ( ! F_143 ( V_7 , V_629 , V_632 ) )
return - V_16 ;
if ( V_629 == V_634 &&
! V_30 -> V_5 [ V_1170 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1170 ] ) {
if ( V_629 != V_634 )
return - V_16 ;
V_1164 = F_24 ( V_30 -> V_5 [ V_1170 ] ) ;
V_1165 = F_25 ( V_30 -> V_5 [ V_1170 ] ) ;
if ( V_1165 < 4 )
return - V_16 ;
}
V_1166 = ! ! V_30 -> V_5 [ V_1171 ] ;
if ( V_1166 )
return 0 ;
F_110 ( V_184 -> V_28 ) ;
V_35 = F_235 ( V_7 , V_184 , V_55 , V_629 , V_484 ,
V_527 , V_525 , V_1026 , V_1027 ,
V_83 . V_98 . V_83 , V_83 . V_98 . V_99 , V_83 . V_96 ,
V_1164 , V_1165 ) ;
F_112 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_146 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1172 * V_1173 ,
int V_1174 )
{
memset ( V_1173 , 0 , sizeof( * V_1173 ) ) ;
V_1173 -> V_1175 = V_30 -> V_5 [ V_1176 ] ;
if ( V_30 -> V_5 [ V_311 ] ) {
T_3 V_1177 ;
V_1177 = F_76 (
V_30 -> V_5 [ V_311 ] ) ;
V_1173 -> V_1178 = F_236 ( V_1177 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_310 ) &&
V_1177 != V_1179 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1180 ] )
V_1173 -> V_1181 = true ;
} else
V_1173 -> V_1178 = F_236 ( V_1179 ) ;
if ( V_30 -> V_5 [ V_1182 ] ) {
void * V_129 ;
int V_47 , V_144 ;
V_129 = F_24 ( V_30 -> V_5 [ V_1182 ] ) ;
V_47 = F_25 ( V_30 -> V_5 [ V_1182 ] ) ;
V_1173 -> V_1183 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1173 -> V_1183 > V_1174 )
return - V_16 ;
memcpy ( V_1173 -> V_1184 , V_129 , V_47 ) ;
for ( V_144 = 0 ; V_144 < V_1173 -> V_1183 ; V_144 ++ )
if ( ! F_237 (
& V_7 -> V_18 ,
V_1173 -> V_1184 [ V_144 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1185 ] ) {
V_1173 -> V_1186 =
F_4 ( V_30 -> V_5 [ V_1185 ] ) ;
if ( ! F_237 ( & V_7 -> V_18 ,
V_1173 -> V_1186 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1187 ] ) {
V_1173 -> V_1161 =
F_4 ( V_30 -> V_5 [ V_1187 ] ) ;
if ( ! F_233 ( V_1173 -> V_1161 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1188 ] ) {
void * V_129 ;
int V_47 ;
V_129 = F_24 ( V_30 -> V_5 [ V_1188 ] ) ;
V_47 = F_25 ( V_30 -> V_5 [ V_1188 ] ) ;
V_1173 -> V_1189 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1173 -> V_1189 > V_1190 )
return - V_16 ;
memcpy ( V_1173 -> V_1191 , V_129 , V_47 ) ;
}
return 0 ;
}
static int F_238 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1192 V_1193 = {} ;
const T_2 * V_484 , * V_527 ;
int V_35 , V_525 = 0 ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_485 ] ||
! V_30 -> V_5 [ V_526 ] ||
! V_30 -> V_5 [ V_463 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_355 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_55 = F_79 ( & V_7 -> V_18 ,
F_4 ( V_30 -> V_5 [ V_463 ] ) ) ;
if ( ! V_55 || ( V_55 -> V_51 & V_60 ) )
return - V_16 ;
V_527 = F_24 ( V_30 -> V_5 [ V_526 ] ) ;
V_525 = F_25 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_30 -> V_5 [ V_610 ] ) {
V_1193 . V_1026 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_1193 . V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
}
if ( V_30 -> V_5 [ V_1194 ] ) {
enum V_1195 V_1196 =
F_4 ( V_30 -> V_5 [ V_1194 ] ) ;
if ( V_1196 == V_1197 )
V_1193 . V_1198 = true ;
else if ( V_1196 != V_1199 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1200 ] )
V_1193 . V_1201 = F_24 ( V_30 -> V_5 [ V_1200 ] ) ;
if ( F_198 ( V_30 -> V_5 [ V_1202 ] ) )
V_1193 . V_51 |= V_1203 ;
if ( V_30 -> V_5 [ V_425 ] )
memcpy ( & V_1193 . V_1204 ,
F_24 ( V_30 -> V_5 [ V_425 ] ) ,
sizeof( V_1193 . V_1204 ) ) ;
if ( V_30 -> V_5 [ V_844 ] ) {
if ( ! V_30 -> V_5 [ V_425 ] )
return - V_16 ;
memcpy ( & V_1193 . V_822 ,
F_24 ( V_30 -> V_5 [ V_844 ] ) ,
sizeof( V_1193 . V_822 ) ) ;
}
if ( F_198 ( V_30 -> V_5 [ V_1205 ] ) )
V_1193 . V_51 |= V_1206 ;
if ( V_30 -> V_5 [ V_434 ] )
memcpy ( & V_1193 . V_1207 ,
F_24 ( V_30 -> V_5 [ V_434 ] ) ,
sizeof( V_1193 . V_1207 ) ) ;
if ( V_30 -> V_5 [ V_845 ] ) {
if ( ! V_30 -> V_5 [ V_434 ] )
return - V_16 ;
memcpy ( & V_1193 . V_823 ,
F_24 ( V_30 -> V_5 [ V_845 ] ) ,
sizeof( V_1193 . V_823 ) ) ;
}
V_35 = F_146 ( V_7 , V_30 , & V_1193 . V_651 , 1 ) ;
if ( ! V_35 ) {
F_110 ( V_184 -> V_28 ) ;
V_35 = F_239 ( V_7 , V_184 , V_55 , V_484 ,
V_527 , V_525 , & V_1193 ) ;
F_112 ( V_184 -> V_28 ) ;
}
return V_35 ;
}
static int F_240 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
const T_2 * V_1026 = NULL , * V_484 ;
int V_1027 = 0 , V_35 ;
T_3 V_1208 ;
bool V_1166 ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1209 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_357 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_1208 = F_76 ( V_30 -> V_5 [ V_1209 ] ) ;
if ( V_1208 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_610 ] ) {
V_1026 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
}
V_1166 = ! ! V_30 -> V_5 [ V_1171 ] ;
F_110 ( V_184 -> V_28 ) ;
V_35 = F_241 ( V_7 , V_184 , V_484 , V_1026 , V_1027 , V_1208 ,
V_1166 ) ;
F_112 ( V_184 -> V_28 ) ;
return V_35 ;
}
static int F_242 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
const T_2 * V_1026 = NULL , * V_484 ;
int V_1027 = 0 , V_35 ;
T_3 V_1208 ;
bool V_1166 ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1209 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_359 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_1208 = F_76 ( V_30 -> V_5 [ V_1209 ] ) ;
if ( V_1208 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_610 ] ) {
V_1026 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
}
V_1166 = ! ! V_30 -> V_5 [ V_1171 ] ;
F_110 ( V_184 -> V_28 ) ;
V_35 = F_243 ( V_7 , V_184 , V_484 , V_1026 , V_1027 , V_1208 ,
V_1166 ) ;
F_112 ( V_184 -> V_28 ) ;
return V_35 ;
}
static bool
F_244 ( struct V_6 * V_7 ,
int V_1210 [ V_330 ] ,
int V_1211 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_264 , V_144 ;
for ( V_264 = 0 ; V_264 < V_330 ; V_264 ++ ) {
struct V_213 * V_214 ;
V_214 = V_18 -> V_331 [ V_264 ] ;
if ( ! V_214 )
continue;
for ( V_144 = 0 ; V_144 < V_214 -> V_235 ; V_144 ++ ) {
if ( V_214 -> V_236 [ V_144 ] . V_238 == V_1211 ) {
V_1210 [ V_264 ] = V_144 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_245 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1212 V_1213 ;
struct V_18 * V_18 ;
struct V_121 * V_1214 = NULL ;
int V_35 ;
memset ( & V_1213 , 0 , sizeof( V_1213 ) ) ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] ||
! F_25 ( V_30 -> V_5 [ V_526 ] ) )
return - V_16 ;
V_1213 . V_481 = 100 ;
if ( V_30 -> V_5 [ V_638 ] ) {
V_1213 . V_481 =
F_4 ( V_30 -> V_5 [ V_638 ] ) ;
if ( V_1213 . V_481 < 1 || V_1213 . V_481 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_319 -> V_361 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_137 )
return - V_480 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_485 ] ) {
V_1213 . V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( ! F_116 ( V_1213 . V_484 ) )
return - V_16 ;
}
V_1213 . V_527 = F_24 ( V_30 -> V_5 [ V_526 ] ) ;
V_1213 . V_525 = F_25 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_30 -> V_5 [ V_610 ] ) {
V_1213 . V_1026 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_1213 . V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
}
V_35 = F_78 ( V_7 , V_30 , & V_1213 . V_461 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_84 ( & V_7 -> V_18 , & V_1213 . V_461 ) )
return - V_16 ;
switch ( V_1213 . V_461 . V_464 ) {
case V_465 :
break;
case V_516 :
case V_517 :
if ( V_7 -> V_18 . V_265 & V_1215 )
break;
default:
return - V_16 ;
}
V_1213 . V_1216 = ! ! V_30 -> V_5 [ V_1217 ] ;
V_1213 . V_647 = ! ! V_30 -> V_5 [ V_648 ] ;
if ( V_30 -> V_5 [ V_908 ] ) {
T_2 * V_1074 =
F_24 ( V_30 -> V_5 [ V_908 ] ) ;
int V_1218 =
F_25 ( V_30 -> V_5 [ V_908 ] ) ;
struct V_213 * V_214 =
V_18 -> V_331 [ V_1213 . V_461 . V_55 -> V_264 ] ;
V_35 = F_212 ( V_214 , V_1074 , V_1218 ,
& V_1213 . V_909 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_1219 ] &&
! F_244 ( V_7 , V_1213 . V_1210 ,
F_4 ( V_30 -> V_5 [ V_1219 ] ) ) )
return - V_16 ;
if ( V_1213 . V_647 && V_30 -> V_5 [ V_1220 ] ) {
bool V_123 = false ;
V_1214 = F_38 ( V_7 ,
V_30 -> V_5 [ V_1220 ] ,
& V_123 ) ;
if ( F_18 ( V_1214 ) )
return F_19 ( V_1214 ) ;
if ( ( V_1213 . V_461 . V_464 != V_465 ) &&
V_123 ) {
F_42 ( V_1214 ) ;
return - V_16 ;
}
}
V_1213 . V_1175 =
F_198 ( V_30 -> V_5 [ V_1176 ] ) ;
V_35 = F_246 ( V_7 , V_184 , & V_1213 , V_1214 ) ;
if ( V_35 )
F_42 ( V_1214 ) ;
return V_35 ;
}
static int F_247 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
if ( ! V_7 -> V_319 -> V_1221 )
return - V_480 ;
if ( V_184 -> V_28 -> V_132 != V_137 )
return - V_480 ;
return F_248 ( V_7 , V_184 , false ) ;
}
static int F_249 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
int V_1210 [ V_330 ] ;
V_22 V_1222 ;
int V_35 ;
if ( V_184 -> V_28 -> V_132 != V_137 &&
V_184 -> V_28 -> V_132 != V_136 )
return - V_480 ;
if ( ! V_7 -> V_319 -> V_401 )
return - V_480 ;
memset ( V_1210 , 0 , sizeof( V_1210 ) ) ;
if ( ! V_30 -> V_5 [ V_1219 ] )
return - V_16 ;
V_1222 = F_4 ( V_30 -> V_5 [ V_1219 ] ) ;
if ( ! F_244 ( V_7 , V_1210 , V_1222 ) )
return - V_16 ;
V_35 = V_7 -> V_319 -> V_401 ( & V_7 -> V_18 , V_184 , V_1210 ) ;
return V_35 ;
}
static int F_250 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1223 ] )
return - V_16 ;
V_35 = - V_480 ;
if ( V_7 -> V_319 -> V_407 ) {
V_7 -> V_1224 = V_30 ;
V_35 = F_251 ( V_7 ,
F_24 ( V_30 -> V_5 [ V_1223 ] ) ,
F_25 ( V_30 -> V_5 [ V_1223 ] ) ) ;
V_7 -> V_1224 = NULL ;
}
return V_35 ;
}
static int F_252 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1225 ;
void * V_129 = NULL ;
int V_1226 = 0 ;
F_15 () ;
if ( V_34 -> args [ 0 ] ) {
V_1225 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_16 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_803;
V_7 = F_8 ( F_17 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_18 ( V_7 ) ) {
V_35 = F_19 ( V_7 ) ;
goto V_803;
}
V_1225 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1223 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1223 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_129 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1226 = F_25 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1225 ) ;
if ( ! V_7 ) {
V_35 = - V_583 ;
goto V_803;
}
if ( ! V_7 -> V_319 -> V_1227 ) {
V_35 = - V_480 ;
goto V_803;
}
while ( 1 ) {
void * V_257 = F_26 ( V_32 , F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_440 , V_441 ,
V_1228 ) ;
struct V_4 * V_1229 ;
if ( ! V_257 )
break;
if ( F_29 ( V_32 , V_26 , V_1225 ) ) {
F_65 ( V_32 , V_257 ) ;
break;
}
V_1229 = F_46 ( V_32 , V_1223 ) ;
if ( ! V_1229 ) {
F_65 ( V_32 , V_257 ) ;
break;
}
V_35 = F_253 ( V_7 , V_32 , V_34 , V_129 , V_1226 ) ;
F_47 ( V_32 , V_1229 ) ;
if ( V_35 == - V_82 || V_35 == - V_583 ) {
F_65 ( V_32 , V_257 ) ;
break;
} else if ( V_35 ) {
F_65 ( V_32 , V_257 ) ;
goto V_803;
}
F_64 ( V_32 , V_257 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1225 + 1 ;
V_803:
F_21 () ;
return V_35 ;
}
static struct V_31 *
F_254 ( struct V_6 * V_7 ,
int V_1230 , V_22 V_49 , V_22 V_50 , T_11 V_1231 )
{
struct V_31 * V_32 ;
void * V_257 ;
struct V_4 * V_129 ;
V_32 = F_72 ( V_1230 + 100 , V_1231 ) ;
if ( ! V_32 )
return NULL ;
V_257 = F_26 ( V_32 , V_49 , V_50 , 0 , V_1228 ) ;
if ( ! V_257 ) {
F_255 ( V_32 ) ;
return NULL ;
}
if ( F_29 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_59;
V_129 = F_46 ( V_32 , V_1223 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_257 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_129 ;
return V_32 ;
V_59:
F_255 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_256 ( struct V_18 * V_18 ,
int V_1230 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_57 ( ! V_7 -> V_1224 ) )
return NULL ;
return F_254 ( V_7 , V_1230 ,
V_7 -> V_1224 -> V_444 ,
V_7 -> V_1224 -> V_445 ,
V_126 ) ;
}
int F_257 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_257 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_129 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
if ( F_57 ( ! V_7 -> V_1224 ) ) {
F_255 ( V_32 ) ;
return - V_16 ;
}
F_47 ( V_32 , V_129 ) ;
F_64 ( V_32 , V_257 ) ;
return F_74 ( V_32 , V_7 -> V_1224 ) ;
}
struct V_31 * F_258 ( struct V_18 * V_18 ,
int V_1230 , T_11 V_1231 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
return F_254 ( V_7 , V_1230 , 0 , 0 , V_1231 ) ;
}
void F_259 ( struct V_31 * V_32 , T_11 V_1231 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_257 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_129 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
F_47 ( V_32 , V_129 ) ;
F_64 ( V_32 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1232 . V_705 , V_1231 ) ;
}
static int F_261 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1233 V_409 ;
struct V_18 * V_18 ;
struct V_121 * V_1214 = NULL ;
int V_35 ;
memset ( & V_409 , 0 , sizeof( V_409 ) ) ;
if ( ! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] ||
! F_25 ( V_30 -> V_5 [ V_526 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_649 ] ) {
V_409 . V_629 =
F_4 ( V_30 -> V_5 [ V_649 ] ) ;
if ( ! F_143 ( V_7 , V_409 . V_629 ,
V_410 ) )
return - V_16 ;
} else
V_409 . V_629 = V_650 ;
V_409 . V_647 = V_30 -> V_5 [ V_648 ] ;
V_35 = F_146 ( V_7 , V_30 , & V_409 . V_651 ,
V_652 ) ;
if ( V_35 )
return V_35 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
V_18 = & V_7 -> V_18 ;
V_409 . V_1234 = - 1 ;
if ( V_30 -> V_5 [ V_1235 ] &&
( V_18 -> V_51 & V_297 ) ) {
V_409 . V_1234 =
F_76 ( V_30 -> V_5 [ V_1235 ] ) ;
}
if ( V_30 -> V_5 [ V_485 ] )
V_409 . V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_409 . V_527 = F_24 ( V_30 -> V_5 [ V_526 ] ) ;
V_409 . V_525 = F_25 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_30 -> V_5 [ V_610 ] ) {
V_409 . V_1026 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_409 . V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
}
if ( V_30 -> V_5 [ V_1194 ] ) {
V_409 . V_1196 = F_4 ( V_30 -> V_5 [ V_1194 ] ) ;
if ( V_409 . V_1196 != V_1197 &&
V_409 . V_1196 != V_1199 )
return - V_16 ;
} else {
V_409 . V_1196 = V_1199 ;
}
if ( V_30 -> V_5 [ V_463 ] ) {
V_409 . V_664 =
F_79 ( V_18 ,
F_4 ( V_30 -> V_5 [ V_463 ] ) ) ;
if ( ! V_409 . V_664 ||
V_409 . V_664 -> V_51 & V_60 )
return - V_16 ;
}
if ( V_409 . V_647 && V_30 -> V_5 [ V_1220 ] ) {
V_1214 = F_38 ( V_7 ,
V_30 -> V_5 [ V_1220 ] , NULL ) ;
if ( F_18 ( V_1214 ) )
return F_19 ( V_1214 ) ;
}
if ( F_198 ( V_30 -> V_5 [ V_1202 ] ) )
V_409 . V_51 |= V_1203 ;
if ( V_30 -> V_5 [ V_425 ] )
memcpy ( & V_409 . V_1204 ,
F_24 ( V_30 -> V_5 [ V_425 ] ) ,
sizeof( V_409 . V_1204 ) ) ;
if ( V_30 -> V_5 [ V_844 ] ) {
if ( ! V_30 -> V_5 [ V_425 ] ) {
F_42 ( V_1214 ) ;
return - V_16 ;
}
memcpy ( & V_409 . V_822 ,
F_24 ( V_30 -> V_5 [ V_844 ] ) ,
sizeof( V_409 . V_822 ) ) ;
}
if ( F_198 ( V_30 -> V_5 [ V_1205 ] ) )
V_409 . V_51 |= V_1206 ;
if ( V_30 -> V_5 [ V_434 ] )
memcpy ( & V_409 . V_1207 ,
F_24 ( V_30 -> V_5 [ V_434 ] ) ,
sizeof( V_409 . V_1207 ) ) ;
if ( V_30 -> V_5 [ V_845 ] ) {
if ( ! V_30 -> V_5 [ V_434 ] ) {
F_42 ( V_1214 ) ;
return - V_16 ;
}
memcpy ( & V_409 . V_823 ,
F_24 ( V_30 -> V_5 [ V_845 ] ) ,
sizeof( V_409 . V_823 ) ) ;
}
F_110 ( V_184 -> V_28 ) ;
V_35 = F_262 ( V_7 , V_184 , & V_409 , V_1214 , NULL ) ;
F_112 ( V_184 -> V_28 ) ;
if ( V_35 )
F_42 ( V_1214 ) ;
return V_35 ;
}
static int F_263 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_3 V_1236 ;
int V_436 ;
if ( ! V_30 -> V_5 [ V_1209 ] )
V_1236 = V_1237 ;
else
V_1236 = F_76 ( V_30 -> V_5 [ V_1209 ] ) ;
if ( V_1236 == 0 )
return - V_16 ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
F_110 ( V_184 -> V_28 ) ;
V_436 = F_264 ( V_7 , V_184 , V_1236 , true ) ;
F_112 ( V_184 -> V_28 ) ;
return V_436 ;
}
static int F_265 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
V_22 V_1238 ;
if ( ! V_30 -> V_5 [ V_1239 ] )
return - V_16 ;
V_1238 = F_4 ( V_30 -> V_5 [ V_1239 ] ) ;
V_2 = F_266 ( V_1238 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_68 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_267 ( V_7 , V_2 ) ;
F_268 ( V_2 ) ;
return V_35 ;
}
static int F_269 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
int (* F_270)( struct V_18 * V_18 , struct V_25 * V_184 ,
struct V_1240 * V_1241 ) = NULL ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1240 V_1241 ;
memset ( & V_1241 , 0 , sizeof( struct V_1240 ) ) ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1242 ] )
return - V_16 ;
V_1241 . V_1243 = F_24 ( V_30 -> V_5 [ V_1242 ] ) ;
V_1241 . V_484 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
switch ( V_30 -> V_1244 -> V_52 ) {
case V_1245 :
F_270 = V_7 -> V_319 -> V_365 ;
break;
case V_1246 :
F_270 = V_7 -> V_319 -> V_367 ;
break;
default:
F_57 ( 1 ) ;
break;
}
if ( ! F_270 )
return - V_480 ;
return F_270 ( & V_7 -> V_18 , V_184 , & V_1241 ) ;
}
static int F_271 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
if ( V_184 -> V_28 -> V_132 != V_138 &&
V_184 -> V_28 -> V_132 != V_139 )
return - V_480 ;
if ( ! V_7 -> V_319 -> V_369 )
return - V_480 ;
return F_272 ( V_7 , V_184 ) ;
}
static int F_273 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 V_1247 , V_1248 ;
T_3 V_1249 ;
T_2 * V_1250 ;
if ( ! ( V_7 -> V_18 . V_51 & V_299 ) ||
! V_7 -> V_319 -> V_386 )
return - V_480 ;
if ( ! V_30 -> V_5 [ V_1251 ] ||
! V_30 -> V_5 [ V_1252 ] ||
! V_30 -> V_5 [ V_1253 ] ||
! V_30 -> V_5 [ V_610 ] ||
! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
V_1250 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_1247 = F_35 ( V_30 -> V_5 [ V_1251 ] ) ;
V_1249 = F_76 ( V_30 -> V_5 [ V_1252 ] ) ;
V_1248 = F_35 ( V_30 -> V_5 [ V_1253 ] ) ;
return F_274 ( V_7 , V_184 , V_1250 , V_1247 ,
V_1248 , V_1249 ,
F_24 ( V_30 -> V_5 [ V_610 ] ) ,
F_25 ( V_30 -> V_5 [ V_610 ] ) ) ;
}
static int F_275 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
enum V_1254 V_1255 ;
T_2 * V_1250 ;
if ( ! ( V_7 -> V_18 . V_51 & V_299 ) ||
! V_7 -> V_319 -> V_388 )
return - V_480 ;
if ( ! V_30 -> V_5 [ V_1256 ] ||
! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
V_1255 = F_35 ( V_30 -> V_5 [ V_1256 ] ) ;
V_1250 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
return F_276 ( V_7 , V_184 , V_1250 , V_1255 ) ;
}
static int F_277 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
struct V_460 V_461 ;
struct V_31 * V_53 ;
void * V_257 ;
T_1 V_574 ;
V_22 V_1257 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_463 ] ||
! V_30 -> V_5 [ V_1258 ] )
return - V_16 ;
V_1257 = F_4 ( V_30 -> V_5 [ V_1258 ] ) ;
if ( ! V_7 -> V_319 -> V_372 ||
! ( V_7 -> V_18 . V_51 & V_371 ) )
return - V_480 ;
if ( V_1257 < V_1259 ||
V_1257 > V_7 -> V_18 . V_414 )
return - V_16 ;
V_35 = F_78 ( V_7 , V_30 , & V_461 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_1260 ) ;
if ( ! V_257 ) {
V_35 = - V_82 ;
goto V_584;
}
V_35 = F_278 ( V_7 , V_17 , V_461 . V_55 ,
V_1257 , & V_574 ) ;
if ( V_35 )
goto V_584;
if ( F_102 ( V_53 , V_1261 , V_574 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_584:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_279 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
T_1 V_574 ;
if ( ! V_30 -> V_5 [ V_1261 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_1262 )
return - V_480 ;
V_574 = F_5 ( V_30 -> V_5 [ V_1261 ] ) ;
return F_280 ( V_7 , V_17 , V_574 ) ;
}
static V_22 F_281 ( struct V_213 * V_214 ,
T_2 * V_1074 , T_2 V_1263 )
{
T_2 V_144 ;
V_22 V_672 = 0 ;
for ( V_144 = 0 ; V_144 < V_1263 ; V_144 ++ ) {
int V_218 = ( V_1074 [ V_144 ] & 0x7f ) * 5 ;
int V_1264 ;
for ( V_1264 = 0 ; V_1264 < V_214 -> V_235 ; V_1264 ++ ) {
struct V_217 * V_1265 =
& V_214 -> V_236 [ V_1264 ] ;
if ( V_218 == V_1265 -> V_238 ) {
V_672 |= 1 << V_1264 ;
break;
}
}
if ( V_1264 == V_214 -> V_235 )
return 0 ;
}
return V_672 ;
}
static bool F_282 ( struct V_213 * V_214 ,
T_2 * V_1074 , T_2 V_1263 ,
T_2 V_222 [ V_1266 ] )
{
T_2 V_144 ;
memset ( V_222 , 0 , V_1266 ) ;
for ( V_144 = 0 ; V_144 < V_1263 ; V_144 ++ ) {
int V_1264 , V_1267 ;
V_1264 = V_1074 [ V_144 ] / 8 ;
V_1267 = F_148 ( V_1074 [ V_144 ] % 8 ) ;
if ( ( V_1264 < 0 ) || ( V_1264 >= V_1266 ) )
return false ;
if ( V_214 -> V_219 . V_222 . V_1268 [ V_1264 ] & V_1267 )
V_222 [ V_1264 ] |= V_1267 ;
else
return false ;
}
return true ;
}
static int F_283 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_86 [ V_1269 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1270 V_672 ;
int V_125 , V_144 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_4 * V_1271 ;
struct V_213 * V_214 ;
if ( V_30 -> V_5 [ V_1272 ] == NULL )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_374 )
return - V_480 ;
memset ( & V_672 , 0 , sizeof( V_672 ) ) ;
for ( V_144 = 0 ; V_144 < V_330 ; V_144 ++ ) {
V_214 = V_7 -> V_18 . V_331 [ V_144 ] ;
V_672 . V_1273 [ V_144 ] . V_1274 =
V_214 ? ( 1 << V_214 -> V_235 ) - 1 : 0 ;
if ( V_214 )
memcpy ( V_672 . V_1273 [ V_144 ] . V_222 ,
V_214 -> V_219 . V_222 . V_1268 ,
sizeof( V_672 . V_1273 [ V_144 ] . V_222 ) ) ;
else
memset ( V_672 . V_1273 [ V_144 ] . V_222 , 0 ,
sizeof( V_672 . V_1273 [ V_144 ] . V_222 ) ) ;
}
F_111 ( V_1275 > V_1266 * 8 ) ;
F_40 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_263 V_264 = F_211 ( V_1271 ) ;
if ( V_264 < 0 || V_264 >= V_330 )
return - V_16 ;
V_214 = V_7 -> V_18 . V_331 [ V_264 ] ;
if ( V_214 == NULL )
return - V_16 ;
F_94 ( V_86 , V_1269 , F_24 ( V_1271 ) ,
F_25 ( V_1271 ) , V_1276 ) ;
if ( V_86 [ V_1277 ] ) {
V_672 . V_1273 [ V_264 ] . V_1274 = F_281 (
V_214 ,
F_24 ( V_86 [ V_1277 ] ) ,
F_25 ( V_86 [ V_1277 ] ) ) ;
if ( ( V_672 . V_1273 [ V_264 ] . V_1274 == 0 ) &&
F_25 ( V_86 [ V_1277 ] ) )
return - V_16 ;
}
if ( V_86 [ V_1278 ] ) {
if ( ! F_282 (
V_214 ,
F_24 ( V_86 [ V_1278 ] ) ,
F_25 ( V_86 [ V_1278 ] ) ,
V_672 . V_1273 [ V_264 ] . V_222 ) )
return - V_16 ;
}
if ( V_672 . V_1273 [ V_264 ] . V_1274 == 0 ) {
if ( ! V_7 -> V_18 . V_331 [ V_264 ] -> V_219 . V_220 )
return - V_16 ;
for ( V_144 = 0 ; V_144 < V_1266 ; V_144 ++ )
if ( V_672 . V_1273 [ V_264 ] . V_222 [ V_144 ] )
break;
if ( V_144 == V_1266 )
return - V_16 ;
}
}
return F_284 ( V_7 , V_184 , NULL , & V_672 ) ;
}
static int F_285 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
T_3 V_1279 = V_252 | V_1280 ;
if ( ! V_30 -> V_5 [ V_1281 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_251 ] )
V_1279 = F_76 ( V_30 -> V_5 [ V_251 ] ) ;
switch ( V_17 -> V_132 ) {
case V_138 :
case V_137 :
case V_139 :
case V_133 :
case V_134 :
case V_136 :
case V_135 :
case V_559 :
break;
default:
return - V_480 ;
}
if ( ! V_7 -> V_319 -> V_376 )
return - V_480 ;
return F_286 ( V_17 , V_30 -> V_444 , V_1279 ,
F_24 ( V_30 -> V_5 [ V_1281 ] ) ,
F_25 ( V_30 -> V_5 [ V_1281 ] ) ) ;
}
static int F_287 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
struct V_460 V_461 ;
int V_35 ;
void * V_257 = NULL ;
T_1 V_574 ;
struct V_31 * V_53 = NULL ;
unsigned int V_1282 = 0 ;
bool V_1283 , V_1081 , V_1284 ;
V_1284 = V_30 -> V_5 [ V_1285 ] ;
if ( ! V_30 -> V_5 [ V_1286 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_376 )
return - V_480 ;
switch ( V_17 -> V_132 ) {
case V_559 :
if ( ! V_30 -> V_5 [ V_463 ] )
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
return - V_480 ;
}
if ( V_30 -> V_5 [ V_1258 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_415 ) )
return - V_16 ;
V_1282 = F_4 ( V_30 -> V_5 [ V_1258 ] ) ;
if ( V_1282 < V_1259 ||
V_1282 > V_7 -> V_18 . V_414 )
return - V_16 ;
}
V_1283 = V_30 -> V_5 [ V_416 ] ;
if ( V_1283 && ! ( V_7 -> V_18 . V_51 & V_415 ) )
return - V_16 ;
V_1081 = F_198 ( V_30 -> V_5 [ V_1082 ] ) ;
V_461 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_463 ] ) {
V_35 = F_78 ( V_7 , V_30 , & V_461 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_461 . V_55 && V_1283 )
return - V_16 ;
if ( ! V_1284 ) {
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_1287 ) ;
if ( ! V_257 ) {
V_35 = - V_82 ;
goto V_584;
}
}
V_35 = F_288 ( V_7 , V_17 , V_461 . V_55 , V_1283 , V_1282 ,
F_24 ( V_30 -> V_5 [ V_1286 ] ) ,
F_25 ( V_30 -> V_5 [ V_1286 ] ) ,
V_1081 , V_1284 , & V_574 ) ;
if ( V_35 )
goto V_584;
if ( V_53 ) {
if ( F_102 ( V_53 , V_1261 , V_574 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
}
return 0 ;
V_59:
V_35 = - V_82 ;
V_584:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_289 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
T_1 V_574 ;
if ( ! V_30 -> V_5 [ V_1261 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_378 )
return - V_480 ;
switch ( V_17 -> V_132 ) {
case V_138 :
case V_137 :
case V_139 :
case V_133 :
case V_134 :
case V_135 :
case V_559 :
break;
default:
return - V_480 ;
}
V_574 = F_5 ( V_30 -> V_5 [ V_1261 ] ) ;
return F_290 ( V_7 , V_17 , V_574 ) ;
}
static int F_291 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
T_2 V_1288 ;
bool V_256 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1289 ] )
return - V_16 ;
V_1288 = F_4 ( V_30 -> V_5 [ V_1289 ] ) ;
if ( V_1288 != V_1290 && V_1288 != V_1291 )
return - V_16 ;
V_17 = V_184 -> V_28 ;
if ( ! V_7 -> V_319 -> V_1292 )
return - V_480 ;
V_256 = ( V_1288 == V_1291 ) ? true : false ;
if ( V_256 == V_17 -> V_1293 )
return 0 ;
V_35 = F_292 ( V_7 , V_184 , V_256 , V_17 -> V_1294 ) ;
if ( ! V_35 )
V_17 -> V_1293 = V_256 ;
return V_35 ;
}
static int F_293 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
enum V_1295 V_1288 ;
struct V_1 * V_17 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_31 * V_53 ;
void * V_257 ;
int V_35 ;
V_17 = V_184 -> V_28 ;
if ( ! V_7 -> V_319 -> V_1292 )
return - V_480 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_1296 ) ;
if ( ! V_257 ) {
V_35 = - V_82 ;
goto V_584;
}
if ( V_17 -> V_1293 )
V_1288 = V_1291 ;
else
V_1288 = V_1290 ;
if ( F_29 ( V_53 , V_1289 , V_1288 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_584:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_294 ( struct V_29 * V_30 ,
V_22 V_218 , V_22 V_1297 , V_22 V_1298 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
if ( V_218 > 100 || V_1298 > V_1299 )
return - V_16 ;
V_17 = V_184 -> V_28 ;
if ( ! V_7 -> V_319 -> V_1300 )
return - V_480 ;
if ( V_17 -> V_132 != V_138 &&
V_17 -> V_132 != V_139 )
return - V_480 ;
return F_295 ( V_7 , V_184 , V_218 , V_1297 , V_1298 ) ;
}
static int F_296 ( struct V_29 * V_30 ,
T_12 V_1301 , V_22 V_1302 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
if ( V_1301 > 0 )
return - V_16 ;
V_17 = V_184 -> V_28 ;
if ( ! V_7 -> V_319 -> V_1303 )
return - V_480 ;
if ( V_17 -> V_132 != V_138 &&
V_17 -> V_132 != V_139 )
return - V_480 ;
return F_297 ( V_7 , V_184 , V_1301 , V_1302 ) ;
}
static int F_298 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1304 + 1 ] ;
struct V_4 * V_1305 ;
int V_35 ;
V_1305 = V_30 -> V_5 [ V_1306 ] ;
if ( ! V_1305 ) {
V_35 = - V_16 ;
goto V_532;
}
V_35 = F_34 ( V_5 , V_1304 , V_1305 ,
V_1307 ) ;
if ( V_35 )
goto V_532;
if ( V_5 [ V_1308 ] &&
V_5 [ V_1309 ] ) {
T_12 V_1301 ;
V_22 V_1302 ;
V_1301 = F_4 ( V_5 [ V_1308 ] ) ;
V_1302 = F_4 ( V_5 [ V_1309 ] ) ;
V_35 = F_296 ( V_30 , V_1301 , V_1302 ) ;
} else if ( V_5 [ V_1310 ] &&
V_5 [ V_1311 ] &&
V_5 [ V_1312 ] ) {
V_22 V_218 , V_1297 , V_1298 ;
V_218 = F_4 ( V_5 [ V_1310 ] ) ;
V_1297 = F_4 ( V_5 [ V_1311 ] ) ;
V_1298 = F_4 ( V_5 [ V_1312 ] ) ;
V_35 = F_294 ( V_30 , V_218 , V_1297 , V_1298 ) ;
} else
V_35 = - V_16 ;
V_532:
return V_35 ;
}
static int F_299 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_939 V_1001 ;
struct V_1007 V_1008 ;
int V_35 ;
memcpy ( & V_1001 , & V_943 , sizeof( V_1001 ) ) ;
memcpy ( & V_1008 , & V_1313 , sizeof( V_1008 ) ) ;
if ( V_30 -> V_5 [ V_945 ] ) {
V_35 = F_195 ( V_30 , & V_1001 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_550 ] ||
! F_25 ( V_30 -> V_5 [ V_550 ] ) )
return - V_16 ;
V_1008 . V_1314 = F_24 ( V_30 -> V_5 [ V_550 ] ) ;
V_1008 . V_942 = F_25 ( V_30 -> V_5 [ V_550 ] ) ;
if ( V_30 -> V_5 [ V_1219 ] &&
! F_244 ( V_7 , V_1008 . V_1210 ,
F_4 ( V_30 -> V_5 [ V_1219 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_638 ] ) {
V_1008 . V_481 =
F_4 ( V_30 -> V_5 [ V_638 ] ) ;
if ( V_1008 . V_481 < 10 ||
V_1008 . V_481 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_639 ] ) {
V_1008 . V_641 =
F_4 ( V_30 -> V_5 [ V_639 ] ) ;
if ( V_1008 . V_641 < 1 || V_1008 . V_641 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1010 ] ) {
V_35 = F_197 ( V_30 , & V_1008 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1008 . V_1030 )
V_1001 . V_961 = false ;
if ( V_30 -> V_5 [ V_463 ] ) {
V_35 = F_78 ( V_7 , V_30 , & V_1008 . V_461 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1008 . V_461 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_908 ] ) {
T_2 * V_1074 = F_24 ( V_30 -> V_5 [ V_908 ] ) ;
int V_1218 =
F_25 ( V_30 -> V_5 [ V_908 ] ) ;
struct V_213 * V_214 ;
if ( ! V_1008 . V_461 . V_55 )
return - V_16 ;
V_214 = V_7 -> V_18 . V_331 [ V_1008 . V_461 . V_55 -> V_264 ] ;
V_35 = F_212 ( V_214 , V_1074 , V_1218 ,
& V_1008 . V_909 ) ;
if ( V_35 )
return V_35 ;
}
return F_300 ( V_7 , V_184 , & V_1008 , & V_1001 ) ;
}
static int F_301 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
return F_302 ( V_7 , V_184 ) ;
}
static int F_303 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1315 * V_172 = V_7 -> V_18 . V_1316 ;
struct V_4 * V_1317 , * V_1318 ;
int V_144 , V_1319 ;
if ( ! V_172 -> V_203 )
return 0 ;
V_1317 = F_46 ( V_53 , V_212 ) ;
if ( ! V_1317 )
return - V_82 ;
for ( V_144 = 0 ; V_144 < V_172 -> V_203 ; V_144 ++ ) {
V_1318 = F_46 ( V_53 , V_144 + 1 ) ;
if ( ! V_1318 )
return - V_82 ;
V_1319 = V_172 -> V_1320 [ V_144 ] . V_1321 ;
if ( F_50 ( V_53 , V_1322 ,
F_304 ( V_1319 , 8 ) ,
V_172 -> V_1320 [ V_144 ] . V_672 ) ||
F_50 ( V_53 , V_1323 ,
V_1319 , V_172 -> V_1320 [ V_144 ] . V_1324 ) ||
F_29 ( V_53 , V_1325 ,
V_172 -> V_1320 [ V_144 ] . V_1326 ) )
return - V_82 ;
F_47 ( V_53 , V_1318 ) ;
}
F_47 ( V_53 , V_1317 ) ;
return 0 ;
}
static int F_305 ( struct V_31 * V_53 ,
struct V_1327 * V_171 )
{
struct V_4 * V_173 ;
if ( ! V_171 )
return 0 ;
V_173 = F_46 ( V_53 , V_174 ) ;
if ( ! V_173 )
return - V_82 ;
if ( F_306 ( V_53 , V_1328 , V_171 -> V_1329 ) ||
F_306 ( V_53 , V_1330 , V_171 -> V_867 ) ||
F_50 ( V_53 , V_1331 , V_522 , V_171 -> V_1332 ) ||
F_53 ( V_53 , V_1333 , V_171 -> V_1334 ) ||
F_53 ( V_53 , V_1335 , V_171 -> V_1336 ) ||
F_50 ( V_53 , V_175 ,
V_171 -> V_1337 , V_171 -> V_1338 ) ||
F_29 ( V_53 , V_180 ,
V_171 -> V_1339 ) ||
F_50 ( V_53 , V_182 ,
V_171 -> V_1340 , V_171 -> V_1341 ) ||
F_50 ( V_53 , V_1342 ,
F_304 ( V_171 -> V_1340 , 8 ) , V_171 -> V_1343 ) )
return - V_82 ;
if ( V_171 -> V_1344 . V_47 &&
F_50 ( V_53 , V_177 ,
sizeof( V_171 -> V_1344 ) , & V_171 -> V_1344 ) )
return - V_82 ;
if ( V_171 -> V_1345 . V_47 &&
F_50 ( V_53 , V_179 ,
sizeof( V_171 -> V_1345 ) + V_171 -> V_1346 ,
& V_171 -> V_1345 ) )
return - V_82 ;
F_47 ( V_53 , V_173 ) ;
return 0 ;
}
static int F_307 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_31 * V_53 ;
void * V_257 ;
V_22 V_1347 = V_533 ;
if ( ! V_7 -> V_18 . V_172 )
return - V_480 ;
if ( V_7 -> V_18 . V_1316 && V_7 -> V_18 . V_1316 -> V_171 ) {
V_1347 += V_7 -> V_18 . V_1316 -> V_171 -> V_1346 +
V_7 -> V_18 . V_1316 -> V_171 -> V_1337 +
V_7 -> V_18 . V_1316 -> V_171 -> V_1340 +
V_7 -> V_18 . V_1316 -> V_171 -> V_1340 / 8 ;
}
V_53 = F_72 ( V_1347 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_1348 ) ;
if ( ! V_257 )
goto V_59;
if ( V_7 -> V_18 . V_1316 ) {
struct V_4 * V_185 ;
V_185 = F_46 ( V_53 , V_1349 ) ;
if ( ! V_185 )
goto V_59;
if ( ( V_7 -> V_18 . V_1316 -> V_1350 &&
F_30 ( V_53 , V_188 ) ) ||
( V_7 -> V_18 . V_1316 -> V_411 &&
F_30 ( V_53 , V_190 ) ) ||
( V_7 -> V_18 . V_1316 -> V_1351 &&
F_30 ( V_53 , V_192 ) ) ||
( V_7 -> V_18 . V_1316 -> V_1352 &&
F_30 ( V_53 , V_196 ) ) ||
( V_7 -> V_18 . V_1316 -> V_1353 &&
F_30 ( V_53 , V_198 ) ) ||
( V_7 -> V_18 . V_1316 -> V_1354 &&
F_30 ( V_53 , V_200 ) ) ||
( V_7 -> V_18 . V_1316 -> V_1355 &&
F_30 ( V_53 , V_202 ) ) )
goto V_59;
if ( F_303 ( V_53 , V_7 ) )
goto V_59;
if ( F_305 ( V_53 ,
V_7 -> V_18 . V_1316 -> V_171 ) )
goto V_59;
F_47 ( V_53 , V_185 ) ;
}
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
F_73 ( V_53 ) ;
return - V_82 ;
}
static int F_308 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1315 * V_1356 )
{
struct V_4 * V_86 [ V_1357 ] ;
struct V_1327 * V_1001 ;
struct V_1358 * V_178 = NULL ;
struct V_1359 * V_50 = NULL ;
V_22 V_1347 ;
V_22 V_1360 , V_1361 , V_1346 = 0 , V_1362 ;
int V_35 , V_1363 ;
if ( ! V_7 -> V_18 . V_172 -> V_171 )
return - V_16 ;
V_35 = F_94 ( V_86 , V_1364 ,
F_24 ( V_45 ) , F_25 ( V_45 ) ,
V_1365 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_86 [ V_1328 ] ||
! V_86 [ V_1330 ] ||
! V_86 [ V_1331 ] ||
! V_86 [ V_1335 ] ||
! V_86 [ V_175 ] ||
! V_86 [ V_180 ] ||
! V_86 [ V_182 ] ||
! V_86 [ V_1342 ] )
return - V_16 ;
V_1360 = F_25 ( V_86 [ V_175 ] ) ;
if ( V_1360 > V_7 -> V_18 . V_172 -> V_171 -> V_176 )
return - V_16 ;
if ( F_4 ( V_86 [ V_180 ] ) >
V_7 -> V_18 . V_172 -> V_171 -> V_181 ||
F_4 ( V_86 [ V_180 ] ) == 0 )
return - V_16 ;
V_1361 = F_25 ( V_86 [ V_182 ] ) ;
if ( V_1361 > V_7 -> V_18 . V_172 -> V_171 -> V_183 )
return - V_16 ;
V_1362 = F_25 ( V_86 [ V_1342 ] ) ;
if ( V_1362 != F_304 ( V_1361 , 8 ) )
return - V_16 ;
if ( V_86 [ V_179 ] ) {
V_22 V_1366 = F_25 ( V_86 [ V_179 ] ) ;
V_178 = F_24 ( V_86 [ V_179 ] ) ;
V_1346 = V_1366 - sizeof( * V_178 ) ;
if ( ! V_178 -> V_47 || V_1346 % V_178 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_172 -> V_171 -> V_178 )
return - V_16 ;
if ( V_178 -> V_47 > V_7 -> V_18 . V_172 -> V_171 -> V_178 -> V_1367 )
return - V_16 ;
if ( V_178 -> V_47 < V_7 -> V_18 . V_172 -> V_171 -> V_178 -> V_1368 )
return - V_16 ;
if ( V_1346 > V_7 -> V_18 . V_172 -> V_171 -> V_178 -> V_1369 )
return - V_16 ;
if ( V_178 -> V_1370 + V_178 -> V_47 > V_1360 )
return - V_16 ;
}
if ( V_86 [ V_177 ] ) {
V_50 = F_24 ( V_86 [ V_177 ] ) ;
if ( ! V_7 -> V_18 . V_172 -> V_171 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1370 > V_1360 )
return - V_16 ;
}
V_1347 = sizeof( * V_1001 ) ;
V_1347 += V_1360 ;
V_1347 += V_1361 + V_1362 ;
V_1347 += V_1346 ;
V_1001 = F_39 ( V_1347 , V_126 ) ;
if ( ! V_1001 )
return - V_127 ;
V_1001 -> V_1329 = F_309 ( V_86 [ V_1328 ] ) ;
V_1001 -> V_867 = F_309 ( V_86 [ V_1330 ] ) ;
memcpy ( V_1001 -> V_1332 , F_24 ( V_86 [ V_1331 ] ) ,
V_522 ) ;
if ( V_86 [ V_1333 ] )
V_1363 = F_76 ( V_86 [ V_1333 ] ) ;
else
V_1363 = 0 ;
#ifdef F_310
V_35 = F_311 ( F_7 ( & V_7 -> V_18 ) , V_1371 , V_1372 ,
V_1373 , & V_1001 -> V_1374 , 1 ) ;
if ( V_35 ) {
F_42 ( V_1001 ) ;
return V_35 ;
}
if ( F_312 ( V_1001 -> V_1374 -> V_44 , V_1363 ) ) {
F_313 ( V_1001 -> V_1374 ) ;
F_42 ( V_1001 ) ;
return - V_1375 ;
}
V_1001 -> V_1334 = F_314 ( V_1001 -> V_1374 -> V_44 ) -> V_1376 ;
#else
if ( ! V_1363 ) {
F_42 ( V_1001 ) ;
return - V_16 ;
}
V_1001 -> V_1334 = V_1363 ;
#endif
V_1001 -> V_1336 = F_76 ( V_86 [ V_1335 ] ) ;
V_1001 -> V_1337 = V_1360 ;
V_1001 -> V_1338 = ( T_2 * ) V_1001 + sizeof( * V_1001 ) + V_1346 ;
memcpy ( ( void * ) V_1001 -> V_1338 ,
F_24 ( V_86 [ V_175 ] ) ,
V_1360 ) ;
if ( V_50 )
V_1001 -> V_1344 = * V_50 ;
V_1001 -> V_1339 = F_4 ( V_86 [ V_180 ] ) ;
V_1001 -> V_1340 = V_1361 ;
V_1001 -> V_1341 = ( T_2 * ) V_1001 + sizeof( * V_1001 ) + V_1346 + V_1360 ;
memcpy ( ( void * ) V_1001 -> V_1341 ,
F_24 ( V_86 [ V_182 ] ) ,
V_1361 ) ;
V_1001 -> V_1343 = ( T_2 * ) V_1001 + sizeof( * V_1001 ) + V_1346 +
V_1360 + V_1361 ;
memcpy ( ( void * ) V_1001 -> V_1343 ,
F_24 ( V_86 [ V_1342 ] ) ,
V_1362 ) ;
if ( V_178 ) {
V_1001 -> V_1346 = V_1346 ;
memcpy ( & V_1001 -> V_1345 , V_178 , sizeof( * V_178 ) + V_1346 ) ;
}
V_1356 -> V_171 = V_1001 ;
return 0 ;
}
static int F_315 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_4 * V_86 [ V_1377 ] ;
struct V_1315 V_1378 = {} ;
struct V_1315 * V_1379 ;
const struct V_1380 * V_172 = V_7 -> V_18 . V_172 ;
int V_35 , V_144 ;
bool V_1381 = V_7 -> V_18 . V_1316 ;
if ( ! V_172 )
return - V_480 ;
if ( ! V_30 -> V_5 [ V_1349 ] ) {
F_316 ( V_7 ) ;
V_7 -> V_18 . V_1316 = NULL ;
goto V_1382;
}
V_35 = F_94 ( V_86 , V_1383 ,
F_24 ( V_30 -> V_5 [ V_1349 ] ) ,
F_25 ( V_30 -> V_5 [ V_1349 ] ) ,
V_1384 ) ;
if ( V_35 )
return V_35 ;
if ( V_86 [ V_188 ] ) {
if ( ! ( V_172 -> V_51 & V_187 ) )
return - V_16 ;
V_1378 . V_1350 = true ;
}
if ( V_86 [ V_190 ] ) {
if ( ! ( V_172 -> V_51 & V_189 ) )
return - V_16 ;
V_1378 . V_411 = true ;
}
if ( V_86 [ V_192 ] ) {
if ( ! ( V_172 -> V_51 & V_191 ) )
return - V_16 ;
V_1378 . V_1351 = true ;
}
if ( V_86 [ V_194 ] )
return - V_16 ;
if ( V_86 [ V_196 ] ) {
if ( ! ( V_172 -> V_51 & V_195 ) )
return - V_16 ;
V_1378 . V_1352 = true ;
}
if ( V_86 [ V_198 ] ) {
if ( ! ( V_172 -> V_51 & V_197 ) )
return - V_16 ;
V_1378 . V_1353 = true ;
}
if ( V_86 [ V_200 ] ) {
if ( ! ( V_172 -> V_51 & V_199 ) )
return - V_16 ;
V_1378 . V_1354 = true ;
}
if ( V_86 [ V_202 ] ) {
if ( ! ( V_172 -> V_51 & V_201 ) )
return - V_16 ;
V_1378 . V_1355 = true ;
}
if ( V_86 [ V_212 ] ) {
struct V_4 * V_205 ;
int V_203 = 0 ;
int V_125 , V_1319 , V_1385 , V_1326 ;
struct V_4 * V_1386 [ V_1387 ] ;
F_40 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_203 ++ ;
if ( V_203 > V_172 -> V_203 )
return - V_16 ;
V_1378 . V_1320 = F_317 ( V_203 ,
sizeof( V_1378 . V_1320 [ 0 ] ) ,
V_126 ) ;
if ( ! V_1378 . V_1320 )
return - V_127 ;
V_1378 . V_203 = V_203 ;
V_144 = 0 ;
F_40 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_94 ( V_1386 , V_1388 ,
F_24 ( V_205 ) , F_25 ( V_205 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1386 [ V_1322 ] ||
! V_1386 [ V_1323 ] )
goto error;
V_1319 = F_25 ( V_1386 [ V_1323 ] ) ;
V_1385 = F_304 ( V_1319 , 8 ) ;
if ( F_25 ( V_1386 [ V_1322 ] ) !=
V_1385 )
goto error;
if ( V_1319 > V_172 -> V_210 ||
V_1319 < V_172 -> V_208 )
goto error;
if ( ! V_1386 [ V_1325 ] )
V_1326 = 0 ;
else
V_1326 = F_4 (
V_1386 [ V_1325 ] ) ;
if ( V_1326 > V_172 -> V_211 )
goto error;
V_1378 . V_1320 [ V_144 ] . V_1326 = V_1326 ;
V_1378 . V_1320 [ V_144 ] . V_672 =
F_318 ( V_1385 + V_1319 , V_126 ) ;
if ( ! V_1378 . V_1320 [ V_144 ] . V_672 ) {
V_35 = - V_127 ;
goto error;
}
V_1378 . V_1320 [ V_144 ] . V_1324 =
V_1378 . V_1320 [ V_144 ] . V_672 + V_1385 ;
memcpy ( V_1378 . V_1320 [ V_144 ] . V_672 ,
F_24 ( V_1386 [ V_1322 ] ) ,
V_1385 ) ;
V_1378 . V_1320 [ V_144 ] . V_1321 = V_1319 ;
memcpy ( V_1378 . V_1320 [ V_144 ] . V_1324 ,
F_24 ( V_1386 [ V_1323 ] ) ,
V_1319 ) ;
V_144 ++ ;
}
}
if ( V_86 [ V_174 ] ) {
V_35 = F_308 (
V_7 , V_86 [ V_174 ] ,
& V_1378 ) ;
if ( V_35 )
goto error;
}
V_1379 = F_319 ( & V_1378 , sizeof( V_1378 ) , V_126 ) ;
if ( ! V_1379 ) {
V_35 = - V_127 ;
goto error;
}
F_316 ( V_7 ) ;
V_7 -> V_18 . V_1316 = V_1379 ;
V_1382:
if ( V_7 -> V_319 -> V_1382 &&
V_1381 != ! ! V_7 -> V_18 . V_1316 )
F_320 ( V_7 , V_7 -> V_18 . V_1316 ) ;
return 0 ;
error:
for ( V_144 = 0 ; V_144 < V_1378 . V_203 ; V_144 ++ )
F_42 ( V_1378 . V_1320 [ V_144 ] . V_672 ) ;
F_42 ( V_1378 . V_1320 ) ;
if ( V_1378 . V_171 && V_1378 . V_171 -> V_1374 )
F_313 ( V_1378 . V_171 -> V_1374 ) ;
F_42 ( V_1378 . V_171 ) ;
return V_35 ;
}
static int F_321 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_4 * V_86 [ V_1389 ] ;
struct V_1390 V_1391 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1392 ] )
return - V_16 ;
V_35 = F_94 ( V_86 , V_1393 ,
F_24 ( V_30 -> V_5 [ V_1392 ] ) ,
F_25 ( V_30 -> V_5 [ V_1392 ] ) ,
V_1394 ) ;
if ( V_35 )
return V_35 ;
if ( F_25 ( V_86 [ V_1395 ] ) != V_1396 )
return - V_1397 ;
if ( F_25 ( V_86 [ V_1398 ] ) != V_1399 )
return - V_1397 ;
if ( F_25 ( V_86 [ V_1400 ] ) != V_1401 )
return - V_1397 ;
memcpy ( V_1391 . V_1402 , F_24 ( V_86 [ V_1398 ] ) ,
V_1399 ) ;
memcpy ( V_1391 . V_1403 , F_24 ( V_86 [ V_1400 ] ) ,
V_1401 ) ;
memcpy ( V_1391 . V_1404 ,
F_24 ( V_86 [ V_1395 ] ) ,
V_1396 ) ;
F_110 ( V_17 ) ;
if ( ! V_17 -> V_140 ) {
V_35 = - V_1405 ;
goto V_532;
}
if ( ! V_7 -> V_319 -> V_1406 ) {
V_35 = - V_480 ;
goto V_532;
}
V_35 = F_322 ( V_7 , V_184 , & V_1391 ) ;
V_532:
F_112 ( V_17 ) ;
return V_35 ;
}
static int F_323 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
if ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 )
return - V_16 ;
if ( V_17 -> V_1407 )
return - V_482 ;
V_17 -> V_1407 = V_30 -> V_444 ;
return 0 ;
}
static int F_324 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_31 * V_53 ;
void * V_257 ;
const T_2 * V_604 ;
T_1 V_574 ;
int V_35 ;
if ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 )
return - V_480 ;
if ( ! V_30 -> V_5 [ V_485 ] )
return - V_16 ;
if ( ! V_7 -> V_319 -> V_393 )
return - V_480 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_1408 ) ;
if ( ! V_257 ) {
V_35 = - V_82 ;
goto V_584;
}
V_604 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
V_35 = F_325 ( V_7 , V_184 , V_604 , & V_574 ) ;
if ( V_35 )
goto V_584;
if ( F_102 ( V_53 , V_1261 , V_574 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_82 ;
V_584:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_326 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1409 * V_1410 , * V_1411 ;
int V_1412 ;
if ( ! ( V_7 -> V_18 . V_51 & V_397 ) )
return - V_480 ;
V_1411 = F_39 ( sizeof( * V_1411 ) , V_126 ) ;
if ( ! V_1411 )
return - V_127 ;
F_227 ( & V_7 -> V_1413 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1410 -> V_1414 == V_30 -> V_444 ) {
V_1412 = - V_637 ;
goto V_803;
}
}
V_1411 -> V_1414 = V_30 -> V_444 ;
F_327 ( & V_1411 -> V_567 , & V_7 -> V_1415 ) ;
F_229 ( & V_7 -> V_1413 ) ;
return 0 ;
V_803:
F_229 ( & V_7 -> V_1413 ) ;
F_42 ( V_1411 ) ;
return V_1412 ;
}
static int F_328 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_319 -> V_399 )
return - V_480 ;
if ( V_17 -> V_132 != V_559 )
return - V_480 ;
if ( V_17 -> V_1416 )
return 0 ;
V_35 = F_329 ( V_7 , V_17 -> V_132 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_330 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1416 = true ;
V_7 -> V_1417 ++ ;
return 0 ;
}
static int F_331 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
if ( V_17 -> V_132 != V_559 )
return - V_480 ;
if ( ! V_7 -> V_319 -> V_1418 )
return - V_480 ;
F_332 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_333 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_257 ;
struct V_31 * V_53 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , V_30 -> V_444 , V_30 -> V_445 , 0 ,
V_1419 ) ;
if ( ! V_257 )
goto V_59;
if ( F_29 ( V_53 , V_1420 ,
V_1421 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
F_255 ( V_53 ) ;
return - V_82 ;
}
static int F_334 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1422 V_1423 ;
struct V_25 * V_184 = V_30 -> V_443 [ 1 ] ;
if ( ! V_7 -> V_319 -> V_1424 )
return - V_480 ;
if ( ! V_30 -> V_5 [ V_1425 ] ||
! F_23 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
memset ( & V_1423 , 0 , sizeof( V_1423 ) ) ;
V_1423 . V_1426 = F_76 ( V_30 -> V_5 [ V_1425 ] ) ;
V_1423 . V_1026 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_1423 . V_1027 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
return F_335 ( V_7 , V_184 , & V_1423 ) ;
}
static int F_336 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
enum V_1427 V_1177 = V_1428 ;
T_3 V_1257 ;
int V_436 ;
if ( ! V_7 -> V_319 -> V_403 )
return - V_480 ;
if ( F_57 ( ! V_7 -> V_319 -> V_405 ) )
return - V_16 ;
if ( V_7 -> V_1429 )
return - V_482 ;
if ( V_30 -> V_5 [ V_1430 ] )
V_1177 = F_76 ( V_30 -> V_5 [ V_1430 ] ) ;
if ( V_1177 >= V_1431 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1432 ] )
return - V_16 ;
V_1257 =
F_76 ( V_30 -> V_5 [ V_1432 ] ) ;
if ( V_1257 > V_1433 )
return - V_1397 ;
V_436 = F_337 ( V_7 , V_17 , V_1177 , V_1257 ) ;
if ( ! V_436 )
V_7 -> V_1429 = V_30 -> V_444 ;
return V_436 ;
}
static int F_338 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_443 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
if ( ! V_7 -> V_319 -> V_405 )
return - V_480 ;
if ( V_7 -> V_1429 ) {
V_7 -> V_1429 = 0 ;
F_339 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_340 ( struct V_1434 * V_319 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_184 ;
bool V_1435 = V_319 -> V_1436 & V_1437 ;
if ( V_1435 )
F_15 () ;
if ( V_319 -> V_1436 & V_1438 ) {
V_7 = F_13 ( F_92 ( V_30 ) , V_30 ) ;
if ( F_18 ( V_7 ) ) {
if ( V_1435 )
F_21 () ;
return F_19 ( V_7 ) ;
}
V_30 -> V_443 [ 0 ] = V_7 ;
} else if ( V_319 -> V_1436 & V_1439 ||
V_319 -> V_1436 & V_1440 ) {
F_2 () ;
V_17 = F_1 ( F_92 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_18 ( V_17 ) ) {
if ( V_1435 )
F_21 () ;
return F_19 ( V_17 ) ;
}
V_184 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_319 -> V_1436 & V_1439 ) {
if ( ! V_184 ) {
if ( V_1435 )
F_21 () ;
return - V_16 ;
}
V_30 -> V_443 [ 1 ] = V_184 ;
} else {
V_30 -> V_443 [ 1 ] = V_17 ;
}
if ( V_184 ) {
if ( V_319 -> V_1436 & V_1441 &&
! F_89 ( V_184 ) ) {
if ( V_1435 )
F_21 () ;
return - V_494 ;
}
F_215 ( V_184 ) ;
} else if ( V_319 -> V_1436 & V_1441 ) {
if ( ! V_17 -> V_1416 ) {
if ( V_1435 )
F_21 () ;
return - V_494 ;
}
}
V_30 -> V_443 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_341 ( struct V_1434 * V_319 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_443 [ 1 ] ) {
if ( V_319 -> V_1436 & V_1440 ) {
struct V_1 * V_17 = V_30 -> V_443 [ 1 ] ;
if ( V_17 -> V_19 )
F_12 ( V_17 -> V_19 ) ;
} else {
F_12 ( V_30 -> V_443 [ 1 ] ) ;
}
}
if ( V_319 -> V_1436 & V_1437 )
F_21 () ;
}
void F_342 ( struct V_6 * V_7 )
{
struct V_31 * V_53 ;
struct V_255 V_256 = {} ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_56 ( V_7 , V_53 , 0 , 0 , 0 , & V_256 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1442 . V_705 , V_126 ) ;
}
static int F_343 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1064 * V_1193 = V_7 -> V_1068 ;
struct V_4 * V_1443 ;
int V_144 ;
if ( F_57 ( ! V_1193 ) )
return 0 ;
V_1443 = F_46 ( V_53 , V_1071 ) ;
if ( ! V_1443 )
goto V_59;
for ( V_144 = 0 ; V_144 < V_1193 -> V_1066 ; V_144 ++ ) {
if ( F_50 ( V_53 , V_144 , V_1193 -> V_1072 [ V_144 ] . V_525 , V_1193 -> V_1072 [ V_144 ] . V_527 ) )
goto V_59;
}
F_47 ( V_53 , V_1443 ) ;
V_1443 = F_46 ( V_53 , V_1070 ) ;
if ( ! V_1443 )
goto V_59;
for ( V_144 = 0 ; V_144 < V_1193 -> V_334 ; V_144 ++ ) {
if ( F_29 ( V_53 , V_144 , V_1193 -> V_335 [ V_144 ] -> V_58 ) )
goto V_59;
}
F_47 ( V_53 , V_1443 ) ;
if ( V_1193 -> V_1026 &&
F_50 ( V_53 , V_610 , V_1193 -> V_1027 , V_1193 -> V_1026 ) )
goto V_59;
if ( V_1193 -> V_51 )
F_29 ( V_53 , V_1076 , V_1193 -> V_51 ) ;
return 0 ;
V_59:
return - V_82 ;
}
static int F_344 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_257 ;
V_257 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_257 )
return - 1 ;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_343 ( V_53 , V_7 ) ;
return F_64 ( V_53 , V_257 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
static int
F_345 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_257 ;
V_257 = F_26 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_257 )
return - 1 ;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
return F_64 ( V_53 , V_257 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
return - V_435 ;
}
void F_214 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_344 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1444 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1445 . V_705 , V_126 ) ;
}
void F_346 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_344 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1113 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1445 . V_705 , V_126 ) ;
}
void F_347 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_344 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1446 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1445 . V_705 , V_126 ) ;
}
void F_348 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_345 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1447 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1445 . V_705 , V_126 ) ;
}
void F_218 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
if ( F_345 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1445 . V_705 , V_126 ) ;
}
void F_349 ( struct V_1448 * V_1065 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1449 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_54 ( V_53 , V_1450 , V_1065 -> V_1451 ) )
goto V_59;
if ( V_1065 -> V_1042 [ 0 ] == '0' && V_1065 -> V_1042 [ 1 ] == '0' ) {
if ( F_54 ( V_53 , V_1452 ,
V_1453 ) )
goto V_59;
} else if ( V_1065 -> V_1042 [ 0 ] == '9' && V_1065 -> V_1042 [ 1 ] == '9' ) {
if ( F_54 ( V_53 , V_1452 ,
V_1454 ) )
goto V_59;
} else if ( ( V_1065 -> V_1042 [ 0 ] == '9' && V_1065 -> V_1042 [ 1 ] == '8' ) ||
V_1065 -> V_1455 ) {
if ( F_54 ( V_53 , V_1452 ,
V_1456 ) )
goto V_59;
} else {
if ( F_54 ( V_53 , V_1452 ,
V_1457 ) ||
F_58 ( V_53 , V_935 ,
V_1065 -> V_1042 ) )
goto V_59;
}
if ( V_1065 -> V_14 != V_1458 &&
F_29 ( V_53 , V_26 , V_1065 -> V_14 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_203 () ;
F_350 ( V_53 , 0 , V_1459 . V_705 ,
V_1460 ) ;
F_205 () ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
static void F_351 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1461 , T_10 V_47 ,
enum V_630 V_52 , T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_1286 , V_47 , V_1461 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_352 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1461 ,
T_10 V_47 , T_11 V_1231 )
{
F_351 ( V_7 , V_19 , V_1461 , V_47 ,
V_632 , V_1231 ) ;
}
void F_353 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1461 ,
T_10 V_47 , T_11 V_1231 )
{
F_351 ( V_7 , V_19 , V_1461 , V_47 ,
V_1463 , V_1231 ) ;
}
void F_354 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1461 ,
T_10 V_47 , T_11 V_1231 )
{
F_351 ( V_7 , V_19 , V_1461 , V_47 ,
V_1464 , V_1231 ) ;
}
void F_355 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1461 ,
T_10 V_47 , T_11 V_1231 )
{
F_351 ( V_7 , V_19 , V_1461 , V_47 ,
V_1465 , V_1231 ) ;
}
void F_356 ( struct V_25 * V_184 , const T_2 * V_1461 ,
T_10 V_47 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1466 * V_1467 = ( void * ) V_1461 ;
V_22 V_52 ;
if ( F_57 ( V_47 < 2 ) )
return;
if ( F_357 ( V_1467 -> V_1468 ) )
V_52 = V_1469 ;
else
V_52 = V_1470 ;
F_358 ( V_184 , V_1461 , V_47 ) ;
F_351 ( V_7 , V_184 , V_1461 , V_47 , V_52 , V_1460 ) ;
}
static void F_359 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_604 , T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_30 ( V_53 , V_1471 ) ||
F_50 ( V_53 , V_485 , V_522 , V_604 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_360 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_604 ,
T_11 V_1231 )
{
F_359 ( V_7 , V_19 , V_632 ,
V_604 , V_1231 ) ;
}
void F_361 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_604 ,
T_11 V_1231 )
{
F_359 ( V_7 , V_19 , V_1463 ,
V_604 , V_1231 ) ;
}
void F_362 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_484 ,
const T_2 * V_1472 , T_10 V_1473 ,
const T_2 * V_1474 , T_10 V_1475 ,
T_3 V_1476 , T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_410 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_484 && F_50 ( V_53 , V_485 , V_522 , V_484 ) ) ||
F_53 ( V_53 , V_1252 , V_1476 ) ||
( V_1472 &&
F_50 ( V_53 , V_1477 , V_1473 , V_1472 ) ) ||
( V_1474 &&
F_50 ( V_53 , V_1478 , V_1475 , V_1474 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_363 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_484 ,
const T_2 * V_1472 , T_10 V_1473 ,
const T_2 * V_1474 , T_10 V_1475 , T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1479 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_484 ) ||
( V_1472 &&
F_50 ( V_53 , V_1477 , V_1473 , V_1472 ) ) ||
( V_1474 &&
F_50 ( V_53 , V_1478 , V_1475 , V_1474 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_364 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1236 ,
const T_2 * V_1026 , T_10 V_1027 , bool V_1480 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_412 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1480 && V_1236 &&
F_53 ( V_53 , V_1209 , V_1236 ) ) ||
( V_1480 &&
F_30 ( V_53 , V_1481 ) ) ||
( V_1026 && F_50 ( V_53 , V_610 , V_1027 , V_1026 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_126 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_365 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_484 ,
T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1482 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_484 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_366 ( struct V_25 * V_184 , const T_2 * V_604 ,
const T_2 * V_1026 , T_2 V_1027 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
if ( F_57 ( V_17 -> V_132 != V_136 ) )
return;
F_367 ( V_184 , V_604 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1483 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_604 ) ||
( V_1027 && V_1026 &&
F_50 ( V_53 , V_610 , V_1027 , V_1026 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_368 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_604 ,
enum V_1484 V_1485 , int V_1486 ,
const T_2 * V_1487 , T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1488 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_604 && F_50 ( V_53 , V_485 , V_522 , V_604 ) ) ||
F_29 ( V_53 , V_118 , V_1485 ) ||
( V_1486 != - 1 &&
F_54 ( V_53 , V_114 , V_1486 ) ) ||
( V_1487 && F_50 ( V_53 , V_113 , 6 , V_1487 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_369 ( struct V_18 * V_18 ,
struct V_54 * V_1489 ,
struct V_54 * V_1490 )
{
struct V_31 * V_53 ;
void * V_257 ;
struct V_4 * V_261 ;
V_53 = F_72 ( V_533 , V_1460 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1491 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , F_370 ( V_18 ) ) )
goto V_59;
V_261 = F_46 ( V_53 , V_1492 ) ;
if ( ! V_261 )
goto V_59;
if ( F_28 ( V_53 , V_1489 , false ) )
goto V_59;
F_47 ( V_53 , V_261 ) ;
V_261 = F_46 ( V_53 , V_1493 ) ;
if ( ! V_261 )
goto V_59;
if ( F_28 ( V_53 , V_1490 , false ) )
goto V_59;
F_47 ( V_53 , V_261 ) ;
F_64 ( V_53 , V_257 ) ;
F_203 () ;
F_350 ( V_53 , 0 , V_1459 . V_705 ,
V_1460 ) ;
F_205 () ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
static void F_371 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_574 ,
struct V_54 * V_55 ,
unsigned int V_1257 , T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_29 ( V_53 , V_463 , V_55 -> V_58 ) ||
F_29 ( V_53 , V_468 ,
V_471 ) ||
F_102 ( V_53 , V_1261 , V_574 ) )
goto V_59;
if ( V_52 == V_1260 &&
F_29 ( V_53 , V_1258 , V_1257 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_372 ( struct V_1 * V_17 , T_1 V_574 ,
struct V_54 * V_55 ,
unsigned int V_1257 , T_11 V_1231 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_373 ( V_17 , V_574 , V_55 , V_1257 ) ;
F_371 ( V_1260 ,
V_7 , V_17 , V_574 , V_55 ,
V_1257 , V_1231 ) ;
}
void F_374 ( struct V_1 * V_17 , T_1 V_574 ,
struct V_54 * V_55 ,
T_11 V_1231 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_375 ( V_17 , V_574 , V_55 ) ;
F_371 ( V_1494 ,
V_7 , V_17 , V_574 , V_55 , 0 , V_1231 ) ;
}
void F_376 ( struct V_25 * V_184 , const T_2 * V_576 ,
struct V_707 * V_708 , T_11 V_1231 )
{
struct V_18 * V_18 = V_184 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_377 ( V_184 , V_576 , V_708 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
if ( F_159 ( V_53 , 0 , 0 , 0 ,
V_7 , V_184 , V_576 , V_708 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
}
void F_378 ( struct V_25 * V_184 , const T_2 * V_576 , T_11 V_1231 )
{
struct V_18 * V_18 = V_184 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
F_379 ( V_184 , V_576 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1495 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_576 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_380 ( struct V_25 * V_184 , const T_2 * V_576 ,
enum V_1496 V_1236 ,
T_11 V_1231 )
{
struct V_18 * V_18 = V_184 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_1497 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1498 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_576 ) ||
F_29 ( V_53 , V_1499 , V_1236 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
static bool F_381 ( struct V_25 * V_184 , T_2 V_52 ,
const T_2 * V_604 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
V_22 V_1414 = F_382 ( V_17 -> V_1407 ) ;
if ( ! V_1414 )
return false ;
V_53 = F_72 ( 100 , V_1231 ) ;
if ( ! V_53 )
return true ;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return true ;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_604 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_383 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1414 ) ;
return true ;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
return true ;
}
bool F_384 ( struct V_25 * V_184 ,
const T_2 * V_604 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
bool V_436 ;
F_385 ( V_184 , V_604 ) ;
if ( F_57 ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 ) ) {
F_386 ( false ) ;
return false ;
}
V_436 = F_381 ( V_184 , V_1500 ,
V_604 , V_1231 ) ;
F_386 ( V_436 ) ;
return V_436 ;
}
bool F_387 ( struct V_25 * V_184 ,
const T_2 * V_604 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
bool V_436 ;
F_388 ( V_184 , V_604 ) ;
if ( F_57 ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 &&
V_17 -> V_132 != V_134 ) ) {
F_386 ( false ) ;
return false ;
}
V_436 = F_381 ( V_184 ,
V_1501 ,
V_604 , V_1231 ) ;
F_386 ( V_436 ) ;
return V_436 ;
}
int F_389 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1414 ,
int V_1502 , int V_1503 ,
const T_2 * V_1461 , T_10 V_47 , T_11 V_1231 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return - V_127 ;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1287 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return - V_127 ;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_29 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_29 ( V_53 , V_463 , V_1502 ) ||
( V_1503 &&
F_29 ( V_53 , V_1504 , V_1503 ) ) ||
F_50 ( V_53 , V_1286 , V_47 , V_1461 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
return F_383 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1414 ) ;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
return - V_82 ;
}
void F_390 ( struct V_1 * V_17 , T_1 V_574 ,
const T_2 * V_1461 , T_10 V_47 , bool V_1505 , T_11 V_1231 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_257 ;
F_391 ( V_17 , V_574 , V_1505 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1506 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_29 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_50 ( V_53 , V_1286 , V_47 , V_1461 ) ||
F_102 ( V_53 , V_1261 , V_574 ) ||
( V_1505 && F_30 ( V_53 , V_1507 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_392 ( struct V_25 * V_184 ,
enum V_1508 V_1509 ,
T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_871 ;
void * V_257 ;
F_393 ( V_184 , V_1509 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1510 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) )
goto V_59;
V_871 = F_46 ( V_53 , V_1306 ) ;
if ( ! V_871 )
goto V_59;
if ( F_29 ( V_53 , V_1511 ,
V_1509 ) )
goto V_59;
F_47 ( V_53 , V_871 ) ;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
static void F_394 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_484 ,
const T_2 * V_1404 , T_11 V_1231 )
{
struct V_31 * V_53 ;
struct V_4 * V_1512 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1513 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_484 ) )
goto V_59;
V_1512 = F_46 ( V_53 , V_1392 ) ;
if ( ! V_1512 )
goto V_59;
if ( F_50 ( V_53 , V_1395 ,
V_1396 , V_1404 ) )
goto V_59;
F_47 ( V_53 , V_1512 ) ;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_395 ( struct V_25 * V_184 , const T_2 * V_484 ,
const T_2 * V_1404 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_396 ( V_184 , V_484 ) ;
F_394 ( V_7 , V_184 , V_484 , V_1404 , V_1231 ) ;
}
static void
F_397 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1514 ,
const T_2 * V_484 , bool V_1515 , T_11 V_1231 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1516 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
V_45 = F_46 ( V_53 , V_1517 ) ;
if ( ! V_45 )
goto V_59;
if ( F_29 ( V_53 , V_1518 , V_1514 ) ||
F_50 ( V_53 , V_1519 , V_522 , V_484 ) ||
( V_1515 &&
F_30 ( V_53 , V_1520 ) ) )
goto V_59;
F_47 ( V_53 , V_45 ) ;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_398 ( struct V_25 * V_184 , int V_1514 ,
const T_2 * V_484 , bool V_1515 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_399 ( V_184 , V_1514 , V_484 , V_1515 ) ;
F_397 ( V_7 , V_184 , V_1514 , V_484 , V_1515 , V_1231 ) ;
}
static void F_400 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_460 * V_461 ,
T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1521 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
if ( F_99 ( V_53 , V_461 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_401 ( struct V_25 * V_184 ,
struct V_460 * V_461 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_402 ( V_184 , V_461 ) ;
F_110 ( V_17 ) ;
if ( F_57 ( V_17 -> V_132 != V_133 &&
V_17 -> V_132 != V_135 ) )
goto V_532;
V_17 -> V_664 = V_461 -> V_55 ;
F_400 ( V_7 , V_184 , V_461 , V_126 ) ;
V_532:
F_112 ( V_17 ) ;
return;
}
void F_403 ( struct V_25 * V_184 ,
const T_2 * V_1250 , V_22 V_1522 ,
V_22 V_218 , V_22 V_1298 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_871 ;
void * V_257 ;
V_53 = F_72 ( V_1497 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1510 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_1250 ) )
goto V_59;
V_871 = F_46 ( V_53 , V_1306 ) ;
if ( ! V_871 )
goto V_59;
if ( F_29 ( V_53 , V_1311 , V_1522 ) )
goto V_59;
if ( F_29 ( V_53 , V_1310 , V_218 ) )
goto V_59;
if ( F_29 ( V_53 , V_1312 , V_1298 ) )
goto V_59;
F_47 ( V_53 , V_871 ) ;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void
F_404 ( struct V_6 * V_7 ,
struct V_460 * V_461 ,
enum V_1523 V_1524 ,
struct V_25 * V_19 , T_11 V_1231 )
{
struct V_31 * V_53 ;
void * V_257 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1525 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_29 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
}
if ( F_29 ( V_53 , V_1526 , V_1524 ) )
goto V_59;
if ( F_99 ( V_53 , V_461 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_405 ( struct V_25 * V_184 ,
const T_2 * V_1250 , V_22 V_1522 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_871 ;
void * V_257 ;
F_406 ( V_184 , V_1250 , V_1522 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1510 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_1250 ) )
goto V_59;
V_871 = F_46 ( V_53 , V_1306 ) ;
if ( ! V_871 )
goto V_59;
if ( F_29 ( V_53 , V_1527 , V_1522 ) )
goto V_59;
F_47 ( V_53 , V_871 ) ;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_407 ( struct V_25 * V_184 , const T_2 * V_604 ,
T_1 V_574 , bool V_1528 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
F_408 ( V_184 , V_604 , V_574 , V_1528 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1408 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_50 ( V_53 , V_485 , V_522 , V_604 ) ||
F_102 ( V_53 , V_1261 , V_574 ) ||
( V_1528 && F_30 ( V_53 , V_1507 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_409 ( struct V_18 * V_18 ,
const T_2 * V_1529 , T_10 V_47 ,
int V_1502 , int V_1503 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
struct V_1409 * V_1410 ;
F_410 ( V_18 , V_1529 , V_47 , V_1502 , V_1503 ) ;
F_227 ( & V_7 -> V_1413 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_72 ( V_47 + 100 , V_1460 ) ;
if ( ! V_53 ) {
F_229 ( & V_7 -> V_1413 ) ;
return;
}
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1287 ) ;
if ( ! V_257 )
goto V_59;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1502 &&
F_29 ( V_53 , V_463 , V_1502 ) ) ||
( V_1503 &&
F_29 ( V_53 , V_1504 , V_1503 ) ) ||
F_50 ( V_53 , V_1286 , V_47 , V_1529 ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_383 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1410 -> V_1414 ) ;
}
F_229 ( & V_7 -> V_1413 ) ;
return;
V_59:
F_229 ( & V_7 -> V_1413 ) ;
if ( V_257 )
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
void F_411 ( struct V_1 * V_17 ,
struct V_1530 * V_1531 ,
T_11 V_1231 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
int V_1347 = 200 ;
F_412 ( V_17 -> V_18 , V_17 , V_1531 ) ;
if ( V_1531 )
V_1347 += V_1531 -> V_1532 ;
V_53 = F_72 ( V_1347 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1533 ) ;
if ( ! V_257 )
goto V_584;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_584;
if ( V_17 -> V_19 && F_29 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_584;
if ( V_1531 ) {
struct V_4 * V_1534 ;
V_1534 = F_46 ( V_53 , V_1349 ) ;
if ( V_1531 -> V_411 &&
F_30 ( V_53 , V_190 ) )
goto V_584;
if ( V_1531 -> V_1351 &&
F_30 ( V_53 , V_192 ) )
goto V_584;
if ( V_1531 -> V_1352 &&
F_30 ( V_53 , V_196 ) )
goto V_584;
if ( V_1531 -> V_1353 &&
F_30 ( V_53 , V_198 ) )
goto V_584;
if ( V_1531 -> V_1354 &&
F_30 ( V_53 , V_200 ) )
goto V_584;
if ( V_1531 -> V_1355 &&
F_30 ( V_53 , V_202 ) )
goto V_584;
if ( V_1531 -> V_1535 >= 0 &&
F_29 ( V_53 , V_212 ,
V_1531 -> V_1535 ) )
goto V_584;
if ( V_1531 -> V_1536 )
F_30 ( V_53 , V_1537 ) ;
if ( V_1531 -> V_1538 )
F_30 ( V_53 ,
V_1539 ) ;
if ( V_1531 -> V_1540 )
F_30 ( V_53 ,
V_1541 ) ;
if ( V_1531 -> V_1542 ) {
V_22 V_1543 = V_1544 ;
V_22 V_1545 = V_1546 ;
if ( ! V_1531 -> V_1547 ) {
V_1543 =
V_1548 ;
V_1545 =
V_1549 ;
}
if ( V_1531 -> V_1550 &&
F_29 ( V_53 , V_1545 , V_1531 -> V_1550 ) )
goto V_584;
if ( F_50 ( V_53 , V_1543 , V_1531 -> V_1532 ,
V_1531 -> V_1542 ) )
goto V_584;
}
F_47 ( V_53 , V_1534 ) ;
}
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_584:
F_73 ( V_53 ) ;
}
void F_413 ( struct V_25 * V_184 , const T_2 * V_1250 ,
enum V_1254 V_1551 ,
T_3 V_1208 , T_11 V_1231 )
{
struct V_1 * V_17 = V_184 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
F_414 ( V_17 -> V_18 , V_184 , V_1250 , V_1551 ,
V_1208 ) ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1552 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_53 , V_10 , V_184 -> V_20 ) ||
F_54 ( V_53 , V_1256 , V_1551 ) ||
F_50 ( V_53 , V_485 , V_522 , V_1250 ) ||
( V_1208 > 0 &&
F_53 ( V_53 , V_1209 , V_1208 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_1231 ) ;
return;
V_59:
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
static int F_415 ( struct V_1553 * V_1554 ,
unsigned long V_256 ,
void * V_1555 )
{
struct V_1556 * V_1557 = V_1555 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1409 * V_1410 , * V_24 ;
if ( V_256 != V_1558 )
return V_1559 ;
F_203 () ;
F_416 (rdev, &cfg80211_rdev_list, list) {
F_416 (wdev, &rdev->wdev_list, list)
F_417 ( V_17 , V_1557 -> V_49 ) ;
F_227 ( & V_7 -> V_1413 ) ;
F_418 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1410 -> V_1414 == V_1557 -> V_49 ) {
F_419 ( & V_1410 -> V_567 ) ;
F_42 ( V_1410 ) ;
break;
}
}
F_229 ( & V_7 -> V_1413 ) ;
}
F_205 () ;
return V_1559 ;
}
void F_420 ( struct V_25 * V_19 ,
struct V_1560 * V_1561 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_257 ;
F_421 ( V_18 , V_19 , V_1561 ) ;
if ( ! V_1561 -> V_1562 )
return;
V_53 = F_72 ( V_533 , V_126 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1563 ) ;
if ( ! V_257 ) {
F_73 ( V_53 ) ;
return;
}
F_29 ( V_53 , V_26 , V_7 -> V_14 ) ;
F_29 ( V_53 , V_10 , V_19 -> V_20 ) ;
F_50 ( V_53 , V_485 , V_522 , V_1561 -> V_1562 ) ;
if ( V_1561 -> V_1110 )
F_50 ( V_53 , V_610 , V_1561 -> V_1564 , V_1561 -> V_1110 ) ;
if ( V_1561 -> V_1565 )
F_50 ( V_53 , V_1566 , V_1561 -> V_1567 ,
V_1561 -> V_1565 ) ;
F_64 ( V_53 , V_257 ) ;
F_260 ( F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1462 . V_705 , V_126 ) ;
}
void F_422 ( struct V_1 * V_17 , T_11 V_1231 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_257 ;
V_22 V_1414 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1429 )
return;
V_1414 = V_7 -> V_1429 ;
V_7 -> V_1429 = 0 ;
V_53 = F_72 ( V_533 , V_1231 ) ;
if ( ! V_53 )
return;
V_257 = F_26 ( V_53 , 0 , 0 , 0 , V_1568 ) ;
if ( ! V_257 )
goto V_59;
if ( F_29 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_64 ( V_53 , V_257 ) ;
F_383 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1414 ) ;
return;
V_59:
if ( V_257 )
F_65 ( V_53 , V_257 ) ;
F_73 ( V_53 ) ;
}
int F_423 ( void )
{
int V_35 ;
V_35 = F_424 ( & V_38 ,
V_1569 , F_425 ( V_1569 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = F_426 ( & V_38 , & V_1442 ) ;
if ( V_35 )
goto V_1570;
V_35 = F_426 ( & V_38 , & V_1445 ) ;
if ( V_35 )
goto V_1570;
V_35 = F_426 ( & V_38 , & V_1459 ) ;
if ( V_35 )
goto V_1570;
V_35 = F_426 ( & V_38 , & V_1462 ) ;
if ( V_35 )
goto V_1570;
#ifdef F_62
V_35 = F_426 ( & V_38 , & V_1232 ) ;
if ( V_35 )
goto V_1570;
#endif
V_35 = F_427 ( & V_1571 ) ;
if ( V_35 )
goto V_1570;
return 0 ;
V_1570:
F_428 ( & V_38 ) ;
return V_35 ;
}
void F_429 ( void )
{
F_430 ( & V_1571 ) ;
F_428 ( & V_38 ) ;
}
