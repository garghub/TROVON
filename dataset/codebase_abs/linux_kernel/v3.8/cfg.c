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
F_29 ( V_12 -> V_9 , V_36 ) ;
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
if ( V_13 )
F_29 ( V_12 -> V_9 , V_36 ) ;
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
F_36 ( V_36 ) ;
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
V_129 -> V_132 = V_12 -> V_9 -> V_133 ;
V_129 -> V_134 = V_135 |
V_136 |
V_137 |
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
V_148 ;
F_54 ( & V_131 ) ;
V_129 -> V_149 = V_131 . V_150 - V_23 -> V_151 ;
V_129 -> V_152 = F_55 ( V_153 - V_23 -> V_154 ) ;
V_129 -> V_155 = V_23 -> V_155 ;
V_129 -> V_156 = V_23 -> V_156 ;
V_129 -> V_157 = V_23 -> V_157 ;
V_129 -> V_158 = V_23 -> V_158 ;
V_129 -> V_159 = V_23 -> V_160 ;
V_129 -> V_161 = V_23 -> V_162 ;
V_129 -> V_163 = V_23 -> V_164 ;
V_129 -> V_165 = V_23 -> V_165 ;
if ( ( V_23 -> V_9 -> V_104 . V_5 & V_166 ) ||
( V_23 -> V_9 -> V_104 . V_5 & V_167 ) ) {
V_129 -> V_134 |= V_168 | V_169 ;
if ( ! V_9 -> V_170 -> V_171 ||
F_56 ( V_9 , V_12 , & V_23 -> V_23 , & V_129 -> signal ) )
V_129 -> signal = ( V_172 ) V_23 -> V_173 ;
V_129 -> V_174 = ( V_172 ) - F_57 ( & V_23 -> V_175 ) ;
}
F_48 ( V_23 , & V_23 -> V_176 , & V_129 -> V_177 ) ;
F_52 ( V_23 , & V_129 -> V_178 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
V_129 -> V_134 |= V_179 |
V_180 |
V_181 ;
V_129 -> V_182 = F_58 ( V_23 -> V_182 ) ;
V_129 -> V_183 = F_58 ( V_23 -> V_183 ) ;
V_129 -> V_184 = V_23 -> V_184 ;
if ( F_28 ( V_23 , V_185 ) ) {
V_129 -> V_134 |= V_186 ;
V_129 -> V_187 = V_23 -> V_187 ;
}
#endif
}
V_129 -> V_188 . V_5 = 0 ;
if ( V_12 -> V_26 . V_189 . V_190 )
V_129 -> V_188 . V_5 |= V_191 ;
if ( V_12 -> V_26 . V_189 . V_192 )
V_129 -> V_188 . V_5 |= V_193 ;
if ( V_12 -> V_26 . V_189 . V_194 )
V_129 -> V_188 . V_5 |= V_195 ;
V_129 -> V_188 . V_196 = V_12 -> V_9 -> V_104 . V_47 . V_197 ;
V_129 -> V_188 . V_198 = V_12 -> V_26 . V_189 . V_199 ;
V_129 -> V_200 . V_201 = 0 ;
V_129 -> V_200 . V_202 = F_59 ( V_203 ) |
F_59 ( V_204 ) |
F_59 ( V_205 ) |
F_59 ( V_206 ) |
F_59 ( V_207 ) |
F_59 ( V_208 ) ;
if ( F_28 ( V_23 , V_209 ) )
V_129 -> V_200 . V_201 |= F_59 ( V_203 ) ;
if ( F_28 ( V_23 , V_210 ) )
V_129 -> V_200 . V_201 |= F_59 ( V_204 ) ;
if ( F_28 ( V_23 , V_211 ) )
V_129 -> V_200 . V_201 |= F_59 ( V_205 ) ;
if ( F_28 ( V_23 , V_57 ) )
V_129 -> V_200 . V_201 |= F_59 ( V_206 ) ;
if ( F_28 ( V_23 , V_212 ) )
V_129 -> V_200 . V_201 |= F_59 ( V_207 ) ;
if ( F_28 ( V_23 , V_213 ) )
V_129 -> V_200 . V_201 |= F_59 ( V_208 ) ;
}
static int F_60 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_214 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_215 = 0 ;
if ( V_214 == V_216 )
V_215 += V_217 ;
V_215 += F_61 ( V_12 , V_214 ) ;
if ( V_215 == 0 )
return - V_218 ;
return V_215 ;
}
static void F_62 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_219 * V_220 ,
T_4 * V_221 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
struct V_34 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_128 V_129 ;
struct V_226 V_227 ;
int V_228 , V_229 ;
#define F_63 7
memset ( V_221 , 0 , sizeof( T_4 ) * V_217 ) ;
#define F_64 ( V_23 ) \
do { \
data[i++] += sta->rx_packets; \
data[i++] += sta->rx_bytes; \
data[i++] += sta->wep_weak_iv_count; \
data[i++] += sta->num_duplicates; \
data[i++] += sta->rx_fragments; \
data[i++] += sta->rx_dropped; \
\
data[i++] += sta->tx_packets; \
data[i++] += sta->tx_bytes; \
data[i++] += sta->tx_fragments; \
data[i++] += sta->tx_filtered_count; \
data[i++] += sta->tx_retry_failed; \
data[i++] += sta->tx_retry_count; \
data[i++] += sta->beacon_loss_count; \
} while (0)
F_24 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_27 ( V_12 , V_12 -> V_15 . V_25 . V_230 ) ;
if ( ! ( V_23 && ! F_65 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_231;
V_228 = 0 ;
F_64 ( V_23 ) ;
V_221 [ V_228 ++ ] = V_23 -> V_232 ;
V_129 . V_134 = 0 ;
F_53 ( V_23 , & V_129 ) ;
if ( V_129 . V_134 & V_142 )
V_221 [ V_228 ] = 100000 *
F_66 ( & V_129 . V_177 ) ;
V_228 ++ ;
if ( V_129 . V_134 & V_143 )
V_221 [ V_228 ] = 100000 *
F_66 ( & V_129 . V_178 ) ;
V_228 ++ ;
if ( V_129 . V_134 & V_169 )
V_221 [ V_228 ] = ( T_3 ) V_129 . V_174 ;
V_228 ++ ;
} else {
F_67 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_228 = 0 ;
F_64 ( V_23 ) ;
}
}
V_231:
V_228 = V_217 - F_63 ;
V_227 . V_134 = 0 ;
F_39 () ;
V_223 = F_40 ( V_12 -> V_26 . V_223 ) ;
if ( V_223 )
V_225 = V_223 -> V_233 . V_234 ;
else
V_225 = NULL ;
F_43 () ;
if ( V_225 ) {
V_229 = 0 ;
do {
V_227 . V_134 = 0 ;
if ( F_68 ( V_9 , V_229 , & V_227 ) != 0 ) {
V_227 . V_134 = 0 ;
break;
}
V_229 ++ ;
} while ( V_225 != V_227 . V_225 );
}
if ( V_227 . V_134 )
V_221 [ V_228 ++ ] = V_227 . V_225 -> V_235 ;
else
V_221 [ V_228 ++ ] = 0 ;
if ( V_227 . V_134 & V_236 )
V_221 [ V_228 ++ ] = ( T_3 ) V_227 . V_237 ;
else
V_221 [ V_228 ++ ] = - 1LL ;
if ( V_227 . V_134 & V_238 )
V_221 [ V_228 ++ ] = V_227 . V_239 ;
else
V_221 [ V_228 ++ ] = - 1LL ;
if ( V_227 . V_134 & V_240 )
V_221 [ V_228 ++ ] = V_227 . V_241 ;
else
V_221 [ V_228 ++ ] = - 1LL ;
if ( V_227 . V_134 & V_242 )
V_221 [ V_228 ++ ] = V_227 . V_243 ;
else
V_221 [ V_228 ++ ] = - 1LL ;
if ( V_227 . V_134 & V_244 )
V_221 [ V_228 ++ ] = V_227 . V_245 ;
else
V_221 [ V_228 ++ ] = - 1LL ;
if ( V_227 . V_134 & V_246 )
V_221 [ V_228 ++ ] = V_227 . V_247 ;
else
V_221 [ V_228 ++ ] = - 1LL ;
F_33 ( & V_9 -> V_49 ) ;
if ( F_65 ( V_228 != V_217 ) )
return;
F_69 ( V_12 , V_220 , & ( V_221 [ V_217 ] ) ) ;
}
static void F_70 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_214 , T_3 * V_221 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_248 = 0 ;
if ( V_214 == V_216 ) {
V_248 = sizeof( V_249 ) ;
memcpy ( V_221 , * V_249 , V_248 ) ;
}
F_71 ( V_12 , V_214 , & ( V_221 [ V_248 ] ) ) ;
}
static int F_72 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , T_3 * V_250 , struct V_128 * V_129 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_51 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_73 ( V_12 , V_98 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_250 , V_23 -> V_23 . V_251 , V_252 ) ;
F_53 ( V_23 , V_129 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_74 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , struct V_226 * V_227 )
{
struct V_8 * V_9 = F_75 ( V_18 -> V_253 ) ;
return F_68 ( V_9 , V_98 , V_227 ) ;
}
static int F_76 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_250 , struct V_128 * V_129 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_51 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_250 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_53 ( V_23 , V_129 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_77 ( struct V_2 * V_2 ,
struct V_254 * V_255 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_78 ( & V_9 -> V_256 , V_255 ) )
return 0 ;
F_24 ( & V_9 -> V_257 ) ;
if ( V_9 -> V_258 ) {
V_12 = F_79 (
V_9 -> V_259 ,
F_80 ( & V_9 -> V_257 ) ) ;
if ( V_12 ) {
F_81 ( V_12 ) ;
V_19 = F_82 ( V_12 , V_255 ,
V_260 ) ;
}
} else if ( V_9 -> V_261 == V_9 -> V_262 ) {
V_9 -> V_263 = V_255 -> V_234 ;
V_9 -> V_264 = F_83 ( V_255 ) ;
F_84 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_256 = * V_255 ;
F_33 ( & V_9 -> V_257 ) ;
return V_19 ;
}
static int F_85 ( struct V_11 * V_12 ,
const T_3 * V_265 , T_5 V_266 )
{
struct V_267 * V_268 , * V_269 ;
if ( ! V_265 || ! V_266 )
return 1 ;
V_269 = F_86 ( V_12 -> V_15 . V_270 . V_267 ) ;
V_268 = F_87 ( sizeof( struct V_267 ) + V_266 , V_271 ) ;
if ( ! V_268 )
return - V_272 ;
V_268 -> V_273 = V_266 ;
memcpy ( V_268 -> V_221 , V_265 , V_266 ) ;
F_88 ( V_12 -> V_15 . V_270 . V_267 , V_268 ) ;
if ( V_269 )
F_89 ( V_269 , V_274 ) ;
return 0 ;
}
static int F_90 ( struct V_11 * V_12 ,
struct V_275 * V_7 )
{
struct V_276 * V_268 , * V_269 ;
int V_277 , V_278 ;
int V_279 , V_13 ;
T_1 V_280 = V_281 ;
V_269 = F_86 ( V_12 -> V_15 . V_270 . V_282 ) ;
if ( ! V_7 -> V_283 && ! V_269 )
return - V_43 ;
if ( V_7 -> V_283 )
V_277 = V_7 -> V_284 ;
else
V_277 = V_269 -> V_284 ;
if ( V_7 -> V_285 || ! V_269 )
V_278 = V_7 -> V_286 ;
else
V_278 = V_269 -> V_286 ;
V_279 = sizeof( * V_268 ) + V_277 + V_278 ;
V_268 = F_87 ( V_279 , V_271 ) ;
if ( ! V_268 )
return - V_272 ;
V_268 -> V_283 = ( ( T_3 * ) V_268 ) + sizeof( * V_268 ) ;
V_268 -> V_285 = V_268 -> V_283 + V_277 ;
V_268 -> V_284 = V_277 ;
V_268 -> V_286 = V_278 ;
if ( V_7 -> V_283 )
memcpy ( V_268 -> V_283 , V_7 -> V_283 , V_277 ) ;
else
memcpy ( V_268 -> V_283 , V_269 -> V_283 , V_277 ) ;
if ( V_7 -> V_285 )
memcpy ( V_268 -> V_285 , V_7 -> V_285 , V_278 ) ;
else
if ( V_269 )
memcpy ( V_268 -> V_285 , V_269 -> V_285 , V_278 ) ;
V_13 = F_85 ( V_12 , V_7 -> V_267 ,
V_7 -> V_287 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_280 |= V_288 ;
F_88 ( V_12 -> V_15 . V_270 . V_282 , V_268 ) ;
if ( V_269 )
F_89 ( V_269 , V_274 ) ;
return V_280 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_289 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_276 * V_269 ;
struct V_11 * V_22 ;
T_1 V_280 = V_290 |
V_291 |
V_281 |
V_292 |
V_293 ;
int V_13 ;
V_269 = F_86 ( V_12 -> V_15 . V_270 . V_282 ) ;
if ( V_269 )
return - V_294 ;
V_12 -> V_295 = V_296 ;
V_12 -> V_297 = V_12 -> V_9 -> V_298 ;
V_13 = F_82 ( V_12 , & V_7 -> V_255 ,
V_299 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_300 = V_7 -> V_301 . V_302 ;
V_12 -> V_303 = V_7 -> V_301 . V_303 ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_300 =
V_7 -> V_301 . V_302 ;
V_22 -> V_303 =
V_7 -> V_301 . V_303 ;
}
V_12 -> V_26 . V_189 . V_199 = V_7 -> V_198 ;
V_12 -> V_26 . V_189 . V_196 = V_7 -> V_196 ;
V_12 -> V_26 . V_189 . V_304 = V_7 -> V_304 ;
if ( V_7 -> V_304 )
memcpy ( V_12 -> V_26 . V_189 . V_305 , V_7 -> V_305 ,
V_7 -> V_304 ) ;
V_12 -> V_26 . V_189 . V_306 =
( V_7 -> V_306 != V_307 ) ;
V_12 -> V_26 . V_189 . V_308 = V_7 -> V_308 ;
V_12 -> V_26 . V_189 . V_309 = V_7 -> V_310 ;
V_13 = F_90 ( V_12 , & V_7 -> V_282 ) ;
if ( V_13 < 0 )
return V_13 ;
V_280 |= V_13 ;
V_13 = F_92 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_269 = F_86 ( V_12 -> V_15 . V_270 . V_282 ) ;
if ( V_269 )
F_89 ( V_269 , V_274 ) ;
F_11 ( V_12 -> V_15 . V_270 . V_282 , NULL ) ;
return V_13 ;
}
F_93 ( V_12 , V_280 ) ;
F_94 ( V_18 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_94 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_275 * V_7 )
{
struct V_11 * V_12 ;
struct V_276 * V_269 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
V_269 = F_86 ( V_12 -> V_15 . V_270 . V_282 ) ;
if ( ! V_269 )
return - V_51 ;
V_13 = F_90 ( V_12 , V_7 ) ;
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
struct V_276 * V_311 ;
struct V_267 * V_312 ;
V_311 = F_86 ( V_12 -> V_15 . V_270 . V_282 ) ;
if ( ! V_311 )
return - V_51 ;
V_312 = F_86 ( V_12 -> V_15 . V_270 . V_267 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_97 ( V_22 -> V_18 ) ;
F_97 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_270 . V_282 , NULL ) ;
F_11 ( V_12 -> V_15 . V_270 . V_267 , NULL ) ;
F_89 ( V_311 , V_274 ) ;
if ( V_312 )
F_89 ( V_312 , V_274 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_98 ( V_9 , V_22 ) ;
F_98 ( V_9 , V_12 ) ;
F_93 ( V_12 , V_291 ) ;
F_99 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_313 -= F_100 ( & V_12 -> V_15 . V_270 . V_314 . V_315 ) ;
F_101 ( & V_12 -> V_15 . V_270 . V_314 . V_315 ) ;
F_81 ( V_12 ) ;
return 0 ;
}
static void F_102 ( struct V_34 * V_23 )
{
struct V_316 * V_317 ;
struct V_318 * V_319 ;
V_319 = F_103 ( sizeof( * V_317 ) ) ;
if ( ! V_319 )
return;
V_317 = (struct V_316 * ) F_104 ( V_319 , sizeof( * V_317 ) ) ;
F_105 ( V_317 -> V_320 ) ;
memcpy ( V_317 -> V_321 , V_23 -> V_23 . V_251 , V_252 ) ;
V_317 -> V_273 = F_106 ( 6 ) ;
V_317 -> V_322 = 0 ;
V_317 -> V_323 = 0x01 ;
V_317 -> V_324 = 0xaf ;
V_317 -> V_325 [ 0 ] = 0x81 ;
V_317 -> V_325 [ 1 ] = 1 ;
V_317 -> V_325 [ 2 ] = 0 ;
V_319 -> V_18 = V_23 -> V_12 -> V_18 ;
V_319 -> V_326 = F_107 ( V_319 , V_23 -> V_12 -> V_18 ) ;
memset ( V_319 -> V_327 , 0 , sizeof( V_319 -> V_327 ) ) ;
F_108 ( V_319 ) ;
}
static int F_109 ( struct V_8 * V_9 ,
struct V_34 * V_23 ,
struct V_328 * V_7 )
{
int V_19 = 0 ;
T_1 V_329 ;
int V_228 , V_330 ;
struct V_102 * V_103 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_331 V_332 = F_51 ( V_12 ) ;
T_1 V_202 , V_201 ;
V_103 = V_9 -> V_104 . V_2 -> V_105 [ V_332 ] ;
V_202 = V_7 -> V_333 ;
V_201 = V_7 -> V_334 ;
if ( V_202 & F_59 ( V_207 ) ) {
if ( F_65 ( ! F_25 ( & V_12 -> V_26 ) ) )
return - V_43 ;
if ( V_201 & F_59 ( V_207 ) &&
! F_28 ( V_23 , V_212 ) ) {
V_19 = F_110 ( V_23 , V_335 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_110 ( V_23 , V_336 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_202 & F_59 ( V_203 ) ) {
if ( V_201 & F_59 ( V_203 ) )
V_19 = F_110 ( V_23 , V_337 ) ;
else if ( F_28 ( V_23 , V_209 ) )
V_19 = F_110 ( V_23 , V_336 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_202 & F_59 ( V_207 ) ) {
if ( F_65 ( ! F_25 ( & V_12 -> V_26 ) ) )
return - V_43 ;
if ( ! ( V_201 & F_59 ( V_207 ) ) &&
F_28 ( V_23 , V_212 ) ) {
V_19 = F_110 ( V_23 , V_335 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_110 ( V_23 , V_338 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_202 & F_59 ( V_204 ) ) {
if ( V_201 & F_59 ( V_204 ) )
F_111 ( V_23 , V_210 ) ;
else
F_112 ( V_23 , V_210 ) ;
}
if ( V_202 & F_59 ( V_205 ) ) {
if ( V_201 & F_59 ( V_205 ) ) {
F_111 ( V_23 , V_211 ) ;
V_23 -> V_23 . V_339 = true ;
} else {
F_112 ( V_23 , V_211 ) ;
V_23 -> V_23 . V_339 = false ;
}
}
if ( V_202 & F_59 ( V_206 ) ) {
if ( V_201 & F_59 ( V_206 ) )
F_111 ( V_23 , V_57 ) ;
else
F_112 ( V_23 , V_57 ) ;
}
if ( V_202 & F_59 ( V_208 ) ) {
if ( V_201 & F_59 ( V_208 ) )
F_111 ( V_23 , V_213 ) ;
else
F_112 ( V_23 , V_213 ) ;
}
if ( V_7 -> V_340 & V_341 ) {
V_23 -> V_23 . V_342 = V_7 -> V_342 ;
V_23 -> V_23 . V_343 = V_7 -> V_343 ;
}
if ( V_7 -> V_344 )
V_23 -> V_23 . V_344 = V_7 -> V_344 ;
if ( V_7 -> V_345 >= 0 )
V_23 -> V_345 = V_7 -> V_345 ;
if ( V_7 -> V_346 ) {
V_329 = 0 ;
for ( V_228 = 0 ; V_228 < V_7 -> V_347 ; V_228 ++ ) {
int V_92 = ( V_7 -> V_346 [ V_228 ] & 0x7f ) * 5 ;
for ( V_330 = 0 ; V_330 < V_103 -> V_348 ; V_330 ++ ) {
if ( V_103 -> V_107 [ V_330 ] . V_108 == V_92 )
V_329 |= F_59 ( V_330 ) ;
}
}
V_23 -> V_23 . V_349 [ V_332 ] = V_329 ;
}
if ( V_7 -> V_350 )
F_113 ( V_12 , V_103 ,
V_7 -> V_350 ,
& V_23 -> V_23 . V_351 ) ;
if ( V_7 -> V_352 )
F_114 ( V_12 , V_103 ,
V_7 -> V_352 ,
& V_23 -> V_23 . V_353 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
if ( V_12 -> V_15 . V_60 . V_61 & V_354 )
switch ( V_7 -> V_184 ) {
case V_355 :
case V_356 :
case V_357 :
V_23 -> V_184 = V_7 -> V_184 ;
break;
default:
break;
}
else
switch ( V_7 -> V_358 ) {
case V_359 :
F_115 ( V_23 ) ;
break;
case V_360 :
F_116 ( V_23 ) ;
break;
}
#endif
}
return 0 ;
}
static int F_117 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_250 , struct V_328 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_361 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_56 )
return - V_43 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_118 ( V_250 , V_12 -> V_26 . V_251 ) )
return - V_43 ;
if ( F_119 ( V_250 ) )
return - V_43 ;
V_23 = F_120 ( V_12 , V_250 , V_271 ) ;
if ( ! V_23 )
return - V_272 ;
F_121 ( V_23 , V_335 ) ;
F_121 ( V_23 , V_336 ) ;
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_122 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_28 ( V_23 , V_213 ) )
F_123 ( V_23 ) ;
V_361 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_56 ;
V_13 = F_124 ( V_23 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
if ( V_361 )
F_102 ( V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_125 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_250 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_250 )
return F_126 ( V_12 , V_250 ) ;
F_98 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_127 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_250 ,
struct V_328 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_362 ;
int V_13 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_250 ) ;
if ( ! V_23 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_51 ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_346 &&
! F_28 ( V_23 , V_213 ) ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_363 = false ;
bool V_364 = false ;
V_362 = F_9 ( V_7 -> V_22 ) ;
if ( V_362 -> V_26 . type != V_20 &&
V_362 -> V_26 . type != V_56 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 -> V_253 -> V_21 ) {
if ( V_362 -> V_15 . V_22 . V_23 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_28 ;
}
F_88 ( V_362 -> V_15 . V_22 . V_23 , V_23 ) ;
V_364 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_88 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_363 = true ;
}
V_23 -> V_12 = V_362 ;
if ( V_23 -> V_232 == V_337 &&
V_363 != V_364 ) {
if ( V_364 )
F_128 ( & V_23 -> V_12 -> V_365 -> V_366 ) ;
else
F_129 ( & V_23 -> V_12 -> V_365 -> V_366 ) ;
}
F_102 ( V_23 ) ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_33 ( & V_9 -> V_49 ) ;
return V_13 ;
}
if ( F_28 ( V_23 , V_213 ) && V_7 -> V_346 )
F_123 ( V_23 ) ;
F_33 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_333 & F_59 ( V_203 ) ) {
F_130 ( V_9 , - 1 ) ;
F_131 ( V_12 ) ;
}
return 0 ;
}
static int F_132 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_367 , T_3 * V_368 )
{
struct V_11 * V_12 ;
struct V_369 * V_370 ;
struct V_34 * V_23 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_368 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_51 ;
}
V_13 = F_133 ( V_367 , V_12 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
V_370 = F_134 ( V_367 , V_12 ) ;
if ( ! V_370 ) {
F_43 () ;
return - V_371 ;
}
F_135 ( V_370 , V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_136 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_367 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_367 )
return F_137 ( V_367 , V_12 ) ;
F_138 ( V_12 ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_367 , T_3 * V_368 )
{
struct V_11 * V_12 ;
struct V_369 * V_370 ;
struct V_34 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_368 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_51 ;
}
V_370 = F_134 ( V_367 , V_12 ) ;
if ( ! V_370 ) {
F_43 () ;
return - V_51 ;
}
F_135 ( V_370 , V_23 ) ;
F_43 () ;
return 0 ;
}
static void F_140 ( struct V_369 * V_370 , T_3 * V_368 ,
struct V_372 * V_373 )
{
struct V_34 * V_374 = F_40 ( V_370 -> V_368 ) ;
if ( V_374 )
memcpy ( V_368 , V_374 -> V_23 . V_251 , V_252 ) ;
else
memset ( V_368 , 0 , V_252 ) ;
memset ( V_373 , 0 , sizeof( * V_373 ) ) ;
V_373 -> V_132 = V_375 ;
V_373 -> V_134 = V_376 |
V_377 |
V_378 |
V_379 |
V_380 |
V_381 |
V_382 ;
V_373 -> V_383 = V_370 -> V_384 . V_385 ;
V_373 -> V_386 = V_370 -> V_386 ;
V_373 -> V_387 = V_370 -> V_387 ;
if ( F_141 ( V_153 , V_370 -> V_388 ) )
V_373 -> V_389 = F_55 ( V_370 -> V_388 - V_153 ) ;
V_373 -> V_390 =
F_55 ( V_370 -> V_390 ) ;
V_373 -> V_391 = V_370 -> V_391 ;
if ( V_370 -> V_5 & V_392 )
V_373 -> V_5 |= V_393 ;
if ( V_370 -> V_5 & V_394 )
V_373 -> V_5 |= V_395 ;
if ( V_370 -> V_5 & V_396 )
V_373 -> V_5 |= V_397 ;
if ( V_370 -> V_5 & V_398 )
V_373 -> V_5 |= V_399 ;
if ( V_370 -> V_5 & V_400 )
V_373 -> V_5 |= V_401 ;
}
static int F_142 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_367 , T_3 * V_368 , struct V_372 * V_373 )
{
struct V_11 * V_12 ;
struct V_369 * V_370 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_370 = F_134 ( V_367 , V_12 ) ;
if ( ! V_370 ) {
F_43 () ;
return - V_51 ;
}
memcpy ( V_367 , V_370 -> V_367 , V_252 ) ;
F_140 ( V_370 , V_368 , V_373 ) ;
F_43 () ;
return 0 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , T_3 * V_367 , T_3 * V_368 ,
struct V_372 * V_373 )
{
struct V_11 * V_12 ;
struct V_369 * V_370 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_370 = F_144 ( V_98 , V_12 ) ;
if ( ! V_370 ) {
F_43 () ;
return - V_51 ;
}
memcpy ( V_367 , V_370 -> V_367 , V_252 ) ;
F_140 ( V_370 , V_368 , V_373 ) ;
F_43 () ;
return 0 ;
}
static int F_145 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_402 * V_47 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_47 , & ( V_12 -> V_15 . V_60 . V_403 ) , sizeof( struct V_402 ) ) ;
return 0 ;
}
static inline bool F_146 ( enum V_404 V_405 , T_1 V_202 )
{
return ( V_202 >> ( V_405 - 1 ) ) & 0x1 ;
}
static int F_147 ( struct V_406 * V_407 ,
const struct V_408 * V_409 )
{
T_3 * V_410 ;
const T_3 * V_411 ;
struct V_11 * V_12 = F_148 ( V_407 ,
struct V_11 , V_15 . V_60 ) ;
V_410 = NULL ;
V_411 = V_407 -> V_412 ;
if ( V_409 -> V_413 ) {
V_410 = F_149 ( V_409 -> V_412 , V_409 -> V_413 ,
V_271 ) ;
if ( ! V_410 )
return - V_272 ;
}
V_407 -> V_413 = V_409 -> V_413 ;
V_407 -> V_412 = V_410 ;
F_150 ( V_411 ) ;
V_407 -> V_414 = V_409 -> V_414 ;
memcpy ( V_407 -> V_415 , V_409 -> V_415 , V_407 -> V_414 ) ;
V_407 -> V_416 = V_409 -> V_417 ;
V_407 -> V_418 = V_409 -> V_419 ;
V_407 -> V_420 = V_409 -> V_421 ;
V_407 -> V_61 = V_62 ;
if ( V_409 -> V_422 )
V_407 -> V_61 |= V_423 ;
if ( V_409 -> V_424 )
V_407 -> V_61 |= V_354 ;
memcpy ( V_12 -> V_26 . V_189 . V_425 , V_409 -> V_425 ,
sizeof( V_409 -> V_425 ) ) ;
return 0 ;
}
static int F_151 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_202 ,
const struct V_402 * V_426 )
{
struct V_402 * V_47 ;
struct V_11 * V_12 ;
struct V_406 * V_407 ;
V_12 = F_9 ( V_18 ) ;
V_407 = & V_12 -> V_15 . V_60 ;
V_47 = & ( V_12 -> V_15 . V_60 . V_403 ) ;
if ( F_146 ( V_427 , V_202 ) )
V_47 -> V_428 = V_426 -> V_428 ;
if ( F_146 ( V_429 , V_202 ) )
V_47 -> V_430 = V_426 -> V_430 ;
if ( F_146 ( V_431 , V_202 ) )
V_47 -> V_432 = V_426 -> V_432 ;
if ( F_146 ( V_433 , V_202 ) )
V_47 -> V_434 = V_426 -> V_434 ;
if ( F_146 ( V_435 , V_202 ) )
V_47 -> V_436 = V_426 -> V_436 ;
if ( F_146 ( V_437 , V_202 ) )
V_47 -> V_438 = V_426 -> V_438 ;
if ( F_146 ( V_439 , V_202 ) )
V_47 -> V_440 = V_426 -> V_440 ;
if ( F_146 ( V_441 , V_202 ) )
V_47 -> V_442 = V_426 -> V_442 ;
if ( F_146 ( V_443 , V_202 ) )
V_47 -> V_444 =
V_426 -> V_444 ;
if ( F_146 ( V_445 , V_202 ) )
V_47 -> V_446 =
V_426 -> V_446 ;
if ( F_146 ( V_447 , V_202 ) )
V_47 -> V_448 = V_426 -> V_448 ;
if ( F_146 ( V_449 , V_202 ) )
V_47 -> V_450 = V_426 -> V_450 ;
if ( F_146 ( V_451 , V_202 ) )
V_47 -> V_452 =
V_426 -> V_452 ;
if ( F_146 ( V_453 , V_202 ) )
V_47 -> V_454 =
V_426 -> V_454 ;
if ( F_146 ( V_455 , V_202 ) )
V_47 -> V_456 =
V_426 -> V_456 ;
if ( F_146 ( V_457 ,
V_202 ) )
V_47 -> V_458 =
V_426 -> V_458 ;
if ( F_146 ( V_459 , V_202 ) ) {
V_47 -> V_460 = V_426 -> V_460 ;
F_152 ( V_407 ) ;
}
if ( F_146 ( V_461 , V_202 ) ) {
if ( V_426 -> V_462 &&
! ( V_47 -> V_460 > V_463 ) ) {
V_47 -> V_460 = V_464 ;
F_152 ( V_407 ) ;
}
V_47 -> V_462 =
V_426 -> V_462 ;
}
if ( F_146 ( V_465 , V_202 ) )
V_47 -> V_466 =
V_426 -> V_466 ;
if ( F_146 ( V_467 , V_202 ) )
V_47 -> V_468 = V_426 -> V_468 ;
if ( F_146 ( V_469 , V_202 ) ) {
if ( ! ( V_12 -> V_9 -> V_104 . V_5 & V_166 ) )
return - V_470 ;
V_47 -> V_471 = V_426 -> V_471 ;
}
if ( F_146 ( V_472 , V_202 ) ) {
V_47 -> V_473 = V_426 -> V_473 ;
V_12 -> V_26 . V_189 . V_474 = V_426 -> V_473 ;
F_93 ( V_12 , V_475 ) ;
}
if ( F_146 ( V_476 , V_202 ) )
V_47 -> V_477 =
V_426 -> V_477 ;
if ( F_146 ( V_478 , V_202 ) )
V_47 -> V_479 =
V_426 -> V_479 ;
if ( F_146 ( V_480 , V_202 ) )
V_47 -> V_481 =
V_426 -> V_481 ;
return 0 ;
}
static int F_153 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_402 * V_47 ,
const struct V_408 * V_409 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_406 * V_407 = & V_12 -> V_15 . V_60 ;
int V_13 ;
memcpy ( & V_407 -> V_403 , V_47 , sizeof( struct V_402 ) ) ;
V_13 = F_147 ( V_407 , V_409 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_295 = V_296 ;
V_12 -> V_297 = V_12 -> V_9 -> V_298 ;
V_13 = F_82 ( V_12 , & V_409 -> V_255 ,
V_299 ) ;
if ( V_13 )
return V_13 ;
F_154 ( V_12 ) ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_156 ( V_12 ) ;
F_81 ( V_12 ) ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_482 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_331 V_332 ;
T_1 V_280 = 0 ;
if ( ! F_86 ( V_12 -> V_15 . V_270 . V_282 ) )
return - V_51 ;
V_332 = F_51 ( V_12 ) ;
if ( V_7 -> V_190 >= 0 ) {
V_12 -> V_26 . V_189 . V_190 = V_7 -> V_190 ;
V_280 |= V_483 ;
}
if ( V_7 -> V_192 >= 0 ) {
V_12 -> V_26 . V_189 . V_192 =
V_7 -> V_192 ;
V_280 |= V_484 ;
}
if ( ! V_12 -> V_26 . V_189 . V_194 &&
V_332 == V_485 ) {
V_12 -> V_26 . V_189 . V_194 = true ;
V_280 |= V_486 ;
}
if ( V_7 -> V_487 >= 0 ) {
V_12 -> V_26 . V_189 . V_194 =
V_7 -> V_487 ;
V_280 |= V_486 ;
}
if ( V_7 -> V_488 ) {
int V_228 , V_330 ;
T_1 V_329 = 0 ;
struct V_102 * V_103 = V_2 -> V_105 [ V_332 ] ;
for ( V_228 = 0 ; V_228 < V_7 -> V_489 ; V_228 ++ ) {
int V_92 = ( V_7 -> V_488 [ V_228 ] & 0x7f ) * 5 ;
for ( V_330 = 0 ; V_330 < V_103 -> V_348 ; V_330 ++ ) {
if ( V_103 -> V_107 [ V_330 ] . V_108 == V_92 )
V_329 |= F_59 ( V_330 ) ;
}
}
V_12 -> V_26 . V_189 . V_488 = V_329 ;
V_280 |= V_490 ;
}
if ( V_7 -> V_491 >= 0 ) {
if ( V_7 -> V_491 )
V_12 -> V_5 |= V_492 ;
else
V_12 -> V_5 &= ~ V_492 ;
}
if ( V_7 -> V_473 >= 0 ) {
V_12 -> V_26 . V_189 . V_474 =
( T_2 ) V_7 -> V_473 ;
V_280 |= V_475 ;
}
if ( V_7 -> V_308 >= 0 ) {
V_12 -> V_26 . V_189 . V_308 = V_7 -> V_308 ;
V_280 |= V_293 ;
}
if ( V_7 -> V_310 >= 0 ) {
V_12 -> V_26 . V_189 . V_309 = V_7 -> V_310 ;
V_280 |= V_293 ;
}
F_93 ( V_12 , V_280 ) ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_493 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_494 V_495 ;
if ( ! V_9 -> V_170 -> V_496 )
return - V_218 ;
if ( V_9 -> V_104 . V_497 < V_498 )
return - V_218 ;
memset ( & V_495 , 0 , sizeof( V_495 ) ) ;
V_495 . V_499 = V_7 -> V_499 ;
V_495 . V_500 = V_7 -> V_501 ;
V_495 . V_502 = V_7 -> V_503 ;
V_495 . V_504 = V_7 -> V_504 ;
V_495 . V_505 = false ;
V_12 -> V_506 [ V_7 -> V_507 ] = V_495 ;
if ( F_159 ( V_9 , V_12 , V_7 -> V_507 , & V_495 ) ) {
F_160 ( V_9 -> V_104 . V_2 ,
L_1 ,
V_7 -> V_507 ) ;
return - V_43 ;
}
F_93 ( V_12 , V_508 ) ;
return 0 ;
}
static int F_161 ( struct V_2 * V_2 ,
struct V_509 * V_510 )
{
return F_162 ( F_2 ( V_2 ) , V_510 ) ;
}
static int F_163 ( struct V_2 * V_2 )
{
return F_164 ( F_2 ( V_2 ) ) ;
}
static int F_165 ( struct V_2 * V_2 ,
struct V_511 * V_512 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_512 -> V_10 ) ;
switch ( F_166 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_58 :
case V_59 :
case V_67 :
case V_64 :
break;
case V_68 :
if ( V_12 -> V_9 -> V_170 -> V_513 )
break;
case V_56 :
if ( V_12 -> V_15 . V_270 . V_282 &&
( ! ( V_2 -> V_514 & V_515 ) ||
! ( V_512 -> V_5 & V_516 ) ) )
return - V_218 ;
break;
default:
return - V_218 ;
}
return F_167 ( V_12 , V_512 ) ;
}
static int
F_168 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_517 * V_512 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_170 -> V_518 )
return - V_218 ;
return F_169 ( V_12 , V_512 ) ;
}
static int
F_170 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_170 -> V_519 )
return - V_218 ;
return F_171 ( V_12 ) ;
}
static int F_172 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_520 * V_512 )
{
return F_173 ( F_9 ( V_18 ) , V_512 ) ;
}
static int F_174 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_521 * V_512 )
{
return F_175 ( F_9 ( V_18 ) , V_512 ) ;
}
static int F_176 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_522 * V_512 )
{
return F_177 ( F_9 ( V_18 ) , V_512 ) ;
}
static int F_178 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_523 * V_512 )
{
return F_179 ( F_9 ( V_18 ) , V_512 ) ;
}
static int F_180 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_524 * V_7 )
{
return F_181 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_182 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_183 ( F_9 ( V_18 ) ) ;
}
static int F_184 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_92 [ V_525 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_189 . V_425 , V_92 ,
sizeof( int ) * V_525 ) ;
return 0 ;
}
static int F_185 ( struct V_2 * V_2 , T_1 V_280 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_280 & V_526 ) {
V_13 = F_186 ( V_9 , V_2 -> V_527 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_280 & V_528 ) {
V_13 = F_187 ( V_9 , V_2 -> V_529 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_280 & V_530 ) {
V_13 = F_188 ( V_9 , V_2 -> V_531 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_280 & V_532 ) {
if ( V_2 -> V_533 > V_534 )
return - V_43 ;
V_9 -> V_104 . V_47 . V_535 = V_2 -> V_533 ;
}
if ( V_280 & V_536 ) {
if ( V_2 -> V_537 > V_534 )
return - V_43 ;
V_9 -> V_104 . V_47 . V_538 = V_2 -> V_537 ;
}
if ( V_280 &
( V_532 | V_536 ) )
F_84 ( V_9 , V_539 ) ;
return 0 ;
}
static int F_189 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_540 type , int V_541 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_542 :
V_12 -> V_543 = V_544 ;
break;
case V_545 :
case V_546 :
if ( V_541 < 0 || ( V_541 % 100 ) )
return - V_218 ;
V_12 -> V_543 = F_190 ( V_541 ) ;
break;
}
F_191 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_542 :
V_9 -> V_543 = V_544 ;
break;
case V_545 :
case V_546 :
if ( V_541 < 0 || ( V_541 % 100 ) )
return - V_218 ;
V_9 -> V_543 = F_190 ( V_541 ) ;
break;
}
F_24 ( & V_9 -> V_257 ) ;
F_67 (sdata, &local->interfaces, list)
V_12 -> V_543 = V_9 -> V_543 ;
F_67 (sdata, &local->interfaces, list)
F_191 ( V_12 ) ;
F_33 ( & V_9 -> V_257 ) ;
return 0 ;
}
static int F_192 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_547 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_258 )
* V_547 = V_9 -> V_104 . V_47 . V_548 ;
else
* V_547 = V_12 -> V_26 . V_189 . V_549 ;
return 0 ;
}
static int F_193 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_251 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_550 . V_551 , V_251 , V_252 ) ;
return 0 ;
}
static void F_194 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_195 ( V_9 ) ;
}
static int F_196 ( struct V_2 * V_2 , void * V_221 , int V_273 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_170 -> V_552 )
return - V_218 ;
return V_9 -> V_170 -> V_552 ( & V_9 -> V_104 , V_221 , V_273 ) ;
}
static int F_197 ( struct V_2 * V_2 ,
struct V_318 * V_319 ,
struct V_553 * V_327 ,
void * V_221 , int V_273 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_170 -> V_554 )
return - V_218 ;
return V_9 -> V_170 -> V_554 ( & V_9 -> V_104 , V_319 , V_327 , V_221 , V_273 ) ;
}
int F_198 ( struct V_11 * V_12 ,
enum V_555 V_295 )
{
const T_3 * V_270 ;
enum V_555 V_556 ;
int V_13 ;
F_199 ( & V_12 -> V_15 . V_25 . V_557 ) ;
V_556 = V_12 -> V_15 . V_25 . V_558 ;
V_12 -> V_15 . V_25 . V_558 = V_295 ;
if ( V_556 == V_295 &&
V_295 != V_559 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_560 ||
V_12 -> V_26 . V_189 . V_255 . V_561 == V_562 )
return 0 ;
V_270 = V_12 -> V_15 . V_25 . V_560 -> V_230 ;
if ( V_295 == V_559 ) {
if ( V_12 -> V_15 . V_25 . V_563 )
V_295 = V_564 ;
else
V_295 = V_296 ;
}
V_13 = F_200 ( V_12 , V_295 ,
V_270 , V_270 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_558 = V_556 ;
return V_13 ;
}
static int F_201 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_565 , int V_566 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_75 ( V_18 -> V_253 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_218 ;
if ( ! ( V_9 -> V_104 . V_5 & V_567 ) )
return - V_218 ;
if ( V_565 == V_12 -> V_15 . V_25 . V_563 &&
V_566 == V_9 -> V_568 )
return 0 ;
V_12 -> V_15 . V_25 . V_563 = V_565 ;
V_9 -> V_568 = V_566 ;
F_24 ( & V_12 -> V_15 . V_25 . V_557 ) ;
F_198 ( V_12 , V_12 -> V_15 . V_25 . V_558 ) ;
F_33 ( & V_12 -> V_15 . V_25 . V_557 ) ;
if ( V_9 -> V_104 . V_5 & V_569 )
F_84 ( V_9 , V_570 ) ;
F_130 ( V_9 , - 1 ) ;
F_131 ( V_12 ) ;
return 0 ;
}
static int F_202 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_571 , T_1 V_572 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_573 * V_26 = & V_12 -> V_26 ;
struct V_574 * V_189 = & V_26 -> V_189 ;
if ( V_571 == V_189 -> V_575 &&
V_572 == V_189 -> V_576 )
return 0 ;
V_189 -> V_575 = V_571 ;
V_189 -> V_576 = V_572 ;
if ( V_12 -> V_15 . V_25 . V_560 &&
V_12 -> V_26 . V_577 & V_578 )
F_93 ( V_12 , V_579 ) ;
return 0 ;
}
static int F_203 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_251 ,
const struct V_580 * V_202 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_75 ( V_18 -> V_253 ) ;
int V_228 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_37 ;
if ( V_9 -> V_104 . V_5 & V_581 ) {
V_19 = F_204 ( V_9 , V_12 , V_202 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_228 = 0 ; V_228 < V_525 ; V_228 ++ ) {
V_12 -> V_582 [ V_228 ] = V_202 -> V_324 [ V_228 ] . V_106 ;
memcpy ( V_12 -> V_583 [ V_228 ] , V_202 -> V_324 [ V_228 ] . V_97 ,
sizeof( V_202 -> V_324 [ V_228 ] . V_97 ) ) ;
}
return 0 ;
}
static int F_205 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_224 * V_225 ,
unsigned int V_584 , T_4 * V_73 ,
struct V_318 * V_585 )
{
struct V_586 * V_587 , * V_588 ;
bool V_589 = false ;
int V_19 ;
F_199 ( & V_9 -> V_557 ) ;
if ( V_9 -> V_258 && ! V_9 -> V_170 -> V_590 )
return - V_218 ;
V_587 = F_87 ( sizeof( * V_587 ) , V_271 ) ;
if ( ! V_587 )
return - V_272 ;
V_587 -> V_234 = V_225 ;
V_587 -> V_584 = V_584 ;
V_587 -> V_591 = V_584 ;
V_587 -> V_592 = V_585 ;
V_587 -> V_593 = ( unsigned long ) V_585 ;
V_587 -> V_12 = V_12 ;
F_206 ( & V_587 -> V_594 , V_595 ) ;
F_207 ( & V_587 -> V_596 ) ;
if ( ! F_208 ( & V_9 -> V_597 ) || V_9 -> V_598 )
goto V_599;
if ( ! V_9 -> V_170 -> V_590 ) {
F_209 ( & V_9 -> V_104 , & V_587 -> V_594 , 0 ) ;
goto V_600;
}
if ( ! V_584 )
V_584 = 10 ;
V_19 = F_210 ( V_9 , V_12 , V_225 , V_584 ) ;
if ( V_19 ) {
F_150 ( V_587 ) ;
return V_19 ;
}
V_587 -> V_601 = true ;
goto V_600;
V_599:
F_67 (tmp, &local->roc_list, list) {
if ( V_588 -> V_234 != V_225 || V_588 -> V_12 != V_12 )
continue;
if ( ! V_588 -> V_601 ) {
F_211 ( & V_587 -> V_602 , & V_588 -> V_596 ) ;
V_588 -> V_584 = F_212 ( V_588 -> V_584 , V_587 -> V_584 ) ;
V_589 = true ;
break;
}
if ( V_9 -> V_170 -> V_590 ) {
unsigned long V_330 = V_153 ;
if ( ! V_588 -> V_603 ) {
F_211 ( & V_587 -> V_602 , & V_588 -> V_596 ) ;
V_589 = true ;
break;
}
if ( F_141 ( V_330 + V_604 ,
V_588 -> V_605 +
F_213 ( V_588 -> V_584 ) ) ) {
int V_606 ;
F_214 ( V_587 ) ;
V_606 = V_587 -> V_584 -
F_55 ( V_588 -> V_605 +
F_213 (
V_588 -> V_584 ) -
V_330 ) ;
if ( V_606 > 0 ) {
F_215 ( & V_587 -> V_602 , & V_588 -> V_602 ) ;
} else {
F_211 ( & V_587 -> V_602 ,
& V_588 -> V_596 ) ;
}
V_589 = true ;
}
} else if ( F_216 ( & V_588 -> V_594 . V_607 ) ) {
unsigned long V_608 ;
F_211 ( & V_587 -> V_602 , & V_588 -> V_596 ) ;
V_589 = true ;
V_608 = V_153 + F_213 ( V_587 -> V_584 ) ;
if ( F_217 ( V_608 , V_588 -> V_594 . V_607 . V_609 ) )
F_218 ( & V_588 -> V_594 . V_607 , V_608 ) ;
else
F_219 ( & V_588 -> V_594 . V_607 ) ;
F_214 ( V_587 ) ;
}
break;
}
V_600:
if ( ! V_589 )
F_211 ( & V_587 -> V_602 , & V_9 -> V_597 ) ;
if ( ! V_585 ) {
V_9 -> V_610 ++ ;
V_587 -> V_73 = V_9 -> V_610 ;
if ( F_65 ( V_587 -> V_73 == 0 ) ) {
V_587 -> V_73 = 1 ;
V_9 -> V_610 ++ ;
}
* V_73 = V_587 -> V_73 ;
} else {
* V_73 = ( unsigned long ) V_585 ;
}
return 0 ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_224 * V_234 ,
unsigned int V_584 ,
T_4 * V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_24 ( & V_9 -> V_557 ) ;
V_19 = F_205 ( V_9 , V_12 , V_234 ,
V_584 , V_73 , NULL ) ;
F_33 ( & V_9 -> V_557 ) ;
return V_19 ;
}
static int F_221 ( struct V_8 * V_9 ,
T_4 V_73 , bool V_611 )
{
struct V_586 * V_587 , * V_588 , * V_612 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_557 ) ;
F_222 (roc, tmp, &local->roc_list, list) {
struct V_586 * V_613 , * V_614 ;
F_222 (dep, tmp2, &roc->dependents, list) {
if ( ! V_611 && V_613 -> V_73 != V_73 )
continue;
else if ( V_611 && V_613 -> V_593 != V_73 )
continue;
F_223 ( & V_613 -> V_602 ) ;
F_33 ( & V_9 -> V_557 ) ;
F_224 ( V_613 ) ;
return 0 ;
}
if ( ! V_611 && V_587 -> V_73 != V_73 )
continue;
else if ( V_611 && V_587 -> V_593 != V_73 )
continue;
V_612 = V_587 ;
break;
}
if ( ! V_612 ) {
F_33 ( & V_9 -> V_557 ) ;
return - V_51 ;
}
if ( V_9 -> V_170 -> V_590 ) {
if ( V_612 -> V_601 ) {
V_19 = F_225 ( V_9 ) ;
if ( F_31 ( V_19 ) ) {
F_33 ( & V_9 -> V_557 ) ;
return V_19 ;
}
}
F_223 ( & V_612 -> V_602 ) ;
if ( V_612 -> V_601 )
F_226 ( V_9 ) ;
F_33 ( & V_9 -> V_557 ) ;
F_224 ( V_612 ) ;
} else {
V_612 -> abort = true ;
F_209 ( & V_9 -> V_104 , & V_612 -> V_594 , 0 ) ;
F_33 ( & V_9 -> V_557 ) ;
F_227 ( & V_612 -> V_594 ) ;
}
return 0 ;
}
static int F_228 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_221 ( V_9 , V_73 , false ) ;
}
static int F_229 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_224 * V_234 , bool V_615 ,
unsigned int V_616 , const T_3 * V_617 , T_5 V_273 ,
bool V_618 , bool V_619 , T_4 * V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_318 * V_319 ;
struct V_34 * V_23 ;
const struct V_620 * V_621 = ( void * ) V_617 ;
bool V_622 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_619 )
V_5 = V_623 ;
else
V_5 = V_624 |
V_625 ;
if ( V_618 )
V_5 |= V_626 ;
switch ( V_12 -> V_26 . type ) {
case V_58 :
if ( ! V_12 -> V_26 . V_189 . V_627 )
V_622 = true ;
#ifdef F_30
case V_59 :
if ( F_25 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_60 . V_414 )
V_622 = true ;
#endif
case V_56 :
case V_20 :
case V_68 :
if ( V_12 -> V_26 . type != V_58 &&
! F_25 ( & V_12 -> V_26 ) &&
! F_230 ( V_12 -> V_365 -> V_282 ) )
V_622 = true ;
if ( ! F_231 ( V_621 -> V_628 ) ||
V_621 -> V_15 . V_629 . V_630 == V_631 )
break;
F_39 () ;
V_23 = F_26 ( V_12 , V_621 -> V_320 ) ;
F_43 () ;
if ( ! V_23 )
return - V_632 ;
break;
case V_24 :
case V_67 :
if ( ! V_12 -> V_15 . V_25 . V_560 )
V_622 = true ;
break;
case V_64 :
V_622 = true ;
break;
default:
return - V_218 ;
}
F_24 ( & V_9 -> V_557 ) ;
if ( ! V_622 ) {
struct V_222 * V_223 ;
F_39 () ;
V_223 = F_40 ( V_12 -> V_26 . V_223 ) ;
if ( V_223 )
V_622 = V_234 != V_223 -> V_233 . V_234 ;
else
V_622 = true ;
F_43 () ;
}
if ( V_622 && ! V_615 ) {
V_19 = - V_28 ;
goto V_52;
}
V_319 = F_103 ( V_9 -> V_104 . V_633 + V_273 ) ;
if ( ! V_319 ) {
V_19 = - V_272 ;
goto V_52;
}
F_232 ( V_319 , V_9 -> V_104 . V_633 ) ;
memcpy ( F_104 ( V_319 , V_273 ) , V_617 , V_273 ) ;
F_233 ( V_319 ) -> V_5 = V_5 ;
V_319 -> V_18 = V_12 -> V_18 ;
if ( ! V_622 ) {
* V_73 = ( unsigned long ) V_319 ;
F_234 ( V_12 , V_319 ) ;
V_19 = 0 ;
goto V_52;
}
F_233 ( V_319 ) -> V_5 |= V_634 ;
if ( V_9 -> V_104 . V_5 & V_635 )
F_233 ( V_319 ) -> V_636 =
V_9 -> V_104 . V_637 ;
V_19 = F_205 ( V_9 , V_12 , V_234 ,
V_616 , V_73 , V_319 ) ;
if ( V_19 )
F_235 ( V_319 ) ;
V_52:
F_33 ( & V_9 -> V_557 ) ;
return V_19 ;
}
static int F_236 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_73 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_221 ( V_9 , V_73 , true ) ;
}
static void F_237 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_638 , bool V_639 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( V_638 ) {
case V_640 | V_641 :
if ( V_12 -> V_26 . type == V_58 ) {
struct V_642 * V_643 = & V_12 -> V_15 . V_644 ;
if ( V_639 )
V_643 -> V_645 ++ ;
else
V_643 -> V_645 -- ;
}
break;
case V_640 | V_646 :
if ( V_639 )
V_9 -> V_647 ++ ;
else
V_9 -> V_647 -- ;
if ( ! V_9 -> V_261 )
break;
F_238 ( & V_9 -> V_104 , & V_9 -> V_648 ) ;
break;
default:
break;
}
}
static int F_239 ( struct V_2 * V_2 , T_1 V_649 , T_1 V_650 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_601 )
return - V_218 ;
return F_240 ( V_9 , V_649 , V_650 ) ;
}
static int F_241 ( struct V_2 * V_2 , T_1 * V_649 , T_1 * V_650 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_242 ( V_9 , V_649 , V_650 ) ;
}
static int F_243 ( struct V_2 * V_2 , T_1 V_80 , T_1 V_651 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_244 ( V_9 , V_80 , V_651 ) ;
}
static void F_245 ( struct V_2 * V_2 ,
T_1 * V_80 , T_1 * V_652 , T_1 * V_651 , T_1 * V_653 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_246 ( V_9 , V_80 , V_652 , V_651 , V_653 ) ;
}
static int F_247 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_654 * V_221 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_170 -> V_655 )
return - V_218 ;
F_248 ( V_9 , V_12 , V_221 ) ;
return 0 ;
}
static void F_249 ( struct V_318 * V_319 )
{
T_3 * V_656 = ( void * ) F_104 ( V_319 , 7 ) ;
* V_656 ++ = V_657 ;
* V_656 ++ = 5 ;
* V_656 ++ = 0x0 ;
* V_656 ++ = 0x0 ;
* V_656 ++ = 0x0 ;
* V_656 ++ = 0x0 ;
* V_656 ++ = V_658 ;
}
static T_2 F_250 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_659 ;
V_659 = 0 ;
if ( F_51 ( V_12 ) != V_660 )
return V_659 ;
if ( ! ( V_9 -> V_104 . V_5 & V_661 ) )
V_659 |= V_662 ;
if ( ! ( V_9 -> V_104 . V_5 & V_663 ) )
V_659 |= V_664 ;
return V_659 ;
}
static void F_251 ( struct V_318 * V_319 , T_3 * V_665 ,
T_3 * V_666 , T_3 * V_230 )
{
struct V_667 * V_668 ;
V_668 = ( void * ) F_104 ( V_319 , sizeof( struct V_667 ) ) ;
V_668 -> V_669 = V_670 ;
V_668 -> V_413 = sizeof( struct V_667 ) - 2 ;
memcpy ( V_668 -> V_230 , V_230 , V_252 ) ;
memcpy ( V_668 -> V_671 , V_665 , V_252 ) ;
memcpy ( V_668 -> V_672 , V_666 , V_252 ) ;
}
static int
F_252 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_666 , T_3 V_673 , T_3 V_674 ,
T_2 V_675 , struct V_318 * V_319 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_331 V_332 = F_51 ( V_12 ) ;
struct V_676 * V_677 ;
V_677 = ( void * ) F_104 ( V_319 , F_253 ( struct V_676 , V_15 ) ) ;
memcpy ( V_677 -> V_320 , V_666 , V_252 ) ;
memcpy ( V_677 -> V_321 , V_12 -> V_26 . V_251 , V_252 ) ;
V_677 -> V_678 = F_254 ( V_679 ) ;
V_677 -> V_680 = V_681 ;
switch ( V_673 ) {
case V_682 :
V_677 -> V_630 = V_683 ;
V_677 -> V_673 = V_682 ;
F_104 ( V_319 , sizeof( V_677 -> V_15 . V_684 ) ) ;
V_677 -> V_15 . V_684 . V_674 = V_674 ;
V_677 -> V_15 . V_684 . V_685 =
F_255 ( F_250 ( V_12 ) ) ;
F_256 ( V_12 , V_319 , false , V_332 ) ;
F_257 ( V_12 , V_319 , false , V_332 ) ;
F_249 ( V_319 ) ;
break;
case V_686 :
V_677 -> V_630 = V_683 ;
V_677 -> V_673 = V_686 ;
F_104 ( V_319 , sizeof( V_677 -> V_15 . V_687 ) ) ;
V_677 -> V_15 . V_687 . V_675 = F_255 ( V_675 ) ;
V_677 -> V_15 . V_687 . V_674 = V_674 ;
V_677 -> V_15 . V_687 . V_685 =
F_255 ( F_250 ( V_12 ) ) ;
F_256 ( V_12 , V_319 , false , V_332 ) ;
F_257 ( V_12 , V_319 , false , V_332 ) ;
F_249 ( V_319 ) ;
break;
case V_688 :
V_677 -> V_630 = V_683 ;
V_677 -> V_673 = V_688 ;
F_104 ( V_319 , sizeof( V_677 -> V_15 . V_689 ) ) ;
V_677 -> V_15 . V_689 . V_675 = F_255 ( V_675 ) ;
V_677 -> V_15 . V_689 . V_674 = V_674 ;
break;
case V_690 :
V_677 -> V_630 = V_683 ;
V_677 -> V_673 = V_690 ;
F_104 ( V_319 , sizeof( V_677 -> V_15 . V_691 ) ) ;
V_677 -> V_15 . V_691 . V_692 = F_255 ( V_675 ) ;
break;
case V_693 :
V_677 -> V_630 = V_683 ;
V_677 -> V_673 = V_693 ;
F_104 ( V_319 , sizeof( V_677 -> V_15 . V_694 ) ) ;
V_677 -> V_15 . V_694 . V_674 = V_674 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int
F_258 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_666 , T_3 V_673 , T_3 V_674 ,
T_2 V_675 , struct V_318 * V_319 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_331 V_332 = F_51 ( V_12 ) ;
struct V_620 * V_621 ;
V_621 = ( void * ) F_104 ( V_319 , 24 ) ;
memset ( V_621 , 0 , 24 ) ;
memcpy ( V_621 -> V_320 , V_666 , V_252 ) ;
memcpy ( V_621 -> V_321 , V_12 -> V_26 . V_251 , V_252 ) ;
memcpy ( V_621 -> V_230 , V_12 -> V_15 . V_25 . V_230 , V_252 ) ;
V_621 -> V_628 = F_255 ( V_640 |
V_695 ) ;
switch ( V_673 ) {
case V_696 :
F_104 ( V_319 , 1 + sizeof( V_621 -> V_15 . V_629 . V_15 . V_697 ) ) ;
V_621 -> V_15 . V_629 . V_630 = V_631 ;
V_621 -> V_15 . V_629 . V_15 . V_697 . V_673 =
V_696 ;
V_621 -> V_15 . V_629 . V_15 . V_697 . V_674 =
V_674 ;
V_621 -> V_15 . V_629 . V_15 . V_697 . V_685 =
F_255 ( F_250 ( V_12 ) ) ;
F_256 ( V_12 , V_319 , false , V_332 ) ;
F_257 ( V_12 , V_319 , false , V_332 ) ;
F_249 ( V_319 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_259 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_666 , T_3 V_673 , T_3 V_674 ,
T_2 V_675 , const T_3 * V_698 ,
T_5 V_699 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_318 * V_319 = NULL ;
bool V_700 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_701 ) )
return - V_470 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_560 )
return - V_43 ;
F_260 ( V_12 , L_2 ,
V_673 , V_666 ) ;
V_319 = F_103 ( V_9 -> V_104 . V_633 +
F_212 ( sizeof( struct V_620 ) ,
sizeof( struct V_676 ) ) +
50 +
7 +
V_699 +
sizeof( struct V_667 ) ) ;
if ( ! V_319 )
return - V_272 ;
F_232 ( V_319 , V_9 -> V_104 . V_633 ) ;
switch ( V_673 ) {
case V_682 :
case V_686 :
case V_688 :
case V_690 :
case V_693 :
V_19 = F_252 ( V_2 , V_18 , V_666 ,
V_673 , V_674 ,
V_675 , V_319 ) ;
V_700 = false ;
break;
case V_696 :
V_19 = F_258 ( V_2 , V_18 , V_666 , V_673 ,
V_674 , V_675 ,
V_319 ) ;
V_700 = true ;
break;
default:
V_19 = - V_470 ;
break;
}
if ( V_19 < 0 )
goto V_702;
if ( V_699 )
memcpy ( F_104 ( V_319 , V_699 ) , V_698 , V_699 ) ;
switch ( V_673 ) {
case V_682 :
case V_688 :
case V_690 :
case V_693 :
F_251 ( V_319 , V_12 -> V_26 . V_251 , V_666 ,
V_12 -> V_15 . V_25 . V_230 ) ;
break;
case V_686 :
case V_696 :
F_251 ( V_319 , V_666 , V_12 -> V_26 . V_251 ,
V_12 -> V_15 . V_25 . V_230 ) ;
break;
default:
V_19 = - V_470 ;
goto V_702;
}
if ( V_700 ) {
F_234 ( V_12 , V_319 ) ;
return 0 ;
}
switch ( V_673 ) {
case V_682 :
case V_686 :
F_261 ( V_319 , V_703 ) ;
V_319 -> V_704 = 2 ;
break;
default:
F_261 ( V_319 , V_705 ) ;
V_319 -> V_704 = 5 ;
break;
}
F_262 () ;
V_19 = F_263 ( V_319 , V_18 ) ;
F_264 () ;
return V_19 ;
V_702:
F_265 ( V_319 ) ;
return V_19 ;
}
static int F_266 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_666 , enum V_706 V_707 )
{
struct V_34 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_701 ) )
return - V_470 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_43 ;
F_260 ( V_12 , L_3 , V_707 , V_666 ) ;
switch ( V_707 ) {
case V_708 :
F_39 () ;
V_23 = F_26 ( V_12 , V_666 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_632 ;
}
F_111 ( V_23 , V_709 ) ;
F_43 () ;
break;
case V_710 :
return F_267 ( V_12 , V_666 ) ;
case V_711 :
case V_712 :
case V_713 :
return - V_470 ;
default:
return - V_470 ;
}
return 0 ;
}
static int F_268 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_666 , T_4 * V_73 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_714 * V_715 ;
struct V_318 * V_319 ;
int V_279 = sizeof( * V_715 ) ;
T_7 V_716 ;
bool V_717 ;
struct V_718 * V_719 ;
struct V_34 * V_23 ;
struct V_222 * V_223 ;
enum V_331 V_332 ;
F_39 () ;
V_223 = F_40 ( V_12 -> V_26 . V_223 ) ;
if ( F_65 ( ! V_223 ) ) {
F_43 () ;
return - V_43 ;
}
V_332 = V_223 -> V_233 . V_234 -> V_332 ;
V_23 = F_26 ( V_12 , V_666 ) ;
if ( V_23 ) {
V_717 = F_28 ( V_23 , V_211 ) ;
} else {
F_43 () ;
return - V_632 ;
}
if ( V_717 ) {
V_716 = F_255 ( V_720 |
V_721 |
V_722 ) ;
} else {
V_279 -= 2 ;
V_716 = F_255 ( V_720 |
V_723 |
V_722 ) ;
}
V_319 = F_103 ( V_9 -> V_104 . V_633 + V_279 ) ;
if ( ! V_319 ) {
F_43 () ;
return - V_272 ;
}
V_319 -> V_18 = V_18 ;
F_232 ( V_319 , V_9 -> V_104 . V_633 ) ;
V_715 = ( void * ) F_104 ( V_319 , V_279 ) ;
V_715 -> V_628 = V_716 ;
V_715 -> V_724 = 0 ;
memcpy ( V_715 -> V_725 , V_23 -> V_23 . V_251 , V_252 ) ;
memcpy ( V_715 -> V_726 , V_12 -> V_26 . V_251 , V_252 ) ;
memcpy ( V_715 -> V_727 , V_12 -> V_26 . V_251 , V_252 ) ;
V_715 -> V_728 = 0 ;
V_719 = F_233 ( V_319 ) ;
V_719 -> V_5 |= V_625 |
V_624 ;
F_261 ( V_319 , V_729 ) ;
V_319 -> V_704 = 7 ;
if ( V_717 )
V_715 -> V_730 = F_255 ( 7 ) ;
F_262 () ;
F_269 ( V_12 , V_319 , V_332 ) ;
F_264 () ;
F_43 () ;
* V_73 = ( unsigned long ) V_319 ;
return 0 ;
}
static int F_270 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_254 * V_255 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_222 * V_223 ;
int V_19 = - V_731 ;
F_39 () ;
V_223 = F_40 ( V_12 -> V_26 . V_223 ) ;
if ( V_223 ) {
* V_255 = V_223 -> V_233 ;
V_19 = 0 ;
}
F_43 () ;
return V_19 ;
}
static void F_271 ( struct V_2 * V_2 , bool V_565 )
{
F_272 ( F_2 ( V_2 ) , V_565 ) ;
}
