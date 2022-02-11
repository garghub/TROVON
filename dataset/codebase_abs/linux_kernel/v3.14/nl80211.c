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
if ( F_28 ( V_53 , V_57 ,
V_55 -> V_58 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_60 ) &&
F_29 ( V_53 , V_61 ) )
goto V_59;
if ( V_55 -> V_51 & V_62 ) {
if ( F_29 ( V_53 , V_63 ) )
goto V_59;
if ( F_29 ( V_53 , V_64 ) )
goto V_59;
}
if ( V_55 -> V_51 & V_65 ) {
if ( F_29 ( V_53 , V_66 ) )
goto V_59;
if ( V_56 ) {
V_22 time ;
time = F_30 ( V_55 -> V_67 ) ;
if ( F_28 ( V_53 , V_68 ,
V_55 -> V_69 ) )
goto V_59;
if ( F_28 ( V_53 , V_70 ,
time ) )
goto V_59;
}
}
if ( V_56 ) {
if ( ( V_55 -> V_51 & V_71 ) &&
F_29 ( V_53 , V_72 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_73 ) &&
F_29 ( V_53 , V_74 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_75 ) &&
F_29 ( V_53 , V_76 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_77 ) &&
F_29 ( V_53 , V_78 ) )
goto V_59;
}
if ( F_28 ( V_53 , V_79 ,
F_31 ( V_55 -> V_80 ) ) )
goto V_59;
return 0 ;
V_59:
return - V_81 ;
}
static int F_32 ( struct V_4 * V_82 , struct V_83 * V_84 )
{
struct V_4 * V_85 [ V_86 + 1 ] ;
int V_35 = F_33 ( V_85 , V_86 , V_82 ,
V_87 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_88 = ! ! V_85 [ V_89 ] ;
V_84 -> V_90 = ! ! V_85 [ V_91 ] ;
if ( V_84 -> V_88 ) {
V_84 -> V_92 = true ;
V_84 -> V_93 = true ;
}
if ( V_84 -> V_90 )
V_84 -> V_93 = true ;
if ( V_85 [ V_94 ] )
V_84 -> V_95 = F_34 ( V_85 [ V_94 ] ) ;
if ( V_85 [ V_96 ] ) {
V_84 -> V_97 . V_82 = F_23 ( V_85 [ V_96 ] ) ;
V_84 -> V_97 . V_98 = F_24 ( V_85 [ V_96 ] ) ;
}
if ( V_85 [ V_99 ] ) {
V_84 -> V_97 . V_50 = F_23 ( V_85 [ V_99 ] ) ;
V_84 -> V_97 . V_100 = F_24 ( V_85 [ V_99 ] ) ;
}
if ( V_85 [ V_101 ] )
V_84 -> V_97 . V_102 = F_4 ( V_85 [ V_101 ] ) ;
if ( V_85 [ V_103 ] ) {
V_84 -> type = F_4 ( V_85 [ V_103 ] ) ;
if ( V_84 -> type < 0 || V_84 -> type >= V_104 )
return - V_16 ;
}
if ( V_85 [ V_105 ] ) {
struct V_4 * V_106 [ V_107 ] ;
V_35 = F_33 ( V_106 , V_107 - 1 ,
V_85 [ V_105 ] ,
V_108 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_92 = V_106 [ V_109 ] ;
V_84 -> V_93 = V_106 [ V_110 ] ;
}
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , struct V_83 * V_84 )
{
if ( V_30 -> V_5 [ V_111 ] ) {
V_84 -> V_97 . V_82 = F_23 ( V_30 -> V_5 [ V_111 ] ) ;
V_84 -> V_97 . V_98 = F_24 ( V_30 -> V_5 [ V_111 ] ) ;
}
if ( V_30 -> V_5 [ V_112 ] ) {
V_84 -> V_97 . V_50 = F_23 ( V_30 -> V_5 [ V_112 ] ) ;
V_84 -> V_97 . V_100 = F_24 ( V_30 -> V_5 [ V_112 ] ) ;
}
if ( V_30 -> V_5 [ V_113 ] )
V_84 -> V_95 = F_34 ( V_30 -> V_5 [ V_113 ] ) ;
if ( V_30 -> V_5 [ V_114 ] )
V_84 -> V_97 . V_102 = F_4 ( V_30 -> V_5 [ V_114 ] ) ;
V_84 -> V_88 = ! ! V_30 -> V_5 [ V_115 ] ;
V_84 -> V_90 = ! ! V_30 -> V_5 [ V_116 ] ;
if ( V_84 -> V_88 ) {
V_84 -> V_92 = true ;
V_84 -> V_93 = true ;
}
if ( V_84 -> V_90 )
V_84 -> V_93 = true ;
if ( V_30 -> V_5 [ V_117 ] ) {
V_84 -> type = F_4 ( V_30 -> V_5 [ V_117 ] ) ;
if ( V_84 -> type < 0 || V_84 -> type >= V_104 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_118 ] ) {
struct V_4 * V_106 [ V_107 ] ;
int V_35 = F_33 (
V_106 , V_107 - 1 ,
V_30 -> V_5 [ V_118 ] ,
V_108 ) ;
if ( V_35 )
return V_35 ;
V_84 -> V_92 = V_106 [ V_109 ] ;
V_84 -> V_93 = V_106 [ V_110 ] ;
}
return 0 ;
}
static int F_36 ( struct V_29 * V_30 , struct V_83 * V_84 )
{
int V_35 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_95 = - 1 ;
V_84 -> type = - 1 ;
if ( V_30 -> V_5 [ V_119 ] )
V_35 = F_32 ( V_30 -> V_5 [ V_119 ] , V_84 ) ;
else
V_35 = F_35 ( V_30 , V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_84 -> V_88 && V_84 -> V_90 )
return - V_16 ;
if ( V_84 -> V_90 ) {
if ( V_84 -> V_92 || ! V_84 -> V_93 )
return - V_16 ;
}
if ( V_84 -> V_95 != - 1 ) {
if ( V_84 -> V_90 ) {
if ( V_84 -> V_95 < 4 || V_84 -> V_95 > 5 )
return - V_16 ;
} else if ( V_84 -> V_88 ) {
if ( V_84 -> V_95 < 0 || V_84 -> V_95 > 3 )
return - V_16 ;
} else {
if ( V_84 -> V_95 < 0 || V_84 -> V_95 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_120 *
F_37 ( struct V_6 * V_7 ,
struct V_4 * V_121 , bool * V_122 )
{
struct V_83 V_123 ;
struct V_4 * V_82 ;
struct V_120 * V_8 ;
int V_124 , V_35 , V_88 = 0 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_125 ) ;
if ( ! V_8 )
return F_3 ( - V_126 ) ;
V_8 -> V_88 = - 1 ;
V_8 -> V_90 = - 1 ;
F_39 (key, keys, rem) {
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_95 = - 1 ;
V_35 = F_32 ( V_82 , & V_123 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_123 . V_97 . V_82 )
goto error;
if ( V_123 . V_95 < 0 || V_123 . V_95 > 4 )
goto error;
if ( V_123 . V_88 ) {
if ( V_88 )
goto error;
V_88 = 1 ;
V_8 -> V_88 = V_123 . V_95 ;
if ( ! V_123 . V_92 || ! V_123 . V_93 )
goto error;
} else if ( V_123 . V_90 )
goto error;
V_35 = F_40 ( V_7 , & V_123 . V_97 ,
V_123 . V_95 , false , NULL ) ;
if ( V_35 )
goto error;
V_8 -> V_127 [ V_123 . V_95 ] . V_102 = V_123 . V_97 . V_102 ;
V_8 -> V_127 [ V_123 . V_95 ] . V_98 = V_123 . V_97 . V_98 ;
V_8 -> V_127 [ V_123 . V_95 ] . V_82 = V_8 -> V_128 [ V_123 . V_95 ] ;
memcpy ( V_8 -> V_128 [ V_123 . V_95 ] , V_123 . V_97 . V_82 , V_123 . V_97 . V_98 ) ;
if ( V_123 . V_97 . V_102 == V_129 ||
V_123 . V_97 . V_102 == V_130 ) {
if ( V_122 )
* V_122 = true ;
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
switch ( V_17 -> V_131 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
break;
case V_136 :
case V_137 :
case V_138 :
if ( ! V_17 -> V_139 )
return - V_140 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_44 ( struct V_31 * V_53 , V_22 V_45 , T_3 V_141 )
{
struct V_4 * V_142 = F_45 ( V_53 , V_45 ) ;
int V_143 ;
if ( ! V_142 )
goto V_59;
V_143 = 0 ;
while ( V_141 ) {
if ( ( V_141 & 1 ) && F_29 ( V_53 , V_143 ) )
goto V_59;
V_141 >>= 1 ;
V_143 ++ ;
}
F_46 ( V_53 , V_142 ) ;
return 0 ;
V_59:
return - V_81 ;
}
static int F_47 ( struct V_18 * V_18 ,
struct V_31 * V_53 ,
bool V_56 )
{
struct V_4 * V_144 ;
int V_143 , V_145 ;
V_144 = F_45 ( V_53 ,
V_146 ) ;
if ( ! V_144 )
goto V_59;
for ( V_143 = 0 ; V_143 < V_18 -> V_147 ; V_143 ++ ) {
const struct V_148 * V_149 ;
struct V_4 * V_150 , * V_151 ;
V_149 = & V_18 -> V_152 [ V_143 ] ;
V_150 = F_45 ( V_53 , V_143 + 1 ) ;
if ( ! V_150 )
goto V_59;
V_151 = F_45 ( V_53 , V_153 ) ;
if ( ! V_151 )
goto V_59;
for ( V_145 = 0 ; V_145 < V_149 -> V_154 ; V_145 ++ ) {
struct V_4 * V_155 ;
V_155 = F_45 ( V_53 , V_145 + 1 ) ;
if ( ! V_155 )
goto V_59;
if ( F_28 ( V_53 , V_156 ,
V_149 -> V_157 [ V_145 ] . V_158 ) )
goto V_59;
if ( F_44 ( V_53 , V_159 ,
V_149 -> V_157 [ V_145 ] . V_160 ) )
goto V_59;
F_46 ( V_53 , V_155 ) ;
}
F_46 ( V_53 , V_151 ) ;
if ( V_149 -> V_161 &&
F_29 ( V_53 , V_162 ) )
goto V_59;
if ( F_28 ( V_53 , V_163 ,
V_149 -> V_164 ) ||
F_28 ( V_53 , V_165 ,
V_149 -> V_166 ) )
goto V_59;
if ( V_56 &&
F_28 ( V_53 , V_167 ,
V_149 -> V_168 ) )
goto V_59;
F_46 ( V_53 , V_150 ) ;
}
F_46 ( V_53 , V_144 ) ;
return 0 ;
V_59:
return - V_81 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
const struct V_169 * V_170 = V_7 -> V_18 . V_171 -> V_170 ;
struct V_4 * V_172 ;
if ( ! V_170 )
return 0 ;
V_172 = F_45 ( V_53 , V_173 ) ;
if ( ! V_172 )
return - V_81 ;
if ( F_28 ( V_53 , V_174 ,
V_170 -> V_175 ) )
return - V_81 ;
if ( F_28 ( V_53 , V_174 ,
V_170 -> V_175 ) )
return - V_81 ;
if ( V_170 -> V_50 && F_29 ( V_53 , V_176 ) )
return - V_81 ;
if ( V_170 -> V_177 && F_49 ( V_53 , V_178 ,
sizeof( * V_170 -> V_177 ) , V_170 -> V_177 ) )
return - V_81 ;
if ( F_28 ( V_53 , V_179 ,
V_170 -> V_180 ) )
return - V_81 ;
if ( F_28 ( V_53 , V_181 ,
V_170 -> V_182 ) )
return - V_81 ;
F_46 ( V_53 , V_172 ) ;
return 0 ;
}
static int F_50 ( struct V_31 * V_53 ,
struct V_6 * V_183 ,
bool V_56 )
{
struct V_4 * V_184 ;
if ( ! V_183 -> V_18 . V_171 )
return 0 ;
V_184 = F_45 ( V_53 , V_185 ) ;
if ( ! V_184 )
return - V_81 ;
if ( ( ( V_183 -> V_18 . V_171 -> V_51 & V_186 ) &&
F_29 ( V_53 , V_187 ) ) ||
( ( V_183 -> V_18 . V_171 -> V_51 & V_188 ) &&
F_29 ( V_53 , V_189 ) ) ||
( ( V_183 -> V_18 . V_171 -> V_51 & V_190 ) &&
F_29 ( V_53 , V_191 ) ) ||
( ( V_183 -> V_18 . V_171 -> V_51 & V_192 ) &&
F_29 ( V_53 , V_193 ) ) ||
( ( V_183 -> V_18 . V_171 -> V_51 & V_194 ) &&
F_29 ( V_53 , V_195 ) ) ||
( ( V_183 -> V_18 . V_171 -> V_51 & V_196 ) &&
F_29 ( V_53 , V_197 ) ) ||
( ( V_183 -> V_18 . V_171 -> V_51 & V_198 ) &&
F_29 ( V_53 , V_199 ) ) ||
( ( V_183 -> V_18 . V_171 -> V_51 & V_200 ) &&
F_29 ( V_53 , V_201 ) ) )
return - V_81 ;
if ( V_183 -> V_18 . V_171 -> V_202 ) {
struct V_203 V_204 = {
. V_205 = V_183 -> V_18 . V_171 -> V_202 ,
. V_206 = V_183 -> V_18 . V_171 -> V_207 ,
. V_208 = V_183 -> V_18 . V_171 -> V_209 ,
. V_210 = V_183 -> V_18 . V_171 -> V_210 ,
} ;
if ( F_49 ( V_53 , V_211 ,
sizeof( V_204 ) , & V_204 ) )
return - V_81 ;
}
if ( V_56 && F_48 ( V_183 , V_53 ) )
return - V_81 ;
F_46 ( V_53 , V_184 ) ;
return 0 ;
}
static int F_51 ( struct V_31 * V_53 ,
struct V_6 * V_183 )
{
struct V_212 V_213 ;
if ( ! V_183 -> V_18 . V_214 )
return 0 ;
V_213 . V_215 = V_183 -> V_18 . V_214 -> V_216 ;
V_213 . V_217 = V_183 -> V_18 . V_214 -> V_217 ;
V_213 . V_204 . V_205 = V_183 -> V_18 . V_214 -> V_202 ;
V_213 . V_204 . V_206 = V_183 -> V_18 . V_214 -> V_207 ;
V_213 . V_204 . V_208 = V_183 -> V_18 . V_214 -> V_209 ;
V_213 . V_204 . V_210 = V_183 -> V_18 . V_214 -> V_210 ;
if ( F_49 ( V_53 , V_218 , sizeof( V_213 ) , & V_213 ) )
return - V_81 ;
return 0 ;
}
static int F_52 ( struct V_31 * V_53 ,
struct V_219 * V_220 )
{
struct V_4 * V_221 , * V_222 ;
struct V_223 * V_224 ;
int V_143 ;
if ( V_220 -> V_225 . V_226 &&
( F_49 ( V_53 , V_227 ,
sizeof( V_220 -> V_225 . V_228 ) ,
& V_220 -> V_225 . V_228 ) ||
F_53 ( V_53 , V_229 ,
V_220 -> V_225 . V_230 ) ||
F_54 ( V_53 , V_231 ,
V_220 -> V_225 . V_232 ) ||
F_54 ( V_53 , V_233 ,
V_220 -> V_225 . V_234 ) ) )
return - V_81 ;
if ( V_220 -> V_235 . V_236 &&
( F_49 ( V_53 , V_237 ,
sizeof( V_220 -> V_235 . V_238 ) ,
& V_220 -> V_235 . V_238 ) ||
F_28 ( V_53 , V_239 ,
V_220 -> V_235 . V_230 ) ) )
return - V_81 ;
V_221 = F_45 ( V_53 , V_240 ) ;
if ( ! V_221 )
return - V_81 ;
for ( V_143 = 0 ; V_143 < V_220 -> V_241 ; V_143 ++ ) {
V_222 = F_45 ( V_53 , V_143 ) ;
if ( ! V_222 )
return - V_81 ;
V_224 = & V_220 -> V_242 [ V_143 ] ;
if ( F_28 ( V_53 , V_243 ,
V_224 -> V_244 ) )
return - V_81 ;
if ( ( V_224 -> V_51 & V_245 ) &&
F_29 ( V_53 ,
V_246 ) )
return - V_81 ;
F_46 ( V_53 , V_222 ) ;
}
F_46 ( V_53 , V_221 ) ;
return 0 ;
}
static int
F_55 ( struct V_31 * V_53 ,
const struct V_247 * V_248 )
{
T_3 V_249 ;
struct V_4 * V_250 , * V_251 ;
enum V_252 V_253 ;
int V_143 ;
if ( ! V_248 )
return 0 ;
V_251 = F_45 ( V_53 , V_254 ) ;
if ( ! V_251 )
return - V_81 ;
for ( V_253 = 0 ; V_253 < V_255 ; V_253 ++ ) {
V_250 = F_45 ( V_53 , V_253 ) ;
if ( ! V_250 )
return - V_81 ;
V_143 = 0 ;
V_249 = V_248 [ V_253 ] . V_256 ;
while ( V_249 ) {
if ( ( V_249 & 1 ) &&
F_53 ( V_53 , V_257 ,
( V_143 << 4 ) | V_258 ) )
return - V_81 ;
V_249 >>= 1 ;
V_143 ++ ;
}
F_46 ( V_53 , V_250 ) ;
}
F_46 ( V_53 , V_251 ) ;
V_251 = F_45 ( V_53 , V_259 ) ;
if ( ! V_251 )
return - V_81 ;
for ( V_253 = 0 ; V_253 < V_255 ; V_253 ++ ) {
V_250 = F_45 ( V_53 , V_253 ) ;
if ( ! V_250 )
return - V_81 ;
V_143 = 0 ;
V_249 = V_248 [ V_253 ] . V_260 ;
while ( V_249 ) {
if ( ( V_249 & 1 ) &&
F_53 ( V_53 , V_257 ,
( V_143 << 4 ) | V_258 ) )
return - V_81 ;
V_249 >>= 1 ;
V_143 ++ ;
}
F_46 ( V_53 , V_250 ) ;
}
F_46 ( V_53 , V_251 ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_183 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_261 * V_262 )
{
void * V_263 ;
struct V_4 * V_264 , * V_265 ;
struct V_4 * V_266 , * V_267 ;
struct V_4 * V_268 ;
enum V_269 V_270 ;
struct V_54 * V_55 ;
int V_143 ;
const struct V_247 * V_248 =
V_183 -> V_18 . V_248 ;
V_22 V_271 ;
V_263 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_272 ) ;
if ( ! V_263 )
return - V_81 ;
if ( F_57 ( ! V_262 ) )
return - V_16 ;
if ( F_28 ( V_53 , V_26 , V_183 -> V_14 ) ||
F_58 ( V_53 , V_273 ,
F_59 ( & V_183 -> V_18 ) ) ||
F_28 ( V_53 , V_274 ,
V_275 ) )
goto V_59;
switch ( V_262 -> V_276 ) {
case 0 :
if ( F_54 ( V_53 , V_277 ,
V_183 -> V_18 . V_278 ) ||
F_54 ( V_53 , V_279 ,
V_183 -> V_18 . V_280 ) ||
F_28 ( V_53 , V_281 ,
V_183 -> V_18 . V_282 ) ||
F_28 ( V_53 , V_283 ,
V_183 -> V_18 . V_284 ) ||
F_54 ( V_53 , V_285 ,
V_183 -> V_18 . V_286 ) ||
F_54 ( V_53 , V_287 ,
V_183 -> V_18 . V_288 ) ||
F_54 ( V_53 , V_289 ,
V_183 -> V_18 . V_290 ) ||
F_53 ( V_53 , V_291 ,
V_183 -> V_18 . V_292 ) ||
F_53 ( V_53 , V_293 ,
V_183 -> V_18 . V_294 ) ||
F_54 ( V_53 , V_295 ,
V_183 -> V_18 . V_296 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_297 ) &&
F_29 ( V_53 , V_298 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_299 ) &&
F_29 ( V_53 , V_300 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_301 ) &&
F_29 ( V_53 , V_302 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_303 ) &&
F_29 ( V_53 , V_304 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_305 ) &&
F_29 ( V_53 , V_306 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_307 ) &&
F_29 ( V_53 , V_308 ) )
goto V_59;
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
case 1 :
if ( F_49 ( V_53 , V_310 ,
sizeof( V_22 ) * V_183 -> V_18 . V_311 ,
V_183 -> V_18 . V_312 ) )
goto V_59;
if ( F_54 ( V_53 , V_313 ,
V_183 -> V_18 . V_314 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_315 ) &&
F_29 ( V_53 , V_316 ) )
goto V_59;
if ( F_28 ( V_53 , V_317 ,
V_183 -> V_18 . V_318 ) ||
F_28 ( V_53 , V_319 ,
V_183 -> V_18 . V_320 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_321 ) &&
F_28 ( V_53 , V_322 ,
V_183 -> V_18 . V_323 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_318 ||
V_183 -> V_18 . V_320 ) &&
V_183 -> V_324 -> V_325 ) {
V_22 V_326 = 0 , V_327 = 0 ;
int V_328 ;
V_328 = F_60 ( V_183 , & V_326 , & V_327 ) ;
if ( ! V_328 ) {
if ( F_28 ( V_53 ,
V_329 ,
V_326 ) ||
F_28 ( V_53 ,
V_330 ,
V_327 ) )
goto V_59;
}
}
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
case 2 :
if ( F_44 ( V_53 , V_331 ,
V_183 -> V_18 . V_332 ) )
goto V_59;
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
case 3 :
V_264 = F_45 ( V_53 , V_333 ) ;
if ( ! V_264 )
goto V_59;
for ( V_270 = V_262 -> V_334 ;
V_270 < V_335 ; V_270 ++ ) {
struct V_219 * V_220 ;
V_220 = V_183 -> V_18 . V_336 [ V_270 ] ;
if ( ! V_220 )
continue;
V_265 = F_45 ( V_53 , V_270 ) ;
if ( ! V_265 )
goto V_59;
switch ( V_262 -> V_337 ) {
case 0 :
if ( F_52 ( V_53 , V_220 ) )
goto V_59;
V_262 -> V_337 ++ ;
if ( V_262 -> V_309 )
break;
default:
V_266 = F_45 (
V_53 , V_338 ) ;
if ( ! V_266 )
goto V_59;
for ( V_143 = V_262 -> V_337 - 1 ;
V_143 < V_220 -> V_339 ;
V_143 ++ ) {
V_267 = F_45 ( V_53 , V_143 ) ;
if ( ! V_267 )
goto V_59;
V_55 = & V_220 -> V_340 [ V_143 ] ;
if ( F_27 (
V_53 , V_55 ,
V_262 -> V_309 ) )
goto V_59;
F_46 ( V_53 , V_267 ) ;
if ( V_262 -> V_309 )
break;
}
if ( V_143 < V_220 -> V_339 )
V_262 -> V_337 = V_143 + 2 ;
else
V_262 -> V_337 = 0 ;
F_46 ( V_53 , V_266 ) ;
}
F_46 ( V_53 , V_265 ) ;
if ( V_262 -> V_309 ) {
if ( V_262 -> V_337 )
V_270 -- ;
break;
}
}
F_46 ( V_53 , V_264 ) ;
if ( V_270 < V_335 )
V_262 -> V_334 = V_270 + 1 ;
else
V_262 -> V_334 = 0 ;
if ( V_262 -> V_334 == 0 && V_262 -> V_337 == 0 )
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
case 4 :
V_268 = F_45 ( V_53 , V_341 ) ;
if ( ! V_268 )
goto V_59;
V_143 = 0 ;
#define F_61 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_61 ( V_342 , V_343 ) ;
F_61 ( V_344 , V_345 ) ;
F_61 ( V_346 , V_347 ) ;
F_61 ( V_348 , V_349 ) ;
F_61 ( V_350 , V_351 ) ;
F_61 ( V_352 , V_353 ) ;
F_61 ( V_354 , V_355 ) ;
F_61 ( V_356 , V_357 ) ;
F_61 ( V_358 , V_359 ) ;
F_61 ( V_360 , V_361 ) ;
F_61 ( V_362 , V_363 ) ;
F_61 ( V_364 , V_365 ) ;
F_61 ( V_366 , V_367 ) ;
F_61 ( V_368 , V_369 ) ;
F_61 ( V_370 , V_371 ) ;
F_61 ( V_372 , V_373 ) ;
F_61 ( V_374 , V_375 ) ;
if ( V_183 -> V_18 . V_51 & V_376 )
F_61 ( V_377 , V_378 ) ;
F_61 ( V_379 , V_380 ) ;
F_61 ( V_381 , V_382 ) ;
F_61 ( V_383 , V_384 ) ;
if ( V_183 -> V_18 . V_51 & V_385 ) {
V_143 ++ ;
if ( F_28 ( V_53 , V_143 , V_386 ) )
goto V_59;
}
if ( V_183 -> V_324 -> V_387 || V_183 -> V_324 -> V_348 ||
V_183 -> V_324 -> V_368 ) {
V_143 ++ ;
if ( F_28 ( V_53 , V_143 , V_388 ) )
goto V_59;
}
F_61 ( V_389 , V_390 ) ;
if ( V_183 -> V_18 . V_51 & V_305 ) {
F_61 ( V_391 , V_392 ) ;
F_61 ( V_393 , V_394 ) ;
}
if ( V_183 -> V_18 . V_51 & V_395 )
F_61 ( V_396 , V_397 ) ;
F_61 ( V_398 , V_399 ) ;
F_61 ( V_400 , V_401 ) ;
if ( V_183 -> V_18 . V_51 & V_402 ) {
V_143 ++ ;
if ( F_28 ( V_53 , V_143 , V_403 ) )
goto V_59;
}
F_61 ( V_404 , V_405 ) ;
F_61 ( V_406 , V_407 ) ;
if ( V_262 -> V_309 ) {
F_61 ( V_408 , V_409 ) ;
F_61 ( V_410 , V_411 ) ;
if ( V_183 -> V_18 . V_51 & V_412 )
F_61 ( V_413 , V_414 ) ;
}
F_61 ( V_415 , V_416 ) ;
#ifdef F_62
F_61 ( V_417 , V_418 ) ;
#endif
#undef F_61
if ( V_183 -> V_324 -> V_419 || V_183 -> V_324 -> V_358 ) {
V_143 ++ ;
if ( F_28 ( V_53 , V_143 , V_420 ) )
goto V_59;
}
if ( V_183 -> V_324 -> V_421 || V_183 -> V_324 -> V_362 ) {
V_143 ++ ;
if ( F_28 ( V_53 , V_143 , V_422 ) )
goto V_59;
}
F_46 ( V_53 , V_268 ) ;
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
case 5 :
if ( V_183 -> V_324 -> V_377 &&
( V_183 -> V_18 . V_51 & V_376 ) &&
F_28 ( V_53 ,
V_423 ,
V_183 -> V_18 . V_424 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_425 ) &&
F_29 ( V_53 , V_426 ) )
goto V_59;
if ( F_55 ( V_53 , V_248 ) )
goto V_59;
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
case 6 :
#ifdef F_63
if ( F_50 ( V_53 , V_183 , V_262 -> V_309 ) )
goto V_59;
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
#else
V_262 -> V_276 ++ ;
#endif
case 7 :
if ( F_44 ( V_53 , V_427 ,
V_183 -> V_18 . V_428 ) )
goto V_59;
if ( F_47 ( & V_183 -> V_18 , V_53 ,
V_262 -> V_309 ) )
goto V_59;
V_262 -> V_276 ++ ;
if ( V_262 -> V_309 )
break;
case 8 :
if ( ( V_183 -> V_18 . V_51 & V_429 ) &&
F_28 ( V_53 , V_430 ,
V_183 -> V_18 . V_431 ) )
goto V_59;
V_271 = V_183 -> V_18 . V_271 ;
if ( V_262 -> V_309 )
V_271 |= V_432 ;
if ( F_28 ( V_53 , V_433 , V_271 ) )
goto V_59;
if ( V_183 -> V_18 . V_434 &&
F_49 ( V_53 , V_435 ,
sizeof( * V_183 -> V_18 . V_434 ) ,
V_183 -> V_18 . V_434 ) )
goto V_59;
if ( V_183 -> V_18 . V_51 & V_429 &&
V_183 -> V_18 . V_436 &&
F_28 ( V_53 , V_437 ,
V_183 -> V_18 . V_436 ) )
goto V_59;
V_262 -> V_276 ++ ;
break;
case 9 :
if ( V_183 -> V_18 . V_438 &&
( F_49 ( V_53 , V_439 ,
V_183 -> V_18 . V_440 ,
V_183 -> V_18 . V_438 ) ||
F_49 ( V_53 , V_441 ,
V_183 -> V_18 . V_440 ,
V_183 -> V_18 . V_442 ) ) )
goto V_59;
if ( V_183 -> V_18 . V_443 &&
F_49 ( V_53 , V_444 ,
sizeof( * V_183 -> V_18 . V_443 ) ,
V_183 -> V_18 . V_443 ) )
goto V_59;
V_262 -> V_276 ++ ;
break;
case 10 :
if ( F_51 ( V_53 , V_183 ) )
goto V_59;
if ( ( V_183 -> V_18 . V_51 & V_445 ) &&
( F_29 ( V_53 , V_446 ) ||
F_29 ( V_53 , V_447 ) ) )
goto V_59;
V_262 -> V_276 ++ ;
break;
case 11 :
if ( V_183 -> V_18 . V_448 ) {
const struct V_449 * V_30 ;
struct V_4 * V_450 ;
V_450 = F_45 ( V_53 , V_451 ) ;
if ( ! V_450 )
goto V_59;
for ( V_143 = 0 ; V_143 < V_183 -> V_18 . V_448 ; V_143 ++ ) {
V_30 = & V_183 -> V_18 . V_452 [ V_143 ] . V_30 ;
if ( F_49 ( V_53 , V_143 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_46 ( V_53 , V_450 ) ;
}
if ( V_183 -> V_18 . V_453 ) {
const struct V_449 * V_30 ;
struct V_4 * V_450 ;
V_450 = F_45 ( V_53 ,
V_454 ) ;
if ( ! V_450 )
goto V_59;
for ( V_143 = 0 ; V_143 < V_183 -> V_18 . V_453 ; V_143 ++ ) {
V_30 = & V_183 -> V_18 . V_455 [ V_143 ] ;
if ( F_49 ( V_53 , V_143 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_46 ( V_53 , V_450 ) ;
}
V_262 -> V_276 = 0 ;
break;
}
return F_64 ( V_53 , V_263 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
static int F_66 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_261 * V_262 )
{
struct V_4 * * V_85 = V_38 . V_40 ;
int V_457 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_85 , V_38 . V_41 , V_42 ) ;
if ( V_457 )
return 0 ;
V_262 -> V_309 = V_85 [ V_458 ] ;
if ( V_85 [ V_26 ] )
V_262 -> V_459 = F_4 ( V_85 [ V_26 ] ) ;
if ( V_85 [ V_12 ] )
V_262 -> V_459 = F_5 ( V_85 [ V_12 ] ) >> 32 ;
if ( V_85 [ V_10 ] ) {
struct V_25 * V_19 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_85 [ V_10 ] ) ;
V_19 = F_10 ( F_16 ( V_32 -> V_44 ) , V_15 ) ;
if ( ! V_19 )
return - V_23 ;
if ( V_19 -> V_28 ) {
V_7 = F_11 (
V_19 -> V_28 -> V_18 ) ;
V_262 -> V_459 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_67 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_95 = 0 , V_457 ;
struct V_261 * V_262 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_183 ;
F_14 () ;
if ( ! V_262 ) {
V_262 = F_38 ( sizeof( * V_262 ) , V_125 ) ;
if ( ! V_262 ) {
F_20 () ;
return - V_126 ;
}
V_262 -> V_459 = - 1 ;
V_457 = F_66 ( V_32 , V_34 , V_262 ) ;
if ( V_457 ) {
F_41 ( V_262 ) ;
F_20 () ;
return V_457 ;
}
V_34 -> args [ 0 ] = ( long ) V_262 ;
}
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_68 ( F_7 ( & V_183 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_95 <= V_262 -> V_460 )
continue;
if ( V_262 -> V_459 != - 1 &&
V_262 -> V_459 != V_183 -> V_14 )
continue;
do {
V_457 = F_56 ( V_183 , V_32 ,
F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_461 ,
V_462 , V_262 ) ;
if ( V_457 < 0 ) {
if ( ( V_457 == - V_81 || V_457 == - V_456 ) &&
! V_32 -> V_47 && ! V_262 -> V_309 &&
V_34 -> V_463 < 4096 ) {
V_34 -> V_463 = 4096 ;
V_262 -> V_276 = 0 ;
F_20 () ;
return 1 ;
}
V_95 -- ;
break;
}
} while ( V_262 -> V_276 > 0 );
break;
}
F_20 () ;
V_262 -> V_460 = V_95 ;
return V_32 -> V_47 ;
}
static int F_70 ( struct V_33 * V_34 )
{
F_41 ( ( void * ) V_34 -> args [ 0 ] ) ;
return 0 ;
}
static int F_71 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_183 = V_30 -> V_464 [ 0 ] ;
struct V_261 V_262 = {} ;
V_53 = F_72 ( 4096 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
if ( F_56 ( V_183 , V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
& V_262 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_81 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_75 ( struct V_4 * V_85 [] ,
struct V_467 * V_468 )
{
if ( ! V_85 [ V_469 ] || ! V_85 [ V_470 ] ||
! V_85 [ V_471 ] || ! V_85 [ V_472 ] ||
! V_85 [ V_473 ] )
return - V_16 ;
V_468 -> V_474 = F_34 ( V_85 [ V_469 ] ) ;
V_468 -> V_475 = F_76 ( V_85 [ V_470 ] ) ;
V_468 -> V_476 = F_76 ( V_85 [ V_471 ] ) ;
V_468 -> V_477 = F_76 ( V_85 [ V_472 ] ) ;
V_468 -> V_478 = F_34 ( V_85 [ V_473 ] ) ;
if ( V_468 -> V_474 >= V_479 )
return - V_16 ;
return 0 ;
}
static bool F_77 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_131 == V_132 ||
V_17 -> V_131 == V_135 ||
V_17 -> V_131 == V_480 ||
V_17 -> V_131 == V_134 ;
}
static int F_78 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_481 * V_482 )
{
V_22 V_483 ;
if ( ! V_30 -> V_5 [ V_484 ] )
return - V_16 ;
V_483 = F_4 ( V_30 -> V_5 [ V_484 ] ) ;
V_482 -> V_55 = F_79 ( & V_7 -> V_18 , V_483 ) ;
V_482 -> V_485 = V_486 ;
V_482 -> V_487 = V_483 ;
V_482 -> V_488 = 0 ;
if ( ! V_482 -> V_55 || V_482 -> V_55 -> V_51 & V_60 )
return - V_16 ;
if ( V_30 -> V_5 [ V_489 ] ) {
enum V_490 V_491 ;
V_491 = F_4 (
V_30 -> V_5 [ V_489 ] ) ;
switch ( V_491 ) {
case V_492 :
case V_493 :
case V_494 :
case V_495 :
F_80 ( V_482 , V_482 -> V_55 ,
V_491 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_496 ] ) {
V_482 -> V_485 =
F_4 ( V_30 -> V_5 [ V_496 ] ) ;
if ( V_30 -> V_5 [ V_497 ] )
V_482 -> V_487 =
F_4 (
V_30 -> V_5 [ V_497 ] ) ;
if ( V_30 -> V_5 [ V_498 ] )
V_482 -> V_488 =
F_4 (
V_30 -> V_5 [ V_498 ] ) ;
}
if ( ! F_81 ( V_482 ) )
return - V_16 ;
if ( ! F_82 ( & V_7 -> V_18 , V_482 ,
V_60 ) )
return - V_16 ;
if ( ( V_482 -> V_485 == V_499 ||
V_482 -> V_485 == V_500 ) &&
! ( V_7 -> V_18 . V_51 & V_445 ) )
return - V_16 ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_29 * V_30 )
{
struct V_481 V_482 ;
int V_8 ;
enum V_252 V_131 = V_480 ;
if ( V_17 )
V_131 = V_17 -> V_131 ;
if ( ! F_77 ( V_17 ) )
return - V_501 ;
V_8 = F_78 ( V_7 , V_30 , & V_482 ) ;
if ( V_8 )
return V_8 ;
switch ( V_131 ) {
case V_132 :
case V_134 :
if ( V_17 -> V_502 ) {
V_8 = - V_503 ;
break;
}
if ( ! F_84 ( & V_7 -> V_18 , & V_482 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_504 = V_482 ;
V_8 = 0 ;
break;
case V_135 :
V_8 = F_85 ( V_7 , V_17 , & V_482 ) ;
break;
case V_480 :
V_8 = F_86 ( V_7 , & V_482 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_87 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_464 [ 1 ] ;
return F_83 ( V_7 , V_19 -> V_28 , V_30 ) ;
}
static int F_88 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
const T_2 * V_505 ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( F_89 ( V_183 ) )
return - V_503 ;
if ( ! V_7 -> V_324 -> V_389 )
return - V_501 ;
if ( V_17 -> V_131 != V_507 )
return - V_501 ;
V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
return F_90 ( V_7 , V_183 , V_505 ) ;
}
static int F_91 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_508 = 0 ;
struct V_4 * V_509 ;
V_22 V_510 ;
T_2 V_278 = 0 , V_280 = 0 ;
V_22 V_282 = 0 , V_284 = 0 ;
T_2 V_286 = 0 ;
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
if ( F_17 ( V_7 ) )
return F_18 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_273 ] )
V_8 = F_93 (
V_7 , F_23 ( V_30 -> V_5 [ V_273 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_511 ] ) {
struct V_467 V_468 ;
struct V_4 * V_85 [ V_512 + 1 ] ;
if ( ! V_7 -> V_324 -> V_513 )
return - V_501 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_131 != V_132 &&
V_19 -> V_28 -> V_131 != V_134 )
return - V_16 ;
if ( ! F_89 ( V_19 ) )
return - V_514 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_94 ( V_85 , V_512 ,
F_23 ( V_509 ) ,
F_24 ( V_509 ) ,
V_515 ) ;
V_8 = F_75 ( V_85 , & V_468 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_95 ( V_7 , V_19 ,
& V_468 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_484 ] ) {
V_8 = F_83 ( V_7 ,
F_77 ( V_17 ) ? V_17 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_516 ] ) {
struct V_1 * V_517 = V_17 ;
enum V_518 type ;
int V_95 , V_519 = 0 ;
if ( ! ( V_7 -> V_18 . V_271 & V_520 ) )
V_517 = NULL ;
if ( ! V_7 -> V_324 -> V_521 )
return - V_501 ;
V_95 = V_516 ;
type = F_4 ( V_30 -> V_5 [ V_95 ] ) ;
if ( ! V_30 -> V_5 [ V_522 ] &&
( type != V_523 ) )
return - V_16 ;
if ( type != V_523 ) {
V_95 = V_522 ;
V_519 = F_4 ( V_30 -> V_5 [ V_95 ] ) ;
}
V_8 = F_96 ( V_7 , V_517 , type , V_519 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_329 ] &&
V_30 -> V_5 [ V_330 ] ) {
V_22 V_326 , V_327 ;
if ( ( ! V_7 -> V_18 . V_318 &&
! V_7 -> V_18 . V_320 ) ||
! V_7 -> V_324 -> V_524 )
return - V_501 ;
V_326 = F_4 ( V_30 -> V_5 [ V_329 ] ) ;
V_327 = F_4 ( V_30 -> V_5 [ V_330 ] ) ;
if ( ( ~ V_326 && ( V_326 & ~ V_7 -> V_18 . V_318 ) ) ||
( ~ V_327 && ( V_327 & ~ V_7 -> V_18 . V_320 ) ) )
return - V_16 ;
V_326 = V_326 & V_7 -> V_18 . V_318 ;
V_327 = V_327 & V_7 -> V_18 . V_320 ;
V_8 = F_97 ( V_7 , V_326 , V_327 ) ;
if ( V_8 )
return V_8 ;
}
V_510 = 0 ;
if ( V_30 -> V_5 [ V_277 ] ) {
V_278 = F_34 (
V_30 -> V_5 [ V_277 ] ) ;
if ( V_278 == 0 )
return - V_16 ;
V_510 |= V_525 ;
}
if ( V_30 -> V_5 [ V_279 ] ) {
V_280 = F_34 (
V_30 -> V_5 [ V_279 ] ) ;
if ( V_280 == 0 )
return - V_16 ;
V_510 |= V_526 ;
}
if ( V_30 -> V_5 [ V_281 ] ) {
V_282 = F_4 (
V_30 -> V_5 [ V_281 ] ) ;
if ( V_282 < 256 )
return - V_16 ;
if ( V_282 != ( V_22 ) - 1 ) {
V_282 &= ~ 0x1 ;
}
V_510 |= V_527 ;
}
if ( V_30 -> V_5 [ V_283 ] ) {
V_284 = F_4 (
V_30 -> V_5 [ V_283 ] ) ;
V_510 |= V_528 ;
}
if ( V_30 -> V_5 [ V_285 ] ) {
V_286 = F_34 (
V_30 -> V_5 [ V_285 ] ) ;
V_510 |= V_529 ;
}
if ( V_510 ) {
T_2 V_530 , V_531 ;
V_22 V_532 , V_533 ;
T_2 V_534 ;
if ( ! V_7 -> V_324 -> V_535 )
return - V_501 ;
V_530 = V_7 -> V_18 . V_278 ;
V_531 = V_7 -> V_18 . V_280 ;
V_532 = V_7 -> V_18 . V_282 ;
V_533 = V_7 -> V_18 . V_284 ;
V_534 = V_7 -> V_18 . V_286 ;
if ( V_510 & V_525 )
V_7 -> V_18 . V_278 = V_278 ;
if ( V_510 & V_526 )
V_7 -> V_18 . V_280 = V_280 ;
if ( V_510 & V_527 )
V_7 -> V_18 . V_282 = V_282 ;
if ( V_510 & V_528 )
V_7 -> V_18 . V_284 = V_284 ;
if ( V_510 & V_529 )
V_7 -> V_18 . V_286 = V_286 ;
V_8 = F_98 ( V_7 , V_510 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_278 = V_530 ;
V_7 -> V_18 . V_280 = V_531 ;
V_7 -> V_18 . V_282 = V_532 ;
V_7 -> V_18 . V_284 = V_533 ;
V_7 -> V_18 . V_286 = V_534 ;
}
}
return 0 ;
}
static inline T_1 V_13 ( struct V_1 * V_17 )
{
return ( T_1 ) V_17 -> V_21 |
( ( T_1 ) F_11 ( V_17 -> V_18 ) -> V_14 << 32 ) ;
}
static int F_99 ( struct V_31 * V_53 ,
const struct V_481 * V_482 )
{
F_57 ( ! F_81 ( V_482 ) ) ;
if ( F_28 ( V_53 , V_484 ,
V_482 -> V_55 -> V_58 ) )
return - V_81 ;
switch ( V_482 -> V_485 ) {
case V_486 :
case V_536 :
case V_537 :
if ( F_28 ( V_53 , V_489 ,
F_100 ( V_482 ) ) )
return - V_81 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_496 , V_482 -> V_485 ) )
return - V_81 ;
if ( F_28 ( V_53 , V_497 , V_482 -> V_487 ) )
return - V_81 ;
if ( V_482 -> V_488 &&
F_28 ( V_53 , V_498 , V_482 -> V_488 ) )
return - V_81 ;
return 0 ;
}
static int F_101 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_25 * V_183 = V_17 -> V_19 ;
void * V_263 ;
V_263 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_538 ) ;
if ( ! V_263 )
return - 1 ;
if ( V_183 &&
( F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_58 ( V_53 , V_539 , V_183 -> V_540 ) ) )
goto V_59;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_541 , V_17 -> V_131 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_49 ( V_53 , V_506 , V_542 , F_103 ( V_17 ) ) ||
F_28 ( V_53 , V_274 ,
V_7 -> V_543 ^
( V_275 << 2 ) ) )
goto V_59;
if ( V_7 -> V_324 -> V_544 ) {
int V_457 ;
struct V_481 V_482 ;
V_457 = F_104 ( V_7 , V_17 , & V_482 ) ;
if ( V_457 == 0 ) {
if ( F_99 ( V_53 , & V_482 ) )
goto V_59;
}
}
if ( V_17 -> V_545 ) {
if ( F_49 ( V_53 , V_546 , V_17 -> V_545 , V_17 -> V_547 ) )
goto V_59;
}
return F_64 ( V_53 , V_263 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
static int F_105 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_548 = 0 ;
int V_549 = 0 ;
int V_550 = V_34 -> args [ 0 ] ;
int V_551 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_68 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_548 < V_550 ) {
V_548 ++ ;
continue;
}
V_549 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_549 < V_551 ) {
V_549 ++ ;
continue;
}
if ( F_101 ( V_32 , F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_461 , V_462 ,
V_7 , V_17 ) < 0 ) {
goto V_552;
}
V_549 ++ ;
}
V_548 ++ ;
}
V_552:
F_20 () ;
V_34 -> args [ 0 ] = V_548 ;
V_34 -> args [ 1 ] = V_549 ;
return V_32 -> V_47 ;
}
static int F_106 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_183 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
if ( F_101 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_183 , V_17 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_81 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_107 ( struct V_4 * V_554 , V_22 * V_555 )
{
struct V_4 * V_51 [ V_556 + 1 ] ;
int V_557 ;
* V_555 = 0 ;
if ( ! V_554 )
return - V_16 ;
if ( F_33 ( V_51 , V_556 ,
V_554 , V_558 ) )
return - V_16 ;
for ( V_557 = 1 ; V_557 <= V_556 ; V_557 ++ )
if ( V_51 [ V_557 ] )
* V_555 |= ( 1 << V_557 ) ;
return 0 ;
}
static int F_108 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_559 ,
enum V_252 V_131 )
{
if ( ! V_559 ) {
if ( V_19 && ( V_19 -> V_560 & V_561 ) )
return - V_503 ;
return 0 ;
}
switch ( V_131 ) {
case V_133 :
if ( V_7 -> V_18 . V_51 & V_562 )
return 0 ;
break;
case V_137 :
if ( V_7 -> V_18 . V_51 & V_563 )
return 0 ;
break;
default:
break;
}
return - V_501 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_564 V_127 ;
int V_35 ;
enum V_252 V_565 , V_566 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
V_22 V_567 , * V_51 = NULL ;
bool V_568 = false ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_565 = V_566 = V_183 -> V_28 -> V_131 ;
if ( V_30 -> V_5 [ V_541 ] ) {
V_566 = F_4 ( V_30 -> V_5 [ V_541 ] ) ;
if ( V_565 != V_566 )
V_568 = true ;
if ( V_566 > V_569 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_570 ] ) {
struct V_1 * V_17 = V_183 -> V_28 ;
if ( V_566 != V_135 )
return - V_16 ;
if ( F_89 ( V_183 ) )
return - V_503 ;
F_110 ( V_17 ) ;
F_111 ( V_571 !=
V_572 ) ;
V_17 -> V_573 =
F_24 ( V_30 -> V_5 [ V_570 ] ) ;
memcpy ( V_17 -> V_547 , F_23 ( V_30 -> V_5 [ V_570 ] ) ,
V_17 -> V_573 ) ;
F_112 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_574 ] ) {
V_127 . V_559 = ! ! F_34 ( V_30 -> V_5 [ V_574 ] ) ;
V_568 = true ;
V_35 = F_108 ( V_7 , V_183 , V_127 . V_559 , V_566 ) ;
if ( V_35 )
return V_35 ;
} else {
V_127 . V_559 = - 1 ;
}
if ( V_30 -> V_5 [ V_575 ] ) {
if ( V_566 != V_480 )
return - V_16 ;
V_35 = F_107 ( V_30 -> V_5 [ V_575 ] ,
& V_567 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_567 ;
V_568 = true ;
}
if ( V_51 && ( * V_51 & V_576 ) &&
! ( V_7 -> V_18 . V_271 & V_577 ) )
return - V_501 ;
if ( V_568 )
V_35 = F_113 ( V_7 , V_183 , V_566 , V_51 , & V_127 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_127 . V_559 != - 1 )
V_183 -> V_28 -> V_559 = V_127 . V_559 ;
return V_35 ;
}
static int F_114 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_564 V_127 ;
struct V_1 * V_17 ;
struct V_31 * V_53 ;
int V_35 ;
enum V_252 type = V_578 ;
V_22 V_51 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( ! V_30 -> V_5 [ V_539 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_541 ] ) {
type = F_4 ( V_30 -> V_5 [ V_541 ] ) ;
if ( type > V_569 )
return - V_16 ;
}
if ( ! V_7 -> V_324 -> V_342 ||
! ( V_7 -> V_18 . V_332 & ( 1 << type ) ) )
return - V_501 ;
if ( type == V_579 && V_30 -> V_5 [ V_506 ] ) {
F_115 ( V_127 . V_580 , V_30 -> V_5 [ V_506 ] ,
V_542 ) ;
if ( ! F_116 ( V_127 . V_580 ) )
return - V_581 ;
}
if ( V_30 -> V_5 [ V_574 ] ) {
V_127 . V_559 = ! ! F_34 ( V_30 -> V_5 [ V_574 ] ) ;
V_35 = F_108 ( V_7 , NULL , V_127 . V_559 , type ) ;
if ( V_35 )
return V_35 ;
}
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_35 = F_107 ( type == V_480 ?
V_30 -> V_5 [ V_575 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_576 ) &&
! ( V_7 -> V_18 . V_271 & V_577 ) )
return - V_501 ;
V_17 = F_117 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_539 ] ) ,
type , V_35 ? NULL : & V_51 , & V_127 ) ;
if ( F_17 ( V_17 ) ) {
F_73 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
switch ( type ) {
case V_135 :
if ( ! V_30 -> V_5 [ V_570 ] )
break;
F_110 ( V_17 ) ;
F_111 ( V_571 !=
V_572 ) ;
V_17 -> V_573 =
F_24 ( V_30 -> V_5 [ V_570 ] ) ;
memcpy ( V_17 -> V_547 , F_23 ( V_30 -> V_5 [ V_570 ] ) ,
V_17 -> V_573 ) ;
F_112 ( V_17 ) ;
break;
case V_579 :
F_118 ( & V_17 -> V_582 ) ;
F_119 ( & V_17 -> V_583 ) ;
F_120 ( & V_17 -> V_584 ) ;
F_119 ( & V_17 -> V_585 ) ;
F_120 ( & V_17 -> V_586 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_121 ( & V_17 -> V_587 , & V_7 -> V_588 ) ;
V_7 -> V_543 ++ ;
break;
default:
break;
}
if ( F_101 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_7 , V_17 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_81 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_122 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
if ( ! V_7 -> V_324 -> V_589 )
return - V_501 ;
if ( ! V_17 -> V_19 )
V_30 -> V_464 [ 1 ] = NULL ;
return F_123 ( V_7 , V_17 ) ;
}
static int F_124 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_3 V_590 ;
if ( ! V_30 -> V_5 [ V_591 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_400 )
return - V_501 ;
V_590 = F_76 ( V_30 -> V_5 [ V_591 ] ) ;
return F_125 ( V_7 , V_183 , V_590 ) ;
}
static void F_126 ( void * V_149 , struct V_592 * V_127 )
{
struct V_4 * V_82 ;
struct V_593 * V_594 = V_149 ;
if ( ( V_127 -> V_82 &&
F_49 ( V_594 -> V_53 , V_111 ,
V_127 -> V_98 , V_127 -> V_82 ) ) ||
( V_127 -> V_50 &&
F_49 ( V_594 -> V_53 , V_112 ,
V_127 -> V_100 , V_127 -> V_50 ) ) ||
( V_127 -> V_102 &&
F_28 ( V_594 -> V_53 , V_114 ,
V_127 -> V_102 ) ) )
goto V_59;
V_82 = F_45 ( V_594 -> V_53 , V_119 ) ;
if ( ! V_82 )
goto V_59;
if ( ( V_127 -> V_82 &&
F_49 ( V_594 -> V_53 , V_96 ,
V_127 -> V_98 , V_127 -> V_82 ) ) ||
( V_127 -> V_50 &&
F_49 ( V_594 -> V_53 , V_99 ,
V_127 -> V_100 , V_127 -> V_50 ) ) ||
( V_127 -> V_102 &&
F_28 ( V_594 -> V_53 , V_101 ,
V_127 -> V_102 ) ) )
goto V_59;
if ( F_54 ( V_594 -> V_53 , V_113 , V_594 -> V_95 ) )
goto V_59;
F_46 ( V_594 -> V_53 , V_82 ) ;
return;
V_59:
V_594 -> error = 1 ;
}
static int F_127 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
int V_35 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 V_595 = 0 ;
const T_2 * V_596 = NULL ;
bool V_597 ;
struct V_593 V_594 = {
. error = 0 ,
} ;
void * V_263 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_113 ] )
V_595 = F_34 ( V_30 -> V_5 [ V_113 ] ) ;
if ( V_595 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_506 ] )
V_596 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_597 = ! ! V_596 ;
if ( V_30 -> V_5 [ V_117 ] ) {
V_22 V_598 = F_4 ( V_30 -> V_5 [ V_117 ] ) ;
if ( V_598 >= V_104 )
return - V_16 ;
if ( V_598 != V_599 &&
V_598 != V_600 )
return - V_16 ;
V_597 = V_598 == V_600 ;
}
if ( ! V_7 -> V_324 -> V_601 )
return - V_501 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_602 ) ;
if ( ! V_263 )
goto V_59;
V_594 . V_53 = V_53 ;
V_594 . V_95 = V_595 ;
if ( F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_54 ( V_53 , V_113 , V_595 ) )
goto V_59;
if ( V_596 &&
F_49 ( V_53 , V_506 , V_542 , V_596 ) )
goto V_59;
if ( V_597 && V_596 &&
! ( V_7 -> V_18 . V_51 & V_297 ) )
return - V_603 ;
V_35 = F_128 ( V_7 , V_183 , V_595 , V_597 , V_596 , & V_594 ,
F_126 ) ;
if ( V_35 )
goto V_604;
if ( V_594 . error )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_81 ;
V_604:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_129 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_83 V_82 ;
int V_35 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_82 ) ;
if ( V_35 )
return V_35 ;
if ( V_82 . V_95 < 0 )
return - V_16 ;
if ( ! V_82 . V_88 && ! V_82 . V_90 )
return - V_16 ;
F_110 ( V_183 -> V_28 ) ;
if ( V_82 . V_88 ) {
if ( ! V_7 -> V_324 -> V_605 ) {
V_35 = - V_501 ;
goto V_552;
}
V_35 = F_42 ( V_183 -> V_28 ) ;
if ( V_35 )
goto V_552;
V_35 = F_130 ( V_7 , V_183 , V_82 . V_95 ,
V_82 . V_92 , V_82 . V_93 ) ;
if ( V_35 )
goto V_552;
#ifdef F_131
V_183 -> V_28 -> V_606 . V_607 = V_82 . V_95 ;
#endif
} else {
if ( V_82 . V_92 || ! V_82 . V_93 ) {
V_35 = - V_16 ;
goto V_552;
}
if ( ! V_7 -> V_324 -> V_608 ) {
V_35 = - V_501 ;
goto V_552;
}
V_35 = F_42 ( V_183 -> V_28 ) ;
if ( V_35 )
goto V_552;
V_35 = F_132 ( V_7 , V_183 , V_82 . V_95 ) ;
if ( V_35 )
goto V_552;
#ifdef F_131
V_183 -> V_28 -> V_606 . V_609 = V_82 . V_95 ;
#endif
}
V_552:
F_112 ( V_183 -> V_28 ) ;
return V_35 ;
}
static int F_133 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
int V_35 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_83 V_82 ;
const T_2 * V_596 = NULL ;
V_35 = F_36 ( V_30 , & V_82 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_82 . V_97 . V_82 )
return - V_16 ;
if ( V_30 -> V_5 [ V_506 ] )
V_596 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( V_82 . type == - 1 ) {
if ( V_596 )
V_82 . type = V_600 ;
else
V_82 . type = V_599 ;
}
if ( V_82 . type != V_600 &&
V_82 . type != V_599 )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_346 )
return - V_501 ;
if ( F_40 ( V_7 , & V_82 . V_97 , V_82 . V_95 ,
V_82 . type == V_600 ,
V_596 ) )
return - V_16 ;
F_110 ( V_183 -> V_28 ) ;
V_35 = F_42 ( V_183 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_134 ( V_7 , V_183 , V_82 . V_95 ,
V_82 . type == V_600 ,
V_596 , & V_82 . V_97 ) ;
F_112 ( V_183 -> V_28 ) ;
return V_35 ;
}
static int F_135 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
int V_35 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 * V_596 = NULL ;
struct V_83 V_82 ;
V_35 = F_36 ( V_30 , & V_82 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_506 ] )
V_596 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( V_82 . type == - 1 ) {
if ( V_596 )
V_82 . type = V_600 ;
else
V_82 . type = V_599 ;
}
if ( V_82 . type != V_600 &&
V_82 . type != V_599 )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_610 )
return - V_501 ;
F_110 ( V_183 -> V_28 ) ;
V_35 = F_42 ( V_183 -> V_28 ) ;
if ( V_82 . type == V_600 && V_596 &&
! ( V_7 -> V_18 . V_51 & V_297 ) )
V_35 = - V_603 ;
if ( ! V_35 )
V_35 = F_136 ( V_7 , V_183 , V_82 . V_95 ,
V_82 . type == V_600 ,
V_596 ) ;
#ifdef F_131
if ( ! V_35 ) {
if ( V_82 . V_95 == V_183 -> V_28 -> V_606 . V_607 )
V_183 -> V_28 -> V_606 . V_607 = - 1 ;
else if ( V_82 . V_95 == V_183 -> V_28 -> V_606 . V_609 )
V_183 -> V_28 -> V_606 . V_609 = - 1 ;
}
#endif
F_112 ( V_183 -> V_28 ) ;
return V_35 ;
}
static int F_137 ( struct V_4 * V_611 )
{
struct V_4 * V_45 ;
int V_612 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_542 )
return - V_16 ;
V_612 ++ ;
}
return V_612 ;
}
static struct V_613 * F_138 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_614 V_615 ;
struct V_4 * V_45 ;
struct V_613 * V_616 ;
int V_143 = 0 , V_612 , V_24 ;
if ( ! V_18 -> V_436 )
return F_3 ( - V_501 ) ;
if ( ! V_30 -> V_5 [ V_617 ] )
return F_3 ( - V_16 ) ;
V_615 = F_4 ( V_30 -> V_5 [ V_617 ] ) ;
if ( V_615 != V_618 &&
V_615 != V_619 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_620 ] )
return F_3 ( - V_16 ) ;
V_612 = F_137 ( V_30 -> V_5 [ V_620 ] ) ;
if ( V_612 < 0 )
return F_3 ( V_612 ) ;
if ( V_612 > V_18 -> V_436 )
return F_3 ( - V_621 ) ;
V_616 = F_38 ( sizeof( * V_616 ) + ( sizeof( struct V_622 ) * V_612 ) ,
V_125 ) ;
if ( ! V_616 )
return F_3 ( - V_126 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_616 -> V_623 [ V_143 ] . V_624 , F_23 ( V_45 ) , V_542 ) ;
V_143 ++ ;
}
V_616 -> V_625 = V_612 ;
V_616 -> V_615 = V_615 ;
return V_616 ;
}
static int F_139 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_613 * V_616 ;
int V_35 ;
if ( V_183 -> V_28 -> V_131 != V_132 &&
V_183 -> V_28 -> V_131 != V_134 )
return - V_501 ;
if ( ! V_183 -> V_28 -> V_502 )
return - V_16 ;
V_616 = F_138 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_616 ) )
return F_18 ( V_616 ) ;
V_35 = F_140 ( V_7 , V_183 , V_616 ) ;
F_41 ( V_616 ) ;
return V_35 ;
}
static int F_141 ( struct V_4 * V_5 [] ,
struct V_626 * V_627 )
{
bool V_628 = false ;
if ( ! F_22 ( V_5 [ V_629 ] ) ||
! F_22 ( V_5 [ V_630 ] ) ||
! F_22 ( V_5 [ V_631 ] ) ||
! F_22 ( V_5 [ V_632 ] ) )
return - V_16 ;
memset ( V_627 , 0 , sizeof( * V_627 ) ) ;
if ( V_5 [ V_633 ] ) {
V_627 -> V_634 = F_23 ( V_5 [ V_633 ] ) ;
V_627 -> V_635 = F_24 ( V_5 [ V_633 ] ) ;
if ( ! V_627 -> V_635 )
return - V_16 ;
V_628 = true ;
}
if ( V_5 [ V_629 ] ) {
V_627 -> V_636 = F_23 ( V_5 [ V_629 ] ) ;
V_627 -> V_637 = F_24 ( V_5 [ V_629 ] ) ;
V_628 = true ;
}
if ( ! V_628 )
return - V_16 ;
if ( V_5 [ V_630 ] ) {
V_627 -> V_638 = F_23 ( V_5 [ V_630 ] ) ;
V_627 -> V_639 = F_24 ( V_5 [ V_630 ] ) ;
}
if ( V_5 [ V_631 ] ) {
V_627 -> V_640 =
F_23 ( V_5 [ V_631 ] ) ;
V_627 -> V_641 =
F_24 ( V_5 [ V_631 ] ) ;
}
if ( V_5 [ V_632 ] ) {
V_627 -> V_642 =
F_23 ( V_5 [ V_632 ] ) ;
V_627 -> V_643 =
F_24 ( V_5 [ V_632 ] ) ;
}
if ( V_5 [ V_644 ] ) {
V_627 -> V_645 = F_23 ( V_5 [ V_644 ] ) ;
V_627 -> V_646 = F_24 ( V_5 [ V_644 ] ) ;
}
return 0 ;
}
static bool F_142 ( struct V_6 * V_7 ,
struct V_647 * V_127 )
{
struct V_1 * V_17 ;
bool V_457 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_131 != V_132 &&
V_17 -> V_131 != V_134 )
continue;
if ( ! V_17 -> V_504 . V_55 )
continue;
V_127 -> V_482 = V_17 -> V_504 ;
V_457 = true ;
break;
}
return V_457 ;
}
static bool F_143 ( struct V_6 * V_7 ,
enum V_648 V_649 ,
enum V_650 V_52 )
{
if ( V_649 > V_651 )
return false ;
switch ( V_52 ) {
case V_652 :
if ( ! ( V_7 -> V_18 . V_271 & V_653 ) &&
V_649 == V_654 )
return false ;
return true ;
case V_420 :
case V_655 :
if ( V_649 == V_654 )
return false ;
return true ;
default:
return false ;
}
}
static int F_144 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_647 V_127 ;
int V_35 ;
T_2 V_656 = 0 ;
if ( V_183 -> V_28 -> V_131 != V_132 &&
V_183 -> V_28 -> V_131 != V_134 )
return - V_501 ;
if ( ! V_7 -> V_324 -> V_348 )
return - V_501 ;
if ( V_17 -> V_502 )
return - V_657 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( ! V_30 -> V_5 [ V_658 ] ||
! V_30 -> V_5 [ V_659 ] ||
! V_30 -> V_5 [ V_633 ] )
return - V_16 ;
V_35 = F_141 ( V_30 -> V_5 , & V_127 . V_660 ) ;
if ( V_35 )
return V_35 ;
V_127 . V_502 =
F_4 ( V_30 -> V_5 [ V_658 ] ) ;
V_127 . V_661 =
F_4 ( V_30 -> V_5 [ V_659 ] ) ;
V_35 = F_145 ( V_7 , V_127 . V_502 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_546 ] ) {
V_127 . V_547 = F_23 ( V_30 -> V_5 [ V_546 ] ) ;
V_127 . V_545 =
F_24 ( V_30 -> V_5 [ V_546 ] ) ;
if ( V_127 . V_545 == 0 ||
V_127 . V_545 > V_571 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_662 ] ) {
V_127 . V_663 = F_4 (
V_30 -> V_5 [ V_662 ] ) ;
if ( V_127 . V_663 != V_664 &&
V_127 . V_663 != V_665 &&
V_127 . V_663 != V_666 )
return - V_16 ;
}
V_127 . V_667 = ! ! V_30 -> V_5 [ V_668 ] ;
if ( V_30 -> V_5 [ V_669 ] ) {
V_127 . V_649 = F_4 (
V_30 -> V_5 [ V_669 ] ) ;
if ( ! F_143 ( V_7 , V_127 . V_649 ,
V_655 ) )
return - V_16 ;
} else
V_127 . V_649 = V_670 ;
V_35 = F_146 ( V_7 , V_30 , & V_127 . V_671 ,
V_672 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_673 ] ) {
if ( ! ( V_7 -> V_18 . V_271 & V_674 ) )
return - V_501 ;
V_127 . V_675 = F_76 (
V_30 -> V_5 [ V_673 ] ) ;
}
if ( V_30 -> V_5 [ V_676 ] ) {
if ( V_183 -> V_28 -> V_131 != V_134 )
return - V_16 ;
V_127 . V_677 =
F_34 ( V_30 -> V_5 [ V_676 ] ) ;
if ( V_127 . V_677 > 127 )
return - V_16 ;
if ( V_127 . V_677 != 0 &&
! ( V_7 -> V_18 . V_271 & V_678 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_679 ] ) {
T_2 V_24 ;
if ( V_183 -> V_28 -> V_131 != V_134 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_679 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_127 . V_680 = V_24 ;
if ( V_127 . V_680 != 0 &&
! ( V_7 -> V_18 . V_271 & V_681 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_484 ] ) {
V_35 = F_78 ( V_7 , V_30 , & V_127 . V_482 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_504 . V_55 ) {
V_127 . V_482 = V_17 -> V_504 ;
} else if ( ! F_142 ( V_7 , & V_127 ) )
return - V_16 ;
if ( ! F_84 ( & V_7 -> V_18 , & V_127 . V_482 ) )
return - V_16 ;
V_35 = F_147 ( V_17 -> V_18 , & V_127 . V_482 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 ) {
V_656 = F_148 ( V_127 . V_482 . V_485 ) ;
V_127 . V_682 = true ;
}
V_35 = F_149 ( V_7 , V_17 , V_17 -> V_131 ,
V_127 . V_482 . V_55 ,
V_683 ,
V_656 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_617 ] ) {
V_127 . V_616 = F_138 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_127 . V_616 ) )
return F_18 ( V_127 . V_616 ) ;
}
F_110 ( V_17 ) ;
V_35 = F_150 ( V_7 , V_183 , & V_127 ) ;
if ( ! V_35 ) {
V_17 -> V_504 = V_127 . V_482 ;
V_17 -> V_502 = V_127 . V_502 ;
V_17 -> V_684 = V_127 . V_482 . V_55 ;
V_17 -> V_545 = V_127 . V_545 ;
memcpy ( V_17 -> V_547 , V_127 . V_547 , V_17 -> V_545 ) ;
}
F_112 ( V_17 ) ;
F_41 ( V_127 . V_616 ) ;
return V_35 ;
}
static int F_151 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_626 V_127 ;
int V_35 ;
if ( V_183 -> V_28 -> V_131 != V_132 &&
V_183 -> V_28 -> V_131 != V_134 )
return - V_501 ;
if ( ! V_7 -> V_324 -> V_685 )
return - V_501 ;
if ( ! V_17 -> V_502 )
return - V_16 ;
V_35 = F_141 ( V_30 -> V_5 , & V_127 ) ;
if ( V_35 )
return V_35 ;
F_110 ( V_17 ) ;
V_35 = F_152 ( V_7 , V_183 , & V_127 ) ;
F_112 ( V_17 ) ;
return V_35 ;
}
static int F_153 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
return F_154 ( V_7 , V_183 ) ;
}
static int F_155 ( struct V_29 * V_30 ,
enum V_252 V_131 ,
struct V_686 * V_127 )
{
struct V_4 * V_51 [ V_687 + 1 ] ;
struct V_4 * V_554 ;
int V_557 ;
V_554 = V_30 -> V_5 [ V_688 ] ;
if ( V_554 ) {
struct V_689 * V_690 ;
V_690 = F_23 ( V_554 ) ;
V_127 -> V_691 = V_690 -> V_692 ;
V_127 -> V_693 = V_690 -> V_694 ;
V_127 -> V_693 &= V_127 -> V_691 ;
if ( ( V_127 -> V_691 |
V_127 -> V_693 ) & F_148 ( V_695 ) )
return - V_16 ;
return 0 ;
}
V_554 = V_30 -> V_5 [ V_696 ] ;
if ( ! V_554 )
return 0 ;
if ( F_33 ( V_51 , V_687 ,
V_554 , V_697 ) )
return - V_16 ;
switch ( V_131 ) {
case V_132 :
case V_133 :
case V_134 :
V_127 -> V_691 = F_148 ( V_698 ) |
F_148 ( V_699 ) |
F_148 ( V_700 ) |
F_148 ( V_701 ) ;
break;
case V_138 :
case V_137 :
V_127 -> V_691 = F_148 ( V_698 ) |
F_148 ( V_702 ) ;
break;
case V_135 :
V_127 -> V_691 = F_148 ( V_703 ) |
F_148 ( V_701 ) |
F_148 ( V_698 ) ;
default:
return - V_16 ;
}
for ( V_557 = 1 ; V_557 <= V_687 ; V_557 ++ ) {
if ( V_51 [ V_557 ] ) {
V_127 -> V_693 |= ( 1 << V_557 ) ;
if ( V_557 > V_704 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_156 ( struct V_31 * V_53 , struct V_705 * V_30 ,
int V_45 )
{
struct V_4 * V_224 ;
V_22 V_244 ;
T_3 V_706 ;
V_224 = F_45 ( V_53 , V_45 ) ;
if ( ! V_224 )
return false ;
V_244 = F_157 ( V_30 ) ;
V_706 = V_244 < ( 1UL << 16 ) ? V_244 : 0 ;
if ( V_244 > 0 &&
F_28 ( V_53 , V_707 , V_244 ) )
return false ;
if ( V_706 > 0 &&
F_53 ( V_53 , V_708 , V_706 ) )
return false ;
if ( V_30 -> V_51 & V_709 ) {
if ( F_54 ( V_53 , V_710 , V_30 -> V_228 ) )
return false ;
if ( V_30 -> V_51 & V_711 &&
F_29 ( V_53 , V_712 ) )
return false ;
if ( V_30 -> V_51 & V_713 &&
F_29 ( V_53 , V_714 ) )
return false ;
} else if ( V_30 -> V_51 & V_715 ) {
if ( F_54 ( V_53 , V_716 , V_30 -> V_228 ) )
return false ;
if ( F_54 ( V_53 , V_717 , V_30 -> V_718 ) )
return false ;
if ( V_30 -> V_51 & V_711 &&
F_29 ( V_53 , V_712 ) )
return false ;
if ( V_30 -> V_51 & V_719 &&
F_29 ( V_53 , V_720 ) )
return false ;
if ( V_30 -> V_51 & V_721 &&
F_29 ( V_53 , V_722 ) )
return false ;
if ( V_30 -> V_51 & V_723 &&
F_29 ( V_53 , V_724 ) )
return false ;
if ( V_30 -> V_51 & V_713 &&
F_29 ( V_53 , V_714 ) )
return false ;
}
F_46 ( V_53 , V_224 ) ;
return true ;
}
static bool F_158 ( struct V_31 * V_53 , T_2 V_692 , T_6 * signal ,
int V_725 )
{
void * V_45 ;
int V_143 = 0 ;
if ( ! V_692 )
return true ;
V_45 = F_45 ( V_53 , V_725 ) ;
if ( ! V_45 )
return false ;
for ( V_143 = 0 ; V_143 < V_726 ; V_143 ++ ) {
if ( ! ( V_692 & F_148 ( V_143 ) ) )
continue;
if ( F_54 ( V_53 , V_143 , signal [ V_143 ] ) )
return false ;
}
F_46 ( V_53 , V_45 ) ;
return true ;
}
static int F_159 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_183 ,
const T_2 * V_596 , struct V_727 * V_728 )
{
void * V_263 ;
struct V_4 * V_729 , * V_730 ;
V_263 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_731 ) ;
if ( ! V_263 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_596 ) ||
F_28 ( V_53 , V_274 , V_728 -> V_732 ) )
goto V_59;
V_729 = F_45 ( V_53 , V_733 ) ;
if ( ! V_729 )
goto V_59;
if ( ( V_728 -> V_734 & V_735 ) &&
F_28 ( V_53 , V_736 ,
V_728 -> V_737 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_738 ) &&
F_28 ( V_53 , V_739 ,
V_728 -> V_740 ) )
goto V_59;
if ( ( V_728 -> V_734 & ( V_741 |
V_742 ) ) &&
F_28 ( V_53 , V_743 ,
( V_22 ) V_728 -> V_744 ) )
goto V_59;
if ( ( V_728 -> V_734 & ( V_745 |
V_746 ) ) &&
F_28 ( V_53 , V_747 ,
( V_22 ) V_728 -> V_748 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_742 ) &&
F_102 ( V_53 , V_749 ,
V_728 -> V_744 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_746 ) &&
F_102 ( V_53 , V_750 ,
V_728 -> V_748 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_751 ) &&
F_53 ( V_53 , V_752 , V_728 -> V_753 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_754 ) &&
F_53 ( V_53 , V_755 , V_728 -> V_756 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_757 ) &&
F_54 ( V_53 , V_758 ,
V_728 -> V_759 ) )
goto V_59;
switch ( V_7 -> V_18 . V_760 ) {
case V_761 :
if ( ( V_728 -> V_734 & V_762 ) &&
F_54 ( V_53 , V_763 ,
V_728 -> signal ) )
goto V_59;
if ( ( V_728 -> V_734 & V_764 ) &&
F_54 ( V_53 , V_765 ,
V_728 -> V_766 ) )
goto V_59;
break;
default:
break;
}
if ( V_728 -> V_734 & V_767 ) {
if ( ! F_158 ( V_53 , V_728 -> V_768 ,
V_728 -> V_769 ,
V_770 ) )
goto V_59;
}
if ( V_728 -> V_734 & V_771 ) {
if ( ! F_158 ( V_53 , V_728 -> V_768 ,
V_728 -> V_772 ,
V_773 ) )
goto V_59;
}
if ( V_728 -> V_734 & V_774 ) {
if ( ! F_156 ( V_53 , & V_728 -> V_775 ,
V_776 ) )
goto V_59;
}
if ( V_728 -> V_734 & V_777 ) {
if ( ! F_156 ( V_53 , & V_728 -> V_778 ,
V_779 ) )
goto V_59;
}
if ( ( V_728 -> V_734 & V_780 ) &&
F_28 ( V_53 , V_781 ,
V_728 -> V_782 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_783 ) &&
F_28 ( V_53 , V_784 ,
V_728 -> V_785 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_786 ) &&
F_28 ( V_53 , V_787 ,
V_728 -> V_788 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_789 ) &&
F_28 ( V_53 , V_790 ,
V_728 -> V_791 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_792 ) &&
F_28 ( V_53 , V_793 ,
V_728 -> V_794 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_795 ) &&
F_28 ( V_53 , V_796 ,
V_728 -> V_797 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_798 ) &&
F_28 ( V_53 , V_799 ,
V_728 -> V_800 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_801 ) &&
F_28 ( V_53 , V_802 ,
V_728 -> V_803 ) )
goto V_59;
if ( V_728 -> V_734 & V_804 ) {
V_730 = F_45 ( V_53 , V_805 ) ;
if ( ! V_730 )
goto V_59;
if ( ( ( V_728 -> V_730 . V_51 & V_806 ) &&
F_29 ( V_53 , V_807 ) ) ||
( ( V_728 -> V_730 . V_51 & V_808 ) &&
F_29 ( V_53 , V_809 ) ) ||
( ( V_728 -> V_730 . V_51 & V_810 ) &&
F_29 ( V_53 , V_811 ) ) ||
F_54 ( V_53 , V_812 ,
V_728 -> V_730 . V_661 ) ||
F_53 ( V_53 , V_813 ,
V_728 -> V_730 . V_502 ) )
goto V_59;
F_46 ( V_53 , V_730 ) ;
}
if ( ( V_728 -> V_734 & V_814 ) &&
F_49 ( V_53 , V_815 ,
sizeof( struct V_689 ) ,
& V_728 -> V_690 ) )
goto V_59;
if ( ( V_728 -> V_734 & V_816 ) &&
F_102 ( V_53 , V_817 ,
V_728 -> V_818 ) )
goto V_59;
F_46 ( V_53 , V_729 ) ;
if ( ( V_728 -> V_734 & V_819 ) &&
F_49 ( V_53 , V_630 , V_728 -> V_820 ,
V_728 -> V_821 ) )
goto V_59;
return F_64 ( V_53 , V_263 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
static int F_160 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_727 V_728 ;
struct V_6 * V_183 ;
struct V_1 * V_17 ;
T_2 V_596 [ V_542 ] ;
int V_822 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_183 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_823;
}
if ( ! V_183 -> V_324 -> V_824 ) {
V_35 = - V_501 ;
goto V_823;
}
while ( 1 ) {
memset ( & V_728 , 0 , sizeof( V_728 ) ) ;
V_35 = F_161 ( V_183 , V_17 -> V_19 , V_822 ,
V_596 , & V_728 ) ;
if ( V_35 == - V_603 )
break;
if ( V_35 )
goto V_823;
if ( F_159 ( V_32 ,
F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_461 , V_462 ,
V_183 , V_17 -> V_19 , V_596 ,
& V_728 ) < 0 )
goto V_552;
V_822 ++ ;
}
V_552:
V_34 -> args [ 2 ] = V_822 ;
V_35 = V_32 -> V_47 ;
V_823:
F_21 ( V_183 ) ;
return V_35 ;
}
static int F_162 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_727 V_728 ;
struct V_31 * V_53 ;
T_2 * V_596 = NULL ;
int V_35 ;
memset ( & V_728 , 0 , sizeof( V_728 ) ) ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
V_596 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( ! V_7 -> V_324 -> V_825 )
return - V_501 ;
V_35 = F_163 ( V_7 , V_183 , V_596 , & V_728 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
if ( F_159 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_7 , V_183 , V_596 , & V_728 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_81 ;
}
return F_74 ( V_53 , V_30 ) ;
}
int F_164 ( struct V_18 * V_18 ,
struct V_686 * V_127 ,
enum V_826 V_827 )
{
if ( V_127 -> V_828 != - 1 )
return - V_16 ;
if ( V_127 -> V_829 )
return - V_16 ;
F_111 ( V_687 != 7 ) ;
switch ( V_827 ) {
case V_830 :
case V_831 :
if ( V_127 -> V_691 &
~ ( F_148 ( V_703 ) |
F_148 ( V_701 ) |
F_148 ( V_698 ) ) )
return - V_16 ;
break;
case V_832 :
case V_833 :
if ( ! ( V_127 -> V_693 & F_148 ( V_702 ) ) )
return - V_16 ;
V_127 -> V_691 &= ~ F_148 ( V_702 ) ;
break;
default:
if ( V_127 -> V_834 != V_835 )
return - V_16 ;
if ( V_127 -> V_797 )
return - V_16 ;
if ( V_127 -> V_836 & V_837 )
return - V_16 ;
}
if ( V_827 != V_832 &&
V_827 != V_833 ) {
if ( V_127 -> V_693 & F_148 ( V_702 ) )
return - V_16 ;
V_127 -> V_691 &= ~ F_148 ( V_702 ) ;
}
if ( V_827 != V_832 ) {
if ( V_127 -> V_836 & V_838 )
return - V_16 ;
if ( V_127 -> V_836 & V_839 )
return - V_16 ;
if ( V_127 -> V_840 )
return - V_16 ;
if ( V_127 -> V_841 || V_127 -> V_842 || V_127 -> V_843 )
return - V_16 ;
}
if ( V_827 != V_844 ) {
if ( V_127 -> V_845 )
return - V_16 ;
}
switch ( V_827 ) {
case V_846 :
if ( ! ( V_127 -> V_691 & F_148 ( V_698 ) ) )
return - V_501 ;
break;
case V_844 :
if ( V_127 -> V_691 &
~ ( F_148 ( V_698 ) |
F_148 ( V_703 ) |
F_148 ( V_847 ) |
F_148 ( V_699 ) |
F_148 ( V_700 ) |
F_148 ( V_701 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_271 & V_848 ) &&
V_127 -> V_691 &
( F_148 ( V_703 ) |
F_148 ( V_847 ) ) )
return - V_16 ;
break;
case V_849 :
case V_850 :
if ( V_127 -> V_691 & ~ F_148 ( V_698 ) )
return - V_16 ;
break;
case V_832 :
if ( V_127 -> V_691 & ~ ( F_148 ( V_698 ) |
F_148 ( V_700 ) ) )
return - V_16 ;
if ( V_127 -> V_693 & F_148 ( V_698 ) &&
! V_127 -> V_840 )
return - V_16 ;
break;
case V_833 :
return - V_16 ;
case V_830 :
if ( V_127 -> V_836 & V_837 )
return - V_16 ;
break;
case V_831 :
if ( V_127 -> V_834 != V_835 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_165 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_851 = V_30 -> V_5 [ V_852 ] ;
struct V_25 * V_853 ;
int V_457 ;
if ( ! V_851 )
return NULL ;
V_853 = F_166 ( F_92 ( V_30 ) , F_4 ( V_851 ) ) ;
if ( ! V_853 )
return F_3 ( - V_23 ) ;
if ( ! V_853 -> V_28 || V_853 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_457 = - V_16 ;
goto error;
}
if ( V_853 -> V_28 -> V_131 != V_133 &&
V_853 -> V_28 -> V_131 != V_132 &&
V_853 -> V_28 -> V_131 != V_134 ) {
V_457 = - V_16 ;
goto error;
}
if ( ! F_89 ( V_853 ) ) {
V_457 = - V_514 ;
goto error;
}
return V_853 ;
error:
F_167 ( V_853 ) ;
return F_3 ( V_457 ) ;
}
static int F_168 ( struct V_29 * V_30 ,
struct V_686 * V_127 )
{
struct V_4 * V_85 [ V_854 + 1 ] ;
struct V_4 * V_554 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_855 ] )
return 0 ;
V_554 = V_30 -> V_5 [ V_855 ] ;
V_35 = F_33 ( V_85 , V_854 , V_554 ,
V_856 ) ;
if ( V_35 )
return V_35 ;
if ( V_85 [ V_857 ] )
V_127 -> V_858 = F_34 (
V_85 [ V_857 ] ) ;
if ( V_127 -> V_858 & ~ V_859 )
return - V_16 ;
if ( V_85 [ V_860 ] )
V_127 -> V_861 = F_34 ( V_85 [ V_860 ] ) ;
if ( V_127 -> V_861 & ~ V_862 )
return - V_16 ;
V_127 -> V_836 |= V_838 ;
return 0 ;
}
static int F_169 ( struct V_29 * V_30 ,
struct V_686 * V_127 )
{
if ( V_30 -> V_5 [ V_863 ] ) {
V_127 -> V_864 =
F_23 ( V_30 -> V_5 [ V_863 ] ) ;
V_127 -> V_865 =
F_24 ( V_30 -> V_5 [ V_863 ] ) ;
if ( V_127 -> V_865 < 2 )
return - V_16 ;
if ( V_127 -> V_865 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_866 ] ) {
V_127 -> V_867 =
F_23 ( V_30 -> V_5 [ V_866 ] ) ;
V_127 -> V_868 =
F_24 ( V_30 -> V_5 [ V_866 ] ) ;
if ( V_127 -> V_868 < 2 ||
V_127 -> V_868 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_170 ( struct V_29 * V_30 ,
struct V_686 * V_127 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_869 ] )
V_127 -> V_829 = F_76 ( V_30 -> V_5 [ V_869 ] ) ;
if ( V_30 -> V_5 [ V_870 ] )
V_127 -> V_842 =
F_23 ( V_30 -> V_5 [ V_870 ] ) ;
if ( V_30 -> V_5 [ V_871 ] )
V_127 -> V_843 =
F_23 ( V_30 -> V_5 [ V_871 ] ) ;
V_35 = F_169 ( V_30 , V_127 ) ;
if ( V_35 )
return V_35 ;
return F_168 ( V_30 , V_127 ) ;
}
static int F_171 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_686 V_127 ;
T_2 * V_596 ;
int V_35 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_828 = - 1 ;
if ( ! V_7 -> V_324 -> V_872 )
return - V_501 ;
if ( V_30 -> V_5 [ V_873 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
V_596 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( V_30 -> V_5 [ V_874 ] ) {
V_127 . V_840 =
F_23 ( V_30 -> V_5 [ V_874 ] ) ;
V_127 . V_875 =
F_24 ( V_30 -> V_5 [ V_874 ] ) ;
}
if ( V_30 -> V_5 [ V_876 ] ) {
V_127 . V_877 =
F_76 ( V_30 -> V_5 [ V_876 ] ) ;
V_127 . V_836 |= V_839 ;
}
if ( V_30 -> V_5 [ V_878 ] ) {
V_127 . V_841 =
F_23 ( V_30 -> V_5 [ V_878 ] ) ;
V_127 . V_879 =
F_24 ( V_30 -> V_5 [ V_878 ] ) ;
}
if ( V_30 -> V_5 [ V_880 ] )
return - V_16 ;
if ( F_155 ( V_30 , V_183 -> V_28 -> V_131 , & V_127 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_881 ] ) {
V_127 . V_834 =
F_34 ( V_30 -> V_5 [ V_881 ] ) ;
if ( V_127 . V_834 >= V_882 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_883 ] ) {
V_127 . V_759 =
F_34 ( V_30 -> V_5 [ V_883 ] ) ;
if ( V_127 . V_759 >= V_884 )
return - V_16 ;
V_127 . V_836 |= V_837 ;
}
if ( V_30 -> V_5 [ V_885 ] ) {
enum V_886 V_887 = F_4 (
V_30 -> V_5 [ V_885 ] ) ;
if ( V_887 <= V_888 ||
V_887 > V_889 )
return - V_16 ;
V_127 . V_797 = V_887 ;
}
V_35 = F_170 ( V_30 , & V_127 ) ;
if ( V_35 )
return V_35 ;
V_127 . V_845 = F_165 ( V_30 , V_7 ) ;
if ( F_17 ( V_127 . V_845 ) )
return F_18 ( V_127 . V_845 ) ;
switch ( V_183 -> V_28 -> V_131 ) {
case V_132 :
case V_133 :
case V_134 :
case V_138 :
case V_137 :
case V_136 :
case V_135 :
break;
default:
V_35 = - V_501 ;
goto V_890;
}
V_35 = F_172 ( V_7 , V_183 , V_596 , & V_127 ) ;
V_890:
if ( V_127 . V_845 )
F_167 ( V_127 . V_845 ) ;
return V_35 ;
}
static int F_173 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
int V_35 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_686 V_127 ;
T_2 * V_596 = NULL ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( ! V_7 -> V_324 -> V_350 )
return - V_501 ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_880 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_874 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_873 ] &&
! V_30 -> V_5 [ V_869 ] )
return - V_16 ;
V_596 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_127 . V_840 =
F_23 ( V_30 -> V_5 [ V_874 ] ) ;
V_127 . V_875 =
F_24 ( V_30 -> V_5 [ V_874 ] ) ;
V_127 . V_828 =
F_76 ( V_30 -> V_5 [ V_880 ] ) ;
if ( V_30 -> V_5 [ V_869 ] )
V_127 . V_829 = F_76 ( V_30 -> V_5 [ V_869 ] ) ;
else
V_127 . V_829 = F_76 ( V_30 -> V_5 [ V_873 ] ) ;
if ( ! V_127 . V_829 || V_127 . V_829 > V_891 )
return - V_16 ;
if ( V_30 -> V_5 [ V_876 ] ) {
V_127 . V_877 =
F_76 ( V_30 -> V_5 [ V_876 ] ) ;
V_127 . V_836 |= V_839 ;
}
if ( V_30 -> V_5 [ V_878 ] ) {
V_127 . V_841 =
F_23 ( V_30 -> V_5 [ V_878 ] ) ;
V_127 . V_879 =
F_24 ( V_30 -> V_5 [ V_878 ] ) ;
}
if ( V_30 -> V_5 [ V_870 ] )
V_127 . V_842 =
F_23 ( V_30 -> V_5 [ V_870 ] ) ;
if ( V_30 -> V_5 [ V_871 ] )
V_127 . V_843 =
F_23 ( V_30 -> V_5 [ V_871 ] ) ;
if ( V_30 -> V_5 [ V_892 ] ) {
V_127 . V_893 = true ;
V_127 . V_894 =
F_34 ( V_30 -> V_5 [ V_892 ] ) ;
}
if ( V_30 -> V_5 [ V_881 ] ) {
V_127 . V_834 =
F_34 ( V_30 -> V_5 [ V_881 ] ) ;
if ( V_127 . V_834 >= V_882 )
return - V_16 ;
}
V_35 = F_169 ( V_30 , & V_127 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_168 ( V_30 , & V_127 ) ;
if ( V_35 )
return V_35 ;
if ( F_155 ( V_30 , V_183 -> V_28 -> V_131 , & V_127 ) )
return - V_16 ;
F_111 ( V_687 != 7 ) ;
switch ( V_183 -> V_28 -> V_131 ) {
case V_132 :
case V_133 :
case V_134 :
if ( ! ( V_7 -> V_18 . V_51 & V_301 ) ||
! ( V_127 . V_693 & F_148 ( V_700 ) ) )
V_127 . V_836 &= ~ V_838 ;
if ( ( V_127 . V_693 & F_148 ( V_702 ) ) ||
V_30 -> V_5 [ V_869 ] )
return - V_16 ;
V_127 . V_691 &= ~ F_148 ( V_702 ) ;
if ( ! ( V_7 -> V_18 . V_271 &
V_848 ) &&
V_127 . V_691 &
( F_148 ( V_703 ) |
F_148 ( V_847 ) ) )
return - V_16 ;
V_127 . V_845 = F_165 ( V_30 , V_7 ) ;
if ( F_17 ( V_127 . V_845 ) )
return F_18 ( V_127 . V_845 ) ;
break;
case V_135 :
V_127 . V_836 &= ~ V_838 ;
if ( V_127 . V_691 & F_148 ( V_847 ) )
return - V_16 ;
if ( ( V_127 . V_693 & F_148 ( V_702 ) ) ||
V_30 -> V_5 [ V_869 ] )
return - V_16 ;
break;
case V_137 :
case V_138 :
V_127 . V_836 &= ~ V_838 ;
if ( V_127 . V_691 &
( F_148 ( V_847 ) |
F_148 ( V_703 ) ) )
return - V_16 ;
if ( ! ( V_127 . V_693 & F_148 ( V_702 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_305 ) )
return - V_501 ;
if ( ! ( V_7 -> V_18 . V_51 & V_307 ) )
return - V_501 ;
V_127 . V_691 &= ~ F_148 ( V_698 ) ;
break;
default:
return - V_501 ;
}
V_35 = F_174 ( V_7 , V_183 , V_596 , & V_127 ) ;
if ( V_127 . V_845 )
F_167 ( V_127 . V_845 ) ;
return V_35 ;
}
static int F_175 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 * V_596 = NULL ;
if ( V_30 -> V_5 [ V_506 ] )
V_596 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( V_183 -> V_28 -> V_131 != V_132 &&
V_183 -> V_28 -> V_131 != V_133 &&
V_183 -> V_28 -> V_131 != V_135 &&
V_183 -> V_28 -> V_131 != V_134 )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_895 )
return - V_501 ;
return F_176 ( V_7 , V_183 , V_596 ) ;
}
static int F_177 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_183 ,
T_2 * V_896 , T_2 * V_897 ,
struct V_898 * V_899 )
{
void * V_263 ;
struct V_4 * V_900 ;
V_263 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_731 ) ;
if ( ! V_263 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_896 ) ||
F_49 ( V_53 , V_901 , V_542 , V_897 ) ||
F_28 ( V_53 , V_274 , V_899 -> V_732 ) )
goto V_59;
V_900 = F_45 ( V_53 , V_902 ) ;
if ( ! V_900 )
goto V_59;
if ( ( V_899 -> V_734 & V_903 ) &&
F_28 ( V_53 , V_904 ,
V_899 -> V_905 ) )
goto V_59;
if ( ( ( V_899 -> V_734 & V_906 ) &&
F_28 ( V_53 , V_907 , V_899 -> V_908 ) ) ||
( ( V_899 -> V_734 & V_909 ) &&
F_28 ( V_53 , V_910 ,
V_899 -> V_911 ) ) ||
( ( V_899 -> V_734 & V_912 ) &&
F_28 ( V_53 , V_913 ,
V_899 -> V_914 ) ) ||
( ( V_899 -> V_734 & V_915 ) &&
F_54 ( V_53 , V_916 ,
V_899 -> V_51 ) ) ||
( ( V_899 -> V_734 & V_917 ) &&
F_28 ( V_53 , V_918 ,
V_899 -> V_919 ) ) ||
( ( V_899 -> V_734 & V_920 ) &&
F_54 ( V_53 , V_921 ,
V_899 -> V_922 ) ) )
goto V_59;
F_46 ( V_53 , V_900 ) ;
return F_64 ( V_53 , V_263 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
static int F_178 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_898 V_899 ;
struct V_6 * V_183 ;
struct V_1 * V_17 ;
T_2 V_896 [ V_542 ] ;
T_2 V_897 [ V_542 ] ;
int V_923 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_183 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_183 -> V_324 -> V_924 ) {
V_35 = - V_501 ;
goto V_823;
}
if ( V_17 -> V_131 != V_135 ) {
V_35 = - V_501 ;
goto V_823;
}
while ( 1 ) {
V_35 = F_179 ( V_183 , V_17 -> V_19 , V_923 , V_896 ,
V_897 , & V_899 ) ;
if ( V_35 == - V_603 )
break;
if ( V_35 )
goto V_823;
if ( F_177 ( V_32 , F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_461 , V_462 ,
V_17 -> V_19 , V_896 , V_897 ,
& V_899 ) < 0 )
goto V_552;
V_923 ++ ;
}
V_552:
V_34 -> args [ 2 ] = V_923 ;
V_35 = V_32 -> V_47 ;
V_823:
F_21 ( V_183 ) ;
return V_35 ;
}
static int F_180 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
int V_35 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_898 V_899 ;
struct V_31 * V_53 ;
T_2 * V_896 = NULL ;
T_2 V_897 [ V_542 ] ;
memset ( & V_899 , 0 , sizeof( V_899 ) ) ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
V_896 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( ! V_7 -> V_324 -> V_925 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_135 )
return - V_501 ;
V_35 = F_181 ( V_7 , V_183 , V_896 , V_897 , & V_899 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
if ( F_177 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_183 , V_896 , V_897 , & V_899 ) < 0 ) {
F_73 ( V_53 ) ;
return - V_81 ;
}
return F_74 ( V_53 , V_30 ) ;
}
static int F_182 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 * V_896 = NULL ;
T_2 * V_897 = NULL ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_901 ] )
return - V_16 ;
V_896 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_897 = F_23 ( V_30 -> V_5 [ V_901 ] ) ;
if ( ! V_7 -> V_324 -> V_926 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_135 )
return - V_501 ;
return F_183 ( V_7 , V_183 , V_896 , V_897 ) ;
}
static int F_184 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 * V_896 = NULL ;
T_2 * V_897 = NULL ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_901 ] )
return - V_16 ;
V_896 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_897 = F_23 ( V_30 -> V_5 [ V_901 ] ) ;
if ( ! V_7 -> V_324 -> V_352 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_135 )
return - V_501 ;
return F_185 ( V_7 , V_183 , V_896 , V_897 ) ;
}
static int F_186 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 * V_896 = NULL ;
if ( V_30 -> V_5 [ V_506 ] )
V_896 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( ! V_7 -> V_324 -> V_927 )
return - V_501 ;
return F_187 ( V_7 , V_183 , V_896 ) ;
}
static int F_188 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_928 V_127 ;
int V_35 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_929 = - 1 ;
V_127 . V_930 = - 1 ;
V_127 . V_931 = - 1 ;
V_127 . V_932 = - 1 ;
V_127 . V_933 = - 1 ;
V_127 . V_677 = - 1 ;
V_127 . V_680 = - 1 ;
if ( V_30 -> V_5 [ V_934 ] )
V_127 . V_929 =
F_34 ( V_30 -> V_5 [ V_934 ] ) ;
if ( V_30 -> V_5 [ V_935 ] )
V_127 . V_930 =
F_34 ( V_30 -> V_5 [ V_935 ] ) ;
if ( V_30 -> V_5 [ V_936 ] )
V_127 . V_931 =
F_34 ( V_30 -> V_5 [ V_936 ] ) ;
if ( V_30 -> V_5 [ V_937 ] ) {
V_127 . V_938 =
F_23 ( V_30 -> V_5 [ V_937 ] ) ;
V_127 . V_939 =
F_24 ( V_30 -> V_5 [ V_937 ] ) ;
}
if ( V_30 -> V_5 [ V_940 ] )
V_127 . V_932 = ! ! F_34 ( V_30 -> V_5 [ V_940 ] ) ;
if ( V_30 -> V_5 [ V_941 ] )
V_127 . V_933 =
F_76 ( V_30 -> V_5 [ V_941 ] ) ;
if ( V_30 -> V_5 [ V_676 ] ) {
if ( V_183 -> V_28 -> V_131 != V_134 )
return - V_16 ;
V_127 . V_677 =
F_189 ( V_30 -> V_5 [ V_676 ] ) ;
if ( V_127 . V_677 < 0 )
return - V_16 ;
if ( V_127 . V_677 != 0 &&
! ( V_7 -> V_18 . V_271 & V_678 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_679 ] ) {
T_2 V_24 ;
if ( V_183 -> V_28 -> V_131 != V_134 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_679 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_127 . V_680 = V_24 ;
if ( V_127 . V_680 &&
! ( V_7 -> V_18 . V_271 & V_681 ) )
return - V_16 ;
}
if ( ! V_7 -> V_324 -> V_356 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_132 &&
V_183 -> V_28 -> V_131 != V_134 )
return - V_501 ;
F_110 ( V_17 ) ;
V_35 = F_190 ( V_7 , V_183 , & V_127 ) ;
F_112 ( V_17 ) ;
return V_35 ;
}
static int F_191 ( struct V_4 * V_85 [] ,
struct V_942 * V_943 )
{
struct V_944 * V_945 = & V_943 -> V_945 ;
struct V_946 * V_947 = & V_943 -> V_947 ;
if ( ! V_85 [ V_948 ] )
return - V_16 ;
if ( ! V_85 [ V_949 ] )
return - V_16 ;
if ( ! V_85 [ V_950 ] )
return - V_16 ;
if ( ! V_85 [ V_951 ] )
return - V_16 ;
if ( ! V_85 [ V_952 ] )
return - V_16 ;
V_943 -> V_51 = F_4 ( V_85 [ V_948 ] ) ;
V_945 -> V_953 =
F_4 ( V_85 [ V_949 ] ) ;
V_945 -> V_954 =
F_4 ( V_85 [ V_950 ] ) ;
V_945 -> V_955 =
F_4 ( V_85 [ V_951 ] ) ;
V_947 -> V_956 =
F_4 ( V_85 [ V_952 ] ) ;
if ( V_85 [ V_957 ] )
V_947 -> V_958 =
F_4 ( V_85 [ V_957 ] ) ;
return 0 ;
}
static int F_192 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
int V_959 ;
char * V_128 = NULL ;
enum V_960 V_961 ;
if ( F_193 ( ! F_194 ( V_962 ) ) )
return - V_963 ;
if ( ! V_30 -> V_5 [ V_964 ] )
return - V_16 ;
V_128 = F_23 ( V_30 -> V_5 [ V_964 ] ) ;
if ( V_30 -> V_5 [ V_965 ] )
V_961 =
F_4 ( V_30 -> V_5 [ V_965 ] ) ;
else
V_961 = V_966 ;
switch ( V_961 ) {
case V_966 :
case V_967 :
break;
default:
return - V_16 ;
}
V_959 = F_195 ( V_128 , V_961 ) ;
return V_959 ;
}
static int F_196 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_968 V_969 ;
int V_35 = 0 ;
void * V_263 ;
struct V_4 * V_900 ;
struct V_31 * V_53 ;
if ( V_17 -> V_131 != V_135 )
return - V_501 ;
if ( ! V_7 -> V_324 -> V_970 )
return - V_501 ;
F_110 ( V_17 ) ;
if ( ! V_17 -> V_971 )
memcpy ( & V_969 , & V_972 , sizeof( V_969 ) ) ;
else
V_35 = F_197 ( V_7 , V_183 , & V_969 ) ;
F_112 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_973 ) ;
if ( ! V_263 )
goto V_552;
V_900 = F_45 ( V_53 , V_974 ) ;
if ( ! V_900 )
goto V_59;
if ( F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_53 ( V_53 , V_975 ,
V_969 . V_976 ) ||
F_53 ( V_53 , V_977 ,
V_969 . V_978 ) ||
F_53 ( V_53 , V_979 ,
V_969 . V_980 ) ||
F_53 ( V_53 , V_981 ,
V_969 . V_982 ) ||
F_54 ( V_53 , V_983 ,
V_969 . V_984 ) ||
F_54 ( V_53 , V_985 ,
V_969 . V_986 ) ||
F_54 ( V_53 , V_987 ,
V_969 . V_988 ) ||
F_54 ( V_53 , V_989 ,
V_969 . V_990 ) ||
F_28 ( V_53 , V_991 ,
V_969 . V_992 ) ||
F_54 ( V_53 , V_993 ,
V_969 . V_994 ) ||
F_28 ( V_53 , V_995 ,
V_969 . V_996 ) ||
F_53 ( V_53 , V_997 ,
V_969 . V_998 ) ||
F_28 ( V_53 , V_999 ,
V_969 . V_1000 ) ||
F_53 ( V_53 , V_1001 ,
V_969 . V_1002 ) ||
F_53 ( V_53 , V_1003 ,
V_969 . V_1004 ) ||
F_53 ( V_53 , V_1005 ,
V_969 . V_1006 ) ||
F_54 ( V_53 , V_1007 ,
V_969 . V_1008 ) ||
F_53 ( V_53 , V_1009 ,
V_969 . V_1010 ) ||
F_54 ( V_53 , V_1011 ,
V_969 . V_1012 ) ||
F_54 ( V_53 , V_1013 ,
V_969 . V_1014 ) ||
F_28 ( V_53 , V_1015 ,
V_969 . V_1016 ) ||
F_28 ( V_53 , V_1017 ,
V_969 . V_933 ) ||
F_28 ( V_53 , V_1018 ,
V_969 . V_1019 ) ||
F_53 ( V_53 , V_1020 ,
V_969 . V_1021 ) ||
F_53 ( V_53 , V_1022 ,
V_969 . V_1023 ) ||
F_28 ( V_53 , V_1024 ,
V_969 . V_1025 ) ||
F_53 ( V_53 , V_1026 ,
V_969 . V_1027 ) ||
F_28 ( V_53 , V_1028 ,
V_969 . V_1029 ) )
goto V_59;
F_46 ( V_53 , V_900 ) ;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
V_552:
F_73 ( V_53 ) ;
return - V_81 ;
}
static int F_198 ( struct V_29 * V_30 ,
struct V_968 * V_1030 ,
V_22 * V_1031 )
{
struct V_4 * V_85 [ V_1032 + 1 ] ;
V_22 V_692 = 0 ;
#define F_199 ( V_85 , V_1030 , T_7 , T_8 , V_158 , V_692 , V_45 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_974 ] )
return - V_16 ;
if ( F_33 ( V_85 , V_1032 ,
V_30 -> V_5 [ V_974 ] ,
V_1033 ) )
return - V_16 ;
F_111 ( V_1032 > 32 ) ;
F_199 ( V_85 , V_1030 , V_976 , 1 , 255 ,
V_692 , V_975 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_978 , 1 , 255 ,
V_692 , V_977 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_980 , 1 , 255 ,
V_692 , V_979 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_982 , 0 , 255 ,
V_692 , V_981 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_984 , 0 , 16 ,
V_692 , V_983 ,
F_34 ) ;
F_199 ( V_85 , V_1030 , V_986 , 1 , 255 ,
V_692 , V_985 , F_34 ) ;
F_199 ( V_85 , V_1030 , V_988 , 1 , 255 ,
V_692 , V_987 ,
F_34 ) ;
F_199 ( V_85 , V_1030 , V_990 , 0 , 1 ,
V_692 , V_989 ,
F_34 ) ;
F_199 ( V_85 , V_1030 , V_992 ,
1 , 255 , V_692 ,
V_991 ,
F_4 ) ;
F_199 ( V_85 , V_1030 , V_994 , 0 , 255 ,
V_692 , V_993 ,
F_34 ) ;
F_199 ( V_85 , V_1030 , V_996 , 1 , 65535 ,
V_692 , V_995 ,
F_4 ) ;
F_199 ( V_85 , V_1030 , V_998 , 1 , 65535 ,
V_692 , V_997 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_1000 ,
1 , 65535 , V_692 ,
V_999 ,
F_4 ) ;
F_199 ( V_85 , V_1030 , V_1002 ,
1 , 65535 , V_692 ,
V_1001 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_1004 ,
1 , 65535 , V_692 ,
V_1003 ,
F_76 ) ;
F_199 ( V_85 , V_1030 ,
V_1006 ,
1 , 65535 , V_692 ,
V_1005 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_1008 , 0 , 4 ,
V_692 , V_1007 ,
F_34 ) ;
F_199 ( V_85 , V_1030 , V_1010 , 1 , 65535 ,
V_692 , V_1009 ,
F_76 ) ;
F_199 ( V_85 , V_1030 ,
V_1012 , 0 , 1 ,
V_692 , V_1011 ,
F_34 ) ;
F_199 ( V_85 , V_1030 , V_1014 , 0 , 1 ,
V_692 , V_1013 ,
F_34 ) ;
F_199 ( V_85 , V_1030 , V_1016 , - 255 , 0 ,
V_692 , V_1015 ,
V_1034 ) ;
F_199 ( V_85 , V_1030 , V_933 , 0 , 16 ,
V_692 , V_1017 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_1019 ,
1 , 65535 , V_692 ,
V_1018 ,
F_4 ) ;
F_199 ( V_85 , V_1030 , V_1021 , 1 , 65535 ,
V_692 , V_1020 ,
F_76 ) ;
F_199 ( V_85 , V_1030 ,
V_1023 ,
1 , 65535 , V_692 ,
V_1022 ,
F_76 ) ;
F_199 ( V_85 , V_1030 , V_1025 ,
V_1035 ,
V_889 ,
V_692 , V_1024 ,
F_4 ) ;
F_199 ( V_85 , V_1030 , V_1027 ,
0 , 65535 , V_692 ,
V_1026 , F_76 ) ;
F_199 ( V_85 , V_1030 , V_1029 , 1 , 0xffffffff ,
V_692 , V_1028 ,
F_4 ) ;
if ( V_1031 )
* V_1031 = V_692 ;
return 0 ;
#undef F_199
}
static int F_200 ( struct V_29 * V_30 ,
struct V_1036 * V_1037 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_4 * V_85 [ V_1038 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1039 ] )
return - V_16 ;
if ( F_33 ( V_85 , V_1038 ,
V_30 -> V_5 [ V_1039 ] ,
V_1040 ) )
return - V_16 ;
if ( V_85 [ V_1041 ] )
V_1037 -> V_1042 =
( F_34 ( V_85 [ V_1041 ] ) ) ?
V_1043 :
V_1044 ;
if ( V_85 [ V_1045 ] )
V_1037 -> V_1046 =
( F_34 ( V_85 [ V_1045 ] ) ) ?
V_1047 :
V_1048 ;
if ( V_85 [ V_1049 ] )
V_1037 -> V_1050 =
( F_34 ( V_85 [ V_1049 ] ) ) ?
V_1051 :
V_1052 ;
if ( V_85 [ V_1053 ] ) {
struct V_4 * V_1054 =
V_85 [ V_1053 ] ;
if ( ! F_22 ( V_1054 ) )
return - V_16 ;
V_1037 -> V_1055 = F_23 ( V_1054 ) ;
V_1037 -> V_1056 = F_24 ( V_1054 ) ;
}
if ( V_85 [ V_1057 ] &&
! ( V_7 -> V_18 . V_271 & V_1058 ) )
return - V_16 ;
V_1037 -> V_1059 = F_201 ( V_85 [ V_1057 ] ) ;
V_1037 -> V_1060 = F_201 ( V_85 [ V_1061 ] ) ;
V_1037 -> V_1062 = F_201 ( V_85 [ V_1063 ] ) ;
if ( V_1037 -> V_1062 )
V_1037 -> V_1059 = true ;
if ( V_85 [ V_1064 ] ) {
if ( ! V_1037 -> V_1059 )
return - V_16 ;
V_1037 -> V_1065 =
F_34 ( V_85 [ V_1064 ] ) ;
}
return 0 ;
}
static int F_202 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_968 V_1030 ;
V_22 V_692 ;
int V_35 ;
if ( V_17 -> V_131 != V_135 )
return - V_501 ;
if ( ! V_7 -> V_324 -> V_354 )
return - V_501 ;
V_35 = F_198 ( V_30 , & V_1030 , & V_692 ) ;
if ( V_35 )
return V_35 ;
F_110 ( V_17 ) ;
if ( ! V_17 -> V_971 )
V_35 = - V_140 ;
if ( ! V_35 )
V_35 = F_203 ( V_7 , V_183 , V_692 , & V_1030 ) ;
F_112 ( V_17 ) ;
return V_35 ;
}
static int F_204 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1066 * V_1067 ;
struct V_31 * V_53 ;
void * V_263 = NULL ;
struct V_4 * V_1068 ;
unsigned int V_143 ;
if ( ! V_962 )
return - V_16 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_81 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1069 ) ;
if ( ! V_263 )
goto V_1070;
if ( F_205 () &&
F_28 ( V_53 , V_965 ,
V_967 ) )
goto V_59;
F_206 () ;
V_1067 = F_207 ( V_962 ) ;
if ( F_58 ( V_53 , V_964 , V_1067 -> V_1071 ) ||
( V_1067 -> V_1072 &&
F_54 ( V_53 , V_1073 , V_1067 -> V_1072 ) ) )
goto V_1074;
V_1068 = F_45 ( V_53 , V_1075 ) ;
if ( ! V_1068 )
goto V_1074;
for ( V_143 = 0 ; V_143 < V_1067 -> V_1076 ; V_143 ++ ) {
struct V_4 * V_1077 ;
const struct V_942 * V_943 ;
const struct V_944 * V_945 ;
const struct V_946 * V_947 ;
V_943 = & V_1067 -> V_1078 [ V_143 ] ;
V_945 = & V_943 -> V_945 ;
V_947 = & V_943 -> V_947 ;
V_1077 = F_45 ( V_53 , V_143 ) ;
if ( ! V_1077 )
goto V_1074;
if ( F_28 ( V_53 , V_948 ,
V_943 -> V_51 ) ||
F_28 ( V_53 , V_949 ,
V_945 -> V_953 ) ||
F_28 ( V_53 , V_950 ,
V_945 -> V_954 ) ||
F_28 ( V_53 , V_951 ,
V_945 -> V_955 ) ||
F_28 ( V_53 , V_957 ,
V_947 -> V_958 ) ||
F_28 ( V_53 , V_952 ,
V_947 -> V_956 ) )
goto V_1074;
F_46 ( V_53 , V_1077 ) ;
}
F_208 () ;
F_46 ( V_53 , V_1068 ) ;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_1074:
F_208 () ;
V_59:
F_65 ( V_53 , V_263 ) ;
V_1070:
F_73 ( V_53 ) ;
return - V_456 ;
}
static int F_209 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_85 [ V_1079 + 1 ] ;
struct V_4 * V_1077 ;
char * V_1071 = NULL ;
int V_1080 = 0 , V_959 = 0 ;
V_22 V_1081 = 0 , V_1082 = 0 , V_1083 ;
enum V_1084 V_1072 = V_1085 ;
struct V_1066 * V_1086 = NULL ;
if ( ! V_30 -> V_5 [ V_964 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1075 ] )
return - V_16 ;
V_1071 = F_23 ( V_30 -> V_5 [ V_964 ] ) ;
if ( V_30 -> V_5 [ V_1073 ] )
V_1072 = F_34 ( V_30 -> V_5 [ V_1073 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1081 ++ ;
if ( V_1081 > V_1087 )
return - V_16 ;
}
if ( ! F_210 ( V_1071 ) )
return - V_16 ;
V_1083 = sizeof( struct V_1066 ) +
V_1081 * sizeof( struct V_942 ) ;
V_1086 = F_38 ( V_1083 , V_125 ) ;
if ( ! V_1086 )
return - V_126 ;
V_1086 -> V_1076 = V_1081 ;
V_1086 -> V_1071 [ 0 ] = V_1071 [ 0 ] ;
V_1086 -> V_1071 [ 1 ] = V_1071 [ 1 ] ;
if ( F_211 ( V_1072 ) )
V_1086 -> V_1072 = V_1072 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_94 ( V_85 , V_1079 ,
F_23 ( V_1077 ) , F_24 ( V_1077 ) ,
V_1088 ) ;
V_959 = F_191 ( V_85 , & V_1086 -> V_1078 [ V_1082 ] ) ;
if ( V_959 )
goto V_1089;
V_1082 ++ ;
if ( V_1082 > V_1087 ) {
V_959 = - V_16 ;
goto V_1089;
}
}
V_959 = F_212 ( V_1086 ) ;
V_1086 = NULL ;
V_1089:
F_41 ( V_1086 ) ;
return V_959 ;
}
static int F_213 ( struct V_4 * V_1090 )
{
struct V_4 * V_1091 , * V_1092 ;
int V_339 = 0 , V_1093 , V_1094 ;
F_39 (attr1, freqs, tmp1) {
V_339 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1091 != V_1092 &&
F_4 ( V_1091 ) == F_4 ( V_1092 ) )
return 0 ;
}
return V_339 ;
}
static int F_214 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
struct V_1095 * V_1096 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1097 = 0 , V_339 , V_143 ;
T_10 V_1056 ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_324 -> V_1098 )
return - V_501 ;
if ( V_7 -> V_1099 || V_7 -> V_1100 ) {
V_35 = - V_503 ;
goto V_1101;
}
if ( V_30 -> V_5 [ V_1102 ] ) {
V_339 = F_213 (
V_30 -> V_5 [ V_1102 ] ) ;
if ( ! V_339 ) {
V_35 = - V_16 ;
goto V_1101;
}
} else {
V_339 = F_215 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1103 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1097 ++ ;
if ( V_1097 > V_18 -> V_288 ) {
V_35 = - V_16 ;
goto V_1101;
}
if ( V_30 -> V_5 [ V_630 ] )
V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
else
V_1056 = 0 ;
if ( V_1056 > V_18 -> V_292 ) {
V_35 = - V_16 ;
goto V_1101;
}
V_1096 = F_38 ( sizeof( * V_1096 )
+ sizeof( * V_1096 -> V_1104 ) * V_1097
+ sizeof( * V_1096 -> V_340 ) * V_339
+ V_1056 , V_125 ) ;
if ( ! V_1096 ) {
V_35 = - V_126 ;
goto V_1101;
}
if ( V_1097 )
V_1096 -> V_1104 = ( void * ) & V_1096 -> V_340 [ V_339 ] ;
V_1096 -> V_1097 = V_1097 ;
if ( V_1056 ) {
if ( V_1096 -> V_1104 )
V_1096 -> V_1055 = ( void * ) ( V_1096 -> V_1104 + V_1097 ) ;
else
V_1096 -> V_1055 = ( void * ) ( V_1096 -> V_340 + V_339 ) ;
}
V_143 = 0 ;
if ( V_30 -> V_5 [ V_1102 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_79 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1105;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1096 -> V_340 [ V_143 ] = V_55 ;
V_143 ++ ;
}
} else {
enum V_269 V_270 ;
for ( V_270 = 0 ; V_270 < V_335 ; V_270 ++ ) {
int V_145 ;
if ( ! V_18 -> V_336 [ V_270 ] )
continue;
for ( V_145 = 0 ; V_145 < V_18 -> V_336 [ V_270 ] -> V_339 ; V_145 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_336 [ V_270 ] -> V_340 [ V_145 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1096 -> V_340 [ V_143 ] = V_55 ;
V_143 ++ ;
}
}
}
if ( ! V_143 ) {
V_35 = - V_16 ;
goto V_1105;
}
V_1096 -> V_339 = V_143 ;
V_143 = 0 ;
if ( V_30 -> V_5 [ V_1103 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_571 ) {
V_35 = - V_16 ;
goto V_1105;
}
V_1096 -> V_1104 [ V_143 ] . V_545 = F_24 ( V_45 ) ;
memcpy ( V_1096 -> V_1104 [ V_143 ] . V_547 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_143 ++ ;
}
}
if ( V_30 -> V_5 [ V_630 ] ) {
V_1096 -> V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
memcpy ( ( void * ) V_1096 -> V_1055 ,
F_23 ( V_30 -> V_5 [ V_630 ] ) ,
V_1096 -> V_1056 ) ;
}
for ( V_143 = 0 ; V_143 < V_335 ; V_143 ++ )
if ( V_18 -> V_336 [ V_143 ] )
V_1096 -> V_1106 [ V_143 ] =
( 1 << V_18 -> V_336 [ V_143 ] -> V_241 ) - 1 ;
if ( V_30 -> V_5 [ V_1107 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_269 V_270 = F_216 ( V_45 ) ;
if ( V_270 < 0 || V_270 >= V_335 ) {
V_35 = - V_16 ;
goto V_1105;
}
if ( ! V_18 -> V_336 [ V_270 ] )
continue;
V_35 = F_217 ( V_18 -> V_336 [ V_270 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1096 -> V_1106 [ V_270 ] ) ;
if ( V_35 )
goto V_1105;
}
}
if ( V_30 -> V_5 [ V_1108 ] ) {
V_1096 -> V_51 = F_4 (
V_30 -> V_5 [ V_1108 ] ) ;
if ( ( V_1096 -> V_51 & V_1109 ) &&
! ( V_18 -> V_271 & V_1110 ) ) {
V_35 = - V_501 ;
goto V_1105;
}
}
V_1096 -> V_1111 =
F_201 ( V_30 -> V_5 [ V_1112 ] ) ;
V_1096 -> V_17 = V_17 ;
V_1096 -> V_18 = & V_7 -> V_18 ;
V_1096 -> V_1113 = V_1114 ;
V_7 -> V_1099 = V_1096 ;
V_35 = F_218 ( V_7 , V_1096 ) ;
if ( ! V_35 ) {
F_219 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_220 ( V_17 -> V_19 ) ;
} else {
V_1105:
V_7 -> V_1099 = NULL ;
F_41 ( V_1096 ) ;
}
V_1101:
return V_35 ;
}
static int F_221 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1115 * V_1096 ;
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1097 = 0 , V_1116 = 0 , V_339 , V_143 ;
V_22 V_1117 ;
enum V_269 V_270 ;
T_10 V_1056 ;
struct V_4 * V_85 [ V_1118 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_395 ) ||
! V_7 -> V_324 -> V_396 )
return - V_501 ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1119 ] )
return - V_16 ;
V_1117 = F_4 ( V_30 -> V_5 [ V_1119 ] ) ;
if ( V_1117 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_1102 ] ) {
V_339 = F_213 (
V_30 -> V_5 [ V_1102 ] ) ;
if ( ! V_339 )
return - V_16 ;
} else {
V_339 = F_215 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1103 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1097 ++ ;
if ( V_1097 > V_18 -> V_290 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1120 ] )
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_1116 ++ ;
if ( V_1116 > V_18 -> V_296 )
return - V_16 ;
if ( V_30 -> V_5 [ V_630 ] )
V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
else
V_1056 = 0 ;
if ( V_1056 > V_18 -> V_294 )
return - V_16 ;
if ( V_7 -> V_1121 ) {
V_35 = - V_963 ;
goto V_552;
}
V_1096 = F_38 ( sizeof( * V_1096 )
+ sizeof( * V_1096 -> V_1104 ) * V_1097
+ sizeof( * V_1096 -> V_1122 ) * V_1116
+ sizeof( * V_1096 -> V_340 ) * V_339
+ V_1056 , V_125 ) ;
if ( ! V_1096 ) {
V_35 = - V_126 ;
goto V_552;
}
if ( V_1097 )
V_1096 -> V_1104 = ( void * ) & V_1096 -> V_340 [ V_339 ] ;
V_1096 -> V_1097 = V_1097 ;
if ( V_1056 ) {
if ( V_1096 -> V_1104 )
V_1096 -> V_1055 = ( void * ) ( V_1096 -> V_1104 + V_1097 ) ;
else
V_1096 -> V_1055 = ( void * ) ( V_1096 -> V_340 + V_339 ) ;
}
if ( V_1116 ) {
if ( V_1096 -> V_1055 )
V_1096 -> V_1122 = ( void * ) ( V_1096 -> V_1055 + V_1056 ) ;
else if ( V_1096 -> V_1104 )
V_1096 -> V_1122 =
( void * ) ( V_1096 -> V_1104 + V_1097 ) ;
else
V_1096 -> V_1122 =
( void * ) ( V_1096 -> V_340 + V_339 ) ;
}
V_1096 -> V_1116 = V_1116 ;
V_143 = 0 ;
if ( V_30 -> V_5 [ V_1102 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_79 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1105;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1096 -> V_340 [ V_143 ] = V_55 ;
V_143 ++ ;
}
} else {
for ( V_270 = 0 ; V_270 < V_335 ; V_270 ++ ) {
int V_145 ;
if ( ! V_18 -> V_336 [ V_270 ] )
continue;
for ( V_145 = 0 ; V_145 < V_18 -> V_336 [ V_270 ] -> V_339 ; V_145 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_336 [ V_270 ] -> V_340 [ V_145 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1096 -> V_340 [ V_143 ] = V_55 ;
V_143 ++ ;
}
}
}
if ( ! V_143 ) {
V_35 = - V_16 ;
goto V_1105;
}
V_1096 -> V_339 = V_143 ;
V_143 = 0 ;
if ( V_30 -> V_5 [ V_1103 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_571 ) {
V_35 = - V_16 ;
goto V_1105;
}
V_1096 -> V_1104 [ V_143 ] . V_545 = F_24 ( V_45 ) ;
memcpy ( V_1096 -> V_1104 [ V_143 ] . V_547 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_143 ++ ;
}
}
V_143 = 0 ;
if ( V_30 -> V_5 [ V_1120 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_547 , * V_1123 ;
F_94 ( V_85 , V_1118 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1124 ) ;
V_547 = V_85 [ V_1125 ] ;
if ( V_547 ) {
if ( F_24 ( V_547 ) > V_571 ) {
V_35 = - V_16 ;
goto V_1105;
}
memcpy ( V_1096 -> V_1122 [ V_143 ] . V_547 . V_547 ,
F_23 ( V_547 ) , F_24 ( V_547 ) ) ;
V_1096 -> V_1122 [ V_143 ] . V_547 . V_545 =
F_24 ( V_547 ) ;
}
V_1123 = V_85 [ V_1126 ] ;
if ( V_1123 )
V_1096 -> V_1127 = F_4 ( V_1123 ) ;
else
V_1096 -> V_1127 =
V_1128 ;
V_143 ++ ;
}
}
if ( V_30 -> V_5 [ V_630 ] ) {
V_1096 -> V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
memcpy ( ( void * ) V_1096 -> V_1055 ,
F_23 ( V_30 -> V_5 [ V_630 ] ) ,
V_1096 -> V_1056 ) ;
}
if ( V_30 -> V_5 [ V_1108 ] ) {
V_1096 -> V_51 = F_4 (
V_30 -> V_5 [ V_1108 ] ) ;
if ( ( V_1096 -> V_51 & V_1109 ) &&
! ( V_18 -> V_271 & V_1110 ) ) {
V_35 = - V_501 ;
goto V_1105;
}
}
V_1096 -> V_183 = V_183 ;
V_1096 -> V_18 = & V_7 -> V_18 ;
V_1096 -> V_1117 = V_1117 ;
V_1096 -> V_1113 = V_1114 ;
V_35 = F_222 ( V_7 , V_183 , V_1096 ) ;
if ( ! V_35 ) {
V_7 -> V_1121 = V_1096 ;
F_223 ( V_7 , V_183 ,
V_1129 ) ;
goto V_552;
}
V_1105:
F_41 ( V_1096 ) ;
V_552:
return V_35 ;
}
static int F_224 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_395 ) ||
! V_7 -> V_324 -> V_1130 )
return - V_501 ;
return F_225 ( V_7 , false ) ;
}
static int F_226 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_481 V_482 ;
enum V_1084 V_1072 ;
int V_35 ;
V_1072 = F_227 ( V_17 -> V_18 ) ;
if ( V_1072 == V_1085 )
return - V_16 ;
V_35 = F_78 ( V_7 , V_30 , & V_482 ) ;
if ( V_35 )
return V_35 ;
if ( F_228 ( V_183 ) )
return - V_503 ;
if ( V_17 -> V_1131 )
return - V_503 ;
V_35 = F_147 ( V_17 -> V_18 , & V_482 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_229 ( V_17 -> V_18 , & V_482 ) )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_1132 )
return - V_501 ;
V_35 = F_149 ( V_7 , V_17 , V_17 -> V_131 ,
V_482 . V_55 , V_683 ,
F_148 ( V_482 . V_485 ) ) ;
if ( V_35 )
return V_35 ;
V_35 = V_7 -> V_324 -> V_1132 ( & V_7 -> V_18 , V_183 , & V_482 ) ;
if ( ! V_35 ) {
V_17 -> V_684 = V_482 . V_55 ;
V_17 -> V_1131 = true ;
V_17 -> V_1133 = V_1114 ;
}
return V_35 ;
}
static int F_230 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_1134 V_127 ;
static struct V_4 * V_1135 [ V_1136 + 1 ] ;
T_2 V_656 = 0 ;
int V_35 ;
bool V_1137 = false ;
if ( ! V_7 -> V_324 -> V_413 ||
! ( V_7 -> V_18 . V_51 & V_412 ) )
return - V_501 ;
switch ( V_183 -> V_28 -> V_131 ) {
case V_132 :
case V_134 :
V_1137 = true ;
if ( ! V_17 -> V_502 )
return - V_16 ;
break;
case V_136 :
case V_135 :
break;
default:
return - V_501 ;
}
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
if ( ! V_30 -> V_5 [ V_484 ] ||
! V_30 -> V_5 [ V_1138 ] )
return - V_16 ;
if ( V_1137 && ! V_30 -> V_5 [ V_1139 ] )
return - V_16 ;
V_127 . V_1140 = F_4 ( V_30 -> V_5 [ V_1138 ] ) ;
if ( ! V_1137 )
goto V_1141;
V_35 = F_141 ( V_30 -> V_5 , & V_127 . V_1142 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1135 , V_1136 ,
V_30 -> V_5 [ V_1139 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_141 ( V_1135 , & V_127 . V_1143 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1135 [ V_1144 ] )
return - V_16 ;
V_127 . V_1145 =
F_76 ( V_1135 [ V_1144 ] ) ;
if ( V_127 . V_1145 >= V_127 . V_1143 . V_637 )
return - V_16 ;
if ( V_127 . V_1143 . V_636 [ V_127 . V_1145 ] !=
V_127 . V_1140 )
return - V_16 ;
if ( V_1135 [ V_1146 ] ) {
V_127 . V_1147 =
F_76 ( V_1135 [ V_1146 ] ) ;
if ( V_127 . V_1147 >=
V_127 . V_1143 . V_646 )
return - V_16 ;
if ( V_127 . V_1143 . V_645 [ V_127 . V_1147 ] !=
V_127 . V_1140 )
return - V_16 ;
}
V_1141:
V_35 = F_78 ( V_7 , V_30 , & V_127 . V_482 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_84 ( & V_7 -> V_18 , & V_127 . V_482 ) )
return - V_16 ;
if ( V_183 -> V_28 -> V_131 == V_132 ||
V_183 -> V_28 -> V_131 == V_134 ||
V_183 -> V_28 -> V_131 == V_136 ) {
V_35 = F_147 ( V_17 -> V_18 ,
& V_127 . V_482 ) ;
if ( V_35 < 0 ) {
return V_35 ;
} else if ( V_35 ) {
V_656 = F_148 ( V_127 . V_482 . V_485 ) ;
V_127 . V_682 = true ;
}
}
V_35 = F_149 ( V_7 , V_17 , V_17 -> V_131 ,
V_127 . V_482 . V_55 ,
V_683 ,
V_656 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_1148 ] )
V_127 . V_1149 = true ;
F_110 ( V_17 ) ;
V_35 = F_231 ( V_7 , V_183 , & V_127 ) ;
F_112 ( V_17 ) ;
return V_35 ;
}
static int F_232 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1150 * V_1151 )
{
struct V_1152 * V_328 = & V_1151 -> V_1153 ;
const struct V_1154 * V_1155 ;
void * V_263 ;
struct V_4 * V_1156 ;
bool V_1157 = false ;
F_43 ( V_17 ) ;
V_263 = F_25 ( V_53 , F_69 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1158 ) ;
if ( ! V_263 )
return - 1 ;
F_233 ( V_34 , V_263 , & V_38 ) ;
if ( F_28 ( V_53 , V_274 , V_7 -> V_1159 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_59;
if ( F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
V_1156 = F_45 ( V_53 , V_1160 ) ;
if ( ! V_1156 )
goto V_59;
if ( ( ! F_234 ( V_328 -> V_505 ) &&
F_49 ( V_53 , V_1161 , V_542 , V_328 -> V_505 ) ) )
goto V_59;
F_206 () ;
V_1155 = F_207 ( V_328 -> V_1155 ) ;
if ( V_1155 ) {
if ( F_102 ( V_53 , V_1162 , V_1155 -> V_1157 ) )
goto V_1163;
V_1157 = true ;
if ( V_1155 -> V_47 && F_49 ( V_53 , V_1164 ,
V_1155 -> V_47 , V_1155 -> V_128 ) )
goto V_1163;
}
V_1155 = F_207 ( V_328 -> V_638 ) ;
if ( V_1155 ) {
if ( ! V_1157 && F_102 ( V_53 , V_1162 , V_1155 -> V_1157 ) )
goto V_1163;
if ( V_1155 -> V_47 && F_49 ( V_53 , V_1165 ,
V_1155 -> V_47 , V_1155 -> V_128 ) )
goto V_1163;
}
F_208 () ;
if ( V_328 -> V_502 &&
F_53 ( V_53 , V_1166 , V_328 -> V_502 ) )
goto V_59;
if ( F_53 ( V_53 , V_1167 , V_328 -> V_877 ) ||
F_28 ( V_53 , V_1168 , V_328 -> V_684 -> V_58 ) ||
F_28 ( V_53 , V_1169 , V_328 -> V_1170 ) ||
F_28 ( V_53 , V_1171 ,
F_235 ( V_1114 - V_1151 -> V_1172 ) ) )
goto V_59;
switch ( V_7 -> V_18 . V_760 ) {
case V_761 :
if ( F_28 ( V_53 , V_1173 , V_328 -> signal ) )
goto V_59;
break;
case V_1174 :
if ( F_54 ( V_53 , V_1175 , V_328 -> signal ) )
goto V_59;
break;
default:
break;
}
switch ( V_17 -> V_131 ) {
case V_138 :
case V_137 :
if ( V_1151 == V_17 -> V_139 &&
F_28 ( V_53 , V_1176 ,
V_1177 ) )
goto V_59;
break;
case V_136 :
if ( V_1151 == V_17 -> V_139 &&
F_28 ( V_53 , V_1176 ,
V_1178 ) )
goto V_59;
break;
default:
break;
}
F_46 ( V_53 , V_1156 ) ;
return F_64 ( V_53 , V_263 ) ;
V_1163:
F_208 () ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
static int F_236 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1150 * V_1098 ;
struct V_1 * V_17 ;
int V_460 = V_34 -> args [ 2 ] , V_95 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_110 ( V_17 ) ;
F_237 ( & V_7 -> V_1179 ) ;
F_238 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1159 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_95 <= V_460 )
continue;
if ( F_232 ( V_32 , V_34 ,
V_34 -> V_36 -> V_461 , V_462 ,
V_7 , V_17 , V_1098 ) < 0 ) {
V_95 -- ;
break;
}
}
F_239 ( & V_7 -> V_1179 ) ;
F_112 ( V_17 ) ;
V_34 -> args [ 2 ] = V_95 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_240 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_183 ,
struct V_1180 * V_1181 )
{
void * V_263 ;
struct V_4 * V_1182 ;
V_263 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1183 ) ;
if ( ! V_263 )
return - V_126 ;
if ( F_28 ( V_53 , V_10 , V_183 -> V_20 ) )
goto V_59;
V_1182 = F_45 ( V_53 , V_1184 ) ;
if ( ! V_1182 )
goto V_59;
if ( F_28 ( V_53 , V_1185 ,
V_1181 -> V_684 -> V_58 ) )
goto V_59;
if ( ( V_1181 -> V_734 & V_1186 ) &&
F_54 ( V_53 , V_1187 , V_1181 -> V_1188 ) )
goto V_59;
if ( ( V_1181 -> V_734 & V_1189 ) &&
F_29 ( V_53 , V_1190 ) )
goto V_59;
if ( ( V_1181 -> V_734 & V_1191 ) &&
F_102 ( V_53 , V_1192 ,
V_1181 -> V_1193 ) )
goto V_59;
if ( ( V_1181 -> V_734 & V_1194 ) &&
F_102 ( V_53 , V_1195 ,
V_1181 -> V_1196 ) )
goto V_59;
if ( ( V_1181 -> V_734 & V_1197 ) &&
F_102 ( V_53 , V_1198 ,
V_1181 -> V_1199 ) )
goto V_59;
if ( ( V_1181 -> V_734 & V_1200 ) &&
F_102 ( V_53 , V_1201 ,
V_1181 -> V_1202 ) )
goto V_59;
if ( ( V_1181 -> V_734 & V_1203 ) &&
F_102 ( V_53 , V_1204 ,
V_1181 -> V_1205 ) )
goto V_59;
F_46 ( V_53 , V_1182 ) ;
return F_64 ( V_53 , V_263 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
static int F_241 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1180 V_1181 ;
struct V_6 * V_183 ;
struct V_1 * V_17 ;
int V_1206 = V_34 -> args [ 2 ] ;
int V_328 ;
V_328 = F_13 ( V_32 , V_34 , & V_183 , & V_17 ) ;
if ( V_328 )
return V_328 ;
if ( ! V_17 -> V_19 ) {
V_328 = - V_16 ;
goto V_823;
}
if ( ! V_183 -> V_324 -> V_1207 ) {
V_328 = - V_501 ;
goto V_823;
}
while ( 1 ) {
struct V_54 * V_55 ;
V_328 = F_242 ( V_183 , V_17 -> V_19 , V_1206 , & V_1181 ) ;
if ( V_328 == - V_603 )
break;
if ( V_328 )
goto V_823;
if ( ! V_1181 . V_684 ) {
V_328 = - V_16 ;
goto V_552;
}
V_55 = F_79 ( & V_183 -> V_18 ,
V_1181 . V_684 -> V_58 ) ;
if ( ! V_55 || V_55 -> V_51 & V_60 ) {
V_1206 ++ ;
continue;
}
if ( F_240 ( V_32 ,
F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_461 , V_462 ,
V_17 -> V_19 , & V_1181 ) < 0 )
goto V_552;
V_1206 ++ ;
}
V_552:
V_34 -> args [ 2 ] = V_1206 ;
V_328 = V_32 -> V_47 ;
V_823:
F_21 ( V_183 ) ;
return V_328 ;
}
static bool F_243 ( V_22 V_1208 )
{
return ! ( V_1208 & ~ ( V_1209 |
V_1210 ) ) ;
}
static int F_244 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_505 , * V_547 , * V_1055 = NULL , * V_1211 = NULL ;
int V_35 , V_545 , V_1056 = 0 , V_1212 = 0 ;
enum V_648 V_649 ;
struct V_83 V_82 ;
bool V_1213 ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_669 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_546 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_484 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_82 ) ;
if ( V_35 )
return V_35 ;
if ( V_82 . V_95 >= 0 ) {
if ( V_82 . type != - 1 && V_82 . type != V_599 )
return - V_16 ;
if ( ! V_82 . V_97 . V_82 || ! V_82 . V_97 . V_98 )
return - V_16 ;
if ( ( V_82 . V_97 . V_102 != V_129 ||
V_82 . V_97 . V_98 != V_1214 ) &&
( V_82 . V_97 . V_102 != V_130 ||
V_82 . V_97 . V_98 != V_1215 ) )
return - V_16 ;
if ( V_82 . V_95 > 4 )
return - V_16 ;
} else {
V_82 . V_97 . V_98 = 0 ;
V_82 . V_97 . V_82 = NULL ;
}
if ( V_82 . V_95 >= 0 ) {
int V_143 ;
bool V_1216 = false ;
for ( V_143 = 0 ; V_143 < V_7 -> V_18 . V_311 ; V_143 ++ ) {
if ( V_82 . V_97 . V_102 == V_7 -> V_18 . V_312 [ V_143 ] ) {
V_1216 = true ;
break;
}
}
if ( ! V_1216 )
return - V_16 ;
}
if ( ! V_7 -> V_324 -> V_358 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_55 = F_79 ( & V_7 -> V_18 ,
F_4 ( V_30 -> V_5 [ V_484 ] ) ) ;
if ( ! V_55 || ( V_55 -> V_51 & V_60 ) )
return - V_16 ;
V_547 = F_23 ( V_30 -> V_5 [ V_546 ] ) ;
V_545 = F_24 ( V_30 -> V_5 [ V_546 ] ) ;
if ( V_30 -> V_5 [ V_630 ] ) {
V_1055 = F_23 ( V_30 -> V_5 [ V_630 ] ) ;
V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
}
V_649 = F_4 ( V_30 -> V_5 [ V_669 ] ) ;
if ( ! F_143 ( V_7 , V_649 , V_652 ) )
return - V_16 ;
if ( V_649 == V_654 &&
! V_30 -> V_5 [ V_1217 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1217 ] ) {
if ( V_649 != V_654 )
return - V_16 ;
V_1211 = F_23 ( V_30 -> V_5 [ V_1217 ] ) ;
V_1212 = F_24 ( V_30 -> V_5 [ V_1217 ] ) ;
if ( V_1212 < 4 )
return - V_16 ;
}
V_1213 = ! ! V_30 -> V_5 [ V_1218 ] ;
if ( V_1213 )
return 0 ;
F_110 ( V_183 -> V_28 ) ;
V_35 = F_245 ( V_7 , V_183 , V_55 , V_649 , V_505 ,
V_547 , V_545 , V_1055 , V_1056 ,
V_82 . V_97 . V_82 , V_82 . V_97 . V_98 , V_82 . V_95 ,
V_1211 , V_1212 ) ;
F_112 ( V_183 -> V_28 ) ;
return V_35 ;
}
static int F_146 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1219 * V_1220 ,
int V_1221 )
{
memset ( V_1220 , 0 , sizeof( * V_1220 ) ) ;
V_1220 -> V_1222 = V_30 -> V_5 [ V_1223 ] ;
if ( V_30 -> V_5 [ V_316 ] ) {
T_3 V_1224 ;
V_1224 = F_76 (
V_30 -> V_5 [ V_316 ] ) ;
V_1220 -> V_1225 = F_246 ( V_1224 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_315 ) &&
V_1224 != V_1226 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1227 ] )
V_1220 -> V_1228 = true ;
} else
V_1220 -> V_1225 = F_246 ( V_1226 ) ;
if ( V_30 -> V_5 [ V_1229 ] ) {
void * V_128 ;
int V_47 , V_143 ;
V_128 = F_23 ( V_30 -> V_5 [ V_1229 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1229 ] ) ;
V_1220 -> V_1230 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1220 -> V_1230 > V_1221 )
return - V_16 ;
memcpy ( V_1220 -> V_1231 , V_128 , V_47 ) ;
for ( V_143 = 0 ; V_143 < V_1220 -> V_1230 ; V_143 ++ )
if ( ! F_247 (
& V_7 -> V_18 ,
V_1220 -> V_1231 [ V_143 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1232 ] ) {
V_1220 -> V_1233 =
F_4 ( V_30 -> V_5 [ V_1232 ] ) ;
if ( ! F_247 ( & V_7 -> V_18 ,
V_1220 -> V_1233 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1234 ] ) {
V_1220 -> V_1208 =
F_4 ( V_30 -> V_5 [ V_1234 ] ) ;
if ( ! F_243 ( V_1220 -> V_1208 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1235 ] ) {
void * V_128 ;
int V_47 ;
V_128 = F_23 ( V_30 -> V_5 [ V_1235 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1235 ] ) ;
V_1220 -> V_1236 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1220 -> V_1236 > V_1237 )
return - V_16 ;
memcpy ( V_1220 -> V_1238 , V_128 , V_47 ) ;
}
return 0 ;
}
static int F_248 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1239 V_1240 = {} ;
const T_2 * V_505 , * V_547 ;
int V_35 , V_545 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_506 ] ||
! V_30 -> V_5 [ V_546 ] ||
! V_30 -> V_5 [ V_484 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_360 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_55 = F_79 ( & V_7 -> V_18 ,
F_4 ( V_30 -> V_5 [ V_484 ] ) ) ;
if ( ! V_55 || ( V_55 -> V_51 & V_60 ) )
return - V_16 ;
V_547 = F_23 ( V_30 -> V_5 [ V_546 ] ) ;
V_545 = F_24 ( V_30 -> V_5 [ V_546 ] ) ;
if ( V_30 -> V_5 [ V_630 ] ) {
V_1240 . V_1055 = F_23 ( V_30 -> V_5 [ V_630 ] ) ;
V_1240 . V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
}
if ( V_30 -> V_5 [ V_1241 ] ) {
enum V_1242 V_1243 =
F_4 ( V_30 -> V_5 [ V_1241 ] ) ;
if ( V_1243 == V_1244 )
V_1240 . V_1245 = true ;
else if ( V_1243 != V_1246 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1247 ] )
V_1240 . V_1248 = F_23 ( V_30 -> V_5 [ V_1247 ] ) ;
if ( F_201 ( V_30 -> V_5 [ V_1249 ] ) )
V_1240 . V_51 |= V_1250 ;
if ( V_30 -> V_5 [ V_435 ] )
memcpy ( & V_1240 . V_1251 ,
F_23 ( V_30 -> V_5 [ V_435 ] ) ,
sizeof( V_1240 . V_1251 ) ) ;
if ( V_30 -> V_5 [ V_870 ] ) {
if ( ! V_30 -> V_5 [ V_435 ] )
return - V_16 ;
memcpy ( & V_1240 . V_842 ,
F_23 ( V_30 -> V_5 [ V_870 ] ) ,
sizeof( V_1240 . V_842 ) ) ;
}
if ( F_201 ( V_30 -> V_5 [ V_1252 ] ) )
V_1240 . V_51 |= V_1253 ;
if ( V_30 -> V_5 [ V_444 ] )
memcpy ( & V_1240 . V_1254 ,
F_23 ( V_30 -> V_5 [ V_444 ] ) ,
sizeof( V_1240 . V_1254 ) ) ;
if ( V_30 -> V_5 [ V_871 ] ) {
if ( ! V_30 -> V_5 [ V_444 ] )
return - V_16 ;
memcpy ( & V_1240 . V_843 ,
F_23 ( V_30 -> V_5 [ V_871 ] ) ,
sizeof( V_1240 . V_843 ) ) ;
}
V_35 = F_146 ( V_7 , V_30 , & V_1240 . V_671 , 1 ) ;
if ( ! V_35 ) {
F_110 ( V_183 -> V_28 ) ;
V_35 = F_249 ( V_7 , V_183 , V_55 , V_505 ,
V_547 , V_545 , & V_1240 ) ;
F_112 ( V_183 -> V_28 ) ;
}
return V_35 ;
}
static int F_250 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
const T_2 * V_1055 = NULL , * V_505 ;
int V_1056 = 0 , V_35 ;
T_3 V_1255 ;
bool V_1213 ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1256 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_362 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_1255 = F_76 ( V_30 -> V_5 [ V_1256 ] ) ;
if ( V_1255 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_630 ] ) {
V_1055 = F_23 ( V_30 -> V_5 [ V_630 ] ) ;
V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
}
V_1213 = ! ! V_30 -> V_5 [ V_1218 ] ;
F_110 ( V_183 -> V_28 ) ;
V_35 = F_251 ( V_7 , V_183 , V_505 , V_1055 , V_1056 , V_1255 ,
V_1213 ) ;
F_112 ( V_183 -> V_28 ) ;
return V_35 ;
}
static int F_252 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
const T_2 * V_1055 = NULL , * V_505 ;
int V_1056 = 0 , V_35 ;
T_3 V_1255 ;
bool V_1213 ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1256 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_364 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_1255 = F_76 ( V_30 -> V_5 [ V_1256 ] ) ;
if ( V_1255 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_630 ] ) {
V_1055 = F_23 ( V_30 -> V_5 [ V_630 ] ) ;
V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
}
V_1213 = ! ! V_30 -> V_5 [ V_1218 ] ;
F_110 ( V_183 -> V_28 ) ;
V_35 = F_253 ( V_7 , V_183 , V_505 , V_1055 , V_1056 , V_1255 ,
V_1213 ) ;
F_112 ( V_183 -> V_28 ) ;
return V_35 ;
}
static bool
F_254 ( struct V_6 * V_7 ,
int V_1257 [ V_335 ] ,
int V_1258 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_270 , V_143 ;
for ( V_270 = 0 ; V_270 < V_335 ; V_270 ++ ) {
struct V_219 * V_220 ;
V_220 = V_18 -> V_336 [ V_270 ] ;
if ( ! V_220 )
continue;
for ( V_143 = 0 ; V_143 < V_220 -> V_241 ; V_143 ++ ) {
if ( V_220 -> V_242 [ V_143 ] . V_244 == V_1258 ) {
V_1257 [ V_270 ] = V_143 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_255 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1259 V_1260 ;
struct V_18 * V_18 ;
struct V_120 * V_1261 = NULL ;
int V_35 ;
memset ( & V_1260 , 0 , sizeof( V_1260 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_546 ] ||
! F_24 ( V_30 -> V_5 [ V_546 ] ) )
return - V_16 ;
V_1260 . V_502 = 100 ;
if ( V_30 -> V_5 [ V_658 ] ) {
V_1260 . V_502 =
F_4 ( V_30 -> V_5 [ V_658 ] ) ;
if ( V_1260 . V_502 < 1 || V_1260 . V_502 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_324 -> V_366 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_136 )
return - V_501 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_506 ] ) {
V_1260 . V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( ! F_116 ( V_1260 . V_505 ) )
return - V_16 ;
}
V_1260 . V_547 = F_23 ( V_30 -> V_5 [ V_546 ] ) ;
V_1260 . V_545 = F_24 ( V_30 -> V_5 [ V_546 ] ) ;
if ( V_30 -> V_5 [ V_630 ] ) {
V_1260 . V_1055 = F_23 ( V_30 -> V_5 [ V_630 ] ) ;
V_1260 . V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
}
V_35 = F_78 ( V_7 , V_30 , & V_1260 . V_482 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_84 ( & V_7 -> V_18 , & V_1260 . V_482 ) )
return - V_16 ;
switch ( V_1260 . V_482 . V_485 ) {
case V_499 :
case V_500 :
case V_486 :
break;
case V_536 :
case V_537 :
if ( V_7 -> V_18 . V_271 & V_1262 )
break;
default:
return - V_16 ;
}
V_1260 . V_1263 = ! ! V_30 -> V_5 [ V_1264 ] ;
V_1260 . V_667 = ! ! V_30 -> V_5 [ V_668 ] ;
if ( V_30 -> V_5 [ V_937 ] ) {
T_2 * V_1106 =
F_23 ( V_30 -> V_5 [ V_937 ] ) ;
int V_1265 =
F_24 ( V_30 -> V_5 [ V_937 ] ) ;
struct V_219 * V_220 =
V_18 -> V_336 [ V_1260 . V_482 . V_55 -> V_270 ] ;
V_35 = F_217 ( V_220 , V_1106 , V_1265 ,
& V_1260 . V_938 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_435 ] )
memcpy ( & V_1260 . V_1251 ,
F_23 ( V_30 -> V_5 [ V_435 ] ) ,
sizeof( V_1260 . V_1251 ) ) ;
if ( V_30 -> V_5 [ V_870 ] ) {
if ( ! V_30 -> V_5 [ V_435 ] )
return - V_16 ;
memcpy ( & V_1260 . V_842 ,
F_23 ( V_30 -> V_5 [ V_870 ] ) ,
sizeof( V_1260 . V_842 ) ) ;
}
if ( V_30 -> V_5 [ V_1266 ] &&
! F_254 ( V_7 , V_1260 . V_1257 ,
F_4 ( V_30 -> V_5 [ V_1266 ] ) ) )
return - V_16 ;
if ( V_1260 . V_667 && V_30 -> V_5 [ V_1267 ] ) {
bool V_122 = false ;
V_1261 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1267 ] ,
& V_122 ) ;
if ( F_17 ( V_1261 ) )
return F_18 ( V_1261 ) ;
if ( ( V_1260 . V_482 . V_485 != V_486 ) &&
V_122 ) {
F_41 ( V_1261 ) ;
return - V_16 ;
}
}
V_1260 . V_1222 =
F_201 ( V_30 -> V_5 [ V_1223 ] ) ;
V_1260 . V_1268 =
F_201 ( V_30 -> V_5 [ V_1269 ] ) ;
V_35 = F_256 ( V_7 , V_183 , & V_1260 , V_1261 ) ;
if ( V_35 )
F_41 ( V_1261 ) ;
return V_35 ;
}
static int F_257 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
if ( ! V_7 -> V_324 -> V_1270 )
return - V_501 ;
if ( V_183 -> V_28 -> V_131 != V_136 )
return - V_501 ;
return F_258 ( V_7 , V_183 , false ) ;
}
static int F_259 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
int V_1257 [ V_335 ] ;
V_22 V_1271 ;
int V_35 ;
if ( V_183 -> V_28 -> V_131 != V_136 &&
V_183 -> V_28 -> V_131 != V_135 )
return - V_501 ;
if ( ! V_7 -> V_324 -> V_406 )
return - V_501 ;
memset ( V_1257 , 0 , sizeof( V_1257 ) ) ;
if ( ! V_30 -> V_5 [ V_1266 ] )
return - V_16 ;
V_1271 = F_4 ( V_30 -> V_5 [ V_1266 ] ) ;
if ( ! F_254 ( V_7 , V_1257 , V_1271 ) )
return - V_16 ;
V_35 = V_7 -> V_324 -> V_406 ( & V_7 -> V_18 , V_183 , V_1257 ) ;
return V_35 ;
}
static struct V_31 *
F_260 ( struct V_6 * V_7 ,
int V_1272 , V_22 V_49 , V_22 V_50 ,
enum V_650 V_52 ,
enum V_1273 V_45 ,
const struct V_449 * V_30 ,
T_11 V_1274 )
{
struct V_31 * V_32 ;
void * V_263 ;
struct V_4 * V_128 ;
V_32 = F_72 ( V_1272 + 100 , V_1274 ) ;
if ( ! V_32 )
return NULL ;
V_263 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_263 ) {
F_261 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1275 ,
V_30 -> V_1276 ) )
goto V_59;
if ( F_28 ( V_32 , V_1277 ,
V_30 -> V_1278 ) )
goto V_59;
}
V_128 = F_45 ( V_32 , V_45 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_263 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_128 ;
return V_32 ;
V_59:
F_261 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_262 ( struct V_18 * V_18 ,
enum V_650 V_52 ,
enum V_1273 V_45 ,
int V_1279 ,
int V_1272 , T_11 V_1274 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_449 * V_30 ;
switch ( V_52 ) {
case V_1280 :
if ( F_57 ( V_1279 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1281 :
if ( F_57 ( V_1279 < 0 ||
V_1279 >= V_18 -> V_453 ) )
return NULL ;
V_30 = & V_18 -> V_455 [ V_1279 ] ;
break;
default:
F_57 ( 1 ) ;
return NULL ;
}
return F_260 ( V_7 , V_1272 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1274 ) ;
}
void F_263 ( struct V_31 * V_32 , T_11 V_1274 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_263 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_128 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1282 V_1283 = V_1284 ;
F_46 ( V_32 , V_128 ) ;
F_64 ( V_32 , V_263 ) ;
if ( V_128 -> F_216 == V_451 )
V_1283 = V_1285 ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1283 , V_1274 ) ;
}
static int F_265 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_92 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_324 -> V_417 )
return - V_501 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1286 ] )
return - V_16 ;
V_7 -> V_1287 = V_30 ;
V_35 = F_266 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1286 ] ) ,
F_24 ( V_30 -> V_5 [ V_1286 ] ) ) ;
V_7 -> V_1287 = NULL ;
return V_35 ;
}
static int F_267 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1288 ;
void * V_128 = NULL ;
int V_1289 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1288 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_823;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_823;
}
V_1288 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1286 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1286 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_128 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1289 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1288 ) ;
if ( ! V_7 ) {
V_35 = - V_603 ;
goto V_823;
}
if ( ! V_7 -> V_324 -> V_1290 ) {
V_35 = - V_501 ;
goto V_823;
}
while ( 1 ) {
void * V_263 = F_25 ( V_32 , F_69 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_461 , V_462 ,
V_1280 ) ;
struct V_4 * V_1291 ;
if ( ! V_263 )
break;
if ( F_28 ( V_32 , V_26 , V_1288 ) ) {
F_65 ( V_32 , V_263 ) ;
break;
}
V_1291 = F_45 ( V_32 , V_1286 ) ;
if ( ! V_1291 ) {
F_65 ( V_32 , V_263 ) ;
break;
}
V_35 = F_268 ( V_7 , V_32 , V_34 , V_128 , V_1289 ) ;
F_46 ( V_32 , V_1291 ) ;
if ( V_35 == - V_81 || V_35 == - V_603 ) {
F_65 ( V_32 , V_263 ) ;
break;
} else if ( V_35 ) {
F_65 ( V_32 , V_263 ) ;
goto V_823;
}
F_64 ( V_32 , V_263 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1288 + 1 ;
V_823:
F_20 () ;
return V_35 ;
}
static int F_269 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1292 V_419 ;
struct V_18 * V_18 ;
struct V_120 * V_1261 = NULL ;
int V_35 ;
memset ( & V_419 , 0 , sizeof( V_419 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_546 ] ||
! F_24 ( V_30 -> V_5 [ V_546 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_669 ] ) {
V_419 . V_649 =
F_4 ( V_30 -> V_5 [ V_669 ] ) ;
if ( ! F_143 ( V_7 , V_419 . V_649 ,
V_420 ) )
return - V_16 ;
} else
V_419 . V_649 = V_670 ;
V_419 . V_667 = V_30 -> V_5 [ V_668 ] ;
V_35 = F_146 ( V_7 , V_30 , & V_419 . V_671 ,
V_672 ) ;
if ( V_35 )
return V_35 ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
V_18 = & V_7 -> V_18 ;
V_419 . V_1293 = - 1 ;
if ( V_30 -> V_5 [ V_1294 ] &&
( V_18 -> V_51 & V_303 ) ) {
V_419 . V_1293 =
F_76 ( V_30 -> V_5 [ V_1294 ] ) ;
}
if ( V_30 -> V_5 [ V_506 ] )
V_419 . V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_419 . V_547 = F_23 ( V_30 -> V_5 [ V_546 ] ) ;
V_419 . V_545 = F_24 ( V_30 -> V_5 [ V_546 ] ) ;
if ( V_30 -> V_5 [ V_630 ] ) {
V_419 . V_1055 = F_23 ( V_30 -> V_5 [ V_630 ] ) ;
V_419 . V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
}
if ( V_30 -> V_5 [ V_1241 ] ) {
V_419 . V_1243 = F_4 ( V_30 -> V_5 [ V_1241 ] ) ;
if ( V_419 . V_1243 != V_1244 &&
V_419 . V_1243 != V_1246 )
return - V_16 ;
} else {
V_419 . V_1243 = V_1246 ;
}
if ( V_30 -> V_5 [ V_484 ] ) {
V_419 . V_684 =
F_79 ( V_18 ,
F_4 ( V_30 -> V_5 [ V_484 ] ) ) ;
if ( ! V_419 . V_684 ||
V_419 . V_684 -> V_51 & V_60 )
return - V_16 ;
}
if ( V_419 . V_667 && V_30 -> V_5 [ V_1267 ] ) {
V_1261 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1267 ] , NULL ) ;
if ( F_17 ( V_1261 ) )
return F_18 ( V_1261 ) ;
}
if ( F_201 ( V_30 -> V_5 [ V_1249 ] ) )
V_419 . V_51 |= V_1250 ;
if ( V_30 -> V_5 [ V_435 ] )
memcpy ( & V_419 . V_1251 ,
F_23 ( V_30 -> V_5 [ V_435 ] ) ,
sizeof( V_419 . V_1251 ) ) ;
if ( V_30 -> V_5 [ V_870 ] ) {
if ( ! V_30 -> V_5 [ V_435 ] ) {
F_41 ( V_1261 ) ;
return - V_16 ;
}
memcpy ( & V_419 . V_842 ,
F_23 ( V_30 -> V_5 [ V_870 ] ) ,
sizeof( V_419 . V_842 ) ) ;
}
if ( F_201 ( V_30 -> V_5 [ V_1252 ] ) )
V_419 . V_51 |= V_1253 ;
if ( V_30 -> V_5 [ V_444 ] )
memcpy ( & V_419 . V_1254 ,
F_23 ( V_30 -> V_5 [ V_444 ] ) ,
sizeof( V_419 . V_1254 ) ) ;
if ( V_30 -> V_5 [ V_871 ] ) {
if ( ! V_30 -> V_5 [ V_444 ] ) {
F_41 ( V_1261 ) ;
return - V_16 ;
}
memcpy ( & V_419 . V_843 ,
F_23 ( V_30 -> V_5 [ V_871 ] ) ,
sizeof( V_419 . V_843 ) ) ;
}
F_110 ( V_183 -> V_28 ) ;
V_35 = F_270 ( V_7 , V_183 , & V_419 , V_1261 , NULL ) ;
F_112 ( V_183 -> V_28 ) ;
if ( V_35 )
F_41 ( V_1261 ) ;
return V_35 ;
}
static int F_271 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_3 V_1295 ;
int V_457 ;
if ( ! V_30 -> V_5 [ V_1256 ] )
V_1295 = V_1296 ;
else
V_1295 = F_76 ( V_30 -> V_5 [ V_1256 ] ) ;
if ( V_1295 == 0 )
return - V_16 ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
F_110 ( V_183 -> V_28 ) ;
V_457 = F_272 ( V_7 , V_183 , V_1295 , true ) ;
F_112 ( V_183 -> V_28 ) ;
return V_457 ;
}
static int F_273 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
V_22 V_1297 ;
if ( ! V_30 -> V_5 [ V_1298 ] )
return - V_16 ;
V_1297 = F_4 ( V_30 -> V_5 [ V_1298 ] ) ;
V_2 = F_274 ( V_1297 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_68 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_275 ( V_7 , V_2 ) ;
F_276 ( V_2 ) ;
return V_35 ;
}
static int F_277 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
int (* F_278)( struct V_18 * V_18 , struct V_25 * V_183 ,
struct V_1299 * V_1300 ) = NULL ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1299 V_1300 ;
memset ( & V_1300 , 0 , sizeof( struct V_1299 ) ) ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1301 ] )
return - V_16 ;
V_1300 . V_1302 = F_23 ( V_30 -> V_5 [ V_1301 ] ) ;
V_1300 . V_505 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
switch ( V_30 -> V_1303 -> V_52 ) {
case V_1304 :
F_278 = V_7 -> V_324 -> V_370 ;
break;
case V_1305 :
F_278 = V_7 -> V_324 -> V_372 ;
break;
default:
F_57 ( 1 ) ;
break;
}
if ( ! F_278 )
return - V_501 ;
return F_278 ( & V_7 -> V_18 , V_183 , & V_1300 ) ;
}
static int F_279 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
if ( V_183 -> V_28 -> V_131 != V_137 &&
V_183 -> V_28 -> V_131 != V_138 )
return - V_501 ;
if ( ! V_7 -> V_324 -> V_374 )
return - V_501 ;
return F_280 ( V_7 , V_183 ) ;
}
static int F_281 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 V_1306 , V_1307 ;
T_3 V_1308 ;
T_2 * V_1309 ;
if ( ! ( V_7 -> V_18 . V_51 & V_305 ) ||
! V_7 -> V_324 -> V_391 )
return - V_501 ;
if ( ! V_30 -> V_5 [ V_1310 ] ||
! V_30 -> V_5 [ V_1311 ] ||
! V_30 -> V_5 [ V_1312 ] ||
! V_30 -> V_5 [ V_630 ] ||
! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
V_1309 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_1306 = F_34 ( V_30 -> V_5 [ V_1310 ] ) ;
V_1308 = F_76 ( V_30 -> V_5 [ V_1311 ] ) ;
V_1307 = F_34 ( V_30 -> V_5 [ V_1312 ] ) ;
return F_282 ( V_7 , V_183 , V_1309 , V_1306 ,
V_1307 , V_1308 ,
F_23 ( V_30 -> V_5 [ V_630 ] ) ,
F_24 ( V_30 -> V_5 [ V_630 ] ) ) ;
}
static int F_283 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
enum V_1313 V_1314 ;
T_2 * V_1309 ;
if ( ! ( V_7 -> V_18 . V_51 & V_305 ) ||
! V_7 -> V_324 -> V_393 )
return - V_501 ;
if ( ! V_30 -> V_5 [ V_1315 ] ||
! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
V_1314 = F_34 ( V_30 -> V_5 [ V_1315 ] ) ;
V_1309 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
return F_284 ( V_7 , V_183 , V_1309 , V_1314 ) ;
}
static int F_285 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
struct V_481 V_482 ;
struct V_31 * V_53 ;
void * V_263 ;
T_1 V_594 ;
V_22 V_1316 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_484 ] ||
! V_30 -> V_5 [ V_1317 ] )
return - V_16 ;
V_1316 = F_4 ( V_30 -> V_5 [ V_1317 ] ) ;
if ( ! V_7 -> V_324 -> V_377 ||
! ( V_7 -> V_18 . V_51 & V_376 ) )
return - V_501 ;
if ( V_1316 < V_1318 ||
V_1316 > V_7 -> V_18 . V_424 )
return - V_16 ;
V_35 = F_78 ( V_7 , V_30 , & V_482 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1319 ) ;
if ( ! V_263 ) {
V_35 = - V_81 ;
goto V_604;
}
V_35 = F_286 ( V_7 , V_17 , V_482 . V_55 ,
V_1316 , & V_594 ) ;
if ( V_35 )
goto V_604;
if ( F_102 ( V_53 , V_1320 , V_594 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_81 ;
V_604:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_287 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
T_1 V_594 ;
if ( ! V_30 -> V_5 [ V_1320 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_1321 )
return - V_501 ;
V_594 = F_5 ( V_30 -> V_5 [ V_1320 ] ) ;
return F_288 ( V_7 , V_17 , V_594 ) ;
}
static V_22 F_289 ( struct V_219 * V_220 ,
T_2 * V_1106 , T_2 V_1322 )
{
T_2 V_143 ;
V_22 V_692 = 0 ;
for ( V_143 = 0 ; V_143 < V_1322 ; V_143 ++ ) {
int V_224 = ( V_1106 [ V_143 ] & 0x7f ) * 5 ;
int V_1323 ;
for ( V_1323 = 0 ; V_1323 < V_220 -> V_241 ; V_1323 ++ ) {
struct V_223 * V_1324 =
& V_220 -> V_242 [ V_1323 ] ;
if ( V_224 == V_1324 -> V_244 ) {
V_692 |= 1 << V_1323 ;
break;
}
}
if ( V_1323 == V_220 -> V_241 )
return 0 ;
}
return V_692 ;
}
static bool F_290 ( struct V_219 * V_220 ,
T_2 * V_1106 , T_2 V_1322 ,
T_2 V_228 [ V_1325 ] )
{
T_2 V_143 ;
memset ( V_228 , 0 , V_1325 ) ;
for ( V_143 = 0 ; V_143 < V_1322 ; V_143 ++ ) {
int V_1323 , V_1326 ;
V_1323 = V_1106 [ V_143 ] / 8 ;
V_1326 = F_148 ( V_1106 [ V_143 ] % 8 ) ;
if ( ( V_1323 < 0 ) || ( V_1323 >= V_1325 ) )
return false ;
if ( V_220 -> V_225 . V_228 . V_1327 [ V_1323 ] & V_1326 )
V_228 [ V_1323 ] |= V_1326 ;
else
return false ;
}
return true ;
}
static T_3 F_291 ( T_2 V_1328 )
{
T_3 V_1329 = 0 ;
switch ( V_1328 ) {
case V_1330 :
break;
case V_1331 :
V_1329 = 0x00FF ;
break;
case V_1332 :
V_1329 = 0x01FF ;
break;
case V_1333 :
V_1329 = 0x03FF ;
break;
default:
break;
}
return V_1329 ;
}
static void F_292 ( T_3 V_1328 ,
T_3 V_1334 [ V_1335 ] )
{
T_2 V_718 ;
for ( V_718 = 0 ; V_718 < V_1335 ; V_718 ++ ) {
V_1334 [ V_718 ] = F_291 ( V_1328 & 0x03 ) ;
V_1328 >>= 2 ;
}
}
static bool F_293 ( struct V_219 * V_220 ,
struct V_1336 * V_775 ,
T_3 V_228 [ V_1335 ] )
{
T_3 V_1337 = F_294 ( V_220 -> V_235 . V_238 . V_1337 ) ;
T_3 V_1338 [ V_1335 ] = {} ;
T_2 V_143 ;
if ( ! V_220 -> V_235 . V_236 )
return false ;
memset ( V_228 , 0 , sizeof( T_3 ) * V_1335 ) ;
F_292 ( V_1337 , V_1338 ) ;
for ( V_143 = 0 ; V_143 < V_1335 ; V_143 ++ ) {
if ( ( V_1338 [ V_143 ] & V_775 -> V_228 [ V_143 ] ) == V_775 -> V_228 [ V_143 ] )
V_228 [ V_143 ] = V_775 -> V_228 [ V_143 ] ;
else
return false ;
}
return true ;
}
static int F_295 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_85 [ V_1339 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1340 V_692 ;
int V_124 , V_143 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_4 * V_1341 ;
struct V_219 * V_220 ;
T_3 V_1342 ;
if ( ! V_7 -> V_324 -> V_379 )
return - V_501 ;
memset ( & V_692 , 0 , sizeof( V_692 ) ) ;
for ( V_143 = 0 ; V_143 < V_335 ; V_143 ++ ) {
V_220 = V_7 -> V_18 . V_336 [ V_143 ] ;
if ( ! V_220 )
continue;
V_692 . V_1343 [ V_143 ] . V_1344 = ( 1 << V_220 -> V_241 ) - 1 ;
memcpy ( V_692 . V_1343 [ V_143 ] . V_1345 ,
V_220 -> V_225 . V_228 . V_1327 ,
sizeof( V_692 . V_1343 [ V_143 ] . V_1345 ) ) ;
if ( ! V_220 -> V_235 . V_236 )
continue;
V_1342 = F_294 ( V_220 -> V_235 . V_238 . V_1337 ) ;
F_292 ( V_1342 , V_692 . V_1343 [ V_143 ] . V_238 ) ;
}
if ( ! V_30 -> V_5 [ V_1346 ] )
goto V_552;
F_111 ( V_1347 > V_1325 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_269 V_270 = F_216 ( V_1341 ) ;
if ( V_270 < 0 || V_270 >= V_335 )
return - V_16 ;
V_220 = V_7 -> V_18 . V_336 [ V_270 ] ;
if ( V_220 == NULL )
return - V_16 ;
F_94 ( V_85 , V_1339 , F_23 ( V_1341 ) ,
F_24 ( V_1341 ) , V_1348 ) ;
if ( V_85 [ V_1349 ] ) {
V_692 . V_1343 [ V_270 ] . V_1344 = F_289 (
V_220 ,
F_23 ( V_85 [ V_1349 ] ) ,
F_24 ( V_85 [ V_1349 ] ) ) ;
if ( ( V_692 . V_1343 [ V_270 ] . V_1344 == 0 ) &&
F_24 ( V_85 [ V_1349 ] ) )
return - V_16 ;
}
if ( V_85 [ V_1350 ] ) {
if ( ! F_290 (
V_220 ,
F_23 ( V_85 [ V_1350 ] ) ,
F_24 ( V_85 [ V_1350 ] ) ,
V_692 . V_1343 [ V_270 ] . V_1345 ) )
return - V_16 ;
}
if ( V_85 [ V_1351 ] ) {
if ( ! F_293 (
V_220 ,
F_23 ( V_85 [ V_1351 ] ) ,
V_692 . V_1343 [ V_270 ] . V_238 ) )
return - V_16 ;
}
if ( V_692 . V_1343 [ V_270 ] . V_1344 == 0 ) {
if ( ! ( V_7 -> V_18 . V_336 [ V_270 ] -> V_225 . V_226 ||
V_7 -> V_18 . V_336 [ V_270 ] -> V_235 . V_236 ) )
return - V_16 ;
for ( V_143 = 0 ; V_143 < V_1325 ; V_143 ++ )
if ( V_692 . V_1343 [ V_270 ] . V_1345 [ V_143 ] )
goto V_552;
for ( V_143 = 0 ; V_143 < V_1335 ; V_143 ++ )
if ( V_692 . V_1343 [ V_270 ] . V_238 [ V_143 ] )
goto V_552;
return - V_16 ;
}
}
V_552:
return F_296 ( V_7 , V_183 , NULL , & V_692 ) ;
}
static int F_297 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
T_3 V_1352 = V_258 | V_1353 ;
if ( ! V_30 -> V_5 [ V_1354 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_257 ] )
V_1352 = F_76 ( V_30 -> V_5 [ V_257 ] ) ;
switch ( V_17 -> V_131 ) {
case V_137 :
case V_136 :
case V_138 :
case V_132 :
case V_133 :
case V_135 :
case V_134 :
case V_579 :
break;
default:
return - V_501 ;
}
if ( ! V_7 -> V_324 -> V_381 )
return - V_501 ;
return F_298 ( V_17 , V_30 -> V_465 , V_1352 ,
F_23 ( V_30 -> V_5 [ V_1354 ] ) ,
F_24 ( V_30 -> V_5 [ V_1354 ] ) ) ;
}
static int F_299 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
struct V_481 V_482 ;
int V_35 ;
void * V_263 = NULL ;
T_1 V_594 ;
struct V_31 * V_53 = NULL ;
struct V_1355 V_127 = {
. V_1356 =
V_30 -> V_5 [ V_1357 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1358 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_381 )
return - V_501 ;
switch ( V_17 -> V_131 ) {
case V_579 :
if ( ! V_30 -> V_5 [ V_484 ] )
return - V_16 ;
case V_137 :
case V_136 :
case V_138 :
case V_132 :
case V_133 :
case V_135 :
case V_134 :
break;
default:
return - V_501 ;
}
if ( V_30 -> V_5 [ V_1317 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_425 ) )
return - V_16 ;
V_127 . V_1359 = F_4 ( V_30 -> V_5 [ V_1317 ] ) ;
if ( V_127 . V_1359 < V_1318 ||
V_127 . V_1359 > V_7 -> V_18 . V_424 )
return - V_16 ;
}
V_127 . V_1360 = V_30 -> V_5 [ V_426 ] ;
if ( V_127 . V_1360 && ! ( V_7 -> V_18 . V_51 & V_425 ) )
return - V_16 ;
V_127 . V_1111 = F_201 ( V_30 -> V_5 [ V_1112 ] ) ;
V_482 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_484 ] ) {
V_35 = F_78 ( V_7 , V_30 , & V_482 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_482 . V_55 && V_127 . V_1360 )
return - V_16 ;
if ( ! V_127 . V_1356 ) {
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1361 ) ;
if ( ! V_263 ) {
V_35 = - V_81 ;
goto V_604;
}
}
V_127 . V_1362 = F_23 ( V_30 -> V_5 [ V_1358 ] ) ;
V_127 . V_47 = F_24 ( V_30 -> V_5 [ V_1358 ] ) ;
V_127 . V_55 = V_482 . V_55 ;
V_35 = F_300 ( V_7 , V_17 , & V_127 , & V_594 ) ;
if ( V_35 )
goto V_604;
if ( V_53 ) {
if ( F_102 ( V_53 , V_1320 , V_594 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
}
return 0 ;
V_59:
V_35 = - V_81 ;
V_604:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_301 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
T_1 V_594 ;
if ( ! V_30 -> V_5 [ V_1320 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_383 )
return - V_501 ;
switch ( V_17 -> V_131 ) {
case V_137 :
case V_136 :
case V_138 :
case V_132 :
case V_133 :
case V_134 :
case V_579 :
break;
default:
return - V_501 ;
}
V_594 = F_5 ( V_30 -> V_5 [ V_1320 ] ) ;
return F_302 ( V_7 , V_17 , V_594 ) ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 V_1363 ;
bool V_262 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1364 ] )
return - V_16 ;
V_1363 = F_4 ( V_30 -> V_5 [ V_1364 ] ) ;
if ( V_1363 != V_1365 && V_1363 != V_1366 )
return - V_16 ;
V_17 = V_183 -> V_28 ;
if ( ! V_7 -> V_324 -> V_1367 )
return - V_501 ;
V_262 = ( V_1363 == V_1366 ) ? true : false ;
if ( V_262 == V_17 -> V_1368 )
return 0 ;
V_35 = F_304 ( V_7 , V_183 , V_262 , V_17 -> V_1369 ) ;
if ( ! V_35 )
V_17 -> V_1368 = V_262 ;
return V_35 ;
}
static int F_305 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
enum V_1370 V_1363 ;
struct V_1 * V_17 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_31 * V_53 ;
void * V_263 ;
int V_35 ;
V_17 = V_183 -> V_28 ;
if ( ! V_7 -> V_324 -> V_1367 )
return - V_501 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1371 ) ;
if ( ! V_263 ) {
V_35 = - V_81 ;
goto V_604;
}
if ( V_17 -> V_1368 )
V_1363 = V_1366 ;
else
V_1363 = V_1365 ;
if ( F_28 ( V_53 , V_1364 , V_1363 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_81 ;
V_604:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_306 ( struct V_29 * V_30 ,
V_22 V_224 , V_22 V_1372 , V_22 V_1373 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
if ( V_224 > 100 || V_1373 > V_1374 )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_1375 )
return - V_501 ;
if ( V_17 -> V_131 != V_137 &&
V_17 -> V_131 != V_138 )
return - V_501 ;
return F_307 ( V_7 , V_183 , V_224 , V_1372 , V_1373 ) ;
}
static int F_308 ( struct V_29 * V_30 ,
T_12 V_1376 , V_22 V_1377 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
if ( V_1376 > 0 )
return - V_16 ;
if ( V_1376 == 0 )
V_1377 = 0 ;
if ( ! V_7 -> V_324 -> V_1378 )
return - V_501 ;
if ( V_17 -> V_131 != V_137 &&
V_17 -> V_131 != V_138 )
return - V_501 ;
return F_309 ( V_7 , V_183 , V_1376 , V_1377 ) ;
}
static int F_310 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1379 + 1 ] ;
struct V_4 * V_1380 ;
int V_35 ;
V_1380 = V_30 -> V_5 [ V_1381 ] ;
if ( ! V_1380 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1379 , V_1380 ,
V_1382 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1383 ] &&
V_5 [ V_1384 ] ) {
T_12 V_1376 = V_1034 ( V_5 [ V_1383 ] ) ;
V_22 V_1377 = F_4 ( V_5 [ V_1384 ] ) ;
return F_308 ( V_30 , V_1376 , V_1377 ) ;
}
if ( V_5 [ V_1385 ] &&
V_5 [ V_1386 ] &&
V_5 [ V_1387 ] ) {
V_22 V_224 = F_4 ( V_5 [ V_1385 ] ) ;
V_22 V_1372 = F_4 ( V_5 [ V_1386 ] ) ;
V_22 V_1373 = F_4 ( V_5 [ V_1387 ] ) ;
return F_306 ( V_30 , V_224 , V_1372 , V_1373 ) ;
}
return - V_16 ;
}
static int F_311 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_968 V_1030 ;
struct V_1036 V_1037 ;
int V_35 ;
memcpy ( & V_1030 , & V_972 , sizeof( V_1030 ) ) ;
memcpy ( & V_1037 , & V_1388 , sizeof( V_1037 ) ) ;
if ( V_30 -> V_5 [ V_974 ] ) {
V_35 = F_198 ( V_30 , & V_1030 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_570 ] ||
! F_24 ( V_30 -> V_5 [ V_570 ] ) )
return - V_16 ;
V_1037 . V_1389 = F_23 ( V_30 -> V_5 [ V_570 ] ) ;
V_1037 . V_971 = F_24 ( V_30 -> V_5 [ V_570 ] ) ;
if ( V_30 -> V_5 [ V_1266 ] &&
! F_254 ( V_7 , V_1037 . V_1257 ,
F_4 ( V_30 -> V_5 [ V_1266 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_658 ] ) {
V_1037 . V_502 =
F_4 ( V_30 -> V_5 [ V_658 ] ) ;
if ( V_1037 . V_502 < 10 ||
V_1037 . V_502 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_659 ] ) {
V_1037 . V_661 =
F_4 ( V_30 -> V_5 [ V_659 ] ) ;
if ( V_1037 . V_661 < 1 || V_1037 . V_661 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1039 ] ) {
V_35 = F_200 ( V_30 , & V_1037 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1037 . V_1059 )
V_1030 . V_990 = false ;
if ( V_30 -> V_5 [ V_484 ] ) {
V_35 = F_78 ( V_7 , V_30 , & V_1037 . V_482 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1037 . V_482 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_937 ] ) {
T_2 * V_1106 = F_23 ( V_30 -> V_5 [ V_937 ] ) ;
int V_1265 =
F_24 ( V_30 -> V_5 [ V_937 ] ) ;
struct V_219 * V_220 ;
if ( ! V_1037 . V_482 . V_55 )
return - V_16 ;
V_220 = V_7 -> V_18 . V_336 [ V_1037 . V_482 . V_55 -> V_270 ] ;
V_35 = F_217 ( V_220 , V_1106 , V_1265 ,
& V_1037 . V_938 ) ;
if ( V_35 )
return V_35 ;
}
return F_312 ( V_7 , V_183 , & V_1037 , & V_1030 ) ;
}
static int F_313 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
return F_314 ( V_7 , V_183 ) ;
}
static int F_315 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1390 * V_171 = V_7 -> V_18 . V_1391 ;
struct V_4 * V_1392 , * V_1393 ;
int V_143 , V_1394 ;
if ( ! V_171 -> V_202 )
return 0 ;
V_1392 = F_45 ( V_53 , V_211 ) ;
if ( ! V_1392 )
return - V_81 ;
for ( V_143 = 0 ; V_143 < V_171 -> V_202 ; V_143 ++ ) {
V_1393 = F_45 ( V_53 , V_143 + 1 ) ;
if ( ! V_1393 )
return - V_81 ;
V_1394 = V_171 -> V_1395 [ V_143 ] . V_1396 ;
if ( F_49 ( V_53 , V_1397 , F_316 ( V_1394 , 8 ) ,
V_171 -> V_1395 [ V_143 ] . V_692 ) ||
F_49 ( V_53 , V_1398 , V_1394 ,
V_171 -> V_1395 [ V_143 ] . V_1399 ) ||
F_28 ( V_53 , V_1400 ,
V_171 -> V_1395 [ V_143 ] . V_1401 ) )
return - V_81 ;
F_46 ( V_53 , V_1393 ) ;
}
F_46 ( V_53 , V_1392 ) ;
return 0 ;
}
static int F_317 ( struct V_31 * V_53 ,
struct V_1402 * V_170 )
{
struct V_4 * V_172 ;
if ( ! V_170 )
return 0 ;
V_172 = F_45 ( V_53 , V_173 ) ;
if ( ! V_172 )
return - V_81 ;
if ( F_318 ( V_53 , V_1403 , V_170 -> V_1404 ) ||
F_318 ( V_53 , V_1405 , V_170 -> V_896 ) ||
F_49 ( V_53 , V_1406 , V_542 , V_170 -> V_1407 ) ||
F_53 ( V_53 , V_1408 , V_170 -> V_1409 ) ||
F_53 ( V_53 , V_1410 , V_170 -> V_1411 ) ||
F_49 ( V_53 , V_174 ,
V_170 -> V_1412 , V_170 -> V_1413 ) ||
F_28 ( V_53 , V_179 ,
V_170 -> V_1414 ) ||
F_49 ( V_53 , V_181 ,
V_170 -> V_1415 , V_170 -> V_1416 ) ||
F_49 ( V_53 , V_1417 ,
F_316 ( V_170 -> V_1415 , 8 ) , V_170 -> V_1418 ) )
return - V_81 ;
if ( V_170 -> V_1419 . V_47 &&
F_49 ( V_53 , V_176 ,
sizeof( V_170 -> V_1419 ) , & V_170 -> V_1419 ) )
return - V_81 ;
if ( V_170 -> V_1420 . V_47 &&
F_49 ( V_53 , V_178 ,
sizeof( V_170 -> V_1420 ) + V_170 -> V_1421 ,
& V_170 -> V_1420 ) )
return - V_81 ;
F_46 ( V_53 , V_172 ) ;
return 0 ;
}
static int F_319 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_31 * V_53 ;
void * V_263 ;
V_22 V_1422 = V_553 ;
if ( ! V_7 -> V_18 . V_171 )
return - V_501 ;
if ( V_7 -> V_18 . V_1391 && V_7 -> V_18 . V_1391 -> V_170 ) {
V_1422 += V_7 -> V_18 . V_1391 -> V_170 -> V_1421 +
V_7 -> V_18 . V_1391 -> V_170 -> V_1412 +
V_7 -> V_18 . V_1391 -> V_170 -> V_1415 +
V_7 -> V_18 . V_1391 -> V_170 -> V_1415 / 8 ;
}
V_53 = F_72 ( V_1422 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1423 ) ;
if ( ! V_263 )
goto V_59;
if ( V_7 -> V_18 . V_1391 ) {
struct V_4 * V_184 ;
V_184 = F_45 ( V_53 , V_1424 ) ;
if ( ! V_184 )
goto V_59;
if ( ( V_7 -> V_18 . V_1391 -> V_1425 &&
F_29 ( V_53 , V_187 ) ) ||
( V_7 -> V_18 . V_1391 -> V_421 &&
F_29 ( V_53 , V_189 ) ) ||
( V_7 -> V_18 . V_1391 -> V_1426 &&
F_29 ( V_53 , V_191 ) ) ||
( V_7 -> V_18 . V_1391 -> V_1427 &&
F_29 ( V_53 , V_195 ) ) ||
( V_7 -> V_18 . V_1391 -> V_1428 &&
F_29 ( V_53 , V_197 ) ) ||
( V_7 -> V_18 . V_1391 -> V_1429 &&
F_29 ( V_53 , V_199 ) ) ||
( V_7 -> V_18 . V_1391 -> V_1430 &&
F_29 ( V_53 , V_201 ) ) )
goto V_59;
if ( F_315 ( V_53 , V_7 ) )
goto V_59;
if ( F_317 ( V_53 ,
V_7 -> V_18 . V_1391 -> V_170 ) )
goto V_59;
F_46 ( V_53 , V_184 ) ;
}
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
F_73 ( V_53 ) ;
return - V_81 ;
}
static int F_320 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1390 * V_1431 )
{
struct V_4 * V_85 [ V_1432 ] ;
struct V_1402 * V_1030 ;
struct V_1433 * V_177 = NULL ;
struct V_1434 * V_50 = NULL ;
V_22 V_1422 ;
V_22 V_1435 , V_1436 , V_1421 = 0 , V_1437 ;
int V_35 , V_1438 ;
if ( ! V_7 -> V_18 . V_171 -> V_170 )
return - V_16 ;
V_35 = F_94 ( V_85 , V_1439 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1440 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_85 [ V_1403 ] ||
! V_85 [ V_1405 ] ||
! V_85 [ V_1406 ] ||
! V_85 [ V_1410 ] ||
! V_85 [ V_174 ] ||
! V_85 [ V_179 ] ||
! V_85 [ V_181 ] ||
! V_85 [ V_1417 ] )
return - V_16 ;
V_1435 = F_24 ( V_85 [ V_174 ] ) ;
if ( V_1435 > V_7 -> V_18 . V_171 -> V_170 -> V_175 )
return - V_16 ;
if ( F_4 ( V_85 [ V_179 ] ) >
V_7 -> V_18 . V_171 -> V_170 -> V_180 ||
F_4 ( V_85 [ V_179 ] ) == 0 )
return - V_16 ;
V_1436 = F_24 ( V_85 [ V_181 ] ) ;
if ( V_1436 > V_7 -> V_18 . V_171 -> V_170 -> V_182 )
return - V_16 ;
V_1437 = F_24 ( V_85 [ V_1417 ] ) ;
if ( V_1437 != F_316 ( V_1436 , 8 ) )
return - V_16 ;
if ( V_85 [ V_178 ] ) {
V_22 V_1441 = F_24 ( V_85 [ V_178 ] ) ;
V_177 = F_23 ( V_85 [ V_178 ] ) ;
V_1421 = V_1441 - sizeof( * V_177 ) ;
if ( ! V_177 -> V_47 || V_1421 % V_177 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_171 -> V_170 -> V_177 )
return - V_16 ;
if ( V_177 -> V_47 > V_7 -> V_18 . V_171 -> V_170 -> V_177 -> V_1442 )
return - V_16 ;
if ( V_177 -> V_47 < V_7 -> V_18 . V_171 -> V_170 -> V_177 -> V_1443 )
return - V_16 ;
if ( V_1421 > V_7 -> V_18 . V_171 -> V_170 -> V_177 -> V_1444 )
return - V_16 ;
if ( V_177 -> V_1445 + V_177 -> V_47 > V_1435 )
return - V_16 ;
}
if ( V_85 [ V_176 ] ) {
V_50 = F_23 ( V_85 [ V_176 ] ) ;
if ( ! V_7 -> V_18 . V_171 -> V_170 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1445 > V_1435 )
return - V_16 ;
}
V_1422 = sizeof( * V_1030 ) ;
V_1422 += V_1435 ;
V_1422 += V_1436 + V_1437 ;
V_1422 += V_1421 ;
V_1030 = F_38 ( V_1422 , V_125 ) ;
if ( ! V_1030 )
return - V_126 ;
V_1030 -> V_1404 = F_321 ( V_85 [ V_1403 ] ) ;
V_1030 -> V_896 = F_321 ( V_85 [ V_1405 ] ) ;
memcpy ( V_1030 -> V_1407 , F_23 ( V_85 [ V_1406 ] ) ,
V_542 ) ;
if ( V_85 [ V_1408 ] )
V_1438 = F_76 ( V_85 [ V_1408 ] ) ;
else
V_1438 = 0 ;
#ifdef F_322
V_35 = F_323 ( F_7 ( & V_7 -> V_18 ) , V_1446 , V_1447 ,
V_1448 , & V_1030 -> V_1449 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1030 ) ;
return V_35 ;
}
if ( F_324 ( V_1030 -> V_1449 -> V_44 , V_1438 ) ) {
F_325 ( V_1030 -> V_1449 ) ;
F_41 ( V_1030 ) ;
return - V_1450 ;
}
V_1030 -> V_1409 = F_326 ( V_1030 -> V_1449 -> V_44 ) -> V_1451 ;
#else
if ( ! V_1438 ) {
F_41 ( V_1030 ) ;
return - V_16 ;
}
V_1030 -> V_1409 = V_1438 ;
#endif
V_1030 -> V_1411 = F_76 ( V_85 [ V_1410 ] ) ;
V_1030 -> V_1412 = V_1435 ;
V_1030 -> V_1413 = ( T_2 * ) V_1030 + sizeof( * V_1030 ) + V_1421 ;
memcpy ( ( void * ) V_1030 -> V_1413 ,
F_23 ( V_85 [ V_174 ] ) ,
V_1435 ) ;
if ( V_50 )
V_1030 -> V_1419 = * V_50 ;
V_1030 -> V_1414 = F_4 ( V_85 [ V_179 ] ) ;
V_1030 -> V_1415 = V_1436 ;
V_1030 -> V_1416 = ( T_2 * ) V_1030 + sizeof( * V_1030 ) + V_1421 + V_1435 ;
memcpy ( ( void * ) V_1030 -> V_1416 ,
F_23 ( V_85 [ V_181 ] ) ,
V_1436 ) ;
V_1030 -> V_1418 = ( T_2 * ) V_1030 + sizeof( * V_1030 ) + V_1421 +
V_1435 + V_1436 ;
memcpy ( ( void * ) V_1030 -> V_1418 ,
F_23 ( V_85 [ V_1417 ] ) ,
V_1437 ) ;
if ( V_177 ) {
V_1030 -> V_1421 = V_1421 ;
memcpy ( & V_1030 -> V_1420 , V_177 , sizeof( * V_177 ) + V_1421 ) ;
}
V_1431 -> V_170 = V_1030 ;
return 0 ;
}
static int F_327 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_4 * V_85 [ V_1452 ] ;
struct V_1390 V_1453 = {} ;
struct V_1390 * V_1454 ;
const struct V_1455 * V_171 = V_7 -> V_18 . V_171 ;
int V_35 , V_143 ;
bool V_1456 = V_7 -> V_18 . V_1391 ;
if ( ! V_171 )
return - V_501 ;
if ( ! V_30 -> V_5 [ V_1424 ] ) {
F_328 ( V_7 ) ;
V_7 -> V_18 . V_1391 = NULL ;
goto V_1457;
}
V_35 = F_94 ( V_85 , V_1458 ,
F_23 ( V_30 -> V_5 [ V_1424 ] ) ,
F_24 ( V_30 -> V_5 [ V_1424 ] ) ,
V_1459 ) ;
if ( V_35 )
return V_35 ;
if ( V_85 [ V_187 ] ) {
if ( ! ( V_171 -> V_51 & V_186 ) )
return - V_16 ;
V_1453 . V_1425 = true ;
}
if ( V_85 [ V_189 ] ) {
if ( ! ( V_171 -> V_51 & V_188 ) )
return - V_16 ;
V_1453 . V_421 = true ;
}
if ( V_85 [ V_191 ] ) {
if ( ! ( V_171 -> V_51 & V_190 ) )
return - V_16 ;
V_1453 . V_1426 = true ;
}
if ( V_85 [ V_193 ] )
return - V_16 ;
if ( V_85 [ V_195 ] ) {
if ( ! ( V_171 -> V_51 & V_194 ) )
return - V_16 ;
V_1453 . V_1427 = true ;
}
if ( V_85 [ V_197 ] ) {
if ( ! ( V_171 -> V_51 & V_196 ) )
return - V_16 ;
V_1453 . V_1428 = true ;
}
if ( V_85 [ V_199 ] ) {
if ( ! ( V_171 -> V_51 & V_198 ) )
return - V_16 ;
V_1453 . V_1429 = true ;
}
if ( V_85 [ V_201 ] ) {
if ( ! ( V_171 -> V_51 & V_200 ) )
return - V_16 ;
V_1453 . V_1430 = true ;
}
if ( V_85 [ V_211 ] ) {
struct V_4 * V_204 ;
int V_202 = 0 ;
int V_124 , V_1394 , V_1460 , V_1401 ;
struct V_4 * V_1461 [ V_1462 ] ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_202 ++ ;
if ( V_202 > V_171 -> V_202 )
return - V_16 ;
V_1453 . V_1395 = F_329 ( V_202 ,
sizeof( V_1453 . V_1395 [ 0 ] ) ,
V_125 ) ;
if ( ! V_1453 . V_1395 )
return - V_126 ;
V_1453 . V_202 = V_202 ;
V_143 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_94 ( V_1461 , V_1463 , F_23 ( V_204 ) ,
F_24 ( V_204 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1461 [ V_1397 ] ||
! V_1461 [ V_1398 ] )
goto error;
V_1394 = F_24 ( V_1461 [ V_1398 ] ) ;
V_1460 = F_316 ( V_1394 , 8 ) ;
if ( F_24 ( V_1461 [ V_1397 ] ) != V_1460 )
goto error;
if ( V_1394 > V_171 -> V_209 ||
V_1394 < V_171 -> V_207 )
goto error;
if ( ! V_1461 [ V_1400 ] )
V_1401 = 0 ;
else
V_1401 = F_4 (
V_1461 [ V_1400 ] ) ;
if ( V_1401 > V_171 -> V_210 )
goto error;
V_1453 . V_1395 [ V_143 ] . V_1401 = V_1401 ;
V_1453 . V_1395 [ V_143 ] . V_692 =
F_330 ( V_1460 + V_1394 , V_125 ) ;
if ( ! V_1453 . V_1395 [ V_143 ] . V_692 ) {
V_35 = - V_126 ;
goto error;
}
V_1453 . V_1395 [ V_143 ] . V_1399 =
V_1453 . V_1395 [ V_143 ] . V_692 + V_1460 ;
memcpy ( V_1453 . V_1395 [ V_143 ] . V_692 ,
F_23 ( V_1461 [ V_1397 ] ) ,
V_1460 ) ;
V_1453 . V_1395 [ V_143 ] . V_1396 = V_1394 ;
memcpy ( V_1453 . V_1395 [ V_143 ] . V_1399 ,
F_23 ( V_1461 [ V_1398 ] ) ,
V_1394 ) ;
V_143 ++ ;
}
}
if ( V_85 [ V_173 ] ) {
V_35 = F_320 (
V_7 , V_85 [ V_173 ] ,
& V_1453 ) ;
if ( V_35 )
goto error;
}
V_1454 = F_331 ( & V_1453 , sizeof( V_1453 ) , V_125 ) ;
if ( ! V_1454 ) {
V_35 = - V_126 ;
goto error;
}
F_328 ( V_7 ) ;
V_7 -> V_18 . V_1391 = V_1454 ;
V_1457:
if ( V_7 -> V_324 -> V_1457 &&
V_1456 != ! ! V_7 -> V_18 . V_1391 )
F_332 ( V_7 , V_7 -> V_18 . V_1391 ) ;
return 0 ;
error:
for ( V_143 = 0 ; V_143 < V_1453 . V_202 ; V_143 ++ )
F_41 ( V_1453 . V_1395 [ V_143 ] . V_692 ) ;
F_41 ( V_1453 . V_1395 ) ;
if ( V_1453 . V_170 && V_1453 . V_170 -> V_1449 )
F_325 ( V_1453 . V_170 -> V_1449 ) ;
F_41 ( V_1453 . V_170 ) ;
return V_35 ;
}
static int F_333 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1392 , * V_1393 , * V_1464 , * V_1465 ;
int V_143 , V_145 , V_1394 ;
struct V_1466 * V_213 ;
if ( ! V_7 -> V_214 -> V_216 )
return 0 ;
V_1465 = F_45 ( V_53 , V_218 ) ;
if ( ! V_1465 )
return - V_81 ;
for ( V_143 = 0 ; V_143 < V_7 -> V_214 -> V_216 ; V_143 ++ ) {
V_1464 = F_45 ( V_53 , V_143 + 1 ) ;
if ( ! V_1464 )
return - V_81 ;
V_213 = & V_7 -> V_214 -> V_1467 [ V_143 ] ;
if ( F_28 ( V_53 , V_1468 ,
V_213 -> V_1469 ) )
return - V_81 ;
if ( F_28 ( V_53 , V_1470 ,
V_213 -> V_1471 ) )
return - V_81 ;
V_1392 = F_45 ( V_53 ,
V_1472 ) ;
if ( ! V_1392 )
return - V_81 ;
for ( V_145 = 0 ; V_145 < V_213 -> V_202 ; V_145 ++ ) {
V_1393 = F_45 ( V_53 , V_145 + 1 ) ;
if ( ! V_1393 )
return - V_81 ;
V_1394 = V_213 -> V_1395 [ V_145 ] . V_1396 ;
if ( F_49 ( V_53 , V_1397 ,
F_316 ( V_1394 , 8 ) ,
V_213 -> V_1395 [ V_145 ] . V_692 ) ||
F_49 ( V_53 , V_1398 , V_1394 ,
V_213 -> V_1395 [ V_145 ] . V_1399 ) ||
F_28 ( V_53 , V_1400 ,
V_213 -> V_1395 [ V_145 ] . V_1401 ) )
return - V_81 ;
F_46 ( V_53 , V_1393 ) ;
}
F_46 ( V_53 , V_1392 ) ;
F_46 ( V_53 , V_1464 ) ;
}
F_46 ( V_53 , V_1465 ) ;
return 0 ;
}
static int F_334 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_31 * V_53 ;
void * V_263 ;
if ( ! V_7 -> V_18 . V_214 )
return - V_501 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1473 ) ;
if ( ! V_263 )
goto V_59;
if ( V_7 -> V_214 && F_333 ( V_53 , V_7 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
F_73 ( V_53 ) ;
return - V_81 ;
}
void F_335 ( struct V_6 * V_7 )
{
struct V_1474 * V_214 = V_7 -> V_214 ;
int V_143 , V_145 ;
struct V_1466 * V_213 ;
if ( ! V_214 )
return;
for ( V_143 = 0 ; V_143 < V_214 -> V_216 ; V_143 ++ ) {
V_213 = & V_214 -> V_1467 [ V_143 ] ;
for ( V_145 = 0 ; V_145 < V_213 -> V_202 ; V_145 ++ )
F_41 ( V_213 -> V_1395 [ V_145 ] . V_692 ) ;
F_41 ( V_213 -> V_1395 ) ;
}
F_41 ( V_214 -> V_1467 ) ;
F_41 ( V_214 ) ;
V_7 -> V_214 = NULL ;
}
static int F_336 ( struct V_6 * V_7 ,
struct V_4 * V_213 ,
struct V_1466 * V_1475 )
{
int V_35 , V_143 ;
const struct V_1476 * V_214 = V_7 -> V_18 . V_214 ;
struct V_4 * V_85 [ V_1477 ] , * V_204 ;
int V_124 , V_1394 , V_1460 , V_1401 , V_202 = 0 ;
struct V_4 * V_1461 [ V_1462 ] ;
V_35 = F_94 ( V_85 , V_1478 , F_23 ( V_213 ) ,
F_24 ( V_213 ) , V_1479 ) ;
if ( V_35 )
return V_35 ;
if ( V_85 [ V_1468 ] )
V_1475 -> V_1469 =
F_4 ( V_85 [ V_1468 ] ) ;
if ( V_1475 -> V_1469 > V_214 -> V_217 )
return - V_16 ;
if ( V_85 [ V_1470 ] )
V_1475 -> V_1471 =
F_4 ( V_85 [ V_1470 ] ) ;
if ( V_1475 -> V_1471 != V_1480 &&
V_1475 -> V_1471 != V_1481 )
return - V_16 ;
if ( ! V_85 [ V_1472 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_202 ++ ;
if ( V_202 > V_214 -> V_202 )
return - V_16 ;
V_1475 -> V_1395 = F_329 ( V_202 , sizeof( V_1475 -> V_1395 [ 0 ] ) ,
V_125 ) ;
if ( ! V_1475 -> V_1395 )
return - V_126 ;
V_1475 -> V_202 = V_202 ;
V_143 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
F_94 ( V_1461 , V_1463 , F_23 ( V_204 ) ,
F_24 ( V_204 ) , NULL ) ;
if ( ! V_1461 [ V_1397 ] ||
! V_1461 [ V_1398 ] )
return - V_16 ;
V_1394 = F_24 ( V_1461 [ V_1398 ] ) ;
V_1460 = F_316 ( V_1394 , 8 ) ;
if ( F_24 ( V_1461 [ V_1397 ] ) != V_1460 )
return - V_16 ;
if ( V_1394 > V_214 -> V_209 ||
V_1394 < V_214 -> V_207 )
return - V_16 ;
if ( ! V_1461 [ V_1400 ] )
V_1401 = 0 ;
else
V_1401 = F_4 ( V_1461 [ V_1400 ] ) ;
if ( V_1401 > V_214 -> V_210 )
return - V_16 ;
V_1475 -> V_1395 [ V_143 ] . V_1401 = V_1401 ;
V_1475 -> V_1395 [ V_143 ] . V_692 =
F_330 ( V_1460 + V_1394 , V_125 ) ;
if ( ! V_1475 -> V_1395 [ V_143 ] . V_692 )
return - V_126 ;
V_1475 -> V_1395 [ V_143 ] . V_1399 =
V_1475 -> V_1395 [ V_143 ] . V_692 + V_1460 ;
memcpy ( V_1475 -> V_1395 [ V_143 ] . V_692 ,
F_23 ( V_1461 [ V_1397 ] ) , V_1460 ) ;
V_1475 -> V_1395 [ V_143 ] . V_1396 = V_1394 ;
memcpy ( V_1475 -> V_1395 [ V_143 ] . V_1399 ,
F_23 ( V_1461 [ V_1398 ] ) , V_1394 ) ;
V_143 ++ ;
}
return 0 ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
const struct V_1476 * V_214 = V_7 -> V_18 . V_214 ;
struct V_1474 V_1482 = {} ;
struct V_1474 * V_1483 ;
int V_35 , V_1484 , V_216 = 0 , V_143 , V_145 ;
struct V_4 * V_213 ;
struct V_1466 * V_1485 ;
if ( ! V_7 -> V_18 . V_214 || ! V_7 -> V_324 -> V_1486 )
return - V_501 ;
if ( ! V_30 -> V_5 [ V_218 ] ) {
F_335 ( V_7 ) ;
V_7 -> V_324 -> V_1486 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_216 ++ ;
if ( V_216 > V_214 -> V_216 )
return - V_16 ;
V_1482 . V_1467 = F_329 ( V_216 , sizeof( V_1482 . V_1467 [ 0 ] ) ,
V_125 ) ;
if ( ! V_1482 . V_1467 )
return - V_126 ;
V_1482 . V_216 = V_216 ;
V_143 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_336 ( V_7 , V_213 ,
& V_1482 . V_1467 [ V_143 ] ) ;
if ( V_35 )
goto error;
V_143 ++ ;
}
V_35 = V_7 -> V_324 -> V_1486 ( & V_7 -> V_18 , & V_1482 ) ;
if ( V_35 )
goto error;
V_1483 = F_331 ( & V_1482 , sizeof( V_1482 ) , V_125 ) ;
if ( ! V_1483 ) {
V_35 = - V_126 ;
goto error;
}
F_335 ( V_7 ) ;
V_7 -> V_214 = V_1483 ;
return 0 ;
error:
for ( V_143 = 0 ; V_143 < V_1482 . V_216 ; V_143 ++ ) {
V_1485 = & V_1482 . V_1467 [ V_143 ] ;
for ( V_145 = 0 ; V_145 < V_1485 -> V_202 ; V_145 ++ )
F_41 ( V_1485 -> V_1395 [ V_145 ] . V_692 ) ;
F_41 ( V_1485 -> V_1395 ) ;
}
F_41 ( V_1482 . V_1467 ) ;
return V_35 ;
}
static int F_338 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_4 * V_85 [ V_1487 ] ;
struct V_1488 V_1489 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1490 ] )
return - V_16 ;
V_35 = F_94 ( V_85 , V_1491 ,
F_23 ( V_30 -> V_5 [ V_1490 ] ) ,
F_24 ( V_30 -> V_5 [ V_1490 ] ) ,
V_1492 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_85 [ V_1493 ] ) != V_1494 )
return - V_1495 ;
if ( F_24 ( V_85 [ V_1496 ] ) != V_1497 )
return - V_1495 ;
if ( F_24 ( V_85 [ V_1498 ] ) != V_1499 )
return - V_1495 ;
memcpy ( V_1489 . V_1500 , F_23 ( V_85 [ V_1496 ] ) ,
V_1497 ) ;
memcpy ( V_1489 . V_1501 , F_23 ( V_85 [ V_1498 ] ) ,
V_1499 ) ;
memcpy ( V_1489 . V_1502 ,
F_23 ( V_85 [ V_1493 ] ) ,
V_1494 ) ;
F_110 ( V_17 ) ;
if ( ! V_17 -> V_139 ) {
V_35 = - V_1503 ;
goto V_552;
}
if ( ! V_7 -> V_324 -> V_1504 ) {
V_35 = - V_501 ;
goto V_552;
}
V_35 = F_339 ( V_7 , V_183 , & V_1489 ) ;
V_552:
F_112 ( V_17 ) ;
return V_35 ;
}
static int F_340 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
if ( V_17 -> V_131 != V_132 &&
V_17 -> V_131 != V_134 )
return - V_16 ;
if ( V_17 -> V_1505 )
return - V_503 ;
V_17 -> V_1505 = V_30 -> V_465 ;
return 0 ;
}
static int F_341 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_31 * V_53 ;
void * V_263 ;
const T_2 * V_624 ;
T_1 V_594 ;
int V_35 ;
if ( V_17 -> V_131 != V_132 &&
V_17 -> V_131 != V_134 )
return - V_501 ;
if ( ! V_30 -> V_5 [ V_506 ] )
return - V_16 ;
if ( ! V_7 -> V_324 -> V_398 )
return - V_501 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1506 ) ;
if ( ! V_263 ) {
V_35 = - V_81 ;
goto V_604;
}
V_624 = F_23 ( V_30 -> V_5 [ V_506 ] ) ;
V_35 = F_342 ( V_7 , V_183 , V_624 , & V_594 ) ;
if ( V_35 )
goto V_604;
if ( F_102 ( V_53 , V_1320 , V_594 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_81 ;
V_604:
F_73 ( V_53 ) ;
return V_35 ;
}
static int F_343 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1507 * V_1508 , * V_1509 ;
int V_1510 ;
if ( ! ( V_7 -> V_18 . V_51 & V_402 ) )
return - V_501 ;
V_1509 = F_38 ( sizeof( * V_1509 ) , V_125 ) ;
if ( ! V_1509 )
return - V_126 ;
F_237 ( & V_7 -> V_1511 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1508 -> V_1512 == V_30 -> V_465 ) {
V_1510 = - V_657 ;
goto V_823;
}
}
V_1509 -> V_1512 = V_30 -> V_465 ;
F_344 ( & V_1509 -> V_587 , & V_7 -> V_1513 ) ;
F_239 ( & V_7 -> V_1511 ) ;
return 0 ;
V_823:
F_239 ( & V_7 -> V_1511 ) ;
F_41 ( V_1509 ) ;
return V_1510 ;
}
static int F_345 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_324 -> V_404 )
return - V_501 ;
if ( V_17 -> V_131 != V_579 )
return - V_501 ;
if ( V_17 -> V_1514 )
return 0 ;
V_35 = F_346 ( V_7 , V_17 -> V_131 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_347 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1514 = true ;
V_7 -> V_1515 ++ ;
return 0 ;
}
static int F_348 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
if ( V_17 -> V_131 != V_579 )
return - V_501 ;
if ( ! V_7 -> V_324 -> V_1516 )
return - V_501 ;
F_349 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_350 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_263 ;
struct V_31 * V_53 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , V_30 -> V_465 , V_30 -> V_466 , 0 ,
V_1517 ) ;
if ( ! V_263 )
goto V_59;
if ( F_28 ( V_53 , V_1518 ,
V_1519 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_74 ( V_53 , V_30 ) ;
V_59:
F_261 ( V_53 ) ;
return - V_81 ;
}
static int F_351 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1520 V_1521 ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
if ( ! V_7 -> V_324 -> V_1522 )
return - V_501 ;
if ( ! V_30 -> V_5 [ V_1523 ] ||
! F_22 ( V_30 -> V_5 [ V_630 ] ) )
return - V_16 ;
memset ( & V_1521 , 0 , sizeof( V_1521 ) ) ;
V_1521 . V_1524 = F_76 ( V_30 -> V_5 [ V_1523 ] ) ;
V_1521 . V_1055 = F_23 ( V_30 -> V_5 [ V_630 ] ) ;
V_1521 . V_1056 = F_24 ( V_30 -> V_5 [ V_630 ] ) ;
return F_352 ( V_7 , V_183 , & V_1521 ) ;
}
static int F_353 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
enum V_1525 V_1224 = V_1526 ;
T_3 V_1316 ;
int V_457 ;
if ( ! V_7 -> V_324 -> V_408 )
return - V_501 ;
if ( F_57 ( ! V_7 -> V_324 -> V_410 ) )
return - V_16 ;
if ( V_7 -> V_1527 )
return - V_503 ;
if ( V_30 -> V_5 [ V_1528 ] )
V_1224 = F_76 ( V_30 -> V_5 [ V_1528 ] ) ;
if ( V_1224 >= V_1529 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1530 ] )
return - V_16 ;
V_1316 =
F_76 ( V_30 -> V_5 [ V_1530 ] ) ;
if ( V_1316 > V_1531 )
return - V_1495 ;
V_457 = F_354 ( V_7 , V_17 , V_1224 , V_1316 ) ;
if ( ! V_457 )
V_7 -> V_1527 = V_30 -> V_465 ;
return V_457 ;
}
static int F_355 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
if ( ! V_7 -> V_324 -> V_410 )
return - V_501 ;
if ( V_7 -> V_1527 ) {
V_7 -> V_1527 = 0 ;
F_356 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_92 ( V_30 ) , V_30 -> V_5 ) ;
int V_143 , V_35 ;
V_22 V_1532 , V_1278 ;
if ( ! V_7 -> V_18 . V_452 )
return - V_501 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1275 ] ||
! V_30 -> V_5 [ V_1277 ] )
return - V_16 ;
V_1532 = F_4 ( V_30 -> V_5 [ V_1275 ] ) ;
V_1278 = F_4 ( V_30 -> V_5 [ V_1277 ] ) ;
for ( V_143 = 0 ; V_143 < V_7 -> V_18 . V_448 ; V_143 ++ ) {
const struct V_1533 * V_1534 ;
void * V_128 = NULL ;
int V_47 = 0 ;
V_1534 = & V_7 -> V_18 . V_452 [ V_143 ] ;
if ( V_1534 -> V_30 . V_1276 != V_1532 || V_1534 -> V_30 . V_1278 != V_1278 )
continue;
if ( V_1534 -> V_51 & ( V_1535 |
V_1536 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1534 -> V_51 & V_1536 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1534 -> V_51 & V_1537 ) {
if ( V_17 -> V_19 &&
! F_89 ( V_17 -> V_19 ) )
return - V_514 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1514 )
return - V_514 ;
}
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_451 ] ) {
V_128 = F_23 ( V_30 -> V_5 [ V_451 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_451 ] ) ;
}
V_7 -> V_1287 = V_30 ;
V_35 = V_7 -> V_18 . V_452 [ V_143 ] . F_358 ( & V_7 -> V_18 , V_17 ,
V_128 , V_47 ) ;
V_7 -> V_1287 = NULL ;
return V_35 ;
}
return - V_501 ;
}
struct V_31 * F_359 ( struct V_18 * V_18 ,
enum V_650 V_52 ,
enum V_1273 V_45 ,
int V_1272 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_57 ( ! V_7 -> V_1287 ) )
return NULL ;
return F_260 ( V_7 , V_1272 ,
V_7 -> V_1287 -> V_465 ,
V_7 -> V_1287 -> V_466 ,
V_52 , V_45 , NULL , V_125 ) ;
}
int F_360 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_263 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_128 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
if ( F_57 ( ! V_7 -> V_1287 ) ) {
F_261 ( V_32 ) ;
return - V_16 ;
}
F_46 ( V_32 , V_128 ) ;
F_64 ( V_32 , V_263 ) ;
return F_74 ( V_32 , V_7 -> V_1287 ) ;
}
static int F_361 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_464 [ 0 ] ;
struct V_1538 * V_1539 = NULL ;
struct V_25 * V_183 = V_30 -> V_464 [ 1 ] ;
T_2 * V_46 , V_47 , V_1540 , V_1541 , V_1542 ;
int V_457 ;
if ( ! V_7 -> V_324 -> V_415 )
return - V_501 ;
if ( V_30 -> V_5 [ V_1543 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1543 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1543 ] ) ;
if ( V_47 % 2 || V_47 < V_1544 ||
V_47 > V_1545 )
return - V_16 ;
V_1539 = F_38 ( sizeof( struct V_1538 ) , V_125 ) ;
if ( ! V_1539 )
return - V_126 ;
V_1540 = ( V_47 - V_1544 ) >> 1 ;
if ( V_1540 ) {
V_1541 = V_1540 *
sizeof( struct V_1546 ) ;
memcpy ( V_1539 -> V_1547 , V_46 , V_1541 ) ;
V_1539 -> V_1540 = V_1540 ;
for ( V_1542 = 0 ; V_1542 < V_1540 ; V_1542 ++ ) {
if ( V_1539 -> V_1547 [ V_1542 ] . V_1548 > 7 ) {
F_41 ( V_1539 ) ;
return - V_16 ;
}
}
V_46 += V_1541 ;
}
memcpy ( V_1539 -> V_1548 , V_46 , V_1544 ) ;
}
F_110 ( V_183 -> V_28 ) ;
V_457 = F_42 ( V_183 -> V_28 ) ;
if ( ! V_457 )
V_457 = F_362 ( V_7 , V_183 , V_1539 ) ;
F_112 ( V_183 -> V_28 ) ;
F_41 ( V_1539 ) ;
return V_457 ;
}
static int F_363 ( const struct V_1549 * V_324 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_183 ;
bool V_1550 = V_324 -> V_1551 & V_1552 ;
if ( V_1550 )
F_14 () ;
if ( V_324 -> V_1551 & V_1553 ) {
V_7 = F_12 ( F_92 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1550 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_464 [ 0 ] = V_7 ;
} else if ( V_324 -> V_1551 & V_1554 ||
V_324 -> V_1551 & V_1555 ) {
F_2 () ;
V_17 = F_1 ( F_92 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1550 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_183 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_324 -> V_1551 & V_1554 ) {
if ( ! V_183 ) {
if ( V_1550 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_464 [ 1 ] = V_183 ;
} else {
V_30 -> V_464 [ 1 ] = V_17 ;
}
if ( V_183 ) {
if ( V_324 -> V_1551 & V_1556 &&
! F_89 ( V_183 ) ) {
if ( V_1550 )
F_20 () ;
return - V_514 ;
}
F_220 ( V_183 ) ;
} else if ( V_324 -> V_1551 & V_1556 ) {
if ( ! V_17 -> V_1514 ) {
if ( V_1550 )
F_20 () ;
return - V_514 ;
}
}
V_30 -> V_464 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_364 ( const struct V_1549 * V_324 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_464 [ 1 ] ) {
if ( V_324 -> V_1551 & V_1555 ) {
struct V_1 * V_17 = V_30 -> V_464 [ 1 ] ;
if ( V_17 -> V_19 )
F_167 ( V_17 -> V_19 ) ;
} else {
F_167 ( V_30 -> V_464 [ 1 ] ) ;
}
}
if ( V_324 -> V_1551 & V_1552 )
F_20 () ;
}
void F_365 ( struct V_6 * V_7 )
{
struct V_31 * V_53 ;
struct V_261 V_262 = {} ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return;
if ( F_56 ( V_7 , V_53 , 0 , 0 , 0 , & V_262 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1557 , V_125 ) ;
}
static int F_366 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1095 * V_1240 = V_7 -> V_1099 ;
struct V_4 * V_1558 ;
int V_143 ;
if ( F_57 ( ! V_1240 ) )
return 0 ;
V_1558 = F_45 ( V_53 , V_1103 ) ;
if ( ! V_1558 )
goto V_59;
for ( V_143 = 0 ; V_143 < V_1240 -> V_1097 ; V_143 ++ ) {
if ( F_49 ( V_53 , V_143 , V_1240 -> V_1104 [ V_143 ] . V_545 , V_1240 -> V_1104 [ V_143 ] . V_547 ) )
goto V_59;
}
F_46 ( V_53 , V_1558 ) ;
V_1558 = F_45 ( V_53 , V_1102 ) ;
if ( ! V_1558 )
goto V_59;
for ( V_143 = 0 ; V_143 < V_1240 -> V_339 ; V_143 ++ ) {
if ( F_28 ( V_53 , V_143 , V_1240 -> V_340 [ V_143 ] -> V_58 ) )
goto V_59;
}
F_46 ( V_53 , V_1558 ) ;
if ( V_1240 -> V_1055 &&
F_49 ( V_53 , V_630 , V_1240 -> V_1056 , V_1240 -> V_1055 ) )
goto V_59;
if ( V_1240 -> V_51 &&
F_28 ( V_53 , V_1108 , V_1240 -> V_51 ) )
goto V_59;
return 0 ;
V_59:
return - V_81 ;
}
static int F_367 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_263 ;
V_263 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_263 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_366 ( V_53 , V_7 ) ;
return F_64 ( V_53 , V_263 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
static int
F_368 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_263 ;
V_263 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_263 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
return F_64 ( V_53 , V_263 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
return - V_456 ;
}
void F_219 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return;
if ( F_367 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1559 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1560 , V_125 ) ;
}
struct V_31 * F_369 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1561 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return NULL ;
if ( F_367 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1561 ? V_1562 :
V_1158 ) < 0 ) {
F_73 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_370 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1560 , V_125 ) ;
}
void F_371 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return;
if ( F_368 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1563 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1560 , V_125 ) ;
}
void F_223 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return;
if ( F_368 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1560 , V_125 ) ;
}
void F_372 ( struct V_1564 * V_1096 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1565 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_54 ( V_53 , V_1566 , V_1096 -> V_1567 ) )
goto V_59;
if ( V_1096 -> V_1071 [ 0 ] == '0' && V_1096 -> V_1071 [ 1 ] == '0' ) {
if ( F_54 ( V_53 , V_1568 ,
V_1569 ) )
goto V_59;
} else if ( V_1096 -> V_1071 [ 0 ] == '9' && V_1096 -> V_1071 [ 1 ] == '9' ) {
if ( F_54 ( V_53 , V_1568 ,
V_1570 ) )
goto V_59;
} else if ( ( V_1096 -> V_1071 [ 0 ] == '9' && V_1096 -> V_1071 [ 1 ] == '8' ) ||
V_1096 -> V_1571 ) {
if ( F_54 ( V_53 , V_1568 ,
V_1572 ) )
goto V_59;
} else {
if ( F_54 ( V_53 , V_1568 ,
V_1573 ) ||
F_58 ( V_53 , V_964 ,
V_1096 -> V_1071 ) )
goto V_59;
}
if ( V_1096 -> V_14 != V_1574 &&
F_28 ( V_53 , V_26 , V_1096 -> V_14 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_206 () ;
F_373 ( & V_38 , V_53 , 0 ,
V_1575 , V_1576 ) ;
F_208 () ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
static void F_374 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1362 , T_10 V_47 ,
enum V_650 V_52 , T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_53 , V_1358 , V_47 , V_1362 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_375 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1362 ,
T_10 V_47 , T_11 V_1274 )
{
F_374 ( V_7 , V_19 , V_1362 , V_47 ,
V_652 , V_1274 ) ;
}
void F_376 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1362 ,
T_10 V_47 , T_11 V_1274 )
{
F_374 ( V_7 , V_19 , V_1362 , V_47 ,
V_1578 , V_1274 ) ;
}
void F_377 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1362 ,
T_10 V_47 , T_11 V_1274 )
{
F_374 ( V_7 , V_19 , V_1362 , V_47 ,
V_1579 , V_1274 ) ;
}
void F_378 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1362 ,
T_10 V_47 , T_11 V_1274 )
{
F_374 ( V_7 , V_19 , V_1362 , V_47 ,
V_1580 , V_1274 ) ;
}
void F_379 ( struct V_25 * V_183 , const T_2 * V_1362 ,
T_10 V_47 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1581 * V_1582 = ( void * ) V_1362 ;
V_22 V_52 ;
if ( F_57 ( V_47 < 2 ) )
return;
if ( F_380 ( V_1582 -> V_1583 ) )
V_52 = V_1584 ;
else
V_52 = V_1585 ;
F_381 ( V_183 , V_1362 , V_47 ) ;
F_374 ( V_7 , V_183 , V_1362 , V_47 , V_52 , V_1576 ) ;
}
static void F_382 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_624 , T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1586 ) ||
F_49 ( V_53 , V_506 , V_542 , V_624 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_383 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_624 ,
T_11 V_1274 )
{
F_382 ( V_7 , V_19 , V_652 ,
V_624 , V_1274 ) ;
}
void F_384 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_624 ,
T_11 V_1274 )
{
F_382 ( V_7 , V_19 , V_1578 ,
V_624 , V_1274 ) ;
}
void F_385 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_505 ,
const T_2 * V_1587 , T_10 V_1588 ,
const T_2 * V_1589 , T_10 V_1590 ,
T_3 V_1591 , T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_420 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_505 && F_49 ( V_53 , V_506 , V_542 , V_505 ) ) ||
F_53 ( V_53 , V_1311 , V_1591 ) ||
( V_1587 &&
F_49 ( V_53 , V_1592 , V_1588 , V_1587 ) ) ||
( V_1589 &&
F_49 ( V_53 , V_1593 , V_1590 , V_1589 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_386 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_505 ,
const T_2 * V_1587 , T_10 V_1588 ,
const T_2 * V_1589 , T_10 V_1590 , T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1594 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_505 ) ||
( V_1587 &&
F_49 ( V_53 , V_1592 , V_1588 , V_1587 ) ) ||
( V_1589 &&
F_49 ( V_53 , V_1593 , V_1590 , V_1589 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_387 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1295 ,
const T_2 * V_1055 , T_10 V_1056 , bool V_1595 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_422 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1595 && V_1295 &&
F_53 ( V_53 , V_1256 , V_1295 ) ) ||
( V_1595 &&
F_29 ( V_53 , V_1596 ) ) ||
( V_1055 && F_49 ( V_53 , V_630 , V_1056 , V_1055 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_125 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_388 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_505 ,
T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1597 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_505 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_389 ( struct V_25 * V_183 , const T_2 * V_624 ,
const T_2 * V_1055 , T_2 V_1056 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
if ( F_57 ( V_17 -> V_131 != V_135 ) )
return;
F_390 ( V_183 , V_624 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1598 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_624 ) ||
( V_1056 && V_1055 &&
F_49 ( V_53 , V_630 , V_1056 , V_1055 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_391 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_624 ,
enum V_1599 V_1600 , int V_1601 ,
const T_2 * V_1602 , T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1603 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_624 && F_49 ( V_53 , V_506 , V_542 , V_624 ) ) ||
F_28 ( V_53 , V_117 , V_1600 ) ||
( V_1601 != - 1 &&
F_54 ( V_53 , V_113 , V_1601 ) ) ||
( V_1602 && F_49 ( V_53 , V_112 , 6 , V_1602 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_392 ( struct V_18 * V_18 ,
struct V_54 * V_1604 ,
struct V_54 * V_1605 )
{
struct V_31 * V_53 ;
void * V_263 ;
struct V_4 * V_267 ;
V_53 = F_72 ( V_553 , V_1576 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1606 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_393 ( V_18 ) ) )
goto V_59;
V_267 = F_45 ( V_53 , V_1607 ) ;
if ( ! V_267 )
goto V_59;
if ( F_27 ( V_53 , V_1604 , false ) )
goto V_59;
F_46 ( V_53 , V_267 ) ;
V_267 = F_45 ( V_53 , V_1608 ) ;
if ( ! V_267 )
goto V_59;
if ( F_27 ( V_53 , V_1605 , false ) )
goto V_59;
F_46 ( V_53 , V_267 ) ;
F_64 ( V_53 , V_263 ) ;
F_206 () ;
F_373 ( & V_38 , V_53 , 0 ,
V_1575 , V_1576 ) ;
F_208 () ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
static void F_394 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_594 ,
struct V_54 * V_55 ,
unsigned int V_1316 , T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_484 , V_55 -> V_58 ) ||
F_28 ( V_53 , V_489 ,
V_492 ) ||
F_102 ( V_53 , V_1320 , V_594 ) )
goto V_59;
if ( V_52 == V_1319 &&
F_28 ( V_53 , V_1317 , V_1316 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_395 ( struct V_1 * V_17 , T_1 V_594 ,
struct V_54 * V_55 ,
unsigned int V_1316 , T_11 V_1274 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_396 ( V_17 , V_594 , V_55 , V_1316 ) ;
F_394 ( V_1319 ,
V_7 , V_17 , V_594 , V_55 ,
V_1316 , V_1274 ) ;
}
void F_397 ( struct V_1 * V_17 , T_1 V_594 ,
struct V_54 * V_55 ,
T_11 V_1274 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_398 ( V_17 , V_594 , V_55 ) ;
F_394 ( V_1609 ,
V_7 , V_17 , V_594 , V_55 , 0 , V_1274 ) ;
}
void F_399 ( struct V_25 * V_183 , const T_2 * V_596 ,
struct V_727 * V_728 , T_11 V_1274 )
{
struct V_18 * V_18 = V_183 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_400 ( V_183 , V_596 , V_728 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
if ( F_159 ( V_53 , 0 , 0 , 0 ,
V_7 , V_183 , V_596 , V_728 ) < 0 ) {
F_73 ( V_53 ) ;
return;
}
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
}
void F_401 ( struct V_25 * V_183 , const T_2 * V_596 , T_11 V_1274 )
{
struct V_18 * V_18 = V_183 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
F_402 ( V_183 , V_596 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1610 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_596 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_403 ( struct V_25 * V_183 , const T_2 * V_596 ,
enum V_1611 V_1295 ,
T_11 V_1274 )
{
struct V_18 * V_18 = V_183 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_1612 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1613 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_596 ) ||
F_28 ( V_53 , V_1614 , V_1295 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
static bool F_404 ( struct V_25 * V_183 , T_2 V_52 ,
const T_2 * V_624 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
V_22 V_1512 = F_405 ( V_17 -> V_1505 ) ;
if ( ! V_1512 )
return false ;
V_53 = F_72 ( 100 , V_1274 ) ;
if ( ! V_53 )
return true ;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_624 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_406 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1512 ) ;
return true ;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
return true ;
}
bool F_407 ( struct V_25 * V_183 ,
const T_2 * V_624 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
bool V_457 ;
F_408 ( V_183 , V_624 ) ;
if ( F_57 ( V_17 -> V_131 != V_132 &&
V_17 -> V_131 != V_134 ) ) {
F_409 ( false ) ;
return false ;
}
V_457 = F_404 ( V_183 , V_1615 ,
V_624 , V_1274 ) ;
F_409 ( V_457 ) ;
return V_457 ;
}
bool F_410 ( struct V_25 * V_183 ,
const T_2 * V_624 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
bool V_457 ;
F_411 ( V_183 , V_624 ) ;
if ( F_57 ( V_17 -> V_131 != V_132 &&
V_17 -> V_131 != V_134 &&
V_17 -> V_131 != V_133 ) ) {
F_409 ( false ) ;
return false ;
}
V_457 = F_404 ( V_183 ,
V_1616 ,
V_624 , V_1274 ) ;
F_409 ( V_457 ) ;
return V_457 ;
}
int F_412 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1512 ,
int V_1617 , int V_1618 ,
const T_2 * V_1362 , T_10 V_47 , V_22 V_51 , T_11 V_1274 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return - V_126 ;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1361 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return - V_126 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_484 , V_1617 ) ||
( V_1618 &&
F_28 ( V_53 , V_1619 , V_1618 ) ) ||
F_49 ( V_53 , V_1358 , V_47 , V_1362 ) ||
( V_51 &&
F_28 ( V_53 , V_1620 , V_51 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
return F_406 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1512 ) ;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
return - V_81 ;
}
void F_413 ( struct V_1 * V_17 , T_1 V_594 ,
const T_2 * V_1362 , T_10 V_47 , bool V_1621 , T_11 V_1274 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_263 ;
F_414 ( V_17 , V_594 , V_1621 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1622 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_49 ( V_53 , V_1358 , V_47 , V_1362 ) ||
F_102 ( V_53 , V_1320 , V_594 ) ||
( V_1621 && F_29 ( V_53 , V_1623 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_415 ( struct V_25 * V_183 ,
enum V_1624 V_1625 ,
T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_900 ;
void * V_263 ;
F_416 ( V_183 , V_1625 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1626 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_183 -> V_20 ) )
goto V_59;
V_900 = F_45 ( V_53 , V_1381 ) ;
if ( ! V_900 )
goto V_59;
if ( F_28 ( V_53 , V_1627 ,
V_1625 ) )
goto V_59;
F_46 ( V_53 , V_900 ) ;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
static void F_417 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_505 ,
const T_2 * V_1502 , T_11 V_1274 )
{
struct V_31 * V_53 ;
struct V_4 * V_1628 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1629 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_505 ) )
goto V_59;
V_1628 = F_45 ( V_53 , V_1490 ) ;
if ( ! V_1628 )
goto V_59;
if ( F_49 ( V_53 , V_1493 ,
V_1494 , V_1502 ) )
goto V_59;
F_46 ( V_53 , V_1628 ) ;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_418 ( struct V_25 * V_183 , const T_2 * V_505 ,
const T_2 * V_1502 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_419 ( V_183 , V_505 ) ;
F_417 ( V_7 , V_183 , V_505 , V_1502 , V_1274 ) ;
}
static void
F_420 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1630 ,
const T_2 * V_505 , bool V_1631 , T_11 V_1274 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1632 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
V_45 = F_45 ( V_53 , V_1633 ) ;
if ( ! V_45 )
goto V_59;
if ( F_28 ( V_53 , V_1634 , V_1630 ) ||
F_49 ( V_53 , V_1635 , V_542 , V_505 ) ||
( V_1631 &&
F_29 ( V_53 , V_1636 ) ) )
goto V_59;
F_46 ( V_53 , V_45 ) ;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_421 ( struct V_25 * V_183 , int V_1630 ,
const T_2 * V_505 , bool V_1631 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_422 ( V_183 , V_1630 , V_505 , V_1631 ) ;
F_420 ( V_7 , V_183 , V_1630 , V_505 , V_1631 , V_1274 ) ;
}
static void F_423 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_481 * V_482 ,
T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1637 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
if ( F_99 ( V_53 , V_482 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_424 ( struct V_25 * V_183 ,
struct V_481 * V_482 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_425 ( V_183 , V_482 ) ;
if ( F_57 ( V_17 -> V_131 != V_132 &&
V_17 -> V_131 != V_134 &&
V_17 -> V_131 != V_136 &&
V_17 -> V_131 != V_135 ) )
return;
V_17 -> V_684 = V_482 -> V_55 ;
F_423 ( V_7 , V_183 , V_482 , V_125 ) ;
}
void F_426 ( struct V_25 * V_183 ,
const T_2 * V_1309 , V_22 V_1638 ,
V_22 V_224 , V_22 V_1373 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_900 ;
void * V_263 ;
V_53 = F_72 ( V_1612 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1626 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_1309 ) )
goto V_59;
V_900 = F_45 ( V_53 , V_1381 ) ;
if ( ! V_900 )
goto V_59;
if ( F_28 ( V_53 , V_1386 , V_1638 ) )
goto V_59;
if ( F_28 ( V_53 , V_1385 , V_224 ) )
goto V_59;
if ( F_28 ( V_53 , V_1387 , V_1373 ) )
goto V_59;
F_46 ( V_53 , V_900 ) ;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void
F_427 ( struct V_6 * V_7 ,
const struct V_481 * V_482 ,
enum V_1639 V_1640 ,
struct V_25 * V_19 , T_11 V_1274 )
{
struct V_31 * V_53 ;
void * V_263 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1641 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
}
if ( F_28 ( V_53 , V_1642 , V_1640 ) )
goto V_59;
if ( F_99 ( V_53 , V_482 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_428 ( struct V_25 * V_183 ,
const T_2 * V_1309 , V_22 V_1638 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_900 ;
void * V_263 ;
F_429 ( V_183 , V_1309 , V_1638 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1626 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_1309 ) )
goto V_59;
V_900 = F_45 ( V_53 , V_1381 ) ;
if ( ! V_900 )
goto V_59;
if ( F_28 ( V_53 , V_1643 , V_1638 ) )
goto V_59;
F_46 ( V_53 , V_900 ) ;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_430 ( struct V_25 * V_183 , const T_2 * V_624 ,
T_1 V_594 , bool V_1644 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
F_431 ( V_183 , V_624 , V_594 , V_1644 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1506 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_624 ) ||
F_102 ( V_53 , V_1320 , V_594 ) ||
( V_1644 && F_29 ( V_53 , V_1623 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_432 ( struct V_18 * V_18 ,
const T_2 * V_1645 , T_10 V_47 ,
int V_1617 , int V_1618 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
struct V_1507 * V_1508 ;
F_433 ( V_18 , V_1645 , V_47 , V_1617 , V_1618 ) ;
F_237 ( & V_7 -> V_1511 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_72 ( V_47 + 100 , V_1576 ) ;
if ( ! V_53 ) {
F_239 ( & V_7 -> V_1511 ) ;
return;
}
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1361 ) ;
if ( ! V_263 )
goto V_59;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1617 &&
F_28 ( V_53 , V_484 , V_1617 ) ) ||
( V_1618 &&
F_28 ( V_53 , V_1619 , V_1618 ) ) ||
F_49 ( V_53 , V_1358 , V_47 , V_1645 ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_406 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1508 -> V_1512 ) ;
}
F_239 ( & V_7 -> V_1511 ) ;
return;
V_59:
F_239 ( & V_7 -> V_1511 ) ;
if ( V_263 )
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
void F_434 ( struct V_1 * V_17 ,
struct V_1646 * V_1647 ,
T_11 V_1274 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
int V_1422 = 200 ;
F_435 ( V_17 -> V_18 , V_17 , V_1647 ) ;
if ( V_1647 )
V_1422 += V_1647 -> V_1648 ;
V_53 = F_72 ( V_1422 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1649 ) ;
if ( ! V_263 )
goto V_604;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_604;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_604;
if ( V_1647 ) {
struct V_4 * V_1650 ;
V_1650 = F_45 ( V_53 , V_1424 ) ;
if ( ! V_1650 )
goto V_604;
if ( V_1647 -> V_421 &&
F_29 ( V_53 , V_189 ) )
goto V_604;
if ( V_1647 -> V_1426 &&
F_29 ( V_53 , V_191 ) )
goto V_604;
if ( V_1647 -> V_1427 &&
F_29 ( V_53 , V_195 ) )
goto V_604;
if ( V_1647 -> V_1428 &&
F_29 ( V_53 , V_197 ) )
goto V_604;
if ( V_1647 -> V_1429 &&
F_29 ( V_53 , V_199 ) )
goto V_604;
if ( V_1647 -> V_1430 &&
F_29 ( V_53 , V_201 ) )
goto V_604;
if ( V_1647 -> V_1651 >= 0 &&
F_28 ( V_53 , V_211 ,
V_1647 -> V_1651 ) )
goto V_604;
if ( V_1647 -> V_1652 &&
F_29 ( V_53 , V_1653 ) )
goto V_604;
if ( V_1647 -> V_1654 &&
F_29 ( V_53 , V_1655 ) )
goto V_604;
if ( V_1647 -> V_1656 &&
F_29 ( V_53 ,
V_1657 ) )
goto V_604;
if ( V_1647 -> V_1658 ) {
V_22 V_1659 = V_1660 ;
V_22 V_1661 = V_1662 ;
if ( ! V_1647 -> V_1663 ) {
V_1659 =
V_1664 ;
V_1661 =
V_1665 ;
}
if ( V_1647 -> V_1666 &&
F_28 ( V_53 , V_1661 , V_1647 -> V_1666 ) )
goto V_604;
if ( F_49 ( V_53 , V_1659 , V_1647 -> V_1648 ,
V_1647 -> V_1658 ) )
goto V_604;
}
F_46 ( V_53 , V_1650 ) ;
}
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_604:
F_73 ( V_53 ) ;
}
void F_436 ( struct V_25 * V_183 , const T_2 * V_1309 ,
enum V_1313 V_1667 ,
T_3 V_1255 , T_11 V_1274 )
{
struct V_1 * V_17 = V_183 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
F_437 ( V_17 -> V_18 , V_183 , V_1309 , V_1667 ,
V_1255 ) ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1668 ) ;
if ( ! V_263 ) {
F_73 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_183 -> V_20 ) ||
F_54 ( V_53 , V_1315 , V_1667 ) ||
F_49 ( V_53 , V_506 , V_542 , V_1309 ) ||
( V_1255 > 0 &&
F_53 ( V_53 , V_1256 , V_1255 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_1274 ) ;
return;
V_59:
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
static int F_438 ( struct V_1669 * V_1670 ,
unsigned long V_262 ,
void * V_1671 )
{
struct V_1672 * V_1673 = V_1671 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1507 * V_1508 , * V_24 ;
if ( V_262 != V_1674 )
return V_1675 ;
F_206 () ;
F_439 (rdev, &cfg80211_rdev_list, list) {
F_439 (wdev, &rdev->wdev_list, list)
F_440 ( V_17 , V_1673 -> V_49 ) ;
F_237 ( & V_7 -> V_1511 ) ;
F_441 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1508 -> V_1512 == V_1673 -> V_49 ) {
F_442 ( & V_1508 -> V_587 ) ;
F_41 ( V_1508 ) ;
break;
}
}
F_239 ( & V_7 -> V_1511 ) ;
}
F_208 () ;
return V_1675 ;
}
void F_443 ( struct V_25 * V_19 ,
struct V_1676 * V_1677 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_263 ;
F_444 ( V_18 , V_19 , V_1677 ) ;
if ( ! V_1677 -> V_1678 )
return;
V_53 = F_72 ( V_553 , V_125 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1679 ) ;
if ( ! V_263 )
goto V_552;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_53 , V_506 , V_542 , V_1677 -> V_1678 ) )
goto V_552;
if ( V_1677 -> V_1155 &&
F_49 ( V_53 , V_630 , V_1677 -> V_1680 , V_1677 -> V_1155 ) )
goto V_552;
if ( V_1677 -> V_1681 &&
F_49 ( V_53 , V_1682 , V_1677 -> V_1683 ,
V_1677 -> V_1681 ) )
goto V_552;
F_64 ( V_53 , V_263 ) ;
F_264 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1577 , V_125 ) ;
return;
V_552:
F_73 ( V_53 ) ;
}
void F_445 ( struct V_1 * V_17 , T_11 V_1274 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_263 ;
V_22 V_1512 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1527 )
return;
V_1512 = V_7 -> V_1527 ;
V_7 -> V_1527 = 0 ;
V_53 = F_72 ( V_553 , V_1274 ) ;
if ( ! V_53 )
return;
V_263 = F_25 ( V_53 , 0 , 0 , 0 , V_1684 ) ;
if ( ! V_263 )
goto V_59;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_102 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_64 ( V_53 , V_263 ) ;
F_406 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1512 ) ;
return;
V_59:
if ( V_263 )
F_65 ( V_53 , V_263 ) ;
F_73 ( V_53 ) ;
}
int F_446 ( void )
{
int V_35 ;
V_35 = F_447 ( & V_38 , V_1685 ,
V_1686 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_448 ( & V_1687 ) ;
if ( V_35 )
goto V_1688;
return 0 ;
V_1688:
F_449 ( & V_38 ) ;
return V_35 ;
}
void F_450 ( void )
{
F_451 ( & V_1687 ) ;
F_449 ( & V_38 ) ;
}
