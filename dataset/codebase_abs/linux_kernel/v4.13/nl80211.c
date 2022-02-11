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
if ( ! V_34 -> args [ 0 ] ) {
V_35 = F_14 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
F_15 ( & V_38 ) ,
V_38 . V_40 , V_41 , NULL ) ;
if ( V_35 )
return V_35 ;
* V_17 = F_1 (
F_16 ( V_32 -> V_42 ) ,
F_15 ( & V_38 ) ) ;
if ( F_17 ( * V_17 ) )
return F_18 ( * V_17 ) ;
* V_7 = F_11 ( ( * V_17 ) -> V_18 ) ;
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = ( * V_17 ) -> V_21 ;
} else {
struct V_18 * V_18 = F_19 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 )
return - V_23 ;
* V_7 = F_11 ( V_18 ) ;
* V_17 = NULL ;
F_6 (tmp, &(*rdev)->wiphy.wdev_list, list) {
if ( V_24 -> V_21 == V_34 -> args [ 1 ] ) {
* V_17 = V_24 ;
break;
}
}
if ( ! * V_17 )
return - V_23 ;
}
return 0 ;
}
static bool F_20 ( const struct V_4 * V_43 )
{
const T_2 * V_44 ;
int V_45 ;
if ( ! V_43 )
return true ;
V_44 = F_21 ( V_43 ) ;
V_45 = F_22 ( V_43 ) ;
while ( V_45 ) {
T_2 V_46 ;
if ( V_45 < 2 )
return false ;
V_45 -= 2 ;
V_46 = V_44 [ 1 ] ;
if ( V_46 > V_45 )
return false ;
V_45 -= V_46 ;
V_44 += 2 + V_46 ;
}
return true ;
}
static inline void * F_23 ( struct V_31 * V_32 , V_22 V_47 , V_22 V_48 ,
int V_49 , T_2 V_50 )
{
return F_24 ( V_32 , V_47 , V_48 , & V_38 , V_49 , V_50 ) ;
}
static int F_25 ( struct V_31 * V_51 ,
struct V_52 * V_53 ,
bool V_54 )
{
if ( ! V_54 && V_53 -> V_49 &
( V_55 | V_56 ) )
return 0 ;
if ( F_26 ( V_51 , V_57 ,
V_53 -> V_58 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_60 ) &&
F_27 ( V_51 , V_61 ) )
goto V_59;
if ( V_53 -> V_49 & V_62 ) {
if ( F_27 ( V_51 , V_63 ) )
goto V_59;
if ( F_27 ( V_51 , V_64 ) )
goto V_59;
}
if ( V_53 -> V_49 & V_65 ) {
if ( F_27 ( V_51 , V_66 ) )
goto V_59;
if ( V_54 ) {
V_22 time ;
time = F_28 ( V_53 -> V_67 ) ;
if ( F_26 ( V_51 , V_68 ,
V_53 -> V_69 ) )
goto V_59;
if ( F_26 ( V_51 , V_70 ,
time ) )
goto V_59;
if ( F_26 ( V_51 ,
V_71 ,
V_53 -> V_72 ) )
goto V_59;
}
}
if ( V_54 ) {
if ( ( V_53 -> V_49 & V_73 ) &&
F_27 ( V_51 , V_74 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_75 ) &&
F_27 ( V_51 , V_76 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_77 ) &&
F_27 ( V_51 , V_78 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_79 ) &&
F_27 ( V_51 , V_80 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_81 ) &&
F_27 ( V_51 , V_82 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_83 ) &&
F_27 ( V_51 , V_84 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_56 ) &&
F_27 ( V_51 , V_85 ) )
goto V_59;
if ( ( V_53 -> V_49 & V_55 ) &&
F_27 ( V_51 , V_86 ) )
goto V_59;
}
if ( F_26 ( V_51 , V_87 ,
F_29 ( V_53 -> V_88 ) ) )
goto V_59;
return 0 ;
V_59:
return - V_89 ;
}
static int F_30 ( struct V_4 * V_90 , struct V_91 * V_92 )
{
struct V_4 * V_93 [ V_94 + 1 ] ;
int V_35 = F_31 ( V_93 , V_94 , V_90 ,
V_95 , NULL ) ;
if ( V_35 )
return V_35 ;
V_92 -> V_96 = ! ! V_93 [ V_97 ] ;
V_92 -> V_98 = ! ! V_93 [ V_99 ] ;
if ( V_92 -> V_96 ) {
V_92 -> V_100 = true ;
V_92 -> V_101 = true ;
}
if ( V_92 -> V_98 )
V_92 -> V_101 = true ;
if ( V_93 [ V_102 ] )
V_92 -> V_103 = F_32 ( V_93 [ V_102 ] ) ;
if ( V_93 [ V_104 ] ) {
V_92 -> V_105 . V_90 = F_21 ( V_93 [ V_104 ] ) ;
V_92 -> V_105 . V_106 = F_22 ( V_93 [ V_104 ] ) ;
}
if ( V_93 [ V_107 ] ) {
V_92 -> V_105 . V_48 = F_21 ( V_93 [ V_107 ] ) ;
V_92 -> V_105 . V_108 = F_22 ( V_93 [ V_107 ] ) ;
}
if ( V_93 [ V_109 ] )
V_92 -> V_105 . V_110 = F_4 ( V_93 [ V_109 ] ) ;
if ( V_93 [ V_111 ] ) {
V_92 -> type = F_4 ( V_93 [ V_111 ] ) ;
if ( V_92 -> type < 0 || V_92 -> type >= V_112 )
return - V_16 ;
}
if ( V_93 [ V_113 ] ) {
struct V_4 * V_114 [ V_115 ] ;
V_35 = F_31 ( V_114 , V_115 - 1 ,
V_93 [ V_113 ] ,
V_116 , NULL ) ;
if ( V_35 )
return V_35 ;
V_92 -> V_100 = V_114 [ V_117 ] ;
V_92 -> V_101 = V_114 [ V_118 ] ;
}
return 0 ;
}
static int F_33 ( struct V_29 * V_30 , struct V_91 * V_92 )
{
if ( V_30 -> V_5 [ V_119 ] ) {
V_92 -> V_105 . V_90 = F_21 ( V_30 -> V_5 [ V_119 ] ) ;
V_92 -> V_105 . V_106 = F_22 ( V_30 -> V_5 [ V_119 ] ) ;
}
if ( V_30 -> V_5 [ V_120 ] ) {
V_92 -> V_105 . V_48 = F_21 ( V_30 -> V_5 [ V_120 ] ) ;
V_92 -> V_105 . V_108 = F_22 ( V_30 -> V_5 [ V_120 ] ) ;
}
if ( V_30 -> V_5 [ V_121 ] )
V_92 -> V_103 = F_32 ( V_30 -> V_5 [ V_121 ] ) ;
if ( V_30 -> V_5 [ V_122 ] )
V_92 -> V_105 . V_110 = F_4 ( V_30 -> V_5 [ V_122 ] ) ;
V_92 -> V_96 = ! ! V_30 -> V_5 [ V_123 ] ;
V_92 -> V_98 = ! ! V_30 -> V_5 [ V_124 ] ;
if ( V_92 -> V_96 ) {
V_92 -> V_100 = true ;
V_92 -> V_101 = true ;
}
if ( V_92 -> V_98 )
V_92 -> V_101 = true ;
if ( V_30 -> V_5 [ V_125 ] ) {
V_92 -> type = F_4 ( V_30 -> V_5 [ V_125 ] ) ;
if ( V_92 -> type < 0 || V_92 -> type >= V_112 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_126 ] ) {
struct V_4 * V_114 [ V_115 ] ;
int V_35 = F_31 ( V_114 ,
V_115 - 1 ,
V_30 -> V_5 [ V_126 ] ,
V_116 ,
V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
V_92 -> V_100 = V_114 [ V_117 ] ;
V_92 -> V_101 = V_114 [ V_118 ] ;
}
return 0 ;
}
static int F_34 ( struct V_29 * V_30 , struct V_91 * V_92 )
{
int V_35 ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_103 = - 1 ;
V_92 -> type = - 1 ;
if ( V_30 -> V_5 [ V_128 ] )
V_35 = F_30 ( V_30 -> V_5 [ V_128 ] , V_92 ) ;
else
V_35 = F_33 ( V_30 , V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 -> V_96 && V_92 -> V_98 )
return - V_16 ;
if ( V_92 -> V_98 ) {
if ( V_92 -> V_100 || ! V_92 -> V_101 )
return - V_16 ;
}
if ( V_92 -> V_103 != - 1 ) {
if ( V_92 -> V_98 ) {
if ( V_92 -> V_103 < 4 || V_92 -> V_103 > 5 )
return - V_16 ;
} else if ( V_92 -> V_96 ) {
if ( V_92 -> V_103 < 0 || V_92 -> V_103 > 3 )
return - V_16 ;
} else {
if ( V_92 -> V_103 < 0 || V_92 -> V_103 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_129 *
F_35 ( struct V_6 * V_7 ,
struct V_4 * V_130 , bool * V_131 )
{
struct V_91 V_132 ;
struct V_4 * V_90 ;
struct V_129 * V_8 ;
int V_133 , V_35 , V_96 = 0 ;
bool V_134 = false ;
F_36 (key, keys, rem) {
V_134 = true ;
break;
}
if ( ! V_134 )
return NULL ;
V_8 = F_37 ( sizeof( * V_8 ) , V_135 ) ;
if ( ! V_8 )
return F_3 ( - V_136 ) ;
V_8 -> V_96 = - 1 ;
F_36 (key, keys, rem) {
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . V_103 = - 1 ;
V_35 = F_30 ( V_90 , & V_132 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_132 . V_105 . V_90 )
goto error;
if ( V_132 . V_103 < 0 || V_132 . V_103 > 3 )
goto error;
if ( V_132 . V_96 ) {
if ( V_96 )
goto error;
V_96 = 1 ;
V_8 -> V_96 = V_132 . V_103 ;
if ( ! V_132 . V_100 || ! V_132 . V_101 )
goto error;
} else if ( V_132 . V_98 )
goto error;
V_35 = F_38 ( V_7 , & V_132 . V_105 ,
V_132 . V_103 , false , NULL ) ;
if ( V_35 )
goto error;
if ( V_132 . V_105 . V_110 != V_137 &&
V_132 . V_105 . V_110 != V_138 ) {
V_35 = - V_16 ;
goto error;
}
V_8 -> V_139 [ V_132 . V_103 ] . V_110 = V_132 . V_105 . V_110 ;
V_8 -> V_139 [ V_132 . V_103 ] . V_106 = V_132 . V_105 . V_106 ;
V_8 -> V_139 [ V_132 . V_103 ] . V_90 = V_8 -> V_140 [ V_132 . V_103 ] ;
memcpy ( V_8 -> V_140 [ V_132 . V_103 ] , V_132 . V_105 . V_90 , V_132 . V_105 . V_106 ) ;
if ( V_131 )
* V_131 = true ;
}
if ( V_8 -> V_96 < 0 ) {
V_35 = - V_16 ;
goto error;
}
return V_8 ;
error:
F_39 ( V_8 ) ;
return F_3 ( V_35 ) ;
}
static int F_40 ( struct V_1 * V_17 )
{
F_41 ( V_17 ) ;
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
case V_157 :
return - V_16 ;
}
return 0 ;
}
static struct V_52 * F_42 ( struct V_18 * V_18 ,
struct V_4 * V_93 )
{
struct V_52 * V_53 ;
if ( V_93 == NULL )
return NULL ;
V_53 = F_43 ( V_18 , F_4 ( V_93 ) ) ;
if ( ! V_53 || V_53 -> V_49 & V_60 )
return NULL ;
return V_53 ;
}
static int F_44 ( struct V_31 * V_51 , V_22 V_43 , T_3 V_158 )
{
struct V_4 * V_159 = F_45 ( V_51 , V_43 ) ;
int V_160 ;
if ( ! V_159 )
goto V_59;
V_160 = 0 ;
while ( V_158 ) {
if ( ( V_158 & 1 ) && F_27 ( V_51 , V_160 ) )
goto V_59;
V_158 >>= 1 ;
V_160 ++ ;
}
F_46 ( V_51 , V_159 ) ;
return 0 ;
V_59:
return - V_89 ;
}
static int F_47 ( struct V_18 * V_18 ,
struct V_31 * V_51 ,
bool V_54 )
{
struct V_4 * V_161 ;
int V_160 , V_162 ;
V_161 = F_45 ( V_51 ,
V_163 ) ;
if ( ! V_161 )
goto V_59;
for ( V_160 = 0 ; V_160 < V_18 -> V_164 ; V_160 ++ ) {
const struct V_165 * V_166 ;
struct V_4 * V_167 , * V_168 ;
V_166 = & V_18 -> V_169 [ V_160 ] ;
V_167 = F_45 ( V_51 , V_160 + 1 ) ;
if ( ! V_167 )
goto V_59;
V_168 = F_45 ( V_51 , V_170 ) ;
if ( ! V_168 )
goto V_59;
for ( V_162 = 0 ; V_162 < V_166 -> V_171 ; V_162 ++ ) {
struct V_4 * V_172 ;
V_172 = F_45 ( V_51 , V_162 + 1 ) ;
if ( ! V_172 )
goto V_59;
if ( F_26 ( V_51 , V_173 ,
V_166 -> V_174 [ V_162 ] . V_175 ) )
goto V_59;
if ( F_44 ( V_51 , V_176 ,
V_166 -> V_174 [ V_162 ] . V_177 ) )
goto V_59;
F_46 ( V_51 , V_172 ) ;
}
F_46 ( V_51 , V_168 ) ;
if ( V_166 -> V_178 &&
F_27 ( V_51 , V_179 ) )
goto V_59;
if ( F_26 ( V_51 , V_180 ,
V_166 -> V_181 ) ||
F_26 ( V_51 , V_182 ,
V_166 -> V_183 ) )
goto V_59;
if ( V_54 &&
( F_26 ( V_51 , V_184 ,
V_166 -> V_185 ) ||
F_26 ( V_51 , V_186 ,
V_166 -> V_187 ) ) )
goto V_59;
if ( V_166 -> V_188 &&
F_26 ( V_51 , V_189 ,
V_166 -> V_188 ) )
goto V_59;
F_46 ( V_51 , V_167 ) ;
}
F_46 ( V_51 , V_161 ) ;
return 0 ;
V_59:
return - V_89 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_31 * V_51 )
{
const struct V_190 * V_191 = V_7 -> V_18 . V_192 -> V_191 ;
struct V_4 * V_193 ;
if ( ! V_191 )
return 0 ;
V_193 = F_45 ( V_51 , V_194 ) ;
if ( ! V_193 )
return - V_89 ;
if ( F_26 ( V_51 , V_195 ,
V_191 -> V_196 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_195 ,
V_191 -> V_196 ) )
return - V_89 ;
if ( V_191 -> V_48 && F_27 ( V_51 , V_197 ) )
return - V_89 ;
if ( V_191 -> V_198 && F_49 ( V_51 , V_199 ,
sizeof( * V_191 -> V_198 ) , V_191 -> V_198 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_200 ,
V_191 -> V_201 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_202 ,
V_191 -> V_203 ) )
return - V_89 ;
F_46 ( V_51 , V_193 ) ;
return 0 ;
}
static int F_50 ( struct V_31 * V_51 ,
struct V_6 * V_7 ,
bool V_54 )
{
struct V_4 * V_204 ;
if ( ! V_7 -> V_18 . V_192 )
return 0 ;
V_204 = F_45 ( V_51 , V_205 ) ;
if ( ! V_204 )
return - V_89 ;
if ( ( ( V_7 -> V_18 . V_192 -> V_49 & V_206 ) &&
F_27 ( V_51 , V_207 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_49 & V_208 ) &&
F_27 ( V_51 , V_209 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_49 & V_210 ) &&
F_27 ( V_51 , V_211 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_49 & V_212 ) &&
F_27 ( V_51 , V_213 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_49 & V_214 ) &&
F_27 ( V_51 , V_215 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_49 & V_216 ) &&
F_27 ( V_51 , V_217 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_49 & V_218 ) &&
F_27 ( V_51 , V_219 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_49 & V_220 ) &&
F_27 ( V_51 , V_221 ) ) )
return - V_89 ;
if ( V_7 -> V_18 . V_192 -> V_222 ) {
struct V_223 V_224 = {
. V_225 = V_7 -> V_18 . V_192 -> V_222 ,
. V_226 = V_7 -> V_18 . V_192 -> V_227 ,
. V_228 = V_7 -> V_18 . V_192 -> V_229 ,
. V_230 = V_7 -> V_18 . V_192 -> V_230 ,
} ;
if ( F_49 ( V_51 , V_231 ,
sizeof( V_224 ) , & V_224 ) )
return - V_89 ;
}
if ( ( V_7 -> V_18 . V_192 -> V_49 & V_232 ) &&
F_26 ( V_51 , V_233 ,
V_7 -> V_18 . V_192 -> V_234 ) )
return - V_89 ;
if ( V_54 && F_48 ( V_7 , V_51 ) )
return - V_89 ;
F_46 ( V_51 , V_204 ) ;
return 0 ;
}
static int F_51 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_235 V_236 ;
if ( ! V_7 -> V_18 . V_237 )
return 0 ;
V_236 . V_238 = V_7 -> V_18 . V_237 -> V_239 ;
V_236 . V_240 = V_7 -> V_18 . V_237 -> V_240 ;
V_236 . V_224 . V_225 = V_7 -> V_18 . V_237 -> V_222 ;
V_236 . V_224 . V_226 = V_7 -> V_18 . V_237 -> V_227 ;
V_236 . V_224 . V_228 = V_7 -> V_18 . V_237 -> V_229 ;
V_236 . V_224 . V_230 = V_7 -> V_18 . V_237 -> V_230 ;
if ( F_49 ( V_51 , V_241 , sizeof( V_236 ) , & V_236 ) )
return - V_89 ;
return 0 ;
}
static int F_52 ( struct V_31 * V_51 ,
struct V_242 * V_243 )
{
struct V_4 * V_244 , * V_245 ;
struct V_246 * V_247 ;
int V_160 ;
if ( V_243 -> V_248 . V_249 &&
( F_49 ( V_51 , V_250 ,
sizeof( V_243 -> V_248 . V_251 ) ,
& V_243 -> V_248 . V_251 ) ||
F_53 ( V_51 , V_252 ,
V_243 -> V_248 . V_253 ) ||
F_54 ( V_51 , V_254 ,
V_243 -> V_248 . V_255 ) ||
F_54 ( V_51 , V_256 ,
V_243 -> V_248 . V_257 ) ) )
return - V_89 ;
if ( V_243 -> V_258 . V_259 &&
( F_49 ( V_51 , V_260 ,
sizeof( V_243 -> V_258 . V_261 ) ,
& V_243 -> V_258 . V_261 ) ||
F_26 ( V_51 , V_262 ,
V_243 -> V_258 . V_253 ) ) )
return - V_89 ;
V_244 = F_45 ( V_51 , V_263 ) ;
if ( ! V_244 )
return - V_89 ;
for ( V_160 = 0 ; V_160 < V_243 -> V_264 ; V_160 ++ ) {
V_245 = F_45 ( V_51 , V_160 ) ;
if ( ! V_245 )
return - V_89 ;
V_247 = & V_243 -> V_265 [ V_160 ] ;
if ( F_26 ( V_51 , V_266 ,
V_247 -> V_267 ) )
return - V_89 ;
if ( ( V_247 -> V_49 & V_268 ) &&
F_27 ( V_51 ,
V_269 ) )
return - V_89 ;
F_46 ( V_51 , V_245 ) ;
}
F_46 ( V_51 , V_244 ) ;
return 0 ;
}
static int
F_55 ( struct V_31 * V_51 ,
const struct V_270 * V_271 )
{
T_3 V_272 ;
struct V_4 * V_273 , * V_274 ;
enum V_275 V_276 ;
int V_160 ;
if ( ! V_271 )
return 0 ;
V_274 = F_45 ( V_51 , V_277 ) ;
if ( ! V_274 )
return - V_89 ;
for ( V_276 = 0 ; V_276 < V_157 ; V_276 ++ ) {
V_273 = F_45 ( V_51 , V_276 ) ;
if ( ! V_273 )
return - V_89 ;
V_160 = 0 ;
V_272 = V_271 [ V_276 ] . V_278 ;
while ( V_272 ) {
if ( ( V_272 & 1 ) &&
F_53 ( V_51 , V_279 ,
( V_160 << 4 ) | V_280 ) )
return - V_89 ;
V_272 >>= 1 ;
V_160 ++ ;
}
F_46 ( V_51 , V_273 ) ;
}
F_46 ( V_51 , V_274 ) ;
V_274 = F_45 ( V_51 , V_281 ) ;
if ( ! V_274 )
return - V_89 ;
for ( V_276 = 0 ; V_276 < V_157 ; V_276 ++ ) {
V_273 = F_45 ( V_51 , V_276 ) ;
if ( ! V_273 )
return - V_89 ;
V_160 = 0 ;
V_272 = V_271 [ V_276 ] . V_282 ;
while ( V_272 ) {
if ( ( V_272 & 1 ) &&
F_53 ( V_51 , V_279 ,
( V_160 << 4 ) | V_280 ) )
return - V_89 ;
V_272 >>= 1 ;
V_160 ++ ;
}
F_46 ( V_51 , V_273 ) ;
}
F_46 ( V_51 , V_274 ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 ,
struct V_31 * V_51 )
{
int V_160 = 0 ;
F_57 ( V_283 , V_284 ) ;
F_57 ( V_285 , V_286 ) ;
F_57 ( V_287 , V_288 ) ;
F_57 ( V_289 , V_290 ) ;
F_57 ( V_291 , V_292 ) ;
F_57 ( V_293 , V_294 ) ;
F_57 ( V_295 , V_296 ) ;
F_57 ( V_297 , V_298 ) ;
F_57 ( V_299 , V_300 ) ;
F_57 ( V_301 , V_302 ) ;
F_57 ( V_303 , V_304 ) ;
F_57 ( V_305 , V_306 ) ;
F_57 ( V_307 , V_308 ) ;
F_57 ( V_309 , V_310 ) ;
F_57 ( V_311 , V_312 ) ;
F_57 ( V_313 , V_314 ) ;
F_57 ( V_315 , V_316 ) ;
if ( V_7 -> V_18 . V_49 & V_317 )
F_57 ( V_318 , V_319 ) ;
F_57 ( V_320 , V_321 ) ;
F_57 ( V_322 , V_323 ) ;
F_57 ( V_324 , V_325 ) ;
if ( V_7 -> V_18 . V_49 & V_326 ) {
V_160 ++ ;
if ( F_26 ( V_51 , V_160 , V_327 ) )
goto V_59;
}
if ( V_7 -> V_328 -> V_329 || V_7 -> V_328 -> V_289 ||
V_7 -> V_328 -> V_309 ) {
V_160 ++ ;
if ( F_26 ( V_51 , V_160 , V_330 ) )
goto V_59;
}
F_57 ( V_331 , V_332 ) ;
if ( V_7 -> V_18 . V_49 & V_333 ) {
F_57 ( V_334 , V_335 ) ;
F_57 ( V_336 , V_337 ) ;
}
if ( V_7 -> V_18 . V_338 )
F_57 ( V_339 , V_340 ) ;
F_57 ( V_341 , V_342 ) ;
F_57 ( V_343 , V_344 ) ;
if ( V_7 -> V_18 . V_49 & V_345 ) {
V_160 ++ ;
if ( F_26 ( V_51 , V_160 , V_346 ) )
goto V_59;
}
F_57 ( V_347 , V_348 ) ;
F_57 ( V_349 , V_350 ) ;
#ifdef F_58
F_57 ( V_351 , V_352 ) ;
#endif
if ( V_7 -> V_328 -> V_353 || V_7 -> V_328 -> V_299 ) {
V_160 ++ ;
if ( F_26 ( V_51 , V_160 , V_354 ) )
goto V_59;
}
if ( V_7 -> V_328 -> V_355 || V_7 -> V_328 -> V_303 ) {
V_160 ++ ;
if ( F_26 ( V_51 , V_160 , V_356 ) )
goto V_59;
}
return V_160 ;
V_59:
return - V_89 ;
}
static int F_59 ( struct V_6 * V_7 ,
enum V_357 V_50 ,
struct V_31 * V_51 , V_22 V_47 , V_22 V_48 ,
int V_49 , struct V_358 * V_359 )
{
void * V_360 ;
struct V_4 * V_361 , * V_362 ;
struct V_4 * V_363 , * V_364 ;
struct V_4 * V_365 ;
enum V_366 V_367 ;
struct V_52 * V_53 ;
int V_160 ;
const struct V_270 * V_271 =
V_7 -> V_18 . V_271 ;
V_22 V_368 ;
V_360 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_360 )
return - V_89 ;
if ( F_60 ( ! V_359 ) )
return - V_16 ;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_61 ( V_51 , V_369 ,
F_62 ( & V_7 -> V_18 ) ) ||
F_26 ( V_51 , V_370 ,
V_371 ) )
goto V_59;
if ( V_50 != V_372 )
goto V_373;
switch ( V_359 -> V_374 ) {
case 0 :
if ( F_54 ( V_51 , V_375 ,
V_7 -> V_18 . V_376 ) ||
F_54 ( V_51 , V_377 ,
V_7 -> V_18 . V_378 ) ||
F_26 ( V_51 , V_379 ,
V_7 -> V_18 . V_380 ) ||
F_26 ( V_51 , V_381 ,
V_7 -> V_18 . V_382 ) ||
F_54 ( V_51 , V_383 ,
V_7 -> V_18 . V_384 ) ||
F_54 ( V_51 , V_385 ,
V_7 -> V_18 . V_386 ) ||
F_54 ( V_51 , V_387 ,
V_7 -> V_18 . V_388 ) ||
F_53 ( V_51 , V_389 ,
V_7 -> V_18 . V_390 ) ||
F_53 ( V_51 , V_391 ,
V_7 -> V_18 . V_392 ) ||
F_54 ( V_51 , V_393 ,
V_7 -> V_18 . V_394 ) ||
F_26 ( V_51 , V_395 ,
V_7 -> V_18 . V_396 ) ||
F_26 ( V_51 , V_397 ,
V_7 -> V_18 . V_398 ) ||
F_26 ( V_51 , V_399 ,
V_7 -> V_18 . V_400 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_401 ) &&
F_27 ( V_51 , V_402 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_403 ) &&
F_27 ( V_51 , V_404 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_405 ) &&
F_27 ( V_51 , V_406 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_407 ) &&
F_27 ( V_51 , V_408 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_333 ) &&
F_27 ( V_51 , V_409 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_410 ) &&
F_27 ( V_51 , V_411 ) )
goto V_59;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 1 :
if ( F_49 ( V_51 , V_413 ,
sizeof( V_22 ) * V_7 -> V_18 . V_414 ,
V_7 -> V_18 . V_415 ) )
goto V_59;
if ( F_54 ( V_51 , V_416 ,
V_7 -> V_18 . V_417 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_418 ) &&
F_27 ( V_51 , V_419 ) )
goto V_59;
if ( F_26 ( V_51 , V_420 ,
V_7 -> V_18 . V_421 ) ||
F_26 ( V_51 , V_422 ,
V_7 -> V_18 . V_423 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_424 ) &&
F_26 ( V_51 , V_425 ,
V_7 -> V_18 . V_426 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_421 ||
V_7 -> V_18 . V_423 ) &&
V_7 -> V_328 -> V_427 ) {
V_22 V_428 = 0 , V_429 = 0 ;
int V_430 ;
V_430 = F_63 ( V_7 , & V_428 , & V_429 ) ;
if ( ! V_430 ) {
if ( F_26 ( V_51 ,
V_431 ,
V_428 ) ||
F_26 ( V_51 ,
V_432 ,
V_429 ) )
goto V_59;
}
}
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 2 :
if ( F_44 ( V_51 , V_433 ,
V_7 -> V_18 . V_434 ) )
goto V_59;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 3 :
V_361 = F_45 ( V_51 , V_435 ) ;
if ( ! V_361 )
goto V_59;
for ( V_367 = V_359 -> V_436 ;
V_367 < V_437 ; V_367 ++ ) {
struct V_242 * V_243 ;
V_243 = V_7 -> V_18 . V_438 [ V_367 ] ;
if ( ! V_243 )
continue;
V_362 = F_45 ( V_51 , V_367 ) ;
if ( ! V_362 )
goto V_59;
switch ( V_359 -> V_439 ) {
case 0 :
if ( F_52 ( V_51 , V_243 ) )
goto V_59;
V_359 -> V_439 ++ ;
if ( V_359 -> V_412 )
break;
default:
V_363 = F_45 (
V_51 , V_440 ) ;
if ( ! V_363 )
goto V_59;
for ( V_160 = V_359 -> V_439 - 1 ;
V_160 < V_243 -> V_441 ;
V_160 ++ ) {
V_364 = F_45 ( V_51 , V_160 ) ;
if ( ! V_364 )
goto V_59;
V_53 = & V_243 -> V_442 [ V_160 ] ;
if ( F_25 (
V_51 , V_53 ,
V_359 -> V_412 ) )
goto V_59;
F_46 ( V_51 , V_364 ) ;
if ( V_359 -> V_412 )
break;
}
if ( V_160 < V_243 -> V_441 )
V_359 -> V_439 = V_160 + 2 ;
else
V_359 -> V_439 = 0 ;
F_46 ( V_51 , V_363 ) ;
}
F_46 ( V_51 , V_362 ) ;
if ( V_359 -> V_412 ) {
if ( V_359 -> V_439 )
V_367 -- ;
break;
}
}
F_46 ( V_51 , V_361 ) ;
if ( V_367 < V_437 )
V_359 -> V_436 = V_367 + 1 ;
else
V_359 -> V_436 = 0 ;
if ( V_359 -> V_436 == 0 && V_359 -> V_439 == 0 )
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 4 :
V_365 = F_45 ( V_51 , V_443 ) ;
if ( ! V_365 )
goto V_59;
V_160 = F_56 ( V_7 , V_51 ) ;
if ( V_160 < 0 )
goto V_59;
if ( V_359 -> V_412 ) {
F_57 ( V_444 , V_445 ) ;
F_57 ( V_446 , V_447 ) ;
if ( V_7 -> V_18 . V_49 & V_448 )
F_57 ( V_449 , V_450 ) ;
F_57 ( V_451 , V_452 ) ;
if ( V_7 -> V_18 . V_368 &
V_453 )
F_57 ( V_454 , V_455 ) ;
F_57 ( V_456 , V_457 ) ;
F_57 ( V_458 , V_459 ) ;
}
#undef F_57
F_46 ( V_51 , V_365 ) ;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 5 :
if ( V_7 -> V_328 -> V_318 &&
( V_7 -> V_18 . V_49 & V_317 ) &&
F_26 ( V_51 ,
V_460 ,
V_7 -> V_18 . V_461 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_462 ) &&
F_27 ( V_51 , V_463 ) )
goto V_59;
if ( F_55 ( V_51 , V_271 ) )
goto V_59;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 6 :
#ifdef F_64
if ( F_50 ( V_51 , V_7 , V_359 -> V_412 ) )
goto V_59;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
#else
V_359 -> V_374 ++ ;
#endif
case 7 :
if ( F_44 ( V_51 , V_464 ,
V_7 -> V_18 . V_465 ) )
goto V_59;
if ( F_47 ( & V_7 -> V_18 , V_51 ,
V_359 -> V_412 ) )
goto V_59;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_49 & V_466 ) &&
F_26 ( V_51 , V_467 ,
V_7 -> V_18 . V_468 ) )
goto V_59;
V_368 = V_7 -> V_18 . V_368 ;
if ( V_359 -> V_412 )
V_368 |= V_469 ;
if ( F_26 ( V_51 , V_470 , V_368 ) )
goto V_59;
if ( V_7 -> V_18 . V_471 &&
F_49 ( V_51 , V_472 ,
sizeof( * V_7 -> V_18 . V_471 ) ,
V_7 -> V_18 . V_471 ) )
goto V_59;
if ( V_7 -> V_18 . V_49 & V_466 &&
V_7 -> V_18 . V_473 &&
F_26 ( V_51 , V_474 ,
V_7 -> V_18 . V_473 ) )
goto V_59;
V_359 -> V_374 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_475 &&
( F_49 ( V_51 , V_476 ,
V_7 -> V_18 . V_477 ,
V_7 -> V_18 . V_475 ) ||
F_49 ( V_51 , V_478 ,
V_7 -> V_18 . V_477 ,
V_7 -> V_18 . V_479 ) ) )
goto V_59;
if ( V_7 -> V_18 . V_480 &&
F_49 ( V_51 , V_481 ,
sizeof( * V_7 -> V_18 . V_480 ) ,
V_7 -> V_18 . V_480 ) )
goto V_59;
V_359 -> V_374 ++ ;
break;
case 10 :
if ( F_51 ( V_51 , V_7 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_482 ) &&
( F_27 ( V_51 , V_483 ) ||
F_27 ( V_51 , V_484 ) ) )
goto V_59;
if ( V_7 -> V_18 . V_485 &&
F_26 ( V_51 , V_486 ,
V_7 -> V_18 . V_485 ) )
goto V_59;
V_359 -> V_374 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_487 ) {
const struct V_488 * V_30 ;
struct V_4 * V_489 ;
V_489 = F_45 ( V_51 , V_490 ) ;
if ( ! V_489 )
goto V_59;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_487 ; V_160 ++ ) {
V_30 = & V_7 -> V_18 . V_491 [ V_160 ] . V_30 ;
if ( F_49 ( V_51 , V_160 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_46 ( V_51 , V_489 ) ;
}
if ( V_7 -> V_18 . V_492 ) {
const struct V_488 * V_30 ;
struct V_4 * V_489 ;
V_489 = F_45 ( V_51 ,
V_493 ) ;
if ( ! V_489 )
goto V_59;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_492 ; V_160 ++ ) {
V_30 = & V_7 -> V_18 . V_494 [ V_160 ] ;
if ( F_49 ( V_51 , V_160 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_46 ( V_51 , V_489 ) ;
}
V_359 -> V_374 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_49 & V_448 &&
F_54 ( V_51 , V_495 ,
V_7 -> V_18 . V_496 ) )
goto V_59;
if ( V_7 -> V_18 . V_497 & V_498 &&
F_27 ( V_51 , V_499 ) )
goto V_59;
if ( V_7 -> V_18 . V_338 &&
F_26 ( V_51 , V_500 ,
V_7 -> V_18 . V_338 ) )
goto V_59;
if ( F_49 ( V_51 , V_501 ,
sizeof( V_7 -> V_18 . V_502 ) ,
V_7 -> V_18 . V_502 ) )
goto V_59;
if ( V_7 -> V_18 . V_503 ) {
struct V_4 * V_489 ;
V_22 V_503 = V_7 -> V_18 . V_503 ;
V_489 = F_45 ( V_51 , V_504 ) ;
if ( ! V_489 )
goto V_59;
V_160 = 0 ;
while ( V_503 ) {
if ( ( V_503 & 1 ) &&
F_27 ( V_51 , V_160 ) )
goto V_59;
V_160 ++ ;
V_503 >>= 1 ;
}
F_46 ( V_51 , V_489 ) ;
}
V_359 -> V_374 ++ ;
break;
case 13 :
if ( V_7 -> V_18 . V_505 &&
V_7 -> V_18 . V_506 ) {
struct V_4 * V_507 , * V_489 ;
V_489 = F_45 ( V_51 ,
V_508 ) ;
if ( ! V_489 )
goto V_59;
for ( V_160 = V_359 -> V_509 ;
V_160 < V_7 -> V_18 . V_505 ; V_160 ++ ) {
const struct V_510 * V_511 ;
V_511 = & V_7 -> V_18 . V_506 [ V_160 ] ;
V_507 = F_45 ( V_51 , V_160 ) ;
if ( ! V_507 ||
F_26 ( V_51 , V_512 ,
V_511 -> V_141 ) ||
F_49 ( V_51 , V_476 ,
V_511 -> V_477 ,
V_511 -> V_475 ) ||
F_49 ( V_51 , V_478 ,
V_511 -> V_477 ,
V_511 -> V_479 ) )
goto V_59;
F_46 ( V_51 , V_507 ) ;
if ( V_359 -> V_412 )
break;
}
F_46 ( V_51 , V_489 ) ;
if ( V_160 < V_7 -> V_18 . V_505 ) {
V_359 -> V_509 = V_160 + 1 ;
break;
}
}
if ( F_26 ( V_51 , V_513 ,
V_7 -> V_18 . V_514 ) )
goto V_59;
V_359 -> V_374 = 0 ;
break;
}
V_373:
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int F_67 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_358 * V_359 )
{
struct V_4 * * V_93 = F_15 ( & V_38 ) ;
int V_516 = F_14 ( V_34 -> V_36 , V_37 + V_38 . V_39 , V_93 ,
V_38 . V_40 , V_41 , NULL ) ;
if ( V_516 )
return 0 ;
V_359 -> V_412 = V_93 [ V_517 ] ;
if ( V_93 [ V_26 ] )
V_359 -> V_518 = F_4 ( V_93 [ V_26 ] ) ;
if ( V_93 [ V_12 ] )
V_359 -> V_518 = F_5 ( V_93 [ V_12 ] ) >> 32 ;
if ( V_93 [ V_10 ] ) {
struct V_25 * V_19 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_93 [ V_10 ] ) ;
V_19 = F_10 ( F_16 ( V_32 -> V_42 ) , V_15 ) ;
if ( ! V_19 )
return - V_23 ;
if ( V_19 -> V_28 ) {
V_7 = F_11 (
V_19 -> V_28 -> V_18 ) ;
V_359 -> V_518 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_68 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_103 = 0 , V_516 ;
struct V_358 * V_359 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_69 () ;
if ( ! V_359 ) {
V_359 = F_37 ( sizeof( * V_359 ) , V_135 ) ;
if ( ! V_359 ) {
F_70 () ;
return - V_136 ;
}
V_359 -> V_518 = - 1 ;
V_516 = F_67 ( V_32 , V_34 , V_359 ) ;
if ( V_516 ) {
F_39 ( V_359 ) ;
F_70 () ;
return V_516 ;
}
V_34 -> args [ 0 ] = ( long ) V_359 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_42 ) ) )
continue;
if ( ++ V_103 <= V_359 -> V_519 )
continue;
if ( V_359 -> V_518 != - 1 &&
V_359 -> V_518 != V_7 -> V_14 )
continue;
do {
V_516 = F_59 ( V_7 , V_372 ,
V_32 ,
F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 ,
V_521 , V_359 ) ;
if ( V_516 < 0 ) {
if ( ( V_516 == - V_89 || V_516 == - V_515 ) &&
! V_32 -> V_45 && ! V_359 -> V_412 &&
V_34 -> V_522 < 4096 ) {
V_34 -> V_522 = 4096 ;
V_359 -> V_374 = 0 ;
F_70 () ;
return 1 ;
}
V_103 -- ;
break;
}
} while ( V_359 -> V_374 > 0 );
break;
}
F_70 () ;
V_359 -> V_519 = V_103 ;
return V_32 -> V_45 ;
}
static int F_73 ( struct V_33 * V_34 )
{
F_39 ( ( void * ) V_34 -> args [ 0 ] ) ;
return 0 ;
}
static int F_74 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_51 ;
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_358 V_359 = {} ;
V_51 = F_75 ( 4096 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
if ( F_59 ( V_7 , V_372 , V_51 ,
V_30 -> V_524 , V_30 -> V_525 , 0 ,
& V_359 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_78 ( struct V_4 * V_93 [] ,
struct V_526 * V_527 )
{
if ( ! V_93 [ V_528 ] || ! V_93 [ V_529 ] ||
! V_93 [ V_530 ] || ! V_93 [ V_531 ] ||
! V_93 [ V_532 ] )
return - V_16 ;
V_527 -> V_533 = F_32 ( V_93 [ V_528 ] ) ;
V_527 -> V_534 = F_79 ( V_93 [ V_529 ] ) ;
V_527 -> V_535 = F_79 ( V_93 [ V_530 ] ) ;
V_527 -> V_536 = F_79 ( V_93 [ V_531 ] ) ;
V_527 -> V_537 = F_32 ( V_93 [ V_532 ] ) ;
if ( V_527 -> V_533 >= V_538 )
return - V_16 ;
return 0 ;
}
static bool F_80 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_141 == V_142 ||
V_17 -> V_141 == V_145 ||
V_17 -> V_141 == V_153 ||
V_17 -> V_141 == V_144 ;
}
static int F_81 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_539 * V_540 )
{
V_22 V_541 ;
if ( ! V_30 -> V_5 [ V_542 ] )
return - V_16 ;
V_541 = F_4 ( V_30 -> V_5 [ V_542 ] ) ;
V_540 -> V_53 = F_43 ( & V_7 -> V_18 , V_541 ) ;
V_540 -> V_543 = V_544 ;
V_540 -> V_545 = V_541 ;
V_540 -> V_546 = 0 ;
if ( ! V_540 -> V_53 || V_540 -> V_53 -> V_49 & V_60 )
return - V_16 ;
if ( V_30 -> V_5 [ V_547 ] ) {
enum V_548 V_549 ;
V_549 = F_4 (
V_30 -> V_5 [ V_547 ] ) ;
switch ( V_549 ) {
case V_550 :
case V_551 :
case V_552 :
case V_553 :
F_82 ( V_540 , V_540 -> V_53 ,
V_549 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_554 ] ) {
V_540 -> V_543 =
F_4 ( V_30 -> V_5 [ V_554 ] ) ;
if ( V_30 -> V_5 [ V_555 ] )
V_540 -> V_545 =
F_4 (
V_30 -> V_5 [ V_555 ] ) ;
if ( V_30 -> V_5 [ V_556 ] )
V_540 -> V_546 =
F_4 (
V_30 -> V_5 [ V_556 ] ) ;
}
if ( ! F_83 ( V_540 ) )
return - V_16 ;
if ( ! F_84 ( & V_7 -> V_18 , V_540 ,
V_60 ) )
return - V_16 ;
if ( ( V_540 -> V_543 == V_557 ||
V_540 -> V_543 == V_558 ) &&
! ( V_7 -> V_18 . V_49 & V_482 ) )
return - V_16 ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 ,
struct V_25 * V_559 ,
struct V_29 * V_30 )
{
struct V_539 V_540 ;
int V_8 ;
enum V_275 V_141 = V_153 ;
struct V_1 * V_17 = NULL ;
if ( V_559 )
V_17 = V_559 -> V_28 ;
if ( ! F_80 ( V_17 ) )
return - V_560 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_81 ( V_7 , V_30 , & V_540 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_86 ( & V_7 -> V_18 , & V_540 ,
V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_561 ) {
if ( ! V_559 || ! V_7 -> V_328 -> V_562 ||
! ( V_7 -> V_18 . V_368 &
V_563 ) ) {
V_8 = - V_564 ;
break;
}
if ( V_540 . V_53 != V_17 -> V_565 . V_53 ) {
V_8 = - V_564 ;
break;
}
V_8 = F_87 ( V_7 , V_559 , & V_540 ) ;
if ( V_8 )
break;
}
V_17 -> V_565 = V_540 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_88 ( V_7 , V_17 , & V_540 ) ;
break;
case V_153 :
V_8 = F_89 ( V_7 , & V_540 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_523 [ 1 ] ;
return F_85 ( V_7 , V_19 , V_30 ) ;
}
static int F_91 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
const T_2 * V_566 ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( F_92 ( V_559 ) )
return - V_564 ;
if ( ! V_7 -> V_328 -> V_331 )
return - V_560 ;
if ( V_17 -> V_141 != V_156 )
return - V_560 ;
V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
return F_93 ( V_7 , V_559 , V_566 ) ;
}
static int F_94 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_568 = 0 ;
struct V_4 * V_569 ;
V_22 V_570 ;
T_2 V_376 = 0 , V_378 = 0 ;
V_22 V_380 = 0 , V_382 = 0 ;
T_2 V_384 = 0 ;
F_2 () ;
if ( V_30 -> V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_30 -> V_5 [ V_10 ] ) ;
V_19 = F_10 ( F_95 ( V_30 ) , V_20 ) ;
if ( V_19 && V_19 -> V_28 )
V_7 = F_11 ( V_19 -> V_28 -> V_18 ) ;
else
V_19 = NULL ;
}
if ( ! V_19 ) {
V_7 = F_8 ( F_95 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_7 ) )
return F_18 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_369 ] )
V_8 = F_96 (
V_7 , F_21 ( V_30 -> V_5 [ V_369 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_571 ] ) {
struct V_526 V_527 ;
struct V_4 * V_93 [ V_572 + 1 ] ;
if ( ! V_7 -> V_328 -> V_573 )
return - V_560 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_92 ( V_19 ) )
return - V_574 ;
F_36 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_31 ( V_93 , V_572 ,
V_569 ,
V_575 ,
V_30 -> V_127 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_78 ( V_93 , & V_527 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_527 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_542 ] ) {
V_8 = F_85 (
V_7 ,
F_80 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_576 ] ) {
struct V_1 * V_577 = V_17 ;
enum V_578 type ;
int V_103 , V_579 = 0 ;
if ( ! ( V_7 -> V_18 . V_368 & V_580 ) )
V_577 = NULL ;
if ( ! V_7 -> V_328 -> V_581 )
return - V_560 ;
V_103 = V_576 ;
type = F_4 ( V_30 -> V_5 [ V_103 ] ) ;
if ( ! V_30 -> V_5 [ V_582 ] &&
( type != V_583 ) )
return - V_16 ;
if ( type != V_583 ) {
V_103 = V_582 ;
V_579 = F_4 ( V_30 -> V_5 [ V_103 ] ) ;
}
V_8 = F_98 ( V_7 , V_577 , type , V_579 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_431 ] &&
V_30 -> V_5 [ V_432 ] ) {
V_22 V_428 , V_429 ;
if ( ( ! V_7 -> V_18 . V_421 &&
! V_7 -> V_18 . V_423 ) ||
! V_7 -> V_328 -> V_584 )
return - V_560 ;
V_428 = F_4 ( V_30 -> V_5 [ V_431 ] ) ;
V_429 = F_4 ( V_30 -> V_5 [ V_432 ] ) ;
if ( ( ~ V_428 && ( V_428 & ~ V_7 -> V_18 . V_421 ) ) ||
( ~ V_429 && ( V_429 & ~ V_7 -> V_18 . V_423 ) ) )
return - V_16 ;
V_428 = V_428 & V_7 -> V_18 . V_421 ;
V_429 = V_429 & V_7 -> V_18 . V_423 ;
V_8 = F_99 ( V_7 , V_428 , V_429 ) ;
if ( V_8 )
return V_8 ;
}
V_570 = 0 ;
if ( V_30 -> V_5 [ V_375 ] ) {
V_376 = F_32 (
V_30 -> V_5 [ V_375 ] ) ;
if ( V_376 == 0 )
return - V_16 ;
V_570 |= V_585 ;
}
if ( V_30 -> V_5 [ V_377 ] ) {
V_378 = F_32 (
V_30 -> V_5 [ V_377 ] ) ;
if ( V_378 == 0 )
return - V_16 ;
V_570 |= V_586 ;
}
if ( V_30 -> V_5 [ V_379 ] ) {
V_380 = F_4 (
V_30 -> V_5 [ V_379 ] ) ;
if ( V_380 < 256 )
return - V_16 ;
if ( V_380 != ( V_22 ) - 1 ) {
V_380 &= ~ 0x1 ;
}
V_570 |= V_587 ;
}
if ( V_30 -> V_5 [ V_381 ] ) {
V_382 = F_4 (
V_30 -> V_5 [ V_381 ] ) ;
V_570 |= V_588 ;
}
if ( V_30 -> V_5 [ V_383 ] ) {
if ( V_30 -> V_5 [ V_589 ] )
return - V_16 ;
V_384 = F_32 (
V_30 -> V_5 [ V_383 ] ) ;
V_570 |= V_590 ;
}
if ( V_30 -> V_5 [ V_589 ] ) {
if ( ! ( V_7 -> V_18 . V_368 & V_591 ) )
return - V_560 ;
V_570 |= V_592 ;
}
if ( V_570 ) {
T_2 V_593 , V_594 ;
V_22 V_595 , V_596 ;
T_2 V_597 ;
if ( ! V_7 -> V_328 -> V_598 )
return - V_560 ;
V_593 = V_7 -> V_18 . V_376 ;
V_594 = V_7 -> V_18 . V_378 ;
V_595 = V_7 -> V_18 . V_380 ;
V_596 = V_7 -> V_18 . V_382 ;
V_597 = V_7 -> V_18 . V_384 ;
if ( V_570 & V_585 )
V_7 -> V_18 . V_376 = V_376 ;
if ( V_570 & V_586 )
V_7 -> V_18 . V_378 = V_378 ;
if ( V_570 & V_587 )
V_7 -> V_18 . V_380 = V_380 ;
if ( V_570 & V_588 )
V_7 -> V_18 . V_382 = V_382 ;
if ( V_570 & V_590 )
V_7 -> V_18 . V_384 = V_384 ;
V_8 = F_100 ( V_7 , V_570 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_376 = V_593 ;
V_7 -> V_18 . V_378 = V_594 ;
V_7 -> V_18 . V_380 = V_595 ;
V_7 -> V_18 . V_382 = V_596 ;
V_7 -> V_18 . V_384 = V_597 ;
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
static int F_101 ( struct V_31 * V_51 ,
const struct V_539 * V_540 )
{
if ( F_60 ( ! F_83 ( V_540 ) ) )
return - V_16 ;
if ( F_26 ( V_51 , V_542 ,
V_540 -> V_53 -> V_58 ) )
return - V_89 ;
switch ( V_540 -> V_543 ) {
case V_544 :
case V_599 :
case V_600 :
if ( F_26 ( V_51 , V_547 ,
F_102 ( V_540 ) ) )
return - V_89 ;
break;
default:
break;
}
if ( F_26 ( V_51 , V_554 , V_540 -> V_543 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_555 , V_540 -> V_545 ) )
return - V_89 ;
if ( V_540 -> V_546 &&
F_26 ( V_51 , V_556 , V_540 -> V_546 ) )
return - V_89 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_51 , V_22 V_47 , V_22 V_48 , int V_49 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_601 )
{
struct V_25 * V_559 = V_17 -> V_19 ;
T_2 V_50 = V_602 ;
void * V_360 ;
if ( V_601 )
V_50 = V_603 ;
V_360 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_360 )
return - 1 ;
if ( V_559 &&
( F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_61 ( V_51 , V_604 , V_559 -> V_605 ) ) )
goto V_59;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_512 , V_17 -> V_141 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) ||
F_49 ( V_51 , V_567 , V_607 , F_105 ( V_17 ) ) ||
F_26 ( V_51 , V_370 ,
V_7 -> V_608 ^
( V_371 << 2 ) ) )
goto V_59;
if ( V_7 -> V_328 -> V_609 ) {
int V_516 ;
struct V_539 V_540 ;
V_516 = F_106 ( V_7 , V_17 , & V_540 ) ;
if ( V_516 == 0 ) {
if ( F_101 ( V_51 , & V_540 ) )
goto V_59;
}
}
if ( V_7 -> V_328 -> V_610 ) {
int V_611 , V_516 ;
V_516 = F_107 ( V_7 , V_17 , & V_611 ) ;
if ( V_516 == 0 &&
F_26 ( V_51 , V_582 ,
F_29 ( V_611 ) ) )
goto V_59;
}
if ( V_17 -> V_612 ) {
if ( F_49 ( V_51 , V_613 , V_17 -> V_612 , V_17 -> V_614 ) )
goto V_59;
}
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_615 = 0 ;
int V_616 = 0 ;
int V_617 = V_34 -> args [ 0 ] ;
int V_618 = V_34 -> args [ 1 ] ;
int V_518 = - 1 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_516 ;
F_69 () ;
if ( ! V_34 -> args [ 2 ] ) {
struct V_358 V_359 = {
. V_518 = - 1 ,
} ;
V_516 = F_67 ( V_32 , V_34 , & V_359 ) ;
if ( V_516 )
goto V_619;
V_518 = V_359 . V_518 ;
if ( V_518 >= 0 )
V_34 -> args [ 2 ] = V_518 + 1 ;
else
V_34 -> args [ 2 ] = - 1 ;
} else if ( V_34 -> args [ 2 ] > 0 ) {
V_518 = V_34 -> args [ 2 ] - 1 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_42 ) ) )
continue;
if ( V_615 < V_617 ) {
V_615 ++ ;
continue;
}
if ( V_518 >= 0 && V_518 != V_7 -> V_14 )
continue;
V_616 = 0 ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_616 < V_618 ) {
V_616 ++ ;
continue;
}
if ( F_103 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_7 , V_17 , false ) < 0 ) {
goto V_620;
}
V_616 ++ ;
}
V_615 ++ ;
}
V_620:
V_34 -> args [ 0 ] = V_615 ;
V_34 -> args [ 1 ] = V_616 ;
V_516 = V_32 -> V_45 ;
V_619:
F_70 () ;
return V_516 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_51 ;
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
if ( F_103 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_110 ( struct V_4 * V_622 , V_22 * V_623 )
{
struct V_4 * V_49 [ V_624 + 1 ] ;
int V_625 ;
* V_623 = 0 ;
if ( ! V_622 )
return - V_16 ;
if ( F_31 ( V_49 , V_624 , V_622 ,
V_626 , NULL ) )
return - V_16 ;
for ( V_625 = 1 ; V_625 <= V_624 ; V_625 ++ )
if ( V_49 [ V_625 ] )
* V_623 |= ( 1 << V_625 ) ;
* V_623 |= V_627 ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 ,
enum V_275 type ,
struct V_29 * V_30 ,
struct V_628 * V_139 )
{
bool V_629 = false ;
int V_35 ;
if ( V_30 -> V_5 [ V_630 ] ) {
if ( type != V_153 )
return - V_16 ;
V_35 = F_110 ( V_30 -> V_5 [ V_630 ] ,
& V_139 -> V_49 ) ;
if ( V_35 )
return V_35 ;
V_629 = true ;
}
if ( V_139 -> V_49 & V_631 &&
! ( V_7 -> V_18 . V_368 & V_632 ) )
return - V_560 ;
if ( V_30 -> V_5 [ V_633 ] ) {
const T_2 * V_634 ;
V_22 V_635 = V_636 ;
if ( type != V_153 )
return - V_16 ;
if ( ! F_112 ( & V_7 -> V_18 , V_635 ) )
return - V_560 ;
V_634 =
F_21 ( V_30 -> V_5 [ V_633 ] ) ;
if ( ( V_634 [ 0 ] & F_113 ( 0 ) ) ||
( V_634 [ V_637 - 1 ] & F_113 ( 7 ) ) )
return - V_16 ;
V_139 -> V_638 = V_634 ;
V_629 = true ;
}
if ( V_30 -> V_5 [ V_639 ] ) {
V_22 V_635 = V_636 ;
if ( type != V_153 )
return - V_16 ;
if ( ! F_112 ( & V_7 -> V_18 , V_635 ) )
return - V_560 ;
V_139 -> V_640 =
F_21 ( V_30 -> V_5 [ V_639 ] ) ;
V_629 = true ;
}
return V_629 ? 1 : 0 ;
}
static int F_114 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_641 ,
enum V_275 V_141 )
{
if ( ! V_641 ) {
if ( V_19 && ( V_19 -> V_642 & V_643 ) )
return - V_564 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_49 & V_644 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_49 & V_645 )
return 0 ;
break;
default:
break;
}
return - V_560 ;
}
static int F_115 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_628 V_139 ;
int V_35 ;
enum V_275 V_646 , V_647 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
bool V_629 = false ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_646 = V_647 = V_559 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_512 ] ) {
V_647 = F_4 ( V_30 -> V_5 [ V_512 ] ) ;
if ( V_646 != V_647 )
V_629 = true ;
if ( V_647 > V_648 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_649 ] ) {
struct V_1 * V_17 = V_559 -> V_28 ;
if ( V_647 != V_145 )
return - V_16 ;
if ( F_92 ( V_559 ) )
return - V_564 ;
F_116 ( V_17 ) ;
F_117 ( V_650 !=
V_651 ) ;
V_17 -> V_652 =
F_22 ( V_30 -> V_5 [ V_649 ] ) ;
memcpy ( V_17 -> V_614 , F_21 ( V_30 -> V_5 [ V_649 ] ) ,
V_17 -> V_652 ) ;
F_118 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_653 ] ) {
V_139 . V_641 = ! ! F_32 ( V_30 -> V_5 [ V_653 ] ) ;
V_629 = true ;
V_35 = F_114 ( V_7 , V_559 , V_139 . V_641 , V_647 ) ;
if ( V_35 )
return V_35 ;
} else {
V_139 . V_641 = - 1 ;
}
V_35 = F_111 ( V_7 , V_647 , V_30 , & V_139 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_629 = true ;
if ( V_629 )
V_35 = F_119 ( V_7 , V_559 , V_647 , & V_139 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_139 . V_641 != - 1 )
V_559 -> V_28 -> V_641 = V_139 . V_641 ;
return V_35 ;
}
static int F_120 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_628 V_139 ;
struct V_1 * V_17 ;
struct V_31 * V_51 ;
int V_35 ;
enum V_275 type = V_151 ;
F_121 ( V_7 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_30 -> V_5 [ V_604 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_512 ] ) {
type = F_4 ( V_30 -> V_5 [ V_512 ] ) ;
if ( type > V_648 )
return - V_16 ;
}
if ( ! V_7 -> V_328 -> V_283 ||
! ( V_7 -> V_18 . V_434 & ( 1 << type ) ) )
return - V_560 ;
if ( ( type == V_155 || type == V_154 ||
V_7 -> V_18 . V_368 & V_654 ) &&
V_30 -> V_5 [ V_567 ] ) {
F_122 ( V_139 . V_655 , V_30 -> V_5 [ V_567 ] ,
V_607 ) ;
if ( ! F_123 ( V_139 . V_655 ) )
return - V_656 ;
}
if ( V_30 -> V_5 [ V_653 ] ) {
V_139 . V_641 = ! ! F_32 ( V_30 -> V_5 [ V_653 ] ) ;
V_35 = F_114 ( V_7 , NULL , V_139 . V_641 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_111 ( V_7 , type , V_30 , & V_139 ) ;
if ( V_35 < 0 )
return V_35 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_17 = F_124 ( V_7 ,
F_21 ( V_30 -> V_5 [ V_604 ] ) ,
V_657 , type , & V_139 ) ;
if ( F_60 ( ! V_17 ) ) {
F_76 ( V_51 ) ;
return - V_658 ;
} else if ( F_17 ( V_17 ) ) {
F_76 ( V_51 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_659 ] )
V_17 -> V_660 = V_30 -> V_524 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_649 ] )
break;
F_116 ( V_17 ) ;
F_117 ( V_650 !=
V_651 ) ;
V_17 -> V_652 =
F_22 ( V_30 -> V_5 [ V_649 ] ) ;
memcpy ( V_17 -> V_614 , F_21 ( V_30 -> V_5 [ V_649 ] ) ,
V_17 -> V_652 ) ;
F_118 ( V_17 ) ;
break;
case V_154 :
case V_155 :
F_125 ( & V_17 -> V_661 ) ;
F_126 ( & V_17 -> V_662 ) ;
F_127 ( & V_17 -> V_663 ) ;
F_126 ( & V_17 -> V_664 ) ;
F_127 ( & V_17 -> V_665 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_128 ( & V_17 -> V_666 , & V_7 -> V_18 . V_667 ) ;
V_7 -> V_608 ++ ;
break;
default:
break;
}
if ( F_103 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
if ( ! V_17 -> V_19 )
F_129 ( V_7 , V_17 , V_602 ) ;
return F_77 ( V_51 , V_30 ) ;
}
static int F_130 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_668 )
return - V_560 ;
if ( ! V_17 -> V_19 )
V_30 -> V_523 [ 1 ] = NULL ;
return F_131 ( V_7 , V_17 ) ;
}
static int F_132 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_3 V_669 ;
if ( ! V_30 -> V_5 [ V_670 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_343 )
return - V_560 ;
V_669 = F_79 ( V_30 -> V_5 [ V_670 ] ) ;
return F_133 ( V_7 , V_559 , V_669 ) ;
}
static void F_134 ( void * V_166 , struct V_671 * V_139 )
{
struct V_4 * V_90 ;
struct V_672 * V_673 = V_166 ;
if ( ( V_139 -> V_90 &&
F_49 ( V_673 -> V_51 , V_119 ,
V_139 -> V_106 , V_139 -> V_90 ) ) ||
( V_139 -> V_48 &&
F_49 ( V_673 -> V_51 , V_120 ,
V_139 -> V_108 , V_139 -> V_48 ) ) ||
( V_139 -> V_110 &&
F_26 ( V_673 -> V_51 , V_122 ,
V_139 -> V_110 ) ) )
goto V_59;
V_90 = F_45 ( V_673 -> V_51 , V_128 ) ;
if ( ! V_90 )
goto V_59;
if ( ( V_139 -> V_90 &&
F_49 ( V_673 -> V_51 , V_104 ,
V_139 -> V_106 , V_139 -> V_90 ) ) ||
( V_139 -> V_48 &&
F_49 ( V_673 -> V_51 , V_107 ,
V_139 -> V_108 , V_139 -> V_48 ) ) ||
( V_139 -> V_110 &&
F_26 ( V_673 -> V_51 , V_109 ,
V_139 -> V_110 ) ) )
goto V_59;
if ( F_54 ( V_673 -> V_51 , V_121 , V_673 -> V_103 ) )
goto V_59;
F_46 ( V_673 -> V_51 , V_90 ) ;
return;
V_59:
V_673 -> error = 1 ;
}
static int F_135 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int V_35 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 V_674 = 0 ;
const T_2 * V_675 = NULL ;
bool V_676 ;
struct V_672 V_673 = {
. error = 0 ,
} ;
void * V_360 ;
struct V_31 * V_51 ;
if ( V_30 -> V_5 [ V_121 ] )
V_674 = F_32 ( V_30 -> V_5 [ V_121 ] ) ;
if ( V_674 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_567 ] )
V_675 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_676 = ! ! V_675 ;
if ( V_30 -> V_5 [ V_125 ] ) {
V_22 V_677 = F_4 ( V_30 -> V_5 [ V_125 ] ) ;
if ( V_677 >= V_112 )
return - V_16 ;
if ( V_677 != V_678 &&
V_677 != V_679 )
return - V_16 ;
V_676 = V_677 == V_679 ;
}
if ( ! V_7 -> V_328 -> V_680 )
return - V_560 ;
if ( ! V_676 && V_675 && ! ( V_7 -> V_18 . V_49 & V_401 ) )
return - V_681 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_682 ) ;
if ( ! V_360 )
goto V_59;
V_673 . V_51 = V_51 ;
V_673 . V_103 = V_674 ;
if ( F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_54 ( V_51 , V_121 , V_674 ) )
goto V_59;
if ( V_675 &&
F_49 ( V_51 , V_567 , V_607 , V_675 ) )
goto V_59;
V_35 = F_136 ( V_7 , V_559 , V_674 , V_676 , V_675 , & V_673 ,
F_134 ) ;
if ( V_35 )
goto V_683;
if ( V_673 . error )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_683:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_137 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_91 V_90 ;
int V_35 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( V_90 . V_103 < 0 )
return - V_16 ;
if ( ! V_90 . V_96 && ! V_90 . V_98 )
return - V_16 ;
F_116 ( V_559 -> V_28 ) ;
if ( V_90 . V_96 ) {
if ( ! V_7 -> V_328 -> V_684 ) {
V_35 = - V_560 ;
goto V_620;
}
V_35 = F_40 ( V_559 -> V_28 ) ;
if ( V_35 )
goto V_620;
V_35 = F_138 ( V_7 , V_559 , V_90 . V_103 ,
V_90 . V_100 , V_90 . V_101 ) ;
if ( V_35 )
goto V_620;
#ifdef F_139
V_559 -> V_28 -> V_685 . V_686 = V_90 . V_103 ;
#endif
} else {
if ( V_90 . V_100 || ! V_90 . V_101 ) {
V_35 = - V_16 ;
goto V_620;
}
if ( ! V_7 -> V_328 -> V_687 ) {
V_35 = - V_560 ;
goto V_620;
}
V_35 = F_40 ( V_559 -> V_28 ) ;
if ( V_35 )
goto V_620;
V_35 = F_140 ( V_7 , V_559 , V_90 . V_103 ) ;
if ( V_35 )
goto V_620;
#ifdef F_139
V_559 -> V_28 -> V_685 . V_688 = V_90 . V_103 ;
#endif
}
V_620:
F_118 ( V_559 -> V_28 ) ;
return V_35 ;
}
static int F_141 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int V_35 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_91 V_90 ;
const T_2 * V_675 = NULL ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_90 . V_105 . V_90 )
return - V_16 ;
if ( V_30 -> V_5 [ V_567 ] )
V_675 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( V_90 . type == - 1 ) {
if ( V_675 )
V_90 . type = V_679 ;
else
V_90 . type = V_678 ;
}
if ( V_90 . type != V_679 &&
V_90 . type != V_678 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_287 )
return - V_560 ;
if ( F_38 ( V_7 , & V_90 . V_105 , V_90 . V_103 ,
V_90 . type == V_679 ,
V_675 ) )
return - V_16 ;
F_116 ( V_559 -> V_28 ) ;
V_35 = F_40 ( V_559 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_142 ( V_7 , V_559 , V_90 . V_103 ,
V_90 . type == V_679 ,
V_675 , & V_90 . V_105 ) ;
F_118 ( V_559 -> V_28 ) ;
return V_35 ;
}
static int F_143 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int V_35 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 * V_675 = NULL ;
struct V_91 V_90 ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_567 ] )
V_675 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( V_90 . type == - 1 ) {
if ( V_675 )
V_90 . type = V_679 ;
else
V_90 . type = V_678 ;
}
if ( V_90 . type != V_679 &&
V_90 . type != V_678 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_689 )
return - V_560 ;
F_116 ( V_559 -> V_28 ) ;
V_35 = F_40 ( V_559 -> V_28 ) ;
if ( V_90 . type == V_678 && V_675 &&
! ( V_7 -> V_18 . V_49 & V_401 ) )
V_35 = - V_681 ;
if ( ! V_35 )
V_35 = F_144 ( V_7 , V_559 , V_90 . V_103 ,
V_90 . type == V_679 ,
V_675 ) ;
#ifdef F_139
if ( ! V_35 ) {
if ( V_90 . V_103 == V_559 -> V_28 -> V_685 . V_686 )
V_559 -> V_28 -> V_685 . V_686 = - 1 ;
else if ( V_90 . V_103 == V_559 -> V_28 -> V_685 . V_688 )
V_559 -> V_28 -> V_685 . V_688 = - 1 ;
}
#endif
F_118 ( V_559 -> V_28 ) ;
return V_35 ;
}
static int F_145 ( struct V_4 * V_690 )
{
struct V_4 * V_43 ;
int V_691 = 0 , V_24 ;
F_36 (attr, nl_attr, tmp) {
if ( F_22 ( V_43 ) != V_607 )
return - V_16 ;
V_691 ++ ;
}
return V_691 ;
}
static struct V_692 * F_146 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_693 V_694 ;
struct V_4 * V_43 ;
struct V_692 * V_695 ;
int V_160 = 0 , V_691 , V_24 ;
if ( ! V_18 -> V_473 )
return F_3 ( - V_560 ) ;
if ( ! V_30 -> V_5 [ V_696 ] )
return F_3 ( - V_16 ) ;
V_694 = F_4 ( V_30 -> V_5 [ V_696 ] ) ;
if ( V_694 != V_697 &&
V_694 != V_698 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_699 ] )
return F_3 ( - V_16 ) ;
V_691 = F_145 ( V_30 -> V_5 [ V_699 ] ) ;
if ( V_691 < 0 )
return F_3 ( V_691 ) ;
if ( V_691 > V_18 -> V_473 )
return F_3 ( - V_700 ) ;
V_695 = F_37 ( sizeof( * V_695 ) + ( sizeof( struct V_701 ) * V_691 ) ,
V_135 ) ;
if ( ! V_695 )
return F_3 ( - V_136 ) ;
F_36 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_695 -> V_702 [ V_160 ] . V_703 , F_21 ( V_43 ) , V_607 ) ;
V_160 ++ ;
}
V_695 -> V_704 = V_691 ;
V_695 -> V_694 = V_694 ;
return V_695 ;
}
static int F_147 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_692 * V_695 ;
int V_35 ;
if ( V_559 -> V_28 -> V_141 != V_142 &&
V_559 -> V_28 -> V_141 != V_144 )
return - V_560 ;
if ( ! V_559 -> V_28 -> V_561 )
return - V_16 ;
V_695 = F_146 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_695 ) )
return F_18 ( V_695 ) ;
V_35 = F_148 ( V_7 , V_559 , V_695 ) ;
F_39 ( V_695 ) ;
return V_35 ;
}
static V_22 F_149 ( struct V_242 * V_243 ,
T_2 * V_705 , T_2 V_706 )
{
T_2 V_160 ;
V_22 V_707 = 0 ;
for ( V_160 = 0 ; V_160 < V_706 ; V_160 ++ ) {
int V_247 = ( V_705 [ V_160 ] & 0x7f ) * 5 ;
int V_708 ;
for ( V_708 = 0 ; V_708 < V_243 -> V_264 ; V_708 ++ ) {
struct V_246 * V_709 =
& V_243 -> V_265 [ V_708 ] ;
if ( V_247 == V_709 -> V_267 ) {
V_707 |= 1 << V_708 ;
break;
}
}
if ( V_708 == V_243 -> V_264 )
return 0 ;
}
return V_707 ;
}
static bool F_150 ( struct V_242 * V_243 ,
T_2 * V_705 , T_2 V_706 ,
T_2 V_251 [ V_710 ] )
{
T_2 V_160 ;
memset ( V_251 , 0 , V_710 ) ;
for ( V_160 = 0 ; V_160 < V_706 ; V_160 ++ ) {
int V_708 , V_711 ;
V_708 = V_705 [ V_160 ] / 8 ;
V_711 = F_113 ( V_705 [ V_160 ] % 8 ) ;
if ( ( V_708 < 0 ) || ( V_708 >= V_710 ) )
return false ;
if ( V_243 -> V_248 . V_251 . V_712 [ V_708 ] & V_711 )
V_251 [ V_708 ] |= V_711 ;
else
return false ;
}
return true ;
}
static T_3 F_151 ( T_2 V_713 )
{
T_3 V_714 = 0 ;
switch ( V_713 ) {
case V_715 :
break;
case V_716 :
V_714 = 0x00FF ;
break;
case V_717 :
V_714 = 0x01FF ;
break;
case V_718 :
V_714 = 0x03FF ;
break;
default:
break;
}
return V_714 ;
}
static void F_152 ( T_3 V_713 ,
T_3 V_719 [ V_720 ] )
{
T_2 V_721 ;
for ( V_721 = 0 ; V_721 < V_720 ; V_721 ++ ) {
V_719 [ V_721 ] = F_151 ( V_713 & 0x03 ) ;
V_713 >>= 2 ;
}
}
static bool F_153 ( struct V_242 * V_243 ,
struct V_722 * V_723 ,
T_3 V_251 [ V_720 ] )
{
T_3 V_724 = F_154 ( V_243 -> V_258 . V_261 . V_724 ) ;
T_3 V_725 [ V_720 ] = {} ;
T_2 V_160 ;
if ( ! V_243 -> V_258 . V_259 )
return false ;
memset ( V_251 , 0 , sizeof( T_3 ) * V_720 ) ;
F_152 ( V_724 , V_725 ) ;
for ( V_160 = 0 ; V_160 < V_720 ; V_160 ++ ) {
if ( ( V_725 [ V_160 ] & V_723 -> V_251 [ V_160 ] ) == V_723 -> V_251 [ V_160 ] )
V_251 [ V_160 ] = V_723 -> V_251 [ V_160 ] ;
else
return false ;
}
return true ;
}
static int F_155 ( struct V_29 * V_30 ,
struct V_726 * V_707 )
{
struct V_4 * V_93 [ V_727 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int V_133 , V_160 ;
struct V_4 * V_728 ;
struct V_242 * V_243 ;
T_3 V_729 ;
memset ( V_707 , 0 , sizeof( * V_707 ) ) ;
for ( V_160 = 0 ; V_160 < V_437 ; V_160 ++ ) {
V_243 = V_7 -> V_18 . V_438 [ V_160 ] ;
if ( ! V_243 )
continue;
V_707 -> V_730 [ V_160 ] . V_731 = ( 1 << V_243 -> V_264 ) - 1 ;
memcpy ( V_707 -> V_730 [ V_160 ] . V_732 ,
V_243 -> V_248 . V_251 . V_712 ,
sizeof( V_707 -> V_730 [ V_160 ] . V_732 ) ) ;
if ( ! V_243 -> V_258 . V_259 )
continue;
V_729 = F_154 ( V_243 -> V_258 . V_261 . V_724 ) ;
F_152 ( V_729 , V_707 -> V_730 [ V_160 ] . V_261 ) ;
}
if ( ! V_30 -> V_5 [ V_733 ] )
goto V_620;
F_117 ( V_734 > V_710 * 8 ) ;
F_36 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_366 V_367 = F_156 ( V_728 ) ;
int V_35 ;
if ( V_367 < 0 || V_367 >= V_437 )
return - V_16 ;
V_243 = V_7 -> V_18 . V_438 [ V_367 ] ;
if ( V_243 == NULL )
return - V_16 ;
V_35 = F_31 ( V_93 , V_727 , V_728 ,
V_735 , V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_736 ] ) {
V_707 -> V_730 [ V_367 ] . V_731 = F_149 (
V_243 ,
F_21 ( V_93 [ V_736 ] ) ,
F_22 ( V_93 [ V_736 ] ) ) ;
if ( ( V_707 -> V_730 [ V_367 ] . V_731 == 0 ) &&
F_22 ( V_93 [ V_736 ] ) )
return - V_16 ;
}
if ( V_93 [ V_737 ] ) {
if ( ! F_150 (
V_243 ,
F_21 ( V_93 [ V_737 ] ) ,
F_22 ( V_93 [ V_737 ] ) ,
V_707 -> V_730 [ V_367 ] . V_732 ) )
return - V_16 ;
}
if ( V_93 [ V_738 ] ) {
if ( ! F_153 (
V_243 ,
F_21 ( V_93 [ V_738 ] ) ,
V_707 -> V_730 [ V_367 ] . V_261 ) )
return - V_16 ;
}
if ( V_93 [ V_739 ] ) {
V_707 -> V_730 [ V_367 ] . V_740 =
F_32 ( V_93 [ V_739 ] ) ;
if ( V_707 -> V_730 [ V_367 ] . V_740 > V_741 )
return - V_16 ;
}
if ( V_707 -> V_730 [ V_367 ] . V_731 == 0 ) {
if ( ! ( V_7 -> V_18 . V_438 [ V_367 ] -> V_248 . V_249 ||
V_7 -> V_18 . V_438 [ V_367 ] -> V_258 . V_259 ) )
return - V_16 ;
for ( V_160 = 0 ; V_160 < V_710 ; V_160 ++ )
if ( V_707 -> V_730 [ V_367 ] . V_732 [ V_160 ] )
goto V_620;
for ( V_160 = 0 ; V_160 < V_720 ; V_160 ++ )
if ( V_707 -> V_730 [ V_367 ] . V_261 [ V_160 ] )
goto V_620;
return - V_16 ;
}
}
V_620:
return 0 ;
}
static int F_157 ( struct V_6 * V_7 ,
enum V_366 V_367 ,
struct V_726 * V_742 )
{
V_22 V_743 , V_744 , V_160 ;
V_22 V_247 = V_742 -> V_730 [ V_367 ] . V_731 ;
if ( F_158 ( V_247 ) > 1 )
return - V_16 ;
V_743 = 0 ;
for ( V_160 = 0 ; V_160 < V_710 ; V_160 ++ ) {
if ( F_159 ( V_742 -> V_730 [ V_367 ] . V_732 [ V_160 ] ) > 1 ) {
return - V_16 ;
} else if ( V_742 -> V_730 [ V_367 ] . V_732 [ V_160 ] ) {
V_743 ++ ;
if ( V_743 > 1 )
return - V_16 ;
}
if ( V_743 && V_247 )
return - V_16 ;
}
V_744 = 0 ;
for ( V_160 = 0 ; V_160 < V_720 ; V_160 ++ ) {
if ( F_160 ( V_742 -> V_730 [ V_367 ] . V_261 [ V_160 ] ) > 1 ) {
return - V_16 ;
} else if ( V_742 -> V_730 [ V_367 ] . V_261 [ V_160 ] ) {
V_744 ++ ;
if ( V_744 > 1 )
return - V_16 ;
}
if ( V_744 && V_247 )
return - V_16 ;
}
if ( ( V_743 && V_744 ) || ( ! V_247 && ! V_743 && ! V_744 ) )
return - V_16 ;
if ( V_247 &&
! F_112 ( & V_7 -> V_18 ,
V_745 ) )
return - V_16 ;
if ( V_743 &&
! F_112 ( & V_7 -> V_18 ,
V_746 ) )
return - V_16 ;
if ( V_744 &&
! F_112 ( & V_7 -> V_18 ,
V_747 ) )
return - V_16 ;
return 0 ;
}
static int F_161 ( struct V_4 * V_5 [] ,
struct V_748 * V_749 )
{
bool V_750 = false ;
if ( ! F_20 ( V_5 [ V_751 ] ) ||
! F_20 ( V_5 [ V_752 ] ) ||
! F_20 ( V_5 [ V_753 ] ) ||
! F_20 ( V_5 [ V_754 ] ) )
return - V_16 ;
memset ( V_749 , 0 , sizeof( * V_749 ) ) ;
if ( V_5 [ V_755 ] ) {
V_749 -> V_756 = F_21 ( V_5 [ V_755 ] ) ;
V_749 -> V_757 = F_22 ( V_5 [ V_755 ] ) ;
if ( ! V_749 -> V_757 )
return - V_16 ;
V_750 = true ;
}
if ( V_5 [ V_751 ] ) {
V_749 -> V_758 = F_21 ( V_5 [ V_751 ] ) ;
V_749 -> V_759 = F_22 ( V_5 [ V_751 ] ) ;
V_750 = true ;
}
if ( ! V_750 )
return - V_16 ;
if ( V_5 [ V_752 ] ) {
V_749 -> V_760 = F_21 ( V_5 [ V_752 ] ) ;
V_749 -> V_761 = F_22 ( V_5 [ V_752 ] ) ;
}
if ( V_5 [ V_753 ] ) {
V_749 -> V_762 =
F_21 ( V_5 [ V_753 ] ) ;
V_749 -> V_763 =
F_22 ( V_5 [ V_753 ] ) ;
}
if ( V_5 [ V_754 ] ) {
V_749 -> V_764 =
F_21 ( V_5 [ V_754 ] ) ;
V_749 -> V_765 =
F_22 ( V_5 [ V_754 ] ) ;
}
if ( V_5 [ V_766 ] ) {
V_749 -> V_767 = F_21 ( V_5 [ V_766 ] ) ;
V_749 -> V_768 = F_22 ( V_5 [ V_766 ] ) ;
}
return 0 ;
}
static void F_162 ( struct V_769 * V_139 ,
const T_2 * V_705 )
{
int V_160 ;
if ( ! V_705 )
return;
for ( V_160 = 0 ; V_160 < V_705 [ 1 ] ; V_160 ++ ) {
if ( V_705 [ 2 + V_160 ] == V_770 )
V_139 -> V_771 = true ;
if ( V_705 [ 2 + V_160 ] == V_772 )
V_139 -> V_773 = true ;
}
}
static void F_163 ( struct V_769 * V_139 )
{
const struct V_748 * V_749 = & V_139 -> V_774 ;
T_4 V_775 = V_749 -> V_761 ;
const T_2 * V_776 = V_749 -> V_760 ;
const T_2 * V_705 ;
const T_2 * V_253 ;
V_705 = F_164 ( V_777 , V_776 , V_775 ) ;
F_162 ( V_139 , V_705 ) ;
V_705 = F_164 ( V_778 , V_776 , V_775 ) ;
F_162 ( V_139 , V_705 ) ;
V_253 = F_164 ( V_779 , V_776 , V_775 ) ;
if ( V_253 && V_253 [ 1 ] >= sizeof( * V_139 -> V_248 ) )
V_139 -> V_248 = ( void * ) ( V_253 + 2 ) ;
V_253 = F_164 ( V_780 , V_776 , V_775 ) ;
if ( V_253 && V_253 [ 1 ] >= sizeof( * V_139 -> V_258 ) )
V_139 -> V_258 = ( void * ) ( V_253 + 2 ) ;
}
static bool F_165 ( struct V_6 * V_7 ,
struct V_769 * V_139 )
{
struct V_1 * V_17 ;
bool V_516 = false ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_565 . V_53 )
continue;
V_139 -> V_540 = V_17 -> V_565 ;
V_516 = true ;
break;
}
return V_516 ;
}
static bool F_166 ( struct V_6 * V_7 ,
enum V_781 V_782 ,
enum V_357 V_50 )
{
if ( V_782 > V_783 )
return false ;
switch ( V_50 ) {
case V_784 :
if ( ! ( V_7 -> V_18 . V_368 & V_785 ) &&
V_782 == V_786 )
return false ;
if ( ! F_112 ( & V_7 -> V_18 ,
V_787 ) &&
( V_782 == V_788 ||
V_782 == V_789 ||
V_782 == V_790 ) )
return false ;
return true ;
case V_354 :
if ( V_782 == V_786 )
return false ;
if ( V_782 == V_789 ||
V_782 == V_790 )
return false ;
if ( ! F_112 (
& V_7 -> V_18 ,
V_791 ) &&
V_782 == V_788 )
return false ;
return true ;
case V_792 :
if ( V_782 == V_786 )
return false ;
if ( V_782 == V_788 ||
V_782 == V_789 ||
V_782 == V_790 )
return false ;
return true ;
default:
return false ;
}
}
static int F_167 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_769 V_139 ;
int V_35 ;
if ( V_559 -> V_28 -> V_141 != V_142 &&
V_559 -> V_28 -> V_141 != V_144 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_289 )
return - V_560 ;
if ( V_17 -> V_561 )
return - V_793 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_30 -> V_5 [ V_794 ] ||
! V_30 -> V_5 [ V_795 ] ||
! V_30 -> V_5 [ V_755 ] )
return - V_16 ;
V_35 = F_161 ( V_30 -> V_5 , & V_139 . V_774 ) ;
if ( V_35 )
return V_35 ;
V_139 . V_561 =
F_4 ( V_30 -> V_5 [ V_794 ] ) ;
V_139 . V_796 =
F_4 ( V_30 -> V_5 [ V_795 ] ) ;
V_35 = F_168 ( V_7 , V_559 -> V_28 -> V_141 ,
V_139 . V_561 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_613 ] ) {
V_139 . V_614 = F_21 ( V_30 -> V_5 [ V_613 ] ) ;
V_139 . V_612 =
F_22 ( V_30 -> V_5 [ V_613 ] ) ;
if ( V_139 . V_612 == 0 ||
V_139 . V_612 > V_650 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_797 ] ) {
V_139 . V_798 = F_4 (
V_30 -> V_5 [ V_797 ] ) ;
if ( V_139 . V_798 != V_799 &&
V_139 . V_798 != V_800 &&
V_139 . V_798 != V_801 )
return - V_16 ;
}
V_139 . V_802 = ! ! V_30 -> V_5 [ V_803 ] ;
if ( V_30 -> V_5 [ V_804 ] ) {
V_139 . V_782 = F_4 (
V_30 -> V_5 [ V_804 ] ) ;
if ( ! F_166 ( V_7 , V_139 . V_782 ,
V_792 ) )
return - V_16 ;
} else
V_139 . V_782 = V_805 ;
V_35 = F_169 ( V_7 , V_30 , & V_139 . V_806 ,
V_807 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_808 ] ) {
if ( ! ( V_7 -> V_18 . V_368 & V_809 ) )
return - V_560 ;
V_139 . V_810 = F_79 (
V_30 -> V_5 [ V_808 ] ) ;
}
if ( V_30 -> V_5 [ V_811 ] ) {
if ( V_559 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_139 . V_812 =
F_32 ( V_30 -> V_5 [ V_811 ] ) ;
if ( V_139 . V_812 > 127 )
return - V_16 ;
if ( V_139 . V_812 != 0 &&
! ( V_7 -> V_18 . V_368 & V_813 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_814 ] ) {
T_2 V_24 ;
if ( V_559 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_32 ( V_30 -> V_5 [ V_814 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_139 . V_815 = V_24 ;
if ( V_139 . V_815 != 0 &&
! ( V_7 -> V_18 . V_368 & V_816 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_542 ] ) {
V_35 = F_81 ( V_7 , V_30 , & V_139 . V_540 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_565 . V_53 ) {
V_139 . V_540 = V_17 -> V_565 ;
} else if ( ! F_165 ( V_7 , & V_139 ) )
return - V_16 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_139 . V_540 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_733 ] ) {
V_35 = F_155 ( V_30 , & V_139 . V_742 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_157 ( V_7 , V_139 . V_540 . V_53 -> V_367 ,
& V_139 . V_742 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_817 ] ) {
V_139 . V_818 =
F_32 ( V_30 -> V_5 [ V_817 ] ) ;
switch ( V_139 . V_818 ) {
case V_819 :
break;
case V_820 :
if ( ! ( V_7 -> V_18 . V_368 &
V_821 ) )
return - V_16 ;
break;
case V_822 :
if ( ! ( V_7 -> V_18 . V_368 &
V_823 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_139 . V_818 = V_819 ;
}
V_139 . V_824 = F_170 ( V_30 -> V_5 [ V_825 ] ) ;
if ( V_139 . V_824 && ! V_7 -> V_18 . V_438 [ V_826 ] )
return - V_560 ;
if ( V_30 -> V_5 [ V_696 ] ) {
V_139 . V_695 = F_146 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_139 . V_695 ) )
return F_18 ( V_139 . V_695 ) ;
}
F_163 ( & V_139 ) ;
F_116 ( V_17 ) ;
V_35 = F_171 ( V_7 , V_559 , & V_139 ) ;
if ( ! V_35 ) {
V_17 -> V_565 = V_139 . V_540 ;
V_17 -> V_561 = V_139 . V_561 ;
V_17 -> V_540 = V_139 . V_540 ;
V_17 -> V_612 = V_139 . V_612 ;
memcpy ( V_17 -> V_614 , V_139 . V_614 , V_17 -> V_612 ) ;
}
F_118 ( V_17 ) ;
F_39 ( V_139 . V_695 ) ;
return V_35 ;
}
static int F_172 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_748 V_139 ;
int V_35 ;
if ( V_559 -> V_28 -> V_141 != V_142 &&
V_559 -> V_28 -> V_141 != V_144 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_827 )
return - V_560 ;
if ( ! V_17 -> V_561 )
return - V_16 ;
V_35 = F_161 ( V_30 -> V_5 , & V_139 ) ;
if ( V_35 )
return V_35 ;
F_116 ( V_17 ) ;
V_35 = F_173 ( V_7 , V_559 , & V_139 ) ;
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_174 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
return F_175 ( V_7 , V_559 , false ) ;
}
static int F_176 ( struct V_29 * V_30 ,
enum V_275 V_141 ,
struct V_828 * V_139 )
{
struct V_4 * V_49 [ V_829 + 1 ] ;
struct V_4 * V_622 ;
int V_625 ;
V_622 = V_30 -> V_5 [ V_830 ] ;
if ( V_622 ) {
struct V_831 * V_832 ;
V_832 = F_21 ( V_622 ) ;
V_139 -> V_833 = V_832 -> V_707 ;
V_139 -> V_834 = V_832 -> V_835 ;
V_139 -> V_834 &= V_139 -> V_833 ;
if ( ( V_139 -> V_833 |
V_139 -> V_834 ) & F_113 ( V_836 ) )
return - V_16 ;
return 0 ;
}
V_622 = V_30 -> V_5 [ V_837 ] ;
if ( ! V_622 )
return 0 ;
if ( F_31 ( V_49 , V_829 , V_622 ,
V_838 , V_30 -> V_127 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_139 -> V_833 = F_113 ( V_839 ) |
F_113 ( V_840 ) |
F_113 ( V_841 ) |
F_113 ( V_842 ) ;
break;
case V_148 :
case V_147 :
V_139 -> V_833 = F_113 ( V_839 ) |
F_113 ( V_843 ) ;
break;
case V_145 :
V_139 -> V_833 = F_113 ( V_844 ) |
F_113 ( V_842 ) |
F_113 ( V_839 ) ;
default:
return - V_16 ;
}
for ( V_625 = 1 ; V_625 <= V_829 ; V_625 ++ ) {
if ( V_49 [ V_625 ] ) {
V_139 -> V_834 |= ( 1 << V_625 ) ;
if ( V_625 > V_845 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_177 ( struct V_31 * V_51 , struct V_846 * V_30 ,
int V_43 )
{
struct V_4 * V_247 ;
V_22 V_267 ;
T_3 V_847 ;
enum V_848 V_849 ;
V_247 = F_45 ( V_51 , V_43 ) ;
if ( ! V_247 )
return false ;
V_267 = F_178 ( V_30 ) ;
V_847 = V_267 < ( 1UL << 16 ) ? V_267 : 0 ;
if ( V_267 > 0 &&
F_26 ( V_51 , V_850 , V_267 ) )
return false ;
if ( V_847 > 0 &&
F_53 ( V_51 , V_851 , V_847 ) )
return false ;
switch ( V_30 -> V_852 ) {
case V_853 :
V_849 = V_854 ;
break;
case V_855 :
V_849 = V_856 ;
break;
default:
F_60 ( 1 ) ;
case V_857 :
V_849 = 0 ;
break;
case V_858 :
V_849 = V_859 ;
break;
case V_860 :
V_849 = V_861 ;
break;
case V_862 :
V_849 = V_863 ;
break;
}
if ( V_849 && F_27 ( V_51 , V_849 ) )
return false ;
if ( V_30 -> V_49 & V_864 ) {
if ( F_54 ( V_51 , V_865 , V_30 -> V_251 ) )
return false ;
if ( V_30 -> V_49 & V_866 &&
F_27 ( V_51 , V_867 ) )
return false ;
} else if ( V_30 -> V_49 & V_868 ) {
if ( F_54 ( V_51 , V_869 , V_30 -> V_251 ) )
return false ;
if ( F_54 ( V_51 , V_870 , V_30 -> V_721 ) )
return false ;
if ( V_30 -> V_49 & V_866 &&
F_27 ( V_51 , V_867 ) )
return false ;
}
F_46 ( V_51 , V_247 ) ;
return true ;
}
static bool F_179 ( struct V_31 * V_51 , T_2 V_707 , T_5 * signal ,
int V_871 )
{
void * V_43 ;
int V_160 = 0 ;
if ( ! V_707 )
return true ;
V_43 = F_45 ( V_51 , V_871 ) ;
if ( ! V_43 )
return false ;
for ( V_160 = 0 ; V_160 < V_872 ; V_160 ++ ) {
if ( ! ( V_707 & F_113 ( V_160 ) ) )
continue;
if ( F_54 ( V_51 , V_160 , signal [ V_160 ] ) )
return false ;
}
F_46 ( V_51 , V_43 ) ;
return true ;
}
static int F_180 ( struct V_31 * V_51 , V_22 V_50 , V_22 V_47 ,
V_22 V_48 , int V_49 ,
struct V_6 * V_7 ,
struct V_25 * V_559 ,
const T_2 * V_675 , struct V_873 * V_874 )
{
void * V_360 ;
struct V_4 * V_875 , * V_876 ;
V_360 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_675 ) ||
F_26 ( V_51 , V_370 , V_874 -> V_877 ) )
goto V_59;
V_875 = F_45 ( V_51 , V_878 ) ;
if ( ! V_875 )
goto V_59;
#define F_181 ( V_43 , T_6 , type ) do { \
BUILD_BUG_ON(sizeof(type) == sizeof(u64)); \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
#define F_182 ( V_43 , T_6 ) do { \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb, NL80211_STA_INFO_PAD)) \
goto nla_put_failure; \
} while (0)
F_181 ( V_879 , V_880 , V_22 ) ;
F_181 ( V_881 , V_882 , V_22 ) ;
if ( V_874 -> V_883 & ( F_113 ( V_884 ) |
F_113 ( V_885 ) ) &&
F_26 ( V_51 , V_884 ,
( V_22 ) V_874 -> V_886 ) )
goto V_59;
if ( V_874 -> V_883 & ( F_113 ( V_887 ) |
F_113 ( V_888 ) ) &&
F_26 ( V_51 , V_887 ,
( V_22 ) V_874 -> V_889 ) )
goto V_59;
F_182 ( V_890 , V_886 ) ;
F_182 ( V_891 , V_889 ) ;
F_181 ( V_892 , V_893 , T_3 ) ;
F_181 ( V_894 , V_895 , T_3 ) ;
F_181 ( V_896 , V_897 , T_2 ) ;
F_182 ( V_898 , V_899 ) ;
switch ( V_7 -> V_18 . V_900 ) {
case V_901 :
F_181 ( SIGNAL , signal , T_2 ) ;
F_181 ( V_902 , V_903 , T_2 ) ;
break;
default:
break;
}
if ( V_874 -> V_883 & F_113 ( V_904 ) ) {
if ( ! F_179 ( V_51 , V_874 -> V_905 ,
V_874 -> V_906 ,
V_904 ) )
goto V_59;
}
if ( V_874 -> V_883 & F_113 ( V_907 ) ) {
if ( ! F_179 ( V_51 , V_874 -> V_905 ,
V_874 -> V_908 ,
V_907 ) )
goto V_59;
}
if ( V_874 -> V_883 & F_113 ( V_909 ) ) {
if ( ! F_177 ( V_51 , & V_874 -> V_723 ,
V_909 ) )
goto V_59;
}
if ( V_874 -> V_883 & F_113 ( V_910 ) ) {
if ( ! F_177 ( V_51 , & V_874 -> V_911 ,
V_910 ) )
goto V_59;
}
F_181 ( V_912 , V_913 , V_22 ) ;
F_181 ( V_914 , V_915 , V_22 ) ;
F_181 ( V_916 , V_917 , V_22 ) ;
F_181 ( V_918 , V_919 , V_22 ) ;
F_181 ( V_920 , V_921 , V_22 ) ;
F_181 ( V_922 , V_923 , V_22 ) ;
F_181 ( V_924 , V_925 , V_22 ) ;
F_181 ( V_926 , V_927 , V_22 ) ;
F_181 ( V_928 , V_929 , V_22 ) ;
if ( V_874 -> V_883 & F_113 ( V_930 ) ) {
V_876 = F_45 ( V_51 , V_930 ) ;
if ( ! V_876 )
goto V_59;
if ( ( ( V_874 -> V_876 . V_49 & V_931 ) &&
F_27 ( V_51 , V_932 ) ) ||
( ( V_874 -> V_876 . V_49 & V_933 ) &&
F_27 ( V_51 , V_934 ) ) ||
( ( V_874 -> V_876 . V_49 & V_935 ) &&
F_27 ( V_51 , V_936 ) ) ||
F_54 ( V_51 , V_937 ,
V_874 -> V_876 . V_796 ) ||
F_53 ( V_51 , V_938 ,
V_874 -> V_876 . V_561 ) )
goto V_59;
F_46 ( V_51 , V_876 ) ;
}
if ( ( V_874 -> V_883 & F_113 ( V_939 ) ) &&
F_49 ( V_51 , V_939 ,
sizeof( struct V_831 ) ,
& V_874 -> V_832 ) )
goto V_59;
F_182 ( V_940 , V_941 ) ;
F_182 ( V_942 , V_943 ) ;
F_182 ( V_944 , V_945 ) ;
F_181 ( V_946 , V_947 , T_2 ) ;
#undef F_181
#undef F_182
if ( V_874 -> V_883 & F_113 ( V_948 ) ) {
struct V_4 * V_949 ;
int V_950 ;
V_949 = F_45 ( V_51 , V_948 ) ;
if ( ! V_949 )
goto V_59;
for ( V_950 = 0 ; V_950 < V_951 + 1 ; V_950 ++ ) {
struct V_952 * V_953 ;
struct V_4 * V_954 ;
V_953 = & V_874 -> V_955 [ V_950 ] ;
if ( ! V_953 -> V_883 )
continue;
V_954 = F_45 ( V_51 , V_950 + 1 ) ;
if ( ! V_954 )
goto V_59;
#define F_183 ( V_43 , T_6 ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb, NL80211_TID_STATS_PAD)) \
goto nla_put_failure; \
} while (0)
F_183 ( V_956 , V_957 ) ;
F_183 ( V_958 , V_959 ) ;
F_183 ( V_960 , V_961 ) ;
F_183 ( V_962 , V_963 ) ;
#undef F_183
F_46 ( V_51 , V_954 ) ;
}
F_46 ( V_51 , V_949 ) ;
}
F_46 ( V_51 , V_875 ) ;
if ( V_874 -> V_964 &&
F_49 ( V_51 , V_752 , V_874 -> V_964 ,
V_874 -> V_965 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int F_184 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_873 V_874 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_675 [ V_607 ] ;
int V_966 = V_34 -> args [ 2 ] ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_967;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_967;
}
if ( ! V_7 -> V_328 -> V_968 ) {
V_35 = - V_560 ;
goto V_967;
}
while ( 1 ) {
memset ( & V_874 , 0 , sizeof( V_874 ) ) ;
V_35 = F_185 ( V_7 , V_17 -> V_19 , V_966 ,
V_675 , & V_874 ) ;
if ( V_35 == - V_681 )
break;
if ( V_35 )
goto V_967;
if ( F_180 ( V_32 , V_969 ,
F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_7 , V_17 -> V_19 , V_675 ,
& V_874 ) < 0 )
goto V_620;
V_966 ++ ;
}
V_620:
V_34 -> args [ 2 ] = V_966 ;
V_35 = V_32 -> V_45 ;
V_967:
F_70 () ;
return V_35 ;
}
static int F_186 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_873 V_874 ;
struct V_31 * V_51 ;
T_2 * V_675 = NULL ;
int V_35 ;
memset ( & V_874 , 0 , sizeof( V_874 ) ) ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_675 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( ! V_7 -> V_328 -> V_970 )
return - V_560 ;
V_35 = F_187 ( V_7 , V_559 , V_675 , & V_874 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
if ( F_180 ( V_51 , V_969 ,
V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_7 , V_559 , V_675 , & V_874 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
int F_188 ( struct V_18 * V_18 ,
struct V_828 * V_139 ,
enum V_971 V_972 )
{
if ( V_139 -> V_973 != - 1 &&
V_972 != V_974 )
return - V_16 ;
if ( V_139 -> V_975 != - 1 &&
V_972 != V_974 )
return - V_16 ;
if ( V_139 -> V_976 &&
! ( V_139 -> V_834 & F_113 ( V_843 ) ) &&
V_972 != V_974 )
return - V_16 ;
F_117 ( V_829 != 7 ) ;
switch ( V_972 ) {
case V_977 :
case V_978 :
if ( V_139 -> V_833 &
~ ( F_113 ( V_844 ) |
F_113 ( V_842 ) |
F_113 ( V_839 ) ) )
return - V_16 ;
break;
case V_979 :
case V_980 :
if ( ! ( V_139 -> V_834 & F_113 ( V_843 ) ) )
return - V_16 ;
V_139 -> V_833 &= ~ F_113 ( V_843 ) ;
break;
default:
if ( V_139 -> V_981 != V_982 )
return - V_16 ;
if ( V_139 -> V_925 )
return - V_16 ;
if ( V_139 -> V_983 & V_984 )
return - V_16 ;
}
if ( V_972 != V_979 &&
V_972 != V_980 ) {
if ( V_139 -> V_834 & F_113 ( V_843 ) )
return - V_16 ;
V_139 -> V_833 &= ~ F_113 ( V_843 ) ;
}
if ( V_972 != V_979 &&
V_972 != V_974 ) {
if ( V_139 -> V_983 & V_985 )
return - V_16 ;
if ( V_139 -> V_983 & V_986 )
return - V_16 ;
if ( V_139 -> V_987 )
return - V_16 ;
if ( V_139 -> V_988 || V_139 -> V_989 || V_139 -> V_990 )
return - V_16 ;
}
if ( V_972 != V_991 &&
V_972 != V_974 ) {
if ( V_139 -> V_992 )
return - V_16 ;
}
switch ( V_972 ) {
case V_993 :
if ( ! ( V_139 -> V_833 & F_113 ( V_839 ) ) )
return - V_560 ;
break;
case V_991 :
case V_974 :
if ( V_139 -> V_833 &
~ ( F_113 ( V_839 ) |
F_113 ( V_844 ) |
F_113 ( V_994 ) |
F_113 ( V_840 ) |
F_113 ( V_841 ) |
F_113 ( V_842 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_368 & V_995 ) &&
V_139 -> V_833 &
( F_113 ( V_844 ) |
F_113 ( V_994 ) ) )
return - V_16 ;
break;
case V_996 :
case V_997 :
if ( V_139 -> V_833 & ~ F_113 ( V_839 ) )
return - V_16 ;
break;
case V_979 :
if ( V_139 -> V_833 & ~ ( F_113 ( V_839 ) |
F_113 ( V_841 ) ) )
return - V_16 ;
if ( V_139 -> V_834 & F_113 ( V_839 ) &&
! V_139 -> V_987 )
return - V_16 ;
break;
case V_980 :
return - V_16 ;
case V_977 :
if ( V_139 -> V_983 & V_984 )
return - V_16 ;
break;
case V_978 :
if ( V_139 -> V_981 != V_982 &&
V_139 -> V_981 != V_998 )
return - V_16 ;
break;
}
if ( V_972 != V_974 &&
V_972 != V_979 )
V_139 -> V_999 = false ;
return 0 ;
}
static struct V_25 * F_189 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_1000 = V_30 -> V_5 [ V_1001 ] ;
struct V_25 * V_1002 ;
int V_516 ;
if ( ! V_1000 )
return NULL ;
V_1002 = F_190 ( F_95 ( V_30 ) , F_4 ( V_1000 ) ) ;
if ( ! V_1002 )
return F_3 ( - V_23 ) ;
if ( ! V_1002 -> V_28 || V_1002 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_516 = - V_16 ;
goto error;
}
if ( V_1002 -> V_28 -> V_141 != V_143 &&
V_1002 -> V_28 -> V_141 != V_142 &&
V_1002 -> V_28 -> V_141 != V_144 ) {
V_516 = - V_16 ;
goto error;
}
if ( ! F_92 ( V_1002 ) ) {
V_516 = - V_574 ;
goto error;
}
return V_1002 ;
error:
F_191 ( V_1002 ) ;
return F_3 ( V_516 ) ;
}
static int F_192 ( struct V_29 * V_30 ,
struct V_828 * V_139 )
{
struct V_4 * V_93 [ V_1003 + 1 ] ;
struct V_4 * V_622 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1004 ] )
return 0 ;
V_622 = V_30 -> V_5 [ V_1004 ] ;
V_35 = F_31 ( V_93 , V_1003 , V_622 ,
V_1005 , V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_1006 ] )
V_139 -> V_1007 = F_32 (
V_93 [ V_1006 ] ) ;
if ( V_139 -> V_1007 & ~ V_1008 )
return - V_16 ;
if ( V_93 [ V_1009 ] )
V_139 -> V_1010 = F_32 ( V_93 [ V_1009 ] ) ;
if ( V_139 -> V_1010 & ~ V_1011 )
return - V_16 ;
V_139 -> V_983 |= V_985 ;
return 0 ;
}
static int F_193 ( struct V_29 * V_30 ,
struct V_828 * V_139 )
{
if ( V_30 -> V_5 [ V_1012 ] ) {
V_139 -> V_1013 =
F_21 ( V_30 -> V_5 [ V_1012 ] ) ;
V_139 -> V_1014 =
F_22 ( V_30 -> V_5 [ V_1012 ] ) ;
if ( V_139 -> V_1014 < 2 )
return - V_16 ;
if ( V_139 -> V_1014 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1015 ] ) {
V_139 -> V_1016 =
F_21 ( V_30 -> V_5 [ V_1015 ] ) ;
V_139 -> V_1017 =
F_22 ( V_30 -> V_5 [ V_1015 ] ) ;
if ( V_139 -> V_1017 < 2 ||
V_139 -> V_1017 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_194 ( struct V_29 * V_30 ,
struct V_828 * V_139 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_1018 ] )
V_139 -> V_976 = F_79 ( V_30 -> V_5 [ V_1018 ] ) ;
if ( V_30 -> V_5 [ V_1019 ] )
V_139 -> V_989 =
F_21 ( V_30 -> V_5 [ V_1019 ] ) ;
if ( V_30 -> V_5 [ V_1020 ] )
V_139 -> V_990 =
F_21 ( V_30 -> V_5 [ V_1020 ] ) ;
V_35 = F_193 ( V_30 , V_139 ) ;
if ( V_35 )
return V_35 ;
return F_192 ( V_30 , V_139 ) ;
}
static int F_195 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_828 V_139 ;
T_2 * V_675 ;
int V_35 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_7 -> V_328 -> V_1021 )
return - V_560 ;
if ( V_30 -> V_5 [ V_1022 ] )
V_139 . V_976 = F_79 ( V_30 -> V_5 [ V_1022 ] ) ;
if ( V_30 -> V_5 [ V_1023 ] )
V_139 . V_973 =
F_79 ( V_30 -> V_5 [ V_1023 ] ) ;
else
V_139 . V_973 = - 1 ;
if ( V_30 -> V_5 [ V_1024 ] ) {
T_2 V_24 ;
V_24 = F_32 ( V_30 -> V_5 [ V_1024 ] ) ;
if ( V_24 >= V_1025 )
return - V_16 ;
V_139 . V_975 = V_24 ;
} else {
V_139 . V_975 = - 1 ;
}
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_675 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( V_30 -> V_5 [ V_1026 ] ) {
V_139 . V_987 =
F_21 ( V_30 -> V_5 [ V_1026 ] ) ;
V_139 . V_1027 =
F_22 ( V_30 -> V_5 [ V_1026 ] ) ;
}
if ( V_30 -> V_5 [ V_1028 ] ) {
V_139 . V_1029 =
F_79 ( V_30 -> V_5 [ V_1028 ] ) ;
V_139 . V_983 |= V_986 ;
}
if ( V_30 -> V_5 [ V_1030 ] ) {
V_139 . V_988 =
F_21 ( V_30 -> V_5 [ V_1030 ] ) ;
V_139 . V_1031 =
F_22 ( V_30 -> V_5 [ V_1030 ] ) ;
}
if ( F_176 ( V_30 , V_559 -> V_28 -> V_141 , & V_139 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_1032 ] ) {
V_139 . V_981 =
F_32 ( V_30 -> V_5 [ V_1032 ] ) ;
if ( V_139 . V_981 >= V_1033 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1034 ] ) {
V_139 . V_897 =
F_32 ( V_30 -> V_5 [ V_1034 ] ) ;
if ( V_139 . V_897 >= V_1035 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1036 ] ) {
V_139 . V_1037 = F_79 (
V_30 -> V_5 [ V_1036 ] ) ;
if ( V_139 . V_1037 > V_1038 )
return - V_16 ;
}
V_139 . V_983 |= V_984 ;
}
if ( V_30 -> V_5 [ V_1039 ] ) {
enum V_1040 V_1041 = F_4 (
V_30 -> V_5 [ V_1039 ] ) ;
if ( V_1041 <= V_1042 ||
V_1041 > V_1043 )
return - V_16 ;
V_139 . V_925 = V_1041 ;
}
if ( V_30 -> V_5 [ V_1044 ] ) {
V_139 . V_999 = true ;
V_139 . V_1045 =
F_32 ( V_30 -> V_5 [ V_1044 ] ) ;
}
V_35 = F_194 ( V_30 , & V_139 ) ;
if ( V_35 )
return V_35 ;
V_139 . V_992 = F_189 ( V_30 , V_7 ) ;
if ( F_17 ( V_139 . V_992 ) )
return F_18 ( V_139 . V_992 ) ;
switch ( V_559 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_560 ;
goto V_1046;
}
V_35 = F_196 ( V_7 , V_559 , V_675 , & V_139 ) ;
V_1046:
if ( V_139 . V_992 )
F_191 ( V_139 . V_992 ) ;
return V_35 ;
}
static int F_197 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int V_35 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_828 V_139 ;
T_2 * V_675 = NULL ;
V_22 V_1047 = F_113 ( V_844 ) |
F_113 ( V_994 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_7 -> V_328 -> V_291 )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1023 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1026 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1022 ] &&
! V_30 -> V_5 [ V_1018 ] )
return - V_16 ;
V_675 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_139 . V_987 =
F_21 ( V_30 -> V_5 [ V_1026 ] ) ;
V_139 . V_1027 =
F_22 ( V_30 -> V_5 [ V_1026 ] ) ;
V_139 . V_973 =
F_79 ( V_30 -> V_5 [ V_1023 ] ) ;
if ( V_30 -> V_5 [ V_1024 ] ) {
T_2 V_24 ;
V_24 = F_32 ( V_30 -> V_5 [ V_1024 ] ) ;
if ( V_24 >= V_1025 )
return - V_16 ;
V_139 . V_975 = V_24 ;
} else {
V_139 . V_975 =
V_559 -> V_28 -> V_141 == V_144 ;
}
if ( V_30 -> V_5 [ V_1018 ] )
V_139 . V_976 = F_79 ( V_30 -> V_5 [ V_1018 ] ) ;
else
V_139 . V_976 = F_79 ( V_30 -> V_5 [ V_1022 ] ) ;
if ( ! V_139 . V_976 || V_139 . V_976 > V_1038 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1028 ] ) {
V_139 . V_1029 =
F_79 ( V_30 -> V_5 [ V_1028 ] ) ;
V_139 . V_983 |= V_986 ;
}
if ( V_30 -> V_5 [ V_1030 ] ) {
V_139 . V_988 =
F_21 ( V_30 -> V_5 [ V_1030 ] ) ;
V_139 . V_1031 =
F_22 ( V_30 -> V_5 [ V_1030 ] ) ;
}
if ( V_30 -> V_5 [ V_1019 ] )
V_139 . V_989 =
F_21 ( V_30 -> V_5 [ V_1019 ] ) ;
if ( V_30 -> V_5 [ V_1020 ] )
V_139 . V_990 =
F_21 ( V_30 -> V_5 [ V_1020 ] ) ;
if ( V_30 -> V_5 [ V_1044 ] ) {
V_139 . V_999 = true ;
V_139 . V_1045 =
F_32 ( V_30 -> V_5 [ V_1044 ] ) ;
}
if ( V_30 -> V_5 [ V_1032 ] ) {
V_139 . V_981 =
F_32 ( V_30 -> V_5 [ V_1032 ] ) ;
if ( V_139 . V_981 >= V_1033 )
return - V_16 ;
}
V_35 = F_193 ( V_30 , & V_139 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_192 ( V_30 , & V_139 ) ;
if ( V_35 )
return V_35 ;
if ( F_176 ( V_30 , V_559 -> V_28 -> V_141 , & V_139 ) )
return - V_16 ;
if ( ! ( V_139 . V_834 & F_113 ( V_841 ) ) ) {
V_139 . V_989 = NULL ;
V_139 . V_990 = NULL ;
}
F_117 ( V_829 != 7 ) ;
switch ( V_559 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_49 & V_405 ) ||
! ( V_139 . V_834 & F_113 ( V_841 ) ) )
V_139 . V_983 &= ~ V_985 ;
if ( ( V_139 . V_834 & F_113 ( V_843 ) ) ||
V_30 -> V_5 [ V_1018 ] )
return - V_16 ;
V_139 . V_833 &= ~ F_113 ( V_843 ) ;
if ( ! ( V_7 -> V_18 . V_368 &
V_995 ) &&
V_139 . V_833 & V_1047 )
return - V_16 ;
if ( ! ( V_139 . V_833 & V_1047 ) ) {
V_139 . V_833 |= V_1047 ;
V_139 . V_834 |= V_1047 ;
}
V_139 . V_992 = F_189 ( V_30 , V_7 ) ;
if ( F_17 ( V_139 . V_992 ) )
return F_18 ( V_139 . V_992 ) ;
break;
case V_145 :
V_139 . V_983 &= ~ V_985 ;
if ( V_139 . V_833 & F_113 ( V_994 ) )
return - V_16 ;
if ( ( V_139 . V_834 & F_113 ( V_843 ) ) ||
V_30 -> V_5 [ V_1018 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_139 . V_983 &= ~ V_985 ;
if ( V_139 . V_833 &
( F_113 ( V_994 ) |
F_113 ( V_844 ) ) )
return - V_16 ;
if ( ! ( V_139 . V_834 & F_113 ( V_843 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_49 & V_333 ) )
return - V_560 ;
if ( ! ( V_7 -> V_18 . V_49 & V_410 ) )
return - V_560 ;
V_139 . V_833 &= ~ F_113 ( V_839 ) ;
break;
default:
return - V_560 ;
}
V_35 = F_198 ( V_7 , V_559 , V_675 , & V_139 ) ;
if ( V_139 . V_992 )
F_191 ( V_139 . V_992 ) ;
return V_35 ;
}
static int F_199 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1048 V_139 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( V_30 -> V_5 [ V_567 ] )
V_139 . V_1049 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( V_559 -> V_28 -> V_141 != V_142 &&
V_559 -> V_28 -> V_141 != V_143 &&
V_559 -> V_28 -> V_141 != V_145 &&
V_559 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1050 )
return - V_560 ;
if ( V_30 -> V_5 [ V_1051 ] ) {
V_139 . V_1052 =
F_32 ( V_30 -> V_5 [ V_1051 ] ) ;
if ( V_139 . V_1052 != V_1053 >> 4 &&
V_139 . V_1052 != V_1054 >> 4 )
return - V_16 ;
} else {
V_139 . V_1052 = V_1054 >> 4 ;
}
if ( V_30 -> V_5 [ V_1055 ] ) {
V_139 . V_1056 =
F_79 ( V_30 -> V_5 [ V_1055 ] ) ;
if ( V_139 . V_1056 == 0 )
return - V_16 ;
} else {
V_139 . V_1056 = V_1057 ;
}
return F_200 ( V_7 , V_559 , & V_139 ) ;
}
static int F_201 ( struct V_31 * V_51 , V_22 V_47 , V_22 V_48 ,
int V_49 , struct V_25 * V_559 ,
T_2 * V_1058 , T_2 * V_1059 ,
struct V_1060 * V_1061 )
{
void * V_360 ;
struct V_4 * V_1062 ;
V_360 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_1063 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_1058 ) ||
F_49 ( V_51 , V_1064 , V_607 , V_1059 ) ||
F_26 ( V_51 , V_370 , V_1061 -> V_877 ) )
goto V_59;
V_1062 = F_45 ( V_51 , V_1065 ) ;
if ( ! V_1062 )
goto V_59;
if ( ( V_1061 -> V_883 & V_1066 ) &&
F_26 ( V_51 , V_1067 ,
V_1061 -> V_1068 ) )
goto V_59;
if ( ( ( V_1061 -> V_883 & V_1069 ) &&
F_26 ( V_51 , V_1070 , V_1061 -> V_1071 ) ) ||
( ( V_1061 -> V_883 & V_1072 ) &&
F_26 ( V_51 , V_1073 ,
V_1061 -> V_1074 ) ) ||
( ( V_1061 -> V_883 & V_1075 ) &&
F_26 ( V_51 , V_1076 ,
V_1061 -> V_1077 ) ) ||
( ( V_1061 -> V_883 & V_1078 ) &&
F_54 ( V_51 , V_1079 ,
V_1061 -> V_49 ) ) ||
( ( V_1061 -> V_883 & V_1080 ) &&
F_26 ( V_51 , V_1081 ,
V_1061 -> V_1082 ) ) ||
( ( V_1061 -> V_883 & V_1083 ) &&
F_54 ( V_51 , V_1084 ,
V_1061 -> V_1085 ) ) )
goto V_59;
F_46 ( V_51 , V_1062 ) ;
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int F_202 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1060 V_1061 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1058 [ V_607 ] ;
T_2 V_1059 [ V_607 ] ;
int V_1086 = V_34 -> args [ 2 ] ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_967;
if ( ! V_7 -> V_328 -> V_1087 ) {
V_35 = - V_560 ;
goto V_967;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_560 ;
goto V_967;
}
while ( 1 ) {
V_35 = F_203 ( V_7 , V_17 -> V_19 , V_1086 , V_1058 ,
V_1059 , & V_1061 ) ;
if ( V_35 == - V_681 )
break;
if ( V_35 )
goto V_967;
if ( F_201 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_17 -> V_19 , V_1058 , V_1059 ,
& V_1061 ) < 0 )
goto V_620;
V_1086 ++ ;
}
V_620:
V_34 -> args [ 2 ] = V_1086 ;
V_35 = V_32 -> V_45 ;
V_967:
F_70 () ;
return V_35 ;
}
static int F_204 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int V_35 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1060 V_1061 ;
struct V_31 * V_51 ;
T_2 * V_1058 = NULL ;
T_2 V_1059 [ V_607 ] ;
memset ( & V_1061 , 0 , sizeof( V_1061 ) ) ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_1058 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( ! V_7 -> V_328 -> V_1088 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_145 )
return - V_560 ;
V_35 = F_205 ( V_7 , V_559 , V_1058 , V_1059 , & V_1061 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
if ( F_201 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_559 , V_1058 , V_1059 , & V_1061 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_206 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 * V_1058 = NULL ;
T_2 * V_1059 = NULL ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1064 ] )
return - V_16 ;
V_1058 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_1059 = F_21 ( V_30 -> V_5 [ V_1064 ] ) ;
if ( ! V_7 -> V_328 -> V_1089 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_145 )
return - V_560 ;
return F_207 ( V_7 , V_559 , V_1058 , V_1059 ) ;
}
static int F_208 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 * V_1058 = NULL ;
T_2 * V_1059 = NULL ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1064 ] )
return - V_16 ;
V_1058 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_1059 = F_21 ( V_30 -> V_5 [ V_1064 ] ) ;
if ( ! V_7 -> V_328 -> V_293 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_145 )
return - V_560 ;
return F_209 ( V_7 , V_559 , V_1058 , V_1059 ) ;
}
static int F_210 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 * V_1058 = NULL ;
if ( V_30 -> V_5 [ V_567 ] )
V_1058 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( ! V_7 -> V_328 -> V_1090 )
return - V_560 ;
return F_211 ( V_7 , V_559 , V_1058 ) ;
}
static int F_212 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int V_35 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1060 V_1061 ;
struct V_31 * V_51 ;
T_2 * V_1058 = NULL ;
T_2 V_1091 [ V_607 ] ;
memset ( & V_1061 , 0 , sizeof( V_1061 ) ) ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_1058 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( ! V_7 -> V_328 -> V_1092 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_145 )
return - V_560 ;
V_35 = F_213 ( V_7 , V_559 , V_1058 , V_1091 , & V_1061 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
if ( F_201 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_559 , V_1058 , V_1091 , & V_1061 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_214 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1060 V_1061 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1058 [ V_607 ] ;
T_2 V_1091 [ V_607 ] ;
int V_1086 = V_34 -> args [ 2 ] ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_967;
if ( ! V_7 -> V_328 -> V_1093 ) {
V_35 = - V_560 ;
goto V_967;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_560 ;
goto V_967;
}
while ( 1 ) {
V_35 = F_215 ( V_7 , V_17 -> V_19 , V_1086 , V_1058 ,
V_1091 , & V_1061 ) ;
if ( V_35 == - V_681 )
break;
if ( V_35 )
goto V_967;
if ( F_201 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_17 -> V_19 , V_1058 , V_1091 ,
& V_1061 ) < 0 )
goto V_620;
V_1086 ++ ;
}
V_620:
V_34 -> args [ 2 ] = V_1086 ;
V_35 = V_32 -> V_45 ;
V_967:
F_70 () ;
return V_35 ;
}
static int F_216 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_1094 V_139 ;
int V_35 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_1095 = - 1 ;
V_139 . V_1096 = - 1 ;
V_139 . V_1097 = - 1 ;
V_139 . V_1098 = - 1 ;
V_139 . V_1099 = - 1 ;
V_139 . V_812 = - 1 ;
V_139 . V_815 = - 1 ;
if ( V_30 -> V_5 [ V_1100 ] )
V_139 . V_1095 =
F_32 ( V_30 -> V_5 [ V_1100 ] ) ;
if ( V_30 -> V_5 [ V_1101 ] )
V_139 . V_1096 =
F_32 ( V_30 -> V_5 [ V_1101 ] ) ;
if ( V_30 -> V_5 [ V_1102 ] )
V_139 . V_1097 =
F_32 ( V_30 -> V_5 [ V_1102 ] ) ;
if ( V_30 -> V_5 [ V_1103 ] ) {
V_139 . V_1104 =
F_21 ( V_30 -> V_5 [ V_1103 ] ) ;
V_139 . V_1105 =
F_22 ( V_30 -> V_5 [ V_1103 ] ) ;
}
if ( V_30 -> V_5 [ V_1106 ] )
V_139 . V_1098 = ! ! F_32 ( V_30 -> V_5 [ V_1106 ] ) ;
if ( V_30 -> V_5 [ V_1107 ] )
V_139 . V_1099 =
F_79 ( V_30 -> V_5 [ V_1107 ] ) ;
if ( V_30 -> V_5 [ V_811 ] ) {
if ( V_559 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_139 . V_812 =
F_217 ( V_30 -> V_5 [ V_811 ] ) ;
if ( V_139 . V_812 < 0 )
return - V_16 ;
if ( V_139 . V_812 != 0 &&
! ( V_7 -> V_18 . V_368 & V_813 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_814 ] ) {
T_2 V_24 ;
if ( V_559 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_32 ( V_30 -> V_5 [ V_814 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_139 . V_815 = V_24 ;
if ( V_139 . V_815 &&
! ( V_7 -> V_18 . V_368 & V_816 ) )
return - V_16 ;
}
if ( ! V_7 -> V_328 -> V_297 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_142 &&
V_559 -> V_28 -> V_141 != V_144 )
return - V_560 ;
F_116 ( V_17 ) ;
V_35 = F_218 ( V_7 , V_559 , & V_139 ) ;
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_219 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_140 = NULL ;
bool V_1108 ;
enum V_1109 V_1110 ;
V_22 V_660 ;
if ( F_220 ( ! F_221 ( V_1111 ) ) )
return - V_1112 ;
if ( V_30 -> V_5 [ V_1113 ] )
V_1110 =
F_4 ( V_30 -> V_5 [ V_1113 ] ) ;
else
V_1110 = V_1114 ;
switch ( V_1110 ) {
case V_1114 :
case V_1115 :
if ( ! V_30 -> V_5 [ V_1116 ] )
return - V_16 ;
V_140 = F_21 ( V_30 -> V_5 [ V_1116 ] ) ;
return F_222 ( V_140 , V_1110 ) ;
case V_1117 :
if ( V_30 -> V_5 [ V_659 ] ) {
V_660 = V_30 -> V_524 ;
V_1108 = ! ! V_30 -> V_5 [ V_1118 ] ;
} else {
V_660 = 0 ;
V_1108 = true ;
}
return F_223 ( V_1108 , V_660 ) ;
default:
return - V_16 ;
}
}
static int F_224 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_1119 V_1120 ;
int V_35 = 0 ;
void * V_360 ;
struct V_4 * V_1062 ;
struct V_31 * V_51 ;
if ( V_17 -> V_141 != V_145 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_1121 )
return - V_560 ;
F_116 ( V_17 ) ;
if ( ! V_17 -> V_1122 )
memcpy ( & V_1120 , & V_1123 , sizeof( V_1120 ) ) ;
else
V_35 = F_225 ( V_7 , V_559 , & V_1120 ) ;
F_118 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1124 ) ;
if ( ! V_360 )
goto V_620;
V_1062 = F_45 ( V_51 , V_1125 ) ;
if ( ! V_1062 )
goto V_59;
if ( F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_53 ( V_51 , V_1126 ,
V_1120 . V_1127 ) ||
F_53 ( V_51 , V_1128 ,
V_1120 . V_1129 ) ||
F_53 ( V_51 , V_1130 ,
V_1120 . V_1131 ) ||
F_53 ( V_51 , V_1132 ,
V_1120 . V_1133 ) ||
F_54 ( V_51 , V_1134 ,
V_1120 . V_1135 ) ||
F_54 ( V_51 , V_1136 ,
V_1120 . V_1137 ) ||
F_54 ( V_51 , V_1138 ,
V_1120 . V_1139 ) ||
F_54 ( V_51 , V_1140 ,
V_1120 . V_1141 ) ||
F_26 ( V_51 , V_1142 ,
V_1120 . V_1143 ) ||
F_54 ( V_51 , V_1144 ,
V_1120 . V_1145 ) ||
F_26 ( V_51 , V_1146 ,
V_1120 . V_1147 ) ||
F_53 ( V_51 , V_1148 ,
V_1120 . V_1149 ) ||
F_26 ( V_51 , V_1150 ,
V_1120 . V_1151 ) ||
F_53 ( V_51 , V_1152 ,
V_1120 . V_1153 ) ||
F_53 ( V_51 , V_1154 ,
V_1120 . V_1155 ) ||
F_53 ( V_51 , V_1156 ,
V_1120 . V_1157 ) ||
F_54 ( V_51 , V_1158 ,
V_1120 . V_1159 ) ||
F_53 ( V_51 , V_1160 ,
V_1120 . V_1161 ) ||
F_54 ( V_51 , V_1162 ,
V_1120 . V_1163 ) ||
F_54 ( V_51 , V_1164 ,
V_1120 . V_1165 ) ||
F_226 ( V_51 , V_1166 ,
V_1120 . V_1167 ) ||
F_26 ( V_51 , V_1168 ,
V_1120 . V_1099 ) ||
F_26 ( V_51 , V_1169 ,
V_1120 . V_1170 ) ||
F_53 ( V_51 , V_1171 ,
V_1120 . V_1172 ) ||
F_53 ( V_51 , V_1173 ,
V_1120 . V_1174 ) ||
F_26 ( V_51 , V_1175 ,
V_1120 . V_1176 ) ||
F_53 ( V_51 , V_1177 ,
V_1120 . V_1178 ) ||
F_26 ( V_51 , V_1179 ,
V_1120 . V_1180 ) )
goto V_59;
F_46 ( V_51 , V_1062 ) ;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_66 ( V_51 , V_360 ) ;
V_620:
F_76 ( V_51 ) ;
return - V_89 ;
}
static int F_227 ( const struct V_4 * V_622 , T_2 V_1181 , T_2 V_175 , bool * V_620 )
{
T_2 V_1182 = F_32 ( V_622 ) ;
if ( V_1182 < V_1181 || V_1182 > V_175 )
return - V_16 ;
* V_620 = V_1182 ;
return 0 ;
}
static int F_228 ( const struct V_4 * V_622 , T_2 V_1181 , T_2 V_175 , T_2 * V_620 )
{
T_2 V_1182 = F_32 ( V_622 ) ;
if ( V_1182 < V_1181 || V_1182 > V_175 )
return - V_16 ;
* V_620 = V_1182 ;
return 0 ;
}
static int F_229 ( const struct V_4 * V_622 , T_3 V_1181 , T_3 V_175 , T_3 * V_620 )
{
T_3 V_1182 = F_79 ( V_622 ) ;
if ( V_1182 < V_1181 || V_1182 > V_175 )
return - V_16 ;
* V_620 = V_1182 ;
return 0 ;
}
static int F_230 ( const struct V_4 * V_622 , V_22 V_1181 , V_22 V_175 , V_22 * V_620 )
{
V_22 V_1182 = F_4 ( V_622 ) ;
if ( V_1182 < V_1181 || V_1182 > V_175 )
return - V_16 ;
* V_620 = V_1182 ;
return 0 ;
}
static int F_231 ( const struct V_4 * V_622 , T_7 V_1181 , T_7 V_175 , T_7 * V_620 )
{
T_7 V_1182 = F_232 ( V_622 ) ;
if ( V_1182 < V_1181 || V_1182 > V_175 )
return - V_16 ;
* V_620 = V_1182 ;
return 0 ;
}
static int F_233 ( const struct V_4 * V_622 ,
enum V_1040 V_1181 ,
enum V_1040 V_175 ,
enum V_1040 * V_620 )
{
V_22 V_1182 = F_4 ( V_622 ) ;
if ( V_1182 < V_1181 || V_1182 > V_175 )
return - V_16 ;
* V_620 = V_1182 ;
return 0 ;
}
static int F_234 ( struct V_29 * V_30 ,
struct V_1119 * V_1183 ,
V_22 * V_1184 )
{
struct V_4 * V_93 [ V_1185 + 1 ] ;
V_22 V_707 = 0 ;
T_3 V_1099 ;
#define F_235 ( V_93 , V_1183 , T_8 , V_1181 , V_175 , V_707 , V_43 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr], min, max, &cfg->param)) \
return -EINVAL; \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1125 ] )
return - V_16 ;
if ( F_31 ( V_93 , V_1185 ,
V_30 -> V_5 [ V_1125 ] ,
V_1186 , V_30 -> V_127 ) )
return - V_16 ;
F_117 ( V_1185 > 32 ) ;
F_235 ( V_93 , V_1183 , V_1127 , 1 , 255 ,
V_707 , V_1126 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1129 , 1 , 255 ,
V_707 , V_1128 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1131 , 1 , 255 ,
V_707 , V_1130 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1133 , 0 , 255 ,
V_707 , V_1132 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1135 , 0 , 16 ,
V_707 , V_1134 ,
F_228 ) ;
F_235 ( V_93 , V_1183 , V_1137 , 1 , 255 ,
V_707 , V_1136 , F_228 ) ;
F_235 ( V_93 , V_1183 , V_1139 , 1 , 255 ,
V_707 , V_1138 ,
F_228 ) ;
F_235 ( V_93 , V_1183 , V_1141 , 0 , 1 ,
V_707 , V_1140 ,
F_227 ) ;
F_235 ( V_93 , V_1183 , V_1143 ,
1 , 255 , V_707 ,
V_1142 ,
F_230 ) ;
F_235 ( V_93 , V_1183 , V_1145 , 0 , 255 ,
V_707 , V_1144 ,
F_228 ) ;
F_235 ( V_93 , V_1183 , V_1147 , 1 , 65535 ,
V_707 , V_1146 ,
F_230 ) ;
F_235 ( V_93 , V_1183 , V_1149 , 1 , 65535 ,
V_707 , V_1148 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1151 ,
1 , 65535 , V_707 ,
V_1150 ,
F_230 ) ;
F_235 ( V_93 , V_1183 , V_1153 ,
1 , 65535 , V_707 ,
V_1152 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1155 ,
1 , 65535 , V_707 ,
V_1154 ,
F_229 ) ;
F_235 ( V_93 , V_1183 ,
V_1157 ,
1 , 65535 , V_707 ,
V_1156 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1159 , 0 , 4 ,
V_707 , V_1158 ,
F_228 ) ;
F_235 ( V_93 , V_1183 , V_1161 , 1 , 65535 ,
V_707 , V_1160 ,
F_229 ) ;
F_235 ( V_93 , V_1183 ,
V_1163 , 0 , 1 ,
V_707 , V_1162 ,
F_227 ) ;
F_235 ( V_93 , V_1183 , V_1165 , 0 , 1 ,
V_707 , V_1164 ,
F_227 ) ;
F_235 ( V_93 , V_1183 , V_1167 , - 255 , 0 ,
V_707 , V_1166 ,
F_231 ) ;
if ( V_93 [ V_1168 ] ) {
V_1099 = F_79 ( V_93 [ V_1168 ] ) ;
if ( V_1099 & ~ ( V_1187 |
V_1188 |
V_1189 ) )
return - V_16 ;
if ( ( V_1099 & V_1188 ) &&
( V_1099 & V_1189 ) )
return - V_16 ;
switch ( V_1099 & V_1187 ) {
case V_1190 :
case V_1191 :
if ( V_1099 & V_1189 )
return - V_16 ;
break;
case V_1192 :
case V_1193 :
if ( ! ( V_1099 & V_1189 ) )
return - V_16 ;
break;
}
V_1183 -> V_1099 = V_1099 ;
V_707 |= ( 1 << ( V_1168 - 1 ) ) ;
}
F_235 ( V_93 , V_1183 , V_1170 ,
1 , 65535 , V_707 ,
V_1169 ,
F_230 ) ;
F_235 ( V_93 , V_1183 , V_1172 , 1 , 65535 ,
V_707 , V_1171 ,
F_229 ) ;
F_235 ( V_93 , V_1183 ,
V_1174 ,
1 , 65535 , V_707 ,
V_1173 ,
F_229 ) ;
F_235 ( V_93 , V_1183 , V_1176 ,
V_1194 ,
V_1043 ,
V_707 , V_1175 ,
F_233 ) ;
F_235 ( V_93 , V_1183 , V_1178 ,
0 , 65535 , V_707 ,
V_1177 , F_229 ) ;
F_235 ( V_93 , V_1183 , V_1180 , 0 , 0xffffffff ,
V_707 , V_1179 ,
F_230 ) ;
if ( V_1184 )
* V_1184 = V_707 ;
return 0 ;
#undef F_235
}
static int F_236 ( struct V_29 * V_30 ,
struct V_1195 * V_1196 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_4 * V_93 [ V_1197 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1198 ] )
return - V_16 ;
if ( F_31 ( V_93 , V_1197 ,
V_30 -> V_5 [ V_1198 ] ,
V_1199 , V_30 -> V_127 ) )
return - V_16 ;
if ( V_93 [ V_1200 ] )
V_1196 -> V_1201 =
( F_32 ( V_93 [ V_1200 ] ) ) ?
V_1202 :
V_1203 ;
if ( V_93 [ V_1204 ] )
V_1196 -> V_1205 =
( F_32 ( V_93 [ V_1204 ] ) ) ?
V_1206 :
V_1207 ;
if ( V_93 [ V_1208 ] )
V_1196 -> V_1209 =
( F_32 ( V_93 [ V_1208 ] ) ) ?
V_1210 :
V_1211 ;
if ( V_93 [ V_1212 ] ) {
struct V_4 * V_1213 =
V_93 [ V_1212 ] ;
if ( ! F_20 ( V_1213 ) )
return - V_16 ;
V_1196 -> V_1214 = F_21 ( V_1213 ) ;
V_1196 -> V_1215 = F_22 ( V_1213 ) ;
}
if ( V_93 [ V_1216 ] &&
! ( V_7 -> V_18 . V_368 & V_1217 ) )
return - V_16 ;
V_1196 -> V_1218 = F_170 ( V_93 [ V_1216 ] ) ;
V_1196 -> V_1219 = F_170 ( V_93 [ V_1220 ] ) ;
V_1196 -> V_1221 = F_170 ( V_93 [ V_1222 ] ) ;
if ( V_1196 -> V_1221 )
V_1196 -> V_1218 = true ;
if ( V_93 [ V_1223 ] ) {
if ( ! V_1196 -> V_1218 )
return - V_16 ;
V_1196 -> V_1224 =
F_32 ( V_93 [ V_1223 ] ) ;
}
return 0 ;
}
static int F_237 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_1119 V_1183 ;
V_22 V_707 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_295 )
return - V_560 ;
V_35 = F_234 ( V_30 , & V_1183 , & V_707 ) ;
if ( V_35 )
return V_35 ;
F_116 ( V_17 ) ;
if ( ! V_17 -> V_1122 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_238 ( V_7 , V_559 , V_707 , & V_1183 ) ;
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_239 ( const struct V_1225 * V_1226 ,
struct V_31 * V_51 )
{
struct V_4 * V_1227 ;
unsigned int V_160 ;
if ( F_61 ( V_51 , V_1116 , V_1226 -> V_1228 ) ||
( V_1226 -> V_1229 &&
F_54 ( V_51 , V_1230 , V_1226 -> V_1229 ) ) )
goto V_59;
V_1227 = F_45 ( V_51 , V_1231 ) ;
if ( ! V_1227 )
goto V_59;
for ( V_160 = 0 ; V_160 < V_1226 -> V_1232 ; V_160 ++ ) {
struct V_4 * V_1233 ;
const struct V_1234 * V_1235 ;
const struct V_1236 * V_1237 ;
const struct V_1238 * V_1239 ;
unsigned int V_1240 ;
V_1235 = & V_1226 -> V_1241 [ V_160 ] ;
V_1237 = & V_1235 -> V_1237 ;
V_1239 = & V_1235 -> V_1239 ;
V_1233 = F_45 ( V_51 , V_160 ) ;
if ( ! V_1233 )
goto V_59;
V_1240 = V_1237 -> V_1240 ;
if ( ! V_1240 )
V_1240 = F_240 ( V_1226 ,
V_1235 ) ;
if ( F_26 ( V_51 , V_1242 ,
V_1235 -> V_49 ) ||
F_26 ( V_51 , V_1243 ,
V_1237 -> V_1244 ) ||
F_26 ( V_51 , V_1245 ,
V_1237 -> V_1246 ) ||
F_26 ( V_51 , V_1247 ,
V_1240 ) ||
F_26 ( V_51 , V_1248 ,
V_1239 -> V_1249 ) ||
F_26 ( V_51 , V_1250 ,
V_1239 -> V_1251 ) ||
F_26 ( V_51 , V_1252 ,
V_1235 -> V_72 ) )
goto V_59;
F_46 ( V_51 , V_1233 ) ;
}
F_46 ( V_51 , V_1227 ) ;
return 0 ;
V_59:
return - V_515 ;
}
static int F_241 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1225 * V_1226 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_89 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1253 ) ;
if ( ! V_360 )
goto V_1254;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1255 ;
V_7 = F_12 ( F_95 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_76 ( V_51 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1255 = V_18 -> V_497 &
V_498 ;
V_1226 = F_242 ( V_18 ) ;
if ( F_60 ( ! V_1226 && V_1255 ) ) {
F_76 ( V_51 ) ;
return - V_16 ;
}
if ( V_1226 &&
F_26 ( V_51 , V_26 , F_243 ( V_18 ) ) )
goto V_59;
}
if ( ! V_18 && F_244 () &&
F_26 ( V_51 , V_1113 ,
V_1115 ) )
goto V_59;
F_245 () ;
if ( ! V_1226 )
V_1226 = F_246 ( V_1111 ) ;
if ( F_239 ( V_1226 , V_51 ) )
goto V_1256;
F_247 () ;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_1256:
F_247 () ;
V_59:
F_66 ( V_51 , V_360 ) ;
V_1254:
F_76 ( V_51 ) ;
return - V_515 ;
}
static int F_248 ( struct V_31 * V_51 , struct V_33 * V_34 ,
V_22 V_48 , int V_49 , struct V_18 * V_18 ,
const struct V_1225 * V_1226 )
{
void * V_360 = F_23 ( V_51 , F_72 ( V_34 -> V_32 ) . V_47 , V_48 , V_49 ,
V_1253 ) ;
if ( ! V_360 )
return - 1 ;
F_249 ( V_34 , V_360 , & V_38 ) ;
if ( F_239 ( V_1226 , V_51 ) )
goto V_59;
if ( ! V_18 && F_244 () &&
F_26 ( V_51 , V_1113 ,
V_1115 ) )
goto V_59;
if ( V_18 &&
F_26 ( V_51 , V_26 , F_243 ( V_18 ) ) )
goto V_59;
if ( V_18 && V_18 -> V_497 & V_498 &&
F_27 ( V_51 , V_499 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int F_250 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1225 * V_1226 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1257 , V_519 = V_34 -> args [ 2 ] ;
F_69 () ;
if ( V_1111 && V_519 == 0 ) {
V_35 = F_248 ( V_32 , V_34 , V_34 -> V_36 -> V_520 ,
V_521 , NULL ,
F_251 ( V_1111 ) ) ;
if ( V_35 < 0 )
goto V_967;
}
V_1257 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1226 = F_242 ( & V_7 -> V_18 ) ;
if ( ! V_1226 )
continue;
if ( ++ V_1257 <= V_519 )
continue;
V_35 = F_248 ( V_32 , V_34 , V_34 -> V_36 -> V_520 ,
V_521 , & V_7 -> V_18 , V_1226 ) ;
if ( V_35 < 0 ) {
V_1257 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1257 ;
V_35 = V_32 -> V_45 ;
V_967:
F_70 () ;
return V_35 ;
}
static int F_252 ( struct V_4 * V_93 [] ,
struct V_1234 * V_1235 )
{
struct V_1236 * V_1237 = & V_1235 -> V_1237 ;
struct V_1238 * V_1239 = & V_1235 -> V_1239 ;
if ( ! V_93 [ V_1242 ] )
return - V_16 ;
if ( ! V_93 [ V_1243 ] )
return - V_16 ;
if ( ! V_93 [ V_1245 ] )
return - V_16 ;
if ( ! V_93 [ V_1247 ] )
return - V_16 ;
if ( ! V_93 [ V_1250 ] )
return - V_16 ;
V_1235 -> V_49 = F_4 ( V_93 [ V_1242 ] ) ;
V_1237 -> V_1244 =
F_4 ( V_93 [ V_1243 ] ) ;
V_1237 -> V_1246 =
F_4 ( V_93 [ V_1245 ] ) ;
V_1237 -> V_1240 =
F_4 ( V_93 [ V_1247 ] ) ;
V_1239 -> V_1251 =
F_4 ( V_93 [ V_1250 ] ) ;
if ( V_93 [ V_1248 ] )
V_1239 -> V_1249 =
F_4 ( V_93 [ V_1248 ] ) ;
if ( V_93 [ V_1252 ] )
V_1235 -> V_72 =
F_4 ( V_93 [ V_1252 ] ) ;
return 0 ;
}
static int F_253 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_93 [ V_1258 + 1 ] ;
struct V_4 * V_1233 ;
char * V_1228 ;
int V_1259 , V_1260 ;
V_22 V_1261 = 0 , V_1262 = 0 , V_1263 ;
enum V_1264 V_1229 = V_1265 ;
struct V_1225 * V_1266 ;
if ( ! V_30 -> V_5 [ V_1116 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1231 ] )
return - V_16 ;
V_1228 = F_21 ( V_30 -> V_5 [ V_1116 ] ) ;
if ( V_30 -> V_5 [ V_1230 ] )
V_1229 = F_32 ( V_30 -> V_5 [ V_1230 ] ) ;
F_36 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1261 ++ ;
if ( V_1261 > V_1267 )
return - V_16 ;
}
if ( ! F_254 ( V_1228 ) )
return - V_16 ;
V_1263 = sizeof( struct V_1225 ) +
V_1261 * sizeof( struct V_1234 ) ;
V_1266 = F_37 ( V_1263 , V_135 ) ;
if ( ! V_1266 )
return - V_136 ;
V_1266 -> V_1232 = V_1261 ;
V_1266 -> V_1228 [ 0 ] = V_1228 [ 0 ] ;
V_1266 -> V_1228 [ 1 ] = V_1228 [ 1 ] ;
if ( F_255 ( V_1229 ) )
V_1266 -> V_1229 = V_1229 ;
F_36 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1260 = F_31 ( V_93 , V_1258 ,
V_1233 , V_1268 ,
V_30 -> V_127 ) ;
if ( V_1260 )
goto V_1269;
V_1260 = F_252 ( V_93 , & V_1266 -> V_1241 [ V_1262 ] ) ;
if ( V_1260 )
goto V_1269;
V_1262 ++ ;
if ( V_1262 > V_1267 ) {
V_1260 = - V_16 ;
goto V_1269;
}
}
return F_256 ( V_1266 , V_1270 ) ;
V_1269:
F_39 ( V_1266 ) ;
return V_1260 ;
}
static int F_257 ( struct V_4 * V_1271 )
{
struct V_4 * V_1272 , * V_1273 ;
int V_441 = 0 , V_1274 , V_1275 ;
F_36 (attr1, freqs, tmp1)
if ( F_22 ( V_1272 ) != sizeof( V_22 ) )
return 0 ;
F_36 (attr1, freqs, tmp1) {
V_441 ++ ;
F_36 (attr2, freqs, tmp2)
if ( V_1272 != V_1273 &&
F_4 ( V_1272 ) == F_4 ( V_1273 ) )
return 0 ;
}
return V_441 ;
}
static bool F_258 ( struct V_18 * V_18 , enum V_366 V_1276 )
{
return V_1276 < V_437 && V_18 -> V_438 [ V_1276 ] ;
}
static int F_259 ( struct V_4 * V_622 , struct V_18 * V_18 ,
struct V_1277 * V_1278 )
{
struct V_4 * V_43 [ V_1279 + 1 ] ;
struct V_4 * V_1280 ;
int V_35 ;
bool V_27 = false ;
int V_160 ;
V_1280 = F_21 ( V_622 ) ;
if ( ! F_260 ( V_1280 , F_22 ( V_1280 ) ) )
return - V_16 ;
V_35 = F_31 ( V_43 , V_1279 , V_1280 ,
V_1281 , NULL ) ;
if ( V_35 )
return V_35 ;
for ( V_160 = 0 ; V_160 <= V_1279 ; V_160 ++ ) {
if ( V_43 [ V_160 ] ) {
if ( V_27 )
return - V_16 ;
V_27 = true ;
}
}
V_1278 -> V_1282 = V_1283 ;
if ( V_43 [ V_1284 ] )
V_1278 -> V_1282 = V_1284 ;
if ( V_43 [ V_1285 ] ) {
V_1278 -> V_1282 = V_1285 ;
V_1278 -> T_8 . V_1286 =
F_4 ( V_43 [ V_1285 ] ) ;
if ( ! F_258 ( V_18 , V_1278 -> T_8 . V_1286 ) )
return - V_16 ;
}
if ( V_43 [ V_1287 ] ) {
struct V_1288 * V_1289 ;
V_1289 = F_21 ( V_43 [ V_1287 ] ) ;
V_1278 -> V_1282 = V_1287 ;
V_1278 -> T_8 . V_1290 . V_367 = V_1289 -> V_367 ;
V_1278 -> T_8 . V_1290 . V_1291 = V_1289 -> V_1291 ;
if ( ! F_258 ( V_18 , V_1278 -> T_8 . V_1290 . V_367 ) )
return - V_16 ;
}
if ( V_1278 -> V_1282 == V_1283 )
return - V_16 ;
if ( ! ( V_18 -> V_503 & F_113 ( V_1278 -> V_1282 ) ) )
return - V_16 ;
return 0 ;
}
static int F_261 ( struct V_4 * * V_5 ,
T_2 * V_675 , T_2 * V_1292 )
{
int V_160 ;
if ( ! V_5 [ V_567 ] && ! V_5 [ V_1293 ] ) {
F_262 ( V_675 ) ;
F_262 ( V_1292 ) ;
V_675 [ 0 ] = 0x2 ;
V_1292 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_567 ] || ! V_5 [ V_1293 ] )
return - V_16 ;
memcpy ( V_675 , F_21 ( V_5 [ V_567 ] ) , V_607 ) ;
memcpy ( V_1292 , F_21 ( V_5 [ V_1293 ] ) , V_607 ) ;
if ( ! F_263 ( V_1292 ) ||
F_263 ( V_675 ) )
return - V_16 ;
for ( V_160 = 0 ; V_160 < V_607 ; V_160 ++ )
V_675 [ V_160 ] &= V_1292 [ V_160 ] ;
return 0 ;
}
static bool F_264 ( struct V_1 * V_17 )
{
F_41 ( V_17 ) ;
if ( ! F_265 ( V_17 ) )
return true ;
if ( ! ( V_17 -> V_540 . V_53 -> V_49 & V_65 ) )
return true ;
return F_266 ( V_17 -> V_18 ) ;
}
static int F_267 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
struct V_1294 * V_1295 ;
struct V_4 * V_43 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1296 = 0 , V_441 , V_160 ;
T_4 V_1215 ;
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_17 -> V_141 == V_154 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_1297 )
return - V_560 ;
if ( V_7 -> V_1298 || V_7 -> V_1299 ) {
V_35 = - V_564 ;
goto V_1300;
}
if ( V_30 -> V_5 [ V_1301 ] ) {
V_441 = F_257 (
V_30 -> V_5 [ V_1301 ] ) ;
if ( ! V_441 ) {
V_35 = - V_16 ;
goto V_1300;
}
} else {
V_441 = F_268 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1302 ] )
F_36 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1296 ++ ;
if ( V_1296 > V_18 -> V_386 ) {
V_35 = - V_16 ;
goto V_1300;
}
if ( V_30 -> V_5 [ V_752 ] )
V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
else
V_1215 = 0 ;
if ( V_1215 > V_18 -> V_390 ) {
V_35 = - V_16 ;
goto V_1300;
}
V_1295 = F_37 ( sizeof( * V_1295 )
+ sizeof( * V_1295 -> V_1303 ) * V_1296
+ sizeof( * V_1295 -> V_442 ) * V_441
+ V_1215 , V_135 ) ;
if ( ! V_1295 ) {
V_35 = - V_136 ;
goto V_1300;
}
if ( V_1296 )
V_1295 -> V_1303 = ( void * ) & V_1295 -> V_442 [ V_441 ] ;
V_1295 -> V_1296 = V_1296 ;
if ( V_1215 ) {
if ( V_1296 )
V_1295 -> V_1214 = ( void * ) ( V_1295 -> V_1303 + V_1296 ) ;
else
V_1295 -> V_1214 = ( void * ) ( V_1295 -> V_442 + V_441 ) ;
}
V_160 = 0 ;
if ( V_30 -> V_5 [ V_1301 ] ) {
F_36 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_52 * V_53 ;
V_53 = F_43 ( V_18 , F_4 ( V_43 ) ) ;
if ( ! V_53 ) {
V_35 = - V_16 ;
goto V_1304;
}
if ( V_53 -> V_49 & V_60 )
continue;
V_1295 -> V_442 [ V_160 ] = V_53 ;
V_160 ++ ;
}
} else {
enum V_366 V_367 ;
for ( V_367 = 0 ; V_367 < V_437 ; V_367 ++ ) {
int V_162 ;
if ( ! V_18 -> V_438 [ V_367 ] )
continue;
for ( V_162 = 0 ; V_162 < V_18 -> V_438 [ V_367 ] -> V_441 ; V_162 ++ ) {
struct V_52 * V_53 ;
V_53 = & V_18 -> V_438 [ V_367 ] -> V_442 [ V_162 ] ;
if ( V_53 -> V_49 & V_60 )
continue;
V_1295 -> V_442 [ V_160 ] = V_53 ;
V_160 ++ ;
}
}
}
if ( ! V_160 ) {
V_35 = - V_16 ;
goto V_1304;
}
V_1295 -> V_441 = V_160 ;
F_116 ( V_17 ) ;
if ( ! F_264 ( V_17 ) ) {
struct V_52 * V_53 ;
if ( V_1295 -> V_441 != 1 ) {
F_118 ( V_17 ) ;
V_35 = - V_564 ;
goto V_1304;
}
V_53 = V_1295 -> V_442 [ 0 ] ;
if ( V_53 -> V_58 != V_17 -> V_540 . V_53 -> V_58 ) {
F_118 ( V_17 ) ;
V_35 = - V_564 ;
goto V_1304;
}
}
F_118 ( V_17 ) ;
V_160 = 0 ;
if ( V_1296 ) {
F_36 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_22 ( V_43 ) > V_650 ) {
V_35 = - V_16 ;
goto V_1304;
}
V_1295 -> V_1303 [ V_160 ] . V_612 = F_22 ( V_43 ) ;
memcpy ( V_1295 -> V_1303 [ V_160 ] . V_614 , F_21 ( V_43 ) , F_22 ( V_43 ) ) ;
V_160 ++ ;
}
}
if ( V_30 -> V_5 [ V_752 ] ) {
V_1295 -> V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
memcpy ( ( void * ) V_1295 -> V_1214 ,
F_21 ( V_30 -> V_5 [ V_752 ] ) ,
V_1295 -> V_1215 ) ;
}
for ( V_160 = 0 ; V_160 < V_437 ; V_160 ++ )
if ( V_18 -> V_438 [ V_160 ] )
V_1295 -> V_705 [ V_160 ] =
( 1 << V_18 -> V_438 [ V_160 ] -> V_264 ) - 1 ;
if ( V_30 -> V_5 [ V_1305 ] ) {
F_36 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_366 V_367 = F_156 ( V_43 ) ;
if ( V_367 < 0 || V_367 >= V_437 ) {
V_35 = - V_16 ;
goto V_1304;
}
if ( ! V_18 -> V_438 [ V_367 ] )
continue;
V_35 = F_269 ( V_18 -> V_438 [ V_367 ] ,
F_21 ( V_43 ) ,
F_22 ( V_43 ) ,
& V_1295 -> V_705 [ V_367 ] ) ;
if ( V_35 )
goto V_1304;
}
}
if ( V_30 -> V_5 [ V_1306 ] ) {
if ( ! F_112 ( V_18 ,
V_1307 ) ) {
V_35 = - V_560 ;
goto V_1304;
}
V_1295 -> V_1308 =
F_79 ( V_30 -> V_5 [ V_1306 ] ) ;
V_1295 -> V_1309 =
F_170 ( V_30 -> V_5 [ V_1310 ] ) ;
}
if ( V_30 -> V_5 [ V_1311 ] ) {
V_1295 -> V_49 = F_4 (
V_30 -> V_5 [ V_1311 ] ) ;
if ( ( V_1295 -> V_49 & V_1312 ) &&
! ( V_18 -> V_368 & V_1313 ) ) {
V_35 = - V_560 ;
goto V_1304;
}
if ( V_1295 -> V_49 & V_1314 ) {
if ( ! ( V_18 -> V_368 &
V_1315 ) ) {
V_35 = - V_560 ;
goto V_1304;
}
if ( V_17 -> V_149 ) {
V_35 = - V_560 ;
goto V_1304;
}
V_35 = F_261 ( V_30 -> V_5 ,
V_1295 -> V_675 ,
V_1295 -> V_1292 ) ;
if ( V_35 )
goto V_1304;
}
}
V_1295 -> V_1316 =
F_170 ( V_30 -> V_5 [ V_1317 ] ) ;
if ( V_30 -> V_5 [ V_1318 ] )
memcpy ( V_1295 -> V_566 ,
F_21 ( V_30 -> V_5 [ V_1318 ] ) , V_607 ) ;
else if ( ! ( V_1295 -> V_49 & V_1314 ) &&
V_30 -> V_5 [ V_567 ] )
memcpy ( V_1295 -> V_566 , F_21 ( V_30 -> V_5 [ V_567 ] ) ,
V_607 ) ;
else
F_270 ( V_1295 -> V_566 ) ;
V_1295 -> V_17 = V_17 ;
V_1295 -> V_18 = & V_7 -> V_18 ;
V_1295 -> V_1319 = V_1320 ;
V_7 -> V_1298 = V_1295 ;
V_35 = F_271 ( V_7 , V_1295 ) ;
if ( ! V_35 ) {
F_272 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_273 ( V_17 -> V_19 ) ;
} else {
V_1304:
V_7 -> V_1298 = NULL ;
F_39 ( V_1295 ) ;
}
V_1300:
return V_35 ;
}
static int F_274 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_1321 )
return - V_560 ;
if ( V_7 -> V_1299 )
return 0 ;
if ( ! V_7 -> V_1298 )
return - V_681 ;
F_275 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_276 ( struct V_18 * V_18 , int V_1322 ,
struct V_1323 * V_1295 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_160 = 0 ;
struct V_4 * V_43 ;
if ( ! V_5 [ V_1324 ] ) {
V_22 V_1325 ;
V_1325 = F_4 ( V_5 [ V_1326 ] ) ;
if ( ! V_1325 )
return - V_16 ;
V_1295 -> V_1327 [ 0 ] . V_1325 =
F_277 ( V_1325 , V_1328 ) ;
if ( ! V_1295 -> V_1327 [ 0 ] . V_1325 )
return - V_16 ;
if ( V_1295 -> V_1327 [ 0 ] . V_1325 >
V_18 -> V_398 )
V_1295 -> V_1327 [ 0 ] . V_1325 =
V_18 -> V_398 ;
return 0 ;
}
F_36 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1329 [ V_1330 + 1 ] ;
if ( F_60 ( V_160 >= V_1322 ) )
return - V_16 ;
V_35 = F_31 ( V_1329 , V_1330 ,
V_43 , V_1331 , NULL ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1329 [ V_1332 ] )
return - V_16 ;
V_1295 -> V_1327 [ V_160 ] . V_1325 =
F_4 ( V_1329 [ V_1332 ] ) ;
if ( ! V_1295 -> V_1327 [ V_160 ] . V_1325 ||
V_1295 -> V_1327 [ V_160 ] . V_1325 >
V_18 -> V_398 )
return - V_16 ;
if ( V_1329 [ V_1333 ] ) {
V_1295 -> V_1327 [ V_160 ] . V_1334 =
F_4 ( V_1329 [ V_1333 ] ) ;
if ( ! V_1295 -> V_1327 [ V_160 ] . V_1334 ||
( V_1295 -> V_1327 [ V_160 ] . V_1334 >
V_18 -> V_400 ) )
return - V_16 ;
} else if ( V_160 < V_1322 - 1 ) {
return - V_16 ;
}
V_160 ++ ;
}
if ( V_1295 -> V_1327 [ V_1322 - 1 ] . V_1334 )
return - V_16 ;
return 0 ;
}
static struct V_1323 *
F_278 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 , int V_394 )
{
struct V_1323 * V_1295 ;
struct V_4 * V_43 ;
int V_35 , V_24 , V_1296 = 0 , V_1335 = 0 , V_441 , V_160 , V_1322 = 0 ;
enum V_366 V_367 ;
T_4 V_1215 ;
struct V_4 * V_93 [ V_1336 + 1 ] ;
T_7 V_1337 = V_1338 ;
if ( ! F_20 ( V_5 [ V_752 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1301 ] ) {
V_441 = F_257 (
V_5 [ V_1301 ] ) ;
if ( ! V_441 )
return F_3 ( - V_16 ) ;
} else {
V_441 = F_268 ( V_18 ) ;
}
if ( V_5 [ V_1302 ] )
F_36 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1296 ++ ;
if ( V_1296 > V_18 -> V_388 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1339 ] ) {
F_36 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1340 ;
V_35 = F_31 ( V_93 ,
V_1336 ,
V_43 , V_1341 ,
NULL ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_93 [ V_1342 ] &&
V_93 [ V_1343 ] )
return F_3 ( - V_16 ) ;
if ( V_93 [ V_1342 ] ||
V_93 [ V_1343 ] ) {
V_1335 ++ ;
continue;
}
V_1340 = V_93 [ V_1344 ] ;
if ( V_1340 )
V_1337 = F_232 ( V_1340 ) ;
}
}
if ( ! V_1335 && V_1337 != V_1338 )
V_1335 = 1 ;
if ( V_1335 > V_394 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_752 ] )
V_1215 = F_22 ( V_5 [ V_752 ] ) ;
else
V_1215 = 0 ;
if ( V_1215 > V_18 -> V_392 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1324 ] ) {
if ( V_5 [ V_1326 ] )
return F_3 ( - V_16 ) ;
F_36 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1322 ++ ;
} else {
if ( ! V_5 [ V_1326 ] )
return F_3 ( - V_16 ) ;
V_1322 = 1 ;
}
if ( ! V_1322 || V_1322 > V_18 -> V_396 )
return F_3 ( - V_16 ) ;
if ( ! F_112 (
V_18 , V_1345 ) &&
( V_5 [ V_1346 ] ||
V_5 [ V_1347 ] ) )
return F_3 ( - V_16 ) ;
V_1295 = F_37 ( sizeof( * V_1295 )
+ sizeof( * V_1295 -> V_1303 ) * V_1296
+ sizeof( * V_1295 -> V_1348 ) * V_1335
+ sizeof( * V_1295 -> V_1327 ) * V_1322
+ sizeof( * V_1295 -> V_442 ) * V_441
+ V_1215 , V_135 ) ;
if ( ! V_1295 )
return F_3 ( - V_136 ) ;
if ( V_1296 )
V_1295 -> V_1303 = ( void * ) & V_1295 -> V_442 [ V_441 ] ;
V_1295 -> V_1296 = V_1296 ;
if ( V_1215 ) {
if ( V_1296 )
V_1295 -> V_1214 = ( void * ) ( V_1295 -> V_1303 + V_1296 ) ;
else
V_1295 -> V_1214 = ( void * ) ( V_1295 -> V_442 + V_441 ) ;
}
if ( V_1335 ) {
if ( V_1295 -> V_1214 )
V_1295 -> V_1348 = ( void * ) ( V_1295 -> V_1214 + V_1215 ) ;
else if ( V_1296 )
V_1295 -> V_1348 =
( void * ) ( V_1295 -> V_1303 + V_1296 ) ;
else
V_1295 -> V_1348 =
( void * ) ( V_1295 -> V_442 + V_441 ) ;
}
V_1295 -> V_1335 = V_1335 ;
if ( V_1335 )
V_1295 -> V_1327 = ( void * ) ( V_1295 -> V_1348 +
V_1335 ) ;
else if ( V_1295 -> V_1214 )
V_1295 -> V_1327 = ( void * ) ( V_1295 -> V_1214 + V_1215 ) ;
else if ( V_1296 )
V_1295 -> V_1327 = ( void * ) ( V_1295 -> V_1303 + V_1296 ) ;
else
V_1295 -> V_1327 = ( void * ) ( V_1295 -> V_442 + V_441 ) ;
V_1295 -> V_1349 = V_1322 ;
V_160 = 0 ;
if ( V_5 [ V_1301 ] ) {
F_36 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_52 * V_53 ;
V_53 = F_43 ( V_18 , F_4 ( V_43 ) ) ;
if ( ! V_53 ) {
V_35 = - V_16 ;
goto V_1304;
}
if ( V_53 -> V_49 & V_60 )
continue;
V_1295 -> V_442 [ V_160 ] = V_53 ;
V_160 ++ ;
}
} else {
for ( V_367 = 0 ; V_367 < V_437 ; V_367 ++ ) {
int V_162 ;
if ( ! V_18 -> V_438 [ V_367 ] )
continue;
for ( V_162 = 0 ; V_162 < V_18 -> V_438 [ V_367 ] -> V_441 ; V_162 ++ ) {
struct V_52 * V_53 ;
V_53 = & V_18 -> V_438 [ V_367 ] -> V_442 [ V_162 ] ;
if ( V_53 -> V_49 & V_60 )
continue;
V_1295 -> V_442 [ V_160 ] = V_53 ;
V_160 ++ ;
}
}
}
if ( ! V_160 ) {
V_35 = - V_16 ;
goto V_1304;
}
V_1295 -> V_441 = V_160 ;
V_160 = 0 ;
if ( V_1296 ) {
F_36 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_22 ( V_43 ) > V_650 ) {
V_35 = - V_16 ;
goto V_1304;
}
V_1295 -> V_1303 [ V_160 ] . V_612 = F_22 ( V_43 ) ;
memcpy ( V_1295 -> V_1303 [ V_160 ] . V_614 , F_21 ( V_43 ) ,
F_22 ( V_43 ) ) ;
V_160 ++ ;
}
}
V_160 = 0 ;
if ( V_5 [ V_1339 ] ) {
F_36 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_614 , * V_566 , * V_1340 ;
V_35 = F_31 ( V_93 ,
V_1336 ,
V_43 , V_1341 ,
NULL ) ;
if ( V_35 )
goto V_1304;
V_614 = V_93 [ V_1342 ] ;
V_566 = V_93 [ V_1343 ] ;
if ( V_614 || V_566 ) {
if ( F_60 ( V_160 >= V_1335 ) ) {
V_35 = - V_16 ;
goto V_1304;
}
if ( V_614 ) {
if ( F_22 ( V_614 ) > V_650 ) {
V_35 = - V_16 ;
goto V_1304;
}
memcpy ( V_1295 -> V_1348 [ V_160 ] . V_614 . V_614 ,
F_21 ( V_614 ) , F_22 ( V_614 ) ) ;
V_1295 -> V_1348 [ V_160 ] . V_614 . V_612 =
F_22 ( V_614 ) ;
}
if ( V_566 ) {
if ( F_22 ( V_566 ) != V_607 ) {
V_35 = - V_16 ;
goto V_1304;
}
memcpy ( V_1295 -> V_1348 [ V_160 ] . V_566 ,
F_21 ( V_566 ) , V_607 ) ;
}
V_1295 -> V_1348 [ V_160 ] . V_1350 =
V_1337 ;
V_1340 = V_93 [ V_1344 ] ;
if ( V_1340 )
V_1295 -> V_1348 [ V_160 ] . V_1350 =
F_232 ( V_1340 ) ;
}
V_160 ++ ;
}
if ( V_160 == 0 && V_1335 )
V_1295 -> V_1348 [ 0 ] . V_1350 = V_1337 ;
V_1295 -> V_1351 = V_1352 ;
for ( V_160 = 0 ; V_160 < V_1335 ; V_160 ++ )
V_1295 -> V_1351 =
V_1181 ( V_1295 -> V_1348 [ V_160 ] . V_1350 ,
V_1295 -> V_1351 ) ;
} else {
V_1295 -> V_1351 = V_1338 ;
}
if ( V_1215 ) {
V_1295 -> V_1215 = V_1215 ;
memcpy ( ( void * ) V_1295 -> V_1214 ,
F_21 ( V_5 [ V_752 ] ) ,
V_1295 -> V_1215 ) ;
}
if ( V_5 [ V_1311 ] ) {
V_1295 -> V_49 = F_4 (
V_5 [ V_1311 ] ) ;
if ( ( V_1295 -> V_49 & V_1312 ) &&
! ( V_18 -> V_368 & V_1313 ) ) {
V_35 = - V_560 ;
goto V_1304;
}
if ( V_1295 -> V_49 & V_1314 ) {
V_22 V_1353 = V_1354 ;
if ( ! V_17 )
V_1353 = V_1355 ;
if ( ! ( V_18 -> V_368 & V_1353 ) ) {
V_35 = - V_560 ;
goto V_1304;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_560 ;
goto V_1304;
}
V_35 = F_261 ( V_5 , V_1295 -> V_675 ,
V_1295 -> V_1292 ) ;
if ( V_35 )
goto V_1304;
}
}
if ( V_5 [ V_1356 ] )
V_1295 -> V_1357 =
F_4 ( V_5 [ V_1356 ] ) ;
if ( V_5 [ V_1346 ] ) {
V_1295 -> V_1358 = F_217 (
V_5 [ V_1346 ] ) ;
V_1295 -> V_1359 = true ;
}
if ( V_1295 -> V_1359 &&
V_5 [ V_1347 ] ) {
struct V_1288 * V_1360 ;
V_1360 = F_21 (
V_5 [ V_1347 ] ) ;
V_1295 -> V_1360 . V_367 = V_1360 -> V_367 ;
V_1295 -> V_1360 . V_1291 = V_1360 -> V_1291 ;
if ( ! F_258 ( V_18 , V_1295 -> V_1360 . V_367 ) ) {
V_35 = - V_16 ;
goto V_1304;
}
}
V_35 = F_276 ( V_18 , V_1322 , V_1295 , V_5 ) ;
if ( V_35 )
goto V_1304;
V_1295 -> V_1319 = V_1320 ;
return V_1295 ;
V_1304:
F_39 ( V_1295 ) ;
return F_3 ( V_35 ) ;
}
static int F_279 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_1323 * V_1361 ;
bool V_1362 ;
int V_35 ;
if ( ! V_7 -> V_18 . V_338 || ! V_7 -> V_328 -> V_339 )
return - V_560 ;
V_1362 = V_30 -> V_5 [ V_1363 ] ;
V_35 = F_280 ( V_7 , V_1362 ) ;
if ( V_35 )
return V_35 ;
V_1361 = F_278 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ,
V_7 -> V_18 . V_394 ) ;
V_35 = F_281 ( V_1361 ) ;
if ( V_35 )
goto V_967;
if ( V_1362 && V_7 -> V_18 . V_338 > 1 ) {
while ( ! V_1361 -> V_1364 )
V_1361 -> V_1364 = V_7 -> V_18 . V_1365 ++ ;
}
V_35 = F_282 ( V_7 , V_559 , V_1361 ) ;
if ( V_35 )
goto V_1304;
V_1361 -> V_559 = V_559 ;
V_1361 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_659 ] )
V_1361 -> V_660 = V_30 -> V_524 ;
F_283 ( V_7 , V_1361 ) ;
F_284 ( V_1361 , V_1366 ) ;
return 0 ;
V_1304:
F_39 ( V_1361 ) ;
V_967:
return V_35 ;
}
static int F_285 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1323 * V_1367 ;
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
T_1 V_673 ;
if ( ! V_7 -> V_18 . V_338 || ! V_7 -> V_328 -> V_1368 )
return - V_560 ;
if ( V_30 -> V_5 [ V_1369 ] ) {
V_673 = F_5 ( V_30 -> V_5 [ V_1369 ] ) ;
return F_286 ( V_7 , V_673 , false ) ;
}
V_1367 = F_287 ( & V_7 -> V_1370 ,
struct V_1323 ,
V_666 ) ;
if ( ! V_1367 || V_1367 -> V_1364 ||
( V_1367 -> V_660 &&
V_1367 -> V_660 != V_30 -> V_524 ) )
return - V_681 ;
return F_288 ( V_7 , V_1367 , false ) ;
}
static int F_289 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_539 V_540 ;
enum V_1264 V_1229 ;
unsigned int V_1371 ;
int V_35 ;
V_1229 = F_290 ( V_17 -> V_18 ) ;
if ( V_1229 == V_1265 )
return - V_16 ;
V_35 = F_81 ( V_7 , V_30 , & V_540 ) ;
if ( V_35 )
return V_35 ;
if ( F_291 ( V_559 ) )
return - V_564 ;
if ( V_17 -> V_1372 )
return - V_564 ;
V_35 = F_292 ( V_17 -> V_18 , & V_540 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_293 ( V_17 -> V_18 , & V_540 ) )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1373 )
return - V_560 ;
V_1371 = F_294 ( & V_7 -> V_18 , & V_540 ) ;
if ( F_60 ( ! V_1371 ) )
V_1371 = V_1374 ;
V_35 = F_295 ( V_7 , V_559 , & V_540 , V_1371 ) ;
if ( ! V_35 ) {
V_17 -> V_540 = V_540 ;
V_17 -> V_1372 = true ;
V_17 -> V_1375 = V_1320 ;
V_17 -> V_1371 = V_1371 ;
}
return V_35 ;
}
static int F_296 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_1376 V_139 ;
static struct V_4 * V_1377 [ V_1378 + 1 ] ;
int V_35 ;
bool V_1379 = false ;
bool V_1380 = true ;
int V_45 , V_160 ;
V_22 V_1381 ;
if ( ! V_7 -> V_328 -> V_449 ||
! ( V_7 -> V_18 . V_49 & V_448 ) )
return - V_560 ;
switch ( V_559 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1379 = true ;
V_1380 = false ;
if ( ! V_17 -> V_561 )
return - V_1382 ;
break;
case V_146 :
if ( ! V_17 -> V_612 )
return - V_1382 ;
break;
case V_145 :
if ( ! V_17 -> V_1122 )
return - V_1382 ;
break;
default:
return - V_560 ;
}
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_30 -> V_5 [ V_542 ] ||
! V_30 -> V_5 [ V_1383 ] )
return - V_16 ;
if ( V_1379 && ! V_30 -> V_5 [ V_1384 ] )
return - V_16 ;
V_1381 = F_4 ( V_30 -> V_5 [ V_1383 ] ) ;
if ( V_1381 > 255 )
return - V_16 ;
V_139 . V_1385 = V_1381 ;
if ( ! V_1379 )
goto V_1386;
V_35 = F_161 ( V_30 -> V_5 , & V_139 . V_1387 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_31 ( V_1377 , V_1378 ,
V_30 -> V_5 [ V_1384 ] ,
V_41 , V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_161 ( V_1377 , & V_139 . V_1388 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1377 [ V_1389 ] )
return - V_16 ;
V_45 = F_22 ( V_1377 [ V_1389 ] ) ;
if ( ! V_45 || ( V_45 % sizeof( T_3 ) ) )
return - V_16 ;
V_139 . V_1390 = V_45 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_496 &&
( V_139 . V_1390 >
V_7 -> V_18 . V_496 ) )
return - V_16 ;
V_139 . V_1391 =
F_21 ( V_1377 [ V_1389 ] ) ;
for ( V_160 = 0 ; V_160 < V_139 . V_1390 ; V_160 ++ ) {
T_3 V_1392 = V_139 . V_1391 [ V_160 ] ;
if ( V_1392 >= V_139 . V_1388 . V_759 )
return - V_16 ;
if ( V_139 . V_1388 . V_758 [ V_1392 ] != V_139 . V_1385 )
return - V_16 ;
}
if ( V_1377 [ V_1393 ] ) {
V_45 = F_22 ( V_1377 [ V_1393 ] ) ;
if ( ! V_45 || ( V_45 % sizeof( T_3 ) ) )
return - V_16 ;
V_139 . V_1394 = V_45 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_496 &&
( V_139 . V_1394 >
V_7 -> V_18 . V_496 ) )
return - V_16 ;
V_139 . V_1395 =
F_21 ( V_1377 [ V_1393 ] ) ;
for ( V_160 = 0 ; V_160 < V_139 . V_1394 ; V_160 ++ ) {
T_3 V_1392 = V_139 . V_1395 [ V_160 ] ;
if ( V_1392 >= V_139 . V_1388 . V_768 )
return - V_16 ;
if ( V_139 . V_1388 . V_767 [ V_1392 ] !=
V_139 . V_1385 )
return - V_16 ;
}
}
V_1386:
V_35 = F_81 ( V_7 , V_30 , & V_139 . V_540 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_139 . V_540 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_292 ( V_17 -> V_18 ,
& V_139 . V_540 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 ) {
V_139 . V_1396 = true ;
if ( V_1380 &&
! F_170 ( V_30 -> V_5 [ V_1397 ] ) ) {
return - V_16 ;
}
}
if ( V_30 -> V_5 [ V_1398 ] )
V_139 . V_1399 = true ;
F_116 ( V_17 ) ;
V_35 = F_297 ( V_7 , V_559 , & V_139 ) ;
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_298 ( struct V_31 * V_51 , struct V_33 * V_34 ,
V_22 V_48 , int V_49 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1400 * V_1401 )
{
struct V_1402 * V_430 = & V_1401 -> V_1403 ;
const struct V_1404 * V_776 ;
void * V_360 ;
struct V_4 * V_1405 ;
F_41 ( V_17 ) ;
V_360 = F_23 ( V_51 , F_72 ( V_34 -> V_32 ) . V_47 , V_48 , V_49 ,
V_1406 ) ;
if ( ! V_360 )
return - 1 ;
F_249 ( V_34 , V_360 , & V_38 ) ;
if ( F_26 ( V_51 , V_370 , V_7 -> V_1407 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_26 ( V_51 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_59;
if ( F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_59;
V_1405 = F_45 ( V_51 , V_1408 ) ;
if ( ! V_1405 )
goto V_59;
if ( ( ! F_299 ( V_430 -> V_566 ) &&
F_49 ( V_51 , V_1409 , V_607 , V_430 -> V_566 ) ) )
goto V_59;
F_245 () ;
if ( F_221 ( V_430 -> V_762 ) &&
F_27 ( V_51 , V_1410 ) )
goto V_1411;
V_776 = F_246 ( V_430 -> V_776 ) ;
if ( V_776 ) {
if ( F_104 ( V_51 , V_1412 , V_776 -> V_1413 ,
V_1414 ) )
goto V_1411;
if ( V_776 -> V_45 && F_49 ( V_51 , V_1415 ,
V_776 -> V_45 , V_776 -> V_140 ) )
goto V_1411;
}
V_776 = F_246 ( V_430 -> V_760 ) ;
if ( V_776 && V_776 -> V_1416 ) {
if ( F_104 ( V_51 , V_1417 , V_776 -> V_1413 ,
V_1414 ) )
goto V_1411;
if ( V_776 -> V_45 && F_49 ( V_51 , V_1418 ,
V_776 -> V_45 , V_776 -> V_140 ) )
goto V_1411;
}
F_247 () ;
if ( V_430 -> V_561 &&
F_53 ( V_51 , V_1419 , V_430 -> V_561 ) )
goto V_59;
if ( F_53 ( V_51 , V_1420 , V_430 -> V_1029 ) ||
F_26 ( V_51 , V_1421 , V_430 -> V_1422 -> V_58 ) ||
F_26 ( V_51 , V_1423 , V_430 -> V_1424 ) ||
F_26 ( V_51 , V_1425 ,
F_300 ( V_1320 - V_1401 -> V_1426 ) ) )
goto V_59;
if ( V_1401 -> V_1427 &&
( F_104 ( V_51 , V_1428 ,
V_1401 -> V_1427 , V_1414 ) ||
F_49 ( V_51 , V_1429 , V_607 ,
V_1401 -> V_1430 ) ) )
goto V_59;
if ( V_1401 -> V_1431 &&
F_104 ( V_51 , V_1432 ,
V_1401 -> V_1431 , V_1414 ) )
goto V_59;
switch ( V_7 -> V_18 . V_900 ) {
case V_901 :
if ( F_26 ( V_51 , V_1433 , V_430 -> signal ) )
goto V_59;
break;
case V_1434 :
if ( F_54 ( V_51 , V_1435 , V_430 -> signal ) )
goto V_59;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1401 == V_17 -> V_149 &&
F_26 ( V_51 , V_1436 ,
V_1437 ) )
goto V_59;
break;
case V_146 :
if ( V_1401 == V_17 -> V_149 &&
F_26 ( V_51 , V_1436 ,
V_1438 ) )
goto V_59;
break;
default:
break;
}
F_46 ( V_51 , V_1405 ) ;
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_1411:
F_247 () ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int F_301 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1400 * V_1297 ;
struct V_1 * V_17 ;
int V_519 = V_34 -> args [ 2 ] , V_103 = 0 ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 ) {
F_70 () ;
return V_35 ;
}
F_116 ( V_17 ) ;
F_302 ( & V_7 -> V_1439 ) ;
F_303 ( V_7 ) ;
V_34 -> V_48 = V_7 -> V_1407 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_103 <= V_519 )
continue;
if ( F_298 ( V_32 , V_34 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_7 , V_17 , V_1297 ) < 0 ) {
V_103 -- ;
break;
}
}
F_304 ( & V_7 -> V_1439 ) ;
F_118 ( V_17 ) ;
V_34 -> args [ 2 ] = V_103 ;
F_70 () ;
return V_32 -> V_45 ;
}
static int F_305 ( struct V_31 * V_51 , V_22 V_47 , V_22 V_48 ,
int V_49 , struct V_25 * V_559 ,
bool V_1440 ,
struct V_1441 * V_1442 )
{
void * V_360 ;
struct V_4 * V_1443 ;
if ( ! V_1442 -> V_1422 && ! V_1440 )
return 0 ;
V_360 = F_23 ( V_51 , V_47 , V_48 , V_49 ,
V_1444 ) ;
if ( ! V_360 )
return - V_136 ;
if ( F_26 ( V_51 , V_10 , V_559 -> V_20 ) )
goto V_59;
V_1443 = F_45 ( V_51 , V_1445 ) ;
if ( ! V_1443 )
goto V_59;
if ( V_1442 -> V_1422 &&
F_26 ( V_51 , V_1446 ,
V_1442 -> V_1422 -> V_58 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1447 ) &&
F_54 ( V_51 , V_1448 , V_1442 -> V_1449 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1450 ) &&
F_27 ( V_51 , V_1451 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1452 ) &&
F_104 ( V_51 , V_1453 ,
V_1442 -> time , V_1454 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1455 ) &&
F_104 ( V_51 , V_1456 ,
V_1442 -> V_1457 , V_1454 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1458 ) &&
F_104 ( V_51 , V_1459 ,
V_1442 -> V_1460 , V_1454 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1461 ) &&
F_104 ( V_51 , V_1462 ,
V_1442 -> V_1463 , V_1454 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1464 ) &&
F_104 ( V_51 , V_1465 ,
V_1442 -> V_1466 , V_1454 ) )
goto V_59;
if ( ( V_1442 -> V_883 & V_1467 ) &&
F_104 ( V_51 , V_1468 ,
V_1442 -> V_1469 , V_1454 ) )
goto V_59;
F_46 ( V_51 , V_1443 ) ;
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int F_306 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_4 * * V_1470 = F_15 ( & V_38 ) ;
struct V_1441 V_1442 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1471 = V_34 -> args [ 2 ] ;
int V_430 ;
bool V_1472 ;
F_69 () ;
V_430 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_430 )
goto V_967;
V_1472 = V_1470 [ V_1473 ] ;
if ( ! V_17 -> V_19 ) {
V_430 = - V_16 ;
goto V_967;
}
if ( ! V_7 -> V_328 -> V_1474 ) {
V_430 = - V_560 ;
goto V_967;
}
while ( 1 ) {
V_430 = F_307 ( V_7 , V_17 -> V_19 , V_1471 , & V_1442 ) ;
if ( V_430 == - V_681 )
break;
if ( V_430 )
goto V_967;
if ( V_1442 . V_1422 &&
V_1442 . V_1422 -> V_49 & V_60 ) {
V_1471 ++ ;
continue;
}
if ( F_305 ( V_32 ,
F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_17 -> V_19 , V_1472 , & V_1442 ) < 0 )
goto V_620;
V_1471 ++ ;
}
V_620:
V_34 -> args [ 2 ] = V_1471 ;
V_430 = V_32 -> V_45 ;
V_967:
F_70 () ;
return V_430 ;
}
static bool F_308 ( V_22 V_1475 )
{
return ! ( V_1475 & ~ ( V_1476 |
V_1477 ) ) ;
}
static int F_309 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_52 * V_53 ;
const T_2 * V_566 , * V_614 , * V_1214 = NULL , * V_1478 = NULL ;
int V_35 , V_612 , V_1215 = 0 , V_1479 = 0 ;
enum V_781 V_782 ;
struct V_91 V_90 ;
bool V_1480 ;
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_804 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_613 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_542 ] )
return - V_16 ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( V_90 . V_103 >= 0 ) {
if ( V_90 . type != - 1 && V_90 . type != V_678 )
return - V_16 ;
if ( ! V_90 . V_105 . V_90 || ! V_90 . V_105 . V_106 )
return - V_16 ;
if ( ( V_90 . V_105 . V_110 != V_137 ||
V_90 . V_105 . V_106 != V_1481 ) &&
( V_90 . V_105 . V_110 != V_138 ||
V_90 . V_105 . V_106 != V_1482 ) )
return - V_16 ;
if ( V_90 . V_103 > 3 )
return - V_16 ;
} else {
V_90 . V_105 . V_106 = 0 ;
V_90 . V_105 . V_90 = NULL ;
}
if ( V_90 . V_103 >= 0 ) {
int V_160 ;
bool V_1483 = false ;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_414 ; V_160 ++ ) {
if ( V_90 . V_105 . V_110 == V_7 -> V_18 . V_415 [ V_160 ] ) {
V_1483 = true ;
break;
}
}
if ( ! V_1483 )
return - V_16 ;
}
if ( ! V_7 -> V_328 -> V_299 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_53 = F_42 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_542 ] ) ;
if ( ! V_53 )
return - V_16 ;
V_614 = F_21 ( V_30 -> V_5 [ V_613 ] ) ;
V_612 = F_22 ( V_30 -> V_5 [ V_613 ] ) ;
if ( V_30 -> V_5 [ V_752 ] ) {
V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
}
V_782 = F_4 ( V_30 -> V_5 [ V_804 ] ) ;
if ( ! F_166 ( V_7 , V_782 , V_784 ) )
return - V_16 ;
if ( ( V_782 == V_786 ||
V_782 == V_788 ||
V_782 == V_789 ||
V_782 == V_790 ) &&
! V_30 -> V_5 [ V_1484 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1484 ] ) {
if ( V_782 != V_786 &&
V_782 != V_788 &&
V_782 != V_789 &&
V_782 != V_790 )
return - V_16 ;
V_1478 = F_21 ( V_30 -> V_5 [ V_1484 ] ) ;
V_1479 = F_22 ( V_30 -> V_5 [ V_1484 ] ) ;
if ( V_1479 < 4 )
return - V_16 ;
}
V_1480 = ! ! V_30 -> V_5 [ V_1485 ] ;
if ( V_1480 )
return 0 ;
F_116 ( V_559 -> V_28 ) ;
V_35 = F_310 ( V_7 , V_559 , V_53 , V_782 , V_566 ,
V_614 , V_612 , V_1214 , V_1215 ,
V_90 . V_105 . V_90 , V_90 . V_105 . V_106 , V_90 . V_103 ,
V_1478 , V_1479 ) ;
F_118 ( V_559 -> V_28 ) ;
return V_35 ;
}
static int F_169 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1486 * V_1487 ,
int V_1488 )
{
memset ( V_1487 , 0 , sizeof( * V_1487 ) ) ;
V_1487 -> V_1489 = V_30 -> V_5 [ V_1490 ] ;
if ( V_30 -> V_5 [ V_419 ] ) {
T_3 V_1491 ;
V_1491 = F_79 (
V_30 -> V_5 [ V_419 ] ) ;
V_1487 -> V_1492 = F_311 ( V_1491 ) ;
if ( ! ( V_7 -> V_18 . V_49 & V_418 ) &&
V_1491 != V_1493 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1494 ] )
V_1487 -> V_1495 = true ;
} else
V_1487 -> V_1492 = F_311 ( V_1493 ) ;
if ( V_30 -> V_5 [ V_1496 ] ) {
void * V_140 ;
int V_45 , V_160 ;
V_140 = F_21 ( V_30 -> V_5 [ V_1496 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_1496 ] ) ;
V_1487 -> V_1497 = V_45 / sizeof( V_22 ) ;
if ( V_45 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1487 -> V_1497 > V_1488 )
return - V_16 ;
memcpy ( V_1487 -> V_1498 , V_140 , V_45 ) ;
for ( V_160 = 0 ; V_160 < V_1487 -> V_1497 ; V_160 ++ )
if ( ! F_312 (
& V_7 -> V_18 ,
V_1487 -> V_1498 [ V_160 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1499 ] ) {
V_1487 -> V_1500 =
F_4 ( V_30 -> V_5 [ V_1499 ] ) ;
if ( ! F_312 ( & V_7 -> V_18 ,
V_1487 -> V_1500 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1501 ] ) {
V_1487 -> V_1475 =
F_4 ( V_30 -> V_5 [ V_1501 ] ) ;
if ( ! F_308 ( V_1487 -> V_1475 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1502 ] ) {
void * V_140 ;
int V_45 ;
V_140 = F_21 ( V_30 -> V_5 [ V_1502 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_1502 ] ) ;
V_1487 -> V_1503 = V_45 / sizeof( V_22 ) ;
if ( V_45 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1487 -> V_1503 > V_1504 )
return - V_16 ;
memcpy ( V_1487 -> V_1505 , V_140 , V_45 ) ;
}
if ( V_30 -> V_5 [ V_1506 ] ) {
if ( F_22 ( V_30 -> V_5 [ V_1506 ] ) != V_1507 )
return - V_16 ;
if ( ! F_112 ( & V_7 -> V_18 ,
V_1508 ) )
return - V_16 ;
V_1487 -> V_1509 = F_21 ( V_30 -> V_5 [ V_1506 ] ) ;
}
return 0 ;
}
static int F_313 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_52 * V_53 ;
struct V_1510 V_1367 = {} ;
const T_2 * V_566 , * V_614 ;
int V_35 , V_612 = 0 ;
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_567 ] ||
! V_30 -> V_5 [ V_613 ] ||
! V_30 -> V_5 [ V_542 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_301 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_53 = F_42 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_542 ] ) ;
if ( ! V_53 )
return - V_16 ;
V_614 = F_21 ( V_30 -> V_5 [ V_613 ] ) ;
V_612 = F_22 ( V_30 -> V_5 [ V_613 ] ) ;
if ( V_30 -> V_5 [ V_752 ] ) {
V_1367 . V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_1367 . V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
}
if ( V_30 -> V_5 [ V_1511 ] ) {
enum V_1512 V_1513 =
F_4 ( V_30 -> V_5 [ V_1511 ] ) ;
if ( V_1513 == V_1514 )
V_1367 . V_1515 = true ;
else if ( V_1513 != V_1516 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1517 ] )
V_1367 . V_1518 = F_21 ( V_30 -> V_5 [ V_1517 ] ) ;
if ( F_170 ( V_30 -> V_5 [ V_1519 ] ) )
V_1367 . V_49 |= V_1520 ;
if ( V_30 -> V_5 [ V_472 ] )
memcpy ( & V_1367 . V_1521 ,
F_21 ( V_30 -> V_5 [ V_472 ] ) ,
sizeof( V_1367 . V_1521 ) ) ;
if ( V_30 -> V_5 [ V_1019 ] ) {
if ( ! V_30 -> V_5 [ V_472 ] )
return - V_16 ;
memcpy ( & V_1367 . V_989 ,
F_21 ( V_30 -> V_5 [ V_1019 ] ) ,
sizeof( V_1367 . V_989 ) ) ;
}
if ( F_170 ( V_30 -> V_5 [ V_1522 ] ) )
V_1367 . V_49 |= V_1523 ;
if ( V_30 -> V_5 [ V_481 ] )
memcpy ( & V_1367 . V_1524 ,
F_21 ( V_30 -> V_5 [ V_481 ] ) ,
sizeof( V_1367 . V_1524 ) ) ;
if ( V_30 -> V_5 [ V_1020 ] ) {
if ( ! V_30 -> V_5 [ V_481 ] )
return - V_16 ;
memcpy ( & V_1367 . V_990 ,
F_21 ( V_30 -> V_5 [ V_1020 ] ) ,
sizeof( V_1367 . V_990 ) ) ;
}
if ( F_170 ( V_30 -> V_5 [ V_1525 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_368 &
V_1526 ) &&
( V_7 -> V_18 . V_368 & V_1527 ) ) &&
! F_112 ( & V_7 -> V_18 ,
V_1528 ) )
return - V_16 ;
V_1367 . V_49 |= V_1529 ;
}
if ( V_30 -> V_5 [ V_1530 ] ) {
V_1367 . V_1531 = F_21 ( V_30 -> V_5 [ V_1530 ] ) ;
V_1367 . V_1532 = F_22 ( V_30 -> V_5 [ V_1530 ] ) ;
if ( ! V_30 -> V_5 [ V_1533 ] )
return - V_16 ;
V_1367 . V_1534 =
F_21 ( V_30 -> V_5 [ V_1533 ] ) ;
}
V_35 = F_169 ( V_7 , V_30 , & V_1367 . V_806 , 1 ) ;
if ( ! V_35 ) {
F_116 ( V_559 -> V_28 ) ;
V_35 = F_314 ( V_7 , V_559 , V_53 , V_566 ,
V_614 , V_612 , & V_1367 ) ;
if ( ! V_35 && V_30 -> V_5 [ V_659 ] ) {
V_559 -> V_28 -> V_1535 =
V_30 -> V_524 ;
memcpy ( V_559 -> V_28 -> V_1536 ,
V_566 , V_607 ) ;
}
F_118 ( V_559 -> V_28 ) ;
}
return V_35 ;
}
static int F_315 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
const T_2 * V_1214 = NULL , * V_566 ;
int V_1215 = 0 , V_35 ;
T_3 V_1056 ;
bool V_1480 ;
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1055 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_303 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_1056 = F_79 ( V_30 -> V_5 [ V_1055 ] ) ;
if ( V_1056 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_752 ] ) {
V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
}
V_1480 = ! ! V_30 -> V_5 [ V_1485 ] ;
F_116 ( V_559 -> V_28 ) ;
V_35 = F_316 ( V_7 , V_559 , V_566 , V_1214 , V_1215 , V_1056 ,
V_1480 ) ;
F_118 ( V_559 -> V_28 ) ;
return V_35 ;
}
static int F_317 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
const T_2 * V_1214 = NULL , * V_566 ;
int V_1215 = 0 , V_35 ;
T_3 V_1056 ;
bool V_1480 ;
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1055 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_305 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_1056 = F_79 ( V_30 -> V_5 [ V_1055 ] ) ;
if ( V_1056 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_752 ] ) {
V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
}
V_1480 = ! ! V_30 -> V_5 [ V_1485 ] ;
F_116 ( V_559 -> V_28 ) ;
V_35 = F_318 ( V_7 , V_559 , V_566 , V_1214 , V_1215 , V_1056 ,
V_1480 ) ;
F_118 ( V_559 -> V_28 ) ;
return V_35 ;
}
static bool
F_319 ( struct V_6 * V_7 ,
int V_1537 [ V_437 ] ,
int V_1538 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_367 , V_160 ;
for ( V_367 = 0 ; V_367 < V_437 ; V_367 ++ ) {
struct V_242 * V_243 ;
V_243 = V_18 -> V_438 [ V_367 ] ;
if ( ! V_243 )
continue;
for ( V_160 = 0 ; V_160 < V_243 -> V_264 ; V_160 ++ ) {
if ( V_243 -> V_265 [ V_160 ] . V_267 == V_1538 ) {
V_1537 [ V_367 ] = V_160 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_320 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1539 V_1540 ;
struct V_18 * V_18 ;
struct V_129 * V_1541 = NULL ;
int V_35 ;
memset ( & V_1540 , 0 , sizeof( V_1540 ) ) ;
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_613 ] ||
! F_22 ( V_30 -> V_5 [ V_613 ] ) )
return - V_16 ;
V_1540 . V_561 = 100 ;
if ( V_30 -> V_5 [ V_794 ] )
V_1540 . V_561 =
F_4 ( V_30 -> V_5 [ V_794 ] ) ;
V_35 = F_168 ( V_7 , V_146 ,
V_1540 . V_561 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_328 -> V_307 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_146 )
return - V_560 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_567 ] ) {
V_1540 . V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( ! F_123 ( V_1540 . V_566 ) )
return - V_16 ;
}
V_1540 . V_614 = F_21 ( V_30 -> V_5 [ V_613 ] ) ;
V_1540 . V_612 = F_22 ( V_30 -> V_5 [ V_613 ] ) ;
if ( V_30 -> V_5 [ V_752 ] ) {
V_1540 . V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_1540 . V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
}
V_35 = F_81 ( V_7 , V_30 , & V_1540 . V_540 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_321 ( & V_7 -> V_18 , & V_1540 . V_540 ,
V_146 ) )
return - V_16 ;
switch ( V_1540 . V_540 . V_543 ) {
case V_557 :
case V_558 :
case V_544 :
break;
case V_599 :
case V_600 :
if ( ! ( V_7 -> V_18 . V_368 & V_1542 ) )
return - V_16 ;
break;
case V_1543 :
case V_1544 :
case V_1545 :
if ( ! ( V_7 -> V_18 . V_368 & V_1542 ) )
return - V_16 ;
if ( ! F_112 ( & V_7 -> V_18 ,
V_1546 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1540 . V_1547 = ! ! V_30 -> V_5 [ V_1548 ] ;
V_1540 . V_802 = ! ! V_30 -> V_5 [ V_803 ] ;
if ( V_30 -> V_5 [ V_1103 ] ) {
T_2 * V_705 =
F_21 ( V_30 -> V_5 [ V_1103 ] ) ;
int V_1549 =
F_22 ( V_30 -> V_5 [ V_1103 ] ) ;
struct V_242 * V_243 =
V_18 -> V_438 [ V_1540 . V_540 . V_53 -> V_367 ] ;
V_35 = F_269 ( V_243 , V_705 , V_1549 ,
& V_1540 . V_1104 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_472 ] )
memcpy ( & V_1540 . V_1521 ,
F_21 ( V_30 -> V_5 [ V_472 ] ) ,
sizeof( V_1540 . V_1521 ) ) ;
if ( V_30 -> V_5 [ V_1019 ] ) {
if ( ! V_30 -> V_5 [ V_472 ] )
return - V_16 ;
memcpy ( & V_1540 . V_989 ,
F_21 ( V_30 -> V_5 [ V_1019 ] ) ,
sizeof( V_1540 . V_989 ) ) ;
}
if ( V_30 -> V_5 [ V_1550 ] &&
! F_319 ( V_7 , V_1540 . V_1537 ,
F_4 ( V_30 -> V_5 [ V_1550 ] ) ) )
return - V_16 ;
if ( V_1540 . V_802 && V_30 -> V_5 [ V_1551 ] ) {
bool V_131 = false ;
V_1541 = F_35 ( V_7 ,
V_30 -> V_5 [ V_1551 ] ,
& V_131 ) ;
if ( F_17 ( V_1541 ) )
return F_18 ( V_1541 ) ;
if ( ( V_1540 . V_540 . V_543 != V_544 ) &&
V_131 ) {
F_322 ( V_1541 ) ;
return - V_16 ;
}
}
V_1540 . V_1489 =
F_170 ( V_30 -> V_5 [ V_1490 ] ) ;
V_1540 . V_1552 =
F_170 ( V_30 -> V_5 [ V_1397 ] ) ;
V_35 = F_323 ( V_7 , V_559 , & V_1540 , V_1541 ) ;
if ( V_35 )
F_322 ( V_1541 ) ;
return V_35 ;
}
static int F_324 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_1553 )
return - V_560 ;
if ( V_559 -> V_28 -> V_141 != V_146 )
return - V_560 ;
return F_325 ( V_7 , V_559 , false ) ;
}
static int F_326 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
int V_1537 [ V_437 ] ;
V_22 V_1554 ;
int V_35 ;
if ( V_559 -> V_28 -> V_141 != V_146 &&
V_559 -> V_28 -> V_141 != V_145 &&
V_559 -> V_28 -> V_141 != V_152 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_349 )
return - V_560 ;
memset ( V_1537 , 0 , sizeof( V_1537 ) ) ;
if ( ! V_30 -> V_5 [ V_1550 ] )
return - V_16 ;
V_1554 = F_4 ( V_30 -> V_5 [ V_1550 ] ) ;
if ( ! F_319 ( V_7 , V_1537 , V_1554 ) )
return - V_16 ;
V_35 = F_327 ( V_7 , V_559 , V_1537 ) ;
return V_35 ;
}
static struct V_31 *
F_328 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1555 ,
V_22 V_47 , V_22 V_48 , enum V_357 V_50 ,
enum V_1556 V_43 ,
const struct V_488 * V_30 ,
T_10 V_1557 )
{
struct V_31 * V_32 ;
void * V_360 ;
struct V_4 * V_140 ;
V_32 = F_75 ( V_1555 + 100 , V_1557 ) ;
if ( ! V_32 )
return NULL ;
V_360 = F_23 ( V_32 , V_47 , V_48 , 0 , V_50 ) ;
if ( ! V_360 ) {
F_329 ( V_32 ) ;
return NULL ;
}
if ( F_26 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_30 ) {
if ( F_26 ( V_32 , V_1558 ,
V_30 -> V_1559 ) )
goto V_59;
if ( F_26 ( V_32 , V_1560 ,
V_30 -> V_1561 ) )
goto V_59;
}
if ( V_17 ) {
if ( F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) , V_606 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_26 ( V_32 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_59;
}
V_140 = F_45 ( V_32 , V_43 ) ;
if ( ! V_140 )
goto V_59;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_360 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_140 ;
return V_32 ;
V_59:
F_329 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_330 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_357 V_50 ,
enum V_1556 V_43 ,
int V_1562 ,
int V_1555 , T_10 V_1557 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_488 * V_30 ;
switch ( V_50 ) {
case V_1563 :
if ( F_60 ( V_1562 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1564 :
if ( F_60 ( V_1562 < 0 ||
V_1562 >= V_18 -> V_492 ) )
return NULL ;
V_30 = & V_18 -> V_494 [ V_1562 ] ;
break;
default:
F_60 ( 1 ) ;
return NULL ;
}
return F_328 ( V_7 , V_17 , V_1555 , 0 , 0 ,
V_50 , V_43 , V_30 , V_1557 ) ;
}
void F_331 ( struct V_31 * V_32 , T_10 V_1557 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_360 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_140 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1565 V_1566 = V_1567 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_46 ( V_32 , V_140 ) ;
F_65 ( V_32 , V_360 ) ;
if ( V_140 -> F_156 == V_490 )
V_1566 = V_1568 ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1566 , V_1557 ) ;
}
static int F_333 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_95 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_351 )
return - V_560 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1569 ] )
return - V_16 ;
V_7 -> V_1570 = V_30 ;
V_35 = F_334 ( V_7 , V_17 ,
F_21 ( V_30 -> V_5 [ V_1569 ] ) ,
F_22 ( V_30 -> V_5 [ V_1569 ] ) ) ;
V_7 -> V_1570 = NULL ;
return V_35 ;
}
static int F_335 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1571 ;
void * V_140 = NULL ;
int V_1572 = 0 ;
F_69 () ;
if ( V_34 -> args [ 0 ] ) {
V_1571 = V_34 -> args [ 0 ] - 1 ;
V_7 = F_9 ( V_1571 ) ;
if ( ! V_7 ) {
V_35 = - V_681 ;
goto V_967;
}
} else {
struct V_4 * * V_1470 = F_15 ( & V_38 ) ;
V_35 = F_14 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_1470 , V_38 . V_40 ,
V_41 , NULL ) ;
if ( V_35 )
goto V_967;
V_7 = F_8 ( F_16 ( V_32 -> V_42 ) , V_1470 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_967;
}
V_1571 = V_7 -> V_14 ;
if ( V_1470 [ V_1569 ] )
V_34 -> args [ 1 ] = ( long ) V_1470 [ V_1569 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_140 = F_21 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1572 = F_22 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
if ( ! V_7 -> V_328 -> V_1573 ) {
V_35 = - V_560 ;
goto V_967;
}
while ( 1 ) {
void * V_360 = F_23 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_1563 ) ;
struct V_4 * V_1574 ;
if ( ! V_360 )
break;
if ( F_26 ( V_32 , V_26 , V_1571 ) ) {
F_66 ( V_32 , V_360 ) ;
break;
}
V_1574 = F_45 ( V_32 , V_1569 ) ;
if ( ! V_1574 ) {
F_66 ( V_32 , V_360 ) ;
break;
}
V_35 = F_336 ( V_7 , V_32 , V_34 , V_140 , V_1572 ) ;
F_46 ( V_32 , V_1574 ) ;
if ( V_35 == - V_89 || V_35 == - V_681 ) {
F_66 ( V_32 , V_360 ) ;
break;
} else if ( V_35 ) {
F_66 ( V_32 , V_360 ) ;
goto V_967;
}
F_65 ( V_32 , V_360 ) ;
}
V_35 = V_32 -> V_45 ;
V_34 -> args [ 0 ] = V_1571 + 1 ;
V_967:
F_70 () ;
return V_35 ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1575 V_353 ;
struct V_18 * V_18 ;
struct V_129 * V_1541 = NULL ;
int V_35 ;
memset ( & V_353 , 0 , sizeof( V_353 ) ) ;
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_613 ] ||
! F_22 ( V_30 -> V_5 [ V_613 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_804 ] ) {
V_353 . V_782 =
F_4 ( V_30 -> V_5 [ V_804 ] ) ;
if ( ! F_166 ( V_7 , V_353 . V_782 ,
V_354 ) )
return - V_16 ;
} else
V_353 . V_782 = V_805 ;
V_353 . V_802 = V_30 -> V_5 [ V_803 ] ;
if ( V_30 -> V_5 [ V_1576 ] &&
! F_112 ( & V_7 -> V_18 ,
V_1577 ) )
return - V_16 ;
V_353 . V_1578 = V_30 -> V_5 [ V_1576 ] ;
V_35 = F_169 ( V_7 , V_30 , & V_353 . V_806 ,
V_807 ) ;
if ( V_35 )
return V_35 ;
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
V_18 = & V_7 -> V_18 ;
V_353 . V_1579 = - 1 ;
if ( V_30 -> V_5 [ V_1580 ] &&
( V_18 -> V_49 & V_407 ) ) {
V_353 . V_1579 =
F_79 ( V_30 -> V_5 [ V_1580 ] ) ;
}
if ( V_30 -> V_5 [ V_567 ] )
V_353 . V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
else if ( V_30 -> V_5 [ V_1581 ] )
V_353 . V_1582 =
F_21 ( V_30 -> V_5 [ V_1581 ] ) ;
V_353 . V_614 = F_21 ( V_30 -> V_5 [ V_613 ] ) ;
V_353 . V_612 = F_22 ( V_30 -> V_5 [ V_613 ] ) ;
if ( V_30 -> V_5 [ V_752 ] ) {
V_353 . V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_353 . V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
}
if ( V_30 -> V_5 [ V_1511 ] ) {
V_353 . V_1513 = F_4 ( V_30 -> V_5 [ V_1511 ] ) ;
if ( V_353 . V_1513 != V_1514 &&
V_353 . V_1513 != V_1516 )
return - V_16 ;
} else {
V_353 . V_1513 = V_1516 ;
}
if ( V_30 -> V_5 [ V_1517 ] )
V_353 . V_1518 =
F_21 ( V_30 -> V_5 [ V_1517 ] ) ;
if ( V_30 -> V_5 [ V_542 ] ) {
V_353 . V_1422 = F_42 (
V_18 , V_30 -> V_5 [ V_542 ] ) ;
if ( ! V_353 . V_1422 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1583 ] ) {
V_353 . V_1584 = F_42 (
V_18 , V_30 -> V_5 [ V_1583 ] ) ;
if ( ! V_353 . V_1584 )
return - V_16 ;
}
if ( V_353 . V_802 && V_30 -> V_5 [ V_1551 ] ) {
V_1541 = F_35 ( V_7 ,
V_30 -> V_5 [ V_1551 ] , NULL ) ;
if ( F_17 ( V_1541 ) )
return F_18 ( V_1541 ) ;
}
if ( F_170 ( V_30 -> V_5 [ V_1519 ] ) )
V_353 . V_49 |= V_1520 ;
if ( V_30 -> V_5 [ V_472 ] )
memcpy ( & V_353 . V_1521 ,
F_21 ( V_30 -> V_5 [ V_472 ] ) ,
sizeof( V_353 . V_1521 ) ) ;
if ( V_30 -> V_5 [ V_1019 ] ) {
if ( ! V_30 -> V_5 [ V_472 ] ) {
F_322 ( V_1541 ) ;
return - V_16 ;
}
memcpy ( & V_353 . V_989 ,
F_21 ( V_30 -> V_5 [ V_1019 ] ) ,
sizeof( V_353 . V_989 ) ) ;
}
if ( F_170 ( V_30 -> V_5 [ V_1522 ] ) )
V_353 . V_49 |= V_1523 ;
if ( V_30 -> V_5 [ V_481 ] )
memcpy ( & V_353 . V_1524 ,
F_21 ( V_30 -> V_5 [ V_481 ] ) ,
sizeof( V_353 . V_1524 ) ) ;
if ( V_30 -> V_5 [ V_1020 ] ) {
if ( ! V_30 -> V_5 [ V_481 ] ) {
F_322 ( V_1541 ) ;
return - V_16 ;
}
memcpy ( & V_353 . V_990 ,
F_21 ( V_30 -> V_5 [ V_1020 ] ) ,
sizeof( V_353 . V_990 ) ) ;
}
if ( F_170 ( V_30 -> V_5 [ V_1525 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_368 &
V_1526 ) &&
( V_7 -> V_18 . V_368 & V_1527 ) ) &&
! F_112 ( & V_7 -> V_18 ,
V_1528 ) ) {
F_322 ( V_1541 ) ;
return - V_16 ;
}
V_353 . V_49 |= V_1529 ;
}
V_353 . V_824 = F_170 ( V_30 -> V_5 [ V_825 ] ) ;
if ( V_353 . V_824 && ! V_7 -> V_18 . V_438 [ V_826 ] ) {
F_322 ( V_1541 ) ;
return - V_560 ;
}
if ( V_30 -> V_5 [ V_504 ] ) {
if ( V_353 . V_566 ) {
F_322 ( V_1541 ) ;
return - V_16 ;
}
V_35 = F_259 ( V_30 -> V_5 [ V_504 ] ,
V_18 , & V_353 . V_1278 ) ;
if ( V_35 ) {
F_322 ( V_1541 ) ;
return V_35 ;
}
}
if ( F_112 ( & V_7 -> V_18 ,
V_791 ) &&
V_30 -> V_5 [ V_1585 ] &&
V_30 -> V_5 [ V_1586 ] &&
V_30 -> V_5 [ V_1587 ] &&
V_30 -> V_5 [ V_1588 ] ) {
V_353 . V_1589 =
F_21 ( V_30 -> V_5 [ V_1585 ] ) ;
V_353 . V_1590 =
F_22 ( V_30 -> V_5 [ V_1585 ] ) ;
V_353 . V_1591 =
F_21 ( V_30 -> V_5 [ V_1586 ] ) ;
V_353 . V_1592 =
F_22 ( V_30 -> V_5 [ V_1586 ] ) ;
V_353 . V_1593 =
F_79 (
V_30 -> V_5 [ V_1587 ] ) ;
V_353 . V_1594 =
F_21 ( V_30 -> V_5 [ V_1588 ] ) ;
V_353 . V_1595 =
F_22 ( V_30 -> V_5 [ V_1588 ] ) ;
} else if ( V_30 -> V_5 [ V_1585 ] ||
V_30 -> V_5 [ V_1586 ] ||
V_30 -> V_5 [ V_1587 ] ||
V_30 -> V_5 [ V_1588 ] ) {
F_322 ( V_1541 ) ;
return - V_16 ;
}
F_116 ( V_559 -> V_28 ) ;
V_35 = F_338 ( V_7 , V_559 , & V_353 , V_1541 ,
V_353 . V_1518 ) ;
if ( V_35 )
F_322 ( V_1541 ) ;
if ( ! V_35 && V_30 -> V_5 [ V_659 ] ) {
V_559 -> V_28 -> V_1535 = V_30 -> V_524 ;
if ( V_353 . V_566 )
memcpy ( V_559 -> V_28 -> V_1536 ,
V_353 . V_566 , V_607 ) ;
else
memset ( V_559 -> V_28 -> V_1536 ,
0 , V_607 ) ;
}
F_118 ( V_559 -> V_28 ) ;
return V_35 ;
}
static int F_339 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1575 V_353 = {} ;
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
V_22 V_570 = 0 ;
int V_516 ;
if ( ! V_7 -> V_328 -> V_458 )
return - V_560 ;
if ( V_30 -> V_5 [ V_752 ] ) {
if ( ! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
V_353 . V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_353 . V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
V_570 |= V_1596 ;
}
F_116 ( V_559 -> V_28 ) ;
if ( ! V_17 -> V_149 )
V_516 = - V_150 ;
else
V_516 = F_340 ( V_7 , V_559 , & V_353 , V_570 ) ;
F_118 ( V_559 -> V_28 ) ;
return V_516 ;
}
static int F_341 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_3 V_1597 ;
int V_516 ;
if ( ! V_30 -> V_5 [ V_1055 ] )
V_1597 = V_1598 ;
else
V_1597 = F_79 ( V_30 -> V_5 [ V_1055 ] ) ;
if ( V_1597 == 0 )
return - V_16 ;
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
F_116 ( V_559 -> V_28 ) ;
V_516 = F_342 ( V_7 , V_559 , V_1597 , true ) ;
F_118 ( V_559 -> V_28 ) ;
return V_516 ;
}
static int F_343 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1599 ] ) {
V_22 V_1600 = F_4 ( V_30 -> V_5 [ V_1599 ] ) ;
V_2 = F_344 ( V_1600 ) ;
} else if ( V_30 -> V_5 [ V_1601 ] ) {
V_22 V_1602 = F_4 ( V_30 -> V_5 [ V_1601 ] ) ;
V_2 = F_345 ( V_1602 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_346 ( V_7 , V_2 ) ;
F_347 ( V_2 ) ;
return V_35 ;
}
static int F_348 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
int (* F_349)( struct V_18 * V_18 , struct V_25 * V_559 ,
struct V_1603 * V_1604 ) = NULL ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1603 V_1604 ;
memset ( & V_1604 , 0 , sizeof( struct V_1603 ) ) ;
if ( ! V_30 -> V_5 [ V_1605 ] )
return - V_16 ;
V_1604 . V_1606 = F_21 ( V_30 -> V_5 [ V_1605 ] ) ;
if ( V_30 -> V_5 [ V_567 ] ) {
V_1604 . V_566 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
} else if ( V_30 -> V_5 [ V_613 ] &&
V_30 -> V_5 [ V_1607 ] &&
( V_30 -> V_1608 -> V_50 == V_1609 ||
V_30 -> V_5 [ V_1506 ] ) ) {
V_1604 . V_614 = F_21 ( V_30 -> V_5 [ V_613 ] ) ;
V_1604 . V_612 = F_22 ( V_30 -> V_5 [ V_613 ] ) ;
V_1604 . V_1610 =
F_21 ( V_30 -> V_5 [ V_1607 ] ) ;
} else {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1506 ] ) {
V_1604 . V_1611 = F_21 ( V_30 -> V_5 [ V_1506 ] ) ;
V_1604 . V_1612 = F_22 ( V_30 -> V_5 [ V_1506 ] ) ;
}
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
switch ( V_30 -> V_1608 -> V_50 ) {
case V_1613 :
F_349 = V_7 -> V_328 -> V_311 ;
break;
case V_1609 :
F_349 = V_7 -> V_328 -> V_313 ;
break;
default:
F_60 ( 1 ) ;
break;
}
if ( ! F_349 )
return - V_560 ;
return F_349 ( & V_7 -> V_18 , V_559 , & V_1604 ) ;
}
static int F_350 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
if ( V_559 -> V_28 -> V_141 != V_147 &&
V_559 -> V_28 -> V_141 != V_148 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_315 )
return - V_560 ;
return F_351 ( V_7 , V_559 ) ;
}
static int F_352 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 V_1614 , V_1615 ;
V_22 V_1616 = 0 ;
T_3 V_1617 ;
T_2 * V_1618 ;
bool V_1619 ;
if ( ! ( V_7 -> V_18 . V_49 & V_333 ) ||
! V_7 -> V_328 -> V_334 )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_1620 ] ||
! V_30 -> V_5 [ V_1621 ] ||
! V_30 -> V_5 [ V_1622 ] ||
! V_30 -> V_5 [ V_752 ] ||
! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_1618 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_1614 = F_32 ( V_30 -> V_5 [ V_1620 ] ) ;
V_1617 = F_79 ( V_30 -> V_5 [ V_1621 ] ) ;
V_1615 = F_32 ( V_30 -> V_5 [ V_1622 ] ) ;
V_1619 = F_170 ( V_30 -> V_5 [ V_1623 ] ) ;
if ( V_30 -> V_5 [ V_1624 ] )
V_1616 =
F_4 ( V_30 -> V_5 [ V_1624 ] ) ;
return F_353 ( V_7 , V_559 , V_1618 , V_1614 ,
V_1615 , V_1617 , V_1616 ,
V_1619 ,
F_21 ( V_30 -> V_5 [ V_752 ] ) ,
F_22 ( V_30 -> V_5 [ V_752 ] ) ) ;
}
static int F_354 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
enum V_1625 V_1626 ;
T_2 * V_1618 ;
if ( ! ( V_7 -> V_18 . V_49 & V_333 ) ||
! V_7 -> V_328 -> V_336 )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_1627 ] ||
! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_1626 = F_32 ( V_30 -> V_5 [ V_1627 ] ) ;
V_1618 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
return F_355 ( V_7 , V_559 , V_1618 , V_1626 ) ;
}
static int F_356 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
struct V_539 V_540 ;
const struct V_539 * V_1628 ;
struct V_31 * V_51 ;
void * V_360 ;
T_1 V_673 ;
V_22 V_1308 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_542 ] ||
! V_30 -> V_5 [ V_1629 ] )
return - V_16 ;
V_1308 = F_4 ( V_30 -> V_5 [ V_1629 ] ) ;
if ( ! V_7 -> V_328 -> V_318 ||
! ( V_7 -> V_18 . V_49 & V_317 ) )
return - V_560 ;
if ( V_1308 < V_1630 ||
V_1308 > V_7 -> V_18 . V_461 )
return - V_16 ;
V_35 = F_81 ( V_7 , V_30 , & V_540 ) ;
if ( V_35 )
return V_35 ;
F_116 ( V_17 ) ;
if ( ! F_264 ( V_17 ) &&
! F_357 ( & V_17 -> V_540 , & V_540 ) ) {
V_1628 = F_358 ( & V_17 -> V_540 ,
& V_540 ) ;
if ( V_1628 != & V_540 ) {
F_118 ( V_17 ) ;
return - V_564 ;
}
}
F_118 ( V_17 ) ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1631 ) ;
if ( ! V_360 ) {
V_35 = - V_89 ;
goto V_683;
}
V_35 = F_359 ( V_7 , V_17 , V_540 . V_53 ,
V_1308 , & V_673 ) ;
if ( V_35 )
goto V_683;
if ( F_104 ( V_51 , V_1369 , V_673 ,
V_606 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_683:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_360 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
T_1 V_673 ;
if ( ! V_30 -> V_5 [ V_1369 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1632 )
return - V_560 ;
V_673 = F_5 ( V_30 -> V_5 [ V_1369 ] ) ;
return F_361 ( V_7 , V_17 , V_673 ) ;
}
static int F_362 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_726 V_707 ;
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_320 )
return - V_560 ;
V_35 = F_155 ( V_30 , & V_707 ) ;
if ( V_35 )
return V_35 ;
return F_363 ( V_7 , V_559 , NULL , & V_707 ) ;
}
static int F_364 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
T_3 V_1633 = V_280 | V_1634 ;
if ( ! V_30 -> V_5 [ V_1635 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_279 ] )
V_1633 = F_79 ( V_30 -> V_5 [ V_279 ] ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
case V_155 :
break;
case V_154 :
default:
return - V_560 ;
}
if ( ! V_7 -> V_328 -> V_322 )
return - V_560 ;
return F_365 ( V_17 , V_30 -> V_524 , V_1633 ,
F_21 ( V_30 -> V_5 [ V_1635 ] ) ,
F_22 ( V_30 -> V_5 [ V_1635 ] ) ) ;
}
static int F_366 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
struct V_539 V_540 ;
int V_35 ;
void * V_360 = NULL ;
T_1 V_673 ;
struct V_31 * V_51 = NULL ;
struct V_1636 V_139 = {
. V_1637 =
V_30 -> V_5 [ V_1638 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1639 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_322 )
return - V_560 ;
switch ( V_17 -> V_141 ) {
case V_155 :
if ( ! V_30 -> V_5 [ V_542 ] )
return - V_16 ;
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
break;
case V_154 :
default:
return - V_560 ;
}
if ( V_30 -> V_5 [ V_1629 ] ) {
if ( ! ( V_7 -> V_18 . V_49 & V_462 ) )
return - V_16 ;
V_139 . V_1640 = F_4 ( V_30 -> V_5 [ V_1629 ] ) ;
if ( V_139 . V_1640 < V_1630 ||
V_139 . V_1640 > V_7 -> V_18 . V_461 )
return - V_16 ;
}
V_139 . V_1641 = V_30 -> V_5 [ V_463 ] ;
if ( V_139 . V_1641 && ! ( V_7 -> V_18 . V_49 & V_462 ) )
return - V_16 ;
V_139 . V_1316 = F_170 ( V_30 -> V_5 [ V_1317 ] ) ;
V_540 . V_53 = NULL ;
if ( V_30 -> V_5 [ V_542 ] ) {
V_35 = F_81 ( V_7 , V_30 , & V_540 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_540 . V_53 && V_139 . V_1641 )
return - V_16 ;
F_116 ( V_17 ) ;
if ( V_139 . V_1641 && ! F_264 ( V_17 ) ) {
F_118 ( V_17 ) ;
return - V_564 ;
}
F_118 ( V_17 ) ;
V_139 . V_1642 = F_21 ( V_30 -> V_5 [ V_1639 ] ) ;
V_139 . V_45 = F_22 ( V_30 -> V_5 [ V_1639 ] ) ;
if ( V_30 -> V_5 [ V_1643 ] ) {
int V_45 = F_22 ( V_30 -> V_5 [ V_1643 ] ) ;
int V_160 ;
if ( V_45 % sizeof( T_3 ) )
return - V_16 ;
V_139 . V_1644 = V_45 / sizeof( T_3 ) ;
V_139 . V_1645 =
F_21 ( V_30 -> V_5 [ V_1643 ] ) ;
for ( V_160 = 0 ; V_160 < V_139 . V_1644 ; V_160 ++ ) {
if ( V_139 . V_1645 [ V_160 ] >= V_139 . V_45 )
return - V_16 ;
}
}
if ( ! V_139 . V_1637 ) {
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1646 ) ;
if ( ! V_360 ) {
V_35 = - V_89 ;
goto V_683;
}
}
V_139 . V_53 = V_540 . V_53 ;
V_35 = F_367 ( V_7 , V_17 , & V_139 , & V_673 ) ;
if ( V_35 )
goto V_683;
if ( V_51 ) {
if ( F_104 ( V_51 , V_1369 , V_673 ,
V_606 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
}
return 0 ;
V_59:
V_35 = - V_89 ;
V_683:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_368 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
T_1 V_673 ;
if ( ! V_30 -> V_5 [ V_1369 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_324 )
return - V_560 ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_144 :
case V_155 :
break;
case V_154 :
default:
return - V_560 ;
}
V_673 = F_5 ( V_30 -> V_5 [ V_1369 ] ) ;
return F_369 ( V_7 , V_17 , V_673 ) ;
}
static int F_370 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 V_1647 ;
bool V_359 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1648 ] )
return - V_16 ;
V_1647 = F_4 ( V_30 -> V_5 [ V_1648 ] ) ;
if ( V_1647 != V_1649 && V_1647 != V_1650 )
return - V_16 ;
V_17 = V_559 -> V_28 ;
if ( ! V_7 -> V_328 -> V_1651 )
return - V_560 ;
V_359 = ( V_1647 == V_1650 ) ? true : false ;
if ( V_359 == V_17 -> V_1652 )
return 0 ;
V_35 = F_371 ( V_7 , V_559 , V_359 , V_17 -> V_1653 ) ;
if ( ! V_35 )
V_17 -> V_1652 = V_359 ;
return V_35 ;
}
static int F_372 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
enum V_1654 V_1647 ;
struct V_1 * V_17 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_31 * V_51 ;
void * V_360 ;
int V_35 ;
V_17 = V_559 -> V_28 ;
if ( ! V_7 -> V_328 -> V_1651 )
return - V_560 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1655 ) ;
if ( ! V_360 ) {
V_35 = - V_89 ;
goto V_683;
}
if ( V_17 -> V_1652 )
V_1647 = V_1650 ;
else
V_1647 = V_1649 ;
if ( F_26 ( V_51 , V_1648 , V_1647 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_683:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_373 ( struct V_29 * V_30 ,
V_22 V_247 , V_22 V_1656 , V_22 V_1657 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
if ( V_247 > 100 || V_1657 > V_1658 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1659 )
return - V_560 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_560 ;
return F_374 ( V_7 , V_559 , V_247 , V_1656 , V_1657 ) ;
}
static int F_375 ( struct V_6 * V_7 ,
struct V_25 * V_559 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
T_7 V_1660 , V_1661 , V_1662 ;
V_22 V_1663 ;
int V_160 , V_1664 ;
int V_35 ;
if ( ! V_17 -> V_1665 )
return F_376 ( V_7 , V_559 , 0 , 0 ) ;
if ( ! V_17 -> V_1665 -> V_1666 && V_17 -> V_149 &&
V_7 -> V_328 -> V_970 ) {
struct V_873 V_874 ;
T_2 * V_675 ;
V_675 = V_17 -> V_149 -> V_1403 . V_566 ;
V_35 = F_187 ( V_7 , V_559 , V_675 , & V_874 ) ;
if ( V_35 )
return V_35 ;
if ( V_874 . V_883 & F_113 ( V_1667 ) )
V_17 -> V_1665 -> V_1666 =
( T_5 ) V_874 . V_947 ;
}
V_1660 = V_17 -> V_1665 -> V_1666 ;
V_1663 = V_17 -> V_1665 -> V_1668 ;
V_1664 = V_17 -> V_1665 -> V_1669 ;
for ( V_160 = 0 ; V_160 < V_1664 ; V_160 ++ )
if ( V_1660 < V_17 -> V_1665 -> V_1670 [ V_160 ] )
break;
V_1661 = V_160 > 0 ?
( V_17 -> V_1665 -> V_1670 [ V_160 - 1 ] - V_1663 ) : V_1671 ;
V_1662 = V_160 < V_1664 ?
( V_17 -> V_1665 -> V_1670 [ V_160 ] + V_1663 - 1 ) : V_1672 ;
return F_376 ( V_7 , V_559 , V_1661 , V_1662 ) ;
}
static int F_377 ( struct V_29 * V_30 ,
const T_7 * V_1673 , int V_1674 ,
V_22 V_1675 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
int V_160 , V_35 ;
T_7 V_1676 = V_1671 ;
for ( V_160 = 0 ; V_160 < V_1674 ; V_160 ++ ) {
if ( V_1673 [ V_160 ] > 0 || V_1673 [ V_160 ] <= V_1676 )
return - V_16 ;
V_1676 = V_1673 [ V_160 ] ;
}
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_560 ;
F_116 ( V_17 ) ;
F_378 ( V_17 ) ;
F_118 ( V_17 ) ;
if ( V_1674 <= 1 && V_7 -> V_328 -> V_1677 ) {
if ( V_1674 == 0 || V_1673 [ 0 ] == 0 )
return F_379 ( V_7 , V_559 , 0 , 0 ) ;
return F_379 ( V_7 , V_559 ,
V_1673 [ 0 ] , V_1675 ) ;
}
if ( ! F_112 ( & V_7 -> V_18 ,
V_1678 ) )
return - V_560 ;
if ( V_1674 == 1 && V_1673 [ 0 ] == 0 )
V_1674 = 0 ;
F_116 ( V_17 ) ;
if ( V_1674 ) {
struct V_1679 * V_1665 ;
V_1665 = F_37 ( sizeof( struct V_1679 ) +
V_1674 * sizeof( T_7 ) , V_135 ) ;
if ( ! V_1665 ) {
V_35 = - V_136 ;
goto V_1300;
}
V_1665 -> V_1668 = V_1675 ;
V_1665 -> V_1669 = V_1674 ;
memcpy ( V_1665 -> V_1670 , V_1673 ,
V_1674 * sizeof( T_7 ) ) ;
V_17 -> V_1665 = V_1665 ;
}
V_35 = F_375 ( V_7 , V_559 ) ;
V_1300:
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_380 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1680 + 1 ] ;
struct V_4 * V_1681 ;
int V_35 ;
V_1681 = V_30 -> V_5 [ V_1682 ] ;
if ( ! V_1681 )
return - V_16 ;
V_35 = F_31 ( V_5 , V_1680 , V_1681 ,
V_1683 , V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1684 ] &&
V_5 [ V_1685 ] ) {
const T_7 * V_1673 =
F_21 ( V_5 [ V_1684 ] ) ;
int V_45 = F_22 ( V_5 [ V_1684 ] ) ;
V_22 V_1675 = F_4 ( V_5 [ V_1685 ] ) ;
if ( V_45 % 4 )
return - V_16 ;
return F_377 ( V_30 , V_1673 , V_45 / 4 ,
V_1675 ) ;
}
if ( V_5 [ V_1686 ] &&
V_5 [ V_1687 ] &&
V_5 [ V_1688 ] ) {
V_22 V_247 = F_4 ( V_5 [ V_1686 ] ) ;
V_22 V_1656 = F_4 ( V_5 [ V_1687 ] ) ;
V_22 V_1657 = F_4 ( V_5 [ V_1688 ] ) ;
return F_373 ( V_30 , V_247 , V_1656 , V_1657 ) ;
}
return - V_16 ;
}
static int F_381 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1689 V_1196 = {} ;
int V_35 ;
V_35 = F_81 ( V_7 , V_30 , & V_1196 . V_540 ) ;
if ( V_35 )
return V_35 ;
return F_382 ( V_7 , V_559 , & V_1196 ) ;
}
static int F_383 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
return F_384 ( V_7 , V_559 ) ;
}
static int F_385 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1119 V_1183 ;
struct V_1195 V_1196 ;
int V_35 ;
memcpy ( & V_1183 , & V_1123 , sizeof( V_1183 ) ) ;
memcpy ( & V_1196 , & V_1690 , sizeof( V_1196 ) ) ;
if ( V_30 -> V_5 [ V_1125 ] ) {
V_35 = F_234 ( V_30 , & V_1183 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_649 ] ||
! F_22 ( V_30 -> V_5 [ V_649 ] ) )
return - V_16 ;
V_1196 . V_1691 = F_21 ( V_30 -> V_5 [ V_649 ] ) ;
V_1196 . V_1122 = F_22 ( V_30 -> V_5 [ V_649 ] ) ;
if ( V_30 -> V_5 [ V_1550 ] &&
! F_319 ( V_7 , V_1196 . V_1537 ,
F_4 ( V_30 -> V_5 [ V_1550 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_794 ] ) {
V_1196 . V_561 =
F_4 ( V_30 -> V_5 [ V_794 ] ) ;
V_35 = F_168 ( V_7 ,
V_145 ,
V_1196 . V_561 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_795 ] ) {
V_1196 . V_796 =
F_4 ( V_30 -> V_5 [ V_795 ] ) ;
if ( V_1196 . V_796 < 1 || V_1196 . V_796 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1198 ] ) {
V_35 = F_236 ( V_30 , & V_1196 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1196 . V_1218 )
V_1183 . V_1141 = false ;
if ( V_30 -> V_5 [ V_542 ] ) {
V_35 = F_81 ( V_7 , V_30 , & V_1196 . V_540 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1196 . V_540 . V_53 = NULL ;
}
if ( V_30 -> V_5 [ V_1103 ] ) {
T_2 * V_705 = F_21 ( V_30 -> V_5 [ V_1103 ] ) ;
int V_1549 =
F_22 ( V_30 -> V_5 [ V_1103 ] ) ;
struct V_242 * V_243 ;
if ( ! V_1196 . V_540 . V_53 )
return - V_16 ;
V_243 = V_7 -> V_18 . V_438 [ V_1196 . V_540 . V_53 -> V_367 ] ;
V_35 = F_269 ( V_243 , V_705 , V_1549 ,
& V_1196 . V_1104 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_733 ] ) {
V_35 = F_155 ( V_30 , & V_1196 . V_742 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_157 ( V_7 , V_1196 . V_540 . V_53 -> V_367 ,
& V_1196 . V_742 ) ;
if ( V_35 )
return V_35 ;
}
V_1196 . V_1552 =
F_170 ( V_30 -> V_5 [ V_1397 ] ) ;
return F_386 ( V_7 , V_559 , & V_1196 , & V_1183 ) ;
}
static int F_387 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
return F_388 ( V_7 , V_559 ) ;
}
static int F_389 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_1692 * V_192 = V_7 -> V_18 . V_1693 ;
struct V_4 * V_1694 , * V_1695 ;
int V_160 , V_1696 ;
if ( ! V_192 -> V_222 )
return 0 ;
V_1694 = F_45 ( V_51 , V_231 ) ;
if ( ! V_1694 )
return - V_89 ;
for ( V_160 = 0 ; V_160 < V_192 -> V_222 ; V_160 ++ ) {
V_1695 = F_45 ( V_51 , V_160 + 1 ) ;
if ( ! V_1695 )
return - V_89 ;
V_1696 = V_192 -> V_1697 [ V_160 ] . V_1698 ;
if ( F_49 ( V_51 , V_1699 , F_277 ( V_1696 , 8 ) ,
V_192 -> V_1697 [ V_160 ] . V_707 ) ||
F_49 ( V_51 , V_1700 , V_1696 ,
V_192 -> V_1697 [ V_160 ] . V_1701 ) ||
F_26 ( V_51 , V_1702 ,
V_192 -> V_1697 [ V_160 ] . V_1703 ) )
return - V_89 ;
F_46 ( V_51 , V_1695 ) ;
}
F_46 ( V_51 , V_1694 ) ;
return 0 ;
}
static int F_390 ( struct V_31 * V_51 ,
struct V_1704 * V_191 )
{
struct V_4 * V_193 ;
if ( ! V_191 )
return 0 ;
V_193 = F_45 ( V_51 , V_194 ) ;
if ( ! V_193 )
return - V_89 ;
if ( F_391 ( V_51 , V_1705 , V_191 -> V_1706 ) ||
F_391 ( V_51 , V_1707 , V_191 -> V_1058 ) ||
F_49 ( V_51 , V_1708 , V_607 , V_191 -> V_1709 ) ||
F_53 ( V_51 , V_1710 , V_191 -> V_1711 ) ||
F_53 ( V_51 , V_1712 , V_191 -> V_1713 ) ||
F_49 ( V_51 , V_195 ,
V_191 -> V_1714 , V_191 -> V_1715 ) ||
F_26 ( V_51 , V_200 ,
V_191 -> V_1716 ) ||
F_49 ( V_51 , V_202 ,
V_191 -> V_1717 , V_191 -> V_1718 ) ||
F_49 ( V_51 , V_1719 ,
F_277 ( V_191 -> V_1717 , 8 ) , V_191 -> V_1720 ) )
return - V_89 ;
if ( V_191 -> V_1721 . V_45 &&
F_49 ( V_51 , V_197 ,
sizeof( V_191 -> V_1721 ) , & V_191 -> V_1721 ) )
return - V_89 ;
if ( V_191 -> V_1722 . V_45 &&
F_49 ( V_51 , V_199 ,
sizeof( V_191 -> V_1722 ) + V_191 -> V_1723 ,
& V_191 -> V_1722 ) )
return - V_89 ;
F_46 ( V_51 , V_193 ) ;
return 0 ;
}
static int F_392 ( struct V_31 * V_51 ,
struct V_1323 * V_1367 )
{
struct V_4 * V_1724 , * V_1271 , * V_1725 , * V_1726 , * V_1327 , * V_1727 ;
int V_160 ;
if ( ! V_1367 )
return 0 ;
V_1724 = F_45 ( V_51 , V_233 ) ;
if ( ! V_1724 )
return - V_89 ;
if ( V_1367 -> V_1349 == 1 &&
F_26 ( V_51 , V_1326 ,
V_1367 -> V_1327 [ 0 ] . V_1325 * 1000 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_1356 , V_1367 -> V_1357 ) )
return - V_89 ;
if ( V_1367 -> V_1359 ) {
struct V_1288 V_1360 ;
if ( F_393 ( V_51 , V_1346 ,
V_1367 -> V_1358 ) )
return - V_89 ;
V_1360 . V_367 = V_1367 -> V_1360 . V_367 ;
V_1360 . V_1291 = V_1367 -> V_1360 . V_1291 ;
if ( F_49 ( V_51 , V_1347 ,
sizeof( V_1360 ) , & V_1360 ) )
return - V_89 ;
}
V_1271 = F_45 ( V_51 , V_1301 ) ;
if ( ! V_1271 )
return - V_89 ;
for ( V_160 = 0 ; V_160 < V_1367 -> V_441 ; V_160 ++ ) {
if ( F_26 ( V_51 , V_160 , V_1367 -> V_442 [ V_160 ] -> V_58 ) )
return - V_89 ;
}
F_46 ( V_51 , V_1271 ) ;
if ( V_1367 -> V_1335 ) {
V_1725 = F_45 ( V_51 , V_1339 ) ;
if ( ! V_1725 )
return - V_89 ;
for ( V_160 = 0 ; V_160 < V_1367 -> V_1335 ; V_160 ++ ) {
V_1726 = F_45 ( V_51 , V_160 ) ;
if ( ! V_1726 )
return - V_89 ;
if ( F_49 ( V_51 , V_1342 ,
V_1367 -> V_1348 [ V_160 ] . V_614 . V_612 ,
V_1367 -> V_1348 [ V_160 ] . V_614 . V_614 ) )
return - V_89 ;
F_46 ( V_51 , V_1726 ) ;
}
F_46 ( V_51 , V_1725 ) ;
}
V_1327 = F_45 ( V_51 , V_1324 ) ;
if ( ! V_1327 )
return - V_89 ;
for ( V_160 = 0 ; V_160 < V_1367 -> V_1349 ; V_160 ++ ) {
V_1727 = F_45 ( V_51 , V_160 + 1 ) ;
if ( ! V_1727 )
return - V_89 ;
if ( ! V_1727 ||
F_26 ( V_51 , V_1332 ,
V_1367 -> V_1327 [ V_160 ] . V_1325 ) ||
( V_1367 -> V_1327 [ V_160 ] . V_1334 &&
F_26 ( V_51 , V_1333 ,
V_1367 -> V_1327 [ V_160 ] . V_1334 ) ) )
return - V_89 ;
F_46 ( V_51 , V_1727 ) ;
}
F_46 ( V_51 , V_1327 ) ;
F_46 ( V_51 , V_1724 ) ;
return 0 ;
}
static int F_394 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_31 * V_51 ;
void * V_360 ;
V_22 V_1728 = V_621 ;
if ( ! V_7 -> V_18 . V_192 )
return - V_560 ;
if ( V_7 -> V_18 . V_1693 && V_7 -> V_18 . V_1693 -> V_191 ) {
V_1728 += V_7 -> V_18 . V_1693 -> V_191 -> V_1723 +
V_7 -> V_18 . V_1693 -> V_191 -> V_1714 +
V_7 -> V_18 . V_1693 -> V_191 -> V_1717 +
V_7 -> V_18 . V_1693 -> V_191 -> V_1717 / 8 ;
}
V_51 = F_75 ( V_1728 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1729 ) ;
if ( ! V_360 )
goto V_59;
if ( V_7 -> V_18 . V_1693 ) {
struct V_4 * V_204 ;
V_204 = F_45 ( V_51 , V_1730 ) ;
if ( ! V_204 )
goto V_59;
if ( ( V_7 -> V_18 . V_1693 -> V_1731 &&
F_27 ( V_51 , V_207 ) ) ||
( V_7 -> V_18 . V_1693 -> V_355 &&
F_27 ( V_51 , V_209 ) ) ||
( V_7 -> V_18 . V_1693 -> V_1732 &&
F_27 ( V_51 , V_211 ) ) ||
( V_7 -> V_18 . V_1693 -> V_1733 &&
F_27 ( V_51 , V_215 ) ) ||
( V_7 -> V_18 . V_1693 -> V_1734 &&
F_27 ( V_51 , V_217 ) ) ||
( V_7 -> V_18 . V_1693 -> V_1735 &&
F_27 ( V_51 , V_219 ) ) ||
( V_7 -> V_18 . V_1693 -> V_1736 &&
F_27 ( V_51 , V_221 ) ) )
goto V_59;
if ( F_389 ( V_51 , V_7 ) )
goto V_59;
if ( F_390 ( V_51 ,
V_7 -> V_18 . V_1693 -> V_191 ) )
goto V_59;
if ( F_392 (
V_51 ,
V_7 -> V_18 . V_1693 -> V_1737 ) )
goto V_59;
F_46 ( V_51 , V_204 ) ;
}
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_76 ( V_51 ) ;
return - V_89 ;
}
static int F_395 ( struct V_6 * V_7 ,
struct V_4 * V_43 ,
struct V_1692 * V_1738 )
{
struct V_4 * V_93 [ V_1739 ] ;
struct V_1704 * V_1183 ;
struct V_1740 * V_198 = NULL ;
struct V_1741 * V_48 = NULL ;
V_22 V_1728 ;
V_22 V_1742 , V_1743 , V_1723 = 0 , V_1744 ;
int V_35 , V_1745 ;
if ( ! V_7 -> V_18 . V_192 -> V_191 )
return - V_16 ;
V_35 = F_31 ( V_93 , V_1746 , V_43 ,
V_1747 , NULL ) ;
if ( V_35 )
return V_35 ;
if ( ! V_93 [ V_1705 ] ||
! V_93 [ V_1707 ] ||
! V_93 [ V_1708 ] ||
! V_93 [ V_1712 ] ||
! V_93 [ V_195 ] ||
! V_93 [ V_200 ] ||
! V_93 [ V_202 ] ||
! V_93 [ V_1719 ] )
return - V_16 ;
V_1742 = F_22 ( V_93 [ V_195 ] ) ;
if ( V_1742 > V_7 -> V_18 . V_192 -> V_191 -> V_196 )
return - V_16 ;
if ( F_4 ( V_93 [ V_200 ] ) >
V_7 -> V_18 . V_192 -> V_191 -> V_201 ||
F_4 ( V_93 [ V_200 ] ) == 0 )
return - V_16 ;
V_1743 = F_22 ( V_93 [ V_202 ] ) ;
if ( V_1743 > V_7 -> V_18 . V_192 -> V_191 -> V_203 )
return - V_16 ;
V_1744 = F_22 ( V_93 [ V_1719 ] ) ;
if ( V_1744 != F_277 ( V_1743 , 8 ) )
return - V_16 ;
if ( V_93 [ V_199 ] ) {
V_22 V_1748 = F_22 ( V_93 [ V_199 ] ) ;
V_198 = F_21 ( V_93 [ V_199 ] ) ;
V_1723 = V_1748 - sizeof( * V_198 ) ;
if ( ! V_198 -> V_45 || V_1723 % V_198 -> V_45 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_192 -> V_191 -> V_198 )
return - V_16 ;
if ( V_198 -> V_45 > V_7 -> V_18 . V_192 -> V_191 -> V_198 -> V_1749 )
return - V_16 ;
if ( V_198 -> V_45 < V_7 -> V_18 . V_192 -> V_191 -> V_198 -> V_1750 )
return - V_16 ;
if ( V_1723 > V_7 -> V_18 . V_192 -> V_191 -> V_198 -> V_1751 )
return - V_16 ;
if ( V_198 -> V_1392 + V_198 -> V_45 > V_1742 )
return - V_16 ;
}
if ( V_93 [ V_197 ] ) {
V_48 = F_21 ( V_93 [ V_197 ] ) ;
if ( ! V_7 -> V_18 . V_192 -> V_191 -> V_48 )
return - V_16 ;
if ( V_48 -> V_45 == 0 || V_48 -> V_45 > 4 )
return - V_16 ;
if ( V_48 -> V_45 + V_48 -> V_1392 > V_1742 )
return - V_16 ;
}
V_1728 = sizeof( * V_1183 ) ;
V_1728 += V_1742 ;
V_1728 += V_1743 + V_1744 ;
V_1728 += V_1723 ;
V_1183 = F_37 ( V_1728 , V_135 ) ;
if ( ! V_1183 )
return - V_136 ;
V_1183 -> V_1706 = F_396 ( V_93 [ V_1705 ] ) ;
V_1183 -> V_1058 = F_396 ( V_93 [ V_1707 ] ) ;
memcpy ( V_1183 -> V_1709 , F_21 ( V_93 [ V_1708 ] ) ,
V_607 ) ;
if ( V_93 [ V_1710 ] )
V_1745 = F_79 ( V_93 [ V_1710 ] ) ;
else
V_1745 = 0 ;
#ifdef F_397
V_35 = F_398 ( F_7 ( & V_7 -> V_18 ) , V_1752 , V_1753 ,
V_1754 , & V_1183 -> V_1755 , 1 ) ;
if ( V_35 ) {
F_39 ( V_1183 ) ;
return V_35 ;
}
if ( F_399 ( V_1183 -> V_1755 -> V_42 , V_1745 ) ) {
F_400 ( V_1183 -> V_1755 ) ;
F_39 ( V_1183 ) ;
return - V_1756 ;
}
V_1183 -> V_1711 = F_401 ( V_1183 -> V_1755 -> V_42 ) -> V_1757 ;
#else
if ( ! V_1745 ) {
F_39 ( V_1183 ) ;
return - V_16 ;
}
V_1183 -> V_1711 = V_1745 ;
#endif
V_1183 -> V_1713 = F_79 ( V_93 [ V_1712 ] ) ;
V_1183 -> V_1714 = V_1742 ;
V_1183 -> V_1715 = ( T_2 * ) V_1183 + sizeof( * V_1183 ) + V_1723 ;
memcpy ( ( void * ) V_1183 -> V_1715 ,
F_21 ( V_93 [ V_195 ] ) ,
V_1742 ) ;
if ( V_48 )
V_1183 -> V_1721 = * V_48 ;
V_1183 -> V_1716 = F_4 ( V_93 [ V_200 ] ) ;
V_1183 -> V_1717 = V_1743 ;
V_1183 -> V_1718 = ( T_2 * ) V_1183 + sizeof( * V_1183 ) + V_1723 + V_1742 ;
memcpy ( ( void * ) V_1183 -> V_1718 ,
F_21 ( V_93 [ V_202 ] ) ,
V_1743 ) ;
V_1183 -> V_1720 = ( T_2 * ) V_1183 + sizeof( * V_1183 ) + V_1723 +
V_1742 + V_1743 ;
memcpy ( ( void * ) V_1183 -> V_1720 ,
F_21 ( V_93 [ V_1719 ] ) ,
V_1744 ) ;
if ( V_198 ) {
V_1183 -> V_1723 = V_1723 ;
memcpy ( & V_1183 -> V_1722 , V_198 , sizeof( * V_198 ) + V_1723 ) ;
}
V_1738 -> V_191 = V_1183 ;
return 0 ;
}
static int F_402 ( struct V_6 * V_7 ,
const struct V_1758 * V_192 ,
struct V_4 * V_43 ,
struct V_1692 * V_1738 )
{
struct V_4 * * V_93 ;
int V_35 ;
V_93 = F_37 ( V_1759 * sizeof( * V_93 ) , V_135 ) ;
if ( ! V_93 )
return - V_136 ;
if ( ! ( V_192 -> V_49 & V_232 ) ) {
V_35 = - V_560 ;
goto V_620;
}
V_35 = F_31 ( V_93 , V_1378 , V_43 , V_41 ,
NULL ) ;
if ( V_35 )
goto V_620;
V_1738 -> V_1737 = F_278 ( & V_7 -> V_18 , NULL , V_93 ,
V_192 -> V_234 ) ;
V_35 = F_281 ( V_1738 -> V_1737 ) ;
if ( V_35 )
V_1738 -> V_1737 = NULL ;
V_620:
F_39 ( V_93 ) ;
return V_35 ;
}
static int F_403 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_4 * V_93 [ V_1760 ] ;
struct V_1692 V_1761 = {} ;
struct V_1692 * V_1762 ;
const struct V_1758 * V_192 = V_7 -> V_18 . V_192 ;
int V_35 , V_160 ;
bool V_1763 = V_7 -> V_18 . V_1693 ;
bool V_1764 = false ;
if ( ! V_192 )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_1730 ] ) {
F_404 ( V_7 ) ;
V_7 -> V_18 . V_1693 = NULL ;
goto V_1765;
}
V_35 = F_31 ( V_93 , V_1766 ,
V_30 -> V_5 [ V_1730 ] ,
V_1767 , V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_207 ] ) {
if ( ! ( V_192 -> V_49 & V_206 ) )
return - V_16 ;
V_1761 . V_1731 = true ;
}
if ( V_93 [ V_209 ] ) {
if ( ! ( V_192 -> V_49 & V_208 ) )
return - V_16 ;
V_1761 . V_355 = true ;
V_1764 = true ;
}
if ( V_93 [ V_211 ] ) {
if ( ! ( V_192 -> V_49 & V_210 ) )
return - V_16 ;
V_1761 . V_1732 = true ;
V_1764 = true ;
}
if ( V_93 [ V_213 ] )
return - V_16 ;
if ( V_93 [ V_215 ] ) {
if ( ! ( V_192 -> V_49 & V_214 ) )
return - V_16 ;
V_1761 . V_1733 = true ;
V_1764 = true ;
}
if ( V_93 [ V_217 ] ) {
if ( ! ( V_192 -> V_49 & V_216 ) )
return - V_16 ;
V_1761 . V_1734 = true ;
V_1764 = true ;
}
if ( V_93 [ V_219 ] ) {
if ( ! ( V_192 -> V_49 & V_218 ) )
return - V_16 ;
V_1761 . V_1735 = true ;
V_1764 = true ;
}
if ( V_93 [ V_221 ] ) {
if ( ! ( V_192 -> V_49 & V_220 ) )
return - V_16 ;
V_1761 . V_1736 = true ;
V_1764 = true ;
}
if ( V_93 [ V_231 ] ) {
struct V_4 * V_224 ;
int V_222 = 0 ;
int V_133 , V_1696 , V_1768 , V_1703 ;
struct V_4 * V_1769 [ V_1770 ] ;
V_1764 = true ;
F_36 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_222 ++ ;
if ( V_222 > V_192 -> V_222 )
return - V_16 ;
V_1761 . V_1697 = F_405 ( V_222 ,
sizeof( V_1761 . V_1697 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1761 . V_1697 )
return - V_136 ;
V_1761 . V_222 = V_222 ;
V_160 = 0 ;
F_36 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1771 ;
F_31 ( V_1769 , V_1772 , V_224 ,
NULL , V_30 -> V_127 ) ;
V_35 = - V_16 ;
if ( ! V_1769 [ V_1699 ] ||
! V_1769 [ V_1700 ] )
goto error;
V_1696 = F_22 ( V_1769 [ V_1700 ] ) ;
V_1768 = F_277 ( V_1696 , 8 ) ;
if ( F_22 ( V_1769 [ V_1699 ] ) != V_1768 )
goto error;
if ( V_1696 > V_192 -> V_229 ||
V_1696 < V_192 -> V_227 )
goto error;
if ( ! V_1769 [ V_1702 ] )
V_1703 = 0 ;
else
V_1703 = F_4 (
V_1769 [ V_1702 ] ) ;
if ( V_1703 > V_192 -> V_230 )
goto error;
V_1761 . V_1697 [ V_160 ] . V_1703 = V_1703 ;
V_1771 = F_406 ( V_1768 + V_1696 , V_135 ) ;
if ( ! V_1771 ) {
V_35 = - V_136 ;
goto error;
}
V_1761 . V_1697 [ V_160 ] . V_707 = V_1771 ;
memcpy ( V_1771 , F_21 ( V_1769 [ V_1699 ] ) ,
V_1768 ) ;
V_1771 += V_1768 ;
V_1761 . V_1697 [ V_160 ] . V_1701 = V_1771 ;
V_1761 . V_1697 [ V_160 ] . V_1698 = V_1696 ;
memcpy ( V_1771 ,
F_21 ( V_1769 [ V_1700 ] ) ,
V_1696 ) ;
V_160 ++ ;
}
}
if ( V_93 [ V_194 ] ) {
V_1764 = true ;
V_35 = F_395 (
V_7 , V_93 [ V_194 ] ,
& V_1761 ) ;
if ( V_35 )
goto error;
}
if ( V_93 [ V_233 ] ) {
V_1764 = true ;
V_35 = F_402 (
V_7 , V_192 , V_93 [ V_233 ] ,
& V_1761 ) ;
if ( V_35 )
goto error;
}
if ( V_1761 . V_1731 && V_1764 ) {
V_35 = - V_16 ;
goto error;
}
V_1762 = F_407 ( & V_1761 , sizeof( V_1761 ) , V_135 ) ;
if ( ! V_1762 ) {
V_35 = - V_136 ;
goto error;
}
F_404 ( V_7 ) ;
V_7 -> V_18 . V_1693 = V_1762 ;
V_1765:
if ( V_7 -> V_328 -> V_1765 &&
V_1763 != ! ! V_7 -> V_18 . V_1693 )
F_408 ( V_7 , V_7 -> V_18 . V_1693 ) ;
return 0 ;
error:
for ( V_160 = 0 ; V_160 < V_1761 . V_222 ; V_160 ++ )
F_39 ( V_1761 . V_1697 [ V_160 ] . V_707 ) ;
F_39 ( V_1761 . V_1697 ) ;
if ( V_1761 . V_191 && V_1761 . V_191 -> V_1755 )
F_400 ( V_1761 . V_191 -> V_1755 ) ;
F_39 ( V_1761 . V_191 ) ;
F_39 ( V_1761 . V_1737 ) ;
return V_35 ;
}
static int F_409 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_4 * V_1694 , * V_1695 , * V_1773 , * V_1774 ;
int V_160 , V_162 , V_1696 ;
struct V_1775 * V_236 ;
if ( ! V_7 -> V_237 -> V_239 )
return 0 ;
V_1774 = F_45 ( V_51 , V_241 ) ;
if ( ! V_1774 )
return - V_89 ;
for ( V_160 = 0 ; V_160 < V_7 -> V_237 -> V_239 ; V_160 ++ ) {
V_1773 = F_45 ( V_51 , V_160 + 1 ) ;
if ( ! V_1773 )
return - V_89 ;
V_236 = & V_7 -> V_237 -> V_1776 [ V_160 ] ;
if ( F_26 ( V_51 , V_1777 ,
V_236 -> V_1357 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_1778 ,
V_236 -> V_1779 ) )
return - V_89 ;
V_1694 = F_45 ( V_51 ,
V_1780 ) ;
if ( ! V_1694 )
return - V_89 ;
for ( V_162 = 0 ; V_162 < V_236 -> V_222 ; V_162 ++ ) {
V_1695 = F_45 ( V_51 , V_162 + 1 ) ;
if ( ! V_1695 )
return - V_89 ;
V_1696 = V_236 -> V_1697 [ V_162 ] . V_1698 ;
if ( F_49 ( V_51 , V_1699 ,
F_277 ( V_1696 , 8 ) ,
V_236 -> V_1697 [ V_162 ] . V_707 ) ||
F_49 ( V_51 , V_1700 , V_1696 ,
V_236 -> V_1697 [ V_162 ] . V_1701 ) ||
F_26 ( V_51 , V_1702 ,
V_236 -> V_1697 [ V_162 ] . V_1703 ) )
return - V_89 ;
F_46 ( V_51 , V_1695 ) ;
}
F_46 ( V_51 , V_1694 ) ;
F_46 ( V_51 , V_1773 ) ;
}
F_46 ( V_51 , V_1774 ) ;
return 0 ;
}
static int F_410 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_31 * V_51 ;
void * V_360 ;
if ( ! V_7 -> V_18 . V_237 )
return - V_560 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1781 ) ;
if ( ! V_360 )
goto V_59;
if ( V_7 -> V_237 && F_409 ( V_51 , V_7 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_76 ( V_51 ) ;
return - V_89 ;
}
void F_411 ( struct V_6 * V_7 )
{
struct V_1782 * V_237 = V_7 -> V_237 ;
int V_160 , V_162 ;
struct V_1775 * V_236 ;
if ( ! V_237 )
return;
for ( V_160 = 0 ; V_160 < V_237 -> V_239 ; V_160 ++ ) {
V_236 = & V_237 -> V_1776 [ V_160 ] ;
for ( V_162 = 0 ; V_162 < V_236 -> V_222 ; V_162 ++ )
F_39 ( V_236 -> V_1697 [ V_162 ] . V_707 ) ;
F_39 ( V_236 -> V_1697 ) ;
}
F_39 ( V_237 -> V_1776 ) ;
F_39 ( V_237 ) ;
V_7 -> V_237 = NULL ;
}
static int F_412 ( struct V_6 * V_7 ,
struct V_4 * V_236 ,
struct V_1775 * V_1783 )
{
int V_35 , V_160 ;
const struct V_1784 * V_237 = V_7 -> V_18 . V_237 ;
struct V_4 * V_93 [ V_1785 ] , * V_224 ;
int V_133 , V_1696 , V_1768 , V_1703 , V_222 = 0 ;
struct V_4 * V_1769 [ V_1770 ] ;
V_35 = F_31 ( V_93 , V_1786 , V_236 ,
V_1787 , NULL ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_1777 ] )
V_1783 -> V_1357 =
F_4 ( V_93 [ V_1777 ] ) ;
if ( V_1783 -> V_1357 > V_237 -> V_240 )
return - V_16 ;
if ( V_93 [ V_1778 ] )
V_1783 -> V_1779 =
F_4 ( V_93 [ V_1778 ] ) ;
if ( V_1783 -> V_1779 != V_1788 &&
V_1783 -> V_1779 != V_1789 )
return - V_16 ;
if ( ! V_93 [ V_1780 ] )
return - V_16 ;
F_36 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_222 ++ ;
if ( V_222 > V_237 -> V_222 )
return - V_16 ;
V_1783 -> V_1697 = F_405 ( V_222 , sizeof( V_1783 -> V_1697 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1783 -> V_1697 )
return - V_136 ;
V_1783 -> V_222 = V_222 ;
V_160 = 0 ;
F_36 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1771 ;
F_31 ( V_1769 , V_1772 , V_224 , NULL , NULL ) ;
if ( ! V_1769 [ V_1699 ] ||
! V_1769 [ V_1700 ] )
return - V_16 ;
V_1696 = F_22 ( V_1769 [ V_1700 ] ) ;
V_1768 = F_277 ( V_1696 , 8 ) ;
if ( F_22 ( V_1769 [ V_1699 ] ) != V_1768 )
return - V_16 ;
if ( V_1696 > V_237 -> V_229 ||
V_1696 < V_237 -> V_227 )
return - V_16 ;
if ( ! V_1769 [ V_1702 ] )
V_1703 = 0 ;
else
V_1703 = F_4 ( V_1769 [ V_1702 ] ) ;
if ( V_1703 > V_237 -> V_230 )
return - V_16 ;
V_1783 -> V_1697 [ V_160 ] . V_1703 = V_1703 ;
V_1771 = F_406 ( V_1768 + V_1696 , V_135 ) ;
if ( ! V_1771 )
return - V_136 ;
V_1783 -> V_1697 [ V_160 ] . V_707 = V_1771 ;
memcpy ( V_1771 , F_21 ( V_1769 [ V_1699 ] ) ,
V_1768 ) ;
V_1771 += V_1768 ;
V_1783 -> V_1697 [ V_160 ] . V_1701 = V_1771 ;
V_1783 -> V_1697 [ V_160 ] . V_1698 = V_1696 ;
memcpy ( V_1771 , F_21 ( V_1769 [ V_1700 ] ) ,
V_1696 ) ;
V_160 ++ ;
}
return 0 ;
}
static int F_413 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
const struct V_1784 * V_237 = V_7 -> V_18 . V_237 ;
struct V_1782 V_1790 = {} ;
struct V_1782 * V_1791 ;
int V_35 , V_1792 , V_239 = 0 , V_160 , V_162 ;
struct V_4 * V_236 ;
struct V_1775 * V_1793 ;
if ( ! V_7 -> V_18 . V_237 || ! V_7 -> V_328 -> V_1794 )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_241 ] ) {
F_411 ( V_7 ) ;
F_414 ( V_7 , NULL ) ;
return 0 ;
}
F_36 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_239 ++ ;
if ( V_239 > V_237 -> V_239 )
return - V_16 ;
V_1790 . V_1776 = F_405 ( V_239 , sizeof( V_1790 . V_1776 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1790 . V_1776 )
return - V_136 ;
V_1790 . V_239 = V_239 ;
V_160 = 0 ;
F_36 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_412 ( V_7 , V_236 ,
& V_1790 . V_1776 [ V_160 ] ) ;
if ( V_35 )
goto error;
V_160 ++ ;
}
V_35 = F_414 ( V_7 , & V_1790 ) ;
if ( V_35 )
goto error;
V_1791 = F_407 ( & V_1790 , sizeof( V_1790 ) , V_135 ) ;
if ( ! V_1791 ) {
V_35 = - V_136 ;
goto error;
}
F_411 ( V_7 ) ;
V_7 -> V_237 = V_1791 ;
return 0 ;
error:
for ( V_160 = 0 ; V_160 < V_1790 . V_239 ; V_160 ++ ) {
V_1793 = & V_1790 . V_1776 [ V_160 ] ;
for ( V_162 = 0 ; V_162 < V_1793 -> V_222 ; V_162 ++ )
F_39 ( V_1793 -> V_1697 [ V_162 ] . V_707 ) ;
F_39 ( V_1793 -> V_1697 ) ;
}
F_39 ( V_1790 . V_1776 ) ;
return V_35 ;
}
static int F_415 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_4 * V_93 [ V_1795 ] ;
struct V_1796 V_1797 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1798 ] )
return - V_16 ;
V_35 = F_31 ( V_93 , V_1799 ,
V_30 -> V_5 [ V_1798 ] ,
V_1800 , V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
if ( F_22 ( V_93 [ V_1801 ] ) != V_1802 )
return - V_1803 ;
if ( F_22 ( V_93 [ V_1804 ] ) != V_1805 )
return - V_1803 ;
if ( F_22 ( V_93 [ V_1806 ] ) != V_1807 )
return - V_1803 ;
V_1797 . V_1808 = F_21 ( V_93 [ V_1804 ] ) ;
V_1797 . V_1809 = F_21 ( V_93 [ V_1806 ] ) ;
V_1797 . V_1810 = F_21 ( V_93 [ V_1801 ] ) ;
F_116 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1382 ;
goto V_620;
}
if ( ! V_7 -> V_328 -> V_1811 ) {
V_35 = - V_560 ;
goto V_620;
}
V_35 = F_416 ( V_7 , V_559 , & V_1797 ) ;
V_620:
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_417 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1812 )
return - V_564 ;
V_17 -> V_1812 = V_30 -> V_524 ;
return 0 ;
}
static int F_418 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_31 * V_51 ;
void * V_360 ;
const T_2 * V_703 ;
T_1 V_673 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_341 )
return - V_560 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1813 ) ;
if ( ! V_360 ) {
V_35 = - V_89 ;
goto V_683;
}
V_703 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_35 = F_419 ( V_7 , V_559 , V_703 , & V_673 ) ;
if ( V_35 )
goto V_683;
if ( F_104 ( V_51 , V_1369 , V_673 ,
V_606 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_683:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_420 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1814 * V_1815 , * V_1816 ;
int V_1817 ;
if ( ! ( V_7 -> V_18 . V_49 & V_345 ) )
return - V_560 ;
V_1816 = F_37 ( sizeof( * V_1816 ) , V_135 ) ;
if ( ! V_1816 )
return - V_136 ;
F_302 ( & V_7 -> V_1818 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1815 -> V_1819 == V_30 -> V_524 ) {
V_1817 = - V_793 ;
goto V_967;
}
}
V_1816 -> V_1819 = V_30 -> V_524 ;
F_421 ( & V_1816 -> V_666 , & V_7 -> V_1820 ) ;
F_304 ( & V_7 -> V_1818 ) ;
return 0 ;
V_967:
F_304 ( & V_7 -> V_1818 ) ;
F_39 ( V_1816 ) ;
return V_1817 ;
}
static int F_422 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_347 )
return - V_560 ;
if ( V_17 -> V_141 != V_155 )
return - V_560 ;
if ( F_423 ( V_17 ) )
return 0 ;
if ( F_424 ( V_7 -> V_1821 ) )
return - V_1822 ;
V_35 = F_425 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1823 = true ;
V_7 -> V_1824 ++ ;
return 0 ;
}
static int F_426 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
if ( V_17 -> V_141 != V_155 )
return - V_560 ;
if ( ! V_7 -> V_328 -> V_1825 )
return - V_560 ;
F_427 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_428 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
struct V_1826 V_1827 = {} ;
int V_35 ;
if ( V_17 -> V_141 != V_154 )
return - V_560 ;
if ( F_423 ( V_17 ) )
return - V_1828 ;
if ( F_424 ( V_7 -> V_1821 ) )
return - V_1822 ;
if ( ! V_30 -> V_5 [ V_1829 ] )
return - V_16 ;
V_1827 . V_1830 =
F_32 ( V_30 -> V_5 [ V_1829 ] ) ;
if ( ! V_1827 . V_1830 )
return - V_16 ;
if ( V_30 -> V_5 [ V_513 ] ) {
V_22 V_438 = F_4 ( V_30 -> V_5 [ V_513 ] ) ;
if ( V_438 & ~ ( V_22 ) V_17 -> V_18 -> V_514 )
return - V_560 ;
if ( V_438 && ! ( V_438 & F_113 ( V_1831 ) ) )
return - V_16 ;
V_1827 . V_438 = V_438 ;
}
V_35 = F_429 ( V_7 , V_17 , & V_1827 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1823 = true ;
V_7 -> V_1824 ++ ;
return 0 ;
}
static int F_430 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_560 ;
F_431 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_432 ( struct V_4 * V_1832 )
{
struct V_4 * V_43 ;
int V_45 = 0 , V_691 = 0 , V_133 ;
F_36 (attr, filter_attr, rem) {
V_45 += F_22 ( V_43 ) ;
V_691 ++ ;
}
if ( V_45 >= V_1833 )
return - V_16 ;
return V_691 ;
}
static int F_433 ( struct V_4 * V_1834 ,
struct V_1835 * V_1836 ,
bool V_278 )
{
struct V_4 * V_43 ;
int V_691 , V_133 , V_160 ;
struct V_1837 * V_1838 ;
V_691 = F_432 ( V_1834 ) ;
if ( V_691 < 0 )
return V_691 ;
F_117 ( sizeof( * V_1836 -> V_1839 ) != sizeof( * V_1836 -> V_1840 ) ) ;
V_1838 = F_405 ( V_691 , sizeof( * V_1836 -> V_1839 ) , V_135 ) ;
if ( ! V_1838 )
return - V_136 ;
V_160 = 0 ;
F_36 (attr, attr_filter, rem) {
V_1838 [ V_160 ] . V_1838 = F_434 ( V_43 , V_135 ) ;
V_1838 [ V_160 ] . V_45 = F_22 ( V_43 ) ;
V_160 ++ ;
}
if ( V_278 ) {
V_1836 -> V_1841 = V_691 ;
V_1836 -> V_1840 = V_1838 ;
} else {
V_1836 -> V_1842 = V_691 ;
V_1836 -> V_1839 = V_1838 ;
}
return 0 ;
}
static int F_435 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
struct V_4 * V_93 [ V_1843 ] , * V_1844 ;
struct V_1835 * V_1836 ;
struct V_31 * V_51 = NULL ;
void * V_360 = NULL ;
int V_35 = 0 ;
if ( V_17 -> V_141 != V_154 )
return - V_560 ;
if ( ! F_423 ( V_17 ) )
return - V_1382 ;
if ( ! V_30 -> V_5 [ V_1845 ] )
return - V_16 ;
V_35 = F_31 ( V_93 , V_1846 ,
V_30 -> V_5 [ V_1845 ] ,
V_1847 , V_30 -> V_127 ) ;
if ( V_35 )
return V_35 ;
V_1836 = F_37 ( sizeof( * V_1836 ) , V_135 ) ;
if ( ! V_1836 )
return - V_136 ;
V_1836 -> V_673 = V_17 -> V_18 -> V_1365 ++ ;
if ( ! V_93 [ V_1848 ] ||
F_32 ( V_93 [ V_1848 ] ) > V_1849 ) {
V_35 = - V_16 ;
goto V_620;
}
V_1836 -> type = F_32 ( V_93 [ V_1848 ] ) ;
if ( ! V_93 [ V_1850 ] ) {
V_35 = - V_16 ;
goto V_620;
}
memcpy ( V_1836 -> V_1851 , F_21 ( V_93 [ V_1850 ] ) ,
sizeof( V_1836 -> V_1851 ) ) ;
V_1836 -> V_1852 =
F_170 ( V_93 [ V_1853 ] ) ;
if ( V_93 [ V_1854 ] ) {
V_1836 -> V_1855 =
F_22 ( V_93 [ V_1854 ] ) ;
V_1836 -> V_1856 =
F_407 ( F_21 ( V_93 [ V_1854 ] ) ,
V_1836 -> V_1855 ,
V_135 ) ;
if ( ! V_1836 -> V_1856 ) {
V_35 = - V_136 ;
goto V_620;
}
}
if ( V_93 [ V_1857 ] )
V_1836 -> V_1858 = F_4 ( V_93 [ V_1857 ] ) ;
switch ( V_1836 -> type ) {
case V_1859 :
if ( ! V_93 [ V_1860 ] ) {
V_35 = - V_16 ;
goto V_620;
}
V_1836 -> V_1861 =
F_32 ( V_93 [ V_1860 ] ) ;
V_1836 -> V_1862 =
F_170 ( V_93 [ V_1863 ] ) ;
if ( ( ! ( V_1836 -> V_1861 & V_1864 ) ) &&
V_1836 -> V_1862 ) {
V_35 = - V_16 ;
goto V_620;
}
break;
case V_1865 :
V_1836 -> V_1866 =
F_170 ( V_93 [ V_1867 ] ) ;
break;
case V_1868 :
if ( ! V_93 [ V_1869 ] ||
! V_93 [ V_1870 ] ) {
V_35 = - V_16 ;
goto V_620;
}
V_1836 -> V_1871 =
F_32 ( V_93 [ V_1869 ] ) ;
V_1836 -> V_1872 =
F_32 ( V_93 [ V_1870 ] ) ;
memcpy ( V_1836 -> V_1873 . V_703 ,
F_21 ( V_93 [ V_1874 ] ) ,
sizeof( V_1836 -> V_1873 . V_703 ) ) ;
if ( V_1836 -> V_1858 ) {
V_35 = - V_16 ;
goto V_620;
}
break;
default:
V_35 = - V_16 ;
goto V_620;
}
if ( V_93 [ V_1875 ] ) {
struct V_4 * V_1876 [ V_1877 ] ;
V_35 = F_31 ( V_1876 , V_1878 ,
V_93 [ V_1875 ] ,
V_1879 , V_30 -> V_127 ) ;
if ( V_35 )
goto V_620;
V_1836 -> V_1880 =
F_170 ( V_1876 [ V_1881 ] ) ;
if ( V_1876 [ V_1882 ] ) {
if ( V_1876 [ V_1883 ] ||
! V_1876 [ V_1884 ] ) {
V_35 = - V_16 ;
goto V_620;
}
V_1836 -> V_1885 =
F_22 ( V_1876 [ V_1882 ] ) ;
V_1836 -> V_1886 =
F_407 ( F_21 ( V_1876 [ V_1882 ] ) ,
V_1836 -> V_1885 , V_135 ) ;
if ( ! V_1836 -> V_1886 ) {
V_35 = - V_136 ;
goto V_620;
}
V_1836 -> V_1887 =
F_32 ( V_1876 [ V_1884 ] ) ;
} else {
struct V_4 * V_43 , * V_1888 =
V_1876 [ V_1883 ] ;
int V_691 , V_133 , V_160 = 0 ;
if ( ! V_1888 ) {
V_35 = - V_16 ;
goto V_620;
}
V_691 = F_145 ( V_1888 ) ;
if ( V_691 <= 0 ) {
V_35 = - V_16 ;
goto V_620;
}
V_1836 -> V_1889 = V_691 ;
V_1836 -> V_1890 =
F_37 ( sizeof( * V_1836 -> V_1890 ) * V_691 ,
V_135 ) ;
if ( ! V_1836 -> V_1890 ) {
V_35 = - V_136 ;
goto V_620;
}
F_36 (attr, mac_attr, rem)
memcpy ( V_1836 -> V_1890 [ V_160 ++ ] . V_703 , F_21 ( V_43 ) ,
sizeof( * V_1836 -> V_1890 ) ) ;
}
}
if ( V_93 [ V_1891 ] ) {
V_35 = F_433 ( V_93 [ V_1891 ] ,
V_1836 , true ) ;
if ( V_35 )
goto V_620;
}
if ( V_93 [ V_1892 ] ) {
V_35 = F_433 ( V_93 [ V_1892 ] ,
V_1836 , false ) ;
if ( V_35 )
goto V_620;
}
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 ) {
V_35 = - V_136 ;
goto V_620;
}
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1893 ) ;
if ( F_60 ( ! V_360 ) ) {
V_35 = - V_136 ;
goto V_620;
}
V_35 = F_436 ( V_7 , V_17 , V_1836 ) ;
V_620:
if ( V_35 < 0 ) {
F_437 ( V_1836 ) ;
F_76 ( V_51 ) ;
return V_35 ;
}
if ( F_104 ( V_51 , V_1369 , V_1836 -> V_673 ,
V_606 ) )
goto V_59;
V_1844 = F_45 ( V_51 , V_1845 ) ;
if ( ! V_1844 )
goto V_59;
if ( F_54 ( V_51 , V_1894 ,
V_1836 -> V_1895 ) )
goto V_59;
F_46 ( V_51 , V_1844 ) ;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_76 ( V_51 ) ;
return - V_89 ;
}
static int F_438 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
T_1 V_673 ;
if ( V_17 -> V_141 != V_154 )
return - V_560 ;
if ( ! F_423 ( V_17 ) )
return - V_1382 ;
if ( ! V_30 -> V_5 [ V_1369 ] )
return - V_16 ;
V_673 = F_5 ( V_30 -> V_5 [ V_1369 ] ) ;
F_439 ( V_7 , V_17 , V_673 ) ;
return 0 ;
}
static int F_440 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
struct V_1826 V_1827 = {} ;
V_22 V_570 = 0 ;
if ( V_17 -> V_141 != V_154 )
return - V_560 ;
if ( ! F_423 ( V_17 ) )
return - V_1382 ;
if ( V_30 -> V_5 [ V_1829 ] ) {
V_1827 . V_1830 =
F_32 ( V_30 -> V_5 [ V_1829 ] ) ;
if ( V_1827 . V_1830 <= 1 || V_1827 . V_1830 == 255 )
return - V_16 ;
V_570 |= V_1896 ;
}
if ( V_30 -> V_5 [ V_513 ] ) {
V_22 V_438 = F_4 ( V_30 -> V_5 [ V_513 ] ) ;
if ( V_438 & ~ ( V_22 ) V_17 -> V_18 -> V_514 )
return - V_560 ;
if ( V_438 && ! ( V_438 & F_113 ( V_1831 ) ) )
return - V_16 ;
V_1827 . V_438 = V_438 ;
V_570 |= V_1897 ;
}
if ( ! V_570 )
return - V_16 ;
return F_441 ( V_7 , V_17 , & V_1827 , V_570 ) ;
}
void F_442 ( struct V_1 * V_17 ,
struct V_1898 * V_1726 , T_10 V_1557 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_4 * V_1899 , * V_1900 , * V_1901 ;
struct V_31 * V_51 ;
void * V_360 ;
if ( F_60 ( ! V_1726 -> V_1902 || ! V_1726 -> V_1903 || ! V_1726 -> V_703 ) )
return;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_1904 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_59;
if ( F_104 ( V_51 , V_1369 , V_1726 -> V_673 ,
V_606 ) ||
F_49 ( V_51 , V_567 , V_607 , V_1726 -> V_703 ) )
goto V_59;
V_1899 = F_45 ( V_51 , V_1905 ) ;
if ( ! V_1899 )
goto V_59;
V_1900 = F_45 ( V_51 , V_1906 ) ;
if ( ! V_1900 )
goto V_59;
if ( F_54 ( V_51 , V_1894 , V_1726 -> V_1902 ) )
goto V_59;
F_46 ( V_51 , V_1900 ) ;
V_1901 = F_45 ( V_51 , V_1907 ) ;
if ( ! V_1901 )
goto V_59;
if ( F_54 ( V_51 , V_1848 , V_1726 -> type ) ||
F_54 ( V_51 , V_1894 , V_1726 -> V_1903 ) )
goto V_59;
if ( V_1726 -> V_30 && V_1726 -> V_1908 &&
F_49 ( V_51 , V_1854 , V_1726 -> V_1908 ,
V_1726 -> V_30 ) )
goto V_59;
F_46 ( V_51 , V_1901 ) ;
F_46 ( V_51 , V_1899 ) ;
F_65 ( V_51 , V_360 ) ;
if ( ! V_17 -> V_660 )
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_51 , 0 , V_1909 , V_1557 ) ;
else
F_443 ( F_7 ( & V_7 -> V_18 ) , V_51 ,
V_17 -> V_660 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_444 ( struct V_1 * V_17 ,
T_2 V_1902 ,
enum V_1910 V_1597 ,
T_1 V_673 , T_10 V_1557 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
struct V_4 * V_1844 ;
void * V_360 ;
if ( F_60 ( ! V_1902 ) )
return;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_1911 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_59;
if ( F_104 ( V_51 , V_1369 , V_673 ,
V_606 ) )
goto V_59;
V_1844 = F_45 ( V_51 , V_1845 ) ;
if ( ! V_1844 )
goto V_59;
if ( F_54 ( V_51 , V_1894 , V_1902 ) ||
F_54 ( V_51 , V_1912 , V_1597 ) )
goto V_59;
F_46 ( V_51 , V_1844 ) ;
F_65 ( V_51 , V_360 ) ;
if ( ! V_17 -> V_660 )
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_51 , 0 , V_1909 , V_1557 ) ;
else
F_443 ( F_7 ( & V_7 -> V_18 ) , V_51 ,
V_17 -> V_660 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
static int F_445 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_360 ;
struct V_31 * V_51 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , V_30 -> V_524 , V_30 -> V_525 , 0 ,
V_1913 ) ;
if ( ! V_360 )
goto V_59;
if ( F_26 ( V_51 , V_1914 ,
V_1915 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_329 ( V_51 ) ;
return - V_89 ;
}
static int F_446 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1916 V_1917 ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_1918 )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_1919 ] ||
! F_20 ( V_30 -> V_5 [ V_752 ] ) )
return - V_16 ;
memset ( & V_1917 , 0 , sizeof( V_1917 ) ) ;
V_1917 . V_1920 = F_79 ( V_30 -> V_5 [ V_1919 ] ) ;
V_1917 . V_1214 = F_21 ( V_30 -> V_5 [ V_752 ] ) ;
V_1917 . V_1215 = F_22 ( V_30 -> V_5 [ V_752 ] ) ;
return F_447 ( V_7 , V_559 , & V_1917 ) ;
}
static int F_448 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
enum V_1921 V_1491 = V_1922 ;
T_3 V_1308 ;
int V_516 ;
if ( ! V_7 -> V_328 -> V_444 )
return - V_560 ;
if ( F_60 ( ! V_7 -> V_328 -> V_446 ) )
return - V_16 ;
if ( V_7 -> V_1923 )
return - V_564 ;
if ( V_30 -> V_5 [ V_1924 ] )
V_1491 = F_79 ( V_30 -> V_5 [ V_1924 ] ) ;
if ( V_1491 >= V_1925 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1926 ] )
return - V_16 ;
V_1308 =
F_79 ( V_30 -> V_5 [ V_1926 ] ) ;
if ( V_1308 > V_1927 )
return - V_1803 ;
V_516 = F_449 ( V_7 , V_17 , V_1491 , V_1308 ) ;
if ( ! V_516 )
V_7 -> V_1923 = V_30 -> V_524 ;
return V_516 ;
}
static int F_450 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_446 )
return - V_560 ;
if ( V_7 -> V_1923 ) {
V_7 -> V_1923 = 0 ;
F_451 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_452 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_95 ( V_30 ) , V_30 -> V_5 ) ;
int V_160 , V_35 ;
V_22 V_1928 , V_1561 ;
if ( ! V_7 -> V_18 . V_491 )
return - V_560 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1558 ] ||
! V_30 -> V_5 [ V_1560 ] )
return - V_16 ;
V_1928 = F_4 ( V_30 -> V_5 [ V_1558 ] ) ;
V_1561 = F_4 ( V_30 -> V_5 [ V_1560 ] ) ;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_487 ; V_160 ++ ) {
const struct V_1929 * V_1930 ;
void * V_140 = NULL ;
int V_45 = 0 ;
V_1930 = & V_7 -> V_18 . V_491 [ V_160 ] ;
if ( V_1930 -> V_30 . V_1559 != V_1928 || V_1930 -> V_30 . V_1561 != V_1561 )
continue;
if ( V_1930 -> V_49 & ( V_1931 |
V_1932 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1930 -> V_49 & V_1932 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1930 -> V_49 & V_1933 ) {
if ( ! F_423 ( V_17 ) )
return - V_574 ;
}
if ( ! V_1930 -> V_1934 )
return - V_560 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_490 ] ) {
V_140 = F_21 ( V_30 -> V_5 [ V_490 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_490 ] ) ;
}
V_7 -> V_1570 = V_30 ;
V_35 = V_7 -> V_18 . V_491 [ V_160 ] . V_1934 ( & V_7 -> V_18 , V_17 ,
V_140 , V_45 ) ;
V_7 -> V_1570 = NULL ;
return V_35 ;
}
return - V_560 ;
}
static int F_453 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
struct V_4 * * V_1470 = F_15 ( & V_38 ) ;
V_22 V_1928 , V_1561 ;
unsigned int V_160 ;
int V_1935 = - 1 ;
int V_35 ;
void * V_140 = NULL ;
unsigned int V_1572 = 0 ;
if ( V_34 -> args [ 0 ] ) {
struct V_18 * V_18 = F_19 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 )
return - V_23 ;
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
V_35 = F_14 ( V_34 -> V_36 , V_37 + V_38 . V_39 , V_1470 ,
V_38 . V_40 , V_41 , NULL ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1470 [ V_1558 ] ||
! V_1470 [ V_1560 ] )
return - V_16 ;
* V_17 = F_1 ( F_16 ( V_32 -> V_42 ) , V_1470 ) ;
if ( F_17 ( * V_17 ) )
* V_17 = NULL ;
* V_7 = F_8 ( F_16 ( V_32 -> V_42 ) , V_1470 ) ;
if ( F_17 ( * V_7 ) )
return F_18 ( * V_7 ) ;
V_1928 = F_4 ( V_1470 [ V_1558 ] ) ;
V_1561 = F_4 ( V_1470 [ V_1560 ] ) ;
for ( V_160 = 0 ; V_160 < ( * V_7 ) -> V_18 . V_487 ; V_160 ++ ) {
const struct V_1929 * V_1930 ;
V_1930 = & ( * V_7 ) -> V_18 . V_491 [ V_160 ] ;
if ( V_1930 -> V_30 . V_1559 != V_1928 || V_1930 -> V_30 . V_1561 != V_1561 )
continue;
if ( ! V_1930 -> V_1936 )
return - V_560 ;
V_1935 = V_160 ;
break;
}
if ( V_1935 < 0 )
return - V_560 ;
if ( V_1470 [ V_490 ] ) {
V_140 = F_21 ( V_1470 [ V_490 ] ) ;
V_1572 = F_22 ( V_1470 [ V_490 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1935 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_140 ;
V_34 -> args [ 4 ] = V_1572 ;
return 0 ;
}
static int F_454 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
unsigned int V_1935 ;
const struct V_1929 * V_1930 ;
void * V_140 ;
int V_1572 ;
int V_35 ;
struct V_4 * V_1937 ;
F_69 () ;
V_35 = F_453 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_620;
V_1935 = V_34 -> args [ 2 ] ;
V_140 = ( void * ) V_34 -> args [ 3 ] ;
V_1572 = V_34 -> args [ 4 ] ;
V_1930 = & V_7 -> V_18 . V_491 [ V_1935 ] ;
if ( V_1930 -> V_49 & ( V_1931 |
V_1932 ) ) {
if ( ! V_17 ) {
V_35 = - V_16 ;
goto V_620;
}
if ( V_1930 -> V_49 & V_1932 &&
! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_620;
}
if ( V_1930 -> V_49 & V_1933 ) {
if ( ! F_423 ( V_17 ) ) {
V_35 = - V_574 ;
goto V_620;
}
}
}
while ( 1 ) {
void * V_360 = F_23 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_520 , V_521 ,
V_1564 ) ;
if ( ! V_360 )
break;
if ( F_26 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ,
V_606 ) ) ) {
F_66 ( V_32 , V_360 ) ;
break;
}
V_1937 = F_45 ( V_32 , V_490 ) ;
if ( ! V_1937 ) {
F_66 ( V_32 , V_360 ) ;
break;
}
V_35 = V_1930 -> V_1936 ( & V_7 -> V_18 , V_17 , V_32 , V_140 , V_1572 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_46 ( V_32 , V_1937 ) ;
if ( V_35 == - V_89 || V_35 == - V_681 ) {
F_66 ( V_32 , V_360 ) ;
break;
} else if ( V_35 ) {
F_66 ( V_32 , V_360 ) ;
goto V_620;
}
F_65 ( V_32 , V_360 ) ;
}
V_35 = V_32 -> V_45 ;
V_620:
F_70 () ;
return V_35 ;
}
struct V_31 * F_455 ( struct V_18 * V_18 ,
enum V_357 V_50 ,
enum V_1556 V_43 ,
int V_1555 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_60 ( ! V_7 -> V_1570 ) )
return NULL ;
return F_328 ( V_7 , NULL , V_1555 ,
V_7 -> V_1570 -> V_524 ,
V_7 -> V_1570 -> V_525 ,
V_50 , V_43 , NULL , V_135 ) ;
}
int F_456 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_360 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_140 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_60 ( ! V_7 -> V_1570 ) ) {
F_329 ( V_32 ) ;
return - V_16 ;
}
F_46 ( V_32 , V_140 ) ;
F_65 ( V_32 , V_360 ) ;
return F_77 ( V_32 , V_7 -> V_1570 ) ;
}
static int F_457 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_1938 * V_1939 = NULL ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
T_2 * V_44 , V_45 , V_1940 , V_1941 , V_1942 ;
int V_516 ;
if ( ! V_7 -> V_328 -> V_451 )
return - V_560 ;
if ( V_30 -> V_5 [ V_1943 ] ) {
V_44 = F_21 ( V_30 -> V_5 [ V_1943 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_1943 ] ) ;
if ( V_45 % 2 || V_45 < V_1944 ||
V_45 > V_1945 )
return - V_16 ;
V_1939 = F_37 ( sizeof( struct V_1938 ) , V_135 ) ;
if ( ! V_1939 )
return - V_136 ;
V_1940 = ( V_45 - V_1944 ) >> 1 ;
if ( V_1940 ) {
V_1941 = V_1940 *
sizeof( struct V_1946 ) ;
memcpy ( V_1939 -> V_1947 , V_44 , V_1941 ) ;
V_1939 -> V_1940 = V_1940 ;
for ( V_1942 = 0 ; V_1942 < V_1940 ; V_1942 ++ ) {
if ( V_1939 -> V_1947 [ V_1942 ] . V_1948 > 7 ) {
F_39 ( V_1939 ) ;
return - V_16 ;
}
}
V_44 += V_1941 ;
}
memcpy ( V_1939 -> V_1948 , V_44 , V_1944 ) ;
}
F_116 ( V_559 -> V_28 ) ;
V_516 = F_40 ( V_559 -> V_28 ) ;
if ( ! V_516 )
V_516 = F_458 ( V_7 , V_559 , V_1939 ) ;
F_118 ( V_559 -> V_28 ) ;
F_39 ( V_1939 ) ;
return V_516 ;
}
static int F_459 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
const T_2 * V_1618 ;
T_2 V_1949 , V_1948 ;
T_3 V_1950 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_368 & V_453 ) )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_1951 ] || ! V_30 -> V_5 [ V_567 ] ||
! V_30 -> V_5 [ V_1952 ] )
return - V_16 ;
V_1949 = F_32 ( V_30 -> V_5 [ V_1951 ] ) ;
if ( V_1949 >= V_951 )
return - V_16 ;
V_1948 = F_32 ( V_30 -> V_5 [ V_1952 ] ) ;
if ( V_1948 >= V_1953 )
return - V_16 ;
if ( V_1949 >= V_1954 ) {
return - V_16 ;
}
V_1618 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( V_30 -> V_5 [ V_1955 ] ) {
V_1950 =
F_79 ( V_30 -> V_5 [ V_1955 ] ) ;
if ( ! V_1950 )
return - V_16 ;
}
F_116 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1382 ;
goto V_620;
default:
V_35 = - V_560 ;
goto V_620;
}
V_35 = F_460 ( V_7 , V_559 , V_1949 , V_1618 , V_1948 , V_1950 ) ;
V_620:
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_461 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
const T_2 * V_1618 ;
T_2 V_1949 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1951 ] || ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_1949 = F_32 ( V_30 -> V_5 [ V_1951 ] ) ;
V_1618 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
F_116 ( V_17 ) ;
V_35 = F_462 ( V_7 , V_559 , V_1949 , V_1618 ) ;
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_463 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_539 V_540 = {} ;
const T_2 * V_703 ;
T_2 V_1956 ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_1957 ||
! ( V_7 -> V_18 . V_368 & V_1958 ) )
return - V_560 ;
switch ( V_559 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_560 ;
}
if ( ! V_30 -> V_5 [ V_567 ] ||
! V_30 -> V_5 [ V_1959 ] )
return - V_16 ;
V_35 = F_81 ( V_7 , V_30 , & V_540 ) ;
if ( V_35 )
return V_35 ;
if ( V_540 . V_53 -> V_367 == V_1831 &&
V_540 . V_543 != V_544 &&
V_540 . V_543 != V_599 )
return - V_16 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_540 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( F_292 ( V_17 -> V_18 , & V_540 , V_17 -> V_141 ) )
return - V_16 ;
V_703 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_1956 = F_32 ( V_30 -> V_5 [ V_1959 ] ) ;
F_116 ( V_17 ) ;
V_35 = F_464 ( V_7 , V_559 , V_703 , V_1956 , & V_540 ) ;
F_118 ( V_17 ) ;
return V_35 ;
}
static int F_465 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
const T_2 * V_703 ;
if ( ! V_7 -> V_328 -> V_1957 ||
! V_7 -> V_328 -> V_1960 ||
! ( V_7 -> V_18 . V_368 & V_1958 ) )
return - V_560 ;
switch ( V_559 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_560 ;
}
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
V_703 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
F_116 ( V_17 ) ;
F_466 ( V_7 , V_559 , V_703 ) ;
F_118 ( V_17 ) ;
return 0 ;
}
static int F_467 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
const struct V_4 * V_622 ;
bool V_1961 ;
if ( ! V_7 -> V_328 -> V_456 )
return - V_560 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_560 ;
V_622 = V_30 -> V_5 [ V_1962 ] ;
V_1961 = F_170 ( V_622 ) ;
return F_468 ( V_7 , V_559 , V_1961 ) ;
}
static int F_469 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_1963 V_1964 = {} ;
int V_516 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_560 ;
if ( ! F_112 ( & V_7 -> V_18 ,
V_1577 ) )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_567 ] || ! V_30 -> V_5 [ V_1506 ] )
return - V_16 ;
F_116 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_516 = - V_1382 ;
goto V_620;
}
V_1964 . V_1965 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
if ( memcmp ( V_1964 . V_1965 , V_17 -> V_149 -> V_1403 . V_566 , V_607 ) ) {
V_516 = - V_16 ;
goto V_620;
}
V_1964 . V_1611 = F_21 ( V_30 -> V_5 [ V_1506 ] ) ;
V_1964 . V_1612 = F_22 ( V_30 -> V_5 [ V_1506 ] ) ;
if ( V_1964 . V_1612 != V_1507 &&
V_1964 . V_1612 != V_1966 ) {
V_516 = - V_16 ;
goto V_620;
}
if ( V_30 -> V_5 [ V_1967 ] ) {
int V_1968 = F_22 ( V_30 -> V_5 [ V_1967 ] ) ;
if ( V_1968 != V_1969 ) {
V_516 = - V_16 ;
goto V_620;
}
V_1964 . V_1970 =
F_21 ( V_30 -> V_5 [ V_1967 ] ) ;
}
V_516 = F_470 ( V_7 , V_559 , & V_1964 ) ;
V_620:
F_118 ( V_17 ) ;
return V_516 ;
}
static int F_471 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_523 [ 0 ] ;
struct V_25 * V_559 = V_30 -> V_523 [ 1 ] ;
struct V_1 * V_17 = V_559 -> V_28 ;
const T_2 * V_1965 ;
int V_516 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_560 ;
if ( ! F_112 ( & V_7 -> V_18 ,
V_1577 ) )
return - V_560 ;
if ( ! V_30 -> V_5 [ V_567 ] )
return - V_16 ;
F_116 ( V_17 ) ;
V_1965 = F_21 ( V_30 -> V_5 [ V_567 ] ) ;
V_516 = F_472 ( V_7 , V_559 , V_1965 ) ;
F_118 ( V_17 ) ;
return V_516 ;
}
static int F_473 ( const struct V_1971 * V_328 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_559 ;
bool V_1972 = V_328 -> V_1973 & V_1974 ;
if ( V_1972 )
F_69 () ;
if ( V_328 -> V_1973 & V_1975 ) {
V_7 = F_12 ( F_95 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1972 )
F_70 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_523 [ 0 ] = V_7 ;
} else if ( V_328 -> V_1973 & V_1976 ||
V_328 -> V_1973 & V_1977 ) {
F_2 () ;
V_17 = F_1 ( F_95 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1972 )
F_70 () ;
return F_18 ( V_17 ) ;
}
V_559 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_328 -> V_1973 & V_1976 ) {
if ( ! V_559 ) {
if ( V_1972 )
F_70 () ;
return - V_16 ;
}
V_30 -> V_523 [ 1 ] = V_559 ;
} else {
V_30 -> V_523 [ 1 ] = V_17 ;
}
if ( V_328 -> V_1973 & V_1978 &&
! F_423 ( V_17 ) ) {
if ( V_1972 )
F_70 () ;
return - V_574 ;
}
if ( V_559 )
F_273 ( V_559 ) ;
V_30 -> V_523 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_474 ( const struct V_1971 * V_328 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_523 [ 1 ] ) {
if ( V_328 -> V_1973 & V_1977 ) {
struct V_1 * V_17 = V_30 -> V_523 [ 1 ] ;
if ( V_17 -> V_19 )
F_191 ( V_17 -> V_19 ) ;
} else {
F_191 ( V_30 -> V_523 [ 1 ] ) ;
}
}
if ( V_328 -> V_1973 & V_1974 )
F_70 () ;
if ( V_328 -> V_1973 & V_1979 ) {
struct V_1980 * V_36 = F_475 ( V_32 ) ;
memset ( F_476 ( V_36 ) , 0 , F_477 ( V_36 ) ) ;
}
}
void F_478 ( struct V_6 * V_7 ,
enum V_357 V_50 )
{
struct V_31 * V_51 ;
struct V_358 V_359 = {} ;
F_60 ( V_50 != V_372 &&
V_50 != V_1981 ) ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return;
if ( F_59 ( V_7 , V_50 , V_51 , 0 , 0 , 0 , & V_359 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1982 , V_135 ) ;
}
void F_129 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
enum V_357 V_50 )
{
struct V_31 * V_51 ;
F_60 ( V_50 != V_602 &&
V_50 != V_603 ) ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return;
if ( F_103 ( V_51 , 0 , 0 , 0 , V_7 , V_17 ,
V_50 == V_603 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1982 , V_135 ) ;
}
static int F_479 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_1294 * V_1367 = V_7 -> V_1298 ;
struct V_4 * V_1280 ;
int V_160 ;
if ( F_60 ( ! V_1367 ) )
return 0 ;
V_1280 = F_45 ( V_51 , V_1302 ) ;
if ( ! V_1280 )
goto V_59;
for ( V_160 = 0 ; V_160 < V_1367 -> V_1296 ; V_160 ++ ) {
if ( F_49 ( V_51 , V_160 , V_1367 -> V_1303 [ V_160 ] . V_612 , V_1367 -> V_1303 [ V_160 ] . V_614 ) )
goto V_59;
}
F_46 ( V_51 , V_1280 ) ;
V_1280 = F_45 ( V_51 , V_1301 ) ;
if ( ! V_1280 )
goto V_59;
for ( V_160 = 0 ; V_160 < V_1367 -> V_441 ; V_160 ++ ) {
if ( F_26 ( V_51 , V_160 , V_1367 -> V_442 [ V_160 ] -> V_58 ) )
goto V_59;
}
F_46 ( V_51 , V_1280 ) ;
if ( V_1367 -> V_1214 &&
F_49 ( V_51 , V_752 , V_1367 -> V_1215 , V_1367 -> V_1214 ) )
goto V_59;
if ( V_1367 -> V_49 &&
F_26 ( V_51 , V_1311 , V_1367 -> V_49 ) )
goto V_59;
if ( V_1367 -> V_30 . V_1983 &&
( F_104 ( V_51 , V_1984 ,
V_1367 -> V_30 . V_1983 , V_1414 ) ||
F_49 ( V_51 , V_1985 , V_607 ,
V_1367 -> V_30 . V_1986 ) ) )
goto V_59;
return 0 ;
V_59:
return - V_89 ;
}
static int F_480 ( struct V_31 * V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_47 , V_22 V_48 , int V_49 ,
V_22 V_50 )
{
void * V_360 ;
V_360 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_59;
F_479 ( V_51 , V_7 ) ;
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
static int
F_481 ( struct V_31 * V_51 ,
struct V_1323 * V_1367 , V_22 V_50 )
{
void * V_360 ;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_26 ( V_51 , V_26 ,
F_11 ( V_1367 -> V_18 ) -> V_14 ) ||
F_26 ( V_51 , V_10 , V_1367 -> V_559 -> V_20 ) ||
F_104 ( V_51 , V_1369 , V_1367 -> V_1364 ,
V_606 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_360 ) ;
return - V_515 ;
}
void F_272 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_51 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return;
if ( F_480 ( V_51 , V_7 , V_17 , 0 , 0 , 0 ,
V_1987 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1988 , V_135 ) ;
}
struct V_31 * F_482 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1989 )
{
struct V_31 * V_51 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return NULL ;
if ( F_480 ( V_51 , V_7 , V_17 , 0 , 0 , 0 ,
V_1989 ? V_1990 :
V_1406 ) < 0 ) {
F_76 ( V_51 ) ;
return NULL ;
}
return V_51 ;
}
void F_483 ( struct V_6 * V_7 ,
struct V_31 * V_51 )
{
if ( ! V_51 )
return;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1988 , V_135 ) ;
}
void F_284 ( struct V_1323 * V_1367 , V_22 V_50 )
{
struct V_31 * V_51 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return;
if ( F_481 ( V_51 , V_1367 , V_50 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_332 ( & V_38 , F_7 ( V_1367 -> V_18 ) , V_51 , 0 ,
V_1988 , V_135 ) ;
}
static bool F_484 ( struct V_31 * V_51 ,
struct V_1991 * V_1295 )
{
if ( F_54 ( V_51 , V_1992 , V_1295 -> V_1619 ) )
goto V_59;
if ( V_1295 -> V_1228 [ 0 ] == '0' && V_1295 -> V_1228 [ 1 ] == '0' ) {
if ( F_54 ( V_51 , V_1993 ,
V_1994 ) )
goto V_59;
} else if ( V_1295 -> V_1228 [ 0 ] == '9' && V_1295 -> V_1228 [ 1 ] == '9' ) {
if ( F_54 ( V_51 , V_1993 ,
V_1995 ) )
goto V_59;
} else if ( ( V_1295 -> V_1228 [ 0 ] == '9' && V_1295 -> V_1228 [ 1 ] == '8' ) ||
V_1295 -> V_1996 ) {
if ( F_54 ( V_51 , V_1993 ,
V_1997 ) )
goto V_59;
} else {
if ( F_54 ( V_51 , V_1993 ,
V_1998 ) ||
F_61 ( V_51 , V_1116 ,
V_1295 -> V_1228 ) )
goto V_59;
}
if ( V_1295 -> V_14 != V_1999 ) {
struct V_18 * V_18 = F_19 ( V_1295 -> V_14 ) ;
if ( V_18 &&
F_26 ( V_51 , V_26 , V_1295 -> V_14 ) )
goto V_59;
if ( V_18 &&
V_18 -> V_497 & V_498 &&
F_27 ( V_51 , V_499 ) )
goto V_59;
}
return true ;
V_59:
return false ;
}
void F_485 ( enum V_357 V_2000 ,
struct V_1991 * V_1295 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2000 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_484 ( V_51 , V_1295 ) == false )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_245 () ;
F_486 ( & V_38 , V_51 , 0 ,
V_2001 , V_2002 ) ;
F_247 () ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
static void F_487 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1642 , T_4 V_45 ,
enum V_357 V_50 , T_10 V_1557 ,
int V_1007 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( 100 + V_45 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_1639 , V_45 , V_1642 ) )
goto V_59;
if ( V_1007 >= 0 ) {
struct V_4 * V_2003 =
F_45 ( V_51 , V_1004 ) ;
if ( ! V_2003 )
goto V_59;
if ( F_54 ( V_51 , V_1006 ,
V_1007 ) )
goto V_59;
F_46 ( V_51 , V_2003 ) ;
}
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_488 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1642 ,
T_4 V_45 , T_10 V_1557 )
{
F_487 ( V_7 , V_19 , V_1642 , V_45 ,
V_784 , V_1557 , - 1 ) ;
}
void F_489 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1642 ,
T_4 V_45 , T_10 V_1557 , int V_1007 )
{
F_487 ( V_7 , V_19 , V_1642 , V_45 ,
V_2005 , V_1557 , V_1007 ) ;
}
void F_490 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1642 ,
T_4 V_45 , T_10 V_1557 )
{
F_487 ( V_7 , V_19 , V_1642 , V_45 ,
V_2006 , V_1557 , - 1 ) ;
}
void F_491 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1642 ,
T_4 V_45 , T_10 V_1557 )
{
F_487 ( V_7 , V_19 , V_1642 , V_45 ,
V_2007 , V_1557 , - 1 ) ;
}
void F_492 ( struct V_25 * V_559 , const T_2 * V_1642 ,
T_4 V_45 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_2008 * V_2009 = ( void * ) V_1642 ;
V_22 V_50 ;
if ( F_60 ( V_45 < 2 ) )
return;
if ( F_493 ( V_2009 -> V_2010 ) )
V_50 = V_2011 ;
else
V_50 = V_2012 ;
F_494 ( V_559 , V_1642 , V_45 ) ;
F_487 ( V_7 , V_559 , V_1642 , V_45 , V_50 , V_2002 , - 1 ) ;
}
static void F_495 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_50 ,
const T_2 * V_703 , T_10 V_1557 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_27 ( V_51 , V_2013 ) ||
F_49 ( V_51 , V_567 , V_607 , V_703 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_496 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_703 ,
T_10 V_1557 )
{
F_495 ( V_7 , V_19 , V_784 ,
V_703 , V_1557 ) ;
}
void F_497 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_703 ,
T_10 V_1557 )
{
F_495 ( V_7 , V_19 , V_2005 ,
V_703 , V_1557 ) ;
}
void F_498 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_2014 * V_2015 ,
T_10 V_1557 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( 100 + V_2015 -> V_2016 + V_2015 -> V_2017 +
V_2015 -> V_1532 + V_2015 -> V_1612 +
( V_2015 -> V_1606 ? V_2018 : 0 ) , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_354 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
( V_2015 -> V_566 &&
F_49 ( V_51 , V_567 , V_607 , V_2015 -> V_566 ) ) ||
F_53 ( V_51 , V_1621 ,
V_2015 -> V_2019 < 0 ? V_2020 :
V_2015 -> V_2019 ) ||
( V_2015 -> V_2019 < 0 &&
( F_27 ( V_51 , V_2013 ) ||
F_26 ( V_51 , V_2021 ,
V_2015 -> V_2022 ) ) ) ||
( V_2015 -> V_2023 &&
F_49 ( V_51 , V_2024 , V_2015 -> V_2016 , V_2015 -> V_2023 ) ) ||
( V_2015 -> V_2025 &&
F_49 ( V_51 , V_2026 , V_2015 -> V_2017 ,
V_2015 -> V_2025 ) ) ||
( V_2015 -> V_2027 &&
F_53 ( V_51 , V_1587 ,
V_2015 -> V_1593 ) ) ||
( V_2015 -> V_2019 == V_2028 &&
( ( V_2015 -> V_1531 &&
F_49 ( V_51 , V_1530 , V_2015 -> V_1532 ,
V_2015 -> V_1531 ) ) ||
( V_2015 -> V_1611 &&
F_49 ( V_51 , V_1506 , V_2015 -> V_1612 , V_2015 -> V_1611 ) ) ||
( V_2015 -> V_1606 &&
F_49 ( V_51 , V_1605 , V_2018 , V_2015 -> V_1606 ) ) ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_499 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_2029 * V_30 , T_10 V_1557 )
{
struct V_31 * V_51 ;
void * V_360 ;
const T_2 * V_566 = V_30 -> V_1405 ? V_30 -> V_1405 -> V_566 : V_30 -> V_566 ;
V_51 = F_75 ( 100 + V_30 -> V_2016 + V_30 -> V_2017 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2030 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_566 ) ||
( V_30 -> V_2023 &&
F_49 ( V_51 , V_2024 , V_30 -> V_2016 ,
V_30 -> V_2023 ) ) ||
( V_30 -> V_2025 &&
F_49 ( V_51 , V_2026 , V_30 -> V_2017 ,
V_30 -> V_2025 ) ) ||
( V_30 -> V_2031 &&
F_27 ( V_51 , V_2032 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_500 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1597 ,
const T_2 * V_1214 , T_4 V_1215 , bool V_2033 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( 100 + V_1215 , V_135 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_356 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
( V_2033 && V_1597 &&
F_53 ( V_51 , V_1055 , V_1597 ) ) ||
( V_2033 &&
F_27 ( V_51 , V_2034 ) ) ||
( V_1214 && F_49 ( V_51 , V_752 , V_1215 , V_1214 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_135 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_501 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_566 ,
T_10 V_1557 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2035 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_566 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_502 ( struct V_25 * V_559 , const T_2 * V_703 ,
const T_2 * V_1214 , T_2 V_1215 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
if ( F_60 ( V_17 -> V_141 != V_145 ) )
return;
F_503 ( V_559 , V_703 ) ;
V_51 = F_75 ( 100 + V_1215 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2036 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_703 ) ||
( V_1215 && V_1214 &&
F_49 ( V_51 , V_752 , V_1215 , V_1214 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_504 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_703 ,
enum V_2037 V_2038 , int V_2039 ,
const T_2 * V_2040 , T_10 V_1557 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2041 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
( V_703 && F_49 ( V_51 , V_567 , V_607 , V_703 ) ) ||
F_26 ( V_51 , V_125 , V_2038 ) ||
( V_2039 != - 1 &&
F_54 ( V_51 , V_121 , V_2039 ) ) ||
( V_2040 && F_49 ( V_51 , V_120 , 6 , V_2040 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_505 ( struct V_18 * V_18 ,
struct V_52 * V_2042 ,
struct V_52 * V_2043 )
{
struct V_31 * V_51 ;
void * V_360 ;
struct V_4 * V_364 ;
V_51 = F_75 ( V_621 , V_2002 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2044 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , F_243 ( V_18 ) ) )
goto V_59;
V_364 = F_45 ( V_51 , V_2045 ) ;
if ( ! V_364 )
goto V_59;
if ( F_25 ( V_51 , V_2042 , false ) )
goto V_59;
F_46 ( V_51 , V_364 ) ;
V_364 = F_45 ( V_51 , V_2046 ) ;
if ( ! V_364 )
goto V_59;
if ( F_25 ( V_51 , V_2043 , false ) )
goto V_59;
F_46 ( V_51 , V_364 ) ;
F_65 ( V_51 , V_360 ) ;
F_245 () ;
F_486 ( & V_38 , V_51 , 0 ,
V_2001 , V_2002 ) ;
F_247 () ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
static void F_506 (
int V_50 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_673 ,
struct V_52 * V_53 ,
unsigned int V_1308 , T_10 V_1557 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) ||
F_26 ( V_51 , V_542 , V_53 -> V_58 ) ||
F_26 ( V_51 , V_547 ,
V_550 ) ||
F_104 ( V_51 , V_1369 , V_673 ,
V_606 ) )
goto V_59;
if ( V_50 == V_1631 &&
F_26 ( V_51 , V_1629 , V_1308 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_507 ( struct V_1 * V_17 , T_1 V_673 ,
struct V_52 * V_53 ,
unsigned int V_1308 , T_10 V_1557 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_508 ( V_17 , V_673 , V_53 , V_1308 ) ;
F_506 ( V_1631 ,
V_7 , V_17 , V_673 , V_53 ,
V_1308 , V_1557 ) ;
}
void F_509 ( struct V_1 * V_17 , T_1 V_673 ,
struct V_52 * V_53 ,
T_10 V_1557 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_510 ( V_17 , V_673 , V_53 ) ;
F_506 ( V_2047 ,
V_7 , V_17 , V_673 , V_53 , 0 , V_1557 ) ;
}
void F_511 ( struct V_25 * V_559 , const T_2 * V_675 ,
struct V_873 * V_874 , T_10 V_1557 )
{
struct V_18 * V_18 = V_559 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
F_512 ( V_559 , V_675 , V_874 ) ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
if ( F_180 ( V_51 , V_969 , 0 , 0 , 0 ,
V_7 , V_559 , V_675 , V_874 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
}
void F_513 ( struct V_25 * V_559 , const T_2 * V_675 ,
struct V_873 * V_874 , T_10 V_1557 )
{
struct V_18 * V_18 = V_559 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
struct V_873 V_2048 = {} ;
if ( ! V_874 )
V_874 = & V_2048 ;
F_514 ( V_559 , V_675 ) ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
if ( F_180 ( V_51 , V_2049 , 0 , 0 , 0 ,
V_7 , V_559 , V_675 , V_874 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
}
void F_515 ( struct V_25 * V_559 , const T_2 * V_675 ,
enum V_2050 V_1597 ,
T_10 V_1557 )
{
struct V_18 * V_18 = V_559 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_2051 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2052 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_675 ) ||
F_26 ( V_51 , V_2053 , V_1597 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
static bool F_516 ( struct V_25 * V_559 , T_2 V_50 ,
const T_2 * V_703 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
V_22 V_1819 = F_517 ( V_17 -> V_1812 ) ;
if ( ! V_1819 )
return false ;
V_51 = F_75 ( 100 , V_1557 ) ;
if ( ! V_51 )
return true ;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return true ;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_703 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_443 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1819 ) ;
return true ;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
return true ;
}
bool F_518 ( struct V_25 * V_559 ,
const T_2 * V_703 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
bool V_516 ;
F_519 ( V_559 , V_703 ) ;
if ( F_60 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_520 ( false ) ;
return false ;
}
V_516 = F_516 ( V_559 , V_2054 ,
V_703 , V_1557 ) ;
F_520 ( V_516 ) ;
return V_516 ;
}
bool F_521 ( struct V_25 * V_559 ,
const T_2 * V_703 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
bool V_516 ;
F_522 ( V_559 , V_703 ) ;
if ( F_60 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_520 ( false ) ;
return false ;
}
V_516 = F_516 ( V_559 ,
V_2055 ,
V_703 , V_1557 ) ;
F_520 ( V_516 ) ;
return V_516 ;
}
int F_523 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1819 ,
int V_2056 , int V_2057 ,
const T_2 * V_1642 , T_4 V_45 , V_22 V_49 , T_10 V_1557 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( 100 + V_45 , V_1557 ) ;
if ( ! V_51 )
return - V_136 ;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_1646 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return - V_136 ;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_26 ( V_51 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) ||
F_26 ( V_51 , V_542 , V_2056 ) ||
( V_2057 &&
F_26 ( V_51 , V_2058 , V_2057 ) ) ||
F_49 ( V_51 , V_1639 , V_45 , V_1642 ) ||
( V_49 &&
F_26 ( V_51 , V_2059 , V_49 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
return F_443 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1819 ) ;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
return - V_89 ;
}
void F_524 ( struct V_1 * V_17 , T_1 V_673 ,
const T_2 * V_1642 , T_4 V_45 , bool V_2060 , T_10 V_1557 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_51 ;
void * V_360 ;
F_525 ( V_17 , V_673 , V_2060 ) ;
V_51 = F_75 ( 100 + V_45 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2061 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_26 ( V_51 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) ||
F_49 ( V_51 , V_1639 , V_45 , V_1642 ) ||
F_104 ( V_51 , V_1369 , V_673 ,
V_606 ) ||
( V_2060 && F_27 ( V_51 , V_2062 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
static struct V_31 * F_526 ( struct V_25 * V_559 ,
const char * V_1049 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 = F_75 ( V_621 , V_1557 ) ;
void * * V_34 ;
if ( ! V_51 )
return NULL ;
V_34 = ( void * * ) V_51 -> V_34 ;
V_34 [ 0 ] = F_23 ( V_51 , 0 , 0 , 0 , V_2063 ) ;
if ( ! V_34 [ 0 ] ) {
F_76 ( V_51 ) ;
return NULL ;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_559 -> V_20 ) )
goto V_59;
if ( V_1049 && F_49 ( V_51 , V_567 , V_607 , V_1049 ) )
goto V_59;
V_34 [ 1 ] = F_45 ( V_51 , V_1682 ) ;
if ( ! V_34 [ 1 ] )
goto V_59;
V_34 [ 2 ] = V_7 ;
return V_51 ;
V_59:
F_76 ( V_51 ) ;
return NULL ;
}
static void F_527 ( struct V_31 * V_51 , T_10 V_1557 )
{
void * * V_34 = ( void * * ) V_51 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_46 ( V_51 , V_34 [ 1 ] ) ;
F_65 ( V_51 , V_34 [ 0 ] ) ;
memset ( V_51 -> V_34 , 0 , sizeof( V_51 -> V_34 ) ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
}
void F_528 ( struct V_25 * V_559 ,
enum V_2064 V_2065 ,
T_7 V_2066 , T_10 V_1557 )
{
struct V_31 * V_51 ;
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
F_529 ( V_559 , V_2065 , V_2066 ) ;
if ( F_60 ( V_2065 != V_2067 &&
V_2065 != V_2068 ) )
return;
if ( V_17 -> V_1665 ) {
V_17 -> V_1665 -> V_1666 = V_2066 ;
F_375 ( V_7 , V_559 ) ;
if ( V_2066 == 0 )
V_2066 = V_17 -> V_1665 -> V_1666 ;
}
V_51 = F_526 ( V_559 , NULL , V_1557 ) ;
if ( ! V_51 )
return;
if ( F_26 ( V_51 , V_2069 ,
V_2065 ) )
goto V_59;
if ( V_2066 && F_226 ( V_51 , V_2070 ,
V_2066 ) )
goto V_59;
F_527 ( V_51 , V_1557 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_530 ( struct V_25 * V_559 ,
const T_2 * V_1618 , V_22 V_2071 ,
V_22 V_247 , V_22 V_1657 , T_10 V_1557 )
{
struct V_31 * V_51 ;
V_51 = F_526 ( V_559 , V_1618 , V_1557 ) ;
if ( ! V_51 )
return;
if ( F_26 ( V_51 , V_1687 , V_2071 ) )
goto V_59;
if ( F_26 ( V_51 , V_1686 , V_247 ) )
goto V_59;
if ( F_26 ( V_51 , V_1688 , V_1657 ) )
goto V_59;
F_527 ( V_51 , V_1557 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_531 ( struct V_25 * V_559 ,
const T_2 * V_1618 , V_22 V_2071 , T_10 V_1557 )
{
struct V_31 * V_51 ;
F_532 ( V_559 , V_1618 , V_2071 ) ;
V_51 = F_526 ( V_559 , V_1618 , V_1557 ) ;
if ( ! V_51 )
return;
if ( F_26 ( V_51 , V_2072 , V_2071 ) )
goto V_59;
F_527 ( V_51 , V_1557 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_533 ( struct V_25 * V_559 , T_10 V_1557 )
{
struct V_31 * V_51 ;
V_51 = F_526 ( V_559 , NULL , V_1557 ) ;
if ( ! V_51 )
return;
if ( F_27 ( V_51 , V_2073 ) )
goto V_59;
F_527 ( V_51 , V_1557 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
static void F_534 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_566 ,
const T_2 * V_1810 , T_10 V_1557 )
{
struct V_31 * V_51 ;
struct V_4 * V_2074 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2075 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_566 ) )
goto V_59;
V_2074 = F_45 ( V_51 , V_1798 ) ;
if ( ! V_2074 )
goto V_59;
if ( F_49 ( V_51 , V_1801 ,
V_1802 , V_1810 ) )
goto V_59;
F_46 ( V_51 , V_2074 ) ;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_535 ( struct V_25 * V_559 , const T_2 * V_566 ,
const T_2 * V_1810 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_536 ( V_559 , V_566 ) ;
F_534 ( V_7 , V_559 , V_566 , V_1810 , V_1557 ) ;
}
static void
F_537 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_2076 ,
const T_2 * V_566 , bool V_2077 , T_10 V_1557 )
{
struct V_31 * V_51 ;
struct V_4 * V_43 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2078 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) )
goto V_59;
V_43 = F_45 ( V_51 , V_2079 ) ;
if ( ! V_43 )
goto V_59;
if ( F_26 ( V_51 , V_2080 , V_2076 ) ||
F_49 ( V_51 , V_2081 , V_607 , V_566 ) ||
( V_2077 &&
F_27 ( V_51 , V_2082 ) ) )
goto V_59;
F_46 ( V_51 , V_43 ) ;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_538 ( struct V_25 * V_559 , int V_2076 ,
const T_2 * V_566 , bool V_2077 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_539 ( V_559 , V_2076 , V_566 , V_2077 ) ;
F_537 ( V_7 , V_559 , V_2076 , V_566 , V_2077 , V_1557 ) ;
}
static void F_540 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_539 * V_540 ,
T_10 V_1557 ,
enum V_357 V_2083 ,
T_2 V_1385 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2083 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_10 , V_19 -> V_20 ) )
goto V_59;
if ( F_101 ( V_51 , V_540 ) )
goto V_59;
if ( ( V_2083 == V_2084 ) &&
( F_26 ( V_51 , V_1383 , V_1385 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_541 ( struct V_25 * V_559 ,
struct V_539 * V_540 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_41 ( V_17 ) ;
F_542 ( V_559 , V_540 ) ;
V_17 -> V_540 = * V_540 ;
V_17 -> V_565 = * V_540 ;
F_540 ( V_7 , V_559 , V_540 , V_135 ,
V_2085 , 0 ) ;
}
void F_543 ( struct V_25 * V_559 ,
struct V_539 * V_540 ,
T_2 V_1385 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_544 ( V_559 , V_540 ) ;
F_540 ( V_7 , V_559 , V_540 , V_135 ,
V_2084 , V_1385 ) ;
}
void
F_545 ( struct V_6 * V_7 ,
const struct V_539 * V_540 ,
enum V_2086 V_2087 ,
struct V_25 * V_19 , T_10 V_1557 )
{
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2088 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_59;
}
if ( F_26 ( V_51 , V_2089 , V_2087 ) )
goto V_59;
if ( F_101 ( V_51 , V_540 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_546 ( struct V_25 * V_559 , const T_2 * V_703 ,
T_1 V_673 , bool V_2090 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
F_547 ( V_559 , V_703 , V_673 , V_2090 ) ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_1813 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_703 ) ||
F_104 ( V_51 , V_1369 , V_673 ,
V_606 ) ||
( V_2090 && F_27 ( V_51 , V_2062 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_548 ( struct V_18 * V_18 ,
const T_2 * V_2091 , T_4 V_45 ,
int V_2056 , int V_2057 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
struct V_1814 * V_1815 ;
F_549 ( V_18 , V_2091 , V_45 , V_2056 , V_2057 ) ;
F_302 ( & V_7 -> V_1818 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_51 = F_75 ( V_45 + 100 , V_2002 ) ;
if ( ! V_51 ) {
F_304 ( & V_7 -> V_1818 ) ;
return;
}
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_1646 ) ;
if ( ! V_360 )
goto V_59;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_2056 &&
F_26 ( V_51 , V_542 , V_2056 ) ) ||
( V_2057 &&
F_26 ( V_51 , V_2058 , V_2057 ) ) ||
F_49 ( V_51 , V_1639 , V_45 , V_2091 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_443 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1815 -> V_1819 ) ;
}
F_304 ( & V_7 -> V_1818 ) ;
return;
V_59:
F_304 ( & V_7 -> V_1818 ) ;
if ( V_360 )
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
static int F_550 ( struct V_31 * V_51 ,
struct V_2092 * V_2093 )
{
struct V_2094 * V_1724 = V_2093 -> V_2095 ;
struct V_4 * V_2096 , * V_2097 , * V_363 ;
int V_160 , V_162 ;
V_2096 = F_45 (
V_51 , V_2098 ) ;
if ( ! V_2096 )
return - V_515 ;
for ( V_160 = 0 ; V_160 < V_1724 -> V_2099 ; V_160 ++ ) {
struct V_2100 * V_1726 = V_1724 -> V_1725 [ V_160 ] ;
V_2097 = F_45 ( V_51 , V_160 ) ;
if ( ! V_2097 )
break;
if ( F_49 ( V_51 , V_613 , V_1726 -> V_614 . V_612 ,
V_1726 -> V_614 . V_614 ) ) {
F_551 ( V_51 , V_2097 ) ;
goto V_620;
}
if ( V_1726 -> V_441 ) {
V_363 = F_45 (
V_51 , V_1301 ) ;
if ( ! V_363 ) {
F_551 ( V_51 , V_2097 ) ;
goto V_620;
}
for ( V_162 = 0 ; V_162 < V_1726 -> V_441 ; V_162 ++ ) {
if ( F_26 ( V_51 , V_162 , V_1726 -> V_442 [ V_162 ] ) ) {
F_551 ( V_51 , V_363 ) ;
F_551 ( V_51 , V_2097 ) ;
goto V_620;
}
}
F_46 ( V_51 , V_363 ) ;
}
F_46 ( V_51 , V_2097 ) ;
}
V_620:
F_46 ( V_51 , V_2096 ) ;
return 0 ;
}
void F_552 ( struct V_1 * V_17 ,
struct V_2092 * V_2093 ,
T_10 V_1557 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
int V_1728 = 200 ;
F_553 ( V_17 -> V_18 , V_17 , V_2093 ) ;
if ( V_2093 )
V_1728 += V_2093 -> V_2101 ;
V_51 = F_75 ( V_1728 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2102 ) ;
if ( ! V_360 )
goto V_683;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_683;
if ( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_683;
if ( V_2093 ) {
struct V_4 * V_2103 ;
V_2103 = F_45 ( V_51 , V_1730 ) ;
if ( ! V_2103 )
goto V_683;
if ( V_2093 -> V_355 &&
F_27 ( V_51 , V_209 ) )
goto V_683;
if ( V_2093 -> V_1732 &&
F_27 ( V_51 , V_211 ) )
goto V_683;
if ( V_2093 -> V_1733 &&
F_27 ( V_51 , V_215 ) )
goto V_683;
if ( V_2093 -> V_1734 &&
F_27 ( V_51 , V_217 ) )
goto V_683;
if ( V_2093 -> V_1735 &&
F_27 ( V_51 , V_219 ) )
goto V_683;
if ( V_2093 -> V_1736 &&
F_27 ( V_51 , V_221 ) )
goto V_683;
if ( V_2093 -> V_2104 >= 0 &&
F_26 ( V_51 , V_231 ,
V_2093 -> V_2104 ) )
goto V_683;
if ( V_2093 -> V_2105 &&
F_27 ( V_51 , V_2106 ) )
goto V_683;
if ( V_2093 -> V_2107 &&
F_27 ( V_51 , V_2108 ) )
goto V_683;
if ( V_2093 -> V_2109 &&
F_27 ( V_51 ,
V_2110 ) )
goto V_683;
if ( V_2093 -> V_2111 ) {
V_22 V_2112 = V_2113 ;
V_22 V_2114 = V_2115 ;
if ( ! V_2093 -> V_2116 ) {
V_2112 =
V_2117 ;
V_2114 =
V_2118 ;
}
if ( V_2093 -> V_2119 &&
F_26 ( V_51 , V_2114 , V_2093 -> V_2119 ) )
goto V_683;
if ( F_49 ( V_51 , V_2112 , V_2093 -> V_2101 ,
V_2093 -> V_2111 ) )
goto V_683;
}
if ( V_2093 -> V_2095 &&
F_550 ( V_51 , V_2093 ) )
goto V_683;
F_46 ( V_51 , V_2103 ) ;
}
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_683:
F_76 ( V_51 ) ;
}
void F_554 ( struct V_25 * V_559 , const T_2 * V_1618 ,
enum V_1625 V_2120 ,
T_3 V_1056 , T_10 V_1557 )
{
struct V_1 * V_17 = V_559 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
F_555 ( V_17 -> V_18 , V_559 , V_1618 , V_2120 ,
V_1056 ) ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2121 ) ;
if ( ! V_360 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_559 -> V_20 ) ||
F_54 ( V_51 , V_1627 , V_2120 ) ||
F_49 ( V_51 , V_567 , V_607 , V_1618 ) ||
( V_1056 > 0 &&
F_53 ( V_51 , V_1055 , V_1056 ) ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_1557 ) ;
return;
V_59:
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
static int F_556 ( struct V_2122 * V_2123 ,
unsigned long V_359 ,
void * V_2124 )
{
struct V_2125 * V_2126 = V_2124 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1814 * V_1815 , * V_24 ;
if ( V_359 != V_2127 || V_2126 -> V_2128 != V_2129 )
return V_2130 ;
F_245 () ;
F_557 (rdev, &cfg80211_rdev_list, list) {
struct V_1323 * V_1361 ;
F_557 (sched_scan_req,
&rdev->sched_scan_req_list,
list) {
if ( V_1361 -> V_660 == V_2126 -> V_47 ) {
V_1361 -> V_2131 = true ;
F_558 ( & V_7 -> V_2132 ) ;
}
}
F_557 (wdev, &rdev->wiphy.wdev_list, list) {
F_559 ( V_17 , V_2126 -> V_47 ) ;
if ( V_17 -> V_660 == V_2126 -> V_47 ) {
V_17 -> V_2131 = true ;
F_558 ( & V_7 -> V_2133 ) ;
} else if ( V_17 -> V_1535 == V_2126 -> V_47 ) {
F_558 ( & V_17 -> V_2134 ) ;
}
}
F_302 ( & V_7 -> V_1818 ) ;
F_560 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1815 -> V_1819 == V_2126 -> V_47 ) {
F_561 ( & V_1815 -> V_666 ) ;
F_39 ( V_1815 ) ;
break;
}
}
F_304 ( & V_7 -> V_1818 ) ;
}
F_247 () ;
F_562 ( V_2126 -> V_47 ) ;
return V_2135 ;
}
void F_563 ( struct V_25 * V_19 ,
struct V_2136 * V_2137 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
F_564 ( V_18 , V_19 , V_2137 ) ;
if ( ! V_2137 -> V_2138 )
return;
V_51 = F_75 ( 100 + V_2137 -> V_2139 , V_135 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2140 ) ;
if ( ! V_360 )
goto V_620;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_567 , V_607 , V_2137 -> V_2138 ) )
goto V_620;
if ( V_2137 -> V_776 &&
F_49 ( V_51 , V_752 , V_2137 -> V_775 , V_2137 -> V_776 ) )
goto V_620;
if ( V_2137 -> V_2141 &&
F_49 ( V_51 , V_2142 , V_2137 -> V_2139 ,
V_2137 -> V_2141 ) )
goto V_620;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_2004 , V_135 ) ;
return;
V_620:
F_76 ( V_51 ) ;
}
void F_565 ( struct V_1 * V_17 , T_10 V_1557 )
{
struct V_6 * V_7 ;
struct V_31 * V_51 ;
void * V_360 ;
V_22 V_1819 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1923 )
return;
V_1819 = V_7 -> V_1923 ;
V_7 -> V_1923 = 0 ;
V_51 = F_75 ( V_621 , V_1557 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2143 ) ;
if ( ! V_360 )
goto V_59;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_59;
F_65 ( V_51 , V_360 ) ;
F_443 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1819 ) ;
return;
V_59:
if ( V_360 )
F_66 ( V_51 , V_360 ) ;
F_76 ( V_51 ) ;
}
void F_566 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_360 ;
V_51 = F_75 ( V_621 , V_135 ) ;
if ( ! V_51 )
return;
V_360 = F_23 ( V_51 , 0 , 0 , 0 , V_2144 ) ;
if ( ! V_360 )
goto V_620;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_606 ) )
goto V_620;
F_65 ( V_51 , V_360 ) ;
F_332 ( & V_38 , F_7 ( V_18 ) , V_51 , 0 ,
V_2004 , V_135 ) ;
return;
V_620:
F_76 ( V_51 ) ;
}
int T_11 F_567 ( void )
{
int V_35 ;
V_35 = F_568 ( & V_38 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_569 ( & V_2145 ) ;
if ( V_35 )
goto V_2146;
return 0 ;
V_2146:
F_570 ( & V_38 ) ;
return V_35 ;
}
void F_571 ( void )
{
F_572 ( & V_2145 ) ;
F_570 ( & V_38 ) ;
}
