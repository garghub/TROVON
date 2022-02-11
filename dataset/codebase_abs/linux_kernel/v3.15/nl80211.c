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
if ( F_28 ( V_53 ,
V_71 ,
V_55 -> V_72 ) )
goto V_59;
}
}
if ( V_56 ) {
if ( ( V_55 -> V_51 & V_73 ) &&
F_29 ( V_53 , V_74 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_75 ) &&
F_29 ( V_53 , V_76 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_77 ) &&
F_29 ( V_53 , V_78 ) )
goto V_59;
if ( ( V_55 -> V_51 & V_79 ) &&
F_29 ( V_53 , V_80 ) )
goto V_59;
}
if ( F_28 ( V_53 , V_81 ,
F_31 ( V_55 -> V_82 ) ) )
goto V_59;
return 0 ;
V_59:
return - V_83 ;
}
static int F_32 ( struct V_4 * V_84 , struct V_85 * V_86 )
{
struct V_4 * V_87 [ V_88 + 1 ] ;
int V_35 = F_33 ( V_87 , V_88 , V_84 ,
V_89 ) ;
if ( V_35 )
return V_35 ;
V_86 -> V_90 = ! ! V_87 [ V_91 ] ;
V_86 -> V_92 = ! ! V_87 [ V_93 ] ;
if ( V_86 -> V_90 ) {
V_86 -> V_94 = true ;
V_86 -> V_95 = true ;
}
if ( V_86 -> V_92 )
V_86 -> V_95 = true ;
if ( V_87 [ V_96 ] )
V_86 -> V_97 = F_34 ( V_87 [ V_96 ] ) ;
if ( V_87 [ V_98 ] ) {
V_86 -> V_99 . V_84 = F_23 ( V_87 [ V_98 ] ) ;
V_86 -> V_99 . V_100 = F_24 ( V_87 [ V_98 ] ) ;
}
if ( V_87 [ V_101 ] ) {
V_86 -> V_99 . V_50 = F_23 ( V_87 [ V_101 ] ) ;
V_86 -> V_99 . V_102 = F_24 ( V_87 [ V_101 ] ) ;
}
if ( V_87 [ V_103 ] )
V_86 -> V_99 . V_104 = F_4 ( V_87 [ V_103 ] ) ;
if ( V_87 [ V_105 ] ) {
V_86 -> type = F_4 ( V_87 [ V_105 ] ) ;
if ( V_86 -> type < 0 || V_86 -> type >= V_106 )
return - V_16 ;
}
if ( V_87 [ V_107 ] ) {
struct V_4 * V_108 [ V_109 ] ;
V_35 = F_33 ( V_108 , V_109 - 1 ,
V_87 [ V_107 ] ,
V_110 ) ;
if ( V_35 )
return V_35 ;
V_86 -> V_94 = V_108 [ V_111 ] ;
V_86 -> V_95 = V_108 [ V_112 ] ;
}
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , struct V_85 * V_86 )
{
if ( V_30 -> V_5 [ V_113 ] ) {
V_86 -> V_99 . V_84 = F_23 ( V_30 -> V_5 [ V_113 ] ) ;
V_86 -> V_99 . V_100 = F_24 ( V_30 -> V_5 [ V_113 ] ) ;
}
if ( V_30 -> V_5 [ V_114 ] ) {
V_86 -> V_99 . V_50 = F_23 ( V_30 -> V_5 [ V_114 ] ) ;
V_86 -> V_99 . V_102 = F_24 ( V_30 -> V_5 [ V_114 ] ) ;
}
if ( V_30 -> V_5 [ V_115 ] )
V_86 -> V_97 = F_34 ( V_30 -> V_5 [ V_115 ] ) ;
if ( V_30 -> V_5 [ V_116 ] )
V_86 -> V_99 . V_104 = F_4 ( V_30 -> V_5 [ V_116 ] ) ;
V_86 -> V_90 = ! ! V_30 -> V_5 [ V_117 ] ;
V_86 -> V_92 = ! ! V_30 -> V_5 [ V_118 ] ;
if ( V_86 -> V_90 ) {
V_86 -> V_94 = true ;
V_86 -> V_95 = true ;
}
if ( V_86 -> V_92 )
V_86 -> V_95 = true ;
if ( V_30 -> V_5 [ V_119 ] ) {
V_86 -> type = F_4 ( V_30 -> V_5 [ V_119 ] ) ;
if ( V_86 -> type < 0 || V_86 -> type >= V_106 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_120 ] ) {
struct V_4 * V_108 [ V_109 ] ;
int V_35 = F_33 (
V_108 , V_109 - 1 ,
V_30 -> V_5 [ V_120 ] ,
V_110 ) ;
if ( V_35 )
return V_35 ;
V_86 -> V_94 = V_108 [ V_111 ] ;
V_86 -> V_95 = V_108 [ V_112 ] ;
}
return 0 ;
}
static int F_36 ( struct V_29 * V_30 , struct V_85 * V_86 )
{
int V_35 ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
V_86 -> V_97 = - 1 ;
V_86 -> type = - 1 ;
if ( V_30 -> V_5 [ V_121 ] )
V_35 = F_32 ( V_30 -> V_5 [ V_121 ] , V_86 ) ;
else
V_35 = F_35 ( V_30 , V_86 ) ;
if ( V_35 )
return V_35 ;
if ( V_86 -> V_90 && V_86 -> V_92 )
return - V_16 ;
if ( V_86 -> V_92 ) {
if ( V_86 -> V_94 || ! V_86 -> V_95 )
return - V_16 ;
}
if ( V_86 -> V_97 != - 1 ) {
if ( V_86 -> V_92 ) {
if ( V_86 -> V_97 < 4 || V_86 -> V_97 > 5 )
return - V_16 ;
} else if ( V_86 -> V_90 ) {
if ( V_86 -> V_97 < 0 || V_86 -> V_97 > 3 )
return - V_16 ;
} else {
if ( V_86 -> V_97 < 0 || V_86 -> V_97 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_122 *
F_37 ( struct V_6 * V_7 ,
struct V_4 * V_123 , bool * V_124 )
{
struct V_85 V_125 ;
struct V_4 * V_84 ;
struct V_122 * V_8 ;
int V_126 , V_35 , V_90 = 0 ;
V_8 = F_38 ( sizeof( * V_8 ) , V_127 ) ;
if ( ! V_8 )
return F_3 ( - V_128 ) ;
V_8 -> V_90 = - 1 ;
V_8 -> V_92 = - 1 ;
F_39 (key, keys, rem) {
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_97 = - 1 ;
V_35 = F_32 ( V_84 , & V_125 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_125 . V_99 . V_84 )
goto error;
if ( V_125 . V_97 < 0 || V_125 . V_97 > 4 )
goto error;
if ( V_125 . V_90 ) {
if ( V_90 )
goto error;
V_90 = 1 ;
V_8 -> V_90 = V_125 . V_97 ;
if ( ! V_125 . V_94 || ! V_125 . V_95 )
goto error;
} else if ( V_125 . V_92 )
goto error;
V_35 = F_40 ( V_7 , & V_125 . V_99 ,
V_125 . V_97 , false , NULL ) ;
if ( V_35 )
goto error;
V_8 -> V_129 [ V_125 . V_97 ] . V_104 = V_125 . V_99 . V_104 ;
V_8 -> V_129 [ V_125 . V_97 ] . V_100 = V_125 . V_99 . V_100 ;
V_8 -> V_129 [ V_125 . V_97 ] . V_84 = V_8 -> V_130 [ V_125 . V_97 ] ;
memcpy ( V_8 -> V_130 [ V_125 . V_97 ] , V_125 . V_99 . V_84 , V_125 . V_99 . V_100 ) ;
if ( V_125 . V_99 . V_104 == V_131 ||
V_125 . V_99 . V_104 == V_132 ) {
if ( V_124 )
* V_124 = true ;
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
switch ( V_17 -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
case V_137 :
break;
case V_138 :
case V_139 :
case V_140 :
if ( ! V_17 -> V_141 )
return - V_142 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static struct V_54 * F_44 ( struct V_18 * V_18 ,
struct V_4 * V_87 )
{
struct V_54 * V_55 ;
if ( V_87 == NULL )
return NULL ;
V_55 = F_45 ( V_18 , F_4 ( V_87 ) ) ;
if ( ! V_55 || V_55 -> V_51 & V_60 )
return NULL ;
return V_55 ;
}
static int F_46 ( struct V_31 * V_53 , V_22 V_45 , T_3 V_143 )
{
struct V_4 * V_144 = F_47 ( V_53 , V_45 ) ;
int V_145 ;
if ( ! V_144 )
goto V_59;
V_145 = 0 ;
while ( V_143 ) {
if ( ( V_143 & 1 ) && F_29 ( V_53 , V_145 ) )
goto V_59;
V_143 >>= 1 ;
V_145 ++ ;
}
F_48 ( V_53 , V_144 ) ;
return 0 ;
V_59:
return - V_83 ;
}
static int F_49 ( struct V_18 * V_18 ,
struct V_31 * V_53 ,
bool V_56 )
{
struct V_4 * V_146 ;
int V_145 , V_147 ;
V_146 = F_47 ( V_53 ,
V_148 ) ;
if ( ! V_146 )
goto V_59;
for ( V_145 = 0 ; V_145 < V_18 -> V_149 ; V_145 ++ ) {
const struct V_150 * V_151 ;
struct V_4 * V_152 , * V_153 ;
V_151 = & V_18 -> V_154 [ V_145 ] ;
V_152 = F_47 ( V_53 , V_145 + 1 ) ;
if ( ! V_152 )
goto V_59;
V_153 = F_47 ( V_53 , V_155 ) ;
if ( ! V_153 )
goto V_59;
for ( V_147 = 0 ; V_147 < V_151 -> V_156 ; V_147 ++ ) {
struct V_4 * V_157 ;
V_157 = F_47 ( V_53 , V_147 + 1 ) ;
if ( ! V_157 )
goto V_59;
if ( F_28 ( V_53 , V_158 ,
V_151 -> V_159 [ V_147 ] . V_160 ) )
goto V_59;
if ( F_46 ( V_53 , V_161 ,
V_151 -> V_159 [ V_147 ] . V_162 ) )
goto V_59;
F_48 ( V_53 , V_157 ) ;
}
F_48 ( V_53 , V_153 ) ;
if ( V_151 -> V_163 &&
F_29 ( V_53 , V_164 ) )
goto V_59;
if ( F_28 ( V_53 , V_165 ,
V_151 -> V_166 ) ||
F_28 ( V_53 , V_167 ,
V_151 -> V_168 ) )
goto V_59;
if ( V_56 &&
F_28 ( V_53 , V_169 ,
V_151 -> V_170 ) )
goto V_59;
F_48 ( V_53 , V_152 ) ;
}
F_48 ( V_53 , V_146 ) ;
return 0 ;
V_59:
return - V_83 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
const struct V_171 * V_172 = V_7 -> V_18 . V_173 -> V_172 ;
struct V_4 * V_174 ;
if ( ! V_172 )
return 0 ;
V_174 = F_47 ( V_53 , V_175 ) ;
if ( ! V_174 )
return - V_83 ;
if ( F_28 ( V_53 , V_176 ,
V_172 -> V_177 ) )
return - V_83 ;
if ( F_28 ( V_53 , V_176 ,
V_172 -> V_177 ) )
return - V_83 ;
if ( V_172 -> V_50 && F_29 ( V_53 , V_178 ) )
return - V_83 ;
if ( V_172 -> V_179 && F_51 ( V_53 , V_180 ,
sizeof( * V_172 -> V_179 ) , V_172 -> V_179 ) )
return - V_83 ;
if ( F_28 ( V_53 , V_181 ,
V_172 -> V_182 ) )
return - V_83 ;
if ( F_28 ( V_53 , V_183 ,
V_172 -> V_184 ) )
return - V_83 ;
F_48 ( V_53 , V_174 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_53 ,
struct V_6 * V_185 ,
bool V_56 )
{
struct V_4 * V_186 ;
if ( ! V_185 -> V_18 . V_173 )
return 0 ;
V_186 = F_47 ( V_53 , V_187 ) ;
if ( ! V_186 )
return - V_83 ;
if ( ( ( V_185 -> V_18 . V_173 -> V_51 & V_188 ) &&
F_29 ( V_53 , V_189 ) ) ||
( ( V_185 -> V_18 . V_173 -> V_51 & V_190 ) &&
F_29 ( V_53 , V_191 ) ) ||
( ( V_185 -> V_18 . V_173 -> V_51 & V_192 ) &&
F_29 ( V_53 , V_193 ) ) ||
( ( V_185 -> V_18 . V_173 -> V_51 & V_194 ) &&
F_29 ( V_53 , V_195 ) ) ||
( ( V_185 -> V_18 . V_173 -> V_51 & V_196 ) &&
F_29 ( V_53 , V_197 ) ) ||
( ( V_185 -> V_18 . V_173 -> V_51 & V_198 ) &&
F_29 ( V_53 , V_199 ) ) ||
( ( V_185 -> V_18 . V_173 -> V_51 & V_200 ) &&
F_29 ( V_53 , V_201 ) ) ||
( ( V_185 -> V_18 . V_173 -> V_51 & V_202 ) &&
F_29 ( V_53 , V_203 ) ) )
return - V_83 ;
if ( V_185 -> V_18 . V_173 -> V_204 ) {
struct V_205 V_206 = {
. V_207 = V_185 -> V_18 . V_173 -> V_204 ,
. V_208 = V_185 -> V_18 . V_173 -> V_209 ,
. V_210 = V_185 -> V_18 . V_173 -> V_211 ,
. V_212 = V_185 -> V_18 . V_173 -> V_212 ,
} ;
if ( F_51 ( V_53 , V_213 ,
sizeof( V_206 ) , & V_206 ) )
return - V_83 ;
}
if ( V_56 && F_50 ( V_185 , V_53 ) )
return - V_83 ;
F_48 ( V_53 , V_186 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_53 ,
struct V_6 * V_185 )
{
struct V_214 V_215 ;
if ( ! V_185 -> V_18 . V_216 )
return 0 ;
V_215 . V_217 = V_185 -> V_18 . V_216 -> V_218 ;
V_215 . V_219 = V_185 -> V_18 . V_216 -> V_219 ;
V_215 . V_206 . V_207 = V_185 -> V_18 . V_216 -> V_204 ;
V_215 . V_206 . V_208 = V_185 -> V_18 . V_216 -> V_209 ;
V_215 . V_206 . V_210 = V_185 -> V_18 . V_216 -> V_211 ;
V_215 . V_206 . V_212 = V_185 -> V_18 . V_216 -> V_212 ;
if ( F_51 ( V_53 , V_220 , sizeof( V_215 ) , & V_215 ) )
return - V_83 ;
return 0 ;
}
static int F_54 ( struct V_31 * V_53 ,
struct V_221 * V_222 )
{
struct V_4 * V_223 , * V_224 ;
struct V_225 * V_226 ;
int V_145 ;
if ( V_222 -> V_227 . V_228 &&
( F_51 ( V_53 , V_229 ,
sizeof( V_222 -> V_227 . V_230 ) ,
& V_222 -> V_227 . V_230 ) ||
F_55 ( V_53 , V_231 ,
V_222 -> V_227 . V_232 ) ||
F_56 ( V_53 , V_233 ,
V_222 -> V_227 . V_234 ) ||
F_56 ( V_53 , V_235 ,
V_222 -> V_227 . V_236 ) ) )
return - V_83 ;
if ( V_222 -> V_237 . V_238 &&
( F_51 ( V_53 , V_239 ,
sizeof( V_222 -> V_237 . V_240 ) ,
& V_222 -> V_237 . V_240 ) ||
F_28 ( V_53 , V_241 ,
V_222 -> V_237 . V_232 ) ) )
return - V_83 ;
V_223 = F_47 ( V_53 , V_242 ) ;
if ( ! V_223 )
return - V_83 ;
for ( V_145 = 0 ; V_145 < V_222 -> V_243 ; V_145 ++ ) {
V_224 = F_47 ( V_53 , V_145 ) ;
if ( ! V_224 )
return - V_83 ;
V_226 = & V_222 -> V_244 [ V_145 ] ;
if ( F_28 ( V_53 , V_245 ,
V_226 -> V_246 ) )
return - V_83 ;
if ( ( V_226 -> V_51 & V_247 ) &&
F_29 ( V_53 ,
V_248 ) )
return - V_83 ;
F_48 ( V_53 , V_224 ) ;
}
F_48 ( V_53 , V_223 ) ;
return 0 ;
}
static int
F_57 ( struct V_31 * V_53 ,
const struct V_249 * V_250 )
{
T_3 V_251 ;
struct V_4 * V_252 , * V_253 ;
enum V_254 V_255 ;
int V_145 ;
if ( ! V_250 )
return 0 ;
V_253 = F_47 ( V_53 , V_256 ) ;
if ( ! V_253 )
return - V_83 ;
for ( V_255 = 0 ; V_255 < V_257 ; V_255 ++ ) {
V_252 = F_47 ( V_53 , V_255 ) ;
if ( ! V_252 )
return - V_83 ;
V_145 = 0 ;
V_251 = V_250 [ V_255 ] . V_258 ;
while ( V_251 ) {
if ( ( V_251 & 1 ) &&
F_55 ( V_53 , V_259 ,
( V_145 << 4 ) | V_260 ) )
return - V_83 ;
V_251 >>= 1 ;
V_145 ++ ;
}
F_48 ( V_53 , V_252 ) ;
}
F_48 ( V_53 , V_253 ) ;
V_253 = F_47 ( V_53 , V_261 ) ;
if ( ! V_253 )
return - V_83 ;
for ( V_255 = 0 ; V_255 < V_257 ; V_255 ++ ) {
V_252 = F_47 ( V_53 , V_255 ) ;
if ( ! V_252 )
return - V_83 ;
V_145 = 0 ;
V_251 = V_250 [ V_255 ] . V_262 ;
while ( V_251 ) {
if ( ( V_251 & 1 ) &&
F_55 ( V_53 , V_259 ,
( V_145 << 4 ) | V_260 ) )
return - V_83 ;
V_251 >>= 1 ;
V_145 ++ ;
}
F_48 ( V_53 , V_252 ) ;
}
F_48 ( V_53 , V_253 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_185 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_263 * V_264 )
{
void * V_265 ;
struct V_4 * V_266 , * V_267 ;
struct V_4 * V_268 , * V_269 ;
struct V_4 * V_270 ;
enum V_271 V_272 ;
struct V_54 * V_55 ;
int V_145 ;
const struct V_249 * V_250 =
V_185 -> V_18 . V_250 ;
V_22 V_273 ;
V_265 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_274 ) ;
if ( ! V_265 )
return - V_83 ;
if ( F_59 ( ! V_264 ) )
return - V_16 ;
if ( F_28 ( V_53 , V_26 , V_185 -> V_14 ) ||
F_60 ( V_53 , V_275 ,
F_61 ( & V_185 -> V_18 ) ) ||
F_28 ( V_53 , V_276 ,
V_277 ) )
goto V_59;
switch ( V_264 -> V_278 ) {
case 0 :
if ( F_56 ( V_53 , V_279 ,
V_185 -> V_18 . V_280 ) ||
F_56 ( V_53 , V_281 ,
V_185 -> V_18 . V_282 ) ||
F_28 ( V_53 , V_283 ,
V_185 -> V_18 . V_284 ) ||
F_28 ( V_53 , V_285 ,
V_185 -> V_18 . V_286 ) ||
F_56 ( V_53 , V_287 ,
V_185 -> V_18 . V_288 ) ||
F_56 ( V_53 , V_289 ,
V_185 -> V_18 . V_290 ) ||
F_56 ( V_53 , V_291 ,
V_185 -> V_18 . V_292 ) ||
F_55 ( V_53 , V_293 ,
V_185 -> V_18 . V_294 ) ||
F_55 ( V_53 , V_295 ,
V_185 -> V_18 . V_296 ) ||
F_56 ( V_53 , V_297 ,
V_185 -> V_18 . V_298 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_299 ) &&
F_29 ( V_53 , V_300 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_301 ) &&
F_29 ( V_53 , V_302 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_303 ) &&
F_29 ( V_53 , V_304 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_305 ) &&
F_29 ( V_53 , V_306 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_307 ) &&
F_29 ( V_53 , V_308 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_309 ) &&
F_29 ( V_53 , V_310 ) )
goto V_59;
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
case 1 :
if ( F_51 ( V_53 , V_312 ,
sizeof( V_22 ) * V_185 -> V_18 . V_313 ,
V_185 -> V_18 . V_314 ) )
goto V_59;
if ( F_56 ( V_53 , V_315 ,
V_185 -> V_18 . V_316 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_317 ) &&
F_29 ( V_53 , V_318 ) )
goto V_59;
if ( F_28 ( V_53 , V_319 ,
V_185 -> V_18 . V_320 ) ||
F_28 ( V_53 , V_321 ,
V_185 -> V_18 . V_322 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_323 ) &&
F_28 ( V_53 , V_324 ,
V_185 -> V_18 . V_325 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_320 ||
V_185 -> V_18 . V_322 ) &&
V_185 -> V_326 -> V_327 ) {
V_22 V_328 = 0 , V_329 = 0 ;
int V_330 ;
V_330 = F_62 ( V_185 , & V_328 , & V_329 ) ;
if ( ! V_330 ) {
if ( F_28 ( V_53 ,
V_331 ,
V_328 ) ||
F_28 ( V_53 ,
V_332 ,
V_329 ) )
goto V_59;
}
}
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
case 2 :
if ( F_46 ( V_53 , V_333 ,
V_185 -> V_18 . V_334 ) )
goto V_59;
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
case 3 :
V_266 = F_47 ( V_53 , V_335 ) ;
if ( ! V_266 )
goto V_59;
for ( V_272 = V_264 -> V_336 ;
V_272 < V_337 ; V_272 ++ ) {
struct V_221 * V_222 ;
V_222 = V_185 -> V_18 . V_338 [ V_272 ] ;
if ( ! V_222 )
continue;
V_267 = F_47 ( V_53 , V_272 ) ;
if ( ! V_267 )
goto V_59;
switch ( V_264 -> V_339 ) {
case 0 :
if ( F_54 ( V_53 , V_222 ) )
goto V_59;
V_264 -> V_339 ++ ;
if ( V_264 -> V_311 )
break;
default:
V_268 = F_47 (
V_53 , V_340 ) ;
if ( ! V_268 )
goto V_59;
for ( V_145 = V_264 -> V_339 - 1 ;
V_145 < V_222 -> V_341 ;
V_145 ++ ) {
V_269 = F_47 ( V_53 , V_145 ) ;
if ( ! V_269 )
goto V_59;
V_55 = & V_222 -> V_342 [ V_145 ] ;
if ( F_27 (
V_53 , V_55 ,
V_264 -> V_311 ) )
goto V_59;
F_48 ( V_53 , V_269 ) ;
if ( V_264 -> V_311 )
break;
}
if ( V_145 < V_222 -> V_341 )
V_264 -> V_339 = V_145 + 2 ;
else
V_264 -> V_339 = 0 ;
F_48 ( V_53 , V_268 ) ;
}
F_48 ( V_53 , V_267 ) ;
if ( V_264 -> V_311 ) {
if ( V_264 -> V_339 )
V_272 -- ;
break;
}
}
F_48 ( V_53 , V_266 ) ;
if ( V_272 < V_337 )
V_264 -> V_336 = V_272 + 1 ;
else
V_264 -> V_336 = 0 ;
if ( V_264 -> V_336 == 0 && V_264 -> V_339 == 0 )
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
case 4 :
V_270 = F_47 ( V_53 , V_343 ) ;
if ( ! V_270 )
goto V_59;
V_145 = 0 ;
#define F_63 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_63 ( V_344 , V_345 ) ;
F_63 ( V_346 , V_347 ) ;
F_63 ( V_348 , V_349 ) ;
F_63 ( V_350 , V_351 ) ;
F_63 ( V_352 , V_353 ) ;
F_63 ( V_354 , V_355 ) ;
F_63 ( V_356 , V_357 ) ;
F_63 ( V_358 , V_359 ) ;
F_63 ( V_360 , V_361 ) ;
F_63 ( V_362 , V_363 ) ;
F_63 ( V_364 , V_365 ) ;
F_63 ( V_366 , V_367 ) ;
F_63 ( V_368 , V_369 ) ;
F_63 ( V_370 , V_371 ) ;
F_63 ( V_372 , V_373 ) ;
F_63 ( V_374 , V_375 ) ;
F_63 ( V_376 , V_377 ) ;
if ( V_185 -> V_18 . V_51 & V_378 )
F_63 ( V_379 , V_380 ) ;
F_63 ( V_381 , V_382 ) ;
F_63 ( V_383 , V_384 ) ;
F_63 ( V_385 , V_386 ) ;
if ( V_185 -> V_18 . V_51 & V_387 ) {
V_145 ++ ;
if ( F_28 ( V_53 , V_145 , V_388 ) )
goto V_59;
}
if ( V_185 -> V_326 -> V_389 || V_185 -> V_326 -> V_350 ||
V_185 -> V_326 -> V_370 ) {
V_145 ++ ;
if ( F_28 ( V_53 , V_145 , V_390 ) )
goto V_59;
}
F_63 ( V_391 , V_392 ) ;
if ( V_185 -> V_18 . V_51 & V_307 ) {
F_63 ( V_393 , V_394 ) ;
F_63 ( V_395 , V_396 ) ;
}
if ( V_185 -> V_18 . V_51 & V_397 )
F_63 ( V_398 , V_399 ) ;
F_63 ( V_400 , V_401 ) ;
F_63 ( V_402 , V_403 ) ;
if ( V_185 -> V_18 . V_51 & V_404 ) {
V_145 ++ ;
if ( F_28 ( V_53 , V_145 , V_405 ) )
goto V_59;
}
F_63 ( V_406 , V_407 ) ;
F_63 ( V_408 , V_409 ) ;
if ( V_264 -> V_311 ) {
F_63 ( V_410 , V_411 ) ;
F_63 ( V_412 , V_413 ) ;
if ( V_185 -> V_18 . V_51 & V_414 )
F_63 ( V_415 , V_416 ) ;
}
F_63 ( V_417 , V_418 ) ;
#ifdef F_64
F_63 ( V_419 , V_420 ) ;
#endif
#undef F_63
if ( V_185 -> V_326 -> V_421 || V_185 -> V_326 -> V_360 ) {
V_145 ++ ;
if ( F_28 ( V_53 , V_145 , V_422 ) )
goto V_59;
}
if ( V_185 -> V_326 -> V_423 || V_185 -> V_326 -> V_364 ) {
V_145 ++ ;
if ( F_28 ( V_53 , V_145 , V_424 ) )
goto V_59;
}
F_48 ( V_53 , V_270 ) ;
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
case 5 :
if ( V_185 -> V_326 -> V_379 &&
( V_185 -> V_18 . V_51 & V_378 ) &&
F_28 ( V_53 ,
V_425 ,
V_185 -> V_18 . V_426 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_427 ) &&
F_29 ( V_53 , V_428 ) )
goto V_59;
if ( F_57 ( V_53 , V_250 ) )
goto V_59;
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
case 6 :
#ifdef F_65
if ( F_52 ( V_53 , V_185 , V_264 -> V_311 ) )
goto V_59;
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
#else
V_264 -> V_278 ++ ;
#endif
case 7 :
if ( F_46 ( V_53 , V_429 ,
V_185 -> V_18 . V_430 ) )
goto V_59;
if ( F_49 ( & V_185 -> V_18 , V_53 ,
V_264 -> V_311 ) )
goto V_59;
V_264 -> V_278 ++ ;
if ( V_264 -> V_311 )
break;
case 8 :
if ( ( V_185 -> V_18 . V_51 & V_431 ) &&
F_28 ( V_53 , V_432 ,
V_185 -> V_18 . V_433 ) )
goto V_59;
V_273 = V_185 -> V_18 . V_273 ;
if ( V_264 -> V_311 )
V_273 |= V_434 ;
if ( F_28 ( V_53 , V_435 , V_273 ) )
goto V_59;
if ( V_185 -> V_18 . V_436 &&
F_51 ( V_53 , V_437 ,
sizeof( * V_185 -> V_18 . V_436 ) ,
V_185 -> V_18 . V_436 ) )
goto V_59;
if ( V_185 -> V_18 . V_51 & V_431 &&
V_185 -> V_18 . V_438 &&
F_28 ( V_53 , V_439 ,
V_185 -> V_18 . V_438 ) )
goto V_59;
V_264 -> V_278 ++ ;
break;
case 9 :
if ( V_185 -> V_18 . V_440 &&
( F_51 ( V_53 , V_441 ,
V_185 -> V_18 . V_442 ,
V_185 -> V_18 . V_440 ) ||
F_51 ( V_53 , V_443 ,
V_185 -> V_18 . V_442 ,
V_185 -> V_18 . V_444 ) ) )
goto V_59;
if ( V_185 -> V_18 . V_445 &&
F_51 ( V_53 , V_446 ,
sizeof( * V_185 -> V_18 . V_445 ) ,
V_185 -> V_18 . V_445 ) )
goto V_59;
V_264 -> V_278 ++ ;
break;
case 10 :
if ( F_53 ( V_53 , V_185 ) )
goto V_59;
if ( ( V_185 -> V_18 . V_51 & V_447 ) &&
( F_29 ( V_53 , V_448 ) ||
F_29 ( V_53 , V_449 ) ) )
goto V_59;
if ( V_185 -> V_18 . V_450 &&
F_28 ( V_53 , V_451 ,
V_185 -> V_18 . V_450 ) )
goto V_59;
V_264 -> V_278 ++ ;
break;
case 11 :
if ( V_185 -> V_18 . V_452 ) {
const struct V_453 * V_30 ;
struct V_4 * V_454 ;
V_454 = F_47 ( V_53 , V_455 ) ;
if ( ! V_454 )
goto V_59;
for ( V_145 = 0 ; V_145 < V_185 -> V_18 . V_452 ; V_145 ++ ) {
V_30 = & V_185 -> V_18 . V_456 [ V_145 ] . V_30 ;
if ( F_51 ( V_53 , V_145 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_48 ( V_53 , V_454 ) ;
}
if ( V_185 -> V_18 . V_457 ) {
const struct V_453 * V_30 ;
struct V_4 * V_454 ;
V_454 = F_47 ( V_53 ,
V_458 ) ;
if ( ! V_454 )
goto V_59;
for ( V_145 = 0 ; V_145 < V_185 -> V_18 . V_457 ; V_145 ++ ) {
V_30 = & V_185 -> V_18 . V_459 [ V_145 ] ;
if ( F_51 ( V_53 , V_145 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_59;
}
F_48 ( V_53 , V_454 ) ;
}
V_264 -> V_278 = 0 ;
break;
}
return F_66 ( V_53 , V_265 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_263 * V_264 )
{
struct V_4 * * V_87 = V_38 . V_40 ;
int V_461 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_87 , V_38 . V_41 , V_42 ) ;
if ( V_461 )
return 0 ;
V_264 -> V_311 = V_87 [ V_462 ] ;
if ( V_87 [ V_26 ] )
V_264 -> V_463 = F_4 ( V_87 [ V_26 ] ) ;
if ( V_87 [ V_12 ] )
V_264 -> V_463 = F_5 ( V_87 [ V_12 ] ) >> 32 ;
if ( V_87 [ V_10 ] ) {
struct V_25 * V_19 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_87 [ V_10 ] ) ;
V_19 = F_10 ( F_16 ( V_32 -> V_44 ) , V_15 ) ;
if ( ! V_19 )
return - V_23 ;
if ( V_19 -> V_28 ) {
V_7 = F_11 (
V_19 -> V_28 -> V_18 ) ;
V_264 -> V_463 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_97 = 0 , V_461 ;
struct V_263 * V_264 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_185 ;
F_14 () ;
if ( ! V_264 ) {
V_264 = F_38 ( sizeof( * V_264 ) , V_127 ) ;
if ( ! V_264 ) {
F_20 () ;
return - V_128 ;
}
V_264 -> V_463 = - 1 ;
V_461 = F_68 ( V_32 , V_34 , V_264 ) ;
if ( V_461 ) {
F_41 ( V_264 ) ;
F_20 () ;
return V_461 ;
}
V_34 -> args [ 0 ] = ( long ) V_264 ;
}
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_185 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_97 <= V_264 -> V_464 )
continue;
if ( V_264 -> V_463 != - 1 &&
V_264 -> V_463 != V_185 -> V_14 )
continue;
do {
V_461 = F_58 ( V_185 , V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_465 ,
V_466 , V_264 ) ;
if ( V_461 < 0 ) {
if ( ( V_461 == - V_83 || V_461 == - V_460 ) &&
! V_32 -> V_47 && ! V_264 -> V_311 &&
V_34 -> V_467 < 4096 ) {
V_34 -> V_467 = 4096 ;
V_264 -> V_278 = 0 ;
F_20 () ;
return 1 ;
}
V_97 -- ;
break;
}
} while ( V_264 -> V_278 > 0 );
break;
}
F_20 () ;
V_264 -> V_464 = V_97 ;
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
struct V_6 * V_185 = V_30 -> V_468 [ 0 ] ;
struct V_263 V_264 = {} ;
V_53 = F_74 ( 4096 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
if ( F_58 ( V_185 , V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
& V_264 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_83 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_87 [] ,
struct V_471 * V_472 )
{
if ( ! V_87 [ V_473 ] || ! V_87 [ V_474 ] ||
! V_87 [ V_475 ] || ! V_87 [ V_476 ] ||
! V_87 [ V_477 ] )
return - V_16 ;
V_472 -> V_478 = F_34 ( V_87 [ V_473 ] ) ;
V_472 -> V_479 = F_78 ( V_87 [ V_474 ] ) ;
V_472 -> V_480 = F_78 ( V_87 [ V_475 ] ) ;
V_472 -> V_481 = F_78 ( V_87 [ V_476 ] ) ;
V_472 -> V_482 = F_34 ( V_87 [ V_477 ] ) ;
if ( V_472 -> V_478 >= V_483 )
return - V_16 ;
return 0 ;
}
static bool F_79 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_133 == V_134 ||
V_17 -> V_133 == V_137 ||
V_17 -> V_133 == V_484 ||
V_17 -> V_133 == V_136 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_485 * V_486 )
{
V_22 V_487 ;
if ( ! V_30 -> V_5 [ V_488 ] )
return - V_16 ;
V_487 = F_4 ( V_30 -> V_5 [ V_488 ] ) ;
V_486 -> V_55 = F_45 ( & V_7 -> V_18 , V_487 ) ;
V_486 -> V_489 = V_490 ;
V_486 -> V_491 = V_487 ;
V_486 -> V_492 = 0 ;
if ( ! V_486 -> V_55 || V_486 -> V_55 -> V_51 & V_60 )
return - V_16 ;
if ( V_30 -> V_5 [ V_493 ] ) {
enum V_494 V_495 ;
V_495 = F_4 (
V_30 -> V_5 [ V_493 ] ) ;
switch ( V_495 ) {
case V_496 :
case V_497 :
case V_498 :
case V_499 :
F_81 ( V_486 , V_486 -> V_55 ,
V_495 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_500 ] ) {
V_486 -> V_489 =
F_4 ( V_30 -> V_5 [ V_500 ] ) ;
if ( V_30 -> V_5 [ V_501 ] )
V_486 -> V_491 =
F_4 (
V_30 -> V_5 [ V_501 ] ) ;
if ( V_30 -> V_5 [ V_502 ] )
V_486 -> V_492 =
F_4 (
V_30 -> V_5 [ V_502 ] ) ;
}
if ( ! F_82 ( V_486 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_486 ,
V_60 ) )
return - V_16 ;
if ( ( V_486 -> V_489 == V_503 ||
V_486 -> V_489 == V_504 ) &&
! ( V_7 -> V_18 . V_51 & V_447 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_29 * V_30 )
{
struct V_485 V_486 ;
int V_8 ;
enum V_254 V_133 = V_484 ;
if ( V_17 )
V_133 = V_17 -> V_133 ;
if ( ! F_79 ( V_17 ) )
return - V_505 ;
V_8 = F_80 ( V_7 , V_30 , & V_486 ) ;
if ( V_8 )
return V_8 ;
switch ( V_133 ) {
case V_134 :
case V_136 :
if ( V_17 -> V_506 ) {
V_8 = - V_507 ;
break;
}
if ( ! F_85 ( & V_7 -> V_18 , & V_486 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_508 = V_486 ;
V_8 = 0 ;
break;
case V_137 :
V_8 = F_86 ( V_7 , V_17 , & V_486 ) ;
break;
case V_484 :
V_8 = F_87 ( V_7 , & V_486 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_88 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_468 [ 1 ] ;
return F_84 ( V_7 , V_19 -> V_28 , V_30 ) ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
const T_2 * V_509 ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( F_90 ( V_185 ) )
return - V_507 ;
if ( ! V_7 -> V_326 -> V_391 )
return - V_505 ;
if ( V_17 -> V_133 != V_511 )
return - V_505 ;
V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
return F_91 ( V_7 , V_185 , V_509 ) ;
}
static int F_92 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_512 = 0 ;
struct V_4 * V_513 ;
V_22 V_514 ;
T_2 V_280 = 0 , V_282 = 0 ;
V_22 V_284 = 0 , V_286 = 0 ;
T_2 V_288 = 0 ;
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
if ( F_17 ( V_7 ) )
return F_18 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_275 ] )
V_8 = F_94 (
V_7 , F_23 ( V_30 -> V_5 [ V_275 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_515 ] ) {
struct V_471 V_472 ;
struct V_4 * V_87 [ V_516 + 1 ] ;
if ( ! V_7 -> V_326 -> V_517 )
return - V_505 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_133 != V_134 &&
V_19 -> V_28 -> V_133 != V_136 )
return - V_16 ;
if ( ! F_90 ( V_19 ) )
return - V_518 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_95 ( V_87 , V_516 ,
F_23 ( V_513 ) ,
F_24 ( V_513 ) ,
V_519 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_87 , & V_472 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_96 ( V_7 , V_19 ,
& V_472 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_488 ] ) {
V_8 = F_84 ( V_7 ,
F_79 ( V_17 ) ? V_17 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_520 ] ) {
struct V_1 * V_521 = V_17 ;
enum V_522 type ;
int V_97 , V_523 = 0 ;
if ( ! ( V_7 -> V_18 . V_273 & V_524 ) )
V_521 = NULL ;
if ( ! V_7 -> V_326 -> V_525 )
return - V_505 ;
V_97 = V_520 ;
type = F_4 ( V_30 -> V_5 [ V_97 ] ) ;
if ( ! V_30 -> V_5 [ V_526 ] &&
( type != V_527 ) )
return - V_16 ;
if ( type != V_527 ) {
V_97 = V_526 ;
V_523 = F_4 ( V_30 -> V_5 [ V_97 ] ) ;
}
V_8 = F_97 ( V_7 , V_521 , type , V_523 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_331 ] &&
V_30 -> V_5 [ V_332 ] ) {
V_22 V_328 , V_329 ;
if ( ( ! V_7 -> V_18 . V_320 &&
! V_7 -> V_18 . V_322 ) ||
! V_7 -> V_326 -> V_528 )
return - V_505 ;
V_328 = F_4 ( V_30 -> V_5 [ V_331 ] ) ;
V_329 = F_4 ( V_30 -> V_5 [ V_332 ] ) ;
if ( ( ~ V_328 && ( V_328 & ~ V_7 -> V_18 . V_320 ) ) ||
( ~ V_329 && ( V_329 & ~ V_7 -> V_18 . V_322 ) ) )
return - V_16 ;
V_328 = V_328 & V_7 -> V_18 . V_320 ;
V_329 = V_329 & V_7 -> V_18 . V_322 ;
V_8 = F_98 ( V_7 , V_328 , V_329 ) ;
if ( V_8 )
return V_8 ;
}
V_514 = 0 ;
if ( V_30 -> V_5 [ V_279 ] ) {
V_280 = F_34 (
V_30 -> V_5 [ V_279 ] ) ;
if ( V_280 == 0 )
return - V_16 ;
V_514 |= V_529 ;
}
if ( V_30 -> V_5 [ V_281 ] ) {
V_282 = F_34 (
V_30 -> V_5 [ V_281 ] ) ;
if ( V_282 == 0 )
return - V_16 ;
V_514 |= V_530 ;
}
if ( V_30 -> V_5 [ V_283 ] ) {
V_284 = F_4 (
V_30 -> V_5 [ V_283 ] ) ;
if ( V_284 < 256 )
return - V_16 ;
if ( V_284 != ( V_22 ) - 1 ) {
V_284 &= ~ 0x1 ;
}
V_514 |= V_531 ;
}
if ( V_30 -> V_5 [ V_285 ] ) {
V_286 = F_4 (
V_30 -> V_5 [ V_285 ] ) ;
V_514 |= V_532 ;
}
if ( V_30 -> V_5 [ V_287 ] ) {
V_288 = F_34 (
V_30 -> V_5 [ V_287 ] ) ;
V_514 |= V_533 ;
}
if ( V_514 ) {
T_2 V_534 , V_535 ;
V_22 V_536 , V_537 ;
T_2 V_538 ;
if ( ! V_7 -> V_326 -> V_539 )
return - V_505 ;
V_534 = V_7 -> V_18 . V_280 ;
V_535 = V_7 -> V_18 . V_282 ;
V_536 = V_7 -> V_18 . V_284 ;
V_537 = V_7 -> V_18 . V_286 ;
V_538 = V_7 -> V_18 . V_288 ;
if ( V_514 & V_529 )
V_7 -> V_18 . V_280 = V_280 ;
if ( V_514 & V_530 )
V_7 -> V_18 . V_282 = V_282 ;
if ( V_514 & V_531 )
V_7 -> V_18 . V_284 = V_284 ;
if ( V_514 & V_532 )
V_7 -> V_18 . V_286 = V_286 ;
if ( V_514 & V_533 )
V_7 -> V_18 . V_288 = V_288 ;
V_8 = F_99 ( V_7 , V_514 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_280 = V_534 ;
V_7 -> V_18 . V_282 = V_535 ;
V_7 -> V_18 . V_284 = V_536 ;
V_7 -> V_18 . V_286 = V_537 ;
V_7 -> V_18 . V_288 = V_538 ;
}
}
return 0 ;
}
static inline T_1 V_13 ( struct V_1 * V_17 )
{
return ( T_1 ) V_17 -> V_21 |
( ( T_1 ) F_11 ( V_17 -> V_18 ) -> V_14 << 32 ) ;
}
static int F_100 ( struct V_31 * V_53 ,
const struct V_485 * V_486 )
{
F_59 ( ! F_82 ( V_486 ) ) ;
if ( F_28 ( V_53 , V_488 ,
V_486 -> V_55 -> V_58 ) )
return - V_83 ;
switch ( V_486 -> V_489 ) {
case V_490 :
case V_540 :
case V_541 :
if ( F_28 ( V_53 , V_493 ,
F_101 ( V_486 ) ) )
return - V_83 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_500 , V_486 -> V_489 ) )
return - V_83 ;
if ( F_28 ( V_53 , V_501 , V_486 -> V_491 ) )
return - V_83 ;
if ( V_486 -> V_492 &&
F_28 ( V_53 , V_502 , V_486 -> V_492 ) )
return - V_83 ;
return 0 ;
}
static int F_102 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_25 * V_185 = V_17 -> V_19 ;
void * V_265 ;
V_265 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_542 ) ;
if ( ! V_265 )
return - 1 ;
if ( V_185 &&
( F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_60 ( V_53 , V_543 , V_185 -> V_544 ) ) )
goto V_59;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_545 , V_17 -> V_133 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_510 , V_546 , F_104 ( V_17 ) ) ||
F_28 ( V_53 , V_276 ,
V_7 -> V_547 ^
( V_277 << 2 ) ) )
goto V_59;
if ( V_7 -> V_326 -> V_548 ) {
int V_461 ;
struct V_485 V_486 ;
V_461 = F_105 ( V_7 , V_17 , & V_486 ) ;
if ( V_461 == 0 ) {
if ( F_100 ( V_53 , & V_486 ) )
goto V_59;
}
}
if ( V_17 -> V_549 ) {
if ( F_51 ( V_53 , V_550 , V_17 -> V_549 , V_17 -> V_551 ) )
goto V_59;
}
return F_66 ( V_53 , V_265 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
static int F_106 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_552 = 0 ;
int V_553 = 0 ;
int V_554 = V_34 -> args [ 0 ] ;
int V_555 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_552 < V_554 ) {
V_552 ++ ;
continue;
}
V_553 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_553 < V_555 ) {
V_553 ++ ;
continue;
}
if ( F_102 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_465 , V_466 ,
V_7 , V_17 ) < 0 ) {
goto V_556;
}
V_553 ++ ;
}
V_552 ++ ;
}
V_556:
F_20 () ;
V_34 -> args [ 0 ] = V_552 ;
V_34 -> args [ 1 ] = V_553 ;
return V_32 -> V_47 ;
}
static int F_107 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_185 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
if ( F_102 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_185 , V_17 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_83 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_108 ( struct V_4 * V_558 , V_22 * V_559 )
{
struct V_4 * V_51 [ V_560 + 1 ] ;
int V_561 ;
* V_559 = 0 ;
if ( ! V_558 )
return - V_16 ;
if ( F_33 ( V_51 , V_560 ,
V_558 , V_562 ) )
return - V_16 ;
for ( V_561 = 1 ; V_561 <= V_560 ; V_561 ++ )
if ( V_51 [ V_561 ] )
* V_559 |= ( 1 << V_561 ) ;
return 0 ;
}
static int F_109 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_563 ,
enum V_254 V_133 )
{
if ( ! V_563 ) {
if ( V_19 && ( V_19 -> V_564 & V_565 ) )
return - V_507 ;
return 0 ;
}
switch ( V_133 ) {
case V_135 :
if ( V_7 -> V_18 . V_51 & V_566 )
return 0 ;
break;
case V_139 :
if ( V_7 -> V_18 . V_51 & V_567 )
return 0 ;
break;
default:
break;
}
return - V_505 ;
}
static int F_110 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_568 V_129 ;
int V_35 ;
enum V_254 V_569 , V_570 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
V_22 V_571 , * V_51 = NULL ;
bool V_572 = false ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_569 = V_570 = V_185 -> V_28 -> V_133 ;
if ( V_30 -> V_5 [ V_545 ] ) {
V_570 = F_4 ( V_30 -> V_5 [ V_545 ] ) ;
if ( V_569 != V_570 )
V_572 = true ;
if ( V_570 > V_573 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_574 ] ) {
struct V_1 * V_17 = V_185 -> V_28 ;
if ( V_570 != V_137 )
return - V_16 ;
if ( F_90 ( V_185 ) )
return - V_507 ;
F_111 ( V_17 ) ;
F_112 ( V_575 !=
V_576 ) ;
V_17 -> V_577 =
F_24 ( V_30 -> V_5 [ V_574 ] ) ;
memcpy ( V_17 -> V_551 , F_23 ( V_30 -> V_5 [ V_574 ] ) ,
V_17 -> V_577 ) ;
F_113 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_578 ] ) {
V_129 . V_563 = ! ! F_34 ( V_30 -> V_5 [ V_578 ] ) ;
V_572 = true ;
V_35 = F_109 ( V_7 , V_185 , V_129 . V_563 , V_570 ) ;
if ( V_35 )
return V_35 ;
} else {
V_129 . V_563 = - 1 ;
}
if ( V_30 -> V_5 [ V_579 ] ) {
if ( V_570 != V_484 )
return - V_16 ;
V_35 = F_108 ( V_30 -> V_5 [ V_579 ] ,
& V_571 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_571 ;
V_572 = true ;
}
if ( V_51 && ( * V_51 & V_580 ) &&
! ( V_7 -> V_18 . V_273 & V_581 ) )
return - V_505 ;
if ( V_572 )
V_35 = F_114 ( V_7 , V_185 , V_570 , V_51 , & V_129 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_129 . V_563 != - 1 )
V_185 -> V_28 -> V_563 = V_129 . V_563 ;
return V_35 ;
}
static int F_115 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_568 V_129 ;
struct V_1 * V_17 ;
struct V_31 * V_53 ;
int V_35 ;
enum V_254 type = V_582 ;
V_22 V_51 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
if ( ! V_30 -> V_5 [ V_543 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_545 ] ) {
type = F_4 ( V_30 -> V_5 [ V_545 ] ) ;
if ( type > V_573 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_344 ||
! ( V_7 -> V_18 . V_334 & ( 1 << type ) ) )
return - V_505 ;
if ( type == V_583 && V_30 -> V_5 [ V_510 ] ) {
F_116 ( V_129 . V_584 , V_30 -> V_5 [ V_510 ] ,
V_546 ) ;
if ( ! F_117 ( V_129 . V_584 ) )
return - V_585 ;
}
if ( V_30 -> V_5 [ V_578 ] ) {
V_129 . V_563 = ! ! F_34 ( V_30 -> V_5 [ V_578 ] ) ;
V_35 = F_109 ( V_7 , NULL , V_129 . V_563 , type ) ;
if ( V_35 )
return V_35 ;
}
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_35 = F_108 ( type == V_484 ?
V_30 -> V_5 [ V_579 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_580 ) &&
! ( V_7 -> V_18 . V_273 & V_581 ) )
return - V_505 ;
V_17 = F_118 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_543 ] ) ,
type , V_35 ? NULL : & V_51 , & V_129 ) ;
if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
switch ( type ) {
case V_137 :
if ( ! V_30 -> V_5 [ V_574 ] )
break;
F_111 ( V_17 ) ;
F_112 ( V_575 !=
V_576 ) ;
V_17 -> V_577 =
F_24 ( V_30 -> V_5 [ V_574 ] ) ;
memcpy ( V_17 -> V_551 , F_23 ( V_30 -> V_5 [ V_574 ] ) ,
V_17 -> V_577 ) ;
F_113 ( V_17 ) ;
break;
case V_583 :
F_119 ( & V_17 -> V_586 ) ;
F_120 ( & V_17 -> V_587 ) ;
F_121 ( & V_17 -> V_588 ) ;
F_120 ( & V_17 -> V_589 ) ;
F_121 ( & V_17 -> V_590 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_122 ( & V_17 -> V_591 , & V_7 -> V_592 ) ;
V_7 -> V_547 ++ ;
break;
default:
break;
}
if ( F_102 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_7 , V_17 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_83 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_123 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_593 )
return - V_505 ;
if ( ! V_17 -> V_19 )
V_30 -> V_468 [ 1 ] = NULL ;
return F_124 ( V_7 , V_17 ) ;
}
static int F_125 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_3 V_594 ;
if ( ! V_30 -> V_5 [ V_595 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_402 )
return - V_505 ;
V_594 = F_78 ( V_30 -> V_5 [ V_595 ] ) ;
return F_126 ( V_7 , V_185 , V_594 ) ;
}
static void F_127 ( void * V_151 , struct V_596 * V_129 )
{
struct V_4 * V_84 ;
struct V_597 * V_598 = V_151 ;
if ( ( V_129 -> V_84 &&
F_51 ( V_598 -> V_53 , V_113 ,
V_129 -> V_100 , V_129 -> V_84 ) ) ||
( V_129 -> V_50 &&
F_51 ( V_598 -> V_53 , V_114 ,
V_129 -> V_102 , V_129 -> V_50 ) ) ||
( V_129 -> V_104 &&
F_28 ( V_598 -> V_53 , V_116 ,
V_129 -> V_104 ) ) )
goto V_59;
V_84 = F_47 ( V_598 -> V_53 , V_121 ) ;
if ( ! V_84 )
goto V_59;
if ( ( V_129 -> V_84 &&
F_51 ( V_598 -> V_53 , V_98 ,
V_129 -> V_100 , V_129 -> V_84 ) ) ||
( V_129 -> V_50 &&
F_51 ( V_598 -> V_53 , V_101 ,
V_129 -> V_102 , V_129 -> V_50 ) ) ||
( V_129 -> V_104 &&
F_28 ( V_598 -> V_53 , V_103 ,
V_129 -> V_104 ) ) )
goto V_59;
if ( F_56 ( V_598 -> V_53 , V_115 , V_598 -> V_97 ) )
goto V_59;
F_48 ( V_598 -> V_53 , V_84 ) ;
return;
V_59:
V_598 -> error = 1 ;
}
static int F_128 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
int V_35 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 V_599 = 0 ;
const T_2 * V_600 = NULL ;
bool V_601 ;
struct V_597 V_598 = {
. error = 0 ,
} ;
void * V_265 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_115 ] )
V_599 = F_34 ( V_30 -> V_5 [ V_115 ] ) ;
if ( V_599 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_510 ] )
V_600 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_601 = ! ! V_600 ;
if ( V_30 -> V_5 [ V_119 ] ) {
V_22 V_602 = F_4 ( V_30 -> V_5 [ V_119 ] ) ;
if ( V_602 >= V_106 )
return - V_16 ;
if ( V_602 != V_603 &&
V_602 != V_604 )
return - V_16 ;
V_601 = V_602 == V_604 ;
}
if ( ! V_7 -> V_326 -> V_605 )
return - V_505 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_606 ) ;
if ( ! V_265 )
goto V_59;
V_598 . V_53 = V_53 ;
V_598 . V_97 = V_599 ;
if ( F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_56 ( V_53 , V_115 , V_599 ) )
goto V_59;
if ( V_600 &&
F_51 ( V_53 , V_510 , V_546 , V_600 ) )
goto V_59;
if ( V_601 && V_600 &&
! ( V_7 -> V_18 . V_51 & V_299 ) )
return - V_607 ;
V_35 = F_129 ( V_7 , V_185 , V_599 , V_601 , V_600 , & V_598 ,
F_127 ) ;
if ( V_35 )
goto V_608;
if ( V_598 . error )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_83 ;
V_608:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_130 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_85 V_84 ;
int V_35 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_84 . V_97 < 0 )
return - V_16 ;
if ( ! V_84 . V_90 && ! V_84 . V_92 )
return - V_16 ;
F_111 ( V_185 -> V_28 ) ;
if ( V_84 . V_90 ) {
if ( ! V_7 -> V_326 -> V_609 ) {
V_35 = - V_505 ;
goto V_556;
}
V_35 = F_42 ( V_185 -> V_28 ) ;
if ( V_35 )
goto V_556;
V_35 = F_131 ( V_7 , V_185 , V_84 . V_97 ,
V_84 . V_94 , V_84 . V_95 ) ;
if ( V_35 )
goto V_556;
#ifdef F_132
V_185 -> V_28 -> V_610 . V_611 = V_84 . V_97 ;
#endif
} else {
if ( V_84 . V_94 || ! V_84 . V_95 ) {
V_35 = - V_16 ;
goto V_556;
}
if ( ! V_7 -> V_326 -> V_612 ) {
V_35 = - V_505 ;
goto V_556;
}
V_35 = F_42 ( V_185 -> V_28 ) ;
if ( V_35 )
goto V_556;
V_35 = F_133 ( V_7 , V_185 , V_84 . V_97 ) ;
if ( V_35 )
goto V_556;
#ifdef F_132
V_185 -> V_28 -> V_610 . V_613 = V_84 . V_97 ;
#endif
}
V_556:
F_113 ( V_185 -> V_28 ) ;
return V_35 ;
}
static int F_134 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
int V_35 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_85 V_84 ;
const T_2 * V_600 = NULL ;
V_35 = F_36 ( V_30 , & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_84 . V_99 . V_84 )
return - V_16 ;
if ( V_30 -> V_5 [ V_510 ] )
V_600 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( V_84 . type == - 1 ) {
if ( V_600 )
V_84 . type = V_604 ;
else
V_84 . type = V_603 ;
}
if ( V_84 . type != V_604 &&
V_84 . type != V_603 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_348 )
return - V_505 ;
if ( F_40 ( V_7 , & V_84 . V_99 , V_84 . V_97 ,
V_84 . type == V_604 ,
V_600 ) )
return - V_16 ;
F_111 ( V_185 -> V_28 ) ;
V_35 = F_42 ( V_185 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_135 ( V_7 , V_185 , V_84 . V_97 ,
V_84 . type == V_604 ,
V_600 , & V_84 . V_99 ) ;
F_113 ( V_185 -> V_28 ) ;
return V_35 ;
}
static int F_136 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
int V_35 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 * V_600 = NULL ;
struct V_85 V_84 ;
V_35 = F_36 ( V_30 , & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_510 ] )
V_600 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( V_84 . type == - 1 ) {
if ( V_600 )
V_84 . type = V_604 ;
else
V_84 . type = V_603 ;
}
if ( V_84 . type != V_604 &&
V_84 . type != V_603 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_614 )
return - V_505 ;
F_111 ( V_185 -> V_28 ) ;
V_35 = F_42 ( V_185 -> V_28 ) ;
if ( V_84 . type == V_604 && V_600 &&
! ( V_7 -> V_18 . V_51 & V_299 ) )
V_35 = - V_607 ;
if ( ! V_35 )
V_35 = F_137 ( V_7 , V_185 , V_84 . V_97 ,
V_84 . type == V_604 ,
V_600 ) ;
#ifdef F_132
if ( ! V_35 ) {
if ( V_84 . V_97 == V_185 -> V_28 -> V_610 . V_611 )
V_185 -> V_28 -> V_610 . V_611 = - 1 ;
else if ( V_84 . V_97 == V_185 -> V_28 -> V_610 . V_613 )
V_185 -> V_28 -> V_610 . V_613 = - 1 ;
}
#endif
F_113 ( V_185 -> V_28 ) ;
return V_35 ;
}
static int F_138 ( struct V_4 * V_615 )
{
struct V_4 * V_45 ;
int V_616 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_546 )
return - V_16 ;
V_616 ++ ;
}
return V_616 ;
}
static struct V_617 * F_139 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_618 V_619 ;
struct V_4 * V_45 ;
struct V_617 * V_620 ;
int V_145 = 0 , V_616 , V_24 ;
if ( ! V_18 -> V_438 )
return F_3 ( - V_505 ) ;
if ( ! V_30 -> V_5 [ V_621 ] )
return F_3 ( - V_16 ) ;
V_619 = F_4 ( V_30 -> V_5 [ V_621 ] ) ;
if ( V_619 != V_622 &&
V_619 != V_623 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_624 ] )
return F_3 ( - V_16 ) ;
V_616 = F_138 ( V_30 -> V_5 [ V_624 ] ) ;
if ( V_616 < 0 )
return F_3 ( V_616 ) ;
if ( V_616 > V_18 -> V_438 )
return F_3 ( - V_625 ) ;
V_620 = F_38 ( sizeof( * V_620 ) + ( sizeof( struct V_626 ) * V_616 ) ,
V_127 ) ;
if ( ! V_620 )
return F_3 ( - V_128 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_620 -> V_627 [ V_145 ] . V_628 , F_23 ( V_45 ) , V_546 ) ;
V_145 ++ ;
}
V_620 -> V_629 = V_616 ;
V_620 -> V_619 = V_619 ;
return V_620 ;
}
static int F_140 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_617 * V_620 ;
int V_35 ;
if ( V_185 -> V_28 -> V_133 != V_134 &&
V_185 -> V_28 -> V_133 != V_136 )
return - V_505 ;
if ( ! V_185 -> V_28 -> V_506 )
return - V_16 ;
V_620 = F_139 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_620 ) )
return F_18 ( V_620 ) ;
V_35 = F_141 ( V_7 , V_185 , V_620 ) ;
F_41 ( V_620 ) ;
return V_35 ;
}
static int F_142 ( struct V_4 * V_5 [] ,
struct V_630 * V_631 )
{
bool V_632 = false ;
if ( ! F_22 ( V_5 [ V_633 ] ) ||
! F_22 ( V_5 [ V_634 ] ) ||
! F_22 ( V_5 [ V_635 ] ) ||
! F_22 ( V_5 [ V_636 ] ) )
return - V_16 ;
memset ( V_631 , 0 , sizeof( * V_631 ) ) ;
if ( V_5 [ V_637 ] ) {
V_631 -> V_638 = F_23 ( V_5 [ V_637 ] ) ;
V_631 -> V_639 = F_24 ( V_5 [ V_637 ] ) ;
if ( ! V_631 -> V_639 )
return - V_16 ;
V_632 = true ;
}
if ( V_5 [ V_633 ] ) {
V_631 -> V_640 = F_23 ( V_5 [ V_633 ] ) ;
V_631 -> V_641 = F_24 ( V_5 [ V_633 ] ) ;
V_632 = true ;
}
if ( ! V_632 )
return - V_16 ;
if ( V_5 [ V_634 ] ) {
V_631 -> V_642 = F_23 ( V_5 [ V_634 ] ) ;
V_631 -> V_643 = F_24 ( V_5 [ V_634 ] ) ;
}
if ( V_5 [ V_635 ] ) {
V_631 -> V_644 =
F_23 ( V_5 [ V_635 ] ) ;
V_631 -> V_645 =
F_24 ( V_5 [ V_635 ] ) ;
}
if ( V_5 [ V_636 ] ) {
V_631 -> V_646 =
F_23 ( V_5 [ V_636 ] ) ;
V_631 -> V_647 =
F_24 ( V_5 [ V_636 ] ) ;
}
if ( V_5 [ V_648 ] ) {
V_631 -> V_649 = F_23 ( V_5 [ V_648 ] ) ;
V_631 -> V_650 = F_24 ( V_5 [ V_648 ] ) ;
}
return 0 ;
}
static bool F_143 ( struct V_6 * V_7 ,
struct V_651 * V_129 )
{
struct V_1 * V_17 ;
bool V_461 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_133 != V_134 &&
V_17 -> V_133 != V_136 )
continue;
if ( ! V_17 -> V_508 . V_55 )
continue;
V_129 -> V_486 = V_17 -> V_508 ;
V_461 = true ;
break;
}
return V_461 ;
}
static bool F_144 ( struct V_6 * V_7 ,
enum V_652 V_653 ,
enum V_654 V_52 )
{
if ( V_653 > V_655 )
return false ;
switch ( V_52 ) {
case V_656 :
if ( ! ( V_7 -> V_18 . V_273 & V_657 ) &&
V_653 == V_658 )
return false ;
return true ;
case V_422 :
case V_659 :
if ( V_653 == V_658 )
return false ;
return true ;
default:
return false ;
}
}
static int F_145 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_651 V_129 ;
int V_35 ;
T_2 V_660 = 0 ;
if ( V_185 -> V_28 -> V_133 != V_134 &&
V_185 -> V_28 -> V_133 != V_136 )
return - V_505 ;
if ( ! V_7 -> V_326 -> V_350 )
return - V_505 ;
if ( V_17 -> V_506 )
return - V_661 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
if ( ! V_30 -> V_5 [ V_662 ] ||
! V_30 -> V_5 [ V_663 ] ||
! V_30 -> V_5 [ V_637 ] )
return - V_16 ;
V_35 = F_142 ( V_30 -> V_5 , & V_129 . V_664 ) ;
if ( V_35 )
return V_35 ;
V_129 . V_506 =
F_4 ( V_30 -> V_5 [ V_662 ] ) ;
V_129 . V_665 =
F_4 ( V_30 -> V_5 [ V_663 ] ) ;
V_35 = F_146 ( V_7 , V_129 . V_506 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_550 ] ) {
V_129 . V_551 = F_23 ( V_30 -> V_5 [ V_550 ] ) ;
V_129 . V_549 =
F_24 ( V_30 -> V_5 [ V_550 ] ) ;
if ( V_129 . V_549 == 0 ||
V_129 . V_549 > V_575 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_666 ] ) {
V_129 . V_667 = F_4 (
V_30 -> V_5 [ V_666 ] ) ;
if ( V_129 . V_667 != V_668 &&
V_129 . V_667 != V_669 &&
V_129 . V_667 != V_670 )
return - V_16 ;
}
V_129 . V_671 = ! ! V_30 -> V_5 [ V_672 ] ;
if ( V_30 -> V_5 [ V_673 ] ) {
V_129 . V_653 = F_4 (
V_30 -> V_5 [ V_673 ] ) ;
if ( ! F_144 ( V_7 , V_129 . V_653 ,
V_659 ) )
return - V_16 ;
} else
V_129 . V_653 = V_674 ;
V_35 = F_147 ( V_7 , V_30 , & V_129 . V_675 ,
V_676 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_677 ] ) {
if ( ! ( V_7 -> V_18 . V_273 & V_678 ) )
return - V_505 ;
V_129 . V_679 = F_78 (
V_30 -> V_5 [ V_677 ] ) ;
}
if ( V_30 -> V_5 [ V_680 ] ) {
if ( V_185 -> V_28 -> V_133 != V_136 )
return - V_16 ;
V_129 . V_681 =
F_34 ( V_30 -> V_5 [ V_680 ] ) ;
if ( V_129 . V_681 > 127 )
return - V_16 ;
if ( V_129 . V_681 != 0 &&
! ( V_7 -> V_18 . V_273 & V_682 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_683 ] ) {
T_2 V_24 ;
if ( V_185 -> V_28 -> V_133 != V_136 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_683 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_129 . V_684 = V_24 ;
if ( V_129 . V_684 != 0 &&
! ( V_7 -> V_18 . V_273 & V_685 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_488 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_129 . V_486 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_508 . V_55 ) {
V_129 . V_486 = V_17 -> V_508 ;
} else if ( ! F_143 ( V_7 , & V_129 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_129 . V_486 ) )
return - V_16 ;
V_35 = F_148 ( V_17 -> V_18 , & V_129 . V_486 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 ) {
V_660 = F_149 ( V_129 . V_486 . V_489 ) ;
V_129 . V_686 = true ;
}
V_35 = F_150 ( V_7 , V_17 , V_17 -> V_133 ,
V_129 . V_486 . V_55 ,
V_687 ,
V_660 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_621 ] ) {
V_129 . V_620 = F_139 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_129 . V_620 ) )
return F_18 ( V_129 . V_620 ) ;
}
F_111 ( V_17 ) ;
V_35 = F_151 ( V_7 , V_185 , & V_129 ) ;
if ( ! V_35 ) {
V_17 -> V_508 = V_129 . V_486 ;
V_17 -> V_506 = V_129 . V_506 ;
V_17 -> V_486 = V_129 . V_486 ;
V_17 -> V_549 = V_129 . V_549 ;
memcpy ( V_17 -> V_551 , V_129 . V_551 , V_17 -> V_549 ) ;
}
F_113 ( V_17 ) ;
F_41 ( V_129 . V_620 ) ;
return V_35 ;
}
static int F_152 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_630 V_129 ;
int V_35 ;
if ( V_185 -> V_28 -> V_133 != V_134 &&
V_185 -> V_28 -> V_133 != V_136 )
return - V_505 ;
if ( ! V_7 -> V_326 -> V_688 )
return - V_505 ;
if ( ! V_17 -> V_506 )
return - V_16 ;
V_35 = F_142 ( V_30 -> V_5 , & V_129 ) ;
if ( V_35 )
return V_35 ;
F_111 ( V_17 ) ;
V_35 = F_153 ( V_7 , V_185 , & V_129 ) ;
F_113 ( V_17 ) ;
return V_35 ;
}
static int F_154 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
return F_155 ( V_7 , V_185 , false ) ;
}
static int F_156 ( struct V_29 * V_30 ,
enum V_254 V_133 ,
struct V_689 * V_129 )
{
struct V_4 * V_51 [ V_690 + 1 ] ;
struct V_4 * V_558 ;
int V_561 ;
V_558 = V_30 -> V_5 [ V_691 ] ;
if ( V_558 ) {
struct V_692 * V_693 ;
V_693 = F_23 ( V_558 ) ;
V_129 -> V_694 = V_693 -> V_695 ;
V_129 -> V_696 = V_693 -> V_697 ;
V_129 -> V_696 &= V_129 -> V_694 ;
if ( ( V_129 -> V_694 |
V_129 -> V_696 ) & F_149 ( V_698 ) )
return - V_16 ;
return 0 ;
}
V_558 = V_30 -> V_5 [ V_699 ] ;
if ( ! V_558 )
return 0 ;
if ( F_33 ( V_51 , V_690 ,
V_558 , V_700 ) )
return - V_16 ;
switch ( V_133 ) {
case V_134 :
case V_135 :
case V_136 :
V_129 -> V_694 = F_149 ( V_701 ) |
F_149 ( V_702 ) |
F_149 ( V_703 ) |
F_149 ( V_704 ) ;
break;
case V_140 :
case V_139 :
V_129 -> V_694 = F_149 ( V_701 ) |
F_149 ( V_705 ) ;
break;
case V_137 :
V_129 -> V_694 = F_149 ( V_706 ) |
F_149 ( V_704 ) |
F_149 ( V_701 ) ;
default:
return - V_16 ;
}
for ( V_561 = 1 ; V_561 <= V_690 ; V_561 ++ ) {
if ( V_51 [ V_561 ] ) {
V_129 -> V_696 |= ( 1 << V_561 ) ;
if ( V_561 > V_707 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_157 ( struct V_31 * V_53 , struct V_708 * V_30 ,
int V_45 )
{
struct V_4 * V_226 ;
V_22 V_246 ;
T_3 V_709 ;
V_226 = F_47 ( V_53 , V_45 ) ;
if ( ! V_226 )
return false ;
V_246 = F_158 ( V_30 ) ;
V_709 = V_246 < ( 1UL << 16 ) ? V_246 : 0 ;
if ( V_246 > 0 &&
F_28 ( V_53 , V_710 , V_246 ) )
return false ;
if ( V_709 > 0 &&
F_55 ( V_53 , V_711 , V_709 ) )
return false ;
if ( V_30 -> V_51 & V_712 ) {
if ( F_56 ( V_53 , V_713 , V_30 -> V_230 ) )
return false ;
if ( V_30 -> V_51 & V_714 &&
F_29 ( V_53 , V_715 ) )
return false ;
if ( V_30 -> V_51 & V_716 &&
F_29 ( V_53 , V_717 ) )
return false ;
} else if ( V_30 -> V_51 & V_718 ) {
if ( F_56 ( V_53 , V_719 , V_30 -> V_230 ) )
return false ;
if ( F_56 ( V_53 , V_720 , V_30 -> V_721 ) )
return false ;
if ( V_30 -> V_51 & V_714 &&
F_29 ( V_53 , V_715 ) )
return false ;
if ( V_30 -> V_51 & V_722 &&
F_29 ( V_53 , V_723 ) )
return false ;
if ( V_30 -> V_51 & V_724 &&
F_29 ( V_53 , V_725 ) )
return false ;
if ( V_30 -> V_51 & V_726 &&
F_29 ( V_53 , V_727 ) )
return false ;
if ( V_30 -> V_51 & V_716 &&
F_29 ( V_53 , V_717 ) )
return false ;
}
F_48 ( V_53 , V_226 ) ;
return true ;
}
static bool F_159 ( struct V_31 * V_53 , T_2 V_695 , T_6 * signal ,
int V_728 )
{
void * V_45 ;
int V_145 = 0 ;
if ( ! V_695 )
return true ;
V_45 = F_47 ( V_53 , V_728 ) ;
if ( ! V_45 )
return false ;
for ( V_145 = 0 ; V_145 < V_729 ; V_145 ++ ) {
if ( ! ( V_695 & F_149 ( V_145 ) ) )
continue;
if ( F_56 ( V_53 , V_145 , signal [ V_145 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_160 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_185 ,
const T_2 * V_600 , struct V_730 * V_731 )
{
void * V_265 ;
struct V_4 * V_732 , * V_733 ;
V_265 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_734 ) ;
if ( ! V_265 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_600 ) ||
F_28 ( V_53 , V_276 , V_731 -> V_735 ) )
goto V_59;
V_732 = F_47 ( V_53 , V_736 ) ;
if ( ! V_732 )
goto V_59;
if ( ( V_731 -> V_737 & V_738 ) &&
F_28 ( V_53 , V_739 ,
V_731 -> V_740 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_741 ) &&
F_28 ( V_53 , V_742 ,
V_731 -> V_743 ) )
goto V_59;
if ( ( V_731 -> V_737 & ( V_744 |
V_745 ) ) &&
F_28 ( V_53 , V_746 ,
( V_22 ) V_731 -> V_747 ) )
goto V_59;
if ( ( V_731 -> V_737 & ( V_748 |
V_749 ) ) &&
F_28 ( V_53 , V_750 ,
( V_22 ) V_731 -> V_751 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_745 ) &&
F_103 ( V_53 , V_752 ,
V_731 -> V_747 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_749 ) &&
F_103 ( V_53 , V_753 ,
V_731 -> V_751 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_754 ) &&
F_55 ( V_53 , V_755 , V_731 -> V_756 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_757 ) &&
F_55 ( V_53 , V_758 , V_731 -> V_759 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_760 ) &&
F_56 ( V_53 , V_761 ,
V_731 -> V_762 ) )
goto V_59;
switch ( V_7 -> V_18 . V_763 ) {
case V_764 :
if ( ( V_731 -> V_737 & V_765 ) &&
F_56 ( V_53 , V_766 ,
V_731 -> signal ) )
goto V_59;
if ( ( V_731 -> V_737 & V_767 ) &&
F_56 ( V_53 , V_768 ,
V_731 -> V_769 ) )
goto V_59;
break;
default:
break;
}
if ( V_731 -> V_737 & V_770 ) {
if ( ! F_159 ( V_53 , V_731 -> V_771 ,
V_731 -> V_772 ,
V_773 ) )
goto V_59;
}
if ( V_731 -> V_737 & V_774 ) {
if ( ! F_159 ( V_53 , V_731 -> V_771 ,
V_731 -> V_775 ,
V_776 ) )
goto V_59;
}
if ( V_731 -> V_737 & V_777 ) {
if ( ! F_157 ( V_53 , & V_731 -> V_778 ,
V_779 ) )
goto V_59;
}
if ( V_731 -> V_737 & V_780 ) {
if ( ! F_157 ( V_53 , & V_731 -> V_781 ,
V_782 ) )
goto V_59;
}
if ( ( V_731 -> V_737 & V_783 ) &&
F_28 ( V_53 , V_784 ,
V_731 -> V_785 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_786 ) &&
F_28 ( V_53 , V_787 ,
V_731 -> V_788 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_789 ) &&
F_28 ( V_53 , V_790 ,
V_731 -> V_791 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_792 ) &&
F_28 ( V_53 , V_793 ,
V_731 -> V_794 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_795 ) &&
F_28 ( V_53 , V_796 ,
V_731 -> V_797 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_798 ) &&
F_28 ( V_53 , V_799 ,
V_731 -> V_800 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_801 ) &&
F_28 ( V_53 , V_802 ,
V_731 -> V_803 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_804 ) &&
F_28 ( V_53 , V_805 ,
V_731 -> V_806 ) )
goto V_59;
if ( V_731 -> V_737 & V_807 ) {
V_733 = F_47 ( V_53 , V_808 ) ;
if ( ! V_733 )
goto V_59;
if ( ( ( V_731 -> V_733 . V_51 & V_809 ) &&
F_29 ( V_53 , V_810 ) ) ||
( ( V_731 -> V_733 . V_51 & V_811 ) &&
F_29 ( V_53 , V_812 ) ) ||
( ( V_731 -> V_733 . V_51 & V_813 ) &&
F_29 ( V_53 , V_814 ) ) ||
F_56 ( V_53 , V_815 ,
V_731 -> V_733 . V_665 ) ||
F_55 ( V_53 , V_816 ,
V_731 -> V_733 . V_506 ) )
goto V_59;
F_48 ( V_53 , V_733 ) ;
}
if ( ( V_731 -> V_737 & V_817 ) &&
F_51 ( V_53 , V_818 ,
sizeof( struct V_692 ) ,
& V_731 -> V_693 ) )
goto V_59;
if ( ( V_731 -> V_737 & V_819 ) &&
F_103 ( V_53 , V_820 ,
V_731 -> V_821 ) )
goto V_59;
F_48 ( V_53 , V_732 ) ;
if ( ( V_731 -> V_737 & V_822 ) &&
F_51 ( V_53 , V_634 , V_731 -> V_823 ,
V_731 -> V_824 ) )
goto V_59;
return F_66 ( V_53 , V_265 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
static int F_161 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_730 V_731 ;
struct V_6 * V_185 ;
struct V_1 * V_17 ;
T_2 V_600 [ V_546 ] ;
int V_825 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_185 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_826;
}
if ( ! V_185 -> V_326 -> V_827 ) {
V_35 = - V_505 ;
goto V_826;
}
while ( 1 ) {
memset ( & V_731 , 0 , sizeof( V_731 ) ) ;
V_35 = F_162 ( V_185 , V_17 -> V_19 , V_825 ,
V_600 , & V_731 ) ;
if ( V_35 == - V_607 )
break;
if ( V_35 )
goto V_826;
if ( F_160 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_465 , V_466 ,
V_185 , V_17 -> V_19 , V_600 ,
& V_731 ) < 0 )
goto V_556;
V_825 ++ ;
}
V_556:
V_34 -> args [ 2 ] = V_825 ;
V_35 = V_32 -> V_47 ;
V_826:
F_21 ( V_185 ) ;
return V_35 ;
}
static int F_163 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_730 V_731 ;
struct V_31 * V_53 ;
T_2 * V_600 = NULL ;
int V_35 ;
memset ( & V_731 , 0 , sizeof( V_731 ) ) ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
V_600 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( ! V_7 -> V_326 -> V_828 )
return - V_505 ;
V_35 = F_164 ( V_7 , V_185 , V_600 , & V_731 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
if ( F_160 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_7 , V_185 , V_600 , & V_731 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_83 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_165 ( struct V_18 * V_18 ,
struct V_689 * V_129 ,
enum V_829 V_830 )
{
if ( V_129 -> V_831 != - 1 )
return - V_16 ;
if ( V_129 -> V_832 )
return - V_16 ;
F_112 ( V_690 != 7 ) ;
switch ( V_830 ) {
case V_833 :
case V_834 :
if ( V_129 -> V_694 &
~ ( F_149 ( V_706 ) |
F_149 ( V_704 ) |
F_149 ( V_701 ) ) )
return - V_16 ;
break;
case V_835 :
case V_836 :
if ( ! ( V_129 -> V_696 & F_149 ( V_705 ) ) )
return - V_16 ;
V_129 -> V_694 &= ~ F_149 ( V_705 ) ;
break;
default:
if ( V_129 -> V_837 != V_838 )
return - V_16 ;
if ( V_129 -> V_800 )
return - V_16 ;
if ( V_129 -> V_839 & V_840 )
return - V_16 ;
}
if ( V_830 != V_835 &&
V_830 != V_836 ) {
if ( V_129 -> V_696 & F_149 ( V_705 ) )
return - V_16 ;
V_129 -> V_694 &= ~ F_149 ( V_705 ) ;
}
if ( V_830 != V_835 ) {
if ( V_129 -> V_839 & V_841 )
return - V_16 ;
if ( V_129 -> V_839 & V_842 )
return - V_16 ;
if ( V_129 -> V_843 )
return - V_16 ;
if ( V_129 -> V_844 || V_129 -> V_845 || V_129 -> V_846 )
return - V_16 ;
}
if ( V_830 != V_847 ) {
if ( V_129 -> V_848 )
return - V_16 ;
}
switch ( V_830 ) {
case V_849 :
if ( ! ( V_129 -> V_694 & F_149 ( V_701 ) ) )
return - V_505 ;
break;
case V_847 :
if ( V_129 -> V_694 &
~ ( F_149 ( V_701 ) |
F_149 ( V_706 ) |
F_149 ( V_850 ) |
F_149 ( V_702 ) |
F_149 ( V_703 ) |
F_149 ( V_704 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_273 & V_851 ) &&
V_129 -> V_694 &
( F_149 ( V_706 ) |
F_149 ( V_850 ) ) )
return - V_16 ;
break;
case V_852 :
case V_853 :
if ( V_129 -> V_694 & ~ F_149 ( V_701 ) )
return - V_16 ;
break;
case V_835 :
if ( V_129 -> V_694 & ~ ( F_149 ( V_701 ) |
F_149 ( V_703 ) ) )
return - V_16 ;
if ( V_129 -> V_696 & F_149 ( V_701 ) &&
! V_129 -> V_843 )
return - V_16 ;
break;
case V_836 :
return - V_16 ;
case V_833 :
if ( V_129 -> V_839 & V_840 )
return - V_16 ;
break;
case V_834 :
if ( V_129 -> V_837 != V_838 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_166 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_854 = V_30 -> V_5 [ V_855 ] ;
struct V_25 * V_856 ;
int V_461 ;
if ( ! V_854 )
return NULL ;
V_856 = F_167 ( F_93 ( V_30 ) , F_4 ( V_854 ) ) ;
if ( ! V_856 )
return F_3 ( - V_23 ) ;
if ( ! V_856 -> V_28 || V_856 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_461 = - V_16 ;
goto error;
}
if ( V_856 -> V_28 -> V_133 != V_135 &&
V_856 -> V_28 -> V_133 != V_134 &&
V_856 -> V_28 -> V_133 != V_136 ) {
V_461 = - V_16 ;
goto error;
}
if ( ! F_90 ( V_856 ) ) {
V_461 = - V_518 ;
goto error;
}
return V_856 ;
error:
F_168 ( V_856 ) ;
return F_3 ( V_461 ) ;
}
static int F_169 ( struct V_29 * V_30 ,
struct V_689 * V_129 )
{
struct V_4 * V_87 [ V_857 + 1 ] ;
struct V_4 * V_558 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_858 ] )
return 0 ;
V_558 = V_30 -> V_5 [ V_858 ] ;
V_35 = F_33 ( V_87 , V_857 , V_558 ,
V_859 ) ;
if ( V_35 )
return V_35 ;
if ( V_87 [ V_860 ] )
V_129 -> V_861 = F_34 (
V_87 [ V_860 ] ) ;
if ( V_129 -> V_861 & ~ V_862 )
return - V_16 ;
if ( V_87 [ V_863 ] )
V_129 -> V_864 = F_34 ( V_87 [ V_863 ] ) ;
if ( V_129 -> V_864 & ~ V_865 )
return - V_16 ;
V_129 -> V_839 |= V_841 ;
return 0 ;
}
static int F_170 ( struct V_29 * V_30 ,
struct V_689 * V_129 )
{
if ( V_30 -> V_5 [ V_866 ] ) {
V_129 -> V_867 =
F_23 ( V_30 -> V_5 [ V_866 ] ) ;
V_129 -> V_868 =
F_24 ( V_30 -> V_5 [ V_866 ] ) ;
if ( V_129 -> V_868 < 2 )
return - V_16 ;
if ( V_129 -> V_868 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_869 ] ) {
V_129 -> V_870 =
F_23 ( V_30 -> V_5 [ V_869 ] ) ;
V_129 -> V_871 =
F_24 ( V_30 -> V_5 [ V_869 ] ) ;
if ( V_129 -> V_871 < 2 ||
V_129 -> V_871 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_171 ( struct V_29 * V_30 ,
struct V_689 * V_129 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_872 ] )
V_129 -> V_832 = F_78 ( V_30 -> V_5 [ V_872 ] ) ;
if ( V_30 -> V_5 [ V_873 ] )
V_129 -> V_845 =
F_23 ( V_30 -> V_5 [ V_873 ] ) ;
if ( V_30 -> V_5 [ V_874 ] )
V_129 -> V_846 =
F_23 ( V_30 -> V_5 [ V_874 ] ) ;
V_35 = F_170 ( V_30 , V_129 ) ;
if ( V_35 )
return V_35 ;
return F_169 ( V_30 , V_129 ) ;
}
static int F_172 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_689 V_129 ;
T_2 * V_600 ;
int V_35 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_831 = - 1 ;
if ( ! V_7 -> V_326 -> V_875 )
return - V_505 ;
if ( V_30 -> V_5 [ V_876 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
V_600 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( V_30 -> V_5 [ V_877 ] ) {
V_129 . V_843 =
F_23 ( V_30 -> V_5 [ V_877 ] ) ;
V_129 . V_878 =
F_24 ( V_30 -> V_5 [ V_877 ] ) ;
}
if ( V_30 -> V_5 [ V_879 ] ) {
V_129 . V_880 =
F_78 ( V_30 -> V_5 [ V_879 ] ) ;
V_129 . V_839 |= V_842 ;
}
if ( V_30 -> V_5 [ V_881 ] ) {
V_129 . V_844 =
F_23 ( V_30 -> V_5 [ V_881 ] ) ;
V_129 . V_882 =
F_24 ( V_30 -> V_5 [ V_881 ] ) ;
}
if ( V_30 -> V_5 [ V_883 ] )
return - V_16 ;
if ( F_156 ( V_30 , V_185 -> V_28 -> V_133 , & V_129 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_884 ] ) {
V_129 . V_837 =
F_34 ( V_30 -> V_5 [ V_884 ] ) ;
if ( V_129 . V_837 >= V_885 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_886 ] ) {
V_129 . V_762 =
F_34 ( V_30 -> V_5 [ V_886 ] ) ;
if ( V_129 . V_762 >= V_887 )
return - V_16 ;
V_129 . V_839 |= V_840 ;
}
if ( V_30 -> V_5 [ V_888 ] ) {
enum V_889 V_890 = F_4 (
V_30 -> V_5 [ V_888 ] ) ;
if ( V_890 <= V_891 ||
V_890 > V_892 )
return - V_16 ;
V_129 . V_800 = V_890 ;
}
V_35 = F_171 ( V_30 , & V_129 ) ;
if ( V_35 )
return V_35 ;
V_129 . V_848 = F_166 ( V_30 , V_7 ) ;
if ( F_17 ( V_129 . V_848 ) )
return F_18 ( V_129 . V_848 ) ;
switch ( V_185 -> V_28 -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
case V_140 :
case V_139 :
case V_138 :
case V_137 :
break;
default:
V_35 = - V_505 ;
goto V_893;
}
V_35 = F_173 ( V_7 , V_185 , V_600 , & V_129 ) ;
V_893:
if ( V_129 . V_848 )
F_168 ( V_129 . V_848 ) ;
return V_35 ;
}
static int F_174 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
int V_35 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_689 V_129 ;
T_2 * V_600 = NULL ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
if ( ! V_7 -> V_326 -> V_352 )
return - V_505 ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_883 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_877 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_876 ] &&
! V_30 -> V_5 [ V_872 ] )
return - V_16 ;
V_600 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_129 . V_843 =
F_23 ( V_30 -> V_5 [ V_877 ] ) ;
V_129 . V_878 =
F_24 ( V_30 -> V_5 [ V_877 ] ) ;
V_129 . V_831 =
F_78 ( V_30 -> V_5 [ V_883 ] ) ;
if ( V_30 -> V_5 [ V_872 ] )
V_129 . V_832 = F_78 ( V_30 -> V_5 [ V_872 ] ) ;
else
V_129 . V_832 = F_78 ( V_30 -> V_5 [ V_876 ] ) ;
if ( ! V_129 . V_832 || V_129 . V_832 > V_894 )
return - V_16 ;
if ( V_30 -> V_5 [ V_879 ] ) {
V_129 . V_880 =
F_78 ( V_30 -> V_5 [ V_879 ] ) ;
V_129 . V_839 |= V_842 ;
}
if ( V_30 -> V_5 [ V_881 ] ) {
V_129 . V_844 =
F_23 ( V_30 -> V_5 [ V_881 ] ) ;
V_129 . V_882 =
F_24 ( V_30 -> V_5 [ V_881 ] ) ;
}
if ( V_30 -> V_5 [ V_873 ] )
V_129 . V_845 =
F_23 ( V_30 -> V_5 [ V_873 ] ) ;
if ( V_30 -> V_5 [ V_874 ] )
V_129 . V_846 =
F_23 ( V_30 -> V_5 [ V_874 ] ) ;
if ( V_30 -> V_5 [ V_895 ] ) {
V_129 . V_896 = true ;
V_129 . V_897 =
F_34 ( V_30 -> V_5 [ V_895 ] ) ;
}
if ( V_30 -> V_5 [ V_884 ] ) {
V_129 . V_837 =
F_34 ( V_30 -> V_5 [ V_884 ] ) ;
if ( V_129 . V_837 >= V_885 )
return - V_16 ;
}
V_35 = F_170 ( V_30 , & V_129 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_169 ( V_30 , & V_129 ) ;
if ( V_35 )
return V_35 ;
if ( F_156 ( V_30 , V_185 -> V_28 -> V_133 , & V_129 ) )
return - V_16 ;
F_112 ( V_690 != 7 ) ;
switch ( V_185 -> V_28 -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
if ( ! ( V_7 -> V_18 . V_51 & V_303 ) ||
! ( V_129 . V_696 & F_149 ( V_703 ) ) )
V_129 . V_839 &= ~ V_841 ;
if ( ( V_129 . V_696 & F_149 ( V_705 ) ) ||
V_30 -> V_5 [ V_872 ] )
return - V_16 ;
V_129 . V_694 &= ~ F_149 ( V_705 ) ;
if ( ! ( V_7 -> V_18 . V_273 &
V_851 ) &&
V_129 . V_694 &
( F_149 ( V_706 ) |
F_149 ( V_850 ) ) )
return - V_16 ;
V_129 . V_848 = F_166 ( V_30 , V_7 ) ;
if ( F_17 ( V_129 . V_848 ) )
return F_18 ( V_129 . V_848 ) ;
break;
case V_137 :
V_129 . V_839 &= ~ V_841 ;
if ( V_129 . V_694 & F_149 ( V_850 ) )
return - V_16 ;
if ( ( V_129 . V_696 & F_149 ( V_705 ) ) ||
V_30 -> V_5 [ V_872 ] )
return - V_16 ;
break;
case V_139 :
case V_140 :
V_129 . V_839 &= ~ V_841 ;
if ( V_129 . V_694 &
( F_149 ( V_850 ) |
F_149 ( V_706 ) ) )
return - V_16 ;
if ( ! ( V_129 . V_696 & F_149 ( V_705 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_307 ) )
return - V_505 ;
if ( ! ( V_7 -> V_18 . V_51 & V_309 ) )
return - V_505 ;
V_129 . V_694 &= ~ F_149 ( V_701 ) ;
break;
default:
return - V_505 ;
}
V_35 = F_175 ( V_7 , V_185 , V_600 , & V_129 ) ;
if ( V_129 . V_848 )
F_168 ( V_129 . V_848 ) ;
return V_35 ;
}
static int F_176 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 * V_600 = NULL ;
if ( V_30 -> V_5 [ V_510 ] )
V_600 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( V_185 -> V_28 -> V_133 != V_134 &&
V_185 -> V_28 -> V_133 != V_135 &&
V_185 -> V_28 -> V_133 != V_137 &&
V_185 -> V_28 -> V_133 != V_136 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_898 )
return - V_505 ;
return F_177 ( V_7 , V_185 , V_600 ) ;
}
static int F_178 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_185 ,
T_2 * V_899 , T_2 * V_900 ,
struct V_901 * V_902 )
{
void * V_265 ;
struct V_4 * V_903 ;
V_265 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_734 ) ;
if ( ! V_265 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_899 ) ||
F_51 ( V_53 , V_904 , V_546 , V_900 ) ||
F_28 ( V_53 , V_276 , V_902 -> V_735 ) )
goto V_59;
V_903 = F_47 ( V_53 , V_905 ) ;
if ( ! V_903 )
goto V_59;
if ( ( V_902 -> V_737 & V_906 ) &&
F_28 ( V_53 , V_907 ,
V_902 -> V_908 ) )
goto V_59;
if ( ( ( V_902 -> V_737 & V_909 ) &&
F_28 ( V_53 , V_910 , V_902 -> V_911 ) ) ||
( ( V_902 -> V_737 & V_912 ) &&
F_28 ( V_53 , V_913 ,
V_902 -> V_914 ) ) ||
( ( V_902 -> V_737 & V_915 ) &&
F_28 ( V_53 , V_916 ,
V_902 -> V_917 ) ) ||
( ( V_902 -> V_737 & V_918 ) &&
F_56 ( V_53 , V_919 ,
V_902 -> V_51 ) ) ||
( ( V_902 -> V_737 & V_920 ) &&
F_28 ( V_53 , V_921 ,
V_902 -> V_922 ) ) ||
( ( V_902 -> V_737 & V_923 ) &&
F_56 ( V_53 , V_924 ,
V_902 -> V_925 ) ) )
goto V_59;
F_48 ( V_53 , V_903 ) ;
return F_66 ( V_53 , V_265 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
static int F_179 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_901 V_902 ;
struct V_6 * V_185 ;
struct V_1 * V_17 ;
T_2 V_899 [ V_546 ] ;
T_2 V_900 [ V_546 ] ;
int V_926 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_185 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_185 -> V_326 -> V_927 ) {
V_35 = - V_505 ;
goto V_826;
}
if ( V_17 -> V_133 != V_137 ) {
V_35 = - V_505 ;
goto V_826;
}
while ( 1 ) {
V_35 = F_180 ( V_185 , V_17 -> V_19 , V_926 , V_899 ,
V_900 , & V_902 ) ;
if ( V_35 == - V_607 )
break;
if ( V_35 )
goto V_826;
if ( F_178 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_465 , V_466 ,
V_17 -> V_19 , V_899 , V_900 ,
& V_902 ) < 0 )
goto V_556;
V_926 ++ ;
}
V_556:
V_34 -> args [ 2 ] = V_926 ;
V_35 = V_32 -> V_47 ;
V_826:
F_21 ( V_185 ) ;
return V_35 ;
}
static int F_181 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
int V_35 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_901 V_902 ;
struct V_31 * V_53 ;
T_2 * V_899 = NULL ;
T_2 V_900 [ V_546 ] ;
memset ( & V_902 , 0 , sizeof( V_902 ) ) ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
V_899 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( ! V_7 -> V_326 -> V_928 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_137 )
return - V_505 ;
V_35 = F_182 ( V_7 , V_185 , V_899 , V_900 , & V_902 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
if ( F_178 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_185 , V_899 , V_900 , & V_902 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_83 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_183 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 * V_899 = NULL ;
T_2 * V_900 = NULL ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_904 ] )
return - V_16 ;
V_899 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_900 = F_23 ( V_30 -> V_5 [ V_904 ] ) ;
if ( ! V_7 -> V_326 -> V_929 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_137 )
return - V_505 ;
return F_184 ( V_7 , V_185 , V_899 , V_900 ) ;
}
static int F_185 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 * V_899 = NULL ;
T_2 * V_900 = NULL ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_904 ] )
return - V_16 ;
V_899 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_900 = F_23 ( V_30 -> V_5 [ V_904 ] ) ;
if ( ! V_7 -> V_326 -> V_354 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_137 )
return - V_505 ;
return F_186 ( V_7 , V_185 , V_899 , V_900 ) ;
}
static int F_187 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 * V_899 = NULL ;
if ( V_30 -> V_5 [ V_510 ] )
V_899 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( ! V_7 -> V_326 -> V_930 )
return - V_505 ;
return F_188 ( V_7 , V_185 , V_899 ) ;
}
static int F_189 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_931 V_129 ;
int V_35 ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_932 = - 1 ;
V_129 . V_933 = - 1 ;
V_129 . V_934 = - 1 ;
V_129 . V_935 = - 1 ;
V_129 . V_936 = - 1 ;
V_129 . V_681 = - 1 ;
V_129 . V_684 = - 1 ;
if ( V_30 -> V_5 [ V_937 ] )
V_129 . V_932 =
F_34 ( V_30 -> V_5 [ V_937 ] ) ;
if ( V_30 -> V_5 [ V_938 ] )
V_129 . V_933 =
F_34 ( V_30 -> V_5 [ V_938 ] ) ;
if ( V_30 -> V_5 [ V_939 ] )
V_129 . V_934 =
F_34 ( V_30 -> V_5 [ V_939 ] ) ;
if ( V_30 -> V_5 [ V_940 ] ) {
V_129 . V_941 =
F_23 ( V_30 -> V_5 [ V_940 ] ) ;
V_129 . V_942 =
F_24 ( V_30 -> V_5 [ V_940 ] ) ;
}
if ( V_30 -> V_5 [ V_943 ] )
V_129 . V_935 = ! ! F_34 ( V_30 -> V_5 [ V_943 ] ) ;
if ( V_30 -> V_5 [ V_944 ] )
V_129 . V_936 =
F_78 ( V_30 -> V_5 [ V_944 ] ) ;
if ( V_30 -> V_5 [ V_680 ] ) {
if ( V_185 -> V_28 -> V_133 != V_136 )
return - V_16 ;
V_129 . V_681 =
F_190 ( V_30 -> V_5 [ V_680 ] ) ;
if ( V_129 . V_681 < 0 )
return - V_16 ;
if ( V_129 . V_681 != 0 &&
! ( V_7 -> V_18 . V_273 & V_682 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_683 ] ) {
T_2 V_24 ;
if ( V_185 -> V_28 -> V_133 != V_136 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_683 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_129 . V_684 = V_24 ;
if ( V_129 . V_684 &&
! ( V_7 -> V_18 . V_273 & V_685 ) )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_358 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_134 &&
V_185 -> V_28 -> V_133 != V_136 )
return - V_505 ;
F_111 ( V_17 ) ;
V_35 = F_191 ( V_7 , V_185 , & V_129 ) ;
F_113 ( V_17 ) ;
return V_35 ;
}
static int F_192 ( struct V_4 * V_87 [] ,
struct V_945 * V_946 )
{
struct V_947 * V_948 = & V_946 -> V_948 ;
struct V_949 * V_950 = & V_946 -> V_950 ;
if ( ! V_87 [ V_951 ] )
return - V_16 ;
if ( ! V_87 [ V_952 ] )
return - V_16 ;
if ( ! V_87 [ V_953 ] )
return - V_16 ;
if ( ! V_87 [ V_954 ] )
return - V_16 ;
if ( ! V_87 [ V_955 ] )
return - V_16 ;
V_946 -> V_51 = F_4 ( V_87 [ V_951 ] ) ;
V_948 -> V_956 =
F_4 ( V_87 [ V_952 ] ) ;
V_948 -> V_957 =
F_4 ( V_87 [ V_953 ] ) ;
V_948 -> V_958 =
F_4 ( V_87 [ V_954 ] ) ;
V_950 -> V_959 =
F_4 ( V_87 [ V_955 ] ) ;
if ( V_87 [ V_960 ] )
V_950 -> V_961 =
F_4 ( V_87 [ V_960 ] ) ;
if ( V_87 [ V_962 ] )
V_946 -> V_72 =
F_4 ( V_87 [ V_962 ] ) ;
return 0 ;
}
static int F_193 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
int V_963 ;
char * V_130 = NULL ;
enum V_964 V_965 ;
if ( F_194 ( ! F_195 ( V_966 ) ) )
return - V_967 ;
if ( ! V_30 -> V_5 [ V_968 ] )
return - V_16 ;
V_130 = F_23 ( V_30 -> V_5 [ V_968 ] ) ;
if ( V_30 -> V_5 [ V_969 ] )
V_965 =
F_4 ( V_30 -> V_5 [ V_969 ] ) ;
else
V_965 = V_970 ;
switch ( V_965 ) {
case V_970 :
case V_971 :
break;
default:
return - V_16 ;
}
V_963 = F_196 ( V_130 , V_965 ) ;
return V_963 ;
}
static int F_197 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_972 V_973 ;
int V_35 = 0 ;
void * V_265 ;
struct V_4 * V_903 ;
struct V_31 * V_53 ;
if ( V_17 -> V_133 != V_137 )
return - V_505 ;
if ( ! V_7 -> V_326 -> V_974 )
return - V_505 ;
F_111 ( V_17 ) ;
if ( ! V_17 -> V_975 )
memcpy ( & V_973 , & V_976 , sizeof( V_973 ) ) ;
else
V_35 = F_198 ( V_7 , V_185 , & V_973 ) ;
F_113 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_977 ) ;
if ( ! V_265 )
goto V_556;
V_903 = F_47 ( V_53 , V_978 ) ;
if ( ! V_903 )
goto V_59;
if ( F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_55 ( V_53 , V_979 ,
V_973 . V_980 ) ||
F_55 ( V_53 , V_981 ,
V_973 . V_982 ) ||
F_55 ( V_53 , V_983 ,
V_973 . V_984 ) ||
F_55 ( V_53 , V_985 ,
V_973 . V_986 ) ||
F_56 ( V_53 , V_987 ,
V_973 . V_988 ) ||
F_56 ( V_53 , V_989 ,
V_973 . V_990 ) ||
F_56 ( V_53 , V_991 ,
V_973 . V_992 ) ||
F_56 ( V_53 , V_993 ,
V_973 . V_994 ) ||
F_28 ( V_53 , V_995 ,
V_973 . V_996 ) ||
F_56 ( V_53 , V_997 ,
V_973 . V_998 ) ||
F_28 ( V_53 , V_999 ,
V_973 . V_1000 ) ||
F_55 ( V_53 , V_1001 ,
V_973 . V_1002 ) ||
F_28 ( V_53 , V_1003 ,
V_973 . V_1004 ) ||
F_55 ( V_53 , V_1005 ,
V_973 . V_1006 ) ||
F_55 ( V_53 , V_1007 ,
V_973 . V_1008 ) ||
F_55 ( V_53 , V_1009 ,
V_973 . V_1010 ) ||
F_56 ( V_53 , V_1011 ,
V_973 . V_1012 ) ||
F_55 ( V_53 , V_1013 ,
V_973 . V_1014 ) ||
F_56 ( V_53 , V_1015 ,
V_973 . V_1016 ) ||
F_56 ( V_53 , V_1017 ,
V_973 . V_1018 ) ||
F_28 ( V_53 , V_1019 ,
V_973 . V_1020 ) ||
F_28 ( V_53 , V_1021 ,
V_973 . V_936 ) ||
F_28 ( V_53 , V_1022 ,
V_973 . V_1023 ) ||
F_55 ( V_53 , V_1024 ,
V_973 . V_1025 ) ||
F_55 ( V_53 , V_1026 ,
V_973 . V_1027 ) ||
F_28 ( V_53 , V_1028 ,
V_973 . V_1029 ) ||
F_55 ( V_53 , V_1030 ,
V_973 . V_1031 ) ||
F_28 ( V_53 , V_1032 ,
V_973 . V_1033 ) )
goto V_59;
F_48 ( V_53 , V_903 ) ;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
V_556:
F_75 ( V_53 ) ;
return - V_83 ;
}
static int F_199 ( struct V_29 * V_30 ,
struct V_972 * V_1034 ,
V_22 * V_1035 )
{
struct V_4 * V_87 [ V_1036 + 1 ] ;
V_22 V_695 = 0 ;
#define F_200 ( V_87 , V_1034 , T_7 , T_8 , V_160 , V_695 , V_45 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_978 ] )
return - V_16 ;
if ( F_33 ( V_87 , V_1036 ,
V_30 -> V_5 [ V_978 ] ,
V_1037 ) )
return - V_16 ;
F_112 ( V_1036 > 32 ) ;
F_200 ( V_87 , V_1034 , V_980 , 1 , 255 ,
V_695 , V_979 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_982 , 1 , 255 ,
V_695 , V_981 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_984 , 1 , 255 ,
V_695 , V_983 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_986 , 0 , 255 ,
V_695 , V_985 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_988 , 0 , 16 ,
V_695 , V_987 ,
F_34 ) ;
F_200 ( V_87 , V_1034 , V_990 , 1 , 255 ,
V_695 , V_989 , F_34 ) ;
F_200 ( V_87 , V_1034 , V_992 , 1 , 255 ,
V_695 , V_991 ,
F_34 ) ;
F_200 ( V_87 , V_1034 , V_994 , 0 , 1 ,
V_695 , V_993 ,
F_34 ) ;
F_200 ( V_87 , V_1034 , V_996 ,
1 , 255 , V_695 ,
V_995 ,
F_4 ) ;
F_200 ( V_87 , V_1034 , V_998 , 0 , 255 ,
V_695 , V_997 ,
F_34 ) ;
F_200 ( V_87 , V_1034 , V_1000 , 1 , 65535 ,
V_695 , V_999 ,
F_4 ) ;
F_200 ( V_87 , V_1034 , V_1002 , 1 , 65535 ,
V_695 , V_1001 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_1004 ,
1 , 65535 , V_695 ,
V_1003 ,
F_4 ) ;
F_200 ( V_87 , V_1034 , V_1006 ,
1 , 65535 , V_695 ,
V_1005 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_1008 ,
1 , 65535 , V_695 ,
V_1007 ,
F_78 ) ;
F_200 ( V_87 , V_1034 ,
V_1010 ,
1 , 65535 , V_695 ,
V_1009 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_1012 , 0 , 4 ,
V_695 , V_1011 ,
F_34 ) ;
F_200 ( V_87 , V_1034 , V_1014 , 1 , 65535 ,
V_695 , V_1013 ,
F_78 ) ;
F_200 ( V_87 , V_1034 ,
V_1016 , 0 , 1 ,
V_695 , V_1015 ,
F_34 ) ;
F_200 ( V_87 , V_1034 , V_1018 , 0 , 1 ,
V_695 , V_1017 ,
F_34 ) ;
F_200 ( V_87 , V_1034 , V_1020 , - 255 , 0 ,
V_695 , V_1019 ,
V_1038 ) ;
F_200 ( V_87 , V_1034 , V_936 , 0 , 16 ,
V_695 , V_1021 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_1023 ,
1 , 65535 , V_695 ,
V_1022 ,
F_4 ) ;
F_200 ( V_87 , V_1034 , V_1025 , 1 , 65535 ,
V_695 , V_1024 ,
F_78 ) ;
F_200 ( V_87 , V_1034 ,
V_1027 ,
1 , 65535 , V_695 ,
V_1026 ,
F_78 ) ;
F_200 ( V_87 , V_1034 , V_1029 ,
V_1039 ,
V_892 ,
V_695 , V_1028 ,
F_4 ) ;
F_200 ( V_87 , V_1034 , V_1031 ,
0 , 65535 , V_695 ,
V_1030 , F_78 ) ;
F_200 ( V_87 , V_1034 , V_1033 , 1 , 0xffffffff ,
V_695 , V_1032 ,
F_4 ) ;
if ( V_1035 )
* V_1035 = V_695 ;
return 0 ;
#undef F_200
}
static int F_201 ( struct V_29 * V_30 ,
struct V_1040 * V_1041 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_4 * V_87 [ V_1042 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1043 ] )
return - V_16 ;
if ( F_33 ( V_87 , V_1042 ,
V_30 -> V_5 [ V_1043 ] ,
V_1044 ) )
return - V_16 ;
if ( V_87 [ V_1045 ] )
V_1041 -> V_1046 =
( F_34 ( V_87 [ V_1045 ] ) ) ?
V_1047 :
V_1048 ;
if ( V_87 [ V_1049 ] )
V_1041 -> V_1050 =
( F_34 ( V_87 [ V_1049 ] ) ) ?
V_1051 :
V_1052 ;
if ( V_87 [ V_1053 ] )
V_1041 -> V_1054 =
( F_34 ( V_87 [ V_1053 ] ) ) ?
V_1055 :
V_1056 ;
if ( V_87 [ V_1057 ] ) {
struct V_4 * V_1058 =
V_87 [ V_1057 ] ;
if ( ! F_22 ( V_1058 ) )
return - V_16 ;
V_1041 -> V_1059 = F_23 ( V_1058 ) ;
V_1041 -> V_1060 = F_24 ( V_1058 ) ;
}
if ( V_87 [ V_1061 ] &&
! ( V_7 -> V_18 . V_273 & V_1062 ) )
return - V_16 ;
V_1041 -> V_1063 = F_202 ( V_87 [ V_1061 ] ) ;
V_1041 -> V_1064 = F_202 ( V_87 [ V_1065 ] ) ;
V_1041 -> V_1066 = F_202 ( V_87 [ V_1067 ] ) ;
if ( V_1041 -> V_1066 )
V_1041 -> V_1063 = true ;
if ( V_87 [ V_1068 ] ) {
if ( ! V_1041 -> V_1063 )
return - V_16 ;
V_1041 -> V_1069 =
F_34 ( V_87 [ V_1068 ] ) ;
}
return 0 ;
}
static int F_203 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_972 V_1034 ;
V_22 V_695 ;
int V_35 ;
if ( V_17 -> V_133 != V_137 )
return - V_505 ;
if ( ! V_7 -> V_326 -> V_356 )
return - V_505 ;
V_35 = F_199 ( V_30 , & V_1034 , & V_695 ) ;
if ( V_35 )
return V_35 ;
F_111 ( V_17 ) ;
if ( ! V_17 -> V_975 )
V_35 = - V_142 ;
if ( ! V_35 )
V_35 = F_204 ( V_7 , V_185 , V_695 , & V_1034 ) ;
F_113 ( V_17 ) ;
return V_35 ;
}
static int F_205 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1070 * V_1071 ;
struct V_31 * V_53 ;
void * V_265 = NULL ;
struct V_4 * V_1072 ;
unsigned int V_145 ;
if ( ! V_966 )
return - V_16 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_83 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1073 ) ;
if ( ! V_265 )
goto V_1074;
if ( F_206 () &&
F_28 ( V_53 , V_969 ,
V_971 ) )
goto V_59;
F_207 () ;
V_1071 = F_208 ( V_966 ) ;
if ( F_60 ( V_53 , V_968 , V_1071 -> V_1075 ) ||
( V_1071 -> V_1076 &&
F_56 ( V_53 , V_1077 , V_1071 -> V_1076 ) ) )
goto V_1078;
V_1072 = F_47 ( V_53 , V_1079 ) ;
if ( ! V_1072 )
goto V_1078;
for ( V_145 = 0 ; V_145 < V_1071 -> V_1080 ; V_145 ++ ) {
struct V_4 * V_1081 ;
const struct V_945 * V_946 ;
const struct V_947 * V_948 ;
const struct V_949 * V_950 ;
unsigned int V_958 ;
V_946 = & V_1071 -> V_1082 [ V_145 ] ;
V_948 = & V_946 -> V_948 ;
V_950 = & V_946 -> V_950 ;
V_1081 = F_47 ( V_53 , V_145 ) ;
if ( ! V_1081 )
goto V_1078;
V_958 = V_948 -> V_958 ;
if ( ! V_958 )
V_958 = F_209 ( V_1071 ,
V_946 ) ;
if ( F_28 ( V_53 , V_951 ,
V_946 -> V_51 ) ||
F_28 ( V_53 , V_952 ,
V_948 -> V_956 ) ||
F_28 ( V_53 , V_953 ,
V_948 -> V_957 ) ||
F_28 ( V_53 , V_954 ,
V_958 ) ||
F_28 ( V_53 , V_960 ,
V_950 -> V_961 ) ||
F_28 ( V_53 , V_955 ,
V_950 -> V_959 ) ||
F_28 ( V_53 , V_962 ,
V_946 -> V_72 ) )
goto V_1078;
F_48 ( V_53 , V_1081 ) ;
}
F_210 () ;
F_48 ( V_53 , V_1072 ) ;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1078:
F_210 () ;
V_59:
F_67 ( V_53 , V_265 ) ;
V_1074:
F_75 ( V_53 ) ;
return - V_460 ;
}
static int F_211 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_87 [ V_1083 + 1 ] ;
struct V_4 * V_1081 ;
char * V_1075 = NULL ;
int V_1084 = 0 , V_963 = 0 ;
V_22 V_1085 = 0 , V_1086 = 0 , V_1087 ;
enum V_1088 V_1076 = V_1089 ;
struct V_1070 * V_1090 = NULL ;
if ( ! V_30 -> V_5 [ V_968 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1079 ] )
return - V_16 ;
V_1075 = F_23 ( V_30 -> V_5 [ V_968 ] ) ;
if ( V_30 -> V_5 [ V_1077 ] )
V_1076 = F_34 ( V_30 -> V_5 [ V_1077 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1085 ++ ;
if ( V_1085 > V_1091 )
return - V_16 ;
}
if ( ! F_212 ( V_1075 ) )
return - V_16 ;
V_1087 = sizeof( struct V_1070 ) +
V_1085 * sizeof( struct V_945 ) ;
V_1090 = F_38 ( V_1087 , V_127 ) ;
if ( ! V_1090 )
return - V_128 ;
V_1090 -> V_1080 = V_1085 ;
V_1090 -> V_1075 [ 0 ] = V_1075 [ 0 ] ;
V_1090 -> V_1075 [ 1 ] = V_1075 [ 1 ] ;
if ( F_213 ( V_1076 ) )
V_1090 -> V_1076 = V_1076 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_963 = F_95 ( V_87 , V_1083 ,
F_23 ( V_1081 ) , F_24 ( V_1081 ) ,
V_1092 ) ;
if ( V_963 )
goto V_1093;
V_963 = F_192 ( V_87 , & V_1090 -> V_1082 [ V_1086 ] ) ;
if ( V_963 )
goto V_1093;
V_1086 ++ ;
if ( V_1086 > V_1091 ) {
V_963 = - V_16 ;
goto V_1093;
}
}
V_963 = F_214 ( V_1090 ) ;
V_1090 = NULL ;
V_1093:
F_41 ( V_1090 ) ;
return V_963 ;
}
static int F_215 ( struct V_4 * V_1094 )
{
struct V_4 * V_1095 , * V_1096 ;
int V_341 = 0 , V_1097 , V_1098 ;
F_39 (attr1, freqs, tmp1) {
V_341 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1095 != V_1096 &&
F_4 ( V_1095 ) == F_4 ( V_1096 ) )
return 0 ;
}
return V_341 ;
}
static int F_216 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
struct V_1099 * V_1100 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1101 = 0 , V_341 , V_145 ;
T_10 V_1060 ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_326 -> V_1102 )
return - V_505 ;
if ( V_7 -> V_1103 || V_7 -> V_1104 ) {
V_35 = - V_507 ;
goto V_1105;
}
if ( V_30 -> V_5 [ V_1106 ] ) {
V_341 = F_215 (
V_30 -> V_5 [ V_1106 ] ) ;
if ( ! V_341 ) {
V_35 = - V_16 ;
goto V_1105;
}
} else {
V_341 = F_217 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1107 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1101 ++ ;
if ( V_1101 > V_18 -> V_290 ) {
V_35 = - V_16 ;
goto V_1105;
}
if ( V_30 -> V_5 [ V_634 ] )
V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
else
V_1060 = 0 ;
if ( V_1060 > V_18 -> V_294 ) {
V_35 = - V_16 ;
goto V_1105;
}
V_1100 = F_38 ( sizeof( * V_1100 )
+ sizeof( * V_1100 -> V_1108 ) * V_1101
+ sizeof( * V_1100 -> V_342 ) * V_341
+ V_1060 , V_127 ) ;
if ( ! V_1100 ) {
V_35 = - V_128 ;
goto V_1105;
}
if ( V_1101 )
V_1100 -> V_1108 = ( void * ) & V_1100 -> V_342 [ V_341 ] ;
V_1100 -> V_1101 = V_1101 ;
if ( V_1060 ) {
if ( V_1100 -> V_1108 )
V_1100 -> V_1059 = ( void * ) ( V_1100 -> V_1108 + V_1101 ) ;
else
V_1100 -> V_1059 = ( void * ) ( V_1100 -> V_342 + V_341 ) ;
}
V_145 = 0 ;
if ( V_30 -> V_5 [ V_1106 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1109;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1100 -> V_342 [ V_145 ] = V_55 ;
V_145 ++ ;
}
} else {
enum V_271 V_272 ;
for ( V_272 = 0 ; V_272 < V_337 ; V_272 ++ ) {
int V_147 ;
if ( ! V_18 -> V_338 [ V_272 ] )
continue;
for ( V_147 = 0 ; V_147 < V_18 -> V_338 [ V_272 ] -> V_341 ; V_147 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_338 [ V_272 ] -> V_342 [ V_147 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1100 -> V_342 [ V_145 ] = V_55 ;
V_145 ++ ;
}
}
}
if ( ! V_145 ) {
V_35 = - V_16 ;
goto V_1109;
}
V_1100 -> V_341 = V_145 ;
V_145 = 0 ;
if ( V_30 -> V_5 [ V_1107 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_575 ) {
V_35 = - V_16 ;
goto V_1109;
}
V_1100 -> V_1108 [ V_145 ] . V_549 = F_24 ( V_45 ) ;
memcpy ( V_1100 -> V_1108 [ V_145 ] . V_551 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_145 ++ ;
}
}
if ( V_30 -> V_5 [ V_634 ] ) {
V_1100 -> V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
memcpy ( ( void * ) V_1100 -> V_1059 ,
F_23 ( V_30 -> V_5 [ V_634 ] ) ,
V_1100 -> V_1060 ) ;
}
for ( V_145 = 0 ; V_145 < V_337 ; V_145 ++ )
if ( V_18 -> V_338 [ V_145 ] )
V_1100 -> V_1110 [ V_145 ] =
( 1 << V_18 -> V_338 [ V_145 ] -> V_243 ) - 1 ;
if ( V_30 -> V_5 [ V_1111 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_271 V_272 = F_218 ( V_45 ) ;
if ( V_272 < 0 || V_272 >= V_337 ) {
V_35 = - V_16 ;
goto V_1109;
}
if ( ! V_18 -> V_338 [ V_272 ] )
continue;
V_35 = F_219 ( V_18 -> V_338 [ V_272 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1100 -> V_1110 [ V_272 ] ) ;
if ( V_35 )
goto V_1109;
}
}
if ( V_30 -> V_5 [ V_1112 ] ) {
V_1100 -> V_51 = F_4 (
V_30 -> V_5 [ V_1112 ] ) ;
if ( ( V_1100 -> V_51 & V_1113 ) &&
! ( V_18 -> V_273 & V_1114 ) ) {
V_35 = - V_505 ;
goto V_1109;
}
}
V_1100 -> V_1115 =
F_202 ( V_30 -> V_5 [ V_1116 ] ) ;
V_1100 -> V_17 = V_17 ;
V_1100 -> V_18 = & V_7 -> V_18 ;
V_1100 -> V_1117 = V_1118 ;
V_7 -> V_1103 = V_1100 ;
V_35 = F_220 ( V_7 , V_1100 ) ;
if ( ! V_35 ) {
F_221 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_222 ( V_17 -> V_19 ) ;
} else {
V_1109:
V_7 -> V_1103 = NULL ;
F_41 ( V_1100 ) ;
}
V_1105:
return V_35 ;
}
static int F_223 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1119 * V_1100 ;
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1101 = 0 , V_1120 = 0 , V_341 , V_145 ;
V_22 V_1121 ;
enum V_271 V_272 ;
T_10 V_1060 ;
struct V_4 * V_87 [ V_1122 + 1 ] ;
T_11 V_1123 = V_1124 ;
if ( ! ( V_7 -> V_18 . V_51 & V_397 ) ||
! V_7 -> V_326 -> V_398 )
return - V_505 ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1125 ] )
return - V_16 ;
V_1121 = F_4 ( V_30 -> V_5 [ V_1125 ] ) ;
if ( V_1121 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_1106 ] ) {
V_341 = F_215 (
V_30 -> V_5 [ V_1106 ] ) ;
if ( ! V_341 )
return - V_16 ;
} else {
V_341 = F_217 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1107 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1101 ++ ;
if ( V_1101 > V_18 -> V_292 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1126 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1127 ;
V_35 = F_95 ( V_87 , V_1122 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1128 ) ;
if ( V_35 )
return V_35 ;
if ( V_87 [ V_1129 ] ) {
V_1120 ++ ;
continue;
}
V_1127 = V_87 [ V_1130 ] ;
if ( V_1127 )
V_1123 = V_1038 ( V_1127 ) ;
}
}
if ( ! V_1120 && V_1123 != V_1124 )
V_1120 = 1 ;
if ( V_1120 > V_18 -> V_298 )
return - V_16 ;
if ( V_30 -> V_5 [ V_634 ] )
V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
else
V_1060 = 0 ;
if ( V_1060 > V_18 -> V_296 )
return - V_16 ;
if ( V_7 -> V_1131 ) {
V_35 = - V_967 ;
goto V_556;
}
V_1100 = F_38 ( sizeof( * V_1100 )
+ sizeof( * V_1100 -> V_1108 ) * V_1101
+ sizeof( * V_1100 -> V_1132 ) * V_1120
+ sizeof( * V_1100 -> V_342 ) * V_341
+ V_1060 , V_127 ) ;
if ( ! V_1100 ) {
V_35 = - V_128 ;
goto V_556;
}
if ( V_1101 )
V_1100 -> V_1108 = ( void * ) & V_1100 -> V_342 [ V_341 ] ;
V_1100 -> V_1101 = V_1101 ;
if ( V_1060 ) {
if ( V_1100 -> V_1108 )
V_1100 -> V_1059 = ( void * ) ( V_1100 -> V_1108 + V_1101 ) ;
else
V_1100 -> V_1059 = ( void * ) ( V_1100 -> V_342 + V_341 ) ;
}
if ( V_1120 ) {
if ( V_1100 -> V_1059 )
V_1100 -> V_1132 = ( void * ) ( V_1100 -> V_1059 + V_1060 ) ;
else if ( V_1100 -> V_1108 )
V_1100 -> V_1132 =
( void * ) ( V_1100 -> V_1108 + V_1101 ) ;
else
V_1100 -> V_1132 =
( void * ) ( V_1100 -> V_342 + V_341 ) ;
}
V_1100 -> V_1120 = V_1120 ;
V_145 = 0 ;
if ( V_30 -> V_5 [ V_1106 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1109;
}
if ( V_55 -> V_51 & V_60 )
continue;
V_1100 -> V_342 [ V_145 ] = V_55 ;
V_145 ++ ;
}
} else {
for ( V_272 = 0 ; V_272 < V_337 ; V_272 ++ ) {
int V_147 ;
if ( ! V_18 -> V_338 [ V_272 ] )
continue;
for ( V_147 = 0 ; V_147 < V_18 -> V_338 [ V_272 ] -> V_341 ; V_147 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_338 [ V_272 ] -> V_342 [ V_147 ] ;
if ( V_55 -> V_51 & V_60 )
continue;
V_1100 -> V_342 [ V_145 ] = V_55 ;
V_145 ++ ;
}
}
}
if ( ! V_145 ) {
V_35 = - V_16 ;
goto V_1109;
}
V_1100 -> V_341 = V_145 ;
V_145 = 0 ;
if ( V_30 -> V_5 [ V_1107 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_575 ) {
V_35 = - V_16 ;
goto V_1109;
}
V_1100 -> V_1108 [ V_145 ] . V_549 = F_24 ( V_45 ) ;
memcpy ( V_1100 -> V_1108 [ V_145 ] . V_551 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_145 ++ ;
}
}
V_145 = 0 ;
if ( V_30 -> V_5 [ V_1126 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_551 , * V_1127 ;
V_35 = F_95 ( V_87 , V_1122 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1128 ) ;
if ( V_35 )
goto V_1109;
V_551 = V_87 [ V_1129 ] ;
if ( V_551 ) {
if ( F_59 ( V_145 >= V_1120 ) ) {
V_35 = - V_16 ;
goto V_1109;
}
if ( F_24 ( V_551 ) > V_575 ) {
V_35 = - V_16 ;
goto V_1109;
}
memcpy ( V_1100 -> V_1132 [ V_145 ] . V_551 . V_551 ,
F_23 ( V_551 ) , F_24 ( V_551 ) ) ;
V_1100 -> V_1132 [ V_145 ] . V_551 . V_549 =
F_24 ( V_551 ) ;
V_1100 -> V_1132 [ V_145 ] . V_1133 =
V_1123 ;
V_1127 = V_87 [ V_1130 ] ;
if ( V_1127 )
V_1100 -> V_1132 [ V_145 ] . V_1133 =
V_1038 ( V_1127 ) ;
}
V_145 ++ ;
}
if ( V_145 == 0 )
V_1100 -> V_1132 [ 0 ] . V_1133 = V_1123 ;
V_1100 -> V_1134 = V_1135 ;
for ( V_145 = 0 ; V_145 < V_1120 ; V_145 ++ )
V_1100 -> V_1134 =
T_8 ( V_1100 -> V_1132 [ V_145 ] . V_1133 ,
V_1100 -> V_1134 ) ;
} else {
V_1100 -> V_1134 = V_1124 ;
}
if ( V_1060 ) {
V_1100 -> V_1060 = V_1060 ;
memcpy ( ( void * ) V_1100 -> V_1059 ,
F_23 ( V_30 -> V_5 [ V_634 ] ) ,
V_1100 -> V_1060 ) ;
}
if ( V_30 -> V_5 [ V_1112 ] ) {
V_1100 -> V_51 = F_4 (
V_30 -> V_5 [ V_1112 ] ) ;
if ( ( V_1100 -> V_51 & V_1113 ) &&
! ( V_18 -> V_273 & V_1114 ) ) {
V_35 = - V_505 ;
goto V_1109;
}
}
V_1100 -> V_185 = V_185 ;
V_1100 -> V_18 = & V_7 -> V_18 ;
V_1100 -> V_1121 = V_1121 ;
V_1100 -> V_1117 = V_1118 ;
V_35 = F_224 ( V_7 , V_185 , V_1100 ) ;
if ( ! V_35 ) {
V_7 -> V_1131 = V_1100 ;
F_225 ( V_7 , V_185 ,
V_1136 ) ;
goto V_556;
}
V_1109:
F_41 ( V_1100 ) ;
V_556:
return V_35 ;
}
static int F_226 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_397 ) ||
! V_7 -> V_326 -> V_1137 )
return - V_505 ;
return F_227 ( V_7 , false ) ;
}
static int F_228 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_485 V_486 ;
enum V_1088 V_1076 ;
unsigned int V_1138 ;
int V_35 ;
V_1076 = F_229 ( V_17 -> V_18 ) ;
if ( V_1076 == V_1089 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_486 ) ;
if ( V_35 )
return V_35 ;
if ( F_230 ( V_185 ) )
return - V_507 ;
if ( V_17 -> V_1139 )
return - V_507 ;
V_35 = F_148 ( V_17 -> V_18 , & V_486 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_231 ( V_17 -> V_18 , & V_486 ) )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1140 )
return - V_505 ;
V_35 = F_150 ( V_7 , V_17 , V_17 -> V_133 ,
V_486 . V_55 , V_687 ,
F_149 ( V_486 . V_489 ) ) ;
if ( V_35 )
return V_35 ;
V_1138 = F_232 ( & V_7 -> V_18 , & V_486 ) ;
if ( F_59 ( ! V_1138 ) )
V_1138 = V_1141 ;
V_35 = V_7 -> V_326 -> V_1140 ( & V_7 -> V_18 , V_185 , & V_486 ,
V_1138 ) ;
if ( ! V_35 ) {
V_17 -> V_486 = V_486 ;
V_17 -> V_1139 = true ;
V_17 -> V_1142 = V_1118 ;
V_17 -> V_1138 = V_1138 ;
}
return V_35 ;
}
static int F_233 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_1143 V_129 ;
static struct V_4 * V_1144 [ V_1145 + 1 ] ;
T_2 V_660 = 0 ;
int V_35 ;
bool V_1146 = false ;
if ( ! V_7 -> V_326 -> V_415 ||
! ( V_7 -> V_18 . V_51 & V_414 ) )
return - V_505 ;
switch ( V_185 -> V_28 -> V_133 ) {
case V_134 :
case V_136 :
V_1146 = true ;
if ( ! V_17 -> V_506 )
return - V_1147 ;
break;
case V_138 :
if ( ! V_17 -> V_549 )
return - V_1147 ;
break;
case V_137 :
if ( ! V_17 -> V_975 )
return - V_1147 ;
break;
default:
return - V_505 ;
}
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
if ( ! V_30 -> V_5 [ V_488 ] ||
! V_30 -> V_5 [ V_1148 ] )
return - V_16 ;
if ( V_1146 && ! V_30 -> V_5 [ V_1149 ] )
return - V_16 ;
V_129 . V_1150 = F_4 ( V_30 -> V_5 [ V_1148 ] ) ;
if ( ! V_1146 )
goto V_1151;
V_35 = F_142 ( V_30 -> V_5 , & V_129 . V_1152 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1144 , V_1145 ,
V_30 -> V_5 [ V_1149 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_142 ( V_1144 , & V_129 . V_1153 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1144 [ V_1154 ] )
return - V_16 ;
V_129 . V_1155 =
F_78 ( V_1144 [ V_1154 ] ) ;
if ( V_129 . V_1155 >= V_129 . V_1153 . V_641 )
return - V_16 ;
if ( V_129 . V_1153 . V_640 [ V_129 . V_1155 ] !=
V_129 . V_1150 )
return - V_16 ;
if ( V_1144 [ V_1156 ] ) {
V_129 . V_1157 =
F_78 ( V_1144 [ V_1156 ] ) ;
if ( V_129 . V_1157 >=
V_129 . V_1153 . V_650 )
return - V_16 ;
if ( V_129 . V_1153 . V_649 [ V_129 . V_1157 ] !=
V_129 . V_1150 )
return - V_16 ;
}
V_1151:
V_35 = F_80 ( V_7 , V_30 , & V_129 . V_486 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_129 . V_486 ) )
return - V_16 ;
switch ( V_185 -> V_28 -> V_133 ) {
case V_134 :
case V_136 :
case V_138 :
case V_137 :
V_35 = F_148 ( V_17 -> V_18 ,
& V_129 . V_486 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 ) {
V_660 = F_149 ( V_129 . V_486 . V_489 ) ;
V_129 . V_686 = true ;
}
break;
default:
break;
}
V_35 = F_150 ( V_7 , V_17 , V_17 -> V_133 ,
V_129 . V_486 . V_55 ,
V_687 ,
V_660 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_1158 ] )
V_129 . V_1159 = true ;
F_111 ( V_17 ) ;
V_35 = F_234 ( V_7 , V_185 , & V_129 ) ;
F_113 ( V_17 ) ;
return V_35 ;
}
static int F_235 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1160 * V_1161 )
{
struct V_1162 * V_330 = & V_1161 -> V_1163 ;
const struct V_1164 * V_1165 ;
void * V_265 ;
struct V_4 * V_1166 ;
bool V_1167 = false ;
F_43 ( V_17 ) ;
V_265 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1168 ) ;
if ( ! V_265 )
return - 1 ;
F_236 ( V_34 , V_265 , & V_38 ) ;
if ( F_28 ( V_53 , V_276 , V_7 -> V_1169 ) )
goto V_59;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_59;
if ( F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
V_1166 = F_47 ( V_53 , V_1170 ) ;
if ( ! V_1166 )
goto V_59;
if ( ( ! F_237 ( V_330 -> V_509 ) &&
F_51 ( V_53 , V_1171 , V_546 , V_330 -> V_509 ) ) )
goto V_59;
F_207 () ;
V_1165 = F_208 ( V_330 -> V_1165 ) ;
if ( V_1165 ) {
if ( F_103 ( V_53 , V_1172 , V_1165 -> V_1167 ) )
goto V_1173;
V_1167 = true ;
if ( V_1165 -> V_47 && F_51 ( V_53 , V_1174 ,
V_1165 -> V_47 , V_1165 -> V_130 ) )
goto V_1173;
}
V_1165 = F_208 ( V_330 -> V_642 ) ;
if ( V_1165 ) {
if ( ! V_1167 && F_103 ( V_53 , V_1172 , V_1165 -> V_1167 ) )
goto V_1173;
if ( V_1165 -> V_47 && F_51 ( V_53 , V_1175 ,
V_1165 -> V_47 , V_1165 -> V_130 ) )
goto V_1173;
}
F_210 () ;
if ( V_330 -> V_506 &&
F_55 ( V_53 , V_1176 , V_330 -> V_506 ) )
goto V_59;
if ( F_55 ( V_53 , V_1177 , V_330 -> V_880 ) ||
F_28 ( V_53 , V_1178 , V_330 -> V_1179 -> V_58 ) ||
F_28 ( V_53 , V_1180 , V_330 -> V_1181 ) ||
F_28 ( V_53 , V_1182 ,
F_238 ( V_1118 - V_1161 -> V_1183 ) ) )
goto V_59;
switch ( V_7 -> V_18 . V_763 ) {
case V_764 :
if ( F_28 ( V_53 , V_1184 , V_330 -> signal ) )
goto V_59;
break;
case V_1185 :
if ( F_56 ( V_53 , V_1186 , V_330 -> signal ) )
goto V_59;
break;
default:
break;
}
switch ( V_17 -> V_133 ) {
case V_140 :
case V_139 :
if ( V_1161 == V_17 -> V_141 &&
F_28 ( V_53 , V_1187 ,
V_1188 ) )
goto V_59;
break;
case V_138 :
if ( V_1161 == V_17 -> V_141 &&
F_28 ( V_53 , V_1187 ,
V_1189 ) )
goto V_59;
break;
default:
break;
}
F_48 ( V_53 , V_1166 ) ;
return F_66 ( V_53 , V_265 ) ;
V_1173:
F_210 () ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
static int F_239 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1160 * V_1102 ;
struct V_1 * V_17 ;
int V_464 = V_34 -> args [ 2 ] , V_97 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_111 ( V_17 ) ;
F_240 ( & V_7 -> V_1190 ) ;
F_241 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1169 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_97 <= V_464 )
continue;
if ( F_235 ( V_32 , V_34 ,
V_34 -> V_36 -> V_465 , V_466 ,
V_7 , V_17 , V_1102 ) < 0 ) {
V_97 -- ;
break;
}
}
F_242 ( & V_7 -> V_1190 ) ;
F_113 ( V_17 ) ;
V_34 -> args [ 2 ] = V_97 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_243 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_185 ,
struct V_1191 * V_1192 )
{
void * V_265 ;
struct V_4 * V_1193 ;
V_265 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1194 ) ;
if ( ! V_265 )
return - V_128 ;
if ( F_28 ( V_53 , V_10 , V_185 -> V_20 ) )
goto V_59;
V_1193 = F_47 ( V_53 , V_1195 ) ;
if ( ! V_1193 )
goto V_59;
if ( F_28 ( V_53 , V_1196 ,
V_1192 -> V_1179 -> V_58 ) )
goto V_59;
if ( ( V_1192 -> V_737 & V_1197 ) &&
F_56 ( V_53 , V_1198 , V_1192 -> V_1199 ) )
goto V_59;
if ( ( V_1192 -> V_737 & V_1200 ) &&
F_29 ( V_53 , V_1201 ) )
goto V_59;
if ( ( V_1192 -> V_737 & V_1202 ) &&
F_103 ( V_53 , V_1203 ,
V_1192 -> V_1204 ) )
goto V_59;
if ( ( V_1192 -> V_737 & V_1205 ) &&
F_103 ( V_53 , V_1206 ,
V_1192 -> V_1207 ) )
goto V_59;
if ( ( V_1192 -> V_737 & V_1208 ) &&
F_103 ( V_53 , V_1209 ,
V_1192 -> V_1210 ) )
goto V_59;
if ( ( V_1192 -> V_737 & V_1211 ) &&
F_103 ( V_53 , V_1212 ,
V_1192 -> V_1213 ) )
goto V_59;
if ( ( V_1192 -> V_737 & V_1214 ) &&
F_103 ( V_53 , V_1215 ,
V_1192 -> V_1216 ) )
goto V_59;
F_48 ( V_53 , V_1193 ) ;
return F_66 ( V_53 , V_265 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
static int F_244 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1191 V_1192 ;
struct V_6 * V_185 ;
struct V_1 * V_17 ;
int V_1217 = V_34 -> args [ 2 ] ;
int V_330 ;
V_330 = F_13 ( V_32 , V_34 , & V_185 , & V_17 ) ;
if ( V_330 )
return V_330 ;
if ( ! V_17 -> V_19 ) {
V_330 = - V_16 ;
goto V_826;
}
if ( ! V_185 -> V_326 -> V_1218 ) {
V_330 = - V_505 ;
goto V_826;
}
while ( 1 ) {
struct V_54 * V_55 ;
V_330 = F_245 ( V_185 , V_17 -> V_19 , V_1217 , & V_1192 ) ;
if ( V_330 == - V_607 )
break;
if ( V_330 )
goto V_826;
if ( ! V_1192 . V_1179 ) {
V_330 = - V_16 ;
goto V_556;
}
V_55 = F_45 ( & V_185 -> V_18 ,
V_1192 . V_1179 -> V_58 ) ;
if ( ! V_55 || V_55 -> V_51 & V_60 ) {
V_1217 ++ ;
continue;
}
if ( F_243 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_465 , V_466 ,
V_17 -> V_19 , & V_1192 ) < 0 )
goto V_556;
V_1217 ++ ;
}
V_556:
V_34 -> args [ 2 ] = V_1217 ;
V_330 = V_32 -> V_47 ;
V_826:
F_21 ( V_185 ) ;
return V_330 ;
}
static bool F_246 ( V_22 V_1219 )
{
return ! ( V_1219 & ~ ( V_1220 |
V_1221 ) ) ;
}
static int F_247 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_509 , * V_551 , * V_1059 = NULL , * V_1222 = NULL ;
int V_35 , V_549 , V_1060 = 0 , V_1223 = 0 ;
enum V_652 V_653 ;
struct V_85 V_84 ;
bool V_1224 ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_673 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_550 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_488 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_84 ) ;
if ( V_35 )
return V_35 ;
if ( V_84 . V_97 >= 0 ) {
if ( V_84 . type != - 1 && V_84 . type != V_603 )
return - V_16 ;
if ( ! V_84 . V_99 . V_84 || ! V_84 . V_99 . V_100 )
return - V_16 ;
if ( ( V_84 . V_99 . V_104 != V_131 ||
V_84 . V_99 . V_100 != V_1225 ) &&
( V_84 . V_99 . V_104 != V_132 ||
V_84 . V_99 . V_100 != V_1226 ) )
return - V_16 ;
if ( V_84 . V_97 > 4 )
return - V_16 ;
} else {
V_84 . V_99 . V_100 = 0 ;
V_84 . V_99 . V_84 = NULL ;
}
if ( V_84 . V_97 >= 0 ) {
int V_145 ;
bool V_1227 = false ;
for ( V_145 = 0 ; V_145 < V_7 -> V_18 . V_313 ; V_145 ++ ) {
if ( V_84 . V_99 . V_104 == V_7 -> V_18 . V_314 [ V_145 ] ) {
V_1227 = true ;
break;
}
}
if ( ! V_1227 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_360 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_488 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_551 = F_23 ( V_30 -> V_5 [ V_550 ] ) ;
V_549 = F_24 ( V_30 -> V_5 [ V_550 ] ) ;
if ( V_30 -> V_5 [ V_634 ] ) {
V_1059 = F_23 ( V_30 -> V_5 [ V_634 ] ) ;
V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
}
V_653 = F_4 ( V_30 -> V_5 [ V_673 ] ) ;
if ( ! F_144 ( V_7 , V_653 , V_656 ) )
return - V_16 ;
if ( V_653 == V_658 &&
! V_30 -> V_5 [ V_1228 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1228 ] ) {
if ( V_653 != V_658 )
return - V_16 ;
V_1222 = F_23 ( V_30 -> V_5 [ V_1228 ] ) ;
V_1223 = F_24 ( V_30 -> V_5 [ V_1228 ] ) ;
if ( V_1223 < 4 )
return - V_16 ;
}
V_1224 = ! ! V_30 -> V_5 [ V_1229 ] ;
if ( V_1224 )
return 0 ;
F_111 ( V_185 -> V_28 ) ;
V_35 = F_248 ( V_7 , V_185 , V_55 , V_653 , V_509 ,
V_551 , V_549 , V_1059 , V_1060 ,
V_84 . V_99 . V_84 , V_84 . V_99 . V_100 , V_84 . V_97 ,
V_1222 , V_1223 ) ;
F_113 ( V_185 -> V_28 ) ;
return V_35 ;
}
static int F_147 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1230 * V_1231 ,
int V_1232 )
{
memset ( V_1231 , 0 , sizeof( * V_1231 ) ) ;
V_1231 -> V_1233 = V_30 -> V_5 [ V_1234 ] ;
if ( V_30 -> V_5 [ V_318 ] ) {
T_3 V_1235 ;
V_1235 = F_78 (
V_30 -> V_5 [ V_318 ] ) ;
V_1231 -> V_1236 = F_249 ( V_1235 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_317 ) &&
V_1235 != V_1237 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1238 ] )
V_1231 -> V_1239 = true ;
} else
V_1231 -> V_1236 = F_249 ( V_1237 ) ;
if ( V_30 -> V_5 [ V_1240 ] ) {
void * V_130 ;
int V_47 , V_145 ;
V_130 = F_23 ( V_30 -> V_5 [ V_1240 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1240 ] ) ;
V_1231 -> V_1241 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1231 -> V_1241 > V_1232 )
return - V_16 ;
memcpy ( V_1231 -> V_1242 , V_130 , V_47 ) ;
for ( V_145 = 0 ; V_145 < V_1231 -> V_1241 ; V_145 ++ )
if ( ! F_250 (
& V_7 -> V_18 ,
V_1231 -> V_1242 [ V_145 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1243 ] ) {
V_1231 -> V_1244 =
F_4 ( V_30 -> V_5 [ V_1243 ] ) ;
if ( ! F_250 ( & V_7 -> V_18 ,
V_1231 -> V_1244 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1245 ] ) {
V_1231 -> V_1219 =
F_4 ( V_30 -> V_5 [ V_1245 ] ) ;
if ( ! F_246 ( V_1231 -> V_1219 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1246 ] ) {
void * V_130 ;
int V_47 ;
V_130 = F_23 ( V_30 -> V_5 [ V_1246 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1246 ] ) ;
V_1231 -> V_1247 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1231 -> V_1247 > V_1248 )
return - V_16 ;
memcpy ( V_1231 -> V_1249 , V_130 , V_47 ) ;
}
return 0 ;
}
static int F_251 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1250 V_1251 = {} ;
const T_2 * V_509 , * V_551 ;
int V_35 , V_549 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_510 ] ||
! V_30 -> V_5 [ V_550 ] ||
! V_30 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_362 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_488 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_551 = F_23 ( V_30 -> V_5 [ V_550 ] ) ;
V_549 = F_24 ( V_30 -> V_5 [ V_550 ] ) ;
if ( V_30 -> V_5 [ V_634 ] ) {
V_1251 . V_1059 = F_23 ( V_30 -> V_5 [ V_634 ] ) ;
V_1251 . V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
}
if ( V_30 -> V_5 [ V_1252 ] ) {
enum V_1253 V_1254 =
F_4 ( V_30 -> V_5 [ V_1252 ] ) ;
if ( V_1254 == V_1255 )
V_1251 . V_1256 = true ;
else if ( V_1254 != V_1257 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1258 ] )
V_1251 . V_1259 = F_23 ( V_30 -> V_5 [ V_1258 ] ) ;
if ( F_202 ( V_30 -> V_5 [ V_1260 ] ) )
V_1251 . V_51 |= V_1261 ;
if ( V_30 -> V_5 [ V_437 ] )
memcpy ( & V_1251 . V_1262 ,
F_23 ( V_30 -> V_5 [ V_437 ] ) ,
sizeof( V_1251 . V_1262 ) ) ;
if ( V_30 -> V_5 [ V_873 ] ) {
if ( ! V_30 -> V_5 [ V_437 ] )
return - V_16 ;
memcpy ( & V_1251 . V_845 ,
F_23 ( V_30 -> V_5 [ V_873 ] ) ,
sizeof( V_1251 . V_845 ) ) ;
}
if ( F_202 ( V_30 -> V_5 [ V_1263 ] ) )
V_1251 . V_51 |= V_1264 ;
if ( V_30 -> V_5 [ V_446 ] )
memcpy ( & V_1251 . V_1265 ,
F_23 ( V_30 -> V_5 [ V_446 ] ) ,
sizeof( V_1251 . V_1265 ) ) ;
if ( V_30 -> V_5 [ V_874 ] ) {
if ( ! V_30 -> V_5 [ V_446 ] )
return - V_16 ;
memcpy ( & V_1251 . V_846 ,
F_23 ( V_30 -> V_5 [ V_874 ] ) ,
sizeof( V_1251 . V_846 ) ) ;
}
V_35 = F_147 ( V_7 , V_30 , & V_1251 . V_675 , 1 ) ;
if ( ! V_35 ) {
F_111 ( V_185 -> V_28 ) ;
V_35 = F_252 ( V_7 , V_185 , V_55 , V_509 ,
V_551 , V_549 , & V_1251 ) ;
F_113 ( V_185 -> V_28 ) ;
}
return V_35 ;
}
static int F_253 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
const T_2 * V_1059 = NULL , * V_509 ;
int V_1060 = 0 , V_35 ;
T_3 V_1266 ;
bool V_1224 ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1267 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_364 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_1266 = F_78 ( V_30 -> V_5 [ V_1267 ] ) ;
if ( V_1266 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_634 ] ) {
V_1059 = F_23 ( V_30 -> V_5 [ V_634 ] ) ;
V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
}
V_1224 = ! ! V_30 -> V_5 [ V_1229 ] ;
F_111 ( V_185 -> V_28 ) ;
V_35 = F_254 ( V_7 , V_185 , V_509 , V_1059 , V_1060 , V_1266 ,
V_1224 ) ;
F_113 ( V_185 -> V_28 ) ;
return V_35 ;
}
static int F_255 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
const T_2 * V_1059 = NULL , * V_509 ;
int V_1060 = 0 , V_35 ;
T_3 V_1266 ;
bool V_1224 ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1267 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_366 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_1266 = F_78 ( V_30 -> V_5 [ V_1267 ] ) ;
if ( V_1266 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_634 ] ) {
V_1059 = F_23 ( V_30 -> V_5 [ V_634 ] ) ;
V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
}
V_1224 = ! ! V_30 -> V_5 [ V_1229 ] ;
F_111 ( V_185 -> V_28 ) ;
V_35 = F_256 ( V_7 , V_185 , V_509 , V_1059 , V_1060 , V_1266 ,
V_1224 ) ;
F_113 ( V_185 -> V_28 ) ;
return V_35 ;
}
static bool
F_257 ( struct V_6 * V_7 ,
int V_1268 [ V_337 ] ,
int V_1269 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_272 , V_145 ;
for ( V_272 = 0 ; V_272 < V_337 ; V_272 ++ ) {
struct V_221 * V_222 ;
V_222 = V_18 -> V_338 [ V_272 ] ;
if ( ! V_222 )
continue;
for ( V_145 = 0 ; V_145 < V_222 -> V_243 ; V_145 ++ ) {
if ( V_222 -> V_244 [ V_145 ] . V_246 == V_1269 ) {
V_1268 [ V_272 ] = V_145 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_258 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1270 V_1271 ;
struct V_18 * V_18 ;
struct V_122 * V_1272 = NULL ;
int V_35 ;
memset ( & V_1271 , 0 , sizeof( V_1271 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_550 ] ||
! F_24 ( V_30 -> V_5 [ V_550 ] ) )
return - V_16 ;
V_1271 . V_506 = 100 ;
if ( V_30 -> V_5 [ V_662 ] ) {
V_1271 . V_506 =
F_4 ( V_30 -> V_5 [ V_662 ] ) ;
if ( V_1271 . V_506 < 1 || V_1271 . V_506 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_368 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_138 )
return - V_505 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_510 ] ) {
V_1271 . V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( ! F_117 ( V_1271 . V_509 ) )
return - V_16 ;
}
V_1271 . V_551 = F_23 ( V_30 -> V_5 [ V_550 ] ) ;
V_1271 . V_549 = F_24 ( V_30 -> V_5 [ V_550 ] ) ;
if ( V_30 -> V_5 [ V_634 ] ) {
V_1271 . V_1059 = F_23 ( V_30 -> V_5 [ V_634 ] ) ;
V_1271 . V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1271 . V_486 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_1271 . V_486 ) )
return - V_16 ;
switch ( V_1271 . V_486 . V_489 ) {
case V_503 :
case V_504 :
case V_490 :
break;
case V_540 :
case V_541 :
if ( V_7 -> V_18 . V_273 & V_1273 )
break;
default:
return - V_16 ;
}
V_1271 . V_1274 = ! ! V_30 -> V_5 [ V_1275 ] ;
V_1271 . V_671 = ! ! V_30 -> V_5 [ V_672 ] ;
if ( V_30 -> V_5 [ V_940 ] ) {
T_2 * V_1110 =
F_23 ( V_30 -> V_5 [ V_940 ] ) ;
int V_1276 =
F_24 ( V_30 -> V_5 [ V_940 ] ) ;
struct V_221 * V_222 =
V_18 -> V_338 [ V_1271 . V_486 . V_55 -> V_272 ] ;
V_35 = F_219 ( V_222 , V_1110 , V_1276 ,
& V_1271 . V_941 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_437 ] )
memcpy ( & V_1271 . V_1262 ,
F_23 ( V_30 -> V_5 [ V_437 ] ) ,
sizeof( V_1271 . V_1262 ) ) ;
if ( V_30 -> V_5 [ V_873 ] ) {
if ( ! V_30 -> V_5 [ V_437 ] )
return - V_16 ;
memcpy ( & V_1271 . V_845 ,
F_23 ( V_30 -> V_5 [ V_873 ] ) ,
sizeof( V_1271 . V_845 ) ) ;
}
if ( V_30 -> V_5 [ V_1277 ] &&
! F_257 ( V_7 , V_1271 . V_1268 ,
F_4 ( V_30 -> V_5 [ V_1277 ] ) ) )
return - V_16 ;
if ( V_1271 . V_671 && V_30 -> V_5 [ V_1278 ] ) {
bool V_124 = false ;
V_1272 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1278 ] ,
& V_124 ) ;
if ( F_17 ( V_1272 ) )
return F_18 ( V_1272 ) ;
if ( ( V_1271 . V_486 . V_489 != V_490 ) &&
V_124 ) {
F_41 ( V_1272 ) ;
return - V_16 ;
}
}
V_1271 . V_1233 =
F_202 ( V_30 -> V_5 [ V_1234 ] ) ;
V_1271 . V_1279 =
F_202 ( V_30 -> V_5 [ V_1280 ] ) ;
V_35 = F_259 ( V_7 , V_185 , & V_1271 , V_1272 ) ;
if ( V_35 )
F_41 ( V_1272 ) ;
return V_35 ;
}
static int F_260 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_1281 )
return - V_505 ;
if ( V_185 -> V_28 -> V_133 != V_138 )
return - V_505 ;
return F_261 ( V_7 , V_185 , false ) ;
}
static int F_262 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
int V_1268 [ V_337 ] ;
V_22 V_1282 ;
int V_35 ;
if ( V_185 -> V_28 -> V_133 != V_138 &&
V_185 -> V_28 -> V_133 != V_137 )
return - V_505 ;
if ( ! V_7 -> V_326 -> V_408 )
return - V_505 ;
memset ( V_1268 , 0 , sizeof( V_1268 ) ) ;
if ( ! V_30 -> V_5 [ V_1277 ] )
return - V_16 ;
V_1282 = F_4 ( V_30 -> V_5 [ V_1277 ] ) ;
if ( ! F_257 ( V_7 , V_1268 , V_1282 ) )
return - V_16 ;
V_35 = V_7 -> V_326 -> V_408 ( & V_7 -> V_18 , V_185 , V_1268 ) ;
return V_35 ;
}
static struct V_31 *
F_263 ( struct V_6 * V_7 ,
int V_1283 , V_22 V_49 , V_22 V_50 ,
enum V_654 V_52 ,
enum V_1284 V_45 ,
const struct V_453 * V_30 ,
T_12 V_1285 )
{
struct V_31 * V_32 ;
void * V_265 ;
struct V_4 * V_130 ;
V_32 = F_74 ( V_1283 + 100 , V_1285 ) ;
if ( ! V_32 )
return NULL ;
V_265 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_265 ) {
F_264 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1286 ,
V_30 -> V_1287 ) )
goto V_59;
if ( F_28 ( V_32 , V_1288 ,
V_30 -> V_1289 ) )
goto V_59;
}
V_130 = F_47 ( V_32 , V_45 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_265 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_130 ;
return V_32 ;
V_59:
F_264 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_265 ( struct V_18 * V_18 ,
enum V_654 V_52 ,
enum V_1284 V_45 ,
int V_1290 ,
int V_1283 , T_12 V_1285 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_453 * V_30 ;
switch ( V_52 ) {
case V_1291 :
if ( F_59 ( V_1290 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1292 :
if ( F_59 ( V_1290 < 0 ||
V_1290 >= V_18 -> V_457 ) )
return NULL ;
V_30 = & V_18 -> V_459 [ V_1290 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_263 ( V_7 , V_1283 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1285 ) ;
}
void F_266 ( struct V_31 * V_32 , T_12 V_1285 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_265 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_130 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1293 V_1294 = V_1295 ;
F_48 ( V_32 , V_130 ) ;
F_66 ( V_32 , V_265 ) ;
if ( V_130 -> F_218 == V_455 )
V_1294 = V_1296 ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1294 , V_1285 ) ;
}
static int F_268 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_93 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_326 -> V_419 )
return - V_505 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1297 ] )
return - V_16 ;
V_7 -> V_1298 = V_30 ;
V_35 = F_269 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1297 ] ) ,
F_24 ( V_30 -> V_5 [ V_1297 ] ) ) ;
V_7 -> V_1298 = NULL ;
return V_35 ;
}
static int F_270 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1299 ;
void * V_130 = NULL ;
int V_1300 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1299 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_826;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_826;
}
V_1299 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1297 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1297 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_130 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1300 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1299 ) ;
if ( ! V_7 ) {
V_35 = - V_607 ;
goto V_826;
}
if ( ! V_7 -> V_326 -> V_1301 ) {
V_35 = - V_505 ;
goto V_826;
}
while ( 1 ) {
void * V_265 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_465 , V_466 ,
V_1291 ) ;
struct V_4 * V_1302 ;
if ( ! V_265 )
break;
if ( F_28 ( V_32 , V_26 , V_1299 ) ) {
F_67 ( V_32 , V_265 ) ;
break;
}
V_1302 = F_47 ( V_32 , V_1297 ) ;
if ( ! V_1302 ) {
F_67 ( V_32 , V_265 ) ;
break;
}
V_35 = F_271 ( V_7 , V_32 , V_34 , V_130 , V_1300 ) ;
F_48 ( V_32 , V_1302 ) ;
if ( V_35 == - V_83 || V_35 == - V_607 ) {
F_67 ( V_32 , V_265 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_265 ) ;
goto V_826;
}
F_66 ( V_32 , V_265 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1299 + 1 ;
V_826:
F_20 () ;
return V_35 ;
}
static int F_272 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1303 V_421 ;
struct V_18 * V_18 ;
struct V_122 * V_1272 = NULL ;
int V_35 ;
memset ( & V_421 , 0 , sizeof( V_421 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_550 ] ||
! F_24 ( V_30 -> V_5 [ V_550 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_673 ] ) {
V_421 . V_653 =
F_4 ( V_30 -> V_5 [ V_673 ] ) ;
if ( ! F_144 ( V_7 , V_421 . V_653 ,
V_422 ) )
return - V_16 ;
} else
V_421 . V_653 = V_674 ;
V_421 . V_671 = V_30 -> V_5 [ V_672 ] ;
V_35 = F_147 ( V_7 , V_30 , & V_421 . V_675 ,
V_676 ) ;
if ( V_35 )
return V_35 ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
V_18 = & V_7 -> V_18 ;
V_421 . V_1304 = - 1 ;
if ( V_30 -> V_5 [ V_1305 ] &&
( V_18 -> V_51 & V_305 ) ) {
V_421 . V_1304 =
F_78 ( V_30 -> V_5 [ V_1305 ] ) ;
}
if ( V_30 -> V_5 [ V_510 ] )
V_421 . V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
else if ( V_30 -> V_5 [ V_1306 ] )
V_421 . V_1307 =
F_23 ( V_30 -> V_5 [ V_1306 ] ) ;
V_421 . V_551 = F_23 ( V_30 -> V_5 [ V_550 ] ) ;
V_421 . V_549 = F_24 ( V_30 -> V_5 [ V_550 ] ) ;
if ( V_30 -> V_5 [ V_634 ] ) {
V_421 . V_1059 = F_23 ( V_30 -> V_5 [ V_634 ] ) ;
V_421 . V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
}
if ( V_30 -> V_5 [ V_1252 ] ) {
V_421 . V_1254 = F_4 ( V_30 -> V_5 [ V_1252 ] ) ;
if ( V_421 . V_1254 != V_1255 &&
V_421 . V_1254 != V_1257 )
return - V_16 ;
} else {
V_421 . V_1254 = V_1257 ;
}
if ( V_30 -> V_5 [ V_488 ] ) {
V_421 . V_1179 = F_44 (
V_18 , V_30 -> V_5 [ V_488 ] ) ;
if ( ! V_421 . V_1179 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1308 ] ) {
V_421 . V_1309 = F_44 (
V_18 , V_30 -> V_5 [ V_1308 ] ) ;
if ( ! V_421 . V_1309 )
return - V_16 ;
}
if ( V_421 . V_671 && V_30 -> V_5 [ V_1278 ] ) {
V_1272 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1278 ] , NULL ) ;
if ( F_17 ( V_1272 ) )
return F_18 ( V_1272 ) ;
}
if ( F_202 ( V_30 -> V_5 [ V_1260 ] ) )
V_421 . V_51 |= V_1261 ;
if ( V_30 -> V_5 [ V_437 ] )
memcpy ( & V_421 . V_1262 ,
F_23 ( V_30 -> V_5 [ V_437 ] ) ,
sizeof( V_421 . V_1262 ) ) ;
if ( V_30 -> V_5 [ V_873 ] ) {
if ( ! V_30 -> V_5 [ V_437 ] ) {
F_41 ( V_1272 ) ;
return - V_16 ;
}
memcpy ( & V_421 . V_845 ,
F_23 ( V_30 -> V_5 [ V_873 ] ) ,
sizeof( V_421 . V_845 ) ) ;
}
if ( F_202 ( V_30 -> V_5 [ V_1263 ] ) )
V_421 . V_51 |= V_1264 ;
if ( V_30 -> V_5 [ V_446 ] )
memcpy ( & V_421 . V_1265 ,
F_23 ( V_30 -> V_5 [ V_446 ] ) ,
sizeof( V_421 . V_1265 ) ) ;
if ( V_30 -> V_5 [ V_874 ] ) {
if ( ! V_30 -> V_5 [ V_446 ] ) {
F_41 ( V_1272 ) ;
return - V_16 ;
}
memcpy ( & V_421 . V_846 ,
F_23 ( V_30 -> V_5 [ V_874 ] ) ,
sizeof( V_421 . V_846 ) ) ;
}
F_111 ( V_185 -> V_28 ) ;
V_35 = F_273 ( V_7 , V_185 , & V_421 , V_1272 , NULL ) ;
F_113 ( V_185 -> V_28 ) ;
if ( V_35 )
F_41 ( V_1272 ) ;
return V_35 ;
}
static int F_274 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_3 V_1310 ;
int V_461 ;
if ( ! V_30 -> V_5 [ V_1267 ] )
V_1310 = V_1311 ;
else
V_1310 = F_78 ( V_30 -> V_5 [ V_1267 ] ) ;
if ( V_1310 == 0 )
return - V_16 ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
F_111 ( V_185 -> V_28 ) ;
V_461 = F_275 ( V_7 , V_185 , V_1310 , true ) ;
F_113 ( V_185 -> V_28 ) ;
return V_461 ;
}
static int F_276 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
V_22 V_1312 ;
if ( ! V_30 -> V_5 [ V_1313 ] )
return - V_16 ;
V_1312 = F_4 ( V_30 -> V_5 [ V_1313 ] ) ;
V_2 = F_277 ( V_1312 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_278 ( V_7 , V_2 ) ;
F_279 ( V_2 ) ;
return V_35 ;
}
static int F_280 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
int (* F_281)( struct V_18 * V_18 , struct V_25 * V_185 ,
struct V_1314 * V_1315 ) = NULL ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1314 V_1315 ;
memset ( & V_1315 , 0 , sizeof( struct V_1314 ) ) ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1316 ] )
return - V_16 ;
V_1315 . V_1317 = F_23 ( V_30 -> V_5 [ V_1316 ] ) ;
V_1315 . V_509 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
switch ( V_30 -> V_1318 -> V_52 ) {
case V_1319 :
F_281 = V_7 -> V_326 -> V_372 ;
break;
case V_1320 :
F_281 = V_7 -> V_326 -> V_374 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_281 )
return - V_505 ;
return F_281 ( & V_7 -> V_18 , V_185 , & V_1315 ) ;
}
static int F_282 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
if ( V_185 -> V_28 -> V_133 != V_139 &&
V_185 -> V_28 -> V_133 != V_140 )
return - V_505 ;
if ( ! V_7 -> V_326 -> V_376 )
return - V_505 ;
return F_283 ( V_7 , V_185 ) ;
}
static int F_284 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 V_1321 , V_1322 ;
V_22 V_1323 = 0 ;
T_3 V_1324 ;
T_2 * V_1325 ;
if ( ! ( V_7 -> V_18 . V_51 & V_307 ) ||
! V_7 -> V_326 -> V_393 )
return - V_505 ;
if ( ! V_30 -> V_5 [ V_1326 ] ||
! V_30 -> V_5 [ V_1327 ] ||
! V_30 -> V_5 [ V_1328 ] ||
! V_30 -> V_5 [ V_634 ] ||
! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
V_1325 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_1321 = F_34 ( V_30 -> V_5 [ V_1326 ] ) ;
V_1324 = F_78 ( V_30 -> V_5 [ V_1327 ] ) ;
V_1322 = F_34 ( V_30 -> V_5 [ V_1328 ] ) ;
if ( V_30 -> V_5 [ V_1329 ] )
V_1323 =
F_4 ( V_30 -> V_5 [ V_1329 ] ) ;
return F_285 ( V_7 , V_185 , V_1325 , V_1321 ,
V_1322 , V_1324 , V_1323 ,
F_23 ( V_30 -> V_5 [ V_634 ] ) ,
F_24 ( V_30 -> V_5 [ V_634 ] ) ) ;
}
static int F_286 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
enum V_1330 V_1331 ;
T_2 * V_1325 ;
if ( ! ( V_7 -> V_18 . V_51 & V_307 ) ||
! V_7 -> V_326 -> V_395 )
return - V_505 ;
if ( ! V_30 -> V_5 [ V_1332 ] ||
! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
V_1331 = F_34 ( V_30 -> V_5 [ V_1332 ] ) ;
V_1325 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
return F_287 ( V_7 , V_185 , V_1325 , V_1331 ) ;
}
static int F_288 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
struct V_485 V_486 ;
struct V_31 * V_53 ;
void * V_265 ;
T_1 V_598 ;
V_22 V_1333 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_488 ] ||
! V_30 -> V_5 [ V_1334 ] )
return - V_16 ;
V_1333 = F_4 ( V_30 -> V_5 [ V_1334 ] ) ;
if ( ! V_7 -> V_326 -> V_379 ||
! ( V_7 -> V_18 . V_51 & V_378 ) )
return - V_505 ;
if ( V_1333 < V_1335 ||
V_1333 > V_7 -> V_18 . V_426 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_486 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1336 ) ;
if ( ! V_265 ) {
V_35 = - V_83 ;
goto V_608;
}
V_35 = F_289 ( V_7 , V_17 , V_486 . V_55 ,
V_1333 , & V_598 ) ;
if ( V_35 )
goto V_608;
if ( F_103 ( V_53 , V_1337 , V_598 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_83 ;
V_608:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_290 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
T_1 V_598 ;
if ( ! V_30 -> V_5 [ V_1337 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1338 )
return - V_505 ;
V_598 = F_5 ( V_30 -> V_5 [ V_1337 ] ) ;
return F_291 ( V_7 , V_17 , V_598 ) ;
}
static V_22 F_292 ( struct V_221 * V_222 ,
T_2 * V_1110 , T_2 V_1339 )
{
T_2 V_145 ;
V_22 V_695 = 0 ;
for ( V_145 = 0 ; V_145 < V_1339 ; V_145 ++ ) {
int V_226 = ( V_1110 [ V_145 ] & 0x7f ) * 5 ;
int V_1340 ;
for ( V_1340 = 0 ; V_1340 < V_222 -> V_243 ; V_1340 ++ ) {
struct V_225 * V_1341 =
& V_222 -> V_244 [ V_1340 ] ;
if ( V_226 == V_1341 -> V_246 ) {
V_695 |= 1 << V_1340 ;
break;
}
}
if ( V_1340 == V_222 -> V_243 )
return 0 ;
}
return V_695 ;
}
static bool F_293 ( struct V_221 * V_222 ,
T_2 * V_1110 , T_2 V_1339 ,
T_2 V_230 [ V_1342 ] )
{
T_2 V_145 ;
memset ( V_230 , 0 , V_1342 ) ;
for ( V_145 = 0 ; V_145 < V_1339 ; V_145 ++ ) {
int V_1340 , V_1343 ;
V_1340 = V_1110 [ V_145 ] / 8 ;
V_1343 = F_149 ( V_1110 [ V_145 ] % 8 ) ;
if ( ( V_1340 < 0 ) || ( V_1340 >= V_1342 ) )
return false ;
if ( V_222 -> V_227 . V_230 . V_1344 [ V_1340 ] & V_1343 )
V_230 [ V_1340 ] |= V_1343 ;
else
return false ;
}
return true ;
}
static T_3 F_294 ( T_2 V_1345 )
{
T_3 V_1346 = 0 ;
switch ( V_1345 ) {
case V_1347 :
break;
case V_1348 :
V_1346 = 0x00FF ;
break;
case V_1349 :
V_1346 = 0x01FF ;
break;
case V_1350 :
V_1346 = 0x03FF ;
break;
default:
break;
}
return V_1346 ;
}
static void F_295 ( T_3 V_1345 ,
T_3 V_1351 [ V_1352 ] )
{
T_2 V_721 ;
for ( V_721 = 0 ; V_721 < V_1352 ; V_721 ++ ) {
V_1351 [ V_721 ] = F_294 ( V_1345 & 0x03 ) ;
V_1345 >>= 2 ;
}
}
static bool F_296 ( struct V_221 * V_222 ,
struct V_1353 * V_778 ,
T_3 V_230 [ V_1352 ] )
{
T_3 V_1354 = F_297 ( V_222 -> V_237 . V_240 . V_1354 ) ;
T_3 V_1355 [ V_1352 ] = {} ;
T_2 V_145 ;
if ( ! V_222 -> V_237 . V_238 )
return false ;
memset ( V_230 , 0 , sizeof( T_3 ) * V_1352 ) ;
F_295 ( V_1354 , V_1355 ) ;
for ( V_145 = 0 ; V_145 < V_1352 ; V_145 ++ ) {
if ( ( V_1355 [ V_145 ] & V_778 -> V_230 [ V_145 ] ) == V_778 -> V_230 [ V_145 ] )
V_230 [ V_145 ] = V_778 -> V_230 [ V_145 ] ;
else
return false ;
}
return true ;
}
static int F_298 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_87 [ V_1356 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1357 V_695 ;
int V_126 , V_145 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_4 * V_1358 ;
struct V_221 * V_222 ;
T_3 V_1359 ;
if ( ! V_7 -> V_326 -> V_381 )
return - V_505 ;
memset ( & V_695 , 0 , sizeof( V_695 ) ) ;
for ( V_145 = 0 ; V_145 < V_337 ; V_145 ++ ) {
V_222 = V_7 -> V_18 . V_338 [ V_145 ] ;
if ( ! V_222 )
continue;
V_695 . V_1360 [ V_145 ] . V_1361 = ( 1 << V_222 -> V_243 ) - 1 ;
memcpy ( V_695 . V_1360 [ V_145 ] . V_1362 ,
V_222 -> V_227 . V_230 . V_1344 ,
sizeof( V_695 . V_1360 [ V_145 ] . V_1362 ) ) ;
if ( ! V_222 -> V_237 . V_238 )
continue;
V_1359 = F_297 ( V_222 -> V_237 . V_240 . V_1354 ) ;
F_295 ( V_1359 , V_695 . V_1360 [ V_145 ] . V_240 ) ;
}
if ( ! V_30 -> V_5 [ V_1363 ] )
goto V_556;
F_112 ( V_1364 > V_1342 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_271 V_272 = F_218 ( V_1358 ) ;
int V_35 ;
if ( V_272 < 0 || V_272 >= V_337 )
return - V_16 ;
V_222 = V_7 -> V_18 . V_338 [ V_272 ] ;
if ( V_222 == NULL )
return - V_16 ;
V_35 = F_95 ( V_87 , V_1356 , F_23 ( V_1358 ) ,
F_24 ( V_1358 ) , V_1365 ) ;
if ( V_35 )
return V_35 ;
if ( V_87 [ V_1366 ] ) {
V_695 . V_1360 [ V_272 ] . V_1361 = F_292 (
V_222 ,
F_23 ( V_87 [ V_1366 ] ) ,
F_24 ( V_87 [ V_1366 ] ) ) ;
if ( ( V_695 . V_1360 [ V_272 ] . V_1361 == 0 ) &&
F_24 ( V_87 [ V_1366 ] ) )
return - V_16 ;
}
if ( V_87 [ V_1367 ] ) {
if ( ! F_293 (
V_222 ,
F_23 ( V_87 [ V_1367 ] ) ,
F_24 ( V_87 [ V_1367 ] ) ,
V_695 . V_1360 [ V_272 ] . V_1362 ) )
return - V_16 ;
}
if ( V_87 [ V_1368 ] ) {
if ( ! F_296 (
V_222 ,
F_23 ( V_87 [ V_1368 ] ) ,
V_695 . V_1360 [ V_272 ] . V_240 ) )
return - V_16 ;
}
if ( V_87 [ V_1369 ] ) {
V_695 . V_1360 [ V_272 ] . V_1370 =
F_34 ( V_87 [ V_1369 ] ) ;
if ( V_695 . V_1360 [ V_272 ] . V_1370 > V_1371 )
return - V_16 ;
}
if ( V_695 . V_1360 [ V_272 ] . V_1361 == 0 ) {
if ( ! ( V_7 -> V_18 . V_338 [ V_272 ] -> V_227 . V_228 ||
V_7 -> V_18 . V_338 [ V_272 ] -> V_237 . V_238 ) )
return - V_16 ;
for ( V_145 = 0 ; V_145 < V_1342 ; V_145 ++ )
if ( V_695 . V_1360 [ V_272 ] . V_1362 [ V_145 ] )
goto V_556;
for ( V_145 = 0 ; V_145 < V_1352 ; V_145 ++ )
if ( V_695 . V_1360 [ V_272 ] . V_240 [ V_145 ] )
goto V_556;
return - V_16 ;
}
}
V_556:
return F_299 ( V_7 , V_185 , NULL , & V_695 ) ;
}
static int F_300 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
T_3 V_1372 = V_260 | V_1373 ;
if ( ! V_30 -> V_5 [ V_1374 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_259 ] )
V_1372 = F_78 ( V_30 -> V_5 [ V_259 ] ) ;
switch ( V_17 -> V_133 ) {
case V_139 :
case V_138 :
case V_140 :
case V_134 :
case V_135 :
case V_137 :
case V_136 :
case V_583 :
break;
default:
return - V_505 ;
}
if ( ! V_7 -> V_326 -> V_383 )
return - V_505 ;
return F_301 ( V_17 , V_30 -> V_469 , V_1372 ,
F_23 ( V_30 -> V_5 [ V_1374 ] ) ,
F_24 ( V_30 -> V_5 [ V_1374 ] ) ) ;
}
static int F_302 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
struct V_485 V_486 ;
int V_35 ;
void * V_265 = NULL ;
T_1 V_598 ;
struct V_31 * V_53 = NULL ;
struct V_1375 V_129 = {
. V_1376 =
V_30 -> V_5 [ V_1377 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1378 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_383 )
return - V_505 ;
switch ( V_17 -> V_133 ) {
case V_583 :
if ( ! V_30 -> V_5 [ V_488 ] )
return - V_16 ;
case V_139 :
case V_138 :
case V_140 :
case V_134 :
case V_135 :
case V_137 :
case V_136 :
break;
default:
return - V_505 ;
}
if ( V_30 -> V_5 [ V_1334 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_427 ) )
return - V_16 ;
V_129 . V_1379 = F_4 ( V_30 -> V_5 [ V_1334 ] ) ;
if ( V_129 . V_1379 < V_1335 ||
V_129 . V_1379 > V_7 -> V_18 . V_426 )
return - V_16 ;
}
V_129 . V_1380 = V_30 -> V_5 [ V_428 ] ;
if ( V_129 . V_1380 && ! ( V_7 -> V_18 . V_51 & V_427 ) )
return - V_16 ;
V_129 . V_1115 = F_202 ( V_30 -> V_5 [ V_1116 ] ) ;
V_486 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_488 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_486 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_486 . V_55 && V_129 . V_1380 )
return - V_16 ;
if ( ! V_129 . V_1376 ) {
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1381 ) ;
if ( ! V_265 ) {
V_35 = - V_83 ;
goto V_608;
}
}
V_129 . V_1382 = F_23 ( V_30 -> V_5 [ V_1378 ] ) ;
V_129 . V_47 = F_24 ( V_30 -> V_5 [ V_1378 ] ) ;
V_129 . V_55 = V_486 . V_55 ;
V_35 = F_303 ( V_7 , V_17 , & V_129 , & V_598 ) ;
if ( V_35 )
goto V_608;
if ( V_53 ) {
if ( F_103 ( V_53 , V_1337 , V_598 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_59:
V_35 = - V_83 ;
V_608:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_304 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
T_1 V_598 ;
if ( ! V_30 -> V_5 [ V_1337 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_385 )
return - V_505 ;
switch ( V_17 -> V_133 ) {
case V_139 :
case V_138 :
case V_140 :
case V_134 :
case V_135 :
case V_136 :
case V_583 :
break;
default:
return - V_505 ;
}
V_598 = F_5 ( V_30 -> V_5 [ V_1337 ] ) ;
return F_305 ( V_7 , V_17 , V_598 ) ;
}
static int F_306 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 V_1383 ;
bool V_264 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1384 ] )
return - V_16 ;
V_1383 = F_4 ( V_30 -> V_5 [ V_1384 ] ) ;
if ( V_1383 != V_1385 && V_1383 != V_1386 )
return - V_16 ;
V_17 = V_185 -> V_28 ;
if ( ! V_7 -> V_326 -> V_1387 )
return - V_505 ;
V_264 = ( V_1383 == V_1386 ) ? true : false ;
if ( V_264 == V_17 -> V_1388 )
return 0 ;
V_35 = F_307 ( V_7 , V_185 , V_264 , V_17 -> V_1389 ) ;
if ( ! V_35 )
V_17 -> V_1388 = V_264 ;
return V_35 ;
}
static int F_308 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
enum V_1390 V_1383 ;
struct V_1 * V_17 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_31 * V_53 ;
void * V_265 ;
int V_35 ;
V_17 = V_185 -> V_28 ;
if ( ! V_7 -> V_326 -> V_1387 )
return - V_505 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1391 ) ;
if ( ! V_265 ) {
V_35 = - V_83 ;
goto V_608;
}
if ( V_17 -> V_1388 )
V_1383 = V_1386 ;
else
V_1383 = V_1385 ;
if ( F_28 ( V_53 , V_1384 , V_1383 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_83 ;
V_608:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_309 ( struct V_29 * V_30 ,
V_22 V_226 , V_22 V_1392 , V_22 V_1393 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
if ( V_226 > 100 || V_1393 > V_1394 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1395 )
return - V_505 ;
if ( V_17 -> V_133 != V_139 &&
V_17 -> V_133 != V_140 )
return - V_505 ;
return F_310 ( V_7 , V_185 , V_226 , V_1392 , V_1393 ) ;
}
static int F_311 ( struct V_29 * V_30 ,
T_11 V_1396 , V_22 V_1397 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
if ( V_1396 > 0 )
return - V_16 ;
if ( V_1396 == 0 )
V_1397 = 0 ;
if ( ! V_7 -> V_326 -> V_1398 )
return - V_505 ;
if ( V_17 -> V_133 != V_139 &&
V_17 -> V_133 != V_140 )
return - V_505 ;
return F_312 ( V_7 , V_185 , V_1396 , V_1397 ) ;
}
static int F_313 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1399 + 1 ] ;
struct V_4 * V_1400 ;
int V_35 ;
V_1400 = V_30 -> V_5 [ V_1401 ] ;
if ( ! V_1400 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1399 , V_1400 ,
V_1402 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1403 ] &&
V_5 [ V_1404 ] ) {
T_11 V_1396 = V_1038 ( V_5 [ V_1403 ] ) ;
V_22 V_1397 = F_4 ( V_5 [ V_1404 ] ) ;
return F_311 ( V_30 , V_1396 , V_1397 ) ;
}
if ( V_5 [ V_1405 ] &&
V_5 [ V_1406 ] &&
V_5 [ V_1407 ] ) {
V_22 V_226 = F_4 ( V_5 [ V_1405 ] ) ;
V_22 V_1392 = F_4 ( V_5 [ V_1406 ] ) ;
V_22 V_1393 = F_4 ( V_5 [ V_1407 ] ) ;
return F_309 ( V_30 , V_226 , V_1392 , V_1393 ) ;
}
return - V_16 ;
}
static int F_314 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_972 V_1034 ;
struct V_1040 V_1041 ;
int V_35 ;
memcpy ( & V_1034 , & V_976 , sizeof( V_1034 ) ) ;
memcpy ( & V_1041 , & V_1408 , sizeof( V_1041 ) ) ;
if ( V_30 -> V_5 [ V_978 ] ) {
V_35 = F_199 ( V_30 , & V_1034 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_574 ] ||
! F_24 ( V_30 -> V_5 [ V_574 ] ) )
return - V_16 ;
V_1041 . V_1409 = F_23 ( V_30 -> V_5 [ V_574 ] ) ;
V_1041 . V_975 = F_24 ( V_30 -> V_5 [ V_574 ] ) ;
if ( V_30 -> V_5 [ V_1277 ] &&
! F_257 ( V_7 , V_1041 . V_1268 ,
F_4 ( V_30 -> V_5 [ V_1277 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_662 ] ) {
V_1041 . V_506 =
F_4 ( V_30 -> V_5 [ V_662 ] ) ;
if ( V_1041 . V_506 < 10 ||
V_1041 . V_506 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_663 ] ) {
V_1041 . V_665 =
F_4 ( V_30 -> V_5 [ V_663 ] ) ;
if ( V_1041 . V_665 < 1 || V_1041 . V_665 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1043 ] ) {
V_35 = F_201 ( V_30 , & V_1041 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1041 . V_1063 )
V_1034 . V_994 = false ;
if ( V_30 -> V_5 [ V_488 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1041 . V_486 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1041 . V_486 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_940 ] ) {
T_2 * V_1110 = F_23 ( V_30 -> V_5 [ V_940 ] ) ;
int V_1276 =
F_24 ( V_30 -> V_5 [ V_940 ] ) ;
struct V_221 * V_222 ;
if ( ! V_1041 . V_486 . V_55 )
return - V_16 ;
V_222 = V_7 -> V_18 . V_338 [ V_1041 . V_486 . V_55 -> V_272 ] ;
V_35 = F_219 ( V_222 , V_1110 , V_1276 ,
& V_1041 . V_941 ) ;
if ( V_35 )
return V_35 ;
}
return F_315 ( V_7 , V_185 , & V_1041 , & V_1034 ) ;
}
static int F_316 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
return F_317 ( V_7 , V_185 ) ;
}
static int F_318 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1410 * V_173 = V_7 -> V_18 . V_1411 ;
struct V_4 * V_1412 , * V_1413 ;
int V_145 , V_1414 ;
if ( ! V_173 -> V_204 )
return 0 ;
V_1412 = F_47 ( V_53 , V_213 ) ;
if ( ! V_1412 )
return - V_83 ;
for ( V_145 = 0 ; V_145 < V_173 -> V_204 ; V_145 ++ ) {
V_1413 = F_47 ( V_53 , V_145 + 1 ) ;
if ( ! V_1413 )
return - V_83 ;
V_1414 = V_173 -> V_1415 [ V_145 ] . V_1416 ;
if ( F_51 ( V_53 , V_1417 , F_319 ( V_1414 , 8 ) ,
V_173 -> V_1415 [ V_145 ] . V_695 ) ||
F_51 ( V_53 , V_1418 , V_1414 ,
V_173 -> V_1415 [ V_145 ] . V_1419 ) ||
F_28 ( V_53 , V_1420 ,
V_173 -> V_1415 [ V_145 ] . V_1421 ) )
return - V_83 ;
F_48 ( V_53 , V_1413 ) ;
}
F_48 ( V_53 , V_1412 ) ;
return 0 ;
}
static int F_320 ( struct V_31 * V_53 ,
struct V_1422 * V_172 )
{
struct V_4 * V_174 ;
if ( ! V_172 )
return 0 ;
V_174 = F_47 ( V_53 , V_175 ) ;
if ( ! V_174 )
return - V_83 ;
if ( F_321 ( V_53 , V_1423 , V_172 -> V_1424 ) ||
F_321 ( V_53 , V_1425 , V_172 -> V_899 ) ||
F_51 ( V_53 , V_1426 , V_546 , V_172 -> V_1427 ) ||
F_55 ( V_53 , V_1428 , V_172 -> V_1429 ) ||
F_55 ( V_53 , V_1430 , V_172 -> V_1431 ) ||
F_51 ( V_53 , V_176 ,
V_172 -> V_1432 , V_172 -> V_1433 ) ||
F_28 ( V_53 , V_181 ,
V_172 -> V_1434 ) ||
F_51 ( V_53 , V_183 ,
V_172 -> V_1435 , V_172 -> V_1436 ) ||
F_51 ( V_53 , V_1437 ,
F_319 ( V_172 -> V_1435 , 8 ) , V_172 -> V_1438 ) )
return - V_83 ;
if ( V_172 -> V_1439 . V_47 &&
F_51 ( V_53 , V_178 ,
sizeof( V_172 -> V_1439 ) , & V_172 -> V_1439 ) )
return - V_83 ;
if ( V_172 -> V_1440 . V_47 &&
F_51 ( V_53 , V_180 ,
sizeof( V_172 -> V_1440 ) + V_172 -> V_1441 ,
& V_172 -> V_1440 ) )
return - V_83 ;
F_48 ( V_53 , V_174 ) ;
return 0 ;
}
static int F_322 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_31 * V_53 ;
void * V_265 ;
V_22 V_1442 = V_557 ;
if ( ! V_7 -> V_18 . V_173 )
return - V_505 ;
if ( V_7 -> V_18 . V_1411 && V_7 -> V_18 . V_1411 -> V_172 ) {
V_1442 += V_7 -> V_18 . V_1411 -> V_172 -> V_1441 +
V_7 -> V_18 . V_1411 -> V_172 -> V_1432 +
V_7 -> V_18 . V_1411 -> V_172 -> V_1435 +
V_7 -> V_18 . V_1411 -> V_172 -> V_1435 / 8 ;
}
V_53 = F_74 ( V_1442 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1443 ) ;
if ( ! V_265 )
goto V_59;
if ( V_7 -> V_18 . V_1411 ) {
struct V_4 * V_186 ;
V_186 = F_47 ( V_53 , V_1444 ) ;
if ( ! V_186 )
goto V_59;
if ( ( V_7 -> V_18 . V_1411 -> V_1445 &&
F_29 ( V_53 , V_189 ) ) ||
( V_7 -> V_18 . V_1411 -> V_423 &&
F_29 ( V_53 , V_191 ) ) ||
( V_7 -> V_18 . V_1411 -> V_1446 &&
F_29 ( V_53 , V_193 ) ) ||
( V_7 -> V_18 . V_1411 -> V_1447 &&
F_29 ( V_53 , V_197 ) ) ||
( V_7 -> V_18 . V_1411 -> V_1448 &&
F_29 ( V_53 , V_199 ) ) ||
( V_7 -> V_18 . V_1411 -> V_1449 &&
F_29 ( V_53 , V_201 ) ) ||
( V_7 -> V_18 . V_1411 -> V_1450 &&
F_29 ( V_53 , V_203 ) ) )
goto V_59;
if ( F_318 ( V_53 , V_7 ) )
goto V_59;
if ( F_320 ( V_53 ,
V_7 -> V_18 . V_1411 -> V_172 ) )
goto V_59;
F_48 ( V_53 , V_186 ) ;
}
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
F_75 ( V_53 ) ;
return - V_83 ;
}
static int F_323 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1410 * V_1451 )
{
struct V_4 * V_87 [ V_1452 ] ;
struct V_1422 * V_1034 ;
struct V_1453 * V_179 = NULL ;
struct V_1454 * V_50 = NULL ;
V_22 V_1442 ;
V_22 V_1455 , V_1456 , V_1441 = 0 , V_1457 ;
int V_35 , V_1458 ;
if ( ! V_7 -> V_18 . V_173 -> V_172 )
return - V_16 ;
V_35 = F_95 ( V_87 , V_1459 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1460 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_87 [ V_1423 ] ||
! V_87 [ V_1425 ] ||
! V_87 [ V_1426 ] ||
! V_87 [ V_1430 ] ||
! V_87 [ V_176 ] ||
! V_87 [ V_181 ] ||
! V_87 [ V_183 ] ||
! V_87 [ V_1437 ] )
return - V_16 ;
V_1455 = F_24 ( V_87 [ V_176 ] ) ;
if ( V_1455 > V_7 -> V_18 . V_173 -> V_172 -> V_177 )
return - V_16 ;
if ( F_4 ( V_87 [ V_181 ] ) >
V_7 -> V_18 . V_173 -> V_172 -> V_182 ||
F_4 ( V_87 [ V_181 ] ) == 0 )
return - V_16 ;
V_1456 = F_24 ( V_87 [ V_183 ] ) ;
if ( V_1456 > V_7 -> V_18 . V_173 -> V_172 -> V_184 )
return - V_16 ;
V_1457 = F_24 ( V_87 [ V_1437 ] ) ;
if ( V_1457 != F_319 ( V_1456 , 8 ) )
return - V_16 ;
if ( V_87 [ V_180 ] ) {
V_22 V_1461 = F_24 ( V_87 [ V_180 ] ) ;
V_179 = F_23 ( V_87 [ V_180 ] ) ;
V_1441 = V_1461 - sizeof( * V_179 ) ;
if ( ! V_179 -> V_47 || V_1441 % V_179 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_173 -> V_172 -> V_179 )
return - V_16 ;
if ( V_179 -> V_47 > V_7 -> V_18 . V_173 -> V_172 -> V_179 -> V_1462 )
return - V_16 ;
if ( V_179 -> V_47 < V_7 -> V_18 . V_173 -> V_172 -> V_179 -> V_1463 )
return - V_16 ;
if ( V_1441 > V_7 -> V_18 . V_173 -> V_172 -> V_179 -> V_1464 )
return - V_16 ;
if ( V_179 -> V_1465 + V_179 -> V_47 > V_1455 )
return - V_16 ;
}
if ( V_87 [ V_178 ] ) {
V_50 = F_23 ( V_87 [ V_178 ] ) ;
if ( ! V_7 -> V_18 . V_173 -> V_172 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1465 > V_1455 )
return - V_16 ;
}
V_1442 = sizeof( * V_1034 ) ;
V_1442 += V_1455 ;
V_1442 += V_1456 + V_1457 ;
V_1442 += V_1441 ;
V_1034 = F_38 ( V_1442 , V_127 ) ;
if ( ! V_1034 )
return - V_128 ;
V_1034 -> V_1424 = F_324 ( V_87 [ V_1423 ] ) ;
V_1034 -> V_899 = F_324 ( V_87 [ V_1425 ] ) ;
memcpy ( V_1034 -> V_1427 , F_23 ( V_87 [ V_1426 ] ) ,
V_546 ) ;
if ( V_87 [ V_1428 ] )
V_1458 = F_78 ( V_87 [ V_1428 ] ) ;
else
V_1458 = 0 ;
#ifdef F_325
V_35 = F_326 ( F_7 ( & V_7 -> V_18 ) , V_1466 , V_1467 ,
V_1468 , & V_1034 -> V_1469 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1034 ) ;
return V_35 ;
}
if ( F_327 ( V_1034 -> V_1469 -> V_44 , V_1458 ) ) {
F_328 ( V_1034 -> V_1469 ) ;
F_41 ( V_1034 ) ;
return - V_1470 ;
}
V_1034 -> V_1429 = F_329 ( V_1034 -> V_1469 -> V_44 ) -> V_1471 ;
#else
if ( ! V_1458 ) {
F_41 ( V_1034 ) ;
return - V_16 ;
}
V_1034 -> V_1429 = V_1458 ;
#endif
V_1034 -> V_1431 = F_78 ( V_87 [ V_1430 ] ) ;
V_1034 -> V_1432 = V_1455 ;
V_1034 -> V_1433 = ( T_2 * ) V_1034 + sizeof( * V_1034 ) + V_1441 ;
memcpy ( ( void * ) V_1034 -> V_1433 ,
F_23 ( V_87 [ V_176 ] ) ,
V_1455 ) ;
if ( V_50 )
V_1034 -> V_1439 = * V_50 ;
V_1034 -> V_1434 = F_4 ( V_87 [ V_181 ] ) ;
V_1034 -> V_1435 = V_1456 ;
V_1034 -> V_1436 = ( T_2 * ) V_1034 + sizeof( * V_1034 ) + V_1441 + V_1455 ;
memcpy ( ( void * ) V_1034 -> V_1436 ,
F_23 ( V_87 [ V_183 ] ) ,
V_1456 ) ;
V_1034 -> V_1438 = ( T_2 * ) V_1034 + sizeof( * V_1034 ) + V_1441 +
V_1455 + V_1456 ;
memcpy ( ( void * ) V_1034 -> V_1438 ,
F_23 ( V_87 [ V_1437 ] ) ,
V_1457 ) ;
if ( V_179 ) {
V_1034 -> V_1441 = V_1441 ;
memcpy ( & V_1034 -> V_1440 , V_179 , sizeof( * V_179 ) + V_1441 ) ;
}
V_1451 -> V_172 = V_1034 ;
return 0 ;
}
static int F_330 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_4 * V_87 [ V_1472 ] ;
struct V_1410 V_1473 = {} ;
struct V_1410 * V_1474 ;
const struct V_1475 * V_173 = V_7 -> V_18 . V_173 ;
int V_35 , V_145 ;
bool V_1476 = V_7 -> V_18 . V_1411 ;
if ( ! V_173 )
return - V_505 ;
if ( ! V_30 -> V_5 [ V_1444 ] ) {
F_331 ( V_7 ) ;
V_7 -> V_18 . V_1411 = NULL ;
goto V_1477;
}
V_35 = F_95 ( V_87 , V_1478 ,
F_23 ( V_30 -> V_5 [ V_1444 ] ) ,
F_24 ( V_30 -> V_5 [ V_1444 ] ) ,
V_1479 ) ;
if ( V_35 )
return V_35 ;
if ( V_87 [ V_189 ] ) {
if ( ! ( V_173 -> V_51 & V_188 ) )
return - V_16 ;
V_1473 . V_1445 = true ;
}
if ( V_87 [ V_191 ] ) {
if ( ! ( V_173 -> V_51 & V_190 ) )
return - V_16 ;
V_1473 . V_423 = true ;
}
if ( V_87 [ V_193 ] ) {
if ( ! ( V_173 -> V_51 & V_192 ) )
return - V_16 ;
V_1473 . V_1446 = true ;
}
if ( V_87 [ V_195 ] )
return - V_16 ;
if ( V_87 [ V_197 ] ) {
if ( ! ( V_173 -> V_51 & V_196 ) )
return - V_16 ;
V_1473 . V_1447 = true ;
}
if ( V_87 [ V_199 ] ) {
if ( ! ( V_173 -> V_51 & V_198 ) )
return - V_16 ;
V_1473 . V_1448 = true ;
}
if ( V_87 [ V_201 ] ) {
if ( ! ( V_173 -> V_51 & V_200 ) )
return - V_16 ;
V_1473 . V_1449 = true ;
}
if ( V_87 [ V_203 ] ) {
if ( ! ( V_173 -> V_51 & V_202 ) )
return - V_16 ;
V_1473 . V_1450 = true ;
}
if ( V_87 [ V_213 ] ) {
struct V_4 * V_206 ;
int V_204 = 0 ;
int V_126 , V_1414 , V_1480 , V_1421 ;
struct V_4 * V_1481 [ V_1482 ] ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_204 ++ ;
if ( V_204 > V_173 -> V_204 )
return - V_16 ;
V_1473 . V_1415 = F_332 ( V_204 ,
sizeof( V_1473 . V_1415 [ 0 ] ) ,
V_127 ) ;
if ( ! V_1473 . V_1415 )
return - V_128 ;
V_1473 . V_204 = V_204 ;
V_145 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_95 ( V_1481 , V_1483 , F_23 ( V_206 ) ,
F_24 ( V_206 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1481 [ V_1417 ] ||
! V_1481 [ V_1418 ] )
goto error;
V_1414 = F_24 ( V_1481 [ V_1418 ] ) ;
V_1480 = F_319 ( V_1414 , 8 ) ;
if ( F_24 ( V_1481 [ V_1417 ] ) != V_1480 )
goto error;
if ( V_1414 > V_173 -> V_211 ||
V_1414 < V_173 -> V_209 )
goto error;
if ( ! V_1481 [ V_1420 ] )
V_1421 = 0 ;
else
V_1421 = F_4 (
V_1481 [ V_1420 ] ) ;
if ( V_1421 > V_173 -> V_212 )
goto error;
V_1473 . V_1415 [ V_145 ] . V_1421 = V_1421 ;
V_1473 . V_1415 [ V_145 ] . V_695 =
F_333 ( V_1480 + V_1414 , V_127 ) ;
if ( ! V_1473 . V_1415 [ V_145 ] . V_695 ) {
V_35 = - V_128 ;
goto error;
}
V_1473 . V_1415 [ V_145 ] . V_1419 =
V_1473 . V_1415 [ V_145 ] . V_695 + V_1480 ;
memcpy ( V_1473 . V_1415 [ V_145 ] . V_695 ,
F_23 ( V_1481 [ V_1417 ] ) ,
V_1480 ) ;
V_1473 . V_1415 [ V_145 ] . V_1416 = V_1414 ;
memcpy ( V_1473 . V_1415 [ V_145 ] . V_1419 ,
F_23 ( V_1481 [ V_1418 ] ) ,
V_1414 ) ;
V_145 ++ ;
}
}
if ( V_87 [ V_175 ] ) {
V_35 = F_323 (
V_7 , V_87 [ V_175 ] ,
& V_1473 ) ;
if ( V_35 )
goto error;
}
V_1474 = F_334 ( & V_1473 , sizeof( V_1473 ) , V_127 ) ;
if ( ! V_1474 ) {
V_35 = - V_128 ;
goto error;
}
F_331 ( V_7 ) ;
V_7 -> V_18 . V_1411 = V_1474 ;
V_1477:
if ( V_7 -> V_326 -> V_1477 &&
V_1476 != ! ! V_7 -> V_18 . V_1411 )
F_335 ( V_7 , V_7 -> V_18 . V_1411 ) ;
return 0 ;
error:
for ( V_145 = 0 ; V_145 < V_1473 . V_204 ; V_145 ++ )
F_41 ( V_1473 . V_1415 [ V_145 ] . V_695 ) ;
F_41 ( V_1473 . V_1415 ) ;
if ( V_1473 . V_172 && V_1473 . V_172 -> V_1469 )
F_328 ( V_1473 . V_172 -> V_1469 ) ;
F_41 ( V_1473 . V_172 ) ;
return V_35 ;
}
static int F_336 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1412 , * V_1413 , * V_1484 , * V_1485 ;
int V_145 , V_147 , V_1414 ;
struct V_1486 * V_215 ;
if ( ! V_7 -> V_216 -> V_218 )
return 0 ;
V_1485 = F_47 ( V_53 , V_220 ) ;
if ( ! V_1485 )
return - V_83 ;
for ( V_145 = 0 ; V_145 < V_7 -> V_216 -> V_218 ; V_145 ++ ) {
V_1484 = F_47 ( V_53 , V_145 + 1 ) ;
if ( ! V_1484 )
return - V_83 ;
V_215 = & V_7 -> V_216 -> V_1487 [ V_145 ] ;
if ( F_28 ( V_53 , V_1488 ,
V_215 -> V_1489 ) )
return - V_83 ;
if ( F_28 ( V_53 , V_1490 ,
V_215 -> V_1491 ) )
return - V_83 ;
V_1412 = F_47 ( V_53 ,
V_1492 ) ;
if ( ! V_1412 )
return - V_83 ;
for ( V_147 = 0 ; V_147 < V_215 -> V_204 ; V_147 ++ ) {
V_1413 = F_47 ( V_53 , V_147 + 1 ) ;
if ( ! V_1413 )
return - V_83 ;
V_1414 = V_215 -> V_1415 [ V_147 ] . V_1416 ;
if ( F_51 ( V_53 , V_1417 ,
F_319 ( V_1414 , 8 ) ,
V_215 -> V_1415 [ V_147 ] . V_695 ) ||
F_51 ( V_53 , V_1418 , V_1414 ,
V_215 -> V_1415 [ V_147 ] . V_1419 ) ||
F_28 ( V_53 , V_1420 ,
V_215 -> V_1415 [ V_147 ] . V_1421 ) )
return - V_83 ;
F_48 ( V_53 , V_1413 ) ;
}
F_48 ( V_53 , V_1412 ) ;
F_48 ( V_53 , V_1484 ) ;
}
F_48 ( V_53 , V_1485 ) ;
return 0 ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_31 * V_53 ;
void * V_265 ;
if ( ! V_7 -> V_18 . V_216 )
return - V_505 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1493 ) ;
if ( ! V_265 )
goto V_59;
if ( V_7 -> V_216 && F_336 ( V_53 , V_7 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
F_75 ( V_53 ) ;
return - V_83 ;
}
void F_338 ( struct V_6 * V_7 )
{
struct V_1494 * V_216 = V_7 -> V_216 ;
int V_145 , V_147 ;
struct V_1486 * V_215 ;
if ( ! V_216 )
return;
for ( V_145 = 0 ; V_145 < V_216 -> V_218 ; V_145 ++ ) {
V_215 = & V_216 -> V_1487 [ V_145 ] ;
for ( V_147 = 0 ; V_147 < V_215 -> V_204 ; V_147 ++ )
F_41 ( V_215 -> V_1415 [ V_147 ] . V_695 ) ;
F_41 ( V_215 -> V_1415 ) ;
}
F_41 ( V_216 -> V_1487 ) ;
F_41 ( V_216 ) ;
V_7 -> V_216 = NULL ;
}
static int F_339 ( struct V_6 * V_7 ,
struct V_4 * V_215 ,
struct V_1486 * V_1495 )
{
int V_35 , V_145 ;
const struct V_1496 * V_216 = V_7 -> V_18 . V_216 ;
struct V_4 * V_87 [ V_1497 ] , * V_206 ;
int V_126 , V_1414 , V_1480 , V_1421 , V_204 = 0 ;
struct V_4 * V_1481 [ V_1482 ] ;
V_35 = F_95 ( V_87 , V_1498 , F_23 ( V_215 ) ,
F_24 ( V_215 ) , V_1499 ) ;
if ( V_35 )
return V_35 ;
if ( V_87 [ V_1488 ] )
V_1495 -> V_1489 =
F_4 ( V_87 [ V_1488 ] ) ;
if ( V_1495 -> V_1489 > V_216 -> V_219 )
return - V_16 ;
if ( V_87 [ V_1490 ] )
V_1495 -> V_1491 =
F_4 ( V_87 [ V_1490 ] ) ;
if ( V_1495 -> V_1491 != V_1500 &&
V_1495 -> V_1491 != V_1501 )
return - V_16 ;
if ( ! V_87 [ V_1492 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_204 ++ ;
if ( V_204 > V_216 -> V_204 )
return - V_16 ;
V_1495 -> V_1415 = F_332 ( V_204 , sizeof( V_1495 -> V_1415 [ 0 ] ) ,
V_127 ) ;
if ( ! V_1495 -> V_1415 )
return - V_128 ;
V_1495 -> V_204 = V_204 ;
V_145 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
F_95 ( V_1481 , V_1483 , F_23 ( V_206 ) ,
F_24 ( V_206 ) , NULL ) ;
if ( ! V_1481 [ V_1417 ] ||
! V_1481 [ V_1418 ] )
return - V_16 ;
V_1414 = F_24 ( V_1481 [ V_1418 ] ) ;
V_1480 = F_319 ( V_1414 , 8 ) ;
if ( F_24 ( V_1481 [ V_1417 ] ) != V_1480 )
return - V_16 ;
if ( V_1414 > V_216 -> V_211 ||
V_1414 < V_216 -> V_209 )
return - V_16 ;
if ( ! V_1481 [ V_1420 ] )
V_1421 = 0 ;
else
V_1421 = F_4 ( V_1481 [ V_1420 ] ) ;
if ( V_1421 > V_216 -> V_212 )
return - V_16 ;
V_1495 -> V_1415 [ V_145 ] . V_1421 = V_1421 ;
V_1495 -> V_1415 [ V_145 ] . V_695 =
F_333 ( V_1480 + V_1414 , V_127 ) ;
if ( ! V_1495 -> V_1415 [ V_145 ] . V_695 )
return - V_128 ;
V_1495 -> V_1415 [ V_145 ] . V_1419 =
V_1495 -> V_1415 [ V_145 ] . V_695 + V_1480 ;
memcpy ( V_1495 -> V_1415 [ V_145 ] . V_695 ,
F_23 ( V_1481 [ V_1417 ] ) , V_1480 ) ;
V_1495 -> V_1415 [ V_145 ] . V_1416 = V_1414 ;
memcpy ( V_1495 -> V_1415 [ V_145 ] . V_1419 ,
F_23 ( V_1481 [ V_1418 ] ) , V_1414 ) ;
V_145 ++ ;
}
return 0 ;
}
static int F_340 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
const struct V_1496 * V_216 = V_7 -> V_18 . V_216 ;
struct V_1494 V_1502 = {} ;
struct V_1494 * V_1503 ;
int V_35 , V_1504 , V_218 = 0 , V_145 , V_147 ;
struct V_4 * V_215 ;
struct V_1486 * V_1505 ;
if ( ! V_7 -> V_18 . V_216 || ! V_7 -> V_326 -> V_1506 )
return - V_505 ;
if ( ! V_30 -> V_5 [ V_220 ] ) {
F_338 ( V_7 ) ;
V_7 -> V_326 -> V_1506 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_218 ++ ;
if ( V_218 > V_216 -> V_218 )
return - V_16 ;
V_1502 . V_1487 = F_332 ( V_218 , sizeof( V_1502 . V_1487 [ 0 ] ) ,
V_127 ) ;
if ( ! V_1502 . V_1487 )
return - V_128 ;
V_1502 . V_218 = V_218 ;
V_145 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_339 ( V_7 , V_215 ,
& V_1502 . V_1487 [ V_145 ] ) ;
if ( V_35 )
goto error;
V_145 ++ ;
}
V_35 = V_7 -> V_326 -> V_1506 ( & V_7 -> V_18 , & V_1502 ) ;
if ( V_35 )
goto error;
V_1503 = F_334 ( & V_1502 , sizeof( V_1502 ) , V_127 ) ;
if ( ! V_1503 ) {
V_35 = - V_128 ;
goto error;
}
F_338 ( V_7 ) ;
V_7 -> V_216 = V_1503 ;
return 0 ;
error:
for ( V_145 = 0 ; V_145 < V_1502 . V_218 ; V_145 ++ ) {
V_1505 = & V_1502 . V_1487 [ V_145 ] ;
for ( V_147 = 0 ; V_147 < V_1505 -> V_204 ; V_147 ++ )
F_41 ( V_1505 -> V_1415 [ V_147 ] . V_695 ) ;
F_41 ( V_1505 -> V_1415 ) ;
}
F_41 ( V_1502 . V_1487 ) ;
return V_35 ;
}
static int F_341 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_4 * V_87 [ V_1507 ] ;
struct V_1508 V_1509 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1510 ] )
return - V_16 ;
V_35 = F_95 ( V_87 , V_1511 ,
F_23 ( V_30 -> V_5 [ V_1510 ] ) ,
F_24 ( V_30 -> V_5 [ V_1510 ] ) ,
V_1512 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_87 [ V_1513 ] ) != V_1514 )
return - V_1515 ;
if ( F_24 ( V_87 [ V_1516 ] ) != V_1517 )
return - V_1515 ;
if ( F_24 ( V_87 [ V_1518 ] ) != V_1519 )
return - V_1515 ;
memcpy ( V_1509 . V_1520 , F_23 ( V_87 [ V_1516 ] ) ,
V_1517 ) ;
memcpy ( V_1509 . V_1521 , F_23 ( V_87 [ V_1518 ] ) ,
V_1519 ) ;
memcpy ( V_1509 . V_1522 ,
F_23 ( V_87 [ V_1513 ] ) ,
V_1514 ) ;
F_111 ( V_17 ) ;
if ( ! V_17 -> V_141 ) {
V_35 = - V_1147 ;
goto V_556;
}
if ( ! V_7 -> V_326 -> V_1523 ) {
V_35 = - V_505 ;
goto V_556;
}
V_35 = F_342 ( V_7 , V_185 , & V_1509 ) ;
V_556:
F_113 ( V_17 ) ;
return V_35 ;
}
static int F_343 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
if ( V_17 -> V_133 != V_134 &&
V_17 -> V_133 != V_136 )
return - V_16 ;
if ( V_17 -> V_1524 )
return - V_507 ;
V_17 -> V_1524 = V_30 -> V_469 ;
return 0 ;
}
static int F_344 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_31 * V_53 ;
void * V_265 ;
const T_2 * V_628 ;
T_1 V_598 ;
int V_35 ;
if ( V_17 -> V_133 != V_134 &&
V_17 -> V_133 != V_136 )
return - V_505 ;
if ( ! V_30 -> V_5 [ V_510 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_400 )
return - V_505 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1525 ) ;
if ( ! V_265 ) {
V_35 = - V_83 ;
goto V_608;
}
V_628 = F_23 ( V_30 -> V_5 [ V_510 ] ) ;
V_35 = F_345 ( V_7 , V_185 , V_628 , & V_598 ) ;
if ( V_35 )
goto V_608;
if ( F_103 ( V_53 , V_1337 , V_598 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
V_35 = - V_83 ;
V_608:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_346 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1526 * V_1527 , * V_1528 ;
int V_1529 ;
if ( ! ( V_7 -> V_18 . V_51 & V_404 ) )
return - V_505 ;
V_1528 = F_38 ( sizeof( * V_1528 ) , V_127 ) ;
if ( ! V_1528 )
return - V_128 ;
F_240 ( & V_7 -> V_1530 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1527 -> V_1531 == V_30 -> V_469 ) {
V_1529 = - V_661 ;
goto V_826;
}
}
V_1528 -> V_1531 = V_30 -> V_469 ;
F_347 ( & V_1528 -> V_591 , & V_7 -> V_1532 ) ;
F_242 ( & V_7 -> V_1530 ) ;
return 0 ;
V_826:
F_242 ( & V_7 -> V_1530 ) ;
F_41 ( V_1528 ) ;
return V_1529 ;
}
static int F_348 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_326 -> V_406 )
return - V_505 ;
if ( V_17 -> V_133 != V_583 )
return - V_505 ;
if ( V_17 -> V_1533 )
return 0 ;
V_35 = F_349 ( V_7 , V_17 -> V_133 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_350 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1533 = true ;
V_7 -> V_1534 ++ ;
return 0 ;
}
static int F_351 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
if ( V_17 -> V_133 != V_583 )
return - V_505 ;
if ( ! V_7 -> V_326 -> V_1535 )
return - V_505 ;
F_352 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_353 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_265 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , V_30 -> V_469 , V_30 -> V_470 , 0 ,
V_1536 ) ;
if ( ! V_265 )
goto V_59;
if ( F_28 ( V_53 , V_1537 ,
V_1538 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_76 ( V_53 , V_30 ) ;
V_59:
F_264 ( V_53 ) ;
return - V_83 ;
}
static int F_354 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1539 V_1540 ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_1541 )
return - V_505 ;
if ( ! V_30 -> V_5 [ V_1542 ] ||
! F_22 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
memset ( & V_1540 , 0 , sizeof( V_1540 ) ) ;
V_1540 . V_1543 = F_78 ( V_30 -> V_5 [ V_1542 ] ) ;
V_1540 . V_1059 = F_23 ( V_30 -> V_5 [ V_634 ] ) ;
V_1540 . V_1060 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
return F_355 ( V_7 , V_185 , & V_1540 ) ;
}
static int F_356 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
enum V_1544 V_1235 = V_1545 ;
T_3 V_1333 ;
int V_461 ;
if ( ! V_7 -> V_326 -> V_410 )
return - V_505 ;
if ( F_59 ( ! V_7 -> V_326 -> V_412 ) )
return - V_16 ;
if ( V_7 -> V_1546 )
return - V_507 ;
if ( V_30 -> V_5 [ V_1547 ] )
V_1235 = F_78 ( V_30 -> V_5 [ V_1547 ] ) ;
if ( V_1235 >= V_1548 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1549 ] )
return - V_16 ;
V_1333 =
F_78 ( V_30 -> V_5 [ V_1549 ] ) ;
if ( V_1333 > V_1550 )
return - V_1515 ;
V_461 = F_357 ( V_7 , V_17 , V_1235 , V_1333 ) ;
if ( ! V_461 )
V_7 -> V_1546 = V_30 -> V_469 ;
return V_461 ;
}
static int F_358 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_412 )
return - V_505 ;
if ( V_7 -> V_1546 ) {
V_7 -> V_1546 = 0 ;
F_359 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_360 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_93 ( V_30 ) , V_30 -> V_5 ) ;
int V_145 , V_35 ;
V_22 V_1551 , V_1289 ;
if ( ! V_7 -> V_18 . V_456 )
return - V_505 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1286 ] ||
! V_30 -> V_5 [ V_1288 ] )
return - V_16 ;
V_1551 = F_4 ( V_30 -> V_5 [ V_1286 ] ) ;
V_1289 = F_4 ( V_30 -> V_5 [ V_1288 ] ) ;
for ( V_145 = 0 ; V_145 < V_7 -> V_18 . V_452 ; V_145 ++ ) {
const struct V_1552 * V_1553 ;
void * V_130 = NULL ;
int V_47 = 0 ;
V_1553 = & V_7 -> V_18 . V_456 [ V_145 ] ;
if ( V_1553 -> V_30 . V_1287 != V_1551 || V_1553 -> V_30 . V_1289 != V_1289 )
continue;
if ( V_1553 -> V_51 & ( V_1554 |
V_1555 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1553 -> V_51 & V_1555 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1553 -> V_51 & V_1556 ) {
if ( V_17 -> V_19 &&
! F_90 ( V_17 -> V_19 ) )
return - V_518 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1533 )
return - V_518 ;
}
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_455 ] ) {
V_130 = F_23 ( V_30 -> V_5 [ V_455 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_455 ] ) ;
}
V_7 -> V_1298 = V_30 ;
V_35 = V_7 -> V_18 . V_456 [ V_145 ] . F_361 ( & V_7 -> V_18 , V_17 ,
V_130 , V_47 ) ;
V_7 -> V_1298 = NULL ;
return V_35 ;
}
return - V_505 ;
}
struct V_31 * F_362 ( struct V_18 * V_18 ,
enum V_654 V_52 ,
enum V_1284 V_45 ,
int V_1283 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1298 ) )
return NULL ;
return F_263 ( V_7 , V_1283 ,
V_7 -> V_1298 -> V_469 ,
V_7 -> V_1298 -> V_470 ,
V_52 , V_45 , NULL , V_127 ) ;
}
int F_363 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_265 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_130 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
if ( F_59 ( ! V_7 -> V_1298 ) ) {
F_264 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_130 ) ;
F_66 ( V_32 , V_265 ) ;
return F_76 ( V_32 , V_7 -> V_1298 ) ;
}
static int F_364 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_468 [ 0 ] ;
struct V_1557 * V_1558 = NULL ;
struct V_25 * V_185 = V_30 -> V_468 [ 1 ] ;
T_2 * V_46 , V_47 , V_1559 , V_1560 , V_1561 ;
int V_461 ;
if ( ! V_7 -> V_326 -> V_417 )
return - V_505 ;
if ( V_30 -> V_5 [ V_1562 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1562 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1562 ] ) ;
if ( V_47 % 2 || V_47 < V_1563 ||
V_47 > V_1564 )
return - V_16 ;
V_1558 = F_38 ( sizeof( struct V_1557 ) , V_127 ) ;
if ( ! V_1558 )
return - V_128 ;
V_1559 = ( V_47 - V_1563 ) >> 1 ;
if ( V_1559 ) {
V_1560 = V_1559 *
sizeof( struct V_1565 ) ;
memcpy ( V_1558 -> V_1566 , V_46 , V_1560 ) ;
V_1558 -> V_1559 = V_1559 ;
for ( V_1561 = 0 ; V_1561 < V_1559 ; V_1561 ++ ) {
if ( V_1558 -> V_1566 [ V_1561 ] . V_1567 > 7 ) {
F_41 ( V_1558 ) ;
return - V_16 ;
}
}
V_46 += V_1560 ;
}
memcpy ( V_1558 -> V_1567 , V_46 , V_1563 ) ;
}
F_111 ( V_185 -> V_28 ) ;
V_461 = F_42 ( V_185 -> V_28 ) ;
if ( ! V_461 )
V_461 = F_365 ( V_7 , V_185 , V_1558 ) ;
F_113 ( V_185 -> V_28 ) ;
F_41 ( V_1558 ) ;
return V_461 ;
}
static int F_366 ( const struct V_1568 * V_326 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_185 ;
bool V_1569 = V_326 -> V_1570 & V_1571 ;
if ( V_1569 )
F_14 () ;
if ( V_326 -> V_1570 & V_1572 ) {
V_7 = F_12 ( F_93 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1569 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_468 [ 0 ] = V_7 ;
} else if ( V_326 -> V_1570 & V_1573 ||
V_326 -> V_1570 & V_1574 ) {
F_2 () ;
V_17 = F_1 ( F_93 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1569 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_185 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_326 -> V_1570 & V_1573 ) {
if ( ! V_185 ) {
if ( V_1569 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_468 [ 1 ] = V_185 ;
} else {
V_30 -> V_468 [ 1 ] = V_17 ;
}
if ( V_185 ) {
if ( V_326 -> V_1570 & V_1575 &&
! F_90 ( V_185 ) ) {
if ( V_1569 )
F_20 () ;
return - V_518 ;
}
F_222 ( V_185 ) ;
} else if ( V_326 -> V_1570 & V_1575 ) {
if ( ! V_17 -> V_1533 ) {
if ( V_1569 )
F_20 () ;
return - V_518 ;
}
}
V_30 -> V_468 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_367 ( const struct V_1568 * V_326 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_468 [ 1 ] ) {
if ( V_326 -> V_1570 & V_1574 ) {
struct V_1 * V_17 = V_30 -> V_468 [ 1 ] ;
if ( V_17 -> V_19 )
F_168 ( V_17 -> V_19 ) ;
} else {
F_168 ( V_30 -> V_468 [ 1 ] ) ;
}
}
if ( V_326 -> V_1570 & V_1571 )
F_20 () ;
}
void F_368 ( struct V_6 * V_7 )
{
struct V_31 * V_53 ;
struct V_263 V_264 = {} ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_53 , 0 , 0 , 0 , & V_264 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1576 , V_127 ) ;
}
static int F_369 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1099 * V_1251 = V_7 -> V_1103 ;
struct V_4 * V_1577 ;
int V_145 ;
if ( F_59 ( ! V_1251 ) )
return 0 ;
V_1577 = F_47 ( V_53 , V_1107 ) ;
if ( ! V_1577 )
goto V_59;
for ( V_145 = 0 ; V_145 < V_1251 -> V_1101 ; V_145 ++ ) {
if ( F_51 ( V_53 , V_145 , V_1251 -> V_1108 [ V_145 ] . V_549 , V_1251 -> V_1108 [ V_145 ] . V_551 ) )
goto V_59;
}
F_48 ( V_53 , V_1577 ) ;
V_1577 = F_47 ( V_53 , V_1106 ) ;
if ( ! V_1577 )
goto V_59;
for ( V_145 = 0 ; V_145 < V_1251 -> V_341 ; V_145 ++ ) {
if ( F_28 ( V_53 , V_145 , V_1251 -> V_342 [ V_145 ] -> V_58 ) )
goto V_59;
}
F_48 ( V_53 , V_1577 ) ;
if ( V_1251 -> V_1059 &&
F_51 ( V_53 , V_634 , V_1251 -> V_1060 , V_1251 -> V_1059 ) )
goto V_59;
if ( V_1251 -> V_51 &&
F_28 ( V_53 , V_1112 , V_1251 -> V_51 ) )
goto V_59;
return 0 ;
V_59:
return - V_83 ;
}
static int F_370 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_265 ;
V_265 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_265 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_369 ( V_53 , V_7 ) ;
return F_66 ( V_53 , V_265 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
static int
F_371 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_265 ;
V_265 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_265 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
return F_66 ( V_53 , V_265 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
return - V_460 ;
}
void F_221 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
if ( F_370 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1578 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1579 , V_127 ) ;
}
struct V_31 * F_372 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1580 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return NULL ;
if ( F_370 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1580 ? V_1581 :
V_1168 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_373 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1579 , V_127 ) ;
}
void F_374 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
if ( F_371 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1582 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1579 , V_127 ) ;
}
void F_225 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
if ( F_371 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1579 , V_127 ) ;
}
void F_375 ( struct V_1583 * V_1100 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1584 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_56 ( V_53 , V_1585 , V_1100 -> V_1586 ) )
goto V_59;
if ( V_1100 -> V_1075 [ 0 ] == '0' && V_1100 -> V_1075 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1587 ,
V_1588 ) )
goto V_59;
} else if ( V_1100 -> V_1075 [ 0 ] == '9' && V_1100 -> V_1075 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1587 ,
V_1589 ) )
goto V_59;
} else if ( ( V_1100 -> V_1075 [ 0 ] == '9' && V_1100 -> V_1075 [ 1 ] == '8' ) ||
V_1100 -> V_1590 ) {
if ( F_56 ( V_53 , V_1587 ,
V_1591 ) )
goto V_59;
} else {
if ( F_56 ( V_53 , V_1587 ,
V_1592 ) ||
F_60 ( V_53 , V_968 ,
V_1100 -> V_1075 ) )
goto V_59;
}
if ( V_1100 -> V_14 != V_1593 &&
F_28 ( V_53 , V_26 , V_1100 -> V_14 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_207 () ;
F_376 ( & V_38 , V_53 , 0 ,
V_1594 , V_1595 ) ;
F_210 () ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
static void F_377 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1382 , T_10 V_47 ,
enum V_654 V_52 , T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1378 , V_47 , V_1382 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_378 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1382 ,
T_10 V_47 , T_12 V_1285 )
{
F_377 ( V_7 , V_19 , V_1382 , V_47 ,
V_656 , V_1285 ) ;
}
void F_379 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1382 ,
T_10 V_47 , T_12 V_1285 )
{
F_377 ( V_7 , V_19 , V_1382 , V_47 ,
V_1597 , V_1285 ) ;
}
void F_380 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1382 ,
T_10 V_47 , T_12 V_1285 )
{
F_377 ( V_7 , V_19 , V_1382 , V_47 ,
V_1598 , V_1285 ) ;
}
void F_381 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1382 ,
T_10 V_47 , T_12 V_1285 )
{
F_377 ( V_7 , V_19 , V_1382 , V_47 ,
V_1599 , V_1285 ) ;
}
void F_382 ( struct V_25 * V_185 , const T_2 * V_1382 ,
T_10 V_47 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1600 * V_1601 = ( void * ) V_1382 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_383 ( V_1601 -> V_1602 ) )
V_52 = V_1603 ;
else
V_52 = V_1604 ;
F_384 ( V_185 , V_1382 , V_47 ) ;
F_377 ( V_7 , V_185 , V_1382 , V_47 , V_52 , V_1595 ) ;
}
static void F_385 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_628 , T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1605 ) ||
F_51 ( V_53 , V_510 , V_546 , V_628 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_386 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_628 ,
T_12 V_1285 )
{
F_385 ( V_7 , V_19 , V_656 ,
V_628 , V_1285 ) ;
}
void F_387 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_628 ,
T_12 V_1285 )
{
F_385 ( V_7 , V_19 , V_1597 ,
V_628 , V_1285 ) ;
}
void F_388 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_509 ,
const T_2 * V_1606 , T_10 V_1607 ,
const T_2 * V_1608 , T_10 V_1609 ,
T_3 V_1610 , T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_422 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_509 && F_51 ( V_53 , V_510 , V_546 , V_509 ) ) ||
F_55 ( V_53 , V_1327 , V_1610 ) ||
( V_1606 &&
F_51 ( V_53 , V_1611 , V_1607 , V_1606 ) ) ||
( V_1608 &&
F_51 ( V_53 , V_1612 , V_1609 , V_1608 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_389 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_509 ,
const T_2 * V_1606 , T_10 V_1607 ,
const T_2 * V_1608 , T_10 V_1609 , T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1613 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_509 ) ||
( V_1606 &&
F_51 ( V_53 , V_1611 , V_1607 , V_1606 ) ) ||
( V_1608 &&
F_51 ( V_53 , V_1612 , V_1609 , V_1608 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_390 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1310 ,
const T_2 * V_1059 , T_10 V_1060 , bool V_1614 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_424 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1614 && V_1310 &&
F_55 ( V_53 , V_1267 , V_1310 ) ) ||
( V_1614 &&
F_29 ( V_53 , V_1615 ) ) ||
( V_1059 && F_51 ( V_53 , V_634 , V_1060 , V_1059 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_127 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_391 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_509 ,
T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1616 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_509 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_392 ( struct V_25 * V_185 , const T_2 * V_628 ,
const T_2 * V_1059 , T_2 V_1060 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
if ( F_59 ( V_17 -> V_133 != V_137 ) )
return;
F_393 ( V_185 , V_628 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1617 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_628 ) ||
( V_1060 && V_1059 &&
F_51 ( V_53 , V_634 , V_1060 , V_1059 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_394 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_628 ,
enum V_1618 V_1619 , int V_1620 ,
const T_2 * V_1621 , T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1622 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_628 && F_51 ( V_53 , V_510 , V_546 , V_628 ) ) ||
F_28 ( V_53 , V_119 , V_1619 ) ||
( V_1620 != - 1 &&
F_56 ( V_53 , V_115 , V_1620 ) ) ||
( V_1621 && F_51 ( V_53 , V_114 , 6 , V_1621 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_395 ( struct V_18 * V_18 ,
struct V_54 * V_1623 ,
struct V_54 * V_1624 )
{
struct V_31 * V_53 ;
void * V_265 ;
struct V_4 * V_269 ;
V_53 = F_74 ( V_557 , V_1595 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1625 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_396 ( V_18 ) ) )
goto V_59;
V_269 = F_47 ( V_53 , V_1626 ) ;
if ( ! V_269 )
goto V_59;
if ( F_27 ( V_53 , V_1623 , false ) )
goto V_59;
F_48 ( V_53 , V_269 ) ;
V_269 = F_47 ( V_53 , V_1627 ) ;
if ( ! V_269 )
goto V_59;
if ( F_27 ( V_53 , V_1624 , false ) )
goto V_59;
F_48 ( V_53 , V_269 ) ;
F_66 ( V_53 , V_265 ) ;
F_207 () ;
F_376 ( & V_38 , V_53 , 0 ,
V_1594 , V_1595 ) ;
F_210 () ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
static void F_397 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_598 ,
struct V_54 * V_55 ,
unsigned int V_1333 , T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_488 , V_55 -> V_58 ) ||
F_28 ( V_53 , V_493 ,
V_496 ) ||
F_103 ( V_53 , V_1337 , V_598 ) )
goto V_59;
if ( V_52 == V_1336 &&
F_28 ( V_53 , V_1334 , V_1333 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_398 ( struct V_1 * V_17 , T_1 V_598 ,
struct V_54 * V_55 ,
unsigned int V_1333 , T_12 V_1285 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_399 ( V_17 , V_598 , V_55 , V_1333 ) ;
F_397 ( V_1336 ,
V_7 , V_17 , V_598 , V_55 ,
V_1333 , V_1285 ) ;
}
void F_400 ( struct V_1 * V_17 , T_1 V_598 ,
struct V_54 * V_55 ,
T_12 V_1285 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_401 ( V_17 , V_598 , V_55 ) ;
F_397 ( V_1628 ,
V_7 , V_17 , V_598 , V_55 , 0 , V_1285 ) ;
}
void F_402 ( struct V_25 * V_185 , const T_2 * V_600 ,
struct V_730 * V_731 , T_12 V_1285 )
{
struct V_18 * V_18 = V_185 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_403 ( V_185 , V_600 , V_731 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
if ( F_160 ( V_53 , 0 , 0 , 0 ,
V_7 , V_185 , V_600 , V_731 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
}
void F_404 ( struct V_25 * V_185 , const T_2 * V_600 , T_12 V_1285 )
{
struct V_18 * V_18 = V_185 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
F_405 ( V_185 , V_600 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1629 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_600 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_406 ( struct V_25 * V_185 , const T_2 * V_600 ,
enum V_1630 V_1310 ,
T_12 V_1285 )
{
struct V_18 * V_18 = V_185 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_1631 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1632 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_600 ) ||
F_28 ( V_53 , V_1633 , V_1310 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
static bool F_407 ( struct V_25 * V_185 , T_2 V_52 ,
const T_2 * V_628 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
V_22 V_1531 = F_408 ( V_17 -> V_1524 ) ;
if ( ! V_1531 )
return false ;
V_53 = F_74 ( 100 , V_1285 ) ;
if ( ! V_53 )
return true ;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_628 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_409 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1531 ) ;
return true ;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_410 ( struct V_25 * V_185 ,
const T_2 * V_628 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
bool V_461 ;
F_411 ( V_185 , V_628 ) ;
if ( F_59 ( V_17 -> V_133 != V_134 &&
V_17 -> V_133 != V_136 ) ) {
F_412 ( false ) ;
return false ;
}
V_461 = F_407 ( V_185 , V_1634 ,
V_628 , V_1285 ) ;
F_412 ( V_461 ) ;
return V_461 ;
}
bool F_413 ( struct V_25 * V_185 ,
const T_2 * V_628 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
bool V_461 ;
F_414 ( V_185 , V_628 ) ;
if ( F_59 ( V_17 -> V_133 != V_134 &&
V_17 -> V_133 != V_136 &&
V_17 -> V_133 != V_135 ) ) {
F_412 ( false ) ;
return false ;
}
V_461 = F_407 ( V_185 ,
V_1635 ,
V_628 , V_1285 ) ;
F_412 ( V_461 ) ;
return V_461 ;
}
int F_415 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1531 ,
int V_1636 , int V_1637 ,
const T_2 * V_1382 , T_10 V_47 , V_22 V_51 , T_12 V_1285 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return - V_128 ;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1381 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return - V_128 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_488 , V_1636 ) ||
( V_1637 &&
F_28 ( V_53 , V_1638 , V_1637 ) ) ||
F_51 ( V_53 , V_1378 , V_47 , V_1382 ) ||
( V_51 &&
F_28 ( V_53 , V_1639 , V_51 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
return F_409 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1531 ) ;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
return - V_83 ;
}
void F_416 ( struct V_1 * V_17 , T_1 V_598 ,
const T_2 * V_1382 , T_10 V_47 , bool V_1640 , T_12 V_1285 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_265 ;
F_417 ( V_17 , V_598 , V_1640 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1641 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1378 , V_47 , V_1382 ) ||
F_103 ( V_53 , V_1337 , V_598 ) ||
( V_1640 && F_29 ( V_53 , V_1642 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_418 ( struct V_25 * V_185 ,
enum V_1643 V_1644 ,
T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_903 ;
void * V_265 ;
F_419 ( V_185 , V_1644 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1645 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_185 -> V_20 ) )
goto V_59;
V_903 = F_47 ( V_53 , V_1401 ) ;
if ( ! V_903 )
goto V_59;
if ( F_28 ( V_53 , V_1646 ,
V_1644 ) )
goto V_59;
F_48 ( V_53 , V_903 ) ;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
static void F_420 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_509 ,
const T_2 * V_1522 , T_12 V_1285 )
{
struct V_31 * V_53 ;
struct V_4 * V_1647 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1648 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_509 ) )
goto V_59;
V_1647 = F_47 ( V_53 , V_1510 ) ;
if ( ! V_1647 )
goto V_59;
if ( F_51 ( V_53 , V_1513 ,
V_1514 , V_1522 ) )
goto V_59;
F_48 ( V_53 , V_1647 ) ;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_421 ( struct V_25 * V_185 , const T_2 * V_509 ,
const T_2 * V_1522 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_422 ( V_185 , V_509 ) ;
F_420 ( V_7 , V_185 , V_509 , V_1522 , V_1285 ) ;
}
static void
F_423 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1649 ,
const T_2 * V_509 , bool V_1650 , T_12 V_1285 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1651 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
V_45 = F_47 ( V_53 , V_1652 ) ;
if ( ! V_45 )
goto V_59;
if ( F_28 ( V_53 , V_1653 , V_1649 ) ||
F_51 ( V_53 , V_1654 , V_546 , V_509 ) ||
( V_1650 &&
F_29 ( V_53 , V_1655 ) ) )
goto V_59;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_424 ( struct V_25 * V_185 , int V_1649 ,
const T_2 * V_509 , bool V_1650 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_425 ( V_185 , V_1649 , V_509 , V_1650 ) ;
F_423 ( V_7 , V_185 , V_1649 , V_509 , V_1650 , V_1285 ) ;
}
static void F_426 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_485 * V_486 ,
T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1656 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_59;
if ( F_100 ( V_53 , V_486 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_427 ( struct V_25 * V_185 ,
struct V_485 * V_486 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_428 ( V_185 , V_486 ) ;
if ( F_59 ( V_17 -> V_133 != V_134 &&
V_17 -> V_133 != V_136 &&
V_17 -> V_133 != V_138 &&
V_17 -> V_133 != V_137 ) )
return;
V_17 -> V_486 = * V_486 ;
V_17 -> V_508 = * V_486 ;
F_426 ( V_7 , V_185 , V_486 , V_127 ) ;
}
void F_429 ( struct V_25 * V_185 ,
const T_2 * V_1325 , V_22 V_1657 ,
V_22 V_226 , V_22 V_1393 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_903 ;
void * V_265 ;
V_53 = F_74 ( V_1631 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1645 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_1325 ) )
goto V_59;
V_903 = F_47 ( V_53 , V_1401 ) ;
if ( ! V_903 )
goto V_59;
if ( F_28 ( V_53 , V_1406 , V_1657 ) )
goto V_59;
if ( F_28 ( V_53 , V_1405 , V_226 ) )
goto V_59;
if ( F_28 ( V_53 , V_1407 , V_1393 ) )
goto V_59;
F_48 ( V_53 , V_903 ) ;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void
F_430 ( struct V_6 * V_7 ,
const struct V_485 * V_486 ,
enum V_1658 V_1659 ,
struct V_25 * V_19 , T_12 V_1285 )
{
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1660 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_59;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
}
if ( F_28 ( V_53 , V_1661 , V_1659 ) )
goto V_59;
if ( F_100 ( V_53 , V_486 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_431 ( struct V_25 * V_185 ,
const T_2 * V_1325 , V_22 V_1657 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_903 ;
void * V_265 ;
F_432 ( V_185 , V_1325 , V_1657 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1645 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_1325 ) )
goto V_59;
V_903 = F_47 ( V_53 , V_1401 ) ;
if ( ! V_903 )
goto V_59;
if ( F_28 ( V_53 , V_1662 , V_1657 ) )
goto V_59;
F_48 ( V_53 , V_903 ) ;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_433 ( struct V_25 * V_185 , const T_2 * V_628 ,
T_1 V_598 , bool V_1663 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
F_434 ( V_185 , V_628 , V_598 , V_1663 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1525 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_628 ) ||
F_103 ( V_53 , V_1337 , V_598 ) ||
( V_1663 && F_29 ( V_53 , V_1642 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_435 ( struct V_18 * V_18 ,
const T_2 * V_1664 , T_10 V_47 ,
int V_1636 , int V_1637 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
struct V_1526 * V_1527 ;
F_436 ( V_18 , V_1664 , V_47 , V_1636 , V_1637 ) ;
F_240 ( & V_7 -> V_1530 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1595 ) ;
if ( ! V_53 ) {
F_242 ( & V_7 -> V_1530 ) ;
return;
}
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1381 ) ;
if ( ! V_265 )
goto V_59;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1636 &&
F_28 ( V_53 , V_488 , V_1636 ) ) ||
( V_1637 &&
F_28 ( V_53 , V_1638 , V_1637 ) ) ||
F_51 ( V_53 , V_1378 , V_47 , V_1664 ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_409 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1527 -> V_1531 ) ;
}
F_242 ( & V_7 -> V_1530 ) ;
return;
V_59:
F_242 ( & V_7 -> V_1530 ) ;
if ( V_265 )
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_437 ( struct V_1 * V_17 ,
struct V_1665 * V_1666 ,
T_12 V_1285 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
int V_1442 = 200 ;
F_438 ( V_17 -> V_18 , V_17 , V_1666 ) ;
if ( V_1666 )
V_1442 += V_1666 -> V_1667 ;
V_53 = F_74 ( V_1442 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1668 ) ;
if ( ! V_265 )
goto V_608;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_608;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_608;
if ( V_1666 ) {
struct V_4 * V_1669 ;
V_1669 = F_47 ( V_53 , V_1444 ) ;
if ( ! V_1669 )
goto V_608;
if ( V_1666 -> V_423 &&
F_29 ( V_53 , V_191 ) )
goto V_608;
if ( V_1666 -> V_1446 &&
F_29 ( V_53 , V_193 ) )
goto V_608;
if ( V_1666 -> V_1447 &&
F_29 ( V_53 , V_197 ) )
goto V_608;
if ( V_1666 -> V_1448 &&
F_29 ( V_53 , V_199 ) )
goto V_608;
if ( V_1666 -> V_1449 &&
F_29 ( V_53 , V_201 ) )
goto V_608;
if ( V_1666 -> V_1450 &&
F_29 ( V_53 , V_203 ) )
goto V_608;
if ( V_1666 -> V_1670 >= 0 &&
F_28 ( V_53 , V_213 ,
V_1666 -> V_1670 ) )
goto V_608;
if ( V_1666 -> V_1671 &&
F_29 ( V_53 , V_1672 ) )
goto V_608;
if ( V_1666 -> V_1673 &&
F_29 ( V_53 , V_1674 ) )
goto V_608;
if ( V_1666 -> V_1675 &&
F_29 ( V_53 ,
V_1676 ) )
goto V_608;
if ( V_1666 -> V_1677 ) {
V_22 V_1678 = V_1679 ;
V_22 V_1680 = V_1681 ;
if ( ! V_1666 -> V_1682 ) {
V_1678 =
V_1683 ;
V_1680 =
V_1684 ;
}
if ( V_1666 -> V_1685 &&
F_28 ( V_53 , V_1680 , V_1666 -> V_1685 ) )
goto V_608;
if ( F_51 ( V_53 , V_1678 , V_1666 -> V_1667 ,
V_1666 -> V_1677 ) )
goto V_608;
}
F_48 ( V_53 , V_1669 ) ;
}
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_608:
F_75 ( V_53 ) ;
}
void F_439 ( struct V_25 * V_185 , const T_2 * V_1325 ,
enum V_1330 V_1686 ,
T_3 V_1266 , T_12 V_1285 )
{
struct V_1 * V_17 = V_185 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
F_440 ( V_17 -> V_18 , V_185 , V_1325 , V_1686 ,
V_1266 ) ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1687 ) ;
if ( ! V_265 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_185 -> V_20 ) ||
F_56 ( V_53 , V_1332 , V_1686 ) ||
F_51 ( V_53 , V_510 , V_546 , V_1325 ) ||
( V_1266 > 0 &&
F_55 ( V_53 , V_1267 , V_1266 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_1285 ) ;
return;
V_59:
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
static int F_441 ( struct V_1688 * V_1689 ,
unsigned long V_264 ,
void * V_1690 )
{
struct V_1691 * V_1692 = V_1690 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1526 * V_1527 , * V_24 ;
if ( V_264 != V_1693 )
return V_1694 ;
F_207 () ;
F_442 (rdev, &cfg80211_rdev_list, list) {
F_442 (wdev, &rdev->wdev_list, list)
F_443 ( V_17 , V_1692 -> V_49 ) ;
F_240 ( & V_7 -> V_1530 ) ;
F_444 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1527 -> V_1531 == V_1692 -> V_49 ) {
F_445 ( & V_1527 -> V_591 ) ;
F_41 ( V_1527 ) ;
break;
}
}
F_242 ( & V_7 -> V_1530 ) ;
}
F_210 () ;
return V_1694 ;
}
void F_446 ( struct V_25 * V_19 ,
struct V_1695 * V_1696 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
F_447 ( V_18 , V_19 , V_1696 ) ;
if ( ! V_1696 -> V_1697 )
return;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1698 ) ;
if ( ! V_265 )
goto V_556;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_510 , V_546 , V_1696 -> V_1697 ) )
goto V_556;
if ( V_1696 -> V_1165 &&
F_51 ( V_53 , V_634 , V_1696 -> V_1699 , V_1696 -> V_1165 ) )
goto V_556;
if ( V_1696 -> V_1700 &&
F_51 ( V_53 , V_1701 , V_1696 -> V_1702 ,
V_1696 -> V_1700 ) )
goto V_556;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1596 , V_127 ) ;
return;
V_556:
F_75 ( V_53 ) ;
}
void F_448 ( struct V_1 * V_17 , T_12 V_1285 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_265 ;
V_22 V_1531 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1546 )
return;
V_1531 = V_7 -> V_1546 ;
V_7 -> V_1546 = 0 ;
V_53 = F_74 ( V_557 , V_1285 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1703 ) ;
if ( ! V_265 )
goto V_59;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_59;
F_66 ( V_53 , V_265 ) ;
F_409 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1531 ) ;
return;
V_59:
if ( V_265 )
F_67 ( V_53 , V_265 ) ;
F_75 ( V_53 ) ;
}
void F_449 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_265 ;
V_53 = F_74 ( V_557 , V_127 ) ;
if ( ! V_53 )
return;
V_265 = F_25 ( V_53 , 0 , 0 , 0 , V_1704 ) ;
if ( ! V_265 )
goto V_556;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_103 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_556;
F_66 ( V_53 , V_265 ) ;
F_267 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1596 , V_127 ) ;
return;
V_556:
F_75 ( V_53 ) ;
}
int F_450 ( void )
{
int V_35 ;
V_35 = F_451 ( & V_38 , V_1705 ,
V_1706 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_452 ( & V_1707 ) ;
if ( V_35 )
goto V_1708;
return 0 ;
V_1708:
F_453 ( & V_38 ) ;
return V_35 ;
}
void F_454 ( void )
{
F_455 ( & V_1707 ) ;
F_453 ( & V_38 ) ;
}
