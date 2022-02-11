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
if ( ( * V_5 & V_27 ) !=
( V_12 -> V_15 . V_16 & V_27 ) )
return - V_28 ;
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
T_2 V_29 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_29 = V_29 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 ,
struct V_33 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_34 * V_23 = NULL ;
struct V_35 * V_36 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_37 ;
switch ( V_7 -> V_38 ) {
case V_39 :
case V_40 :
case V_41 :
if ( F_21 ( V_12 -> V_9 -> V_42 ) )
return - V_43 ;
break;
default:
break;
}
V_36 = F_22 ( V_7 -> V_38 , V_30 , V_7 -> V_44 ,
V_7 -> V_36 , V_7 -> V_45 , V_7 -> V_46 ) ;
if ( F_21 ( V_36 ) )
return F_23 ( V_36 ) ;
if ( V_31 )
V_36 -> V_47 . V_5 |= V_48 ;
F_24 ( & V_12 -> V_9 -> V_49 ) ;
if ( V_32 ) {
if ( F_25 ( & V_12 -> V_26 ) )
V_23 = F_26 ( V_12 , V_32 ) ;
else
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 || ! F_28 ( V_23 , V_50 ) ) {
F_29 ( V_36 ) ;
V_13 = - V_51 ;
goto V_52;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_53 != V_54 )
V_36 -> V_47 . V_5 |= V_55 ;
break;
case V_56 :
case V_20 :
if ( V_36 -> V_23 && F_28 ( V_36 -> V_23 , V_57 ) )
V_36 -> V_47 . V_5 |= V_55 ;
break;
case V_58 :
break;
case V_59 :
#ifdef F_30
if ( V_12 -> V_15 . V_60 . V_61 != V_62 )
V_36 -> V_47 . V_5 |= V_55 ;
break;
#endif
case V_63 :
case V_14 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
F_31 ( 1 ) ;
break;
}
V_13 = F_32 ( V_36 , V_12 , V_23 ) ;
V_52:
F_33 ( & V_12 -> V_9 -> V_49 ) ;
return V_13 ;
}
static int F_34 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
struct V_35 * V_36 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_49 ) ;
F_24 ( & V_9 -> V_69 ) ;
if ( V_32 ) {
V_19 = - V_51 ;
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_52;
if ( V_31 )
V_36 = F_35 ( V_9 , V_23 -> V_70 ) ;
else
V_36 = F_35 ( V_9 , V_23 -> V_71 [ V_30 ] ) ;
} else
V_36 = F_35 ( V_9 , V_12 -> V_72 [ V_30 ] ) ;
if ( ! V_36 ) {
V_19 = - V_51 ;
goto V_52;
}
F_36 ( V_36 , true ) ;
V_19 = 0 ;
V_52:
F_33 ( & V_9 -> V_69 ) ;
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 ,
void * V_73 ,
void (* F_38)( void * V_73 ,
struct V_33 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_34 * V_23 = NULL ;
T_3 V_46 [ 6 ] = { 0 } ;
struct V_33 V_7 ;
struct V_35 * V_36 = NULL ;
T_4 V_74 ;
T_1 V_75 ;
T_2 V_76 ;
int V_13 = - V_51 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
if ( V_32 ) {
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_77;
if ( V_31 )
V_36 = F_40 ( V_23 -> V_70 ) ;
else if ( V_30 < V_78 )
V_36 = F_40 ( V_23 -> V_71 [ V_30 ] ) ;
} else
V_36 = F_40 ( V_12 -> V_72 [ V_30 ] ) ;
if ( ! V_36 )
goto V_77;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_38 = V_36 -> V_47 . V_38 ;
switch ( V_36 -> V_47 . V_38 ) {
case V_40 :
V_75 = V_36 -> V_15 . V_79 . V_80 . V_75 ;
V_76 = V_36 -> V_15 . V_79 . V_80 . V_76 ;
if ( V_36 -> V_5 & V_81 )
F_41 ( V_12 -> V_9 ,
V_36 -> V_47 . V_82 ,
& V_75 , & V_76 ) ;
V_46 [ 0 ] = V_76 & 0xff ;
V_46 [ 1 ] = ( V_76 >> 8 ) & 0xff ;
V_46 [ 2 ] = V_75 & 0xff ;
V_46 [ 3 ] = ( V_75 >> 8 ) & 0xff ;
V_46 [ 4 ] = ( V_75 >> 16 ) & 0xff ;
V_46 [ 5 ] = ( V_75 >> 24 ) & 0xff ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_83 :
V_74 = F_42 ( & V_36 -> V_15 . V_84 . V_85 ) ;
V_46 [ 0 ] = V_74 ;
V_46 [ 1 ] = V_74 >> 8 ;
V_46 [ 2 ] = V_74 >> 16 ;
V_46 [ 3 ] = V_74 >> 24 ;
V_46 [ 4 ] = V_74 >> 32 ;
V_46 [ 5 ] = V_74 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_86 :
V_74 = F_42 ( & V_36 -> V_15 . V_87 . V_85 ) ;
V_46 [ 0 ] = V_74 ;
V_46 [ 1 ] = V_74 >> 8 ;
V_46 [ 2 ] = V_74 >> 16 ;
V_46 [ 3 ] = V_74 >> 24 ;
V_46 [ 4 ] = V_74 >> 32 ;
V_46 [ 5 ] = V_74 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
}
V_7 . V_36 = V_36 -> V_47 . V_36 ;
V_7 . V_44 = V_36 -> V_47 . V_88 ;
F_38 ( V_73 , & V_7 ) ;
V_13 = 0 ;
V_77:
F_43 () ;
return V_13 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_30 , bool V_89 ,
bool V_90 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_45 ( V_12 , V_30 , V_89 , V_90 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_30 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_30 ) ;
return 0 ;
}
void F_48 ( struct V_34 * V_23 ,
const struct V_91 * V_92 ,
struct V_93 * V_94 )
{
V_94 -> V_5 = 0 ;
if ( V_92 -> V_5 & V_95 ) {
V_94 -> V_5 |= V_96 ;
V_94 -> V_97 = V_92 -> V_98 ;
} else if ( V_92 -> V_5 & V_99 ) {
V_94 -> V_5 |= V_100 ;
V_94 -> V_97 = F_49 ( V_92 ) ;
V_94 -> V_101 = F_50 ( V_92 ) ;
} else {
struct V_102 * V_103 ;
V_103 = V_23 -> V_9 -> V_104 . V_2 -> V_105 [
F_51 ( V_23 -> V_12 ) ] ;
V_94 -> V_106 = V_103 -> V_107 [ V_92 -> V_98 ] . V_108 ;
}
if ( V_92 -> V_5 & V_109 )
V_94 -> V_5 |= V_110 ;
if ( V_92 -> V_5 & V_111 )
V_94 -> V_5 |= V_112 ;
if ( V_92 -> V_5 & V_113 )
V_94 -> V_5 |= V_114 ;
if ( V_92 -> V_5 & V_115 )
V_94 -> V_5 |= V_116 ;
}
void F_52 ( struct V_34 * V_23 , struct V_93 * V_94 )
{
V_94 -> V_5 = 0 ;
if ( V_23 -> V_117 & V_118 ) {
V_94 -> V_5 |= V_96 ;
V_94 -> V_97 = V_23 -> V_119 ;
} else if ( V_23 -> V_117 & V_120 ) {
V_94 -> V_5 |= V_100 ;
V_94 -> V_101 = V_23 -> V_121 ;
V_94 -> V_97 = V_23 -> V_119 ;
} else {
struct V_102 * V_103 ;
V_103 = V_23 -> V_9 -> V_104 . V_2 -> V_105 [
F_51 ( V_23 -> V_12 ) ] ;
V_94 -> V_106 =
V_103 -> V_107 [ V_23 -> V_119 ] . V_108 ;
}
if ( V_23 -> V_117 & V_122 )
V_94 -> V_5 |= V_110 ;
if ( V_23 -> V_117 & V_123 )
V_94 -> V_5 |= V_116 ;
if ( V_23 -> V_117 & V_124 )
V_94 -> V_5 |= V_112 ;
if ( V_23 -> V_117 & V_125 )
V_94 -> V_5 |= V_126 ;
if ( V_23 -> V_117 & V_127 )
V_94 -> V_5 |= V_114 ;
}
static void F_53 ( struct V_34 * V_23 , struct V_128 * V_129 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_130 V_131 ;
T_4 V_132 = 0 ;
int V_133 ;
V_129 -> V_134 = V_12 -> V_9 -> V_135 ;
V_129 -> V_136 = V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 ;
F_54 ( & V_131 ) ;
V_129 -> V_151 = V_131 . V_152 - V_23 -> V_153 ;
V_129 -> V_154 = F_55 ( V_155 - V_23 -> V_156 ) ;
V_129 -> V_157 = 0 ;
for ( V_133 = 0 ; V_133 < V_158 ; V_133 ++ ) {
V_129 -> V_157 += V_23 -> V_157 [ V_133 ] ;
V_132 += V_23 -> V_159 [ V_133 ] ;
}
V_129 -> V_159 = V_132 ;
V_129 -> V_160 = V_23 -> V_160 ;
V_129 -> V_161 = V_23 -> V_161 ;
V_129 -> V_162 = V_23 -> V_163 ;
V_129 -> V_164 = V_23 -> V_165 ;
V_129 -> V_166 = V_23 -> V_167 ;
V_129 -> V_168 = V_23 -> V_168 ;
if ( ( V_23 -> V_9 -> V_104 . V_5 & V_169 ) ||
( V_23 -> V_9 -> V_104 . V_5 & V_170 ) ) {
V_129 -> V_136 |= V_171 | V_172 ;
if ( ! V_9 -> V_173 -> V_174 ||
F_56 ( V_9 , V_12 , & V_23 -> V_23 , & V_129 -> signal ) )
V_129 -> signal = ( V_175 ) V_23 -> V_176 ;
V_129 -> V_177 = ( V_175 ) - F_57 ( & V_23 -> V_178 ) ;
}
F_48 ( V_23 , & V_23 -> V_179 , & V_129 -> V_180 ) ;
F_52 ( V_23 , & V_129 -> V_181 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
V_129 -> V_136 |= V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 ;
V_129 -> V_188 = F_58 ( V_23 -> V_188 ) ;
V_129 -> V_189 = F_58 ( V_23 -> V_189 ) ;
V_129 -> V_190 = V_23 -> V_190 ;
if ( F_28 ( V_23 , V_191 ) ) {
V_129 -> V_136 |= V_192 ;
V_129 -> V_193 = V_23 -> V_193 ;
}
V_129 -> V_194 = V_23 -> V_194 ;
V_129 -> V_195 = V_23 -> V_195 ;
V_129 -> V_196 = V_23 -> V_196 ;
#endif
}
V_129 -> V_197 . V_5 = 0 ;
if ( V_12 -> V_26 . V_198 . V_199 )
V_129 -> V_197 . V_5 |= V_200 ;
if ( V_12 -> V_26 . V_198 . V_201 )
V_129 -> V_197 . V_5 |= V_202 ;
if ( V_12 -> V_26 . V_198 . V_203 )
V_129 -> V_197 . V_5 |= V_204 ;
V_129 -> V_197 . V_205 = V_12 -> V_9 -> V_104 . V_47 . V_206 ;
V_129 -> V_197 . V_207 = V_12 -> V_26 . V_198 . V_208 ;
V_129 -> V_209 . V_210 = 0 ;
V_129 -> V_209 . V_211 = F_59 ( V_212 ) |
F_59 ( V_213 ) |
F_59 ( V_214 ) |
F_59 ( V_215 ) |
F_59 ( V_216 ) |
F_59 ( V_217 ) |
F_59 ( V_218 ) ;
if ( F_28 ( V_23 , V_219 ) )
V_129 -> V_209 . V_210 |= F_59 ( V_212 ) ;
if ( F_28 ( V_23 , V_220 ) )
V_129 -> V_209 . V_210 |= F_59 ( V_213 ) ;
if ( F_28 ( V_23 , V_221 ) )
V_129 -> V_209 . V_210 |= F_59 ( V_214 ) ;
if ( F_28 ( V_23 , V_57 ) )
V_129 -> V_209 . V_210 |= F_59 ( V_215 ) ;
if ( F_28 ( V_23 , V_222 ) )
V_129 -> V_209 . V_210 |= F_59 ( V_216 ) ;
if ( F_28 ( V_23 , V_50 ) )
V_129 -> V_209 . V_210 |= F_59 ( V_217 ) ;
if ( F_28 ( V_23 , V_223 ) )
V_129 -> V_209 . V_210 |= F_59 ( V_218 ) ;
}
static int F_60 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_224 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_225 = 0 ;
if ( V_224 == V_226 )
V_225 += V_227 ;
V_225 += F_61 ( V_12 , V_224 ) ;
if ( V_225 == 0 )
return - V_228 ;
return V_225 ;
}
static void F_62 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_229 * V_230 ,
T_4 * V_231 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_232 * V_233 ;
struct V_234 * V_235 ;
struct V_34 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_128 V_129 ;
struct V_236 V_237 ;
int V_238 , V_239 ;
#define F_63 7
memset ( V_231 , 0 , sizeof( T_4 ) * V_227 ) ;
#define F_64 ( V_23 ) \
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
F_24 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_27 ( V_12 , V_12 -> V_15 . V_25 . V_240 ) ;
if ( ! ( V_23 && ! F_65 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_241;
V_129 . V_136 = 0 ;
F_53 ( V_23 , & V_129 ) ;
V_238 = 0 ;
F_64 ( V_23 ) ;
V_231 [ V_238 ++ ] = V_23 -> V_242 ;
if ( V_129 . V_136 & V_144 )
V_231 [ V_238 ] = 100000 *
F_66 ( & V_129 . V_180 ) ;
V_238 ++ ;
if ( V_129 . V_136 & V_145 )
V_231 [ V_238 ] = 100000 *
F_66 ( & V_129 . V_181 ) ;
V_238 ++ ;
if ( V_129 . V_136 & V_172 )
V_231 [ V_238 ] = ( T_3 ) V_129 . V_177 ;
V_238 ++ ;
} else {
F_67 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_238 = 0 ;
F_64 ( V_23 ) ;
}
}
V_241:
V_238 = V_227 - F_63 ;
V_237 . V_136 = 0 ;
F_39 () ;
V_233 = F_40 ( V_12 -> V_26 . V_233 ) ;
if ( V_233 )
V_235 = V_233 -> V_243 . V_244 ;
else
V_235 = NULL ;
F_43 () ;
if ( V_235 ) {
V_239 = 0 ;
do {
V_237 . V_136 = 0 ;
if ( F_68 ( V_9 , V_239 , & V_237 ) != 0 ) {
V_237 . V_136 = 0 ;
break;
}
V_239 ++ ;
} while ( V_235 != V_237 . V_235 );
}
if ( V_237 . V_136 )
V_231 [ V_238 ++ ] = V_237 . V_235 -> V_245 ;
else
V_231 [ V_238 ++ ] = 0 ;
if ( V_237 . V_136 & V_246 )
V_231 [ V_238 ++ ] = ( T_3 ) V_237 . V_247 ;
else
V_231 [ V_238 ++ ] = - 1LL ;
if ( V_237 . V_136 & V_248 )
V_231 [ V_238 ++ ] = V_237 . V_249 ;
else
V_231 [ V_238 ++ ] = - 1LL ;
if ( V_237 . V_136 & V_250 )
V_231 [ V_238 ++ ] = V_237 . V_251 ;
else
V_231 [ V_238 ++ ] = - 1LL ;
if ( V_237 . V_136 & V_252 )
V_231 [ V_238 ++ ] = V_237 . V_253 ;
else
V_231 [ V_238 ++ ] = - 1LL ;
if ( V_237 . V_136 & V_254 )
V_231 [ V_238 ++ ] = V_237 . V_255 ;
else
V_231 [ V_238 ++ ] = - 1LL ;
if ( V_237 . V_136 & V_256 )
V_231 [ V_238 ++ ] = V_237 . V_257 ;
else
V_231 [ V_238 ++ ] = - 1LL ;
F_33 ( & V_9 -> V_49 ) ;
if ( F_65 ( V_238 != V_227 ) )
return;
F_69 ( V_12 , V_230 , & ( V_231 [ V_227 ] ) ) ;
}
static void F_70 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_224 , T_3 * V_231 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_258 = 0 ;
if ( V_224 == V_226 ) {
V_258 = sizeof( V_259 ) ;
memcpy ( V_231 , * V_259 , V_258 ) ;
}
F_71 ( V_12 , V_224 , & ( V_231 [ V_258 ] ) ) ;
}
static int F_72 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , T_3 * V_260 , struct V_128 * V_129 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_51 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_73 ( V_12 , V_98 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_260 , V_23 -> V_23 . V_261 , V_262 ) ;
F_53 ( V_23 , V_129 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_74 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , struct V_236 * V_237 )
{
struct V_8 * V_9 = F_75 ( V_18 -> V_263 ) ;
return F_68 ( V_9 , V_98 , V_237 ) ;
}
static int F_76 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_260 , struct V_128 * V_129 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_51 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_260 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_53 ( V_23 , V_129 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_77 ( struct V_2 * V_2 ,
struct V_264 * V_265 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_78 ( & V_9 -> V_266 , V_265 ) )
return 0 ;
F_24 ( & V_9 -> V_267 ) ;
if ( V_9 -> V_268 ) {
V_12 = F_79 (
V_9 -> V_269 ,
F_80 ( & V_9 -> V_267 ) ) ;
if ( V_12 ) {
F_81 ( V_12 ) ;
V_19 = F_82 ( V_12 , V_265 ,
V_270 ) ;
}
} else if ( V_9 -> V_271 == V_9 -> V_272 ) {
V_9 -> V_273 = * V_265 ;
F_83 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_266 = * V_265 ;
F_33 ( & V_9 -> V_267 ) ;
return V_19 ;
}
static int F_84 ( struct V_11 * V_12 ,
const T_3 * V_274 , T_5 V_275 )
{
struct V_276 * V_277 , * V_278 ;
if ( ! V_274 || ! V_275 )
return 1 ;
V_278 = F_85 ( V_12 -> V_15 . V_279 . V_276 ) ;
V_277 = F_86 ( sizeof( struct V_276 ) + V_275 , V_280 ) ;
if ( ! V_277 )
return - V_281 ;
V_277 -> V_282 = V_275 ;
memcpy ( V_277 -> V_231 , V_274 , V_275 ) ;
F_87 ( V_12 -> V_15 . V_279 . V_276 , V_277 ) ;
if ( V_278 )
F_88 ( V_278 , V_283 ) ;
return 0 ;
}
static int F_89 ( struct V_11 * V_12 ,
struct V_284 * V_7 )
{
struct V_285 * V_277 , * V_278 ;
int V_286 , V_287 ;
int V_288 , V_13 ;
T_1 V_289 = V_290 ;
V_278 = F_85 ( V_12 -> V_15 . V_279 . V_291 ) ;
if ( ! V_7 -> V_292 && ! V_278 )
return - V_43 ;
if ( V_7 -> V_292 )
V_286 = V_7 -> V_293 ;
else
V_286 = V_278 -> V_293 ;
if ( V_7 -> V_294 || ! V_278 )
V_287 = V_7 -> V_295 ;
else
V_287 = V_278 -> V_295 ;
V_288 = sizeof( * V_277 ) + V_286 + V_287 ;
V_277 = F_86 ( V_288 , V_280 ) ;
if ( ! V_277 )
return - V_281 ;
V_277 -> V_292 = ( ( T_3 * ) V_277 ) + sizeof( * V_277 ) ;
V_277 -> V_294 = V_277 -> V_292 + V_286 ;
V_277 -> V_293 = V_286 ;
V_277 -> V_295 = V_287 ;
if ( V_7 -> V_292 )
memcpy ( V_277 -> V_292 , V_7 -> V_292 , V_286 ) ;
else
memcpy ( V_277 -> V_292 , V_278 -> V_292 , V_286 ) ;
if ( V_7 -> V_294 )
memcpy ( V_277 -> V_294 , V_7 -> V_294 , V_287 ) ;
else
if ( V_278 )
memcpy ( V_277 -> V_294 , V_278 -> V_294 , V_287 ) ;
V_13 = F_84 ( V_12 , V_7 -> V_276 ,
V_7 -> V_296 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_289 |= V_297 ;
F_87 ( V_12 -> V_15 . V_279 . V_291 , V_277 ) ;
if ( V_278 )
F_88 ( V_278 , V_283 ) ;
return V_289 ;
}
static int F_90 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_298 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_285 * V_278 ;
struct V_11 * V_22 ;
T_1 V_289 = V_299 |
V_300 |
V_290 |
V_301 |
V_302 ;
int V_13 ;
V_278 = F_85 ( V_12 -> V_15 . V_279 . V_291 ) ;
if ( V_278 )
return - V_303 ;
V_12 -> V_304 = V_305 ;
V_12 -> V_306 = V_12 -> V_9 -> V_307 ;
V_12 -> V_308 = V_7 -> V_308 ;
V_13 = F_82 ( V_12 , & V_7 -> V_265 ,
V_309 ) ;
if ( V_13 )
return V_13 ;
F_91 ( V_12 , false ) ;
V_12 -> V_310 = V_7 -> V_311 . V_312 ;
V_12 -> V_313 = V_7 -> V_311 . V_313 ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_310 =
V_7 -> V_311 . V_312 ;
V_22 -> V_313 =
V_7 -> V_311 . V_313 ;
}
V_12 -> V_26 . V_198 . V_208 = V_7 -> V_207 ;
V_12 -> V_26 . V_198 . V_205 = V_7 -> V_205 ;
V_12 -> V_26 . V_198 . V_314 = true ;
V_12 -> V_26 . V_198 . V_315 = V_7 -> V_315 ;
if ( V_7 -> V_315 )
memcpy ( V_12 -> V_26 . V_198 . V_316 , V_7 -> V_316 ,
V_7 -> V_315 ) ;
V_12 -> V_26 . V_198 . V_317 =
( V_7 -> V_317 != V_318 ) ;
memset ( & V_12 -> V_26 . V_198 . V_319 , 0 ,
sizeof( V_12 -> V_26 . V_198 . V_319 ) ) ;
V_12 -> V_26 . V_198 . V_319 . V_320 =
V_7 -> V_321 & V_322 ;
if ( V_7 -> V_323 )
V_12 -> V_26 . V_198 . V_319 . V_320 |=
V_324 ;
V_13 = F_89 ( V_12 , & V_7 -> V_291 ) ;
if ( V_13 < 0 )
return V_13 ;
V_289 |= V_13 ;
V_13 = F_92 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_278 = F_85 ( V_12 -> V_15 . V_279 . V_291 ) ;
if ( V_278 )
F_88 ( V_278 , V_283 ) ;
F_11 ( V_12 -> V_15 . V_279 . V_291 , NULL ) ;
return V_13 ;
}
F_93 ( V_12 , V_289 ) ;
F_94 ( V_18 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_94 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_284 * V_7 )
{
struct V_11 * V_12 ;
struct V_285 * V_278 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
V_278 = F_85 ( V_12 -> V_15 . V_279 . V_291 ) ;
if ( ! V_278 )
return - V_51 ;
V_13 = F_89 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_93 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_285 * V_325 ;
struct V_276 * V_326 ;
V_325 = F_85 ( V_12 -> V_15 . V_279 . V_291 ) ;
if ( ! V_325 )
return - V_51 ;
V_326 = F_85 ( V_12 -> V_15 . V_279 . V_276 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_97 ( V_22 -> V_18 ) ;
F_97 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_279 . V_291 , NULL ) ;
F_11 ( V_12 -> V_15 . V_279 . V_276 , NULL ) ;
F_88 ( V_325 , V_283 ) ;
if ( V_326 )
F_88 ( V_326 , V_283 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_98 ( V_22 ) ;
F_98 ( V_12 ) ;
F_99 () ;
F_100 () ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
F_101 ( V_22 ) ;
F_102 ( V_22 ) ;
}
F_101 ( V_12 ) ;
F_102 ( V_12 ) ;
V_12 -> V_26 . V_198 . V_314 = false ;
V_12 -> V_26 . V_198 . V_315 = 0 ;
F_103 ( V_327 , & V_12 -> V_328 ) ;
F_93 ( V_12 , V_300 ) ;
if ( V_12 -> V_10 . V_329 ) {
F_104 ( & V_12 -> V_330 ) ;
F_105 ( V_12 -> V_18 , V_331 ,
V_280 ) ;
}
F_106 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_332 -= F_107 ( & V_12 -> V_15 . V_279 . V_333 . V_334 ) ;
F_108 ( & V_12 -> V_15 . V_279 . V_333 . V_334 ) ;
F_91 ( V_12 , true ) ;
F_81 ( V_12 ) ;
return 0 ;
}
static void F_109 ( struct V_34 * V_23 )
{
struct V_335 * V_336 ;
struct V_337 * V_338 ;
V_338 = F_110 ( sizeof( * V_336 ) ) ;
if ( ! V_338 )
return;
V_336 = (struct V_335 * ) F_111 ( V_338 , sizeof( * V_336 ) ) ;
F_112 ( V_336 -> V_339 ) ;
memcpy ( V_336 -> V_340 , V_23 -> V_23 . V_261 , V_262 ) ;
V_336 -> V_282 = F_113 ( 6 ) ;
V_336 -> V_341 = 0 ;
V_336 -> V_342 = 0x01 ;
V_336 -> V_343 = 0xaf ;
V_336 -> V_344 [ 0 ] = 0x81 ;
V_336 -> V_344 [ 1 ] = 1 ;
V_336 -> V_344 [ 2 ] = 0 ;
V_338 -> V_18 = V_23 -> V_12 -> V_18 ;
V_338 -> V_345 = F_114 ( V_338 , V_23 -> V_12 -> V_18 ) ;
memset ( V_338 -> V_346 , 0 , sizeof( V_338 -> V_346 ) ) ;
F_115 ( V_338 ) ;
}
static int F_116 ( struct V_8 * V_9 ,
struct V_34 * V_23 ,
T_1 V_211 , T_1 V_210 )
{
int V_19 ;
if ( V_211 & F_59 ( V_216 ) &&
V_210 & F_59 ( V_216 ) &&
! F_28 ( V_23 , V_222 ) ) {
V_19 = F_117 ( V_23 , V_347 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_211 & F_59 ( V_217 ) &&
V_210 & F_59 ( V_217 ) &&
! F_28 ( V_23 , V_50 ) ) {
V_19 = F_117 ( V_23 , V_348 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_211 & F_59 ( V_212 ) ) {
if ( V_210 & F_59 ( V_212 ) )
V_19 = F_117 ( V_23 , V_349 ) ;
else if ( F_28 ( V_23 , V_219 ) )
V_19 = F_117 ( V_23 , V_348 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_211 & F_59 ( V_217 ) &&
! ( V_210 & F_59 ( V_217 ) ) &&
F_28 ( V_23 , V_50 ) ) {
V_19 = F_117 ( V_23 , V_347 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_211 & F_59 ( V_216 ) &&
! ( V_210 & F_59 ( V_216 ) ) &&
F_28 ( V_23 , V_222 ) ) {
V_19 = F_117 ( V_23 , V_350 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_118 ( struct V_8 * V_9 ,
struct V_34 * V_23 ,
struct V_351 * V_7 )
{
int V_19 = 0 ;
T_1 V_352 ;
int V_238 , V_353 ;
struct V_102 * V_103 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_354 V_355 = F_51 ( V_12 ) ;
T_1 V_211 , V_210 ;
V_103 = V_9 -> V_104 . V_2 -> V_105 [ V_355 ] ;
V_211 = V_7 -> V_356 ;
V_210 = V_7 -> V_357 ;
if ( F_25 ( & V_12 -> V_26 ) ) {
if ( V_211 & F_59 ( V_216 ) )
V_211 |= F_59 ( V_217 ) ;
if ( V_210 & F_59 ( V_216 ) )
V_210 |= F_59 ( V_217 ) ;
} else if ( F_28 ( V_23 , V_223 ) ) {
if ( V_210 & F_59 ( V_212 ) ) {
V_210 |= F_59 ( V_216 ) |
F_59 ( V_217 ) ;
V_211 |= F_59 ( V_216 ) |
F_59 ( V_217 ) ;
}
}
V_19 = F_116 ( V_9 , V_23 , V_211 , V_210 ) ;
if ( V_19 )
return V_19 ;
if ( V_211 & F_59 ( V_213 ) ) {
if ( V_210 & F_59 ( V_213 ) )
F_119 ( V_23 , V_220 ) ;
else
F_120 ( V_23 , V_220 ) ;
}
if ( V_211 & F_59 ( V_214 ) ) {
if ( V_210 & F_59 ( V_214 ) ) {
F_119 ( V_23 , V_221 ) ;
V_23 -> V_23 . V_358 = true ;
} else {
F_120 ( V_23 , V_221 ) ;
V_23 -> V_23 . V_358 = false ;
}
}
if ( V_211 & F_59 ( V_215 ) ) {
if ( V_210 & F_59 ( V_215 ) )
F_119 ( V_23 , V_57 ) ;
else
F_120 ( V_23 , V_57 ) ;
}
if ( V_211 & F_59 ( V_218 ) ) {
if ( V_210 & F_59 ( V_218 ) )
F_119 ( V_23 , V_223 ) ;
else
F_120 ( V_23 , V_223 ) ;
}
if ( V_7 -> V_359 & V_360 ) {
V_23 -> V_23 . V_361 = V_7 -> V_361 ;
V_23 -> V_23 . V_362 = V_7 -> V_362 ;
}
if ( V_7 -> V_363 )
V_23 -> V_23 . V_363 = V_7 -> V_363 ;
if ( V_7 -> V_364 >= 0 )
V_23 -> V_364 = V_7 -> V_364 ;
if ( V_7 -> V_365 ) {
V_352 = 0 ;
for ( V_238 = 0 ; V_238 < V_7 -> V_366 ; V_238 ++ ) {
int V_92 = ( V_7 -> V_365 [ V_238 ] & 0x7f ) * 5 ;
for ( V_353 = 0 ; V_353 < V_103 -> V_367 ; V_353 ++ ) {
if ( V_103 -> V_107 [ V_353 ] . V_108 == V_92 )
V_352 |= F_59 ( V_353 ) ;
}
}
V_23 -> V_23 . V_368 [ V_355 ] = V_352 ;
}
if ( V_7 -> V_369 )
F_121 ( V_12 , V_103 ,
V_7 -> V_369 , V_23 ) ;
if ( V_7 -> V_370 )
F_122 ( V_12 , V_103 ,
V_7 -> V_370 , V_23 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
T_1 V_289 = 0 ;
if ( V_7 -> V_359 & V_371 ) {
switch ( V_7 -> V_190 ) {
case V_372 :
if ( V_23 -> V_190 != V_372 )
V_289 = F_123 (
V_12 ) ;
V_23 -> V_190 = V_7 -> V_190 ;
F_124 ( V_23 ) ;
V_289 |= F_125 ( V_23 ,
V_12 -> V_15 . V_60 . V_373 . V_374 ) ;
break;
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
if ( V_23 -> V_190 == V_372 )
V_289 = F_126 (
V_12 ) ;
V_23 -> V_190 = V_7 -> V_190 ;
F_124 ( V_23 ) ;
V_289 |=
F_127 ( V_12 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_381 ) {
case V_382 :
break;
case V_383 :
V_289 |= F_128 ( V_23 ) ;
break;
case V_384 :
V_289 |= F_129 ( V_23 ) ;
break;
}
if ( V_7 -> V_194 )
V_289 |=
F_125 ( V_23 ,
V_7 -> V_194 ) ;
F_93 ( V_12 , V_289 ) ;
#endif
}
return 0 ;
}
static int F_130 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_260 , struct V_351 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_385 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_56 )
return - V_43 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_131 ( V_260 , V_12 -> V_26 . V_261 ) )
return - V_43 ;
if ( F_132 ( V_260 ) )
return - V_43 ;
V_23 = F_133 ( V_12 , V_260 , V_280 ) ;
if ( ! V_23 )
return - V_281 ;
if ( ! ( V_7 -> V_357 & F_59 ( V_218 ) ) ) {
F_134 ( V_23 , V_347 ) ;
F_134 ( V_23 , V_348 ) ;
}
V_13 = F_118 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_135 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_28 ( V_23 , V_223 ) )
F_136 ( V_23 ) ;
V_385 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_56 ;
V_13 = F_137 ( V_23 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
if ( V_385 )
F_109 ( V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_138 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_260 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_260 )
return F_139 ( V_12 , V_260 ) ;
F_140 ( V_12 ) ;
return 0 ;
}
static int F_141 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_3 * V_260 ,
struct V_351 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_386 ;
enum V_387 V_388 ;
int V_13 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_260 ) ;
if ( ! V_23 ) {
V_13 = - V_51 ;
goto V_389;
}
switch ( V_12 -> V_26 . type ) {
case V_59 :
if ( V_12 -> V_15 . V_60 . V_390 )
V_388 = V_391 ;
else
V_388 = V_392 ;
break;
case V_58 :
V_388 = V_393 ;
break;
case V_24 :
if ( ! F_28 ( V_23 , V_223 ) ) {
V_388 = V_394 ;
break;
}
if ( F_28 ( V_23 , V_219 ) )
V_388 = V_395 ;
else
V_388 = V_396 ;
break;
case V_56 :
case V_20 :
V_388 = V_397 ;
break;
default:
V_13 = - V_228 ;
goto V_389;
}
V_13 = F_142 ( V_2 , V_7 , V_388 ) ;
if ( V_13 )
goto V_389;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_398 = false ;
bool V_399 = false ;
V_386 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_263 -> V_21 ) {
if ( V_386 -> V_15 . V_22 . V_23 ) {
V_13 = - V_28 ;
goto V_389;
}
F_87 ( V_386 -> V_15 . V_22 . V_23 , V_23 ) ;
V_399 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_87 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_398 = true ;
}
V_23 -> V_12 = V_386 ;
if ( V_23 -> V_242 == V_349 &&
V_398 != V_399 ) {
if ( V_399 )
F_143 ( & V_23 -> V_12 -> V_400 -> V_401 ) ;
else
F_144 ( & V_23 -> V_12 -> V_400 -> V_401 ) ;
}
F_109 ( V_23 ) ;
}
V_13 = F_118 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_389;
if ( F_28 ( V_23 , V_223 ) &&
F_28 ( V_23 , V_219 ) )
F_136 ( V_23 ) ;
F_33 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_356 & F_59 ( V_212 ) ) {
F_145 ( V_9 , - 1 ) ;
F_146 ( V_12 ) ;
}
return 0 ;
V_389:
F_33 ( & V_9 -> V_49 ) ;
return V_13 ;
}
static int F_147 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_402 , T_3 * V_403 )
{
struct V_11 * V_12 ;
struct V_404 * V_405 ;
struct V_34 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_403 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_51 ;
}
V_405 = F_148 ( V_12 , V_402 ) ;
if ( F_21 ( V_405 ) ) {
F_43 () ;
return F_23 ( V_405 ) ;
}
F_149 ( V_405 , V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_150 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_402 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_402 )
return F_151 ( V_12 , V_402 ) ;
F_152 ( V_12 ) ;
return 0 ;
}
static int F_153 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_402 , T_3 * V_403 )
{
struct V_11 * V_12 ;
struct V_404 * V_405 ;
struct V_34 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_403 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_51 ;
}
V_405 = F_154 ( V_12 , V_402 ) ;
if ( ! V_405 ) {
F_43 () ;
return - V_51 ;
}
F_149 ( V_405 , V_23 ) ;
F_43 () ;
return 0 ;
}
static void F_155 ( struct V_404 * V_405 , T_3 * V_403 ,
struct V_406 * V_407 )
{
struct V_34 * V_408 = F_40 ( V_405 -> V_403 ) ;
if ( V_408 )
memcpy ( V_403 , V_408 -> V_23 . V_261 , V_262 ) ;
else
memset ( V_403 , 0 , V_262 ) ;
memset ( V_407 , 0 , sizeof( * V_407 ) ) ;
V_407 -> V_134 = V_409 ;
V_407 -> V_136 = V_410 |
V_411 |
V_412 |
V_413 |
V_414 |
V_415 |
V_416 ;
V_407 -> V_417 = V_405 -> V_418 . V_419 ;
V_407 -> V_420 = V_405 -> V_420 ;
V_407 -> V_421 = V_405 -> V_421 ;
if ( F_156 ( V_155 , V_405 -> V_422 ) )
V_407 -> V_423 = F_55 ( V_405 -> V_422 - V_155 ) ;
V_407 -> V_424 =
F_55 ( V_405 -> V_424 ) ;
V_407 -> V_425 = V_405 -> V_425 ;
if ( V_405 -> V_5 & V_426 )
V_407 -> V_5 |= V_427 ;
if ( V_405 -> V_5 & V_428 )
V_407 -> V_5 |= V_429 ;
if ( V_405 -> V_5 & V_430 )
V_407 -> V_5 |= V_431 ;
if ( V_405 -> V_5 & V_432 )
V_407 -> V_5 |= V_433 ;
if ( V_405 -> V_5 & V_434 )
V_407 -> V_5 |= V_435 ;
}
static int F_157 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_402 , T_3 * V_403 , struct V_406 * V_407 )
{
struct V_11 * V_12 ;
struct V_404 * V_405 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_405 = F_154 ( V_12 , V_402 ) ;
if ( ! V_405 ) {
F_43 () ;
return - V_51 ;
}
memcpy ( V_402 , V_405 -> V_402 , V_262 ) ;
F_155 ( V_405 , V_403 , V_407 ) ;
F_43 () ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , T_3 * V_402 , T_3 * V_403 ,
struct V_406 * V_407 )
{
struct V_11 * V_12 ;
struct V_404 * V_405 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_405 = F_159 ( V_12 , V_98 ) ;
if ( ! V_405 ) {
F_43 () ;
return - V_51 ;
}
memcpy ( V_402 , V_405 -> V_402 , V_262 ) ;
F_155 ( V_405 , V_403 , V_407 ) ;
F_43 () ;
return 0 ;
}
static int F_160 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_436 * V_47 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_47 , & ( V_12 -> V_15 . V_60 . V_373 ) , sizeof( struct V_436 ) ) ;
return 0 ;
}
static inline bool F_161 ( enum V_437 V_438 , T_1 V_211 )
{
return ( V_211 >> ( V_438 - 1 ) ) & 0x1 ;
}
static int F_162 ( struct V_439 * V_440 ,
const struct V_441 * V_442 )
{
T_3 * V_443 ;
const T_3 * V_444 ;
struct V_11 * V_12 = F_163 ( V_440 ,
struct V_11 , V_15 . V_60 ) ;
V_443 = NULL ;
V_444 = V_440 -> V_445 ;
if ( V_442 -> V_446 ) {
V_443 = F_164 ( V_442 -> V_445 , V_442 -> V_446 ,
V_280 ) ;
if ( ! V_443 )
return - V_281 ;
}
V_440 -> V_446 = V_442 -> V_446 ;
V_440 -> V_445 = V_443 ;
F_165 ( V_444 ) ;
V_440 -> V_447 = V_442 -> V_447 ;
memcpy ( V_440 -> V_448 , V_442 -> V_448 , V_440 -> V_447 ) ;
V_440 -> V_449 = V_442 -> V_450 ;
V_440 -> V_451 = V_442 -> V_452 ;
V_440 -> V_453 = V_442 -> V_454 ;
V_440 -> V_390 = V_442 -> V_390 ;
V_440 -> V_61 = V_62 ;
if ( V_442 -> V_455 )
V_440 -> V_61 |= V_456 ;
if ( V_442 -> V_457 )
V_440 -> V_61 |= V_458 ;
memcpy ( V_12 -> V_26 . V_198 . V_459 , V_442 -> V_459 ,
sizeof( V_442 -> V_459 ) ) ;
V_12 -> V_26 . V_198 . V_208 = V_442 -> V_207 ;
V_12 -> V_26 . V_198 . V_205 = V_442 -> V_205 ;
return 0 ;
}
static int F_166 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_211 ,
const struct V_436 * V_460 )
{
struct V_436 * V_47 ;
struct V_11 * V_12 ;
struct V_439 * V_440 ;
V_12 = F_9 ( V_18 ) ;
V_440 = & V_12 -> V_15 . V_60 ;
V_47 = & ( V_12 -> V_15 . V_60 . V_373 ) ;
if ( F_161 ( V_461 , V_211 ) )
V_47 -> V_462 = V_460 -> V_462 ;
if ( F_161 ( V_463 , V_211 ) )
V_47 -> V_464 = V_460 -> V_464 ;
if ( F_161 ( V_465 , V_211 ) )
V_47 -> V_466 = V_460 -> V_466 ;
if ( F_161 ( V_467 , V_211 ) )
V_47 -> V_468 = V_460 -> V_468 ;
if ( F_161 ( V_469 , V_211 ) )
V_47 -> V_470 = V_460 -> V_470 ;
if ( F_161 ( V_471 , V_211 ) )
V_47 -> V_472 = V_460 -> V_472 ;
if ( F_161 ( V_473 , V_211 ) )
V_47 -> V_474 = V_460 -> V_474 ;
if ( F_161 ( V_475 , V_211 ) ) {
if ( V_440 -> V_390 )
return - V_28 ;
V_47 -> V_476 = V_460 -> V_476 ;
}
if ( F_161 ( V_477 , V_211 ) )
V_47 -> V_478 =
V_460 -> V_478 ;
if ( F_161 ( V_479 , V_211 ) )
V_47 -> V_480 =
V_460 -> V_480 ;
if ( F_161 ( V_481 , V_211 ) )
V_47 -> V_482 = V_460 -> V_482 ;
if ( F_161 ( V_483 , V_211 ) )
V_47 -> V_484 = V_460 -> V_484 ;
if ( F_161 ( V_485 , V_211 ) )
V_47 -> V_486 =
V_460 -> V_486 ;
if ( F_161 ( V_487 , V_211 ) )
V_47 -> V_488 =
V_460 -> V_488 ;
if ( F_161 ( V_489 , V_211 ) )
V_47 -> V_490 =
V_460 -> V_490 ;
if ( F_161 ( V_491 ,
V_211 ) )
V_47 -> V_492 =
V_460 -> V_492 ;
if ( F_161 ( V_493 , V_211 ) ) {
V_47 -> V_494 = V_460 -> V_494 ;
F_167 ( V_440 ) ;
}
if ( F_161 ( V_495 , V_211 ) ) {
if ( V_460 -> V_496 &&
! ( V_47 -> V_494 > V_497 ) ) {
V_47 -> V_494 = V_498 ;
F_167 ( V_440 ) ;
}
V_47 -> V_496 =
V_460 -> V_496 ;
}
if ( F_161 ( V_499 , V_211 ) )
V_47 -> V_500 =
V_460 -> V_500 ;
if ( F_161 ( V_501 , V_211 ) )
V_47 -> V_502 = V_460 -> V_502 ;
if ( F_161 ( V_503 , V_211 ) ) {
if ( ! ( V_12 -> V_9 -> V_104 . V_5 & V_169 ) )
return - V_504 ;
V_47 -> V_505 = V_460 -> V_505 ;
}
if ( F_161 ( V_506 , V_211 ) ) {
V_47 -> V_507 = V_460 -> V_507 ;
V_12 -> V_26 . V_198 . V_508 = V_460 -> V_507 ;
F_93 ( V_12 , V_509 ) ;
}
if ( F_161 ( V_510 , V_211 ) )
V_47 -> V_511 =
V_460 -> V_511 ;
if ( F_161 ( V_512 , V_211 ) )
V_47 -> V_513 =
V_460 -> V_513 ;
if ( F_161 ( V_514 , V_211 ) )
V_47 -> V_515 =
V_460 -> V_515 ;
if ( F_161 ( V_516 , V_211 ) ) {
V_47 -> V_374 = V_460 -> V_374 ;
F_127 ( V_12 ) ;
}
if ( F_161 ( V_517 , V_211 ) )
V_47 -> V_518 =
V_460 -> V_518 ;
F_168 ( V_12 , V_290 ) ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_436 * V_47 ,
const struct V_441 * V_442 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_439 * V_440 = & V_12 -> V_15 . V_60 ;
int V_13 ;
memcpy ( & V_440 -> V_373 , V_47 , sizeof( struct V_436 ) ) ;
V_13 = F_162 ( V_440 , V_442 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_304 = V_305 ;
V_12 -> V_306 = V_12 -> V_9 -> V_307 ;
V_13 = F_82 ( V_12 , & V_442 -> V_265 ,
V_309 ) ;
if ( V_13 )
return V_13 ;
return F_170 ( V_12 ) ;
}
static int F_171 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_172 ( V_12 ) ;
F_81 ( V_12 ) ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_519 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_354 V_355 ;
T_1 V_289 = 0 ;
if ( ! F_85 ( V_12 -> V_15 . V_279 . V_291 ) )
return - V_51 ;
V_355 = F_51 ( V_12 ) ;
if ( V_7 -> V_199 >= 0 ) {
V_12 -> V_26 . V_198 . V_199 = V_7 -> V_199 ;
V_289 |= V_520 ;
}
if ( V_7 -> V_201 >= 0 ) {
V_12 -> V_26 . V_198 . V_201 =
V_7 -> V_201 ;
V_289 |= V_521 ;
}
if ( ! V_12 -> V_26 . V_198 . V_203 &&
V_355 == V_522 ) {
V_12 -> V_26 . V_198 . V_203 = true ;
V_289 |= V_523 ;
}
if ( V_7 -> V_524 >= 0 ) {
V_12 -> V_26 . V_198 . V_203 =
V_7 -> V_524 ;
V_289 |= V_523 ;
}
if ( V_7 -> V_525 ) {
int V_238 , V_353 ;
T_1 V_352 = 0 ;
struct V_102 * V_103 = V_2 -> V_105 [ V_355 ] ;
for ( V_238 = 0 ; V_238 < V_7 -> V_526 ; V_238 ++ ) {
int V_92 = ( V_7 -> V_525 [ V_238 ] & 0x7f ) * 5 ;
for ( V_353 = 0 ; V_353 < V_103 -> V_367 ; V_353 ++ ) {
if ( V_103 -> V_107 [ V_353 ] . V_108 == V_92 )
V_352 |= F_59 ( V_353 ) ;
}
}
V_12 -> V_26 . V_198 . V_525 = V_352 ;
V_289 |= V_527 ;
}
if ( V_7 -> V_528 >= 0 ) {
if ( V_7 -> V_528 )
V_12 -> V_5 |= V_529 ;
else
V_12 -> V_5 &= ~ V_529 ;
}
if ( V_7 -> V_507 >= 0 ) {
V_12 -> V_26 . V_198 . V_508 =
( T_2 ) V_7 -> V_507 ;
V_289 |= V_509 ;
}
if ( V_7 -> V_321 >= 0 ) {
V_12 -> V_26 . V_198 . V_319 . V_320 &=
~ V_322 ;
V_12 -> V_26 . V_198 . V_319 . V_320 |=
V_7 -> V_321 & V_322 ;
V_289 |= V_302 ;
}
if ( V_7 -> V_323 > 0 ) {
V_12 -> V_26 . V_198 . V_319 . V_320 |=
V_324 ;
V_289 |= V_302 ;
} else if ( V_7 -> V_323 == 0 ) {
V_12 -> V_26 . V_198 . V_319 . V_320 &=
~ V_324 ;
V_289 |= V_302 ;
}
F_93 ( V_12 , V_289 ) ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_530 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_531 V_532 ;
if ( ! V_9 -> V_173 -> V_533 )
return - V_228 ;
if ( V_9 -> V_104 . V_534 < V_158 )
return - V_228 ;
memset ( & V_532 , 0 , sizeof( V_532 ) ) ;
V_532 . V_535 = V_7 -> V_535 ;
V_532 . V_536 = V_7 -> V_537 ;
V_532 . V_538 = V_7 -> V_539 ;
V_532 . V_540 = V_7 -> V_540 ;
V_532 . V_541 = false ;
V_12 -> V_542 [ V_7 -> V_133 ] = V_532 ;
if ( F_175 ( V_9 , V_12 , V_7 -> V_133 , & V_532 ) ) {
F_176 ( V_9 -> V_104 . V_2 ,
L_1 ,
V_7 -> V_133 ) ;
return - V_43 ;
}
F_93 ( V_12 , V_543 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_2 ,
struct V_544 * V_545 )
{
return F_178 ( F_2 ( V_2 ) , V_545 ) ;
}
static int F_179 ( struct V_2 * V_2 )
{
return F_180 ( F_2 ( V_2 ) ) ;
}
static int F_181 ( struct V_2 * V_2 ,
struct V_546 * V_547 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_547 -> V_10 ) ;
switch ( F_182 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_58 :
case V_59 :
case V_67 :
case V_64 :
break;
case V_68 :
if ( V_12 -> V_9 -> V_173 -> V_548 )
break;
case V_56 :
if ( V_12 -> V_15 . V_279 . V_291 &&
( ! ( V_2 -> V_549 & V_550 ) ||
! ( V_547 -> V_5 & V_551 ) ) )
return - V_228 ;
break;
default:
return - V_228 ;
}
return F_183 ( V_12 , V_547 ) ;
}
static int
F_184 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_552 * V_547 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_173 -> V_553 )
return - V_228 ;
return F_185 ( V_12 , V_547 ) ;
}
static int
F_186 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_173 -> V_554 )
return - V_228 ;
return F_187 ( V_12 ) ;
}
static int F_188 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_555 * V_547 )
{
return F_189 ( F_9 ( V_18 ) , V_547 ) ;
}
static int F_190 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_556 * V_547 )
{
return F_191 ( F_9 ( V_18 ) , V_547 ) ;
}
static int F_192 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_557 * V_547 )
{
return F_193 ( F_9 ( V_18 ) , V_547 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_558 * V_547 )
{
return F_195 ( F_9 ( V_18 ) , V_547 ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_559 * V_7 )
{
return F_197 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_198 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_199 ( F_9 ( V_18 ) ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_92 [ V_560 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_198 . V_459 , V_92 ,
sizeof( int ) * V_560 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_2 , T_1 V_289 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_289 & V_561 ) {
V_13 = F_202 ( V_9 , V_2 -> V_562 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_289 & V_563 ) {
V_13 = F_203 ( V_9 , V_2 -> V_564 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_289 & V_565 ) {
V_13 = F_204 ( V_9 , V_2 -> V_566 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_289 & V_567 ) {
if ( V_2 -> V_568 > V_569 )
return - V_43 ;
V_9 -> V_104 . V_47 . V_570 = V_2 -> V_568 ;
}
if ( V_289 & V_571 ) {
if ( V_2 -> V_572 > V_569 )
return - V_43 ;
V_9 -> V_104 . V_47 . V_573 = V_2 -> V_572 ;
}
if ( V_289 &
( V_567 | V_571 ) )
F_83 ( V_9 , V_574 ) ;
return 0 ;
}
static int F_205 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_575 type , int V_576 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_577 :
V_12 -> V_578 = V_579 ;
break;
case V_580 :
case V_581 :
if ( V_576 < 0 || ( V_576 % 100 ) )
return - V_228 ;
V_12 -> V_578 = F_206 ( V_576 ) ;
break;
}
F_207 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_577 :
V_9 -> V_578 = V_579 ;
break;
case V_580 :
case V_581 :
if ( V_576 < 0 || ( V_576 % 100 ) )
return - V_228 ;
V_9 -> V_578 = F_206 ( V_576 ) ;
break;
}
F_24 ( & V_9 -> V_267 ) ;
F_67 (sdata, &local->interfaces, list)
V_12 -> V_578 = V_9 -> V_578 ;
F_67 (sdata, &local->interfaces, list)
F_207 ( V_12 ) ;
F_33 ( & V_9 -> V_267 ) ;
return 0 ;
}
static int F_208 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_582 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_268 )
* V_582 = V_9 -> V_104 . V_47 . V_583 ;
else
* V_582 = V_12 -> V_26 . V_198 . V_584 ;
return 0 ;
}
static int F_209 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_261 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_585 . V_586 , V_261 , V_262 ) ;
return 0 ;
}
static void F_210 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_211 ( V_9 ) ;
}
static int F_212 ( struct V_2 * V_2 , void * V_231 , int V_282 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_173 -> V_587 )
return - V_228 ;
return V_9 -> V_173 -> V_587 ( & V_9 -> V_104 , V_231 , V_282 ) ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_337 * V_338 ,
struct V_588 * V_346 ,
void * V_231 , int V_282 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_173 -> V_589 )
return - V_228 ;
return V_9 -> V_173 -> V_589 ( & V_9 -> V_104 , V_338 , V_346 , V_231 , V_282 ) ;
}
int F_214 ( struct V_11 * V_12 ,
enum V_590 V_304 )
{
const T_3 * V_279 ;
enum V_590 V_591 ;
int V_13 ;
F_215 ( & V_12 -> V_15 . V_25 . V_592 ) ;
V_591 = V_12 -> V_15 . V_25 . V_593 ;
V_12 -> V_15 . V_25 . V_593 = V_304 ;
if ( V_591 == V_304 &&
V_304 != V_594 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_595 ||
V_12 -> V_26 . V_198 . V_265 . V_596 == V_597 )
return 0 ;
V_279 = V_12 -> V_15 . V_25 . V_595 -> V_240 ;
if ( V_304 == V_594 ) {
if ( V_12 -> V_15 . V_25 . V_598 )
V_304 = V_599 ;
else
V_304 = V_305 ;
}
V_13 = F_216 ( V_12 , V_304 ,
V_279 , V_279 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_593 = V_591 ;
return V_13 ;
}
static int F_217 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_600 , int V_601 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_75 ( V_18 -> V_263 ) ;
if ( V_12 -> V_26 . type != V_24 &&
V_12 -> V_26 . type != V_59 )
return - V_228 ;
if ( ! ( V_9 -> V_104 . V_5 & V_602 ) )
return - V_228 ;
if ( V_600 == V_12 -> V_15 . V_25 . V_598 &&
V_601 == V_9 -> V_603 )
return 0 ;
V_12 -> V_15 . V_25 . V_598 = V_600 ;
V_9 -> V_603 = V_601 ;
F_24 ( & V_12 -> V_15 . V_25 . V_592 ) ;
F_214 ( V_12 , V_12 -> V_15 . V_25 . V_593 ) ;
F_33 ( & V_12 -> V_15 . V_25 . V_592 ) ;
if ( V_9 -> V_104 . V_5 & V_604 )
F_83 ( V_9 , V_605 ) ;
F_145 ( V_9 , - 1 ) ;
F_146 ( V_12 ) ;
return 0 ;
}
static int F_218 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_606 , T_1 V_607 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_608 * V_26 = & V_12 -> V_26 ;
struct V_609 * V_198 = & V_26 -> V_198 ;
if ( V_606 == V_198 -> V_610 &&
V_607 == V_198 -> V_611 )
return 0 ;
V_198 -> V_610 = V_606 ;
V_198 -> V_611 = V_607 ;
if ( V_12 -> V_15 . V_25 . V_595 &&
V_12 -> V_26 . V_612 & V_613 )
F_93 ( V_12 , V_614 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_261 ,
const struct V_615 * V_211 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_75 ( V_18 -> V_263 ) ;
int V_238 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_37 ;
if ( V_9 -> V_104 . V_5 & V_616 ) {
V_19 = F_220 ( V_9 , V_12 , V_211 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_238 = 0 ; V_238 < V_560 ; V_238 ++ ) {
struct V_102 * V_103 = V_2 -> V_105 [ V_238 ] ;
int V_353 ;
V_12 -> V_617 [ V_238 ] = V_211 -> V_343 [ V_238 ] . V_106 ;
memcpy ( V_12 -> V_618 [ V_238 ] , V_211 -> V_343 [ V_238 ] . V_97 ,
sizeof( V_211 -> V_343 [ V_238 ] . V_97 ) ) ;
V_12 -> V_619 [ V_238 ] = false ;
if ( ! V_103 )
continue;
for ( V_353 = 0 ; V_353 < V_620 ; V_353 ++ )
if ( ~ V_12 -> V_618 [ V_238 ] [ V_353 ] ) {
V_12 -> V_619 [ V_238 ] = true ;
break;
}
}
return 0 ;
}
static int F_221 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_234 * V_235 ,
unsigned int V_621 , T_4 * V_73 ,
struct V_337 * V_622 ,
enum V_623 type )
{
struct V_624 * V_625 , * V_626 ;
bool V_627 = false ;
int V_19 ;
F_215 ( & V_9 -> V_592 ) ;
if ( V_9 -> V_268 && ! V_9 -> V_173 -> V_628 )
return - V_228 ;
V_625 = F_86 ( sizeof( * V_625 ) , V_280 ) ;
if ( ! V_625 )
return - V_281 ;
V_625 -> V_244 = V_235 ;
V_625 -> V_621 = V_621 ;
V_625 -> V_629 = V_621 ;
V_625 -> V_630 = V_622 ;
V_625 -> type = type ;
V_625 -> V_631 = ( unsigned long ) V_622 ;
V_625 -> V_12 = V_12 ;
F_222 ( & V_625 -> V_632 , V_633 ) ;
F_223 ( & V_625 -> V_634 ) ;
if ( ! F_224 ( & V_9 -> V_635 ) ||
V_9 -> V_636 || V_9 -> V_637 )
goto V_638;
if ( ! V_9 -> V_173 -> V_628 ) {
F_225 ( & V_9 -> V_104 , & V_625 -> V_632 , 0 ) ;
goto V_639;
}
if ( ! V_621 )
V_621 = 10 ;
V_19 = F_226 ( V_9 , V_12 , V_235 , V_621 , type ) ;
if ( V_19 ) {
F_165 ( V_625 ) ;
return V_19 ;
}
V_625 -> V_640 = true ;
goto V_639;
V_638:
F_67 (tmp, &local->roc_list, list) {
if ( V_626 -> V_244 != V_235 || V_626 -> V_12 != V_12 )
continue;
if ( ! V_626 -> V_640 ) {
F_227 ( & V_625 -> V_641 , & V_626 -> V_634 ) ;
V_626 -> V_621 = F_228 ( V_626 -> V_621 , V_625 -> V_621 ) ;
V_626 -> type = F_228 ( V_626 -> type , V_625 -> type ) ;
V_627 = true ;
break;
}
if ( V_9 -> V_173 -> V_628 ) {
unsigned long V_353 = V_155 ;
if ( ! V_626 -> V_642 ) {
F_227 ( & V_625 -> V_641 , & V_626 -> V_634 ) ;
V_627 = true ;
break;
}
if ( F_156 ( V_353 + V_643 ,
V_626 -> V_644 +
F_229 ( V_626 -> V_621 ) ) ) {
int V_645 ;
F_230 ( V_625 ) ;
V_645 = V_625 -> V_621 -
F_55 ( V_626 -> V_644 +
F_229 (
V_626 -> V_621 ) -
V_353 ) ;
if ( V_645 > 0 ) {
F_231 ( & V_625 -> V_641 , & V_626 -> V_641 ) ;
} else {
F_227 ( & V_625 -> V_641 ,
& V_626 -> V_634 ) ;
}
V_627 = true ;
}
} else if ( F_232 ( & V_626 -> V_632 . V_646 ) ) {
unsigned long V_647 ;
F_227 ( & V_625 -> V_641 , & V_626 -> V_634 ) ;
V_627 = true ;
V_647 = V_155 + F_229 ( V_625 -> V_621 ) ;
if ( F_233 ( V_647 , V_626 -> V_632 . V_646 . V_648 ) )
F_234 ( & V_626 -> V_632 . V_646 , V_647 ) ;
else
F_235 ( & V_626 -> V_632 . V_646 ) ;
F_230 ( V_625 ) ;
}
break;
}
V_639:
if ( ! V_627 )
F_227 ( & V_625 -> V_641 , & V_9 -> V_635 ) ;
if ( ! V_622 ) {
V_9 -> V_649 ++ ;
V_625 -> V_73 = V_9 -> V_649 ;
if ( F_65 ( V_625 -> V_73 == 0 ) ) {
V_625 -> V_73 = 1 ;
V_9 -> V_649 ++ ;
}
* V_73 = V_625 -> V_73 ;
} else {
* V_73 = ( unsigned long ) V_622 ;
}
return 0 ;
}
static int F_236 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_234 * V_244 ,
unsigned int V_621 ,
T_4 * V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_24 ( & V_9 -> V_592 ) ;
V_19 = F_221 ( V_9 , V_12 , V_244 ,
V_621 , V_73 , NULL ,
V_650 ) ;
F_33 ( & V_9 -> V_592 ) ;
return V_19 ;
}
static int F_237 ( struct V_8 * V_9 ,
T_4 V_73 , bool V_651 )
{
struct V_624 * V_625 , * V_626 , * V_652 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_592 ) ;
F_238 (roc, tmp, &local->roc_list, list) {
struct V_624 * V_653 , * V_654 ;
F_238 (dep, tmp2, &roc->dependents, list) {
if ( ! V_651 && V_653 -> V_73 != V_73 )
continue;
else if ( V_651 && V_653 -> V_631 != V_73 )
continue;
F_239 ( & V_653 -> V_641 ) ;
F_33 ( & V_9 -> V_592 ) ;
F_240 ( V_653 , true ) ;
return 0 ;
}
if ( ! V_651 && V_625 -> V_73 != V_73 )
continue;
else if ( V_651 && V_625 -> V_631 != V_73 )
continue;
V_652 = V_625 ;
break;
}
if ( ! V_652 ) {
F_33 ( & V_9 -> V_592 ) ;
return - V_51 ;
}
if ( V_9 -> V_173 -> V_628 ) {
if ( V_652 -> V_640 ) {
V_19 = F_241 ( V_9 ) ;
if ( F_31 ( V_19 ) ) {
F_33 ( & V_9 -> V_592 ) ;
return V_19 ;
}
}
F_239 ( & V_652 -> V_641 ) ;
if ( V_652 -> V_640 )
F_242 ( V_9 ) ;
F_33 ( & V_9 -> V_592 ) ;
F_240 ( V_652 , true ) ;
} else {
V_652 -> abort = true ;
F_225 ( & V_9 -> V_104 , & V_652 -> V_632 , 0 ) ;
F_33 ( & V_9 -> V_592 ) ;
F_243 ( & V_652 -> V_632 ) ;
F_65 ( ! V_652 -> V_655 ) ;
F_165 ( V_652 ) ;
}
return 0 ;
}
static int F_244 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_237 ( V_9 , V_73 , false ) ;
}
static int F_245 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_264 * V_265 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
unsigned long V_601 ;
int V_13 ;
if ( ! F_224 ( & V_9 -> V_635 ) || V_9 -> V_636 )
return - V_28 ;
V_12 -> V_304 = V_305 ;
V_12 -> V_306 = V_9 -> V_307 ;
V_12 -> V_308 = true ;
F_24 ( & V_9 -> V_267 ) ;
V_13 = F_82 ( V_12 , V_265 ,
V_309 ) ;
F_33 ( & V_9 -> V_267 ) ;
if ( V_13 )
return V_13 ;
V_601 = F_229 ( V_656 ) ;
F_225 ( & V_12 -> V_9 -> V_104 ,
& V_12 -> V_330 , V_601 ) ;
return 0 ;
}
static int F_246 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_234 * V_244 , bool V_657 ,
unsigned int V_658 , const T_3 * V_659 , T_5 V_282 ,
bool V_660 , bool V_661 , T_4 * V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_337 * V_338 ;
struct V_34 * V_23 ;
const struct V_662 * V_663 = ( void * ) V_659 ;
bool V_664 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_661 )
V_5 = V_665 ;
else
V_5 = V_666 |
V_667 ;
if ( V_660 )
V_5 |= V_668 ;
switch ( V_12 -> V_26 . type ) {
case V_58 :
if ( ! V_12 -> V_26 . V_198 . V_669 )
V_664 = true ;
#ifdef F_30
case V_59 :
if ( F_25 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_60 . V_447 )
V_664 = true ;
#endif
case V_56 :
case V_20 :
case V_68 :
if ( V_12 -> V_26 . type != V_58 &&
! F_25 ( & V_12 -> V_26 ) &&
! F_247 ( V_12 -> V_400 -> V_291 ) )
V_664 = true ;
if ( ! F_248 ( V_663 -> V_670 ) ||
V_663 -> V_15 . V_671 . V_672 == V_673 )
break;
F_39 () ;
V_23 = F_26 ( V_12 , V_663 -> V_339 ) ;
F_43 () ;
if ( ! V_23 )
return - V_674 ;
break;
case V_24 :
case V_67 :
if ( ! V_12 -> V_15 . V_25 . V_595 )
V_664 = true ;
break;
case V_64 :
V_664 = true ;
break;
default:
return - V_228 ;
}
F_24 ( & V_9 -> V_592 ) ;
if ( ! V_664 ) {
struct V_232 * V_233 ;
F_39 () ;
V_233 = F_40 ( V_12 -> V_26 . V_233 ) ;
if ( V_233 )
V_664 = V_244 != V_233 -> V_243 . V_244 ;
else
V_664 = true ;
F_43 () ;
}
if ( V_664 && ! V_657 ) {
V_19 = - V_28 ;
goto V_52;
}
V_338 = F_110 ( V_9 -> V_104 . V_675 + V_282 ) ;
if ( ! V_338 ) {
V_19 = - V_281 ;
goto V_52;
}
F_249 ( V_338 , V_9 -> V_104 . V_675 ) ;
memcpy ( F_111 ( V_338 , V_282 ) , V_659 , V_282 ) ;
F_250 ( V_338 ) -> V_5 = V_5 ;
V_338 -> V_18 = V_12 -> V_18 ;
if ( ! V_664 ) {
* V_73 = ( unsigned long ) V_338 ;
F_251 ( V_12 , V_338 ) ;
V_19 = 0 ;
goto V_52;
}
F_250 ( V_338 ) -> V_5 |= V_676 |
V_677 ;
if ( V_9 -> V_104 . V_5 & V_678 )
F_250 ( V_338 ) -> V_679 =
V_9 -> V_104 . V_680 ;
V_19 = F_221 ( V_9 , V_12 , V_244 ,
V_658 , V_73 , V_338 ,
V_681 ) ;
if ( V_19 )
F_252 ( V_338 ) ;
V_52:
F_33 ( & V_9 -> V_592 ) ;
return V_19 ;
}
static int F_253 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_73 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_237 ( V_9 , V_73 , true ) ;
}
static void F_254 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_682 , bool V_683 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( V_682 ) {
case V_684 | V_685 :
if ( V_12 -> V_26 . type == V_58 ) {
struct V_686 * V_687 = & V_12 -> V_15 . V_688 ;
if ( V_683 )
V_687 -> V_689 ++ ;
else
V_687 -> V_689 -- ;
}
break;
case V_684 | V_690 :
if ( V_683 )
V_9 -> V_691 ++ ;
else
V_9 -> V_691 -- ;
if ( ! V_9 -> V_271 )
break;
F_255 ( & V_9 -> V_104 , & V_9 -> V_692 ) ;
break;
default:
break;
}
}
static int F_256 ( struct V_2 * V_2 , T_1 V_693 , T_1 V_694 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_640 )
return - V_228 ;
return F_257 ( V_9 , V_693 , V_694 ) ;
}
static int F_258 ( struct V_2 * V_2 , T_1 * V_693 , T_1 * V_694 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_259 ( V_9 , V_693 , V_694 ) ;
}
static int F_260 ( struct V_2 * V_2 , T_1 V_80 , T_1 V_695 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_261 ( V_9 , V_80 , V_695 ) ;
}
static void F_262 ( struct V_2 * V_2 ,
T_1 * V_80 , T_1 * V_696 , T_1 * V_695 , T_1 * V_697 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_263 ( V_9 , V_80 , V_696 , V_695 , V_697 ) ;
}
static int F_264 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_698 * V_231 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_173 -> V_699 )
return - V_228 ;
F_265 ( V_9 , V_12 , V_231 ) ;
return 0 ;
}
static void F_266 ( struct V_337 * V_338 )
{
T_3 * V_700 = ( void * ) F_111 ( V_338 , 7 ) ;
* V_700 ++ = V_701 ;
* V_700 ++ = 5 ;
* V_700 ++ = 0x0 ;
* V_700 ++ = 0x0 ;
* V_700 ++ = 0x0 ;
* V_700 ++ = 0x0 ;
* V_700 ++ = V_702 ;
}
static T_2 F_267 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_703 ;
V_703 = 0 ;
if ( F_51 ( V_12 ) != V_704 )
return V_703 ;
if ( ! ( V_9 -> V_104 . V_5 & V_705 ) )
V_703 |= V_706 ;
if ( ! ( V_9 -> V_104 . V_5 & V_707 ) )
V_703 |= V_708 ;
return V_703 ;
}
static void F_268 ( struct V_337 * V_338 , T_3 * V_709 ,
T_3 * V_710 , T_3 * V_240 )
{
struct V_711 * V_712 ;
V_712 = ( void * ) F_111 ( V_338 , sizeof( struct V_711 ) ) ;
V_712 -> V_713 = V_714 ;
V_712 -> V_446 = sizeof( struct V_711 ) - 2 ;
memcpy ( V_712 -> V_240 , V_240 , V_262 ) ;
memcpy ( V_712 -> V_715 , V_709 , V_262 ) ;
memcpy ( V_712 -> V_716 , V_710 , V_262 ) ;
}
static int
F_269 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_710 , T_3 V_717 , T_3 V_718 ,
T_2 V_719 , struct V_337 * V_338 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_354 V_355 = F_51 ( V_12 ) ;
struct V_720 * V_721 ;
V_721 = ( void * ) F_111 ( V_338 , F_270 ( struct V_720 , V_15 ) ) ;
memcpy ( V_721 -> V_339 , V_710 , V_262 ) ;
memcpy ( V_721 -> V_340 , V_12 -> V_26 . V_261 , V_262 ) ;
V_721 -> V_722 = F_271 ( V_723 ) ;
V_721 -> V_724 = V_725 ;
switch ( V_717 ) {
case V_726 :
V_721 -> V_672 = V_727 ;
V_721 -> V_717 = V_726 ;
F_111 ( V_338 , sizeof( V_721 -> V_15 . V_728 ) ) ;
V_721 -> V_15 . V_728 . V_718 = V_718 ;
V_721 -> V_15 . V_728 . V_729 =
F_272 ( F_267 ( V_12 ) ) ;
F_273 ( V_12 , V_338 , false , V_355 ) ;
F_274 ( V_12 , V_338 , false , V_355 ) ;
F_266 ( V_338 ) ;
break;
case V_730 :
V_721 -> V_672 = V_727 ;
V_721 -> V_717 = V_730 ;
F_111 ( V_338 , sizeof( V_721 -> V_15 . V_731 ) ) ;
V_721 -> V_15 . V_731 . V_719 = F_272 ( V_719 ) ;
V_721 -> V_15 . V_731 . V_718 = V_718 ;
V_721 -> V_15 . V_731 . V_729 =
F_272 ( F_267 ( V_12 ) ) ;
F_273 ( V_12 , V_338 , false , V_355 ) ;
F_274 ( V_12 , V_338 , false , V_355 ) ;
F_266 ( V_338 ) ;
break;
case V_732 :
V_721 -> V_672 = V_727 ;
V_721 -> V_717 = V_732 ;
F_111 ( V_338 , sizeof( V_721 -> V_15 . V_733 ) ) ;
V_721 -> V_15 . V_733 . V_719 = F_272 ( V_719 ) ;
V_721 -> V_15 . V_733 . V_718 = V_718 ;
break;
case V_734 :
V_721 -> V_672 = V_727 ;
V_721 -> V_717 = V_734 ;
F_111 ( V_338 , sizeof( V_721 -> V_15 . V_735 ) ) ;
V_721 -> V_15 . V_735 . V_736 = F_272 ( V_719 ) ;
break;
case V_737 :
V_721 -> V_672 = V_727 ;
V_721 -> V_717 = V_737 ;
F_111 ( V_338 , sizeof( V_721 -> V_15 . V_738 ) ) ;
V_721 -> V_15 . V_738 . V_718 = V_718 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int
F_275 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_710 , T_3 V_717 , T_3 V_718 ,
T_2 V_719 , struct V_337 * V_338 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_354 V_355 = F_51 ( V_12 ) ;
struct V_662 * V_663 ;
V_663 = ( void * ) F_111 ( V_338 , 24 ) ;
memset ( V_663 , 0 , 24 ) ;
memcpy ( V_663 -> V_339 , V_710 , V_262 ) ;
memcpy ( V_663 -> V_340 , V_12 -> V_26 . V_261 , V_262 ) ;
memcpy ( V_663 -> V_240 , V_12 -> V_15 . V_25 . V_240 , V_262 ) ;
V_663 -> V_670 = F_272 ( V_684 |
V_739 ) ;
switch ( V_717 ) {
case V_740 :
F_111 ( V_338 , 1 + sizeof( V_663 -> V_15 . V_671 . V_15 . V_741 ) ) ;
V_663 -> V_15 . V_671 . V_672 = V_673 ;
V_663 -> V_15 . V_671 . V_15 . V_741 . V_717 =
V_740 ;
V_663 -> V_15 . V_671 . V_15 . V_741 . V_718 =
V_718 ;
V_663 -> V_15 . V_671 . V_15 . V_741 . V_729 =
F_272 ( F_267 ( V_12 ) ) ;
F_273 ( V_12 , V_338 , false , V_355 ) ;
F_274 ( V_12 , V_338 , false , V_355 ) ;
F_266 ( V_338 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_276 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_710 , T_3 V_717 , T_3 V_718 ,
T_2 V_719 , const T_3 * V_742 ,
T_5 V_743 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_337 * V_338 = NULL ;
bool V_744 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_745 ) )
return - V_504 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_595 )
return - V_43 ;
F_277 ( V_12 , L_2 ,
V_717 , V_710 ) ;
V_338 = F_110 ( V_9 -> V_104 . V_675 +
F_228 ( sizeof( struct V_662 ) ,
sizeof( struct V_720 ) ) +
50 +
7 +
V_743 +
sizeof( struct V_711 ) ) ;
if ( ! V_338 )
return - V_281 ;
F_249 ( V_338 , V_9 -> V_104 . V_675 ) ;
switch ( V_717 ) {
case V_726 :
case V_730 :
case V_732 :
case V_734 :
case V_737 :
V_19 = F_269 ( V_2 , V_18 , V_710 ,
V_717 , V_718 ,
V_719 , V_338 ) ;
V_744 = false ;
break;
case V_740 :
V_19 = F_275 ( V_2 , V_18 , V_710 , V_717 ,
V_718 , V_719 ,
V_338 ) ;
V_744 = true ;
break;
default:
V_19 = - V_504 ;
break;
}
if ( V_19 < 0 )
goto V_746;
if ( V_743 )
memcpy ( F_111 ( V_338 , V_743 ) , V_742 , V_743 ) ;
switch ( V_717 ) {
case V_726 :
case V_732 :
case V_734 :
case V_737 :
F_268 ( V_338 , V_12 -> V_26 . V_261 , V_710 ,
V_12 -> V_15 . V_25 . V_240 ) ;
break;
case V_730 :
case V_740 :
F_268 ( V_338 , V_710 , V_12 -> V_26 . V_261 ,
V_12 -> V_15 . V_25 . V_240 ) ;
break;
default:
V_19 = - V_504 ;
goto V_746;
}
if ( V_744 ) {
F_251 ( V_12 , V_338 ) ;
return 0 ;
}
switch ( V_717 ) {
case V_726 :
case V_730 :
F_278 ( V_338 , V_747 ) ;
V_338 -> V_748 = 2 ;
break;
default:
F_278 ( V_338 , V_749 ) ;
V_338 -> V_748 = 5 ;
break;
}
F_279 () ;
V_19 = F_280 ( V_338 , V_18 ) ;
F_281 () ;
return V_19 ;
V_746:
F_282 ( V_338 ) ;
return V_19 ;
}
static int F_283 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_710 , enum V_750 V_751 )
{
struct V_34 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_745 ) )
return - V_504 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_43 ;
F_277 ( V_12 , L_3 , V_751 , V_710 ) ;
switch ( V_751 ) {
case V_752 :
F_39 () ;
V_23 = F_26 ( V_12 , V_710 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_674 ;
}
F_119 ( V_23 , V_753 ) ;
F_43 () ;
break;
case V_754 :
return F_284 ( V_12 , V_710 ) ;
case V_755 :
case V_756 :
case V_757 :
return - V_504 ;
default:
return - V_504 ;
}
return 0 ;
}
static int F_285 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_710 , T_4 * V_73 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_758 * V_759 ;
struct V_337 * V_338 ;
int V_288 = sizeof( * V_759 ) ;
T_7 V_760 ;
bool V_761 ;
struct V_762 * V_763 ;
struct V_34 * V_23 ;
struct V_232 * V_233 ;
enum V_354 V_355 ;
F_39 () ;
V_233 = F_40 ( V_12 -> V_26 . V_233 ) ;
if ( F_65 ( ! V_233 ) ) {
F_43 () ;
return - V_43 ;
}
V_355 = V_233 -> V_243 . V_244 -> V_355 ;
V_23 = F_26 ( V_12 , V_710 ) ;
if ( V_23 ) {
V_761 = F_28 ( V_23 , V_221 ) ;
} else {
F_43 () ;
return - V_674 ;
}
if ( V_761 ) {
V_760 = F_272 ( V_764 |
V_765 |
V_766 ) ;
} else {
V_288 -= 2 ;
V_760 = F_272 ( V_764 |
V_767 |
V_766 ) ;
}
V_338 = F_110 ( V_9 -> V_104 . V_675 + V_288 ) ;
if ( ! V_338 ) {
F_43 () ;
return - V_281 ;
}
V_338 -> V_18 = V_18 ;
F_249 ( V_338 , V_9 -> V_104 . V_675 ) ;
V_759 = ( void * ) F_111 ( V_338 , V_288 ) ;
V_759 -> V_670 = V_760 ;
V_759 -> V_768 = 0 ;
memcpy ( V_759 -> V_769 , V_23 -> V_23 . V_261 , V_262 ) ;
memcpy ( V_759 -> V_770 , V_12 -> V_26 . V_261 , V_262 ) ;
memcpy ( V_759 -> V_771 , V_12 -> V_26 . V_261 , V_262 ) ;
V_759 -> V_772 = 0 ;
V_763 = F_250 ( V_338 ) ;
V_763 -> V_5 |= V_667 |
V_666 ;
F_278 ( V_338 , V_773 ) ;
V_338 -> V_748 = 7 ;
if ( V_761 )
V_759 -> V_774 = F_272 ( 7 ) ;
F_279 () ;
F_286 ( V_12 , V_338 , V_355 ) ;
F_281 () ;
F_43 () ;
* V_73 = ( unsigned long ) V_338 ;
return 0 ;
}
static int F_287 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_264 * V_265 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_232 * V_233 ;
int V_19 = - V_775 ;
F_39 () ;
V_233 = F_40 ( V_12 -> V_26 . V_233 ) ;
if ( V_233 ) {
* V_265 = V_233 -> V_243 ;
V_19 = 0 ;
} else if ( V_9 -> V_271 > 0 &&
V_9 -> V_271 == V_9 -> V_272 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_268 )
* V_265 = V_9 -> V_266 ;
else
* V_265 = V_9 -> V_273 ;
V_19 = 0 ;
}
F_43 () ;
return V_19 ;
}
static void F_288 ( struct V_2 * V_2 , bool V_600 )
{
F_289 ( F_2 ( V_2 ) , V_600 ) ;
}
