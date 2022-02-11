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
default:
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
static int F_46 ( struct V_31 * V_53 , V_22 V_45 , T_3 V_151 )
{
struct V_4 * V_152 = F_47 ( V_53 , V_45 ) ;
int V_153 ;
if ( ! V_152 )
goto V_61;
V_153 = 0 ;
while ( V_151 ) {
if ( ( V_151 & 1 ) && F_29 ( V_53 , V_153 ) )
goto V_61;
V_151 >>= 1 ;
V_153 ++ ;
}
F_48 ( V_53 , V_152 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_49 ( struct V_18 * V_18 ,
struct V_31 * V_53 ,
bool V_56 )
{
struct V_4 * V_154 ;
int V_153 , V_155 ;
V_154 = F_47 ( V_53 ,
V_156 ) ;
if ( ! V_154 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_18 -> V_157 ; V_153 ++ ) {
const struct V_158 * V_159 ;
struct V_4 * V_160 , * V_161 ;
V_159 = & V_18 -> V_162 [ V_153 ] ;
V_160 = F_47 ( V_53 , V_153 + 1 ) ;
if ( ! V_160 )
goto V_61;
V_161 = F_47 ( V_53 , V_163 ) ;
if ( ! V_161 )
goto V_61;
for ( V_155 = 0 ; V_155 < V_159 -> V_164 ; V_155 ++ ) {
struct V_4 * V_165 ;
V_165 = F_47 ( V_53 , V_155 + 1 ) ;
if ( ! V_165 )
goto V_61;
if ( F_28 ( V_53 , V_166 ,
V_159 -> V_167 [ V_155 ] . V_168 ) )
goto V_61;
if ( F_46 ( V_53 , V_169 ,
V_159 -> V_167 [ V_155 ] . V_170 ) )
goto V_61;
F_48 ( V_53 , V_165 ) ;
}
F_48 ( V_53 , V_161 ) ;
if ( V_159 -> V_171 &&
F_29 ( V_53 , V_172 ) )
goto V_61;
if ( F_28 ( V_53 , V_173 ,
V_159 -> V_174 ) ||
F_28 ( V_53 , V_175 ,
V_159 -> V_176 ) )
goto V_61;
if ( V_56 &&
( F_28 ( V_53 , V_177 ,
V_159 -> V_178 ) ||
F_28 ( V_53 , V_179 ,
V_159 -> V_180 ) ) )
goto V_61;
F_48 ( V_53 , V_160 ) ;
}
F_48 ( V_53 , V_154 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
const struct V_181 * V_182 = V_7 -> V_18 . V_183 -> V_182 ;
struct V_4 * V_184 ;
if ( ! V_182 )
return 0 ;
V_184 = F_47 ( V_53 , V_185 ) ;
if ( ! V_184 )
return - V_91 ;
if ( F_28 ( V_53 , V_186 ,
V_182 -> V_187 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_186 ,
V_182 -> V_187 ) )
return - V_91 ;
if ( V_182 -> V_50 && F_29 ( V_53 , V_188 ) )
return - V_91 ;
if ( V_182 -> V_189 && F_51 ( V_53 , V_190 ,
sizeof( * V_182 -> V_189 ) , V_182 -> V_189 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_191 ,
V_182 -> V_192 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_193 ,
V_182 -> V_194 ) )
return - V_91 ;
F_48 ( V_53 , V_184 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
bool V_56 )
{
struct V_4 * V_195 ;
if ( ! V_7 -> V_18 . V_183 )
return 0 ;
V_195 = F_47 ( V_53 , V_196 ) ;
if ( ! V_195 )
return - V_91 ;
if ( ( ( V_7 -> V_18 . V_183 -> V_51 & V_197 ) &&
F_29 ( V_53 , V_198 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_199 ) &&
F_29 ( V_53 , V_200 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_201 ) &&
F_29 ( V_53 , V_202 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_203 ) &&
F_29 ( V_53 , V_204 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_205 ) &&
F_29 ( V_53 , V_206 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_207 ) &&
F_29 ( V_53 , V_208 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_209 ) &&
F_29 ( V_53 , V_210 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_211 ) &&
F_29 ( V_53 , V_212 ) ) )
return - V_91 ;
if ( V_7 -> V_18 . V_183 -> V_213 ) {
struct V_214 V_215 = {
. V_216 = V_7 -> V_18 . V_183 -> V_213 ,
. V_217 = V_7 -> V_18 . V_183 -> V_218 ,
. V_219 = V_7 -> V_18 . V_183 -> V_220 ,
. V_221 = V_7 -> V_18 . V_183 -> V_221 ,
} ;
if ( F_51 ( V_53 , V_222 ,
sizeof( V_215 ) , & V_215 ) )
return - V_91 ;
}
if ( V_56 && F_50 ( V_7 , V_53 ) )
return - V_91 ;
F_48 ( V_53 , V_195 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_223 V_224 ;
if ( ! V_7 -> V_18 . V_225 )
return 0 ;
V_224 . V_226 = V_7 -> V_18 . V_225 -> V_227 ;
V_224 . V_228 = V_7 -> V_18 . V_225 -> V_228 ;
V_224 . V_215 . V_216 = V_7 -> V_18 . V_225 -> V_213 ;
V_224 . V_215 . V_217 = V_7 -> V_18 . V_225 -> V_218 ;
V_224 . V_215 . V_219 = V_7 -> V_18 . V_225 -> V_220 ;
V_224 . V_215 . V_221 = V_7 -> V_18 . V_225 -> V_221 ;
if ( F_51 ( V_53 , V_229 , sizeof( V_224 ) , & V_224 ) )
return - V_91 ;
return 0 ;
}
static int F_54 ( struct V_31 * V_53 ,
struct V_230 * V_231 )
{
struct V_4 * V_232 , * V_233 ;
struct V_234 * V_235 ;
int V_153 ;
if ( V_231 -> V_236 . V_237 &&
( F_51 ( V_53 , V_238 ,
sizeof( V_231 -> V_236 . V_239 ) ,
& V_231 -> V_236 . V_239 ) ||
F_55 ( V_53 , V_240 ,
V_231 -> V_236 . V_241 ) ||
F_56 ( V_53 , V_242 ,
V_231 -> V_236 . V_243 ) ||
F_56 ( V_53 , V_244 ,
V_231 -> V_236 . V_245 ) ) )
return - V_91 ;
if ( V_231 -> V_246 . V_247 &&
( F_51 ( V_53 , V_248 ,
sizeof( V_231 -> V_246 . V_249 ) ,
& V_231 -> V_246 . V_249 ) ||
F_28 ( V_53 , V_250 ,
V_231 -> V_246 . V_241 ) ) )
return - V_91 ;
V_232 = F_47 ( V_53 , V_251 ) ;
if ( ! V_232 )
return - V_91 ;
for ( V_153 = 0 ; V_153 < V_231 -> V_252 ; V_153 ++ ) {
V_233 = F_47 ( V_53 , V_153 ) ;
if ( ! V_233 )
return - V_91 ;
V_235 = & V_231 -> V_253 [ V_153 ] ;
if ( F_28 ( V_53 , V_254 ,
V_235 -> V_255 ) )
return - V_91 ;
if ( ( V_235 -> V_51 & V_256 ) &&
F_29 ( V_53 ,
V_257 ) )
return - V_91 ;
F_48 ( V_53 , V_233 ) ;
}
F_48 ( V_53 , V_232 ) ;
return 0 ;
}
static int
F_57 ( struct V_31 * V_53 ,
const struct V_258 * V_259 )
{
T_3 V_260 ;
struct V_4 * V_261 , * V_262 ;
enum V_263 V_264 ;
int V_153 ;
if ( ! V_259 )
return 0 ;
V_262 = F_47 ( V_53 , V_265 ) ;
if ( ! V_262 )
return - V_91 ;
for ( V_264 = 0 ; V_264 < V_266 ; V_264 ++ ) {
V_261 = F_47 ( V_53 , V_264 ) ;
if ( ! V_261 )
return - V_91 ;
V_153 = 0 ;
V_260 = V_259 [ V_264 ] . V_267 ;
while ( V_260 ) {
if ( ( V_260 & 1 ) &&
F_55 ( V_53 , V_268 ,
( V_153 << 4 ) | V_269 ) )
return - V_91 ;
V_260 >>= 1 ;
V_153 ++ ;
}
F_48 ( V_53 , V_261 ) ;
}
F_48 ( V_53 , V_262 ) ;
V_262 = F_47 ( V_53 , V_270 ) ;
if ( ! V_262 )
return - V_91 ;
for ( V_264 = 0 ; V_264 < V_266 ; V_264 ++ ) {
V_261 = F_47 ( V_53 , V_264 ) ;
if ( ! V_261 )
return - V_91 ;
V_153 = 0 ;
V_260 = V_259 [ V_264 ] . V_271 ;
while ( V_260 ) {
if ( ( V_260 & 1 ) &&
F_55 ( V_53 , V_268 ,
( V_153 << 4 ) | V_269 ) )
return - V_91 ;
V_260 >>= 1 ;
V_153 ++ ;
}
F_48 ( V_53 , V_261 ) ;
}
F_48 ( V_53 , V_262 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
enum V_272 V_52 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_273 * V_274 )
{
void * V_275 ;
struct V_4 * V_276 , * V_277 ;
struct V_4 * V_278 , * V_279 ;
struct V_4 * V_280 ;
enum V_281 V_282 ;
struct V_54 * V_55 ;
int V_153 ;
const struct V_258 * V_259 =
V_7 -> V_18 . V_259 ;
V_22 V_283 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_275 )
return - V_91 ;
if ( F_59 ( ! V_274 ) )
return - V_16 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_60 ( V_53 , V_284 ,
F_61 ( & V_7 -> V_18 ) ) ||
F_28 ( V_53 , V_285 ,
V_286 ) )
goto V_61;
if ( V_52 != V_287 )
goto V_288;
switch ( V_274 -> V_289 ) {
case 0 :
if ( F_56 ( V_53 , V_290 ,
V_7 -> V_18 . V_291 ) ||
F_56 ( V_53 , V_292 ,
V_7 -> V_18 . V_293 ) ||
F_28 ( V_53 , V_294 ,
V_7 -> V_18 . V_295 ) ||
F_28 ( V_53 , V_296 ,
V_7 -> V_18 . V_297 ) ||
F_56 ( V_53 , V_298 ,
V_7 -> V_18 . V_299 ) ||
F_56 ( V_53 , V_300 ,
V_7 -> V_18 . V_301 ) ||
F_56 ( V_53 , V_302 ,
V_7 -> V_18 . V_303 ) ||
F_55 ( V_53 , V_304 ,
V_7 -> V_18 . V_305 ) ||
F_55 ( V_53 , V_306 ,
V_7 -> V_18 . V_307 ) ||
F_56 ( V_53 , V_308 ,
V_7 -> V_18 . V_309 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_310 ) &&
F_29 ( V_53 , V_311 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_312 ) &&
F_29 ( V_53 , V_313 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_314 ) &&
F_29 ( V_53 , V_315 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_316 ) &&
F_29 ( V_53 , V_317 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_318 ) &&
F_29 ( V_53 , V_319 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_320 ) &&
F_29 ( V_53 , V_321 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 1 :
if ( F_51 ( V_53 , V_323 ,
sizeof( V_22 ) * V_7 -> V_18 . V_324 ,
V_7 -> V_18 . V_325 ) )
goto V_61;
if ( F_56 ( V_53 , V_326 ,
V_7 -> V_18 . V_327 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_328 ) &&
F_29 ( V_53 , V_329 ) )
goto V_61;
if ( F_28 ( V_53 , V_330 ,
V_7 -> V_18 . V_331 ) ||
F_28 ( V_53 , V_332 ,
V_7 -> V_18 . V_333 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_334 ) &&
F_28 ( V_53 , V_335 ,
V_7 -> V_18 . V_336 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_331 ||
V_7 -> V_18 . V_333 ) &&
V_7 -> V_337 -> V_338 ) {
V_22 V_339 = 0 , V_340 = 0 ;
int V_341 ;
V_341 = F_62 ( V_7 , & V_339 , & V_340 ) ;
if ( ! V_341 ) {
if ( F_28 ( V_53 ,
V_342 ,
V_339 ) ||
F_28 ( V_53 ,
V_343 ,
V_340 ) )
goto V_61;
}
}
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 2 :
if ( F_46 ( V_53 , V_344 ,
V_7 -> V_18 . V_345 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 3 :
V_276 = F_47 ( V_53 , V_346 ) ;
if ( ! V_276 )
goto V_61;
for ( V_282 = V_274 -> V_347 ;
V_282 < V_348 ; V_282 ++ ) {
struct V_230 * V_231 ;
V_231 = V_7 -> V_18 . V_349 [ V_282 ] ;
if ( ! V_231 )
continue;
V_277 = F_47 ( V_53 , V_282 ) ;
if ( ! V_277 )
goto V_61;
switch ( V_274 -> V_350 ) {
case 0 :
if ( F_54 ( V_53 , V_231 ) )
goto V_61;
V_274 -> V_350 ++ ;
if ( V_274 -> V_322 )
break;
default:
V_278 = F_47 (
V_53 , V_351 ) ;
if ( ! V_278 )
goto V_61;
for ( V_153 = V_274 -> V_350 - 1 ;
V_153 < V_231 -> V_352 ;
V_153 ++ ) {
V_279 = F_47 ( V_53 , V_153 ) ;
if ( ! V_279 )
goto V_61;
V_55 = & V_231 -> V_353 [ V_153 ] ;
if ( F_27 (
V_53 , V_55 ,
V_274 -> V_322 ) )
goto V_61;
F_48 ( V_53 , V_279 ) ;
if ( V_274 -> V_322 )
break;
}
if ( V_153 < V_231 -> V_352 )
V_274 -> V_350 = V_153 + 2 ;
else
V_274 -> V_350 = 0 ;
F_48 ( V_53 , V_278 ) ;
}
F_48 ( V_53 , V_277 ) ;
if ( V_274 -> V_322 ) {
if ( V_274 -> V_350 )
V_282 -- ;
break;
}
}
F_48 ( V_53 , V_276 ) ;
if ( V_282 < V_348 )
V_274 -> V_347 = V_282 + 1 ;
else
V_274 -> V_347 = 0 ;
if ( V_274 -> V_347 == 0 && V_274 -> V_350 == 0 )
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 4 :
V_280 = F_47 ( V_53 , V_354 ) ;
if ( ! V_280 )
goto V_61;
V_153 = 0 ;
#define F_63 ( T_4 , T_5 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_63 ( V_355 , V_356 ) ;
F_63 ( V_357 , V_358 ) ;
F_63 ( V_359 , V_360 ) ;
F_63 ( V_361 , V_362 ) ;
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
if ( V_7 -> V_18 . V_51 & V_389 )
F_63 ( V_390 , V_391 ) ;
F_63 ( V_392 , V_393 ) ;
F_63 ( V_394 , V_395 ) ;
F_63 ( V_396 , V_397 ) ;
if ( V_7 -> V_18 . V_51 & V_398 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_399 ) )
goto V_61;
}
if ( V_7 -> V_337 -> V_400 || V_7 -> V_337 -> V_361 ||
V_7 -> V_337 -> V_381 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_401 ) )
goto V_61;
}
F_63 ( V_402 , V_403 ) ;
if ( V_7 -> V_18 . V_51 & V_318 ) {
F_63 ( V_404 , V_405 ) ;
F_63 ( V_406 , V_407 ) ;
}
if ( V_7 -> V_18 . V_51 & V_408 )
F_63 ( V_409 , V_410 ) ;
F_63 ( V_411 , V_412 ) ;
F_63 ( V_413 , V_414 ) ;
if ( V_7 -> V_18 . V_51 & V_415 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_416 ) )
goto V_61;
}
F_63 ( V_417 , V_418 ) ;
F_63 ( V_419 , V_420 ) ;
#ifdef F_64
F_63 ( V_421 , V_422 ) ;
#endif
if ( V_274 -> V_322 ) {
F_63 ( V_423 , V_424 ) ;
F_63 ( V_425 , V_426 ) ;
if ( V_7 -> V_18 . V_51 & V_427 )
F_63 ( V_428 , V_429 ) ;
F_63 ( V_430 , V_431 ) ;
}
#undef F_63
if ( V_7 -> V_337 -> V_432 || V_7 -> V_337 -> V_371 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_433 ) )
goto V_61;
}
if ( V_7 -> V_337 -> V_434 || V_7 -> V_337 -> V_375 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_435 ) )
goto V_61;
}
F_48 ( V_53 , V_280 ) ;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 5 :
if ( V_7 -> V_337 -> V_390 &&
( V_7 -> V_18 . V_51 & V_389 ) &&
F_28 ( V_53 ,
V_436 ,
V_7 -> V_18 . V_437 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_438 ) &&
F_29 ( V_53 , V_439 ) )
goto V_61;
if ( F_57 ( V_53 , V_259 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 6 :
#ifdef F_65
if ( F_52 ( V_53 , V_7 , V_274 -> V_322 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
#else
V_274 -> V_289 ++ ;
#endif
case 7 :
if ( F_46 ( V_53 , V_440 ,
V_7 -> V_18 . V_441 ) )
goto V_61;
if ( F_49 ( & V_7 -> V_18 , V_53 ,
V_274 -> V_322 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_51 & V_442 ) &&
F_28 ( V_53 , V_443 ,
V_7 -> V_18 . V_444 ) )
goto V_61;
V_283 = V_7 -> V_18 . V_283 ;
if ( V_274 -> V_322 )
V_283 |= V_445 ;
if ( F_28 ( V_53 , V_446 , V_283 ) )
goto V_61;
if ( V_7 -> V_18 . V_447 &&
F_51 ( V_53 , V_448 ,
sizeof( * V_7 -> V_18 . V_447 ) ,
V_7 -> V_18 . V_447 ) )
goto V_61;
if ( V_7 -> V_18 . V_51 & V_442 &&
V_7 -> V_18 . V_449 &&
F_28 ( V_53 , V_450 ,
V_7 -> V_18 . V_449 ) )
goto V_61;
V_274 -> V_289 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_451 &&
( F_51 ( V_53 , V_452 ,
V_7 -> V_18 . V_453 ,
V_7 -> V_18 . V_451 ) ||
F_51 ( V_53 , V_454 ,
V_7 -> V_18 . V_453 ,
V_7 -> V_18 . V_455 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_456 &&
F_51 ( V_53 , V_457 ,
sizeof( * V_7 -> V_18 . V_456 ) ,
V_7 -> V_18 . V_456 ) )
goto V_61;
V_274 -> V_289 ++ ;
break;
case 10 :
if ( F_53 ( V_53 , V_7 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_458 ) &&
( F_29 ( V_53 , V_459 ) ||
F_29 ( V_53 , V_460 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_461 &&
F_28 ( V_53 , V_462 ,
V_7 -> V_18 . V_461 ) )
goto V_61;
V_274 -> V_289 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_463 ) {
const struct V_464 * V_30 ;
struct V_4 * V_465 ;
V_465 = F_47 ( V_53 , V_466 ) ;
if ( ! V_465 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_463 ; V_153 ++ ) {
V_30 = & V_7 -> V_18 . V_467 [ V_153 ] . V_30 ;
if ( F_51 ( V_53 , V_153 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_465 ) ;
}
if ( V_7 -> V_18 . V_468 ) {
const struct V_464 * V_30 ;
struct V_4 * V_465 ;
V_465 = F_47 ( V_53 ,
V_469 ) ;
if ( ! V_465 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_468 ; V_153 ++ ) {
V_30 = & V_7 -> V_18 . V_470 [ V_153 ] ;
if ( F_51 ( V_53 , V_153 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_465 ) ;
}
V_274 -> V_289 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_51 & V_427 &&
F_56 ( V_53 , V_471 ,
V_7 -> V_18 . V_472 ) )
goto V_61;
V_274 -> V_289 = 0 ;
break;
}
V_288:
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_273 * V_274 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_474 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_474 )
return 0 ;
V_274 -> V_322 = V_95 [ V_475 ] ;
if ( V_95 [ V_26 ] )
V_274 -> V_476 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_274 -> V_476 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
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
V_274 -> V_476 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_474 ;
struct V_273 * V_274 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_274 ) {
V_274 = F_38 ( sizeof( * V_274 ) , V_135 ) ;
if ( ! V_274 ) {
F_20 () ;
return - V_136 ;
}
V_274 -> V_476 = - 1 ;
V_474 = F_68 ( V_32 , V_34 , V_274 ) ;
if ( V_474 ) {
F_41 ( V_274 ) ;
F_20 () ;
return V_474 ;
}
V_34 -> args [ 0 ] = ( long ) V_274 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_274 -> V_477 )
continue;
if ( V_274 -> V_476 != - 1 &&
V_274 -> V_476 != V_7 -> V_14 )
continue;
do {
V_474 = F_58 ( V_7 , V_287 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_478 ,
V_479 , V_274 ) ;
if ( V_474 < 0 ) {
if ( ( V_474 == - V_91 || V_474 == - V_473 ) &&
! V_32 -> V_47 && ! V_274 -> V_322 &&
V_34 -> V_480 < 4096 ) {
V_34 -> V_480 = 4096 ;
V_274 -> V_289 = 0 ;
F_20 () ;
return 1 ;
}
V_105 -- ;
break;
}
} while ( V_274 -> V_289 > 0 );
break;
}
F_20 () ;
V_274 -> V_477 = V_105 ;
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
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_273 V_274 = {} ;
V_53 = F_74 ( 4096 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_58 ( V_7 , V_287 , V_53 ,
V_30 -> V_482 , V_30 -> V_483 , 0 ,
& V_274 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_484 * V_485 )
{
if ( ! V_95 [ V_486 ] || ! V_95 [ V_487 ] ||
! V_95 [ V_488 ] || ! V_95 [ V_489 ] ||
! V_95 [ V_490 ] )
return - V_16 ;
V_485 -> V_491 = F_34 ( V_95 [ V_486 ] ) ;
V_485 -> V_492 = F_78 ( V_95 [ V_487 ] ) ;
V_485 -> V_493 = F_78 ( V_95 [ V_488 ] ) ;
V_485 -> V_494 = F_78 ( V_95 [ V_489 ] ) ;
V_485 -> V_495 = F_34 ( V_95 [ V_490 ] ) ;
if ( V_485 -> V_491 >= V_496 )
return - V_16 ;
return 0 ;
}
static bool F_79 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_141 == V_142 ||
V_17 -> V_141 == V_145 ||
V_17 -> V_141 == V_497 ||
V_17 -> V_141 == V_144 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_498 * V_499 )
{
V_22 V_500 ;
if ( ! V_30 -> V_5 [ V_501 ] )
return - V_16 ;
V_500 = F_4 ( V_30 -> V_5 [ V_501 ] ) ;
V_499 -> V_55 = F_45 ( & V_7 -> V_18 , V_500 ) ;
V_499 -> V_502 = V_503 ;
V_499 -> V_504 = V_500 ;
V_499 -> V_505 = 0 ;
if ( ! V_499 -> V_55 || V_499 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_506 ] ) {
enum V_507 V_508 ;
V_508 = F_4 (
V_30 -> V_5 [ V_506 ] ) ;
switch ( V_508 ) {
case V_509 :
case V_510 :
case V_511 :
case V_512 :
F_81 ( V_499 , V_499 -> V_55 ,
V_508 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_513 ] ) {
V_499 -> V_502 =
F_4 ( V_30 -> V_5 [ V_513 ] ) ;
if ( V_30 -> V_5 [ V_514 ] )
V_499 -> V_504 =
F_4 (
V_30 -> V_5 [ V_514 ] ) ;
if ( V_30 -> V_5 [ V_515 ] )
V_499 -> V_505 =
F_4 (
V_30 -> V_5 [ V_515 ] ) ;
}
if ( ! F_82 ( V_499 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_499 ,
V_62 ) )
return - V_16 ;
if ( ( V_499 -> V_502 == V_516 ||
V_499 -> V_502 == V_517 ) &&
! ( V_7 -> V_18 . V_51 & V_458 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_518 ,
struct V_29 * V_30 )
{
struct V_498 V_499 ;
int V_8 ;
enum V_263 V_141 = V_497 ;
struct V_1 * V_17 = NULL ;
if ( V_518 )
V_17 = V_518 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_519 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_80 ( V_7 , V_30 , & V_499 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_85 ( & V_7 -> V_18 , & V_499 , V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_520 ) {
if ( ! V_518 || ! V_7 -> V_337 -> V_521 ||
! ( V_7 -> V_18 . V_283 &
V_522 ) ) {
V_8 = - V_523 ;
break;
}
if ( V_499 . V_55 != V_17 -> V_524 . V_55 ) {
V_8 = - V_523 ;
break;
}
V_8 = F_86 ( V_7 , V_518 , & V_499 ) ;
if ( V_8 )
break;
}
V_17 -> V_524 = V_499 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_87 ( V_7 , V_17 , & V_499 ) ;
break;
case V_497 :
V_8 = F_88 ( V_7 , & V_499 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_481 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
const T_2 * V_525 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( F_91 ( V_518 ) )
return - V_523 ;
if ( ! V_7 -> V_337 -> V_402 )
return - V_519 ;
if ( V_17 -> V_141 != V_527 )
return - V_519 ;
V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
return F_92 ( V_7 , V_518 , V_525 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_528 = 0 ;
struct V_4 * V_529 ;
V_22 V_530 ;
T_2 V_291 = 0 , V_293 = 0 ;
V_22 V_295 = 0 , V_297 = 0 ;
T_2 V_299 = 0 ;
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
if ( V_30 -> V_5 [ V_284 ] )
V_8 = F_95 (
V_7 , F_23 ( V_30 -> V_5 [ V_284 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_531 ] ) {
struct V_484 V_485 ;
struct V_4 * V_95 [ V_532 + 1 ] ;
if ( ! V_7 -> V_337 -> V_533 )
return - V_519 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_534 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_532 ,
F_23 ( V_529 ) ,
F_24 ( V_529 ) ,
V_535 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_485 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_485 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_501 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_536 ] ) {
struct V_1 * V_537 = V_17 ;
enum V_538 type ;
int V_105 , V_539 = 0 ;
if ( ! ( V_7 -> V_18 . V_283 & V_540 ) )
V_537 = NULL ;
if ( ! V_7 -> V_337 -> V_541 )
return - V_519 ;
V_105 = V_536 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_542 ] &&
( type != V_543 ) )
return - V_16 ;
if ( type != V_543 ) {
V_105 = V_542 ;
V_539 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_537 , type , V_539 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_342 ] &&
V_30 -> V_5 [ V_343 ] ) {
V_22 V_339 , V_340 ;
if ( ( ! V_7 -> V_18 . V_331 &&
! V_7 -> V_18 . V_333 ) ||
! V_7 -> V_337 -> V_544 )
return - V_519 ;
V_339 = F_4 ( V_30 -> V_5 [ V_342 ] ) ;
V_340 = F_4 ( V_30 -> V_5 [ V_343 ] ) ;
if ( ( ~ V_339 && ( V_339 & ~ V_7 -> V_18 . V_331 ) ) ||
( ~ V_340 && ( V_340 & ~ V_7 -> V_18 . V_333 ) ) )
return - V_16 ;
V_339 = V_339 & V_7 -> V_18 . V_331 ;
V_340 = V_340 & V_7 -> V_18 . V_333 ;
V_8 = F_99 ( V_7 , V_339 , V_340 ) ;
if ( V_8 )
return V_8 ;
}
V_530 = 0 ;
if ( V_30 -> V_5 [ V_290 ] ) {
V_291 = F_34 (
V_30 -> V_5 [ V_290 ] ) ;
if ( V_291 == 0 )
return - V_16 ;
V_530 |= V_545 ;
}
if ( V_30 -> V_5 [ V_292 ] ) {
V_293 = F_34 (
V_30 -> V_5 [ V_292 ] ) ;
if ( V_293 == 0 )
return - V_16 ;
V_530 |= V_546 ;
}
if ( V_30 -> V_5 [ V_294 ] ) {
V_295 = F_4 (
V_30 -> V_5 [ V_294 ] ) ;
if ( V_295 < 256 )
return - V_16 ;
if ( V_295 != ( V_22 ) - 1 ) {
V_295 &= ~ 0x1 ;
}
V_530 |= V_547 ;
}
if ( V_30 -> V_5 [ V_296 ] ) {
V_297 = F_4 (
V_30 -> V_5 [ V_296 ] ) ;
V_530 |= V_548 ;
}
if ( V_30 -> V_5 [ V_298 ] ) {
V_299 = F_34 (
V_30 -> V_5 [ V_298 ] ) ;
V_530 |= V_549 ;
}
if ( V_530 ) {
T_2 V_550 , V_551 ;
V_22 V_552 , V_553 ;
T_2 V_554 ;
if ( ! V_7 -> V_337 -> V_555 )
return - V_519 ;
V_550 = V_7 -> V_18 . V_291 ;
V_551 = V_7 -> V_18 . V_293 ;
V_552 = V_7 -> V_18 . V_295 ;
V_553 = V_7 -> V_18 . V_297 ;
V_554 = V_7 -> V_18 . V_299 ;
if ( V_530 & V_545 )
V_7 -> V_18 . V_291 = V_291 ;
if ( V_530 & V_546 )
V_7 -> V_18 . V_293 = V_293 ;
if ( V_530 & V_547 )
V_7 -> V_18 . V_295 = V_295 ;
if ( V_530 & V_548 )
V_7 -> V_18 . V_297 = V_297 ;
if ( V_530 & V_549 )
V_7 -> V_18 . V_299 = V_299 ;
V_8 = F_100 ( V_7 , V_530 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_291 = V_550 ;
V_7 -> V_18 . V_293 = V_551 ;
V_7 -> V_18 . V_295 = V_552 ;
V_7 -> V_18 . V_297 = V_553 ;
V_7 -> V_18 . V_299 = V_554 ;
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
const struct V_498 * V_499 )
{
F_59 ( ! F_82 ( V_499 ) ) ;
if ( F_28 ( V_53 , V_501 ,
V_499 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_499 -> V_502 ) {
case V_503 :
case V_556 :
case V_557 :
if ( F_28 ( V_53 , V_506 ,
F_102 ( V_499 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_513 , V_499 -> V_502 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_514 , V_499 -> V_504 ) )
return - V_91 ;
if ( V_499 -> V_505 &&
F_28 ( V_53 , V_515 , V_499 -> V_505 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_25 * V_518 = V_17 -> V_19 ;
void * V_275 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_558 ) ;
if ( ! V_275 )
return - 1 ;
if ( V_518 &&
( F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_60 ( V_53 , V_559 , V_518 -> V_560 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_561 , V_17 -> V_141 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_526 , V_562 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_285 ,
V_7 -> V_563 ^
( V_286 << 2 ) ) )
goto V_61;
if ( V_7 -> V_337 -> V_564 ) {
int V_474 ;
struct V_498 V_499 ;
V_474 = F_106 ( V_7 , V_17 , & V_499 ) ;
if ( V_474 == 0 ) {
if ( F_101 ( V_53 , & V_499 ) )
goto V_61;
}
}
if ( V_17 -> V_565 ) {
if ( F_51 ( V_53 , V_566 , V_17 -> V_565 , V_17 -> V_567 ) )
goto V_61;
}
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
static int F_107 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_568 = 0 ;
int V_569 = 0 ;
int V_570 = V_34 -> args [ 0 ] ;
int V_571 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_568 < V_570 ) {
V_568 ++ ;
continue;
}
V_569 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_569 < V_571 ) {
V_569 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_478 , V_479 ,
V_7 , V_17 ) < 0 ) {
goto V_572;
}
V_569 ++ ;
}
V_568 ++ ;
}
V_572:
F_20 () ;
V_34 -> args [ 0 ] = V_568 ;
V_34 -> args [ 1 ] = V_569 ;
return V_32 -> V_47 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_103 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_7 , V_17 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_109 ( struct V_4 * V_574 , V_22 * V_575 )
{
struct V_4 * V_51 [ V_576 + 1 ] ;
int V_577 ;
* V_575 = 0 ;
if ( ! V_574 )
return - V_16 ;
if ( F_33 ( V_51 , V_576 ,
V_574 , V_578 ) )
return - V_16 ;
for ( V_577 = 1 ; V_577 <= V_576 ; V_577 ++ )
if ( V_51 [ V_577 ] )
* V_575 |= ( 1 << V_577 ) ;
return 0 ;
}
static int F_110 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_579 ,
enum V_263 V_141 )
{
if ( ! V_579 ) {
if ( V_19 && ( V_19 -> V_580 & V_581 ) )
return - V_523 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_51 & V_582 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_51 & V_583 )
return 0 ;
break;
default:
break;
}
return - V_519 ;
}
static int F_111 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_584 V_137 ;
int V_35 ;
enum V_263 V_585 , V_586 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
V_22 V_587 , * V_51 = NULL ;
bool V_588 = false ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_585 = V_586 = V_518 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_561 ] ) {
V_586 = F_4 ( V_30 -> V_5 [ V_561 ] ) ;
if ( V_585 != V_586 )
V_588 = true ;
if ( V_586 > V_589 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_590 ] ) {
struct V_1 * V_17 = V_518 -> V_28 ;
if ( V_586 != V_145 )
return - V_16 ;
if ( F_91 ( V_518 ) )
return - V_523 ;
F_112 ( V_17 ) ;
F_113 ( V_591 !=
V_592 ) ;
V_17 -> V_593 =
F_24 ( V_30 -> V_5 [ V_590 ] ) ;
memcpy ( V_17 -> V_567 , F_23 ( V_30 -> V_5 [ V_590 ] ) ,
V_17 -> V_593 ) ;
F_114 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_594 ] ) {
V_137 . V_579 = ! ! F_34 ( V_30 -> V_5 [ V_594 ] ) ;
V_588 = true ;
V_35 = F_110 ( V_7 , V_518 , V_137 . V_579 , V_586 ) ;
if ( V_35 )
return V_35 ;
} else {
V_137 . V_579 = - 1 ;
}
if ( V_30 -> V_5 [ V_595 ] ) {
if ( V_586 != V_497 )
return - V_16 ;
V_35 = F_109 ( V_30 -> V_5 [ V_595 ] ,
& V_587 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_587 ;
V_588 = true ;
}
if ( V_51 && ( * V_51 & V_596 ) &&
! ( V_7 -> V_18 . V_283 & V_597 ) )
return - V_519 ;
if ( V_588 )
V_35 = F_115 ( V_7 , V_518 , V_586 , V_51 , & V_137 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_137 . V_579 != - 1 )
V_518 -> V_28 -> V_579 = V_137 . V_579 ;
return V_35 ;
}
static int F_116 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_584 V_137 ;
struct V_1 * V_17 ;
struct V_31 * V_53 ;
int V_35 ;
enum V_263 type = V_598 ;
V_22 V_51 ;
F_117 ( V_7 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_561 ] ) {
type = F_4 ( V_30 -> V_5 [ V_561 ] ) ;
if ( type > V_589 )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_355 ||
! ( V_7 -> V_18 . V_345 & ( 1 << type ) ) )
return - V_519 ;
if ( type == V_599 && V_30 -> V_5 [ V_526 ] ) {
F_118 ( V_137 . V_600 , V_30 -> V_5 [ V_526 ] ,
V_562 ) ;
if ( ! F_119 ( V_137 . V_600 ) )
return - V_601 ;
}
if ( V_30 -> V_5 [ V_594 ] ) {
V_137 . V_579 = ! ! F_34 ( V_30 -> V_5 [ V_594 ] ) ;
V_35 = F_110 ( V_7 , NULL , V_137 . V_579 , type ) ;
if ( V_35 )
return V_35 ;
}
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_35 = F_109 ( type == V_497 ?
V_30 -> V_5 [ V_595 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_596 ) &&
! ( V_7 -> V_18 . V_283 & V_597 ) )
return - V_519 ;
V_17 = F_120 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_559 ] ) ,
type , V_35 ? NULL : & V_51 , & V_137 ) ;
if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_602 ] )
V_17 -> V_603 = V_30 -> V_482 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_590 ] )
break;
F_112 ( V_17 ) ;
F_113 ( V_591 !=
V_592 ) ;
V_17 -> V_593 =
F_24 ( V_30 -> V_5 [ V_590 ] ) ;
memcpy ( V_17 -> V_567 , F_23 ( V_30 -> V_5 [ V_590 ] ) ,
V_17 -> V_593 ) ;
F_114 ( V_17 ) ;
break;
case V_599 :
F_121 ( & V_17 -> V_604 ) ;
F_122 ( & V_17 -> V_605 ) ;
F_123 ( & V_17 -> V_606 ) ;
F_122 ( & V_17 -> V_607 ) ;
F_123 ( & V_17 -> V_608 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_124 ( & V_17 -> V_609 , & V_7 -> V_610 ) ;
V_7 -> V_563 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_7 , V_17 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_125 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_611 )
return - V_519 ;
if ( ! V_17 -> V_19 )
V_30 -> V_481 [ 1 ] = NULL ;
return F_126 ( V_7 , V_17 ) ;
}
static int F_127 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_3 V_612 ;
if ( ! V_30 -> V_5 [ V_613 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_413 )
return - V_519 ;
V_612 = F_78 ( V_30 -> V_5 [ V_613 ] ) ;
return F_128 ( V_7 , V_518 , V_612 ) ;
}
static void F_129 ( void * V_159 , struct V_614 * V_137 )
{
struct V_4 * V_92 ;
struct V_615 * V_616 = V_159 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_616 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_616 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_616 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_616 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_616 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_616 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_616 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_616 -> V_53 , V_123 , V_616 -> V_105 ) )
goto V_61;
F_48 ( V_616 -> V_53 , V_92 ) ;
return;
V_61:
V_616 -> error = 1 ;
}
static int F_130 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
int V_35 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 V_617 = 0 ;
const T_2 * V_618 = NULL ;
bool V_619 ;
struct V_615 V_616 = {
. error = 0 ,
} ;
void * V_275 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_617 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_617 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_526 ] )
V_618 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_619 = ! ! V_618 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_620 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_620 >= V_114 )
return - V_16 ;
if ( V_620 != V_621 &&
V_620 != V_622 )
return - V_16 ;
V_619 = V_620 == V_622 ;
}
if ( ! V_7 -> V_337 -> V_623 )
return - V_519 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_624 ) ;
if ( ! V_275 )
goto V_61;
V_616 . V_53 = V_53 ;
V_616 . V_105 = V_617 ;
if ( F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_617 ) )
goto V_61;
if ( V_618 &&
F_51 ( V_53 , V_526 , V_562 , V_618 ) )
goto V_61;
if ( V_619 && V_618 &&
! ( V_7 -> V_18 . V_51 & V_310 ) )
return - V_625 ;
V_35 = F_131 ( V_7 , V_518 , V_617 , V_619 , V_618 , & V_616 ,
F_129 ) ;
if ( V_35 )
goto V_626;
if ( V_616 . error )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_626:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_132 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_112 ( V_518 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_337 -> V_627 ) {
V_35 = - V_519 ;
goto V_572;
}
V_35 = F_42 ( V_518 -> V_28 ) ;
if ( V_35 )
goto V_572;
V_35 = F_133 ( V_7 , V_518 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_572;
#ifdef F_134
V_518 -> V_28 -> V_628 . V_629 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_572;
}
if ( ! V_7 -> V_337 -> V_630 ) {
V_35 = - V_519 ;
goto V_572;
}
V_35 = F_42 ( V_518 -> V_28 ) ;
if ( V_35 )
goto V_572;
V_35 = F_135 ( V_7 , V_518 , V_92 . V_105 ) ;
if ( V_35 )
goto V_572;
#ifdef F_134
V_518 -> V_28 -> V_628 . V_631 = V_92 . V_105 ;
#endif
}
V_572:
F_114 ( V_518 -> V_28 ) ;
return V_35 ;
}
static int F_136 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
int V_35 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_618 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_526 ] )
V_618 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_618 )
V_92 . type = V_622 ;
else
V_92 . type = V_621 ;
}
if ( V_92 . type != V_622 &&
V_92 . type != V_621 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_359 )
return - V_519 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_622 ,
V_618 ) )
return - V_16 ;
F_112 ( V_518 -> V_28 ) ;
V_35 = F_42 ( V_518 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_137 ( V_7 , V_518 , V_92 . V_105 ,
V_92 . type == V_622 ,
V_618 , & V_92 . V_107 ) ;
F_114 ( V_518 -> V_28 ) ;
return V_35 ;
}
static int F_138 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
int V_35 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 * V_618 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_526 ] )
V_618 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_618 )
V_92 . type = V_622 ;
else
V_92 . type = V_621 ;
}
if ( V_92 . type != V_622 &&
V_92 . type != V_621 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_632 )
return - V_519 ;
F_112 ( V_518 -> V_28 ) ;
V_35 = F_42 ( V_518 -> V_28 ) ;
if ( V_92 . type == V_622 && V_618 &&
! ( V_7 -> V_18 . V_51 & V_310 ) )
V_35 = - V_625 ;
if ( ! V_35 )
V_35 = F_139 ( V_7 , V_518 , V_92 . V_105 ,
V_92 . type == V_622 ,
V_618 ) ;
#ifdef F_134
if ( ! V_35 ) {
if ( V_92 . V_105 == V_518 -> V_28 -> V_628 . V_629 )
V_518 -> V_28 -> V_628 . V_629 = - 1 ;
else if ( V_92 . V_105 == V_518 -> V_28 -> V_628 . V_631 )
V_518 -> V_28 -> V_628 . V_631 = - 1 ;
}
#endif
F_114 ( V_518 -> V_28 ) ;
return V_35 ;
}
static int F_140 ( struct V_4 * V_633 )
{
struct V_4 * V_45 ;
int V_634 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_562 )
return - V_16 ;
V_634 ++ ;
}
return V_634 ;
}
static struct V_635 * F_141 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_636 V_637 ;
struct V_4 * V_45 ;
struct V_635 * V_638 ;
int V_153 = 0 , V_634 , V_24 ;
if ( ! V_18 -> V_449 )
return F_3 ( - V_519 ) ;
if ( ! V_30 -> V_5 [ V_639 ] )
return F_3 ( - V_16 ) ;
V_637 = F_4 ( V_30 -> V_5 [ V_639 ] ) ;
if ( V_637 != V_640 &&
V_637 != V_641 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_642 ] )
return F_3 ( - V_16 ) ;
V_634 = F_140 ( V_30 -> V_5 [ V_642 ] ) ;
if ( V_634 < 0 )
return F_3 ( V_634 ) ;
if ( V_634 > V_18 -> V_449 )
return F_3 ( - V_643 ) ;
V_638 = F_38 ( sizeof( * V_638 ) + ( sizeof( struct V_644 ) * V_634 ) ,
V_135 ) ;
if ( ! V_638 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_638 -> V_645 [ V_153 ] . V_646 , F_23 ( V_45 ) , V_562 ) ;
V_153 ++ ;
}
V_638 -> V_647 = V_634 ;
V_638 -> V_637 = V_637 ;
return V_638 ;
}
static int F_142 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_635 * V_638 ;
int V_35 ;
if ( V_518 -> V_28 -> V_141 != V_142 &&
V_518 -> V_28 -> V_141 != V_144 )
return - V_519 ;
if ( ! V_518 -> V_28 -> V_520 )
return - V_16 ;
V_638 = F_141 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_638 ) )
return F_18 ( V_638 ) ;
V_35 = F_143 ( V_7 , V_518 , V_638 ) ;
F_41 ( V_638 ) ;
return V_35 ;
}
static int F_144 ( struct V_4 * V_5 [] ,
struct V_648 * V_649 )
{
bool V_650 = false ;
if ( ! F_22 ( V_5 [ V_651 ] ) ||
! F_22 ( V_5 [ V_652 ] ) ||
! F_22 ( V_5 [ V_653 ] ) ||
! F_22 ( V_5 [ V_654 ] ) )
return - V_16 ;
memset ( V_649 , 0 , sizeof( * V_649 ) ) ;
if ( V_5 [ V_655 ] ) {
V_649 -> V_656 = F_23 ( V_5 [ V_655 ] ) ;
V_649 -> V_657 = F_24 ( V_5 [ V_655 ] ) ;
if ( ! V_649 -> V_657 )
return - V_16 ;
V_650 = true ;
}
if ( V_5 [ V_651 ] ) {
V_649 -> V_658 = F_23 ( V_5 [ V_651 ] ) ;
V_649 -> V_659 = F_24 ( V_5 [ V_651 ] ) ;
V_650 = true ;
}
if ( ! V_650 )
return - V_16 ;
if ( V_5 [ V_652 ] ) {
V_649 -> V_660 = F_23 ( V_5 [ V_652 ] ) ;
V_649 -> V_661 = F_24 ( V_5 [ V_652 ] ) ;
}
if ( V_5 [ V_653 ] ) {
V_649 -> V_662 =
F_23 ( V_5 [ V_653 ] ) ;
V_649 -> V_663 =
F_24 ( V_5 [ V_653 ] ) ;
}
if ( V_5 [ V_654 ] ) {
V_649 -> V_664 =
F_23 ( V_5 [ V_654 ] ) ;
V_649 -> V_665 =
F_24 ( V_5 [ V_654 ] ) ;
}
if ( V_5 [ V_666 ] ) {
V_649 -> V_667 = F_23 ( V_5 [ V_666 ] ) ;
V_649 -> V_668 = F_24 ( V_5 [ V_666 ] ) ;
}
return 0 ;
}
static bool F_145 ( struct V_6 * V_7 ,
struct V_669 * V_137 )
{
struct V_1 * V_17 ;
bool V_474 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_524 . V_55 )
continue;
V_137 -> V_499 = V_17 -> V_524 ;
V_474 = true ;
break;
}
return V_474 ;
}
static bool F_146 ( struct V_6 * V_7 ,
enum V_670 V_671 ,
enum V_272 V_52 )
{
if ( V_671 > V_672 )
return false ;
switch ( V_52 ) {
case V_673 :
if ( ! ( V_7 -> V_18 . V_283 & V_674 ) &&
V_671 == V_675 )
return false ;
return true ;
case V_433 :
case V_676 :
if ( V_671 == V_675 )
return false ;
return true ;
default:
return false ;
}
}
static int F_147 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_669 V_137 ;
int V_35 ;
if ( V_518 -> V_28 -> V_141 != V_142 &&
V_518 -> V_28 -> V_141 != V_144 )
return - V_519 ;
if ( ! V_7 -> V_337 -> V_361 )
return - V_519 ;
if ( V_17 -> V_520 )
return - V_677 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_678 ] ||
! V_30 -> V_5 [ V_679 ] ||
! V_30 -> V_5 [ V_655 ] )
return - V_16 ;
V_35 = F_144 ( V_30 -> V_5 , & V_137 . V_680 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_520 =
F_4 ( V_30 -> V_5 [ V_678 ] ) ;
V_137 . V_681 =
F_4 ( V_30 -> V_5 [ V_679 ] ) ;
V_35 = F_148 ( V_7 , V_137 . V_520 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_566 ] ) {
V_137 . V_567 = F_23 ( V_30 -> V_5 [ V_566 ] ) ;
V_137 . V_565 =
F_24 ( V_30 -> V_5 [ V_566 ] ) ;
if ( V_137 . V_565 == 0 ||
V_137 . V_565 > V_591 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_682 ] ) {
V_137 . V_683 = F_4 (
V_30 -> V_5 [ V_682 ] ) ;
if ( V_137 . V_683 != V_684 &&
V_137 . V_683 != V_685 &&
V_137 . V_683 != V_686 )
return - V_16 ;
}
V_137 . V_687 = ! ! V_30 -> V_5 [ V_688 ] ;
if ( V_30 -> V_5 [ V_689 ] ) {
V_137 . V_671 = F_4 (
V_30 -> V_5 [ V_689 ] ) ;
if ( ! F_146 ( V_7 , V_137 . V_671 ,
V_676 ) )
return - V_16 ;
} else
V_137 . V_671 = V_690 ;
V_35 = F_149 ( V_7 , V_30 , & V_137 . V_691 ,
V_692 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_693 ] ) {
if ( ! ( V_7 -> V_18 . V_283 & V_694 ) )
return - V_519 ;
V_137 . V_695 = F_78 (
V_30 -> V_5 [ V_693 ] ) ;
}
if ( V_30 -> V_5 [ V_696 ] ) {
if ( V_518 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_697 =
F_34 ( V_30 -> V_5 [ V_696 ] ) ;
if ( V_137 . V_697 > 127 )
return - V_16 ;
if ( V_137 . V_697 != 0 &&
! ( V_7 -> V_18 . V_283 & V_698 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_699 ] ) {
T_2 V_24 ;
if ( V_518 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_699 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_700 = V_24 ;
if ( V_137 . V_700 != 0 &&
! ( V_7 -> V_18 . V_283 & V_701 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_501 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_499 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_524 . V_55 ) {
V_137 . V_499 = V_17 -> V_524 ;
} else if ( ! F_145 ( V_7 , & V_137 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_499 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_639 ] ) {
V_137 . V_638 = F_141 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_638 ) )
return F_18 ( V_137 . V_638 ) ;
}
F_112 ( V_17 ) ;
V_35 = F_150 ( V_7 , V_518 , & V_137 ) ;
if ( ! V_35 ) {
V_17 -> V_524 = V_137 . V_499 ;
V_17 -> V_520 = V_137 . V_520 ;
V_17 -> V_499 = V_137 . V_499 ;
V_17 -> V_565 = V_137 . V_565 ;
memcpy ( V_17 -> V_567 , V_137 . V_567 , V_17 -> V_565 ) ;
}
F_114 ( V_17 ) ;
F_41 ( V_137 . V_638 ) ;
return V_35 ;
}
static int F_151 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_648 V_137 ;
int V_35 ;
if ( V_518 -> V_28 -> V_141 != V_142 &&
V_518 -> V_28 -> V_141 != V_144 )
return - V_519 ;
if ( ! V_7 -> V_337 -> V_702 )
return - V_519 ;
if ( ! V_17 -> V_520 )
return - V_16 ;
V_35 = F_144 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
V_35 = F_152 ( V_7 , V_518 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_153 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
return F_154 ( V_7 , V_518 , false ) ;
}
static int F_155 ( struct V_29 * V_30 ,
enum V_263 V_141 ,
struct V_703 * V_137 )
{
struct V_4 * V_51 [ V_704 + 1 ] ;
struct V_4 * V_574 ;
int V_577 ;
V_574 = V_30 -> V_5 [ V_705 ] ;
if ( V_574 ) {
struct V_706 * V_707 ;
V_707 = F_23 ( V_574 ) ;
V_137 -> V_708 = V_707 -> V_709 ;
V_137 -> V_710 = V_707 -> V_711 ;
V_137 -> V_710 &= V_137 -> V_708 ;
if ( ( V_137 -> V_708 |
V_137 -> V_710 ) & F_156 ( V_712 ) )
return - V_16 ;
return 0 ;
}
V_574 = V_30 -> V_5 [ V_713 ] ;
if ( ! V_574 )
return 0 ;
if ( F_33 ( V_51 , V_704 ,
V_574 , V_714 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_708 = F_156 ( V_715 ) |
F_156 ( V_716 ) |
F_156 ( V_717 ) |
F_156 ( V_718 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_708 = F_156 ( V_715 ) |
F_156 ( V_719 ) ;
break;
case V_145 :
V_137 -> V_708 = F_156 ( V_720 ) |
F_156 ( V_718 ) |
F_156 ( V_715 ) ;
default:
return - V_16 ;
}
for ( V_577 = 1 ; V_577 <= V_704 ; V_577 ++ ) {
if ( V_51 [ V_577 ] ) {
V_137 -> V_710 |= ( 1 << V_577 ) ;
if ( V_577 > V_721 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_157 ( struct V_31 * V_53 , struct V_722 * V_30 ,
int V_45 )
{
struct V_4 * V_235 ;
V_22 V_255 ;
T_3 V_723 ;
V_235 = F_47 ( V_53 , V_45 ) ;
if ( ! V_235 )
return false ;
V_255 = F_158 ( V_30 ) ;
V_723 = V_255 < ( 1UL << 16 ) ? V_255 : 0 ;
if ( V_255 > 0 &&
F_28 ( V_53 , V_724 , V_255 ) )
return false ;
if ( V_723 > 0 &&
F_55 ( V_53 , V_725 , V_723 ) )
return false ;
if ( V_30 -> V_51 & V_726 ) {
if ( F_56 ( V_53 , V_727 , V_30 -> V_239 ) )
return false ;
if ( V_30 -> V_51 & V_728 &&
F_29 ( V_53 , V_729 ) )
return false ;
if ( V_30 -> V_51 & V_730 &&
F_29 ( V_53 , V_731 ) )
return false ;
} else if ( V_30 -> V_51 & V_732 ) {
if ( F_56 ( V_53 , V_733 , V_30 -> V_239 ) )
return false ;
if ( F_56 ( V_53 , V_734 , V_30 -> V_735 ) )
return false ;
if ( V_30 -> V_51 & V_728 &&
F_29 ( V_53 , V_729 ) )
return false ;
if ( V_30 -> V_51 & V_736 &&
F_29 ( V_53 , V_737 ) )
return false ;
if ( V_30 -> V_51 & V_738 &&
F_29 ( V_53 , V_739 ) )
return false ;
if ( V_30 -> V_51 & V_740 &&
F_29 ( V_53 , V_741 ) )
return false ;
if ( V_30 -> V_51 & V_730 &&
F_29 ( V_53 , V_731 ) )
return false ;
}
F_48 ( V_53 , V_235 ) ;
return true ;
}
static bool F_159 ( struct V_31 * V_53 , T_2 V_709 , T_6 * signal ,
int V_742 )
{
void * V_45 ;
int V_153 = 0 ;
if ( ! V_709 )
return true ;
V_45 = F_47 ( V_53 , V_742 ) ;
if ( ! V_45 )
return false ;
for ( V_153 = 0 ; V_153 < V_743 ; V_153 ++ ) {
if ( ! ( V_709 & F_156 ( V_153 ) ) )
continue;
if ( F_56 ( V_53 , V_153 , signal [ V_153 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_160 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_518 ,
const T_2 * V_618 , struct V_744 * V_745 )
{
void * V_275 ;
struct V_4 * V_746 , * V_747 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_748 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_618 ) ||
F_28 ( V_53 , V_285 , V_745 -> V_749 ) )
goto V_61;
V_746 = F_47 ( V_53 , V_750 ) ;
if ( ! V_746 )
goto V_61;
if ( ( V_745 -> V_751 & V_752 ) &&
F_28 ( V_53 , V_753 ,
V_745 -> V_754 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_755 ) &&
F_28 ( V_53 , V_756 ,
V_745 -> V_757 ) )
goto V_61;
if ( ( V_745 -> V_751 & ( V_758 |
V_759 ) ) &&
F_28 ( V_53 , V_760 ,
( V_22 ) V_745 -> V_761 ) )
goto V_61;
if ( ( V_745 -> V_751 & ( V_762 |
V_763 ) ) &&
F_28 ( V_53 , V_764 ,
( V_22 ) V_745 -> V_765 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_759 ) &&
F_104 ( V_53 , V_766 ,
V_745 -> V_761 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_763 ) &&
F_104 ( V_53 , V_767 ,
V_745 -> V_765 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_768 ) &&
F_55 ( V_53 , V_769 , V_745 -> V_770 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_771 ) &&
F_55 ( V_53 , V_772 , V_745 -> V_773 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_774 ) &&
F_56 ( V_53 , V_775 ,
V_745 -> V_776 ) )
goto V_61;
switch ( V_7 -> V_18 . V_777 ) {
case V_778 :
if ( ( V_745 -> V_751 & V_779 ) &&
F_56 ( V_53 , V_780 ,
V_745 -> signal ) )
goto V_61;
if ( ( V_745 -> V_751 & V_781 ) &&
F_56 ( V_53 , V_782 ,
V_745 -> V_783 ) )
goto V_61;
break;
default:
break;
}
if ( V_745 -> V_751 & V_784 ) {
if ( ! F_159 ( V_53 , V_745 -> V_785 ,
V_745 -> V_786 ,
V_787 ) )
goto V_61;
}
if ( V_745 -> V_751 & V_788 ) {
if ( ! F_159 ( V_53 , V_745 -> V_785 ,
V_745 -> V_789 ,
V_790 ) )
goto V_61;
}
if ( V_745 -> V_751 & V_791 ) {
if ( ! F_157 ( V_53 , & V_745 -> V_792 ,
V_793 ) )
goto V_61;
}
if ( V_745 -> V_751 & V_794 ) {
if ( ! F_157 ( V_53 , & V_745 -> V_795 ,
V_796 ) )
goto V_61;
}
if ( ( V_745 -> V_751 & V_797 ) &&
F_28 ( V_53 , V_798 ,
V_745 -> V_799 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_800 ) &&
F_28 ( V_53 , V_801 ,
V_745 -> V_802 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_803 ) &&
F_28 ( V_53 , V_804 ,
V_745 -> V_805 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_806 ) &&
F_28 ( V_53 , V_807 ,
V_745 -> V_808 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_809 ) &&
F_28 ( V_53 , V_810 ,
V_745 -> V_811 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_812 ) &&
F_28 ( V_53 , V_813 ,
V_745 -> V_814 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_815 ) &&
F_28 ( V_53 , V_816 ,
V_745 -> V_817 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_818 ) &&
F_28 ( V_53 , V_819 ,
V_745 -> V_820 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_821 ) &&
F_28 ( V_53 , V_822 ,
V_745 -> V_823 ) )
goto V_61;
if ( V_745 -> V_751 & V_824 ) {
V_747 = F_47 ( V_53 , V_825 ) ;
if ( ! V_747 )
goto V_61;
if ( ( ( V_745 -> V_747 . V_51 & V_826 ) &&
F_29 ( V_53 , V_827 ) ) ||
( ( V_745 -> V_747 . V_51 & V_828 ) &&
F_29 ( V_53 , V_829 ) ) ||
( ( V_745 -> V_747 . V_51 & V_830 ) &&
F_29 ( V_53 , V_831 ) ) ||
F_56 ( V_53 , V_832 ,
V_745 -> V_747 . V_681 ) ||
F_55 ( V_53 , V_833 ,
V_745 -> V_747 . V_520 ) )
goto V_61;
F_48 ( V_53 , V_747 ) ;
}
if ( ( V_745 -> V_751 & V_834 ) &&
F_51 ( V_53 , V_835 ,
sizeof( struct V_706 ) ,
& V_745 -> V_707 ) )
goto V_61;
if ( ( V_745 -> V_751 & V_836 ) &&
F_104 ( V_53 , V_837 ,
V_745 -> V_838 ) )
goto V_61;
F_48 ( V_53 , V_746 ) ;
if ( ( V_745 -> V_751 & V_839 ) &&
F_51 ( V_53 , V_652 , V_745 -> V_840 ,
V_745 -> V_841 ) )
goto V_61;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
static int F_161 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_744 V_745 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_618 [ V_562 ] ;
int V_842 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_843;
}
if ( ! V_7 -> V_337 -> V_844 ) {
V_35 = - V_519 ;
goto V_843;
}
while ( 1 ) {
memset ( & V_745 , 0 , sizeof( V_745 ) ) ;
V_35 = F_162 ( V_7 , V_17 -> V_19 , V_842 ,
V_618 , & V_745 ) ;
if ( V_35 == - V_625 )
break;
if ( V_35 )
goto V_843;
if ( F_160 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_478 , V_479 ,
V_7 , V_17 -> V_19 , V_618 ,
& V_745 ) < 0 )
goto V_572;
V_842 ++ ;
}
V_572:
V_34 -> args [ 2 ] = V_842 ;
V_35 = V_32 -> V_47 ;
V_843:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_163 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_744 V_745 ;
struct V_31 * V_53 ;
T_2 * V_618 = NULL ;
int V_35 ;
memset ( & V_745 , 0 , sizeof( V_745 ) ) ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
V_618 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( ! V_7 -> V_337 -> V_845 )
return - V_519 ;
V_35 = F_164 ( V_7 , V_518 , V_618 , & V_745 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_160 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_7 , V_518 , V_618 , & V_745 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_165 ( struct V_18 * V_18 ,
struct V_703 * V_137 ,
enum V_846 V_847 )
{
if ( V_137 -> V_848 != - 1 )
return - V_16 ;
if ( V_137 -> V_849 )
return - V_16 ;
F_113 ( V_704 != 7 ) ;
switch ( V_847 ) {
case V_850 :
case V_851 :
if ( V_137 -> V_708 &
~ ( F_156 ( V_720 ) |
F_156 ( V_718 ) |
F_156 ( V_715 ) ) )
return - V_16 ;
break;
case V_852 :
case V_853 :
if ( ! ( V_137 -> V_710 & F_156 ( V_719 ) ) )
return - V_16 ;
V_137 -> V_708 &= ~ F_156 ( V_719 ) ;
break;
default:
if ( V_137 -> V_854 != V_855 )
return - V_16 ;
if ( V_137 -> V_817 )
return - V_16 ;
if ( V_137 -> V_856 & V_857 )
return - V_16 ;
}
if ( V_847 != V_852 &&
V_847 != V_853 ) {
if ( V_137 -> V_710 & F_156 ( V_719 ) )
return - V_16 ;
V_137 -> V_708 &= ~ F_156 ( V_719 ) ;
}
if ( V_847 != V_852 ) {
if ( V_137 -> V_856 & V_858 )
return - V_16 ;
if ( V_137 -> V_856 & V_859 )
return - V_16 ;
if ( V_137 -> V_860 )
return - V_16 ;
if ( V_137 -> V_861 || V_137 -> V_862 || V_137 -> V_863 )
return - V_16 ;
}
if ( V_847 != V_864 ) {
if ( V_137 -> V_865 )
return - V_16 ;
}
switch ( V_847 ) {
case V_866 :
if ( ! ( V_137 -> V_708 & F_156 ( V_715 ) ) )
return - V_519 ;
break;
case V_864 :
if ( V_137 -> V_708 &
~ ( F_156 ( V_715 ) |
F_156 ( V_720 ) |
F_156 ( V_867 ) |
F_156 ( V_716 ) |
F_156 ( V_717 ) |
F_156 ( V_718 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_283 & V_868 ) &&
V_137 -> V_708 &
( F_156 ( V_720 ) |
F_156 ( V_867 ) ) )
return - V_16 ;
break;
case V_869 :
case V_870 :
if ( V_137 -> V_708 & ~ F_156 ( V_715 ) )
return - V_16 ;
break;
case V_852 :
if ( V_137 -> V_708 & ~ ( F_156 ( V_715 ) |
F_156 ( V_717 ) ) )
return - V_16 ;
if ( V_137 -> V_710 & F_156 ( V_715 ) &&
! V_137 -> V_860 )
return - V_16 ;
break;
case V_853 :
return - V_16 ;
case V_850 :
if ( V_137 -> V_856 & V_857 )
return - V_16 ;
break;
case V_851 :
if ( V_137 -> V_854 != V_855 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_166 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_871 = V_30 -> V_5 [ V_872 ] ;
struct V_25 * V_873 ;
int V_474 ;
if ( ! V_871 )
return NULL ;
V_873 = F_167 ( F_94 ( V_30 ) , F_4 ( V_871 ) ) ;
if ( ! V_873 )
return F_3 ( - V_23 ) ;
if ( ! V_873 -> V_28 || V_873 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_474 = - V_16 ;
goto error;
}
if ( V_873 -> V_28 -> V_141 != V_143 &&
V_873 -> V_28 -> V_141 != V_142 &&
V_873 -> V_28 -> V_141 != V_144 ) {
V_474 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_873 ) ) {
V_474 = - V_534 ;
goto error;
}
return V_873 ;
error:
F_168 ( V_873 ) ;
return F_3 ( V_474 ) ;
}
static int F_169 ( struct V_29 * V_30 ,
struct V_703 * V_137 )
{
struct V_4 * V_95 [ V_874 + 1 ] ;
struct V_4 * V_574 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_875 ] )
return 0 ;
V_574 = V_30 -> V_5 [ V_875 ] ;
V_35 = F_33 ( V_95 , V_874 , V_574 ,
V_876 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_877 ] )
V_137 -> V_878 = F_34 (
V_95 [ V_877 ] ) ;
if ( V_137 -> V_878 & ~ V_879 )
return - V_16 ;
if ( V_95 [ V_880 ] )
V_137 -> V_881 = F_34 ( V_95 [ V_880 ] ) ;
if ( V_137 -> V_881 & ~ V_882 )
return - V_16 ;
V_137 -> V_856 |= V_858 ;
return 0 ;
}
static int F_170 ( struct V_29 * V_30 ,
struct V_703 * V_137 )
{
if ( V_30 -> V_5 [ V_883 ] ) {
V_137 -> V_884 =
F_23 ( V_30 -> V_5 [ V_883 ] ) ;
V_137 -> V_885 =
F_24 ( V_30 -> V_5 [ V_883 ] ) ;
if ( V_137 -> V_885 < 2 )
return - V_16 ;
if ( V_137 -> V_885 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_886 ] ) {
V_137 -> V_887 =
F_23 ( V_30 -> V_5 [ V_886 ] ) ;
V_137 -> V_888 =
F_24 ( V_30 -> V_5 [ V_886 ] ) ;
if ( V_137 -> V_888 < 2 ||
V_137 -> V_888 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_171 ( struct V_29 * V_30 ,
struct V_703 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_889 ] )
V_137 -> V_849 = F_78 ( V_30 -> V_5 [ V_889 ] ) ;
if ( V_30 -> V_5 [ V_890 ] )
V_137 -> V_862 =
F_23 ( V_30 -> V_5 [ V_890 ] ) ;
if ( V_30 -> V_5 [ V_891 ] )
V_137 -> V_863 =
F_23 ( V_30 -> V_5 [ V_891 ] ) ;
V_35 = F_170 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_169 ( V_30 , V_137 ) ;
}
static int F_172 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_703 V_137 ;
T_2 * V_618 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_848 = - 1 ;
if ( ! V_7 -> V_337 -> V_892 )
return - V_519 ;
if ( V_30 -> V_5 [ V_893 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
V_618 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_30 -> V_5 [ V_894 ] ) {
V_137 . V_860 =
F_23 ( V_30 -> V_5 [ V_894 ] ) ;
V_137 . V_895 =
F_24 ( V_30 -> V_5 [ V_894 ] ) ;
}
if ( V_30 -> V_5 [ V_896 ] ) {
V_137 . V_897 =
F_78 ( V_30 -> V_5 [ V_896 ] ) ;
V_137 . V_856 |= V_859 ;
}
if ( V_30 -> V_5 [ V_898 ] ) {
V_137 . V_861 =
F_23 ( V_30 -> V_5 [ V_898 ] ) ;
V_137 . V_899 =
F_24 ( V_30 -> V_5 [ V_898 ] ) ;
}
if ( V_30 -> V_5 [ V_900 ] )
return - V_16 ;
if ( F_155 ( V_30 , V_518 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_901 ] ) {
V_137 . V_854 =
F_34 ( V_30 -> V_5 [ V_901 ] ) ;
if ( V_137 . V_854 >= V_902 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_903 ] ) {
V_137 . V_776 =
F_34 ( V_30 -> V_5 [ V_903 ] ) ;
if ( V_137 . V_776 >= V_904 )
return - V_16 ;
V_137 . V_856 |= V_857 ;
}
if ( V_30 -> V_5 [ V_905 ] ) {
enum V_906 V_907 = F_4 (
V_30 -> V_5 [ V_905 ] ) ;
if ( V_907 <= V_908 ||
V_907 > V_909 )
return - V_16 ;
V_137 . V_817 = V_907 ;
}
V_35 = F_171 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_865 = F_166 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_865 ) )
return F_18 ( V_137 . V_865 ) ;
switch ( V_518 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_519 ;
goto V_910;
}
V_35 = F_173 ( V_7 , V_518 , V_618 , & V_137 ) ;
V_910:
if ( V_137 . V_865 )
F_168 ( V_137 . V_865 ) ;
return V_35 ;
}
static int F_174 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
int V_35 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_703 V_137 ;
T_2 * V_618 = NULL ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_337 -> V_363 )
return - V_519 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_900 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_894 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_893 ] &&
! V_30 -> V_5 [ V_889 ] )
return - V_16 ;
V_618 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_137 . V_860 =
F_23 ( V_30 -> V_5 [ V_894 ] ) ;
V_137 . V_895 =
F_24 ( V_30 -> V_5 [ V_894 ] ) ;
V_137 . V_848 =
F_78 ( V_30 -> V_5 [ V_900 ] ) ;
if ( V_30 -> V_5 [ V_889 ] )
V_137 . V_849 = F_78 ( V_30 -> V_5 [ V_889 ] ) ;
else
V_137 . V_849 = F_78 ( V_30 -> V_5 [ V_893 ] ) ;
if ( ! V_137 . V_849 || V_137 . V_849 > V_911 )
return - V_16 ;
if ( V_30 -> V_5 [ V_896 ] ) {
V_137 . V_897 =
F_78 ( V_30 -> V_5 [ V_896 ] ) ;
V_137 . V_856 |= V_859 ;
}
if ( V_30 -> V_5 [ V_898 ] ) {
V_137 . V_861 =
F_23 ( V_30 -> V_5 [ V_898 ] ) ;
V_137 . V_899 =
F_24 ( V_30 -> V_5 [ V_898 ] ) ;
}
if ( V_30 -> V_5 [ V_890 ] )
V_137 . V_862 =
F_23 ( V_30 -> V_5 [ V_890 ] ) ;
if ( V_30 -> V_5 [ V_891 ] )
V_137 . V_863 =
F_23 ( V_30 -> V_5 [ V_891 ] ) ;
if ( V_30 -> V_5 [ V_912 ] ) {
V_137 . V_913 = true ;
V_137 . V_914 =
F_34 ( V_30 -> V_5 [ V_912 ] ) ;
}
if ( V_30 -> V_5 [ V_901 ] ) {
V_137 . V_854 =
F_34 ( V_30 -> V_5 [ V_901 ] ) ;
if ( V_137 . V_854 >= V_902 )
return - V_16 ;
}
V_35 = F_170 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_169 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_155 ( V_30 , V_518 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
F_113 ( V_704 != 7 ) ;
switch ( V_518 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_314 ) ||
! ( V_137 . V_710 & F_156 ( V_717 ) ) )
V_137 . V_856 &= ~ V_858 ;
if ( ( V_137 . V_710 & F_156 ( V_719 ) ) ||
V_30 -> V_5 [ V_889 ] )
return - V_16 ;
V_137 . V_708 &= ~ F_156 ( V_719 ) ;
if ( ! ( V_7 -> V_18 . V_283 &
V_868 ) &&
V_137 . V_708 &
( F_156 ( V_720 ) |
F_156 ( V_867 ) ) )
return - V_16 ;
V_137 . V_865 = F_166 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_865 ) )
return F_18 ( V_137 . V_865 ) ;
break;
case V_145 :
V_137 . V_856 &= ~ V_858 ;
if ( V_137 . V_708 & F_156 ( V_867 ) )
return - V_16 ;
if ( ( V_137 . V_710 & F_156 ( V_719 ) ) ||
V_30 -> V_5 [ V_889 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_856 &= ~ V_858 ;
if ( V_137 . V_708 &
( F_156 ( V_867 ) |
F_156 ( V_720 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_710 & F_156 ( V_719 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_318 ) )
return - V_519 ;
if ( ! ( V_7 -> V_18 . V_51 & V_320 ) )
return - V_519 ;
V_137 . V_708 &= ~ F_156 ( V_715 ) ;
break;
default:
return - V_519 ;
}
V_35 = F_175 ( V_7 , V_518 , V_618 , & V_137 ) ;
if ( V_137 . V_865 )
F_168 ( V_137 . V_865 ) ;
return V_35 ;
}
static int F_176 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 * V_618 = NULL ;
if ( V_30 -> V_5 [ V_526 ] )
V_618 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_518 -> V_28 -> V_141 != V_142 &&
V_518 -> V_28 -> V_141 != V_143 &&
V_518 -> V_28 -> V_141 != V_145 &&
V_518 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_915 )
return - V_519 ;
return F_177 ( V_7 , V_518 , V_618 ) ;
}
static int F_178 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_518 ,
T_2 * V_916 , T_2 * V_917 ,
struct V_918 * V_919 )
{
void * V_275 ;
struct V_4 * V_920 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_748 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_916 ) ||
F_51 ( V_53 , V_921 , V_562 , V_917 ) ||
F_28 ( V_53 , V_285 , V_919 -> V_749 ) )
goto V_61;
V_920 = F_47 ( V_53 , V_922 ) ;
if ( ! V_920 )
goto V_61;
if ( ( V_919 -> V_751 & V_923 ) &&
F_28 ( V_53 , V_924 ,
V_919 -> V_925 ) )
goto V_61;
if ( ( ( V_919 -> V_751 & V_926 ) &&
F_28 ( V_53 , V_927 , V_919 -> V_928 ) ) ||
( ( V_919 -> V_751 & V_929 ) &&
F_28 ( V_53 , V_930 ,
V_919 -> V_931 ) ) ||
( ( V_919 -> V_751 & V_932 ) &&
F_28 ( V_53 , V_933 ,
V_919 -> V_934 ) ) ||
( ( V_919 -> V_751 & V_935 ) &&
F_56 ( V_53 , V_936 ,
V_919 -> V_51 ) ) ||
( ( V_919 -> V_751 & V_937 ) &&
F_28 ( V_53 , V_938 ,
V_919 -> V_939 ) ) ||
( ( V_919 -> V_751 & V_940 ) &&
F_56 ( V_53 , V_941 ,
V_919 -> V_942 ) ) )
goto V_61;
F_48 ( V_53 , V_920 ) ;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
static int F_179 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_918 V_919 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_916 [ V_562 ] ;
T_2 V_917 [ V_562 ] ;
int V_943 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_337 -> V_944 ) {
V_35 = - V_519 ;
goto V_843;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_519 ;
goto V_843;
}
while ( 1 ) {
V_35 = F_180 ( V_7 , V_17 -> V_19 , V_943 , V_916 ,
V_917 , & V_919 ) ;
if ( V_35 == - V_625 )
break;
if ( V_35 )
goto V_843;
if ( F_178 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_478 , V_479 ,
V_17 -> V_19 , V_916 , V_917 ,
& V_919 ) < 0 )
goto V_572;
V_943 ++ ;
}
V_572:
V_34 -> args [ 2 ] = V_943 ;
V_35 = V_32 -> V_47 ;
V_843:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_181 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
int V_35 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_918 V_919 ;
struct V_31 * V_53 ;
T_2 * V_916 = NULL ;
T_2 V_917 [ V_562 ] ;
memset ( & V_919 , 0 , sizeof( V_919 ) ) ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
V_916 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( ! V_7 -> V_337 -> V_945 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_145 )
return - V_519 ;
V_35 = F_182 ( V_7 , V_518 , V_916 , V_917 , & V_919 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_178 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_518 , V_916 , V_917 , & V_919 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_183 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 * V_916 = NULL ;
T_2 * V_917 = NULL ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_921 ] )
return - V_16 ;
V_916 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_917 = F_23 ( V_30 -> V_5 [ V_921 ] ) ;
if ( ! V_7 -> V_337 -> V_946 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_145 )
return - V_519 ;
return F_184 ( V_7 , V_518 , V_916 , V_917 ) ;
}
static int F_185 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 * V_916 = NULL ;
T_2 * V_917 = NULL ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_921 ] )
return - V_16 ;
V_916 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_917 = F_23 ( V_30 -> V_5 [ V_921 ] ) ;
if ( ! V_7 -> V_337 -> V_365 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_145 )
return - V_519 ;
return F_186 ( V_7 , V_518 , V_916 , V_917 ) ;
}
static int F_187 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 * V_916 = NULL ;
if ( V_30 -> V_5 [ V_526 ] )
V_916 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( ! V_7 -> V_337 -> V_947 )
return - V_519 ;
return F_188 ( V_7 , V_518 , V_916 ) ;
}
static int F_189 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_948 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_949 = - 1 ;
V_137 . V_950 = - 1 ;
V_137 . V_951 = - 1 ;
V_137 . V_952 = - 1 ;
V_137 . V_953 = - 1 ;
V_137 . V_697 = - 1 ;
V_137 . V_700 = - 1 ;
if ( V_30 -> V_5 [ V_954 ] )
V_137 . V_949 =
F_34 ( V_30 -> V_5 [ V_954 ] ) ;
if ( V_30 -> V_5 [ V_955 ] )
V_137 . V_950 =
F_34 ( V_30 -> V_5 [ V_955 ] ) ;
if ( V_30 -> V_5 [ V_956 ] )
V_137 . V_951 =
F_34 ( V_30 -> V_5 [ V_956 ] ) ;
if ( V_30 -> V_5 [ V_957 ] ) {
V_137 . V_958 =
F_23 ( V_30 -> V_5 [ V_957 ] ) ;
V_137 . V_959 =
F_24 ( V_30 -> V_5 [ V_957 ] ) ;
}
if ( V_30 -> V_5 [ V_960 ] )
V_137 . V_952 = ! ! F_34 ( V_30 -> V_5 [ V_960 ] ) ;
if ( V_30 -> V_5 [ V_961 ] )
V_137 . V_953 =
F_78 ( V_30 -> V_5 [ V_961 ] ) ;
if ( V_30 -> V_5 [ V_696 ] ) {
if ( V_518 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_697 =
F_190 ( V_30 -> V_5 [ V_696 ] ) ;
if ( V_137 . V_697 < 0 )
return - V_16 ;
if ( V_137 . V_697 != 0 &&
! ( V_7 -> V_18 . V_283 & V_698 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_699 ] ) {
T_2 V_24 ;
if ( V_518 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_699 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_700 = V_24 ;
if ( V_137 . V_700 &&
! ( V_7 -> V_18 . V_283 & V_701 ) )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_369 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_142 &&
V_518 -> V_28 -> V_141 != V_144 )
return - V_519 ;
F_112 ( V_17 ) ;
V_35 = F_191 ( V_7 , V_518 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_192 ( struct V_4 * V_95 [] ,
struct V_962 * V_963 )
{
struct V_964 * V_965 = & V_963 -> V_965 ;
struct V_966 * V_967 = & V_963 -> V_967 ;
if ( ! V_95 [ V_968 ] )
return - V_16 ;
if ( ! V_95 [ V_969 ] )
return - V_16 ;
if ( ! V_95 [ V_970 ] )
return - V_16 ;
if ( ! V_95 [ V_971 ] )
return - V_16 ;
if ( ! V_95 [ V_972 ] )
return - V_16 ;
V_963 -> V_51 = F_4 ( V_95 [ V_968 ] ) ;
V_965 -> V_973 =
F_4 ( V_95 [ V_969 ] ) ;
V_965 -> V_974 =
F_4 ( V_95 [ V_970 ] ) ;
V_965 -> V_975 =
F_4 ( V_95 [ V_971 ] ) ;
V_967 -> V_976 =
F_4 ( V_95 [ V_972 ] ) ;
if ( V_95 [ V_977 ] )
V_967 -> V_978 =
F_4 ( V_95 [ V_977 ] ) ;
if ( V_95 [ V_979 ] )
V_963 -> V_74 =
F_4 ( V_95 [ V_979 ] ) ;
return 0 ;
}
static int F_193 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
enum V_980 V_981 ;
if ( F_194 ( ! F_195 ( V_982 ) ) )
return - V_983 ;
if ( V_30 -> V_5 [ V_984 ] )
V_981 =
F_4 ( V_30 -> V_5 [ V_984 ] ) ;
else
V_981 = V_985 ;
switch ( V_981 ) {
case V_985 :
case V_986 :
if ( ! V_30 -> V_5 [ V_987 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_987 ] ) ;
return F_196 ( V_138 , V_981 ) ;
case V_988 :
return F_197 () ;
default:
return - V_16 ;
}
}
static int F_198 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_989 V_990 ;
int V_35 = 0 ;
void * V_275 ;
struct V_4 * V_920 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_519 ;
if ( ! V_7 -> V_337 -> V_991 )
return - V_519 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_992 )
memcpy ( & V_990 , & V_993 , sizeof( V_990 ) ) ;
else
V_35 = F_199 ( V_7 , V_518 , & V_990 ) ;
F_114 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_994 ) ;
if ( ! V_275 )
goto V_572;
V_920 = F_47 ( V_53 , V_995 ) ;
if ( ! V_920 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_55 ( V_53 , V_996 ,
V_990 . V_997 ) ||
F_55 ( V_53 , V_998 ,
V_990 . V_999 ) ||
F_55 ( V_53 , V_1000 ,
V_990 . V_1001 ) ||
F_55 ( V_53 , V_1002 ,
V_990 . V_1003 ) ||
F_56 ( V_53 , V_1004 ,
V_990 . V_1005 ) ||
F_56 ( V_53 , V_1006 ,
V_990 . V_1007 ) ||
F_56 ( V_53 , V_1008 ,
V_990 . V_1009 ) ||
F_56 ( V_53 , V_1010 ,
V_990 . V_1011 ) ||
F_28 ( V_53 , V_1012 ,
V_990 . V_1013 ) ||
F_56 ( V_53 , V_1014 ,
V_990 . V_1015 ) ||
F_28 ( V_53 , V_1016 ,
V_990 . V_1017 ) ||
F_55 ( V_53 , V_1018 ,
V_990 . V_1019 ) ||
F_28 ( V_53 , V_1020 ,
V_990 . V_1021 ) ||
F_55 ( V_53 , V_1022 ,
V_990 . V_1023 ) ||
F_55 ( V_53 , V_1024 ,
V_990 . V_1025 ) ||
F_55 ( V_53 , V_1026 ,
V_990 . V_1027 ) ||
F_56 ( V_53 , V_1028 ,
V_990 . V_1029 ) ||
F_55 ( V_53 , V_1030 ,
V_990 . V_1031 ) ||
F_56 ( V_53 , V_1032 ,
V_990 . V_1033 ) ||
F_56 ( V_53 , V_1034 ,
V_990 . V_1035 ) ||
F_28 ( V_53 , V_1036 ,
V_990 . V_1037 ) ||
F_28 ( V_53 , V_1038 ,
V_990 . V_953 ) ||
F_28 ( V_53 , V_1039 ,
V_990 . V_1040 ) ||
F_55 ( V_53 , V_1041 ,
V_990 . V_1042 ) ||
F_55 ( V_53 , V_1043 ,
V_990 . V_1044 ) ||
F_28 ( V_53 , V_1045 ,
V_990 . V_1046 ) ||
F_55 ( V_53 , V_1047 ,
V_990 . V_1048 ) ||
F_28 ( V_53 , V_1049 ,
V_990 . V_1050 ) )
goto V_61;
F_48 ( V_53 , V_920 ) ;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
V_572:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_200 ( struct V_29 * V_30 ,
struct V_989 * V_1051 ,
V_22 * V_1052 )
{
struct V_4 * V_95 [ V_1053 + 1 ] ;
V_22 V_709 = 0 ;
#define F_201 ( V_95 , V_1051 , T_7 , T_8 , V_168 , V_709 , V_45 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_995 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1053 ,
V_30 -> V_5 [ V_995 ] ,
V_1054 ) )
return - V_16 ;
F_113 ( V_1053 > 32 ) ;
F_201 ( V_95 , V_1051 , V_997 , 1 , 255 ,
V_709 , V_996 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_999 , 1 , 255 ,
V_709 , V_998 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1001 , 1 , 255 ,
V_709 , V_1000 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1003 , 0 , 255 ,
V_709 , V_1002 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1005 , 0 , 16 ,
V_709 , V_1004 ,
F_34 ) ;
F_201 ( V_95 , V_1051 , V_1007 , 1 , 255 ,
V_709 , V_1006 , F_34 ) ;
F_201 ( V_95 , V_1051 , V_1009 , 1 , 255 ,
V_709 , V_1008 ,
F_34 ) ;
F_201 ( V_95 , V_1051 , V_1011 , 0 , 1 ,
V_709 , V_1010 ,
F_34 ) ;
F_201 ( V_95 , V_1051 , V_1013 ,
1 , 255 , V_709 ,
V_1012 ,
F_4 ) ;
F_201 ( V_95 , V_1051 , V_1015 , 0 , 255 ,
V_709 , V_1014 ,
F_34 ) ;
F_201 ( V_95 , V_1051 , V_1017 , 1 , 65535 ,
V_709 , V_1016 ,
F_4 ) ;
F_201 ( V_95 , V_1051 , V_1019 , 1 , 65535 ,
V_709 , V_1018 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1021 ,
1 , 65535 , V_709 ,
V_1020 ,
F_4 ) ;
F_201 ( V_95 , V_1051 , V_1023 ,
1 , 65535 , V_709 ,
V_1022 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1025 ,
1 , 65535 , V_709 ,
V_1024 ,
F_78 ) ;
F_201 ( V_95 , V_1051 ,
V_1027 ,
1 , 65535 , V_709 ,
V_1026 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1029 , 0 , 4 ,
V_709 , V_1028 ,
F_34 ) ;
F_201 ( V_95 , V_1051 , V_1031 , 1 , 65535 ,
V_709 , V_1030 ,
F_78 ) ;
F_201 ( V_95 , V_1051 ,
V_1033 , 0 , 1 ,
V_709 , V_1032 ,
F_34 ) ;
F_201 ( V_95 , V_1051 , V_1035 , 0 , 1 ,
V_709 , V_1034 ,
F_34 ) ;
F_201 ( V_95 , V_1051 , V_1037 , - 255 , 0 ,
V_709 , V_1036 ,
V_1055 ) ;
F_201 ( V_95 , V_1051 , V_953 , 0 , 16 ,
V_709 , V_1038 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1040 ,
1 , 65535 , V_709 ,
V_1039 ,
F_4 ) ;
F_201 ( V_95 , V_1051 , V_1042 , 1 , 65535 ,
V_709 , V_1041 ,
F_78 ) ;
F_201 ( V_95 , V_1051 ,
V_1044 ,
1 , 65535 , V_709 ,
V_1043 ,
F_78 ) ;
F_201 ( V_95 , V_1051 , V_1046 ,
V_1056 ,
V_909 ,
V_709 , V_1045 ,
F_4 ) ;
F_201 ( V_95 , V_1051 , V_1048 ,
0 , 65535 , V_709 ,
V_1047 , F_78 ) ;
F_201 ( V_95 , V_1051 , V_1050 , 1 , 0xffffffff ,
V_709 , V_1049 ,
F_4 ) ;
if ( V_1052 )
* V_1052 = V_709 ;
return 0 ;
#undef F_201
}
static int F_202 ( struct V_29 * V_30 ,
struct V_1057 * V_1058 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_4 * V_95 [ V_1059 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1060 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1059 ,
V_30 -> V_5 [ V_1060 ] ,
V_1061 ) )
return - V_16 ;
if ( V_95 [ V_1062 ] )
V_1058 -> V_1063 =
( F_34 ( V_95 [ V_1062 ] ) ) ?
V_1064 :
V_1065 ;
if ( V_95 [ V_1066 ] )
V_1058 -> V_1067 =
( F_34 ( V_95 [ V_1066 ] ) ) ?
V_1068 :
V_1069 ;
if ( V_95 [ V_1070 ] )
V_1058 -> V_1071 =
( F_34 ( V_95 [ V_1070 ] ) ) ?
V_1072 :
V_1073 ;
if ( V_95 [ V_1074 ] ) {
struct V_4 * V_1075 =
V_95 [ V_1074 ] ;
if ( ! F_22 ( V_1075 ) )
return - V_16 ;
V_1058 -> V_1076 = F_23 ( V_1075 ) ;
V_1058 -> V_1077 = F_24 ( V_1075 ) ;
}
if ( V_95 [ V_1078 ] &&
! ( V_7 -> V_18 . V_283 & V_1079 ) )
return - V_16 ;
V_1058 -> V_1080 = F_203 ( V_95 [ V_1078 ] ) ;
V_1058 -> V_1081 = F_203 ( V_95 [ V_1082 ] ) ;
V_1058 -> V_1083 = F_203 ( V_95 [ V_1084 ] ) ;
if ( V_1058 -> V_1083 )
V_1058 -> V_1080 = true ;
if ( V_95 [ V_1085 ] ) {
if ( ! V_1058 -> V_1080 )
return - V_16 ;
V_1058 -> V_1086 =
F_34 ( V_95 [ V_1085 ] ) ;
}
return 0 ;
}
static int F_204 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_989 V_1051 ;
V_22 V_709 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_519 ;
if ( ! V_7 -> V_337 -> V_367 )
return - V_519 ;
V_35 = F_200 ( V_30 , & V_1051 , & V_709 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_992 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_205 ( V_7 , V_518 , V_709 , & V_1051 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_206 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1087 * V_1088 ;
struct V_31 * V_53 ;
void * V_275 = NULL ;
struct V_4 * V_1089 ;
unsigned int V_153 ;
if ( ! V_982 )
return - V_16 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1090 ) ;
if ( ! V_275 )
goto V_1091;
if ( F_207 () &&
F_28 ( V_53 , V_984 ,
V_986 ) )
goto V_61;
F_208 () ;
V_1088 = F_209 ( V_982 ) ;
if ( F_60 ( V_53 , V_987 , V_1088 -> V_1092 ) ||
( V_1088 -> V_1093 &&
F_56 ( V_53 , V_1094 , V_1088 -> V_1093 ) ) )
goto V_1095;
V_1089 = F_47 ( V_53 , V_1096 ) ;
if ( ! V_1089 )
goto V_1095;
for ( V_153 = 0 ; V_153 < V_1088 -> V_1097 ; V_153 ++ ) {
struct V_4 * V_1098 ;
const struct V_962 * V_963 ;
const struct V_964 * V_965 ;
const struct V_966 * V_967 ;
unsigned int V_975 ;
V_963 = & V_1088 -> V_1099 [ V_153 ] ;
V_965 = & V_963 -> V_965 ;
V_967 = & V_963 -> V_967 ;
V_1098 = F_47 ( V_53 , V_153 ) ;
if ( ! V_1098 )
goto V_1095;
V_975 = V_965 -> V_975 ;
if ( ! V_975 )
V_975 = F_210 ( V_1088 ,
V_963 ) ;
if ( F_28 ( V_53 , V_968 ,
V_963 -> V_51 ) ||
F_28 ( V_53 , V_969 ,
V_965 -> V_973 ) ||
F_28 ( V_53 , V_970 ,
V_965 -> V_974 ) ||
F_28 ( V_53 , V_971 ,
V_975 ) ||
F_28 ( V_53 , V_977 ,
V_967 -> V_978 ) ||
F_28 ( V_53 , V_972 ,
V_967 -> V_976 ) ||
F_28 ( V_53 , V_979 ,
V_963 -> V_74 ) )
goto V_1095;
F_48 ( V_53 , V_1098 ) ;
}
F_211 () ;
F_48 ( V_53 , V_1089 ) ;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1095:
F_211 () ;
V_61:
F_67 ( V_53 , V_275 ) ;
V_1091:
F_75 ( V_53 ) ;
return - V_473 ;
}
static int F_212 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1100 + 1 ] ;
struct V_4 * V_1098 ;
char * V_1092 = NULL ;
int V_1101 = 0 , V_1102 = 0 ;
V_22 V_1103 = 0 , V_1104 = 0 , V_1105 ;
enum V_1106 V_1093 = V_1107 ;
struct V_1087 * V_1108 = NULL ;
if ( ! V_30 -> V_5 [ V_987 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1096 ] )
return - V_16 ;
V_1092 = F_23 ( V_30 -> V_5 [ V_987 ] ) ;
if ( V_30 -> V_5 [ V_1094 ] )
V_1093 = F_34 ( V_30 -> V_5 [ V_1094 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1103 ++ ;
if ( V_1103 > V_1109 )
return - V_16 ;
}
if ( ! F_213 ( V_1092 ) )
return - V_16 ;
V_1105 = sizeof( struct V_1087 ) +
V_1103 * sizeof( struct V_962 ) ;
V_1108 = F_38 ( V_1105 , V_135 ) ;
if ( ! V_1108 )
return - V_136 ;
V_1108 -> V_1097 = V_1103 ;
V_1108 -> V_1092 [ 0 ] = V_1092 [ 0 ] ;
V_1108 -> V_1092 [ 1 ] = V_1092 [ 1 ] ;
if ( F_214 ( V_1093 ) )
V_1108 -> V_1093 = V_1093 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1102 = F_96 ( V_95 , V_1100 ,
F_23 ( V_1098 ) , F_24 ( V_1098 ) ,
V_1110 ) ;
if ( V_1102 )
goto V_1111;
V_1102 = F_192 ( V_95 , & V_1108 -> V_1099 [ V_1104 ] ) ;
if ( V_1102 )
goto V_1111;
V_1104 ++ ;
if ( V_1104 > V_1109 ) {
V_1102 = - V_16 ;
goto V_1111;
}
}
V_1102 = F_215 ( V_1108 ) ;
V_1108 = NULL ;
V_1111:
F_41 ( V_1108 ) ;
return V_1102 ;
}
static int F_216 ( struct V_4 * V_1112 )
{
struct V_4 * V_1113 , * V_1114 ;
int V_352 = 0 , V_1115 , V_1116 ;
F_39 (attr1, freqs, tmp1) {
V_352 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1113 != V_1114 &&
F_4 ( V_1113 ) == F_4 ( V_1114 ) )
return 0 ;
}
return V_352 ;
}
static int F_217 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
struct V_1117 * V_1118 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1119 = 0 , V_352 , V_153 ;
T_10 V_1077 ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_337 -> V_1120 )
return - V_519 ;
if ( V_7 -> V_1121 || V_7 -> V_1122 ) {
V_35 = - V_523 ;
goto V_1123;
}
if ( V_30 -> V_5 [ V_1124 ] ) {
V_352 = F_216 (
V_30 -> V_5 [ V_1124 ] ) ;
if ( ! V_352 ) {
V_35 = - V_16 ;
goto V_1123;
}
} else {
V_352 = F_218 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1125 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1119 ++ ;
if ( V_1119 > V_18 -> V_301 ) {
V_35 = - V_16 ;
goto V_1123;
}
if ( V_30 -> V_5 [ V_652 ] )
V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
else
V_1077 = 0 ;
if ( V_1077 > V_18 -> V_305 ) {
V_35 = - V_16 ;
goto V_1123;
}
V_1118 = F_38 ( sizeof( * V_1118 )
+ sizeof( * V_1118 -> V_1126 ) * V_1119
+ sizeof( * V_1118 -> V_353 ) * V_352
+ V_1077 , V_135 ) ;
if ( ! V_1118 ) {
V_35 = - V_136 ;
goto V_1123;
}
if ( V_1119 )
V_1118 -> V_1126 = ( void * ) & V_1118 -> V_353 [ V_352 ] ;
V_1118 -> V_1119 = V_1119 ;
if ( V_1077 ) {
if ( V_1118 -> V_1126 )
V_1118 -> V_1076 = ( void * ) ( V_1118 -> V_1126 + V_1119 ) ;
else
V_1118 -> V_1076 = ( void * ) ( V_1118 -> V_353 + V_352 ) ;
}
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1124 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1127;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1118 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
} else {
enum V_281 V_282 ;
for ( V_282 = 0 ; V_282 < V_348 ; V_282 ++ ) {
int V_155 ;
if ( ! V_18 -> V_349 [ V_282 ] )
continue;
for ( V_155 = 0 ; V_155 < V_18 -> V_349 [ V_282 ] -> V_352 ; V_155 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_349 [ V_282 ] -> V_353 [ V_155 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1118 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
}
}
if ( ! V_153 ) {
V_35 = - V_16 ;
goto V_1127;
}
V_1118 -> V_352 = V_153 ;
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1125 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_591 ) {
V_35 = - V_16 ;
goto V_1127;
}
V_1118 -> V_1126 [ V_153 ] . V_565 = F_24 ( V_45 ) ;
memcpy ( V_1118 -> V_1126 [ V_153 ] . V_567 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_153 ++ ;
}
}
if ( V_30 -> V_5 [ V_652 ] ) {
V_1118 -> V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
memcpy ( ( void * ) V_1118 -> V_1076 ,
F_23 ( V_30 -> V_5 [ V_652 ] ) ,
V_1118 -> V_1077 ) ;
}
for ( V_153 = 0 ; V_153 < V_348 ; V_153 ++ )
if ( V_18 -> V_349 [ V_153 ] )
V_1118 -> V_1128 [ V_153 ] =
( 1 << V_18 -> V_349 [ V_153 ] -> V_252 ) - 1 ;
if ( V_30 -> V_5 [ V_1129 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_281 V_282 = F_219 ( V_45 ) ;
if ( V_282 < 0 || V_282 >= V_348 ) {
V_35 = - V_16 ;
goto V_1127;
}
if ( ! V_18 -> V_349 [ V_282 ] )
continue;
V_35 = F_220 ( V_18 -> V_349 [ V_282 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1118 -> V_1128 [ V_282 ] ) ;
if ( V_35 )
goto V_1127;
}
}
if ( V_30 -> V_5 [ V_1130 ] ) {
V_1118 -> V_51 = F_4 (
V_30 -> V_5 [ V_1130 ] ) ;
if ( ( V_1118 -> V_51 & V_1131 ) &&
! ( V_18 -> V_283 & V_1132 ) ) {
V_35 = - V_519 ;
goto V_1127;
}
}
V_1118 -> V_1133 =
F_203 ( V_30 -> V_5 [ V_1134 ] ) ;
V_1118 -> V_17 = V_17 ;
V_1118 -> V_18 = & V_7 -> V_18 ;
V_1118 -> V_1135 = V_1136 ;
V_7 -> V_1121 = V_1118 ;
V_35 = F_221 ( V_7 , V_1118 ) ;
if ( ! V_35 ) {
F_222 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_223 ( V_17 -> V_19 ) ;
} else {
V_1127:
V_7 -> V_1121 = NULL ;
F_41 ( V_1118 ) ;
}
V_1123:
return V_35 ;
}
static int F_224 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1137 * V_1118 ;
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1119 = 0 , V_1138 = 0 , V_352 , V_153 ;
V_22 V_1139 ;
enum V_281 V_282 ;
T_10 V_1077 ;
struct V_4 * V_95 [ V_1140 + 1 ] ;
T_11 V_1141 = V_1142 ;
if ( ! ( V_7 -> V_18 . V_51 & V_408 ) ||
! V_7 -> V_337 -> V_409 )
return - V_519 ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1143 ] )
return - V_16 ;
V_1139 = F_4 ( V_30 -> V_5 [ V_1143 ] ) ;
if ( V_1139 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_1124 ] ) {
V_352 = F_216 (
V_30 -> V_5 [ V_1124 ] ) ;
if ( ! V_352 )
return - V_16 ;
} else {
V_352 = F_218 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1125 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1119 ++ ;
if ( V_1119 > V_18 -> V_303 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1144 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1145 ;
V_35 = F_96 ( V_95 , V_1140 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1146 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1147 ] ) {
V_1138 ++ ;
continue;
}
V_1145 = V_95 [ V_1148 ] ;
if ( V_1145 )
V_1141 = V_1055 ( V_1145 ) ;
}
}
if ( ! V_1138 && V_1141 != V_1142 )
V_1138 = 1 ;
if ( V_1138 > V_18 -> V_309 )
return - V_16 ;
if ( V_30 -> V_5 [ V_652 ] )
V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
else
V_1077 = 0 ;
if ( V_1077 > V_18 -> V_307 )
return - V_16 ;
if ( V_7 -> V_1149 ) {
V_35 = - V_983 ;
goto V_572;
}
V_1118 = F_38 ( sizeof( * V_1118 )
+ sizeof( * V_1118 -> V_1126 ) * V_1119
+ sizeof( * V_1118 -> V_1150 ) * V_1138
+ sizeof( * V_1118 -> V_353 ) * V_352
+ V_1077 , V_135 ) ;
if ( ! V_1118 ) {
V_35 = - V_136 ;
goto V_572;
}
if ( V_1119 )
V_1118 -> V_1126 = ( void * ) & V_1118 -> V_353 [ V_352 ] ;
V_1118 -> V_1119 = V_1119 ;
if ( V_1077 ) {
if ( V_1118 -> V_1126 )
V_1118 -> V_1076 = ( void * ) ( V_1118 -> V_1126 + V_1119 ) ;
else
V_1118 -> V_1076 = ( void * ) ( V_1118 -> V_353 + V_352 ) ;
}
if ( V_1138 ) {
if ( V_1118 -> V_1076 )
V_1118 -> V_1150 = ( void * ) ( V_1118 -> V_1076 + V_1077 ) ;
else if ( V_1118 -> V_1126 )
V_1118 -> V_1150 =
( void * ) ( V_1118 -> V_1126 + V_1119 ) ;
else
V_1118 -> V_1150 =
( void * ) ( V_1118 -> V_353 + V_352 ) ;
}
V_1118 -> V_1138 = V_1138 ;
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1124 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1127;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1118 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
} else {
for ( V_282 = 0 ; V_282 < V_348 ; V_282 ++ ) {
int V_155 ;
if ( ! V_18 -> V_349 [ V_282 ] )
continue;
for ( V_155 = 0 ; V_155 < V_18 -> V_349 [ V_282 ] -> V_352 ; V_155 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_349 [ V_282 ] -> V_353 [ V_155 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1118 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
}
}
if ( ! V_153 ) {
V_35 = - V_16 ;
goto V_1127;
}
V_1118 -> V_352 = V_153 ;
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1125 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_591 ) {
V_35 = - V_16 ;
goto V_1127;
}
V_1118 -> V_1126 [ V_153 ] . V_565 = F_24 ( V_45 ) ;
memcpy ( V_1118 -> V_1126 [ V_153 ] . V_567 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_153 ++ ;
}
}
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1144 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_567 , * V_1145 ;
V_35 = F_96 ( V_95 , V_1140 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1146 ) ;
if ( V_35 )
goto V_1127;
V_567 = V_95 [ V_1147 ] ;
if ( V_567 ) {
if ( F_59 ( V_153 >= V_1138 ) ) {
V_35 = - V_16 ;
goto V_1127;
}
if ( F_24 ( V_567 ) > V_591 ) {
V_35 = - V_16 ;
goto V_1127;
}
memcpy ( V_1118 -> V_1150 [ V_153 ] . V_567 . V_567 ,
F_23 ( V_567 ) , F_24 ( V_567 ) ) ;
V_1118 -> V_1150 [ V_153 ] . V_567 . V_565 =
F_24 ( V_567 ) ;
V_1118 -> V_1150 [ V_153 ] . V_1151 =
V_1141 ;
V_1145 = V_95 [ V_1148 ] ;
if ( V_1145 )
V_1118 -> V_1150 [ V_153 ] . V_1151 =
V_1055 ( V_1145 ) ;
}
V_153 ++ ;
}
if ( V_153 == 0 )
V_1118 -> V_1150 [ 0 ] . V_1151 = V_1141 ;
V_1118 -> V_1152 = V_1153 ;
for ( V_153 = 0 ; V_153 < V_1138 ; V_153 ++ )
V_1118 -> V_1152 =
T_8 ( V_1118 -> V_1150 [ V_153 ] . V_1151 ,
V_1118 -> V_1152 ) ;
} else {
V_1118 -> V_1152 = V_1142 ;
}
if ( V_1077 ) {
V_1118 -> V_1077 = V_1077 ;
memcpy ( ( void * ) V_1118 -> V_1076 ,
F_23 ( V_30 -> V_5 [ V_652 ] ) ,
V_1118 -> V_1077 ) ;
}
if ( V_30 -> V_5 [ V_1130 ] ) {
V_1118 -> V_51 = F_4 (
V_30 -> V_5 [ V_1130 ] ) ;
if ( ( V_1118 -> V_51 & V_1131 ) &&
! ( V_18 -> V_283 & V_1132 ) ) {
V_35 = - V_519 ;
goto V_1127;
}
}
V_1118 -> V_518 = V_518 ;
V_1118 -> V_18 = & V_7 -> V_18 ;
V_1118 -> V_1139 = V_1139 ;
V_1118 -> V_1135 = V_1136 ;
V_35 = F_225 ( V_7 , V_518 , V_1118 ) ;
if ( ! V_35 ) {
V_7 -> V_1149 = V_1118 ;
F_226 ( V_7 , V_518 ,
V_1154 ) ;
goto V_572;
}
V_1127:
F_41 ( V_1118 ) ;
V_572:
return V_35 ;
}
static int F_227 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_408 ) ||
! V_7 -> V_337 -> V_1155 )
return - V_519 ;
return F_228 ( V_7 , false ) ;
}
static int F_229 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_498 V_499 ;
enum V_1106 V_1093 ;
unsigned int V_1156 ;
int V_35 ;
V_1093 = F_230 ( V_17 -> V_18 ) ;
if ( V_1093 == V_1107 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_499 ) ;
if ( V_35 )
return V_35 ;
if ( F_231 ( V_518 ) )
return - V_523 ;
if ( V_17 -> V_1157 )
return - V_523 ;
V_35 = F_232 ( V_17 -> V_18 , & V_499 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_233 ( V_17 -> V_18 , & V_499 ) )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_1158 )
return - V_519 ;
V_1156 = F_234 ( & V_7 -> V_18 , & V_499 ) ;
if ( F_59 ( ! V_1156 ) )
V_1156 = V_1159 ;
V_35 = V_7 -> V_337 -> V_1158 ( & V_7 -> V_18 , V_518 , & V_499 ,
V_1156 ) ;
if ( ! V_35 ) {
V_17 -> V_499 = V_499 ;
V_17 -> V_1157 = true ;
V_17 -> V_1160 = V_1136 ;
V_17 -> V_1156 = V_1156 ;
}
return V_35 ;
}
static int F_235 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_1161 V_137 ;
static struct V_4 * V_1162 [ V_1163 + 1 ] ;
T_2 V_1164 = 0 ;
int V_35 ;
bool V_1165 = false ;
int V_47 , V_153 ;
if ( ! V_7 -> V_337 -> V_428 ||
! ( V_7 -> V_18 . V_51 & V_427 ) )
return - V_519 ;
switch ( V_518 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1165 = true ;
if ( ! V_17 -> V_520 )
return - V_1166 ;
break;
case V_146 :
if ( ! V_17 -> V_565 )
return - V_1166 ;
break;
case V_145 :
if ( ! V_17 -> V_992 )
return - V_1166 ;
break;
default:
return - V_519 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_501 ] ||
! V_30 -> V_5 [ V_1167 ] )
return - V_16 ;
if ( V_1165 && ! V_30 -> V_5 [ V_1168 ] )
return - V_16 ;
V_137 . V_1169 = F_4 ( V_30 -> V_5 [ V_1167 ] ) ;
if ( ! V_1165 )
goto V_1170;
V_35 = F_144 ( V_30 -> V_5 , & V_137 . V_1171 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1162 , V_1163 ,
V_30 -> V_5 [ V_1168 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_144 ( V_1162 , & V_137 . V_1172 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1162 [ V_1173 ] )
return - V_16 ;
V_47 = F_24 ( V_1162 [ V_1173 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1174 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_472 &&
( V_137 . V_1174 >
V_7 -> V_18 . V_472 ) )
return - V_16 ;
V_137 . V_1175 =
F_23 ( V_1162 [ V_1173 ] ) ;
for ( V_153 = 0 ; V_153 < V_137 . V_1174 ; V_153 ++ ) {
T_3 V_1176 = V_137 . V_1175 [ V_153 ] ;
if ( V_1176 >= V_137 . V_1172 . V_659 )
return - V_16 ;
if ( V_137 . V_1172 . V_658 [ V_1176 ] != V_137 . V_1169 )
return - V_16 ;
}
if ( V_1162 [ V_1177 ] ) {
V_47 = F_24 ( V_1162 [ V_1177 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1178 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_472 &&
( V_137 . V_1174 >
V_7 -> V_18 . V_472 ) )
return - V_16 ;
V_137 . V_1179 =
F_23 ( V_1162 [ V_1177 ] ) ;
for ( V_153 = 0 ; V_153 < V_137 . V_1178 ; V_153 ++ ) {
T_3 V_1176 = V_137 . V_1179 [ V_153 ] ;
if ( V_1176 >= V_137 . V_1172 . V_668 )
return - V_16 ;
if ( V_137 . V_1172 . V_667 [ V_1176 ] !=
V_137 . V_1169 )
return - V_16 ;
}
}
V_1170:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_499 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_499 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_232 ( V_17 -> V_18 ,
& V_137 . V_499 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 ) {
V_1164 = F_156 ( V_137 . V_499 . V_502 ) ;
V_137 . V_1180 = true ;
}
V_35 = F_236 ( V_7 , V_17 , V_17 -> V_141 ,
V_137 . V_499 . V_55 ,
V_1181 ,
V_1164 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_1182 ] )
V_137 . V_1183 = true ;
F_112 ( V_17 ) ;
V_35 = F_237 ( V_7 , V_518 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_238 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1184 * V_1185 )
{
struct V_1186 * V_341 = & V_1185 -> V_1187 ;
const struct V_1188 * V_1189 ;
void * V_275 ;
struct V_4 * V_1190 ;
bool V_1191 = false ;
F_43 ( V_17 ) ;
V_275 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1192 ) ;
if ( ! V_275 )
return - 1 ;
F_239 ( V_34 , V_275 , & V_38 ) ;
if ( F_28 ( V_53 , V_285 , V_7 -> V_1193 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
V_1190 = F_47 ( V_53 , V_1194 ) ;
if ( ! V_1190 )
goto V_61;
if ( ( ! F_240 ( V_341 -> V_525 ) &&
F_51 ( V_53 , V_1195 , V_562 , V_341 -> V_525 ) ) )
goto V_61;
F_208 () ;
V_1189 = F_209 ( V_341 -> V_1189 ) ;
if ( V_1189 ) {
if ( F_104 ( V_53 , V_1196 , V_1189 -> V_1191 ) )
goto V_1197;
V_1191 = true ;
if ( V_1189 -> V_47 && F_51 ( V_53 , V_1198 ,
V_1189 -> V_47 , V_1189 -> V_138 ) )
goto V_1197;
}
V_1189 = F_209 ( V_341 -> V_660 ) ;
if ( V_1189 ) {
if ( ! V_1191 && F_104 ( V_53 , V_1196 , V_1189 -> V_1191 ) )
goto V_1197;
if ( V_1189 -> V_47 && F_51 ( V_53 , V_1199 ,
V_1189 -> V_47 , V_1189 -> V_138 ) )
goto V_1197;
}
F_211 () ;
if ( V_341 -> V_520 &&
F_55 ( V_53 , V_1200 , V_341 -> V_520 ) )
goto V_61;
if ( F_55 ( V_53 , V_1201 , V_341 -> V_897 ) ||
F_28 ( V_53 , V_1202 , V_341 -> V_1203 -> V_60 ) ||
F_28 ( V_53 , V_1204 , V_341 -> V_1205 ) ||
F_28 ( V_53 , V_1206 ,
F_241 ( V_1136 - V_1185 -> V_1207 ) ) )
goto V_61;
switch ( V_7 -> V_18 . V_777 ) {
case V_778 :
if ( F_28 ( V_53 , V_1208 , V_341 -> signal ) )
goto V_61;
break;
case V_1209 :
if ( F_56 ( V_53 , V_1210 , V_341 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1185 == V_17 -> V_149 &&
F_28 ( V_53 , V_1211 ,
V_1212 ) )
goto V_61;
break;
case V_146 :
if ( V_1185 == V_17 -> V_149 &&
F_28 ( V_53 , V_1211 ,
V_1213 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1190 ) ;
return F_66 ( V_53 , V_275 ) ;
V_1197:
F_211 () ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
static int F_242 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1184 * V_1120 ;
struct V_1 * V_17 ;
int V_477 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
F_243 ( & V_7 -> V_1214 ) ;
F_244 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1193 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_477 )
continue;
if ( F_238 ( V_32 , V_34 ,
V_34 -> V_36 -> V_478 , V_479 ,
V_7 , V_17 , V_1120 ) < 0 ) {
V_105 -- ;
break;
}
}
F_245 ( & V_7 -> V_1214 ) ;
F_114 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_246 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_518 ,
struct V_1215 * V_1216 )
{
void * V_275 ;
struct V_4 * V_1217 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1218 ) ;
if ( ! V_275 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_518 -> V_20 ) )
goto V_61;
V_1217 = F_47 ( V_53 , V_1219 ) ;
if ( ! V_1217 )
goto V_61;
if ( F_28 ( V_53 , V_1220 ,
V_1216 -> V_1203 -> V_60 ) )
goto V_61;
if ( ( V_1216 -> V_751 & V_1221 ) &&
F_56 ( V_53 , V_1222 , V_1216 -> V_1223 ) )
goto V_61;
if ( ( V_1216 -> V_751 & V_1224 ) &&
F_29 ( V_53 , V_1225 ) )
goto V_61;
if ( ( V_1216 -> V_751 & V_1226 ) &&
F_104 ( V_53 , V_1227 ,
V_1216 -> V_1228 ) )
goto V_61;
if ( ( V_1216 -> V_751 & V_1229 ) &&
F_104 ( V_53 , V_1230 ,
V_1216 -> V_1231 ) )
goto V_61;
if ( ( V_1216 -> V_751 & V_1232 ) &&
F_104 ( V_53 , V_1233 ,
V_1216 -> V_1234 ) )
goto V_61;
if ( ( V_1216 -> V_751 & V_1235 ) &&
F_104 ( V_53 , V_1236 ,
V_1216 -> V_1237 ) )
goto V_61;
if ( ( V_1216 -> V_751 & V_1238 ) &&
F_104 ( V_53 , V_1239 ,
V_1216 -> V_1240 ) )
goto V_61;
F_48 ( V_53 , V_1217 ) ;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
static int F_247 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1215 V_1216 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1241 = V_34 -> args [ 2 ] ;
int V_341 ;
V_341 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_341 )
return V_341 ;
if ( ! V_17 -> V_19 ) {
V_341 = - V_16 ;
goto V_843;
}
if ( ! V_7 -> V_337 -> V_1242 ) {
V_341 = - V_519 ;
goto V_843;
}
while ( 1 ) {
struct V_54 * V_55 ;
V_341 = F_248 ( V_7 , V_17 -> V_19 , V_1241 , & V_1216 ) ;
if ( V_341 == - V_625 )
break;
if ( V_341 )
goto V_843;
if ( ! V_1216 . V_1203 ) {
V_341 = - V_16 ;
goto V_572;
}
V_55 = F_45 ( & V_7 -> V_18 ,
V_1216 . V_1203 -> V_60 ) ;
if ( ! V_55 || V_55 -> V_51 & V_62 ) {
V_1241 ++ ;
continue;
}
if ( F_246 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_478 , V_479 ,
V_17 -> V_19 , & V_1216 ) < 0 )
goto V_572;
V_1241 ++ ;
}
V_572:
V_34 -> args [ 2 ] = V_1241 ;
V_341 = V_32 -> V_47 ;
V_843:
F_21 ( V_7 ) ;
return V_341 ;
}
static bool F_249 ( V_22 V_1243 )
{
return ! ( V_1243 & ~ ( V_1244 |
V_1245 ) ) ;
}
static int F_250 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_525 , * V_567 , * V_1076 = NULL , * V_1246 = NULL ;
int V_35 , V_565 , V_1077 = 0 , V_1247 = 0 ;
enum V_670 V_671 ;
struct V_93 V_92 ;
bool V_1248 ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_689 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_566 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_501 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_621 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1249 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1250 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_153 ;
bool V_1251 = false ;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_324 ; V_153 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_325 [ V_153 ] ) {
V_1251 = true ;
break;
}
}
if ( ! V_1251 )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_371 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_501 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_567 = F_23 ( V_30 -> V_5 [ V_566 ] ) ;
V_565 = F_24 ( V_30 -> V_5 [ V_566 ] ) ;
if ( V_30 -> V_5 [ V_652 ] ) {
V_1076 = F_23 ( V_30 -> V_5 [ V_652 ] ) ;
V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
}
V_671 = F_4 ( V_30 -> V_5 [ V_689 ] ) ;
if ( ! F_146 ( V_7 , V_671 , V_673 ) )
return - V_16 ;
if ( V_671 == V_675 &&
! V_30 -> V_5 [ V_1252 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1252 ] ) {
if ( V_671 != V_675 )
return - V_16 ;
V_1246 = F_23 ( V_30 -> V_5 [ V_1252 ] ) ;
V_1247 = F_24 ( V_30 -> V_5 [ V_1252 ] ) ;
if ( V_1247 < 4 )
return - V_16 ;
}
V_1248 = ! ! V_30 -> V_5 [ V_1253 ] ;
if ( V_1248 )
return 0 ;
F_112 ( V_518 -> V_28 ) ;
V_35 = F_251 ( V_7 , V_518 , V_55 , V_671 , V_525 ,
V_567 , V_565 , V_1076 , V_1077 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1246 , V_1247 ) ;
F_114 ( V_518 -> V_28 ) ;
return V_35 ;
}
static int F_149 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1254 * V_1255 ,
int V_1256 )
{
memset ( V_1255 , 0 , sizeof( * V_1255 ) ) ;
V_1255 -> V_1257 = V_30 -> V_5 [ V_1258 ] ;
if ( V_30 -> V_5 [ V_329 ] ) {
T_3 V_1259 ;
V_1259 = F_78 (
V_30 -> V_5 [ V_329 ] ) ;
V_1255 -> V_1260 = F_252 ( V_1259 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) &&
V_1259 != V_1261 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1262 ] )
V_1255 -> V_1263 = true ;
} else
V_1255 -> V_1260 = F_252 ( V_1261 ) ;
if ( V_30 -> V_5 [ V_1264 ] ) {
void * V_138 ;
int V_47 , V_153 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1264 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1264 ] ) ;
V_1255 -> V_1265 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1255 -> V_1265 > V_1256 )
return - V_16 ;
memcpy ( V_1255 -> V_1266 , V_138 , V_47 ) ;
for ( V_153 = 0 ; V_153 < V_1255 -> V_1265 ; V_153 ++ )
if ( ! F_253 (
& V_7 -> V_18 ,
V_1255 -> V_1266 [ V_153 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1267 ] ) {
V_1255 -> V_1268 =
F_4 ( V_30 -> V_5 [ V_1267 ] ) ;
if ( ! F_253 ( & V_7 -> V_18 ,
V_1255 -> V_1268 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1269 ] ) {
V_1255 -> V_1243 =
F_4 ( V_30 -> V_5 [ V_1269 ] ) ;
if ( ! F_249 ( V_1255 -> V_1243 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1270 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1270 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1270 ] ) ;
V_1255 -> V_1271 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1255 -> V_1271 > V_1272 )
return - V_16 ;
memcpy ( V_1255 -> V_1273 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_254 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1274 V_1275 = {} ;
const T_2 * V_525 , * V_567 ;
int V_35 , V_565 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] ||
! V_30 -> V_5 [ V_566 ] ||
! V_30 -> V_5 [ V_501 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_373 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_501 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_567 = F_23 ( V_30 -> V_5 [ V_566 ] ) ;
V_565 = F_24 ( V_30 -> V_5 [ V_566 ] ) ;
if ( V_30 -> V_5 [ V_652 ] ) {
V_1275 . V_1076 = F_23 ( V_30 -> V_5 [ V_652 ] ) ;
V_1275 . V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
}
if ( V_30 -> V_5 [ V_1276 ] ) {
enum V_1277 V_1278 =
F_4 ( V_30 -> V_5 [ V_1276 ] ) ;
if ( V_1278 == V_1279 )
V_1275 . V_1280 = true ;
else if ( V_1278 != V_1281 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1282 ] )
V_1275 . V_1283 = F_23 ( V_30 -> V_5 [ V_1282 ] ) ;
if ( F_203 ( V_30 -> V_5 [ V_1284 ] ) )
V_1275 . V_51 |= V_1285 ;
if ( V_30 -> V_5 [ V_448 ] )
memcpy ( & V_1275 . V_1286 ,
F_23 ( V_30 -> V_5 [ V_448 ] ) ,
sizeof( V_1275 . V_1286 ) ) ;
if ( V_30 -> V_5 [ V_890 ] ) {
if ( ! V_30 -> V_5 [ V_448 ] )
return - V_16 ;
memcpy ( & V_1275 . V_862 ,
F_23 ( V_30 -> V_5 [ V_890 ] ) ,
sizeof( V_1275 . V_862 ) ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1287 ] ) )
V_1275 . V_51 |= V_1288 ;
if ( V_30 -> V_5 [ V_457 ] )
memcpy ( & V_1275 . V_1289 ,
F_23 ( V_30 -> V_5 [ V_457 ] ) ,
sizeof( V_1275 . V_1289 ) ) ;
if ( V_30 -> V_5 [ V_891 ] ) {
if ( ! V_30 -> V_5 [ V_457 ] )
return - V_16 ;
memcpy ( & V_1275 . V_863 ,
F_23 ( V_30 -> V_5 [ V_891 ] ) ,
sizeof( V_1275 . V_863 ) ) ;
}
V_35 = F_149 ( V_7 , V_30 , & V_1275 . V_691 , 1 ) ;
if ( ! V_35 ) {
F_112 ( V_518 -> V_28 ) ;
V_35 = F_255 ( V_7 , V_518 , V_55 , V_525 ,
V_567 , V_565 , & V_1275 ) ;
F_114 ( V_518 -> V_28 ) ;
}
return V_35 ;
}
static int F_256 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
const T_2 * V_1076 = NULL , * V_525 ;
int V_1077 = 0 , V_35 ;
T_3 V_1290 ;
bool V_1248 ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1291 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_375 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_1290 = F_78 ( V_30 -> V_5 [ V_1291 ] ) ;
if ( V_1290 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_652 ] ) {
V_1076 = F_23 ( V_30 -> V_5 [ V_652 ] ) ;
V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
}
V_1248 = ! ! V_30 -> V_5 [ V_1253 ] ;
F_112 ( V_518 -> V_28 ) ;
V_35 = F_257 ( V_7 , V_518 , V_525 , V_1076 , V_1077 , V_1290 ,
V_1248 ) ;
F_114 ( V_518 -> V_28 ) ;
return V_35 ;
}
static int F_258 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
const T_2 * V_1076 = NULL , * V_525 ;
int V_1077 = 0 , V_35 ;
T_3 V_1290 ;
bool V_1248 ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1291 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_377 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_1290 = F_78 ( V_30 -> V_5 [ V_1291 ] ) ;
if ( V_1290 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_652 ] ) {
V_1076 = F_23 ( V_30 -> V_5 [ V_652 ] ) ;
V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
}
V_1248 = ! ! V_30 -> V_5 [ V_1253 ] ;
F_112 ( V_518 -> V_28 ) ;
V_35 = F_259 ( V_7 , V_518 , V_525 , V_1076 , V_1077 , V_1290 ,
V_1248 ) ;
F_114 ( V_518 -> V_28 ) ;
return V_35 ;
}
static bool
F_260 ( struct V_6 * V_7 ,
int V_1292 [ V_348 ] ,
int V_1293 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_282 , V_153 ;
for ( V_282 = 0 ; V_282 < V_348 ; V_282 ++ ) {
struct V_230 * V_231 ;
V_231 = V_18 -> V_349 [ V_282 ] ;
if ( ! V_231 )
continue;
for ( V_153 = 0 ; V_153 < V_231 -> V_252 ; V_153 ++ ) {
if ( V_231 -> V_253 [ V_153 ] . V_255 == V_1293 ) {
V_1292 [ V_282 ] = V_153 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_261 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1294 V_1295 ;
struct V_18 * V_18 ;
struct V_130 * V_1296 = NULL ;
int V_35 ;
memset ( & V_1295 , 0 , sizeof( V_1295 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_566 ] ||
! F_24 ( V_30 -> V_5 [ V_566 ] ) )
return - V_16 ;
V_1295 . V_520 = 100 ;
if ( V_30 -> V_5 [ V_678 ] ) {
V_1295 . V_520 =
F_4 ( V_30 -> V_5 [ V_678 ] ) ;
if ( V_1295 . V_520 < 1 || V_1295 . V_520 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_379 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_146 )
return - V_519 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_526 ] ) {
V_1295 . V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( ! F_119 ( V_1295 . V_525 ) )
return - V_16 ;
}
V_1295 . V_567 = F_23 ( V_30 -> V_5 [ V_566 ] ) ;
V_1295 . V_565 = F_24 ( V_30 -> V_5 [ V_566 ] ) ;
if ( V_30 -> V_5 [ V_652 ] ) {
V_1295 . V_1076 = F_23 ( V_30 -> V_5 [ V_652 ] ) ;
V_1295 . V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1295 . V_499 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_1295 . V_499 ,
V_146 ) )
return - V_16 ;
switch ( V_1295 . V_499 . V_502 ) {
case V_516 :
case V_517 :
case V_503 :
break;
case V_556 :
case V_557 :
if ( V_7 -> V_18 . V_283 & V_1297 )
break;
default:
return - V_16 ;
}
V_1295 . V_1298 = ! ! V_30 -> V_5 [ V_1299 ] ;
V_1295 . V_687 = ! ! V_30 -> V_5 [ V_688 ] ;
if ( V_30 -> V_5 [ V_957 ] ) {
T_2 * V_1128 =
F_23 ( V_30 -> V_5 [ V_957 ] ) ;
int V_1300 =
F_24 ( V_30 -> V_5 [ V_957 ] ) ;
struct V_230 * V_231 =
V_18 -> V_349 [ V_1295 . V_499 . V_55 -> V_282 ] ;
V_35 = F_220 ( V_231 , V_1128 , V_1300 ,
& V_1295 . V_958 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_448 ] )
memcpy ( & V_1295 . V_1286 ,
F_23 ( V_30 -> V_5 [ V_448 ] ) ,
sizeof( V_1295 . V_1286 ) ) ;
if ( V_30 -> V_5 [ V_890 ] ) {
if ( ! V_30 -> V_5 [ V_448 ] )
return - V_16 ;
memcpy ( & V_1295 . V_862 ,
F_23 ( V_30 -> V_5 [ V_890 ] ) ,
sizeof( V_1295 . V_862 ) ) ;
}
if ( V_30 -> V_5 [ V_1301 ] &&
! F_260 ( V_7 , V_1295 . V_1292 ,
F_4 ( V_30 -> V_5 [ V_1301 ] ) ) )
return - V_16 ;
if ( V_1295 . V_687 && V_30 -> V_5 [ V_1302 ] ) {
bool V_132 = false ;
V_1296 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1302 ] ,
& V_132 ) ;
if ( F_17 ( V_1296 ) )
return F_18 ( V_1296 ) ;
if ( ( V_1295 . V_499 . V_502 != V_503 ) &&
V_132 ) {
F_41 ( V_1296 ) ;
return - V_16 ;
}
}
V_1295 . V_1257 =
F_203 ( V_30 -> V_5 [ V_1258 ] ) ;
V_1295 . V_1303 =
F_203 ( V_30 -> V_5 [ V_1304 ] ) ;
V_35 = F_262 ( V_7 , V_518 , & V_1295 , V_1296 ) ;
if ( V_35 )
F_41 ( V_1296 ) ;
return V_35 ;
}
static int F_263 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_1305 )
return - V_519 ;
if ( V_518 -> V_28 -> V_141 != V_146 )
return - V_519 ;
return F_264 ( V_7 , V_518 , false ) ;
}
static int F_265 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
int V_1292 [ V_348 ] ;
V_22 V_1306 ;
int V_35 ;
if ( V_518 -> V_28 -> V_141 != V_146 &&
V_518 -> V_28 -> V_141 != V_145 )
return - V_519 ;
if ( ! V_7 -> V_337 -> V_419 )
return - V_519 ;
memset ( V_1292 , 0 , sizeof( V_1292 ) ) ;
if ( ! V_30 -> V_5 [ V_1301 ] )
return - V_16 ;
V_1306 = F_4 ( V_30 -> V_5 [ V_1301 ] ) ;
if ( ! F_260 ( V_7 , V_1292 , V_1306 ) )
return - V_16 ;
V_35 = V_7 -> V_337 -> V_419 ( & V_7 -> V_18 , V_518 , V_1292 ) ;
return V_35 ;
}
static struct V_31 *
F_266 ( struct V_6 * V_7 ,
int V_1307 , V_22 V_49 , V_22 V_50 ,
enum V_272 V_52 ,
enum V_1308 V_45 ,
const struct V_464 * V_30 ,
T_12 V_1309 )
{
struct V_31 * V_32 ;
void * V_275 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1307 + 100 , V_1309 ) ;
if ( ! V_32 )
return NULL ;
V_275 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_267 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1310 ,
V_30 -> V_1311 ) )
goto V_61;
if ( F_28 ( V_32 , V_1312 ,
V_30 -> V_1313 ) )
goto V_61;
}
V_138 = F_47 ( V_32 , V_45 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_275 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_138 ;
return V_32 ;
V_61:
F_267 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_268 ( struct V_18 * V_18 ,
enum V_272 V_52 ,
enum V_1308 V_45 ,
int V_1314 ,
int V_1307 , T_12 V_1309 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_464 * V_30 ;
switch ( V_52 ) {
case V_1315 :
if ( F_59 ( V_1314 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1316 :
if ( F_59 ( V_1314 < 0 ||
V_1314 >= V_18 -> V_468 ) )
return NULL ;
V_30 = & V_18 -> V_470 [ V_1314 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_266 ( V_7 , V_1307 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1309 ) ;
}
void F_269 ( struct V_31 * V_32 , T_12 V_1309 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_275 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1317 V_1318 = V_1319 ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_275 ) ;
if ( V_138 -> F_219 == V_466 )
V_1318 = V_1320 ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1318 , V_1309 ) ;
}
static int F_271 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_337 -> V_421 )
return - V_519 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1321 ] )
return - V_16 ;
V_7 -> V_1322 = V_30 ;
V_35 = F_272 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1321 ] ) ,
F_24 ( V_30 -> V_5 [ V_1321 ] ) ) ;
V_7 -> V_1322 = NULL ;
return V_35 ;
}
static int F_273 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1323 ;
void * V_138 = NULL ;
int V_1324 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1323 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_843;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_843;
}
V_1323 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1321 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1321 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1324 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1323 ) ;
if ( ! V_7 ) {
V_35 = - V_625 ;
goto V_843;
}
if ( ! V_7 -> V_337 -> V_1325 ) {
V_35 = - V_519 ;
goto V_843;
}
while ( 1 ) {
void * V_275 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_478 , V_479 ,
V_1315 ) ;
struct V_4 * V_1326 ;
if ( ! V_275 )
break;
if ( F_28 ( V_32 , V_26 , V_1323 ) ) {
F_67 ( V_32 , V_275 ) ;
break;
}
V_1326 = F_47 ( V_32 , V_1321 ) ;
if ( ! V_1326 ) {
F_67 ( V_32 , V_275 ) ;
break;
}
V_35 = F_274 ( V_7 , V_32 , V_34 , V_138 , V_1324 ) ;
F_48 ( V_32 , V_1326 ) ;
if ( V_35 == - V_91 || V_35 == - V_625 ) {
F_67 ( V_32 , V_275 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_275 ) ;
goto V_843;
}
F_66 ( V_32 , V_275 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1323 + 1 ;
V_843:
F_20 () ;
return V_35 ;
}
static int F_275 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1327 V_432 ;
struct V_18 * V_18 ;
struct V_130 * V_1296 = NULL ;
int V_35 ;
memset ( & V_432 , 0 , sizeof( V_432 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_566 ] ||
! F_24 ( V_30 -> V_5 [ V_566 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_689 ] ) {
V_432 . V_671 =
F_4 ( V_30 -> V_5 [ V_689 ] ) ;
if ( ! F_146 ( V_7 , V_432 . V_671 ,
V_433 ) )
return - V_16 ;
} else
V_432 . V_671 = V_690 ;
V_432 . V_687 = V_30 -> V_5 [ V_688 ] ;
V_35 = F_149 ( V_7 , V_30 , & V_432 . V_691 ,
V_692 ) ;
if ( V_35 )
return V_35 ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
V_18 = & V_7 -> V_18 ;
V_432 . V_1328 = - 1 ;
if ( V_30 -> V_5 [ V_1329 ] &&
( V_18 -> V_51 & V_316 ) ) {
V_432 . V_1328 =
F_78 ( V_30 -> V_5 [ V_1329 ] ) ;
}
if ( V_30 -> V_5 [ V_526 ] )
V_432 . V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
else if ( V_30 -> V_5 [ V_1330 ] )
V_432 . V_1331 =
F_23 ( V_30 -> V_5 [ V_1330 ] ) ;
V_432 . V_567 = F_23 ( V_30 -> V_5 [ V_566 ] ) ;
V_432 . V_565 = F_24 ( V_30 -> V_5 [ V_566 ] ) ;
if ( V_30 -> V_5 [ V_652 ] ) {
V_432 . V_1076 = F_23 ( V_30 -> V_5 [ V_652 ] ) ;
V_432 . V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
}
if ( V_30 -> V_5 [ V_1276 ] ) {
V_432 . V_1278 = F_4 ( V_30 -> V_5 [ V_1276 ] ) ;
if ( V_432 . V_1278 != V_1279 &&
V_432 . V_1278 != V_1281 )
return - V_16 ;
} else {
V_432 . V_1278 = V_1281 ;
}
if ( V_30 -> V_5 [ V_501 ] ) {
V_432 . V_1203 = F_44 (
V_18 , V_30 -> V_5 [ V_501 ] ) ;
if ( ! V_432 . V_1203 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1332 ] ) {
V_432 . V_1333 = F_44 (
V_18 , V_30 -> V_5 [ V_1332 ] ) ;
if ( ! V_432 . V_1333 )
return - V_16 ;
}
if ( V_432 . V_687 && V_30 -> V_5 [ V_1302 ] ) {
V_1296 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1302 ] , NULL ) ;
if ( F_17 ( V_1296 ) )
return F_18 ( V_1296 ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1284 ] ) )
V_432 . V_51 |= V_1285 ;
if ( V_30 -> V_5 [ V_448 ] )
memcpy ( & V_432 . V_1286 ,
F_23 ( V_30 -> V_5 [ V_448 ] ) ,
sizeof( V_432 . V_1286 ) ) ;
if ( V_30 -> V_5 [ V_890 ] ) {
if ( ! V_30 -> V_5 [ V_448 ] ) {
F_41 ( V_1296 ) ;
return - V_16 ;
}
memcpy ( & V_432 . V_862 ,
F_23 ( V_30 -> V_5 [ V_890 ] ) ,
sizeof( V_432 . V_862 ) ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1287 ] ) )
V_432 . V_51 |= V_1288 ;
if ( V_30 -> V_5 [ V_457 ] )
memcpy ( & V_432 . V_1289 ,
F_23 ( V_30 -> V_5 [ V_457 ] ) ,
sizeof( V_432 . V_1289 ) ) ;
if ( V_30 -> V_5 [ V_891 ] ) {
if ( ! V_30 -> V_5 [ V_457 ] ) {
F_41 ( V_1296 ) ;
return - V_16 ;
}
memcpy ( & V_432 . V_863 ,
F_23 ( V_30 -> V_5 [ V_891 ] ) ,
sizeof( V_432 . V_863 ) ) ;
}
F_112 ( V_518 -> V_28 ) ;
V_35 = F_276 ( V_7 , V_518 , & V_432 , V_1296 , NULL ) ;
F_114 ( V_518 -> V_28 ) ;
if ( V_35 )
F_41 ( V_1296 ) ;
return V_35 ;
}
static int F_277 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_3 V_1334 ;
int V_474 ;
if ( ! V_30 -> V_5 [ V_1291 ] )
V_1334 = V_1335 ;
else
V_1334 = F_78 ( V_30 -> V_5 [ V_1291 ] ) ;
if ( V_1334 == 0 )
return - V_16 ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
F_112 ( V_518 -> V_28 ) ;
V_474 = F_278 ( V_7 , V_518 , V_1334 , true ) ;
F_114 ( V_518 -> V_28 ) ;
return V_474 ;
}
static int F_279 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
V_22 V_1336 ;
if ( ! V_30 -> V_5 [ V_1337 ] )
return - V_16 ;
V_1336 = F_4 ( V_30 -> V_5 [ V_1337 ] ) ;
V_2 = F_280 ( V_1336 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_281 ( V_7 , V_2 ) ;
F_282 ( V_2 ) ;
return V_35 ;
}
static int F_283 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
int (* F_284)( struct V_18 * V_18 , struct V_25 * V_518 ,
struct V_1338 * V_1339 ) = NULL ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1338 V_1339 ;
memset ( & V_1339 , 0 , sizeof( struct V_1338 ) ) ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1340 ] )
return - V_16 ;
V_1339 . V_1341 = F_23 ( V_30 -> V_5 [ V_1340 ] ) ;
V_1339 . V_525 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
switch ( V_30 -> V_1342 -> V_52 ) {
case V_1343 :
F_284 = V_7 -> V_337 -> V_383 ;
break;
case V_1344 :
F_284 = V_7 -> V_337 -> V_385 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_284 )
return - V_519 ;
return F_284 ( & V_7 -> V_18 , V_518 , & V_1339 ) ;
}
static int F_285 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
if ( V_518 -> V_28 -> V_141 != V_147 &&
V_518 -> V_28 -> V_141 != V_148 )
return - V_519 ;
if ( ! V_7 -> V_337 -> V_387 )
return - V_519 ;
return F_286 ( V_7 , V_518 ) ;
}
static int F_287 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 V_1345 , V_1346 ;
V_22 V_1347 = 0 ;
T_3 V_1348 ;
T_2 * V_1349 ;
if ( ! ( V_7 -> V_18 . V_51 & V_318 ) ||
! V_7 -> V_337 -> V_404 )
return - V_519 ;
if ( ! V_30 -> V_5 [ V_1350 ] ||
! V_30 -> V_5 [ V_1351 ] ||
! V_30 -> V_5 [ V_1352 ] ||
! V_30 -> V_5 [ V_652 ] ||
! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
V_1349 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_1345 = F_34 ( V_30 -> V_5 [ V_1350 ] ) ;
V_1348 = F_78 ( V_30 -> V_5 [ V_1351 ] ) ;
V_1346 = F_34 ( V_30 -> V_5 [ V_1352 ] ) ;
if ( V_30 -> V_5 [ V_1353 ] )
V_1347 =
F_4 ( V_30 -> V_5 [ V_1353 ] ) ;
return F_288 ( V_7 , V_518 , V_1349 , V_1345 ,
V_1346 , V_1348 , V_1347 ,
F_23 ( V_30 -> V_5 [ V_652 ] ) ,
F_24 ( V_30 -> V_5 [ V_652 ] ) ) ;
}
static int F_289 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
enum V_1354 V_1355 ;
T_2 * V_1349 ;
if ( ! ( V_7 -> V_18 . V_51 & V_318 ) ||
! V_7 -> V_337 -> V_406 )
return - V_519 ;
if ( ! V_30 -> V_5 [ V_1356 ] ||
! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
V_1355 = F_34 ( V_30 -> V_5 [ V_1356 ] ) ;
V_1349 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
return F_290 ( V_7 , V_518 , V_1349 , V_1355 ) ;
}
static int F_291 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
struct V_498 V_499 ;
struct V_31 * V_53 ;
void * V_275 ;
T_1 V_616 ;
V_22 V_1357 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_501 ] ||
! V_30 -> V_5 [ V_1358 ] )
return - V_16 ;
V_1357 = F_4 ( V_30 -> V_5 [ V_1358 ] ) ;
if ( ! V_7 -> V_337 -> V_390 ||
! ( V_7 -> V_18 . V_51 & V_389 ) )
return - V_519 ;
if ( V_1357 < V_1359 ||
V_1357 > V_7 -> V_18 . V_437 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_499 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1360 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_626;
}
V_35 = F_292 ( V_7 , V_17 , V_499 . V_55 ,
V_1357 , & V_616 ) ;
if ( V_35 )
goto V_626;
if ( F_104 ( V_53 , V_1361 , V_616 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_626:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_293 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
T_1 V_616 ;
if ( ! V_30 -> V_5 [ V_1361 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_1362 )
return - V_519 ;
V_616 = F_5 ( V_30 -> V_5 [ V_1361 ] ) ;
return F_294 ( V_7 , V_17 , V_616 ) ;
}
static V_22 F_295 ( struct V_230 * V_231 ,
T_2 * V_1128 , T_2 V_1363 )
{
T_2 V_153 ;
V_22 V_709 = 0 ;
for ( V_153 = 0 ; V_153 < V_1363 ; V_153 ++ ) {
int V_235 = ( V_1128 [ V_153 ] & 0x7f ) * 5 ;
int V_1364 ;
for ( V_1364 = 0 ; V_1364 < V_231 -> V_252 ; V_1364 ++ ) {
struct V_234 * V_1365 =
& V_231 -> V_253 [ V_1364 ] ;
if ( V_235 == V_1365 -> V_255 ) {
V_709 |= 1 << V_1364 ;
break;
}
}
if ( V_1364 == V_231 -> V_252 )
return 0 ;
}
return V_709 ;
}
static bool F_296 ( struct V_230 * V_231 ,
T_2 * V_1128 , T_2 V_1363 ,
T_2 V_239 [ V_1366 ] )
{
T_2 V_153 ;
memset ( V_239 , 0 , V_1366 ) ;
for ( V_153 = 0 ; V_153 < V_1363 ; V_153 ++ ) {
int V_1364 , V_1367 ;
V_1364 = V_1128 [ V_153 ] / 8 ;
V_1367 = F_156 ( V_1128 [ V_153 ] % 8 ) ;
if ( ( V_1364 < 0 ) || ( V_1364 >= V_1366 ) )
return false ;
if ( V_231 -> V_236 . V_239 . V_1368 [ V_1364 ] & V_1367 )
V_239 [ V_1364 ] |= V_1367 ;
else
return false ;
}
return true ;
}
static T_3 F_297 ( T_2 V_1369 )
{
T_3 V_1370 = 0 ;
switch ( V_1369 ) {
case V_1371 :
break;
case V_1372 :
V_1370 = 0x00FF ;
break;
case V_1373 :
V_1370 = 0x01FF ;
break;
case V_1374 :
V_1370 = 0x03FF ;
break;
default:
break;
}
return V_1370 ;
}
static void F_298 ( T_3 V_1369 ,
T_3 V_1375 [ V_1376 ] )
{
T_2 V_735 ;
for ( V_735 = 0 ; V_735 < V_1376 ; V_735 ++ ) {
V_1375 [ V_735 ] = F_297 ( V_1369 & 0x03 ) ;
V_1369 >>= 2 ;
}
}
static bool F_299 ( struct V_230 * V_231 ,
struct V_1377 * V_792 ,
T_3 V_239 [ V_1376 ] )
{
T_3 V_1378 = F_300 ( V_231 -> V_246 . V_249 . V_1378 ) ;
T_3 V_1379 [ V_1376 ] = {} ;
T_2 V_153 ;
if ( ! V_231 -> V_246 . V_247 )
return false ;
memset ( V_239 , 0 , sizeof( T_3 ) * V_1376 ) ;
F_298 ( V_1378 , V_1379 ) ;
for ( V_153 = 0 ; V_153 < V_1376 ; V_153 ++ ) {
if ( ( V_1379 [ V_153 ] & V_792 -> V_239 [ V_153 ] ) == V_792 -> V_239 [ V_153 ] )
V_239 [ V_153 ] = V_792 -> V_239 [ V_153 ] ;
else
return false ;
}
return true ;
}
static int F_301 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1380 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1381 V_709 ;
int V_134 , V_153 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_4 * V_1382 ;
struct V_230 * V_231 ;
T_3 V_1383 ;
if ( ! V_7 -> V_337 -> V_392 )
return - V_519 ;
memset ( & V_709 , 0 , sizeof( V_709 ) ) ;
for ( V_153 = 0 ; V_153 < V_348 ; V_153 ++ ) {
V_231 = V_7 -> V_18 . V_349 [ V_153 ] ;
if ( ! V_231 )
continue;
V_709 . V_1384 [ V_153 ] . V_1385 = ( 1 << V_231 -> V_252 ) - 1 ;
memcpy ( V_709 . V_1384 [ V_153 ] . V_1386 ,
V_231 -> V_236 . V_239 . V_1368 ,
sizeof( V_709 . V_1384 [ V_153 ] . V_1386 ) ) ;
if ( ! V_231 -> V_246 . V_247 )
continue;
V_1383 = F_300 ( V_231 -> V_246 . V_249 . V_1378 ) ;
F_298 ( V_1383 , V_709 . V_1384 [ V_153 ] . V_249 ) ;
}
if ( ! V_30 -> V_5 [ V_1387 ] )
goto V_572;
F_113 ( V_1388 > V_1366 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_281 V_282 = F_219 ( V_1382 ) ;
int V_35 ;
if ( V_282 < 0 || V_282 >= V_348 )
return - V_16 ;
V_231 = V_7 -> V_18 . V_349 [ V_282 ] ;
if ( V_231 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1380 , F_23 ( V_1382 ) ,
F_24 ( V_1382 ) , V_1389 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1390 ] ) {
V_709 . V_1384 [ V_282 ] . V_1385 = F_295 (
V_231 ,
F_23 ( V_95 [ V_1390 ] ) ,
F_24 ( V_95 [ V_1390 ] ) ) ;
if ( ( V_709 . V_1384 [ V_282 ] . V_1385 == 0 ) &&
F_24 ( V_95 [ V_1390 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1391 ] ) {
if ( ! F_296 (
V_231 ,
F_23 ( V_95 [ V_1391 ] ) ,
F_24 ( V_95 [ V_1391 ] ) ,
V_709 . V_1384 [ V_282 ] . V_1386 ) )
return - V_16 ;
}
if ( V_95 [ V_1392 ] ) {
if ( ! F_299 (
V_231 ,
F_23 ( V_95 [ V_1392 ] ) ,
V_709 . V_1384 [ V_282 ] . V_249 ) )
return - V_16 ;
}
if ( V_95 [ V_1393 ] ) {
V_709 . V_1384 [ V_282 ] . V_1394 =
F_34 ( V_95 [ V_1393 ] ) ;
if ( V_709 . V_1384 [ V_282 ] . V_1394 > V_1395 )
return - V_16 ;
}
if ( V_709 . V_1384 [ V_282 ] . V_1385 == 0 ) {
if ( ! ( V_7 -> V_18 . V_349 [ V_282 ] -> V_236 . V_237 ||
V_7 -> V_18 . V_349 [ V_282 ] -> V_246 . V_247 ) )
return - V_16 ;
for ( V_153 = 0 ; V_153 < V_1366 ; V_153 ++ )
if ( V_709 . V_1384 [ V_282 ] . V_1386 [ V_153 ] )
goto V_572;
for ( V_153 = 0 ; V_153 < V_1376 ; V_153 ++ )
if ( V_709 . V_1384 [ V_282 ] . V_249 [ V_153 ] )
goto V_572;
return - V_16 ;
}
}
V_572:
return F_302 ( V_7 , V_518 , NULL , & V_709 ) ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
T_3 V_1396 = V_269 | V_1397 ;
if ( ! V_30 -> V_5 [ V_1398 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_268 ] )
V_1396 = F_78 ( V_30 -> V_5 [ V_268 ] ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
case V_599 :
break;
default:
return - V_519 ;
}
if ( ! V_7 -> V_337 -> V_394 )
return - V_519 ;
return F_304 ( V_17 , V_30 -> V_482 , V_1396 ,
F_23 ( V_30 -> V_5 [ V_1398 ] ) ,
F_24 ( V_30 -> V_5 [ V_1398 ] ) ) ;
}
static int F_305 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
struct V_498 V_499 ;
int V_35 ;
void * V_275 = NULL ;
T_1 V_616 ;
struct V_31 * V_53 = NULL ;
struct V_1399 V_137 = {
. V_1400 =
V_30 -> V_5 [ V_1401 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1402 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_394 )
return - V_519 ;
switch ( V_17 -> V_141 ) {
case V_599 :
if ( ! V_30 -> V_5 [ V_501 ] )
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
return - V_519 ;
}
if ( V_30 -> V_5 [ V_1358 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_438 ) )
return - V_16 ;
V_137 . V_1403 = F_4 ( V_30 -> V_5 [ V_1358 ] ) ;
if ( V_137 . V_1403 < V_1359 ||
V_137 . V_1403 > V_7 -> V_18 . V_437 )
return - V_16 ;
}
V_137 . V_1404 = V_30 -> V_5 [ V_439 ] ;
if ( V_137 . V_1404 && ! ( V_7 -> V_18 . V_51 & V_438 ) )
return - V_16 ;
V_137 . V_1133 = F_203 ( V_30 -> V_5 [ V_1134 ] ) ;
V_499 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_501 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_499 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_499 . V_55 && V_137 . V_1404 )
return - V_16 ;
V_137 . V_1405 = F_23 ( V_30 -> V_5 [ V_1402 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1402 ] ) ;
if ( V_30 -> V_5 [ V_1406 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1406 ] ) ;
int V_153 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1407 = V_47 / sizeof( T_3 ) ;
V_137 . V_1408 =
F_23 ( V_30 -> V_5 [ V_1406 ] ) ;
for ( V_153 = 0 ; V_153 < V_137 . V_1407 ; V_153 ++ ) {
if ( V_137 . V_1408 [ V_153 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1400 ) {
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1409 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_626;
}
}
V_137 . V_55 = V_499 . V_55 ;
V_35 = F_306 ( V_7 , V_17 , & V_137 , & V_616 ) ;
if ( V_35 )
goto V_626;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1361 , V_616 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_626:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_307 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
T_1 V_616 ;
if ( ! V_30 -> V_5 [ V_1361 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_396 )
return - V_519 ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_144 :
case V_599 :
break;
default:
return - V_519 ;
}
V_616 = F_5 ( V_30 -> V_5 [ V_1361 ] ) ;
return F_308 ( V_7 , V_17 , V_616 ) ;
}
static int F_309 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 V_1410 ;
bool V_274 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1411 ] )
return - V_16 ;
V_1410 = F_4 ( V_30 -> V_5 [ V_1411 ] ) ;
if ( V_1410 != V_1412 && V_1410 != V_1413 )
return - V_16 ;
V_17 = V_518 -> V_28 ;
if ( ! V_7 -> V_337 -> V_1414 )
return - V_519 ;
V_274 = ( V_1410 == V_1413 ) ? true : false ;
if ( V_274 == V_17 -> V_1415 )
return 0 ;
V_35 = F_310 ( V_7 , V_518 , V_274 , V_17 -> V_1416 ) ;
if ( ! V_35 )
V_17 -> V_1415 = V_274 ;
return V_35 ;
}
static int F_311 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
enum V_1417 V_1410 ;
struct V_1 * V_17 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_31 * V_53 ;
void * V_275 ;
int V_35 ;
V_17 = V_518 -> V_28 ;
if ( ! V_7 -> V_337 -> V_1414 )
return - V_519 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1418 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_626;
}
if ( V_17 -> V_1415 )
V_1410 = V_1413 ;
else
V_1410 = V_1412 ;
if ( F_28 ( V_53 , V_1411 , V_1410 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_626:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_312 ( struct V_29 * V_30 ,
V_22 V_235 , V_22 V_1419 , V_22 V_1420 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
if ( V_235 > 100 || V_1420 > V_1421 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_1422 )
return - V_519 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_519 ;
return F_313 ( V_7 , V_518 , V_235 , V_1419 , V_1420 ) ;
}
static int F_314 ( struct V_29 * V_30 ,
T_11 V_1423 , V_22 V_1424 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
if ( V_1423 > 0 )
return - V_16 ;
if ( V_1423 == 0 )
V_1424 = 0 ;
if ( ! V_7 -> V_337 -> V_1425 )
return - V_519 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_519 ;
return F_315 ( V_7 , V_518 , V_1423 , V_1424 ) ;
}
static int F_316 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1426 + 1 ] ;
struct V_4 * V_1427 ;
int V_35 ;
V_1427 = V_30 -> V_5 [ V_1428 ] ;
if ( ! V_1427 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1426 , V_1427 ,
V_1429 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1430 ] &&
V_5 [ V_1431 ] ) {
T_11 V_1423 = V_1055 ( V_5 [ V_1430 ] ) ;
V_22 V_1424 = F_4 ( V_5 [ V_1431 ] ) ;
return F_314 ( V_30 , V_1423 , V_1424 ) ;
}
if ( V_5 [ V_1432 ] &&
V_5 [ V_1433 ] &&
V_5 [ V_1434 ] ) {
V_22 V_235 = F_4 ( V_5 [ V_1432 ] ) ;
V_22 V_1419 = F_4 ( V_5 [ V_1433 ] ) ;
V_22 V_1420 = F_4 ( V_5 [ V_1434 ] ) ;
return F_312 ( V_30 , V_235 , V_1419 , V_1420 ) ;
}
return - V_16 ;
}
static int F_317 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_989 V_1051 ;
struct V_1057 V_1058 ;
int V_35 ;
memcpy ( & V_1051 , & V_993 , sizeof( V_1051 ) ) ;
memcpy ( & V_1058 , & V_1435 , sizeof( V_1058 ) ) ;
if ( V_30 -> V_5 [ V_995 ] ) {
V_35 = F_200 ( V_30 , & V_1051 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_590 ] ||
! F_24 ( V_30 -> V_5 [ V_590 ] ) )
return - V_16 ;
V_1058 . V_1436 = F_23 ( V_30 -> V_5 [ V_590 ] ) ;
V_1058 . V_992 = F_24 ( V_30 -> V_5 [ V_590 ] ) ;
if ( V_30 -> V_5 [ V_1301 ] &&
! F_260 ( V_7 , V_1058 . V_1292 ,
F_4 ( V_30 -> V_5 [ V_1301 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_678 ] ) {
V_1058 . V_520 =
F_4 ( V_30 -> V_5 [ V_678 ] ) ;
if ( V_1058 . V_520 < 10 ||
V_1058 . V_520 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_679 ] ) {
V_1058 . V_681 =
F_4 ( V_30 -> V_5 [ V_679 ] ) ;
if ( V_1058 . V_681 < 1 || V_1058 . V_681 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1060 ] ) {
V_35 = F_202 ( V_30 , & V_1058 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1058 . V_1080 )
V_1051 . V_1011 = false ;
if ( V_30 -> V_5 [ V_501 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1058 . V_499 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1058 . V_499 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_957 ] ) {
T_2 * V_1128 = F_23 ( V_30 -> V_5 [ V_957 ] ) ;
int V_1300 =
F_24 ( V_30 -> V_5 [ V_957 ] ) ;
struct V_230 * V_231 ;
if ( ! V_1058 . V_499 . V_55 )
return - V_16 ;
V_231 = V_7 -> V_18 . V_349 [ V_1058 . V_499 . V_55 -> V_282 ] ;
V_35 = F_220 ( V_231 , V_1128 , V_1300 ,
& V_1058 . V_958 ) ;
if ( V_35 )
return V_35 ;
}
return F_318 ( V_7 , V_518 , & V_1058 , & V_1051 ) ;
}
static int F_319 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
return F_320 ( V_7 , V_518 ) ;
}
static int F_321 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1437 * V_183 = V_7 -> V_18 . V_1438 ;
struct V_4 * V_1439 , * V_1440 ;
int V_153 , V_1441 ;
if ( ! V_183 -> V_213 )
return 0 ;
V_1439 = F_47 ( V_53 , V_222 ) ;
if ( ! V_1439 )
return - V_91 ;
for ( V_153 = 0 ; V_153 < V_183 -> V_213 ; V_153 ++ ) {
V_1440 = F_47 ( V_53 , V_153 + 1 ) ;
if ( ! V_1440 )
return - V_91 ;
V_1441 = V_183 -> V_1442 [ V_153 ] . V_1443 ;
if ( F_51 ( V_53 , V_1444 , F_322 ( V_1441 , 8 ) ,
V_183 -> V_1442 [ V_153 ] . V_709 ) ||
F_51 ( V_53 , V_1445 , V_1441 ,
V_183 -> V_1442 [ V_153 ] . V_1446 ) ||
F_28 ( V_53 , V_1447 ,
V_183 -> V_1442 [ V_153 ] . V_1448 ) )
return - V_91 ;
F_48 ( V_53 , V_1440 ) ;
}
F_48 ( V_53 , V_1439 ) ;
return 0 ;
}
static int F_323 ( struct V_31 * V_53 ,
struct V_1449 * V_182 )
{
struct V_4 * V_184 ;
if ( ! V_182 )
return 0 ;
V_184 = F_47 ( V_53 , V_185 ) ;
if ( ! V_184 )
return - V_91 ;
if ( F_324 ( V_53 , V_1450 , V_182 -> V_1451 ) ||
F_324 ( V_53 , V_1452 , V_182 -> V_916 ) ||
F_51 ( V_53 , V_1453 , V_562 , V_182 -> V_1454 ) ||
F_55 ( V_53 , V_1455 , V_182 -> V_1456 ) ||
F_55 ( V_53 , V_1457 , V_182 -> V_1458 ) ||
F_51 ( V_53 , V_186 ,
V_182 -> V_1459 , V_182 -> V_1460 ) ||
F_28 ( V_53 , V_191 ,
V_182 -> V_1461 ) ||
F_51 ( V_53 , V_193 ,
V_182 -> V_1462 , V_182 -> V_1463 ) ||
F_51 ( V_53 , V_1464 ,
F_322 ( V_182 -> V_1462 , 8 ) , V_182 -> V_1465 ) )
return - V_91 ;
if ( V_182 -> V_1466 . V_47 &&
F_51 ( V_53 , V_188 ,
sizeof( V_182 -> V_1466 ) , & V_182 -> V_1466 ) )
return - V_91 ;
if ( V_182 -> V_1467 . V_47 &&
F_51 ( V_53 , V_190 ,
sizeof( V_182 -> V_1467 ) + V_182 -> V_1468 ,
& V_182 -> V_1467 ) )
return - V_91 ;
F_48 ( V_53 , V_184 ) ;
return 0 ;
}
static int F_325 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_31 * V_53 ;
void * V_275 ;
V_22 V_1469 = V_573 ;
if ( ! V_7 -> V_18 . V_183 )
return - V_519 ;
if ( V_7 -> V_18 . V_1438 && V_7 -> V_18 . V_1438 -> V_182 ) {
V_1469 += V_7 -> V_18 . V_1438 -> V_182 -> V_1468 +
V_7 -> V_18 . V_1438 -> V_182 -> V_1459 +
V_7 -> V_18 . V_1438 -> V_182 -> V_1462 +
V_7 -> V_18 . V_1438 -> V_182 -> V_1462 / 8 ;
}
V_53 = F_74 ( V_1469 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1470 ) ;
if ( ! V_275 )
goto V_61;
if ( V_7 -> V_18 . V_1438 ) {
struct V_4 * V_195 ;
V_195 = F_47 ( V_53 , V_1471 ) ;
if ( ! V_195 )
goto V_61;
if ( ( V_7 -> V_18 . V_1438 -> V_1472 &&
F_29 ( V_53 , V_198 ) ) ||
( V_7 -> V_18 . V_1438 -> V_434 &&
F_29 ( V_53 , V_200 ) ) ||
( V_7 -> V_18 . V_1438 -> V_1473 &&
F_29 ( V_53 , V_202 ) ) ||
( V_7 -> V_18 . V_1438 -> V_1474 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1438 -> V_1475 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1438 -> V_1476 &&
F_29 ( V_53 , V_210 ) ) ||
( V_7 -> V_18 . V_1438 -> V_1477 &&
F_29 ( V_53 , V_212 ) ) )
goto V_61;
if ( F_321 ( V_53 , V_7 ) )
goto V_61;
if ( F_323 ( V_53 ,
V_7 -> V_18 . V_1438 -> V_182 ) )
goto V_61;
F_48 ( V_53 , V_195 ) ;
}
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_326 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1437 * V_1478 )
{
struct V_4 * V_95 [ V_1479 ] ;
struct V_1449 * V_1051 ;
struct V_1480 * V_189 = NULL ;
struct V_1481 * V_50 = NULL ;
V_22 V_1469 ;
V_22 V_1482 , V_1483 , V_1468 = 0 , V_1484 ;
int V_35 , V_1485 ;
if ( ! V_7 -> V_18 . V_183 -> V_182 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1486 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1487 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1450 ] ||
! V_95 [ V_1452 ] ||
! V_95 [ V_1453 ] ||
! V_95 [ V_1457 ] ||
! V_95 [ V_186 ] ||
! V_95 [ V_191 ] ||
! V_95 [ V_193 ] ||
! V_95 [ V_1464 ] )
return - V_16 ;
V_1482 = F_24 ( V_95 [ V_186 ] ) ;
if ( V_1482 > V_7 -> V_18 . V_183 -> V_182 -> V_187 )
return - V_16 ;
if ( F_4 ( V_95 [ V_191 ] ) >
V_7 -> V_18 . V_183 -> V_182 -> V_192 ||
F_4 ( V_95 [ V_191 ] ) == 0 )
return - V_16 ;
V_1483 = F_24 ( V_95 [ V_193 ] ) ;
if ( V_1483 > V_7 -> V_18 . V_183 -> V_182 -> V_194 )
return - V_16 ;
V_1484 = F_24 ( V_95 [ V_1464 ] ) ;
if ( V_1484 != F_322 ( V_1483 , 8 ) )
return - V_16 ;
if ( V_95 [ V_190 ] ) {
V_22 V_1488 = F_24 ( V_95 [ V_190 ] ) ;
V_189 = F_23 ( V_95 [ V_190 ] ) ;
V_1468 = V_1488 - sizeof( * V_189 ) ;
if ( ! V_189 -> V_47 || V_1468 % V_189 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_183 -> V_182 -> V_189 )
return - V_16 ;
if ( V_189 -> V_47 > V_7 -> V_18 . V_183 -> V_182 -> V_189 -> V_1489 )
return - V_16 ;
if ( V_189 -> V_47 < V_7 -> V_18 . V_183 -> V_182 -> V_189 -> V_1490 )
return - V_16 ;
if ( V_1468 > V_7 -> V_18 . V_183 -> V_182 -> V_189 -> V_1491 )
return - V_16 ;
if ( V_189 -> V_1176 + V_189 -> V_47 > V_1482 )
return - V_16 ;
}
if ( V_95 [ V_188 ] ) {
V_50 = F_23 ( V_95 [ V_188 ] ) ;
if ( ! V_7 -> V_18 . V_183 -> V_182 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1176 > V_1482 )
return - V_16 ;
}
V_1469 = sizeof( * V_1051 ) ;
V_1469 += V_1482 ;
V_1469 += V_1483 + V_1484 ;
V_1469 += V_1468 ;
V_1051 = F_38 ( V_1469 , V_135 ) ;
if ( ! V_1051 )
return - V_136 ;
V_1051 -> V_1451 = F_327 ( V_95 [ V_1450 ] ) ;
V_1051 -> V_916 = F_327 ( V_95 [ V_1452 ] ) ;
memcpy ( V_1051 -> V_1454 , F_23 ( V_95 [ V_1453 ] ) ,
V_562 ) ;
if ( V_95 [ V_1455 ] )
V_1485 = F_78 ( V_95 [ V_1455 ] ) ;
else
V_1485 = 0 ;
#ifdef F_328
V_35 = F_329 ( F_7 ( & V_7 -> V_18 ) , V_1492 , V_1493 ,
V_1494 , & V_1051 -> V_1495 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1051 ) ;
return V_35 ;
}
if ( F_330 ( V_1051 -> V_1495 -> V_44 , V_1485 ) ) {
F_331 ( V_1051 -> V_1495 ) ;
F_41 ( V_1051 ) ;
return - V_1496 ;
}
V_1051 -> V_1456 = F_332 ( V_1051 -> V_1495 -> V_44 ) -> V_1497 ;
#else
if ( ! V_1485 ) {
F_41 ( V_1051 ) ;
return - V_16 ;
}
V_1051 -> V_1456 = V_1485 ;
#endif
V_1051 -> V_1458 = F_78 ( V_95 [ V_1457 ] ) ;
V_1051 -> V_1459 = V_1482 ;
V_1051 -> V_1460 = ( T_2 * ) V_1051 + sizeof( * V_1051 ) + V_1468 ;
memcpy ( ( void * ) V_1051 -> V_1460 ,
F_23 ( V_95 [ V_186 ] ) ,
V_1482 ) ;
if ( V_50 )
V_1051 -> V_1466 = * V_50 ;
V_1051 -> V_1461 = F_4 ( V_95 [ V_191 ] ) ;
V_1051 -> V_1462 = V_1483 ;
V_1051 -> V_1463 = ( T_2 * ) V_1051 + sizeof( * V_1051 ) + V_1468 + V_1482 ;
memcpy ( ( void * ) V_1051 -> V_1463 ,
F_23 ( V_95 [ V_193 ] ) ,
V_1483 ) ;
V_1051 -> V_1465 = ( T_2 * ) V_1051 + sizeof( * V_1051 ) + V_1468 +
V_1482 + V_1483 ;
memcpy ( ( void * ) V_1051 -> V_1465 ,
F_23 ( V_95 [ V_1464 ] ) ,
V_1484 ) ;
if ( V_189 ) {
V_1051 -> V_1468 = V_1468 ;
memcpy ( & V_1051 -> V_1467 , V_189 , sizeof( * V_189 ) + V_1468 ) ;
}
V_1478 -> V_182 = V_1051 ;
return 0 ;
}
static int F_333 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_4 * V_95 [ V_1498 ] ;
struct V_1437 V_1499 = {} ;
struct V_1437 * V_1500 ;
const struct V_1501 * V_183 = V_7 -> V_18 . V_183 ;
int V_35 , V_153 ;
bool V_1502 = V_7 -> V_18 . V_1438 ;
if ( ! V_183 )
return - V_519 ;
if ( ! V_30 -> V_5 [ V_1471 ] ) {
F_334 ( V_7 ) ;
V_7 -> V_18 . V_1438 = NULL ;
goto V_1503;
}
V_35 = F_96 ( V_95 , V_1504 ,
F_23 ( V_30 -> V_5 [ V_1471 ] ) ,
F_24 ( V_30 -> V_5 [ V_1471 ] ) ,
V_1505 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_198 ] ) {
if ( ! ( V_183 -> V_51 & V_197 ) )
return - V_16 ;
V_1499 . V_1472 = true ;
}
if ( V_95 [ V_200 ] ) {
if ( ! ( V_183 -> V_51 & V_199 ) )
return - V_16 ;
V_1499 . V_434 = true ;
}
if ( V_95 [ V_202 ] ) {
if ( ! ( V_183 -> V_51 & V_201 ) )
return - V_16 ;
V_1499 . V_1473 = true ;
}
if ( V_95 [ V_204 ] )
return - V_16 ;
if ( V_95 [ V_206 ] ) {
if ( ! ( V_183 -> V_51 & V_205 ) )
return - V_16 ;
V_1499 . V_1474 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_183 -> V_51 & V_207 ) )
return - V_16 ;
V_1499 . V_1475 = true ;
}
if ( V_95 [ V_210 ] ) {
if ( ! ( V_183 -> V_51 & V_209 ) )
return - V_16 ;
V_1499 . V_1476 = true ;
}
if ( V_95 [ V_212 ] ) {
if ( ! ( V_183 -> V_51 & V_211 ) )
return - V_16 ;
V_1499 . V_1477 = true ;
}
if ( V_95 [ V_222 ] ) {
struct V_4 * V_215 ;
int V_213 = 0 ;
int V_134 , V_1441 , V_1506 , V_1448 ;
struct V_4 * V_1507 [ V_1508 ] ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_213 ++ ;
if ( V_213 > V_183 -> V_213 )
return - V_16 ;
V_1499 . V_1442 = F_335 ( V_213 ,
sizeof( V_1499 . V_1442 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1499 . V_1442 )
return - V_136 ;
V_1499 . V_213 = V_213 ;
V_153 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1509 ;
F_96 ( V_1507 , V_1510 , F_23 ( V_215 ) ,
F_24 ( V_215 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1507 [ V_1444 ] ||
! V_1507 [ V_1445 ] )
goto error;
V_1441 = F_24 ( V_1507 [ V_1445 ] ) ;
V_1506 = F_322 ( V_1441 , 8 ) ;
if ( F_24 ( V_1507 [ V_1444 ] ) != V_1506 )
goto error;
if ( V_1441 > V_183 -> V_220 ||
V_1441 < V_183 -> V_218 )
goto error;
if ( ! V_1507 [ V_1447 ] )
V_1448 = 0 ;
else
V_1448 = F_4 (
V_1507 [ V_1447 ] ) ;
if ( V_1448 > V_183 -> V_221 )
goto error;
V_1499 . V_1442 [ V_153 ] . V_1448 = V_1448 ;
V_1509 = F_336 ( V_1506 + V_1441 , V_135 ) ;
if ( ! V_1509 ) {
V_35 = - V_136 ;
goto error;
}
V_1499 . V_1442 [ V_153 ] . V_709 = V_1509 ;
memcpy ( V_1509 , F_23 ( V_1507 [ V_1444 ] ) ,
V_1506 ) ;
V_1509 += V_1506 ;
V_1499 . V_1442 [ V_153 ] . V_1446 = V_1509 ;
V_1499 . V_1442 [ V_153 ] . V_1443 = V_1441 ;
memcpy ( V_1509 ,
F_23 ( V_1507 [ V_1445 ] ) ,
V_1441 ) ;
V_153 ++ ;
}
}
if ( V_95 [ V_185 ] ) {
V_35 = F_326 (
V_7 , V_95 [ V_185 ] ,
& V_1499 ) ;
if ( V_35 )
goto error;
}
V_1500 = F_337 ( & V_1499 , sizeof( V_1499 ) , V_135 ) ;
if ( ! V_1500 ) {
V_35 = - V_136 ;
goto error;
}
F_334 ( V_7 ) ;
V_7 -> V_18 . V_1438 = V_1500 ;
V_1503:
if ( V_7 -> V_337 -> V_1503 &&
V_1502 != ! ! V_7 -> V_18 . V_1438 )
F_338 ( V_7 , V_7 -> V_18 . V_1438 ) ;
return 0 ;
error:
for ( V_153 = 0 ; V_153 < V_1499 . V_213 ; V_153 ++ )
F_41 ( V_1499 . V_1442 [ V_153 ] . V_709 ) ;
F_41 ( V_1499 . V_1442 ) ;
if ( V_1499 . V_182 && V_1499 . V_182 -> V_1495 )
F_331 ( V_1499 . V_182 -> V_1495 ) ;
F_41 ( V_1499 . V_182 ) ;
return V_35 ;
}
static int F_339 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1439 , * V_1440 , * V_1511 , * V_1512 ;
int V_153 , V_155 , V_1441 ;
struct V_1513 * V_224 ;
if ( ! V_7 -> V_225 -> V_227 )
return 0 ;
V_1512 = F_47 ( V_53 , V_229 ) ;
if ( ! V_1512 )
return - V_91 ;
for ( V_153 = 0 ; V_153 < V_7 -> V_225 -> V_227 ; V_153 ++ ) {
V_1511 = F_47 ( V_53 , V_153 + 1 ) ;
if ( ! V_1511 )
return - V_91 ;
V_224 = & V_7 -> V_225 -> V_1514 [ V_153 ] ;
if ( F_28 ( V_53 , V_1515 ,
V_224 -> V_1516 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1517 ,
V_224 -> V_1518 ) )
return - V_91 ;
V_1439 = F_47 ( V_53 ,
V_1519 ) ;
if ( ! V_1439 )
return - V_91 ;
for ( V_155 = 0 ; V_155 < V_224 -> V_213 ; V_155 ++ ) {
V_1440 = F_47 ( V_53 , V_155 + 1 ) ;
if ( ! V_1440 )
return - V_91 ;
V_1441 = V_224 -> V_1442 [ V_155 ] . V_1443 ;
if ( F_51 ( V_53 , V_1444 ,
F_322 ( V_1441 , 8 ) ,
V_224 -> V_1442 [ V_155 ] . V_709 ) ||
F_51 ( V_53 , V_1445 , V_1441 ,
V_224 -> V_1442 [ V_155 ] . V_1446 ) ||
F_28 ( V_53 , V_1447 ,
V_224 -> V_1442 [ V_155 ] . V_1448 ) )
return - V_91 ;
F_48 ( V_53 , V_1440 ) ;
}
F_48 ( V_53 , V_1439 ) ;
F_48 ( V_53 , V_1511 ) ;
}
F_48 ( V_53 , V_1512 ) ;
return 0 ;
}
static int F_340 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_31 * V_53 ;
void * V_275 ;
if ( ! V_7 -> V_18 . V_225 )
return - V_519 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1520 ) ;
if ( ! V_275 )
goto V_61;
if ( V_7 -> V_225 && F_339 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_341 ( struct V_6 * V_7 )
{
struct V_1521 * V_225 = V_7 -> V_225 ;
int V_153 , V_155 ;
struct V_1513 * V_224 ;
if ( ! V_225 )
return;
for ( V_153 = 0 ; V_153 < V_225 -> V_227 ; V_153 ++ ) {
V_224 = & V_225 -> V_1514 [ V_153 ] ;
for ( V_155 = 0 ; V_155 < V_224 -> V_213 ; V_155 ++ )
F_41 ( V_224 -> V_1442 [ V_155 ] . V_709 ) ;
F_41 ( V_224 -> V_1442 ) ;
}
F_41 ( V_225 -> V_1514 ) ;
F_41 ( V_225 ) ;
V_7 -> V_225 = NULL ;
}
static int F_342 ( struct V_6 * V_7 ,
struct V_4 * V_224 ,
struct V_1513 * V_1522 )
{
int V_35 , V_153 ;
const struct V_1523 * V_225 = V_7 -> V_18 . V_225 ;
struct V_4 * V_95 [ V_1524 ] , * V_215 ;
int V_134 , V_1441 , V_1506 , V_1448 , V_213 = 0 ;
struct V_4 * V_1507 [ V_1508 ] ;
V_35 = F_96 ( V_95 , V_1525 , F_23 ( V_224 ) ,
F_24 ( V_224 ) , V_1526 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1515 ] )
V_1522 -> V_1516 =
F_4 ( V_95 [ V_1515 ] ) ;
if ( V_1522 -> V_1516 > V_225 -> V_228 )
return - V_16 ;
if ( V_95 [ V_1517 ] )
V_1522 -> V_1518 =
F_4 ( V_95 [ V_1517 ] ) ;
if ( V_1522 -> V_1518 != V_1527 &&
V_1522 -> V_1518 != V_1528 )
return - V_16 ;
if ( ! V_95 [ V_1519 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_213 ++ ;
if ( V_213 > V_225 -> V_213 )
return - V_16 ;
V_1522 -> V_1442 = F_335 ( V_213 , sizeof( V_1522 -> V_1442 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1522 -> V_1442 )
return - V_136 ;
V_1522 -> V_213 = V_213 ;
V_153 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1509 ;
F_96 ( V_1507 , V_1510 , F_23 ( V_215 ) ,
F_24 ( V_215 ) , NULL ) ;
if ( ! V_1507 [ V_1444 ] ||
! V_1507 [ V_1445 ] )
return - V_16 ;
V_1441 = F_24 ( V_1507 [ V_1445 ] ) ;
V_1506 = F_322 ( V_1441 , 8 ) ;
if ( F_24 ( V_1507 [ V_1444 ] ) != V_1506 )
return - V_16 ;
if ( V_1441 > V_225 -> V_220 ||
V_1441 < V_225 -> V_218 )
return - V_16 ;
if ( ! V_1507 [ V_1447 ] )
V_1448 = 0 ;
else
V_1448 = F_4 ( V_1507 [ V_1447 ] ) ;
if ( V_1448 > V_225 -> V_221 )
return - V_16 ;
V_1522 -> V_1442 [ V_153 ] . V_1448 = V_1448 ;
V_1509 = F_336 ( V_1506 + V_1441 , V_135 ) ;
if ( ! V_1509 )
return - V_136 ;
V_1522 -> V_1442 [ V_153 ] . V_709 = V_1509 ;
memcpy ( V_1509 , F_23 ( V_1507 [ V_1444 ] ) ,
V_1506 ) ;
V_1509 += V_1506 ;
V_1522 -> V_1442 [ V_153 ] . V_1446 = V_1509 ;
V_1522 -> V_1442 [ V_153 ] . V_1443 = V_1441 ;
memcpy ( V_1509 , F_23 ( V_1507 [ V_1445 ] ) ,
V_1441 ) ;
V_153 ++ ;
}
return 0 ;
}
static int F_343 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
const struct V_1523 * V_225 = V_7 -> V_18 . V_225 ;
struct V_1521 V_1529 = {} ;
struct V_1521 * V_1530 ;
int V_35 , V_1531 , V_227 = 0 , V_153 , V_155 ;
struct V_4 * V_224 ;
struct V_1513 * V_1532 ;
if ( ! V_7 -> V_18 . V_225 || ! V_7 -> V_337 -> V_1533 )
return - V_519 ;
if ( ! V_30 -> V_5 [ V_229 ] ) {
F_341 ( V_7 ) ;
V_7 -> V_337 -> V_1533 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_227 ++ ;
if ( V_227 > V_225 -> V_227 )
return - V_16 ;
V_1529 . V_1514 = F_335 ( V_227 , sizeof( V_1529 . V_1514 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1529 . V_1514 )
return - V_136 ;
V_1529 . V_227 = V_227 ;
V_153 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_342 ( V_7 , V_224 ,
& V_1529 . V_1514 [ V_153 ] ) ;
if ( V_35 )
goto error;
V_153 ++ ;
}
V_35 = V_7 -> V_337 -> V_1533 ( & V_7 -> V_18 , & V_1529 ) ;
if ( V_35 )
goto error;
V_1530 = F_337 ( & V_1529 , sizeof( V_1529 ) , V_135 ) ;
if ( ! V_1530 ) {
V_35 = - V_136 ;
goto error;
}
F_341 ( V_7 ) ;
V_7 -> V_225 = V_1530 ;
return 0 ;
error:
for ( V_153 = 0 ; V_153 < V_1529 . V_227 ; V_153 ++ ) {
V_1532 = & V_1529 . V_1514 [ V_153 ] ;
for ( V_155 = 0 ; V_155 < V_1532 -> V_213 ; V_155 ++ )
F_41 ( V_1532 -> V_1442 [ V_155 ] . V_709 ) ;
F_41 ( V_1532 -> V_1442 ) ;
}
F_41 ( V_1529 . V_1514 ) ;
return V_35 ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_4 * V_95 [ V_1534 ] ;
struct V_1535 V_1536 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1537 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1538 ,
F_23 ( V_30 -> V_5 [ V_1537 ] ) ,
F_24 ( V_30 -> V_5 [ V_1537 ] ) ,
V_1539 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1540 ] ) != V_1541 )
return - V_1542 ;
if ( F_24 ( V_95 [ V_1543 ] ) != V_1544 )
return - V_1542 ;
if ( F_24 ( V_95 [ V_1545 ] ) != V_1546 )
return - V_1542 ;
memcpy ( V_1536 . V_1547 , F_23 ( V_95 [ V_1543 ] ) ,
V_1544 ) ;
memcpy ( V_1536 . V_1548 , F_23 ( V_95 [ V_1545 ] ) ,
V_1546 ) ;
memcpy ( V_1536 . V_1549 ,
F_23 ( V_95 [ V_1540 ] ) ,
V_1541 ) ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1166 ;
goto V_572;
}
if ( ! V_7 -> V_337 -> V_1550 ) {
V_35 = - V_519 ;
goto V_572;
}
V_35 = F_345 ( V_7 , V_518 , & V_1536 ) ;
V_572:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_346 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1551 )
return - V_523 ;
V_17 -> V_1551 = V_30 -> V_482 ;
return 0 ;
}
static int F_347 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_31 * V_53 ;
void * V_275 ;
const T_2 * V_646 ;
T_1 V_616 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_519 ;
if ( ! V_30 -> V_5 [ V_526 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_411 )
return - V_519 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1552 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_626;
}
V_646 = F_23 ( V_30 -> V_5 [ V_526 ] ) ;
V_35 = F_348 ( V_7 , V_518 , V_646 , & V_616 ) ;
if ( V_35 )
goto V_626;
if ( F_104 ( V_53 , V_1361 , V_616 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_626:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_349 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1553 * V_1554 , * V_1555 ;
int V_1556 ;
if ( ! ( V_7 -> V_18 . V_51 & V_415 ) )
return - V_519 ;
V_1555 = F_38 ( sizeof( * V_1555 ) , V_135 ) ;
if ( ! V_1555 )
return - V_136 ;
F_243 ( & V_7 -> V_1557 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1554 -> V_1558 == V_30 -> V_482 ) {
V_1556 = - V_677 ;
goto V_843;
}
}
V_1555 -> V_1558 = V_30 -> V_482 ;
F_350 ( & V_1555 -> V_609 , & V_7 -> V_1559 ) ;
F_245 ( & V_7 -> V_1557 ) ;
return 0 ;
V_843:
F_245 ( & V_7 -> V_1557 ) ;
F_41 ( V_1555 ) ;
return V_1556 ;
}
static int F_351 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_337 -> V_417 )
return - V_519 ;
if ( V_17 -> V_141 != V_599 )
return - V_519 ;
if ( V_17 -> V_1560 )
return 0 ;
if ( F_352 ( V_7 -> V_1561 ) )
return - V_1562 ;
V_35 = F_353 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1560 = true ;
V_7 -> V_1563 ++ ;
return 0 ;
}
static int F_354 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
if ( V_17 -> V_141 != V_599 )
return - V_519 ;
if ( ! V_7 -> V_337 -> V_1564 )
return - V_519 ;
F_355 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_356 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_275 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_482 , V_30 -> V_483 , 0 ,
V_1565 ) ;
if ( ! V_275 )
goto V_61;
if ( F_28 ( V_53 , V_1566 ,
V_1567 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_267 ( V_53 ) ;
return - V_91 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1568 V_1569 ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_1570 )
return - V_519 ;
if ( ! V_30 -> V_5 [ V_1571 ] ||
! F_22 ( V_30 -> V_5 [ V_652 ] ) )
return - V_16 ;
memset ( & V_1569 , 0 , sizeof( V_1569 ) ) ;
V_1569 . V_1572 = F_78 ( V_30 -> V_5 [ V_1571 ] ) ;
V_1569 . V_1076 = F_23 ( V_30 -> V_5 [ V_652 ] ) ;
V_1569 . V_1077 = F_24 ( V_30 -> V_5 [ V_652 ] ) ;
return F_358 ( V_7 , V_518 , & V_1569 ) ;
}
static int F_359 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
enum V_1573 V_1259 = V_1574 ;
T_3 V_1357 ;
int V_474 ;
if ( ! V_7 -> V_337 -> V_423 )
return - V_519 ;
if ( F_59 ( ! V_7 -> V_337 -> V_425 ) )
return - V_16 ;
if ( V_7 -> V_1575 )
return - V_523 ;
if ( V_30 -> V_5 [ V_1576 ] )
V_1259 = F_78 ( V_30 -> V_5 [ V_1576 ] ) ;
if ( V_1259 >= V_1577 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1578 ] )
return - V_16 ;
V_1357 =
F_78 ( V_30 -> V_5 [ V_1578 ] ) ;
if ( V_1357 > V_1579 )
return - V_1542 ;
V_474 = F_360 ( V_7 , V_17 , V_1259 , V_1357 ) ;
if ( ! V_474 )
V_7 -> V_1575 = V_30 -> V_482 ;
return V_474 ;
}
static int F_361 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_425 )
return - V_519 ;
if ( V_7 -> V_1575 ) {
V_7 -> V_1575 = 0 ;
F_362 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_363 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_153 , V_35 ;
V_22 V_1580 , V_1313 ;
if ( ! V_7 -> V_18 . V_467 )
return - V_519 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1310 ] ||
! V_30 -> V_5 [ V_1312 ] )
return - V_16 ;
V_1580 = F_4 ( V_30 -> V_5 [ V_1310 ] ) ;
V_1313 = F_4 ( V_30 -> V_5 [ V_1312 ] ) ;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_463 ; V_153 ++ ) {
const struct V_1581 * V_1582 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1582 = & V_7 -> V_18 . V_467 [ V_153 ] ;
if ( V_1582 -> V_30 . V_1311 != V_1580 || V_1582 -> V_30 . V_1313 != V_1313 )
continue;
if ( V_1582 -> V_51 & ( V_1583 |
V_1584 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1582 -> V_51 & V_1584 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1582 -> V_51 & V_1585 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_534 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1560 )
return - V_534 ;
}
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_466 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_466 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_466 ] ) ;
}
V_7 -> V_1322 = V_30 ;
V_35 = V_7 -> V_18 . V_467 [ V_153 ] . F_364 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1322 = NULL ;
return V_35 ;
}
return - V_519 ;
}
struct V_31 * F_365 ( struct V_18 * V_18 ,
enum V_272 V_52 ,
enum V_1308 V_45 ,
int V_1307 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1322 ) )
return NULL ;
return F_266 ( V_7 , V_1307 ,
V_7 -> V_1322 -> V_482 ,
V_7 -> V_1322 -> V_483 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_366 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_275 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
if ( F_59 ( ! V_7 -> V_1322 ) ) {
F_267 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_275 ) ;
return F_76 ( V_32 , V_7 -> V_1322 ) ;
}
static int F_367 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_481 [ 0 ] ;
struct V_1586 * V_1587 = NULL ;
struct V_25 * V_518 = V_30 -> V_481 [ 1 ] ;
T_2 * V_46 , V_47 , V_1588 , V_1589 , V_1590 ;
int V_474 ;
if ( ! V_7 -> V_337 -> V_430 )
return - V_519 ;
if ( V_30 -> V_5 [ V_1591 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1591 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1591 ] ) ;
if ( V_47 % 2 || V_47 < V_1592 ||
V_47 > V_1593 )
return - V_16 ;
V_1587 = F_38 ( sizeof( struct V_1586 ) , V_135 ) ;
if ( ! V_1587 )
return - V_136 ;
V_1588 = ( V_47 - V_1592 ) >> 1 ;
if ( V_1588 ) {
V_1589 = V_1588 *
sizeof( struct V_1594 ) ;
memcpy ( V_1587 -> V_1595 , V_46 , V_1589 ) ;
V_1587 -> V_1588 = V_1588 ;
for ( V_1590 = 0 ; V_1590 < V_1588 ; V_1590 ++ ) {
if ( V_1587 -> V_1595 [ V_1590 ] . V_1596 > 7 ) {
F_41 ( V_1587 ) ;
return - V_16 ;
}
}
V_46 += V_1589 ;
}
memcpy ( V_1587 -> V_1596 , V_46 , V_1592 ) ;
}
F_112 ( V_518 -> V_28 ) ;
V_474 = F_42 ( V_518 -> V_28 ) ;
if ( ! V_474 )
V_474 = F_368 ( V_7 , V_518 , V_1587 ) ;
F_114 ( V_518 -> V_28 ) ;
F_41 ( V_1587 ) ;
return V_474 ;
}
static int F_369 ( const struct V_1597 * V_337 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_518 ;
bool V_1598 = V_337 -> V_1599 & V_1600 ;
if ( V_1598 )
F_14 () ;
if ( V_337 -> V_1599 & V_1601 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1598 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_481 [ 0 ] = V_7 ;
} else if ( V_337 -> V_1599 & V_1602 ||
V_337 -> V_1599 & V_1603 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1598 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_518 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_337 -> V_1599 & V_1602 ) {
if ( ! V_518 ) {
if ( V_1598 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_481 [ 1 ] = V_518 ;
} else {
V_30 -> V_481 [ 1 ] = V_17 ;
}
if ( V_518 ) {
if ( V_337 -> V_1599 & V_1604 &&
! F_91 ( V_518 ) ) {
if ( V_1598 )
F_20 () ;
return - V_534 ;
}
F_223 ( V_518 ) ;
} else if ( V_337 -> V_1599 & V_1604 ) {
if ( ! V_17 -> V_1560 ) {
if ( V_1598 )
F_20 () ;
return - V_534 ;
}
}
V_30 -> V_481 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_370 ( const struct V_1597 * V_337 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_481 [ 1 ] ) {
if ( V_337 -> V_1599 & V_1603 ) {
struct V_1 * V_17 = V_30 -> V_481 [ 1 ] ;
if ( V_17 -> V_19 )
F_168 ( V_17 -> V_19 ) ;
} else {
F_168 ( V_30 -> V_481 [ 1 ] ) ;
}
}
if ( V_337 -> V_1599 & V_1600 )
F_20 () ;
}
void F_371 ( struct V_6 * V_7 ,
enum V_272 V_52 )
{
struct V_31 * V_53 ;
struct V_273 V_274 = {} ;
F_59 ( V_52 != V_287 &&
V_52 != V_1605 ) ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_274 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1606 , V_135 ) ;
}
static int F_372 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1117 * V_1275 = V_7 -> V_1121 ;
struct V_4 * V_1607 ;
int V_153 ;
if ( F_59 ( ! V_1275 ) )
return 0 ;
V_1607 = F_47 ( V_53 , V_1125 ) ;
if ( ! V_1607 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_1275 -> V_1119 ; V_153 ++ ) {
if ( F_51 ( V_53 , V_153 , V_1275 -> V_1126 [ V_153 ] . V_565 , V_1275 -> V_1126 [ V_153 ] . V_567 ) )
goto V_61;
}
F_48 ( V_53 , V_1607 ) ;
V_1607 = F_47 ( V_53 , V_1124 ) ;
if ( ! V_1607 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_1275 -> V_352 ; V_153 ++ ) {
if ( F_28 ( V_53 , V_153 , V_1275 -> V_353 [ V_153 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1607 ) ;
if ( V_1275 -> V_1076 &&
F_51 ( V_53 , V_652 , V_1275 -> V_1077 , V_1275 -> V_1076 ) )
goto V_61;
if ( V_1275 -> V_51 &&
F_28 ( V_53 , V_1130 , V_1275 -> V_51 ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_373 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_275 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_372 ( V_53 , V_7 ) ;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
static int
F_374 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_275 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_473 ;
}
void F_222 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_373 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1608 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1609 , V_135 ) ;
}
struct V_31 * F_375 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1610 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_373 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1610 ? V_1611 :
V_1192 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_376 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1609 , V_135 ) ;
}
void F_377 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_374 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1612 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1609 , V_135 ) ;
}
void F_226 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_374 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1609 , V_135 ) ;
}
void F_378 ( struct V_1613 * V_1118 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1614 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_56 ( V_53 , V_1615 , V_1118 -> V_1616 ) )
goto V_61;
if ( V_1118 -> V_1092 [ 0 ] == '0' && V_1118 -> V_1092 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1617 ,
V_1618 ) )
goto V_61;
} else if ( V_1118 -> V_1092 [ 0 ] == '9' && V_1118 -> V_1092 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1617 ,
V_1619 ) )
goto V_61;
} else if ( ( V_1118 -> V_1092 [ 0 ] == '9' && V_1118 -> V_1092 [ 1 ] == '8' ) ||
V_1118 -> V_1620 ) {
if ( F_56 ( V_53 , V_1617 ,
V_1621 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1617 ,
V_1622 ) ||
F_60 ( V_53 , V_987 ,
V_1118 -> V_1092 ) )
goto V_61;
}
if ( V_1118 -> V_14 != V_1623 &&
F_28 ( V_53 , V_26 , V_1118 -> V_14 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_208 () ;
F_379 ( & V_38 , V_53 , 0 ,
V_1624 , V_1625 ) ;
F_211 () ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static void F_380 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1405 , T_10 V_47 ,
enum V_272 V_52 , T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1402 , V_47 , V_1405 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_381 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1405 ,
T_10 V_47 , T_12 V_1309 )
{
F_380 ( V_7 , V_19 , V_1405 , V_47 ,
V_673 , V_1309 ) ;
}
void F_382 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1405 ,
T_10 V_47 , T_12 V_1309 )
{
F_380 ( V_7 , V_19 , V_1405 , V_47 ,
V_1627 , V_1309 ) ;
}
void F_383 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1405 ,
T_10 V_47 , T_12 V_1309 )
{
F_380 ( V_7 , V_19 , V_1405 , V_47 ,
V_1628 , V_1309 ) ;
}
void F_384 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1405 ,
T_10 V_47 , T_12 V_1309 )
{
F_380 ( V_7 , V_19 , V_1405 , V_47 ,
V_1629 , V_1309 ) ;
}
void F_385 ( struct V_25 * V_518 , const T_2 * V_1405 ,
T_10 V_47 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1630 * V_1631 = ( void * ) V_1405 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_386 ( V_1631 -> V_1632 ) )
V_52 = V_1633 ;
else
V_52 = V_1634 ;
F_387 ( V_518 , V_1405 , V_47 ) ;
F_380 ( V_7 , V_518 , V_1405 , V_47 , V_52 , V_1625 ) ;
}
static void F_388 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_646 , T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1635 ) ||
F_51 ( V_53 , V_526 , V_562 , V_646 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_389 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_646 ,
T_12 V_1309 )
{
F_388 ( V_7 , V_19 , V_673 ,
V_646 , V_1309 ) ;
}
void F_390 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_646 ,
T_12 V_1309 )
{
F_388 ( V_7 , V_19 , V_1627 ,
V_646 , V_1309 ) ;
}
void F_391 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_525 ,
const T_2 * V_1636 , T_10 V_1637 ,
const T_2 * V_1638 , T_10 V_1639 ,
T_3 V_1640 , T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_433 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_525 && F_51 ( V_53 , V_526 , V_562 , V_525 ) ) ||
F_55 ( V_53 , V_1351 , V_1640 ) ||
( V_1636 &&
F_51 ( V_53 , V_1641 , V_1637 , V_1636 ) ) ||
( V_1638 &&
F_51 ( V_53 , V_1642 , V_1639 , V_1638 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_392 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_525 ,
const T_2 * V_1636 , T_10 V_1637 ,
const T_2 * V_1638 , T_10 V_1639 , T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1643 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_525 ) ||
( V_1636 &&
F_51 ( V_53 , V_1641 , V_1637 , V_1636 ) ) ||
( V_1638 &&
F_51 ( V_53 , V_1642 , V_1639 , V_1638 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_393 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1334 ,
const T_2 * V_1076 , T_10 V_1077 , bool V_1644 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_435 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1644 && V_1334 &&
F_55 ( V_53 , V_1291 , V_1334 ) ) ||
( V_1644 &&
F_29 ( V_53 , V_1645 ) ) ||
( V_1076 && F_51 ( V_53 , V_652 , V_1077 , V_1076 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_394 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_525 ,
T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1646 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_525 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_395 ( struct V_25 * V_518 , const T_2 * V_646 ,
const T_2 * V_1076 , T_2 V_1077 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_396 ( V_518 , V_646 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1647 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_646 ) ||
( V_1077 && V_1076 &&
F_51 ( V_53 , V_652 , V_1077 , V_1076 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_397 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_646 ,
enum V_1648 V_1649 , int V_1650 ,
const T_2 * V_1651 , T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1652 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_646 && F_51 ( V_53 , V_526 , V_562 , V_646 ) ) ||
F_28 ( V_53 , V_127 , V_1649 ) ||
( V_1650 != - 1 &&
F_56 ( V_53 , V_123 , V_1650 ) ) ||
( V_1651 && F_51 ( V_53 , V_122 , 6 , V_1651 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_398 ( struct V_18 * V_18 ,
struct V_54 * V_1653 ,
struct V_54 * V_1654 )
{
struct V_31 * V_53 ;
void * V_275 ;
struct V_4 * V_279 ;
V_53 = F_74 ( V_573 , V_1625 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1655 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_399 ( V_18 ) ) )
goto V_61;
V_279 = F_47 ( V_53 , V_1656 ) ;
if ( ! V_279 )
goto V_61;
if ( F_27 ( V_53 , V_1653 , false ) )
goto V_61;
F_48 ( V_53 , V_279 ) ;
V_279 = F_47 ( V_53 , V_1657 ) ;
if ( ! V_279 )
goto V_61;
if ( F_27 ( V_53 , V_1654 , false ) )
goto V_61;
F_48 ( V_53 , V_279 ) ;
F_66 ( V_53 , V_275 ) ;
F_208 () ;
F_379 ( & V_38 , V_53 , 0 ,
V_1624 , V_1625 ) ;
F_211 () ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static void F_400 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_616 ,
struct V_54 * V_55 ,
unsigned int V_1357 , T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_501 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_506 ,
V_509 ) ||
F_104 ( V_53 , V_1361 , V_616 ) )
goto V_61;
if ( V_52 == V_1360 &&
F_28 ( V_53 , V_1358 , V_1357 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_401 ( struct V_1 * V_17 , T_1 V_616 ,
struct V_54 * V_55 ,
unsigned int V_1357 , T_12 V_1309 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_402 ( V_17 , V_616 , V_55 , V_1357 ) ;
F_400 ( V_1360 ,
V_7 , V_17 , V_616 , V_55 ,
V_1357 , V_1309 ) ;
}
void F_403 ( struct V_1 * V_17 , T_1 V_616 ,
struct V_54 * V_55 ,
T_12 V_1309 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_404 ( V_17 , V_616 , V_55 ) ;
F_400 ( V_1658 ,
V_7 , V_17 , V_616 , V_55 , 0 , V_1309 ) ;
}
void F_405 ( struct V_25 * V_518 , const T_2 * V_618 ,
struct V_744 * V_745 , T_12 V_1309 )
{
struct V_18 * V_18 = V_518 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_406 ( V_518 , V_618 , V_745 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
if ( F_160 ( V_53 , 0 , 0 , 0 ,
V_7 , V_518 , V_618 , V_745 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
}
void F_407 ( struct V_25 * V_518 , const T_2 * V_618 , T_12 V_1309 )
{
struct V_18 * V_18 = V_518 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_408 ( V_518 , V_618 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1659 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_618 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_409 ( struct V_25 * V_518 , const T_2 * V_618 ,
enum V_1660 V_1334 ,
T_12 V_1309 )
{
struct V_18 * V_18 = V_518 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_1661 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1662 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_618 ) ||
F_28 ( V_53 , V_1663 , V_1334 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static bool F_410 ( struct V_25 * V_518 , T_2 V_52 ,
const T_2 * V_646 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
V_22 V_1558 = F_411 ( V_17 -> V_1551 ) ;
if ( ! V_1558 )
return false ;
V_53 = F_74 ( 100 , V_1309 ) ;
if ( ! V_53 )
return true ;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_646 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_412 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1558 ) ;
return true ;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_413 ( struct V_25 * V_518 ,
const T_2 * V_646 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
bool V_474 ;
F_414 ( V_518 , V_646 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_415 ( false ) ;
return false ;
}
V_474 = F_410 ( V_518 , V_1664 ,
V_646 , V_1309 ) ;
F_415 ( V_474 ) ;
return V_474 ;
}
bool F_416 ( struct V_25 * V_518 ,
const T_2 * V_646 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
bool V_474 ;
F_417 ( V_518 , V_646 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_415 ( false ) ;
return false ;
}
V_474 = F_410 ( V_518 ,
V_1665 ,
V_646 , V_1309 ) ;
F_415 ( V_474 ) ;
return V_474 ;
}
int F_418 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1558 ,
int V_1666 , int V_1667 ,
const T_2 * V_1405 , T_10 V_47 , V_22 V_51 , T_12 V_1309 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1409 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_501 , V_1666 ) ||
( V_1667 &&
F_28 ( V_53 , V_1668 , V_1667 ) ) ||
F_51 ( V_53 , V_1402 , V_47 , V_1405 ) ||
( V_51 &&
F_28 ( V_53 , V_1669 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_412 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1558 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_419 ( struct V_1 * V_17 , T_1 V_616 ,
const T_2 * V_1405 , T_10 V_47 , bool V_1670 , T_12 V_1309 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_275 ;
F_420 ( V_17 , V_616 , V_1670 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1671 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1402 , V_47 , V_1405 ) ||
F_104 ( V_53 , V_1361 , V_616 ) ||
( V_1670 && F_29 ( V_53 , V_1672 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_421 ( struct V_25 * V_518 ,
enum V_1673 V_1674 ,
T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_920 ;
void * V_275 ;
F_422 ( V_518 , V_1674 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1675 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_518 -> V_20 ) )
goto V_61;
V_920 = F_47 ( V_53 , V_1428 ) ;
if ( ! V_920 )
goto V_61;
if ( F_28 ( V_53 , V_1676 ,
V_1674 ) )
goto V_61;
F_48 ( V_53 , V_920 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static void F_423 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_525 ,
const T_2 * V_1549 , T_12 V_1309 )
{
struct V_31 * V_53 ;
struct V_4 * V_1677 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1678 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_525 ) )
goto V_61;
V_1677 = F_47 ( V_53 , V_1537 ) ;
if ( ! V_1677 )
goto V_61;
if ( F_51 ( V_53 , V_1540 ,
V_1541 , V_1549 ) )
goto V_61;
F_48 ( V_53 , V_1677 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_424 ( struct V_25 * V_518 , const T_2 * V_525 ,
const T_2 * V_1549 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_425 ( V_518 , V_525 ) ;
F_423 ( V_7 , V_518 , V_525 , V_1549 , V_1309 ) ;
}
static void
F_426 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1679 ,
const T_2 * V_525 , bool V_1680 , T_12 V_1309 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1681 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1682 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1683 , V_1679 ) ||
F_51 ( V_53 , V_1684 , V_562 , V_525 ) ||
( V_1680 &&
F_29 ( V_53 , V_1685 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_427 ( struct V_25 * V_518 , int V_1679 ,
const T_2 * V_525 , bool V_1680 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_428 ( V_518 , V_1679 , V_525 , V_1680 ) ;
F_426 ( V_7 , V_518 , V_1679 , V_525 , V_1680 , V_1309 ) ;
}
static void F_429 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_498 * V_499 ,
T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1686 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_499 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_430 ( struct V_25 * V_518 ,
struct V_498 * V_499 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_431 ( V_518 , V_499 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_146 &&
V_17 -> V_141 != V_145 ) )
return;
V_17 -> V_499 = * V_499 ;
V_17 -> V_524 = * V_499 ;
F_429 ( V_7 , V_518 , V_499 , V_135 ) ;
}
void F_432 ( struct V_25 * V_518 ,
const T_2 * V_1349 , V_22 V_1687 ,
V_22 V_235 , V_22 V_1420 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_920 ;
void * V_275 ;
V_53 = F_74 ( V_1661 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1675 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_1349 ) )
goto V_61;
V_920 = F_47 ( V_53 , V_1428 ) ;
if ( ! V_920 )
goto V_61;
if ( F_28 ( V_53 , V_1433 , V_1687 ) )
goto V_61;
if ( F_28 ( V_53 , V_1432 , V_235 ) )
goto V_61;
if ( F_28 ( V_53 , V_1434 , V_1420 ) )
goto V_61;
F_48 ( V_53 , V_920 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void
F_433 ( struct V_6 * V_7 ,
const struct V_498 * V_499 ,
enum V_1688 V_1689 ,
struct V_25 * V_19 , T_12 V_1309 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1690 ) ;
if ( ! V_275 ) {
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
if ( F_28 ( V_53 , V_1691 , V_1689 ) )
goto V_61;
if ( F_101 ( V_53 , V_499 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_434 ( struct V_25 * V_518 ,
const T_2 * V_1349 , V_22 V_1687 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_920 ;
void * V_275 ;
F_435 ( V_518 , V_1349 , V_1687 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1675 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_1349 ) )
goto V_61;
V_920 = F_47 ( V_53 , V_1428 ) ;
if ( ! V_920 )
goto V_61;
if ( F_28 ( V_53 , V_1692 , V_1687 ) )
goto V_61;
F_48 ( V_53 , V_920 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_436 ( struct V_25 * V_518 , const T_2 * V_646 ,
T_1 V_616 , bool V_1693 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_437 ( V_518 , V_646 , V_616 , V_1693 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1552 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_646 ) ||
F_104 ( V_53 , V_1361 , V_616 ) ||
( V_1693 && F_29 ( V_53 , V_1672 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_438 ( struct V_18 * V_18 ,
const T_2 * V_1694 , T_10 V_47 ,
int V_1666 , int V_1667 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
struct V_1553 * V_1554 ;
F_439 ( V_18 , V_1694 , V_47 , V_1666 , V_1667 ) ;
F_243 ( & V_7 -> V_1557 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1625 ) ;
if ( ! V_53 ) {
F_245 ( & V_7 -> V_1557 ) ;
return;
}
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1409 ) ;
if ( ! V_275 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1666 &&
F_28 ( V_53 , V_501 , V_1666 ) ) ||
( V_1667 &&
F_28 ( V_53 , V_1668 , V_1667 ) ) ||
F_51 ( V_53 , V_1402 , V_47 , V_1694 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_412 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1554 -> V_1558 ) ;
}
F_245 ( & V_7 -> V_1557 ) ;
return;
V_61:
F_245 ( & V_7 -> V_1557 ) ;
if ( V_275 )
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_440 ( struct V_1 * V_17 ,
struct V_1695 * V_1696 ,
T_12 V_1309 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
int V_1469 = 200 ;
F_441 ( V_17 -> V_18 , V_17 , V_1696 ) ;
if ( V_1696 )
V_1469 += V_1696 -> V_1697 ;
V_53 = F_74 ( V_1469 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1698 ) ;
if ( ! V_275 )
goto V_626;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_626;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_626;
if ( V_1696 ) {
struct V_4 * V_1699 ;
V_1699 = F_47 ( V_53 , V_1471 ) ;
if ( ! V_1699 )
goto V_626;
if ( V_1696 -> V_434 &&
F_29 ( V_53 , V_200 ) )
goto V_626;
if ( V_1696 -> V_1473 &&
F_29 ( V_53 , V_202 ) )
goto V_626;
if ( V_1696 -> V_1474 &&
F_29 ( V_53 , V_206 ) )
goto V_626;
if ( V_1696 -> V_1475 &&
F_29 ( V_53 , V_208 ) )
goto V_626;
if ( V_1696 -> V_1476 &&
F_29 ( V_53 , V_210 ) )
goto V_626;
if ( V_1696 -> V_1477 &&
F_29 ( V_53 , V_212 ) )
goto V_626;
if ( V_1696 -> V_1700 >= 0 &&
F_28 ( V_53 , V_222 ,
V_1696 -> V_1700 ) )
goto V_626;
if ( V_1696 -> V_1701 &&
F_29 ( V_53 , V_1702 ) )
goto V_626;
if ( V_1696 -> V_1703 &&
F_29 ( V_53 , V_1704 ) )
goto V_626;
if ( V_1696 -> V_1705 &&
F_29 ( V_53 ,
V_1706 ) )
goto V_626;
if ( V_1696 -> V_1707 ) {
V_22 V_1708 = V_1709 ;
V_22 V_1710 = V_1711 ;
if ( ! V_1696 -> V_1712 ) {
V_1708 =
V_1713 ;
V_1710 =
V_1714 ;
}
if ( V_1696 -> V_1715 &&
F_28 ( V_53 , V_1710 , V_1696 -> V_1715 ) )
goto V_626;
if ( F_51 ( V_53 , V_1708 , V_1696 -> V_1697 ,
V_1696 -> V_1707 ) )
goto V_626;
}
F_48 ( V_53 , V_1699 ) ;
}
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_626:
F_75 ( V_53 ) ;
}
void F_442 ( struct V_25 * V_518 , const T_2 * V_1349 ,
enum V_1354 V_1716 ,
T_3 V_1290 , T_12 V_1309 )
{
struct V_1 * V_17 = V_518 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_443 ( V_17 -> V_18 , V_518 , V_1349 , V_1716 ,
V_1290 ) ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1717 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_518 -> V_20 ) ||
F_56 ( V_53 , V_1356 , V_1716 ) ||
F_51 ( V_53 , V_526 , V_562 , V_1349 ) ||
( V_1290 > 0 &&
F_55 ( V_53 , V_1291 , V_1290 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_1309 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static int F_444 ( struct V_1718 * V_1719 ,
unsigned long V_274 ,
void * V_1720 )
{
struct V_1721 * V_1722 = V_1720 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1553 * V_1554 , * V_24 ;
if ( V_274 != V_1723 )
return V_1724 ;
F_208 () ;
F_445 (rdev, &cfg80211_rdev_list, list) {
bool V_1725 = false ;
F_445 (wdev, &rdev->wdev_list, list) {
F_446 ( V_17 , V_1722 -> V_49 ) ;
if ( V_17 -> V_603 == V_1722 -> V_49 )
V_1725 = true ;
}
F_243 ( & V_7 -> V_1557 ) ;
F_447 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1554 -> V_1558 == V_1722 -> V_49 ) {
F_448 ( & V_1554 -> V_609 ) ;
F_41 ( V_1554 ) ;
break;
}
}
F_245 ( & V_7 -> V_1557 ) ;
if ( V_1725 ) {
struct V_1726 * V_1727 ;
V_1727 = F_38 ( sizeof( * V_1727 ) , V_1625 ) ;
if ( V_1727 ) {
V_1727 -> V_1558 = V_1722 -> V_49 ;
F_449 ( & V_7 -> V_1728 ) ;
F_350 ( & V_1727 -> V_609 , & V_7 -> V_1729 ) ;
F_450 ( & V_7 -> V_1728 ) ;
F_451 ( & V_7 -> V_1730 ) ;
}
}
}
F_211 () ;
return V_1731 ;
}
void F_452 ( struct V_25 * V_19 ,
struct V_1732 * V_1733 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_453 ( V_18 , V_19 , V_1733 ) ;
if ( ! V_1733 -> V_1734 )
return;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1735 ) ;
if ( ! V_275 )
goto V_572;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_526 , V_562 , V_1733 -> V_1734 ) )
goto V_572;
if ( V_1733 -> V_1189 &&
F_51 ( V_53 , V_652 , V_1733 -> V_1736 , V_1733 -> V_1189 ) )
goto V_572;
if ( V_1733 -> V_1737 &&
F_51 ( V_53 , V_1738 , V_1733 -> V_1739 ,
V_1733 -> V_1737 ) )
goto V_572;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1626 , V_135 ) ;
return;
V_572:
F_75 ( V_53 ) ;
}
void F_454 ( struct V_1 * V_17 , T_12 V_1309 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_275 ;
V_22 V_1558 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1575 )
return;
V_1558 = V_7 -> V_1575 ;
V_7 -> V_1575 = 0 ;
V_53 = F_74 ( V_573 , V_1309 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1740 ) ;
if ( ! V_275 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_412 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1558 ) ;
return;
V_61:
if ( V_275 )
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_455 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_573 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1741 ) ;
if ( ! V_275 )
goto V_572;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_572;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1626 , V_135 ) ;
return;
V_572:
F_75 ( V_53 ) ;
}
int F_456 ( void )
{
int V_35 ;
V_35 = F_457 ( & V_38 , V_1742 ,
V_1743 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_458 ( & V_1744 ) ;
if ( V_35 )
goto V_1745;
return 0 ;
V_1745:
F_459 ( & V_38 ) ;
return V_35 ;
}
void F_460 ( void )
{
F_461 ( & V_1744 ) ;
F_459 ( & V_38 ) ;
}
