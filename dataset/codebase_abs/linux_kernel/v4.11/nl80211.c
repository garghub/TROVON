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
V_38 . V_40 , V_41 ) ;
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
V_95 ) ;
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
V_116 ) ;
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
int V_35 = F_31 (
V_114 , V_115 - 1 ,
V_30 -> V_5 [ V_126 ] ,
V_116 ) ;
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
if ( V_30 -> V_5 [ V_127 ] )
V_35 = F_30 ( V_30 -> V_5 [ V_127 ] , V_92 ) ;
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
static struct V_128 *
F_35 ( struct V_6 * V_7 ,
struct V_4 * V_129 , bool * V_130 )
{
struct V_91 V_131 ;
struct V_4 * V_90 ;
struct V_128 * V_8 ;
int V_132 , V_35 , V_96 = 0 ;
bool V_133 = false ;
F_36 (key, keys, rem) {
V_133 = true ;
break;
}
if ( ! V_133 )
return NULL ;
V_8 = F_37 ( sizeof( * V_8 ) , V_134 ) ;
if ( ! V_8 )
return F_3 ( - V_135 ) ;
V_8 -> V_96 = - 1 ;
F_36 (key, keys, rem) {
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_103 = - 1 ;
V_35 = F_30 ( V_90 , & V_131 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_131 . V_105 . V_90 )
goto error;
if ( V_131 . V_103 < 0 || V_131 . V_103 > 3 )
goto error;
if ( V_131 . V_96 ) {
if ( V_96 )
goto error;
V_96 = 1 ;
V_8 -> V_96 = V_131 . V_103 ;
if ( ! V_131 . V_100 || ! V_131 . V_101 )
goto error;
} else if ( V_131 . V_98 )
goto error;
V_35 = F_38 ( V_7 , & V_131 . V_105 ,
V_131 . V_103 , false , NULL ) ;
if ( V_35 )
goto error;
if ( V_131 . V_105 . V_110 != V_136 &&
V_131 . V_105 . V_110 != V_137 ) {
V_35 = - V_16 ;
goto error;
}
V_8 -> V_138 [ V_131 . V_103 ] . V_110 = V_131 . V_105 . V_110 ;
V_8 -> V_138 [ V_131 . V_103 ] . V_106 = V_131 . V_105 . V_106 ;
V_8 -> V_138 [ V_131 . V_103 ] . V_90 = V_8 -> V_139 [ V_131 . V_103 ] ;
memcpy ( V_8 -> V_139 [ V_131 . V_103 ] , V_131 . V_105 . V_90 , V_131 . V_105 . V_106 ) ;
if ( V_130 )
* V_130 = true ;
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
switch ( V_17 -> V_140 ) {
case V_141 :
case V_142 :
case V_143 :
case V_144 :
break;
case V_145 :
case V_146 :
case V_147 :
if ( ! V_17 -> V_148 )
return - V_149 ;
break;
case V_150 :
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
static int F_44 ( struct V_31 * V_51 , V_22 V_43 , T_3 V_157 )
{
struct V_4 * V_158 = F_45 ( V_51 , V_43 ) ;
int V_159 ;
if ( ! V_158 )
goto V_59;
V_159 = 0 ;
while ( V_157 ) {
if ( ( V_157 & 1 ) && F_27 ( V_51 , V_159 ) )
goto V_59;
V_157 >>= 1 ;
V_159 ++ ;
}
F_46 ( V_51 , V_158 ) ;
return 0 ;
V_59:
return - V_89 ;
}
static int F_47 ( struct V_18 * V_18 ,
struct V_31 * V_51 ,
bool V_54 )
{
struct V_4 * V_160 ;
int V_159 , V_161 ;
V_160 = F_45 ( V_51 ,
V_162 ) ;
if ( ! V_160 )
goto V_59;
for ( V_159 = 0 ; V_159 < V_18 -> V_163 ; V_159 ++ ) {
const struct V_164 * V_165 ;
struct V_4 * V_166 , * V_167 ;
V_165 = & V_18 -> V_168 [ V_159 ] ;
V_166 = F_45 ( V_51 , V_159 + 1 ) ;
if ( ! V_166 )
goto V_59;
V_167 = F_45 ( V_51 , V_169 ) ;
if ( ! V_167 )
goto V_59;
for ( V_161 = 0 ; V_161 < V_165 -> V_170 ; V_161 ++ ) {
struct V_4 * V_171 ;
V_171 = F_45 ( V_51 , V_161 + 1 ) ;
if ( ! V_171 )
goto V_59;
if ( F_26 ( V_51 , V_172 ,
V_165 -> V_173 [ V_161 ] . V_174 ) )
goto V_59;
if ( F_44 ( V_51 , V_175 ,
V_165 -> V_173 [ V_161 ] . V_176 ) )
goto V_59;
F_46 ( V_51 , V_171 ) ;
}
F_46 ( V_51 , V_167 ) ;
if ( V_165 -> V_177 &&
F_27 ( V_51 , V_178 ) )
goto V_59;
if ( F_26 ( V_51 , V_179 ,
V_165 -> V_180 ) ||
F_26 ( V_51 , V_181 ,
V_165 -> V_182 ) )
goto V_59;
if ( V_54 &&
( F_26 ( V_51 , V_183 ,
V_165 -> V_184 ) ||
F_26 ( V_51 , V_185 ,
V_165 -> V_186 ) ) )
goto V_59;
if ( V_165 -> V_187 &&
F_26 ( V_51 , V_188 ,
V_165 -> V_187 ) )
goto V_59;
F_46 ( V_51 , V_166 ) ;
}
F_46 ( V_51 , V_160 ) ;
return 0 ;
V_59:
return - V_89 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_31 * V_51 )
{
const struct V_189 * V_190 = V_7 -> V_18 . V_191 -> V_190 ;
struct V_4 * V_192 ;
if ( ! V_190 )
return 0 ;
V_192 = F_45 ( V_51 , V_193 ) ;
if ( ! V_192 )
return - V_89 ;
if ( F_26 ( V_51 , V_194 ,
V_190 -> V_195 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_194 ,
V_190 -> V_195 ) )
return - V_89 ;
if ( V_190 -> V_48 && F_27 ( V_51 , V_196 ) )
return - V_89 ;
if ( V_190 -> V_197 && F_49 ( V_51 , V_198 ,
sizeof( * V_190 -> V_197 ) , V_190 -> V_197 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_199 ,
V_190 -> V_200 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_201 ,
V_190 -> V_202 ) )
return - V_89 ;
F_46 ( V_51 , V_192 ) ;
return 0 ;
}
static int F_50 ( struct V_31 * V_51 ,
struct V_6 * V_7 ,
bool V_54 )
{
struct V_4 * V_203 ;
if ( ! V_7 -> V_18 . V_191 )
return 0 ;
V_203 = F_45 ( V_51 , V_204 ) ;
if ( ! V_203 )
return - V_89 ;
if ( ( ( V_7 -> V_18 . V_191 -> V_49 & V_205 ) &&
F_27 ( V_51 , V_206 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_49 & V_207 ) &&
F_27 ( V_51 , V_208 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_49 & V_209 ) &&
F_27 ( V_51 , V_210 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_49 & V_211 ) &&
F_27 ( V_51 , V_212 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_49 & V_213 ) &&
F_27 ( V_51 , V_214 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_49 & V_215 ) &&
F_27 ( V_51 , V_216 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_49 & V_217 ) &&
F_27 ( V_51 , V_218 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_49 & V_219 ) &&
F_27 ( V_51 , V_220 ) ) )
return - V_89 ;
if ( V_7 -> V_18 . V_191 -> V_221 ) {
struct V_222 V_223 = {
. V_224 = V_7 -> V_18 . V_191 -> V_221 ,
. V_225 = V_7 -> V_18 . V_191 -> V_226 ,
. V_227 = V_7 -> V_18 . V_191 -> V_228 ,
. V_229 = V_7 -> V_18 . V_191 -> V_229 ,
} ;
if ( F_49 ( V_51 , V_230 ,
sizeof( V_223 ) , & V_223 ) )
return - V_89 ;
}
if ( ( V_7 -> V_18 . V_191 -> V_49 & V_231 ) &&
F_26 ( V_51 , V_232 ,
V_7 -> V_18 . V_191 -> V_233 ) )
return - V_89 ;
if ( V_54 && F_48 ( V_7 , V_51 ) )
return - V_89 ;
F_46 ( V_51 , V_203 ) ;
return 0 ;
}
static int F_51 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_234 V_235 ;
if ( ! V_7 -> V_18 . V_236 )
return 0 ;
V_235 . V_237 = V_7 -> V_18 . V_236 -> V_238 ;
V_235 . V_239 = V_7 -> V_18 . V_236 -> V_239 ;
V_235 . V_223 . V_224 = V_7 -> V_18 . V_236 -> V_221 ;
V_235 . V_223 . V_225 = V_7 -> V_18 . V_236 -> V_226 ;
V_235 . V_223 . V_227 = V_7 -> V_18 . V_236 -> V_228 ;
V_235 . V_223 . V_229 = V_7 -> V_18 . V_236 -> V_229 ;
if ( F_49 ( V_51 , V_240 , sizeof( V_235 ) , & V_235 ) )
return - V_89 ;
return 0 ;
}
static int F_52 ( struct V_31 * V_51 ,
struct V_241 * V_242 )
{
struct V_4 * V_243 , * V_244 ;
struct V_245 * V_246 ;
int V_159 ;
if ( V_242 -> V_247 . V_248 &&
( F_49 ( V_51 , V_249 ,
sizeof( V_242 -> V_247 . V_250 ) ,
& V_242 -> V_247 . V_250 ) ||
F_53 ( V_51 , V_251 ,
V_242 -> V_247 . V_252 ) ||
F_54 ( V_51 , V_253 ,
V_242 -> V_247 . V_254 ) ||
F_54 ( V_51 , V_255 ,
V_242 -> V_247 . V_256 ) ) )
return - V_89 ;
if ( V_242 -> V_257 . V_258 &&
( F_49 ( V_51 , V_259 ,
sizeof( V_242 -> V_257 . V_260 ) ,
& V_242 -> V_257 . V_260 ) ||
F_26 ( V_51 , V_261 ,
V_242 -> V_257 . V_252 ) ) )
return - V_89 ;
V_243 = F_45 ( V_51 , V_262 ) ;
if ( ! V_243 )
return - V_89 ;
for ( V_159 = 0 ; V_159 < V_242 -> V_263 ; V_159 ++ ) {
V_244 = F_45 ( V_51 , V_159 ) ;
if ( ! V_244 )
return - V_89 ;
V_246 = & V_242 -> V_264 [ V_159 ] ;
if ( F_26 ( V_51 , V_265 ,
V_246 -> V_266 ) )
return - V_89 ;
if ( ( V_246 -> V_49 & V_267 ) &&
F_27 ( V_51 ,
V_268 ) )
return - V_89 ;
F_46 ( V_51 , V_244 ) ;
}
F_46 ( V_51 , V_243 ) ;
return 0 ;
}
static int
F_55 ( struct V_31 * V_51 ,
const struct V_269 * V_270 )
{
T_3 V_271 ;
struct V_4 * V_272 , * V_273 ;
enum V_274 V_275 ;
int V_159 ;
if ( ! V_270 )
return 0 ;
V_273 = F_45 ( V_51 , V_276 ) ;
if ( ! V_273 )
return - V_89 ;
for ( V_275 = 0 ; V_275 < V_156 ; V_275 ++ ) {
V_272 = F_45 ( V_51 , V_275 ) ;
if ( ! V_272 )
return - V_89 ;
V_159 = 0 ;
V_271 = V_270 [ V_275 ] . V_277 ;
while ( V_271 ) {
if ( ( V_271 & 1 ) &&
F_53 ( V_51 , V_278 ,
( V_159 << 4 ) | V_279 ) )
return - V_89 ;
V_271 >>= 1 ;
V_159 ++ ;
}
F_46 ( V_51 , V_272 ) ;
}
F_46 ( V_51 , V_273 ) ;
V_273 = F_45 ( V_51 , V_280 ) ;
if ( ! V_273 )
return - V_89 ;
for ( V_275 = 0 ; V_275 < V_156 ; V_275 ++ ) {
V_272 = F_45 ( V_51 , V_275 ) ;
if ( ! V_272 )
return - V_89 ;
V_159 = 0 ;
V_271 = V_270 [ V_275 ] . V_281 ;
while ( V_271 ) {
if ( ( V_271 & 1 ) &&
F_53 ( V_51 , V_278 ,
( V_159 << 4 ) | V_279 ) )
return - V_89 ;
V_271 >>= 1 ;
V_159 ++ ;
}
F_46 ( V_51 , V_272 ) ;
}
F_46 ( V_51 , V_273 ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 ,
struct V_31 * V_51 )
{
int V_159 = 0 ;
F_57 ( V_282 , V_283 ) ;
F_57 ( V_284 , V_285 ) ;
F_57 ( V_286 , V_287 ) ;
F_57 ( V_288 , V_289 ) ;
F_57 ( V_290 , V_291 ) ;
F_57 ( V_292 , V_293 ) ;
F_57 ( V_294 , V_295 ) ;
F_57 ( V_296 , V_297 ) ;
F_57 ( V_298 , V_299 ) ;
F_57 ( V_300 , V_301 ) ;
F_57 ( V_302 , V_303 ) ;
F_57 ( V_304 , V_305 ) ;
F_57 ( V_306 , V_307 ) ;
F_57 ( V_308 , V_309 ) ;
F_57 ( V_310 , V_311 ) ;
F_57 ( V_312 , V_313 ) ;
F_57 ( V_314 , V_315 ) ;
if ( V_7 -> V_18 . V_49 & V_316 )
F_57 ( V_317 , V_318 ) ;
F_57 ( V_319 , V_320 ) ;
F_57 ( V_321 , V_322 ) ;
F_57 ( V_323 , V_324 ) ;
if ( V_7 -> V_18 . V_49 & V_325 ) {
V_159 ++ ;
if ( F_26 ( V_51 , V_159 , V_326 ) )
goto V_59;
}
if ( V_7 -> V_327 -> V_328 || V_7 -> V_327 -> V_288 ||
V_7 -> V_327 -> V_308 ) {
V_159 ++ ;
if ( F_26 ( V_51 , V_159 , V_329 ) )
goto V_59;
}
F_57 ( V_330 , V_331 ) ;
if ( V_7 -> V_18 . V_49 & V_332 ) {
F_57 ( V_333 , V_334 ) ;
F_57 ( V_335 , V_336 ) ;
}
if ( V_7 -> V_18 . V_49 & V_337 )
F_57 ( V_338 , V_339 ) ;
F_57 ( V_340 , V_341 ) ;
F_57 ( V_342 , V_343 ) ;
if ( V_7 -> V_18 . V_49 & V_344 ) {
V_159 ++ ;
if ( F_26 ( V_51 , V_159 , V_345 ) )
goto V_59;
}
F_57 ( V_346 , V_347 ) ;
F_57 ( V_348 , V_349 ) ;
#ifdef F_58
F_57 ( V_350 , V_351 ) ;
#endif
if ( V_7 -> V_327 -> V_352 || V_7 -> V_327 -> V_298 ) {
V_159 ++ ;
if ( F_26 ( V_51 , V_159 , V_353 ) )
goto V_59;
}
if ( V_7 -> V_327 -> V_354 || V_7 -> V_327 -> V_302 ) {
V_159 ++ ;
if ( F_26 ( V_51 , V_159 , V_355 ) )
goto V_59;
}
return V_159 ;
V_59:
return - V_89 ;
}
static int F_59 ( struct V_6 * V_7 ,
enum V_356 V_50 ,
struct V_31 * V_51 , V_22 V_47 , V_22 V_48 ,
int V_49 , struct V_357 * V_358 )
{
void * V_359 ;
struct V_4 * V_360 , * V_361 ;
struct V_4 * V_362 , * V_363 ;
struct V_4 * V_364 ;
enum V_365 V_366 ;
struct V_52 * V_53 ;
int V_159 ;
const struct V_269 * V_270 =
V_7 -> V_18 . V_270 ;
V_22 V_367 ;
V_359 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_359 )
return - V_89 ;
if ( F_60 ( ! V_358 ) )
return - V_16 ;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_61 ( V_51 , V_368 ,
F_62 ( & V_7 -> V_18 ) ) ||
F_26 ( V_51 , V_369 ,
V_370 ) )
goto V_59;
if ( V_50 != V_371 )
goto V_372;
switch ( V_358 -> V_373 ) {
case 0 :
if ( F_54 ( V_51 , V_374 ,
V_7 -> V_18 . V_375 ) ||
F_54 ( V_51 , V_376 ,
V_7 -> V_18 . V_377 ) ||
F_26 ( V_51 , V_378 ,
V_7 -> V_18 . V_379 ) ||
F_26 ( V_51 , V_380 ,
V_7 -> V_18 . V_381 ) ||
F_54 ( V_51 , V_382 ,
V_7 -> V_18 . V_383 ) ||
F_54 ( V_51 , V_384 ,
V_7 -> V_18 . V_385 ) ||
F_54 ( V_51 , V_386 ,
V_7 -> V_18 . V_387 ) ||
F_53 ( V_51 , V_388 ,
V_7 -> V_18 . V_389 ) ||
F_53 ( V_51 , V_390 ,
V_7 -> V_18 . V_391 ) ||
F_54 ( V_51 , V_392 ,
V_7 -> V_18 . V_393 ) ||
F_26 ( V_51 , V_394 ,
V_7 -> V_18 . V_395 ) ||
F_26 ( V_51 , V_396 ,
V_7 -> V_18 . V_397 ) ||
F_26 ( V_51 , V_398 ,
V_7 -> V_18 . V_399 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_400 ) &&
F_27 ( V_51 , V_401 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_402 ) &&
F_27 ( V_51 , V_403 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_404 ) &&
F_27 ( V_51 , V_405 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_406 ) &&
F_27 ( V_51 , V_407 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_332 ) &&
F_27 ( V_51 , V_408 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_409 ) &&
F_27 ( V_51 , V_410 ) )
goto V_59;
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
case 1 :
if ( F_49 ( V_51 , V_412 ,
sizeof( V_22 ) * V_7 -> V_18 . V_413 ,
V_7 -> V_18 . V_414 ) )
goto V_59;
if ( F_54 ( V_51 , V_415 ,
V_7 -> V_18 . V_416 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_417 ) &&
F_27 ( V_51 , V_418 ) )
goto V_59;
if ( F_26 ( V_51 , V_419 ,
V_7 -> V_18 . V_420 ) ||
F_26 ( V_51 , V_421 ,
V_7 -> V_18 . V_422 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_423 ) &&
F_26 ( V_51 , V_424 ,
V_7 -> V_18 . V_425 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_420 ||
V_7 -> V_18 . V_422 ) &&
V_7 -> V_327 -> V_426 ) {
V_22 V_427 = 0 , V_428 = 0 ;
int V_429 ;
V_429 = F_63 ( V_7 , & V_427 , & V_428 ) ;
if ( ! V_429 ) {
if ( F_26 ( V_51 ,
V_430 ,
V_427 ) ||
F_26 ( V_51 ,
V_431 ,
V_428 ) )
goto V_59;
}
}
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
case 2 :
if ( F_44 ( V_51 , V_432 ,
V_7 -> V_18 . V_433 ) )
goto V_59;
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
case 3 :
V_360 = F_45 ( V_51 , V_434 ) ;
if ( ! V_360 )
goto V_59;
for ( V_366 = V_358 -> V_435 ;
V_366 < V_436 ; V_366 ++ ) {
struct V_241 * V_242 ;
V_242 = V_7 -> V_18 . V_437 [ V_366 ] ;
if ( ! V_242 )
continue;
V_361 = F_45 ( V_51 , V_366 ) ;
if ( ! V_361 )
goto V_59;
switch ( V_358 -> V_438 ) {
case 0 :
if ( F_52 ( V_51 , V_242 ) )
goto V_59;
V_358 -> V_438 ++ ;
if ( V_358 -> V_411 )
break;
default:
V_362 = F_45 (
V_51 , V_439 ) ;
if ( ! V_362 )
goto V_59;
for ( V_159 = V_358 -> V_438 - 1 ;
V_159 < V_242 -> V_440 ;
V_159 ++ ) {
V_363 = F_45 ( V_51 , V_159 ) ;
if ( ! V_363 )
goto V_59;
V_53 = & V_242 -> V_441 [ V_159 ] ;
if ( F_25 (
V_51 , V_53 ,
V_358 -> V_411 ) )
goto V_59;
F_46 ( V_51 , V_363 ) ;
if ( V_358 -> V_411 )
break;
}
if ( V_159 < V_242 -> V_440 )
V_358 -> V_438 = V_159 + 2 ;
else
V_358 -> V_438 = 0 ;
F_46 ( V_51 , V_362 ) ;
}
F_46 ( V_51 , V_361 ) ;
if ( V_358 -> V_411 ) {
if ( V_358 -> V_438 )
V_366 -- ;
break;
}
}
F_46 ( V_51 , V_360 ) ;
if ( V_366 < V_436 )
V_358 -> V_435 = V_366 + 1 ;
else
V_358 -> V_435 = 0 ;
if ( V_358 -> V_435 == 0 && V_358 -> V_438 == 0 )
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
case 4 :
V_364 = F_45 ( V_51 , V_442 ) ;
if ( ! V_364 )
goto V_59;
V_159 = F_56 ( V_7 , V_51 ) ;
if ( V_159 < 0 )
goto V_59;
if ( V_358 -> V_411 ) {
F_57 ( V_443 , V_444 ) ;
F_57 ( V_445 , V_446 ) ;
if ( V_7 -> V_18 . V_49 & V_447 )
F_57 ( V_448 , V_449 ) ;
F_57 ( V_450 , V_451 ) ;
if ( V_7 -> V_18 . V_367 &
V_452 )
F_57 ( V_453 , V_454 ) ;
F_57 ( V_455 , V_456 ) ;
F_57 ( V_457 , V_458 ) ;
}
#undef F_57
F_46 ( V_51 , V_364 ) ;
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
case 5 :
if ( V_7 -> V_327 -> V_317 &&
( V_7 -> V_18 . V_49 & V_316 ) &&
F_26 ( V_51 ,
V_459 ,
V_7 -> V_18 . V_460 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_461 ) &&
F_27 ( V_51 , V_462 ) )
goto V_59;
if ( F_55 ( V_51 , V_270 ) )
goto V_59;
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
case 6 :
#ifdef F_64
if ( F_50 ( V_51 , V_7 , V_358 -> V_411 ) )
goto V_59;
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
#else
V_358 -> V_373 ++ ;
#endif
case 7 :
if ( F_44 ( V_51 , V_463 ,
V_7 -> V_18 . V_464 ) )
goto V_59;
if ( F_47 ( & V_7 -> V_18 , V_51 ,
V_358 -> V_411 ) )
goto V_59;
V_358 -> V_373 ++ ;
if ( V_358 -> V_411 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_49 & V_465 ) &&
F_26 ( V_51 , V_466 ,
V_7 -> V_18 . V_467 ) )
goto V_59;
V_367 = V_7 -> V_18 . V_367 ;
if ( V_358 -> V_411 )
V_367 |= V_468 ;
if ( F_26 ( V_51 , V_469 , V_367 ) )
goto V_59;
if ( V_7 -> V_18 . V_470 &&
F_49 ( V_51 , V_471 ,
sizeof( * V_7 -> V_18 . V_470 ) ,
V_7 -> V_18 . V_470 ) )
goto V_59;
if ( V_7 -> V_18 . V_49 & V_465 &&
V_7 -> V_18 . V_472 &&
F_26 ( V_51 , V_473 ,
V_7 -> V_18 . V_472 ) )
goto V_59;
V_358 -> V_373 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_474 &&
( F_49 ( V_51 , V_475 ,
V_7 -> V_18 . V_476 ,
V_7 -> V_18 . V_474 ) ||
F_49 ( V_51 , V_477 ,
V_7 -> V_18 . V_476 ,
V_7 -> V_18 . V_478 ) ) )
goto V_59;
if ( V_7 -> V_18 . V_479 &&
F_49 ( V_51 , V_480 ,
sizeof( * V_7 -> V_18 . V_479 ) ,
V_7 -> V_18 . V_479 ) )
goto V_59;
V_358 -> V_373 ++ ;
break;
case 10 :
if ( F_51 ( V_51 , V_7 ) )
goto V_59;
if ( ( V_7 -> V_18 . V_49 & V_481 ) &&
( F_27 ( V_51 , V_482 ) ||
F_27 ( V_51 , V_483 ) ) )
goto V_59;
if ( V_7 -> V_18 . V_484 &&
F_26 ( V_51 , V_485 ,
V_7 -> V_18 . V_484 ) )
goto V_59;
V_358 -> V_373 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_486 ) {
const struct V_487 * V_30 ;
struct V_4 * V_488 ;
V_488 = F_45 ( V_51 , V_489 ) ;
if ( ! V_488 )
goto V_59;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_486 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_490 [ V_159 ] . V_30 ;
if ( F_49 ( V_51 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_46 ( V_51 , V_488 ) ;
}
if ( V_7 -> V_18 . V_491 ) {
const struct V_487 * V_30 ;
struct V_4 * V_488 ;
V_488 = F_45 ( V_51 ,
V_492 ) ;
if ( ! V_488 )
goto V_59;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_491 ; V_159 ++ ) {
V_30 = & V_7 -> V_18 . V_493 [ V_159 ] ;
if ( F_49 ( V_51 , V_159 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_46 ( V_51 , V_488 ) ;
}
V_358 -> V_373 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_49 & V_447 &&
F_54 ( V_51 , V_494 ,
V_7 -> V_18 . V_495 ) )
goto V_59;
if ( V_7 -> V_18 . V_496 & V_497 &&
F_27 ( V_51 , V_498 ) )
goto V_59;
if ( F_49 ( V_51 , V_499 ,
sizeof( V_7 -> V_18 . V_500 ) ,
V_7 -> V_18 . V_500 ) )
goto V_59;
if ( V_7 -> V_18 . V_501 ) {
struct V_4 * V_488 ;
V_22 V_501 = V_7 -> V_18 . V_501 ;
V_488 = F_45 ( V_51 , V_502 ) ;
if ( ! V_488 )
goto V_59;
V_159 = 0 ;
while ( V_501 ) {
if ( ( V_501 & 1 ) &&
F_27 ( V_51 , V_159 ) )
goto V_59;
V_159 ++ ;
V_501 >>= 1 ;
}
F_46 ( V_51 , V_488 ) ;
}
V_358 -> V_373 ++ ;
break;
case 13 :
if ( V_7 -> V_18 . V_503 &&
V_7 -> V_18 . V_504 ) {
struct V_4 * V_505 , * V_488 ;
V_488 = F_45 ( V_51 ,
V_506 ) ;
if ( ! V_488 )
goto V_59;
for ( V_159 = V_358 -> V_507 ;
V_159 < V_7 -> V_18 . V_503 ; V_159 ++ ) {
const struct V_508 * V_509 ;
V_509 = & V_7 -> V_18 . V_504 [ V_159 ] ;
V_505 = F_45 ( V_51 , V_159 ) ;
if ( ! V_505 ||
F_26 ( V_51 , V_510 ,
V_509 -> V_140 ) ||
F_49 ( V_51 , V_475 ,
V_509 -> V_476 ,
V_509 -> V_474 ) ||
F_49 ( V_51 , V_477 ,
V_509 -> V_476 ,
V_509 -> V_478 ) )
goto V_59;
F_46 ( V_51 , V_505 ) ;
if ( V_358 -> V_411 )
break;
}
F_46 ( V_51 , V_488 ) ;
if ( V_159 < V_7 -> V_18 . V_503 ) {
V_358 -> V_507 = V_159 + 1 ;
break;
}
}
if ( F_26 ( V_51 , V_511 ,
V_7 -> V_18 . V_512 ) )
goto V_59;
V_358 -> V_373 = 0 ;
break;
}
V_372:
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int F_67 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_357 * V_358 )
{
struct V_4 * * V_93 = F_15 ( & V_38 ) ;
int V_514 = F_14 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_93 , V_38 . V_40 , V_41 ) ;
if ( V_514 )
return 0 ;
V_358 -> V_411 = V_93 [ V_515 ] ;
if ( V_93 [ V_26 ] )
V_358 -> V_516 = F_4 ( V_93 [ V_26 ] ) ;
if ( V_93 [ V_12 ] )
V_358 -> V_516 = F_5 ( V_93 [ V_12 ] ) >> 32 ;
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
V_358 -> V_516 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_68 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_103 = 0 , V_514 ;
struct V_357 * V_358 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_69 () ;
if ( ! V_358 ) {
V_358 = F_37 ( sizeof( * V_358 ) , V_134 ) ;
if ( ! V_358 ) {
F_70 () ;
return - V_135 ;
}
V_358 -> V_516 = - 1 ;
V_514 = F_67 ( V_32 , V_34 , V_358 ) ;
if ( V_514 ) {
F_39 ( V_358 ) ;
F_70 () ;
return V_514 ;
}
V_34 -> args [ 0 ] = ( long ) V_358 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_42 ) ) )
continue;
if ( ++ V_103 <= V_358 -> V_517 )
continue;
if ( V_358 -> V_516 != - 1 &&
V_358 -> V_516 != V_7 -> V_14 )
continue;
do {
V_514 = F_59 ( V_7 , V_371 ,
V_32 ,
F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 ,
V_519 , V_358 ) ;
if ( V_514 < 0 ) {
if ( ( V_514 == - V_89 || V_514 == - V_513 ) &&
! V_32 -> V_45 && ! V_358 -> V_411 &&
V_34 -> V_520 < 4096 ) {
V_34 -> V_520 = 4096 ;
V_358 -> V_373 = 0 ;
F_70 () ;
return 1 ;
}
V_103 -- ;
break;
}
} while ( V_358 -> V_373 > 0 );
break;
}
F_70 () ;
V_358 -> V_517 = V_103 ;
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
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_357 V_358 = {} ;
V_51 = F_75 ( 4096 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
if ( F_59 ( V_7 , V_371 , V_51 ,
V_30 -> V_522 , V_30 -> V_523 , 0 ,
& V_358 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_78 ( struct V_4 * V_93 [] ,
struct V_524 * V_525 )
{
if ( ! V_93 [ V_526 ] || ! V_93 [ V_527 ] ||
! V_93 [ V_528 ] || ! V_93 [ V_529 ] ||
! V_93 [ V_530 ] )
return - V_16 ;
V_525 -> V_531 = F_32 ( V_93 [ V_526 ] ) ;
V_525 -> V_532 = F_79 ( V_93 [ V_527 ] ) ;
V_525 -> V_533 = F_79 ( V_93 [ V_528 ] ) ;
V_525 -> V_534 = F_79 ( V_93 [ V_529 ] ) ;
V_525 -> V_535 = F_32 ( V_93 [ V_530 ] ) ;
if ( V_525 -> V_531 >= V_536 )
return - V_16 ;
return 0 ;
}
static bool F_80 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_140 == V_141 ||
V_17 -> V_140 == V_144 ||
V_17 -> V_140 == V_152 ||
V_17 -> V_140 == V_143 ;
}
static int F_81 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_537 * V_538 )
{
V_22 V_539 ;
if ( ! V_30 -> V_5 [ V_540 ] )
return - V_16 ;
V_539 = F_4 ( V_30 -> V_5 [ V_540 ] ) ;
V_538 -> V_53 = F_43 ( & V_7 -> V_18 , V_539 ) ;
V_538 -> V_541 = V_542 ;
V_538 -> V_543 = V_539 ;
V_538 -> V_544 = 0 ;
if ( ! V_538 -> V_53 || V_538 -> V_53 -> V_49 & V_60 )
return - V_16 ;
if ( V_30 -> V_5 [ V_545 ] ) {
enum V_546 V_547 ;
V_547 = F_4 (
V_30 -> V_5 [ V_545 ] ) ;
switch ( V_547 ) {
case V_548 :
case V_549 :
case V_550 :
case V_551 :
F_82 ( V_538 , V_538 -> V_53 ,
V_547 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_552 ] ) {
V_538 -> V_541 =
F_4 ( V_30 -> V_5 [ V_552 ] ) ;
if ( V_30 -> V_5 [ V_553 ] )
V_538 -> V_543 =
F_4 (
V_30 -> V_5 [ V_553 ] ) ;
if ( V_30 -> V_5 [ V_554 ] )
V_538 -> V_544 =
F_4 (
V_30 -> V_5 [ V_554 ] ) ;
}
if ( ! F_83 ( V_538 ) )
return - V_16 ;
if ( ! F_84 ( & V_7 -> V_18 , V_538 ,
V_60 ) )
return - V_16 ;
if ( ( V_538 -> V_541 == V_555 ||
V_538 -> V_541 == V_556 ) &&
! ( V_7 -> V_18 . V_49 & V_481 ) )
return - V_16 ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 ,
struct V_25 * V_557 ,
struct V_29 * V_30 )
{
struct V_537 V_538 ;
int V_8 ;
enum V_274 V_140 = V_152 ;
struct V_1 * V_17 = NULL ;
if ( V_557 )
V_17 = V_557 -> V_28 ;
if ( ! F_80 ( V_17 ) )
return - V_558 ;
if ( V_17 )
V_140 = V_17 -> V_140 ;
V_8 = F_81 ( V_7 , V_30 , & V_538 ) ;
if ( V_8 )
return V_8 ;
switch ( V_140 ) {
case V_141 :
case V_143 :
if ( ! F_86 ( & V_7 -> V_18 , & V_538 ,
V_140 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_559 ) {
if ( ! V_557 || ! V_7 -> V_327 -> V_560 ||
! ( V_7 -> V_18 . V_367 &
V_561 ) ) {
V_8 = - V_562 ;
break;
}
if ( V_538 . V_53 != V_17 -> V_563 . V_53 ) {
V_8 = - V_562 ;
break;
}
V_8 = F_87 ( V_7 , V_557 , & V_538 ) ;
if ( V_8 )
break;
}
V_17 -> V_563 = V_538 ;
V_8 = 0 ;
break;
case V_144 :
V_8 = F_88 ( V_7 , V_17 , & V_538 ) ;
break;
case V_152 :
V_8 = F_89 ( V_7 , & V_538 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_521 [ 1 ] ;
return F_85 ( V_7 , V_19 , V_30 ) ;
}
static int F_91 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
const T_2 * V_564 ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( F_92 ( V_557 ) )
return - V_562 ;
if ( ! V_7 -> V_327 -> V_330 )
return - V_558 ;
if ( V_17 -> V_140 != V_155 )
return - V_558 ;
V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
return F_93 ( V_7 , V_557 , V_564 ) ;
}
static int F_94 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_566 = 0 ;
struct V_4 * V_567 ;
V_22 V_568 ;
T_2 V_375 = 0 , V_377 = 0 ;
V_22 V_379 = 0 , V_381 = 0 ;
T_2 V_383 = 0 ;
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
if ( V_30 -> V_5 [ V_368 ] )
V_8 = F_96 (
V_7 , F_21 ( V_30 -> V_5 [ V_368 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_569 ] ) {
struct V_524 V_525 ;
struct V_4 * V_93 [ V_570 + 1 ] ;
if ( ! V_7 -> V_327 -> V_571 )
return - V_558 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_140 != V_141 &&
V_19 -> V_28 -> V_140 != V_143 )
return - V_16 ;
if ( ! F_92 ( V_19 ) )
return - V_572 ;
F_36 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_31 ( V_93 , V_570 ,
V_567 ,
V_573 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_78 ( V_93 , & V_525 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_525 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_540 ] ) {
V_8 = F_85 (
V_7 ,
F_80 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_574 ] ) {
struct V_1 * V_575 = V_17 ;
enum V_576 type ;
int V_103 , V_577 = 0 ;
if ( ! ( V_7 -> V_18 . V_367 & V_578 ) )
V_575 = NULL ;
if ( ! V_7 -> V_327 -> V_579 )
return - V_558 ;
V_103 = V_574 ;
type = F_4 ( V_30 -> V_5 [ V_103 ] ) ;
if ( ! V_30 -> V_5 [ V_580 ] &&
( type != V_581 ) )
return - V_16 ;
if ( type != V_581 ) {
V_103 = V_580 ;
V_577 = F_4 ( V_30 -> V_5 [ V_103 ] ) ;
}
V_8 = F_98 ( V_7 , V_575 , type , V_577 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_430 ] &&
V_30 -> V_5 [ V_431 ] ) {
V_22 V_427 , V_428 ;
if ( ( ! V_7 -> V_18 . V_420 &&
! V_7 -> V_18 . V_422 ) ||
! V_7 -> V_327 -> V_582 )
return - V_558 ;
V_427 = F_4 ( V_30 -> V_5 [ V_430 ] ) ;
V_428 = F_4 ( V_30 -> V_5 [ V_431 ] ) ;
if ( ( ~ V_427 && ( V_427 & ~ V_7 -> V_18 . V_420 ) ) ||
( ~ V_428 && ( V_428 & ~ V_7 -> V_18 . V_422 ) ) )
return - V_16 ;
V_427 = V_427 & V_7 -> V_18 . V_420 ;
V_428 = V_428 & V_7 -> V_18 . V_422 ;
V_8 = F_99 ( V_7 , V_427 , V_428 ) ;
if ( V_8 )
return V_8 ;
}
V_568 = 0 ;
if ( V_30 -> V_5 [ V_374 ] ) {
V_375 = F_32 (
V_30 -> V_5 [ V_374 ] ) ;
if ( V_375 == 0 )
return - V_16 ;
V_568 |= V_583 ;
}
if ( V_30 -> V_5 [ V_376 ] ) {
V_377 = F_32 (
V_30 -> V_5 [ V_376 ] ) ;
if ( V_377 == 0 )
return - V_16 ;
V_568 |= V_584 ;
}
if ( V_30 -> V_5 [ V_378 ] ) {
V_379 = F_4 (
V_30 -> V_5 [ V_378 ] ) ;
if ( V_379 < 256 )
return - V_16 ;
if ( V_379 != ( V_22 ) - 1 ) {
V_379 &= ~ 0x1 ;
}
V_568 |= V_585 ;
}
if ( V_30 -> V_5 [ V_380 ] ) {
V_381 = F_4 (
V_30 -> V_5 [ V_380 ] ) ;
V_568 |= V_586 ;
}
if ( V_30 -> V_5 [ V_382 ] ) {
if ( V_30 -> V_5 [ V_587 ] )
return - V_16 ;
V_383 = F_32 (
V_30 -> V_5 [ V_382 ] ) ;
V_568 |= V_588 ;
}
if ( V_30 -> V_5 [ V_587 ] ) {
if ( ! ( V_7 -> V_18 . V_367 & V_589 ) )
return - V_558 ;
V_568 |= V_590 ;
}
if ( V_568 ) {
T_2 V_591 , V_592 ;
V_22 V_593 , V_594 ;
T_2 V_595 ;
if ( ! V_7 -> V_327 -> V_596 )
return - V_558 ;
V_591 = V_7 -> V_18 . V_375 ;
V_592 = V_7 -> V_18 . V_377 ;
V_593 = V_7 -> V_18 . V_379 ;
V_594 = V_7 -> V_18 . V_381 ;
V_595 = V_7 -> V_18 . V_383 ;
if ( V_568 & V_583 )
V_7 -> V_18 . V_375 = V_375 ;
if ( V_568 & V_584 )
V_7 -> V_18 . V_377 = V_377 ;
if ( V_568 & V_585 )
V_7 -> V_18 . V_379 = V_379 ;
if ( V_568 & V_586 )
V_7 -> V_18 . V_381 = V_381 ;
if ( V_568 & V_588 )
V_7 -> V_18 . V_383 = V_383 ;
V_8 = F_100 ( V_7 , V_568 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_375 = V_591 ;
V_7 -> V_18 . V_377 = V_592 ;
V_7 -> V_18 . V_379 = V_593 ;
V_7 -> V_18 . V_381 = V_594 ;
V_7 -> V_18 . V_383 = V_595 ;
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
const struct V_537 * V_538 )
{
if ( F_60 ( ! F_83 ( V_538 ) ) )
return - V_16 ;
if ( F_26 ( V_51 , V_540 ,
V_538 -> V_53 -> V_58 ) )
return - V_89 ;
switch ( V_538 -> V_541 ) {
case V_542 :
case V_597 :
case V_598 :
if ( F_26 ( V_51 , V_545 ,
F_102 ( V_538 ) ) )
return - V_89 ;
break;
default:
break;
}
if ( F_26 ( V_51 , V_552 , V_538 -> V_541 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_553 , V_538 -> V_543 ) )
return - V_89 ;
if ( V_538 -> V_544 &&
F_26 ( V_51 , V_554 , V_538 -> V_544 ) )
return - V_89 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_51 , V_22 V_47 , V_22 V_48 , int V_49 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_599 )
{
struct V_25 * V_557 = V_17 -> V_19 ;
T_2 V_50 = V_600 ;
void * V_359 ;
if ( V_599 )
V_50 = V_601 ;
V_359 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_359 )
return - 1 ;
if ( V_557 &&
( F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_61 ( V_51 , V_602 , V_557 -> V_603 ) ) )
goto V_59;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_510 , V_17 -> V_140 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) ||
F_49 ( V_51 , V_565 , V_605 , F_105 ( V_17 ) ) ||
F_26 ( V_51 , V_369 ,
V_7 -> V_606 ^
( V_370 << 2 ) ) )
goto V_59;
if ( V_7 -> V_327 -> V_607 ) {
int V_514 ;
struct V_537 V_538 ;
V_514 = F_106 ( V_7 , V_17 , & V_538 ) ;
if ( V_514 == 0 ) {
if ( F_101 ( V_51 , & V_538 ) )
goto V_59;
}
}
if ( V_7 -> V_327 -> V_608 ) {
int V_609 , V_514 ;
V_514 = F_107 ( V_7 , V_17 , & V_609 ) ;
if ( V_514 == 0 &&
F_26 ( V_51 , V_580 ,
F_29 ( V_609 ) ) )
goto V_59;
}
if ( V_17 -> V_610 ) {
if ( F_49 ( V_51 , V_611 , V_17 -> V_610 , V_17 -> V_612 ) )
goto V_59;
}
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_613 = 0 ;
int V_614 = 0 ;
int V_615 = V_34 -> args [ 0 ] ;
int V_616 = V_34 -> args [ 1 ] ;
int V_516 = - 1 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_514 ;
F_69 () ;
if ( ! V_34 -> args [ 2 ] ) {
struct V_357 V_358 = {
. V_516 = - 1 ,
} ;
V_514 = F_67 ( V_32 , V_34 , & V_358 ) ;
if ( V_514 )
goto V_617;
V_516 = V_358 . V_516 ;
if ( V_516 >= 0 )
V_34 -> args [ 2 ] = V_516 + 1 ;
else
V_34 -> args [ 2 ] = - 1 ;
} else if ( V_34 -> args [ 2 ] > 0 ) {
V_516 = V_34 -> args [ 2 ] - 1 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_42 ) ) )
continue;
if ( V_613 < V_615 ) {
V_613 ++ ;
continue;
}
if ( V_516 >= 0 && V_516 != V_7 -> V_14 )
continue;
V_614 = 0 ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_614 < V_616 ) {
V_614 ++ ;
continue;
}
if ( F_103 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_7 , V_17 , false ) < 0 ) {
goto V_618;
}
V_614 ++ ;
}
V_613 ++ ;
}
V_618:
V_34 -> args [ 0 ] = V_613 ;
V_34 -> args [ 1 ] = V_614 ;
V_514 = V_32 -> V_45 ;
V_617:
F_70 () ;
return V_514 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_51 ;
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
if ( F_103 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_110 ( struct V_4 * V_620 , V_22 * V_621 )
{
struct V_4 * V_49 [ V_622 + 1 ] ;
int V_623 ;
* V_621 = 0 ;
if ( ! V_620 )
return - V_16 ;
if ( F_31 ( V_49 , V_622 ,
V_620 , V_624 ) )
return - V_16 ;
for ( V_623 = 1 ; V_623 <= V_622 ; V_623 ++ )
if ( V_49 [ V_623 ] )
* V_621 |= ( 1 << V_623 ) ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_625 ,
enum V_274 V_140 )
{
if ( ! V_625 ) {
if ( V_19 && ( V_19 -> V_626 & V_627 ) )
return - V_562 ;
return 0 ;
}
switch ( V_140 ) {
case V_142 :
if ( V_7 -> V_18 . V_49 & V_628 )
return 0 ;
break;
case V_146 :
if ( V_7 -> V_18 . V_49 & V_629 )
return 0 ;
break;
default:
break;
}
return - V_558 ;
}
static int F_112 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_630 V_138 ;
int V_35 ;
enum V_274 V_631 , V_632 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
V_22 V_633 , * V_49 = NULL ;
bool V_634 = false ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_631 = V_632 = V_557 -> V_28 -> V_140 ;
if ( V_30 -> V_5 [ V_510 ] ) {
V_632 = F_4 ( V_30 -> V_5 [ V_510 ] ) ;
if ( V_631 != V_632 )
V_634 = true ;
if ( V_632 > V_635 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_636 ] ) {
struct V_1 * V_17 = V_557 -> V_28 ;
if ( V_632 != V_144 )
return - V_16 ;
if ( F_92 ( V_557 ) )
return - V_562 ;
F_113 ( V_17 ) ;
F_114 ( V_637 !=
V_638 ) ;
V_17 -> V_639 =
F_22 ( V_30 -> V_5 [ V_636 ] ) ;
memcpy ( V_17 -> V_612 , F_21 ( V_30 -> V_5 [ V_636 ] ) ,
V_17 -> V_639 ) ;
F_115 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_640 ] ) {
V_138 . V_625 = ! ! F_32 ( V_30 -> V_5 [ V_640 ] ) ;
V_634 = true ;
V_35 = F_111 ( V_7 , V_557 , V_138 . V_625 , V_632 ) ;
if ( V_35 )
return V_35 ;
} else {
V_138 . V_625 = - 1 ;
}
if ( V_30 -> V_5 [ V_641 ] ) {
if ( V_632 != V_152 )
return - V_16 ;
V_35 = F_110 ( V_30 -> V_5 [ V_641 ] ,
& V_633 ) ;
if ( V_35 )
return V_35 ;
V_49 = & V_633 ;
V_634 = true ;
}
if ( V_30 -> V_5 [ V_642 ] ) {
const T_2 * V_643 ;
V_22 V_644 = V_645 ;
if ( ! F_116 ( & V_7 -> V_18 , V_644 ) )
return - V_558 ;
V_643 =
F_21 ( V_30 -> V_5 [ V_642 ] ) ;
if ( ( V_643 [ 0 ] & F_117 ( 7 ) ) ||
( V_643 [ V_646 - 1 ] & F_117 ( 0 ) ) )
return - V_16 ;
memcpy ( V_138 . V_647 , V_643 ,
V_646 ) ;
V_634 = true ;
}
if ( V_30 -> V_5 [ V_648 ] ) {
V_22 V_644 = V_645 ;
if ( ! F_116 ( & V_7 -> V_18 , V_644 ) )
return - V_558 ;
F_118 ( V_138 . V_649 ,
V_30 -> V_5 [ V_648 ] ,
V_605 ) ;
V_634 = true ;
}
if ( V_49 && ( * V_49 & V_650 ) &&
! ( V_7 -> V_18 . V_367 & V_651 ) )
return - V_558 ;
if ( V_634 )
V_35 = F_119 ( V_7 , V_557 , V_632 , V_49 , & V_138 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_138 . V_625 != - 1 )
V_557 -> V_28 -> V_625 = V_138 . V_625 ;
return V_35 ;
}
static int F_120 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_630 V_138 ;
struct V_1 * V_17 ;
struct V_31 * V_51 ;
int V_35 ;
enum V_274 type = V_150 ;
V_22 V_49 ;
F_121 ( V_7 ) ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
if ( ! V_30 -> V_5 [ V_602 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_510 ] ) {
type = F_4 ( V_30 -> V_5 [ V_510 ] ) ;
if ( type > V_635 )
return - V_16 ;
}
if ( ! V_7 -> V_327 -> V_282 ||
! ( V_7 -> V_18 . V_433 & ( 1 << type ) ) )
return - V_558 ;
if ( ( type == V_154 || type == V_153 ||
V_7 -> V_18 . V_367 & V_652 ) &&
V_30 -> V_5 [ V_565 ] ) {
F_118 ( V_138 . V_649 , V_30 -> V_5 [ V_565 ] ,
V_605 ) ;
if ( ! F_122 ( V_138 . V_649 ) )
return - V_653 ;
}
if ( V_30 -> V_5 [ V_640 ] ) {
V_138 . V_625 = ! ! F_32 ( V_30 -> V_5 [ V_640 ] ) ;
V_35 = F_111 ( V_7 , NULL , V_138 . V_625 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_110 ( type == V_152 ?
V_30 -> V_5 [ V_641 ] : NULL ,
& V_49 ) ;
if ( ! V_35 && ( V_49 & V_650 ) &&
! ( V_7 -> V_18 . V_367 & V_651 ) )
return - V_558 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_17 = F_123 ( V_7 ,
F_21 ( V_30 -> V_5 [ V_602 ] ) ,
V_654 , type , V_35 ? NULL : & V_49 ,
& V_138 ) ;
if ( F_60 ( ! V_17 ) ) {
F_76 ( V_51 ) ;
return - V_655 ;
} else if ( F_17 ( V_17 ) ) {
F_76 ( V_51 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_656 ] )
V_17 -> V_657 = V_30 -> V_522 ;
switch ( type ) {
case V_144 :
if ( ! V_30 -> V_5 [ V_636 ] )
break;
F_113 ( V_17 ) ;
F_114 ( V_637 !=
V_638 ) ;
V_17 -> V_639 =
F_22 ( V_30 -> V_5 [ V_636 ] ) ;
memcpy ( V_17 -> V_612 , F_21 ( V_30 -> V_5 [ V_636 ] ) ,
V_17 -> V_639 ) ;
F_115 ( V_17 ) ;
break;
case V_153 :
case V_154 :
F_124 ( & V_17 -> V_658 ) ;
F_125 ( & V_17 -> V_659 ) ;
F_126 ( & V_17 -> V_660 ) ;
F_125 ( & V_17 -> V_661 ) ;
F_126 ( & V_17 -> V_662 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_127 ( & V_17 -> V_663 , & V_7 -> V_18 . V_664 ) ;
V_7 -> V_606 ++ ;
break;
default:
break;
}
if ( F_103 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
if ( ! V_17 -> V_19 )
F_128 ( V_7 , V_17 , V_600 ) ;
return F_77 ( V_51 , V_30 ) ;
}
static int F_129 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
if ( ! V_7 -> V_327 -> V_665 )
return - V_558 ;
if ( ! V_17 -> V_19 )
V_30 -> V_521 [ 1 ] = NULL ;
return F_130 ( V_7 , V_17 ) ;
}
static int F_131 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_3 V_666 ;
if ( ! V_30 -> V_5 [ V_667 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_342 )
return - V_558 ;
V_666 = F_79 ( V_30 -> V_5 [ V_667 ] ) ;
return F_132 ( V_7 , V_557 , V_666 ) ;
}
static void F_133 ( void * V_165 , struct V_668 * V_138 )
{
struct V_4 * V_90 ;
struct V_669 * V_670 = V_165 ;
if ( ( V_138 -> V_90 &&
F_49 ( V_670 -> V_51 , V_119 ,
V_138 -> V_106 , V_138 -> V_90 ) ) ||
( V_138 -> V_48 &&
F_49 ( V_670 -> V_51 , V_120 ,
V_138 -> V_108 , V_138 -> V_48 ) ) ||
( V_138 -> V_110 &&
F_26 ( V_670 -> V_51 , V_122 ,
V_138 -> V_110 ) ) )
goto V_59;
V_90 = F_45 ( V_670 -> V_51 , V_127 ) ;
if ( ! V_90 )
goto V_59;
if ( ( V_138 -> V_90 &&
F_49 ( V_670 -> V_51 , V_104 ,
V_138 -> V_106 , V_138 -> V_90 ) ) ||
( V_138 -> V_48 &&
F_49 ( V_670 -> V_51 , V_107 ,
V_138 -> V_108 , V_138 -> V_48 ) ) ||
( V_138 -> V_110 &&
F_26 ( V_670 -> V_51 , V_109 ,
V_138 -> V_110 ) ) )
goto V_59;
if ( F_54 ( V_670 -> V_51 , V_121 , V_670 -> V_103 ) )
goto V_59;
F_46 ( V_670 -> V_51 , V_90 ) ;
return;
V_59:
V_670 -> error = 1 ;
}
static int F_134 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int V_35 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 V_671 = 0 ;
const T_2 * V_672 = NULL ;
bool V_673 ;
struct V_669 V_670 = {
. error = 0 ,
} ;
void * V_359 ;
struct V_31 * V_51 ;
if ( V_30 -> V_5 [ V_121 ] )
V_671 = F_32 ( V_30 -> V_5 [ V_121 ] ) ;
if ( V_671 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_565 ] )
V_672 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_673 = ! ! V_672 ;
if ( V_30 -> V_5 [ V_125 ] ) {
V_22 V_674 = F_4 ( V_30 -> V_5 [ V_125 ] ) ;
if ( V_674 >= V_112 )
return - V_16 ;
if ( V_674 != V_675 &&
V_674 != V_676 )
return - V_16 ;
V_673 = V_674 == V_676 ;
}
if ( ! V_7 -> V_327 -> V_677 )
return - V_558 ;
if ( ! V_673 && V_672 && ! ( V_7 -> V_18 . V_49 & V_400 ) )
return - V_678 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_679 ) ;
if ( ! V_359 )
goto V_59;
V_670 . V_51 = V_51 ;
V_670 . V_103 = V_671 ;
if ( F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_54 ( V_51 , V_121 , V_671 ) )
goto V_59;
if ( V_672 &&
F_49 ( V_51 , V_565 , V_605 , V_672 ) )
goto V_59;
V_35 = F_135 ( V_7 , V_557 , V_671 , V_673 , V_672 , & V_670 ,
F_133 ) ;
if ( V_35 )
goto V_680;
if ( V_670 . error )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_680:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_136 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_91 V_90 ;
int V_35 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( V_90 . V_103 < 0 )
return - V_16 ;
if ( ! V_90 . V_96 && ! V_90 . V_98 )
return - V_16 ;
F_113 ( V_557 -> V_28 ) ;
if ( V_90 . V_96 ) {
if ( ! V_7 -> V_327 -> V_681 ) {
V_35 = - V_558 ;
goto V_618;
}
V_35 = F_40 ( V_557 -> V_28 ) ;
if ( V_35 )
goto V_618;
V_35 = F_137 ( V_7 , V_557 , V_90 . V_103 ,
V_90 . V_100 , V_90 . V_101 ) ;
if ( V_35 )
goto V_618;
#ifdef F_138
V_557 -> V_28 -> V_682 . V_683 = V_90 . V_103 ;
#endif
} else {
if ( V_90 . V_100 || ! V_90 . V_101 ) {
V_35 = - V_16 ;
goto V_618;
}
if ( ! V_7 -> V_327 -> V_684 ) {
V_35 = - V_558 ;
goto V_618;
}
V_35 = F_40 ( V_557 -> V_28 ) ;
if ( V_35 )
goto V_618;
V_35 = F_139 ( V_7 , V_557 , V_90 . V_103 ) ;
if ( V_35 )
goto V_618;
#ifdef F_138
V_557 -> V_28 -> V_682 . V_685 = V_90 . V_103 ;
#endif
}
V_618:
F_115 ( V_557 -> V_28 ) ;
return V_35 ;
}
static int F_140 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int V_35 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_91 V_90 ;
const T_2 * V_672 = NULL ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_90 . V_105 . V_90 )
return - V_16 ;
if ( V_30 -> V_5 [ V_565 ] )
V_672 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( V_90 . type == - 1 ) {
if ( V_672 )
V_90 . type = V_676 ;
else
V_90 . type = V_675 ;
}
if ( V_90 . type != V_676 &&
V_90 . type != V_675 )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_286 )
return - V_558 ;
if ( F_38 ( V_7 , & V_90 . V_105 , V_90 . V_103 ,
V_90 . type == V_676 ,
V_672 ) )
return - V_16 ;
F_113 ( V_557 -> V_28 ) ;
V_35 = F_40 ( V_557 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_141 ( V_7 , V_557 , V_90 . V_103 ,
V_90 . type == V_676 ,
V_672 , & V_90 . V_105 ) ;
F_115 ( V_557 -> V_28 ) ;
return V_35 ;
}
static int F_142 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int V_35 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 * V_672 = NULL ;
struct V_91 V_90 ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_565 ] )
V_672 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( V_90 . type == - 1 ) {
if ( V_672 )
V_90 . type = V_676 ;
else
V_90 . type = V_675 ;
}
if ( V_90 . type != V_676 &&
V_90 . type != V_675 )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_686 )
return - V_558 ;
F_113 ( V_557 -> V_28 ) ;
V_35 = F_40 ( V_557 -> V_28 ) ;
if ( V_90 . type == V_675 && V_672 &&
! ( V_7 -> V_18 . V_49 & V_400 ) )
V_35 = - V_678 ;
if ( ! V_35 )
V_35 = F_143 ( V_7 , V_557 , V_90 . V_103 ,
V_90 . type == V_676 ,
V_672 ) ;
#ifdef F_138
if ( ! V_35 ) {
if ( V_90 . V_103 == V_557 -> V_28 -> V_682 . V_683 )
V_557 -> V_28 -> V_682 . V_683 = - 1 ;
else if ( V_90 . V_103 == V_557 -> V_28 -> V_682 . V_685 )
V_557 -> V_28 -> V_682 . V_685 = - 1 ;
}
#endif
F_115 ( V_557 -> V_28 ) ;
return V_35 ;
}
static int F_144 ( struct V_4 * V_687 )
{
struct V_4 * V_43 ;
int V_688 = 0 , V_24 ;
F_36 (attr, nl_attr, tmp) {
if ( F_22 ( V_43 ) != V_605 )
return - V_16 ;
V_688 ++ ;
}
return V_688 ;
}
static struct V_689 * F_145 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_690 V_691 ;
struct V_4 * V_43 ;
struct V_689 * V_692 ;
int V_159 = 0 , V_688 , V_24 ;
if ( ! V_18 -> V_472 )
return F_3 ( - V_558 ) ;
if ( ! V_30 -> V_5 [ V_693 ] )
return F_3 ( - V_16 ) ;
V_691 = F_4 ( V_30 -> V_5 [ V_693 ] ) ;
if ( V_691 != V_694 &&
V_691 != V_695 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_696 ] )
return F_3 ( - V_16 ) ;
V_688 = F_144 ( V_30 -> V_5 [ V_696 ] ) ;
if ( V_688 < 0 )
return F_3 ( V_688 ) ;
if ( V_688 > V_18 -> V_472 )
return F_3 ( - V_697 ) ;
V_692 = F_37 ( sizeof( * V_692 ) + ( sizeof( struct V_698 ) * V_688 ) ,
V_134 ) ;
if ( ! V_692 )
return F_3 ( - V_135 ) ;
F_36 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_692 -> V_699 [ V_159 ] . V_700 , F_21 ( V_43 ) , V_605 ) ;
V_159 ++ ;
}
V_692 -> V_701 = V_688 ;
V_692 -> V_691 = V_691 ;
return V_692 ;
}
static int F_146 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_689 * V_692 ;
int V_35 ;
if ( V_557 -> V_28 -> V_140 != V_141 &&
V_557 -> V_28 -> V_140 != V_143 )
return - V_558 ;
if ( ! V_557 -> V_28 -> V_559 )
return - V_16 ;
V_692 = F_145 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_692 ) )
return F_18 ( V_692 ) ;
V_35 = F_147 ( V_7 , V_557 , V_692 ) ;
F_39 ( V_692 ) ;
return V_35 ;
}
static V_22 F_148 ( struct V_241 * V_242 ,
T_2 * V_702 , T_2 V_703 )
{
T_2 V_159 ;
V_22 V_704 = 0 ;
for ( V_159 = 0 ; V_159 < V_703 ; V_159 ++ ) {
int V_246 = ( V_702 [ V_159 ] & 0x7f ) * 5 ;
int V_705 ;
for ( V_705 = 0 ; V_705 < V_242 -> V_263 ; V_705 ++ ) {
struct V_245 * V_706 =
& V_242 -> V_264 [ V_705 ] ;
if ( V_246 == V_706 -> V_266 ) {
V_704 |= 1 << V_705 ;
break;
}
}
if ( V_705 == V_242 -> V_263 )
return 0 ;
}
return V_704 ;
}
static bool F_149 ( struct V_241 * V_242 ,
T_2 * V_702 , T_2 V_703 ,
T_2 V_250 [ V_707 ] )
{
T_2 V_159 ;
memset ( V_250 , 0 , V_707 ) ;
for ( V_159 = 0 ; V_159 < V_703 ; V_159 ++ ) {
int V_705 , V_708 ;
V_705 = V_702 [ V_159 ] / 8 ;
V_708 = F_117 ( V_702 [ V_159 ] % 8 ) ;
if ( ( V_705 < 0 ) || ( V_705 >= V_707 ) )
return false ;
if ( V_242 -> V_247 . V_250 . V_709 [ V_705 ] & V_708 )
V_250 [ V_705 ] |= V_708 ;
else
return false ;
}
return true ;
}
static T_3 F_150 ( T_2 V_710 )
{
T_3 V_711 = 0 ;
switch ( V_710 ) {
case V_712 :
break;
case V_713 :
V_711 = 0x00FF ;
break;
case V_714 :
V_711 = 0x01FF ;
break;
case V_715 :
V_711 = 0x03FF ;
break;
default:
break;
}
return V_711 ;
}
static void F_151 ( T_3 V_710 ,
T_3 V_716 [ V_717 ] )
{
T_2 V_718 ;
for ( V_718 = 0 ; V_718 < V_717 ; V_718 ++ ) {
V_716 [ V_718 ] = F_150 ( V_710 & 0x03 ) ;
V_710 >>= 2 ;
}
}
static bool F_152 ( struct V_241 * V_242 ,
struct V_719 * V_720 ,
T_3 V_250 [ V_717 ] )
{
T_3 V_721 = F_153 ( V_242 -> V_257 . V_260 . V_721 ) ;
T_3 V_722 [ V_717 ] = {} ;
T_2 V_159 ;
if ( ! V_242 -> V_257 . V_258 )
return false ;
memset ( V_250 , 0 , sizeof( T_3 ) * V_717 ) ;
F_151 ( V_721 , V_722 ) ;
for ( V_159 = 0 ; V_159 < V_717 ; V_159 ++ ) {
if ( ( V_722 [ V_159 ] & V_720 -> V_250 [ V_159 ] ) == V_720 -> V_250 [ V_159 ] )
V_250 [ V_159 ] = V_720 -> V_250 [ V_159 ] ;
else
return false ;
}
return true ;
}
static int F_154 ( struct V_29 * V_30 ,
struct V_723 * V_704 )
{
struct V_4 * V_93 [ V_724 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int V_132 , V_159 ;
struct V_4 * V_725 ;
struct V_241 * V_242 ;
T_3 V_726 ;
memset ( V_704 , 0 , sizeof( * V_704 ) ) ;
for ( V_159 = 0 ; V_159 < V_436 ; V_159 ++ ) {
V_242 = V_7 -> V_18 . V_437 [ V_159 ] ;
if ( ! V_242 )
continue;
V_704 -> V_727 [ V_159 ] . V_728 = ( 1 << V_242 -> V_263 ) - 1 ;
memcpy ( V_704 -> V_727 [ V_159 ] . V_729 ,
V_242 -> V_247 . V_250 . V_709 ,
sizeof( V_704 -> V_727 [ V_159 ] . V_729 ) ) ;
if ( ! V_242 -> V_257 . V_258 )
continue;
V_726 = F_153 ( V_242 -> V_257 . V_260 . V_721 ) ;
F_151 ( V_726 , V_704 -> V_727 [ V_159 ] . V_260 ) ;
}
if ( ! V_30 -> V_5 [ V_730 ] )
goto V_618;
F_114 ( V_731 > V_707 * 8 ) ;
F_36 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_365 V_366 = F_155 ( V_725 ) ;
int V_35 ;
if ( V_366 < 0 || V_366 >= V_436 )
return - V_16 ;
V_242 = V_7 -> V_18 . V_437 [ V_366 ] ;
if ( V_242 == NULL )
return - V_16 ;
V_35 = F_31 ( V_93 , V_724 , V_725 ,
V_732 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_733 ] ) {
V_704 -> V_727 [ V_366 ] . V_728 = F_148 (
V_242 ,
F_21 ( V_93 [ V_733 ] ) ,
F_22 ( V_93 [ V_733 ] ) ) ;
if ( ( V_704 -> V_727 [ V_366 ] . V_728 == 0 ) &&
F_22 ( V_93 [ V_733 ] ) )
return - V_16 ;
}
if ( V_93 [ V_734 ] ) {
if ( ! F_149 (
V_242 ,
F_21 ( V_93 [ V_734 ] ) ,
F_22 ( V_93 [ V_734 ] ) ,
V_704 -> V_727 [ V_366 ] . V_729 ) )
return - V_16 ;
}
if ( V_93 [ V_735 ] ) {
if ( ! F_152 (
V_242 ,
F_21 ( V_93 [ V_735 ] ) ,
V_704 -> V_727 [ V_366 ] . V_260 ) )
return - V_16 ;
}
if ( V_93 [ V_736 ] ) {
V_704 -> V_727 [ V_366 ] . V_737 =
F_32 ( V_93 [ V_736 ] ) ;
if ( V_704 -> V_727 [ V_366 ] . V_737 > V_738 )
return - V_16 ;
}
if ( V_704 -> V_727 [ V_366 ] . V_728 == 0 ) {
if ( ! ( V_7 -> V_18 . V_437 [ V_366 ] -> V_247 . V_248 ||
V_7 -> V_18 . V_437 [ V_366 ] -> V_257 . V_258 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_707 ; V_159 ++ )
if ( V_704 -> V_727 [ V_366 ] . V_729 [ V_159 ] )
goto V_618;
for ( V_159 = 0 ; V_159 < V_717 ; V_159 ++ )
if ( V_704 -> V_727 [ V_366 ] . V_260 [ V_159 ] )
goto V_618;
return - V_16 ;
}
}
V_618:
return 0 ;
}
static int F_156 ( struct V_6 * V_7 ,
enum V_365 V_366 ,
struct V_723 * V_739 )
{
V_22 V_740 , V_741 , V_159 ;
V_22 V_246 = V_739 -> V_727 [ V_366 ] . V_728 ;
if ( F_157 ( V_246 ) > 1 )
return - V_16 ;
V_740 = 0 ;
for ( V_159 = 0 ; V_159 < V_707 ; V_159 ++ ) {
if ( F_158 ( V_739 -> V_727 [ V_366 ] . V_729 [ V_159 ] ) > 1 ) {
return - V_16 ;
} else if ( V_739 -> V_727 [ V_366 ] . V_729 [ V_159 ] ) {
V_740 ++ ;
if ( V_740 > 1 )
return - V_16 ;
}
if ( V_740 && V_246 )
return - V_16 ;
}
V_741 = 0 ;
for ( V_159 = 0 ; V_159 < V_717 ; V_159 ++ ) {
if ( F_159 ( V_739 -> V_727 [ V_366 ] . V_260 [ V_159 ] ) > 1 ) {
return - V_16 ;
} else if ( V_739 -> V_727 [ V_366 ] . V_260 [ V_159 ] ) {
V_741 ++ ;
if ( V_741 > 1 )
return - V_16 ;
}
if ( V_741 && V_246 )
return - V_16 ;
}
if ( ( V_740 && V_741 ) || ( ! V_246 && ! V_740 && ! V_741 ) )
return - V_16 ;
if ( V_246 &&
! F_116 ( & V_7 -> V_18 ,
V_742 ) )
return - V_16 ;
if ( V_740 &&
! F_116 ( & V_7 -> V_18 ,
V_743 ) )
return - V_16 ;
if ( V_741 &&
! F_116 ( & V_7 -> V_18 ,
V_744 ) )
return - V_16 ;
return 0 ;
}
static int F_160 ( struct V_4 * V_5 [] ,
struct V_745 * V_746 )
{
bool V_747 = false ;
if ( ! F_20 ( V_5 [ V_748 ] ) ||
! F_20 ( V_5 [ V_749 ] ) ||
! F_20 ( V_5 [ V_750 ] ) ||
! F_20 ( V_5 [ V_751 ] ) )
return - V_16 ;
memset ( V_746 , 0 , sizeof( * V_746 ) ) ;
if ( V_5 [ V_752 ] ) {
V_746 -> V_753 = F_21 ( V_5 [ V_752 ] ) ;
V_746 -> V_754 = F_22 ( V_5 [ V_752 ] ) ;
if ( ! V_746 -> V_754 )
return - V_16 ;
V_747 = true ;
}
if ( V_5 [ V_748 ] ) {
V_746 -> V_755 = F_21 ( V_5 [ V_748 ] ) ;
V_746 -> V_756 = F_22 ( V_5 [ V_748 ] ) ;
V_747 = true ;
}
if ( ! V_747 )
return - V_16 ;
if ( V_5 [ V_749 ] ) {
V_746 -> V_757 = F_21 ( V_5 [ V_749 ] ) ;
V_746 -> V_758 = F_22 ( V_5 [ V_749 ] ) ;
}
if ( V_5 [ V_750 ] ) {
V_746 -> V_759 =
F_21 ( V_5 [ V_750 ] ) ;
V_746 -> V_760 =
F_22 ( V_5 [ V_750 ] ) ;
}
if ( V_5 [ V_751 ] ) {
V_746 -> V_761 =
F_21 ( V_5 [ V_751 ] ) ;
V_746 -> V_762 =
F_22 ( V_5 [ V_751 ] ) ;
}
if ( V_5 [ V_763 ] ) {
V_746 -> V_764 = F_21 ( V_5 [ V_763 ] ) ;
V_746 -> V_765 = F_22 ( V_5 [ V_763 ] ) ;
}
return 0 ;
}
static void F_161 ( struct V_766 * V_138 ,
const T_2 * V_702 )
{
int V_159 ;
if ( ! V_702 )
return;
for ( V_159 = 0 ; V_159 < V_702 [ 1 ] ; V_159 ++ ) {
if ( V_702 [ 2 + V_159 ] == V_767 )
V_138 -> V_768 = true ;
if ( V_702 [ 2 + V_159 ] == V_769 )
V_138 -> V_770 = true ;
}
}
static void F_162 ( struct V_766 * V_138 )
{
const struct V_745 * V_746 = & V_138 -> V_771 ;
T_4 V_772 = V_746 -> V_758 ;
const T_2 * V_773 = V_746 -> V_757 ;
const T_2 * V_702 ;
const T_2 * V_252 ;
V_702 = F_163 ( V_774 , V_773 , V_772 ) ;
F_161 ( V_138 , V_702 ) ;
V_702 = F_163 ( V_775 , V_773 , V_772 ) ;
F_161 ( V_138 , V_702 ) ;
V_252 = F_163 ( V_776 , V_773 , V_772 ) ;
if ( V_252 && V_252 [ 1 ] >= sizeof( * V_138 -> V_247 ) )
V_138 -> V_247 = ( void * ) ( V_252 + 2 ) ;
V_252 = F_163 ( V_777 , V_773 , V_772 ) ;
if ( V_252 && V_252 [ 1 ] >= sizeof( * V_138 -> V_257 ) )
V_138 -> V_257 = ( void * ) ( V_252 + 2 ) ;
}
static bool F_164 ( struct V_6 * V_7 ,
struct V_766 * V_138 )
{
struct V_1 * V_17 ;
bool V_514 = false ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_17 -> V_140 != V_141 &&
V_17 -> V_140 != V_143 )
continue;
if ( ! V_17 -> V_563 . V_53 )
continue;
V_138 -> V_538 = V_17 -> V_563 ;
V_514 = true ;
break;
}
return V_514 ;
}
static bool F_165 ( struct V_6 * V_7 ,
enum V_778 V_779 ,
enum V_356 V_50 )
{
if ( V_779 > V_780 )
return false ;
switch ( V_50 ) {
case V_781 :
if ( ! ( V_7 -> V_18 . V_367 & V_782 ) &&
V_779 == V_783 )
return false ;
if ( ! F_116 ( & V_7 -> V_18 ,
V_784 ) &&
( V_779 == V_785 ||
V_779 == V_786 ||
V_779 == V_787 ) )
return false ;
return true ;
case V_353 :
case V_788 :
if ( V_779 == V_783 )
return false ;
if ( V_779 == V_785 ||
V_779 == V_786 ||
V_779 == V_787 )
return false ;
return true ;
default:
return false ;
}
}
static int F_166 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_766 V_138 ;
int V_35 ;
if ( V_557 -> V_28 -> V_140 != V_141 &&
V_557 -> V_28 -> V_140 != V_143 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_288 )
return - V_558 ;
if ( V_17 -> V_559 )
return - V_789 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
if ( ! V_30 -> V_5 [ V_790 ] ||
! V_30 -> V_5 [ V_791 ] ||
! V_30 -> V_5 [ V_752 ] )
return - V_16 ;
V_35 = F_160 ( V_30 -> V_5 , & V_138 . V_771 ) ;
if ( V_35 )
return V_35 ;
V_138 . V_559 =
F_4 ( V_30 -> V_5 [ V_790 ] ) ;
V_138 . V_792 =
F_4 ( V_30 -> V_5 [ V_791 ] ) ;
V_35 = F_167 ( V_7 , V_557 -> V_28 -> V_140 ,
V_138 . V_559 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_611 ] ) {
V_138 . V_612 = F_21 ( V_30 -> V_5 [ V_611 ] ) ;
V_138 . V_610 =
F_22 ( V_30 -> V_5 [ V_611 ] ) ;
if ( V_138 . V_610 == 0 ||
V_138 . V_610 > V_637 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_793 ] ) {
V_138 . V_794 = F_4 (
V_30 -> V_5 [ V_793 ] ) ;
if ( V_138 . V_794 != V_795 &&
V_138 . V_794 != V_796 &&
V_138 . V_794 != V_797 )
return - V_16 ;
}
V_138 . V_798 = ! ! V_30 -> V_5 [ V_799 ] ;
if ( V_30 -> V_5 [ V_800 ] ) {
V_138 . V_779 = F_4 (
V_30 -> V_5 [ V_800 ] ) ;
if ( ! F_165 ( V_7 , V_138 . V_779 ,
V_788 ) )
return - V_16 ;
} else
V_138 . V_779 = V_801 ;
V_35 = F_168 ( V_7 , V_30 , & V_138 . V_802 ,
V_803 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_804 ] ) {
if ( ! ( V_7 -> V_18 . V_367 & V_805 ) )
return - V_558 ;
V_138 . V_806 = F_79 (
V_30 -> V_5 [ V_804 ] ) ;
}
if ( V_30 -> V_5 [ V_807 ] ) {
if ( V_557 -> V_28 -> V_140 != V_143 )
return - V_16 ;
V_138 . V_808 =
F_32 ( V_30 -> V_5 [ V_807 ] ) ;
if ( V_138 . V_808 > 127 )
return - V_16 ;
if ( V_138 . V_808 != 0 &&
! ( V_7 -> V_18 . V_367 & V_809 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_810 ] ) {
T_2 V_24 ;
if ( V_557 -> V_28 -> V_140 != V_143 )
return - V_16 ;
V_24 = F_32 ( V_30 -> V_5 [ V_810 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_138 . V_811 = V_24 ;
if ( V_138 . V_811 != 0 &&
! ( V_7 -> V_18 . V_367 & V_812 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_540 ] ) {
V_35 = F_81 ( V_7 , V_30 , & V_138 . V_538 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_563 . V_53 ) {
V_138 . V_538 = V_17 -> V_563 ;
} else if ( ! F_164 ( V_7 , & V_138 ) )
return - V_16 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_138 . V_538 ,
V_17 -> V_140 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_730 ] ) {
V_35 = F_154 ( V_30 , & V_138 . V_739 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_156 ( V_7 , V_138 . V_538 . V_53 -> V_366 ,
& V_138 . V_739 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_813 ] ) {
V_138 . V_814 =
F_32 ( V_30 -> V_5 [ V_813 ] ) ;
switch ( V_138 . V_814 ) {
case V_815 :
break;
case V_816 :
if ( ! ( V_7 -> V_18 . V_367 &
V_817 ) )
return - V_16 ;
break;
case V_818 :
if ( ! ( V_7 -> V_18 . V_367 &
V_819 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_138 . V_814 = V_815 ;
}
V_138 . V_820 = F_169 ( V_30 -> V_5 [ V_821 ] ) ;
if ( V_138 . V_820 && ! V_7 -> V_18 . V_437 [ V_822 ] )
return - V_558 ;
if ( V_30 -> V_5 [ V_693 ] ) {
V_138 . V_692 = F_145 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_138 . V_692 ) )
return F_18 ( V_138 . V_692 ) ;
}
F_162 ( & V_138 ) ;
F_113 ( V_17 ) ;
V_35 = F_170 ( V_7 , V_557 , & V_138 ) ;
if ( ! V_35 ) {
V_17 -> V_563 = V_138 . V_538 ;
V_17 -> V_559 = V_138 . V_559 ;
V_17 -> V_538 = V_138 . V_538 ;
V_17 -> V_610 = V_138 . V_610 ;
memcpy ( V_17 -> V_612 , V_138 . V_612 , V_17 -> V_610 ) ;
}
F_115 ( V_17 ) ;
F_39 ( V_138 . V_692 ) ;
return V_35 ;
}
static int F_171 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_745 V_138 ;
int V_35 ;
if ( V_557 -> V_28 -> V_140 != V_141 &&
V_557 -> V_28 -> V_140 != V_143 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_823 )
return - V_558 ;
if ( ! V_17 -> V_559 )
return - V_16 ;
V_35 = F_160 ( V_30 -> V_5 , & V_138 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
V_35 = F_172 ( V_7 , V_557 , & V_138 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_173 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
return F_174 ( V_7 , V_557 , false ) ;
}
static int F_175 ( struct V_29 * V_30 ,
enum V_274 V_140 ,
struct V_824 * V_138 )
{
struct V_4 * V_49 [ V_825 + 1 ] ;
struct V_4 * V_620 ;
int V_623 ;
V_620 = V_30 -> V_5 [ V_826 ] ;
if ( V_620 ) {
struct V_827 * V_828 ;
V_828 = F_21 ( V_620 ) ;
V_138 -> V_829 = V_828 -> V_704 ;
V_138 -> V_830 = V_828 -> V_831 ;
V_138 -> V_830 &= V_138 -> V_829 ;
if ( ( V_138 -> V_829 |
V_138 -> V_830 ) & F_117 ( V_832 ) )
return - V_16 ;
return 0 ;
}
V_620 = V_30 -> V_5 [ V_833 ] ;
if ( ! V_620 )
return 0 ;
if ( F_31 ( V_49 , V_825 ,
V_620 , V_834 ) )
return - V_16 ;
switch ( V_140 ) {
case V_141 :
case V_142 :
case V_143 :
V_138 -> V_829 = F_117 ( V_835 ) |
F_117 ( V_836 ) |
F_117 ( V_837 ) |
F_117 ( V_838 ) ;
break;
case V_147 :
case V_146 :
V_138 -> V_829 = F_117 ( V_835 ) |
F_117 ( V_839 ) ;
break;
case V_144 :
V_138 -> V_829 = F_117 ( V_840 ) |
F_117 ( V_838 ) |
F_117 ( V_835 ) ;
default:
return - V_16 ;
}
for ( V_623 = 1 ; V_623 <= V_825 ; V_623 ++ ) {
if ( V_49 [ V_623 ] ) {
V_138 -> V_830 |= ( 1 << V_623 ) ;
if ( V_623 > V_841 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_176 ( struct V_31 * V_51 , struct V_842 * V_30 ,
int V_43 )
{
struct V_4 * V_246 ;
V_22 V_266 ;
T_3 V_843 ;
enum V_844 V_845 ;
V_246 = F_45 ( V_51 , V_43 ) ;
if ( ! V_246 )
return false ;
V_266 = F_177 ( V_30 ) ;
V_843 = V_266 < ( 1UL << 16 ) ? V_266 : 0 ;
if ( V_266 > 0 &&
F_26 ( V_51 , V_846 , V_266 ) )
return false ;
if ( V_843 > 0 &&
F_53 ( V_51 , V_847 , V_843 ) )
return false ;
switch ( V_30 -> V_848 ) {
case V_849 :
V_845 = V_850 ;
break;
case V_851 :
V_845 = V_852 ;
break;
default:
F_60 ( 1 ) ;
case V_853 :
V_845 = 0 ;
break;
case V_854 :
V_845 = V_855 ;
break;
case V_856 :
V_845 = V_857 ;
break;
case V_858 :
V_845 = V_859 ;
break;
}
if ( V_845 && F_27 ( V_51 , V_845 ) )
return false ;
if ( V_30 -> V_49 & V_860 ) {
if ( F_54 ( V_51 , V_861 , V_30 -> V_250 ) )
return false ;
if ( V_30 -> V_49 & V_862 &&
F_27 ( V_51 , V_863 ) )
return false ;
} else if ( V_30 -> V_49 & V_864 ) {
if ( F_54 ( V_51 , V_865 , V_30 -> V_250 ) )
return false ;
if ( F_54 ( V_51 , V_866 , V_30 -> V_718 ) )
return false ;
if ( V_30 -> V_49 & V_862 &&
F_27 ( V_51 , V_863 ) )
return false ;
}
F_46 ( V_51 , V_246 ) ;
return true ;
}
static bool F_178 ( struct V_31 * V_51 , T_2 V_704 , T_5 * signal ,
int V_867 )
{
void * V_43 ;
int V_159 = 0 ;
if ( ! V_704 )
return true ;
V_43 = F_45 ( V_51 , V_867 ) ;
if ( ! V_43 )
return false ;
for ( V_159 = 0 ; V_159 < V_868 ; V_159 ++ ) {
if ( ! ( V_704 & F_117 ( V_159 ) ) )
continue;
if ( F_54 ( V_51 , V_159 , signal [ V_159 ] ) )
return false ;
}
F_46 ( V_51 , V_43 ) ;
return true ;
}
static int F_179 ( struct V_31 * V_51 , V_22 V_50 , V_22 V_47 ,
V_22 V_48 , int V_49 ,
struct V_6 * V_7 ,
struct V_25 * V_557 ,
const T_2 * V_672 , struct V_869 * V_870 )
{
void * V_359 ;
struct V_4 * V_871 , * V_872 ;
V_359 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_359 )
return - 1 ;
if ( F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_672 ) ||
F_26 ( V_51 , V_369 , V_870 -> V_873 ) )
goto V_59;
V_871 = F_45 ( V_51 , V_874 ) ;
if ( ! V_871 )
goto V_59;
#define F_180 ( V_43 , T_6 , type ) do { \
BUILD_BUG_ON(sizeof(type) == sizeof(u64)); \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
#define F_181 ( V_43 , T_6 ) do { \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb, NL80211_STA_INFO_PAD)) \
goto nla_put_failure; \
} while (0)
F_180 ( V_875 , V_876 , V_22 ) ;
F_180 ( V_877 , V_878 , V_22 ) ;
if ( V_870 -> V_879 & ( F_117 ( V_880 ) |
F_117 ( V_881 ) ) &&
F_26 ( V_51 , V_880 ,
( V_22 ) V_870 -> V_882 ) )
goto V_59;
if ( V_870 -> V_879 & ( F_117 ( V_883 ) |
F_117 ( V_884 ) ) &&
F_26 ( V_51 , V_883 ,
( V_22 ) V_870 -> V_885 ) )
goto V_59;
F_181 ( V_886 , V_882 ) ;
F_181 ( V_887 , V_885 ) ;
F_180 ( V_888 , V_889 , T_3 ) ;
F_180 ( V_890 , V_891 , T_3 ) ;
F_180 ( V_892 , V_893 , T_2 ) ;
F_181 ( V_894 , V_895 ) ;
switch ( V_7 -> V_18 . V_896 ) {
case V_897 :
F_180 ( SIGNAL , signal , T_2 ) ;
F_180 ( V_898 , V_899 , T_2 ) ;
break;
default:
break;
}
if ( V_870 -> V_879 & F_117 ( V_900 ) ) {
if ( ! F_178 ( V_51 , V_870 -> V_901 ,
V_870 -> V_902 ,
V_900 ) )
goto V_59;
}
if ( V_870 -> V_879 & F_117 ( V_903 ) ) {
if ( ! F_178 ( V_51 , V_870 -> V_901 ,
V_870 -> V_904 ,
V_903 ) )
goto V_59;
}
if ( V_870 -> V_879 & F_117 ( V_905 ) ) {
if ( ! F_176 ( V_51 , & V_870 -> V_720 ,
V_905 ) )
goto V_59;
}
if ( V_870 -> V_879 & F_117 ( V_906 ) ) {
if ( ! F_176 ( V_51 , & V_870 -> V_907 ,
V_906 ) )
goto V_59;
}
F_180 ( V_908 , V_909 , V_22 ) ;
F_180 ( V_910 , V_911 , V_22 ) ;
F_180 ( V_912 , V_913 , V_22 ) ;
F_180 ( V_914 , V_915 , V_22 ) ;
F_180 ( V_916 , V_917 , V_22 ) ;
F_180 ( V_918 , V_919 , V_22 ) ;
F_180 ( V_920 , V_921 , V_22 ) ;
F_180 ( V_922 , V_923 , V_22 ) ;
F_180 ( V_924 , V_925 , V_22 ) ;
if ( V_870 -> V_879 & F_117 ( V_926 ) ) {
V_872 = F_45 ( V_51 , V_926 ) ;
if ( ! V_872 )
goto V_59;
if ( ( ( V_870 -> V_872 . V_49 & V_927 ) &&
F_27 ( V_51 , V_928 ) ) ||
( ( V_870 -> V_872 . V_49 & V_929 ) &&
F_27 ( V_51 , V_930 ) ) ||
( ( V_870 -> V_872 . V_49 & V_931 ) &&
F_27 ( V_51 , V_932 ) ) ||
F_54 ( V_51 , V_933 ,
V_870 -> V_872 . V_792 ) ||
F_53 ( V_51 , V_934 ,
V_870 -> V_872 . V_559 ) )
goto V_59;
F_46 ( V_51 , V_872 ) ;
}
if ( ( V_870 -> V_879 & F_117 ( V_935 ) ) &&
F_49 ( V_51 , V_935 ,
sizeof( struct V_827 ) ,
& V_870 -> V_828 ) )
goto V_59;
F_181 ( V_936 , V_937 ) ;
F_181 ( V_938 , V_939 ) ;
F_181 ( V_940 , V_941 ) ;
F_180 ( V_942 , V_943 , T_2 ) ;
#undef F_180
#undef F_181
if ( V_870 -> V_879 & F_117 ( V_944 ) ) {
struct V_4 * V_945 ;
int V_946 ;
V_945 = F_45 ( V_51 , V_944 ) ;
if ( ! V_945 )
goto V_59;
for ( V_946 = 0 ; V_946 < V_947 + 1 ; V_946 ++ ) {
struct V_948 * V_949 ;
struct V_4 * V_950 ;
V_949 = & V_870 -> V_951 [ V_946 ] ;
if ( ! V_949 -> V_879 )
continue;
V_950 = F_45 ( V_51 , V_946 + 1 ) ;
if ( ! V_950 )
goto V_59;
#define F_182 ( V_43 , T_6 ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb, NL80211_TID_STATS_PAD)) \
goto nla_put_failure; \
} while (0)
F_182 ( V_952 , V_953 ) ;
F_182 ( V_954 , V_955 ) ;
F_182 ( V_956 , V_957 ) ;
F_182 ( V_958 , V_959 ) ;
#undef F_182
F_46 ( V_51 , V_950 ) ;
}
F_46 ( V_51 , V_945 ) ;
}
F_46 ( V_51 , V_871 ) ;
if ( V_870 -> V_960 &&
F_49 ( V_51 , V_749 , V_870 -> V_960 ,
V_870 -> V_961 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int F_183 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_869 V_870 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_672 [ V_605 ] ;
int V_962 = V_34 -> args [ 2 ] ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_963;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_963;
}
if ( ! V_7 -> V_327 -> V_964 ) {
V_35 = - V_558 ;
goto V_963;
}
while ( 1 ) {
memset ( & V_870 , 0 , sizeof( V_870 ) ) ;
V_35 = F_184 ( V_7 , V_17 -> V_19 , V_962 ,
V_672 , & V_870 ) ;
if ( V_35 == - V_678 )
break;
if ( V_35 )
goto V_963;
if ( F_179 ( V_32 , V_965 ,
F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_7 , V_17 -> V_19 , V_672 ,
& V_870 ) < 0 )
goto V_618;
V_962 ++ ;
}
V_618:
V_34 -> args [ 2 ] = V_962 ;
V_35 = V_32 -> V_45 ;
V_963:
F_70 () ;
return V_35 ;
}
static int F_185 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_869 V_870 ;
struct V_31 * V_51 ;
T_2 * V_672 = NULL ;
int V_35 ;
memset ( & V_870 , 0 , sizeof( V_870 ) ) ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_672 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( ! V_7 -> V_327 -> V_966 )
return - V_558 ;
V_35 = F_186 ( V_7 , V_557 , V_672 , & V_870 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
if ( F_179 ( V_51 , V_965 ,
V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_7 , V_557 , V_672 , & V_870 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
int F_187 ( struct V_18 * V_18 ,
struct V_824 * V_138 ,
enum V_967 V_968 )
{
if ( V_138 -> V_969 != - 1 &&
V_968 != V_970 )
return - V_16 ;
if ( V_138 -> V_971 != - 1 &&
V_968 != V_970 )
return - V_16 ;
if ( V_138 -> V_972 &&
! ( V_138 -> V_830 & F_117 ( V_839 ) ) &&
V_968 != V_970 )
return - V_16 ;
F_114 ( V_825 != 7 ) ;
switch ( V_968 ) {
case V_973 :
case V_974 :
if ( V_138 -> V_829 &
~ ( F_117 ( V_840 ) |
F_117 ( V_838 ) |
F_117 ( V_835 ) ) )
return - V_16 ;
break;
case V_975 :
case V_976 :
if ( ! ( V_138 -> V_830 & F_117 ( V_839 ) ) )
return - V_16 ;
V_138 -> V_829 &= ~ F_117 ( V_839 ) ;
break;
default:
if ( V_138 -> V_977 != V_978 )
return - V_16 ;
if ( V_138 -> V_921 )
return - V_16 ;
if ( V_138 -> V_979 & V_980 )
return - V_16 ;
}
if ( V_968 != V_975 &&
V_968 != V_976 ) {
if ( V_138 -> V_830 & F_117 ( V_839 ) )
return - V_16 ;
V_138 -> V_829 &= ~ F_117 ( V_839 ) ;
}
if ( V_968 != V_975 &&
V_968 != V_970 ) {
if ( V_138 -> V_979 & V_981 )
return - V_16 ;
if ( V_138 -> V_979 & V_982 )
return - V_16 ;
if ( V_138 -> V_983 )
return - V_16 ;
if ( V_138 -> V_984 || V_138 -> V_985 || V_138 -> V_986 )
return - V_16 ;
}
if ( V_968 != V_987 &&
V_968 != V_970 ) {
if ( V_138 -> V_988 )
return - V_16 ;
}
switch ( V_968 ) {
case V_989 :
if ( ! ( V_138 -> V_829 & F_117 ( V_835 ) ) )
return - V_558 ;
break;
case V_987 :
case V_970 :
if ( V_138 -> V_829 &
~ ( F_117 ( V_835 ) |
F_117 ( V_840 ) |
F_117 ( V_990 ) |
F_117 ( V_836 ) |
F_117 ( V_837 ) |
F_117 ( V_838 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_367 & V_991 ) &&
V_138 -> V_829 &
( F_117 ( V_840 ) |
F_117 ( V_990 ) ) )
return - V_16 ;
break;
case V_992 :
case V_993 :
if ( V_138 -> V_829 & ~ F_117 ( V_835 ) )
return - V_16 ;
break;
case V_975 :
if ( V_138 -> V_829 & ~ ( F_117 ( V_835 ) |
F_117 ( V_837 ) ) )
return - V_16 ;
if ( V_138 -> V_830 & F_117 ( V_835 ) &&
! V_138 -> V_983 )
return - V_16 ;
break;
case V_976 :
return - V_16 ;
case V_973 :
if ( V_138 -> V_979 & V_980 )
return - V_16 ;
break;
case V_974 :
if ( V_138 -> V_977 != V_978 &&
V_138 -> V_977 != V_994 )
return - V_16 ;
break;
}
if ( V_968 != V_970 &&
V_968 != V_975 )
V_138 -> V_995 = false ;
return 0 ;
}
static struct V_25 * F_188 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_996 = V_30 -> V_5 [ V_997 ] ;
struct V_25 * V_998 ;
int V_514 ;
if ( ! V_996 )
return NULL ;
V_998 = F_189 ( F_95 ( V_30 ) , F_4 ( V_996 ) ) ;
if ( ! V_998 )
return F_3 ( - V_23 ) ;
if ( ! V_998 -> V_28 || V_998 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_514 = - V_16 ;
goto error;
}
if ( V_998 -> V_28 -> V_140 != V_142 &&
V_998 -> V_28 -> V_140 != V_141 &&
V_998 -> V_28 -> V_140 != V_143 ) {
V_514 = - V_16 ;
goto error;
}
if ( ! F_92 ( V_998 ) ) {
V_514 = - V_572 ;
goto error;
}
return V_998 ;
error:
F_190 ( V_998 ) ;
return F_3 ( V_514 ) ;
}
static int F_191 ( struct V_29 * V_30 ,
struct V_824 * V_138 )
{
struct V_4 * V_93 [ V_999 + 1 ] ;
struct V_4 * V_620 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1000 ] )
return 0 ;
V_620 = V_30 -> V_5 [ V_1000 ] ;
V_35 = F_31 ( V_93 , V_999 , V_620 ,
V_1001 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_1002 ] )
V_138 -> V_1003 = F_32 (
V_93 [ V_1002 ] ) ;
if ( V_138 -> V_1003 & ~ V_1004 )
return - V_16 ;
if ( V_93 [ V_1005 ] )
V_138 -> V_1006 = F_32 ( V_93 [ V_1005 ] ) ;
if ( V_138 -> V_1006 & ~ V_1007 )
return - V_16 ;
V_138 -> V_979 |= V_981 ;
return 0 ;
}
static int F_192 ( struct V_29 * V_30 ,
struct V_824 * V_138 )
{
if ( V_30 -> V_5 [ V_1008 ] ) {
V_138 -> V_1009 =
F_21 ( V_30 -> V_5 [ V_1008 ] ) ;
V_138 -> V_1010 =
F_22 ( V_30 -> V_5 [ V_1008 ] ) ;
if ( V_138 -> V_1010 < 2 )
return - V_16 ;
if ( V_138 -> V_1010 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1011 ] ) {
V_138 -> V_1012 =
F_21 ( V_30 -> V_5 [ V_1011 ] ) ;
V_138 -> V_1013 =
F_22 ( V_30 -> V_5 [ V_1011 ] ) ;
if ( V_138 -> V_1013 < 2 ||
V_138 -> V_1013 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_193 ( struct V_29 * V_30 ,
struct V_824 * V_138 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_1014 ] )
V_138 -> V_972 = F_79 ( V_30 -> V_5 [ V_1014 ] ) ;
if ( V_30 -> V_5 [ V_1015 ] )
V_138 -> V_985 =
F_21 ( V_30 -> V_5 [ V_1015 ] ) ;
if ( V_30 -> V_5 [ V_1016 ] )
V_138 -> V_986 =
F_21 ( V_30 -> V_5 [ V_1016 ] ) ;
V_35 = F_192 ( V_30 , V_138 ) ;
if ( V_35 )
return V_35 ;
return F_191 ( V_30 , V_138 ) ;
}
static int F_194 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_824 V_138 ;
T_2 * V_672 ;
int V_35 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
if ( ! V_7 -> V_327 -> V_1017 )
return - V_558 ;
if ( V_30 -> V_5 [ V_1018 ] )
V_138 . V_972 = F_79 ( V_30 -> V_5 [ V_1018 ] ) ;
if ( V_30 -> V_5 [ V_1019 ] )
V_138 . V_969 =
F_79 ( V_30 -> V_5 [ V_1019 ] ) ;
else
V_138 . V_969 = - 1 ;
if ( V_30 -> V_5 [ V_1020 ] ) {
T_2 V_24 ;
V_24 = F_32 ( V_30 -> V_5 [ V_1020 ] ) ;
if ( V_24 >= V_1021 )
return - V_16 ;
V_138 . V_971 = V_24 ;
} else {
V_138 . V_971 = - 1 ;
}
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_672 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( V_30 -> V_5 [ V_1022 ] ) {
V_138 . V_983 =
F_21 ( V_30 -> V_5 [ V_1022 ] ) ;
V_138 . V_1023 =
F_22 ( V_30 -> V_5 [ V_1022 ] ) ;
}
if ( V_30 -> V_5 [ V_1024 ] ) {
V_138 . V_1025 =
F_79 ( V_30 -> V_5 [ V_1024 ] ) ;
V_138 . V_979 |= V_982 ;
}
if ( V_30 -> V_5 [ V_1026 ] ) {
V_138 . V_984 =
F_21 ( V_30 -> V_5 [ V_1026 ] ) ;
V_138 . V_1027 =
F_22 ( V_30 -> V_5 [ V_1026 ] ) ;
}
if ( F_175 ( V_30 , V_557 -> V_28 -> V_140 , & V_138 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_1028 ] ) {
V_138 . V_977 =
F_32 ( V_30 -> V_5 [ V_1028 ] ) ;
if ( V_138 . V_977 >= V_1029 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1030 ] ) {
V_138 . V_893 =
F_32 ( V_30 -> V_5 [ V_1030 ] ) ;
if ( V_138 . V_893 >= V_1031 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1032 ] ) {
V_138 . V_1033 = F_79 (
V_30 -> V_5 [ V_1032 ] ) ;
if ( V_138 . V_1033 > V_1034 )
return - V_16 ;
}
V_138 . V_979 |= V_980 ;
}
if ( V_30 -> V_5 [ V_1035 ] ) {
enum V_1036 V_1037 = F_4 (
V_30 -> V_5 [ V_1035 ] ) ;
if ( V_1037 <= V_1038 ||
V_1037 > V_1039 )
return - V_16 ;
V_138 . V_921 = V_1037 ;
}
if ( V_30 -> V_5 [ V_1040 ] ) {
V_138 . V_995 = true ;
V_138 . V_1041 =
F_32 ( V_30 -> V_5 [ V_1040 ] ) ;
}
V_35 = F_193 ( V_30 , & V_138 ) ;
if ( V_35 )
return V_35 ;
V_138 . V_988 = F_188 ( V_30 , V_7 ) ;
if ( F_17 ( V_138 . V_988 ) )
return F_18 ( V_138 . V_988 ) ;
switch ( V_557 -> V_28 -> V_140 ) {
case V_141 :
case V_142 :
case V_143 :
case V_147 :
case V_146 :
case V_145 :
case V_144 :
break;
default:
V_35 = - V_558 ;
goto V_1042;
}
V_35 = F_195 ( V_7 , V_557 , V_672 , & V_138 ) ;
V_1042:
if ( V_138 . V_988 )
F_190 ( V_138 . V_988 ) ;
return V_35 ;
}
static int F_196 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int V_35 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_824 V_138 ;
T_2 * V_672 = NULL ;
V_22 V_1043 = F_117 ( V_840 ) |
F_117 ( V_990 ) ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
if ( ! V_7 -> V_327 -> V_290 )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1019 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1022 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1018 ] &&
! V_30 -> V_5 [ V_1014 ] )
return - V_16 ;
V_672 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_138 . V_983 =
F_21 ( V_30 -> V_5 [ V_1022 ] ) ;
V_138 . V_1023 =
F_22 ( V_30 -> V_5 [ V_1022 ] ) ;
V_138 . V_969 =
F_79 ( V_30 -> V_5 [ V_1019 ] ) ;
if ( V_30 -> V_5 [ V_1020 ] ) {
T_2 V_24 ;
V_24 = F_32 ( V_30 -> V_5 [ V_1020 ] ) ;
if ( V_24 >= V_1021 )
return - V_16 ;
V_138 . V_971 = V_24 ;
} else {
V_138 . V_971 =
V_557 -> V_28 -> V_140 == V_143 ;
}
if ( V_30 -> V_5 [ V_1014 ] )
V_138 . V_972 = F_79 ( V_30 -> V_5 [ V_1014 ] ) ;
else
V_138 . V_972 = F_79 ( V_30 -> V_5 [ V_1018 ] ) ;
if ( ! V_138 . V_972 || V_138 . V_972 > V_1034 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1024 ] ) {
V_138 . V_1025 =
F_79 ( V_30 -> V_5 [ V_1024 ] ) ;
V_138 . V_979 |= V_982 ;
}
if ( V_30 -> V_5 [ V_1026 ] ) {
V_138 . V_984 =
F_21 ( V_30 -> V_5 [ V_1026 ] ) ;
V_138 . V_1027 =
F_22 ( V_30 -> V_5 [ V_1026 ] ) ;
}
if ( V_30 -> V_5 [ V_1015 ] )
V_138 . V_985 =
F_21 ( V_30 -> V_5 [ V_1015 ] ) ;
if ( V_30 -> V_5 [ V_1016 ] )
V_138 . V_986 =
F_21 ( V_30 -> V_5 [ V_1016 ] ) ;
if ( V_30 -> V_5 [ V_1040 ] ) {
V_138 . V_995 = true ;
V_138 . V_1041 =
F_32 ( V_30 -> V_5 [ V_1040 ] ) ;
}
if ( V_30 -> V_5 [ V_1028 ] ) {
V_138 . V_977 =
F_32 ( V_30 -> V_5 [ V_1028 ] ) ;
if ( V_138 . V_977 >= V_1029 )
return - V_16 ;
}
V_35 = F_192 ( V_30 , & V_138 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_191 ( V_30 , & V_138 ) ;
if ( V_35 )
return V_35 ;
if ( F_175 ( V_30 , V_557 -> V_28 -> V_140 , & V_138 ) )
return - V_16 ;
if ( ! ( V_138 . V_830 & F_117 ( V_837 ) ) ) {
V_138 . V_985 = NULL ;
V_138 . V_986 = NULL ;
}
F_114 ( V_825 != 7 ) ;
switch ( V_557 -> V_28 -> V_140 ) {
case V_141 :
case V_142 :
case V_143 :
if ( ! ( V_7 -> V_18 . V_49 & V_404 ) ||
! ( V_138 . V_830 & F_117 ( V_837 ) ) )
V_138 . V_979 &= ~ V_981 ;
if ( ( V_138 . V_830 & F_117 ( V_839 ) ) ||
V_30 -> V_5 [ V_1014 ] )
return - V_16 ;
V_138 . V_829 &= ~ F_117 ( V_839 ) ;
if ( ! ( V_7 -> V_18 . V_367 &
V_991 ) &&
V_138 . V_829 & V_1043 )
return - V_16 ;
if ( ! ( V_138 . V_829 & V_1043 ) ) {
V_138 . V_829 |= V_1043 ;
V_138 . V_830 |= V_1043 ;
}
V_138 . V_988 = F_188 ( V_30 , V_7 ) ;
if ( F_17 ( V_138 . V_988 ) )
return F_18 ( V_138 . V_988 ) ;
break;
case V_144 :
V_138 . V_979 &= ~ V_981 ;
if ( V_138 . V_829 & F_117 ( V_990 ) )
return - V_16 ;
if ( ( V_138 . V_830 & F_117 ( V_839 ) ) ||
V_30 -> V_5 [ V_1014 ] )
return - V_16 ;
break;
case V_146 :
case V_147 :
V_138 . V_979 &= ~ V_981 ;
if ( V_138 . V_829 &
( F_117 ( V_990 ) |
F_117 ( V_840 ) ) )
return - V_16 ;
if ( ! ( V_138 . V_830 & F_117 ( V_839 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_49 & V_332 ) )
return - V_558 ;
if ( ! ( V_7 -> V_18 . V_49 & V_409 ) )
return - V_558 ;
V_138 . V_829 &= ~ F_117 ( V_835 ) ;
break;
default:
return - V_558 ;
}
V_35 = F_197 ( V_7 , V_557 , V_672 , & V_138 ) ;
if ( V_138 . V_988 )
F_190 ( V_138 . V_988 ) ;
return V_35 ;
}
static int F_198 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1044 V_138 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
if ( V_30 -> V_5 [ V_565 ] )
V_138 . V_1045 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( V_557 -> V_28 -> V_140 != V_141 &&
V_557 -> V_28 -> V_140 != V_142 &&
V_557 -> V_28 -> V_140 != V_144 &&
V_557 -> V_28 -> V_140 != V_143 )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_1046 )
return - V_558 ;
if ( V_30 -> V_5 [ V_1047 ] ) {
V_138 . V_1048 =
F_32 ( V_30 -> V_5 [ V_1047 ] ) ;
if ( V_138 . V_1048 != V_1049 >> 4 &&
V_138 . V_1048 != V_1050 >> 4 )
return - V_16 ;
} else {
V_138 . V_1048 = V_1050 >> 4 ;
}
if ( V_30 -> V_5 [ V_1051 ] ) {
V_138 . V_1052 =
F_79 ( V_30 -> V_5 [ V_1051 ] ) ;
if ( V_138 . V_1052 == 0 )
return - V_16 ;
} else {
V_138 . V_1052 = V_1053 ;
}
return F_199 ( V_7 , V_557 , & V_138 ) ;
}
static int F_200 ( struct V_31 * V_51 , V_22 V_47 , V_22 V_48 ,
int V_49 , struct V_25 * V_557 ,
T_2 * V_1054 , T_2 * V_1055 ,
struct V_1056 * V_1057 )
{
void * V_359 ;
struct V_4 * V_1058 ;
V_359 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_1059 ) ;
if ( ! V_359 )
return - 1 ;
if ( F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_1054 ) ||
F_49 ( V_51 , V_1060 , V_605 , V_1055 ) ||
F_26 ( V_51 , V_369 , V_1057 -> V_873 ) )
goto V_59;
V_1058 = F_45 ( V_51 , V_1061 ) ;
if ( ! V_1058 )
goto V_59;
if ( ( V_1057 -> V_879 & V_1062 ) &&
F_26 ( V_51 , V_1063 ,
V_1057 -> V_1064 ) )
goto V_59;
if ( ( ( V_1057 -> V_879 & V_1065 ) &&
F_26 ( V_51 , V_1066 , V_1057 -> V_1067 ) ) ||
( ( V_1057 -> V_879 & V_1068 ) &&
F_26 ( V_51 , V_1069 ,
V_1057 -> V_1070 ) ) ||
( ( V_1057 -> V_879 & V_1071 ) &&
F_26 ( V_51 , V_1072 ,
V_1057 -> V_1073 ) ) ||
( ( V_1057 -> V_879 & V_1074 ) &&
F_54 ( V_51 , V_1075 ,
V_1057 -> V_49 ) ) ||
( ( V_1057 -> V_879 & V_1076 ) &&
F_26 ( V_51 , V_1077 ,
V_1057 -> V_1078 ) ) ||
( ( V_1057 -> V_879 & V_1079 ) &&
F_54 ( V_51 , V_1080 ,
V_1057 -> V_1081 ) ) )
goto V_59;
F_46 ( V_51 , V_1058 ) ;
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int F_201 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1056 V_1057 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1054 [ V_605 ] ;
T_2 V_1055 [ V_605 ] ;
int V_1082 = V_34 -> args [ 2 ] ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_963;
if ( ! V_7 -> V_327 -> V_1083 ) {
V_35 = - V_558 ;
goto V_963;
}
if ( V_17 -> V_140 != V_144 ) {
V_35 = - V_558 ;
goto V_963;
}
while ( 1 ) {
V_35 = F_202 ( V_7 , V_17 -> V_19 , V_1082 , V_1054 ,
V_1055 , & V_1057 ) ;
if ( V_35 == - V_678 )
break;
if ( V_35 )
goto V_963;
if ( F_200 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_17 -> V_19 , V_1054 , V_1055 ,
& V_1057 ) < 0 )
goto V_618;
V_1082 ++ ;
}
V_618:
V_34 -> args [ 2 ] = V_1082 ;
V_35 = V_32 -> V_45 ;
V_963:
F_70 () ;
return V_35 ;
}
static int F_203 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int V_35 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1056 V_1057 ;
struct V_31 * V_51 ;
T_2 * V_1054 = NULL ;
T_2 V_1055 [ V_605 ] ;
memset ( & V_1057 , 0 , sizeof( V_1057 ) ) ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_1054 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( ! V_7 -> V_327 -> V_1084 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_144 )
return - V_558 ;
V_35 = F_204 ( V_7 , V_557 , V_1054 , V_1055 , & V_1057 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
if ( F_200 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_557 , V_1054 , V_1055 , & V_1057 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_205 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 * V_1054 = NULL ;
T_2 * V_1055 = NULL ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1060 ] )
return - V_16 ;
V_1054 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_1055 = F_21 ( V_30 -> V_5 [ V_1060 ] ) ;
if ( ! V_7 -> V_327 -> V_1085 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_144 )
return - V_558 ;
return F_206 ( V_7 , V_557 , V_1054 , V_1055 ) ;
}
static int F_207 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 * V_1054 = NULL ;
T_2 * V_1055 = NULL ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1060 ] )
return - V_16 ;
V_1054 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_1055 = F_21 ( V_30 -> V_5 [ V_1060 ] ) ;
if ( ! V_7 -> V_327 -> V_292 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_144 )
return - V_558 ;
return F_208 ( V_7 , V_557 , V_1054 , V_1055 ) ;
}
static int F_209 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 * V_1054 = NULL ;
if ( V_30 -> V_5 [ V_565 ] )
V_1054 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( ! V_7 -> V_327 -> V_1086 )
return - V_558 ;
return F_210 ( V_7 , V_557 , V_1054 ) ;
}
static int F_211 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int V_35 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1056 V_1057 ;
struct V_31 * V_51 ;
T_2 * V_1054 = NULL ;
T_2 V_1087 [ V_605 ] ;
memset ( & V_1057 , 0 , sizeof( V_1057 ) ) ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_1054 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( ! V_7 -> V_327 -> V_1088 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_144 )
return - V_558 ;
V_35 = F_212 ( V_7 , V_557 , V_1054 , V_1087 , & V_1057 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
if ( F_200 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_557 , V_1054 , V_1087 , & V_1057 ) < 0 ) {
F_76 ( V_51 ) ;
return - V_89 ;
}
return F_77 ( V_51 , V_30 ) ;
}
static int F_213 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1056 V_1057 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1054 [ V_605 ] ;
T_2 V_1087 [ V_605 ] ;
int V_1082 = V_34 -> args [ 2 ] ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_963;
if ( ! V_7 -> V_327 -> V_1089 ) {
V_35 = - V_558 ;
goto V_963;
}
if ( V_17 -> V_140 != V_144 ) {
V_35 = - V_558 ;
goto V_963;
}
while ( 1 ) {
V_35 = F_214 ( V_7 , V_17 -> V_19 , V_1082 , V_1054 ,
V_1087 , & V_1057 ) ;
if ( V_35 == - V_678 )
break;
if ( V_35 )
goto V_963;
if ( F_200 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_17 -> V_19 , V_1054 , V_1087 ,
& V_1057 ) < 0 )
goto V_618;
V_1082 ++ ;
}
V_618:
V_34 -> args [ 2 ] = V_1082 ;
V_35 = V_32 -> V_45 ;
V_963:
F_70 () ;
return V_35 ;
}
static int F_215 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_1090 V_138 ;
int V_35 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_138 . V_1091 = - 1 ;
V_138 . V_1092 = - 1 ;
V_138 . V_1093 = - 1 ;
V_138 . V_1094 = - 1 ;
V_138 . V_1095 = - 1 ;
V_138 . V_808 = - 1 ;
V_138 . V_811 = - 1 ;
if ( V_30 -> V_5 [ V_1096 ] )
V_138 . V_1091 =
F_32 ( V_30 -> V_5 [ V_1096 ] ) ;
if ( V_30 -> V_5 [ V_1097 ] )
V_138 . V_1092 =
F_32 ( V_30 -> V_5 [ V_1097 ] ) ;
if ( V_30 -> V_5 [ V_1098 ] )
V_138 . V_1093 =
F_32 ( V_30 -> V_5 [ V_1098 ] ) ;
if ( V_30 -> V_5 [ V_1099 ] ) {
V_138 . V_1100 =
F_21 ( V_30 -> V_5 [ V_1099 ] ) ;
V_138 . V_1101 =
F_22 ( V_30 -> V_5 [ V_1099 ] ) ;
}
if ( V_30 -> V_5 [ V_1102 ] )
V_138 . V_1094 = ! ! F_32 ( V_30 -> V_5 [ V_1102 ] ) ;
if ( V_30 -> V_5 [ V_1103 ] )
V_138 . V_1095 =
F_79 ( V_30 -> V_5 [ V_1103 ] ) ;
if ( V_30 -> V_5 [ V_807 ] ) {
if ( V_557 -> V_28 -> V_140 != V_143 )
return - V_16 ;
V_138 . V_808 =
F_216 ( V_30 -> V_5 [ V_807 ] ) ;
if ( V_138 . V_808 < 0 )
return - V_16 ;
if ( V_138 . V_808 != 0 &&
! ( V_7 -> V_18 . V_367 & V_809 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_810 ] ) {
T_2 V_24 ;
if ( V_557 -> V_28 -> V_140 != V_143 )
return - V_16 ;
V_24 = F_32 ( V_30 -> V_5 [ V_810 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_138 . V_811 = V_24 ;
if ( V_138 . V_811 &&
! ( V_7 -> V_18 . V_367 & V_812 ) )
return - V_16 ;
}
if ( ! V_7 -> V_327 -> V_296 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_141 &&
V_557 -> V_28 -> V_140 != V_143 )
return - V_558 ;
F_113 ( V_17 ) ;
V_35 = F_217 ( V_7 , V_557 , & V_138 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_218 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_139 = NULL ;
bool V_1104 ;
enum V_1105 V_1106 ;
V_22 V_657 ;
if ( F_219 ( ! F_220 ( V_1107 ) ) )
return - V_1108 ;
if ( V_30 -> V_5 [ V_1109 ] )
V_1106 =
F_4 ( V_30 -> V_5 [ V_1109 ] ) ;
else
V_1106 = V_1110 ;
switch ( V_1106 ) {
case V_1110 :
case V_1111 :
if ( ! V_30 -> V_5 [ V_1112 ] )
return - V_16 ;
V_139 = F_21 ( V_30 -> V_5 [ V_1112 ] ) ;
return F_221 ( V_139 , V_1106 ) ;
case V_1113 :
if ( V_30 -> V_5 [ V_656 ] ) {
V_657 = V_30 -> V_522 ;
V_1104 = ! ! V_30 -> V_5 [ V_1114 ] ;
} else {
V_657 = 0 ;
V_1104 = true ;
}
return F_222 ( V_1104 , V_657 ) ;
default:
return - V_16 ;
}
}
static int F_223 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_1115 V_1116 ;
int V_35 = 0 ;
void * V_359 ;
struct V_4 * V_1058 ;
struct V_31 * V_51 ;
if ( V_17 -> V_140 != V_144 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_1117 )
return - V_558 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1118 )
memcpy ( & V_1116 , & V_1119 , sizeof( V_1116 ) ) ;
else
V_35 = F_224 ( V_7 , V_557 , & V_1116 ) ;
F_115 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1120 ) ;
if ( ! V_359 )
goto V_618;
V_1058 = F_45 ( V_51 , V_1121 ) ;
if ( ! V_1058 )
goto V_59;
if ( F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_53 ( V_51 , V_1122 ,
V_1116 . V_1123 ) ||
F_53 ( V_51 , V_1124 ,
V_1116 . V_1125 ) ||
F_53 ( V_51 , V_1126 ,
V_1116 . V_1127 ) ||
F_53 ( V_51 , V_1128 ,
V_1116 . V_1129 ) ||
F_54 ( V_51 , V_1130 ,
V_1116 . V_1131 ) ||
F_54 ( V_51 , V_1132 ,
V_1116 . V_1133 ) ||
F_54 ( V_51 , V_1134 ,
V_1116 . V_1135 ) ||
F_54 ( V_51 , V_1136 ,
V_1116 . V_1137 ) ||
F_26 ( V_51 , V_1138 ,
V_1116 . V_1139 ) ||
F_54 ( V_51 , V_1140 ,
V_1116 . V_1141 ) ||
F_26 ( V_51 , V_1142 ,
V_1116 . V_1143 ) ||
F_53 ( V_51 , V_1144 ,
V_1116 . V_1145 ) ||
F_26 ( V_51 , V_1146 ,
V_1116 . V_1147 ) ||
F_53 ( V_51 , V_1148 ,
V_1116 . V_1149 ) ||
F_53 ( V_51 , V_1150 ,
V_1116 . V_1151 ) ||
F_53 ( V_51 , V_1152 ,
V_1116 . V_1153 ) ||
F_54 ( V_51 , V_1154 ,
V_1116 . V_1155 ) ||
F_53 ( V_51 , V_1156 ,
V_1116 . V_1157 ) ||
F_54 ( V_51 , V_1158 ,
V_1116 . V_1159 ) ||
F_54 ( V_51 , V_1160 ,
V_1116 . V_1161 ) ||
F_26 ( V_51 , V_1162 ,
V_1116 . V_1163 ) ||
F_26 ( V_51 , V_1164 ,
V_1116 . V_1095 ) ||
F_26 ( V_51 , V_1165 ,
V_1116 . V_1166 ) ||
F_53 ( V_51 , V_1167 ,
V_1116 . V_1168 ) ||
F_53 ( V_51 , V_1169 ,
V_1116 . V_1170 ) ||
F_26 ( V_51 , V_1171 ,
V_1116 . V_1172 ) ||
F_53 ( V_51 , V_1173 ,
V_1116 . V_1174 ) ||
F_26 ( V_51 , V_1175 ,
V_1116 . V_1176 ) )
goto V_59;
F_46 ( V_51 , V_1058 ) ;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_66 ( V_51 , V_359 ) ;
V_618:
F_76 ( V_51 ) ;
return - V_89 ;
}
static int F_225 ( const struct V_4 * V_620 , T_2 V_1177 , T_2 V_174 , bool * V_618 )
{
T_2 V_1178 = F_32 ( V_620 ) ;
if ( V_1178 < V_1177 || V_1178 > V_174 )
return - V_16 ;
* V_618 = V_1178 ;
return 0 ;
}
static int F_226 ( const struct V_4 * V_620 , T_2 V_1177 , T_2 V_174 , T_2 * V_618 )
{
T_2 V_1178 = F_32 ( V_620 ) ;
if ( V_1178 < V_1177 || V_1178 > V_174 )
return - V_16 ;
* V_618 = V_1178 ;
return 0 ;
}
static int F_227 ( const struct V_4 * V_620 , T_3 V_1177 , T_3 V_174 , T_3 * V_618 )
{
T_3 V_1178 = F_79 ( V_620 ) ;
if ( V_1178 < V_1177 || V_1178 > V_174 )
return - V_16 ;
* V_618 = V_1178 ;
return 0 ;
}
static int F_228 ( const struct V_4 * V_620 , V_22 V_1177 , V_22 V_174 , V_22 * V_618 )
{
V_22 V_1178 = F_4 ( V_620 ) ;
if ( V_1178 < V_1177 || V_1178 > V_174 )
return - V_16 ;
* V_618 = V_1178 ;
return 0 ;
}
static int F_229 ( const struct V_4 * V_620 , T_7 V_1177 , T_7 V_174 , T_7 * V_618 )
{
T_7 V_1178 = F_230 ( V_620 ) ;
if ( V_1178 < V_1177 || V_1178 > V_174 )
return - V_16 ;
* V_618 = V_1178 ;
return 0 ;
}
static int F_231 ( const struct V_4 * V_620 ,
enum V_1036 V_1177 ,
enum V_1036 V_174 ,
enum V_1036 * V_618 )
{
V_22 V_1178 = F_4 ( V_620 ) ;
if ( V_1178 < V_1177 || V_1178 > V_174 )
return - V_16 ;
* V_618 = V_1178 ;
return 0 ;
}
static int F_232 ( struct V_29 * V_30 ,
struct V_1115 * V_1179 ,
V_22 * V_1180 )
{
struct V_4 * V_93 [ V_1181 + 1 ] ;
V_22 V_704 = 0 ;
T_3 V_1095 ;
#define F_233 ( V_93 , V_1179 , T_8 , V_1177 , V_174 , V_704 , V_43 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr], min, max, &cfg->param)) \
return -EINVAL; \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1121 ] )
return - V_16 ;
if ( F_31 ( V_93 , V_1181 ,
V_30 -> V_5 [ V_1121 ] ,
V_1182 ) )
return - V_16 ;
F_114 ( V_1181 > 32 ) ;
F_233 ( V_93 , V_1179 , V_1123 , 1 , 255 ,
V_704 , V_1122 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1125 , 1 , 255 ,
V_704 , V_1124 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1127 , 1 , 255 ,
V_704 , V_1126 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1129 , 0 , 255 ,
V_704 , V_1128 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1131 , 0 , 16 ,
V_704 , V_1130 ,
F_226 ) ;
F_233 ( V_93 , V_1179 , V_1133 , 1 , 255 ,
V_704 , V_1132 , F_226 ) ;
F_233 ( V_93 , V_1179 , V_1135 , 1 , 255 ,
V_704 , V_1134 ,
F_226 ) ;
F_233 ( V_93 , V_1179 , V_1137 , 0 , 1 ,
V_704 , V_1136 ,
F_225 ) ;
F_233 ( V_93 , V_1179 , V_1139 ,
1 , 255 , V_704 ,
V_1138 ,
F_228 ) ;
F_233 ( V_93 , V_1179 , V_1141 , 0 , 255 ,
V_704 , V_1140 ,
F_226 ) ;
F_233 ( V_93 , V_1179 , V_1143 , 1 , 65535 ,
V_704 , V_1142 ,
F_228 ) ;
F_233 ( V_93 , V_1179 , V_1145 , 1 , 65535 ,
V_704 , V_1144 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1147 ,
1 , 65535 , V_704 ,
V_1146 ,
F_228 ) ;
F_233 ( V_93 , V_1179 , V_1149 ,
1 , 65535 , V_704 ,
V_1148 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1151 ,
1 , 65535 , V_704 ,
V_1150 ,
F_227 ) ;
F_233 ( V_93 , V_1179 ,
V_1153 ,
1 , 65535 , V_704 ,
V_1152 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1155 , 0 , 4 ,
V_704 , V_1154 ,
F_226 ) ;
F_233 ( V_93 , V_1179 , V_1157 , 1 , 65535 ,
V_704 , V_1156 ,
F_227 ) ;
F_233 ( V_93 , V_1179 ,
V_1159 , 0 , 1 ,
V_704 , V_1158 ,
F_225 ) ;
F_233 ( V_93 , V_1179 , V_1161 , 0 , 1 ,
V_704 , V_1160 ,
F_225 ) ;
F_233 ( V_93 , V_1179 , V_1163 , - 255 , 0 ,
V_704 , V_1162 ,
F_229 ) ;
if ( V_93 [ V_1164 ] ) {
V_1095 = F_79 ( V_93 [ V_1164 ] ) ;
if ( V_1095 & ~ ( V_1183 |
V_1184 |
V_1185 ) )
return - V_16 ;
if ( ( V_1095 & V_1184 ) &&
( V_1095 & V_1185 ) )
return - V_16 ;
switch ( V_1095 & V_1183 ) {
case V_1186 :
case V_1187 :
if ( V_1095 & V_1185 )
return - V_16 ;
break;
case V_1188 :
case V_1189 :
if ( ! ( V_1095 & V_1185 ) )
return - V_16 ;
break;
}
V_1179 -> V_1095 = V_1095 ;
V_704 |= ( 1 << ( V_1164 - 1 ) ) ;
}
F_233 ( V_93 , V_1179 , V_1166 ,
1 , 65535 , V_704 ,
V_1165 ,
F_228 ) ;
F_233 ( V_93 , V_1179 , V_1168 , 1 , 65535 ,
V_704 , V_1167 ,
F_227 ) ;
F_233 ( V_93 , V_1179 ,
V_1170 ,
1 , 65535 , V_704 ,
V_1169 ,
F_227 ) ;
F_233 ( V_93 , V_1179 , V_1172 ,
V_1190 ,
V_1039 ,
V_704 , V_1171 ,
F_231 ) ;
F_233 ( V_93 , V_1179 , V_1174 ,
0 , 65535 , V_704 ,
V_1173 , F_227 ) ;
F_233 ( V_93 , V_1179 , V_1176 , 0 , 0xffffffff ,
V_704 , V_1175 ,
F_228 ) ;
if ( V_1180 )
* V_1180 = V_704 ;
return 0 ;
#undef F_233
}
static int F_234 ( struct V_29 * V_30 ,
struct V_1191 * V_1192 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_4 * V_93 [ V_1193 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1194 ] )
return - V_16 ;
if ( F_31 ( V_93 , V_1193 ,
V_30 -> V_5 [ V_1194 ] ,
V_1195 ) )
return - V_16 ;
if ( V_93 [ V_1196 ] )
V_1192 -> V_1197 =
( F_32 ( V_93 [ V_1196 ] ) ) ?
V_1198 :
V_1199 ;
if ( V_93 [ V_1200 ] )
V_1192 -> V_1201 =
( F_32 ( V_93 [ V_1200 ] ) ) ?
V_1202 :
V_1203 ;
if ( V_93 [ V_1204 ] )
V_1192 -> V_1205 =
( F_32 ( V_93 [ V_1204 ] ) ) ?
V_1206 :
V_1207 ;
if ( V_93 [ V_1208 ] ) {
struct V_4 * V_1209 =
V_93 [ V_1208 ] ;
if ( ! F_20 ( V_1209 ) )
return - V_16 ;
V_1192 -> V_1210 = F_21 ( V_1209 ) ;
V_1192 -> V_1211 = F_22 ( V_1209 ) ;
}
if ( V_93 [ V_1212 ] &&
! ( V_7 -> V_18 . V_367 & V_1213 ) )
return - V_16 ;
V_1192 -> V_1214 = F_169 ( V_93 [ V_1212 ] ) ;
V_1192 -> V_1215 = F_169 ( V_93 [ V_1216 ] ) ;
V_1192 -> V_1217 = F_169 ( V_93 [ V_1218 ] ) ;
if ( V_1192 -> V_1217 )
V_1192 -> V_1214 = true ;
if ( V_93 [ V_1219 ] ) {
if ( ! V_1192 -> V_1214 )
return - V_16 ;
V_1192 -> V_1220 =
F_32 ( V_93 [ V_1219 ] ) ;
}
return 0 ;
}
static int F_235 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_1115 V_1179 ;
V_22 V_704 ;
int V_35 ;
if ( V_17 -> V_140 != V_144 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_294 )
return - V_558 ;
V_35 = F_232 ( V_30 , & V_1179 , & V_704 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1118 )
V_35 = - V_149 ;
if ( ! V_35 )
V_35 = F_236 ( V_7 , V_557 , V_704 , & V_1179 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_237 ( const struct V_1221 * V_1222 ,
struct V_31 * V_51 )
{
struct V_4 * V_1223 ;
unsigned int V_159 ;
if ( F_61 ( V_51 , V_1112 , V_1222 -> V_1224 ) ||
( V_1222 -> V_1225 &&
F_54 ( V_51 , V_1226 , V_1222 -> V_1225 ) ) )
goto V_59;
V_1223 = F_45 ( V_51 , V_1227 ) ;
if ( ! V_1223 )
goto V_59;
for ( V_159 = 0 ; V_159 < V_1222 -> V_1228 ; V_159 ++ ) {
struct V_4 * V_1229 ;
const struct V_1230 * V_1231 ;
const struct V_1232 * V_1233 ;
const struct V_1234 * V_1235 ;
unsigned int V_1236 ;
V_1231 = & V_1222 -> V_1237 [ V_159 ] ;
V_1233 = & V_1231 -> V_1233 ;
V_1235 = & V_1231 -> V_1235 ;
V_1229 = F_45 ( V_51 , V_159 ) ;
if ( ! V_1229 )
goto V_59;
V_1236 = V_1233 -> V_1236 ;
if ( ! V_1236 )
V_1236 = F_238 ( V_1222 ,
V_1231 ) ;
if ( F_26 ( V_51 , V_1238 ,
V_1231 -> V_49 ) ||
F_26 ( V_51 , V_1239 ,
V_1233 -> V_1240 ) ||
F_26 ( V_51 , V_1241 ,
V_1233 -> V_1242 ) ||
F_26 ( V_51 , V_1243 ,
V_1236 ) ||
F_26 ( V_51 , V_1244 ,
V_1235 -> V_1245 ) ||
F_26 ( V_51 , V_1246 ,
V_1235 -> V_1247 ) ||
F_26 ( V_51 , V_1248 ,
V_1231 -> V_72 ) )
goto V_59;
F_46 ( V_51 , V_1229 ) ;
}
F_46 ( V_51 , V_1223 ) ;
return 0 ;
V_59:
return - V_513 ;
}
static int F_239 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1221 * V_1222 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_89 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1249 ) ;
if ( ! V_359 )
goto V_1250;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1251 ;
V_7 = F_12 ( F_95 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_76 ( V_51 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1251 = V_18 -> V_496 &
V_497 ;
V_1222 = F_240 ( V_18 ) ;
if ( F_60 ( ! V_1222 && V_1251 ) ) {
F_76 ( V_51 ) ;
return - V_16 ;
}
if ( V_1222 &&
F_26 ( V_51 , V_26 , F_241 ( V_18 ) ) )
goto V_59;
}
if ( ! V_18 && F_242 () &&
F_26 ( V_51 , V_1109 ,
V_1111 ) )
goto V_59;
F_243 () ;
if ( ! V_1222 )
V_1222 = F_244 ( V_1107 ) ;
if ( F_237 ( V_1222 , V_51 ) )
goto V_1252;
F_245 () ;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_1252:
F_245 () ;
V_59:
F_66 ( V_51 , V_359 ) ;
V_1250:
F_76 ( V_51 ) ;
return - V_513 ;
}
static int F_246 ( struct V_31 * V_51 , struct V_33 * V_34 ,
V_22 V_48 , int V_49 , struct V_18 * V_18 ,
const struct V_1221 * V_1222 )
{
void * V_359 = F_23 ( V_51 , F_72 ( V_34 -> V_32 ) . V_47 , V_48 , V_49 ,
V_1249 ) ;
if ( ! V_359 )
return - 1 ;
F_247 ( V_34 , V_359 , & V_38 ) ;
if ( F_237 ( V_1222 , V_51 ) )
goto V_59;
if ( ! V_18 && F_242 () &&
F_26 ( V_51 , V_1109 ,
V_1111 ) )
goto V_59;
if ( V_18 &&
F_26 ( V_51 , V_26 , F_241 ( V_18 ) ) )
goto V_59;
if ( V_18 && V_18 -> V_496 & V_497 &&
F_27 ( V_51 , V_498 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int F_248 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1221 * V_1222 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1253 , V_517 = V_34 -> args [ 2 ] ;
F_69 () ;
if ( V_1107 && V_517 == 0 ) {
V_35 = F_246 ( V_32 , V_34 , V_34 -> V_36 -> V_518 ,
V_519 , NULL ,
F_249 ( V_1107 ) ) ;
if ( V_35 < 0 )
goto V_963;
}
V_1253 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1222 = F_240 ( & V_7 -> V_18 ) ;
if ( ! V_1222 )
continue;
if ( ++ V_1253 <= V_517 )
continue;
V_35 = F_246 ( V_32 , V_34 , V_34 -> V_36 -> V_518 ,
V_519 , & V_7 -> V_18 , V_1222 ) ;
if ( V_35 < 0 ) {
V_1253 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1253 ;
V_35 = V_32 -> V_45 ;
V_963:
F_70 () ;
return V_35 ;
}
static int F_250 ( struct V_4 * V_93 [] ,
struct V_1230 * V_1231 )
{
struct V_1232 * V_1233 = & V_1231 -> V_1233 ;
struct V_1234 * V_1235 = & V_1231 -> V_1235 ;
if ( ! V_93 [ V_1238 ] )
return - V_16 ;
if ( ! V_93 [ V_1239 ] )
return - V_16 ;
if ( ! V_93 [ V_1241 ] )
return - V_16 ;
if ( ! V_93 [ V_1243 ] )
return - V_16 ;
if ( ! V_93 [ V_1246 ] )
return - V_16 ;
V_1231 -> V_49 = F_4 ( V_93 [ V_1238 ] ) ;
V_1233 -> V_1240 =
F_4 ( V_93 [ V_1239 ] ) ;
V_1233 -> V_1242 =
F_4 ( V_93 [ V_1241 ] ) ;
V_1233 -> V_1236 =
F_4 ( V_93 [ V_1243 ] ) ;
V_1235 -> V_1247 =
F_4 ( V_93 [ V_1246 ] ) ;
if ( V_93 [ V_1244 ] )
V_1235 -> V_1245 =
F_4 ( V_93 [ V_1244 ] ) ;
if ( V_93 [ V_1248 ] )
V_1231 -> V_72 =
F_4 ( V_93 [ V_1248 ] ) ;
return 0 ;
}
static int F_251 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_93 [ V_1254 + 1 ] ;
struct V_4 * V_1229 ;
char * V_1224 ;
int V_1255 , V_1256 ;
V_22 V_1257 = 0 , V_1258 = 0 , V_1259 ;
enum V_1260 V_1225 = V_1261 ;
struct V_1221 * V_1262 ;
if ( ! V_30 -> V_5 [ V_1112 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1227 ] )
return - V_16 ;
V_1224 = F_21 ( V_30 -> V_5 [ V_1112 ] ) ;
if ( V_30 -> V_5 [ V_1226 ] )
V_1225 = F_32 ( V_30 -> V_5 [ V_1226 ] ) ;
F_36 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1257 ++ ;
if ( V_1257 > V_1263 )
return - V_16 ;
}
if ( ! F_252 ( V_1224 ) )
return - V_16 ;
V_1259 = sizeof( struct V_1221 ) +
V_1257 * sizeof( struct V_1230 ) ;
V_1262 = F_37 ( V_1259 , V_134 ) ;
if ( ! V_1262 )
return - V_135 ;
V_1262 -> V_1228 = V_1257 ;
V_1262 -> V_1224 [ 0 ] = V_1224 [ 0 ] ;
V_1262 -> V_1224 [ 1 ] = V_1224 [ 1 ] ;
if ( F_253 ( V_1225 ) )
V_1262 -> V_1225 = V_1225 ;
F_36 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1256 = F_31 ( V_93 , V_1254 ,
V_1229 , V_1264 ) ;
if ( V_1256 )
goto V_1265;
V_1256 = F_250 ( V_93 , & V_1262 -> V_1237 [ V_1258 ] ) ;
if ( V_1256 )
goto V_1265;
V_1258 ++ ;
if ( V_1258 > V_1263 ) {
V_1256 = - V_16 ;
goto V_1265;
}
}
return F_254 ( V_1262 , V_1266 ) ;
V_1265:
F_39 ( V_1262 ) ;
return V_1256 ;
}
static int F_255 ( struct V_4 * V_1267 )
{
struct V_4 * V_1268 , * V_1269 ;
int V_440 = 0 , V_1270 , V_1271 ;
F_36 (attr1, freqs, tmp1) {
V_440 ++ ;
F_36 (attr2, freqs, tmp2)
if ( V_1268 != V_1269 &&
F_4 ( V_1268 ) == F_4 ( V_1269 ) )
return 0 ;
}
return V_440 ;
}
static bool F_256 ( struct V_18 * V_18 , enum V_365 V_1272 )
{
return V_1272 < V_436 && V_18 -> V_437 [ V_1272 ] ;
}
static int F_257 ( struct V_4 * V_620 , struct V_18 * V_18 ,
struct V_1273 * V_1274 )
{
struct V_4 * V_43 [ V_1275 + 1 ] ;
struct V_4 * V_1276 ;
int V_35 ;
bool V_27 = false ;
int V_159 ;
V_1276 = F_21 ( V_620 ) ;
if ( ! F_258 ( V_1276 , F_22 ( V_1276 ) ) )
return - V_16 ;
V_35 = F_31 ( V_43 , V_1275 , V_1276 ,
V_1277 ) ;
if ( V_35 )
return V_35 ;
for ( V_159 = 0 ; V_159 <= V_1275 ; V_159 ++ ) {
if ( V_43 [ V_159 ] ) {
if ( V_27 )
return - V_16 ;
V_27 = true ;
}
}
V_1274 -> V_1278 = V_1279 ;
if ( V_43 [ V_1280 ] )
V_1274 -> V_1278 = V_1280 ;
if ( V_43 [ V_1281 ] ) {
V_1274 -> V_1278 = V_1281 ;
V_1274 -> T_8 . V_1282 =
F_4 ( V_43 [ V_1281 ] ) ;
if ( ! F_256 ( V_18 , V_1274 -> T_8 . V_1282 ) )
return - V_16 ;
}
if ( V_43 [ V_1283 ] ) {
struct V_1284 * V_1285 ;
V_1285 = F_21 ( V_43 [ V_1283 ] ) ;
V_1274 -> V_1278 = V_1283 ;
V_1274 -> T_8 . V_1286 . V_366 = V_1285 -> V_366 ;
V_1274 -> T_8 . V_1286 . V_1287 = V_1285 -> V_1287 ;
if ( ! F_256 ( V_18 , V_1274 -> T_8 . V_1286 . V_366 ) )
return - V_16 ;
}
if ( V_1274 -> V_1278 == V_1279 )
return - V_16 ;
if ( ! ( V_18 -> V_501 & F_117 ( V_1274 -> V_1278 ) ) )
return - V_16 ;
return 0 ;
}
static int F_259 ( struct V_4 * * V_5 ,
T_2 * V_672 , T_2 * V_1288 )
{
int V_159 ;
if ( ! V_5 [ V_565 ] && ! V_5 [ V_1289 ] ) {
F_260 ( V_672 ) ;
F_260 ( V_1288 ) ;
V_672 [ 0 ] = 0x2 ;
V_1288 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_565 ] || ! V_5 [ V_1289 ] )
return - V_16 ;
memcpy ( V_672 , F_21 ( V_5 [ V_565 ] ) , V_605 ) ;
memcpy ( V_1288 , F_21 ( V_5 [ V_1289 ] ) , V_605 ) ;
if ( ! F_261 ( V_1288 ) ||
F_261 ( V_672 ) )
return - V_16 ;
for ( V_159 = 0 ; V_159 < V_605 ; V_159 ++ )
V_672 [ V_159 ] &= V_1288 [ V_159 ] ;
return 0 ;
}
static int F_262 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
struct V_1290 * V_1291 ;
struct V_4 * V_43 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1292 = 0 , V_440 , V_159 ;
T_4 V_1211 ;
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_17 -> V_140 == V_153 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_1293 )
return - V_558 ;
if ( V_7 -> V_1294 || V_7 -> V_1295 ) {
V_35 = - V_562 ;
goto V_1296;
}
if ( V_30 -> V_5 [ V_1297 ] ) {
V_440 = F_255 (
V_30 -> V_5 [ V_1297 ] ) ;
if ( ! V_440 ) {
V_35 = - V_16 ;
goto V_1296;
}
} else {
V_440 = F_263 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1298 ] )
F_36 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1292 ++ ;
if ( V_1292 > V_18 -> V_385 ) {
V_35 = - V_16 ;
goto V_1296;
}
if ( V_30 -> V_5 [ V_749 ] )
V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
else
V_1211 = 0 ;
if ( V_1211 > V_18 -> V_389 ) {
V_35 = - V_16 ;
goto V_1296;
}
V_1291 = F_37 ( sizeof( * V_1291 )
+ sizeof( * V_1291 -> V_1299 ) * V_1292
+ sizeof( * V_1291 -> V_441 ) * V_440
+ V_1211 , V_134 ) ;
if ( ! V_1291 ) {
V_35 = - V_135 ;
goto V_1296;
}
if ( V_1292 )
V_1291 -> V_1299 = ( void * ) & V_1291 -> V_441 [ V_440 ] ;
V_1291 -> V_1292 = V_1292 ;
if ( V_1211 ) {
if ( V_1292 )
V_1291 -> V_1210 = ( void * ) ( V_1291 -> V_1299 + V_1292 ) ;
else
V_1291 -> V_1210 = ( void * ) ( V_1291 -> V_441 + V_440 ) ;
}
V_159 = 0 ;
if ( V_30 -> V_5 [ V_1297 ] ) {
F_36 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_52 * V_53 ;
V_53 = F_43 ( V_18 , F_4 ( V_43 ) ) ;
if ( ! V_53 ) {
V_35 = - V_16 ;
goto V_1300;
}
if ( V_53 -> V_49 & V_60 )
continue;
V_1291 -> V_441 [ V_159 ] = V_53 ;
V_159 ++ ;
}
} else {
enum V_365 V_366 ;
for ( V_366 = 0 ; V_366 < V_436 ; V_366 ++ ) {
int V_161 ;
if ( ! V_18 -> V_437 [ V_366 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_437 [ V_366 ] -> V_440 ; V_161 ++ ) {
struct V_52 * V_53 ;
V_53 = & V_18 -> V_437 [ V_366 ] -> V_441 [ V_161 ] ;
if ( V_53 -> V_49 & V_60 )
continue;
V_1291 -> V_441 [ V_159 ] = V_53 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1300;
}
V_1291 -> V_440 = V_159 ;
V_159 = 0 ;
if ( V_1292 ) {
F_36 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_22 ( V_43 ) > V_637 ) {
V_35 = - V_16 ;
goto V_1300;
}
V_1291 -> V_1299 [ V_159 ] . V_610 = F_22 ( V_43 ) ;
memcpy ( V_1291 -> V_1299 [ V_159 ] . V_612 , F_21 ( V_43 ) , F_22 ( V_43 ) ) ;
V_159 ++ ;
}
}
if ( V_30 -> V_5 [ V_749 ] ) {
V_1291 -> V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
memcpy ( ( void * ) V_1291 -> V_1210 ,
F_21 ( V_30 -> V_5 [ V_749 ] ) ,
V_1291 -> V_1211 ) ;
}
for ( V_159 = 0 ; V_159 < V_436 ; V_159 ++ )
if ( V_18 -> V_437 [ V_159 ] )
V_1291 -> V_702 [ V_159 ] =
( 1 << V_18 -> V_437 [ V_159 ] -> V_263 ) - 1 ;
if ( V_30 -> V_5 [ V_1301 ] ) {
F_36 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_365 V_366 = F_155 ( V_43 ) ;
if ( V_366 < 0 || V_366 >= V_436 ) {
V_35 = - V_16 ;
goto V_1300;
}
if ( ! V_18 -> V_437 [ V_366 ] )
continue;
V_35 = F_264 ( V_18 -> V_437 [ V_366 ] ,
F_21 ( V_43 ) ,
F_22 ( V_43 ) ,
& V_1291 -> V_702 [ V_366 ] ) ;
if ( V_35 )
goto V_1300;
}
}
if ( V_30 -> V_5 [ V_1302 ] ) {
if ( ! F_116 ( V_18 ,
V_1303 ) ) {
V_35 = - V_558 ;
goto V_1300;
}
V_1291 -> V_1304 =
F_79 ( V_30 -> V_5 [ V_1302 ] ) ;
V_1291 -> V_1305 =
F_169 ( V_30 -> V_5 [ V_1306 ] ) ;
}
if ( V_30 -> V_5 [ V_1307 ] ) {
V_1291 -> V_49 = F_4 (
V_30 -> V_5 [ V_1307 ] ) ;
if ( ( V_1291 -> V_49 & V_1308 ) &&
! ( V_18 -> V_367 & V_1309 ) ) {
V_35 = - V_558 ;
goto V_1300;
}
if ( V_1291 -> V_49 & V_1310 ) {
if ( ! ( V_18 -> V_367 &
V_1311 ) ) {
V_35 = - V_558 ;
goto V_1300;
}
if ( V_17 -> V_148 ) {
V_35 = - V_558 ;
goto V_1300;
}
V_35 = F_259 ( V_30 -> V_5 ,
V_1291 -> V_672 ,
V_1291 -> V_1288 ) ;
if ( V_35 )
goto V_1300;
}
}
V_1291 -> V_1312 =
F_169 ( V_30 -> V_5 [ V_1313 ] ) ;
if ( V_30 -> V_5 [ V_1314 ] )
memcpy ( V_1291 -> V_564 ,
F_21 ( V_30 -> V_5 [ V_1314 ] ) , V_605 ) ;
else if ( ! ( V_1291 -> V_49 & V_1310 ) &&
V_30 -> V_5 [ V_565 ] )
memcpy ( V_1291 -> V_564 , F_21 ( V_30 -> V_5 [ V_565 ] ) ,
V_605 ) ;
else
F_265 ( V_1291 -> V_564 ) ;
V_1291 -> V_17 = V_17 ;
V_1291 -> V_18 = & V_7 -> V_18 ;
V_1291 -> V_1315 = V_1316 ;
V_7 -> V_1294 = V_1291 ;
V_35 = F_266 ( V_7 , V_1291 ) ;
if ( ! V_35 ) {
F_267 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_268 ( V_17 -> V_19 ) ;
} else {
V_1300:
V_7 -> V_1294 = NULL ;
F_39 ( V_1291 ) ;
}
V_1296:
return V_35 ;
}
static int F_269 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
if ( ! V_7 -> V_327 -> V_1317 )
return - V_558 ;
if ( V_7 -> V_1295 )
return 0 ;
if ( ! V_7 -> V_1294 )
return - V_678 ;
F_270 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_271 ( struct V_18 * V_18 , int V_1318 ,
struct V_1319 * V_1291 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_159 = 0 ;
struct V_4 * V_43 ;
if ( ! V_5 [ V_1320 ] ) {
V_22 V_1321 ;
V_1321 = F_4 ( V_5 [ V_1322 ] ) ;
if ( ! V_1321 )
return - V_16 ;
V_1291 -> V_1323 [ 0 ] . V_1321 =
F_272 ( V_1321 , V_1324 ) ;
if ( ! V_1291 -> V_1323 [ 0 ] . V_1321 )
return - V_16 ;
if ( V_1291 -> V_1323 [ 0 ] . V_1321 >
V_18 -> V_397 )
V_1291 -> V_1323 [ 0 ] . V_1321 =
V_18 -> V_397 ;
return 0 ;
}
F_36 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1325 [ V_1326 + 1 ] ;
if ( F_60 ( V_159 >= V_1318 ) )
return - V_16 ;
V_35 = F_31 ( V_1325 , V_1326 ,
V_43 , V_1327 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1325 [ V_1328 ] )
return - V_16 ;
V_1291 -> V_1323 [ V_159 ] . V_1321 =
F_4 ( V_1325 [ V_1328 ] ) ;
if ( ! V_1291 -> V_1323 [ V_159 ] . V_1321 ||
V_1291 -> V_1323 [ V_159 ] . V_1321 >
V_18 -> V_397 )
return - V_16 ;
if ( V_1325 [ V_1329 ] ) {
V_1291 -> V_1323 [ V_159 ] . V_1330 =
F_4 ( V_1325 [ V_1329 ] ) ;
if ( ! V_1291 -> V_1323 [ V_159 ] . V_1330 ||
( V_1291 -> V_1323 [ V_159 ] . V_1330 >
V_18 -> V_399 ) )
return - V_16 ;
} else if ( V_159 < V_1318 - 1 ) {
return - V_16 ;
}
V_159 ++ ;
}
if ( V_1291 -> V_1323 [ V_1318 - 1 ] . V_1330 )
return - V_16 ;
return 0 ;
}
static struct V_1319 *
F_273 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 , int V_393 )
{
struct V_1319 * V_1291 ;
struct V_4 * V_43 ;
int V_35 , V_24 , V_1292 = 0 , V_1331 = 0 , V_440 , V_159 , V_1318 = 0 ;
enum V_365 V_366 ;
T_4 V_1211 ;
struct V_4 * V_93 [ V_1332 + 1 ] ;
T_7 V_1333 = V_1334 ;
if ( ! F_20 ( V_5 [ V_749 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1297 ] ) {
V_440 = F_255 (
V_5 [ V_1297 ] ) ;
if ( ! V_440 )
return F_3 ( - V_16 ) ;
} else {
V_440 = F_263 ( V_18 ) ;
}
if ( V_5 [ V_1298 ] )
F_36 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1292 ++ ;
if ( V_1292 > V_18 -> V_387 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1335 ] ) {
F_36 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1336 ;
V_35 = F_31 ( V_93 ,
V_1332 ,
V_43 , V_1337 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_93 [ V_1338 ] ) {
V_1331 ++ ;
continue;
}
V_1336 = V_93 [ V_1339 ] ;
if ( V_1336 )
V_1333 = F_230 ( V_1336 ) ;
}
}
if ( ! V_1331 && V_1333 != V_1334 )
V_1331 = 1 ;
if ( V_1331 > V_393 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_749 ] )
V_1211 = F_22 ( V_5 [ V_749 ] ) ;
else
V_1211 = 0 ;
if ( V_1211 > V_18 -> V_391 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1320 ] ) {
if ( V_5 [ V_1322 ] )
return F_3 ( - V_16 ) ;
F_36 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1318 ++ ;
} else {
if ( ! V_5 [ V_1322 ] )
return F_3 ( - V_16 ) ;
V_1318 = 1 ;
}
if ( ! V_1318 || V_1318 > V_18 -> V_395 )
return F_3 ( - V_16 ) ;
if ( ! F_116 (
V_18 , V_1340 ) &&
( V_5 [ V_1341 ] ||
V_5 [ V_1342 ] ) )
return F_3 ( - V_16 ) ;
V_1291 = F_37 ( sizeof( * V_1291 )
+ sizeof( * V_1291 -> V_1299 ) * V_1292
+ sizeof( * V_1291 -> V_1343 ) * V_1331
+ sizeof( * V_1291 -> V_1323 ) * V_1318
+ sizeof( * V_1291 -> V_441 ) * V_440
+ V_1211 , V_134 ) ;
if ( ! V_1291 )
return F_3 ( - V_135 ) ;
if ( V_1292 )
V_1291 -> V_1299 = ( void * ) & V_1291 -> V_441 [ V_440 ] ;
V_1291 -> V_1292 = V_1292 ;
if ( V_1211 ) {
if ( V_1292 )
V_1291 -> V_1210 = ( void * ) ( V_1291 -> V_1299 + V_1292 ) ;
else
V_1291 -> V_1210 = ( void * ) ( V_1291 -> V_441 + V_440 ) ;
}
if ( V_1331 ) {
if ( V_1291 -> V_1210 )
V_1291 -> V_1343 = ( void * ) ( V_1291 -> V_1210 + V_1211 ) ;
else if ( V_1292 )
V_1291 -> V_1343 =
( void * ) ( V_1291 -> V_1299 + V_1292 ) ;
else
V_1291 -> V_1343 =
( void * ) ( V_1291 -> V_441 + V_440 ) ;
}
V_1291 -> V_1331 = V_1331 ;
if ( V_1331 )
V_1291 -> V_1323 = ( void * ) ( V_1291 -> V_1343 +
V_1331 ) ;
else if ( V_1291 -> V_1210 )
V_1291 -> V_1323 = ( void * ) ( V_1291 -> V_1210 + V_1211 ) ;
else if ( V_1292 )
V_1291 -> V_1323 = ( void * ) ( V_1291 -> V_1299 + V_1292 ) ;
else
V_1291 -> V_1323 = ( void * ) ( V_1291 -> V_441 + V_440 ) ;
V_1291 -> V_1344 = V_1318 ;
V_159 = 0 ;
if ( V_5 [ V_1297 ] ) {
F_36 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_52 * V_53 ;
V_53 = F_43 ( V_18 , F_4 ( V_43 ) ) ;
if ( ! V_53 ) {
V_35 = - V_16 ;
goto V_1300;
}
if ( V_53 -> V_49 & V_60 )
continue;
V_1291 -> V_441 [ V_159 ] = V_53 ;
V_159 ++ ;
}
} else {
for ( V_366 = 0 ; V_366 < V_436 ; V_366 ++ ) {
int V_161 ;
if ( ! V_18 -> V_437 [ V_366 ] )
continue;
for ( V_161 = 0 ; V_161 < V_18 -> V_437 [ V_366 ] -> V_440 ; V_161 ++ ) {
struct V_52 * V_53 ;
V_53 = & V_18 -> V_437 [ V_366 ] -> V_441 [ V_161 ] ;
if ( V_53 -> V_49 & V_60 )
continue;
V_1291 -> V_441 [ V_159 ] = V_53 ;
V_159 ++ ;
}
}
}
if ( ! V_159 ) {
V_35 = - V_16 ;
goto V_1300;
}
V_1291 -> V_440 = V_159 ;
V_159 = 0 ;
if ( V_1292 ) {
F_36 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_22 ( V_43 ) > V_637 ) {
V_35 = - V_16 ;
goto V_1300;
}
V_1291 -> V_1299 [ V_159 ] . V_610 = F_22 ( V_43 ) ;
memcpy ( V_1291 -> V_1299 [ V_159 ] . V_612 , F_21 ( V_43 ) ,
F_22 ( V_43 ) ) ;
V_159 ++ ;
}
}
V_159 = 0 ;
if ( V_5 [ V_1335 ] ) {
F_36 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_612 , * V_1336 ;
V_35 = F_31 ( V_93 ,
V_1332 ,
V_43 , V_1337 ) ;
if ( V_35 )
goto V_1300;
V_612 = V_93 [ V_1338 ] ;
if ( V_612 ) {
if ( F_60 ( V_159 >= V_1331 ) ) {
V_35 = - V_16 ;
goto V_1300;
}
if ( F_22 ( V_612 ) > V_637 ) {
V_35 = - V_16 ;
goto V_1300;
}
memcpy ( V_1291 -> V_1343 [ V_159 ] . V_612 . V_612 ,
F_21 ( V_612 ) , F_22 ( V_612 ) ) ;
V_1291 -> V_1343 [ V_159 ] . V_612 . V_610 =
F_22 ( V_612 ) ;
V_1291 -> V_1343 [ V_159 ] . V_1345 =
V_1333 ;
V_1336 = V_93 [ V_1339 ] ;
if ( V_1336 )
V_1291 -> V_1343 [ V_159 ] . V_1345 =
F_230 ( V_1336 ) ;
}
V_159 ++ ;
}
if ( V_159 == 0 && V_1331 )
V_1291 -> V_1343 [ 0 ] . V_1345 = V_1333 ;
V_1291 -> V_1346 = V_1347 ;
for ( V_159 = 0 ; V_159 < V_1331 ; V_159 ++ )
V_1291 -> V_1346 =
V_1177 ( V_1291 -> V_1343 [ V_159 ] . V_1345 ,
V_1291 -> V_1346 ) ;
} else {
V_1291 -> V_1346 = V_1334 ;
}
if ( V_1211 ) {
V_1291 -> V_1211 = V_1211 ;
memcpy ( ( void * ) V_1291 -> V_1210 ,
F_21 ( V_5 [ V_749 ] ) ,
V_1291 -> V_1211 ) ;
}
if ( V_5 [ V_1307 ] ) {
V_1291 -> V_49 = F_4 (
V_5 [ V_1307 ] ) ;
if ( ( V_1291 -> V_49 & V_1308 ) &&
! ( V_18 -> V_367 & V_1309 ) ) {
V_35 = - V_558 ;
goto V_1300;
}
if ( V_1291 -> V_49 & V_1310 ) {
V_22 V_1348 = V_1349 ;
if ( ! V_17 )
V_1348 = V_1350 ;
if ( ! ( V_18 -> V_367 & V_1348 ) ) {
V_35 = - V_558 ;
goto V_1300;
}
if ( V_17 && V_17 -> V_148 ) {
V_35 = - V_558 ;
goto V_1300;
}
V_35 = F_259 ( V_5 , V_1291 -> V_672 ,
V_1291 -> V_1288 ) ;
if ( V_35 )
goto V_1300;
}
}
if ( V_5 [ V_1351 ] )
V_1291 -> V_1352 =
F_4 ( V_5 [ V_1351 ] ) ;
if ( V_5 [ V_1341 ] ) {
V_1291 -> V_1353 = F_216 (
V_5 [ V_1341 ] ) ;
V_1291 -> V_1354 = true ;
}
if ( V_1291 -> V_1354 &&
V_5 [ V_1342 ] ) {
struct V_1284 * V_1355 ;
V_1355 = F_21 (
V_5 [ V_1342 ] ) ;
V_1291 -> V_1355 . V_366 = V_1355 -> V_366 ;
V_1291 -> V_1355 . V_1287 = V_1355 -> V_1287 ;
if ( ! F_256 ( V_18 , V_1291 -> V_1355 . V_366 ) ) {
V_35 = - V_16 ;
goto V_1300;
}
}
V_35 = F_271 ( V_18 , V_1318 , V_1291 , V_5 ) ;
if ( V_35 )
goto V_1300;
V_1291 -> V_1315 = V_1316 ;
return V_1291 ;
V_1300:
F_39 ( V_1291 ) ;
return F_3 ( V_35 ) ;
}
static int F_274 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_1319 * V_1356 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_49 & V_337 ) ||
! V_7 -> V_327 -> V_338 )
return - V_558 ;
if ( V_7 -> V_1356 )
return - V_1108 ;
V_1356 = F_273 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ,
V_7 -> V_18 . V_393 ) ;
V_35 = F_275 ( V_1356 ) ;
if ( V_35 )
goto V_963;
V_35 = F_276 ( V_7 , V_557 , V_1356 ) ;
if ( V_35 )
goto V_1300;
V_1356 -> V_557 = V_557 ;
V_1356 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_656 ] )
V_1356 -> V_657 = V_30 -> V_522 ;
F_277 ( V_7 -> V_1356 , V_1356 ) ;
F_278 ( V_7 , V_557 ,
V_1357 ) ;
return 0 ;
V_1300:
F_39 ( V_1356 ) ;
V_963:
return V_35 ;
}
static int F_279 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_49 & V_337 ) ||
! V_7 -> V_327 -> V_1358 )
return - V_558 ;
return F_280 ( V_7 , false ) ;
}
static int F_281 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_537 V_538 ;
enum V_1260 V_1225 ;
unsigned int V_1359 ;
int V_35 ;
V_1225 = F_282 ( V_17 -> V_18 ) ;
if ( V_1225 == V_1261 )
return - V_16 ;
V_35 = F_81 ( V_7 , V_30 , & V_538 ) ;
if ( V_35 )
return V_35 ;
if ( F_283 ( V_557 ) )
return - V_562 ;
if ( V_17 -> V_1360 )
return - V_562 ;
V_35 = F_284 ( V_17 -> V_18 , & V_538 ,
V_17 -> V_140 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_285 ( V_17 -> V_18 , & V_538 ) )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_1361 )
return - V_558 ;
V_1359 = F_286 ( & V_7 -> V_18 , & V_538 ) ;
if ( F_60 ( ! V_1359 ) )
V_1359 = V_1362 ;
V_35 = F_287 ( V_7 , V_557 , & V_538 , V_1359 ) ;
if ( ! V_35 ) {
V_17 -> V_538 = V_538 ;
V_17 -> V_1360 = true ;
V_17 -> V_1363 = V_1316 ;
V_17 -> V_1359 = V_1359 ;
}
return V_35 ;
}
static int F_288 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_1364 V_138 ;
static struct V_4 * V_1365 [ V_1366 + 1 ] ;
int V_35 ;
bool V_1367 = false ;
int V_45 , V_159 ;
V_22 V_1368 ;
if ( ! V_7 -> V_327 -> V_448 ||
! ( V_7 -> V_18 . V_49 & V_447 ) )
return - V_558 ;
switch ( V_557 -> V_28 -> V_140 ) {
case V_141 :
case V_143 :
V_1367 = true ;
if ( ! V_17 -> V_559 )
return - V_1369 ;
break;
case V_145 :
if ( ! V_17 -> V_610 )
return - V_1369 ;
break;
case V_144 :
if ( ! V_17 -> V_1118 )
return - V_1369 ;
break;
default:
return - V_558 ;
}
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
if ( ! V_30 -> V_5 [ V_540 ] ||
! V_30 -> V_5 [ V_1370 ] )
return - V_16 ;
if ( V_1367 && ! V_30 -> V_5 [ V_1371 ] )
return - V_16 ;
V_1368 = F_4 ( V_30 -> V_5 [ V_1370 ] ) ;
if ( V_1368 > 255 )
return - V_16 ;
V_138 . V_1372 = V_1368 ;
if ( ! V_1367 )
goto V_1373;
V_35 = F_160 ( V_30 -> V_5 , & V_138 . V_1374 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_31 ( V_1365 , V_1366 ,
V_30 -> V_5 [ V_1371 ] ,
V_41 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_160 ( V_1365 , & V_138 . V_1375 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1365 [ V_1376 ] )
return - V_16 ;
V_45 = F_22 ( V_1365 [ V_1376 ] ) ;
if ( ! V_45 || ( V_45 % sizeof( T_3 ) ) )
return - V_16 ;
V_138 . V_1377 = V_45 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_495 &&
( V_138 . V_1377 >
V_7 -> V_18 . V_495 ) )
return - V_16 ;
V_138 . V_1378 =
F_21 ( V_1365 [ V_1376 ] ) ;
for ( V_159 = 0 ; V_159 < V_138 . V_1377 ; V_159 ++ ) {
T_3 V_1379 = V_138 . V_1378 [ V_159 ] ;
if ( V_1379 >= V_138 . V_1375 . V_756 )
return - V_16 ;
if ( V_138 . V_1375 . V_755 [ V_1379 ] != V_138 . V_1372 )
return - V_16 ;
}
if ( V_1365 [ V_1380 ] ) {
V_45 = F_22 ( V_1365 [ V_1380 ] ) ;
if ( ! V_45 || ( V_45 % sizeof( T_3 ) ) )
return - V_16 ;
V_138 . V_1381 = V_45 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_495 &&
( V_138 . V_1381 >
V_7 -> V_18 . V_495 ) )
return - V_16 ;
V_138 . V_1382 =
F_21 ( V_1365 [ V_1380 ] ) ;
for ( V_159 = 0 ; V_159 < V_138 . V_1381 ; V_159 ++ ) {
T_3 V_1379 = V_138 . V_1382 [ V_159 ] ;
if ( V_1379 >= V_138 . V_1375 . V_765 )
return - V_16 ;
if ( V_138 . V_1375 . V_764 [ V_1379 ] !=
V_138 . V_1372 )
return - V_16 ;
}
}
V_1373:
V_35 = F_81 ( V_7 , V_30 , & V_138 . V_538 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_138 . V_538 ,
V_17 -> V_140 ) )
return - V_16 ;
V_35 = F_284 ( V_17 -> V_18 ,
& V_138 . V_538 ,
V_17 -> V_140 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_138 . V_1383 = true ;
if ( V_30 -> V_5 [ V_1384 ] )
V_138 . V_1385 = true ;
F_113 ( V_17 ) ;
V_35 = F_289 ( V_7 , V_557 , & V_138 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_290 ( struct V_31 * V_51 , struct V_33 * V_34 ,
V_22 V_48 , int V_49 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1386 * V_1387 )
{
struct V_1388 * V_429 = & V_1387 -> V_1389 ;
const struct V_1390 * V_773 ;
void * V_359 ;
struct V_4 * V_1391 ;
F_41 ( V_17 ) ;
V_359 = F_23 ( V_51 , F_72 ( V_34 -> V_32 ) . V_47 , V_48 , V_49 ,
V_1392 ) ;
if ( ! V_359 )
return - 1 ;
F_247 ( V_34 , V_359 , & V_38 ) ;
if ( F_26 ( V_51 , V_369 , V_7 -> V_1393 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_26 ( V_51 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_59;
if ( F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_59;
V_1391 = F_45 ( V_51 , V_1394 ) ;
if ( ! V_1391 )
goto V_59;
if ( ( ! F_291 ( V_429 -> V_564 ) &&
F_49 ( V_51 , V_1395 , V_605 , V_429 -> V_564 ) ) )
goto V_59;
F_243 () ;
if ( F_220 ( V_429 -> V_759 ) &&
F_27 ( V_51 , V_1396 ) )
goto V_1397;
V_773 = F_244 ( V_429 -> V_773 ) ;
if ( V_773 ) {
if ( F_104 ( V_51 , V_1398 , V_773 -> V_1399 ,
V_1400 ) )
goto V_1397;
if ( V_773 -> V_45 && F_49 ( V_51 , V_1401 ,
V_773 -> V_45 , V_773 -> V_139 ) )
goto V_1397;
}
V_773 = F_244 ( V_429 -> V_757 ) ;
if ( V_773 && V_773 -> V_1402 ) {
if ( F_104 ( V_51 , V_1403 , V_773 -> V_1399 ,
V_1400 ) )
goto V_1397;
if ( V_773 -> V_45 && F_49 ( V_51 , V_1404 ,
V_773 -> V_45 , V_773 -> V_139 ) )
goto V_1397;
}
F_245 () ;
if ( V_429 -> V_559 &&
F_53 ( V_51 , V_1405 , V_429 -> V_559 ) )
goto V_59;
if ( F_53 ( V_51 , V_1406 , V_429 -> V_1025 ) ||
F_26 ( V_51 , V_1407 , V_429 -> V_1408 -> V_58 ) ||
F_26 ( V_51 , V_1409 , V_429 -> V_1410 ) ||
F_26 ( V_51 , V_1411 ,
F_292 ( V_1316 - V_1387 -> V_1412 ) ) )
goto V_59;
if ( V_1387 -> V_1413 &&
( F_104 ( V_51 , V_1414 ,
V_1387 -> V_1413 , V_1400 ) ||
F_49 ( V_51 , V_1415 , V_605 ,
V_1387 -> V_1416 ) ) )
goto V_59;
if ( V_1387 -> V_1417 &&
F_104 ( V_51 , V_1418 ,
V_1387 -> V_1417 , V_1400 ) )
goto V_59;
switch ( V_7 -> V_18 . V_896 ) {
case V_897 :
if ( F_26 ( V_51 , V_1419 , V_429 -> signal ) )
goto V_59;
break;
case V_1420 :
if ( F_54 ( V_51 , V_1421 , V_429 -> signal ) )
goto V_59;
break;
default:
break;
}
switch ( V_17 -> V_140 ) {
case V_147 :
case V_146 :
if ( V_1387 == V_17 -> V_148 &&
F_26 ( V_51 , V_1422 ,
V_1423 ) )
goto V_59;
break;
case V_145 :
if ( V_1387 == V_17 -> V_148 &&
F_26 ( V_51 , V_1422 ,
V_1424 ) )
goto V_59;
break;
default:
break;
}
F_46 ( V_51 , V_1391 ) ;
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_1397:
F_245 () ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int F_293 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1386 * V_1293 ;
struct V_1 * V_17 ;
int V_517 = V_34 -> args [ 2 ] , V_103 = 0 ;
int V_35 ;
F_69 () ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 ) {
F_70 () ;
return V_35 ;
}
F_113 ( V_17 ) ;
F_294 ( & V_7 -> V_1425 ) ;
F_295 ( V_7 ) ;
V_34 -> V_48 = V_7 -> V_1393 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_103 <= V_517 )
continue;
if ( F_290 ( V_32 , V_34 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_7 , V_17 , V_1293 ) < 0 ) {
V_103 -- ;
break;
}
}
F_296 ( & V_7 -> V_1425 ) ;
F_115 ( V_17 ) ;
V_34 -> args [ 2 ] = V_103 ;
F_70 () ;
return V_32 -> V_45 ;
}
static int F_297 ( struct V_31 * V_51 , V_22 V_47 , V_22 V_48 ,
int V_49 , struct V_25 * V_557 ,
bool V_1426 ,
struct V_1427 * V_1428 )
{
void * V_359 ;
struct V_4 * V_1429 ;
if ( ! V_1428 -> V_1408 && ! V_1426 )
return 0 ;
V_359 = F_23 ( V_51 , V_47 , V_48 , V_49 ,
V_1430 ) ;
if ( ! V_359 )
return - V_135 ;
if ( F_26 ( V_51 , V_10 , V_557 -> V_20 ) )
goto V_59;
V_1429 = F_45 ( V_51 , V_1431 ) ;
if ( ! V_1429 )
goto V_59;
if ( V_1428 -> V_1408 &&
F_26 ( V_51 , V_1432 ,
V_1428 -> V_1408 -> V_58 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1433 ) &&
F_54 ( V_51 , V_1434 , V_1428 -> V_1435 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1436 ) &&
F_27 ( V_51 , V_1437 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1438 ) &&
F_104 ( V_51 , V_1439 ,
V_1428 -> time , V_1440 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1441 ) &&
F_104 ( V_51 , V_1442 ,
V_1428 -> V_1443 , V_1440 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1444 ) &&
F_104 ( V_51 , V_1445 ,
V_1428 -> V_1446 , V_1440 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1447 ) &&
F_104 ( V_51 , V_1448 ,
V_1428 -> V_1449 , V_1440 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1450 ) &&
F_104 ( V_51 , V_1451 ,
V_1428 -> V_1452 , V_1440 ) )
goto V_59;
if ( ( V_1428 -> V_879 & V_1453 ) &&
F_104 ( V_51 , V_1454 ,
V_1428 -> V_1455 , V_1440 ) )
goto V_59;
F_46 ( V_51 , V_1429 ) ;
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int F_298 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_4 * * V_1456 = F_15 ( & V_38 ) ;
struct V_1427 V_1428 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1457 = V_34 -> args [ 2 ] ;
int V_429 ;
bool V_1458 ;
F_69 () ;
V_429 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_429 )
goto V_963;
V_1458 = V_1456 [ V_1459 ] ;
if ( ! V_17 -> V_19 ) {
V_429 = - V_16 ;
goto V_963;
}
if ( ! V_7 -> V_327 -> V_1460 ) {
V_429 = - V_558 ;
goto V_963;
}
while ( 1 ) {
V_429 = F_299 ( V_7 , V_17 -> V_19 , V_1457 , & V_1428 ) ;
if ( V_429 == - V_678 )
break;
if ( V_429 )
goto V_963;
if ( V_1428 . V_1408 &&
V_1428 . V_1408 -> V_49 & V_60 ) {
V_1457 ++ ;
continue;
}
if ( F_297 ( V_32 ,
F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_17 -> V_19 , V_1458 , & V_1428 ) < 0 )
goto V_618;
V_1457 ++ ;
}
V_618:
V_34 -> args [ 2 ] = V_1457 ;
V_429 = V_32 -> V_45 ;
V_963:
F_70 () ;
return V_429 ;
}
static bool F_300 ( V_22 V_1461 )
{
return ! ( V_1461 & ~ ( V_1462 |
V_1463 ) ) ;
}
static int F_301 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_52 * V_53 ;
const T_2 * V_564 , * V_612 , * V_1210 = NULL , * V_1464 = NULL ;
int V_35 , V_610 , V_1211 = 0 , V_1465 = 0 ;
enum V_778 V_779 ;
struct V_91 V_90 ;
bool V_1466 ;
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_800 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_611 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_540 ] )
return - V_16 ;
V_35 = F_34 ( V_30 , & V_90 ) ;
if ( V_35 )
return V_35 ;
if ( V_90 . V_103 >= 0 ) {
if ( V_90 . type != - 1 && V_90 . type != V_675 )
return - V_16 ;
if ( ! V_90 . V_105 . V_90 || ! V_90 . V_105 . V_106 )
return - V_16 ;
if ( ( V_90 . V_105 . V_110 != V_136 ||
V_90 . V_105 . V_106 != V_1467 ) &&
( V_90 . V_105 . V_110 != V_137 ||
V_90 . V_105 . V_106 != V_1468 ) )
return - V_16 ;
if ( V_90 . V_103 > 3 )
return - V_16 ;
} else {
V_90 . V_105 . V_106 = 0 ;
V_90 . V_105 . V_90 = NULL ;
}
if ( V_90 . V_103 >= 0 ) {
int V_159 ;
bool V_1469 = false ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_413 ; V_159 ++ ) {
if ( V_90 . V_105 . V_110 == V_7 -> V_18 . V_414 [ V_159 ] ) {
V_1469 = true ;
break;
}
}
if ( ! V_1469 )
return - V_16 ;
}
if ( ! V_7 -> V_327 -> V_298 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_53 = F_42 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_540 ] ) ;
if ( ! V_53 )
return - V_16 ;
V_612 = F_21 ( V_30 -> V_5 [ V_611 ] ) ;
V_610 = F_22 ( V_30 -> V_5 [ V_611 ] ) ;
if ( V_30 -> V_5 [ V_749 ] ) {
V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
}
V_779 = F_4 ( V_30 -> V_5 [ V_800 ] ) ;
if ( ! F_165 ( V_7 , V_779 , V_781 ) )
return - V_16 ;
if ( ( V_779 == V_783 ||
V_779 == V_785 ||
V_779 == V_786 ||
V_779 == V_787 ) &&
! V_30 -> V_5 [ V_1470 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1470 ] ) {
if ( V_779 != V_783 &&
V_779 != V_785 &&
V_779 != V_786 &&
V_779 != V_787 )
return - V_16 ;
V_1464 = F_21 ( V_30 -> V_5 [ V_1470 ] ) ;
V_1465 = F_22 ( V_30 -> V_5 [ V_1470 ] ) ;
if ( V_1465 < 4 )
return - V_16 ;
}
V_1466 = ! ! V_30 -> V_5 [ V_1471 ] ;
if ( V_1466 )
return 0 ;
F_113 ( V_557 -> V_28 ) ;
V_35 = F_302 ( V_7 , V_557 , V_53 , V_779 , V_564 ,
V_612 , V_610 , V_1210 , V_1211 ,
V_90 . V_105 . V_90 , V_90 . V_105 . V_106 , V_90 . V_103 ,
V_1464 , V_1465 ) ;
F_115 ( V_557 -> V_28 ) ;
return V_35 ;
}
static int F_168 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1472 * V_1473 ,
int V_1474 )
{
memset ( V_1473 , 0 , sizeof( * V_1473 ) ) ;
V_1473 -> V_1475 = V_30 -> V_5 [ V_1476 ] ;
if ( V_30 -> V_5 [ V_418 ] ) {
T_3 V_1477 ;
V_1477 = F_79 (
V_30 -> V_5 [ V_418 ] ) ;
V_1473 -> V_1478 = F_303 ( V_1477 ) ;
if ( ! ( V_7 -> V_18 . V_49 & V_417 ) &&
V_1477 != V_1479 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1480 ] )
V_1473 -> V_1481 = true ;
} else
V_1473 -> V_1478 = F_303 ( V_1479 ) ;
if ( V_30 -> V_5 [ V_1482 ] ) {
void * V_139 ;
int V_45 , V_159 ;
V_139 = F_21 ( V_30 -> V_5 [ V_1482 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_1482 ] ) ;
V_1473 -> V_1483 = V_45 / sizeof( V_22 ) ;
if ( V_45 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1473 -> V_1483 > V_1474 )
return - V_16 ;
memcpy ( V_1473 -> V_1484 , V_139 , V_45 ) ;
for ( V_159 = 0 ; V_159 < V_1473 -> V_1483 ; V_159 ++ )
if ( ! F_304 (
& V_7 -> V_18 ,
V_1473 -> V_1484 [ V_159 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1485 ] ) {
V_1473 -> V_1486 =
F_4 ( V_30 -> V_5 [ V_1485 ] ) ;
if ( ! F_304 ( & V_7 -> V_18 ,
V_1473 -> V_1486 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1487 ] ) {
V_1473 -> V_1461 =
F_4 ( V_30 -> V_5 [ V_1487 ] ) ;
if ( ! F_300 ( V_1473 -> V_1461 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1488 ] ) {
void * V_139 ;
int V_45 ;
V_139 = F_21 ( V_30 -> V_5 [ V_1488 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_1488 ] ) ;
V_1473 -> V_1489 = V_45 / sizeof( V_22 ) ;
if ( V_45 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1473 -> V_1489 > V_1490 )
return - V_16 ;
memcpy ( V_1473 -> V_1491 , V_139 , V_45 ) ;
}
return 0 ;
}
static int F_305 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_52 * V_53 ;
struct V_1492 V_1493 = {} ;
const T_2 * V_564 , * V_612 ;
int V_35 , V_610 = 0 ;
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_565 ] ||
! V_30 -> V_5 [ V_611 ] ||
! V_30 -> V_5 [ V_540 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_300 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_53 = F_42 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_540 ] ) ;
if ( ! V_53 )
return - V_16 ;
V_612 = F_21 ( V_30 -> V_5 [ V_611 ] ) ;
V_610 = F_22 ( V_30 -> V_5 [ V_611 ] ) ;
if ( V_30 -> V_5 [ V_749 ] ) {
V_1493 . V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_1493 . V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
}
if ( V_30 -> V_5 [ V_1494 ] ) {
enum V_1495 V_1496 =
F_4 ( V_30 -> V_5 [ V_1494 ] ) ;
if ( V_1496 == V_1497 )
V_1493 . V_1498 = true ;
else if ( V_1496 != V_1499 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1500 ] )
V_1493 . V_1501 = F_21 ( V_30 -> V_5 [ V_1500 ] ) ;
if ( F_169 ( V_30 -> V_5 [ V_1502 ] ) )
V_1493 . V_49 |= V_1503 ;
if ( V_30 -> V_5 [ V_471 ] )
memcpy ( & V_1493 . V_1504 ,
F_21 ( V_30 -> V_5 [ V_471 ] ) ,
sizeof( V_1493 . V_1504 ) ) ;
if ( V_30 -> V_5 [ V_1015 ] ) {
if ( ! V_30 -> V_5 [ V_471 ] )
return - V_16 ;
memcpy ( & V_1493 . V_985 ,
F_21 ( V_30 -> V_5 [ V_1015 ] ) ,
sizeof( V_1493 . V_985 ) ) ;
}
if ( F_169 ( V_30 -> V_5 [ V_1505 ] ) )
V_1493 . V_49 |= V_1506 ;
if ( V_30 -> V_5 [ V_480 ] )
memcpy ( & V_1493 . V_1507 ,
F_21 ( V_30 -> V_5 [ V_480 ] ) ,
sizeof( V_1493 . V_1507 ) ) ;
if ( V_30 -> V_5 [ V_1016 ] ) {
if ( ! V_30 -> V_5 [ V_480 ] )
return - V_16 ;
memcpy ( & V_1493 . V_986 ,
F_21 ( V_30 -> V_5 [ V_1016 ] ) ,
sizeof( V_1493 . V_986 ) ) ;
}
if ( F_169 ( V_30 -> V_5 [ V_1508 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_367 &
V_1509 ) &&
( V_7 -> V_18 . V_367 & V_1510 ) ) &&
! F_116 ( & V_7 -> V_18 ,
V_1511 ) )
return - V_16 ;
V_1493 . V_49 |= V_1512 ;
}
if ( V_30 -> V_5 [ V_1513 ] ) {
V_1493 . V_1514 = F_21 ( V_30 -> V_5 [ V_1513 ] ) ;
V_1493 . V_1515 = F_22 ( V_30 -> V_5 [ V_1513 ] ) ;
if ( ! V_30 -> V_5 [ V_1516 ] )
return - V_16 ;
V_1493 . V_1517 =
F_21 ( V_30 -> V_5 [ V_1516 ] ) ;
}
V_35 = F_168 ( V_7 , V_30 , & V_1493 . V_802 , 1 ) ;
if ( ! V_35 ) {
F_113 ( V_557 -> V_28 ) ;
V_35 = F_306 ( V_7 , V_557 , V_53 , V_564 ,
V_612 , V_610 , & V_1493 ) ;
if ( ! V_35 && V_30 -> V_5 [ V_656 ] ) {
V_557 -> V_28 -> V_1518 =
V_30 -> V_522 ;
memcpy ( V_557 -> V_28 -> V_1519 ,
V_564 , V_605 ) ;
}
F_115 ( V_557 -> V_28 ) ;
}
return V_35 ;
}
static int F_307 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
const T_2 * V_1210 = NULL , * V_564 ;
int V_1211 = 0 , V_35 ;
T_3 V_1052 ;
bool V_1466 ;
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1051 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_302 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_1052 = F_79 ( V_30 -> V_5 [ V_1051 ] ) ;
if ( V_1052 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_749 ] ) {
V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
}
V_1466 = ! ! V_30 -> V_5 [ V_1471 ] ;
F_113 ( V_557 -> V_28 ) ;
V_35 = F_308 ( V_7 , V_557 , V_564 , V_1210 , V_1211 , V_1052 ,
V_1466 ) ;
F_115 ( V_557 -> V_28 ) ;
return V_35 ;
}
static int F_309 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
const T_2 * V_1210 = NULL , * V_564 ;
int V_1211 = 0 , V_35 ;
T_3 V_1052 ;
bool V_1466 ;
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1051 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_304 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_1052 = F_79 ( V_30 -> V_5 [ V_1051 ] ) ;
if ( V_1052 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_749 ] ) {
V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
}
V_1466 = ! ! V_30 -> V_5 [ V_1471 ] ;
F_113 ( V_557 -> V_28 ) ;
V_35 = F_310 ( V_7 , V_557 , V_564 , V_1210 , V_1211 , V_1052 ,
V_1466 ) ;
F_115 ( V_557 -> V_28 ) ;
return V_35 ;
}
static bool
F_311 ( struct V_6 * V_7 ,
int V_1520 [ V_436 ] ,
int V_1521 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_366 , V_159 ;
for ( V_366 = 0 ; V_366 < V_436 ; V_366 ++ ) {
struct V_241 * V_242 ;
V_242 = V_18 -> V_437 [ V_366 ] ;
if ( ! V_242 )
continue;
for ( V_159 = 0 ; V_159 < V_242 -> V_263 ; V_159 ++ ) {
if ( V_242 -> V_264 [ V_159 ] . V_266 == V_1521 ) {
V_1520 [ V_366 ] = V_159 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_312 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1522 V_1523 ;
struct V_18 * V_18 ;
struct V_128 * V_1524 = NULL ;
int V_35 ;
memset ( & V_1523 , 0 , sizeof( V_1523 ) ) ;
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_611 ] ||
! F_22 ( V_30 -> V_5 [ V_611 ] ) )
return - V_16 ;
V_1523 . V_559 = 100 ;
if ( V_30 -> V_5 [ V_790 ] )
V_1523 . V_559 =
F_4 ( V_30 -> V_5 [ V_790 ] ) ;
V_35 = F_167 ( V_7 , V_145 ,
V_1523 . V_559 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_327 -> V_306 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_145 )
return - V_558 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_565 ] ) {
V_1523 . V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( ! F_122 ( V_1523 . V_564 ) )
return - V_16 ;
}
V_1523 . V_612 = F_21 ( V_30 -> V_5 [ V_611 ] ) ;
V_1523 . V_610 = F_22 ( V_30 -> V_5 [ V_611 ] ) ;
if ( V_30 -> V_5 [ V_749 ] ) {
V_1523 . V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_1523 . V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
}
V_35 = F_81 ( V_7 , V_30 , & V_1523 . V_538 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_313 ( & V_7 -> V_18 , & V_1523 . V_538 ,
V_145 ) )
return - V_16 ;
switch ( V_1523 . V_538 . V_541 ) {
case V_555 :
case V_556 :
case V_542 :
break;
case V_597 :
case V_598 :
if ( ! ( V_7 -> V_18 . V_367 & V_1525 ) )
return - V_16 ;
break;
case V_1526 :
case V_1527 :
case V_1528 :
if ( ! ( V_7 -> V_18 . V_367 & V_1525 ) )
return - V_16 ;
if ( ! F_116 ( & V_7 -> V_18 ,
V_1529 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1523 . V_1530 = ! ! V_30 -> V_5 [ V_1531 ] ;
V_1523 . V_798 = ! ! V_30 -> V_5 [ V_799 ] ;
if ( V_30 -> V_5 [ V_1099 ] ) {
T_2 * V_702 =
F_21 ( V_30 -> V_5 [ V_1099 ] ) ;
int V_1532 =
F_22 ( V_30 -> V_5 [ V_1099 ] ) ;
struct V_241 * V_242 =
V_18 -> V_437 [ V_1523 . V_538 . V_53 -> V_366 ] ;
V_35 = F_264 ( V_242 , V_702 , V_1532 ,
& V_1523 . V_1100 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_471 ] )
memcpy ( & V_1523 . V_1504 ,
F_21 ( V_30 -> V_5 [ V_471 ] ) ,
sizeof( V_1523 . V_1504 ) ) ;
if ( V_30 -> V_5 [ V_1015 ] ) {
if ( ! V_30 -> V_5 [ V_471 ] )
return - V_16 ;
memcpy ( & V_1523 . V_985 ,
F_21 ( V_30 -> V_5 [ V_1015 ] ) ,
sizeof( V_1523 . V_985 ) ) ;
}
if ( V_30 -> V_5 [ V_1533 ] &&
! F_311 ( V_7 , V_1523 . V_1520 ,
F_4 ( V_30 -> V_5 [ V_1533 ] ) ) )
return - V_16 ;
if ( V_1523 . V_798 && V_30 -> V_5 [ V_1534 ] ) {
bool V_130 = false ;
V_1524 = F_35 ( V_7 ,
V_30 -> V_5 [ V_1534 ] ,
& V_130 ) ;
if ( F_17 ( V_1524 ) )
return F_18 ( V_1524 ) ;
if ( ( V_1523 . V_538 . V_541 != V_542 ) &&
V_130 ) {
F_314 ( V_1524 ) ;
return - V_16 ;
}
}
V_1523 . V_1475 =
F_169 ( V_30 -> V_5 [ V_1476 ] ) ;
V_1523 . V_1535 =
F_169 ( V_30 -> V_5 [ V_1536 ] ) ;
V_35 = F_315 ( V_7 , V_557 , & V_1523 , V_1524 ) ;
if ( V_35 )
F_314 ( V_1524 ) ;
return V_35 ;
}
static int F_316 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
if ( ! V_7 -> V_327 -> V_1537 )
return - V_558 ;
if ( V_557 -> V_28 -> V_140 != V_145 )
return - V_558 ;
return F_317 ( V_7 , V_557 , false ) ;
}
static int F_318 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
int V_1520 [ V_436 ] ;
V_22 V_1538 ;
int V_35 ;
if ( V_557 -> V_28 -> V_140 != V_145 &&
V_557 -> V_28 -> V_140 != V_144 &&
V_557 -> V_28 -> V_140 != V_151 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_348 )
return - V_558 ;
memset ( V_1520 , 0 , sizeof( V_1520 ) ) ;
if ( ! V_30 -> V_5 [ V_1533 ] )
return - V_16 ;
V_1538 = F_4 ( V_30 -> V_5 [ V_1533 ] ) ;
if ( ! F_311 ( V_7 , V_1520 , V_1538 ) )
return - V_16 ;
V_35 = F_319 ( V_7 , V_557 , V_1520 ) ;
return V_35 ;
}
static struct V_31 *
F_320 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1539 ,
V_22 V_47 , V_22 V_48 , enum V_356 V_50 ,
enum V_844 V_43 ,
const struct V_487 * V_30 ,
T_10 V_1540 )
{
struct V_31 * V_32 ;
void * V_359 ;
struct V_4 * V_139 ;
V_32 = F_75 ( V_1539 + 100 , V_1540 ) ;
if ( ! V_32 )
return NULL ;
V_359 = F_23 ( V_32 , V_47 , V_48 , 0 , V_50 ) ;
if ( ! V_359 ) {
F_321 ( V_32 ) ;
return NULL ;
}
if ( F_26 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_30 ) {
if ( F_26 ( V_32 , V_1541 ,
V_30 -> V_1542 ) )
goto V_59;
if ( F_26 ( V_32 , V_1543 ,
V_30 -> V_1544 ) )
goto V_59;
}
if ( V_17 ) {
if ( F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) , V_604 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_26 ( V_32 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_59;
}
V_139 = F_45 ( V_32 , V_43 ) ;
if ( ! V_139 )
goto V_59;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_359 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_139 ;
return V_32 ;
V_59:
F_321 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_322 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_356 V_50 ,
enum V_844 V_43 ,
int V_1545 ,
int V_1539 , T_10 V_1540 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_487 * V_30 ;
switch ( V_50 ) {
case V_1546 :
if ( F_60 ( V_1545 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1547 :
if ( F_60 ( V_1545 < 0 ||
V_1545 >= V_18 -> V_491 ) )
return NULL ;
V_30 = & V_18 -> V_493 [ V_1545 ] ;
break;
default:
F_60 ( 1 ) ;
return NULL ;
}
return F_320 ( V_7 , V_17 , V_1539 , 0 , 0 ,
V_50 , V_43 , V_30 , V_1540 ) ;
}
void F_323 ( struct V_31 * V_32 , T_10 V_1540 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_359 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_139 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1548 V_1549 = V_1550 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_46 ( V_32 , V_139 ) ;
F_65 ( V_32 , V_359 ) ;
if ( V_139 -> F_155 == V_489 )
V_1549 = V_1551 ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1549 , V_1540 ) ;
}
static int F_325 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_95 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_327 -> V_350 )
return - V_558 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1552 ] )
return - V_16 ;
V_7 -> V_1553 = V_30 ;
V_35 = F_326 ( V_7 , V_17 ,
F_21 ( V_30 -> V_5 [ V_1552 ] ) ,
F_22 ( V_30 -> V_5 [ V_1552 ] ) ) ;
V_7 -> V_1553 = NULL ;
return V_35 ;
}
static int F_327 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1554 ;
void * V_139 = NULL ;
int V_1555 = 0 ;
F_69 () ;
if ( V_34 -> args [ 0 ] ) {
V_1554 = V_34 -> args [ 0 ] - 1 ;
V_7 = F_9 ( V_1554 ) ;
if ( ! V_7 ) {
V_35 = - V_678 ;
goto V_963;
}
} else {
struct V_4 * * V_1456 = F_15 ( & V_38 ) ;
V_35 = F_14 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_1456 , V_38 . V_40 , V_41 ) ;
if ( V_35 )
goto V_963;
V_7 = F_8 ( F_16 ( V_32 -> V_42 ) , V_1456 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_963;
}
V_1554 = V_7 -> V_14 ;
if ( V_1456 [ V_1552 ] )
V_34 -> args [ 1 ] = ( long ) V_1456 [ V_1552 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_139 = F_21 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1555 = F_22 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
if ( ! V_7 -> V_327 -> V_1556 ) {
V_35 = - V_558 ;
goto V_963;
}
while ( 1 ) {
void * V_359 = F_23 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_1546 ) ;
struct V_4 * V_1557 ;
if ( ! V_359 )
break;
if ( F_26 ( V_32 , V_26 , V_1554 ) ) {
F_66 ( V_32 , V_359 ) ;
break;
}
V_1557 = F_45 ( V_32 , V_1552 ) ;
if ( ! V_1557 ) {
F_66 ( V_32 , V_359 ) ;
break;
}
V_35 = F_328 ( V_7 , V_32 , V_34 , V_139 , V_1555 ) ;
F_46 ( V_32 , V_1557 ) ;
if ( V_35 == - V_89 || V_35 == - V_678 ) {
F_66 ( V_32 , V_359 ) ;
break;
} else if ( V_35 ) {
F_66 ( V_32 , V_359 ) ;
goto V_963;
}
F_65 ( V_32 , V_359 ) ;
}
V_35 = V_32 -> V_45 ;
V_34 -> args [ 0 ] = V_1554 + 1 ;
V_963:
F_70 () ;
return V_35 ;
}
static int F_329 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1558 V_352 ;
struct V_18 * V_18 ;
struct V_128 * V_1524 = NULL ;
int V_35 ;
memset ( & V_352 , 0 , sizeof( V_352 ) ) ;
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_611 ] ||
! F_22 ( V_30 -> V_5 [ V_611 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_800 ] ) {
V_352 . V_779 =
F_4 ( V_30 -> V_5 [ V_800 ] ) ;
if ( ! F_165 ( V_7 , V_352 . V_779 ,
V_353 ) )
return - V_16 ;
} else
V_352 . V_779 = V_801 ;
V_352 . V_798 = V_30 -> V_5 [ V_799 ] ;
V_35 = F_168 ( V_7 , V_30 , & V_352 . V_802 ,
V_803 ) ;
if ( V_35 )
return V_35 ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
V_18 = & V_7 -> V_18 ;
V_352 . V_1559 = - 1 ;
if ( V_30 -> V_5 [ V_1560 ] &&
( V_18 -> V_49 & V_406 ) ) {
V_352 . V_1559 =
F_79 ( V_30 -> V_5 [ V_1560 ] ) ;
}
if ( V_30 -> V_5 [ V_565 ] )
V_352 . V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
else if ( V_30 -> V_5 [ V_1561 ] )
V_352 . V_1562 =
F_21 ( V_30 -> V_5 [ V_1561 ] ) ;
V_352 . V_612 = F_21 ( V_30 -> V_5 [ V_611 ] ) ;
V_352 . V_610 = F_22 ( V_30 -> V_5 [ V_611 ] ) ;
if ( V_30 -> V_5 [ V_749 ] ) {
V_352 . V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_352 . V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
}
if ( V_30 -> V_5 [ V_1494 ] ) {
V_352 . V_1496 = F_4 ( V_30 -> V_5 [ V_1494 ] ) ;
if ( V_352 . V_1496 != V_1497 &&
V_352 . V_1496 != V_1499 )
return - V_16 ;
} else {
V_352 . V_1496 = V_1499 ;
}
if ( V_30 -> V_5 [ V_1500 ] )
V_352 . V_1501 =
F_21 ( V_30 -> V_5 [ V_1500 ] ) ;
if ( V_30 -> V_5 [ V_540 ] ) {
V_352 . V_1408 = F_42 (
V_18 , V_30 -> V_5 [ V_540 ] ) ;
if ( ! V_352 . V_1408 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1563 ] ) {
V_352 . V_1564 = F_42 (
V_18 , V_30 -> V_5 [ V_1563 ] ) ;
if ( ! V_352 . V_1564 )
return - V_16 ;
}
if ( V_352 . V_798 && V_30 -> V_5 [ V_1534 ] ) {
V_1524 = F_35 ( V_7 ,
V_30 -> V_5 [ V_1534 ] , NULL ) ;
if ( F_17 ( V_1524 ) )
return F_18 ( V_1524 ) ;
}
if ( F_169 ( V_30 -> V_5 [ V_1502 ] ) )
V_352 . V_49 |= V_1503 ;
if ( V_30 -> V_5 [ V_471 ] )
memcpy ( & V_352 . V_1504 ,
F_21 ( V_30 -> V_5 [ V_471 ] ) ,
sizeof( V_352 . V_1504 ) ) ;
if ( V_30 -> V_5 [ V_1015 ] ) {
if ( ! V_30 -> V_5 [ V_471 ] ) {
F_314 ( V_1524 ) ;
return - V_16 ;
}
memcpy ( & V_352 . V_985 ,
F_21 ( V_30 -> V_5 [ V_1015 ] ) ,
sizeof( V_352 . V_985 ) ) ;
}
if ( F_169 ( V_30 -> V_5 [ V_1505 ] ) )
V_352 . V_49 |= V_1506 ;
if ( V_30 -> V_5 [ V_480 ] )
memcpy ( & V_352 . V_1507 ,
F_21 ( V_30 -> V_5 [ V_480 ] ) ,
sizeof( V_352 . V_1507 ) ) ;
if ( V_30 -> V_5 [ V_1016 ] ) {
if ( ! V_30 -> V_5 [ V_480 ] ) {
F_314 ( V_1524 ) ;
return - V_16 ;
}
memcpy ( & V_352 . V_986 ,
F_21 ( V_30 -> V_5 [ V_1016 ] ) ,
sizeof( V_352 . V_986 ) ) ;
}
if ( F_169 ( V_30 -> V_5 [ V_1508 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_367 &
V_1509 ) &&
( V_7 -> V_18 . V_367 & V_1510 ) ) &&
! F_116 ( & V_7 -> V_18 ,
V_1511 ) ) {
F_314 ( V_1524 ) ;
return - V_16 ;
}
V_352 . V_49 |= V_1512 ;
}
V_352 . V_820 = F_169 ( V_30 -> V_5 [ V_821 ] ) ;
if ( V_352 . V_820 && ! V_7 -> V_18 . V_437 [ V_822 ] ) {
F_314 ( V_1524 ) ;
return - V_558 ;
}
if ( V_30 -> V_5 [ V_502 ] ) {
if ( V_352 . V_564 ) {
F_314 ( V_1524 ) ;
return - V_16 ;
}
V_35 = F_257 ( V_30 -> V_5 [ V_502 ] ,
V_18 , & V_352 . V_1274 ) ;
if ( V_35 ) {
F_314 ( V_1524 ) ;
return V_35 ;
}
}
F_113 ( V_557 -> V_28 ) ;
V_35 = F_330 ( V_7 , V_557 , & V_352 , V_1524 ,
V_352 . V_1501 ) ;
if ( V_35 )
F_314 ( V_1524 ) ;
if ( ! V_35 && V_30 -> V_5 [ V_656 ] ) {
V_557 -> V_28 -> V_1518 = V_30 -> V_522 ;
if ( V_352 . V_564 )
memcpy ( V_557 -> V_28 -> V_1519 ,
V_352 . V_564 , V_605 ) ;
else
memset ( V_557 -> V_28 -> V_1519 ,
0 , V_605 ) ;
}
F_115 ( V_557 -> V_28 ) ;
return V_35 ;
}
static int F_331 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1558 V_352 = {} ;
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
V_22 V_568 = 0 ;
int V_514 ;
if ( ! V_7 -> V_327 -> V_457 )
return - V_558 ;
if ( V_30 -> V_5 [ V_749 ] ) {
if ( ! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
V_352 . V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_352 . V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
V_568 |= V_1565 ;
}
F_113 ( V_557 -> V_28 ) ;
if ( ! V_17 -> V_148 )
V_514 = - V_149 ;
else
V_514 = F_332 ( V_7 , V_557 , & V_352 , V_568 ) ;
F_115 ( V_557 -> V_28 ) ;
return V_514 ;
}
static int F_333 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_3 V_1566 ;
int V_514 ;
if ( ! V_30 -> V_5 [ V_1051 ] )
V_1566 = V_1567 ;
else
V_1566 = F_79 ( V_30 -> V_5 [ V_1051 ] ) ;
if ( V_1566 == 0 )
return - V_16 ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
F_113 ( V_557 -> V_28 ) ;
V_514 = F_334 ( V_7 , V_557 , V_1566 , true ) ;
F_115 ( V_557 -> V_28 ) ;
return V_514 ;
}
static int F_335 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1568 ] ) {
V_22 V_1569 = F_4 ( V_30 -> V_5 [ V_1568 ] ) ;
V_2 = F_336 ( V_1569 ) ;
} else if ( V_30 -> V_5 [ V_1570 ] ) {
V_22 V_1571 = F_4 ( V_30 -> V_5 [ V_1570 ] ) ;
V_2 = F_337 ( V_1571 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_338 ( V_7 , V_2 ) ;
F_339 ( V_2 ) ;
return V_35 ;
}
static int F_340 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
int (* F_341)( struct V_18 * V_18 , struct V_25 * V_557 ,
struct V_1572 * V_1573 ) = NULL ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1572 V_1573 ;
memset ( & V_1573 , 0 , sizeof( struct V_1572 ) ) ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1574 ] )
return - V_16 ;
V_1573 . V_1575 = F_21 ( V_30 -> V_5 [ V_1574 ] ) ;
V_1573 . V_564 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
switch ( V_30 -> V_1576 -> V_50 ) {
case V_1577 :
F_341 = V_7 -> V_327 -> V_310 ;
break;
case V_1578 :
F_341 = V_7 -> V_327 -> V_312 ;
break;
default:
F_60 ( 1 ) ;
break;
}
if ( ! F_341 )
return - V_558 ;
return F_341 ( & V_7 -> V_18 , V_557 , & V_1573 ) ;
}
static int F_342 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
if ( V_557 -> V_28 -> V_140 != V_146 &&
V_557 -> V_28 -> V_140 != V_147 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_314 )
return - V_558 ;
return F_343 ( V_7 , V_557 ) ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 V_1579 , V_1580 ;
V_22 V_1581 = 0 ;
T_3 V_1582 ;
T_2 * V_1583 ;
bool V_1584 ;
if ( ! ( V_7 -> V_18 . V_49 & V_332 ) ||
! V_7 -> V_327 -> V_333 )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_1585 ] ||
! V_30 -> V_5 [ V_1586 ] ||
! V_30 -> V_5 [ V_1587 ] ||
! V_30 -> V_5 [ V_749 ] ||
! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_1583 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_1579 = F_32 ( V_30 -> V_5 [ V_1585 ] ) ;
V_1582 = F_79 ( V_30 -> V_5 [ V_1586 ] ) ;
V_1580 = F_32 ( V_30 -> V_5 [ V_1587 ] ) ;
V_1584 = F_169 ( V_30 -> V_5 [ V_1588 ] ) ;
if ( V_30 -> V_5 [ V_1589 ] )
V_1581 =
F_4 ( V_30 -> V_5 [ V_1589 ] ) ;
return F_345 ( V_7 , V_557 , V_1583 , V_1579 ,
V_1580 , V_1582 , V_1581 ,
V_1584 ,
F_21 ( V_30 -> V_5 [ V_749 ] ) ,
F_22 ( V_30 -> V_5 [ V_749 ] ) ) ;
}
static int F_346 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
enum V_1590 V_1591 ;
T_2 * V_1583 ;
if ( ! ( V_7 -> V_18 . V_49 & V_332 ) ||
! V_7 -> V_327 -> V_335 )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_1592 ] ||
! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_1591 = F_32 ( V_30 -> V_5 [ V_1592 ] ) ;
V_1583 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
return F_347 ( V_7 , V_557 , V_1583 , V_1591 ) ;
}
static int F_348 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
struct V_537 V_538 ;
struct V_31 * V_51 ;
void * V_359 ;
T_1 V_670 ;
V_22 V_1304 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_540 ] ||
! V_30 -> V_5 [ V_1593 ] )
return - V_16 ;
V_1304 = F_4 ( V_30 -> V_5 [ V_1593 ] ) ;
if ( ! V_7 -> V_327 -> V_317 ||
! ( V_7 -> V_18 . V_49 & V_316 ) )
return - V_558 ;
if ( V_1304 < V_1594 ||
V_1304 > V_7 -> V_18 . V_460 )
return - V_16 ;
V_35 = F_81 ( V_7 , V_30 , & V_538 ) ;
if ( V_35 )
return V_35 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1595 ) ;
if ( ! V_359 ) {
V_35 = - V_89 ;
goto V_680;
}
V_35 = F_349 ( V_7 , V_17 , V_538 . V_53 ,
V_1304 , & V_670 ) ;
if ( V_35 )
goto V_680;
if ( F_104 ( V_51 , V_1596 , V_670 ,
V_604 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_680:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_350 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
T_1 V_670 ;
if ( ! V_30 -> V_5 [ V_1596 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_1597 )
return - V_558 ;
V_670 = F_5 ( V_30 -> V_5 [ V_1596 ] ) ;
return F_351 ( V_7 , V_17 , V_670 ) ;
}
static int F_352 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_723 V_704 ;
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_327 -> V_319 )
return - V_558 ;
V_35 = F_154 ( V_30 , & V_704 ) ;
if ( V_35 )
return V_35 ;
return F_353 ( V_7 , V_557 , NULL , & V_704 ) ;
}
static int F_354 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
T_3 V_1598 = V_279 | V_1599 ;
if ( ! V_30 -> V_5 [ V_1600 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_278 ] )
V_1598 = F_79 ( V_30 -> V_5 [ V_278 ] ) ;
switch ( V_17 -> V_140 ) {
case V_146 :
case V_145 :
case V_147 :
case V_141 :
case V_142 :
case V_144 :
case V_143 :
case V_154 :
break;
case V_153 :
default:
return - V_558 ;
}
if ( ! V_7 -> V_327 -> V_321 )
return - V_558 ;
return F_355 ( V_17 , V_30 -> V_522 , V_1598 ,
F_21 ( V_30 -> V_5 [ V_1600 ] ) ,
F_22 ( V_30 -> V_5 [ V_1600 ] ) ) ;
}
static int F_356 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
struct V_537 V_538 ;
int V_35 ;
void * V_359 = NULL ;
T_1 V_670 ;
struct V_31 * V_51 = NULL ;
struct V_1601 V_138 = {
. V_1602 =
V_30 -> V_5 [ V_1603 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1604 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_321 )
return - V_558 ;
switch ( V_17 -> V_140 ) {
case V_154 :
if ( ! V_30 -> V_5 [ V_540 ] )
return - V_16 ;
case V_146 :
case V_145 :
case V_147 :
case V_141 :
case V_142 :
case V_144 :
case V_143 :
break;
case V_153 :
default:
return - V_558 ;
}
if ( V_30 -> V_5 [ V_1593 ] ) {
if ( ! ( V_7 -> V_18 . V_49 & V_461 ) )
return - V_16 ;
V_138 . V_1605 = F_4 ( V_30 -> V_5 [ V_1593 ] ) ;
if ( V_138 . V_1605 < V_1594 ||
V_138 . V_1605 > V_7 -> V_18 . V_460 )
return - V_16 ;
}
V_138 . V_1606 = V_30 -> V_5 [ V_462 ] ;
if ( V_138 . V_1606 && ! ( V_7 -> V_18 . V_49 & V_461 ) )
return - V_16 ;
V_138 . V_1312 = F_169 ( V_30 -> V_5 [ V_1313 ] ) ;
V_538 . V_53 = NULL ;
if ( V_30 -> V_5 [ V_540 ] ) {
V_35 = F_81 ( V_7 , V_30 , & V_538 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_538 . V_53 && V_138 . V_1606 )
return - V_16 ;
V_138 . V_1607 = F_21 ( V_30 -> V_5 [ V_1604 ] ) ;
V_138 . V_45 = F_22 ( V_30 -> V_5 [ V_1604 ] ) ;
if ( V_30 -> V_5 [ V_1608 ] ) {
int V_45 = F_22 ( V_30 -> V_5 [ V_1608 ] ) ;
int V_159 ;
if ( V_45 % sizeof( T_3 ) )
return - V_16 ;
V_138 . V_1609 = V_45 / sizeof( T_3 ) ;
V_138 . V_1610 =
F_21 ( V_30 -> V_5 [ V_1608 ] ) ;
for ( V_159 = 0 ; V_159 < V_138 . V_1609 ; V_159 ++ ) {
if ( V_138 . V_1610 [ V_159 ] >= V_138 . V_45 )
return - V_16 ;
}
}
if ( ! V_138 . V_1602 ) {
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1611 ) ;
if ( ! V_359 ) {
V_35 = - V_89 ;
goto V_680;
}
}
V_138 . V_53 = V_538 . V_53 ;
V_35 = F_357 ( V_7 , V_17 , & V_138 , & V_670 ) ;
if ( V_35 )
goto V_680;
if ( V_51 ) {
if ( F_104 ( V_51 , V_1596 , V_670 ,
V_604 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
}
return 0 ;
V_59:
V_35 = - V_89 ;
V_680:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_358 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
T_1 V_670 ;
if ( ! V_30 -> V_5 [ V_1596 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_323 )
return - V_558 ;
switch ( V_17 -> V_140 ) {
case V_146 :
case V_145 :
case V_147 :
case V_141 :
case V_142 :
case V_143 :
case V_154 :
break;
case V_153 :
default:
return - V_558 ;
}
V_670 = F_5 ( V_30 -> V_5 [ V_1596 ] ) ;
return F_359 ( V_7 , V_17 , V_670 ) ;
}
static int F_360 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 V_1612 ;
bool V_358 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1613 ] )
return - V_16 ;
V_1612 = F_4 ( V_30 -> V_5 [ V_1613 ] ) ;
if ( V_1612 != V_1614 && V_1612 != V_1615 )
return - V_16 ;
V_17 = V_557 -> V_28 ;
if ( ! V_7 -> V_327 -> V_1616 )
return - V_558 ;
V_358 = ( V_1612 == V_1615 ) ? true : false ;
if ( V_358 == V_17 -> V_1617 )
return 0 ;
V_35 = F_361 ( V_7 , V_557 , V_358 , V_17 -> V_1618 ) ;
if ( ! V_35 )
V_17 -> V_1617 = V_358 ;
return V_35 ;
}
static int F_362 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
enum V_1619 V_1612 ;
struct V_1 * V_17 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_31 * V_51 ;
void * V_359 ;
int V_35 ;
V_17 = V_557 -> V_28 ;
if ( ! V_7 -> V_327 -> V_1616 )
return - V_558 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1620 ) ;
if ( ! V_359 ) {
V_35 = - V_89 ;
goto V_680;
}
if ( V_17 -> V_1617 )
V_1612 = V_1615 ;
else
V_1612 = V_1614 ;
if ( F_26 ( V_51 , V_1613 , V_1612 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_680:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_363 ( struct V_29 * V_30 ,
V_22 V_246 , V_22 V_1621 , V_22 V_1622 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
if ( V_246 > 100 || V_1622 > V_1623 )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_1624 )
return - V_558 ;
if ( V_17 -> V_140 != V_146 &&
V_17 -> V_140 != V_147 )
return - V_558 ;
return F_364 ( V_7 , V_557 , V_246 , V_1621 , V_1622 ) ;
}
static int F_365 ( struct V_29 * V_30 ,
T_7 V_1625 , V_22 V_1626 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
if ( V_1625 > 0 )
return - V_16 ;
if ( V_1625 == 0 )
V_1626 = 0 ;
if ( ! V_7 -> V_327 -> V_1627 )
return - V_558 ;
if ( V_17 -> V_140 != V_146 &&
V_17 -> V_140 != V_147 )
return - V_558 ;
return F_366 ( V_7 , V_557 , V_1625 , V_1626 ) ;
}
static int F_367 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1628 + 1 ] ;
struct V_4 * V_1629 ;
int V_35 ;
V_1629 = V_30 -> V_5 [ V_1630 ] ;
if ( ! V_1629 )
return - V_16 ;
V_35 = F_31 ( V_5 , V_1628 , V_1629 ,
V_1631 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1632 ] &&
V_5 [ V_1633 ] ) {
T_7 V_1625 = F_230 ( V_5 [ V_1632 ] ) ;
V_22 V_1626 = F_4 ( V_5 [ V_1633 ] ) ;
return F_365 ( V_30 , V_1625 , V_1626 ) ;
}
if ( V_5 [ V_1634 ] &&
V_5 [ V_1635 ] &&
V_5 [ V_1636 ] ) {
V_22 V_246 = F_4 ( V_5 [ V_1634 ] ) ;
V_22 V_1621 = F_4 ( V_5 [ V_1635 ] ) ;
V_22 V_1622 = F_4 ( V_5 [ V_1636 ] ) ;
return F_363 ( V_30 , V_246 , V_1621 , V_1622 ) ;
}
return - V_16 ;
}
static int F_368 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1637 V_1192 = {} ;
int V_35 ;
V_35 = F_81 ( V_7 , V_30 , & V_1192 . V_538 ) ;
if ( V_35 )
return V_35 ;
return F_369 ( V_7 , V_557 , & V_1192 ) ;
}
static int F_370 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
return F_371 ( V_7 , V_557 ) ;
}
static int F_372 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1115 V_1179 ;
struct V_1191 V_1192 ;
int V_35 ;
memcpy ( & V_1179 , & V_1119 , sizeof( V_1179 ) ) ;
memcpy ( & V_1192 , & V_1638 , sizeof( V_1192 ) ) ;
if ( V_30 -> V_5 [ V_1121 ] ) {
V_35 = F_232 ( V_30 , & V_1179 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_636 ] ||
! F_22 ( V_30 -> V_5 [ V_636 ] ) )
return - V_16 ;
V_1192 . V_1639 = F_21 ( V_30 -> V_5 [ V_636 ] ) ;
V_1192 . V_1118 = F_22 ( V_30 -> V_5 [ V_636 ] ) ;
if ( V_30 -> V_5 [ V_1533 ] &&
! F_311 ( V_7 , V_1192 . V_1520 ,
F_4 ( V_30 -> V_5 [ V_1533 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_790 ] ) {
V_1192 . V_559 =
F_4 ( V_30 -> V_5 [ V_790 ] ) ;
V_35 = F_167 ( V_7 ,
V_144 ,
V_1192 . V_559 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_791 ] ) {
V_1192 . V_792 =
F_4 ( V_30 -> V_5 [ V_791 ] ) ;
if ( V_1192 . V_792 < 1 || V_1192 . V_792 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1194 ] ) {
V_35 = F_234 ( V_30 , & V_1192 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1192 . V_1214 )
V_1179 . V_1137 = false ;
if ( V_30 -> V_5 [ V_540 ] ) {
V_35 = F_81 ( V_7 , V_30 , & V_1192 . V_538 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1192 . V_538 . V_53 = NULL ;
}
if ( V_30 -> V_5 [ V_1099 ] ) {
T_2 * V_702 = F_21 ( V_30 -> V_5 [ V_1099 ] ) ;
int V_1532 =
F_22 ( V_30 -> V_5 [ V_1099 ] ) ;
struct V_241 * V_242 ;
if ( ! V_1192 . V_538 . V_53 )
return - V_16 ;
V_242 = V_7 -> V_18 . V_437 [ V_1192 . V_538 . V_53 -> V_366 ] ;
V_35 = F_264 ( V_242 , V_702 , V_1532 ,
& V_1192 . V_1100 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_730 ] ) {
V_35 = F_154 ( V_30 , & V_1192 . V_739 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_156 ( V_7 , V_1192 . V_538 . V_53 -> V_366 ,
& V_1192 . V_739 ) ;
if ( V_35 )
return V_35 ;
}
return F_373 ( V_7 , V_557 , & V_1192 , & V_1179 ) ;
}
static int F_374 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
return F_375 ( V_7 , V_557 ) ;
}
static int F_376 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_1640 * V_191 = V_7 -> V_18 . V_1641 ;
struct V_4 * V_1642 , * V_1643 ;
int V_159 , V_1644 ;
if ( ! V_191 -> V_221 )
return 0 ;
V_1642 = F_45 ( V_51 , V_230 ) ;
if ( ! V_1642 )
return - V_89 ;
for ( V_159 = 0 ; V_159 < V_191 -> V_221 ; V_159 ++ ) {
V_1643 = F_45 ( V_51 , V_159 + 1 ) ;
if ( ! V_1643 )
return - V_89 ;
V_1644 = V_191 -> V_1645 [ V_159 ] . V_1646 ;
if ( F_49 ( V_51 , V_1647 , F_272 ( V_1644 , 8 ) ,
V_191 -> V_1645 [ V_159 ] . V_704 ) ||
F_49 ( V_51 , V_1648 , V_1644 ,
V_191 -> V_1645 [ V_159 ] . V_1649 ) ||
F_26 ( V_51 , V_1650 ,
V_191 -> V_1645 [ V_159 ] . V_1651 ) )
return - V_89 ;
F_46 ( V_51 , V_1643 ) ;
}
F_46 ( V_51 , V_1642 ) ;
return 0 ;
}
static int F_377 ( struct V_31 * V_51 ,
struct V_1652 * V_190 )
{
struct V_4 * V_192 ;
if ( ! V_190 )
return 0 ;
V_192 = F_45 ( V_51 , V_193 ) ;
if ( ! V_192 )
return - V_89 ;
if ( F_378 ( V_51 , V_1653 , V_190 -> V_1654 ) ||
F_378 ( V_51 , V_1655 , V_190 -> V_1054 ) ||
F_49 ( V_51 , V_1656 , V_605 , V_190 -> V_1657 ) ||
F_53 ( V_51 , V_1658 , V_190 -> V_1659 ) ||
F_53 ( V_51 , V_1660 , V_190 -> V_1661 ) ||
F_49 ( V_51 , V_194 ,
V_190 -> V_1662 , V_190 -> V_1663 ) ||
F_26 ( V_51 , V_199 ,
V_190 -> V_1664 ) ||
F_49 ( V_51 , V_201 ,
V_190 -> V_1665 , V_190 -> V_1666 ) ||
F_49 ( V_51 , V_1667 ,
F_272 ( V_190 -> V_1665 , 8 ) , V_190 -> V_1668 ) )
return - V_89 ;
if ( V_190 -> V_1669 . V_45 &&
F_49 ( V_51 , V_196 ,
sizeof( V_190 -> V_1669 ) , & V_190 -> V_1669 ) )
return - V_89 ;
if ( V_190 -> V_1670 . V_45 &&
F_49 ( V_51 , V_198 ,
sizeof( V_190 -> V_1670 ) + V_190 -> V_1671 ,
& V_190 -> V_1670 ) )
return - V_89 ;
F_46 ( V_51 , V_192 ) ;
return 0 ;
}
static int F_379 ( struct V_31 * V_51 ,
struct V_1319 * V_1493 )
{
struct V_4 * V_1672 , * V_1267 , * V_1673 , * V_1674 , * V_1323 , * V_1675 ;
int V_159 ;
if ( ! V_1493 )
return 0 ;
V_1672 = F_45 ( V_51 , V_232 ) ;
if ( ! V_1672 )
return - V_89 ;
if ( V_1493 -> V_1344 == 1 &&
F_26 ( V_51 , V_1322 ,
V_1493 -> V_1323 [ 0 ] . V_1321 * 1000 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_1351 , V_1493 -> V_1352 ) )
return - V_89 ;
if ( V_1493 -> V_1354 ) {
struct V_1284 V_1355 ;
if ( F_380 ( V_51 , V_1341 ,
V_1493 -> V_1353 ) )
return - V_89 ;
V_1355 . V_366 = V_1493 -> V_1355 . V_366 ;
V_1355 . V_1287 = V_1493 -> V_1355 . V_1287 ;
if ( F_49 ( V_51 , V_1342 ,
sizeof( V_1355 ) , & V_1355 ) )
return - V_89 ;
}
V_1267 = F_45 ( V_51 , V_1297 ) ;
if ( ! V_1267 )
return - V_89 ;
for ( V_159 = 0 ; V_159 < V_1493 -> V_440 ; V_159 ++ ) {
if ( F_26 ( V_51 , V_159 , V_1493 -> V_441 [ V_159 ] -> V_58 ) )
return - V_89 ;
}
F_46 ( V_51 , V_1267 ) ;
if ( V_1493 -> V_1331 ) {
V_1673 = F_45 ( V_51 , V_1335 ) ;
if ( ! V_1673 )
return - V_89 ;
for ( V_159 = 0 ; V_159 < V_1493 -> V_1331 ; V_159 ++ ) {
V_1674 = F_45 ( V_51 , V_159 ) ;
if ( ! V_1674 )
return - V_89 ;
if ( F_49 ( V_51 , V_1338 ,
V_1493 -> V_1343 [ V_159 ] . V_612 . V_610 ,
V_1493 -> V_1343 [ V_159 ] . V_612 . V_612 ) )
return - V_89 ;
F_46 ( V_51 , V_1674 ) ;
}
F_46 ( V_51 , V_1673 ) ;
}
V_1323 = F_45 ( V_51 , V_1320 ) ;
if ( ! V_1323 )
return - V_89 ;
for ( V_159 = 0 ; V_159 < V_1493 -> V_1344 ; V_159 ++ ) {
V_1675 = F_45 ( V_51 , V_159 + 1 ) ;
if ( ! V_1675 )
return - V_89 ;
if ( ! V_1675 ||
F_26 ( V_51 , V_1328 ,
V_1493 -> V_1323 [ V_159 ] . V_1321 ) ||
( V_1493 -> V_1323 [ V_159 ] . V_1330 &&
F_26 ( V_51 , V_1329 ,
V_1493 -> V_1323 [ V_159 ] . V_1330 ) ) )
return - V_89 ;
F_46 ( V_51 , V_1675 ) ;
}
F_46 ( V_51 , V_1323 ) ;
F_46 ( V_51 , V_1672 ) ;
return 0 ;
}
static int F_381 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_31 * V_51 ;
void * V_359 ;
V_22 V_1676 = V_619 ;
if ( ! V_7 -> V_18 . V_191 )
return - V_558 ;
if ( V_7 -> V_18 . V_1641 && V_7 -> V_18 . V_1641 -> V_190 ) {
V_1676 += V_7 -> V_18 . V_1641 -> V_190 -> V_1671 +
V_7 -> V_18 . V_1641 -> V_190 -> V_1662 +
V_7 -> V_18 . V_1641 -> V_190 -> V_1665 +
V_7 -> V_18 . V_1641 -> V_190 -> V_1665 / 8 ;
}
V_51 = F_75 ( V_1676 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1677 ) ;
if ( ! V_359 )
goto V_59;
if ( V_7 -> V_18 . V_1641 ) {
struct V_4 * V_203 ;
V_203 = F_45 ( V_51 , V_1678 ) ;
if ( ! V_203 )
goto V_59;
if ( ( V_7 -> V_18 . V_1641 -> V_1679 &&
F_27 ( V_51 , V_206 ) ) ||
( V_7 -> V_18 . V_1641 -> V_354 &&
F_27 ( V_51 , V_208 ) ) ||
( V_7 -> V_18 . V_1641 -> V_1680 &&
F_27 ( V_51 , V_210 ) ) ||
( V_7 -> V_18 . V_1641 -> V_1681 &&
F_27 ( V_51 , V_214 ) ) ||
( V_7 -> V_18 . V_1641 -> V_1682 &&
F_27 ( V_51 , V_216 ) ) ||
( V_7 -> V_18 . V_1641 -> V_1683 &&
F_27 ( V_51 , V_218 ) ) ||
( V_7 -> V_18 . V_1641 -> V_1684 &&
F_27 ( V_51 , V_220 ) ) )
goto V_59;
if ( F_376 ( V_51 , V_7 ) )
goto V_59;
if ( F_377 ( V_51 ,
V_7 -> V_18 . V_1641 -> V_190 ) )
goto V_59;
if ( F_379 (
V_51 ,
V_7 -> V_18 . V_1641 -> V_1685 ) )
goto V_59;
F_46 ( V_51 , V_203 ) ;
}
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_76 ( V_51 ) ;
return - V_89 ;
}
static int F_382 ( struct V_6 * V_7 ,
struct V_4 * V_43 ,
struct V_1640 * V_1686 )
{
struct V_4 * V_93 [ V_1687 ] ;
struct V_1652 * V_1179 ;
struct V_1688 * V_197 = NULL ;
struct V_1689 * V_48 = NULL ;
V_22 V_1676 ;
V_22 V_1690 , V_1691 , V_1671 = 0 , V_1692 ;
int V_35 , V_1693 ;
if ( ! V_7 -> V_18 . V_191 -> V_190 )
return - V_16 ;
V_35 = F_31 ( V_93 , V_1694 , V_43 ,
V_1695 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_93 [ V_1653 ] ||
! V_93 [ V_1655 ] ||
! V_93 [ V_1656 ] ||
! V_93 [ V_1660 ] ||
! V_93 [ V_194 ] ||
! V_93 [ V_199 ] ||
! V_93 [ V_201 ] ||
! V_93 [ V_1667 ] )
return - V_16 ;
V_1690 = F_22 ( V_93 [ V_194 ] ) ;
if ( V_1690 > V_7 -> V_18 . V_191 -> V_190 -> V_195 )
return - V_16 ;
if ( F_4 ( V_93 [ V_199 ] ) >
V_7 -> V_18 . V_191 -> V_190 -> V_200 ||
F_4 ( V_93 [ V_199 ] ) == 0 )
return - V_16 ;
V_1691 = F_22 ( V_93 [ V_201 ] ) ;
if ( V_1691 > V_7 -> V_18 . V_191 -> V_190 -> V_202 )
return - V_16 ;
V_1692 = F_22 ( V_93 [ V_1667 ] ) ;
if ( V_1692 != F_272 ( V_1691 , 8 ) )
return - V_16 ;
if ( V_93 [ V_198 ] ) {
V_22 V_1696 = F_22 ( V_93 [ V_198 ] ) ;
V_197 = F_21 ( V_93 [ V_198 ] ) ;
V_1671 = V_1696 - sizeof( * V_197 ) ;
if ( ! V_197 -> V_45 || V_1671 % V_197 -> V_45 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_191 -> V_190 -> V_197 )
return - V_16 ;
if ( V_197 -> V_45 > V_7 -> V_18 . V_191 -> V_190 -> V_197 -> V_1697 )
return - V_16 ;
if ( V_197 -> V_45 < V_7 -> V_18 . V_191 -> V_190 -> V_197 -> V_1698 )
return - V_16 ;
if ( V_1671 > V_7 -> V_18 . V_191 -> V_190 -> V_197 -> V_1699 )
return - V_16 ;
if ( V_197 -> V_1379 + V_197 -> V_45 > V_1690 )
return - V_16 ;
}
if ( V_93 [ V_196 ] ) {
V_48 = F_21 ( V_93 [ V_196 ] ) ;
if ( ! V_7 -> V_18 . V_191 -> V_190 -> V_48 )
return - V_16 ;
if ( V_48 -> V_45 == 0 || V_48 -> V_45 > 4 )
return - V_16 ;
if ( V_48 -> V_45 + V_48 -> V_1379 > V_1690 )
return - V_16 ;
}
V_1676 = sizeof( * V_1179 ) ;
V_1676 += V_1690 ;
V_1676 += V_1691 + V_1692 ;
V_1676 += V_1671 ;
V_1179 = F_37 ( V_1676 , V_134 ) ;
if ( ! V_1179 )
return - V_135 ;
V_1179 -> V_1654 = F_383 ( V_93 [ V_1653 ] ) ;
V_1179 -> V_1054 = F_383 ( V_93 [ V_1655 ] ) ;
memcpy ( V_1179 -> V_1657 , F_21 ( V_93 [ V_1656 ] ) ,
V_605 ) ;
if ( V_93 [ V_1658 ] )
V_1693 = F_79 ( V_93 [ V_1658 ] ) ;
else
V_1693 = 0 ;
#ifdef F_384
V_35 = F_385 ( F_7 ( & V_7 -> V_18 ) , V_1700 , V_1701 ,
V_1702 , & V_1179 -> V_1703 , 1 ) ;
if ( V_35 ) {
F_39 ( V_1179 ) ;
return V_35 ;
}
if ( F_386 ( V_1179 -> V_1703 -> V_42 , V_1693 ) ) {
F_387 ( V_1179 -> V_1703 ) ;
F_39 ( V_1179 ) ;
return - V_1704 ;
}
V_1179 -> V_1659 = F_388 ( V_1179 -> V_1703 -> V_42 ) -> V_1705 ;
#else
if ( ! V_1693 ) {
F_39 ( V_1179 ) ;
return - V_16 ;
}
V_1179 -> V_1659 = V_1693 ;
#endif
V_1179 -> V_1661 = F_79 ( V_93 [ V_1660 ] ) ;
V_1179 -> V_1662 = V_1690 ;
V_1179 -> V_1663 = ( T_2 * ) V_1179 + sizeof( * V_1179 ) + V_1671 ;
memcpy ( ( void * ) V_1179 -> V_1663 ,
F_21 ( V_93 [ V_194 ] ) ,
V_1690 ) ;
if ( V_48 )
V_1179 -> V_1669 = * V_48 ;
V_1179 -> V_1664 = F_4 ( V_93 [ V_199 ] ) ;
V_1179 -> V_1665 = V_1691 ;
V_1179 -> V_1666 = ( T_2 * ) V_1179 + sizeof( * V_1179 ) + V_1671 + V_1690 ;
memcpy ( ( void * ) V_1179 -> V_1666 ,
F_21 ( V_93 [ V_201 ] ) ,
V_1691 ) ;
V_1179 -> V_1668 = ( T_2 * ) V_1179 + sizeof( * V_1179 ) + V_1671 +
V_1690 + V_1691 ;
memcpy ( ( void * ) V_1179 -> V_1668 ,
F_21 ( V_93 [ V_1667 ] ) ,
V_1692 ) ;
if ( V_197 ) {
V_1179 -> V_1671 = V_1671 ;
memcpy ( & V_1179 -> V_1670 , V_197 , sizeof( * V_197 ) + V_1671 ) ;
}
V_1686 -> V_190 = V_1179 ;
return 0 ;
}
static int F_389 ( struct V_6 * V_7 ,
const struct V_1706 * V_191 ,
struct V_4 * V_43 ,
struct V_1640 * V_1686 )
{
struct V_4 * * V_93 ;
int V_35 ;
V_93 = F_37 ( V_1707 * sizeof( * V_93 ) , V_134 ) ;
if ( ! V_93 )
return - V_135 ;
if ( ! ( V_191 -> V_49 & V_231 ) ) {
V_35 = - V_558 ;
goto V_618;
}
V_35 = F_31 ( V_93 , V_1366 , V_43 , V_41 ) ;
if ( V_35 )
goto V_618;
V_1686 -> V_1685 = F_273 ( & V_7 -> V_18 , NULL , V_93 ,
V_191 -> V_233 ) ;
V_35 = F_275 ( V_1686 -> V_1685 ) ;
if ( V_35 )
V_1686 -> V_1685 = NULL ;
V_618:
F_39 ( V_93 ) ;
return V_35 ;
}
static int F_390 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_4 * V_93 [ V_1708 ] ;
struct V_1640 V_1709 = {} ;
struct V_1640 * V_1710 ;
const struct V_1706 * V_191 = V_7 -> V_18 . V_191 ;
int V_35 , V_159 ;
bool V_1711 = V_7 -> V_18 . V_1641 ;
bool V_1712 = false ;
if ( ! V_191 )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_1678 ] ) {
F_391 ( V_7 ) ;
V_7 -> V_18 . V_1641 = NULL ;
goto V_1713;
}
V_35 = F_31 ( V_93 , V_1714 ,
V_30 -> V_5 [ V_1678 ] ,
V_1715 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_206 ] ) {
if ( ! ( V_191 -> V_49 & V_205 ) )
return - V_16 ;
V_1709 . V_1679 = true ;
}
if ( V_93 [ V_208 ] ) {
if ( ! ( V_191 -> V_49 & V_207 ) )
return - V_16 ;
V_1709 . V_354 = true ;
V_1712 = true ;
}
if ( V_93 [ V_210 ] ) {
if ( ! ( V_191 -> V_49 & V_209 ) )
return - V_16 ;
V_1709 . V_1680 = true ;
V_1712 = true ;
}
if ( V_93 [ V_212 ] )
return - V_16 ;
if ( V_93 [ V_214 ] ) {
if ( ! ( V_191 -> V_49 & V_213 ) )
return - V_16 ;
V_1709 . V_1681 = true ;
V_1712 = true ;
}
if ( V_93 [ V_216 ] ) {
if ( ! ( V_191 -> V_49 & V_215 ) )
return - V_16 ;
V_1709 . V_1682 = true ;
V_1712 = true ;
}
if ( V_93 [ V_218 ] ) {
if ( ! ( V_191 -> V_49 & V_217 ) )
return - V_16 ;
V_1709 . V_1683 = true ;
V_1712 = true ;
}
if ( V_93 [ V_220 ] ) {
if ( ! ( V_191 -> V_49 & V_219 ) )
return - V_16 ;
V_1709 . V_1684 = true ;
V_1712 = true ;
}
if ( V_93 [ V_230 ] ) {
struct V_4 * V_223 ;
int V_221 = 0 ;
int V_132 , V_1644 , V_1716 , V_1651 ;
struct V_4 * V_1717 [ V_1718 ] ;
V_1712 = true ;
F_36 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_221 ++ ;
if ( V_221 > V_191 -> V_221 )
return - V_16 ;
V_1709 . V_1645 = F_392 ( V_221 ,
sizeof( V_1709 . V_1645 [ 0 ] ) ,
V_134 ) ;
if ( ! V_1709 . V_1645 )
return - V_135 ;
V_1709 . V_221 = V_221 ;
V_159 = 0 ;
F_36 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1719 ;
F_31 ( V_1717 , V_1720 , V_223 ,
NULL ) ;
V_35 = - V_16 ;
if ( ! V_1717 [ V_1647 ] ||
! V_1717 [ V_1648 ] )
goto error;
V_1644 = F_22 ( V_1717 [ V_1648 ] ) ;
V_1716 = F_272 ( V_1644 , 8 ) ;
if ( F_22 ( V_1717 [ V_1647 ] ) != V_1716 )
goto error;
if ( V_1644 > V_191 -> V_228 ||
V_1644 < V_191 -> V_226 )
goto error;
if ( ! V_1717 [ V_1650 ] )
V_1651 = 0 ;
else
V_1651 = F_4 (
V_1717 [ V_1650 ] ) ;
if ( V_1651 > V_191 -> V_229 )
goto error;
V_1709 . V_1645 [ V_159 ] . V_1651 = V_1651 ;
V_1719 = F_393 ( V_1716 + V_1644 , V_134 ) ;
if ( ! V_1719 ) {
V_35 = - V_135 ;
goto error;
}
V_1709 . V_1645 [ V_159 ] . V_704 = V_1719 ;
memcpy ( V_1719 , F_21 ( V_1717 [ V_1647 ] ) ,
V_1716 ) ;
V_1719 += V_1716 ;
V_1709 . V_1645 [ V_159 ] . V_1649 = V_1719 ;
V_1709 . V_1645 [ V_159 ] . V_1646 = V_1644 ;
memcpy ( V_1719 ,
F_21 ( V_1717 [ V_1648 ] ) ,
V_1644 ) ;
V_159 ++ ;
}
}
if ( V_93 [ V_193 ] ) {
V_1712 = true ;
V_35 = F_382 (
V_7 , V_93 [ V_193 ] ,
& V_1709 ) ;
if ( V_35 )
goto error;
}
if ( V_93 [ V_232 ] ) {
V_1712 = true ;
V_35 = F_389 (
V_7 , V_191 , V_93 [ V_232 ] ,
& V_1709 ) ;
if ( V_35 )
goto error;
}
if ( V_1709 . V_1679 && V_1712 ) {
V_35 = - V_16 ;
goto error;
}
V_1710 = F_394 ( & V_1709 , sizeof( V_1709 ) , V_134 ) ;
if ( ! V_1710 ) {
V_35 = - V_135 ;
goto error;
}
F_391 ( V_7 ) ;
V_7 -> V_18 . V_1641 = V_1710 ;
V_1713:
if ( V_7 -> V_327 -> V_1713 &&
V_1711 != ! ! V_7 -> V_18 . V_1641 )
F_395 ( V_7 , V_7 -> V_18 . V_1641 ) ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1709 . V_221 ; V_159 ++ )
F_39 ( V_1709 . V_1645 [ V_159 ] . V_704 ) ;
F_39 ( V_1709 . V_1645 ) ;
if ( V_1709 . V_190 && V_1709 . V_190 -> V_1703 )
F_387 ( V_1709 . V_190 -> V_1703 ) ;
F_39 ( V_1709 . V_190 ) ;
F_39 ( V_1709 . V_1685 ) ;
return V_35 ;
}
static int F_396 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_4 * V_1642 , * V_1643 , * V_1721 , * V_1722 ;
int V_159 , V_161 , V_1644 ;
struct V_1723 * V_235 ;
if ( ! V_7 -> V_236 -> V_238 )
return 0 ;
V_1722 = F_45 ( V_51 , V_240 ) ;
if ( ! V_1722 )
return - V_89 ;
for ( V_159 = 0 ; V_159 < V_7 -> V_236 -> V_238 ; V_159 ++ ) {
V_1721 = F_45 ( V_51 , V_159 + 1 ) ;
if ( ! V_1721 )
return - V_89 ;
V_235 = & V_7 -> V_236 -> V_1724 [ V_159 ] ;
if ( F_26 ( V_51 , V_1725 ,
V_235 -> V_1352 ) )
return - V_89 ;
if ( F_26 ( V_51 , V_1726 ,
V_235 -> V_1727 ) )
return - V_89 ;
V_1642 = F_45 ( V_51 ,
V_1728 ) ;
if ( ! V_1642 )
return - V_89 ;
for ( V_161 = 0 ; V_161 < V_235 -> V_221 ; V_161 ++ ) {
V_1643 = F_45 ( V_51 , V_161 + 1 ) ;
if ( ! V_1643 )
return - V_89 ;
V_1644 = V_235 -> V_1645 [ V_161 ] . V_1646 ;
if ( F_49 ( V_51 , V_1647 ,
F_272 ( V_1644 , 8 ) ,
V_235 -> V_1645 [ V_161 ] . V_704 ) ||
F_49 ( V_51 , V_1648 , V_1644 ,
V_235 -> V_1645 [ V_161 ] . V_1649 ) ||
F_26 ( V_51 , V_1650 ,
V_235 -> V_1645 [ V_161 ] . V_1651 ) )
return - V_89 ;
F_46 ( V_51 , V_1643 ) ;
}
F_46 ( V_51 , V_1642 ) ;
F_46 ( V_51 , V_1721 ) ;
}
F_46 ( V_51 , V_1722 ) ;
return 0 ;
}
static int F_397 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_31 * V_51 ;
void * V_359 ;
if ( ! V_7 -> V_18 . V_236 )
return - V_558 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1729 ) ;
if ( ! V_359 )
goto V_59;
if ( V_7 -> V_236 && F_396 ( V_51 , V_7 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_76 ( V_51 ) ;
return - V_89 ;
}
void F_398 ( struct V_6 * V_7 )
{
struct V_1730 * V_236 = V_7 -> V_236 ;
int V_159 , V_161 ;
struct V_1723 * V_235 ;
if ( ! V_236 )
return;
for ( V_159 = 0 ; V_159 < V_236 -> V_238 ; V_159 ++ ) {
V_235 = & V_236 -> V_1724 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_235 -> V_221 ; V_161 ++ )
F_39 ( V_235 -> V_1645 [ V_161 ] . V_704 ) ;
F_39 ( V_235 -> V_1645 ) ;
}
F_39 ( V_236 -> V_1724 ) ;
F_39 ( V_236 ) ;
V_7 -> V_236 = NULL ;
}
static int F_399 ( struct V_6 * V_7 ,
struct V_4 * V_235 ,
struct V_1723 * V_1731 )
{
int V_35 , V_159 ;
const struct V_1732 * V_236 = V_7 -> V_18 . V_236 ;
struct V_4 * V_93 [ V_1733 ] , * V_223 ;
int V_132 , V_1644 , V_1716 , V_1651 , V_221 = 0 ;
struct V_4 * V_1717 [ V_1718 ] ;
V_35 = F_31 ( V_93 , V_1734 , V_235 ,
V_1735 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 [ V_1725 ] )
V_1731 -> V_1352 =
F_4 ( V_93 [ V_1725 ] ) ;
if ( V_1731 -> V_1352 > V_236 -> V_239 )
return - V_16 ;
if ( V_93 [ V_1726 ] )
V_1731 -> V_1727 =
F_4 ( V_93 [ V_1726 ] ) ;
if ( V_1731 -> V_1727 != V_1736 &&
V_1731 -> V_1727 != V_1737 )
return - V_16 ;
if ( ! V_93 [ V_1728 ] )
return - V_16 ;
F_36 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_221 ++ ;
if ( V_221 > V_236 -> V_221 )
return - V_16 ;
V_1731 -> V_1645 = F_392 ( V_221 , sizeof( V_1731 -> V_1645 [ 0 ] ) ,
V_134 ) ;
if ( ! V_1731 -> V_1645 )
return - V_135 ;
V_1731 -> V_221 = V_221 ;
V_159 = 0 ;
F_36 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1719 ;
F_31 ( V_1717 , V_1720 , V_223 , NULL ) ;
if ( ! V_1717 [ V_1647 ] ||
! V_1717 [ V_1648 ] )
return - V_16 ;
V_1644 = F_22 ( V_1717 [ V_1648 ] ) ;
V_1716 = F_272 ( V_1644 , 8 ) ;
if ( F_22 ( V_1717 [ V_1647 ] ) != V_1716 )
return - V_16 ;
if ( V_1644 > V_236 -> V_228 ||
V_1644 < V_236 -> V_226 )
return - V_16 ;
if ( ! V_1717 [ V_1650 ] )
V_1651 = 0 ;
else
V_1651 = F_4 ( V_1717 [ V_1650 ] ) ;
if ( V_1651 > V_236 -> V_229 )
return - V_16 ;
V_1731 -> V_1645 [ V_159 ] . V_1651 = V_1651 ;
V_1719 = F_393 ( V_1716 + V_1644 , V_134 ) ;
if ( ! V_1719 )
return - V_135 ;
V_1731 -> V_1645 [ V_159 ] . V_704 = V_1719 ;
memcpy ( V_1719 , F_21 ( V_1717 [ V_1647 ] ) ,
V_1716 ) ;
V_1719 += V_1716 ;
V_1731 -> V_1645 [ V_159 ] . V_1649 = V_1719 ;
V_1731 -> V_1645 [ V_159 ] . V_1646 = V_1644 ;
memcpy ( V_1719 , F_21 ( V_1717 [ V_1648 ] ) ,
V_1644 ) ;
V_159 ++ ;
}
return 0 ;
}
static int F_400 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
const struct V_1732 * V_236 = V_7 -> V_18 . V_236 ;
struct V_1730 V_1738 = {} ;
struct V_1730 * V_1739 ;
int V_35 , V_1740 , V_238 = 0 , V_159 , V_161 ;
struct V_4 * V_235 ;
struct V_1723 * V_1741 ;
if ( ! V_7 -> V_18 . V_236 || ! V_7 -> V_327 -> V_1742 )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_240 ] ) {
F_398 ( V_7 ) ;
F_401 ( V_7 , NULL ) ;
return 0 ;
}
F_36 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_238 ++ ;
if ( V_238 > V_236 -> V_238 )
return - V_16 ;
V_1738 . V_1724 = F_392 ( V_238 , sizeof( V_1738 . V_1724 [ 0 ] ) ,
V_134 ) ;
if ( ! V_1738 . V_1724 )
return - V_135 ;
V_1738 . V_238 = V_238 ;
V_159 = 0 ;
F_36 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_399 ( V_7 , V_235 ,
& V_1738 . V_1724 [ V_159 ] ) ;
if ( V_35 )
goto error;
V_159 ++ ;
}
V_35 = F_401 ( V_7 , & V_1738 ) ;
if ( V_35 )
goto error;
V_1739 = F_394 ( & V_1738 , sizeof( V_1738 ) , V_134 ) ;
if ( ! V_1739 ) {
V_35 = - V_135 ;
goto error;
}
F_398 ( V_7 ) ;
V_7 -> V_236 = V_1739 ;
return 0 ;
error:
for ( V_159 = 0 ; V_159 < V_1738 . V_238 ; V_159 ++ ) {
V_1741 = & V_1738 . V_1724 [ V_159 ] ;
for ( V_161 = 0 ; V_161 < V_1741 -> V_221 ; V_161 ++ )
F_39 ( V_1741 -> V_1645 [ V_161 ] . V_704 ) ;
F_39 ( V_1741 -> V_1645 ) ;
}
F_39 ( V_1738 . V_1724 ) ;
return V_35 ;
}
static int F_402 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_4 * V_93 [ V_1743 ] ;
struct V_1744 V_1745 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1746 ] )
return - V_16 ;
V_35 = F_31 ( V_93 , V_1747 ,
V_30 -> V_5 [ V_1746 ] ,
V_1748 ) ;
if ( V_35 )
return V_35 ;
if ( F_22 ( V_93 [ V_1749 ] ) != V_1750 )
return - V_1751 ;
if ( F_22 ( V_93 [ V_1752 ] ) != V_1753 )
return - V_1751 ;
if ( F_22 ( V_93 [ V_1754 ] ) != V_1755 )
return - V_1751 ;
V_1745 . V_1756 = F_21 ( V_93 [ V_1752 ] ) ;
V_1745 . V_1757 = F_21 ( V_93 [ V_1754 ] ) ;
V_1745 . V_1758 = F_21 ( V_93 [ V_1749 ] ) ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_148 ) {
V_35 = - V_1369 ;
goto V_618;
}
if ( ! V_7 -> V_327 -> V_1759 ) {
V_35 = - V_558 ;
goto V_618;
}
V_35 = F_403 ( V_7 , V_557 , & V_1745 ) ;
V_618:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_404 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
if ( V_17 -> V_140 != V_141 &&
V_17 -> V_140 != V_143 )
return - V_16 ;
if ( V_17 -> V_1760 )
return - V_562 ;
V_17 -> V_1760 = V_30 -> V_522 ;
return 0 ;
}
static int F_405 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_31 * V_51 ;
void * V_359 ;
const T_2 * V_700 ;
T_1 V_670 ;
int V_35 ;
if ( V_17 -> V_140 != V_141 &&
V_17 -> V_140 != V_143 )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( ! V_7 -> V_327 -> V_340 )
return - V_558 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1761 ) ;
if ( ! V_359 ) {
V_35 = - V_89 ;
goto V_680;
}
V_700 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_35 = F_406 ( V_7 , V_557 , V_700 , & V_670 ) ;
if ( V_35 )
goto V_680;
if ( F_104 ( V_51 , V_1596 , V_670 ,
V_604 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
V_35 = - V_89 ;
V_680:
F_76 ( V_51 ) ;
return V_35 ;
}
static int F_407 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1762 * V_1763 , * V_1764 ;
int V_1765 ;
if ( ! ( V_7 -> V_18 . V_49 & V_344 ) )
return - V_558 ;
V_1764 = F_37 ( sizeof( * V_1764 ) , V_134 ) ;
if ( ! V_1764 )
return - V_135 ;
F_294 ( & V_7 -> V_1766 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1763 -> V_1767 == V_30 -> V_522 ) {
V_1765 = - V_789 ;
goto V_963;
}
}
V_1764 -> V_1767 = V_30 -> V_522 ;
F_408 ( & V_1764 -> V_663 , & V_7 -> V_1768 ) ;
F_296 ( & V_7 -> V_1766 ) ;
return 0 ;
V_963:
F_296 ( & V_7 -> V_1766 ) ;
F_39 ( V_1764 ) ;
return V_1765 ;
}
static int F_409 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_327 -> V_346 )
return - V_558 ;
if ( V_17 -> V_140 != V_154 )
return - V_558 ;
if ( F_410 ( V_17 ) )
return 0 ;
if ( F_411 ( V_7 -> V_1769 ) )
return - V_1770 ;
V_35 = F_412 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1771 = true ;
V_7 -> V_1772 ++ ;
return 0 ;
}
static int F_413 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
if ( V_17 -> V_140 != V_154 )
return - V_558 ;
if ( ! V_7 -> V_327 -> V_1773 )
return - V_558 ;
F_414 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_415 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
struct V_1774 V_1775 = {} ;
int V_35 ;
if ( V_17 -> V_140 != V_153 )
return - V_558 ;
if ( F_410 ( V_17 ) )
return - V_1776 ;
if ( F_411 ( V_7 -> V_1769 ) )
return - V_1770 ;
if ( ! V_30 -> V_5 [ V_1777 ] )
return - V_16 ;
V_1775 . V_1778 =
F_32 ( V_30 -> V_5 [ V_1777 ] ) ;
if ( ! V_1775 . V_1778 )
return - V_16 ;
if ( V_30 -> V_5 [ V_511 ] ) {
V_22 V_437 = F_4 ( V_30 -> V_5 [ V_511 ] ) ;
if ( V_437 & ~ ( V_22 ) V_17 -> V_18 -> V_512 )
return - V_558 ;
if ( V_437 && ! ( V_437 & F_117 ( V_1779 ) ) )
return - V_16 ;
V_1775 . V_437 = V_437 ;
}
V_35 = F_416 ( V_7 , V_17 , & V_1775 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1771 = true ;
V_7 -> V_1772 ++ ;
return 0 ;
}
static int F_417 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
if ( V_17 -> V_140 != V_153 )
return - V_558 ;
F_418 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_419 ( struct V_4 * V_1780 )
{
struct V_4 * V_43 ;
int V_45 = 0 , V_688 = 0 , V_132 ;
F_36 (attr, filter_attr, rem) {
V_45 += F_22 ( V_43 ) ;
V_688 ++ ;
}
if ( V_45 >= V_1781 )
return - V_16 ;
return V_688 ;
}
static int F_420 ( struct V_4 * V_1782 ,
struct V_1783 * V_1784 ,
bool V_277 )
{
struct V_4 * V_43 ;
int V_688 , V_132 , V_159 ;
struct V_1785 * V_1786 ;
V_688 = F_419 ( V_1782 ) ;
if ( V_688 < 0 )
return V_688 ;
F_114 ( sizeof( * V_1784 -> V_1787 ) != sizeof( * V_1784 -> V_1788 ) ) ;
V_1786 = F_392 ( V_688 , sizeof( * V_1784 -> V_1787 ) , V_134 ) ;
if ( ! V_1786 )
return - V_135 ;
V_159 = 0 ;
F_36 (attr, attr_filter, rem) {
V_1786 [ V_159 ] . V_1786 = F_421 ( V_43 , V_134 ) ;
V_1786 [ V_159 ] . V_45 = F_22 ( V_43 ) ;
V_159 ++ ;
}
if ( V_277 ) {
V_1784 -> V_1789 = V_688 ;
V_1784 -> V_1788 = V_1786 ;
} else {
V_1784 -> V_1790 = V_688 ;
V_1784 -> V_1787 = V_1786 ;
}
return 0 ;
}
static int F_422 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
struct V_4 * V_93 [ V_1791 ] , * V_1792 ;
struct V_1783 * V_1784 ;
struct V_31 * V_51 = NULL ;
void * V_359 = NULL ;
int V_35 = 0 ;
if ( V_17 -> V_140 != V_153 )
return - V_558 ;
if ( ! F_410 ( V_17 ) )
return - V_1369 ;
if ( ! V_30 -> V_5 [ V_1793 ] )
return - V_16 ;
if ( V_17 -> V_657 &&
V_17 -> V_657 != V_30 -> V_522 )
return - V_1369 ;
V_35 = F_31 ( V_93 , V_1794 ,
V_30 -> V_5 [ V_1793 ] ,
V_1795 ) ;
if ( V_35 )
return V_35 ;
V_1784 = F_37 ( sizeof( * V_1784 ) , V_134 ) ;
if ( ! V_1784 )
return - V_135 ;
V_1784 -> V_670 = V_17 -> V_18 -> V_1796 ++ ;
if ( ! V_93 [ V_1797 ] ||
F_32 ( V_93 [ V_1797 ] ) > V_1798 ) {
V_35 = - V_16 ;
goto V_618;
}
V_1784 -> type = F_32 ( V_93 [ V_1797 ] ) ;
if ( ! V_93 [ V_1799 ] ) {
V_35 = - V_16 ;
goto V_618;
}
memcpy ( V_1784 -> V_1800 , F_21 ( V_93 [ V_1799 ] ) ,
sizeof( V_1784 -> V_1800 ) ) ;
V_1784 -> V_1801 =
F_169 ( V_93 [ V_1802 ] ) ;
if ( V_93 [ V_1803 ] ) {
V_1784 -> V_1804 =
F_22 ( V_93 [ V_1803 ] ) ;
V_1784 -> V_1805 =
F_394 ( F_21 ( V_93 [ V_1803 ] ) ,
V_1784 -> V_1804 ,
V_134 ) ;
if ( ! V_1784 -> V_1805 ) {
V_35 = - V_135 ;
goto V_618;
}
}
if ( V_93 [ V_1806 ] )
V_1784 -> V_1807 = F_4 ( V_93 [ V_1806 ] ) ;
switch ( V_1784 -> type ) {
case V_1808 :
if ( ! V_93 [ V_1809 ] ) {
V_35 = - V_16 ;
goto V_618;
}
V_1784 -> V_1810 =
F_32 ( V_93 [ V_1809 ] ) ;
V_1784 -> V_1811 =
F_169 ( V_93 [ V_1812 ] ) ;
if ( ( ! ( V_1784 -> V_1810 & V_1813 ) ) &&
V_1784 -> V_1811 ) {
V_35 = - V_16 ;
goto V_618;
}
break;
case V_1814 :
V_1784 -> V_1815 =
F_169 ( V_93 [ V_1816 ] ) ;
break;
case V_1817 :
if ( ! V_93 [ V_1818 ] ||
! V_93 [ V_1819 ] ) {
V_35 = - V_16 ;
goto V_618;
}
V_1784 -> V_1820 =
F_32 ( V_93 [ V_1818 ] ) ;
V_1784 -> V_1821 =
F_32 ( V_93 [ V_1819 ] ) ;
memcpy ( V_1784 -> V_1822 . V_700 ,
F_21 ( V_93 [ V_1823 ] ) ,
sizeof( V_1784 -> V_1822 . V_700 ) ) ;
if ( V_1784 -> V_1807 ) {
V_35 = - V_16 ;
goto V_618;
}
break;
default:
V_35 = - V_16 ;
goto V_618;
}
if ( V_93 [ V_1824 ] ) {
struct V_4 * V_1825 [ V_1826 ] ;
V_35 = F_31 ( V_1825 , V_1827 ,
V_93 [ V_1824 ] ,
V_1828 ) ;
if ( V_35 )
goto V_618;
V_1784 -> V_1829 =
F_169 ( V_1825 [ V_1830 ] ) ;
if ( V_1825 [ V_1831 ] ) {
if ( V_1825 [ V_1832 ] ||
! V_1825 [ V_1833 ] ) {
V_35 = - V_16 ;
goto V_618;
}
V_1784 -> V_1834 =
F_22 ( V_1825 [ V_1831 ] ) ;
V_1784 -> V_1835 =
F_394 ( F_21 ( V_1825 [ V_1831 ] ) ,
V_1784 -> V_1834 , V_134 ) ;
if ( ! V_1784 -> V_1835 ) {
V_35 = - V_135 ;
goto V_618;
}
V_1784 -> V_1836 =
F_32 ( V_1825 [ V_1833 ] ) ;
} else {
struct V_4 * V_43 , * V_1837 =
V_1825 [ V_1832 ] ;
int V_688 , V_132 , V_159 = 0 ;
if ( ! V_1837 ) {
V_35 = - V_16 ;
goto V_618;
}
V_688 = F_144 ( V_1837 ) ;
if ( V_688 <= 0 ) {
V_35 = - V_16 ;
goto V_618;
}
V_1784 -> V_1838 = V_688 ;
V_1784 -> V_1839 =
F_37 ( sizeof( * V_1784 -> V_1839 ) * V_688 ,
V_134 ) ;
if ( ! V_1784 -> V_1839 ) {
V_35 = - V_135 ;
goto V_618;
}
F_36 (attr, mac_attr, rem)
memcpy ( V_1784 -> V_1839 [ V_159 ++ ] . V_700 , F_21 ( V_43 ) ,
sizeof( * V_1784 -> V_1839 ) ) ;
}
}
if ( V_93 [ V_1840 ] ) {
V_35 = F_420 ( V_93 [ V_1840 ] ,
V_1784 , true ) ;
if ( V_35 )
goto V_618;
}
if ( V_93 [ V_1841 ] ) {
V_35 = F_420 ( V_93 [ V_1841 ] ,
V_1784 , false ) ;
if ( V_35 )
goto V_618;
}
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 ) {
V_35 = - V_135 ;
goto V_618;
}
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1842 ) ;
if ( F_60 ( ! V_359 ) ) {
V_35 = - V_135 ;
goto V_618;
}
V_35 = F_423 ( V_7 , V_17 , V_1784 ) ;
V_618:
if ( V_35 < 0 ) {
F_424 ( V_1784 ) ;
F_76 ( V_51 ) ;
return V_35 ;
}
if ( F_104 ( V_51 , V_1596 , V_1784 -> V_670 ,
V_604 ) )
goto V_59;
V_1792 = F_45 ( V_51 , V_1793 ) ;
if ( ! V_1792 )
goto V_59;
if ( F_54 ( V_51 , V_1843 ,
V_1784 -> V_1844 ) )
goto V_59;
F_46 ( V_51 , V_1792 ) ;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_76 ( V_51 ) ;
return - V_89 ;
}
static int F_425 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
T_1 V_670 ;
if ( V_17 -> V_140 != V_153 )
return - V_558 ;
if ( ! F_410 ( V_17 ) )
return - V_1369 ;
if ( ! V_30 -> V_5 [ V_1596 ] )
return - V_16 ;
if ( V_17 -> V_657 &&
V_17 -> V_657 != V_30 -> V_522 )
return - V_1369 ;
V_670 = F_5 ( V_30 -> V_5 [ V_1596 ] ) ;
F_426 ( V_7 , V_17 , V_670 ) ;
return 0 ;
}
static int F_427 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
struct V_1774 V_1775 = {} ;
V_22 V_568 = 0 ;
if ( V_17 -> V_140 != V_153 )
return - V_558 ;
if ( ! F_410 ( V_17 ) )
return - V_1369 ;
if ( V_30 -> V_5 [ V_1777 ] ) {
V_1775 . V_1778 =
F_32 ( V_30 -> V_5 [ V_1777 ] ) ;
if ( V_1775 . V_1778 <= 1 || V_1775 . V_1778 == 255 )
return - V_16 ;
V_568 |= V_1845 ;
}
if ( V_30 -> V_5 [ V_511 ] ) {
V_22 V_437 = F_4 ( V_30 -> V_5 [ V_511 ] ) ;
if ( V_437 & ~ ( V_22 ) V_17 -> V_18 -> V_512 )
return - V_558 ;
if ( V_437 && ! ( V_437 & F_117 ( V_1779 ) ) )
return - V_16 ;
V_1775 . V_437 = V_437 ;
V_568 |= V_1846 ;
}
if ( ! V_568 )
return - V_16 ;
return F_428 ( V_7 , V_17 , & V_1775 , V_568 ) ;
}
void F_429 ( struct V_1 * V_17 ,
struct V_1847 * V_1674 , T_10 V_1540 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_4 * V_1848 , * V_1849 , * V_1850 ;
struct V_31 * V_51 ;
void * V_359 ;
if ( F_60 ( ! V_1674 -> V_1851 || ! V_1674 -> V_1852 || ! V_1674 -> V_700 ) )
return;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1853 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_59;
if ( F_104 ( V_51 , V_1596 , V_1674 -> V_670 ,
V_604 ) ||
F_49 ( V_51 , V_565 , V_605 , V_1674 -> V_700 ) )
goto V_59;
V_1848 = F_45 ( V_51 , V_1854 ) ;
if ( ! V_1848 )
goto V_59;
V_1849 = F_45 ( V_51 , V_1855 ) ;
if ( ! V_1849 )
goto V_59;
if ( F_54 ( V_51 , V_1843 , V_1674 -> V_1851 ) )
goto V_59;
F_46 ( V_51 , V_1849 ) ;
V_1850 = F_45 ( V_51 , V_1856 ) ;
if ( ! V_1850 )
goto V_59;
if ( F_54 ( V_51 , V_1797 , V_1674 -> type ) ||
F_54 ( V_51 , V_1843 , V_1674 -> V_1852 ) )
goto V_59;
if ( V_1674 -> V_30 && V_1674 -> V_1857 &&
F_49 ( V_51 , V_1803 , V_1674 -> V_1857 ,
V_1674 -> V_30 ) )
goto V_59;
F_46 ( V_51 , V_1850 ) ;
F_46 ( V_51 , V_1848 ) ;
F_65 ( V_51 , V_359 ) ;
if ( ! V_17 -> V_657 )
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_51 , 0 , V_1858 , V_1540 ) ;
else
F_430 ( F_7 ( & V_7 -> V_18 ) , V_51 ,
V_17 -> V_657 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_431 ( struct V_1 * V_17 ,
T_2 V_1851 ,
enum V_1859 V_1566 ,
T_1 V_670 , T_10 V_1540 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
struct V_4 * V_1792 ;
void * V_359 ;
if ( F_60 ( ! V_1851 ) )
return;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1860 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_59;
if ( F_104 ( V_51 , V_1596 , V_670 ,
V_604 ) )
goto V_59;
V_1792 = F_45 ( V_51 , V_1793 ) ;
if ( ! V_1792 )
goto V_59;
if ( F_54 ( V_51 , V_1843 , V_1851 ) ||
F_54 ( V_51 , V_1861 , V_1566 ) )
goto V_59;
F_46 ( V_51 , V_1792 ) ;
F_65 ( V_51 , V_359 ) ;
if ( ! V_17 -> V_657 )
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_51 , 0 , V_1858 , V_1540 ) ;
else
F_430 ( F_7 ( & V_7 -> V_18 ) , V_51 ,
V_17 -> V_657 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
static int F_432 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_359 ;
struct V_31 * V_51 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , V_30 -> V_522 , V_30 -> V_523 , 0 ,
V_1862 ) ;
if ( ! V_359 )
goto V_59;
if ( F_26 ( V_51 , V_1863 ,
V_1864 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_77 ( V_51 , V_30 ) ;
V_59:
F_321 ( V_51 ) ;
return - V_89 ;
}
static int F_433 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1865 V_1866 ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
if ( ! V_7 -> V_327 -> V_1867 )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_1868 ] ||
! F_20 ( V_30 -> V_5 [ V_749 ] ) )
return - V_16 ;
memset ( & V_1866 , 0 , sizeof( V_1866 ) ) ;
V_1866 . V_1869 = F_79 ( V_30 -> V_5 [ V_1868 ] ) ;
V_1866 . V_1210 = F_21 ( V_30 -> V_5 [ V_749 ] ) ;
V_1866 . V_1211 = F_22 ( V_30 -> V_5 [ V_749 ] ) ;
return F_434 ( V_7 , V_557 , & V_1866 ) ;
}
static int F_435 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
enum V_1870 V_1477 = V_1871 ;
T_3 V_1304 ;
int V_514 ;
if ( ! V_7 -> V_327 -> V_443 )
return - V_558 ;
if ( F_60 ( ! V_7 -> V_327 -> V_445 ) )
return - V_16 ;
if ( V_7 -> V_1872 )
return - V_562 ;
if ( V_30 -> V_5 [ V_1873 ] )
V_1477 = F_79 ( V_30 -> V_5 [ V_1873 ] ) ;
if ( V_1477 >= V_1874 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1875 ] )
return - V_16 ;
V_1304 =
F_79 ( V_30 -> V_5 [ V_1875 ] ) ;
if ( V_1304 > V_1876 )
return - V_1751 ;
V_514 = F_436 ( V_7 , V_17 , V_1477 , V_1304 ) ;
if ( ! V_514 )
V_7 -> V_1872 = V_30 -> V_522 ;
return V_514 ;
}
static int F_437 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
if ( ! V_7 -> V_327 -> V_445 )
return - V_558 ;
if ( V_7 -> V_1872 ) {
V_7 -> V_1872 = 0 ;
F_438 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_439 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_95 ( V_30 ) , V_30 -> V_5 ) ;
int V_159 , V_35 ;
V_22 V_1877 , V_1544 ;
if ( ! V_7 -> V_18 . V_490 )
return - V_558 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1541 ] ||
! V_30 -> V_5 [ V_1543 ] )
return - V_16 ;
V_1877 = F_4 ( V_30 -> V_5 [ V_1541 ] ) ;
V_1544 = F_4 ( V_30 -> V_5 [ V_1543 ] ) ;
for ( V_159 = 0 ; V_159 < V_7 -> V_18 . V_486 ; V_159 ++ ) {
const struct V_1878 * V_1879 ;
void * V_139 = NULL ;
int V_45 = 0 ;
V_1879 = & V_7 -> V_18 . V_490 [ V_159 ] ;
if ( V_1879 -> V_30 . V_1542 != V_1877 || V_1879 -> V_30 . V_1544 != V_1544 )
continue;
if ( V_1879 -> V_49 & ( V_1880 |
V_1881 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1879 -> V_49 & V_1881 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1879 -> V_49 & V_1882 ) {
if ( ! F_410 ( V_17 ) )
return - V_572 ;
}
if ( ! V_1879 -> V_1883 )
return - V_558 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_489 ] ) {
V_139 = F_21 ( V_30 -> V_5 [ V_489 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_489 ] ) ;
}
V_7 -> V_1553 = V_30 ;
V_35 = V_7 -> V_18 . V_490 [ V_159 ] . V_1883 ( & V_7 -> V_18 , V_17 ,
V_139 , V_45 ) ;
V_7 -> V_1553 = NULL ;
return V_35 ;
}
return - V_558 ;
}
static int F_440 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
struct V_4 * * V_1456 = F_15 ( & V_38 ) ;
V_22 V_1877 , V_1544 ;
unsigned int V_159 ;
int V_1884 = - 1 ;
int V_35 ;
void * V_139 = NULL ;
unsigned int V_1555 = 0 ;
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
V_35 = F_14 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_1456 , V_38 . V_40 , V_41 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1456 [ V_1541 ] ||
! V_1456 [ V_1543 ] )
return - V_16 ;
* V_17 = F_1 ( F_16 ( V_32 -> V_42 ) , V_1456 ) ;
if ( F_17 ( * V_17 ) )
* V_17 = NULL ;
* V_7 = F_8 ( F_16 ( V_32 -> V_42 ) , V_1456 ) ;
if ( F_17 ( * V_7 ) )
return F_18 ( * V_7 ) ;
V_1877 = F_4 ( V_1456 [ V_1541 ] ) ;
V_1544 = F_4 ( V_1456 [ V_1543 ] ) ;
for ( V_159 = 0 ; V_159 < ( * V_7 ) -> V_18 . V_486 ; V_159 ++ ) {
const struct V_1878 * V_1879 ;
V_1879 = & ( * V_7 ) -> V_18 . V_490 [ V_159 ] ;
if ( V_1879 -> V_30 . V_1542 != V_1877 || V_1879 -> V_30 . V_1544 != V_1544 )
continue;
if ( ! V_1879 -> V_1885 )
return - V_558 ;
V_1884 = V_159 ;
break;
}
if ( V_1884 < 0 )
return - V_558 ;
if ( V_1456 [ V_489 ] ) {
V_139 = F_21 ( V_1456 [ V_489 ] ) ;
V_1555 = F_22 ( V_1456 [ V_489 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1884 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_139 ;
V_34 -> args [ 4 ] = V_1555 ;
return 0 ;
}
static int F_441 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
unsigned int V_1884 ;
const struct V_1878 * V_1879 ;
void * V_139 ;
int V_1555 ;
int V_35 ;
struct V_4 * V_1886 ;
F_69 () ;
V_35 = F_440 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
goto V_618;
V_1884 = V_34 -> args [ 2 ] ;
V_139 = ( void * ) V_34 -> args [ 3 ] ;
V_1555 = V_34 -> args [ 4 ] ;
V_1879 = & V_7 -> V_18 . V_490 [ V_1884 ] ;
if ( V_1879 -> V_49 & ( V_1880 |
V_1881 ) ) {
if ( ! V_17 ) {
V_35 = - V_16 ;
goto V_618;
}
if ( V_1879 -> V_49 & V_1881 &&
! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_618;
}
if ( V_1879 -> V_49 & V_1882 ) {
if ( ! F_410 ( V_17 ) ) {
V_35 = - V_572 ;
goto V_618;
}
}
}
while ( 1 ) {
void * V_359 = F_23 ( V_32 , F_72 ( V_34 -> V_32 ) . V_47 ,
V_34 -> V_36 -> V_518 , V_519 ,
V_1547 ) ;
if ( ! V_359 )
break;
if ( F_26 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ,
V_604 ) ) ) {
F_66 ( V_32 , V_359 ) ;
break;
}
V_1886 = F_45 ( V_32 , V_489 ) ;
if ( ! V_1886 ) {
F_66 ( V_32 , V_359 ) ;
break;
}
V_35 = V_1879 -> V_1885 ( & V_7 -> V_18 , V_17 , V_32 , V_139 , V_1555 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_46 ( V_32 , V_1886 ) ;
if ( V_35 == - V_89 || V_35 == - V_678 ) {
F_66 ( V_32 , V_359 ) ;
break;
} else if ( V_35 ) {
F_66 ( V_32 , V_359 ) ;
goto V_618;
}
F_65 ( V_32 , V_359 ) ;
}
V_35 = V_32 -> V_45 ;
V_618:
F_70 () ;
return V_35 ;
}
struct V_31 * F_442 ( struct V_18 * V_18 ,
enum V_356 V_50 ,
enum V_844 V_43 ,
int V_1539 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_60 ( ! V_7 -> V_1553 ) )
return NULL ;
return F_320 ( V_7 , NULL , V_1539 ,
V_7 -> V_1553 -> V_522 ,
V_7 -> V_1553 -> V_523 ,
V_50 , V_43 , NULL , V_134 ) ;
}
int F_443 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_359 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_139 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_60 ( ! V_7 -> V_1553 ) ) {
F_321 ( V_32 ) ;
return - V_16 ;
}
F_46 ( V_32 , V_139 ) ;
F_65 ( V_32 , V_359 ) ;
return F_77 ( V_32 , V_7 -> V_1553 ) ;
}
static int F_444 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_1887 * V_1888 = NULL ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
T_2 * V_44 , V_45 , V_1889 , V_1890 , V_1891 ;
int V_514 ;
if ( ! V_7 -> V_327 -> V_450 )
return - V_558 ;
if ( V_30 -> V_5 [ V_1892 ] ) {
V_44 = F_21 ( V_30 -> V_5 [ V_1892 ] ) ;
V_45 = F_22 ( V_30 -> V_5 [ V_1892 ] ) ;
if ( V_45 % 2 || V_45 < V_1893 ||
V_45 > V_1894 )
return - V_16 ;
V_1888 = F_37 ( sizeof( struct V_1887 ) , V_134 ) ;
if ( ! V_1888 )
return - V_135 ;
V_1889 = ( V_45 - V_1893 ) >> 1 ;
if ( V_1889 ) {
V_1890 = V_1889 *
sizeof( struct V_1895 ) ;
memcpy ( V_1888 -> V_1896 , V_44 , V_1890 ) ;
V_1888 -> V_1889 = V_1889 ;
for ( V_1891 = 0 ; V_1891 < V_1889 ; V_1891 ++ ) {
if ( V_1888 -> V_1896 [ V_1891 ] . V_1897 > 7 ) {
F_39 ( V_1888 ) ;
return - V_16 ;
}
}
V_44 += V_1890 ;
}
memcpy ( V_1888 -> V_1897 , V_44 , V_1893 ) ;
}
F_113 ( V_557 -> V_28 ) ;
V_514 = F_40 ( V_557 -> V_28 ) ;
if ( ! V_514 )
V_514 = F_445 ( V_7 , V_557 , V_1888 ) ;
F_115 ( V_557 -> V_28 ) ;
F_39 ( V_1888 ) ;
return V_514 ;
}
static int F_446 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
const T_2 * V_1583 ;
T_2 V_1898 , V_1897 ;
T_3 V_1899 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_367 & V_452 ) )
return - V_558 ;
if ( ! V_30 -> V_5 [ V_1900 ] || ! V_30 -> V_5 [ V_565 ] ||
! V_30 -> V_5 [ V_1901 ] )
return - V_16 ;
V_1898 = F_32 ( V_30 -> V_5 [ V_1900 ] ) ;
if ( V_1898 >= V_947 )
return - V_16 ;
V_1897 = F_32 ( V_30 -> V_5 [ V_1901 ] ) ;
if ( V_1897 >= V_1902 )
return - V_16 ;
if ( V_1898 >= V_1903 ) {
return - V_16 ;
}
V_1583 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
if ( V_30 -> V_5 [ V_1904 ] ) {
V_1899 =
F_79 ( V_30 -> V_5 [ V_1904 ] ) ;
if ( ! V_1899 )
return - V_16 ;
}
F_113 ( V_17 ) ;
switch ( V_17 -> V_140 ) {
case V_146 :
case V_147 :
if ( V_17 -> V_148 )
break;
V_35 = - V_1369 ;
goto V_618;
default:
V_35 = - V_558 ;
goto V_618;
}
V_35 = F_447 ( V_7 , V_557 , V_1898 , V_1583 , V_1897 , V_1899 ) ;
V_618:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_448 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
const T_2 * V_1583 ;
T_2 V_1898 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1900 ] || ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_1898 = F_32 ( V_30 -> V_5 [ V_1900 ] ) ;
V_1583 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_449 ( V_7 , V_557 , V_1898 , V_1583 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_450 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_537 V_538 = {} ;
const T_2 * V_700 ;
T_2 V_1905 ;
int V_35 ;
if ( ! V_7 -> V_327 -> V_1906 ||
! ( V_7 -> V_18 . V_367 & V_1907 ) )
return - V_558 ;
switch ( V_557 -> V_28 -> V_140 ) {
case V_146 :
case V_147 :
break;
default:
return - V_558 ;
}
if ( ! V_30 -> V_5 [ V_565 ] ||
! V_30 -> V_5 [ V_1908 ] )
return - V_16 ;
V_35 = F_81 ( V_7 , V_30 , & V_538 ) ;
if ( V_35 )
return V_35 ;
if ( V_538 . V_53 -> V_366 == V_1779 &&
V_538 . V_541 != V_542 &&
V_538 . V_541 != V_597 )
return - V_16 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_538 ,
V_17 -> V_140 ) )
return - V_16 ;
if ( F_284 ( V_17 -> V_18 , & V_538 , V_17 -> V_140 ) )
return - V_16 ;
V_700 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
V_1905 = F_32 ( V_30 -> V_5 [ V_1908 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_451 ( V_7 , V_557 , V_700 , V_1905 , & V_538 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_452 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
const T_2 * V_700 ;
if ( ! V_7 -> V_327 -> V_1906 ||
! V_7 -> V_327 -> V_1909 ||
! ( V_7 -> V_18 . V_367 & V_1907 ) )
return - V_558 ;
switch ( V_557 -> V_28 -> V_140 ) {
case V_146 :
case V_147 :
break;
default:
return - V_558 ;
}
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
V_700 = F_21 ( V_30 -> V_5 [ V_565 ] ) ;
F_113 ( V_17 ) ;
F_453 ( V_7 , V_557 , V_700 ) ;
F_115 ( V_17 ) ;
return 0 ;
}
static int F_454 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_521 [ 0 ] ;
struct V_25 * V_557 = V_30 -> V_521 [ 1 ] ;
struct V_1 * V_17 = V_557 -> V_28 ;
const struct V_4 * V_620 ;
bool V_1910 ;
if ( ! V_7 -> V_327 -> V_455 )
return - V_558 ;
if ( V_17 -> V_140 != V_141 &&
V_17 -> V_140 != V_143 )
return - V_558 ;
V_620 = V_30 -> V_5 [ V_1911 ] ;
V_1910 = F_169 ( V_620 ) ;
return F_455 ( V_7 , V_557 , V_1910 ) ;
}
static int F_456 ( const struct V_1912 * V_327 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_557 ;
bool V_1913 = V_327 -> V_1914 & V_1915 ;
if ( V_1913 )
F_69 () ;
if ( V_327 -> V_1914 & V_1916 ) {
V_7 = F_12 ( F_95 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1913 )
F_70 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_521 [ 0 ] = V_7 ;
} else if ( V_327 -> V_1914 & V_1917 ||
V_327 -> V_1914 & V_1918 ) {
F_2 () ;
V_17 = F_1 ( F_95 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1913 )
F_70 () ;
return F_18 ( V_17 ) ;
}
V_557 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_327 -> V_1914 & V_1917 ) {
if ( ! V_557 ) {
if ( V_1913 )
F_70 () ;
return - V_16 ;
}
V_30 -> V_521 [ 1 ] = V_557 ;
} else {
V_30 -> V_521 [ 1 ] = V_17 ;
}
if ( V_327 -> V_1914 & V_1919 &&
! F_410 ( V_17 ) ) {
if ( V_1913 )
F_70 () ;
return - V_572 ;
}
if ( V_557 )
F_268 ( V_557 ) ;
V_30 -> V_521 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_457 ( const struct V_1912 * V_327 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_521 [ 1 ] ) {
if ( V_327 -> V_1914 & V_1918 ) {
struct V_1 * V_17 = V_30 -> V_521 [ 1 ] ;
if ( V_17 -> V_19 )
F_190 ( V_17 -> V_19 ) ;
} else {
F_190 ( V_30 -> V_521 [ 1 ] ) ;
}
}
if ( V_327 -> V_1914 & V_1915 )
F_70 () ;
if ( V_327 -> V_1914 & V_1920 ) {
struct V_1921 * V_36 = F_458 ( V_32 ) ;
memset ( F_459 ( V_36 ) , 0 , F_460 ( V_36 ) ) ;
}
}
void F_461 ( struct V_6 * V_7 ,
enum V_356 V_50 )
{
struct V_31 * V_51 ;
struct V_357 V_358 = {} ;
F_60 ( V_50 != V_371 &&
V_50 != V_1922 ) ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return;
if ( F_59 ( V_7 , V_50 , V_51 , 0 , 0 , 0 , & V_358 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1923 , V_134 ) ;
}
void F_128 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
enum V_356 V_50 )
{
struct V_31 * V_51 ;
F_60 ( V_50 != V_600 &&
V_50 != V_601 ) ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return;
if ( F_103 ( V_51 , 0 , 0 , 0 , V_7 , V_17 ,
V_50 == V_601 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1923 , V_134 ) ;
}
static int F_462 ( struct V_31 * V_51 ,
struct V_6 * V_7 )
{
struct V_1290 * V_1493 = V_7 -> V_1294 ;
struct V_4 * V_1276 ;
int V_159 ;
if ( F_60 ( ! V_1493 ) )
return 0 ;
V_1276 = F_45 ( V_51 , V_1298 ) ;
if ( ! V_1276 )
goto V_59;
for ( V_159 = 0 ; V_159 < V_1493 -> V_1292 ; V_159 ++ ) {
if ( F_49 ( V_51 , V_159 , V_1493 -> V_1299 [ V_159 ] . V_610 , V_1493 -> V_1299 [ V_159 ] . V_612 ) )
goto V_59;
}
F_46 ( V_51 , V_1276 ) ;
V_1276 = F_45 ( V_51 , V_1297 ) ;
if ( ! V_1276 )
goto V_59;
for ( V_159 = 0 ; V_159 < V_1493 -> V_440 ; V_159 ++ ) {
if ( F_26 ( V_51 , V_159 , V_1493 -> V_441 [ V_159 ] -> V_58 ) )
goto V_59;
}
F_46 ( V_51 , V_1276 ) ;
if ( V_1493 -> V_1210 &&
F_49 ( V_51 , V_749 , V_1493 -> V_1211 , V_1493 -> V_1210 ) )
goto V_59;
if ( V_1493 -> V_49 &&
F_26 ( V_51 , V_1307 , V_1493 -> V_49 ) )
goto V_59;
if ( V_1493 -> V_30 . V_1924 &&
( F_104 ( V_51 , V_1925 ,
V_1493 -> V_30 . V_1924 , V_1400 ) ||
F_49 ( V_51 , V_1926 , V_605 ,
V_1493 -> V_30 . V_1927 ) ) )
goto V_59;
return 0 ;
V_59:
return - V_89 ;
}
static int F_463 ( struct V_31 * V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_47 , V_22 V_48 , int V_49 ,
V_22 V_50 )
{
void * V_359 ;
V_359 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_359 )
return - 1 ;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_59;
F_462 ( V_51 , V_7 ) ;
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
static int
F_464 ( struct V_31 * V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_47 , V_22 V_48 , int V_49 , V_22 V_50 )
{
void * V_359 ;
V_359 = F_23 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
if ( ! V_359 )
return - 1 ;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return 0 ;
V_59:
F_66 ( V_51 , V_359 ) ;
return - V_513 ;
}
void F_267 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_51 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return;
if ( F_463 ( V_51 , V_7 , V_17 , 0 , 0 , 0 ,
V_1928 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1929 , V_134 ) ;
}
struct V_31 * F_465 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1930 )
{
struct V_31 * V_51 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return NULL ;
if ( F_463 ( V_51 , V_7 , V_17 , 0 , 0 , 0 ,
V_1930 ? V_1931 :
V_1392 ) < 0 ) {
F_76 ( V_51 ) ;
return NULL ;
}
return V_51 ;
}
void F_466 ( struct V_6 * V_7 ,
struct V_31 * V_51 )
{
if ( ! V_51 )
return;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1929 , V_134 ) ;
}
void F_278 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_50 )
{
struct V_31 * V_51 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return;
if ( F_464 ( V_51 , V_7 , V_19 , 0 , 0 , 0 , V_50 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1929 , V_134 ) ;
}
static bool F_467 ( struct V_31 * V_51 ,
struct V_1932 * V_1291 )
{
if ( F_54 ( V_51 , V_1933 , V_1291 -> V_1584 ) )
goto V_59;
if ( V_1291 -> V_1224 [ 0 ] == '0' && V_1291 -> V_1224 [ 1 ] == '0' ) {
if ( F_54 ( V_51 , V_1934 ,
V_1935 ) )
goto V_59;
} else if ( V_1291 -> V_1224 [ 0 ] == '9' && V_1291 -> V_1224 [ 1 ] == '9' ) {
if ( F_54 ( V_51 , V_1934 ,
V_1936 ) )
goto V_59;
} else if ( ( V_1291 -> V_1224 [ 0 ] == '9' && V_1291 -> V_1224 [ 1 ] == '8' ) ||
V_1291 -> V_1937 ) {
if ( F_54 ( V_51 , V_1934 ,
V_1938 ) )
goto V_59;
} else {
if ( F_54 ( V_51 , V_1934 ,
V_1939 ) ||
F_61 ( V_51 , V_1112 ,
V_1291 -> V_1224 ) )
goto V_59;
}
if ( V_1291 -> V_14 != V_1940 ) {
struct V_18 * V_18 = F_19 ( V_1291 -> V_14 ) ;
if ( V_18 &&
F_26 ( V_51 , V_26 , V_1291 -> V_14 ) )
goto V_59;
if ( V_18 &&
V_18 -> V_496 & V_497 &&
F_27 ( V_51 , V_498 ) )
goto V_59;
}
return true ;
V_59:
return false ;
}
void F_468 ( enum V_356 V_1941 ,
struct V_1932 * V_1291 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1941 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_467 ( V_51 , V_1291 ) == false )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_243 () ;
F_469 ( & V_38 , V_51 , 0 ,
V_1942 , V_1943 ) ;
F_245 () ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
static void F_470 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1607 , T_4 V_45 ,
enum V_356 V_50 , T_10 V_1540 ,
int V_1003 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( 100 + V_45 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_1604 , V_45 , V_1607 ) )
goto V_59;
if ( V_1003 >= 0 ) {
struct V_4 * V_1944 =
F_45 ( V_51 , V_1000 ) ;
if ( ! V_1944 )
goto V_59;
if ( F_54 ( V_51 , V_1002 ,
V_1003 ) )
goto V_59;
F_46 ( V_51 , V_1944 ) ;
}
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_471 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1607 ,
T_4 V_45 , T_10 V_1540 )
{
F_470 ( V_7 , V_19 , V_1607 , V_45 ,
V_781 , V_1540 , - 1 ) ;
}
void F_472 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1607 ,
T_4 V_45 , T_10 V_1540 , int V_1003 )
{
F_470 ( V_7 , V_19 , V_1607 , V_45 ,
V_1946 , V_1540 , V_1003 ) ;
}
void F_473 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1607 ,
T_4 V_45 , T_10 V_1540 )
{
F_470 ( V_7 , V_19 , V_1607 , V_45 ,
V_1947 , V_1540 , - 1 ) ;
}
void F_474 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1607 ,
T_4 V_45 , T_10 V_1540 )
{
F_470 ( V_7 , V_19 , V_1607 , V_45 ,
V_1948 , V_1540 , - 1 ) ;
}
void F_475 ( struct V_25 * V_557 , const T_2 * V_1607 ,
T_4 V_45 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1949 * V_1950 = ( void * ) V_1607 ;
V_22 V_50 ;
if ( F_60 ( V_45 < 2 ) )
return;
if ( F_476 ( V_1950 -> V_1951 ) )
V_50 = V_1952 ;
else
V_50 = V_1953 ;
F_477 ( V_557 , V_1607 , V_45 ) ;
F_470 ( V_7 , V_557 , V_1607 , V_45 , V_50 , V_1943 , - 1 ) ;
}
static void F_478 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_50 ,
const T_2 * V_700 , T_10 V_1540 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_27 ( V_51 , V_1954 ) ||
F_49 ( V_51 , V_565 , V_605 , V_700 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_479 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_700 ,
T_10 V_1540 )
{
F_478 ( V_7 , V_19 , V_781 ,
V_700 , V_1540 ) ;
}
void F_480 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_700 ,
T_10 V_1540 )
{
F_478 ( V_7 , V_19 , V_1946 ,
V_700 , V_1540 ) ;
}
void F_481 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_564 ,
const T_2 * V_1955 , T_4 V_1956 ,
const T_2 * V_1957 , T_4 V_1958 ,
int V_1959 ,
enum V_1960 V_1961 ,
T_10 V_1540 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( 100 + V_1956 + V_1958 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_353 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
( V_564 && F_49 ( V_51 , V_565 , V_605 , V_564 ) ) ||
F_53 ( V_51 , V_1586 ,
V_1959 < 0 ? V_1962 :
V_1959 ) ||
( V_1959 < 0 &&
( F_27 ( V_51 , V_1954 ) ||
F_26 ( V_51 , V_1963 , V_1961 ) ) ) ||
( V_1955 &&
F_49 ( V_51 , V_1964 , V_1956 , V_1955 ) ) ||
( V_1957 &&
F_49 ( V_51 , V_1965 , V_1958 , V_1957 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_482 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_564 ,
const T_2 * V_1955 , T_4 V_1956 ,
const T_2 * V_1957 , T_4 V_1958 , T_10 V_1540 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( 100 + V_1956 + V_1958 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1966 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_564 ) ||
( V_1955 &&
F_49 ( V_51 , V_1964 , V_1956 , V_1955 ) ) ||
( V_1957 &&
F_49 ( V_51 , V_1965 , V_1958 , V_1957 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_483 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1566 ,
const T_2 * V_1210 , T_4 V_1211 , bool V_1967 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( 100 + V_1211 , V_134 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_355 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
( V_1967 && V_1566 &&
F_53 ( V_51 , V_1051 , V_1566 ) ) ||
( V_1967 &&
F_27 ( V_51 , V_1968 ) ) ||
( V_1210 && F_49 ( V_51 , V_749 , V_1211 , V_1210 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_134 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_484 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_564 ,
T_10 V_1540 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1969 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_564 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_485 ( struct V_25 * V_557 , const T_2 * V_700 ,
const T_2 * V_1210 , T_2 V_1211 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
if ( F_60 ( V_17 -> V_140 != V_144 ) )
return;
F_486 ( V_557 , V_700 ) ;
V_51 = F_75 ( 100 + V_1211 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1970 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_700 ) ||
( V_1211 && V_1210 &&
F_49 ( V_51 , V_749 , V_1211 , V_1210 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_487 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_700 ,
enum V_1971 V_1972 , int V_1973 ,
const T_2 * V_1974 , T_10 V_1540 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1975 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
( V_700 && F_49 ( V_51 , V_565 , V_605 , V_700 ) ) ||
F_26 ( V_51 , V_125 , V_1972 ) ||
( V_1973 != - 1 &&
F_54 ( V_51 , V_121 , V_1973 ) ) ||
( V_1974 && F_49 ( V_51 , V_120 , 6 , V_1974 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_488 ( struct V_18 * V_18 ,
struct V_52 * V_1976 ,
struct V_52 * V_1977 )
{
struct V_31 * V_51 ;
void * V_359 ;
struct V_4 * V_363 ;
V_51 = F_75 ( V_619 , V_1943 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1978 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , F_241 ( V_18 ) ) )
goto V_59;
V_363 = F_45 ( V_51 , V_1979 ) ;
if ( ! V_363 )
goto V_59;
if ( F_25 ( V_51 , V_1976 , false ) )
goto V_59;
F_46 ( V_51 , V_363 ) ;
V_363 = F_45 ( V_51 , V_1980 ) ;
if ( ! V_363 )
goto V_59;
if ( F_25 ( V_51 , V_1977 , false ) )
goto V_59;
F_46 ( V_51 , V_363 ) ;
F_65 ( V_51 , V_359 ) ;
F_243 () ;
F_469 ( & V_38 , V_51 , 0 ,
V_1942 , V_1943 ) ;
F_245 () ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
static void F_489 (
int V_50 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_670 ,
struct V_52 * V_53 ,
unsigned int V_1304 , T_10 V_1540 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) ||
F_26 ( V_51 , V_540 , V_53 -> V_58 ) ||
F_26 ( V_51 , V_545 ,
V_548 ) ||
F_104 ( V_51 , V_1596 , V_670 ,
V_604 ) )
goto V_59;
if ( V_50 == V_1595 &&
F_26 ( V_51 , V_1593 , V_1304 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_490 ( struct V_1 * V_17 , T_1 V_670 ,
struct V_52 * V_53 ,
unsigned int V_1304 , T_10 V_1540 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_491 ( V_17 , V_670 , V_53 , V_1304 ) ;
F_489 ( V_1595 ,
V_7 , V_17 , V_670 , V_53 ,
V_1304 , V_1540 ) ;
}
void F_492 ( struct V_1 * V_17 , T_1 V_670 ,
struct V_52 * V_53 ,
T_10 V_1540 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_493 ( V_17 , V_670 , V_53 ) ;
F_489 ( V_1981 ,
V_7 , V_17 , V_670 , V_53 , 0 , V_1540 ) ;
}
void F_494 ( struct V_25 * V_557 , const T_2 * V_672 ,
struct V_869 * V_870 , T_10 V_1540 )
{
struct V_18 * V_18 = V_557 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
F_495 ( V_557 , V_672 , V_870 ) ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
if ( F_179 ( V_51 , V_965 , 0 , 0 , 0 ,
V_7 , V_557 , V_672 , V_870 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
}
void F_496 ( struct V_25 * V_557 , const T_2 * V_672 ,
struct V_869 * V_870 , T_10 V_1540 )
{
struct V_18 * V_18 = V_557 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
struct V_869 V_1982 = {} ;
if ( ! V_870 )
V_870 = & V_1982 ;
F_497 ( V_557 , V_672 ) ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
if ( F_179 ( V_51 , V_1983 , 0 , 0 , 0 ,
V_7 , V_557 , V_672 , V_870 ) < 0 ) {
F_76 ( V_51 ) ;
return;
}
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
}
void F_498 ( struct V_25 * V_557 , const T_2 * V_672 ,
enum V_1984 V_1566 ,
T_10 V_1540 )
{
struct V_18 * V_18 = V_557 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_1985 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1986 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_672 ) ||
F_26 ( V_51 , V_1987 , V_1566 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
static bool F_499 ( struct V_25 * V_557 , T_2 V_50 ,
const T_2 * V_700 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
V_22 V_1767 = F_500 ( V_17 -> V_1760 ) ;
if ( ! V_1767 )
return false ;
V_51 = F_75 ( 100 , V_1540 ) ;
if ( ! V_51 )
return true ;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_50 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return true ;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_700 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_430 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1767 ) ;
return true ;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
return true ;
}
bool F_501 ( struct V_25 * V_557 ,
const T_2 * V_700 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
bool V_514 ;
F_502 ( V_557 , V_700 ) ;
if ( F_60 ( V_17 -> V_140 != V_141 &&
V_17 -> V_140 != V_143 ) ) {
F_503 ( false ) ;
return false ;
}
V_514 = F_499 ( V_557 , V_1988 ,
V_700 , V_1540 ) ;
F_503 ( V_514 ) ;
return V_514 ;
}
bool F_504 ( struct V_25 * V_557 ,
const T_2 * V_700 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
bool V_514 ;
F_505 ( V_557 , V_700 ) ;
if ( F_60 ( V_17 -> V_140 != V_141 &&
V_17 -> V_140 != V_143 &&
V_17 -> V_140 != V_142 ) ) {
F_503 ( false ) ;
return false ;
}
V_514 = F_499 ( V_557 ,
V_1989 ,
V_700 , V_1540 ) ;
F_503 ( V_514 ) ;
return V_514 ;
}
int F_506 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1767 ,
int V_1990 , int V_1991 ,
const T_2 * V_1607 , T_4 V_45 , V_22 V_49 , T_10 V_1540 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( 100 + V_45 , V_1540 ) ;
if ( ! V_51 )
return - V_135 ;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1611 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return - V_135 ;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_26 ( V_51 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) ||
F_26 ( V_51 , V_540 , V_1990 ) ||
( V_1991 &&
F_26 ( V_51 , V_1992 , V_1991 ) ) ||
F_49 ( V_51 , V_1604 , V_45 , V_1607 ) ||
( V_49 &&
F_26 ( V_51 , V_1993 , V_49 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
return F_430 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1767 ) ;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
return - V_89 ;
}
void F_507 ( struct V_1 * V_17 , T_1 V_670 ,
const T_2 * V_1607 , T_4 V_45 , bool V_1994 , T_10 V_1540 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_51 ;
void * V_359 ;
F_508 ( V_17 , V_670 , V_1994 ) ;
V_51 = F_75 ( 100 + V_45 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1995 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_26 ( V_51 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) ||
F_49 ( V_51 , V_1604 , V_45 , V_1607 ) ||
F_104 ( V_51 , V_1596 , V_670 ,
V_604 ) ||
( V_1994 && F_27 ( V_51 , V_1996 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
static struct V_31 * F_509 ( struct V_25 * V_557 ,
const char * V_1045 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 = F_75 ( V_619 , V_1540 ) ;
void * * V_34 ;
if ( ! V_51 )
return NULL ;
V_34 = ( void * * ) V_51 -> V_34 ;
V_34 [ 0 ] = F_23 ( V_51 , 0 , 0 , 0 , V_1997 ) ;
if ( ! V_34 [ 0 ] ) {
F_76 ( V_51 ) ;
return NULL ;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_557 -> V_20 ) )
goto V_59;
if ( V_1045 && F_49 ( V_51 , V_565 , V_605 , V_1045 ) )
goto V_59;
V_34 [ 1 ] = F_45 ( V_51 , V_1630 ) ;
if ( ! V_34 [ 1 ] )
goto V_59;
V_34 [ 2 ] = V_7 ;
return V_51 ;
V_59:
F_76 ( V_51 ) ;
return NULL ;
}
static void F_510 ( struct V_31 * V_51 , T_10 V_1540 )
{
void * * V_34 = ( void * * ) V_51 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_46 ( V_51 , V_34 [ 1 ] ) ;
F_65 ( V_51 , V_34 [ 0 ] ) ;
memset ( V_51 -> V_34 , 0 , sizeof( V_51 -> V_34 ) ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
}
void F_511 ( struct V_25 * V_557 ,
enum V_1998 V_1999 ,
T_7 V_2000 , T_10 V_1540 )
{
struct V_31 * V_51 ;
F_512 ( V_557 , V_1999 , V_2000 ) ;
if ( F_60 ( V_1999 != V_2001 &&
V_1999 != V_2002 ) )
return;
V_51 = F_509 ( V_557 , NULL , V_1540 ) ;
if ( ! V_51 )
return;
if ( F_26 ( V_51 , V_2003 ,
V_1999 ) )
goto V_59;
if ( V_2000 && F_513 ( V_51 , V_2004 ,
V_2000 ) )
goto V_59;
F_510 ( V_51 , V_1540 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_514 ( struct V_25 * V_557 ,
const T_2 * V_1583 , V_22 V_2005 ,
V_22 V_246 , V_22 V_1622 , T_10 V_1540 )
{
struct V_31 * V_51 ;
V_51 = F_509 ( V_557 , V_1583 , V_1540 ) ;
if ( ! V_51 )
return;
if ( F_26 ( V_51 , V_1635 , V_2005 ) )
goto V_59;
if ( F_26 ( V_51 , V_1634 , V_246 ) )
goto V_59;
if ( F_26 ( V_51 , V_1636 , V_1622 ) )
goto V_59;
F_510 ( V_51 , V_1540 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_515 ( struct V_25 * V_557 ,
const T_2 * V_1583 , V_22 V_2005 , T_10 V_1540 )
{
struct V_31 * V_51 ;
F_516 ( V_557 , V_1583 , V_2005 ) ;
V_51 = F_509 ( V_557 , V_1583 , V_1540 ) ;
if ( ! V_51 )
return;
if ( F_26 ( V_51 , V_2006 , V_2005 ) )
goto V_59;
F_510 ( V_51 , V_1540 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
void F_517 ( struct V_25 * V_557 , T_10 V_1540 )
{
struct V_31 * V_51 ;
V_51 = F_509 ( V_557 , NULL , V_1540 ) ;
if ( ! V_51 )
return;
if ( F_27 ( V_51 , V_2007 ) )
goto V_59;
F_510 ( V_51 , V_1540 ) ;
return;
V_59:
F_76 ( V_51 ) ;
}
static void F_518 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_564 ,
const T_2 * V_1758 , T_10 V_1540 )
{
struct V_31 * V_51 ;
struct V_4 * V_2008 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2009 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_564 ) )
goto V_59;
V_2008 = F_45 ( V_51 , V_1746 ) ;
if ( ! V_2008 )
goto V_59;
if ( F_49 ( V_51 , V_1749 ,
V_1750 , V_1758 ) )
goto V_59;
F_46 ( V_51 , V_2008 ) ;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_519 ( struct V_25 * V_557 , const T_2 * V_564 ,
const T_2 * V_1758 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_520 ( V_557 , V_564 ) ;
F_518 ( V_7 , V_557 , V_564 , V_1758 , V_1540 ) ;
}
static void
F_521 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_2010 ,
const T_2 * V_564 , bool V_2011 , T_10 V_1540 )
{
struct V_31 * V_51 ;
struct V_4 * V_43 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2012 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) )
goto V_59;
V_43 = F_45 ( V_51 , V_2013 ) ;
if ( ! V_43 )
goto V_59;
if ( F_26 ( V_51 , V_2014 , V_2010 ) ||
F_49 ( V_51 , V_2015 , V_605 , V_564 ) ||
( V_2011 &&
F_27 ( V_51 , V_2016 ) ) )
goto V_59;
F_46 ( V_51 , V_43 ) ;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_522 ( struct V_25 * V_557 , int V_2010 ,
const T_2 * V_564 , bool V_2011 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_523 ( V_557 , V_2010 , V_564 , V_2011 ) ;
F_521 ( V_7 , V_557 , V_2010 , V_564 , V_2011 , V_1540 ) ;
}
static void F_524 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_537 * V_538 ,
T_10 V_1540 ,
enum V_356 V_2017 ,
T_2 V_1372 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2017 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_10 , V_19 -> V_20 ) )
goto V_59;
if ( F_101 ( V_51 , V_538 ) )
goto V_59;
if ( ( V_2017 == V_2018 ) &&
( F_26 ( V_51 , V_1370 , V_1372 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_525 ( struct V_25 * V_557 ,
struct V_537 * V_538 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_41 ( V_17 ) ;
F_526 ( V_557 , V_538 ) ;
V_17 -> V_538 = * V_538 ;
V_17 -> V_563 = * V_538 ;
F_524 ( V_7 , V_557 , V_538 , V_134 ,
V_2019 , 0 ) ;
}
void F_527 ( struct V_25 * V_557 ,
struct V_537 * V_538 ,
T_2 V_1372 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_528 ( V_557 , V_538 ) ;
F_524 ( V_7 , V_557 , V_538 , V_134 ,
V_2018 , V_1372 ) ;
}
void
F_529 ( struct V_6 * V_7 ,
const struct V_537 * V_538 ,
enum V_2020 V_2021 ,
struct V_25 * V_19 , T_10 V_1540 )
{
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2022 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_59;
}
if ( F_26 ( V_51 , V_2023 , V_2021 ) )
goto V_59;
if ( F_101 ( V_51 , V_538 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_530 ( struct V_25 * V_557 , const T_2 * V_700 ,
T_1 V_670 , bool V_2024 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
F_531 ( V_557 , V_700 , V_670 , V_2024 ) ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1761 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_700 ) ||
F_104 ( V_51 , V_1596 , V_670 ,
V_604 ) ||
( V_2024 && F_27 ( V_51 , V_1996 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_532 ( struct V_18 * V_18 ,
const T_2 * V_2025 , T_4 V_45 ,
int V_1990 , int V_1991 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
struct V_1762 * V_1763 ;
F_533 ( V_18 , V_2025 , V_45 , V_1990 , V_1991 ) ;
F_294 ( & V_7 -> V_1766 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_51 = F_75 ( V_45 + 100 , V_1943 ) ;
if ( ! V_51 ) {
F_296 ( & V_7 -> V_1766 ) ;
return;
}
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_1611 ) ;
if ( ! V_359 )
goto V_59;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
( V_1990 &&
F_26 ( V_51 , V_540 , V_1990 ) ) ||
( V_1991 &&
F_26 ( V_51 , V_1992 , V_1991 ) ) ||
F_49 ( V_51 , V_1604 , V_45 , V_2025 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_430 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1763 -> V_1767 ) ;
}
F_296 ( & V_7 -> V_1766 ) ;
return;
V_59:
F_296 ( & V_7 -> V_1766 ) ;
if ( V_359 )
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
static int F_534 ( struct V_31 * V_51 ,
struct V_2026 * V_2027 )
{
struct V_2028 * V_1672 = V_2027 -> V_2029 ;
struct V_4 * V_2030 , * V_2031 , * V_362 ;
int V_159 , V_161 ;
V_2030 = F_45 (
V_51 , V_2032 ) ;
if ( ! V_2030 )
return - V_513 ;
for ( V_159 = 0 ; V_159 < V_1672 -> V_2033 ; V_159 ++ ) {
struct V_2034 * V_1674 = V_1672 -> V_1673 [ V_159 ] ;
V_2031 = F_45 ( V_51 , V_159 ) ;
if ( ! V_2031 )
break;
if ( F_49 ( V_51 , V_611 , V_1674 -> V_612 . V_610 ,
V_1674 -> V_612 . V_612 ) ) {
F_535 ( V_51 , V_2031 ) ;
goto V_618;
}
if ( V_1674 -> V_440 ) {
V_362 = F_45 (
V_51 , V_1297 ) ;
if ( ! V_362 ) {
F_535 ( V_51 , V_2031 ) ;
goto V_618;
}
for ( V_161 = 0 ; V_161 < V_1674 -> V_440 ; V_161 ++ ) {
if ( F_26 ( V_51 , V_161 , V_1674 -> V_441 [ V_161 ] ) ) {
F_535 ( V_51 , V_362 ) ;
F_535 ( V_51 , V_2031 ) ;
goto V_618;
}
}
F_46 ( V_51 , V_362 ) ;
}
F_46 ( V_51 , V_2031 ) ;
}
V_618:
F_46 ( V_51 , V_2030 ) ;
return 0 ;
}
void F_536 ( struct V_1 * V_17 ,
struct V_2026 * V_2027 ,
T_10 V_1540 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
int V_1676 = 200 ;
F_537 ( V_17 -> V_18 , V_17 , V_2027 ) ;
if ( V_2027 )
V_1676 += V_2027 -> V_2035 ;
V_51 = F_75 ( V_1676 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2036 ) ;
if ( ! V_359 )
goto V_680;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_680;
if ( V_17 -> V_19 && F_26 ( V_51 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_680;
if ( V_2027 ) {
struct V_4 * V_2037 ;
V_2037 = F_45 ( V_51 , V_1678 ) ;
if ( ! V_2037 )
goto V_680;
if ( V_2027 -> V_354 &&
F_27 ( V_51 , V_208 ) )
goto V_680;
if ( V_2027 -> V_1680 &&
F_27 ( V_51 , V_210 ) )
goto V_680;
if ( V_2027 -> V_1681 &&
F_27 ( V_51 , V_214 ) )
goto V_680;
if ( V_2027 -> V_1682 &&
F_27 ( V_51 , V_216 ) )
goto V_680;
if ( V_2027 -> V_1683 &&
F_27 ( V_51 , V_218 ) )
goto V_680;
if ( V_2027 -> V_1684 &&
F_27 ( V_51 , V_220 ) )
goto V_680;
if ( V_2027 -> V_2038 >= 0 &&
F_26 ( V_51 , V_230 ,
V_2027 -> V_2038 ) )
goto V_680;
if ( V_2027 -> V_2039 &&
F_27 ( V_51 , V_2040 ) )
goto V_680;
if ( V_2027 -> V_2041 &&
F_27 ( V_51 , V_2042 ) )
goto V_680;
if ( V_2027 -> V_2043 &&
F_27 ( V_51 ,
V_2044 ) )
goto V_680;
if ( V_2027 -> V_2045 ) {
V_22 V_2046 = V_2047 ;
V_22 V_2048 = V_2049 ;
if ( ! V_2027 -> V_2050 ) {
V_2046 =
V_2051 ;
V_2048 =
V_2052 ;
}
if ( V_2027 -> V_2053 &&
F_26 ( V_51 , V_2048 , V_2027 -> V_2053 ) )
goto V_680;
if ( F_49 ( V_51 , V_2046 , V_2027 -> V_2035 ,
V_2027 -> V_2045 ) )
goto V_680;
}
if ( V_2027 -> V_2029 &&
F_534 ( V_51 , V_2027 ) )
goto V_680;
F_46 ( V_51 , V_2037 ) ;
}
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_680:
F_76 ( V_51 ) ;
}
void F_538 ( struct V_25 * V_557 , const T_2 * V_1583 ,
enum V_1590 V_2054 ,
T_3 V_1052 , T_10 V_1540 )
{
struct V_1 * V_17 = V_557 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
F_539 ( V_17 -> V_18 , V_557 , V_1583 , V_2054 ,
V_1052 ) ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2055 ) ;
if ( ! V_359 ) {
F_76 ( V_51 ) ;
return;
}
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_557 -> V_20 ) ||
F_54 ( V_51 , V_1592 , V_2054 ) ||
F_49 ( V_51 , V_565 , V_605 , V_1583 ) ||
( V_1052 > 0 &&
F_53 ( V_51 , V_1051 , V_1052 ) ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_1540 ) ;
return;
V_59:
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
static int F_540 ( struct V_2056 * V_2057 ,
unsigned long V_358 ,
void * V_2058 )
{
struct V_2059 * V_2060 = V_2058 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1762 * V_1763 , * V_24 ;
if ( V_358 != V_2061 || V_2060 -> V_2062 != V_2063 )
return V_2064 ;
F_243 () ;
F_541 (rdev, &cfg80211_rdev_list, list) {
bool V_2065 = false ;
struct V_1319 * V_1356 =
F_244 ( V_7 -> V_1356 ) ;
if ( V_1356 && V_2060 -> V_47 &&
V_1356 -> V_657 == V_2060 -> V_47 ) {
V_1356 -> V_657 = 0 ;
if ( V_7 -> V_327 -> V_1358 &&
V_7 -> V_18 . V_49 & V_337 )
F_542 ( & V_7 -> V_2066 ) ;
}
F_541 (wdev, &rdev->wiphy.wdev_list, list) {
F_543 ( V_17 , V_2060 -> V_47 ) ;
if ( V_17 -> V_657 == V_2060 -> V_47 )
V_2065 = true ;
else if ( V_17 -> V_1518 == V_2060 -> V_47 )
F_542 ( & V_17 -> V_2067 ) ;
}
F_294 ( & V_7 -> V_1766 ) ;
F_544 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1763 -> V_1767 == V_2060 -> V_47 ) {
F_545 ( & V_1763 -> V_663 ) ;
F_39 ( V_1763 ) ;
break;
}
}
F_296 ( & V_7 -> V_1766 ) ;
if ( V_2065 ) {
struct V_2068 * V_2069 ;
V_2069 = F_37 ( sizeof( * V_2069 ) , V_1943 ) ;
if ( V_2069 ) {
V_2069 -> V_1767 = V_2060 -> V_47 ;
F_546 ( & V_7 -> V_2070 ) ;
F_408 ( & V_2069 -> V_663 , & V_7 -> V_2071 ) ;
F_547 ( & V_7 -> V_2070 ) ;
F_542 ( & V_7 -> V_2072 ) ;
}
}
}
F_245 () ;
F_548 ( V_2060 -> V_47 ) ;
return V_2073 ;
}
void F_549 ( struct V_25 * V_19 ,
struct V_2074 * V_2075 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
F_550 ( V_18 , V_19 , V_2075 ) ;
if ( ! V_2075 -> V_2076 )
return;
V_51 = F_75 ( 100 + V_2075 -> V_2077 , V_134 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2078 ) ;
if ( ! V_359 )
goto V_618;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_19 -> V_20 ) ||
F_49 ( V_51 , V_565 , V_605 , V_2075 -> V_2076 ) )
goto V_618;
if ( V_2075 -> V_773 &&
F_49 ( V_51 , V_749 , V_2075 -> V_772 , V_2075 -> V_773 ) )
goto V_618;
if ( V_2075 -> V_2079 &&
F_49 ( V_51 , V_2080 , V_2075 -> V_2077 ,
V_2075 -> V_2079 ) )
goto V_618;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_51 , 0 ,
V_1945 , V_134 ) ;
return;
V_618:
F_76 ( V_51 ) ;
}
void F_551 ( struct V_1 * V_17 , T_10 V_1540 )
{
struct V_6 * V_7 ;
struct V_31 * V_51 ;
void * V_359 ;
V_22 V_1767 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1872 )
return;
V_1767 = V_7 -> V_1872 ;
V_7 -> V_1872 = 0 ;
V_51 = F_75 ( V_619 , V_1540 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2081 ) ;
if ( ! V_359 )
goto V_59;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_59;
F_65 ( V_51 , V_359 ) ;
F_430 ( F_7 ( & V_7 -> V_18 ) , V_51 , V_1767 ) ;
return;
V_59:
if ( V_359 )
F_66 ( V_51 , V_359 ) ;
F_76 ( V_51 ) ;
}
void F_552 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_51 ;
void * V_359 ;
V_51 = F_75 ( V_619 , V_134 ) ;
if ( ! V_51 )
return;
V_359 = F_23 ( V_51 , 0 , 0 , 0 , V_2082 ) ;
if ( ! V_359 )
goto V_618;
if ( F_26 ( V_51 , V_26 , V_7 -> V_14 ) ||
F_26 ( V_51 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_51 , V_12 , V_13 ( V_17 ) ,
V_604 ) )
goto V_618;
F_65 ( V_51 , V_359 ) ;
F_324 ( & V_38 , F_7 ( V_18 ) , V_51 , 0 ,
V_1945 , V_134 ) ;
return;
V_618:
F_76 ( V_51 ) ;
}
int T_11 F_553 ( void )
{
int V_35 ;
V_35 = F_554 ( & V_38 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_555 ( & V_2083 ) ;
if ( V_35 )
goto V_2084;
return 0 ;
V_2084:
F_556 ( & V_38 ) ;
return V_35 ;
}
void F_557 ( void )
{
F_558 ( & V_2083 ) ;
F_556 ( & V_38 ) ;
}
