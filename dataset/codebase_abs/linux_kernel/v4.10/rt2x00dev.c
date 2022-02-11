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
if ( F_11 ( V_2 ) )
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_10 , & V_2 -> V_11 ) )
return;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
if ( F_11 ( V_2 ) )
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 , true ) ;
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_16 ) ;
V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_17 ) ;
F_6 ( V_2 , false ) ;
F_5 ( V_2 , false ) ;
}
static void F_22 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_18 ;
struct V_20 * V_21 = F_23 ( V_4 ) ;
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
if ( F_15 ( V_22 , & V_21 -> V_23 ) ) {
F_24 ( & V_21 -> V_24 ) ;
F_25 ( V_2 , V_4 ) ;
F_26 ( & V_21 -> V_24 ) ;
}
}
static void F_27 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_28 ( V_26 , struct V_1 , V_27 ) ;
F_29 ( V_2 -> V_28 ,
V_29 ,
F_22 ,
V_2 ) ;
}
static void F_30 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_28 ( V_26 , struct V_1 , V_30 . V_26 ) ;
if ( ! F_3 ( V_31 , & V_2 -> V_11 ) )
return;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_32 ) )
F_31 ( V_2 , L_1 ) ;
F_32 ( V_33 , & V_2 -> V_11 ) ;
}
static void F_33 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_34 V_35 = {} ;
struct V_1 * V_2 = V_18 ;
struct V_36 * V_37 ;
if ( V_4 -> type != V_38 )
return;
V_37 = F_34 ( V_2 -> V_28 , V_4 ) ;
while ( V_37 ) {
F_35 ( V_2 -> V_28 , & V_35 , V_37 ) ;
V_37 = F_34 ( V_2 -> V_28 , V_4 ) ;
}
}
static void F_36 ( void * V_18 , T_2 * V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_18 ;
if ( V_4 -> type != V_38 &&
V_4 -> type != V_39 &&
V_4 -> type != V_40 &&
V_4 -> type != V_41 )
return;
F_37 ( F_38 ( V_2 ) ) ;
F_25 ( V_2 , V_4 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_40 (
V_2 -> V_28 , V_29 ,
F_33 , V_2 ) ;
if ( F_41 ( V_2 ) )
return;
F_40 (
V_2 -> V_28 , V_29 ,
F_36 , V_2 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_10 , & V_2 -> V_11 ) )
return;
F_40 (
V_2 -> V_28 , V_29 ,
F_36 , V_2 ) ;
}
void F_43 ( struct V_42 * V_43 )
{
F_7 ( V_44 , & V_43 -> V_11 ) ;
F_44 ( V_43 , V_45 ) ;
}
void F_45 ( struct V_42 * V_43 )
{
F_7 ( V_46 , & V_43 -> V_11 ) ;
F_32 ( V_44 , & V_43 -> V_11 ) ;
F_44 ( V_43 , V_47 ) ;
}
static inline int F_46 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_49 * V_50 = ( void * ) V_43 -> V_37 -> V_18 ;
struct V_51 * V_52 ;
int V_53 ;
if ( F_47 ( ! F_48 ( V_50 -> V_54 ) ) )
return 0 ;
V_53 = 0 ;
F_49 () ;
F_50 (bar_entry, &rt2x00dev->bar_list, list) {
if ( V_52 -> V_43 != V_43 )
continue;
F_51 ( & V_2 -> V_55 ) ;
V_53 = V_52 -> V_56 ;
F_52 ( & V_52 -> V_57 ) ;
F_53 ( & V_2 -> V_55 ) ;
F_54 ( V_52 , V_58 ) ;
break;
}
F_55 () ;
return V_53 ;
}
void F_56 ( struct V_42 * V_43 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_61 * V_62 = F_57 ( V_43 -> V_37 ) ;
struct V_63 * V_64 = F_58 ( V_43 -> V_37 ) ;
unsigned int V_65 , V_66 ;
T_2 V_67 , V_68 , V_69 ;
T_2 V_70 = V_64 -> V_11 ;
bool V_71 ;
F_59 ( V_43 ) ;
F_60 ( V_43 -> V_37 , V_2 -> V_72 ) ;
V_64 -> V_11 &= ~ V_73 ;
V_65 = F_61 ( V_43 -> V_37 ) ;
if ( F_62 ( V_2 , V_74 ) )
F_63 ( V_43 -> V_37 , V_65 ) ;
if ( F_64 ( V_2 ) )
F_65 ( V_43 -> V_37 , V_65 ) ;
F_66 ( V_2 , V_75 , V_43 -> V_37 ) ;
V_71 =
F_46 ( V_43 ) ||
F_3 ( V_76 , & V_60 -> V_11 ) ||
F_3 ( V_77 , & V_60 -> V_11 ) ;
V_2 -> V_78 . V_79 . V_80 += V_71 ;
V_2 -> V_78 . V_79 . V_81 += ! V_71 ;
V_67 = V_64 -> V_82 ;
V_68 = V_64 -> V_83 ;
V_69 = F_3 ( V_84 , & V_60 -> V_11 ) ?
( V_60 -> V_85 + 1 ) : 1 ;
memset ( & V_62 -> V_9 , 0 , sizeof( V_62 -> V_9 ) ) ;
V_62 -> V_9 . V_86 = 0 ;
for ( V_66 = 0 ; V_66 < V_69 && V_66 < V_87 ; V_66 ++ ) {
V_62 -> V_9 . V_88 [ V_66 ] . V_89 = V_67 - V_66 ;
V_62 -> V_9 . V_88 [ V_66 ] . V_11 = V_68 ;
if ( V_67 - V_66 == 0 ) {
V_62 -> V_9 . V_88 [ V_66 ] . V_90 = V_69 - V_66 ;
V_66 ++ ;
break;
}
V_62 -> V_9 . V_88 [ V_66 ] . V_90 = 1 ;
}
if ( V_66 < ( V_87 - 1 ) )
V_62 -> V_9 . V_88 [ V_66 ] . V_89 = - 1 ;
if ( ! ( V_62 -> V_11 & V_91 ) ) {
if ( V_71 )
V_62 -> V_11 |= V_92 ;
else
V_2 -> V_93 . V_94 ++ ;
}
if ( F_3 ( V_95 , & V_60 -> V_11 ) ||
V_62 -> V_11 & V_96 ) {
V_62 -> V_11 |= V_97 ;
V_62 -> V_9 . V_98 = 1 ;
V_62 -> V_9 . V_99 = V_71 ? 1 : 0 ;
if ( ! V_71 )
V_62 -> V_11 |= V_100 ;
}
if ( V_68 & V_101 ) {
if ( V_71 )
V_2 -> V_93 . V_102 ++ ;
else
V_2 -> V_93 . V_103 ++ ;
}
if ( ! ( V_70 & V_104 ) ) {
if ( F_62 ( V_2 , V_105 ) )
F_67 ( V_2 -> V_28 , V_43 -> V_37 ) ;
else
F_68 ( V_2 -> V_28 , V_43 -> V_37 ) ;
} else
F_69 ( V_43 -> V_37 ) ;
V_43 -> V_37 = NULL ;
V_43 -> V_11 = 0 ;
V_2 -> V_7 -> V_12 -> V_106 ( V_43 ) ;
F_44 ( V_43 , V_107 ) ;
F_51 ( & V_43 -> V_48 -> V_108 ) ;
if ( ! F_70 ( V_43 -> V_48 ) )
F_71 ( V_43 -> V_48 ) ;
F_53 ( & V_43 -> V_48 -> V_108 ) ;
}
void F_72 ( struct V_42 * V_43 , T_1 V_9 )
{
struct V_59 V_60 ;
V_60 . V_11 = 0 ;
F_73 ( V_9 , & V_60 . V_11 ) ;
V_60 . V_85 = 0 ;
F_56 ( V_43 , & V_60 ) ;
}
static T_2 * F_74 ( T_2 * V_18 , unsigned int V_109 , T_2 V_110 )
{
struct V_111 * V_112 = ( void * ) V_18 ;
T_2 * V_113 , * V_114 ;
V_113 = ( T_2 * ) V_112 -> V_115 . V_116 . V_117 ;
V_114 = V_18 + V_109 ;
while ( V_113 < V_114 ) {
if ( V_113 + 2 + V_113 [ 1 ] > V_114 )
return NULL ;
if ( V_113 [ 0 ] == V_110 )
return V_113 ;
V_113 += 2 + V_113 [ 1 ] ;
}
return NULL ;
}
static void F_75 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_28 ( V_26 , struct V_1 , V_118 ) ;
if ( ! F_3 ( V_31 , & V_2 -> V_11 ) )
return;
if ( ! F_3 ( V_33 , & V_2 -> V_11 ) )
F_76 ( V_2 , & V_2 -> V_28 -> V_119 ,
V_120 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_121 * V_122 )
{
struct V_51 * V_43 ;
struct V_49 * V_123 = ( void * ) V_37 -> V_18 ;
if ( F_47 ( ! F_78 ( V_123 -> V_54 ) ) )
return;
if ( V_122 -> V_124 < sizeof( * V_123 ) + V_125 )
return;
F_49 () ;
F_50 (entry, &rt2x00dev->bar_list, list) {
if ( V_123 -> V_126 != V_43 -> V_126 )
continue;
#define F_79 ( T_3 , T_4 ) ( \
((a) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK)) == \
((b) & cpu_to_le16(IEEE80211_BAR_CTRL_TID_INFO_MASK))) \
if (!TID_CHECK(ba->control, entry->control))
continue;
#undef F_79
if ( ! F_80 ( V_123 -> V_127 , V_43 -> V_128 ) )
continue;
if ( ! F_80 ( V_123 -> V_128 , V_43 -> V_127 ) )
continue;
F_51 ( & V_2 -> V_55 ) ;
V_43 -> V_56 = 1 ;
F_53 ( & V_2 -> V_55 ) ;
break;
}
F_55 () ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_121 * V_122 )
{
struct V_129 * V_130 = ( void * ) V_37 -> V_18 ;
struct V_131 * V_132 ;
T_2 * V_133 ;
T_2 V_134 ;
bool V_135 ;
if ( F_47 ( ! F_82 ( V_130 -> V_54 ) ||
! ( V_2 -> V_28 -> V_119 . V_11 & V_136 ) ) )
return;
if ( V_37 -> V_109 <= 40 + V_125 )
return;
if ( ! ( V_122 -> V_137 & V_138 ) ||
! V_2 -> V_139 )
return;
V_2 -> V_140 = V_141 ;
V_133 = F_74 ( V_37 -> V_18 , V_37 -> V_109 - V_125 , V_142 ) ;
if ( ! V_133 )
return;
if ( V_133 [ 1 ] < sizeof( * V_132 ) )
return;
V_134 = V_133 [ 1 ] ;
V_132 = (struct V_131 * ) & V_133 [ 2 ] ;
V_135 = F_83 ( V_132 , V_134 , V_2 -> V_139 ) ;
V_135 |= ( V_132 -> V_143 & 0x01 ) ;
if ( ! V_135 && ! F_3 ( V_33 , & V_2 -> V_11 ) )
F_84 ( V_2 -> V_144 , & V_2 -> V_118 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_145 * V_146 ;
const struct V_147 * V_148 ;
unsigned int V_66 ;
int signal = V_122 -> signal ;
int type = ( V_122 -> V_137 & V_149 ) ;
switch ( V_122 -> V_150 ) {
case V_151 :
case V_152 :
if ( V_122 -> V_137 & V_153 )
signal = F_86 ( V_122 -> V_150 , signal ) ;
V_146 = & V_2 -> V_154 [ V_2 -> V_155 ] ;
for ( V_66 = 0 ; V_66 < V_146 -> V_156 ; V_66 ++ ) {
V_148 = F_87 ( V_146 -> V_157 [ V_66 ] . V_158 ) ;
if ( ( ( type == V_159 ) &&
( V_148 -> V_160 == signal ) ) ||
( ( type == V_161 ) &&
( V_148 -> V_162 == signal ) ) ||
( ( type == V_153 ) &&
( V_148 -> V_163 == signal ) ) ) {
return V_66 ;
}
}
break;
case V_164 :
case V_165 :
if ( signal >= 0 && signal <= 76 )
return signal ;
break;
default:
break;
}
F_88 ( V_2 , L_2 ,
V_122 -> V_150 , signal , type ) ;
return 0 ;
}
void F_89 ( struct V_42 * V_43 , T_5 V_166 )
{
struct V_1 * V_2 = V_43 -> V_48 -> V_2 ;
struct V_121 V_122 ;
struct V_36 * V_37 ;
struct V_167 * V_168 ;
unsigned int V_65 ;
int V_67 ;
if ( ! F_3 ( V_31 , & V_2 -> V_11 ) ||
! F_3 ( V_10 , & V_2 -> V_11 ) )
goto V_169;
if ( F_3 ( V_170 , & V_43 -> V_11 ) )
goto V_169;
V_37 = F_90 ( V_43 , V_166 ) ;
if ( ! V_37 )
goto V_169;
F_59 ( V_43 ) ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_2 -> V_7 -> V_12 -> V_171 ( V_43 , & V_122 ) ;
if ( F_91 ( V_122 . V_124 == 0 ||
V_122 . V_124 > V_43 -> V_48 -> V_172 ) ) {
F_31 ( V_2 , L_3 ,
V_122 . V_124 , V_43 -> V_48 -> V_172 ) ;
F_92 ( V_43 -> V_37 ) ;
goto V_173;
}
V_65 = F_61 ( V_43 -> V_37 ) ;
if ( ( V_122 . V_137 & V_174 ) &&
( V_122 . V_11 & V_175 ) )
F_93 ( V_43 -> V_37 , V_65 ,
& V_122 ) ;
else if ( V_65 &&
( V_122 . V_124 > V_65 ) &&
( V_122 . V_137 & V_176 ) )
F_63 ( V_43 -> V_37 , V_65 ) ;
F_94 ( V_43 -> V_37 , V_122 . V_124 ) ;
V_67 = F_85 ( V_2 , & V_122 ) ;
if ( V_122 . V_150 == V_164 ||
V_122 . V_150 == V_165 )
V_122 . V_11 |= V_177 ;
F_81 ( V_2 , V_43 -> V_37 , & V_122 ) ;
F_77 ( V_2 , V_43 -> V_37 , & V_122 ) ;
F_95 ( V_2 , V_43 -> V_37 , & V_122 ) ;
F_96 ( V_2 , & V_122 ) ;
F_66 ( V_2 , V_178 , V_43 -> V_37 ) ;
V_168 = F_97 ( V_43 -> V_37 ) ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_179 = V_122 . V_180 ;
V_168 -> V_181 = V_2 -> V_155 ;
V_168 -> V_182 = V_2 -> V_183 ;
V_168 -> V_67 = V_67 ;
V_168 -> signal = V_122 . V_184 ;
V_168 -> V_185 = V_122 . V_11 ;
V_168 -> V_186 = V_2 -> V_78 . V_187 . V_188 . V_189 ;
F_98 ( V_2 -> V_28 , V_43 -> V_37 ) ;
V_173:
V_43 -> V_37 = V_37 ;
V_169:
V_43 -> V_11 = 0 ;
F_44 ( V_43 , V_107 ) ;
if ( F_3 ( V_31 , & V_2 -> V_11 ) &&
F_3 ( V_10 , & V_2 -> V_11 ) )
V_2 -> V_7 -> V_12 -> V_106 ( V_43 ) ;
}
static void F_99 ( struct V_190 * V_43 ,
const int V_191 , const int V_192 ,
const int V_193 )
{
V_43 -> V_181 = V_191 <= 14 ? V_194 : V_195 ;
V_43 -> V_196 = F_100 ( V_191 ,
V_43 -> V_181 ) ;
V_43 -> V_158 = V_193 ;
V_43 -> V_197 = V_192 ;
V_43 -> V_198 = 0xff ;
}
static void F_101 ( struct V_199 * V_43 ,
const T_6 V_200 , const struct V_147 * V_148 )
{
V_43 -> V_11 = 0 ;
V_43 -> V_162 = V_148 -> V_162 ;
V_43 -> V_158 = V_200 ;
V_43 -> V_201 = V_200 ;
if ( V_148 -> V_11 & V_202 )
V_43 -> V_11 |= V_203 ;
}
void F_102 ( struct V_1 * V_2 , T_2 * V_204 )
{
const char * V_205 ;
V_205 = F_103 ( V_2 -> V_206 -> V_207 ) ;
if ( V_205 )
F_104 ( V_204 , V_205 ) ;
if ( ! F_105 ( V_204 ) ) {
F_106 ( V_204 ) ;
F_107 ( V_2 , L_4 , V_204 ) ;
}
}
static int F_108 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
struct V_210 * V_28 = V_2 -> V_28 ;
struct V_190 * V_211 ;
struct V_199 * V_88 ;
unsigned int V_212 ;
unsigned int V_66 ;
V_212 = 0 ;
if ( V_209 -> V_213 & V_214 )
V_212 += 4 ;
if ( V_209 -> V_213 & V_215 )
V_212 += 8 ;
V_211 = F_109 ( V_209 -> V_216 , sizeof( * V_211 ) , V_217 ) ;
if ( ! V_211 )
return - V_218 ;
V_88 = F_109 ( V_212 , sizeof( * V_88 ) , V_217 ) ;
if ( ! V_88 )
goto V_219;
for ( V_66 = 0 ; V_66 < V_212 ; V_66 ++ )
F_101 ( & V_88 [ V_66 ] , V_66 , F_87 ( V_66 ) ) ;
for ( V_66 = 0 ; V_66 < V_209 -> V_216 ; V_66 ++ ) {
F_99 ( & V_211 [ V_66 ] ,
V_209 -> V_211 [ V_66 ] . V_191 ,
V_209 -> V_220 [ V_66 ] . V_197 , V_66 ) ;
}
if ( V_209 -> V_221 & V_222 ) {
V_2 -> V_154 [ V_194 ] . V_223 = 14 ;
V_2 -> V_154 [ V_194 ] . V_156 = V_212 ;
V_2 -> V_154 [ V_194 ] . V_211 = V_211 ;
V_2 -> V_154 [ V_194 ] . V_157 = V_88 ;
V_28 -> V_224 -> V_154 [ V_194 ] =
& V_2 -> V_154 [ V_194 ] ;
memcpy ( & V_2 -> V_154 [ V_194 ] . V_225 ,
& V_209 -> V_226 , sizeof( V_209 -> V_226 ) ) ;
}
if ( V_209 -> V_221 & V_227 ) {
V_2 -> V_154 [ V_195 ] . V_223 =
V_209 -> V_216 - 14 ;
V_2 -> V_154 [ V_195 ] . V_156 =
V_212 - 4 ;
V_2 -> V_154 [ V_195 ] . V_211 = & V_211 [ 14 ] ;
V_2 -> V_154 [ V_195 ] . V_157 = & V_88 [ 4 ] ;
V_28 -> V_224 -> V_154 [ V_195 ] =
& V_2 -> V_154 [ V_195 ] ;
memcpy ( & V_2 -> V_154 [ V_195 ] . V_225 ,
& V_209 -> V_226 , sizeof( V_209 -> V_226 ) ) ;
}
return 0 ;
V_219:
F_110 ( V_211 ) ;
F_31 ( V_2 , L_5 ) ;
return - V_218 ;
}
static void F_111 ( struct V_1 * V_2 )
{
if ( F_3 ( V_228 , & V_2 -> V_11 ) )
F_112 ( V_2 -> V_28 ) ;
if ( F_47 ( V_2 -> V_28 -> V_224 -> V_154 [ V_194 ] ) ) {
F_110 ( V_2 -> V_28 -> V_224 -> V_154 [ V_194 ] -> V_211 ) ;
F_110 ( V_2 -> V_28 -> V_224 -> V_154 [ V_194 ] -> V_157 ) ;
V_2 -> V_28 -> V_224 -> V_154 [ V_194 ] = NULL ;
V_2 -> V_28 -> V_224 -> V_154 [ V_195 ] = NULL ;
}
F_110 ( V_2 -> V_209 . V_220 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_208 * V_209 = & V_2 -> V_209 ;
int V_9 ;
if ( F_3 ( V_228 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_108 ( V_2 , V_209 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_28 -> V_229 = V_2 -> V_7 -> V_230 ;
V_2 -> V_28 -> V_72 =
F_114 (unsigned int, IEEE80211_TX_STATUS_HEADROOM,
rt2x00dev->extra_tx_headroom) ;
if ( F_62 ( V_2 , V_74 ) )
V_2 -> V_28 -> V_72 += V_231 ;
else if ( F_62 ( V_2 , V_232 ) )
V_2 -> V_28 -> V_72 += V_233 ;
V_2 -> V_28 -> V_234 = sizeof( struct V_235 ) ;
if ( F_62 ( V_2 , V_236 ) ) {
int V_237 =
F_115 ( V_2 -> V_7 -> V_230 *
V_2 -> V_238 -> V_239 *
sizeof( T_1 ) ) ;
V_9 = F_116 ( & V_2 -> V_240 , V_237 ,
V_217 ) ;
if ( V_9 )
return V_9 ;
}
#define F_117 ( T_7 ) \
if (rt2x00dev->ops->lib->taskletname) { \
tasklet_init(&rt2x00dev->taskletname, \
rt2x00dev->ops->lib->taskletname, \
(unsigned long)rt2x00dev); \
}
F_117 ( V_241 ) ;
F_117 ( V_242 ) ;
F_117 ( V_243 ) ;
F_117 ( V_244 ) ;
F_117 ( V_245 ) ;
#undef F_117
V_9 = F_118 ( V_2 -> V_28 ) ;
if ( V_9 )
return V_9 ;
F_7 ( V_228 , & V_2 -> V_11 ) ;
return 0 ;
}
static void F_119 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_246 , & V_2 -> V_11 ) )
return;
if ( F_62 ( V_2 , V_247 ) )
F_120 ( V_2 ) ;
V_2 -> V_7 -> V_12 -> V_248 ( V_2 ) ;
F_121 ( V_2 ) ;
}
static int F_122 ( struct V_1 * V_2 )
{
int V_9 ;
if ( F_3 ( V_246 , & V_2 -> V_11 ) )
return 0 ;
V_9 = F_123 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_9 = V_2 -> V_7 -> V_12 -> V_249 ( V_2 ) ;
if ( V_9 ) {
F_121 ( V_2 ) ;
return V_9 ;
}
F_7 ( V_246 , & V_2 -> V_11 ) ;
if ( F_62 ( V_2 , V_247 ) )
F_124 ( V_2 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 )
{
int V_250 ;
if ( F_3 ( V_251 , & V_2 -> V_11 ) )
return 0 ;
V_250 = F_126 ( V_2 ) ;
if ( V_250 )
return V_250 ;
V_250 = F_122 ( V_2 ) ;
if ( V_250 )
return V_250 ;
V_2 -> V_252 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_253 = 0 ;
V_250 = F_2 ( V_2 ) ;
if ( V_250 )
return V_250 ;
F_7 ( V_251 , & V_2 -> V_11 ) ;
return 0 ;
}
void F_127 ( struct V_1 * V_2 )
{
if ( ! F_15 ( V_251 , & V_2 -> V_11 ) )
return;
F_14 ( V_2 ) ;
V_2 -> V_252 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_253 = 0 ;
}
static inline void F_128 ( struct V_1 * V_2 )
{
struct V_254 * V_255 ;
struct V_256 * V_257 ;
if ( V_2 -> V_7 -> V_8 < 2 )
return;
V_255 = & V_2 -> V_258 ;
V_255 -> V_259 = V_2 -> V_7 -> V_8 ;
V_255 -> V_260 = F_129 ( V_38 ) ;
#ifdef F_130
V_255 -> V_260 |= F_129 ( V_40 ) ;
#endif
V_257 = & V_2 -> V_261 [ V_262 ] ;
V_257 -> V_263 = V_255 ;
V_257 -> V_264 = 1 ;
V_257 -> V_265 = V_255 -> V_259 ;
V_257 -> V_266 = 1 ;
V_2 -> V_28 -> V_224 -> V_267 = V_2 -> V_261 ;
V_2 -> V_28 -> V_224 -> V_268 = 1 ;
}
static unsigned int F_131 ( struct V_1 * V_2 )
{
if ( F_37 ( ! V_2 -> V_238 ) )
return 0 ;
if ( F_38 ( V_2 ) )
return V_2 -> V_238 [ 0 ] . V_269 + V_2 -> V_238 [ 0 ] . V_270 ;
return V_2 -> V_238 [ 0 ] . V_269 ;
}
int F_132 ( struct V_1 * V_2 )
{
int V_250 = - V_218 ;
F_128 ( V_2 ) ;
if ( V_2 -> V_7 -> V_271 > 0 ) {
V_2 -> V_272 = F_133 ( V_2 -> V_7 -> V_271 ,
V_217 ) ;
if ( ! V_2 -> V_272 ) {
V_250 = - V_218 ;
goto exit;
}
}
F_134 ( & V_2 -> V_273 ) ;
F_135 ( & V_2 -> V_274 ) ;
F_136 ( & V_2 -> V_275 ) ;
F_134 ( & V_2 -> V_55 ) ;
F_7 ( V_31 , & V_2 -> V_11 ) ;
V_2 -> V_28 -> V_276 = sizeof( struct V_20 ) ;
V_2 -> V_28 -> V_224 -> V_277 [ V_278 - 1 ] =
( V_2 -> V_7 -> V_8 - 1 ) ;
V_2 -> V_144 =
F_137 ( L_6 , 0 , F_138 ( V_2 -> V_28 -> V_224 ) ) ;
if ( ! V_2 -> V_144 ) {
V_250 = - V_218 ;
goto exit;
}
F_139 ( & V_2 -> V_27 , F_27 ) ;
F_140 ( & V_2 -> V_30 , F_30 ) ;
F_139 ( & V_2 -> V_118 , F_75 ) ;
V_250 = V_2 -> V_7 -> V_12 -> V_279 ( V_2 ) ;
if ( V_250 ) {
F_31 ( V_2 , L_7 ) ;
goto exit;
}
V_250 = F_141 ( V_2 ) ;
if ( V_250 )
goto exit;
V_2 -> V_72 = F_131 ( V_2 ) ;
V_2 -> V_28 -> V_224 -> V_280 = F_129 ( V_281 ) ;
if ( V_2 -> V_282 -> V_239 > 0 )
V_2 -> V_28 -> V_224 -> V_280 |=
F_129 ( V_39 ) |
#ifdef F_130
F_129 ( V_40 ) |
#endif
#ifdef F_142
F_129 ( V_41 ) |
#endif
F_129 ( V_38 ) ;
V_2 -> V_28 -> V_224 -> V_11 |= V_283 ;
V_250 = F_113 ( V_2 ) ;
if ( V_250 ) {
F_31 ( V_2 , L_8 ) ;
goto exit;
}
F_143 ( V_2 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
if ( ! F_62 ( V_2 , V_247 ) )
F_124 ( V_2 ) ;
return 0 ;
exit:
F_146 ( V_2 ) ;
return V_250 ;
}
void F_146 ( struct V_1 * V_2 )
{
F_32 ( V_31 , & V_2 -> V_11 ) ;
if ( ! F_62 ( V_2 , V_247 ) )
F_120 ( V_2 ) ;
F_14 ( V_2 ) ;
F_147 ( & V_2 -> V_27 ) ;
F_148 ( & V_2 -> V_30 ) ;
F_147 ( & V_2 -> V_118 ) ;
#if F_149 ( V_284 )
if ( F_38 ( V_2 ) ) {
F_150 ( V_2 -> V_285 ) ;
F_151 ( & V_2 -> V_286 ) ;
F_147 ( & V_2 -> V_287 ) ;
F_147 ( & V_2 -> V_288 ) ;
}
#endif
if ( V_2 -> V_144 )
F_152 ( V_2 -> V_144 ) ;
F_153 ( & V_2 -> V_240 ) ;
F_154 ( & V_2 -> V_241 ) ;
F_154 ( & V_2 -> V_242 ) ;
F_154 ( & V_2 -> V_243 ) ;
F_154 ( & V_2 -> V_244 ) ;
F_154 ( & V_2 -> V_245 ) ;
F_119 ( V_2 ) ;
F_155 ( V_2 ) ;
F_156 ( V_2 ) ;
F_111 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
F_110 ( V_2 -> V_272 ) ;
}
int F_159 ( struct V_1 * V_2 , T_8 V_289 )
{
F_160 ( V_2 , L_9 ) ;
if ( ! F_15 ( V_31 , & V_2 -> V_11 ) )
return 0 ;
F_119 ( V_2 ) ;
F_161 ( V_2 ) ;
F_155 ( V_2 ) ;
if ( V_2 -> V_7 -> V_12 -> V_13 ( V_2 , V_290 ) )
F_88 ( V_2 , L_10 ) ;
return 0 ;
}
int F_162 ( struct V_1 * V_2 )
{
F_160 ( V_2 , L_11 ) ;
F_145 ( V_2 ) ;
F_163 ( V_2 ) ;
F_7 ( V_31 , & V_2 -> V_11 ) ;
return 0 ;
}
