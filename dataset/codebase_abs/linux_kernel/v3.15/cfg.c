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
return F_16 ( V_10 , true ) ;
}
static void F_17 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
F_18 ( F_5 ( V_10 ) ) ;
}
static int F_19 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_2 V_31 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_31 = V_31 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 ,
struct V_35 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 = NULL ;
const struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_41 ;
switch ( V_7 -> V_42 ) {
case V_43 :
case V_44 :
case V_45 :
if ( F_21 ( V_9 -> V_46 ) )
return - V_47 ;
break;
case V_48 :
case V_49 :
case V_50 :
break;
default:
V_38 = F_22 ( V_9 , V_7 -> V_42 , V_12 -> V_26 . type ) ;
break;
}
V_40 = F_23 ( V_7 -> V_42 , V_32 , V_7 -> V_51 ,
V_7 -> V_40 , V_7 -> V_52 , V_7 -> V_53 ,
V_38 ) ;
if ( F_21 ( V_40 ) )
return F_24 ( V_40 ) ;
if ( V_33 )
V_40 -> V_54 . V_5 |= V_55 ;
F_25 ( & V_9 -> V_56 ) ;
if ( V_34 ) {
if ( F_26 ( & V_12 -> V_26 ) )
V_23 = F_27 ( V_12 , V_34 ) ;
else
V_23 = F_28 ( V_12 , V_34 ) ;
if ( ! V_23 || ! F_29 ( V_23 , V_57 ) ) {
F_30 ( V_40 ) ;
V_13 = - V_58 ;
goto V_59;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_60 != V_61 )
V_40 -> V_54 . V_5 |= V_62 ;
break;
case V_63 :
case V_20 :
if ( V_40 -> V_23 && F_29 ( V_40 -> V_23 , V_64 ) )
V_40 -> V_54 . V_5 |= V_62 ;
break;
case V_65 :
break;
case V_66 :
#ifdef F_31
if ( V_12 -> V_15 . V_67 . V_68 != V_69 )
V_40 -> V_54 . V_5 |= V_62 ;
break;
#endif
case V_70 :
case V_14 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
F_32 ( 1 ) ;
break;
}
if ( V_23 )
V_23 -> V_76 = V_38 ;
V_13 = F_33 ( V_40 , V_12 , V_23 ) ;
V_59:
F_34 ( & V_9 -> V_56 ) ;
return V_13 ;
}
static int F_35 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
struct V_39 * V_40 = NULL ;
int V_19 ;
F_25 ( & V_9 -> V_56 ) ;
F_25 ( & V_9 -> V_77 ) ;
if ( V_34 ) {
V_19 = - V_58 ;
V_23 = F_28 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_59;
if ( V_33 )
V_40 = F_36 ( V_9 , V_23 -> V_78 [ V_32 ] ) ;
else
V_40 = F_36 ( V_9 , V_23 -> V_79 [ V_32 ] ) ;
} else
V_40 = F_36 ( V_9 , V_12 -> V_80 [ V_32 ] ) ;
if ( ! V_40 ) {
V_19 = - V_58 ;
goto V_59;
}
F_37 ( V_40 , true ) ;
V_19 = 0 ;
V_59:
F_34 ( & V_9 -> V_77 ) ;
F_34 ( & V_9 -> V_56 ) ;
return V_19 ;
}
static int F_38 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 ,
void * V_81 ,
void (* F_39)( void * V_81 ,
struct V_35 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_36 * V_23 = NULL ;
T_3 V_53 [ 6 ] = { 0 } ;
struct V_35 V_7 ;
struct V_39 * V_40 = NULL ;
T_4 V_82 ;
T_1 V_83 ;
T_2 V_84 ;
int V_13 = - V_58 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
if ( V_34 ) {
V_23 = F_28 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_85;
if ( V_33 && V_32 < V_86 )
V_40 = F_41 ( V_23 -> V_78 [ V_32 ] ) ;
else if ( ! V_33 &&
V_32 < V_86 + V_87 )
V_40 = F_41 ( V_23 -> V_79 [ V_32 ] ) ;
} else
V_40 = F_41 ( V_12 -> V_80 [ V_32 ] ) ;
if ( ! V_40 )
goto V_85;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_42 = V_40 -> V_54 . V_42 ;
switch ( V_40 -> V_54 . V_42 ) {
case V_44 :
V_83 = V_40 -> V_15 . V_88 . V_89 . V_83 ;
V_84 = V_40 -> V_15 . V_88 . V_89 . V_84 ;
if ( V_40 -> V_5 & V_90 )
F_42 ( V_12 -> V_9 ,
V_40 -> V_54 . V_91 ,
& V_83 , & V_84 ) ;
V_53 [ 0 ] = V_84 & 0xff ;
V_53 [ 1 ] = ( V_84 >> 8 ) & 0xff ;
V_53 [ 2 ] = V_83 & 0xff ;
V_53 [ 3 ] = ( V_83 >> 8 ) & 0xff ;
V_53 [ 4 ] = ( V_83 >> 16 ) & 0xff ;
V_53 [ 5 ] = ( V_83 >> 24 ) & 0xff ;
V_7 . V_53 = V_53 ;
V_7 . V_52 = 6 ;
break;
case V_48 :
V_82 = F_43 ( & V_40 -> V_15 . V_92 . V_93 ) ;
V_53 [ 0 ] = V_82 ;
V_53 [ 1 ] = V_82 >> 8 ;
V_53 [ 2 ] = V_82 >> 16 ;
V_53 [ 3 ] = V_82 >> 24 ;
V_53 [ 4 ] = V_82 >> 32 ;
V_53 [ 5 ] = V_82 >> 40 ;
V_7 . V_53 = V_53 ;
V_7 . V_52 = 6 ;
break;
case V_49 :
V_82 = F_43 ( & V_40 -> V_15 . V_94 . V_93 ) ;
V_53 [ 0 ] = V_82 ;
V_53 [ 1 ] = V_82 >> 8 ;
V_53 [ 2 ] = V_82 >> 16 ;
V_53 [ 3 ] = V_82 >> 24 ;
V_53 [ 4 ] = V_82 >> 32 ;
V_53 [ 5 ] = V_82 >> 40 ;
V_7 . V_53 = V_53 ;
V_7 . V_52 = 6 ;
break;
}
V_7 . V_40 = V_40 -> V_54 . V_40 ;
V_7 . V_51 = V_40 -> V_54 . V_95 ;
F_39 ( V_81 , & V_7 ) ;
V_13 = 0 ;
V_85:
F_44 () ;
return V_13 ;
}
static int F_45 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 , bool V_96 ,
bool V_97 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_46 ( V_12 , V_32 , V_96 , V_97 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_48 ( V_12 , V_32 ) ;
return 0 ;
}
void F_49 ( struct V_36 * V_23 ,
const struct V_98 * V_99 ,
struct V_100 * V_101 )
{
V_101 -> V_5 = 0 ;
if ( V_99 -> V_5 & V_102 ) {
V_101 -> V_5 |= V_103 ;
V_101 -> V_104 = V_99 -> V_105 ;
} else if ( V_99 -> V_5 & V_106 ) {
V_101 -> V_5 |= V_107 ;
V_101 -> V_104 = F_50 ( V_99 ) ;
V_101 -> V_108 = F_51 ( V_99 ) ;
} else {
struct V_109 * V_110 ;
int V_111 = F_52 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_112 ;
V_110 = V_23 -> V_9 -> V_113 . V_2 -> V_114 [
F_53 ( V_23 -> V_12 ) ] ;
V_112 = V_110 -> V_115 [ V_99 -> V_105 ] . V_116 ;
V_101 -> V_117 = F_54 ( V_112 , 1 << V_111 ) ;
}
if ( V_99 -> V_5 & V_118 )
V_101 -> V_5 |= V_119 ;
if ( V_99 -> V_5 & V_120 )
V_101 -> V_5 |= V_121 ;
if ( V_99 -> V_5 & V_122 )
V_101 -> V_5 |= V_123 ;
if ( V_99 -> V_5 & V_124 )
V_101 -> V_5 |= V_125 ;
}
void F_55 ( struct V_36 * V_23 , struct V_100 * V_101 )
{
V_101 -> V_5 = 0 ;
if ( V_23 -> V_126 & V_127 ) {
V_101 -> V_5 |= V_103 ;
V_101 -> V_104 = V_23 -> V_128 ;
} else if ( V_23 -> V_126 & V_129 ) {
V_101 -> V_5 |= V_107 ;
V_101 -> V_108 = V_23 -> V_130 ;
V_101 -> V_104 = V_23 -> V_128 ;
} else {
struct V_109 * V_110 ;
int V_111 = F_52 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_112 ;
V_110 = V_23 -> V_9 -> V_113 . V_2 -> V_114 [
F_53 ( V_23 -> V_12 ) ] ;
V_112 = V_110 -> V_115 [ V_23 -> V_128 ] . V_116 ;
V_101 -> V_117 = F_54 ( V_112 , 1 << V_111 ) ;
}
if ( V_23 -> V_126 & V_131 )
V_101 -> V_5 |= V_119 ;
if ( V_23 -> V_126 & V_132 )
V_101 -> V_5 |= V_125 ;
if ( V_23 -> V_133 & V_134 )
V_101 -> V_5 |= V_121 ;
if ( V_23 -> V_133 & V_135 )
V_101 -> V_5 |= V_136 ;
if ( V_23 -> V_133 & V_137 )
V_101 -> V_5 |= V_123 ;
}
static void F_56 ( struct V_36 * V_23 , struct V_138 * V_139 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_140 V_141 ;
T_4 V_142 = 0 ;
int V_143 , V_144 ;
V_139 -> V_145 = V_12 -> V_9 -> V_146 ;
V_139 -> V_147 = V_148 |
V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 |
V_161 ;
F_57 ( & V_141 ) ;
V_139 -> V_162 = V_141 . V_163 - V_23 -> V_164 ;
V_139 -> V_165 = F_58 ( V_166 - V_23 -> V_167 ) ;
V_139 -> V_168 = 0 ;
for ( V_144 = 0 ; V_144 < V_169 ; V_144 ++ ) {
V_139 -> V_168 += V_23 -> V_168 [ V_144 ] ;
V_142 += V_23 -> V_170 [ V_144 ] ;
}
V_139 -> V_170 = V_142 ;
V_139 -> V_171 = V_23 -> V_171 ;
V_139 -> V_172 = V_23 -> V_172 ;
V_139 -> V_173 = V_23 -> V_174 ;
V_139 -> V_175 = V_23 -> V_176 ;
V_139 -> V_177 = V_23 -> V_178 ;
V_139 -> V_179 = V_23 -> V_179 ;
if ( ( V_23 -> V_9 -> V_113 . V_5 & V_180 ) ||
( V_23 -> V_9 -> V_113 . V_5 & V_181 ) ) {
V_139 -> V_147 |= V_182 | V_183 ;
if ( ! V_9 -> V_184 -> V_185 ||
F_59 ( V_9 , V_12 , & V_23 -> V_23 , & V_139 -> signal ) )
V_139 -> signal = ( V_186 ) V_23 -> V_187 ;
V_139 -> V_188 = ( V_186 ) - F_60 ( & V_23 -> V_189 ) ;
}
if ( V_23 -> V_190 ) {
V_139 -> V_147 |= V_191 |
V_192 ;
V_139 -> V_190 = V_23 -> V_190 ;
for ( V_143 = 0 ; V_143 < F_61 ( V_139 -> V_193 ) ; V_143 ++ ) {
V_139 -> V_193 [ V_143 ] = V_23 -> V_194 [ V_143 ] ;
V_139 -> V_195 [ V_143 ] =
( V_186 ) - F_60 ( & V_23 -> V_195 [ V_143 ] ) ;
}
}
F_49 ( V_23 , & V_23 -> V_196 , & V_139 -> V_197 ) ;
F_55 ( V_23 , & V_139 -> V_198 ) ;
if ( F_26 ( & V_12 -> V_26 ) ) {
#ifdef F_31
V_139 -> V_147 |= V_199 |
V_200 |
V_201 |
V_202 |
V_203 |
V_204 ;
V_139 -> V_205 = V_23 -> V_205 ;
V_139 -> V_206 = V_23 -> V_206 ;
V_139 -> V_207 = V_23 -> V_207 ;
if ( F_29 ( V_23 , V_208 ) ) {
V_139 -> V_147 |= V_209 ;
V_139 -> V_210 = V_23 -> V_210 ;
}
V_139 -> V_211 = V_23 -> V_211 ;
V_139 -> V_212 = V_23 -> V_212 ;
V_139 -> V_213 = V_23 -> V_213 ;
#endif
}
V_139 -> V_214 . V_5 = 0 ;
if ( V_12 -> V_26 . V_215 . V_216 )
V_139 -> V_214 . V_5 |= V_217 ;
if ( V_12 -> V_26 . V_215 . V_218 )
V_139 -> V_214 . V_5 |= V_219 ;
if ( V_12 -> V_26 . V_215 . V_220 )
V_139 -> V_214 . V_5 |= V_221 ;
V_139 -> V_214 . V_222 = V_12 -> V_9 -> V_113 . V_54 . V_223 ;
V_139 -> V_214 . V_224 = V_12 -> V_26 . V_215 . V_225 ;
V_139 -> V_226 . V_227 = 0 ;
V_139 -> V_226 . V_27 = F_62 ( V_228 ) |
F_62 ( V_229 ) |
F_62 ( V_230 ) |
F_62 ( V_231 ) |
F_62 ( V_232 ) |
F_62 ( V_233 ) |
F_62 ( V_234 ) ;
if ( F_29 ( V_23 , V_235 ) )
V_139 -> V_226 . V_227 |= F_62 ( V_228 ) ;
if ( F_29 ( V_23 , V_236 ) )
V_139 -> V_226 . V_227 |= F_62 ( V_229 ) ;
if ( F_29 ( V_23 , V_237 ) )
V_139 -> V_226 . V_227 |= F_62 ( V_230 ) ;
if ( F_29 ( V_23 , V_64 ) )
V_139 -> V_226 . V_227 |= F_62 ( V_231 ) ;
if ( F_29 ( V_23 , V_238 ) )
V_139 -> V_226 . V_227 |= F_62 ( V_232 ) ;
if ( F_29 ( V_23 , V_57 ) )
V_139 -> V_226 . V_227 |= F_62 ( V_233 ) ;
if ( F_29 ( V_23 , V_239 ) )
V_139 -> V_226 . V_227 |= F_62 ( V_234 ) ;
}
static int F_63 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_240 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_241 = 0 ;
if ( V_240 == V_242 )
V_241 += V_243 ;
V_241 += F_64 ( V_12 , V_240 ) ;
if ( V_241 == 0 )
return - V_244 ;
return V_241 ;
}
static void F_65 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_245 * V_246 ,
T_4 * V_247 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_248 * V_249 ;
struct V_250 * V_251 ;
struct V_36 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_138 V_139 ;
struct V_252 V_253 ;
int V_143 , V_254 ;
#define F_66 7
memset ( V_247 , 0 , sizeof( T_4 ) * V_243 ) ;
#define F_67 ( V_23 ) \
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
F_25 ( & V_9 -> V_56 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_28 ( V_12 , V_12 -> V_15 . V_25 . V_255 ) ;
if ( ! ( V_23 && ! F_68 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_256;
V_139 . V_147 = 0 ;
F_56 ( V_23 , & V_139 ) ;
V_143 = 0 ;
F_67 ( V_23 ) ;
V_247 [ V_143 ++ ] = V_23 -> V_257 ;
if ( V_139 . V_147 & V_155 )
V_247 [ V_143 ] = 100000 *
F_69 ( & V_139 . V_197 ) ;
V_143 ++ ;
if ( V_139 . V_147 & V_156 )
V_247 [ V_143 ] = 100000 *
F_69 ( & V_139 . V_198 ) ;
V_143 ++ ;
if ( V_139 . V_147 & V_183 )
V_247 [ V_143 ] = ( T_3 ) V_139 . V_188 ;
V_143 ++ ;
} else {
F_70 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_139 . V_147 = 0 ;
F_56 ( V_23 , & V_139 ) ;
V_143 = 0 ;
F_67 ( V_23 ) ;
}
}
V_256:
V_143 = V_243 - F_66 ;
V_253 . V_147 = 0 ;
F_40 () ;
V_249 = F_41 ( V_12 -> V_26 . V_249 ) ;
if ( V_249 )
V_251 = V_249 -> V_258 . V_259 ;
else
V_251 = NULL ;
F_44 () ;
if ( V_251 ) {
V_254 = 0 ;
do {
V_253 . V_147 = 0 ;
if ( F_71 ( V_9 , V_254 , & V_253 ) != 0 ) {
V_253 . V_147 = 0 ;
break;
}
V_254 ++ ;
} while ( V_251 != V_253 . V_251 );
}
if ( V_253 . V_147 )
V_247 [ V_143 ++ ] = V_253 . V_251 -> V_260 ;
else
V_247 [ V_143 ++ ] = 0 ;
if ( V_253 . V_147 & V_261 )
V_247 [ V_143 ++ ] = ( T_3 ) V_253 . V_262 ;
else
V_247 [ V_143 ++ ] = - 1LL ;
if ( V_253 . V_147 & V_263 )
V_247 [ V_143 ++ ] = V_253 . V_264 ;
else
V_247 [ V_143 ++ ] = - 1LL ;
if ( V_253 . V_147 & V_265 )
V_247 [ V_143 ++ ] = V_253 . V_266 ;
else
V_247 [ V_143 ++ ] = - 1LL ;
if ( V_253 . V_147 & V_267 )
V_247 [ V_143 ++ ] = V_253 . V_268 ;
else
V_247 [ V_143 ++ ] = - 1LL ;
if ( V_253 . V_147 & V_269 )
V_247 [ V_143 ++ ] = V_253 . V_270 ;
else
V_247 [ V_143 ++ ] = - 1LL ;
if ( V_253 . V_147 & V_271 )
V_247 [ V_143 ++ ] = V_253 . V_272 ;
else
V_247 [ V_143 ++ ] = - 1LL ;
F_34 ( & V_9 -> V_56 ) ;
if ( F_68 ( V_143 != V_243 ) )
return;
F_72 ( V_12 , V_246 , & ( V_247 [ V_243 ] ) ) ;
}
static void F_73 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_240 , T_3 * V_247 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_273 = 0 ;
if ( V_240 == V_242 ) {
V_273 = sizeof( V_274 ) ;
memcpy ( V_247 , V_274 , V_273 ) ;
}
F_74 ( V_12 , V_240 , & ( V_247 [ V_273 ] ) ) ;
}
static int F_75 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_105 , T_3 * V_275 , struct V_138 * V_139 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_58 ;
F_25 ( & V_9 -> V_56 ) ;
V_23 = F_76 ( V_12 , V_105 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_275 , V_23 -> V_23 . V_276 , V_277 ) ;
F_56 ( V_23 , V_139 ) ;
}
F_34 ( & V_9 -> V_56 ) ;
return V_19 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_105 , struct V_252 * V_253 )
{
struct V_8 * V_9 = F_78 ( V_18 -> V_278 ) ;
return F_71 ( V_9 , V_105 , V_253 ) ;
}
static int F_79 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_275 , struct V_138 * V_139 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_58 ;
F_25 ( & V_9 -> V_56 ) ;
V_23 = F_28 ( V_12 , V_275 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_56 ( V_23 , V_139 ) ;
}
F_34 ( & V_9 -> V_56 ) ;
return V_19 ;
}
static int F_80 ( struct V_2 * V_2 ,
struct V_279 * V_280 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_81 ( & V_9 -> V_281 , V_280 ) )
return 0 ;
F_25 ( & V_9 -> V_282 ) ;
F_25 ( & V_9 -> V_283 ) ;
if ( V_9 -> V_284 ) {
V_12 = F_82 (
V_9 -> V_285 ,
F_83 ( & V_9 -> V_283 ) ) ;
if ( V_12 ) {
F_84 ( V_12 ) ;
V_19 = F_85 ( V_12 , V_280 ,
V_286 ) ;
}
} else if ( V_9 -> V_287 == V_9 -> V_288 ) {
V_9 -> V_289 = * V_280 ;
F_86 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_281 = * V_280 ;
F_34 ( & V_9 -> V_283 ) ;
F_34 ( & V_9 -> V_282 ) ;
return V_19 ;
}
static int F_87 ( struct V_11 * V_12 ,
const T_3 * V_290 , T_5 V_291 )
{
struct V_292 * V_293 , * V_294 ;
if ( ! V_290 || ! V_291 )
return 1 ;
V_294 = F_88 ( V_12 -> V_15 . V_295 . V_292 , V_12 ) ;
V_293 = F_89 ( sizeof( struct V_292 ) + V_291 , V_296 ) ;
if ( ! V_293 )
return - V_297 ;
V_293 -> V_298 = V_291 ;
memcpy ( V_293 -> V_247 , V_290 , V_291 ) ;
F_90 ( V_12 -> V_15 . V_295 . V_292 , V_293 ) ;
if ( V_294 )
F_91 ( V_294 , V_299 ) ;
return 0 ;
}
static int F_92 ( struct V_11 * V_12 ,
struct V_300 * V_7 )
{
struct V_301 * V_293 , * V_294 ;
int V_302 , V_303 ;
int V_304 , V_13 ;
T_1 V_305 = V_306 ;
V_294 = F_88 ( V_12 -> V_15 . V_295 . V_307 , V_12 ) ;
if ( ! V_7 -> V_308 && ! V_294 )
return - V_47 ;
if ( V_7 -> V_308 )
V_302 = V_7 -> V_309 ;
else
V_302 = V_294 -> V_309 ;
if ( V_7 -> V_310 || ! V_294 )
V_303 = V_7 -> V_311 ;
else
V_303 = V_294 -> V_311 ;
V_304 = sizeof( * V_293 ) + V_302 + V_303 ;
V_293 = F_89 ( V_304 , V_296 ) ;
if ( ! V_293 )
return - V_297 ;
V_293 -> V_308 = ( ( T_3 * ) V_293 ) + sizeof( * V_293 ) ;
V_293 -> V_310 = V_293 -> V_308 + V_302 ;
V_293 -> V_309 = V_302 ;
V_293 -> V_311 = V_303 ;
if ( V_7 -> V_308 )
memcpy ( V_293 -> V_308 , V_7 -> V_308 , V_302 ) ;
else
memcpy ( V_293 -> V_308 , V_294 -> V_308 , V_302 ) ;
if ( V_7 -> V_310 )
memcpy ( V_293 -> V_310 , V_7 -> V_310 , V_303 ) ;
else
if ( V_294 )
memcpy ( V_293 -> V_310 , V_294 -> V_310 , V_303 ) ;
V_13 = F_87 ( V_12 , V_7 -> V_292 ,
V_7 -> V_312 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_305 |= V_313 ;
F_90 ( V_12 -> V_15 . V_295 . V_307 , V_293 ) ;
if ( V_294 )
F_91 ( V_294 , V_299 ) ;
return V_305 ;
}
static int F_93 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_314 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_301 * V_294 ;
struct V_11 * V_22 ;
T_1 V_305 = V_315 |
V_316 |
V_306 |
V_317 |
V_318 ;
int V_13 ;
V_294 = F_88 ( V_12 -> V_15 . V_295 . V_307 , V_12 ) ;
if ( V_294 )
return - V_319 ;
V_12 -> V_320 = V_321 ;
V_12 -> V_322 = V_12 -> V_9 -> V_323 ;
F_25 ( & V_9 -> V_282 ) ;
V_12 -> V_324 = V_7 -> V_324 ;
V_13 = F_85 ( V_12 , & V_7 -> V_280 ,
V_325 ) ;
F_34 ( & V_9 -> V_282 ) ;
if ( V_13 )
return V_13 ;
F_94 ( V_12 , false ) ;
V_12 -> V_326 = V_7 -> V_327 . V_328 ;
V_12 -> V_329 = V_7 -> V_327 . V_329 ;
V_12 -> V_330 = F_95 ( V_12 -> V_9 ,
& V_7 -> V_327 ,
V_12 -> V_26 . type ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_326 =
V_7 -> V_327 . V_328 ;
V_22 -> V_329 =
V_7 -> V_327 . V_329 ;
V_22 -> V_330 =
F_95 ( V_12 -> V_9 ,
& V_7 -> V_327 ,
V_22 -> V_26 . type ) ;
}
V_12 -> V_26 . V_215 . V_225 = V_7 -> V_224 ;
V_12 -> V_26 . V_215 . V_222 = V_7 -> V_222 ;
V_12 -> V_26 . V_215 . V_331 = true ;
V_12 -> V_26 . V_215 . V_332 = V_7 -> V_332 ;
if ( V_7 -> V_332 )
memcpy ( V_12 -> V_26 . V_215 . V_333 , V_7 -> V_333 ,
V_7 -> V_332 ) ;
V_12 -> V_26 . V_215 . V_334 =
( V_7 -> V_334 != V_335 ) ;
memset ( & V_12 -> V_26 . V_215 . V_336 , 0 ,
sizeof( V_12 -> V_26 . V_215 . V_336 ) ) ;
V_12 -> V_26 . V_215 . V_336 . V_337 =
V_7 -> V_338 & V_339 ;
if ( V_7 -> V_340 )
V_12 -> V_26 . V_215 . V_336 . V_337 |=
V_341 ;
V_13 = F_92 ( V_12 , & V_7 -> V_307 ) ;
if ( V_13 < 0 ) {
F_84 ( V_12 ) ;
return V_13 ;
}
V_305 |= V_13 ;
V_13 = F_96 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_294 = F_88 ( V_12 -> V_15 . V_295 . V_307 , V_12 ) ;
if ( V_294 )
F_91 ( V_294 , V_299 ) ;
F_11 ( V_12 -> V_15 . V_295 . V_307 , NULL ) ;
F_84 ( V_12 ) ;
return V_13 ;
}
F_97 ( V_9 , V_12 ) ;
F_98 ( V_12 , V_305 ) ;
F_99 ( V_18 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_99 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_100 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_300 * V_7 )
{
struct V_11 * V_12 ;
struct V_301 * V_294 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_101 ( V_12 ) ;
if ( V_12 -> V_26 . V_342 )
return - V_30 ;
V_294 = F_88 ( V_12 -> V_15 . V_295 . V_307 , V_12 ) ;
if ( ! V_294 )
return - V_58 ;
V_13 = F_92 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_98 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_301 * V_343 ;
struct V_292 * V_344 ;
struct V_279 V_280 ;
F_101 ( V_12 ) ;
V_343 = F_88 ( V_12 -> V_15 . V_295 . V_307 , V_12 ) ;
if ( ! V_343 )
return - V_58 ;
V_344 = F_88 ( V_12 -> V_15 . V_295 . V_292 , V_12 ) ;
V_12 -> V_26 . V_342 = false ;
F_103 ( V_12 -> V_15 . V_295 . V_345 ) ;
V_12 -> V_15 . V_295 . V_345 = NULL ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_104 ( V_22 -> V_18 ) ;
F_104 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_295 . V_307 , NULL ) ;
F_11 ( V_12 -> V_15 . V_295 . V_292 , NULL ) ;
F_91 ( V_343 , V_299 ) ;
if ( V_344 )
F_91 ( V_344 , V_299 ) ;
V_12 -> V_15 . V_295 . V_346 = V_321 ;
F_105 ( V_12 , true ) ;
F_106 ( V_12 , true ) ;
V_12 -> V_26 . V_215 . V_331 = false ;
V_12 -> V_26 . V_215 . V_332 = 0 ;
F_107 ( V_347 , & V_12 -> V_348 ) ;
F_98 ( V_12 , V_316 ) ;
if ( V_12 -> V_10 . V_349 ) {
V_280 = V_12 -> V_26 . V_215 . V_280 ;
F_108 ( & V_12 -> V_350 ) ;
F_109 ( V_12 -> V_18 , & V_280 ,
V_351 ,
V_296 ) ;
}
F_110 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_352 -= F_111 ( & V_12 -> V_15 . V_295 . V_353 . V_354 ) ;
F_112 ( & V_12 -> V_15 . V_295 . V_353 . V_354 ) ;
F_94 ( V_12 , true ) ;
F_25 ( & V_9 -> V_282 ) ;
F_84 ( V_12 ) ;
F_34 ( & V_9 -> V_282 ) ;
return 0 ;
}
static void F_113 ( struct V_36 * V_23 )
{
struct V_355 * V_356 ;
struct V_357 * V_358 ;
V_358 = F_114 ( sizeof( * V_356 ) ) ;
if ( ! V_358 )
return;
V_356 = (struct V_355 * ) F_115 ( V_358 , sizeof( * V_356 ) ) ;
F_116 ( V_356 -> V_359 ) ;
memcpy ( V_356 -> V_360 , V_23 -> V_23 . V_276 , V_277 ) ;
V_356 -> V_298 = F_117 ( 6 ) ;
V_356 -> V_361 = 0 ;
V_356 -> V_362 = 0x01 ;
V_356 -> V_363 = 0xaf ;
V_356 -> V_364 [ 0 ] = 0x81 ;
V_356 -> V_364 [ 1 ] = 1 ;
V_356 -> V_364 [ 2 ] = 0 ;
V_358 -> V_18 = V_23 -> V_12 -> V_18 ;
V_358 -> V_365 = F_118 ( V_358 , V_23 -> V_12 -> V_18 ) ;
memset ( V_358 -> V_366 , 0 , sizeof( V_358 -> V_366 ) ) ;
F_119 ( V_358 ) ;
}
static int F_120 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
T_1 V_27 , T_1 V_227 )
{
int V_19 ;
if ( V_27 & F_62 ( V_232 ) &&
V_227 & F_62 ( V_232 ) &&
! F_29 ( V_23 , V_238 ) ) {
V_19 = F_121 ( V_23 , V_367 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_233 ) &&
V_227 & F_62 ( V_233 ) &&
! F_29 ( V_23 , V_57 ) ) {
V_19 = F_121 ( V_23 , V_368 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_228 ) ) {
if ( V_227 & F_62 ( V_228 ) )
V_19 = F_121 ( V_23 , V_369 ) ;
else if ( F_29 ( V_23 , V_235 ) )
V_19 = F_121 ( V_23 , V_368 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_233 ) &&
! ( V_227 & F_62 ( V_233 ) ) &&
F_29 ( V_23 , V_57 ) ) {
V_19 = F_121 ( V_23 , V_367 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_232 ) &&
! ( V_227 & F_62 ( V_232 ) ) &&
F_29 ( V_23 , V_238 ) ) {
V_19 = F_121 ( V_23 , V_370 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_122 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
struct V_371 * V_7 )
{
int V_19 = 0 ;
struct V_109 * V_110 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_372 V_373 = F_53 ( V_12 ) ;
T_1 V_27 , V_227 ;
V_110 = V_9 -> V_113 . V_2 -> V_114 [ V_373 ] ;
V_27 = V_7 -> V_374 ;
V_227 = V_7 -> V_375 ;
if ( F_26 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_62 ( V_232 ) )
V_27 |= F_62 ( V_233 ) ;
if ( V_227 & F_62 ( V_232 ) )
V_227 |= F_62 ( V_233 ) ;
} else if ( F_29 ( V_23 , V_239 ) ) {
if ( V_227 & F_62 ( V_228 ) ) {
V_227 |= F_62 ( V_232 ) |
F_62 ( V_233 ) ;
V_27 |= F_62 ( V_232 ) |
F_62 ( V_233 ) ;
}
}
V_19 = F_120 ( V_9 , V_23 , V_27 , V_227 ) ;
if ( V_19 )
return V_19 ;
if ( V_27 & F_62 ( V_229 ) ) {
if ( V_227 & F_62 ( V_229 ) )
F_123 ( V_23 , V_236 ) ;
else
F_124 ( V_23 , V_236 ) ;
}
if ( V_27 & F_62 ( V_230 ) ) {
if ( V_227 & F_62 ( V_230 ) ) {
F_123 ( V_23 , V_237 ) ;
V_23 -> V_23 . V_376 = true ;
} else {
F_124 ( V_23 , V_237 ) ;
V_23 -> V_23 . V_376 = false ;
}
}
if ( V_27 & F_62 ( V_231 ) ) {
if ( V_227 & F_62 ( V_231 ) )
F_123 ( V_23 , V_64 ) ;
else
F_124 ( V_23 , V_64 ) ;
}
if ( V_27 & F_62 ( V_234 ) ) {
if ( V_227 & F_62 ( V_234 ) )
F_123 ( V_23 , V_239 ) ;
else
F_124 ( V_23 , V_239 ) ;
}
if ( V_7 -> V_377 & V_378 ) {
V_23 -> V_23 . V_379 = V_7 -> V_379 ;
V_23 -> V_23 . V_380 = V_7 -> V_380 ;
}
if ( V_7 -> V_381 )
V_23 -> V_23 . V_381 = V_7 -> V_381 ;
if ( V_7 -> V_382 >= 0 )
V_23 -> V_382 = V_7 -> V_382 ;
if ( V_7 -> V_383 ) {
F_125 ( & V_12 -> V_26 . V_215 . V_280 ,
V_110 , V_7 -> V_383 ,
V_7 -> V_384 ,
& V_23 -> V_23 . V_385 [ V_373 ] ) ;
}
if ( V_7 -> V_386 )
F_126 ( V_12 , V_110 ,
V_7 -> V_386 , V_23 ) ;
if ( V_7 -> V_387 )
F_127 ( V_12 , V_110 ,
V_7 -> V_387 , V_23 ) ;
if ( V_7 -> V_388 ) {
F_128 ( V_12 , V_23 ,
V_7 -> V_389 ,
V_373 , false ) ;
}
if ( F_26 ( & V_12 -> V_26 ) ) {
#ifdef F_31
T_1 V_305 = 0 ;
if ( V_7 -> V_377 & V_390 ) {
switch ( V_7 -> V_207 ) {
case V_391 :
if ( V_23 -> V_207 != V_391 )
V_305 = F_129 (
V_12 ) ;
V_23 -> V_207 = V_7 -> V_207 ;
F_130 ( V_23 ) ;
V_305 |= F_131 ( V_23 ,
V_12 -> V_15 . V_67 . V_392 . V_393 ) ;
break;
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
if ( V_23 -> V_207 == V_391 )
V_305 = F_132 (
V_12 ) ;
V_23 -> V_207 = V_7 -> V_207 ;
F_130 ( V_23 ) ;
V_305 |= F_131 ( V_23 ,
V_400 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_401 ) {
case V_402 :
break;
case V_403 :
V_305 |= F_133 ( V_23 ) ;
break;
case V_404 :
V_305 |= F_134 ( V_23 ) ;
break;
}
if ( V_7 -> V_211 )
V_305 |=
F_131 ( V_23 ,
V_7 -> V_211 ) ;
F_135 ( V_12 , V_305 ) ;
#endif
}
return 0 ;
}
static int F_136 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_275 , struct V_371 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_405 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_63 )
return - V_47 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_137 ( V_275 , V_12 -> V_26 . V_276 ) )
return - V_47 ;
if ( F_138 ( V_275 ) )
return - V_47 ;
V_23 = F_139 ( V_12 , V_275 , V_296 ) ;
if ( ! V_23 )
return - V_297 ;
if ( ! ( V_7 -> V_375 & F_62 ( V_234 ) ) ) {
F_140 ( V_23 , V_367 ) ;
F_140 ( V_23 , V_368 ) ;
}
V_13 = F_122 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_141 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_29 ( V_23 , V_239 ) )
F_142 ( V_23 ) ;
V_405 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_63 ;
V_13 = F_143 ( V_23 ) ;
if ( V_13 ) {
F_44 () ;
return V_13 ;
}
if ( V_405 )
F_113 ( V_23 ) ;
F_44 () ;
return 0 ;
}
static int F_144 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_275 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_275 )
return F_145 ( V_12 , V_275 ) ;
F_146 ( V_12 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_3 * V_275 ,
struct V_371 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_406 ;
enum V_407 V_408 ;
int V_13 ;
F_25 ( & V_9 -> V_56 ) ;
V_23 = F_28 ( V_12 , V_275 ) ;
if ( ! V_23 ) {
V_13 = - V_58 ;
goto V_409;
}
switch ( V_12 -> V_26 . type ) {
case V_66 :
if ( V_12 -> V_15 . V_67 . V_410 )
V_408 = V_411 ;
else
V_408 = V_412 ;
break;
case V_65 :
V_408 = V_413 ;
break;
case V_24 :
if ( ! F_29 ( V_23 , V_239 ) ) {
V_408 = V_414 ;
break;
}
if ( F_29 ( V_23 , V_235 ) )
V_408 = V_415 ;
else
V_408 = V_416 ;
break;
case V_63 :
case V_20 :
V_408 = V_417 ;
break;
default:
V_13 = - V_244 ;
goto V_409;
}
V_13 = F_148 ( V_2 , V_7 , V_408 ) ;
if ( V_13 )
goto V_409;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_418 = false ;
bool V_419 = false ;
V_406 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_278 -> V_21 ) {
if ( V_406 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_409;
}
F_90 ( V_406 -> V_15 . V_22 . V_23 , V_23 ) ;
V_419 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_90 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_418 = true ;
}
V_23 -> V_12 = V_406 ;
if ( V_23 -> V_257 == V_369 &&
V_418 != V_419 ) {
if ( V_419 )
F_149 ( & V_23 -> V_12 -> V_420 -> V_421 ) ;
else
F_150 ( & V_23 -> V_12 -> V_420 -> V_421 ) ;
}
F_113 ( V_23 ) ;
}
V_13 = F_122 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_409;
if ( F_29 ( V_23 , V_239 ) &&
F_29 ( V_23 , V_235 ) )
F_142 ( V_23 ) ;
F_34 ( & V_9 -> V_56 ) ;
if ( ( V_12 -> V_26 . type == V_63 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_422 != V_23 -> V_12 -> V_420 -> V_423 &&
F_29 ( V_23 , V_235 ) &&
F_151 ( V_23 ) != 1 ) {
F_152 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_276 ) ;
F_153 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_420 -> V_423 ,
V_23 -> V_23 . V_276 ,
V_23 -> V_12 -> V_26 . V_215 . V_255 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_374 & F_62 ( V_228 ) ) {
F_154 ( V_9 , - 1 ) ;
F_155 ( V_12 ) ;
}
return 0 ;
V_409:
F_34 ( & V_9 -> V_56 ) ;
return V_13 ;
}
static int F_156 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_424 , T_3 * V_425 )
{
struct V_11 * V_12 ;
struct V_426 * V_427 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_23 = F_27 ( V_12 , V_425 ) ;
if ( ! V_23 ) {
F_44 () ;
return - V_58 ;
}
V_427 = F_157 ( V_12 , V_424 ) ;
if ( F_21 ( V_427 ) ) {
F_44 () ;
return F_24 ( V_427 ) ;
}
F_158 ( V_427 , V_23 ) ;
F_44 () ;
return 0 ;
}
static int F_159 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_424 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_424 )
return F_160 ( V_12 , V_424 ) ;
F_161 ( V_12 ) ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_424 , T_3 * V_425 )
{
struct V_11 * V_12 ;
struct V_426 * V_427 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_23 = F_27 ( V_12 , V_425 ) ;
if ( ! V_23 ) {
F_44 () ;
return - V_58 ;
}
V_427 = F_163 ( V_12 , V_424 ) ;
if ( ! V_427 ) {
F_44 () ;
return - V_58 ;
}
F_158 ( V_427 , V_23 ) ;
F_44 () ;
return 0 ;
}
static void F_164 ( struct V_426 * V_427 , T_3 * V_425 ,
struct V_428 * V_429 )
{
struct V_36 * V_430 = F_41 ( V_427 -> V_425 ) ;
if ( V_430 )
memcpy ( V_425 , V_430 -> V_23 . V_276 , V_277 ) ;
else
memset ( V_425 , 0 , V_277 ) ;
memset ( V_429 , 0 , sizeof( * V_429 ) ) ;
V_429 -> V_145 = V_431 ;
V_429 -> V_147 = V_432 |
V_433 |
V_434 |
V_435 |
V_436 |
V_437 |
V_438 ;
V_429 -> V_439 = V_427 -> V_440 . V_441 ;
V_429 -> V_442 = V_427 -> V_442 ;
V_429 -> V_443 = V_427 -> V_443 ;
if ( F_165 ( V_166 , V_427 -> V_444 ) )
V_429 -> V_445 = F_58 ( V_427 -> V_444 - V_166 ) ;
V_429 -> V_446 =
F_58 ( V_427 -> V_446 ) ;
V_429 -> V_447 = V_427 -> V_447 ;
if ( V_427 -> V_5 & V_448 )
V_429 -> V_5 |= V_449 ;
if ( V_427 -> V_5 & V_450 )
V_429 -> V_5 |= V_451 ;
if ( V_427 -> V_5 & V_452 )
V_429 -> V_5 |= V_453 ;
if ( V_427 -> V_5 & V_454 )
V_429 -> V_5 |= V_455 ;
if ( V_427 -> V_5 & V_456 )
V_429 -> V_5 |= V_457 ;
}
static int F_166 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_424 , T_3 * V_425 , struct V_428 * V_429 )
{
struct V_11 * V_12 ;
struct V_426 * V_427 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_427 = F_163 ( V_12 , V_424 ) ;
if ( ! V_427 ) {
F_44 () ;
return - V_58 ;
}
memcpy ( V_424 , V_427 -> V_424 , V_277 ) ;
F_164 ( V_427 , V_425 , V_429 ) ;
F_44 () ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_105 , T_3 * V_424 , T_3 * V_425 ,
struct V_428 * V_429 )
{
struct V_11 * V_12 ;
struct V_426 * V_427 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_427 = F_168 ( V_12 , V_105 ) ;
if ( ! V_427 ) {
F_44 () ;
return - V_58 ;
}
memcpy ( V_424 , V_427 -> V_424 , V_277 ) ;
F_164 ( V_427 , V_425 , V_429 ) ;
F_44 () ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_458 * V_54 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_54 , & ( V_12 -> V_15 . V_67 . V_392 ) , sizeof( struct V_458 ) ) ;
return 0 ;
}
static inline bool F_170 ( enum V_459 V_460 , T_1 V_27 )
{
return ( V_27 >> ( V_460 - 1 ) ) & 0x1 ;
}
static int F_171 ( struct V_461 * V_462 ,
const struct V_463 * V_464 )
{
T_3 * V_465 ;
const T_3 * V_466 ;
struct V_11 * V_12 = F_172 ( V_462 ,
struct V_11 , V_15 . V_67 ) ;
V_465 = NULL ;
V_466 = V_462 -> V_467 ;
if ( V_464 -> V_468 ) {
V_465 = F_173 ( V_464 -> V_467 , V_464 -> V_468 ,
V_296 ) ;
if ( ! V_465 )
return - V_297 ;
}
V_462 -> V_468 = V_464 -> V_468 ;
V_462 -> V_467 = V_465 ;
F_103 ( V_466 ) ;
V_462 -> V_469 = V_464 -> V_469 ;
memcpy ( V_462 -> V_470 , V_464 -> V_470 , V_462 -> V_469 ) ;
V_462 -> V_471 = V_464 -> V_472 ;
V_462 -> V_473 = V_464 -> V_474 ;
V_462 -> V_475 = V_464 -> V_476 ;
V_462 -> V_410 = V_464 -> V_410 ;
V_462 -> V_477 = V_464 -> V_478 ;
V_462 -> V_68 = V_69 ;
if ( V_464 -> V_479 )
V_462 -> V_68 |= V_480 ;
if ( V_464 -> V_481 )
V_462 -> V_68 |= V_482 ;
memcpy ( V_12 -> V_26 . V_215 . V_483 , V_464 -> V_483 ,
sizeof( V_464 -> V_483 ) ) ;
V_12 -> V_26 . V_215 . V_484 = V_464 -> V_484 ;
V_12 -> V_26 . V_215 . V_225 = V_464 -> V_224 ;
V_12 -> V_26 . V_215 . V_222 = V_464 -> V_222 ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_458 * V_485 )
{
struct V_458 * V_54 ;
struct V_11 * V_12 ;
struct V_461 * V_462 ;
V_12 = F_9 ( V_18 ) ;
V_462 = & V_12 -> V_15 . V_67 ;
V_54 = & ( V_12 -> V_15 . V_67 . V_392 ) ;
if ( F_170 ( V_486 , V_27 ) )
V_54 -> V_487 = V_485 -> V_487 ;
if ( F_170 ( V_488 , V_27 ) )
V_54 -> V_489 = V_485 -> V_489 ;
if ( F_170 ( V_490 , V_27 ) )
V_54 -> V_491 = V_485 -> V_491 ;
if ( F_170 ( V_492 , V_27 ) )
V_54 -> V_493 = V_485 -> V_493 ;
if ( F_170 ( V_494 , V_27 ) )
V_54 -> V_495 = V_485 -> V_495 ;
if ( F_170 ( V_496 , V_27 ) )
V_54 -> V_497 = V_485 -> V_497 ;
if ( F_170 ( V_498 , V_27 ) )
V_54 -> V_499 = V_485 -> V_499 ;
if ( F_170 ( V_500 , V_27 ) ) {
if ( V_462 -> V_410 )
return - V_30 ;
V_54 -> V_501 = V_485 -> V_501 ;
}
if ( F_170 ( V_502 , V_27 ) )
V_54 -> V_503 =
V_485 -> V_503 ;
if ( F_170 ( V_504 , V_27 ) )
V_54 -> V_505 =
V_485 -> V_505 ;
if ( F_170 ( V_506 , V_27 ) )
V_54 -> V_507 = V_485 -> V_507 ;
if ( F_170 ( V_508 , V_27 ) )
V_54 -> V_509 = V_485 -> V_509 ;
if ( F_170 ( V_510 , V_27 ) )
V_54 -> V_511 =
V_485 -> V_511 ;
if ( F_170 ( V_512 , V_27 ) )
V_54 -> V_513 =
V_485 -> V_513 ;
if ( F_170 ( V_514 , V_27 ) )
V_54 -> V_515 =
V_485 -> V_515 ;
if ( F_170 ( V_516 ,
V_27 ) )
V_54 -> V_517 =
V_485 -> V_517 ;
if ( F_170 ( V_518 , V_27 ) ) {
V_54 -> V_519 = V_485 -> V_519 ;
F_175 ( V_462 ) ;
}
if ( F_170 ( V_520 , V_27 ) ) {
if ( V_485 -> V_521 &&
! ( V_54 -> V_519 > V_522 ) ) {
V_54 -> V_519 = V_523 ;
F_175 ( V_462 ) ;
}
V_54 -> V_521 =
V_485 -> V_521 ;
}
if ( F_170 ( V_524 , V_27 ) )
V_54 -> V_525 =
V_485 -> V_525 ;
if ( F_170 ( V_526 , V_27 ) )
V_54 -> V_527 = V_485 -> V_527 ;
if ( F_170 ( V_528 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_113 . V_5 & V_180 ) )
return - V_529 ;
V_54 -> V_530 = V_485 -> V_530 ;
}
if ( F_170 ( V_531 , V_27 ) ) {
V_54 -> V_532 = V_485 -> V_532 ;
V_12 -> V_26 . V_215 . V_533 = V_485 -> V_532 ;
F_98 ( V_12 , V_534 ) ;
}
if ( F_170 ( V_535 , V_27 ) )
V_54 -> V_536 =
V_485 -> V_536 ;
if ( F_170 ( V_537 , V_27 ) )
V_54 -> V_538 =
V_485 -> V_538 ;
if ( F_170 ( V_539 , V_27 ) )
V_54 -> V_540 =
V_485 -> V_540 ;
if ( F_170 ( V_541 , V_27 ) ) {
V_54 -> V_393 = V_485 -> V_393 ;
F_176 ( V_12 ) ;
}
if ( F_170 ( V_542 , V_27 ) )
V_54 -> V_543 =
V_485 -> V_543 ;
if ( F_170 ( V_544 , V_27 ) )
V_54 -> V_545 = V_485 -> V_545 ;
F_135 ( V_12 , V_306 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_458 * V_54 ,
const struct V_463 * V_464 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_461 * V_462 = & V_12 -> V_15 . V_67 ;
int V_13 ;
memcpy ( & V_462 -> V_392 , V_54 , sizeof( struct V_458 ) ) ;
V_13 = F_171 ( V_462 , V_464 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_320 = V_321 ;
V_12 -> V_322 = V_12 -> V_9 -> V_323 ;
F_25 ( & V_12 -> V_9 -> V_282 ) ;
V_13 = F_85 ( V_12 , & V_464 -> V_280 ,
V_325 ) ;
F_34 ( & V_12 -> V_9 -> V_282 ) ;
if ( V_13 )
return V_13 ;
return F_178 ( V_12 ) ;
}
static int F_179 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_180 ( V_12 ) ;
F_25 ( & V_12 -> V_9 -> V_282 ) ;
F_84 ( V_12 ) ;
F_34 ( & V_12 -> V_9 -> V_282 ) ;
return 0 ;
}
static int F_181 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_546 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_372 V_373 ;
T_1 V_305 = 0 ;
if ( ! F_88 ( V_12 -> V_15 . V_295 . V_307 , V_12 ) )
return - V_58 ;
V_373 = F_53 ( V_12 ) ;
if ( V_7 -> V_216 >= 0 ) {
V_12 -> V_26 . V_215 . V_216 = V_7 -> V_216 ;
V_305 |= V_547 ;
}
if ( V_7 -> V_218 >= 0 ) {
V_12 -> V_26 . V_215 . V_218 =
V_7 -> V_218 ;
V_305 |= V_548 ;
}
if ( ! V_12 -> V_26 . V_215 . V_220 &&
V_373 == V_549 ) {
V_12 -> V_26 . V_215 . V_220 = true ;
V_305 |= V_550 ;
}
if ( V_7 -> V_551 >= 0 ) {
V_12 -> V_26 . V_215 . V_220 =
V_7 -> V_551 ;
V_305 |= V_550 ;
}
if ( V_7 -> V_484 ) {
F_125 ( & V_12 -> V_26 . V_215 . V_280 ,
V_2 -> V_114 [ V_373 ] ,
V_7 -> V_484 ,
V_7 -> V_552 ,
& V_12 -> V_26 . V_215 . V_484 ) ;
V_305 |= V_553 ;
}
if ( V_7 -> V_554 >= 0 ) {
if ( V_7 -> V_554 )
V_12 -> V_5 |= V_555 ;
else
V_12 -> V_5 &= ~ V_555 ;
}
if ( V_7 -> V_532 >= 0 ) {
V_12 -> V_26 . V_215 . V_533 =
( T_2 ) V_7 -> V_532 ;
V_305 |= V_534 ;
}
if ( V_7 -> V_338 >= 0 ) {
V_12 -> V_26 . V_215 . V_336 . V_337 &=
~ V_339 ;
V_12 -> V_26 . V_215 . V_336 . V_337 |=
V_7 -> V_338 & V_339 ;
V_305 |= V_318 ;
}
if ( V_7 -> V_340 > 0 ) {
V_12 -> V_26 . V_215 . V_336 . V_337 |=
V_341 ;
V_305 |= V_318 ;
} else if ( V_7 -> V_340 == 0 ) {
V_12 -> V_26 . V_215 . V_336 . V_337 &=
~ V_341 ;
V_305 |= V_318 ;
}
F_98 ( V_12 , V_305 ) ;
return 0 ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_556 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_557 V_558 ;
if ( ! V_9 -> V_184 -> V_559 )
return - V_244 ;
if ( V_9 -> V_113 . V_560 < V_169 )
return - V_244 ;
memset ( & V_558 , 0 , sizeof( V_558 ) ) ;
V_558 . V_561 = V_7 -> V_561 ;
V_558 . V_562 = V_7 -> V_563 ;
V_558 . V_564 = V_7 -> V_565 ;
V_558 . V_566 = V_7 -> V_566 ;
V_558 . V_567 = false ;
V_12 -> V_568 [ V_7 -> V_144 ] = V_558 ;
if ( F_183 ( V_9 , V_12 , V_7 -> V_144 , & V_558 ) ) {
F_184 ( V_9 -> V_113 . V_2 ,
L_2 ,
V_7 -> V_144 ) ;
return - V_47 ;
}
F_98 ( V_12 , V_569 ) ;
return 0 ;
}
static int F_185 ( struct V_2 * V_2 ,
struct V_570 * V_571 )
{
return F_186 ( F_2 ( V_2 ) , V_571 ) ;
}
static int F_187 ( struct V_2 * V_2 )
{
return F_188 ( F_2 ( V_2 ) ) ;
}
static int F_189 ( struct V_2 * V_2 ,
struct V_572 * V_573 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_573 -> V_10 ) ;
switch ( F_190 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_65 :
case V_66 :
case V_74 :
case V_71 :
break;
case V_75 :
if ( V_12 -> V_9 -> V_184 -> V_574 )
break;
case V_63 :
if ( V_12 -> V_15 . V_295 . V_307 &&
( ! ( V_2 -> V_575 & V_576 ) ||
! ( V_573 -> V_5 & V_577 ) ) )
return - V_244 ;
break;
default:
return - V_244 ;
}
return F_191 ( V_12 , V_573 ) ;
}
static int
F_192 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_578 * V_573 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_184 -> V_579 )
return - V_244 ;
return F_193 ( V_12 , V_573 ) ;
}
static int
F_194 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_184 -> V_580 )
return - V_244 ;
return F_195 ( V_12 ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_581 * V_573 )
{
return F_197 ( F_9 ( V_18 ) , V_573 ) ;
}
static int F_198 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_582 * V_573 )
{
return F_199 ( F_9 ( V_18 ) , V_573 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_583 * V_573 )
{
return F_201 ( F_9 ( V_18 ) , V_573 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_584 * V_573 )
{
return F_203 ( F_9 ( V_18 ) , V_573 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_585 * V_7 )
{
return F_205 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_207 ( F_9 ( V_18 ) ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_99 [ V_586 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_215 . V_483 , V_99 ,
sizeof( int ) * V_586 ) ;
return 0 ;
}
static int F_209 ( struct V_2 * V_2 , T_1 V_305 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_305 & V_587 ) {
V_13 = F_210 ( V_9 , V_2 -> V_588 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_305 & V_589 ) {
V_13 = F_211 ( V_9 , V_2 -> V_590 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_305 & V_591 ) {
V_13 = F_212 ( V_9 , V_2 -> V_592 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_305 & V_593 ) {
if ( V_2 -> V_594 > V_595 )
return - V_47 ;
V_9 -> V_113 . V_54 . V_596 = V_2 -> V_594 ;
}
if ( V_305 & V_597 ) {
if ( V_2 -> V_598 > V_595 )
return - V_47 ;
V_9 -> V_113 . V_54 . V_599 = V_2 -> V_598 ;
}
if ( V_305 &
( V_593 | V_597 ) )
F_86 ( V_9 , V_600 ) ;
return 0 ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_601 type , int V_602 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_603 :
V_12 -> V_604 = V_605 ;
break;
case V_606 :
case V_607 :
if ( V_602 < 0 || ( V_602 % 100 ) )
return - V_244 ;
V_12 -> V_604 = F_214 ( V_602 ) ;
break;
}
F_215 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_603 :
V_9 -> V_604 = V_605 ;
break;
case V_606 :
case V_607 :
if ( V_602 < 0 || ( V_602 % 100 ) )
return - V_244 ;
V_9 -> V_604 = F_214 ( V_602 ) ;
break;
}
F_25 ( & V_9 -> V_283 ) ;
F_70 (sdata, &local->interfaces, list)
V_12 -> V_604 = V_9 -> V_604 ;
F_70 (sdata, &local->interfaces, list)
F_215 ( V_12 ) ;
F_34 ( & V_9 -> V_283 ) ;
return 0 ;
}
static int F_216 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_608 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_284 )
* V_608 = V_9 -> V_113 . V_54 . V_609 ;
else
* V_608 = V_12 -> V_26 . V_215 . V_610 ;
return 0 ;
}
static int F_217 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_276 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_611 . V_612 , V_276 , V_277 ) ;
return 0 ;
}
static void F_218 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_219 ( V_9 ) ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_247 , int V_298 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_613 * V_26 = NULL ;
if ( ! V_9 -> V_184 -> V_614 )
return - V_244 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_615 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_184 -> V_614 ( & V_9 -> V_113 , V_26 , V_247 , V_298 ) ;
}
static int F_221 ( struct V_2 * V_2 ,
struct V_357 * V_358 ,
struct V_616 * V_366 ,
void * V_247 , int V_298 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_184 -> V_617 )
return - V_244 ;
return V_9 -> V_184 -> V_617 ( & V_9 -> V_113 , V_358 , V_366 , V_247 , V_298 ) ;
}
int F_222 ( struct V_11 * V_12 ,
enum V_618 V_320 )
{
struct V_36 * V_23 ;
enum V_618 V_619 ;
int V_143 ;
if ( F_32 ( V_12 -> V_26 . type != V_63 ) )
return - V_47 ;
if ( V_12 -> V_26 . V_215 . V_280 . V_620 == V_621 )
return 0 ;
V_619 = V_12 -> V_15 . V_295 . V_423 ;
V_12 -> V_15 . V_295 . V_423 = V_320 ;
if ( V_619 == V_320 ||
V_320 == V_622 )
return 0 ;
if ( ! F_223 ( & V_12 -> V_15 . V_295 . V_421 ) ) {
V_12 -> V_320 = V_320 ;
F_224 ( & V_12 -> V_9 -> V_113 , & V_12 -> V_623 ) ;
return 0 ;
}
F_152 ( V_12 ,
L_3 ,
V_320 , F_223 ( & V_12 -> V_15 . V_295 . V_421 ) ) ;
F_25 ( & V_12 -> V_9 -> V_56 ) ;
for ( V_143 = 0 ; V_143 < V_624 ; V_143 ++ ) {
for ( V_23 = F_82 ( V_12 -> V_9 -> V_625 [ V_143 ] ,
F_83 ( & V_12 -> V_9 -> V_56 ) ) ;
V_23 ;
V_23 = F_82 ( V_23 -> V_626 ,
F_83 ( & V_12 -> V_9 -> V_56 ) ) ) {
if ( V_23 -> V_12 -> V_420 != & V_12 -> V_15 . V_295 )
continue;
if ( F_151 ( V_23 ) == 1 )
continue;
if ( F_29 ( V_23 , V_627 ) &&
! F_225 ( V_23 -> V_422 ,
V_320 ) ) {
F_152 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_276 ) ;
continue;
}
if ( ! F_29 ( V_23 , V_235 ) )
continue;
F_152 ( V_12 , L_5 , V_23 -> V_23 . V_276 ) ;
F_153 ( V_12 , V_320 ,
V_23 -> V_23 . V_276 ,
V_12 -> V_26 . V_215 . V_255 ) ;
}
}
F_34 ( & V_12 -> V_9 -> V_56 ) ;
V_12 -> V_320 = V_320 ;
F_224 ( & V_12 -> V_9 -> V_113 , & V_12 -> V_623 ) ;
return 0 ;
}
int F_226 ( struct V_11 * V_12 ,
enum V_618 V_320 )
{
const T_3 * V_295 ;
enum V_618 V_619 ;
int V_13 ;
F_227 ( & V_12 -> V_10 . V_282 ) ;
if ( F_32 ( V_12 -> V_26 . type != V_24 ) )
return - V_47 ;
V_619 = V_12 -> V_15 . V_25 . V_423 ;
V_12 -> V_15 . V_25 . V_423 = V_320 ;
if ( V_619 == V_320 &&
V_320 != V_622 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_628 ||
V_12 -> V_26 . V_215 . V_280 . V_620 == V_621 )
return 0 ;
V_295 = V_12 -> V_15 . V_25 . V_628 -> V_255 ;
if ( V_320 == V_622 ) {
if ( V_12 -> V_15 . V_25 . V_629 )
V_320 = V_630 ;
else
V_320 = V_321 ;
}
V_13 = F_153 ( V_12 , V_320 ,
V_295 , V_295 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_423 = V_619 ;
return V_13 ;
}
static int F_228 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_631 , int V_632 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_278 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_244 ;
if ( ! ( V_9 -> V_113 . V_5 & V_633 ) )
return - V_244 ;
if ( V_631 == V_12 -> V_15 . V_25 . V_629 &&
V_632 == V_9 -> V_634 )
return 0 ;
V_12 -> V_15 . V_25 . V_629 = V_631 ;
V_9 -> V_634 = V_632 ;
F_229 ( V_12 ) ;
F_226 ( V_12 , V_12 -> V_15 . V_25 . V_423 ) ;
F_230 ( V_12 ) ;
if ( V_9 -> V_113 . V_5 & V_635 )
F_86 ( V_9 , V_636 ) ;
F_154 ( V_9 , - 1 ) ;
F_155 ( V_12 ) ;
return 0 ;
}
static int F_231 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_637 , T_1 V_638 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_613 * V_26 = & V_12 -> V_26 ;
struct V_639 * V_215 = & V_26 -> V_215 ;
if ( V_637 == V_215 -> V_640 &&
V_638 == V_215 -> V_641 )
return 0 ;
V_215 -> V_640 = V_637 ;
V_215 -> V_641 = V_638 ;
if ( V_12 -> V_15 . V_25 . V_628 &&
V_12 -> V_26 . V_642 & V_643 )
F_98 ( V_12 , V_644 ) ;
return 0 ;
}
static int F_232 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_276 ,
const struct V_645 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_278 ) ;
int V_143 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_41 ;
if ( V_9 -> V_113 . V_5 & V_646 ) {
V_19 = F_233 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_143 = 0 ; V_143 < V_586 ; V_143 ++ ) {
struct V_109 * V_110 = V_2 -> V_114 [ V_143 ] ;
int V_647 ;
V_12 -> V_648 [ V_143 ] = V_27 -> V_363 [ V_143 ] . V_117 ;
memcpy ( V_12 -> V_649 [ V_143 ] , V_27 -> V_363 [ V_143 ] . V_650 ,
sizeof( V_27 -> V_363 [ V_143 ] . V_650 ) ) ;
V_12 -> V_651 [ V_143 ] = false ;
if ( ! V_110 )
continue;
for ( V_647 = 0 ; V_647 < V_652 ; V_647 ++ )
if ( ~ V_12 -> V_649 [ V_143 ] [ V_647 ] ) {
V_12 -> V_651 [ V_143 ] = true ;
break;
}
}
return 0 ;
}
static int F_234 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_250 * V_251 ,
unsigned int V_653 , T_4 * V_81 ,
struct V_357 * V_654 ,
enum V_655 type )
{
struct V_656 * V_657 , * V_658 ;
bool V_659 = false ;
int V_19 ;
F_227 ( & V_9 -> V_282 ) ;
if ( V_9 -> V_284 && ! V_9 -> V_184 -> V_660 )
return - V_244 ;
V_657 = F_89 ( sizeof( * V_657 ) , V_296 ) ;
if ( ! V_657 )
return - V_297 ;
if ( ! V_653 )
V_653 = 10 ;
V_657 -> V_259 = V_251 ;
V_657 -> V_653 = V_653 ;
V_657 -> V_661 = V_653 ;
V_657 -> V_662 = V_654 ;
V_657 -> type = type ;
V_657 -> V_663 = ( unsigned long ) V_654 ;
V_657 -> V_12 = V_12 ;
F_235 ( & V_657 -> V_664 , V_665 ) ;
F_236 ( & V_657 -> V_666 ) ;
if ( ! V_654 ) {
V_9 -> V_667 ++ ;
V_657 -> V_81 = V_9 -> V_667 ;
if ( F_68 ( V_657 -> V_81 == 0 ) ) {
V_657 -> V_81 = 1 ;
V_9 -> V_667 ++ ;
}
* V_81 = V_657 -> V_81 ;
} else {
* V_81 = ( unsigned long ) V_654 ;
}
if ( ! F_237 ( & V_9 -> V_668 ) ||
V_9 -> V_669 || V_9 -> V_670 )
goto V_671;
if ( ! V_9 -> V_184 -> V_660 ) {
F_238 ( & V_9 -> V_113 , & V_657 -> V_664 , 0 ) ;
goto V_672;
}
V_19 = F_239 ( V_9 , V_12 , V_251 , V_653 , type ) ;
if ( V_19 ) {
F_103 ( V_657 ) ;
return V_19 ;
}
V_657 -> V_673 = true ;
goto V_672;
V_671:
F_70 (tmp, &local->roc_list, list) {
if ( V_658 -> V_259 != V_251 || V_658 -> V_12 != V_12 )
continue;
if ( ! V_658 -> V_673 ) {
F_240 ( & V_657 -> V_674 , & V_658 -> V_666 ) ;
V_658 -> V_653 = F_241 ( V_658 -> V_653 , V_657 -> V_653 ) ;
V_658 -> type = F_241 ( V_658 -> type , V_657 -> type ) ;
V_659 = true ;
break;
}
if ( V_9 -> V_184 -> V_660 ) {
unsigned long V_647 = V_166 ;
if ( ! V_658 -> V_675 ) {
F_240 ( & V_657 -> V_674 , & V_658 -> V_666 ) ;
V_659 = true ;
break;
}
if ( F_165 ( V_647 + V_676 ,
V_658 -> V_677 +
F_242 ( V_658 -> V_653 ) ) ) {
int V_678 ;
F_243 ( V_657 ) ;
V_678 = V_657 -> V_653 -
F_58 ( V_658 -> V_677 +
F_242 (
V_658 -> V_653 ) -
V_647 ) ;
if ( V_678 > 0 ) {
F_244 ( & V_657 -> V_674 , & V_658 -> V_674 ) ;
} else {
F_240 ( & V_657 -> V_674 ,
& V_658 -> V_666 ) ;
}
V_659 = true ;
}
} else if ( F_245 ( & V_658 -> V_664 . V_679 ) ) {
unsigned long V_680 ;
F_240 ( & V_657 -> V_674 , & V_658 -> V_666 ) ;
V_659 = true ;
V_680 = V_166 + F_242 ( V_657 -> V_653 ) ;
if ( F_246 ( V_680 , V_658 -> V_664 . V_679 . V_681 ) )
F_247 ( & V_658 -> V_664 . V_679 , V_680 ) ;
else
F_248 ( & V_658 -> V_664 . V_679 ) ;
F_243 ( V_657 ) ;
}
break;
}
V_672:
if ( ! V_659 )
F_240 ( & V_657 -> V_674 , & V_9 -> V_668 ) ;
return 0 ;
}
static int F_249 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_250 * V_259 ,
unsigned int V_653 ,
T_4 * V_81 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_25 ( & V_9 -> V_282 ) ;
V_19 = F_234 ( V_9 , V_12 , V_259 ,
V_653 , V_81 , NULL ,
V_682 ) ;
F_34 ( & V_9 -> V_282 ) ;
return V_19 ;
}
static int F_250 ( struct V_8 * V_9 ,
T_4 V_81 , bool V_683 )
{
struct V_656 * V_657 , * V_658 , * V_684 = NULL ;
int V_19 ;
F_25 ( & V_9 -> V_282 ) ;
F_251 (roc, tmp, &local->roc_list, list) {
struct V_656 * V_685 , * V_686 ;
F_251 (dep, tmp2, &roc->dependents, list) {
if ( ! V_683 && V_685 -> V_81 != V_81 )
continue;
else if ( V_683 && V_685 -> V_663 != V_81 )
continue;
F_252 ( & V_685 -> V_674 ) ;
F_34 ( & V_9 -> V_282 ) ;
F_253 ( V_685 , true ) ;
return 0 ;
}
if ( ! V_683 && V_657 -> V_81 != V_81 )
continue;
else if ( V_683 && V_657 -> V_663 != V_81 )
continue;
V_684 = V_657 ;
break;
}
if ( ! V_684 ) {
F_34 ( & V_9 -> V_282 ) ;
return - V_58 ;
}
if ( V_9 -> V_184 -> V_660 ) {
if ( V_684 -> V_673 ) {
V_19 = F_254 ( V_9 ) ;
if ( F_32 ( V_19 ) ) {
F_34 ( & V_9 -> V_282 ) ;
return V_19 ;
}
}
F_252 ( & V_684 -> V_674 ) ;
if ( V_684 -> V_673 )
F_255 ( V_9 ) ;
F_34 ( & V_9 -> V_282 ) ;
F_253 ( V_684 , true ) ;
} else {
V_684 -> abort = true ;
F_238 ( & V_9 -> V_113 , & V_684 -> V_664 , 0 ) ;
F_34 ( & V_9 -> V_282 ) ;
F_256 ( & V_684 -> V_664 ) ;
F_68 ( ! V_684 -> V_687 ) ;
F_103 ( V_684 ) ;
}
return 0 ;
}
static int F_257 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_81 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_250 ( V_9 , V_81 , false ) ;
}
static int F_258 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_279 * V_280 ,
T_1 V_688 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_25 ( & V_9 -> V_282 ) ;
if ( ! F_237 ( & V_9 -> V_668 ) || V_9 -> V_669 ) {
V_13 = - V_30 ;
goto V_59;
}
V_12 -> V_320 = V_321 ;
V_12 -> V_322 = V_9 -> V_323 ;
V_12 -> V_324 = true ;
V_13 = F_85 ( V_12 , V_280 ,
V_325 ) ;
if ( V_13 )
goto V_59;
F_238 ( & V_12 -> V_9 -> V_113 ,
& V_12 -> V_350 ,
F_242 ( V_688 ) ) ;
V_59:
F_34 ( & V_9 -> V_282 ) ;
return V_13 ;
}
static struct V_300 *
F_259 ( struct V_300 * V_307 )
{
struct V_300 * V_689 ;
T_3 * V_690 ;
int V_298 ;
V_298 = V_307 -> V_309 + V_307 -> V_311 + V_307 -> V_691 +
V_307 -> V_692 + V_307 -> V_693 +
V_307 -> V_312 ;
V_689 = F_89 ( sizeof( * V_689 ) + V_298 , V_296 ) ;
if ( ! V_689 )
return NULL ;
V_690 = ( T_3 * ) ( V_689 + 1 ) ;
if ( V_307 -> V_309 ) {
V_689 -> V_309 = V_307 -> V_309 ;
V_689 -> V_308 = V_690 ;
memcpy ( V_690 , V_307 -> V_308 , V_307 -> V_309 ) ;
V_690 += V_307 -> V_309 ;
}
if ( V_307 -> V_311 ) {
V_689 -> V_311 = V_307 -> V_311 ;
V_689 -> V_310 = V_690 ;
memcpy ( V_690 , V_307 -> V_310 , V_307 -> V_311 ) ;
V_690 += V_307 -> V_311 ;
}
if ( V_307 -> V_691 ) {
V_689 -> V_691 = V_307 -> V_691 ;
V_689 -> V_694 = V_690 ;
memcpy ( V_690 , V_307 -> V_694 , V_307 -> V_691 ) ;
V_690 += V_307 -> V_691 ;
}
if ( V_307 -> V_692 ) {
V_689 -> V_692 = V_307 -> V_692 ;
V_689 -> V_695 = V_690 ;
memcpy ( V_690 , V_307 -> V_695 , V_307 -> V_692 ) ;
V_690 += V_307 -> V_692 ;
}
if ( V_307 -> V_693 ) {
V_689 -> V_693 = V_307 -> V_693 ;
V_689 -> V_696 = V_690 ;
memcpy ( V_690 , V_307 -> V_696 , V_307 -> V_693 ) ;
V_690 += V_307 -> V_693 ;
}
if ( V_307 -> V_312 ) {
V_689 -> V_312 = V_307 -> V_312 ;
V_307 -> V_292 = V_690 ;
memcpy ( V_690 , V_307 -> V_292 , V_307 -> V_312 ) ;
V_690 += V_307 -> V_312 ;
}
return V_689 ;
}
void F_260 ( struct V_613 * V_26 )
{
struct V_11 * V_12 = F_261 ( V_26 ) ;
F_224 ( & V_12 -> V_9 -> V_113 ,
& V_12 -> V_697 ) ;
}
static void F_262 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 , V_305 = 0 ;
F_101 ( V_12 ) ;
F_25 ( & V_9 -> V_282 ) ;
V_12 -> V_324 = V_12 -> V_698 ;
V_13 = F_263 ( V_12 , & V_305 ) ;
F_34 ( & V_9 -> V_282 ) ;
if ( F_68 ( V_13 < 0 ) )
return;
if ( ! V_9 -> V_284 ) {
V_9 -> V_289 = V_12 -> V_699 ;
F_86 ( V_9 , 0 ) ;
}
V_12 -> V_26 . V_342 = false ;
switch ( V_12 -> V_26 . type ) {
case V_63 :
V_13 = F_92 ( V_12 , V_12 -> V_15 . V_295 . V_345 ) ;
F_103 ( V_12 -> V_15 . V_295 . V_345 ) ;
V_12 -> V_15 . V_295 . V_345 = NULL ;
if ( V_13 < 0 )
return;
V_305 |= V_13 ;
break;
case V_65 :
V_13 = F_264 ( V_12 ) ;
if ( V_13 < 0 )
return;
V_305 |= V_13 ;
break;
#ifdef F_31
case V_66 :
V_13 = F_265 ( V_12 ) ;
if ( V_13 < 0 )
return;
V_305 |= V_13 ;
break;
#endif
default:
F_68 ( 1 ) ;
return;
}
F_98 ( V_12 , V_305 ) ;
F_266 ( & V_12 -> V_9 -> V_113 ,
V_700 ,
V_701 ) ;
F_267 ( V_12 -> V_18 , & V_12 -> V_699 ) ;
}
void F_268 ( struct V_702 * V_664 )
{
struct V_11 * V_12 =
F_172 ( V_664 , struct V_11 ,
V_697 ) ;
F_229 ( V_12 ) ;
if ( ! V_12 -> V_26 . V_342 )
goto V_703;
if ( ! F_12 ( V_12 ) )
goto V_703;
F_262 ( V_12 ) ;
V_703:
F_230 ( V_12 ) ;
}
static int F_269 ( struct V_11 * V_12 ,
struct V_704 * V_7 ,
T_1 * V_305 )
{
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_63 :
V_12 -> V_15 . V_295 . V_345 =
F_259 ( & V_7 -> V_705 ) ;
if ( ! V_12 -> V_15 . V_295 . V_345 )
return - V_297 ;
if ( V_7 -> V_706 <= 1 )
break;
V_12 -> V_707 =
V_7 -> V_708 ;
V_12 -> V_709 = V_7 -> V_710 ;
V_13 = F_92 ( V_12 , & V_7 -> V_711 ) ;
if ( V_13 < 0 ) {
F_103 ( V_12 -> V_15 . V_295 . V_345 ) ;
return V_13 ;
}
* V_305 |= V_13 ;
break;
case V_65 :
if ( ! V_12 -> V_26 . V_215 . V_712 )
return - V_47 ;
if ( V_7 -> V_280 . V_620 != V_12 -> V_15 . V_713 . V_280 . V_620 )
return - V_47 ;
switch ( V_7 -> V_280 . V_620 ) {
case V_714 :
if ( F_270 ( & V_7 -> V_280 ) !=
F_270 ( & V_12 -> V_15 . V_713 . V_280 ) )
return - V_47 ;
case V_715 :
case V_716 :
case V_621 :
case V_717 :
break;
default:
return - V_47 ;
}
if ( V_12 -> V_15 . V_713 . V_280 . V_259 -> V_373 !=
V_7 -> V_280 . V_259 -> V_373 )
return - V_47 ;
if ( V_7 -> V_706 > 1 ) {
V_13 = F_271 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_305 |= V_13 ;
}
F_272 ( V_12 , V_7 ) ;
break;
#ifdef F_31
case V_66 : {
struct V_461 * V_462 = & V_12 -> V_15 . V_67 ;
if ( V_7 -> V_280 . V_620 != V_12 -> V_26 . V_215 . V_280 . V_620 )
return - V_47 ;
if ( V_12 -> V_26 . V_215 . V_280 . V_259 -> V_373 !=
V_7 -> V_280 . V_259 -> V_373 )
return - V_47 ;
if ( V_462 -> V_718 == V_719 ) {
V_462 -> V_718 = V_720 ;
if ( ! V_462 -> V_721 )
V_462 -> V_721 = 1 ;
else
V_462 -> V_721 ++ ;
}
if ( V_7 -> V_706 > 1 ) {
V_13 = F_273 ( V_12 , V_7 ) ;
if ( V_13 < 0 ) {
V_462 -> V_718 = V_719 ;
return V_13 ;
}
* V_305 |= V_13 ;
}
if ( V_462 -> V_718 == V_720 )
F_272 ( V_12 , V_7 ) ;
break;
}
#endif
default:
return - V_244 ;
}
return 0 ;
}
int F_274 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_704 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_248 * V_249 ;
struct V_722 * V_723 ;
int V_13 , V_724 , V_305 = 0 ;
F_101 ( V_12 ) ;
if ( ! F_237 ( & V_9 -> V_668 ) || V_9 -> V_669 )
return - V_30 ;
if ( V_12 -> V_10 . V_349 )
return - V_30 ;
if ( F_81 ( & V_7 -> V_280 ,
& V_12 -> V_26 . V_215 . V_280 ) )
return - V_47 ;
F_40 () ;
V_249 = F_41 ( V_12 -> V_26 . V_249 ) ;
if ( ! V_249 ) {
F_44 () ;
return - V_30 ;
}
V_723 = F_172 ( V_249 , struct V_722 , V_54 ) ;
if ( V_723 -> V_725 > 1 ) {
F_44 () ;
return - V_30 ;
}
V_724 = 0 ;
F_275 (chanctx, &local->chanctx_list, list)
V_724 ++ ;
F_44 () ;
if ( V_724 > 1 )
return - V_30 ;
if ( V_12 -> V_26 . V_342 )
return - V_30 ;
V_13 = F_269 ( V_12 , V_7 , & V_305 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_698 = V_7 -> V_324 ;
if ( V_7 -> V_726 )
F_276 ( & V_9 -> V_113 ,
V_700 ,
V_701 ) ;
V_12 -> V_699 = V_7 -> V_280 ;
V_12 -> V_26 . V_342 = true ;
if ( V_305 ) {
F_98 ( V_12 , V_305 ) ;
F_277 ( V_12 , & V_7 -> V_280 ) ;
} else {
F_262 ( V_12 ) ;
}
return 0 ;
}
static int F_278 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_727 * V_7 ,
T_4 * V_81 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_357 * V_358 ;
struct V_36 * V_23 ;
const struct V_728 * V_729 = ( void * ) V_7 -> V_730 ;
bool V_731 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_7 -> V_732 )
V_5 = V_733 ;
else
V_5 = V_734 |
V_735 ;
if ( V_7 -> V_736 )
V_5 |= V_737 ;
switch ( V_12 -> V_26 . type ) {
case V_65 :
if ( ! V_12 -> V_26 . V_215 . V_712 )
V_731 = true ;
#ifdef F_31
case V_66 :
if ( F_26 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_67 . V_469 )
V_731 = true ;
#endif
case V_63 :
case V_20 :
case V_75 :
if ( V_12 -> V_26 . type != V_65 &&
! F_26 ( & V_12 -> V_26 ) &&
! F_279 ( V_12 -> V_420 -> V_307 ) )
V_731 = true ;
if ( ! F_280 ( V_729 -> V_738 ) ||
V_729 -> V_15 . V_739 . V_740 == V_741 ||
V_729 -> V_15 . V_739 . V_740 == V_742 ||
V_729 -> V_15 . V_739 . V_740 == V_743 )
break;
F_40 () ;
V_23 = F_27 ( V_12 , V_729 -> V_359 ) ;
F_44 () ;
if ( ! V_23 )
return - V_744 ;
break;
case V_24 :
case V_74 :
if ( ! V_12 -> V_15 . V_25 . V_628 )
V_731 = true ;
break;
case V_71 :
V_731 = true ;
break;
default:
return - V_244 ;
}
if ( V_731 && ! V_7 -> V_259 )
return - V_47 ;
F_25 ( & V_9 -> V_282 ) ;
if ( ! V_731 ) {
struct V_248 * V_249 ;
F_40 () ;
V_249 = F_41 ( V_12 -> V_26 . V_249 ) ;
if ( V_249 ) {
V_731 = V_7 -> V_259 &&
( V_7 -> V_259 !=
V_249 -> V_258 . V_259 ) ;
} else if ( ! V_7 -> V_259 ) {
V_19 = - V_47 ;
F_44 () ;
goto V_59;
} else {
V_731 = true ;
}
F_44 () ;
}
if ( V_731 && ! V_7 -> V_745 ) {
V_19 = - V_30 ;
goto V_59;
}
V_358 = F_114 ( V_9 -> V_113 . V_746 + V_7 -> V_298 ) ;
if ( ! V_358 ) {
V_19 = - V_297 ;
goto V_59;
}
F_281 ( V_358 , V_9 -> V_113 . V_746 ) ;
memcpy ( F_115 ( V_358 , V_7 -> V_298 ) , V_7 -> V_730 , V_7 -> V_298 ) ;
F_282 ( V_358 ) -> V_5 = V_5 ;
V_358 -> V_18 = V_12 -> V_18 ;
if ( ! V_731 ) {
* V_81 = ( unsigned long ) V_358 ;
F_283 ( V_12 , V_358 ) ;
V_19 = 0 ;
goto V_59;
}
F_282 ( V_358 ) -> V_5 |= V_747 |
V_748 ;
if ( V_9 -> V_113 . V_5 & V_749 )
F_282 ( V_358 ) -> V_750 =
V_9 -> V_113 . V_751 ;
V_19 = F_234 ( V_9 , V_12 , V_7 -> V_259 ,
V_7 -> V_752 , V_81 , V_358 ,
V_753 ) ;
if ( V_19 )
F_284 ( V_358 ) ;
V_59:
F_34 ( & V_9 -> V_282 ) ;
return V_19 ;
}
static int F_285 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_81 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_250 ( V_9 , V_81 , true ) ;
}
static void F_286 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_754 , bool V_755 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_754 ) {
case V_756 | V_757 :
if ( V_755 )
V_9 -> V_758 ++ ;
else
V_9 -> V_758 -- ;
if ( ! V_9 -> V_287 )
break;
F_224 ( & V_9 -> V_113 , & V_9 -> V_759 ) ;
break;
default:
break;
}
}
static int F_287 ( struct V_2 * V_2 , T_1 V_760 , T_1 V_761 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_673 )
return - V_244 ;
return F_288 ( V_9 , V_760 , V_761 ) ;
}
static int F_289 ( struct V_2 * V_2 , T_1 * V_760 , T_1 * V_761 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_290 ( V_9 , V_760 , V_761 ) ;
}
static int F_291 ( struct V_2 * V_2 , T_1 V_89 , T_1 V_762 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_292 ( V_9 , V_89 , V_762 ) ;
}
static void F_293 ( struct V_2 * V_2 ,
T_1 * V_89 , T_1 * V_763 , T_1 * V_762 , T_1 * V_764 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_294 ( V_9 , V_89 , V_763 , V_762 , V_764 ) ;
}
static int F_295 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_765 * V_247 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_184 -> V_766 )
return - V_244 ;
F_296 ( V_9 , V_12 , V_247 ) ;
return 0 ;
}
static void F_297 ( struct V_357 * V_358 )
{
T_3 * V_690 = ( void * ) F_115 ( V_358 , 7 ) ;
* V_690 ++ = V_767 ;
* V_690 ++ = 5 ;
* V_690 ++ = 0x0 ;
* V_690 ++ = 0x0 ;
* V_690 ++ = 0x0 ;
* V_690 ++ = 0x0 ;
* V_690 ++ = V_768 ;
}
static T_2 F_298 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_769 ;
V_769 = 0 ;
if ( F_53 ( V_12 ) != V_770 )
return V_769 ;
if ( ! ( V_9 -> V_113 . V_5 & V_771 ) )
V_769 |= V_772 ;
if ( ! ( V_9 -> V_113 . V_5 & V_773 ) )
V_769 |= V_774 ;
return V_769 ;
}
static void F_299 ( struct V_357 * V_358 , T_3 * V_775 ,
T_3 * V_776 , T_3 * V_255 )
{
struct V_777 * V_778 ;
V_778 = ( void * ) F_115 ( V_358 , sizeof( struct V_777 ) ) ;
V_778 -> V_779 = V_780 ;
V_778 -> V_468 = sizeof( struct V_777 ) - 2 ;
memcpy ( V_778 -> V_255 , V_255 , V_277 ) ;
memcpy ( V_778 -> V_781 , V_775 , V_277 ) ;
memcpy ( V_778 -> V_782 , V_776 , V_277 ) ;
}
static int
F_300 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_776 , T_3 V_783 , T_3 V_784 ,
T_2 V_785 , struct V_357 * V_358 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_372 V_373 = F_53 ( V_12 ) ;
struct V_786 * V_787 ;
V_787 = ( void * ) F_115 ( V_358 , F_301 ( struct V_786 , V_15 ) ) ;
memcpy ( V_787 -> V_359 , V_776 , V_277 ) ;
memcpy ( V_787 -> V_360 , V_12 -> V_26 . V_276 , V_277 ) ;
V_787 -> V_788 = F_302 ( V_789 ) ;
V_787 -> V_790 = V_791 ;
switch ( V_783 ) {
case V_792 :
V_787 -> V_740 = V_793 ;
V_787 -> V_783 = V_792 ;
F_115 ( V_358 , sizeof( V_787 -> V_15 . V_794 ) ) ;
V_787 -> V_15 . V_794 . V_784 = V_784 ;
V_787 -> V_15 . V_794 . V_795 =
F_303 ( F_298 ( V_12 ) ) ;
F_304 ( V_12 , V_358 , false , V_373 ) ;
F_305 ( V_12 , V_358 , false , V_373 ) ;
F_297 ( V_358 ) ;
break;
case V_796 :
V_787 -> V_740 = V_793 ;
V_787 -> V_783 = V_796 ;
F_115 ( V_358 , sizeof( V_787 -> V_15 . V_797 ) ) ;
V_787 -> V_15 . V_797 . V_785 = F_303 ( V_785 ) ;
V_787 -> V_15 . V_797 . V_784 = V_784 ;
V_787 -> V_15 . V_797 . V_795 =
F_303 ( F_298 ( V_12 ) ) ;
F_304 ( V_12 , V_358 , false , V_373 ) ;
F_305 ( V_12 , V_358 , false , V_373 ) ;
F_297 ( V_358 ) ;
break;
case V_798 :
V_787 -> V_740 = V_793 ;
V_787 -> V_783 = V_798 ;
F_115 ( V_358 , sizeof( V_787 -> V_15 . V_799 ) ) ;
V_787 -> V_15 . V_799 . V_785 = F_303 ( V_785 ) ;
V_787 -> V_15 . V_799 . V_784 = V_784 ;
break;
case V_800 :
V_787 -> V_740 = V_793 ;
V_787 -> V_783 = V_800 ;
F_115 ( V_358 , sizeof( V_787 -> V_15 . V_801 ) ) ;
V_787 -> V_15 . V_801 . V_802 = F_303 ( V_785 ) ;
break;
case V_803 :
V_787 -> V_740 = V_793 ;
V_787 -> V_783 = V_803 ;
F_115 ( V_358 , sizeof( V_787 -> V_15 . V_804 ) ) ;
V_787 -> V_15 . V_804 . V_784 = V_784 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int
F_306 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_776 , T_3 V_783 , T_3 V_784 ,
T_2 V_785 , struct V_357 * V_358 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_372 V_373 = F_53 ( V_12 ) ;
struct V_728 * V_729 ;
V_729 = ( void * ) F_115 ( V_358 , 24 ) ;
memset ( V_729 , 0 , 24 ) ;
memcpy ( V_729 -> V_359 , V_776 , V_277 ) ;
memcpy ( V_729 -> V_360 , V_12 -> V_26 . V_276 , V_277 ) ;
memcpy ( V_729 -> V_255 , V_12 -> V_15 . V_25 . V_255 , V_277 ) ;
V_729 -> V_738 = F_303 ( V_756 |
V_805 ) ;
switch ( V_783 ) {
case V_806 :
F_115 ( V_358 , 1 + sizeof( V_729 -> V_15 . V_739 . V_15 . V_807 ) ) ;
V_729 -> V_15 . V_739 . V_740 = V_741 ;
V_729 -> V_15 . V_739 . V_15 . V_807 . V_783 =
V_806 ;
V_729 -> V_15 . V_739 . V_15 . V_807 . V_784 =
V_784 ;
V_729 -> V_15 . V_739 . V_15 . V_807 . V_795 =
F_303 ( F_298 ( V_12 ) ) ;
F_304 ( V_12 , V_358 , false , V_373 ) ;
F_305 ( V_12 , V_358 , false , V_373 ) ;
F_297 ( V_358 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_307 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_776 , T_3 V_783 , T_3 V_784 ,
T_2 V_785 , T_1 V_808 ,
const T_3 * V_809 , T_5 V_810 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_357 * V_358 = NULL ;
bool V_811 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_812 ) )
return - V_529 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_628 )
return - V_47 ;
F_308 ( V_12 , L_6 ,
V_783 , V_776 ) ;
V_358 = F_114 ( V_9 -> V_113 . V_746 +
F_241 ( sizeof( struct V_728 ) ,
sizeof( struct V_786 ) ) +
50 +
7 +
V_810 +
sizeof( struct V_777 ) ) ;
if ( ! V_358 )
return - V_297 ;
F_281 ( V_358 , V_9 -> V_113 . V_746 ) ;
switch ( V_783 ) {
case V_792 :
case V_796 :
case V_798 :
case V_800 :
case V_803 :
V_19 = F_300 ( V_2 , V_18 , V_776 ,
V_783 , V_784 ,
V_785 , V_358 ) ;
V_811 = false ;
break;
case V_806 :
V_19 = F_306 ( V_2 , V_18 , V_776 , V_783 ,
V_784 , V_785 ,
V_358 ) ;
V_811 = true ;
break;
default:
V_19 = - V_529 ;
break;
}
if ( V_19 < 0 )
goto V_813;
if ( V_810 )
memcpy ( F_115 ( V_358 , V_810 ) , V_809 , V_810 ) ;
switch ( V_783 ) {
case V_792 :
case V_798 :
case V_800 :
case V_803 :
F_299 ( V_358 , V_12 -> V_26 . V_276 , V_776 ,
V_12 -> V_15 . V_25 . V_255 ) ;
break;
case V_796 :
case V_806 :
F_299 ( V_358 , V_776 , V_12 -> V_26 . V_276 ,
V_12 -> V_15 . V_25 . V_255 ) ;
break;
default:
V_19 = - V_529 ;
goto V_813;
}
if ( V_811 ) {
F_283 ( V_12 , V_358 ) ;
return 0 ;
}
switch ( V_783 ) {
case V_792 :
case V_796 :
F_309 ( V_358 , V_814 ) ;
V_358 -> V_815 = 2 ;
break;
default:
F_309 ( V_358 , V_816 ) ;
V_358 -> V_815 = 5 ;
break;
}
F_310 () ;
V_19 = F_311 ( V_358 , V_18 ) ;
F_312 () ;
return V_19 ;
V_813:
F_313 ( V_358 ) ;
return V_19 ;
}
static int F_314 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_776 , enum V_817 V_818 )
{
struct V_36 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_812 ) )
return - V_529 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_47 ;
F_308 ( V_12 , L_7 , V_818 , V_776 ) ;
switch ( V_818 ) {
case V_819 :
F_40 () ;
V_23 = F_27 ( V_12 , V_776 ) ;
if ( ! V_23 ) {
F_44 () ;
return - V_744 ;
}
F_123 ( V_23 , V_820 ) ;
F_44 () ;
break;
case V_821 :
return F_315 ( V_12 , V_776 ) ;
case V_822 :
case V_823 :
case V_824 :
return - V_529 ;
default:
return - V_529 ;
}
return 0 ;
}
static int F_316 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_776 , T_4 * V_81 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_825 * V_826 ;
struct V_357 * V_358 ;
int V_304 = sizeof( * V_826 ) ;
T_7 V_827 ;
bool V_828 ;
struct V_829 * V_830 ;
struct V_36 * V_23 ;
struct V_248 * V_249 ;
enum V_372 V_373 ;
F_40 () ;
V_249 = F_41 ( V_12 -> V_26 . V_249 ) ;
if ( F_68 ( ! V_249 ) ) {
F_44 () ;
return - V_47 ;
}
V_373 = V_249 -> V_258 . V_259 -> V_373 ;
V_23 = F_28 ( V_12 , V_776 ) ;
if ( V_23 ) {
V_828 = F_29 ( V_23 , V_237 ) ;
} else {
F_44 () ;
return - V_744 ;
}
if ( V_828 ) {
V_827 = F_303 ( V_831 |
V_832 |
V_833 ) ;
} else {
V_304 -= 2 ;
V_827 = F_303 ( V_831 |
V_834 |
V_833 ) ;
}
V_358 = F_114 ( V_9 -> V_113 . V_746 + V_304 ) ;
if ( ! V_358 ) {
F_44 () ;
return - V_297 ;
}
V_358 -> V_18 = V_18 ;
F_281 ( V_358 , V_9 -> V_113 . V_746 ) ;
V_826 = ( void * ) F_115 ( V_358 , V_304 ) ;
V_826 -> V_738 = V_827 ;
V_826 -> V_835 = 0 ;
memcpy ( V_826 -> V_836 , V_23 -> V_23 . V_276 , V_277 ) ;
memcpy ( V_826 -> V_837 , V_12 -> V_26 . V_276 , V_277 ) ;
memcpy ( V_826 -> V_838 , V_12 -> V_26 . V_276 , V_277 ) ;
V_826 -> V_839 = 0 ;
V_830 = F_282 ( V_358 ) ;
V_830 -> V_5 |= V_735 |
V_734 ;
F_309 ( V_358 , V_840 ) ;
V_358 -> V_815 = 7 ;
if ( V_828 )
V_826 -> V_841 = F_303 ( 7 ) ;
F_310 () ;
F_317 ( V_12 , V_358 , V_373 ) ;
F_312 () ;
F_44 () ;
* V_81 = ( unsigned long ) V_358 ;
return 0 ;
}
static int F_318 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_279 * V_280 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_248 * V_249 ;
int V_19 = - V_842 ;
F_40 () ;
V_249 = F_41 ( V_12 -> V_26 . V_249 ) ;
if ( V_249 ) {
* V_280 = V_249 -> V_258 ;
V_19 = 0 ;
} else if ( V_9 -> V_287 > 0 &&
V_9 -> V_287 == V_9 -> V_288 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_284 )
* V_280 = V_9 -> V_281 ;
else
* V_280 = V_9 -> V_289 ;
V_19 = 0 ;
}
F_44 () ;
return V_19 ;
}
static void F_319 ( struct V_2 * V_2 , bool V_631 )
{
F_320 ( F_2 ( V_2 ) , V_631 ) ;
}
static int F_321 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_843 * V_844 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_845 * V_846 , * V_847 ;
if ( V_844 ) {
V_846 = F_89 ( sizeof( * V_846 ) , V_296 ) ;
if ( ! V_846 )
return - V_297 ;
memcpy ( & V_846 -> V_844 , V_844 , sizeof( * V_844 ) ) ;
} else {
V_846 = NULL ;
}
V_847 = F_88 ( V_12 -> V_844 , V_12 ) ;
F_90 ( V_12 -> V_844 , V_846 ) ;
if ( V_847 )
F_91 ( V_847 , V_299 ) ;
return 0 ;
}
