static struct V_1 * F_1 ( struct V_2 * V_2 ,
const char * V_3 ,
enum V_4 type ,
T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_3 ( V_9 , V_3 , & V_10 , type , V_7 ) ;
if ( V_13 )
return F_4 ( V_13 ) ;
if ( type == V_14 && V_5 ) {
V_12 = F_5 ( V_10 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
}
return V_10 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
F_7 ( F_5 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
enum V_4 type , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
V_19 = F_10 ( V_12 , type ) ;
if ( V_19 )
return V_19 ;
if ( type == V_20 &&
V_7 && V_7 -> V_21 == 0 )
F_11 ( V_12 -> V_15 . V_22 . V_23 , NULL ) ;
else if ( type == V_24 &&
V_7 && V_7 -> V_21 >= 0 )
V_12 -> V_15 . V_25 . V_21 = V_7 -> V_21 ;
if ( V_12 -> V_26 . type == V_14 && V_5 ) {
struct V_8 * V_9 = V_12 -> V_9 ;
if ( F_12 ( V_12 ) ) {
T_1 V_27 = V_28 |
V_29 ;
if ( ( * V_5 & V_27 ) != ( V_12 -> V_15 . V_16 & V_27 ) )
return - V_30 ;
F_13 ( V_12 , - 1 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
F_13 ( V_12 , 1 ) ;
F_14 ( V_9 ) ;
} else {
V_12 -> V_15 . V_16 = * V_5 ;
}
}
return 0 ;
}
static int F_15 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_19 ;
F_16 ( & V_12 -> V_9 -> V_31 ) ;
V_19 = F_17 ( V_12 , NULL , 0 , 0 ) ;
F_18 ( & V_12 -> V_9 -> V_31 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_19 ( V_10 , true ) ;
}
static void F_20 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
F_21 ( F_5 ( V_10 ) ) ;
}
static int F_22 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_2 V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_32 = V_32 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 ,
struct V_36 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 = NULL ;
const struct V_38 * V_39 = NULL ;
struct V_40 * V_41 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
switch ( V_7 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
if ( F_24 ( V_9 -> V_47 ) )
return - V_48 ;
break;
case V_49 :
case V_50 :
case V_51 :
break;
default:
V_39 = F_25 ( V_9 , V_7 -> V_43 , V_12 -> V_26 . type ) ;
break;
}
V_41 = F_26 ( V_7 -> V_43 , V_33 , V_7 -> V_52 ,
V_7 -> V_41 , V_7 -> V_53 , V_7 -> V_54 ,
V_39 ) ;
if ( F_24 ( V_41 ) )
return F_27 ( V_41 ) ;
if ( V_34 )
V_41 -> V_55 . V_5 |= V_56 ;
F_16 ( & V_9 -> V_57 ) ;
if ( V_35 ) {
if ( F_28 ( & V_12 -> V_26 ) )
V_23 = F_29 ( V_12 , V_35 ) ;
else
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 || ! F_31 ( V_23 , V_58 ) ) {
F_32 ( V_41 ) ;
V_13 = - V_59 ;
goto V_60;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_61 != V_62 )
V_41 -> V_55 . V_5 |= V_63 ;
break;
case V_64 :
case V_20 :
if ( V_41 -> V_23 && F_31 ( V_41 -> V_23 , V_65 ) )
V_41 -> V_55 . V_5 |= V_63 ;
break;
case V_66 :
break;
case V_67 :
#ifdef F_33
if ( V_12 -> V_15 . V_68 . V_69 != V_70 )
V_41 -> V_55 . V_5 |= V_63 ;
break;
#endif
case V_71 :
case V_14 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
F_34 ( 1 ) ;
break;
}
if ( V_23 )
V_23 -> V_77 = V_39 ;
V_13 = F_35 ( V_41 , V_12 , V_23 ) ;
V_60:
F_18 ( & V_9 -> V_57 ) ;
return V_13 ;
}
static int F_36 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
struct V_40 * V_41 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_57 ) ;
F_16 ( & V_9 -> V_78 ) ;
if ( V_35 ) {
V_19 = - V_59 ;
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_60;
if ( V_34 )
V_41 = F_37 ( V_9 , V_23 -> V_79 [ V_33 ] ) ;
else
V_41 = F_37 ( V_9 , V_23 -> V_80 [ V_33 ] ) ;
} else
V_41 = F_37 ( V_9 , V_12 -> V_81 [ V_33 ] ) ;
if ( ! V_41 ) {
V_19 = - V_59 ;
goto V_60;
}
F_38 ( V_41 , true ) ;
V_19 = 0 ;
V_60:
F_18 ( & V_9 -> V_78 ) ;
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_39 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 ,
void * V_82 ,
void (* F_40)( void * V_82 ,
struct V_36 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_37 * V_23 = NULL ;
T_3 V_54 [ 6 ] = { 0 } ;
struct V_36 V_7 ;
struct V_40 * V_41 = NULL ;
T_4 V_83 ;
T_1 V_84 ;
T_2 V_85 ;
int V_13 = - V_59 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
if ( V_35 ) {
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_86;
if ( V_34 && V_33 < V_87 )
V_41 = F_42 ( V_23 -> V_79 [ V_33 ] ) ;
else if ( ! V_34 &&
V_33 < V_87 + V_88 )
V_41 = F_42 ( V_23 -> V_80 [ V_33 ] ) ;
} else
V_41 = F_42 ( V_12 -> V_81 [ V_33 ] ) ;
if ( ! V_41 )
goto V_86;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_43 = V_41 -> V_55 . V_43 ;
switch ( V_41 -> V_55 . V_43 ) {
case V_45 :
V_84 = V_41 -> V_15 . V_89 . V_90 . V_84 ;
V_85 = V_41 -> V_15 . V_89 . V_90 . V_85 ;
if ( V_41 -> V_5 & V_91 )
F_43 ( V_12 -> V_9 ,
V_41 -> V_55 . V_92 ,
& V_84 , & V_85 ) ;
V_54 [ 0 ] = V_85 & 0xff ;
V_54 [ 1 ] = ( V_85 >> 8 ) & 0xff ;
V_54 [ 2 ] = V_84 & 0xff ;
V_54 [ 3 ] = ( V_84 >> 8 ) & 0xff ;
V_54 [ 4 ] = ( V_84 >> 16 ) & 0xff ;
V_54 [ 5 ] = ( V_84 >> 24 ) & 0xff ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
case V_49 :
V_83 = F_44 ( & V_41 -> V_15 . V_93 . V_94 ) ;
V_54 [ 0 ] = V_83 ;
V_54 [ 1 ] = V_83 >> 8 ;
V_54 [ 2 ] = V_83 >> 16 ;
V_54 [ 3 ] = V_83 >> 24 ;
V_54 [ 4 ] = V_83 >> 32 ;
V_54 [ 5 ] = V_83 >> 40 ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
case V_50 :
V_83 = F_44 ( & V_41 -> V_15 . V_95 . V_94 ) ;
V_54 [ 0 ] = V_83 ;
V_54 [ 1 ] = V_83 >> 8 ;
V_54 [ 2 ] = V_83 >> 16 ;
V_54 [ 3 ] = V_83 >> 24 ;
V_54 [ 4 ] = V_83 >> 32 ;
V_54 [ 5 ] = V_83 >> 40 ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
}
V_7 . V_41 = V_41 -> V_55 . V_41 ;
V_7 . V_52 = V_41 -> V_55 . V_96 ;
F_40 ( V_82 , & V_7 ) ;
V_13 = 0 ;
V_86:
F_45 () ;
return V_13 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_33 , bool V_97 ,
bool V_98 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_33 , V_97 , V_98 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_33 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_49 ( V_12 , V_33 ) ;
return 0 ;
}
void F_50 ( struct V_37 * V_23 ,
const struct V_99 * V_100 ,
struct V_101 * V_102 )
{
V_102 -> V_5 = 0 ;
if ( V_100 -> V_5 & V_103 ) {
V_102 -> V_5 |= V_104 ;
V_102 -> V_105 = V_100 -> V_106 ;
} else if ( V_100 -> V_5 & V_107 ) {
V_102 -> V_5 |= V_108 ;
V_102 -> V_105 = F_51 ( V_100 ) ;
V_102 -> V_109 = F_52 ( V_100 ) ;
} else {
struct V_110 * V_111 ;
int V_112 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_113 ;
V_111 = V_23 -> V_9 -> V_114 . V_2 -> V_115 [
F_54 ( V_23 -> V_12 ) ] ;
V_113 = V_111 -> V_116 [ V_100 -> V_106 ] . V_117 ;
V_102 -> V_118 = F_55 ( V_113 , 1 << V_112 ) ;
}
if ( V_100 -> V_5 & V_119 )
V_102 -> V_5 |= V_120 ;
if ( V_100 -> V_5 & V_121 )
V_102 -> V_5 |= V_122 ;
if ( V_100 -> V_5 & V_123 )
V_102 -> V_5 |= V_124 ;
if ( V_100 -> V_5 & V_125 )
V_102 -> V_5 |= V_126 ;
}
void F_56 ( struct V_37 * V_23 , struct V_101 * V_102 )
{
V_102 -> V_5 = 0 ;
if ( V_23 -> V_127 & V_128 ) {
V_102 -> V_5 |= V_104 ;
V_102 -> V_105 = V_23 -> V_129 ;
} else if ( V_23 -> V_127 & V_130 ) {
V_102 -> V_5 |= V_108 ;
V_102 -> V_109 = V_23 -> V_131 ;
V_102 -> V_105 = V_23 -> V_129 ;
} else {
struct V_110 * V_111 ;
int V_112 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_113 ;
V_111 = V_23 -> V_9 -> V_114 . V_2 -> V_115 [
F_54 ( V_23 -> V_12 ) ] ;
V_113 = V_111 -> V_116 [ V_23 -> V_129 ] . V_117 ;
V_102 -> V_118 = F_55 ( V_113 , 1 << V_112 ) ;
}
if ( V_23 -> V_127 & V_132 )
V_102 -> V_5 |= V_120 ;
if ( V_23 -> V_127 & V_133 )
V_102 -> V_5 |= V_126 ;
if ( V_23 -> V_134 & V_135 )
V_102 -> V_5 |= V_122 ;
if ( V_23 -> V_134 & V_136 )
V_102 -> V_5 |= V_137 ;
if ( V_23 -> V_134 & V_138 )
V_102 -> V_5 |= V_124 ;
}
static void F_57 ( struct V_37 * V_23 , struct V_139 * V_140 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_141 * V_142 = NULL ;
struct V_143 V_144 ;
T_4 V_145 = 0 ;
T_1 V_146 = 0 ;
int V_147 , V_148 ;
if ( F_31 ( V_23 , V_149 ) )
V_142 = V_9 -> V_150 ;
V_140 -> V_151 = V_12 -> V_9 -> V_152 ;
V_140 -> V_153 = V_154 |
V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 |
V_161 |
V_162 |
V_163 |
V_164 |
V_165 |
V_166 |
V_167 ;
F_58 ( & V_144 ) ;
V_140 -> V_168 = V_144 . V_169 - V_23 -> V_170 ;
V_140 -> V_171 = F_59 ( V_172 - V_23 -> V_173 ) ;
V_140 -> V_174 = 0 ;
for ( V_148 = 0 ; V_148 < V_175 ; V_148 ++ ) {
V_140 -> V_174 += V_23 -> V_174 [ V_148 ] ;
V_145 += V_23 -> V_176 [ V_148 ] ;
}
V_140 -> V_176 = V_145 ;
V_140 -> V_177 = V_23 -> V_177 ;
V_140 -> V_178 = V_23 -> V_178 ;
V_140 -> V_179 = V_23 -> V_180 ;
V_140 -> V_181 = V_23 -> V_182 ;
V_140 -> V_183 = V_23 -> V_184 ;
V_140 -> V_185 = V_23 -> V_185 ;
if ( ( V_23 -> V_9 -> V_114 . V_5 & V_186 ) ||
( V_23 -> V_9 -> V_114 . V_5 & V_187 ) ) {
V_140 -> V_153 |= V_188 | V_189 ;
if ( ! V_9 -> V_190 -> V_191 ||
F_60 ( V_9 , V_12 , & V_23 -> V_23 , & V_140 -> signal ) )
V_140 -> signal = ( V_192 ) V_23 -> V_193 ;
V_140 -> V_194 = ( V_192 ) - F_61 ( & V_23 -> V_195 ) ;
}
if ( V_23 -> V_196 ) {
V_140 -> V_153 |= V_197 |
V_198 ;
V_140 -> V_196 = V_23 -> V_196 ;
for ( V_147 = 0 ; V_147 < F_62 ( V_140 -> V_199 ) ; V_147 ++ ) {
V_140 -> V_199 [ V_147 ] = V_23 -> V_200 [ V_147 ] ;
V_140 -> V_201 [ V_147 ] =
( V_192 ) - F_61 ( & V_23 -> V_201 [ V_147 ] ) ;
}
}
F_50 ( V_23 , & V_23 -> V_202 , & V_140 -> V_203 ) ;
F_56 ( V_23 , & V_140 -> V_204 ) ;
if ( F_28 ( & V_12 -> V_26 ) ) {
#ifdef F_33
V_140 -> V_153 |= V_205 |
V_206 |
V_207 |
V_208 |
V_209 |
V_210 ;
V_140 -> V_211 = V_23 -> V_211 ;
V_140 -> V_212 = V_23 -> V_212 ;
V_140 -> V_213 = V_23 -> V_213 ;
if ( F_31 ( V_23 , V_214 ) ) {
V_140 -> V_153 |= V_215 ;
V_140 -> V_216 = V_23 -> V_216 ;
}
V_140 -> V_217 = V_23 -> V_217 ;
V_140 -> V_218 = V_23 -> V_218 ;
V_140 -> V_219 = V_23 -> V_219 ;
#endif
}
V_140 -> V_220 . V_5 = 0 ;
if ( V_12 -> V_26 . V_221 . V_222 )
V_140 -> V_220 . V_5 |= V_223 ;
if ( V_12 -> V_26 . V_221 . V_224 )
V_140 -> V_220 . V_5 |= V_225 ;
if ( V_12 -> V_26 . V_221 . V_226 )
V_140 -> V_220 . V_5 |= V_227 ;
V_140 -> V_220 . V_228 = V_12 -> V_9 -> V_114 . V_55 . V_229 ;
V_140 -> V_220 . V_230 = V_12 -> V_26 . V_221 . V_231 ;
V_140 -> V_232 . V_233 = 0 ;
V_140 -> V_232 . V_27 = F_63 ( V_234 ) |
F_63 ( V_235 ) |
F_63 ( V_236 ) |
F_63 ( V_237 ) |
F_63 ( V_238 ) |
F_63 ( V_239 ) |
F_63 ( V_240 ) ;
if ( F_31 ( V_23 , V_241 ) )
V_140 -> V_232 . V_233 |= F_63 ( V_234 ) ;
if ( F_31 ( V_23 , V_242 ) )
V_140 -> V_232 . V_233 |= F_63 ( V_235 ) ;
if ( F_31 ( V_23 , V_243 ) )
V_140 -> V_232 . V_233 |= F_63 ( V_236 ) ;
if ( F_31 ( V_23 , V_65 ) )
V_140 -> V_232 . V_233 |= F_63 ( V_237 ) ;
if ( F_31 ( V_23 , V_244 ) )
V_140 -> V_232 . V_233 |= F_63 ( V_238 ) ;
if ( F_31 ( V_23 , V_58 ) )
V_140 -> V_232 . V_233 |= F_63 ( V_239 ) ;
if ( F_31 ( V_23 , V_245 ) )
V_140 -> V_232 . V_233 |= F_63 ( V_240 ) ;
if ( V_142 && V_142 -> V_190 -> V_246 )
V_146 = V_142 -> V_190 -> V_246 ( V_23 -> V_247 ) ;
else
V_146 = F_64 ( V_9 , & V_23 -> V_23 ) ;
if ( V_146 != 0 ) {
V_140 -> V_153 |= V_248 ;
V_140 -> V_249 = V_146 ;
}
}
static int F_65 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_250 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_251 = 0 ;
if ( V_250 == V_252 )
V_251 += V_253 ;
V_251 += F_66 ( V_12 , V_250 ) ;
if ( V_251 == 0 )
return - V_254 ;
return V_251 ;
}
static void F_67 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_255 * V_256 ,
T_4 * V_257 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_258 * V_259 ;
struct V_260 * V_261 ;
struct V_37 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_139 V_140 ;
struct V_262 V_263 ;
int V_147 , V_264 ;
#define F_68 7
memset ( V_257 , 0 , sizeof( T_4 ) * V_253 ) ;
#define F_69 ( V_23 ) \
do { \
data[i++] += sta->rx_packets; \
data[i++] += sta->rx_bytes; \
data[i++] += sta->wep_weak_iv_count; \
data[i++] += sta->num_duplicates; \
data[i++] += sta->rx_fragments; \
data[i++] += sta->rx_dropped; \
\
data[i++] += sinfo.tx_packets; \
data[i++] += sinfo.tx_bytes; \
data[i++] += sta->tx_fragments; \
data[i++] += sta->tx_filtered_count; \
data[i++] += sta->tx_retry_failed; \
data[i++] += sta->tx_retry_count; \
data[i++] += sta->beacon_loss_count; \
} while (0)
F_16 ( & V_9 -> V_57 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_30 ( V_12 , V_12 -> V_15 . V_25 . V_265 ) ;
if ( ! ( V_23 && ! F_70 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_266;
V_140 . V_153 = 0 ;
F_57 ( V_23 , & V_140 ) ;
V_147 = 0 ;
F_69 ( V_23 ) ;
V_257 [ V_147 ++ ] = V_23 -> V_267 ;
if ( V_140 . V_153 & V_161 )
V_257 [ V_147 ] = 100000 *
F_71 ( & V_140 . V_203 ) ;
V_147 ++ ;
if ( V_140 . V_153 & V_162 )
V_257 [ V_147 ] = 100000 *
F_71 ( & V_140 . V_204 ) ;
V_147 ++ ;
if ( V_140 . V_153 & V_189 )
V_257 [ V_147 ] = ( T_3 ) V_140 . V_194 ;
V_147 ++ ;
} else {
F_72 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_140 . V_153 = 0 ;
F_57 ( V_23 , & V_140 ) ;
V_147 = 0 ;
F_69 ( V_23 ) ;
}
}
V_266:
V_147 = V_253 - F_68 ;
V_263 . V_153 = 0 ;
F_41 () ;
V_259 = F_42 ( V_12 -> V_26 . V_259 ) ;
if ( V_259 )
V_261 = V_259 -> V_268 . V_269 ;
else
V_261 = NULL ;
F_45 () ;
if ( V_261 ) {
V_264 = 0 ;
do {
V_263 . V_153 = 0 ;
if ( F_73 ( V_9 , V_264 , & V_263 ) != 0 ) {
V_263 . V_153 = 0 ;
break;
}
V_264 ++ ;
} while ( V_261 != V_263 . V_261 );
}
if ( V_263 . V_153 )
V_257 [ V_147 ++ ] = V_263 . V_261 -> V_270 ;
else
V_257 [ V_147 ++ ] = 0 ;
if ( V_263 . V_153 & V_271 )
V_257 [ V_147 ++ ] = ( T_3 ) V_263 . V_272 ;
else
V_257 [ V_147 ++ ] = - 1LL ;
if ( V_263 . V_153 & V_273 )
V_257 [ V_147 ++ ] = V_263 . V_274 ;
else
V_257 [ V_147 ++ ] = - 1LL ;
if ( V_263 . V_153 & V_275 )
V_257 [ V_147 ++ ] = V_263 . V_276 ;
else
V_257 [ V_147 ++ ] = - 1LL ;
if ( V_263 . V_153 & V_277 )
V_257 [ V_147 ++ ] = V_263 . V_278 ;
else
V_257 [ V_147 ++ ] = - 1LL ;
if ( V_263 . V_153 & V_279 )
V_257 [ V_147 ++ ] = V_263 . V_280 ;
else
V_257 [ V_147 ++ ] = - 1LL ;
if ( V_263 . V_153 & V_281 )
V_257 [ V_147 ++ ] = V_263 . V_282 ;
else
V_257 [ V_147 ++ ] = - 1LL ;
F_18 ( & V_9 -> V_57 ) ;
if ( F_70 ( V_147 != V_253 ) )
return;
F_74 ( V_12 , V_256 , & ( V_257 [ V_253 ] ) ) ;
}
static void F_75 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_250 , T_3 * V_257 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_283 = 0 ;
if ( V_250 == V_252 ) {
V_283 = sizeof( V_284 ) ;
memcpy ( V_257 , V_284 , V_283 ) ;
}
F_76 ( V_12 , V_250 , & ( V_257 [ V_283 ] ) ) ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_106 , T_3 * V_285 , struct V_139 * V_140 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_59 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_78 ( V_12 , V_106 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_285 , V_23 -> V_23 . V_286 , V_287 ) ;
F_57 ( V_23 , V_140 ) ;
}
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_79 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_106 , struct V_262 * V_263 )
{
struct V_8 * V_9 = F_80 ( V_18 -> V_288 ) ;
return F_73 ( V_9 , V_106 , V_263 ) ;
}
static int F_81 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_285 , struct V_139 * V_140 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_59 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_30 ( V_12 , V_285 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_57 ( V_23 , V_140 ) ;
}
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_82 ( struct V_2 * V_2 ,
struct V_289 * V_290 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_83 ( & V_9 -> V_291 , V_290 ) )
return 0 ;
F_16 ( & V_9 -> V_292 ) ;
F_16 ( & V_9 -> V_293 ) ;
if ( V_9 -> V_294 ) {
V_12 = F_84 (
V_9 -> V_295 ,
F_85 ( & V_9 -> V_293 ) ) ;
if ( V_12 ) {
F_86 ( V_12 ) ;
V_19 = F_87 ( V_12 , V_290 ,
V_296 ) ;
}
} else if ( V_9 -> V_297 == V_9 -> V_298 ) {
V_9 -> V_299 = * V_290 ;
F_88 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_291 = * V_290 ;
F_18 ( & V_9 -> V_293 ) ;
F_18 ( & V_9 -> V_292 ) ;
return V_19 ;
}
static int F_89 ( struct V_11 * V_12 ,
const T_3 * V_300 , T_5 V_301 )
{
struct V_302 * V_303 , * V_304 ;
if ( ! V_300 || ! V_301 )
return 1 ;
V_304 = F_90 ( V_12 -> V_15 . V_305 . V_302 , V_12 ) ;
V_303 = F_91 ( sizeof( struct V_302 ) + V_301 , V_306 ) ;
if ( ! V_303 )
return - V_307 ;
V_303 -> V_308 = V_301 ;
memcpy ( V_303 -> V_257 , V_300 , V_301 ) ;
F_92 ( V_12 -> V_15 . V_305 . V_302 , V_303 ) ;
if ( V_304 )
F_93 ( V_304 , V_309 ) ;
return 0 ;
}
static int F_94 ( struct V_11 * V_12 ,
struct V_310 * V_7 )
{
struct V_311 * V_303 , * V_304 ;
int V_312 , V_313 ;
int V_314 , V_13 ;
T_1 V_315 = V_316 ;
V_304 = F_90 ( V_12 -> V_15 . V_305 . V_317 , V_12 ) ;
if ( ! V_7 -> V_318 && ! V_304 )
return - V_48 ;
if ( V_7 -> V_318 )
V_312 = V_7 -> V_319 ;
else
V_312 = V_304 -> V_319 ;
if ( V_7 -> V_320 || ! V_304 )
V_313 = V_7 -> V_321 ;
else
V_313 = V_304 -> V_321 ;
V_314 = sizeof( * V_303 ) + V_312 + V_313 ;
V_303 = F_91 ( V_314 , V_306 ) ;
if ( ! V_303 )
return - V_307 ;
V_303 -> V_318 = ( ( T_3 * ) V_303 ) + sizeof( * V_303 ) ;
V_303 -> V_320 = V_303 -> V_318 + V_312 ;
V_303 -> V_319 = V_312 ;
V_303 -> V_321 = V_313 ;
if ( V_7 -> V_318 )
memcpy ( V_303 -> V_318 , V_7 -> V_318 , V_312 ) ;
else
memcpy ( V_303 -> V_318 , V_304 -> V_318 , V_312 ) ;
if ( V_7 -> V_320 )
memcpy ( V_303 -> V_320 , V_7 -> V_320 , V_313 ) ;
else
if ( V_304 )
memcpy ( V_303 -> V_320 , V_304 -> V_320 , V_313 ) ;
V_13 = F_89 ( V_12 , V_7 -> V_302 ,
V_7 -> V_322 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_315 |= V_323 ;
F_92 ( V_12 -> V_15 . V_305 . V_317 , V_303 ) ;
if ( V_304 )
F_93 ( V_304 , V_309 ) ;
return V_315 ;
}
static int F_95 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_324 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_311 * V_304 ;
struct V_11 * V_22 ;
T_1 V_315 = V_325 |
V_326 |
V_316 |
V_327 |
V_328 ;
int V_13 ;
V_304 = F_90 ( V_12 -> V_15 . V_305 . V_317 , V_12 ) ;
if ( V_304 )
return - V_329 ;
V_12 -> V_330 = V_331 ;
V_12 -> V_332 = V_12 -> V_9 -> V_333 ;
F_16 ( & V_9 -> V_292 ) ;
V_13 = F_87 ( V_12 , & V_7 -> V_290 ,
V_334 ) ;
if ( ! V_13 )
F_96 ( V_12 , false ) ;
F_18 ( & V_9 -> V_292 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_335 = V_7 -> V_336 . V_337 ;
V_12 -> V_338 = V_7 -> V_336 . V_338 ;
V_12 -> V_339 = F_97 ( V_12 -> V_9 ,
& V_7 -> V_336 ,
V_12 -> V_26 . type ) ;
F_72 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_335 =
V_7 -> V_336 . V_337 ;
V_22 -> V_338 =
V_7 -> V_336 . V_338 ;
V_22 -> V_339 =
F_97 ( V_12 -> V_9 ,
& V_7 -> V_336 ,
V_22 -> V_26 . type ) ;
}
V_12 -> V_26 . V_221 . V_231 = V_7 -> V_230 ;
V_12 -> V_26 . V_221 . V_228 = V_7 -> V_228 ;
V_12 -> V_26 . V_221 . V_340 = true ;
V_12 -> V_26 . V_221 . V_341 = V_7 -> V_341 ;
if ( V_7 -> V_341 )
memcpy ( V_12 -> V_26 . V_221 . V_342 , V_7 -> V_342 ,
V_7 -> V_341 ) ;
V_12 -> V_26 . V_221 . V_343 =
( V_7 -> V_343 != V_344 ) ;
memset ( & V_12 -> V_26 . V_221 . V_345 , 0 ,
sizeof( V_12 -> V_26 . V_221 . V_345 ) ) ;
V_12 -> V_26 . V_221 . V_345 . V_346 =
V_7 -> V_347 & V_348 ;
if ( V_7 -> V_349 )
V_12 -> V_26 . V_221 . V_345 . V_346 |=
V_350 ;
V_13 = F_94 ( V_12 , & V_7 -> V_317 ) ;
if ( V_13 < 0 ) {
F_86 ( V_12 ) ;
return V_13 ;
}
V_315 |= V_13 ;
V_13 = F_98 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_304 = F_90 ( V_12 -> V_15 . V_305 . V_317 , V_12 ) ;
if ( V_304 )
F_93 ( V_304 , V_309 ) ;
F_11 ( V_12 -> V_15 . V_305 . V_317 , NULL ) ;
F_86 ( V_12 ) ;
return V_13 ;
}
F_99 ( V_9 , V_12 ) ;
F_100 ( V_12 , V_315 ) ;
F_101 ( V_18 ) ;
F_72 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_101 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_310 * V_7 )
{
struct V_11 * V_12 ;
struct V_311 * V_304 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_103 ( V_12 ) ;
if ( V_12 -> V_26 . V_351 )
return - V_30 ;
V_304 = F_90 ( V_12 -> V_15 . V_305 . V_317 , V_12 ) ;
if ( ! V_304 )
return - V_59 ;
V_13 = F_94 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_100 ( V_12 , V_13 ) ;
return 0 ;
}
bool F_104 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_105 ( & V_9 -> V_292 ) ;
F_41 () ;
F_106 (sdata, &local->interfaces, list) {
if ( ! F_12 ( V_12 ) )
continue;
if ( ! V_12 -> V_26 . V_351 )
continue;
if ( ! V_12 -> V_352 )
continue;
F_45 () ;
return true ;
}
F_45 () ;
return false ;
}
static int F_107 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_311 * V_353 ;
struct V_302 * V_354 ;
struct V_289 V_290 ;
F_103 ( V_12 ) ;
V_353 = F_90 ( V_12 -> V_15 . V_305 . V_317 , V_12 ) ;
if ( ! V_353 )
return - V_59 ;
V_354 = F_90 ( V_12 -> V_15 . V_305 . V_302 , V_12 ) ;
F_16 ( & V_9 -> V_292 ) ;
V_12 -> V_26 . V_351 = false ;
if ( ! F_104 ( V_9 ) )
F_108 ( & V_9 -> V_114 ,
V_355 ,
V_356 ) ;
F_18 ( & V_9 -> V_292 ) ;
F_109 ( V_12 -> V_15 . V_305 . V_357 ) ;
V_12 -> V_15 . V_305 . V_357 = NULL ;
F_72 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_110 ( V_22 -> V_18 ) ;
F_110 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_305 . V_317 , NULL ) ;
F_11 ( V_12 -> V_15 . V_305 . V_302 , NULL ) ;
F_93 ( V_353 , V_309 ) ;
if ( V_354 )
F_93 ( V_354 , V_309 ) ;
V_12 -> V_15 . V_305 . V_358 = V_331 ;
F_111 ( V_12 , true ) ;
F_112 ( V_12 , true ) ;
V_12 -> V_26 . V_221 . V_340 = false ;
V_12 -> V_26 . V_221 . V_341 = 0 ;
F_113 ( V_359 , & V_12 -> V_360 ) ;
F_100 ( V_12 , V_326 ) ;
if ( V_12 -> V_10 . V_361 ) {
V_290 = V_12 -> V_26 . V_221 . V_290 ;
F_114 ( & V_12 -> V_362 ) ;
F_115 ( V_12 -> V_18 , & V_290 ,
V_363 ,
V_306 ) ;
}
F_116 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_364 -= F_117 ( & V_12 -> V_15 . V_305 . V_365 . V_366 ) ;
F_118 ( & V_12 -> V_15 . V_305 . V_365 . V_366 ) ;
F_16 ( & V_9 -> V_292 ) ;
F_96 ( V_12 , true ) ;
F_86 ( V_12 ) ;
F_18 ( & V_9 -> V_292 ) ;
return 0 ;
}
static void F_119 ( struct V_37 * V_23 )
{
struct V_367 * V_368 ;
struct V_369 * V_370 ;
V_370 = F_120 ( sizeof( * V_368 ) ) ;
if ( ! V_370 )
return;
V_368 = (struct V_367 * ) F_121 ( V_370 , sizeof( * V_368 ) ) ;
F_122 ( V_368 -> V_371 ) ;
memcpy ( V_368 -> V_372 , V_23 -> V_23 . V_286 , V_287 ) ;
V_368 -> V_308 = F_123 ( 6 ) ;
V_368 -> V_373 = 0 ;
V_368 -> V_374 = 0x01 ;
V_368 -> V_375 = 0xaf ;
V_368 -> V_376 [ 0 ] = 0x81 ;
V_368 -> V_376 [ 1 ] = 1 ;
V_368 -> V_376 [ 2 ] = 0 ;
V_370 -> V_18 = V_23 -> V_12 -> V_18 ;
V_370 -> V_377 = F_124 ( V_370 , V_23 -> V_12 -> V_18 ) ;
memset ( V_370 -> V_378 , 0 , sizeof( V_370 -> V_378 ) ) ;
F_125 ( V_370 ) ;
}
static int F_126 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
T_1 V_27 , T_1 V_233 )
{
int V_19 ;
if ( V_27 & F_63 ( V_238 ) &&
V_233 & F_63 ( V_238 ) &&
! F_31 ( V_23 , V_244 ) ) {
V_19 = F_127 ( V_23 , V_379 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_63 ( V_239 ) &&
V_233 & F_63 ( V_239 ) &&
! F_31 ( V_23 , V_58 ) ) {
V_19 = F_127 ( V_23 , V_380 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_63 ( V_234 ) ) {
if ( V_233 & F_63 ( V_234 ) )
V_19 = F_127 ( V_23 , V_381 ) ;
else if ( F_31 ( V_23 , V_241 ) )
V_19 = F_127 ( V_23 , V_380 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_63 ( V_239 ) &&
! ( V_233 & F_63 ( V_239 ) ) &&
F_31 ( V_23 , V_58 ) ) {
V_19 = F_127 ( V_23 , V_379 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_63 ( V_238 ) &&
! ( V_233 & F_63 ( V_238 ) ) &&
F_31 ( V_23 , V_244 ) ) {
V_19 = F_127 ( V_23 , V_382 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_128 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
struct V_383 * V_7 )
{
int V_19 = 0 ;
struct V_110 * V_111 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_384 V_385 = F_54 ( V_12 ) ;
T_1 V_27 , V_233 ;
V_111 = V_9 -> V_114 . V_2 -> V_115 [ V_385 ] ;
V_27 = V_7 -> V_386 ;
V_233 = V_7 -> V_387 ;
if ( F_28 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_63 ( V_238 ) )
V_27 |= F_63 ( V_239 ) ;
if ( V_233 & F_63 ( V_238 ) )
V_233 |= F_63 ( V_239 ) ;
} else if ( F_31 ( V_23 , V_245 ) ) {
if ( V_233 & F_63 ( V_234 ) ) {
V_233 |= F_63 ( V_238 ) |
F_63 ( V_239 ) ;
V_27 |= F_63 ( V_238 ) |
F_63 ( V_239 ) ;
}
}
V_19 = F_126 ( V_9 , V_23 , V_27 , V_233 ) ;
if ( V_19 )
return V_19 ;
if ( V_27 & F_63 ( V_235 ) ) {
if ( V_233 & F_63 ( V_235 ) )
F_129 ( V_23 , V_242 ) ;
else
F_130 ( V_23 , V_242 ) ;
}
if ( V_27 & F_63 ( V_236 ) ) {
if ( V_233 & F_63 ( V_236 ) ) {
F_129 ( V_23 , V_243 ) ;
V_23 -> V_23 . V_388 = true ;
} else {
F_130 ( V_23 , V_243 ) ;
V_23 -> V_23 . V_388 = false ;
}
}
if ( V_27 & F_63 ( V_237 ) ) {
if ( V_233 & F_63 ( V_237 ) )
F_129 ( V_23 , V_65 ) ;
else
F_130 ( V_23 , V_65 ) ;
}
if ( V_27 & F_63 ( V_240 ) ) {
if ( V_233 & F_63 ( V_240 ) )
F_129 ( V_23 , V_245 ) ;
else
F_130 ( V_23 , V_245 ) ;
}
if ( V_7 -> V_389 & V_390 ) {
V_23 -> V_23 . V_391 = V_7 -> V_391 ;
V_23 -> V_23 . V_392 = V_7 -> V_392 ;
}
if ( V_7 -> V_393 )
V_23 -> V_23 . V_393 = V_7 -> V_393 ;
if ( V_7 -> V_394 >= 0 )
V_23 -> V_394 = V_7 -> V_394 ;
if ( V_7 -> V_395 ) {
F_131 ( & V_12 -> V_26 . V_221 . V_290 ,
V_111 , V_7 -> V_395 ,
V_7 -> V_396 ,
& V_23 -> V_23 . V_397 [ V_385 ] ) ;
}
if ( V_7 -> V_398 )
F_132 ( V_12 , V_111 ,
V_7 -> V_398 , V_23 ) ;
if ( V_7 -> V_399 )
F_133 ( V_12 , V_111 ,
V_7 -> V_399 , V_23 ) ;
if ( V_7 -> V_400 ) {
F_134 ( V_12 , V_23 ,
V_7 -> V_401 ,
V_385 , false ) ;
}
if ( F_28 ( & V_12 -> V_26 ) ) {
#ifdef F_33
T_1 V_315 = 0 ;
if ( V_7 -> V_389 & V_402 ) {
switch ( V_7 -> V_213 ) {
case V_403 :
if ( V_23 -> V_213 != V_403 )
V_315 = F_135 (
V_12 ) ;
V_23 -> V_213 = V_7 -> V_213 ;
F_136 ( V_23 ) ;
V_315 |= F_137 ( V_23 ,
V_12 -> V_15 . V_68 . V_404 . V_405 ) ;
break;
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
if ( V_23 -> V_213 == V_403 )
V_315 = F_138 (
V_12 ) ;
V_23 -> V_213 = V_7 -> V_213 ;
F_136 ( V_23 ) ;
V_315 |= F_137 ( V_23 ,
V_412 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_413 ) {
case V_414 :
break;
case V_415 :
V_315 |= F_139 ( V_23 ) ;
break;
case V_416 :
V_315 |= F_140 ( V_23 ) ;
break;
}
if ( V_7 -> V_217 )
V_315 |=
F_137 ( V_23 ,
V_7 -> V_217 ) ;
F_141 ( V_12 , V_315 ) ;
#endif
}
return 0 ;
}
static int F_142 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_285 ,
struct V_383 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_417 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_64 )
return - V_48 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_143 ( V_285 , V_12 -> V_26 . V_286 ) )
return - V_48 ;
if ( F_144 ( V_285 ) )
return - V_48 ;
V_23 = F_145 ( V_12 , V_285 , V_306 ) ;
if ( ! V_23 )
return - V_307 ;
if ( ! ( V_7 -> V_387 & F_63 ( V_240 ) ) ) {
F_146 ( V_23 , V_379 ) ;
F_146 ( V_23 , V_380 ) ;
} else {
V_23 -> V_23 . V_418 = true ;
}
V_13 = F_128 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_147 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_31 ( V_23 , V_245 ) )
F_148 ( V_23 ) ;
V_417 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_64 ;
V_13 = F_149 ( V_23 ) ;
if ( V_13 ) {
F_45 () ;
return V_13 ;
}
if ( V_417 )
F_119 ( V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_150 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_285 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_285 )
return F_151 ( V_12 , V_285 ) ;
F_152 ( V_12 ) ;
return 0 ;
}
static int F_153 ( struct V_2 * V_2 ,
struct V_17 * V_18 , const T_3 * V_285 ,
struct V_383 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_419 ;
enum V_420 V_421 ;
int V_13 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_30 ( V_12 , V_285 ) ;
if ( ! V_23 ) {
V_13 = - V_59 ;
goto V_422;
}
switch ( V_12 -> V_26 . type ) {
case V_67 :
if ( V_12 -> V_15 . V_68 . V_423 )
V_421 = V_424 ;
else
V_421 = V_425 ;
break;
case V_66 :
V_421 = V_426 ;
break;
case V_24 :
if ( ! F_31 ( V_23 , V_245 ) ) {
V_421 = V_427 ;
break;
}
if ( F_31 ( V_23 , V_241 ) )
V_421 = V_428 ;
else
V_421 = V_429 ;
break;
case V_64 :
case V_20 :
V_421 = V_430 ;
break;
default:
V_13 = - V_254 ;
goto V_422;
}
V_13 = F_154 ( V_2 , V_7 , V_421 ) ;
if ( V_13 )
goto V_422;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_431 = false ;
bool V_432 = false ;
V_419 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_288 -> V_21 ) {
if ( V_419 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_422;
}
F_92 ( V_419 -> V_15 . V_22 . V_23 , V_23 ) ;
V_432 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_11 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_431 = true ;
}
V_23 -> V_12 = V_419 ;
if ( V_23 -> V_267 == V_381 &&
V_431 != V_432 ) {
if ( V_432 )
F_155 ( & V_23 -> V_12 -> V_433 -> V_434 ) ;
else
F_156 ( & V_23 -> V_12 -> V_433 -> V_434 ) ;
}
F_119 ( V_23 ) ;
}
V_13 = F_128 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_422;
if ( F_31 ( V_23 , V_245 ) &&
F_31 ( V_23 , V_241 ) )
F_148 ( V_23 ) ;
F_18 ( & V_9 -> V_57 ) ;
if ( ( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_435 != V_23 -> V_12 -> V_433 -> V_436 &&
F_31 ( V_23 , V_241 ) &&
F_157 ( V_23 ) != 1 ) {
F_158 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_286 ) ;
F_159 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_433 -> V_436 ,
V_23 -> V_23 . V_286 ,
V_23 -> V_12 -> V_26 . V_221 . V_265 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_386 & F_63 ( V_234 ) ) {
F_160 ( V_9 , - 1 ) ;
F_161 ( V_12 ) ;
}
return 0 ;
V_422:
F_18 ( & V_9 -> V_57 ) ;
return V_13 ;
}
static int F_162 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_437 , const T_3 * V_438 )
{
struct V_11 * V_12 ;
struct V_439 * V_440 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_438 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_440 = F_163 ( V_12 , V_437 ) ;
if ( F_24 ( V_440 ) ) {
F_45 () ;
return F_27 ( V_440 ) ;
}
F_164 ( V_440 , V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_437 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_437 )
return F_166 ( V_12 , V_437 ) ;
F_167 ( V_12 ) ;
return 0 ;
}
static int F_168 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_437 , const T_3 * V_438 )
{
struct V_11 * V_12 ;
struct V_439 * V_440 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_438 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_440 = F_169 ( V_12 , V_437 ) ;
if ( ! V_440 ) {
F_45 () ;
return - V_59 ;
}
F_164 ( V_440 , V_23 ) ;
F_45 () ;
return 0 ;
}
static void F_170 ( struct V_439 * V_440 , T_3 * V_438 ,
struct V_441 * V_442 )
{
struct V_37 * V_443 = F_42 ( V_440 -> V_438 ) ;
if ( V_443 )
memcpy ( V_438 , V_443 -> V_23 . V_286 , V_287 ) ;
else
memset ( V_438 , 0 , V_287 ) ;
memset ( V_442 , 0 , sizeof( * V_442 ) ) ;
V_442 -> V_151 = V_444 ;
V_442 -> V_153 = V_445 |
V_446 |
V_447 |
V_448 |
V_449 |
V_450 |
V_451 ;
V_442 -> V_452 = V_440 -> V_453 . V_454 ;
V_442 -> V_455 = V_440 -> V_455 ;
V_442 -> V_456 = V_440 -> V_456 ;
if ( F_171 ( V_172 , V_440 -> V_457 ) )
V_442 -> V_458 = F_59 ( V_440 -> V_457 - V_172 ) ;
V_442 -> V_459 =
F_59 ( V_440 -> V_459 ) ;
V_442 -> V_460 = V_440 -> V_460 ;
if ( V_440 -> V_5 & V_461 )
V_442 -> V_5 |= V_462 ;
if ( V_440 -> V_5 & V_463 )
V_442 -> V_5 |= V_464 ;
if ( V_440 -> V_5 & V_465 )
V_442 -> V_5 |= V_466 ;
if ( V_440 -> V_5 & V_467 )
V_442 -> V_5 |= V_468 ;
if ( V_440 -> V_5 & V_469 )
V_442 -> V_5 |= V_470 ;
}
static int F_172 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_437 , T_3 * V_438 , struct V_441 * V_442 )
{
struct V_11 * V_12 ;
struct V_439 * V_440 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_440 = F_169 ( V_12 , V_437 ) ;
if ( ! V_440 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_437 , V_440 -> V_437 , V_287 ) ;
F_170 ( V_440 , V_438 , V_442 ) ;
F_45 () ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_106 , T_3 * V_437 , T_3 * V_438 ,
struct V_441 * V_442 )
{
struct V_11 * V_12 ;
struct V_439 * V_440 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_440 = F_174 ( V_12 , V_106 ) ;
if ( ! V_440 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_437 , V_440 -> V_437 , V_287 ) ;
F_170 ( V_440 , V_438 , V_442 ) ;
F_45 () ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_471 * V_55 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_55 , & ( V_12 -> V_15 . V_68 . V_404 ) , sizeof( struct V_471 ) ) ;
return 0 ;
}
static inline bool F_176 ( enum V_472 V_473 , T_1 V_27 )
{
return ( V_27 >> ( V_473 - 1 ) ) & 0x1 ;
}
static int F_177 ( struct V_474 * V_475 ,
const struct V_476 * V_477 )
{
T_3 * V_478 ;
const T_3 * V_479 ;
struct V_11 * V_12 = F_178 ( V_475 ,
struct V_11 , V_15 . V_68 ) ;
V_478 = NULL ;
V_479 = V_475 -> V_480 ;
if ( V_477 -> V_481 ) {
V_478 = F_179 ( V_477 -> V_480 , V_477 -> V_481 ,
V_306 ) ;
if ( ! V_478 )
return - V_307 ;
}
V_475 -> V_481 = V_477 -> V_481 ;
V_475 -> V_480 = V_478 ;
F_109 ( V_479 ) ;
V_475 -> V_482 = V_477 -> V_482 ;
memcpy ( V_475 -> V_483 , V_477 -> V_483 , V_475 -> V_482 ) ;
V_475 -> V_484 = V_477 -> V_485 ;
V_475 -> V_486 = V_477 -> V_487 ;
V_475 -> V_488 = V_477 -> V_489 ;
V_475 -> V_423 = V_477 -> V_423 ;
V_475 -> V_490 = V_477 -> V_491 ;
V_475 -> V_69 = V_70 ;
if ( V_477 -> V_492 )
V_475 -> V_69 |= V_493 ;
if ( V_477 -> V_494 )
V_475 -> V_69 |= V_495 ;
memcpy ( V_12 -> V_26 . V_221 . V_496 , V_477 -> V_496 ,
sizeof( V_477 -> V_496 ) ) ;
V_12 -> V_26 . V_221 . V_497 = V_477 -> V_497 ;
V_12 -> V_26 . V_221 . V_231 = V_477 -> V_230 ;
V_12 -> V_26 . V_221 . V_228 = V_477 -> V_228 ;
return 0 ;
}
static int F_180 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_471 * V_498 )
{
struct V_471 * V_55 ;
struct V_11 * V_12 ;
struct V_474 * V_475 ;
V_12 = F_9 ( V_18 ) ;
V_475 = & V_12 -> V_15 . V_68 ;
V_55 = & ( V_12 -> V_15 . V_68 . V_404 ) ;
if ( F_176 ( V_499 , V_27 ) )
V_55 -> V_500 = V_498 -> V_500 ;
if ( F_176 ( V_501 , V_27 ) )
V_55 -> V_502 = V_498 -> V_502 ;
if ( F_176 ( V_503 , V_27 ) )
V_55 -> V_504 = V_498 -> V_504 ;
if ( F_176 ( V_505 , V_27 ) )
V_55 -> V_506 = V_498 -> V_506 ;
if ( F_176 ( V_507 , V_27 ) )
V_55 -> V_508 = V_498 -> V_508 ;
if ( F_176 ( V_509 , V_27 ) )
V_55 -> V_510 = V_498 -> V_510 ;
if ( F_176 ( V_511 , V_27 ) )
V_55 -> V_512 = V_498 -> V_512 ;
if ( F_176 ( V_513 , V_27 ) ) {
if ( V_475 -> V_423 )
return - V_30 ;
V_55 -> V_514 = V_498 -> V_514 ;
}
if ( F_176 ( V_515 , V_27 ) )
V_55 -> V_516 =
V_498 -> V_516 ;
if ( F_176 ( V_517 , V_27 ) )
V_55 -> V_518 =
V_498 -> V_518 ;
if ( F_176 ( V_519 , V_27 ) )
V_55 -> V_520 = V_498 -> V_520 ;
if ( F_176 ( V_521 , V_27 ) )
V_55 -> V_522 = V_498 -> V_522 ;
if ( F_176 ( V_523 , V_27 ) )
V_55 -> V_524 =
V_498 -> V_524 ;
if ( F_176 ( V_525 , V_27 ) )
V_55 -> V_526 =
V_498 -> V_526 ;
if ( F_176 ( V_527 , V_27 ) )
V_55 -> V_528 =
V_498 -> V_528 ;
if ( F_176 ( V_529 ,
V_27 ) )
V_55 -> V_530 =
V_498 -> V_530 ;
if ( F_176 ( V_531 , V_27 ) ) {
V_55 -> V_532 = V_498 -> V_532 ;
F_181 ( V_475 ) ;
}
if ( F_176 ( V_533 , V_27 ) ) {
if ( V_498 -> V_534 &&
! ( V_55 -> V_532 > V_535 ) ) {
V_55 -> V_532 = V_536 ;
F_181 ( V_475 ) ;
}
V_55 -> V_534 =
V_498 -> V_534 ;
}
if ( F_176 ( V_537 , V_27 ) )
V_55 -> V_538 =
V_498 -> V_538 ;
if ( F_176 ( V_539 , V_27 ) )
V_55 -> V_540 = V_498 -> V_540 ;
if ( F_176 ( V_541 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_114 . V_5 & V_186 ) )
return - V_542 ;
V_55 -> V_543 = V_498 -> V_543 ;
}
if ( F_176 ( V_544 , V_27 ) ) {
V_55 -> V_545 = V_498 -> V_545 ;
V_12 -> V_26 . V_221 . V_546 = V_498 -> V_545 ;
F_100 ( V_12 , V_547 ) ;
}
if ( F_176 ( V_548 , V_27 ) )
V_55 -> V_549 =
V_498 -> V_549 ;
if ( F_176 ( V_550 , V_27 ) )
V_55 -> V_551 =
V_498 -> V_551 ;
if ( F_176 ( V_552 , V_27 ) )
V_55 -> V_553 =
V_498 -> V_553 ;
if ( F_176 ( V_554 , V_27 ) ) {
V_55 -> V_405 = V_498 -> V_405 ;
F_182 ( V_12 ) ;
}
if ( F_176 ( V_555 , V_27 ) )
V_55 -> V_556 =
V_498 -> V_556 ;
if ( F_176 ( V_557 , V_27 ) )
V_55 -> V_558 = V_498 -> V_558 ;
F_141 ( V_12 , V_316 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_471 * V_55 ,
const struct V_476 * V_477 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_474 * V_475 = & V_12 -> V_15 . V_68 ;
int V_13 ;
memcpy ( & V_475 -> V_404 , V_55 , sizeof( struct V_471 ) ) ;
V_13 = F_177 ( V_475 , V_477 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_330 = V_331 ;
V_12 -> V_332 = V_12 -> V_9 -> V_333 ;
F_16 ( & V_12 -> V_9 -> V_292 ) ;
V_13 = F_87 ( V_12 , & V_477 -> V_290 ,
V_334 ) ;
F_18 ( & V_12 -> V_9 -> V_292 ) ;
if ( V_13 )
return V_13 ;
return F_184 ( V_12 ) ;
}
static int F_185 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_186 ( V_12 ) ;
F_16 ( & V_12 -> V_9 -> V_292 ) ;
F_86 ( V_12 ) ;
F_18 ( & V_12 -> V_9 -> V_292 ) ;
return 0 ;
}
static int F_187 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_559 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_384 V_385 ;
T_1 V_315 = 0 ;
if ( ! F_90 ( V_12 -> V_15 . V_305 . V_317 , V_12 ) )
return - V_59 ;
V_385 = F_54 ( V_12 ) ;
if ( V_7 -> V_222 >= 0 ) {
V_12 -> V_26 . V_221 . V_222 = V_7 -> V_222 ;
V_315 |= V_560 ;
}
if ( V_7 -> V_224 >= 0 ) {
V_12 -> V_26 . V_221 . V_224 =
V_7 -> V_224 ;
V_315 |= V_561 ;
}
if ( ! V_12 -> V_26 . V_221 . V_226 &&
V_385 == V_562 ) {
V_12 -> V_26 . V_221 . V_226 = true ;
V_315 |= V_563 ;
}
if ( V_7 -> V_564 >= 0 ) {
V_12 -> V_26 . V_221 . V_226 =
V_7 -> V_564 ;
V_315 |= V_563 ;
}
if ( V_7 -> V_497 ) {
F_131 ( & V_12 -> V_26 . V_221 . V_290 ,
V_2 -> V_115 [ V_385 ] ,
V_7 -> V_497 ,
V_7 -> V_565 ,
& V_12 -> V_26 . V_221 . V_497 ) ;
V_315 |= V_566 ;
}
if ( V_7 -> V_567 >= 0 ) {
if ( V_7 -> V_567 )
V_12 -> V_5 |= V_568 ;
else
V_12 -> V_5 &= ~ V_568 ;
}
if ( V_7 -> V_545 >= 0 ) {
V_12 -> V_26 . V_221 . V_546 =
( T_2 ) V_7 -> V_545 ;
V_315 |= V_547 ;
}
if ( V_7 -> V_347 >= 0 ) {
V_12 -> V_26 . V_221 . V_345 . V_346 &=
~ V_348 ;
V_12 -> V_26 . V_221 . V_345 . V_346 |=
V_7 -> V_347 & V_348 ;
V_315 |= V_328 ;
}
if ( V_7 -> V_349 > 0 ) {
V_12 -> V_26 . V_221 . V_345 . V_346 |=
V_350 ;
V_315 |= V_328 ;
} else if ( V_7 -> V_349 == 0 ) {
V_12 -> V_26 . V_221 . V_345 . V_346 &=
~ V_350 ;
V_315 |= V_328 ;
}
F_100 ( V_12 , V_315 ) ;
return 0 ;
}
static int F_188 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_569 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_570 V_571 ;
if ( ! V_9 -> V_190 -> V_572 )
return - V_254 ;
if ( V_9 -> V_114 . V_573 < V_175 )
return - V_254 ;
memset ( & V_571 , 0 , sizeof( V_571 ) ) ;
V_571 . V_574 = V_7 -> V_574 ;
V_571 . V_575 = V_7 -> V_576 ;
V_571 . V_577 = V_7 -> V_578 ;
V_571 . V_579 = V_7 -> V_579 ;
V_571 . V_580 = false ;
V_12 -> V_581 [ V_7 -> V_148 ] = V_571 ;
if ( F_189 ( V_9 , V_12 , V_7 -> V_148 , & V_571 ) ) {
F_190 ( V_9 -> V_114 . V_2 ,
L_2 ,
V_7 -> V_148 ) ;
return - V_48 ;
}
F_100 ( V_12 , V_582 ) ;
return 0 ;
}
static int F_191 ( struct V_2 * V_2 ,
struct V_583 * V_584 )
{
return F_192 ( F_2 ( V_2 ) , V_584 ) ;
}
static int F_193 ( struct V_2 * V_2 )
{
return F_194 ( F_2 ( V_2 ) ) ;
}
static int F_195 ( struct V_2 * V_2 ,
struct V_585 * V_586 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_586 -> V_10 ) ;
switch ( F_196 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_66 :
case V_67 :
case V_75 :
case V_72 :
break;
case V_76 :
if ( V_12 -> V_9 -> V_190 -> V_587 )
break;
case V_64 :
if ( V_12 -> V_15 . V_305 . V_317 &&
( ! ( V_2 -> V_588 & V_589 ) ||
! ( V_586 -> V_5 & V_590 ) ) )
return - V_254 ;
break;
default:
return - V_254 ;
}
return F_197 ( V_12 , V_586 ) ;
}
static int
F_198 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_591 * V_586 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_190 -> V_592 )
return - V_254 ;
return F_199 ( V_12 , V_586 ) ;
}
static int
F_200 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_190 -> V_593 )
return - V_254 ;
return F_201 ( V_12 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_594 * V_586 )
{
return F_203 ( F_9 ( V_18 ) , V_586 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_595 * V_586 )
{
return F_205 ( F_9 ( V_18 ) , V_586 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_596 * V_586 )
{
return F_207 ( F_9 ( V_18 ) , V_586 ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_597 * V_586 )
{
return F_209 ( F_9 ( V_18 ) , V_586 ) ;
}
static int F_210 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_598 * V_7 )
{
return F_211 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_212 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_213 ( F_9 ( V_18 ) ) ;
}
static int F_214 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 [ V_599 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_221 . V_496 , V_100 ,
sizeof( int ) * V_599 ) ;
return 0 ;
}
static int F_215 ( struct V_2 * V_2 , T_1 V_315 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_315 & V_600 ) {
V_13 = F_216 ( V_9 , V_2 -> V_601 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_315 & V_602 ) {
V_13 = F_217 ( V_9 , V_2 -> V_603 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_315 & V_604 ) {
V_13 = F_218 ( V_9 , V_2 -> V_605 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_315 & V_606 ) {
if ( V_2 -> V_607 > V_608 )
return - V_48 ;
V_9 -> V_114 . V_55 . V_609 = V_2 -> V_607 ;
}
if ( V_315 & V_610 ) {
if ( V_2 -> V_611 > V_608 )
return - V_48 ;
V_9 -> V_114 . V_55 . V_612 = V_2 -> V_611 ;
}
if ( V_315 &
( V_606 | V_610 ) )
F_88 ( V_9 , V_613 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_614 type , int V_615 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_616 :
V_12 -> V_617 = V_618 ;
break;
case V_619 :
case V_620 :
if ( V_615 < 0 || ( V_615 % 100 ) )
return - V_254 ;
V_12 -> V_617 = F_220 ( V_615 ) ;
break;
}
F_221 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_616 :
V_9 -> V_617 = V_618 ;
break;
case V_619 :
case V_620 :
if ( V_615 < 0 || ( V_615 % 100 ) )
return - V_254 ;
V_9 -> V_617 = F_220 ( V_615 ) ;
break;
}
F_16 ( & V_9 -> V_293 ) ;
F_72 (sdata, &local->interfaces, list)
V_12 -> V_617 = V_9 -> V_617 ;
F_72 (sdata, &local->interfaces, list)
F_221 ( V_12 ) ;
F_18 ( & V_9 -> V_293 ) ;
return 0 ;
}
static int F_222 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_621 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_294 )
* V_621 = V_9 -> V_114 . V_55 . V_622 ;
else
* V_621 = V_12 -> V_26 . V_221 . V_623 ;
return 0 ;
}
static int F_223 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_286 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_624 . V_625 , V_286 , V_287 ) ;
return 0 ;
}
static void F_224 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_225 ( V_9 ) ;
}
static int F_226 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_257 , int V_308 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_626 * V_26 = NULL ;
if ( ! V_9 -> V_190 -> V_627 )
return - V_254 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_628 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_190 -> V_627 ( & V_9 -> V_114 , V_26 , V_257 , V_308 ) ;
}
static int F_227 ( struct V_2 * V_2 ,
struct V_369 * V_370 ,
struct V_629 * V_378 ,
void * V_257 , int V_308 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_190 -> V_630 )
return - V_254 ;
return V_9 -> V_190 -> V_630 ( & V_9 -> V_114 , V_370 , V_378 , V_257 , V_308 ) ;
}
int F_228 ( struct V_11 * V_12 ,
enum V_631 V_330 )
{
struct V_37 * V_23 ;
enum V_631 V_632 ;
int V_147 ;
if ( F_34 ( V_12 -> V_26 . type != V_64 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_221 . V_290 . V_633 == V_634 )
return 0 ;
V_632 = V_12 -> V_15 . V_305 . V_436 ;
V_12 -> V_15 . V_305 . V_436 = V_330 ;
if ( V_632 == V_330 ||
V_330 == V_635 )
return 0 ;
if ( ! F_229 ( & V_12 -> V_15 . V_305 . V_434 ) ) {
V_12 -> V_330 = V_330 ;
F_230 ( & V_12 -> V_9 -> V_114 , & V_12 -> V_636 ) ;
return 0 ;
}
F_158 ( V_12 ,
L_3 ,
V_330 , F_229 ( & V_12 -> V_15 . V_305 . V_434 ) ) ;
F_16 ( & V_12 -> V_9 -> V_57 ) ;
for ( V_147 = 0 ; V_147 < V_637 ; V_147 ++ ) {
for ( V_23 = F_84 ( V_12 -> V_9 -> V_638 [ V_147 ] ,
F_85 ( & V_12 -> V_9 -> V_57 ) ) ;
V_23 ;
V_23 = F_84 ( V_23 -> V_639 ,
F_85 ( & V_12 -> V_9 -> V_57 ) ) ) {
if ( V_23 -> V_12 -> V_433 != & V_12 -> V_15 . V_305 )
continue;
if ( F_157 ( V_23 ) == 1 )
continue;
if ( F_31 ( V_23 , V_640 ) &&
! F_231 ( V_23 -> V_435 ,
V_330 ) ) {
F_158 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_286 ) ;
continue;
}
if ( ! F_31 ( V_23 , V_241 ) )
continue;
F_158 ( V_12 , L_5 , V_23 -> V_23 . V_286 ) ;
F_159 ( V_12 , V_330 ,
V_23 -> V_23 . V_286 ,
V_12 -> V_26 . V_221 . V_265 ) ;
}
}
F_18 ( & V_12 -> V_9 -> V_57 ) ;
V_12 -> V_330 = V_330 ;
F_230 ( & V_12 -> V_9 -> V_114 , & V_12 -> V_636 ) ;
return 0 ;
}
int F_232 ( struct V_11 * V_12 ,
enum V_631 V_330 )
{
const T_3 * V_305 ;
enum V_631 V_632 ;
int V_13 ;
F_105 ( & V_12 -> V_10 . V_292 ) ;
if ( F_34 ( V_12 -> V_26 . type != V_24 ) )
return - V_48 ;
V_632 = V_12 -> V_15 . V_25 . V_436 ;
V_12 -> V_15 . V_25 . V_436 = V_330 ;
if ( V_632 == V_330 &&
V_330 != V_635 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_641 ||
V_12 -> V_26 . V_221 . V_290 . V_633 == V_634 )
return 0 ;
V_305 = V_12 -> V_15 . V_25 . V_641 -> V_265 ;
if ( V_330 == V_635 ) {
if ( V_12 -> V_15 . V_25 . V_642 )
V_330 = V_643 ;
else
V_330 = V_331 ;
}
V_13 = F_159 ( V_12 , V_330 ,
V_305 , V_305 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_436 = V_632 ;
return V_13 ;
}
static int F_233 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_644 , int V_645 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_80 ( V_18 -> V_288 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_254 ;
if ( ! ( V_9 -> V_114 . V_5 & V_646 ) )
return - V_254 ;
if ( V_644 == V_12 -> V_15 . V_25 . V_642 &&
V_645 == V_9 -> V_647 )
return 0 ;
V_12 -> V_15 . V_25 . V_642 = V_644 ;
V_9 -> V_647 = V_645 ;
F_234 ( V_12 ) ;
F_232 ( V_12 , V_12 -> V_15 . V_25 . V_436 ) ;
F_235 ( V_12 ) ;
if ( V_9 -> V_114 . V_5 & V_648 )
F_88 ( V_9 , V_649 ) ;
F_160 ( V_9 , - 1 ) ;
F_161 ( V_12 ) ;
return 0 ;
}
static int F_236 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_650 , T_1 V_651 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_626 * V_26 = & V_12 -> V_26 ;
struct V_652 * V_221 = & V_26 -> V_221 ;
if ( V_650 == V_221 -> V_653 &&
V_651 == V_221 -> V_654 )
return 0 ;
V_221 -> V_653 = V_650 ;
V_221 -> V_654 = V_651 ;
if ( V_12 -> V_15 . V_25 . V_641 &&
V_12 -> V_26 . V_655 & V_656 )
F_100 ( V_12 , V_657 ) ;
return 0 ;
}
static int F_237 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_286 ,
const struct V_658 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_80 ( V_18 -> V_288 ) ;
int V_147 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
if ( V_9 -> V_114 . V_5 & V_659 ) {
V_19 = F_238 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_147 = 0 ; V_147 < V_599 ; V_147 ++ ) {
struct V_110 * V_111 = V_2 -> V_115 [ V_147 ] ;
int V_660 ;
V_12 -> V_661 [ V_147 ] = V_27 -> V_375 [ V_147 ] . V_118 ;
memcpy ( V_12 -> V_662 [ V_147 ] , V_27 -> V_375 [ V_147 ] . V_663 ,
sizeof( V_27 -> V_375 [ V_147 ] . V_663 ) ) ;
V_12 -> V_664 [ V_147 ] = false ;
if ( ! V_111 )
continue;
for ( V_660 = 0 ; V_660 < V_665 ; V_660 ++ )
if ( ~ V_12 -> V_662 [ V_147 ] [ V_660 ] ) {
V_12 -> V_664 [ V_147 ] = true ;
break;
}
}
return 0 ;
}
static int F_239 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_260 * V_261 ,
unsigned int V_666 , T_4 * V_82 ,
struct V_369 * V_667 ,
enum V_668 type )
{
struct V_669 * V_670 , * V_671 ;
bool V_672 = false ;
int V_19 ;
F_105 ( & V_9 -> V_292 ) ;
if ( V_9 -> V_294 && ! V_9 -> V_190 -> V_673 )
return - V_254 ;
V_670 = F_91 ( sizeof( * V_670 ) , V_306 ) ;
if ( ! V_670 )
return - V_307 ;
if ( ! V_666 )
V_666 = 10 ;
V_670 -> V_269 = V_261 ;
V_670 -> V_666 = V_666 ;
V_670 -> V_674 = V_666 ;
V_670 -> V_675 = V_667 ;
V_670 -> type = type ;
V_670 -> V_676 = ( unsigned long ) V_667 ;
V_670 -> V_12 = V_12 ;
F_240 ( & V_670 -> V_677 , V_678 ) ;
F_241 ( & V_670 -> V_679 ) ;
if ( ! V_667 ) {
V_9 -> V_680 ++ ;
V_670 -> V_82 = V_9 -> V_680 ;
if ( F_70 ( V_670 -> V_82 == 0 ) ) {
V_670 -> V_82 = 1 ;
V_9 -> V_680 ++ ;
}
* V_82 = V_670 -> V_82 ;
} else {
* V_82 = ( unsigned long ) V_667 ;
}
if ( ! F_242 ( & V_9 -> V_681 ) ||
V_9 -> V_682 || V_9 -> V_683 )
goto V_684;
if ( ! V_9 -> V_190 -> V_673 ) {
F_243 ( & V_9 -> V_114 , & V_670 -> V_677 , 0 ) ;
goto V_685;
}
V_19 = F_244 ( V_9 , V_12 , V_261 , V_666 , type ) ;
if ( V_19 ) {
F_109 ( V_670 ) ;
return V_19 ;
}
V_670 -> V_686 = true ;
goto V_685;
V_684:
F_72 (tmp, &local->roc_list, list) {
if ( V_671 -> V_269 != V_261 || V_671 -> V_12 != V_12 )
continue;
if ( ! V_671 -> V_686 ) {
F_245 ( & V_670 -> V_687 , & V_671 -> V_679 ) ;
V_671 -> V_666 = F_246 ( V_671 -> V_666 , V_670 -> V_666 ) ;
V_671 -> type = F_246 ( V_671 -> type , V_670 -> type ) ;
V_672 = true ;
break;
}
if ( V_9 -> V_190 -> V_673 ) {
unsigned long V_660 = V_172 ;
if ( ! V_671 -> V_688 ) {
F_245 ( & V_670 -> V_687 , & V_671 -> V_679 ) ;
V_672 = true ;
break;
}
if ( F_171 ( V_660 + V_689 ,
V_671 -> V_690 +
F_247 ( V_671 -> V_666 ) ) ) {
int V_691 ;
F_248 ( V_670 ) ;
V_691 = V_670 -> V_666 -
F_59 ( V_671 -> V_690 +
F_247 (
V_671 -> V_666 ) -
V_660 ) ;
if ( V_691 > 0 ) {
F_249 ( & V_670 -> V_687 , & V_671 -> V_687 ) ;
} else {
F_245 ( & V_670 -> V_687 ,
& V_671 -> V_679 ) ;
}
V_672 = true ;
}
} else if ( F_250 ( & V_671 -> V_677 . V_692 ) ) {
unsigned long V_693 ;
F_245 ( & V_670 -> V_687 , & V_671 -> V_679 ) ;
V_672 = true ;
V_693 = V_172 + F_247 ( V_670 -> V_666 ) ;
if ( F_251 ( V_693 , V_671 -> V_677 . V_692 . V_694 ) )
F_252 ( & V_671 -> V_677 . V_692 , V_693 ) ;
else
F_253 ( & V_671 -> V_677 . V_692 ) ;
F_248 ( V_670 ) ;
}
break;
}
V_685:
if ( ! V_672 )
F_245 ( & V_670 -> V_687 , & V_9 -> V_681 ) ;
return 0 ;
}
static int F_254 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_260 * V_269 ,
unsigned int V_666 ,
T_4 * V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_292 ) ;
V_19 = F_239 ( V_9 , V_12 , V_269 ,
V_666 , V_82 , NULL ,
V_695 ) ;
F_18 ( & V_9 -> V_292 ) ;
return V_19 ;
}
static int F_255 ( struct V_8 * V_9 ,
T_4 V_82 , bool V_696 )
{
struct V_669 * V_670 , * V_671 , * V_697 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_292 ) ;
F_256 (roc, tmp, &local->roc_list, list) {
struct V_669 * V_698 , * V_699 ;
F_256 (dep, tmp2, &roc->dependents, list) {
if ( ! V_696 && V_698 -> V_82 != V_82 )
continue;
else if ( V_696 && V_698 -> V_676 != V_82 )
continue;
F_257 ( & V_698 -> V_687 ) ;
F_18 ( & V_9 -> V_292 ) ;
F_258 ( V_698 , true ) ;
return 0 ;
}
if ( ! V_696 && V_670 -> V_82 != V_82 )
continue;
else if ( V_696 && V_670 -> V_676 != V_82 )
continue;
V_697 = V_670 ;
break;
}
if ( ! V_697 ) {
F_18 ( & V_9 -> V_292 ) ;
return - V_59 ;
}
if ( V_9 -> V_190 -> V_673 ) {
if ( V_697 -> V_686 ) {
V_19 = F_259 ( V_9 ) ;
if ( F_34 ( V_19 ) ) {
F_18 ( & V_9 -> V_292 ) ;
return V_19 ;
}
}
F_257 ( & V_697 -> V_687 ) ;
if ( V_697 -> V_686 )
F_260 ( V_9 ) ;
F_18 ( & V_9 -> V_292 ) ;
F_258 ( V_697 , true ) ;
} else {
V_697 -> abort = true ;
F_243 ( & V_9 -> V_114 , & V_697 -> V_677 , 0 ) ;
F_18 ( & V_9 -> V_292 ) ;
F_261 ( & V_697 -> V_677 ) ;
F_70 ( ! V_697 -> V_700 ) ;
F_109 ( V_697 ) ;
}
return 0 ;
}
static int F_262 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_255 ( V_9 , V_82 , false ) ;
}
static int F_263 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_289 * V_290 ,
T_1 V_701 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_292 ) ;
if ( ! F_242 ( & V_9 -> V_681 ) || V_9 -> V_682 ) {
V_13 = - V_30 ;
goto V_60;
}
V_12 -> V_330 = V_331 ;
V_12 -> V_332 = V_9 -> V_333 ;
V_13 = F_87 ( V_12 , V_290 ,
V_334 ) ;
if ( V_13 )
goto V_60;
F_243 ( & V_12 -> V_9 -> V_114 ,
& V_12 -> V_362 ,
F_247 ( V_701 ) ) ;
V_60:
F_18 ( & V_9 -> V_292 ) ;
return V_13 ;
}
static struct V_310 *
F_264 ( struct V_310 * V_317 )
{
struct V_310 * V_702 ;
T_3 * V_703 ;
int V_308 ;
V_308 = V_317 -> V_319 + V_317 -> V_321 + V_317 -> V_704 +
V_317 -> V_705 + V_317 -> V_706 +
V_317 -> V_322 ;
V_702 = F_91 ( sizeof( * V_702 ) + V_308 , V_306 ) ;
if ( ! V_702 )
return NULL ;
V_703 = ( T_3 * ) ( V_702 + 1 ) ;
if ( V_317 -> V_319 ) {
V_702 -> V_319 = V_317 -> V_319 ;
V_702 -> V_318 = V_703 ;
memcpy ( V_703 , V_317 -> V_318 , V_317 -> V_319 ) ;
V_703 += V_317 -> V_319 ;
}
if ( V_317 -> V_321 ) {
V_702 -> V_321 = V_317 -> V_321 ;
V_702 -> V_320 = V_703 ;
memcpy ( V_703 , V_317 -> V_320 , V_317 -> V_321 ) ;
V_703 += V_317 -> V_321 ;
}
if ( V_317 -> V_704 ) {
V_702 -> V_704 = V_317 -> V_704 ;
V_702 -> V_707 = V_703 ;
memcpy ( V_703 , V_317 -> V_707 , V_317 -> V_704 ) ;
V_703 += V_317 -> V_704 ;
}
if ( V_317 -> V_705 ) {
V_702 -> V_705 = V_317 -> V_705 ;
V_702 -> V_708 = V_703 ;
memcpy ( V_703 , V_317 -> V_708 , V_317 -> V_705 ) ;
V_703 += V_317 -> V_705 ;
}
if ( V_317 -> V_706 ) {
V_702 -> V_706 = V_317 -> V_706 ;
V_702 -> V_709 = V_703 ;
memcpy ( V_703 , V_317 -> V_709 , V_317 -> V_706 ) ;
V_703 += V_317 -> V_706 ;
}
if ( V_317 -> V_322 ) {
V_702 -> V_322 = V_317 -> V_322 ;
V_317 -> V_302 = V_703 ;
memcpy ( V_703 , V_317 -> V_302 , V_317 -> V_322 ) ;
V_703 += V_317 -> V_322 ;
}
return V_702 ;
}
void F_265 ( struct V_626 * V_26 )
{
struct V_11 * V_12 = F_266 ( V_26 ) ;
F_230 ( & V_12 -> V_9 -> V_114 ,
& V_12 -> V_710 ) ;
}
static int F_267 ( struct V_11 * V_12 ,
T_1 * V_315 )
{
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_13 = F_94 ( V_12 , V_12 -> V_15 . V_305 . V_357 ) ;
F_109 ( V_12 -> V_15 . V_305 . V_357 ) ;
V_12 -> V_15 . V_305 . V_357 = NULL ;
if ( V_13 < 0 )
return V_13 ;
* V_315 |= V_13 ;
break;
case V_66 :
V_13 = F_268 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_315 |= V_13 ;
break;
#ifdef F_33
case V_67 :
V_13 = F_269 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_315 |= V_13 ;
break;
#endif
default:
F_70 ( 1 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_270 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_1 V_315 = 0 ;
int V_13 ;
F_103 ( V_12 ) ;
F_105 ( & V_9 -> V_292 ) ;
V_12 -> V_711 = V_12 -> V_712 ;
V_13 = F_271 ( V_12 , & V_315 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! V_9 -> V_294 ) {
V_9 -> V_299 = V_12 -> V_713 ;
F_88 ( V_9 , 0 ) ;
}
V_12 -> V_26 . V_351 = false ;
V_13 = F_267 ( V_12 , & V_315 ) ;
if ( V_13 )
return V_13 ;
F_100 ( V_12 , V_315 ) ;
F_272 ( V_12 -> V_18 , & V_12 -> V_713 ) ;
if ( ! F_104 ( V_9 ) )
F_108 ( & V_9 -> V_114 ,
V_355 ,
V_356 ) ;
return 0 ;
}
static void F_273 ( struct V_11 * V_12 )
{
if ( F_270 ( V_12 ) ) {
F_274 ( V_12 , L_6 ) ;
F_275 ( V_12 -> V_9 -> V_114 . V_2 , & V_12 -> V_10 ,
V_306 ) ;
}
}
void F_276 ( struct V_714 * V_677 )
{
struct V_11 * V_12 =
F_178 ( V_677 , struct V_11 ,
V_710 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
F_234 ( V_12 ) ;
F_16 ( & V_9 -> V_292 ) ;
if ( ! V_12 -> V_26 . V_351 )
goto V_715;
if ( ! F_12 ( V_12 ) )
goto V_715;
F_273 ( V_12 ) ;
V_715:
F_18 ( & V_9 -> V_292 ) ;
F_235 ( V_12 ) ;
}
static int F_277 ( struct V_11 * V_12 ,
struct V_716 * V_7 ,
T_1 * V_315 )
{
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_12 -> V_15 . V_305 . V_357 =
F_264 ( & V_7 -> V_717 ) ;
if ( ! V_12 -> V_15 . V_305 . V_357 )
return - V_307 ;
if ( V_7 -> V_718 <= 1 )
break;
if ( ( V_7 -> V_719 >
V_720 ) ||
( V_7 -> V_721 >
V_720 ) )
return - V_48 ;
memset ( V_12 -> V_722 , 0 ,
sizeof( V_12 -> V_722 ) ) ;
memset ( V_12 -> V_723 , 0 ,
sizeof( V_12 -> V_723 ) ) ;
memcpy ( V_12 -> V_722 ,
V_7 -> V_724 ,
V_7 -> V_719 * sizeof( T_2 ) ) ;
memcpy ( V_12 -> V_723 ,
V_7 -> V_725 ,
V_7 -> V_721 * sizeof( T_2 ) ) ;
V_13 = F_94 ( V_12 , & V_7 -> V_726 ) ;
if ( V_13 < 0 ) {
F_109 ( V_12 -> V_15 . V_305 . V_357 ) ;
return V_13 ;
}
* V_315 |= V_13 ;
break;
case V_66 :
if ( ! V_12 -> V_26 . V_221 . V_727 )
return - V_48 ;
if ( V_7 -> V_290 . V_633 != V_12 -> V_15 . V_728 . V_290 . V_633 )
return - V_48 ;
switch ( V_7 -> V_290 . V_633 ) {
case V_729 :
if ( F_278 ( & V_7 -> V_290 ) !=
F_278 ( & V_12 -> V_15 . V_728 . V_290 ) )
return - V_48 ;
case V_730 :
case V_731 :
case V_634 :
case V_732 :
break;
default:
return - V_48 ;
}
if ( V_12 -> V_15 . V_728 . V_290 . V_269 -> V_385 !=
V_7 -> V_290 . V_269 -> V_385 )
return - V_48 ;
if ( V_7 -> V_718 > 1 ) {
V_13 = F_279 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_315 |= V_13 ;
}
F_280 ( V_12 , V_7 ) ;
break;
#ifdef F_33
case V_67 : {
struct V_474 * V_475 = & V_12 -> V_15 . V_68 ;
if ( V_7 -> V_290 . V_633 != V_12 -> V_26 . V_221 . V_290 . V_633 )
return - V_48 ;
if ( V_12 -> V_26 . V_221 . V_290 . V_269 -> V_385 !=
V_7 -> V_290 . V_269 -> V_385 )
return - V_48 ;
if ( V_475 -> V_733 == V_734 ) {
V_475 -> V_733 = V_735 ;
if ( ! V_475 -> V_736 )
V_475 -> V_736 = 1 ;
else
V_475 -> V_736 ++ ;
}
if ( V_7 -> V_718 > 1 ) {
V_13 = F_281 ( V_12 , V_7 ) ;
if ( V_13 < 0 ) {
V_475 -> V_733 = V_734 ;
return V_13 ;
}
* V_315 |= V_13 ;
}
if ( V_475 -> V_733 == V_735 )
F_280 ( V_12 , V_7 ) ;
break;
}
#endif
default:
return - V_254 ;
}
return 0 ;
}
static int
F_282 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_716 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_258 * V_55 ;
struct V_737 * V_738 ;
int V_13 , V_739 , V_315 = 0 ;
F_103 ( V_12 ) ;
F_105 ( & V_9 -> V_292 ) ;
if ( ! F_242 ( & V_9 -> V_681 ) || V_9 -> V_682 )
return - V_30 ;
if ( V_12 -> V_10 . V_361 )
return - V_30 ;
if ( F_83 ( & V_7 -> V_290 ,
& V_12 -> V_26 . V_221 . V_290 ) )
return - V_48 ;
F_16 ( & V_9 -> V_31 ) ;
V_55 = F_84 ( V_12 -> V_26 . V_259 ,
F_85 ( & V_9 -> V_31 ) ) ;
if ( ! V_55 ) {
F_18 ( & V_9 -> V_31 ) ;
return - V_30 ;
}
V_738 = F_178 ( V_55 , struct V_737 , V_55 ) ;
if ( F_283 ( V_9 , V_738 ) > 1 ) {
F_18 ( & V_9 -> V_31 ) ;
return - V_30 ;
}
V_739 = 0 ;
F_106 (chanctx, &local->chanctx_list, list)
V_739 ++ ;
F_18 ( & V_9 -> V_31 ) ;
if ( V_739 > 1 )
return - V_30 ;
if ( V_12 -> V_26 . V_351 )
return - V_30 ;
V_13 = F_277 ( V_12 , V_7 , & V_315 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_712 = V_7 -> V_711 ;
V_12 -> V_713 = V_7 -> V_290 ;
V_12 -> V_352 = V_7 -> V_740 ;
V_12 -> V_741 = V_7 -> V_718 ;
V_12 -> V_26 . V_351 = true ;
if ( V_12 -> V_352 )
F_284 ( & V_9 -> V_114 ,
V_355 ,
V_356 ) ;
if ( V_315 ) {
F_100 ( V_12 , V_315 ) ;
F_285 ( V_12 , & V_7 -> V_290 ) ;
} else {
F_273 ( V_12 ) ;
}
return 0 ;
}
int F_286 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_716 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_292 ) ;
V_13 = F_282 ( V_2 , V_18 , V_7 ) ;
F_18 ( & V_9 -> V_292 ) ;
return V_13 ;
}
static int F_287 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_742 * V_7 ,
T_4 * V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_369 * V_370 ;
struct V_37 * V_23 ;
const struct V_743 * V_744 = ( void * ) V_7 -> V_745 ;
bool V_746 = false ;
T_1 V_5 ;
int V_19 ;
T_3 * V_257 ;
if ( V_7 -> V_747 )
V_5 = V_748 ;
else
V_5 = V_749 |
V_750 ;
if ( V_7 -> V_751 )
V_5 |= V_752 ;
switch ( V_12 -> V_26 . type ) {
case V_66 :
if ( ! V_12 -> V_26 . V_221 . V_727 )
V_746 = true ;
#ifdef F_33
case V_67 :
if ( F_28 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_68 . V_482 )
V_746 = true ;
#endif
case V_64 :
case V_20 :
case V_76 :
if ( V_12 -> V_26 . type != V_66 &&
! F_28 ( & V_12 -> V_26 ) &&
! F_288 ( V_12 -> V_433 -> V_317 ) )
V_746 = true ;
if ( ! F_289 ( V_744 -> V_753 ) ||
V_744 -> V_15 . V_754 . V_755 == V_756 ||
V_744 -> V_15 . V_754 . V_755 == V_757 ||
V_744 -> V_15 . V_754 . V_755 == V_758 )
break;
F_41 () ;
V_23 = F_29 ( V_12 , V_744 -> V_371 ) ;
F_45 () ;
if ( ! V_23 )
return - V_759 ;
break;
case V_24 :
case V_75 :
if ( ! V_12 -> V_15 . V_25 . V_641 )
V_746 = true ;
break;
case V_72 :
V_746 = true ;
break;
default:
return - V_254 ;
}
if ( V_746 && ! V_7 -> V_269 )
return - V_48 ;
F_16 ( & V_9 -> V_292 ) ;
if ( ! V_746 ) {
struct V_258 * V_259 ;
F_41 () ;
V_259 = F_42 ( V_12 -> V_26 . V_259 ) ;
if ( V_259 ) {
V_746 = V_7 -> V_269 &&
( V_7 -> V_269 !=
V_259 -> V_268 . V_269 ) ;
} else if ( ! V_7 -> V_269 ) {
V_19 = - V_48 ;
F_45 () ;
goto V_60;
} else {
V_746 = true ;
}
F_45 () ;
}
if ( V_746 && ! V_7 -> V_760 ) {
V_19 = - V_30 ;
goto V_60;
}
V_370 = F_120 ( V_9 -> V_114 . V_761 + V_7 -> V_308 ) ;
if ( ! V_370 ) {
V_19 = - V_307 ;
goto V_60;
}
F_290 ( V_370 , V_9 -> V_114 . V_761 ) ;
V_257 = F_121 ( V_370 , V_7 -> V_308 ) ;
memcpy ( V_257 , V_7 -> V_745 , V_7 -> V_308 ) ;
if ( V_12 -> V_26 . V_351 &&
( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_66 ) &&
V_7 -> V_762 ) {
int V_147 ;
T_3 V_763 = V_12 -> V_741 ;
for ( V_147 = 0 ; V_147 < V_7 -> V_762 ; V_147 ++ )
V_257 [ V_7 -> V_764 [ V_147 ] ] = V_763 ;
}
F_291 ( V_370 ) -> V_5 = V_5 ;
V_370 -> V_18 = V_12 -> V_18 ;
if ( ! V_746 ) {
* V_82 = ( unsigned long ) V_370 ;
F_292 ( V_12 , V_370 ) ;
V_19 = 0 ;
goto V_60;
}
F_291 ( V_370 ) -> V_5 |= V_765 |
V_766 ;
if ( V_9 -> V_114 . V_5 & V_767 )
F_291 ( V_370 ) -> V_768 =
V_9 -> V_114 . V_769 ;
V_19 = F_239 ( V_9 , V_12 , V_7 -> V_269 ,
V_7 -> V_770 , V_82 , V_370 ,
V_771 ) ;
if ( V_19 )
F_293 ( V_370 ) ;
V_60:
F_18 ( & V_9 -> V_292 ) ;
return V_19 ;
}
static int F_294 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_82 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_255 ( V_9 , V_82 , true ) ;
}
static void F_295 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_772 , bool V_773 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_772 ) {
case V_774 | V_775 :
if ( V_773 )
V_9 -> V_776 ++ ;
else
V_9 -> V_776 -- ;
if ( ! V_9 -> V_297 )
break;
F_230 ( & V_9 -> V_114 , & V_9 -> V_777 ) ;
break;
default:
break;
}
}
static int F_296 ( struct V_2 * V_2 , T_1 V_778 , T_1 V_779 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_686 )
return - V_254 ;
return F_297 ( V_9 , V_778 , V_779 ) ;
}
static int F_298 ( struct V_2 * V_2 , T_1 * V_778 , T_1 * V_779 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_299 ( V_9 , V_778 , V_779 ) ;
}
static int F_300 ( struct V_2 * V_2 , T_1 V_90 , T_1 V_780 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_301 ( V_9 , V_90 , V_780 ) ;
}
static void F_302 ( struct V_2 * V_2 ,
T_1 * V_90 , T_1 * V_781 , T_1 * V_780 , T_1 * V_782 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_303 ( V_9 , V_90 , V_781 , V_780 , V_782 ) ;
}
static int F_304 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_783 * V_257 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_190 -> V_784 )
return - V_254 ;
F_305 ( V_9 , V_12 , V_257 ) ;
return 0 ;
}
static int F_306 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_785 , T_4 * V_82 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_786 * V_787 ;
struct V_369 * V_370 ;
int V_314 = sizeof( * V_787 ) ;
T_7 V_788 ;
bool V_789 ;
struct V_790 * V_791 ;
struct V_37 * V_23 ;
struct V_258 * V_259 ;
enum V_384 V_385 ;
F_41 () ;
V_259 = F_42 ( V_12 -> V_26 . V_259 ) ;
if ( F_70 ( ! V_259 ) ) {
F_45 () ;
return - V_48 ;
}
V_385 = V_259 -> V_268 . V_269 -> V_385 ;
V_23 = F_30 ( V_12 , V_785 ) ;
if ( V_23 ) {
V_789 = F_31 ( V_23 , V_243 ) ;
} else {
F_45 () ;
return - V_759 ;
}
if ( V_789 ) {
V_788 = F_307 ( V_792 |
V_793 |
V_794 ) ;
} else {
V_314 -= 2 ;
V_788 = F_307 ( V_792 |
V_795 |
V_794 ) ;
}
V_370 = F_120 ( V_9 -> V_114 . V_761 + V_314 ) ;
if ( ! V_370 ) {
F_45 () ;
return - V_307 ;
}
V_370 -> V_18 = V_18 ;
F_290 ( V_370 , V_9 -> V_114 . V_761 ) ;
V_787 = ( void * ) F_121 ( V_370 , V_314 ) ;
V_787 -> V_753 = V_788 ;
V_787 -> V_796 = 0 ;
memcpy ( V_787 -> V_797 , V_23 -> V_23 . V_286 , V_287 ) ;
memcpy ( V_787 -> V_798 , V_12 -> V_26 . V_286 , V_287 ) ;
memcpy ( V_787 -> V_799 , V_12 -> V_26 . V_286 , V_287 ) ;
V_787 -> V_800 = 0 ;
V_791 = F_291 ( V_370 ) ;
V_791 -> V_5 |= V_750 |
V_749 ;
F_308 ( V_370 , V_801 ) ;
V_370 -> V_802 = 7 ;
if ( V_789 )
V_787 -> V_803 = F_307 ( 7 ) ;
F_309 () ;
F_310 ( V_12 , V_370 , V_385 ) ;
F_311 () ;
F_45 () ;
* V_82 = ( unsigned long ) V_370 ;
return 0 ;
}
static int F_312 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_289 * V_290 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_258 * V_259 ;
int V_19 = - V_804 ;
F_41 () ;
V_259 = F_42 ( V_12 -> V_26 . V_259 ) ;
if ( V_259 ) {
* V_290 = V_259 -> V_268 ;
V_19 = 0 ;
} else if ( V_9 -> V_297 > 0 &&
V_9 -> V_297 == V_9 -> V_298 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_294 )
* V_290 = V_9 -> V_291 ;
else
* V_290 = V_9 -> V_299 ;
V_19 = 0 ;
}
F_45 () ;
return V_19 ;
}
static void F_313 ( struct V_2 * V_2 , bool V_644 )
{
F_314 ( F_2 ( V_2 ) , V_644 ) ;
}
static int F_315 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_805 * V_806 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_807 * V_808 , * V_809 ;
if ( V_806 ) {
V_808 = F_91 ( sizeof( * V_808 ) , V_306 ) ;
if ( ! V_808 )
return - V_307 ;
memcpy ( & V_808 -> V_806 , V_806 , sizeof( * V_806 ) ) ;
} else {
V_808 = NULL ;
}
V_809 = F_90 ( V_12 -> V_806 , V_12 ) ;
F_92 ( V_12 -> V_806 , V_808 ) ;
if ( V_809 )
F_93 ( V_809 , V_309 ) ;
return 0 ;
}
static int F_316 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_289 * V_290 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
T_1 V_315 = 0 ;
V_19 = F_317 ( V_12 , V_290 , & V_315 ) ;
if ( V_19 == 0 )
F_100 ( V_12 , V_315 ) ;
return V_19 ;
}
