static struct V_1 * F_1 ( struct V_2 * V_2 , char * V_3 ,
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
struct V_1 * V_10 ,
enum V_4 type , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_17 ;
V_17 = F_9 ( V_12 , type ) ;
if ( V_17 )
return V_17 ;
if ( type == V_18 &&
V_7 && V_7 -> V_19 == 0 )
F_10 ( V_12 -> V_15 . V_20 . V_21 , NULL ) ;
else if ( type == V_22 &&
V_7 && V_7 -> V_19 >= 0 )
V_12 -> V_15 . V_23 . V_19 = V_7 -> V_19 ;
if ( V_12 -> V_24 . type == V_14 && V_5 ) {
struct V_8 * V_9 = V_12 -> V_9 ;
if ( F_11 ( V_12 ) ) {
if ( ( * V_5 & V_25 ) !=
( V_12 -> V_15 . V_16 & V_25 ) )
return - V_26 ;
F_12 ( V_12 , - 1 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
F_12 ( V_12 , 1 ) ;
F_13 ( V_9 ) ;
} else {
V_12 -> V_15 . V_16 = * V_5 ;
}
}
return 0 ;
}
static int F_14 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
V_12 -> V_27 = V_27 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 V_28 , bool V_29 , const T_3 * V_30 ,
struct V_31 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 = NULL ;
struct V_33 * V_34 ;
int V_13 ;
if ( ! F_11 ( V_12 ) )
return - V_35 ;
switch ( V_7 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 :
if ( F_16 ( V_12 -> V_9 -> V_40 ) )
return - V_41 ;
break;
default:
break;
}
V_34 = F_17 ( V_7 -> V_36 , V_28 , V_7 -> V_42 ,
V_7 -> V_34 , V_7 -> V_43 , V_7 -> V_44 ) ;
if ( F_16 ( V_34 ) )
return F_18 ( V_34 ) ;
if ( V_29 )
V_34 -> V_45 . V_5 |= V_46 ;
F_19 ( & V_12 -> V_9 -> V_47 ) ;
if ( V_30 ) {
if ( F_20 ( & V_12 -> V_24 ) )
V_21 = F_21 ( V_12 , V_30 ) ;
else
V_21 = F_22 ( V_12 , V_30 ) ;
if ( ! V_21 ) {
F_23 ( V_12 -> V_9 , V_34 ) ;
V_13 = - V_48 ;
goto V_49;
}
}
V_13 = F_24 ( V_34 , V_12 , V_21 ) ;
if ( V_13 )
F_23 ( V_12 -> V_9 , V_34 ) ;
V_49:
F_25 ( & V_12 -> V_9 -> V_47 ) ;
return V_13 ;
}
static int F_26 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 V_28 , bool V_29 , const T_3 * V_30 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_32 * V_21 ;
struct V_33 * V_34 = NULL ;
int V_17 ;
F_19 ( & V_9 -> V_47 ) ;
F_19 ( & V_9 -> V_50 ) ;
if ( V_30 ) {
V_17 = - V_48 ;
V_21 = F_22 ( V_12 , V_30 ) ;
if ( ! V_21 )
goto V_49;
if ( V_29 )
V_34 = F_27 ( V_9 , V_21 -> V_51 ) ;
else
V_34 = F_27 ( V_9 , V_21 -> V_52 [ V_28 ] ) ;
} else
V_34 = F_27 ( V_9 , V_12 -> V_53 [ V_28 ] ) ;
if ( ! V_34 ) {
V_17 = - V_48 ;
goto V_49;
}
F_28 ( V_34 ) ;
V_17 = 0 ;
V_49:
F_25 ( & V_9 -> V_50 ) ;
F_25 ( & V_9 -> V_47 ) ;
return V_17 ;
}
static int F_29 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 V_28 , bool V_29 , const T_3 * V_30 ,
void * V_54 ,
void (* F_30)( void * V_54 ,
struct V_31 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_32 * V_21 = NULL ;
T_3 V_44 [ 6 ] = { 0 } ;
struct V_31 V_7 ;
struct V_33 * V_34 = NULL ;
T_4 V_55 ;
T_1 V_56 ;
T_2 V_57 ;
int V_13 = - V_48 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
if ( V_30 ) {
V_21 = F_22 ( V_12 , V_30 ) ;
if ( ! V_21 )
goto V_58;
if ( V_29 )
V_34 = F_32 ( V_21 -> V_51 ) ;
else if ( V_28 < V_59 )
V_34 = F_32 ( V_21 -> V_52 [ V_28 ] ) ;
} else
V_34 = F_32 ( V_12 -> V_53 [ V_28 ] ) ;
if ( ! V_34 )
goto V_58;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_36 = V_34 -> V_45 . V_36 ;
switch ( V_34 -> V_45 . V_36 ) {
case V_38 :
V_56 = V_34 -> V_15 . V_60 . V_61 . V_56 ;
V_57 = V_34 -> V_15 . V_60 . V_61 . V_57 ;
if ( V_34 -> V_5 & V_62 )
F_33 ( V_12 -> V_9 ,
V_34 -> V_45 . V_63 ,
& V_56 , & V_57 ) ;
V_44 [ 0 ] = V_57 & 0xff ;
V_44 [ 1 ] = ( V_57 >> 8 ) & 0xff ;
V_44 [ 2 ] = V_56 & 0xff ;
V_44 [ 3 ] = ( V_56 >> 8 ) & 0xff ;
V_44 [ 4 ] = ( V_56 >> 16 ) & 0xff ;
V_44 [ 5 ] = ( V_56 >> 24 ) & 0xff ;
V_7 . V_44 = V_44 ;
V_7 . V_43 = 6 ;
break;
case V_64 :
V_55 = F_34 ( & V_34 -> V_15 . V_65 . V_66 ) ;
V_44 [ 0 ] = V_55 ;
V_44 [ 1 ] = V_55 >> 8 ;
V_44 [ 2 ] = V_55 >> 16 ;
V_44 [ 3 ] = V_55 >> 24 ;
V_44 [ 4 ] = V_55 >> 32 ;
V_44 [ 5 ] = V_55 >> 40 ;
V_7 . V_44 = V_44 ;
V_7 . V_43 = 6 ;
break;
case V_67 :
V_55 = F_34 ( & V_34 -> V_15 . V_68 . V_66 ) ;
V_44 [ 0 ] = V_55 ;
V_44 [ 1 ] = V_55 >> 8 ;
V_44 [ 2 ] = V_55 >> 16 ;
V_44 [ 3 ] = V_55 >> 24 ;
V_44 [ 4 ] = V_55 >> 32 ;
V_44 [ 5 ] = V_55 >> 40 ;
V_7 . V_44 = V_44 ;
V_7 . V_43 = 6 ;
break;
}
V_7 . V_34 = V_34 -> V_45 . V_34 ;
V_7 . V_42 = V_34 -> V_45 . V_69 ;
F_30 ( V_54 , & V_7 ) ;
V_13 = 0 ;
V_58:
F_35 () ;
return V_13 ;
}
static int F_36 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_28 , bool V_70 ,
bool V_71 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_37 ( V_12 , V_28 , V_70 , V_71 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_28 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_39 ( V_12 , V_28 ) ;
return 0 ;
}
static void F_40 ( struct V_72 * V_73 , struct V_32 * V_21 , int V_74 )
{
if ( ! ( V_73 -> V_5 & V_75 ) ) {
struct V_76 * V_77 ;
V_77 = V_21 -> V_9 -> V_78 . V_2 -> V_79 [
V_21 -> V_9 -> V_78 . V_45 . V_80 -> V_81 ] ;
V_73 -> V_82 = V_77 -> V_83 [ V_74 ] . V_84 ;
} else
V_73 -> V_85 = V_74 ;
}
void F_41 ( struct V_32 * V_21 ,
const struct V_86 * V_73 ,
struct V_72 * V_87 )
{
V_87 -> V_5 = 0 ;
if ( V_73 -> V_5 & V_88 )
V_87 -> V_5 |= V_75 ;
if ( V_73 -> V_5 & V_89 )
V_87 -> V_5 |= V_90 ;
if ( V_73 -> V_5 & V_91 )
V_87 -> V_5 |= V_92 ;
F_40 ( V_87 , V_21 , V_73 -> V_74 ) ;
}
static void F_42 ( struct V_32 * V_21 , struct V_93 * V_94 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_95 V_96 ;
V_94 -> V_97 = V_12 -> V_9 -> V_98 ;
V_94 -> V_99 = V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 ;
F_43 ( & V_96 ) ;
V_94 -> V_114 = V_96 . V_115 - V_21 -> V_116 ;
V_94 -> V_117 = F_44 ( V_118 - V_21 -> V_119 ) ;
V_94 -> V_120 = V_21 -> V_120 ;
V_94 -> V_121 = V_21 -> V_121 ;
V_94 -> V_122 = V_21 -> V_122 ;
V_94 -> V_123 = V_21 -> V_123 ;
V_94 -> V_124 = V_21 -> V_125 ;
V_94 -> V_126 = V_21 -> V_127 ;
V_94 -> V_128 = V_21 -> V_129 ;
V_94 -> V_130 = V_21 -> V_130 ;
if ( ( V_21 -> V_9 -> V_78 . V_5 & V_131 ) ||
( V_21 -> V_9 -> V_78 . V_5 & V_132 ) ) {
V_94 -> V_99 |= V_133 | V_134 ;
V_94 -> signal = ( V_135 ) V_21 -> V_136 ;
V_94 -> V_137 = ( V_135 ) - F_45 ( & V_21 -> V_138 ) ;
}
F_41 ( V_21 , & V_21 -> V_139 , & V_94 -> V_140 ) ;
V_94 -> V_141 . V_5 = 0 ;
if ( V_21 -> V_142 & V_143 )
V_94 -> V_141 . V_5 |= V_75 ;
if ( V_21 -> V_142 & V_144 )
V_94 -> V_141 . V_5 |= V_90 ;
if ( V_21 -> V_142 & V_145 )
V_94 -> V_141 . V_5 |= V_92 ;
F_40 ( & V_94 -> V_141 , V_21 , V_21 -> V_146 ) ;
if ( F_20 ( & V_12 -> V_24 ) ) {
#ifdef F_46
V_94 -> V_99 |= V_147 |
V_148 |
V_149 ;
V_94 -> V_150 = F_47 ( V_21 -> V_150 ) ;
V_94 -> V_151 = F_47 ( V_21 -> V_151 ) ;
V_94 -> V_152 = V_21 -> V_152 ;
if ( F_48 ( V_21 , V_153 ) ) {
V_94 -> V_99 |= V_154 ;
V_94 -> V_155 = V_21 -> V_155 ;
}
#endif
}
V_94 -> V_156 . V_5 = 0 ;
if ( V_12 -> V_24 . V_157 . V_158 )
V_94 -> V_156 . V_5 |= V_159 ;
if ( V_12 -> V_24 . V_157 . V_160 )
V_94 -> V_156 . V_5 |= V_161 ;
if ( V_12 -> V_24 . V_157 . V_162 )
V_94 -> V_156 . V_5 |= V_163 ;
V_94 -> V_156 . V_164 = V_12 -> V_9 -> V_78 . V_45 . V_165 ;
V_94 -> V_156 . V_166 = V_12 -> V_24 . V_157 . V_167 ;
V_94 -> V_168 . V_169 = 0 ;
V_94 -> V_168 . V_170 = F_49 ( V_171 ) |
F_49 ( V_172 ) |
F_49 ( V_173 ) |
F_49 ( V_174 ) |
F_49 ( V_175 ) |
F_49 ( V_176 ) ;
if ( F_48 ( V_21 , V_177 ) )
V_94 -> V_168 . V_169 |= F_49 ( V_171 ) ;
if ( F_48 ( V_21 , V_178 ) )
V_94 -> V_168 . V_169 |= F_49 ( V_172 ) ;
if ( F_48 ( V_21 , V_179 ) )
V_94 -> V_168 . V_169 |= F_49 ( V_173 ) ;
if ( F_48 ( V_21 , V_180 ) )
V_94 -> V_168 . V_169 |= F_49 ( V_174 ) ;
if ( F_48 ( V_21 , V_181 ) )
V_94 -> V_168 . V_169 |= F_49 ( V_175 ) ;
if ( F_48 ( V_21 , V_182 ) )
V_94 -> V_168 . V_169 |= F_49 ( V_176 ) ;
}
static int F_50 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int V_183 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_184 = 0 ;
if ( V_183 == V_185 )
V_184 += V_186 ;
V_184 += F_51 ( V_12 , V_183 ) ;
if ( V_184 == 0 )
return - V_187 ;
return V_184 ;
}
static void F_52 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_188 * V_189 ,
T_4 * V_190 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_93 V_94 ;
struct V_191 V_192 ;
int V_193 , V_194 ;
#define F_53 7
memset ( V_190 , 0 , sizeof( T_4 ) * V_186 ) ;
#define F_54 ( V_21 ) \
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
F_31 () ;
if ( V_12 -> V_24 . type == V_22 ) {
V_21 = F_22 ( V_12 , V_12 -> V_15 . V_23 . V_195 ) ;
if ( ! ( V_21 && ! F_55 ( V_21 -> V_12 -> V_10 != V_10 ) ) )
goto V_196;
V_193 = 0 ;
F_54 ( V_21 ) ;
V_190 [ V_193 ++ ] = V_21 -> V_197 ;
V_94 . V_99 = 0 ;
F_42 ( V_21 , & V_94 ) ;
if ( V_94 . V_99 & V_107 )
V_190 [ V_193 ] = 100000 *
F_56 ( & V_94 . V_140 ) ;
V_193 ++ ;
if ( V_94 . V_99 & V_108 )
V_190 [ V_193 ] = 100000 *
F_56 ( & V_94 . V_141 ) ;
V_193 ++ ;
if ( V_94 . V_99 & V_134 )
V_190 [ V_193 ] = ( T_3 ) V_94 . V_137 ;
V_193 ++ ;
} else {
F_57 (sta, &local->sta_list, list) {
if ( V_21 -> V_12 -> V_10 != V_10 )
continue;
V_193 = 0 ;
F_54 ( V_21 ) ;
}
}
V_196:
V_193 = V_186 - F_53 ;
V_194 = 0 ;
while ( true ) {
V_192 . V_99 = 0 ;
if ( F_58 ( V_9 , V_194 , & V_192 ) != 0 ) {
V_192 . V_99 = 0 ;
break;
}
if ( V_192 . V_80 &&
( V_9 -> V_198 -> V_199 ==
V_192 . V_80 -> V_199 ) )
break;
V_194 ++ ;
}
if ( V_192 . V_99 )
V_190 [ V_193 ++ ] = V_192 . V_80 -> V_199 ;
else
V_190 [ V_193 ++ ] = 0 ;
if ( V_192 . V_99 & V_200 )
V_190 [ V_193 ++ ] = ( T_3 ) V_192 . V_201 ;
else
V_190 [ V_193 ++ ] = - 1LL ;
if ( V_192 . V_99 & V_202 )
V_190 [ V_193 ++ ] = V_192 . V_203 ;
else
V_190 [ V_193 ++ ] = - 1LL ;
if ( V_192 . V_99 & V_204 )
V_190 [ V_193 ++ ] = V_192 . V_205 ;
else
V_190 [ V_193 ++ ] = - 1LL ;
if ( V_192 . V_99 & V_206 )
V_190 [ V_193 ++ ] = V_192 . V_207 ;
else
V_190 [ V_193 ++ ] = - 1LL ;
if ( V_192 . V_99 & V_208 )
V_190 [ V_193 ++ ] = V_192 . V_209 ;
else
V_190 [ V_193 ++ ] = - 1LL ;
if ( V_192 . V_99 & V_210 )
V_190 [ V_193 ++ ] = V_192 . V_211 ;
else
V_190 [ V_193 ++ ] = - 1LL ;
F_35 () ;
if ( F_55 ( V_193 != V_186 ) )
return;
F_59 ( V_12 , V_189 , & ( V_190 [ V_186 ] ) ) ;
}
static void F_60 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_1 V_183 , T_3 * V_190 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_212 = 0 ;
if ( V_183 == V_185 ) {
V_212 = sizeof( V_213 ) ;
memcpy ( V_190 , * V_213 , V_212 ) ;
}
F_61 ( V_12 , V_183 , & ( V_190 [ V_212 ] ) ) ;
}
static int F_62 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , T_3 * V_214 , struct V_93 * V_94 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 ;
int V_17 = - V_48 ;
F_31 () ;
V_21 = F_63 ( V_12 , V_74 ) ;
if ( V_21 ) {
V_17 = 0 ;
memcpy ( V_214 , V_21 -> V_21 . V_215 , V_216 ) ;
F_42 ( V_21 , V_94 ) ;
}
F_35 () ;
return V_17 ;
}
static int F_64 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , struct V_191 * V_192 )
{
struct V_8 * V_9 = F_65 ( V_10 -> V_217 ) ;
return F_58 ( V_9 , V_74 , V_192 ) ;
}
static int F_66 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_214 , struct V_93 * V_94 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 ;
int V_17 = - V_48 ;
F_31 () ;
V_21 = F_22 ( V_12 , V_214 ) ;
if ( V_21 ) {
V_17 = 0 ;
F_42 ( V_21 , V_94 ) ;
}
F_35 () ;
return V_17 ;
}
static int F_67 ( struct V_11 * V_12 ,
const T_3 * V_218 , T_5 V_219 )
{
struct V_220 * V_221 , * V_222 ;
if ( ! V_218 || ! V_219 )
return 1 ;
V_222 = F_68 ( V_12 -> V_15 . V_223 . V_224 ) ;
V_221 = F_69 ( V_219 ) ;
if ( ! V_221 )
return - V_225 ;
memcpy ( F_70 ( V_221 , V_219 ) , V_218 , V_219 ) ;
F_71 ( V_12 -> V_15 . V_223 . V_224 , V_221 ) ;
if ( V_222 ) {
F_72 () ;
F_73 ( V_222 ) ;
}
return 0 ;
}
static int F_74 ( struct V_11 * V_12 ,
struct V_226 * V_7 )
{
struct V_227 * V_221 , * V_222 ;
int V_228 , V_229 ;
int V_230 , V_13 ;
T_1 V_231 = V_232 ;
V_222 = F_68 ( V_12 -> V_15 . V_223 . V_233 ) ;
if ( ! V_7 -> V_234 && ! V_222 )
return - V_41 ;
if ( V_7 -> V_234 )
V_228 = V_7 -> V_235 ;
else
V_228 = V_222 -> V_235 ;
if ( V_7 -> V_236 || ! V_222 )
V_229 = V_7 -> V_237 ;
else
V_229 = V_222 -> V_237 ;
V_230 = sizeof( * V_221 ) + V_228 + V_229 ;
V_221 = F_75 ( V_230 , V_238 ) ;
if ( ! V_221 )
return - V_225 ;
V_221 -> V_234 = ( ( T_3 * ) V_221 ) + sizeof( * V_221 ) ;
V_221 -> V_236 = V_221 -> V_234 + V_228 ;
V_221 -> V_235 = V_228 ;
V_221 -> V_237 = V_229 ;
if ( V_7 -> V_234 )
memcpy ( V_221 -> V_234 , V_7 -> V_234 , V_228 ) ;
else
memcpy ( V_221 -> V_234 , V_222 -> V_234 , V_228 ) ;
if ( V_7 -> V_236 )
memcpy ( V_221 -> V_236 , V_7 -> V_236 , V_229 ) ;
else
if ( V_222 )
memcpy ( V_221 -> V_236 , V_222 -> V_236 , V_229 ) ;
V_13 = F_67 ( V_12 , V_7 -> V_224 ,
V_7 -> V_239 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_231 |= V_240 ;
F_71 ( V_12 -> V_15 . V_223 . V_233 , V_221 ) ;
if ( V_222 )
F_76 ( V_222 , V_241 ) ;
return V_231 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_242 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_227 * V_222 ;
struct V_11 * V_20 ;
T_1 V_231 = V_243 |
V_244 |
V_232 |
V_245 ;
int V_13 ;
V_222 = F_68 ( V_12 -> V_15 . V_223 . V_233 ) ;
if ( V_222 )
return - V_246 ;
V_12 -> V_247 = V_7 -> V_248 . V_249 ;
V_12 -> V_250 = V_7 -> V_248 . V_250 ;
F_78 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_20 -> V_247 =
V_7 -> V_248 . V_249 ;
V_20 -> V_250 =
V_7 -> V_248 . V_250 ;
}
V_12 -> V_24 . V_157 . V_167 = V_7 -> V_166 ;
V_12 -> V_24 . V_157 . V_164 = V_7 -> V_164 ;
V_12 -> V_24 . V_157 . V_251 = V_7 -> V_251 ;
if ( V_7 -> V_251 )
memcpy ( V_12 -> V_24 . V_157 . V_252 , V_7 -> V_252 ,
V_7 -> V_251 ) ;
V_12 -> V_24 . V_157 . V_253 =
( V_7 -> V_253 != V_254 ) ;
V_13 = F_74 ( V_12 , & V_7 -> V_233 ) ;
if ( V_13 < 0 )
return V_13 ;
V_231 |= V_13 ;
F_79 ( V_12 , V_231 ) ;
F_80 ( V_10 ) ;
F_78 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_80 ( V_20 -> V_10 ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_226 * V_7 )
{
struct V_11 * V_12 ;
struct V_227 * V_222 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
V_222 = F_68 ( V_12 -> V_15 . V_223 . V_233 ) ;
if ( ! V_222 )
return - V_48 ;
V_13 = F_74 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_79 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 , * V_20 ;
struct V_227 * V_222 ;
V_12 = F_5 ( V_10 ) ;
V_222 = F_68 ( V_12 -> V_15 . V_223 . V_233 ) ;
if ( ! V_222 )
return - V_48 ;
F_78 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_83 ( V_20 -> V_10 ) ;
F_83 ( V_10 ) ;
F_10 ( V_12 -> V_15 . V_223 . V_233 , NULL ) ;
F_76 ( V_222 , V_241 ) ;
F_79 ( V_12 , V_244 ) ;
return 0 ;
}
static void F_84 ( struct V_32 * V_21 )
{
struct V_255 * V_256 ;
struct V_220 * V_257 ;
V_257 = F_69 ( sizeof( * V_256 ) ) ;
if ( ! V_257 )
return;
V_256 = (struct V_255 * ) F_70 ( V_257 , sizeof( * V_256 ) ) ;
memset ( V_256 -> V_258 , 0xff , V_216 ) ;
memcpy ( V_256 -> V_259 , V_21 -> V_21 . V_215 , V_216 ) ;
V_256 -> V_260 = F_85 ( 6 ) ;
V_256 -> V_261 = 0 ;
V_256 -> V_262 = 0x01 ;
V_256 -> V_263 = 0xaf ;
V_256 -> V_264 [ 0 ] = 0x81 ;
V_256 -> V_264 [ 1 ] = 1 ;
V_256 -> V_264 [ 2 ] = 0 ;
V_257 -> V_10 = V_21 -> V_12 -> V_10 ;
V_257 -> V_265 = F_86 ( V_257 , V_21 -> V_12 -> V_10 ) ;
memset ( V_257 -> V_266 , 0 , sizeof( V_257 -> V_266 ) ) ;
F_87 ( V_257 ) ;
}
static int F_88 ( struct V_8 * V_9 ,
struct V_32 * V_21 ,
struct V_267 * V_7 )
{
int V_17 = 0 ;
T_1 V_268 ;
int V_193 , V_269 ;
struct V_76 * V_77 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_170 , V_169 ;
V_77 = V_9 -> V_78 . V_2 -> V_79 [ V_9 -> V_198 -> V_81 ] ;
V_170 = V_7 -> V_270 ;
V_169 = V_7 -> V_271 ;
if ( V_170 & F_49 ( V_175 ) ) {
if ( F_55 ( ! F_20 ( & V_12 -> V_24 ) ) )
return - V_41 ;
if ( V_169 & F_49 ( V_175 ) &&
! F_48 ( V_21 , V_181 ) ) {
V_17 = F_89 ( V_21 , V_272 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_89 ( V_21 , V_273 ) ;
if ( V_17 )
return V_17 ;
}
}
if ( V_170 & F_49 ( V_171 ) ) {
if ( V_169 & F_49 ( V_171 ) )
V_17 = F_89 ( V_21 , V_274 ) ;
else if ( F_48 ( V_21 , V_177 ) )
V_17 = F_89 ( V_21 , V_273 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_170 & F_49 ( V_175 ) ) {
if ( F_55 ( ! F_20 ( & V_12 -> V_24 ) ) )
return - V_41 ;
if ( ! ( V_169 & F_49 ( V_175 ) ) &&
F_48 ( V_21 , V_181 ) ) {
V_17 = F_89 ( V_21 , V_272 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_89 ( V_21 , V_275 ) ;
if ( V_17 )
return V_17 ;
}
}
if ( V_170 & F_49 ( V_172 ) ) {
if ( V_169 & F_49 ( V_172 ) )
F_90 ( V_21 , V_178 ) ;
else
F_91 ( V_21 , V_178 ) ;
}
if ( V_170 & F_49 ( V_173 ) ) {
if ( V_169 & F_49 ( V_173 ) ) {
F_90 ( V_21 , V_179 ) ;
V_21 -> V_21 . V_276 = true ;
} else {
F_91 ( V_21 , V_179 ) ;
V_21 -> V_21 . V_276 = false ;
}
}
if ( V_170 & F_49 ( V_174 ) ) {
if ( V_169 & F_49 ( V_174 ) )
F_90 ( V_21 , V_180 ) ;
else
F_91 ( V_21 , V_180 ) ;
}
if ( V_170 & F_49 ( V_176 ) ) {
if ( V_169 & F_49 ( V_176 ) )
F_90 ( V_21 , V_182 ) ;
else
F_91 ( V_21 , V_182 ) ;
}
if ( V_7 -> V_277 & V_278 ) {
V_21 -> V_21 . V_279 = V_7 -> V_279 ;
V_21 -> V_21 . V_280 = V_7 -> V_280 ;
}
if ( V_7 -> V_281 )
V_21 -> V_21 . V_281 = V_7 -> V_281 ;
if ( V_7 -> V_282 >= 0 )
V_21 -> V_282 = V_7 -> V_282 ;
if ( V_7 -> V_283 ) {
V_268 = 0 ;
for ( V_193 = 0 ; V_193 < V_7 -> V_284 ; V_193 ++ ) {
int V_73 = ( V_7 -> V_283 [ V_193 ] & 0x7f ) * 5 ;
for ( V_269 = 0 ; V_269 < V_77 -> V_285 ; V_269 ++ ) {
if ( V_77 -> V_83 [ V_269 ] . V_84 == V_73 )
V_268 |= F_49 ( V_269 ) ;
}
}
V_21 -> V_21 . V_286 [ V_9 -> V_198 -> V_81 ] = V_268 ;
}
if ( V_7 -> V_287 )
F_92 ( V_12 , V_77 ,
V_7 -> V_287 ,
& V_21 -> V_21 . V_288 ) ;
if ( F_20 ( & V_12 -> V_24 ) ) {
#ifdef F_46
if ( V_12 -> V_15 . V_289 . V_290 & V_291 )
switch ( V_7 -> V_152 ) {
case V_292 :
case V_293 :
case V_294 :
V_21 -> V_152 = V_7 -> V_152 ;
break;
default:
break;
}
else
switch ( V_7 -> V_295 ) {
case V_296 :
F_93 ( V_21 ) ;
break;
case V_297 :
F_94 ( V_21 ) ;
break;
}
#endif
}
return 0 ;
}
static int F_95 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_214 , struct V_267 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_32 * V_21 ;
struct V_11 * V_12 ;
int V_13 ;
int V_298 ;
if ( V_7 -> V_20 ) {
V_12 = F_5 ( V_7 -> V_20 ) ;
if ( V_12 -> V_24 . type != V_18 &&
V_12 -> V_24 . type != V_299 )
return - V_41 ;
} else
V_12 = F_5 ( V_10 ) ;
if ( F_96 ( V_214 , V_12 -> V_24 . V_215 ) )
return - V_41 ;
if ( F_97 ( V_214 ) )
return - V_41 ;
V_21 = F_98 ( V_12 , V_214 , V_238 ) ;
if ( ! V_21 )
return - V_225 ;
F_99 ( V_21 , V_272 ) ;
F_99 ( V_21 , V_273 ) ;
V_13 = F_88 ( V_9 , V_21 , V_7 ) ;
if ( V_13 ) {
F_100 ( V_9 , V_21 ) ;
return V_13 ;
}
if ( ! F_48 ( V_21 , V_182 ) )
F_101 ( V_21 ) ;
V_298 = V_12 -> V_24 . type == V_18 ||
V_12 -> V_24 . type == V_299 ;
V_13 = F_102 ( V_21 ) ;
if ( V_13 ) {
F_35 () ;
return V_13 ;
}
if ( V_298 )
F_84 ( V_21 ) ;
F_35 () ;
return 0 ;
}
static int F_103 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_214 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_214 )
return F_104 ( V_12 , V_214 ) ;
F_105 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 * V_214 ,
struct V_267 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_32 * V_21 ;
struct V_11 * V_300 ;
int V_13 ;
F_19 ( & V_9 -> V_47 ) ;
V_21 = F_22 ( V_12 , V_214 ) ;
if ( ! V_21 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_48 ;
}
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_283 &&
! F_48 ( V_21 , V_182 ) ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_41 ;
}
if ( V_7 -> V_20 && V_7 -> V_20 != V_21 -> V_12 -> V_10 ) {
bool V_301 = false ;
bool V_302 = false ;
V_300 = F_5 ( V_7 -> V_20 ) ;
if ( V_300 -> V_24 . type != V_18 &&
V_300 -> V_24 . type != V_299 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_41 ;
}
if ( V_7 -> V_20 -> V_217 -> V_19 ) {
if ( V_300 -> V_15 . V_20 . V_21 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_26 ;
}
F_71 ( V_300 -> V_15 . V_20 . V_21 , V_21 ) ;
V_302 = true ;
}
if ( V_21 -> V_12 -> V_24 . type == V_18 &&
V_21 -> V_12 -> V_15 . V_20 . V_21 ) {
F_71 ( V_21 -> V_12 -> V_15 . V_20 . V_21 , NULL ) ;
V_301 = true ;
}
V_21 -> V_12 = V_300 ;
if ( V_21 -> V_197 == V_274 &&
V_301 != V_302 ) {
if ( V_302 )
F_107 ( & V_21 -> V_12 -> V_303 -> V_304 ) ;
else
F_108 ( & V_21 -> V_12 -> V_303 -> V_304 ) ;
}
F_84 ( V_21 ) ;
}
V_13 = F_88 ( V_9 , V_21 , V_7 ) ;
if ( V_13 ) {
F_25 ( & V_9 -> V_47 ) ;
return V_13 ;
}
if ( F_48 ( V_21 , V_182 ) && V_7 -> V_283 )
F_101 ( V_21 ) ;
F_25 ( & V_9 -> V_47 ) ;
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_270 & F_49 ( V_171 ) )
F_109 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_305 , T_3 * V_306 )
{
struct V_11 * V_12 ;
struct V_307 * V_308 ;
struct V_32 * V_21 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_21 = F_21 ( V_12 , V_306 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_48 ;
}
V_13 = F_111 ( V_305 , V_12 ) ;
if ( V_13 ) {
F_35 () ;
return V_13 ;
}
V_308 = F_112 ( V_305 , V_12 ) ;
if ( ! V_308 ) {
F_35 () ;
return - V_309 ;
}
F_113 ( V_308 , V_21 ) ;
F_35 () ;
return 0 ;
}
static int F_114 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_305 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_305 )
return F_115 ( V_305 , V_12 ) ;
F_116 ( V_12 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 * V_305 , T_3 * V_306 )
{
struct V_11 * V_12 ;
struct V_307 * V_308 ;
struct V_32 * V_21 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_21 = F_21 ( V_12 , V_306 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_48 ;
}
V_308 = F_112 ( V_305 , V_12 ) ;
if ( ! V_308 ) {
F_35 () ;
return - V_48 ;
}
F_113 ( V_308 , V_21 ) ;
F_35 () ;
return 0 ;
}
static void F_118 ( struct V_307 * V_308 , T_3 * V_306 ,
struct V_310 * V_311 )
{
struct V_32 * V_312 = F_32 ( V_308 -> V_306 ) ;
if ( V_312 )
memcpy ( V_306 , V_312 -> V_21 . V_215 , V_216 ) ;
else
memset ( V_306 , 0 , V_216 ) ;
V_311 -> V_97 = V_313 ;
V_311 -> V_99 = V_314 |
V_315 |
V_316 |
V_317 |
V_318 |
V_319 |
V_320 ;
V_311 -> V_321 = V_308 -> V_322 . V_323 ;
V_311 -> V_324 = V_308 -> V_324 ;
V_311 -> V_325 = V_308 -> V_325 ;
if ( F_119 ( V_118 , V_308 -> V_326 ) )
V_311 -> V_327 = F_44 ( V_308 -> V_326 - V_118 ) ;
V_311 -> V_328 =
F_44 ( V_308 -> V_328 ) ;
V_311 -> V_329 = V_308 -> V_329 ;
V_311 -> V_5 = 0 ;
if ( V_308 -> V_5 & V_330 )
V_311 -> V_5 |= V_331 ;
if ( V_308 -> V_5 & V_332 )
V_311 -> V_5 |= V_333 ;
if ( V_308 -> V_5 & V_334 )
V_311 -> V_5 |= V_335 ;
if ( V_308 -> V_5 & V_336 )
V_311 -> V_5 |= V_337 ;
if ( V_308 -> V_5 & V_332 )
V_311 -> V_5 |= V_333 ;
V_311 -> V_5 = V_308 -> V_5 ;
}
static int F_120 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_305 , T_3 * V_306 , struct V_310 * V_311 )
{
struct V_11 * V_12 ;
struct V_307 * V_308 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_308 = F_112 ( V_305 , V_12 ) ;
if ( ! V_308 ) {
F_35 () ;
return - V_48 ;
}
memcpy ( V_305 , V_308 -> V_305 , V_216 ) ;
F_118 ( V_308 , V_306 , V_311 ) ;
F_35 () ;
return 0 ;
}
static int F_121 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , T_3 * V_305 , T_3 * V_306 ,
struct V_310 * V_311 )
{
struct V_11 * V_12 ;
struct V_307 * V_308 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_308 = F_122 ( V_74 , V_12 ) ;
if ( ! V_308 ) {
F_35 () ;
return - V_48 ;
}
memcpy ( V_305 , V_308 -> V_305 , V_216 ) ;
F_118 ( V_308 , V_306 , V_311 ) ;
F_35 () ;
return 0 ;
}
static int F_123 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_338 * V_45 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
memcpy ( V_45 , & ( V_12 -> V_15 . V_289 . V_339 ) , sizeof( struct V_338 ) ) ;
return 0 ;
}
static inline bool F_124 ( enum V_340 V_341 , T_1 V_170 )
{
return ( V_170 >> ( V_341 - 1 ) ) & 0x1 ;
}
static int F_125 ( struct V_342 * V_343 ,
const struct V_344 * V_345 )
{
T_3 * V_346 ;
const T_3 * V_347 ;
struct V_11 * V_12 = F_126 ( V_343 ,
struct V_11 , V_15 . V_289 ) ;
V_346 = NULL ;
V_347 = V_343 -> V_348 ;
if ( V_345 -> V_349 ) {
V_346 = F_127 ( V_345 -> V_348 , V_345 -> V_349 ,
V_238 ) ;
if ( ! V_346 )
return - V_225 ;
}
V_343 -> V_349 = V_345 -> V_349 ;
V_343 -> V_348 = V_346 ;
F_128 ( V_347 ) ;
V_343 -> V_350 = V_345 -> V_350 ;
memcpy ( V_343 -> V_351 , V_345 -> V_351 , V_343 -> V_350 ) ;
V_343 -> V_352 = V_345 -> V_353 ;
V_343 -> V_354 = V_345 -> V_355 ;
V_343 -> V_356 = V_345 -> V_357 ;
V_343 -> V_290 = V_358 ;
if ( V_345 -> V_359 )
V_343 -> V_290 |= V_360 ;
if ( V_345 -> V_361 )
V_343 -> V_290 |= V_291 ;
memcpy ( V_12 -> V_24 . V_157 . V_362 , V_345 -> V_362 ,
sizeof( V_345 -> V_362 ) ) ;
return 0 ;
}
static int F_129 ( struct V_2 * V_2 ,
struct V_1 * V_10 , T_1 V_170 ,
const struct V_338 * V_363 )
{
struct V_338 * V_45 ;
struct V_11 * V_12 ;
struct V_342 * V_343 ;
V_12 = F_5 ( V_10 ) ;
V_343 = & V_12 -> V_15 . V_289 ;
V_45 = & ( V_12 -> V_15 . V_289 . V_339 ) ;
if ( F_124 ( V_364 , V_170 ) )
V_45 -> V_365 = V_363 -> V_365 ;
if ( F_124 ( V_366 , V_170 ) )
V_45 -> V_367 = V_363 -> V_367 ;
if ( F_124 ( V_368 , V_170 ) )
V_45 -> V_369 = V_363 -> V_369 ;
if ( F_124 ( V_370 , V_170 ) )
V_45 -> V_371 = V_363 -> V_371 ;
if ( F_124 ( V_372 , V_170 ) )
V_45 -> V_373 = V_363 -> V_373 ;
if ( F_124 ( V_374 , V_170 ) )
V_45 -> V_375 = V_363 -> V_375 ;
if ( F_124 ( V_376 , V_170 ) )
V_45 -> V_375 = V_363 -> V_377 ;
if ( F_124 ( V_378 , V_170 ) )
V_45 -> V_379 = V_363 -> V_379 ;
if ( F_124 ( V_380 , V_170 ) )
V_45 -> V_381 =
V_363 -> V_381 ;
if ( F_124 ( V_382 , V_170 ) )
V_45 -> V_383 =
V_363 -> V_383 ;
if ( F_124 ( V_384 , V_170 ) )
V_45 -> V_385 = V_363 -> V_385 ;
if ( F_124 ( V_386 , V_170 ) )
V_45 -> V_387 = V_363 -> V_387 ;
if ( F_124 ( V_388 , V_170 ) )
V_45 -> V_389 =
V_363 -> V_389 ;
if ( F_124 ( V_390 , V_170 ) )
V_45 -> V_391 =
V_363 -> V_391 ;
if ( F_124 ( V_392 , V_170 ) )
V_45 -> V_393 =
V_363 -> V_393 ;
if ( F_124 ( V_394 ,
V_170 ) )
V_45 -> V_395 =
V_363 -> V_395 ;
if ( F_124 ( V_396 , V_170 ) ) {
V_45 -> V_397 = V_363 -> V_397 ;
F_130 ( V_343 ) ;
}
if ( F_124 ( V_398 , V_170 ) ) {
if ( V_363 -> V_399 &&
! V_45 -> V_397 ) {
V_45 -> V_397 = 1 ;
F_130 ( V_343 ) ;
}
V_45 -> V_399 =
V_363 -> V_399 ;
}
if ( F_124 ( V_400 , V_170 ) ) {
V_45 -> V_401 =
V_363 -> V_401 ;
}
if ( F_124 ( V_402 , V_170 ) )
V_45 -> V_403 = V_363 -> V_403 ;
if ( F_124 ( V_404 , V_170 ) ) {
if ( ! ( V_12 -> V_9 -> V_78 . V_5 & V_131 ) )
return - V_405 ;
V_45 -> V_406 = V_363 -> V_406 ;
}
if ( F_124 ( V_407 , V_170 ) ) {
V_45 -> V_408 = V_363 -> V_408 ;
V_12 -> V_24 . V_157 . V_409 = V_363 -> V_408 ;
F_79 ( V_12 , V_410 ) ;
}
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const struct V_338 * V_45 ,
const struct V_344 * V_345 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_342 * V_343 = & V_12 -> V_15 . V_289 ;
int V_13 ;
memcpy ( & V_343 -> V_339 , V_45 , sizeof( struct V_338 ) ) ;
V_13 = F_125 ( V_343 , V_345 ) ;
if ( V_13 )
return V_13 ;
F_132 ( V_12 ) ;
return 0 ;
}
static int F_133 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_134 ( V_12 ) ;
return 0 ;
}
static int F_135 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_411 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_231 = 0 ;
V_12 = F_5 ( V_10 ) ;
if ( V_7 -> V_158 >= 0 ) {
V_12 -> V_24 . V_157 . V_158 = V_7 -> V_158 ;
V_231 |= V_412 ;
}
if ( V_7 -> V_160 >= 0 ) {
V_12 -> V_24 . V_157 . V_160 =
V_7 -> V_160 ;
V_231 |= V_413 ;
}
if ( ! V_12 -> V_24 . V_157 . V_162 &&
V_12 -> V_9 -> V_78 . V_45 . V_80 -> V_81 == V_414 ) {
V_12 -> V_24 . V_157 . V_162 = true ;
V_231 |= V_415 ;
}
if ( V_7 -> V_416 >= 0 ) {
V_12 -> V_24 . V_157 . V_162 =
V_7 -> V_416 ;
V_231 |= V_415 ;
}
if ( V_7 -> V_417 ) {
int V_193 , V_269 ;
T_1 V_268 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_76 * V_77 =
V_2 -> V_79 [ V_9 -> V_198 -> V_81 ] ;
for ( V_193 = 0 ; V_193 < V_7 -> V_418 ; V_193 ++ ) {
int V_73 = ( V_7 -> V_417 [ V_193 ] & 0x7f ) * 5 ;
for ( V_269 = 0 ; V_269 < V_77 -> V_285 ; V_269 ++ ) {
if ( V_77 -> V_83 [ V_269 ] . V_84 == V_73 )
V_268 |= F_49 ( V_269 ) ;
}
}
V_12 -> V_24 . V_157 . V_417 = V_268 ;
V_231 |= V_419 ;
}
if ( V_7 -> V_420 >= 0 ) {
if ( V_7 -> V_420 )
V_12 -> V_5 |= V_421 ;
else
V_12 -> V_5 &= ~ V_421 ;
}
if ( V_7 -> V_408 >= 0 ) {
V_12 -> V_24 . V_157 . V_409 =
( T_2 ) V_7 -> V_408 ;
V_231 |= V_410 ;
}
F_79 ( V_12 , V_231 ) ;
return 0 ;
}
static int F_136 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_422 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_423 V_424 ;
if ( ! V_9 -> V_425 -> V_426 )
return - V_187 ;
if ( V_9 -> V_78 . V_427 < V_428 )
return - V_187 ;
memset ( & V_424 , 0 , sizeof( V_424 ) ) ;
V_424 . V_429 = V_7 -> V_429 ;
V_424 . V_430 = V_7 -> V_431 ;
V_424 . V_432 = V_7 -> V_433 ;
V_424 . V_434 = V_7 -> V_434 ;
V_424 . V_435 = false ;
V_12 -> V_436 [ V_7 -> V_437 ] = V_424 ;
if ( F_137 ( V_9 , V_12 , V_7 -> V_437 , & V_424 ) ) {
F_138 ( V_9 -> V_78 . V_2 ,
L_1 ,
V_7 -> V_437 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_139 ( struct V_2 * V_2 ,
struct V_1 * V_438 ,
struct V_439 * V_440 ,
enum V_441 V_442 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
struct V_439 * V_443 ;
enum V_441 V_444 ;
enum V_441 V_445 = V_446 ;
if ( V_438 )
V_12 = F_5 ( V_438 ) ;
switch ( F_140 ( V_9 , NULL ) ) {
case V_447 :
return - V_26 ;
case V_448 :
if ( V_9 -> V_198 != V_440 )
return - V_26 ;
if ( ! V_12 && V_9 -> V_449 == V_442 )
return 0 ;
break;
case V_450 :
break;
}
if ( V_12 )
V_445 = V_12 -> V_24 . V_157 . V_442 ;
V_444 = V_9 -> V_449 ;
if ( ! F_141 ( V_9 , V_12 , V_442 ) )
return - V_26 ;
V_443 = V_9 -> V_198 ;
V_9 -> V_198 = V_440 ;
if ( ( V_443 != V_9 -> V_198 ) ||
( V_444 != V_9 -> V_449 ) )
F_142 ( V_9 , V_451 ) ;
if ( V_12 && V_12 -> V_24 . type != V_14 &&
V_445 != V_12 -> V_24 . V_157 . V_442 )
F_79 ( V_12 , V_410 ) ;
return 0 ;
}
static int F_143 ( struct V_2 * V_2 ,
struct V_452 * V_453 )
{
return F_144 ( F_2 ( V_2 ) , V_453 ) ;
}
static int F_145 ( struct V_2 * V_2 )
{
return F_146 ( F_2 ( V_2 ) ) ;
}
static int F_147 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_454 * V_455 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_148 ( & V_12 -> V_24 ) ) {
case V_22 :
case V_456 :
case V_457 :
case V_458 :
break;
case V_459 :
if ( V_12 -> V_9 -> V_425 -> V_460 )
break;
case V_299 :
if ( V_12 -> V_15 . V_223 . V_233 )
return - V_187 ;
break;
default:
return - V_187 ;
}
return F_149 ( V_12 , V_455 ) ;
}
static int
F_150 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_461 * V_455 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_425 -> V_462 )
return - V_187 ;
return F_151 ( V_12 , V_455 ) ;
}
static int
F_152 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_425 -> V_463 )
return - V_187 ;
return F_153 ( V_12 ) ;
}
static int F_154 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_464 * V_455 )
{
return F_155 ( F_5 ( V_10 ) , V_455 ) ;
}
static int F_156 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_465 * V_455 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_140 ( V_9 , V_12 ) ) {
case V_447 :
return - V_26 ;
case V_448 :
if ( V_9 -> V_198 == V_455 -> V_303 -> V_80 )
break;
return - V_26 ;
case V_450 :
break;
}
return F_157 ( F_5 ( V_10 ) , V_455 ) ;
}
static int F_158 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_466 * V_455 )
{
return F_159 ( F_5 ( V_10 ) , V_455 ) ;
}
static int F_160 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_467 * V_455 )
{
return F_161 ( F_5 ( V_10 ) , V_455 ) ;
}
static int F_162 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_468 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_140 ( V_9 , V_12 ) ) {
case V_447 :
return - V_26 ;
case V_448 :
if ( ! V_7 -> V_469 )
return - V_26 ;
if ( V_9 -> V_198 == V_7 -> V_80 )
break;
return - V_26 ;
case V_450 :
break;
}
return F_163 ( V_12 , V_7 ) ;
}
static int F_164 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return F_165 ( V_12 ) ;
}
static int F_166 ( struct V_2 * V_2 , T_1 V_231 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_231 & V_470 ) {
V_13 = F_167 ( V_9 , V_2 -> V_471 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_231 & V_472 ) {
V_13 = F_168 ( V_9 , V_2 -> V_473 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_231 & V_474 ) {
V_13 = F_169 ( V_9 , V_2 -> V_475 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_231 & V_476 )
V_9 -> V_78 . V_45 . V_477 = V_2 -> V_478 ;
if ( V_231 & V_479 )
V_9 -> V_78 . V_45 . V_480 = V_2 -> V_481 ;
if ( V_231 &
( V_476 | V_479 ) )
F_142 ( V_9 , V_482 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 ,
enum V_483 type , int V_484 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_439 * V_440 = V_9 -> V_78 . V_45 . V_80 ;
T_1 V_485 = 0 ;
switch ( type ) {
case V_486 :
V_9 -> V_487 = - 1 ;
break;
case V_488 :
if ( V_484 < 0 || ( V_484 % 100 ) )
return - V_187 ;
V_9 -> V_487 = F_171 ( V_484 ) ;
break;
case V_489 :
if ( V_484 < 0 || ( V_484 % 100 ) )
return - V_187 ;
if ( F_171 ( V_484 ) > V_440 -> V_490 )
return - V_41 ;
V_9 -> V_487 = F_171 ( V_484 ) ;
break;
}
F_142 ( V_9 , V_485 ) ;
return 0 ;
}
static int F_172 ( struct V_2 * V_2 , int * V_491 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_491 = V_9 -> V_78 . V_45 . V_492 ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_3 * V_215 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
memcpy ( & V_12 -> V_15 . V_493 . V_494 , V_215 , V_216 ) ;
return 0 ;
}
static void F_174 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_175 ( V_9 ) ;
}
static int F_176 ( struct V_2 * V_2 , void * V_190 , int V_260 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_425 -> V_495 )
return - V_187 ;
return V_9 -> V_425 -> V_495 ( & V_9 -> V_78 , V_190 , V_260 ) ;
}
static int F_177 ( struct V_2 * V_2 ,
struct V_220 * V_257 ,
struct V_496 * V_266 ,
void * V_190 , int V_260 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_425 -> V_497 )
return - V_187 ;
return V_9 -> V_425 -> V_497 ( & V_9 -> V_78 , V_257 , V_266 , V_190 , V_260 ) ;
}
int F_178 ( struct V_11 * V_12 ,
enum V_498 V_499 )
{
const T_3 * V_223 ;
enum V_498 V_500 ;
int V_13 ;
F_179 ( & V_12 -> V_15 . V_23 . V_501 ) ;
V_500 = V_12 -> V_15 . V_23 . V_502 ;
V_12 -> V_15 . V_23 . V_502 = V_499 ;
if ( V_500 == V_499 &&
V_499 != V_503 )
return 0 ;
if ( ! V_12 -> V_15 . V_23 . V_504 ||
V_12 -> V_24 . V_157 . V_442 == V_446 ) {
F_19 ( & V_12 -> V_9 -> V_505 ) ;
F_180 ( V_12 -> V_9 ) ;
F_25 ( & V_12 -> V_9 -> V_505 ) ;
return 0 ;
}
V_223 = V_12 -> V_15 . V_23 . V_504 -> V_195 ;
if ( V_499 == V_503 ) {
if ( V_12 -> V_15 . V_23 . V_506 )
V_499 = V_507 ;
else
V_499 = V_508 ;
}
V_13 = F_181 ( V_12 , V_499 ,
V_223 , V_223 ) ;
if ( V_13 )
V_12 -> V_15 . V_23 . V_502 = V_500 ;
return V_13 ;
}
static int F_182 ( struct V_2 * V_2 , struct V_1 * V_10 ,
bool V_509 , int V_510 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_65 ( V_10 -> V_217 ) ;
if ( V_12 -> V_24 . type != V_22 )
return - V_187 ;
if ( ! ( V_9 -> V_78 . V_5 & V_511 ) )
return - V_187 ;
if ( V_509 == V_12 -> V_15 . V_23 . V_506 &&
V_510 == V_9 -> V_512 )
return 0 ;
V_12 -> V_15 . V_23 . V_506 = V_509 ;
V_9 -> V_512 = V_510 ;
F_19 ( & V_12 -> V_15 . V_23 . V_501 ) ;
F_178 ( V_12 , V_12 -> V_15 . V_23 . V_502 ) ;
F_25 ( & V_12 -> V_15 . V_23 . V_501 ) ;
if ( V_9 -> V_78 . V_5 & V_513 )
F_142 ( V_9 , V_514 ) ;
F_109 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_6 V_515 , T_1 V_516 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_517 * V_24 = & V_12 -> V_24 ;
struct V_518 * V_157 = & V_24 -> V_157 ;
if ( V_515 == V_157 -> V_519 &&
V_516 == V_157 -> V_520 )
return 0 ;
V_157 -> V_519 = V_515 ;
V_157 -> V_520 = V_516 ;
if ( V_12 -> V_15 . V_23 . V_504 &&
V_12 -> V_24 . V_521 & V_522 )
F_79 ( V_12 , V_523 ) ;
return 0 ;
}
static int F_184 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
const T_3 * V_215 ,
const struct V_524 * V_170 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_65 ( V_10 -> V_217 ) ;
int V_193 , V_17 ;
if ( ! F_11 ( V_12 ) )
return - V_35 ;
if ( V_9 -> V_78 . V_5 & V_525 ) {
V_17 = F_185 ( V_9 , V_12 , V_170 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_193 = 0 ; V_193 < V_526 ; V_193 ++ ) {
V_12 -> V_527 [ V_193 ] = V_170 -> V_263 [ V_193 ] . V_82 ;
memcpy ( V_12 -> V_528 [ V_193 ] , V_170 -> V_263 [ V_193 ] . V_85 ,
sizeof( V_170 -> V_263 [ V_193 ] . V_85 ) ) ;
}
return 0 ;
}
static int F_186 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
struct V_439 * V_440 ,
enum V_441 V_529 ,
unsigned int V_530 , T_4 * V_54 )
{
int V_17 ;
T_1 V_531 ;
F_179 ( & V_9 -> V_501 ) ;
if ( V_9 -> V_532 )
return - V_26 ;
V_531 = F_187 () | 1 ;
* V_54 = V_531 ;
V_9 -> V_533 = V_10 ;
V_9 -> V_532 = V_531 ;
V_9 -> V_534 = V_440 ;
V_9 -> V_535 = V_529 ;
V_9 -> V_536 = V_530 ;
V_17 = F_188 ( V_9 , V_440 , V_529 , V_530 ) ;
if ( V_17 ) {
V_9 -> V_534 = NULL ;
V_9 -> V_532 = 0 ;
}
return V_17 ;
}
static int F_189 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_439 * V_440 ,
enum V_441 V_442 ,
unsigned int V_530 ,
T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_425 -> V_537 ) {
int V_17 ;
F_19 ( & V_9 -> V_501 ) ;
V_17 = F_186 ( V_9 , V_10 ,
V_440 , V_442 ,
V_530 , V_54 ) ;
V_9 -> V_538 = false ;
F_25 ( & V_9 -> V_501 ) ;
return V_17 ;
}
return F_190 ( V_12 , V_440 , V_442 ,
V_530 , V_54 ) ;
}
static int F_191 ( struct V_8 * V_9 ,
T_4 V_54 )
{
int V_17 ;
F_179 ( & V_9 -> V_501 ) ;
if ( V_9 -> V_532 != V_54 )
return - V_48 ;
V_17 = F_192 ( V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 -> V_532 = 0 ;
V_9 -> V_534 = NULL ;
F_193 ( V_9 ) ;
return 0 ;
}
static int F_194 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_425 -> V_539 ) {
int V_17 ;
F_19 ( & V_9 -> V_501 ) ;
V_17 = F_191 ( V_9 , V_54 ) ;
F_25 ( & V_9 -> V_501 ) ;
return V_17 ;
}
return F_195 ( V_12 , V_54 ) ;
}
static enum V_540
F_196 ( struct V_541 * V_542 , struct V_220 * V_257 )
{
if ( V_542 -> V_543 . V_544 && ! V_542 -> V_543 . V_545 )
F_197 ( V_542 -> V_12 -> V_10 ,
( unsigned long ) V_542 -> V_543 . V_546 ,
V_542 -> V_190 , V_542 -> V_547 , false , V_238 ) ;
return V_548 ;
}
static int F_198 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_439 * V_440 , bool V_549 ,
enum V_441 V_442 ,
bool V_550 , unsigned int V_544 ,
const T_3 * V_551 , T_5 V_260 , bool V_552 ,
bool V_553 , T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_220 * V_257 ;
struct V_32 * V_21 ;
struct V_541 * V_542 ;
const struct V_554 * V_555 = ( void * ) V_551 ;
T_1 V_5 ;
bool V_556 = false ;
if ( V_553 )
V_5 = V_557 ;
else
V_5 = V_558 |
V_559 ;
if ( V_440 != V_9 -> V_560 &&
V_440 != V_9 -> V_198 )
V_556 = true ;
if ( V_550 &&
( V_442 != V_9 -> V_561 &&
V_442 != V_9 -> V_449 ) )
V_556 = true ;
if ( V_440 == V_9 -> V_534 ) {
V_556 = false ;
V_5 |= V_562 ;
}
if ( V_552 )
V_5 |= V_563 ;
if ( V_556 && ! V_549 )
return - V_26 ;
switch ( V_12 -> V_24 . type ) {
case V_456 :
case V_299 :
case V_18 :
case V_459 :
case V_457 :
if ( ! F_199 ( V_555 -> V_564 ) ||
V_555 -> V_15 . V_565 . V_566 == V_567 )
break;
F_31 () ;
V_21 = F_21 ( V_12 , V_555 -> V_258 ) ;
F_35 () ;
if ( ! V_21 )
return - V_568 ;
break;
case V_22 :
case V_458 :
break;
default:
return - V_187 ;
}
V_257 = F_69 ( V_9 -> V_78 . V_569 + V_260 ) ;
if ( ! V_257 )
return - V_225 ;
F_200 ( V_257 , V_9 -> V_78 . V_569 ) ;
memcpy ( F_70 ( V_257 , V_260 ) , V_551 , V_260 ) ;
F_201 ( V_257 ) -> V_5 = V_5 ;
if ( V_5 & V_562 )
F_201 ( V_257 ) -> V_570 =
V_9 -> V_78 . V_571 ;
V_257 -> V_10 = V_12 -> V_10 ;
* V_54 = ( unsigned long ) V_257 ;
if ( V_556 && V_9 -> V_425 -> V_537 ) {
unsigned int V_530 ;
int V_17 ;
F_19 ( & V_9 -> V_501 ) ;
V_530 = 100 ;
if ( V_544 )
V_530 = V_544 ;
V_17 = F_186 ( V_9 , V_10 , V_440 ,
V_442 ,
V_530 , V_54 ) ;
if ( V_17 ) {
F_202 ( V_257 ) ;
F_25 ( & V_9 -> V_501 ) ;
return V_17 ;
}
V_9 -> V_538 = true ;
V_9 -> V_536 = V_544 ;
* V_54 ^= 2 ;
F_201 ( V_257 ) -> V_5 |= V_562 ;
F_201 ( V_257 ) -> V_570 =
V_9 -> V_78 . V_571 ;
V_9 -> V_572 = V_257 ;
V_9 -> V_573 = V_257 ;
F_25 ( & V_9 -> V_501 ) ;
return 0 ;
}
if ( ! V_556 && ! V_544 && ! V_12 -> V_24 . V_157 . V_574 ) {
F_203 ( V_12 , V_257 ) ;
return 0 ;
}
V_542 = F_75 ( sizeof( * V_542 ) + V_260 , V_238 ) ;
if ( ! V_542 ) {
F_202 ( V_257 ) ;
return - V_225 ;
}
V_542 -> type = V_575 ;
V_542 -> V_440 = V_440 ;
V_542 -> V_576 = V_442 ;
V_542 -> V_12 = V_12 ;
V_542 -> V_577 = F_196 ;
V_542 -> V_543 . V_546 = V_257 ;
V_542 -> V_543 . V_544 = V_544 ;
V_542 -> V_547 = V_260 ;
memcpy ( V_542 -> V_190 , V_551 , V_260 ) ;
F_204 ( V_542 ) ;
return 0 ;
}
static int F_205 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_541 * V_542 ;
int V_17 = - V_48 ;
F_19 ( & V_9 -> V_501 ) ;
if ( V_9 -> V_425 -> V_539 ) {
V_54 ^= 2 ;
V_17 = F_191 ( V_9 , V_54 ) ;
if ( V_17 == 0 ) {
F_202 ( V_9 -> V_572 ) ;
V_9 -> V_572 = NULL ;
V_9 -> V_573 = NULL ;
}
F_25 ( & V_9 -> V_501 ) ;
return V_17 ;
}
F_78 (wk, &local->work_list, list) {
if ( V_542 -> V_12 != V_12 )
continue;
if ( V_542 -> type != V_575 )
continue;
if ( V_54 != ( unsigned long ) V_542 -> V_543 . V_546 )
continue;
V_542 -> V_510 = V_118 ;
F_206 ( & V_9 -> V_78 , & V_9 -> V_578 ) ;
V_17 = 0 ;
break;
}
F_25 ( & V_9 -> V_501 ) ;
return V_17 ;
}
static void F_207 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_579 , bool V_580 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_579 != ( V_581 | V_582 ) )
return;
if ( V_580 )
V_9 -> V_583 ++ ;
else
V_9 -> V_583 -- ;
F_206 ( & V_9 -> V_78 , & V_9 -> V_584 ) ;
}
static int F_208 ( struct V_2 * V_2 , T_1 V_585 , T_1 V_586 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_587 )
return - V_187 ;
return F_209 ( V_9 , V_585 , V_586 ) ;
}
static int F_210 ( struct V_2 * V_2 , T_1 * V_585 , T_1 * V_586 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_211 ( V_9 , V_585 , V_586 ) ;
}
static int F_212 ( struct V_2 * V_2 , T_1 V_61 , T_1 V_588 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_213 ( V_9 , V_61 , V_588 ) ;
}
static void F_214 ( struct V_2 * V_2 ,
T_1 * V_61 , T_1 * V_589 , T_1 * V_588 , T_1 * V_590 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_215 ( V_9 , V_61 , V_589 , V_588 , V_590 ) ;
}
static int F_216 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_591 * V_190 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_425 -> V_592 )
return - V_187 ;
F_217 ( V_9 , V_12 , V_190 ) ;
return 0 ;
}
static void F_218 ( struct V_220 * V_257 )
{
T_3 * V_593 = ( void * ) F_70 ( V_257 , 7 ) ;
* V_593 ++ = V_594 ;
* V_593 ++ = 5 ;
* V_593 ++ = 0x0 ;
* V_593 ++ = 0x0 ;
* V_593 ++ = 0x0 ;
* V_593 ++ = 0x0 ;
* V_593 ++ = V_595 ;
}
static T_2 F_219 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_596 ;
V_596 = 0 ;
if ( V_9 -> V_198 -> V_81 != V_597 )
return V_596 ;
if ( ! ( V_9 -> V_78 . V_5 & V_598 ) )
V_596 |= V_599 ;
if ( ! ( V_9 -> V_78 . V_5 & V_600 ) )
V_596 |= V_601 ;
return V_596 ;
}
static void F_220 ( struct V_220 * V_257 , T_3 * V_602 ,
T_3 * V_603 , T_3 * V_195 )
{
struct V_604 * V_605 ;
V_605 = ( void * ) F_70 ( V_257 , sizeof( struct V_604 ) ) ;
V_605 -> V_606 = V_607 ;
V_605 -> V_349 = sizeof( struct V_604 ) - 2 ;
memcpy ( V_605 -> V_195 , V_195 , V_216 ) ;
memcpy ( V_605 -> V_608 , V_602 , V_216 ) ;
memcpy ( V_605 -> V_609 , V_603 , V_216 ) ;
}
static int
F_221 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_603 , T_3 V_610 , T_3 V_611 ,
T_2 V_612 , struct V_220 * V_257 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_613 * V_614 ;
V_614 = ( void * ) F_70 ( V_257 , F_222 ( struct V_613 , V_15 ) ) ;
memcpy ( V_614 -> V_258 , V_603 , V_216 ) ;
memcpy ( V_614 -> V_259 , V_12 -> V_24 . V_215 , V_216 ) ;
V_614 -> V_615 = F_223 ( V_616 ) ;
V_614 -> V_617 = V_618 ;
switch ( V_610 ) {
case V_619 :
V_614 -> V_566 = V_620 ;
V_614 -> V_610 = V_619 ;
F_70 ( V_257 , sizeof( V_614 -> V_15 . V_621 ) ) ;
V_614 -> V_15 . V_621 . V_611 = V_611 ;
V_614 -> V_15 . V_621 . V_622 =
F_224 ( F_219 ( V_12 ) ) ;
F_225 ( & V_12 -> V_24 , V_257 , false ) ;
F_226 ( & V_12 -> V_24 , V_257 , false ) ;
F_218 ( V_257 ) ;
break;
case V_623 :
V_614 -> V_566 = V_620 ;
V_614 -> V_610 = V_623 ;
F_70 ( V_257 , sizeof( V_614 -> V_15 . V_624 ) ) ;
V_614 -> V_15 . V_624 . V_612 = F_224 ( V_612 ) ;
V_614 -> V_15 . V_624 . V_611 = V_611 ;
V_614 -> V_15 . V_624 . V_622 =
F_224 ( F_219 ( V_12 ) ) ;
F_225 ( & V_12 -> V_24 , V_257 , false ) ;
F_226 ( & V_12 -> V_24 , V_257 , false ) ;
F_218 ( V_257 ) ;
break;
case V_625 :
V_614 -> V_566 = V_620 ;
V_614 -> V_610 = V_625 ;
F_70 ( V_257 , sizeof( V_614 -> V_15 . V_626 ) ) ;
V_614 -> V_15 . V_626 . V_612 = F_224 ( V_612 ) ;
V_614 -> V_15 . V_626 . V_611 = V_611 ;
break;
case V_627 :
V_614 -> V_566 = V_620 ;
V_614 -> V_610 = V_627 ;
F_70 ( V_257 , sizeof( V_614 -> V_15 . V_628 ) ) ;
V_614 -> V_15 . V_628 . V_629 = F_224 ( V_612 ) ;
break;
case V_630 :
V_614 -> V_566 = V_620 ;
V_614 -> V_610 = V_630 ;
F_70 ( V_257 , sizeof( V_614 -> V_15 . V_631 ) ) ;
V_614 -> V_15 . V_631 . V_611 = V_611 ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int
F_227 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_603 , T_3 V_610 , T_3 V_611 ,
T_2 V_612 , struct V_220 * V_257 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_554 * V_555 ;
V_555 = ( void * ) F_70 ( V_257 , 24 ) ;
memset ( V_555 , 0 , 24 ) ;
memcpy ( V_555 -> V_258 , V_603 , V_216 ) ;
memcpy ( V_555 -> V_259 , V_12 -> V_24 . V_215 , V_216 ) ;
memcpy ( V_555 -> V_195 , V_12 -> V_15 . V_23 . V_195 , V_216 ) ;
V_555 -> V_564 = F_224 ( V_581 |
V_632 ) ;
switch ( V_610 ) {
case V_633 :
F_70 ( V_257 , 1 + sizeof( V_555 -> V_15 . V_565 . V_15 . V_634 ) ) ;
V_555 -> V_15 . V_565 . V_566 = V_567 ;
V_555 -> V_15 . V_565 . V_15 . V_634 . V_610 =
V_633 ;
V_555 -> V_15 . V_565 . V_15 . V_634 . V_611 =
V_611 ;
V_555 -> V_15 . V_565 . V_15 . V_634 . V_622 =
F_224 ( F_219 ( V_12 ) ) ;
F_225 ( & V_12 -> V_24 , V_257 , false ) ;
F_226 ( & V_12 -> V_24 , V_257 , false ) ;
F_218 ( V_257 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_228 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_603 , T_3 V_610 , T_3 V_611 ,
T_2 V_612 , const T_3 * V_635 ,
T_5 V_636 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_637 * V_638 ;
struct V_220 * V_257 = NULL ;
bool V_639 ;
int V_17 ;
if ( ! ( V_2 -> V_5 & V_640 ) )
return - V_405 ;
if ( V_12 -> V_24 . type != V_22 ||
! V_12 -> V_15 . V_23 . V_504 )
return - V_41 ;
#ifdef F_229
F_230 ( V_641 L_2 , V_610 , V_603 ) ;
#endif
V_257 = F_69 ( V_9 -> V_78 . V_569 +
F_231 ( sizeof( struct V_554 ) ,
sizeof( struct V_613 ) ) +
50 +
7 +
V_636 +
sizeof( struct V_604 ) ) ;
if ( ! V_257 )
return - V_225 ;
V_638 = F_201 ( V_257 ) ;
F_200 ( V_257 , V_9 -> V_78 . V_569 ) ;
switch ( V_610 ) {
case V_619 :
case V_623 :
case V_625 :
case V_627 :
case V_630 :
V_17 = F_221 ( V_2 , V_10 , V_603 ,
V_610 , V_611 ,
V_612 , V_257 ) ;
V_639 = false ;
break;
case V_633 :
V_17 = F_227 ( V_2 , V_10 , V_603 , V_610 ,
V_611 , V_612 ,
V_257 ) ;
V_639 = true ;
break;
default:
V_17 = - V_405 ;
break;
}
if ( V_17 < 0 )
goto V_642;
if ( V_636 )
memcpy ( F_70 ( V_257 , V_636 ) , V_635 , V_636 ) ;
switch ( V_610 ) {
case V_619 :
case V_625 :
case V_627 :
case V_630 :
F_220 ( V_257 , V_12 -> V_24 . V_215 , V_603 ,
V_12 -> V_15 . V_23 . V_195 ) ;
break;
case V_623 :
case V_633 :
F_220 ( V_257 , V_603 , V_12 -> V_24 . V_215 ,
V_12 -> V_15 . V_23 . V_195 ) ;
break;
default:
V_17 = - V_405 ;
goto V_642;
}
if ( V_639 ) {
F_203 ( V_12 , V_257 ) ;
return 0 ;
}
switch ( V_610 ) {
case V_619 :
case V_623 :
F_232 ( V_257 , V_643 ) ;
V_257 -> V_644 = 2 ;
break;
default:
F_232 ( V_257 , V_645 ) ;
V_257 -> V_644 = 5 ;
break;
}
F_233 () ;
V_17 = F_234 ( V_257 , V_10 ) ;
F_235 () ;
return V_17 ;
V_642:
F_73 ( V_257 ) ;
return V_17 ;
}
static int F_236 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_603 , enum V_646 V_647 )
{
struct V_32 * V_21 ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! ( V_2 -> V_5 & V_640 ) )
return - V_405 ;
if ( V_12 -> V_24 . type != V_22 )
return - V_41 ;
#ifdef F_229
F_230 ( V_641 L_3 , V_647 , V_603 ) ;
#endif
switch ( V_647 ) {
case V_648 :
F_31 () ;
V_21 = F_21 ( V_12 , V_603 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_568 ;
}
F_90 ( V_21 , V_649 ) ;
F_35 () ;
break;
case V_650 :
return F_237 ( V_12 , V_603 ) ;
case V_651 :
case V_652 :
case V_653 :
return - V_405 ;
default:
return - V_405 ;
}
return 0 ;
}
static int F_238 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_3 * V_603 , T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_654 * V_655 ;
struct V_220 * V_257 ;
int V_230 = sizeof( * V_655 ) ;
T_7 V_656 ;
bool V_657 ;
struct V_637 * V_638 ;
struct V_32 * V_21 ;
F_31 () ;
V_21 = F_21 ( V_12 , V_603 ) ;
if ( V_21 ) {
V_657 = F_48 ( V_21 , V_179 ) ;
F_35 () ;
} else {
F_35 () ;
return - V_568 ;
}
if ( V_657 ) {
V_656 = F_224 ( V_658 |
V_659 |
V_660 ) ;
} else {
V_230 -= 2 ;
V_656 = F_224 ( V_658 |
V_661 |
V_660 ) ;
}
V_257 = F_69 ( V_9 -> V_78 . V_569 + V_230 ) ;
if ( ! V_257 )
return - V_225 ;
V_257 -> V_10 = V_10 ;
F_200 ( V_257 , V_9 -> V_78 . V_569 ) ;
V_655 = ( void * ) F_70 ( V_257 , V_230 ) ;
V_655 -> V_564 = V_656 ;
V_655 -> V_662 = 0 ;
memcpy ( V_655 -> V_663 , V_21 -> V_21 . V_215 , V_216 ) ;
memcpy ( V_655 -> V_664 , V_12 -> V_24 . V_215 , V_216 ) ;
memcpy ( V_655 -> V_665 , V_12 -> V_24 . V_215 , V_216 ) ;
V_655 -> V_666 = 0 ;
V_638 = F_201 ( V_257 ) ;
V_638 -> V_5 |= V_559 |
V_558 ;
F_232 ( V_257 , V_667 ) ;
V_257 -> V_644 = 7 ;
if ( V_657 )
V_655 -> V_668 = F_224 ( 7 ) ;
F_233 () ;
F_239 ( V_12 , V_257 ) ;
F_235 () ;
* V_54 = ( unsigned long ) V_257 ;
return 0 ;
}
static struct V_439 *
F_240 ( struct V_2 * V_2 ,
enum V_441 * type )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* type = V_9 -> V_449 ;
return V_9 -> V_198 ;
}
static void F_241 ( struct V_2 * V_2 , bool V_509 )
{
F_242 ( F_2 ( V_2 ) , V_509 ) ;
}
