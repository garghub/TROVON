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
struct V_36 * V_23 = NULL ;
struct V_37 * V_38 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_39 ;
switch ( V_7 -> V_40 ) {
case V_41 :
case V_42 :
case V_43 :
if ( F_21 ( V_12 -> V_9 -> V_44 ) )
return - V_45 ;
break;
default:
break;
}
V_38 = F_22 ( V_7 -> V_40 , V_32 , V_7 -> V_46 ,
V_7 -> V_38 , V_7 -> V_47 , V_7 -> V_48 ) ;
if ( F_21 ( V_38 ) )
return F_23 ( V_38 ) ;
if ( V_33 )
V_38 -> V_49 . V_5 |= V_50 ;
F_24 ( & V_12 -> V_9 -> V_51 ) ;
if ( V_34 ) {
if ( F_25 ( & V_12 -> V_26 ) )
V_23 = F_26 ( V_12 , V_34 ) ;
else
V_23 = F_27 ( V_12 , V_34 ) ;
if ( ! V_23 || ! F_28 ( V_23 , V_52 ) ) {
F_29 ( V_38 ) ;
V_13 = - V_53 ;
goto V_54;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_55 != V_56 )
V_38 -> V_49 . V_5 |= V_57 ;
break;
case V_58 :
case V_20 :
if ( V_38 -> V_23 && F_28 ( V_38 -> V_23 , V_59 ) )
V_38 -> V_49 . V_5 |= V_57 ;
break;
case V_60 :
break;
case V_61 :
#ifdef F_30
if ( V_12 -> V_15 . V_62 . V_63 != V_64 )
V_38 -> V_49 . V_5 |= V_57 ;
break;
#endif
case V_65 :
case V_14 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
F_31 ( 1 ) ;
break;
}
V_13 = F_32 ( V_38 , V_12 , V_23 ) ;
V_54:
F_33 ( & V_12 -> V_9 -> V_51 ) ;
return V_13 ;
}
static int F_34 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
struct V_37 * V_38 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_51 ) ;
F_24 ( & V_9 -> V_71 ) ;
if ( V_34 ) {
V_19 = - V_53 ;
V_23 = F_27 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_54;
if ( V_33 )
V_38 = F_35 ( V_9 , V_23 -> V_72 ) ;
else
V_38 = F_35 ( V_9 , V_23 -> V_73 [ V_32 ] ) ;
} else
V_38 = F_35 ( V_9 , V_12 -> V_74 [ V_32 ] ) ;
if ( ! V_38 ) {
V_19 = - V_53 ;
goto V_54;
}
F_36 ( V_38 , true ) ;
V_19 = 0 ;
V_54:
F_33 ( & V_9 -> V_71 ) ;
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 ,
void * V_75 ,
void (* F_38)( void * V_75 ,
struct V_35 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_36 * V_23 = NULL ;
T_3 V_48 [ 6 ] = { 0 } ;
struct V_35 V_7 ;
struct V_37 * V_38 = NULL ;
T_4 V_76 ;
T_1 V_77 ;
T_2 V_78 ;
int V_13 = - V_53 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
if ( V_34 ) {
V_23 = F_27 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_79;
if ( V_33 )
V_38 = F_40 ( V_23 -> V_72 ) ;
else if ( V_32 < V_80 )
V_38 = F_40 ( V_23 -> V_73 [ V_32 ] ) ;
} else
V_38 = F_40 ( V_12 -> V_74 [ V_32 ] ) ;
if ( ! V_38 )
goto V_79;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_40 = V_38 -> V_49 . V_40 ;
switch ( V_38 -> V_49 . V_40 ) {
case V_42 :
V_77 = V_38 -> V_15 . V_81 . V_82 . V_77 ;
V_78 = V_38 -> V_15 . V_81 . V_82 . V_78 ;
if ( V_38 -> V_5 & V_83 )
F_41 ( V_12 -> V_9 ,
V_38 -> V_49 . V_84 ,
& V_77 , & V_78 ) ;
V_48 [ 0 ] = V_78 & 0xff ;
V_48 [ 1 ] = ( V_78 >> 8 ) & 0xff ;
V_48 [ 2 ] = V_77 & 0xff ;
V_48 [ 3 ] = ( V_77 >> 8 ) & 0xff ;
V_48 [ 4 ] = ( V_77 >> 16 ) & 0xff ;
V_48 [ 5 ] = ( V_77 >> 24 ) & 0xff ;
V_7 . V_48 = V_48 ;
V_7 . V_47 = 6 ;
break;
case V_85 :
V_76 = F_42 ( & V_38 -> V_15 . V_86 . V_87 ) ;
V_48 [ 0 ] = V_76 ;
V_48 [ 1 ] = V_76 >> 8 ;
V_48 [ 2 ] = V_76 >> 16 ;
V_48 [ 3 ] = V_76 >> 24 ;
V_48 [ 4 ] = V_76 >> 32 ;
V_48 [ 5 ] = V_76 >> 40 ;
V_7 . V_48 = V_48 ;
V_7 . V_47 = 6 ;
break;
case V_88 :
V_76 = F_42 ( & V_38 -> V_15 . V_89 . V_87 ) ;
V_48 [ 0 ] = V_76 ;
V_48 [ 1 ] = V_76 >> 8 ;
V_48 [ 2 ] = V_76 >> 16 ;
V_48 [ 3 ] = V_76 >> 24 ;
V_48 [ 4 ] = V_76 >> 32 ;
V_48 [ 5 ] = V_76 >> 40 ;
V_7 . V_48 = V_48 ;
V_7 . V_47 = 6 ;
break;
}
V_7 . V_38 = V_38 -> V_49 . V_38 ;
V_7 . V_46 = V_38 -> V_49 . V_90 ;
F_38 ( V_75 , & V_7 ) ;
V_13 = 0 ;
V_79:
F_43 () ;
return V_13 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 , bool V_91 ,
bool V_92 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_45 ( V_12 , V_32 , V_91 , V_92 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_32 ) ;
return 0 ;
}
void F_48 ( struct V_36 * V_23 ,
const struct V_93 * V_94 ,
struct V_95 * V_96 )
{
V_96 -> V_5 = 0 ;
if ( V_94 -> V_5 & V_97 ) {
V_96 -> V_5 |= V_98 ;
V_96 -> V_99 = V_94 -> V_100 ;
} else if ( V_94 -> V_5 & V_101 ) {
V_96 -> V_5 |= V_102 ;
V_96 -> V_99 = F_49 ( V_94 ) ;
V_96 -> V_103 = F_50 ( V_94 ) ;
} else {
struct V_104 * V_105 ;
int V_106 = F_51 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_107 ;
V_105 = V_23 -> V_9 -> V_108 . V_2 -> V_109 [
F_52 ( V_23 -> V_12 ) ] ;
V_107 = V_105 -> V_110 [ V_94 -> V_100 ] . V_111 ;
V_96 -> V_112 = F_53 ( V_107 , 1 << V_106 ) ;
}
if ( V_94 -> V_5 & V_113 )
V_96 -> V_5 |= V_114 ;
if ( V_94 -> V_5 & V_115 )
V_96 -> V_5 |= V_116 ;
if ( V_94 -> V_5 & V_117 )
V_96 -> V_5 |= V_118 ;
if ( V_94 -> V_5 & V_119 )
V_96 -> V_5 |= V_120 ;
}
void F_54 ( struct V_36 * V_23 , struct V_95 * V_96 )
{
V_96 -> V_5 = 0 ;
if ( V_23 -> V_121 & V_122 ) {
V_96 -> V_5 |= V_98 ;
V_96 -> V_99 = V_23 -> V_123 ;
} else if ( V_23 -> V_121 & V_124 ) {
V_96 -> V_5 |= V_102 ;
V_96 -> V_103 = V_23 -> V_125 ;
V_96 -> V_99 = V_23 -> V_123 ;
} else {
struct V_104 * V_105 ;
int V_106 = F_51 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_107 ;
V_105 = V_23 -> V_9 -> V_108 . V_2 -> V_109 [
F_52 ( V_23 -> V_12 ) ] ;
V_107 = V_105 -> V_110 [ V_23 -> V_123 ] . V_111 ;
V_96 -> V_112 = F_53 ( V_107 , 1 << V_106 ) ;
}
if ( V_23 -> V_121 & V_126 )
V_96 -> V_5 |= V_114 ;
if ( V_23 -> V_121 & V_127 )
V_96 -> V_5 |= V_120 ;
if ( V_23 -> V_121 & V_128 )
V_96 -> V_5 |= V_116 ;
if ( V_23 -> V_121 & V_129 )
V_96 -> V_5 |= V_130 ;
if ( V_23 -> V_121 & V_131 )
V_96 -> V_5 |= V_118 ;
}
static void F_55 ( struct V_36 * V_23 , struct V_132 * V_133 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_134 V_135 ;
T_4 V_136 = 0 ;
int V_137 , V_138 ;
V_133 -> V_139 = V_12 -> V_9 -> V_140 ;
V_133 -> V_141 = V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 |
V_155 ;
F_56 ( & V_135 ) ;
V_133 -> V_156 = V_135 . V_157 - V_23 -> V_158 ;
V_133 -> V_159 = F_57 ( V_160 - V_23 -> V_161 ) ;
V_133 -> V_162 = 0 ;
for ( V_138 = 0 ; V_138 < V_163 ; V_138 ++ ) {
V_133 -> V_162 += V_23 -> V_162 [ V_138 ] ;
V_136 += V_23 -> V_164 [ V_138 ] ;
}
V_133 -> V_164 = V_136 ;
V_133 -> V_165 = V_23 -> V_165 ;
V_133 -> V_166 = V_23 -> V_166 ;
V_133 -> V_167 = V_23 -> V_168 ;
V_133 -> V_169 = V_23 -> V_170 ;
V_133 -> V_171 = V_23 -> V_172 ;
V_133 -> V_173 = V_23 -> V_173 ;
if ( ( V_23 -> V_9 -> V_108 . V_5 & V_174 ) ||
( V_23 -> V_9 -> V_108 . V_5 & V_175 ) ) {
V_133 -> V_141 |= V_176 | V_177 ;
if ( ! V_9 -> V_178 -> V_179 ||
F_58 ( V_9 , V_12 , & V_23 -> V_23 , & V_133 -> signal ) )
V_133 -> signal = ( V_180 ) V_23 -> V_181 ;
V_133 -> V_182 = ( V_180 ) - F_59 ( & V_23 -> V_183 ) ;
}
if ( V_23 -> V_184 ) {
V_133 -> V_141 |= V_185 |
V_186 ;
V_133 -> V_184 = V_23 -> V_184 ;
for ( V_137 = 0 ; V_137 < F_60 ( V_133 -> V_187 ) ; V_137 ++ ) {
V_133 -> V_187 [ V_137 ] = V_23 -> V_188 [ V_137 ] ;
V_133 -> V_189 [ V_137 ] =
( V_180 ) - F_59 ( & V_23 -> V_189 [ V_137 ] ) ;
}
}
F_48 ( V_23 , & V_23 -> V_190 , & V_133 -> V_191 ) ;
F_54 ( V_23 , & V_133 -> V_192 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
V_133 -> V_141 |= V_193 |
V_194 |
V_195 |
V_196 |
V_197 |
V_198 ;
V_133 -> V_199 = F_61 ( V_23 -> V_199 ) ;
V_133 -> V_200 = F_61 ( V_23 -> V_200 ) ;
V_133 -> V_201 = V_23 -> V_201 ;
if ( F_28 ( V_23 , V_202 ) ) {
V_133 -> V_141 |= V_203 ;
V_133 -> V_204 = V_23 -> V_204 ;
}
V_133 -> V_205 = V_23 -> V_205 ;
V_133 -> V_206 = V_23 -> V_206 ;
V_133 -> V_207 = V_23 -> V_207 ;
#endif
}
V_133 -> V_208 . V_5 = 0 ;
if ( V_12 -> V_26 . V_209 . V_210 )
V_133 -> V_208 . V_5 |= V_211 ;
if ( V_12 -> V_26 . V_209 . V_212 )
V_133 -> V_208 . V_5 |= V_213 ;
if ( V_12 -> V_26 . V_209 . V_214 )
V_133 -> V_208 . V_5 |= V_215 ;
V_133 -> V_208 . V_216 = V_12 -> V_9 -> V_108 . V_49 . V_217 ;
V_133 -> V_208 . V_218 = V_12 -> V_26 . V_209 . V_219 ;
V_133 -> V_220 . V_221 = 0 ;
V_133 -> V_220 . V_27 = F_62 ( V_222 ) |
F_62 ( V_223 ) |
F_62 ( V_224 ) |
F_62 ( V_225 ) |
F_62 ( V_226 ) |
F_62 ( V_227 ) |
F_62 ( V_228 ) ;
if ( F_28 ( V_23 , V_229 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_222 ) ;
if ( F_28 ( V_23 , V_230 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_223 ) ;
if ( F_28 ( V_23 , V_231 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_224 ) ;
if ( F_28 ( V_23 , V_59 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_225 ) ;
if ( F_28 ( V_23 , V_232 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_226 ) ;
if ( F_28 ( V_23 , V_52 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_227 ) ;
if ( F_28 ( V_23 , V_233 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_228 ) ;
}
static int F_63 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_234 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_235 = 0 ;
if ( V_234 == V_236 )
V_235 += V_237 ;
V_235 += F_64 ( V_12 , V_234 ) ;
if ( V_235 == 0 )
return - V_238 ;
return V_235 ;
}
static void F_65 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_239 * V_240 ,
T_4 * V_241 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_242 * V_243 ;
struct V_244 * V_245 ;
struct V_36 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_132 V_133 ;
struct V_246 V_247 ;
int V_137 , V_248 ;
#define F_66 7
memset ( V_241 , 0 , sizeof( T_4 ) * V_237 ) ;
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
F_24 ( & V_9 -> V_51 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_27 ( V_12 , V_12 -> V_15 . V_25 . V_249 ) ;
if ( ! ( V_23 && ! F_68 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_250;
V_133 . V_141 = 0 ;
F_55 ( V_23 , & V_133 ) ;
V_137 = 0 ;
F_67 ( V_23 ) ;
V_241 [ V_137 ++ ] = V_23 -> V_251 ;
if ( V_133 . V_141 & V_149 )
V_241 [ V_137 ] = 100000 *
F_69 ( & V_133 . V_191 ) ;
V_137 ++ ;
if ( V_133 . V_141 & V_150 )
V_241 [ V_137 ] = 100000 *
F_69 ( & V_133 . V_192 ) ;
V_137 ++ ;
if ( V_133 . V_141 & V_177 )
V_241 [ V_137 ] = ( T_3 ) V_133 . V_182 ;
V_137 ++ ;
} else {
F_70 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_133 . V_141 = 0 ;
F_55 ( V_23 , & V_133 ) ;
V_137 = 0 ;
F_67 ( V_23 ) ;
}
}
V_250:
V_137 = V_237 - F_66 ;
V_247 . V_141 = 0 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( V_243 )
V_245 = V_243 -> V_252 . V_253 ;
else
V_245 = NULL ;
F_43 () ;
if ( V_245 ) {
V_248 = 0 ;
do {
V_247 . V_141 = 0 ;
if ( F_71 ( V_9 , V_248 , & V_247 ) != 0 ) {
V_247 . V_141 = 0 ;
break;
}
V_248 ++ ;
} while ( V_245 != V_247 . V_245 );
}
if ( V_247 . V_141 )
V_241 [ V_137 ++ ] = V_247 . V_245 -> V_254 ;
else
V_241 [ V_137 ++ ] = 0 ;
if ( V_247 . V_141 & V_255 )
V_241 [ V_137 ++ ] = ( T_3 ) V_247 . V_256 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_257 )
V_241 [ V_137 ++ ] = V_247 . V_258 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_259 )
V_241 [ V_137 ++ ] = V_247 . V_260 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_261 )
V_241 [ V_137 ++ ] = V_247 . V_262 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_263 )
V_241 [ V_137 ++ ] = V_247 . V_264 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_265 )
V_241 [ V_137 ++ ] = V_247 . V_266 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
F_33 ( & V_9 -> V_51 ) ;
if ( F_68 ( V_137 != V_237 ) )
return;
F_72 ( V_12 , V_240 , & ( V_241 [ V_237 ] ) ) ;
}
static void F_73 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_234 , T_3 * V_241 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_267 = 0 ;
if ( V_234 == V_236 ) {
V_267 = sizeof( V_268 ) ;
memcpy ( V_241 , V_268 , V_267 ) ;
}
F_74 ( V_12 , V_234 , & ( V_241 [ V_267 ] ) ) ;
}
static int F_75 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , T_3 * V_269 , struct V_132 * V_133 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_53 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_76 ( V_12 , V_100 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_269 , V_23 -> V_23 . V_270 , V_271 ) ;
F_55 ( V_23 , V_133 ) ;
}
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , struct V_246 * V_247 )
{
struct V_8 * V_9 = F_78 ( V_18 -> V_272 ) ;
return F_71 ( V_9 , V_100 , V_247 ) ;
}
static int F_79 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_269 , struct V_132 * V_133 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_53 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_27 ( V_12 , V_269 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_55 ( V_23 , V_133 ) ;
}
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_80 ( struct V_2 * V_2 ,
struct V_273 * V_274 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_81 ( & V_9 -> V_275 , V_274 ) )
return 0 ;
F_24 ( & V_9 -> V_276 ) ;
if ( V_9 -> V_277 ) {
V_12 = F_82 (
V_9 -> V_278 ,
F_83 ( & V_9 -> V_276 ) ) ;
if ( V_12 ) {
F_84 ( V_12 ) ;
V_19 = F_85 ( V_12 , V_274 ,
V_279 ) ;
}
} else if ( V_9 -> V_280 == V_9 -> V_281 ) {
V_9 -> V_282 = * V_274 ;
F_86 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_275 = * V_274 ;
F_33 ( & V_9 -> V_276 ) ;
return V_19 ;
}
static int F_87 ( struct V_11 * V_12 ,
const T_3 * V_283 , T_5 V_284 )
{
struct V_285 * V_286 , * V_287 ;
if ( ! V_283 || ! V_284 )
return 1 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_285 ) ;
V_286 = F_89 ( sizeof( struct V_285 ) + V_284 , V_289 ) ;
if ( ! V_286 )
return - V_290 ;
V_286 -> V_291 = V_284 ;
memcpy ( V_286 -> V_241 , V_283 , V_284 ) ;
F_90 ( V_12 -> V_15 . V_288 . V_285 , V_286 ) ;
if ( V_287 )
F_91 ( V_287 , V_292 ) ;
return 0 ;
}
int F_92 ( struct V_11 * V_12 ,
struct V_293 * V_7 )
{
struct V_294 * V_286 , * V_287 ;
int V_295 , V_296 ;
int V_297 , V_13 ;
T_1 V_298 = V_299 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( ! V_7 -> V_301 && ! V_287 )
return - V_45 ;
if ( V_7 -> V_301 )
V_295 = V_7 -> V_302 ;
else
V_295 = V_287 -> V_302 ;
if ( V_7 -> V_303 || ! V_287 )
V_296 = V_7 -> V_304 ;
else
V_296 = V_287 -> V_304 ;
V_297 = sizeof( * V_286 ) + V_295 + V_296 ;
V_286 = F_89 ( V_297 , V_289 ) ;
if ( ! V_286 )
return - V_290 ;
V_286 -> V_301 = ( ( T_3 * ) V_286 ) + sizeof( * V_286 ) ;
V_286 -> V_303 = V_286 -> V_301 + V_295 ;
V_286 -> V_302 = V_295 ;
V_286 -> V_304 = V_296 ;
if ( V_7 -> V_301 )
memcpy ( V_286 -> V_301 , V_7 -> V_301 , V_295 ) ;
else
memcpy ( V_286 -> V_301 , V_287 -> V_301 , V_295 ) ;
if ( V_7 -> V_303 )
memcpy ( V_286 -> V_303 , V_7 -> V_303 , V_296 ) ;
else
if ( V_287 )
memcpy ( V_286 -> V_303 , V_287 -> V_303 , V_296 ) ;
V_13 = F_87 ( V_12 , V_7 -> V_285 ,
V_7 -> V_305 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_298 |= V_306 ;
F_90 ( V_12 -> V_15 . V_288 . V_300 , V_286 ) ;
if ( V_287 )
F_91 ( V_287 , V_292 ) ;
return V_298 ;
}
static int F_93 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_307 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_294 * V_287 ;
struct V_11 * V_22 ;
T_1 V_298 = V_308 |
V_309 |
V_299 |
V_310 |
V_311 ;
int V_13 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( V_287 )
return - V_312 ;
V_12 -> V_313 = V_314 ;
V_12 -> V_315 = V_12 -> V_9 -> V_316 ;
V_12 -> V_317 = V_7 -> V_317 ;
V_13 = F_85 ( V_12 , & V_7 -> V_274 ,
V_318 ) ;
if ( V_13 )
return V_13 ;
F_94 ( V_12 , false ) ;
V_12 -> V_319 = V_7 -> V_320 . V_321 ;
V_12 -> V_322 = V_7 -> V_320 . V_322 ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_319 =
V_7 -> V_320 . V_321 ;
V_22 -> V_322 =
V_7 -> V_320 . V_322 ;
}
V_12 -> V_26 . V_209 . V_219 = V_7 -> V_218 ;
V_12 -> V_26 . V_209 . V_216 = V_7 -> V_216 ;
V_12 -> V_26 . V_209 . V_323 = true ;
V_12 -> V_26 . V_209 . V_324 = V_7 -> V_324 ;
if ( V_7 -> V_324 )
memcpy ( V_12 -> V_26 . V_209 . V_325 , V_7 -> V_325 ,
V_7 -> V_324 ) ;
V_12 -> V_26 . V_209 . V_326 =
( V_7 -> V_326 != V_327 ) ;
memset ( & V_12 -> V_26 . V_209 . V_328 , 0 ,
sizeof( V_12 -> V_26 . V_209 . V_328 ) ) ;
V_12 -> V_26 . V_209 . V_328 . V_329 =
V_7 -> V_330 & V_331 ;
if ( V_7 -> V_332 )
V_12 -> V_26 . V_209 . V_328 . V_329 |=
V_333 ;
V_13 = F_92 ( V_12 , & V_7 -> V_300 ) ;
if ( V_13 < 0 )
return V_13 ;
V_298 |= V_13 ;
V_13 = F_95 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( V_287 )
F_91 ( V_287 , V_292 ) ;
F_11 ( V_12 -> V_15 . V_288 . V_300 , NULL ) ;
return V_13 ;
}
F_96 ( V_12 , V_298 ) ;
F_97 ( V_18 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_97 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_98 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_293 * V_7 )
{
struct V_11 * V_12 ;
struct V_294 * V_287 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
if ( V_12 -> V_26 . V_334 )
return - V_30 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( ! V_287 )
return - V_53 ;
V_13 = F_92 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_96 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_294 * V_335 ;
struct V_285 * V_336 ;
V_335 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( ! V_335 )
return - V_53 ;
V_336 = F_88 ( V_12 -> V_15 . V_288 . V_285 ) ;
V_12 -> V_26 . V_334 = false ;
F_100 ( & V_12 -> V_337 ) ;
F_100 ( & V_12 -> V_15 . V_288 . V_338 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_101 ( V_22 -> V_18 ) ;
F_101 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_288 . V_300 , NULL ) ;
F_11 ( V_12 -> V_15 . V_288 . V_285 , NULL ) ;
F_91 ( V_335 , V_292 ) ;
if ( V_336 )
F_91 ( V_336 , V_292 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_102 ( V_22 ) ;
F_102 ( V_12 ) ;
F_103 () ;
F_104 () ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
F_105 ( V_22 ) ;
F_106 ( V_22 ) ;
}
F_105 ( V_12 ) ;
F_106 ( V_12 ) ;
V_12 -> V_26 . V_209 . V_323 = false ;
V_12 -> V_26 . V_209 . V_324 = 0 ;
F_107 ( V_339 , & V_12 -> V_340 ) ;
F_96 ( V_12 , V_309 ) ;
if ( V_12 -> V_10 . V_341 ) {
F_108 ( & V_12 -> V_342 ) ;
F_109 ( V_12 -> V_18 , V_343 ,
V_289 ) ;
}
F_110 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_344 -= F_111 ( & V_12 -> V_15 . V_288 . V_345 . V_346 ) ;
F_112 ( & V_12 -> V_15 . V_288 . V_345 . V_346 ) ;
F_94 ( V_12 , true ) ;
F_84 ( V_12 ) ;
return 0 ;
}
static void F_113 ( struct V_36 * V_23 )
{
struct V_347 * V_348 ;
struct V_349 * V_350 ;
V_350 = F_114 ( sizeof( * V_348 ) ) ;
if ( ! V_350 )
return;
V_348 = (struct V_347 * ) F_115 ( V_350 , sizeof( * V_348 ) ) ;
F_116 ( V_348 -> V_351 ) ;
memcpy ( V_348 -> V_352 , V_23 -> V_23 . V_270 , V_271 ) ;
V_348 -> V_291 = F_117 ( 6 ) ;
V_348 -> V_353 = 0 ;
V_348 -> V_354 = 0x01 ;
V_348 -> V_355 = 0xaf ;
V_348 -> V_356 [ 0 ] = 0x81 ;
V_348 -> V_356 [ 1 ] = 1 ;
V_348 -> V_356 [ 2 ] = 0 ;
V_350 -> V_18 = V_23 -> V_12 -> V_18 ;
V_350 -> V_357 = F_118 ( V_350 , V_23 -> V_12 -> V_18 ) ;
memset ( V_350 -> V_358 , 0 , sizeof( V_350 -> V_358 ) ) ;
F_119 ( V_350 ) ;
}
static int F_120 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
T_1 V_27 , T_1 V_221 )
{
int V_19 ;
if ( V_27 & F_62 ( V_226 ) &&
V_221 & F_62 ( V_226 ) &&
! F_28 ( V_23 , V_232 ) ) {
V_19 = F_121 ( V_23 , V_359 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_227 ) &&
V_221 & F_62 ( V_227 ) &&
! F_28 ( V_23 , V_52 ) ) {
V_19 = F_121 ( V_23 , V_360 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_222 ) ) {
if ( V_221 & F_62 ( V_222 ) )
V_19 = F_121 ( V_23 , V_361 ) ;
else if ( F_28 ( V_23 , V_229 ) )
V_19 = F_121 ( V_23 , V_360 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_227 ) &&
! ( V_221 & F_62 ( V_227 ) ) &&
F_28 ( V_23 , V_52 ) ) {
V_19 = F_121 ( V_23 , V_359 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_226 ) &&
! ( V_221 & F_62 ( V_226 ) ) &&
F_28 ( V_23 , V_232 ) ) {
V_19 = F_121 ( V_23 , V_362 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_122 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
struct V_363 * V_7 )
{
int V_19 = 0 ;
struct V_104 * V_105 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_364 V_365 = F_52 ( V_12 ) ;
T_1 V_27 , V_221 ;
V_105 = V_9 -> V_108 . V_2 -> V_109 [ V_365 ] ;
V_27 = V_7 -> V_366 ;
V_221 = V_7 -> V_367 ;
if ( F_25 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_62 ( V_226 ) )
V_27 |= F_62 ( V_227 ) ;
if ( V_221 & F_62 ( V_226 ) )
V_221 |= F_62 ( V_227 ) ;
} else if ( F_28 ( V_23 , V_233 ) ) {
if ( V_221 & F_62 ( V_222 ) ) {
V_221 |= F_62 ( V_226 ) |
F_62 ( V_227 ) ;
V_27 |= F_62 ( V_226 ) |
F_62 ( V_227 ) ;
}
}
V_19 = F_120 ( V_9 , V_23 , V_27 , V_221 ) ;
if ( V_19 )
return V_19 ;
if ( V_27 & F_62 ( V_223 ) ) {
if ( V_221 & F_62 ( V_223 ) )
F_123 ( V_23 , V_230 ) ;
else
F_124 ( V_23 , V_230 ) ;
}
if ( V_27 & F_62 ( V_224 ) ) {
if ( V_221 & F_62 ( V_224 ) ) {
F_123 ( V_23 , V_231 ) ;
V_23 -> V_23 . V_368 = true ;
} else {
F_124 ( V_23 , V_231 ) ;
V_23 -> V_23 . V_368 = false ;
}
}
if ( V_27 & F_62 ( V_225 ) ) {
if ( V_221 & F_62 ( V_225 ) )
F_123 ( V_23 , V_59 ) ;
else
F_124 ( V_23 , V_59 ) ;
}
if ( V_27 & F_62 ( V_228 ) ) {
if ( V_221 & F_62 ( V_228 ) )
F_123 ( V_23 , V_233 ) ;
else
F_124 ( V_23 , V_233 ) ;
}
if ( V_7 -> V_369 & V_370 ) {
V_23 -> V_23 . V_371 = V_7 -> V_371 ;
V_23 -> V_23 . V_372 = V_7 -> V_372 ;
}
if ( V_7 -> V_373 )
V_23 -> V_23 . V_373 = V_7 -> V_373 ;
if ( V_7 -> V_374 >= 0 )
V_23 -> V_374 = V_7 -> V_374 ;
if ( V_7 -> V_375 ) {
F_125 ( & V_12 -> V_26 . V_209 . V_274 ,
V_105 , V_7 -> V_375 ,
V_7 -> V_376 ,
& V_23 -> V_23 . V_377 [ V_365 ] ) ;
}
if ( V_7 -> V_378 )
F_126 ( V_12 , V_105 ,
V_7 -> V_378 , V_23 ) ;
if ( V_7 -> V_379 )
F_127 ( V_12 , V_105 ,
V_7 -> V_379 , V_23 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
T_1 V_298 = 0 ;
if ( V_7 -> V_369 & V_380 ) {
switch ( V_7 -> V_201 ) {
case V_381 :
if ( V_23 -> V_201 != V_381 )
V_298 = F_128 (
V_12 ) ;
V_23 -> V_201 = V_7 -> V_201 ;
F_129 ( V_23 ) ;
V_298 |= F_130 ( V_23 ,
V_12 -> V_15 . V_62 . V_382 . V_383 ) ;
break;
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
if ( V_23 -> V_201 == V_381 )
V_298 = F_131 (
V_12 ) ;
V_23 -> V_201 = V_7 -> V_201 ;
F_129 ( V_23 ) ;
V_298 |= F_130 ( V_23 ,
V_390 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_391 ) {
case V_392 :
break;
case V_393 :
V_298 |= F_132 ( V_23 ) ;
break;
case V_394 :
V_298 |= F_133 ( V_23 ) ;
break;
}
if ( V_7 -> V_205 )
V_298 |=
F_130 ( V_23 ,
V_7 -> V_205 ) ;
F_134 ( V_12 , V_298 ) ;
#endif
}
return 0 ;
}
static int F_135 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_269 , struct V_363 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_395 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_58 )
return - V_45 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_136 ( V_269 , V_12 -> V_26 . V_270 ) )
return - V_45 ;
if ( F_137 ( V_269 ) )
return - V_45 ;
V_23 = F_138 ( V_12 , V_269 , V_289 ) ;
if ( ! V_23 )
return - V_290 ;
if ( ! ( V_7 -> V_367 & F_62 ( V_228 ) ) ) {
F_139 ( V_23 , V_359 ) ;
F_139 ( V_23 , V_360 ) ;
}
V_13 = F_122 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_140 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_28 ( V_23 , V_233 ) )
F_141 ( V_23 ) ;
V_395 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_58 ;
V_13 = F_142 ( V_23 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
if ( V_395 )
F_113 ( V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_269 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_269 )
return F_144 ( V_12 , V_269 ) ;
F_145 ( V_12 ) ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_3 * V_269 ,
struct V_363 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_396 ;
enum V_397 V_398 ;
int V_13 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_27 ( V_12 , V_269 ) ;
if ( ! V_23 ) {
V_13 = - V_53 ;
goto V_399;
}
switch ( V_12 -> V_26 . type ) {
case V_61 :
if ( V_12 -> V_15 . V_62 . V_400 )
V_398 = V_401 ;
else
V_398 = V_402 ;
break;
case V_60 :
V_398 = V_403 ;
break;
case V_24 :
if ( ! F_28 ( V_23 , V_233 ) ) {
V_398 = V_404 ;
break;
}
if ( F_28 ( V_23 , V_229 ) )
V_398 = V_405 ;
else
V_398 = V_406 ;
break;
case V_58 :
case V_20 :
V_398 = V_407 ;
break;
default:
V_13 = - V_238 ;
goto V_399;
}
V_13 = F_147 ( V_2 , V_7 , V_398 ) ;
if ( V_13 )
goto V_399;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_408 = false ;
bool V_409 = false ;
V_396 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_272 -> V_21 ) {
if ( V_396 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_399;
}
F_90 ( V_396 -> V_15 . V_22 . V_23 , V_23 ) ;
V_409 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_90 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_408 = true ;
}
V_23 -> V_12 = V_396 ;
if ( V_23 -> V_251 == V_361 &&
V_408 != V_409 ) {
if ( V_409 )
F_148 ( & V_23 -> V_12 -> V_410 -> V_411 ) ;
else
F_149 ( & V_23 -> V_12 -> V_410 -> V_411 ) ;
}
F_113 ( V_23 ) ;
}
V_13 = F_122 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_399;
if ( F_28 ( V_23 , V_233 ) &&
F_28 ( V_23 , V_229 ) )
F_141 ( V_23 ) ;
F_33 ( & V_9 -> V_51 ) ;
if ( ( V_12 -> V_26 . type == V_58 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_412 != V_23 -> V_12 -> V_410 -> V_413 &&
F_28 ( V_23 , V_229 ) &&
F_150 ( V_23 ) != 1 ) {
F_151 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_270 ) ;
F_152 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_410 -> V_413 ,
V_23 -> V_23 . V_270 ,
V_23 -> V_12 -> V_26 . V_209 . V_249 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_366 & F_62 ( V_222 ) ) {
F_153 ( V_9 , - 1 ) ;
F_154 ( V_12 ) ;
}
return 0 ;
V_399:
F_33 ( & V_9 -> V_51 ) ;
return V_13 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_414 , T_3 * V_415 )
{
struct V_11 * V_12 ;
struct V_416 * V_417 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_415 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_53 ;
}
V_417 = F_156 ( V_12 , V_414 ) ;
if ( F_21 ( V_417 ) ) {
F_43 () ;
return F_23 ( V_417 ) ;
}
F_157 ( V_417 , V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_414 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_414 )
return F_159 ( V_12 , V_414 ) ;
F_160 ( V_12 ) ;
return 0 ;
}
static int F_161 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_414 , T_3 * V_415 )
{
struct V_11 * V_12 ;
struct V_416 * V_417 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_415 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_53 ;
}
V_417 = F_162 ( V_12 , V_414 ) ;
if ( ! V_417 ) {
F_43 () ;
return - V_53 ;
}
F_157 ( V_417 , V_23 ) ;
F_43 () ;
return 0 ;
}
static void F_163 ( struct V_416 * V_417 , T_3 * V_415 ,
struct V_418 * V_419 )
{
struct V_36 * V_420 = F_40 ( V_417 -> V_415 ) ;
if ( V_420 )
memcpy ( V_415 , V_420 -> V_23 . V_270 , V_271 ) ;
else
memset ( V_415 , 0 , V_271 ) ;
memset ( V_419 , 0 , sizeof( * V_419 ) ) ;
V_419 -> V_139 = V_421 ;
V_419 -> V_141 = V_422 |
V_423 |
V_424 |
V_425 |
V_426 |
V_427 |
V_428 ;
V_419 -> V_429 = V_417 -> V_430 . V_431 ;
V_419 -> V_432 = V_417 -> V_432 ;
V_419 -> V_433 = V_417 -> V_433 ;
if ( F_164 ( V_160 , V_417 -> V_434 ) )
V_419 -> V_435 = F_57 ( V_417 -> V_434 - V_160 ) ;
V_419 -> V_436 =
F_57 ( V_417 -> V_436 ) ;
V_419 -> V_437 = V_417 -> V_437 ;
if ( V_417 -> V_5 & V_438 )
V_419 -> V_5 |= V_439 ;
if ( V_417 -> V_5 & V_440 )
V_419 -> V_5 |= V_441 ;
if ( V_417 -> V_5 & V_442 )
V_419 -> V_5 |= V_443 ;
if ( V_417 -> V_5 & V_444 )
V_419 -> V_5 |= V_445 ;
if ( V_417 -> V_5 & V_446 )
V_419 -> V_5 |= V_447 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_414 , T_3 * V_415 , struct V_418 * V_419 )
{
struct V_11 * V_12 ;
struct V_416 * V_417 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_417 = F_162 ( V_12 , V_414 ) ;
if ( ! V_417 ) {
F_43 () ;
return - V_53 ;
}
memcpy ( V_414 , V_417 -> V_414 , V_271 ) ;
F_163 ( V_417 , V_415 , V_419 ) ;
F_43 () ;
return 0 ;
}
static int F_166 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , T_3 * V_414 , T_3 * V_415 ,
struct V_418 * V_419 )
{
struct V_11 * V_12 ;
struct V_416 * V_417 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_417 = F_167 ( V_12 , V_100 ) ;
if ( ! V_417 ) {
F_43 () ;
return - V_53 ;
}
memcpy ( V_414 , V_417 -> V_414 , V_271 ) ;
F_163 ( V_417 , V_415 , V_419 ) ;
F_43 () ;
return 0 ;
}
static int F_168 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_448 * V_49 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_49 , & ( V_12 -> V_15 . V_62 . V_382 ) , sizeof( struct V_448 ) ) ;
return 0 ;
}
static inline bool F_169 ( enum V_449 V_450 , T_1 V_27 )
{
return ( V_27 >> ( V_450 - 1 ) ) & 0x1 ;
}
static int F_170 ( struct V_451 * V_452 ,
const struct V_453 * V_454 )
{
T_3 * V_455 ;
const T_3 * V_456 ;
struct V_11 * V_12 = F_171 ( V_452 ,
struct V_11 , V_15 . V_62 ) ;
V_455 = NULL ;
V_456 = V_452 -> V_457 ;
if ( V_454 -> V_458 ) {
V_455 = F_172 ( V_454 -> V_457 , V_454 -> V_458 ,
V_289 ) ;
if ( ! V_455 )
return - V_290 ;
}
V_452 -> V_458 = V_454 -> V_458 ;
V_452 -> V_457 = V_455 ;
F_173 ( V_456 ) ;
V_452 -> V_459 = V_454 -> V_459 ;
memcpy ( V_452 -> V_460 , V_454 -> V_460 , V_452 -> V_459 ) ;
V_452 -> V_461 = V_454 -> V_462 ;
V_452 -> V_463 = V_454 -> V_464 ;
V_452 -> V_465 = V_454 -> V_466 ;
V_452 -> V_400 = V_454 -> V_400 ;
V_452 -> V_467 = V_454 -> V_468 ;
V_452 -> V_63 = V_64 ;
if ( V_454 -> V_469 )
V_452 -> V_63 |= V_470 ;
if ( V_454 -> V_471 )
V_452 -> V_63 |= V_472 ;
memcpy ( V_12 -> V_26 . V_209 . V_473 , V_454 -> V_473 ,
sizeof( V_454 -> V_473 ) ) ;
V_12 -> V_26 . V_209 . V_474 = V_454 -> V_474 ;
V_12 -> V_26 . V_209 . V_219 = V_454 -> V_218 ;
V_12 -> V_26 . V_209 . V_216 = V_454 -> V_216 ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_448 * V_475 )
{
struct V_448 * V_49 ;
struct V_11 * V_12 ;
struct V_451 * V_452 ;
V_12 = F_9 ( V_18 ) ;
V_452 = & V_12 -> V_15 . V_62 ;
V_49 = & ( V_12 -> V_15 . V_62 . V_382 ) ;
if ( F_169 ( V_476 , V_27 ) )
V_49 -> V_477 = V_475 -> V_477 ;
if ( F_169 ( V_478 , V_27 ) )
V_49 -> V_479 = V_475 -> V_479 ;
if ( F_169 ( V_480 , V_27 ) )
V_49 -> V_481 = V_475 -> V_481 ;
if ( F_169 ( V_482 , V_27 ) )
V_49 -> V_483 = V_475 -> V_483 ;
if ( F_169 ( V_484 , V_27 ) )
V_49 -> V_485 = V_475 -> V_485 ;
if ( F_169 ( V_486 , V_27 ) )
V_49 -> V_487 = V_475 -> V_487 ;
if ( F_169 ( V_488 , V_27 ) )
V_49 -> V_489 = V_475 -> V_489 ;
if ( F_169 ( V_490 , V_27 ) ) {
if ( V_452 -> V_400 )
return - V_30 ;
V_49 -> V_491 = V_475 -> V_491 ;
}
if ( F_169 ( V_492 , V_27 ) )
V_49 -> V_493 =
V_475 -> V_493 ;
if ( F_169 ( V_494 , V_27 ) )
V_49 -> V_495 =
V_475 -> V_495 ;
if ( F_169 ( V_496 , V_27 ) )
V_49 -> V_497 = V_475 -> V_497 ;
if ( F_169 ( V_498 , V_27 ) )
V_49 -> V_499 = V_475 -> V_499 ;
if ( F_169 ( V_500 , V_27 ) )
V_49 -> V_501 =
V_475 -> V_501 ;
if ( F_169 ( V_502 , V_27 ) )
V_49 -> V_503 =
V_475 -> V_503 ;
if ( F_169 ( V_504 , V_27 ) )
V_49 -> V_505 =
V_475 -> V_505 ;
if ( F_169 ( V_506 ,
V_27 ) )
V_49 -> V_507 =
V_475 -> V_507 ;
if ( F_169 ( V_508 , V_27 ) ) {
V_49 -> V_509 = V_475 -> V_509 ;
F_175 ( V_452 ) ;
}
if ( F_169 ( V_510 , V_27 ) ) {
if ( V_475 -> V_511 &&
! ( V_49 -> V_509 > V_512 ) ) {
V_49 -> V_509 = V_513 ;
F_175 ( V_452 ) ;
}
V_49 -> V_511 =
V_475 -> V_511 ;
}
if ( F_169 ( V_514 , V_27 ) )
V_49 -> V_515 =
V_475 -> V_515 ;
if ( F_169 ( V_516 , V_27 ) )
V_49 -> V_517 = V_475 -> V_517 ;
if ( F_169 ( V_518 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_108 . V_5 & V_174 ) )
return - V_519 ;
V_49 -> V_520 = V_475 -> V_520 ;
}
if ( F_169 ( V_521 , V_27 ) ) {
V_49 -> V_522 = V_475 -> V_522 ;
V_12 -> V_26 . V_209 . V_523 = V_475 -> V_522 ;
F_96 ( V_12 , V_524 ) ;
}
if ( F_169 ( V_525 , V_27 ) )
V_49 -> V_526 =
V_475 -> V_526 ;
if ( F_169 ( V_527 , V_27 ) )
V_49 -> V_528 =
V_475 -> V_528 ;
if ( F_169 ( V_529 , V_27 ) )
V_49 -> V_530 =
V_475 -> V_530 ;
if ( F_169 ( V_531 , V_27 ) ) {
V_49 -> V_383 = V_475 -> V_383 ;
F_176 ( V_12 ) ;
}
if ( F_169 ( V_532 , V_27 ) )
V_49 -> V_533 =
V_475 -> V_533 ;
if ( F_169 ( V_534 , V_27 ) )
V_49 -> V_535 = V_475 -> V_535 ;
F_134 ( V_12 , V_299 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_448 * V_49 ,
const struct V_453 * V_454 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_451 * V_452 = & V_12 -> V_15 . V_62 ;
int V_13 ;
memcpy ( & V_452 -> V_382 , V_49 , sizeof( struct V_448 ) ) ;
V_13 = F_170 ( V_452 , V_454 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_313 = V_314 ;
V_12 -> V_315 = V_12 -> V_9 -> V_316 ;
V_13 = F_85 ( V_12 , & V_454 -> V_274 ,
V_318 ) ;
if ( V_13 )
return V_13 ;
return F_178 ( V_12 ) ;
}
static int F_179 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_180 ( V_12 ) ;
F_84 ( V_12 ) ;
return 0 ;
}
static int F_181 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_536 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_364 V_365 ;
T_1 V_298 = 0 ;
if ( ! F_88 ( V_12 -> V_15 . V_288 . V_300 ) )
return - V_53 ;
V_365 = F_52 ( V_12 ) ;
if ( V_7 -> V_210 >= 0 ) {
V_12 -> V_26 . V_209 . V_210 = V_7 -> V_210 ;
V_298 |= V_537 ;
}
if ( V_7 -> V_212 >= 0 ) {
V_12 -> V_26 . V_209 . V_212 =
V_7 -> V_212 ;
V_298 |= V_538 ;
}
if ( ! V_12 -> V_26 . V_209 . V_214 &&
V_365 == V_539 ) {
V_12 -> V_26 . V_209 . V_214 = true ;
V_298 |= V_540 ;
}
if ( V_7 -> V_541 >= 0 ) {
V_12 -> V_26 . V_209 . V_214 =
V_7 -> V_541 ;
V_298 |= V_540 ;
}
if ( V_7 -> V_474 ) {
F_125 ( & V_12 -> V_26 . V_209 . V_274 ,
V_2 -> V_109 [ V_365 ] ,
V_7 -> V_474 ,
V_7 -> V_542 ,
& V_12 -> V_26 . V_209 . V_474 ) ;
V_298 |= V_543 ;
}
if ( V_7 -> V_544 >= 0 ) {
if ( V_7 -> V_544 )
V_12 -> V_5 |= V_545 ;
else
V_12 -> V_5 &= ~ V_545 ;
}
if ( V_7 -> V_522 >= 0 ) {
V_12 -> V_26 . V_209 . V_523 =
( T_2 ) V_7 -> V_522 ;
V_298 |= V_524 ;
}
if ( V_7 -> V_330 >= 0 ) {
V_12 -> V_26 . V_209 . V_328 . V_329 &=
~ V_331 ;
V_12 -> V_26 . V_209 . V_328 . V_329 |=
V_7 -> V_330 & V_331 ;
V_298 |= V_311 ;
}
if ( V_7 -> V_332 > 0 ) {
V_12 -> V_26 . V_209 . V_328 . V_329 |=
V_333 ;
V_298 |= V_311 ;
} else if ( V_7 -> V_332 == 0 ) {
V_12 -> V_26 . V_209 . V_328 . V_329 &=
~ V_333 ;
V_298 |= V_311 ;
}
F_96 ( V_12 , V_298 ) ;
return 0 ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_546 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_547 V_548 ;
if ( ! V_9 -> V_178 -> V_549 )
return - V_238 ;
if ( V_9 -> V_108 . V_550 < V_163 )
return - V_238 ;
memset ( & V_548 , 0 , sizeof( V_548 ) ) ;
V_548 . V_551 = V_7 -> V_551 ;
V_548 . V_552 = V_7 -> V_553 ;
V_548 . V_554 = V_7 -> V_555 ;
V_548 . V_556 = V_7 -> V_556 ;
V_548 . V_557 = false ;
V_12 -> V_558 [ V_7 -> V_138 ] = V_548 ;
if ( F_183 ( V_9 , V_12 , V_7 -> V_138 , & V_548 ) ) {
F_184 ( V_9 -> V_108 . V_2 ,
L_2 ,
V_7 -> V_138 ) ;
return - V_45 ;
}
F_96 ( V_12 , V_559 ) ;
return 0 ;
}
static int F_185 ( struct V_2 * V_2 ,
struct V_560 * V_561 )
{
return F_186 ( F_2 ( V_2 ) , V_561 ) ;
}
static int F_187 ( struct V_2 * V_2 )
{
return F_188 ( F_2 ( V_2 ) ) ;
}
static int F_189 ( struct V_2 * V_2 ,
struct V_562 * V_563 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_563 -> V_10 ) ;
switch ( F_190 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_60 :
case V_61 :
case V_69 :
case V_66 :
break;
case V_70 :
if ( V_12 -> V_9 -> V_178 -> V_564 )
break;
case V_58 :
if ( V_12 -> V_15 . V_288 . V_300 &&
( ! ( V_2 -> V_565 & V_566 ) ||
! ( V_563 -> V_5 & V_567 ) ) )
return - V_238 ;
break;
default:
return - V_238 ;
}
return F_191 ( V_12 , V_563 ) ;
}
static int
F_192 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_568 * V_563 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_178 -> V_569 )
return - V_238 ;
return F_193 ( V_12 , V_563 ) ;
}
static int
F_194 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_178 -> V_570 )
return - V_238 ;
return F_195 ( V_12 ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_571 * V_563 )
{
return F_197 ( F_9 ( V_18 ) , V_563 ) ;
}
static int F_198 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_572 * V_563 )
{
return F_199 ( F_9 ( V_18 ) , V_563 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_573 * V_563 )
{
return F_201 ( F_9 ( V_18 ) , V_563 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_574 * V_563 )
{
return F_203 ( F_9 ( V_18 ) , V_563 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_575 * V_7 )
{
return F_205 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_207 ( F_9 ( V_18 ) ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_94 [ V_576 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_209 . V_473 , V_94 ,
sizeof( int ) * V_576 ) ;
return 0 ;
}
static int F_209 ( struct V_2 * V_2 , T_1 V_298 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_298 & V_577 ) {
V_13 = F_210 ( V_9 , V_2 -> V_578 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_298 & V_579 ) {
V_13 = F_211 ( V_9 , V_2 -> V_580 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_298 & V_581 ) {
V_13 = F_212 ( V_9 , V_2 -> V_582 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_298 & V_583 ) {
if ( V_2 -> V_584 > V_585 )
return - V_45 ;
V_9 -> V_108 . V_49 . V_586 = V_2 -> V_584 ;
}
if ( V_298 & V_587 ) {
if ( V_2 -> V_588 > V_585 )
return - V_45 ;
V_9 -> V_108 . V_49 . V_589 = V_2 -> V_588 ;
}
if ( V_298 &
( V_583 | V_587 ) )
F_86 ( V_9 , V_590 ) ;
return 0 ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_591 type , int V_592 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_593 :
V_12 -> V_594 = V_595 ;
break;
case V_596 :
case V_597 :
if ( V_592 < 0 || ( V_592 % 100 ) )
return - V_238 ;
V_12 -> V_594 = F_214 ( V_592 ) ;
break;
}
F_215 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_593 :
V_9 -> V_594 = V_595 ;
break;
case V_596 :
case V_597 :
if ( V_592 < 0 || ( V_592 % 100 ) )
return - V_238 ;
V_9 -> V_594 = F_214 ( V_592 ) ;
break;
}
F_24 ( & V_9 -> V_276 ) ;
F_70 (sdata, &local->interfaces, list)
V_12 -> V_594 = V_9 -> V_594 ;
F_70 (sdata, &local->interfaces, list)
F_215 ( V_12 ) ;
F_33 ( & V_9 -> V_276 ) ;
return 0 ;
}
static int F_216 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_598 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_277 )
* V_598 = V_9 -> V_108 . V_49 . V_599 ;
else
* V_598 = V_12 -> V_26 . V_209 . V_600 ;
return 0 ;
}
static int F_217 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_270 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_601 . V_602 , V_270 , V_271 ) ;
return 0 ;
}
static void F_218 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_219 ( V_9 ) ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_241 , int V_291 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_603 * V_26 = NULL ;
if ( ! V_9 -> V_178 -> V_604 )
return - V_238 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_605 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_178 -> V_604 ( & V_9 -> V_108 , V_26 , V_241 , V_291 ) ;
}
static int F_221 ( struct V_2 * V_2 ,
struct V_349 * V_350 ,
struct V_606 * V_358 ,
void * V_241 , int V_291 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_178 -> V_607 )
return - V_238 ;
return V_9 -> V_178 -> V_607 ( & V_9 -> V_108 , V_350 , V_358 , V_241 , V_291 ) ;
}
int F_222 ( struct V_11 * V_12 ,
enum V_608 V_313 )
{
struct V_36 * V_23 ;
enum V_608 V_609 ;
int V_137 ;
if ( F_31 ( V_12 -> V_26 . type != V_58 ) )
return - V_45 ;
if ( V_12 -> V_26 . V_209 . V_274 . V_610 == V_611 )
return 0 ;
V_609 = V_12 -> V_15 . V_288 . V_413 ;
V_12 -> V_15 . V_288 . V_413 = V_313 ;
if ( V_609 == V_313 ||
V_313 == V_612 )
return 0 ;
if ( ! F_223 ( & V_12 -> V_15 . V_288 . V_411 ) ) {
V_12 -> V_313 = V_313 ;
F_224 ( & V_12 -> V_9 -> V_108 , & V_12 -> V_613 ) ;
return 0 ;
}
F_151 ( V_12 ,
L_3 ,
V_313 , F_223 ( & V_12 -> V_15 . V_288 . V_411 ) ) ;
F_24 ( & V_12 -> V_9 -> V_51 ) ;
for ( V_137 = 0 ; V_137 < V_614 ; V_137 ++ ) {
for ( V_23 = F_82 ( V_12 -> V_9 -> V_615 [ V_137 ] ,
F_83 ( & V_12 -> V_9 -> V_51 ) ) ;
V_23 ;
V_23 = F_82 ( V_23 -> V_616 ,
F_83 ( & V_12 -> V_9 -> V_51 ) ) ) {
if ( V_23 -> V_12 -> V_410 != & V_12 -> V_15 . V_288 )
continue;
if ( F_150 ( V_23 ) == 1 )
continue;
if ( F_28 ( V_23 , V_617 ) &&
! F_225 ( V_23 -> V_412 ,
V_313 ) ) {
F_151 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_270 ) ;
continue;
}
if ( ! F_28 ( V_23 , V_229 ) )
continue;
F_151 ( V_12 , L_5 , V_23 -> V_23 . V_270 ) ;
F_152 ( V_12 , V_313 ,
V_23 -> V_23 . V_270 ,
V_12 -> V_26 . V_209 . V_249 ) ;
}
}
F_33 ( & V_12 -> V_9 -> V_51 ) ;
V_12 -> V_313 = V_313 ;
F_224 ( & V_12 -> V_9 -> V_108 , & V_12 -> V_613 ) ;
return 0 ;
}
int F_226 ( struct V_11 * V_12 ,
enum V_608 V_313 )
{
const T_3 * V_288 ;
enum V_608 V_609 ;
int V_13 ;
F_227 ( & V_12 -> V_10 . V_618 ) ;
if ( F_31 ( V_12 -> V_26 . type != V_24 ) )
return - V_45 ;
V_609 = V_12 -> V_15 . V_25 . V_413 ;
V_12 -> V_15 . V_25 . V_413 = V_313 ;
if ( V_609 == V_313 &&
V_313 != V_612 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_619 ||
V_12 -> V_26 . V_209 . V_274 . V_610 == V_611 )
return 0 ;
V_288 = V_12 -> V_15 . V_25 . V_619 -> V_249 ;
if ( V_313 == V_612 ) {
if ( V_12 -> V_15 . V_25 . V_620 )
V_313 = V_621 ;
else
V_313 = V_314 ;
}
V_13 = F_152 ( V_12 , V_313 ,
V_288 , V_288 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_413 = V_609 ;
return V_13 ;
}
static int F_228 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_622 , int V_623 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_272 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_238 ;
if ( ! ( V_9 -> V_108 . V_5 & V_624 ) )
return - V_238 ;
if ( V_622 == V_12 -> V_15 . V_25 . V_620 &&
V_623 == V_9 -> V_625 )
return 0 ;
V_12 -> V_15 . V_25 . V_620 = V_622 ;
V_9 -> V_625 = V_623 ;
F_229 ( V_12 ) ;
F_226 ( V_12 , V_12 -> V_15 . V_25 . V_413 ) ;
F_230 ( V_12 ) ;
if ( V_9 -> V_108 . V_5 & V_626 )
F_86 ( V_9 , V_627 ) ;
F_153 ( V_9 , - 1 ) ;
F_154 ( V_12 ) ;
return 0 ;
}
static int F_231 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_628 , T_1 V_629 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_603 * V_26 = & V_12 -> V_26 ;
struct V_630 * V_209 = & V_26 -> V_209 ;
if ( V_628 == V_209 -> V_631 &&
V_629 == V_209 -> V_632 )
return 0 ;
V_209 -> V_631 = V_628 ;
V_209 -> V_632 = V_629 ;
if ( V_12 -> V_15 . V_25 . V_619 &&
V_12 -> V_26 . V_633 & V_634 )
F_96 ( V_12 , V_635 ) ;
return 0 ;
}
static int F_232 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_270 ,
const struct V_636 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_272 ) ;
int V_137 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_39 ;
if ( V_9 -> V_108 . V_5 & V_637 ) {
V_19 = F_233 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_137 = 0 ; V_137 < V_576 ; V_137 ++ ) {
struct V_104 * V_105 = V_2 -> V_109 [ V_137 ] ;
int V_638 ;
V_12 -> V_639 [ V_137 ] = V_27 -> V_355 [ V_137 ] . V_112 ;
memcpy ( V_12 -> V_640 [ V_137 ] , V_27 -> V_355 [ V_137 ] . V_99 ,
sizeof( V_27 -> V_355 [ V_137 ] . V_99 ) ) ;
V_12 -> V_641 [ V_137 ] = false ;
if ( ! V_105 )
continue;
for ( V_638 = 0 ; V_638 < V_642 ; V_638 ++ )
if ( ~ V_12 -> V_640 [ V_137 ] [ V_638 ] ) {
V_12 -> V_641 [ V_137 ] = true ;
break;
}
}
return 0 ;
}
static int F_234 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_244 * V_245 ,
unsigned int V_643 , T_4 * V_75 ,
struct V_349 * V_644 ,
enum V_645 type )
{
struct V_646 * V_647 , * V_648 ;
bool V_649 = false ;
int V_19 ;
F_227 ( & V_9 -> V_618 ) ;
if ( V_9 -> V_277 && ! V_9 -> V_178 -> V_650 )
return - V_238 ;
V_647 = F_89 ( sizeof( * V_647 ) , V_289 ) ;
if ( ! V_647 )
return - V_290 ;
V_647 -> V_253 = V_245 ;
V_647 -> V_643 = V_643 ;
V_647 -> V_651 = V_643 ;
V_647 -> V_652 = V_644 ;
V_647 -> type = type ;
V_647 -> V_653 = ( unsigned long ) V_644 ;
V_647 -> V_12 = V_12 ;
F_235 ( & V_647 -> V_654 , V_655 ) ;
F_236 ( & V_647 -> V_656 ) ;
if ( ! F_237 ( & V_9 -> V_657 ) ||
V_9 -> V_658 || V_9 -> V_659 )
goto V_660;
if ( ! V_9 -> V_178 -> V_650 ) {
F_238 ( & V_9 -> V_108 , & V_647 -> V_654 , 0 ) ;
goto V_661;
}
if ( ! V_643 )
V_643 = 10 ;
V_19 = F_239 ( V_9 , V_12 , V_245 , V_643 , type ) ;
if ( V_19 ) {
F_173 ( V_647 ) ;
return V_19 ;
}
V_647 -> V_662 = true ;
goto V_661;
V_660:
F_70 (tmp, &local->roc_list, list) {
if ( V_648 -> V_253 != V_245 || V_648 -> V_12 != V_12 )
continue;
if ( ! V_648 -> V_662 ) {
F_240 ( & V_647 -> V_663 , & V_648 -> V_656 ) ;
V_648 -> V_643 = F_241 ( V_648 -> V_643 , V_647 -> V_643 ) ;
V_648 -> type = F_241 ( V_648 -> type , V_647 -> type ) ;
V_649 = true ;
break;
}
if ( V_9 -> V_178 -> V_650 ) {
unsigned long V_638 = V_160 ;
if ( ! V_648 -> V_664 ) {
F_240 ( & V_647 -> V_663 , & V_648 -> V_656 ) ;
V_649 = true ;
break;
}
if ( F_164 ( V_638 + V_665 ,
V_648 -> V_666 +
F_242 ( V_648 -> V_643 ) ) ) {
int V_667 ;
F_243 ( V_647 ) ;
V_667 = V_647 -> V_643 -
F_57 ( V_648 -> V_666 +
F_242 (
V_648 -> V_643 ) -
V_638 ) ;
if ( V_667 > 0 ) {
F_244 ( & V_647 -> V_663 , & V_648 -> V_663 ) ;
} else {
F_240 ( & V_647 -> V_663 ,
& V_648 -> V_656 ) ;
}
V_649 = true ;
}
} else if ( F_245 ( & V_648 -> V_654 . V_668 ) ) {
unsigned long V_669 ;
F_240 ( & V_647 -> V_663 , & V_648 -> V_656 ) ;
V_649 = true ;
V_669 = V_160 + F_242 ( V_647 -> V_643 ) ;
if ( F_246 ( V_669 , V_648 -> V_654 . V_668 . V_670 ) )
F_247 ( & V_648 -> V_654 . V_668 , V_669 ) ;
else
F_248 ( & V_648 -> V_654 . V_668 ) ;
F_243 ( V_647 ) ;
}
break;
}
V_661:
if ( ! V_649 )
F_240 ( & V_647 -> V_663 , & V_9 -> V_657 ) ;
if ( ! V_644 ) {
V_9 -> V_671 ++ ;
V_647 -> V_75 = V_9 -> V_671 ;
if ( F_68 ( V_647 -> V_75 == 0 ) ) {
V_647 -> V_75 = 1 ;
V_9 -> V_671 ++ ;
}
* V_75 = V_647 -> V_75 ;
} else {
* V_75 = ( unsigned long ) V_644 ;
}
return 0 ;
}
static int F_249 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_244 * V_253 ,
unsigned int V_643 ,
T_4 * V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_24 ( & V_9 -> V_618 ) ;
V_19 = F_234 ( V_9 , V_12 , V_253 ,
V_643 , V_75 , NULL ,
V_672 ) ;
F_33 ( & V_9 -> V_618 ) ;
return V_19 ;
}
static int F_250 ( struct V_8 * V_9 ,
T_4 V_75 , bool V_673 )
{
struct V_646 * V_647 , * V_648 , * V_674 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_618 ) ;
F_251 (roc, tmp, &local->roc_list, list) {
struct V_646 * V_675 , * V_676 ;
F_251 (dep, tmp2, &roc->dependents, list) {
if ( ! V_673 && V_675 -> V_75 != V_75 )
continue;
else if ( V_673 && V_675 -> V_653 != V_75 )
continue;
F_252 ( & V_675 -> V_663 ) ;
F_33 ( & V_9 -> V_618 ) ;
F_253 ( V_675 , true ) ;
return 0 ;
}
if ( ! V_673 && V_647 -> V_75 != V_75 )
continue;
else if ( V_673 && V_647 -> V_653 != V_75 )
continue;
V_674 = V_647 ;
break;
}
if ( ! V_674 ) {
F_33 ( & V_9 -> V_618 ) ;
return - V_53 ;
}
if ( V_9 -> V_178 -> V_650 ) {
if ( V_674 -> V_662 ) {
V_19 = F_254 ( V_9 ) ;
if ( F_31 ( V_19 ) ) {
F_33 ( & V_9 -> V_618 ) ;
return V_19 ;
}
}
F_252 ( & V_674 -> V_663 ) ;
if ( V_674 -> V_662 )
F_255 ( V_9 ) ;
F_33 ( & V_9 -> V_618 ) ;
F_253 ( V_674 , true ) ;
} else {
V_674 -> abort = true ;
F_238 ( & V_9 -> V_108 , & V_674 -> V_654 , 0 ) ;
F_33 ( & V_9 -> V_618 ) ;
F_256 ( & V_674 -> V_654 ) ;
F_68 ( ! V_674 -> V_677 ) ;
F_173 ( V_674 ) ;
}
return 0 ;
}
static int F_257 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_250 ( V_9 , V_75 , false ) ;
}
static int F_258 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_273 * V_274 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
unsigned long V_623 ;
int V_13 ;
if ( ! F_237 ( & V_9 -> V_657 ) || V_9 -> V_658 )
return - V_30 ;
V_12 -> V_313 = V_314 ;
V_12 -> V_315 = V_9 -> V_316 ;
V_12 -> V_317 = true ;
F_24 ( & V_9 -> V_276 ) ;
V_13 = F_85 ( V_12 , V_274 ,
V_318 ) ;
F_33 ( & V_9 -> V_276 ) ;
if ( V_13 )
return V_13 ;
V_623 = F_242 ( V_678 ) ;
F_238 ( & V_12 -> V_9 -> V_108 ,
& V_12 -> V_342 , V_623 ) ;
return 0 ;
}
static struct V_293 *
F_259 ( struct V_293 * V_300 )
{
struct V_293 * V_679 ;
T_3 * V_680 ;
int V_291 ;
V_291 = V_300 -> V_302 + V_300 -> V_304 + V_300 -> V_681 +
V_300 -> V_682 + V_300 -> V_683 +
V_300 -> V_305 ;
V_679 = F_89 ( sizeof( * V_679 ) + V_291 , V_289 ) ;
if ( ! V_679 )
return NULL ;
V_680 = ( T_3 * ) ( V_679 + 1 ) ;
if ( V_300 -> V_302 ) {
V_679 -> V_302 = V_300 -> V_302 ;
V_679 -> V_301 = V_680 ;
memcpy ( V_680 , V_300 -> V_301 , V_300 -> V_302 ) ;
V_680 += V_300 -> V_302 ;
}
if ( V_300 -> V_304 ) {
V_679 -> V_304 = V_300 -> V_304 ;
V_679 -> V_303 = V_680 ;
memcpy ( V_680 , V_300 -> V_303 , V_300 -> V_304 ) ;
V_680 += V_300 -> V_304 ;
}
if ( V_300 -> V_681 ) {
V_679 -> V_681 = V_300 -> V_681 ;
V_679 -> V_684 = V_680 ;
memcpy ( V_680 , V_300 -> V_684 , V_300 -> V_681 ) ;
V_680 += V_300 -> V_681 ;
}
if ( V_300 -> V_682 ) {
V_679 -> V_682 = V_300 -> V_682 ;
V_679 -> V_685 = V_680 ;
memcpy ( V_680 , V_300 -> V_685 , V_300 -> V_682 ) ;
V_680 += V_300 -> V_682 ;
}
if ( V_300 -> V_683 ) {
V_679 -> V_683 = V_300 -> V_683 ;
V_679 -> V_686 = V_680 ;
memcpy ( V_680 , V_300 -> V_686 , V_300 -> V_683 ) ;
V_680 += V_300 -> V_683 ;
}
if ( V_300 -> V_305 ) {
V_679 -> V_305 = V_300 -> V_305 ;
V_300 -> V_285 = V_680 ;
memcpy ( V_680 , V_300 -> V_285 , V_300 -> V_305 ) ;
V_680 += V_300 -> V_305 ;
}
return V_679 ;
}
void F_260 ( struct V_687 * V_654 )
{
struct V_11 * V_12 =
F_171 ( V_654 , struct V_11 ,
V_337 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 , V_298 = 0 ;
if ( ! F_12 ( V_12 ) )
return;
V_12 -> V_317 = V_12 -> V_688 ;
V_13 = F_261 ( V_12 , & V_9 -> V_689 ,
& V_298 ) ;
if ( F_68 ( V_13 < 0 ) )
return;
if ( ! V_9 -> V_277 ) {
V_9 -> V_282 = V_9 -> V_689 ;
F_86 ( V_9 , 0 ) ;
}
F_96 ( V_12 , V_298 ) ;
switch ( V_12 -> V_26 . type ) {
case V_58 :
V_13 = F_92 ( V_12 , V_12 -> V_15 . V_288 . V_690 ) ;
if ( V_13 < 0 )
return;
V_298 |= V_13 ;
F_173 ( V_12 -> V_15 . V_288 . V_690 ) ;
V_12 -> V_15 . V_288 . V_690 = NULL ;
F_96 ( V_12 , V_13 ) ;
break;
case V_60 :
F_262 ( V_12 ) ;
break;
#ifdef F_30
case V_61 :
V_13 = F_263 ( V_12 ) ;
if ( V_13 < 0 )
return;
break;
#endif
default:
F_68 ( 1 ) ;
return;
}
V_12 -> V_26 . V_334 = false ;
F_264 ( & V_12 -> V_9 -> V_108 ,
V_691 ,
V_692 ) ;
F_265 ( V_12 -> V_18 , & V_9 -> V_689 ) ;
}
static int F_266 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_693 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_242 * V_243 ;
struct V_694 * V_695 ;
struct V_451 T_7 * V_452 ;
int V_13 , V_696 ;
if ( ! F_237 ( & V_9 -> V_657 ) || V_9 -> V_658 )
return - V_30 ;
if ( V_12 -> V_10 . V_341 )
return - V_30 ;
if ( F_81 ( & V_7 -> V_274 ,
& V_12 -> V_26 . V_209 . V_274 ) )
return - V_45 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( ! V_243 ) {
F_43 () ;
return - V_30 ;
}
V_695 = F_171 ( V_243 , struct V_694 , V_49 ) ;
if ( V_695 -> V_697 > 1 ) {
F_43 () ;
return - V_30 ;
}
V_696 = 0 ;
F_267 (chanctx, &local->chanctx_list, list)
V_696 ++ ;
F_43 () ;
if ( V_696 > 1 )
return - V_30 ;
if ( V_12 -> V_26 . V_334 )
return - V_30 ;
switch ( V_12 -> V_26 . type ) {
case V_58 :
V_12 -> V_698 =
V_7 -> V_699 ;
V_12 -> V_700 = V_7 -> V_701 ;
V_12 -> V_15 . V_288 . V_690 =
F_259 ( & V_7 -> V_702 ) ;
if ( ! V_12 -> V_15 . V_288 . V_690 )
return - V_290 ;
V_13 = F_92 ( V_12 , & V_7 -> V_703 ) ;
if ( V_13 < 0 ) {
F_173 ( V_12 -> V_15 . V_288 . V_690 ) ;
return V_13 ;
}
break;
case V_60 :
if ( ! V_12 -> V_26 . V_209 . V_704 )
return - V_45 ;
if ( V_7 -> V_274 . V_610 != V_12 -> V_15 . V_705 . V_274 . V_610 )
return - V_45 ;
switch ( V_7 -> V_274 . V_610 ) {
case V_706 :
if ( F_268 ( & V_7 -> V_274 ) !=
F_268 ( & V_12 -> V_15 . V_705 . V_274 ) )
return - V_45 ;
case V_707 :
case V_708 :
case V_611 :
case V_709 :
break;
default:
return - V_45 ;
}
if ( V_12 -> V_15 . V_705 . V_274 . V_253 -> V_365 !=
V_7 -> V_274 . V_253 -> V_365 )
return - V_45 ;
V_13 = F_269 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
#ifdef F_30
case V_61 :
V_452 = & V_12 -> V_15 . V_62 ;
if ( ! V_452 -> V_460 )
return - V_45 ;
if ( V_7 -> V_274 . V_610 != V_12 -> V_26 . V_209 . V_274 . V_610 )
return - V_45 ;
if ( V_12 -> V_26 . V_209 . V_274 . V_253 -> V_365 !=
V_7 -> V_274 . V_253 -> V_365 )
return - V_45 ;
V_452 -> V_710 = true ;
if ( ! V_452 -> V_711 )
V_452 -> V_711 = 1 ;
else
V_452 -> V_711 ++ ;
V_13 = F_270 ( V_12 , V_7 , true ) ;
if ( V_13 < 0 ) {
V_452 -> V_710 = false ;
return V_13 ;
}
break;
#endif
default:
return - V_238 ;
}
V_12 -> V_688 = V_7 -> V_317 ;
if ( V_7 -> V_712 )
F_271 ( & V_9 -> V_108 ,
V_691 ,
V_692 ) ;
V_9 -> V_689 = V_7 -> V_274 ;
V_12 -> V_26 . V_334 = true ;
F_96 ( V_12 , V_13 ) ;
F_272 ( V_12 , & V_7 -> V_274 ) ;
return 0 ;
}
static int F_273 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_244 * V_253 , bool V_713 ,
unsigned int V_714 , const T_3 * V_715 , T_5 V_291 ,
bool V_716 , bool V_717 , T_4 * V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_349 * V_350 ;
struct V_36 * V_23 ;
const struct V_718 * V_719 = ( void * ) V_715 ;
bool V_720 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_717 )
V_5 = V_721 ;
else
V_5 = V_722 |
V_723 ;
if ( V_716 )
V_5 |= V_724 ;
switch ( V_12 -> V_26 . type ) {
case V_60 :
if ( ! V_12 -> V_26 . V_209 . V_704 )
V_720 = true ;
#ifdef F_30
case V_61 :
if ( F_25 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_62 . V_459 )
V_720 = true ;
#endif
case V_58 :
case V_20 :
case V_70 :
if ( V_12 -> V_26 . type != V_60 &&
! F_25 ( & V_12 -> V_26 ) &&
! F_274 ( V_12 -> V_410 -> V_300 ) )
V_720 = true ;
if ( ! F_275 ( V_719 -> V_725 ) ||
V_719 -> V_15 . V_726 . V_727 == V_728 ||
V_719 -> V_15 . V_726 . V_727 == V_729 ||
V_719 -> V_15 . V_726 . V_727 == V_730 )
break;
F_39 () ;
V_23 = F_26 ( V_12 , V_719 -> V_351 ) ;
F_43 () ;
if ( ! V_23 )
return - V_731 ;
break;
case V_24 :
case V_69 :
if ( ! V_12 -> V_15 . V_25 . V_619 )
V_720 = true ;
break;
case V_66 :
V_720 = true ;
break;
default:
return - V_238 ;
}
if ( V_720 && ! V_253 )
return - V_45 ;
F_24 ( & V_9 -> V_618 ) ;
if ( ! V_720 ) {
struct V_242 * V_243 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( V_243 ) {
V_720 = V_253 && ( V_253 != V_243 -> V_252 . V_253 ) ;
} else if ( ! V_253 ) {
V_19 = - V_45 ;
F_43 () ;
goto V_54;
} else {
V_720 = true ;
}
F_43 () ;
}
if ( V_720 && ! V_713 ) {
V_19 = - V_30 ;
goto V_54;
}
V_350 = F_114 ( V_9 -> V_108 . V_732 + V_291 ) ;
if ( ! V_350 ) {
V_19 = - V_290 ;
goto V_54;
}
F_276 ( V_350 , V_9 -> V_108 . V_732 ) ;
memcpy ( F_115 ( V_350 , V_291 ) , V_715 , V_291 ) ;
F_277 ( V_350 ) -> V_5 = V_5 ;
V_350 -> V_18 = V_12 -> V_18 ;
if ( ! V_720 ) {
* V_75 = ( unsigned long ) V_350 ;
F_278 ( V_12 , V_350 ) ;
V_19 = 0 ;
goto V_54;
}
F_277 ( V_350 ) -> V_5 |= V_733 |
V_734 ;
if ( V_9 -> V_108 . V_5 & V_735 )
F_277 ( V_350 ) -> V_736 =
V_9 -> V_108 . V_737 ;
V_19 = F_234 ( V_9 , V_12 , V_253 ,
V_714 , V_75 , V_350 ,
V_738 ) ;
if ( V_19 )
F_279 ( V_350 ) ;
V_54:
F_33 ( & V_9 -> V_618 ) ;
return V_19 ;
}
static int F_280 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_75 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_250 ( V_9 , V_75 , true ) ;
}
static void F_281 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_739 , bool V_740 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_739 ) {
case V_741 | V_742 :
if ( V_740 )
V_9 -> V_743 ++ ;
else
V_9 -> V_743 -- ;
if ( ! V_9 -> V_280 )
break;
F_224 ( & V_9 -> V_108 , & V_9 -> V_744 ) ;
break;
default:
break;
}
}
static int F_282 ( struct V_2 * V_2 , T_1 V_745 , T_1 V_746 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_662 )
return - V_238 ;
return F_283 ( V_9 , V_745 , V_746 ) ;
}
static int F_284 ( struct V_2 * V_2 , T_1 * V_745 , T_1 * V_746 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_285 ( V_9 , V_745 , V_746 ) ;
}
static int F_286 ( struct V_2 * V_2 , T_1 V_82 , T_1 V_747 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_287 ( V_9 , V_82 , V_747 ) ;
}
static void F_288 ( struct V_2 * V_2 ,
T_1 * V_82 , T_1 * V_748 , T_1 * V_747 , T_1 * V_749 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_289 ( V_9 , V_82 , V_748 , V_747 , V_749 ) ;
}
static int F_290 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_750 * V_241 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_178 -> V_751 )
return - V_238 ;
F_291 ( V_9 , V_12 , V_241 ) ;
return 0 ;
}
static void F_292 ( struct V_349 * V_350 )
{
T_3 * V_680 = ( void * ) F_115 ( V_350 , 7 ) ;
* V_680 ++ = V_752 ;
* V_680 ++ = 5 ;
* V_680 ++ = 0x0 ;
* V_680 ++ = 0x0 ;
* V_680 ++ = 0x0 ;
* V_680 ++ = 0x0 ;
* V_680 ++ = V_753 ;
}
static T_2 F_293 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_754 ;
V_754 = 0 ;
if ( F_52 ( V_12 ) != V_755 )
return V_754 ;
if ( ! ( V_9 -> V_108 . V_5 & V_756 ) )
V_754 |= V_757 ;
if ( ! ( V_9 -> V_108 . V_5 & V_758 ) )
V_754 |= V_759 ;
return V_754 ;
}
static void F_294 ( struct V_349 * V_350 , T_3 * V_760 ,
T_3 * V_761 , T_3 * V_249 )
{
struct V_762 * V_763 ;
V_763 = ( void * ) F_115 ( V_350 , sizeof( struct V_762 ) ) ;
V_763 -> V_764 = V_765 ;
V_763 -> V_458 = sizeof( struct V_762 ) - 2 ;
memcpy ( V_763 -> V_249 , V_249 , V_271 ) ;
memcpy ( V_763 -> V_766 , V_760 , V_271 ) ;
memcpy ( V_763 -> V_767 , V_761 , V_271 ) ;
}
static int
F_295 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_761 , T_3 V_768 , T_3 V_769 ,
T_2 V_770 , struct V_349 * V_350 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_364 V_365 = F_52 ( V_12 ) ;
struct V_771 * V_772 ;
V_772 = ( void * ) F_115 ( V_350 , F_296 ( struct V_771 , V_15 ) ) ;
memcpy ( V_772 -> V_351 , V_761 , V_271 ) ;
memcpy ( V_772 -> V_352 , V_12 -> V_26 . V_270 , V_271 ) ;
V_772 -> V_773 = F_297 ( V_774 ) ;
V_772 -> V_775 = V_776 ;
switch ( V_768 ) {
case V_777 :
V_772 -> V_727 = V_778 ;
V_772 -> V_768 = V_777 ;
F_115 ( V_350 , sizeof( V_772 -> V_15 . V_779 ) ) ;
V_772 -> V_15 . V_779 . V_769 = V_769 ;
V_772 -> V_15 . V_779 . V_780 =
F_298 ( F_293 ( V_12 ) ) ;
F_299 ( V_12 , V_350 , false , V_365 ) ;
F_300 ( V_12 , V_350 , false , V_365 ) ;
F_292 ( V_350 ) ;
break;
case V_781 :
V_772 -> V_727 = V_778 ;
V_772 -> V_768 = V_781 ;
F_115 ( V_350 , sizeof( V_772 -> V_15 . V_782 ) ) ;
V_772 -> V_15 . V_782 . V_770 = F_298 ( V_770 ) ;
V_772 -> V_15 . V_782 . V_769 = V_769 ;
V_772 -> V_15 . V_782 . V_780 =
F_298 ( F_293 ( V_12 ) ) ;
F_299 ( V_12 , V_350 , false , V_365 ) ;
F_300 ( V_12 , V_350 , false , V_365 ) ;
F_292 ( V_350 ) ;
break;
case V_783 :
V_772 -> V_727 = V_778 ;
V_772 -> V_768 = V_783 ;
F_115 ( V_350 , sizeof( V_772 -> V_15 . V_784 ) ) ;
V_772 -> V_15 . V_784 . V_770 = F_298 ( V_770 ) ;
V_772 -> V_15 . V_784 . V_769 = V_769 ;
break;
case V_785 :
V_772 -> V_727 = V_778 ;
V_772 -> V_768 = V_785 ;
F_115 ( V_350 , sizeof( V_772 -> V_15 . V_786 ) ) ;
V_772 -> V_15 . V_786 . V_787 = F_298 ( V_770 ) ;
break;
case V_788 :
V_772 -> V_727 = V_778 ;
V_772 -> V_768 = V_788 ;
F_115 ( V_350 , sizeof( V_772 -> V_15 . V_789 ) ) ;
V_772 -> V_15 . V_789 . V_769 = V_769 ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int
F_301 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_761 , T_3 V_768 , T_3 V_769 ,
T_2 V_770 , struct V_349 * V_350 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_364 V_365 = F_52 ( V_12 ) ;
struct V_718 * V_719 ;
V_719 = ( void * ) F_115 ( V_350 , 24 ) ;
memset ( V_719 , 0 , 24 ) ;
memcpy ( V_719 -> V_351 , V_761 , V_271 ) ;
memcpy ( V_719 -> V_352 , V_12 -> V_26 . V_270 , V_271 ) ;
memcpy ( V_719 -> V_249 , V_12 -> V_15 . V_25 . V_249 , V_271 ) ;
V_719 -> V_725 = F_298 ( V_741 |
V_790 ) ;
switch ( V_768 ) {
case V_791 :
F_115 ( V_350 , 1 + sizeof( V_719 -> V_15 . V_726 . V_15 . V_792 ) ) ;
V_719 -> V_15 . V_726 . V_727 = V_728 ;
V_719 -> V_15 . V_726 . V_15 . V_792 . V_768 =
V_791 ;
V_719 -> V_15 . V_726 . V_15 . V_792 . V_769 =
V_769 ;
V_719 -> V_15 . V_726 . V_15 . V_792 . V_780 =
F_298 ( F_293 ( V_12 ) ) ;
F_299 ( V_12 , V_350 , false , V_365 ) ;
F_300 ( V_12 , V_350 , false , V_365 ) ;
F_292 ( V_350 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_302 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_761 , T_3 V_768 , T_3 V_769 ,
T_2 V_770 , const T_3 * V_793 ,
T_5 V_794 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_349 * V_350 = NULL ;
bool V_795 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_796 ) )
return - V_519 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_619 )
return - V_45 ;
F_303 ( V_12 , L_6 ,
V_768 , V_761 ) ;
V_350 = F_114 ( V_9 -> V_108 . V_732 +
F_241 ( sizeof( struct V_718 ) ,
sizeof( struct V_771 ) ) +
50 +
7 +
V_794 +
sizeof( struct V_762 ) ) ;
if ( ! V_350 )
return - V_290 ;
F_276 ( V_350 , V_9 -> V_108 . V_732 ) ;
switch ( V_768 ) {
case V_777 :
case V_781 :
case V_783 :
case V_785 :
case V_788 :
V_19 = F_295 ( V_2 , V_18 , V_761 ,
V_768 , V_769 ,
V_770 , V_350 ) ;
V_795 = false ;
break;
case V_791 :
V_19 = F_301 ( V_2 , V_18 , V_761 , V_768 ,
V_769 , V_770 ,
V_350 ) ;
V_795 = true ;
break;
default:
V_19 = - V_519 ;
break;
}
if ( V_19 < 0 )
goto V_797;
if ( V_794 )
memcpy ( F_115 ( V_350 , V_794 ) , V_793 , V_794 ) ;
switch ( V_768 ) {
case V_777 :
case V_783 :
case V_785 :
case V_788 :
F_294 ( V_350 , V_12 -> V_26 . V_270 , V_761 ,
V_12 -> V_15 . V_25 . V_249 ) ;
break;
case V_781 :
case V_791 :
F_294 ( V_350 , V_761 , V_12 -> V_26 . V_270 ,
V_12 -> V_15 . V_25 . V_249 ) ;
break;
default:
V_19 = - V_519 ;
goto V_797;
}
if ( V_795 ) {
F_278 ( V_12 , V_350 ) ;
return 0 ;
}
switch ( V_768 ) {
case V_777 :
case V_781 :
F_304 ( V_350 , V_798 ) ;
V_350 -> V_799 = 2 ;
break;
default:
F_304 ( V_350 , V_800 ) ;
V_350 -> V_799 = 5 ;
break;
}
F_305 () ;
V_19 = F_306 ( V_350 , V_18 ) ;
F_307 () ;
return V_19 ;
V_797:
F_308 ( V_350 ) ;
return V_19 ;
}
static int F_309 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_761 , enum V_801 V_802 )
{
struct V_36 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_796 ) )
return - V_519 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_45 ;
F_303 ( V_12 , L_7 , V_802 , V_761 ) ;
switch ( V_802 ) {
case V_803 :
F_39 () ;
V_23 = F_26 ( V_12 , V_761 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_731 ;
}
F_123 ( V_23 , V_804 ) ;
F_43 () ;
break;
case V_805 :
return F_310 ( V_12 , V_761 ) ;
case V_806 :
case V_807 :
case V_808 :
return - V_519 ;
default:
return - V_519 ;
}
return 0 ;
}
static int F_311 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_761 , T_4 * V_75 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_809 * V_810 ;
struct V_349 * V_350 ;
int V_297 = sizeof( * V_810 ) ;
T_8 V_811 ;
bool V_812 ;
struct V_813 * V_814 ;
struct V_36 * V_23 ;
struct V_242 * V_243 ;
enum V_364 V_365 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( F_68 ( ! V_243 ) ) {
F_43 () ;
return - V_45 ;
}
V_365 = V_243 -> V_252 . V_253 -> V_365 ;
V_23 = F_27 ( V_12 , V_761 ) ;
if ( V_23 ) {
V_812 = F_28 ( V_23 , V_231 ) ;
} else {
F_43 () ;
return - V_731 ;
}
if ( V_812 ) {
V_811 = F_298 ( V_815 |
V_816 |
V_817 ) ;
} else {
V_297 -= 2 ;
V_811 = F_298 ( V_815 |
V_818 |
V_817 ) ;
}
V_350 = F_114 ( V_9 -> V_108 . V_732 + V_297 ) ;
if ( ! V_350 ) {
F_43 () ;
return - V_290 ;
}
V_350 -> V_18 = V_18 ;
F_276 ( V_350 , V_9 -> V_108 . V_732 ) ;
V_810 = ( void * ) F_115 ( V_350 , V_297 ) ;
V_810 -> V_725 = V_811 ;
V_810 -> V_819 = 0 ;
memcpy ( V_810 -> V_820 , V_23 -> V_23 . V_270 , V_271 ) ;
memcpy ( V_810 -> V_821 , V_12 -> V_26 . V_270 , V_271 ) ;
memcpy ( V_810 -> V_822 , V_12 -> V_26 . V_270 , V_271 ) ;
V_810 -> V_823 = 0 ;
V_814 = F_277 ( V_350 ) ;
V_814 -> V_5 |= V_723 |
V_722 ;
F_304 ( V_350 , V_824 ) ;
V_350 -> V_799 = 7 ;
if ( V_812 )
V_810 -> V_825 = F_298 ( 7 ) ;
F_305 () ;
F_312 ( V_12 , V_350 , V_365 ) ;
F_307 () ;
F_43 () ;
* V_75 = ( unsigned long ) V_350 ;
return 0 ;
}
static int F_313 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_273 * V_274 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_242 * V_243 ;
int V_19 = - V_826 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( V_243 ) {
* V_274 = V_243 -> V_252 ;
V_19 = 0 ;
} else if ( V_9 -> V_280 > 0 &&
V_9 -> V_280 == V_9 -> V_281 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_277 )
* V_274 = V_9 -> V_275 ;
else
* V_274 = V_9 -> V_282 ;
V_19 = 0 ;
}
F_43 () ;
return V_19 ;
}
static void F_314 ( struct V_2 * V_2 , bool V_622 )
{
F_315 ( F_2 ( V_2 ) , V_622 ) ;
}
