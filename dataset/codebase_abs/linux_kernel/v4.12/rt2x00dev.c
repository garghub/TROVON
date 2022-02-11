T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 )
return 0 ;
return V_4 -> V_6 [ 5 ] & ( V_2 -> V_7 -> V_8 - 1 ) ;
}
int F_2 ( struct V_1 * V_2 )
{
int V_9 ;
if ( F_3 ( V_10 , & V_2 -> V_11 ) )
return 0 ;
F_4 ( V_2 ) ;
V_9 =
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_14 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_15 ) ;
F_5 ( V_2 , true ) ;
F_6 ( V_2 , true ) ;
F_7 ( V_10 , & V_2 -> V_11 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_10 , & V_2 -> V_11 ) )
return;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 , true ) ;
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_16 ) ;
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_17 ) ;
F_6 ( V_2 , false ) ;
F_5 ( V_2 , false ) ;
}
static void F_17 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_18 ;
struct V_20 * V_21 = F_18 ( V_4 ) ;
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
if ( F_12 ( V_22 , & V_21 -> V_23 ) ) {
F_19 ( & V_21 -> V_24 ) ;
F_20 ( V_2 , V_4 ) ;
F_21 ( & V_21 -> V_24 ) ;
}
}
static void F_22 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_23 ( V_26 , struct V_1 , V_27 ) ;
F_24 ( V_2 -> V_28 ,
V_29 ,
F_17 ,
V_2 ) ;
}
static void F_25 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_23 ( V_26 , struct V_1 , V_30 . V_26 ) ;
if ( ! F_3 ( V_31 , & V_2 -> V_11 ) )
return;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_32 ) )
F_26 ( V_2 , L_1 ) ;
F_27 ( V_33 , & V_2 -> V_11 ) ;
}
static void F_28 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_34 V_35 = {} ;
struct V_1 * V_2 = V_18 ;
struct V_36 * V_37 ;
if ( V_4 -> type != V_38 )
return;
V_37 = F_29 ( V_2 -> V_28 , V_4 ) ;
while ( V_37 ) {
F_30 ( V_2 -> V_28 , & V_35 , V_37 ) ;
V_37 = F_29 ( V_2 -> V_28 , V_4 ) ;
}
}
static void F_31 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_18 ;
if ( V_4 -> type != V_38 &&
V_4 -> type != V_39 &&
V_4 -> type != V_40 &&
V_4 -> type != V_41 )
return;
F_32 ( F_33 ( V_2 ) ) ;
F_20 ( V_2 , V_4 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_35 (
V_2 -> V_28 , V_29 ,
F_28 , V_2 ) ;
if ( F_36 ( V_2 ) )
return;
F_35 (
V_2 -> V_28 , V_29 ,
F_31 , V_2 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_35 (
V_2 -> V_28 , V_29 ,
F_31 , V_2 ) ;
}
void F_38 ( struct V_42 * V_43 )
{
F_7 ( V_44 , & V_43 -> V_11 ) ;
F_39 ( V_43 , V_45 ) ;
}
void F_40 ( struct V_42 * V_43 )
{
F_7 ( V_46 , & V_43 -> V_11 ) ;
F_27 ( V_44 , & V_43 -> V_11 ) ;
F_39 ( V_43 , V_47 ) ;
}
static inline int F_41 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_49 * V_50 = ( void * ) V_43 -> V_37 -> V_18 ;
struct V_51 * V_52 ;
int V_53 ;
if ( F_42 ( ! F_43 ( V_50 -> V_54 ) ) )
return 0 ;
V_53 = 0 ;
F_44 () ;
F_45 (bar_entry, &rt2x00dev->bar_list, list) {
if ( V_52 -> V_43 != V_43 )
continue;
F_46 ( & V_2 -> V_55 ) ;
V_53 = V_52 -> V_56 ;
F_47 ( & V_52 -> V_57 ) ;
F_48 ( & V_2 -> V_55 ) ;
F_49 ( V_52 , V_58 ) ;
break;
}
F_50 () ;
return V_53 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_63 * V_64 ,
bool V_65 )
{
T_2 V_66 , V_67 , V_68 ;
int V_69 ;
V_66 = V_62 -> V_70 ;
V_67 = V_62 -> V_71 ;
V_68 = F_3 ( V_72 , & V_64 -> V_11 ) ?
( V_64 -> V_73 + 1 ) : 1 ;
memset ( & V_60 -> V_9 , 0 , sizeof( V_60 -> V_9 ) ) ;
V_60 -> V_9 . V_74 = 0 ;
for ( V_69 = 0 ; V_69 < V_68 && V_69 < V_75 ; V_69 ++ ) {
V_60 -> V_9 . V_76 [ V_69 ] . V_77 = V_66 - V_69 ;
V_60 -> V_9 . V_76 [ V_69 ] . V_11 = V_67 ;
if ( V_66 - V_69 == 0 ) {
V_60 -> V_9 . V_76 [ V_69 ] . V_78 = V_68 - V_69 ;
V_69 ++ ;
break;
}
V_60 -> V_9 . V_76 [ V_69 ] . V_78 = 1 ;
}
if ( V_69 < ( V_75 - 1 ) )
V_60 -> V_9 . V_76 [ V_69 ] . V_77 = - 1 ;
if ( F_3 ( V_79 , & V_64 -> V_11 ) )
V_60 -> V_11 |= V_80 ;
if ( ! ( V_60 -> V_11 & V_80 ) ) {
if ( V_65 )
V_60 -> V_11 |= V_81 ;
else
V_2 -> V_82 . V_83 ++ ;
}
if ( F_3 ( V_84 , & V_64 -> V_11 ) ||
V_60 -> V_11 & V_85 ) {
V_60 -> V_11 |= V_86 |
V_85 ;
V_60 -> V_9 . V_87 = 1 ;
V_60 -> V_9 . V_88 = V_65 ? 1 : 0 ;
if ( ! V_65 )
V_60 -> V_11 |= V_89 ;
}
if ( V_67 & V_90 ) {
if ( V_65 )
V_2 -> V_82 . V_91 ++ ;
else
V_2 -> V_82 . V_92 ++ ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
V_43 -> V_37 = NULL ;
V_43 -> V_11 = 0 ;
V_2 -> V_7 -> V_12 -> V_93 ( V_43 ) ;
F_39 ( V_43 , V_94 ) ;
F_46 ( & V_43 -> V_48 -> V_95 ) ;
if ( ! F_53 ( V_43 -> V_48 ) )
F_54 ( V_43 -> V_48 ) ;
F_48 ( & V_43 -> V_48 -> V_95 ) ;
}
void F_55 ( struct V_42 * V_43 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_61 * V_62 = F_56 ( V_43 -> V_37 ) ;
struct V_59 V_96 = {} ;
bool V_65 ;
F_57 ( V_43 ) ;
V_62 -> V_11 &= ~ V_97 ;
F_58 ( V_2 , V_98 , V_43 ) ;
V_65 =
F_41 ( V_43 ) ||
F_3 ( V_99 , & V_64 -> V_11 ) ;
if ( ! F_3 ( V_100 , & V_64 -> V_11 ) ) {
V_2 -> V_101 . V_102 . V_103 += V_65 ;
V_2 -> V_101 . V_102 . V_104 += ! V_65 ;
F_51 ( V_2 , & V_96 , V_62 , V_64 ,
V_65 ) ;
F_59 ( V_2 -> V_28 , V_62 -> V_105 , & V_96 ) ;
}
F_60 ( V_43 -> V_37 ) ;
F_52 ( V_2 , V_43 ) ;
}
void F_61 ( struct V_42 * V_43 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_59 * V_60 = F_62 ( V_43 -> V_37 ) ;
struct V_61 * V_62 = F_56 ( V_43 -> V_37 ) ;
T_2 V_106 = V_62 -> V_11 ;
unsigned int V_107 ;
bool V_65 ;
F_57 ( V_43 ) ;
F_63 ( V_43 -> V_37 , V_2 -> V_108 ) ;
V_62 -> V_11 &= ~ V_97 ;
V_107 = F_64 ( V_43 -> V_37 ) ;
if ( F_65 ( V_2 , V_109 ) )
F_66 ( V_43 -> V_37 , V_107 ) ;
if ( F_67 ( V_2 ) )
F_68 ( V_43 -> V_37 , V_107 ) ;
F_58 ( V_2 , V_98 , V_43 ) ;
V_65 =
F_41 ( V_43 ) ||
F_3 ( V_99 , & V_64 -> V_11 ) ||
F_3 ( V_100 , & V_64 -> V_11 ) ;
V_2 -> V_101 . V_102 . V_103 += V_65 ;
V_2 -> V_101 . V_102 . V_104 += ! V_65 ;
F_51 ( V_2 , V_60 , V_62 , V_64 , V_65 ) ;
if ( ! ( V_106 & V_110 ) ) {
if ( F_65 ( V_2 , V_111 ) )
F_69 ( V_2 -> V_28 , V_43 -> V_37 ) ;
else
F_70 ( V_2 -> V_28 , V_43 -> V_37 ) ;
} else {
F_60 ( V_43 -> V_37 ) ;
}
F_52 ( V_2 , V_43 ) ;
}
void F_71 ( struct V_42 * V_43 , T_1 V_9 )
{
struct V_63 V_64 ;
V_64 . V_11 = 0 ;
F_72 ( V_9 , & V_64 . V_11 ) ;
V_64 . V_73 = 0 ;
F_61 ( V_43 , & V_64 ) ;
}
static T_2 * F_73 ( T_2 * V_18 , unsigned int V_112 , T_2 V_113 )
{
struct V_114 * V_115 = ( void * ) V_18 ;
T_2 * V_116 , * V_117 ;
V_116 = ( T_2 * ) V_115 -> V_118 . V_119 . V_120 ;
V_117 = V_18 + V_112 ;
while ( V_116 < V_117 ) {
if ( V_116 + 2 + V_116 [ 1 ] > V_117 )
return NULL ;
if ( V_116 [ 0 ] == V_113 )
return V_116 ;
V_116 += 2 + V_116 [ 1 ] ;
}
return NULL ;
}
static void F_74 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_23 ( V_26 , struct V_1 , V_121 ) ;
if ( ! F_3 ( V_31 , & V_2 -> V_11 ) )
return;
if ( ! F_3 ( V_33 , & V_2 -> V_11 ) )
F_75 ( V_2 , & V_2 -> V_28 -> V_122 ,
V_123 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_124 * V_125 )
{
struct V_51 * V_43 ;
struct V_49 * V_126 = ( void * ) V_37 -> V_18 ;
if ( F_42 ( ! F_77 ( V_126 -> V_54 ) ) )
return;
if ( V_125 -> V_127 < sizeof( * V_126 ) + V_128 )
return;
F_44 () ;
F_45 (entry, &rt2x00dev->bar_list, list) {
if ( V_126 -> V_129 != V_43 -> V_129 )
continue;
#define F_78 ( T_3 , T_4 ) ( \
((a) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK)) == \
((b) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK))) \
if (!TID_CHECK(ba->control, entry->control))
continue;
#undef F_78
if ( ! F_79 ( V_126 -> V_130 , V_43 -> V_131 ) )
continue;
if ( ! F_79 ( V_126 -> V_131 , V_43 -> V_130 ) )
continue;
F_46 ( & V_2 -> V_55 ) ;
V_43 -> V_56 = 1 ;
F_48 ( & V_2 -> V_55 ) ;
break;
}
F_50 () ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_124 * V_125 )
{
struct V_132 * V_133 = ( void * ) V_37 -> V_18 ;
struct V_134 * V_135 ;
T_2 * V_136 ;
T_2 V_137 ;
bool V_138 ;
if ( F_42 ( ! F_81 ( V_133 -> V_54 ) ||
! ( V_2 -> V_28 -> V_122 . V_11 & V_139 ) ) )
return;
if ( V_37 -> V_112 <= 40 + V_128 )
return;
if ( ! ( V_125 -> V_140 & V_141 ) ||
! V_2 -> V_142 )
return;
V_2 -> V_143 = V_144 ;
V_136 = F_73 ( V_37 -> V_18 , V_37 -> V_112 - V_128 , V_145 ) ;
if ( ! V_136 )
return;
if ( V_136 [ 1 ] < sizeof( * V_135 ) )
return;
V_137 = V_136 [ 1 ] ;
V_135 = (struct V_134 * ) & V_136 [ 2 ] ;
V_138 = F_82 ( V_135 , V_137 , V_2 -> V_142 ) ;
V_138 |= ( V_135 -> V_146 & 0x01 ) ;
if ( ! V_138 && ! F_3 ( V_33 , & V_2 -> V_11 ) )
F_83 ( V_2 -> V_147 , & V_2 -> V_121 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_148 * V_149 ;
const struct V_150 * V_151 ;
unsigned int V_69 ;
int signal = V_125 -> signal ;
int type = ( V_125 -> V_140 & V_152 ) ;
switch ( V_125 -> V_153 ) {
case V_154 :
case V_155 :
if ( V_125 -> V_140 & V_156 )
signal = F_85 ( V_125 -> V_153 , signal ) ;
V_149 = & V_2 -> V_157 [ V_2 -> V_158 ] ;
for ( V_69 = 0 ; V_69 < V_149 -> V_159 ; V_69 ++ ) {
V_151 = F_86 ( V_149 -> V_160 [ V_69 ] . V_161 ) ;
if ( ( ( type == V_162 ) &&
( V_151 -> V_163 == signal ) ) ||
( ( type == V_164 ) &&
( V_151 -> V_165 == signal ) ) ||
( ( type == V_156 ) &&
( V_151 -> V_166 == signal ) ) ) {
return V_69 ;
}
}
break;
case V_167 :
case V_168 :
if ( signal >= 0 && signal <= 76 )
return signal ;
break;
default:
break;
}
F_87 ( V_2 , L_2 ,
V_125 -> V_153 , signal , type ) ;
return 0 ;
}
void F_88 ( struct V_42 * V_43 , T_5 V_169 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_124 V_125 ;
struct V_36 * V_37 ;
struct V_170 * V_171 ;
unsigned int V_107 ;
int V_66 ;
if ( ! F_3 ( V_31 , & V_2 -> V_11 ) ||
! F_3 ( V_10 , & V_2 -> V_11 ) )
goto V_172;
if ( F_3 ( V_173 , & V_43 -> V_11 ) )
goto V_172;
V_37 = F_89 ( V_43 , V_169 ) ;
if ( ! V_37 )
goto V_172;
F_57 ( V_43 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_2 -> V_7 -> V_12 -> V_174 ( V_43 , & V_125 ) ;
if ( F_90 ( V_125 . V_127 == 0 ||
V_125 . V_127 > V_43 -> V_48 -> V_175 ) ) {
F_26 ( V_2 , L_3 ,
V_125 . V_127 , V_43 -> V_48 -> V_175 ) ;
F_91 ( V_43 -> V_37 ) ;
goto V_176;
}
V_107 = F_64 ( V_43 -> V_37 ) ;
if ( ( V_125 . V_140 & V_177 ) &&
( V_125 . V_11 & V_178 ) )
F_92 ( V_43 -> V_37 , V_107 ,
& V_125 ) ;
else if ( V_107 &&
( V_125 . V_127 > V_107 ) &&
( V_125 . V_140 & V_179 ) )
F_66 ( V_43 -> V_37 , V_107 ) ;
F_93 ( V_43 -> V_37 , V_125 . V_127 ) ;
V_66 = F_84 ( V_2 , & V_125 ) ;
if ( V_125 . V_153 == V_167 ||
V_125 . V_153 == V_168 )
V_125 . V_180 = V_181 ;
F_80 ( V_2 , V_43 -> V_37 , & V_125 ) ;
F_76 ( V_2 , V_43 -> V_37 , & V_125 ) ;
F_94 ( V_2 , V_43 -> V_37 , & V_125 ) ;
F_95 ( V_2 , & V_125 ) ;
F_58 ( V_2 , V_182 , V_43 ) ;
V_171 = F_96 ( V_43 -> V_37 ) ;
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
V_171 -> V_183 = V_125 . V_184 ;
V_171 -> V_185 = V_2 -> V_158 ;
V_171 -> V_186 = V_2 -> V_187 ;
V_171 -> V_66 = V_66 ;
V_171 -> signal = V_125 . V_188 ;
V_171 -> V_189 = V_125 . V_11 ;
V_171 -> V_190 = V_125 . V_190 ;
V_171 -> V_180 = V_125 . V_180 ;
V_171 -> V_191 = V_125 . V_191 ;
V_171 -> V_192 = V_2 -> V_101 . V_193 . V_194 . V_195 ;
F_97 ( V_2 -> V_28 , V_43 -> V_37 ) ;
V_176:
V_43 -> V_37 = V_37 ;
V_172:
V_43 -> V_11 = 0 ;
F_39 ( V_43 , V_94 ) ;
if ( F_3 ( V_31 , & V_2 -> V_11 ) &&
F_3 ( V_10 , & V_2 -> V_11 ) )
V_2 -> V_7 -> V_12 -> V_93 ( V_43 ) ;
}
static void F_98 ( struct V_196 * V_43 ,
const int V_197 , const int V_198 ,
const int V_199 )
{
V_43 -> V_185 = V_197 <= 14 ? V_200 : V_201 ;
V_43 -> V_202 = F_99 ( V_197 ,
V_43 -> V_185 ) ;
V_43 -> V_161 = V_199 ;
V_43 -> V_203 = V_198 ;
V_43 -> V_204 = 0xff ;
}
static void F_100 ( struct V_205 * V_43 ,
const T_6 V_206 , const struct V_150 * V_151 )
{
V_43 -> V_11 = 0 ;
V_43 -> V_165 = V_151 -> V_165 ;
V_43 -> V_161 = V_206 ;
V_43 -> V_207 = V_206 ;
if ( V_151 -> V_11 & V_208 )
V_43 -> V_11 |= V_209 ;
}
void F_101 ( struct V_1 * V_2 , T_2 * V_210 )
{
const char * V_211 ;
V_211 = F_102 ( V_2 -> V_212 -> V_213 ) ;
if ( V_211 )
F_103 ( V_210 , V_211 ) ;
if ( ! F_104 ( V_210 ) ) {
F_105 ( V_210 ) ;
F_106 ( V_2 , L_4 , V_210 ) ;
}
}
static int F_107 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
struct V_216 * V_28 = V_2 -> V_28 ;
struct V_196 * V_217 ;
struct V_205 * V_76 ;
unsigned int V_218 ;
unsigned int V_69 ;
V_218 = 0 ;
if ( V_215 -> V_219 & V_220 )
V_218 += 4 ;
if ( V_215 -> V_219 & V_221 )
V_218 += 8 ;
V_217 = F_108 ( V_215 -> V_222 , sizeof( * V_217 ) , V_223 ) ;
if ( ! V_217 )
return - V_224 ;
V_76 = F_108 ( V_218 , sizeof( * V_76 ) , V_223 ) ;
if ( ! V_76 )
goto V_225;
for ( V_69 = 0 ; V_69 < V_218 ; V_69 ++ )
F_100 ( & V_76 [ V_69 ] , V_69 , F_86 ( V_69 ) ) ;
for ( V_69 = 0 ; V_69 < V_215 -> V_222 ; V_69 ++ ) {
F_98 ( & V_217 [ V_69 ] ,
V_215 -> V_217 [ V_69 ] . V_197 ,
V_215 -> V_226 [ V_69 ] . V_203 , V_69 ) ;
}
if ( V_215 -> V_227 & V_228 ) {
V_2 -> V_157 [ V_200 ] . V_229 = 14 ;
V_2 -> V_157 [ V_200 ] . V_159 = V_218 ;
V_2 -> V_157 [ V_200 ] . V_217 = V_217 ;
V_2 -> V_157 [ V_200 ] . V_160 = V_76 ;
V_28 -> V_230 -> V_157 [ V_200 ] =
& V_2 -> V_157 [ V_200 ] ;
memcpy ( & V_2 -> V_157 [ V_200 ] . V_231 ,
& V_215 -> V_232 , sizeof( V_215 -> V_232 ) ) ;
}
if ( V_215 -> V_227 & V_233 ) {
V_2 -> V_157 [ V_201 ] . V_229 =
V_215 -> V_222 - 14 ;
V_2 -> V_157 [ V_201 ] . V_159 =
V_218 - 4 ;
V_2 -> V_157 [ V_201 ] . V_217 = & V_217 [ 14 ] ;
V_2 -> V_157 [ V_201 ] . V_160 = & V_76 [ 4 ] ;
V_28 -> V_230 -> V_157 [ V_201 ] =
& V_2 -> V_157 [ V_201 ] ;
memcpy ( & V_2 -> V_157 [ V_201 ] . V_231 ,
& V_215 -> V_232 , sizeof( V_215 -> V_232 ) ) ;
}
return 0 ;
V_225:
F_109 ( V_217 ) ;
F_26 ( V_2 , L_5 ) ;
return - V_224 ;
}
static void F_110 ( struct V_1 * V_2 )
{
if ( F_3 ( V_234 , & V_2 -> V_11 ) )
F_111 ( V_2 -> V_28 ) ;
if ( F_42 ( V_2 -> V_28 -> V_230 -> V_157 [ V_200 ] ) ) {
F_109 ( V_2 -> V_28 -> V_230 -> V_157 [ V_200 ] -> V_217 ) ;
F_109 ( V_2 -> V_28 -> V_230 -> V_157 [ V_200 ] -> V_160 ) ;
V_2 -> V_28 -> V_230 -> V_157 [ V_200 ] = NULL ;
V_2 -> V_28 -> V_230 -> V_157 [ V_201 ] = NULL ;
}
F_109 ( V_2 -> V_215 . V_226 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_214 * V_215 = & V_2 -> V_215 ;
int V_9 ;
if ( F_3 ( V_234 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_107 ( V_2 , V_215 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_28 -> V_235 = V_2 -> V_7 -> V_236 ;
V_2 -> V_28 -> V_108 =
F_113 (unsigned int, IEEE80211_TX_STATUS_HEADROOM,
rt2x00dev->extra_tx_headroom) ;
if ( F_65 ( V_2 , V_109 ) )
V_2 -> V_28 -> V_108 += V_237 ;
else if ( F_65 ( V_2 , V_238 ) )
V_2 -> V_28 -> V_108 += V_239 ;
V_2 -> V_28 -> V_240 = sizeof( struct V_241 ) ;
if ( F_65 ( V_2 , V_242 ) ) {
int V_243 =
F_114 ( V_2 -> V_7 -> V_236 *
V_2 -> V_244 -> V_245 *
sizeof( T_1 ) ) ;
V_9 = F_115 ( & V_2 -> V_246 , V_243 ,
V_223 ) ;
if ( V_9 )
return V_9 ;
}
#define F_116 ( T_7 ) \
if (rt2x00dev->ops->lib->taskletname) { \
tasklet_init(&rt2x00dev->taskletname, \
rt2x00dev->ops->lib->taskletname, \
(unsigned long)rt2x00dev); \
}
F_116 ( V_247 ) ;
F_116 ( V_248 ) ;
F_116 ( V_249 ) ;
F_116 ( V_250 ) ;
F_116 ( V_251 ) ;
#undef F_116
V_9 = F_117 ( V_2 -> V_28 ) ;
if ( V_9 )
return V_9 ;
F_7 ( V_234 , & V_2 -> V_11 ) ;
return 0 ;
}
static void F_118 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_252 , & V_2 -> V_11 ) )
return;
if ( F_65 ( V_2 , V_253 ) )
F_119 ( V_2 ) ;
V_2 -> V_7 -> V_12 -> V_254 ( V_2 ) ;
F_120 ( V_2 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_9 ;
if ( F_3 ( V_252 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_122 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_9 = V_2 -> V_7 -> V_12 -> V_255 ( V_2 ) ;
if ( V_9 ) {
F_120 ( V_2 ) ;
return V_9 ;
}
F_7 ( V_252 , & V_2 -> V_11 ) ;
if ( F_65 ( V_2 , V_253 ) )
F_123 ( V_2 ) ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 )
{
int V_256 ;
if ( F_3 ( V_257 , & V_2 -> V_11 ) )
return 0 ;
V_256 = F_125 ( V_2 ) ;
if ( V_256 )
return V_256 ;
V_256 = F_121 ( V_2 ) ;
if ( V_256 )
return V_256 ;
V_2 -> V_258 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_259 = 0 ;
V_256 = F_2 ( V_2 ) ;
if ( V_256 )
return V_256 ;
F_7 ( V_257 , & V_2 -> V_11 ) ;
return 0 ;
}
void F_126 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_257 , & V_2 -> V_11 ) )
return;
F_11 ( V_2 ) ;
V_2 -> V_258 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_259 = 0 ;
}
static inline void F_127 ( struct V_1 * V_2 )
{
struct V_260 * V_261 ;
struct V_262 * V_263 ;
if ( V_2 -> V_7 -> V_8 < 2 )
return;
V_261 = & V_2 -> V_264 ;
V_261 -> V_265 = V_2 -> V_7 -> V_8 ;
V_261 -> V_266 = F_128 ( V_38 ) ;
#ifdef F_129
V_261 -> V_266 |= F_128 ( V_40 ) ;
#endif
V_263 = & V_2 -> V_267 [ V_268 ] ;
V_263 -> V_269 = V_261 ;
V_263 -> V_270 = 1 ;
V_263 -> V_271 = V_261 -> V_265 ;
V_263 -> V_272 = 1 ;
V_2 -> V_28 -> V_230 -> V_273 = V_2 -> V_267 ;
V_2 -> V_28 -> V_230 -> V_274 = 1 ;
}
static unsigned int F_130 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 -> V_244 ) )
return 0 ;
if ( F_33 ( V_2 ) )
return V_2 -> V_244 [ 0 ] . V_275 + V_2 -> V_244 [ 0 ] . V_276 ;
return V_2 -> V_244 [ 0 ] . V_275 ;
}
int F_131 ( struct V_1 * V_2 )
{
int V_256 = - V_224 ;
F_127 ( V_2 ) ;
if ( V_2 -> V_7 -> V_277 > 0 ) {
V_2 -> V_278 = F_132 ( V_2 -> V_7 -> V_277 ,
V_223 ) ;
if ( ! V_2 -> V_278 ) {
V_256 = - V_224 ;
goto exit;
}
}
F_133 ( & V_2 -> V_279 ) ;
F_134 ( & V_2 -> V_280 ) ;
F_134 ( & V_2 -> V_281 ) ;
F_135 ( & V_2 -> V_282 ) ;
F_133 ( & V_2 -> V_55 ) ;
F_7 ( V_31 , & V_2 -> V_11 ) ;
V_2 -> V_28 -> V_283 = sizeof( struct V_20 ) ;
V_2 -> V_28 -> V_230 -> V_284 [ V_285 - 1 ] =
( V_2 -> V_7 -> V_8 - 1 ) ;
V_2 -> V_147 =
F_136 ( L_6 , 0 , F_137 ( V_2 -> V_28 -> V_230 ) ) ;
if ( ! V_2 -> V_147 ) {
V_256 = - V_224 ;
goto exit;
}
F_138 ( & V_2 -> V_27 , F_22 ) ;
F_139 ( & V_2 -> V_30 , F_25 ) ;
F_138 ( & V_2 -> V_121 , F_74 ) ;
V_256 = V_2 -> V_7 -> V_12 -> V_286 ( V_2 ) ;
if ( V_256 ) {
F_26 ( V_2 , L_7 ) ;
goto exit;
}
V_256 = F_140 ( V_2 ) ;
if ( V_256 )
goto exit;
V_2 -> V_108 = F_130 ( V_2 ) ;
V_2 -> V_28 -> V_230 -> V_287 = F_128 ( V_288 ) ;
if ( V_2 -> V_289 -> V_245 > 0 )
V_2 -> V_28 -> V_230 -> V_287 |=
F_128 ( V_39 ) |
#ifdef F_129
F_128 ( V_40 ) |
#endif
#ifdef F_141
F_128 ( V_41 ) |
#endif
F_128 ( V_38 ) ;
V_2 -> V_28 -> V_230 -> V_11 |= V_290 ;
F_142 ( V_2 -> V_28 -> V_230 ,
V_291 ) ;
V_256 = F_112 ( V_2 ) ;
if ( V_256 ) {
F_26 ( V_2 , L_8 ) ;
goto exit;
}
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
if ( ! F_65 ( V_2 , V_253 ) )
F_123 ( V_2 ) ;
return 0 ;
exit:
F_146 ( V_2 ) ;
return V_256 ;
}
void F_146 ( struct V_1 * V_2 )
{
F_27 ( V_31 , & V_2 -> V_11 ) ;
if ( ! F_65 ( V_2 , V_253 ) )
F_119 ( V_2 ) ;
F_11 ( V_2 ) ;
F_147 ( & V_2 -> V_27 ) ;
F_148 ( & V_2 -> V_30 ) ;
F_147 ( & V_2 -> V_121 ) ;
F_149 ( & V_2 -> V_247 ) ;
F_149 ( & V_2 -> V_248 ) ;
F_149 ( & V_2 -> V_249 ) ;
F_149 ( & V_2 -> V_250 ) ;
F_149 ( & V_2 -> V_251 ) ;
F_118 ( V_2 ) ;
if ( V_2 -> V_147 )
F_150 ( V_2 -> V_147 ) ;
F_151 ( & V_2 -> V_246 ) ;
F_152 ( V_2 ) ;
F_153 ( V_2 ) ;
F_110 ( V_2 ) ;
F_154 ( V_2 ) ;
F_155 ( V_2 ) ;
F_109 ( V_2 -> V_278 ) ;
}
int F_156 ( struct V_1 * V_2 , T_8 V_292 )
{
F_157 ( V_2 , L_9 ) ;
if ( ! F_12 ( V_31 , & V_2 -> V_11 ) )
return 0 ;
F_118 ( V_2 ) ;
F_158 ( V_2 ) ;
F_152 ( V_2 ) ;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_293 ) )
F_87 ( V_2 , L_10 ) ;
return 0 ;
}
int F_159 ( struct V_1 * V_2 )
{
F_157 ( V_2 , L_11 ) ;
F_145 ( V_2 ) ;
F_160 ( V_2 ) ;
F_7 ( V_31 , & V_2 -> V_11 ) ;
return 0 ;
}
